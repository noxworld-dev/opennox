#define DG_DYNARR_IMPLEMENTATION
#include "GameEx.h"
#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_3.h"
#include "GAME3_1.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4.h"
#include "GAME5_2.h"
#include "client__gui__guimsg.h"
#include "client__gui__window.h"
#include "common/fs/nox_fs.h"
#include "memmap.h"

#include "client__shell__noxworld.h"
#include "operators.h"

extern int nox_win_width_game;
extern int nox_win_height_game;
extern int dword_5d4594_3484;
extern nox_object_t* nox_xxx_host_player_unit_3843628;
extern nox_window* dword_5d4594_1064896;
extern void* nox_win_activeWindow_1064900;
extern unsigned int dword_587000_87404;
extern unsigned int dword_5d4594_1064868;
extern unsigned int dword_5d4594_1316972;
extern uint32_t nox_player_netCode_85319C;
extern nox_net_struct_t* nox_net_struct_arr[NOX_NET_STRUCT_MAX];
extern nox_window* nox_win_unk3;

//-------------------------------------------------------------------------
// Data declarations

unsigned int gameex_flags = 0x1E;

int DefaultPacket[4] = {171901697, 1, 347, 44391266}; // weak
wchar_t wndEntryNames[5][35] = {
	{119u, 97u,  114u, 114u, 105u, 111u, 114u, 115u, 32u, 108u, 105u, 107u, 101u, 32u, 115u, 104u, 105u, 101u,
	 108u, 100u, 115u, 0u,   0u,   0u,   0u,   0u,   0u,  0u,   0u,   0u,   0u,   0u,  0u,   0u,   0u},
	{119u, 97u, 108u, 107u, 105u, 110u, 103u, 32u, 119u, 105u, 116u, 104u, 32u, 115u, 119u, 111u, 114u, 100u,
	 32u,  98u, 108u, 111u, 99u,  107u, 0u,   0u,  0u,   0u,   0u,   0u,   0u,  0u,   0u,   0u,   0u},
	{119u, 101u, 97u, 112u, 111u, 110u, 32u, 114u, 111u, 108u, 108u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
	 0u,   0u,   0u,  0u,   0u,   0u,   0u,  0u,   0u,   0u,   0u,   0u, 0u, 0u, 0u, 0u, 0u},
	{115u, 104u, 105u, 101u, 108u, 100u, 32u,  38u,  32u,  98u, 101u, 114u, 115u, 101u, 114u, 107u, 101u, 114u,
	 32u,  98u,  108u, 111u, 99u,  107u, 105u, 110u, 103u, 0u,  0u,   0u,   0u,   0u,   0u,   0u,   0u},
	{101u, 120u, 116u, 101u, 110u, 115u, 105u, 111u, 110u, 32u, 109u, 101u, 115u, 115u, 97u, 103u, 101u, 115u,
	 0u,   0u,   0u,   0u,   0u,   0u,   0u,   0u,   0u,   0u,  0u,   0u,   0u,   0u,   0u,  0u,   0u}};
char someSwitch = 0;        // weak
char isInvalidIp = 0;       // weak
char inputNewIpMsgBox[512]; // weak


int nox_CharToOemW(const wchar_t* pSrc, char* pDst) { return nox_sprintf(pDst, "%S", pSrc); }

//----- (10001A20) --------------------------------------------------------
int gameex_sendPacket(char* buf, int len, int smth) {
	if (!buf || !len || *getMemU32Ptr(0x5D4594, 815700) >= NOX_NET_STRUCT_MAX) {
		return 0;
	}
	// 0x69B7E8 = netSocketData
	nox_net_struct_t* ns = nox_net_struct_arr[*getMemU32Ptr(0x5D4594, 815700)];
	if (!ns) {
		return 0;
	}
	return nox_net_sendto(ns->sock, buf, len, &ns->addr);
}

