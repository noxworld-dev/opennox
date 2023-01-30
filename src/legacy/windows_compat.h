#ifndef COMPAT_WINDOWS_H
#define COMPAT_WINDOWS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH 260

typedef void* HANDLE;
typedef void* HINSTANCE;
typedef int HWND;
typedef int LCID;

typedef struct _FILETIME {
	uint32_t dwLowDateTime;
	uint32_t dwHighDateTime;
} FILETIME, *LPFILETIME;

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

#define FindFirstFileA compatFindFirstFileA
#define FindNextFileA compatFindNextFileA
#define FindClose compatFindClose

HANDLE FindFirstFileA(const char* lpFileName, LPWIN32_FIND_DATAA lpFindFileData);
int FindNextFileA(HANDLE hFindFile, LPWIN32_FIND_DATAA lpFindFileData);
int FindClose(HANDLE hFindFile);

#ifdef __cplusplus
}
#endif

#endif
