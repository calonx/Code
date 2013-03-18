using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace PProjTool {
    class Solution {
        public string FullPath { get; private set; }
        public string Root { get; private set; }
        public string Name { get; private set; }
        public Guid Guid { get; private set; }

        private List<ProjectRef> m_dependencies;

        struct SlnConfig {
            public Configuration config;
            public Platform platform;

            public override string ToString () {
                return config.ToString() + "|" + platform.ToString();
            }
        }
        private List<SlnConfig> m_configs = new List<SlnConfig>() {
            new SlnConfig() { config = Configuration.Debug, platform = Platform.x64 },
            new SlnConfig() { config = Configuration.Release, platform = Platform.x64 },
        };

        public Solution (string root, string name, IEnumerable<ProjectRef> dependencies) {
            Root = root;
            Name = name;
            FullPath = Path.Combine(Root, Name + ".sln");
            Guid = GuidHash.CreateGuidFromPath(FullPath);
            m_dependencies = new List<ProjectRef>(dependencies);
        }

        public void Write () {
            StreamWriter writer = new StreamWriter(FullPath);
            writer.WriteLine("Microsoft Visual Studio Solution File, Format Version 10.00");
            writer.WriteLine("# Visual Studio 2008");
            foreach (var projectRef in m_dependencies)
                WriteProjectEntry(writer, projectRef);
            writer.WriteLine("Global");
            writer.WriteLine("    GlobalSection(SolutionConfigurationPlatforms) = preSolution");
            foreach (var config in m_configs)
                writer.WriteLine("{0} = {0}", config);
            writer.WriteLine("    EndGlobalSection");
            writer.WriteLine("    GlobalSection(ProjectConfigurationPlatforms) = postSolution");
            writer.WriteLine("    EndGlobalSection");
            writer.WriteLine("    GlobalSection(SolutionProperties) = preSolution");
            writer.WriteLine("        HideSolutionNode = FALSE");
            writer.WriteLine("    EndGlobalSection");
            writer.WriteLine("EndGlobal");
            writer.Close();
        }

        private void WriteProjectEntry (StreamWriter writer, ProjectRef projectRef) {
            IProject project = projectRef.Project;
            if (project == null)
                throw new ArgumentException("I encountered an unknown project named '" + projectRef.Name + "'.");

            string relativePath = PathExt.FilePathMakeRelative(Root, project.FullPath);

            writer.WriteLine(
                "Project(\"{0}\") = \"{1}\", \"{2}\"",
                Guid,
                project.Name,
                relativePath,
                project.Guid
            );
            //TODO: write project-dependencies here
            writer.WriteLine("EndProject");
        }
    }
}
