#include "nox_wchar.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wctype.h>

char* nox_itoa(int val, char* s, int radix);

wchar2_t* nox_itow(int val, wchar2_t* s, int radix) {
	char tmp[32];
	unsigned int i;

	nox_itoa(val, tmp, radix);
	for (i = 0; tmp[i]; i++)
		s[i] = tmp[i];
	s[i] = 0;

	return s;
}

int nox_vsnwprintf(wchar2_t* buffer, size_t count, const wchar2_t* format, va_list ap) {
	int i = 0, j, out = 0;
	wchar2_t ch;

#define EMIT(c)                                                                                                        \
	do {                                                                                                               \
		if (buffer && out < count)                                                                                     \
			buffer[out++] = c;                                                                                         \
		else                                                                                                           \
			out++;                                                                                                     \
	} while (0)

	if (count == 0)
		buffer = NULL;

	while ((ch = format[i++]) != 0) {
		char flag = 0;
		int width = -1, precision = -1;

		if (ch != '%') {
			EMIT(ch);
			continue;
		}

		ch = format[i++];
		switch (ch) {
		case '+':
		case '-':
		case '0':
			flag = ch;
			ch = format[i++];
			break;
		}

		while (ch >= '0' && ch <= '9') {
			if (width < 0)
				width = 0;
			width = width * 10 + ch - '0';
			ch = format[i++];
		}

		if (ch == '.') {
			ch = format[i++];
			precision = 0;
			while (ch >= '0' && ch <= '9') {
				precision = precision * 10 + ch - '0';
				ch = format[i++];
			}
		}

		switch (ch) {
		case 'c': {
			wchar2_t c = va_arg(ap, int);
			EMIT(c);
		} break;
		case 's': {
			static const wchar2_t null[] = {'(', 'n', 'u', 'l', 'l', ')', 0};
			const wchar2_t* pwch = va_arg(ap, const wchar2_t*);
			if (pwch == NULL)
				pwch = null;
			for (j = 0; pwch[j]; j++)
				EMIT(pwch[j]);
		} break;
		case 'S': {
			const char* pcch = va_arg(ap, const char*);
			if (pcch == NULL)
				pcch = "(null)";
			for (j = 0; pcch[j]; j++)
				EMIT(pcch[j] & 0xFF);
		} break;
		case 'd':
		case 'i': {
			char tmp[32];
			int len;

			len = strlen(nox_itoa(va_arg(ap, int), tmp, 10));

			for (j = 0; j < width - (precision > 0 ? precision : len); j++) {
				if (flag == '0')
					EMIT('0');
				else
					EMIT(' ');
			}

			for (j = 0; j < precision - len; j++)
				EMIT('0');

			for (j = 0; j < len; j++)
				EMIT(tmp[j]);
		} break;
		case 'X':
		case 'x':
		case 'o':
		case 'u': {
			char tmp[32];
			int len;

			len = strlen(nox_itoa(va_arg(ap, unsigned int), tmp, ch == 'u' ? 10 : ch == 'o' ? 8 : 16));
			for (j = 0; j < width - (precision > 0 ? precision : len); j++) {
				if (flag == '0')
					EMIT('0');
				else
					EMIT(' ');
			}

			for (j = 0; j < precision - len; j++)
				EMIT('0');

			for (j = 0; j < len; j++)
				EMIT(ch == 'X' ? toupper(tmp[j]) : tmp[j]);
		} break;
		case 'f': {
			char tmp[32];
			char tmp2[32];
			double val;
			int len;
			int final_precision = precision > 0 ? precision : 5;
			snprintf(tmp, 32, "%%.%df", final_precision);
			val = va_arg(ap, double);
			snprintf(tmp2, 32, tmp, val);
			len = strlen(tmp2);

			for (j = 0; j < len; j++) {
				EMIT(tmp2[j]);
			}

		} break;
		case '%':
			EMIT('%');
			break;
		case '!':
			EMIT('!');
			break;
		default:
			printf("Unhandled format character: '%c'", ch);
			abort();
			// EMIT(ch);
			break;
		}
	}

	EMIT(0);
	return out - 1;
#undef EMIT
}

