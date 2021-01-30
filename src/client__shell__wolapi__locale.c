#include "proto.h"

extern _DWORD dword_5d4594_1312476;
extern _DWORD dword_5d4594_1312472;
extern _DWORD dword_5d4594_1312484;
extern _DWORD dword_5d4594_1312480;
extern int nox_win_width;
extern int nox_win_height;

//----- (004B5770) --------------------------------------------------------
int __cdecl sub_4B5770_wol_locale(int a1) {
	int i;       // esi
	wchar_t* v2; // eax
	wchar_t* v3; // eax
	_DWORD* v4;  // esi
	_DWORD* v5;  // ebx
	_DWORD* v6;  // ebp
	_DWORD* v7;  // edi
	char* v8;    // eax
	char* v10;   // [esp+14h] [ebp+4h]

	*getMemU32Ptr(0x5D4594, 1312488) = a1;
	dword_5d4594_1312480 = nox_new_window_from_file("locale.wnd", sub_4B5AB0);
	nox_wnd_nox_xxx_wndDraw_46A9B0(*(_DWORD**)&dword_5d4594_1312480, nox_win_width / 2 - 75, nox_win_height / 2 - 77);
	sub_46B120(*(_DWORD**)&dword_5d4594_1312480, 0);
	nox_xxx_wndShowModalMB_46A8C0(*(int*)&dword_5d4594_1312480);
	sub_46C690(*(int*)&dword_5d4594_1312480);
	nox_xxx_windowDestroyChildsMB_46B500(*(int*)&dword_5d4594_1312480);
	dword_5d4594_1312484 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1312480, 1981);
	sub_4B5990();
	for (i = 0; i < *(int*)&dword_5d4594_1312472; ++i)
		nox_window_call_field_94(*(int*)&dword_5d4594_1312484, 16397, *(_DWORD*)(dword_5d4594_1312476 + 4 * i), -1);
	v2 =
		nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 174848), 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\locale.c", 213);
	nox_window_call_field_94(*(int*)&dword_5d4594_1312484, 16397, (int)v2, -1);
	nox_window_call_field_94(*(int*)&dword_5d4594_1312484, 16403, 0, 0);
	v3 =
		nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 174900), 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\locale.c", 216);
	nox_window_call_field_94(*(int*)&dword_5d4594_1312484, 16397, (int)v3, -1);
	nox_window_call_field_94(*(int*)&dword_5d4594_1312484, 16403, 0, 0);
	v4 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1312480, 1982);
	v5 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1312480, 1983);
	v6 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1312480, 1984);
	v7 = *(_DWORD**)(dword_5d4594_1312484 + 32);
	v10 = nox_xxx_gLoadImg_42F970("UISlider");
	v8 = nox_xxx_gLoadImg_42F970("UISliderLit");
	sub_4B5700((int)v4, 0, 0, (int)v10, (int)v8, (int)v8);
	nox_xxx_wnd_46B280((int)v4, *(int*)&dword_5d4594_1312484);
	nox_xxx_wnd_46B280((int)v5, *(int*)&dword_5d4594_1312484);
	nox_xxx_wnd_46B280((int)v6, *(int*)&dword_5d4594_1312484);
	v7[9] = v4;
	v7[7] = v5;
	v7[8] = v6;
	*(_DWORD*)(v4[100] + 8) = 16;
	*(_DWORD*)(v4[100] + 12) = 10;
	return 1;
}

//----- (004B5A30) --------------------------------------------------------
wchar_t* __cdecl sub_4B5A30_wol_locale(wchar_t* a1) {
	int v1;         // ebp
	__int16* v2;    // edi
	char** v3;      // ebx
	wchar_t* v4;    // esi
	__int16 v6[16]; // [esp+8h] [ebp-20h]

	v1 = 0;
	memset(v6, 0xFFu, sizeof(v6));
	v2 = v6;
	if (*(int*)&dword_5d4594_1312472 <= 0)
		return (wchar_t*)v6;
	v3 = (char**)getMemAt(0x587000, 174360);
	do {
		v4 = nox_strman_loadString_40F1D0(*v3, 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\locale.c", 101);
		if (nox_wcscmp(v4, (const wchar_t*)v2) < 0 && nox_wcscmp(v4, a1) > 0)
			v2 = (__int16*)v4;
		++v1;
		v3 += 2;
	} while (v1 < *(int*)&dword_5d4594_1312472);
	return (wchar_t*)v2;
}

//----- (004B5B70) --------------------------------------------------------
int __cdecl sub_4B5B70_wol_locale(wchar_t* a1) {
	int v1;      // edi
	char** v2;   // esi
	wchar_t* v3; // eax
	wchar_t* v4; // eax
	int result;  // eax

	v1 = 0;
	if (*(int*)&dword_5d4594_1312472 <= 0) {
	LABEL_5:
		v4 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 175064), 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\locale.c",
								   78);
		result = nox_wcscmp(a1, v4) != 0;
	} else {
		v2 = (char**)getMemAt(0x587000, 174360);
		while (1) {
			v3 = nox_strman_loadString_40F1D0(*v2, 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\locale.c", 71);
			if (!nox_wcscmp(a1, v3))
				break;
			++v1;
			v2 += 2;
			if (v1 >= *(int*)&dword_5d4594_1312472)
				goto LABEL_5;
		}
		result = *getMemU32Ptr(0x587000, 8 * v1 + 174364);
	}
	return result;
}
