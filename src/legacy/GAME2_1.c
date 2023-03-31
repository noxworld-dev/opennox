#include "GAME2_1.h"
#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_2.h"
#include "GAME2_3.h"
#include "GAME3.h"
#include "GAME3_1.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4_1.h"
#include "GAME5_2.h"
#include "client__draw__debugdraw.h"
#include "client__draw__staticdraw.h"
#include "client__drawable__drawable.h"
#include "client__gui__window.h"
#include "common__net_list.h"
#include "common__object__modifier.h"
#include "common__system__team.h"
#include "operators.h"

#include "client__gui__gamewin__gamewin.h"
#include "client__gui__gui_ctf.h"
#include "client__gui__guicon.h"
#include "client__gui__guiinput.h"
#include "client__gui__guiinv.h"
#include "client__gui__guijourn.h"
#include "client__gui__guimeter.h"
#include "client__gui__guiquit.h"
#include "client__gui__guirank.h"
#include "client__gui__guisave.h"
#include "client__gui__guispell.h"
#include "client__gui__guisumn.h"
#include "client__gui__guitrade.h"
#include "client__gui__tooltip.h"
#include "client__video__draw_common.h"

#include "client__draw__selectdw.h"

#include "client__system__ctrlevnt.h"
#include "common/fs/nox_fs.h"
#include "common__magic__speltree.h"
#include "input_common.h"

extern uint32_t dword_5d4594_1062552;
extern uint32_t dword_5d4594_1049844;
extern uint32_t dword_5d4594_1050008;
extern uint32_t dword_5d4594_1096272;
extern uint32_t dword_5d4594_1049516;
extern uint32_t dword_5d4594_1062520;
extern uint32_t dword_5d4594_1096276;
extern uint32_t dword_5d4594_1049976;
extern uint32_t dword_5d4594_1090284;
extern uint32_t dword_5d4594_1062484;
extern uint32_t dword_5d4594_1049992;
extern uint32_t dword_5d4594_1062556;
extern uint32_t dword_5d4594_1096264;
extern uint32_t dword_5d4594_1062564;
extern uint32_t dword_5d4594_1090280;
extern uint32_t dword_5d4594_1062560;
extern uint32_t dword_5d4594_1096280;
extern uint32_t dword_587000_145672;
extern uint32_t dword_5d4594_1064868;
extern uint32_t dword_5d4594_1049996;
extern uint32_t dword_5d4594_1062492;
extern uint32_t dword_5d4594_1062496;
extern uint32_t dword_5d4594_1096260;
extern uint32_t nox_client_gui_flag_1556112;
extern uint32_t dword_5d4594_1096284;
extern uint32_t dword_587000_145664;
extern uint32_t dword_5d4594_1096288;
extern uint32_t dword_5d4594_1047936;
extern uint32_t dword_5d4594_1062488;
extern uint32_t dword_5d4594_1062468;
extern uint32_t dword_5d4594_1064860;
extern uint32_t dword_5d4594_1096252;
extern uint32_t dword_5d4594_1064864;
extern uint32_t dword_587000_136184;
extern uint32_t dword_5d4594_1049532;
extern uint32_t dword_5d4594_1049484;
extern uint32_t dword_5d4594_1062516;
extern uint32_t nox_client_translucentFrontWalls_805844;
extern uint64_t qword_581450_9512;
extern uint64_t qword_581450_9544;
extern uint32_t dword_5d4594_1090276;
extern uint32_t dword_5d4594_1062476;
extern uint32_t dword_5d4594_1047932;
extern uint32_t dword_5d4594_1049512;
extern uint32_t nox_client_highResFloors_154952;
extern uint32_t dword_5d4594_1062528;
extern uint32_t dword_5d4594_1062524;
extern uint32_t dword_5d4594_251540;
extern uint32_t dword_5d4594_1064856;
extern uint32_t dword_5d4594_1049856;
extern uint32_t dword_5d4594_1049520;
extern uint32_t nox_client_highResFrontWalls_80820;
extern uint32_t dword_5d4594_1049800_inventory_click_row_index;
extern uint32_t nox_xxx_minimap_587000_149232;
extern uint32_t nox_gameDisableMapDraw_5d4594_2650672;
extern uint32_t dword_5d4594_1062456;
extern uint32_t dword_5d4594_1063636;
extern uint32_t dword_5d4594_1049796_inventory_click_column_index;
extern uint32_t dword_5d4594_1049508;
extern nox_window* dword_5d4594_1090048;
extern uint32_t dword_5d4594_1049500;
extern uint32_t dword_5d4594_1062512;
extern uint32_t dword_5d4594_1049864;
extern uint32_t dword_5d4594_1062508;
extern uint32_t dword_5d4594_1049504;
extern uint32_t dword_5d4594_1090120;
extern uint32_t dword_5d4594_1063116;
extern uint32_t dword_5d4594_1062480;
extern uint32_t nox_player_netCode_85319C;
extern void* nox_xxx_aClosewoodengat_587000_133480;
extern int nox_win_width;
extern int nox_win_height;
extern uint32_t array_5D4594_1049872[9];

extern uint32_t nox_color_white_2523948;
extern uint32_t nox_color_blue_2650684;
extern uint32_t nox_color_yellow_2589772;
extern uint32_t nox_color_violet_2598268;
extern uint32_t nox_color_black_2650656;



nox_window* nox_win_unk5 = 0;
nox_window* dword_5d4594_1062452 = 0;

nox_window_yyy nox_windows_arr_1093036[7] = {0};

obj_5D4594_2650668_t** ptr_5D4594_2650668 = 0;
const int ptr_5D4594_2650668_cap = 128;

nox_inventory_cell_t nox_client_inventory_grid_1050020[NOX_INVENTORY_CELLS_MAX] = {0};

//----- (00460D40) --------------------------------------------------------
int sub_460D40() { return dword_5d4594_1049508 != 0; }

//----- (00460D50) --------------------------------------------------------
int sub_460D50() {
	unsigned char* v0; // edi
	uint32_t** v1;     // esi
	int v2;            // ebx
	unsigned char* v3; // esi
	int result;        // eax

	nox_xxx_windowDestroyMB_46C4E0(*(uint32_t**)&dword_5d4594_1049500);
	dword_5d4594_1049500 = 0;
	nox_xxx_windowDestroyMB_46C4E0(*(uint32_t**)&dword_5d4594_1049504);
	dword_5d4594_1049504 = 0;
	nox_xxx_windowDestroyMB_46C4E0(*(uint32_t**)&dword_5d4594_1049520);
	dword_5d4594_1049520 = 0;
	nox_xxx_windowDestroyMB_46C4E0(*(uint32_t**)&dword_5d4594_1049508);
	dword_5d4594_1049508 = 0;
	nox_xxx_windowDestroyMB_46C4E0(*(uint32_t**)&dword_5d4594_1049512);
	dword_5d4594_1049512 = 0;
	nox_xxx_windowDestroyMB_46C4E0(*(uint32_t**)&dword_5d4594_1049516);
	dword_5d4594_1049516 = 0;
	v0 = getMemAt(0x5D4594, 1048404);
	do {
		nox_xxx_windowDestroyMB_46C4E0(*(uint32_t**)v0);
		*(uint32_t*)v0 = 0;
		v1 = (uint32_t**)(v0 + 24);
		v2 = 5;
		do {
			nox_xxx_windowDestroyMB_46C4E0(*(v1 - 5));
			*(v1 - 5) = 0;
			nox_xxx_windowDestroyMB_46C4E0(*v1);
			*v1 = 0;
			++v1;
			--v2;
		} while (v2);
		v0 += 256;
	} while ((int)v0 < (int)getMemAt(0x5D4594, 1049684));
	nox_xxx_windowDestroyMB_46C4E0(*(uint32_t**)getMemAt(0x5D4594, 1048148));
	*getMemU32Ptr(0x5D4594, 1048148) = 0;
	v3 = getMemAt(0x5D4594, 1048152);
	do {
		result = nox_xxx_windowDestroyMB_46C4E0(*(uint32_t**)v3);
		*(uint32_t*)v3 = 0;
		v3 += 4;
	} while ((int)v3 < (int)getMemAt(0x5D4594, 1048164));
	dword_5d4594_1049532 = 0;
	*getMemU32Ptr(0x5D4594, 1047928) = 0;
	dword_5d4594_1047932 = 0;
	return result;
}

//----- (00460E60) --------------------------------------------------------
int nox_xxx_cliPrepareGameplay1_460E60() {
	int result; // eax

	if (sub_460D40()) {
		sub_460D50();
	}
	result = nox_xxx_quickBarCreate_45E190();
	if (result) {
		sub_460EA0(nox_client_getRenderGUI());
		result = 1;
	}
	return result;
}

//----- (00460EA0) --------------------------------------------------------
int sub_460EA0(int a1) { return sub_460B90(a1); }

//----- (00460EB0) --------------------------------------------------------
void sub_460EB0(int a1, char a2) {
	if (a1 < 0 || a1 >= 140) {
		return;
	}
	*getMemU8Ptr(0x5D4594, 1049544 + a1) = a2;
}

//----- (00461010) --------------------------------------------------------
void sub_461010() {
	if (!dword_5d4594_1049484) {
		return;
	}
	nox_window_set_hidden(*getMemIntPtr(0x5D4594, 1048148), 1);
	nox_window_set_hidden(*(int*)&dword_5d4594_1049512, 0);
	sub_46AE10(*(int*)&dword_5d4594_1049500, 0);
	nox_xxx_clientPlaySoundSpecial_452D80(797, 100);
	dword_5d4594_1049484 = 0;
}

//----- (00461060) --------------------------------------------------------
void sub_461060() {
	if (dword_5d4594_1049484 == 1) {
		sub_461010();
		return;
	}
	if (*getMemU32Ptr(0x5D4594, 1049476) == 1) {
		nox_xxx_quickBarClose_4606B0();
	}
	nox_window_set_hidden(*getMemIntPtr(0x5D4594, 1048148), 0);
	nox_window_set_hidden(*(int*)&dword_5d4594_1049512, 1);
	sub_46AE10(*(int*)&dword_5d4594_1049500, 1);
	nox_xxx_clientPlaySoundSpecial_452D80(796, 100);
	dword_5d4594_1049484 = 1;
}

//----- (00461090) --------------------------------------------------------
char* sub_461090(int a1, int a2) {
	int v2;       // edx
	char* result; // eax

	v2 = gameFrame();
	result = (char*)getMemAt(0x5D4594, 1047764 + 24*1 + 20);
	do {
		if (*((uint32_t*)result - 5) == a1) {
			*(uint32_t*)result = a2 == 0 ? v2 : 0;
			*((uint32_t*)result - 3) = a2;
		}
		result += 24;
	} while ((int)result < (int)getMemAt(0x5D4594, 1047928));
	return result;
}

//----- (004610D0) --------------------------------------------------------
char* sub_4610D0(unsigned char a1) {
	int* v1;      // esi
	char* result; // eax

	if (a1 != 6) {
		return sub_461090(*getMemU32Ptr(0x5D4594, 1047764 + 24*a1), 1);
	}
	v1 = getMemIntPtr(0x5D4594, 1047764 + 24*1);
	do {
		result = sub_461090(*v1, 1);
		v1 += 6;
	} while ((int)v1 < (int)getMemAt(0x5D4594, 1047908));
	return result;
}

//----- (00461120) --------------------------------------------------------
char* sub_461120(int a1, int a2) {
	int v2;       // edx
	char* result; // eax

	v2 = 1 << a1;
	result = (char*)getMemAt(0x5D4594, 1047764 + 24*1 + 12);
	do {
		if (*((uint32_t*)result - 3) == a1) {
			if (a2) {
				*(uint32_t*)result |= v2;
			} else {
				*(uint32_t*)result &= ~v2;
			}
		}
		result += 24;
	} while ((int)result < (int)getMemAt(0x5D4594, 1047920));
	return result;
}

//----- (00461160) --------------------------------------------------------
int sub_461160(int a1) {
	int v1;            // edx
	unsigned char* v2; // eax

	v1 = 1;
	v2 = getMemAt(0x5D4594, 1047764 + 24*1);
	while (*(uint32_t*)v2 != a1) {
		v2 += 24;
		++v1;
		if ((int)v2 >= (int)getMemAt(0x5D4594, 1047908)) {
			return 0;
		}
	}
	return ((1 << a1) & *getMemU32Ptr(0x5D4594, 1047764 + 24*v1 + 12)) != 0;
}

//----- (004611A0) --------------------------------------------------------
int sub_4611A0() { return dword_5d4594_1047932; }

//----- (004611B0) --------------------------------------------------------
int sub_4611B0() {
	int result; // eax

	result = dword_5d4594_1047936;
	if (dword_5d4594_1047936) {
		result = nox_xxx_clientSendAbil_45DAF0(*(int*)&dword_5d4594_1047936);
		dword_5d4594_1047936 = 0;
		dword_5d4594_1047932 = 0;
	}
	return result;
}

//----- (004611E0) --------------------------------------------------------
void nox_xxx_netAbilityRewardCli_4611E0(int a1, int a2, char* a3) {
	unsigned char* v3; // esi

	if (a1 >= 1 && a1 < 6) {
		v3 = getMemAt(0x5D4594, 1047764 + 24*1 + 16);
		do {
			if (*((uint32_t*)v3 - 4) == a1 && *(uint32_t*)v3 != a2) {
				if (nox_common_gameFlags_check_40A5C0(2) && *getMemU32Ptr(0x8531A0, 2576)) {
					*(uint32_t*)(*getMemU32Ptr(0x8531A0, 2576) + 4 * a1 + 3696) = a2;
				}
				*(uint32_t*)v3 = a2;
				if (a2) {
					nox_xxx_abilityReward_45D290(a1, a3, (int)a3);
				}
			}
			v3 += 24;
		} while ((int)v3 < (int)getMemAt(0x5D4594, 1047924));
	}
}

//----- (00461250) --------------------------------------------------------
int nox_xxx_buttonFindFirstEmptySlot_461250() {
	int v0;       // ecx
	int v1;       // esi
	uint32_t* v2; // eax

	v0 = *(unsigned char*)((uint32_t)nox_xxx_aClosewoodengat_587000_133480 + 200);
	do {
		v1 = 0;
		v2 = (uint32_t*)((uint32_t)nox_xxx_aClosewoodengat_587000_133480 + 40 * v0);
		do {
			if (!*v2) {
				nox_xxx_clientUpdateButtonRow_45E110(v0);
				return v1;
			}
			++v1;
			v2 += 2;
		} while (v1 < 5);
		if (++v0 >= 5) {
			v0 = 0;
		}
	} while (v0 != *(unsigned char*)((uint32_t)nox_xxx_aClosewoodengat_587000_133480 + 200));
	return -1;
}

//----- (004612A0) --------------------------------------------------------
int sub_4612A0() {
	int result;  // eax
	uint32_t* i; // ecx

	result = 0;
	for (i = (uint32_t*)((uint32_t)nox_xxx_aClosewoodengat_587000_133480 +
						 40 * *(unsigned char*)((uint32_t)nox_xxx_aClosewoodengat_587000_133480 + 200));
		 *i; i += 2) {
		if (++result >= 5) {
			return -1;
		}
	}
	return result;
}

//----- (004612D0) --------------------------------------------------------
int nox_xxx_buttonHaveSpellInBarMB_4612D0(int a1) {
	int v1;       // edx
	int v2;       // eax
	uint32_t* v3; // ecx

	v1 = *(unsigned char*)((uint32_t)nox_xxx_aClosewoodengat_587000_133480 + 200);
	do {
		v2 = 0;
		v3 = (uint32_t*)((uint32_t)nox_xxx_aClosewoodengat_587000_133480 + 40 * v1);
		do {
			if (*v3 == a1) {
				return 1;
			}
			++v2;
			v3 += 2;
		} while (v2 < 5);
		if (++v1 >= 5) {
			v1 = 0;
		}
	} while (v1 != *(unsigned char*)((uint32_t)nox_xxx_aClosewoodengat_587000_133480 + 200));
	return 0;
}

//----- (00461320) --------------------------------------------------------
void nox_xxx_buttonSetImgMB_461320(int a1, uint32_t* a2) {
	if (a2) {
		if (a1 >= 0 && a1 < 5) {
			nox_client_wndGetPosition_46AA60(
				*(uint32_t**)((uint32_t)nox_xxx_aClosewoodengat_587000_133480 + 4 * a1 + 212), a2, a2 + 1);
		}
	}
}

//----- (00461360) --------------------------------------------------------
int sub_461360(int a1) {
	int v1;     // edx
	int v2;     // ecx
	int v3;     // ebx
	int v4;     // esi
	int result; // eax

	v1 = nox_xxx_aClosewoodengat_587000_133480;
	v2 = *(unsigned char*)((uint32_t)nox_xxx_aClosewoodengat_587000_133480 + 200);
	v3 = *(unsigned char*)((uint32_t)nox_xxx_aClosewoodengat_587000_133480 + 200);
	do {
		v4 = 5;
		result = 40 * v2;
		do {
			if (*(uint32_t*)(result + v1) == a1) {
				*(uint32_t*)(result + v1) = 0;
				v1 = nox_xxx_aClosewoodengat_587000_133480;
			}
			result += 8;
			--v4;
		} while (v4);
		if (++v2 >= 5) {
			v2 = 0;
		}
	} while (v2 != v3);
	return result;
}

//----- (00461400) --------------------------------------------------------
int sub_461400() {
	int i;      // esi
	int result; // eax
	int v2;     // ecx

	for (i = 0; i < 40; i += 8) {
		result = i;
		v2 = 5;
		do {
			*(uint32_t*)(result + (uint32_t)nox_xxx_aClosewoodengat_587000_133480) =
				*getMemU32Ptr(0x5D4594, 1047564 + result);
			*(uint8_t*)(result + (uint32_t)nox_xxx_aClosewoodengat_587000_133480 + 4) =
				getMemByte(0x5D4594, 1047568 + result);
			result += 40;
			--v2;
		} while (v2);
	}
	return result;
}

//----- (00461440) --------------------------------------------------------
int sub_461440(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 1049688) = a1;
	return result;
}

//----- (00461450) --------------------------------------------------------
int sub_461450() { return *getMemU32Ptr(0x5D4594, 1049688); }

//----- (00461460) --------------------------------------------------------
void nox_xxx_playerInitColors_461460(nox_playerInfo* pl) {
	int a1 = pl;
	int v1;     // eax
	char v2;    // cl
	char v3;    // dl
	int v4;     // eax
	char v5;    // cl
	char v6;    // dl
	int v7;     // eax
	char v8;    // cl
	char v9;    // dl
	int v10;    // eax
	char v11;   // cl
	char v12;   // dl

	v1 = nox_color_rgb_4344A0(*(uint8_t*)(a1 + 2253), *(uint8_t*)(a1 + 2254), *(uint8_t*)(a1 + 2255));
	v2 = *(uint8_t*)(a1 + 2257);
	v3 = *(uint8_t*)(a1 + 2256);
	*(uint32_t*)(a1 + 2296) = v1;
	v4 = nox_color_rgb_4344A0(v3, v2, *(uint8_t*)(a1 + 2258));
	v5 = *(uint8_t*)(a1 + 2260);
	v6 = *(uint8_t*)(a1 + 2259);
	*(uint32_t*)(a1 + 2292) = v4;
	v7 = nox_color_rgb_4344A0(v6, v5, *(uint8_t*)(a1 + 2261));
	v8 = *(uint8_t*)(a1 + 2263);
	v9 = *(uint8_t*)(a1 + 2262);
	*(uint32_t*)(a1 + 2300) = v7;
	v10 = nox_color_rgb_4344A0(v9, v8, *(uint8_t*)(a1 + 2264));
	v11 = *(uint8_t*)(a1 + 2266);
	v12 = *(uint8_t*)(a1 + 2265);
	*(uint32_t*)(a1 + 2304) = v10;
	*(uint32_t*)(a1 + 2308) = nox_color_rgb_4344A0(v12, v11, *(uint8_t*)(a1 + 2267));
	*(uint32_t*)(a1 + 2312) = nox_color_white_2523948;
}

//----- (00461520) --------------------------------------------------------
char* sub_461520() {
	char* result; // eax
	int i;        // esi

	result = nox_common_playerInfoGetFirst_416EA0();
	for (i = (int)result; result; i = (int)result) {
		nox_xxx_playerInitColors_461460(i);
		result = nox_common_playerInfoGetNext_416EE0(i);
	}
	return result;
}

//----- (00461550) --------------------------------------------------------
int nox_xxx_clientSetAltWeapon_461550(int a1) {
	if (dword_5d4594_1062480) {
		dword_5d4594_1062484 = *(uint32_t*)(dword_5d4594_1062480 + 4);
	} else {
		dword_5d4594_1062484 = 0;
	}
	dword_5d4594_1062480 = a1;
	sub_4619F0();
	if (!dword_5d4594_1062480) {
		return nox_xxx_clientReportSecondaryWeapon_4BF010(0);
	}
	*(uint32_t*)(**(uint32_t**)&dword_5d4594_1062480 + 128) = *(uint32_t*)(a1 + 4);
	*(uint32_t*)(dword_5d4594_1062480 + 136) = 1;
	return nox_xxx_clientReportSecondaryWeapon_4BF010(**(uint32_t**)&dword_5d4594_1062480);
}

//----- (004615C0) --------------------------------------------------------
int sub_4615C0() {
	int v0; // eax
	int v1; // ecx

	v0 = *getMemU32Ptr(0x5D4594, 1063640);
	if (!*getMemU32Ptr(0x5D4594, 1063640)) {
		v0 = nox_xxx_getTTByNameSpriteMB_44CFC0("Bow");
		*getMemU32Ptr(0x5D4594, 1063640) = v0;
	}
	if (!array_5D4594_1049872[8]) {
		return array_5D4594_1049872[7];
	}
	v1 = array_5D4594_1049872[8];
	while (*(uint32_t*)(v1 + 108) != v0) {
		v1 = *(uint32_t*)(v1 + 368);
		if (!v1) {
			return array_5D4594_1049872[7];
		}
	}
	return array_5D4594_1049872[8];
}

//----- (00461600) --------------------------------------------------------
int sub_461600(int a1) {
	int* v1;    // ecx
	int result; // eax

	v1 = &array_5D4594_1049872;
	while (1) {
		result = *v1;
		if (*v1) {
			break;
		}
	LABEL_5:
		++v1;
		if ((int)v1 >= &array_5D4594_1049872[9]) {
			return 0;
		}
	}
	while (*(uint32_t*)(result + 108) != a1) {
		result = *(uint32_t*)(result + 368);
		if (!result) {
			goto LABEL_5;
		}
	}
	return result;
}

//----- (00461630) --------------------------------------------------------
int nox_xxx_send2ServInvenFail_461630(short a1) {
	char v3[3]; // [esp+0h] [ebp-4h]
	v3[0] = -15;
	*(uint16_t*)&v3[1] = a1;
	return nox_xxx_netClientSend2_4E53C0(31, v3, 3, 0, 0);
}

//----- (00461930) --------------------------------------------------------
int sub_461930() {
	unsigned char* v0; // ecx
	int v1;            // eax

	v0 = &array_5D4594_1049872;
	while (1) {
		v1 = *(uint32_t*)v0;
		if (*(uint32_t*)v0) {
			break;
		}
	LABEL_5:
		v0 += 4;
		if ((int)v0 >= &array_5D4594_1049872[9]) {
			return 0;
		}
	}
	while (!(*(uint32_t*)(v1 + 112) & 0x1001000)) {
		v1 = *(uint32_t*)(v1 + 368);
		if (!v1) {
			goto LABEL_5;
		}
	}
	return 1;
}

//----- (00461970) --------------------------------------------------------
int* sub_461970(int a1, int a2) {
	int* v2; // edx
	int v3;  // ecx

	if (!(nox_get_thing(a2)->pri_class & 0x4000000)) {
		v2 = nox_client_inventory_grid_1050020;
		do {
			v3 = 0;
			int* ptr = v2;
			do {
				if (*((uint8_t*)ptr + 140) && *(uint32_t*)(*ptr + 108) == a2 && *((uint8_t*)ptr + 140) < 0x20u) {
					ptr[(unsigned char)(*((uint8_t*)ptr + 140))++ + 1] = a1;
					return ptr;
				}
				++v3;
				ptr += NOX_INVENTORY_ROW_COUNT * (sizeof(nox_inventory_cell_t) / 4);
			} while (v3 < 4);
			v2 += sizeof(nox_inventory_cell_t) / 4;
		} while ((int)v2 < (int)&nox_client_inventory_grid_1050020[NOX_INVENTORY_ROW_COUNT - 1]);
	}
	return 0;
}

//----- (004619F0) --------------------------------------------------------
char* sub_4619F0() {
	char* v0;     // edi
	char* result; // eax
	int v2;       // esi
	int v3;       // ecx

	v0 = (char*)&(nox_client_inventory_grid_1050020[0].field_140);
	do {
		result = v0;
		v2 = 4;
		do {
			v3 = 0;
			if ((unsigned char)*result > 0) {
				do {
					*((uint32_t*)result - 1) = 0;
					++v3;
				} while (v3 < (unsigned char)*result);
			}
			result += NOX_INVENTORY_ROW_COUNT * sizeof(nox_inventory_cell_t);
			--v2;
		} while (v2);
		v0 += sizeof(nox_inventory_cell_t);
	} while ((int)v0 <= (int)&(nox_client_inventory_grid_1050020[NOX_INVENTORY_ROW_COUNT - 1].field_140));
	return result;
}

//----- (00461B50) --------------------------------------------------------
unsigned char* sub_461B50() {
	int v0;                // ebx
	unsigned char* result; // eax
	int v2;                // ebp
	int v3;                // ecx
	int v4;                // edi
	int v5;                // esi
	int v7;                // eax
	unsigned char* v8;     // edx
	unsigned char* v9;     // eax
	int v10;               // ecx
	int v11;               // ecx
	int v12;               // edx
	int i;                 // eax
	int v14;               // ebp
	bool v15;              // cc
	int j;                 // esi
	int v17;               // edx
	int v18;               // ecx
	int* v19;              // [esp+10h] [ebp-38h]
	unsigned char* v20;    // [esp+14h] [ebp-34h]
	int* v21;              // [esp+18h] [ebp-30h]
	int v22;               // [esp+1Ch] [ebp-2Ch]
	int v23;               // [esp+20h] [ebp-28h]
	int v24;               // [esp+24h] [ebp-24h]
	int v25;               // [esp+28h] [ebp-20h]
	int* v26;              // [esp+2Ch] [ebp-1Ch]
	int v27;               // [esp+30h] [ebp-18h]
	unsigned char* v28;    // [esp+38h] [ebp-10h]
	unsigned char* v29;    // [esp+3Ch] [ebp-Ch]
	int v30;               // [esp+40h] [ebp-8h]

	v0 = 0;
	result = &(nox_client_inventory_grid_1050020[0].field_136);
	v25 = 0;
	v26 = &(nox_client_inventory_grid_1050020[0].field_136);
LABEL_2:
	v2 = 0;
	v24 = 0;
	v21 = (int*)(result - 136);
	v20 = result;
	v19 = (int*)(result + 4);
	while (*(uint8_t*)v19) {
	LABEL_35:
		v24 = ++v2;
		v19 += NOX_INVENTORY_ROW_COUNT * (sizeof(nox_inventory_cell_t) / 4);
		v20 += NOX_INVENTORY_ROW_COUNT * sizeof(nox_inventory_cell_t);
		v21 += NOX_INVENTORY_ROW_COUNT * (sizeof(nox_inventory_cell_t) / 4);
		if (v2 >= 4) {
			result += sizeof(nox_inventory_cell_t);
			v25 = ++v0;
			v26 = (int*)result;
			if ((int)result >= (int)&(nox_client_inventory_grid_1050020[NOX_INVENTORY_ROW_COUNT - 1].field_136)) {
				return result;
			}
			goto LABEL_2;
		}
	}
	v3 = v0;
	v27 = v0;
	if ((int)result < (int)&(nox_client_inventory_grid_1050020[NOX_INVENTORY_ROW_COUNT - 1].field_136)) {
	LABEL_5:
		if (v3 == v0) {
			v4 = v2;
			v22 = v2;
		} else {
			v4 = 0;
			v22 = 0;
		}
		result = &(nox_client_inventory_grid_1050020[v3 + NOX_INVENTORY_ROW_COUNT * v4].field_140);
		while (!*result) {
			++v4;
			result += NOX_INVENTORY_ROW_COUNT * sizeof(nox_inventory_cell_t);
			v22 = v4;
			if (v4 >= 4) {
				v27 = ++v3;
				if (v3 >= 20) {
					goto LABEL_38;
				}
				goto LABEL_5;
			}
		}
		v5 = v3 + NOX_INVENTORY_ROW_COUNT * v4;
		int v6 = v5;
		v7 = nox_client_inventory_grid_1050020[v5].field_0;
		v8 = &nox_client_inventory_grid_1050020[v5];
		v29 = &nox_client_inventory_grid_1050020[v5];
		v30 = *(uint32_t*)(v7 + 108);
		if (!(*(uint32_t*)(v7 + 112) & 0x4000000)) {
			v9 = &(nox_client_inventory_grid_1050020[0].field_140);
			v23 = 0;
			v28 = &(nox_client_inventory_grid_1050020[0].field_140);
			while (1) {
				v10 = 0;
				while (!*v9 || *v9 == 32 || *(uint32_t*)(*((uint32_t*)v9 - 35) + 108) != v30 ||
					   v10 == v4 && v23 == v27) {
					++v10;
					v9 += NOX_INVENTORY_ROW_COUNT * sizeof(nox_inventory_cell_t);
					if (v10 >= 4) {
						goto LABEL_28;
					}
				}
				v11 = v23 + NOX_INVENTORY_ROW_COUNT * v10;
				v12 = nox_client_inventory_grid_1050020[v11].field_140;
				for (i = nox_client_inventory_grid_1050020[v6].field_140; i > 0; v6 = v5) {
					if (v12 == 32) {
						break;
					}
					--i;
					v14 = v12++ + v11;
					*(uint32_t*)((uint8_t*)nox_client_inventory_grid_1050020 + 4 + 4 * (v14 + 36 * v11)) =
						*(uint32_t*)((uint8_t*)nox_client_inventory_grid_1050020 + 4 + 4 * (i + v5 + 36 * v5));
					v4 = v22;
				}
				nox_client_inventory_grid_1050020[v11].field_140 = v12;
				if (i <= 0) {
					nox_client_inventory_grid_1050020[v6].field_140 = 0;
					nox_xxx_spriteDelete_45A4B0(*(uint64_t**)v29);
					v0 = v25;
					*(uint32_t*)v29 = 0;
					v2 = v24 - 1;
					v21 -= NOX_INVENTORY_ROW_COUNT * (sizeof(nox_inventory_cell_t) / 4);
					result = (unsigned char*)v26;
					v19 -= NOX_INVENTORY_ROW_COUNT * (sizeof(nox_inventory_cell_t) / 4);
					v20 -= NOX_INVENTORY_ROW_COUNT * sizeof(nox_inventory_cell_t);
					goto LABEL_35;
				}
				nox_client_inventory_grid_1050020[v6].field_140 = i;
			LABEL_28:
				v9 = v28 + sizeof(nox_inventory_cell_t);
				v15 = (int)(v28 + sizeof(nox_inventory_cell_t)) <
					  (int)&(nox_client_inventory_grid_1050020[NOX_INVENTORY_ROW_COUNT - 1].field_140);
				++v23;
				v28 += sizeof(nox_inventory_cell_t);
				if (v15) {
					continue;
				}
				break;
			}
			v2 = v24;
			v8 = &nox_client_inventory_grid_1050020[v5];
		}
		memcpy(v21, v8, sizeof(nox_inventory_cell_t));
		if (*(uint32_t*)v20) {
			dword_5d4594_1062480 = v21;
		}
		result = (unsigned char*)v26;
		nox_client_inventory_grid_1050020[v6].field_140 = 0;
		*(uint32_t*)v8 = 0;
		nox_client_inventory_grid_1050020[v6].field_132 = 0;
		v0 = v25;
		goto LABEL_35;
	}
LABEL_38:
	for (j = v0; j < NOX_INVENTORY_ROW_COUNT - 1; ++j) {
		if (j == v0) {
			v17 = v2;
		} else {
			v17 = 0;
		}
		v18 = 4 - v17;
		result = &(nox_client_inventory_grid_1050020[j + NOX_INVENTORY_ROW_COUNT * v17].field_136);
		do {
			*((uint32_t*)result - 1) = 0;
			*(uint32_t*)result = 0;
			result += NOX_INVENTORY_ROW_COUNT * sizeof(nox_inventory_cell_t);
			--v18;
		} while (v18);
	}
	return result;
}

