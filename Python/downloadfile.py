import urllib.request
import sys

def DownloadFile (srcUri, savePath):
    print('Downloading...')
    data = urllib.request.urlopen(srcUri).read()
    print('Writing to ' + savePath)
    f = open(savePath, 'wb')
    f.write(data)
    f.close()
    print('Done!')

if len(sys.argv) == 3:
    DownloadFile(sys.argv[1], sys.argv[2])
else:
    print("Usage: downloadfile.py <source URI> <save path>")