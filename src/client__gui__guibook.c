#include "client__gui__guibook.h"
#include "client__gui__window.h"

#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_2.h"
#include "GAME3_1.h"
#include "GAME4_1.h"
#include "client__gui__guimsg.h"
#include "common__magic__speltree.h"
#include "common__random.h"
#include "common__strman.h"
#include "input_common.h"

extern uint32_t dword_5d4594_1046852;
extern uint32_t dword_5d4594_1046652;
extern uint32_t dword_5d4594_1047524;
extern uint32_t dword_5d4594_1046944;
extern uint32_t dword_5d4594_1046648;
extern uint32_t dword_5d4594_1046640;
float2 obj_5d4594_1046620 = {0};
extern uint32_t dword_5d4594_1046932;
extern uint32_t dword_5d4594_1046948;
extern uint32_t dword_5d4594_1046636;
extern uint32_t dword_5d4594_1046928;
extern uint32_t dword_5d4594_1047512;
extern uint32_t dword_5d4594_1046656;
extern uint32_t dword_5d4594_1046924;
extern uint32_t dword_5d4594_1047520;
extern uint32_t nox_xxx_aNox_cfg_0_587000_132132;
extern uint32_t dword_5d4594_1046936;
extern uint32_t dword_5d4594_1046872;
extern uint32_t dword_5d4594_1047516;
extern uint32_t dword_5d4594_1046868;
extern int nox_win_width;
extern int nox_win_height;

//----- (0045AD70) --------------------------------------------------------
void nox_xxx_bookShowMB_45AD70(int a1) {
	unsigned int result; // eax
	wchar_t* v2;         // eax

	result = nox_xxx_guiCursor_477600();
	if (result) {
		return;
	}
	if (!(!nox_xxx_playerAnimCheck_4372B0() || (result = nox_common_gameFlags_check_40A5C0(2048)) == 0)) {
		return;
	}
	if (!*getMemU32Ptr(0x8531A0, 2576) ||
		nox_xxx_guiSpellSortList_45ADF0(*(unsigned char*)(*getMemU32Ptr(0x8531A0, 2576) + 2251))) {
		nox_xxx_book_45B010(a1);
	} else {
		v2 = nox_strman_loadString_40F1D0("EmptyBook", 0, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 377);
		nox_xxx_printCentered_445490(v2);
		nox_xxx_clientPlaySoundSpecial_452D80(925, 100);
	}
}