//----- (00461E60) --------------------------------------------------------
uint64_t** sub_461E60(uint64_t*** a1) {
	uint64_t** v1;     // eax
	int v2;            // edi
	int v3;            // ecx
	uint64_t** result; // eax

	v1 = *a1;
	v2 = (int)a1[1];
	if (v2 < *((unsigned char*)*a1 + 140) - 1) {
		v3 = 4 * v2 + 4;
		do {
			++v2;
			*(uint64_t**)((char*)v1 + v3) = *(uint64_t**)((char*)v1 + v3 + 4);
			v1 = *a1;
			v3 += 4;
		} while (v2 < *((unsigned char*)*a1 + 140) - 1);
	}
	if (!--*((uint8_t*)*a1 + 140)) {
		nox_xxx_spriteDelete_45A4B0(**a1);
		**a1 = 0;
	}
	result = (uint64_t**)(*a1)[34];
	if (result) {
		nox_xxx_clientSetAltWeapon_461550(0);
		result = *a1;
		(*a1)[34] = 0;
	}
	return result;
}

//----- (00461EF0) --------------------------------------------------------
char* sub_461EF0(int a1) {
	int row_idx = 0;
	do {
		int col_idx = 0;
		do {
			const nox_inventory_cell_t* p_item = &nox_client_inventory_grid_1050020[row_idx + NOX_INVENTORY_ROW_COUNT * col_idx];
			const int field140_val = p_item->field_140;
			if (field140_val > 0) {
				const uint32_t* p_maybe_stack_items = &p_item->field_4;
				for (int maybe_stack_idx = 0; maybe_stack_idx < field140_val; ++maybe_stack_idx) {
					if (*(p_maybe_stack_items + maybe_stack_idx) == a1) {
						*getMemU32Ptr(0x5D4594, 1049792) = maybe_stack_idx;
						const char* result = (char*)getMemAt(0x5D4594, 1049788);
						*getMemU32Ptr(0x5D4594, 1049788) = p_item;
						return result;
					}
				}
			}
			++col_idx;
		} while (col_idx < NOX_INVENTORY_COL_COUNT);
		++row_idx;
	} while (row_idx <= NOX_INVENTORY_ROW_COUNT);

	return 0;
}

//----- (00461F90) --------------------------------------------------------
int sub_461F90(int a1) {
	int v1;            // ecx
	unsigned char* v2; // eax
	int v3;            // esi
	int v5;            // eax
	int v6;            // eax
	int v7;            // eax

	v1 = 0;
	v2 = &array_5D4594_1049872;
	while (1) {
		v3 = *(uint32_t*)v2;
		if (*(uint32_t*)v2) {
			break;
		}
	LABEL_5:
		v2 += 4;
		++v1;
		if ((int)v2 >= &array_5D4594_1049872[9]) {
			return 0;
		}
	}
	while (*(uint32_t*)(v3 + 128) != a1) {
		v3 = *(uint32_t*)(v3 + 368);
		if (!v3) {
			goto LABEL_5;
		}
	}
	v5 = *(uint32_t*)(v3 + 372);
	if (v5) {
		*(uint32_t*)(v5 + 368) = *(uint32_t*)(v3 + 368);
	} else {
		array_5D4594_1049872[v1] = *(uint32_t*)(v3 + 368);
	}
	v6 = *(uint32_t*)(v3 + 368);
	if (v6) {
		*(uint32_t*)(v6 + 372) = *(uint32_t*)(v3 + 372);
	}
	v7 = *(uint32_t*)(v3 + 112);
	if (v7 & 0x1000 || nox_xxx_ammoCheck_415880(*(char**)(v3 + 108)) == 2 ||
		nox_xxx_ammoCheck_415880(*(char**)(v3 + 108)) == 128) {
		sub_470D70();
	}
	return v3;
}

//----- (004622E0) --------------------------------------------------------
int sub_4622E0(int a1) {
	int v1;     // edi
	int result; // eax

	v1 = *(uint32_t*)(a1 + 112);
	if (*(uint32_t*)(a1 + 112) & 0x1000000 && *(uint8_t*)(a1 + 116) & 2) {
		return 0;
	}
	if (!(v1 & 0x2000000) || (result = 1, !(*(uint8_t*)(a1 + 116) & 1))) {
		if (v1 & 0x2000000) {
			if (*(uint32_t*)(a1 + 116) & 0x144) {
				return 2;
			}
			if (*(uint8_t*)(a1 + 116) & 0x90) {
				return 3;
			}
			if (*(uint8_t*)(a1 + 116) & 0x20) {
				return 4;
			}
			if (*(uint8_t*)(a1 + 116) & 2) {
				return 8;
			}
			if (*(uint8_t*)(a1 + 116) & 8) {
				return 5;
			}
		}
		if (*(uint32_t*)(a1 + 112) & 0x1000000) {
			if (*(uint8_t*)(a1 + 116) & 4) {
				return 8;
			}
			return 7;
		}
		if (v1 & 0x1000) {
			return 7;
		}
		result = 9;
	}
	return result;
}

//----- (004623B0) --------------------------------------------------------
int nox_xxx_clientEquip_4623B0(int a1) {
	char v3[3]; // [esp+0h] [ebp-4h]
	v3[0] = 117;
	*(uint16_t*)&v3[1] = nox_xxx_netGetUnitCodeCli_578B00(a1);
	return nox_netlist_addToMsgListCli_40EBC0(31, 0, v3, 3);
}

//----- (004623E0) --------------------------------------------------------
uint32_t* sub_4623E0(uint32_t* a1, int a2) {
	int v2;           // ebx
	uint32_t* result; // eax
	int v4;           // ecx
	int v5;           // ecx

	if (!(a1[28] & 0x2000000)) {
		goto LABEL_19;
	}
	v2 = a1[29];
	if (v2 & 0x140) {
		result = (uint32_t*)array_5D4594_1049872[a2];
		if (!result) {
			goto LABEL_19;
		}
		while (result[92]) {
			result = (uint32_t*)result[92];
		}
		if (!result) {
			goto LABEL_19;
		}
		if (v2 & 0x40) {
			if (result[28] & 0x2000000) {
				v4 = result[29];
				if (v4 & 0x100) {
					result = (uint32_t*)result[93];
				}
			}
		}
	} else {
		if (!(v2 & 0x10)) {
			goto LABEL_19;
		}
		result = (uint32_t*)array_5D4594_1049872[a2];
		if (!result) {
			goto LABEL_19;
		}
		while (result[92]) {
			result = (uint32_t*)result[92];
		}
	}
	if (result) {
		v5 = result[92];
		if (v5) {
			*(uint32_t*)(v5 + 372) = a1;
		}
		a1[92] = result[92];
		result[92] = a1;
		a1[93] = result;
		return result;
	}
LABEL_19:
	a1[93] = 0;
	a1[92] = array_5D4594_1049872[a2];
	result = *(uint32_t**)&array_5D4594_1049872[a2];
	if (result) {
		result[93] = a1;
	}
	array_5D4594_1049872[a2] = a1;
	return result;
}

//----- (004624D0) --------------------------------------------------------
int sub_4624D0(int a1) {
	int result; // eax
	int v2;     // edi
	int* v3;    // eax
	int* v4;    // esi

	result = sub_461F90(a1);
	v2 = result;
	if (!result) {
		return result;
	}
	v3 = (int*)sub_461EF0(a1);
	v4 = v3;
	if (!v3) {
		return nox_xxx_spriteDelete_45A4B0((uint64_t*)v2);
	}
	*(uint32_t*)(*v3 + 132) = 0;
	if (dword_5d4594_1062492 != v2) {
		if (nox_xxx_ammoCheck_415880(*(char**)(v2 + 108)) & 0xC && dword_5d4594_1062480 &&
			nox_xxx_ammoCheck_415880(*(char**)(**(uint32_t**)&dword_5d4594_1062480 + 108)) == 2) {
			*(uint32_t*)(dword_5d4594_1062480 + 136) = 0;
			nox_xxx_clientSetAltWeapon_461550(0);
		}
		return nox_xxx_spriteDelete_45A4B0((uint64_t*)v2);
	}
	dword_5d4594_1062492 = 0;
	if (dword_5d4594_1062480) {
		dword_5d4594_1062496 = *(uint32_t*)(v2 + 128);
		*(uint32_t*)(**(uint32_t**)&dword_5d4594_1062480 + 128) = *(uint32_t*)(dword_5d4594_1062480 + 4);
		nox_xxx_clientEquip_4623B0(**(uint32_t**)&dword_5d4594_1062480);
	} else {
		nox_xxx_clientSetAltWeapon_461550(*v3);
		*(uint32_t*)(*v4 + 136) = 1;
	}
	return nox_xxx_spriteDelete_45A4B0((uint64_t*)v2);
}

//----- (004625D0) --------------------------------------------------------
int sub_4625D0(uint32_t* a1) {
	short* v2; // eax
	int v3;    // [esp+0h] [ebp-10h]
	int v4;    // [esp+4h] [ebp-Ch]
	int v5;    // [esp+8h] [ebp-8h]
	int v6;    // [esp+Ch] [ebp-4h]

	if (dword_5d4594_1049864 == 5) {
		return 1;
	}
	nox_client_wndGetPosition_46AA60(a1, &v3, &v4);
	nox_window_get_size((int)a1, &v5, &v6);
	if (v4 + v6 > 0) {
		nox_xxx_drawSetTextColor_434390(nox_color_white_2523948);
		if (dword_5d4594_1062480 && **(uint32_t**)&dword_5d4594_1062480) {
			*(uint32_t*)(**(uint32_t**)&dword_5d4594_1062480 + 12) = v3 + v5 / 2;
			*(uint32_t*)(**(uint32_t**)&dword_5d4594_1062480 + 16) = v4 + v6 / 2;
			(*(void (**)(unsigned char*, uint32_t))(**(uint32_t**)&dword_5d4594_1062480 + 300))(
				getMemAt(0x5D4594, 1049732), **(uint32_t**)&dword_5d4594_1062480);
		}
		v2 = (short*)sub_42E8E0(35, 1);
		if (v2) {
			nox_xxx_drawString_43F6E0(*(int*)&dword_5d4594_1063636, v2, v3 + 22, v4 + 41);
		}
	}
	return 1;
}

//----- (004626C0) --------------------------------------------------------
double sub_4626C0(int a1) {
	int v1; // edx
	int* i; // ecx
	int v3; // eax

	if (!a1 || !(*(uint32_t*)(a1 + 112) & 0x13001000)) {
		return 0.0;
	}
	v1 = 2;
	for (i = (int*)(a1 + 440);; ++i) {
		v3 = *i;
		if (*i) {
			if (*(void (**)(int, int, int, int))(v3 + 52) == nox_xxx_lightngEffect_4E06F0) {
				break;
			}
		}
		if (++v1 >= 4) {
			return 0.0;
		}
	}
	return *(float*)(v3 + 56);
}

//----- (00462700) --------------------------------------------------------
double sub_462700(int a1) {
	int v1; // edx
	int* i; // ecx
	int v3; // eax

	if (!a1 || !(*(uint32_t*)(a1 + 112) & 0x13001000)) {
		return 0.0;
	}
	v1 = 2;
	for (i = (int*)(a1 + 440);; ++i) {
		v3 = *i;
		if (*i) {
			if (*(uint32_t * (**)(int, int, int, int))(v3 + 52) == nox_xxx_fireEffect_4E0550) {
				break;
			}
		}
		if (++v1 >= 4) {
			return 0.0;
		}
	}
	return *(float*)(v3 + 56);
}

// 462878: variable 'v3' is possibly undefined
// 46288E: variable 'v4' is possibly undefined
// 4628A4: variable 'v5' is possibly undefined
// 4628CE: variable 'v6' is possibly undefined
// 4628E8: variable 'v7' is possibly undefined

//----- (00463370) --------------------------------------------------------
int sub_463370(uint32_t* a1, nox_point* pos, uint32_t* a3) {
	uint32_t* v5; // ecx
	int result;   // eax
	int v7;       // [esp+0h] [ebp-4h]

	nox_client_wndGetPosition_46AA60(a1, &a1, &v7);
	v5 = a3;
	*a3 = pos->x - (uint32_t)a1;
	result = pos->y - v7;
	v5[1] = result;
	return result;
}

//----- (004633B0) --------------------------------------------------------
int sub_4633B0(int a1, float* a2, float* a3) {
	int result; // eax
	int v4;     // esi
	float v5;   // [esp+0h] [ebp-10h]
	float v6;   // [esp+0h] [ebp-10h]

	result = a1;
	*a2 = *(unsigned short*)(a1 + 292);
	*a3 = *(unsigned short*)(a1 + 294);
	if (*(uint32_t*)(a1 + 112) & 0x13001000) {
		v4 = *(uint32_t*)(a1 + 436);
		if (v4) {
			if (*(float* (**)(int, int, int, int, int, float*))(v4 + 76) == sub_4E0380) {
				v5 = (double)*a2 * *(float*)(v4 + 80);
				*a2 = nox_float2int(v5);
				v6 = (double)*a3 * *(float*)(v4 + 80);
				result = nox_float2int(v6);
				*a3 = result;
			}
		}
	}
	return result;
}

//----- (00463420) --------------------------------------------------------
int sub_463420(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 1050012) = a1;
	return result;
}

//----- (00463430) --------------------------------------------------------
int nox_xxx_inventoryDrawAllMB_463430(int a1) {
	int v1;          // et1
	int v2;          // ebp
	int v3;          // esi
	int v4;          // edi
	int v5;          // eax
	int v6;          // eax
	int v7;          // ebp
	int v8;          // eax
	int v9;          // edi
	int v10;         // esi
	int v11;         // esi
	int v12;         // edi
	int v13;         // et1
	int v14;         // et1
	int2 v16;        // [esp+10h] [ebp-28h]
	wchar2_t v17[16]; // [esp+18h] [ebp-20h]

	v1 = dword_587000_136184;
	nox_window_setPos_46A9B0(*(uint32_t**)(a1 + 396), 0, v1);
	nox_client_wndGetPosition_46AA60((uint32_t*)a1, &v16, &v16.field_4);
	nox_xxx_guiFontHeightMB_43F320(0);
	v2 = 0;
	v3 = v16.field_0 + 10;
	v4 = v16.field_4 + 234;
	do {
		if ((1 << v2) & *getMemU32Ptr(0x5D4594, 1062540) && v2 != 31 && v2 != 30) {
			v5 = nox_xxx_getEnchantSpell_424920(v2);
			v6 = nox_xxx_spellIcon_424A90(v5);
			nox_client_drawImageAt_47D2C0(v6, v3, v4);
			v3 += 35;
		}
		++v2;
	} while (v2 < 32);
	v7 = 0;
	do {
		if (getMemByte(0x5D4594, 1062536) & (unsigned char)(1 << v7)) {
			v8 = sub_413420(1 << v7);
			nox_client_drawImageAt_47D2C0(v8, v3, v4);
			v3 += 35;
		}
		++v7;
	} while (v7 < 6);
	if (nox_common_gameFlags_check_40A5C0(4096) && dword_5d4594_1050008) {
		v4 += 5;
		v3 += 6;
		nox_client_drawImageAt_47D2C0(
			*(uint32_t*)(*(uint32_t*)(*(uint32_t*)(dword_5d4594_1050008 + 96) + 4) +
						 4 * (gameFrame() %
							  (unsigned int)*(unsigned char*)(*(uint32_t*)(dword_5d4594_1050008 + 96) + 8))),
			v3 - 58, v4 - 53);
		nox_swprintf(v17, L"X %d", *getMemU32Ptr(0x5D4594, 1050012));
		nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x852978, 0));
		nox_xxx_drawString_43F6E0(*(int*)&dword_5d4594_1063636, (short*)v17, v3 + 20, v4 + 9);
		*getMemU32Ptr(0x5D4594, 1049812) = v3 - 30;
		*getMemU32Ptr(0x5D4594, 1049816) = v4 - 20;
		*getMemU32Ptr(0x5D4594, 1049820) = v3 + 30;
		*getMemU32Ptr(0x5D4594, 1049824) = v4 + 20;
	}
	if (nox_common_gameFlags_check_40A5C0(4096) && sub_4BFD30()) {
		v9 = v4 + 5;
		v10 = v3 + 66;
		nox_client_drawImageAt_47D2C0(*getMemIntPtr(0x5D4594, 1050004), v10 - 64, v9 - 58);
		*getMemU32Ptr(0x5D4594, 1049828) = v10 - 30;
		*getMemU32Ptr(0x5D4594, 1049832) = v9 - 20;
		*getMemU32Ptr(0x5D4594, 1049836) = v10 + 30;
		*getMemU32Ptr(0x5D4594, 1049840) = v9 + 20;
	}
	if (getMemByte(0x5D4594, 1049868)) {
		v11 = v16.field_4 + 13;
		v12 = v16.field_0 + 254;
		if (v16.field_4 + 163 > 0) {
			nox_xxx_wndDraw_49F7F0();
			nox_client_copyRect_49F6F0(v12, v11, 260, 150);
			if (getMemByte(0x5D4594, 1049869)) {
				if (getMemByte(0x5D4594, 1049869) == 1) {
					nox_xxx_guiDrawJournal_469D40(v12, v11, *(int*)&dword_5d4594_1062512);
				}
			} else {
				nox_xxx_guiDrawInventoryTray_4643B0(v12, v11);
			}
			sub_49F860();
		}
		if (dword_5d4594_1049864 == 5) {
			sub_4627F0(&v16);
			nox_client_drawImageAt_47D2C0(*getMemIntPtr(0x5D4594, 1049912), v16.field_0, v16.field_4);
		} else {
			if (getMemByte(0x5D4594, 1049870)) {
				if (getMemByte(0x5D4594, 1049870) == 1) {
					nox_client_makePlayerStatsDlg_463880(&v16.field_0);
					nox_client_drawImageAt_47D2C0(*getMemIntPtr(0x5D4594, 1049912), v16.field_0, v16.field_4);
				}
			} else {
				sub_4BF7E0(&v16);
				nox_client_drawImageAt_47D2C0(*getMemIntPtr(0x5D4594, 1049908), v16.field_0, v16.field_4);
			}
			nox_xxx_drawSetTextColor_434390(nox_color_white_2523948);
			nox_xxx_drawStringWrap_43FAF0(0, getMemAt(0x5D4594, 1062588), v16.field_0 + 13, v16.field_4 + 17, 196, 0);
		}
	}
	if (getMemByte(0x5D4594, 1049868) == 1) {
		v14 = dword_587000_136184;
		dword_587000_136184 = v14 + 64;
		if (v14 + 64 > 0) {
			dword_587000_136184 = 0;
			*getMemU8Ptr(0x5D4594, 1049868) = 2;
		}
	} else if (getMemByte(0x5D4594, 1049868) == 3) {
		v13 = dword_587000_136184;
		dword_587000_136184 = v13 - 32;
		if (v13 - 32 <= -225) {
			dword_587000_136184 = -225;
			*getMemU8Ptr(0x5D4594, 1049868) = 0;
			if (getMemByte(0x5D4594, 1049869)) {
				if (getMemByte(0x5D4594, 1049869) == 1) {
					dword_5d4594_1062520 = dword_5d4594_1062512;
				}
			} else {
				dword_5d4594_1062516 = dword_5d4594_1062512;
			}
			*getMemU8Ptr(0x5D4594, 1049869) = 0;
			dword_5d4594_1062512 = dword_5d4594_1062516;
			nox_window_call_field_94(*(int*)&dword_5d4594_1062508, 16395, 0, 850);
			nox_window_call_field_94(*(int*)&dword_5d4594_1062508, 16394,
									 *(uint32_t*)(*(uint32_t*)(dword_5d4594_1062508 + 32) + 4) - dword_5d4594_1062512,
									 0);
			nox_xxx_wndSetIcon_46AE60(*(int*)&dword_5d4594_1062528, 0);
			sub_46AEC0(*(int*)&dword_5d4594_1062528, *(int*)&dword_5d4594_1049976);
			nox_xxx_wndSetID_46B080(*(uint32_t**)&dword_5d4594_1062528, 9105);
			*getMemU8Ptr(0x5D4594, 1049870) = 0;
			nox_xxx_wndSetIcon_46AE60(*(int*)&dword_5d4594_1062524, *(int*)&dword_5d4594_1049992);
			sub_46AEC0(*(int*)&dword_5d4594_1062524, *(int*)&dword_5d4594_1049996);
			nox_xxx_wndSetID_46B080(*(uint32_t**)&dword_5d4594_1062524, 9107);
			nox_window_set_hidden(*(int*)&dword_5d4594_1062468, 0);
		}
	}
	if (sub_467C80() && nox_xxx_playerAnimCheck_4372B0()) {
		sub_467C10();
	}
	return 1;
}

//----- (004643B0) --------------------------------------------------------
int nox_xxx_guiDrawInventoryTray_4643B0(int a1, int a2) {
	int v2;                  // ebx
	int v3;                  // esi
	unsigned char* v4;       // ebp
	int v5;                  // edi
	int v6;                  // ebx
	int v7;                  // esi
	double v8;               // st7
	double v9;               // st6
	int v10;                 // eax
	int v11;                 // edx
	int v12;                 // eax
	short v13;               // ax
	short v14;               // ax
	short v15;               // si
	bool v16;                // zf
	int result;              // eax
	int v18;                 // [esp-8h] [ebp-5Ch]
	int v19;                 // [esp-4h] [ebp-58h]
	int v20;                 // [esp+10h] [ebp-44h]
	int v21;                 // [esp+14h] [ebp-40h]
	int v22;                 // [esp+18h] [ebp-3Ch]
	unsigned char* v23;      // [esp+1Ch] [ebp-38h]
	int v24;                 // [esp+20h] [ebp-34h]
	int v25;                 // [esp+24h] [ebp-30h]
	int v26;                 // [esp+28h] [ebp-2Ch]
	int v27;                 // [esp+2Ch] [ebp-28h]
	wchar2_t WideCharStr[16]; // [esp+34h] [ebp-20h]
	unsigned char* v29;      // [esp+58h] [ebp+4h]

	v2 = a2;
	nox_client_drawImageAt_47D2C0(*getMemIntPtr(0x5D4594, 1049928), a1, a2);
	nox_itow(*(int*)&dword_5d4594_1062552, WideCharStr, 10);
	nox_xxx_drawSetTextColor_434390(nox_color_yellow_2589772);
	nox_xxx_drawGetStringSize_43F840(*(int*)&dword_5d4594_1063636, WideCharStr, &v24, 0, 0);
	nox_xxx_drawString_43F6E0(*(int*)&dword_5d4594_1063636, (short*)WideCharStr, a1 - v24 + 43, a2 + 36);
	if (dword_5d4594_1049864 == 5) {
		nox_client_drawImageAt_47D2C0(*getMemIntPtr(0x5D4594, 1049932), a1, a2 + 50);
	}
	if (sub_473670()) {
		nox_client_drawImageAt_47D2C0(*getMemIntPtr(0x5D4594, 1049936), a1, a2 + 100);
	}
	v3 = a1 + 60;
	v4 = &(nox_client_inventory_grid_1050020[0].field_140);
	v27 = a1 + 60;
	v5 = a2 - dword_5d4594_1062512;
	v20 = 0;
	v23 = &(nox_client_inventory_grid_1050020[0].field_140);
	do {
		if (v5 > v2 - 50) {
			v6 = v3;
			nox_client_drawImageAt_47D2C0(*getMemU32Ptr(0x5D4594, 1049916 + 4 * (v20 % 3)), v3, v5);
			v29 = v4;
			v22 = 4;
			while (1) {
				if (*v4) {
					v7 = *((uint32_t*)v4 - 35);
					if (v7) {
						break;
					}
				}
			LABEL_43:
				v6 += 50;
				v4 += NOX_INVENTORY_ROW_COUNT * sizeof(nox_inventory_cell_t);
				v16 = v22 == 1;
				v29 = v4;
				--v22;
				if (v16) {
					v2 = a2;
					v4 = v23;
					v3 = v27;
					goto LABEL_45;
				}
			}
			v21 = 0;
			nox_client_drawEnableAlpha_434560(1);
			nox_client_drawSetAlpha_434580(0x40u);
			v8 = (double)*(unsigned short*)(v7 + 292);
			v25 = *(unsigned short*)(v7 + 294);
			v9 = (double)v25;
			if (v8 >= v9 * *getMemDoublePtr(0x581450, 9608)) {
				if (v8 >= v9 * *(double*)&qword_581450_9544) {
					goto LABEL_16;
				}
				v10 = nox_color_yellow_2589772;
			} else {
				v10 = *getMemU32Ptr(0x85B3FC, 940);
			}
			if (v10 != 0x80000000) {
				nox_client_drawSetColor_434460(v10);
				nox_client_drawRectFilledOpaque_49CE30(v6, v5, 50, 50);
			}
		LABEL_16:
			nox_client_drawSetAlpha_434580(0x80u);
			if (*((uint32_t*)v4 - 2)) {
				v11 = *getMemU32Ptr(0x5D4594, 1049964);
				v19 = v5;
				v18 = v6;
			} else {
				if (*((uint32_t*)v4 - 1)) {
					nox_client_drawImageAt_47D2C0(*getMemIntPtr(0x5D4594, 1049968), v6, v5);
				LABEL_27:
					nox_client_drawEnableAlpha_434560(0);
					*(uint32_t*)(v7 + 16) = v5 + 25;
					*(uint32_t*)(v7 + 12) = v6 + 25;
					(*(void (**)(unsigned char*, int))(v7 + 300))(getMemAt(0x5D4594, 1049732), v7);
					if (dword_5d4594_1049864 == 6) {
						if (*(uint32_t*)(v7 + 112) & 0x13001000) {
							if ((*(uint32_t*)(v7 + 112) & 0x1000) == 4096) {
								v13 = *(uint16_t*)(v7 + 450);
								if (*(uint16_t*)(v7 + 448) < v13) {
									if (v13) {
										v21 = 1;
									}
								}
							}
						}
						v14 = *(uint16_t*)(v7 + 294);
						if ((*(uint16_t*)(v7 + 292) == v14 || !v14) && !v21) {
							nox_client_drawRectFilledAlpha_49CF10(v6, v5, 50, 50);
						}
					}
					if (*v29 > 1u) {
						nox_swprintf(WideCharStr, L"%d", *v29);
						nox_xxx_drawSetTextColor_434390(nox_color_white_2523948);
						nox_xxx_drawString_43F6E0(*(int*)&dword_5d4594_1063636, (short*)WideCharStr, v6 + 6, v5 + 6);
					}
					if (*(uint32_t*)(v7 + 112) & 0x13001000) {
						v15 = *(uint16_t*)(v7 + 448);
						if (v15 >= 0) {
							nox_swprintf(WideCharStr, L"%d", v15);
							nox_xxx_drawSetTextColor_434390(nox_color_blue_2650684);
							nox_xxx_drawGetStringSize_43F840(*(int*)&dword_5d4594_1063636, WideCharStr, &v26, 0, 0);
							nox_xxx_drawString_43F6E0(*(int*)&dword_5d4594_1063636, (short*)WideCharStr, v6 - v26 + 44,
													  v5 + 6);
						}
					}
					v4 = v29;
					goto LABEL_43;
				}
				if (*((uint32_t*)v4 - 34) != dword_5d4594_1062488) {
					goto LABEL_27;
				}
				if (!dword_5d4594_1062480) {
					goto LABEL_27;
				}
				v12 = **(uint32_t**)&dword_5d4594_1062480;
				if (!**(uint32_t**)&dword_5d4594_1062480 || !(*(uint32_t*)(v12 + 112) & 0x1000000) ||
					!(*(uint8_t*)(v12 + 116) & 0xC)) {
					goto LABEL_27;
				}
				v11 = *getMemU32Ptr(0x5D4594, 1049968);
				v19 = v5;
				v18 = v6;
			}
			nox_client_drawImageAt_47D2C0(v11, v18, v19);
			goto LABEL_27;
		}
	LABEL_45:
		v5 += 50;
		result = v2 + 150;
		if (v5 > v2 + 150) {
			break;
		}
		v4 += sizeof(nox_inventory_cell_t);
		++v20;
		v23 = v4;
	} while ((int)v4 < (int)&(nox_client_inventory_grid_1050020[NOX_INVENTORY_ROW_COUNT - 1].field_140));
	return result;
}

//----- (00464770) --------------------------------------------------------
int sub_464770(int a1, int a2, unsigned int a3) {
	int v3;     // eax
	int v4;     // esi
	int v5;     // eax
	int v6;     // eax
	int result; // eax

	if (dword_5d4594_1049864 == 6) {
		return 1;
	}
	switch (a2) {
	case 5:
	case 8:
		return 1;
	case 6:
		if (!*getMemU32Ptr(0x5D4594, 1049848)) {
			goto LABEL_25;
		}
		if (!nox_xxx_wndPointInWnd_46AAB0(*(uint32_t**)&dword_5d4594_1062456, (unsigned short)a3, a3 >> 16)) {
			goto LABEL_22;
		}
		if (dword_5d4594_1049856) {
			if (*(uint32_t*)(*getMemU32Ptr(0x5D4594, 1049848) + 112) & 0x1001000) {
				if (dword_5d4594_1062480) {
					nox_client_invAlterWeapon_4672C0();
				} else {
					dword_5d4594_1062492 = *getMemU32Ptr(0x5D4594, 1049848);
					nox_xxx_clientDequip_464B70(*getMemIntPtr(0x5D4594, 1049848));
				}
			}
		} else if (!(*(uint32_t*)(*getMemU32Ptr(0x5D4594, 1049848) + 112) & 0x1001000) ||
				   nox_client_inventory_grid_1050020[dword_5d4594_1049800_inventory_click_row_index +
									   NOX_INVENTORY_ROW_COUNT * dword_5d4594_1049796_inventory_click_column_index]
					   .field_132) {
			sub_4649B0(*getMemIntPtr(0x5D4594, 1049848), *(int*)&dword_5d4594_1049796_inventory_click_column_index,
					   *(int*)&dword_5d4594_1049800_inventory_click_row_index);
		} else {
			if (nox_xxx_ammoCheck_415880(*(char**)(*getMemU32Ptr(0x5D4594, 1049848) + 108)) == 2) {
				v3 = sub_415840((char*)4);
				v4 = sub_461600(v3);
				v5 = sub_415840((char*)8);
				v6 = sub_461600(v5);
				if (!v4 && !v6) {
					sub_4649B0(*getMemIntPtr(0x5D4594, 1049848),
							   *(int*)&dword_5d4594_1049796_inventory_click_column_index,
							   *(int*)&dword_5d4594_1049800_inventory_click_row_index);
					nox_xxx_cursorResetDraggedItem_4776A0();
					if (!dword_5d4594_1049856) {
						nox_xxx_spriteDelete_45A4B0(*(uint64_t**)getMemAt(0x5D4594, 1049848));
					}
					*getMemU32Ptr(0x5D4594, 1049848) = 0;
					dword_5d4594_1049856 = 0;
					return 1;
				}
			}
			if (dword_5d4594_1062480) {
				*(uint32_t*)(dword_5d4594_1062480 + 136) = 0;
			}
			sub_4649B0(*getMemIntPtr(0x5D4594, 1049848), *(int*)&dword_5d4594_1049796_inventory_click_column_index,
					   *(int*)&dword_5d4594_1049800_inventory_click_row_index);
			nox_xxx_clientSetAltWeapon_461550(
				&nox_client_inventory_grid_1050020[dword_5d4594_1049800_inventory_click_row_index +
									 NOX_INVENTORY_ROW_COUNT * dword_5d4594_1049796_inventory_click_column_index]);
			*(uint32_t*)(dword_5d4594_1062480 + 136) = 1;
		}
	LABEL_22:
		nox_xxx_cursorResetDraggedItem_4776A0();
		if (!dword_5d4594_1049856) {
			nox_xxx_spriteDelete_45A4B0(*(uint64_t**)getMemAt(0x5D4594, 1049848));
		}
		*getMemU32Ptr(0x5D4594, 1049848) = 0;
		dword_5d4594_1049856 = 0;
	LABEL_25:
		nox_xxx_wndClearCaptureMain_46ADE0(*(int*)&dword_5d4594_1062456);
		result = 1;
		break;
	case 7:
		if (dword_5d4594_1062480) {
			nox_client_invAlterWeapon_4672C0();
		}
		return 1;
	default:
		return 0;
	}
	return result;
}

//----- (00464B40) --------------------------------------------------------
int sub_464B40(int a1, int a2) { return a1 >= 0 && a1 < 4 && a2 >= 0 && a2 < 21; }

//----- (00464B70) --------------------------------------------------------
int nox_xxx_clientDequip_464B70(int a1) {
	char v3[3]; // [esp+0h] [ebp-4h]
	v3[0] = 118;
	*(uint16_t*)&v3[1] = nox_xxx_netGetUnitCodeCli_578B00(a1);
	return nox_netlist_addToMsgListCli_40EBC0(31, 0, v3, 3);
}

//----- (00464BA0) --------------------------------------------------------
int nox_xxx_XorEaxEaxSub_464BA0() { return 0; }

//----- (00464BB0) --------------------------------------------------------
int nox_xxx_inventoryWndProc_464BB0(int a1, int a2) { return a2 != 8 && a2 != 12 && a2 != 16; }

