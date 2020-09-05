#include "guishop.h"

#include "../../proto.h"
#include "guimsg.h"
extern _DWORD dword_5d4594_1098456;
extern _DWORD dword_5d4594_1098620;
extern _DWORD dword_5d4594_1098596;
extern _DWORD dword_5d4594_1098600;
extern _DWORD dword_5d4594_1098616;
extern _DWORD dword_5d4594_1098604;
extern _DWORD dword_5d4594_1098592;
extern _DWORD dword_5d4594_1098580;
extern _DWORD dword_5d4594_1098624;
extern _DWORD dword_5d4594_1107036;
extern _DWORD dword_5d4594_1098628;
extern _DWORD dword_5d4594_1098576;
extern _DWORD nox_client_renderGUI_80828;

//----- (00478730) --------------------------------------------------------
_DWORD* __cdecl sub_478730(int* a1) {
	int v1;              // ecx
	int v2;              // edx
	int v3;              // ecx
	_DWORD* result;      // eax
	unsigned __int8* v5; // esi
	unsigned int v6;     // eax
	unsigned int v7;     // ecx
	int v8;              // ebp
	const void* v9;      // ebx
	wchar_t* v10;        // eax
	int v11;             // [esp-24h] [ebp-34h]
	int v12;             // [esp-20h] [ebp-30h]
	int v13;             // [esp-1Ch] [ebp-2Ch]
	int v14;             // [esp-18h] [ebp-28h]

	v1 = (*a1 - *getMemU32Ptr(0x5D4594, 1098380)) / 50;
	v2 = (a1[1] - *getMemU32Ptr(0x5D4594, 1098384) + dword_5d4594_1107036) / 50;
	if (v1 >= 6)
		v1 = 5;
	if (v2 >= 10)
		v2 = 9;
	v3 = v2 + 10 * v1;
	result = *(_DWORD**)getMemAt(0x5D4594, 140 * v3 + 1098640);
	v5 = getMemAt(0x5D4594, 140 * v3 + 1098636);
	if (result) {
		v6 = sub_4674A0();
		v7 = *((_DWORD*)v5 + 34);
		v8 = *((_DWORD*)v5 + 1);
		if (v6 < v8 * *((_DWORD*)v5 + 34))
			v8 = v6 / v7;
		if (v8) {
			v9 = 0;
			if (*(_DWORD*)(*(_DWORD*)v5 + 112) & 0x13001000)
				v9 = (const void*)(*(_DWORD*)v5 + 432);
			sub_4C05F0(1, *((_DWORD*)v5 + 34));
			v14 = *(_DWORD*)(*(_DWORD*)v5 + 108);
			v13 = *(_DWORD*)&v5[4 * *((_DWORD*)v5 + 1) + 4];
			v12 = a1[1];
			v11 = *a1;
			v10 =
				loadString_sub_40F1D0((char*)getMemAt(0x587000, 152564), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIShop.c", 328);
			result = (_DWORD*)sub_4C0430((int)v10, v11, v12, v13, v14, v9, v8, 0, sub_478850, 0);
		} else {
			result = sub_479520(v7 - v6);
		}
	}
	return result;
}

//----- (00478880) --------------------------------------------------------
void __cdecl sub_478880(int a1, __int16 a2) {
	wchar_t* v2; // eax

	if (sub_467B00(a1, 1)) {
		LOWORD(a1) = 5833;
		HIWORD(a1) = a2;
		sub_40EBC0(31, 0, &a1, 4);
	} else {
		sub_452D80(925, 100);
		v2 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 152612), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIShop.c", 207);
		sub_445490(v2);
	}
}

//----- (004788F0) --------------------------------------------------------
void __cdecl sub_4788F0(int a1, int a2) {
	wchar_t* v2; // eax
	char v3[5];  // [esp+8h] [ebp-8h]

	if (sub_467B00(a1, a2)) {
		v3[0] = -55;
		v3[1] = 23;
		*(_WORD*)&v3[2] = a1;
		v3[4] = a2;
		sub_40EBC0(31, 0, v3, 5);
	} else {
		sub_452D80(925, 100);
		v2 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 152676), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIShop.c", 233);
		sub_445490(v2);
	}
}

