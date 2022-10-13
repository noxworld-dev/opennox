#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME2_2.h"
#include "GAME2_3.h"
#include "GAME3.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4.h"
#include "GAME5.h"
#include "GAME5_2.h"
#include "client__system__parsecmd.h"
#include "client/audio/ail/compat_mss.h"

#include "client__gui__guicon.h"
#include "client__gui__guiquit.h"
#include "client__gui__window.h"
#include "client__network__cdecode.h"
#include "client__shell__mainmenu.h"
#include "client__shell__noxworld.h"
#include "client__shell__selchar.h"
#include "client__shell__selcolor.h"

#include "MixPatch.h"
#include "client__io__win95__focus.h"
#include "client__system__ctrlevnt.h"
#include "client__video__draw_common.h"
#include "common/fs/nox_fs.h"
#include "common__binfile.h"
#include "common__net_list.h"
#include "common__strman.h"
#include "input_common.h"
#include "operators.h"

extern uint32_t dword_587000_122856;
extern uint32_t dword_5d4594_830272;
extern uint32_t dword_5d4594_829532;
extern uint32_t dword_5d4594_830200;
extern uint32_t dword_5d4594_830268;
extern uint32_t dword_5d4594_815748;
extern uint32_t dword_5d4594_830196;
extern uint32_t dword_5d4594_830252;
extern uint32_t dword_587000_109280;
extern uint32_t dword_5d4594_830112;
extern uint32_t dword_5d4594_830192;
extern uint32_t dword_5d4594_816444;
extern uint32_t dword_5d4594_830260;
extern uint32_t dword_5d4594_829544;
extern uint32_t dword_5d4594_816412;
extern uint32_t dword_5d4594_829500;
extern uint32_t dword_5d4594_830120;
extern uint32_t dword_5d4594_830256;
extern uint32_t dword_5d4594_830204;
extern uint32_t dword_5d4594_830208;
extern uint32_t dword_587000_111668;
extern uint32_t dword_5d4594_825736;
extern uint32_t dword_5d4594_830292;
extern uint32_t nox_xxx_xxxRenderGUI_587000_80832;
extern uint32_t dword_5d4594_826036;
extern uint32_t dword_5d4594_816356;
extern uint32_t dword_5d4594_826032;
extern uint32_t nox_client_renderBubbles_80844;
extern uint32_t dword_5d4594_830276;
extern uint32_t dword_5d4594_830264;
extern uint32_t dword_5d4594_829504;
extern uint32_t dword_5d4594_825744;
extern uint32_t dword_5d4594_816372;
extern uint32_t nox_client_lockHighResFloors_1193152;
extern void* dword_587000_81128;
extern uint32_t dword_5d4594_2649712;
extern uint32_t nox_client_translucentFrontWalls_805844;
extern uint64_t qword_581450_9552;
extern uint64_t qword_581450_9544;
extern uint32_t dword_5d4594_830148;
extern uint32_t dword_5d4594_830116;
extern uint32_t dword_5d4594_816368;
extern uint32_t dword_5d4594_816340;
extern uint32_t dword_5d4594_815044;
extern uint32_t dword_587000_93156;
extern void* dword_587000_127004;
extern uint32_t dword_5d4594_829484;
extern void* dword_5d4594_814624;
extern uint32_t dword_5d4594_826028;
extern uint32_t nox_client_highResFrontWalls_80820;
extern uint32_t dword_5d4594_830104;
extern uint32_t dword_5d4594_830108;
extern uint32_t dword_5d4594_816348;
extern uint32_t dword_5d4594_829488;
extern uint32_t nox_game_createOrJoin_815048;
extern uint32_t nox_client_gui_flag_815132;
extern uint32_t dword_587000_87412;
extern uint32_t dword_5d4594_829492;
extern uint32_t dword_5d4594_830248;
extern uint32_t dword_5d4594_829480;
extern uint32_t nox_client_renderGUI_80828;
extern nox_window* nox_wnd_quitMenu_825760;
extern uint32_t dword_5d4594_2650652;
extern uint32_t nox_player_netCode_85319C;
void* dword_5d4594_830236 = 0;
void* dword_5d4594_830232 = 0;

extern uint32_t nox_color_white_2523948;
extern uint32_t nox_color_red_2589776;
extern uint32_t nox_color_blue_2650684;
extern uint32_t nox_color_green_2614268;
extern uint32_t nox_color_cyan_2649820;
extern uint32_t nox_color_yellow_2589772;
extern uint32_t nox_color_violet_2598268;
extern uint32_t nox_color_black_2650656;
extern uint32_t nox_color_orange_2614256;

extern int nox_win_width;
extern int nox_win_height;


extern nox_video_mode nox_video_modes[];
extern int nox_video_modes_cnt;

extern nox_parse_thing_draw_funcs_t nox_parse_thing_draw_funcs[];
extern int nox_parse_thing_draw_funcs_cnt;

uint32_t dword_5d4594_816364 = 0;
uint32_t dword_5d4594_816376 = 0;
uint32_t dword_5d4594_816092 = 0;

nox_gui_animation* nox_wnd_xxx_829520 = 0;
nox_gui_animation* nox_wnd_xxx_830244 = 0;


//----- (0043B510) --------------------------------------------------------
void nox_client_xxx_switchChatMap_43B510() {
	short v0;     // ax
	char* result; // eax
	char* v2;     // edi
	short v5;     // cx
	int v6;       // [esp+0h] [ebp-54h]
	char v7[80];  // [esp+4h] [ebp-50h]

	nox_client_gui_flag_815132 = 0;
	nox_xxx_setGameFlags_40A4D0(5);
	nox_xxx_setMouseBounds_430A70(0, nox_win_width - 1, 0, nox_win_height - 1);
	v6 = *getMemU32Ptr(0x5D4594, 814916);
	if (0) {
		v0 = *getMemU16Ptr(0x5D4594, 814916) - *getMemU16Ptr(0x587000, 87528 + 8 * dword_587000_87412);
		HIWORD(v6) -= *getMemU16Ptr(0x587000, 87530 + 8 * dword_587000_87412);
		LOWORD(v6) = v0;
	}
	strcpy(v7, nox_client_getChatMap_49FF40(&v6));
	if (!strchr(v7, '.')) {
		sub_409B50(v7);
		v2 = &v7[strlen(v7) + 1];
		*(uint32_t*)--v2 = *getMemU32Ptr(0x587000, 90856);
		v2[4] = 0;
		if (!nox_common_getEngineFlag(/*NOX_ENGINE_FLAG_REPLAY_WRITE |*/ NOX_ENGINE_FLAG_REPLAY_READ)) {
			nox_xxx_gameSetMapPath_409D70(v7);
		}
		nox_common_gameFlags_unset_40A540(55280);
		nox_xxx_setGameFlags_40A4D0(128);
		result = sub_4165D0(0);
		v5 = *((uint16_t*)result + 26) & 0x280F;
		LOBYTE(v5) = result[52] & 0xF | 0x80;
		*((uint16_t*)result + 26) = v5;
	}
}
// 43B510: using guessed type char var_50[80];

//----- (0043B6D0) --------------------------------------------------------
int sub_43B6D0() { return dword_5d4594_815044; }

//----- (0043BC10) --------------------------------------------------------
unsigned short* sub_43BC10(wchar_t* a1, unsigned char a2) {
	const size_t a1_len = nox_wcslen(a1);
	wchar_t* a1_last_char = &a1[a1_len];

	int a1v = 0;
	do {
		nox_xxx_drawGetStringSize_43F840(0, a1, &a1v, 0, 0);
		*a1_last_char = 0;
		--a1_last_char;
	} while (a1v + 5 > a2);

	return a1;
}

//----- (0043BC80) --------------------------------------------------------
int nox_sprintAddrPort_43BC80(const char* addr, unsigned short port, char* dst) {
	return nox_sprintf(dst, "%s:%d", addr, port);
}

//----- (0043BDB0) --------------------------------------------------------
int sub_43BDB0() { return *getMemU32Ptr(0x5D4594, 815092); }

