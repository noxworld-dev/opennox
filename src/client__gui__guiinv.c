#include "client__gui__guiinv.h"
#include "client__gui__window.h"

#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME2_2.h"
#include "GAME2_3.h"
#include "GAME3_1.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME5_2.h"
#include "client__drawable__drawable.h"
#include "client__gui__guimsg.h"
#include "client__gui__tooltip.h"
#include "common__magic__speltree.h"
#include "common__object__modifier.h"
#include "common__strman.h"
#include "input_common.h"
#include "operators.h"

extern uint32_t dword_5d4594_1049844;
extern uint32_t dword_5d4594_1049808;
extern uint32_t dword_5d4594_1062484;
extern uint32_t dword_5d4594_1062556;
extern uint32_t dword_5d4594_1062564;
extern uint32_t dword_5d4594_1062560;
extern uint32_t dword_5d4594_1049804;
extern uint32_t dword_5d4594_1062496;
extern uint32_t dword_5d4594_1063120;
extern uint32_t dword_5d4594_1062488;
extern uint32_t dword_5d4594_1062516;
extern uint32_t dword_5d4594_1062476;
extern uint32_t dword_5d4594_1049856;
extern uint32_t dword_5d4594_1049800_inventory_click_row_index;
extern uint32_t dword_5d4594_1062456;
extern uint32_t dword_5d4594_1063636;
extern uint32_t dword_5d4594_1049796_inventory_click_column_index;
extern uint32_t dword_5d4594_1062512;
extern uint32_t dword_5d4594_1049864;
extern uint32_t dword_5d4594_1063116;
extern uint32_t dword_5d4594_1062480;
extern uint32_t array_5D4594_1049872[9];
extern int nox_win_width;
extern int nox_win_height;
extern unsigned int nox_gameFPS;

extern nox_inventory_cell_t nox_client_inventory_grid_1050020[NOX_INVENTORY_CELLS_MAX];

//----- (00461660) --------------------------------------------------------
int nox_xxx_spritePickup_461660(int a1, int a2, const void* a3) {
	int* v3;     // eax
	wchar_t* v4; // eax
	int v6;      // ecx
	int v7;      // edx
	int v8;      // eax
	int2 a4;     // [esp+8h] [ebp-8h]

	if (a2 != dword_5d4594_1062560 && a2 != *getMemU32Ptr(0x5D4594, 1049728) &&
		a2 != *getMemU32Ptr(0x5D4594, 1049724) && a2 != dword_5d4594_1062556 && a2 != dword_5d4594_1062564) {
		v3 = sub_461970(a1, a2);
		if (v3) {
			if (*(uint8_t*)(*v3 + 112) & 0x10) {
				sub_472310();
			}
		} else {
			if (!sub_4617C0(a1, a2, a3, &a4)) {
				v4 = nox_strman_loadString_40F1D0("InventoryFull", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 682);
				nox_xxx_printCentered_445490(v4);
				return 0;
			}
			v6 = a4.field_0;
			v7 = a4.field_4;
			if (nox_client_inventory_grid_1050020[a4.field_4 + NOX_INVENTORY_ROW_COUNT * a4.field_0].field_0->flags28 & 0x10) {
				sub_472310();
				v7 = a4.field_4;
				v6 = a4.field_0;
			}
			if (nox_client_inventory_grid_1050020[v7 + NOX_INVENTORY_ROW_COUNT * v6].field_0->flags28 & 0x3001000) {
				dword_5d4594_1062516 = 0;
				if (v7 >= 3) {
					dword_5d4594_1062516 = 10 * (5 * v7 - 10);
				}
			}
		}
		v8 = nox_get_thing(a2);
		if (v8) {
			if (*(uint32_t*)(v8 + 32) & 0x1001000) {
				sub_4673F0(a4.field_0, a4.field_4);
			}
		}
	}
	return 1;
}

//----- (004617C0) --------------------------------------------------------
int sub_4617C0(int a1, int a2, const void* a3, int2* a4) {
	unsigned short v4; // di
	unsigned short i;  // dx
	int result;        // eax
	int v7;            // ebp
	int v8;            // esi
	unsigned char* v9; // ebx
	uint32_t* v10;     // eax
	wchar_t* v11;      // eax
	int v12;           // eax
	int v13;           // eax
	int v14;           // ecx
	uint32_t* v15;     // esi

	v4 = 0;
	while (1) {
		for (i = 0; i < 4; ++i) {
			if (!nox_client_inventory_grid_1050020[v4 + NOX_INVENTORY_ROW_COUNT * i].field_140) {
				v7 = i;
				v8 = v4;
				v9 = &nox_client_inventory_grid_1050020[v4 + NOX_INVENTORY_ROW_COUNT * i];
				v10 = nox_new_drawable_for_thing(a2);
				*(uint32_t*)v9 = v10;
				if (v10) {
					v10[30] |= 0x40000000u;
					v12 = *(uint32_t*)v9;
					*((uint32_t*)v9 + 1) = a1;
					v9[140] = 1;
					if (*(uint32_t*)(v12 + 112) & 0x13001000) {
						memcpy((void*)(v12 + 432), a3, 0x14u);
						v8 = v4;
					}
					if (a4) {
						a4->field_0 = v7;
						a4->field_4 = v8;
					}
					if (sub_461930() && !dword_5d4594_1062480) {
						if ((v13 = *(uint32_t*)v9, v14 = *(uint32_t*)(*(uint32_t*)v9 + 112), v14 & 0x1000000) &&
								!(*(uint8_t*)(v13 + 116) & 2) ||
							v14 & 0x1000) {
							v15 = nox_xxx_getProjectileClassById_413250(*(uint32_t*)(v13 + 108));
							if (!v15 || (unsigned char)(1 << *(uint8_t*)(*getMemU32Ptr(0x8531A0, 2576) + 2251)) &
											*((uint8_t*)v15 + 62)) {
								nox_xxx_clientSetAltWeapon_461550((int)v9);
								*((uint32_t*)v9 + 34) = 1;
							}
						}
					}
					result = 1;
				} else {
					v11 = nox_strman_loadString_40F1D0("DrawablesExhausted", 0,
													   "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 550);
					nox_xxx_printCentered_445490(v11);
					result = 0;
				}
				return result;
			}
		}
		if (++v4 < 0x14u) {
			continue;
		}
		break;
	}
	return 0;
}

//----- (00461A30) --------------------------------------------------------
int nox_xxx_unused_461A30(int a1, int a2) {
	int v2;      // esi
	wchar_t* v4; // eax

	v2 = *(uint32_t*)(a1 + 396);
	if (a2 != 6) {
		return 0;
	}
	dword_5d4594_1049864 = 4;
	v4 = nox_strman_loadString_40F1D0("GrabInstruction", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 1220);
	nox_xxx_printCentered_445490(v4);
	nox_xxx_wndSetCaptureMain_46ADC0(v2);
	return 1;
}

//----- (00461A80) --------------------------------------------------------
void sub_461A80(int a1) {
	int v1;       // ebx
	char* v2;     // esi
	uint64_t* v3; // eax
	uint64_t* v4; // eax
	wchar_t* v5;  // eax

	v1 = 0;
	v2 = sub_461EF0(a1);
	if (v2) {
		if (*(uint8_t*)(**(uint32_t**)v2 + 112) & 0x10) {
			v1 = 1;
		}
		sub_461E60((uint64_t***)v2);
		*(uint32_t*)(*(uint32_t*)v2 + 132) = 0;
		sub_461B50();
		v3 = (uint64_t*)sub_461F90(a1);
		if (v3) {
			nox_xxx_spriteDelete_45A4B0(v3);
		}
		if (v1) {
			sub_472310();
		}
	} else {
		v4 = *(uint64_t**)getMemAt(0x5D4594, 1049848);
		if (*getMemU32Ptr(0x5D4594, 1049848) && *(uint32_t*)(*getMemU32Ptr(0x5D4594, 1049848) + 128) == a1) {
			if (*(uint8_t*)(*getMemU32Ptr(0x5D4594, 1049848) + 112) & 0x10) {
				sub_472310();
				v4 = *(uint64_t**)getMemAt(0x5D4594, 1049848);
			}
			nox_xxx_spriteDelete_45A4B0(v4);
			*getMemU32Ptr(0x5D4594, 1049848) = 0;
			dword_5d4594_1049856 = 0;
			nox_xxx_cursorResetDraggedItem_4776A0();
		} else {
			v5 = nox_strman_loadString_40F1D0("DroppedNotFound", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 1439);
			nox_xxx_printCentered_445490(v5);
		}
	}
}

//----- (00462040) --------------------------------------------------------
void sub_462040(int a1) {
	int v1;             // edi
	char* v2;           // ebp
	int v3;             // eax
	const void* v4;     // esi
	uint32_t* v5;       // eax
	uint32_t* v6;       // ebx
	wchar_t* v7;        // eax
	int v8;             // eax
	int v9;             // esi
	int v10;            // edi
	char* v11;          // eax
	unsigned char* v12; // ebp
	int v13;            // ecx
	unsigned char* v14; // eax
	short v16;          // ax
	int* v17;           // eax
	short v18;          // [esp+10h] [ebp-Ch]
	short v19;          // [esp+14h] [ebp-8h]
	int v20;            // [esp+20h] [ebp+4h]

	v1 = a1;
	v2 = sub_461EF0(a1);
	if (v2) {
		v20 = sub_4622E0(**(uint32_t**)v2);
		v3 = **(uint32_t**)v2;
	} else {
		if (!*getMemU32Ptr(0x5D4594, 1049848) || *(uint32_t*)(*getMemU32Ptr(0x5D4594, 1049848) + 128) != a1) {
			v7 = nox_strman_loadString_40F1D0("EquippedNotFound", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 1605);
			nox_xxx_printCentered_445490(v7);
			return;
		}
		v20 = sub_4622E0(*getMemIntPtr(0x5D4594, 1049848));
		v3 = *getMemU32Ptr(0x5D4594, 1049848);
	}
	v4 = (const void*)(v3 + 432);
	v19 = *(uint16_t*)(v3 + 294);
	v18 = *(uint16_t*)(v3 + 292);
	if (v20 == 9) {
		v7 = nox_strman_loadString_40F1D0("TooManyEquipped", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 1701);
		nox_xxx_printCentered_445490(v7);
		return;
	}
	v5 = nox_new_drawable_for_thing(*(uint32_t*)(v3 + 108));
	v6 = v5;
	if (!v5) {
		v7 = nox_strman_loadString_40F1D0("DrawablesExhausted", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 1619);
		nox_xxx_printCentered_445490(v7);
		return;
	}
	v8 = v5[30];
	v6[32] = v1;
	v6[30] = v8 | 0x40000000;
	memcpy(v6 + 108, v4, 0x18u);
	*((uint16_t*)v6 + 146) = v18;
	*((uint16_t*)v6 + 147) = v19;
	sub_4623E0(v6, v20);
	v9 = 0;
	if (v2) {
		*(uint32_t*)(*(uint32_t*)v2 + 132) = 1;
		if (*(uint32_t*)(*(uint32_t*)v2 + 136)) {
			nox_xxx_clientSetAltWeapon_461550(0);
			*(uint32_t*)(*(uint32_t*)v2 + 136) = 0;
		}
	}
	if (v6[28] & 0x1000000 && v6[29] & 0xC) {
		v10 = 1;
		if (dword_5d4594_1062488 && (v11 = sub_461EF0(*(int*)&dword_5d4594_1062488)) != 0) {
			*(uint32_t*)(**(uint32_t**)v11 + 128) = *(uint32_t*)(*(uint32_t*)v11 + 4);
			nox_xxx_clientEquip_4623B0(**(uint32_t**)v11);
		} else {
			v12 = nox_client_inventory_grid_1050020;
			do {
				if (!v10) {
					break;
				}
				v13 = 0;
				v14 = v12;
				while (!v14[140] || !(*(uint8_t*)(*(uint32_t*)v14 + 115) & 1) ||
					   *(uint32_t*)(*(uint32_t*)v14 + 116) != 2) {
					++v13;
					v14 += NOX_INVENTORY_ROW_COUNT * sizeof(nox_inventory_cell_t);
					if (v13 >= 4) {
						goto LABEL_26;
					}
				}
				int v15 = v9 + NOX_INVENTORY_ROW_COUNT * v13;
				nox_client_inventory_grid_1050020[v15].field_0->field_32 = nox_client_inventory_grid_1050020[v15].field_4;
				nox_xxx_clientEquip_4623B0(nox_client_inventory_grid_1050020[v15].field_0);
				v10 = 0;
			LABEL_26:
				v12 += sizeof(nox_inventory_cell_t);
				++v9;
			} while ((int)v12 < (int)&nox_client_inventory_grid_1050020[NOX_INVENTORY_ROW_COUNT - 1]);
		}
	}
	if (!v20) {
		dword_5d4594_1062488 = v6[32];
	}
	v16 = *((uint16_t*)v6 + 224);
	if (v16 >= 0) {
		sub_470D90(v16, *((short*)v6 + 225));
	}
	if (dword_5d4594_1062496) {
		v17 = (int*)sub_461EF0(*(int*)&dword_5d4594_1062496);
		if (v17) {
			*(uint32_t*)(*v17 + 136) = 1;
			nox_xxx_clientSetAltWeapon_461550(*v17);
			dword_5d4594_1062496 = 0;
		}
	}
}

//----- (00462740) --------------------------------------------------------
int sub_462740() {
	wchar_t* v0;  // eax
	uint32_t* v1; // eax

	if (wndIsShown_nox_xxx_wndIsShown_46ACC0(*(int*)&dword_5d4594_1062476)) {
		return 0;
	}
	nox_window_set_hidden(*(int*)&dword_5d4594_1062476, 1);
	dword_5d4594_1063116 = 0;
	dword_5d4594_1063120 = 0;
	v0 = nox_strman_loadString_40F1D0("thing.db:IdentifyDescription", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c",
									  2361);
	nox_wcscpy((wchar_t*)getMemAt(0x5D4594, 1063124), v0);
	v1 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1062476, 9156);
	nox_window_call_field_94((int)v1, 16399, 0, 0);
	nox_xxx_wndClearCaptureMain_46ADE0(*(int*)&dword_5d4594_1062456);
	dword_5d4594_1049864 = 0;
	nox_client_setCursorType_477610(0);
	return 1;
}

