#ifndef _WIN32

#include "cdrom.h"
#include "client__drawable__drawdb.h"
#include "client__draw__fx.h"
#include "client__draw__image.h"
#include "client__gui__guiinv.h"
#include "client__gui__guimeter.h"
#include "client__gui__guishop.h"
#include "client__gui__guispell.h"
#include "client__gui__servopts__guiserv.h"
#include "client__gui__window.h"
#include "client__io__win95__focus.h"
#include "client__network__netclint.h"
#include "client__shell__optsback.h"
#include "client__system__ctrlevnt.h"
#include "client__video__draw_common.h"
#include "client__video__sdl__draw_nogl.h"
#include "common__config.h"
#include "common__magic__speltree.h"
#include "defs.h"
#include "GAME1_1.h"
#include "GAME1_3.h"
#include "GAME1.h"
#include "GAME2_2.h"
#include "GAME2_3.h"
#include "GAME2.h"
#include "GAME3_3.h"
#include "GAME3.h"
#include "GAME4_1.h"
#include "GAME4.h"
#include "GAME5_2.h"
#include "input_common.h"
#include "input.h"
#include "legacy/client__video__ddraw__draw_ddraw.h"
#include "legacy/input_ddraw.h"
#include "legacy/mmx.h"
#include "legacy/win_ddraw.h"
#include "movie.h"
#include "server__network__mapsend.h"
#include "server__script__builtin.h"
#include "server__script__script.h"
#include "server__xfer__savegame__savegame.h"
#include "thing.h"
#include "win.h"

#include <ctype.h>
#include <fcntl.h>
#include <fenv.h>
#include <glob.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <unistd.h>
#include <wctype.h>
#include <errno.h>
#include <time.h>

#include "common/fs/nox_fs.h"

#ifndef NOX_CGO
#include <SDL2/SDL_stdinc.h>
#endif // NOX_CGO

#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#include <emscripten/html5.h>
#endif

enum {
	HANDLE_FILE,
	HANDLE_PROCESS,
	HANDLE_THREAD,
	HANDLE_MUTEX,
};

struct _REGKEY {
	char* path;
};

DWORD last_error;
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
	if (type != ((DWORD)h >> 16))
		return NULL;
	if ((WORD)h >= 1024)
		return NULL;
	return handles[(WORD)h];
}

void WINAPI OutputDebugStringA(LPCSTR lpOutputString) { fprintf(stderr, "%s", lpOutputString); }

// Memory functions
BOOL WINAPI HeapDestroy(HANDLE hHeap) {
	abort();
	return 0;
}

// CRT functions
unsigned int _control87(unsigned int new_, unsigned int mask) {
	if (new_ == 0x300 && mask == 0x300)
		fesetround(FE_TOWARDZERO);
	else
		abort();
	return 0;
}

unsigned int _controlfp(unsigned int new_, unsigned int mask) {
	if (new_ == 0x300 && mask == 0x300)
		fesetround(FE_TOWARDZERO);
	else
		abort();
	return 0;
}

typedef struct {
    void(* start_address)(void*);
    void* arglist;
} thread_arg_wrapper;

// thread_start_wrapper correctly converts WinAPI callback function signature to pthread callback signature.
void* thread_start_wrapper(void* arglist) {
    thread_arg_wrapper* arg = arglist;
    arglist = arg->arglist;
    void(* start_address)(void*) = arg->start_address;
    free(arg);
    start_address(arglist);
    return 0;
}

uintptr_t _beginthread(void(* start_address)(void*), unsigned int stack_size, void* arglist) {
#ifdef __EMSCRIPTEN__
	fprintf(stderr, "%s: unsupported\n");
	while (1) {
	}
#endif
	printf("thread start\n");
    thread_arg_wrapper* arg = (thread_arg_wrapper*)malloc(sizeof(thread_arg_wrapper));
	arg->start_address = start_address;
	arg->arglist = arglist;

	pthread_t handle;
	if (pthread_create(&handle, NULL, thread_start_wrapper, arg))
		return (uintptr_t)-1;

	return new_handle(HANDLE_THREAD, handle);
}

