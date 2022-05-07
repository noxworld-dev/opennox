#include "GAME1.h"
#include "client__gui__guicon.h"
#include "common/fs/nox_fs.h"
#include <string.h>
#include <time.h>

char nox_log_buf[512] = {0};

FILE* nox_file_log_4 = 0;
FILE* nox_file_net_log = 0;

//----- (00413B00) --------------------------------------------------------
char* nox_asctime_413B00() {
	time_t t;
	time(&t);
	return asctime(localtime(&t));
}

//----- (00413B20) --------------------------------------------------------
int nox_xxx_log_open_413B20(FILE** f, const char* path) {
	if (!path) {
		return 0;
	}
	*f = nox_fs_create_rw(path);
	if (!f) {
		return 0;
	}
	nox_fs_fprintf(*f, "Log opened: %s", nox_asctime_413B00());
	nox_fs_flush(*f);
	return 1;
}

//----- (00413AD0) --------------------------------------------------------
void nox_xxx_log_close_413AD0(FILE* f) {
	if (f) {
		nox_fs_fprintf(f, "Log closed: %s", nox_asctime_413B00());
		nox_fs_flush(f);
		nox_fs_close(f);
	}
}

//----- (00413A80) --------------------------------------------------------
int nox_xxx_log_4_reopen_413A80(char* path) {
	if (!nox_common_getEngineFlag(NOX_ENGINE_FLAG_LOG_TO_FILE)) {
		return 0;
	}
	nox_xxx_log_close_413AD0(nox_file_log_4);
	nox_file_log_4 = 0;
	nox_xxx_log_open_413B20(&nox_file_log_4, path);
	return 1;
}

//----- (00413C00) --------------------------------------------------------
void nox_xxx_log_4_close_413C00() {
	nox_common_resetEngineFlag(NOX_ENGINE_FLAG_LOG_TO_FILE | NOX_ENGINE_FLAG_LOG_TO_CONSOLE);
	if (nox_file_log_4) {
		nox_xxx_log_close_413AD0(nox_file_log_4);
		nox_file_log_4 = 0;
	}
}

//----- (00413D30) --------------------------------------------------------
void nox_xxx_networkLog_printf_413D30(char* fmt, ...) {
	if (!nox_common_gameFlags_check_40A5C0(4)) {
		return;
	}
	va_list va;
	va_start(va, fmt);

	time_t v6;
	time(&v6);
	struct tm* v1 = localtime(&v6);

	nox_vsprintf(nox_log_buf, fmt, va);
	nox_sprintf(nox_log_buf, "%s%c(", nox_log_buf, 240);
	strcat(nox_log_buf, asctime(v1));
	nox_log_buf[strlen(nox_log_buf) - 1] = 0;
	strcat(nox_log_buf, ")\n");
	if (nox_file_net_log) {
		nox_fs_fputs_sync(nox_file_net_log, nox_log_buf);
	}
	nox_gui_console_Printf_450C00(NOX_CONSOLE_GREEN, L"%S", nox_log_buf);
}

//----- (00413CC0) --------------------------------------------------------
void nox_xxx_networkLog_init_413CC0() {
	nox_file_net_log = nox_fs_append_text("network.log");
	if (nox_file_net_log) {
		nox_xxx_networkLog_printf_413D30("StartLog%c%s", 240, "1.0");
	}
}

//----- (00413D00) --------------------------------------------------------
void nox_xxx_networkLog_close_413D00() {
	nox_xxx_networkLog_printf_413D30("EndLog");
	nox_fs_close(nox_file_net_log);
	nox_file_net_log = 0;
}