//----- (004627F0) --------------------------------------------------------
int sub_4627F0(uint32_t* a1) {
	int v2;           // ebx
	int v3;           // eax
	int result;       // eax
	wchar_t* v5;      // eax
	uint32_t* v6;     // eax
	wchar_t* v7;      // eax
	wchar_t* v8;      // eax
	uint32_t* v9;     // eax
	uint32_t* v10;    // esi
	wchar_t* v11;     // eax
	wchar_t* v12;     // eax
	wchar_t* v13;     // eax
	wchar_t* v14;     // eax
	int v15;          // eax
	int v16;          // ecx
	float* v17;       // eax
	double v18;       // st7
	int v19;          // ecx
	int v20;          // eax
	wchar_t* v21;     // eax
	wchar_t* v22;     // eax
	int v23;          // ecx
	int v24;          // eax
	int v25;          // ecx
	uint32_t* v26;    // edi
	int v27;          // eax
	double v28;       // st7
	int v29;          // eax
	double v30;       // st7
	double v31;       // st7
	double v32;       // st7
	int v33;          // eax
	wchar_t* v34;     // eax
	wchar_t* v35;     // eax
	wchar_t* v36;     // eax
	wchar_t* v37;     // eax
	wchar_t* v38;     // eax
	int v39;          // ecx
	uint32_t* v40;    // eax
	wchar_t* v41;     // eax
	wchar_t* v42;     // eax
	int v43;          // edi
	int v44;          // ecx
	wchar_t* v45;     // eax
	int v46;          // ebx
	int v47;          // ecx
	wchar_t* v48;     // eax
	int v49;          // eax
	uint32_t* v50;    // eax
	wchar_t* v51;     // [esp-Ch] [ebp-444h]
	wchar_t* v52;     // [esp-Ch] [ebp-444h]
	wchar_t* v53;     // [esp-Ch] [ebp-444h]
	wchar_t* v54;     // [esp-4h] [ebp-43Ch]
	wchar_t* v55;     // [esp-4h] [ebp-43Ch]
	int v56;          // [esp+0h] [ebp-438h]
	double v57;       // [esp+0h] [ebp-438h]
	double v58;       // [esp+0h] [ebp-438h]
	double v59;       // [esp+0h] [ebp-438h]
	double v60;       // [esp+0h] [ebp-438h]
	double v61;       // [esp+0h] [ebp-438h]
	double v62;       // [esp+0h] [ebp-438h]
	int v63;          // [esp+4h] [ebp-434h]
	int v64;          // [esp+4h] [ebp-434h]
	float v65;        // [esp+4h] [ebp-434h]
	int v66;          // [esp+4h] [ebp-434h]
	int v67;          // [esp+4h] [ebp-434h]
	float v68;        // [esp+18h] [ebp-420h]
	float v69;        // [esp+1Ch] [ebp-41Ch]
	float v70;        // [esp+20h] [ebp-418h]
	float v71;        // [esp+24h] [ebp-414h]
	float v72;        // [esp+28h] [ebp-410h]
	int v73;          // [esp+2Ch] [ebp-40Ch]
	int2 v74;         // [esp+30h] [ebp-408h]
	wchar_t v75[256]; // [esp+38h] [ebp-400h]
	wchar_t v76[256]; // [esp+238h] [ebp-200h]

	v73 = 1;
	nox_point mpos = nox_client_getMousePos_4309F0();
	nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2523948));
	v2 = 0;
#ifndef NOX_CGO
	nox_xxx_Font_43F340(0);
	nox_xxx_guiFontHeightMB_43F320(0);
#endif // NOX_CGO
	nox_client_drawSetColor_434460(*getMemIntPtr(0x85B3FC, 952));
	nox_client_drawRectFilledOpaque_49CE30(*a1 + 11, a1[1] + 15, 200, 200);
	sub_463370(*(uint32_t**)&dword_5d4594_1062456, &mpos, &v74);
	if (sub_4281F0(&v74, (int4*)getMemAt(0x587000, 136352)) || sub_4281F0(&v74, (int4*)getMemAt(0x587000, 136368))) {
		if (sub_4281F0(&v74, (int4*)getMemAt(0x587000, 136368)) && (v74.field_4 - 13) / 50 != 1) {
			nox_client_setCursorType_477610(7);
			goto LABEL_14;
		}
	} else {
		if (sub_4281F0(&v74, (int4*)getMemAt(0x587000, 136336))) {
			nox_client_setCursorType_477610(0);
			goto LABEL_14;
		}
		if (!sub_478030()) {
			nox_client_setCursorType_477610(7);
			goto LABEL_14;
		}
		if (!sub_479870() || (LOBYTE(v3) = sub_479880(&v74), !v3)) {
			nox_client_setCursorType_477610(7);
			goto LABEL_14;
		}
	}
	nox_client_setCursorType_477610(6);
