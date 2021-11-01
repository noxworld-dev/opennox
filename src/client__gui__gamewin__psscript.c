#include "client__gui__gamewin__psscript.h"

#include "client__gui__gamewin__gamewin.h"
#include "common__strman.h"

//----- (004A0800) --------------------------------------------------------
int  nox_gui_parseWindowTooltip_4A0800(nox_window_data* data, char* buf) {
	wchar_t* str = nox_strman_loadString_40F1D0(buf, 0, "C:\\NoxPost\\src\\Client\\Gui\\GameWin\\psscript.c", 267);
	nox_xxx_wndWddSetTooltip_46B000(data, str);
	return 1;
}

//----- (004A0A90) --------------------------------------------------------
int  nox_gui_parseWindowText_4A0A90(nox_window_data* data, char* buf) {
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

//----- (004A10A0) --------------------------------------------------------
#ifndef NOX_CGO
int  nox_xxx_wndParseDataField_4A10A0(void** out, const char* typ, char* buf) {
	if (!strcmp(typ, "VERTSLIDER") || !strcmp(typ, "HORZSLIDER")) {
		*getMemU32Ptr(0x5D4594, 1305820) = 0;
		*getMemU32Ptr(0x5D4594, 1305824) = 0;
		*getMemU32Ptr(0x5D4594, 1305828) = 0;
		*getMemU32Ptr(0x5D4594, 1305832) = 0;
		*getMemU32Ptr(0x5D4594, 1305820) = atoi(strtok(buf, " \t\n\r"));
		*getMemU32Ptr(0x5D4594, 1305824) = atoi(strtok(0, " \t\n\r"));
		*out = getMemAt(0x5D4594, 1305820);
		return 1;
	} else if (!strcmp(typ, "SCROLLLISTBOX")) {
		memset(getMemAt(0x5D4594, 1306892), 0, 0x38u);
		*getMemU16Ptr(0x5D4594, 1306892) = atoi(strtok(buf, " \t\n\r"));
		*getMemU16Ptr(0x5D4594, 1306894) = atoi(strtok(0, " \t\n\r"));
		*getMemU32Ptr(0x5D4594, 1306896) = atoi(strtok(0, " \t\n\r"));
		*getMemU32Ptr(0x5D4594, 1306900) = atoi(strtok(0, " \t\n\r"));
		*getMemU32Ptr(0x5D4594, 1306904) = atoi(strtok(0, " \t\n\r"));
		*getMemU32Ptr(0x5D4594, 1306908) = atoi(strtok(0, " \t\n\r"));
		*getMemU32Ptr(0x5D4594, 1306912) = atoi(strtok(0, " \t\n\r"));
		*out = getMemAt(0x5D4594, 1306892);
		return 1;
	} else if (!strcmp(typ, "ENTRYFIELD")) {
		memset(getMemAt(0x5D4594, 1305836), 0, 0x420u);
		*getMemU16Ptr(0x5D4594, 1306876) = atoi(strtok(buf, " \t\n\r"));
		char* v12 = strtok(0, " \t\n\r");
		if (v12) {
			*getMemU16Ptr(0x5D4594, 1306878) = atoi(v12);
		} else {
			*getMemU16Ptr(0x5D4594, 1306878) = -1;
}
		char* v13 = strtok(0, " \t\n\r");
		if (v13) {
			*getMemU32Ptr(0x5D4594, 1306860) = atoi(v13) != 0;
		} else {
			*getMemU32Ptr(0x5D4594, 1306860) = 0;
		}
		char* v14 = strtok(0, " \t\n\r");
		if (v14) {
			int v14i = atoi(v14);
			*getMemU32Ptr(0x5D4594, 1306864) = v14i == 1;
			*getMemU32Ptr(0x5D4594, 1306868) = v14i == 2;
			*getMemU32Ptr(0x5D4594, 1306872) = v14i == 3;
		} else {
			*getMemU32Ptr(0x5D4594, 1306864) = 0;
			*getMemU32Ptr(0x5D4594, 1306868) = 0;
			*getMemU32Ptr(0x5D4594, 1306872) = 0;
		}
		*out = getMemAt(0x5D4594, 1305836);
		return 1;
	} else if (!strcmp(typ, "STATICTEXT")) {
		*getMemU32Ptr(0x5D4594, 1307256) = atoi(strtok(buf, " \t\n\r"));
		*getMemU32Ptr(0x5D4594, 1307256) = *getMemU32Ptr(0x5D4594, 1307256) != 0;
		*getMemU32Ptr(0x5D4594, 1307260) = atoi(strtok(0, " \t\n\r"));
		*getMemU32Ptr(0x5D4594, 1307260) = *getMemU32Ptr(0x5D4594, 1307260) != 0;
		char* v18 = strtok(0, " \t\n\r");
		*getMemU32Ptr(0x5D4594, 1307252) =
			nox_strman_loadString_40F1D0(v18, 0, "C:\\NoxPost\\src\\Client\\Gui\\GameWin\\psscript.c", 542);
		*out = getMemAt(0x5D4594, 1307252);
		return 1;
	} else if (!strcmp(typ, "RADIOBUTTON")) {
		*getMemU32Ptr(0x5D4594, 1305812) = atoi(strtok(buf, " \t\n\r"));
		*getMemU32Ptr(0x5D4594, 1307256) = *getMemU32Ptr(0x5D4594, 1307256) != 0;
		*out = getMemAt(0x5D4594, 1305812);
		return 1;
	}
	*out = 0;
	return 1;
}
#endif // NOX_CGO
