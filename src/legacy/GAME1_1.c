#include <math.h>
#include <time.h>

// For htonl
#ifdef _WIN32
#include <winsock.h>
#else
#include <arpa/inet.h>
#endif

#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4.h"
#include "GAME5_2.h"
#include "common__system__team.h"
#include "server__ability__ability.h"
#include "server__magic__plyrgide.h"
#include "server__magic__plyrspel.h"
#include "server__system__server.h"

#include "client__gui__guiinv.h"
#include "client__gui__guijourn.h"
#include "client__gui__servopts__guiserv.h"
#include "client__gui__servopts__playrlst.h"
#include "common__binfile.h"
#include "common__crypt.h"
#include "common__log.h"
#include "common__random.h"
#include "operators.h"

#include "client__gui__guibook.h"

#include "client__video__draw_common.h"
#include "common/fs/nox_fs.h"
#include "common__magic__speltree.h"
#include "server__script__builtin.h"
#include "server__script__script.h"

FILE* nox_file_2 = 0;

extern uint32_t dword_5d4594_527712;
extern uint32_t dword_5d4594_739392;
extern uint32_t dword_5d4594_527988;
extern uint32_t dword_5d4594_529332;
extern uint32_t dword_5d4594_600116;
extern uint32_t dword_5d4594_528264;
extern uint32_t dword_5d4594_741296;
extern uint32_t dword_5d4594_599496;
extern uint32_t dword_5d4594_528260;
extern uint32_t dword_5d4594_741260;
extern uint32_t dword_5d4594_531652;
extern uint32_t dword_5d4594_741244;
extern uint32_t dword_587000_66116;
extern uint32_t dword_5d4594_741256;
extern uint32_t dword_5d4594_741252;
extern uint32_t dword_5d4594_741248;
extern uint32_t dword_5d4594_529336;
extern uint32_t dword_5d4594_531656;
extern uint32_t dword_5d4594_741292;
extern uint32_t dword_5d4594_588068;
extern uint32_t dword_5d4594_608316;
extern uint32_t dword_5d4594_588084;
extern uint32_t dword_5d4594_588120;
extern uint32_t dword_5d4594_528252;
extern uint32_t dword_587000_60044;
extern uint32_t dword_5d4594_741284;
extern uint32_t dword_5d4594_531648;
extern uint32_t nox_xxx_polygonNextAngle_587000_60356;
extern uint32_t dword_5d4594_528256;
extern uint32_t dword_5d4594_534808;
extern uint32_t dword_5d4594_529340;
extern uint32_t nox_xxx_polygonNextIdx_587000_60352;
extern uint32_t dword_5d4594_2660652;
extern uint32_t dword_5d4594_529316;
extern uint32_t nox_player_netCode_85319C;
extern obj_5D4594_2650668_t** ptr_5D4594_2650668;
extern int ptr_5D4594_2650668_cap;

//----- (00418800) --------------------------------------------------------
void sub_418800(wchar2_t* a1, wchar2_t* a2, int a3) {
	if (a1) {
		nox_wcsncpy(a1, a2, 20);
		a1[20] = 0;
		*((uint32_t*)a1 + 17) = a3;
	}
}

//----- (00418830) --------------------------------------------------------
int sub_418830(int a1, int a2) {
	int result; // eax

	result = a1;
	if (a1) {
		*(uint32_t*)(a1 + 60) = a2;
	}
	return result;
}

//----- (00418840) --------------------------------------------------------
int nox_xxx_unused_418840() {
	int v0;       // ebp
	char* v1;     // ebx
	char* v2;     // esi
	short v3;     // ax
	int* i;       // edi
	char* v5;     // eax
	int j;        // esi
	uint32_t* v7; // eax
	int v8;       // ecx
	int v9;       // eax
	int k;        // esi
	int v11;      // eax

	v0 = 0;
	v1 = sub_416640();
	v2 = sub_4165B0();
	nox_server_teamsZzz_419030(1);
	v3 = *((uint16_t*)v2 + 26) & 0x3FFF;
	HIBYTE(v3) |= 0x80u;
	*((uint16_t*)v2 + 26) = v3;
	for (i = sub_425A50(); i; i = sub_425A60(i)) {
		if (v0 >= (unsigned char)v1[52]) {
			break;
		}
		v5 = nox_xxx_teamCreate_4186D0(0);
		i[9] = (int)v5;
		if (v5) {
			sub_418800((wchar2_t*)v5, (wchar2_t*)i + 6, 0);
			sub_418830(i[9], i[8]);
			sub_4184D0((wchar2_t*)i[9]);
			++v0;
			for (j = nox_xxx_getFirstPlayerUnit_4DA7C0(); j; j = nox_xxx_getNextPlayerUnit_4DA7F0(j)) {
				v7 = *(uint32_t**)(*(uint32_t*)(j + 748) + 276);
				if (v7[515] != nox_player_netCode_85319C ||
					!nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
					v8 = v7[920];
					if (!(v8 & 1) || v8 & 0x20) {
						v9 = v7[517];
						if (v9) {
							if (v9 == i[8]) {
								nox_xxx_createAtImpl_4191D0(*(uint8_t*)(i[9] + 57), j + 48, 1, *(uint32_t*)(j + 36), 0);
							}
						}
					}
				}
			}
		}
	}
	for (k = nox_xxx_getFirstPlayerUnit_4DA7C0(); k; k = nox_xxx_getNextPlayerUnit_4DA7F0(k)) {
		if (!nox_xxx_servObjectHasTeam_419130(k + 48)) {
			v11 = *(uint32_t*)(*(uint32_t*)(k + 748) + 276);
			if ((*(uint32_t*)(v11 + 2060) != nox_player_netCode_85319C ||
				 !nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) &&
				!(*(uint8_t*)(v11 + 3680) & 1)) {
				nox_xxx_playerGoObserver_4E6860(v11, 0, 0);
			}
		}
	}
	nox_xxx_SetGameplayFlag_417D50(4);
	return 1;
}

//----- (004189D0) --------------------------------------------------------
char* sub_4189D0() {
	char* v0;         // edi
	unsigned char v1; // bl
	char* i;          // esi
	unsigned char v3; // al

	v0 = 0;
	v1 = 32;
	for (i = nox_server_teamFirst_418B10(); i; i = nox_server_teamNext_418B60((int)i)) {
		v3 = sub_418BC0((int)i);
		if (v3 < v1) {
			v1 = v3;
			v0 = i;
		}
	}
	return v0;
}

//----- (00418A10) --------------------------------------------------------
char* sub_418A10() {
	char* result; // eax

	result = nox_server_teamFirst_418B10();
	if (!result) {
		return nox_xxx_teamCreate_4186D0(0);
	}
	while (*((uint32_t*)result + 15)) {
		result = nox_server_teamNext_418B60((int)result);
		if (!result) {
			return nox_xxx_teamCreate_4186D0(0);
		}
	}
	return result;
}

//----- (00418A40) --------------------------------------------------------
char* sub_418A40(wchar2_t* a1) {
	char* v1; // esi

	v1 = nox_server_teamFirst_418B10();
	if (!v1) {
		return 0;
	}
	while (_nox_wcsicmp((const wchar2_t*)v1, a1)) {
		v1 = nox_server_teamNext_418B60((int)v1);
		if (!v1) {
			return 0;
		}
	}
	return v1;
}

//----- (00418A80) --------------------------------------------------------
char* sub_418A80(int a1) {
	char* result; // eax

	result = nox_server_teamFirst_418B10();
	if (!result) {
		return 0;
	}
	while ((unsigned char)result[56] != a1) {
		result = nox_server_teamNext_418B60((int)result);
		if (!result) {
			return 0;
		}
	}
	return result;
}

//----- (00418BC0) --------------------------------------------------------
int sub_418BC0(int a1) {
	int v1;       // ebx
	char* i;      // esi
	uint32_t* v4; // eax

	v1 = 0;
	if (!a1) {
		return 0;
	}
	for (i = nox_common_playerInfoGetFirst_416EA0(); i; i = nox_common_playerInfoGetNext_416EE0((int)i)) {
		v4 = nox_xxx_objGetTeamByNetCode_418C80(*((uint32_t*)i + 515));
		if (v4) {
			if (nox_xxx_teamCompare2_419180((int)v4, *(uint8_t*)(a1 + 57))) {
				++v1;
			}
		}
	}
	return v1;
}

//----- (00418C60) --------------------------------------------------------
int nox_xxx_teamCheckSmth_418C60(int a1) {
	int result; // eax

	result = a1;
	if (a1) {
		result = *(uint32_t*)(a1 + 44);
	}
	return result;
}

//----- (00418C70) --------------------------------------------------------
uint32_t* sub_418C70(uint32_t* a1) {
	uint32_t* result; // eax

	result = a1;
	if (a1) {
		result = (uint32_t*)*a1;
	}
	return result;
}

//----- (00418C80) --------------------------------------------------------
uint32_t* nox_xxx_objGetTeamByNetCode_418C80(int a1) {
	int v1;       // eax
	uint32_t* v3; // eax

	if (nox_common_gameFlags_check_40A5C0(1)) {
		v1 = nox_server_getObjectFromNetCode_4ECCB0(a1);
		if (v1) {
			return (uint32_t*)(v1 + 48);
		}
	} else {
		v3 = nox_xxx_netSpriteByCodeDynamic_45A6F0(a1);
		if (v3) {
			return v3 + 6;
		}
	}
	return 0;
}

//----- (00418CD0) --------------------------------------------------------
void nox_xxx_teamRenameMB_418CD0(wchar2_t* a1, wchar2_t* a2) {
	int v2;      // eax
	char v3[46]; // [esp+4h] [ebp-30h]

	if (a1) {
		sub_457010((int)a1, a2);
		*((uint32_t*)a1 + 17) = 0;
		if (nox_common_gameFlags_check_40A5C0(1)) {
			v2 = *((unsigned char*)a1 + 57);
			*(uint16_t*)v3 = 1220;
			*(uint32_t*)&v3[2] = v2;
			nox_wcscpy((wchar2_t*)&v3[6], a2);
			nox_xxx_netSendPacket1_4E5390(159, (int)v3, 46, 0, 1);
		}
		nox_wcscpy(a1, a2);
	}
}

//----- (00418D80) --------------------------------------------------------
void sub_418D80(int a1) {
	int v1;       // eax
	char* i;      // esi
	uint32_t* v3; // eax
	int v4;       // edi
	char v5[6];   // [esp+8h] [ebp-8h]

	if (a1 && sub_418BC0(a1) > 0) {
		if (nox_common_gameFlags_check_40A5C0(1)) {
			v1 = *(unsigned char*)(a1 + 57);
			v5[0] = -60;
			v5[1] = 5;
			*(uint32_t*)&v5[2] = v1;
			nox_xxx_netSendPacket1_4E5390(159, (int)v5, 6, 0, 1);
		}
		for (i = nox_common_playerInfoGetFirst_416EA0(); i; i = nox_common_playerInfoGetNext_416EE0((int)i)) {
			v3 = nox_xxx_objGetTeamByNetCode_418C80(*((uint32_t*)i + 515));
			v4 = (int)v3;
			if (v3) {
				if (*((uint8_t*)v3 + 4) == *(uint8_t*)(a1 + 57)) {
					sub_4571A0(*((uint32_t*)i + 515), 0);
					sub_418E40(a1, v4);
				}
			}
		}
	}
}

//----- (00418E40) --------------------------------------------------------
uint32_t* sub_418E40(int a1, int a2) {
	uint32_t* result; // eax
	uint32_t* v3;     // esi
	int v4;           // edi
	int i;            // esi

	result = (uint32_t*)a1;
	if (a1 && a2) {
		if (*(uint32_t*)(a1 + 44) == a2) {
			*(uint32_t*)(a1 + 44) = *(uint32_t*)a2;
		} else {
			result = (uint32_t*)nox_xxx_teamCheckSmth_418C60(a1);
			if (!result) {
				return result;
			}
			while (*result != a2) {
				result = sub_418C70(result);
				if (!result) {
					return result;
				}
			}
			*result = *(uint32_t*)a2;
		}
		*(uint32_t*)a2 = 0;
		*(uint8_t*)(a2 + 4) = 0;
		result = (uint32_t*)nox_xxx_getFirstPlayerUnit_4DA7C0();
		v3 = result;
		if (result) {
			while (v3 + 12 != (uint32_t*)a2) {
				result = (uint32_t*)nox_xxx_getNextPlayerUnit_4DA7F0((int)v3);
				v3 = result;
				if (!result) {
					return result;
				}
			}
			v4 = v3[187];
			sub_4D97E0(*(unsigned char*)(*(uint32_t*)(v4 + 276) + 2064));
			sub_4E8110(*(unsigned char*)(*(uint32_t*)(v4 + 276) + 2064));
			result = nox_xxx_monsterMarkUpdate_4E8020((int)v3);
			for (i = v3[129]; i; i = *(uint32_t*)(i + 512)) {
				if (*(uint8_t*)(i + 8) & 6) {
					result = nox_xxx_monsterMarkUpdate_4E8020(i);
				}
			}
		}
	}
	return result;
}

//----- (00418F20) --------------------------------------------------------
void sub_418F20(nox_team_t* a1p, int a2) {
	wchar2_t* a1 = a1p;
	int v2;         // edx
	char* i;        // edi
	uint32_t* v4;   // eax
	char v5[6];     // [esp+8h] [ebp-30h]
	wchar2_t v6[20]; // [esp+10h] [ebp-28h]

	if (a1 && nox_xxx_clientGetTeamColor_418AB0(*((unsigned char*)a1 + 57))) {
		nox_wcscpy(v6, a1);
		if (nox_common_gameFlags_check_40A5C0(1) && a2) {
			v2 = *((unsigned char*)a1 + 57);
			v5[0] = -60;
			v5[1] = 6;
			*(uint32_t*)&v5[2] = v2;
			nox_xxx_netSendPacket1_4E5390(159, (int)v5, 6, 0, 1);
		}
		for (i = nox_common_playerInfoGetFirst_416EA0(); i; i = nox_common_playerInfoGetNext_416EE0((int)i)) {
			v4 = nox_xxx_objGetTeamByNetCode_418C80(*((uint32_t*)i + 515));
			if (v4 && *((uint8_t*)v4 + 4) == *((uint8_t*)a1 + 57)) {
				sub_418E40((int)a1, (int)v4);
			}
		}
		*((uint32_t*)a1 + 12) = 0;
		*((uint32_t*)a1 + 16) = 0;
		*a1 = 0;
		*((uint32_t*)a1 + 17) = 0;
		*((uint32_t*)a1 + 11) = 0;
		*((uint32_t*)a1 + 18) = 0;
		*((uint32_t*)a1 + 19) = 0;
		*((uint8_t*)a1 + 57) = 0;
		*((uint32_t*)a1 + 15) = 0;
		--*getMemU8Ptr(0x5D4594, 526280);
		sub_459CD0();
		if (nox_common_gameFlags_check_40A5C0(1)) {
			sub_456EA0(v6);
		}
	}
}

//----- (00419090) --------------------------------------------------------
void nox_xxx_netChangeTeamID_419090(int a1, int a2) {
	int v2;      // edx
	int v3;      // ecx
	char v4[10]; // [esp+4h] [ebp-Ch]

	if (a1) {
		*(uint32_t*)(a1 + 52) = a2;
		if (nox_common_gameFlags_check_40A5C0(1)) {
			v2 = *(uint32_t*)(a1 + 52);
			v3 = *(unsigned char*)(a1 + 57);
			v4[0] = -60;
			v4[1] = 8;
			*(uint32_t*)&v4[2] = v3;
			*(uint32_t*)&v4[6] = v2;
			nox_xxx_netSendPacket1_4E5390(159, (int)v4, 10, 0, 1);
		}
	}
}

//----- (004190F0) --------------------------------------------------------
int sub_4190F0(wchar2_t* a1) {
	char* v1; // esi

	v1 = nox_server_teamFirst_418B10();
	if (!v1) {
		return 0;
	}
	while (_nox_wcsicmp((const wchar2_t*)v1, a1)) {
		v1 = nox_server_teamNext_418B60((int)v1);
		if (!v1) {
			return 0;
		}
	}
	return 1;
}

//----- (00419130) --------------------------------------------------------
int nox_xxx_servObjectHasTeam_419130(int a1) {
	int result; // eax

	result = a1;
	if (a1) {
		result = *(uint8_t*)(a1 + 4) != 0;
	}
	return result;
}

//----- (00419150) --------------------------------------------------------
int nox_xxx_servCompareTeams_419150(int a1, int a2) {
	char v2;    // cl
	char v3;    // al
	int result; // eax

	result = 0;
	if (a1) {
		if (a2) {
			v2 = *(uint8_t*)(a1 + 4);
			if (v2) {
				v3 = *(uint8_t*)(a2 + 4);
				if (v3) {
					if (v2 == v3) {
						result = 1;
					}
				}
			}
		}
	}
	return result;
}

//----- (00419180) --------------------------------------------------------
int nox_xxx_teamCompare2_419180(void* a1p, unsigned char a2) {
	int a1 = a1p;
	char* v2;     // eax
	uint32_t* v3; // eax

	if (!a1) {
		return 0;
	}
	if (*(uint8_t*)(a1 + 4) != a2) {
		return 0;
	}
	v2 = nox_xxx_clientGetTeamColor_418AB0(a2);
	if (!v2) {
		return 0;
	}
	v3 = (uint32_t*)nox_xxx_teamCheckSmth_418C60((int)v2);
	if (!v3) {
		return 0;
	}
	while (v3 != (uint32_t*)a1) {
		v3 = sub_418C70(v3);
		if (!v3) {
			return 0;
		}
	}
	return 1;
}

//----- (00419570) --------------------------------------------------------
void nox_xxx_netChangeTeamMb_419570(void* a1p, int a2) {
	int a1 = a1p;
	char* v2;   // esi
	char* v3;   // ebx
	char v4[6]; // [esp+8h] [ebp-8h]

	if (a1) {
		v2 = nox_xxx_clientGetTeamColor_418AB0(*(unsigned char*)(a1 + 4));
		if (v2) {
			if (nox_xxx_teamCompare2_419180(a1, *(uint8_t*)(a1 + 4))) {
				if (nox_common_gameFlags_check_40A5C0(1) && nox_common_gameFlags_check_40A5C0(0x2000)) {
					v3 = nox_common_playerInfoGetByID_417040(a2);
					if (v3 && 0 && !nox_common_gameFlags_check_40A5C0(128)) {
						sub_425ED0((int)v3, 0);
					}
					sub_4571A0(a2, 0);
					v4[0] = -60;
					v4[1] = 2;
					*(uint32_t*)&v4[2] = a2;
					nox_xxx_netSendPacket1_4E5390(159, (int)v4, 6, 0, 1);
				}
				sub_418E40((int)v2, a1);
				--*((uint32_t*)v2 + 12);
				if ((sub_40A740() || nox_common_gameFlags_check_40A5C0(0x8000)) && !sub_418BC0((int)v2)) {
					if (nox_common_gameFlags_check_40A5C0(96) ||
						nox_common_gameFlags_check_40A5C0(16) && nox_xxx_CheckGameplayFlags_417DA0(4)) {
						*((uint32_t*)v2 + 15) = 0;
						sub_418800((wchar2_t*)v2, (wchar2_t*)getMemAt(0x5D4594, 527664), 0);
					} else {
						sub_418F20((wchar2_t*)v2, 1);
					}
				}
			}
		}
	}
}

//----- (004196D0) --------------------------------------------------------
int sub_4196D0(void* a1p, void* a2p, int a3, int a4) {
	int a1 = a1p;
	int a2 = a2p;
	int v4;      // ecx
	char* v5;    // eax
	char v7[10]; // [esp+8h] [ebp-Ch]

	if (!a1 || !a2 || !nox_xxx_teamCompare2_419180(a1, *(uint8_t*)(a1 + 4))) {
		return 0;
	}
	nox_common_playerInfoGetByID_417040(a3);
	if (nox_common_gameFlags_check_40A5C0(1) && nox_common_gameFlags_check_40A5C0(0x2000)) {
		v4 = *(unsigned char*)(a2 + 57);
		v7[0] = -60;
		v7[1] = 3;
		*(uint32_t*)&v7[2] = v4;
		*(uint16_t*)&v7[6] = a3;
		nox_xxx_netSendPacket1_4E5390(159, (int)v7, 10, 0, 1);
		sub_4571A0(a3, *(unsigned char*)(a2 + 57));
	}
	v5 = nox_xxx_clientGetTeamColor_418AB0(*(unsigned char*)(a1 + 4));
	--*((uint32_t*)v5 + 12);
	sub_418E40((int)v5, a1);
	nox_xxx_createAtImpl_4191D0(*(uint8_t*)(a2 + 57), a1, 0, a3, a4);
	if (a3 == nox_player_netCode_85319C) {
		sub_455E70(*(uint8_t*)(a2 + 57));
	}
	return 1;
}

//----- (004197C0) --------------------------------------------------------
void sub_4197C0(wchar2_t* a1, int a2) {
	int v2;       // edi
	uint32_t* v3; // ebp
	char v4[18];  // [esp+4h] [ebp-14h]

	if (a1) {
		*(uint32_t*)&v4[6] = *((uint32_t*)a1 + 15);
		*(uint32_t*)&v4[2] = *((unsigned char*)a1 + 57);
		*(uint16_t*)v4 = 196;
		*(uint32_t*)&v4[10] = *((uint32_t*)a1 + 13);
		v4[14] = 0;
		v4[16] = *((uint8_t*)a1 + 56);
		v4[17] = *((uint8_t*)a1 + 68);
		if (nox_common_gameFlags_check_40A5C0(512)) {
			v4[14] = 1;
		}
		v4[15] = nox_wcslen(a1);
		v2 = 2 * (unsigned char)v4[15];
		v3 = calloc(1, v2 + 18);
		*(uint64_t*)v3 = *(uint64_t*)v4;
		v3[2] = *(uint32_t*)&v4[8];
		v3[3] = *(uint32_t*)&v4[12];
		*((uint16_t*)v3 + 8) = *(uint16_t*)&v4[16];
		memcpy((char*)v3 + 18, a1, 2 * (unsigned char)v4[15]);
		nox_xxx_netSendPacket1_4E5390(a2, (int)v3, v2 + 18, 0, 1);
		free(v3);
	}
}

//----- (004198A0) --------------------------------------------------------
void sub_4198A0(int a1, int a2, int a3) {
	int v3;      // eax
	int v4;      // ecx
	char v5[10]; // [esp+8h] [ebp-Ch]

	if (a1) {
		v3 = nox_server_getObjectFromNetCode_4ECCB0(a3);
		if (v3) {
			v5[0] = -60;
			v4 = *(unsigned char*)(a1 + 4);
			v5[1] = 1;
			*(uint16_t*)&v5[6] = a3;
			*(uint32_t*)&v5[2] = v4;
			*(uint16_t*)&v5[8] = *(uint16_t*)(v3 + 4);
			nox_xxx_netSendPacket1_4E5390(a2, (int)v5, 10, 0, 1);
		}
	}
}

//----- (00419900) --------------------------------------------------------
char sub_419900(int a1, int a2, short a3) {
	char result; // al
	char v4[10]; // [esp+0h] [ebp-Ch]

	result = a1;
	if (a1 && a2) {
		result = *(uint8_t*)(a1 + 57);
		if (*(uint8_t*)(a2 + 4) != result) {
			*(uint32_t*)&v4[2] = *(unsigned char*)(a1 + 57);
			v4[0] = -60;
			v4[1] = 10;
			*(uint16_t*)&v4[6] = a3;
			result = nox_xxx_netClientSend2_4E53C0(31, v4, 10, 0, 1);
		}
	}
	return result;
}

//----- (00419960) --------------------------------------------------------
char sub_419960(int a1, int a2, short a3) {
	char result; // al
	char v4[10]; // [esp+0h] [ebp-Ch]

	result = a1;
	if (a1 && a2) {
		result = *(uint8_t*)(a1 + 57);
		if (*(uint8_t*)(a2 + 4) != result) {
			*(uint32_t*)&v4[2] = *(unsigned char*)(a1 + 57);
			v4[0] = -60;
			v4[1] = 11;
			*(uint16_t*)&v4[6] = a3;
			result = nox_xxx_netClientSend2_4E53C0(31, v4, 10, 0, 1);
		}
	}
	return result;
}

//----- (00419A10) --------------------------------------------------------
double sub_419A10(float a1) {
	*getMemFloatPtr(0x5D4594, 527672) = a1;
	**(uint32_t**)getMemAt(0x587000, 55744) &= 0x7FFFFFFFu;
	return *getMemFloatPtr(0x5D4594, 527672);
}

//----- (00419A30) --------------------------------------------------------
unsigned int sub_419A30(float a1) {
	unsigned int result; // eax

	if (a1 < 0.0) {
		return 0;
	}
	*getMemU32Ptr(0x5D4594, 527668) = getMemAt(0x5D4594, 527676);
	*getMemFloatPtr(0x5D4594, 527676) = a1 + 8388608.0;
	result = 0x7fffff & *getMemU32Ptr(0x5D4594, 527676);
	*getMemU32Ptr(0x5D4594, 527680) = 0x7fffff & *getMemU32Ptr(0x5D4594, 527676);
	return result;
}

//----- (00419A70) --------------------------------------------------------
int nox_float2int(float a1) { return (int)a1; }

//----- (00419A90) --------------------------------------------------------
short nox_float2int16(float a1) { return (int)a1; }

//----- (00419AB0) --------------------------------------------------------
short nox_float2int16_abs(float a1) { return (int)fabs(a1); }

//----- (00419AF0) --------------------------------------------------------
float nox_double2float(double a1) { return (float)a1; }

//----- (00419B10) --------------------------------------------------------
int nox_double2int(double a1) { return (int)a1; }

//----- (00419E10) --------------------------------------------------------
int sub_419E10(int a1, int a2) {
	int result; // eax

	result = a1;
	if (a1 && !(*(uint8_t*)(a1 + 16) & 0x20)) {
		result = 1 << *(uint8_t*)(*(uint32_t*)(*(uint32_t*)(a1 + 748) + 276) + 2064);
		if (a2) {
			dword_5d4594_527712 |= result;
		} else {
			result = ~result;
			dword_5d4594_527712 &= result;
		}
	}
	return result;
}

//----- (00419E60) --------------------------------------------------------
int sub_419E60(nox_object_t* a1p) {
	int a1 = a1p;
	int result; // eax

	if (a1 && *(uint8_t*)(a1 + 8) & 4) {
		result = (dword_5d4594_527712 & (1 << *(uint8_t*)(*(uint32_t*)(*(uint32_t*)(a1 + 748) + 276) + 2064))) != 0;
	} else {
		result = 0;
	}
	return result;
}

//----- (00419EA0) --------------------------------------------------------
int sub_419EA0() { return dword_5d4594_527712 != 0; }

//----- (0041A000) --------------------------------------------------------
int sub_41A000(char* a1, nox_savegame_xxx* sv) {
	int result;        // eax
	int v3;            // ecx
	unsigned char* v4; // eax
	int v5;            // edx
	unsigned int v6;   // ecx
	char v7;           // al
	uint8_t* v8;       // edi
	char* v9;          // esi
	int v10;           // [esp+10h] [ebp-508h]
	int v11;           // [esp+14h] [ebp-504h]
	char v12[1276];    // [esp+18h] [ebp-500h]
	short v13;         // [esp+514h] [ebp-4h]

	sv->field_1028[0] = getMemByte(0x5D4594, 527728);
	result = nox_xxx_cryptOpen_426910(a1, 1, 27);
	if (!result) {
		return 0;
	}
	while (1) {
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v10, 4u);
		if (!v10) {
			break;
		}
		nox_xxx_fileCryptReadCrcMB_426C20(&v11, 4u);
		if (v10 == 1) {
			memcpy(v12, getMemAt(0x85B3FC, 10980), sizeof(v12));
			v3 = 0;
			v13 = *getMemU16Ptr(0x85B3FC, 12256);
			if (*getMemU32Ptr(0x587000, 55936)) {
				v4 = getMemAt(0x587000, 55936);
				while (v4 != getMemAt(0x587000, 55948)) {
					v5 = *((uint32_t*)v4 + 3);
					v4 += 12;
					++v3;
					if (!v5) {
						goto LABEL_10;
					}
				}
				if (!(*(int (**)(uint32_t))getMemAt(0x587000, 55956))(0)) {
					nox_xxx_cryptClose_4269F0();
					return 0;
				}
			}
		LABEL_10:
			memcpy(sv, getMemAt(0x85B3FC, 10980), sizeof(nox_savegame_xxx));
			memcpy(getMemAt(0x85B3FC, 10980), v12, 0x4FCu);
			*getMemU16Ptr(0x85B3FC, 12256) = v13;
		} else {
			nox_xxx_cryptSeekCur_40E0A0(v11);
		}
	}
	nox_xxx_cryptClose_4269F0();
	v6 = strlen(a1) + 1;
	v7 = v6;
	v6 >>= 2;
	memcpy(&sv->path, a1, 4 * v6);
	v9 = &a1[4 * v6];
	v8 = &sv->path[4 * v6];
	LOBYTE(v6) = v7;
	memcpy(v8, v9, v6 & 3);
	return 1;
}

