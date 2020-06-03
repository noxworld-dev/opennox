#include "objlst.h"

#include "../../../proto.h"

//----- (004530C0) --------------------------------------------------------
int __cdecl sub_4530C0(int a1, int a2) {
	int v2;          // edi
	wchar_t* v3;     // eax
	int v4;          // esi
	int v5;          // ebx
	int v6;          // eax
	wchar_t* v7;     // eax
	int v8;          // esi
	int v9;          // ebx
	int v10;         // eax
	_DWORD* v11;     // eax
	_DWORD* v12;     // eax
	wchar_t v14[66]; // [esp+Ch] [ebp-84h]

	v2 = 0;
	*(_DWORD*)&byte_5D4594[1045468] = nox_new_window_from_file("objlst.wnd", sub_4533D0);
	sub_46B340(*(int*)&byte_5D4594[1045468], sub_453350);
	sub_46B120(*(_DWORD**)&byte_5D4594[1045468], a1);
	sub_46B280(*(int*)&byte_5D4594[1045468], a1);
	*(_DWORD*)&byte_5D4594[1045464] = sub_46B0C0(*(_DWORD**)&byte_5D4594[1045468], 1510);
	sub_4532E0();
	nox_window_call_field_94(*(int*)&byte_5D4594[1045464], 16399, 0, 0);
	if (a2 == 0x1000000) {
		*(_DWORD*)&byte_5D4594[1045460] = 0;
		v7 = loadString_sub_40F1D0((char*)&byte_587000[127380], 0,
					   "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\objlst.c", 321);
		nox_wcscpy(v14, v7);
		v8 = 4;
		v9 = 25;
		do {
			v10 = sub_4159F0(v8);
			if (v10) {
				nox_window_call_field_94(*(int*)&byte_5D4594[1045464], 16397, v10, -1);
				++v2;
			}
			v8 *= 2;
			--v9;
		} while (v9);
	} else if (a2 == 0x2000000) {
		*(_DWORD*)&byte_5D4594[1045460] = 1;
		v3 = loadString_sub_40F1D0((char*)&byte_587000[127316], 0,
					   "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\objlst.c", 308);
		nox_wcscpy(v14, v3);
		v4 = 1;
		v5 = 26;
		do {
			v6 = sub_415E80(v4);
			if (v6) {
				nox_window_call_field_94(*(int*)&byte_5D4594[1045464], 16397, v6, -1);
				++v2;
			}
			v4 *= 2;
			--v5;
		} while (v5);
	}
	nox_window_call_field_94(*(int*)&byte_5D4594[1045464], 16385, (int)v14, 0);
	v11 = sub_46B0C0(*(_DWORD**)&byte_5D4594[1045468], 1513);
	nox_window_call_field_94(*(int*)&byte_5D4594[1045464], 16408, (int)v11, 0);
	v12 = sub_46B0C0(*(_DWORD**)&byte_5D4594[1045468], 1514);
	nox_window_call_field_94(*(int*)&byte_5D4594[1045464], 16409, (int)v12, 0);
	*(_DWORD*)&byte_5D4594[4 * *(_DWORD*)&byte_5D4594[1045460] + 1045472] = v2;
	sub_453750();
	if (!nox_common_gameFlags_check_40A5C0(1) || nox_common_gameFlags_check_40A5C0(49152))
		sub_46AD20(*(_DWORD**)&byte_5D4594[1045468], 1515, 1533, 0);
	return *(_DWORD*)&byte_5D4594[1045468];
}
