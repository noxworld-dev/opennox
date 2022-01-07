#ifndef NOX_COMMON_FS_H
#define NOX_COMMON_FS_H

#include <stdbool.h>
#include <stdio.h>

#define NOX_FILEPATH_MAX 1024

#ifndef NOX_CGO

#ifndef _WIN32
char* nox_fs_normalize(const char* path);
#endif

const char* nox_fs_root();
void nox_fs_set_root(const char* root);

// nox_fs_workdir copies current work directory to specified buffer.
bool nox_fs_workdir(char* dst, int max);
// nox_fs_set_workdir sets current work directory.
bool nox_fs_set_workdir(const char* path);

void nox_fs_set_progname(const char* name);
void nox_fs_progname(char* dst, int max);

bool nox_fs_mkdir(const char* path);
bool nox_fs_remove(const char* path);
bool nox_fs_remove_dir(const char* path);
bool nox_fs_copy(const char* src, const char* dst);
bool nox_fs_move(const char* src, const char* dst);

int nox_fs_access(const char* filename, int mode);

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

int nox_fs_fputs(FILE* f, const char* str);
int nox_fs_fputs_sync(FILE* f, const char* str);
#define nox_fs_fprintf fprintf
#define nox_fs_fscan_str(f, p) fscanf(f, "%s", p)
#define nox_fs_fscan_char(f, p) fscanf(f, "%c", p)
#define nox_fs_fscan_char2(f, p) fscanf(f, "%2c", p)
#define nox_fs_fscan_skip(f) fscanf(f, "%*s")

#else // NOX_CGO

#ifndef _WIN32
char* nox_fs_normalize(char* path);
#endif

char* nox_fs_root();

// nox_fs_workdir copies current work directory to specified buffer.
bool nox_fs_workdir(char* dst, int max);
// nox_fs_set_workdir sets current work directory.
bool nox_fs_set_workdir(char* path);

void nox_fs_progname(char* dst, int max);

bool nox_fs_mkdir(char* path);
bool nox_fs_remove(char* path);
bool nox_fs_remove_dir(char* path);
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
// nox_fs_create_rw creates the file for reading and writing (in binary mode).
FILE* nox_fs_create_rw(char* path);
// nox_fs_append_text opens the file for appending (in text mode).
FILE* nox_fs_append_text(char* path);

int nox_fs_fputs(FILE* f, char* str);
int nox_fs_fputs_sync(FILE* f, char* str);
int nox_fs_fprintf(FILE* f, const char* format, ...);
int nox_fs_fscan_str(FILE* f, char* dst);
int nox_fs_fscan_skip(FILE* f);
int nox_fs_fscan_char(FILE* f, char* dst);
int nox_fs_fscan_char2(FILE* f, char* dst);

#endif // NOX_CGO

int nox_fs_fseek(FILE* f, long off, int mode);
long nox_fs_ftell(FILE* f);
long nox_fs_fsize(FILE* f);
int nox_fs_fread(FILE* f, void* dst, int sz);
int nox_fs_fwrite(FILE* f, void* src, int sz);
bool nox_fs_fgets(FILE* f, char* dst, int max);
int nox_fs_fgetc(FILE* f);
bool nox_fs_feof(FILE* f);

void nox_fs_close(FILE* f);
void nox_fs_flush(FILE* f);

#define nox_fs_fseek_start(f, off) nox_fs_fseek(f, off, SEEK_SET)
#define nox_fs_fseek_cur(f, off) nox_fs_fseek(f, off, SEEK_CUR)
#define nox_fs_fseek_end(f, off) nox_fs_fseek(f, off, SEEK_END)

#endif // NOX_COMMON_FS_H
