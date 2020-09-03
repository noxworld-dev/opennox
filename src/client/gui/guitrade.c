#include "guitrade.h"

#include "../../proto.h"
#include "gamewin/gamewin.h"
#include "guimsg.h"

extern _DWORD dword_5d4594_1320964;
extern _DWORD dword_5d4594_1320940;
extern int nox_win_width;
extern int nox_win_height;

//----- (004C09D0) --------------------------------------------------------
int sub_4C09D0() {
	_DWORD* v0;           // eax
	wchar_t* v2;          // eax
	wchar_t* v3;          // esi
	wchar_t* v4;          // eax
	wchar_t* v5;          // esi
	wchar_t* v6;          // eax
	_DWORD* v7;           // eax
	_DWORD* v8;           // eax
	wchar_t* v9;          // esi
	wchar_t* v10;         // eax
	wchar_t* v11;         // esi
	wchar_t* v12;         // eax
	wchar_t* v13;         // esi
	wchar_t* v14;         // eax
	unsigned __int8* v15; // edx
	unsigned __int8* v16; // eax
	int v17;              // ecx
	unsigned __int8* v18; // edx
	unsigned __int8* v19; // eax
	int v20;              // ecx
	wchar_t* v21;         // eax

	v0 = nox_new_window_from_file("Trade.wnd", sub_4C0C90);
	dword_5d4594_1320940 = v0;
	if (!v0)
		return 0;
	nox_window_set_all_funcs(v0, sub_4C0630, sub_4C0D00, 0);
	v2 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 183764), 0, "C:\\NoxPost\\src\\client\\Gui\\GUITrade.c", 692);
	sub_46B000((wchar_t*)(dword_5d4594_1320940 + 36), v2);
	v3 = (wchar_t*)sub_46B0C0(*(_DWORD**)&dword_5d4594_1320940, 3702);
	v4 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 183816), 0, "C:\\NoxPost\\src\\client\\Gui\\GUITrade.c", 695);
	sub_46B000(v3 + 18, v4);
	v5 = (wchar_t*)sub_46B0C0(*(_DWORD**)&dword_5d4594_1320940, 3703);
	v6 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 183872), 0, "C:\\NoxPost\\src\\client\\Gui\\GUITrade.c", 698);
	sub_46B000(v5 + 18, v6);
	v7 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1320940, 3704);
	sub_46B070((int)v7, sub_4C1120);
	v8 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1320940, 3705);
	sub_46B070((int)v8, sub_4C1120);
	v9 = (wchar_t*)sub_46B0C0(*(_DWORD**)&dword_5d4594_1320940, 3708);
	v10 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 183928), 0, "C:\\NoxPost\\src\\client\\Gui\\GUITrade.c", 709);
	sub_46B000(v9 + 18, v10);
	v11 = (wchar_t*)sub_46B0C0(*(_DWORD**)&dword_5d4594_1320940, 3709);
	v12 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 183988), 0, "C:\\NoxPost\\src\\client\\Gui\\GUITrade.c", 712);
	sub_46B000(v11 + 18, v12);
	v13 = (wchar_t*)sub_46B0C0(*(_DWORD**)&dword_5d4594_1320940, 3710);
	v14 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 184048), 0, "C:\\NoxPost\\src\\client\\Gui\\GUITrade.c", 715);
	sub_46B000(v13 + 18, v14);
	nox_window_set_hidden(*(int*)&dword_5d4594_1320940, 1);
	sub_46ABB0(*(int*)&dword_5d4594_1320940, 0);
	v15 = getMemAt(0x5D4594, 1319288);
	do {
		v16 = v15;
		v17 = 2;
		do {
			*((_DWORD*)v16 - 1) = 0;
			*(_DWORD*)v16 = 0;
			v16 += 280;
			--v17;
		} while (v17);
		v15 += 140;
	} while ((int)v15 < (int)getMemAt(0x5D4594, 1319568));
	v18 = getMemAt(0x5D4594, 1320312);
	do {
		v19 = v18;
		v20 = 2;
		do {
			*((_DWORD*)v19 - 1) = 0;
			*(_DWORD*)v19 = 0;
			v19 += 280;
			--v20;
		} while (v20);
		v18 += 140;
	} while ((int)v18 < (int)getMemAt(0x5D4594, 1320592));
	v21 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 184100), 0, "C:\\NoxPost\\src\\client\\Gui\\GUITrade.c", 749);
	nox_wcscpy((wchar_t*)getMemAt(0x5D4594, 1319972), v21);
	*(_DWORD*)getMemAt(0x5D4594, 1320188) = 0;
	*(_DWORD*)getMemAt(0x5D4594, 1320192) = 0;
	*(_DWORD*)getMemAt(0x5D4594, 1320196) = nox_win_width;
	*(_DWORD*)getMemAt(0x5D4594, 1320200) = nox_win_height;
	*(_DWORD*)getMemAt(0x5D4594, 1320220) = nox_win_width;
	*(_DWORD*)getMemAt(0x5D4594, 1320224) = nox_win_height;
	*(_DWORD*)getMemAt(0x5D4594, 1320204) = 0;
	*(_DWORD*)getMemAt(0x5D4594, 1320208) = 0;
	*(_DWORD*)getMemAt(0x5D4594, 1320164) = sub_42F970("TradeBase");
	*(_DWORD*)getMemAt(0x5D4594, 1320168) = sub_42F970("TradeLeftAcceptPushed");
	*(_DWORD*)getMemAt(0x5D4594, 1320172) = sub_42F970("TradeLeftAcceptLit");
	*(_DWORD*)getMemAt(0x5D4594, 1320176) = sub_42F970("TradeRightAcceptLit");
	*(_DWORD*)getMemAt(0x5D4594, 1320180) = sub_42F970("TradeCancelLit");
	*(_DWORD*)getMemAt(0x5D4594, 1320184) = sub_42F970("TradeGold");
	return 1;
}