//----- (0045BD40) --------------------------------------------------------
int nox_xxx_bookDrawList_45BD40(int a1) {
	int v1;                 // esi
	int v2;                 // ebp
	int v3;                 // edi
	int v4;                 // esi
	int v5;                 // ebx
	int v6;                 // ebp
	int v7;                 // edi
	int v8;                 // esi
	char v9;                // cl
	unsigned short* v10;    // eax
	short* v11;             // eax
	unsigned short* v12;    // eax
	unsigned short* v13;    // eax
	int v14;                // esi
	wchar_t* v15;           // eax
	int v16;                // eax
	int v17;                // eax
	int v18;                // ebp
	wchar_t* v19;           // eax
	int v20;                // ebx
	wchar_t* v21;           // eax
	wchar_t* v22;           // eax
	int v23;                // esi
	unsigned short* v24;    // eax
	int v25;                // eax
	uint16_t* v26;          // eax
	int v27;                // eax
	unsigned short* v28;    // eax
	unsigned short* v29;    // esi
	int v30;                // edi
	int v31;                // edx
	int v32;                // ecx
	unsigned short* v33;    // eax
	int v34;                // ecx
	uint16_t* v35;          // eax
	unsigned short* v36;    // eax
	int v37;                // eax
	short v38;              // bx
	unsigned short* v39;    // eax
	int v40;                // eax
	int v41;                // esi
	uint16_t* v42;          // eax
	int v43;                // esi
	int v44;                // ebp
	wchar_t* v45;           // eax
	int v46;                // esi
	int v47;                // esi
	unsigned short* v48;    // ebp
	unsigned short* v49;    // ebp
	unsigned short* v50;    // ebp
	unsigned short* v51;    // ebp
	wchar_t* v52;           // eax
	unsigned short* v53;    // eax
	int v55;                // [esp-10h] [ebp-23Ch]
	int v56;                // [esp-10h] [ebp-23Ch]
	int v57;                // [esp-10h] [ebp-23Ch]
	int v58;                // [esp-Ch] [ebp-238h]
	int v59;                // [esp-Ch] [ebp-238h]
	int v60;                // [esp-8h] [ebp-234h]
	int v61;                // [esp-8h] [ebp-234h]
	int v62;                // [esp-4h] [ebp-230h]
	int v63;                // [esp-4h] [ebp-230h]
	int v64;                // [esp-4h] [ebp-230h]
	int v65;                // [esp+10h] [ebp-21Ch]
	int v66;                // [esp+14h] [ebp-218h]
	int v67;                // [esp+18h] [ebp-214h]
	int v68;                // [esp+1Ch] [ebp-210h]
	wchar_t WideCharStr[4]; // [esp+20h] [ebp-20Ch]
	int v70;                // [esp+28h] [ebp-204h]
	wchar_t v71[256];       // [esp+2Ch] [ebp-200h]

	nox_gui_getWindowOffs_46AA20(a1, &v66, &v67);
	v1 = v66 - 24;
	v2 = v67 - 76;
	v3 = nox_xxx_guiFontHeightMB_43F320(0);
	dword_5d4594_1046656 = v3 + 2;
	nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 1046880));
	nox_client_drawImageAt_47D2C0(*getMemIntPtr(0x5D4594, 1046856), v1, v2);
	if (dword_5d4594_1046872) {
		nox_client_drawImageAt_47D2C0(*getMemIntPtr(0x5D4594, 1046660), v1, v2);
	} else {
		nox_client_drawImageAt_47D2C0(*getMemIntPtr(0x5D4594, 1046644), v1, v2);
	}
	if (dword_5d4594_1046868 == 3) {
		nox_video_drawAnimatedImageOrCursorAt_4BE6D0(*(int*)&dword_5d4594_1046928, v1, v2);
		goto LABEL_75;
	}
	if (dword_5d4594_1046868 == 2) {
		nox_video_drawAnimatedImageOrCursorAt_4BE6D0(*(int*)&dword_5d4594_1046924, v1, v2);
		goto LABEL_75;
	}
	if (nox_xxx_aNox_cfg_0_587000_132132) {
		v4 = dword_5d4594_1046936;
		*(uint32_t*)WideCharStr = 141 / dword_5d4594_1046656 - 1;
		if (!dword_5d4594_1046936) {
			nox_window_set_hidden(*(int*)&dword_5d4594_1046944, 1);
			v4 = dword_5d4594_1046936;
		}
		v5 = 0;
		v6 = v66 + 78;
		v7 = v67 + 19;
		if (2 * *(uint32_t*)WideCharStr > 0) {
			while (1) {
				v8 = v5 + 2 * *(uint32_t*)WideCharStr * v4;
				if (v8 >= *getMemIntPtr(0x5D4594, 1047508) - dword_5d4594_1047512) {
					break;
				}
				if (v5 == *(uint32_t*)WideCharStr) {
					v6 = v66 + 199;
					v7 = v67 + 19;
				}
				nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 1046880));
				v9 = *(uint8_t*)(dword_5d4594_1047516 + 2251);
				if (dword_5d4594_1046868 == 1) {
					if (v9 == 2 && !nox_xxx_spellIsEnabled_424B70(*getMemU32Ptr(0x5D4594, 1046960 + 4 * v8) + 74)) {
						nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 1046884));
					}
					v10 = (unsigned short*)nox_xxx_guiCreatureGetName_427240(*getMemU32Ptr(0x5D4594, 1046960 + 4 * v8));
					nox_xxx_drawGetStringSize_43F840(0, v10, &v65, 0, 128);
					v62 = v7;
					v60 = v6 - v65 / 2;
					v11 = (short*)nox_xxx_guiCreatureGetName_427240(*getMemU32Ptr(0x5D4594, 1046960 + 4 * v8));
				} else if (v9) {
					if (!nox_xxx_spellIsEnabled_424B70(*getMemU32Ptr(0x5D4594, 1046960 + 4 * v8))) {
						nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 1046884));
					}
					v13 = (unsigned short*)nox_xxx_spellTitle_424930(*getMemU32Ptr(0x5D4594, 1046960 + 4 * v8));
					nox_xxx_drawGetStringSize_43F840(0, v13, &v65, 0, 128);
					v62 = v7;
					v60 = v6 - v65 / 2;
					v11 = (short*)nox_xxx_spellTitle_424930(*getMemU32Ptr(0x5D4594, 1046960 + 4 * v8));
				} else {
					v12 = (unsigned short*)nox_xxx_abilityGetName_0_425260(*getMemU32Ptr(0x5D4594, 1046960 + 4 * v8));
					nox_xxx_drawGetStringSize_43F840(0, v12, &v65, 0, 128);
					v62 = v7;
					v60 = v6 - v65 / 2;
					v11 = (short*)nox_xxx_abilityGetName_0_425260(*getMemU32Ptr(0x5D4594, 1046960 + 4 * v8));
				}
				nox_xxx_drawString_43F6E0(0, v11, v60, v62);
				v7 += dword_5d4594_1046656;
				if (++v5 >= 2 * *(uint32_t*)WideCharStr) {
					break;
				}
				v4 = dword_5d4594_1046936;
			}
		}
		goto LABEL_75;
	}
	if (dword_5d4594_1046868 == 1) {
		v14 = v67 + 51;
		v15 = nox_strman_loadString_40F1D0("Size", 0, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 978);
		nox_swprintf(v71, L"%s ", v15);
		v16 = nox_xxx_guideGetUnitSize_427460(*getMemU32Ptr(0x5D4594, 1046960 + 4 * dword_5d4594_1046932)) - 1;
		if (v16) {
			v17 = v16 - 1;
			if (v17) {
				if (v17 == 2) {
					v18 = 76;
					v19 = nox_strman_loadString_40F1D0("Large", 0, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 995);
					nox_wcscat(v71, v19);
					v20 = 0;
				} else {
					v18 = *(uint32_t*)WideCharStr;
					v20 = *(uint32_t*)WideCharStr;
				}
			} else {
				v18 = 38;
				v21 = nox_strman_loadString_40F1D0("Medium", 0, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 989);
				nox_wcscat(v71, v21);
				v20 = 0;
			}
		} else {
			v18 = 38;
			v22 = nox_strman_loadString_40F1D0("Small", 0, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 983);
			nox_wcscat(v71, v22);
			v20 = 19;
		}
		if (*(uint8_t*)(dword_5d4594_1047516 + 2251) == 2 &&
			(*(uint32_t*)(dword_5d4594_1047516 + 4232) ||
			 nox_common_gameFlags_check_40A5C0(0x2000) && !nox_common_gameFlags_check_40A5C0(4096))) {
			nox_xxx_drawGetStringSize_43F840(0, v71, &v70, 0, 0);
			nox_xxx_drawStringWrap_43FAF0(0, v71, (108 - v70) / 2 + v66 + 24, v14, 128, 0);
		}
		v23 = v14 + v3 + 2;
		v24 = (unsigned short*)nox_xxx_guiCreatureGetName_427240(
			*getMemU32Ptr(0x5D4594, 1046960 + 4 * dword_5d4594_1046932));
		nox_xxx_bookGetStringSize_43FA80(0, v24, &v70, &v68, 108);
		if (v68 <= v3) {
			v25 = (108 - v70) / 2 + v66 + 24;
		} else {
			v25 = v66 + 24;
		}
		v55 = v25;
		v26 = (uint16_t*)nox_xxx_guiCreatureGetName_427240(*getMemU32Ptr(0x5D4594, 1046960 + 4 * dword_5d4594_1046932));
		nox_xxx_bookDrawString_43FA80_43FD80(0, v26, v55, v23, 128, 0);
		v63 = v23 + v20 + v68 + 2;
		v61 = (108 - v18) / 2 + v66 + 24;
		v27 = nox_xxx_bookGetCreatureImg_427400(*getMemU32Ptr(0x5D4594, 1046960 + 4 * dword_5d4594_1046932));
		nox_client_drawImageAt_47D2C0(v27, v61, v63);
		v28 = (unsigned short*)nox_xxx_guideGetDescById_4272E0(
			*getMemU32Ptr(0x5D4594, 1046960 + 4 * dword_5d4594_1046932));
		v29 = v28;
		v30 = v67 + 52;
		if (v28) {
			nox_xxx_drawGetStringSize_43F840(0, v28, 0, WideCharStr, 92);
			v31 = *(uint32_t*)WideCharStr;
			v32 = v66 + 153;
			goto LABEL_53;
		}
	} else {
		if (!*(uint8_t*)(dword_5d4594_1047516 + 2251)) {
			sub_425450(*getMemU32Ptr(0x5D4594, 1046960 + 4 * dword_5d4594_1046932));
			v33 = (unsigned short*)nox_xxx_abilityGetName_0_425260(
				*getMemU32Ptr(0x5D4594, 1046960 + 4 * dword_5d4594_1046932));
			nox_xxx_bookGetStringSize_43FA80(0, v33, &v70, &v68, 108);
			if (v68 <= v3) {
				v34 = (108 - v70) / 2 + v66 + 24;
			} else {
				v34 = v66 + 24;
			}
			v58 = v67 + 53;
			v56 = v34;
			v35 =
				(uint16_t*)nox_xxx_abilityGetName_0_425260(*getMemU32Ptr(0x5D4594, 1046960 + 4 * dword_5d4594_1046932));
			nox_xxx_bookDrawString_43FA80_43FD80(0, v35, v56, v58, 128, 0);
			v36 = (unsigned short*)sub_4252F0(*getMemU32Ptr(0x5D4594, 1046960 + 4 * dword_5d4594_1046932));
			v29 = v36;
			v30 = v67 + 52;
			if (!v36) {
				goto LABEL_75;
			}
			nox_xxx_drawGetStringSize_43F840(0, v36, 0, WideCharStr, 92);
			v31 = *(uint32_t*)WideCharStr;
			v32 = v66 + 153;
		LABEL_53:
			v37 = (141 - v31) / 2 + v67 + 17;
			if (v37 > v30) {
				goto LABEL_73;
			}
			goto LABEL_74;
		}
		v38 = nox_xxx_spellFlags_424A70(*getMemU32Ptr(0x5D4594, 1046960 + 4 * dword_5d4594_1046932));
		v39 = (unsigned short*)nox_xxx_spellTitle_424930(*getMemU32Ptr(0x5D4594, 1046960 + 4 * dword_5d4594_1046932));
		nox_xxx_bookGetStringSize_43FA80(0, v39, &v65, &v68, 108);
		if (v68 <= v3) {
			v40 = (108 - v65) / 2 + v66 + 24;
		} else {
			v40 = v66 + 24;
		}
		v41 = v67 + 53;
		v59 = v67 + 53;
		v57 = v40;
		v42 = (uint16_t*)nox_xxx_spellTitle_424930(*getMemU32Ptr(0x5D4594, 1046960 + 4 * dword_5d4594_1046932));
		nox_xxx_bookDrawString_43FA80_43FD80(0, v42, v57, v59, 128, 0);
		v43 = v41 + v68 + 2;
		v44 = nox_xxx_spellManaCost_4249A0(*getMemU32Ptr(0x5D4594, 1046960 + 4 * dword_5d4594_1046932), 1);
		v45 = nox_strman_loadString_40F1D0("ManaCost", 0, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1115);
		nox_swprintf(v71, L"%s ", v45);
		if (v44) {
			_itow(v44, WideCharStr, 10);
			nox_wcscat(v71, WideCharStr);
		} else if (nox_xxx_spellHasFlags_424A50(*getMemU32Ptr(0x5D4594, 1046960 + 4 * dword_5d4594_1046932), 0x800000)) {
			nox_wcscat(v71, L"0");
		} else {
			nox_wcscat(v71, L"*");
		}
		nox_xxx_drawGetStringSize_43F840(0, v71, &v65, 0, 0);
		v46 = v43 + 2;
		nox_xxx_drawStringWrap_43FAF0(0, v71, (108 - v65) / 2 + v66 + 24, v46, 128, 0);
		v47 = v46 + v3 + 2;
		if (v38 & 0x100) {
			v48 = nox_strman_loadString_40F1D0("SpellInstant", 0, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1173);
			nox_xxx_drawGetStringSize_43F840(0, v48, &v65, 0, 0);
			nox_xxx_drawStringWrap_43FAF0(0, v48, (108 - v65) / 2 + v66 + 24, v47, 128, 0);
			v47 += v3;
		}
		if (v38 & 4) {
			v49 = nox_strman_loadString_40F1D0("SpellTargeted", 0, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1181);
			nox_xxx_drawGetStringSize_43F840(0, v49, &v65, 0, 0);
			nox_xxx_drawStringWrap_43FAF0(0, v49, (108 - v65) / 2 + v66 + 24, v47, 128, 0);
			v47 += v3;
		}
		if (v38 & 8) {
			v50 = nox_strman_loadString_40F1D0("SpellAtLocation", 0, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1189);
			nox_xxx_drawGetStringSize_43F840(0, v50, &v65, 0, 0);
			nox_xxx_drawStringWrap_43FAF0(0, v50, (108 - v65) / 2 + v66 + 24, v47, 128, 0);
			v47 += v3;
		}
		if (v38 & 0x20) {
			v51 = nox_strman_loadString_40F1D0("SpellHostile", 0, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1197);
			nox_xxx_drawGetStringSize_43F840(0, v51, &v65, 0, 0);
			nox_xxx_drawStringWrap_43FAF0(0, v51, (108 - v65) / 2 + v66 + 24, v47, 128, 0);
			v47 += v3;
		}
		v64 =
			*(uint32_t*)(dword_5d4594_1047516 + 4 * *getMemU32Ptr(0x5D4594, 1046960 + 4 * dword_5d4594_1046932) + 3696);
		v52 = nox_strman_loadString_40F1D0("PowerLevel", 0, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1206);
		nox_swprintf(v71, v52, v64);
		nox_xxx_drawGetStringSize_43F840(0, v71, &v65, 0, 0);
		nox_xxx_drawStringWrap_43FAF0(0, v71, (108 - v65) / 2 + v66 + 24, v3 + v47, 128, 0);
		v53 = (unsigned short*)nox_xxx_spellDescription_424A30(
			*getMemU32Ptr(0x5D4594, 1046960 + 4 * dword_5d4594_1046932));
		v29 = v53;
		v30 = v67 + 52;
		if (v53) {
			nox_xxx_drawGetStringSize_43F840(0, v53, 0, WideCharStr, 92);
			v32 = v66 + 153;
			v37 = (141 - *(uint32_t*)WideCharStr) / 2 + v67 + 17;
			if (v37 > v30) {
			LABEL_73:
				v37 = v30;
			}
		LABEL_74:
			nox_xxx_drawStringWrap_43FAF0(0, v29, v32, v37, 92, 0);
			goto LABEL_75;
		}
	}
