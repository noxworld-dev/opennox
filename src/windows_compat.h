#ifndef COMPAT_WINDOWS_H
#define COMPAT_WINDOWS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <arpa/inet.h>
#include <fcntl.h>
#include <netdb.h>
#include <pthread.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define __fastcall
#define __stdcall

#define MAX_PATH 260
#define INFINITE ((DWORD)-1)

#define __int8 char
#define __int16 short
#define __int32 int
#define __int64 long long

typedef unsigned char BYTE;
typedef char CHAR;
typedef wchar_t WCHAR;
typedef unsigned short WORD;
typedef int INT;
typedef unsigned int DWORD;
typedef unsigned int UINT;
typedef int LONG;
typedef unsigned int ULONG;
typedef long long LONGLONG;
typedef unsigned long long ULONGLONG;
typedef uint64_t QWORD;
typedef void* LPVOID;
typedef DWORD DWORD_PTR;
typedef intptr_t INT_PTR;
typedef uintptr_t UINT_PTR;

typedef int BOOL;
typedef BOOL* LPBOOL;
typedef BYTE* LPBYTE;
typedef DWORD* LPDWORD;
typedef LONG* PLONG;
typedef const char* LPCCH;
typedef const char* LPCSTR;
typedef char* LPSTR;
typedef const wchar_t* LPCWSTR;
typedef wchar_t* LPWSTR;

typedef int HANDLE;
typedef int HDC;
typedef int HIMC;
typedef void* HINSTANCE;
typedef struct _REGKEY* HKEY;
typedef HKEY* PHKEY;
#define HKEY_LOCAL_MACHINE ((HKEY)1)
typedef int HKL;
typedef void* HMODULE;
typedef int HPALETTE;
typedef int HRESULT;
typedef int HWND;
typedef int LCID;
typedef int REGSAM;
typedef INT_PTR LRESULT;
typedef INT_PTR LSTATUS;
typedef INT_PTR LPARAM;
typedef UINT_PTR WPARAM;

typedef struct _WAVEOUT* HWAVEOUT;
typedef HWAVEOUT* LPHWAVEOUT;

typedef struct {
	WORD wFormatTag;
	WORD nChannels;
	DWORD nSamplesPerSec;
	DWORD nAvgBytesPerSec;
	WORD nBlockAlign;
} WAVEFORMAT, *LPWAVEFORMAT;

#pragma pack(push, 1)
typedef struct {
	WORD wFormatTag;
	WORD nChannels;
	DWORD nSamplesPerSec;
	DWORD nAvgBytesPerSec;
	WORD nBlockAlign;
	WORD wBitsPerSample;
	WORD cbSize;
} WAVEFORMATEX;

typedef struct {
	WAVEFORMATEX wfx;
	WORD wID;
	DWORD fdwFlags;
	WORD nBlockSize;
	WORD nFramesPerBlock;
	WORD nCodecDelay;
} MPEGLAYER3WAVEFORMAT;
#pragma pack(pop)

typedef struct _GUID {
	DWORD Data1;
	WORD Data2;
	WORD Data3;
	BYTE Data4[8];
} GUID;
typedef GUID IID;

typedef struct _SYSTEMTIME {
	WORD wYear;
	WORD wMonth;
	WORD wDayOfWeek;
	WORD wDay;
	WORD wHour;
	WORD wMinute;
	WORD wSecond;
	WORD wMilliseconds;
} SYSTEMTIME, *LPSYSTEMTIME;

typedef struct _MEMORYSTATUS {
	DWORD dwLength;
} MEMORYSTATUS, *LPMEMORYSTATUS;

typedef union _LARGE_INTEGER {
	QWORD QuadPart;
	DWORD LowPart;
} LARGE_INTEGER, *PLARGE_INTEGER;

typedef struct _FILETIME {
	DWORD dwLowDateTime;
	DWORD dwHighDateTime;
} FILETIME, *LPFILETIME;

typedef struct _SECURITY_ATTRIBUTES {
} SECURITY_ATTRIBUTES, *LPSECURITY_ATTRIBUTES;

typedef struct _CRITICAL_SECTION {
	void* opaque;
} CRITICAL_SECTION, *LPCRITICAL_SECTION;

typedef struct _OSVERSIONINFOA {
	DWORD dwOSVersionInfoSize;
	DWORD dwMajorVersion;
	DWORD dwMinorVersion;
	DWORD dwBuildNumber;
	DWORD dwPlatformId;
	BYTE szCSDVersion[128];
} OSVERSIONINFOA, *LPOSVERSIONINFOA;

