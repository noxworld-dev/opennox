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

typedef struct {
	const char* name;
	wchar2_t* title;
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

//----- (004191D0) --------------------------------------------------------
void nox_xxx_createAtImpl_4191D0(unsigned char a1, void* a2p, int a3, int a4, int a5) {
	int a2 = a2p;
	char* result;     // eax
	char* v6;         // esi
	int v7;           // ebx
	char* v8;         // ebp
	char* v9;         // ebp
	wchar2_t* v10;     // eax
	wchar2_t* v11;     // eax
	short v12;        // dx
	int v13;          // eax
	uint32_t* v14;    // eax
	char* v15;        // ebx
	wchar2_t* v16;     // eax
	wchar2_t* v17;     // eax
	char* v18;        // esi
	int v19;          // edi
	int i;            // esi
	int v21[3];       // [esp+0h] [ebp-110h] // FIXME: 10 bytes
	short v22;        // [esp+8h] [ebp-108h]
	char* v23;        // [esp+Ch] [ebp-104h]
	wchar2_t v24[128]; // [esp+10h] [ebp-100h]

	result = *(char**)&dword_5d4594_527660;
	if (!dword_5d4594_527660) {
		result = (char*)nox_xxx_getNameId_4E3AA0("GameBall");
		dword_5d4594_527660 = result;
	}
	if (!a2) {
		return;
	}
	v6 = nox_xxx_getTeamByID_418AB0(a1);
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