LABEL_75:
	if (!nox_xxx_aNox_cfg_0_587000_132132 &&
		*(int*)&dword_5d4594_1046932 >= *getMemIntPtr(0x5D4594, 1047508) - *(int*)&dword_5d4594_1047512 - 1) {
		nox_window_set_hidden(*(int*)&dword_5d4594_1046948, 1);
	}
	return 1;
}

//----- (0045CF00) --------------------------------------------------------
int nox_xxx_book_45CF00(uint32_t* a1) {
	wchar_t* v1; // eax
	wchar_t* v3; // eax
	wchar_t* v4; // eax

	if (*a1 == 1310) {
		if (!*(uint8_t*)(dword_5d4594_1047516 + 2251)) {
			v3 = nox_strman_loadString_40F1D0("ToolTipAbilityTab", 0, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1640);
			nox_xxx_cursorSetTooltip_4776B0(v3);
			return 1;
		}
		v4 = nox_strman_loadString_40F1D0("ToolTipSpellTab", 0, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1644);
		nox_xxx_cursorSetTooltip_4776B0(v4);
	} else if (*a1 == 1320) {
		v1 = nox_strman_loadString_40F1D0("ToolTipGuideTab", 0, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1649);
		nox_xxx_cursorSetTooltip_4776B0(v1);
		return 1;
	}
	return 1;
}