LABEL_14:
	result = dword_5d4594_1063116;
	if (!dword_5d4594_1063116) {
		if (dword_5d4594_1063120) {
			dword_5d4594_1063120 = 0;
			v5 = nox_strman_loadString_40F1D0("thing.db:IdentifyDescription", 0,
											  "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2529);
			nox_wcscpy((wchar_t*)getMemAt(0x5D4594, 1063124), v5);
			v6 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1062476, 9156);
			result = nox_window_call_field_94((int)v6, 16399, 0, 0);
		}
		return result;
	}
	if (dword_5d4594_1063120 == dword_5d4594_1063116) {
		return result;
	}
	dword_5d4594_1063120 = dword_5d4594_1063116;
	v7 = nox_strman_loadString_40F1D0("IdentifyItem", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2545);
	nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1063124), L"%s ", v7);
	v8 = nox_xxx_clientAskInfoMb_4BF050(*(wchar_t**)&dword_5d4594_1063116);
	nox_wcscpy(v75, v8);
	if (!nox_wcscmp(v75, (const wchar_t*)getMemAt(0x5D4594, 1063652))) {
		dword_5d4594_1063120 = 0;
	}
	nox_wcscat((wchar_t*)getMemAt(0x5D4594, 1063124), v75);
	v9 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1062476, 9151);
	sub_46AEE0((int)v9, (int)getMemAt(0x5D4594, 1063124));
	v10 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1062476, 9156);
	nox_window_call_field_94((int)v10, 16399, 0, 0);
	if (nox_common_gameFlags_check_40A5C0(2048)) {
		if (*(uint16_t*)(dword_5d4594_1063116 + 294)) {
			sub_4633B0(*(int*)&dword_5d4594_1063116, &v71, &v68);
			v63 = (int)v68;
			v56 = (int)v71;
			v11 =
				nox_strman_loadString_40F1D0("IdentifyDurability", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2575);
			nox_swprintf(v75, v11, v56, v63);
		} else {
			v12 = nox_strman_loadString_40F1D0("IdentifyDurabilityIndestructable", 0,
											   "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2583);
			nox_wcscpy(v75, v12);
		}
	} else {
		switch (sub_57B190(*(uint16_t*)(dword_5d4594_1063116 + 292), *(uint16_t*)(dword_5d4594_1063116 + 294))) {
		case 0:
			v13 = nox_strman_loadString_40F1D0("IdentifyDurabilityNoDamage", 0,
											   "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2595);
			goto LABEL_30;
		case 1:
			v52 = nox_strman_loadString_40F1D0("IdentifyDurabilitySlight", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c",
											   2599);
			nox_swprintf(v75, v52);
			break;
		case 2:
			v53 = nox_strman_loadString_40F1D0("IdentifyDurabilityModerate", 0,
											   "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2603);
			nox_swprintf(v75, v53);
			break;
		case 3:
			v13 = nox_strman_loadString_40F1D0("IdentifyDurabilitySevere", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c",
											   2607);
		LABEL_30:
			nox_swprintf(v75, v13);
			break;
		case 4:
			v51 = nox_strman_loadString_40F1D0("IdentifyDurabilityIndestructable", 0,
											   "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2591);
			nox_swprintf(v75, v51);
			break;
		default:
			break;
		}
	}
	nox_window_call_field_94((int)v10, 16397, (int)v75, -1);
	nox_window_call_field_94((int)v10, 16397, (int)getMemAt(0x5D4594, 1063656), -1);
	v64 = *(unsigned char*)(dword_5d4594_1063116 + 298);
	v14 = nox_strman_loadString_40F1D0("IdentifyWeight", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2620);
	nox_swprintf(v75, v14, v64);
	nox_window_call_field_94((int)v10, 16397, (int)v75, -1);
	nox_window_call_field_94((int)v10, 16397, (int)getMemAt(0x5D4594, 1063660), -1);
	v15 = dword_5d4594_1063116;
	v16 = *(uint32_t*)(dword_5d4594_1063116 + 112);
	if (!(v16 & 0x2000000)) {
		if (!(v16 & 0x1001000)) {
			goto LABEL_72;
		}
		v23 = *getMemU32Ptr(0x8531A0, 2576);
		LODWORD(v68) = dword_5d4594_1063116 + 432;
		v69 = 1.0;
		v70 = *getMemFloatPtr(0x8531A0, 2576);
		if (!*getMemU32Ptr(0x5D4594, 1063644)) {
			*getMemU32Ptr(0x5D4594, 1063644) = nox_xxx_getTTByNameSpriteMB_44CFC0("ArcherArrow");
			v24 = nox_xxx_getTTByNameSpriteMB_44CFC0("ArcherBolt");
			v23 = *getMemU32Ptr(0x8531A0, 2576);
			*getMemU32Ptr(0x5D4594, 1063648) = v24;
			v15 = dword_5d4594_1063116;
		}
		if (!v23 || !(*(uint8_t*)(v15 + 116) & 2)) {
			goto LABEL_50;
		}
		v25 = *(uint32_t*)(v23 + 4);
		if (v25 & 4) {
			v26 = nox_xxx_getProjectileClassById_413250(*getMemIntPtr(0x5D4594, 1063644));
			v2 = 4;
		} else {
			if (!(v25 & 8)) {
				goto LABEL_50;
			}
			v26 = nox_xxx_getProjectileClassById_413250(*getMemIntPtr(0x5D4594, 1063648));
			v2 = 8;
		}
		if (v26) {
			goto LABEL_51;
		}
		v15 = dword_5d4594_1063116;
	LABEL_50:
		v26 = nox_xxx_getProjectileClassById_413250(*(uint32_t*)(v15 + 108));
	LABEL_51:
		v71 = sub_4626C0(*(int*)&dword_5d4594_1063116);
		v72 = sub_462700(*(int*)&dword_5d4594_1063116);
		v27 = *(uint32_t*)LODWORD(v68);
		if (*(uint32_t*)LODWORD(v68) &&
			*(float* (**)(int, int, int, int, float*))(v27 + 40) == nox_xxx_effectDamageMultiplier_4E04C0) {
			v69 = *(float*)(v27 + 44);
		}
		v28 = nox_xxx_calcBoltDamage_4EF1E0(*(uint32_t*)(LODWORD(v70) + 2239), (int)v26);
		v29 = v26[1];
		v70 = v28 * v69 + v71 + v72;
		if (v29 == *getMemU32Ptr(0x5D4594, 1063648) && nox_common_gameFlags_check_40A5C0(2048)) {
			v30 = nox_xxx_gamedataGetFloat_419D40((void*)getMemAt(0x587000, 137632));
		} else {
			LODWORD(v68) = *((unsigned short*)v26 + 36);
			v30 = (double)SLODWORD(v68);
		}
		v68 = v30 * v69;
		v31 = v70 - v68 - v72 - v71;
		v69 = v31;
		if (v31 < 0.0) {
			v32 = v70 - v69;
			v69 = 0.0;
			v70 = v32;
		}
		v33 = *(uint32_t*)(dword_5d4594_1063116 + 116);
		if (v33 & 0xC) {
			v34 =
				nox_strman_loadString_40F1D0("WeaponDamageLabelNA", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2770);
			nox_swprintf(v75, v34);
		} else if (!(v33 & 2) || v2) {
			v58 = v70;
			v55 = nox_strman_loadString_40F1D0("WeaponDamageLabel", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2776);
			nox_swprintf(v75, v55, v58);
		} else {
			v57 = v70;
			v54 = nox_strman_loadString_40F1D0("WeaponDamageLabelUnknownPlus", 0,
											   "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2773);
			nox_swprintf(v75, v54, v57);
		}
		nox_window_call_field_94((int)v10, 16397, (int)v75, -1);
		nox_wcscpy(v75, L"  ");
		v59 = v68;
		v35 = nox_strman_loadString_40F1D0("BaseDamageLabel", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2785);
		nox_swprintf(v76, v35, v59);
		nox_wcscat(v75, v76);
		nox_window_call_field_94((int)v10, 16397, (int)v75, -1);
		nox_wcscpy(v75, L"  ");
		v60 = v69;
		v36 = nox_strman_loadString_40F1D0("StrengthDamageLabel", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2792);
		nox_swprintf(v76, v36, v60);
		nox_wcscat(v75, v76);
		nox_window_call_field_94((int)v10, 16397, (int)v75, -1);
		if (v72 > 0.0) {
			nox_wcscpy(v75, L"  ");
			v61 = v72;
			v37 = nox_strman_loadString_40F1D0("FireDamageLabel", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2801);
			nox_swprintf(v76, v37, v61);
			nox_wcscat(v75, v76);
			nox_window_call_field_94((int)v10, 16397, (int)v75, -1);
		}
		if (v71 > 0.0) {
			nox_wcscpy(v75, L"  ");
			v62 = v71;
			v38 = nox_strman_loadString_40F1D0("ElectricalDamageLabel", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c",
											   2811);
			nox_swprintf(v76, v38, v62);
			nox_wcscat(v75, v76);
			nox_window_call_field_94((int)v10, 16397, (int)v75, -1);
		}
		nox_window_call_field_94((int)v10, 16397, (int)getMemAt(0x5D4594, 1063668), -1);
		goto LABEL_71;
	}
	v17 = (float*)nox_xxx_equipClothFindDefByTT_413270(*(uint32_t*)(dword_5d4594_1063116 + 108));
	v18 = 1.0;
	v19 = *(uint32_t*)(dword_5d4594_1063116 + 432);
	if (v19 && *(float* (**)(int, int, int, int, int, float*))(v19 + 76) == sub_4E0370) {
		v18 = *(float*)(v19 + 80);
	}
	v65 = v18 * v17[16] * 1000.0 + 0.5;
	v20 = nox_float2int(v65);
	if (*(uint8_t*)(dword_5d4594_1063116 + 116) & 2) {
		v21 = nox_strman_loadString_40F1D0("ArmorValueLabelNA", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2647);
		nox_swprintf(v75, v21);
	} else {
		v66 = v20;
		v22 = nox_strman_loadString_40F1D0("ArmorValueLabel", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2649);
		nox_swprintf(v75, v22, v66);
	}
	nox_window_call_field_94((int)v10, 16397, (int)v75, -1);
	nox_window_call_field_94((int)v10, 16397, (int)getMemAt(0x5D4594, 1063664), -1);
LABEL_71:
	v15 = dword_5d4594_1063116;
LABEL_72:
	v39 = *(uint32_t*)(v15 + 112);
	if (v39 & 0x13001000) {
		if (v39 & 0x11001000) {
			v40 = nox_xxx_getProjectileClassById_413250(*(uint32_t*)(v15 + 108));
		} else {
			v40 = nox_xxx_equipClothFindDefByTT_413270(*(uint32_t*)(v15 + 108));
		}
		if (v40) {
			v15 = dword_5d4594_1063116;
			v43 = dword_5d4594_1063116 + 432;
			if (*(uint32_t*)(dword_5d4594_1063116 + 112) & 0x10000000) {
				goto LABEL_91;
			}
			v44 = *(uint32_t*)(dword_5d4594_1063116 + 440);
			if (v44 && *(uint32_t*)(v44 + 16)) {
				v45 = nox_strman_loadString_40F1D0("IdentifySpecialAttributes", 0,
												   "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2851);
				nox_swprintf(v75, v45);
				nox_window_call_field_94((int)v10, 16397, (int)v75, -1);
				v46 = 0;
				nox_wcscpy(v75, L"  ");
				nox_swprintf(v76, *(const wchar_t**)(*(uint32_t*)(v43 + 8) + 16));
				nox_wcscat(v75, v76);
				nox_window_call_field_94((int)v10, 16397, (int)v75, -1);
				v15 = dword_5d4594_1063116;
			} else {
				v46 = v73;
			}
			v47 = *(uint32_t*)(v43 + 12);
			if (v47 && *(uint32_t*)(v47 + 16)) {
				if (v46 == 1) {
					v48 = nox_strman_loadString_40F1D0("IdentifySpecialAttributes", 0,
													   "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2868);
					nox_swprintf(v75, v48);
					nox_window_call_field_94((int)v10, 16397, (int)v75, -1);
					v73 = 0;
					v46 = 0;
				}
				nox_wcscpy(v75, L"  ");
				nox_swprintf(v76, *(const wchar_t**)(*(uint32_t*)(v43 + 12) + 16));
				nox_wcscat(v75, v76);
				nox_window_call_field_94((int)v10, 16397, (int)v75, -1);
				v15 = dword_5d4594_1063116;
			}
			if (v46) {
				goto LABEL_91;
			}
			nox_window_call_field_94((int)v10, 16397, (int)getMemAt(0x5D4594, 1063672), -1);
		} else {
			v41 = nox_strman_loadString_40F1D0("IdentifySpecialAttributes", 0,
											   "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2835);
			nox_swprintf(v75, v41);
			nox_window_call_field_94((int)v10, 16397, (int)v75, -1);
			v42 = nox_strman_loadString_40F1D0("IdentifyUnknown", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2837);
			nox_swprintf(v75, v42);
			nox_window_call_field_94((int)v10, 16397, (int)v75, -1);
		}
		v15 = dword_5d4594_1063116;
	}
LABEL_91:
	v49 = nox_get_thing_desc(*(uint32_t*)(v15 + 108));
	if (v49) {
		nox_window_call_field_94((int)v10, 16397, v49, -1);
	}
	v67 = nox_get_thing_pretty_image(*(uint32_t*)(dword_5d4594_1063116 + 108));
	v50 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1062476, 9155);
	return nox_xxx_wndSetIcon_46AE60((int)v50, v67);
}
//----- (00463880) --------------------------------------------------------
void nox_client_makePlayerStatsDlg_463880(int* a1) {
	wchar_t v77[256];

	int v1 = nox_xxx_guiFontHeightMB_43F320(0);
	int v2 = nox_xxx_guiFontHeightMB_43F320(dword_5d4594_1063636);
	int v68 = v1 - v2;
	float v51 = (double)(v1 - v2) * 0.5 + 0.5;
	int v3 = nox_float2int(v51);
	int v73 = v3;
	int v72 = *getMemU32Ptr(0x5D4594, 2523948);
	int v6 = a1[0];
	int v7 = a1[1];
	int v4 = *getMemU32Ptr(0x8531A0, 2576);
	if (!v4) {
		return;
	}
	sub_57B350();
	float* v70 = nox_xxx_plrGetMaxVarsPtr_57B360(*(unsigned char*)(v4 + 2251));
	float* v71 = nox_xxx_plrGetMaxVarsPtr_57B360(0);
	int v8 = v6 + 11;
	int v9 = v7 + 15;
	nox_xxx_drawSetTextColor_434390(v72);
	nox_client_drawSetColor_434460(*getMemIntPtr(0x85B3FC, 952));
	nox_client_drawRectFilledOpaque_49CE30(v8, v9, 200, 200);
	int v10 = v8 + 2;
	int v11 = v9 + 2 * v1 + 3;
	int v52 = *(char*)(v4 + 3684);
	wchar_t* v12 = nox_strman_loadString_40F1D0("StatsLevel", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 1878);
	nox_swprintf(v77, v12, v52);
	nox_xxx_drawStringWrap_43FAF0(0, v77, v10, v11, 200, 0);
	int v13 = v11 + v1 + 1;
	if (nox_common_gameFlags_check_40A5C0(2048)) {
		int v53 = (long long)nox_xxx_gamedataGetFloatTable_419D70("XPTable", *(char*)(v4 + 3684) + 1);
		int v41 = *getMemU32Ptr(0x5D4594, 1062544);
		wchar_t* v14 = nox_strman_loadString_40F1D0("StatsEXP", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 1886);
		nox_swprintf(v77, v14, v41, v53);
		nox_xxx_drawStringWrap_43FAF0(0, v77, v10, v13, 200, 0);
	}
	int v15 = 2 * v1 + 2 + v13;
	wchar_t* v16 = nox_strman_loadString_40F1D0("StatsHealth", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 1896);
	nox_xxx_drawStringWrap_43FAF0(0, v16, v10, v15, 200, 0);
	nox_client_drawSetColor_434460(*getMemIntPtr(0x5D4594, 2598268));
	nox_client_drawRectFilledOpaque_49CE30(v10 + 60, v15, 90, v1);
	float v54 = (double)(int)(90 * *(uint32_t*)(v4 + 2247)) / *v70;
	int v67 = nox_float2int(v54);
	nox_client_drawSetColor_434460(*getMemIntPtr(0x5D4594, 2589776));
	nox_client_drawRectFilledOpaque_49CE30(v10 + 60, v15, v67, v1);
	v68 = 90 * sub_470CC0();
	float v55 = (double)v68 / *v70;
	v67 = nox_float2int(v55);
	nox_client_drawSetColor_434460(*getMemIntPtr(0x85B3FC, 940));
	nox_client_drawRectFilledOpaque_49CE30(v10 + 60, v15, v67, v1);
	int v56 = nox_float2int(*v70);
	int v42 = *(uint32_t*)(v4 + 2247);
	wchar_t* v17 = nox_strman_loadString_40F1D0("MinMaxFormat", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 1914);
	nox_swprintf(v77, v17, v42, v56);
	nox_xxx_drawGetStringSize_43F840(*(int*)&dword_5d4594_1063636, v77, &v67, 0, 0);
	float v69 = 0;
	LODWORD(v69) = v15 + v73;
	nox_xxx_drawStringWrap_43FAF0(*(int*)&dword_5d4594_1063636, v77, v10 - v67 + 193, v15 + v73, 200, 0);
	int v18 = sub_470CC0();
	nox_swprintf(v77, L"%d", v18);
	nox_xxx_drawStringWrap_43FAF0(*(int*)&dword_5d4594_1063636, v77, v10 + 45, SLODWORD(v69), 200, 0);
	int v19 = v15 + v1 + 1;
	if (*(uint8_t*)(v4 + 2251)) {
		nox_client_drawSetColor_434460(*getMemIntPtr(0x85B3FC, 944));
		nox_client_drawRectFilledOpaque_49CE30(v10 + 60, v19, 90, v1);
		v68 = 90 * *(uint32_t*)(v4 + 2243);
		float v57 = (double)v68 / v70[1];
		v67 = nox_float2int(v57);
		wchar_t* v20 = nox_strman_loadString_40F1D0("StatsMana", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 1941);
		nox_xxx_drawStringWrap_43FAF0(0, v20, v10, v19, 200, 0);
		nox_client_drawSetColor_434460(*getMemIntPtr(0x85B3FC, 980));
		nox_client_drawRectFilledOpaque_49CE30(v10 + 60, v19, v67, v1);
		v68 = 90 * nox_xxx_cliGetMana_470DD0();
		float v58 = (double)v68 / v70[1];
		v67 = nox_float2int(v58);
		nox_client_drawSetColor_434460(*getMemIntPtr(0x85B3FC, 116));
		nox_client_drawRectFilledOpaque_49CE30(v10 + 60, v19, v67, v1);
		int v59 = nox_float2int(v70[1]);
		int v43 = *(uint32_t*)(v4 + 2243);
		wchar_t* v21 = nox_strman_loadString_40F1D0("MinMaxFormat", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 1952);
		nox_swprintf(v77, v21, v43, v59);
		nox_xxx_drawGetStringSize_43F840(*(int*)&dword_5d4594_1063636, v77, &v67, 0, 0);
		nox_xxx_drawStringWrap_43FAF0(*(int*)&dword_5d4594_1063636, v77, v10 - v67 + 193, v19 + v73, 200, 0);
		int v22 = nox_xxx_cliGetMana_470DD0();
		nox_swprintf(v77, L"%d", v22);
		nox_xxx_drawStringWrap_43FAF0(*(int*)&dword_5d4594_1063636, v77, v10 + 45, v19 + v73, 200, 0);
		v19 += v1 + 1;
	}
	nox_client_drawSetColor_434460(*getMemIntPtr(0x85B3FC, 956));
	nox_client_drawRectFilledOpaque_49CE30(v10 + 60, v19, 90, v1);
	v68 = 90 * *(uint32_t*)(v4 + 2239);
	float v60 = (double)v68 / v70[3];
	v67 = nox_float2int(v60);
	wchar_t* v23 = nox_strman_loadString_40F1D0("StatsStrength", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 1975);
	nox_xxx_drawStringWrap_43FAF0(0, v23, v10, v19, 200, 0);
	nox_client_drawSetColor_434460(*getMemIntPtr(0x5D4594, 2597996));
	nox_client_drawRectFilledOpaque_49CE30(v10 + 60, v19, v67, v1);
	int v61 = nox_float2int(v70[3]);
	int v44 = *(uint32_t*)(v4 + 2239);
	wchar_t* v24 = nox_strman_loadString_40F1D0("MinMaxFormat", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 1982);
	nox_swprintf(v77, v24, v44, v61);
	nox_xxx_drawGetStringSize_43F840(*(int*)&dword_5d4594_1063636, v77, &v67, 0, 0);
	nox_xxx_drawStringWrap_43FAF0(*(int*)&dword_5d4594_1063636, v77, v10 - v67 + 193, v19 + v73, 200, 0);
	nox_swprintf(v77, L"%d", *(uint32_t*)(v4 + 2239));
	nox_xxx_drawStringWrap_43FAF0(*(int*)&dword_5d4594_1063636, v77, v10 + 45, v19 + v73, 200, 0);
	int v25 = v19 + v1 + 1;
	nox_client_drawSetColor_434460(*getMemIntPtr(0x852978, 12));
	nox_client_drawRectFilledOpaque_49CE30(v10 + 60, v25, 90, v1);
	v68 = 90 * *(uint32_t*)(v4 + 2235);
	float v62 = (double)v68 / v70[2] + 0.5;
	v67 = nox_float2int(v62);
	wchar_t* v26 = nox_strman_loadString_40F1D0("StatsSpeed", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2006);
	nox_xxx_drawStringWrap_43FAF0(0, v26, v10, v25, 200, 0);
	nox_client_drawSetColor_434460(*getMemIntPtr(0x5D4594, 2589772));
	nox_client_drawRectFilledOpaque_49CE30(v10 + 60, v25, v67, v1);
	nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2523948));
	v69 = *getMemFloatPtr(0x5D4594, 1063100) / (v71[2] * 0.000001);
	if (getMemByte(0x5D4594, 1062541) & 2) {
		v69 = ((double)v67 + v69) * 1.25 - (double)v67;
	}
	if (getMemByte(0x5D4594, 1062540) & 0x10) {
		v69 = ((double)v67 + v69) * 0.5 - (double)v67;
	}
	if (v69 >= 0.0) {
		if (v69 > 0.0) {
			*(float*)&v68 = COERCE_FLOAT(nox_float2int(v69));
			if (v67 + v68 > 90) {
				v68 = 90 - v67;
			}
			nox_client_drawSetColor_434460(*getMemIntPtr(0x5D4594, 2589772));
			nox_client_drawRectFilledOpaque_49CE30(v67 + v10 + 60, v25, v68, v1);
			nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x85B3FC, 980));
		}
	} else {
		nox_client_drawSetColor_434460(*getMemIntPtr(0x85B3FC, 944));
		float v45 = -v69;
		int v46 = nox_float2int(v45);
		int v27 = nox_float2int(v69);
		nox_client_drawRectFilledOpaque_49CE30(v67 + v27 + v10 + 60, v25, v46, v1);
	}
	*(float*)&v68 = v69 * 100.0 * 0.011111111;
	float v63 = v70[2] * 100.0 / v71[2];
	int v64 = nox_float2int(v63);
	float v47 = (double)*(int*)(v4 + 2235) * 100.0 / v71[2] + *(float*)&v68 + 0.5;
	int v48 = nox_float2int(v47);
	wchar_t* v28 = nox_strman_loadString_40F1D0("MinMaxFormat", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2045);
	nox_swprintf(v77, v28, v48, v64);
	int v76 = 0;
	nox_xxx_drawGetStringSize_43F840(*(int*)&dword_5d4594_1063636, v77, &v76, 0, 0);
	LODWORD(v69) = v25 + v73;
	nox_xxx_drawStringWrap_43FAF0(*(int*)&dword_5d4594_1063636, v77, v10 - v76 + 193, v25 + v73, 200, 0);
	nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2523948));
	float v65 = (double)*(int*)(v4 + 2235) * 100.0 / v71[2] + *(float*)&v68 + 0.5;
	int v29 = nox_float2int(v65);
	nox_swprintf(v77, L"%d", v29);
	nox_xxx_drawStringWrap_43FAF0(*(int*)&dword_5d4594_1063636, v77, v10 + 45, SLODWORD(v69), 200, 0);
	nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2523948));
	int v30 = 2 * v1 + 2 + v25;
	if (nox_strman_get_lang_code() == 6 || nox_strman_get_lang_code() == 8) {
		v10 += 39;
	}
	nox_xxx_drawSetTextColor_434390(v72);
	wchar_t* v31 = nox_strman_loadString_40F1D0("StatsArmorLabel", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2072);
	nox_wcscpy(v77, v31);
	int v75 = 0;
	nox_xxx_drawGetStringSize_43F840(0, v77, &v75, 0, 0);
	nox_xxx_drawStringWrap_43FAF0(0, v77, v10, v30, 0, 0);
	float v49 = *getMemFloatPtr(0x5D4594, 1062548) * 1000.0 + 0.5;
	int v50 = nox_float2int(v49);
	wchar_t* v32 = nox_strman_loadString_40F1D0("MinMaxFormat", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2076);
	nox_swprintf(v77, v32, v50, 1000);
	nox_xxx_drawStringWrap_43FAF0(0, v77, v75 + v10 + 5, v30, 0, 0);
	int v74 = v30 + v1 + 1;
	int itemsWeight = 0;
	for (int i = 0; i < NOX_INVENTORY_ROW_COUNT; i++) {
		nox_inventory_cell_t* v71a = &nox_client_inventory_grid_1050020[i];
		unsigned char* v33 = &(v71a->field_140);
		for (int j = 0; j < NOX_INVENTORY_COL_COUNT; j++) {
			if (*v33) {
				itemsWeight += *v33 * *(unsigned char*)(*((uint32_t*)v33 - 35) + 298);
			}
			v33 += NOX_INVENTORY_ROW_COUNT * sizeof(nox_inventory_cell_t);
		}
	}
	nox_xxx_drawSetTextColor_434390(v72);
	wchar_t* v35 = nox_strman_loadString_40F1D0("DollWeight", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2098);
	nox_xxx_drawGetStringSize_43F840(0, v35, &v67, 0, 0);
	int v36 = v74;
	int v40 = v74;
	int v39 = v10 + v75 - v67;
	wchar_t* v37 = nox_strman_loadString_40F1D0("DollWeight", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2099);
	nox_xxx_drawStringWrap_43FAF0(0, v37, v39, v40, 0, 0);
	if (itemsWeight > *(unsigned short*)(v4 + 3652)) {
		v72 = *getMemU32Ptr(0x85B3FC, 940);
	}
	nox_xxx_drawSetTextColor_434390(v72);
	int v66 = *(unsigned short*)(v4 + 3652);
	wchar_t* v38 = nox_strman_loadString_40F1D0("MinMaxFormat", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 2107);
	nox_swprintf(v77, v38, itemsWeight, v66);
	nox_xxx_drawStringWrap_43FAF0(0, v77, v75 + v10 + 5, v36, 0, 0);
}

