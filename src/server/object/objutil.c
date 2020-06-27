#include "../../proto.h"

//----- (004E77E0) --------------------------------------------------------
wchar_t* __cdecl sub_4E77E0_obj_util(int a1) {
	int v1;            // eax
	_DWORD* v2;        // edi
	_DWORD* v3;        // eax
	_DWORD* v4;        // ebx
	wchar_t* v5;       // eax
	int v7;            // eax
	const wchar_t* v8; // eax
	int v9;            // eax
	int v10;           // eax
	wchar_t* v11;      // eax
	int v12;           // [esp-4h] [ebp-10h]

	v1 = *(_DWORD*)(a1 + 8);
	if (v1 & 0x13001000) {
		v2 = *(_DWORD**)(a1 + 692);
		if (v1 & 0x11001000)
			v3 = sub_413250(*(unsigned __int16*)(a1 + 4));
		else
			v3 = sub_413270(*(unsigned __int16*)(a1 + 4));
		v4 = v3;
		if (!v3) {
			v12 = sub_4E39D0(a1);
			v5 = loadString_sub_40F1D0((char*)&byte_587000[203812], 0, "C:\\NoxPost\\src\\Server\\Object\\objutil.c",
									   983);
			nox_swprintf((wchar_t*)&byte_5D4594[1565660], v5, v12);
			return (wchar_t*)&byte_5D4594[1565660];
		}
		nox_wcscpy((wchar_t*)&byte_5D4594[1565660], (const wchar_t*)&byte_5D4594[1567732]);
		if (*v2 && *(_DWORD*)(*v2 + 8)) {
			nox_wcscat((wchar_t*)&byte_5D4594[1565660], *(const wchar_t**)(*v2 + 8));
			nox_wcscat((wchar_t*)&byte_5D4594[1565660], L" ");
		}
		v7 = v2[1];
		if (v7) {
			v8 = *(const wchar_t**)(v7 + 8);
			if (v8) {
				nox_wcscat((wchar_t*)&byte_5D4594[1565660], v8);
				nox_wcscat((wchar_t*)&byte_5D4594[1565660], L" ");
			}
		}
		if (v4[2])
			nox_wcscat((wchar_t*)&byte_5D4594[1565660], (const wchar_t*)v4[2]);
		v9 = v2[2];
		if (v9 && *(_DWORD*)(v9 + 8)) {
			nox_wcscat((wchar_t*)&byte_5D4594[1565660], L" ");
			nox_wcscat((wchar_t*)&byte_5D4594[1565660], *(const wchar_t**)(v2[2] + 8));
		}
		v10 = v2[3];
		if (v10 && *(_DWORD*)(v10 + 12)) {
			nox_wcscat((wchar_t*)&byte_5D4594[1565660], L" ");
			nox_wcscat((wchar_t*)&byte_5D4594[1565660], *(const wchar_t**)(v2[3] + 12));
			return (wchar_t*)&byte_5D4594[1565660];
		}
	} else {
		v11 =
			loadString_sub_40F1D0((char*)&byte_587000[203876], 0, "C:\\NoxPost\\src\\Server\\Object\\objutil.c", 1032);
		nox_wcscpy((wchar_t*)&byte_5D4594[1565660], v11);
	}
	return (wchar_t*)&byte_5D4594[1565660];
}