//----- (0043C650) --------------------------------------------------------
int sub_43C650() {
	long long v0;    // kr00_8
	unsigned int v1; // eax
	int v2;          // ett
	int result;      // eax

	v0 = nox_platform_get_ticks();
	v1 = *getMemU32Ptr(0x5D4594, 815756);
	if (*getMemU64Ptr(0x5D4594, 815740)) {
		v2 = ((unsigned int)v0 < *getMemIntPtr(0x5D4594, 815740)) + *getMemU32Ptr(0x5D4594, 815744);
		*getMemU32Ptr(0x5D4594, 815220 + 8 * *getMemU32Ptr(0x5D4594, 815756)) = v0 - *getMemU32Ptr(0x5D4594, 815740);
		*getMemU32Ptr(0x5D4594, 815224 + 8 * v1) = HIDWORD(v0) - v2;
	} else {
		*getMemU32Ptr(0x5D4594, 815220 + 8 * *getMemU32Ptr(0x5D4594, 815756)) = v0;
		*getMemU32Ptr(0x5D4594, 815224 + 8 * v1) = HIDWORD(v0);
	}
	*getMemU64Ptr(0x5D4594, 815756) = (__PAIR64__(*getMemUintPtr(0x5D4594, 815760), v1) + 1) % 0x3C;
	result = dword_5d4594_815748 + 1;
	*getMemU64Ptr(0x5D4594, 815740) = v0;
	++dword_5d4594_815748;
	return result;
}

//----- (0043C790) --------------------------------------------------------
int sub_43C790() { return *getMemU32Ptr(0x587000, 91876); }

//----- (0043C7A0) --------------------------------------------------------
int sub_43C7A0(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x587000, 91876) = a1;
	return result;
}

//----- (0043CEB0) --------------------------------------------------------
void sub_43CEB0() {
	unsigned int v1;           // esi
	unsigned int v2;           // edi
	unsigned int v3;           // ebx
	unsigned long long v4 = 0; // rax
	unsigned int v5;           // ecx
	int v6;                    // kr00_4
	unsigned int v7;           // kr08_4
	unsigned int v9;           // [esp+0h] [ebp-8h]

	int v0 = dword_5d4594_815748;
	if (*(int*)&dword_5d4594_815748 >= 60) {
		v0 = 60;
	}
	v1 = 0;
	v2 = 0;
	v3 = 0;
	if (!(v0 && v0 > 10)) {
		*getMemU32Ptr(0x587000, 91884) = 0;
		*getMemU32Ptr(0x587000, 91880) = 33;
		return;
	}
	v5 = 0;
	v9 = v0;
	do {
		do {
			v6 = *getMemU32Ptr(0x5D4594, 815220 + 8 * v5) + v2;
			v3 = (__PAIR64__(*getMemU32Ptr(0x5D4594, 815224 + 8 * v5), *getMemU32Ptr(0x5D4594, 815220 + 8 * v5)) +
				  __PAIR64__(v3, v2)) >>
				 32;
			v2 += *getMemU32Ptr(0x5D4594, 815220 + 8 * v5);
			v7 = v5 + 1;
			v1 = (__PAIR64__(v1, v5++) + 1) >> 32;
		} while (v1 < HIDWORD(v4));
		LODWORD(v4) = v9;
	} while (v1 <= HIDWORD(v4) && v7 < v9);
	long long v0a = __PAIR64__(v3, v6) / v4;
	*getMemU64Ptr(0x587000, 91880) = v0a;
}
// 43CFA0: variable 'v1' is possibly undefined

//----- (0043D2D0) --------------------------------------------------------
void sub_43D2D0() {
	int v1; // esi

	if (dword_5d4594_816340) {
		if (dword_5d4594_816364) {
			sub_486520(getMemUintPtr(0x5D4594, 816244));
			sub_486520(getMemUintPtr(0x5D4594, 816148));
			v1 = *(uint32_t*)((uint32_t)dword_587000_81128 + 4) >> 16;
			if (v1 == *getMemU32Ptr(0x587000, 93168)) {
				if ((unsigned long long)(nox_platform_get_ticks() - *getMemU64Ptr(0x5D4594, 816380)) > 0x32) {
					**(uint32_t**)&dword_587000_81128 &= 0xFFFFFFFD;
					*(uint32_t*)((uint32_t)dword_587000_81128 + 32) &= 0xFFFFFFFD;
					*(uint32_t*)((uint32_t)dword_587000_81128 + 64) &= 0xFFFFFFFD;
				}
			} else {
				*getMemU64Ptr(0x5D4594, 816380) = nox_platform_get_ticks();
				*getMemU32Ptr(0x587000, 93168) = v1;
			}
			if (dword_5d4594_816364) {
				if (**(uint8_t**)&dword_587000_81128 & 2 || getMemByte(0x5D4594, 816148) & 2 ||
					getMemByte(0x5D4594, 816244) & 2) {
					sub_43D3C0(*(int*)&dword_5d4594_816364, *getMemIntPtr(0x5D4594, 816096));
				}
			}
		}
	}
}

//----- (0043D3C0) --------------------------------------------------------
void sub_43D3C0(int a1, int a2) {
	unsigned int v2; // eax

	if (a1) {
		v2 = (*(uint32_t*)((uint32_t)dword_587000_81128 + 4) >> 16) *
			 ((*getMemU16Ptr(0x5D4594, 816154) * ((a2 * (unsigned int)*getMemU16Ptr(0x5D4594, 816250)) >> 14)) >> 14);
		*getMemU32Ptr(0x5D4594, 816148) &= 0xFFFFFFFD;
		*getMemU32Ptr(0x5D4594, 816244) &= 0xFFFFFFFD;
		AIL_set_stream_volume(a1, (int)(127 * (v2 >> 14)) / 100);
	}
}
// 581430: using guessed type int AIL_set_stream_volume(uint32_t, uint32_t);

//----- (0043D440) --------------------------------------------------------
void sub_43D440() {
	int* v0 = getMemIntPtr(0x5D4594, 816108 + 20 * *getMemU32Ptr(0x5D4594, 816352));
	if (!dword_5d4594_816340) {
		return;
	}
	switch (dword_5d4594_816348) {
	case 0:
		if (dword_5d4594_816356 && (dword_587000_93156 != 0)) {
			dword_5d4594_816348 = 3;
		} else {
			if (*v0) {
				if (dword_587000_93156) {
					sub_486320(getMemAt(0x5D4594, 816148), 0x4000);
					if (nox_xxx_musicStartPlay_43D6C0(v0)) {
						dword_5d4594_816348 = 1;
						v0[4] = 1;
					} else {
						*v0 = 0;
					}
				}
			}
		}
		break;
	case 1:
		if (dword_587000_93156 && *v0 == dword_5d4594_816092 && dword_5d4594_816364 &&
			AIL_stream_status(dword_5d4594_816364) != 2) {
			if (dword_5d4594_816356) {
				dword_5d4594_816348 = 4;
				sub_486350((int)getMemAt(0x5D4594, 816148), 0);
			}
		} else {
			dword_5d4594_816348 = 2;
			sub_486350((int)getMemAt(0x5D4594, 816148), 0);
		}
		break;
	case 2:
		if (!dword_5d4594_816364) {
			sub_43D650();
			dword_5d4594_816348 = 0;
		} else {
			if (AIL_stream_status(dword_5d4594_816364) == 2 || !(*getMemU32Ptr(0x5D4594, 816152) & 0xFFFF0000)) {
				sub_43D650();
				dword_5d4594_816348 = 0;
			}
		}
		break;
	case 3:
		if (!dword_5d4594_816356 || (dword_587000_93156 == 0)) {
			if (!dword_587000_93156 || *v0 != dword_5d4594_816092 || !dword_5d4594_816364 ||
				AIL_stream_status(dword_5d4594_816364) == 2) {
				sub_43D650();
				dword_5d4594_816348 = 0;
			} else {
				sub_486350((int)getMemAt(0x5D4594, 816148), 0x4000);
				sub_43D6A0();
				dword_5d4594_816348 = 1;
			}
		}
		break;
	case 4:
		if (dword_5d4594_816364 && (AIL_stream_status(dword_5d4594_816364) != 2)) {
			if (!(*getMemU32Ptr(0x5D4594, 816152) & 0xFFFF0000)) {
				sub_43D680();
				dword_5d4594_816348 = 3;
			}
		} else {
			sub_43D650();
			dword_5d4594_816348 = 0;
		}
		break;
	default:
		break;
	}
}
// 58141C: using guessed type int AIL_stream_status(uint32_t);

//----- (0043D8E0) --------------------------------------------------------
int sub_43D8E0() {
	int result; // eax
	int v1;     // eax

	if (dword_5d4594_816340) {
		return 1;
	}
	v1 = sub_43F130();
	dword_5d4594_816376 = v1;
	dword_587000_93156 = v1 != 0;
	sub_4864A0(getMemAt(0x5D4594, 816148));
	sub_486380(getMemAt(0x5D4594, 816148), 0x3E8u, 0, 0x4000);
	dword_5d4594_816348 = 0;
	dword_5d4594_816092 = 0;
	*getMemU32Ptr(0x5D4594, 816352) = 0;
	*getMemU32Ptr(0x5D4594, 816108) = 0;
	dword_5d4594_816356 = 0;
	dword_5d4594_816372 = 0;
	dword_5d4594_816368 = 0;
	dword_5d4594_816364 = 0;
	result = 1;
	dword_5d4594_816340 = 1;
	return result;
}

