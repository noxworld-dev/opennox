#ifndef NOX_COMMON_LOG
#define NOX_COMMON_LOG

#include <stdio.h>

int nox_xxx_log_4_reopen_413A80(char* path);
void nox_xxx_log_4_close_413C00();
void nox_xxx_bandLog_open_413C30();
void nox_xxx_bandLog_close_413C60();
void nox_xxx_bandLog_printf_413C80(char* fmt, ...);
void nox_xxx_networkLog_init_413CC0();
void nox_xxx_networkLog_close_413D00();
void nox_xxx_networkLog_printf_413D30(char* fmt, ...);

#endif // NOX_COMMON_LOG
