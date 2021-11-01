#ifndef NOX_PORT_CLIENT_GUI_GUICON
#define NOX_PORT_CLIENT_GUI_GUICON

#include "client__gui__window.h"
#include "nox_wchar.h"

enum {
	NOX_CONSOLE_BLACK = 1,
	NOX_CONSOLE_DARK_GREY = 2,
	NOX_CONSOLE_LIGHT_GREY = 3,
	NOX_CONSOLE_WHITE = 4,
	NOX_CONSOLE_DARK_RED = 5,
	NOX_CONSOLE_RED = 6,
	NOX_CONSOLE_LIGHT_RED = 7,
	NOX_CONSOLE_DARK_GREEN = 8,
	NOX_CONSOLE_GREEN = 9,
	NOX_CONSOLE_LIGHT_GREEN = 10,
	NOX_CONSOLE_DARK_BLUE = 11,
	NOX_CONSOLE_BLUE = 12,
	NOX_CONSOLE_LIGHT_BLUE = 13,
	NOX_CONSOLE_DARK_YELLOW = 14,
	NOX_CONSOLE_YELLOW = 15,
	NOX_CONSOLE_LIGHT_YELLOW = 16
};

nox_window* nox_gui_console_Create_450C70(int win_width, int win_height);
void nox_gui_console_reloadColors_451100();
int nox_gui_console_Hide_4512B0();
int nox_gui_console_Clear_450B70();
void nox_gui_console_Enable_450BE0();
void nox_gui_console_Disable_450BF0();
void nox_gui_console_Lock_450B20(wchar_t* pass);
void nox_gui_console_Unlock_450B50();
void nox_client_toggleConsole_451350();
int nox_gui_console_flagXxx_451410();

int nox_gui_console_Print_450B90(unsigned char cl, wchar_t* str);
int nox_gui_console_Printf_450C00(unsigned char cl, wchar_t* fmt, ...);
void nox_gui_console_PrintOrError_450C30(unsigned char cl, wchar_t* str);

#endif // NOX_PORT_CLIENT_GUI_GUICON