//----- (00478B10) --------------------------------------------------------
wchar_t* __cdecl sub_478B10(int2* a1) {
	_DWORD* v1;      // esi
	wchar_t* result; // eax
	int v3;          // [esp+4h] [ebp-10h]
	int v4;          // [esp+8h] [ebp-Ch]
	int v5;          // [esp+Ch] [ebp-8h]
	int v6;          // [esp+10h] [ebp-4h]

	v1 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1098576, 3806);
	nox_client_wndGetPosition_46AA60(v1, &v5, &v6);
	nox_window_get_size((int)v1, &v4, &v3);
	nox_client_drawImageAt_47D2C0(*(int*)&dword_5d4594_1098456, a1->field_0, a1->field_4);
	result = *(wchar_t**)&dword_5d4594_1098596;
	if (dword_5d4594_1098596 ||
		(result = loadString_sub_40F1D0((char*)getMemAt(0x587000, 152740), *(_DWORD**)&dword_5d4594_1098596,
										"C:\\NoxPost\\src\\client\\Gui\\GUIShop.c", 597),
		 (dword_5d4594_1098596 = result) != 0)) {
		result = (wchar_t*)sub_43FAF0(0, result, v5 + 8, v6 + 8, v4 - 16, v3 - 16);
	}
	return result;
}

//----- (00478BC0) --------------------------------------------------------
wchar_t* __cdecl sub_478BC0(int* a1) {
	_DWORD* v1;      // esi
	wchar_t* result; // eax
	int v3;          // [esp+4h] [ebp-10h]
	int v4;          // [esp+8h] [ebp-Ch]
	int v5;          // [esp+Ch] [ebp-8h]
	int v6;          // [esp+10h] [ebp-4h]

	v1 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1098576, 3806);
	nox_client_wndGetPosition_46AA60(v1, &v5, &v6);
	nox_window_get_size((int)v1, &v4, &v3);
	sub_434390(*(int*)getMemAt(0x5D4594, 2523948));
	nox_client_drawImageAt_47D2C0(*(int*)&dword_5d4594_1098456, *a1, a1[1]);
	result = *(wchar_t**)&dword_5d4594_1098600;
	if (dword_5d4594_1098600 ||
		(result = loadString_sub_40F1D0((char*)getMemAt(0x587000, 152796), *(_DWORD**)&dword_5d4594_1098600,
										"C:\\NoxPost\\src\\client\\Gui\\GUIShop.c", 628),
		 (dword_5d4594_1098600 = result) != 0)) {
		result = (wchar_t*)sub_43FAF0(0, result, v5 + 8, v6 + 8, v4 - 16, v3 - 16);
	}
	return result;
}

//----- (00478FD0) --------------------------------------------------------
int __cdecl sub_478FD0(const wchar_t* a1, char* a2, int a3) {
	_DWORD* v3; // esi

	v3 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1098576, 3810);
	sub_445C20();
	dword_5d4594_1098624 = 1;
	dword_5d4594_1098628 = 1;
	nox_window_set_hidden(*(int*)&dword_5d4594_1098576, 0);
	sub_46ABB0(*(int*)&dword_5d4594_1098576, 1);
	sub_46A8C0(*(int*)&dword_5d4594_1098576);
	*getMemU32Ptr(0x5D4594, 1098612) = nox_client_renderGUI_80828;
	nox_client_renderGUI_80828 = 0;
	sub_467BB0();
	if (a1)
		nox_wcscpy((wchar_t*)getMemAt(0x5D4594, 1097300), a1);
	else
		nox_wcscpy((wchar_t*)getMemAt(0x5D4594, 1097300), (const wchar_t*)getMemAt(0x5D4594, 1107044));
	sub_46AEE0((int)v3, (int)getMemAt(0x5D4594, 1097300));
	if (strlen(a2)) {
		dword_5d4594_1098604 =
			loadString_sub_40F1D0(a2, getMemAt(0x5D4594, 1098608), "C:\\NoxPost\\src\\client\\Gui\\GUIShop.c", 1128);
	} else {
		dword_5d4594_1098604 = 0;
		*getMemU32Ptr(0x5D4594, 1098608) = 0;
	}
	sub_4790F0(a3);
	if (*getMemU32Ptr(0x5D4594, 1098608))
		sub_44D900(*(int*)getMemAt(0x5D4594, 1098608), 100);
	dword_5d4594_1107036 = 0;
	return nox_window_call_field_94(*(int*)&dword_5d4594_1098580, 16394, *(int*)&dword_5d4594_1098592, 0);
}

