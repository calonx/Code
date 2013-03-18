using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Xml;

namespace PProjTool {

    enum Language {
        CPlusPlus,
        CSharp,
    }

    interface IProject {
        void Write ();
        string FullPath { get; }
        string Name { get; }
        Guid Guid { get; }
    }

    class Filter {
        public Filter (string name, IEnumerable<Filter> filters, IEnumerable<string> files) {
            Name = name;
            Subfilters = filters.ToList();
            Files = files.ToList();
        }

        public string Name { get; private set; }
        public List<Filter> Subfilters { get; private set; }
        public List<string> Files { get; private set; }
    }

    class Project : IProject {
        public string FullPath { get; private set; }
        public string Root { get; private set; }
        public string Name { get; private set; }
        public ProjectType Type { get; private set; }
        public Language Language { get; private set; }
        public Guid Guid { get; private set; }
        public IEnumerable<string> Files { get { throw new NotImplementedException(); } }

        private Filter m_rootFilter;

        public Project (string root, string name, ProjectType type, Language language, Filter rootFilter) {
            Root = root;
            Name = name;
            Type = type;
            Language = language;
            m_rootFilter = rootFilter;
            Guid = GuidHash.CreateGuidFromPath(Path.Combine(Root, Name));

            string extension = "";
            switch (Language) {
                case Language.CPlusPlus: extension = ".vcproj"; break;
                case Language.CSharp:    extension = ".csproj"; break;
            }
            FullPath = Path.Combine(Root, Name + extension);
        }

        public void Write () {
            if (Language != Language.CPlusPlus)
                throw new NotImplementedException("Only C++ projects are supported at this time.");
            WriteCpp();
        }

        private void WriteCpp () {
            string path = Path.Combine(Root, "Vs2008");
            Directory.CreateDirectory(path);

            path = Path.Combine(path, Name);
            string vcprojPath = Path.ChangeExtension(path, ".vcproj");
            ProjectWriter writer = new ProjectWriter(vcprojPath);

            using (writer.WriteElement("VisualStudioProject")) {
                writer.WriteAttribute("ProjectType", "Visual C++");
                writer.WriteAttribute("Version", "9.00");
                writer.WriteAttribute("Name", Name);
                writer.WriteAttribute("ProjectGUID", Guid.ToString());

                Platform platform = Platform.x64;

                using (writer.WriteElement("Platforms")) {
                    using (writer.WriteElement("Platform"))
                        writer.WriteAttribute("Name", platform);
                }

                var configs = new CppConfigSettings[] {
                    ConfigDebugDefault,
                    ConfigReleaseDefault,
                };

                using (writer.WriteElement("Configurations")) {
                    foreach (var config in configs)
                        WriteCppConfiguration(writer, config);
                }

                OptimizeFilters(m_rootFilter.Subfilters);

                using (writer.WriteElement("Files")) {
                    foreach (var filter in m_rootFilter.Subfilters)
                        WriteFilter(writer, configs, filter);

                    bool pchNeedsCreation = true;
                    foreach (var file in m_rootFilter.Files) {
                        WriteFile(writer, configs, file, pchNeedsCreation);
                        pchNeedsCreation = false;
                    }
                }
            }

            writer.Close();
        }

        private static bool IsCppFile (string file) {
            return file.EndsWith(".cpp") || file.EndsWith(".h");
        }

        private void OptimizeFilters (List<Filter> filters) {
            for (int i = 0; i < filters.Count; ++i) {
                bool empty = OptimizeFilter(filters[i]);
                if (empty)
                    filters.RemoveAt(i--);
            }
        }

        private bool OptimizeFilter (Filter filter) {
            for (int i = 0; i < filter.Subfilters.Count; ++i) {
                bool empty = OptimizeFilter(filter.Subfilters[i]);
                if (empty)
                    filter.Subfilters.RemoveAt(i--);
            }

            bool hasFiles = (filter.Files.Where(f => IsCppFile(f)).Count() == 0);
            bool hasFilters = (filter.Subfilters.Count == 0);
            return hasFiles && hasFilters;
        }

        private void WriteFilter (ProjectWriter writer, IEnumerable<CppConfigSettings> configs, Filter filter) {
            var files = filter.Files.Where(f => IsCppFile(f));

            using (writer.WriteElement("Filter")) {
                writer.WriteAttribute("Name", filter.Name);

                foreach (var subfilter in filter.Subfilters)
                    WriteFilter(writer, configs, subfilter);

                bool pchNeedsCreation = true;
                foreach (var file in files) {
                    WriteFile(writer, configs, file, pchNeedsCreation);
                    pchNeedsCreation = false;
                }
            }
        }