// 464C71: variable 'v4' is possibly undefined
// 464C8B: variable 'v5' is possibly undefined
// 464CD6: variable 'v6' is possibly undefined
// 464CF0: variable 'v7' is possibly undefined
// 464D4C: variable 'v8' is possibly undefined
// 464E24: variable 'v14' is possibly undefined
// 464E64: variable 'v15' is possibly undefined
// 464F2B: variable 'v21' is possibly undefined
// 464F52: variable 'v22' is possibly undefined
// 464F6C: variable 'v23' is possibly undefined
// 465009: variable 'v24' is possibly undefined
// 465020: variable 'v25' is possibly undefined
// 465066: variable 'v26' is possibly undefined
// 465200: variable 'v30' is possibly undefined
// 46521A: variable 'v31' is possibly undefined
// 465281: variable 'v34' is possibly undefined
// 46535F: variable 'v36' is possibly undefined
// 4653B8: variable 'v37' is possibly undefined

//----- (004657B0) --------------------------------------------------------
int nox_xxx_trade_4657B0(short a1) {
	char v2[4]; // [esp+0h] [ebp-4h]

	v2[0] = -55;
	v2[1] = 30;
	*(uint16_t*)&v2[2] = a1;
	return nox_netlist_addToMsgListCli_40EBC0(31, 0, v2, 4);
}

//----- (004657E0) --------------------------------------------------------
char nox_xxx_clientTradeMB_4657E0(uint32_t* a1) {
	int v1; // eax

	v1 = nox_xxx_pointInRect_4281F0((int2*)a1, (int4*)getMemAt(0x587000, 136352));
	if (v1) {
		int i = (a1[1] + dword_5d4594_1062512 - 13) / 50 + NOX_INVENTORY_ROW_COUNT * ((*a1 - 314) / 50);
		uint8_t n = nox_client_inventory_grid_1050020[i].field_140;
		LOBYTE(v1) = n;
		if ((uint8_t)v1) {
			LOBYTE(v1) = nox_xxx_clientTrade_465870(*(uint32_t*)((uint8_t*)&nox_client_inventory_grid_1050020[i] + 4 * n));
		}
	}
	return v1;
}
// 4657F5: variable 'v1' is possibly undefined

//----- (00465870) --------------------------------------------------------
int nox_xxx_clientTrade_465870(short a1) {
	char v2[4]; // [esp+0h] [ebp-4h]

	v2[0] = -55;
	v2[1] = 28;
	*(uint16_t*)&v2[2] = a1;
	return nox_netlist_addToMsgListCli_40EBC0(31, 0, v2, 4);
}

//----- (004658A0) --------------------------------------------------------
void sub_4658A0(int a1, int2* a2) {
	if (getMemByte(0x5D4594, 1049868) == 2) {
		if (nox_xxx_pointInRect_4281F0(a2, (int4*)getMemAt(0x587000, 136336))) {
			*getMemU32Ptr(0x5D4594, 1049848) = array_5D4594_1049872[sub_465990(a2)];
			dword_5d4594_1049856 = 1;
		} else {
			dword_5d4594_1049856 = 0;
			if (nox_xxx_pointInRect_4281F0(a2, (int4*)getMemAt(0x587000, 136368))) {
				if ((a2->field_4 - 13) / 50 == 2) {
					nox_client_toggleMap_473610();
				}
			} else if (nox_xxx_pointInRect_4281F0(a2, (int4*)getMemAt(0x587000, 136352))) {
				dword_5d4594_1049796_inventory_click_column_index = (a2->field_0 - 314) / 50;
				dword_5d4594_1049800_inventory_click_row_index = (a2->field_4 + *(int*)&dword_5d4594_1062512 - 13) / 50;
				if (sub_464B40(*(int*)&dword_5d4594_1049796_inventory_click_column_index,
							   *(int*)&dword_5d4594_1049800_inventory_click_row_index)) {
					nox_xxx_cliInventorySpriteUpd_465A30();
				}
			}
		}
	}
}
// 4658C2: variable 'v2' is possibly undefined
// 4658FF: variable 'v3' is possibly undefined
// 465934: variable 'v5' is possibly undefined

//----- (00465990) --------------------------------------------------------
int sub_465990(uint32_t* a1) {
	int v1;  // eax
	int v2;  // esi
	int v3;  // eax
	int v5;  // eax
	int2 v6; // [esp+4h] [ebp-8h]

	v1 = a1[1] - 15;
	v6.field_0 = *a1 - 11;
	v6.field_4 = v1;
	v2 = 0;
	while (1) {
		v3 = nox_xxx_pointInRect_4281F0(&v6, (int4*)getMemAt(0x587000, 136192 + 16 * v2));
		if (!v3) {
			goto LABEL_6;
		}
		if (v2 == 6) {
			break;
		}
		if (v2) {
			return v2;
		}
		if (array_5D4594_1049872[0]) {
			return 0;
		}
	LABEL_6:
		if (++v2 >= 9) {
			return -1;
		}
	}
	v5 = array_5D4594_1049872[8];
	if (!array_5D4594_1049872[8]) {
		return 5;
	}
	while (!(*(uint32_t*)(v5 + 112) & 0x2000000) || !(*(uint8_t*)(v5 + 116) & 2)) {
		v5 = *(uint32_t*)(v5 + 368);
		if (!v5) {
			return 5;
		}
	}
	return 8;
}
// 4659C7: variable 'v3' is possibly undefined

//----- (00465BE0) --------------------------------------------------------
int nox_xxx_clientDrop_465BE0(int2* a1) {
	int result; // eax
	short v2;   // dx
	char v3[7]; // [esp+0h] [ebp-8h]

	result = *getMemU32Ptr(0x5D4594, 1049848);
	if (*getMemU32Ptr(0x5D4594, 1049848)) {
		v3[0] = 114;
		*(uint16_t*)&v3[1] = nox_xxx_netGetUnitCodeCli_578B00(*getMemIntPtr(0x5D4594, 1049848));
		v2 = a1->field_4;
		*(uint16_t*)&v3[3] = a1->field_0;
		*(uint16_t*)&v3[5] = v2;
		result = nox_netlist_addToMsgListCli_40EBC0(31, 0, v3, 7);
	}
	return result;
}

//----- (00465C30) --------------------------------------------------------
int nox_xxx_clientKeyEquip_465C30(int a1, int a2) {
	dword_5d4594_1049796_inventory_click_column_index = a1;
	dword_5d4594_1049800_inventory_click_row_index = a2;
	nox_xxx_cliInventorySpriteUpd_465A30();
	nox_xxx_clientEquip_4623B0(*getMemIntPtr(0x5D4594, 1049848));
	return sub_4649B0(*getMemIntPtr(0x5D4594, 1049848), a1, a2);
}

//----- (00465C70) --------------------------------------------------------
void nox_xxx_clientUse_465C70(int a1) {
	int v2; // [esp-4h] [ebp-4h]

	if (a1) {
		v2 = a1;
		LOBYTE(a1) = 116;
		*(uint16_t*)((char*)&a1 + 1) = nox_xxx_netGetUnitCodeCli_578B00(v2);
		nox_netlist_addToMsgListCli_40EBC0(31, 0, &a1, 3);
	}
}

//----- (00465CA0) --------------------------------------------------------
int sub_465CA0() {
	nox_window_set_hidden(*(int*)&dword_5d4594_1062476, 0);
	dword_5d4594_1049864 = 5;
	nox_client_setCursorType_477610(6);
	return nox_xxx_wndSetCaptureMain_46ADC0(*(int*)&dword_5d4594_1062456);
}

//----- (00465CD0) --------------------------------------------------------
void sub_465CD0(uint32_t* a1, int a2, int a3, int a4) {
	int v4;   // edi
	char* v5; // ebx
	int v6;   // esi
	int2 v7;  // [esp+8h] [ebp-8h]

	v4 = a4;
	if (a4) {
		sub_473970((int2*)a1, &v7);
		v5 = sub_461EF0(a2);
		if (v5) {
			v6 = 4;
			do {
				*getMemU32Ptr(0x5D4594, 1049848) = **(uint32_t**)v5;
				*(uint32_t*)(*getMemU32Ptr(0x5D4594, 1049848) + 128) = *(uint32_t*)(*(uint32_t*)v5 + v6);
				if (!sub_4C12C0()) {
					nox_xxx_clientDrop_465BE0(&v7);
				}
				v6 += 4;
				--v4;
				*getMemU32Ptr(0x5D4594, 1049848) = 0;
			} while (v4);
		}
	}
}

//----- (00465D50) --------------------------------------------------------
int sub_465D50_draw(int a1) {
	int v2;     // eax
	int result; // eax
	int v4;     // [esp+0h] [ebp-4h]

	nox_client_wndGetPosition_46AA60(*(uint32_t**)(a1 + 396), &v4, &a1);
	v2 = sub_4615C0();
	if (v2) {
		*(uint32_t*)(v2 + 12) = v4 + 51;
		*(uint32_t*)(v2 + 16) = a1 + 81;
		(*(void (**)(unsigned char*, int))(v2 + 300))(getMemAt(0x5D4594, 1049732), v2);
		result = 1;
	} else {
		if (!dword_5d4594_1062496 && !dword_5d4594_1062492) {
			nox_client_drawImageAt_47D2C0(*getMemIntPtr(0x5D4594, 1050000), v4 + 21, a1 + 50);
		}
		result = 1;
	}
	return result;
}

//----- (00465DE0) --------------------------------------------------------
int sub_465DE0(int a1) {
	dword_5d4594_1049844 = a1;
	return nox_xxx_j_inventoryNameSignInit_467460();
}
// 467460: using guessed type int nox_xxx_j_inventoryNameSignInit_467460(void);


//----- (00465E00) --------------------------------------------------------
int nox_xxx_wndCreateInventoryMB_465E00() {
	uint32_t* v0; // eax
	int result;   // eax
	char* v3;     // eax
	char* v4;     // eax
	uint32_t* v5; // eax
	int v6;       // eax
	int v7;       // eax

	nox_xxx_inventoryLoadImages_467050();
	nox_xxx_inventoryNameSignInit_4671E0();
	dword_5d4594_1063636 = nox_xxx_guiFontPtrByName_43F360("small");
	*getMemU32Ptr(0x5D4594, 1049732) = 0;
	*getMemU32Ptr(0x5D4594, 1049736) = 0;
	*getMemU32Ptr(0x5D4594, 1049740) = nox_win_width;
	*getMemU32Ptr(0x5D4594, 1049744) = nox_win_height;
	*getMemU32Ptr(0x5D4594, 1049764) = nox_win_width;
	*getMemU32Ptr(0x5D4594, 1049768) = nox_win_height;
	*getMemU32Ptr(0x5D4594, 1049748) = 0;
	*getMemU32Ptr(0x5D4594, 1049752) = 0;
	dword_5d4594_1062452 = nox_window_new(0, 552, 0, 0, 563, 264, 0);
	nox_window_set_all_funcs(*(uint32_t**)&dword_5d4594_1062452, 0, nox_xxx_movEax1Sub_4661C0, 0);
	v0 = nox_window_new(*(int*)&dword_5d4594_1062452, 8, 0, 224, nox_win_width, 40, 0);
	nox_window_set_all_funcs(v0, nox_xxx_XorEaxEaxSub_464BA0, nox_xxx_movEax1Sub_4661C0,
							 nox_xxx_inventroryOnHovewerSub_4667E0);
	dword_5d4594_1062456 = nox_window_new(*(int*)&dword_5d4594_1062452, 40, 0, 0, 563, 224, sub_466220);
	nox_window_set_all_funcs(*(uint32_t**)&dword_5d4594_1062456, sub_464BD0, nox_xxx_inventoryDrawAllMB_463430,
							 sub_466620);
	*(uint32_t*)(dword_5d4594_1062456 + 44) |= 0x100u;
	*getMemU32Ptr(0x5D4594, 1062472) = nox_window_new(*(int*)&dword_5d4594_1062452, 40, 0, 0, 1, 1, 0);
	nox_window_set_all_funcs(*(uint32_t**)getMemAt(0x5D4594, 1062472), sub_464BD0, nox_xxx_movEax1Sub_4661C0, 0);
	dword_5d4594_1062468 = nox_window_new(*(int*)&dword_5d4594_1062456, 40, 173, 174, 50, 50, 0);
	nox_window_set_all_funcs(*(uint32_t**)&dword_5d4594_1062468, sub_464770, sub_4625D0, sub_4661D0);
	*(uint32_t*)(dword_5d4594_1062468 + 44) |= 0x100u;
	result = sub_466950(*(int*)&dword_5d4594_1062456);
	if (!result) {
		return 0;
	}

	result = sub_466C40(*(int*)&dword_5d4594_1062456);
	if (!result) {
		return 0;
	}

	result = sub_466ED0(*(int*)&dword_5d4594_1062456);
	if (!result) {
		return 0;
	}

	nox_win_unk5 = nox_window_new(0, 0x408 | NOX_WIN_LAYER_BACK, -1, nox_win_height - 127, 111, 127, 0);
	if (!nox_win_unk5) {
		return 0;
	}

	nox_window_set_all_funcs(nox_win_unk5, nox_xxx_inventoryWndProc_464BB0, nox_xxx_inventoryDrawProc_466580, 0);
	v3 = nox_xxx_gLoadImg_42F970("CurrentWeapon");
	nox_xxx_wndSetIcon_46AE60(nox_win_unk5, (int)v3);
	v4 = nox_xxx_gLoadImg_42F970("CurrentWeaponLit");
	nox_xxx_wndSetIconLit_46AEA0(nox_win_unk5, (int)v4);
	nox_xxx_wndSetOffsetMB_46AE40(nox_win_unk5, -1, 0);
	nox_win_init_cur_weapon(nox_win_unk5, 24, 51, 53, 53);
	sub_471160(nox_win_unk5, 79, 40, 20, 127);
	sub_470D70();
	v5 = nox_window_new(nox_win_unk5, 8, 5, 11, 28, 29, 0);
	nox_window_set_all_funcs(v5, sub_466550, nox_xxx_movEax1Sub_4661C0, sub_466160);
	memset(nox_client_inventory_grid_1050020, 0, sizeof(nox_inventory_cell_t) * NOX_INVENTORY_CELLS_MAX);
	if (!dword_5d4594_1062560) {
		dword_5d4594_1062560 = nox_xxx_getTTByNameSpriteMB_44CFC0("Gold");
		*getMemU32Ptr(0x5D4594, 1049728) = nox_xxx_getTTByNameSpriteMB_44CFC0("QuestGoldPile");
		*getMemU32Ptr(0x5D4594, 1049724) = nox_xxx_getTTByNameSpriteMB_44CFC0("QuestGoldChest");
	}
	nox_client_inventory_grid_1050020[1 * NOX_INVENTORY_ROW_COUNT - 1].field_0 =
		nox_new_drawable_for_thing(*(int*)&dword_5d4594_1062560);
	if (nox_client_inventory_grid_1050020[NOX_INVENTORY_ROW_COUNT - 1].field_0) {
		nox_client_inventory_grid_1050020[NOX_INVENTORY_ROW_COUNT - 1].field_140 = 1;
	}
	v6 = dword_5d4594_1062564;
	if (!dword_5d4594_1062564) {
		v6 = nox_xxx_getTTByNameSpriteMB_44CFC0("Identify");
		dword_5d4594_1062564 = v6;
	}
	nox_client_inventory_grid_1050020[2 * NOX_INVENTORY_ROW_COUNT - 1].field_0 = nox_new_drawable_for_thing(v6);
	if (nox_client_inventory_grid_1050020[2 * NOX_INVENTORY_ROW_COUNT - 1].field_0) {
		nox_client_inventory_grid_1050020[2 * NOX_INVENTORY_ROW_COUNT - 1].field_140 = 1;
	}
	v7 = dword_5d4594_1062556;
	if (!dword_5d4594_1062556) {
		v7 = nox_xxx_getTTByNameSpriteMB_44CFC0("AutoMap");
		dword_5d4594_1062556 = v7;
	}
	nox_client_inventory_grid_1050020[3 * NOX_INVENTORY_ROW_COUNT - 1].field_0 = nox_new_drawable_for_thing(v7);
	if (nox_client_inventory_grid_1050020[3 * NOX_INVENTORY_ROW_COUNT - 1].field_0) {
		nox_client_inventory_grid_1050020[3 * NOX_INVENTORY_ROW_COUNT - 1].field_140 = 1;
	}

	return dword_5d4594_1062456;
}

//----- (004661C0) --------------------------------------------------------
int nox_xxx_movEax1Sub_4661C0() { return 1; }

//----- (00466220) --------------------------------------------------------
int sub_466220(int a1, int a2, int* a3, int a4) {
	int result; // eax
	int v5;     // ecx
	int v6;     // ecx
	int v7;     // ecx
	int v8;     // eax

	if (a2 == 16391) {
		switch (nox_xxx_wndGetID_46B0A0(a3)) {
		case 9102:
			if (*(int*)&dword_5d4594_1062512 - 25 >= 0) {
				v5 = *(int*)&dword_5d4594_1062512 - 25 - (*(int*)&dword_5d4594_1062512 - 25) % 50;
			} else {
				v5 = 0;
			}
			dword_5d4594_1062512 = v5;
			nox_window_call_field_94(*(int*)&dword_5d4594_1062508, 16394,
									 *(uint32_t*)(*(uint32_t*)(dword_5d4594_1062508 + 32) + 4) - v5, 0);
			nox_xxx_clientPlaySoundSpecial_452D80(766, 100);
			result = 0;
			break;
		case 9103:
			v6 = dword_5d4594_1062512 + 50;
			dword_5d4594_1062512 = v6;
			if (v6 <= *(int*)(*(uint32_t*)(dword_5d4594_1062508 + 32) + 4)) {
				v7 = v6 - v6 % 50;
			} else {
				v7 = *(uint32_t*)(*(uint32_t*)(dword_5d4594_1062508 + 32) + 4);
			}
			dword_5d4594_1062512 = v7;
			nox_window_call_field_94(*(int*)&dword_5d4594_1062508, 16394,
									 *(uint32_t*)(*(uint32_t*)(dword_5d4594_1062508 + 32) + 4) - v7, 0);
			nox_xxx_clientPlaySoundSpecial_452D80(766, 100);
			result = 0;
			break;
		case 9105:
			v8 = sub_469FA0() - 150;
			if (dword_5d4594_1049864 == 5) {
				goto LABEL_23;
			}
			if (v8 < 0) {
				v8 = 0;
			}
			*getMemU8Ptr(0x5D4594, 1049869) = 1;
			dword_5d4594_1062516 = dword_5d4594_1062512;
			dword_5d4594_1062512 = dword_5d4594_1062520;
			nox_window_call_field_94(*(int*)&dword_5d4594_1062508, 16395, 0, v8);
			nox_window_call_field_94(*(int*)&dword_5d4594_1062508, 16394,
									 *(uint32_t*)(*(uint32_t*)(dword_5d4594_1062508 + 32) + 4) - dword_5d4594_1062512,
									 0);
			nox_xxx_wndSetIcon_46AE60(*(int*)&dword_5d4594_1062528, *getMemIntPtr(0x5D4594, 1049980));
			sub_46AEC0(*(int*)&dword_5d4594_1062528, *getMemIntPtr(0x5D4594, 1049984));
			nox_xxx_wndSetID_46B080(*(uint32_t**)&dword_5d4594_1062528, 9106);
			result = 0;
			break;
		case 9106:
			*getMemU8Ptr(0x5D4594, 1049869) = 0;
			dword_5d4594_1062520 = dword_5d4594_1062512;
			dword_5d4594_1062512 = dword_5d4594_1062516;
			nox_window_call_field_94(*(int*)&dword_5d4594_1062508, 16395, 0, 850);
			nox_window_call_field_94(*(int*)&dword_5d4594_1062508, 16394,
									 *(uint32_t*)(*(uint32_t*)(dword_5d4594_1062508 + 32) + 4) - dword_5d4594_1062512,
									 0);
			nox_xxx_wndSetIcon_46AE60(*(int*)&dword_5d4594_1062528, 0);
			sub_46AEC0(*(int*)&dword_5d4594_1062528, *(int*)&dword_5d4594_1049976);
			nox_xxx_wndSetID_46B080(*(uint32_t**)&dword_5d4594_1062528, 9105);
			result = 0;
			break;
		case 9107:
			if (dword_5d4594_1049864 == 5) {
				goto LABEL_23;
			}
			*getMemU8Ptr(0x5D4594, 1049870) = 1;
			nox_xxx_wndSetIcon_46AE60(*(int*)&dword_5d4594_1062524, 0);
			sub_46AEC0(*(int*)&dword_5d4594_1062524, *getMemIntPtr(0x5D4594, 1049988));
			nox_xxx_wndSetID_46B080(*(uint32_t**)&dword_5d4594_1062524, 9108);
			nox_window_set_hidden(*(int*)&dword_5d4594_1062468, 1);
			result = 0;
			break;
		case 9108:
			if (dword_5d4594_1049864 != 5) {
				*getMemU8Ptr(0x5D4594, 1049870) = 0;
				nox_xxx_wndSetIcon_46AE60(*(int*)&dword_5d4594_1062524, *(int*)&dword_5d4594_1049992);
				sub_46AEC0(*(int*)&dword_5d4594_1062524, *(int*)&dword_5d4594_1049996);
				nox_xxx_wndSetID_46B080(*(uint32_t**)&dword_5d4594_1062524, 9107);
				nox_window_set_hidden(*(int*)&dword_5d4594_1062468, 0);
			}
			goto LABEL_23;
		case 9111:
			sub_467C10();
			result = 0;
			break;
		default:
			goto LABEL_23;
		}
	} else if (a2 == 16393) {
		result = 0;
		dword_5d4594_1062512 = *(uint32_t*)(*(uint32_t*)(dword_5d4594_1062508 + 32) + 4) - a4;
	} else {
	LABEL_23:
		result = 0;
	}
	return result;
}

//----- (00466550) --------------------------------------------------------
int sub_466550(int a1, unsigned int a2) {
	if (a2 >= 5) {
		if (a2 <= 6) {
			return 1;
		}
		if (a2 == 7) {
			nox_client_toggleInventory_467C60();
			return 1;
		}
	}
	return 0;
}

//----- (00466580) --------------------------------------------------------
int nox_xxx_inventoryDrawProc_466580(uint32_t* a1) {
	uint32_t* v1; // esi
	int v2;       // eax
	short* v3;    // eax
	int v5;       // [esp+4h] [ebp-Ch]
	int v6;       // [esp+8h] [ebp-8h]
	int v7;       // [esp+Ch] [ebp-4h]

	v1 = a1;
	nox_client_wndGetPosition_46AA60(a1, &v5, &a1);
	nox_window_get_size((int)v1, &v7, &v6);
	if (getMemByte(0x5D4594, 1049868)) {
		v2 = v1[19];
	} else {
		v2 = v1[15];
	}
	nox_client_drawImageAt_47D2C0(v2, v5, (int)a1);
	nox_xxx_drawSetTextColor_434390(nox_color_white_2523948);
	v3 = (short*)sub_42E8E0(35, 1);
	if (v3) {
		nox_xxx_drawString_43F6E0(*(int*)&dword_5d4594_1063636, v3, v5 + 19, (int)a1 + 102);
	}
	return 1;
}

//----- (00466620) --------------------------------------------------------
int sub_466620(int a1, int a2, unsigned int a3) {
	wchar2_t* v3; // eax
	int2 a2a;    // [esp+0h] [ebp-8h]

	a2a.field_4 = a3 >> 16;
	a2a.field_0 = (unsigned short)a3;
	v3 = sub_466660(a1, &a2a);
	nox_xxx_cursorSetTooltip_4776B0(v3);
	return 1;
}

// 466676: variable 'v2' is possibly undefined
// 4666FF: variable 'v6' is possibly undefined
// 466737: variable 'v10' is possibly undefined

// 4668C0: variable 'v11' is possibly undefined
// 466900: variable 'v13' is possibly undefined

//----- (00466950) --------------------------------------------------------
int sub_466950(int a1) {
	uint32_t* v1; // eax
	uint32_t* v3; // eax
	uint32_t* v4; // eax
	int v5[4];    // [esp+10h] [ebp-15Ch]
	char v6[332]; // [esp+20h] [ebp-14Ch]

	v5[1] = 0;
	v5[2] = 0;
	memset(v6, 0, sizeof(v6));
	v5[3] = 0;
	v5[0] = 0;
	*(uint32_t*)&v6[24] = 0;
	*(uint32_t*)&v6[48] = 0;
	*(uint32_t*)&v6[32] = *getMemU32Ptr(0x5D4594, 1049940);
	*(uint32_t*)&v6[40] = *getMemU32Ptr(0x5D4594, 1049944);
	*(uint32_t*)&v6[56] = *getMemU32Ptr(0x5D4594, 1049944);
	*(uint32_t*)&v6[68] = 0x80000000;
	*(uint32_t*)&v6[8] = 1;
	*(uint16_t*)&v6[72] = 0;
	*(uint32_t*)&v6[16] = a1;
	v1 = (uint32_t*)nox_gui_newButtonOrCheckbox_4A91A0(a1, 1161, 522, 2, 20, 25, v6);
	*getMemU32Ptr(0x5D4594, 1062500) = v1;
	if (!v1) {
		return 0;
	}
	nox_xxx_wndSetID_46B080(v1, 9102);
	memset(v6, 0, sizeof(v6));
	*(uint32_t*)&v6[32] = *getMemU32Ptr(0x5D4594, 1049948);
	*(uint32_t*)&v6[24] = 0;
	*(uint32_t*)&v6[48] = 0;
	*(uint32_t*)&v6[40] = *getMemU32Ptr(0x5D4594, 1049952);
	*(uint32_t*)&v6[56] = *getMemU32Ptr(0x5D4594, 1049952);
	*(uint32_t*)&v6[68] = 0x80000000;
	*(uint32_t*)&v6[8] = 1;
	*(uint16_t*)&v6[72] = 0;
	*(uint32_t*)&v6[16] = a1;
	v3 = (uint32_t*)nox_gui_newButtonOrCheckbox_4A91A0(a1, 1161, 522, 148, 20, 25, v6);
	*getMemU32Ptr(0x5D4594, 1062504) = v3;
	if (!v3) {
		return 0;
	}
	nox_xxx_wndSetID_46B080(v3, 9103);
	memset(v6, 0, sizeof(v6));
	v5[2] = 0;
	*(uint32_t*)&v6[20] = 0x80000000;
	*(uint32_t*)&v6[44] = 0x80000000;
	*(uint32_t*)&v6[28] = 0x80000000;
	*(uint32_t*)&v6[36] = 0x80000000;
	*(uint32_t*)&v6[52] = 0x80000000;
	*(uint32_t*)&v6[8] = 8;
	*(uint32_t*)&v6[16] = a1;
	v5[3] = 0;
	v5[0] = 0;
	v5[1] = 850;
	v4 = nox_gui_newSlider_4B4EE0(a1, 1033, 524, 42, 16, 91, v6, (float*)v5);
	dword_5d4594_1062508 = v4;
	if (!v4) {
		return 0;
	}
	nox_xxx_wndSetWindowProc_46B300((int)v4, sub_466BF0);
	nox_xxx_wndSetWindowProc_46B300(*(uint32_t*)(dword_5d4594_1062508 + 400), sub_466BA0);
	*(uint32_t*)(*(uint32_t*)(dword_5d4594_1062508 + 400) + 8) = 16;
	*(uint32_t*)(*(uint32_t*)(dword_5d4594_1062508 + 400) + 12) = 16;
	nox_xxx_wndSetOffsetMB_46AE40(*(uint32_t*)(dword_5d4594_1062508 + 400), 0, -15);
	sub_4B5700(*(int*)&dword_5d4594_1062508, 0, 0, *getMemIntPtr(0x5D4594, 1049956), *getMemIntPtr(0x5D4594, 1049960),
			   *getMemIntPtr(0x5D4594, 1049960));
	return 1;
}

//----- (00466BA0) --------------------------------------------------------
int sub_466BA0(uint32_t* a1, int a2, unsigned int a3, int a4) {
	int result; // eax

	if (*getMemU32Ptr(0x5D4594, 1049848)) {
		result = sub_464BD0((int)a1, a2, a3);
	} else {
		result = nox_xxx_wndButtonProc_4A7F50(a1, a2, a3, a4);
	}
	return result;
}

//----- (00466BF0) --------------------------------------------------------
int sub_466BF0(int a1, int a2, unsigned int a3, int a4) {
	int result; // eax

	if (*getMemU32Ptr(0x5D4594, 1049848)) {
		result = sub_464BD0(a1, a2, a3);
	} else {
		result = nox_xxx_wndScrollBoxDraw_4B4BA0(a1, a2, a3, a4);
	}
	return result;
}

//----- (00466C40) --------------------------------------------------------
int sub_466C40(int a1) {
	uint32_t* v1; // eax
	uint32_t* v3; // eax
	uint32_t* v4; // eax
	char v5[332]; // [esp+Ch] [ebp-14Ch]

	memset(v5, 0, sizeof(v5));
	*(uint32_t*)&v5[24] = 0;
	*(uint32_t*)&v5[48] = 0;
	*(uint32_t*)&v5[32] = 0;
	*(uint32_t*)&v5[40] = 0;
	*(uint32_t*)&v5[56] = dword_5d4594_1049976;
	*(uint32_t*)&v5[60] = -243;
	*(uint32_t*)&v5[64] = -170;
	*(uint32_t*)&v5[16] = a1;
	*(uint32_t*)&v5[8] = 1;
	v1 = (uint32_t*)nox_gui_newButtonOrCheckbox_4A91A0(a1, 1161, 243, 170, 34, 34, v5);
	dword_5d4594_1062528 = v1;
	if (!v1) {
		return 0;
	}
	nox_xxx_wndSetID_46B080(v1, 9105);
	nox_gui_winSetFunc96_46B070(*(int*)&dword_5d4594_1062528, sub_466E20);
	memset(v5, 0, sizeof(v5));
	*(uint32_t*)&v5[24] = dword_5d4594_1049992;
	*(uint32_t*)&v5[48] = 0;
	*(uint32_t*)&v5[32] = 0;
	*(uint32_t*)&v5[40] = 0;
	*(uint32_t*)&v5[56] = dword_5d4594_1049996;
	*(uint32_t*)&v5[60] = -5;
	*(uint32_t*)&v5[64] = -186;
	*(uint32_t*)&v5[16] = a1;
	*(uint32_t*)&v5[8] = 1;
	v3 = (uint32_t*)nox_gui_newButtonOrCheckbox_4A91A0(a1, 1161, 5, 186, 34, 34, v5);
	dword_5d4594_1062524 = v3;
	if (!v3) {
		return 0;
	}
	nox_xxx_wndSetID_46B080(v3, 9107);
	nox_gui_winSetFunc96_46B070(*(int*)&dword_5d4594_1062524, sub_466E20);
	memset(v5, 0, sizeof(v5));
	*(uint32_t*)&v5[24] = 0;
	*(uint32_t*)&v5[48] = 0;
	*(uint32_t*)&v5[32] = 0;
	*(uint32_t*)&v5[40] = 0;
	*(uint32_t*)&v5[56] = *getMemU32Ptr(0x5D4594, 1049972);
	*(uint32_t*)&v5[60] = -547;
	*(uint32_t*)&v5[64] = -2;
	*(uint32_t*)&v5[16] = a1;
	*(uint32_t*)&v5[8] = 1;
	v4 = (uint32_t*)nox_gui_newButtonOrCheckbox_4A91A0(a1, 1161, 547, 2, 16, 16, v5);
	*getMemU32Ptr(0x5D4594, 1062532) = v4;
	if (!v4) {
		return 0;
	}
	nox_xxx_wndSetID_46B080(v4, 9111);
	nox_gui_winSetFunc96_46B070(*getMemIntPtr(0x5D4594, 1062532), sub_466E20);
	return 1;
}

//----- (00466ED0) --------------------------------------------------------
int sub_466ED0(int a1) {
	int result;   // eax
	uint32_t* v2; // eax

	result = nox_new_window_from_file("identify.wnd", 0);
	dword_5d4594_1062476 = result;
	if (result) {
		sub_46AB20((uint32_t*)result, 200, 200);
		sub_46B120(*(uint32_t**)&dword_5d4594_1062476, a1);
		nox_window_setPos_46A9B0(*(uint32_t**)&dword_5d4594_1062476, 51, 15);
		v2 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1062476, 9155);
		nox_xxx_wndSetDrawFn_46B340((int)v2, sub_466F50);
		result = 1;
	}
	return result;
}

