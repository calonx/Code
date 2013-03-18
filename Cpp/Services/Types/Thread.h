


typedef DWORD (WINAPI *FThreadProc)(void *);

template<class T, dword (T::*F)()>
DWORD WINAPI TThreadProc (void * user) {
    return (((T *)user)->*F)();
}

#define THREADPROC_WRAP(classType, methodName) (&TThreadProc<classType, &classType::methodName>)