typedef struct _WIN32_FIND_DATAA {
	DWORD dwFileAttributes;
	FILETIME ftCreationTime;
	FILETIME ftLastAccessTime;
	FILETIME ftLastWriteTime;
	DWORD nFileSizeHigh;
	DWORD nFileSizeLow;
	DWORD dwReserved0;
	DWORD dwReserved1;
	CHAR cFileName[MAX_PATH];
	CHAR cAlternateFileName[14];
} WIN32_FIND_DATAA, *LPWIN32_FIND_DATAA;

typedef struct _OVERLAPPED {
} OVERLAPPED, *LPOVERLAPPED;

typedef struct _RECT {
	LONG left;
	LONG top;
	LONG right;
	LONG bottom;
} RECT, *LPRECT;

typedef struct _POINT {
	LONG x;
	LONG y;
} POINT;

typedef struct WSAData {
	WORD wVersion;
	WORD wHighVersion;
	CHAR szDescription[257];
	CHAR szSystemStatus[129];
	WORD iMaxSockets;
	WORD iMaxUdpDg;
	LPVOID lpVendorInfo;
} WSADATA, *LPWSADATA;

struct compatin_addr {
	union {
		DWORD S_addr;
	} S_un;
};

#include <sys/stat.h>
#undef st_mtime
#undef st_atime
#undef st_ctime
struct compat_stat {
	DWORD st_dev;
	WORD st_ino;
	WORD st_mode;
	WORD st_nlink;
	WORD st_uid;
	WORD st_gid;
	DWORD st_rdev;
	DWORD st_size;
	DWORD st_mtime;
	DWORD st_atime;
	DWORD st_ctime;
};

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd);

enum {
	FILE_ATTRIBUTE_DIRECTORY = 0x10,
	FILE_ATTRIBUTE_NORMAL = 0x80,
};

enum {
	ERROR_NO_MORE_FILES = 18,
};

enum {
	LOCALE_SYSTEM_DEFAULT = 0x800,
};

enum {
	DATE_SHORTDATE = 0x1,
};

enum {
	TIME_NOSECONDS = 0x2,
	TIME_NOTIMEMARKER = 0x4,
	TIME_FORCE24HOURFORMAT = 0x8,
};

#define CloseHandle compatCloseHandle
#define GetLastError compatGetLastError
#define GetLocalTime compatGetLocalTime
#define FindFirstFileA compatFindFirstFileA
#define FindNextFileA compatFindNextFileA
#define FindClose compatFindClose
#define GetDateFormatA compatGetDateFormatA
#define RegOpenKeyExA compatRegOpenKeyExA
#define RegQueryValueExA compatRegQueryValueExA
#define RegSetValueExA compatRegSetValueExA
#define RegCloseKey compatRegCloseKey
#define MulDiv compatMulDiv
#define RegCreateKeyExA compatRegCreateKeyExA
#define GlobalMemoryStatus compatGlobalMemoryStatus
#define QueryPerformanceCounter compatQueryPerformanceCounter
#define QueryPerformanceFrequency compatQueryPerformanceFrequency
#define HeapDestroy compatHeapDestroy
#define GetVersionExA compatGetVersionExA
#define OutputDebugStringA compatOutputDebugStringA
#define ShellExecuteA compatShellExecuteA
#define GetTimeFormatA compatGetTimeFormatA
#define SystemTimeToFileTime compatSystemTimeToFileTime
#define CompareFileTime compatCompareFileTime
#define CreateMutexA compatCreateMutexA
#define ReleaseMutex compatReleaseMutex
#define SetEvent compatSetEvent
#define WaitForSingleObject compatWaitForSingleObject
#define CopyRect compatCopyRect
#define SetRect compatSetRect
#define IsRectEmpty compatIsRectEmpty
#define _rotl compat_rotl
#define _strrev compat_strrev
#define _itoa compat_itoa
#define _itow compat_itow
#define _makepath compat_makepath
#define _splitpath compat_splitpath
#define InterlockedExchange compatInterlockedExchange
#define InterlockedDecrement compatInterlockedDecrement
#define InterlockedIncrement compatInterlockedIncrement
#define MessageBoxA compatMessageBoxA
#define _beginthread compat_beginthread
#define WideCharToMultiByte compatWideCharToMultiByte
#define _control87 compat_control87
#define _controlfp compat_controlfp
#define _open compat_open
#define _chmod compat_chmod
#define _access compat_access
#define _stat compat_stat

#define _strdup strdup
#define _strcmpi strcasecmp
#define _strnicmp strncasecmp
#define _fileno fileno
#define _read read
#define _write write
#define _close close