        private void WriteFile (ProjectWriter writer, IEnumerable<CppConfigSettings> configs, string path, bool createPch) {
            string vcprojRelPath = Path.Combine("..", path);
            using (writer.WriteElement("File")) {
                writer.WriteAttribute("RelativePath", vcprojRelPath);
                if (path.EndsWith(".cpp")) {
                    foreach (var config in configs)
                        WriteFileConfiguration(writer, config, createPch);
                }
            }
        }

        private void WriteFileConfiguration (ProjectWriter writer, CppConfigSettings config, bool createPch) {
            using (writer.WriteElement("FileConfiguration")) {
                writer.WriteAttribute("Name", "{0}|{1}", config.configuration, config.platform);
                using (writer.WriteElement("Tool")) {
                    writer.WriteAttribute("Name", "VCCLCompilerTool");

                    if (createPch)
                        writer.WriteAttribute("CreatePrecompiledHeader", (int)UsePrecompiledHeader.CreatePrecompiledHeader);
                    else
                        writer.WriteAttribute("UsePrecompiledHeader", (int)UsePrecompiledHeader.UsePrecompiledHeader);
                }
            }
        }

        class CppConfigSettings {
            public Configuration configuration;
            public Platform platform;
            public CharacterSet characterSet;

            // Compiler options
            public Optimization optimization;
            public WholeProgramOptimization wholeProgramOptimization;
            public bool minimalRebuild;
            public bool enableFunctionLevelLinking;
            public bool enableIntrinsicFunctions;
            public BasicRuntimeChecks runtimeChecks;
            public RuntimeLibrary runtimeLibrary;
            public WarningLevel warningLevel;
            public DebugInformationFormat debugFormat;
            public UsePrecompiledHeader precompiledHeader;
            public string precompiledHeaderTarget;

            // Linker options
            public bool generateDebugInformation;
            public OptimizeReferences optimizeReferences;
            public EnableComdatFolding enableComdatFolding;
            public TargetMachine targetMachine;
        }

        private CppConfigSettings ConfigDebugDefault = new CppConfigSettings() {
            configuration = Configuration.Debug,
            platform = Platform.x64,
            characterSet = CharacterSet.Unicode,

            optimization = Optimization.Disabled,
            wholeProgramOptimization = WholeProgramOptimization.No,
            minimalRebuild = true,
            enableFunctionLevelLinking = false,
            enableIntrinsicFunctions = false,
            runtimeChecks = BasicRuntimeChecks.Both,
            runtimeLibrary = RuntimeLibrary.MultithreadedDebugDll,
            warningLevel = WarningLevel.W4,
            debugFormat = DebugInformationFormat.ProgramDatabase,
            precompiledHeader = UsePrecompiledHeader.CreatePrecompiledHeader,
            precompiledHeaderTarget = "Pch.h",

            generateDebugInformation = true,
            optimizeReferences = OptimizeReferences.Default,
            enableComdatFolding = EnableComdatFolding.Default,
            targetMachine = TargetMachine.X64,
        };

        private CppConfigSettings ConfigReleaseDefault = new CppConfigSettings() {
            configuration = Configuration.Release,
            platform = Platform.x64,
            characterSet = CharacterSet.Unicode,

            optimization = Optimization.MaximizeSpeed,
            wholeProgramOptimization = WholeProgramOptimization.LinkTimeCodeGeneration,
            minimalRebuild = false,
            enableFunctionLevelLinking = true,
            enableIntrinsicFunctions = true,
            runtimeChecks = BasicRuntimeChecks.Default,
            runtimeLibrary = RuntimeLibrary.MultithreadedDll,
            warningLevel = WarningLevel.W4,
            debugFormat = DebugInformationFormat.ProgramDatabase,
            precompiledHeader = UsePrecompiledHeader.CreatePrecompiledHeader,
            precompiledHeaderTarget = "Pch.h",

            generateDebugInformation = true,
            optimizeReferences = OptimizeReferences.EliminateUnreferencedData,
            enableComdatFolding = EnableComdatFolding.RemoveRedundantComdats,
            targetMachine = TargetMachine.X64,
        };

        class ProjectWriter {
            private XmlWriter m_writer;