char* _strrev(char* str) {
	char *begin, *end;

	if (!str[0])
		return str;

	begin = str;
	end = str + strlen(str) - 1;

	while (begin < end) {
		char tmp = *end;
		*end = *begin;
		*begin = tmp;
	}

	return str;
}

#ifndef NOX_CGO
char* _itoa(int val, char* s, int radix) {
	return SDL_itoa(val, s, radix);
}

char* _utoa(unsigned int val, char* s, int radix) {
	return SDL_uitoa(val, s, radix);
}
#else // NOX_CGO
char* nox_itoa(int val, char* s, int radix);
char* nox_utoa(int val, char* s, int radix);
char* _itoa(int val, char* s, int radix) {
	return nox_itoa(val, s, radix);
}
char* _utoa(unsigned int val, char* s, int radix) {
	return nox_utoa(val, s, radix);
}
#endif // NOX_CGO

wchar_t* _itow(int val, wchar_t* s, int radix) {
	char tmp[32];
	unsigned int i;

	_itoa(val, tmp, radix);
	for (i = 0; tmp[i]; i++)
		s[i] = tmp[i];
	s[i] = 0;

	return s;
}

void _makepath(char* path, const char* drive, const char* dir, const char* fname, const char* ext) {
	sprintf(path, "%s%s%s%s%s%s%s", drive, drive && drive[0] && (!dir || dir[0] != '\\') ? "\\" : "", dir,
			dir && dir[0] && dir[strlen(dir) - 1] != '\\' ? "\\" : "", fname, ext && ext[0] && ext[0] != '.' ? "." : "",
			ext);
	// _dprintf("%s: (\"%s\", \"%s\", \"%s\", \"%s\") = \"%s\"", __FUNCTION__, drive, dir, fname, ext, path);
}

void _splitpath(const char* path, char* drive, char* dir, char* fname, char* ext) {
	const char* tmp;

	if (isalpha(path[0]) && path[1] == ':') {
		if (drive) {
			drive[0] = path[0];
			drive[1] = path[1];
			drive[2] = 0;
		}
		path += 2;
	} else if (drive) {
		drive[0] = 0;
	}

	tmp = strrchr(path, '\\');
	if (tmp) {
		if (dir) {
			memcpy(dir, path, tmp + 1 - path);
			dir[tmp + 1 - path] = 0;
		}
		path = tmp + 1;
	} else if (dir) {
		dir[0] = 0;
	}

	tmp = strrchr(path, '.');
	if (tmp) {
		if (fname) {
			memcpy(fname, path, tmp - path);
			fname[tmp - path] = 0;
		}
		path = tmp;
	} else if (fname) {
		fname[0] = 0;
	}

	if (ext) {
		strcpy(ext, path);
	}

	// _dprintf("%s: \"%s\" = (\"%s\", \"%s\", \"%s\", \"%s\")", __FUNCTION__, path, drive, dir, fname, ext);
}

// Misc functions
BOOL WINAPI CloseHandle(HANDLE hObject) {
	switch ((DWORD)hObject >> 16) {
	case 0:
		close((WORD)hObject);
		break;
	case HANDLE_THREAD:
		handles[(WORD)hObject] = NULL;
		break;
	case HANDLE_MUTEX: {
		pthread_mutex_t* m = lookup_handle(HANDLE_MUTEX, hObject);
		pthread_mutex_destroy(m);
		free(m);
	}
		handles[(WORD)hObject] = NULL;
		break;
	default:
		abort();
		return false;
	}

	return true;
}

DWORD WINAPI GetLastError() { return last_error; }

BOOL WINAPI GetVersionExA(LPOSVERSIONINFOA lpVersionInformation) {
	lpVersionInformation->dwOSVersionInfoSize = sizeof(OSVERSIONINFOA);
	lpVersionInformation->dwMajorVersion = 5;
	lpVersionInformation->dwMinorVersion = 1;
	return true;
}

