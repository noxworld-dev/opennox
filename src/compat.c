#ifndef _WIN32

#include "defs.h"

#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <fenv.h>
#include <glob.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include <wctype.h>

#include "common/fs/nox_fs.h"
#include "windows_compat.h"

void OutputDebugStringA(const char* lpOutputString) { fprintf(stderr, "%s", lpOutputString); }

char* nox_itoa(int val, char* s, int radix);
char* _itoa(int val, char* s, int radix) { return nox_itoa(val, s, radix); }

wchar_t* _itow(int val, wchar_t* s, int radix) {
	char tmp[32];
	unsigned int i;

	_itoa(val, tmp, radix);
	for (i = 0; tmp[i]; i++)
		s[i] = tmp[i];
	s[i] = 0;

	return s;
}

int InterlockedExchange(volatile int* Target, int Value) { return __sync_lock_test_and_set(Target, Value); }

// Time functions
// compatGetDateFormatA(Locale=2048, dwFlags=1, lpDate=0x1708c6a4, lpFormat=0x00000000, lpDateStr="nox.str:Warrior",
// cchDate=256) at compat.c:1001
int GetDateFormatA(LCID Locale, uint32_t dwFlags, const SYSTEMTIME* lpDate, const char* lpFormat, char* lpDateStr,
				   int cchDate) {
	if (Locale != 0x800 || dwFlags != 1 || lpFormat)
		abort();

	// default locale, short date (M/d/yy)
	return snprintf(lpDateStr, cchDate, "%d/%d/%02d", lpDate->wMonth, lpDate->wDay, lpDate->wYear % 100);
}

void GetLocalTime(LPSYSTEMTIME lpSystemTime) {
	time_t t;
	struct tm* tm;

	time(&t);
	tm = localtime(&t);

	lpSystemTime->wYear = tm->tm_year + 1900;
	lpSystemTime->wMonth = tm->tm_mon;
	lpSystemTime->wDayOfWeek = tm->tm_wday;
	lpSystemTime->wDay = tm->tm_mday;
	lpSystemTime->wHour = tm->tm_hour;
	lpSystemTime->wMinute = tm->tm_min;
	lpSystemTime->wSecond = tm->tm_sec;
	lpSystemTime->wMilliseconds = 0;
}

struct _FIND_FILE {
	size_t idx;
	glob_t globbuf;
};

static void fill_find_data(const char* path, LPWIN32_FIND_DATAA lpFindFileData) {
	struct stat st;
	const char* filename = strrchr(path, '/');
	filename = filename == NULL ? path : filename + 1;

	stat(path, &st);

	memset(lpFindFileData, 0, sizeof(*lpFindFileData));
	lpFindFileData->dwFileAttributes = S_ISDIR(st.st_mode) ? FILE_ATTRIBUTE_DIRECTORY : FILE_ATTRIBUTE_NORMAL;
	lpFindFileData->nFileSizeHigh = st.st_size >> 32;
	lpFindFileData->nFileSizeLow = st.st_size;
	strcpy(lpFindFileData->cFileName, filename);

	// _dprintf("%s: attr=0x%X, filename=%s", __FUNCTION__, lpFindFileData->dwFileAttributes,
	// lpFindFileData->cFileName);
}

HANDLE FindFirstFileA(const char* lpFileName, LPWIN32_FIND_DATAA lpFindFileData) {
	char* converted = nox_fs_normalize(lpFileName);
	int len = strlen(converted);
	struct _FIND_FILE* ff = calloc(sizeof(*ff), 1);

	// _dprintf("%s: converted=%s", __FUNCTION__, converted);

	// glob is close enough to the semantics
	if (len >= 2 && converted[len - 2] == '.' && converted[len - 1] == '*')
		converted[len - 2] = 0;
	if (glob(converted, GLOB_NOESCAPE, NULL, &ff->globbuf)) {
		free(converted);
		free(ff);
		return (HANDLE)-1;
	}
	free(converted);

	fill_find_data(ff->globbuf.gl_pathv[ff->idx++], lpFindFileData);
	return (HANDLE)ff;
}

int FindNextFileA(HANDLE hFindFile, LPWIN32_FIND_DATAA lpFindFileData) {
	struct _FIND_FILE* ff = (struct _FIND_FILE*)hFindFile;

	if (ff->idx >= ff->globbuf.gl_pathc) {
		return false;
	}

	fill_find_data(ff->globbuf.gl_pathv[ff->idx++], lpFindFileData);
	return true;
}

int FindClose(HANDLE hFindFile) {
	struct _FIND_FILE* ff = (struct _FIND_FILE*)hFindFile;

	globfree(&ff->globbuf);
	free(ff);
	return true;
}

#endif // _WIN32
