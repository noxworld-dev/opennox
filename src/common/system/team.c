#include "team.h"
// FIXME
#include "../../client/gui/guimsg.h"
#include "../../client/gui/servopts/guiserv.h"
#include "../../proto.h"
extern _DWORD dword_5d4594_527660;

//----- (00417C60) --------------------------------------------------------
int sub_417C60() {
	unsigned __int8* v0; // eax
	unsigned __int8* v1; // esi

	memset(getMemAt(0x5D4594, 526292), 0, 0x550u);
	v0 = getMemAt(0x5D4594, 526292 + 72);
	do {
		*(v0 - 15) = 0;
		*(_DWORD*)v0 = 0;
		*((_DWORD*)v0 + 1) = 0;
		*((_DWORD*)v0 - 3) = 0;
		v0 += 80;
	} while ((int)v0 < (int)getMemAt(0x5D4594, 526292 + 1352));
	if (!*getMemU32Ptr(0x5D4594, 526288)) {
		v1 = getMemAt(0x587000, 54596);
		do {
			*(_DWORD*)v1 = nox_strman_loadString_40F1D0(*((char**)v1 - 1), 0, "C:\\NoxPost\\src\\common\\System\\team.c", 233);
			v1 += 16;
		} while ((int)v1 < (int)getMemAt(0x587000, 54756));
		*getMemU32Ptr(0x5D4594, 526288) = 1;
	}
	nox_xxx_SetGameplayFlag_417D50(2);
	nox_xxx_UnsetGameplayFlags_417D70(1);
	return nox_xxx_UnsetGameplayFlags_417D70(4);
}

//----- (00417E10) --------------------------------------------------------
int nox_xxx_createCoopTeam_417E10() {
	char* v0;    // esi
	_DWORD* v1;  // eax
	wchar_t* v2; // eax

	nox_xxx_setGameFlags_40A4D0(512);
	v0 = nox_xxx_clientGetTeamColor_418AB0(1);
	if (!v0)
		v0 = nox_xxx_teamCreate_4186D0(1);
	v1 = nox_xxx_objGetTeamByNetCode_418C80(*getMemIntPtr(0x5D4594, 2616328));
	if (v1)
		nox_xxx_createAtImpl_4191D0(v0[57], (int)v1, 0, *getMemIntPtr(0x5D4594, 2616328), 0);
	if (v0) {
		v2 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 55164), 0, "C:\\NoxPost\\src\\common\\System\\team.c", 405);
		sub_418800((wchar_t*)v0, v2, 0);
	}
	return nox_xxx_UnsetGameplayFlags_417D70(1);
}

//----- (004186D0) --------------------------------------------------------
char* __cdecl nox_xxx_teamCreate_4186D0(char a1) {
	wchar_t* v1;         // eax
	char* result;        // eax
	unsigned __int8 v3;  // al
	unsigned __int8 v4;  // bl
	int v5;              // esi
	char v6;             // al
	unsigned __int8* v7; // esi
	wchar_t* v8;         // eax

	if (getMemByte(0x5D4594, 526280) < 0x10u) {
		v3 = sub_4187E0();
		v4 = v3;
		v5 = 5 * v3;
		v6 = a1;
		v7 = getMemAt(0x5D4594, 526292 + 16 * v5);
		*((_DWORD*)v7 + 13) = 0;
		*((_DWORD*)v7 + 12) = 0;
		*(_WORD*)v7 = 0;
		*((_DWORD*)v7 + 17) = 0;
		*((_DWORD*)v7 + 11) = 0;
		*((_DWORD*)v7 + 15) = 0;
		v7[58] = v4;
		if (!a1)
			v6 = sub_4187A0();
		v7[57] = v6;
		v7[56] = v4;
		*((_DWORD*)v7 + 16) = 1;
		++*getMemU8Ptr( 0x5D4594, 526280);
		sub_459CD0();
		if (!nox_common_gameFlags_check_40A5C0(512)) {
			v8 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 55444), 0, "C:\\NoxPost\\src\\common\\System\\team.c", 1009);
			nox_xxx_consoleVPrint_450C00(6u, v8);
		}
		result = (char*)v7;
	} else {
		v1 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 55396), 0, "C:\\NoxPost\\src\\common\\System\\team.c", 982);
		nox_xxx_consoleVPrint_450C00(6u, v1);
		result = 0;
	}
	return result;
}

//----- (00418C20) --------------------------------------------------------
wchar_t* __cdecl sub_418C20(int a1) {
	int v1;              // ecx
	unsigned __int8* v2; // eax

	v1 = 0;
	v2 = getMemAt(0x587000, 54600);
	while (*(_DWORD*)v2 != a1) {
		v2 += 16;
		++v1;
		if ((int)v2 >= (int)getMemAt(0x587000, 54760))
			return nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 55492), 0, "C:\\NoxPost\\src\\common\\System\\team.c",
										 1365);
	}
	return *(wchar_t**)getMemAt(0x587000, 16 * v1 + 54596);
}