//----- (00466F50) --------------------------------------------------------
int sub_466F50(uint32_t* a1, int* a2) {
	int v3;        // ecx
	uint32_t* v4;  // eax
	int v5;        // ecx
	uint32_t* v6;  // ebx
	int v7;        // edx
	int v8;        // edi
	int v9;        // ebp
	uint8_t* v10;  // esi
	int* v11;      // edi
	uint8_t** v12; // esi
	int v13;       // ebx
	uint8_t* v14;  // eax
	int v15;       // [esp+0h] [ebp-8h]
	int v16;       // [esp+4h] [ebp-4h]

	if (!dword_5d4594_1063116) {
		return 1;
	}
	v3 = *(uint32_t*)(dword_5d4594_1063116 + 112);
	if (v3 & 0x13001000) {
		v4 = v3 & 0x11001000 ? nox_xxx_getProjectileClassById_413250(*(uint32_t*)(dword_5d4594_1063116 + 108))
							 : nox_xxx_equipClothFindDefByTT_413270(*(uint32_t*)(dword_5d4594_1063116 + 108));
		v6 = v4;
		if (v4) {
			v7 = dword_5d4594_1063116;
			v8 = 1;
			v9 = dword_5d4594_1063116 + 432;
			v10 = v4 + 4;
			do {
				LOBYTE(v4) = v10[1];
				LOBYTE(v5) = *v10;
				LOBYTE(v7) = *(v10 - 1);
				nox_draw_setMaterial_4340A0(v8++, v7, v5, (int)v4);
				v10 += 3;
			} while (v8 < 7);
			v11 = v6 + 9;
			v12 = (uint8_t**)v9;
			v13 = 4;
			do {
				v14 = *v12;
				if (*v12) {
					LOBYTE(v5) = v14[26];
					LOBYTE(v7) = v14[25];
					LOBYTE(v14) = v14[24];
					nox_draw_setMaterial_4340A0(*v11, (int)v14, v7, v5);
				}
				++v12;
				++v11;
				--v13;
			} while (v13);
		}
	}
	nox_client_wndGetPosition_46AA60(a1, &v15, &v16);
	nox_client_drawImageAt_47D2C0(a2[6], a2[15] + v15, a2[16] + v16);
	return 1;
}
// 466FBD: variable 'v7' is possibly undefined
// 466FBD: variable 'v5' is possibly undefined

//----- (00467050) --------------------------------------------------------
char* nox_xxx_inventoryLoadImages_467050() {
	char* result; // eax

	*getMemU32Ptr(0x5D4594, 1049908) = nox_xxx_gLoadImg_42F970("InventoryBase");
	*getMemU32Ptr(0x5D4594, 1049912) = nox_xxx_gLoadImg_42F970("InventoryIdentifyBase");
	*getMemU32Ptr(0x5D4594, 1049916) = nox_xxx_gLoadImg_42F970("InventoryTray1");
	*getMemU32Ptr(0x5D4594, 1049920) = nox_xxx_gLoadImg_42F970("InventoryTray2");
	*getMemU32Ptr(0x5D4594, 1049924) = nox_xxx_gLoadImg_42F970("InventoryTray3");
	*getMemU32Ptr(0x5D4594, 1049928) = nox_xxx_gLoadImg_42F970("InventoryTraySpecial");
	*getMemU32Ptr(0x5D4594, 1049932) = nox_xxx_gLoadImg_42F970("InventoryTrayIdentifyLit");
	*getMemU32Ptr(0x5D4594, 1049936) = nox_xxx_gLoadImg_42F970("InventoryTrayMapLit");
	*getMemU32Ptr(0x5D4594, 1049940) = nox_xxx_gLoadImg_42F970("InventoryUpButton");
	*getMemU32Ptr(0x5D4594, 1049944) = nox_xxx_gLoadImg_42F970("InventoryUpButtonLit");
	*getMemU32Ptr(0x5D4594, 1049948) = nox_xxx_gLoadImg_42F970("InventoryDownButton");
	*getMemU32Ptr(0x5D4594, 1049952) = nox_xxx_gLoadImg_42F970("InventoryDownButtonLit");
	*getMemU32Ptr(0x5D4594, 1049956) = nox_xxx_gLoadImg_42F970("InventorySliderButton");
	*getMemU32Ptr(0x5D4594, 1049960) = nox_xxx_gLoadImg_42F970("InventorySliderButtonLit");
	*getMemU32Ptr(0x5D4594, 1049964) = nox_xxx_gLoadImg_42F970("InventoryEquipRing");
	*getMemU32Ptr(0x5D4594, 1049968) = nox_xxx_gLoadImg_42F970("InventoryQuickItemRing");
	*getMemU32Ptr(0x5D4594, 1049972) = nox_xxx_gLoadImg_42F970("InventoryCloseButtonLit");
	dword_5d4594_1049976 = nox_xxx_gLoadImg_42F970("InventoryJournalButtonLit");
	*getMemU32Ptr(0x5D4594, 1049980) = nox_xxx_gLoadImg_42F970("InventoryInventoryButton");
	*getMemU32Ptr(0x5D4594, 1049984) = nox_xxx_gLoadImg_42F970("InventoryInventoryButtonLit");
	*getMemU32Ptr(0x5D4594, 1049988) = nox_xxx_gLoadImg_42F970("InventoryDollButtonLit");
	dword_5d4594_1049992 = nox_xxx_gLoadImg_42F970("InventoryStatsButton");
	dword_5d4594_1049996 = nox_xxx_gLoadImg_42F970("InventoryStatsButtonLit");
	*getMemU32Ptr(0x5D4594, 1050000) = nox_xxx_gLoadImg_42F970("GUIFist");
	*getMemU32Ptr(0x5D4594, 1050004) = nox_xxx_gLoadImg_42F970("SharedKeyMode");
	result = nox_xxx_gLoadAnim_42FA20("ExtraLives");
	dword_5d4594_1050008 = result;
	return result;
}

//----- (004672C0) --------------------------------------------------------
void nox_client_invAlterWeapon_4672C0() { // Switch onto secondary weapon
	int result;                           // eax
	int v1;                               // edi
	int v2;                               // eax
	uint32_t* v3;                         // edx
	int v4;                               // eax
	int i;                                // esi
	int v6;                               // eax

	result = *getMemU32Ptr(0x852978, 8);
	if (!*getMemU32Ptr(0x852978, 8)) {
		return;
	}
	result = nox_xxx_guiCursor_477600();
	if (result) {
		return;
	}
	result = sub_461160(1);
	if (result) {
		return;
	}
	v1 = *getMemU32Ptr(0x8531A0, 2576);
	if (!*getMemU32Ptr(0x8531A0, 2576)) {
		return;
	}
	result = *getMemU32Ptr(0x852978, 8);
	if (*(uint32_t*)(*getMemU32Ptr(0x852978, 8) + 276) == 34) {
		return;
	}
	v2 = nox_xxx_pointInRect_4281F0((int2*)getMemAt(0x5D4594, 1062572), (int4*)getMemAt(0x587000, 136336));
	if (v2 == 1) {
		nox_xxx_cursorSetDraggedItem_477690(0);
	}
	v3 = *(uint32_t**)&dword_5d4594_1062480;
	if (dword_5d4594_1062480) {
		if (nox_xxx_ammoCheck_415880(*(char**)(**(uint32_t**)&dword_5d4594_1062480 + 108)) == 2) {
			v4 = sub_415840((char*)2);
			result = sub_461600(v4);
			if (result) {
			LABEL_11:
				dword_5d4594_1062492 = result;
				nox_xxx_clientDequip_464B70(result);
				nox_xxx_clientPlaySoundSpecial_452D80(895, 100);
			}
			return;
		}
		v3 = *(uint32_t**)&dword_5d4594_1062480;
	}
	for (i = 1; i < 27; ++i) {
		result = 1 << i;
		if (1 << i != 2 && result & *(uint32_t*)(v1 + 4)) {
			v6 = sub_415840((char*)(1 << i));
			result = sub_461600(v6);
			if (result) {
				goto LABEL_11;
			}
			v3 = *(uint32_t**)&dword_5d4594_1062480;
		}
	}
	if (v3) {
		*(uint32_t*)(*v3 + 128) = v3[1];
		nox_xxx_clientEquip_4623B0(**(uint32_t**)&dword_5d4594_1062480);
		nox_xxx_clientPlaySoundSpecial_452D80(895, 100);
	}
}
// 467323: variable 'v2' is possibly undefined

//----- (004673F0) --------------------------------------------------------
int sub_4673F0(int a1, int a2) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 1062580) = a1;
	*getMemU32Ptr(0x5D4594, 1062584) = a2;
	return result;
}

//----- (00467410) --------------------------------------------------------
int sub_467410(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 1062540) = a1;
	return result;
}

//----- (00467420) --------------------------------------------------------
char sub_467420(char a1) {
	char result; // al

	result = a1;
	*getMemU8Ptr(0x5D4594, 1062536) = a1;
	return result;
}

//----- (00467430) --------------------------------------------------------
unsigned char sub_467430() { return getMemByte(0x5D4594, 1062536); }

//----- (00467440) --------------------------------------------------------
int sub_467440(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 1062544) = a1;
	return result;
}

//----- (00467450) --------------------------------------------------------
int sub_467450(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 1062548) = a1;
	return result;
}

//----- (00467470) --------------------------------------------------------
int sub_467470(int a1, float a2) {
	int result; // eax

	result = (unsigned char)a1;
	*getMemFloatPtr(0x5D4594, 1063100 + 4 * (unsigned char)a1) = a2;
	return result;
}

//----- (00467490) --------------------------------------------------------
int sub_467490(int a1) {
	int result; // eax

	result = a1;
	dword_5d4594_1062552 = a1;
	return result;
}

//----- (004674A0) --------------------------------------------------------
int sub_4674A0() { return dword_5d4594_1062552; }

//----- (004674B0) --------------------------------------------------------
void nox_window_set_visible_unk5(int visible) {
	if (visible) {
		nox_window_set_hidden(nox_win_unk5, 0);
	} else {
		nox_window_set_hidden(nox_win_unk5, 1);
	}
}

//----- (004674E0) --------------------------------------------------------
void nox_xxx_cliUseCurePoison_4674E0(int a1) {
	if (nox_xxx_guiCursor_477600() != 1) {
		if (!nox_xxx_checkGameFlagPause_413A50()) {
			int result = nox_xxx_cliInventoryFirstItemByTT_467520(a1);
			if (result) {
				*(uint32_t*)(*(uint32_t*)result + 128) = *((uint32_t*)result + 1);
				nox_xxx_clientUse_465C70(*(uint32_t*)result);
			}
		}
	}
}

//----- (00467520) --------------------------------------------------------
char* nox_xxx_cliInventoryFirstItemByTT_467520(int a1) {
	int v1;            // esi
	unsigned char* v2; // edx
	int v3;            // eax
	unsigned char* v4; // ecx

	v1 = 0;
	v2 = nox_client_inventory_grid_1050020;
	while (1) {
		v3 = 0;
		v4 = v2;
		do {
			if (v4[140] && *(uint32_t*)(*(uint32_t*)v4 + 108) == a1) {
				return &nox_client_inventory_grid_1050020[v1 + NOX_INVENTORY_ROW_COUNT * v3];
			}
			++v3;
			v4 += NOX_INVENTORY_ROW_COUNT * sizeof(nox_inventory_cell_t);
		} while (v3 < 4);
		v2 += sizeof(nox_inventory_cell_t);
		++v1;
		if ((int)v2 <= (int)&nox_client_inventory_grid_1050020[NOX_INVENTORY_ROW_COUNT - 1]) {
			continue;
		}
		break;
	}
	return 0;
}

//----- (00467590) --------------------------------------------------------
int sub_467590() {
	int result; // eax

	if (*getMemU32Ptr(0x8531A0, 2576)) {
		result = *(char*)(*getMemU32Ptr(0x8531A0, 2576) + 3684);
	} else {
		result = 1;
	}
	return result;
}

//----- (004675B0) --------------------------------------------------------
int sub_4675B0() { return dword_5d4594_1049864; }

//----- (004675E0) --------------------------------------------------------
short sub_4675E0(int a1, short a2, short a3) {
	char* v3; // eax
	int v4;   // eax

	v3 = sub_461EF0(a1);
	if (v3) {
		*(uint16_t*)(**(uint32_t**)v3 + 292) = a2;
		v4 = **(uint32_t**)v3;
		*(uint16_t*)(v4 + 294) = a3;
	} else {
		LOWORD(v4) = *getMemU16Ptr(0x5D4594, 1049848);
		if (*getMemU32Ptr(0x5D4594, 1049848) && *(uint32_t*)(*getMemU32Ptr(0x5D4594, 1049848) + 128) == a1) {
			*(uint16_t*)(*getMemU32Ptr(0x5D4594, 1049848) + 292) = a2;
			LOWORD(v4) = a3;
			*(uint16_t*)(*getMemU32Ptr(0x5D4594, 1049848) + 294) = a3;
		}
	}
	return v4;
}

//----- (00467650) --------------------------------------------------------
int sub_467650() {
	int result; // eax

	sub_462740();
	dword_5d4594_1049864 = 6;
	nox_client_setCursorType_477610(8);
	result = sub_467C80();
	if (!result) {
		result = sub_467BB0();
	}
	return result;
}

//----- (00467680) --------------------------------------------------------
void sub_467680() {
	if (dword_5d4594_1049864 == 6) {
		dword_5d4594_1049864 = 0;
	}
}

//----- (004676A0) --------------------------------------------------------
nox_window* nox_xxx_wndGetHandle_4676A0() { return dword_5d4594_1062452; }

//----- (004676D0) --------------------------------------------------------
int sub_4676D0(int a1) {
	char* v1;   // eax
	int result; // eax

	v1 = sub_461EF0(a1);
	if (v1) {
		return **(uint32_t**)v1;
	}
	result = *getMemU32Ptr(0x5D4594, 1049848);
	if (!*getMemU32Ptr(0x5D4594, 1049848) || *(uint32_t*)(*getMemU32Ptr(0x5D4594, 1049848) + 128) != a1) {
		result = 0;
	}
	return result;
}

//----- (00467700) --------------------------------------------------------
int sub_467700(int a1) {
	char* v1; // eax

	v1 = sub_461EF0(a1);
	if (v1) {
		return *(unsigned char*)(*(uint32_t*)v1 + 140);
	}
	if (*getMemU32Ptr(0x5D4594, 1049848) && *(uint32_t*)(*getMemU32Ptr(0x5D4594, 1049848) + 128) == a1) {
		return 1;
	}
	return 0;
}

//----- (00467740) --------------------------------------------------------
int sub_467740(int a1) {
	dword_5d4594_1062488 = a1;
	return a1;
}

//----- (00467810) --------------------------------------------------------
int sub_467810(int a1, int a2) {
	if (a1 < 0 || a2 < 0 || a1 >= 4 || a2 >= 20) {
		return 0;
	}
	return nox_client_inventory_grid_1050020[a2 + NOX_INVENTORY_ROW_COUNT * a1].field_140;
}

//----- (00467850) --------------------------------------------------------
int sub_467850(int a1) {
	char* v1; // eax
	v1 = nox_xxx_cliInventoryFirstItemByTT_467520(a1);
	if (v1) {
		return (unsigned char)v1[140];
	}
	return 0;
}

//----- (00467870) --------------------------------------------------------
char* sub_467870(int a1, int a2) {
	if (a1 < 0 || a2 < 0 || a1 >= 4 || a2 >= 20) {
		return 0;
	}
	return &(nox_client_inventory_grid_1050020[a2 + NOX_INVENTORY_ROW_COUNT * a1].field_4);
}

//----- (004678B0) --------------------------------------------------------
int sub_4678B0() {
	if (dword_5d4594_1062480) {
		return *(uint32_t*)(dword_5d4594_1062480 + 4);
	}
	return 0;
}

//----- (004678C0) --------------------------------------------------------
int sub_4678C0() { return dword_5d4594_1062488; }

//----- (004678D0) --------------------------------------------------------
int sub_4678D0() {
	int v0;     // edi
	int v1;     // esi
	int v2;     // eax
	int v3;     // eax
	int result; // eax
	char* v5;   // eax

	v0 = *getMemU32Ptr(0x8531A0, 2576);
	if (!*getMemU32Ptr(0x8531A0, 2576)) {
		goto LABEL_7;
	}
	v1 = 1;
	while (1) {
		if (1 << v1 != 2) {
			if ((1 << v1) & *(uint32_t*)(v0 + 4)) {
				v2 = sub_415840((char*)(1 << v1));
				v3 = sub_461600(v2);
				if (v3) {
					break;
				}
			}
		}
		if (++v1 >= 27) {
			goto LABEL_7;
		}
	}
	v5 = sub_461EF0(*(uint32_t*)(v3 + 128));
	if (v5) {
		result = **(uint32_t**)v5;
	} else {
	LABEL_7:
		result = 0;
	}
	return result;
}

//----- (00467930) --------------------------------------------------------
char* sub_467930(int a1, int a2, int a3) {
	char* result; // eax
	int v4;       // ecx

	result = (char*)a1;
	if (a1) {
		result = sub_461EF0(a1);
		if (result) {
			v4 = **(uint32_t**)result;
			*(uint16_t*)(v4 + 448) = a2;
			*(uint16_t*)(v4 + 450) = a3;
			result = *(char**)result;
			if (*((uint32_t*)result + 33) == 1) {
				result = (char*)sub_470D90(a2, a3);
			}
		}
	}
	return result;
}

//----- (00467980) --------------------------------------------------------
int sub_467980() {
	unsigned char* v0; // ebp
	unsigned char* v1; // esi
	int v2;            // edi

	v0 = nox_client_inventory_grid_1050020;
	do {
		v1 = v0;
		v2 = 4;
		do {
			if (*(uint32_t*)v1) {
				nox_xxx_spriteDelete_45A4B0(*(uint64_t**)v1);
				*(uint32_t*)v1 = 0;
			}
			v1[140] = 0;
			*((uint32_t*)v1 + 33) = 0;
			*((uint32_t*)v1 + 34) = 0;
			v1 += NOX_INVENTORY_ROW_COUNT * sizeof(nox_inventory_cell_t);
			--v2;
		} while (v2);
		v0 += sizeof(nox_inventory_cell_t);
	} while ((int)v0 <= (int)&nox_client_inventory_grid_1050020[NOX_INVENTORY_ROW_COUNT - 1]);
	sub_462740();
	dword_5d4594_1049864 = 0;
	nox_xxx_clientSetAltWeapon_461550(0);
	dword_5d4594_1062488 = 0;
	memset(&array_5D4594_1049872, 0, 0x24u); // equipped weapon array?
	dword_5d4594_1062492 = 0;
	dword_5d4594_1062496 = 0;
	*getMemU8Ptr(0x5D4594, 1062536) = 0;
	*getMemU32Ptr(0x5D4594, 1062540) = 0;
	*getMemU32Ptr(0x5D4594, 1062544) = 0;
	*getMemU32Ptr(0x5D4594, 1062548) = 0;
	dword_5d4594_1062552 = 0;
	sub_472310();
	dword_587000_136184 = -225;
	*getMemU8Ptr(0x5D4594, 1049868) = 0;
	*getMemU8Ptr(0x5D4594, 1049869) = 0;
	dword_5d4594_1062516 = 0;
	dword_5d4594_1062520 = 0;
	dword_5d4594_1062512 = 0;
	nox_window_call_field_94(*(int*)&dword_5d4594_1062508, 16395, 0, 850);
	nox_window_call_field_94(*(int*)&dword_5d4594_1062508, 16394,
							 *(uint32_t*)(*(uint32_t*)(dword_5d4594_1062508 + 32) + 4) - dword_5d4594_1062512, 0);
	nox_xxx_wndSetIcon_46AE60(*(int*)&dword_5d4594_1062528, 0);
	sub_46AEC0(*(int*)&dword_5d4594_1062528, *(int*)&dword_5d4594_1049976);
	nox_xxx_wndSetID_46B080(*(uint32_t**)&dword_5d4594_1062528, 9105);
	*getMemU8Ptr(0x5D4594, 1049870) = 0;
	nox_xxx_wndSetIcon_46AE60(*(int*)&dword_5d4594_1062524, *(int*)&dword_5d4594_1049992);
	sub_46AEC0(*(int*)&dword_5d4594_1062524, *(int*)&dword_5d4594_1049996);
	nox_xxx_wndSetID_46B080(*(uint32_t**)&dword_5d4594_1062524, 9107);
	return nox_window_set_hidden(*(int*)&dword_5d4594_1062468, 0);
}

//----- (00467B00) --------------------------------------------------------
int sub_467B00(int a1, int a2) {
	int v2;            // ebx
	unsigned char* v3; // ebp
	int i;             // esi
	int v5;            // edi
	int v6;            // eax
	int v8;            // [esp+10h] [ebp-8h]
	unsigned char* v9; // [esp+14h] [ebp-4h]

	v2 = 0;
	v8 = 0;
	v9 = nox_client_inventory_grid_1050020;
	do {
		v3 = v9;
		for (i = 0; i < 4; ++i) {
			v5 = sub_467810(i, v2);
			if (!v5) {
				goto LABEL_15;
			}
			if (*(uint32_t*)(*(uint32_t*)v3 + 108) == a1) {
				v6 = 31;
				if (*(uint8_t*)(*(uint32_t*)v3 + 112) & 0x10) {
					v6 = nox_common_gameFlags_check_40A5C0(6144) ? 9 : 3;
				}
				if (!(*(uint32_t*)(*(uint32_t*)v3 + 112) & 0x4000000) && a2 + v5 <= v6) {
				LABEL_15:
					++v8;
				}
			}
			v3 += NOX_INVENTORY_ROW_COUNT * sizeof(nox_inventory_cell_t);
		}
		++v2;
		v9 += sizeof(nox_inventory_cell_t);
	} while ((int)v9 < (int)&nox_client_inventory_grid_1050020[NOX_INVENTORY_ROW_COUNT - 1]);
	return v8;
}

//----- (00467BB0) --------------------------------------------------------
int sub_467BB0() {
	int result; // eax

	result = nox_gui_xxx_check_446360();
	if (!result) {
		result = sub_4AE3D0();
		if (!result) {
			result = nox_xxx_guiCursor_477600();
			if (!result) {
				result = nox_xxx_playerAnimCheck_4372B0();
				if (!result) {
					result = nox_xxx_get_57AF20();
					if (!result) {
						if (getMemByte(0x5D4594, 1049868) == 3 || !getMemByte(0x5D4594, 1049868)) {
							*getMemU8Ptr(0x5D4594, 1049868) = 1;
							nox_xxx_clientPlaySoundSpecial_452D80(789, 100);
						}
						result = dword_5d4594_1062516;
						dword_5d4594_1062512 = dword_5d4594_1062516;
					}
				}
			}
		}
	}
	return result;
}

//----- (00467C10) --------------------------------------------------------
int sub_467C10() {
	if (dword_5d4594_1049864 == 6) {
		return 1;
	}
	if (!sub_467C80()) {
		return 0;
	}
	*getMemU8Ptr(0x5D4594, 1049868) = 3;
	nox_xxx_clientPlaySoundSpecial_452D80(790, 100);
	if (dword_5d4594_1049864 == 5) {
		sub_462740();
	}
	sub_467CD0();
	return 1;
}

//----- (00467C60) --------------------------------------------------------
int nox_client_toggleInventory_467C60() {
	int result; // eax

	if (sub_467C80()) {
		result = sub_467C10();
	} else {
		result = sub_467BB0();
	}
	return result;
}

//----- (00467C80) --------------------------------------------------------
int sub_467C80() { return getMemByte(0x5D4594, 1049868) == 1 || getMemByte(0x5D4594, 1049868) == 2; }

//----- (00467CA0) --------------------------------------------------------
int sub_467CA0() {
	int result; // eax

	result = sub_467C80();
	if (!result) {
		dword_5d4594_1062516 = 0;
		result = dword_5d4594_1062508;
		if (dword_5d4594_1062508) {
			result = nox_window_call_field_94(*(int*)&dword_5d4594_1062508, 16394,
											  *(uint32_t*)(*(uint32_t*)(dword_5d4594_1062508 + 32) + 4), 0);
		}
	}
	return result;
}

//----- (00467CD0) --------------------------------------------------------
int sub_467CD0() {
	int v0;            // esi
	char* v1;          // eax
	char* v2;          // edi
	unsigned char* v3; // ebx
	int v4;            // eax
	int v5;            // eax
	int v6;            // eax

	v0 = 0;
	if (*getMemU32Ptr(0x5D4594, 1049848)) {
		if (!dword_5d4594_1049856 &&
			!sub_4649B0(*getMemIntPtr(0x5D4594, 1049848), *(int*)&dword_5d4594_1049796_inventory_click_column_index,
						*(int*)&dword_5d4594_1049800_inventory_click_row_index)) {
			nox_xxx_spritePickup_461660(*(uint32_t*)(*getMemU32Ptr(0x5D4594, 1049848) + 128),
										*(uint32_t*)(*getMemU32Ptr(0x5D4594, 1049848) + 108),
										(const void*)(*getMemU32Ptr(0x5D4594, 1049848) + 432));
			v1 = sub_461EF0(*(uint32_t*)(*getMemU32Ptr(0x5D4594, 1049848) + 128));
			v2 = v1;
			if (v1) {
				v3 = &array_5D4594_1049872;
				*(uint32_t*)(*(uint32_t*)v1 + 132) = 0;
				do {
					v4 = *(uint32_t*)v3;
					if (*(uint32_t*)v3) {
						while (*(uint32_t*)(v4 + 128) != *(uint32_t*)(*getMemU32Ptr(0x5D4594, 1049848) + 128)) {
							v4 = *(uint32_t*)(v4 + 368);
							if (!v4) {
								goto LABEL_12;
							}
						}
						*(uint32_t*)(*(uint32_t*)v2 + 132) = 1;
						if (*(uint32_t*)(*(uint32_t*)v2 + 136)) {
							nox_xxx_clientSetAltWeapon_461550(0);
							*(uint32_t*)(*(uint32_t*)v2 + 136) = 0;
						}
					}
				LABEL_12:
					v3 += 4;
				} while ((int)v3 < &array_5D4594_1049872[9]);
			}
		}
		*getMemU32Ptr(0x5D4594, 1049848) = 0;
		dword_5d4594_1049856 = 0;
		nox_xxx_cursorResetDraggedItem_4776A0();
		v0 = 1;
	}
	v5 = nox_xxx_wndGetCaptureMain_46AE00();
	if (nox_window_is_child(nox_xxx_wndGetHandle_4676A0(), v5) == 1) {
		v6 = nox_xxx_wndGetCaptureMain_46AE00();
		nox_xxx_wndClearCaptureMain_46ADE0(v6);
	}
	return v0;
}

//----- (00467DF0) --------------------------------------------------------
int nox_xxx_gameClearAll_467DF0(int a1) {
	int result; // eax
	int v4[3];  // [esp+0h] [ebp-Ch]

	v4[0] = 25;
	v4[1] = 25;
	v4[2] = 25;
	sub_4460A0(0);
	if (sub_47A260() == 1) {
		sub_47A1F0();
	}
	if (sub_478030() == 1) {
		sub_479280();
	}
	sub_45D810();
	nox_xxx_gameDeleteSpiningCrownSkull_4B8220();
	nox_alloc_npcs_2();
	sub_4573B0();
	if (!nox_common_gameFlags_check_40A5C0(1)) {
		sub_469B90(v4);
		sub_4349C0(v4);
		sub_421B10();
	}
	nox_xxx_spriteDeleteSomeList_49C4B0();
	nox_xxx_sprite_49C4F0();
	sub_49A630();
	sub_49BBB0();
	nox_client_resetScreenParticles_431510();
	nox_xxx_spriteDeleteAll_45A5E0(a1);
	result = nox_common_gameFlags_check_40A5C0(1);
	if (!result) {
		nox_xxx_wall_410160();
		for (int i = 0; i < ptr_5D4594_2650668_cap * 44; i += 44) {
			for (int j = 0; j < ptr_5D4594_2650668_cap; j++) {
				*(uint8_t*)((uint32_t)(ptr_5D4594_2650668[j]) + i) = 0;
				*(uint32_t*)((uint32_t)(ptr_5D4594_2650668[j]) + i + 4) = 255;
				*(uint32_t*)((uint32_t)(ptr_5D4594_2650668[j]) + i + 24) = 255;
				nox_xxx_tileFreeTile_422200((uint32_t)(ptr_5D4594_2650668[j]) + i + 4);
				result = nox_xxx_tileFreeTile_422200((uint32_t)(ptr_5D4594_2650668[j]) + i + 24);
			}
		}
	}
	return result;
}
// 49A2F0: using guessed type int  nox_alloc_npcs_2(uint32_t, uint32_t, uint32_t);

//----- (00469B90) --------------------------------------------------------
int sub_469B90(int* a1) {
	int result; // eax

	*getMemU32Ptr(0x587000, 142296) = *a1;
	*getMemU32Ptr(0x587000, 142300) = a1[1];
	result = a1[2];
	*getMemU32Ptr(0x587000, 142304) = a1[2];
	return result;
}

//----- (00469BB0) --------------------------------------------------------
char* nox_xxx_getAmbientColor_469BB0() { return (char*)getMemAt(0x587000, 142296); }

//----- (00469FA0) --------------------------------------------------------
int sub_469FA0() { return *getMemU32Ptr(0x5D4594, 1064848); }

//----- (00469FB0) --------------------------------------------------------
int sub_469FB0(const char* a1) {
	int v1;          // ebp
	const char** v2; // edi

	v1 = 0;
	v2 = (const char**)getMemAt(0x587000, 142868);
	while (strcmp(*v2, a1)) {
		++v2;
		++v1;
		if ((int)v2 >= (int)getMemAt(0x587000, 142928)) {
			return -1;
		}
	}
	return v1;
}

//----- (0046A010) --------------------------------------------------------
int nox_thing_read_wall_46A010(nox_memfile* f, char* a2) {
	uint32_t* a1 = f;
	uint32_t* v2;       // esi
	char* v3;           // ebx
	unsigned char* v4;  // edx
	int v5;             // ecx
	const char* v6;     // edi
	int v8;             // ebp
	unsigned char* v9;  // eax
	unsigned char* v10; // eax
	unsigned char* v11; // eax
	unsigned char* v12; // eax
	int v13;            // ebp
	int v14;            // edi
	unsigned char* v15; // ebp
	int* v16;           // eax
	int v17;            // ecx
	int* v18;           // eax
	int v19;            // ecx
	int* v20;           // eax
	int v21;            // ecx
	char* v22;          // eax
	char v23;           // cl
	int v24;            // edi
	char* v25;          // eax
	unsigned char* v26; // ecx
	bool v27;           // zf
	int* v28;           // eax
	int v29;            // ecx
	uint32_t* v30;      // [esp-4h] [ebp-40h]
	int v31;            // [esp+10h] [ebp-2Ch]
	unsigned char* v32; // [esp+14h] [ebp-28h]
	int v33;            // [esp+18h] [ebp-24h]
	int v34;            // [esp+1Ch] [ebp-20h]
	int v35;            // [esp+20h] [ebp-1Ch]
	int v36;            // [esp+24h] [ebp-18h]
	int v37;            // [esp+28h] [ebp-14h]
	int v38;            // [esp+2Ch] [ebp-10h]
	int v39;            // [esp+30h] [ebp-Ch]
	int v40;            // [esp+34h] [ebp-8h]
	const char* v41;    // [esp+38h] [ebp-4h]
	unsigned char v42;  // [esp+40h] [ebp+4h]
	unsigned char v43;  // [esp+40h] [ebp+4h]
	unsigned char v44;  // [esp+40h] [ebp+4h]
	unsigned char v45;  // [esp+40h] [ebp+4h]
	unsigned char v46;  // [esp+40h] [ebp+4h]
	const char** v47;   // [esp+40h] [ebp+4h]
	unsigned char* v48; // [esp+44h] [ebp+8h]
	int v49;            // [esp+44h] [ebp+8h]

	v2 = a1;
	v3 = a2;
	v30 = a1;
	v4 = (unsigned char*)(a1[2] + 4);
	a1[2] = v4;
	v42 = *v4;
	v2[2] = v4 + 1;
	nox_memfile_read(a2, 1u, v42, (int)v30);
	a2[v42] = 0;
	v5 = 0;
	if (dword_5d4594_251540 <= 0) {
		return 0;
	}
	v6 = (const char*)getMemAt(0x85B3FC, 43044);
	v48 = getMemAt(0x85B3FC, 43044);
	while (strcmp(v6, v3)) {
		++v5;
		v6 = (const char*)(v48 + 12332);
		v48 += 12332;
		if (v5 >= dword_5d4594_251540) {
			return 0;
		}
	}
	v49 = v5;
	if (v5 == -1) {
		return 0;
	}
	v38 = 12332 * v5;
	memset(getMemAt(0x85B3FC, 51476 + 12332 * v5), 0, 0xF00u);
	v2[2] += 14;
	nox_memfile_read64align_40AD60((char*)&v31, 1, 1, v2);
	v8 = 0;
	if ((uint8_t)v31) {
		if (v8 >= 8) {
			return 0;
		}
		while (1) {
			v9 = (unsigned char*)v2[2];
			v43 = *v9;
			v2[2] = v9 + 1;
			nox_memfile_read(v3, 1u, v43, (int)v2);
			v3[v43] = 0;
			if (++v8 >= (unsigned char)v31) {
				break;
			}
			if (v8 >= 8) {
				return 0;
			}
		}
	}
	v10 = (unsigned char*)v2[2];
	v44 = *v10;
	v2[2] = v10 + 1;
	nox_memfile_read(v3, 1u, v44, (int)v2);
	v3[v44] = 0;
	v11 = (unsigned char*)v2[2];
	v45 = *v11;
	v2[2] = v11 + 1;
	nox_memfile_read(v3, 1u, v45, (int)v2);
	v3[v45] = 0;
	v12 = (unsigned char*)v2[2];
	v46 = *v12;
	v2[2] = v12 + 1;
	nox_memfile_read(v3, 1u, v46, (int)v2);
	v3[v46] = 0;
	++v2[2];
	v47 = (const char**)getMemAt(0x587000, 142868);
	while (1) {
		v13 = sub_469FB0(*v47);
		v36 = v13;
		if (v13 < 0) {
			break;
		}
		nox_memfile_read64align_40AD60((char*)&v35, 1, 1, v2);
		if ((unsigned char)v35 >= 0x10u) {
			break;
		}
		v14 = 0;
		v34 = 0;
		if ((uint8_t)v35) {
			v37 = 3083 * v49;
			while (1) {
				v33 = 4;
				v32 = getMemAt(0x85B3FC, 51476 + 4 * (v14 + 16 * v13 + v37));
				v15 = getMemAt(0x85B3FC, 43800 + 8 * (v14 + 16 * v13) + v38);
				do {
					v16 = (int*)v2[2];
					v17 = *v16;
					v2[2] = v16 + 1;
					*((uint32_t*)v15 - 1) = v17;
					v18 = (int*)v2[2];
					v19 = *v18;
					v2[2] = v18 + 1;
					*(uint32_t*)v15 = v19;
					v20 = (int*)v2[2];
					v21 = *v20;
					v2[2] = v20 + 1;
					v40 = v21;
					*v3 = getMemByte(0x5D4594, 1064852);
					if (v21 == -1) {
						v22 = (char*)v2[2];
						v23 = *v22++;
						v2[2] = v22;
						LOBYTE(v41) = v23;
						LOBYTE(v39) = *v22;
						v2[2] = v22 + 1;
						v24 = (unsigned char)v39;
						nox_memfile_read(v3, (unsigned char)v39, 1, (int)v2);
						v21 = v40;
						v3[v24] = 0;
						v14 = v34;
					}
					v25 = nox_xxx_readImgMB_42FAA0(v21, v41, v3);
					v26 = v32;
					v15 += 1920;
					*(uint32_t*)v32 = v25;
					v27 = v33 == 1;
					v32 = v26 + 960;
					--v33;
				} while (!v27);
				v34 = ++v14;
				if (v14 >= (unsigned char)v35) {
					break;
				}
				v13 = v36;
			}
		}
		++v47;
		if ((int)v47 >= (int)getMemAt(0x587000, 142928)) {
			v28 = (int*)v2[2];
			v29 = *v28;
			v2[2] = v28 + 1;
			return v29 == 1162757152;
		}
	}
	return 0;
}