//----- (0041A140) --------------------------------------------------------
int nox_xxx_playerSaveToFile_41A140(char* a1, int a2) {
	int result;        // eax
	int v3;            // ebp
	int v4;            // ebx
	unsigned char* v5; // esi
	int v7;            // edi
	int v9;            // eax
	int v10;           // [esp+18h] [ebp+8h]

	result = nox_common_playerInfoFromNum_417090(a2);
	if (!result) {
		return 0;
	}
	v3 = *(uint32_t*)(result + 2056);
	if (!v3) {
		nox_xxx_networkLog_printf_413D30("SaveServerPlayerData: NULL player object\n");
		return 0;
	}
	v4 = result + 2185;
	if (!nox_xxx_cryptOpen_426910(a1, 0, 27)) {
		nox_xxx_networkLog_printf_413D30("SavePlayerData: Can't open file '%s'\n", a1);
		return 0;
	}
	v10 = 0;
	if (!*getMemU32Ptr(0x587000, 55816)) {
		nox_xxx_cryptClose_4269F0();
		return 1;
	}
	v5 = getMemAt(0x587000, 55824);
	while (1) {
		nox_xxx_fileReadWrite_426AC0_file3_fread(v5 - 4, 4u);
		nox_xxx_crypt_426C90();
		v7 = (*(int (**)(int, int, uint32_t, uint32_t))v5)(v3, v4, 0, 0);
		nox_xxx_crypt_426D40();
		if (!v7) {
			break;
		}
		v9 = *((uint32_t*)v5 + 1);
		v5 += 12;
		++v10;
		if (!v9) {
			nox_xxx_cryptClose_4269F0();
			return 1;
		}
	}
	nox_xxx_networkLog_printf_413D30("SavePlayerData: Error saving player data '%s'\n",
									 *getMemU32Ptr(0x587000, 55816 + 12 * v10));
	nox_xxx_cryptClose_4269F0();
	return 0;
}
// 41A1C9: variable 'v6' is possibly undefined
// 41A1DB: variable 'v8' is possibly undefined

//----- (0041A230) --------------------------------------------------------
int nox_xxx_mapSavePlayerDataMB_41A230(char* a1) {
	char* v1;          // edi
	unsigned char* v3; // esi
	int v5;            // edi
	int v7;            // eax

	v1 = a1;
	if (!nox_xxx_cryptOpen_426910(a1, 2, 27)) {
		return 0;
	}
	if (sub_45D9B0()) {
		sub_45D870();
	}
	if ((char*)getMemAt(0x85B3FC, 10984) != v1) { // FIXME: strcpy overlap
		strcpy((char*)getMemAt(0x85B3FC, 10984), v1);
	}
	if (*getMemU32Ptr(0x587000, 55936)) {
		v3 = getMemAt(0x587000, 55944);
		while (1) {
			nox_xxx_fileReadWrite_426AC0_file3_fread(v3 - 4, 4u);
			nox_xxx_crypt_426C90();
			v5 = (*(int (**)(uint32_t))v3)(0);
			nox_xxx_crypt_426D40();
			if (!v5) {
				nox_xxx_cryptClose_4269F0();
				return 0;
			}
			v7 = *((uint32_t*)v3 + 1);
			v3 += 12;
			if (!v7) {
				break;
			}
		}
	}
	a1 = 0;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 4u);
	nox_xxx_cryptClose_4269F0();
	return 1;
}
// 41A291: variable 'v4' is possibly undefined
// 41A29F: variable 'v6' is possibly undefined

//----- (0041A2E0) --------------------------------------------------------
int nox_xxx_cliPlrInfoLoadFromFile_41A2E0(char* a1, int a2) {
	char* result;       // eax
	int v3;             // esi
	char* v4;           // edi
	int v5;             // ecx
	unsigned char* v6;  // eax
	int v7;             // ebx
	int v8;             // eax
	int v9;             // edi
	unsigned short v10; // ax
	unsigned short v11; // ax

	result = nox_common_playerInfoFromNum_417090(a2);
	if (!result) {
		return 0;
	}
	v3 = *((uint32_t*)result + 514);
	if (!v3) {
		return 0;
	}
	v4 = result + 2185;
	result = (char*)nox_xxx_cryptOpen_426910(a1, 1, 27);
	if (!result) {
		return 0;
	}
	if (nox_common_gameFlags_check_40A5C0(2048)) {
		nox_xxx_set_god_4EF500(0);
	}
	*getMemU16Ptr(0x5D4594, 527696) = nox_xxx_unitGetHP_4EE780(v3);
	*getMemU32Ptr(0x5D4594, 527696) = *getMemU16Ptr(0x5D4594, 527696);
	*getMemU16Ptr(0x5D4594, 527700) = nox_xxx_unitGetOldMana_4EEC80(v3);
	*getMemU32Ptr(0x5D4594, 527700) = *getMemU16Ptr(0x5D4594, 527700);
	sub_4EFF10(v3);
	sub_419E10(v3, 1);
	do {
		while (1) {
			nox_xxx_fileReadWrite_426AC0_file3_fread(&a2, 4u);
			if (!a2) {
				nox_xxx_cryptClose_4269F0();
				sub_4EF140(v3);
				v10 = nox_xxx_unitGetMaxHP_4EE7A0(v3);
				nox_xxx_unitDamageClear_4EE5E0(v3, v10 - *getMemU32Ptr(0x5D4594, 527696));
				v11 = nox_xxx_playerGetMaxMana_4EECB0(v3);
				nox_xxx_playerManaSub_4EEBF0(v3, v11 - *getMemU32Ptr(0x5D4594, 527700));
				nox_xxx_playerHP_4EE730(v3);
				sub_419E10(v3, 0);
				return 1;
			}
			nox_xxx_fileCryptReadCrcMB_426C20(&a1, 4u);
			v5 = 0;
			if (!*getMemU32Ptr(0x587000, 55816)) {
				nox_xxx_cryptSeekCur_40E0A0((int)a1);
				continue;
			}
			v6 = getMemAt(0x587000, 55816);
			while (1) {
				if (a2 == *((uint32_t*)v6 + 1)) {
					goto LABEL_13_1;
				}
				v7 = *((uint32_t*)v6 + 3);
				v6 += 12;
				++v5;
				if (!v7) {
					nox_xxx_cryptSeekCur_40E0A0((int)a1);
					break;
				}
			}
		}
	LABEL_13_1:;
	} while ((*(int (**)(int, int))getMemAt(0x587000, 55824 + 12 * v5))(v3, (int)v4));
	v8 = *(uint32_t*)(v3 + 504);
	if (v8) {
		do {
			v9 = *(uint32_t*)(v8 + 496);
			nox_xxx_delayedDeleteObject_4E5CC0(v8);
			v8 = v9;
		} while (v9);
	}
	sub_419E10(v3, 0);
	nox_xxx_cryptClose_4269F0();
	return 0;
}

//----- (0041A480) --------------------------------------------------------
int nox_xxx_plrLoad_41A480(char* a1) {
	int v2;            // ecx
	unsigned char* v3; // eax
	int v4;            // esi
	int v5;            // [esp+Ch] [ebp-408h]
	int v6;            // [esp+10h] [ebp-404h]
	char v7[1024];     // [esp+14h] [ebp-400h]

	strcpy(v7, a1);
	if (!nox_xxx_cryptOpen_426910(a1, 1, 27)) {
		return 0;
	}
	sub_4602F0();
	while (1) {
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v5, 4u);
		if (!v5) {
			break;
		}
		nox_xxx_fileCryptReadCrcMB_426C20(&v6, 4u);
		v2 = 0;
		if (!*getMemU32Ptr(0x587000, 55936)) {
			nox_xxx_cryptSeekCur_40E0A0(v6);
			continue;
		}
		v3 = getMemAt(0x587000, 55936);
		while (1) {
			if (v5 == *((uint32_t*)v3 + 1)) {
				if (!(*(int (**)(void*))getMemAt(0x587000, 55944 + 12 * v2))(0)) {
					nox_xxx_cryptClose_4269F0();
					return 0;
				}
				break;
			}
			v4 = *((uint32_t*)v3 + 3);
			v3 += 12;
			++v2;
			if (!v4) {
				nox_xxx_cryptSeekCur_40E0A0(v6);
				break;
			}
		}
	}
	nox_xxx_cryptClose_4269F0();
	strcpy((char*)getMemAt(0x85B3FC, 10984), v7);
	return 1;
}

//----- (0041A590) --------------------------------------------------------
int sub_41A590(int a1, int a2) {
	int v2;    // esi
	int v3;    // edi
	int v4;    // ebx
	size_t v6; // eax
	int v7;    // eax
	int v8;    // ebx
	char* v9;  // eax
	int v10;   // eax
	int v11;   // esi
	float v12; // [esp+0h] [ebp-20h]
	int v13;   // [esp+14h] [ebp-Ch]
	int v14;   // [esp+18h] [ebp-8h]
	int v15;   // [esp+1Ch] [ebp-4h]

	v2 = a2;
	v3 = 0;
	v4 = 0;
	v15 = 0;
	if (!a2) {
		return 0;
	}
	if (a1) {
		v3 = *(uint32_t*)(a1 + 748);
		if (v3) {
			v15 = *(uint32_t*)(v3 + 276);
			v4 = v15;
		}
	}
	a2 = 5;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&a2, 2u);
	if ((short)a2 > 5) {
		return 0;
	}
	if ((short)a2 >= 5) {
		v13 = nox_common_gameFlags_check_40A5C0(4096) ? 4 : 2 - nox_common_gameFlags_check_40A5C0(2048);
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v13, 4u);
		if (v4) {
			if (*(uint8_t*)(v4 + 2064) != 31) {
				if (nox_common_gameFlags_check_40A5C0(4096)) {
					if (v13 != 4) {
						nox_xxx_playerCallDisconnect_4DEAB0(*(unsigned char*)(v4 + 2064), 1);
						return 0;
					}
				} else if (v13 != 4) {
					goto LABEL_20;
				}
				if (!nox_common_gameFlags_check_40A5C0(4096)) {
					nox_xxx_playerCallDisconnect_4DEAB0(*(unsigned char*)(v4 + 2064), 1);
					return 0;
				}
			}
		}
	}
LABEL_20:
	LOBYTE(v14) = nox_wcslen((const wchar2_t*)v2);
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v14, 1u);
	if ((unsigned char)v14 >= 0x19u) {
		return 0;
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)v2, 2 * (unsigned char)v14);
	*(uint16_t*)(v2 + 2 * (unsigned char)v14) = 0;
	if (v3) {
		nox_wcscpy((wchar2_t*)(*(uint32_t*)(v3 + 276) + 4704), (const wchar2_t*)v2);
	}
	if (nox_crypt_IsReadOnly() == 1 && v3) {
		v6 = nox_wcslen((const wchar2_t*)v2);
		v7 = nox_xxx_protectionStringCRCLen_56FAE0((int*)v2, 2 * v6);
		nox_xxx_playerResetProtectionCRC_56F7D0(*(uint32_t*)(*(uint32_t*)(v3 + 276) + 4628), v7);
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(v2 + 50), 4u);
	nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(v2 + 54), 4u);
	if (nox_crypt_IsReadOnly() == 1 && v3) {
		sub_56F780(*(uint32_t*)(*(uint32_t*)(v3 + 276) + 4624), *(uint32_t*)(v2 + 54));
		sub_56F780(*(uint32_t*)(*(uint32_t*)(v3 + 276) + 4620), *(uint32_t*)(v2 + 50));
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(v2 + 58), 4u);
	nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(v2 + 62), 4u);
	nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(v2 + 66), 1u);
	if (nox_crypt_IsReadOnly() == 1 && v3) {
		sub_56F820(*(uint32_t*)(*(uint32_t*)(v3 + 276) + 4616), *(uint8_t*)(v2 + 66));
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(v2 + 67), 1u);
	nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(v2 + 68), 3u);
	nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(v2 + 71), 3u);
	nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(v2 + 74), 3u);
	nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(v2 + 77), 3u);
	nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(v2 + 80), 3u);
	if ((short)a2 >= 2) {
		nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(v2 + 83), 1u);
		nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(v2 + 84), 1u);
		nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(v2 + 85), 1u);
		nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(v2 + 86), 1u);
		nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(v2 + 87), 1u);
	}
	v8 = a1;
	if (nox_crypt_IsReadOnly() == 1) {
		if (a1) {
			v9 = nox_common_playerInfoGetByID_417040(*(uint32_t*)(a1 + 36));
			if (v9) {
				nox_xxx_playerInitColors_461460((int)v9);
			}
		}
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(v2 + 88), 1u);
	if ((short)a2 >= 3) {
		v13 = 0;
		if (v3) {
			v13 = *(uint32_t*)(v3 + 320);
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v13, 4u);
		if (nox_crypt_IsReadOnly() == 1 && v3) {
			*(uint32_t*)(v3 + 320) = v13;
		}
		v12 = nox_xxx_gamedataGetFloat_419D40("MaxExtraLives");
		v10 = nox_float2int(v12);
		if (v3 && *(uint32_t*)(v3 + 320) > v10) {
			return 0;
		}
		if ((uint16_t)a2 == 3) {
			nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 4u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 4u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 4u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 4u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 4u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 4u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 4u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 4u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 4u);
		}
	}
	if (nox_crypt_IsReadOnly() == 1) {
		sub_4D6000(v8);
	}
	if ((short)a2 >= 4) {
		v11 = v15;
		a1 = 0;
		if (v15) {
			a1 = *(uint32_t*)(v15 + 4696);
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 4u);
		if (nox_crypt_IsReadOnly() == 1) {
			if (!v11 || (*(uint32_t*)(v11 + 4696) = a1, nox_crypt_IsReadOnly() == 1)) {
				if (v3) {
					sub_4D7450(*(unsigned char*)(*(uint32_t*)(v3 + 276) + 2064),
							   *(uint32_t*)(*(uint32_t*)(v3 + 276) + 4696));
				}
			}
		}
	}
	return 1;
}

//----- (0041AA30) --------------------------------------------------------
char* sub_41AA30(int a1) {
	int v1;       // esi
	int v2;       // ebp
	char* result; // eax
	int v4;       // eax
	int v5;       // eax
	int v6;       // [esp+10h] [ebp-Ch]
	int v7;       // [esp+14h] [ebp-8h]
	int v8;       // [esp+18h] [ebp-4h]

	v1 = a1;
	v2 = *(uint32_t*)(a1 + 748);
	result = nox_common_playerInfoGetByID_417040(*(uint32_t*)(a1 + 36));
	LOBYTE(a1) = 1;
	if (result) {
		v7 = 2;
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v7, 2u);
		if ((short)v7 > 2) {
			return 0;
		}
		if (!nox_common_gameFlags_check_40A5C0(2048)) {
			LOBYTE(a1) = 0;
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 1u);
		if ((uint8_t)a1) {
			result = (char*)nox_common_gameFlags_check_40A5C0(2048);
			if (!result) {
				return result;
			}
			LOWORD(v4) = nox_xxx_unitGetMaxHP_4EE7A0(v1);
			v6 = v4;
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v6, 2u);
			if (nox_crypt_IsReadOnly() == 1) {
				nox_xxx_unitSetMaxHP_4EE7C0(v1, v6);
				nox_xxx_unitSetHP_4E4560(v1, v6);
			}
			LOWORD(v5) = nox_xxx_playerGetMaxMana_4EECB0(v1);
			v6 = v5;
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v6, 2u);
			if (nox_crypt_IsReadOnly() == 1) {
				nox_xxx_playerSetMaxMana_4EECD0(v1, v6);
				nox_xxx_playerManaRefresh_4EECF0(v1);
			}
			*getMemU32Ptr(0x5D4594, 527696) = **(unsigned short**)(v1 + 556);
			nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x5D4594, 527696), 2u);
			*getMemU32Ptr(0x5D4594, 527700) = *(unsigned short*)(v2 + 4);
			nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x5D4594, 527700), 2u);
			LOBYTE(v8) = *(uint8_t*)(v1 + 540);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v8, 1u);
			if (nox_crypt_IsReadOnly() == 1) {
				nox_xxx_setSomePoisonData_4EEA90(v1, (unsigned char)v8);
			}
			nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(v1 + 541), 1u);
			nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(v1 + 542), 2u);
			nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(v1 + 28), 4u);
			if (nox_crypt_IsReadOnly() == 1) {
				sub_56F8C0(*(uint32_t*)(*(uint32_t*)(v2 + 276) + 4604), *(float*)(v1 + 28));
				sub_4D81A0(v1);
			}
			if ((short)v7 >= 2) {
				nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(v1 + 124), 2u);
				if (nox_crypt_IsReadOnly() == 1) {
					*(uint16_t*)(v1 + 126) = *(uint16_t*)(v1 + 124);
				}
			}
		}
		result = (char*)1;
	}
	return result;
}
// 41AAD8: variable 'v4' is possibly undefined
// 41AB12: variable 'v5' is possibly undefined

//----- (0041AC30) --------------------------------------------------------
int sub_41AC30(uint32_t* a1) {
	uint32_t* v1;  // ebp
	int result;    // eax
	int v3;        // eax
	int v4;        // esi
	int v5;        // edi
	int v6;        // edi
	int v7;        // esi
	int v8;        // ebp
	char* v9;      // eax
	int v10;       // ebx
	int* v11;      // ebp
	int v12;       // eax
	int v13;       // esi
	uint8_t* v14;  // eax
	int v15;       // esi
	uint8_t* v16;  // eax
	int v17;       // eax
	int m;         // esi
	int v19;       // eax
	int v20;       // eax
	int v21;       // eax
	int v22;       // esi
	int v23;       // ebx
	uint32_t* v24; // eax
	uint32_t* v25; // esi
	int v26;       // eax
	int v27;       // edi
	int i;         // esi
	uint32_t* v29; // eax
	uint32_t* v30; // eax
	uint32_t* j;   // eax
	uint8_t* v32;  // esi
	size_t v33;    // [esp-4h] [ebp-13Ch]
	size_t v34;    // [esp-4h] [ebp-13Ch]
	char l;        // [esp+12h] [ebp-126h]
	char v36;      // [esp+13h] [ebp-125h]
	int v37;       // [esp+14h] [ebp-124h]
	int k;         // [esp+18h] [ebp-120h]
	int v39;       // [esp+1Ch] [ebp-11Ch]
	int v40;       // [esp+20h] [ebp-118h]
	int v41;       // [esp+24h] [ebp-114h]
	int v42;       // [esp+28h] [ebp-110h]
	int v43;       // [esp+2Ch] [ebp-10Ch]
	int v44;       // [esp+30h] [ebp-108h]
	int v45;       // [esp+34h] [ebp-104h]
	char v46[256]; // [esp+38h] [ebp-100h]

	v1 = a1;
	v36 = 1;
	v40 = a1[187];
	if (!*getMemU32Ptr(0x5D4594, 527704)) {
		*getMemU32Ptr(0x5D4594, 527704) = nox_xxx_getNameId_4E3AA0("Glyph");
	}
	if (nox_crypt_IsReadOnly() == 1) {
		sub_4EF140((int)a1);
	}
	v42 = 3;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v42, 2u);
	if ((short)v42 > 3) {
		return 0;
	}
	if (nox_common_gameFlags_check_40A5C0(0x2000) && !nox_common_gameFlags_check_40A5C0(4096)) {
		v36 = 0;
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v36, 1u);
	if (!v36) {
		goto LABEL_115;
	}
	if (!nox_common_gameFlags_check_40A5C0(2048)) {
		result = nox_common_gameFlags_check_40A5C0(4096);
		if (!result) {
			return 0;
		}
	}
	v44 = *(uint32_t*)(*(uint32_t*)(v40 + 276) + 2164);
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v44, 4u);
	if (nox_crypt_IsReadOnly() == 1) {
		v3 = nox_xxx_playerGetGold_4FA6B0((int)a1);
		nox_xxx_playerSubGold_4FA5D0((int)a1, v3);
		nox_xxx_playerAddGold_4FA590((int)a1, v44);
	}
	if (nox_crypt_IsReadOnly()) {
		v21 = a1[126];
		if (v21) {
			do {
				v22 = *(uint32_t*)(v21 + 496);
				nox_xxx_delayedDeleteObject_4E5CC0(v21);
				v21 = v22;
			} while (v22);
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread(&k, 4u);
		if (nox_common_gameFlags_check_40A5C0(4096) && k > 2560) {
			return 0;
		}
		v23 = 0;
		if (k > 0) {
			do {
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v39, 1u);
				nox_xxx_fileReadWrite_426AC0_file3_fread(v46, (unsigned char)v39);
				v46[(unsigned char)v39] = 0;
				v24 = nox_xxx_newObjectByTypeID_4E3810(v46);
				v25 = v24;
				if (!v24) {
					return 0;
				}
				if (!((int (*)(uint32_t*, uint32_t))v24[176])(v24, 0)) {
					return 0;
				}
				v25[14] = 1161297920;
				v25[15] = 1161297920;
				if (nox_common_gameFlags_check_40A5C0(4096)) {
					if (!sub_4F2590((int)v25)) {
						return 0;
					}
				}
				nox_xxx_servMapLoadPlaceObj_4F3F50((int)v25, (int)a1, 0);
				nox_xxx_unitsNewAddToList_4DAC00();
				if (!nox_xxx_inventoryServPlace_4F36F0((int)a1, (int)v25, 1, 1)) {
					if (!nox_common_gameFlags_check_40A5C0(4096)) {
						return 0;
					}
					nox_xxx_delayedDeleteObject_4E5CC0((int)v25);
				}
				v26 = v25[4];
				if (!(v26 & 0x20) && v26 & 0x100) {
					nox_xxx_playerTryDequip_4F2FB0(a1, (nox_object_t*)v25);
				}
			} while (++v23 < k);
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v41, 1u);
		v27 = 0;
		if ((uint8_t)v41) {
			do {
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v37, 4u);
				for (i = a1[126]; i; i = *(uint32_t*)(i + 496)) {
					if (*(uint32_t*)(i + 44) == v37) {
						nox_xxx_playerTryEquip_4F2F70(a1, i);
					}
				}
				++v27;
			} while (v27 < (unsigned char)v41);
		}
		if (nox_common_gameFlags_check_40A5C0(2048)) {
			sub_467750(0, 0);
			sub_467740(0);
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v37, 4u);
		if (v37) {
			v29 = (uint32_t*)a1[126];
			if (v29) {
				while (1) {
					if (v29[11] == v37) {
						nox_xxx_netSendSecondaryWeapon_4D9670(*(unsigned char*)(*(uint32_t*)(v40 + 276) + 2064), v29, 0);
						break;
					}
					v29 = (uint32_t*)v29[124];
					if (!v29) {
						break;
					}
				}
			}
		}
		if ((short)v42 >= 2) {
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v37, 4u);
			if (v37) {
				v30 = (uint32_t*)a1[126];
				if (v30) {
					while (1) {
						if (v30[11] == v37) {
							nox_xxx_netMsgLastQuiver_4D96B0(*(unsigned char*)(*(uint32_t*)(v40 + 276) + 2064), v30);
							break;
						}
						v30 = (uint32_t*)v30[124];
						if (!v30) {
							break;
						}
					}
				}
			}
		}
		if (nox_common_gameFlags_check_40A5C0(4096)) {
			for (j = (uint32_t*)nox_xxx_inventoryGetFirst_4E7980((int)a1); j;
				 j = (uint32_t*)nox_xxx_inventoryGetNext_4E7990((int)j)) {
				j[11] = nox_server_NextObjectScriptID();
				j[10] = j[9];
			}
		}
		goto LABEL_109;
	}
	v4 = a1[126];
	v5 = 0;
	for (k = 0; v4; v4 = *(uint32_t*)(v4 + 496)) {
		if (!nox_common_gameFlags_check_40A5C0(4096) || sub_41B3E0(v4)) {
			++k;
		}
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread(&k, 4u);
	if (nox_common_gameFlags_check_40A5C0(2048)) {
		v5 = sub_41B3B0();
	}
	if (k != v5 || !nox_common_gameFlags_check_40A5C0(2048)) {
		v15 = a1[126];
		if (v15) {
			while (1) {
				if (!nox_common_gameFlags_check_40A5C0(4096) || sub_41B3E0(v15)) {
					LOBYTE(v39) = strlen((const char*)nox_xxx_getUnitName_4E39D0(v15));
					nox_xxx_fileReadWrite_426AC0_file3_fread(&v39, 1u);
					v34 = (unsigned char)v39;
					v16 = (uint8_t*)nox_xxx_getUnitName_4E39D0(v15);
					nox_xxx_fileReadWrite_426AC0_file3_fread(v16, v34);
					if (!(*(int (**)(int, uint32_t))(v15 + 704))(v15, 0)) {
						return 0;
					}
				}
				v15 = *(uint32_t*)(v15 + 496);
				if (!v15) {
					v1 = a1;
					break;
				}
			}
		}
	} else {
		v6 = 0;
		v41 = 0;
		while (1) {
			v7 = 0;
			v43 = 0;
			do {
				v8 = sub_467810(v7, v6);
				v45 = v8;
				if (v8) {
					v9 = sub_467870(v7, v6);
					v10 = 0;
					if (v8 > 0) {
						v11 = (int*)v9;
						while (1) {
							v12 = nox_xxx_equipedItemByCode_4F7920((int)a1, *v11);
							v13 = v12;
							if (!v12) {
								return 0;
							}
							LOBYTE(v39) = strlen((const char*)nox_xxx_getUnitName_4E39D0(v12));
							nox_xxx_fileReadWrite_426AC0_file3_fread(&v39, 1u);
							v33 = (unsigned char)v39;
							v14 = (uint8_t*)nox_xxx_getUnitName_4E39D0(v13);
							nox_xxx_fileReadWrite_426AC0_file3_fread(v14, v33);
							if (!(*(int (**)(int, uint32_t))(v13 + 704))(v13, 0)) {
								return 0;
							}
							++v10;
							++v11;
							if (v10 >= v45) {
								v6 = v41;
								v7 = v43;
								break;
							}
						}
					}
				}
				++v7;
				v43 = v7;
			} while (v7 < 4);
			++v6;
			v41 = v6;
			if (v6 >= 20) {
				break;
			}
		}
		v1 = a1;
	}
	v17 = v1[126];
	for (l = 0; v17; v17 = *(uint32_t*)(v17 + 496)) {
		if (*(uint32_t*)(v17 + 16) & 0x100) {
			++l;
		}
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread(&l, 1u);
	for (m = v1[126]; m; m = *(uint32_t*)(m + 496)) {
		if (*(uint32_t*)(m + 16) & 0x100) {
			nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(m + 44), 4u);
		}
	}
	v19 = sub_4678B0();
	v37 = v19;
	if (!v19) {
		if (!m) {
			v37 = 0;
		}
	} else {
		m = v1[126];
		if (m) {
			while (1) {
				if (*(uint32_t*)(m + 36) == v19) {
					v37 = *(uint32_t*)(m + 44);
					if (!m) {
						v37 = 0;
					}
					break;
				}
				m = *(uint32_t*)(m + 496);
				if (!m) {
					v37 = 0;
					break;
				}
			}
		} else {
			v37 = 0;
		}
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v37, 4u);
	v20 = sub_4678C0();
	v37 = v20;
	if (v20) {
		m = v1[126];
		if (!m) {
			v37 = 0;
			goto LABEL_67;
		}
		while (*(uint32_t*)(m + 36) != v20) {
			m = *(uint32_t*)(m + 496);
			if (!m) {
				v37 = 0;
				goto LABEL_67;
			}
		}
		v37 = *(uint32_t*)(m + 44);
	}
	if (!m) {
		v37 = 0;
	}
LABEL_67:
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v37, 4u);
LABEL_109:
	v32 = (uint8_t*)(v40 + 244);
	if ((short)v42 < 3) {
		*(uint8_t*)(v40 + 244) = 0;
	} else {
		nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(v40 + 244), 1u);
	}
	if (nox_crypt_IsReadOnly() == 1 && nox_common_gameFlags_check_40A5C0(4096)) {
		*v32 = 0;
	}
