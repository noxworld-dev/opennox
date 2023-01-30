#ifndef NOX_COMMON_FS_H
#define NOX_COMMON_FS_H

#include <stdbool.h>
#include <stdio.h>

#define NOX_FILEPATH_MAX 1024

#ifndef _WIN32
char* nox_fs_normalize(char* path);
#endif

char* nox_fs_root();

// nox_fs_set_workdir sets current work directory.
bool nox_fs_set_workdir(char* path);

bool nox_fs_mkdir(char* path);
bool nox_fs_remove(char* path);
bool nox_fs_copy(char* src, char* dst);
bool nox_fs_move(char* src, char* dst);

int nox_fs_access(char* filename, int mode);

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

int nox_fs_fputs(FILE* f, char* str);
int nox_fs_fprintf(FILE* f, const char* format, ...);

int nox_fs_fseek(FILE* f, long off, int mode);
long nox_fs_ftell(FILE* f);
long nox_fs_fsize(FILE* f);
int nox_fs_fread(FILE* f, void* dst, int sz);
int nox_fs_fwrite(FILE* f, void* src, int sz);
bool nox_fs_fgets(FILE* f, char* dst, int max);
bool nox_fs_feof(FILE* f);

void nox_fs_close(FILE* f);

#define nox_fs_fseek_start(f, off) nox_fs_fseek(f, off, SEEK_SET)
#define nox_fs_fseek_cur(f, off) nox_fs_fseek(f, off, SEEK_CUR)

#endif // NOX_COMMON_FS_H
