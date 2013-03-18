#include "Pch.h"

// Excellent reference: http://qualapps.blogspot.com/2010/05/understanding-readdirectorychangesw.html


class CFileWatchThread {
    static void ThreadProc ();
};

static void ThreadProc ();


class CFileWatcher : public IFileWatcher {

};

IFileWatcher * FileWatcherCreate () {
    return new CFileWatcher();
}