//----- (004649B0) --------------------------------------------------------
int sub_4649B0(int a1, int a2, int a3) {
	int result;        // eax
	unsigned char* v4; // ebp
	unsigned char v5;  // al
	uint32_t* v6;      // eax
	wchar_t* v7;       // eax
	unsigned char* v8; // ecx
	int v9;            // eax
	int v10;           // eax

	result = sub_464B40(a2, a3);
	if (!result) {
		return 0;
	}
	v4 = &nox_client_inventory_grid_1050020[a3 + NOX_INVENTORY_ROW_COUNT * a2];
	v5 = nox_client_inventory_grid_1050020[a3 + NOX_INVENTORY_ROW_COUNT * a2].field_140;
	if (v5) {
		if (*(uint32_t*)(a1 + 112) & 0x4000000) {
			return 0;
		}
		if (*(uint32_t*)(*(uint32_t*)v4 + 108) != *(uint32_t*)(a1 + 108)) {
			return 0;
		}
	}
	if (v5 >= 0x20u) {
		return 0;
	}
	if (!v5) {
		v6 = nox_new_drawable_for_thing(*(uint32_t*)(a1 + 108));
		*(uint32_t*)v4 = v6;
		if (!v6) {
			v7 = nox_strman_loadString_40F1D0("DrawablesExhausted", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 898);
			nox_xxx_printCentered_445490(v7);
			return 0;
		}
		v6[30] |= 0x40000000u;
		memcpy((void*)(*(uint32_t*)v4 + 432), (const void*)(a1 + 432), 0x18u);
		*(uint16_t*)(*(uint32_t*)v4 + 292) = *(uint16_t*)(a1 + 292);
		*(uint16_t*)(*(uint32_t*)v4 + 294) = *(uint16_t*)(a1 + 294);
	}
	v8 = &array_5D4594_1049872;
	*(uint32_t*)&v4[4 * v4[140]++ + 4] = *(uint32_t*)(a1 + 128);
	*((uint32_t*)v4 + 33) = 0;
	while (1) {
		v9 = *(uint32_t*)v8;
		if (*(uint32_t*)v8) {
			break;
		}
	LABEL_17:
		v8 += 4;
		if ((int)v8 >= &array_5D4594_1049872[9]) {
			return 1;
		}
	}
	while (*(uint32_t*)(v9 + 128) != *(uint32_t*)(a1 + 128)) {
		v9 = *(uint32_t*)(v9 + 368);
		if (!v9) {
			goto LABEL_17;
		}
	}
	v10 = *((uint32_t*)v4 + 34);
	*((uint32_t*)v4 + 33) = 1;
	if (v10) {
		nox_xxx_clientSetAltWeapon_461550(0);
		*((uint32_t*)v4 + 34) = 0;
	}
	return 1;
}

