
#undef  interface
#define interface struct __declspec(novtable)

#undef byte
typedef wchar_t         wchar;
typedef unsigned        dword;
typedef unsigned        uint;
typedef unsigned short  ushort;
typedef unsigned char   byte;
typedef char            sbyte;

template<typename T, uint size>
uint arrsize (T(&)[size]) { return size; }

template<class T>
inline void Swap (T & lhs, T & rhs) {
    T temp = lhs;
    lhs = rhs;
    rhs = temp;
}

template<class T>
inline void ZeroPtr (T * t) {
    memset(t, 0, sizeof(T));
}

template<class T>
inline void MemCopy (T * dst, const T * src, uint count) {
    memcpy(dst, src, count * sizeof(T));
}

template<class T>
inline void MemCopy (void * dst, const T * src, uint count) {
    memcpy(reinterpret_cast<T *>(dst), src, count * sizeof(T));
}


//==============================================================================
// Conditional-compilation replacements
//==============================================================================

#ifndef NDEBUG

inline bool EnvIsDebug ()   { return true;  }
inline bool EnvIsRelease () { return false; }

#else

inline bool EnvIsDebug ()   { return false; }
inline bool EnvIsRelease () { return true;  }

#endif // NDEBUG