LONG InterlockedExchange(volatile LONG* Target, LONG Value) { return __sync_lock_test_and_set(Target, Value); }

LONG InterlockedDecrement(volatile LONG* Addend) { return __sync_fetch_and_sub(Addend, 1); }

LONG InterlockedIncrement(volatile LONG* Addend) { return __sync_fetch_and_add(Addend, 1); }

int WINAPI MessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType) {
	abort();
	return 0;
}

int WINAPI MulDiv(int nNumber, int nNumerator, int nDenominator) {
	abort();
	return 0;
}

HINSTANCE WINAPI ShellExecuteA(HWND hwnd, LPCSTR lpOperation, LPCSTR lpFile, LPCSTR lpParameters, LPCSTR lpDirectory,
							   INT nShowCmd) {
	abort();
	return 0;
}

int WINAPI WideCharToMultiByte(UINT CodePage, DWORD dwFlags, LPCWSTR lpWideCharStr, int cchWideChar,
							   LPSTR lpMultiByteStr, int cbMultiByte, LPCCH lpDefaultChar, LPBOOL lpUsedDefaultChar) {
	abort();
	return 0;
}

#ifdef __EMSCRIPTEN__
void build_server_info(void* arg) {
	static char oldbuf[256];
	static int oldlen;
	char buf[256];
	int dummy[3] = {0, 0, 0};
	int length, ready;

	ready = EM_ASM_INT({ return network.isready(); });

	if (!ready) {
		oldlen = 0;
		return;
	}

	length = nox_server_makeServerInfoPacket_554040(dummy, sizeof(buf), buf);
	if (oldlen != length || memcmp(buf, oldbuf, length) != 0) {
		memcpy(oldbuf, buf, length);
		oldlen = length;

		EM_ASM_({ network.registerServer($1 > 0 ? Module.HEAPU8.slice($0, $0 + $1) : null); }, oldbuf, oldlen);
	}
}
#endif

// Time functions
// compatGetDateFormatA(Locale=2048, dwFlags=1, lpDate=0x1708c6a4, lpFormat=0x00000000, lpDateStr="nox.str:Warrior",
// cchDate=256) at compat.c:1001
int WINAPI GetDateFormatA(LCID Locale, DWORD dwFlags, const SYSTEMTIME* lpDate, LPCSTR lpFormat, LPSTR lpDateStr,
						  int cchDate) {
	if (Locale != 0x800 || dwFlags != 1 || lpFormat)
		abort();

	// default locale, short date (M/d/yy)
	return snprintf(lpDateStr, cchDate, "%d/%d/%02d", lpDate->wMonth, lpDate->wDay, lpDate->wYear % 100);
}

int WINAPI GetTimeFormatA(LCID Locale, DWORD dwFlags, const SYSTEMTIME* lpTime, LPCSTR lpFormat, LPSTR lpTimeStr,
						  int cchTime) {
	if (Locale != 0x800 || dwFlags != 14 || lpFormat)
		abort();

	// default locale, 24 hour, no time marker, no seconds
	return snprintf(lpTimeStr, cchTime, "%02d:%02d", lpTime->wHour, lpTime->wMinute);
}

BOOL WINAPI SystemTimeToFileTime(const SYSTEMTIME* lpSystemTime, LPFILETIME lpFileTime) {
	QWORD t;
	struct tm tm;

	tm.tm_sec = lpSystemTime->wSecond;
	tm.tm_min = lpSystemTime->wMinute;
	tm.tm_hour = lpSystemTime->wHour;
	tm.tm_mday = lpSystemTime->wDay;
	tm.tm_mon = lpSystemTime->wMonth;
	tm.tm_year = lpSystemTime->wYear - 1900;
	tm.tm_isdst = -1;
	tm.tm_zone = NULL;
	tm.tm_gmtoff = 0;

	t = mktime(&tm);
	t = (t * 1000 + lpSystemTime->wMilliseconds) * 10000;
	lpFileTime->dwLowDateTime = t & 0xffffffff;
	lpFileTime->dwHighDateTime = t >> 32;
	return 0;
}

