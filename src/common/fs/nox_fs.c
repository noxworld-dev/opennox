//+build none

#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "nox_fs.h"

#ifdef _WIN32
#include <windows.h>
#else // !_WIN32
#include <sys/stat.h>
#endif // _WIN32

char __nox_fs_root[NOX_FILEPATH_MAX + 1] = {0};

//----- (00409E10) --------------------------------------------------------
const char* nox_fs_root() { return __nox_fs_root; }

//----- (00409E20) --------------------------------------------------------
void nox_fs_set_root(const char* wd) {
	strncpy(__nox_fs_root, wd, NOX_FILEPATH_MAX);
	__nox_fs_root[NOX_FILEPATH_MAX] = 0;
}

#ifndef _WIN32
#include <dirent.h>
#include <unistd.h>

//#define DOS2UNIX_LOGGING
char* dos_to_unix_recurse_paths(char* currentPath, char* unparsedPath) {
	// Check if we still have something left to recurse
	if (unparsedPath[0] == 0 || (unparsedPath[0] == '/' && unparsedPath[1] == 0)) {
		return currentPath;
	}

	// Extract the current token from the unparsed string
	char dirOrig[NOX_FILEPATH_MAX] = {0};
	char dirLower[NOX_FILEPATH_MAX] = {0};
	char* unparsedLeft = unparsedPath;
	char* token = strchr(unparsedLeft, '/');
	if (token != NULL) {
		strncpy(dirOrig, unparsedLeft, token - unparsedLeft);
		unparsedLeft += strlen(dirOrig) + 1;
		int i;
		for (i = 0; dirOrig[i]; i++) {
			dirLower[i] = tolower(dirOrig[i]);
		}
	} else {
		strcpy(dirOrig, unparsedLeft);
		unparsedLeft += strlen(dirOrig);
		int i;
		for (i = 0; dirOrig[i]; i++) {
			dirLower[i] = tolower(dirOrig[i]);
		}
	}

	// Special check for glob characters
	if (strchr(dirOrig, '*')) {
		char temp[NOX_FILEPATH_MAX];
		sprintf(temp, "%s/%s", currentPath, dirOrig);
		strcpy(currentPath, temp);
		return currentPath;
	}

	// Open the directory and compare all the lowercased files/folders with the current lowercased token
	DIR* d = opendir(currentPath[0] == 0 ? "/" : currentPath);
	if (!d) {
		printf("Opendir errno: %d\n", errno);
		// abort();
		// If we couldn't open the directory, just assume it's correct - this might be access errors in root paths
		char temp[NOX_FILEPATH_MAX];
		sprintf(temp, "%s/%s", currentPath, dirOrig);
		strcpy(currentPath, temp);
		return dos_to_unix_recurse_paths(currentPath, unparsedLeft);
	}

	struct dirent* dir;
	char foundExactCase[NOX_FILEPATH_MAX] = {0};
	char foundAnyCase[NOX_FILEPATH_MAX] = {0};

	while ((dir = readdir(d)) != NULL) {
		int i;

		// First we try to match a lowercased match
		if (!strcmp(dir->d_name, dirLower)) {
			char temp[NOX_FILEPATH_MAX];
			sprintf(temp, "%s/%s", currentPath, dirLower);
			strcpy(currentPath, temp);
			closedir(d);
			return dos_to_unix_recurse_paths(currentPath, unparsedLeft);
		}

		// Next we try to match an existing exact matched version
		if (!strcmp(dir->d_name, dirOrig)) {
			strcpy(foundExactCase, dir->d_name);
			// We do not break because we still hope to find a lowercased match
		}

		// And then we try to match whatever left, by lowercasing whatever we got
		char buf[NOX_FILEPATH_MAX] = {0};
		for (i = 0; dir->d_name[i]; i++) {
			buf[i] = tolower(dir->d_name[i]);
		}

		if (!strcmp(buf, dirLower)) {
			strcpy(foundAnyCase, dir->d_name);
			// We do not break because we still hope to find an exact or lowercased match
		}
	}
	closedir(d);

	// Now check if we found an exact match
	if (foundExactCase[0] != 0) {
		char temp[NOX_FILEPATH_MAX];
		sprintf(temp, "%s/%s", currentPath, foundExactCase);
		strcpy(currentPath, temp);
#ifdef DOS2UNIX_LOGGING
		printf("dos2unix: file %s not found in lower case, returning exact found case %s\n", dirOrig, foundExactCase);
#endif
		return dos_to_unix_recurse_paths(currentPath, unparsedLeft);
	}

	// ... or at least in any case?
	if (foundAnyCase[0] != 0) {
		char temp[NOX_FILEPATH_MAX];
		sprintf(temp, "%s/%s", currentPath, foundAnyCase);
		strcpy(currentPath, temp);
#ifdef DOS2UNIX_LOGGING
		printf("dos2unix: file %s not found in lower or exact case, returning any other found case %s\n", dirOrig,
			   foundAnyCase);
#endif
		return dos_to_unix_recurse_paths(currentPath, unparsedLeft);
	}

	// If we still found nothing means the file or folder probably doesn't exist
	// Let's just return whatever we constructed before with anything left
	char temp[NOX_FILEPATH_MAX];
	int i;
	for (i = 0; unparsedPath[i]; i++) {
		if (isupper(unparsedPath[i])) {
			unparsedPath[i] = tolower(unparsedPath[i]);
		}
	}
	sprintf(temp, "%s/%s", currentPath, unparsedPath);
	strcpy(currentPath, temp);
#ifdef DOS2UNIX_LOGGING
	printf("dos2unix: file %s not found, returning %s\n", dirOrig, currentPath);
#endif
	return currentPath;
}

