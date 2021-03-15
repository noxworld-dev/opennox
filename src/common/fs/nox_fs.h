#ifndef NOX_COMMON_FS_H
#define NOX_COMMON_FS_H

#include <stdbool.h>
#include <stdio.h>

#define NOX_FILEPATH_MAX 1024

#ifndef NOX_CGO

#ifdef __linux__
char* nox_fs_normalize(const char* path);
#endif

const char* nox_fs_root();
void nox_fs_set_root(const char* root);

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

#else // NOX_CGO

#ifdef __linux__
char* nox_fs_normalize(char* path);
#endif

char* nox_fs_root();

// nox_fs_workdir copies current work directory to specified buffer.
bool nox_fs_workdir(char* dst, int max);
// nox_fs_set_workdir sets current work directory.
bool nox_fs_set_workdir(char* path);

// nox_fs_open opens the file for reading (in binary mode).
FILE* nox_fs_open(char* path);
// nox_fs_open_text opens the file for reading (in text mode).
FILE* nox_fs_open_text(char* path);
// nox_fs_create creates the file for writing (in binary mode).
FILE* nox_fs_create(char* path);
// nox_fs_create_text creates or opens the file for writing (in text mode).
FILE* nox_fs_create_text(char* path);
// nox_fs_open_rw opens the file for reading and writing (in binary mode).
FILE* nox_fs_open_rw(char* path);
// nox_fs_create_rw creates the file for reading and writing (in binary mode).
FILE* nox_fs_create_rw(char* path);
// nox_fs_append_text opens the file for appending (in text mode).
FILE* nox_fs_append_text(char* path);

#endif // NOX_CGO

#endif // NOX_COMMON_FS_H