//----- (0045C7D0) --------------------------------------------------------
int nox_xxx_bookDrawFn_45C7D0(uint32_t* a1) {
	int v1;     // esi
	int v3;     // edi
	int v4;     // eax
	int v5;     // eax
	int v6;     // edi
	int v7;     // eax
	int v8;     // eax
	int v9;     // eax
	int v10;    // ecx
	double v11; // st7
	int v12;    // eax
	int v13;    // [esp-28h] [ebp-34h]
	int v14;    // [esp-28h] [ebp-34h]
	int v15;    // [esp-24h] [ebp-30h]
	int v16;    // [esp-20h] [ebp-2Ch]
	char v17;   // [esp-18h] [ebp-24h]
	char v18;   // [esp-18h] [ebp-24h]
	char v19;   // [esp-14h] [ebp-20h]
	char v20;   // [esp-14h] [ebp-20h]
	int v21;    // [esp-10h] [ebp-1Ch]
	int v22;    // [esp-Ch] [ebp-18h]
	int v23;    // [esp-Ch] [ebp-18h]
	int v24;    // [esp+4h] [ebp-8h]
	int v25;    // [esp+8h] [ebp-4h]

	v1 = dword_5d4594_1046652 != 0 ? 3 : 0;
	if (!dword_5d4594_1047520) {
		return 1;
	}
	if (dword_5d4594_1046648 &&
		nox_xxx_bookGet_430B40_get_mouse_prev_seq() - dword_5d4594_1046648 < (unsigned int)(2 * gameFPS())) {
		return 1;
	}
	nox_client_wndGetPosition_46AA60(a1, &v25, &v24);
	if (dword_5d4594_1046648) {
		v3 = 50;
		do {
			v19 = nox_common_randomIntMinMax_415FF0(3, 6, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1287);
			v17 = nox_common_randomIntMinMax_415FF0(2, 5, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1286);
			v16 = nox_common_randomIntMinMax_415FF0(-10, -1, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1284);
			v15 = nox_common_randomIntMinMax_415FF0(-10, 10, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1283);
			v4 = nox_common_randomIntMinMax_415FF0(0, 30, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1282);
			v13 = v24 + v4;
			v5 = nox_common_randomIntMinMax_415FF0(0, 30, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1281);
			nox_client_newScreenParticle_431540(v1, v25 + v5, v13, v15, v16, 1, v17, v19, 2, 1);
			--v3;
		} while (v3);
		nox_xxx_clientPlaySoundSpecial_452D80(795, 100);
		dword_5d4594_1046648 = 0;
	}
	v6 = 2;
	do {
		v20 = nox_common_randomIntMinMax_415FF0(2, 4, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1331);
		v18 = nox_common_randomIntMinMax_415FF0(1, 2, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1330);
		v7 = nox_common_randomIntMinMax_415FF0(0, 30, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1326);
		v14 = v24 + v7;
		v8 = nox_common_randomIntMinMax_415FF0(0, 30, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 1325);
		nox_client_newScreenParticle_431540(v1, v25 + v8, v14, 0, 0, 0, v18, v20, 1, 1);
		--v6;
	} while (v6);
	v22 = v24;
	v21 = v25;
	if (dword_5d4594_1046652 == 1) {
		v9 = nox_xxx_spellGetAbilityIcon_425310(*(int*)&dword_5d4594_1047524, 0);
	} else {
		v9 = nox_xxx_spellIcon_424A90(*(int*)&dword_5d4594_1047524);
	}
	nox_client_drawImageAt_47D2C0(v9, v21, v22);
	*(float*)&dword_5d4594_1046636 = *(float*)&dword_5d4594_1046636 + obj_5d4594_1046620.field_0;
	*(float*)&dword_5d4594_1046640 = *(float*)&dword_5d4594_1046640 + obj_5d4594_1046620.field_4;
	if ((double)*getMemIntPtr(0x5D4594, 1046668) <= *(float*)&dword_5d4594_1046636 &&
		(double)*getMemIntPtr(0x5D4594, 1046672) <= *(float*)&dword_5d4594_1046640) {
	LABEL_26:
		nox_xxx_book_45DBE0(*(void**)getMemAt(0x5D4594, 1046676), *(int*)&dword_5d4594_1047524,
							*(int*)&dword_5d4594_1046852);
		sub_45D810();
		goto LABEL_27;
	}
	if (*(float*)&dword_5d4594_1046636 >
		(double)*getMemFloatPtr(0x5D4594, 1046692 + 8 * *getMemU32Ptr(0x5D4594, 1046628))) {
		v10 = *getMemU32Ptr(0x5D4594, 1046628) + 1;
		*getMemU32Ptr(0x5D4594, 1046628) = v10;
		if (v10 < *getMemIntPtr(0x5D4594, 1046680)) {
			if (v10 <= *getMemIntPtr(0x5D4594, 1046680) - 1) {
				obj_5d4594_1046620.field_0 =
					*getMemFloatPtr(0x5D4594, 1046692 + 8 * v10) - *getMemFloatPtr(0x5D4594, 1046684 + 8 * v10);
				obj_5d4594_1046620.field_4 =
					*getMemFloatPtr(0x5D4594, 1046696 + 8 * v10) - *getMemFloatPtr(0x5D4594, 1046688 + 8 * v10);
				nox_xxx_utilNormalizeVector_509F20(&obj_5d4594_1046620);
				if (nox_win_width < 1000) {
					if (nox_win_width < 750) {
						v11 = 6.0;
					} else {
						v11 = 8.0;
					}
				} else {
					v11 = 10.0;
				}
				obj_5d4594_1046620.field_0 = obj_5d4594_1046620.field_0 * v11;
				obj_5d4594_1046620.field_4 = obj_5d4594_1046620.field_4 * v11;
			}
			goto LABEL_27;
		}
		goto LABEL_26;
	}
LABEL_27:
	v23 = nox_float2int(*(float*)&dword_5d4594_1046640);
	v12 = nox_float2int(*(float*)&dword_5d4594_1046636);
	nox_window_setPos_46A9B0(a1, v12, v23);
	return 1;
}