LABEL_115:
	if (nox_common_gameFlags_check_40A5C0(4096) && !sub_4F2C30((int)v1)) {
		return 0;
	}
	nox_xxx_netMsgInventoryLoaded_4D96E0(*(unsigned char*)(*(uint32_t*)(v40 + 276) + 2064));
	return 1;
}
// 41AC30: using guessed type char var_100[256];

//----- (0041B3B0) --------------------------------------------------------
int sub_41B3B0() {
	int v0; // ebx
	int i;  // edi
	int j;  // esi

	v0 = 0;
	for (i = 0; i < 20; ++i) {
		for (j = 0; j < 4; ++j) {
			v0 += sub_467810(j, i);
		}
	}
	return v0;
}

//----- (0041B3E0) --------------------------------------------------------
int sub_41B3E0(int a1) {
	int v1;     // eax
	int result; // eax

	v1 = *getMemU32Ptr(0x5D4594, 527724);
	if (!*getMemU32Ptr(0x5D4594, 527724)) {
		v1 = nox_xxx_getNameId_4E3AA0("Glyph");
		*getMemU32Ptr(0x5D4594, 527724) = v1;
	}
	if ((*(uint8_t*)(a1 + 8) & 0x40) == 64) {
		result = 0;
	} else {
		result = *(unsigned short*)(a1 + 4) != v1;
	}
	return result;
}

//----- (0041B420) --------------------------------------------------------
int nox_xxx_guiFieldbook_41B420(int a1) {
	char* v1;      // esi
	int result;    // eax
	uint32_t* v3;  // ebp
	uint32_t* v4;  // eax
	int v5;        // ecx
	int i;         // esi
	char* v7;      // eax
	int v8;        // esi
	int v9;        // eax
	int v10;       // eax
	size_t v11;    // [esp-4h] [ebp-124h]
	char v12;      // [esp+13h] [ebp-10Dh]
	int v13;       // [esp+14h] [ebp-10Ch]
	int v14;       // [esp+18h] [ebp-108h]
	int v15;       // [esp+1Ch] [ebp-104h]
	char v16[256]; // [esp+20h] [ebp-100h]

	v1 = nox_common_playerInfoGetByID_417040(*(uint32_t*)(a1 + 36));
	v12 = 1;
	if (!v1) {
		return 0;
	}
	v15 = 1;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v15, 2u);
	if ((short)v15 > 1) {
		return 0;
	}
	if (nox_common_gameFlags_check_40A5C0(0x2000) && !nox_common_gameFlags_check_40A5C0(4096)) {
		v12 = 0;
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v12, 1u);
	if (!v12) {
		return 1;
	}
	if (!nox_common_gameFlags_check_40A5C0(2048)) {
		result = nox_common_gameFlags_check_40A5C0(4096);
		if (!result) {
			return result;
		}
	}
	if (nox_crypt_IsReadOnly()) {
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v13, 1u);
		if ((unsigned char)v13 > 0x29u) {
			return 0;
		}
		v8 = 0;
		if ((unsigned char)v13 > 0u) {
			while (1) {
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v14, 1u);
				if ((int)(unsigned char)v14 >= 256) {
					break;
				}
				nox_xxx_fileReadWrite_426AC0_file3_fread(v16, (unsigned char)v14);
				v16[(unsigned char)v14] = 0;
				if (nox_common_gameFlags_check_40A5C0(4096)) {
					v9 = nox_xxx_guide_427010(v16);
					if (!sub_4F2EF0(v9)) {
						break;
					}
				}
				v10 = nox_xxx_guide_427010(v16);
				nox_xxx_awardBeastGuide_4FAE80_magic_plyrgide(a1, v10, 0);
				if (++v8 >= (unsigned char)v13) {
					return 1;
				}
			}
			return 0;
		}
		return 1;
	}
	v3 = v1 + 4248;
	LOBYTE(v13) = 0;
	v4 = v1 + 4248;
	v5 = 40;
	do {
		if (*v4) {
			LOBYTE(v13) = v13 + 1;
		}
		++v4;
		--v5;
	} while (v5);
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v13, 1u);
	for (i = 1; i < 41; ++i) {
		if (*v3) {
			LOBYTE(v14) = strlen(nox_xxx_guideNameByN_427230(i));
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v14, 1u);
			v11 = (unsigned char)v14;
			v7 = nox_xxx_guideNameByN_427230(i);
			nox_xxx_fileReadWrite_426AC0_file3_fread(v7, v11);
		}
		++v3;
	}
	return 1;
}
// 41B420: using guessed type char var_100[256];

//----- (0041B660) --------------------------------------------------------
int nox_xxx_guiSpellbook_41B660(int a1) {
	int result;    // eax
	int v2;        // esi
	uint8_t* v3;   // ebp
	uint32_t* v4;  // eax
	int v5;        // ecx
	int v6;        // ecx
	char v7;       // al
	int v8;        // esi
	char* v9;      // eax
	char* v10;     // eax
	int v11;       // ebp
	bool v12;      // cc
	int v13;       // eax
	int v14;       // eax
	int v15;       // eax
	size_t v16;    // [esp-4h] [ebp-128h]
	size_t v17;    // [esp-4h] [ebp-128h]
	int v18;       // [esp-4h] [ebp-128h]
	char v19;      // [esp+13h] [ebp-111h]
	int v20;       // [esp+14h] [ebp-110h]
	int v21;       // [esp+18h] [ebp-10Ch]
	int v22;       // [esp+1Ch] [ebp-108h]
	int v23;       // [esp+20h] [ebp-104h]
	char v24[256]; // [esp+24h] [ebp-100h]

	result = nox_common_playerInfoGetByID_417040(*(uint32_t*)(a1 + 36));
	v2 = result;
	v19 = 1;
	if (!result) {
		return result;
	}
	v22 = 3;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v22, 2u);
	if ((short)v22 > 3) {
		return 0;
	}
	if (nox_common_gameFlags_check_40A5C0(0x2000) && !nox_common_gameFlags_check_40A5C0(4096)) {
		v19 = 0;
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v19, 1u);
	if (!v19) {
		return 1;
	}
	if (!nox_common_gameFlags_check_40A5C0(2048)) {
		result = nox_common_gameFlags_check_40A5C0(4096);
		if (!result) {
			return result;
		}
	}
	if (nox_crypt_IsReadOnly()) {
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v20, 1u);
		if ((unsigned char)v20 > 0x89u) {
			return 0;
		}
		v11 = 0;
		if ((uint8_t)v20) {
			while (1) {
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v21, 1u);
				if ((int)(unsigned char)v21 >= 256) {
					break;
				}
				nox_xxx_fileReadWrite_426AC0_file3_fread(v24, (unsigned char)v21);
				v12 = (short)v22 < 2;
				v23 = 3;
				v24[(unsigned char)v21] = 0;
				if (!v12) {
					nox_xxx_fileReadWrite_426AC0_file3_fread(&v23, 4u);
				}
				if (nox_common_gameFlags_check_40A5C0(4096) && v23 > 3 && *(uint8_t*)(v2 + 2251)) {
					break;
				}
				if (nox_common_gameFlags_check_40A5C0(4096)) {
					if (*(uint8_t*)(v2 + 2251)) {
						v13 = nox_xxx_spellNameToN_4243F0(v24);
						if (!nox_xxx_spell_4F2E70(v13)) {
							break;
						}
					}
				}
				if ((short)v22 < 3 || *(uint8_t*)(v2 + 2251)) {
					v18 = v23;
					v15 = nox_xxx_spellNameToN_4243F0(v24);
					nox_xxx_spellGrantToPlayer_4FB550(a1, v15, 0, 0, v18);
				} else {
					v14 = nox_xxx_abilityNameToN_424D80(v24);
					nox_xxx_abilityRewardServ_4FB9C0_ability(a1, v14, 0);
				}
				if (++v11 >= (unsigned char)v20) {
					return 1;
				}
			}
			return 0;
		}
		return 1;
	}
	LOBYTE(v20) = 0;
	v3 = (uint8_t*)(v2 + 3700);
	v4 = (uint32_t*)(v2 + 3700);
	if (*(uint8_t*)(v2 + 2251)) {
		v6 = 136;
		do {
			if (*v4) {
				LOBYTE(v20) = v20 + 1;
			}
			++v4;
			--v6;
		} while (v6);
	} else {
		v5 = 5;
		do {
			if (*v4) {
				LOBYTE(v20) = v20 + 1;
			}
			++v4;
			--v5;
		} while (v5);
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v20, 1u);
	v7 = *(uint8_t*)(v2 + 2251);
	v8 = 1;
	if (v7) {
		do {
			if (*(uint32_t*)v3) {
				LOBYTE(v21) = strlen(nox_xxx_spellNameByN_424870(v8));
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v21, 1u);
				v17 = (unsigned char)v21;
				v10 = nox_xxx_spellNameByN_424870(v8);
				nox_xxx_fileReadWrite_426AC0_file3_fread(v10, v17);
				nox_xxx_fileReadWrite_426AC0_file3_fread(v3, 4u);
			}
			++v8;
			v3 += 4;
		} while (v8 < 137);
		result = 1;
	} else {
		do {
			if (*(uint32_t*)v3) {
				LOBYTE(v21) = strlen(nox_xxx_abilityGetName_425250(v8));
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v21, 1u);
				v16 = (unsigned char)v21;
				v9 = nox_xxx_abilityGetName_425250(v8);
				nox_xxx_fileReadWrite_426AC0_file3_fread(v9, v16);
				nox_xxx_fileReadWrite_426AC0_file3_fread(v3, 4u);
			}
			++v8;
			v3 += 4;
		} while (v8 < 6);
		result = 1;
	}
	return result;
}
// 41B660: using guessed type char var_100[256];

//----- (0041B9C0) --------------------------------------------------------
int nox_xxx_guiEnchantment_41B9C0(uint32_t* a1) {
	int result;    // eax
	int i;         // ebp
	char* v3;      // ebx
	int v4;        // eax
	int v5;        // ebp
	int v6;        // edi
	int v7;        // ecx
	int v8;        // eax
	short v9;      // ax
	int v10;       // eax
	int j;         // edi
	int k;         // edi
	int v13;       // [esp-8h] [ebp-140h]
	char v14;      // [esp+Dh] [ebp-12Bh]
	char v15;      // [esp+Eh] [ebp-12Ah]
	char v16;      // [esp+Fh] [ebp-129h]
	int v17;       // [esp+10h] [ebp-128h]
	int v18;       // [esp+14h] [ebp-124h]
	int v19;       // [esp+18h] [ebp-120h]
	int v20;       // [esp+1Ch] [ebp-11Ch]
	int v21;       // [esp+20h] [ebp-118h]
	int v22;       // [esp+24h] [ebp-114h]
	int v23;       // [esp+28h] [ebp-110h]
	int v24[3];    // [esp+2Ch] [ebp-10Ch]
	char v27[256]; // [esp+38h] [ebp-100h]

	v19 = a1[187];
	v16 = 1;
	v18 = 5;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v18, 2u);
	if ((short)v18 > 5) {
		return 0;
	}
	if (nox_crypt_IsReadOnly() == 1 && nox_common_gameFlags_check_40A5C0(2048)) {
		nox_xxx_spellCastByPlayer_4FEEF0();
		sub_4FE8A0(0);
	}
	if (nox_common_gameFlags_check_40A5C0(0x2000)) {
		v16 = 0;
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v16, 1u);
	if (v16) {
		result = nox_common_gameFlags_check_40A5C0(2048);
		if (!result) {
			return result;
		}
		if (nox_crypt_IsReadOnly()) {
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v22, 1u);
			v5 = 0;
			if ((uint8_t)v22) {
				do {
					nox_xxx_fileReadWrite_426AC0_file3_fread(&v20, 1u);
					nox_xxx_fileReadWrite_426AC0_file3_fread(v27, (unsigned char)v20);
					v27[(unsigned char)v20] = 0;
					v6 = nox_xxx_enchantByName_424880(v27);
					nox_xxx_fileReadWrite_426AC0_file3_fread(&v17, 2u);
					LOBYTE(v21) = 2;
					if ((short)v18 >= 2) {
						nox_xxx_fileReadWrite_426AC0_file3_fread(&v21, 1u);
					}
					v7 = a1[15];
					v24[1] = a1[14];
					v13 = (unsigned char)v21;
					v24[0] = a1;
					v24[2] = v7;
					v8 = nox_xxx_getEnchantSpell_424920(v6);
					nox_xxx_spellAccept_4FD400(v8, (int)a1, a1, (int)a1, (int*)&v24, v13);
					v9 = v17;
					if (!(uint16_t)v17) {
						v9 = (uint16_t)gameFPS();
						v17 = gameFPS();
					}
					*((uint16_t*)a1 + v6 + 172) = v9;
					if (v6 == 26 && (short)v18 >= 3) {
						nox_xxx_fileReadWrite_426AC0_file3_fread(&v23, 4u);
						v10 = sub_4FF2D0(51, (int)a1);
						if (v10) {
							*(uint32_t*)(v10 + 72) = v23;
						}
					}
					++v5;
				} while (v5 < (unsigned char)v22);
			}
		} else {
			LOBYTE(v22) = sub_424CB0((int)a1);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v22, 1u);
			for (i = sub_424D00(); i != -1; i = sub_424D20(i)) {
				if (nox_xxx_testUnitBuffs_4FF350((int)a1, i)) {
					v3 = nox_xxx_getEnchantName_4248F0(i);
					LOBYTE(v20) = strlen(v3);
					nox_xxx_fileReadWrite_426AC0_file3_fread(&v20, 1u);
					nox_xxx_fileReadWrite_426AC0_file3_fread(v3, (unsigned char)v20);
					nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)a1 + 2 * i + 344, 2u);
					LOBYTE(v21) = nox_xxx_buffGetPower_4FF570((int)a1, i);
					nox_xxx_fileReadWrite_426AC0_file3_fread(&v21, 1u);
					if (i == 26) {
						v4 = sub_4FF2D0(51, (int)a1);
						if (v4) {
							v17 = *(uint32_t*)(v4 + 72);
						} else {
							v17 = 100;
						}
						nox_xxx_fileReadWrite_426AC0_file3_fread(&v17, 4u);
					}
				}
			}
		}
		if ((short)v18 >= 5 && !*(uint8_t*)(*(uint32_t*)(v19 + 276) + 2251)) {
			v14 = nox_common_playerIsAbilityActive_4FC250((int)a1, 1);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v14, 1u);
			if (nox_crypt_IsReadOnly() == 1 && v14 == 1) {
				sub_4FC670(1);
			}
			v15 = nox_common_playerIsAbilityActive_4FC250((int)a1, 4);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v15, 1u);
			v23 = sub_4FC030((int)a1, 4);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v23, 4u);
			if (nox_crypt_IsReadOnly() == 1 && v15 == 1) {
				nox_xxx_playerExecuteAbil_4FBB70((int)a1, 4);
				sub_4FC070((int)a1, 4, v23);
			}
			for (j = 2 - (v14 != 1); j < 6; ++j) {
				v17 = sub_4FBE60((int)a1, j);
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v17, 4u);
				if (nox_crypt_IsReadOnly() == 1) {
					sub_4FBEA0((int)a1, j, v17);
					if (v17) {
						nox_xxx_netAbilRepotState_4D8100((int)a1, j, 0);
					}
				}
			}
		}
	}
	if ((uint16_t)v18 == 4 && !*(uint8_t*)(*(uint32_t*)(v19 + 276) + 2251)) {
		v14 = nox_common_playerIsAbilityActive_4FC250((int)a1, 1);
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v14, 1u);
		if (nox_crypt_IsReadOnly() == 1 && v14 == 1) {
			sub_4FC670(1);
		}
		v15 = nox_common_playerIsAbilityActive_4FC250((int)a1, 4);
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v15, 1u);
		v19 = sub_4FC030((int)a1, 4);
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v19, 4u);
		if (nox_crypt_IsReadOnly() == 1 && v15 == 1) {
			nox_xxx_playerExecuteAbil_4FBB70((int)a1, 4);
			sub_4FC070((int)a1, 4, v19);
		}
		for (k = 2 - (v14 != 1); k < 6; ++k) {
			v17 = sub_4FBE60((int)a1, k);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v17, 4u);
			if (nox_crypt_IsReadOnly() == 1) {
				sub_4FBEA0((int)a1, k, v17);
				if (v17) {
					nox_xxx_netAbilRepotState_4D8100((int)a1, k, 0);
				}
			}
		}
	}
	return 1;
}
// 41B9C0: using guessed type char var_100[256];

//----- (0041BEC0) --------------------------------------------------------
int sub_41BEC0(int a1) {
	int v1;       // edi
	int v2;       // esi
	int result;   // eax
	int i;        // eax
	int v5;       // esi
	int v6;       // esi
	int j;        // eax
	int v8;       // [esp+Ch] [ebp-50h]
	int v9;       // [esp+10h] [ebp-4Ch]
	int v10;      // [esp+14h] [ebp-48h]
	int v11;      // [esp+18h] [ebp-44h]
	char v12[64]; // [esp+1Ch] [ebp-40h]

	v1 = a1;
	v2 = *(uint32_t*)(*(uint32_t*)(a1 + 748) + 276);
	LOBYTE(a1) = 1;
	v10 = 1;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v10, 2u);
	if ((short)v10 > 1) {
		return 0;
	}
	if (nox_common_gameFlags_check_40A5C0(0x2000)) {
		LOBYTE(a1) = 0;
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 1u);
	if (!(uint8_t)a1) {
		return 1;
	}
	result = nox_common_gameFlags_check_40A5C0(2048);
	if (!result) {
		return result;
	}
	v8 = 0;
	for (i = *(uint32_t*)(v2 + 3644); i; i = *(uint32_t*)(i + 64)) {
		++v8;
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v8, 2u);
	if (nox_crypt_IsReadOnly() != 1) {
		if ((unsigned short)v8 > 0u) {
			v6 = *(uint32_t*)(v2 + 3644);
			for (j = *(uint32_t*)(v6 + 64); j; j = *(uint32_t*)(j + 64)) {
				v6 = j;
			}
			for (; v6; v6 = *(uint32_t*)(v6 + 68)) {
				LOBYTE(v9) = strlen((const char*)v6);
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v9, 1u);
				nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)v6, (unsigned char)v9);
				nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(v6 + 72), 2u);
			}
		}
		return 1;
	}
	sub_4277B0(v1, 0xFFFFu);
	v5 = 0;
	if ((unsigned short)v8 <= 0u) {
		return 1;
	}
	do {
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v9, 1u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(v12, (unsigned char)v9);
		v12[(unsigned char)v9] = 0;
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v11, 2u);
		nox_xxx_comJournalEntryAdd_427500(v1, v12, v11);
		++v5;
	} while (v5 < (unsigned short)v8);
	return 1;
}
// 41BEC0: using guessed type char var_40[64];

//----- (0041C080) --------------------------------------------------------
int sub_41C080(int a1) {
	uint32_t* v1;    // ebp
	int v2;          // ebx
	int result;      // eax
	unsigned int v4; // [esp+8h] [ebp-Ch]
	int v5;          // [esp+Ch] [ebp-8h]
	char v6[4];      // [esp+10h] [ebp-4h]

	v1 = (uint32_t*)a1;
	v2 = *(uint32_t*)(*(uint32_t*)(a1 + 748) + 276);
	if (nox_common_gameFlags_check_40A5C0(0x2000)) {
		return 1;
	}
	a1 = 5;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 2u);
	if ((short)a1 > 5) {
		return 0;
	}
	if ((short)a1 >= 5) {
		if (nox_crypt_IsReadOnly()) {
			nox_xxx_fileReadWrite_426AC0_file3_fread(v6, 4u);
		} else {
			int oid = nox_server_LastObjectScriptID();
			nox_xxx_fileReadWrite_426AC0_file3_fread(&oid, 4u);
			nox_server_SetLastObjectScriptID(oid);
		}
	}
	if (!nox_crypt_IsReadOnly()) {
		strcpy((char*)(v2 + 4760), nox_xxx_mapGetMapName_409B40());
	}
	v4 = strlen((const char*)(v2 + 4760));
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v4, 2u);
	nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(v2 + 4760), 2 * (unsigned short)v4);
	*(uint8_t*)((unsigned short)v4 + v2 + 4760) = 0;
	if ((short)a1 < 2 || (nox_crypt_IsReadOnly() ? (result = sub_500B70()) : (result = sub_500A60()), result)) {
		if ((short)a1 < 3 || (result = sub_5000B0(v1)) != 0) {
			if ((short)a1 >= 4) {
				LOBYTE(v5) = sub_450750();
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v5, 1u);
				sub_450760(v5);
				return 1;
			}
			sub_450760(0);
			return 1;
		}
	}
	return result;
}

//----- (0041C280) --------------------------------------------------------
// Related to placing traps??
int sub_41C280(void* a1) {
	int result; // eax
	char* v2;   // eax
	char* v3;   // esi
	int v4;     // [esp+4h] [ebp-4h]

	v4 = 3;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v4, 2u);
	if ((short)v4 > 3) {
		return 0;
	}
	result = sub_460940(a1);
	if (result) {
		if ((short)v4 >= 2) {
			LOBYTE(a1) = nox_xxx_buttonsGetSelectedRow_45E180();
			nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 1u);
			if (nox_crypt_IsReadOnly() == 1) {
				nox_xxx_clientUpdateButtonRow_45E110((unsigned char)a1);
			}
			LOBYTE(a1) = sub_4604E0();
			nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 1u);
			if (nox_crypt_IsReadOnly() == 1) {
				nox_client_trapSetSelect_4604B0((unsigned char)a1);
			}
		}
		if ((short)v4 >= 3) {
			v2 = nox_common_playerInfoGetByID_417040(nox_player_netCode_85319C);
			v3 = v2;
			if (v2) {
				LOBYTE(a1) = v2[3648];
			} else {
				LOBYTE(a1) = 4;
			}
			nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 1u);
			if (nox_crypt_IsReadOnly() == 1) {
				if (nox_common_gameFlags_check_40A5C0(2048)) {
					nox_xxx_orderUnitLocal_500C70((unsigned char)v3[2064], (unsigned char)a1);
				}
			}
		}
		result = 1;
	}
	return result;
}

//----- (0041C3B0) --------------------------------------------------------
int nox_xxx_parseFileInfoData_41C3B0(int a1) {
	int v1;          // eax
	int v2;          // eax
	int v3;          // [esp+0h] [ebp-Ch]
	unsigned int v4; // [esp+4h] [ebp-8h]
	int v5;          // [esp+8h] [ebp-4h]

	v5 = 12;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v5, 2u);
	if ((short)v5 > 12) {
		return 0;
	}
	if (nox_common_gameFlags_check_40A5C0(0x2000)) {
		*getMemU32Ptr(0x85B3FC, 10980) &= 0xFFFFFFFE;
		if (nox_common_gameFlags_check_40A5C0(4096) || nox_xxx_isQuest_4D6F50() || sub_4D6F70()) {
			v2 = *getMemU32Ptr(0x85B3FC, 10980);
			LOBYTE(v2) = getMemByte(0x85B3FC, 10980) | 4;
			*getMemU32Ptr(0x85B3FC, 10980) = v2;
		} else {
			v1 = *getMemU32Ptr(0x85B3FC, 10980);
			LOBYTE(v1) = getMemByte(0x85B3FC, 10980) | 2;
			*getMemU32Ptr(0x85B3FC, 10980) = v1;
		}
	} else {
		*getMemU32Ptr(0x85B3FC, 10980) = *getMemU32Ptr(0x85B3FC, 10980) & 0xFFFFFFF9 | 1;
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x85B3FC, 10980), 4u);
	if (nox_crypt_IsReadOnly()) {
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v4, 2u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x85B3FC, 10984), (short)v4);
		*getMemU8Ptr(0x85B3FC, 10984 + (short)v4) = 0;
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v3, 1u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x85B3FC, 12008), (unsigned char)v3);
		*getMemU8Ptr(0x85B3FC, 12008 + (unsigned char)v3) = 0;
	} else {
		v4 = strlen((const char*)getMemAt(0x85B3FC, 10984));
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v4, 2u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x85B3FC, 10984), (short)v4);
		LOBYTE(v3) = strlen((const char*)getMemAt(0x85B3FC, 12008));
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v3, 1u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x85B3FC, 12008), (unsigned char)v3);
	}
	noxGetLocalTime(getMemAt(0x85B3FC, 12168));
	nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x85B3FC, 12168), 2u);
	nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x85B3FC, 12170), 2u);
	nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x85B3FC, 12172), 2u);
	nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x85B3FC, 12174), 2u);
	nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x85B3FC, 12176), 2u);
	nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x85B3FC, 12178), 2u);
	nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x85B3FC, 12180), 2u);
	nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x85B3FC, 12182), 2u);
	nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x85B3FC, 12187), 3u);
	nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x85B3FC, 12184), 3u);
	nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x85B3FC, 12190), 3u);
	nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x85B3FC, 12193), 3u);
	nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x85B3FC, 12196), 3u);
	nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x85B3FC, 12199), 1u);
	nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x85B3FC, 12200), 1u);
	nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x85B3FC, 12201), 1u);
	nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x85B3FC, 12202), 1u);
	nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x85B3FC, 12203), 1u);
	if (nox_crypt_IsReadOnly()) {
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v3, 1u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x85B3FC, 12204), 2 * (unsigned char)v3);
		*getMemU16Ptr(0x85B3FC, 12204 + 2 * (unsigned char)v3) = 0;
	} else {
		LOBYTE(v3) = nox_wcslen((const wchar2_t*)getMemAt(0x85B3FC, 12204));
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v3, 1u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x85B3FC, 12204), 2 * (unsigned char)v3);
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x85B3FC, 12254), 1u);
	*getMemU8Ptr(0x85B3FC, 12255) = 0;
	nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x85B3FC, 12255), 1u);
	if (!nox_crypt_IsReadOnly()) {
		*getMemU8Ptr(0x85B3FC, 12256) = sub_467590();
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x85B3FC, 12256), 1u);
	if ((short)v5 >= 11) {
		strcpy((char*)getMemAt(0x85B3FC, 12136), nox_xxx_mapGetMapName_409B40());
		LOBYTE(v3) = strlen((const char*)getMemAt(0x85B3FC, 12136));
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v3, 1u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x85B3FC, 12136), (unsigned char)v3);
		*getMemU8Ptr(0x85B3FC, 12136 + (unsigned char)v3) = 0;
	}
	if ((short)v5 < 12) {
		*getMemU8Ptr(0x85B3FC, 12257) = 0;
	} else {
		nox_xxx_fileReadWrite_426AC0_file3_fread(getMemAt(0x85B3FC, 12257), 1u);
	}
	return 1;
}

