#include "psscript.h"

#include "../../../proto.h"
#include "gamewin.h"

//----- (004A0800) --------------------------------------------------------
int __cdecl sub_4A0800(wchar_t* a1, char* a2) {
	wchar_t* v2; // eax

	v2 = nox_xxx_loadString_40F1D0(a2, 0, "C:\\NoxPost\\src\\Client\\Gui\\GameWin\\psscript.c", 267);
	nox_xxx_wndWddSetTooltip_46B000(a1, v2);
	return 1;
}

//----- (004A0A90) --------------------------------------------------------
int __cdecl sub_4A0A90(int a1, char* a2) {
	wchar_t* v2; // eax

	if (!strcmp(a2, "Options.wnd:8BitColor")) {
		v2 = L"\tWindowed";
	} else if (!strcmp(a2, "Options.wnd:16BitColor")) {
		v2 = L"\tFullscreen";
	} else {
		v2 = nox_xxx_loadString_40F1D0(a2, 0, "C:\\NoxPost\\src\\Client\\Gui\\GameWin\\psscript.c", 424);
	}
	nox_wcsncpy((wchar_t*)(a1 + 72), v2, 0x3Fu);
	*(_WORD*)(a1 + 196) = 0;
	return 1;
}

//----- (004A10A0) --------------------------------------------------------
int __cdecl nox_xxx_wndParseDataField_4A10A0(_DWORD* a1, const char* a2, char* a3) {
	char* v3;        // eax
	char* v4;        // eax
	char* v5;        // eax
	char* v6;        // eax
	char* v7;        // eax
	char* v8;        // eax
	char* v9;        // eax
	int result;      // eax
	char* v11;       // eax
	char* v12;       // eax
	char* v13;       // eax
	char* v14;       // eax
	const char* v15; // esi
	char* v16;       // eax
	char* v17;       // eax
	char* v18;       // eax
	char* v19;       // eax
	char* v20;       // eax
	char* v21;       // eax

	if (!strcmp(a2, "VERTSLIDER") || !strcmp(a2, "HORZSLIDER")) {
		*getMemU32Ptr(0x5D4594, 1305820) = 0;
		*getMemU32Ptr(0x5D4594, 1305824) = 0;
		*getMemU32Ptr(0x5D4594, 1305828) = 0;
		*getMemU32Ptr(0x5D4594, 1305832) = 0;
		v20 = strtok(a3, " \t\n\r");
		*getMemU32Ptr(0x5D4594, 1305820) = atoi(v20);
		v21 = strtok(0, " \t\n\r");
		*getMemU32Ptr(0x5D4594, 1305824) = atoi(v21);
		result = 1;
		*a1 = getMemAt(0x5D4594, 1305820);
	} else if (!strcmp(a2, "SCROLLLISTBOX")) {
		memset(getMemAt(0x5D4594, 1306892), 0, 0x38u);
		v3 = strtok(a3, " \t\n\r");
		*getMemU16Ptr(0x5D4594, 1306892) = atoi(v3);
		v4 = strtok(0, " \t\n\r");
		*getMemU16Ptr(0x5D4594, 1306892 + 2) = atoi(v4);
		v5 = strtok(0, " \t\n\r");
		*getMemU32Ptr(0x5D4594, 1306892 + 4) = atoi(v5);
		v6 = strtok(0, " \t\n\r");
		*getMemU32Ptr(0x5D4594, 1306892 + 8) = atoi(v6);
		v7 = strtok(0, " \t\n\r");
		*getMemU32Ptr(0x5D4594, 1306892 + 12) = atoi(v7);
		v8 = strtok(0, " \t\n\r");
		*getMemU32Ptr(0x5D4594, 1306892 + 16) = atoi(v8);
		v9 = strtok(0, " \t\n\r");
		*getMemU32Ptr(0x5D4594, 1306892 + 20) = atoi(v9);
		result = 1;
		*a1 = getMemAt(0x5D4594, 1306892);
	} else if (!strcmp(a2, "ENTRYFIELD")) {
		memset(getMemAt(0x5D4594, 1305836), 0, 0x420u);
		v11 = strtok(a3, " \t\n\r");
		*getMemU16Ptr(0x5D4594, 1305836 + 1040) = atoi(v11);
		v12 = strtok(0, " \t\n\r");
		if (v12)
			*getMemU16Ptr(0x5D4594, 1305836 + 1042) = atoi(v12);
		else
			*getMemU16Ptr(0x5D4594, 1305836 + 1042) = -1;
		v13 = strtok(0, " \t\n\r");
		if (v13) {
			*getMemU32Ptr(0x5D4594, 1305836 + 1024) = atoi(v13) != 0;
		} else {
			*getMemU32Ptr(0x5D4594, 1305836 + 1024) = 0;
		}
		v14 = strtok(0, " \t\n\r");
		v15 = v14;
		if (v14) {
			*getMemU32Ptr(0x5D4594, 1305836 + 1028) = atoi(v14) == 1;
			*getMemU32Ptr(0x5D4594, 1305836 + 1032) = atoi(v15) == 2;
			*getMemU32Ptr(0x5D4594, 1305836 + 1036) = atoi(v15) == 3;
		} else {
			*getMemU32Ptr(0x5D4594, 1305836 + 1028) = 0;
			*getMemU32Ptr(0x5D4594, 1305836 + 1032) = 0;
			*getMemU32Ptr(0x5D4594, 1305836 + 1036) = 0;
		}
		*a1 = getMemAt(0x5D4594, 1305836);
		result = 1;
	} else if (!strcmp(a2, "STATICTEXT")) {
		v16 = strtok(a3, " \t\n\r");
		*getMemU32Ptr(0x5D4594, 1307256) = atoi(v16);
		*getMemU32Ptr(0x5D4594, 1307256) = *getMemU32Ptr(0x5D4594, 1307256) != 0;
		v17 = strtok(0, " \t\n\r");
		*getMemU32Ptr(0x5D4594, 1307260) = atoi(v17);
		*getMemU32Ptr(0x5D4594, 1307260) = *getMemU32Ptr(0x5D4594, 1307260) != 0;
		v18 = strtok(0, " \t\n\r");
		*getMemU32Ptr(0x5D4594, 1307252) =
			nox_xxx_loadString_40F1D0(v18, 0, "C:\\NoxPost\\src\\Client\\Gui\\GameWin\\psscript.c", 542);
		result = 1;
		*a1 = getMemAt(0x5D4594, 1307252);
	} else if (!strcmp(a2, "RADIOBUTTON")) {
		v19 = strtok(a3, " \t\n\r");
		*getMemU32Ptr(0x5D4594, 1305812) = atoi(v19);
		*getMemU32Ptr(0x5D4594, 1307256) = *getMemU32Ptr(0x5D4594, 1307256) != 0;
		result = 1;
		*a1 = getMemAt(0x5D4594, 1305812);
	} else {
		result = 1;
		*a1 = 0;
	}
	return result;
}