//----- (0045D870) --------------------------------------------------------
void sub_45D870() {
	int v1;  // esi
	int v3;  // edi
	int v4;  // ebx
	int v5;  // ebp
	int v6;  // eax
	int v7;  // [esp-30h] [ebp-38h]
	char v8; // [esp-20h] [ebp-28h]
	int v9;  // [esp+0h] [ebp-8h]
	int v10; // [esp+4h] [ebp-4h]

	if (dword_5d4594_1047520) {
		v1 = dword_5d4594_1046652 != 1 ? 0 : 3;
		v9 = ((int)*getMemU32Ptr(0x5D4594, 1046668) - nox_float2int(*(float*)&dword_5d4594_1046636)) / 50;
		v10 = ((int)*getMemU32Ptr(0x5D4594, 1046672) - nox_float2int(*(float*)&dword_5d4594_1046640)) / 50;
		v3 = nox_float2int(*(float*)&dword_5d4594_1046636);
		v4 = nox_float2int(*(float*)&dword_5d4594_1046640);
		v5 = 50;
		do {
			v8 = nox_common_randomIntMinMax_415FF0(3, 4, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 2483);
			v7 = v4 - nox_common_randomIntMinMax_415FF0(0, 30, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 2479);
			v6 = nox_common_randomIntMinMax_415FF0(0, 30, "C:\\NoxPost\\src\\Client\\Gui\\guibook.c", 2478);
			nox_client_newScreenParticle_431540(v1, v3 + v6, v7, 0, 0, 1, v8, 0, 0, 1);
			v3 += v9;
			v4 += v10;
			--v5;
		} while (v5);
		nox_xxx_book_45DBE0(*(void**)getMemAt(0x5D4594, 1046676), *(int*)&dword_5d4594_1047524,
							*(int*)&dword_5d4594_1046852);
		sub_45D810();
	}
}
