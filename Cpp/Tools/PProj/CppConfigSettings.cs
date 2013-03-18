using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PProjTool {

    #region Project Settings

    enum CharacterSet {
        NotSet,
        Unicode,
        MultiByte,
    }

    #endregion

    #region Compiler Options

    enum Optimization {
        Disabled,
        MinimizeSize,
        MaximizeSpeed,
        FullOptimization,
    }

    enum WholeProgramOptimization {
        No,
        LinkTimeCodeGeneration,
    }

    enum BasicRuntimeChecks {
        Default,
        StackFrames,
        UninitializedVariables,
        Both,
    }

    enum RuntimeLibrary {
        Multithreaded,
        MultithreadedDebug,
        MultithreadedDll,
        MultithreadedDebugDll,
    }

    enum WarningLevel {
        Off,
        W1,
        W2,
        W3,
        W4,
    }

    enum DebugInformationFormat {
        Disabled,
        C7Compatible,
        Unused,
        ProgramDatabase,
        ProgramDatabaseForEditAndContinue,
    }

    enum UsePrecompiledHeader {
        NotUsingPrecompiledHeaders,
        CreatePrecompiledHeader,
        UsePrecompiledHeader,
    }

    #endregion

    #region Linker Options

    enum OptimizeReferences {
        Default,
        KeepUnreferencedData,
        EliminateUnreferencedData,
    }

    enum EnableComdatFolding {
        Default,
        DoNotRemoveRedundantComdats,
        RemoveRedundantComdats,
    }

    enum TargetMachine {
        NotSet,
        X86,
        AM33,
        ARM,
        EBC,
        IA64,
        M32R,
        MIPS,
        MIPS16,
        MIPSFPU,
        MIPSFPU16,
        MIPSR41XX,
        SH3,
        SH3DSP,
        SH4,
        SH5,
        THUMB,
        X64,
    }

    #endregion
}
