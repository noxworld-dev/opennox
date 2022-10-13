#include "client__gui__guirank.h"
#include "client__gui__window.h"
#include "common__strman.h"

#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME2_2.h"
#include "GAME2_3.h"
#include "client__gui__gadgets__listbox.h"
#include "common__system__team.h"
#include "operators.h"

extern uint32_t dword_587000_145672;
extern uint32_t dword_5d4594_1090108;
extern uint32_t dword_5d4594_1090112;
extern uint32_t dword_587000_145668;
extern uint32_t dword_5d4594_1090040;
extern uint32_t dword_587000_145664;
extern uint32_t dword_5d4594_1090044;
extern uint32_t dword_5d4594_1090100;
extern uint32_t nox_player_netCode_85319C;
extern int dword_5d4594_3799524;
extern uint32_t dword_5d4594_1090120;
extern int nox_win_width;
extern int nox_win_height;
extern uint32_t nox_color_white_2523948;
extern uint32_t nox_color_yellow_2589772;

nox_window* dword_5d4594_1090048 = 0;

//----- (0046DC60) --------------------------------------------------------
wchar_t* sub_46DC60(int a1, unsigned char a2, int a3) {
	wchar_t* result; // eax

	if (a3) {
		return (wchar_t*)sub_46DC00(a1, a2, a3);
	}
	result = nox_strman_loadString_40F1D0("InternalError", 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1050);
	if (result) {
		result = (wchar_t*)sub_46DC00(a1, a2, (int)result);
	}
	return result;
}

