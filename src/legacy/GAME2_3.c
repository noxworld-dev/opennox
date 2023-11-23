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

extern uint32_t dword_8531A0_2572;
extern uint32_t dword_5d4594_1303508;
extern uint32_t dword_5d4594_1200776;
extern uint32_t dword_5d4594_1203832;
extern uint32_t dword_5d4594_1200796;
extern uint32_t dword_5d4594_1305788;
extern void* nox_alloc_healthChange_1301772;
extern uint32_t nox_server_sanctuaryHelp_54276;
extern uint32_t dword_5d4594_1197308;
extern uint32_t dword_5d4594_1197372;
extern void* nox_alloc_friendList_1203860;
extern uint32_t dword_5d4594_1305748;
extern uint32_t dword_5d4594_1197328;
extern uint32_t dword_5d4594_1197352;
extern uint32_t dword_5d4594_1197336;
extern uint32_t dword_5d4594_1197356;
extern uint32_t dword_5d4594_1301780;
extern uint32_t dword_5d4594_1203836;
extern uint32_t dword_5d4594_1203840;
extern uint32_t dword_5d4594_1197332;
extern void* nox_alloc_chat_1197364;
extern uint32_t dword_5d4594_1203864;
extern uint32_t dword_5d4594_1193712;
extern uint32_t nox_server_connectionType_3596;
extern uint32_t dword_5d4594_1301776;
extern uint32_t dword_5d4594_1197316;
extern void* nox_alloc_pixelSpan_1301844;
extern uint32_t dword_5d4594_1197320;
extern uint32_t nox_wol_servers_sorting_166704;
extern uint32_t dword_5d4594_1197324;
extern uint32_t dword_5d4594_1305680;
extern uint32_t dword_5d4594_1301848;
extern uint32_t dword_5d4594_1197312;
extern uint32_t dword_5d4594_1303452;
extern uint32_t dword_5d4594_1305684;
extern uint32_t nox_player_netCode_85319C;
extern int nox_win_width;
extern int nox_win_height;

extern uint32_t nox_color_white_2523948;
extern uint32_t nox_color_yellow_2589772;
extern uint32_t nox_color_black_2650656;

const int nox_max_npcs = 1024;
nox_npc* npc_array;

