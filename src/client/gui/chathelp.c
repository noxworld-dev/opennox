#include "chathelp.h"

#include "../../proto.h"
#include "servopts/guiserv.h"

extern _DWORD dword_5d4594_1305680;
extern _DWORD dword_587000_26048;
extern int nox_win_width;
extern int nox_win_height;

//----- (0049C560) --------------------------------------------------------
_DWORD* nox_xxx_cliShowHelpGui_49C560() {
	int v0;         // esi
	_DWORD* result; // eax
	_DWORD* v2;     // esi
	wchar_t* v3;    // eax
	wchar_t* v4;    // eax
	wchar_t* v5;    // eax
	char* v6;       // [esp-4h] [ebp-8h]
	char* v7;       // [esp-4h] [ebp-8h]
	char* v8;       // [esp-4h] [ebp-8h]

	v0 = dword_587000_26048;
	if (nox_xxx_guiFontHeightMB_43F320(0) > 10)
		v0 = 2;
	result = nox_new_window_from_file(*(const char**)getMemAt(0x587000, 4 * v0 + 164512), nox_xxx_wnd_49C760);
	dword_5d4594_1305680 = result;
	if (result) {
		sub_46B120(result, 0);
		nox_xxx_wndShowModalMB_46A8C0(*(int*)&dword_5d4594_1305680);
		sub_46C690(*(int*)&dword_5d4594_1305680);
		nox_xxx_windowDestroyChildsMB_46B500(*(int*)&dword_5d4594_1305680);
		nox_wnd_nox_xxx_wndDraw_46A9B0(*(_DWORD**)&dword_5d4594_1305680, (nox_win_width - *(int*)(dword_5d4594_1305680 + 8)) / 2,
						   (nox_win_height - *(int*)(dword_5d4594_1305680 + 12)) / 2);
		if (nox_common_gameFlags_check_40A5C0(1)) {
			v2 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1305680, 4102);
			v6 = sub_42E8E0(45, 1);
			v3 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 164712), 0, "C:\\NoxPost\\src\\client\\Gui\\chathelp.c", 85);
			nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1304656), v3, v6);
			nox_wcscat((wchar_t*)getMemAt(0x5D4594, 1304656), L" ");
			v7 = sub_42E8E0(8, 1);
			v4 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 164776), 0, "C:\\NoxPost\\src\\client\\Gui\\chathelp.c", 87);
		} else {
			v2 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1305680, 4102);
			v8 = sub_42E8E0(45, 1);
			v5 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 164836), 0, "C:\\NoxPost\\src\\client\\Gui\\chathelp.c", 94);
			nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1304656), v5, v8);
			nox_wcscat((wchar_t*)getMemAt(0x5D4594, 1304656), L" ");
			v7 = sub_42E8E0(8, 1);
			v4 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 164904), 0, "C:\\NoxPost\\src\\client\\Gui\\chathelp.c", 96);
		}
		nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1304400), v4, v7);
		nox_wcscat((wchar_t*)getMemAt(0x5D4594, 1304656), (const wchar_t*)getMemAt(0x5D4594, 1304400));
		nox_window_call_field_94((int)v2, 16385, (int)getMemAt(0x5D4594, 1304656), 0);
		if (nox_common_gameFlags_check_40A5C0(1)) {
			if (!sub_459DA0())
				nox_xxx_guiServerOptsLoad_457500();
			sub_459D80(1);
		}
		if (nox_common_gameFlags_check_40A5C0(4096) || (result = (_DWORD*)sub_4D6F50()) != 0)
			result = (_DWORD*)sub_49C7A0();
	}
	return result;
}