//----- (00464BD0) --------------------------------------------------------
int sub_464BD0(int a1, int a2, unsigned int a3) {
	int v4;          // eax
	int v5;          // eax
	int v6;          // eax
	int v7;          // eax
	int v8;          // eax
	int v9;          // esi
	int v10;         // edi
	int v14;         // eax
	int v15;         // eax
	int v16;         // esi
	int v17;         // edi
	int v19;         // ecx
	int v20;         // eax
	int v21;         // eax
	int v26;         // eax
	uint32_t* v28;   // esi
	wchar_t* v29;    // eax
	int v30;         // eax
	int v31;         // eax
	int v32;         // esi
	int v33;         // edi
	int v34;         // eax
	int v36;         // eax
	int v37;         // eax
	int v38;         // eax
	uint32_t* v40;   // ecx
	int v41;         // edx
	int v42;         // edx
	int v45;         // esi
	int v47;         // eax
	int v48;         // esi
	const void* v49; // edi
	wchar_t* v50;    // eax
	int2 v51;        // [esp-24h] [ebp-7Ch]
	int v52;         // [esp-1Ch] [ebp-74h]
	int v53;         // [esp-18h] [ebp-70h]
	int v54;         // [esp-8h] [ebp-60h]
	int v55;         // [esp-4h] [ebp-5Ch]
	int2 v56;        // [esp+8h] [ebp-50h]
	int2 v57;        // [esp+10h] [ebp-48h]
	int2 v58;        // [esp+18h] [ebp-40h]
	int2 v59;        // [esp+20h] [ebp-38h]

	v59.field_4 = a3 >> 16;
	v59.field_0 = (unsigned short)a3;
	sub_463370(*(uint32_t**)&dword_5d4594_1062456, &v59, &v56);
	if (sub_45D9B0() || getMemByte(0x5D4594, 1049868) != 2) {
		return 1;
	}
	switch (a2) {
	case 5:
		if (nox_xxx_playerAnimCheck_4372B0()) {
			return 1;
		}
		if (dword_5d4594_1049864 == 5) {
			v8 = sub_4281F0(&v56, (int4*)getMemAt(0x587000, 136352));
			if (v8) {
				v9 = (v56.field_0 - 314) / 50;
				v10 = (dword_5d4594_1062512 + v56.field_4 - 13) / 50;
				if (!sub_464B40(v9, v10)) {
					return 1;
				}
				int v11 = v10 + NOX_INVENTORY_ROW_COUNT * v9;
				if (nox_client_inventory_grid_1050020[v11].field_140) {
					nox_drawable* dr = nox_client_inventory_grid_1050020[v11].field_0;
					dword_5d4594_1063116 = dr;
					dr->field_32 = nox_client_inventory_grid_1050020[v11].field_4;
				} else {
					dword_5d4594_1063116 = 0;
				}
				return 1;
			}
			if (sub_478030()) {
				if (sub_479870()) {
					LOBYTE(v14) = sub_479880(&v56);
					if (v14) {
						dword_5d4594_1063116 = sub_4798A0(&v56);
						return 1;
					}
				}
			}
		} else if (dword_5d4594_1049864 == 6) {
			v15 = sub_4281F0(&v56, (int4*)getMemAt(0x587000, 136352));
			if (v15) {
				v16 = (v56.field_0 - 314) / 50;
				v17 = (dword_5d4594_1062512 + v56.field_4 - 13) / 50;
				if (sub_464B40(v16, v17)) {
					int v18 = v17 + NOX_INVENTORY_ROW_COUNT * v16;
					if (nox_client_inventory_grid_1050020[v18].field_140) {
						v19 = nox_client_inventory_grid_1050020[v18].field_0;
						v20 = nox_client_inventory_grid_1050020[v18].field_4;
						*(uint32_t*)(v19 + 128) = v20;
						if (v19) {
							nox_xxx_trade_4657B0(v20);
							return 1;
						}
					}
				}
			}
		} else if (getMemByte(0x5D4594, 1049870) != 1 ||
				   (v21 = sub_4281F0(&v56, (int4*)getMemAt(0x587000, 136336)), v21 != 1)) {
			if (getMemByte(0x5D4594, 1049869) || sub_4281F0(&v56, (int4*)getMemAt(0x587000, 136384)) ||
				sub_4281F0(&v56, (int4*)getMemAt(0x587000, 136400))) {
				if (sub_4281F0(&v56, (int4*)getMemAt(0x587000, 136384)) == 1) {
					return 0;
				}
				if (sub_4281F0(&v56, (int4*)getMemAt(0x587000, 136400)) == 1) {
					return 0;
				}
			} else {
				nox_xxx_wndSetCaptureMain_46ADC0(*(int*)&dword_5d4594_1062456);
				if (sub_479590() == 3) {
					nox_xxx_clientTradeMB_4657E0(&v56);
				} else {
					sub_4658A0(*(int*)&dword_5d4594_1062456, &v56);
				}
				if (*getMemU32Ptr(0x5D4594, 1049848)) {
					nox_xxx_cursorSetDraggedItem_477690(*getMemIntPtr(0x5D4594, 1049848));
					nox_xxx_setKeybTimeout_4160D0(0);
					*(int2*)getMemAt(0x5D4594, 1062572) = v56;
					nox_xxx_clientPlaySoundSpecial_452D80(791, 100);
					return 1;
				}
			}
		}
		return 1;
	case 6:
		goto LABEL_53;
	case 7:
		if (nox_xxx_playerAnimCheck_4372B0() || dword_5d4594_1049864 == 6) {
			return 1;
		}
		if (!getMemByte(0x5D4594, 1049869)) {
			v26 = sub_4281F0(&v56, (int4*)getMemAt(0x587000, 136368));
			if (v26) {
				if ((v56.field_4 - 13) / 50 == 1) {
					if (dword_5d4594_1049864 != 5) {
						sub_465CA0();
						return 1;
					}
				LABEL_5:
					sub_462740();
					return 1;
				}
			}
		}
	LABEL_53:
		if (nox_xxx_playerAnimCheck_4372B0() || dword_5d4594_1049864 == 6) {
			return 1;
		}
		if (dword_5d4594_1049864 == 5) {
			if (nox_xxx_cursorGetTypePrev_477630() == 7) {
				goto LABEL_5;
			}
		} else {
			nox_xxx_wndClearCaptureMain_46ADE0(*(int*)&dword_5d4594_1062456);
		}
		if (dword_5d4594_1049864 == 4) {
			v58 = v59;
			sub_473970(&v58, &v58);
			v28 = nox_drawable_find_49ABF0(&v58, 20);
			if (v28) {
				v57.field_0 = nox_win_width / 2;
				v57.field_4 = nox_win_height / 2;
				sub_473970(&v57, &v57);
				if ((v57.field_0 - v28[3]) * (v57.field_0 - v28[3]) + (v57.field_4 - v28[4]) * (v57.field_4 - v28[4]) <=
					5625) {
				LABEL_64:
					dword_5d4594_1049864 = 0;
					return 1;
				}
				v29 = nox_strman_loadString_40F1D0("ObjectTooFar", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 3858);
			} else {
				v29 = nox_strman_loadString_40F1D0("NoObject", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 3869);
			}
			nox_xxx_printCentered_445490(v29);
			goto LABEL_64;
		}
		if (!*getMemU32Ptr(0x5D4594, 1049848)) {
			return 1;
		}
		if (!nox_xxx_wndPointInWnd_46AAB0(*(uint32_t**)&dword_5d4594_1062456, v59.field_0, v59.field_4) ||
			(v30 = sub_4281F0(&v56, (int4*)getMemAt(0x587000, 136384)), v30) ||
			(v31 = sub_4281F0(&v56, (int4*)getMemAt(0x587000, 136400)), v31)) {
			v58 = v59;
			sub_473970(&v58, &v57);
			if (dword_5d4594_1049856 == 1) {
				if (!sub_4C12C0()) {
					nox_xxx_clientDrop_465BE0(&v57);
				}
			} else {
				v47 = dword_5d4594_1049800_inventory_click_row_index +
					  14 * dword_5d4594_1049796_inventory_click_column_index +
					  7 * dword_5d4594_1049796_inventory_click_column_index;
				v48 = nox_client_inventory_grid_1050020[v47].field_140;
				if (nox_client_inventory_grid_1050020[v47].field_140) {
					v49 = 0;
					nox_xxx_wndClearCaptureMain_46ADE0(*(int*)&dword_5d4594_1062456);
					if (*(uint32_t*)(*getMemU32Ptr(0x5D4594, 1049848) + 112) & 0x13001000) {
						v49 = (const void*)(*getMemU32Ptr(0x5D4594, 1049848) + 432);
					}
					sub_4C05F0(0, 0);
					v53 = *(uint32_t*)(*getMemU32Ptr(0x5D4594, 1049848) + 108);
					v52 = *(uint32_t*)(*getMemU32Ptr(0x5D4594, 1049848) + 128);
					v51 = v58;
					v50 = nox_strman_loadString_40F1D0("DropLabel", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 4148);
					nox_gui_itemAmountDialog_4C0430((int)v50, v51.field_0, v51.field_4, v52, v53, v49, v48 + 1, 0,
													sub_465CD0, 0);
				} else if (!sub_4C12C0()) {
					nox_xxx_clientDrop_465BE0(&v57);
				}
			}
			if (dword_5d4594_1049856) {
				goto LABEL_121;
			}
		LABEL_119:
			v55 = dword_5d4594_1049800_inventory_click_row_index;
			v54 = dword_5d4594_1049796_inventory_click_column_index;
			goto LABEL_120;
		}
		v32 = *getMemU32Ptr(0x5D4594, 1062572) - v56.field_0;
		v33 = *getMemU32Ptr(0x5D4594, 1062576) - v56.field_4;
		if (!nox_xxx_checkKeybTimeout_4160F0(0, nox_gameFPS / 3u) && v32 * v32 + v33 * v33 < 100) {
			v34 = sub_4281F0(&v56, (int4*)getMemAt(0x587000, 136352));
			if (!v34) {
				goto LABEL_121;
			}
			if (!sub_4C12C0()) {
				if (*(uint32_t*)(*getMemU32Ptr(0x5D4594, 1049848) + 112) & 0x3001000) {
					int v35 = dword_5d4594_1049800_inventory_click_row_index +
							  NOX_INVENTORY_ROW_COUNT * dword_5d4594_1049796_inventory_click_column_index;
					if (nox_client_inventory_grid_1050020[v35].field_136) {
						nox_xxx_clientSetAltWeapon_461550(0);
						nox_client_inventory_grid_1050020[v35].field_136 = 0;
					} else if (nox_client_inventory_grid_1050020[v35].field_132) {
						nox_xxx_clientDequip_464B70(*getMemIntPtr(0x5D4594, 1049848));
					} else {
						nox_xxx_clientKeyEquip_465C30(*(int*)&dword_5d4594_1049796_inventory_click_column_index,
													  *(int*)&dword_5d4594_1049800_inventory_click_row_index);
					}
				} else {
					nox_xxx_clientUse_465C70(*getMemIntPtr(0x5D4594, 1049848));
				}
			}
			goto LABEL_80;
		}
		v36 = sub_4281F0(&v56, (int4*)getMemAt(0x587000, 136336));
		if (v36 && !getMemByte(0x5D4594, 1049870)) {
			if (!dword_5d4594_1049856) {
				nox_xxx_clientEquip_4623B0(*getMemIntPtr(0x5D4594, 1049848));
				sub_4649B0(*getMemIntPtr(0x5D4594, 1049848), *(int*)&dword_5d4594_1049796_inventory_click_column_index,
						   *(int*)&dword_5d4594_1049800_inventory_click_row_index);
			}
			goto LABEL_121;
		}
		v37 = sub_4281F0(&v56, (int4*)getMemAt(0x587000, 136352));
		if (!v37) {
			goto LABEL_119;
		}
		v38 = *(uint32_t*)(*getMemU32Ptr(0x5D4594, 1049848) + 108);
		if (v38 == dword_5d4594_1062560 || v38 == *getMemU32Ptr(0x5D4594, 1049728) ||
			v38 == *getMemU32Ptr(0x5D4594, 1049724) || v38 == dword_5d4594_1062556 || v38 == dword_5d4594_1062564) {
			sub_4649B0(*getMemIntPtr(0x5D4594, 1049848), *(int*)&dword_5d4594_1049796_inventory_click_column_index,
					   *(int*)&dword_5d4594_1049800_inventory_click_row_index);
			goto LABEL_121;
		}
		dword_5d4594_1049804 = (v56.field_0 - 314) / 50;
		dword_5d4594_1049808 = (dword_5d4594_1062512 + v56.field_4 - 13) / 50;
		if (!sub_464B40((v56.field_0 - 314) / 50, (dword_5d4594_1062512 + v56.field_4 - 13) / 50)) {
			goto LABEL_121;
		}
		if (dword_5d4594_1049856) {
			int v39 = dword_5d4594_1049808 + NOX_INVENTORY_ROW_COUNT * dword_5d4594_1049804;
			if (nox_client_inventory_grid_1050020[v39].field_140 && (v40 = (uint32_t*)nox_client_inventory_grid_1050020[v39].field_0) != 0 &&
				((v41 = v40[28], v41 & 0x2000000) && *(uint32_t*)(*getMemU32Ptr(0x5D4594, 1049848) + 112) & 0x2000000 &&
					 v40[29] == *(uint32_t*)(*getMemU32Ptr(0x5D4594, 1049848) + 116) ||
				 v41 & 0x1001000 && *(uint32_t*)(*getMemU32Ptr(0x5D4594, 1049848) + 112) & 0x1001000)) {
				v42 = nox_client_inventory_grid_1050020[v39].field_4;
				*getMemU32Ptr(0x5D4594, 1049860) = 1;
				v40[32] = v42;
				nox_xxx_clientEquip_4623B0((int)v40);
			} else {
				*getMemU32Ptr(0x5D4594, 1049860) = 1;
				nox_xxx_clientDequip_464B70(*getMemIntPtr(0x5D4594, 1049848));
			}
			goto LABEL_121;
		}
		if (nox_client_inventory_grid_1050020[dword_5d4594_1049800_inventory_click_row_index +
								NOX_INVENTORY_ROW_COUNT * dword_5d4594_1049796_inventory_click_column_index]
				.field_140) {
			v55 = dword_5d4594_1049800_inventory_click_row_index;
			v54 = dword_5d4594_1049796_inventory_click_column_index;
		LABEL_120:
			sub_4649B0(*getMemIntPtr(0x5D4594, 1049848), v54, v55);
			goto LABEL_121;
		}
		if (!sub_4649B0(*getMemIntPtr(0x5D4594, 1049848), *(int*)&dword_5d4594_1049804, *(int*)&dword_5d4594_1049808)) {
		LABEL_80:
			sub_4649B0(*getMemIntPtr(0x5D4594, 1049848), *(int*)&dword_5d4594_1049796_inventory_click_column_index,
					   *(int*)&dword_5d4594_1049800_inventory_click_row_index);
			goto LABEL_121;
		}
		nox_xxx_clientPlaySoundSpecial_452D80(792, 100);
		int v43 = dword_5d4594_1049800_inventory_click_row_index +
				  NOX_INVENTORY_ROW_COUNT * dword_5d4594_1049796_inventory_click_column_index;
		v45 = nox_client_inventory_grid_1050020[v43].field_136;
		if (v45) {
			int v46 = dword_5d4594_1049808 + NOX_INVENTORY_ROW_COUNT * dword_5d4594_1049804;
			nox_client_inventory_grid_1050020[v46].field_136 = v45;
			nox_client_inventory_grid_1050020[v43].field_136 = 0;
			dword_5d4594_1062480 = &nox_client_inventory_grid_1050020[v46];
		}
		sub_461B50();
	LABEL_121:
		nox_xxx_cursorResetDraggedItem_4776A0();
		if (!dword_5d4594_1049856) {
			nox_xxx_spriteDelete_45A4B0(*(uint64_t**)getMemAt(0x5D4594, 1049848));
		}
		*getMemU32Ptr(0x5D4594, 1049848) = 0;
		dword_5d4594_1049856 = 0;
		return 1;
	case 8:
		return 1;
	case 9:
		if (dword_5d4594_1049864 == 5) {
			goto LABEL_5;
		}
		return 0;
	case 19:
		if (nox_xxx_playerAnimCheck_4372B0()) {
			return 1;
		}
		v6 = sub_4281F0(&v56, (int4*)getMemAt(0x587000, 136384));
		if (v6) {
			goto LABEL_124;
		}
		v7 = sub_4281F0(&v56, (int4*)getMemAt(0x587000, 136400));
		if (v7) {
			goto LABEL_124;
		}
		nox_window_call_field_94(*(int*)&dword_5d4594_1062456, 16391, *getMemIntPtr(0x5D4594, 1062500), 0);
		return 1;
	case 20:
		if (nox_xxx_playerAnimCheck_4372B0()) {
			return 1;
		}
		v4 = sub_4281F0(&v56, (int4*)getMemAt(0x587000, 136384));
		if (v4) {
			goto LABEL_124;
		}
		v5 = sub_4281F0(&v56, (int4*)getMemAt(0x587000, 136400));
		if (v5) {
			goto LABEL_124;
		}
		nox_window_call_field_94(*(int*)&dword_5d4594_1062456, 16391, *getMemIntPtr(0x5D4594, 1062504), 0);
		return 1;
	default:
	LABEL_124:
		if (dword_5d4594_1049864 == 5) {
			return 1;
		}
		return 0;
	}
}
//----- (00465A30) --------------------------------------------------------
void nox_xxx_cliInventorySpriteUpd_465A30() {
	int inventory_item_idx = dword_5d4594_1049800_inventory_click_row_index +
							 NOX_INVENTORY_ROW_COUNT * dword_5d4594_1049796_inventory_click_column_index;
	if (nox_client_inventory_grid_1050020[inventory_item_idx].field_140) {
		uint32_t* v1 = nox_new_drawable_for_thing(nox_client_inventory_grid_1050020[inventory_item_idx].field_0->field_27);
		*getMemU32Ptr(0x5D4594, 1049848) = v1;
		if (v1) {
			v1[30] |= 0x40000000u;
			*(uint32_t*)((uint32_t)v1 + 128) = nox_client_inventory_grid_1050020[inventory_item_idx].field_4;
			memcpy((void*)((uint32_t)v1 + 432),
				   (const void*)&(nox_client_inventory_grid_1050020[inventory_item_idx].field_0->field_108_1), 24);
			*(uint16_t*)((uint32_t)v1 + 292) = nox_client_inventory_grid_1050020[inventory_item_idx].field_0->field_73_1;
			*(uint16_t*)((uint32_t)v1 + 294) = nox_client_inventory_grid_1050020[inventory_item_idx].field_0->field_73_2;
			int* v3[2];
			v3[0] = &nox_client_inventory_grid_1050020[inventory_item_idx].field_0;
			v3[1] = 0;
			sub_461E60((uint64_t***)v3);
		} else {
			wchar_t* v2 =
				nox_strman_loadString_40F1D0("DrawablesExhausted", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 1123);
			nox_xxx_printCentered_445490(v2);
		}
	}
}