//----- (0041C780) --------------------------------------------------------
int sub_41C780(int a1) {
	int i;    // edi
	char* v2; // esi
	bool v3;  // [esp+3h] [ebp-19h]
	int v4;   // [esp+4h] [ebp-18h]
	int v5;   // [esp+8h] [ebp-14h]
	int4 v6;  // [esp+Ch] [ebp-10h]

	v5 = 11;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v5, 2u);
	if ((short)v5 > 11) {
		return 0;
	}
	if ((short)v5 < 11 ||
		(v3 = !nox_common_gameFlags_check_40A5C0(0x2000), nox_xxx_fileReadWrite_426AC0_file3_fread(&v3, 1u), v3)) {
		if (nox_crypt_IsReadOnly()) {
			v6.field_0 = 0;
			v6.field_4 = 0;
			v6.field_8 = 0;
			v6.field_C = 0;
		} else {
			sub_43DD10(&v6.field_0);
			v4 = sub_43DB20();
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v6.field_C, 4u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v6.field_8, 4u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v6, 4u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v6.field_4, 4u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v4, 4u);
		for (i = 0; i < v4; ++i) {
			v2 = sub_43DB40(i);
			if (nox_crypt_IsReadOnly() == 1) {
				*(uint32_t*)v2 = 0;
				*((uint32_t*)v2 + 1) = 0;
				*((uint32_t*)v2 + 2) = 0;
				*((uint32_t*)v2 + 3) = 0;
			}
			nox_xxx_fileReadWrite_426AC0_file3_fread(v2 + 12, 4u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(v2 + 8, 4u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(v2, 4u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(v2 + 4, 4u);
		}
		if (nox_crypt_IsReadOnly() == 1 && !nox_common_gameFlags_check_40A5C0(0x2000)) {
			sub_43D9E0(&v6);
			sub_43DB30(v4);
		}
	}
	return 1;
}

//----- (0041CAC0) --------------------------------------------------------
void sub_41CAC0(char* a1, void* a2) {
	char** v3;         // esi
	int v4;            // ebx
	int v5;            // edi
	int v6;            // eax
	unsigned char* v7; // ecx
	int v8;            // ebp
	int v9;            // eax
	uint32_t* v10;     // esi
	int v11;           // edi
	int v12;           // [esp+0h] [ebp-8h]
	char* v13;         // [esp+4h] [ebp-4h]

	nox_file_2 = nox_binfile_open_408CC0(a1, 0);
	if (!nox_file_2) {
		return;
	}
	if (!nox_binfile_cryptSet_408D40(nox_file_2, 27)) {
		return;
	}
	v3 = a2;
	v4 = 0;
	while (1) {
		nox_binfile_fread_408E40((char*)&v13, 4, 1, nox_file_2);
		if (!v13) {
			break;
		}
		v5 = nox_binfile_ftell_426A50(nox_file_2);
		nox_binfile_fread_align_408FE0((char*)&v12, 4, 1, nox_file_2);
		v6 = nox_binfile_ftell_426A50(nox_file_2);
		if (!*getMemU32Ptr(0x587000, 55816)) {
			nox_binfile_fseek_409050(nox_file_2, v12, SEEK_CUR);
			continue;
		}
		v7 = getMemAt(0x587000, 55816);
		while (1) {
			if (v13 == *((char**)v7 + 1)) {
				v9 = v6 - v5;
				*v3 = v13;
				v10 = (char**)((char*)v3 + v9 - 4);
				v4 += v9 + 4;
				*v10 = v12;
				v3 = (char**)(v10 + 2);
				if (v12) {
					v11 = v12;
					v4 += v12;
					do {
						nox_binfile_fread_408E40((char*)&a1, 1, 1, nox_file_2);
						*(uint8_t*)v3 = (uint8_t)a1;
						v3 = (char**)((char*)v3 + 1);
						--v11;
					} while (v11);
				}
				break;
			}
			v8 = *((uint32_t*)v7 + 3);
			v7 += 12;
			if (!v8) {
				nox_binfile_fseek_409050(nox_file_2, v12, SEEK_CUR);
				break;
			}
		}
	}
	*v3 = 0;
	nox_binfile_close_408D90(nox_file_2);
}

//----- (0041CC50) --------------------------------------------------------
int nox_xxx_computeServerPlayerDataBufferSize_41CC50(char* a1) {
	char* v1;          // esi
	FILE* v2;          // eax
	int result;        // eax
	int v4;            // edi
	int v5;            // esi
	int v6;            // eax
	unsigned char* v7; // ecx
	int v8;            // ebx
	int v9;            // [esp+4h] [ebp-4h]

	v1 = a1;
	v2 = nox_binfile_open_408CC0(a1, 0);
	nox_file_2 = v2;
	if (v2) {
		if (nox_binfile_cryptSet_408D40((int)v2, 27)) {
			v4 = 0;
			while (1) {
				nox_binfile_fread_408E40((char*)&a1, 4, 1, nox_file_2);
				if (nox_binfile_lastErr_409370(nox_file_2) == -1) {
					break;
				}
				if (!a1) {
					v4 += 4;
					break;
				}
				v5 = nox_binfile_ftell_426A50(nox_file_2);
				nox_binfile_fread_align_408FE0((char*)&v9, 4, 1, nox_file_2);
				v6 = nox_binfile_ftell_426A50(nox_file_2) - v5;
				if (*getMemU32Ptr(0x587000, 55816)) {
					v7 = getMemAt(0x587000, 55816);
					while (a1 != *((char**)v7 + 1)) {
						v8 = *((uint32_t*)v7 + 3);
						v7 += 12;
						if (!v8) {
							goto LABEL_14;
						}
					}
					v4 += v9 + v6 + 4;
				}
			LABEL_14:
				nox_binfile_fseek_409050(nox_file_2, v9, SEEK_CUR);
			}
			nox_binfile_close_408D90(nox_file_2);
			result = v4;
		} else {
			nox_xxx_networkLog_printf_413D30("computeServerPlayerDataBufferSize: Can't key file '%s'\n", v1);
			result = 0;
		}
	} else {
		nox_xxx_networkLog_printf_413D30("computeServerPlayerDataBufferSize: Can't open file '%s'\n", v1);
		result = 0;
	}
	return result;
}

//----- (0041CE00) --------------------------------------------------------
int nox_xxx_netSavePlayer_41CE00() {
	char v2[3]; // [esp+0h] [ebp-4h]

	v2[0] = -63;
	*(uint16_t*)&v2[1] = nox_player_netCode_85319C; // playerNetCode; my player Id (client)
	nox_xxx_netClientSend2_4E53C0(31, v2, 3, 0, 1);
	return 1;
}

//----- (0041CEE0) --------------------------------------------------------
int sub_41CEE0(void* a1p, int a2) {
	int a1 = a1p;
	int v3;            // ebx
	unsigned char* v4; // esi
	int v6;            // edi
	int v8;            // eax

	memcpy(getMemAt(0x85B3FC, 10980), a1, sizeof(nox_savegame_xxx));
	if (!nox_xxx_cryptOpen_426910((char*)getMemAt(0x85B3FC, 10984), 0, 27)) {
		return 0;
	}
	v3 = a2;
	if (!a2) {
		a1 = 1;
	}
	if (*getMemU32Ptr(0x587000, 55936)) {
		v4 = getMemAt(0x587000, 55940);
		while (1) {
			if (v3 || *(uint32_t*)v4 == a1) {
				nox_xxx_fileReadWrite_426AC0_file3_fread(v4, 4u);
				nox_xxx_crypt_426C90();
				v6 = (*((int (**)(uint32_t))v4 + 1))(0);
				nox_xxx_crypt_426D40();
				if (!v6) {
					nox_xxx_cryptClose_4269F0();
					return 0;
				}
			}
			v8 = *((uint32_t*)v4 + 2);
			v4 += 12;
			if (!v8) {
				break;
			}
		}
	}
	a1 = 0;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 4u);
	nox_xxx_cryptClose_4269F0();
	return 1;
}
// 41CF42: variable 'v5' is possibly undefined
// 41CF51: variable 'v7' is possibly undefined

//----- (0041D1A0) --------------------------------------------------------
int sub_41D1A0(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 527720) = a1;
	return result;
}

//----- (0041D1B0) --------------------------------------------------------
int sub_41D1B0() { return *getMemU32Ptr(0x5D4594, 527720); }

//----- (0041D650) --------------------------------------------------------
int sub_41D650() {
	char* v0;   // eax
	int result; // eax

	v0 = sub_41FA40();
	result = sub_41F800(v0);
	if (result) {
		result = 0;
	}
	*getMemU32Ptr(0x5D4594, 371700) = 1;
	return result;
}

//----- (0041D670) --------------------------------------------------------
int sub_41D670(char* a1) {
	int v1;      // eax
	short v3;    // [esp+2h] [ebp-4Ah]
	char v4[72]; // [esp+4h] [ebp-48h]

	if (!sub_420230(v4, &v3)) {
		return 0;
	}
	v1 = sub_4200E0();
	abort();
	return 0;
}

//----- (0041D6C0) --------------------------------------------------------
int sub_41D6C0() {
	int v0;         // ebx
	char* v1;       // ebp
	int v2;         // eax
	int v3;         // ebp
	char* v4;       // ebx
	int v5;         // eax
	int result;     // eax
	char* v7;       // ebp
	int v8;         // eax
	short v9;       // [esp+12h] [ebp-45Ah]
	char* v10;      // [esp+14h] [ebp-458h]
	int v11;        // [esp+18h] [ebp-454h]
	int v12;        // [esp+1Ch] [ebp-450h]
	int v13;        // [esp+20h] [ebp-44Ch]
	char v14[72];   // [esp+24h] [ebp-448h]
	char v15[1024]; // [esp+6Ch] [ebp-400h]

	v0 = 1;
	memset(v15, 0, sizeof(v15));
	v11 = 1;
	v12 = 1;
	if (!sub_420230(v14, &v9)) {
		return 0;
	}
	if ((unsigned int)nox_common_playerInfoCount_416F40() > 25) {
		v1 = nox_common_playerInfoGetFirst_416EA0();
		v13 = 25;
		while (1) {
			if (v1[2096]) {
				if (v0) {
					strcat(v15, v1 + 2096);
					v0 = 0;
				} else {
					*(uint16_t*)&v15[strlen(v15)] = *getMemU16Ptr(0x587000, 58112);
					strcat(v15, v1 + 2096);
				}
			}
			v10 = nox_common_playerInfoGetNext_416EE0((int)v1);
			--v13;
			if (!v13) {
				break;
			}
			v1 = v10;
		}
		if (!v0) {
			v2 = sub_4200E0();
			abort();
		}
		v3 = 1;
		if (!v10) {
			return v11 && v12 == 1;
		}
		v15[0] = 0;
		v4 = nox_common_playerInfoGetNext_416EE0((int)v10);
		if (!v4) {
			return v11 && v12 == 1;
		}
		do {
			if (v4[2096]) {
				if (v3) {
					strcat(v15, v4 + 2096);
					v3 = 0;
				} else {
					*(uint16_t*)&v15[strlen(v15)] = *getMemU16Ptr(0x587000, 58116);
					strcat(v15, v4 + 2096);
				}
			}
			v4 = nox_common_playerInfoGetNext_416EE0((int)v4);
		} while (v4);
		if (!v3) {
			v5 = sub_4200E0();
			abort();
		} else {
			result = v12;
		}
		return v11 && result == 1;
	}
	v7 = nox_common_playerInfoGetFirst_416EA0();
	if (v7) {
		do {
			if (v7[2096]) {
				if (v0) {
					strcat(v15, v7 + 2096);
					v0 = 0;
				} else {
					*(uint16_t*)&v15[strlen(v15)] = *getMemU16Ptr(0x587000, 58120);
					strcat(v15, v7 + 2096);
				}
			}
			v7 = nox_common_playerInfoGetNext_416EE0((int)v7);
		} while (v7);
		if (!v0) {
			v8 = sub_4200E0();
			abort();
		}
	}
	return v11;
}

//----- (0041DA10) --------------------------------------------------------
int sub_41DA10(int a1) {
	uint16_t* v1;   // edi
	int result = 0; // eax

	v1 = *(uint16_t**)getMemAt(0x587000, 58132 + 16 * a1);
	if (v1) {
		result = 0;
		memset(v1, 0, 0x2Cu);
		v1[22] = 0;
		*getMemU32Ptr(0x587000, 58136 + 16 * a1) = 0;
	}
	return result;
}

//----- (0041DA70) --------------------------------------------------------
int sub_41DA70(int a1, short a2) {
	int result; // eax
	int v3;     // ecx
	int v4;     // edx

	result = 16 * a1;
	v3 = *getMemU32Ptr(0x587000, 58132 + 16 * a1);
	if (v3 && (v4 = *getMemU32Ptr(0x587000, 58136 + 16 * a1), v4 < 23)) {
		*(uint16_t*)(v3 + 2 * v4) = a2;
		++*getMemU32Ptr(0x587000, 58136 + 16 * a1);
	} else {
		result = sub_41E300(11);
		if (result) {
			dword_5d4594_2660652 = 0;
		}
	}
	return result;
}

//----- (0041E2F0) --------------------------------------------------------
int sub_41E2F0() { return dword_5d4594_527988; }

//----- (0041E370) --------------------------------------------------------
int sub_41E370() {
	int result; // eax

	result = 0;
	dword_5d4594_528252 = 0;
	dword_5d4594_528256 = 0;
	dword_5d4594_528260 = 0;
	dword_5d4594_528264 = 0;
	return result;
}

//----- (0041E390) --------------------------------------------------------
int nox_xxx_reconAttempt_41E390() {
	int result; // eax

	if (gameFrame() - dword_5d4594_528264 <= (unsigned int)(3600 * gameFPS())) {
		result = dword_5d4594_528252;
		if (dword_5d4594_528252) {
			result = dword_5d4594_528256;
			if (!dword_5d4594_528256) {
				nox_xxx_networkLog_printf_413D30("RECON: Attempting to re-login");
				sub_40E090();
				result = nox_xxx_officialStringCmp_41FDE0();
				if (result == 1) {
					dword_5d4594_528256 = 1;
				} else {
					result = sub_41E470();
				}
			}
		}
	} else {
		sub_41E370();
		result = sub_41E4B0(1);
	}
	return result;
}

//----- (0041E400) --------------------------------------------------------
void nox_xxx_reconStart_41E400() {
	if (dword_5d4594_528252 != 1 && dword_5d4594_528256 != 1) {
		if (!dword_5d4594_528260) {
			if (!dword_5d4594_528264) {
				nox_xxx_networkLog_printf_413D30("RECON: Starting reconnection process frame (%d)",
												 gameFrame());
				dword_5d4594_528252 = 1;
				dword_5d4594_528256 = 0;
				dword_5d4594_528264 = gameFrame();
				dword_5d4594_528260 = gameFrame() + 120 * gameFPS();
			}
		}
	}
}

//----- (0041E470) --------------------------------------------------------
int sub_41E470() {
	int result; // eax

	nox_xxx_networkLog_printf_413D30("RECON: TryReconnectAgain called on frame (%d)", gameFrame());
	dword_5d4594_528256 = 0;
	result = gameFrame() + 120 * gameFPS();
	dword_5d4594_528260 = gameFrame() + 120 * gameFPS();
	return result;
}

//----- (0041E4B0) --------------------------------------------------------
int sub_41E4B0(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 528268) = a1;
	return result;
}

//----- (0041EC30) --------------------------------------------------------
int sub_41EC30() {
	uint32_t* v0; // ebx
	int v1;       // esi
	int v2;       // edi
	int result;   // eax
	int v4;       // eax

	v0 = *(uint32_t**)&dword_5d4594_529316;
	dword_5d4594_529332 = 0;
	dword_5d4594_529336 = 0;
	if (dword_5d4594_529316) {
		do {
			v1 = v0[7];
			if (v1) {
				do {
					v2 = *(uint32_t*)(v1 + 40);
					if (*(uint32_t*)v1) {
						free(*(void**)v1);
					}
					free((void*)v1);
					v1 = v2;
				} while (v2);
			}
			v0[7] = 0;
			v0[8] = 0;
			v0[6] = 0;
			v0 = (uint32_t*)v0[9];
		} while (v0);
	}
	result = sub_41E2F0();
	if (result == 7) {
		v4 = sub_41E2F0();
		result = sub_41DA70(v4, 10);
	}
	dword_5d4594_529340 = 0;
	return result;
}

//----- (0041F4B0) --------------------------------------------------------
int sub_41F4B0() {
	int v0;     // esi
	int v1;     // edi
	int result; // eax
	int v3;     // eax

	v0 = dword_5d4594_531648;
	if (dword_5d4594_531648) {
		do {
			v1 = *(uint32_t*)(v0 + 20);
			if (*(uint32_t*)v0) {
				free(*(void**)v0);
			}
			free((void*)v0);
			v0 = v1;
		} while (v1);
	}
	dword_5d4594_531648 = 0;
	dword_5d4594_531652 = 0;
	dword_5d4594_531656 = 0;
	result = sub_41E2F0();
	if (result == 7) {
		v3 = sub_41E2F0();
		result = sub_41DA70(v3, 11);
	}
	return result;
}

//----- (0041F790) --------------------------------------------------------
uint32_t* sub_41F790(const char* a1) {
	uint32_t* v1; // edi

	v1 = *(uint32_t**)&dword_5d4594_531648;
	if (!a1 || !dword_5d4594_531648) {
		return 0;
	}
	while (strcmp((const char*)(*v1 + 36), a1)) {
		v1 = (uint32_t*)v1[5];
		if (!v1) {
			return 0;
		}
	}
	return v1;
}

//----- (0041F800) --------------------------------------------------------
int sub_41F800(const char* a1) {
	int* v1;    // eax
	int result; // eax

	v1 = sub_41F790(a1);
	if (v1) {
		result = *v1;
	} else {
		result = 0;
	}
	return result;
}

//----- (0041FA40) --------------------------------------------------------
char* sub_41FA40() { return (char*)getMemAt(0x5D4594, 534756); }

//----- (0041FA50) --------------------------------------------------------
void sub_41FA50(const char* a1) {
	if (a1) {
		strcpy((char*)getMemAt(0x5D4594, 534756), a1);
	}
}

//----- (0041FBE0) --------------------------------------------------------
int sub_41FBE0(uint32_t* a1, uint32_t* a2) {
	int result; // eax

	if (*(int*)&dword_587000_60044 == -1) {
		return 0;
	}
	*a1 = getMemAt(0x5D4594, 531660 + 24 * dword_587000_60044);
	result = 1;
	*a2 = getMemAt(0x5D4594, 531670 + 24 * dword_587000_60044);
	return result;
}

//----- (0041FDE0) --------------------------------------------------------
int nox_xxx_officialStringCmp_41FDE0() {
	int v0;         // ebx
	size_t v1;      // eax
	const char* v3; // [esp+8h] [ebp-8h]
	const char* v4; // [esp+Ch] [ebp-4h]

	memset(getMemAt(0x85B3FC, 10308), 0, 0x6Cu);
	if (sub_41FBE0(&v3, &v4) != 1) {
		return 0;
	}
	v0 = sub_4207E0();
	if (v0) {
		strcpy((char*)(v0 + 228), v3);
		strcpy((char*)(v0 + 238), v4);
		sub_41FA50(v3);
		v1 = strcspn((const char*)(v0 + 24), ":");
		if (!strncmp("Official", (const char*)(v1 + v0 + 25), 8u)) {
			nox_xxx_setGameFlags_40A4D0(0x1000000);
		} else {
			nox_common_gameFlags_unset_40A540(0x1000000);
		}
	}
	return 1;
}

//----- (004200E0) --------------------------------------------------------
int sub_4200E0() { return *getMemU32Ptr(0x587000, 60072); }

//----- (00420100) --------------------------------------------------------
int sub_420100() { return *getMemU32Ptr(0x587000, 60072) >> 8; }

//----- (00420230) --------------------------------------------------------
int sub_420230(char* a1, uint16_t* a2) {
	int v2;       // ebx
	char* v3;     // eax
	char* v4;     // eax
	char v6[128]; // [esp+10h] [ebp-80h]

	if (!a1) {
		return 0;
	}
	if (!a2) {
		return 0;
	}
	v2 = dword_5d4594_534808;
	if (!dword_5d4594_534808) {
		return 0;
	}
	while (1) {
		if (!nox_strcmpi((const char*)(v2 + 95), "LAD")) {
			strcpy(v6, (const char*)(v2 + 100));
			*a1 = 0;
			*a2 = 0;
			strtok(v6, ";");
			v3 = strtok(0, ";");
			if (v3) {
				strcpy(a1, v3);
			}
			v4 = strtok(0, ";");
			if (v4) {
				*a2 = atoi(v4);
			}
			if (*a1 && *a2) {
				break;
			}
		}
		v2 = *(uint32_t*)(v2 + 20);
		if (!v2) {
			return 0;
		}
	}
	return 1;
}

//----- (00420360) --------------------------------------------------------
int sub_420360(char* a1, uint16_t* a2) {
	int v2;       // ebx
	char* v3;     // eax
	char* v4;     // eax
	char* v5;     // eax
	char v7[128]; // [esp+10h] [ebp-80h]

	if (!a1) {
		return 0;
	}
	if (!a2) {
		return 0;
	}
	*a1 = 0;
	*a2 = 0;
	v2 = dword_5d4594_534808;
	if (!dword_5d4594_534808) {
		return 0;
	}
	while (1) {
		if (!nox_strcmpi((const char*)(v2 + 95), "GAM")) {
			if (nox_common_gameFlags_check_40A5C0(4096)) {
				if (!nox_strcmpi((const char*)(v2 + 24), "Quest gameres server")) {
					strcpy(v7, (const char*)(v2 + 100));
					*a1 = 0;
					*a2 = 0;
					strtok(v7, ";");
					v3 = strtok(0, ";");
					if (v3) {
						strcpy(a1, v3);
					}
					v4 = strtok(0, ";");
					if (v4) {
						*a2 = atoi(v4);
					}
				}
			} else {
				if (!nox_common_gameFlags_check_40A5C0(0x2000)) {
					return 0;
				}
				if (!nox_strcmpi((const char*)(v2 + 24), "Gameres server")) {
					strcpy(v7, (const char*)(v2 + 100));
					*a1 = 0;
					*a2 = 0;
					strtok(v7, ";");
					v5 = strtok(0, ";");
					if (v5) {
						strcpy(a1, v5);
					}
					v4 = strtok(0, ";");
					if (v4) {
						*a2 = atoi(v4);
					}
				}
			}
			if (*a1 && *a2) {
				return 1;
			}
		}
		v2 = *(uint32_t*)(v2 + 20);
		if (!v2) {
			return 0;
		}
	}
}

//----- (004207E0) --------------------------------------------------------
int sub_4207E0() { return *getMemU32Ptr(0x5D4594, 534812); }

//----- (00420C40) --------------------------------------------------------
uint32_t* sub_420C40(int a1, int a2) {
	uint32_t* result; // eax

	result = calloc(1, 0xCu);
	if (result) {
		*result = a1;
		result[1] = a2;
		result[2] = dword_5d4594_588068;
		dword_5d4594_588068 = result;
	}
	return result;
}

//----- (00420C70) --------------------------------------------------------
uint32_t* sub_420C70() {
	uint32_t* result; // eax
	uint32_t* v1;     // esi

	result = *(uint32_t**)&dword_5d4594_588068;
	if (dword_5d4594_588068) {
		do {
			v1 = (uint32_t*)result[2];
			free(result);
			result = v1;
		} while (v1);
		dword_5d4594_588068 = 0;
	} else {
		dword_5d4594_588068 = 0;
	}
	return result;
}

//----- (00420CA0) --------------------------------------------------------
char* nox_xxx_polygon_420CA0() {
	int v0;           // eax
	unsigned char* i; // ecx

	v0 = 1;
	if (nox_xxx_polygonNextAngle_587000_60356 <= 1u) {
		return 0;
	}
	for (i = getMemAt(0x5D4594, 535872); !*(uint32_t*)i; i += 16) {
		if ((unsigned int)++v0 >= *(int*)&nox_xxx_polygonNextAngle_587000_60356) {
			return 0;
		}
	}
	return (char*)getMemAt(0x5D4594, 535844 + 16 * v0);
}

//----- (00420CD0) --------------------------------------------------------
char* nox_xxx_polygon_420CD0(uint32_t* a1) {
	unsigned int v1;  // eax
	unsigned char* i; // ecx

	v1 = *a1 + 1;
	if (v1 >= *(int*)&nox_xxx_polygonNextAngle_587000_60356) {
		return 0;
	}
	for (i = getMemAt(0x5D4594, 535856 + 16 * v1); !*(uint32_t*)i; i += 16) {
		if (++v1 >= *(int*)&nox_xxx_polygonNextAngle_587000_60356) {
			return 0;
		}
	}
	return (char*)getMemAt(0x5D4594, 535844 + 16 * v1);
}

//----- (00420D10) --------------------------------------------------------
int sub_420D10() {
	int result;       // eax
	unsigned char* i; // ecx

	result = 1;
	if (nox_xxx_polygonNextAngle_587000_60356 <= 1u) {
		return (nox_xxx_polygonNextAngle_587000_60356)++;
	}
	for (i = getMemAt(0x5D4594, 535872); *(uint32_t*)i; i += 16) {
		if ((unsigned int)++result >= *(int*)&nox_xxx_polygonNextAngle_587000_60356) {
			return (nox_xxx_polygonNextAngle_587000_60356)++;
		}
	}
	return result;
}

//----- (00420D40) --------------------------------------------------------
unsigned int* nox_xxx_polygonSetAngle_420D40(int a1, int a2, unsigned int a3, int a4) {
	bool v4;              // cf
	unsigned int* result; // eax

	if (a4) {
		sub_420C40(a3, a4);
	}
	v4 = a3 < *(int*)&nox_xxx_polygonNextAngle_587000_60356;
	result = getMemUintPtr(0x5D4594, 535844 + 16 * a3);
	*result = a3;
	if (!v4) {
		nox_xxx_polygonNextAngle_587000_60356 = a3 + 1;
	}
	*getMemU32Ptr(0x5D4594, 535848 + 16 * a3) = a1;
	*getMemU32Ptr(0x5D4594, 535852 + 16 * a3) = a2;
	*getMemU32Ptr(0x5D4594, 535856 + 16 * a3) = 1;
	return result;
}

//----- (00420DA0) --------------------------------------------------------
unsigned int* sub_420DA0(float a1, float a2) {
	int* v2;              // eax
	int* v3;              // ebx
	int v4;               // eax
	unsigned int* result; // eax
	int v6;               // edx
	int v7;               // ecx
	int v8;               // ecx
	int v9;               // eax
	int2 v10;             // [esp+Ch] [ebp-8h]

	v10.field_0 = nox_float2int(a1);
	v10.field_4 = nox_float2int(a2);
	if (nox_common_gameFlags_check_40A5C0(0x200000) && (v2 = (int*)sub_420E80(a1, a2, 900.0), (v3 = v2) != 0)) {
		if (!sub_421B40(v2)) {
			v8 = *v3;
			v9 = *getMemU16Ptr(0x5D4594, 588072);
			++*getMemU16Ptr(0x5D4594, 588072);
			*getMemU32Ptr(0x5D4594, 534820 + 4 * v9) = v8;
		}
	} else if (!nox_common_gameFlags_check_40A5C0(0x200000) || !nox_xxx_polygonIsPlayerInPolygon_4217B0(&v10, 0)) {
		v4 = sub_420D10();
		result = nox_xxx_polygonSetAngle_420D40(SLODWORD(a1), SLODWORD(a2), v4, 0);
		v6 = *result;
		v7 = *getMemU16Ptr(0x5D4594, 588072);
		++*getMemU16Ptr(0x5D4594, 588072);
		*getMemU32Ptr(0x5D4594, 534820 + 4 * v7) = v6;
		return result;
	}
	return 0;
}

//----- (00420E80) --------------------------------------------------------
int sub_420E80(float a1, float a2, float a3) {
	int v3;            // esi
	unsigned char* v4; // ecx
	int v5;            // edx
	double v6;         // st6
	double v7;         // st5

	v3 = 0;
	if (nox_xxx_polygonNextAngle_587000_60356 > 1u) {
		v4 = getMemAt(0x5D4594, 535864);
		v5 = nox_xxx_polygonNextAngle_587000_60356 - 1;
		do {
			if (*((uint32_t*)v4 + 2)) {
				v6 = *((float*)v4 + 1) - a2;
				v7 = v6 * v6 + (*(float*)v4 - a1) * (*(float*)v4 - a1);
				if (v7 < a3) {
					a3 = v7;
					v3 = (int)(v4 - 4);
				}
			}
			v4 += 16;
			--v5;
		} while (v5);
	}
	return v3;
}

