#include "common__system__team.h"
// FIXME
#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME2.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "client__gui__guicon.h"
#include "client__gui__guimsg.h"
#include "client__gui__servopts__guiserv.h"
#include "common__strman.h"
#include "operators.h"

extern uint32_t dword_5d4594_527660;
extern uint32_t nox_player_netCode_85319C;

#ifndef NOX_CGO
nox_team_t nox_server_teams_526292[NOX_TEAMS_MAX] = {0};
#endif // NOX_CGO

typedef struct {
	const char* name;
	wchar_t* title;
	int code;
	uint32_t* color;
} nox_team_info_t;

uint32_t nox_color_white_2523948 = 0;
uint32_t nox_color_red_2589776 = 0;
uint32_t nox_color_blue_2650684 = 0;
uint32_t nox_color_green_2614268 = 0;
uint32_t nox_color_cyan_2649820 = 0;
uint32_t nox_color_yellow_2589772 = 0;
uint32_t nox_color_violet_2598268 = 0;
uint32_t nox_color_black_2650656 = 0;
uint32_t nox_color_orange_2614256 = 0;

nox_team_info_t nox_team_table[] = {
    {"advserv.wnd:None", 0, 0, &nox_color_white_2523948},
    {"modifier.db:MaterialTeamRedDesc",    0, 1, &nox_color_red_2589776},
    {"modifier.db:MaterialTeamBlueDesc",   0, 2, &nox_color_blue_2650684},
    {"modifier.db:MaterialTeamGreenDesc",  0, 3, &nox_color_green_2614268},
    {"modifier.db:MaterialTeamCyanDesc",   0, 4, &nox_color_cyan_2649820},
    {"modifier.db:MaterialTeamYellowDesc", 0, 5, &nox_color_yellow_2589772},
    {"modifier.db:MaterialTeamVioletDesc", 0, 6, &nox_color_violet_2598268},
    {"modifier.db:MaterialTeamBlackDesc",  0, 7, &nox_color_black_2650656},
    {"modifier.db:MaterialTeamWhiteDesc",  0, 8, &nox_color_white_2523948},
    {"modifier.db:MaterialTeamOrangeDesc", 0, 9, &nox_color_orange_2614256},
};
int nox_team_table_cnt = sizeof(nox_team_table) / sizeof(nox_team_info_t);

#ifndef NOX_CGO
//----- (00418AE0) --------------------------------------------------------
nox_team_t* nox_server_teamByXxx_418AE0(int a1) {
	for (nox_team_t* it = nox_server_teamFirst_418B10(); it; it = nox_server_teamNext_418B60(it)) {
		if (it->field_60 == a1) {
			return it;
		}
	}
	return 0;
}

//----- (00418B10) --------------------------------------------------------
nox_team_t* nox_server_teamFirst_418B10() {
	for (int i = 1; i < NOX_TEAMS_MAX; i++) {
		nox_team_t* t = &nox_server_teams_526292[i];
		if (t->active) {
			return t;
		}
	}
	return 0;
}

//----- (00418B60) --------------------------------------------------------
nox_team_t* nox_server_teamNext_418B60(nox_team_t* t) {
	if (!t) {
		return 0;
	}
	for (int i = t->ind+1; i < NOX_TEAMS_MAX; i++) {
		nox_team_t* t2 = &nox_server_teams_526292[i];
		if (t2->active) {
			return t2;
		}
	}
	return 0;
}

//----- (004187E0) --------------------------------------------------------
int nox_server_teamGetInactive_4187E0() {
	for (int i = 1; i < NOX_TEAMS_MAX; i++) {
		nox_team_t* t = &nox_server_teams_526292[i];
		if (!t->active) {
			return i;
		}
	}
	return 0;
}

//----- (004187A0) --------------------------------------------------------
char sub_4187A0() {
	int i;    // ebx
	char* v1; // eax

	for (i = 1; i < 17; ++i) {
		v1 = nox_server_teamFirst_418B10();
		if (!v1) {
			return i;
		}
		while ((unsigned char)v1[57] != i) {
			v1 = nox_server_teamNext_418B60((int)v1);
			if (!v1) {
				return i;
			}
		}
	}
	return 0;
}