// File functions
char* nox_fs_normalize(const char* path) {
	int i, len = strlen(path);

	// printf("dos2unix: accessing file %s\n", path);

	if (path[0] == 'C' && path[1] == ':')
		path += 2;

	// Let's first convert relative paths into full paths
	char cwd[NOX_FILEPATH_MAX];
	getcwd(cwd, NOX_FILEPATH_MAX - 1);
	bool isInCwd = false;

	char* str = calloc(len + strlen(cwd) + 10, 1);

	bool absolute = true;

	if (path[0] != '\\') {
		absolute = false;
		sprintf(str, "%s/%s", cwd, path);
		isInCwd = true;
	} else {
		strcpy(str, path);
	}

	// Fixup dir separators
	for (i = 0; str[i]; i++) {
		if (str[i] == '\\') {
			str[i] = '/';
		}
	}

	char* dataPathUnfixed = nox_fs_root();
	char dataPath[NOX_FILEPATH_MAX];
	strcpy(dataPath, dataPathUnfixed);

	for (i = 0; dataPath[i]; i++) {
		if (dataPath[i] == '\\') {
			dataPath[i] = '/';
		}
	}

	for (i = 0; cwd[i]; i++) {
		if (cwd[i] == '\\') {
			cwd[i] = '/';
		}
	}

	// Find out which known path part is in out path part to reduce lookups
	bool isInDataPath = false;
	if (absolute && !isInCwd && strstr(str, cwd) == str) {
		isInCwd = true;
	}

	if (!isInCwd && strlen(dataPath) > 0 && dataPath[0] == '/' && strstr(str, dataPath) == str) {
		isInDataPath = true;
	}

	// Check if lowered filename exists
	// We do not lowercase the known path
	char* pathLowercased = calloc(len + strlen(cwd) + 10, 1);
	int seekLoc = 0;
	if (isInCwd && seekLoc == 0) {
		seekLoc = strlen(cwd) + 1;
	} else if (isInDataPath && seekLoc == 0) {
		seekLoc = strlen(dataPath) + 1;
	}
	for (i = seekLoc; str[i]; i++) {
		pathLowercased[i] = tolower(str[i]);
	}

	if (!access(pathLowercased, 0)) {
		if (!absolute) {
			char* result = calloc(strlen(pathLowercased) + 1, 1);
			strcpy(result, &pathLowercased[strlen(cwd) + 1]);
			free(pathLowercased);
			pathLowercased = result;
		}
#ifdef DOS2UNIX_LOGGING
		printf("dos2unix: file %s exists, fast lowercase translate to %s\n", path, pathLowercased);
#endif
		free(str);
		return pathLowercased;
	}
	free(pathLowercased);

	// Check if exact filename exists
	if (!access(str, 0)) {
		if (!absolute) {
			char* result = calloc(strlen(str) + 1, 1);
			strcpy(result, &str[strlen(cwd) + 1]);
			free(str);
			str = result;
		}
#ifdef DOS2UNIX_LOGGING
		printf("dos2unix: file %s exists, fast exact translate to %s\n", path, str);
#endif
		return str;
	}

	// If we're still here it means we didn't managed to find the file, we need to check for case now
	char* resultBuffer = calloc(len + strlen(cwd) + 10, 1);

	char* strPntr = &str[1];
	if (isInCwd) {
		strPntr = str + strlen(cwd) + 1;
		strcpy(resultBuffer, cwd);
	} else if (isInDataPath) {
		strPntr = str + strlen(dataPath) + 1;
		strcpy(resultBuffer, dataPath);
	}

	// We skip the leading "/" as we already have it (we start seeking from root folder)
	char* result = dos_to_unix_recurse_paths(resultBuffer, strPntr);

	// Something terribly wrong, just break here
	if (!result) {
		abort();
		free(resultBuffer);
		return str;
	}

	if (!absolute) {
		result = calloc(strlen(resultBuffer), 1);
		strcpy(result, &resultBuffer[strlen(cwd) + 1]);
		free(resultBuffer);
	}

	// Success, return it
#ifdef DOS2UNIX_LOGGING
	printf("dos2unix: translated %s into %s\n", path, result);
#endif
	free(str);
	return result;
}
#endif // _WIN32

