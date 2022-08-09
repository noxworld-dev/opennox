#include "noxstring.h"
#include <string.h>

char nox_log_buf[512] = {0};

//----- (00413D30) --------------------------------------------------------
void nox_xxx_networkLog_print(char* str);
void nox_xxx_networkLog_printf_413D30(char* fmt, ...) {
	va_list va;
	va_start(va, fmt);
	nox_vsprintf(nox_log_buf, fmt, va);
	nox_xxx_networkLog_print(nox_log_buf);
}
