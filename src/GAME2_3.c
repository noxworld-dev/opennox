#include <math.h>

#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME2_2.h"
#include "GAME2_3.h"
#include "GAME3.h"
#include "GAME3_1.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4.h"
#include "GAME5_2.h"
#include "client__drawable__drawable.h"
#include "common__system__team.h"

#include "client__gui__chathelp.h"
#include "client__gui__gadgets__listbox.h"
#include "client__gui__guicon.h"
#include "client__gui__guiinv.h"
#include "client__gui__guiquit.h"
#include "client__gui__guivote.h"
#include "client__gui__window.h"
#include "client__network__cdecode.h"
#include "client__network__deathmsg.h"
#include "client__shell__noxworld.h"

#include "client__draw__fx.h"
#include "client__gui__guibook.h"
#include "client__video__draw_common.h"

#include "common/fs/nox_fs.h"
#include "common__magic__speltree.h"
#include "common__net_list.h"
#include "defs.h"
#include "input_common.h"
#include "operators.h"

extern unsigned char byte_5D4594_3804364[160];

extern uint32_t dword_5d4594_1301808;
extern uint32_t dword_5d4594_1303508;
extern uint32_t dword_5d4594_1200776;
extern uint32_t dword_5d4594_1301796;
extern uint32_t dword_5d4594_1203832;
extern uint32_t dword_5d4594_1200796;
extern uint32_t dword_5d4594_1305788;
extern void* nox_alloc_healthChange_1301772;
extern uint32_t nox_server_sanctuaryHelp_54276;
extern uint32_t dword_5d4594_1303536;
extern uint32_t dword_5d4594_1197308;
extern uint32_t dword_5d4594_1197372;
extern uint32_t dword_5d4594_1301816;
extern void* nox_alloc_friendList_1203860;
extern uint32_t dword_5d4594_1301812;
extern uint32_t dword_5d4594_1305748;
extern uint32_t dword_5d4594_1197328;
extern uint32_t dword_5d4594_1303472;
extern uint32_t dword_5d4594_1197352;
extern uint32_t dword_5d4594_1197336;
extern uint32_t dword_5d4594_1197356;
extern uint32_t dword_5d4594_1303468;
extern uint32_t dword_5d4594_1301780;
extern uint32_t dword_5d4594_1203836;
extern uint32_t dword_5d4594_1203840;
extern uint32_t dword_5d4594_1197332;
extern void* nox_alloc_chat_1197364;
extern uint32_t dword_5d4594_1203864;
extern uint32_t dword_5d4594_1217452;
extern uint32_t dword_5d4594_1193712;
extern uint32_t nox_server_connectionType_3596;
extern void* nox_draw_colorTablesRev_3804668;
extern uint32_t dword_5d4594_810636;
extern uint32_t dword_5d4594_1301776;
extern uint32_t dword_5d4594_1197316;
extern uint32_t dword_5d4594_1217460;
extern uint32_t cpuid_5d4594_3801804;
extern void* nox_alloc_pixelSpan_1301844;
extern uint32_t dword_5d4594_1197320;
extern uint32_t nox_wol_servers_sorting_166704;
extern uint32_t dword_5d4594_1197324;
extern uint32_t dword_5d4594_1217456;
extern uint32_t dword_5d4594_1305680;
extern uint32_t dword_5d4594_1301848;
extern uint32_t dword_5d4594_1197312;
extern uint32_t dword_5d4594_1303452;
extern uint32_t nox_client_gui_flag_815132;
extern uint32_t dword_5d4594_1305684;
extern uint32_t dword_5d4594_1217464;
extern uint32_t nox_video_modeXxx_3801780;
extern uint32_t dword_5d4594_810632;
extern uint32_t nox_client_renderGUI_80828;
extern uint32_t dword_5d4594_1217448;
extern uint32_t nox_player_netCode_85319C;
extern unsigned char* nox_draw_colors_r_3804672;
extern unsigned char* nox_draw_colors_g_3804656;
extern unsigned char* nox_draw_colors_b_3804664;
extern uint8_t** nox_pixbuffer_rows_3798784;
extern int nox_win_width;
extern int nox_win_height;
extern int nox_backbuffer_width;
extern int nox_backbuffer_height;
extern unsigned int nox_gameFPS;
extern unsigned int nox_frame_xxx_2598000;
extern uint32_t dword_5d4594_3799476;

extern uint32_t nox_color_white_2523948;
extern uint32_t nox_color_red_2589776;
extern uint32_t nox_color_blue_2650684;
extern uint32_t nox_color_green_2614268;
extern uint32_t nox_color_cyan_2649820;
extern uint32_t nox_color_yellow_2589772;
extern uint32_t nox_color_violet_2598268;
extern uint32_t nox_color_black_2650656;
extern uint32_t nox_color_orange_2614256;

const int nox_max_npcs = 1024;
nox_npc* npc_array;

extern nox_render_data_t* nox_draw_curDrawData_3799572;
extern nox_render_data_t obj_5D4594_3800716;

void* dword_5d4594_810640 = 0;

nox_list_item_t nox_gui_wol_servers_list = {0};

void nox_gui_winParentsReset_4A0CF0();
nox_window* nox_gui_winParentsTop_4A14F0();
nox_window* nox_gui_winParentsPop_4A18A0();
void nox_gui_winParentsPush_4A18C0(nox_window* win);

//----- (0048C580) --------------------------------------------------------
void sub_48C580(pixel8888* a1, int num) {
	unsigned int* pix = (unsigned int*)a1;
	for (int i = num - 1; i >= 0; i--) {
		unsigned int result = *pix;
		for (unsigned int* it = &pix[i]; it > pix; --it) {
			if (result > *it) {
				result = InterlockedExchange((volatile signed int*)it, result);
			}
		}
		*pix = result;
		++pix;
	}
}

//----- (0048C5E0) --------------------------------------------------------
int sub_48C5E0(int a1, int a2) {
	unsigned int v2; // eax
	int v3;          // ecx
	bool v4;         // tt

	v2 = *getMemU32Ptr(0x587000, 156212);
	v3 = 32;
	do {
		v4 = __CFSHL__(v2, 1);
		v2 = __ROL4__(v2, 1);
		if (v4) {
			v2 ^= 0xA0Au;
		}
		--v3;
	} while (v3);
	*getMemU32Ptr(0x587000, 156212) = v2;
	return a1 + (((unsigned int)(a2 - a1) * (unsigned long long)v2) >> 32);
}

//----- (0048C610) --------------------------------------------------------
short sub_48C610() {
	int v0;  // eax
	int v1;  // ecx
	bool v2; // tt

	v0 = *getMemU32Ptr(0x587000, 156216);
	v1 = 16;
	do {
		v2 = __CFSHL__(v0, 1);
		LOWORD(v0) = __ROL2__(v0, 1);
		if (v2) {
			v0 ^= 0xAu;
		}
		--v1;
	} while (v1);
	*getMemU32Ptr(0x587000, 156216) = v0;
	return v0;
}

//----- (0048C650) --------------------------------------------------------
uint32_t* sub_48C650(int a1, int a2, int a3, uint32_t* a4, uint32_t* a5) {
	int v5;           // eax
	uint32_t* result; // eax

	v5 = sub_48C5E0(a1, a2);
	sub_4AEDA0(&a2, &a1, v5, a3);
	*a4 += a2;
	result = a5;
	*a5 += a1;
	return result;
}

//----- (0048C690) --------------------------------------------------------
unsigned int sub_48C690(int a1, int a2, int a3, int a4) {
	return sub_48C730((a3 - a1) * (a3 - a1) + (a4 - a2) * (a4 - a2));
}

//----- (0048C6B0) --------------------------------------------------------
unsigned int sub_48C6B0(int a1, int a2) { return sub_48C730(a2 * a2 + a1 * a1); }

//----- (0048C730) --------------------------------------------------------
unsigned sub_48C730(unsigned int a1) {
	int result; // eax

	if (a1 < 0x10000) {
		if (a1 < 0x100) {
			if (a1 < 0x10) {
				if (a1 < 4) {
					result = getMemByte(0x587000, 155956 + 64 * a1) >> 7;
				} else {
					result = getMemByte(0x587000, 155956 + 16 * a1) >> 6;
				}
			} else if (a1 < 0x40) {
				result = getMemByte(0x587000, 155956 + 4 * a1) >> 5;
			} else {
				result = getMemByte(0x587000, 155956 + a1) >> 4;
			}
		} else if (a1 < 0x1000) {
			if (a1 < 0x400) {
				result = getMemByte(0x587000, 155956 + (a1 >> 2)) >> 3;
			} else {
				result = getMemByte(0x587000, 155956 + (a1 >> 4)) >> 2;
			}
		} else if (a1 < 0x4000) {
			result = getMemByte(0x587000, 155956 + (a1 >> 6)) >> 1;
		} else {
			result = getMemByte(0x587000, 155956 + (a1 >> 8));
		}
	} else if (a1 < 0x1000000) {
		if (a1 < 0x100000) {
			if (a1 < 0x40000) {
				result = getMemByte(0x587000, 155956 + (a1 >> 10)) << 1;
			} else {
				result = getMemByte(0x587000, 155956 + (a1 >> 12)) << 2;
			}
		} else if (a1 < 0x400000) {
			result = getMemByte(0x587000, 155956 + (a1 >> 14)) << 3;
		} else {
			result = getMemByte(0x587000, 155956 + (a1 >> 16)) << 4;
		}
	} else if (a1 < 0x10000000) {
		if (a1 < 0x4000000) {
			result = getMemByte(0x587000, 155956 + (a1 >> 18)) << 5;
		} else {
			result = getMemByte(0x587000, 155956 + (a1 >> 20)) << 6;
		}
	} else if (a1 < 0x40000000) {
		result = getMemByte(0x587000, 155956 + (a1 >> 22)) << 7;
	} else {
		result = (unsigned char)getMemByte(0x587000, 155956 + (a1 >> 24)) << 8;
	}
	return result;
}

//----- (0048CA70) --------------------------------------------------------
int nox_xxx_showObserverWindow_48CA70(int a1) { return nox_window_set_hidden(*(int*)&dword_5d4594_1193712, a1); }

//----- (0048CAD0) --------------------------------------------------------
int sub_48CAD0() {
	if (wndIsShown_nox_xxx_wndIsShown_46ACC0(*(int*)&dword_5d4594_1197312)) {
		return 0;
	}
	nox_xxx_wnd_46C6E0(*(int*)&dword_5d4594_1197312);
	nox_window_set_hidden(*(int*)&dword_5d4594_1197312, 1);
	return 1;
}

//----- (0048D000) --------------------------------------------------------
int sub_48D000() {
	uint32_t* v0; // eax

	v0 = nox_new_window_from_file("GuiKick.wnd", nox_xxx_guiKick_48D0A0);
	dword_5d4594_1197312 = v0;
	if (!v0) {
		return 0;
	}
	dword_5d4594_1197316 = nox_xxx_wndGetChildByID_46B0C0(v0, 4320);
	dword_5d4594_1197320 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1197312, 4321);
	nox_window_setPos_46A9B0(*(uint32_t**)&dword_5d4594_1197312,
							 (nox_win_width - *(int*)(dword_5d4594_1197312 + 8)) / 2,
							 *(uint32_t*)(dword_5d4594_1197312 + 20));
	nox_window_set_hidden(*(int*)&dword_5d4594_1197312, 1);
	dword_5d4594_1197324 = 0;
	dword_5d4594_1197328 = 0;
	dword_5d4594_1197332 = 0;
	dword_5d4594_1197336 = 0;
	return 1;
}

//----- (0048D0A0) --------------------------------------------------------
int nox_xxx_guiKick_48D0A0(int a1, int a2, int* a3, int a4) {
	int v4; // eax

	if (a2 != 16391) {
		return 0;
	}
	v4 = nox_xxx_wndGetID_46B0A0(a3) - 4311;
	if (v4) {
		if (v4 == 1) {
		LABEL_14:
			sub_48CAD0();
			goto LABEL_15;
		}
	} else {
		if (dword_5d4594_1197308 != 4) {
			if (dword_5d4594_1197308 == 2) {
				sub_48D340();
			} else {
				if (dword_5d4594_1197308 && dword_5d4594_1197308 != 1 && dword_5d4594_1197308 != 3) {
					goto LABEL_15;
				}
				sub_48D120();
			}
			goto LABEL_14;
		}
		sub_48D410();
	}
LABEL_15:
	nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
	return 1;
}

//----- (0048D120) --------------------------------------------------------
int sub_48D120() {
	int v0;             // ebp
	int* v1;            // eax
	int* v2;            // esi
	int i;              // eax
	const wchar_t* v4;  // eax
	wchar_t* v5;        // ebx
	int v6;             // esi
	const wchar_t* v7;  // edi
	int result;         // eax
	int v9;             // ebp
	wchar_t* v10;       // ebx
	int v11;            // esi
	const wchar_t* v12; // edi

	v0 = 0;
	dword_5d4594_1197328 = dword_5d4594_1197324;
	memcpy(getMemAt(0x5D4594, 1195512), getMemAt(0x5D4594, 1193720), 0x700u);
	dword_5d4594_1197324 = 0;
	v1 = (int*)nox_window_call_field_94(*(int*)&dword_5d4594_1197316, 16404, 0, 0);
	v2 = v1;
	for (i = *v1; i != -1; ++v2) {
		v4 = (const wchar_t*)nox_window_call_field_94(*(int*)&dword_5d4594_1197316, 16406, i, 0);
		if (v4) {
			nox_wcscpy((wchar_t*)getMemAt(0x5D4594, 1193720 + 56 * dword_5d4594_1197324), v4);
			++dword_5d4594_1197324;
		}
		i = v2[1];
	}
	if (*(int*)&dword_5d4594_1197328 > 0) {
		v5 = (wchar_t*)getMemAt(0x5D4594, 1195512);
		do {
			v6 = 0;
			if (*(int*)&dword_5d4594_1197324 <= 0) {
			LABEL_11:
				nox_xxx_voteSend_48D260(v5);
			} else {
				v7 = (const wchar_t*)getMemAt(0x5D4594, 1193720);
				while (nox_wcscmp(v5, v7)) {
					++v6;
					v7 += 28;
					if (v6 >= *(int*)&dword_5d4594_1197324) {
						goto LABEL_11;
					}
				}
			}
			++v0;
			v5 += 28;
		} while (v0 < *(int*)&dword_5d4594_1197328);
	}
	result = dword_5d4594_1197324;
	v9 = 0;
	if (*(int*)&dword_5d4594_1197324 > 0) {
		v10 = (wchar_t*)getMemAt(0x5D4594, 1193720);
		do {
			v11 = 0;
			if (*(int*)&dword_5d4594_1197328 <= 0) {
			LABEL_19:
				nox_xxx_netSendRenameMb_48D2D0(v10);
			} else {
				v12 = (const wchar_t*)getMemAt(0x5D4594, 1195512);
				while (nox_wcscmp(v10, v12)) {
					++v11;
					v12 += 28;
					if (v11 >= *(int*)&dword_5d4594_1197328) {
						goto LABEL_19;
					}
				}
			}
			result = dword_5d4594_1197324;
			++v9;
			v10 += 28;
		} while (v9 < *(int*)&dword_5d4594_1197324);
	}
	return result;
}

//----- (0048D260) --------------------------------------------------------
char* nox_xxx_voteSend_48D260(wchar_t* a1) {
	char* result; // eax
	int v2;       // esi
	char v3[52];  // [esp+8h] [ebp-34h]

	result = nox_common_playerInfoGetFirst_416EA0();
	v2 = (int)result;
	if (result) {
		while (nox_wcscmp((const wchar_t*)(v2 + 4704), a1)) {
			result = nox_common_playerInfoGetNext_416EE0(v2);
			v2 = (int)result;
			if (!result) {
				return result;
			}
		}
		*(uint16_t*)v3 = 750;
		nox_wcscpy((wchar_t*)&v3[2], a1);
		result = (char*)nox_netlist_addToMsgListCli_40EBC0(31, 0, v3, 52);
	}
	return result;
}

//----- (0048D2D0) --------------------------------------------------------
char* nox_xxx_netSendRenameMb_48D2D0(wchar_t* a1) {
	char* result; // eax
	int v2;       // esi
	char v3[52];  // [esp+8h] [ebp-34h]

	result = nox_common_playerInfoGetFirst_416EA0();
	v2 = (int)result;
	if (result) {
		while (nox_wcscmp((const wchar_t*)(v2 + 4704), a1)) {
			result = nox_common_playerInfoGetNext_416EE0(v2);
			v2 = (int)result;
			if (!result) {
				return result;
			}
		}
		*(uint16_t*)v3 = 238;
		nox_wcscpy((wchar_t*)&v3[2], a1);
		result = (char*)nox_netlist_addToMsgListCli_40EBC0(31, 0, v3, 52);
	}
	return result;
}

//----- (0048D340) --------------------------------------------------------
int sub_48D340() {
	int result; // eax

	if (nox_window_call_field_94(*(int*)&dword_5d4594_1197320, 16404, 0, 0)) {
		result = 0;
		dword_5d4594_1197332 = 0;
		if (dword_5d4594_1197336 == 1) {
			result = nox_xxx_clientVote_48D3E0();
			dword_5d4594_1197336 = dword_5d4594_1197332;
			return result;
		}
	} else {
		result = 1;
		dword_5d4594_1197332 = 1;
		if (!dword_5d4594_1197336) {
			result = sub_48D3B0();
			dword_5d4594_1197336 = dword_5d4594_1197332;
			return result;
		}
	}
	dword_5d4594_1197336 = result;
	return result;
}

//----- (0048D3B0) --------------------------------------------------------
int sub_48D3B0() {
	char v1[2]; // [esp+0h] [ebp-2h]

	v1[0] = -18;
	v1[1] = 4;
	return nox_xxx_netClientSend2_4E53C0(31, v1, 2, 0, 1);
}

//----- (0048D3E0) --------------------------------------------------------
int nox_xxx_clientVote_48D3E0() {
	char v1[2]; // [esp+0h] [ebp-2h]

	v1[0] = -18;
	v1[1] = 5;
	return nox_xxx_netClientSend2_4E53C0(31, v1, 2, 0, 1);
}

//----- (0048D410) --------------------------------------------------------
uint32_t* sub_48D410() {
	uint32_t* result; // eax

	result = (uint32_t*)nox_window_call_field_94(*(int*)&dword_5d4594_1197320, 16404, 0, 0);
	if (!result) {
		return sub_48CB10(2);
	}
	if (result == (uint32_t*)1) {
		result = sub_48CB10(3);
	}
	return result;
}

//----- (0048D450) --------------------------------------------------------
int sub_48D450() {
	int result; // eax

	nox_xxx_wnd_46C6E0(*(int*)&dword_5d4594_1197312);
	nox_xxx_wndClearCaptureMain_46ADE0(*(int*)&dword_5d4594_1197312);
	nox_xxx_windowDestroyMB_46C4E0(*(uint32_t**)&dword_5d4594_1197312);
	result = 0;
	dword_5d4594_1197312 = 0;
	dword_5d4594_1197316 = 0;
	dword_5d4594_1197320 = 0;
	dword_5d4594_1197324 = 0;
	dword_5d4594_1197328 = 0;
	dword_5d4594_1197332 = 0;
	dword_5d4594_1197336 = 0;
	return result;
}

//----- (0048D4A0) --------------------------------------------------------
int sub_48D4A0() {
	int result; // eax

	result = 0;
	dword_5d4594_1197332 = 0;
	dword_5d4594_1197336 = 0;
	return result;
}

//----- (0048D4B0) --------------------------------------------------------
int sub_48D4B0(int a1) {
	int result; // eax

	*getMemU32Ptr(0x5D4594, 1197304) = a1;
	if (a1 == 1) {
		result = sub_4C3460(0);
	} else {
		result = sub_4C3460(1);
	}
	return result;
}

//----- (0048D4F0) --------------------------------------------------------
int sub_48D4F0(unsigned short a1, unsigned short a2) {
	unsigned short v2; // cx

	v2 = 10000;
	if (a1 - 10000 < 0) {
		if (a2 >= 0xFFFF - (unsigned short)(10000 - a1)) {
			return 1;
		}
		v2 = a1;
	}
	return a2 < a1 && a2 >= a1 - v2;
}

//----- (0048D560) --------------------------------------------------------
int sub_48D560(unsigned short a1) {
	int* v1; // eax

	v1 = nox_common_list_getFirstSafe_425890(getMemIntPtr(0x5D4594, 1197340));
	if (!v1) {
		return 0;
	}
	while (v1[2] != a1) {
		v1 = nox_common_list_getNextSafe_4258A0(v1);
		if (!v1) {
			return 0;
		}
	}
	return 1;
}

//----- (0048D5A0) --------------------------------------------------------
uint32_t* sub_48D5A0(int a1) {
	uint32_t* result; // eax
	uint32_t* v2;     // ebx

	result = (uint32_t*)sub_48D4F0(*getMemU16Ptr(0x5D4594, 1197360), *(uint16_t*)(a1 + 1));
	if (!result) {
		result = (uint32_t*)sub_48D560(*(uint16_t*)(a1 + 1));
		if (!result) {
			result = calloc(*(unsigned char*)(a1 + 3) + 32, 1u);
			v2 = result;
			if (result) {
				sub_425770(result);
				v2[2] = *(unsigned short*)(a1 + 1);
				*((uint16_t*)v2 + 12) = *(unsigned char*)(a1 + 3);
				*((uint64_t*)v2 + 2) = nox_platform_get_ticks();
				memcpy(v2 + 8, (const void*)(a1 + 4), *(unsigned char*)(a1 + 3));
				if (*getMemU16Ptr(0x5D4594, 1197360) == *(uint16_t*)(a1 + 1)) {
					dword_5d4594_1197352 = v2;
				}
				result = (uint32_t*)sub_425790(getMemIntPtr(0x5D4594, 1197340), v2);
			}
		}
	}
	return result;
}

//----- (0048D660) --------------------------------------------------------
int sub_48D660() {
	unsigned long long v0; // rax
	int* v1;               // esi
	int* v2;               // edi

	LODWORD(v0) = dword_5d4594_1197352;
	if (!dword_5d4594_1197352) {
		if (dword_5d4594_1197356) {
			v0 = nox_platform_get_ticks() - *(uint64_t*)(dword_5d4594_1197356 + 16);
			if (v0 > 0x7530) {
				*getMemU16Ptr(0x5D4594, 1197360) = *(uint16_t*)(dword_5d4594_1197356 + 8);
				dword_5d4594_1197352 = dword_5d4594_1197356;
				LODWORD(v0) = nox_common_list_getNextSafe_4258A0(*(int**)&dword_5d4594_1197356);
				dword_5d4594_1197356 = v0;
			}
		}
	}
	v1 = *(int**)&dword_5d4594_1197352;
	if (dword_5d4594_1197352) {
		do {
			LODWORD(v0) = v1[2];
			if ((uint32_t)v0 != *getMemU16Ptr(0x5D4594, 1197360)) {
				break;
			}
			v2 = nox_common_list_getNextSafe_4258A0(v1);
			if (!v2) {
				v2 = nox_common_list_getFirstSafe_425890(getMemIntPtr(0x5D4594, 1197340));
				if (v2 == v1) {
					v2 = 0;
				}
			}
			nox_xxx_netOnPacketRecvCli_48EA70(31, (unsigned int)(v1 + 8), *((unsigned short*)v1 + 12));
			++*getMemU16Ptr(0x5D4594, 1197360);
			sub_425920((uint32_t**)v1);
			free(v1);
			v1 = v2;
		} while (v2);
	}
	dword_5d4594_1197356 = v1;
	dword_5d4594_1197352 = 0;
	return v0;
}

//----- (0048D740) --------------------------------------------------------
int sub_48D740() {
	int result; // eax

	nox_common_list_clear_425760(getMemAt(0x5D4594, 1197340));
	result = 0;
	dword_5d4594_1197352 = 0;
	dword_5d4594_1197356 = 0;
	*getMemU16Ptr(0x5D4594, 1197360) = 0;
	return result;
}

//----- (0048D760) --------------------------------------------------------
void sub_48D760() {
	int* v0; // esi
	int* v1; // edi

	v0 = nox_common_list_getFirstSafe_425890(getMemIntPtr(0x5D4594, 1197340));
	if (v0) {
		do {
			v1 = nox_common_list_getNextSafe_4258A0(v0);
			sub_425920((uint32_t**)v0);
			free(v0);
			v0 = v1;
		} while (v1);
	}
	nox_common_list_clear_425760(getMemAt(0x5D4594, 1197340));
	*getMemU16Ptr(0x5D4594, 1197360) = 0;
}

//----- (0048D7B0) --------------------------------------------------------
int* sub_48D7B0() {
	int* result; // eax

	for (result = nox_common_list_getFirstSafe_425890(getMemIntPtr(0x5D4594, 1197340)); result;
		 result = nox_common_list_getNextSafe_4258A0(result)) {
		;
	}
	return result;
}

//----- (0048D800) --------------------------------------------------------
int sub_48D800() {
	if (nox_alloc_chat_1197364) {
		nox_free_alloc_class(*(void**)&nox_alloc_chat_1197364);
	}
	nox_alloc_chat_1197364 = 0;
	*getMemU32Ptr(0x5D4594, 1197368) = 0;
	return 1;
}

//----- (0048D830) --------------------------------------------------------
int sub_48D830(nox_drawable* dr) {
	int a1 = dr;
	return nox_xxx_netCode2ChatBubble_48D850(*(uint32_t*)(a1 + 128)) != 0;
}

//----- (0048D850) --------------------------------------------------------
int nox_xxx_netCode2ChatBubble_48D850(int a1) {
	int result; // eax

	result = *getMemU32Ptr(0x5D4594, 1197368);
	if (!*getMemU32Ptr(0x5D4594, 1197368)) {
		return 0;
	}
	while (*(uint32_t*)(result + 656) != a1) {
		result = *(uint32_t*)(result + 684);
		if (!result) {
			return 0;
		}
	}
	return result;
}

//----- (0048D880) --------------------------------------------------------
wchar_t* nox_xxx_createTextBubble_48D880(int a1, wchar_t* a2) {
	wchar_t* v2;     // esi
	int v3;          // ebx
	wchar_t* result; // eax
	int v5;          // eax
	int v6;          // eax

	v2 = (wchar_t*)nox_xxx_netCode2ChatBubble_48D850(*(unsigned short*)(a1 + 1));
	if (v2) {
		v3 = 0;
	} else {
		result = (wchar_t*)nox_alloc_class_new_obj_zero(*(uint32_t**)&nox_alloc_chat_1197364);
		v2 = result;
		if (!result) {
			return result;
		}
		v3 = 1;
	}
	nox_wcscpy(v2, a2);
	*((uint32_t*)v2 + 159) = *(unsigned char*)(a1 + 8);
	*((uint32_t*)v2 + 161) = *(uint32_t*)(a1 + 4);
	*((uint32_t*)v2 + 164) = *(unsigned short*)(a1 + 1);
	if (*(uint16_t*)(a1 + 9)) {
		v6 = *(unsigned short*)(a1 + 9);
	} else {
		v5 = *((uint32_t*)v2 + 159) / 8;
		if (v5 >= 8) {
			v5 = 8;
		}
		v6 = nox_gameFPS * (v5 + 2);
	}
	result = (wchar_t*)(nox_frame_xxx_2598000 + v6);
	*((uint32_t*)v2 + 160) = result;
	if (v3) {
		result = *(wchar_t**)getMemAt(0x5D4594, 1197368);
		if (*getMemU32Ptr(0x5D4594, 1197368)) {
			result = *(wchar_t**)&dword_5d4594_1197372;
			*(uint32_t*)(dword_5d4594_1197372 + 684) = v2;
			*((uint32_t*)v2 + 172) = dword_5d4594_1197372;
			*((uint32_t*)v2 + 171) = 0;
			dword_5d4594_1197372 = v2;
		} else {
			*getMemU32Ptr(0x5D4594, 1197368) = v2;
			dword_5d4594_1197372 = v2;
			*((uint32_t*)v2 + 172) = 0;
			*((uint32_t*)v2 + 171) = 0;
		}
	}
	return result;
}

//----- (0048D990) --------------------------------------------------------
void sub_48D990(nox_draw_viewport_t* a1p) {
	uint32_t* a1 = a1p;
	int v1;        // ebx
	uint32_t* v2;  // esi
	int v3;        // eax
	uint32_t* v4;  // edi
	char* v5;      // eax
	char* v6;      // eax
	int* v7;       // eax
	int v8;        // edi
	int v9;        // eax
	int v10;       // eax
	int v11;       // ebp
	int v12;       // ebp
	int v13;       // esi
	int v14;       // ebp
	int v15;       // esi
	int v16;       // ebp
	int v18;       // [esp+Ch] [ebp-28h]
	int i;         // [esp+10h] [ebp-24h]
	uint16_t* v20; // [esp+14h] [ebp-20h]
	int v21;       // [esp+18h] [ebp-1Ch]
	int v22;       // [esp+1Ch] [ebp-18h]
	int v23;       // [esp+20h] [ebp-14h]
	int v24;       // [esp+24h] [ebp-10h]
	int v25;       // [esp+24h] [ebp-10h]
	int v26;       // [esp+24h] [ebp-10h]
	int v27;       // [esp+28h] [ebp-Ch]
	int v28;       // [esp+28h] [ebp-Ch]
	int v29;       // [esp+2Ch] [ebp-8h]
	int v30;       // [esp+38h] [ebp+4h]

	v22 = nox_xxx_guiFontHeightMB_43F320(0);
	v1 = v22 / 2;
	sub_437260();
	sub_48DCF0(a1);
	v2 = *(uint32_t**)getMemAt(0x5D4594, 1197368);
	v30 = *getMemU32Ptr(0x5D4594, 1197368);
	if (!*getMemU32Ptr(0x5D4594, 1197368)) {
		sub_437290();
		return;
	}
	while (1) {
		if (v2[165]) {
			v3 = v2[167];
			v21 = nox_color_white_2523948;
			v20 = 0;
			if (v3 && *(uint8_t*)(v3 + 112) & 4) {
				v4 = nox_xxx_objGetTeamByNetCode_418C80(*(uint32_t*)(v3 + 128));
				v5 = nox_common_playerInfoGetByID_417040(v2[164]);
				if (v5) {
					v20 = v5 + 4704;
				}
				if (v4) {
					v6 = nox_xxx_clientGetTeamColor_418AB0(*((unsigned char*)v4 + 4));
					if (v6) {
						v7 = (int*)nox_xxx_materialGetTeamColor_418D50((int)v6);
						if (v7) {
							v21 = *v7;
						}
					}
				}
			}
			v8 = v2[162];
			v18 = v2[163];
			for (i = 0; i < 2; ++i) {
				if (i) {
					v9 = *getMemU32Ptr(0x85B3FC, 956);
					--v8;
					--v18;
				} else {
					v9 = *getMemU32Ptr(0x852978, 4);
				}
				nox_client_drawSetColor_434460(v9);
				v23 = v8 - v1;
				nox_client_drawAddPoint_49F500(v8, v18 - v1);
				nox_client_drawAddPoint_49F500(v8 - v1, v18);
				nox_client_drawLineFromPoints_49E4B0();
				v10 = *(uint32_t*)(v30 + 672);
				v11 = v10 + v8;
				v24 = v10 + v8;
				nox_client_drawAddPoint_49F500(v8, v18 - v1);
				nox_client_drawAddPoint_49F500(v11, v18 - v1);
				nox_client_drawLineFromPoints_49E4B0();
				v12 = v1 + v11;
				nox_client_drawAddPoint_49F500(v12, v18);
				nox_client_drawAddPoint_49F500(v24, v18 - v1);
				nox_client_drawLineFromPoints_49E4B0();
				v25 = v12;
				v27 = v18 + *(uint32_t*)(v30 + 676);
				nox_client_drawAddPoint_49F500(v12, v18);
				nox_client_drawAddPoint_49F500(v12, v27);
				nox_client_drawLineFromPoints_49E4B0();
				v13 = v1 + v27;
				v14 = v12 - v1;
				nox_client_drawAddPoint_49F500(v14, v1 + v27);
				nox_client_drawAddPoint_49F500(v25, v27);
				nox_client_drawLineFromPoints_49E4B0();
				if (*(uint32_t*)(v30 + 664)) {
					v28 = v1 + v27;
					v26 = v1 + v8 + *(int*)(v30 + 672) / 2;
					nox_client_drawAddPoint_49F500(v14, v13);
					nox_client_drawAddPoint_49F500(v26, v13);
					nox_client_drawLineFromPoints_49E4B0();
					v15 = v22 + v13;
					v29 = v8 + *(int*)(v30 + 672) / 2;
					nox_client_drawAddPoint_49F500(v29, v15);
					nox_client_drawAddPoint_49F500(v26, v28);
					nox_client_drawLineFromPoints_49E4B0();
					v16 = v8 + *(int*)(v30 + 672) / 2 - v1;
					nox_client_drawAddPoint_49F500(v29, v15);
					v13 = v28;
					nox_client_drawAddPoint_49F500(v16, v28);
					nox_client_drawLineFromPoints_49E4B0();
					nox_client_drawAddPoint_49F500(v8, v28);
					nox_client_drawAddPoint_49F500(v16, v28);
				} else {
					nox_client_drawAddPoint_49F500(v8, v13);
					nox_client_drawAddPoint_49F500(v14, v13);
				}
				nox_client_drawLineFromPoints_49E4B0();
				nox_client_drawAddPoint_49F500(v8, v13);
				nox_client_drawAddPoint_49F500(v23, v13 - v1);
				nox_client_drawLineFromPoints_49E4B0();
				nox_client_drawAddPoint_49F500(v23, v13 - v1 - *(uint32_t*)(v30 + 676));
				nox_client_drawAddPoint_49F500(v23, v13 - v1);
				nox_client_drawLineFromPoints_49E4B0();
			}
			nox_xxx_drawSetTextColor_434390(nox_color_white_2523948);
			nox_xxx_drawSetColor_4343E0(*getMemIntPtr(0x852978, 4));
			nox_xxx_drawStringWrapHL_43FD00(0, (uint16_t*)v30, v8, v18, 128, 0);
			if (v20) {
				nox_xxx_drawSetTextColor_434390(v21);
				nox_xxx_drawStringWrapHL_43FD00(0, v20, v8, v18 - v22 - 1, 128, 0);
			}
			v2 = (uint32_t*)v30;
		}
		v30 = v2[171];
		if (!v30) {
			break;
		}
		v2 = (uint32_t*)v2[171];
	}
	sub_437290();
}