nox_render_data_t* nox_draw_curDrawData_3799572 = 0;

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
				result = __sync_lock_test_and_set((volatile signed int*)it, result);
			}
		}
		*pix = result;
		++pix;
	}
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
			sub_48CAD0();
			goto LABEL_15;
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
	const wchar2_t* v4;  // eax
	wchar2_t* v5;        // ebx
	int v6;             // esi
	const wchar2_t* v7;  // edi
	int result;         // eax
	int v9;             // ebp
	wchar2_t* v10;       // ebx
	int v11;            // esi
	const wchar2_t* v12; // edi

	v0 = 0;
	dword_5d4594_1197328 = dword_5d4594_1197324;
	memcpy(getMemAt(0x5D4594, 1195512), getMemAt(0x5D4594, 1193720), 0x700u);
	dword_5d4594_1197324 = 0;
	v1 = (int*)nox_window_call_field_94(*(int*)&dword_5d4594_1197316, 16404, 0, 0);
	v2 = v1;
	for (i = *v1; i != -1; ++v2) {
		v4 = (const wchar2_t*)nox_window_call_field_94(*(int*)&dword_5d4594_1197316, 16406, i, 0);
		if (v4) {
			nox_wcscpy((wchar2_t*)getMemAt(0x5D4594, 1193720 + 56 * dword_5d4594_1197324), v4);
			++dword_5d4594_1197324;
		}
		i = v2[1];
	}
	if (*(int*)&dword_5d4594_1197328 > 0) {
		v5 = (wchar2_t*)getMemAt(0x5D4594, 1195512);
		do {
			v6 = 0;
			if (*(int*)&dword_5d4594_1197324 <= 0) {
				nox_xxx_voteSend_48D260(v5);
			} else {
				v7 = (const wchar2_t*)getMemAt(0x5D4594, 1193720);
				while (1) {
					if (!nox_wcscmp(v5, v7)) {
						break;
					}
					++v6;
					v7 += 28;
					if (v6 >= *(int*)&dword_5d4594_1197324) {
						nox_xxx_voteSend_48D260(v5);
						break;
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
		v10 = (wchar2_t*)getMemAt(0x5D4594, 1193720);
		do {
			v11 = 0;
			if (*(int*)&dword_5d4594_1197328 <= 0) {
				nox_xxx_netSendRenameMb_48D2D0(v10);
			} else {
				v12 = (const wchar2_t*)getMemAt(0x5D4594, 1195512);
				while (1) {
					if (!nox_wcscmp(v10, v12)) {
						break;
					}
					++v11;
					v12 += 28;
					if (v11 >= *(int*)&dword_5d4594_1197328) {
						nox_xxx_netSendRenameMb_48D2D0(v10);
						break;
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
char* nox_xxx_voteSend_48D260(wchar2_t* a1) {
	char* result; // eax
	int v2;       // esi
	char v3[52];  // [esp+8h] [ebp-34h]

	result = nox_common_playerInfoGetFirst_416EA0();
	v2 = (int)result;
	if (result) {
		while (nox_wcscmp((const wchar2_t*)(v2 + 4704), a1)) {
			result = nox_common_playerInfoGetNext_416EE0(v2);
			v2 = (int)result;
			if (!result) {
				return result;
			}
		}
		*(uint16_t*)v3 = 750;
		nox_wcscpy((wchar2_t*)&v3[2], a1);
		result = (char*)nox_netlist_addToMsgListCli_40EBC0(31, 0, v3, 52);
	}
	return result;
}

//----- (0048D2D0) --------------------------------------------------------
char* nox_xxx_netSendRenameMb_48D2D0(wchar2_t* a1) {
	char* result; // eax
	int v2;       // esi
	char v3[52];  // [esp+8h] [ebp-34h]

	result = nox_common_playerInfoGetFirst_416EA0();
	v2 = (int)result;
	if (result) {
		while (nox_wcscmp((const wchar2_t*)(v2 + 4704), a1)) {
			result = nox_common_playerInfoGetNext_416EE0(v2);
			v2 = (int)result;
			if (!result) {
				return result;
			}
		}
		*(uint16_t*)v3 = 238;
		nox_wcscpy((wchar2_t*)&v3[2], a1);
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
			nox_common_list_remove_425920((uint32_t**)v1);
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
			nox_common_list_remove_425920((uint32_t**)v0);
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
wchar2_t* nox_xxx_createTextBubble_48D880(int a1, wchar2_t* a2) {
	wchar2_t* v2;     // esi
	int v3;          // ebx
	wchar2_t* result; // eax
	int v5;          // eax
	int v6;          // eax

	v2 = (wchar2_t*)nox_xxx_netCode2ChatBubble_48D850(*(unsigned short*)(a1 + 1));
	if (v2) {
		v3 = 0;
	} else {
		result = (wchar2_t*)nox_alloc_class_new_obj_zero(*(uint32_t**)&nox_alloc_chat_1197364);
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
		v6 = gameFPS() * (v5 + 2);
	}
	result = (wchar2_t*)(gameFrame() + v6);
	*((uint32_t*)v2 + 160) = result;
	if (v3) {
		result = *(wchar2_t**)getMemAt(0x5D4594, 1197368);
		if (*getMemU32Ptr(0x5D4594, 1197368)) {
			result = *(wchar2_t**)&dword_5d4594_1197372;
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
	int v7;       // eax
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
					v6 = nox_xxx_getTeamByID_418AB0(*((unsigned char*)v4 + 4));
					if (v6) {
						v7 = nox_xxx_materialGetTeamColor_418D50((int)v6);
						v21 = v7;
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
						goto LABEL_26;
					}
					v19 = v21 - *(uint32_t*)(v2 + 676) - v24;
				}
				*(uint32_t*)(v2 + 652) = v19;
				*v13 = 0;
			LABEL_26:
				a1a.field_0 = *(uint32_t*)(v2 + 648);
				a1a.field_4 = *(uint32_t*)(v2 + 652);
				a1a.field_8 = *(uint32_t*)(v2 + 648) + *v11;
				a1a.field_C = *(uint32_t*)(v2 + 676) + *(uint32_t*)(v2 + 652);
				sub_48E000(&a1a, (uint32_t*)(v2 + 664));
				*(uint32_t*)(v2 + 648) = a1a.field_0;
				*(uint32_t*)(v2 + 652) = a1a.field_4;
			}
			if (gameFrame() > *(int*)(v2 + 640)) {
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
			a1->field_4 = v2;
			*a2 = 0;
			goto LABEL_13;
		}
	} else {
		v2 = 55;
		v11.field_C = 55;
		v3 = nox_xxx_pointInRect_4281F0((int2*)a1, &v11);
		if (v3) {
			a1->field_4 = v2;
			*a2 = 0;
			goto LABEL_13;
		}
		v3 = nox_xxx_pointInRect_4281F0((int2*)&a1->field_8, &v11);
		if (v3) {
			a1->field_4 = v2;
			*a2 = 0;
			goto LABEL_13;
		}
	}
LABEL_13:
	if (nox_client_getRenderGUI()) {
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
		v9 = (char*)result + v7[163] + v7[169];
		result = a5;
		*a5 = (int)v9;
		break;
	case 8:
		v7 = a3;
		*a4 = (int)result + a3[162] + a3[168];
		v9 = (char*)result + v7[163] + v7[169];
		result = a5;
		*a5 = (int)v9;
		break;
	case 0x10:
		*a4 = a2[162];
		v8 = a3[163] - a2[169] - (uint32_t)result;
		result = a5;
		*a5 = v8;
		return result;
	case 0x20:
		*a4 = a2[162];
		v7 = a3;
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
	v7[80] = gameFrame();
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
		v24 = nox_xxx_cliGenerateAlias_57B9A0((int)getMemAt(0x5D4594, 1198020), v3, v6, gameFrame());
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
			v16[72] = gameFrame();
			v17 = (v11 >> 4) & 7;
			*((uint8_t*)v16 + 297) = v17;
			if (v17 > 3u) {
				*((uint8_t*)v16 + 297) = v17 + 1;
			}
			if (v16[69] != v26) {
				v18 = gameFrame();
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
		v24 = nox_xxx_cliGenerateAlias_57B9A0((int)getMemAt(0x5D4594, 1198020), v6, v9, gameFrame());
		if (v24 != -1) {
			sub_57BA10((int)getMemAt(0x5D4594, 1198020 + 8 * v24), v6, v9, gameFrame() + 60);
			v26[1] = v24;
			v26[0] = -91;
			*(uint16_t*)&v26[2] = v6;
			*(uint16_t*)&v26[4] = v8;
			*(uint32_t*)&v26[6] = gameFrame() + 60;
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
		v18[72] = gameFrame();
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
			v23 = gameFrame();
			*(uint32_t*)(v19 + 276) = v28;
			*(uint32_t*)(v19 + 316) = v23;
		}
		++v14;
	} else {
		v18[72] = gameFrame();
		nox_xxx_sprite_49AA00_drawable(v18);
	}
	*v13 = *(uint32_t*)(v19 + 12);
	v13[1] = *(uint32_t*)(v19 + 16);
	return (unsigned char*)(v14 - (uint32_t)a1);
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
			v1 = dword_5d4594_1203836;
			goto LABEL_9;
		}
		if (v2 == *getMemU32Ptr(0x5D4594, 1203848)) {
			*(uint16_t*)(a1 + 8) = *getMemU16Ptr(0x5D4594, 1203852);
			v1 = dword_5d4594_1203836;
			goto LABEL_9;
		}
	}
LABEL_9:
	v3 = 24 * v1;
	*getMemU32Ptr(0x5D4594, 1201428 + v3) = *(unsigned short*)(a1 + 2);
	*getMemU32Ptr(0x5D4594, 1201432 + v3) = *(unsigned short*)(a1 + 4);
	*getMemU32Ptr(0x5D4594, 1201436 + v3) = *(unsigned short*)(a1 + 6);
	*getMemU32Ptr(0x5D4594, 1201440 + v3) = *(unsigned short*)(a1 + 8);
	*getMemU32Ptr(0x5D4594, 1201444 + v3) = *(unsigned char*)(a1 + 10);
	*getMemU32Ptr(0x5D4594, 1201448 + v3) = gameFrame();
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
		if ((unsigned int)(gameFrame() - *getMemU32Ptr(0x5D4594, 1201448 + 24 * v0)) <= 0x5A) {
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
	wchar2_t v28[32]; // [esp+2Ch] [ebp-C0h]
	wchar2_t v29[32]; // [esp+6Ch] [ebp-80h]
	wchar2_t v30[32]; // [esp+ACh] [ebp-40h]
	nox_thing* t9 = 0;

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
			nox_swprintf(v29, (const wchar2_t*)v5 + 2352);
		}
	}
	if (a1[1]) {
		v6 = nox_common_playerInfoGetByID_417040(a1[1]);
		if (v6) {
			if (v3) {
				nox_swprintf(v28, L"+%s", v6 + 4704);
			} else {
				nox_swprintf(v28, (const wchar2_t*)v6 + 2352);
			}
		}
	}
	if (a1[2]) {
		v7 = nox_common_playerInfoGetByID_417040(a1[2]);
		if (v7) {
			nox_swprintf(v30, (const wchar2_t*)v7 + 2352);
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
		v8 = *getMemU32Ptr(0x5D4594, 1203828);
		goto LABEL_28;
	}
	t9 = nox_get_thing(a1[3]);
	if (!t9) {
		v8 = *getMemU32Ptr(0x5D4594, 1203828);
		goto LABEL_28;
	}
	if (t9->pri_class & 0x1001000) {
		sub_4B9650(a1[3]);
	}
	v8 = t9->pretty_image;
LABEL_26:
	if (!v8) {
		v8 = *getMemU32Ptr(0x5D4594, 1203828);
	}
LABEL_28:
	nox_draw_imageMeta_47D5C0(v8, &v27, &v26, &v23, &v25);
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
			nox_xxx_drawSetTextColor_434390(dword_8531A0_2572);
		}
		v15 = nox_xxx_drawString_43F6E0(v24, (short*)v29, v14 / 2, v17);
	}
	if (a1[1]) {
		nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2597996));
		if (a1[1] == nox_player_netCode_85319C) {
			nox_xxx_drawSetTextColor_434390(dword_8531A0_2572);
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
			nox_xxx_drawSetTextColor_434390(dword_8531A0_2572);
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

//----- (00495B50) --------------------------------------------------------
void sub_495B50(void* a1p) {
	uint32_t* a1 = a1p;
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
		if (*(uint32_t*)(a1 + 12) == *(uint32_t*)(a1 + 32) && *(uint32_t*)(a1 + 16) == *(uint32_t*)(a1 + 36)) {
			*(uint8_t*)(a2 + 56) = 0;
			return result;
		}
	} else {
		v5 = (uint32_t*)(a2 + 8);
		while (1) {
			if (!(*v5 == v5[2] || v5[1] == v5[3])) {
				break;
			}
			++v3;
			v5 += 2;
			if (v3 >= result) {
				if (*(uint32_t*)(a1 + 12) == *(uint32_t*)(a1 + 32) && *(uint32_t*)(a1 + 16) == *(uint32_t*)(a1 + 36)) {
					*(uint8_t*)(a2 + 56) = 0;
					return result;
				}
				break;
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
		while (1) {
			if (!(*v5 == v5[2] || v5[1] == v5[3])) {
				v6 = a1;
				break;
			}
			++v3;
			v5 += 2;
			if (v3 >= v4) {
				v6 = a1;
				if (a1[3] == a1[8]) {
					result = a1[9];
					if (a1[4] == result) {
						*(uint8_t*)(a2 + 56) = 0;
						return result;
					}
				}
				break;
			}
		}
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

//----- (00495FC0) --------------------------------------------------------
void sub_495FC0(void* a1p, nox_drawable* a2p) {
	uint32_t* a1 = a1p;
	int a2 = a2p;
	int v3;           // edx

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
	while (1) {
		if (v8 != getMemAt(0x5D4594, 1217484)) {
			if (*(uint32_t*)v8) {
				*(uint32_t*)(*(uint32_t*)v8 + 120) |= 0x1000000u;
				goto LABEL_5;
			}
			return 0;
		}
	LABEL_5:
		v8 += 4;
		if ((int)v8 >= (int)getMemAt(0x5D4594, 1217504)) {
			*getMemU32Ptr(0x5D4594, 1217504) = 0;
			return 1;
		}
	}
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
			v3[79] = gameFrame();
			v3[81] = *a1;
			v3[82] = a1[1];
			v3[115] = nox_xxx_sprite_4CA540;
			nox_xxx_spriteToList_49BC80_drawable(v3);
			nox_xxx_spriteToSightDestroyList_49BAB0_drawable(v3);
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
void sub_499F60(int a1, int a2, int a3, short a4, char a5, char a6, char a7, char a8, char a9, int a10) {
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
		nox_xxx_sprite_45A110_drawable(v13);
	}
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
	wchar2_t v13[80]; // [esp+24h] [ebp-A0h]

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
					nox_swprintf(v13, L"%d", abs(*((short*)v8 + 2)));
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
						nox_xxx_drawSetTextColor_434390(dword_8531A0_2572);
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
	a1[5] = gameFrame();
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
	if (!nox_xxx_guiCursor_477600() && !nox_video_inFadeTransition_44E0D0()) {
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

//----- (0049BB80) --------------------------------------------------------
void* sub_49BB80(char a1) {
	void* result; // eax

	*getMemU8Ptr(0x5D4594, 1303504) = a1;
	*getMemU8Ptr(0x5D4594, 1303512) = 0;
	*getMemU32Ptr(0x5D4594, 1303516) = gameFrame();
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
		if (gameFrame() >= *getMemIntPtr(0x5D4594, 1303516)) {
			v0 = nox_xxx_spellGetPhoneme_4FE1C0(nox_player_netCode_85319C, v1);
			nox_xxx_clientPlaySoundSpecial_452D80(v0, 100);
			nox_client_setPhonemeFrame_476E00(*getMemU32Ptr(0x587000, 163576 + 4 * v1));
			*getMemU32Ptr(0x5D4594, 1303516) = gameFrame() + 3;
			dword_5d4594_1303508 = nox_xxx_updateSpellRelated_424830(*(int*)&dword_5d4594_1303508, v1);
			++*getMemU8Ptr(0x5D4594, 1303512);
		}
		if (**(uint32_t**)&dword_5d4594_1303508 == getMemByte(0x5D4594, 1303504)) {
			sub_49BBB0();
		}
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
				break;
			case 2u:
				v12 = *getMemU32Ptr(0x5D4594, 1304380);
				break;
			case 3u:
				v12 = *getMemU32Ptr(0x5D4594, 1304356);
				break;
			case 4u:
				v12 = *getMemU32Ptr(0x5D4594, 1304360);
				break;
			case 5u:
				v12 = *getMemU32Ptr(0x5D4594, 1304372);
				break;
			case 6u:
				v12 = *getMemU32Ptr(0x5D4594, 1304376);
				break;
			case 7u:
				v12 = *getMemU32Ptr(0x5D4594, 1304396);
				break;
			case 0x8Cu:
				v12 = *getMemU32Ptr(0x5D4594, 1304352);
				break;
			default:
				return result;
			}
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
int sub_49C520(nox_drawable* a1p) {
	int a1 = a1p;
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
	nox_rect rc; // [esp+10h] [ebp-10h]

	if (a3) {
		if (a4) {
			if (!nox_draw_curDrawData_3799572->flag_0 ||
				(noxSetRect(&rc, xLeft, yTop, xLeft + a3, yTop + a4),
				 nox_xxx_utilRect_49F930((int4*)&rc, (int4*)&rc, (int4*)(&nox_draw_curDrawData_3799572->clip)))) {
				nox_draw_set54RGB32_434040(a5);
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

//----- (0049D1C0) --------------------------------------------------------
int sub_49D1C0(void* a1, int a2, int a3) {
	sub_49E3C0(a1, a2, a3);
	return 0;
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
	nox_rect rcSrc;   // [esp+0h] [ebp-20h]
	nox_rect rc;      // [esp+10h] [ebp-10h]

	noxSetRect(&rc, xLeft, yTop, xLeft + a3, yTop + a4);
	result = nox_xxx_utilRect_49F930((int4*)&rcSrc, (int4*)&rc, (int4*)(&nox_draw_curDrawData_3799572->rect3));
	if (result) {
		noxCopyRect(&nox_draw_curDrawData_3799572->clip, &rcSrc);
		--rcSrc.max_x;
		--rcSrc.max_y;
		result = (int4*)noxCopyRect((&nox_draw_curDrawData_3799572->rect2), &rcSrc);
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
void nox_xxx_wndDraw_49F7F0() {
	if (!dword_5d4594_1305748) {
		*getMemU32Ptr(0x5D4594, 1305772) = nox_draw_curDrawData_3799572->flag_0;
		*getMemU32Ptr(0x5D4594, 1305756) = nox_draw_curDrawData_3799572->clip.min_x;
		*getMemU32Ptr(0x5D4594, 1305760) = nox_draw_curDrawData_3799572->clip.min_y;
		*getMemU32Ptr(0x5D4594, 1305764) = nox_draw_curDrawData_3799572->clip.max_x;
		*getMemU32Ptr(0x5D4594, 1305768) = nox_draw_curDrawData_3799572->clip.max_y;
		*getMemU32Ptr(0x5D4594, 1305732) = nox_draw_curDrawData_3799572->rect2.min_x;
		*getMemU32Ptr(0x5D4594, 1305736) = nox_draw_curDrawData_3799572->rect2.min_y;
		*getMemU32Ptr(0x5D4594, 1305740) = nox_draw_curDrawData_3799572->rect2.max_x;
		*getMemU32Ptr(0x5D4594, 1305744) = nox_draw_curDrawData_3799572->rect2.max_y;
		dword_5d4594_1305748 = 1;
	}
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
		if (0) {
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
			nox_common_list_remove_425920((uint32_t**)v2);
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
	wchar2_t* v6; // ebp
	wchar2_t* v7; // eax
	wchar2_t* v8; // ebp
	wchar2_t* v9; // eax

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
			if (nox_strcmpi(rec->server_name, (const char*)v3 + 120) <= 0) {
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
		while (nox_strcmpi(rec->server_name, (const char*)v3 + 120) < 0) {
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
