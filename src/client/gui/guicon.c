#include "guicon.h"

#include "../system/parsecmd.h"

#include "../../proto.h"
extern _DWORD dword_5d4594_833732;
extern _DWORD dword_5d4594_833720;
extern _DWORD dword_5d4594_833712;
extern _DWORD dword_5d4594_833716;

//----- (00450C30) --------------------------------------------------------
wchar_t* __cdecl sub_450C30(unsigned __int8 a1, int a2) {
	wchar_t* result; // eax

	if (a2)
		return (wchar_t*)sub_450B90(a1, a2);
	result = loadString_sub_40F1D0((char*)&byte_587000[126456], 0, "C:\\NoxPost\\src\\Client\\Gui\\guicon.c", 97);
	if (result)
		result = (wchar_t*)sub_450B90(a1, (int)result);
	return result;
}

//----- (00450FD0) --------------------------------------------------------
int sub_450FD0() {
	wchar_t* v0;     // esi
	size_t v1;       // eax
	wchar_t* v3;     // [esp-14h] [ebp-218h]
	wchar_t* v4;     // [esp-14h] [ebp-218h]
	wchar_t v5[256]; // [esp+4h] [ebp-200h]

	if (!*(_DWORD*)(*(_DWORD*)(dword_5d4594_833716 + 32) + 1044)) {
		v0 = (wchar_t*)nox_window_call_field_94(*(int*)&dword_5d4594_833716, 16413, 0, 0);
		if (dword_5d4594_833732 && *(_WORD*)&byte_5D4594[832552]) {
			if (_nox_wcsicmp(v0, (const wchar_t*)&byte_5D4594[832552])) {
				v4 = loadString_sub_40F1D0((char*)&byte_587000[126560], 0,
							   "C:\\NoxPost\\src\\Client\\Gui\\guicon.c", 124);
				sub_450C30(4u, (int)v4);
			} else {
				dword_5d4594_833732 = 0;
				v3 = loadString_sub_40F1D0((char*)&byte_587000[126508], 0,
							   "C:\\NoxPost\\src\\Client\\Gui\\guicon.c", 121);
				sub_450C30(6u, (int)v3);
			}
			nox_window_call_field_94(*(int*)&dword_5d4594_833716, 16414, (int)&byte_5D4594[833744], 0);
		} else {
			nox_wcscpy(v5, L"> ");
			nox_wcscat(v5, v0);
			sub_450B90(4u, (int)v5);
			if (v0) {
				if (*(_DWORD*)&nox_common_engineFlags & 0x200000) {
					v1 = nox_wcslen(v0);
					sub_4D33E0(v0, v1 + 1);
				}
				nox_server_parseCmdText_443C80(v0, 0);
			}
			nox_window_call_field_94(*(int*)&dword_5d4594_833716, 16414, (int)&byte_5D4594[833748], 0);
		}
	}
	return 1;
}

//----- (00451350) --------------------------------------------------------
int sub_451350() {
	int result;  // eax
	wchar_t* v1; // eax

	if (!(sub_46ADA0(*(int*)&dword_5d4594_833712) & 0x10))
		return sub_4512B0();
	result = sub_446360();
	if (!result) {
		sub_46A8C0(*(int*)&dword_5d4594_833712);
		*(_DWORD*)(dword_5d4594_833712 + 4) |= 8u;
		*(_DWORD*)(dword_5d4594_833720 + 4) |= 8u;
		*(_DWORD*)(dword_5d4594_833716 + 4) |= 8u;
		*(_DWORD*)(dword_5d4594_833716 + 4) |= 1u;
		sub_46B500(*(int*)&dword_5d4594_833716);
		result = *(_DWORD*)&byte_5D4594[833728];
		if (*(_DWORD*)&byte_5D4594[833728]) {
			sub_450B70();
			v1 = loadString_sub_40F1D0((char*)&byte_587000[126620], 0,
						   "C:\\NoxPost\\src\\Client\\Gui\\guicon.c", 459);
			result = sub_450C00(4u, v1);
			dword_5d4594_833732 = 1;
		}
	}
	return result;
}