char* progname = "nox";
void nox_fs_set_progname(const char* name) { progname = name; }
void nox_fs_progname(char* dst, int max) {
	strcpy(dst, progname);

	for (int i = 0; dst[i]; i++)
		if (dst[i] == '/')
			dst[i] = '\\';
}

bool nox_fs_workdir(char* dst, int max) {
#ifndef _WIN32
	if (!getcwd(dst, max)) {
		return false;
	}
	for (int i = 0; dst[i]; i++) {
		if (dst[i] == '/') {
			dst[i] = '\\';
		}
	}
	return true;
#else  // _WIN32
	return GetCurrentDirectoryA(max, dst);
#endif // _WIN32
}

bool nox_fs_set_workdir(const char* path) {
#ifndef _WIN32
	char* converted = nox_fs_normalize(path);
	int res = chdir(converted);
	// printf("%s: %s = %08x\n", __FUNCTION__, converted, (int)result);
	free(converted);
	return res == 0;
#else  // _WIN32
	return SetCurrentDirectoryA(path);
#endif // _WIN32
}

bool nox_fs_mkdir(const char* path) {
#ifndef _WIN32
	char* converted = nox_fs_normalize(path);
	int res = mkdir(converted, 0777);
	free(converted);
#else  // _WIN32
	int res = _mkdir(path);
#endif // _WIN32
	if (res != 0 && errno == EEXIST) {
		res = 0;
	}
	return res == 0;
}

bool nox_fs_remove(const char* path) {
#ifndef _WIN32
	char* converted = nox_fs_normalize(path);
	int res = unlink(converted);
	free(converted);
	return res == 0;
#else  // _WIN32
	return _unlink(path);
#endif // _WIN32
}

bool nox_fs_remove_dir(const char* path) {
#ifndef _WIN32
	char* converted = nox_fs_normalize(path);
	int res = rmdir(converted);
	free(converted);
	return res == 0;
#else  // _WIN32
	return RemoveDirectoryA(path);
#endif // _WIN32
}