//----- (0046E870) --------------------------------------------------------
int nox_xxx_guiDrawRank_46E870() {
	int v0;              // ebx
	unsigned short* v1;  // eax
	int v2;              // eax
	unsigned short* v3;  // eax
	unsigned short* v4;  // eax
	int v5;              // eax
	unsigned short* v6;  // eax
	int v7;              // eax
	unsigned short* v8;  // eax
	unsigned short* v9;  // eax
	unsigned short* v10; // eax
	unsigned short* v11; // eax
	unsigned short* v12; // eax
	int v13;             // eax
	int v14;             // ecx
	unsigned char* v15;  // eax
	int v16;             // edi
	int v17;             // esi
	int v18;             // ebp
	int v19;             // edi
	int v20;             // ebx
	uint32_t* v21;       // eax
	int v22;             // edx
	int v23;             // ecx
	uint32_t* v24;       // eax
	int v25;             // edx
	uint32_t* v26;       // eax
	int v27;             // edx
	uint32_t* v28;       // eax
	int v29;             // ecx
	int v30;             // esi
	int result;          // eax
	int v32;             // [esp-4h] [ebp-1DCh]
	int v33;             // [esp-4h] [ebp-1DCh]
	int v34;             // [esp-4h] [ebp-1DCh]
	int v35;             // [esp-4h] [ebp-1DCh]
	int v36;             // [esp-4h] [ebp-1DCh]
	int v37;             // [esp-4h] [ebp-1DCh]
	int v38;             // [esp-4h] [ebp-1DCh]
	int v39;             // [esp-4h] [ebp-1DCh]
	int v40;             // [esp-4h] [ebp-1DCh]
	int v41;             // [esp+10h] [ebp-1C8h]
	int v42;             // [esp+14h] [ebp-1C4h]
	int v43;             // [esp+18h] [ebp-1C0h]
	int v44;             // [esp+1Ch] [ebp-1BCh]
	int v45[3];          // [esp+20h] [ebp-1B8h]
	int v46;             // [esp+2Ch] [ebp-1ACh]
	int v47;             // [esp+30h] [ebp-1A8h]
	char v48[56];        // [esp+34h] [ebp-1A4h]
	char v49[332];       // [esp+6Ch] [ebp-16Ch]
	wchar_t v50[16];     // [esp+1B8h] [ebp-20h]

	dword_587000_145668 = 6;
	sub_46F030();
	v0 = nox_xxx_guiFontHeightMB_43F320(0);
	v46 = v0;
	*getMemU32Ptr(0x5D4594, 1084036) = 80;
	if (nox_xxx_check_flag_aaa_43AF70() == 1) {
		nox_swprintf(v50, L"%S", getMemAt(0x587000, 145768));
		nox_xxx_drawGetStringSize_43F840(0, v50, &v41, &v44, nox_win_width);
	} else {
		v32 = nox_win_width;
		v1 = nox_strman_loadString_40F1D0("Flag", 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1641);
		nox_xxx_drawGetStringSize_43F840(0, v1, &v41, &v44, v32);
	}
	v2 = v41;
	if (v41 < 18) {
		v2 = 18;
		v41 = 18;
	}
	*getMemU32Ptr(0x5D4594, 1084040) = v2 + 14;
	v33 = nox_win_width;
	v3 = nox_strman_loadString_40F1D0("Score", 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1649);
	nox_xxx_drawGetStringSize_43F840(0, v3, &v41, &v44, v33);
	v34 = nox_win_width;
	v4 = nox_strman_loadString_40F1D0("HealthHeading", 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1650);
	nox_xxx_drawGetStringSize_43F840(0, v4, &v42, &v43, v34);
	v5 = v41;
	if (v42 > v41) {
		v5 = v42;
		v41 = v42;
	}
	*getMemU32Ptr(0x5D4594, 1084048) = v5 + 7;
	v35 = nox_win_width;
	v6 = nox_strman_loadString_40F1D0("Ping", 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1657);
	nox_xxx_drawGetStringSize_43F840(0, v6, &v41, &v44, v35);
	nox_xxx_drawGetStringSize_43F840(0, getMemU16Ptr(0x587000, 145972), &v42, &v43, nox_win_width);
	v7 = v41;
	if (v42 > v41) {
		v7 = v42;
		v41 = v42;
	}
	*getMemU32Ptr(0x5D4594, 1084052) = v7 + 7;
	v36 = nox_win_width;
	v8 = nox_strman_loadString_40F1D0("Class", 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1667);
	nox_xxx_drawGetStringSize_43F840(0, v8, &v41, &v44, v36);
	v37 = nox_win_width;
	v9 = nox_strman_loadString_40F1D0("Warrior", 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1668);
	nox_xxx_drawGetStringSize_43F840(0, v9, &v42, &v43, v37);
	if (v42 > v41) {
		v41 = v42;
	}
	v38 = nox_win_width;
	v10 = nox_strman_loadString_40F1D0("Wizard", 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1671);
	nox_xxx_drawGetStringSize_43F840(0, v10, &v42, &v43, v38);
	if (v42 > v41) {
		v41 = v42;
	}
	v39 = nox_win_width;
	v11 = nox_strman_loadString_40F1D0("Conjurer", 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1674);
	nox_xxx_drawGetStringSize_43F840(0, v11, &v42, &v43, v39);
	if (v42 > v41) {
		v41 = v42;
	}
	v40 = nox_win_width;
	v12 = nox_strman_loadString_40F1D0("LivesHeading", 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1677);
	nox_xxx_drawGetStringSize_43F840(0, v12, &v42, &v43, v40);
	v13 = v41;
	if (v42 > v41) {
		v13 = v42;
		v41 = v42;
	}
	v14 = 0;
	*getMemU32Ptr(0x5D4594, 1084044) = v13 + 7;
	v15 = getMemAt(0x5D4594, 1084036);
	do {
		v16 = *(uint32_t*)v15;
		v15 += 4;
		v14 += v16;
	} while ((int)v15 < (int)getMemAt(0x5D4594, 1084056));
	dword_5d4594_1090040 = v14;
	dword_5d4594_1090044 = 439 - v0;
	dword_5d4594_1090048 = nox_window_new(0, 1560, 0, v0 + 40, 1, 1, 0);
	nox_window_set_all_funcs(*(uint32_t**)&dword_5d4594_1090048, sub_46F060, sub_46F080, 0);
	*(uint32_t*)((uint32_t)dword_5d4594_1090048 + 56) = 0x80000000;
	*(uint32_t*)((uint32_t)dword_5d4594_1090048 + 64) = 0x80000000;
	*(uint32_t*)((uint32_t)dword_5d4594_1090048 + 72) = 0x80000000;
	*(uint32_t*)((uint32_t)dword_5d4594_1090048 + 80) = 0x80000000;
	*(uint32_t*)((uint32_t)dword_5d4594_1090048 + 88) = 0x80000000;
	memset(v49, 0, sizeof(v49));
	nox_wcscpy((wchar_t*)&v49[72], (const wchar_t*)getMemAt(0x5D4594, 1090136));
	*(uint32_t*)&v49[68] = *getMemU32Ptr(0x85B3FC, 940);
	*(uint32_t*)&v49[20] = 0x80000000;
	memset(v48, 0, sizeof(v48));
	*(uint16_t*)&v48[6] = 0;
	*(uint32_t*)&v48[12] = 0;
	*(uint32_t*)&v48[16] = 0;
	*(uint32_t*)&v49[28] = 0x80000000;
	*(uint32_t*)&v49[36] = 0x80000000;
	*(uint32_t*)&v49[44] = 0x80000000;
	*(uint32_t*)&v49[52] = 0x80000000;
	v17 = 0;
	v47 = 3 * v0;
	v18 = 3 * v0 + 1;
	*(uint32_t*)&v49[8] = 32;
	*(uint32_t*)&v48[2] = (unsigned short)(v0 + 1);
	strcpy(v48, "@");
	*(uint32_t*)&v48[8] = 1;
	v19 = 2 * (v0 + 1);
	v20 = 2 * v0;
	do {
		v21 = nox_gui_newScrollListBox_4A4310(*(int*)&dword_5d4594_1090048, 1088, v17 * dword_5d4594_1090040, v18,
											  *(int*)&dword_5d4594_1090040, dword_5d4594_1090044 - v19, (int)v49,
											  (short*)v48);
		v22 = *getMemU32Ptr(0x5D4594, 1084036);
		v23 = dword_5d4594_1090044 - v19;
		*getMemU32Ptr(0x5D4594, 1090052 + 4 * v17) = v21;
		v24 = nox_gui_newScrollListBox_4A4310((int)v21, 1088, 0, v20, v22, v23, (int)v49, (short*)v48);
		v25 = dword_5d4594_1090044;
		*getMemU32Ptr(0x5D4594, 1090060 + 4 * v17) = v24;
		v26 = nox_gui_newScrollListBox_4A4310(*getMemU32Ptr(0x5D4594, 1090052 + 4 * v17), 1088,
											  *getMemIntPtr(0x5D4594, 1084036), v20, *getMemIntPtr(0x5D4594, 1084040),
											  v25 - v19, (int)v49, (short*)v48);
		v27 = dword_5d4594_1090044;
		*getMemU32Ptr(0x5D4594, 1090068 + 4 * v17) = v26;
		*getMemU32Ptr(0x5D4594, 1090076 + 4 * v17) =
			nox_gui_newScrollListBox_4A4310(*getMemU32Ptr(0x5D4594, 1090052 + 4 * v17), 1088,
											*getMemU32Ptr(0x5D4594, 1084036) + *getMemU32Ptr(0x5D4594, 1084040), v20,
											*getMemIntPtr(0x5D4594, 1084044), v27 - v19, (int)v49, (short*)v48);
		v28 = nox_gui_newScrollListBox_4A4310(
			*getMemU32Ptr(0x5D4594, 1090052 + 4 * v17), 1088,
			*getMemU32Ptr(0x5D4594, 1084036) + *getMemU32Ptr(0x5D4594, 1084040) + *getMemU32Ptr(0x5D4594, 1084044), v20,
			*getMemIntPtr(0x5D4594, 1084048), dword_5d4594_1090044 - v19, (int)v49, (short*)v48);
		v29 = dword_5d4594_1090044;
		*getMemU32Ptr(0x5D4594, 1090084 + 4 * v17) = v28;
		*getMemU32Ptr(0x5D4594, 1090092 + 4 * v17) =
			nox_gui_newScrollListBox_4A4310(*getMemU32Ptr(0x5D4594, 1090052 + 4 * v17), 1088,
											*getMemU32Ptr(0x5D4594, 1084036) + *getMemU32Ptr(0x5D4594, 1084040) +
												*getMemU32Ptr(0x5D4594, 1084048) + *getMemU32Ptr(0x5D4594, 1084044),
											v20, *getMemIntPtr(0x5D4594, 1084052), v29 - v19, (int)v49, (short*)v48);
		nox_xxx_wndSetProc_46B2C0(*getMemU32Ptr(0x5D4594, 1090052 + 4 * v17), nox_xxx_Proc_46F070);
		sub_46B120(*(uint32_t**)getMemAt(0x5D4594, 1090060 + 4 * v17), *getMemU32Ptr(0x5D4594, 1090052 + 4 * v17));
		sub_46B120(*(uint32_t**)getMemAt(0x5D4594, 1090068 + 4 * v17), *getMemU32Ptr(0x5D4594, 1090052 + 4 * v17));
		sub_46B120(*(uint32_t**)getMemAt(0x5D4594, 1090076 + 4 * v17), *getMemU32Ptr(0x5D4594, 1090052 + 4 * v17));
		sub_46B120(*(uint32_t**)getMemAt(0x5D4594, 1090084 + 4 * v17), *getMemU32Ptr(0x5D4594, 1090052 + 4 * v17));
		sub_46B120(*(uint32_t**)getMemAt(0x5D4594, 1090092 + 4 * v17), *getMemU32Ptr(0x5D4594, 1090052 + 4 * v17));
		++v17;
	} while (v17 < 2);
	*(uint32_t*)&v49[8] = 2048;
	*(uint32_t*)&v49[68] = nox_color_yellow_2589772;
	v45[0] = nox_strman_loadString_40F1D0("yourrank", 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1772);
	v30 = v46 + 1;
	v45[1] = 0;
	v45[2] = 0;
	dword_5d4594_1090100 = nox_gui_newStaticText_489300(*(int*)&dword_5d4594_1090048, 1088, 0, v46,
														*(int*)&dword_5d4594_1090040, v46 + 1, v49, v45);
	*(uint32_t*)&v49[68] = nox_color_white_2523948;
	v45[0] = nox_strman_loadString_40F1D0("WindowDir:Empty", 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1782);
	dword_5d4594_1090112 = nox_gui_newStaticText_489300(*(int*)&dword_5d4594_1090048, 1088, 0, v20,
														*(int*)&dword_5d4594_1090040, v30, v49, v45);
	*(uint32_t*)&v49[68] = *getMemU32Ptr(0x85B3FC, 940);
	v45[0] = nox_strman_loadString_40F1D0("WindowDir:Empty", 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1790);
	dword_5d4594_1090108 = nox_gui_newStaticText_489300(*(int*)&dword_5d4594_1090048, 1088, 0, v47,
														*(int*)&dword_5d4594_1090040, v30, v49, v45);
	*(uint32_t*)&v49[68] = *getMemU32Ptr(0x8531A0, 2572);
	v45[0] = nox_strman_loadString_40F1D0("TeamPlayerRank", 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1798);
	*getMemU32Ptr(0x5D4594, 1090104) = nox_gui_newStaticText_489300(*(int*)&dword_5d4594_1090048, 1088, 0, 0,
																	*(int*)&dword_5d4594_1090040, v30, v49, v45);
	result = dword_5d4594_1090048;
	dword_587000_145664 = 1;
	return result;
}

