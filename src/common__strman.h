#ifndef NOX_COMMON_STRMAN_H
#define NOX_COMMON_STRMAN_H
#include "nox_wchar.h"

enum {
	NOX_LANG_US = 1,
	NOX_LANG_UK = 2,
	NOX_LANG_GE = 3,
	NOX_LANG_FR = 4,
	NOX_LANG_SP = 5,
	NOX_LANG_IT = 6,
	NOX_LANG_JA = 7,
	NOX_LANG_KO = 8,
	NOX_LANG_UNK = 9,
};

#ifndef NOX_CGO
const wchar_t* nox_strman_loadString_40F1D0(const char* name, char** strOut, const char* srcFile, int srcLine);
int nox_strman_readfile(const char* path);
#else  // NOX_CGO
wchar_t* nox_strman_loadString_40F1D0(char* name, char** strOut, char* srcFile, int srcLine);
int nox_strman_readfile(char* path);
#endif // NOX_CGO
void nox_strman_free_410020();
int nox_strman_get_lang_code();

#endif // NOX_COMMON_STRMAN_H
