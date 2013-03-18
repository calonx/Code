using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace PProjTool {
    class Program {
        static void Main (string[] args) {
            PProjContext context = new PProjContext();
            foreach (var path in args) {
                if (!context.Load(path))
                    Console.WriteLine("Failed to load '" + path + "'.");
            }
            if (!context.GenerateProjects())
                Console.WriteLine("Project-generation failed.");
        }
    }
}