//----- (0046A3B0) --------------------------------------------------------
int nox_xxx_getWallSprite_46A3B0(int a1, int a2, int a3, int a4) {
	return *getMemU32Ptr(0x85B3FC, 51476 + 4 * (16 * (a2 + 12 * a4 + 3 * a4) + a3 + 3083 * a1));
}

//----- (0046A3F0) --------------------------------------------------------
char* nox_xxx_getWallDrawOffset_46A3F0(int a1, int a2, int a3, int a4) {
	return (char*)getMemAt(0x85B3FC, 43796 + 12332 * a1 + 8 * (a3 + 16 * (a2 + 12 * a4 + 3 * a4)));
}

//----- (0046A430) --------------------------------------------------------
void nox_client_chatStart_46A430(int a1) {
	if (!nox_common_gameFlags_check_40A5C0(2048)) {
		if (!dword_5d4594_1064868) {
			**(uint16_t**)&dword_5d4594_1064864 = 0;
			*(uint16_t*)(dword_5d4594_1064864 + 1052) = 0;
			nox_xxx_wndShowModalMB_46A8C0(*(int*)&dword_5d4594_1064856);
			sub_46C690(*(int*)&dword_5d4594_1064856);
			nox_xxx_windowFocus_46B500(*(int*)&dword_5d4594_1064860);
			dword_5d4594_1064868 = 1;
			*getMemU32Ptr(0x5D4594, 1064872) = a1;
		}
	}
}

//----- (0046A4A0) --------------------------------------------------------
int sub_46A4A0() { return dword_5d4594_1064868; }

//----- (0046A4B0) --------------------------------------------------------
size_t nox_xxx_cmdSayDo_46A4B0(wchar2_t* a1, int a2) {
	uint32_t* v2;      // ebp
	size_t v3;         // edi
	size_t result;     // eax
	const wchar2_t* v5; // edi
	char v6;           // al
	int v7;            // eax
	char v8[520];      // [esp+Ch] [ebp-208h]

	v2 = nox_xxx_netSpriteByCodeDynamic_45A6F0(nox_player_netCode_85319C);
	v3 = nox_wcsspn(a1, L" ");
	result = nox_wcslen(a1);
	if (v3 != result) {
		v5 = &a1[v3];
		v8[0] = -88;
		*(uint16_t*)&v8[9] = 0;
		*(uint16_t*)&v8[1] = nox_player_netCode_85319C;
		v8[3] = 0;
		if (nox_xxx_cliCanTalkMB_4100F0((short*)a1)) {
			v6 = v8[3] | 2;
		} else {
			v6 = v8[3] | 4;
		}
		v8[3] = v6;
		if (a2) {
			v8[3] |= 1u;
		}
		v8[8] = nox_wcslen(v5) + 1;
		if (v8[3] & 4) {
			nox_wcscpy((wchar2_t*)&v8[11], v5);
			v7 = 2;
		} else {
			nox_sprintf(&v8[11], "%S", v5);
			v7 = 1;
		}
		if (v2) {
			*(uint16_t*)&v8[4] = *((uint16_t*)v2 + 6);
			*(uint16_t*)&v8[6] = *((uint16_t*)v2 + 8);
		} else {
			*(uint16_t*)&v8[6] = -1;
			*(uint16_t*)&v8[4] = -1;
		}
		result = nox_netlist_addToMsgListCli_40EBC0(31, 0, v8, v7 * (unsigned char)v8[8] + 11);
	}
	return result;
}

//----- (0046A5D0) --------------------------------------------------------
int sub_46A5D0(uint32_t* a1, int a2) {
	int v2;  // ecx
	bool v3; // sf
	int v5;  // [esp+4h] [ebp-8h]
	int v6;  // [esp+8h] [ebp-4h]

	v5 = 0;
	v6 = 0;
	nox_xxx_wndShowModalMB_46A8C0(*(int*)&dword_5d4594_1064856);
	nox_xxx_windowFocus_46B500(*(int*)&dword_5d4594_1064860);
	nox_xxx_drawGetStringSize_43F840(0, *(unsigned short**)&dword_5d4594_1064864, &v5, 0, 0);
	nox_xxx_drawGetStringSize_43F840(0, (unsigned short*)(dword_5d4594_1064864 + 512), &v6, 0, 0);
	v3 = v5 + v6 - 90 < 0;
	v5 += v6 + 10;
	v2 = v5;
	if (v5 < 100) {
		v2 = 100;
	LABEL_5:
		v5 = v2;
		goto LABEL_6;
	}
	if (v5 > 320) {
		v2 = 320;
		goto LABEL_5;
	}
LABEL_6:
	nox_window_setPos_46A9B0(*(uint32_t**)&dword_5d4594_1064856, (nox_win_width - v2) / 2,
							 *(uint32_t*)(dword_5d4594_1064856 + 20));
	sub_46AB20(a1, v5, 20);
	return nox_xxx_wndEditDrawNoImage_488160((int)a1, a2);
}

//----- (0046A6A0) --------------------------------------------------------
int sub_46A6A0() {
	if (wndIsShown_nox_xxx_wndIsShown_46ACC0(*(int*)&dword_5d4594_1064856)) {
		return 0;
	}
	if (nox_xxx_wndGetFocus_46B4F0() == dword_5d4594_1064860) {
		nox_xxx_windowFocus_46B500(0);
	}
	nox_xxx_wnd_46C6E0(*(int*)&dword_5d4594_1064856);
	nox_window_set_hidden(*(int*)&dword_5d4594_1064856, 1);
	*(uint32_t*)(dword_5d4594_1064856 + 4) &= 0xFFFFFFF7;
	*(uint32_t*)(dword_5d4594_1064860 + 4) &= 0xFFFFFFF7;
	set_dword_5d4594_3799468(1);
	dword_5d4594_1064868 = 0;
	return 1;
}

//----- (0046A730) --------------------------------------------------------
uint32_t* sub_46A730() {
	uint32_t* result; // eax

	*getMemU32Ptr(0x5D4594, 1064876) = nox_win_width / 2;
	*getMemU32Ptr(0x5D4594, 1064880) = 2 * nox_win_height / 3;
	result = nox_new_window_from_file("GuiChat.wnd", sub_46A820);
	dword_5d4594_1064856 = result;
	if (result) {
		nox_window_setPos_46A9B0(result, *getMemIntPtr(0x5D4594, 1064876), *getMemIntPtr(0x5D4594, 1064880));
		result = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1064856, 9201);
		dword_5d4594_1064860 = result;
		if (result) {
			nox_xxx_wndSetDrawFn_46B340((int)result, sub_46A5D0);
			nox_xxx_wndSetWindowProc_46B300(*(int*)&dword_5d4594_1064860, sub_46A7E0);
			result = *(uint32_t**)&dword_5d4594_1064856;
			dword_5d4594_1064864 = *(uint32_t*)(dword_5d4594_1064860 + 32);
		}
	}
	return result;
}

//----- (0046A7E0) --------------------------------------------------------
int sub_46A7E0(uint32_t* a1, int a2, int a3, int a4) {
	if (a2 != 21 || a3 != 1) {
		return nox_xxx_wndEditProc_487D70(a1, a2, a3, a4);
	}
	if (a4 == 2) {
		nox_xxx_consoleEsc_49B7A0();
	}
	return 1;
}

//----- (0046A820) --------------------------------------------------------
int sub_46A820(int a1, int a2, int a3, int a4) {
	if (a2 == 16415) {
		if (*(uint16_t*)(dword_5d4594_1064864 + 1052)) {
			nox_xxx_cmdSayDo_46A4B0(*(wchar2_t**)&dword_5d4594_1064864, *getMemIntPtr(0x5D4594, 1064872));
		}
		sub_46A6A0();
	}
	return 0;
}

//----- (0046A860) --------------------------------------------------------
int sub_46A860() {
	int result; // eax

	result = dword_5d4594_1064856;
	if (dword_5d4594_1064856) {
		result = nox_xxx_windowDestroyMB_46C4E0(*(uint32_t**)&dword_5d4594_1064856);
		dword_5d4594_1064856 = 0;
	}
	dword_5d4594_1064860 = 0;
	dword_5d4594_1064864 = 0;
	dword_5d4594_1064868 = 0;
	*getMemU32Ptr(0x5D4594, 1064872) = 0;
	return result;
}

//----- (0046A8A0) --------------------------------------------------------
int nox_xxx_wndRetNULL_46A8A0() { return 0; }

//----- (0046A8B0) --------------------------------------------------------
int nox_xxx_wndRetNULL_0_46A8B0() { return 0; }

//----- (0046AE10) --------------------------------------------------------
int sub_46AE10(int a1, int a2) {
	int result; // eax
	int v3;     // ecx

	result = a1;
	if (a1) {
		v3 = *(uint32_t*)(a1 + 36);
		if (a2) {
			*(uint32_t*)(a1 + 36) = v3 | 2;
		} else {
			*(uint32_t*)(a1 + 36) = v3 & 0xFFFFFFFD;
		}
	}
	return result;
}

//----- (0046AE40) --------------------------------------------------------
int nox_xxx_wndSetOffsetMB_46AE40(int a1, int a2, int a3) {
	int result; // eax

	result = a1;
	if (a1) {
		*(uint32_t*)(a1 + 96) = a2;
		*(uint32_t*)(a1 + 100) = a3;
	}
	return result;
}

//----- (0046AE60) --------------------------------------------------------
int nox_xxx_wndSetIcon_46AE60(int a1, int a2) {
	if (!a1) {
		return -2;
	}
	*(uint32_t*)(a1 + 60) = a2;
	return 0;
}

//----- (0046AEA0) --------------------------------------------------------
int nox_xxx_wndSetIconLit_46AEA0(int a1, int a2) {
	if (!a1) {
		return -2;
	}
	*(uint32_t*)(a1 + 76) = a2;
	return 0;
}

//----- (0046AEC0) --------------------------------------------------------
int sub_46AEC0(int a1, int a2) {
	if (!a1) {
		return -2;
	}
	*(uint32_t*)(a1 + 92) = a2;
	return 0;
}

//----- (0046AEE0) --------------------------------------------------------
int sub_46AEE0(int a1, int a2) {
	nox_window_call_field_94(a1, 16385, a2, 0);
	return 0;
}

//----- (0046AF00) --------------------------------------------------------
wchar2_t* sub_46AF00(void* a1p) {
	int a1 = a1p;
	int v1;     // ecx
	int result; // eax

	if (!a1) {
		goto LABEL_9;
	}
	v1 = *(uint32_t*)(a1 + 44);
	if (v1 & 0x800) {
		return nox_window_call_field_94(a1, 16386, 0, 0);
	}
	if ((v1 & 0x80u) != 0) {
		result = nox_window_call_field_94(a1, 16413, 0, 0);
	} else {
	LABEL_9:
		result = 0;
	}
	return result;
}

//----- (0046AF40) --------------------------------------------------------
void* sub_46AF40(void* a1p) {
	int a1 = a1p;
	int result; // eax

	result = a1;
	if (a1) {
		result = *(uint32_t*)(a1 + 236);
	}
	return result;
}

//----- (0046AF80) --------------------------------------------------------
int nox_gui_windowCopyDrawData_46AF80(nox_window* win, const void* p) {
	if (!win) {
		return -2;
	}
	if (!p) {
		return -3;
	}
	memcpy(&win->draw_data, p, sizeof(nox_window_data));
	return 0;
}

//----- (0046B630) --------------------------------------------------------
nox_window* sub_46B630(nox_window* a1p, int a2, int a3) {
	int a1 = a1p;
	int result;   // eax
	int i;        // esi
	uint32_t* v5; // ecx
	int v6;       // edx
	int j;        // edi

	result = a1;
	if (a1) {
	LABEL_2:
		for (i = *(uint32_t*)(result + 400); i; i = *(uint32_t*)(i + 388)) {
			v5 = *(uint32_t**)(i + 396);
			v6 = *(uint32_t*)(i + 16);
			for (j = *(uint32_t*)(i + 20); v5; v5 = (uint32_t*)v5[99]) {
				v6 += v5[4];
				j += v5[5];
			}
			if (a2 >= v6 && a2 <= v6 + *(uint32_t*)(i + 8) && a3 >= j && a3 <= j + *(uint32_t*)(i + 12) &&
				!(*(uint8_t*)(i + 4) & 0x10)) {
				result = i;
				goto LABEL_2;
			}
		}
	}
	return result;
}

//----- (0046C2A0) --------------------------------------------------------
int nox_xxx_wnd_46C2A0(nox_window* a1p) {
	int a1 = a1p;
	int v2; // eax

	if (!a1) {
		return 1;
	}
	if (*(uint8_t*)(a1 + 4) & 0x10) {
		return 1;
	}
	v2 = *(uint32_t*)(a1 + 396);
	if (v2) {
		while (!(*(uint8_t*)(v2 + 4) & 0x10)) {
			v2 = *(uint32_t*)(v2 + 396);
			if (!v2) {
				return 0;
			}
		}
		return 1;
	}
	return 0;
}

//----- (0046DB80) --------------------------------------------------------
int sub_46DB80() {
	int i;      // esi
	int result; // eax

	for (i = 0; i < 8; i += 4) {
		nox_window_call_field_94(*getMemU32Ptr(0x5D4594, 1090060 + i), 16399, 1, 0);
		nox_window_call_field_94(*getMemU32Ptr(0x5D4594, 1090068 + i), 16399, 1, 0);
		nox_window_call_field_94(*getMemU32Ptr(0x5D4594, 1090076 + i), 16399, 1, 0);
		nox_window_call_field_94(*getMemU32Ptr(0x5D4594, 1090084 + i), 16399, 1, 0);
		result = nox_window_call_field_94(*getMemU32Ptr(0x5D4594, 1090092 + i), 16399, 1, 0);
	}
	return result;
}

//----- (0046DC00) --------------------------------------------------------
int sub_46DC00(int a1, unsigned char a2, int a3) {
	nox_window_call_field_94(a1, 16397, a3, a2);
	return 1;
}

//----- (0046DC30) --------------------------------------------------------
int sub_46DC30(int a1, unsigned char a2, wchar2_t* a3, ...) {
	va_list va; // [esp+10h] [ebp+10h]

	va_start(va, a3);
	nox_vswprintf((wchar2_t*)getMemAt(0x5D4594, 1089000), a3, va);
	return sub_46DC00(a1, a2, (int)getMemAt(0x5D4594, 1089000));
}

//----- (0046DCC0) --------------------------------------------------------
char* sub_46DCC0() {
	char* result;      // eax
	signed int v1;     // ebx
	unsigned int v2;   // esi
	unsigned int v3;   // edi
	int v4;            // ebp
	char* k;           // esi
	int v6;            // eax
	char* l;           // eax
	int v8;            // ecx
	int v9;            // ebx
	int v10;           // esi
	char* v11;         // edi
	int m;             // ebp
	unsigned char v13; // dl
	int v14;           // eax
	int v15;           // ecx
	int v16;           // edi
	uint32_t* v17;     // eax
	uint32_t* v18;     // edi
	char* v19;         // eax
	int v20;           // edx
	unsigned char v21; // al
	int v22;           // ecx
	unsigned int v23;  // esi
	char* i;           // eax
	int v25;           // ecx
	unsigned int v26;  // ebp
	int v27;           // esi
	char* v28;         // edi
	unsigned int j;    // ebx
	unsigned char v30; // dl
	int v31;           // eax
	int v32;           // ecx
	int v33;           // ecx
	int v34;           // edi
	uint32_t* v35;     // eax
	uint32_t* v36;     // edi
	char* v37;         // eax
	int v38;           // edx
	unsigned char v39; // al
	int v40;           // ecx
	unsigned int v41;  // [esp+0h] [ebp-8h]
	wchar2_t* v42;      // [esp+4h] [ebp-4h]
	wchar2_t* v43;      // [esp+4h] [ebp-4h]

	if (dword_5d4594_1090120 == 5) {
		v23 = nox_common_playerInfoCount_416F40();
		v43 = (wchar2_t*)v23;
		*getMemU8Ptr(0x5D4594, 1090117) = 0;
		*getMemU8Ptr(0x5D4594, 1090118) = 0;
		if (nox_common_gameFlags_check_40A5C0(1) &&
			nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
			v43 = (wchar2_t*)--v23;
		}
		for (i = nox_common_playerInfoGetFirst_416EA0(); i; i = nox_common_playerInfoGetNext_416EE0((int)i)) {
			v25 = *((uint32_t*)i + 920);
			if (!(v25 & 1) || v25 & 0x20) {
				if (!*((uint32_t*)i + 527)) {
					*((uint32_t*)i + 527) = 0x8000000;
				}
			} else {
				*((uint32_t*)i + 527) |= 0x80000000;
			}
		}
		v26 = 0;
		if (getMemByte(0x5D4594, 1090117) < v23) {
			v27 = (int)v43;
			do {
				v28 = nox_common_playerInfoGetFirst_416EA0();
				for (j = -1; v28; v28 = nox_common_playerInfoGetNext_416EE0((int)v28)) {
					if ((v28[2064] != 31 || !nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) &&
						*((int*)v28 + 527) >= v26 && !sub_46E1E0(*((uint32_t*)v28 + 515)) && *((int*)v28 + 527) < j) {
						j = *((uint32_t*)v28 + 527);
						v27 = (int)v28;
					}
				}
				v30 = getMemByte(0x5D4594, 1090117);
				v31 = 80 * getMemByte(0x5D4594, 1090117);
				*getMemU32Ptr(0x5D4594, 1084192 + v31) = *(uint32_t*)(v27 + 2060);
				v32 = *(uint32_t*)(v27 + 3680);
				if (!(v32 & 1) || v32 & 0x20) {
					v33 = *(uint32_t*)(v27 + 2108);
					if (v33 == 0x8000000) {
						*getMemU32Ptr(0x5D4594, 1084196 + v31) = 0;
					} else {
						*getMemU32Ptr(0x5D4594, 1084196 + v31) = v33;
						++*getMemU8Ptr(0x5D4594, 1090118);
					}
				} else {
					*getMemU32Ptr(0x5D4594, 1084196 + v31) = *(uint32_t*)(v27 + 2108) + 0x80000000;
				}
				*getMemU32Ptr(0x5D4594, 1084200 + v31) = *(unsigned short*)(v27 + 2148);
				*getMemU32Ptr(0x5D4594, 1084208 + v31) = *(uint32_t*)(v27 + 3680);
				v34 = 80 * v30;
				*getMemU32Ptr(0x5D4594, 1084204 + v34) = sub_46E080(v27);
				nox_wcscpy((wchar2_t*)getMemAt(0x5D4594, 1084132 + v34), (const wchar2_t*)(v27 + 4704));
				sub_46E170((wchar2_t*)getMemAt(0x5D4594, 1084132 + 80 * getMemByte(0x5D4594, 1090117)));
				*getMemU8Ptr(0x5D4594, 1084188 + 80 * getMemByte(0x5D4594, 1090117)) = *(uint8_t*)(v27 + 2251);
				v35 = nox_xxx_objGetTeamByNetCode_418C80(*(uint32_t*)(v27 + 2060));
				v36 = v35;
				if (v35 && nox_xxx_servObjectHasTeam_419130((int)v35)) {
					v37 = nox_xxx_clientGetTeamColor_418AB0(*((unsigned char*)v36 + 4));
					if (v37) {
						v38 = (unsigned char)v37[57];
						v39 = getMemByte(0x5D4594, 1090117);
						*getMemU32Ptr(0x5D4594, 1084184 + 80 * getMemByte(0x5D4594, 1090117)) = v38;
					} else {
						v39 = getMemByte(0x5D4594, 1090117);
						*getMemU32Ptr(0x5D4594, 1084184 + 80 * getMemByte(0x5D4594, 1090117)) = -1;
					}
				} else {
					v39 = getMemByte(0x5D4594, 1090117);
					*getMemU32Ptr(0x5D4594, 1084184 + 80 * getMemByte(0x5D4594, 1090117)) = -1;
				}
				*getMemU8Ptr(0x5D4594, 1090117) = v39 + 1;
				v26 = j;
			} while ((unsigned char)(v39 + 1) < (unsigned int)v43);
		}
		for (result = nox_common_playerInfoGetFirst_416EA0(); result;
			 result = nox_common_playerInfoGetNext_416EE0((int)result)) {
			v40 = *((uint32_t*)result + 920);
			if (!(v40 & 1) || v40 & 0x20) {
				if (*((uint32_t*)result + 527) == 0x8000000) {
					*((uint32_t*)result + 527) = 0;
				}
			} else {
				*((uint32_t*)result + 527) &= 0x7FFFFFFFu;
			}
		}
	} else if (nox_common_gameFlags_check_40A5C0(1024)) {
		v1 = 0x80000000;
		v41 = nox_common_playerInfoCount_416F40();
		v2 = nox_xxx_getTeamCounter_417DD0();
		*getMemU8Ptr(0x5D4594, 1090116) = 0;
		v42 = (wchar2_t*)v2;
		*getMemU8Ptr(0x5D4594, 1090117) = 0;
		*getMemU8Ptr(0x5D4594, 1090118) = 0;
		if (nox_common_gameFlags_check_40A5C0(1) &&
			nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
			--v41;
		}
		if (getMemByte(0x5D4594, 1090116) < v2) {
			v3 = v2;
			do {
				v4 = 0x7FFFFFFF;
				for (k = nox_server_teamFirst_418B10(); k; k = nox_server_teamNext_418B60((int)k)) {
					if (*((int*)k + 13) >= v1 && !sub_46E130((unsigned char)k[57]) && *((int*)k + 13) < v4) {
						v4 = *((uint32_t*)k + 13);
						v3 = (unsigned int)k;
					}
				}
				v6 = 56 * getMemByte(0x5D4594, 1090116);
				*getMemU32Ptr(0x5D4594, 1087252 + v6) = *(uint32_t*)(v3 + 52);
				*getMemU32Ptr(0x5D4594, 1087248 + v6) = *(unsigned char*)(v3 + 57);
				*getMemU8Ptr(0x5D4594, 1087256 + v6) = *(uint8_t*)(v3 + 56);
				nox_wcscpy((wchar2_t*)getMemAt(0x5D4594, 1087204 + v6), (const wchar2_t*)v3);
				sub_46E170((wchar2_t*)getMemAt(0x5D4594, 1087204 + 56 * getMemByte(0x5D4594, 1090116)));
				++*getMemU8Ptr(0x5D4594, 1090116);
				v1 = v4;
			} while (getMemByte(0x5D4594, 1090116) < (unsigned int)v42);
		}
		for (l = nox_common_playerInfoGetFirst_416EA0(); l; l = nox_common_playerInfoGetNext_416EE0((int)l)) {
			v8 = *((uint32_t*)l + 920);
			if (v8 & 1 && !(v8 & 0x20)) {
				*((uint32_t*)l + 535) += 0xFFFF;
			}
		}
		v9 = -1;
		if (getMemByte(0x5D4594, 1090117) < v41) {
			v10 = (int)v42;
			do {
				v11 = nox_common_playerInfoGetFirst_416EA0();
				for (m = 0x7FFFFFFF; v11; v11 = nox_common_playerInfoGetNext_416EE0((int)v11)) {
					if ((v11[2064] != 31 || !nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) &&
						*((int*)v11 + 535) >= v9 && !sub_46E1E0(*((uint32_t*)v11 + 515)) && *((int*)v11 + 535) < m) {
						m = *((uint32_t*)v11 + 535);
						v10 = (int)v11;
					}
				}
				v13 = getMemByte(0x5D4594, 1090117);
				v14 = 80 * getMemByte(0x5D4594, 1090117);
				*getMemU32Ptr(0x5D4594, 1084192 + v14) = *(uint32_t*)(v10 + 2060);
				v15 = *(uint32_t*)(v10 + 3680);
				if (!(v15 & 1) || v15 & 0x20) {
					*getMemU32Ptr(0x5D4594, 1084196 + v14) = *(uint32_t*)(v10 + 2140);
					++*getMemU8Ptr(0x5D4594, 1090118);
				} else {
					*getMemU32Ptr(0x5D4594, 1084196 + v14) = *(uint32_t*)(v10 + 2140) - 0xFFFF;
				}
				*getMemU32Ptr(0x5D4594, 1084200 + v14) = *(unsigned short*)(v10 + 2148);
				*getMemU32Ptr(0x5D4594, 1084208 + v14) = *(uint32_t*)(v10 + 3680);
				v16 = 80 * v13;
				*getMemU32Ptr(0x5D4594, 1084204 + v16) = sub_46E080(v10);
				nox_wcscpy((wchar2_t*)getMemAt(0x5D4594, 1084132 + v16), (const wchar2_t*)(v10 + 4704));
				sub_46E170((wchar2_t*)getMemAt(0x5D4594, 1084132 + 80 * getMemByte(0x5D4594, 1090117)));
				*getMemU8Ptr(0x5D4594, 1084188 + 80 * getMemByte(0x5D4594, 1090117)) = *(uint8_t*)(v10 + 2251);
				v17 = nox_xxx_objGetTeamByNetCode_418C80(*(uint32_t*)(v10 + 2060));
				v18 = v17;
				if (v17 && nox_xxx_servObjectHasTeam_419130((int)v17)) {
					v19 = nox_xxx_clientGetTeamColor_418AB0(*((unsigned char*)v18 + 4));
					if (v19) {
						v20 = (unsigned char)v19[57];
						v21 = getMemByte(0x5D4594, 1090117);
						*getMemU32Ptr(0x5D4594, 1084184 + 80 * getMemByte(0x5D4594, 1090117)) = v20;
					} else {
						v21 = getMemByte(0x5D4594, 1090117);
						*getMemU32Ptr(0x5D4594, 1084184 + 80 * getMemByte(0x5D4594, 1090117)) = -1;
					}
				} else {
					v21 = getMemByte(0x5D4594, 1090117);
					*getMemU32Ptr(0x5D4594, 1084184 + 80 * getMemByte(0x5D4594, 1090117)) = -1;
				}
				*getMemU8Ptr(0x5D4594, 1090117) = v21 + 1;
				v9 = m;
			} while ((unsigned char)(v21 + 1) < v41);
		}
		for (result = nox_common_playerInfoGetFirst_416EA0(); result;
			 result = nox_common_playerInfoGetNext_416EE0((int)result)) {
			v22 = *((uint32_t*)result + 920);
			if (v22 & 1) {
				if (!(v22 & 0x20)) {
					*((uint32_t*)result + 535) -= 0xFFFF;
				}
			}
		}
	} else {
		result = sub_46E4E0();
	}
	return result;
}

//----- (0046E080) --------------------------------------------------------
int sub_46E080(int a1) {
	int v1;       // eax
	uint32_t* v3; // eax

	if (nox_common_gameFlags_check_40A5C0(32)) {
		v1 = *(uint32_t*)(a1 + 2060);
		if (v1 == *getMemU16Ptr(0x5D4594, 1090128)) {
			return 2;
		}
		if (v1 == *getMemU16Ptr(0x5D4594, 1090130)) {
			return 3;
		}
	} else if (nox_common_gameFlags_check_40A5C0(64)) {
		if (*(uint32_t*)(a1 + 2060) == *getMemU16Ptr(0x5D4594, 1090132)) {
			return 4;
		}
	} else if (nox_common_gameFlags_check_40A5C0(16)) {
		v3 = nox_xxx_netSpriteByCodeDynamic_45A6F0(*(uint32_t*)(a1 + 2060));
		if (v3) {
			if (nox_client_drawable_testBuff_4356C0((int)v3, 30)) {
				return 1;
			}
		}
	}
	return 0;
}

//----- (0046E130) --------------------------------------------------------
int sub_46E130(int a1) {
	int v1;           // eax
	unsigned char* i; // ecx

	v1 = 0;
	if (!getMemByte(0x5D4594, 1090116)) {
		return 0;
	}
	for (i = getMemAt(0x5D4594, 1087248); *(uint32_t*)i != a1; i += 56) {
		if (++v1 >= (unsigned int)getMemByte(0x5D4594, 1090116)) {
			return 0;
		}
	}
	return 1;
}

//----- (0046E170) --------------------------------------------------------
unsigned short* sub_46E170(wchar2_t* a1) {
	if (!a1 || !*getMemIntPtr(0x5D4594, 1084036)) {
		return 0;
	}
	unsigned short* v1; // esi
	size_t v2;          // edi

	v1 = a1;
	v2 = nox_wcslen(a1);
	int a1a = 0;
	nox_xxx_drawGetStringSize_43F840(0, v1, &a1a, 0, 0);
	if (a1a == 0) {
		return 0;
	}
	if ((a1a + 5) > *getMemIntPtr(0x5D4594, 1084036)) {
		unsigned short* v3 = &v1[v2];
		do {
			*v3 = 0;
			--v3;
			nox_xxx_drawGetStringSize_43F840(0, v1, (int*)&a1a, 0, 0);
		} while ((a1a + 5) > *getMemIntPtr(0x5D4594, 1084036));
	}
	return v1;
}

//----- (0046E1E0) --------------------------------------------------------
int sub_46E1E0(int a1) {
	int v1;           // eax
	unsigned char* i; // ecx

	v1 = 0;
	if (!getMemByte(0x5D4594, 1090117)) {
		return 0;
	}
	for (i = getMemAt(0x5D4594, 1084192); *(uint32_t*)i != a1; i += 80) {
		if (++v1 >= (unsigned int)getMemByte(0x5D4594, 1090117)) {
			return 0;
		}
	}
	return 1;
}