BOOL CloseHandle(HANDLE hObject);
DWORD GetLastError();
void GetLocalTime(LPSYSTEMTIME lpSystemTime);
HANDLE FindFirstFileA(LPCSTR lpFileName, LPWIN32_FIND_DATAA lpFindFileData);
BOOL FindNextFileA(HANDLE hFindFile, LPWIN32_FIND_DATAA lpFindFileData);
BOOL FindClose(HANDLE hFindFile);
int GetDateFormatA(LCID Locale, DWORD dwFlags, const SYSTEMTIME* lpDate, LPCSTR lpFormat, LPSTR lpDateStr,
						  int cchDate);
LSTATUS RegOpenKeyExA(HKEY hKey, LPCSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult);
LSTATUS RegQueryValueExA(HKEY hKey, LPCSTR lpValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData,
								LPDWORD lpcbData);
LSTATUS RegSetValueExA(HKEY, LPCSTR lpValueName, DWORD Reserved, DWORD dwType, const BYTE* lpData, DWORD cbData);
LSTATUS RegCloseKey(HKEY hKey);
int MulDiv(int nNumber, int nNumerator, int nDenominator);
LSTATUS RegCreateKeyExA(HKEY hKey, LPCSTR lpSubKey, DWORD Reserved, LPSTR lpClass, DWORD dwOptions,
							   REGSAM samDesired, const LPSECURITY_ATTRIBUTES lpSecurityAttributes, PHKEY phkResult,
							   LPDWORD lpdwDisposition);
void GlobalMemoryStatus(LPMEMORYSTATUS lpBuffer);
BOOL QueryPerformanceCounter(LARGE_INTEGER* lpPerformanceCount);
BOOL QueryPerformanceFrequency(LARGE_INTEGER* lpFrequency);
BOOL HeapDestroy(HANDLE hHeap);
BOOL GetVersionExA(LPOSVERSIONINFOA lpVersionInformation);
void OutputDebugStringA(LPCSTR lpOutputString);
HINSTANCE ShellExecuteA(HWND hwnd, LPCSTR lpOperation, LPCSTR lpFile, LPCSTR lpParameters, LPCSTR lpDirectory,
							   INT nShowCmd);
int GetTimeFormatA(LCID Locale, DWORD dwFlags, const SYSTEMTIME* lpTime, LPCSTR lpFormat, LPSTR lpTimeStr,
						  int cchTime);
BOOL SystemTimeToFileTime(const SYSTEMTIME* lpSystemTime, LPFILETIME lpFileTime);
LONG CompareFileTime(const FILETIME* lpFileTime1, const FILETIME* lpFileTime2);
HANDLE CreateMutexA(LPSECURITY_ATTRIBUTES lpSecurityAttributes, BOOL bInitialOwner, LPCSTR lpName);
BOOL ReleaseMutex(HANDLE hMutex);
BOOL SetEvent(HANDLE hEvent);
DWORD WaitForSingleObject(HANDLE hHandle, DWORD dwMilliseconds);
int WideCharToMultiByte(UINT CodePage, DWORD dwFlags, LPCWSTR lpWideCharStr, int cchWideChar,
							   LPSTR lpMultiByteStr, int cbMultiByte, LPCCH lpDefaultChar, LPBOOL lpUsedDefaultChar);

LONG InterlockedExchange(volatile LONG* Target, LONG Value);
LONG InterlockedDecrement(volatile LONG* Addend);
LONG InterlockedIncrement(volatile LONG* Addend);
int MessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType);

unsigned int _control87(unsigned int new_, unsigned int mask);
unsigned int _controlfp(unsigned int new_, unsigned int mask);
uintptr_t _beginthread(void(* start_address)(void*), unsigned int stack_size, void* arglist);
char* _strrev(char* str);
char* _itoa(int val, char* s, int radix);
wchar_t* _itow(int val, wchar_t* s, int radix);
void _makepath(char* path, const char* drive, const char* dir, const char* fname, const char* ext);
void _splitpath(const char* path, char* drive, char* dir, char* fname, char* ext);
int _open(const char* filename, int oflag, ...);
int _chmod(const char* filename, int mode);
int _access(const char* filename, int mode);
int _stat(const char* path, struct _stat* buffer);

static inline unsigned int _rotl(unsigned int value, int shift) {
	unsigned int c = shift & 31;
	if (c == 0)
		return value;
	return (value << c) | (value >> (32 - c));
}
static inline BOOL CopyRect(LPRECT lprcDst, const RECT* lprcSrc) {
	*lprcDst = *lprcSrc;
	return true;
}
static inline BOOL SetRect(LPRECT lprc, int xLeft, int yTop, int xRight, int yBottom) {
	lprc->left = xLeft;
	lprc->top = yTop;
	lprc->right = xRight;
	lprc->bottom = yBottom;
	return true;
}
static inline BOOL IsRectEmpty(const RECT* lprc) {
	return lprc->right <= lprc->left || lprc->bottom <= lprc->top;
}

#ifdef __cplusplus
}
#endif

#endif