//----- (00421430) --------------------------------------------------------
void* sub_421430() {
	unsigned char* v0; // esi
	void* result;      // eax

	v0 = getMemAt(0x5D4594, 552476);
	for (int i = 0; i < 255; i++) {
		if (*((uint32_t*)v0 - 27)) {
			if (*getMemU32Ptr(0x5D4594, 588076)) {
				free(*((void**)v0 - 27));
			}
			*((uint32_t*)v0 - 27) = 0;
		}
		result = *(void**)v0;
		if (*(uint32_t*)v0) {
			if (*getMemU32Ptr(0x5D4594, 588076)) {
				free(*(void**)v0);
			}
			*(uint32_t*)v0 = 0;
		}
		*((uint16_t*)v0 + 10) = 0;
		*((uint32_t*)v0 - 7) = 0;
		*((uint32_t*)v0 + 2) = -1;
		*((uint32_t*)v0 + 4) = -1;
		*((uint32_t*)v0 - 6) = 0;
		v0 += 140;
	}
	nox_xxx_polygonNextIdx_587000_60352 = 1;
	return result;
}

//----- (00421010) --------------------------------------------------------
char* sub_421010() {
	char* result; // eax

	result = (char*)getMemAt(0x5D4594, 535872);
	do {
		*(uint32_t*)result = 0;
		result += 16;
	} while ((int)result < (int)getMemAt(0x5D4594, 552240));
	nox_xxx_polygonNextAngle_587000_60356 = 1;
	return result;
}

//----- (00421030) --------------------------------------------------------
char* nox_xxx_polygonGetAngle_421030(int a1) { return (char*)getMemAt(0x5D4594, 535844 + 16 * a1); }

//----- (00421040) --------------------------------------------------------
void sub_421040(int a1) {
	int v1;       // esi
	uint32_t* v2; // ebx
	uint32_t* v3; // eax
	int v4;       // ecx
	int v5;       // edx
	uint32_t* v6; // ecx

	v1 = 0;
	if (*(uint16_t*)(a1 + 128)) {
		v2 = *(uint32_t**)&dword_5d4594_588068;
		do {
			v3 = v2;
			if (v2) {
				v4 = *(uint32_t*)(a1 + 108);
				v5 = *(uint32_t*)(v4 + 4 * v1);
				v6 = (uint32_t*)(v4 + 4 * v1);
				while (v5 != v3[1]) {
					v3 = (uint32_t*)v3[2];
					if (!v3) {
						goto LABEL_9;
					}
				}
				*v6 = *v3;
				v2 = *(uint32_t**)&dword_5d4594_588068;
			}
		LABEL_9:
			++v1;
		} while (v1 < *(unsigned short*)(a1 + 128));
	}
}

//----- (004210A0) --------------------------------------------------------
char* nox_xxx_polygonGetNext_4210A0() {
	int v0;           // eax
	unsigned char* i; // ecx

	v0 = 1;
	if (nox_xxx_polygonNextIdx_587000_60352 <= 1u) {
		return 0;
	}
	for (i = getMemAt(0x5D4594, 552452); !*(uint32_t*)i; i += 140) {
		if ((unsigned int)++v0 >= *(int*)&nox_xxx_polygonNextIdx_587000_60352) {
			return 0;
		}
	}
	return (char*)getMemAt(0x5D4594, 552228 + 140 * v0);
}

//----- (004210E0) --------------------------------------------------------
char* sub_4210E0(int a1) {
	unsigned int v1;  // eax
	unsigned char* i; // ecx

	v1 = *(uint32_t*)(a1 + 80) + 1;
	if (v1 >= *(int*)&nox_xxx_polygonNextIdx_587000_60352) {
		return 0;
	}
	for (i = getMemAt(0x5D4594, 552312 + 140 * v1); !*(uint32_t*)i; i += 140) {
		if (++v1 >= *(int*)&nox_xxx_polygonNextIdx_587000_60352) {
			return 0;
		}
	}
	return (char*)getMemAt(0x5D4594, 552228 + 140 * v1);
}

//----- (00421130) --------------------------------------------------------
int sub_421130() {
	int result;       // eax
	unsigned char* i; // ecx

	result = 1;
	if (nox_xxx_polygonNextIdx_587000_60352 <= 1u) {
		return (nox_xxx_polygonNextIdx_587000_60352)++;
	}
	for (i = getMemAt(0x5D4594, 552452); *(uint32_t*)i; i += 140) {
		if ((unsigned int)++result >= *(int*)&nox_xxx_polygonNextIdx_587000_60352) {
			return (nox_xxx_polygonNextIdx_587000_60352)++;
		}
	}
	return result;
}

//----- (00421160) --------------------------------------------------------
int sub_421160(int a1) {
	int result; // eax

	strcpy((char*)(a1 + 4), (const char*)getMemAt(0x587000, 60364));
	*(uint8_t*)(a1 + 104) = getMemByte(0x587000, 60464);
	*(uint8_t*)(a1 + 105) = getMemByte(0x587000, 60465);
	*(uint8_t*)(a1 + 106) = getMemByte(0x587000, 60466);
	*(uint8_t*)(a1 + 130) = getMemByte(0x587000, 60490);
	result = 0;
	*(uint32_t*)(a1 + 132) = 0;
	*(uint32_t*)(a1 + 136) = 0;
	return result;
}

//----- (004211D0) --------------------------------------------------------
int sub_4211D0(int a1) {
	int result; // eax

	strcpy((char*)getMemAt(0x587000, 60364), (const char*)(a1 + 4));
	*getMemU8Ptr(0x587000, 60464) = *(uint8_t*)(a1 + 104);
	*getMemU8Ptr(0x587000, 60465) = *(uint8_t*)(a1 + 105);
	*getMemU8Ptr(0x587000, 60466) = *(uint8_t*)(a1 + 106);
	*getMemU8Ptr(0x587000, 60490) = *(uint8_t*)(a1 + 130);
	result = 0;
	*(uint32_t*)(a1 + 132) = 0;
	*(uint32_t*)(a1 + 136) = 0;
	return result;
}

//----- (00421230) --------------------------------------------------------
unsigned char* sub_421230() {
	int v0;            // edi
	unsigned char* v1; // esi
	uint8_t* v2;       // eax

	v0 = sub_421130();
	v1 = getMemAt(0x5D4594, 552228 + 140 * v0);
	*(uint32_t*)v1 = 0;
	if (nox_common_gameFlags_check_40A5C0(0x200000)) {
		v2 = calloc(1u, 0x100u);
		*(uint32_t*)v1 = v2;
		if (!v2) {
			free(v1);
			return 0;
		}
		*v2 = 0;
		*(uint8_t*)(*(uint32_t*)v1 + 128) = 0;
	}
	*((uint32_t*)v1 + 20) = v0;
	nox_itoa(v0, (char*)v1 + 4, 10);
	sub_421160((int)v1);
	*((uint32_t*)v1 + 21) = 1;
	return getMemAt(0x5D4594, 552228 + 140 * v0);
}

//----- (004214A0) --------------------------------------------------------
char* nox_xxx_polygonGetByIdx_4214A0(int a1) {
	char* result; // eax

	if (a1 == -559023410) {
		result = 0;
	} else {
		result = (char*)getMemAt(0x5D4594, 552228 + 140 * a1);
	}
	return result;
}

//----- (004214D0) --------------------------------------------------------
void sub_4214D0() {
	unsigned char* v0; // esi
	int v1;            // eax
	unsigned char* v2; // edi
	int v3;            // eax
	int v4;            // ebx
	bool v5;           // cc
	unsigned char* v6; // edi

	if (*getMemU16Ptr(0x5D4594, 588072) >= 3u) {
		v0 = sub_421230();
		if (v0) {
			*((uint32_t*)v0 + 27) = calloc(*getMemU16Ptr(0x5D4594, 588072), 4u);
			v1 = 0;
			*((uint16_t*)v0 + 64) = *getMemU16Ptr(0x5D4594, 588072);
			if (*getMemU16Ptr(0x5D4594, 588072)) {
				do {
					*(uint32_t*)(*((uint32_t*)v0 + 27) + 4 * v1) = *getMemU32Ptr(0x5D4594, 534820 + 4 * v1);
					++v1;
				} while (v1 < *getMemU16Ptr(0x5D4594, 588072));
			}
			v2 = getMemAt(0x5D4594, 535844 + 16 * **((uint32_t**)v0 + 27));
			*((uint32_t*)v0 + 22) = nox_float2int(*((float*)v2 + 1));
			*((uint32_t*)v0 + 23) = nox_float2int(*((float*)v2 + 2));
			*((uint32_t*)v0 + 24) = nox_float2int(*((float*)v2 + 1));
			v3 = nox_float2int(*((float*)v2 + 2));
			v4 = 1;
			v5 = *((uint16_t*)v0 + 64) <= 1u;
			*((uint32_t*)v0 + 25) = v3;
			if (!v5) {
				do {
					v6 = getMemAt(0x5D4594, 535844 + 16 * *(uint32_t*)(*((uint32_t*)v0 + 27) + 4 * v4));
					if (*((float*)v6 + 1) >= (double)*((int*)v0 + 22)) {
						if (*((float*)v6 + 1) > (double)*((int*)v0 + 24)) {
							*((uint32_t*)v0 + 24) = nox_float2int(*((float*)v6 + 1));
						}
					} else {
						*((uint32_t*)v0 + 22) = nox_float2int(*((float*)v6 + 1));
					}
					if (*((float*)v6 + 2) >= (double)*((int*)v0 + 23)) {
						if (*((float*)v6 + 2) > (double)*((int*)v0 + 25)) {
							*((uint32_t*)v0 + 25) = nox_float2int(*((float*)v6 + 2));
						}
					} else {
						*((uint32_t*)v0 + 23) = nox_float2int(*((float*)v6 + 2));
					}
					++v4;
				} while (v4 < *((unsigned short*)v0 + 64));
			}
			*getMemU16Ptr(0x5D4594, 588072) = 0;
		}
	}
}

//----- (00421660) --------------------------------------------------------
int nox_xxx_polygon_421660(int* a1, int a2) {
	char v2;            // bp
	int v4;             // edx
	int v5;             // ecx
	uint32_t* v6;       // edx
	unsigned char* v7;  // esi
	int v8;             // eax
	unsigned short v9;  // cx
	unsigned short v10; // bx
	unsigned char* v11; // esi
	int4 v12 = {0};     // [esp+8h] [ebp-20h]
	int4 v16;           // [esp+18h] [ebp-10h]

	v2 = 0;
	if (!a2) {
		return 0;
	}
	v4 = a1[1];
	v16.field_0 = *a1;
	v16.field_4 = v4;
	v5 = (getMemByte(0x5D4594, 588080) & 2) != 0 ? 0x1700 : 0;
	++*getMemU32Ptr(0x5D4594, 588080);
	v6 = *(uint32_t**)(a2 + 108);
	v16.field_8 = v5;
	v16.field_C = (getMemByte(0x5D4594, 588080) & 2) != 0 ? 0x1700 : 0;
	v7 = getMemAt(0x5D4594, 535844 + 16 * *v6);
	v12.field_0 = nox_float2int(*((float*)v7 + 1));
	v8 = nox_float2int(*((float*)v7 + 2));
	v9 = *(uint16_t*)(a2 + 128);
	v10 = 1;
	for (v12.field_4 = v8; v10 <= v9; ++v10) {
		v11 = getMemAt(0x5D4594, 535844 + 16 * *(uint32_t*)(*(uint32_t*)(a2 + 108) + 4 * (v10 % (int)v9)));
		if (v10 & 1) {
			v12.field_8 = nox_float2int(*((float*)v11 + 1));
			v12.field_C = nox_float2int(*((float*)v11 + 2));
		} else {
			v12.field_0 = nox_float2int(*((float*)v11 + 1));
			v12.field_4 = nox_float2int(*((float*)v11 + 2));
		}
		if (sub_427C80(&v16, &v12)) {
			++v2;
		}
		v9 = *(uint16_t*)(a2 + 128);
	}
	return v2 & 1;
}

//----- (00421790) --------------------------------------------------------
int nox_xxx_polygonGetIdxA_421790(int2* a1, int a2) {
	nox_player_polygon_check_data* v2; // eax
	int result;                        // eax

	v2 = nox_xxx_polygonIsPlayerInPolygon_4217B0(a1, a2);
	if (v2) {
		result = v2->field_0[20];
	} else {
		result = 0;
	}
	return result;
}

//----- (004217B0) --------------------------------------------------------
nox_player_polygon_check_data* nox_xxx_polygonIsPlayerInPolygon_4217B0(int2* a1, int a2) {
	int v2;           // eax
	int v4;           // edi
	unsigned char* i; // esi
	int v6;           // eax

	if (a2) {
		if (a2 != -559023410) {
			if (*getMemU32Ptr(0x5D4594, 552312 + 140 * a2)) {
				v2 = nox_xxx_pointInRect_4281F0(a1, (int4*)getMemAt(0x5D4594, 552316 + 140 * a2));
				if (v2) {
					if (nox_xxx_polygon_421660(&a1->field_0, (int)getMemAt(0x5D4594, 552228 + 140 * a2))) {
						return (nox_player_polygon_check_data*)getMemAt(0x5D4594, 552228 + 140 * a2);
					}
				}
			}
		}
	}
	v4 = 1;
	if (nox_xxx_polygonNextIdx_587000_60352 <= 1u) {
		return 0;
	}
	for (i = getMemAt(0x5D4594, 552448);; i += 140) {
		if (*((uint32_t*)i + 1)) {
			if (*(uint32_t*)i != a2) {
				v6 = nox_xxx_pointInRect_4281F0(a1, (int4*)(i + 8));
				if (v6) {
					if (nox_xxx_polygon_421660(&a1->field_0, (int)(i - 80))) {
						break;
					}
				}
			}
		}
		if ((unsigned int)++v4 >= *(int*)&nox_xxx_polygonNextIdx_587000_60352) {
			return 0;
		}
	}
	return (nox_player_polygon_check_data*)(i - 80);
}
// 4217F5: variable 'v2' is possibly undefined
// 421840: variable 'v6' is possibly undefined

//----- (00421880) --------------------------------------------------------
int sub_421880(int a1, int a2, float a3) {
	unsigned char* v3; // esi
	int v4;            // eax
	int v5;            // ebx
	int v6;            // ecx
	unsigned char* v7; // esi
	int4 v9 = {0};     // [esp+10h] [ebp-10h]

	v3 = getMemAt(0x5D4594, 535844 + 16 * **(uint32_t**)(a2 + 108));
	v9.field_0 = nox_float2int(*((float*)v3 + 1));
	v4 = nox_float2int(*((float*)v3 + 2));
	v5 = 1;
	v6 = *(unsigned short*)(a2 + 128);
	v9.field_4 = v4;
	if ((int)(unsigned short)v6 < 1) {
		return 0;
	}
	while (1) {
		v7 = getMemAt(0x5D4594, 535844 + 16 * *(uint32_t*)(*(uint32_t*)(a2 + 108) + 4 * (v5 % v6)));
		if (v5 & 1) {
			v9.field_8 = nox_float2int(*((float*)v7 + 1));
			v9.field_C = nox_float2int(*((float*)v7 + 2));
		} else {
			v9.field_0 = nox_float2int(*((float*)v7 + 1));
			v9.field_4 = nox_float2int(*((float*)v7 + 2));
		}
		if (sub_427DF0(a1, &v9, a3)) {
			break;
		}
		++v5;
		v6 = *(unsigned short*)(a2 + 128);
		if (v5 > (unsigned short)v6) {
			return 0;
		}
	}
	return 1;
}

//----- (00421990) --------------------------------------------------------
int* sub_421990(int2* a1, float a2, int a3) {
	int* i; // esi
	int v5; // edi

	if (a3) {
		if (a3 != -559023410) {
			i = getMemIntPtr(0x5D4594, 552228 + 140 * a3);
			if (*getMemU32Ptr(0x5D4594, 552312 + 140 * a3)) {
				if (sub_421880((int)a1, (int)getMemAt(0x5D4594, 552228 + 140 * a3), a2)) {
					return i;
				}
			}
		}
	}
	v5 = 1;
	if (nox_xxx_polygonNextIdx_587000_60352 > 1u) {
		for (i = getMemIntPtr(0x5D4594, 552368); !i[21] || i[20] == a3 || !sub_421880((int)a1, (int)i, a2); i += 35) {
			if ((unsigned int)++v5 >= *(int*)&nox_xxx_polygonNextIdx_587000_60352) {
				return 0;
			}
		}
		return i;
	}
	return 0;
}

//----- (00421B10) --------------------------------------------------------
uint32_t* sub_421B10() {
	uint32_t* result; // eax

	sub_421430();
	sub_421010();
	result = sub_420C70();
	*getMemU32Ptr(0x5D4594, 588076) = 1;
	*getMemU16Ptr(0x5D4594, 588072) = 0;
	return result;
}

//----- (00421B40) --------------------------------------------------------
int sub_421B40(uint32_t* a1) {
	int v1;           // eax
	unsigned char* i; // ecx

	v1 = 0;
	if ((int)*getMemU16Ptr(0x5D4594, 588072) <= 0) {
		return 0;
	}
	for (i = getMemAt(0x5D4594, 534820); *(uint32_t*)i != *a1; i += 4) {
		if (++v1 >= *getMemU16Ptr(0x5D4594, 588072)) {
			return 0;
		}
	}
	return 1;
}

//----- (00421B80) --------------------------------------------------------
void nox_xxx_polygonDrawColor_421B80() {
	int v0;                            // esi
	char* v1;                          // eax
	char* v2;                          // esi
	nox_player_polygon_check_data* v3; // eax
	char* v4;                          // eax
	int2 v5;                           // [esp+4h] [ebp-10h]
	int2 v6;                           // [esp+Ch] [ebp-8h]

	v0 = *getMemU32Ptr(0x852978, 8);
	if (!v0) {
		return;
	}
	nox_xxx_getSomeCoods_435670(&v5);
	sub_435690(&v6);
	v1 = nox_common_playerInfoGetByID_417040(*(uint32_t*)(v0 + 128));
	v2 = v1;
	if (!v1) {
		return;
	}
	if (nox_xxx_polygonNextIdx_587000_60352 > 1u) {
		if (!(*((int*)v1 + 915) == -559023410 || v5.field_0 != v6.field_0 || v5.field_4 != v6.field_4)) {
			return;
		}
		v3 = nox_xxx_polygonIsPlayerInPolygon_4217B0(&v5, *((uint32_t*)v1 + 915));
		if (v3) {
			if (*((uint32_t*)v2 + 915) != v3->field_0[20]) {
				v2[3668] = BYTE2(v3->field_0[32]);
				*((uint32_t*)v2 + 915) = v3->field_0[20];
				sub_434990(LOBYTE(v3->field_0[26]), BYTE1(v3->field_0[26]), BYTE2(v3->field_0[26]));
			}
			return;
		}
	}
	v2[3668] = 1;
	*((uint32_t*)v2 + 915) = 0;
	v4 = nox_xxx_getAmbientColor_469BB0();
	sub_4349C0(v4);
}

//----- (00421C70) --------------------------------------------------------
void nox_xxx_questCheckSecretArea_421C70(nox_object_t* a1p) {
	int a1 = a1p;
	int v1;            // ebp
	int v2;            // eax
	float v3;          // edx
	unsigned char* v4; // esi
	int v5;            // ecx
	int v6;            // ecx
	int v7;            // ecx
	int i;             // edi
	int v9;            // eax
	int v10;           // eax
	int v11;           // eax
	int v12;           // ecx
	int2 v13;          // [esp+10h] [ebp-8h]

	if (!a1 || !(*(uint8_t*)(a1 + 8) & 4)) {
		return;
	}
	v1 = *(uint32_t*)(*(uint32_t*)(a1 + 748) + 276);
	if (*(uint8_t*)(v1 + 2064) == 31) {
		v11 = *(uint32_t*)(v1 + 3660);
		if (!v11) {
			*(uint32_t*)(v1 + 3664) = 0;
			goto LABEL_33;
		}
		if (v11 == -559023410) {
			goto LABEL_33;
		}
		v4 = getMemAt(0x5D4594, 552228 + 140 * v11);
	} else {
		if (*(int*)(v1 + 3664) != -559023410 && *(float*)(a1 + 56) == *(float*)(a1 + 72) &&
			*(float*)(a1 + 60) == *(float*)(a1 + 76)) {
			return;
		}
		v2 = nox_float2int(*(float*)(a1 + 56));
		v3 = *(float*)(a1 + 60);
		v13.field_0 = v2;
		v13.field_4 = nox_float2int(v3);
		v4 = (unsigned char*)nox_xxx_polygonIsPlayerInPolygon_4217B0(&v13, *(uint32_t*)(v1 + 3664));
		if (v4) {
			goto LABEL_12;
		}
		v5 = *(uint32_t*)(v1 + 3664);
		if (!v5 || v5 == -559023410) {
			goto LABEL_33;
		}
		v4 = getMemAt(0x5D4594, 552228 + 140 * v5);
	}
	if (!v4) {
		goto LABEL_33;
	} else {
		goto LABEL_12;
	}
LABEL_33:
	v12 = *(uint32_t*)(v1 + 3664);
	if (v12 && v12 != -559023410) {
		if (*getMemIntPtr(0x5D4594, 552352 + 140 * v12) != -1) {
			nox_xxx_scriptCallByEventBlock_502490(getMemIntPtr(0x5D4594, 552348 + 140 * v12), a1, 0, 27);
		}
		*(uint32_t*)(v1 + 3664) = 0;
		*(uint8_t*)(v1 + 3668) = 1;
	}
	return;
LABEL_12:
	v6 = *(uint32_t*)(v1 + 3664);
	if (v6 != *((uint32_t*)v4 + 20)) {
		if (v6 != -559023410) {
			if (v6) {
				v7 = 35 * v6;
				if (*getMemIntPtr(0x5D4594, 552352 + 4 * v7) != -1) {
					nox_xxx_scriptCallByEventBlock_502490(getMemIntPtr(0x5D4594, 552348 + 4 * v7), a1, 0, 29);
				}
			}
			if (!((1 << *(uint8_t*)(v1 + 2064)) & *((uint32_t*)v4 + 34)) && v4[132] & 1 &&
				nox_common_gameFlags_check_40A5C0(4096)) {
				sub_4D61F0(a1);
				nox_xxx_netPriMsgToPlayer_4DA2C0(a1, "GeneralPrint:SecretFound", 0);
				nox_xxx_aud_501960(904, a1, 0, 0);
				for (i = nox_xxx_getFirstPlayerUnit_4DA7C0(); i; i = nox_xxx_getNextPlayerUnit_4DA7F0(i)) {
					if (i != a1) {
						nox_xxx_netInformTextMsg_4DA0F0(
							*(unsigned char*)(*(uint32_t*)(*(uint32_t*)(i + 748) + 276) + 2064), 20,
							(int*)(a1 + 36));
					}
				}
				v9 = *((uint32_t*)v4 + 33);
				LOBYTE(v9) = v9 & 0xFE;
				*((uint32_t*)v4 + 33) = v9;
			}
			v10 = *((uint32_t*)v4 + 29);
			*((uint32_t*)v4 + 34) |= 1 << *(uint8_t*)(v1 + 2064);
			if (v10 != -1) {
				nox_xxx_scriptCallByEventBlock_502490((int*)v4 + 28, a1, 0, 28);
			}
		}
		*(uint32_t*)(v1 + 3664) = *((uint32_t*)v4 + 20);
		*(uint8_t*)(v1 + 3668) = v4[130];
	}
	return;
}

//----- (00421F10) --------------------------------------------------------
unsigned char* sub_421F10(int* a1, int a2) {
	unsigned char* v2; // esi
	int v3;            // eax
	int v5;            // edi
	unsigned char* i;  // esi
	int v7;            // eax

	if (a2) {
		if (a2 != 0xDEADFACE) {
			v2 = getMemAt(0x5D4594, 552228 + 140 * a2);
			if (*getMemU32Ptr(0x5D4594, 552312 + 140 * a2)) {
				if (*((int*)v2 + 29) != -1 || *((int*)v2 + 31) != -1) {
					v3 = nox_xxx_pointInRect_4281F0((int2*)a1, (int4*)(v2 + 88));
					if (v3) {
						if (nox_xxx_polygon_421660(a1, (int)getMemAt(0x5D4594, 552228 + 140 * a2))) {
							return getMemAt(0x5D4594, 552228 + 140 * a2);
						}
					}
				}
			}
		}
	}
	v5 = 1;
	if (nox_xxx_polygonNextIdx_587000_60352 <= 1u) {
		return 0;
	}
	for (i = getMemAt(0x5D4594, 552448);; i += 140) {
		if (*((uint32_t*)i + 1) && *(int*)i != a2 && (*((int*)i + 9) != -1 || *((int*)i + 11) != -1)) {
			v7 = nox_xxx_pointInRect_4281F0((int2*)a1, (int4*)(i + 8));
			if (v7) {
				if (nox_xxx_polygon_421660(a1, (int)(i - 80))) {
					break;
				}
			}
		}
		if ((unsigned int)++v5 >= *(int*)&nox_xxx_polygonNextIdx_587000_60352) {
			return 0;
		}
	}
	return i - 80;
}
// 421F64: variable 'v3' is possibly undefined
// 421FBE: variable 'v7' is possibly undefined

//----- (00421FF0) --------------------------------------------------------
void nox_xxx_monsterPolygonEnter_421FF0(nox_object_t* a1p) {
	int a1 = a1p;
	int* v1;           // ebp
	int v2;            // eax
	float v3;          // ecx
	uint32_t* v4;      // eax
	int v5;            // ecx
	uint32_t* v6;      // edi
	int v7;            // ecx
	int v8;            // ecx
	unsigned char* v9; // eax
	int2 v10;          // [esp+Ch] [ebp-8h]

	v1 = *(int**)(a1 + 748);
	if (a1 && *(uint8_t*)(a1 + 8) & 2 &&
		(*v1 == -559023410 || *(float*)(a1 + 56) != *(float*)(a1 + 72) || *(float*)(a1 + 60) != *(float*)(a1 + 76))) {
		v2 = nox_float2int(*(float*)(a1 + 56));
		v3 = *(float*)(a1 + 60);
		v10.field_0 = v2;
		v10.field_4 = nox_float2int(v3);
		if (*v1 == -559023410) {
			v4 = nox_xxx_polygonIsPlayerInPolygon_4217B0(&v10, 0);
		} else {
			v4 = sub_421F10(&v10.field_0, *v1);
		}
		v5 = *v1;
		v6 = v4;
		if (v4) {
			if (v5 != v4[20]) {
				if (v5 != -559023410) {
					if (v5) {
						v7 = 35 * v5;
						if (*getMemIntPtr(0x5D4594, 552352 + 4 * v7) != -1) {
							nox_xxx_scriptCallByEventBlock_502490(getMemIntPtr(0x5D4594, 552348 + 4 * v7), a1, 0, 26);
						}
					}
					if (v6[29] != -1) {
						nox_xxx_scriptCallByEventBlock_502490(v6 + 28, a1, 0, 25);
					}
				}
				*v1 = v6[20];
			}
		} else if (v5 && v5 != -559023410) {
			v8 = 35 * v5;
			v9 = getMemAt(0x5D4594, 552228 + 4 * v8);
			if (*getMemU32Ptr(0x5D4594, 552312 + 4 * v8) && *((int*)v9 + 31) != -1) {
				nox_xxx_scriptCallByEventBlock_502490((int*)v9 + 30, a1, 0, 24);
			}
			*v1 = 0;
		}
	}
}

//----- (00422140) --------------------------------------------------------
int sub_422140(int a1) {
	int result; // eax

	result = a1;
	if (a1) {
		*(uint32_t*)(a1 + 3660) = -559023410;
		*(uint32_t*)(a1 + 3664) = -559023410;
	}
	return result;
}