//----- (00466160) --------------------------------------------------------
int sub_466160() {
	wchar_t* v0; // eax

	if (getMemByte(0x5D4594, 1049868) == 2) {
		v0 = nox_strman_loadString_40F1D0("CloseInventoryTT", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 410);
	} else {
		v0 = nox_strman_loadString_40F1D0("OpenInventoryTT", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 414);
	}
	nox_xxx_cursorSetTooltip_4776B0(v0);
	return 1;
}

//----- (004661D0) --------------------------------------------------------
int sub_4661D0() {
	wchar_t* v0; // eax
	wchar_t* v2; // eax

	if (dword_5d4594_1062480) {
		v0 = nox_xxx_clientAskInfoMb_4BF050(**(wchar_t***)&dword_5d4594_1062480);
		nox_xxx_cursorSetTooltip_4776B0(v0);
	} else {
		v2 = nox_strman_loadString_40F1D0("ToolTipWeapon2Area", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 3331);
		nox_xxx_cursorSetTooltip_4776B0(v2);
	}
	return 1;
}

//----- (00466660) --------------------------------------------------------
wchar_t* sub_466660(int a1, int2* a2) {
	int v2;          // eax
	int v3;          // eax
	wchar_t* result; // eax
	wchar_t* v5;     // eax
	int v6;          // eax
	int v7;          // esi
	int v8;          // edi
	int v9;          // edx
	int v10;         // eax
	int v13;         // ecx

	v2 = sub_4281F0(a2, (int4*)getMemAt(0x587000, 136336));
	if (!v2) {
		if (!getMemByte(0x5D4594, 1049869)) {
			v6 = sub_4281F0(a2, (int4*)getMemAt(0x587000, 136368));
			if (v6) {
				v7 = a2->field_4 - 13;
				v8 = v7 / 50;
				v9 = 20;
				dword_5d4594_1049796_inventory_click_column_index = v7 / 50;
			} else {
				v10 = sub_4281F0(a2, (int4*)getMemAt(0x587000, 136352));
				if (!v10) {
					return 0;
				}
				v8 = (a2->field_0 - 314) / 50;
				dword_5d4594_1049796_inventory_click_column_index = (a2->field_0 - 314) / 50;
				v9 = (a2->field_4 + dword_5d4594_1062512 - 13) / 50;
			}
			dword_5d4594_1049800_inventory_click_row_index = v9;
			if (sub_464B40(v8, v9)) {
				int v12 = dword_5d4594_1049800_inventory_click_row_index +
						  NOX_INVENTORY_ROW_COUNT * dword_5d4594_1049796_inventory_click_column_index;
				if (nox_client_inventory_grid_1050020[v12].field_140) {
					v13 = nox_client_inventory_grid_1050020[v12].field_0;
					*(uint32_t*)(v13 + 128) = nox_client_inventory_grid_1050020[v12].field_4;
					return nox_xxx_clientAskInfoMb_4BF050((wchar_t*)v13);
				}
			}
		}
		return 0;
	}
	if (getMemByte(0x5D4594, 1049870) == 1) {
		return 0;
	}
	v3 = sub_465990(a2);
	if (v3 == -1) {
		return nox_strman_loadString_40F1D0("DollRegionError", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 3155);
	}
	v5 = *(wchar_t**)&array_5D4594_1049872[v3];
	if (v5) {
		result = nox_xxx_clientAskInfoMb_4BF050(v5);
	} else {
		result = nox_strman_loadString_40F1D0("ToolTipDrag", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 3159);
	}
	return result;
}
//----- (004667E0) --------------------------------------------------------
int nox_xxx_inventroryOnHovewerSub_4667E0(int a1, int a2, unsigned int a3) {
	int v3;       // edx
	int v4;       // esi
	int v5;       // ecx
	int v6;       // eax
	wchar_t* v7;  // eax
	int result;   // eax
	int v9;       // ecx
	wchar_t* v10; // eax
	int v11;      // eax
	wchar_t* v12; // eax
	int v13;      // eax
	wchar_t* v14; // eax
	int2 v15;     // [esp+4h] [ebp-8h]

	v3 = 40;
	v15.field_0 = (unsigned short)a3;
	v15.field_4 = a3 >> 16;
	v4 = 0;
	while (v3 <= (unsigned short)a3) {
		v3 += 35;
		++v4;
	}
	v5 = 0;
	do {
		if ((1 << v5) & *getMemU32Ptr(0x5D4594, 1062540) && v5 != 31) {
			--v4;
		}
		if (v4 < 0) {
			break;
		}
		++v5;
	} while (v5 < 32);
	if (v5 != 32) {
		v6 = nox_xxx_getEnchantSpell_424920(v5);
		v7 = (wchar_t*)nox_xxx_spellTitle_424930(v6);
		nox_xxx_cursorSetTooltip_4776B0(v7);
		return 1;
	}
	v9 = 0;
	do {
		if ((1 << v9) & getMemByte(0x5D4594, 1062536)) {
			--v4;
		}
		if (v4 < 0) {
			break;
		}
		++v9;
	} while (v9 < 6);
	if (v9 != 6) {
		v10 = sub_413480(1 << v9);
		nox_xxx_cursorSetTooltip_4776B0(v10);
		return 1;
	}
	if (!nox_common_gameFlags_check_40A5C0(4096)) {
		goto LABEL_28;
	}
	v11 = sub_4281F0(&v15, (int4*)getMemAt(0x5D4594, 1049812));
	if (v11 == 1) {
		v12 = nox_strman_loadString_40F1D0("thing.db:AnkhGUI", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 4385);
		nox_xxx_cursorSetTooltip_4776B0(v12);
		return 1;
	}
	v13 = sub_4281F0(&v15, (int4*)getMemAt(0x5D4594, 1049828));
	if (v13 == 1 && sub_4BFD30() == 1) {
		v14 = nox_strman_loadString_40F1D0("GeneralPrint:TooltipKeyIcon", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c",
										   4388);
		nox_xxx_cursorSetTooltip_4776B0(v14);
		result = 1;
	} else {
	LABEL_28:
		nox_xxx_cursorSetTooltip_4776B0(0);
		result = 1;
	}
	return result;
}
//----- (00466E20) --------------------------------------------------------
int sub_466E20(uint32_t* a1) {
	wchar_t* v1; // eax
	int result;  // eax

	switch (*a1) {
	case 0x2391:
		v1 = nox_strman_loadString_40F1D0("JournalModeTT", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 424);
		goto LABEL_7;
	case 0x2392:
		v1 = nox_strman_loadString_40F1D0("InventoryModeTT", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 428);
		goto LABEL_7;
	case 0x2393:
		v1 = nox_strman_loadString_40F1D0("StatsModeTT", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 432);
		goto LABEL_7;
	case 0x2394:
		v1 = nox_strman_loadString_40F1D0("PaperDollModeTT", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 436);
		goto LABEL_7;
	case 0x2397:
		v1 = nox_strman_loadString_40F1D0("CloseInventoryTT", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 440);
	LABEL_7:
		nox_xxx_cursorSetTooltip_4776B0(v1);
		result = 1;
		break;
	default:
		result = 0;
		break;
	}
	return result;
}