//----- (0046F030) --------------------------------------------------------
wchar_t* sub_46F030() {
	int i;           // esi
	wchar_t* result; // eax

	for (i = 0; i < 12; i += 4) {
		result = nox_strman_loadString_40F1D0(*(char**)getMemAt(0x587000, 145676 + i), 0,
											  "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 167);
		*getMemU32Ptr(0x5D4594, 1084056 + i) = result;
	}
	return result;
}

//----- (0046F080) --------------------------------------------------------
int sub_46F080(int a1, int a2) {
	char* v2;          // ebp
	char* v4;          // esi
	short v5;          // ax
	int v6;            // eax
	uint32_t* v7;      // eax
	int v8;            // eax
	int v9;            // eax
	wchar_t* v10;      // eax
	wchar_t* v11;      // eax
	unsigned char v12; // bl
	unsigned char v13; // di
	int v14;           // esi
	int v15;           // ebp
	int v16;           // edi
	int v17;           // esi
	int v18;           // eax
	unsigned char v19; // al
	char* v20;         // eax
	wchar_t* v21;      // eax
	wchar_t* v22;      // edi
	wchar_t* v23;      // eax
	wchar_t* v24;      // eax
	int v25;           // esi
	wchar_t* v26;      // eax
	int v27;           // [esp-14h] [ebp-38h]
	int v28;           // [esp-10h] [ebp-34h]
	int v29;           // [esp-10h] [ebp-34h]
	int v30;           // [esp-10h] [ebp-34h]
	unsigned char v31; // [esp+4h] [ebp-20h]
	unsigned char v32; // [esp+4h] [ebp-20h]
	int v33;           // [esp+8h] [ebp-1Ch]
	int v34;           // [esp+Ch] [ebp-18h]
	char* v35;         // [esp+10h] [ebp-14h]
	int v36;           // [esp+14h] [ebp-10h]
	int v37;           // [esp+18h] [ebp-Ch]
	int xLeft;         // [esp+1Ch] [ebp-8h]
	int yTop;          // [esp+20h] [ebp-4h]
	unsigned char v40; // [esp+28h] [ebp+4h]

	v2 = 0;
	v35 = 0;
	if (!nox_common_gameFlags_check_40A5C0(8) && dword_587000_145668 != 6) {
		dword_5d4594_1090120 = dword_587000_145668 - 1;
		if (*(int*)&dword_587000_145668 - 1 < 0) {
			dword_5d4594_1090120 = 5;
		}
		sub_4703F0();
		dword_587000_145668 = 6;
		if (!dword_5d4594_1090120) {
			return 1;
		}
	}
	nox_client_wndGetPosition_46AA60((uint32_t*)a1, &xLeft, &yTop);
	v4 = nox_xxx_cliGamedataGet_416590(0);
	if (nox_common_gameFlags_check_40A5C0(1)) {
		v5 = nox_common_gameFlags_getVal_40A5B0();
		v6 = (unsigned short)nox_xxx_servGamedataGet_40A020(v5);
	} else {
		v6 = *((unsigned short*)v4 + 27);
	}
	v34 = v6;
	if ((signed char)*(uint8_t*)(a1 + 4) >= 0) {
		if (*(uint32_t*)(a2 + 20) != 0x80000000) {
			nox_client_drawRectFilledAlpha_49CF10(xLeft, yTop, *(uint32_t*)(a1 + 8), *(uint32_t*)(a1 + 12));
		}
	} else {
		nox_client_drawImageAt_47D2C0(*(uint32_t*)(a2 + 24), xLeft, yTop);
	}
	if (dword_587000_145664 || gameFrame() > (unsigned int)(*getMemU32Ptr(0x5D4594, 1090124) + gameFPS())) {
		dword_5d4594_3799524 = 1;
		*getMemU32Ptr(0x5D4594, 1090124) = gameFrame();
		dword_587000_145672 = -1;
		v33 = 0;
		sub_46DB80();
		sub_46DCC0();
		dword_587000_145664 = 0;
		v7 = nox_xxx_objGetTeamByNetCode_418C80(nox_player_netCode_85319C);
		if (v7) {
			v2 = nox_xxx_clientGetTeamColor_418AB0(*((unsigned char*)v7 + 4));
			v35 = v2;
		}
		if (*getMemU32Ptr(0x8531A0, 2576)) {
			v8 = *(uint32_t*)(*getMemU32Ptr(0x8531A0, 2576) + 3680);
			if (!(v8 & 1) || v8 & 0x20) {
				v33 = 1;
			}
		}
		v9 = dword_5d4594_1090120;
		if (getMemByte(0x5D4594, 1090116) && (dword_5d4594_1090120 == 2 || dword_5d4594_1090120 == 3)) {
			v10 = nox_strman_loadString_40F1D0("team", 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1338);
			sub_46DC60(*getMemIntPtr(0x5D4594, 1090060), 9u, (int)v10);
			sub_46DC60(*getMemIntPtr(0x5D4594, 1090068), 9u, (int)getMemAt(0x587000, 146512));
			sub_46DC60(*getMemIntPtr(0x5D4594, 1090076), 9u, (int)getMemAt(0x587000, 146516));
			v11 = nox_strman_loadString_40F1D0("score", 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1341);
			sub_46DC60(*getMemIntPtr(0x5D4594, 1090084), 9u, (int)v11);
			sub_46DC60(*getMemIntPtr(0x5D4594, 1090092), 9u, (int)getMemAt(0x587000, 146564));
			v12 = 0;
			v31 = 0;
			if (getMemByte(0x5D4594, 1090116)) {
				do {
					v13 = sub_46FEB0(v31);
					v14 = 56 * v31;
					sub_46DC30(*getMemIntPtr(0x5D4594, 1090060), v13, (wchar_t*)getMemAt(0x587000, 146568),
							   getMemAt(0x5D4594, 1087204 + v14));
					sub_46DC30(*getMemIntPtr(0x5D4594, 1090068), v13, (wchar_t*)getMemAt(0x587000, 146576));
					sub_46DC30(*getMemIntPtr(0x5D4594, 1090076), v13, (wchar_t*)getMemAt(0x587000, 146580));
					sub_46DC30(*getMemIntPtr(0x5D4594, 1090084), v13, (wchar_t*)getMemAt(0x587000, 146584),
							   *getMemU32Ptr(0x5D4594, 1087252 + v14));
					sub_46DC30(*getMemIntPtr(0x5D4594, 1090092), v13, (wchar_t*)getMemAt(0x587000, 146592));
					v31 = ++v12;
				} while (v12 < getMemByte(0x5D4594, 1090116));
			} else {
				v13 = a1;
			}
			sub_46DC30(*getMemIntPtr(0x5D4594, 1090060), v13, (wchar_t*)getMemAt(0x587000, 146596));
			sub_46DC30(*getMemIntPtr(0x5D4594, 1090068), v13, (wchar_t*)getMemAt(0x587000, 146600));
			sub_46DC30(*getMemIntPtr(0x5D4594, 1090076), v13, (wchar_t*)getMemAt(0x587000, 146604));
			sub_46DC30(*getMemIntPtr(0x5D4594, 1090084), v13, (wchar_t*)getMemAt(0x587000, 146608));
			sub_46DC30(*getMemIntPtr(0x5D4594, 1090092), v13, (wchar_t*)getMemAt(0x587000, 146612));
			v9 = dword_5d4594_1090120;
		}
		v36 = *(short*)(*(uint32_t*)(*getMemU32Ptr(0x5D4594, 1090060) + 32) + 46);
		if (getMemByte(0x5D4594, 1090117) && (v9 == 2 || v9 == 4 || v9 == 5)) {
			sub_46F8F0(0, 0);
			v9 = dword_5d4594_1090120;
			if (dword_5d4594_1090120 == 4) {
				if (getMemByte(0x5D4594, 1090117) <= 3u) {
					LOBYTE(a2) = getMemByte(0x5D4594, 1090117);
				} else {
					LOBYTE(a2) = 3;
				}
			} else {
				LOBYTE(a2) = getMemByte(0x5D4594, 1090117);
			}
			v32 = 0;
			if ((uint8_t)a2) {
				do {
					v15 = 0;
					v16 = v32 >> 4;
					if (v32 == 16) {
						sub_46F8F0(1, v36);
					}
					if (nox_common_gameFlags_check_40A5C0(1024) && v34 > 0 &&
						*getMemIntPtr(0x5D4594, 1084196 + 80 * v32) >= v34) {
						v15 = 1;
					}
					v17 = 80 * v32;
					v18 = *getMemU32Ptr(0x5D4594, 1084208 + v17);
					if (!(v18 & 1) || v18 & 0x20 || v15) {
						if (*getMemIntPtr(0x5D4594, 1084184 + 80 * v32) == -1) {
							v40 = 3;
							if (v18 & 0x20 || v15) {
								v40 = 2;
							}
						} else {
							v19 = sub_46FE60(*getMemU32Ptr(0x5D4594, 1084184 + 80 * v32));
							v40 = sub_46FEB0(v19);
							if (getMemByte(0x5D4594, 1084208 + 80 * v32) & 0x20 || v15) {
								v40 -= 2;
							}
						}
					} else {
						v40 = 9;
					}
					if (*getMemU32Ptr(0x5D4594, 1084192 + 80 * v32) == nox_player_netCode_85319C) {
						dword_587000_145672 =
							*(short*)(*(uint32_t*)(*getMemU32Ptr(0x5D4594, 1090060 + 4 * v16) + 32) + 46);
						*getMemU32Ptr(0x5D4594, 1088996) = v32 >> 4;
					}
					sub_46DC30(*getMemU32Ptr(0x5D4594, 1090060 + 4 * v16), v40, (wchar_t*)getMemAt(0x587000, 146616),
							   getMemAt(0x5D4594, 1084132 + v17));
					sub_46DC30(*getMemU32Ptr(0x5D4594, 1090076 + 4 * v16), v40, (wchar_t*)getMemAt(0x587000, 146624),
							   *getMemU32Ptr(0x5D4594, 1084056 + 4 * getMemByte(0x5D4594, 1084188 + 80 * v32)));
					if (dword_5d4594_1090120 != 5 || *getMemU32Ptr(0x5D4594, 1084196 + 80 * v32) > 0) {
						sub_46DC30(*getMemU32Ptr(0x5D4594, 1090084 + 4 * v16), v40,
								   (wchar_t*)getMemAt(0x587000, 146632), *getMemU32Ptr(0x5D4594, 1084196 + 80 * v32));
					} else {
						sub_46DC30(*getMemU32Ptr(0x5D4594, 1090084 + 4 * v16), v40,
								   (wchar_t*)getMemAt(0x587000, 146640));
					}
					sub_46DC30(*getMemU32Ptr(0x5D4594, 1090092 + 4 * v16), v40, (wchar_t*)getMemAt(0x587000, 146648),
							   *getMemU32Ptr(0x5D4594, 1084200 + 80 * v32));
					if (dword_5d4594_1090120 == 5) {
						v20 = nox_common_playerInfoGetByID_417040(*getMemU32Ptr(0x5D4594, 1084192 + 80 * v32));
						if (v20) {
							sub_46DC30(*getMemU32Ptr(0x5D4594, 1090068 + 4 * v16), v40,
									   (wchar_t*)getMemAt(0x587000, 146656), v20 + 2096);
						}
					} else {
						v21 = sub_46FB50(*getMemU32Ptr(0x5D4594, 1084204 + 80 * v32), &v37);
						sub_46DC60(*getMemU32Ptr(0x5D4594, 1090068 + 4 * v16), v37, (int)v21);
					}
					++v32;
				} while (v32 < (unsigned char)a2);
				v9 = dword_5d4594_1090120;
				v2 = v35;
			}
		} else if (v9 == 1) {
			sub_46FFD0();
			v9 = dword_5d4594_1090120;
		}
		switch (v9) {
		case 1:
		case 2:
		case 4:
		case 5:
			switch (v9) {
			case 2:
				v22 =
					nox_strman_loadString_40F1D0("TeamPlayerRank", 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1475);
				break;
			case 4:
				v22 = nox_strman_loadString_40F1D0("Top3", 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1479);
				break;
			case 5:
				v22 = nox_strman_loadString_40F1D0("WolRank", 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1483);
				break;
			case 1:
				v22 = nox_strman_loadString_40F1D0("Noxworld.c:Quest", 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c",
												   1487);
				break;
			default:
				v22 = (wchar_t*)a2;
				break;
			}
			if (!nox_common_gameFlags_check_40A5C0(1) ||
				!nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
				if (dword_5d4594_1090120 == 1) {
					// quest on-screen stats
					v28 = nox_gui_getQuestStage_450B10();
					v23 = nox_strman_loadString_40F1D0("Noxworld.c:Stage", 0,
													   "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1499);
					nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1086692), L"%s %d", v23, v28);
				} else {
					v29 = getMemByte(0x5D4594, 1090118);
					v27 = (unsigned char)sub_46FEE0();
					v24 = nox_strman_loadString_40F1D0("yourrank", 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1501);
					nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1086692), L"%s %d / %d", v24, v27, v29);
				}
			}
			break;
		case 3:
			if (v2) {
				v33 = 1;
				v25 = (unsigned char)sub_46FF70(*((uint32_t*)v2 + 13));
			} else {
				v25 = 0;
			}
			v22 = nox_strman_loadString_40F1D0("Teams", 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1519);
			if (!nox_common_gameFlags_check_40A5C0(1) ||
				!nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
				v30 = getMemByte(0x5D4594, 1090116);
				v26 = nox_strman_loadString_40F1D0("yourteamrank", 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 1525);
				nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1086692), L"%s %d / %d", v26, v25, v30);
			}
			break;
		default:
			v22 = (wchar_t*)a2;
			break;
		}
		if (v33) {
			if (wndIsShown_nox_xxx_wndIsShown_46ACC0(*(int*)&dword_5d4594_1090100)) {
				nox_window_set_hidden(*(int*)&dword_5d4594_1090100, 0);
			}
			nox_window_call_field_94(*(int*)&dword_5d4594_1090100, 16385, (int)getMemAt(0x5D4594, 1086692), 0);
		} else if (!wndIsShown_nox_xxx_wndIsShown_46ACC0(*(int*)&dword_5d4594_1090100)) {
			nox_window_set_hidden(*(int*)&dword_5d4594_1090100, 1);
		}
		nox_window_call_field_94(*getMemIntPtr(0x5D4594, 1090104), 16385, (int)v22, 0);
		sub_46FC50();
		sub_46FD80();
	}
	if ((int)dword_587000_145672 >= 0) {
		sub_46FAE0();
	}
	return 1;
}