//----- (004191D0) --------------------------------------------------------
void nox_xxx_createAtImpl_4191D0(unsigned __int8 a1, int a2, int a3, int a4, int a5) {
	char* result;     // eax
	char* v6;         // esi
	int v7;           // ebx
	char* v8;         // ebp
	char* v9;         // ebp
	wchar_t* v10;     // eax
	wchar_t* v11;     // eax
	__int16 v12;      // dx
	int v13;          // eax
	_DWORD* v14;      // eax
	char* v15;        // ebx
	wchar_t* v16;     // eax
	wchar_t* v17;     // eax
	char* v18;        // esi
	int v19;          // edi
	int i;            // esi
	float2 v21;       // [esp+0h] [ebp-110h]
	__int16 v22;      // [esp+8h] [ebp-108h]
	char* v23;        // [esp+Ch] [ebp-104h]
	wchar_t v24[128]; // [esp+10h] [ebp-100h]

	result = *(char**)&dword_5d4594_527660;
	if (!dword_5d4594_527660) {
		result = (char*)nox_xxx_getNameId_4E3AA0((CHAR*)getMemAt(0x587000, 55500));
		dword_5d4594_527660 = result;
	}
	if (!a2) {
		return;
	}
	v6 = nox_xxx_clientGetTeamColor_418AB0(a1);
	if (v6) {
		result = (char*)nox_xxx_teamCompare2_419180(a2, a1);
		if (result)
			return;
	} else {
		v6 = nox_xxx_teamCreate_4186D0(a1);
	}
	*(_BYTE*)(a2 + 4) = v6[57];
	*(_DWORD*)a2 = *((_DWORD*)v6 + 11);
	*((_DWORD*)v6 + 11) = a2;
	if (a4 == *getMemU32Ptr(0x5D4594, 2616328))
		sub_455E70(v6[57]);
	if (nox_common_gameFlags_check_40A5C0(1)) {
		if (nox_common_gameFlags_check_40A5C0(0x2000)) {
			v7 = nox_server_getObjectFromNetCode_4ECCB0(a4);
			v8 = nox_common_playerInfoGetByID_417040(a4);
			v23 = v8;
			if (v8) {
				if (nox_common_gameFlags_check_40A5C0(0x8000))
					sub_425ED0((int)v8, 1);
				if (v7 && *(_BYTE*)(v7 + 8) & 4) {
					if (a5 == 1 && !nox_xxx_CheckGameplayFlags_417DA0(2) && nox_common_gameFlags_check_40A5C0(128)) {
						sub_4ED970(50.0, (float2*)(*((_DWORD*)v6 + 18) + 56), &v21);
						nox_xxx_unitMove_4E7010(v7, &v21);
					}
					v9 = nox_common_playerInfoGetByID_417040(a4);
					if (v9) {
						if (nox_common_gameFlags_check_40A5C0(4096)) {
							v10 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 55548), 0,
														"C:\\NoxPost\\src\\common\\System\\team.c", 1848);
							nox_swprintf(v24, v10, v9 + 4704);
						} else {
							v11 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 55616), 0,
														"C:\\NoxPost\\src\\common\\System\\team.c", 1850);
							nox_swprintf(v24, v11, v9 + 4704, v6);
						}
						nox_xxx_printCentered_445490(v24);
					}
					v8 = v23;
				}
			}
			if (a3 && v7 && (v8 || *(unsigned __int16*)(v7 + 4) == dword_5d4594_527660)) {
				v12 = *(_WORD*)(v7 + 4);
				v13 = (unsigned __int8)v6[57];
				LOWORD(v21.field_0) = 452;
				HIWORD(v21.field_4) = a4;
				*(_DWORD*)((char*)&v21.field_0 + 2) = v13;
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
					v16 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 55664), 0,
												"C:\\NoxPost\\src\\common\\System\\team.c", 1889);
					nox_swprintf(v24, v16, v15 + 4704);
				} else {
					v17 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 55732), 0,
												"C:\\NoxPost\\src\\common\\System\\team.c", 1891);
					nox_swprintf(v24, v17, v15 + 4704, v6);
				}
				nox_xxx_printCentered_445490(v24);
			}
		}
	}
	++*((_DWORD*)v6 + 12);
	result = (char*)nox_xxx_getFirstPlayerUnit_4DA7C0();
	v18 = result;
	if (!result) {
		return;
	}
	while (*((_DWORD*)v18 + 9) != a4) {
		result = (char*)nox_xxx_getNextPlayerUnit_4DA7F0((int)v18);
		v18 = result;
		if (!result)
			return;
	}
	v19 = *((_DWORD*)v18 + 187);
	sub_4D97E0(*(unsigned __int8*)(*(_DWORD*)(v19 + 276) + 2064));
	sub_4E8110(*(unsigned __int8*)(*(_DWORD*)(v19 + 276) + 2064));
	result = nox_xxx_monsterMarkUpdate_4E8020((int)v18);
	for (i = *((_DWORD*)v18 + 129); i; i = *(_DWORD*)(i + 512)) {
		if (*(_BYTE*)(i + 8) & 6)
			result = nox_xxx_monsterMarkUpdate_4E8020(i);
	}
}