//----- (004C15D0) --------------------------------------------------------
int __cdecl sub_4C15D0(int a1) {
	int result;           // eax
	int v2;               // ebp
	unsigned __int8* v3;  // ebx
	int v4;               // esi
	int v5;               // edi
	unsigned __int8* v6;  // esi
	int v7;               // ebp
	unsigned __int8* v8;  // ebx
	int v9;               // esi
	int v10;              // edi
	wchar_t* v11;         // eax
	unsigned __int8* v12; // [esp+8h] [ebp-4h]

	result = dword_5d4594_1320964;
	v2 = 0;
	v12 = 0;
	if (dword_5d4594_1320964) {
		v3 = getMemAt(0x5D4594, 1319284);
		while (2) {
			v4 = 0;
			v5 = (int)v3;
			do {
				if (sub_4C1760(v5, *(unsigned __int16*)(a1 + 2))) {
					v6 = getMemAt(0x5D4594, 140 * (v2 + 2 * v4) + 1319284);
					goto LABEL_18;
				}
				++v4;
				v5 += 280;
			} while (v4 < 2);
			v3 += 140;
			++v2;
			if ((int)v3 < (int)getMemAt(0x5D4594, 1319564))
				continue;
			break;
		}
		v7 = 0;
		v8 = getMemAt(0x5D4594, 1320308);
		while (2) {
			v9 = 0;
			v10 = (int)v8;
			do {
				if (sub_4C1760(v10, *(unsigned __int16*)(a1 + 2))) {
					v12 = getMemAt(0x5D4594, 140 * (v7 + 2 * v9) + 1320308);
					goto LABEL_17;
				}
				++v9;
				v10 += 280;
			} while (v9 < 2);
			v8 += 140;
			++v7;
			if ((int)v8 < (int)getMemAt(0x5D4594, 1320588))
				continue;
			break;
		}
		v11 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 184292), 0, "C:\\NoxPost\\src\\client\\Gui\\GUITrade.c", 1141);
		sub_445490(v11);
	LABEL_17:
		v6 = v12;
	LABEL_18:
		*((_DWORD*)v6 + 34) -= *((_DWORD*)v6 + 34) / *((_DWORD*)v6 + 1);
		sub_4C1710((int)v6, *(unsigned __int16*)(a1 + 2));
		result = *((_DWORD*)v6 + 1) - 1;
		*((_DWORD*)v6 + 1) = result;
		if (!result) {
			result = sub_45A4B0(*(_QWORD**)v6);
			*(_DWORD*)v6 = 0;
		}
	}
	return result;
}
