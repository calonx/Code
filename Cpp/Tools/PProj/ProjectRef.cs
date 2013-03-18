using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PProjTool {
    class ProjectRef {
        public string Name { get; set; }
        public IProject Project { get; private set; }

        public ProjectRef (string name) {
            Name = name;
        }

        public ProjectRef (string name, IProject project) {
            Name = name;
            Project = project;
        }

        public void SetProject (IProject project) {
            if (Project != null)
                throw new InvalidOperationException(string.Format("Project '{0}' is already defined!", Name));
            Project = project;
        }
    }
}