//----- (0048DCF0) --------------------------------------------------------
void sub_48DCF0(uint32_t* a1) {
	int v1;             // eax
	int v2;             // esi
	uint32_t* v3;       // ebx
	int v4;             // eax
	unsigned int v5;    // edx
	int v6;             // ecx
	int v7;             // eax
	uint32_t* v8;       // eax
	int v9;             // eax
	unsigned short v10; // dx
	int* v11;           // ebp
	int v12;            // edx
	uint32_t* v13;      // edi
	int v14;            // eax
	int v15;            // eax
	int v16;            // eax
	int v17;            // ecx
	int v18;            // eax
	int v19;            // eax
	int v20;            // ecx
	int v21;            // eax
	int v22;            // eax
	int v23;            // eax
	int v24;            // [esp+8h] [ebp-18h]
	int v25;            // [esp+Ch] [ebp-14h]
	int4 a1a;           // [esp+10h] [ebp-10h]
	int v27;            // [esp+24h] [ebp+4h]

	v1 = nox_xxx_guiFontHeightMB_43F320(0);
	v2 = *getMemU32Ptr(0x5D4594, 1197368);
	v3 = a1;
	v24 = v1;
	v4 = 0;
	if (*getMemU32Ptr(0x5D4594, 1197368)) {
		while (1) {
			v5 = *(uint32_t*)(v2 + 656);
			v6 = *(uint32_t*)(v2 + 684);
			*(uint32_t*)(v2 + 680) = v4;
			v25 = v6;
			v27 = v4 + 1;
			*(uint32_t*)(v2 + 668) = 0;
			if (nox_xxx_netTestHighBit_578B70(v5)) {
				v7 = nox_xxx_netClearHighBit_578B30(*(uint32_t*)(v2 + 656));
				v8 = nox_xxx_netSpriteByCodeStatic_45A720(v7);
			} else {
				v9 = nox_xxx_netClearHighBit_578B30(*(uint32_t*)(v2 + 656));
				v8 = nox_xxx_netSpriteByCodeDynamic_45A6F0(v9);
			}
			*(uint32_t*)(v2 + 668) = v8;
			if (v8) {
				*(uint16_t*)(v2 + 644) = *((uint16_t*)v8 + 6);
				*(uint16_t*)(v2 + 646) = *((uint16_t*)v8 + 8);
			}
			v10 = *(uint16_t*)(v2 + 646);
			v11 = (uint32_t*)(v2 + 672);
			*(uint32_t*)(v2 + 648) = *v3 + *(unsigned short*)(v2 + 644) - v3[4];
			*(uint32_t*)(v2 + 652) = v3[1] + v10 - v3[5];
			nox_xxx_drawGetStringSize_43F840(0, (unsigned short*)v2, (int*)(v2 + 672), (uint32_t*)(v2 + 676), 128);
			if (*(uint32_t*)(v2 + 672) > 128) {
				*v11 = 128;
			}
			v12 = *(uint32_t*)(v2 + 676);
			*(uint32_t*)(v2 + 648) += *v11 / -2;
			v13 = (uint32_t*)(v2 + 664);
			*(uint32_t*)(v2 + 652) += -64 - v12;
			*(uint32_t*)(v2 + 660) = 1;
			*(uint32_t*)(v2 + 664) = 1;
			if (nox_common_gameFlags_check_40A5C0(2048)) {
				v14 = *(uint32_t*)(v2 + 648);
				if (v14 < *v3 || v14 > v3[2] || (v15 = *(uint32_t*)(v2 + 652) - 64, v15 < v3[1]) || v15 > v3[3]) {
					*(uint32_t*)(v2 + 660) = 0;
					*v13 = 0;
				}
			}
			if (*(uint32_t*)(v2 + 660)) {
				break;
			}
		LABEL_27:
			if (nox_frame_xxx_2598000 > *(int*)(v2 + 640)) {
				v22 = *(uint32_t*)(v2 + 688);
				if (v22) {
					*(uint32_t*)(v22 + 684) = *(uint32_t*)(v2 + 684);
				} else {
					*getMemU32Ptr(0x5D4594, 1197368) = *(uint32_t*)(v2 + 684);
				}
				v23 = *(uint32_t*)(v2 + 684);
				if (v23) {
					*(uint32_t*)(v23 + 688) = *(uint32_t*)(v2 + 688);
				} else {
					dword_5d4594_1197372 = *(uint32_t*)(v2 + 688);
				}
				nox_alloc_class_free_obj_first(*(unsigned int**)&nox_alloc_chat_1197364, (uint64_t*)v2);
			}
			v2 = v25;
			if (!v25) {
				v2 = *getMemU32Ptr(0x5D4594, 1197368);
				goto LABEL_37;
			}
			v4 = v27;
		}
		v16 = *v3 + v24;
		v17 = *(uint32_t*)(v2 + 648);
		if (v17 >= v16) {
			v18 = v3[2];
			if (v24 + v17 + *v11 <= v18) {
				goto LABEL_22;
			}
			v16 = v18 - *v11 - v24;
		}
		*(uint32_t*)(v2 + 648) = v16;
		*v13 = 0;
	LABEL_22:
		v19 = v3[1] + 2 * v24 + 2;
		v20 = *(uint32_t*)(v2 + 652);
		if (v20 >= v19) {
			v21 = v3[3];
			if (v24 + *(uint32_t*)(v2 + 676) + v20 <= v21) {
			LABEL_26:
				a1a.field_0 = *(uint32_t*)(v2 + 648);
				a1a.field_4 = *(uint32_t*)(v2 + 652);
				a1a.field_8 = *(uint32_t*)(v2 + 648) + *v11;
				a1a.field_C = *(uint32_t*)(v2 + 676) + *(uint32_t*)(v2 + 652);
				sub_48E000(&a1a, (uint32_t*)(v2 + 664));
				*(uint32_t*)(v2 + 648) = a1a.field_0;
				*(uint32_t*)(v2 + 652) = a1a.field_4;
				goto LABEL_27;
			}
			v19 = v21 - *(uint32_t*)(v2 + 676) - v24;
		}
		*(uint32_t*)(v2 + 652) = v19;
		*v13 = 0;
		goto LABEL_26;
	}
LABEL_37:
	while (v2) {
		sub_48E240((int)v3, (uint32_t*)v2);
		v2 = *(uint32_t*)(v2 + 684);
	}
}
// 48DD5E: variable 'v7' is possibly undefined
// 48DD72: variable 'v9' is possibly undefined

//----- (0048E000) --------------------------------------------------------
bool sub_48E000(int4* a1, uint32_t* a2) {
	int v2;   // ebx
	int v3;   // eax
	int v4;   // eax
	int v5;   // eax
	int v6;   // eax
	int v7;   // eax
	int v8;   // eax
	int v9;   // eax
	int4 v11; // [esp+10h] [ebp-10h]

	if (a1->field_0 < 0 || a1->field_4 < 0 || a1->field_8 > nox_win_width || a1->field_C > nox_win_height) {
		*a2 = 0;
	}
	v11.field_0 = 0;
	v11.field_4 = 0;
	v11.field_8 = 563;
	if (sub_467C80()) {
		v2 = 279;
		v11.field_C = 279;
		v3 = nox_xxx_pointInRect_4281F0((int2*)a1, &v11);
		if (v3 || (v3 = nox_xxx_pointInRect_4281F0((int2*)&a1->field_8, &v11), v3)) {
		LABEL_12:
			a1->field_4 = v2;
			*a2 = 0;
			goto LABEL_13;
		}
	} else {
		v2 = 55;
		v11.field_C = 55;
		v3 = nox_xxx_pointInRect_4281F0((int2*)a1, &v11);
		if (v3) {
			goto LABEL_12;
		}
		v3 = nox_xxx_pointInRect_4281F0((int2*)&a1->field_8, &v11);
		if (v3) {
			goto LABEL_12;
		}
	}
LABEL_13:
	if (nox_client_renderGUI_80828) {
		v11.field_0 = 0;
		v11.field_C = nox_win_height;
		v11.field_8 = 111;
		v11.field_4 = nox_win_height - 127;
		v4 = nox_xxx_pointInRect_4281F0((int2*)a1, &v11);
		if (v4 || (v5 = nox_xxx_pointInRect_4281F0((int2*)&a1->field_8, &v11), v5)) {
			a1->field_4 += v11.field_4 - a1->field_C;
			*a2 = 0;
		}
		v11.field_4 = nox_win_height - 74;
		v11.field_0 = nox_win_width / 2 - 160;
		v11.field_8 = v11.field_0 + 320;
		v11.field_C = nox_win_height;
		v6 = nox_xxx_pointInRect_4281F0((int2*)a1, &v11);
		if (v6 || (v7 = nox_xxx_pointInRect_4281F0((int2*)&a1->field_8, &v11), v7)) {
			a1->field_4 += v11.field_4 - a1->field_C;
			*a2 = 0;
		}
		v11.field_8 = nox_win_width;
		v11.field_0 = nox_win_width - 91;
		v11.field_C = nox_win_height;
		v11.field_4 = nox_win_height - 201;
		v8 = nox_xxx_pointInRect_4281F0((int2*)a1, &v11);
		if (v8 || (v9 = nox_xxx_pointInRect_4281F0((int2*)&a1->field_8, &v11), v9)) {
			a1->field_4 += v11.field_4 - a1->field_C;
			*a2 = 0;
		}
		v3 = sub_4C3260();
		if (v3) {
			v11.field_0 = nox_win_width - 87;
			v11.field_4 = 0;
			v11.field_8 = nox_win_width;
			v11.field_C = 145;
			v3 = nox_xxx_pointInRect_4281F0((int2*)a1, &v11);
			if (v3 || (v3 = nox_xxx_pointInRect_4281F0((int2*)&a1->field_8, &v11), v3)) {
				a1->field_4 = 145;
				*a2 = 0;
			}
		}
	}
	return v3;
}
// 48E069: variable 'v3' is possibly undefined
// 48E0EF: variable 'v4' is possibly undefined
// 48E104: variable 'v5' is possibly undefined
// 48E156: variable 'v6' is possibly undefined
// 48E16B: variable 'v7' is possibly undefined
// 48E1B4: variable 'v8' is possibly undefined
// 48E1C9: variable 'v9' is possibly undefined

//----- (0048E240) --------------------------------------------------------
char sub_48E240(int a1, uint32_t* a2) {
	int v2;       // eax
	uint32_t* v3; // esi
	int v4;       // edi
	uint32_t* v5; // ebp
	char v6;      // bl
	int v7;       // edi
	int v8;       // edx
	int v9;       // edi
	int v10;      // edx
	int v12;      // [esp+Ch] [ebp-Ch]
	int v13;      // [esp+10h] [ebp-8h]
	int v14;      // [esp+14h] [ebp-4h]
	char v15;     // [esp+20h] [ebp+8h]

	LOBYTE(v2) = getMemByte(0x5D4594, 1197368);
	v3 = a2;
	if (a2 != *(uint32_t**)getMemAt(0x5D4594, 1197368)) {
		v4 = 0;
		v5 = *(uint32_t**)getMemAt(0x5D4594, 1197368);
		if (*getMemU32Ptr(0x5D4594, 1197368)) {
			while (1) {
				v2 = v5[165];
				if (v2) {
					v2 = v5[170];
					if (v2 >= a2[170]) {
						goto LABEL_9;
					}
					v2 = sub_48E480(a2, v5);
					if (v2) {
						break;
					}
				}
				v5 = (uint32_t*)v5[171];
				if (!v5) {
					return v2;
				}
			}
			v4 = 1;
		LABEL_9:
			if (v5 && v4) {
				v6 = 0;
				v15 = 0;
				switch (sub_48E530(v3[162] + v3[168] / 2, v3[163] + v3[169] / 2)) {
				case 17:
					v6 = -96;
					v15 = 8;
					break;
				case 18:
					v6 = 48;
					v15 = -118;
					break;
				case 20:
					v6 = -112;
					v15 = 2;
					break;
				case 33:
					v6 = -64;
					v15 = 44;
					break;
				case 34:
					v6 = -16;
					v15 = 15;
					break;
				case 36:
					v6 = -64;
					v15 = 19;
					break;
				case 65:
					v6 = 96;
					v15 = 4;
					break;
				case 66:
					v6 = 48;
					v15 = 69;
					break;
				case 68:
					v6 = 80;
					v15 = 1;
					break;
				default:
					break;
				}
				v7 = 0;
				while (1) {
					LOBYTE(v2) = 1 << v7;
					LOBYTE(v14) = 1 << v7;
					if ((unsigned char)(1 << v7) & (unsigned char)v6) {
						sub_48E6A0(v14, v3, v5, &v12, &v13);
						v2 = sub_48E5C0(v3, v12, v13);
						if (v2) {
							break;
						}
					}
					if (++v7 >= 8) {
						goto LABEL_27;
					}
				}
				v8 = v13;
				v3[162] = v12;
				v3[163] = v8;
			LABEL_27:
				if (v7 == 8) {
					v9 = 0;
					while (1) {
						LOBYTE(v2) = 1 << v9;
						LOBYTE(v14) = 1 << v9;
						if ((unsigned char)(1 << v9) & (unsigned char)v15) {
							sub_48E6A0(v14, v3, v5, &v12, &v13);
							v2 = sub_48E5C0(v3, v12, v13);
							if (v2) {
								break;
							}
						}
						if (++v9 >= 8) {
							return v2;
						}
					}
					v10 = v13;
					v3[162] = v12;
					v3[163] = v10;
				}
			}
		}
	}
	return v2;
}

//----- (0048E480) --------------------------------------------------------
int sub_48E480(uint32_t* a1, uint32_t* a2) {
	int v2; // eax
	int v3; // esi
	int v4; // edx
	int v5; // ebx
	int v7; // [esp+24h] [ebp-Ch]
	int v8; // [esp+34h] [ebp+4h]

	v2 = nox_xxx_guiFontHeightMB_43F320(0);
	v3 = a1[162];
	v7 = a1[163] - v2;
	v4 = v2 + v3 + a1[168];
	v5 = v2 + a1[163] + a1[169];
	v8 = a2[163];
	return v3 - v2 < v2 + a2[162] + a2[168] && v4 > a2[162] - v2 && v7 < v2 + v8 + a2[169] && v5 > v8 - v2;
}

//----- (0048E530) --------------------------------------------------------
int sub_48E530(int a1, int a2) {
	int v2; // edi
	int v3; // eax

	if (a1 >= nox_win_width / 3) {
		v3 = (a1 >= 2 * nox_win_width / 3) - 1;
		LOBYTE(v3) = v3 & 0xE0;
		v2 = v3 + 64;
	} else {
		v2 = 16;
	}
	if (a2 < nox_win_height / 3) {
		return v2 | 1;
	}
	if (a2 >= 2 * nox_win_height / 3) {
		return v2 | 4;
	}
	return v2 | 2;
}

//----- (0048E5C0) --------------------------------------------------------
int sub_48E5C0(uint32_t* a1, int a2, int a3) {
	int v3;       // edx
	int v4;       // eax
	uint32_t* v6; // edi
	int v7;       // ebx
	int v8;       // ebp
	int v9;       // eax
	int a2a;      // [esp+10h] [ebp-14h]
	int4 a1a;     // [esp+14h] [ebp-10h]

	a2a = 1;
	nox_xxx_guiFontHeightMB_43F320(0);
	a1a.field_0 = a2;
	v3 = a1[168];
	a1a.field_4 = a3;
	v4 = a3 + a1[169];
	a1a.field_8 = a2 + v3;
	a1a.field_C = v4;
	sub_48E000(&a1a, &a2a);
	if (!a2a) {
		return 0;
	}
	v6 = *(uint32_t**)getMemAt(0x5D4594, 1197368);
	if (*getMemU32Ptr(0x5D4594, 1197368)) {
		while (1) {
			if (a1[165]) {
				if (v6[170] >= a1[170]) {
					return 1;
				}
				v7 = a1[162];
				v8 = a1[163];
				a1[162] = a2;
				a1[163] = a3;
				v9 = sub_48E480(a1, v6);
				a2a = v9;
				a1[162] = v7;
				a1[163] = v8;
				if (v9) {
					break;
				}
			}
			v6 = (uint32_t*)v6[171];
			if (!v6) {
				return 1;
			}
		}
		return 0;
	}
	return 1;
}

//----- (0048E6A0) --------------------------------------------------------
int* sub_48E6A0(char a1, uint32_t* a2, uint32_t* a3, int* a4, int* a5) {
	int* result;  // eax
	int v6;       // ecx
	uint32_t* v7; // ecx
	int v8;       // edx
	char* v9;     // edx
	int v10;      // edx

	result = (int*)(2 * nox_xxx_guiFontHeightMB_43F320(0));
	switch ((unsigned char)a1) {
	case 1:
		*a4 = a3[162] - a2[168] - (uint32_t)result;
		*a5 = a3[163] - a2[169] - (uint32_t)result;
		return result;
	case 2:
		*a4 = (int)result + a3[162] + a3[168];
		v6 = a3[163] - a2[169] - (uint32_t)result;
		result = a5;
		*a5 = v6;
		return result;
	case 4:
		v7 = a3;
		*a4 = a3[162] - a2[168] - (uint32_t)result;
		goto LABEL_8;
	case 8:
		v7 = a3;
		*a4 = (int)result + a3[162] + a3[168];
		goto LABEL_8;
	case 0x10:
		*a4 = a2[162];
		v8 = a3[163] - a2[169] - (uint32_t)result;
		result = a5;
		*a5 = v8;
		return result;
	case 0x20:
		*a4 = a2[162];
		v7 = a3;
	LABEL_8:
		v9 = (char*)result + v7[163] + v7[169];
		result = a5;
		*a5 = (int)v9;
		break;
	case 0x40:
		v10 = a3[162] - a2[168] - (uint32_t)result;
		result = a4;
		*a4 = v10;
		*a5 = a2[163];
		break;
	case 0x80:
		*a4 = (int)result + a3[162] + a3[168];
		result = a5;
		*a5 = a2[163];
		break;
	default:
		return result;
	}
	return result;
}

//----- (0048E8E0) --------------------------------------------------------
void sub_48E8E0(int a1) {
	int v1; // eax
	int v2; // ecx
	int v3; // ecx

	v1 = nox_xxx_netCode2ChatBubble_48D850(a1);
	if (v1) {
		v2 = *(uint32_t*)(v1 + 688);
		if (v2) {
			*(uint32_t*)(v2 + 684) = *(uint32_t*)(v1 + 684);
		} else {
			*getMemU32Ptr(0x5D4594, 1197368) = *(uint32_t*)(v1 + 684);
		}
		v3 = *(uint32_t*)(v1 + 684);
		if (v3) {
			*(uint32_t*)(v3 + 688) = *(uint32_t*)(v1 + 688);
		}
		nox_alloc_class_free_obj_first(*(unsigned int**)&nox_alloc_chat_1197364, (uint64_t*)v1);
	}
}

//----- (0048E940) --------------------------------------------------------
void sub_48E940() {
	nox_alloc_class_free_all(*(uint32_t**)&nox_alloc_chat_1197364);
	*getMemU32Ptr(0x5D4594, 1197368) = 0;
}

//----- (0048E970) --------------------------------------------------------
uint32_t* nox_xxx_spriteCreate_48E970(int a1, unsigned int a2, int a3, int a4) {
	int v4;       // eax
	int v5;       // ebx
	uint32_t* v6; // eax
	uint32_t* v7; // esi
	int v8;       // eax
	int v10;      // [esp-4h] [ebp-10h]

	v4 = nox_xxx_netClearHighBit_578B30(a2);
	v5 = v4;
	v10 = v4;
	if (nox_xxx_netTestHighBit_578B70(a2)) {
		v6 = nox_xxx_netSpriteByCodeStatic_45A720(v10);
	} else {
		v6 = nox_xxx_netSpriteByCodeDynamic_45A6F0(v10);
	}
	v7 = v6;
	if (v6) {
		nox_xxx_updateSpritePosition_49AA90(v6, a3, a4);
	} else {
		if (!*getMemU32Ptr(0x5D4594, 1200836)) {
			*getMemU32Ptr(0x5D4594, 1200836) = nox_xxx_getTTByNameSpriteMB_44CFC0("Crown");
		}
		if (!*getMemU32Ptr(0x5D4594, 1200840)) {
			*getMemU32Ptr(0x5D4594, 1200840) = nox_xxx_getTTByNameSpriteMB_44CFC0("GameBall");
		}
		v8 = nox_xxx_spriteLoadAdd_45A360_drawable(a1, a3, a4);
		v7 = (uint32_t*)v8;
		if (!v8) {
			nox_xxx_spriteLoadError_4356E0();
			return 0;
		}
		*(uint32_t*)(v8 + 128) = v5;
		if (a1 == *getMemU32Ptr(0x5D4594, 1200836) || a1 == *getMemU32Ptr(0x5D4594, 1200840) ||
			*(uint32_t*)(v8 + 112) & 0x10000000) {
			sub_459DD0(v8, 1);
		}
	}
	nox_xxx_spriteSetActiveMB_45A990_drawable((int)v7);
	nox_xxx_sprite_49BA10(v7);
	v7[80] = nox_frame_xxx_2598000;
	v7[122] = 0;
	return v7;
}
// 48E97E: variable 'v4' is possibly undefined

// 48EC64: variable 'v16' is possibly undefined
// 48ECC4: variable 'v18' is possibly undefined
// 48ED16: variable 'v20' is possibly undefined
// 48EDD6: variable 'v24' is possibly undefined
// 48F160: variable 'v31' is possibly undefined
// 48F596: variable 'v40' is possibly undefined
// 48F671: variable 'v42' is possibly undefined
// 48F6EB: variable 'v44' is possibly undefined
// 48F793: variable 'v49' is possibly undefined
// 48F831: variable 'v54' is possibly undefined
// 48F929: variable 'v57' is possibly undefined
// 48F952: variable 'v59' is possibly undefined
// 48FAB0: variable 'v62' is possibly undefined
// 48FB1E: variable 'v64' is possibly undefined
// 48FD0B: variable 'v69' is possibly undefined
// 48FDA2: variable 'v71' is possibly undefined
// 48FE68: variable 'v77' is possibly undefined
// 48FEFD: variable 'v82' is possibly undefined
// 48FF39: variable 'k' is possibly undefined
// 48FF58: variable 'v84' is possibly undefined
// 49008E: variable 'v88' is possibly undefined
// 490118: variable 'v90' is possibly undefined
// 490281: variable 'v92' is possibly undefined
// 4902D3: variable 'v94' is possibly undefined
// 490334: variable 'v96' is possibly undefined
// 490394: variable 'v98' is possibly undefined
// 4904D6: variable 'v103' is possibly undefined
// 49056F: variable 'v105' is possibly undefined
// 49060D: variable 'v109' is possibly undefined
// 49096A: variable 'v120' is possibly undefined
// 4909AC: variable 'v122' is possibly undefined
// 4909ED: variable 'v124' is possibly undefined
// 490AC3: variable 'v129' is possibly undefined
// 490B3C: variable 'v132' is possibly undefined
// 490C1D: variable 'v137' is possibly undefined
// 490CFC: variable 'v140' is possibly undefined
// 490FE2: variable 'v152' is possibly undefined
// 491687: variable 'v178' is possibly undefined
// 4916D9: variable 'v180' is possibly undefined
// 491710: variable 'v5' is possibly undefined
// 49172D: variable 'v182' is possibly undefined
// 491768: variable 'v184' is possibly undefined
// 49180F: variable 'v189' is possibly undefined
// 49187C: variable 'v193' is possibly undefined
// 4918F3: variable 'v196' is possibly undefined
// 491AA8: variable 'v198' is possibly undefined
// 491D48: variable 'v209' is possibly undefined
// 491EEA: variable 'v214' is possibly undefined
// 49252B: variable 'v236' is possibly undefined
// 49308F: variable 'v274' is possibly undefined
// 493335: variable 'v281' is possibly undefined
// 493364: variable 'v283' is possibly undefined
// 493378: variable 'v284' is possibly undefined
// 493639: variable 'v291' is possibly undefined
// 493696: variable 'v293' is possibly undefined
// 4936AF: variable 'v294' is possibly undefined
// 4939A7: variable 'v297' is possibly undefined
// 467460: using guessed type int nox_xxx_j_inventoryNameSignInit_467460(void);

//----- (004947E0) --------------------------------------------------------
char* sub_4947E0(int a1) {
	short v1;     // ax
	int v2;       // edi
	char* result; // eax
	int i;        // esi

	if (nox_common_gameFlags_check_40A5C0(1)) {
		v1 = nox_common_gameFlags_getVal_40A5B0();
		v2 = (unsigned short)nox_xxx_servGamedataGet_40A020(v1);
	} else {
		v2 = *((unsigned short*)nox_xxx_cliGamedataGet_416590(0) + 27);
	}
	result = nox_common_playerInfoGetFirst_416EA0();
	for (i = (int)result; result; i = (int)result) {
		if (!(*(uint8_t*)(i + 3680) & 1)) {
			if (i == a1) {
				if (nox_common_gameFlags_check_40A5C0(1024)) {
					if (*(uint32_t*)(i + 2140) >= v2) {
						*(uint32_t*)(i + 2140) = v2 - 1;
					}
				} else {
					*(uint32_t*)(i + 2136) = v2;
				}
			} else if (nox_common_gameFlags_check_40A5C0(1024)) {
				if (*(uint32_t*)(i + 2140) < v2) {
					*(uint32_t*)(i + 2140) = v2;
				}
			} else if (*(uint32_t*)(i + 2136) >= v2) {
				*(uint32_t*)(i + 2136) = v2 - 1;
			}
		}
		result = nox_common_playerInfoGetNext_416EE0(i);
	}
	return result;
}

//----- (004948B0) --------------------------------------------------------
int sub_4948B0(int a1) {
	short v1;   // ax
	int v2;     // edi
	char* i;    // esi
	int result; // eax
	int j;      // ebp
	char* v6;   // eax
	char* v7;   // esi
	int k;      // ebp
	char* v9;   // eax
	char* v10;  // esi

	if (nox_common_gameFlags_check_40A5C0(1)) {
		v1 = nox_common_gameFlags_getVal_40A5B0();
		v2 = (unsigned short)nox_xxx_servGamedataGet_40A020(v1);
	} else {
		v2 = *((unsigned short*)nox_xxx_cliGamedataGet_416590(0) + 27);
	}
	for (i = nox_server_teamFirst_418B10(); i; i = nox_server_teamNext_418B60((int)i)) {
		if (i == (char*)a1) {
			if (!nox_common_gameFlags_check_40A5C0(1024)) {
				*((uint32_t*)i + 13) = v2;
			}
		} else if (!nox_common_gameFlags_check_40A5C0(1024) && *((uint32_t*)i + 13) >= v2) {
			*((uint32_t*)i + 13) = v2 - 1;
		}
	}
	if (nox_common_gameFlags_check_40A5C0(1)) {
		result = nox_xxx_getFirstPlayerUnit_4DA7C0();
		for (j = result; result; j = result) {
			if (!nox_xxx_teamCompare2_419180(j + 48, *(uint8_t*)(a1 + 57))) {
				v6 = nox_common_playerInfoGetByID_417040(*(uint32_t*)(j + 36));
				v7 = v6;
				if (v6) {
					if (!(v6[3680] & 1)) {
						if (nox_common_gameFlags_check_40A5C0(1024)) {
							if (*((uint32_t*)v7 + 535) < v2) {
								*((uint32_t*)v7 + 535) = v2;
							}
						} else if (*((uint32_t*)v7 + 534) >= v2) {
							*((uint32_t*)v7 + 534) = v2 - 1;
						}
					}
				}
			}
			result = nox_xxx_getNextPlayerUnit_4DA7F0(j);
		}
	} else {
		result = nox_xxx_cliGetSpritePlayer_45A000();
		for (k = result; result; k = result) {
			if (!nox_xxx_teamCompare2_419180(k + 24, *(uint8_t*)(a1 + 57))) {
				v9 = nox_common_playerInfoGetByID_417040(*(uint32_t*)(k + 128));
				v10 = v9;
				if (v9) {
					if (!(v9[3680] & 1)) {
						if (nox_common_gameFlags_check_40A5C0(1024)) {
							if (*((uint32_t*)v10 + 535) < v2) {
								*((uint32_t*)v10 + 535) = v2;
							}
						} else if (*((uint32_t*)v10 + 534) >= v2) {
							*((uint32_t*)v10 + 534) = v2 - 1;
						}
					}
				}
			}
			result = sub_45A010(k);
		}
	}
	return result;
}

//----- (00494A60) --------------------------------------------------------
int nox_xxx_netCliProcUpdateStream_494A60(unsigned char* a1, int a2, uint32_t* a3) {
	unsigned short v3;  // di
	unsigned short v4;  // bp
	unsigned char* v5;  // esi
	int v6;             // ebx
	int v7;             // eax
	unsigned short v8;  // ax
	unsigned short v9;  // cx
	unsigned char* v10; // esi
	unsigned char v11;  // bl
	unsigned char* v12; // esi
	unsigned char v13;  // dl
	unsigned char v14;  // dl
	int v15;            // esi
	uint32_t* v16;      // eax
	unsigned char v17;  // cl
	int v18;            // edx
	unsigned short v20; // [esp+10h] [ebp-18h]
	unsigned short v21; // [esp+14h] [ebp-14h]
	unsigned char* v22; // [esp+18h] [ebp-10h]
	char v23[10];       // [esp+1Ch] [ebp-Ch]
	unsigned char v24;  // [esp+2Ch] [ebp+4h]
	unsigned char v25;  // [esp+2Ch] [ebp+4h]
	unsigned char v26;  // [esp+30h] [ebp+8h]

	v22 = a1;
	if (*a1 == 0xFFu) {
		v3 = *(uint16_t*)(a1 + 1);
		v4 = *(uint16_t*)(a1 + 3);
		v5 = a1 + 5;
		v6 = *(unsigned short*)(a1 + 3);
		v24 = nox_xxx_cliGenerateAlias_57B9A0((int)getMemAt(0x5D4594, 1198020), v3, v6, nox_frame_xxx_2598000);
		if (v24 != -1) {
			sub_57BA10((int)getMemAt(0x5D4594, 1198020 + 8 * v24), v3, v6, -1);
			v23[0] = -91;
			*(uint16_t*)&v23[2] = v3;
			*(uint16_t*)&v23[4] = v4;
			v23[1] = v24;
			*(uint32_t*)&v23[6] = -1;
			nox_netlist_addToMsgListCli_40EBC0(a2, 0, v23, 10);
		}
	} else {
		v7 = 8 * *a1;
		v5 = a1 + 1;
		v3 = *getMemU16Ptr(0x5D4594, 1198020 + v7);
		v4 = *getMemU16Ptr(0x5D4594, 1198022 + v7);
	}
	v8 = *(uint16_t*)v5;
	v9 = *((uint16_t*)v5 + 1);
	v20 = *(uint16_t*)v5;
	v10 = v5 + 4;
	v21 = v9;
	v11 = *v10;
	v12 = v10 + 1;
	if ((v11 & 0x80u) == 0) {
		v25 = 0;
	} else {
		v13 = *v12++;
		v25 = v13;
	}
	v14 = *v12;
	v15 = (int)(v12 + 1);
	v26 = v14;
	if (v3 || v4) {
		v16 = nox_xxx_spriteCreate_48E970(v4, v3, v8, v9);
		if (v16) {
			v16[72] = nox_frame_xxx_2598000;
			v17 = (v11 >> 4) & 7;
			*((uint8_t*)v16 + 297) = v17;
			if (v17 > 3u) {
				*((uint8_t*)v16 + 297) = v17 + 1;
			}
			if (v16[69] != v26) {
				v18 = nox_frame_xxx_2598000;
				v16[69] = v26;
				v16[79] = v18;
			}
			nox_xxx_spriteSetFrameMB_45AB80((int)v16, v25);
		}
	}
	*a3 = v20;
	a3[1] = v21;
	nox_xxx_cliUpdateCameraPos_435600(v20, v21);
	return v15 - (uint32_t)v22;
}

//----- (00494C30) --------------------------------------------------------
unsigned char* nox_xxx_netCliUpdateStream2_494C30(unsigned char* a1, int a2, int* a3) {
	unsigned char* v3; // esi
	unsigned char v4;  // al
	unsigned short v6; // di
	uint16_t* v7;      // esi
	unsigned short v8; // bp
	unsigned short v9; // bx
	short* v10;        // esi
	int v11;           // eax
	int v12;           // ecx
	int* v13;          // ebx
	int v14;           // esi
	int v15;           // eax
	int v16;           // ecx
	int v17;           // eax
	uint32_t* v18;     // eax
	int v19;           // edi
	char v20;          // cl
	unsigned char v21; // al
	unsigned char v22; // dl
	int v23;           // ecx
	unsigned char v24; // [esp+10h] [ebp-18h]
	int v25;           // [esp+14h] [ebp-14h]
	char v26[10];      // [esp+1Ch] [ebp-Ch]
	char v27;          // [esp+34h] [ebp+Ch]
	unsigned char v28; // [esp+34h] [ebp+Ch]

	v3 = a1;
	v4 = *a1;
	v25 = 0;
	if (!*a1) {
		v4 = a1[1];
		v3 = a1 + 1;
		if (!v4 && !a1[2]) {
			return (unsigned char*)-3;
		}
		v25 = 1;
	}
	if (v4 == 0xFFu) {
		v6 = *(uint16_t*)(v3 + 1);
		v7 = v3 + 3;
		v8 = *v7;
		v9 = *v7;
		v10 = v7 + 1;
		v24 = nox_xxx_cliGenerateAlias_57B9A0((int)getMemAt(0x5D4594, 1198020), v6, v9, nox_frame_xxx_2598000);
		if (v24 != -1) {
			sub_57BA10((int)getMemAt(0x5D4594, 1198020 + 8 * v24), v6, v9, nox_frame_xxx_2598000 + 60);
			v26[1] = v24;
			v26[0] = -91;
			*(uint16_t*)&v26[2] = v6;
			*(uint16_t*)&v26[4] = v8;
			*(uint32_t*)&v26[6] = nox_frame_xxx_2598000 + 60;
			nox_netlist_addToMsgListCli_40EBC0(a2, 0, v26, 10);
		}
	} else {
		v11 = 8 * v4;
		v10 = (short*)(v3 + 1);
		v6 = *getMemU16Ptr(0x5D4594, 1198020 + v11);
		v8 = *getMemU16Ptr(0x5D4594, 1198022 + v11);
	}
	if (v25) {
		v12 = *v10;
		v13 = a3;
		v14 = (int)(v10 + 2);
		*a3 = v12;
		a3[1] = *(short*)(v14 - 2);
	} else {
		v13 = a3;
		v15 = *(char*)v10;
		v14 = (int)(v10 + 1);
		*a3 += v15;
		a3[1] += *(char*)(v14 - 1);
	}
	v16 = *v13;
	if ((int)*v13 < 0) {
		return &a1[-v14];
	}
	if (v16 > 6000) {
		return &a1[-v14];
	}
	v17 = v13[1];
	if (v17 < 0) {
		return &a1[-v14];
	}
	if (v17 > 6000) {
		return &a1[-v14];
	}
	v18 = nox_xxx_spriteCreate_48E970(v8, v6, v16, v13[1]);
	v19 = (int)v18;
	if (!v18) {
		return &a1[-v14];
	}
	if (v18[28] & 0x200000) {
		v18[72] = nox_frame_xxx_2598000;
		v27 = *(uint8_t*)v14;
		v20 = *(uint8_t*)v14;
		v21 = (*(uint8_t*)v14 >> 4) & 7;
		*(uint8_t*)(v19 + 297) = v21;
		if (v21 > 3u) {
			*(uint8_t*)(v19 + 297) = v21 + 1;
		}
		if (v20 < 0) {
			nox_xxx_spriteSetFrameMB_45AB80(v19, *(unsigned char*)++v14);
			v20 = v27;
		}
		if (*(uint8_t*)(v19 + 112) & 4) {
			v22 = *(uint8_t*)++v14;
			v28 = v22;
		} else {
			v28 = v20 & 0xF;
		}
		if (*(uint32_t*)(v19 + 276) != v28) {
			v23 = nox_frame_xxx_2598000;
			*(uint32_t*)(v19 + 276) = v28;
			*(uint32_t*)(v19 + 316) = v23;
		}
		++v14;
	} else {
		v18[72] = nox_frame_xxx_2598000;
		nox_xxx_sprite_49AA00_drawable(v18);
	}
	*v13 = *(uint32_t*)(v19 + 12);
	v13[1] = *(uint32_t*)(v19 + 16);
	return (unsigned char*)(v14 - (uint32_t)a1);
}