//----- (0043D990) --------------------------------------------------------
void sub_43D990() {
	int4 v1; // [esp+0h] [ebp-10h]

	v1.field_0 = 0;
	sub_43D9E0(&v1);
}

//----- (0043D9B0) --------------------------------------------------------
void sub_43D9B0(int a1, int a2) {
	int4 v3; // [esp+0h] [ebp-10h]

	v3.field_0 = a1;
	v3.field_C = 0;
	v3.field_8 = 0;
	v3.field_4 = a2;
	sub_43D9E0(&v3);
}

//----- (0043D9E0) --------------------------------------------------------
void sub_43D9E0(int4* a1) {
	int4* v1; // edx
	int v2;   // ecx

	v1 = (int4*)getMemAt(0x5D4594, 816108 + 20 * (*getMemU32Ptr(0x5D4594, 816352) ^ 1));
	v2 = a1->field_4;
	if (v2 <= 100) {
		if (v2 < 0) {
			a1->field_4 = 0;
		}
	} else {
		a1->field_4 = 100;
	}
	if (*getMemU32Ptr(0x5D4594, 816344)) {
		*(int4*)getMemAt(0x5D4594, 816060) = *a1;
	} else {
		*v1 = *a1;
		v1[1].field_0 = 0;
		*getMemU32Ptr(0x5D4594, 816352) ^= 1u;
	}
}

//----- (0043DA80) --------------------------------------------------------
int sub_43DA80() {
	int result; // eax

	if (*(int*)&dword_5d4594_816368 < 6) {
		sub_43DD10(getMemIntPtr(0x5D4594, 815772 + 16 * (dword_5d4594_816368 + 6 * dword_5d4594_816372)));
		++dword_5d4594_816368;
		result = 1;
	} else {
		dword_5d4594_816368 = 6;
		result = 0;
	}
	return result;
}

//----- (0043DAD0) --------------------------------------------------------
void sub_43DAD0() {
	if (dword_5d4594_816368 > 0) {
		sub_43D9E0((int4*)getMemAt(0x5D4594, 815772 + 16 * (--dword_5d4594_816368 + 6 * dword_5d4594_816372)));
	}
	dword_5d4594_816368 = 0;
}

//----- (0043DB20) --------------------------------------------------------
int sub_43DB20() { return dword_5d4594_816368; }

//----- (0043DB30) --------------------------------------------------------
int sub_43DB30(int a1) {
	int result; // eax

	result = a1;
	dword_5d4594_816368 = a1;
	return result;
}

//----- (0043DB40) --------------------------------------------------------
char* sub_43DB40(int a1) { return (char*)getMemAt(0x5D4594, 815772 + 16 * (a1 + 6 * dword_5d4594_816372)); }

//----- (0043DB60) --------------------------------------------------------
int sub_43DB60() {
	int result; // eax
	int v1;     // eax
	int v2;     // ecx

	result = 3;
	if (*(int*)&dword_5d4594_816372 < 3) {
		sub_43DA80();
		v1 = dword_5d4594_816372;
		v2 = dword_5d4594_816368;
		dword_5d4594_816368 = 0;
		*getMemU32Ptr(0x5D4594, 816076 + 4 * dword_5d4594_816372) = v2;
		result = v1 + 1;
		dword_5d4594_816372 = result;
	} else {
		dword_5d4594_816372 = 3;
	}
	return result;
}

//----- (0043DBA0) --------------------------------------------------------
void sub_43DBA0() {
	int v1; // eax
	if (dword_5d4594_816372 > 0) {
		v1 = dword_5d4594_816372 - 1;
		dword_5d4594_816372 = v1;
		dword_5d4594_816368 = *getMemU32Ptr(0x5D4594, 816076 + 4 * v1);
		sub_43DAD0();
	} else {
		dword_5d4594_816372 = 0;
	}
}

//----- (0043DBD0) --------------------------------------------------------
int sub_43DBD0() {
	++dword_5d4594_816356;
	sub_43D440();
	return 0;
}

//----- (0043DBE0) --------------------------------------------------------
int sub_43DBE0() {
	if (--*(int*)&dword_5d4594_816356 < 0) {
		dword_5d4594_816356 = 0;
	}
	sub_43D440();
	return 0;
}

//----- (0043DC00) --------------------------------------------------------
void sub_43DC00() { dword_587000_93156 = 0; }

//----- (0043DC10) --------------------------------------------------------
int sub_43DC10() {
	int result; // eax

	result = dword_5d4594_816376;
	if (dword_5d4594_816376) {
		dword_587000_93156 = 1;
	}
	return result;
}

//----- (0043DC30) --------------------------------------------------------
int sub_43DC30() { return dword_587000_93156; }

//----- (0043DC40) --------------------------------------------------------
int sub_43DC40() {
	int result; // eax

	if (!dword_5d4594_816340 ||
		(result = 1, dword_5d4594_816348 != 1) && dword_5d4594_816348 != 4 && dword_5d4594_816348 != 2) {
		result = 0;
	}
	return result;
}

//----- (0043DD10) --------------------------------------------------------
int sub_43DD10(int* a1) {
	unsigned char* v1; // ecx
	int result;        // eax

	v1 = getMemAt(0x5D4594, 816108 + 20 * *getMemU32Ptr(0x5D4594, 816352));
	*a1 = *getMemU32Ptr(0x5D4594, 816108 + 20 * *getMemU32Ptr(0x5D4594, 816352));
	a1[1] = *((uint32_t*)v1 + 1);
	a1[2] = *((uint32_t*)v1 + 2);
	a1[3] = *((uint32_t*)v1 + 3);
	result = dword_5d4594_816364;
	if (dword_5d4594_816364) {
		result = *a1;
		if (dword_5d4594_816092 == *a1) {
			result = AIL_stream_position(dword_5d4594_816364);
			a1[2] = result;
		}
	}
	return result;
}
// 581404: using guessed type int AIL_stream_position(uint32_t);

//----- (0043DD70) --------------------------------------------------------
void sub_43DD70(int a1, int a2) {
	sub_43DD10(getMemIntPtr(0x5D4594, 816060));
	sub_43D9B0(a1, a2);
	*getMemU32Ptr(0x5D4594, 816344) = 1;
}

//----- (0043E1A0) --------------------------------------------------------
uint32_t* nox_xxx_gui_43E1A0(int a1) {
	uint32_t* result; // eax

	if (a1) {
		result = nox_window_new(0, 552, 0, 0, nox_win_width, nox_win_height, 0);
		dword_5d4594_816412 = result;
		result[14] = nox_color_black_2650656;
	} else {
		result = *(uint32_t**)&dword_5d4594_816412;
		if (dword_5d4594_816412) {
			result = (uint32_t*)nox_xxx_windowDestroyMB_46C4E0(*(uint32_t**)&dword_5d4594_816412);
			dword_5d4594_816412 = 0;
		}
	}
	return result;
}

//----- (0043E8C0) --------------------------------------------------------
int sub_43E8C0(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 816408) = a1;
	return result;
}

//----- (0043EDB0) --------------------------------------------------------
void sub_43EDB0(HSAMPLE a1) {
	int v1;     // eax
	int v2;     // esi
	int result; // eax

	v1 = AIL_sample_user_data(a1);
	v2 = v1;
	result = *(uint32_t*)(v1 + 28);
	if (!result) {
		result = (*(int (**)(uint32_t))(*(uint32_t*)(v2 + 4) + 284))(*(uint32_t*)(v2 + 4));
		*(uint32_t*)(v2 + 28) = 1;
	}
}

