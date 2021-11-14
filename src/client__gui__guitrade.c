#include "client__gui__guitrade.h"
#include "client__gui__window.h"
#include "common__strman.h"

#include "GAME1_2.h"
#include "GAME2.h"
#include "GAME2_3.h"
#include "GAME3_1.h"
#include "client__gui__gamewin__gamewin.h"
#include "client__gui__guimsg.h"
#include "client__drawable__drawable.h"

extern uint32_t dword_5d4594_1320964;
extern uint32_t dword_5d4594_1320940;
extern int nox_win_width;
extern int nox_win_height;

//----- (004C09D0) --------------------------------------------------------
int sub_4C09D0() {
	uint32_t* v0;       // eax
	wchar_t* v2;        // eax
	wchar_t* v3;        // esi
	wchar_t* v4;        // eax
	wchar_t* v5;        // esi
	wchar_t* v6;        // eax
	uint32_t* v7;       // eax
	uint32_t* v8;       // eax
	wchar_t* v9;        // esi
	wchar_t* v10;       // eax
	wchar_t* v11;       // esi
	wchar_t* v12;       // eax
	wchar_t* v13;       // esi
	wchar_t* v14;       // eax
	unsigned char* v15; // edx
	unsigned char* v16; // eax
	int v17;            // ecx
	unsigned char* v18; // edx
	unsigned char* v19; // eax
	int v20;            // ecx
	wchar_t* v21;       // eax

	v0 = nox_new_window_from_file("Trade.wnd", sub_4C0C90);
	dword_5d4594_1320940 = v0;
	if (!v0) {
		return 0;
	}
	nox_window_set_all_funcs(v0, sub_4C0630, sub_4C0D00, 0);
	v2 = nox_strman_loadString_40F1D0("TradeMain", 0, "C:\\NoxPost\\src\\client\\Gui\\GUITrade.c", 692);
	nox_xxx_wndWddSetTooltip_46B000((wchar_t*)(dword_5d4594_1320940 + 36), v2);
	v3 = (wchar_t*)nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1320940, 3702);
	v4 = nox_strman_loadString_40F1D0("TradePlayerName", 0, "C:\\NoxPost\\src\\client\\Gui\\GUITrade.c", 695);
	nox_xxx_wndWddSetTooltip_46B000(v3 + 18, v4);
	v5 = (wchar_t*)nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1320940, 3703);
	v6 = nox_strman_loadString_40F1D0("TradeVendorName", 0, "C:\\NoxPost\\src\\client\\Gui\\GUITrade.c", 698);
	nox_xxx_wndWddSetTooltip_46B000(v5 + 18, v6);
	v7 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1320940, 3704);
	nox_gui_winSetFunc96_46B070((int)v7, sub_4C1120);
	v8 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1320940, 3705);
	nox_gui_winSetFunc96_46B070((int)v8, sub_4C1120);
	v9 = (wchar_t*)nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1320940, 3708);
	v10 = nox_strman_loadString_40F1D0("TradePlayerAccept", 0, "C:\\NoxPost\\src\\client\\Gui\\GUITrade.c", 709);
	nox_xxx_wndWddSetTooltip_46B000(v9 + 18, v10);
	v11 = (wchar_t*)nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1320940, 3709);
	v12 = nox_strman_loadString_40F1D0("TradeVendorAccept", 0, "C:\\NoxPost\\src\\client\\Gui\\GUITrade.c", 712);
	nox_xxx_wndWddSetTooltip_46B000(v11 + 18, v12);
	v13 = (wchar_t*)nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1320940, 3710);
	v14 = nox_strman_loadString_40F1D0("TradeCancel", 0, "C:\\NoxPost\\src\\client\\Gui\\GUITrade.c", 715);
	nox_xxx_wndWddSetTooltip_46B000(v13 + 18, v14);
	nox_window_set_hidden(*(int*)&dword_5d4594_1320940, 1);
	nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1320940, 0);
	v15 = getMemAt(0x5D4594, 1319288);
	do {
		v16 = v15;
		v17 = 2;
		do {
			*((uint32_t*)v16 - 1) = 0;
			*(uint32_t*)v16 = 0;
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
			*((uint32_t*)v19 - 1) = 0;
			*(uint32_t*)v19 = 0;
			v19 += 280;
			--v20;
		} while (v20);
		v18 += 140;
	} while ((int)v18 < (int)getMemAt(0x5D4594, 1320592));
	v21 = nox_strman_loadString_40F1D0("TotalValueLabel", 0, "C:\\NoxPost\\src\\client\\Gui\\GUITrade.c", 749);
	nox_wcscpy((wchar_t*)getMemAt(0x5D4594, 1319972), v21);
	*getMemU32Ptr(0x5D4594, 1320188) = 0;
	*getMemU32Ptr(0x5D4594, 1320192) = 0;
	*getMemU32Ptr(0x5D4594, 1320196) = nox_win_width;
	*getMemU32Ptr(0x5D4594, 1320200) = nox_win_height;
	*getMemU32Ptr(0x5D4594, 1320220) = nox_win_width;
	*getMemU32Ptr(0x5D4594, 1320224) = nox_win_height;
	*getMemU32Ptr(0x5D4594, 1320204) = 0;
	*getMemU32Ptr(0x5D4594, 1320208) = 0;
	*getMemU32Ptr(0x5D4594, 1320164) = nox_xxx_gLoadImg_42F970("TradeBase");
	*getMemU32Ptr(0x5D4594, 1320168) = nox_xxx_gLoadImg_42F970("TradeLeftAcceptPushed");
	*getMemU32Ptr(0x5D4594, 1320172) = nox_xxx_gLoadImg_42F970("TradeLeftAcceptLit");
	*getMemU32Ptr(0x5D4594, 1320176) = nox_xxx_gLoadImg_42F970("TradeRightAcceptLit");
	*getMemU32Ptr(0x5D4594, 1320180) = nox_xxx_gLoadImg_42F970("TradeCancelLit");
	*getMemU32Ptr(0x5D4594, 1320184) = nox_xxx_gLoadImg_42F970("TradeGold");
	return 1;
}