//----- (00494E90) --------------------------------------------------------
int nox_netlist_receiveCli_494E90(int ind) {
	int res = 0;

	int n1 = 0;
	unsigned char* buf1 = nox_netlist_copyPacketList2_40F120(ind, &n1);
	if (buf1) {
		res = nox_xxx_netOnPacketRecvCli_48EA70(ind, buf1, n1);
	} else {
		res = n1;
	}

	int n2 = 0;
	unsigned char* buf2 = nox_netlist_copyPacketList_40ED60(ind, 1, &n2);
	if (buf2) {
		res = nox_xxx_netOnPacketRecvCli_48EA70(ind, buf2, n2);
		if (res) {
			sub_48D660();
		}
	}
	return res;
}

//----- (00494F00) --------------------------------------------------------
int sub_494F00() {
	int result; // eax
	int v1;     // esi
	int v2;     // eax

	*getMemU32Ptr(0x5D4594, 1200772) = nox_xxx_getTTByNameSpriteMB_44CFC0("Spark");
	if (!*getMemU32Ptr(0x5D4594, 1200772)) {
		return 0;
	}
	result = nox_xxx_getTTByNameSpriteMB_44CFC0("BlueSpark");
	dword_5d4594_1200776 = result;
	if (result) {
		result = nox_xxx_getTTByNameSpriteMB_44CFC0("YellowSpark");
		*getMemU32Ptr(0x5D4594, 1200780) = result;
		if (result) {
			result = nox_xxx_getTTByNameSpriteMB_44CFC0("CyanSpark");
			*getMemU32Ptr(0x5D4594, 1200784) = result;
			if (result) {
				result = nox_xxx_getTTByNameSpriteMB_44CFC0("GreenSpark");
				*getMemU32Ptr(0x5D4594, 1200788) = result;
				if (result) {
					result = nox_xxx_getTTByNameSpriteMB_44CFC0("Puff");
					*getMemU32Ptr(0x5D4594, 1200792) = result;
					if (result) {
						v1 = 0;
						while (1) {
							v2 = nox_xxx_getTTByNameSpriteMB_44CFC0(*(char**)getMemAt(0x587000, 161216 + v1));
							*getMemU32Ptr(0x5D4594, 1200812 + v1) = v2;
							if (!v2) {
								break;
							}
							v1 += 4;
							if (v1 >= 20) {
								dword_5d4594_1200796 = nox_xxx_getTTByNameSpriteMB_44CFC0("VioletSpark");
								return dword_5d4594_1200796 != 0;
							}
						}
						return 0;
					}
				}
			}
		}
	}
	return result;
}

//----- (00494FF0) --------------------------------------------------------
char* sub_494FF0() {
	int v0;            // eax
	unsigned char* v1; // ecx

	v0 = 0;
	v1 = getMemAt(0x5D4594, 1200928);
	while (*(uint32_t*)v1) {
		v1 += 16;
		++v0;
		if ((int)v1 >= (int)getMemAt(0x5D4594, 1201440)) {
			return 0;
		}
	}
	return (char*)getMemAt(0x5D4594, 1200916 + 16 * v0);
}

//----- (00495020) --------------------------------------------------------
char* sub_495020(int a1) {
	int v1;            // eax
	unsigned char* v2; // ecx

	v1 = 0;
	v2 = getMemAt(0x5D4594, 1200916);
	while (!*((uint32_t*)v2 + 3) || *(uint32_t*)v2 != a1) {
		v2 += 16;
		++v1;
		if ((int)v2 >= (int)getMemAt(0x5D4594, 1201428)) {
			return 0;
		}
	}
	return (char*)getMemAt(0x5D4594, 1200916 + 16 * v1);
}

//----- (00495060) --------------------------------------------------------
int sub_495060(int a1, short a2, short a3) {
	unsigned char* v3; // eax
	char* v4;          // eax

	v3 = getMemAt(0x5D4594, 1200916);
	do {
		if (*((uint32_t*)v3 + 3) == 1 && *(uint32_t*)v3 == a1) {
			return 1;
		}
		v3 += 16;
	} while ((int)v3 < (int)getMemAt(0x5D4594, 1201428));
	v4 = sub_494FF0();
	if (v4) {
		*((uint16_t*)v4 + 3) = a2;
		*((uint16_t*)v4 + 4) = a3;
		*((uint32_t*)v4 + 3) = 1;
		v4[4] = 0;
		*(uint32_t*)v4 = a1;
		return 1;
	}
	return 0;
}

//----- (004950C0) --------------------------------------------------------
int sub_4950C0(int a1) {
	char* v1; // eax

	v1 = sub_495020(a1);
	if (!v1) {
		return 0;
	}
	*((uint32_t*)v1 + 3) = 0;
	return 1;
}

//----- (004950F0) --------------------------------------------------------
int sub_4950F0(int a1, char a2) {
	char* v2; // eax

	v2 = sub_495020(a1);
	if (!v2) {
		return 0;
	}
	v2[4] = a2;
	return 1;
}

//----- (00495120) --------------------------------------------------------
int sub_495120(int a1, short a2, short a3) {
	char* v3; // eax

	v3 = sub_495020(a1);
	if (!v3) {
		return 0;
	}
	*((uint16_t*)v3 + 3) = a2;
	*((uint16_t*)v3 + 4) = a3;
	return 1;
}

//----- (00495150) --------------------------------------------------------
int sub_495150(int a1, short a2) {
	char* v2; // eax

	v2 = sub_495020(a1);
	if (!v2) {
		return 0;
	}
	*((uint16_t*)v2 + 3) = a2;
	return 1;
}

//----- (00495180) --------------------------------------------------------
int sub_495180(int a1, uint16_t* a2, uint16_t* a3, uint8_t* a4) {
	char* v4; // eax

	v4 = sub_495020(a1);
	if (!v4) {
		return 0;
	}
	*a2 = *((uint16_t*)v4 + 3);
	*a3 = *((uint16_t*)v4 + 4);
	*a4 = v4[4];
	return 1;
}

//----- (004951C0) --------------------------------------------------------
char* sub_4951C0() {
	char* result; // eax

	result = (char*)getMemAt(0x5D4594, 1200922);
	do {
		*(uint32_t*)(result + 6) = 0;
		*(uint16_t*)result = 0;
		*((uint16_t*)result + 1) = 0;
		*(result - 2) = 0;
		*(uint32_t*)(result - 6) = 0;
		result += 16;
	} while ((int)result < (int)getMemAt(0x5D4594, 1201434));
	return result;
}

//----- (004951F0) --------------------------------------------------------
int nox_xxx_unitSpriteCheckAlly_4951F0(int a1) { return sub_495020(a1) != 0; }

//----- (00495210) --------------------------------------------------------
int sub_495210(int a1) {
	int v1; // esi
	int v2; // eax
	int v3; // eax

	v1 = dword_5d4594_1203836;
	if ((dword_5d4594_1203836 + 1) % 100 == dword_5d4594_1203840) {
		dword_5d4594_1203840 = (dword_5d4594_1203840 + 1) % 100;
	}
	if (*(uint8_t*)(a1 + 10) == 1) {
		v2 = *(unsigned short*)(a1 + 8);
		if ((unsigned short)v2 == *getMemU32Ptr(0x5D4594, 1203844)) {
			*(uint16_t*)(a1 + 8) = *getMemU16Ptr(0x5D4594, 1203856);
		LABEL_8:
			v1 = dword_5d4594_1203836;
			goto LABEL_9;
		}
		if (v2 == *getMemU32Ptr(0x5D4594, 1203848)) {
			*(uint16_t*)(a1 + 8) = *getMemU16Ptr(0x5D4594, 1203852);
			goto LABEL_8;
		}
	}
LABEL_9:
	v3 = 24 * v1;
	*getMemU32Ptr(0x5D4594, 1201428 + v3) = *(unsigned short*)(a1 + 2);
	*getMemU32Ptr(0x5D4594, 1201432 + v3) = *(unsigned short*)(a1 + 4);
	*getMemU32Ptr(0x5D4594, 1201436 + v3) = *(unsigned short*)(a1 + 6);
	*getMemU32Ptr(0x5D4594, 1201440 + v3) = *(unsigned short*)(a1 + 8);
	*getMemU32Ptr(0x5D4594, 1201444 + v3) = *(unsigned char*)(a1 + 10);
	*getMemU32Ptr(0x5D4594, 1201448 + v3) = nox_frame_xxx_2598000;
	dword_5d4594_1203836 = (v1 + 1) % 100;
	return sub_4952E0((uint16_t*)a1);
}

//----- (00495430) --------------------------------------------------------
int sub_495430() {
	int v0;       // ecx
	int v1;       // esi
	int result;   // eax
	int i;        // edi
	long long v4; // rtt

	dword_5d4594_1203832 = 0;
	nox_client_drawEnableAlpha_434560(0);
	sub_4345F0(0);
	nox_xxx_draw_434600(0);
	v0 = dword_5d4594_1203840;
	v1 = dword_5d4594_1203840;
	result = dword_5d4594_1203836;
	for (i = nox_win_height / 4 / 36; v1 != dword_5d4594_1203836; v1 = (v1 + 1) % 100) {
		if (dword_5d4594_1203832 > i) {
			break;
		}
		if ((unsigned int)(nox_frame_xxx_2598000 - *getMemU32Ptr(0x5D4594, 1201448 + 24 * v0)) <= 0x5A) {
			sub_495500(getMemIntPtr(0x5D4594, 1201428 + 24 * v1));
			v0 = dword_5d4594_1203840;
			++dword_5d4594_1203832;
		} else {
			v4 = v0 + 1;
			v0 = (v0 + 1) % 100;
			dword_5d4594_1203840 = v4 % 100;
		}
		result = dword_5d4594_1203836;
	}
	return result;
}

//----- (00495500) --------------------------------------------------------
int* sub_495500(int* a1) {
	int v1;          // edi
	int v2;          // eax
	int v3;          // ebp
	bool v4;         // zf
	char* v5;        // eax
	char* v6;        // eax
	char* v7;        // eax
	int v8;          // ebp
	int v11;         // esi
	int v12;         // esi
	int v13;         // ecx
	int v14;         // kr04_4
	int v15;         // esi
	int v16;         // edi
	int v17;         // ebx
	int v18;         // esi
	int* result;     // eax
	int v20;         // esi
	int v21;         // [esp+10h] [ebp-DCh]
	int v22;         // [esp+14h] [ebp-D8h]
	int v23;         // [esp+18h] [ebp-D4h]
	int v24;         // [esp+1Ch] [ebp-D0h]
	int v25;         // [esp+20h] [ebp-CCh]
	int v26;         // [esp+24h] [ebp-C8h]
	int v27;         // [esp+28h] [ebp-C4h]
	wchar_t v28[32]; // [esp+2Ch] [ebp-C0h]
	wchar_t v29[32]; // [esp+6Ch] [ebp-80h]
	wchar_t v30[32]; // [esp+ACh] [ebp-40h]

	v1 = nox_xxx_guiFontPtrByName_43F360("large");
	v2 = *a1;
	v3 = 0;
	v4 = *a1 == 0;
	v24 = v1;
	v29[0] = 0;
	v28[0] = 0;
	v30[0] = 0;
	v23 = 0;
	v25 = 0;
	v27 = 0;
	v26 = 0;
	if (!v4) {
		v5 = nox_common_playerInfoGetByID_417040(v2);
		if (v5) {
			v3 = 1;
			nox_swprintf(v29, (const wchar_t*)v5 + 2352);
		}
	}
	if (a1[1]) {
		v6 = nox_common_playerInfoGetByID_417040(a1[1]);
		if (v6) {
			if (v3) {
				nox_swprintf(v28, L"+%s", v6 + 4704);
			} else {
				nox_swprintf(v28, (const wchar_t*)v6 + 2352);
			}
		}
	}
	if (a1[2]) {
		v7 = nox_common_playerInfoGetByID_417040(a1[2]);
		if (v7) {
			nox_swprintf(v30, (const wchar_t*)v7 + 2352);
		}
	}
	if (a1[4] != 1) {
		if (a1[4] == 2) {
			switch (a1[3]) {
			case 1:
			case 12:
				v8 = nox_xxx_spellIcon_424A90(5);
				goto LABEL_26;
			case 2:
				v8 = nox_xxx_spellGetAbilityIcon_425310(1, 0);
				goto LABEL_26;
			case 4:
				v8 = nox_xxx_spellIcon_424A90(130);
				goto LABEL_26;
			case 5:
				v8 = nox_xxx_spellIcon_424A90(60);
				goto LABEL_26;
			case 9:
			case 17:
				v8 = nox_xxx_spellIcon_424A90(43);
				goto LABEL_26;
			case 15:
				v8 = nox_xxx_spellIcon_424A90(56);
				goto LABEL_26;
			case 16:
				v8 = nox_xxx_spellIcon_424A90(16);
				goto LABEL_26;
			default:
				break;
			}
		}
	LABEL_27:
		v8 = *getMemU32Ptr(0x5D4594, 1203828);
		goto LABEL_28;
	}
	nox_thing* t9 = nox_get_thing(a1[3]);
	if (!t9) {
		goto LABEL_27;
	}
	if (t9->pri_class & 0x1001000) {
		sub_4B9650(a1[3]);
	}
	v8 = t9->pretty_image;
LABEL_26:
	if (!v8) {
		goto LABEL_27;
	}
LABEL_28:
	sub_47D5C0(v8, &v27, &v26, &v23, &v25);
	nox_xxx_drawGetStringSize_43F840(v1, v29, &v21, &v22, 0);
	v11 = v21;
	nox_xxx_drawGetStringSize_43F840(v1, v28, &v21, &v22, 0);
	v12 = v21 + v11;
	nox_xxx_drawGetStringSize_43F840(v1, v30, &v21, &v22, 0);
	v13 = v12 + v23 + v21 + 20;
	v14 = nox_win_width - (v12 + v23 + v21 + 10);
	v15 = v14 / 2;
	v16 = 36 * dword_5d4594_1203832;
	nox_client_drawRectFilledAlpha_49CF10(v14 / 2 - 5, 36 * dword_5d4594_1203832, v13, 36);
	v17 = v16 + (36 - v22) / 2;
	if (*a1) {
		nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2597996));
		if (*a1 == nox_player_netCode_85319C) {
			nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x8531A0, 2572));
		}
		v15 = nox_xxx_drawString_43F6E0(v24, (short*)v29, v14 / 2, v17);
	}
	if (a1[1]) {
		nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2597996));
		if (a1[1] == nox_player_netCode_85319C) {
			nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x8531A0, 2572));
		}
		v15 = nox_xxx_drawString_43F6E0(v24, (short*)v28, v15, v17);
	}
	v18 = v15 + 5;
	if (v8) {
		nox_client_drawImageAt_47D2C0(v8, v18 - v27, v16 + (36 - v25) / 2 - v26);
	}
	result = a1;
	v20 = v18 + v23 + 5;
	if (a1[2]) {
		nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2597996));
		if (a1[2] == nox_player_netCode_85319C) {
			nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x8531A0, 2572));
		}
		result = (int*)nox_xxx_drawString_43F6E0(v24, (short*)v30, v20, v17);
	}
	return result;
}

//----- (004958F0) --------------------------------------------------------
int sub_4958F0() {
	int result; // eax

	dword_5d4594_1203840 = 0;
	dword_5d4594_1203836 = 0;
	if (!*getMemU32Ptr(0x5D4594, 1203844)) {
		*getMemU32Ptr(0x5D4594, 1203844) = nox_xxx_getTTByNameSpriteMB_44CFC0("ArcherBolt");
	}
	if (!*getMemU32Ptr(0x5D4594, 1203848)) {
		*getMemU32Ptr(0x5D4594, 1203848) = nox_xxx_getTTByNameSpriteMB_44CFC0("ArcherArrow");
	}
	if (!*getMemU32Ptr(0x5D4594, 1203852)) {
		*getMemU32Ptr(0x5D4594, 1203852) = nox_xxx_getTTByNameSpriteMB_44CFC0("Bow");
	}
	if (!*getMemU32Ptr(0x5D4594, 1203856)) {
		*getMemU32Ptr(0x5D4594, 1203856) = nox_xxx_getTTByNameSpriteMB_44CFC0("CrossBow");
	}
	result = nox_xxx_spellIcon_424A90(15);
	*getMemU32Ptr(0x5D4594, 1203828) = result;
	return result;
}

//----- (00495980) --------------------------------------------------------
int nox_xxx_allocClassListFriends_495980() {
	nox_alloc_friendList_1203860 = nox_new_alloc_class("FriendListClass", 8, 128);
	return nox_alloc_friendList_1203860 != 0;
}

//----- (004959B0) --------------------------------------------------------
void sub_4959B0() {
	nox_alloc_class_free_all(*(uint32_t**)&nox_alloc_friendList_1203860);
	dword_5d4594_1203864 = 0;
}

//----- (004959D0) --------------------------------------------------------
int sub_4959D0() {
	int result; // eax

	nox_free_alloc_class(*(void**)&nox_alloc_friendList_1203860);
	result = 0;
	nox_alloc_friendList_1203860 = 0;
	dword_5d4594_1203864 = 0;
	return result;
}

//----- (004959F0) --------------------------------------------------------
uint32_t* nox_xxx_cliAddObjFriend_4959F0(int a1) {
	uint32_t* result; // eax

	result = nox_alloc_class_new_obj_zero(*(uint32_t**)&nox_alloc_friendList_1203860);
	if (result) {
		*result = a1;
		result[1] = dword_5d4594_1203864;
		dword_5d4594_1203864 = result;
	}
	return result;
}

//----- (00495A20) --------------------------------------------------------
void sub_495A20(int a1) {
	int v1; // eax
	int v2; // ecx

	v1 = dword_5d4594_1203864;
	v2 = 0;
	if (dword_5d4594_1203864) {
		while (*(uint32_t*)v1 != a1) {
			v2 = v1;
			v1 = *(uint32_t*)(v1 + 4);
			if (!v1) {
				return;
			}
		}
		if (v2) {
			*(uint32_t*)(v2 + 4) = *(uint32_t*)(v1 + 4);
		} else {
			dword_5d4594_1203864 = *(uint32_t*)(v1 + 4);
		}
		nox_alloc_class_free_obj_first(*(unsigned int**)&nox_alloc_friendList_1203860, (uint64_t*)v1);
	}
}

//----- (00495A80) --------------------------------------------------------
int sub_495A80(int a1) {
	uint32_t* v1; // eax

	v1 = *(uint32_t**)&dword_5d4594_1203864;
	if (!dword_5d4594_1203864) {
		return 0;
	}
	while (*v1 != a1) {
		v1 = (uint32_t*)v1[1];
		if (!v1) {
			return 0;
		}
	}
	return 1;
}

//----- (00495AB0) --------------------------------------------------------
int nox_xxx_allocArrayDrawableFX_495AB0() {
	int result; // eax

	result = nox_new_alloc_class("DrawableFX", 80, 128);
	*getMemU32Ptr(0x5D4594, 1203868) = result;
	if (result) {
		*getMemU32Ptr(0x5D4594, 1203872) = 0;
		result = 1;
	}
	return result;
}

//----- (00495AE0) --------------------------------------------------------
int sub_495AE0() {
	int result; // eax

	nox_free_alloc_class(*(void**)getMemAt(0x5D4594, 1203868));
	result = 0;
	*getMemU32Ptr(0x5D4594, 1203868) = 0;
	*getMemU32Ptr(0x5D4594, 1203872) = 0;
	return result;
}

//----- (00495B50) --------------------------------------------------------
uint32_t* sub_495B50(uint32_t* a1) {
	uint32_t* result; // eax
	int v2;           // ecx
	int v3;           // ecx
	int v4;           // ecx
	int v5;           // edx
	int v6;           // ecx

	result = a1;
	if (a1) {
		v2 = a1[18];
		if (v2) {
			*(uint32_t*)(v2 + 76) = a1[19];
		}
		v3 = a1[19];
		if (v3) {
			*(uint32_t*)(v3 + 72) = a1[18];
		} else {
			*getMemU32Ptr(0x5D4594, 1203872) = a1[18];
		}
		v4 = a1[16];
		v5 = a1[15];
		if (v4) {
			*(uint32_t*)(v4 + 68) = a1[17];
		}
		v6 = a1[17];
		if (v6) {
			*(uint32_t*)(v6 + 64) = a1[16];
		} else {
			result = (uint32_t*)a1[16];
			*(uint32_t*)(v5 + 456) = result;
		}
	}
	return result;
}

//----- (00495BB0) --------------------------------------------------------
uint32_t* sub_495BB0(nox_drawable* dr, nox_draw_viewport_t* vp) {
	uint32_t* a1 = dr;
	uint32_t* a2 = vp;
	uint32_t* result; // eax
	uint32_t* v3;     // esi

	result = (uint32_t*)a1[114];
	if (result) {
		do {
			v3 = (uint32_t*)result[16];
			if (*result == 1) {
				sub_495BF0((int)a1, (int)result, (int)a2);
			} else if (*result == 2) {
				sub_495D00(a1, (int)result, a2);
			}
			result = v3;
		} while (v3);
	}
	return result;
}

//----- (00495BF0) --------------------------------------------------------
int sub_495BF0(int a1, int a2, int a3) {
	int v3;            // ecx
	int result;        // eax
	uint32_t* v5;      // edx
	int v6;            // edx
	int v7;            // edi
	int v8;            // ebx
	uint32_t* v9;      // edi
	int v10;           // ecx
	uint32_t* v11;     // eax
	char v12;          // al
	unsigned char v13; // [esp+10h] [ebp-Ch]
	int v14;           // [esp+14h] [ebp-8h]
	int v15;           // [esp+18h] [ebp-4h]

	v3 = 0;
	result = *(unsigned char*)(a2 + 56);
	v13 = -1;
	if (result <= 0) {
	LABEL_6:
		if (*(uint32_t*)(a1 + 12) == *(uint32_t*)(a1 + 32) && *(uint32_t*)(a1 + 16) == *(uint32_t*)(a1 + 36)) {
			*(uint8_t*)(a2 + 56) = 0;
			return result;
		}
	} else {
		v5 = (uint32_t*)(a2 + 8);
		while (*v5 == v5[2] || v5[1] == v5[3]) {
			++v3;
			v5 += 2;
			if (v3 >= result) {
				goto LABEL_6;
			}
		}
	}
	v6 = *(uint32_t*)(a1 + 12);
	v7 = *(uint32_t*)(a1 + 16);
	v8 = 0;
	v14 = *(uint32_t*)(a1 + 12);
	v15 = *(uint32_t*)(a1 + 16);
	if (result > 0) {
		v9 = (uint32_t*)(a2 + 8);
		do {
			v13 -= 42;
			nox_client_drawEnableAlpha_434560(1);
			nox_client_drawSetAlpha_434580(v13);
			*(uint32_t*)(a1 + 12) = *v9;
			*(uint32_t*)(a1 + 16) = v9[1];
			(*(void (**)(int, int))(a1 + 300))(a3, a1);
			++v8;
			v9 += 2;
		} while (v8 < *(unsigned char*)(a2 + 56));
		v7 = v15;
		v6 = v14;
	}
	v10 = *(unsigned char*)(a2 + 56);
	if (v10 > 0) {
		v11 = (uint32_t*)(a2 + 8 * v10);
		do {
			v11[2] = *v11;
			v11[3] = v11[1];
			v11 -= 2;
			--v10;
		} while (v10);
	}
	*(uint32_t*)(a1 + 12) = v6;
	*(uint32_t*)(a1 + 16) = v7;
	v12 = *(uint8_t*)(a2 + 56);
	*(uint32_t*)(a2 + 8) = v6;
	*(uint32_t*)(a2 + 12) = v7;
	if (v12 != 5) {
		*(uint8_t*)(a2 + 56) = v12 + 1;
	}
	nox_client_drawEnableAlpha_434560(0);
	return 1;
}

//----- (00495D00) --------------------------------------------------------
int sub_495D00(uint32_t* a1, int a2, uint32_t* a3) {
	int v3;            // eax
	int v4;            // ecx
	uint32_t* v5;      // edx
	uint32_t* v6;      // ebp
	int result;        // eax
	uint32_t* v8;      // edi
	int v9;            // ebx
	int v10;           // esi
	int v11;           // ebx
	int v12;           // ecx
	int v13;           // esi
	int v14;           // ebp
	int v15;           // esi
	int v16;           // ebp
	int v17;           // eax
	bool v18;          // cc
	int v19;           // edx
	uint32_t* v20;     // eax
	char v21;          // al
	float v22;         // [esp+0h] [ebp-2Ch]
	float v23;         // [esp+0h] [ebp-2Ch]
	float v24;         // [esp+0h] [ebp-2Ch]
	float v25;         // [esp+0h] [ebp-2Ch]
	unsigned char v26; // [esp+14h] [ebp-18h]
	int v27;           // [esp+18h] [ebp-14h]
	float* v28;        // [esp+1Ch] [ebp-10h]
	float* v29;        // [esp+20h] [ebp-Ch]
	int v30;           // [esp+28h] [ebp-4h]
	int v31;           // [esp+28h] [ebp-4h]
	uint32_t* v32;     // [esp+38h] [ebp+Ch]

	v3 = 0;
	v4 = *(unsigned char*)(a2 + 56);
	v26 = -1;
	if (v4 <= 0) {
	LABEL_6:
		v6 = a1;
		if (a1[3] == a1[8]) {
			result = a1[9];
			if (a1[4] == result) {
				*(uint8_t*)(a2 + 56) = 0;
				return result;
			}
		}
	} else {
		v5 = (uint32_t*)(a2 + 8);
		while (*v5 == v5[2] || v5[1] == v5[3]) {
			++v3;
			v5 += 2;
			if (v3 >= v4) {
				goto LABEL_6;
			}
		}
		v6 = a1;
	}
	v8 = a3;
	v9 = v6[3] + *a3 - a3[4];
	v10 = 8 * v6[77];
	v30 = v6[4] - *((short*)v6 + 52) - *((short*)v6 + 53) - a3[5] + a3[1] - 10;
	v28 = getMemFloatPtr(0x587000, 194136 + 64 * v6[77]);
	v22 = *getMemFloatPtr(0x587000, 194136 + 64 * v6[77]) * -12.0;
	v11 = nox_float2int(v22) + v9;
	v29 = getMemFloatPtr(0x587000, 194140 + 8 * v10);
	v23 = *getMemFloatPtr(0x587000, 194140 + 8 * v10) * -12.0;
	v27 = 0;
	v31 = nox_float2int(v23) + v30;
	v12 = a2;
	if (*(uint8_t*)(a2 + 56)) {
		v32 = (uint32_t*)(a2 + 12);
		do {
			v26 -= 63;
			nox_client_drawEnableAlpha_434560(1);
			nox_client_drawSetAlpha_434580(v26);
			v13 = *v8 + *(v32 - 1) - v8[4];
			v14 = *v32 - *((short*)v6 + 52) - *((short*)v6 + 53) - v8[5] + v8[1] - 10;
			v24 = *v28 * -12.0;
			v15 = nox_float2int(v24) + v13;
			v25 = *v29 * -12.0;
			v16 = nox_float2int(v25) + v14;
			v17 = nox_color_rgb_4344A0(200, 200, 200);
			nox_client_drawSetColor_434460(v17);
			nox_client_drawAddPoint_49F500(v11, v31);
			nox_client_drawAddPoint_49F500(v15, v16);
			nox_client_drawLineFromPoints_49E4B0();
			v12 = a2;
			v32 += 2;
			v31 = v16;
			v6 = a1;
			v18 = v27 + 1 < *(unsigned char*)(a2 + 56);
			v11 = v15;
			++v27;
		} while (v18);
	}
	v19 = *(unsigned char*)(v12 + 56);
	if (v19 > 0) {
		v20 = (uint32_t*)(v12 + 8 * v19);
		do {
			v20[2] = *v20;
			v20[3] = v20[1];
			v20 -= 2;
			--v19;
		} while (v19);
	}
	*(uint32_t*)(v12 + 8) = v6[3];
	*(uint32_t*)(v12 + 12) = v6[4];
	v21 = *(uint8_t*)(v12 + 56);
	if (v21 != 5) {
		*(uint8_t*)(v12 + 56) = v21 + 1;
	}
	nox_client_drawEnableAlpha_434560(0);
	return 1;
}

//----- (00495F70) --------------------------------------------------------
void sub_495F70(int a1) {
	uint32_t* v1; // eax

	if (a1 && sub_496020(a1, 1) != 1) {
		v1 = nox_alloc_class_new_obj_zero(*(uint32_t**)getMemAt(0x5D4594, 1203868));
		if (v1) {
			*v1 = 1;
			v1[1] = 0;
			sub_495FC0(v1, a1);
		}
	}
}

//----- (00495FC0) --------------------------------------------------------
uint32_t* sub_495FC0(uint32_t* a1, int a2) {
	uint32_t* result; // eax
	int v3;           // edx

	result = a1;
	if (a1 && a2) {
		a1[15] = a2;
		a1[18] = *getMemU32Ptr(0x5D4594, 1203872);
		a1[19] = 0;
		if (*getMemU32Ptr(0x5D4594, 1203872)) {
			*(uint32_t*)(*getMemU32Ptr(0x5D4594, 1203872) + 76) = a1;
		}
		*getMemU32Ptr(0x5D4594, 1203872) = a1;
		a1[16] = *(uint32_t*)(a2 + 456);
		a1[17] = 0;
		v3 = *(uint32_t*)(a2 + 456);
		if (v3) {
			*(uint32_t*)(v3 + 68) = a1;
		}
		*(uint32_t*)(a2 + 456) = a1;
	}
	return result;
}

//----- (00496020) --------------------------------------------------------
int sub_496020(int a1, int a2) {
	uint32_t* v2; // eax

	v2 = *(uint32_t**)(a1 + 456);
	if (!v2) {
		return 0;
	}
	while (*v2 != a2) {
		v2 = (uint32_t*)v2[16];
		if (!v2) {
			return 0;
		}
	}
	return 1;
}

//----- (004960B0) --------------------------------------------------------
int sub_4960B0() {
	int result; // eax

	result = (int)calloc(1, 4 * (4 * nox_win_width / 23 * (nox_win_height / 23) / 2));
	dword_5d4594_1217456 = result;
	if (result) {
		sub_4CA860();
		result = 1;
	}
	return result;
}

//----- (00496120) --------------------------------------------------------
int sub_496120() {
	if (dword_5d4594_1217456) {
		free(*(void**)&dword_5d4594_1217456);
		dword_5d4594_1217456 = 0;
	}
	return 1;
}

