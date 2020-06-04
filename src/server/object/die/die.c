#include "../../../common/object/armrlook.h"
#include "../objutil.h"

#include "../../../proto.h"
extern _DWORD dword_587000_26048;

// TODO: convert table_274080

//----- (0054E170) --------------------------------------------------------
void __cdecl sub_54E170_obj_die(int a1) {
	int v1;      // ebx
	int v2;      // edi
	_DWORD* v3;  // eax
	__int16 v4;  // ax
	int v5;      // ebp
	__int16 v6;  // ax
	wchar_t* v7; // esi
	int v8;      // edi
	wchar_t* v9; // eax
	float2* v10; // [esp+14h] [ebp+4h]

	v1 = a1;
	v2 = 0;
	if (!dword_587000_26048 || dword_587000_26048 == 1) {
		v3 = sub_413270(*(unsigned __int16*)(a1 + 4));
		if (v3) {
			v4 = *(_WORD*)(v3[2] + 2 * nox_wcslen((const wchar_t*)v3[2]) - 2);
			if (v4 == 83 || v4 == 115)
				v2 = 1;
		}
	}
	v5 = *(_DWORD*)(a1 + 492);
	if (v5)
		v10 = (float2*)(v5 + 56);
	else
		v10 = (float2*)(a1 + 56);
	v6 = *(_WORD*)(v1 + 24);
	if (v6 & 0x10) {
		if (v2)
			v7 = loadString_sub_40F1D0((char*)&byte_587000[290860], 0,
						   "C:\\NoxPost\\src\\Server\\Object\\die\\Die.c", 1536);
		else
			v7 = loadString_sub_40F1D0((char*)&byte_587000[290920], 0,
						   "C:\\NoxPost\\src\\Server\\Object\\die\\Die.c", 1538);
		v8 = 806;
	} else if (v6 & 8) {
		if (v2)
			v7 = loadString_sub_40F1D0((char*)&byte_587000[290976], 0,
						   "C:\\NoxPost\\src\\Server\\Object\\die\\Die.c", 1547);
		else
			v7 = loadString_sub_40F1D0((char*)&byte_587000[291036], 0,
						   "C:\\NoxPost\\src\\Server\\Object\\die\\Die.c", 1549);
		v8 = 812;
	} else if (v6 & 4) {
		if (v2)
			v7 = loadString_sub_40F1D0((char*)&byte_587000[291092], 0,
						   "C:\\NoxPost\\src\\Server\\Object\\die\\Die.c", 1558);
		else
			v7 = loadString_sub_40F1D0((char*)&byte_587000[291152], 0,
						   "C:\\NoxPost\\src\\Server\\Object\\die\\Die.c", 1560);
		v8 = 809;
	} else if (v6 & 2) {
		if (v2)
			v7 = loadString_sub_40F1D0((char*)&byte_587000[291208], 0,
						   "C:\\NoxPost\\src\\Server\\Object\\die\\Die.c", 1569);
		else
			v7 = loadString_sub_40F1D0((char*)&byte_587000[291268], 0,
						   "C:\\NoxPost\\src\\Server\\Object\\die\\Die.c", 1571);
		v8 = 815;
	} else {
		v8 = (int)v10;
		v7 = loadString_sub_40F1D0((char*)&byte_587000[291324], 0,
					   "C:\\NoxPost\\src\\Server\\Object\\die\\Die.c", 1579);
	}
	v9 = sub_4E77E0_obj_util(v1);
	sub_4D9EB0(v5, v7, v9);
	sub_501A30(v8, v10, 0, 0);
	sub_4E5CC0(v1);
}

//----- (0054E370) --------------------------------------------------------
void __cdecl sub_54E370_obj_die(int a1) {
	int v1;      // edi
	float2* v2;  // ebx
	__int16 v3;  // ax
	wchar_t* v4; // eax
	wchar_t* v5; // eax
	wchar_t* v6; // eax
	wchar_t* v7; // [esp-4h] [ebp-10h]
	wchar_t* v8; // [esp-4h] [ebp-10h]
	wchar_t* v9; // [esp-4h] [ebp-10h]

	v1 = *(_DWORD*)(a1 + 492);
	v2 = (float2*)(v1 + 56);
	if (!v1)
		v2 = (float2*)(a1 + 56);
	v3 = *(_WORD*)(a1 + 24);
	if (v3 & 0x10) {
		v7 = sub_4E77E0_obj_util(a1);
		v4 = loadString_sub_40F1D0((char*)&byte_587000[291380], 0,
					   "C:\\NoxPost\\src\\Server\\Object\\die\\Die.c", 1626);
		sub_4D9EB0(v1, v4, v7);
		sub_501A30(818, v2, 0, 0);
		sub_4E5CC0(a1);
	} else {
		if (v3 & 8) {
			v8 = sub_4E77E0_obj_util(a1);
			v5 = loadString_sub_40F1D0((char*)&byte_587000[291436], 0,
						   "C:\\NoxPost\\src\\Server\\Object\\die\\Die.c", 1633);
			sub_4D9EB0(v1, v5, v8);
			sub_501A30(819, v2, 0, 0);
		} else {
			v9 = sub_415B60(a1);
			v6 = loadString_sub_40F1D0((char*)&byte_587000[291492], 0,
						   "C:\\NoxPost\\src\\Server\\Object\\die\\Die.c", 1640);
			sub_4D9EB0(v1, v6, v9);
		}
		sub_4E5CC0(a1);
	}
}