int nox_vsnprintf(char* buffer, size_t count, const char* format, va_list ap) {
	// return vsnprintf(buffer, count, format, ap);
	int i = 0, j, out = 0;
	char ch;

#define EMIT(c)                                                                                                        \
	do {                                                                                                               \
		if (buffer && out < count)                                                                                     \
			buffer[out++] = c;                                                                                         \
		else                                                                                                           \
			out++;                                                                                                     \
	} while (0)

	if (count == 0)
		buffer = NULL;

	while ((ch = format[i++]) != 0) {
		char flag = 0;
		int width = -1, precision = -1;

		if (ch != '%') {
			EMIT(ch);
			continue;
		}

		ch = format[i++];
		switch (ch) {
		case '+':
		case '-':
		case '0':
			flag = ch;
			ch = format[i++];
			break;
		}

		while (ch >= '0' && ch <= '9') {
			if (width < 0)
				width = 0;
			width = width * 10 + ch - '0';
			ch = format[i++];
		}

		if (ch == '.') {
			ch = format[i++];
			precision = 0;
			while (ch >= '0' && ch <= '9') {
				precision = precision * 10 + ch - '0';
				ch = format[i++];
			}
		}

		switch (ch) {
		case 'c': {
			char c = (char)va_arg(ap, int);
			EMIT(c);
		} break;
		case 's': {
			const char* pcch = va_arg(ap, const char*);
			if (pcch == NULL)
				pcch = "(null)";
			for (j = 0; pcch[j]; j++)
				EMIT(pcch[j]);
		} break;
		case 'S': {
			static const wchar2_t null[] = {'(', 'n', 'u', 'l', 'l', ')', 0};
			const wchar2_t* pwch = va_arg(ap, const wchar2_t*);
			if (pwch == NULL)
				pwch = null;
			for (j = 0; pwch[j]; j++)
				EMIT(pwch[j]);
		} break;
		case 'd':
		case 'i': {
			char tmp[32];
			int len;

			len = strlen(nox_itoa(va_arg(ap, int), tmp, 10));

			for (j = 0; j < width - (precision > 0 ? precision : len); j++) {
				if (flag == '0')
					EMIT('0');
				else
					EMIT(' ');
			}

			for (j = 0; j < precision - len; j++)
				EMIT('0');

			for (j = 0; j < len; j++)
				EMIT(tmp[j]);
		} break;
		case 'X':
		case 'x':
		case 'o':
		case 'u': {
			char tmp[32];
			int len;

			len = strlen(nox_itoa(va_arg(ap, unsigned int), tmp, ch == 'u' ? 10 : ch == 'o' ? 8 : 16));
			for (j = 0; j < width - (precision > 0 ? precision : len); j++) {
				if (flag == '0')
					EMIT('0');
				else
					EMIT(' ');
			}

			for (j = 0; j < precision - len; j++)
				EMIT('0');

			for (j = 0; j < len; j++)
				EMIT(ch == 'X' ? toupper(tmp[j]) : tmp[j]);
		} break;
		case '%':
			EMIT('%');
			break;
		case '!':
			EMIT('!');
			break;
		default:
			printf("Unhandled format character: '%c'", ch);
			abort();
			break;
		}
	}

	EMIT(0);
	return out - 1;
#undef EMIT
}

int nox_vsprintf(char* str, const char* format, va_list ap) { return nox_vsnprintf(str, 0x7fffffff, format, ap); }

int nox_sprintf(char* str, const char* format, ...) {
	int ret;
	va_list ap;
	va_start(ap, format);
	ret = nox_vsprintf(str, format, ap);
	va_end(ap);
	return ret;
}

wchar2_t* nox_wcscat(wchar2_t* dest, const wchar2_t* src) {
	wchar2_t* ret = dest;
	if (!src) {
		return ret;
	}

	while (*dest)
		dest++;

	while (*src)
		*dest++ = *src++;
	*dest = 0;

	return ret;
}

wchar2_t* nox_wcschr(wchar2_t* nox_wcs, wchar2_t wc) {
	size_t result;
	for (result = 0; nox_wcs[result]; result++)
		if (nox_wcs[result] == wc)
			return &nox_wcs[result];
	return NULL;
}