//----- (00496150) --------------------------------------------------------
int nox_xxx_drawBlack_496150(nox_draw_viewport_t* a1p) {
	int* a1 = a1p;
	int v1;             // esi
	int v2;             // ecx
	int v3;             // ebx
	int v4;             // ebp
	int v5;             // ebx
	int v6;             // esi
	int v7;             // eax
	int v8;             // ebp
	unsigned char* v9;  // esi
	unsigned char v10;  // dl
	int v11;            // ecx
	unsigned char v12;  // al
	unsigned char v13;  // al
	int v14;            // edx
	unsigned char v15;  // al
	unsigned char* v16; // esi
	bool v17;           // zf
	int v18;            // ebp
	int v19;            // esi
	int v20;            // ebx
	int v21;            // ebp
	int v22;            // eax
	int v23;            // ecx
	char v24;           // al
	int v25;            // ebp
	int v26;            // edx
	int v27;            // ecx
	int v28;            // ebp
	int v29;            // eax
	int v30;            // ebp
	int v31;            // edx
	int v32;            // ecx
	int v33;            // ecx
	int v34;            // ebp
	double v35;         // st7
	int v36;            // ebx
	int v37;            // ebx
	int v38;            // ecx
	int v39;            // ebp
	int v40;            // ebx
	int v41;            // ebx
	int v42;            // ebx
	double v43;         // st7
	double v44;         // st7
	int v45;            // ebx
	int v46;            // ebx
	int v47;            // ebx
	int v48;            // edx
	int v49;            // ecx
	int v50;            // edx
	int v51;            // ebx
	int v52;            // ebx
	int v53;            // esi
	int v54;            // eax
	unsigned char v55;  // cl
	unsigned char v56;  // dl
	int v57;            // ecx
	int v58;            // edi
	int v59;            // ebp
	int v60;            // ecx
	int v61;            // ecx
	int v62;            // ecx
	int v63;            // ecx
	int v64;            // ebp
	int v65;            // ecx
	int v66;            // ecx
	int v68;            // [esp+4h] [ebp-8Ch]
	int v69;            // [esp+18h] [ebp-78h]
	int v70;            // [esp+1Ch] [ebp-74h]
	int v71;            // [esp+20h] [ebp-70h]
	int v72;            // [esp+20h] [ebp-70h]
	unsigned int v73;   // [esp+28h] [ebp-68h]
	int v74;            // [esp+2Ch] [ebp-64h]
	int v75;            // [esp+30h] [ebp-60h]
	int v76;            // [esp+34h] [ebp-5Ch]
	float2 a4;          // [esp+38h] [ebp-58h]
	float2 v78;         // [esp+40h] [ebp-50h]
	int v79;            // [esp+48h] [ebp-48h]
	int v80;            // [esp+4Ch] [ebp-44h]
	int2 a1a;           // [esp+50h] [ebp-40h]
	int2 a2;            // [esp+58h] [ebp-38h]
	float4 v83;         // [esp+60h] [ebp-30h]
	float4 a3;          // [esp+70h] [ebp-20h]
	float4 v86;         // [esp+80h] [ebp-10h]

	sub_4CAE60();
	dword_5d4594_1217464 = 0;
	dword_5d4594_1217460 = 0;
	v1 = a1[4];
	v2 = a1[5];
	v3 = a1[8];
	v79 = v1 / 23;
	v80 = v2 / 23;
	v74 = (v3 + v1) / 23 - v1 / 23;
	v4 = (a1[9] + v2) / 23 - v2 / 23;
	*getMemU32Ptr(0x5D4594, 1217444) = v1 + v3 / 2;
	dword_5d4594_1217448 = a1[5] + a1[12] + a1[9] / 2;
	sub_498030(a1);
	sub_497260(a1);
	if (v4 < 0) {
		goto LABEL_32;
	}
	v5 = v80;
	v6 = v74;
	v71 = v80;
	v70 = 23 * v80;
	v75 = v4 + 1;
	do {
		v7 = ((uint8_t)v5 + (uint8_t)v79) & 1;
		if (v7 > v6) {
			goto LABEL_31;
		}
		v8 = v7 + v79;
		v69 = 23 * (v7 + v79);
		v73 = (unsigned int)(v6 - v7 + 2) >> 1;
		do {
			v9 = (unsigned char*)nox_server_getWallAtGrid_410580(v8, v5);
			if (v9) {
				v10 = (unsigned char)sub_57B500(v8, v5, 64);
				if (v10 != 255) {
					v11 = v9[1];
					v12 = v9[4];
					if (getMemByte(0x85B3FC, 43076 + 12332 * v11) & 1) {
						if (v12 & 0x40) {
							if ((*getMemIntPtr(0x5D4594, 1217444) - v69 - 11) *
										(*getMemIntPtr(0x5D4594, 1217444) - v69 - 11) +
									(*(int*)&dword_5d4594_1217448 - v70 - 11) *
										(*(int*)&dword_5d4594_1217448 - v70 - 11) <
								3600) {
								v5 = v71;
								v9[4] = v12 | 1;
								goto LABEL_29;
							}
							v5 = v71;
						}
						if (v10) {
							if (v10 == 1) {
								nox_xxx_drawBlackofWall_497C40(v8, v5, 6);
							} else {
								v16 = getMemAt(0x587000, 161764 + v10);
								if (getMemByte(0x587000, 161764 + v10) & 2) {
									nox_xxx_drawBlackofWall_497C40(v8, v5, 2);
								}
								if (*v16 & 1) {
									nox_xxx_drawBlackofWall_497C40(v8, v5, 1);
								}
								if (*v16 & 8) {
									nox_xxx_drawBlackofWall_497C40(v8, v5, 8);
								}
								if (*v16 & 4) {
									nox_xxx_drawBlackofWall_497C40(v8, v5, 4);
								}
							}
						} else {
							nox_xxx_drawBlackofWall_497C40(v8, v5, 9);
						}
					} else {
						v13 = v12 | 1;
						v14 = v9[6];
						v9[4] = v13;
						if (23 * v14 <= *(int*)&dword_5d4594_1217448) {
							v15 = v13 & 0xFD;
						} else {
							v15 = v13 | 2;
						}
						v9[4] = v15;
						if (getMemByte(0x85B3FC, 43076 + 12332 * v11) & 4) {
							nox_xxx_drawList1096512_Append_4754C0(v9);
						}
					}
				}
			}
		LABEL_29:
			v8 += 2;
			v17 = v73 == 1;
			v69 += 46;
			--v73;
		} while (!v17);
		v6 = v74;
	LABEL_31:
		++v5;
		v17 = v75 == 1;
		v70 += 23;
		v71 = v5;
		--v75;
	} while (!v17);
LABEL_32:
	sub_498110();
	v72 = 0;
	a3.field_0 = (double)*getMemIntPtr(0x5D4594, 1217444);
	a3.field_4 = (double)*(int*)&dword_5d4594_1217448;
	if (*(int*)&dword_5d4594_1217460 <= 0) {
		v51 = dword_5d4594_1217464;
	} else {
		do {
			v18 = 0;
			v19 = *(uint32_t*)(dword_5d4594_1217456 + 4 * v72);
			switch (*(unsigned char*)(v19 + 56)) {
			case 0u:
				v20 = 25736 * *(int*)(v19 + 40) / 75000;
				a3.field_8 = (double)(int)(*getMemU32Ptr(0x5D4594, 1217444) + sub_414BD0(6434 - v20));
				a3.field_C = (double)(int)(dword_5d4594_1217448 + sub_414BD0(v20));
				sub_4CA960((uint32_t*)(v19 + 24), *(uint8_t*)(v19 + 36), &a3, &a4);
				v21 = 25736 * *(int*)(v19 + 44) / 75000;
				a3.field_8 = (double)(int)(*getMemU32Ptr(0x5D4594, 1217444) + sub_414BD0(6434 - v21));
				a3.field_C = (double)(int)(dword_5d4594_1217448 + sub_414BD0(v21));
				sub_4CA960((uint32_t*)(v19 + 24), *(uint8_t*)(v19 + 36), &a3, &v78);
				v22 = nox_server_getWallAtGrid_410580(*(uint32_t*)(v19 + 24), *(uint32_t*)(v19 + 28));
				v23 = v22;
				LOBYTE(v22) = *(uint8_t*)(v22 + 4);
				*(uint32_t*)(v23 + 12) = 1;
				v24 = v22 | 1;
				*(uint8_t*)(v23 + 4) = v24;
				if (v78.field_0 < (double)a4.field_0) {
					*(uint8_t*)(v23 + 4) = v24 | 2;
				}
				*(uint8_t*)(v23 + 3) |= *(uint8_t*)(v19 + 36);
				v18 = *(uint32_t*)(v19 + 24) + (*(uint32_t*)(v19 + 28) << 8);
				break;
			case 1u:
				a4.field_0 = (double)(*getMemIntPtr(0x5D4594, 1217444) +
									  sub_414C50(25736 * *(int*)(v19 + 40) / 75000 - 19302) * (a1[9] / 2) / 4096);
				a4.field_4 = (double)a1[5];
				v18 = 0;
				v78.field_0 = (double)(*getMemIntPtr(0x5D4594, 1217444) +
									   sub_414C50(25736 * *(int*)(v19 + 44) / 75000 - 19302) * (a1[9] / 2) / 4096);
				v78.field_4 = (double)a1[5];
				break;
			case 2u:
				v25 = a1[9];
				v26 = *getMemU32Ptr(0x5D4594, 1217444) -
					  sub_414C50(25736 * *(int*)(v19 + 40) / 75000 - 6434) * (v25 / 2) / 4096;
				v27 = a1[5] + v25 - 1;
				v28 = a1[9];
				a4.field_0 = (double)v26;
				a4.field_4 = (double)v27;
				v29 = sub_414C50(25736 * *(int*)(v19 + 44) / 75000 - 6434);
				v76 = a1[5] + v28 - 1;
				v78.field_0 = (double)(*getMemIntPtr(0x5D4594, 1217444) - v29 * (v28 / 2) / 4096);
				v78.field_4 = (double)v76;
				v18 = 0;
				break;
			case 3u:
				v32 = 25736 * *(uint32_t*)(v19 + 40);
				a4.field_0 = (double)a1[4];
				a4.field_4 =
					(double)(*(int*)&dword_5d4594_1217448 - sub_414C50(v32 / 75000 - 12868) * (a1[8] / 2) / 4096);
				v33 = 25736 * *(uint32_t*)(v19 + 44);
				v78.field_0 = (double)a1[4];
				v18 = 0;
				v78.field_4 =
					(double)(*(int*)&dword_5d4594_1217448 - sub_414C50(v33 / 75000 - 12868) * (a1[8] / 2) / 4096);
				break;
			case 4u:
				v30 = a1[8];
				v68 = 25736 * *(int*)(v19 + 40) / 75000;
				a4.field_0 = (double)(int)(a1[8] + a1[4] - 1);
				a4.field_4 = (double)(int)(dword_5d4594_1217448 + sub_414C50(v68) * (v30 / 2) / 4096);
				v31 = 25736 * *(int*)(v19 + 44) / 75000;
				v78.field_0 = (double)(int)(a1[4] + v30 - 1);
				v78.field_4 = (double)(int)(dword_5d4594_1217448 + sub_414C50(v31) * (a1[8] / 2) / 4096);
				v18 = 0;
				break;
			case 6u:
				v34 = *(uint32_t*)(v19 + 20);
				v35 = (double)*(int*)(v34 + 12);
				*(uint32_t*)(v34 + 132) = 1;
				v86.field_0 = v35;
				v86.field_4 = (double)*(int*)(v34 + 16);
				v86.field_8 =
					(double)(*(int*)(v34 + 12) + *getMemIntPtr(0x587000, 196184 + 8 * *(unsigned char*)(v34 + 299)));
				v86.field_C =
					(double)(*(int*)(v34 + 16) + *getMemIntPtr(0x587000, 196188 + 8 * *(unsigned char*)(v34 + 299)));
				v36 = 25736 * *(int*)(v19 + 40) / 75000;
				a3.field_8 = (double)(*getMemIntPtr(0x5D4594, 1217444) + sub_414BD0(6434 - v36));
				a3.field_C = (double)(*(int*)&dword_5d4594_1217448 + sub_414BD0(v36));
				if (!sub_497180(&a3.field_0, &v86.field_0, &a4.field_0)) {
					a4 = *(float2*)&v86.field_0;
				}
				v37 = 25736 * *(int*)(v19 + 44) / 75000;
				a3.field_8 = (double)(*getMemIntPtr(0x5D4594, 1217444) + sub_414BD0(6434 - v37));
				a3.field_C = (double)(*(int*)&dword_5d4594_1217448 + sub_414BD0(v37));
				if (!sub_497180(&a3.field_0, &v86.field_0, &v78.field_0)) {
					v78 = *(float2*)&v86.field_8;
				}
				v18 = *(uint32_t*)(v34 + 128);
				break;
			case 7u:
				*(uint32_t*)(*(uint32_t*)(v19 + 20) + 132) = 1;
				v38 = *(uint32_t*)(v19 + 20);
				v39 = *getMemU32Ptr(0x5D4594, 1217444) - *(uint32_t*)(v38 + 12);
				v40 = *(uint32_t*)(v38 + 16) - dword_5d4594_1217448;
				nox_double2int(sqrt((double)*(int*)(v19 + 32)));
				v83.field_0 = (double)(int)(v40 + *(int*)(*(uint32_t*)(v19 + 20) + 12));
				v83.field_4 = (double)(int)(v39 + *(int*)(*(uint32_t*)(v19 + 20) + 16));
				v83.field_8 = (double)(int)(*(int*)(*(uint32_t*)(v19 + 20) + 12) - v40);
				v83.field_C = (double)(int)(*(int*)(*(uint32_t*)(v19 + 20) + 16) - v39);
				v41 = 25736 * *(int*)(v19 + 40) / 75000;
				a3.field_8 = (double)(int)(*getMemIntPtr(0x5D4594, 1217444) + sub_414BD0(6434 - v41));
				a3.field_C = (double)(int)(*(int*)&dword_5d4594_1217448 + sub_414BD0(v41));
				if (!sub_497180(&a3.field_0, &v83.field_0, &a4.field_0)) {
					a4 = *(float2*)&v83;
				}
				v42 = 25736 * *(int*)(v19 + 44) / 75000;
				a3.field_8 = (double)(int)(*getMemIntPtr(0x5D4594, 1217444) + sub_414BD0(6434 - v42));
				a3.field_C = (double)(int)(*(int*)&dword_5d4594_1217448 + sub_414BD0(v42));
				if (sub_497180(&a3.field_0, &v83.field_0, &v78.field_0)) {
					goto LABEL_63;
				}
				goto LABEL_62;
			case 8u:
			case 9u:
			case 0xAu:
			case 0xBu:
			case 0xDu:
			case 0xEu:
				*(uint32_t*)(*(uint32_t*)(v19 + 20) + 132) = 1;
				switch (*(unsigned char*)(v19 + 56)) {
				case 8u:
					v83.field_0 = (double)*(int*)(*(int*)(v19 + 20) + 12) + *(float*)(*(uint32_t*)(v19 + 20) + 64);
					v83.field_4 = (double)*(int*)(*(int*)(v19 + 20) + 16) + *(float*)(*(uint32_t*)(v19 + 20) + 68);
					v83.field_8 = (double)*(int*)(*(int*)(v19 + 20) + 12) + *(float*)(*(uint32_t*)(v19 + 20) + 72);
					v43 = (double)*(int*)(*(int*)(v19 + 20) + 16) + *(float*)(*(uint32_t*)(v19 + 20) + 76);
					goto LABEL_58;
				case 9u:
					v83.field_0 = (double)*(int*)(*(int*)(v19 + 20) + 12) + *(float*)(*(uint32_t*)(v19 + 20) + 64);
					v44 = (double)*(int*)(*(int*)(v19 + 20) + 16) + *(float*)(*(uint32_t*)(v19 + 20) + 68);
					goto LABEL_57;
				case 0xAu:
					v83.field_0 = (double)*(int*)(*(int*)(v19 + 20) + 12) + *(float*)(*(uint32_t*)(v19 + 20) + 88);
					v83.field_4 = (double)*(int*)(*(int*)(v19 + 20) + 16) + *(float*)(*(uint32_t*)(v19 + 20) + 92);
					v83.field_8 = (double)*(int*)(*(int*)(v19 + 20) + 12) + *(float*)(*(uint32_t*)(v19 + 20) + 72);
					v43 = (double)*(int*)(*(int*)(v19 + 20) + 16) + *(float*)(*(uint32_t*)(v19 + 20) + 76);
					goto LABEL_58;
				case 0xBu:
					v83.field_0 = (double)*(int*)(*(int*)(v19 + 20) + 12) + *(float*)(*(uint32_t*)(v19 + 20) + 88);
					v44 = (double)*(int*)(*(int*)(v19 + 20) + 16) + *(float*)(*(uint32_t*)(v19 + 20) + 92);
					goto LABEL_57;
				case 0xDu:
					v83.field_0 = (double)*(int*)(*(int*)(v19 + 20) + 12) + *(float*)(*(uint32_t*)(v19 + 20) + 64);
					v83.field_4 = (double)*(int*)(*(int*)(v19 + 20) + 16) + *(float*)(*(uint32_t*)(v19 + 20) + 68);
					v83.field_8 = (double)*(int*)(*(int*)(v19 + 20) + 12) + *(float*)(*(uint32_t*)(v19 + 20) + 88);
					v43 = (double)*(int*)(*(int*)(v19 + 20) + 16) + *(float*)(*(uint32_t*)(v19 + 20) + 92);
					goto LABEL_58;
				case 0xEu:
					v83.field_0 = (double)*(int*)(*(uint32_t*)(v19 + 20) + 12) + *(float*)(*(uint32_t*)(v19 + 20) + 72);
					v44 = (double)*(int*)(*(uint32_t*)(v19 + 20) + 16) + *(float*)(*(uint32_t*)(v19 + 20) + 76);
				LABEL_57:
					v83.field_4 = v44;
					v83.field_8 = (double)*(int*)(*(int*)(v19 + 20) + 12) + *(float*)(*(uint32_t*)(v19 + 20) + 80);
					v43 = (double)*(int*)(*(int*)(v19 + 20) + 16) + *(float*)(*(uint32_t*)(v19 + 20) + 84);
				LABEL_58:
					v83.field_C = v43;
					break;
				default:
					break;
				}
				v45 = 25736 * *(int*)(v19 + 40) / 75000;
				a3.field_8 = (double)(int)(*getMemIntPtr(0x5D4594, 1217444) + sub_414BD0(6434 - v45));
				a3.field_C = (double)(int)(*(int*)&dword_5d4594_1217448 + sub_414BD0(v45));
				if (!sub_497180(&a3.field_0, &v83.field_0, &a4.field_0)) {
					a4 = *(float2*)&v83.field_0;
				}
				v46 = 25736 * *(int*)(v19 + 44) / 75000;
				a3.field_8 = (double)(int)(*getMemIntPtr(0x5D4594, 1217444) + sub_414BD0(6434 - v46));
				a3.field_C = (double)(int)(*(int*)&dword_5d4594_1217448 + sub_414BD0(v46));
				if (!sub_497180(&a3.field_0, &v83.field_0, &v78.field_0)) {
				LABEL_62:
					v78 = *(float2*)&v83.field_8;
				}
			LABEL_63:
				v18 = *(uint32_t*)(*(uint32_t*)(v19 + 20) + 128);
				break;
			default:
				break;
			}
			a1a.field_0 = *a1 - a1[4] + nox_float2int(a4.field_0);
			a1a.field_4 = a1[1] - a1[5] + nox_float2int(a4.field_4);
			a2.field_0 = *a1 - a1[4] + nox_float2int(v78.field_0);
			a2.field_4 = a1[1] - a1[5] + nox_float2int(v78.field_4);
			// _dprintf("%d\t%d\t%d %d %d %d", v72, *(unsigned char *)(v19 + 56), a1a.field_0, a1a.field_4,
			// a2.field_0, a2.field_4);
			if (sub_57BA30(&a1a, &a2, (int4*)a1)) {
				v47 = dword_5d4594_1217464;
				v48 = a1a.field_4;
				*getMemU32Ptr(0x5D4594, 1203876 + 8 * dword_5d4594_1217464) = a1a.field_0;
				v49 = a2.field_0;
				*getMemU32Ptr(0x5D4594, 1203880 + 8 * v47) = v48;
				v50 = a2.field_4;
				*getMemU32Ptr(0x5D4594, 1213348 + 4 * v47) = v18;
				*getMemU8Ptr(0x5D4594, 1212324 + v47++) = *(uint8_t*)(v19 + 56);
				dword_5d4594_1217464 = v47;
				*getMemU32Ptr(0x5D4594, 1203876 + 8 * v47) = v49;
				*getMemU32Ptr(0x5D4594, 1203880 + 8 * v47) = v50;
				*getMemU32Ptr(0x5D4594, 1213348 + 4 * v47) = v18;
				*getMemU8Ptr(0x5D4594, 1212324 + v47) = *(uint8_t*)(v19 + 56);
				v51 = v47 + 1;
				dword_5d4594_1217464 = v51;
			} else {
				v51 = dword_5d4594_1217464;
			}
			++v72;
		} while (v72 < *(int*)&dword_5d4594_1217460);
	}
	v52 = v51 - 1;
	v53 = 0;
	dword_5d4594_1217464 = v52;
	v54 = v52 - 1;
	while (v53 < v52) {
		v55 = getMemByte(0x5D4594, 1212324 + v54);
		if (v55) {
			v56 = getMemByte(0x5D4594, 1212324 + v53);
			if (!v56) {
				goto LABEL_89;
			}
			if (v56 != v55) {
				goto LABEL_99;
			}
			if (*getMemU32Ptr(0x5D4594, 1213348 + 4 * v53) != *getMemU32Ptr(0x5D4594, 1213348 + 4 * v54)) {
				v57 = *getMemU32Ptr(0x5D4594, 1203876 + 8 * v54);
				v58 = *getMemU32Ptr(0x5D4594, 1203876 + 8 * v53) - v57;
				if (v58 < 0) {
					v59 = v57 - *getMemU32Ptr(0x5D4594, 1203876 + 8 * v53);
				LABEL_83:
					v61 = *getMemU32Ptr(0x5D4594, 1203880 + 8 * v54);
					if (*getMemIntPtr(0x5D4594, 1203880 + 8 * v53) - v61 >= 0) {
						v62 = *getMemU32Ptr(0x5D4594, 1203880 + 8 * v53) - v61;
					} else {
						v62 = v61 - *getMemU32Ptr(0x5D4594, 1203880 + 8 * v53);
					}
					if (v59 <= 4 && v62 <= 4) {
						goto LABEL_100;
					}
				LABEL_99:
					*getMemU8Ptr(0x5D4594, 1212324 + v54) = 12;
					goto LABEL_100;
				}
			LABEL_82:
				v59 = v58;
				goto LABEL_83;
			}
		} else {
			if (getMemByte(0x5D4594, 1212324 + v53)) {
			LABEL_89:
				if (v55 == 6 || getMemByte(0x5D4594, 1212324 + v53) == 6) {
					v63 = *getMemU32Ptr(0x5D4594, 1203876 + 8 * v54);
					v64 = *getMemIntPtr(0x5D4594, 1203876 + 8 * v53) - v63 >= 0
							  ? *getMemU32Ptr(0x5D4594, 1203876 + 8 * v53) - v63
							  : v63 - *getMemU32Ptr(0x5D4594, 1203876 + 8 * v53);
					v65 = *getMemU32Ptr(0x5D4594, 1203880 + 8 * v54);
					v66 = *getMemIntPtr(0x5D4594, 1203880 + 8 * v53) - v65 >= 0
							  ? *getMemU32Ptr(0x5D4594, 1203880 + 8 * v53) - v65
							  : v65 - *getMemU32Ptr(0x5D4594, 1203880 + 8 * v53);
					if (v64 <= 4 && v66 <= 4) {
						goto LABEL_100;
					}
				}
				goto LABEL_99;
			}
			if (*getMemU32Ptr(0x5D4594, 1213348 + 4 * v54) != *getMemU32Ptr(0x5D4594, 1213348 + 4 * v53)) {
				v60 = *getMemU32Ptr(0x5D4594, 1203876 + 8 * v54);
				v58 = *getMemU32Ptr(0x5D4594, 1203876 + 8 * v53) - v60;
				if (v58 < 0) {
					v59 = v60 - *getMemU32Ptr(0x5D4594, 1203876 + 8 * v53);
					goto LABEL_83;
				}
				goto LABEL_82;
			}
		}
	LABEL_100:
		v54 = v53++;
	}
	sub_4989A0();
	return sub_4C52E0(getMemIntPtr(0x5D4594, 1203876), *(int*)&dword_5d4594_1217464);
}

//----- (00497180) --------------------------------------------------------
int sub_497180(float* a1, float* a2, float* a3) {
	double v3;  // st7
	double v4;  // st6
	float v5;   // ecx
	double v6;  // st5
	float v7;   // eax
	float v8;   // eax
	int result; // eax
	float v10;  // [esp+4h] [ebp-1Ch]
	float v11;  // [esp+8h] [ebp-18h]
	float v12;  // [esp+14h] [ebp-Ch]

	if (*a1 >= (double)a1[2]) {
		v3 = a1[2];
		v4 = *a1;
	} else {
		v3 = *a1;
		v4 = a1[2];
	}
	if (a1[1] >= (double)a1[3]) {
		v5 = a1[1];
		v12 = a1[3];
	} else {
		v5 = a1[3];
		v12 = a1[1];
	}
	if (*a2 >= (double)a2[2]) {
		v6 = a2[2];
		v7 = *a2;
	} else {
		v6 = *a2;
		v7 = a2[2];
	}
	v11 = v7;
	if (a2[1] >= (double)a2[3]) {
		v10 = a2[3];
		v8 = a2[1];
	} else {
		v10 = a2[1];
		v8 = a2[3];
	}
	if (v6 > v4 || v11 < v3 || v10 > (double)v5 || v8 < (double)v12) {
		result = 0;
	} else {
		result = sub_4278B0(a1, a2, a3);
	}
	return result;
}

//----- (00497260) --------------------------------------------------------
int sub_497260(int* a1) {
	int result; // eax
	int v2;     // esi
	int* v3;    // edi
	double v4;  // st7
	double v5;  // st6
	int v6;     // eax
	double v7;  // st7
	double v8;  // st6
	double v9;  // st7
	double v10; // st6
	float v11;  // [esp+Ch] [ebp-Ch]
	float v12;  // [esp+Ch] [ebp-Ch]
	float v13;  // [esp+Ch] [ebp-Ch]
	float v14;  // [esp+10h] [ebp-8h]
	float v15;  // [esp+10h] [ebp-8h]
	float v16;  // [esp+10h] [ebp-8h]
	float v17;  // [esp+14h] [ebp-4h]
	float v18;  // [esp+14h] [ebp-4h]
	float v19;  // [esp+14h] [ebp-4h]
	float v20;  // [esp+1Ch] [ebp+4h]
	float v21;  // [esp+1Ch] [ebp+4h]
	float v22;  // [esp+1Ch] [ebp+4h]

	result = nox_xxx_sprite_45A030();
	v2 = result;
	if (result) {
		v3 = a1;
		do {
			*(uint32_t*)(v2 + 132) = 0;
			if (!nox_xxx_spriteCheckFlag31_4356C0(v2, 0)) {
				if (*(char*)(v2 + 112) >= 0) {
					v6 = *(uint32_t*)(v2 + 44);
					if (v6 == 2) {
						v7 = (double)*(int*)(v2 + 12);
						v8 = (double)*(int*)(v2 + 16);
						if (v7 - *(float*)(v2 + 48) < (double)(v3[4] + v3[8])) {
							v21 = v7;
							v15 = v21 + *(float*)(v2 + 48);
							if ((double)v3[4] < v15) {
								v12 = v8 - *(float*)(v2 + 48);
								if ((double)(v3[5] + v3[9]) > v12) {
									v18 = v8 + *(float*)(v2 + 48);
									if ((double)v3[5] < v18) {
										sub_497650(*(float*)&v2);
									}
								}
							}
						}
					} else if (v6 == 3) {
						v9 = (double)*(int*)(v2 + 12);
						v10 = (double)*(int*)(v2 + 16);
						if (v9 + *(float*)(v2 + 72) < (double)(v3[4] + v3[8])) {
							v22 = v9;
							v16 = v22 + *(float*)(v2 + 80);
							if ((double)v3[4] < v16) {
								v13 = v10 + *(float*)(v2 + 68);
								if ((double)(v3[5] + v3[9]) > v13) {
									v19 = v10 + *(float*)(v2 + 92);
									if ((double)v3[5] < v19) {
										sub_4977C0(v2);
									}
								}
							}
						}
					}
				} else {
					v4 = (double)*(int*)(v2 + 12);
					v5 = (double)*(int*)(v2 + 16);
					if (v4 - 32.0 < (double)(v3[4] + v3[8])) {
						v20 = v4;
						v14 = v20 + 32.0;
						if ((double)v3[4] < v14) {
							v11 = v5 - 32.0;
							if ((double)(v3[5] + v3[9]) > v11) {
								v17 = v5 + 32.0;
								if ((double)v3[5] < v17) {
									sub_4974B0(v2);
								}
							}
						}
					}
				}
			}
			result = sub_45A040(v2);
			v2 = result;
		} while (result);
	}
	return result;
}

//----- (004974B0) --------------------------------------------------------
void sub_4974B0(int a1) {
	int v1;    // edi
	int v2;    // esi
	int v3;    // ecx
	double v4; // st7
	int v5;    // eax
	int v6;    // eax
	int v7;    // eax
	int v8;    // eax
	int v9;    // eax
	int v10;   // eax
	int v11;   // eax
	int v12;   // ecx
	int v13;   // eax
	float v14; // [esp+0h] [ebp-14h]
	int v15;   // [esp+18h] [ebp+4h]

	v1 = a1;
	if (!(*(uint8_t*)(a1 + 116) & 4)) {
		v2 = sub_4CADD0();
		*(uint8_t*)(v2 + 48) = 1;
		*(uint8_t*)(v2 + 56) = 6;
		*(uint32_t*)(v2 + 20) = a1;
		v3 = 8 * *(unsigned char*)(a1 + 299);
		v4 = (double)(int)(*getMemU32Ptr(0x5D4594, 1217444) - *getMemIntPtr(0x587000, 196184 + v3) / 2 -
						   *(uint32_t*)(a1 + 12));
		v15 = dword_5d4594_1217448 - *getMemIntPtr(0x587000, 196188 + v3) / 2 - *(uint32_t*)(a1 + 16);
		v14 = (double)v15 * (double)v15 + v4 * v4;
		*(uint32_t*)(v2 + 32) = nox_float2int(v14);
		v5 = sub_4CA8B0(*(uint32_t*)(v1 + 16) - dword_5d4594_1217448,
						*(uint32_t*)(v1 + 12) - *getMemU32Ptr(0x5D4594, 1217444));
		*(uint32_t*)(v2 + 40) = v5;
		if (v5 < 0) {
			do {
				v6 = *(uint32_t*)(v2 + 40);
				*(uint32_t*)(v2 + 40) = v6 + 75000;
			} while (v6 + 75000 < 0);
		}
		if (*(int*)(v2 + 40) >= 75000) {
			do {
				v7 = *(uint32_t*)(v2 + 40) - 75000;
				*(uint32_t*)(v2 + 40) = v7;
			} while (v7 >= 75000);
		}
		v8 = sub_4CA8B0(*(uint32_t*)(v1 + 16) + *getMemIntPtr(0x587000, 196188 + 8 * *(unsigned char*)(v1 + 299)) -
							dword_5d4594_1217448,
						*(uint32_t*)(v1 + 12) + *getMemIntPtr(0x587000, 196184 + 8 * *(unsigned char*)(v1 + 299)) -
							*getMemU32Ptr(0x5D4594, 1217444));
		*(uint32_t*)(v2 + 44) = v8;
		if (v8 < 0) {
			do {
				v9 = *(uint32_t*)(v2 + 44);
				*(uint32_t*)(v2 + 44) = v9 + 75000;
			} while (v9 + 75000 < 0);
		}
		if (*(int*)(v2 + 44) >= 75000) {
			do {
				v10 = *(uint32_t*)(v2 + 44) - 75000;
				*(uint32_t*)(v2 + 44) = v10;
			} while (v10 >= 75000);
		}
		v11 = *(uint32_t*)(v2 + 44);
		v12 = *(uint32_t*)(v2 + 40);
		if (v11 < v12) {
			*(uint32_t*)(v2 + 40) = v11;
			*(uint32_t*)(v2 + 44) = v12;
		}
		if ((double)(int)(*(uint32_t*)(v2 + 44) - *(uint32_t*)(v2 + 40)) >= 37500.0) {
			v13 = sub_4CAED0(v2);
			*(uint32_t*)(v13 + 40) = 0;
			*(uint32_t*)(v13 + 44) = *(uint32_t*)(v2 + 40);
			*(uint32_t*)(v2 + 40) = *(uint32_t*)(v2 + 44);
			*(uint32_t*)(v2 + 44) = 74999;
			sub_4CAE90(v13);
		}
		sub_4CAE90(v2);
	}
}

//----- (00497650) --------------------------------------------------------
int sub_497650(float a1) {
	int v1;       // eax
	float v2;     // edi
	uint32_t* v3; // esi
	int v4;       // ecx
	double v5;    // st7
	int v6;       // eax
	int v7;       // ebx
	int v8;       // eax
	int v9;       // ebp
	int v10;      // eax
	int v11;      // eax
	int v12;      // ecx
	int v13;      // edi
	int v14;      // ebp
	int v15;      // eax
	int v16;      // eax
	int v17;      // eax
	int v18;      // ecx
	int v19;      // eax
	float v21;    // [esp+0h] [ebp-1Ch]
	int v22;      // [esp+0h] [ebp-1Ch]
	float v23;    // [esp+14h] [ebp-8h]
	float v24;    // [esp+20h] [ebp+4h]

	v1 = sub_4CADD0();
	v2 = a1;
	v3 = (uint32_t*)v1;
	*(uint8_t*)(v1 + 48) = 1;
	*(uint8_t*)(v1 + 56) = 7;
	*(float*)(v1 + 20) = a1;
	v4 = *(uint32_t*)(LODWORD(a1) + 16);
	v24 = (double)(int)(*(uint32_t*)(LODWORD(a1) + 12) - *getMemU32Ptr(0x5D4594, 1217444));
	v5 = (double)(int)(v4 - dword_5d4594_1217448);
	v23 = v5;
	v21 = v5 * v23 + v24 * v24;
	v6 = nox_float2int(v21);
	v3[8] = v6;
	v7 = (long long)sqrt((double)v6);
	v22 = nox_float2int(v24);
	v8 = nox_float2int(v23);
	v9 = sub_4CA8B0(v8, v22);
	v10 = nox_float2int(*(float*)(LODWORD(v2) + 48));
	v11 = sub_4CA8B0(v10, v7);
	v3[10] = v11 + v9;
	if (v11 + v9 < 0) {
		do {
			v12 = v3[10];
			v3[10] = v12 + 75000;
		} while (v12 + 75000 < 0);
	}
	if (v3[10] >= 75000) {
		do {
			v13 = v3[10] - 75000;
			v3[10] = v13;
		} while (v13 >= 75000);
	}
	v14 = v9 - v11;
	v3[11] = v14;
	if (v14 < 0) {
		do {
			v15 = v3[11];
			v3[11] = v15 + 75000;
		} while (v15 + 75000 < 0);
	}
	if (v3[11] >= 75000) {
		do {
			v16 = v3[11] - 75000;
			v3[11] = v16;
		} while (v16 >= 75000);
	}
	v17 = v3[11];
	v18 = v3[10];
	if (v17 < v18) {
		v3[10] = v17;
		v3[11] = v18;
	}
	if ((double)(v3[11] - v3[10]) >= 37500.0) {
		v19 = sub_4CAED0((int)v3);
		*(uint32_t*)(v19 + 40) = 0;
		*(uint32_t*)(v19 + 44) = v3[10];
		v3[10] = v3[11];
		v3[11] = 74999;
		sub_4CAE90(v19);
	}
	return sub_4CAE90((int)v3);
}