//----- (0046F8F0) --------------------------------------------------------
wchar_t* sub_46F8F0(int a1, int a2) {
	int v2;      // edi
	wchar_t* v3; // eax
	wchar_t* v4; // eax
	wchar_t* v6; // [esp-14h] [ebp-1Ch]
	wchar_t* v7; // [esp-14h] [ebp-1Ch]
	wchar_t* v8; // [esp-14h] [ebp-1Ch]

	v2 = a2;
	if (a2 > 0) {
		do {
			sub_46DC60(*getMemU32Ptr(0x5D4594, 1090060 + 4 * a1), 9u, (int)getMemAt(0x587000, 147124));
			sub_46DC60(*getMemU32Ptr(0x5D4594, 1090068 + 4 * a1), 9u, (int)getMemAt(0x587000, 147128));
			sub_46DC60(*getMemU32Ptr(0x5D4594, 1090076 + 4 * a1), 9u, (int)getMemAt(0x587000, 147132));
			sub_46DC60(*getMemU32Ptr(0x5D4594, 1090084 + 4 * a1), 9u, (int)getMemAt(0x587000, 147136));
			sub_46DC60(*getMemU32Ptr(0x5D4594, 1090092 + 4 * a1), 9u, (int)getMemAt(0x587000, 147140));
			--v2;
		} while (v2);
	}
	v3 = nox_strman_loadString_40F1D0("player", 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 189);
	sub_46DC60(*getMemU32Ptr(0x5D4594, 1090060 + 4 * a1), 9u, (int)v3);
	sub_46DC60(*getMemU32Ptr(0x5D4594, 1090068 + 4 * a1), 9u, (int)getMemAt(0x587000, 147188));
	if (dword_5d4594_1090120 == 1) {
		v6 = nox_strman_loadString_40F1D0("LivesHeading", 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 193);
	} else {
		v6 = nox_strman_loadString_40F1D0("class", 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 195);
	}
	sub_46DC60(*getMemU32Ptr(0x5D4594, 1090076 + 4 * a1), 9u, (int)v6);
	if (dword_5d4594_1090120 == 5) {
		v7 = nox_strman_loadString_40F1D0("rank", 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 199);
		sub_46DC60(*getMemU32Ptr(0x5D4594, 1090084 + 4 * a1), 9u, (int)v7);
	} else {
		if (dword_5d4594_1090120 == 1) {
			v8 = nox_strman_loadString_40F1D0("HealthHeading", 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 201);
		} else {
			v8 = nox_strman_loadString_40F1D0("score", 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 203);
		}
		sub_46DC60(*getMemU32Ptr(0x5D4594, 1090084 + 4 * a1), 9u, (int)v8);
	}
	if (dword_5d4594_1090120 == 1) {
		v4 = nox_strman_loadString_40F1D0("class", 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 207);
	} else {
		v4 = nox_strman_loadString_40F1D0("ping", 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 209);
	}
	return sub_46DC60(*getMemU32Ptr(0x5D4594, 1090092 + 4 * a1), 9u, (int)v4);
}

