using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PProjTool {
    static class GuidHash {

        public static Guid CreateGuidFromPath (string path) {

            // Sucky version that hopefully works for now (copied from Project.cs)
            Encoding encoding = Encoding.Default;
            byte[] srcBytes = encoding.GetBytes(path);
            byte[] dstBytes = new byte[16];
            int dstIndex = 0;
            for (int i = 0; i < srcBytes.Length; ++i) {
                dstBytes[dstIndex] ^= srcBytes[i];
                dstIndex = (dstIndex + 1) % 16;
            }
            return new Guid(dstBytes);
        }
    }
}