//----- (004977C0) --------------------------------------------------------
int sub_4977C0(int a1) {
	int v1;       // esi
	double v2;    // st7
	double v3;    // st6
	int v4;       // eax
	int v5;       // edi
	int v6;       // eax
	int v7;       // ebp
	int v8;       // eax
	int v9;       // ebx
	int v10;      // eax
	int result;   // eax
	double v12;   // st7
	int v13;      // eax
	double v14;   // st7
	int v15;      // eax
	double v16;   // st7
	int v17;      // eax
	double v18;   // st7
	int v19;      // eax
	double v20;   // st7
	int v21;      // eax
	double v22;   // st7
	int v23;      // eax
	float v24;    // [esp+0h] [ebp-40h]
	float v25;    // [esp+0h] [ebp-40h]
	float v26;    // [esp+0h] [ebp-40h]
	float v27;    // [esp+0h] [ebp-40h]
	float v28;    // [esp+0h] [ebp-40h]
	float v29;    // [esp+0h] [ebp-40h]
	int v30;      // [esp+4h] [ebp-3Ch]
	int v31;      // [esp+4h] [ebp-3Ch]
	int v32;      // [esp+4h] [ebp-3Ch]
	int v33;      // [esp+4h] [ebp-3Ch]
	float v34;    // [esp+1Ch] [ebp-24h]
	float v35;    // [esp+1Ch] [ebp-24h]
	float v36;    // [esp+1Ch] [ebp-24h]
	float v37;    // [esp+1Ch] [ebp-24h]
	float v38[8]; // [esp+20h] [ebp-20h]
	float v39;    // [esp+44h] [ebp+4h]
	int v40;      // [esp+44h] [ebp+4h]

	v1 = a1;
	v2 = (double)*(int*)(a1 + 12);
	v38[0] = v2 + *(float*)(a1 + 64);
	v3 = (double)*(int*)(a1 + 16);
	v39 = v3;
	v38[1] = v3 + *(float*)(v1 + 68);
	v38[2] = v2 + *(float*)(v1 + 72);
	v38[3] = v39 + *(float*)(v1 + 76);
	v38[4] = v2 + *(float*)(v1 + 80);
	v38[5] = v39 + *(float*)(v1 + 84);
	v38[6] = v2 + *(float*)(v1 + 88);
	v38[7] = v39 + *(float*)(v1 + 92);
	v30 = nox_float2int(v38[0]) - *getMemU32Ptr(0x5D4594, 1217444);
	v4 = nox_float2int(v38[1]);
	v5 = sub_4CA8B0(v4 - dword_5d4594_1217448, v30);
	v31 = nox_float2int(v38[2]) - *getMemU32Ptr(0x5D4594, 1217444);
	v6 = nox_float2int(v38[3]);
	v7 = sub_4CA8B0(v6 - dword_5d4594_1217448, v31);
	v32 = nox_float2int(v38[4]) - *getMemU32Ptr(0x5D4594, 1217444);
	v8 = nox_float2int(v38[5]);
	v9 = sub_4CA8B0(v8 - dword_5d4594_1217448, v32);
	v33 = nox_float2int(v38[6]) - *getMemU32Ptr(0x5D4594, 1217444);
	v10 = nox_float2int(v38[7]);
	v40 = sub_4CA8B0(v10 - dword_5d4594_1217448, v33);
	result = (unsigned char)sub_497B80(v38, getMemIntPtr(0x5D4594, 1217444)) - 1;
	switch (result) {
	case 0:
		v35 = (v38[5] + v38[1]) * 0.5;
		v14 = (v38[4] + v38[0]) * 0.5 - (double)*getMemIntPtr(0x5D4594, 1217444);
		v25 = (v35 - (double)*(int*)&dword_5d4594_1217448) * (v35 - (double)*(int*)&dword_5d4594_1217448) + v14 * v14;
		v15 = nox_float2int(v25);
		result = sub_497F60(v5, v9, 9, v15, v1);
		break;
	case 1:
		v37 = (v38[7] + v38[3]) * 0.5;
		v18 = (v38[6] + v38[2]) * 0.5 - (double)*getMemIntPtr(0x5D4594, 1217444);
		v27 = (v37 - (double)*(int*)&dword_5d4594_1217448) * (v37 - (double)*(int*)&dword_5d4594_1217448) + v18 * v18;
		v19 = nox_float2int(v27);
		result = sub_497F60(v40, v7, 10, v19, v1);
		break;
	case 3:
		v34 = (v38[3] + v38[1]) * 0.5;
		v12 = (v38[2] + v38[0]) * 0.5 - (double)*getMemIntPtr(0x5D4594, 1217444);
		v24 = (v34 - (double)*(int*)&dword_5d4594_1217448) * (v34 - (double)*(int*)&dword_5d4594_1217448) + v12 * v12;
		v13 = nox_float2int(v24);
		result = sub_497F60(v5, v7, 8, v13, v1);
		break;
	case 4:
	case 9:
		v22 = (double)(int)(*(uint32_t*)(v1 + 12) - *getMemU32Ptr(0x5D4594, 1217444));
		v29 = (double)(int)(*(uint32_t*)(v1 + 16) - dword_5d4594_1217448) *
				  (double)(int)(*(uint32_t*)(v1 + 16) - dword_5d4594_1217448) +
			  v22 * v22;
		v23 = nox_float2int(v29);
		result = sub_497F60(v7, v9, 14, v23, v1);
		break;
	case 5:
	case 8:
		v20 = (double)(int)(*(uint32_t*)(v1 + 12) - *getMemU32Ptr(0x5D4594, 1217444));
		v28 = (double)(int)(*(uint32_t*)(v1 + 16) - dword_5d4594_1217448) *
				  (double)(int)(*(uint32_t*)(v1 + 16) - dword_5d4594_1217448) +
			  v20 * v20;
		v21 = nox_float2int(v28);
		result = sub_497F60(v5, v40, 13, v21, v1);
		break;
	case 7:
		v36 = (v38[7] + v38[5]) * 0.5;
		v16 = (v38[6] + v38[4]) * 0.5 - (double)*getMemIntPtr(0x5D4594, 1217444);
		v26 = (v36 - (double)*(int*)&dword_5d4594_1217448) * (v36 - (double)*(int*)&dword_5d4594_1217448) + v16 * v16;
		v17 = nox_float2int(v26);
		result = sub_497F60(v40, v9, 11, v17, v1);
		break;
	default:
		return result;
	}
	return result;
}

//----- (00497B80) --------------------------------------------------------
char sub_497B80(float* a1, int* a2) {
	int* v2;   // eax
	float* v3; // ecx
	char v4;   // dl
	double v5; // st7
	float v7;  // [esp+0h] [ebp-4h]
	float v8;  // [esp+8h] [ebp+4h]
	float v9;  // [esp+Ch] [ebp+8h]

	v2 = a2;
	v3 = a1;
	v4 = 0;
	v9 = (double)*a2;
	v7 = (double)v2[1];
	v5 = (a1[5] + a1[4] - v9 - v7) * 0.70709997;
	v8 = (a1[1] + *a1 - v9 - v7) * 0.70709997;
	if ((v3[1] - *v3 + v9 - v7) * 0.70709997 <= 0.0) {
		if ((v3[3] - v3[2] + v9 - v7) * 0.70709997 < 0.0) {
			v4 = 2;
		}
	} else {
		v4 = 1;
	}
	if (v5 < 0.0) {
		return v4 | 8;
	}
	if (v8 > 0.0) {
		v4 |= 4u;
	}
	return v4;
}

//----- (00497C40) --------------------------------------------------------
int nox_xxx_drawBlackofWall_497C40(int a1, int a2, char a3) {
	int v3;      // edi
	int v4;      // ebp
	int v5;      // ebx
	int v6;      // esi
	int v7;      // ecx
	int v8;      // eax
	int v9;      // edi
	int v10;     // ecx
	int v11;     // eax
	int v12;     // eax
	int v13;     // eax
	int v14;     // eax
	int v15;     // eax
	int v16;     // eax
	int v17;     // eax
	int v18;     // ecx
	int v19;     // eax
	int v21;     // [esp+10h] [ebp-10h]
	int v22;     // [esp+14h] [ebp-Ch]
	int v23 = 0; // [esp+18h] [ebp-8h]
	int v24 = 0; // [esp+1Ch] [ebp-4h]

	v21 = 23 * a1;
	v22 = 23 * a2;
	v3 = 23 * a1 + nox_float2int(11.5);
	v4 = 23 * a2 + nox_float2int(11.5);
	v5 = sub_4CADD0();
	*(uint32_t*)(v5 + 24) = a1;
	*(uint8_t*)(v5 + 36) = a3;
	*(uint32_t*)(v5 + 28) = a2;
	*(uint8_t*)(v5 + 48) = 1;
	*(uint8_t*)(v5 + 56) = 0;
	switch (a3) {
	case 1:
		v6 = v3 - *getMemU32Ptr(0x5D4594, 1217444) + nox_float2int(5.75);
		v7 = v4 - dword_5d4594_1217448 - nox_float2int(5.75);
		v8 = v3;
		v9 = 23 * a2;
		v23 = v21 + 23;
		break;
	case 2:
		v6 = v3 - *getMemU32Ptr(0x5D4594, 1217444) - nox_float2int(5.75);
		v7 = v4 - dword_5d4594_1217448 - nox_float2int(5.75);
		v8 = v3;
		v9 = 23 * a2;
		v23 = 23 * a1;
		break;
	case 4:
		v6 = v3 - *getMemU32Ptr(0x5D4594, 1217444) + nox_float2int(5.75);
		v10 = nox_float2int(5.75);
		v8 = v3;
		v7 = v4 - dword_5d4594_1217448 + v10;
		v23 = v21 + 23;
		v9 = v22 + 23;
		break;
	case 6:
		v8 = 23 * a1;
		v7 = v4 - dword_5d4594_1217448;
		v4 = 23 * a2;
		v6 = v3 - *getMemU32Ptr(0x5D4594, 1217444);
		v23 = v21 + 23;
		v9 = v22 + 23;
		break;
	case 8:
		v6 = v3 - *getMemU32Ptr(0x5D4594, 1217444) - nox_float2int(5.75);
		v23 = 23 * a1;
		v7 = v4 - dword_5d4594_1217448 + nox_float2int(5.75);
		v8 = v3;
		v9 = v22 + 23;
		break;
	case 9:
		v6 = v3 - *getMemU32Ptr(0x5D4594, 1217444);
		v7 = v4 - dword_5d4594_1217448;
		v4 = 23 * a2;
		v8 = v21 + 23;
		v23 = 23 * a1;
		v9 = v22 + 23;
		break;
	default:
		v6 = a1;
		v7 = a1;
		v4 = v24;
		v8 = v23;
		v9 = v24;
		break;
	}
	*(uint32_t*)(v5 + 32) = v6 * v6 + v7 * v7;
	v11 = sub_4CA8B0(v4 - dword_5d4594_1217448, v8 - *getMemU32Ptr(0x5D4594, 1217444));
	*(uint32_t*)(v5 + 40) = v11;
	if (v11 < 0) {
		do {
			v12 = *(uint32_t*)(v5 + 40);
			*(uint32_t*)(v5 + 40) = v12 + 75000;
		} while (v12 + 75000 < 0);
	}
	if (*(uint32_t*)(v5 + 40) >= 75000) {
		do {
			v13 = *(uint32_t*)(v5 + 40) - 75000;
			*(uint32_t*)(v5 + 40) = v13;
		} while (v13 >= 75000);
	}
	v14 = sub_4CA8B0(v9 - dword_5d4594_1217448, v23 - *getMemU32Ptr(0x5D4594, 1217444));
	*(uint32_t*)(v5 + 44) = v14;
	if (v14 < 0) {
		do {
			v15 = *(uint32_t*)(v5 + 44);
			*(uint32_t*)(v5 + 44) = v15 + 75000;
		} while (v15 + 75000 < 0);
	}
	if (*(uint32_t*)(v5 + 44) >= 75000) {
		do {
			v16 = *(uint32_t*)(v5 + 44) - 75000;
			*(uint32_t*)(v5 + 44) = v16;
		} while (v16 >= 75000);
	}
	v17 = *(uint32_t*)(v5 + 44);
	v18 = *(uint32_t*)(v5 + 40);
	if (v17 < v18) {
		*(uint32_t*)(v5 + 40) = v17;
		*(uint32_t*)(v5 + 44) = v18;
	}
	if (*(uint32_t*)(v5 + 44) - *(uint32_t*)(v5 + 40) >= 37500) {
		v19 = sub_4CAED0(v5);
		*(uint32_t*)(v19 + 40) = 0;
		*(uint32_t*)(v19 + 44) = *(uint32_t*)(v5 + 40);
		*(uint32_t*)(v5 + 40) = *(uint32_t*)(v5 + 44);
		*(uint32_t*)(v5 + 44) = 74999;
		sub_4CAE90(v19);
	}
	return sub_4CAE90(v5);
}
// 497E2E: variable 'v24' is possibly undefined
// 497E32: variable 'v23' is possibly undefined

//----- (00497F60) --------------------------------------------------------
int sub_497F60(int a1, int a2, char a3, int a4, int a5) {
	int v5;  // esi
	int v6;  // ecx
	int v7;  // edx
	int v8;  // edx
	int v9;  // edx
	int v10; // eax

	v5 = sub_4CADD0();
	*(uint8_t*)(v5 + 56) = a3;
	*(uint32_t*)(v5 + 32) = a4;
	*(uint8_t*)(v5 + 48) = 1;
	*(uint32_t*)(v5 + 20) = a5;
	if (a2 >= a1) {
		*(uint32_t*)(v5 + 40) = a1;
		*(uint32_t*)(v5 + 44) = a2;
	} else {
		*(uint32_t*)(v5 + 40) = a2;
		*(uint32_t*)(v5 + 44) = a1;
	}
	if (*(int*)(v5 + 40) < 0) {
		do {
			v6 = *(uint32_t*)(v5 + 40);
			*(uint32_t*)(v5 + 40) = v6 + 75000;
		} while (v6 + 75000 < 0);
	}
	if (*(uint32_t*)(v5 + 40) >= 75000) {
		do {
			v7 = *(uint32_t*)(v5 + 40) - 75000;
			*(uint32_t*)(v5 + 40) = v7;
		} while (v7 >= 75000);
	}
	if (*(int*)(v5 + 44) < 0) {
		do {
			v8 = *(uint32_t*)(v5 + 44);
			*(uint32_t*)(v5 + 44) = v8 + 75000;
		} while (v8 + 75000 < 0);
	}
	if (*(uint32_t*)(v5 + 44) >= 75000) {
		do {
			v9 = *(uint32_t*)(v5 + 44) - 75000;
			*(uint32_t*)(v5 + 44) = v9;
		} while (v9 >= 75000);
	}
	if (*(int*)(v5 + 44) - *(int*)(v5 + 40) >= 37500) {
		v10 = sub_4CAED0(v5);
		*(uint32_t*)(v10 + 40) = 0;
		*(uint32_t*)(v10 + 44) = *(uint32_t*)(v5 + 40);
		*(uint32_t*)(v5 + 40) = *(uint32_t*)(v5 + 44);
		*(uint32_t*)(v5 + 44) = 74999;
		sub_4CAE90(v10);
	}
	return sub_4CAE90(v5);
}

//----- (00498030) --------------------------------------------------------
int sub_498030(uint32_t* a1) {
	int v1; // esi
	int v2; // edi
	int v3; // ebx
	int v4; // ebp
	int v5; // edi
	int v6; // ebx
	int v7; // esi
	int v9; // [esp+14h] [ebp+4h]

	v1 = a1[4];
	v2 = a1[5];
	v3 = a1[8] + v1;
	v4 = a1[9] + v2;
	v9 = sub_4CA8B0(v2 - dword_5d4594_1217448, v1 - *getMemU32Ptr(0x5D4594, 1217444));
	v5 = sub_4CA8B0(v2 - dword_5d4594_1217448, v3 - *getMemU32Ptr(0x5D4594, 1217444));
	v6 = sub_4CA8B0(v4 - dword_5d4594_1217448, v3 - *getMemU32Ptr(0x5D4594, 1217444));
	v7 = sub_4CA8B0(v4 - dword_5d4594_1217448, v1 - *getMemU32Ptr(0x5D4594, 1217444));
	sub_497F60(v9, v5, 1, 0x7FFFFFFF, 0);
	sub_497F60(v5, v6, 4, 0x7FFFFFFF, 0);
	sub_497F60(v6, v7, 2, 0x7FFFFFFF, 0);
	return sub_497F60(v7, v9, 3, 0x7FFFFFFF, 0);
}

//----- (00498110) --------------------------------------------------------
int sub_498110() {
	int result; // eax

	for (result = sub_4CAEB0(); result; result = sub_4CAEB0()) {
		sub_498130(result);
	}
	return result;
}

//----- (00498130) --------------------------------------------------------
int sub_498130(int a1) {
	int i;  // ebx
	int v2; // esi

	for (i = sub_498290(a1); i < *(int*)&dword_5d4594_1217460; ++i) {
		v2 = *(uint32_t*)(dword_5d4594_1217456 + 4 * i);
		if (*(int*)(v2 + 40) > *(int*)(a1 + 44)) {
			break;
		}
		sub_498380(a1, *(uint32_t*)(dword_5d4594_1217456 + 4 * i));
		if (!*(uint8_t*)(a1 + 48) || *(int*)(a1 + 44) - *(int*)(a1 + 40) < 0) {
			return sub_4CAE40(a1);
		}
		if (!*(uint8_t*)(v2 + 48) || *(int*)(v2 + 44) - *(int*)(v2 + 40) < 0) {
			if (sub_4982E0(v2) <= i) {
				--i;
			}
			sub_4CAE40(v2);
		}
	}
	return sub_4981D0(a1);
}

//----- (004981D0) --------------------------------------------------------
int sub_4981D0(int a1) {
	int v1; // ecx
	int v2; // esi
	int v3; // eax

	v1 = dword_5d4594_1217460 - 1;
	v2 = 0;
	while (v2 <= v1) {
		v3 = (v1 + v2) / 2;
		if (*(int*)(*(uint32_t*)(dword_5d4594_1217456 + 4 * v3) + 40) >= *(int*)(a1 + 40)) {
			v1 = v3 - 1;
		} else {
			v2 = v3 + 1;
		}
	}
	return sub_498220(a1, v2);
}

//----- (00498220) --------------------------------------------------------
int sub_498220(int a1, int a2) {
	if (a2 < *(int*)&dword_5d4594_1217460) {
		memmove(dword_5d4594_1217456 + 4 * a2 + 4, (uint8_t*)(dword_5d4594_1217456 + 4 * a2),
				4 * (dword_5d4594_1217460 + 0x3FFFFFFF * a2));
	}
	*(uint32_t*)(dword_5d4594_1217456 + 4 * a2) = a1;
	return ++dword_5d4594_1217460;
}

//----- (00498290) --------------------------------------------------------
int sub_498290(int a1) {
	int v1;     // esi
	int v2;     // ecx
	int v3;     // eax
	int result; // eax

	v1 = 0;
	v2 = dword_5d4594_1217460 - 1;
	if (*(int*)&dword_5d4594_1217460 - 1 < 0) {
		goto LABEL_11;
	}
	do {
		v3 = (v2 + v1) / 2;
		if (*(int*)(*(uint32_t*)(dword_5d4594_1217456 + 4 * v3) + 44) >= *(int*)(a1 + 40)) {
			v2 = v3 - 1;
		} else {
			v1 = v3 + 1;
		}
	} while (v1 <= v2);
	if (v2 >= 0) {
		result = v2;
	} else {
	LABEL_11:
		result = 0;
	}
	return result;
}

//----- (004982E0) --------------------------------------------------------
int sub_4982E0(int a1) {
	int v1; // esi

	v1 = sub_498330(a1);
	memmove(dword_5d4594_1217456 + 4 * v1, (uint8_t*)(dword_5d4594_1217456 + 4 * (v1 + 1)),
			4 * (dword_5d4594_1217460 + 0x3FFFFFFF * (v1 + 1)));
	--dword_5d4594_1217460;
	return v1;
}

//----- (00498330) --------------------------------------------------------
int sub_498330(int a1) {
	int v1;     // ebx
	int v2;     // edi
	int v3;     // esi
	int result; // eax
	int v5;     // ecx

	v1 = *(uint32_t*)(a1 + 40);
	v2 = 0;
	v3 = dword_5d4594_1217460 - 1;
	while (1) {
		result = (v3 + v2) / 2;
		v5 = *(uint32_t*)(*(uint32_t*)(dword_5d4594_1217456 + 4 * result) + 40);
		if (v5 == v1) {
			break;
		}
		if (v5 >= v1) {
			v3 = (v3 + v2) / 2;
		} else {
			v2 = result + 1;
		}
		if (v2 > v3) {
			nox_exit(-1);
		}
	}
	return result;
}

//----- (00498380) --------------------------------------------------------
void sub_498380(int a1, int a2) {
	int v2;   // ebx
	int v3;   // edx
	int v4;   // ecx
	int v5;   // eax
	int v6;   // ecx
	int v7;   // eax
	int v8;   // ebx
	int v9;   // ecx
	int v10;  // ecx
	int v11;  // esi
	bool v12; // cc
	int v13;  // edx
	int v14;  // eax
	int v15;  // ebx
	int v16;  // ecx
	int v17;  // ecx
	int v18;  // edi
	int v19;  // ecx
	int v20;  // eax
	int v21;  // eax
	int v22;  // ecx

	v2 = *(uint32_t*)(a1 + 40);
	v3 = *(uint32_t*)(a2 + 44);
	if (v3 < v2) {
		return;
	}
	v4 = *(uint32_t*)(a2 + 40);
	v5 = *(uint32_t*)(a1 + 44);
	if (v4 > v5) {
		return;
	}
	if (v4 < v2) {
		if (v3 <= v5) {
			if (*(int*)(a1 + 32) >= *(int*)(a2 + 32)) {
				v6 = *(uint32_t*)(a1 + 44);
				*(uint32_t*)(a1 + 40) = v3 + 1;
				if (v3 + 1 > v6) {
					*(uint8_t*)(a1 + 48) = 0;
				}
			} else {
				*(uint32_t*)(a2 + 44) = v2 - 1;
			}
			return;
		}
		if (*(int*)(a1 + 32) < *(int*)(a2 + 32)) {
			v7 = sub_4CAED0(a2);
			v8 = *(uint32_t*)(v7 + 44);
			v9 = *(uint32_t*)(a1 + 44) + 1;
			*(uint32_t*)(v7 + 40) = v9;
			if (v9 > v8) {
				*(uint8_t*)(v7 + 48) = 0;
			}
			v10 = *(uint32_t*)(a1 + 40) - 1;
			v11 = *(uint32_t*)(a2 + 40);
			*(uint32_t*)(a2 + 44) = v10;
			if (v11 > v10) {
				*(uint8_t*)(a2 + 48) = 0;
			}
			sub_4CAE90(v7);
			return;
		}
	LABEL_27:
		*(uint8_t*)(a1 + 48) = 0;
		return;
	}
	v12 = v3 <= v5;
	v13 = *(uint32_t*)(a1 + 32);
	if (v12) {
		if (v13 >= *(int*)(a2 + 32)) {
			v14 = sub_4CAED0(a1);
			v15 = *(uint32_t*)(v14 + 44);
			v16 = *(uint32_t*)(a2 + 44) + 1;
			*(uint32_t*)(v14 + 40) = v16;
			if (v16 > v15) {
				*(uint8_t*)(v14 + 48) = 0;
			}
			v17 = *(uint32_t*)(a2 + 40) - 1;
			v18 = *(uint32_t*)(a1 + 40);
			*(uint32_t*)(a1 + 44) = v17;
			if (v18 > v17) {
				*(uint8_t*)(a1 + 48) = 0;
			}
			sub_4CAE90(v14);
		} else {
			*(uint8_t*)(a2 + 48) = 0;
		}
	} else {
		if (v13 >= *(int*)(a2 + 32)) {
			v21 = v4 - 1;
			v22 = *(uint32_t*)(a1 + 40);
			*(uint32_t*)(a1 + 44) = v21;
			if (v22 <= v21) {
				return;
			}
			goto LABEL_27;
		}
		v19 = *(uint32_t*)(a2 + 44);
		v20 = v5 + 1;
		*(uint32_t*)(a2 + 40) = v20;
		if (v20 > v19) {
			*(uint8_t*)(a2 + 48) = 0;
		}
	}
}

//----- (004984B0) --------------------------------------------------------
int nox_xxx_client_4984B0_drawable(nox_drawable* dr) {
	int a1 = dr;
	int v1;    // edi
	int v3;    // ebx
	int v4;    // ecx
	int v5;    // kr0C_4
	int v6;    // ebp
	int v7;    // esi
	int v8;    // ebx
	int v9;    // ecx
	int v10;   // edx
	int v11;   // eax
	int v12;   // eax
	int v13;   // ebp
	int v14;   // esi
	int v15;   // ebx
	int v16;   // ecx
	int v17;   // esi
	int v18;   // eax
	int v19;   // ebp
	int v20;   // ecx
	int v21;   // edx
	int* v22;  // esi
	int v23;   // edi
	int v24;   // ebx
	int v25;   // ecx
	int v26;   // edx
	int v27;   // ebp
	int* v28;  // esi
	int v29;   // edi
	int v30;   // ebx
	int v31;   // [esp+10h] [ebp-58h]
	int v32;   // [esp+10h] [ebp-58h]
	char* v33; // [esp+14h] [ebp-54h]
	int v34;   // [esp+18h] [ebp-50h]
	int v35;   // [esp+18h] [ebp-50h]
	int v36;   // [esp+18h] [ebp-50h]
	int v37;   // [esp+1Ch] [ebp-4Ch]
	int v38;   // [esp+1Ch] [ebp-4Ch]
	int v39;   // [esp+20h] [ebp-48h]
	int v40;   // [esp+20h] [ebp-48h]
	int v41;   // [esp+24h] [ebp-44h]
	int v42;   // [esp+28h] [ebp-40h]
	int v43;   // [esp+2Ch] [ebp-3Ch]
	int v44;   // [esp+30h] [ebp-38h]
	int v45;   // [esp+34h] [ebp-34h]
	int4 a1a;  // [esp+38h] [ebp-30h]
	int4 a2;   // [esp+48h] [ebp-20h]
	int4 v48;  // [esp+58h] [ebp-10h]
	int* i;    // [esp+6Ch] [ebp+4h]
	int v50;   // [esp+6Ch] [ebp+4h]
	int v51;   // [esp+6Ch] [ebp+4h]

	v1 = a1;
	if (!*(uint32_t*)(a1 + 300)) {
		return 0;
	}
	if (a1 == *getMemU32Ptr(0x852978, 8)) {
		return 1;
	}
	if ((signed char)*(uint8_t*)(a1 + 112) >= 0) {
		v42 = *(uint32_t*)(a1 + 12);
		v43 = *(uint32_t*)(a1 + 16);
		v6 = *(uint32_t*)(a1 + 12);
	} else {
		if (!(*(uint8_t*)(a1 + 116) & 4)) {
			return *(uint32_t*)(a1 + 132);
		}
		v3 = *(uint32_t*)(a1 + 12);
		v4 = 8 * *(unsigned char*)(a1 + 299);
		v5 = *getMemIntPtr(0x587000, 196184 + v4);
		v6 = v3 + v5 / 2;
		v42 = v3 + v5 / 2;
		v43 = *(uint32_t*)(a1 + 16) + *getMemIntPtr(0x587000, 196188 + v4) / 2;
	}
	if (*(uint32_t*)(a1 + 120) & 0x10000) {
		return *(uint32_t*)(a1 + 132);
	}
	v31 = 0;
	v33 = nox_draw_getViewport_437250();
	v7 = *((uint32_t*)v33 + 4) - *(uint32_t*)v33;
	v44 = v7;
	v8 = *((uint32_t*)v33 + 5) - *((uint32_t*)v33 + 1);
	v45 = v8;
	a1a.field_0 = *(uint32_t*)v33 + *((int*)v33 + 8) / 2;
	a1a.field_4 = *((uint32_t*)v33 + 1) + *((uint32_t*)v33 + 12) + *((int*)v33 + 9) / 2;
	v37 = v6 - v7;
	a1a.field_8 = v6 - v7;
	a1a.field_C = v43 - v8;
	v9 = *getMemU32Ptr(0x5D4594, 1203868 + 8 * dword_5d4594_1217464);
	v10 = *getMemU32Ptr(0x5D4594, 1203872 + 8 * dword_5d4594_1217464);
	if (*(int*)&dword_5d4594_1217464 <= 0) {
		return 1;
	}
	for (i = getMemIntPtr(0x5D4594, 1203880);; i += 2) {
		a2.field_4 = v10;
		a2.field_0 = v9;
		v34 = *(i - 1);
		v11 = *i;
		a2.field_8 = *(i - 1);
		v39 = v11;
		a2.field_C = v11;
		if (sub_427C80(&a1a, &a2)) {
			break;
		}
		v9 = v34;
		v10 = v39;
		if (++v31 >= *(int*)&dword_5d4594_1217464) {
			return 1;
		}
	}
	if (*(uint32_t*)(v1 + 44) == 2) {
		v12 = nox_float2int(*(float*)(v1 + 48));
		v50 = v12;
		if (*(uint16_t*)(v1 + 2)) {
			v35 = *(unsigned short*)(v1 + 6);
			v13 = v6 - (*(unsigned short*)(v1 + 4) >> 1) - v7;
			v14 = v43 + v12 + *(short*)(v1 + 104) - v35 - v8 - nox_float2int(*(float*)(v1 + 96));
			v15 = v13 + *(unsigned short*)(v1 + 4);
			v16 = v14 + v35;
		} else {
			v13 = v6 - v12 - v7;
			v14 = v43 - v12 - v8 - nox_float2int(*(float*)(v1 + 100));
			v15 = v42 + v50 - v44;
			v16 = v43 + v50 + *(short*)(v1 + 104) - v45 - nox_float2int(*(float*)(v1 + 96));
		}
	} else if (*(uint16_t*)(v1 + 2)) {
		v13 = v6 - (*(unsigned short*)(v1 + 4) >> 1) - v7;
		v16 = nox_float2int(*(float*)(v1 + 92)) + v43 + *(short*)(v1 + 104) - v8;
		v14 = v16 - *(unsigned short*)(v1 + 6);
		v15 = v13 + *(unsigned short*)(v1 + 4);
	} else {
		v13 = v37 + nox_float2int(*(float*)(v1 + 72));
		v17 = v43 - v8 - nox_float2int(*(float*)(v1 + 100));
		v14 = nox_float2int(*(float*)(v1 + 68)) + v17;
		v15 = v37 + nox_float2int(*(float*)(v1 + 80));
		v16 = nox_float2int(*(float*)(v1 + 92)) + v43 + *(short*)(v1 + 104) - v45;
	}
	v32 = 0;
	v51 = 0;
	v41 = v13;
	v38 = v14;
	v40 = v15;
	v36 = v16;
	if (v13 < *(int*)v33 || v13 > *((uint32_t*)v33 + 2)) {
		v32 = 1;
	} else {
		v51 = 1;
	}
	if (v14 < *((uint32_t*)v33 + 1) || v14 > *((uint32_t*)v33 + 3)) {
		++v32;
	} else {
		++v51;
	}
	if (v15 < *(int*)v33 || v15 > *((uint32_t*)v33 + 2)) {
		++v32;
	} else {
		++v51;
	}
	if (v16 < *((uint32_t*)v33 + 1) || v16 > *((uint32_t*)v33 + 3)) {
		++v32;
	} else {
		++v51;
	}
	if (*(uint16_t*)(v1 + 2)) {
		if (v15 - v13 > 6) {
			v13 += 3;
			v15 -= 3;
		}
		if (v16 - v14 >= 22) {
			v14 += 11;
			v16 -= 11;
		}
	}
	if (!v51 || !v32) {
		return 0;
	}
	v48.field_0 = a1a.field_0;
	v48.field_4 = a1a.field_4;
	if (v41 >= *(int*)v33) {
		if (v40 <= *((uint32_t*)v33 + 2)) {
			goto LABEL_50;
		}
		v48.field_8 = v13;
		a1a.field_8 = v13;
	} else {
		v48.field_8 = v15;
		a1a.field_8 = v15;
	}
	a1a.field_C = v14;
	v48.field_C = v16;
LABEL_50:
	if (v38 >= *((uint32_t*)v33 + 1)) {
		if (v36 <= *((uint32_t*)v33 + 3)) {
			goto LABEL_55;
		}
		a1a.field_8 = v13;
		v48.field_C = v14;
		a1a.field_C = v14;
	} else {
		a1a.field_8 = v13;
		v48.field_C = v16;
		a1a.field_C = v16;
	}
	v48.field_8 = v15;
LABEL_55:
	v18 = dword_5d4594_1217464;
	v19 = 0;
	v20 = *getMemU32Ptr(0x5D4594, 1203868 + 8 * dword_5d4594_1217464);
	v21 = *getMemU32Ptr(0x5D4594, 1203872 + 8 * dword_5d4594_1217464);
	if (*(int*)&dword_5d4594_1217464 <= 0) {
	LABEL_59:
		v25 = *getMemU32Ptr(0x5D4594, 1203868 + 8 * v18);
		v26 = *getMemU32Ptr(0x5D4594, 1203872 + 8 * v18);
		v27 = 0;
		if (v18 <= 0) {
			return 1;
		}
		v28 = getMemIntPtr(0x5D4594, 1203880);
		while (1) {
			v29 = *(v28 - 1);
			v30 = *v28;
			a2.field_0 = v25;
			a2.field_4 = v26;
			a2.field_8 = v29;
			a2.field_C = v30;
			if (sub_427C80(&v48, &a2)) {
				break;
			}
			++v27;
			v28 += 2;
			v25 = v29;
			v26 = v30;
			if (v27 >= *(int*)&dword_5d4594_1217464) {
				return 1;
			}
		}
	} else {
		v22 = getMemIntPtr(0x5D4594, 1203880);
		while (1) {
			v23 = *(v22 - 1);
			v24 = *v22;
			a2.field_4 = v21;
			a2.field_0 = v20;
			a2.field_8 = v23;
			a2.field_C = v24;
			if (sub_427C80(&a1a, &a2)) {
				break;
			}
			v18 = dword_5d4594_1217464;
			++v19;
			v22 += 2;
			v20 = v23;
			v21 = v24;
			if (v19 >= *(int*)&dword_5d4594_1217464) {
				goto LABEL_59;
			}
		}
	}
	return 0;
}