LONG WINAPI CompareFileTime(const FILETIME* lpFileTime1, const FILETIME* lpFileTime2) {
	if (lpFileTime1->dwHighDateTime != lpFileTime2->dwHighDateTime)
		return (LONG)lpFileTime1->dwHighDateTime - (LONG)lpFileTime2->dwHighDateTime;
	if (lpFileTime1->dwLowDateTime != lpFileTime2->dwLowDateTime)
		return (LONG)lpFileTime1->dwLowDateTime - (LONG)lpFileTime2->dwLowDateTime;
	return 0;
}

void WINAPI GetLocalTime(LPSYSTEMTIME lpSystemTime) {
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

BOOL WINAPI QueryPerformanceCounter(LARGE_INTEGER* lpPerformanceCount) {
	struct timeval tv;

	gettimeofday(&tv, NULL);
	lpPerformanceCount->QuadPart = (QWORD)tv.tv_sec * 1000000 + tv.tv_usec;
	return true;
}

BOOL WINAPI QueryPerformanceFrequency(LARGE_INTEGER* lpFrequency) {
	lpFrequency->QuadPart = 1000000;
	return true;
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

HANDLE WINAPI FindFirstFileA(LPCSTR lpFileName, LPWIN32_FIND_DATAA lpFindFileData) {
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

BOOL WINAPI FindNextFileA(HANDLE hFindFile, LPWIN32_FIND_DATAA lpFindFileData) {
	struct _FIND_FILE* ff = (struct _FIND_FILE*)hFindFile;

	if (ff->idx >= ff->globbuf.gl_pathc) {
		last_error = ERROR_NO_MORE_FILES;
		return false;
	}

	fill_find_data(ff->globbuf.gl_pathv[ff->idx++], lpFindFileData);
	return true;
}

BOOL WINAPI FindClose(HANDLE hFindFile) {
	struct _FIND_FILE* ff = (struct _FIND_FILE*)hFindFile;

	globfree(&ff->globbuf);
	free(ff);
	return true;
}

int _open(const char* filename, int oflag, ...) {
	va_list ap;
	int fd;
	char* converted = nox_fs_normalize(filename);

	va_start(ap, oflag);
	fd = open(converted, oflag, va_arg(ap, int));
	va_end(ap);

	free(converted);
	return fd;
}

#ifndef NOX_CGO
int _chmod(const char* filename, int mode) {
	int result;
	char* converted = nox_fs_normalize(filename);
	result = chmod(converted, mode);
	free(converted);
	return result;
}
#endif // NOX_CGO

int _access(const char* filename, int mode) {
	int result;
	char* converted = nox_fs_normalize(filename);
	result = access(converted, mode);
	free(converted);
	return result;
}

int _stat(const char* path, struct _stat* buffer) {
	int result;
	char* converted = nox_fs_normalize(path);
	struct stat st;

	result = stat(converted, &st);
	free(converted);

	if (result)
		return result;

	buffer->st_dev = st.st_dev;
	buffer->st_ino = st.st_ino;
	buffer->st_mode = st.st_mode;
	buffer->st_nlink = st.st_nlink;
	buffer->st_uid = st.st_uid;
	buffer->st_gid = st.st_gid;
	buffer->st_rdev = st.st_rdev;
	buffer->st_size = st.st_size;
#ifdef __APPLE__
	buffer->st_mtime = st.st_mtimespec.tv_sec;
	buffer->st_atime = st.st_atimespec.tv_sec;
	buffer->st_ctime = st.st_ctimespec.tv_sec;
#else
	buffer->st_mtime = st.st_mtim.tv_sec;
	buffer->st_atime = st.st_atim.tv_sec;
	buffer->st_ctime = st.st_ctim.tv_sec;
#endif
	return result;
}

// Registry functions
LSTATUS WINAPI RegCreateKeyExA(HKEY hKey, LPCSTR lpSubKey, DWORD Reserved, LPSTR lpClass, DWORD dwOptions,
							   REGSAM samDesired, const LPSECURITY_ATTRIBUTES lpSecurityAttributes, PHKEY phkResult,
							   LPDWORD lpdwDisposition) {
	abort();
	return 0;
}

LSTATUS WINAPI RegOpenKeyExA(HKEY hKey, LPCSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult) {
	HKEY hkResult;
	const char* root;

	if (hKey == HKEY_LOCAL_MACHINE)
		root = "HKEY_LOCAL_MACHINE";
	else
		root = hKey->path;

	hkResult = calloc(sizeof(*hkResult), 1);
	hkResult->path = malloc(strlen(root) + strlen(lpSubKey) + 2);
	sprintf(hkResult->path, "%s\\%s", root, lpSubKey);
	*phkResult = hkResult;
	return 0;
}

LSTATUS WINAPI RegQueryValueExA(HKEY hKey, LPCSTR lpValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData,
								LPDWORD lpcbData) {
	_dprintf("%s: key=\"%s\", value=\"%s\"", __FUNCTION__, hKey->path, lpValueName);

	if (strcmp(hKey->path, "HKEY_LOCAL_MACHINE\\SOFTWARE\\Westwood\\Nox") == 0 && strcmp(lpValueName, "Serial") == 0) {
		int i;
		for (i = 0; i < *lpcbData - 1; i++)
			lpData[i] = (nox_platform_rand() % 10) + '0';
		lpData[i] = 0;
		*lpType = 1; // REG_SZ
		return 0;
	}

	return 3;
}

LSTATUS WINAPI RegSetValueExA(HKEY hKey, LPCSTR lpValueName, DWORD Reserved, DWORD dwType, const BYTE* lpData,
							  DWORD cbData) {
	abort();
	return 0;
}

LSTATUS WINAPI RegCloseKey(HKEY hKey) {
	free(hKey->path);
	free(hKey);
	return 0;
}

// Synchronization functions

HANDLE WINAPI CreateMutexA(LPSECURITY_ATTRIBUTES lpSecurityAttributes, BOOL bInitialOwner, LPCSTR lpName) {
	pthread_mutex_t* m = malloc(sizeof(pthread_mutex_t));
	pthread_mutexattr_t attr;

	pthread_mutexattr_init(&attr);
	pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
	pthread_mutex_init(m, &attr);
	pthread_mutexattr_destroy(&attr);

	if (bInitialOwner)
		pthread_mutex_lock(m);

	return new_handle(HANDLE_MUTEX, m);
}

BOOL WINAPI ReleaseMutex(HANDLE hMutex) {
	pthread_mutex_t* m = lookup_handle(HANDLE_MUTEX, hMutex);
	if (m == NULL)
		return false;
	pthread_mutex_unlock(m);
	return true;
}

BOOL WINAPI SetEvent(HANDLE hEvent) {
	abort();
	return 0;
}

#if defined(__APPLE__) || defined(__EMSCRIPTEN__) || defined(__CXGO__)
#else
int pthread_timedjoin_np(void*, void*, void*);
#endif

DWORD WINAPI WaitForSingleObject(HANDLE hHandle, DWORD dwMilliseconds) {
	DWORD result = (DWORD)-1;
	struct timespec tv;

	clock_gettime(CLOCK_REALTIME, &tv);
	tv.tv_sec += dwMilliseconds / 1000;
	tv.tv_nsec += (dwMilliseconds % 1000) * 1000000;
	while (tv.tv_nsec >= 1000000000) {
		tv.tv_sec++;
		tv.tv_nsec -= 1000000000;
	}

	switch ((DWORD)hHandle >> 16) {
	case HANDLE_THREAD: {
		pthread_t thr = lookup_handle(HANDLE_THREAD, hHandle);
		result = 0;
		if (dwMilliseconds == INFINITE)
			pthread_join(thr, NULL);
#if defined(__APPLE__) || defined(__EMSCRIPTEN__)
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
#if defined(__APPLE__) || defined(__EMSCRIPTEN__)
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