//----- (10001AD0) --------------------------------------------------------
void gameex_makeExtensionPacket(int ptr, short opcode, bool needsPlayer) {
	*(uint16_t*)(ptr + 0) = 0xF13A; // extension packet code
	*(uint16_t*)(ptr + 2) = opcode;
	if (needsPlayer)
		*(uint32_t*)(ptr + 4) = (nox_player_netCode_85319C); // playerNetCode
}

//----- (10001C20) --------------------------------------------------------
char getPlayerClassFromObjPtr(int a1) { return *(uint8_t*)(*(uint32_t*)(*(uint32_t*)(a1 + 748) + 276) + 2251); }

//----- (10001D40) --------------------------------------------------------
char playerInfoStructParser_0(char* a1) {
	char* v1;  // esi
	char pDst; // [esp+10h] [ebp-18h]

	if (a1 == (char*)-2)
		return 0;
	v1 = nox_common_playerInfoGetFirst_416EA0();
	if (!v1)
		return 0;
	while (1) {
		nox_CharToOemW((const wchar_t*)v1 + 2352, &pDst);
		if (!strcmp(&pDst, a1 + 2))
			break;
		v1 = nox_common_playerInfoGetNext_416EE0((int)v1);
		if (!v1)
			return 0;
	}
	a1[1] = *((uint8_t*)nox_xxx_objGetTeamByNetCode_418C80(*((uint32_t*)v1 + 515)) + 4);
	*a1 = v1[2251];
	return 1;
}

//----- (10001E10) --------------------------------------------------------
char playerInfoStructParser_1(int a1, int a2, int* a3) {
	char* v3;     // eax
	char* v4;     // eax
	uint32_t* v6; // eax
	char pDst;    // [esp+Ch] [ebp-18h]

	if (a1 == -2)
		return 0;
	v3 = nox_common_playerInfoGetFirst_416EA0();
	*(uint32_t*)a2 = v3;
	if (!v3)
		return 0;
	while (1) {
		nox_CharToOemW((const wchar_t*)(*(uint32_t*)a2 + 4704), &pDst);
		if (!strcmp(&pDst, (const char*)(a1 + 2)))
			break;
		v4 = nox_common_playerInfoGetNext_416EE0(a2);
		*(uint32_t*)a2 = v4;
		if (!v4)
			return 0;
	}
	v6 = nox_xxx_objGetTeamByNetCode_418C80(*(uint32_t*)(*(uint32_t*)a2 + 2060));
	*a3 = (int)v6;
	*(uint8_t*)(a1 + 1) = *((uint8_t*)v6 + 4);
	*(uint8_t*)a1 = *(uint8_t*)(*(uint32_t*)a2 + 2251);
	return 1;
}

//----- (10001EE0) --------------------------------------------------------
char mix_MouseKeyboardWeaponRoll(int playerObj, char a2) {
	int v2;        // esi
	signed int v4; // edi
	int i;         // esi MAPDST
	int v6;        // eax
	int v8;        // eax
	int weapFlags; // eax
	int v11;       // eax
	char v16;      // [esp+Fh] [ebp-1h]

	v16 = 0;
	v2 = *(uint32_t*)(playerObj + 748);
	if (!(*(uint8_t*)(*(uint32_t*)(v2 + 276) + 3680) & 3) && *(uint8_t*)(v2 + 88) != 1) {
		int cur = *(uint32_t*)(v2 + 104);
		v4 = 496;
		if (!a2)
			v4 = 500;
		if (cur) {
			int next = cur;
			while (1) {
				next = *(uint32_t*)(next + v4);
				if (!next)
					break;
				weapFlags = nox_xxx_weaponInventoryEquipFlags_415820(next); // weaponEquipFlags
				if (weapFlags && weapFlags != 2) {
					if (nox_xxx_playerClassCanUseItem_57B3D0(
							next, *(uint8_t*)(*(uint32_t*)(*(uint32_t*)(playerObj + 748) + 276) + 2251))) {
						v11 = nox_xxx_playerCheckStrength_4F3180(playerObj, next);
						if (v11) {
							if (nox_xxx_playerTryDequip_4F2FB0((uint32_t*)playerObj, (const nox_object_t*)cur) &&
								nox_xxx_playerTryEquip_4F2F70((uint32_t*)playerObj, next)) {
								v16 = 1;
							}
							return v16;
						}
					}
				}
			}
		} else {
			for (i = *(uint32_t*)(playerObj + 504); i; i = *(uint32_t*)(i + 496)) {
				v6 = nox_xxx_weaponInventoryEquipFlags_415820(i); // weaponEquipFlags
				if (v6 && v6 != 2) {
					if (nox_xxx_playerClassCanUseItem_57B3D0(
							i, *(uint8_t*)(*(uint32_t*)(*(uint32_t*)(playerObj + 0x2EC) + 0x114) + 0x8CB))) {
						v8 = nox_xxx_playerCheckStrength_4F3180(playerObj, i);
						if (v8) {
							if (nox_xxx_playerTryEquip_4F2F70((uint32_t*)playerObj, i)) {
								v16 = 1;
							}
							return v16;
						}
					}
				}
			}
		}
	}
	return v16;
}
/* Orphan comments:
playerCanUseItem
playerCheckStrength
*/

