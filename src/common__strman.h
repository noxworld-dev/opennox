#ifndef NOX_COMMON_STRMAN_H
#define NOX_COMMON_STRMAN_H
#include <wchar.h>
#include "common__poison.h"

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

typedef struct nox_missing_string nox_missing_string;
typedef struct nox_missing_string {
	nox_missing_string* next;
	wchar_t data[258];
} nox_missing_string;

typedef struct nox_string_entry {
	char data[50];
	unsigned short field_50;
} nox_string_entry;

const wchar_t* nox_strman_loadString_40F1D0(const char* name, char** strOut, const char* srcFile, int srcLine);
int nox_strman_readfile(const char* path);
void nox_strman_free_410020();
int nox_strman_get_lang_code();

#endif // NOX_COMMON_STRMAN_H