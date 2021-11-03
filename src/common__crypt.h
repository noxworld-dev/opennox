#ifndef NOX_COMMON_CRYPT_H
#define NOX_COMMON_CRYPT_H

#include <stdio.h>
#include <stdint.h>

int nox_xxx_cryptOpen_426910(char* a1, int a2, int a3);
FILE* nox_xxx_cryptClose_4269F0();
int nox_xxx_cryptSetTypeMB_426A50(int a1);
int nox_xxx_file_4268E0();
FILE* nox_xxx_mapgenGetSomeFile_426A60();
int sub_426AA0(int a1);
void sub_4268F0(int a1);
size_t nox_xxx_fileReadWrite_426AC0_file3_fread(uint8_t* a1, size_t a2);
void nox_xxx_fileCryptReadCrcMB_426C20(uint8_t* a1, size_t a2);
void nox_xxx_crypt_426C90();
void nox_xxx_crypt_426D40();
void nox_xxx_cryptXor_56FDD0(char key, unsigned char* p, int n);
void nox_xxx_cryptXorDst_56FE00(char key, unsigned char* src, int n, unsigned char* dst);

#endif // NOX_COMMON_CRYPT_H