//----- (0043EE00) --------------------------------------------------------
int sub_43EE00(void* a1p) {
	int a1 = a1p;
	int v1;           // esi
	int result;       // eax
	int v3;           // ebx
	int v4;           // edi
	char* v5;         // ebp
	unsigned int v6;  // ecx
	signed int v7;    // esi
	signed int v8;    // eax
	char* v9;         // esi
	char v10;         // bp
	unsigned int v11; // ecx
	char* v12;        // edi
	char* v13;        // esi
	int v14;          // ecx
	int v15;          // edx
	int v16;          // eax
	char* v17;        // [esp+4h] [ebp-18h]
	signed int v18;   // [esp+8h] [ebp-14h]
	char* v19;        // [esp+Ch] [ebp-10h]
	int v20;          // [esp+10h] [ebp-Ch]
	int v21;          // [esp+14h] [ebp-8h]
	char* v22;        // [esp+18h] [ebp-4h]

	v1 = a1;
	result = AIL_sample_buffer_ready(*(uint32_t*)(a1 + 8));
	v20 = result;
	if (result != -1) {
		while (1) {
			v3 = *(uint32_t*)(v1 + 4);
			v4 = 0;
			v5 = 0;
			v17 = *(char**)(v1 + 4 * v20 + 20);
			v6 = 0;
			v7 = 0;
			v21 = 0;
			v19 = 0;
			v18 = 0;
			if (!*(uint32_t*)(a1 + 12)) {
				break;
			}
		LABEL_27:
			AIL_load_sample_buffer(*(uint32_t*)(a1 + 8), v20, v19, v4);
			result = AIL_sample_buffer_ready(*(uint32_t*)(a1 + 8));
			v20 = result;
			if (result == -1) {
				return result;
			}
			v1 = a1;
		}
		while (1) {
			if (v4 >= 0x4000) {
				goto LABEL_27;
			}
			v8 = *(uint32_t*)(v3 + 300);
			if (!v8) {
				(*(void (**)(int))(v3 + 276))(v3);
				v8 = *(uint32_t*)(v3 + 300);
				if (!v8) {
					(*(void (**)(int))(v3 + 280))(v3);
					v8 = *(uint32_t*)(v3 + 300);
					if (!v8) {
						*(uint32_t*)(a1 + 12) = 1;
						goto LABEL_27;
					}
				}
				v6 = v18;
			}
			if (v4) {
				break;
			}
			v19 = *(char**)(v3 + 296);
			if (v8 < 0x4000 || v5) {
				break;
			}
			v7 = v8;
		LABEL_24:
			v15 = *(uint32_t*)(v3 + 304) - v7;
			*(uint32_t*)(v3 + 300) -= v7;
			v16 = v7 + *(uint32_t*)(v3 + 296);
			*(uint32_t*)(v3 + 304) = v15;
			*(uint32_t*)(v3 + 296) = v16;
			v4 += v7;
			v21 = v4;
			if (*(uint32_t*)(a1 + 12)) {
				goto LABEL_27;
			}
		}
		if (v8 + v4 > 0x4000) {
			v8 = 0x4000 - v4;
		}
		if (!v8) {
			goto LABEL_24;
		}
		if (v5) {
			if (v6) {
				v9 = v5;
				v10 = v6;
				v11 = v6 >> 2;
				memcpy(v22, v9, 4 * v11);
				v13 = &v9[4 * v11];
				v12 = &v22[4 * v11];
				v19 = v22;
				v14 = v10 & 3;
				v5 = 0;
				memcpy(v12, v13, v14);
			}
		} else if (!v6) {
			v5 = *(char**)(v3 + 296);
			v22 = v17;
			v18 = v8;
		LABEL_23:
			v7 = v8;
			v17 += v8;
			v6 = v18;
			goto LABEL_24;
		}
		memcpy(v17, *(const void**)(v3 + 296), v8);
		v4 = v21;
		goto LABEL_23;
	}
	return result;
}
// 43EF03: variable 'v22' is possibly undefined
// 5813C4: using guessed type int AIL_load_sample_buffer(uint32_t, uint32_t, uint32_t, uint32_t);
// 5813C8: using guessed type int AIL_sample_buffer_ready(uint32_t);

//----- (0043F0E0) --------------------------------------------------------
int sub_43F0E0(uint32_t* a1) {
	int v1;     // ecx
	int result; // eax
	int v3;     // eax

	v1 = a1[1];
	if (v1) {
		if (v1 == 2) {
			v3 = -(a1[3] != 2);
			LOBYTE(v3) = v3 & 0xFE;
			result = v3 + 7;
		} else {
			result = 0;
		}
	} else if (a1[3] == 2) {
		result = (a1[4] == 2) + 2;
	} else {
		result = a1[4] == 2;
	}
	return result;
}

//----- (004417E0) --------------------------------------------------------
void sub_4417E0(wchar_t* a1, const char* a2) {
	unsigned char v2; // dl
	char* v3;         // edi
	char v4[64];      // [esp+4h] [ebp-C0h]
	wchar_t v5[64];   // [esp+44h] [ebp-80h]

	if (a2) {
		strcpy(v4, a2);
		v2 = getMemByte(0x587000, 103296);
		v3 = &v4[strlen(v4)];
		*(uint32_t*)v3 = *getMemU32Ptr(0x587000, 103292);
		v3[4] = v2;
		nox_swprintf(v5, L"%-20.20S\t\t", v4);
		nox_wcscat(a1, v5);
	}
}
// 4417E0: using guessed type char var_C0[64];

//----- (004438A0) --------------------------------------------------------
int nox_xxx_doExecrul_4438A0(int a1) {
	FILE* v1;        // eax
	FILE* v2;        // esi
	char* v3;        // eax
	char v5[256];    // [esp+8h] [ebp-400h]
	char v6[256];    // [esp+108h] [ebp-300h]
	wchar_t v7[128]; // [esp+208h] [ebp-200h]

	if (!a1) {
		return 0;
	}
	v6[0] = 0;
	nox_sprintf(v6, "%S", a1);
	v1 = nox_fs_open_text(v6);
	v2 = v1;
	if (!v1) {
		return 0;
	}
	if (!nox_fs_feof(v1)) {
		do {
			memset(v5, 0, 0xFCu);
			*(uint16_t*)&v5[252] = 0;
			v5[254] = 0;
			nox_fs_fgets(v2, v5, 255);
			v3 = strchr(v5, 10);
			if (v3) {
				*v3 = 0;
			}
			if (v5[0]) {
				nox_swprintf(v7, L"%S", v5);
				nox_gui_console_Printf_450C00(NOX_CONSOLE_WHITE, (wchar_t*)getMemAt(0x587000, 106956), v7);
				nox_server_parseCmdText_443C80(v7, 1);
			}
		} while (!nox_fs_feof(v2));
	}
	nox_fs_close(v2);
	return 1;
}

//----- (00445450) --------------------------------------------------------
wchar_t* sub_445450() {
	unsigned char* v0; // esi
	wchar_t* result;   // eax

	v0 = getMemAt(0x5D4594, 824440);
	do {
		result = nox_wcscpy((wchar_t*)v0 - 318, (const wchar_t*)getMemAt(0x5D4594, 825740));
		*(uint32_t*)v0 = 0;
		v0[4] = 0;
		v0 += 644;
	} while ((int)v0 < (int)getMemAt(0x5D4594, 826372));
	dword_5d4594_825736 = 0;
	return result;
}

//----- (00445530) --------------------------------------------------------
int nox_xxx_drawMessageLines_445530() {
	int v1;             // ebp
	int v2;             // eax
	int v3;             // ebx
	int result;         // eax
	int v5;             // ebx
	unsigned short* v6; // ebx
	int v7;             // kr00_4
	unsigned char* v8;  // esi
	int v9;             // edi
	int v10;            // esi
	int v11;            // ecx
	int i;              // [esp+10h] [ebp-Ch]
	int v13;            // [esp+14h] [ebp-8h]
	int v14;            // [esp+18h] [ebp-4h]

	v13 = 0;
	nox_draw_viewport_t* rdr = nox_draw_getViewport_437250();
	v1 = 3 * rdr->height / 4 + rdr->y1 - 15;
	v2 = dword_5d4594_825736;
	for (i = dword_5d4594_825736;; v2 = i) {
		v3 = 161 * v2;
		result = gameFrame();
		v5 = 4 * v3;
		if (*getMemU32Ptr(0x5D4594, 824440 + v5) < gameFrame()) {
			break;
		}
		nox_xxx_drawSetTextColor_434390(nox_color_black_2650656);
		v6 = getMemU16Ptr(0x5D4594, 823804 + v5);
		nox_xxx_drawGetStringSize_43F840(0, v6, &v14, 0, 0);
		v7 = nox_win_width - v14;
		v8 = getMemAt(0x587000, 107848);
		v9 = (nox_win_width - v14) / 2;
		do {
			nox_xxx_drawString_43F6E0(0, (short*)v6, v9 + *(uint32_t*)v8, v1 + *((uint32_t*)v8 + 1));
			v8 += 8;
		} while ((int)v8 < (int)getMemAt(0x587000, 107880));
		v10 = v13;
		if (v13) {
			nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2597996));
		} else {
			nox_xxx_drawSetTextColor_434390(nox_color_white_2523948);
		}
		nox_xxx_drawString_43F6E0(0, (short*)v6, v7 / 2, v1);
		v11 = -4 - nox_xxx_guiFontHeightMB_43F320(0);
		result = i;
		v1 += v11;
		if (i) {
			--i;
		} else {
			i = 2;
		}
		++v13;
		if (v10 + 1 >= 3) {
			break;
		}
	}
	return result;
}