            public ProjectWriter (string path) {
                XmlWriterSettings settings = new XmlWriterSettings() {
                    CloseOutput = true,
                    Indent = true,
                    IndentChars = "\t",
                    NewLineOnAttributes = true,
                };
                m_writer = XmlWriter.Create(path, settings);
                m_writer.WriteStartDocument();
            }

            public IDisposable WriteElement (string name) {
                return m_writer.WriteElement(name);
            }

            public void WriteAttribute (string name, string value) {
                m_writer.WriteAttributeString(name, value);
            }

            public void WriteAttribute (string name, string format, params object[] list) {
                m_writer.WriteAttributeString(name, string.Format(format, list));
            }

            public void WriteAttribute (string name, bool value) {
                m_writer.WriteAttributeString(name, value ? "true" : "false");
            }

            public void WriteAttribute (string name, int value) {
                m_writer.WriteAttributeString(name, value.ToString());
            }

            public void WriteAttribute (string name, object value) {
                m_writer.WriteAttributeString(name, value.ToString());
            }

            public void Close () {
                m_writer.Close();
                m_writer = null;
            }
        }

        private string TempDirectory { get { return @"$(TEMP)\VsIntermediate\2008\$(ConfigurationName)"; } }

        private void WriteCppConfiguration (ProjectWriter writer, CppConfigSettings settings) {
            using (writer.WriteElement("Configuration")) {
                writer.WriteAttribute("Name", "{0}|{1}", settings.configuration, settings.platform);
                writer.WriteAttribute("OutputDirectory", "$(SolutionDir)");
                writer.WriteAttribute("IntermediateDirectory", TempDirectory);
                writer.WriteAttribute("ConfigurationType", (int)Type);
                writer.WriteAttribute("CharacterSet", (int)settings.characterSet);
                writer.WriteAttribute("WholeProgramOptimization", settings.wholeProgramOptimization);

                using (writer.WriteElement("Tool")) {
                    writer.WriteAttribute("Name", "VCCLCompilerTool");
                    writer.WriteAttribute("Optimization", (int)settings.optimization);
                    writer.WriteAttribute("EnableIntrinsicFunctions", settings.enableIntrinsicFunctions);
                    writer.WriteAttribute("EnableFunctionLevelLinking", settings.enableFunctionLevelLinking);
                    writer.WriteAttribute("MinimalRebuild", settings.minimalRebuild);
                    writer.WriteAttribute("BasicRuntimeChecks", (int)settings.runtimeChecks);
                    writer.WriteAttribute("RuntimeLibrary", (int)settings.runtimeLibrary);
                    writer.WriteAttribute("WarningLevel", (int)settings.warningLevel);
                    writer.WriteAttribute("DebugInformationFormat", (int)settings.debugFormat);
                    writer.WriteAttribute("UsePrecompiledHeader", (int)settings.precompiledHeader);
                    writer.WriteAttribute("PrecompiledHeaderThrough", settings.precompiledHeaderTarget);
                }

                using (writer.WriteElement("Tool")) {
                    writer.WriteAttribute("Name", "VCLinkerTool");
                    writer.WriteAttribute("GenerateDebugInformation", settings.generateDebugInformation);
                    writer.WriteAttribute("OptimizeReferences", (int)settings.optimizeReferences);
                    writer.WriteAttribute("EnableCOMDATFolding", (int)settings.enableComdatFolding);
                    writer.WriteAttribute("TargetMachine", (int)settings.targetMachine);
                }
            }
        }
    }

    static class XmlHelpers {
        public static IDisposable WriteElement (this XmlWriter writer, string name) {
            return new ElementScopeObject(writer, name);
        }

        private class ElementScopeObject : IDisposable {
            private XmlWriter m_writer;

            public ElementScopeObject (XmlWriter writer, string name) {
                m_writer = writer;
                writer.WriteStartElement(name);
            }

            public void Dispose () {
                m_writer.WriteEndElement();
            }
        }

        public static bool NameIs (this XmlReader reader, string name) {
            return string.Compare(reader.Name, name, true) == 0;
        }
    }

    static class EnumHelpers {
        public static bool TryParse<T> (string value, out T enumValue) {
            var names = Enum.GetNames(typeof(T));
            for (int i = 0; i < names.Length; ++i) {
                if (string.Compare(names[i], value, true) == 0) {
                    enumValue = (T)Enum.GetValues(typeof(T)).GetValue(i);
                    return true;
                }
            }
            enumValue = default(T);
            return false;
        }
    }
}