//----- (004671E0) --------------------------------------------------------
int nox_xxx_inventoryNameSignInit_4671E0() {
	int result;   // eax
	int v1;       // ecx
	wchar_t* v2;  // eax
	int v3;       // [esp-8h] [ebp-6Ch]
	wchar_t* v4;  // [esp-4h] [ebp-68h]
	char v5[100]; // [esp+0h] [ebp-64h]

	nox_wcscpy((wchar_t*)getMemAt(0x5D4594, 1062588), (const wchar_t*)getMemAt(0x5D4594, 1063676));
	if (nox_common_gameFlags_check_40A5C0(4096) || nox_xxx_isQuest_4D6F50() || (result = sub_4D6F70()) != 0) {
		result = dword_5d4594_1049844;
		if (dword_5d4594_1049844 > NOX_PLAYER_MAX_LEVEL) {
			result = NOX_PLAYER_MAX_LEVEL;
		}
		v1 = *getMemU32Ptr(0x8531A0, 2576);
	} else {
		v1 = *getMemU32Ptr(0x8531A0, 2576);
		if (!*getMemU32Ptr(0x8531A0, 2576)) {
			return result;
		}
		result = *(char*)(*getMemU32Ptr(0x8531A0, 2576) + 3684);
	}
	if (v1) {
		nox_sprintf(v5, "experience:%s%d", *getMemU32Ptr(0x587000, 29456 + 4 * *(unsigned char*)(v1 + 2251)), result);
		v4 = nox_strman_loadString_40F1D0(v5, 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 4763);
		v3 = *getMemU32Ptr(0x8531A0, 2576) + 4704;
		v2 = nox_strman_loadString_40F1D0("ElaborateNameFormat", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 4761);
		result = nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1062588), v2, v3, v4);
	}
	return result;
}

