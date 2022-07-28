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

enum {
	HANDLE_FILE,
	HANDLE_PROCESS,
	HANDLE_THREAD,
	HANDLE_MUTEX,
};

void* handles[1024];

static inline HANDLE new_handle(unsigned int type, void* data) {
	unsigned int i;
	for (i = 0; i < 1024; i++) {
		if (!handles[i]) {
			handles[i] = data;
			return (HANDLE)((type << 16) | i);
		}
	}
	return (HANDLE)-1;
}

static inline void* lookup_handle(unsigned int type, HANDLE h) {
	if (type != ((uint32_t)h >> 16))
		return NULL;
	if ((uint16_t)h >= 1024)
		return NULL;
	return handles[(uint16_t)h];
}

void OutputDebugStringA(const char* lpOutputString) { fprintf(stderr, "%s", lpOutputString); }

// Memory functions
int HeapDestroy(HANDLE hHeap) {
	abort();
	return 0;
}

char* nox_itoa(int val, char* s, int radix);
char* nox_utoa(int val, char* s, int radix);
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

// Misc functions
int CloseHandle(HANDLE hObject) {
	switch ((uint32_t)hObject >> 16) {
	case 0:
		close((uint16_t)hObject);
		break;
	case HANDLE_THREAD:
		handles[(uint16_t)hObject] = NULL;
		break;
	case HANDLE_MUTEX: {
		pthread_mutex_t* m = lookup_handle(HANDLE_MUTEX, hObject);
		pthread_mutex_destroy(m);
		free(m);
	}
		handles[(uint16_t)hObject] = NULL;
		break;
	default:
		abort();
		return false;
	}

	return true;
}

int InterlockedExchange(volatile int* Target, int Value) { return __sync_lock_test_and_set(Target, Value); }

int InterlockedDecrement(volatile int* Addend) { return __sync_fetch_and_sub(Addend, 1); }

int InterlockedIncrement(volatile int* Addend) { return __sync_fetch_and_add(Addend, 1); }

int MulDiv(int nNumber, int nNumerator, int nDenominator) {
	abort();
	return 0;
}

HINSTANCE ShellExecuteA(HWND hwnd, const char* lpOperation, const char* lpFile, const char* lpParameters,
						const char* lpDirectory, int nShowCmd) {
	abort();
	return 0;
}

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

// Synchronization functions

HANDLE CreateMutexA(LPSECURITY_ATTRIBUTES lpSecurityAttributes, int bInitialOwner, const char* lpName) {
	pthread_mutex_t* m = calloc(1, sizeof(pthread_mutex_t));
	pthread_mutexattr_t attr;

	pthread_mutexattr_init(&attr);
	pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
	pthread_mutex_init(m, &attr);
	pthread_mutexattr_destroy(&attr);

	if (bInitialOwner)
		pthread_mutex_lock(m);

	return new_handle(HANDLE_MUTEX, m);
}

int ReleaseMutex(HANDLE hMutex) {
	pthread_mutex_t* m = lookup_handle(HANDLE_MUTEX, hMutex);
	if (m == NULL)
		return false;
	pthread_mutex_unlock(m);
	return true;
}

int SetEvent(HANDLE hEvent) {
	abort();
	return 0;
}

#if defined(__APPLE__) || defined(__CXGO__)
#else
int pthread_timedjoin_np(void*, void*, void*);
#endif

uint32_t WaitForSingleObject(HANDLE hHandle, uint32_t dwMilliseconds) {
	uint32_t result = (uint32_t)-1;
	struct timespec tv;

	clock_gettime(CLOCK_REALTIME, &tv);
	tv.tv_sec += dwMilliseconds / 1000;
	tv.tv_nsec += (dwMilliseconds % 1000) * 1000000;
	while (tv.tv_nsec >= 1000000000) {
		tv.tv_sec++;
		tv.tv_nsec -= 1000000000;
	}

	switch ((uint32_t)hHandle >> 16) {
	case HANDLE_THREAD: {
		pthread_t thr = lookup_handle(HANDLE_THREAD, hHandle);
		result = 0;
		if (dwMilliseconds == INFINITE)
			pthread_join(thr, NULL);
#if defined(__APPLE__)
		else
			pthread_join(thr, NULL);
#else
		else if (pthread_timedjoin_np(thr, NULL, &tv) == ETIMEDOUT)
			result = 0x102;
#endif
	} break;
	case HANDLE_MUTEX: {
		pthread_mutex_t* m = lookup_handle(HANDLE_MUTEX, hHandle);
		result = 0;
		if (dwMilliseconds == INFINITE)
			pthread_mutex_lock(m);
#if defined(__APPLE__)
		else
			pthread_mutex_lock(m);
#else
		else if (pthread_mutex_timedlock(m, &tv) == ETIMEDOUT)
			result = 0x102;
#endif
	} break;
	default:
		abort();
		break;
	}

	return result;
}

#endif // _WIN32
