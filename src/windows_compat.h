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
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_PATH 260
#define INFINITE ((uint32_t)-1)

typedef void* HANDLE;
typedef int HIMC;
typedef void* HINSTANCE;
typedef int HWND;
typedef int LCID;

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

typedef struct _FILETIME {
	uint32_t dwLowDateTime;
	uint32_t dwHighDateTime;
} FILETIME, *LPFILETIME;

typedef struct _SECURITY_ATTRIBUTES {
} SECURITY_ATTRIBUTES, *LPSECURITY_ATTRIBUTES;

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

typedef struct _RECT {
	int min_x;
	int min_y;
	int max_x;
	int max_y;
} RECT, *LPRECT;

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

enum {
	FILE_ATTRIBUTE_DIRECTORY = 0x10,
	FILE_ATTRIBUTE_NORMAL = 0x80,
};

#define CloseHandle compatCloseHandle
#define GetLocalTime compatGetLocalTime
#define FindFirstFileA compatFindFirstFileA
#define FindNextFileA compatFindNextFileA
#define FindClose compatFindClose
#define GetDateFormatA compatGetDateFormatA
#define MulDiv compatMulDiv
#define HeapDestroy compatHeapDestroy
#define OutputDebugStringA compatOutputDebugStringA
#define ShellExecuteA compatShellExecuteA
#define CreateMutexA compatCreateMutexA
#define ReleaseMutex compatReleaseMutex
#define SetEvent compatSetEvent
#define WaitForSingleObject compatWaitForSingleObject
#define CopyRect compatCopyRect
#define SetRect compatSetRect
#define _rotl compat_rotl
#define _itoa compat_itoa
#define _itow compat_itow
#define InterlockedExchange compatInterlockedExchange
#define InterlockedDecrement compatInterlockedDecrement
#define InterlockedIncrement compatInterlockedIncrement
#define _open compat_open
#define _stat compat_stat

#define _strdup strdup
#define _strcmpi strcasecmp
#define _strnicmp strncasecmp

int CloseHandle(HANDLE hObject);
void GetLocalTime(LPSYSTEMTIME lpSystemTime);
HANDLE FindFirstFileA(const char* lpFileName, LPWIN32_FIND_DATAA lpFindFileData);
int FindNextFileA(HANDLE hFindFile, LPWIN32_FIND_DATAA lpFindFileData);
int FindClose(HANDLE hFindFile);
int GetDateFormatA(LCID Locale, uint32_t dwFlags, const SYSTEMTIME* lpDate, const char* lpFormat, char* lpDateStr,
				   int cchDate);
int MulDiv(int nNumber, int nNumerator, int nDenominator);
int HeapDestroy(HANDLE hHeap);
void OutputDebugStringA(const char* lpOutputString);
HINSTANCE ShellExecuteA(HWND hwnd, const char* lpOperation, const char* lpFile, const char* lpParameters,
						const char* lpDirectory, int nShowCmd);
HANDLE CreateMutexA(LPSECURITY_ATTRIBUTES lpSecurityAttributes, int bInitialOwner, const char* lpName);
int ReleaseMutex(HANDLE hMutex);
int SetEvent(HANDLE hEvent);
uint32_t WaitForSingleObject(HANDLE hHandle, uint32_t dwMilliseconds);

int InterlockedExchange(volatile int* Target, int Value);
int InterlockedDecrement(volatile int* Addend);
int InterlockedIncrement(volatile int* Addend);

char* _itoa(int val, char* s, int radix);
wchar_t* _itow(int val, wchar_t* s, int radix);
int _open(const char* filename, int oflag, ...);
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
	lprc->min_x = xLeft;
	lprc->min_y = yTop;
	lprc->max_x = xRight;
	lprc->max_y = yBottom;
	return true;
}

#ifdef __cplusplus
}
#endif

#endif
