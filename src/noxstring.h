#ifndef NOX_STRING_H
#define NOX_STRING_H
#include <stdarg.h>
#include <wchar.h>
#include "common/poison.h"

int _nox_wcsicmp(const wchar_t* string1, const wchar_t* string2);
int nox_wsprintfA(char* lpBuffer, const char* lpFmt, ...);
wchar_t* nox_wcscat(wchar_t* dest, const wchar_t* src);
wchar_t* nox_wcschr(wchar_t* nox_wcs, wchar_t wc);
int nox_wcscmp(const wchar_t* s1, const wchar_t* s2);
wchar_t* nox_wcscpy(wchar_t* dest, const wchar_t* src);
size_t nox_wcslen(const wchar_t* nox_wcs);
wchar_t* nox_wcsncpy(wchar_t* dest, const wchar_t* src, size_t n);
size_t nox_wcsspn(const wchar_t* nox_wcs, const wchar_t* accept);
wchar_t* nox_wcsstr(wchar_t* haystack, const wchar_t* needle);
long nox_wcstol(const wchar_t* nptr, wchar_t** endptr, int base);
wchar_t* nox_wcstok(wchar_t*, const wchar_t*);
int nox_vsnwprintf(wchar_t* buffer, size_t count, const wchar_t* format, va_list ap);
int nox_vsnprintf(char* buffer, size_t count, const char* format, va_list ap);
int nox_vsprintf(char* str, const char* format, va_list ap);
int nox_snprintf(char* str, size_t size, const char* format, ...);
int nox_sprintf(char* str, const char* format, ...);
int nox_swprintf(wchar_t* str, const wchar_t* fmt, ...);
int nox_vswprintf(wchar_t* str, const wchar_t* fmt, va_list ap);

#define dprintf _dprintf
void _dprintf(const char* fmt, ...);

void dhexdump(const char* data, unsigned int len);

#endif