//----- (0046FB50) --------------------------------------------------------
wchar_t* sub_46FB50(int a1, uint8_t* a2) {
	wchar_t* v2;     // eax
	wchar_t* result; // eax
	wchar_t* v4;     // eax
	wchar_t* v5;     // eax
	wchar_t* v6;     // eax

	switch (a1) {
	case 4:
		v2 = nox_strman_loadString_40F1D0("Ball", 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 244);
		nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1090024), L"<%s", v2);
		*a2 = 4;
		result = (wchar_t*)getMemAt(0x5D4594, 1090024);
		break;
	case 1:
		v4 = nox_strman_loadString_40F1D0("King", 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 250);
		nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1090024), L"<%s", v4);
		result = (wchar_t*)getMemAt(0x5D4594, 1090024);
		*a2 = 4;
		break;
	case 2:
		v5 = nox_strman_loadString_40F1D0("Flag", 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 256);
		nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1090024), L"<%s", v5);
		result = (wchar_t*)getMemAt(0x5D4594, 1090024);
		*a2 = 7;
		break;
	case 3:
		v6 = nox_strman_loadString_40F1D0("Flag", 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 262);
		nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1090024), L"<%s", v6);
		*a2 = 13;
		result = (wchar_t*)getMemAt(0x5D4594, 1090024);
		break;
	default:
		result = (wchar_t*)getMemAt(0x587000, 147724);
		*a2 = 4;
		break;
	}
	return result;
}

