#include <stdarg.h>
#include <stdio.h>

#include "common/fs/nox_fs.h"

int nox_fs_fprintf(FILE* f, const char* format, ...) {
	char buf[2048] = {0};

	va_list args;
	va_start(args, format);
	vsnprintf(buf, sizeof(buf), format, args);
	va_end(args);

	return nox_fs_fputs(f, buf);
}
