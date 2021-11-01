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
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_PATH 260
#define INFINITE ((uint32_t)-1)

typedef void* HANDLE;
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

#pragma pack(push, 1)
typedef struct {
	uint16_t wFormatTag;
	uint16_t nChannels;
	uint32_t nSamplesPerSec;
	uint32_t nAvgBytesPerSec;
	uint16_t nBlockAlign;
	uint16_t wBitsPerSample;
	uint16_t cbSize;
} WAVEFORMATEX;

typedef struct {
	WAVEFORMATEX wfx;
	uint16_t wID;
	uint32_t fdwFlags;
	uint16_t nBlockSize;
	uint16_t nFramesPerBlock;
	uint16_t nCodecDelay;
} MPEGLAYER3WAVEFORMAT;
#pragma pack(pop)

typedef struct _GUID {
	uint32_t Data1;
	uint16_t Data2;
	uint16_t Data3;
	uint8_t Data4[8];
} GUID;
typedef GUID IID;

typedef struct _SYSTEMTIME {
	uint16_t wYear;
	uint16_t wMonth;
	uint16_t wDayOfWeek;
	uint16_t wDay;
	uint16_t wHour;
	uint16_t wMinute;
	uint16_t wSecond;
	uint16_t wMilliseconds;
} SYSTEMTIME, *LPSYSTEMTIME;

typedef struct _MEMORYSTATUS {
	uint32_t dwLength;
} MEMORYSTATUS, *LPMEMORYSTATUS;

typedef union _LARGE_INTEGER {
	uint64_t QuadPart;
	uint32_t LowPart;
} LARGE_INTEGER, *PLARGE_INTEGER;

typedef struct _FILETIME {
	uint32_t dwLowDateTime;
	uint32_t dwHighDateTime;
} FILETIME, *LPFILETIME;

typedef struct _SECURITY_ATTRIBUTES {
} SECURITY_ATTRIBUTES, *LPSECURITY_ATTRIBUTES;

typedef struct _CRITICAL_SECTION {
	void* opaque;
} CRITICAL_SECTION, *LPCRITICAL_SECTION;

typedef struct _OSVERSIONINFOA {
	uint32_t dwOSVersionInfoSize;
	uint32_t dwMajorVersion;
	uint32_t dwMinorVersion;
	uint32_t dwBuildNumber;
	uint32_t dwPlatformId;
	uint8_t szCSDVersion[128];
} OSVERSIONINFOA, *LPOSVERSIONINFOA;

typedef struct _WIN32_FIND_DATAA {
	uint32_t dwFileAttributes;
	FILETIME ftCreationTime;
	FILETIME ftLastAccessTime;
	FILETIME ftLastWriteTime;
	uint32_t nFileSizeHigh;
	uint32_t nFileSizeLow;
	uint32_t dwReserved0;
	uint32_t dwReserved1;
	char cFileName[MAX_PATH];
	char cAlternateFileName[14];
} WIN32_FIND_DATAA, *LPWIN32_FIND_DATAA;

typedef struct _OVERLAPPED {
} OVERLAPPED, *LPOVERLAPPED;

typedef struct _RECT {
	int left;
	int top;
	int right;
	int bottom;
} RECT, *LPRECT;

typedef struct _POINT {
	int x;
	int y;
} POINT;

typedef struct WSAData {
	uint16_t wVersion;
	uint16_t wHighVersion;
	char szDescription[257];
	char szSystemStatus[129];
	uint16_t iMaxSockets;
	uint16_t iMaxUdpDg;
	void* lpVendorInfo;
} WSADATA, *LPWSADATA;

struct compatin_addr {
	union {
		uint32_t S_addr;
	} S_un;
};

#include <sys/stat.h>
#undef st_mtime
#undef st_atime
#undef st_ctime
struct compat_stat {
	uint32_t st_dev;
	uint16_t st_ino;
	uint16_t st_mode;
	uint16_t st_nlink;
	uint16_t st_uid;
	uint16_t st_gid;
	uint32_t st_rdev;
	uint32_t st_size;
	uint32_t st_mtime;
	uint32_t st_atime;
	uint32_t st_ctime;
};