//----- (0046FC50) --------------------------------------------------------
char sub_46FC50() {
	short v0;    // ax
	short v1;    // ax
	int v2;      // eax
	int v3;      // eax
	wchar_t* v4; // eax
	int v6;      // [esp-Ch] [ebp-Ch]
	int v7;      // [esp-8h] [ebp-8h]

	if (sub_40A220() && (!nox_common_gameFlags_check_40A5C0(1) || sub_40A300() ||
						 (v0 = nox_common_gameFlags_getVal_40A5B0(), sub_40A180(v0)))) {
		if (!nox_common_gameFlags_check_40A5C0(1) || sub_40A300() ||
			(v1 = nox_common_gameFlags_getVal_40A5B0(), LOBYTE(v2) = sub_40A180(v1), (uint8_t)v2)) {
			if (wndIsShown_nox_xxx_wndIsShown_46ACC0(*(int*)&dword_5d4594_1090108)) {
				nox_window_set_hidden(*(int*)&dword_5d4594_1090108, 0);
			}
			v3 = sub_40A230();
			v7 = v3 % 60000 / 1000;
			v6 = v3 / 60000;
			v4 = nox_strman_loadString_40F1D0("TimeRemaining", 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 352);
			nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1084068), v4, v6, v7);
			LOBYTE(v2) =
				nox_window_call_field_94(*(int*)&dword_5d4594_1090108, 16385, (int)getMemAt(0x5D4594, 1084068), 0);
		}
	} else {
		v2 = wndIsShown_nox_xxx_wndIsShown_46ACC0(*(int*)&dword_5d4594_1090108);
		if (!v2) {
			LOBYTE(v2) = nox_window_set_hidden(*(int*)&dword_5d4594_1090108, 1);
		}
	}
	return v2;
}

