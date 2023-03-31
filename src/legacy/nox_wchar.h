#ifndef NOX_WCHAR_H
#define NOX_WCHAR_H

#include <stdint.h>
#include <wchar.h>
#include <wctype.h>

#include "static_assert.h"

#ifndef _WIN32
// GCC wchar_t size is different than the one on Windows, so we must poison all the functions that expect invalid size.
#pragma GCC poison fgetwln fgetws fputwc fputws fwprintf fwscanf mbrtowc mbsnrtowcs mbsrtowcs putwc putwchar swprintf  \
	swscanf vfwprintf vfwscanf vswprintf vswscanf vwprintf vwscanf wcrtomb wcscat wcschr wcscmp wcscoll wcscpy wcscspn \
		wcsftime wcsftime wcslcat wcslcpy wcslen wcsncat wcsncmp wcsncpy wcsnrtombs wcspbrk wcsrchr wcsrtombs wcsspn   \
			wcsstr wcstod wcstof wcstok wcstol wcstold wcstoll wcstoul wcstoull wcswidth wcsxfrm wcwidth wmemchr       \
				wmemcmp wmemcpy wmemmove wmemset wprintf wscanf
#endif // !_WIN32

typedef uint16_t wchar2_t;

_Static_assert(sizeof(wchar2_t) == 2, "wrong size of wchar2_t!");

#include "noxstring.h"

#endif // NOX_WCHAR_H