//----- (004C15D0) --------------------------------------------------------
int sub_4C15D0(int a1) {
	int result;         // eax
	int v2;             // ebp
	unsigned char* v3;  // ebx
	int v4;             // esi
	int v5;             // edi
	unsigned char* v6;  // esi
	int v7;             // ebp
	unsigned char* v8;  // ebx
	int v9;             // esi
	int v10;            // edi
	wchar_t* v11;       // eax
	unsigned char* v12; // [esp+8h] [ebp-4h]

	result = dword_5d4594_1320964;
	v2 = 0;
	v12 = 0;
	if (dword_5d4594_1320964) {
		v3 = getMemAt(0x5D4594, 1319284);
		while (2) {
			v4 = 0;
			v5 = (int)v3;
			do {
				if (sub_4C1760(v5, *(unsigned short*)(a1 + 2))) {
					v6 = getMemAt(0x5D4594, 1319284 + 140 * (v2 + 2 * v4));
					goto LABEL_18;
				}
				++v4;
				v5 += 280;
			} while (v4 < 2);
			v3 += 140;
			++v2;
			if ((int)v3 < (int)getMemAt(0x5D4594, 1319564)) {
				continue;
			}
			break;
		}
		v7 = 0;
		v8 = getMemAt(0x5D4594, 1320308);
		while (2) {
			v9 = 0;
			v10 = (int)v8;
			do {
				if (sub_4C1760(v10, *(unsigned short*)(a1 + 2))) {
					v12 = getMemAt(0x5D4594, 1320308 + 140 * (v7 + 2 * v9));
					goto LABEL_17;
				}
				++v9;
				v10 += 280;
			} while (v9 < 2);
			v8 += 140;
			++v7;
			if ((int)v8 < (int)getMemAt(0x5D4594, 1320588)) {
				continue;
			}
			break;
		}
		v11 =
			nox_strman_loadString_40F1D0("TradeGUIItemNotFound", 0, "C:\\NoxPost\\src\\client\\Gui\\GUITrade.c", 1141);
		nox_xxx_printCentered_445490(v11);
	LABEL_17:
		v6 = v12;
	LABEL_18:
		*((uint32_t*)v6 + 34) -= *((uint32_t*)v6 + 34) / *((uint32_t*)v6 + 1);
		sub_4C1710((int)v6, *(unsigned short*)(a1 + 2));
		result = *((uint32_t*)v6 + 1) - 1;
		*((uint32_t*)v6 + 1) = result;
		if (!result) {
			result = nox_xxx_spriteDelete_45A4B0(*(uint64_t**)v6);
			*(uint32_t*)v6 = 0;
		}
	}
	return result;
}
