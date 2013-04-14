namespace PCommon
{

#include "Types.h"
#include "Math.h"



template<typename T>
inline void Release (T ** ppT)
{
    if (*ppT)
    {
        (*ppT)->Release();
        *ppT = NULL;
    }
}

template<typename T, size_t N>
inline void MemZero(T (& dst)[N])
{
    memset(&dst, 0, sizeof(dst));
}

template<typename T>
inline void MemZero (T * pT)
{
    memset(pT, 0, sizeof(T));
}

template<typename T>
inline void MemZero (T ** pT)
{
    static_assert(false, "Don't use MemZero to clear pointers.");
}

template<typename T>
inline void ArrCopy(const T * src, T * dst, s32 count)
{
    for (s32 i = 0; i < count; ++i)
        dst[i] = src[i];
}

template<typename T, size_t N>
void StrCopy(const T * src, T (* dst)[N])
{
    static_assert(N > 0);

    s32 i = 0;
    for (; i < N - 1; ++i)
        dst[i] = src[i];
    dst[i] = 0;
}



namespace Internal
{

template <typename T, size_t N>
T (&_ArraySizeHelper (T (&)[N])) [N];

} // namespace Internal

#define countof(array) (sizeof(Internal::_ArraySizeHelper(array)))

} // namespace PCommon