//----- (00479520) --------------------------------------------------------
_DWORD* __cdecl sub_479520(int a1) {
	wchar_t* v1; // eax
	wchar_t* v2; // eax

	v1 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 153264), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIShop.c", 1346);
	nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1097352), v1, a1);
	v2 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 153316), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIShop.c", 1350);
	sub_449A10(*(int*)&dword_5d4594_1098576, (int)v2, (int)getMemAt(0x5D4594, 1097352), 33, 0, 0);
	return sub_452D80(925, 100);
}

void sub_479680() { dword_5d4594_1098616 = 0; }

//----- (004795E0) --------------------------------------------------------
int __cdecl sub_4795E0(int a1, int a2) {
	const void* v2; // ebp
	int2* v3;       // ebx
	int result;     // eax
	int v5;         // esi
	wchar_t* v6;    // eax
	int v7;         // [esp-24h] [ebp-34h]
	int v8;         // [esp-20h] [ebp-30h]
	int v9;         // [esp-18h] [ebp-28h]
	int v10;        // [esp-10h] [ebp-20h]

	v2 = 0;
	v3 = nox_client_getMousePos_4309F0();
	result = dword_5d4594_1098616;
	if (dword_5d4594_1098616 != 1) {
		result = sub_4676D0(a1);
		v5 = result;
		if (result) {
			if (*(_DWORD*)(result + 112) & 0x13001000)
				v2 = (const void*)(result + 432);
			sub_4C05F0(1, a2);
			v10 = sub_467700(a1);
			v9 = *(_DWORD*)(v5 + 108);
			v8 = v3->field_4;
			v7 = v3->field_0;
			v6 =
				loadString_sub_40F1D0((char*)getMemAt(0x587000, 153376), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIShop.c", 1504);
			result = sub_4C0430((int)v6, v7, v8, a1, v9, v2, v10, 0, sub_479690, (int)&sub_479680);
			dword_5d4594_1098616 = 1;
		}
	}
	return result;
}

//----- (00479740) --------------------------------------------------------
void __cdecl sub_479740(int a1, unsigned int a2) {
	const void* v2;   // ebp
	int2* v3;         // ebx
	int v4;           // eax
	int v5;           // edi
	wchar_t* v6;      // eax
	int v7;           // [esp-24h] [ebp-38h]
	int v8;           // [esp-20h] [ebp-34h]
	int v9;           // [esp-18h] [ebp-2Ch]
	unsigned int v10; // [esp+10h] [ebp-4h]

	v2 = 0;
	v3 = nox_client_getMousePos_4309F0();
	v10 = sub_4674A0();
	if (dword_5d4594_1098620 != 1) {
		v4 = sub_4676D0(a1);
		v5 = v4;
		if (v4) {
			if (*(_DWORD*)(v4 + 112) & 0x13001000)
				v2 = (const void*)(v4 + 432);
			sub_4C05F0(1, a2);
			if (a2 > v10) {
				sub_479520(a2 - v10);
				sub_467680();
			} else {
				v9 = *(_DWORD*)(v5 + 108);
				v8 = v3->field_4;
				v7 = v3->field_0;
				v6 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 153424), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIShop.c",
										   1580);
				sub_4C0430((int)v6, v7, v8, a1, v9, v2, 1, 0, sub_479820, sub_479810);
				dword_5d4594_1098620 = 1;
			}
		}
	}
}
