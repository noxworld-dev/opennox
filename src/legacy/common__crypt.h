#ifndef NOX_COMMON_CRYPT_H
#define NOX_COMMON_CRYPT_H

#include <stdio.h>

int nox_crypt_IsReadOnly();
int nox_xxx_cryptOpen_426910(char* a1, int a2, int a3);
void nox_xxx_cryptClose_4269F0();
void nox_xxx_cryptSetTypeMB_426A50(int a1);
int nox_xxx_cryptFlush_4268E0();
FILE* nox_xxx_mapgenGetSomeFile_426A60();
int nox_xxx_cryptSeekCur_40E0A0(int a1);
void sub_4268F0(int a1);
size_t nox_xxx_fileReadWrite_426AC0_file3_fread_impl(unsigned char* a1, size_t a2, char* fname, int line);
#define nox_xxx_fileReadWrite_426AC0_file3_fread(a1, a2) nox_xxx_fileReadWrite_426AC0_file3_fread_impl(a1, a2, __FILE__, __LINE__)
void nox_xxx_fileCryptReadCrcMB_426C20(unsigned char* a1, size_t a2);
void nox_xxx_crypt_426C90();
void nox_xxx_crypt_426D40();
int sub_41C200();

#endif // NOX_COMMON_CRYPT_H