//----- (00422160) --------------------------------------------------------
int* nox_xxx_tileListAddNewSubtile_422160(int a1, int a2, int a3, int a4) {
	int* result; // eax
	char* v5;    // eax
	int i;       // ecx

	result = *(int**)&dword_5d4594_588084;
	if (!dword_5d4594_588084) {
		v5 = (char*)calloc(1, 0xC8u);
		dword_5d4594_588084 = v5;
		for (i = 0; i < 180; i += 20) {
			*(uint32_t*)&v5[i + 16] = &v5[i + 20];
			v5 = *(char**)&dword_5d4594_588084;
		}
		*(uint32_t*)(dword_5d4594_588084 + 196) = 0;
		result = *(int**)&dword_5d4594_588084;
	}
	dword_5d4594_588084 = result[4];
	*result = a1;
	result[1] = a2;
	result[2] = a3;
	result[3] = a4;
	result[4] = 0;
	return result;
}

//----- (004221E0) --------------------------------------------------------
int nox_xxx_tileFreeTileOne_4221E0(void* a1) {
	int result; // eax

	result = a1;
	*(uint32_t*)((uint32_t)a1 + 16) = dword_5d4594_588084;
	dword_5d4594_588084 = a1;
	return result;
}

//----- (00422200) --------------------------------------------------------
int nox_xxx_tileFreeTile_422200(int a1) {
	int result; // eax
	int v2;     // esi

	result = *(uint32_t*)(a1 + 16);
	if (result) {
		do {
			v2 = *(uint32_t*)(result + 16);
			nox_xxx_tileFreeTileOne_4221E0(result);
			result = v2;
		} while (v2);
		*(uint32_t*)(a1 + 16) = 0;
	} else {
		*(uint32_t*)(a1 + 16) = 0;
	}
	return result;
}

//----- (00422230) --------------------------------------------------------
int nox_server_mapRWFloorMap_422230(int a1) {
	int v2;             // ecx
	char v3;            // bl
	int v4;             // esi
	int l;              // edx
	uint32_t* v6;       // eax
	char v7;            // bl
	int v8;             // esi
	int m;              // edx
	int v10;            // ecx
	uint32_t* v11;      // eax
	char v12;           // bl
	int v13;            // edx
	uint8_t** v14;      // esi
	uint8_t* v15;       // ecx
	int v16;            // eax
	uint8_t** v17;      // esi
	int v18;            // ebp
	char v19;           // bl
	int n;              // edx
	uint8_t* v21;       // ecx
	int v22;            // eax
	int v23;            // edi
	int v24;            // eax
	int v25;            // esi
	int ii;             // ebx
	int v27;            // ecx
	unsigned short v28; // dx
	int v29;            // ecx
	int v30;            // eax
	uint8_t* v31;       // ecx
	uint8_t* v32;       // ecx
	int v33;            // ebx
	int v34;            // ebp
	char v35;           // al
	int v36;            // esi
	uint8_t* v37;       // eax
	uint8_t* v38;       // edi
	uint8_t* v39;       // eax
	unsigned short v40; // cx
	int v41;            // ebp
	int v42;            // esi
	unsigned short v43; // cx
	unsigned short k;   // cx
	short v47;          // bx
	int v48;            // esi
	int v49;            // edi
	int v50;            // eax
	int v51;            // ebx
	int v52;            // edi
	int v53;            // esi
	uint8_t* v54;       // eax
	uint8_t* v55;       // ecx
	int v56;            // edi
	int v58;            // esi
	int v59;            // [esp+10h] [ebp-40h]
	int v60;            // [esp+14h] [ebp-3Ch]
	int v61;            // [esp+18h] [ebp-38h]
	int v62;            // [esp+1Ch] [ebp-34h]
	int v63 = 0;        // [esp+20h] [ebp-30h]
	int v64 = 0;        // [esp+24h] [ebp-2Ch]
	int v65 = 0;        // [esp+28h] [ebp-28h]
	int v66;            // [esp+2Ch] [ebp-24h]
	int v67;            // [esp+30h] [ebp-20h]
	int v68;            // [esp+34h] [ebp-1Ch]
	int2 v69;           // [esp+38h] [ebp-18h]
	int4 v70;           // [esp+40h] [ebp-10h]

	v62 = 4;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v62, 2u);
	if ((short)v62 > 4) {
		return 0;
	}
	if ((short)v62 <= 3) {
		return nox_xxx_tile_422C10(v62, a1);
	}
	if (nox_crypt_IsReadOnly()) {
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v60, 4u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v61, 4u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v66, 4u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v67, 4u);
		if (a1) {
			sub_428170((uint32_t*)a1, &v70);
			v41 = v70.field_0 / 23 - v60;
			v42 = v70.field_4 / 23 - v61;
			a1 = v70.field_4 / 23 - v61;
			v61 = v70.field_4 / 23;
			v60 = v70.field_0 / 23;
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v59, 2u);
			v43 = v59;
			if ((uint16_t)v59 != (uint16_t)-1) {
				while (1) {
					v50 = v41 + (v43 >> 8);
					v51 = v42 + (unsigned char)v43;
					if (((uint8_t)v42 + (uint8_t)v43) & 1) {
						v56 = (23 * v50 - 23) / 46;
						v58 = (23 * v51 + 23) / 46;
						if (nox_common_gameFlags_check_40A5C0(0x400000)) {
							v54 = (uint8_t*)*nox_xxx_tileAllocTileInCoordList_5040A0(v56, v58, COERCE_FLOAT(1));
						} else {
							*(uint8_t*)(&ptr_5D4594_2650668[v56][v58].field_0) |= 0x1;
							v54 = (uint8_t*)(&ptr_5D4594_2650668[v56][v58].field_1);
						}
					} else {
						v52 = 23 * v50 / 46;
						v53 = 23 * v51 / 46;
						if (nox_common_gameFlags_check_40A5C0(0x400000)) {
							v54 =
								(uint8_t*)*nox_xxx_tileAllocTileInCoordList_5040A0(v52, 23 * v51 / 46, COERCE_FLOAT(2));
						} else {
							v55 = (uint8_t*)(&ptr_5D4594_2650668[v52][v53].field_0);
							*v55 |= 0x2;
							v54 = (uint8_t*)(&ptr_5D4594_2650668[v52][v53].field_6);
						}
					}
					nox_xxx_tileReadOne_422A40(v62, v54);
					nox_xxx_fileReadWrite_426AC0_file3_fread(&v59, 2u);
					v43 = v59;
					if ((uint16_t)v59 == (uint16_t)-1) {
						break;
					}
					v42 = a1;
				}
				return 1;
			}
		} else {
			for (int i = 0; i < ptr_5D4594_2650668_cap; i++) {
				for (int j = 0; j < ptr_5D4594_2650668_cap; j++) {
					*(uint8_t*)(&ptr_5D4594_2650668[j][i].field_0) = 0;
				}
			}
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v59, 2u);
			for (k = v59; (uint16_t)v59 != (uint16_t)-1; k = v59) {
				v47 = 0;
				v48 = (k >> 8) & 0x7F;
				v49 = k & 0x7F;
				if ((k & 0x8000u) != 0) {
					v47 = -32768;
				}
				if ((k & 0x80u) != 0) {
					LOBYTE(v47) = v47 | 0x80;
				}
				if (v47 < 0) {
					*(uint8_t*)(&ptr_5D4594_2650668[v48][v49].field_0) |= 0x1;
					nox_xxx_tileReadOne_422A40(v62, (uint8_t*)(&ptr_5D4594_2650668[v48][v49].field_1));
				}
				if (v47 & 0x80) {
					*(uint8_t*)(&ptr_5D4594_2650668[v48][v49].field_0) |= 0x2;
					nox_xxx_tileReadOne_422A40(v62, (uint8_t*)(&ptr_5D4594_2650668[v48][v49].field_6));
				}
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v59, 2u);
			}
		}
		return 1;
	}
	if (a1) {
		sub_428170((uint32_t*)a1, &v70);
		v60 = v70.field_0 / 23;
		v18 = v70.field_8 / 23;
		v64 = v70.field_8 / 23;
		v63 = v70.field_C / 23;
		v61 = v70.field_4 / 23;
		v66 = v70.field_8 / 23 - v70.field_0 / 23 + 1;
		v67 = v70.field_C / 23 - v70.field_4 / 23 + 1;
		goto LABEL_43;
	}
	v2 = v65;
	v3 = 0;
	v4 = 0;
	for (l = 0; l < ptr_5D4594_2650668_cap * 44; l += 44) {
		if (v3) {
			break;
		}
		v2 = 0;
		v65 = l;
		v6 = ptr_5D4594_2650668;
		while (!*(uint8_t*)(l + *v6)) {
			++v2;
			++v6;
			if (v2 >= ptr_5D4594_2650668_cap) {
				goto LABEL_14;
			}
		}
		v61 = v4;
		v3 = 1;
	LABEL_14:
		++v4;
	}
	if (v2 == ptr_5D4594_2650668_cap && v4 == ptr_5D4594_2650668_cap) {
		return 1;
	}
	v7 = 0;
	v8 = 127;
	for (m = 5588; m >= 0; m -= 44) {
		if (v7) {
			break;
		}
		v10 = 0;
		v65 = m;
		v11 = ptr_5D4594_2650668;
		while (!*(uint8_t*)(m + *v11)) {
			++v10;
			++v11;
			if (v10 >= ptr_5D4594_2650668_cap) {
				goto LABEL_24;
			}
		}
		v63 = v8;
		v7 = 1;
	LABEL_24:
		--v8;
	}
	v12 = 0;
	v13 = 0;
	v14 = ptr_5D4594_2650668;
	do {
		if (v12) {
			break;
		}
		v15 = *v14;
		v16 = 0;
		while (!*v15) {
			++v16;
			v15 += 44;
			if (v16 >= ptr_5D4594_2650668_cap) {
				goto LABEL_32;
			}
		}
		v60 = v13;
		v12 = 1;
	LABEL_32:
		++v13;
		++v14;
	} while (v13 < ptr_5D4594_2650668_cap);
	v17 = &ptr_5D4594_2650668[ptr_5D4594_2650668_cap - 1];
	v18 = v64;
	v19 = 0;
	for (n = ptr_5D4594_2650668_cap - 1; n >= 0; --n) {
		if (v19) {
			break;
		}
		v21 = *v17;
		v22 = 0;
		while (!*v21) {
			++v22;
			v21 += 44;
			if (v22 >= ptr_5D4594_2650668_cap) {
				goto LABEL_40;
			}
		}
		v18 = n;
		v19 = 1;
	LABEL_40:
		--v17;
	}
	v64 = v18;
	v66 = v18 - v60 + 1;
	v67 = v63 - v61 + 1;
LABEL_43:
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v60, 4u);
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v61, 4u);
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v66, 4u);
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v67, 4u);
	if (a1) {
		v33 = v61;
		if (v61 > v63) {
			v59 = 0xFFFF;
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v59, 2u);
			return 1;
		}
		v34 = v60;
		while (1) {
			v35 = v34;
			v65 = v34;
			if (v34 <= v64) {
				v36 = 23 * v34 + 11;
				while (1) {
					if (!(((uint8_t)v33 + v35) & 1)) {
						if (v33 & 1) {
							v39 = (uint8_t*)((uint32_t)(ptr_5D4594_2650668[(v36 - 34) / 46]) + 44 * (23 * (v33 + 1) / 46));
							if (*v39 & 1) {
								v38 = v39 + 4;
								v69.field_0 = v36;
								v69.field_4 = 23 * v33 + 34;
								if (nox_xxx_wallMath_427F30(&v69, (uint32_t*)a1)) {
									LOBYTE(v40) = 0;
									HIBYTE(v40) = v65;
									v68 = v33 | v40;
									nox_xxx_fileReadWrite_426AC0_file3_fread(&v68, 2u);
									nox_xxx_tileReadOne_422A40(v62, v38);
								}
								v34 = v60;
								goto LABEL_73;
							}
						} else {
							v37 = (uint8_t*)((uint32_t)(ptr_5D4594_2650668[(v36 - 11) / 46]) + 44 * (23 * v33 / 46));
							if (*v37 & 2) {
								v38 = v37 + 24;
								v69.field_0 = v36;
								v69.field_4 = 23 * v33 + 34;
								if (nox_xxx_wallMath_427F30(&v69, (uint32_t*)a1)) {
									LOBYTE(v40) = 0;
									HIBYTE(v40) = v65;
									v68 = v33 | v40;
									nox_xxx_fileReadWrite_426AC0_file3_fread(&v68, 2u);
									nox_xxx_tileReadOne_422A40(v62, v38);
								}
								v34 = v60;
								goto LABEL_73;
							}
						}
					}
				LABEL_73:
					v35 = v65 + 1;
					v36 += 23;
					if (++v65 > v64) {
						break;
					}
				}
			}
			++v33;
			if (v33 > v63) {
				v59 = 0xFFFF;
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v59, 2u);
				return 1;
			}
		}
	}
	v23 = v61;
	if (v61 <= v63) {
		v24 = ptr_5D4594_2650668;
		v25 = 44 * v61;
		do {
			for (ii = v60; ii <= v18; ++ii) {
				v27 = *(uint32_t*)(v24 + 4 * ii);
				if (*(uint8_t*)(v25 + v27) & 3) {
					LOBYTE(v28) = 0;
					HIBYTE(v28) = ii;
					a1 = v23 | v28;
					if (*(uint8_t*)(v25 + v27) & 1) {
						v29 = a1;
						BYTE1(v29) |= 0x80u;
						a1 = v29;
					}
					if (*(uint8_t*)(v25 + *(uint32_t*)(v24 + 4 * ii)) & 2) {
						v30 = a1;
						LOBYTE(v30) = a1 | 0x80;
						a1 = v30;
					}
					nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 2u);
					v24 = ptr_5D4594_2650668;
				}
				v31 = (uint8_t*)(v25 + *(uint32_t*)(v24 + 4 * ii));
				if (*v31 & 1) {
					nox_xxx_tileReadOne_422A40(v62, v31 + 4);
					v24 = ptr_5D4594_2650668;
				}
				v32 = (uint8_t*)(v25 + *(uint32_t*)(v24 + 4 * ii));
				if (*v32 & 2) {
					nox_xxx_tileReadOne_422A40(v62, v32 + 24);
					v24 = ptr_5D4594_2650668;
				}
			}
			++v23;
			v25 += 44;
		} while (v23 <= v63);
	}
	v59 = 0xFFFF;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v59, 2u);
	return 1;
}

//----- (00422A40) --------------------------------------------------------
unsigned char nox_xxx_tileReadOne_422A40(int a1, uint8_t* a2) {
	uint8_t* v2;          // esi
	size_t v3;            // eax
	char v4;              // al
	char v5;              // al
	int v6;               // eax
	unsigned char result; // al
	int i;                // esi
	size_t v9;            // eax
	int v10;              // ebx
	bool v11;             // zf
	int* v12;             // edi
	int* v13;             // esi
	size_t v14;           // [esp+Ch] [ebp-8h]
	int v15;              // [esp+10h] [ebp-4h]

	v2 = a2;
	LOBYTE(a2) = *a2;
	v3 = nox_xxx_fileReadWrite_426AC0_file3_fread(&a2, 1u);
	LOWORD(v3) = *((uint16_t*)v2 + 2);
	*(uint32_t*)v2 = (unsigned char)a2;
	v14 = v3;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v14, 2u);
	v4 = v2[8];
	*((uint32_t*)v2 + 1) = (short)v14;
	LOBYTE(a2) = v4;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&a2, 1u);
	v5 = v2[12];
	*((uint32_t*)v2 + 2) = (unsigned char)a2;
	LOBYTE(a2) = v5;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&a2, 1u);
	v6 = *((uint32_t*)v2 + 4);
	*((uint32_t*)v2 + 3) = (unsigned char)a2;
	for (LOBYTE(v15) = 0; v6; v6 = *(uint32_t*)(v6 + 16)) {
		LOBYTE(v15) = v15 + 1;
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v15, 1u);
	result = nox_crypt_IsReadOnly();
	if (nox_crypt_IsReadOnly()) {
		result = v15;
		v10 = 0;
		v11 = (uint8_t)v15 == 0;
		*((uint32_t*)v2 + 4) = 0;
		v12 = (int*)v2;
		if (!v11) {
			do {
				v13 = nox_xxx_tileListAddNewSubtile_422160(0, 0, 0, 0);
				nox_xxx_fileReadWrite_426AC0_file3_fread(&a2, 1u);
				*v13 = (unsigned char)a2;
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v14, 2u);
				v13[1] = (short)v14;
				nox_xxx_fileReadWrite_426AC0_file3_fread(&a2, 1u);
				v13[2] = (unsigned char)a2;
				result = nox_xxx_fileReadWrite_426AC0_file3_fread(&a2, 1u);
				++v10;
				v13[3] = (unsigned char)a2;
				v12[4] = (int)v13;
				v12 = v13;
			} while (v10 < (unsigned char)v15);
		}
	} else {
		for (i = *((uint32_t*)v2 + 4); i; i = *(uint32_t*)(i + 16)) {
			LOBYTE(a2) = *(uint8_t*)i;
			v9 = nox_xxx_fileReadWrite_426AC0_file3_fread(&a2, 1u);
			LOWORD(v9) = *(uint16_t*)(i + 4);
			v14 = v9;
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v14, 2u);
			LOBYTE(a2) = *(uint8_t*)(i + 8);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&a2, 1u);
			LOBYTE(a2) = *(uint8_t*)(i + 12);
			result = nox_xxx_fileReadWrite_426AC0_file3_fread(&a2, 1u);
		}
	}
	return result;
}

//----- (00422C10) --------------------------------------------------------
int nox_xxx_tile_422C10(int a1, int a2) {
	int v3;        // ecx
	char v4;       // bl
	int v5;        // esi
	int i;         // edx
	uint32_t* v7;  // eax
	char v8;       // bl
	int v9;        // esi
	int j;         // edx
	int v11;       // ecx
	uint32_t* v12; // eax
	char v13;      // bl
	int v14;       // edx
	uint8_t** v15; // esi
	uint8_t* v16;  // ecx
	int v17;       // eax
	uint8_t** v18; // esi
	int v19;       // edi
	char v20;      // bl
	int k;         // edx
	uint8_t* v22;  // ecx
	int v23;       // eax
	int v24;       // esi
	int v26;       // edi
	int v27;       // ebp
	int l;         // eax
	int m;         // esi
	int n;         // eax
	int ii;        // esi
	int v35;       // ebx
	int v36;       // eax
	int v37;       // ebp
	int v38;       // edi
	uint8_t* v39;  // eax
	int v40;       // esi
	uint8_t* v41;  // eax
	int jj;        // eax
	int kk;        // esi
	int v44;       // ecx
	int v45;       // edx
	int v46;       // ebx
	int v47;       // edi
	int v48;       // esi
	int v49;       // edi
	int v51;       // esi
	int v52;       // esi
	int v55;       // ecx
	int v56;       // esi
	int v57;       // eax
	int v58;       // ebp
	int v59;       // esi
	uint8_t* v60;  // eax
	int v61;       // ebx
	int v62;       // edi
	int* v63;      // esi
	int v64;       // edi
	int v66;       // esi
	int v67;       // ebp
	int* v68;      // edi
	int* v69;      // esi
	bool v70;      // cc
	uint8_t* v71;  // eax
	int v72;       // ebx
	int v73;       // edi
	int* v74;      // esi
	int v75;       // [esp+10h] [ebp-34h]
	int v76;       // [esp+14h] [ebp-30h]
	int v77;       // [esp+18h] [ebp-2Ch]
	int v78;       // [esp+1Ch] [ebp-28h]
	int v79;       // [esp+20h] [ebp-24h]
	int v80 = 0;   // [esp+24h] [ebp-20h]
	int v81 = 0;   // [esp+28h] [ebp-1Ch]
	int2 v82;      // [esp+2Ch] [ebp-18h]
	int4 v83;      // [esp+34h] [ebp-10h]

	if ((short)a1 < 3) {
		return 0;
	}
	if (!nox_crypt_IsReadOnly()) {
		if (a2) {
			sub_428170((uint32_t*)a2, &v83);
			v76 = v83.field_0 / 23;
			v80 = v83.field_8 / 23;
			v77 = v83.field_4 / 23;
			v81 = v83.field_C / 23;
			v24 = v81;
			v78 = v83.field_8 / 23 - v83.field_0 / 23 + 1;
			v79 = v81 - v83.field_4 / 23 + 1;
		} else {
			v3 = 0;
			v4 = 0;
			v5 = 0;
			for (i = 0; i < ptr_5D4594_2650668_cap * 44; i += 44) {
				if (v4) {
					break;
				}
				v3 = 0;
				a1 = i;
				v7 = ptr_5D4594_2650668;
				while (!*(uint8_t*)(i + *v7)) {
					++v3;
					++v7;
					if (v3 >= ptr_5D4594_2650668_cap) {
						goto LABEL_12;
					}
				}
				v77 = v5;
				v4 = 1;
			LABEL_12:
				++v5;
			}
			if (v3 == ptr_5D4594_2650668_cap && v5 == ptr_5D4594_2650668_cap) {
				return 1;
			}
			v8 = 0;
			v9 = 127;
			for (j = 5588; j >= 0; j -= 44) {
				if (v8) {
					break;
				}
				v11 = 0;
				a1 = j;
				v12 = ptr_5D4594_2650668;
				while (!*(uint8_t*)(j + *v12)) {
					++v11;
					++v12;
					if (v11 >= ptr_5D4594_2650668_cap) {
						goto LABEL_22;
					}
				}
				v81 = v9;
				v8 = 1;
			LABEL_22:
				--v9;
			}
			v13 = 0;
			v14 = 0;
			v15 = ptr_5D4594_2650668;
			do {
				if (v13) {
					break;
				}
				v16 = *v15;
				v17 = 0;
				while (!*v16) {
					++v17;
					v16 += 44;
					if (v17 >= ptr_5D4594_2650668_cap) {
						goto LABEL_30;
					}
				}
				v76 = v14;
				v13 = 1;
			LABEL_30:
				++v14;
				++v15;
			} while (v14 < 128);
			v18 = (uint8_t**)(ptr_5D4594_2650668 + ptr_5D4594_2650668_cap - 1);
			v19 = v80;
			v20 = 0;
			for (k = ptr_5D4594_2650668_cap - 1; k >= 0; --k) {
				if (v20) {
					break;
				}
				v22 = *v18;
				v23 = 0;
				while (!*v22) {
					++v23;
					v22 += 44;
					if (v23 >= ptr_5D4594_2650668_cap) {
						goto LABEL_38;
					}
				}
				v19 = k;
				v20 = 1;
			LABEL_38:
				--v18;
			}
			v24 = v81;
			v80 = v19;
			v78 = v19 - v76 + 1;
			v79 = v81 - v77 + 1;
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v76, 4u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v77, 4u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v78, 4u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v79, 4u);
		if (!a2) {
			if (v77 > v24) {
				return 1;
			}

			v26 = v76;
			v27 = v80;
			int v28 = v77;
			a2 = v81 - v77 + 1;
			do {
				if (v26 <= v27) {
					do {
						obj_5D4594_2650668_t* obj = &ptr_5D4594_2650668[v26][v28];

						nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(&obj->field_0), 1);
						if (obj->field_0 & 0x1) {
							nox_xxx_fileReadWrite_426AC0_file3_fread(&obj->field_1, 16);
							LOBYTE(v75) = 0;
							for (l = obj->field_5; l; l = *(uint32_t*)(l + 16)) {
								LOBYTE(v75) = v75 + 1;
							}
							nox_xxx_fileReadWrite_426AC0_file3_fread(&v75, 1);
							for (m = obj->field_5; m; m = *(uint32_t*)(m + 16)) {
								nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)m, 16);
							}
						}
						if (obj->field_0 & 0x2) {
							nox_xxx_fileReadWrite_426AC0_file3_fread(&obj->field_6, 16);
							LOBYTE(v75) = 0;
							for (n = obj->field_10; n; n = *(uint32_t*)(n + 16)) {
								LOBYTE(v75) = v75 + 1;
							}
							nox_xxx_fileReadWrite_426AC0_file3_fread(&v75, 1);
							for (ii = obj->field_10; ii; ii = *(uint32_t*)(ii + 16)) {
								nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)ii, 16);
							}
						}
						++v26;
					} while (v26 <= v27);
					v26 = v76;
				}
				v28++;
				--a2;
			} while (a2);
			return 1;
		}
		v35 = v77;
		if (v77 > v24) {
			return 1;
		}
		v36 = v76;
	LABEL_61:
		v37 = v36;
		if (v36 > v80) {
			goto LABEL_78;
		}
		v38 = 23 * v36 + 11;
		while (1) {
			if (!(((uint8_t)v35 + (uint8_t)v37) & 1)) {
				if (v35 & 1) {
					v41 = (uint8_t*)((uint32_t)(ptr_5D4594_2650668[(v38 - 34) / 46]) + 44 * (23 * (v35 + 1) / 46));
					if (!(*v41 & 1)) {
						goto LABEL_75;
					}
					v40 = (int)(v41 + 4);
				} else {
					v39 = (uint8_t*)((uint32_t)(ptr_5D4594_2650668[(v38 - 11) / 46]) + 44 * (23 * v35 / 46));
					if (!(*v39 & 2)) {
						goto LABEL_75;
					}
					v40 = (int)(v39 + 24);
				}
				v82.field_0 = v38;
				v82.field_4 = 23 * v35 + 34;
				if (nox_xxx_wallMath_427F30(&v82, (uint32_t*)a2)) {
					LOBYTE(a1) = 1;
					nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 1u);
					nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)v40, 0x10u);
					LOBYTE(v75) = 0;
					for (jj = *(uint32_t*)(v40 + 16); jj; jj = *(uint32_t*)(jj + 16)) {
						LOBYTE(v75) = v75 + 1;
					}
					nox_xxx_fileReadWrite_426AC0_file3_fread(&v75, 1u);
					for (kk = *(uint32_t*)(v40 + 16); kk; kk = *(uint32_t*)(kk + 16)) {
						nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)kk, 0x10u);
					}
					goto LABEL_76;
				}
			}
		LABEL_75:
			LOBYTE(a1) = 0;
			nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 1u);
		LABEL_76:
			++v37;
			v38 += 23;
			if (v37 > v80) {
				v36 = v76;
			LABEL_78:
				if (++v35 > v81) {
					return 1;
				}
				goto LABEL_61;
			}
		}
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v76, 4u);
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v77, 4u);
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v78, 4u);
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v79, 4u);
	if (!a2) {
		for (int ll = 0; ll < ptr_5D4594_2650668_cap; ll++) {
			for (int mm = 0; mm < ptr_5D4594_2650668_cap; mm++) {
				*(uint8_t*)&ptr_5D4594_2650668[mm][ll] = 0;
			}
		}
		v55 = v77;
		v81 = v77;
		if (v77 < v77 + v79) {
			v56 = v78;
			a2 = 44 * v77;
			v57 = v76;
			do {
				v58 = v57;
				if (v57 < v56 + v57) {
					do {
						v59 = a2;
						nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(a2 + (uint32_t)(ptr_5D4594_2650668[v58])),
																 1u);
						v60 = (uint8_t*)(v59 + (uint32_t)(ptr_5D4594_2650668[v58]));
						if (*v60 & 1) {
							nox_xxx_fileReadWrite_426AC0_file3_fread(v60 + 4, 0x10u);
							nox_xxx_fileReadWrite_426AC0_file3_fread(&v75, 1u);
							if ((uint8_t)v75) {
								v61 = 0;
								v62 = (uint32_t)(ptr_5D4594_2650668[v58]) + v59 + 4;
								if ((uint8_t)v75) {
									do {
										v63 = nox_xxx_tileListAddNewSubtile_422160(0, 0, 0, 0);
										nox_xxx_fileReadWrite_426AC0_file3_fread(v63, 0x10u);
										*(uint32_t*)(v62 + 16) = v63;
										++v61;
										v62 = (int)v63;
									} while (v61 < (unsigned char)v75);
								}
							} else {
								*(uint32_t*)((uint32_t)(ptr_5D4594_2650668[v58]) + a2 + 20) = 0;
							}
						}
						v71 = (uint8_t*)((uint32_t)(ptr_5D4594_2650668[v58]) + a2);
						if (*v71 & 2) {
							nox_xxx_fileReadWrite_426AC0_file3_fread(v71 + 24, 0x10u);
							nox_xxx_fileReadWrite_426AC0_file3_fread(&v75, 1u);
							if ((uint8_t)v75) {
								v72 = 0;
								v73 = (uint32_t)(ptr_5D4594_2650668[v58]) + a2 + 24;
								if ((uint8_t)v75) {
									do {
										v74 = nox_xxx_tileListAddNewSubtile_422160(0, 0, 0, 0);
										nox_xxx_fileReadWrite_426AC0_file3_fread(v74, 0x10u);
										*(uint32_t*)(v73 + 16) = v74;
										++v72;
										v73 = (int)v74;
									} while (v72 < (unsigned char)v75);
								}
							} else {
								*(uint32_t*)((uint32_t)(ptr_5D4594_2650668[v58]) + a2 + 40) = 0;
							}
						}
						v56 = v78;
						v57 = v76;
						++v58;
					} while (v58 < v78 + v76);
					v55 = v77;
				}
				v70 = ++v81 < v55 + v79;
				a2 += 44;
			} while (v70);
		}
		return 1;
	}
	sub_428170((uint32_t*)a2, &v83);
	v44 = v83.field_0 / 23;
	v76 = v83.field_0 / 23;
	v45 = v83.field_4 / 23;
	v77 = v83.field_4 / 23;
	v46 = v83.field_4 / 23;
	if (v83.field_4 / 23 >= v83.field_4 / 23 + v79) {
		return 1;
	}
	v47 = v78;
	do {
		a2 = v44;
		if (v44 < v47 + v44) {
			v81 = 23 * v44;
			v48 = 23 * v44;
			do {
				nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 1u);
				if ((uint8_t)a1) {
					if (v46 & 1) {
						v64 = (v48 - 23) / 46;
						v66 = (v46 + 23) / 46;
						if (nox_common_gameFlags_check_40A5C0(0x400000)) {
							v52 = *nox_xxx_tileAllocTileInCoordList_5040A0(v64, v66, COERCE_FLOAT(1));
						} else {
							*(uint8_t*)((uint32_t)(ptr_5D4594_2650668[v64]) + 44 * v66) |= 1u;
							v52 = (uint32_t)(ptr_5D4594_2650668[v64]) + 44 * v66 + 4;
						}
					} else {
						v49 = v48 / 46;
						v51 = v46 / 46;
						if (nox_common_gameFlags_check_40A5C0(0x400000)) {
							v52 = *nox_xxx_tileAllocTileInCoordList_5040A0(v49, v51, COERCE_FLOAT(2));
						} else {
							*(uint8_t*)((uint32_t)(ptr_5D4594_2650668[v49]) + 44 * v51) |= 2u;
							v52 = (uint32_t)(ptr_5D4594_2650668[v49]) + 44 * v51 + 24;
						}
					}
					nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)v52, 0x10u);
					nox_xxx_fileReadWrite_426AC0_file3_fread(&v75, 1u);
					if ((uint8_t)v75) {
						v67 = 0;
						v68 = (int*)v52;
						if ((uint8_t)v75) {
							do {
								v69 = nox_xxx_tileListAddNewSubtile_422160(0, 0, 0, 0);
								nox_xxx_fileReadWrite_426AC0_file3_fread(v69, 0x10u);
								v68[4] = (int)v69;
								++v67;
								v68 = v69;
							} while (v67 < (unsigned char)v75);
						}
					} else {
						*(uint32_t*)(v52 + 16) = 0;
					}
				}
				v47 = v78;
				v44 = v76;
				v48 = v81 + 23;
				v70 = ++a2 < v78 + v76;
				v81 += 23;
			} while (v70);
			v45 = v77;
		}
		++v46;
	} while (v46 < v45 + v79);
	return 1;
}