//----- (10002030) --------------------------------------------------------
char playerDropATrap(int playerObj) {
	int v2; // eax
	int i;  // esi
	// int v5; // [esp+10h] [ebp-14h]
	char v7; // [esp+18h] [ebp-Ch]
	char v8; // [esp+1Fh] [ebp-5h]
	float pos[2] = {0};

	v7 = 17;
	if (!playerObj)
		return 0;
	v8 = 0;
	v2 = *(uint32_t*)(*(uint32_t*)(playerObj + 0x2EC) + 0x114);
	pos[0] = *(float*)(v2 + 0xE30);
	pos[1] = *(float*)(v2 + 0xE34);
	if (!(*(uint8_t*)(*(uint32_t*)(*(uint32_t*)(playerObj + 0x2EC) + 0x114) + 0xE60) &
		  3) // check playerGameStatus/isObs
		&& *(uint8_t*)(*(uint32_t*)(playerObj + 0x2EC) + 0x58) != 1) {
		for (i = *(uint32_t*)(playerObj + 0x1F8); i; i = *(uint32_t*)(i + 0x1F0)) {
			if (*(uint8_t*)(i + 0xA) == v7) // check if something from *(byte*)(unit+0xA)=17
			{
				nox_xxx_drop_4ED810(playerObj, i, pos); // drop this item
				return 1;
			}
		}
	}
	return v8;
}