//----- (004989A0) --------------------------------------------------------
void sub_4989A0() {
	int v0;             // ebp
	unsigned char* v1;  // edx
	int v2;             // eax
	int v3;             // ecx
	int v4;             // esi
	int v5;             // edi
	int v6;             // ebx
	int v7;             // [esp+0h] [ebp-24h]
	unsigned char* v8;  // [esp+4h] [ebp-20h]
	unsigned char* v9;  // [esp+8h] [ebp-1Ch]
	int v10;            // [esp+Ch] [ebp-18h]
	unsigned char* v11; // [esp+10h] [ebp-14h]
	int v12;            // [esp+14h] [ebp-10h]
	int v13;            // [esp+18h] [ebp-Ch]
	unsigned char* i;   // [esp+1Ch] [ebp-8h]
	unsigned char v15;  // [esp+20h] [ebp-4h]

	if (dword_5d4594_1217464 > 2) {
		v0 = 2;
		v1 = getMemAt(0x5D4594, 1203896);
		v12 = *getMemU32Ptr(0x5D4594, 1203876);
		v2 = *getMemU32Ptr(0x5D4594, 1203884);
		v13 = *getMemU32Ptr(0x5D4594, 1203880);
		v3 = *getMemU32Ptr(0x5D4594, 1203888);
		v10 = 2;
		v7 = 1;
		v9 = getMemAt(0x5D4594, 1213352);
		v8 = getMemAt(0x5D4594, 1203888);
		v11 = getMemAt(0x5D4594, 1213356);
		for (i = getMemAt(0x5D4594, 1203896);; i += 8) {
			v4 = *((uint32_t*)v1 - 1);
			v5 = *(uint32_t*)v1;
			v15 = getMemByte(0x5D4594, 1212324 + v0);
			if ((v12 - v2) * (*(uint32_t*)v1 - v3) != (v13 - v3) * (v4 - v2)) {
				break;
			}
			v6 = v7;
			if (getMemByte(0x5D4594, 1212324 + v10) != getMemByte(0x5D4594, 1212324 + v7)) {
				goto LABEL_7;
			}
		LABEL_8:
			v0 = v10 + 1;
			*((uint32_t*)v8 - 1) = v4;
			*(uint32_t*)v8 = v5;
			v10 = v0;
			*getMemU8Ptr(0x5D4594, 1212324 + v6) = v15;
			*(uint32_t*)v9 = *(uint32_t*)v11;
			v3 = v5;
			v2 = v4;
			v1 = i + 8;
			v11 += 4;
			if (v0 >= *(int*)&dword_5d4594_1217464) {
				dword_5d4594_1217464 = v6 + 1;
				return;
			}
		}
		v6 = v7;
	LABEL_7:
		v7 = ++v6;
		v8 += 8;
		v12 = v2;
		v9 += 4;
		v13 = v3;
		goto LABEL_8;
	}
}

//----- (00498AE0) --------------------------------------------------------
void sub_498AE0() {
	int v0; // ecx
	int v1; // esi
	int i;  // eax

	nox_client_drawEnableAlpha_434560(1);
	nox_set_color_rgb_434430(0, 0, 0);
	v0 = dword_5d4594_1217464;
	v1 = 0;
	for (i = dword_5d4594_1217464 - 1; v1 < v0; ++v1) {
		if (getMemByte(0x5D4594, 1212324 + i) == 12) {
			sub_498B50(*getMemU32Ptr(0x5D4594, 1203876 + 8 * i), *getMemU32Ptr(0x5D4594, 1203880 + 8 * i),
					   *getMemU32Ptr(0x5D4594, 1203876 + 8 * v1), *getMemU32Ptr(0x5D4594, 1203880 + 8 * v1));
			v0 = dword_5d4594_1217464;
		}
		i = v1;
	}
	nox_client_drawEnableAlpha_434560(0);
}

//----- (00498B50) --------------------------------------------------------
int sub_498B50(int a1, int a2, int a3, int a4) {
	int v4;            // ebp
	int v5;            // esi
	int v6;            // edi
	int v7;            // ecx
	int v8;            // eax
	int v9;            // ebx
	int v10;           // edx
	int v11;           // eax
	int v12;           // ebx
	int v13;           // ebp
	int result;        // eax
	unsigned char v15; // [esp+14h] [ebp+4h]
	int v16;           // [esp+18h] [ebp+8h]
	int v17;           // [esp+1Ch] [ebp+Ch]
	int v18;           // [esp+20h] [ebp+10h]

	v4 = a3;
	v5 = a1;
	v6 = a2;
	v7 = a2 - a4;
	v8 = a1 - a3;
	v9 = a1 - a3;
	v10 = a4 - a2;
	if (a1 - a3 < 0) {
		v8 = a3 - a1;
	}
	if (v7 < 0) {
		v7 = a4 - a2;
	}
	if (v8 <= v7) {
		v16 = 0;
		v17 = v10 < 0 ? 1 : -1;
	} else {
		v17 = 0;
		v11 = (v9 < 0) - 1;
		LOBYTE(v11) = v11 & 0xFE;
		v16 = v11 + 1;
	}
	v15 = -48;
	v12 = a4 - v6;
	v13 = v4 - v5;
	v18 = 10;
	do {
		nox_client_drawSetAlpha_434580(v15);
		v15 -= 20;
		nox_client_drawAddPoint_49F500(v5, v6);
		nox_client_drawAddPoint_49F500(v5 + v13, v12 + v6);
		nox_client_drawLineFromPoints_49E4B0();
		v5 += v17;
		v6 += v16;
		result = --v18;
	} while (v18);
	return result;
}

//----- (00498C20) --------------------------------------------------------
int sub_498C20(int2* a1, int2* a2, int a3) {
	int2* v3;           // edi
	int2* v4;           // ebp
	char v5;            // al
	char v6;            // bl
	int v7;             // eax
	int v8;             // edx
	int* v9;            // ecx
	int v10;            // eax
	int v11;            // ebp
	int v12;            // edx
	int v13;            // ebp
	int v14;            // edx
	int v15;            // eax
	int v16;            // esi
	int v17;            // eax
	int v18;            // ecx
	bool v19;           // cc
	float v21;          // [esp+0h] [ebp-44h]
	float v22;          // [esp+0h] [ebp-44h]
	float v23;          // [esp+0h] [ebp-44h]
	float v24;          // [esp+0h] [ebp-44h]
	float v25;          // [esp+0h] [ebp-44h]
	float v26;          // [esp+0h] [ebp-44h]
	float v27;          // [esp+4h] [ebp-40h]
	float v28;          // [esp+14h] [ebp-30h]
	float v29 = 0;      // [esp+18h] [ebp-2Ch]
	float v30;          // [esp+1Ch] [ebp-28h]
	int v31 = 0;        // [esp+20h] [ebp-24h]
	int v32;            // [esp+24h] [ebp-20h]
	unsigned char* v33; // [esp+28h] [ebp-1Ch]
	int2 a1a;           // [esp+2Ch] [ebp-18h]
	int2 a2a;           // [esp+34h] [ebp-10h]
	int2 a3a;           // [esp+3Ch] [ebp-8h]
	char v37;           // [esp+48h] [ebp+4h]
	char v38;           // [esp+50h] [ebp+Ch]
	float v39;          // [esp+50h] [ebp+Ch]

	v3 = a1;
	if (!a1) {
		return 0;
	}
	v4 = a2;
	if (!a2) {
		return 0;
	}
	if (!a3) {
		return 0;
	}
	dword_5d4594_1217452 = 0;
	v5 = sub_4990D0(a1, a2);
	v6 = v5;
	v37 = v5;
	if (!v5) {
		return 0;
	}
	if (v5 != 4 && v5 != 8) {
		v29 = (double)(a2->field_4 - v3->field_4) / (double)(a2->field_0 - v3->field_0);
		v27 = (double)v3->field_0 * v29;
		v31 = v3->field_4 - nox_float2int(v27);
	}
	v7 = dword_5d4594_1217464;
	v8 = 0;
	v32 = 0;
	if (dword_5d4594_1217464 > 0) {
		v9 = getMemIntPtr(0x5D4594, 1203884);
		v33 = getMemAt(0x5D4594, 1203884);
		while (1) {
			a2a = *((int2*)v9 - 1);
			if (v8 == v7 - 1) {
				a3a = *(int2*)getMemAt(0x5D4594, 1203876);
			} else {
				v10 = v9[1];
				a3a.field_0 = *v9;
				a3a.field_4 = v10;
			}
			v38 = sub_4990D0(&a2a, &a3a);
			if (v38 &&
				(!(v6 & 1) || a2a.field_0 <= v3->field_0 || a2a.field_0 <= v4->field_0 || a3a.field_0 <= v3->field_0 ||
				 a3a.field_0 <= v4->field_0) &&
				(!(v37 & 2) || a2a.field_0 >= v3->field_0 || a2a.field_0 >= v4->field_0 ||
				 a3a.field_0 >= v3->field_0)) {
				if (!(v37 & 4) || (v11 = v3->field_4, a2a.field_4 <= v11) || (v12 = a2->field_4, a2a.field_4 <= v12) ||
					a3a.field_4 <= v11 || a3a.field_4 <= v12) {
					if (!(v37 & 8) || (v13 = v3->field_4, a2a.field_4 >= v13) ||
						(v14 = a2->field_4, a2a.field_4 >= v14) || a3a.field_4 >= v13 || a3a.field_4 >= v14) {
						if (a2a.field_0 == a3a.field_0) {
							if (v37 == 4 || v37 == 8) {
								goto LABEL_65;
							}
							if (v37 != 1 && v37 != 2) {
								a1a.field_0 = a2a.field_0;
								v26 = (double)a2a.field_0 * v29;
								a1a.field_4 = v31 + nox_float2int(v26);
							LABEL_59:
								if (sub_499160(&a1a, &a2a, &a3a) && sub_499160(&a1a, v3, a2)) {
									sub_499130(&a1a.field_0);
								}
								goto LABEL_65;
							}
							a1a.field_4 = v3->field_0;
							a1a.field_0 = a2a.field_0;
							if (sub_499160(&a1a, &a2a, &a3a) && sub_499160(&a1a, v3, a2)) {
							LABEL_64:
								sub_499130(&a1a.field_0);
								goto LABEL_65;
							}
						} else {
							v28 = (double)(a3a.field_4 - a2a.field_4) / (double)(a3a.field_0 - a2a.field_0);
							v21 = (double)a2a.field_0 * v28;
							v15 = nox_float2int(v21);
							v16 = a2a.field_4 - v15;
							if (v37 == 4 || v37 == 8) {
								if (v38 == 1 || v38 == 2) {
									a1a.field_0 = v3->field_0;
									a1a.field_4 = a2a.field_0;
									if (sub_499160(&a1a, &a2a, &a3a) && sub_499160(&a1a, v3, a2)) {
										sub_499130(&a1a.field_0);
									}
								} else {
									a1a.field_0 = v3->field_0;
									v22 = (double)a1a.field_0 * v28;
									a1a.field_4 = v16 + nox_float2int(v22);
									if (sub_499160(&a1a, &a2a, &a3a) && sub_499160(&a1a, v3, a2)) {
										sub_499130(&a1a.field_0);
									}
								}
							}
							if (v37 == 1 || v37 == 2) {
								if (v38 == 1 || v38 == 2) {
									goto LABEL_65;
								}
								v25 = (double)(v31 - v16) / v28;
								v17 = nox_float2int(v25);
								v18 = v3->field_4;
								a1a.field_0 = v17;
								a1a.field_4 = v18;
								goto LABEL_59;
							}
							if (v29 != v28) {
								v39 = (double)(v31 - v16);
								v30 = v28 - v29;
								v23 = v39 / v30;
								a1a.field_0 = nox_float2int(v23);
								v24 = v39 * v28 / v30;
								a1a.field_4 = v16 + nox_float2int(v24);
								if (sub_499160(&a1a, &a2a, &a3a) && sub_499160(&a1a, v3, a2)) {
									goto LABEL_64;
								}
							}
						}
					}
				}
			}
		LABEL_65:
			v7 = dword_5d4594_1217464;
			v8 = v32 + 1;
			v9 = (int*)(v33 + 8);
			v19 = ++v32 < *(int*)&dword_5d4594_1217464;
			v33 += 8;
			if (!v19) {
				break;
			}
			v6 = v37;
			v4 = a2;
		}
	}
	sub_4991E0(v3);
	return dword_5d4594_1217452;
}
// 498EE0: variable 'v29' is possibly undefined
// 498EFA: variable 'v31' is possibly undefined

//----- (004990D0) --------------------------------------------------------
char sub_4990D0(uint32_t* a1, uint32_t* a2) {
	int v2;      // ecx
	int v3;      // edx
	char result; // al
	int v5;      // ecx
	int v6;      // edx
	int v7;      // ecx
	int v8;      // edx

	if (*a1 <= *a2) {
		if (*a1 >= *a2) {
			v7 = a1[1];
			v8 = a2[1];
			if (v7 <= v8) {
				if (v7 >= v8) {
					result = 0;
				} else {
					result = 8;
				}
			} else {
				result = 4;
			}
		} else {
			v5 = a1[1];
			v6 = a2[1];
			result = 2;
			if (v5 <= v6) {
				if (v5 < v6) {
					result = 10;
				}
			} else {
				result = 6;
			}
		}
	} else {
		v2 = a1[1];
		v3 = a2[1];
		result = 1;
		if (v2 <= v3) {
			if (v2 < v3) {
				result = 9;
			}
		} else {
			result = 5;
		}
	}
	return result;
}

//----- (00499130) --------------------------------------------------------
int sub_499130(int* a1) {
	int result; // eax

	result = dword_5d4594_1217452;
	if (*(int*)&dword_5d4594_1217452 < 32) {
		result = dword_5d4594_1217452 + 1;
		*getMemU32Ptr(0x5D4594, 1212060 + 8 * result) = *a1;
		*getMemU32Ptr(0x5D4594, 1212064 + 8 * result) = a1[1];
		dword_5d4594_1217452 = result;
	}
	return result;
}

//----- (00499160) --------------------------------------------------------
int sub_499160(int2* a1, int2* a2, int2* a3) {
	int v3;     // edi
	int v4;     // esi
	int v5;     // eax
	int v6;     // edx
	int v7;     // ecx
	int result; // eax

	v3 = a3->field_0;
	if (a3->field_0 > a2->field_0) {
		v4 = a3->field_4;
		if (v4 > a2->field_4) {
			v3 = a3->field_0;
			v6 = a2->field_0;
			v4 = a2->field_4;
			v5 = a3->field_4;
		} else {
			v6 = a2->field_0;
			v5 = a2->field_4;
		}
	} else {
		v4 = a2->field_4;
		if (a3->field_4 > v4) {
			v6 = a3->field_0;
			v3 = a2->field_0;
			v5 = a3->field_4;
		} else {
			v5 = a2->field_4;
			v6 = a3->field_0;
			v4 = a3->field_4;
			v3 = a2->field_0;
		}
	}
	result = 0;
	if (a1->field_0 >= v6 && a1->field_0 <= v3) {
		v7 = a1->field_4;
		if (v7 >= v4 && v7 <= v5) {
			result = 1;
		}
	}
	return result;
}

//----- (004991E0) --------------------------------------------------------
void sub_4991E0(uint32_t* a1) {
	int v1;            // ebp
	uint32_t* v2;      // ebx
	int v3;            // esi
	unsigned char* v4; // edx
	int v5;            // edi
	int v6;            // edi
	uint32_t* v7;      // ecx
	int v8;            // eax
	int v9;            // eax
	int v10;           // esi
	int v11;           // eax
	int v12;           // [esp+4h] [ebp-4h]
	int v13;           // [esp+Ch] [ebp+4h]

	v1 = dword_5d4594_1217452;
	if (dword_5d4594_1217452 > 0) {
		v2 = a1;
		v3 = 1;
		v12 = 1;
		v4 = getMemAt(0x5D4594, 1212068);
		do {
			v5 = *((uint32_t*)v4 + 1) - v2[1];
			v6 = (*(uint32_t*)v4 - *v2) * (*(uint32_t*)v4 - *v2) + v5 * v5;
			if (v3 < v1) {
				v7 = v4 + 8;
				v13 = v1 - v3;
				do {
					v8 = v7[1] - v2[1];
					v9 = (*v7 - *v2) * (*v7 - *v2) + v8 * v8;
					if (v9 < v6) {
						v10 = *((uint32_t*)v4 + 1);
						v6 = v9;
						v11 = *(uint32_t*)v4;
						*(uint32_t*)v4 = *v7;
						*((uint32_t*)v4 + 1) = v7[1];
						*v7 = v11;
						v7[1] = v10;
					}
					v7 += 2;
					--v13;
				} while (v13);
				v1 = dword_5d4594_1217452;
				v3 = v12;
			}
			++v3;
			v4 += 8;
			v12 = v3;
		} while (v3 - 1 < v1);
	}
}

//----- (00499290) --------------------------------------------------------
uint64_t sub_499290(int a1) {
	long long result; // rax

	LODWORD(result) = *getMemU32Ptr(0x5D4594, 1212068 + 8 * a1);
	HIDWORD(result) = *getMemU32Ptr(0x5D4594, 1212072 + 8 * a1);
	return result;
}

//----- (004992B0) --------------------------------------------------------
int sub_4992B0(int a1, int a2) {
	int result; // eax
	int v3;     // ecx
	int v4;     // ebp
	int v5;     // ecx
	int v6;     // edx
	int v7;     // [esp+0h] [ebp-8h]
	int v8;     // [esp+4h] [ebp-4h]

	result = 0;
	v7 = 0;
	v8 = 0;
	if (*(int*)&dword_5d4594_1217464 > 0) {
		v3 = 8 * *(int*)&dword_5d4594_1217464 - 8;
		do {
			v4 = *getMemIntPtr(0x5D4594, 1203876 + v3);
			v5 = *getMemIntPtr(0x5D4594, 1203880 + v3);
			v6 = *getMemIntPtr(0x5D4594, 1203880 + 8 * v8);
			if (v6 > a2) {
				if (v5 > a2) {
					goto LABEL_11;
				}
			} else if (a2 < v5) {
				goto LABEL_8;
			}
			if (a2 < v6) {
			LABEL_8:
				if (a1 >= *getMemIntPtr(0x5D4594, 1203876 + 8 * v8) +
							  (a2 - v6) * (v4 - *getMemIntPtr(0x5D4594, 1203876 + 8 * v8)) / (v5 - v6)) {
					result = v7;
				} else {
					result = !v7;
					v7 = !v7;
				}
			}
		LABEL_11:
			v3 = 8 * v8++;
		} while (v8 < *(int*)&dword_5d4594_1217464);
	}
	return result;
}

//----- (00499360) --------------------------------------------------------
int nox_xxx_loadReflSheild_499360() {
	int v0;            // eax
	int v1;            // eax
	int v2;            // eax
	int v3;            // eax
	int v4;            // eax
	int v5;            // eax
	int v6;            // eax
	int v7;            // eax
	unsigned char* v8; // eax

	v0 = nox_xxx_getTTByNameSpriteMB_44CFC0("ReflectiveShieldNW");
	*getMemU32Ptr(0x5D4594, 1217468) = nox_new_drawable_for_thing(v0);
	v1 = nox_xxx_getTTByNameSpriteMB_44CFC0("ReflectiveShieldN");
	*getMemU32Ptr(0x5D4594, 1217472) = nox_new_drawable_for_thing(v1);
	v2 = nox_xxx_getTTByNameSpriteMB_44CFC0("ReflectiveShieldNE");
	*getMemU32Ptr(0x5D4594, 1217476) = nox_new_drawable_for_thing(v2);
	v3 = nox_xxx_getTTByNameSpriteMB_44CFC0("ReflectiveShieldW");
	*getMemU32Ptr(0x5D4594, 1217480) = nox_new_drawable_for_thing(v3);
	*getMemU32Ptr(0x5D4594, 1217484) = 0;
	v4 = nox_xxx_getTTByNameSpriteMB_44CFC0("ReflectiveShieldE");
	*getMemU32Ptr(0x5D4594, 1217488) = nox_new_drawable_for_thing(v4);
	v5 = nox_xxx_getTTByNameSpriteMB_44CFC0("ReflectiveShieldSW");
	*getMemU32Ptr(0x5D4594, 1217492) = nox_new_drawable_for_thing(v5);
	v6 = nox_xxx_getTTByNameSpriteMB_44CFC0("ReflectiveShieldS");
	*getMemU32Ptr(0x5D4594, 1217496) = nox_new_drawable_for_thing(v6);
	v7 = nox_xxx_getTTByNameSpriteMB_44CFC0("ReflectiveShieldSE");
	*getMemU32Ptr(0x5D4594, 1217500) = nox_new_drawable_for_thing(v7);
	v8 = getMemAt(0x5D4594, 1217468);
	while (v8 == getMemAt(0x5D4594, 1217484)) {
	LABEL_5:
		v8 += 4;
		if ((int)v8 >= (int)getMemAt(0x5D4594, 1217504)) {
			*getMemU32Ptr(0x5D4594, 1217504) = 0;
			return 1;
		}
	}
	if (*(uint32_t*)v8) {
		*(uint32_t*)(*(uint32_t*)v8 + 120) |= 0x1000000u;
		goto LABEL_5;
	}
	return 0;
}

//----- (00499450) --------------------------------------------------------
int sub_499450() {
	unsigned char* v0; // esi
	int result;        // eax

	v0 = getMemAt(0x5D4594, 1217468);
	do {
		result = *(uint32_t*)v0;
		if (*(uint32_t*)v0) {
			result = nox_xxx_spriteDelete_45A4B0(*(uint64_t**)v0);
		}
		*(uint32_t*)v0 = 0;
		v0 += 4;
	} while ((int)v0 < (int)getMemAt(0x5D4594, 1217504));
	*getMemU32Ptr(0x5D4594, 1217504) = 0;
	return result;
}

//----- (00499810) --------------------------------------------------------
int nox_xxx_drawShield_499810(nox_draw_viewport_t* vp, nox_drawable* dr) {
	int a1 = vp;
	int a2 = dr;
	int v3; // [esp-4h] [ebp-8h]

	*(uint32_t*)(*getMemU32Ptr(0x5D4594, 1217468 + 4 * *(unsigned char*)(a2 + 297)) + 12) =
		*(uint32_t*)(a2 + 12) + *getMemU32Ptr(0x587000, 161776 + 8 * *(unsigned char*)(a2 + 297));
	*(uint32_t*)(*getMemU32Ptr(0x5D4594, 1217468 + 4 * *(unsigned char*)(a2 + 297)) + 16) =
		*(uint32_t*)(a2 + 16) + *(short*)(a2 + 104) + *getMemU32Ptr(0x587000, 161780 + 8 * *(unsigned char*)(a2 + 297));
	v3 = *getMemU32Ptr(0x5D4594, 1217468 + 4 * *(unsigned char*)(a2 + 297));
	(*(void (**)(int, int))(v3 + 300))(a1, v3);
	return 0;
}

//----- (00499880) --------------------------------------------------------
uint32_t* nox_xxx_fxDrawTurnUndead_499880(short* a1) {
	int i;            // ebx
	uint32_t* result; // eax
	uint32_t* v3;     // esi
	int v4;           // eax
	double v5;        // st7

	if (!*getMemU32Ptr(0x5D4594, 1217508)) {
		*getMemU32Ptr(0x5D4594, 1217508) = nox_xxx_getTTByNameSpriteMB_44CFC0("UndeadKiller");
	}
	for (i = 0; i < 256; i += 6) {
		result = (uint32_t*)nox_xxx_spriteLoadAdd_45A360_drawable(*getMemIntPtr(0x5D4594, 1217508), *a1, a1[1]);
		v3 = result;
		if (result) {
			v4 = 8 * (short)i;
			*((uint16_t*)v3 + 254) = i;
			*((float*)v3 + 117) = *getMemFloatPtr(0x587000, 194136 + v4) * 4.0;
			v5 = *getMemFloatPtr(0x587000, 194140 + v4) * 4.0;
			v3[119] = 0;
			*((float*)v3 + 118) = v5;
			v3[79] = nox_frame_xxx_2598000;
			v3[81] = *a1;
			v3[82] = a1[1];
			v3[115] = nox_xxx_sprite_4CA540;
			nox_xxx_spriteToList_49BC80_drawable(v3);
			result = nox_xxx_spriteToSightDestroyList_49BAB0_drawable(v3);
		}
	}
	return result;
}

//----- (00499CF0) --------------------------------------------------------
void nox_xxx_bookRewardCli_499CF0(int* a1, int a2, int a3) {
	unsigned int result; // eax
	int v4;              // esi
	int2 a3a;            // [esp+8h] [ebp-8h]

	if (!nox_common_gameFlags_check_40A5C0(2048) ||
		(result = nox_xxx_bookGet_430B40_get_mouse_prev_seq() - *getMemU32Ptr(0x5D4594, 1217504), result >= 2)) {
		*getMemU32Ptr(0x5D4594, 1217504) = nox_xxx_bookGet_430B40_get_mouse_prev_seq();
		if (a1 == (int*)2) {
			v4 = 0;
		} else {
			v4 = (a1 == (int*)3) + 2;
		}
		a3a.field_0 = 5;
		a3a.field_4 = nox_win_height / 3;
		nox_xxx_bookSetForward_45D200(a1, a2, &a3a);
		nox_xxx_draw_499E70(v4, a3a.field_0, a3a.field_4, 271, 166, 1, 1);
		nox_xxx_draw_499E70(v4, a3a.field_0, a3a.field_4, 135, 166, 2, 1);
		nox_xxx_draw_499E70(v4, a3a.field_0, a3a.field_4 + 166, 135, 166, 2, 1);
		nox_xxx_draw_499E70(v4, a3a.field_0 + 271, a3a.field_4, 271, 166, 1, 2);
		nox_xxx_draw_499E70(v4, a3a.field_0 + 135, a3a.field_4, 135, 166, 2, 2);
		nox_xxx_draw_499E70(v4, a3a.field_0 + 135, a3a.field_4 + 166, 135, 166, 2, 2);
		if (a1 != (int*)4 && a3 == 1) {
			nox_xxx_bookFillAll_45D570((int)a1, a2);
		}
	}
}

//----- (00499F60) --------------------------------------------------------
uint32_t* sub_499F60(int a1, int a2, int a3, short a4, char a5, char a6, char a7, char a8, char a9, int a10) {
	uint32_t* result; // eax
	int v11;          // edx
	int v12;          // ecx
	uint32_t* v13;    // esi
	int v14;          // eax

	if (!*getMemU32Ptr(0x5D4594, 1217512)) {
		*getMemU32Ptr(0x5D4594, 1217512) = nox_xxx_getTTByNameSpriteMB_44CFC0("RedBubbleParticle");
		*getMemU32Ptr(0x5D4594, 1217516) = nox_xxx_getTTByNameSpriteMB_44CFC0("WhiteBubbleParticle");
		*getMemU32Ptr(0x5D4594, 1217520) = nox_xxx_getTTByNameSpriteMB_44CFC0("LightBlueBubbleParticle");
		*getMemU32Ptr(0x5D4594, 1217524) = nox_xxx_getTTByNameSpriteMB_44CFC0("OrangeBubbleParticle");
		*getMemU32Ptr(0x5D4594, 1217528) = nox_xxx_getTTByNameSpriteMB_44CFC0("GreenBubbleParticle");
		*getMemU32Ptr(0x5D4594, 1217532) = nox_xxx_getTTByNameSpriteMB_44CFC0("VioletBubbleParticle");
		*getMemU32Ptr(0x5D4594, 1217536) = nox_xxx_getTTByNameSpriteMB_44CFC0("LightVioletBubbleParticle");
		*getMemU32Ptr(0x5D4594, 1217540) = nox_xxx_getTTByNameSpriteMB_44CFC0("YellowBubbleParticle");
	}
	result = (uint32_t*)nox_xxx_spriteLoadAdd_45A360_drawable(a1, a2, a3);
	v13 = result;
	if (result) {
		BYTE1(v11) = HIBYTE(a4);
		LOBYTE(result) = *((uint8_t*)result + 160);
		LOBYTE(v12) = *((uint8_t*)v13 + 156);
		*((uint16_t*)v13 + 52) = a4;
		LOBYTE(v11) = *((uint8_t*)v13 + 152);
		v13[108] = nox_color_rgb_4344A0(v11, v12, (int)result);
		if (a1 == *getMemU32Ptr(0x5D4594, 1217512)) {
			v14 = nox_color_rgb_4344A0(255, 128, 128);
		} else if (a1 == *getMemU32Ptr(0x5D4594, 1217516)) {
			v14 = nox_color_rgb_4344A0(255, 255, 255);
		} else if (a1 == *getMemU32Ptr(0x5D4594, 1217524)) {
			v14 = nox_color_rgb_4344A0(255, 100, 50);
		} else if (a1 == *getMemU32Ptr(0x5D4594, 1217528)) {
			v14 = nox_color_rgb_4344A0(64, 255, 64);
		} else if (a1 == *getMemU32Ptr(0x5D4594, 1217532)) {
			v14 = nox_color_rgb_4344A0(255, 100, 255);
		} else if (a1 == *getMemU32Ptr(0x5D4594, 1217536)) {
			v14 = nox_color_rgb_4344A0(255, 200, 255);
		} else if (a1 == *getMemU32Ptr(0x5D4594, 1217540)) {
			v14 = nox_color_rgb_4344A0(255, 255, 200);
		} else {
			v14 = nox_color_rgb_4344A0(200, 200, 255);
		}
		v13[109] = v14;
		*((uint8_t*)v13 + 440) = a5;
		*((uint8_t*)v13 + 443) = a6;
		*((uint8_t*)v13 + 442) = a6;
		*((uint8_t*)v13 + 441) = 1;
		*((uint8_t*)v13 + 444) = a8;
		*((uint8_t*)v13 + 445) = a9;
		*((uint8_t*)v13 + 446) = a7;
		nox_xxx_spriteToSightDestroyList_49BAB0_drawable(v13);
		nox_xxx_spriteTransparentDecay_49B950(v13, a10);
		result = nox_xxx_sprite_45A110_drawable(v13);
	}
	return result;
}
// 49A025: variable 'v11' is possibly undefined
// 49A025: variable 'v12' is possibly undefined

//----- (0049A2C0) --------------------------------------------------------
void nox_alloc_npcs() { npc_array = calloc(nox_max_npcs, sizeof(nox_npc)); }

//----- (0049A300) --------------------------------------------------------
nox_npc* nox_new_npc(int id) {
	int n = 0;
	nox_npc* cur = npc_array;
	while (cur->live) {
		cur++;
		n++;
		if (n >= nox_max_npcs) {
			return 0;
		}
	}
	nox_init_npc(cur, id);
	return cur;
}

//----- (0049A340) --------------------------------------------------------
nox_npc* nox_npc_by_id(int id) {
	int n = 0;
	nox_npc* cur = npc_array;
	while (cur->id != id || !cur->live) {
		cur++;
		n++;
		if (n >= nox_max_npcs) {
			return 0;
		}
	}
	return cur;
}

//----- (0049A380) --------------------------------------------------------
int nox_init_npc(nox_npc* ptr, int id) {
	memset(ptr, 0, sizeof(nox_npc));
	ptr->live = 1;
	ptr->id = id;
	return id;
}

//----- (0049A3B0) --------------------------------------------------------
nox_npc* nox_npc_set_328(int id, int a2) {
	nox_npc* p = nox_npc_by_id(id);
	if (p) {
		p->data8[326] = a2;
	}
	return p;
}

//----- (0049A3D0) --------------------------------------------------------
char* nox_xxx_clientEquip_49A3D0(char a1, int a2, int a3, int a4) {
	char* npc;   // eax
	uint32_t* k; // edx
	char* v7;    // ecx
	char** v8;   // edi
	int l;       // esi
	uint32_t* i; // edx
	char* v12;   // ecx
	char** v13;  // edi
	int j;       // esi

	npc = nox_npc_by_id(a2);
	if (!npc) {
		return 0;
	}
	if (a1 == 81 || a1 == 80) {
		int v10 = 0;
		for (i = npc + 32; *i; i += 6) {
			if (++v10 >= 27) {
				return npc;
			}
		}
		v12 = &npc[24 * v10];
		*((uint32_t*)v12 + 8) = a3;
		v13 = (char**)(v12 + 36);
		*((uint32_t*)npc + 326) |= a3;
		for (j = 0; j < 4; ++j) {
			npc = (char*)nox_xxx_modifGetDescById_413330(*(unsigned char*)(j + a4));
			*v13 = npc;
			++v13;
		}
	} else {
		int v5 = 0;
		for (k = npc + 680; *k; k += 6) {
			if (++v5 >= 26) {
				return npc;
			}
		}
		v7 = &npc[24 * v5];
		*((uint32_t*)v7 + 170) = a3;
		v8 = (char**)(v7 + 684);
		*((uint32_t*)npc + 327) |= a3;
		for (l = 0; l < 4; ++l) {
			npc = (char*)nox_xxx_modifGetDescById_413330(*(unsigned char*)(l + a4));
			*v8 = npc;
			++v8;
		}
	}
	return npc;
}

//----- (0049A5F0) --------------------------------------------------------
int nox_xxx_allocArrayHealthChanges_49A5F0() {
	int result; // eax

	result = nox_new_alloc_class("HealthChange", 20, 32);
	nox_alloc_healthChange_1301772 = result;
	if (result) {
		dword_5d4594_1301780 = nox_xxx_guiFontPtrByName_43F360("numbers");
		result = 1;
	}
	return result;
}

//----- (0049A630) --------------------------------------------------------
void sub_49A630() {
	nox_alloc_class_free_all(*(uint32_t**)&nox_alloc_healthChange_1301772);
	dword_5d4594_1301776 = 0;
}

//----- (0049A650) --------------------------------------------------------
uint16_t* nox_xxx_cliAddHealthChange_49A650(int a1, short a2) {
	uint16_t* result; // eax
	uint16_t* v3;     // esi

	result = nox_alloc_class_new_obj_zero(*(uint32_t**)&nox_alloc_healthChange_1301772);
	v3 = result;
	if (result) {
		*(uint32_t*)result = a1;
		result[2] = a2;
		*((uint32_t*)result + 2) = nox_xxx_bookGet_430B40_get_mouse_prev_seq();
		*((uint32_t*)v3 + 3) = dword_5d4594_1301776;
		*((uint32_t*)v3 + 4) = 0;
		result = *(uint16_t**)&dword_5d4594_1301776;
		if (dword_5d4594_1301776) {
			*(uint32_t*)(dword_5d4594_1301776 + 16) = v3;
		}
		dword_5d4594_1301776 = v3;
	}
	return result;
}