//----- (00417C60) --------------------------------------------------------
int nox_server_teamsReset_417C60() {
	memset(nox_server_teams_526292, 0, NOX_TEAMS_MAX*sizeof(nox_team_t));
	for (int i = 0; i < NOX_TEAMS_MAX - 1; i++) {
		nox_team_t* t = &nox_server_teams_526292[i];
		t->field_57 = 0;
		t->field_72 = 0;
		t->field_76 = 0;
		t->field_60 = 0;
	}
	if (!*getMemU32Ptr(0x5D4594, 526288)) {
		for (int i = 0; i < nox_team_table_cnt; i++) {
			nox_team_info_t* t = &nox_team_table[i];
			t->title = nox_strman_loadString_40F1D0(t->name, 0, "C:\\NoxPost\\src\\common\\System\\team.c", 233);
		}
		*getMemU32Ptr(0x5D4594, 526288) = 1;
	}
	nox_xxx_SetGameplayFlag_417D50(2);
	nox_xxx_UnsetGameplayFlags_417D70(1);
	nox_xxx_UnsetGameplayFlags_417D70(4);
	return 1;
}

//----- (00418AB0) --------------------------------------------------------
nox_team_t* nox_xxx_clientGetTeamColor_418AB0(int a1) {
	char* result; // eax

	result = nox_server_teamFirst_418B10();
	if (!result) {
		return 0;
	}
	while ((unsigned char)result[57] != a1) {
		result = nox_server_teamNext_418B60((int)result);
		if (!result) {
			return 0;
		}
	}
	return result;
}

//----- (00417E10) --------------------------------------------------------
int nox_xxx_createCoopTeam_417E10() {
	char* v0;     // esi
	uint32_t* v1; // eax
	wchar_t* v2;  // eax

	nox_xxx_setGameFlags_40A4D0(512);
	v0 = nox_xxx_clientGetTeamColor_418AB0(1);
	if (!v0) {
		v0 = nox_xxx_teamCreate_4186D0(1);
	}
	v1 = nox_xxx_objGetTeamByNetCode_418C80(nox_player_netCode_85319C);
	if (v1) {
		nox_xxx_createAtImpl_4191D0(v0[57], (int)v1, 0, nox_player_netCode_85319C, 0);
	}
	if (v0) {
		v2 = nox_strman_loadString_40F1D0("COOP", 0, "C:\\NoxPost\\src\\common\\System\\team.c", 405);
		sub_418800((wchar_t*)v0, v2, 0);
	}
	nox_xxx_UnsetGameplayFlags_417D70(1);
	return 1;
}

//----- (00417DD0) --------------------------------------------------------
unsigned char nox_xxx_getTeamCounter_417DD0() { return getMemByte(0x5D4594, 526280); }

//----- (004186D0) --------------------------------------------------------
nox_team_t* nox_xxx_teamCreate_4186D0(char a1) {
	if (getMemByte(0x5D4594, 526280) >= (NOX_TEAMS_MAX - 1)) {
		wchar_t* v1 = nox_strman_loadString_40F1D0("teamexceed", 0, "C:\\NoxPost\\src\\common\\System\\team.c", 982);
		nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v1);
		return 0;
	}
	unsigned char ti = nox_server_teamGetInactive_4187E0();
	nox_team_t* t = &nox_server_teams_526292[ti];
	t->field_52 = 0;
	t->field_48 = 0;
	t->name[0] = 0;
	t->field_68 = 0;
	t->field_44 = 0;
	t->field_60 = 0;
	t->ind = ti;
	t->field_56 = ti;
	char v6 = a1;
	if (!a1) {
		v6 = sub_4187A0();
	}
	t->field_57 = v6;
	t->active = 1;
	++*getMemU8Ptr(0x5D4594, 526280);
	sub_459CD0();
	if (!nox_common_gameFlags_check_40A5C0(512)) {
		wchar_t* v8 = nox_strman_loadString_40F1D0("teamcreate", 0, "C:\\NoxPost\\src\\common\\System\\team.c", 1009);
		nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v8);
	}
	return t;
}

