#include "client__gui__gamewin__psscript.h"

#include "client__gui__gamewin__gamewin.h"
#include "common__strman.h"

//----- (004A0800) --------------------------------------------------------
int nox_gui_parseWindowTooltip_4A0800(nox_window_data* data, char* buf) {
	wchar_t* str = nox_strman_loadString_40F1D0(buf, 0, "C:\\NoxPost\\src\\Client\\Gui\\GameWin\\psscript.c", 267);
	nox_xxx_wndWddSetTooltip_46B000(data, str);
	return 1;
}

//----- (004A0A90) --------------------------------------------------------
int nox_gui_parseWindowText_4A0A90(nox_window_data* data, char* buf) {
	wchar_t* str;
	if (!strcmp(buf, "Options.wnd:8BitColor")) {
		str = L"\tWindowed";
	} else if (!strcmp(buf, "Options.wnd:16BitColor")) {
		str = L"\tFullscreen";
	} else {
		str = nox_strman_loadString_40F1D0(buf, 0, "C:\\NoxPost\\src\\Client\\Gui\\GameWin\\psscript.c", 424);
	}
	nox_wcsncpy(data->text, str, 63);
	data->text[63] = 0;
	return 1;
}