//----- (10002680) --------------------------------------------------------
int MixRecvFromReplacer(nox_socket_t s, char* buf, int len, struct nox_net_sockaddr* from) {
	uint32_t* v8; // esi
	char v9;      // al
	int v10;      // esi
	int v11;      // edx
	// uint32_t *v12; // esi
	char* v13; // edi
	// int v14; // eax
	// unsigned int v15; // esi
	// int *v16; // eax
	// int v17; // eax
	char* v18;          // eax
	char v19;           // cl
	char* v20;          // eax
	char* v21;          // edx
	char v22;           // cl
	int v23;            // edx
	int v24;            // eax
	int v25;            // ecx
	char* v26;          // edi
	char* v27;          // eax
	char v28;           // cl
	unsigned int v29;   // kr00_4
	char* v30;          // edx
	unsigned int v31;   // ecx
	unsigned char* v32; // esi
	char v33;           // bl
	uint32_t* v35;      // eax
	char v36;           // [esp+17h] [ebp-CDh]
	// int a1[2]; // [esp+1Ch] [ebp-C8h]
	struct nox_net_sockaddr* to; // [esp+24h] [ebp-C0h]
	int v39;                     // [esp+28h] [ebp-BCh]
	// int a2[2]; // [esp+34h] [ebp-B0h]
	int v43[6];              // [esp+3Ch] [ebp-A8h]
	unsigned char v44[0x80]; // [esp+54h] [ebp-90h]
	// int v45; // [esp+E0h] [ebp-4h]

	to = from;
	int op = *((unsigned short*)buf + 1);
	switch (op) {
	case 0: // warrior weapon scroll
		if ((gameex_flags >> 3) & 1) {
			v8 = nox_xxx_objGetTeamByNetCode_418C80(*((uint32_t*)buf + 1));
			v9 = buf[8];
			v10 = (int)(v8 - 12);
			v36 = ((unsigned int)v9 >> 4) & 1;
			if (v36)
				buf[8] = v9 & 0xEF;
			if (!getPlayerClassFromObjPtr(v10) || v36) {
				if (mix_MouseKeyboardWeaponRoll(v10, buf[8])) {
					*((uint16_t*)buf + 1) = 2;
					nox_net_sendto(s, buf, 4, from);
				}
			}
		}
		break;
	case 1u:
	case 6u:
		break;
	case 2u: // clientPlaySoundSpecial
		nox_xxx_clientPlaySoundSpecial_452D80(895, 100);
		break;
	case 4u:
		if (nox_common_gameFlags_check_40A5C0(1)) {
			if ((gameex_flags >> 5) & 1) {
				v18 = buf + 4;
				do {
					v19 = *v18;
					v18[(char*)v43 + 2 - (buf + 4)] = *v18;
					++v18;
				} while (v19);
				if (playerInfoStructParser_0((char*)v43)) {
					buf[2] = 6;
					v20 = nox_xxx_serverOptionsGetServername_40A4C0();
					v21 = (char*)v43 + 2;
					do {
						v22 = *v20;
						*v21++ = *v20++;
					} while (v22);
					v23 = v43[1];
					v24 = v43[2];
					*((uint32_t*)buf + 1) = v43[0];
					v25 = v43[3];
					*((uint32_t*)buf + 2) = v23;
					LOWORD(v23) = v43[4];
					*((uint32_t*)buf + 3) = v24;
					*((uint32_t*)buf + 4) = v25;
					*((uint16_t*)buf + 10) = v23;
					nox_net_sendto(s, buf, 22, from);
				}
			}
		}
		break;
	case 5u:
		if ((gameex_flags >> 5) & 1) {
			memset(v44, 0, 0x80u);
			mbstowcs((wchar_t*)v44, buf + 4, strlen(buf + 4));
			nox_xxx_printCentered_445490((wchar_t*)v44);
			nox_xxx_clientPlaySoundSpecial_452D80(901, 100);
		}
		break;
	case 7u:
		memset(v44, 0, 0x80u);
		mbstowcs((wchar_t*)v44, buf + 4, strlen(buf + 4));
		nox_xxx_printCentered_445490((wchar_t*)v44);
		nox_xxx_clientPlaySoundSpecial_452D80(901, 100);
		break;
	case 8u:
		if (nox_common_gameFlags_check_40A5C0(1) && (gameex_flags >> 5) & 1) {
			v26 = buf + 4;
			v27 = buf + 4;
			do {
				v28 = *v27;
				v27[(char*)v43 + 2 - (buf + 4)] = *v27;
				++v27;
			} while (v28);
			if (playerInfoStructParser_1((int)v43, (int)&to, &v39)) {
				buf[2] = 7;
				v29 = strlen((const char*)v43 + 2);
				v30 = &buf[v29 + 4];
				v31 = strlen(v30);
				if (v31) {
					v32 = (unsigned char*)(v44 - (unsigned char*)v30);
					do {
						v33 = *v30;
						v30[(uint32_t)v32] = *v30;
						++v30;
					} while (v33);
					memset(v26, 0, v29 + v31);
					strcpy(v26, (const char*)v44);
				}
			}
		}
		break;
	case 9u:
		if ((gameex_flags >> 3) & 1) {
			v35 = nox_xxx_objGetTeamByNetCode_418C80(*((uint32_t*)buf + 1));
			playerDropATrap((int)(v35 - 12));
		}
		break;
	}
	// replace Mix packet with a placeholder
	*((uint32_t*)buf + 0) = DefaultPacket[0];
	*((uint32_t*)buf + 1) = DefaultPacket[1];
	*((uint32_t*)buf + 2) = DefaultPacket[2];
	*((uint32_t*)buf + 3) = DefaultPacket[3];
	return 16;
}
// 1000EF00: using guessed type int DefaultPacket[4];

