#include "guicon.h"

#include "../system/parsecmd.h"

#include "../../proto.h"
extern _DWORD dword_5d4594_833728;
extern _DWORD dword_5d4594_833732;
extern _DWORD dword_5d4594_833720;
extern _DWORD dword_5d4594_833712;
extern _DWORD dword_5d4594_833716;

//----- (00450C30) --------------------------------------------------------
wchar_t* __cdecl sub_450C30(unsigned __int8 a1, int a2) {
	wchar_t* result; // eax

	if (a2)
		return (wchar_t*)nox_xxx_consolePrint_450B90(a1, a2);
	result = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 126456), 0, "C:\\NoxPost\\src\\Client\\Gui\\guicon.c", 97);
	if (result)
		result = (wchar_t*)nox_xxx_consolePrint_450B90(a1, (int)result);
	return result;
}

//----- (00450FD0) --------------------------------------------------------
int nox_xxx_consoleEnter_450FD0() {
	wchar_t* v0;     // esi
	size_t v1;       // eax
	wchar_t* v3;     // [esp-14h] [ebp-218h]
	wchar_t* v4;     // [esp-14h] [ebp-218h]
	wchar_t v5[256]; // [esp+4h] [ebp-200h]

	if (!*(_DWORD*)(*(_DWORD*)(dword_5d4594_833716 + 32) + 1044)) {
		v0 = (wchar_t*)nox_window_call_field_94(*(int*)&dword_5d4594_833716, 16413, 0, 0);
		if (dword_5d4594_833732 && *getMemU16Ptr(0x5D4594, 832552)) {
			if (_nox_wcsicmp(v0, (const wchar_t*)getMemAt(0x5D4594, 832552))) {
				v4 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 126560), 0, "C:\\NoxPost\\src\\Client\\Gui\\guicon.c",
										   124);
				sub_450C30(4u, (int)v4);
			} else {
				dword_5d4594_833732 = 0;
				v3 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 126508), 0, "C:\\NoxPost\\src\\Client\\Gui\\guicon.c",
										   121);
				sub_450C30(6u, (int)v3);
			}
			nox_window_call_field_94(*(int*)&dword_5d4594_833716, 16414, (int)getMemAt(0x5D4594, 833744), 0);
		} else {
			nox_wcscpy(v5, L"> ");
			nox_wcscat(v5, v0);
			nox_xxx_consolePrint_450B90(4u, (int)v5);
			if (v0) {
				if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_22)) {
					v1 = nox_wcslen(v0);
					nox_xxx_replaySaveConsole_4D33E0(v0, v1 + 1);
				}
				nox_server_parseCmdText_443C80(v0, 0);
			}
			nox_window_call_field_94(*(int*)&dword_5d4594_833716, 16414, (int)getMemAt(0x5D4594, 833748), 0);
		}
	}
	return 1;
}

//----- (00451350) --------------------------------------------------------
int nox_xxx_consoleF1_451350() {
	int result;  // eax
	wchar_t* v1; // eax

	if (!(sub_46ADA0(*(int*)&dword_5d4594_833712) & 0x10))
		return sub_4512B0();
	result = sub_446360();
	if (!result) {
		nox_xxx_wndShowModalMB_46A8C0(*(int*)&dword_5d4594_833712);
		*(_DWORD*)(dword_5d4594_833712 + 4) |= 8u;
		*(_DWORD*)(dword_5d4594_833720 + 4) |= 8u;
		*(_DWORD*)(dword_5d4594_833716 + 4) |= 8u;
		*(_DWORD*)(dword_5d4594_833716 + 4) |= 1u;
		nox_xxx_windowDestroyChildsMB_46B500(*(int*)&dword_5d4594_833716);
		result = dword_5d4594_833728;
		if (dword_5d4594_833728) {
			nox_xxx_conClear_450B70();
			v1 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 126620), 0, "C:\\NoxPost\\src\\Client\\Gui\\guicon.c", 459);
			result = nox_xxx_consoleVPrint_450C00(4u, v1);
			dword_5d4594_833732 = 1;
		}
	}
	return result;
}