//----- (004456E0) --------------------------------------------------------
int nox_xxx_guiChatMode_4456E0(int* a1) {
	int* v1; // esi
	int v2;  // edx
	int v4;  // [esp+4h] [ebp-4h]

	v1 = a1;
	nox_client_wndGetPosition_46AA60(a1, &a1, &v4);
	v2 = v1[25];
	a1 = (int*)((char*)a1 + v1[24]);
	nox_client_drawImageAt_47D2C0(v1[15], (int)a1, v2 + v4);
	return 1;
}

//----- (00445730) --------------------------------------------------------
int nox_xxx_guiChatShowHide_445730(int a1) { return nox_window_set_hidden(*(int*)&dword_5d4594_825744, a1); }

//----- (00445770) --------------------------------------------------------
int sub_445770() {
	int result; // eax

	result = nox_xxx_windowDestroyMB_46C4E0(*(uint32_t**)&dword_5d4594_825744);
	dword_5d4594_825744 = 0;
	return result;
}

// 445B20: using guessed type int nox_xxx_quitDialogYes_445B20();

//----- (00445B20) --------------------------------------------------------
// Microsoft VisualC 2-14/net runtime
void nox_xxx_quitDialogYes_445B20() {
	nox_client_quit_4460C0();
	sub_445C40();
}
// 445B20: using guessed type int nox_xxx_quitDialogYes_445B20();

//----- (00445B30) --------------------------------------------------------
int nox_xxx_quitDialogNo_445B30() { return nox_xxx_wndSetCaptureMain_46ADC0(nox_wnd_quitMenu_825760); }

//----- (00445BA0) --------------------------------------------------------
void sub_445BA0() { sub_413A00(0); }

//----- (00445C20) --------------------------------------------------------
void sub_445C20() {
	int v = nox_xxx_wndGetFlags_46ADA0(nox_wnd_quitMenu_825760);
	if (!(v & 0x10)) {
		sub_445C40();
	}
}

//----- (00445FF0) --------------------------------------------------------
uint32_t* sub_445FF0() {
	int i;            // esi
	uint32_t* result; // eax

	if (nox_wnd_quitMenu_825760) {
		nox_wnd_quitMenu_825760->draw_data.bg_color = nox_color_black_2650656;
	}
	for (i = 9001; i <= 9006; ++i) {
		result = nox_xxx_wndGetChildByID_46B0C0(nox_wnd_quitMenu_825760, i);
		if (result) {
			result[26] = nox_color_orange_2614256;
		}
	}
	return result;
}

//----- (00446360) --------------------------------------------------------
unsigned int nox_gui_xxx_check_446360() {
	unsigned int result; // eax

	if (nox_wnd_quitMenu_825760) {
		result = ((unsigned int)~nox_xxx_wndGetFlags_46ADA0(nox_wnd_quitMenu_825760) >> 4) & 1;
	} else {
		result = 0;
	}
	return result;
}

//----- (004463E0) --------------------------------------------------------
int nox_motd_4463E0(int a1) {
	FILE* result; // eax
	FILE* v2;     // edi
	char* v3;     // eax

	dword_5d4594_826036 = 0;
	*getMemU32Ptr(0x5D4594, 826040 + 4 * a1) = 0;
	result = nox_fs_open("motd.txt");
	v2 = result;
	if (result) {
		*getMemU32Ptr(0x5D4594, 826040 + 4 * a1) = nox_fs_fsize(v2);
		v3 = (char*)calloc(*getMemU32Ptr(0x5D4594, 826040 + 4 * a1) + 1, 1u);
		dword_5d4594_826036 = v3;
		if (v3) {
			nox_binfile_fread_raw_40ADD0(v3, *getMemU32Ptr(0x5D4594, 826040 + 4 * a1), 1u, v2);
			v3 = *(char**)&dword_5d4594_826036;
		}
		v3[(*getMemU32Ptr(0x5D4594, 826040 + 4 * a1))++] = 0;
		nox_fs_close(v2);
	}
	return 0;
}

//----- (00446490) --------------------------------------------------------
void* sub_446490(int a1) {
	void* result; // eax

	result = *(void**)&dword_5d4594_826036;
	if (dword_5d4594_826036) {
		free(*(void**)&dword_5d4594_826036);
		result = a1;
	}
	dword_5d4594_826036 = 0;
	*getMemU32Ptr(0x5D4594, 826040 + 4 * (uint32_t)a1) = 0;
	return result;
}

//----- (004464D0) --------------------------------------------------------
void* sub_4464D0(int a1, uint32_t* a2) {
	*a2 = *getMemU32Ptr(0x5D4594, 826040 + 4 * a1);
	return *(void**)&dword_5d4594_826036;
}

//----- (004464F0) --------------------------------------------------------
int sub_4464F0(int a1, uint32_t* a2) {
	if (!*getMemU32Ptr(0x5D4594, 826056 + 4 * a1)) {
		return 0;
	}
	*a2 = *getMemU32Ptr(0x5D4594, 826048 + 4 * a1);
	return *getMemU32Ptr(0x5D4594, 826056 + 4 * a1);
}

//----- (00446520) --------------------------------------------------------
void sub_446520(int a1, const void* a2, int a3) {
	void* v3; // edi

	if (a2) {
		if (a3 > 0) {
			v3 = calloc(a3, 1u);
			*getMemU32Ptr(0x5D4594, 826056 + 4 * a1) = v3;
			memcpy(v3, a2, a3);
			*getMemU32Ptr(0x5D4594, 826048 + 4 * a1) = a3;
			*getMemU32Ptr(0x5D4594, 826064 + 4 * a1) = 1;
		}
	}
}

//----- (00446580) --------------------------------------------------------
int sub_446580(int a1) {
	int result; // eax

	result = *getMemU32Ptr(0x5D4594, 826056 + 4 * a1);
	if (result) {
		free(*(void**)getMemAt(0x5D4594, 826056 + 4 * a1));
		*getMemU32Ptr(0x5D4594, 826056 + 4 * a1) = 0;
		*getMemU32Ptr(0x5D4594, 826048 + 4 * a1) = 0;
		*getMemU32Ptr(0x5D4594, 826064 + 4 * a1) = 0;
	}
	return result;
}

//----- (004465C0) --------------------------------------------------------
int nox_xxx_guiMotdLoad_4465C0() {
	uint32_t* v0; // eax
	uint32_t* v1; // eax
	uint32_t* v2; // edi
	char* v3;     // ebx
	uint32_t* v4; // esi
	uint32_t* v5; // ebp
	char* v7;     // [esp+10h] [ebp-8h]
	uint32_t* v8; // [esp+14h] [ebp-4h]

	v0 = nox_new_window_from_file("motd.wnd", sub_4466C0);
	dword_5d4594_826028 = v0;
	v1 = nox_xxx_wndGetChildByID_46B0C0(v0, 4203);
	dword_5d4594_826032 = v1;
	v2 = (uint32_t*)v1[8];
	v7 = nox_xxx_gLoadImg_42F970("UISlider");
	v3 = nox_xxx_gLoadImg_42F970("UISliderLit");
	v4 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_826028, 4204);
	v5 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_826028, 4205);
	v8 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_826028, 4206);
	*(uint32_t*)(v4[100] + 8) = 16;
	*(uint32_t*)(v4[100] + 12) = 10;
	sub_4B5700((int)v4, 0, 0, (int)v7, (int)v3, (int)v3);
	nox_xxx_wnd_46B280((int)v4, *(int*)&dword_5d4594_826032);
	nox_xxx_wnd_46B280((int)v5, *(int*)&dword_5d4594_826032);
	nox_xxx_wnd_46B280((int)v8, *(int*)&dword_5d4594_826032);
	v2[9] = v4;
	v2[7] = v5;
	v2[8] = v8;
	return dword_5d4594_826028;
}

//----- (004466C0) --------------------------------------------------------
int sub_4466C0(int a1, int a2, int a3, int a4) {
	if (a2 == 16391) {
		nox_xxx_clientPlaySoundSpecial_452D80(766, 100);
		sub_446780();
	}
	return 0;
}