//----- (0046E4E0) --------------------------------------------------------
char* sub_46E4E0() {
	int v0;            // ebx
	unsigned int v1;   // esi
	unsigned int v2;   // edi
	signed int v3;     // ebp
	char* i;           // esi
	int v5;            // eax
	char* j;           // eax
	int v7;            // ecx
	int v8;            // ebx
	int v9;            // esi
	char* v10;         // edi
	signed int k;      // ebp
	unsigned char v12; // dl
	int v13;           // eax
	int v14;           // ecx
	int v15;           // edi
	uint32_t* v16;     // eax
	uint32_t* v17;     // edi
	char* v18;         // eax
	int v19;           // edx
	unsigned char v20; // al
	char* result;      // eax
	int v22;           // ecx
	unsigned int v23;  // [esp+10h] [ebp-8h]
	wchar2_t* v24;      // [esp+14h] [ebp-4h]

	v0 = 0x7FFFFFFF;
	v1 = nox_xxx_getTeamCounter_417DD0();
	v24 = (wchar2_t*)v1;
	v23 = nox_common_playerInfoCount_416F40();
	*getMemU8Ptr(0x5D4594, 1090116) = 0;
	*getMemU8Ptr(0x5D4594, 1090117) = 0;
	*getMemU8Ptr(0x5D4594, 1090118) = 0;
	if (nox_common_gameFlags_check_40A5C0(1) && nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
		--v23;
	}
	if (getMemByte(0x5D4594, 1090116) < v1) {
		v2 = v1;
		do {
			v3 = 0x80000000;
			for (i = nox_server_teamFirst_418B10(); i; i = nox_server_teamNext_418B60((int)i)) {
				if (*((int*)i + 13) <= v0 && !sub_46E130((unsigned char)i[57]) && *((int*)i + 13) > v3) {
					v3 = *((uint32_t*)i + 13);
					v2 = (unsigned int)i;
				}
			}
			v5 = 56 * getMemByte(0x5D4594, 1090116);
			*getMemU32Ptr(0x5D4594, 1087252 + v5) = *(uint32_t*)(v2 + 52);
			*getMemU32Ptr(0x5D4594, 1087248 + v5) = *(unsigned char*)(v2 + 57);
			*getMemU8Ptr(0x5D4594, 1087256 + v5) = *(uint8_t*)(v2 + 56);
			nox_wcscpy((wchar2_t*)getMemAt(0x5D4594, 1087204 + v5), (const wchar2_t*)v2);
			sub_46E170((wchar2_t*)getMemAt(0x5D4594, 1087204 + 56 * getMemByte(0x5D4594, 1090116)));
			++*getMemU8Ptr(0x5D4594, 1090116);
			v0 = v3;
		} while (getMemByte(0x5D4594, 1090116) < (unsigned int)v24);
	}
	for (j = nox_common_playerInfoGetFirst_416EA0(); j; j = nox_common_playerInfoGetNext_416EE0((int)j)) {
		v7 = *((uint32_t*)j + 920);
		if (v7 & 1 && !(v7 & 0x20)) {
			*((uint32_t*)j + 534) -= 0xFFFF;
		}
	}
	v8 = 0x7FFFFFFF;
	if (getMemByte(0x5D4594, 1090117) < v23) {
		v9 = (int)v24;
		do {
			v10 = nox_common_playerInfoGetFirst_416EA0();
			for (k = 0x80000000; v10; v10 = nox_common_playerInfoGetNext_416EE0((int)v10)) {
				if ((v10[2064] != 31 || !nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) &&
					*((int*)v10 + 534) <= v8 && !sub_46E1E0(*((uint32_t*)v10 + 515)) && *((int*)v10 + 534) > k) {
					k = *((uint32_t*)v10 + 534);
					v9 = (int)v10;
				}
			}
			v12 = getMemByte(0x5D4594, 1090117);
			v13 = 80 * getMemByte(0x5D4594, 1090117);
			*getMemU32Ptr(0x5D4594, 1084192 + v13) = *(uint32_t*)(v9 + 2060);
			v14 = *(uint32_t*)(v9 + 3680);
			if (!(v14 & 1) || v14 & 0x20) {
				*getMemU32Ptr(0x5D4594, 1084196 + v13) = *(uint32_t*)(v9 + 2136);
				++*getMemU8Ptr(0x5D4594, 1090118);
			} else {
				*getMemU32Ptr(0x5D4594, 1084196 + v13) = *(uint32_t*)(v9 + 2136) + 0xFFFF;
			}
			*getMemU32Ptr(0x5D4594, 1084200 + v13) = *(unsigned short*)(v9 + 2148);
			v15 = 80 * v12;
			*getMemU32Ptr(0x5D4594, 1084204 + v15) = sub_46E080(v9);
			*getMemU32Ptr(0x5D4594, 1084208 + v15) = *(uint32_t*)(v9 + 3680);
			nox_wcscpy((wchar2_t*)getMemAt(0x5D4594, 1084132 + v15), (const wchar2_t*)(v9 + 4704));
			sub_46E170((wchar2_t*)getMemAt(0x5D4594, 1084132 + 80 * getMemByte(0x5D4594, 1090117)));
			*getMemU8Ptr(0x5D4594, 1084188 + 80 * getMemByte(0x5D4594, 1090117)) = *(uint8_t*)(v9 + 2251);
			v16 = nox_xxx_objGetTeamByNetCode_418C80(*(uint32_t*)(v9 + 2060));
			v17 = v16;
			if (v16 && nox_xxx_servObjectHasTeam_419130((int)v16)) {
				v18 = nox_xxx_clientGetTeamColor_418AB0(*((unsigned char*)v17 + 4));
				if (v18) {
					v19 = (unsigned char)v18[57];
					v20 = getMemByte(0x5D4594, 1090117);
					*getMemU32Ptr(0x5D4594, 1084184 + 80 * getMemByte(0x5D4594, 1090117)) = v19;
				} else {
					v20 = getMemByte(0x5D4594, 1090117);
					*getMemU32Ptr(0x5D4594, 1084184 + 80 * getMemByte(0x5D4594, 1090117)) = -1;
				}
			} else {
				v20 = getMemByte(0x5D4594, 1090117);
				*getMemU32Ptr(0x5D4594, 1084184 + 80 * getMemByte(0x5D4594, 1090117)) = -1;
			}
			*getMemU8Ptr(0x5D4594, 1090117) = v20 + 1;
			v8 = k;
		} while ((unsigned char)(v20 + 1) < v23);
	}
	for (result = nox_common_playerInfoGetFirst_416EA0(); result;
		 result = nox_common_playerInfoGetNext_416EE0((int)result)) {
		v22 = *((uint32_t*)result + 920);
		if (v22 & 1) {
			if (!(v22 & 0x20)) {
				*((uint32_t*)result + 534) += 0xFFFF;
			}
		}
	}
	return result;
}

//----- (0046F060) --------------------------------------------------------
int sub_46F060() { return 0; }

//----- (0046F070) --------------------------------------------------------
int nox_xxx_Proc_46F070() { return 0; }

//----- (0046FAE0) --------------------------------------------------------
void sub_46FAE0() {
	int yTop; // [esp+0h] [ebp-8h]
	int v1;   // [esp+4h] [ebp-4h]

	nox_client_wndGetPosition_46AA60(*(uint32_t**)getMemAt(0x5D4594, 1090060 + 4 * *getMemU32Ptr(0x5D4594, 1088996)),
									 &v1, &yTop);
	yTop +=
		dword_587000_145672 *
			*(short*)(*(uint32_t*)(*getMemU32Ptr(0x5D4594, 1090060 + 4 * *getMemU32Ptr(0x5D4594, 1088996)) + 32) + 2) +
		*(short*)(*(uint32_t*)(*getMemU32Ptr(0x5D4594, 1090060 + 4 * *getMemU32Ptr(0x5D4594, 1088996)) + 32) + 2) / 2;
	nox_client_drawSetColor_434460(nox_color_yellow_2589772);
	nox_xxx_drawPointMB_499B70(v1 + 1, yTop, 3);
}

//----- (0046FE60) --------------------------------------------------------
unsigned char sub_46FE60(int a1) {
	unsigned char result; // al
	unsigned char v2;     // [esp+8h] [ebp-4h]

	result = 0;
	v2 = 0;
	if (!getMemByte(0x5D4594, 1090116)) {
		return 0;
	}
	while (*getMemU32Ptr(0x5D4594, 1087248 + 56 * v2) != a1) {
		v2 = ++result;
		if (result >= getMemByte(0x5D4594, 1090116)) {
			return 0;
		}
	}
	return result;
}

//----- (0046FEB0) --------------------------------------------------------
unsigned char sub_46FEB0(unsigned char a1) {
	return getMemByte(0x587000, 145584 + 8 * (getMemByte(0x5D4594, 1087256 + 56 * a1) % 10));
}

//----- (0046FEE0) --------------------------------------------------------
char sub_46FEE0() {
	int v0;            // eax
	char v1;           // bl
	unsigned char* i;  // edx
	int v4;            // esi
	int v5;            // ecx
	unsigned char* v6; // eax
	int v7;            // ecx
	unsigned char* v8; // eax

	v0 = 0;
	v1 = 1;
	if (!getMemByte(0x5D4594, 1090117)) {
		return 0;
	}
	for (i = getMemAt(0x5D4594, 1084192); *(uint32_t*)i != nox_player_netCode_85319C; i += 80) {
		if (++v0 >= (unsigned int)getMemByte(0x5D4594, 1090117)) {
			return 0;
		}
	}
	v4 = *getMemU32Ptr(0x5D4594, 1084196 + 80 * v0);
	if (!nox_common_gameFlags_check_40A5C0(1024)) {
		v7 = getMemByte(0x5D4594, 1090117);
		if (getMemByte(0x5D4594, 1090117)) {
			v8 = getMemAt(0x5D4594, 1084196);
			do {
				if (*(uint32_t*)v8 > v4) {
					++v1;
				}
				v8 += 80;
				--v7;
			} while (v7);
		}
		return v1;
	}
	v5 = getMemByte(0x5D4594, 1090117);
	if (!getMemByte(0x5D4594, 1090117)) {
		return v1;
	}
	v6 = getMemAt(0x5D4594, 1084196);
	do {
		if (*(uint32_t*)v6 < v4) {
			++v1;
		}
		v6 += 80;
		--v5;
	} while (v5);
	return v1;
}

//----- (0046FF70) --------------------------------------------------------
char sub_46FF70(int a1) {
	char v1;           // bl
	int v2;            // ecx
	unsigned char* v3; // eax
	int v5;            // ecx
	unsigned char* v6; // eax

	v1 = 1;
	if (!nox_common_gameFlags_check_40A5C0(1024)) {
		v5 = getMemByte(0x5D4594, 1090116);
		if (getMemByte(0x5D4594, 1090116)) {
			v6 = getMemAt(0x5D4594, 1087252);
			do {
				if (*(uint32_t*)v6 > a1) {
					++v1;
				}
				v6 += 56;
				--v5;
			} while (v5);
		}
		return v1;
	}
	v2 = getMemByte(0x5D4594, 1090116);
	if (!getMemByte(0x5D4594, 1090116)) {
		return v1;
	}
	v3 = getMemAt(0x5D4594, 1087252);
	do {
		if (*(uint32_t*)v3 < a1) {
			++v1;
		}
		v3 += 56;
		--v2;
	} while (v2);
	return v1;
}

//----- (0046FFD0) --------------------------------------------------------
unsigned char sub_46FFD0() {
	unsigned char result; // al
	int v1;               // ebx
	unsigned char* v2;    // ebp
	char* v3;             // eax
	unsigned char* v4;    // esi
	unsigned char v5;     // al
	unsigned char v6;     // di
	int v7;               // edx
	int v8;               // eax
	int v9;               // eax
	int v10;              // eax
	wchar2_t* v11;         // eax
	int v12;              // eax
	int v13;              // edx
	int v14;              // eax
	unsigned char v15;    // cl
	float v16;            // [esp+0h] [ebp-4Ch]
	int v17;              // [esp+14h] [ebp-38h]
	int v18;              // [esp+18h] [ebp-34h]
	int v19;              // [esp+1Ch] [ebp-30h]
	int v20;              // [esp+20h] [ebp-2Ch]
	int v21;              // [esp+24h] [ebp-28h]
	int v22;              // [esp+28h] [ebp-24h]
	int v23;              // [esp+2Ch] [ebp-20h]
	int v24;              // [esp+30h] [ebp-1Ch]
	float v25;            // [esp+34h] [ebp-18h]
	int v26;              // [esp+38h] [ebp-14h]
	int v27;              // [esp+3Ch] [ebp-10h]
	int v28;              // [esp+40h] [ebp-Ch]
	int v29;              // [esp+44h] [ebp-8h]
	int v30;              // [esp+48h] [ebp-4h]

	sub_46DB80();
	sub_46F8F0(0, 0);
	result = getMemByte(0x5D4594, 1090117);
	v23 = 0;
	if (getMemByte(0x5D4594, 1090117)) {
		v1 = 1;
		v2 = getMemAt(0x5D4594, 1084184);
		do {
			v3 = nox_common_playerInfoGetByID_417040(*((uint32_t*)v2 + 2));
			v4 = (unsigned char*)v3;
			if (v3 && *((uint32_t*)v3 + 1198)) {
				if (v2[24] & 1) {
					LOBYTE(v21) = 9;
				} else if (*(int*)v2 == -1) {
					LOBYTE(v21) = 4;
				} else {
					v5 = sub_46FE60(*(uint32_t*)v2);
					LOBYTE(v21) = sub_46FEB0(v5);
				}
				if (*((uint32_t*)v2 + 2) == nox_player_netCode_85319C) {
					dword_587000_145672 = *(short*)(*(uint32_t*)(*getMemU32Ptr(0x5D4594, 1090060) + 32) + 46);
					*getMemU32Ptr(0x5D4594, 1088996) = 0;
				}
				v6 = v21;
				sub_46DC30(*getMemIntPtr(0x5D4594, 1090060), v21, (wchar2_t*)getMemAt(0x587000, 147828), v2 - 52);
				sub_46DC30(*getMemIntPtr(0x5D4594, 1090076), v6, (wchar2_t*)getMemAt(0x587000, 147836), v4[4816]);
				v7 = *((uint32_t*)v2 + 2);
				v8 = v4[2282];
				LOBYTE(v22) = 4;
				if (v7 == nox_player_netCode_85319C) {
					v9 = sub_470CD0();
					v24 = v9;
					v25 = (double)v9;
					v10 = sub_470CC0();
					v24 = v10;
					v16 = (double)v10 / v25 * 100.0;
					v8 = nox_float2int(v16);
				}
				if (v8 > 25) {
					if (v8 <= 50) {
						LOBYTE(v22) = 15;
					}
				} else {
					LOBYTE(v22) = 6;
				}
				sub_46DC30(*getMemIntPtr(0x5D4594, 1090084), v22, (wchar2_t*)getMemAt(0x587000, 147844), v8);
				sub_46DC30(*getMemIntPtr(0x5D4594, 1090092), v6, (wchar2_t*)getMemAt(0x587000, 147856),
						   *getMemU32Ptr(0x5D4594, 1084056 + 4 * v2[4]));
				v11 = sub_46FB50(*((uint32_t*)v2 + 5), &v26);
				sub_46DC60(*getMemIntPtr(0x5D4594, 1090068), v26, (int)v11);
				if (v4[4824]) {
					nox_client_wndGetPosition_46AA60(*(uint32_t**)getMemAt(0x5D4594, 1090068), &v19, &v18);
					nox_window_get_size(*getMemIntPtr(0x5D4594, 1090068), &v28, &v27);
					v12 = *(uint32_t*)(*getMemU32Ptr(0x5D4594, 1090068) + 32);
					v19 += 5;
					v18 = v18 + *(short*)(v12 + 2) / 2 + *(short*)(v12 + 2) * v1 - 1;
					nox_client_drawSetColor_434460(nox_color_white_2523948);
					nox_video_drawCircleColored_4C3270(v19, v18, 2, nox_color_white_2523948);
					nox_client_drawAddPoint_49F500(v19 + 2, v18);
					nox_client_drawAddPoint_49F500(v19 + 9, v18);
					nox_client_drawLineFromPoints_49E4B0();
					nox_client_drawAddPoint_49F500(v19 + 9, v18);
					nox_client_drawAddPoint_49F500(v19 + 9, v18 + 3);
					nox_client_drawLineFromPoints_49E4B0();
					nox_client_drawAddPoint_49F500(v19 + 7, v18);
					nox_client_drawAddPoint_49F500(v19 + 7, v18 + 2);
					nox_client_drawLineFromPoints_49E4B0();
				}
				if (v4[4825]) {
					nox_client_wndGetPosition_46AA60(*(uint32_t**)getMemAt(0x5D4594, 1090068), &v17, &v20);
					nox_window_get_size(*getMemIntPtr(0x5D4594, 1090068), &v30, &v29);
					v13 = v17 + 5;
					v14 = *(uint32_t*)(*getMemU32Ptr(0x5D4594, 1090068) + 32);
					v15 = v4[4824];
					v17 += 5;
					if (v15 == 1) {
						v17 = v13 + 15;
					}
					v20 = v20 + *(short*)(v14 + 2) / 2 + *(short*)(v14 + 2) * v1 - 1;
					nox_client_drawSetColor_434460(nox_color_yellow_2589772);
					nox_video_drawCircleColored_4C3270(v17, v20, 2, nox_color_yellow_2589772);
					nox_client_drawAddPoint_49F500(v17 + 2, v20);
					nox_client_drawAddPoint_49F500(v17 + 9, v20);
					nox_client_drawLineFromPoints_49E4B0();
					nox_client_drawAddPoint_49F500(v17 + 9, v20);
					nox_client_drawAddPoint_49F500(v17 + 9, v20 + 3);
					nox_client_drawLineFromPoints_49E4B0();
					nox_client_drawAddPoint_49F500(v17 + 7, v20);
					nox_client_drawAddPoint_49F500(v17 + 7, v20 + 2);
					nox_client_drawLineFromPoints_49E4B0();
				}
				++v1;
			}
			result = v23 + 1;
			v2 += 80;
			++v23;
		} while (v23 < getMemByte(0x5D4594, 1090117));
		dword_587000_145664 = 1;
	} else {
		dword_587000_145664 = 1;
	}
	return result;
}

//----- (00470580) --------------------------------------------------------
int sub_470580() {
	return dword_5d4594_1090120 && wndIsShown_nox_xxx_wndIsShown_46ACC0(*(int*)&dword_5d4594_1090048) != 1;
}

//----- (004705B0) --------------------------------------------------------
void sub_4705B0() {
	if (dword_5d4594_1090048) {
		if (wndIsShown_nox_xxx_wndIsShown_46ACC0(dword_5d4594_1090048)) {
			nox_window_set_hidden(dword_5d4594_1090048, 0);
		}
		dword_5d4594_1090120 = 0;
		sub_4703F0();
	}
}

//----- (004705F0) --------------------------------------------------------
char sub_4705F0(char a1, char a2, short a3) {
	char result; // al

	result = a2;
	if (a2 == 1) {
		result = a1;
		if (a1 != 2 && a1) {
			if (a1 == 1) {
				result = a3;
				*getMemU16Ptr(0x5D4594, 1090128) = a3;
			}
		} else {
			*getMemU16Ptr(0x5D4594, 1090128) = 0;
		}
	} else if (a2 == 2) {
		result = a1;
		if (a1 != 2 && a1) {
			if (a1 == 1) {
				*getMemU16Ptr(0x5D4594, 1090130) = a3;
			}
		} else {
			*getMemU16Ptr(0x5D4594, 1090130) = 0;
		}
	}
	return result;
}

//----- (00470650) --------------------------------------------------------
char sub_470650(char a1, short a2) {
	char result; // al

	result = a1;
	if (a1 && a1 != 1) {
		if (a1 == 4 || a1 == 2) {
			result = a2;
			*getMemU16Ptr(0x5D4594, 1090132) = a2;
		}
	} else {
		*getMemU16Ptr(0x5D4594, 1090132) = 0;
	}
	return result;
}

//----- (00470680) --------------------------------------------------------
int sub_470680() {
	int result; // eax

	result = 0;
	*getMemU16Ptr(0x5D4594, 1090128) = 0;
	*getMemU16Ptr(0x5D4594, 1090130) = 0;
	*getMemU16Ptr(0x5D4594, 1090132) = 0;
	return result;
}

//----- (004706A0) --------------------------------------------------------
int sub_4706A0() { return dword_5d4594_1090048 && dword_5d4594_1090120; }

//----- (00470A90) --------------------------------------------------------
int nox_xxx_playerGet_470A90() { return dword_5d4594_1096252; }

//----- (00470AA0) --------------------------------------------------------
void nox_xxx_cliShowHideTubes_470AA0(int a1) {
	dword_5d4594_1096252 = a1;
	if (*getMemU32Ptr(0x5D4594, 1093176)) {
		if (a1) {
			nox_window_set_hidden(nox_windows_arr_1093036[2].win, 0);
			nox_window_set_hidden(nox_windows_arr_1093036[3].win, 0);
		} else {
			nox_window_set_hidden(nox_windows_arr_1093036[2].win, 1);
			nox_window_set_hidden(nox_windows_arr_1093036[3].win, 1);
		}
	}
}

//----- (00470B00) --------------------------------------------------------
unsigned char* nox_xxx_guiHealthManaColorInit_470B00() {
	unsigned char* result; // eax

	dword_5d4594_1090284 = nox_color_rgb_4344A0(255, 0, 0);
	dword_5d4594_1090280 = nox_color_rgb_4344A0(100, 0, 0);
	*getMemU32Ptr(0x5D4594, 1091964) = nox_color_rgb_4344A0(0, 255, 0);
	*getMemU32Ptr(0x5D4594, 1092992) = nox_color_rgb_4344A0(0, 100, 0);

	nox_windows_arr_1093036[0].color_1 = dword_5d4594_1090284;
	nox_windows_arr_1093036[0].color_2 = dword_5d4594_1090280;

	nox_windows_arr_1093036[1].color_1 = nox_color_rgb_4344A0(0, 0, 255);
	nox_windows_arr_1093036[1].color_2 = nox_color_rgb_4344A0(0, 0, 100);

	nox_windows_arr_1093036[4].color_1 = nox_color_rgb_4344A0(240, 0, 240);
	nox_windows_arr_1093036[4].color_2 = nox_color_rgb_4344A0(50, 0, 50);

	nox_windows_arr_1093036[5].color_1 = nox_color_rgb_4344A0(255, 0, 255);
	nox_windows_arr_1093036[5].color_2 = nox_color_rgb_4344A0(50, 0, 50);

	nox_windows_arr_1093036[6].color_1 = nox_color_rgb_4344A0(255, 0, 255);
	nox_windows_arr_1093036[6].color_2 = nox_color_rgb_4344A0(50, 0, 50);

	result = getMemAt(0x5D4594, 1094732);
	do {
		*((uint32_t*)result - 384) = 0;
		*(uint32_t*)result = 0;
		result += 24;
	} while ((int)result < (int)getMemAt(0x5D4594, 1096268));
	return result;
}

//----- (00470C40) --------------------------------------------------------
int sub_470C40(int a1) {
	int result; // eax

	dword_5d4594_1096264 = a1;
	if (a1) {
		result = *getMemU32Ptr(0x5D4594, 1091964);
		nox_windows_arr_1093036[0].color_1 = *getMemU32Ptr(0x5D4594, 1091964);
		nox_windows_arr_1093036[0].color_2 = *getMemU32Ptr(0x5D4594, 1092992);
	} else {
		result = dword_5d4594_1090280;
		nox_windows_arr_1093036[0].color_1 = dword_5d4594_1090284;
		nox_windows_arr_1093036[0].color_2 = dword_5d4594_1090280;
	}
	return result;
}

//----- (00470C80) --------------------------------------------------------
int nox_xxx_cliSetTotalHealth_470C80(int a1, int a2) {
	int result; // eax

	if (*getMemU32Ptr(0x8531A0, 2576)) {
		*(uint32_t*)(*getMemU32Ptr(0x8531A0, 2576) + 2247) = a2;
	}
	result = a1;
	nox_windows_arr_1093036[0].field_2 = a2;
	nox_windows_arr_1093036[0].field_1 = a1;
	dword_5d4594_1096260 = 32;
	return result;
}

//----- (00470CB0) --------------------------------------------------------
int sub_470CB0(int a1) {
	int result; // eax

	result = a1;
	nox_windows_arr_1093036[0].field_1 = a1;
	return result;
}

//----- (00470CC0) --------------------------------------------------------
int sub_470CC0() { return nox_windows_arr_1093036[0].field_1; }

//----- (00470CD0) --------------------------------------------------------
int sub_470CD0() { return nox_windows_arr_1093036[0].field_2; }

//----- (00470CE0) --------------------------------------------------------
int nox_xxx_cliSetManaAndMax_470CE0(int a1, int a2) {
	int result; // eax

	if (*getMemU32Ptr(0x8531A0, 2576)) {
		*(uint32_t*)(*getMemU32Ptr(0x8531A0, 2576) + 2243) = a2;
	}
	result = a1;
	nox_windows_arr_1093036[1].field_2 = a2;
	nox_windows_arr_1093036[1].field_1 = a1;
	dword_5d4594_1096260 = 32;
	return result;
}

//----- (00470D10) --------------------------------------------------------
int nox_xxx_cliSetMana_470D10(int a1) {
	int result; // eax

	result = a1;
	nox_windows_arr_1093036[1].field_1 = a1;
	return result;
}

//----- (00470D20) --------------------------------------------------------
int sub_470D20(int a1, int a2) {
	int result; // eax

	result = a1;
	nox_windows_arr_1093036[4].field_1 = a1;
	nox_windows_arr_1093036[4].field_2 = a2;
	if (a1 != a2) {
		result = nox_xxx_setKeybTimeout_4160D0(17);
	}
	return result;
}

//----- (00470D70) --------------------------------------------------------
void sub_470D70() {
	nox_window_set_hidden(nox_windows_arr_1093036[5].win, 1);
	nox_window_set_hidden(nox_windows_arr_1093036[6].win, 1);
}

//----- (00470D90) --------------------------------------------------------
int sub_470D90(int a1, int a2) {
	int result; // eax

	nox_window_set_hidden(nox_windows_arr_1093036[5].win, 0);
	nox_window_set_hidden(nox_windows_arr_1093036[6].win, 0);
	result = a1;
	nox_windows_arr_1093036[5].field_1 = a1;
	nox_windows_arr_1093036[5].field_2 = a2;
	nox_windows_arr_1093036[6].field_1 = a1;
	nox_windows_arr_1093036[6].field_2 = a2;
	return result;
}

//----- (00470DD0) --------------------------------------------------------
int nox_xxx_cliGetMana_470DD0() { return nox_windows_arr_1093036[1].field_1; }

//----- (00470DE0) --------------------------------------------------------
int sub_470DE0() {
	int result; // eax
	int v1;     // ebp
	int v2;     // edx
	int v3;     // esi

	result = nox_player_netCode_85319C;
	if (nox_player_netCode_85319C) {
		v1 = nox_windows_arr_1093036[0].field_1;
		if (nox_windows_arr_1093036[0].field_1 >= 1) {
			result = -858993458 * nox_windows_arr_1093036[0].field_2;
			v2 = 2 * nox_windows_arr_1093036[0].field_2 / 5;
			v3 = v2;
			if (nox_windows_arr_1093036[0].field_1 < v2) {
				*getMemU32Ptr(0x5D4594, 1091960) =
					gameFPS() / 3u + nox_windows_arr_1093036[0].field_1 * ((unsigned int)(3 * gameFPS()) >> 2) / v2;
				result = nox_xxx_checkKeybTimeout_4160F0(4u, *getMemU32Ptr(0x5D4594, 1091960) - 1);
				if (result) {
					nox_xxx_clientPlaySoundSpecial_452D80(896, 66 * (v3 - v1) / v3 + 33);
					result = nox_xxx_setKeybTimeout_4160D0(4);
				}
			}
		}
	}
	return result;
}

//----- (00470E90) --------------------------------------------------------
int sub_470E90(int a1, int a2) {
	int result; // eax

	switch (a2) {
	case 5:
		nox_client_invAlterWeapon_4672C0();
		goto LABEL_4;
	case 8:
	case 12:
	case 16:
		result = 0;
		break;
	default:
	LABEL_4:
		result = 1;
		break;
	}
	return result;
}

//----- (00470EE0) --------------------------------------------------------
void nox_win_init_cur_weapon(nox_window* a1, int a2, int a3, int w, int h) {
	nox_windows_arr_1093036[4].win = nox_window_new(a1, 0x408, a2, a3, w, h, 0);
	nox_window_set_all_funcs(nox_windows_arr_1093036[4].win, sub_470E90, sub_470F40_draw, sub_4710B0);
	nox_windows_arr_1093036[4].win->widget_data = 4;
}

//----- (00470F40) --------------------------------------------------------
int sub_470F40_draw(nox_window* win) {
	unsigned char* v3; // edi
	int v4;            // ebx
	int v5;            // esi
	int v6;            // ecx
	int v7;            // eax
	double v8;         // st7
	double v9;         // st6
	int v12;           // [esp+10h] [ebp-1Ch]
	int v14;           // [esp+18h] [ebp-14h]
	int v16;           // [esp+20h] [ebp-Ch]
	int v17;           // [esp+24h] [ebp-8h]
	int v18;           // [esp+30h] [ebp+4h]

	v18 = 1;
	v3 = &nox_windows_arr_1093036[(int)win->widget_data]; // TODO: this doesn't look right!
	nox_client_wndGetPosition_46AA60(win, &v14, &v16);

	int w;
	int h;
	nox_window_get_size(win, &w, &h);
	v4 = w / 2;
	v17 = w / 2 + v14;
	v5 = h / 2 + v16;

	v6 = *((int*)v3 + 2);
	if (v6) {
		v12 = (*((int*)v3 + 1) << 8) / v6;
	} else {
		v18 = 0;
	}
	*((uint32_t*)v3 + 4) = *((uint32_t*)v3 + 3);
	if (!v18) {
		sub_465D50_draw(win);
		return 1;
	}
	if (v12 >= 256) {
		v7 = sub_4678D0();
		if (v7) {
			v8 = (double)*(unsigned short*)(v7 + 292);
			v9 = (double)*(unsigned short*)(v7 + 294);
			if (v8 < v9 * *getMemDoublePtr(0x581450, 9608)) {
				*((uint32_t*)v3 + 4) = *getMemU32Ptr(0x85B3FC, 940);
				v12 = 1;
			} else if (v8 < v9 * *(double*)&qword_581450_9544) {
				*((uint32_t*)v3 + 4) = nox_color_yellow_2589772;
				v12 = 1;
			} else {
				v18 = 0;
				v12 = 1;
			}
		} else {
			v18 = 0;
			v12 = 1;
		}
	}
	if (v18) {
		nox_client_drawEnableAlpha_434560(1);
		nox_client_drawSetAlpha_434580(0x40u);
		sub_4AE6F0(v17, v5, v4, v12, *((uint32_t*)v3 + 4));
		nox_client_drawEnableAlpha_434560(0);
	}
	sub_465D50_draw(win);
	return 1;
}
// 470FE2: variable 'v12' is possibly undefined

//----- (00471250) --------------------------------------------------------
int sub_471250(uint32_t* a1) {
	unsigned char* v1;  // esi
	int v2;             // edi
	unsigned char* v3;  // esi
	int result;         // eax
	int v5;             // eax
	int v6;             // ecx
	int v7;             // ebx
	int v8;             // ebp
	int v9;             // ecx
	int v10;            // esi
	int v11;            // edi
	double v12;         // st7
	int v13;            // eax
	unsigned char* v14; // esi
	int v15;            // [esp+10h] [ebp-1Ch]
	int v16;            // [esp+14h] [ebp-18h]
	int v17;            // [esp+18h] [ebp-14h]
	int v18;            // [esp+1Ch] [ebp-10h]
	int v19;            // [esp+20h] [ebp-Ch]
	unsigned char* v20; // [esp+24h] [ebp-8h]
	float v21;          // [esp+28h] [ebp-4h]
	float v22;          // [esp+30h] [ebp+4h]

	v20 = &nox_windows_arr_1093036[a1[8]];
	v1 = v20;
	nox_client_wndGetPosition_46AA60(a1, &v18, &v17);
	v2 = 1;
	if (*((int*)v1 + 2) >= 1) {
		v15 = 1;
		v5 = nox_xxx_bookGet_430B40_get_mouse_prev_seq();
		v6 = *((uint32_t*)v1 + 2);
		v19 = v5;
		if (v6 > 30) {
			v15 = 0;
			v2 = 0;
		}
		v7 = (v2 + 61) / v6 - v2;
		v8 = 61 - v7;
		v22 = 0.001;
		v16 = 0;
		v21 = (double)(v2 - v6 * ((v2 + 61) / v6) + 61) / (double)v6;
		if (v6 > 0) {
			while (1) {
				if (v16 >= *((uint32_t*)v1 + 1)) {
					v9 = *((uint32_t*)v1 + 4);
				} else {
					v9 = *((uint32_t*)v1 + 3);
				}
				v10 = v8;
				v8 -= v7 + v2;
				v11 = v7;
				if (v7 <= 0) {
					v11 = 1;
				}
				v12 = v22 + v21;
				v22 = v12;
				if (v12 >= *(double*)&qword_581450_9512) {
					--v8;
					--v10;
					++v11;
					v22 = v22 - *(double*)&qword_581450_9512;
				}
				nox_client_drawSetColor_434460(v9);
				nox_client_drawEnableAlpha_434560(1);
				if (v10 < 0) {
					v13 = -v10;
					v10 = 0;
					v11 -= v13;
				}
				if (v11 > 0) {
					v14 = getMemAt(0x587000, 147905 + 8 * v10);
					do {
						if ((int)v14 >= (int)getMemAt(0x587000, 148393)) {
							break;
						}
						if (*(uint32_t*)(v14 + 3) != v19) {
							nox_client_drawRectFilledOpaque_49CE30(v18 + *(v14 - 1), v17 + *v14, v14[1], 1);
							*(uint32_t*)(v14 + 3) = v19;
						}
						v14 += 8;
						--v11;
					} while (v11 > 0);
				}
				nox_client_drawEnableAlpha_434560(0);
				if (++v16 >= *((uint32_t*)v20 + 2)) {
					break;
				}
				v2 = v15;
				v1 = v20;
			}
		}
		result = 1;
	} else {
		nox_client_drawSetColor_434460(*((uint32_t*)v1 + 3));
		nox_client_drawEnableAlpha_434560(1);
		v3 = getMemAt(0x587000, 147905);
		do {
			nox_client_drawRectFilledOpaque_49CE30(v18 + *(v3 - 1), v17 + *v3, v3[1], 1);
			v3 += 8;
		} while ((int)v3 < (int)getMemAt(0x587000, 148393));
		nox_client_drawEnableAlpha_434560(0);
		result = 1;
	}
	return result;
}