int nox_wcscmp(const wchar2_t* s1, const wchar2_t* s2) {
	if (s1 == s2)
		return 0;
	if (!s1)
		return -1;
	if (!s2)
		return +1;
	size_t result;
	for (result = 0; s1[result] && s1[result] == s2[result]; result++)
		;
	return s1[result] - s2[result];
}

wchar2_t* nox_wcscpy(wchar2_t* dest, const wchar2_t* src) {
	size_t result;
	for (result = 0; src[result]; result++)
		dest[result] = src[result];
	dest[result] = 0;
	return dest;
}

size_t nox_wcslen(const wchar2_t* nox_wcs) {
	size_t result;
	for (result = 0; nox_wcs[result]; result++)
		;
	return result;
}

wchar2_t* nox_wcsncpy(wchar2_t* dest, const wchar2_t* src, size_t n) {
	size_t result;
	for (result = 0; src[result] && result < n; result++)
		dest[result] = src[result];
	while (result < n)
		dest[result++] = 0;
	return dest;
}

size_t nox_wcsspn(const wchar2_t* nox_wcs, const wchar2_t* accept) {
	size_t i;

	for (i = 0; nox_wcs[i]; i++)
		if (!nox_wcschr(accept, nox_wcs[i]))
			break;

	return i;
}

wchar2_t* nox_wcstok(wchar2_t* str, const wchar2_t* delim) {
	static wchar2_t* next;
	size_t i;

	if (str == NULL)
		str = next;
	if (str == NULL)
		return NULL;

	// skip deliminators
	while (*str) {
		if (!nox_wcschr(delim, *str))
			break;
		str++;
	}

	if (!*str) {
		next = NULL;
		return NULL;
	}

	// lookup for next delim
	for (i = 0; str[i]; i++) {
		if (nox_wcschr(delim, str[i])) {
			str[i] = 0;
			next = &str[i + 1];
			return str;
		}
	}

	next = &str[i];
	return str;
}

int _nox_wcsicmp(const wchar2_t* string1, const wchar2_t* string2) {
	size_t i;

	for (i = 0; string1[i] && towlower(string1[i]) == towlower(string2[i]); i++)
		;

	return towlower(string1[i]) - towlower(string2[i]);
}

int nox_strcmpi(const char* _l, const char* _r) {
	// MUSL implementation
	const unsigned char *l=(void *)_l, *r=(void *)_r;
	for (; *l && *r && (*l == *r || tolower(*l) == tolower(*r)); l++, r++);
	int ret = tolower(*l) - tolower(*r);
	// Old code may expect this
	if (ret < -1) { ret = -1; }
	if (ret > +1) { ret = +1; }
	return ret;
}

int nox_strnicmp(const char* _l, const char* _r, int n) {
	// MUSL implementation
	const unsigned char *l=(void *)_l, *r=(void *)_r;
	if (!n--) { return 0; }
	for (; *l && *r && n && (*l == *r || tolower(*l) == tolower(*r)); l++, r++, n--);
	int ret = tolower(*l) - tolower(*r);
	// Old code may expect this
	if (ret < -1) { ret = -1; }
	if (ret > +1) { ret = +1; }
	return ret;
}

long nox_wcstol(const wchar2_t* nptr, wchar2_t** endptr, int base) {
	long result;
	size_t i, len = nox_wcslen(nptr);
	char *tmp, *ptr;

	tmp = calloc(len + 1, 1);

	for (i = 0; i < len; i++)
		tmp[i] = nptr[i] < 0x80 ? nptr[i] : 0x7f;
	tmp[i] = 0;

	result = strtol(tmp, &ptr, base);

	if (endptr)
		*endptr = &nptr[ptr - tmp];

	free(tmp);
	return result;
}

int nox_swprintf(wchar2_t* str, const wchar2_t* fmt, ...) {
	int len;
	va_list ap;
	va_start(ap, fmt);
	len = nox_vsnwprintf(str, 0x3fffffff, fmt, ap);
	va_end(ap);
	return len;
}

int nox_vswprintf(wchar2_t* str, const wchar2_t* fmt, va_list ap) { return nox_vsnwprintf(str, 0x3fffffff, fmt, ap); }