//----- (004466F0) --------------------------------------------------------
char* sub_4466F0(char* a1, uint8_t* a2) {
	char* v2;     // edx
	char* v3;     // eax
	char v4;      // cl
	char* result; // eax

	v2 = a2;
	v3 = a1;
	*a2 = 0;
	if (!*a1) {
		return 0;
	}
	while (1) {
		v4 = *v3;
		if (!*v3) {
			*v2 = 0;
			return 0;
		}
		if (v4 == 10) {
			*v2 = 0;
			return v3 + 1;
		}
		if (v4 == 13) {
			break;
		}
		*v2++ = v4;
		++v3;
	}
	result = v3 + 1;
	*v2 = 0;
	if (*result == 10) {
		++result;
	}
	return result;
}

//----- (00446730) --------------------------------------------------------
uint8_t* nox_xxx_motdAddSomeTextMB_446730(uint8_t* a1) {
	uint8_t* result; // eax
	wchar_t v2[256]; // [esp+0h] [ebp-200h]

	result = a1;
	if (*a1) {
		nox_swprintf(v2, L"%S", a1);
		result = (uint8_t*)nox_window_call_field_94(*(int*)&dword_5d4594_826032, 16397, (int)v2, -1);
	}
	return result;
}

//----- (00446780) --------------------------------------------------------
int sub_446780() {
	if (wndIsShown_nox_xxx_wndIsShown_46ACC0(*(int*)&dword_5d4594_826028)) {
		return 0;
	}
	nox_xxx_windowFocus_46B500(0);
	nox_window_set_hidden(*(int*)&dword_5d4594_826028, 1);
	*(uint32_t*)(dword_5d4594_826028 + 4) &= 0xFFFFFFF7;
	*(uint32_t*)(dword_5d4594_826032 + 4) &= 0xFFFFFFF7;
	nox_window_call_field_94(*(int*)&dword_5d4594_826032, 16399, 0, 0);
	return 1;
}

//----- (004467F0) --------------------------------------------------------
void nox_xxx_motd_4467F0() {
	unsigned int result; // eax
	uint32_t* v1;        // eax
	char* v2;            // esi
	uint32_t* v3;        // eax
	char v4[256];        // [esp+0h] [ebp-100h]

	result = nox_gui_xxx_check_446360();
	if (!result) {
		result = nox_xxx_isQuest_4D6F50();
		if (!result || (result = nox_common_gameFlags_check_40A5C0(128)) == 0) {
			if (!nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
				result = nox_xxx_wndGetFlags_46ADA0(*(int*)&dword_5d4594_826028);
				if (result & 0x10) {
					result = sub_44A4A0();
					if (!result) {
						result = sub_49C810();
						if (!result) {
							result = sub_49CB40();
							if (!result) {
								nox_xxx_wndShowModalMB_46A8C0(*(int*)&dword_5d4594_826028);
								v1 = nox_xxx_wndGetChildByID_46B0C0(0, 4100);
								if (v1) {
									nox_xxx_wndShowModalMB_46A8C0((int)v1);
								}
								*(uint32_t*)(dword_5d4594_826028 + 4) |= 8u;
								*(uint32_t*)(dword_5d4594_826032 + 4) |= 8u;
								v2 = *(char**)getMemAt(0x5D4594, 826060);
								if (*getMemU32Ptr(0x5D4594, 826060)) {
									while (1) {
										v2 = sub_4466F0(v2, v4);
										if (!v2) {
											break;
										}
										if (!v4[0]) {
											strcpy(v4, " ");
										}
										nox_xxx_motdAddSomeTextMB_446730(v4);
									}
									if (v4[0]) {
										nox_xxx_motdAddSomeTextMB_446730(v4);
									}
								}
								v3 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_826028, 4202);
								nox_xxx_windowFocus_46B500((int)v3);
							}
						}
					}
				}
			}
			*getMemU32Ptr(0x5D4594, 826068) = 0;
		}
	}
}

//----- (00446950) --------------------------------------------------------
int sub_446950() { return dword_5d4594_826028 && !(nox_xxx_wndGetFlags_46ADA0(*(int*)&dword_5d4594_826028) & 0x10); }

//----- (004469D0) --------------------------------------------------------
wchar_t* sub_4469D0(int a1) {
	if (a1 / *getMemU32Ptr(0x5D4594, 826092) + 1 <= 1) {
		return *(wchar_t**)getMemAt(0x587000, 108848 + 8 * a1);
	}
	nox_swprintf((wchar_t*)getMemAt(0x5D4594, 827140), L"%s %d",
				 *getMemU32Ptr(0x587000, 108848 + 8 * (a1 % *getMemU32Ptr(0x5D4594, 826092))),
				 a1 / *getMemU32Ptr(0x5D4594, 826092) + 1);
	return (wchar_t*)getMemAt(0x5D4594, 827140);
}

//----- (00446C70) --------------------------------------------------------
int sub_446C70() { return nox_window_call_field_94(*(int*)&dword_5d4594_829488, 16404, 0, 0); }

//----- (00446C90) --------------------------------------------------------
int sub_446C90() { return *(int*)nox_window_call_field_94(*(int*)&dword_5d4594_829488, 16404, 0, 0) != -1; }

//----- (00446CC0) --------------------------------------------------------
wchar_t* sub_446CC0(int a1) {
	wchar_t* result; // eax
	char* v2;        // eax
	char* v3;        // eax

	result = (wchar_t*)sub_41E2F0();
	if (result == (wchar_t*)7) {
		if (a1) {
			v2 = sub_41FA40();
			nox_swprintf((wchar_t*)getMemAt(0x5D4594, 829224), *(const wchar_t**)getMemAt(0x5D4594, 829528), v2, a1);
		} else {
			result = *(wchar_t**)&dword_5d4594_829532;
			if (!dword_5d4594_829532) {
				return result;
			}
			v3 = sub_41FA40();
			nox_swprintf((wchar_t*)getMemAt(0x5D4594, 829224), *(const wchar_t**)&dword_5d4594_829532, v3);
			nox_window_call_field_94(*(int*)&dword_5d4594_829484, 16403, -1, 0);
		}
		result = (wchar_t*)nox_window_call_field_94(*getMemIntPtr(0x5D4594, 829496), 16385,
													(int)getMemAt(0x5D4594, 829224), 0);
	}
	return result;
}

//----- (00446D50) --------------------------------------------------------
void sub_446D50() {
	char* v0; // eax
	int v1;   // [esp+0h] [ebp-4h]

	v1 = 0;
	v0 = (char*)sub_4464F0(0, &v1);
	sub_446D80(v0);
}

//----- (00446D80) --------------------------------------------------------
void sub_446D80(char* a1) {
	char* v1;        // esi
	char v2[256];    // [esp+4h] [ebp-300h]
	wchar_t v3[256]; // [esp+104h] [ebp-200h]

	v1 = a1;
	if (a1) {
		while (1) {
			v1 = sub_446E20(v1, v2);
			if (!v1) {
				break;
			}
			if (!v2[0]) {
				strcpy(v2, " ");
			}
			nox_swprintf(v3, L"%S", v2);
			sub_447310(0, (int)v3);
		}
		if (v2[0]) {
			nox_swprintf(v3, L"%S", v2);
			sub_447310(0, (int)v3);
		}
	}
}

//----- (00446E20) --------------------------------------------------------
char* sub_446E20(char* a1, uint8_t* a2) {
	char* v2;     // edx
	char* v3;     // eax
	char v4;      // cl
	char* result; // eax

	v2 = a2;
	v3 = a1;
	*a2 = 0;
	if (!*a1) {
		return 0;
	}
	while (1) {
		v4 = *v3;
		if (!*v3) {
			*v2 = 0;
			return 0;
		}
		if (v4 == 10) {
			*v2 = 0;
			return v3 + 1;
		}
		if (v4 == 13) {
			break;
		}
		*v2++ = v4;
		++v3;
	}
	result = v3 + 1;
	*v2 = 0;
	if (*result == 10) {
		++result;
	}
	return result;
}

//----- (00446E60) --------------------------------------------------------
wchar_t* sub_446E60() {
	wchar_t* result; // eax

	nox_window_call_field_94(*(int*)&dword_5d4594_829484, 16399, 0, 0);
	for (result = sub_41F0A0(); result; result = sub_41F070()) {
		nox_window_call_field_94(*(int*)&dword_5d4594_829484, 16397, (int)result, 14);
	}
	return result;
}