//----- (00418C20) --------------------------------------------------------
wchar_t* nox_server_teamTitle_418C20(int a1) {
	for (int i = 0; i < nox_team_table_cnt; i++) {
		nox_team_info_t* t = &nox_team_table[i];
		if (t->code == a1) {
			return t->title;
		}
	}
	return nox_strman_loadString_40F1D0("NoTeam", 0, "C:\\NoxPost\\src\\common\\System\\team.c", 1365);
}

//----- (00418D50) --------------------------------------------------------
uint32_t* nox_xxx_materialGetTeamColor_418D50(nox_team_t* a1p) {
	if (!a1p) {
		return 0;
	}
	for (int i = 0; i < nox_team_table_cnt; i++) {
		nox_team_info_t* t = &nox_team_table[i];
		if (t->code == *(unsigned char*)((int)a1p + 56)) {
			return t->color;
		}
	}
	return 0;
}

//----- (00417D00) --------------------------------------------------------
int nox_server_teamsResetYyy_417D00() {
	for (int i = 1; i < NOX_TEAMS_MAX; i++) {
		nox_team_t* t = &nox_server_teams_526292[i];
		t->field_52 = 0;
	}
	int result = 0;
	if (nox_common_gameFlags_check_40A5C0(1)) {
		short v3 = 2500;
		result = nox_xxx_netSendPacket1_4E5390(159, (int)&v3, 2, 0, 1);
	}
	return result;
}

//----- (00419030) --------------------------------------------------------
int nox_server_teamsZzz_419030(int a1) {
	nox_xxx_UnsetGameplayFlags_417D70(4);
	for (int i = 1; i < NOX_TEAMS_MAX; i++) {
		nox_team_t* t = &nox_server_teams_526292[i];
		if (t->active) {
			sub_418F20(t, 0);
		}
	}
	int result = 0;
	if (a1) {
		uint16_t a1a = 1988;
		sub_456FA0();
		result = nox_xxx_netSendPacket1_4E5390(159, (int)&a1a, 2, 0, 1);
	}
	return result;
}
#endif // NOX_CGO

