#include "Pch.h"

enum EWatchEvent {
    WATCH_EVENT_FILE_CREATE,
    WATCH_EVENT_FILE_DELETE,
    WATCH_EVENT_FILE_MODIFY,
    WATCH_EVENT_DIRECTORY_CREATE,
    WATCH_EVENT_DIRECTORY_DELETE,
    WATCH_EVENT_DIRECTORY_MODIFY,
    WATCH_EVENT_ABORT,
    WATCH_EVENTS
};

interface IFileWatchNotify {
    virtual void OnFileWatchEvent (EWatchEvent event, const wchar path[]) = 0;
    virtual void OnFileWatchAbort () = 0;
};

struct WatchEventInfo {
    EWatchEvent type;
    wchar       path[MAX_PATH];
};

class CWatchServer {
public:
    void Initialize ();
    void Shutdown ();

private:
};

static CWatchServer s_watchServer;

interface IWatcher {
    virtual void PushEvent (const WatchEventInfo & event) = 0;
};

class CWatcher : private IWatcher {
    CWatcher (IFileWatchNotify * notify);
    
    void PumpEvents ();
    void Stop ();
    void Watch (const wchar directory[]);
    
private: // IWatcher
    void PushEvent (const WatchEventInfo & event);

private:
    TArray<WatchEventInfo>  m_events;
    CRITICAL_SECTION        m_eventLock;
    IFileWatchNotify *      m_notify;
};

void CWatcher::PumpEvents () {
    TArray<WatchEventInfo> events;
    
    EnterCriticalSection(&m_eventLock);
    {
        m_events.Swap(&events);
    }
    LeaveCriticalSection(&m_eventLock);
    
    const WatchEventInfo * ptr = events.Ptr();
    const WatchEventInfo * end = events.End();
    for (; ptr != end; ++ptr)
        m_notify->OnFileWatchEvent(ptr->type, ptr->path);
}

void CWatcher::PushEvent (const WatchEventInfo & event) {
    EnterCriticalSection(&m_eventLock);
    {
        m_events.Add(event);
    }
    LeaveCriticalSection(&m_eventLock);
}

const uint READ_BUFFER_SIZE = 0x10000; // 16 KB


class CWatchWorker {
public:
    CWatchWorker (IWatcher * watcher);
    
private:
    void BeginRead ();

private:
    IWatcher * m_watcher;
    
    ubyte m_asyncBuffer[READ_BUFFER_SIZE];
    ubyte m_workingBuffer[READ_BUFFER_SIZE];
};


int main () {
    const wchar * watchPath = L"C:\\Files\\Temp\\Watch";
    //CWatcher 
}