//----- (00471450) --------------------------------------------------------
int sub_471450(uint32_t* a1) {
	uint32_t* v1;           // esi
	int v3;                 // [esp+4h] [ebp-10h]
	int v4;                 // [esp+8h] [ebp-Ch]
	wchar2_t WideCharStr[4]; // [esp+Ch] [ebp-8h]

	v1 = a1;
	nox_itow(nox_windows_arr_1093036[a1[8]].field_1, WideCharStr, 10);
	nox_xxx_drawSetTextColor_434390(nox_color_white_2523948);
	nox_xxx_drawGetStringSize_43F840(*(int*)&dword_5d4594_1096288, WideCharStr, &v3, 0, 0);
	nox_client_wndGetPosition_46AA60(v1, &v4, &a1);
	nox_xxx_drawString_43F6E0(*(int*)&dword_5d4594_1096288, (short*)WideCharStr, v4 - v3 / 2 + 8, (int)a1 + 1);
	return 1;
}

//----- (00471A80) --------------------------------------------------------
int nox_xxx_guiBottleSlotDrawFn_471A80(uint32_t* a1) {
	int v1;        // esi
	int v2;        // esi
	int v3;        // eax
	int v4;        // eax
	short* v5;     // esi
	int v6;        // eax
	int v8;        // [esp+4h] [ebp-14h]
	wchar2_t v9[8]; // [esp+8h] [ebp-10h]

	v1 = a1[8];
	nox_client_wndGetPosition_46AA60(a1, &v8, &a1);
	v2 = 536 * v1;
	if (*getMemU16Ptr(0x5D4594, 1090312 + v2)) {
		v3 = *getMemU32Ptr(0x5D4594, 1090296 + v2);
		if (v3) {
			*(uint32_t*)(v3 + 12) = v8 + 14;
			*(uint32_t*)(*getMemU32Ptr(0x5D4594, 1090296 + v2) + 16) = (char*)a1 + 15;
			(*(void (**)(unsigned char*, uint32_t))(*getMemU32Ptr(0x5D4594, 1090296 + v2) + 300))(
				getMemAt(0x5D4594, 1091908), *getMemU32Ptr(0x5D4594, 1090296 + v2));
		}
		nox_xxx_drawSetTextColor_434390(nox_color_white_2523948);
		nox_swprintf(v9, L"%d", *getMemU16Ptr(0x5D4594, 1090312 + v2));
		v4 = nox_xxx_guiFontHeightMB_43F320(*(int*)&dword_5d4594_1096288);
		nox_xxx_drawString_43F6E0(*(int*)&dword_5d4594_1096288, (short*)v9, v8 - 2, (int)((char*)a1 - v4 + 10));
	}
	v5 = getMemI16Ptr(0x5D4594, 1090300 + v2);
	if (v5) {
		v6 = nox_xxx_guiFontHeightMB_43F320(*(int*)&dword_5d4594_1096288);
		nox_xxx_drawString_43F6E0(*(int*)&dword_5d4594_1096288, v5, v8 - 2, (int)((char*)a1 - v6 + 33));
	}
	return 1;
}

//----- (00471B90) --------------------------------------------------------
int nox_xxx_guiBottleSlotProc_471B90(int a1, int a2) {
	int result; // eax

	switch (a2) {
	case 5:
		if (*getMemU32Ptr(0x5D4594, 1090308 + 536 * *(uint32_t*)(a1 + 32))) {
			nox_xxx_cliUseCurePoison_4674E0(*getMemU32Ptr(0x5D4594, 1090308 + 536 * *(uint32_t*)(a1 + 32)));
		}
		goto LABEL_5;
	case 8:
	case 12:
	case 16:
		result = 0;
		break;
	default:
	LABEL_5:
		result = 1;
		break;
	}
	return result;
}

//----- (00471C00) --------------------------------------------------------
int nox_xxx_drawHealthManaBar_471C00(int a1) {
	int v1;            // esi
	unsigned char* v2; // ebp
	int v3;            // edi
	int v4;            // esi
	int v5;            // ebx
	int v7;            // [esp+Ch] [ebp+4h]

	v1 = *(uint32_t*)(a1 + 32);
	v7 = v1;
	v2 = &nox_windows_arr_1093036[v1];
	if (nox_xxx_clientIsObserver_4372E0() || nox_gameDisableMapDraw_5d4594_2650672 ||
		nox_common_gameFlags_check_40A5C0(9437184)) {
		return 1;
	}
	if (v1) {
		v3 = nox_win_width / 2 + 21;
	} else {
		v3 = nox_win_width / 2 + 15;
	}
	v4 = nox_win_height / 2 - 48;
	v5 = 48 * *((int*)v2 + 1) / *((int*)v2 + 2);
	nox_client_drawSetColor_434460(nox_color_black_2650656);
	nox_client_drawRectFilledOpaque_49CE30(v3, v4, 2, 48);
	nox_client_drawSetColor_434460(*((uint32_t*)v2 + 3));
	nox_client_drawRectFilledOpaque_49CE30(v3, v4 - v5 + 48, 2, v5);
	if (v7) {
		nox_client_drawSetColor_434460(*getMemIntPtr(0x85B3FC, 944));
	} else if (dword_5d4594_1096264) {
		nox_client_drawSetColor_434460(*getMemIntPtr(0x85B3FC, 984));
	} else {
		nox_client_drawSetColor_434460(nox_color_violet_2598268);
	}
	nox_client_drawBorderLines_49CC70(v3 - 1, v4 - 1, 4, 50);
	return 1;
}

//----- (00472080) --------------------------------------------------------
int sub_472080() {
	int result; // eax

	result = nox_windows_arr_1093036[4].field_1;
	if (nox_windows_arr_1093036[4].field_1 != nox_windows_arr_1093036[4].field_2) {
		result = sub_416120(0x11u);
		if (result) {
			result = 0x64u / (int)gameFPS();
			nox_windows_arr_1093036[4].field_1 += 0x64u / (int)gameFPS();
		}
	}
	return result;
}

//----- (004720C0) --------------------------------------------------------
int sub_4720C0(int xLeft, int a2) {
	nox_client_drawPixel_49EFA0(xLeft + 1, a2);
	nox_client_drawRectFilledOpaque_49CE30(xLeft, a2 + 1, 3, 1);
	nox_client_drawPixel_49EFA0(xLeft + 1, a2 + 2);
	return 0;
}

//----- (00472100) --------------------------------------------------------
int nox_xxx_guiHealthManaTubeProc_472100(int a1, int a2) {
	int result; // eax
	int v3;     // [esp-4h] [ebp-4h]

	switch (a2) {
	case 7:
		v3 = dword_5d4594_1096252 == 1;
		dword_5d4594_1096252 = 1 - dword_5d4594_1096252;
		nox_window_set_hidden(nox_windows_arr_1093036[2].win, v3);
		if (getMemByte(0x85B3FC, 12254) != 0) {
			nox_window_set_hidden(nox_windows_arr_1093036[3].win, dword_5d4594_1096252 == 0);
		}
		nox_xxx_clientPlaySoundSpecial_452D80(901, 100);
		goto LABEL_6;
	case 8:
	case 12:
	case 16:
		result = 0;
		break;
	default:
	LABEL_6:
		result = 1;
		break;
	}
	return result;
}

//----- (004721A0) --------------------------------------------------------
int sub_4721A0(int a1) {
	int result; // eax

	if (a1) {
		result = nox_window_set_hidden(*(int*)&dword_5d4594_1090276, 0);
	} else {
		result = nox_window_set_hidden(*(int*)&dword_5d4594_1090276, 1);
	}
	return result;
}

//----- (004721D0) --------------------------------------------------------
int nox_xxx_cliPrepareGameplay2_4721D0() {
	nox_xxx_windowDestroyMB_46C4E0(*(uint32_t**)&dword_5d4594_1090276);
	nox_xxx_windowDestroyMB_46C4E0(nox_windows_arr_1093036[2].win);
	if (nox_windows_arr_1093036[3].win) {
		nox_xxx_windowDestroyMB_46C4E0(nox_windows_arr_1093036[3].win);
	}
	nox_xxx_guiHealthManaInit_4714E0();
	sub_472310();
	return sub_4721A0(nox_client_getRenderGUI());
}

//----- (00472220) --------------------------------------------------------
void nox_client_quickHealthPotion_472220() {
	if (!nox_xxx_guiCursor_477600()) {
		if (*getMemU32Ptr(0x5D4594, 1090308)) {
			nox_xxx_cliUseCurePoison_4674E0(*getMemIntPtr(0x5D4594, 1090308));
		}
	}
}

//----- (00472240) --------------------------------------------------------
void nox_client_quickManaPotion_472240() {
	if (!nox_xxx_guiCursor_477600()) {
		if (*getMemU32Ptr(0x5D4594, 1090844)) {
			nox_xxx_cliUseCurePoison_4674E0(*getMemIntPtr(0x5D4594, 1090844));
		}
	}
}

//----- (00472260) --------------------------------------------------------
void nox_client_quickCurePoisonPotion_472260() {
	if (!nox_xxx_guiCursor_477600()) {
		if (*getMemU32Ptr(0x5D4594, 1091380)) {
			nox_xxx_cliUseCurePoison_4674E0(*getMemIntPtr(0x5D4594, 1091380));
		}
	}
}

//----- (00472280) --------------------------------------------------------
wchar2_t* sub_472280() {
	wchar2_t* result; // eax
	char* v1;        // eax
	char* v2;        // eax
	char* v3;        // eax

	result = *(wchar2_t**)getMemAt(0x8531A0, 2576);
	if (*getMemU32Ptr(0x8531A0, 2576)) {
		v1 = sub_42E8E0(38, 1);
		nox_wcsncpy((wchar2_t*)getMemAt(0x5D4594, 1091372), (const wchar2_t*)v1, 3u);
		*getMemU16Ptr(0x5D4594, 1091378) = 0;
		v2 = sub_42E8E0(36, 1);
		nox_wcsncpy((wchar2_t*)getMemAt(0x5D4594, 1090300), (const wchar2_t*)v2, 3u);
		result = *(wchar2_t**)getMemAt(0x8531A0, 2576);
		*getMemU16Ptr(0x5D4594, 1090306) = 0;
		if (*(uint8_t*)(*getMemU32Ptr(0x8531A0, 2576) + 2251)) {
			v3 = sub_42E8E0(37, 1);
			result = nox_wcsncpy((wchar2_t*)getMemAt(0x5D4594, 1090836), (const wchar2_t*)v3, 3u);
			*getMemU16Ptr(0x5D4594, 1090842) = 0;
		}
	}
	return result;
}

//----- (00472310) --------------------------------------------------------
unsigned char* sub_472310() {
	unsigned char* result; // eax

	*getMemU16Ptr(0x5D4594, 1091384) = sub_467850(*(int*)&dword_5d4594_1096276);
	*getMemU16Ptr(0x5D4594, 1090848) = sub_467850(*(int*)&dword_5d4594_1096272);
	*getMemU16Ptr(0x5D4594, 1091384) = sub_467850(*(int*)&dword_5d4594_1096276);
	*getMemU16Ptr(0x5D4594, 1090312) = sub_467850(*getMemIntPtr(0x5D4594, 1096268));
	if (*getMemU16Ptr(0x5D4594, 1090312)) {
		result = (unsigned char*)nox_get_thing(*getMemIntPtr(0x5D4594, 1096268));
		if (result) {
			nox_drawable_link_thing(getMemAt(0x5D4594, 1090316), *((uint32_t*)result + 7));
			result = getMemAt(0x5D4594, 1090316);
			*getMemU32Ptr(0x5D4594, 1090296) = getMemAt(0x5D4594, 1090316);
			if (true) // TODO: byte_5D4594 != (unsigned char*)-1090316
			{
				result = (unsigned char*)(*getMemU32Ptr(0x5D4594, 1090436) | 0x40000000);
				*getMemU32Ptr(0x5D4594, 1090308) = *getMemU32Ptr(0x5D4594, 1096268);
				*getMemU32Ptr(0x5D4594, 1090436) |= 0x40000000u;
				return result;
			}
		} else {
			*getMemU32Ptr(0x5D4594, 1090296) = 0;
		}
		*getMemU32Ptr(0x5D4594, 1090308) = *getMemU32Ptr(0x5D4594, 1096268);
	} else {
		*getMemU16Ptr(0x5D4594, 1090312) = sub_467850(*(int*)&dword_5d4594_1096284);
		if (*getMemU16Ptr(0x5D4594, 1090312)) {
			nox_thing* t1 = nox_get_thing(*(int*)&dword_5d4594_1096284);
			if (t1) {
				nox_drawable_link_thing(getMemAt(0x5D4594, 1090316), t1->field_1c);
				*getMemU32Ptr(0x5D4594, 1090296) = getMemAt(0x5D4594, 1090316);
				if (true) // TODO: byte_5D4594 != (unsigned char*)-1090316
				{
					*getMemU32Ptr(0x5D4594, 1090436) |= 0x40000000u;
					result = *(unsigned char**)&dword_5d4594_1096284;
					*getMemU32Ptr(0x5D4594, 1090308) = dword_5d4594_1096284;
					return result;
				}
			} else {
				*getMemU32Ptr(0x5D4594, 1090296) = 0;
			}
			result = *(unsigned char**)&dword_5d4594_1096284;
			*getMemU32Ptr(0x5D4594, 1090308) = dword_5d4594_1096284;
		} else {
			result = (unsigned char*)sub_467850(*(int*)&dword_5d4594_1096280);
			*getMemU16Ptr(0x5D4594, 1090312) = (uint16_t)result;
			if ((uint16_t)result) {
				result = (unsigned char*)nox_get_thing(*(int*)&dword_5d4594_1096280);
				if (result) {
					result =
						(unsigned char*)nox_drawable_link_thing(getMemAt(0x5D4594, 1090316), *((uint32_t*)result + 7));
					*getMemU32Ptr(0x5D4594, 1090296) = getMemAt(0x5D4594, 1090316);
					if (true) // TODO: byte_5D4594 != (unsigned char*)-1090316
					{
						result = (unsigned char*)(*getMemU32Ptr(0x5D4594, 1090436) | 0x40000000);
						*getMemU32Ptr(0x5D4594, 1090308) = dword_5d4594_1096280;
						*getMemU32Ptr(0x5D4594, 1090436) |= 0x40000000u;
						return result;
					}
				} else {
					*getMemU32Ptr(0x5D4594, 1090296) = 0;
				}
				*getMemU32Ptr(0x5D4594, 1090308) = dword_5d4594_1096280;
			} else {
				*getMemU32Ptr(0x5D4594, 1090296) = 0;
				*getMemU32Ptr(0x5D4594, 1090308) = 0;
			}
		}
	}
	return result;
}

//----- (004724E0) --------------------------------------------------------
void nox_client_mapZoomIn_4724E0() {
	nox_xxx_minimap_587000_149232 -= 10;
	if (*(int*)&nox_xxx_minimap_587000_149232 < 500) {
		nox_xxx_minimap_587000_149232 = 500;
	}
}

//----- (00472500) --------------------------------------------------------
void nox_client_mapZoomOut_472500() {
	nox_xxx_minimap_587000_149232 += 10;
	if (nox_xxx_minimap_587000_149232 > 4000) {
		nox_xxx_minimap_587000_149232 = 4000;
	}
}

//----- (00472520) --------------------------------------------------------
int nox_xxx_cliSetMinimapZoom_472520(int a1) {
	int result; // eax

	result = a1;
	nox_xxx_minimap_587000_149232 = a1;
	return result;
}

//----- (00472540) --------------------------------------------------------
int sub_472540(int a1) {
	int v1;     // edx
	int v2;     // eax
	int result; // eax
	int2 a1a;   // [esp+0h] [ebp-8h]

	if (a1 == *getMemU32Ptr(0x852978, 8)) {
		nox_xxx_getSomeCoods_435670(&a1a);
	} else {
		v1 = *(uint32_t*)(a1 + 16);
		a1a.field_0 = *(uint32_t*)(a1 + 12);
		a1a.field_4 = v1;
	}
	v2 = nox_xxx_polygonGetIdxA_421790(&a1a, *getMemIntPtr(0x5D4594, 1096312));
	if (v2) {
		*getMemU32Ptr(0x5D4594, 1096312) = v2;
	} else {
		v2 = *getMemU32Ptr(0x5D4594, 1096312);
	}
	if (v2) {
		result = (unsigned char)nox_xxx_polygonGetByIdx_4214A0(v2)[130];
	} else {
		result = 1;
	}
	return result;
}

//----- (004725C0) --------------------------------------------------------
void nox_xxx_drawMinimap4Sprite_4725C0(int a1) {
	int4* result; // eax

	result = (int4*)nox_client_drawable_testBuff_4356C0(*getMemIntPtr(0x852978, 8), 2);
	if (!result) {
		sub_437260();
		*getMemU32Ptr(0x5D4594, 1096316) = sub_472540(a1);
		nox_xxx_cliDrawMinimap_472600(a1, *getMemIntPtr(0x5D4594, 1096316));
		sub_437290();
	}
}

//----- (00472600) --------------------------------------------------------
int nox_xxx_cliDrawMinimap_472600(int a1, int a2) {
	char* v2;                           // ebp
	int v3;                             // esi
	int v4;                             // kr08_4
	int v5;                             // ebx
	int v6;                             // et1
	int v7;                             // esi
	int v8;                             // ebx
	int v9;                             // ebp
	int v10;                            // eax
	int v11;                            // edi
	char v12;                           // al
	int v13;                            // eax
	int v14;                            // esi
	int v15;                            // ebp
	unsigned char* v16;                 // esi
	int v17;                            // eax
	int v18;                            // eax
	int v19;                            // eax
	int v20;                            // et1
	int v21;                            // ecx
	int v22;                            // ebx
	int v23;                            // ebp
	int v24;                            // esi
	int v25;                            // ecx
	int v26;                            // et1
	char v27;                           // al
	char v28;                           // dl
	int v29;                            // edi
	char* v30;                          // esi
	float* v31;                         // esi
	int v32;                            // et1
	double v33;                         // st7
	int v34;                            // et1
	double v35;                         // st7
	float* j;                           // esi
	int v37;                            // et1
	double v38;                         // st7
	uint32_t* v39;                      // eax
	int k;                              // esi
	nox_player_polygon_check_data* v41; // eax
	int v42;                            // et1
	int v43;                            // eax
	int v44;                            // eax
	int v45;                            // edi
	uint32_t* v46;                      // eax
	char* v47;                          // eax
	int v48;                           // eax
	uint32_t* v49;                      // eax
	uint32_t* v50;                      // edi
	char* v51;                          // eax
	int v52;                           // eax
	int v53;                            // eax
	int v54;                            // eax
	char* v55;                          // eax
	char* v56;                          // eax
	uint32_t* v57;                      // eax
	int v58;                           // eax
	int l;                              // esi
	int v60;                            // eax
	int v61;                            // edx
	uint32_t* v62;                      // edi
	nox_player_polygon_check_data* v63; // eax
	int v64;                            // et1
	char* v65;                          // eax
	int v66;                           // eax
	int v68;                            // [esp-10h] [ebp-70h]
	int v69;                            // [esp+10h] [ebp-50h]
	int v70;                            // [esp+10h] [ebp-50h]
	int i;                              // [esp+14h] [ebp-4Ch]
	int v72;                            // [esp+14h] [ebp-4Ch]
	int v73;                            // [esp+14h] [ebp-4Ch]
	int v74;                            // [esp+18h] [ebp-48h]
	char* v75;                          // [esp+18h] [ebp-48h]
	int2 v76;                           // [esp+20h] [ebp-40h]
	int v77;                            // [esp+28h] [ebp-38h]
	int v78;                            // [esp+2Ch] [ebp-34h]
	int v79;                            // [esp+30h] [ebp-30h]
	int v80;                            // [esp+34h] [ebp-2Ch]
	int v81;                            // [esp+38h] [ebp-28h]
	int2 xLeft;                         // [esp+40h] [ebp-20h]
	int yTop;                           // [esp+4Ch] [ebp-14h]
	int2 v84;                           // [esp+50h] [ebp-10h]
	int v85;                            // [esp+5Ch] [ebp-4h]

	v2 = nox_draw_getViewport_437250();
	if (!getMemByte(0x5D4594, 1096300)) {
		*getMemU8Ptr(0x5D4594, 1096300) = nox_xxx_wallTileByName_410D60("InvisibleWallSet");
		*getMemU8Ptr(0x5D4594, 1096301) = nox_xxx_wallTileByName_410D60("InvisibleBlockingWallSet");
	}
	nox_client_drawEnableAlpha_434560(0);
	nox_xxx_wndDraw_49F7F0();
	v3 = nox_win_width / 6;
	v4 = nox_win_height - nox_win_width / 6;
	yTop = v4 / 2;
	nox_client_copyRect_49F6F0(0, 0, nox_win_width, nox_win_height);
	v5 = *(uint32_t*)v2;
	if (*(uint32_t*)v2 <= 0) {
		nox_client_drawRectFilledAlpha_49CF10(0, v4 / 2, v3, v3);
	} else {
		nox_client_drawSetColor_434460(nox_color_black_2650656);
		if (v5 >= v3) {
			nox_client_drawRectFilledOpaque_49CE30(0, v4 / 2, v3, v3);
		} else {
			nox_client_drawRectFilledOpaque_49CE30(0, v4 / 2, v5, v3);
			nox_client_drawRectFilledAlpha_49CF10(v5, v4 / 2, v3 - v5, v3);
		}
	}
	nox_client_drawEnableAlpha_434560(1);
	nox_client_drawSetColor_434460(nox_color_black_2650656);
	nox_client_drawSetAlpha_434580(0x5Au);
	nox_client_drawRectLines_473510(-1, yTop - 1, v3 + 2, v3 + 2);
	nox_client_drawSetAlpha_434580(0x3Cu);
	nox_client_drawRectLines_473510(-2, yTop - 2, v3 + 4, v3 + 4);
	nox_client_drawSetAlpha_434580(0x28u);
	nox_client_drawRectLines_473510(-3, yTop - 3, v3 + 6, v3 + 6);
	nox_client_drawEnableAlpha_434560(0);
	nox_client_copyRect_49F6F0(0, yTop, v3, v3);
	v6 = nox_xxx_minimap_587000_149232;
	v7 = v3 * v6 / 100;
	nox_xxx_getSomeCoods_435670(&v84);
	v8 = v84.field_0 - v7 / 2;
	v9 = v84.field_4 - v7 / 2;
	xLeft.field_0 = v84.field_0 - v7 / 2;
	xLeft.field_4 = v9;
	v81 = v8 / 23;
	v77 = (v8 + v7) / 23;
	v78 = (v9 + v7) / 23;
	v74 = 23 * (v8 / 23);
	v80 = 23 * (v9 / 23);
	v10 = v9 / 23;
	for (i = v9 / 23; i <= v78; ++i) {
		v11 = sub_4106A0(v10);
		while (v11) {
			v12 = *(uint8_t*)(v11 + 1);
			if (v12 == getMemByte(0x5D4594, 1096300)) {
				goto LABEL_37;
			}
			if (v12 == getMemByte(0x5D4594, 1096301)) {
				goto LABEL_37;
			}
			if (*(uint8_t*)(v11 + 8) && *(unsigned char*)(v11 + 8) != a2) {
				goto LABEL_37;
			}
			v13 = *(unsigned char*)(v11 + 5);
			if (v13 < v81) {
				goto LABEL_37;
			}
			if (v13 > v77) {
				break;
			}
			v14 = v74 + 23 * (v13 - v81);
			if (*(uint8_t*)(v11 + 4) & 0x10) {
				v15 = *(uint32_t*)(v11 + 32);
				if (!v15) {
					goto LABEL_37;
				}
				v69 = 0;
				v16 = getMemAt(0x587000, 149244);
				while (1) {
					v17 = nox_server_getWallAtGrid_410580(*((uint32_t*)v16 - 1) + *(unsigned char*)(v11 + 5),
														  *(uint32_t*)v16 + *(unsigned char*)(v11 + 6));
					if (v17) {
						if (*(uint32_t*)(v17 + 12)) {
							goto LABEL_28;
						}
					} else {
						v18 = nox_server_getWallAtGrid_410580(*((uint32_t*)v16 - 1) + *(unsigned char*)(v11 + 5),
															  *(unsigned char*)(v11 + 6));
						if (v18 && *(uint32_t*)(v18 + 12) ||
							(v19 = nox_server_getWallAtGrid_410580(
								 *(unsigned char*)(v11 + 5), *(uint32_t*)v16 + *(unsigned char*)(v11 + 6))) != 0 &&
								*(uint32_t*)(v19 + 12)) {
						LABEL_28:
							if (v69 < 4) {
								v20 = nox_xxx_minimap_587000_149232;
								v21 = 8 * *(unsigned char*)(v15 + 299);
								v22 = 100 * (*(int*)(v15 + 12) - xLeft.field_0) / v20;
								v85 = 100 * (*(int*)(v15 + 16) - xLeft.field_4) / v20;
								v23 = 100 * *getMemIntPtr(0x587000, 196184 + v21) / v20;
								v24 = 100 * *getMemIntPtr(0x587000, 196188 + v21) / v20;
								nox_client_drawSetColor_434460(*getMemIntPtr(0x85B3FC, 940));
								nox_client_drawAddPoint_49F500(v22, yTop + v85);
								nox_xxx_rasterPointRel_49F570(v23, v24);
								nox_client_drawLineFromPoints_49E4B0();
								v8 = xLeft.field_0;
							}
							goto LABEL_37;
						}
					}
					v16 += 8;
					++v69;
					if ((int)v16 >= (int)getMemAt(0x587000, 149276)) {
						goto LABEL_37;
					}
				}
			}
			if (nox_common_gameFlags_check_40A5C0(0x10000) || *(uint32_t*)(v11 + 12)) {
				v26 = nox_xxx_minimap_587000_149232;
				v25 = v26;
				v76.field_0 = 100 * (v14 - v8) / v26;
				v76.field_4 = yTop + 100 * (v80 - v9) / v26;
				v27 = *(uint8_t*)(v11 + 4);
				if (!(v27 & 4) || (v28 = *(uint8_t*)(*(uint32_t*)(v11 + 28) + 21), v28 != 3) && v28 != 2) {
					if (!(v27 & 0x20)) {
						sub_4730D0(&v76, *(uint8_t*)v11, 2300 / v25);
					}
				}
			}
		LABEL_37:
			v11 = *(uint32_t*)(v11 + 24);
			v9 = xLeft.field_4;
		}
		v10 = i + 1;
		v80 += 23;
	}
	if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_SHOW_AI)) {
		v29 = sub_50CB00();
		v30 = (char*)sub_50CB10();
		if (v29 >= 2) {
			nox_client_drawSetColor_434460(*getMemIntPtr(0x8531A0, 2572));
			if (v29 - 1 > 0) {
				v31 = (float*)(v30 + 8);
				v72 = v29 - 1;
				do {
					v32 = nox_xxx_minimap_587000_149232;
					v33 = *(v31 - 1);
					xLeft.field_0 = (int)(100 * ((unsigned long long)(long long)*(v31 - 2) - v8)) / v32;
					nox_client_drawAddPoint_49F500(xLeft.field_0,
												   yTop + (int)(100 * ((unsigned long long)(long long)v33 - v9)) / v32);
					v34 = nox_xxx_minimap_587000_149232;
					v35 = v31[1];
					xLeft.field_0 = (int)(100 * ((unsigned long long)(long long)*v31 - v8)) / v34;
					nox_client_drawAddPoint_49F500(xLeft.field_0,
												   yTop + (int)(100 * ((unsigned long long)(long long)v35 - v9)) / v34);
					nox_client_drawLineFromPoints_49E4B0();
					v31 += 2;
					--v72;
				} while (v72);
			}
		}
		for (j = (float*)nox_xxx_minimapFirstMonster_50AAE0(); j; j = (float*)nox_xxx_minimapNextMonster_50AB10()) {
			nox_client_drawSetColor_434460(*getMemIntPtr(0x85B3FC, 940));
			v37 = nox_xxx_minimap_587000_149232;
			v38 = j[1];
			xLeft.field_0 = (int)(100 * ((unsigned long long)(long long)*j - v8)) / v37;
			nox_xxx_minimapDrawPoint_473570(xLeft.field_0,
											yTop + (int)(100 * ((unsigned long long)(long long)v38 - v9)) / v37);
		}
	}
	v73 = 0;
	if (!*getMemU32Ptr(0x5D4594, 1096304)) {
		*getMemU32Ptr(0x5D4594, 1096304) = nox_xxx_getTTByNameSpriteMB_44CFC0("Crown");
		*getMemU32Ptr(0x5D4594, 1096308) = nox_xxx_getTTByNameSpriteMB_44CFC0("GameBall");
	}
	v39 = nox_xxx_objGetTeamByNetCode_418C80(nox_player_netCode_85319C);
	v70 = (int)v39;
	if (v39 && nox_xxx_servObjectHasTeam_419130((int)v39)) {
		v73 = 1;
	}
	for (k = nox_xxx_cliFirstMinimapObj_459EB0(); k; k = nox_xxx_cliNextMinimapObj_459EC0(k)) {
		v41 = nox_xxx_polygonIsPlayerInPolygon_4217B0((int2*)(k + 12), 0);
		if (v41) {
			if (BYTE2(v41->field_0[32]) != a2) {
				continue;
			}
		} else if (a2 != 1) {
			continue;
		}
		v42 = nox_xxx_minimap_587000_149232;
		xLeft.field_0 = 100 * (*(int*)(k + 12) - v8) / v42;
		xLeft.field_4 = yTop + 100 * (*(int*)(k + 16) - v9) / v42;
		if (!(*(uint32_t*)(k + 112) & 0x400000) || (v43 = nox_color_blue_2650684, !(*(uint8_t*)(k + 116) & 8))) {
			v43 = *getMemU32Ptr(0x85B3FC, 940);
		}
		nox_client_drawSetColor_434460(v43);
		v44 = *(uint32_t*)(k + 108);
		if (v44 == *getMemIntPtr(0x5D4594, 1096304)) {
			if (nox_server_teamFirst_418B10() || (v45 = nox_xxx_cliGetSpritePlayer_45A000()) == 0) {
			LABEL_64:
				nox_client_drawSetColor_434460(*getMemIntPtr(0x8531A0, 2572));
				v46 = nox_xxx_objGetTeamByNetCode_418C80(*(uint32_t*)(k + 128));
				if (v46) {
					v47 = nox_xxx_clientGetTeamColor_418AB0(*((unsigned char*)v46 + 4));
					if (v47) {
						v48 = nox_xxx_materialGetTeamColor_418D50((int)v47);
						nox_client_drawSetColor_434460(v48);
					}
				}
				sub_473420(&xLeft);
			} else {
				while (!nox_client_drawable_testBuff_4356C0(v45, 30)) {
					v45 = sub_45A010(v45);
					if (!v45) {
						goto LABEL_64;
					}
				}
			}
			continue;
		}
		if (v44 == *getMemIntPtr(0x5D4594, 1096308)) {
			v49 = nox_xxx_objGetTeamByNetCode_418C80(*(uint32_t*)(k + 128));
			v50 = v49;
			if (v49 && nox_xxx_servObjectHasTeam_419130((int)v49)) {
				v51 = nox_xxx_clientGetTeamColor_418AB0(*((unsigned char*)v50 + 4));
				if (v51) {
					v52 = nox_xxx_materialGetTeamColor_418D50((int)v51);
					nox_client_drawSetColor_434460(v52);
				}
			} else {
				nox_client_drawSetColor_434460(nox_color_white_2523948);
			}
			nox_video_drawCircleRad3_4734F0(&xLeft.field_0);
			continue;
		}
		v53 = *(uint32_t*)(k + 112);
		if (v53 & 0x10000000) {
			if (*(uint32_t*)(k + 120) & 0x1000000) {
				nox_client_drawSetColor_434460(nox_color_white_2523948);
				v54 = sub_4B9470(*(const char***)(k + 436));
				v55 = nox_xxx_clientGetTeamColor_418AB0(v54);
				if (v55) {
					goto LABEL_88;
				}
				goto LABEL_89;
			}
		} else {
			if (!(v53 & 4)) {
				nox_xxx_minimapDrawPoint_473570(xLeft.field_0, xLeft.field_4);
				continue;
			}
			if (!nox_common_gameFlags_check_40A5C0(32)) {
				if (k == *getMemIntPtr(0x852978, 8)) {
					sub_4735C0(xLeft.field_0, xLeft.field_4);
				} else {
					nox_xxx_minimapDrawPoint_473570(xLeft.field_0, xLeft.field_4);
				}
				continue;
			}
			v56 = nox_common_playerInfoGetByID_417040(*(uint32_t*)(k + 128));
			if (v56) {
				v81 = *((uint32_t*)v56 + 1) & 1;
				if (v81) {
					nox_client_drawSetColor_434460(nox_color_white_2523948);
					v57 = nox_xxx_objGetTeamByNetCode_418C80(*(uint32_t*)(k + 128));
					if (v57) {
						v55 = *((uint8_t*)v57 + 4) == 1 ? nox_xxx_clientGetTeamColor_418AB0(2)
														: nox_xxx_clientGetTeamColor_418AB0(1);
						if (v55) {
						LABEL_88:
							v58 = nox_xxx_materialGetTeamColor_418D50((int)v55);
							nox_client_drawSetColor_434460(v58);
						}
					}
				LABEL_89:
					sub_4733B0(&xLeft);
					continue;
				}
			}
		}
	}
	v79 = *getMemU32Ptr(0x8531A0, 2572);
	for (l = nox_xxx_cliGetSpritePlayer_45A000(); l; l = sub_45A010(l)) {
		v60 = nox_client_drawable_testBuff_4356C0(l, 30);
		v61 = *(uint32_t*)(l + 128);
		v77 = v60;
		v62 = nox_xxx_objGetTeamByNetCode_418C80(v61);
		v68 = *(uint32_t*)(l + 128);
		v81 = (int)v62;
		v75 = nox_common_playerInfoGetByID_417040(v68);
		if (v70 && v62 && v73) {
			v76.field_0 = nox_xxx_servCompareTeams_419150(v70, (int)v62);
			if (v76.field_0) {
				goto LABEL_103;
			}
		} else {
			v76.field_0 = 0;
		}
		if (v77 || l == *getMemU32Ptr(0x852978, 8) || *(uint8_t*)(*getMemU32Ptr(0x8531A0, 2576) + 3680) & 1) {
		LABEL_103:
			v63 = nox_xxx_polygonIsPlayerInPolygon_4217B0((int2*)(l + 12), 0);
			if ((!v63 || BYTE2(v63->field_0[32]) == a2) && v75 && (v75[3680] & 1) != 1) {
				v64 = nox_xxx_minimap_587000_149232;
				xLeft.field_0 = 100 * (*(int*)(l + 12) - v8) / v64;
				xLeft.field_4 = yTop + 100 * (*(int*)(l + 16) - v9) / v64;
				if (l == *getMemU32Ptr(0x852978, 8) || v76.field_0) {
					nox_client_drawSetColor_434460(v79);
				} else {
					nox_client_drawSetColor_434460(*getMemIntPtr(0x85B3FC, 940));
				}
				if (v77) {
					if (v81) {
						v65 = nox_xxx_clientGetTeamColor_418AB0(*(unsigned char*)(v81 + 4));
						if (v65) {
							v66 = nox_xxx_materialGetTeamColor_418D50((int)v65);
							nox_client_drawSetColor_434460(v66);
						}
					}
					sub_473420(&xLeft);
				} else {
					nox_xxx_minimapDrawPoint_473570(xLeft.field_0, xLeft.field_4);
				}
			}
		}
	}
	return sub_49F860();
}