//----- (004191D0) --------------------------------------------------------
void nox_xxx_createAtImpl_4191D0(unsigned char a1, void* a2p, int a3, int a4, int a5) {
	int a2 = a2p;
	char* result;     // eax
	char* v6;         // esi
	int v7;           // ebx
	char* v8;         // ebp
	char* v9;         // ebp
	wchar_t* v10;     // eax
	wchar_t* v11;     // eax
	short v12;        // dx
	int v13;          // eax
	uint32_t* v14;    // eax
	char* v15;        // ebx
	wchar_t* v16;     // eax
	wchar_t* v17;     // eax
	char* v18;        // esi
	int v19;          // edi
	int i;            // esi
	int v21[3];       // [esp+0h] [ebp-110h] // FIXME: 10 bytes
	short v22;        // [esp+8h] [ebp-108h]
	char* v23;        // [esp+Ch] [ebp-104h]
	wchar_t v24[128]; // [esp+10h] [ebp-100h]

	result = *(char**)&dword_5d4594_527660;
	if (!dword_5d4594_527660) {
		result = (char*)nox_xxx_getNameId_4E3AA0("GameBall");
		dword_5d4594_527660 = result;
	}
	if (!a2) {
		return;
	}
	v6 = nox_xxx_clientGetTeamColor_418AB0(a1);
	if (v6) {
		result = (char*)nox_xxx_teamCompare2_419180(a2, a1);
		if (result) {
			return;
		}
	} else {
		v6 = nox_xxx_teamCreate_4186D0(a1);
	}
	*(uint8_t*)(a2 + 4) = v6[57];
	*(uint32_t*)a2 = *((uint32_t*)v6 + 11);
	*((uint32_t*)v6 + 11) = a2;
	if (a4 == nox_player_netCode_85319C) {
		sub_455E70(v6[57]);
	}
	if (nox_common_gameFlags_check_40A5C0(1)) {
		if (nox_common_gameFlags_check_40A5C0(0x2000)) {
			v7 = nox_server_getObjectFromNetCode_4ECCB0(a4);
			v8 = nox_common_playerInfoGetByID_417040(a4);
			v23 = v8;
			if (v8) {
				if (nox_common_gameFlags_check_40A5C0(0x8000)) {
					sub_425ED0((int)v8, 1);
				}
				if (v7 && *(uint8_t*)(v7 + 8) & 4) {
					if (a5 == 1 && !nox_xxx_CheckGameplayFlags_417DA0(2) && nox_common_gameFlags_check_40A5C0(128)) {
						sub_4ED970(50.0, (float2*)(*((uint32_t*)v6 + 18) + 56), &v21);
						nox_xxx_unitMove_4E7010(v7, &v21);
					}
					v9 = nox_common_playerInfoGetByID_417040(a4);
					if (v9) {
						if (nox_common_gameFlags_check_40A5C0(4096)) {
							v10 = nox_strman_loadString_40F1D0("GeneralPrint:PlayerJoinQuest", 0,
															   "C:\\NoxPost\\src\\common\\System\\team.c", 1848);
							nox_swprintf(v24, v10, v9 + 4704);
						} else {
							v11 = nox_strman_loadString_40F1D0("NewMember", 0,
															   "C:\\NoxPost\\src\\common\\System\\team.c", 1850);
							nox_swprintf(v24, v11, v9 + 4704, v6);
						}
						nox_xxx_printCentered_445490(v24);
					}
					v8 = v23;
				}
			}
			if (a3 && v7 && (v8 || *(unsigned short*)(v7 + 4) == dword_5d4594_527660)) {
				v12 = *(uint16_t*)(v7 + 4);
				v13 = (unsigned char)v6[57];
				LOWORD(v21[0]) = 452;
				HIWORD(v21[1]) = a4;
				*(uint32_t*)((char*)&v21[0] + 2) = v13;
				v22 = v12;
				sub_4571A0(a4, v13);
				nox_xxx_netSendPacket1_4E5390(159, (int)&v21, 10, 0, 1);
			}
		}
	} else {
		v14 = nox_xxx_netSpriteByCodeDynamic_45A6F0(a4);
		if (v14 && v14[28] & 4) {
			v15 = nox_common_playerInfoGetByID_417040(a4);
			if (v15) {
				if (nox_common_gameFlags_check_40A5C0(4096)) {
					v16 = nox_strman_loadString_40F1D0("GeneralPrint:PlayerJoinQuest", 0,
													   "C:\\NoxPost\\src\\common\\System\\team.c", 1889);
					nox_swprintf(v24, v16, v15 + 4704);
				} else {
					v17 =
						nox_strman_loadString_40F1D0("NewMember", 0, "C:\\NoxPost\\src\\common\\System\\team.c", 1891);
					nox_swprintf(v24, v17, v15 + 4704, v6);
				}
				nox_xxx_printCentered_445490(v24);
			}
		}
	}
	++*((uint32_t*)v6 + 12);
	result = (char*)nox_xxx_getFirstPlayerUnit_4DA7C0();
	v18 = result;
	if (!result) {
		return;
	}
	while (*((uint32_t*)v18 + 9) != a4) {
		result = (char*)nox_xxx_getNextPlayerUnit_4DA7F0((int)v18);
		v18 = result;
		if (!result) {
			return;
		}
	}
	v19 = *((uint32_t*)v18 + 187);
	sub_4D97E0(*(unsigned char*)(*(uint32_t*)(v19 + 276) + 2064));
	sub_4E8110(*(unsigned char*)(*(uint32_t*)(v19 + 276) + 2064));
	result = nox_xxx_monsterMarkUpdate_4E8020((int)v18);
	for (i = *((uint32_t*)v18 + 129); i; i = *(uint32_t*)(i + 512)) {
		if (*(uint8_t*)(i + 8) & 6) {
			result = nox_xxx_monsterMarkUpdate_4E8020(i);
		}
	}
}