//----- (00423930) --------------------------------------------------------
void set_bitmask_flags_from_plus_separated_names_423930(const char* input, uint32_t* bitmask,
														const char** allowed_names) {
	char input_copy[256];
	strcpy(input_copy, input);
	if (strncmp(input_copy, "NULL", 4u) == 0) {
		return;
	}

	char* cur_value = strtok(input_copy, "+");
	while (cur_value) {
		set_one_bitmask_flag_by_name_4239C0(cur_value, bitmask, allowed_names);
		cur_value = strtok(0, "+");
	}
}

//----- (004239C0) --------------------------------------------------------
int set_one_bitmask_flag_by_name_4239C0(char* name, uint32_t* bitmask, const char** allowed_names) {
	for (char i = 0; allowed_names[i]; ++i) {
		if (!nox_strcmpi(allowed_names[i], name)) {
			*bitmask |= 1 << i;
			return 1;
		}
	}

	return 0;
}

//----- (004240F0) --------------------------------------------------------
int sub_4240F0(int a1, const char* a2, int a3) {
	const char* v3;    // esi
	int v4;            // ebp
	unsigned char* v5; // edi

	v3 = *(const char**)getMemAt(0x587000, 64704);
	v4 = 0;
	if (!*getMemU32Ptr(0x587000, 64704)) {
		return 0;
	}
	v5 = getMemAt(0x587000, 64704);
	while (strcmp(a2, v3)) {
		v3 = (const char*)*((uint32_t*)v5 + 2);
		v5 += 8;
		++v4;
		if (!v3) {
			return 0;
		}
	}
	*(uint32_t*)(*getMemU32Ptr(0x587000, 64708 + 8 * v4) + a1) = a3;
	return 1;
}

//----- (00424170) --------------------------------------------------------
int nox_xxx_parseSoundSetBin_424170(char* a1) {
	FILE* v2;     // ebp
	uint32_t* v3; // ebx
	char* v4;     // edx
	int v5;       // eax
	char v6[256]; // [esp+10h] [ebp-200h]
	char v7[256]; // [esp+110h] [ebp-100h]

	v2 = nox_binfile_open_408CC0(a1, 0);
	if (!v2) {
		return 0;
	}
	if (!nox_binfile_cryptSet_408D40(v2, 5)) {
		return 0;
	}
	while (nox_xxx_parseString_409470(v2, v6)) {
		v3 = calloc(1u, 0x54u);
		v3[19] = dword_5d4594_588120;
		v3[20] = 0;
		dword_5d4594_588120 = v3;
		v4 = (char*)calloc(strlen(v6) + 1, 1);
		*v3 = v4;
		strcpy(v4, v6);
		while (nox_xxx_parseString_409470(v2, v6) && strcmp(v6, "END") && nox_xxx_parseString_409470(v2, v7)) {
			v5 = nox_xxx_utilFindSound_40AF50(v7);
			if (!sub_4240F0((int)v3, v6, v5)) {
				return 0;
			}
		}
	}
	nox_binfile_close_408D90(v2);
	return 1;
}

//----- (00424300) --------------------------------------------------------
void* nox_xxx_monsterGetSoundSet_424300(nox_object_t* a1p) {
	int a1 = a1p;
	int result; // eax

	result = a1;
	if (a1) {
		if (*(uint8_t*)(a1 + 8) & 2) {
			result = *(uint32_t*)(*(uint32_t*)(a1 + 748) + 488);
		} else {
			result = 0;
		}
	}
	return result;
}

//----- (00424320) --------------------------------------------------------
int nox_xxx_setNPCVoiceSet_424320(int a1, int a2) {
	int result; // eax

	result = a1;
	if (a1) {
		if (*(uint8_t*)(a1 + 8) & 2) {
			*(uint32_t*)(*(uint32_t*)(a1 + 748) + 488) = a2;
			result = 1;
		} else {
			result = 0;
		}
	}
	return result;
}

//----- (00424350) --------------------------------------------------------
const char** nox_xxx_getDefaultSoundSet_424350(const char* a1) {
	int v1; // edi

	if (!a1) {
		return 0;
	}
	v1 = dword_5d4594_588120;
	if (!dword_5d4594_588120) {
		return 0;
	}
	while (strcmp(*(const char**)v1, a1)) {
		v1 = *(uint32_t*)(v1 + 76);
		if (!v1) {
			return 0;
		}
	}
	return (const char**)v1;
}

//----- (00424CB0) --------------------------------------------------------
char sub_424CB0(int a1) {
	char v1;           // bl
	int v2;            // esi
	unsigned char* v3; // edi

	v1 = 0;
	v2 = 0;
	if (*(int*)&dword_587000_66116 <= 0) {
		return 0;
	}
	v3 = getMemAt(0x587000, 66000);
	do {
		if (nox_xxx_testUnitBuffs_4FF350(a1, *(uint32_t*)v3)) {
			++v1;
		}
		++v2;
		v3 += 4;
	} while (v2 < *(int*)&dword_587000_66116);
	return v1;
}

//----- (00424D00) --------------------------------------------------------
int sub_424D00() {
	int result; // eax

	if (*(int*)&dword_587000_66116 <= 0) {
		result = -1;
	} else {
		result = *getMemU32Ptr(0x587000, 66000);
	}
	return result;
}

//----- (00424D20) --------------------------------------------------------
int sub_424D20(int a1) {
	int v1;           // eax
	unsigned char* i; // edx

	v1 = 0;
	if (*(int*)&dword_587000_66116 <= 0) {
		return -1;
	}
	for (i = getMemAt(0x587000, 66000); *(int*)i != a1 || v1 >= *(int*)&dword_587000_66116 - 1; i += 4) {
		if (++v1 >= *(int*)&dword_587000_66116) {
			return -1;
		}
	}
	return *getMemU32Ptr(0x587000, 66004 + 4 * v1);
}

//----- (00424D80) --------------------------------------------------------
int nox_xxx_abilityNameToN_424D80(const char* a1) {
	const char* v1;    // ecx
	int v2;            // ebp
	unsigned char* v3; // edi

	v1 = *(const char**)getMemAt(0x587000, 69736);
	v2 = 0;
	if (!*getMemU32Ptr(0x587000, 69736)) {
		return 0;
	}
	v3 = getMemAt(0x587000, 69736);
	while (strcmp(v1, a1)) {
		v1 = (const char*)*((uint32_t*)v3 + 1);
		v3 += 4;
		++v2;
		if (!v1) {
			return 0;
		}
	}
	return v2;
}

// 424FE7: variable 'v34' is possibly undefined
// 424F00: using guessed type char var_100[256];

//----- (004254A0) --------------------------------------------------------
int sub_4254A0(int a1, uint8_t* a2) {
	*(uint32_t*)a1 = a2;
	*(uint8_t*)(a1 + 4) = 0;
	return *a2 & 1;
}

//----- (004254C0) --------------------------------------------------------
bool sub_4254C0(unsigned char** a1) {
	char v1;           // cl
	unsigned char* v2; // ecx

	v1 = *((uint8_t*)a1 + 4) + 1;
	*((uint8_t*)a1 + 4) = v1;
	if (v1 == 8) {
		v2 = *a1;
		*((uint8_t*)a1 + 4) = 0;
		*a1 = v2 + 1;
	}
	return ((1 << *((uint8_t*)a1 + 4)) & **a1) > 0;
}

//----- (00425500) --------------------------------------------------------
uint8_t* sub_425500(int a1, uint8_t* a2, char a3) {
	uint8_t* result; // eax

	result = a2;
	*(uint32_t*)a1 = a2;
	*(uint8_t*)(a1 + 4) = 0;
	*a2 = a3;
	return result;
}

//----- (00425520) --------------------------------------------------------
char sub_425520(int a1, char a2) {
	char v2;     // cl
	uint8_t* v3; // ecx
	char result; // al

	v2 = *(uint8_t*)(a1 + 4) + 1;
	*(uint8_t*)(a1 + 4) = v2;
	if (v2 == 8) {
		v3 = *(uint8_t**)a1;
		*(uint8_t*)(a1 + 4) = 0;
		*(uint32_t*)a1 = ++v3;
		*v3 = 0;
	}
	result = a2 << *(uint8_t*)(a1 + 4);
	**(uint8_t**)a1 |= result;
	return result;
}

//----- (00425550) --------------------------------------------------------
int sub_425550(uint8_t* a1, uint8_t* a2, int a3) {
	int v3;     // edi
	int v4;     // esi
	char v5;    // al
	int v6;     // ebx
	char v8[8]; // [esp+8h] [ebp-10h]
	char v9[8]; // [esp+10h] [ebp-8h]
	bool v10;   // [esp+1Ch] [ebp+4h]

	v3 = 1;
	v4 = 0;
	v5 = sub_4254A0((int)v9, a1);
	sub_425500((int)v8, a2, v5);
	if (a3 == 1) {
		return 1;
	}
	v6 = a3 - 1;
	do {
		if (!(++v4 % 7u)) {
			sub_425520((int)v8, 1);
			++v3;
		}
		v10 = sub_4254C0((unsigned char**)v9);
		sub_425520((int)v8, v10);
		--v6;
	} while (v6);
	return v3;
}

//----- (00425760) --------------------------------------------------------
void nox_common_list_clear_425760(nox_list_item_t* list) {
	list->field_0 = list;
	list->field_1 = list;
	list->field_2 = list;
}

//----- (00425770) --------------------------------------------------------
void* sub_425770(void* a1p) {
	uint32_t* a1 = a1p;
	uint32_t* result; // eax

	result = a1;
	*a1 = a1;
	a1[1] = a1;
	a1[2] = 0;
	return result;
}

//----- (00425790) --------------------------------------------------------
int sub_425790(int* a1, uint32_t* a2) {
	int v2;     // esi
	int v3;     // ebx
	int* v4;    // eax

	v2 = 0;
	v3 = a2[2];
	v4 = (int*)nox_common_list_getNext_425940(a1);
	if (!v4) {
		nox_common_list_append_4258E0((int)a1, a2);
		return v2;
	}
	while (v3 > v4[2]) {
		++v2;
		v4 = nox_common_list_getNext_425940(v4);
		if (!v4) {
			nox_common_list_append_4258E0((int)a1, a2);
			return v2;
		}
	}
	nox_common_list_append_4258E0((int)v4, a2);
	return v2;
}

//----- (004257F0) --------------------------------------------------------
void sub_4257F0(int* a1, uint32_t* a2) {
	int v2;  // esi
	int* v3; // eax

	v2 = a2[2];
	v3 = (int*)nox_common_list_getNext_425940(a1);
	if (!v3) {
		nox_common_list_append_4258E0((int)a1, a2);
		return;
	}
	while (v3[2] > v2) {
		v3 = (int*)nox_common_list_getNext_425940(v3);
		if (!v3) {
			nox_common_list_append_4258E0((int)a1, a2);
			return;
		}
	}
	nox_common_list_append_4258E0((int)v3, a2);
}

//----- (00425890) --------------------------------------------------------
nox_list_item_t* nox_common_list_getFirstSafe_425890(nox_list_item_t* list) {
	return nox_common_list_getNextSafe_4258A0(list);
}

//----- (004258A0) --------------------------------------------------------
nox_list_item_t* nox_common_list_getNextSafe_4258A0(nox_list_item_t* list) {
	if (!list) {
		return 0;
	}
	return nox_common_list_getNext_425940(list);
}

//----- (004258C0) --------------------------------------------------------
uint32_t* sub_4258C0(uint32_t** a1, int a2) {
	uint32_t* result; // eax
	int v3;           // edx
	int v4;           // esi

	result = *a1;
	if (*a1 == a1) {
		return 0;
	}
	v3 = a2;
	while (1) {
		v4 = v3--;
		if (!v4) {
			break;
		}
		result = (uint32_t*)*result;
		if (result == a1) {
			return 0;
		}
	}
	return result;
}

//----- (004258E0) --------------------------------------------------------
void nox_common_list_append_4258E0(nox_list_item_t* list, nox_list_item_t* cur) {
	if (!list || !cur) {
		abort();
	}
	nox_list_item_t* it = list->field_1;

	// FIXME: in some cases 'it' is null, which suggests that some lists are not initialized properly
	//        auto-initializing them however leads to more serious issues like double-free

	//	if (!it && !list->field_0 && !list->field_2) {
	//		nox_common_list_clear_425760(list);
	//		it = list->field_1;
	//	}

	cur->field_0 = list;
	cur->field_1 = it;

	list->field_1 = cur;
	if (it) { // see above note
		it->field_0 = cur;
	}
}

//----- (00425900) --------------------------------------------------------
uint32_t* sub_425900(uint32_t* a1, uint32_t* a2) {
	uint32_t* result; // eax

	result = a2;
	a2[1] = a1;
	*a2 = *a1;
	*a1 = a2;
	*(uint32_t*)(*a2 + 4) = a2;
	return result;
}

//----- (00425920) --------------------------------------------------------
void nox_common_list_remove_425920(void* a1p) {
	uint32_t** a1 = a1p;

	*a1[1] = *a1;
	(*a1)[1] = a1[1];
	*a1 = a1;
	a1[1] = a1;
}

//----- (00425940) --------------------------------------------------------
nox_list_item_t* nox_common_list_getNext_425940(nox_list_item_t* list) {
	nox_list_item_t* it = list->field_0;
	if (it && it == it->field_2) {
		return 0;
	}
	return it;
}

//----- (00425960) --------------------------------------------------------
int sub_425960(int a1) {
	return *(uint32_t*)(*(uint32_t*)(a1 + 4) + 8) != *(uint32_t*)(a1 + 4) ? *(uint32_t*)(a1 + 4) : 0;
}

//----- (004259C0) --------------------------------------------------------
void sub_4259C0() {
	if (!*getMemU32Ptr(0x5D4594, 599472)) {
		nox_common_list_clear_425760(getMemAt(0x5D4594, 599460));
		*getMemU32Ptr(0x5D4594, 599472) = 1;
	}
}

//----- (004259F0) --------------------------------------------------------
int* sub_4259F0() {
	int* result; // eax
	int* v1;     // ebx
	int* v2;     // ebp
	int* v3;     // esi
	int* v4;     // edi

	result = sub_425A50();
	v1 = result;
	if (result) {
		do {
			v2 = sub_425A60(v1);
			v3 = sub_425BC0((int)v1);
			if (v3) {
				do {
					v4 = sub_425BE0(v3);
					nox_common_list_remove_425920((uint32_t**)v3);
					free(v3);
					v3 = v4;
				} while (v4);
			}
			nox_common_list_remove_425920((uint32_t**)v1);
			free(v1);
			v1 = v2;
		} while (v2);
	}
	return result;
}

//----- (00425A50) --------------------------------------------------------
int* sub_425A50() { return nox_common_list_getFirstSafe_425890(getMemIntPtr(0x5D4594, 599460)); }

//----- (00425A60) --------------------------------------------------------
int* sub_425A60(int* a1) { return nox_common_list_getNextSafe_4258A0(a1); }

//----- (00425A70) --------------------------------------------------------
int* sub_425A70(int a1) {
	int* result; // eax

	result = sub_425A50();
	if (!result) {
		return 0;
	}
	while (result[8] != a1) {
		result = sub_425A60(result);
		if (!result) {
			return 0;
		}
	}
	return result;
}

//----- (00425AA0) --------------------------------------------------------
int sub_425AA0(int a1) {
	int* v1; // eax

	v1 = sub_425A50();
	if (!v1) {
		return 0;
	}
	while (v1[8] != a1) {
		v1 = sub_425A60(v1);
		if (!v1) {
			return 0;
		}
	}
	return 1;
}

//----- (00425AD0) --------------------------------------------------------
wchar2_t* sub_425AD0(int a1, wchar2_t* a2) {
	wchar2_t* v2; // esi

	v2 = 0;
	if (!sub_425AA0(a1)) {
		v2 = (wchar2_t*)calloc(1, 0x34u);
		*((uint32_t*)v2 + 8) = a1;
		nox_wcscpy(v2 + 6, a2);
		*((uint32_t*)v2 + 9) = 0;
		sub_425770(v2);
		nox_common_list_clear_425760((uint32_t*)v2 + 10);
		nox_common_list_append_4258E0((int)getMemAt(0x5D4594, 599460), v2);
	}
	return v2;
}

//----- (00425B30) --------------------------------------------------------
void sub_425B30(void* a1, int a2) {
	uint32_t* v2; // eax
	uint32_t* v3; // esi

	v2 = calloc(1, 0x10u);
	v3 = v2;
	v2[3] = a2;
	sub_425770(v2);
	nox_common_list_append_4258E0((int)a1 + 40, v3);
}

//----- (00425B60) --------------------------------------------------------
char* sub_425B60(void* lpMem, int a2) {
	int* v2;      // esi
	char* result; // eax

	v2 = sub_425BC0((int)lpMem);
	if (v2) {
		while (v2[3] != a2) {
			v2 = sub_425BE0(v2);
			if (!v2) {
				goto LABEL_6;
			}
		}
		nox_common_list_remove_425920((uint32_t**)v2);
		free(v2);
	}
LABEL_6:
	result = (char*)lpMem + 40;
	if (*((void**)lpMem + 11) == (char*)lpMem + 40) {
		nox_common_list_remove_425920((uint32_t**)lpMem);
		free(lpMem);
	}
	return result;
}

//----- (00425BC0) --------------------------------------------------------
int* sub_425BC0(int a1) { return nox_common_list_getFirstSafe_425890((int*)(a1 + 40)); }

//----- (00425BE0) --------------------------------------------------------
int* sub_425BE0(int* a1) { return nox_common_list_getNextSafe_4258A0(a1); }

//----- (00425BF0) --------------------------------------------------------
int nox_xxx_countObserverPlayers_425BF0() {
	int v0;  // esi
	char* i; // eax
	int v2;  // ecx

	v0 = 0;
	if (nox_common_gameFlags_check_40A5C0(0x8000)) {
		for (i = nox_common_playerInfoGetFirst_416EA0(); i; i = nox_common_playerInfoGetNext_416EE0((int)i)) {
			v2 = *((uint32_t*)i + 920);
			if (v2 & 1 && !(v2 & 0x20) && i[2064] != 31) {
				++v0;
			}
		}
	}
	return v0;
}

//----- (00425CA0) --------------------------------------------------------
char* sub_425CA0(int a1, int a2) {
	char* result; // eax
	int v3;       // ebx
	int v4;       // ebp
	int v5;       // ebp
	int v6;       // eax
	int v7;       // eax
	int v8;       // esi
	int v9;       // eax
	int v10;      // eax
	int v11;      // eax
	int v12;      // [esp+8h] [ebp+4h]
	int v13;      // [esp+Ch] [ebp+8h]

	result = (char*)nox_common_gameFlags_check_40A5C0(0x2000);
	if (result) {
		result = (char*)nox_common_gameFlags_check_40A5C0(4096);
		if (!result) {
			if (a1) {
				v3 = a2;
				if (*(int*)(a1 + 4648) == -1) {
					v4 = (dword_5d4594_608316)++;
					v13 = v4;
					v5 = 32 * v4;
					strcpy((char*)getMemAt(0x5D4594, 600124 + v5), (const char*)(a1 + 2096));
					if (*(uint8_t*)(v3 + 2064) == 31) {
						v6 = nox_xxx_net_getIP_554200(0);
					} else {
						v6 = nox_xxx_net_getIP_554200(*(unsigned char*)(a1 + 2064) + 1);
					}
					*getMemU32Ptr(0x5D4594, 600136 + v5) = htonl(v6);
					*getMemU32Ptr(0x5D4594, 600140 + v5) = *(uint32_t*)(a1 + 2068);
					*getMemU8Ptr(0x5D4594, 600144 + v5) = *(uint8_t*)(a1 + 2251);
					*(uint32_t*)(a1 + 4648) = v13;
				} else {
					v13 = *(uint32_t*)(a1 + 4648);
				}
				if (v3) {
					if (*(int*)(v3 + 4648) == -1) {
						v12 = (dword_5d4594_608316)++;
						strcpy((char*)getMemAt(0x5D4594, 600124 + 32 * v13), (const char*)(v3 + 2096));
						if (*(uint8_t*)(v3 + 2064) == 31) {
							v7 = nox_xxx_net_getIP_554200(0);
							v8 = v12;
							*getMemU32Ptr(0x5D4594, 600136 + 32 * v13) = htonl(v7);
						} else {
							v9 = nox_xxx_net_getIP_554200(*(unsigned char*)(v3 + 2064) + 1);
							v8 = v12;
							*getMemU32Ptr(0x5D4594, 600136 + 32 * v12) = htonl(v9);
						}
						v10 = 32 * v8;
						*getMemU32Ptr(0x5D4594, 600140 + v10) = *(uint32_t*)(v3 + 2068);
						*getMemU8Ptr(0x5D4594, 600144 + v10) = *(uint8_t*)(v3 + 2251);
						*(uint32_t*)(v3 + 4648) = v8;
					} else {
						v12 = *(uint32_t*)(v3 + 4648);
					}
				} else {
					LOBYTE(v12) = -1;
				}
				v11 = dword_5d4594_739392;
				*getMemU8Ptr(0x5D4594, 608320 + 2 * dword_5d4594_739392) = v13;
				*getMemU8Ptr(0x5D4594, 608321 + 2 * v11) = v12;
				dword_5d4594_739392 = v11 + 1;
				result = *(char**)&dword_5d4594_608316;
				if (dword_5d4594_608316 >= 0xFFu) {
					result = nox_xxx_net_4263C0();
				}
			}
		}
	}
	return result;
}

//----- (00425E90) --------------------------------------------------------
int sub_425E90(int a1, char a2) {
	int result; // eax

	result = nox_common_gameFlags_check_40A5C0(0x2000);
	if (result) {
		result = nox_common_gameFlags_check_40A5C0(4096);
		if (!result) {
			result = *(uint32_t*)(a1 + 4648);
			if (result != -1) {
				result *= 32;
				*getMemU8Ptr(0x5D4594, 600145 + result) = a2;
			}
		}
	}
	return result;
}

//----- (00425ED0) --------------------------------------------------------
int sub_425ED0(int a1, char a2) {
	int result; // eax

	result = nox_common_gameFlags_check_40A5C0(0x2000);
	if (result) {
		result = nox_common_gameFlags_check_40A5C0(4096);
		if (!result) {
			result = *(uint32_t*)(a1 + 4648);
			if (result != -1) {
				result *= 32;
				*getMemU8Ptr(0x5D4594, 600152 + result) = a2;
			}
		}
	}
	return result;
}

//----- (00425F10) --------------------------------------------------------
void sub_425F10(nox_playerInfo* pl) {
	int a1 = pl;
	int result;  // eax
	int v2;      // ebx
	int v3;      // ecx
	int v4;      // ebp
	uint8_t* v5; // edi
	int v6;      // ebp
	bool v7;     // zf
	int v8;      // eax
	int v9;      // eax
	int v10;     // eax
	int v11;     // eax
	int v12;     // [esp+8h] [ebp+4h]

	result = nox_common_gameFlags_check_40A5C0(0x2000);
	if (result) {
		result = nox_common_gameFlags_check_40A5C0(4096);
		if (!result) {
			v2 = a1;
			if (a1) {
				result = *(uint32_t*)(a1 + 4648);
				v3 = -1;
				if (result == -1) {
					v4 = (dword_5d4594_608316)++;
					v12 = v4;
					v5 = (uint8_t*)(v2 + 2096);
					v6 = 32 * v4;
					do {
						if (!v3) {
							break;
						}
						v7 = *v5++ == 0;
						--v3;
					} while (!v7);
					memcpy(getMemAt(0x5D4594, 600124 + v6), &v5[v3 + 1], ~v3);
					if (*(uint8_t*)(v2 + 2064) == 31) {
						v8 = nox_xxx_net_getIP_554200(0);
						*getMemU32Ptr(0x5D4594, 600136 + v6) = htonl(v8);
						if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
							*getMemU8Ptr(0x5D4594, 600152 + v6) = 0;
							goto LABEL_18;
						}
						v9 = *(uint32_t*)(v2 + 3680);
						if (v9 & 1 && !(v9 & 0x20)) {
							*getMemU8Ptr(0x5D4594, 600152 + v6) = 0;
							goto LABEL_18;
						}
					} else {
						v10 = nox_xxx_net_getIP_554200(*(unsigned char*)(v2 + 2064) + 1);
						*getMemU32Ptr(0x5D4594, 600136 + v6) = htonl(v10);
						v11 = *(uint32_t*)(v2 + 3680);
						if (v11 & 1 && !(v11 & 0x20)) {
							*getMemU8Ptr(0x5D4594, 600152 + v6) = 0;
							goto LABEL_18;
						}
					}
					*getMemU8Ptr(0x5D4594, 600152 + v6) = 1;
				LABEL_18:
					*getMemU32Ptr(0x5D4594, 600140 + v6) = *(uint32_t*)(v2 + 2068);
					*getMemU8Ptr(0x5D4594, 600144 + v6) = *(uint8_t*)(v2 + 2251);
					*getMemU32Ptr(0x5D4594, 600148 + v6) = time(0);
					result = v12;
					*getMemU8Ptr(0x5D4594, 600145 + v6) = 1;
					*(uint32_t*)(v2 + 4648) = v12;
				}
			}
		}
	}
}