//----- (00467750) --------------------------------------------------------
int sub_467750(int a1, char a2) {
	if (a1 != 0) {
		uint32_t* v2 = (uint32_t*)sub_461EF0(a1);
		if (v2 != NULL) {
			if (dword_5d4594_1062480) {
				*(uint32_t*)(dword_5d4594_1062480 + 136) = 0;
			}
			dword_5d4594_1062480 = *v2;
			*(uint32_t*)(dword_5d4594_1062480 + 136) = 1;
			return 1;
		}
	} else {
		if (dword_5d4594_1062480) {
			*(uint32_t*)(dword_5d4594_1062480 + 136) = 0;
			dword_5d4594_1062480 = 0;
		}
	}

	if (a2) {
		if (a2 != 1) {
			return 0;
		}
		wchar_t* v5 =
			nox_strman_loadString_40F1D0("Weapon2CantUse", 0, "C:\\NoxPost\\src\\Client\\Gui\\guiinv.c", 5379);
		nox_xxx_printCentered_445490(v5);
		if (!dword_5d4594_1062484) {
			return 0;
		}
		int* v6 = (int*)sub_461EF0(*(int*)&dword_5d4594_1062484);
		if (v6) {
			nox_xxx_clientSetAltWeapon_461550(*v6);
			return 0;
		}
	}
	dword_5d4594_1062484 = 0;
	return 0;
}
