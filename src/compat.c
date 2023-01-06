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
