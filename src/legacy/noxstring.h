#ifndef NOX_STRING_H
#define NOX_STRING_H
#include <stdarg.h>
#include "nox_wchar.h"

int _nox_wcsicmp(const wchar2_t* string1, const wchar2_t* string2);
int nox_strcmpi(const char* string1, const char* string2);
int nox_strnicmp(const char* string1, const char* string2, int sz);
wchar2_t* nox_wcscat(wchar2_t* dest, const wchar2_t* src);
wchar2_t* nox_wcschr(wchar2_t* nox_wcs, wchar2_t wc);
int nox_wcscmp(const wchar2_t* s1, const wchar2_t* s2);
wchar2_t* nox_wcscpy(wchar2_t* dest, const wchar2_t* src);
size_t nox_wcslen(const wchar2_t* nox_wcs);
wchar2_t* nox_wcsncpy(wchar2_t* dest, const wchar2_t* src, size_t n);
size_t nox_wcsspn(const wchar2_t* nox_wcs, const wchar2_t* accept);
long nox_wcstol(const wchar2_t* nptr, wchar2_t** endptr, int base);
wchar2_t* nox_wcstok(wchar2_t*, const wchar2_t*);
int nox_vsnwprintf(wchar2_t* buffer, size_t count, const wchar2_t* format, va_list ap);
int nox_vsnprintf(char* buffer, size_t count, const char* format, va_list ap);
int nox_vsprintf(char* str, const char* format, va_list ap);
int nox_sprintf(char* str, const char* format, ...);
int nox_swprintf(wchar2_t* str, const wchar2_t* fmt, ...);
int nox_vswprintf(wchar2_t* str, const wchar2_t* fmt, va_list ap);

char* nox_itoa(int val, char* s, int radix);
wchar2_t* nox_itow(int val, wchar2_t* s, int radix);

#endif // NOX_STRING_H