//----- (00426150) --------------------------------------------------------
void sub_426150() {
	char* v1;     // esi
	char* v2;     // ebp
	short v3;     // ax

	if (!nox_common_gameFlags_check_40A5C0(0x2000)) {
		return;
	}
	if (nox_common_gameFlags_check_40A5C0(4096)) {
		return;
	}
	v1 = sub_416640();
	v2 = nox_xxx_cliGamedataGet_416590(0);
	*getMemU16Ptr(0x5D4594, 599482) = (unsigned char)v1[103];
	*getMemU32Ptr(0x5D4594, 599484) = (unsigned char)v1[104];
	*getMemU32Ptr(0x5D4594, 599488) = *((uint32_t*)v1 + 10);
	*getMemU32Ptr(0x5D4594, 599492) = sub_4200E0();
	*getMemU8Ptr(0x5D4594, 599502) = (v2[53] & 0xC0) != 0;
	v3 = *((uint16_t*)v2 + 26);
	if (v3 & 0x100) {
		dword_5d4594_599496 = 0;
	} else if (v3 & 0x20) {
		dword_5d4594_599496 = 1;
	} else if (v3 & 0x40) {
		dword_5d4594_599496 = 2;
	} else if (v3 & 0x10) {
		dword_5d4594_599496 = 3;
	} else if (v3 & 0x400) {
		dword_5d4594_599496 = 4;
	}
	*getMemU8Ptr(0x5D4594, 599500) = (v2[53] & 0x40) == 0;
	*getMemU32Ptr(0x5D4594, 599508) = *((unsigned short*)v2 + 27);
	*getMemU32Ptr(0x5D4594, 599512) = (unsigned char)v2[56];
	*getMemU8Ptr(0x5D4594, 599516) = v1[100];
	*getMemU32Ptr(0x5D4594, 599520) = v1[101] & 0xF;
	*getMemU32Ptr(0x5D4594, 599524) = (unsigned char)v1[101] >> 4;
	*getMemU32Ptr(0x5D4594, 599528) = *(unsigned short*)(v1 + 105);
	*getMemU32Ptr(0x5D4594, 599532) = *(unsigned short*)(v1 + 107);
	*getMemU8Ptr(0x5D4594, 599536) = v1[102];
	*getMemU8Ptr(0x5D4594, 599537) = v1[100] & 0x30;
	*getMemU8Ptr(0x5D4594, 599501) = sub_417DE0();
	strncpy((char*)getMemAt(0x5D4594, 599828), v2 + 9, 0xFu);
	*getMemU8Ptr(0x5D4594, 599843) = 0;
	memcpy(getMemAt(0x5D4594, 599540), v2 + 24, 0x64u);
	*getMemU32Ptr(0x5D4594, 599564) = *((uint32_t*)v2 + 12);
	*getMemU32Ptr(0x5D4594, 599560) = *((uint32_t*)v2 + 11);
	strncpy((char*)getMemAt(0x5D4594, 599572), v2, 8u);
	*getMemU8Ptr(0x5D4594, 599580) = 0;
	*getMemU32Ptr(0x5D4594, 600112) = 0;
	*getMemU32Ptr(0x5D4594, 600084) = 0;
	*getMemU32Ptr(0x5D4594, 600088) = 0;
	*getMemU32Ptr(0x5D4594, 600092) = 0;
	*getMemU32Ptr(0x5D4594, 600096) = 0;
}

//----- (004263C0) --------------------------------------------------------
char* nox_xxx_net_4263C0() {
	char* result; // eax
	char* i;      // eax
	char* v2;     // eax
	int j;        // esi

	result = (char*)nox_common_gameFlags_check_40A5C0(0x2000);
	if (result) {
		result = (char*)nox_common_gameFlags_check_40A5C0(4096);
		if (!result) {
			sub_4282F0((int)getMemAt(0x5D4594, 599476), (int)getMemAt(0x5D4594, 600124),
					   *(size_t*)&dword_5d4594_608316);
			sub_428540((int)getMemAt(0x5D4594, 599476), (char*)getMemAt(0x5D4594, 608320), *(int*)&dword_5d4594_739392);
			*getMemU32Ptr(0x5D4594, 599504) = time(0) - dword_5d4594_600116;
			sub_428810((int)getMemAt(0x5D4594, 599476), 1);
			memset(getMemAt(0x5D4594, 600124), 0, 0x2000u);
			memset(getMemAt(0x5D4594, 608320), 0, 0x20000u);
			dword_5d4594_608316 = 0;
			dword_5d4594_739392 = 0;
			for (i = nox_common_playerInfoGetFirst_416EA0(); i; i = nox_common_playerInfoGetNext_416EE0((int)i)) {
				*((uint32_t*)i + 1162) = -1;
			}
			v2 = nox_common_playerInfoFromNum_417090(31);
			if (v2) {
				sub_425F10((int)v2);
			}
			result = nox_common_playerInfoGetFirst_416EA0();
			for (j = (int)result; result; j = (int)result) {
				if (*(uint8_t*)(j + 2064) != 31) {
					sub_425F10(j);
				}
				result = nox_common_playerInfoGetNext_416EE0(j);
			}
		}
	}
	return result;
}

//----- (004264D0) --------------------------------------------------------
int sub_4264D0() {
	char* i; // esi

	if (!nox_common_gameFlags_check_40A5C0(0x2000) || nox_common_gameFlags_check_40A5C0(4096)) {
		if (nox_common_gameFlags_check_40A5C0(4096)) {
			*getMemU32Ptr(0x5D4594, 739416) = time(0) - dword_5d4594_600116;
		}
	} else {
		for (i = nox_common_playerInfoGetFirst_416EA0(); i; i = nox_common_playerInfoGetNext_416EE0((int)i)) {
			sub_425E90((int)i, 1);
		}
		*getMemU32Ptr(0x5D4594, 599504) = time(0) - dword_5d4594_600116;
	}
	if (!nox_common_gameFlags_check_40A5C0(4096)) {
		return sub_428810((int)getMemAt(0x5D4594, 599476), 2);
	}
	sub_4285C0(getMemI16Ptr(0x5D4594, 739396));
	return sub_428890(getMemI16Ptr(0x5D4594, 739396));
}

//----- (00426A30) --------------------------------------------------------
int nox_xxx_wallGet_426A30() { return *getMemU32Ptr(0x5D4594, 739992); }

//----- (00426A70) --------------------------------------------------------
char* nox_xxx_mapGetWallSize_426A70() { return (char*)getMemAt(0x5D4594, 739980); }

//----- (00426A80) --------------------------------------------------------
void nox_xxx_mapWall_426A80(int* a1) {
	*getMemU32Ptr(0x5D4594, 739980) = a1[0];
	*getMemU32Ptr(0x5D4594, 739984) = a1[1];
}

//----- (00427010) --------------------------------------------------------
int nox_xxx_guide_427010(const char* a1) {
	int v1;          // ebp
	const char** v2; // edi

	v1 = 0;
	v2 = (const char**)getMemAt(0x587000, 70500);
	while (strcmp(*v2, a1)) {
		++v2;
		++v1;
		if ((int)v2 >= (int)getMemAt(0x587000, 70664)) {
			return 0;
		}
	}
	return v1;
}

//----- (00427230) --------------------------------------------------------
char* nox_xxx_guideNameByN_427230(int a1) { return *(char**)getMemAt(0x587000, 70500 + 4 * a1); }

//----- (00427240) --------------------------------------------------------
int nox_xxx_guiCreatureGetName_427240(int a1) {
	int result; // eax

	if (a1 > 0 && a1 < 41 && *getMemU32Ptr(0x5D4594, 740080 + 28 * a1)) {
		result = *getMemU32Ptr(0x5D4594, 740076 + 28 * a1);
	} else {
		result = 0;
	}
	return result;
}

//----- (004272B0) --------------------------------------------------------
int nox_xxx_creatureIsCharmableByTT_4272B0(int a1) {
	int result;        // eax
	unsigned char* v2; // ecx

	result = 1;
	v2 = getMemAt(0x5D4594, 740108);
	while (!*(uint32_t*)v2 || *(uint32_t*)v2 != a1) {
		v2 += 28;
		++result;
		if ((int)v2 >= (int)getMemAt(0x5D4594, 741228)) {
			return 0;
		}
	}
	return result;
}

//----- (004272E0) --------------------------------------------------------
int nox_xxx_guideGetDescById_4272E0(int a1) { return *getMemU32Ptr(0x5D4594, 740084 + 28 * a1); }

//----- (00427300) --------------------------------------------------------
int nox_xxx_bookGetFirstCreMB_427300() {
	int result;        // eax
	unsigned char* v1; // ecx

	result = 1;
	v1 = getMemAt(0x5D4594, 740108);
	while (!*(uint32_t*)v1) {
		v1 += 28;
		++result;
		if ((int)v1 >= (int)getMemAt(0x5D4594, 741228)) {
			return 0;
		}
	}
	return result;
}

//----- (00427320) --------------------------------------------------------
int nox_xxx_bookGetNextCre_427320(int a1) {
	int result;        // eax
	unsigned char* v2; // ecx

	result = a1 + 1;
	if (a1 + 1 >= 41) {
		return 0;
	}
	v2 = getMemAt(0x5D4594, 740080 + 28 * result);
	while (!*(uint32_t*)v2) {
		v2 += 28;
		++result;
		if ((int)v2 >= (int)getMemAt(0x5D4594, 741228)) {
			return 0;
		}
	}
	return result;
}

//----- (00427400) --------------------------------------------------------
int nox_xxx_bookGetCreatureImg_427400(int a1) {
	int result; // eax

	if (a1 <= 0 || a1 >= 41) {
		result = 0;
	} else {
		result = *getMemU32Ptr(0x5D4594, 740092 + 28 * a1);
	}
	return result;
}

//----- (00427430) --------------------------------------------------------
int sub_427430(int a1) {
	int result; // eax

	if (a1 <= 0 || a1 >= 41) {
		result = 0;
	} else {
		result = *getMemU32Ptr(0x5D4594, 740088 + 28 * a1);
	}
	return result;
}

//----- (00427460) --------------------------------------------------------
unsigned char nox_xxx_guideGetUnitSize_427460(int a1) { return getMemByte(0x5D4594, 740100 + 28 * a1); }

//----- (00427490) --------------------------------------------------------
nox_playerInfo_journal* nox_xxx_journalEntryAdd_427490(nox_playerInfo* a1p, char* a2, short a3) {
	int a1 = a1p;
	uint8_t* result; // eax
	uint8_t* v4;     // esi
	int v5;          // eax

	result = calloc(1, 0x4Cu);
	v4 = result;
	if (result) {
		memset(result, 0, 0x4Cu);
		strncpy(result, a2, 0x3Fu);
		v4[63] = 0;
		*((uint16_t*)v4 + 36) = a3;
		*((uint32_t*)v4 + 17) = 0;
		*((uint32_t*)v4 + 16) = *(uint32_t*)(a1 + 3644);
		v5 = *(uint32_t*)(a1 + 3644);
		if (v5) {
			*(uint32_t*)(v5 + 68) = v4;
		}
		*(uint32_t*)(a1 + 3644) = v4;
		result = v4;
	}
	return result;
}

//----- (00427500) --------------------------------------------------------
void nox_xxx_comJournalEntryAdd_427500(nox_object_t* a1p, char* a2, short a3) {
	int a1 = a1p;
	int v3;      // esi
	uint8_t* v4; // eax

	v3 = *(uint32_t*)(*(uint32_t*)(a1 + 748) + 276);
	v4 = nox_xxx_journalEntryAdd_427490(v3, a2, a3);
	if (v4) {
		if (*(uint8_t*)(v3 + 2064) == 31) {
			nox_xxx_cliBuildJournalString_469BC0();
		} else {
			nox_xxx_netSendJournalAdd_4D9440(*(unsigned char*)(v3 + 2064), (int)v4);
		}
	}
}

//----- (00427590) --------------------------------------------------------
int nox_xxx_journalEntryRemove_427590(nox_playerInfo* a1p, const char* a2) {
	int a1 = a1p;
	int v2; // edi
	int v4; // eax
	int v5; // eax

	v2 = *(uint32_t*)(a1 + 3644);
	if (!v2) {
		return 0;
	}
	while (strcmp((const char*)v2, a2)) {
		v2 = *(uint32_t*)(v2 + 64);
		if (!v2) {
			return 0;
		}
	}
	v4 = *(uint32_t*)(v2 + 68);
	if (v4) {
		*(uint32_t*)(v4 + 64) = *(uint32_t*)(v2 + 64);
	}
	v5 = *(uint32_t*)(v2 + 64);
	if (v5) {
		*(uint32_t*)(v5 + 68) = *(uint32_t*)(v2 + 68);
	}
	if (v2 == *(uint32_t*)(a1 + 3644)) {
		*(uint32_t*)(a1 + 3644) = *(uint32_t*)(v2 + 64);
	}
	free((void*)v2);
	return 1;
}

//----- (00427630) --------------------------------------------------------
void nox_xxx_comJournalEntryRemove_427630(int a1, const char* a2) {
	int v2; // esi

	v2 = *(uint32_t*)(*(uint32_t*)(a1 + 748) + 276);
	if (nox_xxx_journalEntryRemove_427590(v2, a2)) {
		if (*(uint8_t*)(v2 + 2064) == 31) {
			nox_xxx_cliBuildJournalString_469BC0();
		} else {
			nox_xxx_netSendJournalRemove_4D94A0(*(unsigned char*)(v2 + 2064), a2);
		}
	}
}

//----- (00427680) --------------------------------------------------------
int nox_xxx_comRemoveEntryAll_427680(const char* a1) {
	int result; // eax
	int i;      // esi

	result = nox_xxx_getFirstPlayerUnit_4DA7C0();
	for (i = result; result; i = result) {
		nox_xxx_comJournalEntryRemove_427630(i, a1);
		result = nox_xxx_getNextPlayerUnit_4DA7F0(i);
	}
	return result;
}

//----- (004276B0) --------------------------------------------------------
int nox_xxx_journalUpdateEntry_4276B0(nox_playerInfo* a1p, const char* a2, short a3) {
	int a1 = a1p;
	int v3;     // edi
	int result; // eax

	v3 = *(uint32_t*)(a1 + 3644);
	if (!v3) {
		return 0;
	}
	while (strcmp((const char*)v3, a2)) {
		v3 = *(uint32_t*)(v3 + 64);
		if (!v3) {
			return 0;
		}
	}
	result = v3;
	*(uint16_t*)(v3 + 72) = a3;
	return result;
}

//----- (00427720) --------------------------------------------------------
int nox_xxx_comJournalEntryUpdate_427720(int a1, const char* a2, short a3) {
	int v3;     // esi
	int result; // eax

	v3 = *(uint32_t*)(*(uint32_t*)(a1 + 748) + 276);
	result = nox_xxx_journalUpdateEntry_4276B0(v3, a2, a3);
	if (result) {
		if (*(uint8_t*)(v3 + 2064) != 31) {
			result = nox_xxx_netSendJournalUpdate_4D9500(*(unsigned char*)(v3 + 2064), result);
		}
	}
	return result;
}

//----- (00427770) --------------------------------------------------------
int nox_xxx_comUpdateEntryAll_427770(const char* a1, short a2) {
	int result; // eax
	int i;      // esi

	result = nox_xxx_getFirstPlayerUnit_4DA7C0();
	for (i = result; result; i = result) {
		nox_xxx_comJournalEntryUpdate_427720(i, a1, a2);
		result = nox_xxx_getNextPlayerUnit_4DA7F0(i);
	}
	return result;
}

//----- (004277B0) --------------------------------------------------------
// This removes player's journal with matching bitmask
int sub_4277B0(nox_object_t* a1p, unsigned short a2) {
	int a1 = a1p;
	int v2;     // edi
	int result; // eax
	int v4;     // esi
	int v5;     // edx
	int v6;     // ecx

	v2 = *(uint32_t*)(*(uint32_t*)(a1 + 748) + 276);
	result = *(uint32_t*)(v2 + 3644);
	if (result) {
		do {
			v4 = *(uint32_t*)(result + 64);
			if (a2 & *(uint16_t*)(result + 72)) {
				v5 = *(uint32_t*)(result + 68);
				if (v5) {
					*(uint32_t*)(v5 + 64) = *(uint32_t*)(result + 64);
				}
				v6 = *(uint32_t*)(result + 64);
				if (v6) {
					*(uint32_t*)(v6 + 68) = *(uint32_t*)(result + 68);
				}
				if (result == *(uint32_t*)(v2 + 3644)) {
					*(uint32_t*)(v2 + 3644) = *(uint32_t*)(result + 64);
				}
				free((void*)result);
			}
			result = v4;
		} while (v4);
	}
	return result;
}

//----- (004278B0) --------------------------------------------------------
int sub_4278B0(float* a1, float* a2, float* a3) {
	double v3; // st7
	double v4; // st7

	*(float*)&dword_5d4594_741244 = a1[2] - *a1;
	*(float*)&dword_5d4594_741248 = a1[3] - a1[1];
	*(float*)&dword_5d4594_741252 = a2[2] - *a2;
	*(float*)&dword_5d4594_741256 = a2[3] - a2[1];
	*(float*)&dword_5d4594_741260 = *a2 - *a1;
	v3 = a2[1] - a1[1];
	*getMemFloatPtr(0x5D4594, 741264) = v3;
	*(float*)&dword_5d4594_741292 =
		v3 * *(float*)&dword_5d4594_741244 - *(float*)&dword_5d4594_741260 * *(float*)&dword_5d4594_741248;
	v4 = *(float*)&dword_5d4594_741252 * *(float*)&dword_5d4594_741248 -
		 *(float*)&dword_5d4594_741256 * *(float*)&dword_5d4594_741244;
	*(float*)&dword_5d4594_741284 = v4;
	if (v4 == 0.0) {
		return 0;
	}
	*a3 = *(float*)&dword_5d4594_741292 * *(float*)&dword_5d4594_741252 / *(float*)&dword_5d4594_741284 + *a2;
	a3[1] = *(float*)&dword_5d4594_741292 * *(float*)&dword_5d4594_741256 / *(float*)&dword_5d4594_741284 + a2[1];
	return 1;
}

//----- (00427980) --------------------------------------------------------
int sub_427980(float4* a1, float4* a2) {
	double v2;  // st7
	float v3;   // ecx
	float v4;   // eax
	float v5;   // eax
	int result; // eax
	double v7;  // st7
	float v8;   // [esp+4h] [ebp+4h]
	float v9;   // [esp+4h] [ebp+4h]

	if (a1->field_0 >= (double)a1->field_8) {
		*getMemFloatPtr(0x5D4594, 741268) = a1->field_8;
		v2 = a1->field_0;
	} else {
		*getMemFloatPtr(0x5D4594, 741268) = a1->field_0;
		v2 = a1->field_8;
	}
	*getMemFloatPtr(0x5D4594, 741276) = v2;
	if (a1->field_4 >= (double)a1->field_C) {
		*getMemFloatPtr(0x5D4594, 741272) = a1->field_C;
		v3 = a1->field_4;
	} else {
		*getMemFloatPtr(0x5D4594, 741272) = a1->field_4;
		v3 = a1->field_C;
	}
	*getMemFloatPtr(0x5D4594, 741280) = v3;
	if (a2->field_0 >= (double)a2->field_8) {
		*getMemFloatPtr(0x5D4594, 741228) = a2->field_8;
		v4 = a2->field_0;
	} else {
		*getMemFloatPtr(0x5D4594, 741228) = a2->field_0;
		v4 = a2->field_8;
	}
	*getMemFloatPtr(0x5D4594, 741236) = v4;
	if (a2->field_4 >= (double)a2->field_C) {
		*getMemFloatPtr(0x5D4594, 741232) = a2->field_C;
		v5 = a2->field_4;
	} else {
		*getMemFloatPtr(0x5D4594, 741232) = a2->field_4;
		v5 = a2->field_C;
	}
	*getMemFloatPtr(0x5D4594, 741240) = v5;
	if (v2 < *getMemFloatPtr(0x5D4594, 741228) ||
		*getMemFloatPtr(0x5D4594, 741268) > (double)*getMemFloatPtr(0x5D4594, 741236) ||
		*getMemFloatPtr(0x5D4594, 741280) < (double)*getMemFloatPtr(0x5D4594, 741232) ||
		*getMemFloatPtr(0x5D4594, 741272) > (double)*getMemFloatPtr(0x5D4594, 741240)) {
		return 0;
	}
	if (a1->field_4 == a1->field_C && a2->field_4 == a2->field_C) {
		return 1;
	}
	*(float*)&dword_5d4594_741244 = a1->field_8 - a1->field_0;
	*(float*)&dword_5d4594_741248 = a1->field_C - a1->field_4;
	*(float*)&dword_5d4594_741252 = a2->field_8 - a2->field_0;
	*(float*)&dword_5d4594_741256 = a2->field_C - a2->field_4;
	*(float*)&dword_5d4594_741260 = a2->field_0 - a1->field_0;
	v7 = a2->field_4 - a1->field_4;
	*getMemFloatPtr(0x5D4594, 741264) = v7;
	*(float*)&dword_5d4594_741292 =
		v7 * *(float*)&dword_5d4594_741244 - *(float*)&dword_5d4594_741260 * *(float*)&dword_5d4594_741248;
	*(float*)&dword_5d4594_741284 = *(float*)&dword_5d4594_741252 * *(float*)&dword_5d4594_741248 -
									*(float*)&dword_5d4594_741256 * *(float*)&dword_5d4594_741244;
	if (*(float*)&dword_5d4594_741292 == 0.0 || *(float*)&dword_5d4594_741284 == 0.0 ||
		*(float*)&dword_5d4594_741292 < 0.0 && *(float*)&dword_5d4594_741284 > 0.0) {
		return 0;
	}
	if (*(float*)&dword_5d4594_741292 > 0.0 && *(float*)&dword_5d4594_741284 < 0.0 ||
		(v8 = sub_419A10(*(float*)&dword_5d4594_741292), sub_419A10(*(float*)&dword_5d4594_741284) < v8) ||
		(*getMemU32Ptr(0x5D4594, 741288) = dword_5d4594_741284,
		 *(float*)& dword_5d4594_741296 = *getMemFloatPtr(0x5D4594, 741264) * *(float*)&dword_5d4594_741252 -
										  *(float*)&dword_5d4594_741260 * *(float*)&dword_5d4594_741256,
		 *(float*)&dword_5d4594_741296 < 0.0) &&
			*(float*)&dword_5d4594_741284 > 0.0 ||
		*(float*)&dword_5d4594_741296 > 0.0 && *(float*)&dword_5d4594_741284 < 0.0 ||
		(v9 = sub_419A10(*(float*)&dword_5d4594_741296), sub_419A10(*getMemFloatPtr(0x5D4594, 741288)) < v9)) {
		return 0;
	}
	return 1;
}

//----- (00427C80) --------------------------------------------------------
int sub_427C80(int4* a1, int4* a2) {
	int v2;    // eax
	int v3;    // ecx
	int v4;    // esi
	int v5;    // ebp
	int v6;    // edx
	int v7;    // edi
	int v8;    // ebx
	int v10;   // ebp
	int v11;   // edx
	int v12;   // ebp
	int v13;   // esi
	int v14;   // ecx
	int v15;   // eax
	int v16;   // esi
	int v17;   // [esp+10h] [ebp-10h]
	int v18;   // [esp+14h] [ebp-Ch]
	int v19;   // [esp+18h] [ebp-8h]
	int v20;   // [esp+1Ch] [ebp-4h]
	int v21;   // [esp+24h] [ebp+4h]
	int4* v22; // [esp+28h] [ebp+8h]
	int4* v23; // [esp+28h] [ebp+8h]

	v2 = a1->field_0;
	v3 = a1->field_4;
	v4 = a1->field_8;
	v19 = a1->field_C;
	v5 = a2->field_0;
	v21 = a2->field_4;
	v17 = a2->field_C;
	v6 = a2->field_8;
	v7 = v4 - v2;
	v8 = a2->field_0 - v6;
	v20 = a2->field_0;
	if (v4 - v2 >= 0) {
		v6 = a2->field_8;
		v22 = (int4*)v2;
	} else {
		v22 = (int4*)v4;
		v4 = v2;
	}
	if (v8 <= 0) {
		if (v4 < v5 || v6 < (int)v22) {
			return 0;
		}
	} else if (v4 < v6 || v5 < (int)v22) {
		return 0;
	}
	v10 = v19;
	v11 = v21 - v17;
	v18 = v19 - v3;
	if (v19 - v3 >= 0) {
		v23 = (int4*)v3;
	} else {
		v23 = (int4*)v19;
		v10 = v3;
	}
	if (v11 <= 0) {
		if (v10 < v21 || v17 < (int)v23) {
			return 0;
		}
	} else {
		if (v10 < v17) {
			return 0;
		}
		if (v21 < (int)v23) {
			return 0;
		}
	}
	v12 = v2 - v20;
	v13 = v3 - v21;
	v14 = v11 * (v2 - v20) - v8 * (v3 - v21);
	v15 = v8 * v18 - v7 * v11;
	if (v15 <= 0) {
		if (v14 > 0 || v14 < v15) {
			return 0;
		}
	} else {
		if (v14 < 0) {
			return 0;
		}
		if (v14 > v15) {
			return 0;
		}
	}
	v16 = v7 * v13 - v18 * v12;
	if (v15 <= 0) {
		if (v16 <= 0 && v16 >= v15) {
			return 1;
		}
		return 0;
	}
	if (v16 < 0) {
		return 0;
	}
	if (v16 > v15) {
		return 0;
	}
	return 1;
}

//----- (00427DF0) --------------------------------------------------------
int sub_427DF0(int a1, int* a2, float a3) {
	double v3; // st7
	double v4; // st7
	double v6; // st7
	float v7;  // [esp+Ch] [ebp-1Ch]
	float v8;  // [esp+10h] [ebp-18h]
	float v9;  // [esp+10h] [ebp-18h]
	float v10; // [esp+10h] [ebp-18h]
	float v11; // [esp+14h] [ebp-14h]
	float v12; // [esp+14h] [ebp-14h]
	float v13; // [esp+14h] [ebp-14h]
	float v14; // [esp+18h] [ebp-10h]
	float v15; // [esp+1Ch] [ebp-Ch]
	float v16; // [esp+20h] [ebp-8h]
	float v17; // [esp+24h] [ebp-4h]
	float v18; // [esp+30h] [ebp+8h]

	v16 = (double)*a2;
	v17 = (double)a2[1];
	v8 = (double)a2[2] - v16;
	v3 = (double)a2[3] - v17;
	v11 = v3;
	v7 = nox_double2float(sqrt(v3 * v11 + v8 * v8));
	v14 = v8 / v7;
	v4 = v11 / v7;
	v15 = v4;
	v9 = (double)*(int*)a1 - v16;
	v12 = (double)*(int*)(a1 + 4) - v17;
	if (nox_double2float(fabs(v9 * -v4 + v12 * v14)) > a3) {
		return 0;
	}
	v6 = v12 * v15 + v9 * v14;
	v18 = v6;
	if (v6 > v7) {
		return 0;
	}
	if (v18 < 0.0) {
		return 0;
	}
	v10 = v18 * v14 + v16;
	v13 = v18 * v15 + v17;
	*(uint32_t*)a1 = nox_float2int(v10);
	*(uint32_t*)(a1 + 4) = nox_float2int(v13);
	return 1;
}
