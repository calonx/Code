using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;
using System.IO;

namespace PProjTool {
    class PathExt {
        [DllImport("shlwapi.dll", CharSet = CharSet.Auto)]
        static extern bool PathRelativePathTo (
             [Out] StringBuilder pszPath,
             [In] string pszFrom,
             [In] FileAttributes dwAttrFrom,
             [In] string pszTo,
             [In] FileAttributes dwAttrTo
        );

        const Int32 MAX_PATH = 260;

        public static string FilePathMakeRelative (string srcDir, string targetFile) {
            return MakeRelative(
                srcDir,
                FileAttributes.Directory,
                targetFile,
                FileAttributes.Normal
            );
        }

        public static string DirPathMakeRelative (string srcDir, string targetDir) {
            return MakeRelative(
                srcDir,
                FileAttributes.Directory,
                targetDir,
                FileAttributes.Directory
            );
        }

        private static string MakeRelative (
            string srcPath,
            FileAttributes srcAttributes,
            string targetPath,
            FileAttributes targetAttributes
        ) {
            StringBuilder relativePath = new StringBuilder(MAX_PATH);
            bool success = PathRelativePathTo(
                 relativePath,
                 srcPath,
                 srcAttributes,
                 targetPath,
                 targetAttributes
            );
            if (!success) {
                throw new ArgumentException(string.Format(
                    "Could not make path '{0}' relative to '{1}'",
                    srcPath,
                    targetPath
                ));
            }
            return relativePath.ToString();
        }
    }
}