FILE* __nox_fs_fopen(const char* path, const char* mode) {
#ifndef _WIN32
	char* converted = nox_fs_normalize(path);
	FILE* f = fopen(converted, mode);
	// printf("%s: %s = %08x\n", __FUNCTION__, converted, (int)result);
	free(converted);
	return f;
#else  // _WIN32
	return fopen(path, mode);
#endif // _WIN32
}

int nox_fs_access(const char* filename, int mode) {
#ifndef _WIN32
	int result;
	char* converted = nox_fs_normalize(filename);
	result = access(converted, mode);
	free(converted);
	return result;
#else  // _WIN32
	return _access(filename, mode);
#endif // _WIN32
}

FILE* nox_fs_open(const char* path) { return __nox_fs_fopen(path, "rb"); }

FILE* nox_fs_open_text(const char* path) { return __nox_fs_fopen(path, "r"); }

FILE* nox_fs_create(const char* path) { return __nox_fs_fopen(path, "wb"); }

FILE* nox_fs_create_text(const char* path) { return __nox_fs_fopen(path, "w"); }

FILE* nox_fs_open_rw(const char* path) { return __nox_fs_fopen(path, "r+b"); }

FILE* nox_fs_create_rw(const char* path) { return __nox_fs_fopen(path, "w+b"); }

FILE* nox_fs_append_text(const char* path) { return __nox_fs_fopen(path, "w"); }

bool nox_fs_copy(const char* src, const char* dst) {
#ifndef _WIN32
	char buf[1024];
	FILE* rfd = nox_fs_open(src);
	if (rfd <= 0)
		return 0;

	FILE* wfd = nox_fs_create(dst);
	if (wfd <= 0) {
		fclose(rfd);
		return 0;
	}

	while (1) {
		int ret = nox_fs_fread(rfd, buf, sizeof(buf));
		if (ret <= 0)
			break;
		if (nox_fs_fwrite(wfd, buf, ret) != ret) {
			fclose(rfd);
			return 0;
		}
	}

	fclose(rfd);
	fclose(wfd);
	return 1;
#else  // _WIN32
	return CopyFileA(src, dst, 0);
#endif // _WIN32
}

int nox_fs_fread(FILE* f, void* dst, int sz) { return fread(dst, 1, sz, f); }

int nox_fs_fwrite(FILE* f, void* dst, int sz) { return fwrite(dst, 1, sz, f); }

int nox_fs_fseek(FILE* f, long off, int mode) { return fseek(f, off, mode); }

long nox_fs_ftell(FILE* f) { return ftell(f); }

long nox_fs_fsize(FILE* f) {
	long cur = ftell(f);
	fseek(f, 0, SEEK_END);
	long size = ftell(f);
	fseek(f, cur, SEEK_SET);
	return size;
}

void nox_fs_close(FILE* f) { fclose(f); }

void nox_fs_flush(FILE* f) { fflush(f); }

bool nox_fs_move(const char* src, const char* dst) {
	printf("%s\n", __FUNCTION__);
	abort();
}

bool nox_fs_fgets(FILE* stream, char* str, int size) {
	char* out = fgets(str, size, stream);
	if (out) {
		// XXX hack for text-mode line conversion
		size = strlen(out);
		if (size >= 2 && out[size - 1] == '\n' && out[size - 2] == '\r') {
			out[size - 2] = '\n';
			out[size - 1] = '\0';
		}
	}
	return out;
}

int nox_fs_fgetc(FILE* f) { return fgetc(f); }

int nox_fs_fputs(FILE* f, const char* str) { return fputs(str, f); }

bool nox_fs_feof(FILE* f) { return feof(f) != 0; }

//----- (00413BD0) --------------------------------------------------------
int nox_fs_fputs_sync(FILE* f, const char* str) {
	int res = 0;
	if (f) {
		res = nox_fs_fprintf(f, "%s", str);
		nox_fs_flush(f);
	}
	return 0;
}
