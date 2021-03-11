#ifndef NOX_COMMON_FS_H
#define NOX_COMMON_FS_H

#include <stdbool.h>
#include <stdio.h>

#define NOX_FILEPATH_MAX 1024

#ifdef __linux__
char* nox_fs_normalize(const char* path);
#endif

#ifndef NOX_CGO
const char* nox_fs_root();
void nox_fs_set_root(const char* root);
#else // NOX_CGO
char* nox_fs_root();
#endif // NOX_CGO

// nox_fs_workdir copies current work directory to specified buffer.
bool nox_fs_workdir(char* dst, int max);
// nox_fs_set_workdir sets current work directory.
bool nox_fs_set_workdir(const char* path);

// nox_fs_open opens the file for reading (in binary mode).
FILE* nox_fs_open(const char* path);
// nox_fs_open_text opens the file for reading (in text mode).
FILE* nox_fs_open_text(const char* path);
// nox_fs_create creates the file for writing (in binary mode).
FILE* nox_fs_create(const char* path);
// nox_fs_create_text creates or opens the file for writing (in text mode).
FILE* nox_fs_create_text(const char* path);
// nox_fs_open_rw opens the file for reading and writing (in binary mode).
FILE* nox_fs_open_rw(const char* path);
// nox_fs_create_rw creates the file for reading and writing (in binary mode).
FILE* nox_fs_create_rw(const char* path);
// nox_fs_append_text opens the file for appending (in text mode).
FILE* nox_fs_append_text(const char* path);

#endif // NOX_COMMON_FS_H