//----- (004730D0) --------------------------------------------------------
int sub_4730D0(int2* a1, unsigned char a2, int a3) {
	int result = 0; // eax
	int v4;     // ebx
	int v5;     // edi
	int2* v6;   // ebp

	if (nox_xxx_minimap_587000_149232 <= 2000) {
		v4 = *getMemU32Ptr(0x85B3FC, 956);
		result = a2;
		v5 = a3 / 2;
		switch (a2) {
		case 0u:
			result =
				sub_473380(a1->field_0, a3 + a1->field_4, a1->field_0 + a3, a1->field_4, *getMemIntPtr(0x85B3FC, 956));
			break;
		case 1u:
			result =
				sub_473380(a1->field_0, a1->field_4, a1->field_0 + a3, a1->field_4 + a3, *getMemIntPtr(0x85B3FC, 956));
			break;
		case 2u:
			sub_473380(a1->field_0, a3 + a1->field_4, a1->field_0 + a3, a1->field_4, *getMemIntPtr(0x85B3FC, 956));
			result = sub_473380(a1->field_0, a1->field_4, a1->field_0 + a3, a1->field_4 + a3, v4);
			break;
		case 3u:
			sub_473380(a1->field_0, a1->field_4, a1->field_0 + v5, a1->field_4 + v5, *getMemIntPtr(0x85B3FC, 956));
			result = sub_473380(a1->field_0, a3 + a1->field_4, a3 + a1->field_0, a1->field_4, v4);
			break;
		case 4u:
			sub_473380(a1->field_0, a1->field_4, a1->field_0 + a3, a1->field_4 + a3, *getMemIntPtr(0x85B3FC, 956));
			result = sub_473380(v5 + a1->field_0, v5 + a1->field_4, a3 + a1->field_0, a1->field_4, v4);
			break;
		case 5u:
			sub_473380(a1->field_0, a3 + a1->field_4, a1->field_0 + a3, a1->field_4, *getMemIntPtr(0x85B3FC, 956));
			result = sub_473380(v5 + a1->field_0, v5 + a1->field_4, a3 + a1->field_0, a1->field_4 + a3, v4);
			break;
		case 6u:
			v6 = a1;
			sub_473380(a1->field_0, a1->field_4, a1->field_0 + a3, a1->field_4 + a3, *getMemIntPtr(0x85B3FC, 956));
			goto LABEL_15;
		case 7u:
			sub_473380(a1->field_0, a1->field_4, a1->field_0 + v5, a1->field_4 + v5, *getMemIntPtr(0x85B3FC, 956));
			result = sub_473380(v5 + a1->field_0, v5 + a1->field_4, a3 + a1->field_0, a1->field_4, v4);
			break;
		case 8u:
			sub_473380(v5 + a1->field_0, v5 + a1->field_4, a1->field_0 + a3, a1->field_4 + a3,
					   *getMemIntPtr(0x85B3FC, 956));
			result = sub_473380(v5 + a1->field_0, v5 + a1->field_4, a3 + a1->field_0, a1->field_4, v4);
			break;
		case 9u:
			sub_473380(v5 + a1->field_0, v5 + a1->field_4, a1->field_0 + a3, a1->field_4 + a3,
					   *getMemIntPtr(0x85B3FC, 956));
			result = sub_473380(v5 + a1->field_0, v5 + a1->field_4, a1->field_0, a1->field_4 + a3, v4);
			break;
		case 0xAu:
			v6 = a1;
			sub_473380(a1->field_0, a1->field_4, a1->field_0 + v5, a1->field_4 + v5, *getMemIntPtr(0x85B3FC, 956));
		LABEL_15:
			result = sub_473380(v6->field_0, a3 + v6->field_4, v5 + v6->field_0, v6->field_4 + v5, v4);
			break;
		default:
			return result;
		}
	} else {
		nox_client_drawSetColor_434460(*getMemIntPtr(0x85B3FC, 956));
		nox_client_drawPixel_49EFA0(a1->field_0, a1->field_4);
	}
	return result;
}

//----- (00473380) --------------------------------------------------------
int sub_473380(int a1, int a2, int a3, int a4, int a5) {
	nox_client_drawSetColor_434460(a5);
	nox_client_drawAddPoint_49F500(a1, a2);
	nox_client_drawAddPoint_49F500(a3, a4);
	return nox_client_drawLineFromPoints_49E4B0();
}

//----- (004733B0) --------------------------------------------------------
int sub_4733B0(uint32_t* a1) {
	int v1; // esi
	int v2; // edi

	v1 = a1[1] + 4;
	v2 = *a1 - 2;
	nox_client_drawAddPoint_49F500(v2, v1);
	v1 -= 8;
	nox_client_drawAddPoint_49F500(v2, v1);
	nox_client_drawLineFromPoints_49E4B0();
	nox_client_drawAddPoint_49F500(v2, v1);
	v2 += 4;
	nox_client_drawAddPoint_49F500(v2, v1);
	nox_client_drawLineFromPoints_49E4B0();
	nox_client_drawAddPoint_49F500(v2, v1);
	v1 += 4;
	nox_client_drawAddPoint_49F500(v2, v1);
	nox_client_drawLineFromPoints_49E4B0();
	nox_client_drawAddPoint_49F500(v2, v1);
	nox_client_drawAddPoint_49F500(v2 - 4, v1);
	return nox_client_drawLineFromPoints_49E4B0();
}

//----- (00473420) --------------------------------------------------------
int sub_473420(uint32_t* a1) {
	int v1; // edi
	int v2; // esi

	v1 = a1[1] + 6;
	v2 = *a1 - 4;
	nox_client_drawAddPoint_49F500(v2, v1);
	v1 -= 12;
	v2 -= 2;
	nox_client_drawAddPoint_49F500(v2, v1);
	nox_client_drawLineFromPoints_49E4B0();
	nox_client_drawAddPoint_49F500(v2, v1);
	v1 += 6;
	v2 += 4;
	nox_client_drawAddPoint_49F500(v2, v1);
	nox_client_drawLineFromPoints_49E4B0();
	nox_client_drawAddPoint_49F500(v2, v1);
	v1 -= 6;
	v2 += 2;
	nox_client_drawAddPoint_49F500(v2, v1);
	nox_client_drawLineFromPoints_49E4B0();
	nox_client_drawAddPoint_49F500(v2, v1);
	v1 += 6;
	v2 += 2;
	nox_client_drawAddPoint_49F500(v2, v1);
	nox_client_drawLineFromPoints_49E4B0();
	nox_client_drawAddPoint_49F500(v2, v1);
	v1 -= 6;
	v2 += 4;
	nox_client_drawAddPoint_49F500(v2, v1);
	nox_client_drawLineFromPoints_49E4B0();
	nox_client_drawAddPoint_49F500(v2, v1);
	v1 += 12;
	v2 -= 2;
	nox_client_drawAddPoint_49F500(v2, v1);
	nox_client_drawLineFromPoints_49E4B0();
	nox_client_drawAddPoint_49F500(v2, v1);
	nox_client_drawAddPoint_49F500(v2 - 8, v1);
	return nox_client_drawLineFromPoints_49E4B0();
}

//----- (004734F0) --------------------------------------------------------
void nox_video_drawCircleRad3_4734F0(int* a1) { nox_video_drawCircle_4B0B90(a1[0], a1[1], 3); }

//----- (00473510) --------------------------------------------------------
int nox_client_drawRectLines_473510(int a1, int a2, int a3, int a4) {
	int v4; // esi
	int v5; // edi

	nox_client_drawAddPoint_49F500(a1, a2);
	v4 = a1 + a3 - 1;
	nox_client_drawAddPoint_49F500(v4, a2);
	nox_client_drawLineFromPoints_49E4B0();
	nox_client_drawAddPoint_49F500(v4, a2);
	v5 = a4 - 1 + a2;
	nox_client_drawAddPoint_49F500(v4, v5);
	nox_client_drawLineFromPoints_49E4B0();
	nox_client_drawAddPoint_49F500(v4, v5);
	nox_client_drawAddPoint_49F500(a1, v5);
	return nox_client_drawLineFromPoints_49E4B0();
}

//----- (00473570) --------------------------------------------------------
void nox_xxx_minimapDrawPoint_473570(int xLeft, int yTop) {
	if (nox_xxx_minimap_587000_149232 > 1200) {
		nox_xxx_drawPointMB_499B70(xLeft, yTop, (nox_xxx_minimap_587000_149232 < 1750) + 2);
	} else {
		nox_xxx_drawPointMB_499B70(xLeft, yTop, 4);
	}
}

//----- (004735C0) --------------------------------------------------------
void sub_4735C0(int xLeft, int yTop) {
	if (nox_xxx_minimap_587000_149232 > 1200) {
		nox_xxx_drawPointMB_499B70(xLeft, yTop, (nox_xxx_minimap_587000_149232 < 1750) + 4);
	} else {
		nox_xxx_drawPointMB_499B70(xLeft, yTop, 6);
	}
}

//----- (004738E0) --------------------------------------------------------
int nox_xxx_drawMinimapAndLines_4738E0() {
	int result;   // eax
	uint32_t* v1; // eax

	result = 1;
	if (nox_client_gui_flag_1556112 != 1) {
		if (getMemByte(0x5D4594, 1096424) & 1) {
			v1 = nox_xxx_netSpriteByCodeDynamic_45A6F0(nox_player_netCode_85319C);
			nox_xxx_drawMinimap4Sprite_4725C0((int)v1);
		}
		result = nox_xxx_drawMessageLines_445530();
	}
	return result;
}

//----- (00473920) --------------------------------------------------------
void nox_xxx____setargv_11_473920() { *getMemU32Ptr(0x5D4594, 1096520) = 1; }

//----- (00473930) --------------------------------------------------------
char* sub_473930() {
	char* result; // eax

	*getMemU32Ptr(0x5D4594, 1096456) = nox_xxx_gLoadAnim_42FA20("ConfusedBirdies");
	result = nox_xxx_gLoadAnim_42FA20("SphericalShieldAnim");
	*getMemU32Ptr(0x5D4594, 1096460) = result;
	return result;
}

//----- (00473960) --------------------------------------------------------
int sub_473960() {
	int result; // eax

	result = 0;
	*getMemU32Ptr(0x5D4594, 1096456) = 0;
	*getMemU32Ptr(0x5D4594, 1096460) = 0;
	return result;
}

//----- (004739E0) --------------------------------------------------------
int sub_4739E0(uint32_t* a1, int2* a2, int2* a3) {
	int result; // eax

	a3->field_0 = a2->field_0 + *a1 - a1[4];
	result = a2->field_4;
	a3->field_4 = result + a1[1] - a1[5];
	return result;
}

//----- (00473A10) --------------------------------------------------------
int sub_473A10(uint32_t* a1, int2* a2, uint32_t* a3) {
	int result; // eax

	*a3 = a2->field_0 + a1[4] - *a1;
	result = a2->field_4;
	a3[1] = result + a1[5] - a1[1];
	return result;
}

//----- (00473C10) --------------------------------------------------------
void nox_xxx_drawWalls_473C10(nox_draw_viewport_t* vp, void* data) {
	uint32_t* a1 = vp;
	unsigned char* a2 = data;
	unsigned char* v3; // esi
	unsigned char v4;  // dl
	int v5;            // ecx
	int v6;            // ebx
	int v7;            // ebp
	int v8;            // eax
	int v9;            // edi
	int v10;           // eax
	int v11;           // ecx
	int v12;           // eax
	int v13;           // ecx
	int v14;           // eax
	int v15;           // edx
	int v16;           // eax
	int v17;           // ecx
	int v18;           // eax
	int v19;           // ecx
	bool v20;          // zf
	int v21;           // edx
	int v22;           // ebx
	int v23;           // ecx
	int v24;           // edx
	int v25;           // eax
	unsigned char v26; // al
	unsigned char v27; // al
	char v28;          // cl
	int v29;           // eax
	int v30;           // eax
	int v31;           // eax
	int* v32;          // edi
	int v33;           // eax
	int v34;           // eax
	int v35;           // eax
	int v36;           // edx
	int v37;           // eax
	int v38;           // eax
	int v39;           // eax
	int v40;           // edx
	int v41;           // eax
	int v42;           // eax
	int v43;           // eax
	int v44;           // edx
	char* v45;         // eax
	int v46;           // ebx
	int v47;           // ebp
	int v48;           // eax
	int v49;           // ecx
	int v50;           // edx
	int v51;           // eax
	int v52;           // eax
	int v53;           // eax
	uint8_t* v54;      // edi
	char* v55;         // eax
	int v56;           // ebx
	int v57;           // ebp
	int v58;           // eax
	int v59;           // edx
	int v60;           // ecx
	int v61;           // eax
	int v63;           // [esp-18h] [ebp-80h]
	int v64;           // [esp-14h] [ebp-7Ch]
	int v65;           // [esp-10h] [ebp-78h]
	int v66;           // [esp-Ch] [ebp-74h]
	int v67;           // [esp-8h] [ebp-70h]
	int v68;           // [esp-4h] [ebp-6Ch]
	int v69;           // [esp-4h] [ebp-6Ch]
	int a3;            // [esp+10h] [ebp-58h]
	int a4;            // [esp+14h] [ebp-54h]
	int v72;           // [esp+18h] [ebp-50h]
	int v73;           // [esp+1Ch] [ebp-4Ch]
	int v74;           // [esp+20h] [ebp-48h]
	int v75;           // [esp+24h] [ebp-44h]
	int v76;           // [esp+28h] [ebp-40h]
	int2 v77;          // [esp+2Ch] [ebp-3Ch]
	int2 a2a;          // [esp+34h] [ebp-34h]
	int2 a1a;          // [esp+3Ch] [ebp-2Ch]
	int2 v80;          // [esp+44h] [ebp-24h]
	int2 v81;          // [esp+4Ch] [ebp-1Ch]
	int v82;           // [esp+54h] [ebp-14h]
	int v83[3];        // [esp+5Ch] [ebp-Ch]
	int v84;           // [esp+70h] [ebp+8h]

	v3 = a2;
	a4 = nox_win_width;
	v72 = 0;
	a3 = 0;
	if (!a2) {
		return;
	}
	v4 = a2[4];
	if (!(v4 & 1)) {
		return;
	}
	v5 = a2[6];
	v6 = *a1 + 23 * a2[5] - a1[4];
	v82 = *a1 + 23 * a2[5] - a1[4];
	v7 = a1[1] + 23 * v5 - a1[5];
	v74 = *getMemU32Ptr(0x587000, 149364 + 4 * a2[3]);
	v8 = v74;
	if (v74 == -1) {
		v8 = *a2;
		v74 = *a2;
	}
	v84 = v8;
	if (v8) {
		if (v8 == 1 && v4 & 0x40) {
			v84 = 12;
		}
	} else if (v4 & 0x40) {
		v84 = 11;
	}
	if (*getMemU32Ptr(0x587000, 80808)) {
		v9 = 16 * v74;
		v10 = *getMemU32Ptr(0x587000, 85440 + 16 * v74);
		v11 = *getMemU32Ptr(0x587000, 85448 + 16 * v74);
		a1a.field_4 = v7 + *getMemU32Ptr(0x587000, 85444 + 16 * v74);
		v12 = v6 + v10;
		a2a.field_4 = v7 + *getMemU32Ptr(0x587000, 85452 + 16 * v74);
		v13 = v6 + v11;
		a1a.field_0 = v12;
		a2a.field_0 = v13;
		if (v74 == 7 || v74 == 9) {
			if (sub_4C42A0(&a1a, &a2a, &a3, &a4)) {
				v22 = 1;
			} else {
				v22 = 0;
				a3 = a2a.field_0;
			}
			v23 = *getMemU32Ptr(0x587000, 85508 + v9);
			a1a.field_0 = v82 + *getMemU32Ptr(0x587000, 85504 + v9);
			v24 = v82 + *getMemU32Ptr(0x587000, 85512 + v9);
			v25 = *getMemU32Ptr(0x587000, 85516 + v9);
			a1a.field_4 = v7 + v23;
			a2a.field_0 = v24;
			a2a.field_4 = v7 + v25;
			if (sub_4C42A0(&a1a, &a2a, &a3, &a4)) {
			LABEL_51:
				v19 = a3;
			} else {
				if (!v22) {
					return;
				}
				if (a4 > a1a.field_0) {
					a4 = a1a.field_0;
				}
				v19 = a3;
			}
		} else {
			if (v74 != 8 && v74 != 10) {
				if (!sub_4C42A0(&a1a, &a2a, &a3, &a4)) {
					return;
				}
				goto LABEL_51;
			}
			v76 = v13;
			v75 = v12;
			if (sub_4C42A0(&a1a, &a2a, &v75, &v76)) {
				v73 = v76 - v75 >= 3;
			} else {
				v73 = 0;
			}
			v14 = *getMemU32Ptr(0x587000, 85504 + 16 * v74);
			v15 = *getMemU32Ptr(0x587000, 85516 + 16 * v74);
			v80.field_4 = v7 + *getMemU32Ptr(0x587000, 85508 + 16 * v74);
			v16 = v6 + v14;
			v17 = v6 + *getMemU32Ptr(0x587000, 85512 + 16 * v74);
			v80.field_0 = v16;
			a3 = v16;
			v81.field_0 = v17;
			a4 = v17;
			v81.field_4 = v7 + v15;
			v18 = sub_4C42A0(&v80, &v81, &a3, &a4);
			v19 = a3;
			v20 = v18 == 0;
			if (v20) {
				v21 = 0;
			} else {
				v21 = a4 - a3 >= 3;
			}
			if (v73) {
				if (v21) {
					if (a3 > v75) {
						v19 = v75;
						a3 = v75;
					}
					if (v19 <= v80.field_0) {
						v19 = 0;
						a3 = 0;
					}
					if (a4 < v76) {
						a4 = v76;
					}
					if (a4 >= v81.field_0) {
						a4 = nox_win_width;
					}
				} else {
					v19 = v75;
					a3 = v75;
					a4 = v76;
					if (v74 != 8) {
						v84 = 1;
						goto LABEL_33;
					}
					v84 = 0;
					if (v76 == v81.field_0) {
						a4 = nox_win_width;
					}
				}
			} else {
				if (!v21) {
					return;
				}
				v84 = (v74 != 8) + 13;
				if (a4 == v81.field_0) {
					a4 = nox_win_width;
				}
			LABEL_33:
				if (v19 == v80.field_0) {
					v19 = 0;
					a3 = 0;
				}
			}
		}
		if (v19 >= a4) {
			v26 = v3[4];
			v3[3] = 0;
			v3[4] = v26 & 0xFC;
			return;
		}
	}
	v27 = v3[4];
	v28 = v3[4] & 2;
	if (!v28) {
		v29 = (v3[4] >> 2) & 2;
		goto LABEL_64;
	}
	if (*getMemU32Ptr(0x5D4594, 805848) && nox_client_translucentFrontWalls_805844) {
		if (!nox_client_highResFrontWalls_80820 && nox_client_highResFloors_154952) {
			v72 |= 4u;
			goto LABEL_61;
		}
		v72 = 8;
	}
	if (!nox_client_highResFrontWalls_80820) {
		v72 |= 4u;
	}
LABEL_61:
	v29 = (v27 & 8 | 4u) >> 2;
LABEL_64:
	v73 = v29;
	if (v28 && nox_client_translucentFrontWalls_805844 && !(getMemByte(0x85B3FC, 43076 + 12332 * v3[1]) & 4)) {
		v30 = v72;
		LOBYTE(v30) = v72 | 2;
		v72 = v30;
	} else {
		v72 |= 1u;
	}
	if (*getMemU32Ptr(0x587000, 80816)) {
		switch (v74) {
		case 0:
		case 3:
			v31 = v3[6];
			v77.field_0 = 23 * v3[5];
			v77.field_4 = 23 * (v31 + 1);
			v32 = sub_469920(&v77);
			if (v32 != (int*)31) {
				v83[0] = *v32;
				v83[1] = v32[1];
				v33 = v32[2];
				v32 = v83;
				v83[2] = v33;
			}
			v77.field_0 += 23;
			v77.field_4 -= 23;
			v34 = sub_469920(&v77);
			break;
		case 1:
		case 4:
			v35 = v3[6];
			v77.field_0 = 23 * v3[5];
			v77.field_4 = 23 * v35;
			v32 = sub_469920(&v77);
			if (v32 != (int*)31) {
				v83[0] = *v32;
				v83[1] = v32[1];
				v36 = v32[2];
				v32 = v83;
				v83[2] = v36;
			}
			v77.field_0 += 23;
			v77.field_4 += 23;
			v34 = sub_469920(&v77);
			break;
		case 7:
			v37 = v3[6];
			v77.field_0 = 23 * v3[5];
			v77.field_4 = 23 * v37;
			v32 = sub_469920(&v77);
			if (v32 != (int*)31) {
				v83[0] = *v32;
				v83[1] = v32[1];
				v38 = v32[2];
				v32 = v83;
				v83[2] = v38;
			}
			v77.field_0 += 23;
			v34 = sub_469920(&v77);
			break;
		case 8:
			v39 = v3[6];
			v77.field_0 = 23 * v3[5] + 11;
			v77.field_4 = 23 * v39 + 11;
			v32 = sub_469920(&v77);
			if (v32 != (int*)31) {
				v83[0] = *v32;
				v83[1] = v32[1];
				v40 = v32[2];
				v32 = v83;
				v83[2] = v40;
			}
			v77.field_0 -= 34;
			v77.field_4 -= 34;
			v34 = sub_469920(&v77);
			break;
		case 10:
			v41 = v3[6];
			v77.field_0 = 23 * v3[5];
			v77.field_4 = 23 * (v41 + 1);
			v32 = sub_469920(&v77);
			if (v32 != (int*)31) {
				v83[0] = *v32;
				v83[1] = v32[1];
				v42 = v32[2];
				v32 = v83;
				v83[2] = v42;
			}
			v77.field_0 += 11;
			v77.field_4 -= 11;
			v34 = sub_469920(&v77);
			break;
		default:
			v43 = v3[6];
			v77.field_0 = 23 * v3[5];
			v77.field_4 = 23 * (v43 + 1);
			v32 = sub_469920(&v77);
			if (v32 != (int*)31) {
				v83[0] = *v32;
				v83[1] = v32[1];
				v44 = v32[2];
				v32 = v83;
				v83[2] = v44;
			}
			v77.field_0 += 23;
			v34 = sub_469920(&v77);
			break;
		}
		v74 = v34;
		v45 = nox_xxx_getWallDrawOffset_46A3F0(v3[1], v84, v3[2], v73);
		v46 = v82 + *(uint32_t*)v45 - 51;
		v47 = -73 - *((uint32_t*)v45 + 1) + v7;
		sub_4345F0(1);
		v48 = *((uint8_t*)v32 + 8);
		LOBYTE(v49) = *((uint8_t*)v32 + 4);
		LOBYTE(v50) = *(uint8_t*)v32;
		nox_draw_setColorMultAndIntensityRGB_433CD0(v50, v49, v48);
		if (!(v72 & 2)) {
			v69 = v72;
			v66 = a4;
			v65 = a3;
			v64 = nox_win_height;
			v63 = v74;
			v52 = nox_xxx_getWallSprite_46A3B0(v3[1], v84, v3[2], v73);
			nox_xxx_edgeDraw_480EF0(v52, v46, v47, v32, v63, v64, v65, v66, 0, v69);
			goto LABEL_106;
		}
		if (!sub_47D380(a3, a4)) {
			goto LABEL_106;
		}
		nox_client_drawEnableAlpha_434560(1);
		nox_client_drawSetAlpha_434580(0x80u);
		sub_47D400(nox_client_highResFrontWalls_80820 == 0, a1[5]);
		v68 = v47;
		v67 = v46;
		v51 = nox_xxx_getWallSprite_46A3B0(v3[1], v84, v3[2], v73);
	} else {
		v53 = v3[6];
		v77.field_0 = 23 * v3[5] + 11;
		v77.field_4 = 23 * v53 + 11;
		v54 = sub_469920(&v77);
		v55 = nox_xxx_getWallDrawOffset_46A3F0(v3[1], v84, v3[2], v73);
		v56 = v82 + *(uint32_t*)v55 - 50;
		v57 = -72 - *((uint32_t*)v55 + 1) + v7;
		sub_4345F0(1);
		LOBYTE(v59) = v54[8];
		v58 = v54[4];
		LOBYTE(v60) = *v54;
		nox_draw_setColorMultAndIntensityRGB_433CD0(v60, v58, v59);
		if (!(v72 & 2)) {
			if (sub_47D380(a3, a4)) {
				sub_47D400(nox_client_highResFrontWalls_80820 == 0, a1[5]);
				v61 = nox_xxx_getWallSprite_46A3B0(v3[1], v84, v3[2], v73);
				nox_client_drawImageAt_47D2C0(v61, v56, v57);
				sub_47D400(0, 0);
			}
			goto LABEL_106;
		}
		if (!sub_47D380(a3, a4)) {
			goto LABEL_106;
		}
		nox_client_drawEnableAlpha_434560(1);
		nox_client_drawSetAlpha_434580(0x80u);
		sub_47D400(nox_client_highResFrontWalls_80820 == 0, a1[5]);
		v68 = v57;
		v67 = v56;
		v51 = nox_xxx_getWallSprite_46A3B0(v3[1], v84, v3[2], v73);
	}
	nox_client_drawImageAt_47D2C0(v51, v67, v68);
	sub_47D400(0, 0);
	nox_client_drawEnableAlpha_434560(0);
LABEL_106:
	sub_4345F0(0);
	v3[3] = 0;
	v3[4] &= 0xFC;
	*((uint32_t*)v3 + 3) = 1;
	return;
}
// 474366: variable 'v50' is possibly undefined
// 474366: variable 'v49' is possibly undefined
// 4744A3: variable 'v60' is possibly undefined
// 4744A3: variable 'v59' is possibly undefined

//----- (00474B40) --------------------------------------------------------
int sub_474B40(nox_drawable* dr) {
	int a1 = dr;
	uint32_t* v1; // edi
	uint32_t* v2; // eax
	int v3;       // eax

	v1 = nox_xxx_objGetTeamByNetCode_418C80(nox_player_netCode_85319C);
	if (v1) {
		v2 = nox_xxx_objGetTeamByNetCode_418C80(*(uint32_t*)(a1 + 128));
		if (v2) {
			if (nox_player_netCode_85319C == *(uint32_t*)(a1 + 128) ||
				nox_xxx_servCompareTeams_419150((int)v1, (int)v2)) {
				return 1;
			}
		}
	}
	v3 = *getMemU32Ptr(0x852978, 8);
	if (a1 == *getMemU32Ptr(0x852978, 8)) {
		return 1;
	}
	if (*getMemU32Ptr(0x852978, 8)) {
		if (!nox_client_drawable_testBuff_4356C0(*getMemIntPtr(0x852978, 8), 21)) {
			v3 = *getMemU32Ptr(0x852978, 8);
			goto LABEL_9;
		}
		return 1;
	}
LABEL_9:
	if (*(uint8_t*)(a1 + 112) & 4) {
		if (a1 != v3) {
			nox_common_playerInfoGetByID_417040(*(uint32_t*)(a1 + 128));
		}
	}
	return 0;
}

//----- (004756E0) --------------------------------------------------------
int nox_xxx_sprite_4756E0_drawable(nox_drawable* dr) {
	uint32_t* a1 = dr;
	int result;           // eax
	int (*v2)(int*, int); // esi
	int v3;               // edx
	int v4;               // ecx

	result = 0;
	v2 = (int (*)(int*, int))a1[75];
	if (v2) {
		v3 = a1[30];
		v4 = a1[28];
		if (!(v3 & 0x1000) && v3 & 1 && (v2 == nox_thing_static_draw || v2 == nox_thing_static_random_draw) &&
			!(v4 & 0x80800000) && (v3 & 0x48 || v4 & 0x400000) && !(v3 & 0x800)) {
			result = 1;
		}
	}
	return result;
}

//----- (00475740) --------------------------------------------------------
int nox_xxx_sprite_475740_drawable(nox_drawable* dr) {
	uint32_t* a1 = dr;
	int result;           // eax
	int (*v2)(int*, int); // edx
	int v3;               // ebx
	int v4;               // ecx

	result = 0;
	v2 = (int (*)(int*, int))a1[75];
	if (v2) {
		v3 = a1[30];
		v4 = a1[28];
		if (!(v3 & 0x1000)) {
			if (v3 & 1) {
				result = 1;
				if ((v2 == nox_thing_static_draw || v2 == nox_thing_static_random_draw) && !(v4 & 0x80800000) &&
					!(v3 & 0x800) && (v3 & 0x48 || v4 & 0x400000)) {
					result = 0;
				}
			}
		}
	}
	return result;
}

//----- (004757A0) --------------------------------------------------------
int nox_xxx_sprite_4757A0_drawable(nox_drawable* dr) {
	int a1 = dr;
	int result; // eax
	int v2;     // ecx

	result = 0;
	if (*(uint32_t*)(a1 + 300)) {
		v2 = *(uint32_t*)(a1 + 120);
		if (!(v2 & 0x1000)) {
			if (v2 & 0x4000) {
				if (v2 & 0x40) {
					result = 1;
				}
			}
		}
	}
	return result;
}

//----- (004757D0) --------------------------------------------------------
int sub_4757D0_drawable(nox_drawable* dr) {
	uint32_t* a1 = dr;
	int result; // eax
	int v2;     // ecx

	result = 0;
	if (a1[75]) {
		v2 = a1[30];
		if (!(v2 & 1) && (!(a1[28] & 0x2000) || v2 & 0x1000000) && !(v2 & 0x1000)) {
			result = 1;
		}
	}
	return result;
}

int nox_xxx_drawAllMB_475810_draw_B(nox_draw_viewport_t* vp) {
	int v10 = 1;
	int v11;
	float2 v38;
	if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_FLOOR_RENDERING) ||
		(v38.field_0 = (double)vp->field_6, v38.field_4 = (double)vp->field_7,
		 v11 = nox_xxx_tileNFromPoint_411160(&v38), v11 == 255) ||
		v11 == -1) {
		v10 = 0;
	}
	return v10;
}