int WinMain(char* lpCmdLine);

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

int CloseHandle(HANDLE hObject);
uint32_t GetLastError();
void GetLocalTime(LPSYSTEMTIME lpSystemTime);
HANDLE FindFirstFileA(const char* lpFileName, LPWIN32_FIND_DATAA lpFindFileData);
int FindNextFileA(HANDLE hFindFile, LPWIN32_FIND_DATAA lpFindFileData);
int FindClose(HANDLE hFindFile);
int GetDateFormatA(LCID Locale, uint32_t dwFlags, const SYSTEMTIME* lpDate, const char* lpFormat, char* lpDateStr,
						  int cchDate);
int RegOpenKeyExA(HKEY hKey, const char* lpSubKey, uint32_t ulOptions, REGSAM samDesired, PHKEY phkResult);
int RegQueryValueExA(HKEY hKey, const char* lpValueName, uint32_t* lpReserved, uint32_t* lpType, uint8_t* lpData,
								uint32_t* lpcbData);
int RegSetValueExA(HKEY, const char* lpValueName, uint32_t Reserved, uint32_t dwType, const uint8_t* lpData, uint32_t cbData);
int RegCloseKey(HKEY hKey);
int MulDiv(int nNumber, int nNumerator, int nDenominator);
int RegCreateKeyExA(HKEY hKey, const char* lpSubKey, uint32_t Reserved, char* lpClass, uint32_t dwOptions,
							   REGSAM samDesired, const LPSECURITY_ATTRIBUTES lpSecurityAttributes, PHKEY phkResult,
							   uint32_t* lpdwDisposition);
void GlobalMemoryStatus(LPMEMORYSTATUS lpBuffer);
int QueryPerformanceCounter(LARGE_INTEGER* lpPerformanceCount);
int QueryPerformanceFrequency(LARGE_INTEGER* lpFrequency);
int HeapDestroy(HANDLE hHeap);
int GetVersionExA(LPOSVERSIONINFOA lpVersionInformation);
void OutputDebugStringA(const char* lpOutputString);
HINSTANCE ShellExecuteA(HWND hwnd, const char* lpOperation, const char* lpFile, const char* lpParameters, const char* lpDirectory,
							   int nShowCmd);
int GetTimeFormatA(LCID Locale, uint32_t dwFlags, const SYSTEMTIME* lpTime, const char* lpFormat, char* lpTimeStr,
						  int cchTime);
int SystemTimeToFileTime(const SYSTEMTIME* lpSystemTime, LPFILETIME lpFileTime);
int CompareFileTime(const FILETIME* lpFileTime1, const FILETIME* lpFileTime2);
HANDLE CreateMutexA(LPSECURITY_ATTRIBUTES lpSecurityAttributes, int bInitialOwner, const char* lpName);
int ReleaseMutex(HANDLE hMutex);
int SetEvent(HANDLE hEvent);
uint32_t WaitForSingleObject(HANDLE hHandle, uint32_t dwMilliseconds);
int WideCharToMultiByte(unsigned int CodePage, uint32_t dwFlags, const wchar_t* lpWideCharStr, int cchWideChar,
							   char* lpMultiByteStr, int cbMultiByte, const char* lpDefaultChar, int* lpUsedDefaultChar);

int InterlockedExchange(volatile int* Target, int Value);
int InterlockedDecrement(volatile int* Addend);
int InterlockedIncrement(volatile int* Addend);
int MessageBoxA(HWND hWnd, const char* lpText, const char* lpCaption, unsigned int uType);

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
static inline int CopyRect(LPRECT lprcDst, const RECT* lprcSrc) {
	*lprcDst = *lprcSrc;
	return true;
}
static inline int SetRect(LPRECT lprc, int xLeft, int yTop, int xRight, int yBottom) {
	lprc->left = xLeft;
	lprc->top = yTop;
	lprc->right = xRight;
	lprc->bottom = yBottom;
	return true;
}
static inline int IsRectEmpty(const RECT* lprc) {
	return lprc->right <= lprc->left || lprc->bottom <= lprc->top;
}

#ifdef __cplusplus
}
#endif

#endif