//----- (00446EB0) --------------------------------------------------------
char* sub_446EB0() {
	char* result;    // eax
	const char* i;   // esi
	wchar_t v2[256]; // [esp+4h] [ebp-200h]

	nox_window_call_field_94(*(int*)&dword_5d4594_829488, 16399, 0, 0);
	result = sub_41F780();
	for (i = result; result; i = result) {
		nox_swprintf(v2, L"%S", i);
		if (sub_427880(i)) {
			nox_window_call_field_94(*(int*)&dword_5d4594_829488, 16397, (int)v2, 2);
		} else {
			nox_window_call_field_94(*(int*)&dword_5d4594_829488, 16397, (int)v2, 14);
		}
		result = sub_41F710();
	}
	return result;
}

//----- (00446F40) --------------------------------------------------------
char* sub_446F40(int a1) {
	int v1; // eax

	if (a1 == -1) {
		return 0;
	}
	v1 = nox_window_call_field_94(*(int*)&dword_5d4594_829488, 16406, a1, 0);
	nox_sprintf((char*)getMemAt(0x5D4594, 827120), "%S", v1);
	return (char*)getMemAt(0x5D4594, 827120);
}

//----- (004471A0) --------------------------------------------------------
const wchar_t* sub_4471A0(const char* a1, int a2, int a3, int a4) {
	const wchar_t* result; // eax

	result = (const wchar_t*)sub_427880(a1);
	if (!result) {
		result = *(const wchar_t**)&dword_5d4594_829492;
		if (dword_5d4594_829492) {
			result = *(const wchar_t**)&dword_5d4594_829544;
			if (dword_5d4594_829544) {
				if (a2) {
					if (a3) {
						if (a4 == 1) {
							nox_swprintf((wchar_t*)getMemAt(0x5D4594, 827176),
										 *(const wchar_t**)getMemAt(0x5D4594, 829552), a1, a2);
							return (const wchar_t*)nox_window_call_field_94(*(int*)&dword_5d4594_829492, 16397,
																			(int)getMemAt(0x5D4594, 827176), 7);
						}
						result = *(const wchar_t**)getMemAt(0x5D4594, 829548);
					}
					nox_swprintf((wchar_t*)getMemAt(0x5D4594, 827176), result, a1, a2);
					result = (const wchar_t*)nox_window_call_field_94(*(int*)&dword_5d4594_829492, 16397,
																	  (int)getMemAt(0x5D4594, 827176), (a3 != 0) + 6);
				}
			}
		}
	}
	return result;
}

//----- (00447250) --------------------------------------------------------
const wchar_t* sub_447250(const char* a1, int a2, int a3, int a4) {
	const wchar_t* result; // eax
	const wchar_t* v5;     // esi
	char* v6;              // eax

	result = (const wchar_t*)sub_427880(a1);
	if (!result) {
		result = *(const wchar_t**)&dword_5d4594_829492;
		if (dword_5d4594_829492) {
			if (*getMemU32Ptr(0x5D4594, 829556)) {
				result = *(const wchar_t**)getMemAt(0x5D4594, 829560);
				if (*getMemU32Ptr(0x5D4594, 829560)) {
					if (a2) {
						if (a3) {
							if (a4 == 1) {
								v5 = *(const wchar_t**)getMemAt(0x5D4594, 829564);
								v6 = sub_41FA40();
								nox_swprintf((wchar_t*)getMemAt(0x5D4594, 827176), v5, a1, v6, a2);
								return (const wchar_t*)nox_window_call_field_94(*(int*)&dword_5d4594_829492, 16397,
																				(int)getMemAt(0x5D4594, 827176), 13);
							}
						} else {
							result = *(const wchar_t**)getMemAt(0x5D4594, 829556);
						}
						nox_swprintf((wchar_t*)getMemAt(0x5D4594, 827176), result, a1, a2);
						result = (const wchar_t*)nox_window_call_field_94(*(int*)&dword_5d4594_829492, 16397,
																		  (int)getMemAt(0x5D4594, 827176), 13);
					}
				}
			}
		}
	}
	return result;
}

//----- (00447310) --------------------------------------------------------
int sub_447310(int a1, int a2) {
	int result; // eax

	result = dword_5d4594_829492;
	if (dword_5d4594_829492) {
		if (*getMemU32Ptr(0x5D4594, 829536)) {
			result = a2;
			if (a2) {
				if (a1) {
					nox_swprintf((wchar_t*)getMemAt(0x5D4594, 827176), *(const wchar_t**)getMemAt(0x5D4594, 829536), a1,
								 a2);
				} else {
					nox_swprintf((wchar_t*)getMemAt(0x5D4594, 827176), L"%s", a2);
				}
				result =
					nox_window_call_field_94(*(int*)&dword_5d4594_829492, 16397, (int)getMemAt(0x5D4594, 827176), 9);
			}
		}
	}
	return result;
}

//----- (00447380) --------------------------------------------------------
void sub_447380(const char* a1, char* a2) {
	const wchar_t* v3; // edi

	if (sub_427880(a1)) {
		return;
	}
	if (!dword_5d4594_829492) {
		return;
	}
	if (!dword_5d4594_829544) {
		return;
	}
	if (!a2) {
		return;
	}
	v3 = *(const wchar_t**)getMemAt(0x5D4594, 829540);
	sub_447410(a2);
	if (a1) {
		nox_swprintf((wchar_t*)getMemAt(0x5D4594, 827176), v3, a1, a2);
	} else {
		nox_swprintf((wchar_t*)getMemAt(0x5D4594, 827176), L"%S", a2);
	}
	nox_window_call_field_94(*(int*)&dword_5d4594_829492, 16397, (int)getMemAt(0x5D4594, 827176), 4);
	nox_xxx_clientPlaySoundSpecial_452D80(226, 100);
}

//----- (00447410) --------------------------------------------------------
unsigned int sub_447410(char* a1) {
	int v1;              // edx
	char* v2;            // ecx
	char v3;             // al
	unsigned int result; // eax

	v1 = 0;
	v2 = a1;
	if (*a1) {
		do {
			if ((unsigned char)*v2 < 0x80u) {
				*getMemU8Ptr(0x5D4594, 826096 + v1++) = *v2;
			}
			v3 = *++v2;
		} while (v3);
	}
	*getMemU8Ptr(0x5D4594, 826096 + v1) = 0;
	result = strlen((const char*)getMemAt(0x5D4594, 826096)) + 1;
	memcpy(a1, getMemAt(0x5D4594, 826096), result);
	return result;
}

//----- (004475E0) --------------------------------------------------------
int sub_4475E0() { return nox_window_call_field_94(*(int*)&dword_5d4594_829488, 16399, 0, 0); }

//----- (00447600) --------------------------------------------------------
void sub_447600() {
	if (!sub_44A4A0()) {
		nox_xxx_windowFocus_46B500(*(int*)&dword_5d4594_829500);
	}
}

//----- (00447BF0) --------------------------------------------------------
int sub_447BF0(uint32_t* a1, int a2, unsigned int a3, int a4) {
	int result; // eax

	if (a2 == 19) {
		nox_window_call_field_94((int)a1, 16391, *(uint32_t*)(a1[8] + 28), 0);
		result = 0;
	} else if (a2 == 20) {
		nox_window_call_field_94((int)a1, 16391, *(uint32_t*)(a1[8] + 32), 0);
		result = 0;
	} else if (*(uint32_t*)(a1[8] + 16)) {
		result = nox_xxx_wndListboxProcWithData10_4A2DE0((int)a1, a2, a3, a4);
	} else {
		result = nox_xxx_wndListboxProcWithoutData10_4A28E0(a1, a2, a3, a4);
	}
	return result;
}

//----- (00447C70) --------------------------------------------------------
int sub_447C70(int a1, int a2, int a3, int a4) {
	int v5; // eax

	if (a2 != 21) {
		return 0;
	}
	if (a3 != 1) {
		return 0;
	}
	if (a4 == 2 && sub_41E2F0() == 7) {
		sub_41E300(9);
		v5 = sub_41E2F0();
		sub_41DA70(v5, 8);
		sub_44A400();
	}
	return 1;
}

//----- (00448490) --------------------------------------------------------
int sub_448490() {
	int result; // eax

	result = dword_5d4594_829480;
	if (dword_5d4594_829480) {
		result = nox_xxx_windowDestroyMB_46C4E0(*(uint32_t**)&dword_5d4594_829480);
		dword_5d4594_829480 = 0;
		dword_5d4594_829484 = 0;
		dword_5d4594_829488 = 0;
		dword_5d4594_829492 = 0;
		dword_5d4594_829500 = 0;
	}
	return result;
}