//----- (0049A6A0) --------------------------------------------------------
void sub_49A6A0(nox_draw_viewport_t* vp, nox_drawable* dr) {
	uint32_t* a1 = vp;
	int a2 = dr;
	uint32_t* v2;    // eax
	int v3;          // esi
	uint32_t* v4;    // edi
	int v5;          // edi
	int v6;          // esi
	int v7;          // edi
	uint32_t* v8;    // [esp+4h] [ebp-C0h]
	int v9;          // [esp+Ch] [ebp-B8h]
	int v10;         // [esp+10h] [ebp-B4h]
	uint32_t* v11;   // [esp+1Ch] [ebp-A8h]
	int v12;         // [esp+20h] [ebp-A4h]
	wchar_t v13[80]; // [esp+24h] [ebp-A0h]

	v10 = nox_xxx_bookGet_430B40_get_mouse_prev_seq();
	if (a2 == *getMemU32Ptr(0x852978, 8)) {
		v9 = *getMemU32Ptr(0x85B3FC, 940);
	} else {
		v9 = nox_color_yellow_2589772;
	}
	v2 = *(uint32_t**)&dword_5d4594_1301776;
	v8 = *(uint32_t**)&dword_5d4594_1301776;
	if (dword_5d4594_1301776) {
		while (1) {
			v3 = v2[2];
			v4 = (uint32_t*)v2[3];
			v11 = (uint32_t*)v2[3];
			if ((unsigned int)(v10 - v3) <= 0x1E) {
				if (*v2 == *(uint32_t*)(a2 + 128)) {
					v5 = *a1 + *(uint32_t*)(a2 + 12) - a1[4];
					v6 = *(uint32_t*)(a2 + 16) + a1[1] + 2 * (v3 - v10) - *(short*)(a2 + 104) -
						 (unsigned long long)(long long)*(float*)(a2 + 100) - a1[5];
					nox_swprintf(v13, L"%d", abs32(*((short*)v8 + 2)));
					nox_xxx_drawGetStringSize_43F840(*(int*)&dword_5d4594_1301780, v13, &v12, 0, 0);
					v7 = v12 / -2 + v5;
					nox_xxx_drawSetTextColor_434390(nox_color_black_2650656);
					nox_xxx_drawString_43F6E0(*(int*)&dword_5d4594_1301780, (short*)v13, v7 - 1, v6 - 1);
					nox_xxx_drawString_43F6E0(*(int*)&dword_5d4594_1301780, (short*)v13, v7 - 1, v6 + 1);
					nox_xxx_drawString_43F6E0(*(int*)&dword_5d4594_1301780, (short*)v13, v7 + 1, v6 - 1);
					nox_xxx_drawString_43F6E0(*(int*)&dword_5d4594_1301780, (short*)v13, v7 + 1, v6 + 1);
					if (*((short*)v8 + 2) <= 0) {
						nox_xxx_drawSetTextColor_434390(v9);
					} else {
						nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x8531A0, 2572));
					}
					nox_xxx_drawString_43F6E0(*(int*)&dword_5d4594_1301780, (short*)v13, v7, v6);
					v4 = v11;
				}
			} else {
				sub_49A880((int)v2);
			}
			v8 = v4;
			if (!v4) {
				break;
			}
			v2 = v4;
		}
	}
}

//----- (0049A880) --------------------------------------------------------
void sub_49A880(int a1) {
	int v1; // ecx
	int v2; // ecx

	v1 = *(uint32_t*)(a1 + 16);
	if (v1) {
		*(uint32_t*)(v1 + 12) = *(uint32_t*)(a1 + 12);
	} else {
		dword_5d4594_1301776 = *(uint32_t*)(a1 + 12);
	}
	v2 = *(uint32_t*)(a1 + 12);
	if (v2) {
		*(uint32_t*)(v2 + 16) = *(uint32_t*)(a1 + 16);
	}
	nox_alloc_class_free_obj_first(*(unsigned int**)&nox_alloc_healthChange_1301772, (uint64_t*)a1);
}

//----- (0049A8C0) --------------------------------------------------------
int sub_49A8C0() {
	int result; // eax

	nox_free_alloc_class(*(void**)&nox_alloc_healthChange_1301772);
	result = 0;
	nox_alloc_healthChange_1301772 = 0;
	dword_5d4594_1301776 = 0;
	dword_5d4594_1301780 = 0;
	return result;
}

//----- (0049AA90) --------------------------------------------------------
void nox_xxx_updateSpritePosition_49AA90(nox_drawable* dr, int a2, int a3) {
	uint32_t* a1 = dr;
	int v3; // ebx
	int v4; // ecx
	int v5; // edi
	int v6; // edx

	v3 = a2;
	v4 = a1[4];
	a1[8] = a1[3];
	a1[9] = v4;
	if (a2 < 0 || a2 >= 5888 || (v5 = a3, a3 < 0) || a3 >= 5888) {
		v3 = 50;
		v5 = 50;
		if (!(a1[30] & 0x400000)) {
			nox_xxx_sprite_45A110_drawable(dr);
		}
	}
	v6 = a1[5];
	a1[3] = v3;
	a1[10] = v6;
	a1[4] = v5;
	a1[5] = nox_frame_xxx_2598000;
	nox_xxx_sprite_49AA00_drawable(dr);
}

//----- (0049AEA0) --------------------------------------------------------
int sub_49AEA0() {
	if (nox_alloc_pixelSpan_1301844) {
		nox_free_alloc_class(*(void**)&nox_alloc_pixelSpan_1301844);
		nox_alloc_pixelSpan_1301844 = 0;
	}
	if (dword_5d4594_1301848) {
		free(*(void**)&dword_5d4594_1301848);
		dword_5d4594_1301848 = 0;
	}
	return 1;
}

//----- (0049B3E0) --------------------------------------------------------
int sub_49B3E0() {
	int result; // eax

	result = nox_new_window_from_file("GGOver.wnd", sub_49B420);
	dword_5d4594_1303452 = result;
	if (result) {
		nox_window_set_hidden(result, 1);
		nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1303452, 0);
		result = 1;
	}
	return result;
}

//----- (0049B420) --------------------------------------------------------
int sub_49B420(int a1, int a2, int* a3, int a4) {
	int v3; // esi

	if (a2 == 16391) {
		v3 = nox_xxx_wndGetID_46B0A0(a3);
		nox_xxx_clientPlaySoundSpecial_452D80(766, 100);
		if (v3 == 10701) {
			nox_client_quit_4460C0();
			sub_49B6B0();
		} else if (v3 == 10702) {
			LOWORD(a2) = 1008;
			nox_xxx_netClientSend2_4E53C0(31, &a2, 2, 0, 1);
			sub_49B6B0();
			return 0;
		}
	}
	return 0;
}

//----- (0049B490) --------------------------------------------------------
int sub_49B490() {
	int result; // eax

	result = nox_xxx_windowDestroyMB_46C4E0(*(uint32_t**)&dword_5d4594_1303452);
	dword_5d4594_1303452 = 0;
	return result;
}

//----- (0049B6B0) --------------------------------------------------------
int sub_49B6B0() {
	nox_window_set_hidden(*(int*)&dword_5d4594_1303452, 1);
	nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1303452, 0);
	return nox_xxx_windowFocus_46B500(0);
}

//----- (0049B7A0) --------------------------------------------------------
void nox_xxx_consoleEsc_49B7A0() {
	int v0; // esi

	v0 = 0;
	if (!nox_xxx_guiCursor_477600() && !sub_44E0D0()) {
		if (sub_460660()) {
			v0 = 1;
		}
		if (!sub_46A6A0() && v0 != 1) {
			if (sub_45D9B0() == 1) {
				sub_45D870();
			} else {
				if (sub_4BFE40()) {
					v0 = 1;
				}
				if (nox_xxx_quickBarClose_4606B0()) {
					v0 = 1;
				}
				if (sub_462740()) {
					v0 = 1;
				}
				if (!sub_44A4E0() && v0 != 1) {
					if (sub_479590() == 2) {
						sub_4795A0(1);
					} else if (sub_479590() == 3) {
						sub_4795A0(1);
					} else if (sub_479590() == 4) {
						sub_4795A0(1);
					} else if (!sub_478040() && !sub_479950()) {
						if (sub_467C10()) {
							v0 = 1;
						}
						if (nox_xxx_bookHideMB_45ACA0(0)) {
							v0 = 1;
						}
						if (nox_gui_console_Hide_4512B0()) {
							v0 = 1;
						}
						if (sub_446780()) {
							v0 = 1;
						}
						if (nox_xxx_guiServerOptionsTryHide_4574D0()) {
							v0 = 1;
						}
						if (sub_48CAD0()) {
							v0 = 1;
						}
						if (sub_4AD9B0(1)) {
							v0 = 1;
						}
						if (sub_4C35B0(1)) {
							v0 = 1;
						}
						if (!sub_46D6F0() && v0 != 1) {
							if (nox_xxx_game_4DCCB0()) {
								sub_445C40();
							} else {
								nox_xxx_clientPlaySoundSpecial_452D80(231, 100);
							}
						}
					}
				}
			}
		}
	}
}
// 49B874: variable 'v1' is possibly undefined
// 49B881: variable 'v2' is possibly undefined

//----- (0049B950) --------------------------------------------------------
uint32_t* nox_xxx_spriteTransparentDecay_49B950(uint32_t* a1, int a2) {
	unsigned int v2;  // edx
	uint32_t* result; // eax
	uint32_t* v4;     // ecx
	int v5;           // ecx

	if (a1[89]) {
		nox_xxx_sprite_49BA10(a1);
	}
	v2 = nox_frame_xxx_2598000 + a2;
	a1[89] = nox_frame_xxx_2598000 + a2;
	result = *(uint32_t**)&dword_5d4594_1303468;
	if (dword_5d4594_1303468) {
		v4 = 0;
		while (result[89] < v2) {
			v4 = result;
			result = (uint32_t*)result[87];
			if (!result) {
				goto LABEL_10;
			}
		}
		if (!result) {
		LABEL_10:
			v4[87] = a1;
			a1[87] = 0;
			a1[88] = v4;
			return result;
		}
		a1[87] = result;
		a1[88] = result[88];
		v5 = result[88];
		if (v5) {
			*(uint32_t*)(v5 + 348) = a1;
		} else {
			dword_5d4594_1303468 = a1;
		}
		result[88] = a1;
	} else {
		a1[87] = dword_5d4594_1303468;
		a1[88] = result;
		dword_5d4594_1303468 = a1;
	}
	return result;
}

//----- (0049BA10) --------------------------------------------------------
uint32_t* nox_xxx_sprite_49BA10(nox_drawable* dr) {
	uint32_t* a1 = dr;
	uint32_t* result; // eax
	int v2;           // ecx
	int v3;           // ecx

	result = a1;
	if (a1[89]) {
		v2 = a1[88];
		if (v2) {
			*(uint32_t*)(v2 + 348) = a1[87];
		} else {
			dword_5d4594_1303468 = a1[87];
		}
		v3 = a1[87];
		if (v3) {
			*(uint32_t*)(v3 + 352) = a1[88];
		}
		a1[89] = 0;
	}
	return result;
}

//----- (0049BA70) --------------------------------------------------------
int sub_49BA70() {
	int result; // eax
	int v1;     // esi

	result = dword_5d4594_1303468;
	if (dword_5d4594_1303468) {
		do {
			v1 = *(uint32_t*)(result + 348);
			if (*(uint32_t*)(result + 356) > nox_frame_xxx_2598000) {
				break;
			}
			nox_xxx_spriteDeleteStatic_45A4E0_drawable(result);
			result = v1;
		} while (v1);
	}
	return result;
}

//----- (0049BAB0) --------------------------------------------------------
uint32_t* nox_xxx_spriteToSightDestroyList_49BAB0_drawable(uint32_t* a1) {
	uint32_t* result; // eax

	result = a1;
	a1[84] = 0;
	a1[83] = dword_5d4594_1303472;
	if (dword_5d4594_1303472) {
		*(uint32_t*)(dword_5d4594_1303472 + 336) = a1;
	}
	dword_5d4594_1303472 = a1;
	a1[30] |= 0x200000u;
	return result;
}

//----- (0049BAF0) --------------------------------------------------------
uint32_t* sub_49BAF0(nox_drawable* dr) {
	uint32_t* a1 = dr;
	uint32_t* result; // eax
	int v2;           // ecx
	int v3;           // ecx

	result = a1;
	if (a1[30] & 0x200000) {
		v2 = a1[84];
		if (v2) {
			*(uint32_t*)(v2 + 332) = a1[83];
		} else {
			dword_5d4594_1303472 = a1[83];
		}
		v3 = a1[83];
		if (v3) {
			*(uint32_t*)(v3 + 336) = a1[84];
		}
		a1[30] &= 0xFFDFFFFF;
	}
	return result;
}

//----- (0049BB40) --------------------------------------------------------
void sub_49BB40() {
	int v0; // esi
	int v1; // edi

	v0 = dword_5d4594_1303472;
	if (dword_5d4594_1303472) {
		do {
			v1 = *(uint32_t*)(v0 + 332);
			if (*(uint32_t*)(v0 + 340) < (unsigned int)sub_435590()) {
				nox_xxx_spriteDeleteStatic_45A4E0_drawable(v0);
			}
			v0 = v1;
		} while (v1);
	}
}

//----- (0049BB80) --------------------------------------------------------
void* sub_49BB80(char a1) {
	void* result; // eax

	*getMemU8Ptr(0x5D4594, 1303504) = a1;
	*getMemU8Ptr(0x5D4594, 1303512) = 0;
	*getMemU32Ptr(0x5D4594, 1303516) = nox_frame_xxx_2598000;
	result = nox_xxx_spellGetDefArrayPtr_424820();
	dword_5d4594_1303508 = result;
	return result;
}

//----- (0049BBB0) --------------------------------------------------------
void sub_49BBB0() { *getMemU8Ptr(0x5D4594, 1303504) = 0; }

//----- (0049BBC0) --------------------------------------------------------
void sub_49BBC0() {
	int v0;           // eax
	unsigned char v1; // [esp+0h] [ebp-4h]

	if (getMemByte(0x5D4594, 1303504)) {
		v1 = nox_xxx_spellPhonemes_424A20(getMemByte(0x5D4594, 1303504), getMemByte(0x5D4594, 1303512));
		if (nox_frame_xxx_2598000 >= *getMemIntPtr(0x5D4594, 1303516)) {
			v0 = nox_xxx_spellGetPhoneme_4FE1C0(nox_player_netCode_85319C, v1);
			nox_xxx_clientPlaySoundSpecial_452D80(v0, 100);
			nox_client_setPhonemeFrame_476E00(*getMemU32Ptr(0x587000, 163576 + 4 * v1));
			*getMemU32Ptr(0x5D4594, 1303516) = nox_frame_xxx_2598000 + 3;
			dword_5d4594_1303508 = nox_xxx_updateSpellRelated_424830(*(int*)&dword_5d4594_1303508, v1);
			++*getMemU8Ptr(0x5D4594, 1303512);
		}
		if (**(uint32_t**)&dword_5d4594_1303508 == getMemByte(0x5D4594, 1303504)) {
			sub_49BBB0();
		}
	}
}

//----- (0049BC80) --------------------------------------------------------
uint32_t* nox_xxx_spriteToList_49BC80_drawable(uint32_t* a1) {
	uint32_t* result; // eax

	result = a1;
	if (!a1[96]) {
		a1[95] = 0;
		a1[94] = dword_5d4594_1303536;
		if (dword_5d4594_1303536) {
			*(uint32_t*)(dword_5d4594_1303536 + 380) = a1;
		}
		dword_5d4594_1303536 = a1;
		a1[96] = 1;
	}
	return result;
}

//----- (0049BCD0) --------------------------------------------------------
uint32_t* sub_49BCD0(nox_drawable* dr) {
	uint32_t* a1 = dr;
	uint32_t* result; // eax
	int v2;           // ecx
	int v3;           // ecx
	int v4;           // ecx

	result = a1;
	if (a1[96]) {
		v2 = a1[95];
		if (v2) {
			*(uint32_t*)(v2 + 376) = a1[94];
			v3 = a1[94];
			if (v3) {
				*(uint32_t*)(v3 + 380) = a1[95];
				a1[96] = 0;
				return result;
			}
		} else {
			dword_5d4594_1303536 = a1[94];
			v4 = a1[94];
			if (v4) {
				*(uint32_t*)(v4 + 380) = 0;
			}
		}
		a1[96] = 0;
	}
	return result;
}

//----- (0049BD40) --------------------------------------------------------
int nox_xxx_getSomeSprite_49BD40() { return dword_5d4594_1303536; }

//----- (0049BD50) --------------------------------------------------------
int nox_xxx_getSprite178_49BD50(int a1) {
	int result; // eax

	if (a1) {
		result = *(uint32_t*)(a1 + 376);
	} else {
		result = 0;
	}
	return result;
}

//----- (0049BD70) --------------------------------------------------------
void sub_49BD70(nox_draw_viewport_t* a1p) {
	int a1 = a1p;
	void (*result2)(int, int); // eax
	int (*v4)(int, uint32_t);  // eax

	if (nox_xxx_checkGameFlagPause_413A50() == 1) {
		return;
	}
	int v2 = nox_xxx_getSomeSprite_49BD40();
	while (v2) {
		int v3 = nox_xxx_getSprite178_49BD50(v2);
		v4 = (int (*)(int, uint32_t)) * ((uint32_t*)v2 + 116);
		if (!v4 || v4(a1, v2) != 0) {
			result2 = (int (*)(int, int)) * ((uint32_t*)v2 + 115);
			if (result2) {
				result2(a1, (int)v2);
			}
		}
		v2 = v3;
	}
}

//----- (0049C160) --------------------------------------------------------
uint32_t* nox_xxx_clientAddRayEffect_49C160(int a1) {
	uint32_t* result;   // eax
	int v2;             // eax
	int v3;             // esi
	int v4;             // eax
	int v5;             // ebx
	uint32_t* v6;       // eax
	uint32_t* v7;       // edi
	int v8;             // esi
	int v9;             // edi
	int v10;            // kr00_4
	int v11;            // ecx
	int v12;            // edx
	int v13;            // edx
	unsigned char* v14; // ecx

	result = *(uint32_t**)getMemAt(0x5D4594, 1304312);
	if (*getMemIntPtr(0x5D4594, 1304312) < 96) {
		if (!*getMemU32Ptr(0x5D4594, 1304352)) {
			*getMemU32Ptr(0x5D4594, 1304352) = nox_xxx_getTTByNameSpriteMB_44CFC0("DynamicLightning");
			*getMemU32Ptr(0x5D4594, 1304356) = nox_xxx_getTTByNameSpriteMB_44CFC0("DynamicChainLightning");
			*getMemU32Ptr(0x5D4594, 1304360) = nox_xxx_getTTByNameSpriteMB_44CFC0("DynamicEnergyBolt");
			*getMemU32Ptr(0x5D4594, 1304364) = nox_xxx_getTTByNameSpriteMB_44CFC0("OrbRay");
			*getMemU32Ptr(0x5D4594, 1304368) = nox_xxx_getTTByNameSpriteMB_44CFC0("PlasmaRay");
			*getMemU32Ptr(0x5D4594, 1304372) = nox_xxx_getTTByNameSpriteMB_44CFC0("DrainManaRay");
			*getMemU32Ptr(0x5D4594, 1304376) = nox_xxx_getTTByNameSpriteMB_44CFC0("HealRay");
			*getMemU32Ptr(0x5D4594, 1304380) = nox_xxx_getTTByNameSpriteMB_44CFC0("CharmRay");
			*getMemU32Ptr(0x5D4594, 1304384) = nox_xxx_getTTByNameSpriteMB_44CFC0("DrainManaOrb");
			*getMemU32Ptr(0x5D4594, 1304388) = nox_xxx_getTTByNameSpriteMB_44CFC0("HealOrb");
			*getMemU32Ptr(0x5D4594, 1304392) = nox_xxx_getTTByNameSpriteMB_44CFC0("CharmOrb");
			*getMemU32Ptr(0x5D4594, 1304396) = nox_xxx_getTTByNameSpriteMB_44CFC0("HarpoonRope");
		}
		v2 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(a1 + 3));
		v3 = v2;
		v4 = nox_xxx_netClearHighBit_578B30(*(uint16_t*)(a1 + 5));
		v5 = v4;
		v6 = nox_xxx_netTestHighBit_578B70(*(unsigned short*)(a1 + 3)) ? nox_xxx_netSpriteByCodeStatic_45A720(v3)
																	   : nox_xxx_netSpriteByCodeDynamic_45A6F0(v3);
		v7 = v6;
		result = nox_xxx_netTestHighBit_578B70(*(unsigned short*)(a1 + 5)) ? nox_xxx_netSpriteByCodeStatic_45A720(v5)
																		   : nox_xxx_netSpriteByCodeDynamic_45A6F0(v5);
		if (v7 && result) {
			v8 = v7[3];
			v9 = v7[4];
			v10 = result[4] - v9;
			v11 = v8 + ((int)result[3] - v8) / 2;
			result = (uint32_t*)(v9 + v10 / 2);
			switch (*(unsigned char*)(a1 + 1)) {
			case 1u:
				v12 = *getMemU32Ptr(0x5D4594, 1304368);
				goto LABEL_21;
			case 2u:
				v12 = *getMemU32Ptr(0x5D4594, 1304380);
				goto LABEL_21;
			case 3u:
				v12 = *getMemU32Ptr(0x5D4594, 1304356);
				goto LABEL_21;
			case 4u:
				v12 = *getMemU32Ptr(0x5D4594, 1304360);
				goto LABEL_21;
			case 5u:
				v12 = *getMemU32Ptr(0x5D4594, 1304372);
				goto LABEL_21;
			case 6u:
				v12 = *getMemU32Ptr(0x5D4594, 1304376);
				goto LABEL_21;
			case 7u:
				v12 = *getMemU32Ptr(0x5D4594, 1304396);
				goto LABEL_21;
			case 0x8Cu:
				v12 = *getMemU32Ptr(0x5D4594, 1304352);
			LABEL_21:
				result = (uint32_t*)nox_xxx_spriteLoadAdd_45A360_drawable(v12, v11, v9 + v10 / 2);
				if (!result) {
					return result;
				}
				*((uint8_t*)result + 432) = 1;
				*(uint32_t*)((char*)result + 437) = *(unsigned short*)(a1 + 3);
				*(uint32_t*)((char*)result + 441) = *(unsigned short*)(a1 + 5);
				v13 = 0;
				*(uint32_t*)((char*)result + 433) = *(unsigned char*)(a1 + 2);
				v14 = getMemAt(0x5D4594, 1303924);
				break;
			default:
				return result;
			}
			while (*(uint32_t*)v14) {
				v14 += 4;
				++v13;
				if ((int)v14 >= (int)getMemAt(0x5D4594, 1304308)) {
					return result;
				}
			}
			*getMemU32Ptr(0x5D4594, 1303924 + 4 * v13) = result;
		}
	}
	return result;
}
// 49C248: variable 'v2' is possibly undefined
// 49C256: variable 'v4' is possibly undefined

//----- (0049C450) --------------------------------------------------------
void nox_xxx_clientRemoveRayEffect_49C450(int a1) {
	int v1;  // esi
	int* v2; // ecx

	v1 = 0;
	v2 = getMemIntPtr(0x5D4594, 1303924);
	while (1) {
		int result = *v2;
		if (*v2) {
			if (*(unsigned short*)(a1 + 3) == *(uint32_t*)(result + 437) &&
				*(unsigned short*)(a1 + 5) == *(uint32_t*)(result + 441)) {
				break;
			}
		}
		++v2;
		++v1;
		if ((int)v2 >= (int)getMemAt(0x5D4594, 1304308)) {
			return;
		}
	}
	nox_xxx_spriteDeleteStatic_45A4E0_drawable(*v2);
	*getMemU32Ptr(0x5D4594, 1303924 + 4 * v1) = 0;
}

//----- (0049C4B0) --------------------------------------------------------
void nox_xxx_spriteDeleteSomeList_49C4B0() {
	int v0;  // esi
	int* v1; // edi

	v0 = 0;
	if (*getMemU32Ptr(0x5D4594, 1304308) > 0) {
		v1 = getMemIntPtr(0x5D4594, 1303540);
		do {
			nox_xxx_spriteDeleteStatic_45A4E0_drawable(*v1);
			++v0;
			++v1;
		} while (v0 < *getMemIntPtr(0x5D4594, 1304308));
	}
	*getMemU32Ptr(0x5D4594, 1304308) = 0;
	sub_4C5050();
}

//----- (0049C4F0) --------------------------------------------------------
void nox_xxx_sprite_49C4F0() {
	int* v0 = getMemIntPtr(0x5D4594, 1303924);
	do {
		if (*v0) {
			nox_xxx_spriteDeleteStatic_45A4E0_drawable(*v0);
			*v0 = 0;
		}
		++v0;
	} while ((int)v0 < (int)getMemAt(0x5D4594, 1304308));
}

//----- (0049C520) --------------------------------------------------------
int sub_49C520(int a1) {
	unsigned char* v1; // eax
	int v2;            // eax
	unsigned char* i;  // ecx

	v1 = getMemAt(0x5D4594, 1303924);
	while (a1 != *(uint32_t*)v1) {
		v1 += 4;
		if ((int)v1 >= (int)getMemAt(0x5D4594, 1304308)) {
			v2 = 0;
			if (*getMemIntPtr(0x5D4594, 1304308) <= 0) {
				return 0;
			}
			for (i = getMemAt(0x5D4594, 1303540); a1 != *(uint32_t*)i; i += 4) {
				if (++v2 >= *getMemIntPtr(0x5D4594, 1304308)) {
					return 0;
				}
			}
			return 1;
		}
	}
	return 1;
}

//----- (0049C760) --------------------------------------------------------
int nox_xxx_wnd_49C760(int a1, int a2, int* a3, int a4) {
	int v3; // esi

	if (a2 == 16391) {
		v3 = nox_xxx_wndGetID_46B0A0(a3);
		nox_xxx_clientPlaySoundSpecial_452D80(766, 100);
		if (v3 == 4103) {
			sub_49C7A0();
		}
	}
	return 1;
}

//----- (0049C7A0) --------------------------------------------------------
int sub_49C7A0() {
	int result; // eax

	result = dword_5d4594_1305680;
	if (dword_5d4594_1305680) {
		nox_server_sanctuaryHelp_54276 =
			((unsigned int)~(
				 nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1305680, 4104)->draw_data.field_0) >>
			 2) &
			1;
		nox_xxx_wnd_46C6E0(*(int*)&dword_5d4594_1305680);
		nox_xxx_wndClearCaptureMain_46ADE0(*(int*)&dword_5d4594_1305680);
		nox_xxx_windowDestroyMB_46C4E0(*(uint32_t**)&dword_5d4594_1305680);
		dword_5d4594_1305680 = 0;
		nox_xxx_windowFocus_46B500(0);
		result = nox_common_gameFlags_check_40A5C0(1);
		if (result) {
			result = sub_459D80(0);
		}
	}
	return result;
}

//----- (0049C810) --------------------------------------------------------
int sub_49C810() { return dword_5d4594_1305680 != 0; }

//----- (0049CA60) --------------------------------------------------------
int sub_49CA60(int a1, int a2, int* a3, int a4) {
	int v3;       // esi
	uint32_t* v4; // eax
	int v5;       // eax
	int v6;       // eax

	if (a2 == 16391) {
		v3 = nox_xxx_wndGetID_46B0A0(a3);
		nox_xxx_clientPlaySoundSpecial_452D80(766, 100);
		if (v3 == 10353) {
			nox_xxx_wnd_46C6E0(*(int*)&dword_5d4594_1305684);
			nox_xxx_wndClearCaptureMain_46ADE0(*(int*)&dword_5d4594_1305684);
			if (nox_common_gameFlags_check_40A5C0(128) && nox_server_sanctuaryHelp_54276) {
				nox_xxx_cliShowHelpGui_49C560();
			} else {
				sub_459D80(0);
			}
			v4 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1305684, 10352);
			v5 = nox_window_call_field_94((int)v4, 16404, 0, 0);
			nox_server_connectionType_3596 = v5 + 1;
			v6 = sub_40A710(v5 + 1);
			nox_xxx_rateUpdate_40A6D0(v6);
			nox_xxx_windowDestroyMB_46C4E0(*(uint32_t**)&dword_5d4594_1305684);
			dword_5d4594_1305684 = 0;
			nox_xxx_windowFocus_46B500(0);
		}
	}
	return 1;
}

//----- (0049CB40) --------------------------------------------------------
int sub_49CB40() { return dword_5d4594_1305684 != 0; }

// Most probably borders with alpha
//----- (0049CD30) --------------------------------------------------------
void sub_49CD30(int xLeft, int yTop, int a3, int a4, int a5, int a6) {
	RECT rc; // [esp+10h] [ebp-10h]

	if (a3) {
		if (a4) {
			if (!nox_draw_curDrawData_3799572->flag_0 ||
				(SetRect(&rc, xLeft, yTop, xLeft + a3, yTop + a4),
				 nox_xxx_utilRect_49F930((int4*)&rc, (int4*)&rc, (int4*)(&nox_draw_curDrawData_3799572->clip)))) {
				sub_434040(a5);
				sub_434080(a6);
				nox_client_drawAddPoint_49F500(xLeft, yTop);
				nox_client_drawAddPoint_49F500(xLeft + a3 - 1, yTop);
				sub_49E4F0(64);
				nox_client_drawAddPoint_49F500(xLeft + a3, yTop);
				nox_client_drawAddPoint_49F500(xLeft + a3, yTop + a4 - 1);
				sub_49E4F0(64);
				nox_client_drawAddPoint_49F500(xLeft + a3, yTop + a4);
				nox_client_drawAddPoint_49F500(xLeft, yTop + a4);
				sub_49E4F0(64);
				nox_client_drawAddPoint_49F500(xLeft, yTop + a4 - 1);
				nox_client_drawAddPoint_49F500(xLeft, yTop + 1);
				sub_49E4F0(64);
			}
		}
	}
}

//----- (0049CF10) --------------------------------------------------------
int4* nox_client_drawRectFilledAlpha_49CF10(int xLeft, int yTop, int a3, int a4) {
	int4* result; // eax
	RECT rc;      // [esp+4h] [ebp-10h]

	if (!nox_draw_curDrawData_3799572->flag_0) {
		return sub_49D6F0(xLeft, yTop, a3, a4);
	}
	SetRect(&rc, xLeft, yTop, xLeft + a3, yTop + a4);
	result = nox_xxx_utilRect_49F930((int4*)&rc, (int4*)&rc, (int4*)(&nox_draw_curDrawData_3799572->clip));
	if (result) {
		result = sub_49D6F0(rc.min_x, rc.min_y, rc.max_x - rc.min_x, rc.max_y - rc.min_y);
	}
	return result;
}

// black screen
//----- (0049D050) --------------------------------------------------------
int4* sub_49D050(int xLeft, int yTop, int a3, int a4) {
	int4* result; // eax
	RECT rc;      // [esp+4h] [ebp-10h]

	if (!nox_draw_curDrawData_3799572->flag_0) {
		return sub_49D8E0(xLeft, yTop, a3, a4);
	}
	SetRect(&rc, xLeft, yTop, xLeft + a3, yTop + a4);
	result = nox_xxx_utilRect_49F930((int4*)&rc, (int4*)&rc, (int4*)(&nox_draw_curDrawData_3799572->clip));
	if (result) {
		result = sub_49D8E0(rc.min_x, rc.min_y, rc.max_x - rc.min_x, rc.max_y - rc.min_y);
	}
	return result;
}

// black screen fade-in/out
//----- (0049D0F0) --------------------------------------------------------
int4* nox_client_drawRectFadingScreen_49D0F0(int xLeft, int yTop, int a3, int a4) {
	int4* result; // eax
	RECT rc;      // [esp+4h] [ebp-10h]

	if (!nox_draw_curDrawData_3799572->flag_0) {
		return sub_49DBB0(xLeft, yTop, a3, a4);
	}
	SetRect(&rc, xLeft, yTop, xLeft + a3, yTop + a4);
	result = nox_xxx_utilRect_49F930((int4*)&rc, (int4*)&rc, (int4*)(&nox_draw_curDrawData_3799572->clip));
	if (result) {
		result = sub_49DBB0(rc.min_x, rc.min_y, rc.max_x - rc.min_x, rc.max_y - rc.min_y);
	}
	return result;
}

//----- (0049D1C0) --------------------------------------------------------
int sub_49D1C0(void* a1, int a2, int a3) {
	sub_49E3C0(a1, a2, a3);
	return 0;
}

//----- (0049D270) --------------------------------------------------------
void nox_xxx_draw_49D270_MBRect_49D270(int a1, int a2, unsigned int a3, int a4) {
	int result;   // eax
	int v5;       // edx
	uint32_t* v6; // esi
	char* v7;     // edi
	char* v8;     // edi

	result = nox_draw_curDrawData_3799572;
	if (nox_draw_curDrawData_3799572->field_13) {
		sub_49D370(a1, a2, a3, a4);
		return;
	}
	v5 = a4;
	if (a4 > 0 && (int)a3 > 0) {
		result = nox_draw_curDrawData_3799572->field_61;
		v6 = &nox_pixbuffer_rows_3798784[a2];
		do {
			v7 = (char*)(2 * a1 + *v6);
			memset32(v7, result, a3 >> 1);
			v8 = &v7[4 * (a3 >> 1)];
			if (a3 & 1) {
				*(uint16_t*)v8 = result;
			}
			++v6;
		} while (v5-- > 1);
	}
}

