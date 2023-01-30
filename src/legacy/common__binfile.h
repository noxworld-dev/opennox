#ifndef NOX_COMMON_BINFILE_H
#define NOX_COMMON_BINFILE_H

#include <stdio.h>

#define NOX_BINFILE_READ 0
#define NOX_BINFILE_WRITE 1
#define NOX_BINFILE_RW 2

int nox_binfile_lastErr_409370(FILE* f);
int nox_binfile_ftell_426A50(FILE* f);

FILE* nox_binfile_open_408CC0(char* path, int mode);
int nox_binfile_close_408D90(FILE* a1);
int nox_binfile_fread_408E40(char* a1, int a2, int a3, FILE* a4);
int nox_binfile_fread_align_408FE0(char* a1, int a2, int a3, FILE* a4);
int nox_binfile_fseek_409050(FILE* a1, int a2, int a3);
int nox_binfile_cryptSet_408D40(FILE* f, int key);
int nox_binfile_skipLine_409520(FILE* f);
int nox_binfile_fread_raw_40ADD0(char* buf, size_t size, size_t count, FILE* file);

#endif // NOX_COMMON_BINFILE_H
