using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Xml;
using System.IO;

namespace PProjTool {

    #region Configurations

    enum Configuration {
        Debug,
        Release,
    }

    enum Platform {
        Win32,
        x64,
    }

    // Corresponds to Visual Studio "ConfigurationType"
    enum ProjectType {
        Exe = 1,
        Dll = 2,
        Lib = 4,
    }

    #endregion

    public class PProjContext {
        Dictionary<string, ProjectRef> m_projectRefs = new Dictionary<string, ProjectRef>();
        Dictionary<string, Solution> m_solutions = new Dictionary<string, Solution>();

        public bool Load (string pprojPath) {
            string root = Path.GetDirectoryName(pprojPath);

            XmlReaderSettings settings = new XmlReaderSettings() { IgnoreComments = true, IgnoreWhitespace = true };
            using (XmlReader reader = XmlReader.Create(pprojPath, settings)) {
                if (!reader.Read())
                    return false;

                if (!reader.NameIs("pproj"))
                    return false;

                while (reader.Read()) {
                    if (!reader.IsStartElement())
                        continue;

                    if (reader.NameIs("project")) {
                        if (!ReadProject(reader, root))
                            return false;
                    }

                }
            }

            return true;
        }

        private struct DirSpec {
            public string include;
            public bool recurse;
        }

        private bool ReadProject (XmlReader reader, string root) {
            string name = reader.GetAttribute("name");
            string typeString = reader.GetAttribute("type");
            string languageString = reader.GetAttribute("language");
            string location = reader.GetAttribute("location");

            List<string> projectDeps = new List<string>();
            List<DirSpec> dirSpecs = new List<DirSpec>();
            while (reader.Read()) {
                if (reader.NameIs("project") && !reader.IsStartElement())
                    break;
                else if (!reader.IsStartElement())
                    continue;

                if (reader.NameIs("dir")) {
                    dirSpecs.Add(new DirSpec() {
                        include = reader.GetAttribute("include"),
                        recurse = reader.GetAttribute("recurse") == "true",
                    });
                }
                else if (reader.NameIs("dep"))
                    projectDeps.Add(reader.GetAttribute("project"));
            }

            // Default to including the files in the project's directory
            if (dirSpecs.Count == 0)
                dirSpecs.Add(new DirSpec() { include = "." });

            var rootFilter = GatherProjectFiles(root, location, dirSpecs);

            ProjectType type;
            if (!EnumHelpers.TryParse<ProjectType>(typeString, out type))
                return false;

            Language language;
            if (languageString == "C++")
                language = Language.CPlusPlus;
            else
                throw new NotImplementedException("Only C++ projects are supported at this time.");

            ProjectRef projectRef;
            if (!m_projectRefs.TryGetValue(name, out projectRef)) {
                projectRef = new ProjectRef(name);
                m_projectRefs.Add(name, projectRef);
            }

            Project project = new Project(root, name, type, language, rootFilter);

            projectRef.SetProject(project);

            foreach (var dep in projectDeps) {
                if (!m_projectRefs.ContainsKey(dep))
                    m_projectRefs.Add(dep, new ProjectRef(dep));
            }

            return true;
        }

        private Filter GatherProjectFiles (string pprojRoot, string projectLocation, IEnumerable<DirSpec> dirSpecs) {
            string projectPath = Path.GetFullPath(Path.Combine(pprojRoot, projectLocation));

            List<string> rootFiles = new List<string>();
            List<Filter> filters = new List<Filter>();
            foreach (var dirSpec in dirSpecs) {
                string includePath = Path.GetFullPath(Path.Combine(projectPath, dirSpec.include + "\\"));
                string[] files = Directory.GetFiles(
                    includePath,
                    "*.*",
                    dirSpec.recurse ? SearchOption.AllDirectories : SearchOption.TopDirectoryOnly
                );

                List<string> filterFiles = new List<string>();
                foreach (string file in files) {
                    string relPath = file.Substring(includePath.Length);
                    if (dirSpec.include != ".")
                        relPath = Path.Combine(dirSpec.include, relPath);
                    relPath = Path.Combine(projectLocation, relPath);
                    filterFiles.Add(relPath);
                }

                if (dirSpec.include == ".")
                    rootFiles = filterFiles;
                else {
                    var subfilters = new List<Filter>();
                    var filter = new Filter(dirSpec.include, subfilters, filterFiles);
                    filters.Add(filter);
                }
            }
            
            return new Filter(".", filters, rootFiles);
        }

        public bool GenerateProjects () {
            foreach (var projectRef in m_projectRefs.Values.OrderBy(p => p.Name)) {
                if (projectRef.Project == null)
                    throw new ArgumentException("Unresolved project-reference: '" + projectRef.Name + "'.");
                projectRef.Project.Write();
            }
            return true;
        }

        public bool GenerateSolutions () {
            throw new NotImplementedException();
        }
    }
}