//----- (0046FD80) --------------------------------------------------------
int sub_46FD80() {
	int result;  // eax
	short v1;    // ax
	int v2;      // eax
	wchar_t* v3; // eax
	int v4;      // [esp-4h] [ebp-4h]

	if (nox_common_gameFlags_check_40A5C0(4224)) {
		result = wndIsShown_nox_xxx_wndIsShown_46ACC0(*(int*)&dword_5d4594_1090112);
		if (!result) {
			result = nox_window_set_hidden(*(int*)&dword_5d4594_1090112, 1);
		}
	} else {
		if (wndIsShown_nox_xxx_wndIsShown_46ACC0(*(int*)&dword_5d4594_1090112)) {
			nox_window_set_hidden(*(int*)&dword_5d4594_1090112, 0);
		}
		if (nox_common_gameFlags_check_40A5C0(1)) {
			v1 = nox_common_gameFlags_getVal_40A5B0();
			v2 = (unsigned short)nox_xxx_servGamedataGet_40A020(v1);
		} else {
			v2 = *((unsigned short*)nox_xxx_cliGamedataGet_416590(0) + 27);
		}
		v4 = v2;
		v3 = nox_strman_loadString_40F1D0("LessonLimit", 0, "C:\\NoxPost\\src\\client\\Gui\\guirank.c", 390);
		nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1083972), v3, v4);
		result = nox_window_call_field_94(*(int*)&dword_5d4594_1090112, 16385, (int)getMemAt(0x5D4594, 1083972), 0);
	}
	return result;
}