//----- (0049D370) --------------------------------------------------------
void sub_49D370(int a1, int a2, int a3, int a4) {
	int v4;            // eax
	unsigned char v5;  // bl
	int result;        // eax
	int v7;            // ecx
	int v8;            // edx
	int v9;            // esi
	short* v10;        // esi
	int v11;           // ebp
	short v12;         // cx
	bool v13;          // zf
	unsigned char v14; // [esp+Ch] [ebp-28h]
	unsigned char v15; // [esp+10h] [ebp-24h]
	unsigned char v16; // [esp+14h] [ebp-20h]
	int v17;           // [esp+38h] [ebp+4h]
	int v18;           // [esp+3Ch] [ebp+8h]
	int v19;           // [esp+44h] [ebp+10h]

	v4 = nox_draw_curDrawData_3799572->field_61 & 0xFFFF;
	v17 = 2 * a1;
	v5 = *((uint8_t*)byte_5D4594_3804364 + 8);
	v16 =
		(*((uint32_t*)((uint8_t*)byte_5D4594_3804364 + 0)) & (unsigned int)v4) >> *((uint8_t*)byte_5D4594_3804364 + 12);
	v15 =
		(*((uint32_t*)((uint8_t*)byte_5D4594_3804364 + 4)) & (unsigned int)v4) >> *((uint8_t*)byte_5D4594_3804364 + 16);
	v14 = ((unsigned char)nox_draw_curDrawData_3799572->field_61 & *((uint8_t*)byte_5D4594_3804364 + 8))
		  << *((uint8_t*)byte_5D4594_3804364 + 20);
	result = a4 - 1;
	if (a4) {
		v7 = a3;
		v8 = 4 * a2;
		v18 = a4;
		do {
			v9 = nox_pixbuffer_rows_3798784[v8 / 4];
			v8 += 4;
			v10 = (short*)(v17 + v9);
			if (v7) {
				v11 = v16;
				v19 = v7;
				while (1) {
					v12 = *v10;
					++v10;
					v13 = v19 == 1;
					*(v10 - 1) =
						*(uint16_t*)(nox_draw_colors_b_3804664 +
									 2 * (unsigned char)((((unsigned char)v12 & v5)
														  << *((uint8_t*)byte_5D4594_3804364 + 20)) +
														 ((v14 -
														   (unsigned char)(((unsigned char)v12 & v5)
																		   << *((uint8_t*)byte_5D4594_3804364 + 20))) >>
														  1))) |
						*(uint16_t*)(nox_draw_colors_g_3804656 +
									 2 * (unsigned char)(((unsigned short)(*((uint16_t*)((uint8_t*)byte_5D4594_3804364 +
																						 4)) &
																		   v12) >>
														  *((uint8_t*)byte_5D4594_3804364 + 16)) +
														 ((v15 -
														   (unsigned char)((unsigned short)(*((uint16_t*)((uint8_t*)
																											  byte_5D4594_3804364 +
																										  4)) &
																							v12) >>
																		   *((uint8_t*)byte_5D4594_3804364 + 16))) >>
														  1))) |
						*(uint16_t*)(nox_draw_colors_r_3804672 +
									 2 * (unsigned char)(((unsigned short)(*((uint16_t*)((uint8_t*)byte_5D4594_3804364 +
																						 0)) &
																		   v12) >>
														  *((uint8_t*)byte_5D4594_3804364 + 12)) +
														 ((v11 -
														   (unsigned char)((unsigned short)(*((uint16_t*)((uint8_t*)
																											  byte_5D4594_3804364 +
																										  0)) &
																							v12) >>
																		   *((uint8_t*)byte_5D4594_3804364 + 12))) >>
														  1)));
					v5 = *((uint8_t*)byte_5D4594_3804364 + 8);
					--v19;
					if (v13) {
						break;
					}
					v11 = v16;
				}
				v7 = a3;
			}
			result = --v18;
		} while (v18);
	}
}

//----- (0049D6F0) --------------------------------------------------------
short sub_49D6F0(int a1, int a2, unsigned int a3, int a4) {
	unsigned int v4 = 0; // eax
	uint32_t* v5;        // esi
	int v6;              // edx
	int v7;              // ebx
	char v8;             // cf
	// char v9; // of
	char v10;          // cc
	int v11;           // ecx
	unsigned int* v12; // edi
	int v13;           // ecx
	unsigned int* v14; // edi
	unsigned int v16;  // [esp+1Ch] [ebp+10h]

	if (a4 > 0) {
		LOWORD(v4) = a2;
		v5 = &nox_pixbuffer_rows_3798784[a2];
		v6 = *((uint32_t*)((uint8_t*)byte_5D4594_3804364 + 24));
		v7 = 2 * a1;
		v8 = a3 & 1;
		// v10 = (((a3 >> 1) & 0x80000000) != 0) ^ v9 | (a3 >> 1 == 0);
		v16 = a3 >> 1;
		if (v16) {
			if (v8) {
				do {
					v13 = v16;
					v14 = (unsigned int*)(v7 + *v5);
					do {
						*v14 = (v6 & *v14) >> 1;
						++v14;
						v10 = v13-- <= 1;
					} while (!v10);
					LOWORD(v4) = (unsigned short)(v6 & *(uint16_t*)v14) >> 1;
					*(uint16_t*)v14 = v4;
					++v5;
					v10 = a4-- <= 1;
				} while (!v10);
			} else {
				do {
					v11 = v16;
					v12 = (unsigned int*)(v7 + *v5);
					do {
						v4 = (v6 & *v12) >> 1;
						*v12 = v4;
						++v12;
						v10 = v11-- <= 1;
					} while (!v10);
					++v5;
					v10 = a4-- <= 1;
				} while (!v10);
			}
		}
	}
	return v4;
}

//----- (0049D8E0) --------------------------------------------------------
int sub_49D8E0(int a1, int a2, int a3, int a4) {
	int* v4;         // esi
	int v5;          // edi
	uint16_t* v6;    // edi
	unsigned int v7; // edx
	int v8;          // eax
	unsigned int v9; // ebx
	int v10;         // edx
	int result;      // eax
	bool v12;        // cc
	int v13;         // [esp+Ch] [ebp-4h]

	v4 = &nox_pixbuffer_rows_3798784[a2];
	do {
		v13 = a3;
		v5 = *v4;
		++v4;
		v6 = (uint16_t*)(a1 + a1 + v5);
		do {
			v7 = (unsigned short)*v6;
			v8 = (unsigned short)(*((uint16_t*)((uint8_t*)byte_5D4594_3804364 + 0)) & *v6) >>
				 *((uint8_t*)byte_5D4594_3804364 + 12);
			LOBYTE(v8) = SADD8(obj_5D4594_3800716.field_54,
							   v8); //__CFADD__(obj_5D4594_3800716.field_54, (uint8_t)v8) ? -1 : (unsigned
									// char)(obj_5D4594_3800716.field_54 + v8);
			v9 = (*((uint32_t*)((uint8_t*)byte_5D4594_3804364 + 4)) & v7) >> *((uint8_t*)byte_5D4594_3804364 + 16);
			LOBYTE(v9) = SADD8(obj_5D4594_3800716.field_55,
							   v9); //__CFADD__(obj_5D4594_3800716.field_55, (uint8_t)v9) ? -1 : (unsigned
									// char)(obj_5D4594_3800716.field_55 + v9);
			v10 = (*((uint32_t*)((uint8_t*)byte_5D4594_3804364 + 8)) & v7) << *((uint8_t*)byte_5D4594_3804364 + 20);
			LOBYTE(v10) = SADD8(obj_5D4594_3800716.field_56,
								v10); //__CFADD__(obj_5D4594_3800716.field_56, (uint8_t)v10) ? -1 : (unsigned
									  // char)(obj_5D4594_3800716.field_56 + v10);
			result = *(uint32_t*)(nox_draw_colors_b_3804664 + 2 * v10) |
					 *(uint32_t*)(nox_draw_colors_g_3804656 + 2 * v9) |
					 *(uint32_t*)(nox_draw_colors_r_3804672 + 2 * v8);
			*v6 = result;
			++v6;
			v12 = v13-- <= 1;
		} while (!v12);
		v12 = a4-- <= 1;
	} while (!v12);
	return result;
}

//----- (0049DBB0) --------------------------------------------------------
int sub_49DBB0(int a1, int a2, int a3, int a4) {
	int* v4;               // esi
	int v5;                // edi
	uint16_t* v6;          // edi
	unsigned long long v7; // kr00_8
	unsigned long long v8; // kr08_8
	int result;            // eax
	bool v10;              // cc
	int v11;               // [esp+Ch] [ebp-4h]

	v4 = &nox_pixbuffer_rows_3798784[a2];
	do {
		v11 = a3;
		v5 = *v4;
		++v4;
		v6 = (uint16_t*)(a1 + a1 + v5);
		do {
			v7 = ((unsigned short)(*((uint16_t*)((uint8_t*)byte_5D4594_3804364 + 4)) & *v6) >>
				  *((uint8_t*)byte_5D4594_3804364 + 16)) -
				 (unsigned long long)*(unsigned int*)&obj_5D4594_3800716.field_55;
			v8 = ((unsigned short)(*((uint16_t*)((uint8_t*)byte_5D4594_3804364 + 8)) & *v6)
				  << *((uint8_t*)byte_5D4594_3804364 + 20)) -
				 (unsigned long long)*(unsigned int*)&obj_5D4594_3800716.field_56;
			result =
				*(uint32_t*)(nox_draw_colors_b_3804664 + 2 * (~HIDWORD(v8) & v8)) |
				*(uint32_t*)(nox_draw_colors_g_3804656 + 2 * (~HIDWORD(v7) & v7)) |
				*(uint32_t*)(nox_draw_colors_r_3804672 +
							 2 * (~((__PAIR64__(
										 *((uint32_t*)((uint8_t*)byte_5D4594_3804364 + 12)),
										 (unsigned short)(*((uint16_t*)((uint8_t*)byte_5D4594_3804364 + 0)) & *v6) >>
											 *((uint8_t*)byte_5D4594_3804364 + 12)) -
									 __PAIR64__(*((uint32_t*)((uint8_t*)byte_5D4594_3804364 + 12)),
												*(unsigned int*)&obj_5D4594_3800716.field_54)) >>
									32) &
								  (((unsigned short)(*((uint16_t*)((uint8_t*)byte_5D4594_3804364 + 0)) & *v6) >>
									*((uint8_t*)byte_5D4594_3804364 + 12)) -
								   *(uint32_t*)(&obj_5D4594_3800716.field_54))));
			*v6 = result;
			++v6;
			v10 = v11-- <= 1;
		} while (!v10);
		v10 = a4-- <= 1;
	} while (!v10);
	return result;
}

//----- (0049E3C0) --------------------------------------------------------
void sub_49E3C0(uint32_t* a1, int a2, unsigned int a3) {
	uint32_t* v3;  // edi
	signed int v4; // ecx

	if ((int)a3 > 0) {
		v3 = a1;
		v4 = a3 >> 2;
		if (a3 >> 2) {
			do {
				*v3 = a2;
				++v3;
			} while (v4-- > 1);
		}
		if ((int)(a3 & 3) >= 2) {
			*(uint16_t*)v3 = a2;
		}
	}
}

//----- (0049F6D0) --------------------------------------------------------
int sub_49F6D0(int a1) {
	int result; // eax

	result = nox_draw_curDrawData_3799572->flag_0;
	nox_draw_curDrawData_3799572->flag_0 = a1;
	return result;
}

//----- (0049F6F0) --------------------------------------------------------
int4* nox_client_copyRect_49F6F0(int xLeft, int yTop, int a3, int a4) {
	int4* result; // eax
	RECT rcSrc;   // [esp+0h] [ebp-20h]
	RECT rc;      // [esp+10h] [ebp-10h]

	SetRect(&rc, xLeft, yTop, xLeft + a3, yTop + a4);
	result = nox_xxx_utilRect_49F930((int4*)&rcSrc, (int4*)&rc, (int4*)(&nox_draw_curDrawData_3799572->rect3));
	if (result) {
		CopyRect(&nox_draw_curDrawData_3799572->clip, &rcSrc);
		--rcSrc.max_x;
		--rcSrc.max_y;
		result = (int4*)CopyRect((LPRECT)(&nox_draw_curDrawData_3799572->rect2), &rcSrc);
	}
	return result;
}

//----- (0049F780) --------------------------------------------------------
int4* sub_49F780(int xLeft, int a2) {
	int v2; // esi
	int v3; // eax

	v2 = xLeft;
	if (xLeft < (int)nox_draw_curDrawData_3799572->clip.min_x) {
		v2 = nox_draw_curDrawData_3799572->clip.min_x;
	}
	v3 = a2;
	if (a2 > (int)nox_draw_curDrawData_3799572->clip.max_x) {
		v3 = nox_draw_curDrawData_3799572->clip.max_x;
	}
	return nox_client_copyRect_49F6F0(v2, nox_draw_curDrawData_3799572->clip.min_y, v3 - v2,
									  nox_draw_curDrawData_3799572->clip.max_y - nox_draw_curDrawData_3799572->clip.min_y);
}

//----- (0049F7F0) --------------------------------------------------------
int nox_xxx_wndDraw_49F7F0() {
	int result; // eax
	int v1;     // edx

	result = dword_5d4594_1305748;
	if (!dword_5d4594_1305748) {
		*getMemU32Ptr(0x5D4594, 1305772) = nox_draw_curDrawData_3799572->flag_0;
		result = (uint32_t)(&nox_draw_curDrawData_3799572->rect2);
		*getMemU32Ptr(0x5D4594, 1305756) = nox_draw_curDrawData_3799572->clip.min_x;
		*getMemU32Ptr(0x5D4594, 1305760) = nox_draw_curDrawData_3799572->clip.min_y;
		*getMemU32Ptr(0x5D4594, 1305764) = nox_draw_curDrawData_3799572->clip.max_x;
		*getMemU32Ptr(0x5D4594, 1305768) = nox_draw_curDrawData_3799572->clip.max_y;
		*getMemU32Ptr(0x5D4594, 1305732) = nox_draw_curDrawData_3799572->rect2.min_x;
		*getMemU32Ptr(0x5D4594, 1305736) = nox_draw_curDrawData_3799572->rect2.min_y;
		*getMemU32Ptr(0x5D4594, 1305740) = nox_draw_curDrawData_3799572->rect2.max_x;
		v1 = nox_draw_curDrawData_3799572->rect2.max_y;
		dword_5d4594_1305748 = 1;
		*getMemU32Ptr(0x5D4594, 1305744) = v1;
	}
	return result;
}

//----- (0049F860) --------------------------------------------------------
int sub_49F860() {
	int result; // eax

	result = dword_5d4594_1305748;
	if (dword_5d4594_1305748) {
		nox_draw_curDrawData_3799572->flag_0 = *getMemU32Ptr(0x5D4594, 1305772);
		nox_rect* v1 = &nox_draw_curDrawData_3799572->clip;
		v1->min_x = *getMemU32Ptr(0x5D4594, 1305756);
		v1->min_y = *getMemU32Ptr(0x5D4594, 1305760);
		v1->max_x = *getMemU32Ptr(0x5D4594, 1305764);
		v1->max_y = *getMemU32Ptr(0x5D4594, 1305768);
		nox_rect* v2 = &nox_draw_curDrawData_3799572->rect2;
		v2->min_x = *getMemU32Ptr(0x5D4594, 1305732);
		v2->min_y = *getMemU32Ptr(0x5D4594, 1305736);
		result = *getMemU32Ptr(0x5D4594, 1305740);
		v2->max_x = *getMemU32Ptr(0x5D4594, 1305740);
		v2->max_y = *getMemU32Ptr(0x5D4594, 1305744);
		dword_5d4594_1305748 = 0;
	}
	return result;
}

//----- (0049F8E0) --------------------------------------------------------
bool sub_49F8E0(int x, int y, int d) {
	return x - d < nox_draw_curDrawData_3799572->clip.min_x || x + d >= nox_draw_curDrawData_3799572->clip.max_x ||
		   y - d < nox_draw_curDrawData_3799572->clip.min_y || y + d >= nox_draw_curDrawData_3799572->clip.max_y;
}

//----- (0049F930) --------------------------------------------------------
int4* nox_xxx_utilRect_49F930(int4* a1, int4* a2, int4* a3) {
	int v3;       // ecx
	int v4;       // edx
	int v5;       // ebx
	int v6;       // edi
	int4* result; // eax

	v3 = a3->field_0;
	if (a2->field_0 >= a3->field_0) {
		v3 = a2->field_0;
	}
	v4 = a3->field_8;
	if (a2->field_8 <= v4) {
		v4 = a2->field_8;
	}
	if (v3 >= v4) {
		return 0;
	}
	v5 = a3->field_4;
	if (a2->field_4 >= v5) {
		v5 = a2->field_4;
	}
	v6 = a3->field_C;
	if (a2->field_C <= v6) {
		v6 = a2->field_C;
	}
	if (v5 >= v6) {
		return 0;
	}
	result = a1;
	a1->field_0 = v3;
	a1->field_4 = v5;
	a1->field_8 = v4;
	a1->field_C = v6;
	return result;
}

//----- (0049F990) --------------------------------------------------------
int sub_49F990(int* a1, int* a2, int* a3, int* a4) {
	int v4;  // ebx
	int v5;  // edi
	int v6;  // esi
	int v7;  // ecx
	int v8;  // ebp
	int v9;  // eax
	int v10; // edx
	int v12; // eax
	int v13; // eax
	int v14; // edx
	int v15; // eax
	int v16; // eax
	int v17; // eax
	int v18; // edx
	int v19; // eax
	int v20; // [esp+10h] [ebp-14h]
	int v21; // [esp+10h] [ebp-14h]
	int v22; // [esp+14h] [ebp-10h]
	int v23; // [esp+18h] [ebp-Ch]
	int v24; // [esp+1Ch] [ebp-8h]
	int v25; // [esp+20h] [ebp-4h]

	v4 = nox_draw_curDrawData_3799572->rect2.min_x;
	v24 = nox_draw_curDrawData_3799572->rect2.max_y;
	v23 = nox_draw_curDrawData_3799572->rect2.min_y;
	v5 = *a2;
	v25 = nox_draw_curDrawData_3799572->rect2.max_x;
	v6 = *a3;
	v7 = *a1;
	v8 = *a4;
	v9 = 0;
	if (*a1 >= v4) {
		if (v7 > (int)nox_draw_curDrawData_3799572->rect2.max_x) {
			v9 = 2;
		}
	} else {
		v9 = 1;
	}
	if (v5 >= v23) {
		if (v5 > v24) {
			LOBYTE(v9) = v9 | 4;
		}
	} else {
		LOBYTE(v9) = v9 | 8;
	}
	v22 = 0;
	if (v6 >= v4) {
		if (v6 > v25) {
			v22 = 2;
		}
	} else {
		v22 = 1;
	}
	if (v8 >= v23) {
		if (v8 <= v24) {
			goto LABEL_18;
		}
		v10 = v22 | 4;
	} else {
		v10 = v22 | 8;
	}
	v22 = v10;
LABEL_18:
	if (!(v9 | v22)) {
		return 1;
	}
	if (v9 & v22) {
		return 0;
	}
	if (v9) {
		if (v9 & 8) {
			if (v8 == v5) {
				return 0;
			}
			v12 = (v23 - v5) * (v6 - v7) / (v8 - v5);
			v5 = nox_draw_curDrawData_3799572->rect2.min_y;
			v7 += v12;
		} else if (v9 & 4) {
			if (v8 == v5) {
				return 0;
			}
			v13 = (v24 - v5) * (v6 - v7) / (v8 - v5);
			v5 = nox_draw_curDrawData_3799572->rect2.max_y;
			v7 += v13;
		}
		if (v7 <= v25) {
			if (v7 < v4) {
				if (v6 == v7) {
					return 0;
				}
				v15 = (v4 - v7) * (v8 - v5) / (v6 - v7);
				v7 = nox_draw_curDrawData_3799572->rect2.min_x;
				v5 += v15;
			}
		} else {
			v20 = v6 - v7;
			if (v6 == v7) {
				return 0;
			}
			v14 = v25 - v7;
			v7 = nox_draw_curDrawData_3799572->rect2.max_x;
			v5 += v14 * (v8 - v5) / v20;
		}
	}
	if (v22) {
		if (v22 & 8) {
			if (v8 == v5) {
				return 0;
			}
			v16 = (v6 - v7) * (v23 - v8) / (v8 - v5);
			v8 = nox_draw_curDrawData_3799572->rect2.min_y;
			v6 += v16;
		} else if (v22 & 4) {
			if (v8 == v5) {
				return 0;
			}
			v17 = (v6 - v7) * (v24 - v8) / (v8 - v5);
			v8 = nox_draw_curDrawData_3799572->rect2.max_y;
			v6 += v17;
		}
		if (v6 <= v25) {
			if (v6 < v4) {
				if (v6 == v7) {
					return 0;
				}
				v19 = (v4 - v6) * (v8 - v5) / (v6 - v7);
				v6 = nox_draw_curDrawData_3799572->rect2.min_x;
				v8 += v19;
			}
		} else {
			v21 = v6 - v7;
			if (v6 == v7) {
				return 0;
			}
			v18 = v25 - v6;
			v6 = nox_draw_curDrawData_3799572->rect2.max_x;
			v8 += v18 * (v8 - v5) / v21;
		}
	}
	*a1 = v7;
	*a2 = v5;
	*a3 = v6;
	*a4 = v8;
	if (v7 >= v4 && v7 <= v25 && v5 >= v23 && v5 <= v24 && v6 >= v4 && v6 <= v25 && v8 >= v23 && v8 <= v24) {
		return 1;
	}
	return 0;
}

//----- (0049FDB0) --------------------------------------------------------
void sub_49FDB0(int a1) {
	unsigned char* v1; // ebx
	int j;             // esi
	int v3;            // eax
	unsigned char* v4; // ebx
	int i;             // esi
	int v6;            // eax
	int v7;            // [esp+0h] [ebp-90h]
	char v8[140];      // [esp+4h] [ebp-8Ch]

	if (!dword_5d4594_1305788) {
		if (nox_xxx_check_flag_aaa_43AF70()) {
			v7 = 0;
			if (*getMemU32Ptr(0x587000, 166016 + 4 * a1) > 0) {
				v4 = getMemAt(0x587000, 166032 + 80 * a1);
				do {
					for (i = 0; i < (char)*v4; ++i) {
						v6 = 8 * (12 * a1 + (char)v4[i + 1]);
						sub_420DA0(*getMemFloatPtr(0x587000, 165360 + v6), *getMemFloatPtr(0x587000, 165364 + v6));
					}
					strcpy(&v8[4], *((const char**)v4 + 3));
					sub_4211D0((int)v8);
					sub_4214D0();
					v4 += 16;
					++v7;
				} while (v7 < *getMemIntPtr(0x587000, 166016 + 4 * a1));
			}
		} else {
			v1 = getMemAt(0x587000, 165744);
			do {
				for (j = 0; j < (char)*v1; ++j) {
					v3 = 8 * (char)v1[j + 1];
					sub_420DA0(*getMemFloatPtr(0x587000, 165104 + v3), *getMemFloatPtr(0x587000, 165108 + v3));
				}
				strcpy(&v8[4], *((const char**)v1 + 3));
				sub_4211D0((int)v8);
				sub_4214D0();
				v1 += 16;
			} while ((int)v1 < (int)getMemAt(0x587000, 166016));
		}
		dword_5d4594_1305788 = 1;
	}
}

//----- (0049FF20) --------------------------------------------------------
uint32_t* sub_49FF20() {
	uint32_t* result; // eax

	result = *(uint32_t**)&dword_5d4594_1305788;
	if (dword_5d4594_1305788) {
		result = sub_421B10();
		dword_5d4594_1305788 = 0;
	}
	return result;
}

//----- (0049FF40) --------------------------------------------------------
char* nox_client_getChatMap_49FF40(short* a1) {
	int v1;                            // edx
	nox_player_polygon_check_data* v2; // eax
	char* result;                      // eax
	int2 v4;                           // [esp+0h] [ebp-8h]

	v1 = a1[1] + 10;
	v4.field_0 = *a1 + 10;
	v4.field_4 = v1;
	v2 = nox_xxx_polygonIsPlayerInPolygon_4217B0(&v4, 0);
	if (v2 || (v2 = (nox_player_polygon_check_data*)sub_421990(&v4, 100.0, 0)) != 0) {
		result = (char*)&v2->field_0[1];
	} else {
		result = *(char**)getMemAt(0x587000, 165756);
	}
	return result;
}

//----- (0049FFA0) --------------------------------------------------------
int* sub_49FFA0(int a1) {
	int* result; // eax
	int* v2;     // esi
	int* v3;     // edi

	if (!*getMemU32Ptr(0x5D4594, 1305808)) {
		nox_common_list_clear_425760(&nox_gui_wol_servers_list);
	}
	result = nox_common_list_getFirstSafe_425890(&nox_gui_wol_servers_list);
	v2 = result;
	if (result) {
		do {
			v3 = nox_common_list_getNextSafe_4258A0(v2);
			sub_425920((uint32_t**)v2);
			if (a1) {
				nox_xxx_windowDestroyMB_46C4E0((uint32_t*)v2[7]);
			}
			free(v2);
			v2 = v3;
		} while (v3);
		*getMemU32Ptr(0x5D4594, 1305808) = 1;
	} else {
		*getMemU32Ptr(0x5D4594, 1305808) = 1;
	}
	return result;
}

//----- (004A0020) --------------------------------------------------------
char* sub_4A0020() { return &nox_gui_wol_servers_list; }

//----- (004A0030) --------------------------------------------------------
int nox_wol_servers_addResult_4A0030(nox_gui_server_ent_t* srv) {
	int* v3;     // edi
	wchar_t* v6; // ebp
	wchar_t* v7; // eax
	wchar_t* v8; // ebp
	wchar_t* v9; // eax

	nox_gui_server_ent_t* rec = calloc(1, sizeof(nox_gui_server_ent_t));
	memcpy(rec, srv, sizeof(nox_gui_server_ent_t));

	int v2 = 0;
	switch (nox_wol_servers_sorting_166704) {
	case 0: // by name (asc)
		if (nox_gui_wol_servers_list.field_1 == &nox_gui_wol_servers_list) {
			return sub_425790(&nox_gui_wol_servers_list, rec);
		}
		v3 = nox_common_list_getFirstSafe_425890(&nox_gui_wol_servers_list);
		if (!v3) {
			nox_common_list_append_4258E0(&nox_gui_wol_servers_list, rec);
			return 0;
		}
		do {
			if (_strcmpi(rec->server_name, (const char*)v3 + 120) <= 0) {
				nox_common_list_append_4258E0((int)v3, rec);
				return v2;
			}
			++v2;
			v3 = nox_common_list_getNextSafe_4258A0(v3);
		} while (v3);
		nox_common_list_append_4258E0(&nox_gui_wol_servers_list, rec);
		return v2;
	case 1: // by name (desc)
		if (nox_gui_wol_servers_list.field_1 == &nox_gui_wol_servers_list) {
			return sub_425790(&nox_gui_wol_servers_list, rec);
		}
		v3 = nox_common_list_getFirstSafe_425890(&nox_gui_wol_servers_list);
		if (!v3) {
			nox_common_list_append_4258E0(&nox_gui_wol_servers_list, rec);
			return 0;
		}
		while (_strcmpi(rec->server_name, (const char*)v3 + 120) < 0) {
			++v2;
			v3 = nox_common_list_getNextSafe_4258A0(v3);
			if (!v3) {
				nox_common_list_append_4258E0(&nox_gui_wol_servers_list, rec);
				return v2;
			}
		}
		nox_common_list_append_4258E0((int)v3, rec);
		return v2;
	case 2: // by players (asc)
		rec->sort_key = rec->players;
		return sub_425790(&nox_gui_wol_servers_list, rec);
	case 3: // by players (desc)
		rec->sort_key = 32 - rec->players;
		return sub_425790(&nox_gui_wol_servers_list, rec);
	case 4: // by mode (asc)
		if (nox_gui_wol_servers_list.field_1 == &nox_gui_wol_servers_list) {
			return sub_425790(&nox_gui_wol_servers_list, rec);
		}
		v6 = nox_gui_wol_gameModeString_43BCB0(rec->flags);
		v3 = nox_common_list_getFirstSafe_425890(&nox_gui_wol_servers_list);
		if (!v3) {
			nox_common_list_append_4258E0(&nox_gui_wol_servers_list, rec);
			return 0;
		}
		while (1) {
			v7 = nox_gui_wol_gameModeString_43BCB0(*(uint16_t*)((char*)v3 + 163));
			if (nox_wcscmp(v6, v7) <= 0) {
				nox_common_list_append_4258E0((int)v3, rec);
				return v2;
			}
			++v2;
			v3 = nox_common_list_getNextSafe_4258A0(v3);
			if (!v3) {
				nox_common_list_append_4258E0(&nox_gui_wol_servers_list, rec);
				return v2;
			}
		}
	case 5: // by mode (desc)
		if (nox_gui_wol_servers_list.field_1 == &nox_gui_wol_servers_list) {
			return sub_425790(&nox_gui_wol_servers_list, rec);
		}
		v8 = nox_gui_wol_gameModeString_43BCB0(rec->flags);
		v3 = nox_common_list_getFirstSafe_425890(&nox_gui_wol_servers_list);
		if (!v3) {
			nox_common_list_append_4258E0(&nox_gui_wol_servers_list, rec);
			return 0;
		}
		while (1) {
			v9 = nox_gui_wol_gameModeString_43BCB0(*(uint16_t*)((char*)v3 + 163));
			if (nox_wcscmp(v8, v9) >= 0) {
				break;
			}
			++v2;
			v3 = nox_common_list_getNextSafe_4258A0(v3);
			if (!v3) {
				nox_common_list_append_4258E0(&nox_gui_wol_servers_list, rec);
				return v2;
			}
		}
		nox_common_list_append_4258E0((int)v3, rec);
		return v2;
	case 6: // by ping (asc)
		rec->sort_key = rec->ping;
		return sub_425790(&nox_gui_wol_servers_list, rec);
	case 7: // by ping (desc)
		rec->sort_key = 1000 - rec->ping;
		return sub_425790(&nox_gui_wol_servers_list, rec);
	case 8: // by status (asc)
		rec->sort_key = rec->status & 0x30;
		return sub_425790(&nox_gui_wol_servers_list, rec);
	case 9: // by status (desc)
		rec->sort_key = 48 - (rec->status & 0x30);
		return sub_425790(&nox_gui_wol_servers_list, rec);
	default:
		return 0;
	}
}

//----- (004A0290) --------------------------------------------------------
void nox_wol_servers_sortBtnHandler_4A0290(int id) {
	switch (id - 10047) {
	case 0:
		nox_wol_servers_sorting_166704 = (nox_wol_servers_sorting_166704 == 0) + 0;
		break;
	case 1:
		nox_wol_servers_sorting_166704 = (nox_wol_servers_sorting_166704 == 2) + 2;
		break;
	case 2:
		nox_wol_servers_sorting_166704 = (nox_wol_servers_sorting_166704 == 4) + 4;
		break;
	case 3:
		nox_wol_servers_sorting_166704 = (nox_wol_servers_sorting_166704 == 6) + 6;
		break;
	case 4:
		nox_wol_servers_sorting_166704 = (nox_wol_servers_sorting_166704 == 8) + 8;
		break;
	}
}

//----- (004A0330) --------------------------------------------------------
int sub_4A0330(int* a1) {
	int v1; // esi
	int* i; // eax

	v1 = 0;
	for (i = nox_common_list_getFirstSafe_425890(&nox_gui_wol_servers_list); i;
		 i = nox_common_list_getNextSafe_4258A0(i)) {
		if (i == a1) {
			break;
		}
		++v1;
	}
	return v1;
}

//----- (004A0360) --------------------------------------------------------
int* sub_4A0360() {
	int* result; // eax
	int* i;      // esi

	result = nox_common_list_getFirstSafe_425890(&nox_gui_wol_servers_list);
	for (i = result; result; i = result) {
		nox_gui_wol_newServerLine_43B7C0(i);
		result = nox_common_list_getNextSafe_4258A0(i);
	}
	return result;
}

//----- (004A0390) --------------------------------------------------------
int* sub_4A0390() {
	uint32_t* v0; // ecx
	int* v1;      // esi
	int* v2;      // edi
	int v4[3];    // [esp+0h] [ebp-Ch]
	uint32_t* v5; // [esp+4h] [ebp-8h]

	nox_common_list_clear_425760(&v4);
	v0 = nox_gui_wol_servers_list.field_1;
	v4[0] = nox_gui_wol_servers_list.field_0;
	v5 = nox_gui_wol_servers_list.field_1;
	if (nox_gui_wol_servers_list.field_0) {
		*(uint32_t*)((uint32_t)nox_gui_wol_servers_list.field_0 + 4) = &v4;
		v0 = v5;
	}
	if (v0) {
		*v0 = &v4;
	}
	nox_common_list_clear_425760(&nox_gui_wol_servers_list);
	v1 = nox_common_list_getFirstSafe_425890(&v4);
	if (v1) {
		do {
			v2 = nox_common_list_getNextSafe_4258A0(v1);
			nox_wol_servers_addResult_4A0030(v1);
			v1 = v2;
		} while (v2);
	}
	return sub_4A0360();
}

//----- (004A0410) --------------------------------------------------------
int sub_4A0410(const char* a1, short a2) {
	int* v2; // edi

	v2 = nox_common_list_getFirstSafe_425890(&nox_gui_wol_servers_list);
	if (!v2) {
		return 1;
	}
	while (strcmp(a1, (const char*)v2 + 12) || a2 != *(uint16_t*)((char*)v2 + 109)) {
		v2 = nox_common_list_getNextSafe_4258A0(v2);
		if (!v2) {
			return 1;
		}
	}
	return 0;
}

//----- (004A0490) --------------------------------------------------------
int* sub_4A0490(int a1) {
	int* result; // eax

	result = nox_common_list_getFirstSafe_425890(&nox_gui_wol_servers_list);
	if (!result) {
		return 0;
	}
	while (result[9] != a1) {
		result = nox_common_list_getNextSafe_4258A0(result);
		if (!result) {
			return 0;
		}
	}
	return result;
}

//----- (004A04C0) --------------------------------------------------------
int* sub_4A04C0(int a1) {
	int v1;      // esi
	int* result; // eax

	v1 = 0;
	result = nox_common_list_getFirstSafe_425890(&nox_gui_wol_servers_list);
	if (!result) {
		return 0;
	}
	while (a1 != v1) {
		++v1;
		result = nox_common_list_getNextSafe_4258A0(result);
		if (!result) {
			return 0;
		}
	}
	return result;
}

//----- (004A04F0) --------------------------------------------------------
int* sub_4A04F0(char* a1) {
	int* v1; // esi

	v1 = nox_common_list_getFirstSafe_425890(&nox_gui_wol_servers_list);
	if (!v1) {
		return 0;
	}
	while (_strcmpi((const char*)(v1[8] + 52), a1)) {
		v1 = nox_common_list_getNextSafe_4258A0(v1);
		if (!v1) {
			return 0;
		}
	}
	return v1;
}

//----- (004A0540) --------------------------------------------------------
void sub_4A0540(void* lpMem) {
	sub_425920((uint32_t**)lpMem);
	nox_xxx_windowDestroyMB_46C4E0(*((uint32_t**)lpMem + 7));
	free(lpMem);
}

//----- (004A0560) --------------------------------------------------------
int nox_xxx_getConnResult_4A0560() { return nox_wol_servers_sorting_166704; }