//----- (10002C30) --------------------------------------------------------
void OnLibraryNotice_256() {}
void OnLibraryNotice_259(uint32_t arg1) {}

void OnLibraryNotice_262(uint32_t arg1) {}
void OnLibraryNotice_263(uint32_t arg1) { nox_common_gameFlags_check_40A5C0(1); }
void OnLibraryNotice_264(uint32_t arg1) { nox_common_gameFlags_check_40A5C0(1); }
bool gameexSomeWeirdCheckFixmePlease();
void OnLibraryNotice_265(unsigned int arg1, unsigned int arg2, int arg3) {
	// toggles weapons by mouse wheel
	// autoshield is actually implemented in appendix of nox_xxx_playerDequipWeapon_53A140
	// a2a = (*(uint32_t*)(vaArg3 + 4) >> 7) & 1;
	char a2a = arg3 > 0; // scroll weapons back or forth
	if (arg2 == 2 && gameexSomeWeirdCheckFixmePlease()) {
		if ((gameex_flags >> 3) & 1) {
			if (nox_common_gameFlags_check_40A5C0(516)) {
				if (nox_common_gameFlags_check_40A5C0(1)) {
					if (nox_xxx_host_player_unit_3843628) { // playerObjServerHost
						if (!getPlayerClassFromObjPtr(nox_xxx_host_player_unit_3843628)) {
							if (mix_MouseKeyboardWeaponRoll(nox_xxx_host_player_unit_3843628, a2a))
								nox_xxx_clientPlaySoundSpecial_452D80(895, 100); // clientPlaySound
						}
					}
				} else {
					char buf[10];
					gameex_makeExtensionPacket((int)&buf, 0, 1);
					buf[8] = a2a;
					gameex_sendPacket(&buf, 9, 0);
				}
			}
		}
	}
}
void OnLibraryNotice_420(uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4) {
	int v23 = arg1;
	int v19 = arg2;
	uint32_t* v16 = getPlayerClassFromObjPtr(arg1);
	if (*(uint8_t*)(v19 + 0xA) != 17) {
		nox_xxx_inventoryServPlace_4F36F0(v23, v19, 1, 1);
		return;
	}
	char v17 = *(uint8_t*)(v19 + 4);
	if (v17 != 0x6A) {
		if ((v17 == 0x6B || v17 == 0x6D) && (uint8_t)v16) {
			goto ifIsWarrior;
		}
		nox_xxx_inventoryServPlace_4F36F0(v23, v19, 1, 1);
		return;
	}
	if ((uint8_t)v16 == 1) {
		nox_xxx_inventoryServPlace_4F36F0(v23, v19, 1, 1);
		return;
	}
ifIsWarrior:
	nox_xxx_netPriMsgToPlayer_4DA2C0(v23, (const char*)getMemAt(0x587000, 215732),
									 0); // 0x5BBAB4 = pickup.c:ObjectEquipClassFail
	nox_xxx_aud_501960(925, v23, 2, *(uint32_t*)(v23 + 36));
}

//----- (10004330) --------------------------------------------------------
int getFlagValueFromFlagIndex(signed int a1) {
	signed int v1;   // edx
	unsigned int v2; // eax
	signed int v3;   // ecx
	int result;      // eax

	v1 = 2;
	v2 = a1;
	if (a1 < 0)
		v2 = -a1;
	v3 = 1;
	while (1) {
		if (v2 & 1)
			v3 *= v1;
		v2 >>= 1;
		if (!v2)
			break;
		v1 *= v1;
	}
	if (a1 >= 0)
		result = v3;
	else
		result = 1 / v3;
	return result;
}