//----- (004484D0) --------------------------------------------------------
void sub_4484D0(wchar_t* a1, int a2, int a3) {
	wchar_t* v3;       // eax
	const wchar_t* v4; // eax

	if (a1) {
		nox_window_call_field_94(*(int*)&dword_5d4594_829484, 16402, a3, 0);
		v3 = sub_41F330((int)a1, a2);
		nox_window_call_field_94(*(int*)&dword_5d4594_829484, 16397, (int)v3, 14);
		v4 = (const wchar_t*)sub_41EC00();
		if (v4) {
			if (!nox_wcscmp(v4, a1)) {
				nox_window_call_field_94(*(int*)&dword_5d4594_829484, 16403, a3, 0);
			}
		}
	}
}

//----- (00448550) --------------------------------------------------------
int sub_448550(int a1) { return nox_window_call_field_94(*(int*)&dword_5d4594_829484, 16398, a1, 0); }

//----- (00448570) --------------------------------------------------------
void sub_448570(const char* a1, char a2, int a3) {
	char* v3;        // eax
	wchar_t v4[256]; // [esp+4h] [ebp-200h]

	if (a1) {
		nox_window_call_field_94(*(int*)&dword_5d4594_829488, 16402, a3, 0);
		v3 = sub_41F740((int)a1, a2);
		nox_swprintf(v4, L"%S", v3);
		if (sub_427880(a1)) {
			nox_window_call_field_94(*(int*)&dword_5d4594_829488, 16397, (int)v4, 2);
		} else {
			nox_window_call_field_94(*(int*)&dword_5d4594_829488, 16397, (int)v4, 14);
		}
	}
}

//----- (00448620) --------------------------------------------------------
int sub_448620(int a1) {
	int result; // eax

	result = a1;
	if (a1 >= 0) {
		result = nox_window_call_field_94(*(int*)&dword_5d4594_829488, 16398, a1, 0);
	}
	return result;
}

//----- (00448650) --------------------------------------------------------
int sub_448650(uint8_t* a1, wchar_t* a2) {
	int result; // eax

	if (*a1 == -16) {
		result = sub_425680(a1 + 1, a2);
	} else {
		result = nox_swprintf(a2, L"%S", a1);
	}
	return result;
}

//----- (00448680) --------------------------------------------------------
int sub_448680(wchar_t* a1, char* a2) {
	int result;    // eax
	size_t v3;     // eax
	char v4[2048]; // [esp+4h] [ebp-800h]

	if (nox_xxx_cliCanTalkMB_4100F0((short*)a1)) {
		return nox_sprintf(a2, "%S", a1);
	}
	memset(v4, 0, sizeof(v4));
	memset(a2, 0, 0x800u);
	v3 = nox_wcslen(a1);
	sub_425550(a1, v4, 16 * (v3 + 1));
	result = 0;
	*a2 = -16;
	memcpy(a2 + 1, v4, strlen(v4));
	return result;
}

//----- (0044A520) --------------------------------------------------------
char* sub_44A520(int a1) {
	int v1;            // eax
	int v2;            // edx
	unsigned char* v3; // ecx

	v1 = *getMemU32Ptr(0x587000, 113136);
	v2 = 0;
	if (!*getMemU32Ptr(0x587000, 113136)) {
		return *(char**)getMemAt(0x587000, 113140);
	}
	v3 = getMemAt(0x587000, 113136);
	while (v1 != a1) {
		v1 = *((uint32_t*)v3 + 2);
		v3 += 8;
		++v2;
		if (!v1) {
			return *(char**)getMemAt(0x587000, 113140);
		}
	}
	return *(char**)getMemAt(0x587000, 113140 + 8 * v2);
}

//----- (0044AA40) --------------------------------------------------------
int sub_44AA40() {
	nox_wnd_xxx_830244->state = NOX_GUI_ANIM_OUT;
	sub_43BE40(2);
	nox_xxx_clientPlaySoundSpecial_452D80(923, 100);
	sub_4207F0(1);
	return 1;
}

//----- (0044AA70) --------------------------------------------------------
int sub_44AA70() {
	int (*v0)(void); // esi

	v0 = nox_wnd_xxx_830244->field_13;
	nox_gui_freeAnimation_43C570(nox_wnd_xxx_830244);
	if (dword_5d4594_830248) {
		nox_xxx_windowDestroyMB_46C4E0(*(uint32_t**)&dword_5d4594_830248);
		dword_5d4594_830248 = 0;
	}
	sub_43BE40(1);
	v0();
	return 1;
}

//----- (0044AFB0) --------------------------------------------------------
uint32_t* sub_44AFB0(int a1, int a2, int a3) {
	uint32_t* result; // eax

	if (a3 < -2147221388 || a3 > -2147221386) {
		result = nox_xxx_dialogMsgBoxCreate_449A10(*(int*)&dword_5d4594_830248, a1, a2, 33, 0, 0);
	} else {
		result = nox_xxx_dialogMsgBoxCreate_449A10(*(int*)&dword_5d4594_830248, a1, a2, 545, 0, 0);
	}
	*getMemU32Ptr(0x5D4594, 830280) = a3;
	return result;
}

//----- (0044B940) --------------------------------------------------------
int sub_44B940(uint32_t* a1, int a2, nox_memfile* f) {
	int v3;            // esi
	int v4;            // ebx
	void* v5;          // eax
	int v6;            // ebp
	int v8;            // ebx
	char v10;          // cl
	int v13;           // [esp+10h] [ebp-90h]
	int v14;           // [esp+14h] [ebp-8Ch]
	unsigned char v15; // [esp+18h] [ebp-88h]
	const char* v16;   // [esp+1Ch] [ebp-84h]
	char v17[128];     // [esp+20h] [ebp-80h]

	v3 = a2;
	v4 = 0;
	*a1 = 40;
	v14 = 0;
	while (1) {
		v13 = v4 >= 16 ? v4 + 4 : v4;
		v5 = calloc(v3, 4);
		*(uint32_t*)((char*)a1 + v13 + 4) = v5;
		if (!v5) {
			break;
		}
		v6 = 0;
		if (v3 > 0) {
			do {
				v8 = nox_memfile_read_i32(f);
				v17[0] = getMemByte(0x5D4594, 830840);
				if (v8 == -1) {
					v10 = nox_memfile_read_i8(f);
					v15 = nox_memfile_read_u8(f);
					LOBYTE(v16) = v10;
					nox_memfile_read(v17, 1, v15, f);
					v17[v15] = 0;
					v3 = a2;
				}
				*(uint32_t*)(*(uint32_t*)((char*)a1 + v13 + 4) + 4 * ++v6 - 4) = nox_xxx_readImgMB_42FAA0(v8, v16, v17);
			} while (v6 < v3);
			v4 = v14;
		}
		v4 += 4;
		v14 = v4;
		if (v4 >= 32) {
			return 1;
		}
	}
	return 0;
}
// 44BA0E: variable 'v16' is possibly undefined
// 44B940: using guessed type char var_80[128];

//----- (0044BA60) --------------------------------------------------------
int nox_xxx_parse_Armor_44BA60(const char* a1) {
	int v1;          // ebp
	const char** v2; // edi

	v1 = 0;
	v2 = (const char**)getMemAt(0x587000, 113856);
	while (strcmp(*v2, a1)) {
		++v2;
		++v1;
		if ((int)v2 >= (int)getMemAt(0x587000, 113960)) {
			return -1;
		}
	}
	return v1;
}

//----- (0044BAC0) --------------------------------------------------------
int sub_44BAC0(const char* a1) {
	int v1;          // ebp
	const char** v2; // edi

	v1 = 0;
	v2 = (const char**)getMemAt(0x587000, 113964);
	while (strcmp(*v2, a1)) {
		++v2;
		++v1;
		if ((int)v2 >= (int)getMemAt(0x587000, 114072)) {
			return -1;
		}
	}
	return v1;
}

//----- (0044BB20) --------------------------------------------------------
int sub_44BB20(const char* a1) {
	int v1;          // ebp
	const char** v2; // edi

	v1 = 0;
	v2 = (const char**)getMemAt(0x587000, 115688);
	while (strcmp(a1, *v2)) {
		++v2;
		++v1;
		if ((int)v2 >= (int)getMemAt(0x587000, 115908)) {
			return -1;
		}
	}
	return v1;
}
// 44BD0C: variable 'v15' is possibly undefined
// 44BC50: using guessed type char var_80[128];
// 44BE2F: variable 'v11' is possibly undefined
// 44BF33: variable 'v11' is possibly undefined
// 44BE90: using guessed type char var_80[128];
// 44C0BD: variable 'v13' is possibly undefined
