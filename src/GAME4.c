#include "common__system__team.h"
#include "server__magic__plyrspel.h"
#include "server__magic__spell__execdur.h"
#include "server__script__script.h"
#include "server__script__file.h"
#include "common__random.h"

#include "nox_fs.h"
#include "proto.h"

extern _DWORD dword_5d4594_3835368;
extern _DWORD dword_5d4594_1569656;
extern _DWORD nox_server_kickQuestPlayerMinVotes_229992;
extern _DWORD dword_5d4594_1569660;
extern _DWORD dword_5d4594_1569736;
extern _DWORD nox_server_resetQuestMinVotes_229988;
extern _DWORD dword_5d4594_1599644;
extern _DWORD dword_5d4594_1599068;
extern _DWORD dword_5d4594_3835392;
extern _DWORD dword_5d4594_1569652;
extern _DWORD dword_5d4594_3835312;
extern _DWORD dword_5d4594_1568868;
extern _DWORD mox_alloc_magicEnt_1569668;
extern void* nox_alloc_execAbil_1569644;
extern void* nox_alloc_vote_1599652;
extern void* nox_alloc_spellDur_1569724;
extern _DWORD dword_5d4594_1599616;
extern _DWORD dword_5d4594_1599064;
extern void* nox_alloc_magicWall_1569748;
extern _DWORD dword_5d4594_1599060;
extern _DWORD dword_5d4594_1599592;
extern _DWORD dword_5d4594_1599556;
extern _DWORD dword_5d4594_1569664;
extern _DWORD dword_5d4594_1599548;
extern _DWORD dword_5d4594_1599480;
extern _DWORD dword_5d4594_1599532;
extern _DWORD dword_5d4594_1599476;
extern _DWORD dword_5d4594_1569756;
extern _DWORD dword_5d4594_1569672;
extern _DWORD dword_5d4594_1599564;
extern _DWORD dword_5d4594_3835396;
extern _DWORD dword_5d4594_1599588;
extern _DWORD dword_5d4594_1599596;
extern _DWORD dword_5d4594_1599576;
extern _DWORD dword_5d4594_1599540;
extern _DWORD dword_5d4594_1569752;
extern _DWORD dword_5d4594_251568;
extern _DWORD dword_5d4594_1569728;
extern _DWORD dword_5d4594_1570272;
extern _DWORD dword_5d4594_1599656;
extern _DWORD dword_5d4594_2650652;

extern int nox_win_width;
extern unsigned int nox_gameFPS;

FILE* nox_file_8 = 0;

//----- (004F5F30) --------------------------------------------------------
int  nox_xxx_XFerSpellReward_4F5F30(int* a1) {
	unsigned __int8* v1; // esi
	int result;          // eax
	unsigned __int8 v3;  // cl
	unsigned __int8 v4;  // al
	unsigned __int8 v5;  // bl
	unsigned __int8 v6;  // al
	int v7;              // [esp+Ch] [ebp-94h]
	unsigned __int8 v8;  // [esp+12h] [ebp-8Eh]
	unsigned __int8 v9;  // [esp+13h] [ebp-8Dh]
	int v10;             // [esp+14h] [ebp-8Ch]
	char v11;            // [esp+1Ah] [ebp-86h]
	char v12;            // [esp+1Bh] [ebp-85h]
	int v13;             // [esp+1Ch] [ebp-84h]
	char v14[128];       // [esp+20h] [ebp-80h]

	v1 = (unsigned __int8*)a1[184];
	v13 = a1[34];
	v10 = 60;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v10, 2u);
	if ((__int16)v10 > 60)
		return 0;
	result = nox_xxx_mapReadWriteObjData_4F4530(a1, (__int16)v10);
	if (result) {
		if ((__int16)v10 >= 31) {
			if (*getMemU32Ptr(0x5D4594, 3803300) == 1) {
				if ((__int16)v10 >= 41) {
					nox_xxx_fileReadWrite_426AC0_file3_fread(&v7, 1u);
					if ((unsigned __int8)v7 >= 0x80u)
						return 0;
					nox_xxx_fileReadWrite_426AC0_file3_fread(v14, (unsigned __int8)v7);
					v14[(unsigned __int8)v7] = 0;
					*v1 = nox_xxx_spellNameToN_4243F0(v14);
				} else {
					nox_xxx_fileReadWrite_426AC0_file3_fread(&v7, 1u);
					if ((unsigned __int8)v7 >= 0x80u)
						return 0;
					nox_xxx_fileReadWrite_426AC0_file3_fread(v14, (unsigned __int8)v7);
					v14[(unsigned __int8)v7] = 0;
					nox_xxx_spellNameToN_4243F0(v14);
					nox_xxx_fileReadWrite_426AC0_file3_fread(&v7, 1u);
					if ((unsigned __int8)v7 >= 0x80u)
						return 0;
					nox_xxx_fileReadWrite_426AC0_file3_fread(v14, (unsigned __int8)v7);
					v14[(unsigned __int8)v7] = 0;
					v5 = nox_xxx_spellNameToN_4243F0(v14);
					nox_xxx_fileReadWrite_426AC0_file3_fread(&v7, 1u);
					if ((unsigned __int8)v7 >= 0x80u)
						return 0;
					nox_xxx_fileReadWrite_426AC0_file3_fread(v14, (unsigned __int8)v7);
					v14[(unsigned __int8)v7] = 0;
					v6 = nox_xxx_spellNameToN_4243F0(v14);
					*v1 = v5;
					if (v6)
						*v1 = v6;
				}
				goto LABEL_28;
			}
		} else if (*getMemU32Ptr(0x5D4594, 3803300) == 1) {
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v12, 1u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v9, 1u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v8, 1u);
			v3 = v9;
			if (v9 >= 0x89u) {
				v3 = 0;
				v9 = 0;
			}
			v4 = v8;
			if (v8 >= 0x89u) {
				v4 = 0;
				v8 = 0;
			}
			*v1 = v3;
			if (v4)
				*v1 = v4;
			if ((_WORD)v10 == 10)
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v11, 1u);
			goto LABEL_28;
		}
		strcpy(v14, nox_xxx_spellNameByN_424870(*v1));
		LOBYTE(v7) = strlen(v14);
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v7, 1u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(v14, (unsigned __int8)v7);
	LABEL_28:
		if (!a1[34] || *getMemU32Ptr(0x5D4594, 3803300) != 1 || (result = nox_xxx_xfer_4F3E30(v10, (int)a1, a1[34])) != 0) {
			a1[34] = v13;
			result = 1;
		}
	}
	return result;
}
// 4F5F30: using guessed type char var_80[128];

//----- (004F6240) --------------------------------------------------------
int  nox_xxx_XFerAbilityReward_4F6240(int* a1) {
	_BYTE* v1;    // ebp
	int result;   // eax
	int v3;       // [esp+8h] [ebp-8Ch]
	int v4;       // [esp+Ch] [ebp-88h]
	int v5;       // [esp+10h] [ebp-84h]
	char v6[128]; // [esp+14h] [ebp-80h]

	v1 = (_BYTE*)a1[184];
	v5 = a1[34];
	v4 = 61;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v4, 2u);
	if ((__int16)v4 > 61)
		return 0;
	result = nox_xxx_mapReadWriteObjData_4F4530(a1, (__int16)v4);
	if (result) {
		strcpy(v6, nox_xxx_abilityGetName_425250((unsigned __int8)*v1));
		LOBYTE(v3) = strlen(v6);
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v3, 1u);
		if ((unsigned __int8)v3 < 0x80u) {
			nox_xxx_fileReadWrite_426AC0_file3_fread(v6, (unsigned __int8)v3);
			v6[(unsigned __int8)v3] = 0;
			*v1 = nox_xxx_abilityNameToN_424D80(v6);
			if (!a1[34] || *getMemU32Ptr(0x5D4594, 3803300) != 1 || (result = nox_xxx_xfer_4F3E30(v4, (int)a1, a1[34])) != 0) {
				a1[34] = v5;
				result = 1;
			}
		} else {
			result = 0;
		}
	}
	return result;
}
// 4F6240: using guessed type char var_80[128];

//----- (004F6390) --------------------------------------------------------
int  nox_xxx_XFerFieldGuide_4F6390(int* a1) {
	int* v1;    // esi
	char* v2;   // ebx
	int v3;     // ebp
	int result; // eax
	int v5;     // [esp+Ch] [ebp-4h]

	v1 = a1;
	v2 = (char*)a1[184];
	v3 = a1[34];
	v5 = 60;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v5, 2u);
	if ((__int16)v5 > 60)
		return 0;
	result = nox_xxx_mapReadWriteObjData_4F4530(v1, (__int16)v5);
	if (result) {
		if (*getMemU32Ptr(0x5D4594, 3803300)) {
			nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 1u);
			if ((unsigned __int8)a1 >= 0x40u)
				return 0;
			nox_xxx_fileReadWrite_426AC0_file3_fread(v2, (unsigned __int8)a1);
			v2[(unsigned __int8)a1] = 0;
		} else {
			LOBYTE(a1) = strlen(v2);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 1u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(v2, (unsigned __int8)a1);
		}
		if (!v1[34] || *getMemU32Ptr(0x5D4594, 3803300) != 1 || (result = nox_xxx_xfer_4F3E30(v5, (int)v1, v1[34])) != 0) {
			v1[34] = v3;
			result = 1;
		}
	}
	return result;
}

//----- (004F64A0) --------------------------------------------------------
int  nox_xxx_XFerWeapon_4F64A0(int a1) {
	int result;          // eax
	const char*** v2;    // esi
	int v3;              // ebx
	int v4;              // esi
	char* v5;            // edi
	int v6;              // eax
	int v7;              // ecx
	int v8;              // esi
	unsigned __int8 v9;  // bl
	int v10;             // edi
	int v11;             // eax
	size_t v12;          // eax
	_DWORD* v13;         // eax
	unsigned __int8 v14; // [esp+12h] [ebp-126h]
	unsigned __int8 v15; // [esp+13h] [ebp-125h]
	int v16;             // [esp+14h] [ebp-124h]
	int v17;             // [esp+18h] [ebp-120h]
	int v18;             // [esp+1Ch] [ebp-11Ch]
	int v19;             // [esp+20h] [ebp-118h]
	char v20[20];        // [esp+24h] [ebp-114h]
	char v21[256];       // [esp+38h] [ebp-100h]

	v19 = *(_DWORD*)(a1 + 136);
	v17 = 64;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v17, 2u);
	if ((__int16)v17 > 64)
		return 0;
	result = nox_xxx_mapReadWriteObjData_4F4530((int*)a1, (__int16)v17);
	if (!result)
		return result;
	if ((__int16)v17 < 11 && *getMemU32Ptr(0x5D4594, 3803300) == 1) {
		*(_DWORD*)v20 = 0;
		*(_DWORD*)&v20[4] = 0;
		*(_DWORD*)&v20[8] = 0;
		*(_DWORD*)&v20[12] = 0;
		nox_xxx_modifSetItemAttrs_4E4990(a1, (int*)v20);
		return 1;
	}
	if (*getMemU32Ptr(0x5D4594, 3803300)) {
		v4 = 0;
		v5 = v20;
		while (1) {
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v18, 1u);
			if ((int)(unsigned __int8)v18 >= 256)
				return 0;
			nox_xxx_fileReadWrite_426AC0_file3_fread(v21, (unsigned __int8)v18);
			v21[(unsigned __int8)v18] = 0;
			v6 = nox_xxx_modifGetIdByName_413290(v21);
			*(_DWORD*)v5 = nox_xxx_modifGetDescById_413330(v6);
			++v4;
			v5 += 4;
			if (v4 >= 4) {
				*(_WORD*)&v20[16] = -1;
				*(_WORD*)&v20[18] = -1;
				nox_xxx_modifSetItemAttrs_4E4990(a1, (int*)v20);
				goto LABEL_18;
			}
		}
	}
	v2 = *(const char****)(a1 + 692);
	v3 = 4;
	do {
		if (*v2) {
			LOBYTE(v18) = strlen(**v2);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v18, 1u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(**v2, (unsigned __int8)v18);
		} else {
			LOBYTE(v18) = 0;
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v18, 1u);
		}
		++v2;
		--v3;
	} while (v3);
LABEL_18:
	if ((__int16)v17 >= 41) {
		v7 = 0;
		if (*(_DWORD*)(a1 + 8) & 0x1000 && *(_DWORD*)(a1 + 12) & 0x47F0000)
			v7 = 1;
		if (((__int16)v17 >= 62 || !(*(_DWORD*)(a1 + 8) & 0x1000) || !(*(_DWORD*)(a1 + 12) & 0x4000000)) && v7) {
			v8 = *(_DWORD*)(a1 + 736);
			v14 = *(_BYTE*)(v8 + 108);
			v15 = *(_BYTE*)(v8 + 109);
			v9 = v15;
			v16 = *(_DWORD*)(v8 + 112);
			v10 = v16;
			v14 = *(_BYTE*)(v8 + 108);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v14, 1u);
			v15 = *(_BYTE*)(v8 + 109);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v15, 1u);
			if ((__int16)v17 >= 61) {
				v16 = *(_DWORD*)(v8 + 112);
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v16, 4u);
			}
			if (!nox_common_gameFlags_check_40A5C0(4096)) {
				*(_BYTE*)(v8 + 108) = v14;
				goto LABEL_36;
			}
			if (v14 <= v9 && v16 >= 0 && v16 <= v10 && v9 == v15) {
				*(_BYTE*)(v8 + 108) = v14;
			LABEL_36:
				*(_BYTE*)(v8 + 109) = v15;
				*(_DWORD*)(v8 + 112) = v16;
				goto LABEL_37;
			}
			*(_BYTE*)(v8 + 108) = 0;
			*(_BYTE*)(v8 + 109) = v9;
			*(_DWORD*)(v8 + 112) = 0;
		}
	}
LABEL_37:
	if ((__int16)v17 >= 42) {
		LOWORD(v11) = nox_xxx_unitGetHP_4EE780(a1);
		v16 = v11;
		v12 = nox_xxx_fileReadWrite_426AC0_file3_fread(&v16, 2u);
		LOWORD(v12) = *(_WORD*)(*(_DWORD*)(a1 + 556) + 4);
		if ((unsigned __int16)v16 > (unsigned __int16)v12)
			v16 = v12;
		if (*getMemU32Ptr(0x5D4594, 3803300) == 1) {
			if (nox_xxx_gameIsSwitchToSolo_4DB240() == 1 || nox_xxx_gameIsNotMultiplayer_4DB250() == 1 || nox_common_gameFlags_check_40A5C0(4096) && sub_419EA0()) {
				nox_xxx_unitSetHP_4E4560(a1, v16);
			} else {
				v13 = nox_xxx_getProjectileClassById_413250(*(unsigned __int16*)(a1 + 4));
				if (v13) {
					*(_WORD*)(*(_DWORD*)(a1 + 556) + 4) = *((_WORD*)v13 + 26);
					*(_WORD*)(*(_DWORD*)(a1 + 556) + 2) = *((_WORD*)v13 + 26);
					nox_xxx_unitSetHP_4E4560(a1, *((_WORD*)v13 + 26));
				}
			}
		}
	}
	if ((_WORD)v17 == 63)
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v14, 1u);
	if ((__int16)v17 >= 64)
		nox_xxx_fileReadWrite_426AC0_file3_fread((_BYTE*)(*(_DWORD*)(a1 + 748) + 4), 4u);
	if (*(_DWORD*)(a1 + 136) && *getMemU32Ptr(0x5D4594, 3803300) == 1 && !nox_xxx_xfer_4F3E30(v17, a1, *(_DWORD*)(a1 + 136)))
		return 0;
	*(_DWORD*)(a1 + 136) = v19;
	return 1;
}
// 4F673C: variable 'v11' is possibly undefined
// 4F64A0: using guessed type char var_100[256];

//----- (004F6860) --------------------------------------------------------
int  nox_xxx_XFerArmor_4F6860(int a1) {
	int result;       // eax
	const char*** v2; // esi
	int v3;           // ebx
	int v4;           // esi
	char* v5;         // edi
	int v6;           // eax
	int v7;           // eax
	size_t v8;        // eax
	_DWORD* v9;       // eax
	int v10;          // [esp+Ch] [ebp-128h]
	int v11;          // [esp+10h] [ebp-124h]
	size_t v12;       // [esp+14h] [ebp-120h]
	char v13;         // [esp+1Bh] [ebp-119h]
	int v14;          // [esp+1Ch] [ebp-118h]
	char v15[20];     // [esp+20h] [ebp-114h]
	char v16[256];    // [esp+34h] [ebp-100h]

	v14 = *(_DWORD*)(a1 + 136);
	v10 = 62;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v10, 2u);
	if ((__int16)v10 > 62)
		return 0;
	result = nox_xxx_mapReadWriteObjData_4F4530((int*)a1, (__int16)v10);
	if (result) {
		if ((__int16)v10 < 11 && *getMemU32Ptr(0x5D4594, 3803300) == 1) {
			*(_DWORD*)v15 = 0;
			*(_DWORD*)&v15[4] = 0;
			*(_DWORD*)&v15[8] = 0;
			*(_DWORD*)&v15[12] = 0;
			nox_xxx_modifSetItemAttrs_4E4990(a1, (int*)v15);
			return 1;
		}
		if (*getMemU32Ptr(0x5D4594, 3803300)) {
			v4 = 0;
			v5 = v15;
			while (1) {
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v11, 1u);
				if ((int)(unsigned __int8)v11 >= 256)
					return 0;
				nox_xxx_fileReadWrite_426AC0_file3_fread(v16, (unsigned __int8)v11);
				v16[(unsigned __int8)v11] = 0;
				v6 = nox_xxx_modifGetIdByName_413290(v16);
				*(_DWORD*)v5 = nox_xxx_modifGetDescById_413330(v6);
				++v4;
				v5 += 4;
				if (v4 >= 4) {
					*(_WORD*)&v15[16] = -1;
					*(_WORD*)&v15[18] = -1;
					nox_xxx_modifSetItemAttrs_4E4990(a1, (int*)v15);
					goto LABEL_18;
				}
			}
		}
		v2 = *(const char****)(a1 + 692);
		v3 = 4;
		do {
			if (*v2) {
				LOBYTE(v11) = strlen(**v2);
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v11, 1u);
				nox_xxx_fileReadWrite_426AC0_file3_fread(**v2, (unsigned __int8)v11);
			} else {
				LOBYTE(v11) = 0;
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v11, 1u);
			}
			++v2;
			--v3;
		} while (v3);
	LABEL_18:
		if ((__int16)v10 >= 41) {
			LOWORD(v7) = nox_xxx_unitGetHP_4EE780(a1);
			v12 = v7;
			v8 = nox_xxx_fileReadWrite_426AC0_file3_fread(&v12, 2u);
			LOWORD(v8) = *(_WORD*)(*(_DWORD*)(a1 + 556) + 4);
			if ((unsigned __int16)v12 > (unsigned __int16)v8)
				v12 = v8;
			if (*getMemU32Ptr(0x5D4594, 3803300) == 1) {
				if (nox_xxx_gameIsSwitchToSolo_4DB240() == 1 || nox_xxx_gameIsNotMultiplayer_4DB250() == 1 || nox_common_gameFlags_check_40A5C0(4096) && sub_419EA0()) {
					nox_xxx_unitSetHP_4E4560(a1, v12);
				} else {
					v9 = nox_xxx_equipClothFindDefByTT_413270(*(unsigned __int16*)(a1 + 4));
					if (v9) {
						*(_WORD*)(*(_DWORD*)(a1 + 556) + 4) = *((_WORD*)v9 + 26);
						*(_WORD*)(*(_DWORD*)(a1 + 556) + 2) = *((_WORD*)v9 + 26);
						nox_xxx_unitSetHP_4E4560(a1, *((_WORD*)v9 + 26));
					}
				}
			}
		}
		if ((_WORD)v10 == 61)
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v13, 1u);
		if ((__int16)v10 >= 62)
			nox_xxx_fileReadWrite_426AC0_file3_fread((_BYTE*)(*(_DWORD*)(a1 + 748) + 4), 4u);
		if (*(_DWORD*)(a1 + 136) && *getMemU32Ptr(0x5D4594, 3803300) == 1 && !nox_xxx_xfer_4F3E30(v10, a1, *(_DWORD*)(a1 + 136)))
			return 0;
		*(_DWORD*)(a1 + 136) = v14;
		result = 1;
	}
	return result;
}
// 4F69F8: variable 'v7' is possibly undefined
// 4F6860: using guessed type char var_100[256];

//----- (004F6B20) --------------------------------------------------------
int  nox_xxx_XFerAmmo_4F6B20(int* a1) {
	int v1;           // ecx
	int result;       // eax
	const char*** v3; // esi
	int v4;           // ebp
	char* v5;         // esi
	int v6;           // esi
	char* v7;         // edi
	int v8;           // eax
	bool v9;          // zf
	char* v10;        // eax
	char v11;         // cl
	char v12;         // [esp+Eh] [ebp-126h]
	char v13;         // [esp+Fh] [ebp-125h]
	int v14;          // [esp+10h] [ebp-124h]
	char* v15;        // [esp+14h] [ebp-120h]
	int v16;          // [esp+18h] [ebp-11Ch]
	int v17;          // [esp+1Ch] [ebp-118h]
	char v18[20];     // [esp+20h] [ebp-114h]
	char v19[256];    // [esp+34h] [ebp-100h]

	v1 = a1[34];
	v15 = (char*)a1[184];
	v17 = v1;
	v16 = 60;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v16, 2u);
	if ((__int16)v16 > 60)
		return 0;
	result = nox_xxx_mapReadWriteObjData_4F4530(a1, (__int16)v16);
	if (result) {
		if (*getMemU32Ptr(0x5D4594, 3803300)) {
			v6 = 0;
			v7 = v18;
			while (1) {
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v14, 1u);
				if ((int)(unsigned __int8)v14 >= 256)
					return 0;
				nox_xxx_fileReadWrite_426AC0_file3_fread(v19, (unsigned __int8)v14);
				v19[(unsigned __int8)v14] = 0;
				v8 = nox_xxx_modifGetIdByName_413290(v19);
				*(_DWORD*)v7 = nox_xxx_modifGetDescById_413330(v8);
				++v6;
				v7 += 4;
				if (v6 >= 4) {
					*(_WORD*)&v18[16] = -1;
					*(_WORD*)&v18[18] = -1;
					nox_xxx_modifSetItemAttrs_4E4990((int)a1, (int*)v18);
					nox_xxx_fileReadWrite_426AC0_file3_fread(&v13, 1u);
					nox_xxx_fileReadWrite_426AC0_file3_fread(&v12, 1u);
					v9 = !nox_common_gameFlags_check_40A5C0(4096);
					v10 = v15;
					if (!v9)
						v15[2] = 0;
					v11 = v12;
					v10[1] = v13;
					*v10 = v11;
					goto LABEL_17;
				}
			}
		}
		v3 = (const char***)a1[173];
		v4 = 4;
		do {
			if (*v3) {
				LOBYTE(v14) = strlen(**v3);
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v14, 1u);
				nox_xxx_fileReadWrite_426AC0_file3_fread(**v3, (unsigned __int8)v14);
			} else {
				LOBYTE(v14) = 0;
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v14, 1u);
			}
			++v3;
			--v4;
		} while (v4);
		v5 = v15;
		nox_xxx_fileReadWrite_426AC0_file3_fread(v15 + 1, 1u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(v5, 1u);
	LABEL_17:
		if (a1[34] && *getMemU32Ptr(0x5D4594, 3803300) == 1 && !nox_xxx_xfer_4F3E30(v16, (int)a1, a1[34]))
			return 0;
		a1[34] = v17;
		result = 1;
	}
	return result;
}
// 4F6B20: using guessed type char var_100[256];

//----- (004F6D20) --------------------------------------------------------
int  nox_xxx_XFerTeam_4F6D20(int* a1) {
	int result;       // eax
	const char*** v2; // esi
	int v3;           // ebx
	char* v4;         // esi
	int v5;           // edi
	int v6;           // eax
	_DWORD* v7;       // edx
	int v8;           // [esp+4h] [ebp-120h]
	int v9;           // [esp+8h] [ebp-11Ch]
	int v10;          // [esp+Ch] [ebp-118h]
	char v11[20];     // [esp+10h] [ebp-114h]
	char v12[256];    // [esp+24h] [ebp-100h]

	v10 = a1[34];
	v9 = 60;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v9, 2u);
	if ((__int16)v9 > 60)
		return 0;
	result = nox_xxx_mapReadWriteObjData_4F4530(a1, (__int16)v9);
	if (result) {
		if (*getMemU32Ptr(0x5D4594, 3803300)) {
			v4 = v11;
			v5 = 4;
			do {
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v8, 1u);
				nox_xxx_fileReadWrite_426AC0_file3_fread(v12, (unsigned __int8)v8);
				v12[(unsigned __int8)v8] = 0;
				v6 = nox_xxx_modifGetIdByName_413290(v12);
				*(_DWORD*)v4 = nox_xxx_modifGetDescById_413330(v6);
				v4 += 4;
				--v5;
			} while (v5);
			*(_WORD*)&v11[16] = -1;
			*(_WORD*)&v11[18] = -1;
			nox_xxx_modifSetItemAttrs_4E4990((int)a1, (int*)v11);
			if (a1[2] & 0x10000000) {
				v7 = (_DWORD*)a1[187];
				*v7 = a1[14];
				v7[1] = a1[15];
			}
		} else {
			v2 = (const char***)a1[173];
			v3 = 4;
			do {
				if (*v2) {
					LOBYTE(v8) = strlen(**v2);
					nox_xxx_fileReadWrite_426AC0_file3_fread(&v8, 1u);
					nox_xxx_fileReadWrite_426AC0_file3_fread(**v2, (unsigned __int8)v8);
				} else {
					LOBYTE(v8) = 0;
					nox_xxx_fileReadWrite_426AC0_file3_fread(&v8, 1u);
				}
				++v2;
				--v3;
			} while (v3);
		}
		if (!a1[34] || *getMemU32Ptr(0x5D4594, 3803300) != 1 || (result = nox_xxx_xfer_4F3E30(v9, (int)a1, a1[34])) != 0) {
			a1[34] = v10;
			result = 1;
		}
	}
	return result;
}
// 4F6D20: using guessed type char var_100[256];

//----- (004F6EC0) --------------------------------------------------------
int  nox_xxx_XFerGold_4F6EC0(int a1) {
	int* v1;    // esi
	_BYTE* v2;  // edi
	int v3;     // ebx
	int result; // eax

	v1 = (int*)a1;
	v2 = *(_BYTE**)(a1 + 692);
	v3 = *(_DWORD*)(a1 + 136);
	a1 = 60;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 2u);
	if ((__int16)a1 > 60)
		return 0;
	result = nox_xxx_mapReadWriteObjData_4F4530(v1, (__int16)a1);
	if (result) {
		nox_xxx_fileReadWrite_426AC0_file3_fread(v2, 4u);
		if (!v1[34] || *getMemU32Ptr(0x5D4594, 3803300) != 1 || (result = nox_xxx_xfer_4F3E30(a1, (int)v1, v1[34])) != 0) {
			v1[34] = v3;
			result = 1;
		}
	}
	return result;
}

//----- (004F6F60) --------------------------------------------------------
int  nox_xxx_XFerObelisk_4F6F60(int* a1) {
	int* v1;    // esi
	_BYTE* v2;  // edi
	int v3;     // ebp
	int result; // eax
	_DWORD* v5; // edi
	int v6;     // eax
	float v7;   // [esp+0h] [ebp-18h]
	int v8;     // [esp+10h] [ebp-8h]
	int v9;     // [esp+14h] [ebp-4h]

	v1 = a1;
	v2 = (_BYTE*)a1[187];
	v3 = a1[34];
	v8 = 61;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v8, 2u);
	if ((__int16)v8 > 61)
		return 0;
	result = nox_xxx_mapReadWriteObjData_4F4530(v1, (__int16)v8);
	if (result) {
		if ((__int16)v8 >= 61) {
			LOBYTE(a1) = 0;
			nox_xxx_fileReadWrite_426AC0_file3_fread(v2, 4u);
			if (*getMemU32Ptr(0x5D4594, 3803300) == 1) {
				v9 = 80 * *(_DWORD*)v2 / 50;
				v7 = (double)v9;
				nullsub_35(v1, LODWORD(v7));
			}
			if (nox_common_gameFlags_check_40A5C0(2048)) {
				v5 = nox_xxx_netSpriteByCodeStatic_45A720(v1[10]);
				if (v5) {
					v6 = nox_xxx_cliFirstMinimapObj_459EB0();
					if (v6) {
						while ((_DWORD*)v6 != v5) {
							v6 = nox_xxx_cliNextMinimapObj_459EC0(v6);
							if (!v6)
								goto LABEL_14;
						}
						LOBYTE(a1) = 1;
					}
				}
			}
		LABEL_14:
			nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 1u);
		}
		if (!v1[34] || *getMemU32Ptr(0x5D4594, 3803300) != 1 || (result = nox_xxx_xfer_4F3E30(v8, (int)v1, v1[34])) != 0) {
			v1[34] = v3;
			result = 1;
		}
	}
	return result;
}
// 4E4770: using guessed type void  nullsub_35(_DWORD, _DWORD);

//----- (004F70A0) --------------------------------------------------------
int  nox_xxx_XFerToxicCloud_4F70A0(int a1) {
	int* v1;   // esi
	_BYTE* v2; // edi
	int v3;    // ebx

	v1 = (int*)a1;
	v2 = *(_BYTE**)(a1 + 748);
	v3 = *(_DWORD*)(a1 + 136);
	a1 = 61;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 2u);
	if ((__int16)a1 > 61)
		return 0;
	if ((__int16)a1 <= 0)
		return 0;
	if (!nox_xxx_mapReadWriteObjData_4F4530(v1, (__int16)a1))
		return 0;
	nox_xxx_fileReadWrite_426AC0_file3_fread(v2, 4u);
	if (v1[34]) {
		if (*getMemU32Ptr(0x5D4594, 3803300) == 1 && !nox_xxx_xfer_4F3E30(a1, (int)v1, v1[34]))
			return 0;
	}
	v1[34] = v3;
	return 1;
}

//----- (004F7130) --------------------------------------------------------
int  nox_xxx_XFerMonsterGen_4F7130(int* a1) {
	_BYTE* v1;     // ebx
	int v2;        // eax
	int v3;        // edi
	int v4;        // esi
	_BYTE* v5;     // ebp
	char* v6;      // eax
	char* v7;      // eax
	char* v8;      // eax
	char* v9;      // edi
	int* v10;      // ebp
	char v11;      // cl
	int* v12;      // ebx
	int v13;       // eax
	int v14;       // esi
	_BYTE* v15;    // eax
	int v16;       // ebp
	int v17;       // edi
	_DWORD* v18;   // esi
	int v19;       // ecx
	bool v20;      // cc
	int v21;       // esi
	_BYTE* v22;    // edi
	size_t v24;    // [esp-4h] [ebp-138h]
	char v25;      // [esp+13h] [ebp-121h]
	int v26;       // [esp+14h] [ebp-120h]
	int v27;       // [esp+18h] [ebp-11Ch]
	int v28;       // [esp+1Ch] [ebp-118h]
	int v29;       // [esp+20h] [ebp-114h]
	int v30;       // [esp+24h] [ebp-110h]
	int v31;       // [esp+28h] [ebp-10Ch]
	_BYTE* v32;    // [esp+2Ch] [ebp-108h]
	int v33;       // [esp+30h] [ebp-104h]
	char v34[256]; // [esp+34h] [ebp-100h]

	v1 = (_BYTE*)a1[187];
	v2 = a1[34];
	v3 = a1[189];
	v32 = (_BYTE*)a1[187];
	v33 = v2;
	v29 = 63;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v29, 2u);
	if ((__int16)v29 <= 63 && (__int16)v29 > 0 && nox_xxx_mapReadWriteObjData_4F4530(a1, (__int16)v29)) {
		LOBYTE(v31) = 3;
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v31, 1u);
		v4 = 0;
		if ((_BYTE)v31) {
			v5 = v1 + 80;
			do {
				nox_xxx_fileReadWrite_426AC0_file3_fread(v5, 1u);
				++v4;
				++v5;
			} while (v4 < (unsigned __int8)v31);
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread(v1 + 86, 1u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(v1 + 87, 1u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(v1 + 88, 4u);
		if (v3)
			v6 = (char*)(v3 + 1920);
		else
			v6 = 0;
		nox_xxx_xferReadScriptHandler_4F5580((int)(v1 + 48), v6);
		if (v3)
			v7 = (char*)(v3 + 2048);
		else
			v7 = 0;
		nox_xxx_xferReadScriptHandler_4F5580((int)(v1 + 56), v7);
		if (v3)
			v8 = (char*)(v3 + 2176);
		else
			v8 = 0;
		nox_xxx_xferReadScriptHandler_4F5580((int)(v1 + 72), v8);
		if (v3)
			v9 = (char*)(v3 + 2304);
		else
			v9 = 0;
		nox_xxx_xferReadScriptHandler_4F5580((int)(v1 + 64), v9);
		if (*getMemU32Ptr(0x5D4594, 3803300)) {
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v27, 1u);
			v16 = 0;
			if ((_BYTE)v27) {
				while (1) {
					nox_xxx_fileReadWrite_426AC0_file3_fread(&v30, 1u);
					v17 = 0;
					if ((_BYTE)v30)
						break;
				LABEL_36:
					if (++v16 >= (unsigned __int8)v27)
						goto LABEL_37;
				}
				while (1) {
					nox_xxx_fileReadWrite_426AC0_file3_fread(&v28, 1u);
					nox_xxx_fileReadWrite_426AC0_file3_fread(v34, (unsigned __int8)v28);
					v34[(unsigned __int8)v28] = 0;
					v18 = nox_xxx_objectCreateByName_4E3810(v34);
					if (!v18)
						return 0;
					nox_xxx_fileReadWrite_426AC0_file3_fread(&v26, 2u);
					nox_xxx_fileCryptReadCrcMB_426C20(&v32, 4u);
					if (!((int(*)(_DWORD*, _DWORD))v18[176])(v18, 0))
						return 0;
					v19 = v17++ + 4 * v16;
					v20 = v17 < (unsigned __int8)v30;
					*(_DWORD*)&v1[4 * v19] = v18;
					if (!v20)
						goto LABEL_36;
				}
			}
		} else {
			LOBYTE(v26) = 3;
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v26, 1u);
			v10 = (int*)v1;
			v28 = 3;
			do {
				v11 = 0;
				v12 = v10;
				v25 = 0;
				v13 = 4;
				do {
					if (*v12)
						++v11;
					++v12;
					--v13;
				} while (v13);
				v25 = v11;
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v25, 1u);
				v30 = 4;
				do {
					v14 = *v10;
					if (*v10) {
						LOBYTE(v27) = strlen((const char*)nox_xxx_getUnitName_4E39D0(*v10));
						nox_xxx_fileReadWrite_426AC0_file3_fread(&v27, 1u);
						v24 = (unsigned __int8)v27;
						v15 = (_BYTE*)nox_xxx_getUnitName_4E39D0(v14);
						nox_xxx_fileReadWrite_426AC0_file3_fread(v15, v24);
						nox_xxx_xfer_saveObj_51DF90(v14);
					}
					++v10;
					--v30;
				} while (v30);
				v10 = v12;
				--v28;
			} while (v28);
			v1 = v32;
		}
	LABEL_37:
		if ((__int16)v29 >= 62) {
			LOBYTE(v26) = 3;
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v26, 1u);
			v21 = 0;
			if ((_BYTE)v26) {
				v22 = v1 + 83;
				do {
					nox_xxx_fileReadWrite_426AC0_file3_fread(v22, 1u);
					++v21;
					++v22;
				} while (v21 < (unsigned __int8)v26);
			}
		}
		if ((__int16)v29 >= 63)
			nox_xxx_fileReadWrite_426AC0_file3_fread(v1 + 92, 4u);
		if (!a1[34] || *getMemU32Ptr(0x5D4594, 3803300) != 1 || nox_xxx_xfer_4F3E30(v29, (int)a1, a1[34])) {
			a1[34] = v33;
			return 1;
		}
	}
	return 0;
}
// 4F7130: using guessed type char var_100[256];

//----- (004F74D0) --------------------------------------------------------
int  nox_xxx_XFerRewardMarker_4F74D0(int* a1) {
	_BYTE* v1;     // esi
	int v2;        // ebp
	int i;         // eax
	char* v4;      // eax
	int v5;        // edi
	int v6;        // eax
	int v7;        // edi
	int v8;        // eax
	int v9;        // ebp
	char* v10;     // eax
	int v11;       // eax
	int v12;       // edi
	int v13;       // eax
	int v14;       // ebp
	char* v15;     // eax
	int v16;       // eax
	size_t v18;    // [esp-4h] [ebp-124h]
	size_t v19;    // [esp-4h] [ebp-124h]
	size_t v20;    // [esp-4h] [ebp-124h]
	int v21;       // [esp+10h] [ebp-110h]
	int v22;       // [esp+14h] [ebp-10Ch]
	int v23;       // [esp+18h] [ebp-108h]
	int v24;       // [esp+1Ch] [ebp-104h]
	char v25[256]; // [esp+20h] [ebp-100h]

	v1 = (_BYTE*)a1[173];
	v24 = a1[34];
	v23 = 63;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v23, 2u);
	if ((__int16)v23 <= 63) {
		v2 = 0;
		if ((__int16)v23 > 0) {
			if (nox_xxx_mapReadWriteObjData_4F4530(a1, (__int16)v23)) {
				nox_xxx_fileReadWrite_426AC0_file3_fread(v1, 4u);
				nox_xxx_fileReadWrite_426AC0_file3_fread(v1 + 4, 4u);
				v22 = 0;
				for (i = 0; i < 137; ++i) {
					if (v1[i + 8] == 1)
						++v22;
				}
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v22, 2u);
				if (*getMemU32Ptr(0x5D4594, 3803300)) {
					v5 = 0;
					if ((_WORD)v22) {
						do {
							nox_xxx_fileReadWrite_426AC0_file3_fread(&v21, 1u);
							nox_xxx_fileReadWrite_426AC0_file3_fread(v25, (unsigned __int8)v21);
							v25[(unsigned __int8)v21] = 0;
							v6 = nox_xxx_spellNameToN_4243F0(v25);
							if (!v6)
								return 0;
							v1[v6 + 8] = 1;
						} while (++v5 < (unsigned __int16)v22);
					}
				} else {
					do {
						if (v1[v2 + 8]) {
							LOBYTE(v21) = strlen(nox_xxx_spellNameByN_424870(v2));
							nox_xxx_fileReadWrite_426AC0_file3_fread(&v21, 1u);
							v18 = (unsigned __int8)v21;
							v4 = nox_xxx_spellNameByN_424870(v2);
							nox_xxx_fileReadWrite_426AC0_file3_fread(v4, v18);
						}
						++v2;
					} while (v2 < 137);
				}
				v7 = 0;
				v8 = 0;
				v22 = 0;
				do {
					if (v1[v8 + 145] == 1)
						++v22;
					++v8;
				} while (v8 < 6);
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v22, 2u);
				if (*getMemU32Ptr(0x5D4594, 3803300)) {
					if ((_WORD)v22) {
						do {
							nox_xxx_fileReadWrite_426AC0_file3_fread(&v21, 1u);
							nox_xxx_fileReadWrite_426AC0_file3_fread(v25, (unsigned __int8)v21);
							v25[(unsigned __int8)v21] = 0;
							v11 = nox_xxx_abilityNameToN_424D80(v25);
							if (!v11)
								return 0;
							v1[v11 + 145] = 1;
						} while (++v7 < (unsigned __int16)v22);
					}
				} else {
					v9 = 0;
					do {
						if (v1[v9 + 145]) {
							LOBYTE(v21) = strlen(nox_xxx_abilityGetName_425250(v9));
							nox_xxx_fileReadWrite_426AC0_file3_fread(&v21, 1u);
							v19 = (unsigned __int8)v21;
							v10 = nox_xxx_abilityGetName_425250(v9);
							nox_xxx_fileReadWrite_426AC0_file3_fread(v10, v19);
						}
						++v9;
					} while (v9 < 6);
				}
				v12 = 0;
				v13 = 0;
				v22 = 0;
				do {
					if (v1[v13 + 151] == 1)
						++v22;
					++v13;
				} while (v13 < 41);
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v22, 2u);
				if (*getMemU32Ptr(0x5D4594, 3803300)) {
					if ((_WORD)v22) {
						do {
							nox_xxx_fileReadWrite_426AC0_file3_fread(&v21, 1u);
							nox_xxx_fileReadWrite_426AC0_file3_fread(v25, (unsigned __int8)v21);
							v25[(unsigned __int8)v21] = 0;
							v16 = nox_xxx_guide_427010(v25);
							if (!v16)
								return 0;
							v1[v16 + 151] = 1;
						} while (++v12 < (unsigned __int16)v22);
					}
				} else {
					v14 = 0;
					do {
						if (v1[v14 + 151]) {
							LOBYTE(v21) = strlen(nox_xxx_guideNameByN_427230(v14));
							nox_xxx_fileReadWrite_426AC0_file3_fread(&v21, 1u);
							v20 = (unsigned __int8)v21;
							v15 = nox_xxx_guideNameByN_427230(v14);
							nox_xxx_fileReadWrite_426AC0_file3_fread(v15, v20);
						}
						++v14;
					} while (v14 < 41);
				}
				nox_xxx_fileReadWrite_426AC0_file3_fread(v1 + 196, 4u);
				nox_xxx_fileReadWrite_426AC0_file3_fread(v1 + 192, 4u);
				nox_xxx_fileReadWrite_426AC0_file3_fread(v1 + 200, 4u);
				nox_xxx_fileReadWrite_426AC0_file3_fread(v1 + 204, 4u);
				nox_xxx_fileReadWrite_426AC0_file3_fread(v1 + 208, 4u);
				if ((__int16)v23 >= 62)
					nox_xxx_fileReadWrite_426AC0_file3_fread(v1 + 212, 4u);
				if ((__int16)v23 >= 63)
					nox_xxx_fileReadWrite_426AC0_file3_fread(v1 + 216, 1u);
				if (!a1[34] || *getMemU32Ptr(0x5D4594, 3803300) != 1 || nox_xxx_xfer_4F3E30(v23, (int)a1, a1[34])) {
					a1[34] = v24;
					return 1;
				}
			}
		}
	}
	return 0;
}
// 4F74D0: using guessed type char var_100[256];

//----- (004F78E0) --------------------------------------------------------
int  nox_xxx_unitInventoryContains_4F78E0(int a1, int a2) {
	int v2; // eax

	if (*(_DWORD*)(a2 + 492) != a1)
		return 0;
	v2 = *(_DWORD*)(a1 + 504);
	if (!v2)
		return 0;
	while (v2 != a2) {
		v2 = *(_DWORD*)(v2 + 496);
		if (!v2)
			return 0;
	}
	return 1;
}

//----- (004F7920) --------------------------------------------------------
int  nox_xxx_equipedItemByCode_4F7920(int a1, int a2) {
	int result; // eax

	result = *(_DWORD*)(a1 + 504);
	if (!result)
		return 0;
	while (*(_DWORD*)(result + 36) != a2) {
		result = *(_DWORD*)(result + 496);
		if (!result)
			return 0;
	}
	return result;
}

//----- (004F7950) --------------------------------------------------------
void  sub_4F7950(int a1) {
	int v1;  // ebp
	int v2;  // edi
	int* v3; // esi

	v1 = *(_DWORD*)(a1 + 748);
	v2 = 3;
	v3 = (int*)(v1 + 168);
	do {
		if (*v3)
			nox_xxx_delayedDeleteObject_4E5CC0(*v3);
		*v3 = 0;
		++v3;
		--v2;
	} while (v2);
	*(_BYTE*)(v1 + 181) = 0;
	*(_BYTE*)(v1 + 180) = 0;
}

//----- (004F79A0) --------------------------------------------------------
void  nox_xxx_playerSetCustomWP_4F79A0(int a1, int a2, int a3) {
	int v3;    // esi
	int v4;    // eax
	float2 v5; // [esp+8h] [ebp-8h]

	v3 = *(_DWORD*)(a1 + 748);
	if (!(*(_BYTE*)(*(_DWORD*)(v3 + 276) + 3680) & 3)) {
		v4 = *(_DWORD*)(v3 + 4 * *(unsigned __int8*)(v3 + 180) + 168);
		if (v4) {
			LODWORD(v5.field_0) = a2;
			LODWORD(v5.field_4) = a3;
			nox_xxx_unitMove_4E7010(v4, &v5);
		} else {
			*(_DWORD*)(v3 + 4 * *(unsigned __int8*)(v3 + 180) + 168) = nox_xxx_objectCreateByName_4E3810("PlayerWaypoint");
			nox_xxx_createAt_4DAA50(*(_DWORD*)(v3 + 4 * *(unsigned __int8*)(v3 + 180) + 168), a1, *(float*)&a2, *(float*)&a3);
		}
	}
}

//----- (004F7A40) --------------------------------------------------------
int  nox_xxx_playerConfusedGetDirection_4F7A40(int a1) {
	int v1;        // edi
	int v2;        // ecx
	signed int v3; // edx
	int v4;        // edi

	v1 = *(__int16*)(a1 + 126);
	v2 = (unsigned __int8)nox_xxx_buffGetPower_4FF570(a1, 3);
	v3 = (*getMemU32Ptr(0x5D4594, 2598000) + *(_DWORD*)(a1 + 36)) % 0x28u;
	if (v3 > 20)
		v3 = 40 - v3;
	v4 = (v2 + 3) * (v3 - 10) + v1;
	if (v4 < 0)
		v4 += (unsigned int)(255 - v4) >> 8 << 8;
	if (v4 >= 256)
		v4 += -256 * ((unsigned int)v4 >> 8);
	return v4;
}

//----- (004F7AB0) --------------------------------------------------------
_DWORD*  nox_xxx_mapFindPlayerStart_4F7AB0(float2* a1, int a2) {
	_DWORD* result; // eax
	int v3;         // ebp
	int v4;         // ebx
	float2* v5;     // edi
	int v6;         // esi
	int j;          // ebx
	int v8;         // ebp
	int v9;         // edi
	int i;          // esi
	double v11;     // st7
	double v12;     // st6
	double v13;     // st5
	int v14;        // esi
	float v15;      // [esp+10h] [ebp-10h]
	int v16;        // [esp+14h] [ebp-Ch]
	float v17;      // [esp+18h] [ebp-8h]
	int v18;        // [esp+1Ch] [ebp-4h]

	result = *(_DWORD**)&dword_5d4594_1568868;
	v3 = 0;
	v16 = 0;
	if (!dword_5d4594_1568868) {
		result = (_DWORD*)nox_xxx_getNameId_4E3AA0("PlayerStart");
		dword_5d4594_1568868 = result;
	}
	if (a2) {
		if (nox_xxx_servObjectHasTeam_419130(a2 + 48)) {
			v16 = *(unsigned __int8*)(a2 + 52);
			nox_xxx_clientGetTeamColor_418AB0(v16);
			v3 = v16;
		}
		v4 = 0;
		v5 = 0;
		v6 = nox_server_getFirstObject_4DA790();
		if (!v6)
			goto LABEL_13;
		do {
			if (*(unsigned __int16*)(v6 + 4) == dword_5d4594_1568868) {
				v5 = (float2*)v6;
				if (sub_4F7CE0(v6, v3))
					++v4;
			}
			v6 = nox_server_getNextObject_4DA7A0(v6);
		} while (v6);
		v18 = v4;
		if (v4) {
			v17 = 0.0;
			j = 0;
			v8 = 1;
			v9 = nox_server_getFirstObject_4DA790();
			if (!v9)
				goto LABEL_39;
			do {
				if (*(unsigned __int16*)(v9 + 4) == dword_5d4594_1568868 && sub_4F7CE0(v9, v16)) {
					v15 = 10000000.0;
					for (i = nox_xxx_getFirstPlayerUnit_4DA7C0(); i; i = nox_xxx_getNextPlayerUnit_4DA7F0(i)) {
						if (i != a2 && nox_xxx_unitIsEnemyTo_5330C0(a2, i)) {
							v11 = *(float*)(v9 + 56) - *(float*)(i + 56);
							v12 = *(float*)(v9 + 60) - *(float*)(i + 60);
							v13 = v12 * v12 + v11 * v11;
							if (v13 < v15)
								v15 = v13;
							v8 = 0;
						}
					}
					if (v15 > (double)v17) {
						j = v9;
						v17 = v15;
					}
				}
				v9 = nox_server_getNextObject_4DA7A0(v9);
			} while (v9);
			if (v8 || !j) {
			LABEL_39:
				v14 = nox_common_randomInt_415FA0(0, v18 - 1);
				for (j = nox_server_getFirstObject_4DA790(); j; j = nox_server_getNextObject_4DA7A0(j)) {
					if (*(unsigned __int16*)(j + 4) == dword_5d4594_1568868 && sub_4F7CE0(j, v16)) {
						if (!v14)
							break;
						--v14;
					}
				}
			}
			result = (_DWORD*)&a1->field_0;
			*a1 = *(float2*)(j + 56);
		} else {
			if (!v5) {
			LABEL_13:
				result = (_DWORD*)&a1->field_0;
				a1->field_0 = 2000.0;
				a1->field_4 = 2000.0;
				return result;
			}
			result = (_DWORD*)&a1->field_0;
			*a1 = v5[7];
		}
	}
	return result;
}

//----- (004F7CE0) --------------------------------------------------------
BOOL  sub_4F7CE0(int a1, int a2) {
	return *(_DWORD*)(a1 + 16) & 0x1000000 && (!a2 || !nox_xxx_servObjectHasTeam_419130(a1 + 48) || nox_xxx_teamCompare2_419180(a1 + 48, a2));
}

//----- (004F7D30) --------------------------------------------------------
int  nox_xxx_playerSubStamina_4F7D30(int a1, int a2) {
	int v2; // eax
	int v3; // ecx
	int v5; // esi

	v2 = *(_DWORD*)(a1 + 8);
	if (v2 & 4) {
		v3 = *(_DWORD*)(a1 + 748);
		if (*(unsigned __int8*)(v3 + 91) >= a2) {
			*(_BYTE*)(v3 + 91) -= a2;
			nox_xxx_netReportStamina_4D8800(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), a1);
			return 1;
		}
	} else {
		if (!(v2 & 2))
			return 1;
		v5 = *(_DWORD*)(a1 + 748);
		if (*(unsigned __int8*)(v5 + 1128) >= a2) {
			*(_BYTE*)(v5 + 1128) -= a2;
			return 1;
		}
	}
	return 0;
}

//----- (004F7DB0) --------------------------------------------------------
void  sub_4F7DB0(int a1, char a2) {
	int v2; // eax

	if (*(_BYTE*)(a1 + 8) & 4) {
		v2 = *(_DWORD*)(a1 + 748);
		*(_BYTE*)(v2 + 91) -= a2;
		nox_xxx_netReportStamina_4D8800(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), a1);
	}
}

//----- (004F7DF0) --------------------------------------------------------
int  nox_xxx_checkWinkFlags_4F7DF0(int a1) {
	int v1; // eax
	int v2; // esi
	int v4; // eax

	v1 = *getMemU32Ptr(0x5D4594, 1568872);
	if (!*getMemU32Ptr(0x5D4594, 1568872)) {
		v1 = nox_xxx_getNameId_4E3AA0("GameBall");
		*getMemU32Ptr(0x5D4594, 1568872) = v1;
	}
	v2 = *(_DWORD*)(a1 + 516);
	if (!v2)
		return 0;
	while (*(unsigned __int16*)(v2 + 4) != v1) {
		v2 = *(_DWORD*)(v2 + 512);
		if (!v2)
			return 0;
	}
	v4 = *(_DWORD*)(v2 + 16);
	LOBYTE(v4) = v4 & 0xBF;
	*(_DWORD*)(v2 + 16) = v4;
	nox_xxx_objectApplyForce_52DF80(a1 + 56, v2, 100.0);
	*(_DWORD*)(v2 + 520) = 0;
	nox_xxx_unitClearOwner_4EC300(v2);
	nox_xxx_aud_501960(926, a1, 0, 0);
	sub_4E8290(1, 0);
	return 1;
}

//----- (004F7E80) --------------------------------------------------------
int  nox_xxx_weaponGetStaminaByType_4F7E80(int a1) {
	if (a1 & 0x200)
		return 70;
	if (a1 & 0x4000)
		return 100;
	if (a1 & 0x800)
		return 50;
	if (a1 & 0x100)
		return 45;
	if (a1 & 0x1000)
		return 75;
	if (a1 & 0x2000)
		return 100;
	if (a1 & 0x7FF8000)
		return 45;
	return (a1 & 0x400) != 0 ? 75 : 10;
}

//----- (004F7EF0) --------------------------------------------------------
__int16  nox_xxx_playerRespawn_4F7EF0(int a1) {
	char* v1;   // eax
	char* v2;   // ebp
	_DWORD* v3; // edi
	int v4;     // ebx
	float v5;   // edx
	int v6;     // edi
	int v7;     // eax
	float2 v9;  // [esp+10h] [ebp-8h]

	v1 = sub_416640();
	v2 = v1;
	if (a1) {
		v3 = *(_DWORD**)(a1 + 748);
		v4 = v3[69];
		if (!nox_common_gameFlags_check_40A5C0(4096) || (v1 = (char*)v3[137]) == 0) {
			if (v4)
				*(_DWORD*)(v4 + 4700) = 0;
			if (nox_common_gameFlags_check_40A5C0(4096)) {
				nox_xxx_playerMakeDefItems_4EF7D0(a1, 1, 1);
				*((_BYTE*)v3 + *(unsigned __int8*)(v3[69] + 2064) + 452) = -6;
				nox_xxx_netPriMsgToPlayer_4DA2C0(a1, "GeneralPrint:Respawn", 0);
			} else {
				nox_xxx_playerMakeDefItems_4EF7D0(a1, 1, 0);
			}
			if (nox_common_gameFlags_check_40A5C0(4096))
				nox_xxx_aud_501960(1006, a1, 0, 0);
			else
				nox_xxx_aud_501960(148, a1, 0, 0);
			if (!dword_5d4594_2650652 || *(_DWORD*)(v2 + 58))
				nox_xxx_respawnPlayerImpl_53FBC0((float*)(a1 + 56), *(__int16*)(a1 + 124));
			v5 = *(float*)(a1 + 60);
			v9.field_0 = *(float*)(a1 + 56);
			v9.field_4 = v5;
			if (nox_common_gameFlags_check_40A5C0(4096) && (v6 = v3[77]) != 0)
				sub_4F80C0(v6, &v9);
			else
				nox_xxx_mapFindPlayerStart_4F7AB0(&v9, a1);
			nox_xxx_unitMove_4E7010(a1, &v9);
			if (nox_common_gameFlags_check_40A5C0(16)) {
				if (nox_xxx_CheckGameplayFlags_417DA0(4)) {
					v7 = *((_DWORD*)nox_xxx_clientGetTeamColor_418AB0(*(unsigned __int8*)(*(_DWORD*)(v4 + 2056) + 52)) + 19);
					if (v7) {
						if (!*(_DWORD*)(v7 + 492))
							sub_4F3400(*(_DWORD*)(v4 + 2056), v7, 1);
					}
				}
			}
			v1 = (char*)nox_common_gameFlags_check_40A5C0(0x2000);
			if (v1)
				LOWORD(v1) = nox_xxx_buffApplyTo_4FF380(a1, 23, 5 * (_WORD)nox_gameFPS, 5);
		}
	}
	return (__int16)v1;
}

//----- (004F80C0) --------------------------------------------------------
BOOL  sub_4F80C0(int a1, float2* a3) {
	int v2;      // ebx
	BOOL result; // eax

	*a3 = *(float2*)(a1 + 56);
	v2 = 32;
	do {
		sub_4ED970(60.0, (float2*)(a1 + 56), a3);
		result = nox_xxx_mapTileAllowTeleport_411A90(a3);
		if (!result)
			break;
		--v2;
	} while (v2);
	return result;
}

//----- (004F8100) --------------------------------------------------------
char  nox_xxx_updatePlayer_4F8100(_DWORD* a1) {
	_DWORD* v1;          // edi
	int v2;              // ebx
	int v3;              // edx
	int v4;              // esi
	_WORD* v5;           // ebp
	int v6;              // eax
	int v7;              // eax
	__int16 v8;          // ax
	_DWORD* v9;          // eax
	int v10;             // ecx
	__int16 v11;         // ax
	__int16 v12;         // ax
	int v13;             // eax
	int v14;             // eax
	unsigned __int8 v15; // cl
	int v16;             // eax
	double v17;          // st7
	int v18;             // eax
	float v20;           // [esp+0h] [ebp-14h]
	float v21;           // [esp+18h] [ebp+4h]

	v1 = a1;
	v2 = 0;
	v3 = 4;
	v4 = a1[187];
	v5 = (_WORD*)a1[139];
	v6 = v4 + 116;
	do {
		if (*(_DWORD*)v6 && *(_BYTE*)(*(_DWORD*)v6 + 16) & 0x20)
			*(_DWORD*)v6 = 0;
		v6 += 4;
		--v3;
	} while (v3);
	if (!(a1[4] & 0x20)) {
		if (nox_common_gameFlags_check_40A5C0(4096) && *(_DWORD*)(v4 + 280)) {
			a1[22] = 0;
			a1[23] = 0;
			a1[20] = 0;
			a1[21] = 0;
		}
		if (nox_common_gameFlags_check_40A5C0(4096) && (v7 = *(_DWORD*)(v4 + 548)) != 0 &&
			*(_BYTE*)(*(_DWORD*)(v4 + 276) + 2064) != 31 &&
			*getMemU32Ptr(0x5D4594, 2598000) - v7 > (unsigned int)(30 * nox_gameFPS)) {
			LOBYTE(v6) = sub_4DCFB0((int)a1);
		} else {
			v8 = *(_WORD*)(v4 + 78);
			if (v8) {
				*(_WORD*)(v4 + 78) = v8 - 1;
			} else {
				if (*(_WORD*)(v4 + 76))
					v2 = 1000 * (*(unsigned __int16*)(v4 + 76) - (unsigned __int16)*v5) / *(unsigned __int16*)(v4 + 76);
				*(_WORD*)(v4 + 76) = *v5;
				if (v2 > 0)
					*(_WORD*)(v4 + 78) = 7;
			}
			if (nox_common_gameFlags_check_40A5C0(0x4000000))
				sub_4F9E70((int)a1);
			sub_4F9ED0(a1);
			v9 = *(_DWORD**)(v4 + 276);
			v10 = v9[907];
			if (!v10)
				v10 = v9[514];
			v9[908] = *(_DWORD*)(v10 + 56);
			v9[909] = *(_DWORD*)(v10 + 60);
			v11 = *(_WORD*)(v4 + 160);
			if (v11)
				*(_WORD*)(v4 + 160) = v11 - 1;
			nox_xxx_unitNeedSync_4E44F0((int)a1);
			v12 = *(_WORD*)(v4 + 82);
			if (v12)
				*(_WORD*)(v4 + 82) = v12 - 1;
			v13 = a1[4];
			if ((v13 & 0x8000) == 0) {
				if (v2 > 0) {
					v14 = a1[131];
					if (*(_BYTE*)(*(_DWORD*)(v4 + 276) + 2252)) {
						if (v14 == 5) {
							nox_xxx_aud_501960(330, (int)a1, 0, 0);
						} else if (v2 <= 450) {
							if (v2 <= 70)
								nox_xxx_aud_501960(327, (int)a1, 0, 0);
							else
								nox_xxx_aud_501960(328, (int)a1, 0, 0);
						} else {
							nox_xxx_aud_501960(329, (int)a1, 0, 0);
						}
					} else if (v14 == 5) {
						nox_xxx_aud_501960(320, (int)a1, 0, 0);
					} else if (v2 <= 450) {
						if (v2 <= 70)
							nox_xxx_aud_501960(317, (int)a1, 0, 0);
						else
							nox_xxx_aud_501960(318, (int)a1, 0, 0);
					} else {
						nox_xxx_aud_501960(319, (int)a1, 0, 0);
					}
				}
				v15 = *(_BYTE*)(v4 + 91);
				if (v15 < 0x64u)
					*(_BYTE*)(v4 + 91) = v15 + 0x64u / nox_gameFPS;
			}
			v16 = *(_DWORD*)(v4 + 216);
			if (v16 && !*(_BYTE*)(v4 + 188) &&
				(unsigned int)(*getMemU32Ptr(0x5D4594, 2598000) - v16) > *getMemIntPtr(0x5D4594, 2614260)) {
				nox_xxx_playerSpell_4FB2A0_magic_plyrspel((int)a1);
				*(_DWORD*)(v4 + 216) = 0;
			}
			nox_xxx_playerInventory_4F8420((int)a1);
			nox_xxx_unitUpdatePlayerImpl_4F8460((int)a1);
			if (nox_xxx_testUnitBuffs_4FF350((int)a1, 8) && *(_BYTE*)(v4 + 88) != 1)
				nox_xxx_playerSetState_4FA020(a1, 5);
			nox_xxx_questCheckSecretArea_421C70((int)a1);
			v6 = *(_DWORD*)(v4 + 132);
			if (v6) {
				v17 = nox_xxx_gamedataGetFloat_419D40(getMemAt(0x587000, 216044));
				v18 = *(_DWORD*)(v4 + 132);
				if (*(_BYTE*)(v18 + 16) & 0x20) {
					LOBYTE(v6) = (unsigned int)nox_xxx_harpoonBreakForPlr_537520(a1);
				} else {
					sub_4E7540((int)a1, v18);
					v21 = v17;
					v20 = -v21;
					LOBYTE(v6) = nox_xxx_objectApplyForce_52DF80((int)(v1 + 14), *(_DWORD*)(v4 + 132), v20);
				}
			}
		}
	}
	return v6;
}

//----- (004F8420) --------------------------------------------------------
void  nox_xxx_playerInventory_4F8420(int a1) {
	_DWORD* i; // esi
	int v2;    // eax
	int v3;    // eax

	for (i = *(_DWORD**)(a1 + 504); i; i = (_DWORD*)i[124]) {
		v2 = i[4];
		if (v2 & 0x100) {
			LOBYTE(v3) = nox_xxx_playerCheckStrength_4F3180(a1, (int)i);
			if (!v3)
				nox_xxx_invForceDropItem_4ED930(a1, i);
		}
	}
}
// 4F8444: variable 'v3' is possibly undefined

//----- (004F8460) --------------------------------------------------------
void  nox_xxx_unitUpdatePlayerImpl_4F8460(int a1) {
	int v1;               // esi
	int v2;               // edi
	char v3;              // al
	int v4;               // edx
	unsigned __int8* v5;  // ebp
	int v6;               // ecx
	int v7;               // eax
	unsigned __int8 v8;   // al
	int v9;               // ecx
	unsigned int v10;     // eax
	int v11;              // ebx
	unsigned __int8 v12;  // al
	int v13;              // ecx
	unsigned __int8 v14;  // cl
	int v15;              // kr00_4
	int v16;              // ebx
	unsigned int v17;     // ecx
	unsigned __int8 v18;  // cl
	bool v19;             // cc
	int v20;              // ecx
	int v21;              // eax
	double v22;           // st7
	double v23;           // st6
	double v24;           // st7
	signed int v25;       // ebx
	int v26;              // eax
	unsigned int v27;     // eax
	int v28;              // eax
	int v29;              // eax
	int v30;              // eax
	unsigned int v31;     // ecx
	unsigned int v32;     // ebx
	unsigned int v33;     // ebp
	int v34;              // eax
	unsigned int v35;     // eax
	int v36;              // eax
	int v37;              // eax
	int v38;              // ecx
	__int16 v41;          // ax
	int v42;              // ecx
	int j;                // edi
	char* v44;            // eax
	int i;                // edi
	char* v46;            // eax
	int v47;              // eax
	unsigned __int8* v48; // eax
	signed int v49;       // edi
	int v50;              // eax
	double v51;           // st7
	int v52;              // eax
	int v53;              // eax
	unsigned __int8 v54;  // al
	int v55;              // ecx
	int v56;              // eax
	int v57;              // eax
	int v58;              // eax
	int v59;              // eax
	int v60;              // ecx
	int v61;              // eax
	int v62;              // eax
	int v63;              // eax
	int v64;              // eax
	int v65;              // eax
	char v66;             // al
	int v67;              // [esp+10h] [ebp-Ch]
	int v68;              // [esp+14h] [ebp-8h]
	int v69;              // [esp+18h] [ebp-4h]

	v1 = a1;
	v2 = *(_DWORD*)(a1 + 748);
	a1 = 0;
	v68 = 0;
	switch (*(unsigned __int8*)(v2 + 88)) {
	case 0u:
	case 5u:
		if (!nox_xxx_playerCanMove_4F9BC0(v1))
			goto LABEL_10;
		v20 = *(_DWORD*)(*(_DWORD*)(v1 + 748) + 276);
		if (*(_DWORD*)(v20 + 3656)) {
			v69 = 3;
			if (*(_BYTE*)(v20 + 2252))
				nox_xxx_aud_501960(333, v1, 0, 0);
			else
				nox_xxx_aud_501960(323, v1, 0, 0);
			nox_xxx_netInformTextMsg_4DA0F0(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), 13, &v69);
			goto LABEL_10;
		}
		v21 = *(_DWORD*)(v2 + 276);
		v68 = 1;
		if (*(_BYTE*)(v2 + 88) != 5 &&
				(v23 = (double)*(int*)(v21 + 2288) - *(float*)(v1 + 60),
				 v22 = (double)*(int*)(v21 + 2284) - *(float*)(v1 + 56), v23 * v23 + v22 * v22 <= 10000.0) ||
			nox_common_playerIsAbilityActive_4FC250(v1, 4)) {
			a1 = 0;
			goto LABEL_93;
		}
		v24 = *(float*)(v1 + 544) + *(float*)(v1 + 544);
		a1 = 1;
		*(float*)(v1 + 544) = v24;
		nox_xxx_animPlayerGetFrameRange_4F9F90(6, &v67, &v69);
		v25 = (*(_DWORD*)(v1 + 36) + *getMemU32Ptr(0x5D4594, 2598000)) / (unsigned int)(v69 + 1) % v67;
		if (v25 <= (int)((*(_DWORD*)(v1 + 36) + *getMemU32Ptr(0x5D4594, 2598000) - 1) / (unsigned int)(v69 + 1) % v67) ||
			v25 != 2 && v25 != 8) {
			goto LABEL_90;
		}
		v26 = nox_xxx_tileNFromPoint_411160((float2*)(v1 + 56));
		if (v26 < 0 || v26 >= *(int*)&dword_5d4594_251568)
			goto LABEL_90;
		v27 = *getMemU32Ptr(0x5D4594, 60 * v26 + 2682224);
		if (v27 <= 0x80) {
			if (v27 == 128) {
				nox_xxx_aud_501960(278, v1, 0, 0);
				goto LABEL_90;
			}
			v28 = v27 - 2;
			if (!v28)
				goto LABEL_90;
			v29 = v28 - 6;
			if (!v29) {
				nox_xxx_aud_501960(277, v1, 0, 0);
				goto LABEL_90;
			}
			if (v29 == 56) {
				nox_xxx_aud_501960(276, v1, 0, 0);
				goto LABEL_90;
			}
		LABEL_87:
			nox_xxx_aud_501960(275, v1, 0, 0);
			goto LABEL_90;
		}
		switch (v27) {
		case 0x400u:
			nox_xxx_aud_501960(274, v1, 0, 0);
			break;
		case 0x800u:
			nox_xxx_aud_501960(279, v1, 0, 0);
			break;
		case 0x4000u:
			break;
		default:
			goto LABEL_87;
		}
	LABEL_90:
		if (nox_common_randomInt_415FA0(0, 100) <= 1)
			nox_xxx_aud_501960(322, v1, 0, 0);
	LABEL_93:
		if (!sub_4F9AB0(v1)) {
			if (nox_xxx_testUnitBuffs_4FF350(v1, 3))
				*(_WORD*)(v1 + 126) = nox_xxx_playerConfusedGetDirection_4F7A40(v1);
			v30 = 8 * *(__int16*)(v1 + 126);
			*(float*)(v1 + 88) = *getMemFloatPtr(0x587000, v30 + 194136) * *(float*)(v1 + 544) + *(float*)(v1 + 88);
			*(float*)(v1 + 92) = *getMemFloatPtr(0x587000, v30 + 194140) * *(float*)(v1 + 544) + *(float*)(v1 + 92);
		}
		if (!*(_BYTE*)(v2 + 88)) {
			nox_xxx_animPlayerGetFrameRange_4F9F90(4, &v67, &v69);
			v31 = *(_DWORD*)(v1 + 36) + *getMemU32Ptr(0x5D4594, 2598000);
			v32 = (v31 - 1) / (v69 + 1) % v67;
			v33 = v31 / (v69 + 1) % v67;
			if ((!nox_common_playerIsAbilityActive_4FC250(v1, 4) || a1) && v33 != v32 && (v33 == 3 || v33 == 9)) {
				v34 = nox_xxx_tileNFromPoint_411160((float2*)(v1 + 56));
				if (v34 >= 0 && v34 < *(int*)&dword_5d4594_251568) {
					v35 = *getMemU32Ptr(0x5D4594, 60 * v34 + 2682224);
					if (v35 <= 0x80) {
						if (v35 == 128) {
							nox_xxx_aud_501960(272, v1, 0, 0);
							goto LABEL_10;
						}
						v36 = v35 - 2;
						if (!v36)
							goto LABEL_10;
						v37 = v36 - 6;
						if (!v37) {
							nox_xxx_aud_501960(271, v1, 0, 0);
							goto LABEL_10;
						}
						if (v37 == 56) {
							nox_xxx_aud_501960(270, v1, 0, 0);
							goto LABEL_10;
						}
					LABEL_116:
						nox_xxx_aud_501960(269, v1, 0, 0);
						goto LABEL_10;
					}
					switch (v35) {
					case 0x400u:
						nox_xxx_aud_501960(268, v1, 0, 0);
						break;
					case 0x800u:
						nox_xxx_aud_501960(273, v1, 0, 0);
						break;
					case 0x4000u:
						break;
					default:
						goto LABEL_116;
					}
				}
			}
		}
	LABEL_10:
		if (nox_xxx_playerCmdGet_51AC40(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064)))
			goto LABEL_247;
		v3 = *(_BYTE*)(v2 + 88);
		if ((!v3 || v3 == 5) && !sub_4F9A80(v1)) {
			nox_xxx_playerSetState_4FA020((_DWORD*)v1, 13);
			*(_DWORD*)(v1 + 136) = *getMemU32Ptr(0x5D4594, 2598000);
		}
		v4 = *(_DWORD*)(v2 + 276);
		*(_DWORD*)(v2 + 240) &= 0xFFFFFFE1;
		if (*(_BYTE*)(v4 + 3680) & 3 ||
			(v69 = sub_4FEE50(31, v1), (v5 = nox_xxx_playerControlBufferFirst_51AB50(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064))) == 0)) {
		LABEL_247:
			if (v68) {
				v66 = *(_BYTE*)(v2 + 88);
				if (v66) {
					if (v66 != 5) {
						if (nox_common_playerIsAbilityActive_4FC250(v1, 4))
							sub_4FC300((_DWORD*)v1, 4);
					}
				}
			}
			return;
		}
		while (1) {
			if (!v69 || *((_DWORD*)v5 + 2) == 1) {
				switch (*((_DWORD*)v5 + 2)) {
				case 1:
					if (!nox_xxx_testUnitBuffs_4FF350(v1, 25) && (!nox_common_gameFlags_check_40A5C0(4096) || !*(_DWORD*)(v2 + 280)) &&
						nox_common_playerIsAbilityActive_4FC250(v1, 1) != 1)
						*(_WORD*)(v1 + 126) = *((_WORD*)v5 + 6);
					break;
				case 2:
				case 3:
				case 4:
				case 5:
					if (nox_xxx_playerCanMove_4F9BC0(v1)) {
						nox_xxx_cancelAllSpells_4FEE90(v1);
						if (!nox_common_playerIsAbilityActive_4FC250(v1, 1) &&
							(*(_BYTE*)(v2 + 88) != 1 || *(_DWORD*)(*(_DWORD*)(v2 + 276) + 4) & 0x47F0000 &&
															nox_common_mapPlrActionToStateId_4FA2B0(v1) != 29)) {
							if (*(_BYTE*)(v2 + 88) == 16) {
								nox_xxx_playerSetState_4FA020((_DWORD*)v1, 17);
							} else {
								if (a1)
									nox_xxx_playerSetState_4FA020((_DWORD*)v1, 5);
								else
									nox_xxx_playerSetState_4FA020((_DWORD*)v1, 0);
								v56 = *(_DWORD*)(v2 + 240);
								if (v5[12] & 2)
									LOBYTE(v56) = v56 | 1;
								else
									LOBYTE(v56) = v56 & 0xFE;
								*(_DWORD*)(v2 + 240) = v56;
								if (*((_DWORD*)v5 + 2) == 4)
									*(_DWORD*)(v2 + 240) |= 4u;
								if (*((_DWORD*)v5 + 2) == 5) {
									v57 = *(_DWORD*)(v2 + 240);
									LOBYTE(v57) = v57 | 2;
									*(_DWORD*)(v2 + 240) = v57;
								}
								if (*((_DWORD*)v5 + 2) == 2) {
									v58 = *(_DWORD*)(v2 + 240);
									LOBYTE(v58) = v58 | 8;
									*(_DWORD*)(v2 + 240) = v58;
								}
								if (*((_DWORD*)v5 + 2) == 3) {
									v59 = *(_DWORD*)(v2 + 240);
									LOBYTE(v59) = v59 | 0x10;
									*(_DWORD*)(v2 + 240) = v59;
								}
								*(_DWORD*)(v1 + 136) = *getMemU32Ptr(0x5D4594, 2598000);
							}
						}
					}
					break;
				case 6:
					if (nox_xxx_playerCanAttack_4F9C40(v1)) {
						if (!nox_common_gameFlags_check_40A5C0(128) && !nox_xxx_checkWinkFlags_4F7DF0(v1))
							nox_xxx_playerInputAttack_4F9C70((_DWORD*)v1);
						if (*(_BYTE*)(v2 + 88) == 10)
							nox_xxx_playerSetState_4FA020((_DWORD*)v1, 13);
					}
					break;
				case 7:
					if (!nox_xxx_playerCanMove_4F9BC0(v1) || nox_common_playerIsAbilityActive_4FC250(v1, 1) || nox_xxx_probablyWarcryCheck_4FC3E0(v1, 2))
						break;
					nox_xxx_cancelAllSpells_4FEE90(v1);
					v60 = *(_DWORD*)(*(_DWORD*)(v1 + 748) + 276);
					if (*(_DWORD*)(v60 + 3656)) {
						v67 = 3;
						if (*(_BYTE*)(v60 + 2252))
							nox_xxx_aud_501960(333, v1, 0, 0);
						else
							nox_xxx_aud_501960(323, v1, 0, 0);
						nox_xxx_netInformTextMsg_4DA0F0(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064), 13, &v67);
					} else if (nox_xxx_playerSubStamina_4F7D30(v1, 90)) {
						if (nox_xxx_testUnitBuffs_4FF350(v1, 3))
							*(_WORD*)(v1 + 126) = nox_xxx_playerConfusedGetDirection_4F7A40(v1);
						*(_DWORD*)(v1 + 16) |= 0x4000u;
						nox_xxx_playerSetState_4FA020((_DWORD*)v1, 12);
						*(_DWORD*)(v1 + 136) = *getMemU32Ptr(0x5D4594, 2598000);
						return;
					}
					break;
				case 0x14:
					if (!nox_common_gameFlags_check_40A5C0(128)) {
						if (!*(_DWORD*)(v2 + 216))
							nox_xxx_plrSetSpellType_4F9B90(v1);
						*(_DWORD*)(v2 + 184) = nox_xxx_updateSpellRelated_424830(*(_DWORD*)(v2 + 184), 1);
						nox_xxx_aud_501960(186, v1, 0, 0);
						*(_BYTE*)(v2 + 188) = 0;
					}
					break;
				case 0x15:
					if (!nox_common_gameFlags_check_40A5C0(128)) {
						if (!*(_DWORD*)(v2 + 216))
							nox_xxx_plrSetSpellType_4F9B90(v1);
						*(_DWORD*)(v2 + 184) = nox_xxx_updateSpellRelated_424830(*(_DWORD*)(v2 + 184), 7);
						nox_xxx_aud_501960(190, v1, 0, 0);
						*(_BYTE*)(v2 + 188) = 0;
					}
					break;
				case 0x16:
					if (!nox_common_gameFlags_check_40A5C0(128)) {
						if (!*(_DWORD*)(v2 + 216))
							nox_xxx_plrSetSpellType_4F9B90(v1);
						*(_DWORD*)(v2 + 184) = nox_xxx_updateSpellRelated_424830(*(_DWORD*)(v2 + 184), 3);
						nox_xxx_aud_501960(192, v1, 0, 0);
						*(_BYTE*)(v2 + 188) = 0;
					}
					break;
				case 0x17:
					if (!nox_common_gameFlags_check_40A5C0(128)) {
						if (!*(_DWORD*)(v2 + 216))
							nox_xxx_plrSetSpellType_4F9B90(v1);
						*(_DWORD*)(v2 + 184) = nox_xxx_updateSpellRelated_424830(*(_DWORD*)(v2 + 184), 5);
						nox_xxx_aud_501960(188, v1, 0, 0);
						*(_BYTE*)(v2 + 188) = 0;
					}
					break;
				case 0x18:
					if (!nox_common_gameFlags_check_40A5C0(128)) {
						if (!*(_DWORD*)(v2 + 216))
							nox_xxx_plrSetSpellType_4F9B90(v1);
						*(_DWORD*)(v2 + 184) = nox_xxx_updateSpellRelated_424830(*(_DWORD*)(v2 + 184), 2);
						nox_xxx_aud_501960(187, v1, 0, 0);
						*(_BYTE*)(v2 + 188) = 0;
					}
					break;
				case 0x19:
					if (!nox_common_gameFlags_check_40A5C0(128)) {
						if (!*(_DWORD*)(v2 + 216))
							nox_xxx_plrSetSpellType_4F9B90(v1);
						*(_DWORD*)(v2 + 184) = nox_xxx_updateSpellRelated_424830(*(_DWORD*)(v2 + 184), 0);
						nox_xxx_aud_501960(193, v1, 0, 0);
						*(_BYTE*)(v2 + 188) = 0;
					}
					break;
				case 0x1A:
					if (!nox_common_gameFlags_check_40A5C0(128)) {
						if (!*(_DWORD*)(v2 + 216))
							nox_xxx_plrSetSpellType_4F9B90(v1);
						*(_DWORD*)(v2 + 184) = nox_xxx_updateSpellRelated_424830(*(_DWORD*)(v2 + 184), 8);
						nox_xxx_aud_501960(189, v1, 0, 0);
						*(_BYTE*)(v2 + 188) = 0;
					}
					break;
				case 0x1B:
					if (!nox_common_gameFlags_check_40A5C0(128)) {
						if (!*(_DWORD*)(v2 + 216))
							nox_xxx_plrSetSpellType_4F9B90(v1);
						*(_DWORD*)(v2 + 184) = nox_xxx_updateSpellRelated_424830(*(_DWORD*)(v2 + 184), 6);
						nox_xxx_aud_501960(191, v1, 0, 0);
						*(_BYTE*)(v2 + 188) = 0;
					}
					break;
				case 0x1C:
					nox_xxx_playerSetState_4FA020((_DWORD*)v1, 13);
					if (!nox_common_gameFlags_check_40A5C0(128)) {
						if (*(_DWORD*)(v2 + 216)) {
							nox_xxx_playerSpell_4FB2A0_magic_plyrspel(v1);
							*(_DWORD*)(v2 + 216) = 0;
						} else {
							v61 = nox_server_getObjectFromNetCode_4ECCB0(*((_DWORD*)v5 + 3));
							nox_xxx_playerDoSchedSpell_4FB0E0(v1, v61);
						}
					}
					break;
				case 0x1D:
					nox_xxx_playerSetState_4FA020((_DWORD*)v1, 13);
					if (!nox_common_gameFlags_check_40A5C0(128)) {
						if (*(_DWORD*)(v2 + 216)) {
							nox_xxx_playerSpell_4FB2A0_magic_plyrspel(v1);
							*(_DWORD*)(v2 + 216) = 0;
						}
						v62 = *(_DWORD*)(v2 + 276);
						*(_DWORD*)(v2 + 220) = *(_DWORD*)(v62 + 2284);
						*(_DWORD*)(v2 + 224) = *(_DWORD*)(v62 + 2288);
						v63 = nox_server_getObjectFromNetCode_4ECCB0(*((_DWORD*)v5 + 3));
						nox_xxx_playerDoSchedSpell_4FB0E0(v1, v63);
					}
					break;
				case 0x1E:
					if (!nox_common_gameFlags_check_40A5C0(128)) {
						if (*(_DWORD*)(v2 + 216)) {
							nox_xxx_playerSpell_4FB2A0_magic_plyrspel(v1);
							*(_DWORD*)(v2 + 216) = 0;
						}
						v64 = *(_DWORD*)(v2 + 276);
						*(_DWORD*)(v2 + 220) = *(_DWORD*)(v64 + 2284);
						*(_DWORD*)(v2 + 224) = *(_DWORD*)(v64 + 2288);
						v65 = nox_server_getObjectFromNetCode_4ECCB0(*((_DWORD*)v5 + 3));
						nox_xxx_playerDoSchedSpellQueue_4FB1D0(v1, v65);
					}
					break;
				default:
					break;
				}
			}
			v5 = nox_xxx_playerGetControlBufferNext_51ABC0(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064));
			if (!v5)
				goto LABEL_247;
		}
	case 1u:
		if (!nox_xxx_playerAttack_538960(v1)) {
			if (*(_BYTE*)(*(_DWORD*)(v2 + 276) + 4) & 4) {
				nox_xxx_playerSetState_4FA020((_DWORD*)v1, 14);
				*(_DWORD*)(v1 + 136) = *getMemU32Ptr(0x5D4594, 2598000);
			} else {
				nox_xxx_playerSetState_4FA020((_DWORD*)v1, 13);
				*(_BYTE*)(*(_DWORD*)(v2 + 276) + 8) = 0;
			}
		}
		goto LABEL_10;
	case 2u:
		nox_xxx_animPlayerGetFrameRange_4F9F90(21, &v67, &v69);
		v54 = (*getMemU32Ptr(0x5D4594, 2598000) - *(_DWORD*)(v1 + 136)) / (unsigned int)(v69 + 1);
		v55 = v67;
		*(_BYTE*)(v2 + 236) = v54;
		if (v54 >= v55)
			*(_BYTE*)(v2 + 236) = v55 - 1;
		goto LABEL_10;
	case 3u:
		if ((unsigned int)(*getMemU32Ptr(0x5D4594, 2598000) - *(_DWORD*)(v1 + 136)) > (int)nox_gameFPS) {
			nox_xxx_playerSetState_4FA020((_DWORD*)v1, 4);
			*(_DWORD*)(v2 + 240) &= 0xFFFFFFDF;
			v38 = *(_DWORD*)(v1 + 16) | 0x18;
			*(_DWORD*)(v1 + 136) = *getMemU32Ptr(0x5D4594, 2598000);
			*(_DWORD*)(v1 + 16) = v38;
			*(_DWORD*)(v1 + 84) = 0;
			*(_DWORD*)(v1 + 80) = 0;
			*(_DWORD*)(v1 + 92) = 0;
			*(_DWORD*)(v1 + 88) = 0;
			*(_DWORD*)(v1 + 100) = 0;
			*(_DWORD*)(v1 + 96) = 0;
			nox_script_callOnEvent("PlayerDeath", 0, 0);
		}
		return;
	case 4u:
		if ((unsigned int)(*getMemU32Ptr(0x5D4594, 2598000) - *(_DWORD*)(v1 + 136)) <= (int)nox_gameFPS >> 1)
			return;
		if (!nox_common_gameFlags_check_40A5C0(1024) || (v41 = nox_xxx_servGamedataGet_40A020(1024), v41 <= 0) ||
			(v42 = *(_DWORD*)(v2 + 276), *(_DWORD*)(v42 + 2140) < v41)) {
			if (nox_common_gameFlags_check_40A5C0(0x2000) &&
				(v47 = *(_DWORD*)(v2 + 276), !(*(_BYTE*)(v47 + 3680) & 1)) &&
				(v48 = nox_xxx_playerControlBufferFirst_51AB50(*(unsigned __int8*)(v47 + 2064))) != 0) {
				while (*((_DWORD*)v48 + 2) != 6) {
					v48 = nox_xxx_playerGetControlBufferNext_51ABC0(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064));
					if (!v48)
						goto LABEL_149;
				}
				nox_xxx_playerCmd_51AC30(*(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2064));
				nox_xxx_playerRespawn_4F7EF0(v1);
			} else {
			LABEL_149:
				if (!nox_server_doPlayersAutoRespawn_40A5F0())
					return;
				nox_xxx_playerRespawn_4F7EF0(v1);
			}
			goto LABEL_10;
		}
		if (*(_BYTE*)(v42 + 3680) & 1) {
			a1 = *(_DWORD*)(v42 + 3628);
			nox_xxx_playerCameraUnlock_4E6040(v1);
			for (i = nox_xxx_getFirstPlayerUnit_4DA7C0(); i; i = nox_xxx_getNextPlayerUnit_4DA7F0(i)) {
				v46 = nox_common_playerInfoGetByID_417040(*(_DWORD*)(i + 36));
				if (!(*(_DWORD*)(i + 16) & 0x8000) && !(v46[3680] & 1))
					nox_xxx_playerCameraFollow_4E6060(v1, i);
			}
		} else {
			nox_xxx_netNeedTimestampStatus_4174F0(v42, 32);
			nox_xxx_playerGoObserver_4E6860(*(_DWORD*)(v2 + 276), 0, 0);
			nox_xxx_playerCameraUnlock_4E6040(v1);
			nox_xxx_playerLeaveObsByObserved_4E60A0(v1);
			if (!sub_4F9E10(v1)) {
				for (j = nox_xxx_getFirstPlayerUnit_4DA7C0(); j; j = nox_xxx_getNextPlayerUnit_4DA7F0(j)) {
					v44 = nox_common_playerInfoGetByID_417040(*(_DWORD*)(j + 36));
					if (!(*(_DWORD*)(j + 16) & 0x8000) && !(v44[3680] & 1))
						nox_xxx_playerCameraFollow_4E6060(v1, j);
				}
			}
		}
		return;
	case 0xAu:
		goto LABEL_9;
	case 0xCu:
		nox_xxx_animPlayerGetFrameRange_4F9F90(3, &v69, &a1);
		v49 = (*getMemU32Ptr(0x5D4594, 2598000) - *(_DWORD*)(v1 + 136)) / (unsigned int)(a1 + 1);
		v50 = nox_xxx_getFirstPlayerUnit_4DA7C0();
		if (!v50)
			goto LABEL_155;
		while (*(_DWORD*)(*(_DWORD*)(v50 + 748) + 132) != v1) {
			v50 = nox_xxx_getNextPlayerUnit_4DA7F0(v50);
			if (!v50) {
			LABEL_155:
				v51 = *(float*)(v1 + 544) + *(float*)(v1 + 544);
				v52 = 8 * *(__int16*)(v1 + 124);
				*(float*)(v1 + 88) = v51 * *getMemFloatPtr(0x587000, v52 + 194136);
				*(float*)(v1 + 92) = v51 * *getMemFloatPtr(0x587000, v52 + 194140);
				break;
			}
		}
		if (v49 >= v69) {
			nox_xxx_playerSetState_4FA020((_DWORD*)v1, 0);
			v53 = *(_DWORD*)(v1 + 16);
			BYTE1(v53) &= 0xBFu;
			*(_DWORD*)(v1 + 16) = v53;
			*(_DWORD*)(v1 + 136) = *getMemU32Ptr(0x5D4594, 2598000);
		}
		return;
	case 0xDu:
		*(_DWORD*)(v1 + 16) &= 0xFFFFBFFE;
		if (sub_4F9A80(v1))
			nox_xxx_playerSetState_4FA020((_DWORD*)v1, 0);
		if (nox_common_gameFlags_check_40A5C0(128) || !(**(_DWORD**)(v2 + 276) & 0x3000000) ||
			!nox_xxx_monsterTestBlockShield_533E70(v1) && (unsigned int)(*getMemU32Ptr(0x5D4594, 2598000) - *(_DWORD*)(v1 + 136)) <=
								   (int)nox_gameFPS >> 2) {
			goto LABEL_10;
		}
		nox_xxx_playerSetState_4FA020((_DWORD*)v1, 15);
	LABEL_9:
		*(_BYTE*)(v2 + 236) = 0;
		goto LABEL_10;
	case 0xEu:
		nox_xxx_animPlayerGetFrameRange_4F9F90(33, &v69, &v67);
		*(_BYTE*)(v2 + 236) = v69 - 1;
		if ((unsigned int)(*getMemU32Ptr(0x5D4594, 2598000) - *(_DWORD*)(v1 + 136)) > (int)nox_gameFPS)
			nox_xxx_playerSetState_4FA020((_DWORD*)v1, 13);
		goto LABEL_10;
	case 0xFu:
		nox_xxx_animPlayerGetFrameRange_4F9F90(40, &v67, &v69);
		v8 = (*getMemU32Ptr(0x5D4594, 2598000) - *(_DWORD*)(v1 + 136)) / (unsigned int)(v69 + 1);
		v9 = v67;
		*(_BYTE*)(v2 + 236) = v8;
		if (v8 >= v9) {
			nox_xxx_playerSetState_4FA020((_DWORD*)v1, 16);
			*(_BYTE*)(v2 + 236) = v67 - 1;
		}
		goto LABEL_10;
	case 0x10u:
		nox_xxx_animPlayerGetFrameRange_4F9F90(40, &v69, &v67);
		*(_BYTE*)(v2 + 236) = v69 - 1;
		goto LABEL_10;
	case 0x11u:
		nox_xxx_animPlayerGetFrameRange_4F9F90(40, &v67, &v69);
		v10 = (*getMemU32Ptr(0x5D4594, 2598000) - *(_DWORD*)(v1 + 136)) / (unsigned int)(v69 + 1);
		v11 = v67 - v10;
		if ((int)(v67 - v10) < v67) {
			if (v11 <= 0) {
				LOBYTE(v11) = 0;
				nox_xxx_playerSetState_4FA020((_DWORD*)v1, 13);
			}
			*(_BYTE*)(v2 + 236) = v11;
		} else {
			*(_BYTE*)(v2 + 236) = v67 - 1;
		}
		goto LABEL_10;
	case 0x12u:
		nox_xxx_animPlayerGetFrameRange_4F9F90(48, &v67, &v69);
		LOBYTE(v7) = (*getMemU32Ptr(0x5D4594, 2598000) - *(_DWORD*)(v1 + 136)) / (unsigned int)(v69 + 1);
		v6 = v67;
		*(_BYTE*)(v2 + 236) = v7;
		v7 = (unsigned __int8)v7;
		goto LABEL_56;
	case 0x13u:
		nox_xxx_animPlayerGetFrameRange_4F9F90(49, &v67, &v69);
		LOBYTE(v7) = (*getMemU32Ptr(0x5D4594, 2598000) - *(_DWORD*)(v1 + 136)) / (unsigned int)(v69 + 1);
		v6 = v67;
		*(_BYTE*)(v2 + 236) = v7;
		v7 = (unsigned __int8)v7;
		goto LABEL_56;
	case 0x14u:
		nox_xxx_animPlayerGetFrameRange_4F9F90(47, &v67, &v69);
		LOBYTE(v7) = (*getMemU32Ptr(0x5D4594, 2598000) - *(_DWORD*)(v1 + 136)) / (unsigned int)(v69 + 1);
		v6 = v67;
		*(_BYTE*)(v2 + 236) = v7;
		v7 = (unsigned __int8)v7;
		goto LABEL_56;
	case 0x15u:
		nox_xxx_animPlayerGetFrameRange_4F9F90(30, &v69, &v67);
		LOBYTE(v7) = (*getMemU32Ptr(0x5D4594, 2598000) - *(_DWORD*)(v1 + 136)) / (unsigned int)(v67 + 1);
		v6 = v69;
		*(_BYTE*)(v2 + 236) = v7;
		v7 = (unsigned __int8)v7;
		goto LABEL_56;
	case 0x16u:
		nox_xxx_animPlayerGetFrameRange_4F9F90(31, &v69, &v67);
		*(_BYTE*)(v2 + 236) = v69 - 1;
		goto LABEL_10;
	case 0x17u:
		nox_xxx_animPlayerGetFrameRange_4F9F90(50, &v67, &v69);
		LOBYTE(v7) = (*getMemU32Ptr(0x5D4594, 2598000) - *(_DWORD*)(v1 + 136)) / (unsigned int)(v69 + 1);
		v6 = v67;
		*(_BYTE*)(v2 + 236) = v7;
		v7 = (unsigned __int8)v7;
		goto LABEL_56;
	case 0x18u:
		nox_xxx_animPlayerGetFrameRange_4F9F90(19, &v67, &v69);
		LOBYTE(v7) = (*getMemU32Ptr(0x5D4594, 2598000) - *(_DWORD*)(v1 + 136)) / (unsigned int)(v69 + 1);
		v6 = v67;
		*(_BYTE*)(v2 + 236) = v7;
		v7 = (unsigned __int8)v7;
		goto LABEL_56;
	case 0x19u:
		nox_xxx_animPlayerGetFrameRange_4F9F90(20, &v67, &v69);
		LOBYTE(v7) = (*getMemU32Ptr(0x5D4594, 2598000) - *(_DWORD*)(v1 + 136)) / (unsigned int)(v69 + 1);
		v6 = v67;
		*(_BYTE*)(v2 + 236) = v7;
		v7 = (unsigned __int8)v7;
		goto LABEL_56;
	case 0x1Au:
		nox_xxx_animPlayerGetFrameRange_4F9F90(15, &v67, &v69);
		LOBYTE(v7) = (*getMemU32Ptr(0x5D4594, 2598000) - *(_DWORD*)(v1 + 136)) / (unsigned int)(v69 + 1);
		v6 = v67;
		*(_BYTE*)(v2 + 236) = v7;
		v7 = (unsigned __int8)v7;
	LABEL_56:
		v19 = v7 < v6;
		goto LABEL_57;
	case 0x1Bu:
		nox_xxx_animPlayerGetFrameRange_4F9F90(16, &v67, &v69);
		v14 = (*getMemU32Ptr(0x5D4594, 2598000) - *(_DWORD*)(v1 + 136)) / (unsigned int)(v69 + 1);
		v15 = v67;
		*(_BYTE*)(v2 + 236) = v14;
		if (v14 >= v15 / 2) {
			nox_xxx_playerSetState_4FA020((_DWORD*)v1, 28);
			*(_BYTE*)(v2 + 236) = v67 / 2;
		}
		goto LABEL_10;
	case 0x1Cu:
		nox_xxx_animPlayerGetFrameRange_4F9F90(16, &v67, &v69);
		*(_BYTE*)(v2 + 236) = v67 / 2;
		if ((unsigned int)(*getMemU32Ptr(0x5D4594, 2598000) - *(_DWORD*)(v1 + 136)) > 0x14) {
			nox_xxx_playerSetState_4FA020((_DWORD*)v1, 29);
			*(_BYTE*)(v2 + 236) = v67 / 2;
		}
		goto LABEL_10;
	case 0x1Du:
		nox_xxx_animPlayerGetFrameRange_4F9F90(16, &v67, &v69);
		v16 = v67;
		v17 = (*getMemU32Ptr(0x5D4594, 2598000) - *(_DWORD*)(v1 + 136)) / (unsigned int)(v69 + 1);
		goto LABEL_51;
	case 0x1Eu:
		nox_xxx_animPlayerGetFrameRange_4F9F90(52, &v67, &v69);
		v12 = (*getMemU32Ptr(0x5D4594, 2598000) - *(_DWORD*)(v1 + 136)) / (unsigned int)(v69 + 1);
		v13 = v67;
		*(_BYTE*)(v2 + 236) = v12;
		if (v12 >= v13) {
			nox_xxx_playerSetState_4FA020((_DWORD*)v1, 13);
			*(_DWORD*)(v2 + 164) = 0;
		}
		goto LABEL_10;
	case 0x20u:
		nox_xxx_animPlayerGetFrameRange_4F9F90(54, &v67, &v69);
		*(_BYTE*)(v2 + 236) = v67 / 2;
		if ((unsigned int)(*getMemU32Ptr(0x5D4594, 2598000) - *(_DWORD*)(v1 + 136)) > 0x14) {
			nox_xxx_playerSetState_4FA020((_DWORD*)v1, 33);
			*(_BYTE*)(v2 + 236) = v67 / 2;
		}
		goto LABEL_10;
	case 0x21u:
		nox_xxx_animPlayerGetFrameRange_4F9F90(54, &v67, &v69);
		v16 = v67;
		v17 = (*getMemU32Ptr(0x5D4594, 2598000) - *(_DWORD*)(v1 + 136)) / (unsigned int)(v69 + 1);
	LABEL_51:
		v18 = v16 / 2 + v17;
		*(_BYTE*)(v2 + 236) = v18;
		v19 = v18 < v16;
	LABEL_57:
		if (!v19)
			nox_xxx_playerSetState_4FA020((_DWORD*)v1, 13);
		goto LABEL_10;
	default:
		goto LABEL_10;
	}
}

//----- (004F9A80) --------------------------------------------------------
BOOL  sub_4F9A80(int a1) {
	return *(_DWORD*)(*(_DWORD*)(a1 + 748) + 4 * *(unsigned __int8*)(*(_DWORD*)(a1 + 748) + 181) + 168) != 0;
}

//----- (004F9AB0) --------------------------------------------------------
int  sub_4F9AB0(int a1) {
	int v1;     // edi
	int v2;     // ecx
	int result; // eax
	double v4;  // st7
	int v5;     // eax
	double v6;  // st7
	float2 v7;  // [esp+8h] [ebp-8h]

	v1 = *(_DWORD*)(a1 + 748);
	v2 = *(_DWORD*)(v1 + 4 * *(unsigned __int8*)(v1 + 181) + 168);
	if (!v2)
		return 0;
	v7.field_0 = *(float*)(v2 + 56) - *(float*)(a1 + 56);
	v4 = *(float*)(v2 + 60) - *(float*)(a1 + 60);
	v7.field_4 = v4;
	if (v4 * v7.field_4 + v7.field_0 * v7.field_0 >= 100.0) {
		*(_WORD*)(a1 + 126) = nox_xxx_math_509ED0(&v7);
		if (nox_xxx_testUnitBuffs_4FF350(a1, 3))
			*(_WORD*)(a1 + 126) = nox_xxx_playerConfusedGetDirection_4F7A40(a1);
		v5 = 8 * *(__int16*)(a1 + 126);
		*(float*)(a1 + 88) = *getMemFloatPtr(0x587000, v5 + 194136) * *(float*)(a1 + 544) + *(float*)(a1 + 88);
		v6 = *getMemFloatPtr(0x587000, v5 + 194140) * *(float*)(a1 + 544);
		result = 1;
		*(float*)(a1 + 92) = v6 + *(float*)(a1 + 92);
	} else {
		nox_xxx_delayedDeleteObject_4E5CC0(v2);
		result = 0;
		*(_DWORD*)(v1 + 4 * *(unsigned __int8*)(v1 + 181) + 168) = 0;
	}
	return result;
}

//----- (004F9B90) --------------------------------------------------------
void*  nox_xxx_plrSetSpellType_4F9B90(int a1) {
	int v1;       // esi
	void* result; // eax

	v1 = *(_DWORD*)(a1 + 748);
	result = nox_xxx_spellGetDefArrayPtr_424820();
	*(_DWORD*)(v1 + 184) = result;
	*(_DWORD*)(v1 + 216) = *getMemU32Ptr(0x5D4594, 2598000);
	return result;
}

//----- (004F9BC0) --------------------------------------------------------
int  nox_xxx_playerCanMove_4F9BC0(int a1) {
	int v1; // esi
	int v3; // eax

	v1 = *(_DWORD*)(a1 + 748);
	if (nox_xxx_testUnitBuffs_4FF350(a1, 25))
		return 0;
	if (nox_xxx_testUnitBuffs_4FF350(a1, 5))
		return 0;
	if (nox_common_gameFlags_check_40A5C0(4096) && *(_DWORD*)(v1 + 280))
		return 0;
	if (*(_BYTE*)(v1 + 88) == 1) {
		v3 = *(_DWORD*)(v1 + 104);
		if (v3) {
			if (*(_DWORD*)(v3 + 8) & 0x1000000 && *(_BYTE*)(v3 + 12) & 8)
				return 0;
		}
	}
	return 1;
}

//----- (004F9C40) --------------------------------------------------------
BOOL  nox_xxx_playerCanAttack_4F9C40(int a1) {
	int v1;      // esi
	BOOL result; // eax

	v1 = *(_DWORD*)(a1 + 748);
	if (nox_xxx_testUnitBuffs_4FF350(a1, 25))
		result = 0;
	else
		result = *(_BYTE*)(v1 + 88) != 23;
	return result;
}

//----- (004F9C70) --------------------------------------------------------
void  nox_xxx_playerInputAttack_4F9C70(_DWORD* a1) {
	int v1;  // edi
	int v2;  // eax
	int v3;  // ebp
	int v4;  // eax
	int v5;  // eax
	char v6; // bp

	if (a1 && nox_xxx_playerAimsAtEnemy_4F9DC0((int)a1)) {
		v1 = a1[187];
		v2 = *(_DWORD*)(*(_DWORD*)(v1 + 276) + 4);
		if (v2) {
			if (v2 & 0x47F0000 && nox_common_mapPlrActionToStateId_4FA2B0((int)a1) != 29) {
				v3 = *(_DWORD*)(*(_DWORD*)(v1 + 104) + 736);
				if (*(_BYTE*)(v3 + 108) || !*(_BYTE*)(v3 + 109)) {
					a1[34] = *getMemU32Ptr(0x5D4594, 2598000);
					*(_BYTE*)(v1 + 236) = 0;
					nox_xxx_playerSetState_4FA020(a1, 1);
					nox_xxx_useByNetCode_53F8E0((int)a1, *(_DWORD*)(v1 + 104));
				} else if (nox_xxx_playerSubStamina_4F7D30((int)a1, 45)) {
					v4 = *(_DWORD*)(v3 + 96);
					LOBYTE(v4) = v4 | 2;
					*(_DWORD*)(v3 + 96) = v4;
					a1[34] = *getMemU32Ptr(0x5D4594, 2598000);
					*(_BYTE*)(v1 + 236) = 0;
					nox_xxx_playerSetState_4FA020(a1, 1);
				}
			} else if (*(_BYTE*)(v1 + 88) != 1) {
				v5 = nox_xxx_weaponGetStaminaByType_4F7E80(*(_DWORD*)(*(_DWORD*)(v1 + 276) + 4));
				v6 = v5;
				if (nox_xxx_playerSubStamina_4F7D30((int)a1, v5)) {
					a1[34] = *getMemU32Ptr(0x5D4594, 2598000);
					*(_BYTE*)(v1 + 236) = 0;
					if (!nox_xxx_playerSetState_4FA020(a1, 1))
						sub_4F7DB0((int)a1, -v6);
				}
			}
			nox_xxx_spellBuffOff_4FF5B0((int)a1, 0);
			nox_xxx_spellBuffOff_4FF5B0((int)a1, 23);
			nox_xxx_spellCancelDurSpell_4FEB10(67, (int)a1);
		} else if (*(_BYTE*)(v1 + 88) != 1) {
			nox_xxx_playerSetState_4FA020(a1, 1);
		}
	}
}

//----- (004F9DC0) --------------------------------------------------------
BOOL  nox_xxx_playerAimsAtEnemy_4F9DC0(int a1) {
	BOOL result; // eax

	if (!a1)
		return 0;
	if (!*(_DWORD*)(*(_DWORD*)(a1 + 748) + 288) || nox_xxx_unitIsEnemyTo_5330C0(a1, *(_DWORD*)(*(_DWORD*)(a1 + 748) + 288)) ||
		(result = nox_common_gameFlags_check_40A5C0(4096))) {
		result = 1;
	}
	return result;
}

//----- (004F9E10) --------------------------------------------------------
int  sub_4F9E10(int a1) {
	int v1; // eax
	int v2; // ecx

	if (!a1)
		return 0;
	if (!*(_DWORD*)(a1 + 520))
		return 0;
	v1 = nox_xxx_findParentChainPlayer_4EC580(*(_DWORD*)(a1 + 520));
	if (*(_BYTE*)(v1 + 16) & 0x20)
		return 0;
	v2 = *(_DWORD*)(v1 + 8);
	if (v2 & 2 || v2 & 4 && *(_BYTE*)(*(_DWORD*)(*(_DWORD*)(v1 + 748) + 276) + 3680) & 1)
		return 0;
	nox_xxx_playerCameraFollow_4E6060(a1, v1);
	return 1;
}

//----- (004F9E70) --------------------------------------------------------
void  sub_4F9E70(int a1) {
	int v1;    // edx
	int v2;    // eax
	_WORD* v3; // ecx

	v1 = sub_40AA50();
	v2 = *(_DWORD*)(a1 + 16);
	v3 = *(_WORD**)(a1 + 556);
	if ((v2 & 0x8000) == 0 && v3 && *v3 &&
		!(*getMemU32Ptr(0x5D4594, 2598000) %
		  (v1 * nox_gameFPS / (unsigned int)(unsigned __int16)v3[2]))) {
		nox_xxx_unitDamageClear_4EE5E0(a1, 1);
	}
}

//----- (004F9ED0) --------------------------------------------------------
void  sub_4F9ED0(_DWORD* a1) {
	int v1;               // ecx
	int v2;               // ebx
	unsigned __int16* v3; // eax
	int v4;               // ecx
	unsigned __int16 v5;  // si

	v1 = a1[4];
	v2 = a1[187];
	v3 = (unsigned __int16*)a1[139];
	if ((v1 & 0x8000) != 0)
		return;
	if (!v3)
		goto LABEL_8;
	v4 = nox_gameFPS;
	if ((unsigned int)(*getMemU32Ptr(0x5D4594, 2598000) - a1[134]) > (int)nox_gameFPS) {
		v5 = v3[2];
		if (*v3 < v5 && v5 &&
			!(*getMemU32Ptr(0x5D4594, 2598000) % (300 * nox_gameFPS / (unsigned int)v3[2]))) {
			nox_xxx_unitAdjustHP_4EE460((int)a1, 1);
		LABEL_8:
			v4 = nox_gameFPS;
			goto LABEL_9;
		}
	}
LABEL_9:
	if (*(_WORD*)(v2 + 4) < *(_WORD*)(v2 + 8) &&
		!(*getMemU32Ptr(0x5D4594, 2598000) % (300 * v4 / (unsigned int)*(unsigned __int16*)(v2 + 8)))) {
		nox_xxx_playerManaAdd_4EEB80((int)a1, 1);
	}
}

//----- (004F9F90) --------------------------------------------------------
int  nox_xxx_animPlayerGetFrameRange_4F9F90(int a1, _DWORD* a2, int* a3) {
	int result; // eax

	*a2 = *getMemU32Ptr(0x5D4594, 8 * a1 + 1568412);
	result = *getMemU32Ptr(0x5D4594, 8 * a1 + 1568416);
	*a3 = result;
	return result;
}

//----- (004F9FB0) --------------------------------------------------------
int  nox_xxx_anim_4F9FB0(int a1, int a2, int a3) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 8 * a1 + 1568412) = a2;
	*getMemU32Ptr(0x5D4594, 8 * a1 + 1568416) = a3;
	return result;
}

//----- (004F9FD0) --------------------------------------------------------
int  nox_xxx_unitGetStrength_4F9FD0(int a1) {
	int v1; // ecx

	if (!a1)
		return 0;
	v1 = *(_DWORD*)(a1 + 8);
	if (v1 & 4)
		return *(_DWORD*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276) + 2239);
	if (!(v1 & 2))
		return 0;
	if (*(_BYTE*)(a1 + 12) & 0x10)
		return *(unsigned __int8*)(*(_DWORD*)(a1 + 748) + 1324);
	return 30;
}

//----- (004FA020) --------------------------------------------------------
int  nox_xxx_playerSetState_4FA020(_DWORD* a1, int a2) {
	int v2; // ebx
	int v3; // ebp
	int v4; // eax
	int v5; // esi
	int v7; // eax
	int v8; // eax
	int v9; // ecx

	v2 = a2;
	v3 = 1;
	v4 = a1[4];
	v5 = a1[187];
	if ((v4 & 0x8000) != 0 && a2 != 3 && a2 != 4)
		return 0;
	if (!nox_common_gameFlags_check_40A5C0(2048)) {
		v7 = a1[4];
		if (v7 & 0x4000) {
			if (a2 == 30)
				return 0;
		}
	}
	if (a2 == 24 || a2 == 25 || a2 == 26 || a2 == 27 || a2 == 28 || a2 == 29) {
		if (nox_common_playerIsAbilityActive_4FC250((int)a1, 1))
			return 0;
		if (*(_BYTE*)(v5 + 88) == 12)
			return 0;
	}
	if (*(_BYTE*)(v5 + 88) == 1) {
		if (a2 == 1)
			goto LABEL_26;
		if (nox_xxx_probablyWarcryCheck_4FC3E0((int)a1, 2) && a2 != 4 && a2 != 3)
			return 0;
	}
	if (a2 != 1) {
		*(_BYTE*)(*(_DWORD*)(v5 + 276) + 8) = 0;
		switch (a2) {
		case 3:
		case 4:
			*(_WORD*)(v5 + 160) = 0;
			*(_DWORD*)(v5 + 164) = 0;
			break;
		case 25:
			if (*(unsigned __int8*)(v5 + 88) != a2)
				nox_xxx_aud_501960(301, (int)a1, 0, 0);
			break;
		case 26:
			if (*(unsigned __int8*)(v5 + 88) != a2)
				nox_xxx_aud_501960(300, (int)a1, 0, 0);
			break;
		case 28:
			if (*(unsigned __int8*)(v5 + 88) != a2)
				nox_xxx_aud_501960(302, (int)a1, 0, 0);
			break;
		default:
			goto LABEL_42;
		}
		goto LABEL_42;
	}
LABEL_26:
	if (*(_DWORD*)v5 <= *getMemIntPtr(0x5D4594, 2598000)) {
		v8 = *(_DWORD*)(v5 + 276);
		v9 = *(_DWORD*)(v8 + 4);
		*(_DWORD*)v5 = 0;
		if (v9) {
			*(_BYTE*)(v8 + 8) = 0;
		} else {
			*(_BYTE*)(*(_DWORD*)(v5 + 276) + 8) = nox_common_randomInt_415FA0(23, 24);
			if (!*(_BYTE*)(*(_DWORD*)(v5 + 276) + 2251) && nox_common_randomInt_415FA0(0, 100) > 75)
				*(_BYTE*)(*(_DWORD*)(v5 + 276) + 8) = 25;
			nox_xxx_spellBuffOff_4FF5B0((int)a1, 0);
			nox_xxx_spellBuffOff_4FF5B0((int)a1, 23);
			nox_xxx_spellCancelDurSpell_4FEB10(67, (int)a1);
		}
	} else {
		v3 = 0;
		v2 = *(unsigned __int8*)(v5 + 88);
	}
LABEL_42:
	if (*(unsigned __int8*)(v5 + 88) != v2) {
		*(_BYTE*)(v5 + 89) = *(_BYTE*)(v5 + 88);
		*(_BYTE*)(v5 + 88) = v2;
		a1[34] = *getMemU32Ptr(0x5D4594, 2598000);
		*(_BYTE*)(v5 + 236) = 0;
	}
	if (v2 == 30)
		*(_DWORD*)(v5 + 164) = *getMemU32Ptr(0x5D4594, 2598000);
	return v3;
}

//----- (004FA280) --------------------------------------------------------
int  sub_4FA280(int a1) {
	int v1; // ecx

	v1 = 2;
	while (!((1 << v1) & a1)) {
		if (++v1 >= 27)
			return 0;
	}
	return *getMemU32Ptr(0x587000, 4 * v1 + 215824);
}

//----- (004FA2B0) --------------------------------------------------------
int  nox_common_mapPlrActionToStateId_4FA2B0(int a1) {
	int v1;     // edi
	int result; // eax
	int v3;     // ecx

	v1 = *(_DWORD*)(a1 + 748);
	switch (*(unsigned __int8*)(v1 + 88)) {
	case 0u:
		result = 4;
		break;
	case 1u:
	case 0xEu:
	case 0x16u:
		if (nox_common_playerIsAbilityActive_4FC250(a1, 2) && nox_xxx_probablyWarcryCheck_4FC3E0(a1, 2)) {
			result = 46;
		} else if (nox_common_playerIsAbilityActive_4FC250(a1, 1)) {
			result = 45;
		} else {
			result = *(_DWORD*)(v1 + 276);
			v3 = *(_DWORD*)(result + 4);
			if (v3 & 0x47F0000) {
				result = ~(unsigned __int8)*(_DWORD*)(*(_DWORD*)(*(_DWORD*)(v1 + 104) + 736) + 96) & 2;
				LOBYTE(result) = result | 0x1D;
			} else if (v3 && v3 != 1 || (LOBYTE(result) = *(_BYTE*)(result + 8), !(_BYTE)result)) {
				result = sub_4FA280(v3);
			} else {
				result = (unsigned __int8)result;
			}
		}
		break;
	case 2u:
	case 0xAu:
		result = 21;
		break;
	case 3u:
		result = 1;
		break;
	case 4u:
		result = 2;
		break;
	case 5u:
		result = 6;
		break;
	case 0xCu:
		result = 3;
		break;
	case 0xDu:
		result = (*(_DWORD*)(*(_DWORD*)(v1 + 276) + 4) & 0x400) != 0 ? 0x26 : 0;
		break;
	case 0xFu:
	case 0x10u:
	case 0x11u:
		result = 40;
		break;
	case 0x12u:
		result = 48;
		break;
	case 0x13u:
		result = 49;
		break;
	case 0x14u:
		result = 47;
		break;
	case 0x15u:
		result = 30;
		break;
	case 0x17u:
		result = 50;
		break;
	case 0x18u:
		result = 19;
		break;
	case 0x19u:
		result = 20;
		break;
	case 0x1Au:
		result = 15;
		break;
	case 0x1Bu:
	case 0x1Cu:
	case 0x1Du:
		result = 16;
		break;
	case 0x1Eu:
		result = 52;
		break;
	case 0x20u:
		result = 54;
		break;
	default:
		result = 0;
		break;
	}
	return result;
}

//----- (004FA490) --------------------------------------------------------
int  nox_xxx_itemApplyUpdateEffect_4FA490(int a1) {
	int result;                              // eax
	_DWORD* i;                               // esi
	int* v3;                                 // edi
	int v4;                                  // ebx
	int( * v5)(int, _DWORD*, _DWORD); // ecx

	result = a1;
	for (i = *(_DWORD**)(a1 + 504); i; i = (_DWORD*)i[124]) {
		result = i[4];
		if (result & 0x100 && i[2] & 0x13001000) {
			v3 = (int*)i[173];
			v4 = 4;
			do {
				result = *v3;
				if (*v3) {
					v5 = *(int(**)(int, _DWORD*, _DWORD))(result + 100);
					if (v5)
						result = v5(result, i, 0);
				}
				++v3;
				--v4;
			} while (v4);
		}
	}
	return result;
}

//----- (004FA4F0) --------------------------------------------------------
int  nox_xxx_checkInversionEffect_4FA4F0(int a1, int a2) {
	_DWORD* v2;                                         // edi
	int v3;                                             // eax
	int v4;                                             // ebp
	int* v5;                                            // ebx
	int v6;                                             // esi
	BOOL( * v7)(int, int, int, int, int, BOOL*); // eax
	int v8;                                             // eax
	int result;                                         // eax
	int v10;                                            // [esp+10h] [ebp-4h]

	v2 = *(_DWORD**)(a1 + 504);
	if (!v2)
		return 0;
	while (1) {
		v3 = v2[4];
		if (v3 & 0x100) {
			if (v2[2] & 0x13001000)
				break;
		}
	LABEL_10:
		v2 = (_DWORD*)v2[124];
		if (!v2)
			return 0;
	}
	v4 = 2;
	v5 = (int*)(v2[173] + 8);
	while (1) {
		v6 = *v5;
		v10 = 0;
		if (v6) {
			v7 = *(BOOL(**)(int, int, int, int, int, BOOL*))(v6 + 88);
			if (v7) {
				if (v7 == nox_xxx_inversionEffect_4E03D0) {
					v8 = nox_xxx_findParentChainPlayer_4EC580(a2);
					(*(void(**)(int, _DWORD*, int, int, int, int*))(v6 + 88))(v6, v2, a1, a2, v8, &v10);
					result = 1;
					if (v10 == 1)
						return result;
				}
			}
		}
		++v4;
		++v5;
		if (v4 >= 4)
			goto LABEL_10;
	}
}

//----- (004FA590) --------------------------------------------------------
_DWORD*  nox_xxx_playerAddGold_4FA590(int a1, int a2) {
	int v2; // eax

	v2 = *(_DWORD*)(a1 + 748);
	*(_DWORD*)(*(_DWORD*)(v2 + 276) + 2164) += a2;
	return sub_56F920(*(_DWORD*)(*(_DWORD*)(v2 + 276) + 4588), a2);
}

//----- (004FA5D0) --------------------------------------------------------
_DWORD*  nox_xxx_playerSubGold_4FA5D0(int a1, unsigned int a2) {
	int v2;          // esi
	int v3;          // edx
	unsigned int v4; // eax

	v2 = *(_DWORD*)(a1 + 748);
	v3 = *(_DWORD*)(v2 + 276);
	v4 = *(_DWORD*)(v3 + 2164);
	if (v4 >= a2)
		*(_DWORD*)(v3 + 2164) = v4 - a2;
	else
		*(_DWORD*)(v3 + 2164) = 0;
	return sub_56F920(*(_DWORD*)(*(_DWORD*)(v2 + 276) + 4588), -a2);
}

//----- (004FA620) --------------------------------------------------------
_DWORD*  sub_4FA620(int a1, int a2) {
	_DWORD* result; // eax
	int v3;         // eax
	int v4;         // edx

	result = (_DWORD*)a1;
	if (a1 && *(_BYTE*)(a1 + 8) & 4) {
		v3 = *(_DWORD*)(a1 + 748);
		if (a2 >= 0 || (v4 = *(_DWORD*)(v3 + 276), *(_DWORD*)(v4 + 2164) >= (unsigned int)-a2)) {
			*(_DWORD*)(*(_DWORD*)(v3 + 276) + 2164) += a2;
			result = sub_56F920(*(_DWORD*)(*(_DWORD*)(v3 + 276) + 4588), a2);
		} else {
			*(_DWORD*)(v4 + 2164) = 0;
			result = nox_xxx_playerUpdateNetBuffs_56F7D0(*(_DWORD*)(*(_DWORD*)(v3 + 276) + 4588), 0);
		}
	}
	return result;
}

//----- (004FA6B0) --------------------------------------------------------
int  nox_xxx_playerGetGold_4FA6B0(int a1) { return *(_DWORD*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276) + 2164); }

//----- (004FA6D0) --------------------------------------------------------
int  sub_4FA6D0(int a1) {
	int result; // eax

	if (a1 && *(_BYTE*)(a1 + 8) & 4)
		result = *(_DWORD*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276) + 2164);
	else
		result = 0;
	return result;
}

//----- (004FA700) --------------------------------------------------------
int  nox_xxx_playerBotCreate_4FA700(int a1) {
	int result;       // eax
	int v2;           // ebp
	_DWORD* v3;       // esi
	int v4;           // eax
	int v5;           // eax
	int v6;           // ebp
	unsigned int v7;  // edx
	__int16 v8;       // ax
	__int16 v9;       // ax
	int v10;          // ebp
	unsigned int v11; // eax
	int v12;          // eax
	__int16 v13;      // cx

	result = a1;
	v2 = *(_DWORD*)(a1 + 748);
	if (!*(_DWORD*)(v2 + 292)) {
		result = (int)calloc(1u, 0x898u);
		*(_DWORD*)(v2 + 292) = result;
	}
	v3 = *(_DWORD**)(v2 + 292);
	if (v3) {
		memset(v3, 0, 0x898u);
		v3[545] = v2;
		v4 = nox_xxx_getNameId_4E3AA0("NPC");
		v3[121] = nox_xxx_monsterDefByTT_517560(v4);
		v3[334] = 1048576000;
		*((_BYTE*)v3 + 1340) = 1;
		v3[336] = 1061997773;
		*((_BYTE*)v3 + 1348) = 1;
		v3[360] = 186376;
		*((_BYTE*)v3 + 1444) = 0;
		*((_BYTE*)v3 + 544) = 0;
		v3[138] = 5;
		v3[340] = 38;
		v3[327] = 1056964608;
		v3[326] = 1062501089;
		v3[328] = 1125515264;
		v3[329] = 1106247680;
		*((_BYTE*)v3 + 1332) = -1;
		v3[330] = 1065353216;
		*((_BYTE*)v3 + 1324) = 30;
		v3[332] = 1056964608;
		v3[338] = 1065353216;
		v3[307] = -1;
		v3[309] = -1;
		v3[311] = -1;
		v3[313] = -1;
		v3[315] = -1;
		v3[317] = -1;
		v3[319] = -1;
		v3[321] = -1;
		v3[323] = -1;
		v3[325] = -1;
		v3[510] = 3;
		v3[524] = -1;
		v3[525] = -1;
		*v3 = -559023410;
		v3[94] = *(__int16*)(a1 + 124);
		v3[95] = *(_DWORD*)(a1 + 56);
		v3[96] = *(_DWORD*)(a1 + 60);
		result = *(unsigned __int8*)(*(_DWORD*)(v2 + 276) + 2251);
		if (*(_BYTE*)(*(_DWORD*)(v2 + 276) + 2251)) {
			v5 = result - 1;
			if (v5) {
				result = v5 - 1;
				if (!result) {
					v6 = v3[360];
					v3[339] = 1112014848;
					v3[410] = 0x8000000;
					v3[360] = v6 | 0x20;
					*((_WORD*)v3 + 724) = 0;
					v7 = nox_gameFPS;
					v3[430] = 0x10000000;
					*((_WORD*)v3 + 725) = v7 >> 1;
					*((_WORD*)v3 + 728) = 0;
					*((_WORD*)v3 + 729) = 6 * (_WORD)nox_gameFPS;
					v3[432] = 0x20000000;
					v3[446] = 0x20000000;
					*((_WORD*)v3 + 732) = 3 * (_WORD)nox_gameFPS;
					v8 = (_WORD)nox_gameFPS;
					*((_WORD*)v3 + 736) = 0;
					*((_WORD*)v3 + 733) = 30 * v8;
					v3[401] = 0x40000000;
					v3[424] = 0x40000000;
					v3[456] = 0x40000000;
					v3[455] = 0x40000000;
					v3[464] = 0x40000000;
					v9 = (_WORD)nox_gameFPS;
					v3[376] = 2147483648;
					*((_WORD*)v3 + 740) = 0;
					*((_WORD*)v3 + 737) = 2 * v9;
					result = nox_gameFPS;
					*((_WORD*)v3 + 741) = 6 * (_WORD)nox_gameFPS;
				}
			} else {
				v10 = v3[360];
				v3[339] = 1112014848;
				v3[410] = 0x8000000;
				v3[360] = v10 | 0x20;
				*((_WORD*)v3 + 724) = 0;
				v11 = nox_gameFPS;
				*((_WORD*)v3 + 728) = 0;
				*((_WORD*)v3 + 725) = v11 >> 1;
				v3[423] = 0x10000000;
				v3[408] = 0x10000000;
				v3[411] = 0x10000000;
				*((_WORD*)v3 + 729) = (_WORD)nox_gameFPS;
				v3[384] = 0x20000000;
				v3[405] = 0x20000000;
				*((_WORD*)v3 + 732) = 3 * (_WORD)nox_gameFPS;
				*((_WORD*)v3 + 733) = 30 * (_WORD)nox_gameFPS;
				v12 = nox_common_randomInt_415FA0(0, 100);
				if (v12 >= 33) {
					if (v12 >= 66) {
						v3[415] = 0x40000000;
						v3[422] = 0x40000000;
					} else {
						v3[388] = 0x40000000;
					}
				} else {
					v3[399] = 0x40000000;
				}
				*((_WORD*)v3 + 736) = 0;
				v13 = (_WORD)nox_gameFPS;
				v3[376] = 2147483648;
				*((_WORD*)v3 + 740) = 0;
				*((_WORD*)v3 + 737) = 2 * v13;
				result = 6 * nox_gameFPS;
				*((_WORD*)v3 + 741) = 6 * (_WORD)nox_gameFPS;
			}
		} else {
			v3[339] = 0;
		}
	}
	return result;
}

//----- (004FAAC0) --------------------------------------------------------
char  nox_xxx_mobMorphFromPlayer_4FAAC0(_DWORD* a1) {
	int v1; // eax
	int v2; // edx

	v1 = a1[2];
	if (v1 & 4) {
		LOBYTE(v1) = v1 & 0xFB | 2;
		v2 = *(_DWORD*)(a1[187] + 292);
		a1[2] = v1;
		a1[187] = v2;
		a1[3] = 16;
	}
	return v1;
}

//----- (004FAAF0) --------------------------------------------------------
char  nox_xxx_mobMorphToPlayer_4FAAF0(_DWORD* a1) {
	int v1; // eax
	int v2; // edx

	v1 = a1[2];
	if (v1 & 2) {
		LOBYTE(v1) = v1 & 0xFD | 4;
		v2 = *(_DWORD*)(a1[187] + 2180);
		a1[2] = v1;
		a1[187] = v2;
		a1[3] = 0;
	}
	return v1;
}

//----- (004FAB20) --------------------------------------------------------
int  nox_xxx_updatePlayerMonsterBot_4FAB20(_DWORD* a1) {
	int v1;     // edi
	int result; // eax
	int v3;     // ebx
	int v4;     // eax
	char v5;    // al
	int v6;     // ecx

	v1 = a1[187];
	if (*(_DWORD*)(v1 + 292) || (nox_xxx_playerBotCreate_4FA700((int)a1), (result = *(_DWORD*)(v1 + 292)) != 0)) {
		result = nox_xxx_respawnPlayerBot_4FAC70((int)a1);
		if (!result) {
			v3 = *(_DWORD*)(v1 + 292);
			v4 = *(_DWORD*)(v3 + 1440);
			BYTE1(v4) |= 1u;
			*(_DWORD*)(v3 + 1440) = v4;
			nox_xxx_mobMorphFromPlayer_4FAAC0(a1);
			nox_xxx_unitUpdateMonster_50A5C0(*(float*)&a1);
			nox_xxx_mobMorphToPlayer_4FAAF0(a1);
			v5 = nox_xxx_monsterActionToPlrState_4FABC0((int)a1);
			v6 = *(_DWORD*)(v1 + 276);
			*(_BYTE*)(v1 + 88) = v5;
			*(_BYTE*)(v1 + 236) = *(_BYTE*)(v3 + 481);
			*(_DWORD*)(v6 + 3632) = a1[14];
			result = a1[15];
			*(_DWORD*)(v6 + 3636) = result;
		}
	} else {
		a1[186] = nox_xxx_updatePlayer_4F8100;
	}
	return result;
}

//----- (004FABC0) --------------------------------------------------------
char  nox_xxx_monsterActionToPlrState_4FABC0(int a1) {
	int v1;      // ecx
	char v2;     // al
	char result; // al

	v1 = *(_DWORD*)(*(_DWORD*)(a1 + 748) + 292);
	v2 = *(_BYTE*)(v1 + 544);
	if (v2 == -1)
		return 13;
	switch (*(_DWORD*)(v1 + 24 * (v2 + 23))) {
	case 7:
	case 8:
	case 0xA:
	case 0xD:
	case 0x1D:
		result = (*(_DWORD*)(v1 + 1440) & 0x4000) != 0 ? 5 : 0;
		break;
	case 9:
		result = 0;
		break;
	case 0x10:
	case 0x11:
		result = 1;
		break;
	case 0x12:
	case 0x13:
	case 0x14:
		result = 2;
		break;
	case 0x15:
	case 0x17:
		result = 16;
		break;
	case 0x16:
		result = 17;
		break;
	case 0x18:
		result = 5;
		break;
	case 0x1E:
		result = 3;
		break;
	case 0x1F:
		result = 4;
		break;
	default:
		return 13;
	}
	return result;
}

//----- (004FAC70) --------------------------------------------------------
int  nox_xxx_respawnPlayerBot_4FAC70(int a1) {
	int v1;    // edi
	char* v2;  // ebx
	float2 v4; // [esp+Ch] [ebp-8h]

	v1 = *(_DWORD*)(*(_DWORD*)(a1 + 748) + 292);
	v2 = sub_416640();
	if (!**(_WORD**)(a1 + 556)) {
		if (*getMemU32Ptr(0x5D4594, 2598000) - *(_DWORD*)(v1 + 548) <
			(unsigned int)(2 * nox_gameFPS))
			return 1;
		nox_xxx_playerBotCreate_4FA700(a1);
		nox_xxx_playerMakeDefItems_4EF7D0(a1, 1, 0);
		if (!dword_5d4594_2650652 || *(_DWORD*)(v2 + 58))
			nox_xxx_respawnPlayerImpl_53FBC0((float*)(a1 + 56), *(__int16*)(a1 + 124));
		nox_xxx_mapFindPlayerStart_4F7AB0(&v4, a1);
		nox_xxx_unitMove_4E7010(a1, &v4);
		nox_xxx_aud_501960(148, a1, 0, 0);
		if (nox_common_gameFlags_check_40A5C0(0x2000))
			nox_xxx_buffApplyTo_4FF380(a1, 23, 5 * (_WORD)nox_gameFPS, 5);
	}
	return 0;
}

//----- (004FAD50) --------------------------------------------------------
int  nox_xxx_netSendRewardNotify_4FAD50(int a1, int a2, int a3, char a4) {
	int result; // eax
	int v5;     // ecx
	char v6[5]; // [esp+0h] [ebp-8h]

	result = a1;
	if (a1 && *(_BYTE*)(a1 + 8) & 4) {
		v5 = *(_DWORD*)(a1 + 748);
		v6[0] = -16;
		if (a2) {
			if (a2 == 1) {
				v6[1] = 31;
			} else {
				result = a2 - 2;
				if (a2 != 2)
					return result;
				v6[1] = 32;
			}
		} else {
			v6[1] = 30;
		}
		*(_WORD*)&v6[3] = *(_WORD*)(a3 + 36);
		v6[2] = a4;
		result = nox_xxx_netSendPacket0_4E5420(*(unsigned __int8*)(*(_DWORD*)(v5 + 276) + 2064), v6, 5, 0, 1);
	}
	return result;
}

//----- (004FADD0) --------------------------------------------------------
void  sub_4FADD0(int a1, const char* a2, char a3) {
	unsigned int v4; // kr04_4
	char v5[52];     // [esp+8h] [ebp-34h]

	if (a1) {
		if (*(_BYTE*)(a1 + 8) & 4) {
			if (a2) {
				v4 = strlen(a2) + 1;
				if ((_BYTE)v4 != 1 && (unsigned __int8)(v4 - 1) <= 0x30u) {
					v5[51] = a3;
					v5[0] = -16;
					v5[1] = 33;
					strcpy(&v5[2], a2);
					nox_xxx_netSendPacket0_4E5420(*(unsigned __int8*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276) + 2064), v5, 52, 0, 1);
				}
			}
		}
	}
}

//----- (004FB000) --------------------------------------------------------
int  sub_4FB000(int a1, int a2) {
	int v2;         // esi
	const char* v3; // eax
	int v4;         // eax
	int result;     // eax

	if (a1 && a2 && *(_BYTE*)(a1 + 8) & 4 && *(_BYTE*)(a2 + 8) & 2 &&
		(v2 = *(_DWORD*)(a1 + 748), v3 = (const char*)nox_xxx_getUnitName_4E39D0(a2), (v4 = nox_xxx_guide_427010(v3)) != 0)) {
		result = *(_DWORD*)(*(_DWORD*)(v2 + 276) + 4 * v4 + 4244);
	} else {
		result = 0;
	}
	return result;
}

//----- (004FB050) --------------------------------------------------------
int  sub_4FB050(int a1, int a2, int* a3) {
	int result; // eax
	float v4;   // [esp+0h] [ebp-8h]

	result = sub_4FB000(a1, a2);
	if (result) {
		v4 = nox_xxx_gamedataGetFloat_419D40(getMemAt(0x587000, 216356)) * (double)*a3 + 0.5;
		result = nox_float2int(v4);
		*a3 = result;
	}
	return result;
}

//----- (004FB0E0) --------------------------------------------------------
int  nox_xxx_playerDoSchedSpell_4FB0E0(int a1, int a2) {
	_DWORD* v2; // edi
	int v3;     // esi
	int v5;     // ecx
	_DWORD* v6; // eax
	int v7[3];  // [esp+8h] [ebp-Ch]

	v2 = (_DWORD*)a1;
	v3 = *(_DWORD*)(a1 + 748);
	if (!*(_BYTE*)(v3 + 212))
		return 0;
	a1 = nox_xxx_checkPlrCantCastSpell_4FD150(a1, *(_DWORD*)(v3 + 192), 0);
	v7[0] = a2;
	*(float*)&v7[1] = (double)*(int*)(v3 + 220);
	*(float*)&v7[2] = (double)*(int*)(v3 + 224);
	if (a1) {
		nox_xxx_netInformTextMsg_4DA0F0(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), 0, &a1);
		nox_xxx_aud_501960(231, (int)v2, 0, 0);
	} else {
		nox_xxx_castSpellByUser_4FDD20(*(_DWORD*)(v3 + 192), v2, v7);
	}
	v5 = 1;
	if (*(_BYTE*)(v3 + 212) > 1u) {
		v6 = (_DWORD*)(v3 + 192);
		do {
			++v5;
			*v6 = v6[1];
			++v6;
		} while (v5 < *(unsigned __int8*)(v3 + 212));
	}
	*(_DWORD*)(v3 + 4 * v5 + 188) = 0;
	--*(_BYTE*)(v3 + 212);
	return 1;
}

//----- (004FB1D0) --------------------------------------------------------
int  nox_xxx_playerDoSchedSpellQueue_4FB1D0(int a1, int a2) {
	_DWORD* v2; // edi
	int v3;     // esi
	int v5[3];  // [esp+8h] [ebp-Ch]

	v2 = (_DWORD*)a1;
	v3 = *(_DWORD*)(a1 + 748);
	if (!*(_BYTE*)(v3 + 212))
		return 0;
	a1 = nox_xxx_checkPlrCantCastSpell_4FD150(a1, *(_DWORD*)(v3 + 4 * *(unsigned __int8*)(v3 + 212) + 188), 0);
	v5[0] = a2;
	*(float*)&v5[1] = (double)*(int*)(v3 + 220);
	*(float*)&v5[2] = (double)*(int*)(v3 + 224);
	if (a1) {
		nox_xxx_netInformTextMsg_4DA0F0(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), 0, &a1);
		nox_xxx_aud_501960(231, (int)v2, 0, 0);
	} else {
		nox_xxx_castSpellByUser_4FDD20(*(_DWORD*)(v3 + 4 * *(unsigned __int8*)(v3 + 212) + 188), v2, v5);
	}
	--*(_BYTE*)(v3 + 212);
	return 1;
}

//----- (004FB990) --------------------------------------------------------
char* nox_xxx_allocArrayExecAbilities_4FB990() {
	char* result; // eax

	memset(getMemAt(0x5D4594, 1568876), 0, 0x300u);
	result = nox_new_alloc_class("executingAbilityClass", 24, 64);
	nox_alloc_execAbil_1569644 = result;
	return result;
}

//----- (004FBAF0) --------------------------------------------------------
void  nox_xxx_playerInvokeAbility_4FBAF0(_DWORD* a1, int a2) {
	__int16 v2; // ax
	__int16 v3; // ax

	if (!(a1[4] & 0x8020)) {
		switch (a2) {
		case 1:
			nox_xxx_warriorBerserker_53FEB0((int)a1);
			break;
		case 2:
			nox_xxx_warriorWarcry_53FF40((int)a1);
			break;
		case 3:
			nox_xxx_warriorHarpoon_540070(a1);
			break;
		case 4:
			v2 = sub_425470(4);
			nox_xxx_warriorTreadLightly_5400B0(a1, v2);
			break;
		case 5:
			v3 = sub_425470(5);
			nox_xxx_warriorInfravis_540110((int)a1, v3);
			break;
		default:
			return;
		}
	}
}

//----- (004FBB70) --------------------------------------------------------
void  nox_xxx_playerExecuteAbil_4FBB70(int a1, int a2) {
	_DWORD* v2;  // esi
	int v3;      // edi
	int v4;      // ebx
	int v5;      // eax
	int v6;      // eax
	int v7;      // eax
	int v8;      // eax
	int v9;      // ebp
	int v10;     // ebx
	_DWORD* v11; // eax
	int v12;     // ecx
	int v13;     // eax

	v2 = (_DWORD*)a1;
	if (!a1)
		return;
	v3 = a2;
	if (a2 <= 0)
		return;
	if (a2 >= 6)
		return;
	if (*(_DWORD*)(a1 + 16) & 0x8020)
		return;
	if (!(*(_BYTE*)(a1 + 8) & 4))
		return;
	v4 = *(_DWORD*)(a1 + 748);
	if (*(_BYTE*)(*(_DWORD*)(v4 + 276) + 2251))
		return;
	if (nox_common_gameFlags_check_40A5C0(32) && v3 == 1) {
		v5 = v2[126];
		if (v5) {
			while (!(*(_DWORD*)(v5 + 8) & 0x10000000)) {
				v5 = *(_DWORD*)(v5 + 496);
				if (!v5)
					goto LABEL_12;
			}
			a1 = 5;
			nox_xxx_netInformTextMsg_4DA0F0(*(unsigned __int8*)(*(_DWORD*)(v4 + 276) + 2064), 2, &a1);
			goto LABEL_49;
		}
	LABEL_12:
		v6 = nox_xxx_probablyWarcryCheck_4FC3E0((int)v2, 2);
		goto LABEL_16;
	}
	if (v3 == 2) {
		v6 = nox_common_playerIsAbilityActive_4FC250((int)v2, 1);
	LABEL_16:
		if (v6) {
		LABEL_19:
			a1 = 2;
		LABEL_30:
			nox_xxx_netInformTextMsg_4DA0F0(*(unsigned __int8*)(*(_DWORD*)(v4 + 276) + 2064), 2, &a1);
		LABEL_49:
			nox_xxx_aud_501960(231, (int)v2, 0, 0);
			return;
		}
		v7 = nox_common_playerIsAbilityActive_4FC250((int)v2, 3);
		goto LABEL_18;
	}
	if (v3 == 1) {
		v6 = nox_xxx_probablyWarcryCheck_4FC3E0((int)v2, 2);
		goto LABEL_16;
	}
	if (v3 != 3)
		goto LABEL_25;
	if (nox_xxx_probablyWarcryCheck_4FC3E0((int)v2, 2))
		goto LABEL_19;
	v7 = nox_common_playerIsAbilityActive_4FC250((int)v2, 1);
LABEL_18:
	if (v7)
		goto LABEL_19;
LABEL_25:
	if (nox_common_playerIsAbilityActive_4FC250((int)v2, v3))
		goto LABEL_19;
	if (*(_BYTE*)(v4 + 88) == 12 || !nox_common_gameFlags_check_40A5C0(2048) && (v8 = v2[4], BYTE1(v8) & 0x40)) {
		a1 = 6;
		goto LABEL_30;
	}
	v9 = *(_DWORD*)(v4 + 276);
	if ((!nox_common_gameFlags_check_40A5C0(0x2000) || nox_common_gameFlags_check_40A5C0(4096)) &&
		!*(_DWORD*)(v9 + 4 * v3 + 3696)) {
		a1 = 3;
		goto LABEL_48;
	}
	if (v3 == 1 && *(_DWORD*)(*(_DWORD*)(v4 + 276) + 3656) == 1) {
		a1 = 7;
		nox_xxx_netInformTextMsg_4DA0F0(*(unsigned __int8*)(*(_DWORD*)(v4 + 276) + 2064), 2, &a1);
		return;
	}
	if (*getMemU32Ptr(0x5D4594, 1568876 + 4 * (v3 + 6 * *(unsigned __int8*)(v9 + 2064)))) {
		a1 = 2;
	LABEL_48:
		nox_xxx_netInformTextMsg_4DA0F0(*(unsigned __int8*)(*(_DWORD*)(v4 + 276) + 2064), 2, &a1);
		goto LABEL_49;
	}
	*getMemU32Ptr(0x5D4594, 1568876 + 4 * (v3 + 6 * *(unsigned __int8*)(v9 + 2064))) = nox_xxx_abilityCooldown_4252D0(v3);
	if (nox_xxx_abilityCooldown_4252D0(v3))
		nox_xxx_netAbilRepotState_4D8100((int)v2, v3, 0);
	v10 = sub_425470(v3);
	if (v10 > 0) {
		v11 = nox_alloc_class_new_obj_zero(*(_DWORD**)&nox_alloc_execAbil_1569644);
		if (v11) {
			v12 = *getMemU32Ptr(0x5D4594, 2598000);
			v11[1] = v2;
			*v11 = v3;
			v11[2] = v10 + v12;
			v11[4] = *getMemU32Ptr(0x5D4594, 1569648) ;
			v11[3] = 1;
			v11[5] = 0;
			if (*getMemU32Ptr(0x5D4594, 1569648) )
				*(_DWORD*)(*getMemU32Ptr(0x5D4594, 1569648) + 20) = v11;
			*getMemU32Ptr(0x5D4594, 1569648)  = v11;
		}
	}
	nox_xxx_playerInvokeAbility_4FBAF0(v2, v3);
	v13 = sub_425230(v3, 0);
	nox_xxx_aud_501960(v13, (int)v2, 0, 0);
}

//----- (004FBE60) --------------------------------------------------------
int  sub_4FBE60(int a1, int a2) {
	char* v2;   // eax
	int result; // eax

	v2 = nox_common_playerInfoGetByID_417040(*(_DWORD*)(a1 + 36));
	if (v2)
		result = *getMemU32Ptr(0x5D4594, 1568876 + 4 * (a2 + 6 * (unsigned __int8)v2[2064]));
	else
		result = 0;
	return result;
}

//----- (004FBEA0) --------------------------------------------------------
char*  sub_4FBEA0(int a1, int a2, int a3) {
	char* result; // eax
	int v4;       // edx

	result = nox_common_playerInfoGetByID_417040(*(_DWORD*)(a1 + 36));
	if (result) {
		v4 = a2 + 6 * (unsigned __int8)result[2064];
		result = (char*)a3;
		*getMemU32Ptr(0x5D4594, 1568876 + 4 * v4) = a3;
	}
	return result;
}

//----- (004FC030) --------------------------------------------------------
int  sub_4FC030(int a1, int a2) {
	_DWORD* v2; // eax

	v2 = *(_DWORD**)getMemAt(0x5D4594, 1569648);
	if (!*getMemU32Ptr(0x5D4594, 1569648) )
		return -1;
	while (v2[1] != a1 || *v2 != a2) {
		v2 = (_DWORD*)v2[4];
		if (!v2)
			return -1;
	}
	return v2[2] - *getMemU32Ptr(0x5D4594, 2598000);
}

//----- (004FC070) --------------------------------------------------------
_DWORD*  sub_4FC070(int a1, int a2, int a3) {
	_DWORD* result; // eax

	result = *(_DWORD**)getMemAt(0x5D4594, 1569648);
	if (*getMemU32Ptr(0x5D4594, 1569648) ) {
		while (result[1] != a1 || *result != a2) {
			result = (_DWORD*)result[4];
			if (!result)
				return result;
		}
		result[2] = a3 + *getMemU32Ptr(0x5D4594, 2598000);
	}
	return result;
}

//----- (004FC0B0) --------------------------------------------------------
void  sub_4FC0B0(int a1, int a2) {
	int v2; // eax
	int v3; // esi
	int v4; // eax
	int v5; // edi
	int v6; // eax
	int v7; // eax

	if (a1) {
		if (*(_BYTE*)(a1 + 8) & 4) {
			v2 = *(_DWORD*)(*(_DWORD*)(a1 + 748) + 276);
			if (!*(_BYTE*)(v2 + 2251)) {
				*getMemU32Ptr(0x5D4594, 1568876 + 4 * (a2 + 6 * *(unsigned __int8*)(v2 + 2064))) = 0;
				sub_4D80C0(a1, a2);
				v3 = *getMemU32Ptr(0x5D4594, 1569648) ;
				if (*getMemU32Ptr(0x5D4594, 1569648) ) {
					do {
						v4 = *(_DWORD*)(v3 + 4);
						v5 = *(_DWORD*)(v3 + 16);
						if (v4 == a1 && *(_DWORD*)v3 == a2) {
							sub_4FC3C0(v4, *(_DWORD*)v3, 0);
							v6 = *(_DWORD*)(v3 + 16);
							if (v6)
								*(_DWORD*)(v6 + 20) = *(_DWORD*)(v3 + 20);
							v7 = *(_DWORD*)(v3 + 20);
							if (v7)
								*(_DWORD*)(v7 + 16) = *(_DWORD*)(v3 + 16);
							else
								*getMemU32Ptr(0x5D4594, 1569648)  = *(_DWORD*)(v3 + 16);
							nox_alloc_class_free_obj(*(unsigned int**)&nox_alloc_execAbil_1569644, (_QWORD*)v3);
						}
						v3 = v5;
					} while (v5);
				}
			}
		}
	}
}

//----- (004FC180) --------------------------------------------------------
void  nox_xxx_playerCancelAbils_4FC180(int a1) {
	int v1; // edx
	int i;  // eax
	int v3; // ecx
	int v4; // esi
	int v5; // eax
	int v6; // edi
	int v7; // eax
	int v8; // eax

	if (a1) {
		if (*(_BYTE*)(a1 + 8) & 4) {
			v1 = *(_DWORD*)(a1 + 748);
			if (!*(_BYTE*)(*(_DWORD*)(v1 + 276) + 2251)) {
				for (i = 1; i < 6; ++i) {
					v3 = i + 6 * *(unsigned __int8*)(*(_DWORD*)(v1 + 276) + 2064);
					*getMemU32Ptr(0x5D4594, 1568876 + 4 * v3) = 0;
				}
				sub_4D80C0(a1, 6);
				v4 = *getMemU32Ptr(0x5D4594, 1569648) ;
				if (*getMemU32Ptr(0x5D4594, 1569648) ) {
					do {
						v5 = *(_DWORD*)(v4 + 4);
						v6 = *(_DWORD*)(v4 + 16);
						if (v5 == a1) {
							sub_4FC3C0(v5, *(_DWORD*)v4, 0);
							v7 = *(_DWORD*)(v4 + 16);
							if (v7)
								*(_DWORD*)(v7 + 20) = *(_DWORD*)(v4 + 20);
							v8 = *(_DWORD*)(v4 + 20);
							if (v8)
								*(_DWORD*)(v8 + 16) = *(_DWORD*)(v4 + 16);
							else
								*getMemU32Ptr(0x5D4594, 1569648)  = *(_DWORD*)(v4 + 16);
							nox_alloc_class_free_obj(*(unsigned int**)&nox_alloc_execAbil_1569644, (_QWORD*)v4);
						}
						v4 = v6;
					} while (v6);
				}
			}
		}
	}
}

//----- (004FC250) --------------------------------------------------------
int  nox_common_playerIsAbilityActive_4FC250(int a1, int a2) {
	int v2;     // eax
	_DWORD* v3; // eax
	int v4;     // ecx

	if (!(*(_BYTE*)(a1 + 8) & 4))
		return 0;
	v2 = *(_DWORD*)(a1 + 748);
	if (v2) {
		if (*(_BYTE*)(*(_DWORD*)(v2 + 276) + 2251))
			return 0;
	}
	v3 = *(_DWORD**)getMemAt(0x5D4594, 1569648);
	if (!*getMemU32Ptr(0x5D4594, 1569648) )
		return 0;
	while (1) {
		v4 = v3[4];
		if (v3[1] == a1 && *v3 == a2)
			break;
		v3 = (_DWORD*)v3[4];
		if (!v4)
			return 0;
	}
	return 1;
}

//----- (004FC2B0) --------------------------------------------------------
int  nox_xxx_playerIsExecutingAbility_4FC2B0(int a1) {
	int v1; // eax
	int v2; // eax

	if (!(*(_BYTE*)(a1 + 8) & 4))
		return 0;
	v1 = *(_DWORD*)(a1 + 748);
	if (v1) {
		if (*(_BYTE*)(*(_DWORD*)(v1 + 276) + 2251))
			return 0;
	}
	v2 = *getMemU32Ptr(0x5D4594, 1569648) ;
	if (!*getMemU32Ptr(0x5D4594, 1569648) )
		return 0;
	while (*(_DWORD*)(v2 + 4) != a1) {
		v2 = *(_DWORD*)(v2 + 16);
		if (!v2)
			return 0;
	}
	return 1;
}

//----- (004FC300) --------------------------------------------------------
void  sub_4FC300(_DWORD* a1, int a2) {
	int v2; // eax
	int v3; // esi
	int v4; // ecx

	if (a1 && a2 > 0 && a2 < 6) {
		switch (a2) {
		case 3:
			nox_xxx_netHarpoonBreak_4D98A0(a1, *(_DWORD**)(a1[187] + 136));
			break;
		case 4:
			nox_xxx_spellBuffOff_4FF5B0((int)a1, 31);
			break;
		case 5:
			return;
		}
		sub_4FC3C0((int)a1, a2, 0);
		v2 = *getMemU32Ptr(0x5D4594, 1569648) ;
		if (*getMemU32Ptr(0x5D4594, 1569648) ) {
			do {
				v3 = *(_DWORD*)(v2 + 16);
				if (*(_DWORD**)(v2 + 4) == a1 && *(_DWORD*)v2 == a2) {
					if (v3)
						*(_DWORD*)(v3 + 20) = *(_DWORD*)(v2 + 20);
					v4 = *(_DWORD*)(v2 + 20);
					if (v4)
						*(_DWORD*)(v4 + 16) = *(_DWORD*)(v2 + 16);
					else
						*getMemU32Ptr(0x5D4594, 1569648)  = *(_DWORD*)(v2 + 16);
					nox_alloc_class_free_obj(*(unsigned int**)&nox_alloc_execAbil_1569644, (_QWORD*)v2);
				}
				v2 = v3;
			} while (v3);
		}
	}
}

//----- (004FC3C0) --------------------------------------------------------
int  sub_4FC3C0(int a1, char a2, char a3) { return nox_xxx_netReportActiveAbils_4D8150(a1, a2, a3); }

//----- (004FC3E0) --------------------------------------------------------
int  nox_xxx_probablyWarcryCheck_4FC3E0(int a1, int a2) {
	int v2;     // eax
	_DWORD* v3; // eax
	int v4;     // ecx

	if (!(*(_BYTE*)(a1 + 8) & 4))
		return 0;
	v2 = *(_DWORD*)(a1 + 748);
	if (v2) {
		if (*(_BYTE*)(*(_DWORD*)(v2 + 276) + 2251))
			return 0;
	}
	v3 = *(_DWORD**)getMemAt(0x5D4594, 1569648);
	if (!*getMemU32Ptr(0x5D4594, 1569648) )
		return 0;
	while (1) {
		v4 = v3[4];
		if (v3[1] == a1 && *v3 == a2)
			break;
		v3 = (_DWORD*)v3[4];
		if (!v4)
			return 0;
	}
	return v3[3];
}

//----- (004FC440) --------------------------------------------------------
void  sub_4FC440(int a1, int a2) {
	int v2;     // eax
	_DWORD* v3; // eax
	int v4;     // ecx

	if (*(_BYTE*)(a1 + 8) & 4) {
		v2 = *(_DWORD*)(a1 + 748);
		if (!v2 || !*(_BYTE*)(*(_DWORD*)(v2 + 276) + 2251)) {
			v3 = *(_DWORD**)getMemAt(0x5D4594, 1569648);
			if (*getMemU32Ptr(0x5D4594, 1569648) ) {
				while (1) {
					v4 = v3[4];
					if (v3[1] == a1 && *v3 == a2)
						break;
					v3 = (_DWORD*)v3[4];
					if (!v4)
						return;
				}
				v3[3] = 0;
			}
		}
	}
}

//----- (004FC4A0) --------------------------------------------------------
int  nox_xxx_unused_4FC4A0(int a1, int a2, int a3) {
	int result; // eax

	result = a3;
	*getMemU32Ptr(0x5D4594, 1568876 + 4 * (a2 + 6 * a1)) = a3;
	return result;
}

//----- (004FC4C0) --------------------------------------------------------
int  nox_xxx_unused_4FC4C0(int a1) {
	char* v1;  // esi
	int v2;    // eax
	int v3;    // ecx
	double v4; // st7
	double v5; // st6

	v1 = nox_common_playerInfoGetFirst_416EA0();
	if (!v1)
		return 0;
	while (1) {
		v2 = *((_DWORD*)v1 + 514);
		if (v2) {
			if (!v1[2251]) {
				if (nox_common_playerIsAbilityActive_4FC250(v2, 2)) {
					v3 = *((_DWORD*)v1 + 514);
					v4 = *(float*)(a1 + 56) - *(float*)(v3 + 56);
					v5 = *(float*)(a1 + 60) - *(float*)(v3 + 60);
					if (sqrt(v5 * v5 + v4 * v4) + 0.1 < 300.0) {
						if (nox_xxx_mapCheck_537110(v3, a1))
							break;
					}
				}
			}
		}
		v1 = nox_common_playerInfoGetNext_416EE0((int)v1);
		if (!v1)
			return 0;
	}
	return 1;
}

//----- (004FC570) --------------------------------------------------------
int  nox_xxx_resetMapInit_4FC570(int a1) {
	int result; // eax

	result = a1;
	dword_5d4594_1569652 = a1;
	return result;
}

//----- (004FC580) --------------------------------------------------------
int  sub_4FC580(int a1) {
	int result; // eax

	result = a1;
	dword_5d4594_1569656 = a1;
	return result;
}

//----- (004FC670) --------------------------------------------------------
int  sub_4FC670(int a1) {
	int result; // eax

	result = a1;
	dword_5d4594_1569660 = a1;
	return result;
}

//----- (004FC960) --------------------------------------------------------
int  sub_4FC960(int a1, char a2) {
	int result; // eax
	int i;      // esi
	int v4;     // eax
	int v5;     // [esp-Ch] [ebp-10h]

	result = nox_xxx_getFirstPlayerUnit_4DA7C0();
	for (i = result; result; i = result) {
		if (i != a1) {
			v5 = *(_DWORD*)(i + 36);
			v4 = nox_xxx_spellGetPhoneme_4FE1C0(*(_DWORD*)(a1 + 36), a2);
			nox_xxx_aud_501960(v4, a1, 2, v5);
		}
		result = nox_xxx_getNextPlayerUnit_4DA7F0(i);
	}
	return result;
}

//----- (004FC9B0) --------------------------------------------------------
int nox_xxx_allocSpellRelatedArrays_4FC9B0() {
	int result; // eax

	result = nox_xxx_spellCreateDurations_4FE850();
	if (result) {
		result = nox_new_alloc_class("magicEntityClass", 60, 64);
		mox_alloc_magicEnt_1569668 = result;
		if (result) {
			result = nox_xxx_objectCreateByName_4E3810("ImaginaryCaster");
			dword_5d4594_1569664 = result;
			if (result) {
				nox_xxx_createAt_4DAA50(result, 0, 2944.0, 2944.0);
				*getMemU32Ptr(0x5D4594, 1569676) = nox_xxx_getNameId_4E3AA0("Pixie");
				*getMemU32Ptr(0x5D4594, 1569680) = nox_xxx_getNameId_4E3AA0("MagicMissile");
				*getMemU32Ptr(0x5D4594, 1569684) = nox_xxx_getNameId_4E3AA0("SmallFist");
				*getMemU32Ptr(0x5D4594, 1569688) = nox_xxx_getNameId_4E3AA0("MediumFist");
				*getMemU32Ptr(0x5D4594, 1569692) = nox_xxx_getNameId_4E3AA0("LargeFist");
				*getMemU32Ptr(0x5D4594, 1569696) = nox_xxx_getNameId_4E3AA0("DeathBall");
				*getMemU32Ptr(0x5D4594, 1569700) = nox_xxx_getNameId_4E3AA0("Meteor");
				result = 1;
			}
		}
	}
	return result;
}

//----- (004FCA80) --------------------------------------------------------
int nox_xxx_freeSpellRelated_4FCA80() {
	sub_4FE880();
	nox_free_alloc_class(*(LPVOID*)&mox_alloc_magicEnt_1569668);
	dword_5d4594_1569672 = 0;
	nox_xxx_delayedDeleteObject_4E5CC0(*(int*)&dword_5d4594_1569664);
	dword_5d4594_1569664 = 0;
	return 1;
}

//----- (004FCAC0) --------------------------------------------------------
int  nox_xxx_Fn_4FCAC0(int a1, int a2) {
	int i;      // eax
	int v3;     // ecx
	_DWORD* v4; // eax

	sub_4FE8A0(a1);
	nox_alloc_class_yyy_4144D0(*(_DWORD**)&mox_alloc_magicEnt_1569668);
	dword_5d4594_1569672 = 0;
	for (i = nox_xxx_getFirstPlayerUnit_4DA7C0(); i; i = nox_xxx_getNextPlayerUnit_4DA7F0(i)) {
		v3 = *(_DWORD*)(i + 748);
		*(_BYTE*)(v3 + 188) = 0;
		*(_DWORD*)(v3 + 216) = 0;
		*(_DWORD*)(v3 + 192) = 0;
		*(_DWORD*)(v3 + 196) = 0;
		*(_DWORD*)(v3 + 200) = 0;
		*(_DWORD*)(v3 + 204) = 0;
		*(_DWORD*)(v3 + 208) = 0;
		*(_BYTE*)(v3 + 212) = 0;
	}
	if (a2) {
		v4 = nox_xxx_objectCreateByName_4E3810("ImaginaryCaster");
		dword_5d4594_1569664 = v4;
		if (!v4)
			return 0;
		nox_xxx_createAt_4DAA50((int)v4, 0, 2944.0, 2944.0);
	}
	return 1;
}

//----- (004FCB80) --------------------------------------------------------
void nox_xxx_spellCastByBook_4FCB80() {
	int v0;              // esi
	int v1;              // eax
	int v2;              // eax
	int v3;              // eax
	int v4;              // edi
	int v5;              // eax
	int v6;              // eax
	int v7;              // ebx
	int v8;              // edx
	int v9;              // ebp
	int v10;             // eax
	_DWORD* v11;         // ebx
	int v12;             // eax
	int v13;             // eax
	_DWORD* v14;         // eax
	_DWORD* v15;         // eax
	int v16;             // eax
	int v17;             // eax
	int v18;             // edi
	char* v19;           // ebx
	unsigned __int8 v20; // bp
	int v21;             // eax
	int v22;             // edx
	char v23[2];         // [esp+6h] [ebp-12h]
	int v24;             // [esp+8h] [ebp-10h]
	int v25;             // [esp+Ch] [ebp-Ch]
	int v26;             // [esp+10h] [ebp-8h]
	int v27;             // [esp+14h] [ebp-4h]

	v0 = dword_5d4594_1569672;
	if (dword_5d4594_1569672) {
		while (1) {
			v1 = *(_DWORD*)(v0 + 4);
			if (*(_DWORD*)(v1 + 16) & 0x8020) {
				v2 = *(_DWORD*)(v0 + 52);
				if (v2)
					*(_DWORD*)(v2 + 56) = *(_DWORD*)(v0 + 56);
				v3 = *(_DWORD*)(v0 + 56);
				if (!v3)
					goto LABEL_39;
				*(_DWORD*)(v3 + 52) = *(_DWORD*)(v0 + 52);
				goto LABEL_40;
			}
			if (*getMemU32Ptr(0x5D4594, 2598000) < *(int*)(v0 + 40))
				goto LABEL_47;
			v4 = 0;
			if (*(_BYTE*)(v1 + 8) & 4)
				v4 = *(_DWORD*)(v1 + 748);
			if (!*(_BYTE*)(v0 + 36)) {
				v23[0] = 112;
				v5 = *(_DWORD*)(v4 + 276);
				v23[1] = *(_BYTE*)(v0 + 4 * *(unsigned __int8*)(v0 + 28) + 8);
				nox_xxx_netAddToMsgListCli_40EBC0(*(unsigned __int8*)(v5 + 2064), 1, v23, 2);
			}
			v6 = *(unsigned __int8*)(v0 + 28);
			v7 = **(_DWORD**)(v0 + 32);
			v24 = *(_DWORD*)(v0 + 4 * v6 + 8);
			v8 = v24;
			if (v7 != v24) {
				v19 = sub_416640();
				LOBYTE(v27) =
					nox_xxx_spellGetPhonemeMB_424A20(*(_DWORD*)(v0 + 4 * *(unsigned __int8*)(v0 + 28) + 8))[*(unsigned __int8*)(v0 + 36)];
				v20 = v27;
				if (!dword_5d4594_2650652 || *(_DWORD*)(v19 + 62))
					sub_4FC960(*(_DWORD*)(v0 + 4), v27);
				v21 = nox_xxx_updateSpellRelated_424830(*(_DWORD*)(v0 + 32), v20);
				v22 = *(_DWORD*)(v0 + 4);
				*(_DWORD*)(v0 + 32) = v21;
				if (*(_BYTE*)(v22 + 8) & 4)
					*(_DWORD*)(v4 + 184) = *(_DWORD*)(v0 + 32);
				++*(_BYTE*)(v0 + 36);
				*(_DWORD*)(v0 + 40) = *getMemU32Ptr(0x5D4594, 2598000) + *(_DWORD*)(v0 + 44);
				goto LABEL_47;
			}
			v26 = *(_DWORD*)(v0 + 4 * v6 + 12);
			if (!*(_BYTE*)(v0 + 29))
				goto LABEL_26;
			if (v24 != 34)
				break;
		LABEL_29:
			v14 = *(_DWORD**)(v0 + 4);
			if (v14[2] & 4) {
				v15 = *(_DWORD**)(v4 + 276);
				*(_DWORD*)(v4 + 220) = v15[571];
				*(_DWORD*)(v4 + 224) = v15[572];
				if (*(_DWORD*)(v0 + 48))
					v15[910] = *(_DWORD*)(v0 + 4);
				else
					v15[910] = *(_DWORD*)(v4 + 288);
				nox_xxx_playerSpell_4FB2A0_magic_plyrspel(*(_DWORD*)(v0 + 4));
				*(_DWORD*)(v4 + 216) = 0;
				*(_BYTE*)(v4 + 188) = 0;
				*(_BYTE*)(v4 + 212) = 0;
			} else {
				nox_xxx_castSpellByUser_4FDD20(v8, v14, 0);
			}
			v16 = *(_DWORD*)(v0 + 52);
			if (v16)
				*(_DWORD*)(v16 + 56) = *(_DWORD*)(v0 + 56);
			v17 = *(_DWORD*)(v0 + 56);
			if (!v17) {
			LABEL_39:
				dword_5d4594_1569672 = *(_DWORD*)(v0 + 52);
				goto LABEL_40;
			}
			*(_DWORD*)(v17 + 52) = *(_DWORD*)(v0 + 52);
		LABEL_40:
			v18 = *(_DWORD*)(v0 + 52);
			nox_alloc_class_free_obj(*(unsigned int**)&mox_alloc_magicEnt_1569668, (_QWORD*)v0);
			v0 = v18;
		LABEL_48:
			if (!v0)
				return;
		}
		if (*(_BYTE*)(*(_DWORD*)(v0 + 4) + 8) & 4) {
			v9 = 0;
			v10 = 1;
			if (!*(_BYTE*)(v4 + 212))
				goto LABEL_51;
			v11 = (_DWORD*)(v4 + 192);
			do {
				if (*v11 == v8) {
					v12 = *(_DWORD*)(v4 + 276);
					v25 = 6;
					nox_xxx_netInformTextMsg_4DA0F0(*(unsigned __int8*)(v12 + 2064), 0, &v25);
					v8 = v24;
					v10 = 0;
				}
				++v9;
				++v11;
			} while (v9 < *(unsigned __int8*)(v4 + 212));
			if (v10) {
			LABEL_51:
				if (sub_4FCF90(*(_DWORD*)(v0 + 4), v8, 2) < 0) {
					v13 = *(_DWORD*)(v4 + 276);
					v25 = 11;
					nox_xxx_netInformTextMsg_4DA0F0(*(unsigned __int8*)(v13 + 2064), 0, &v25);
					nox_xxx_aud_501960(232, *(_DWORD*)(v0 + 4), 0, 0);
				} else {
					*(_DWORD*)(v4 + 4 * (unsigned __int8)(*(_BYTE*)(v4 + 212))++ + 192) = v24;
				}
				v8 = v24;
			}
		}
	LABEL_26:
		if (v8 != 34 && v26) {
			*(_BYTE*)(v0 + 36) = 0;
			*(_DWORD*)(v0 + 32) = nox_xxx_spellGetDefArrayPtr_424820();
			*(_DWORD*)(v0 + 40) = *getMemU32Ptr(0x5D4594, 2598000) + *(_DWORD*)(v0 + 44);
			++*(_BYTE*)(v0 + 28);
		LABEL_47:
			v0 = *(_DWORD*)(v0 + 52);
			goto LABEL_48;
		}
		goto LABEL_29;
	}
}

//----- (004FCEB0) --------------------------------------------------------
int  sub_4FCEB0(int a1) {
	int result; // eax
	int v2;     // esi
	int v3;     // ecx

	result = nox_xxx_spellCastedFirst_4FE930();
	if (result) {
		do {
			v2 = *(_DWORD*)(result + 116);
			if (a1 != 1 || (v3 = *(_DWORD*)(result + 48)) == 0 || (*(_BYTE*)(v3 + 8) & 4) != 4)
				nox_xxx_spellCancelSpellDo_4FE9D0(result);
			result = v2;
		} while (v2);
	}
	return result;
}

//----- (004FCEF0) --------------------------------------------------------
int  nox_xxx_spellCheckSmth_4FCEF0(int a1, int* a2, int a3) {
	int* v3; // ebx
	int v5;  // esi
	int v6;  // edi
	int v7;  // eax
	int v8;  // eax

	if (a1) {
		v3 = a2;
		if (a2) {
			if (a3) {
				if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_6))
					return 1;
				if (*(_BYTE*)(a1 + 8) & 2)
					return 1;
				v5 = (unsigned __int16)nox_xxx_unitGetOldMana_4EEC80(a1);
				v6 = 0;
				if (a3 <= 0)
					return 1;
				while (1) {
					v7 = *v3;
					if ((int)*v3 < 75 || v7 > 114)
						v8 = nox_xxx_getManaCost_4249A0(v7, 2);
					else
						v8 = sub_500CA0(v7, a1);
					if (v8 > v5)
						break;
					v5 -= v8;
					++v6;
					++v3;
					if (v6 >= a3)
						return 1;
				}
			}
		}
	}
	return 0;
}

//----- (004FCF90) --------------------------------------------------------
int  sub_4FCF90(int a1, int a2, int a3) {
	unsigned __int16* v3; // ebp
	int result;           // eax
	int v5;               // eax
	int v6;               // esi

	v3 = *(unsigned __int16**)(a1 + 748);
	if (!(*(_BYTE*)(a1 + 8) & 4))
		return -1;
	if (!a2)
		return -1;
	if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_6))
		return 0;
	if (a2 < 75 || a2 > 114)
		v5 = nox_xxx_getManaCost_4249A0(a2, a3);
	else
		v5 = sub_500CA0(a2, a1);
	v6 = v5;
	if (v3[2] >= v5) {
		nox_xxx_playerManaSub_4EEBF0(a1, v5);
		result = v6;
	} else {
		v3[40] = nox_xxx_getManaCost_4249A0(a2, 1);
		result = -1;
		v3[41] = (_WORD)nox_gameFPS;
	}
	return result;
}

//----- (004FD030) --------------------------------------------------------
unsigned __int16  sub_4FD030(int a1, __int16 a2) {
	unsigned __int16 result; // ax

	result = a1;
	if (*(_BYTE*)(a1 + 8) & 4)
		result = nox_xxx_playerManaAdd_4EEB80(a1, a2);
	return result;
}

//----- (004FD050) --------------------------------------------------------
void  nox_xxx_teleportPixie_4FD050(_DWORD* a1, int a2) {
	a1[16] = *(_DWORD*)(a2 + 56);
	a1[17] = *(_DWORD*)(a2 + 60);
	a1[14] = *(_DWORD*)(a2 + 56);
	a1[15] = *(_DWORD*)(a2 + 60);
	a1[18] = *(_DWORD*)(a2 + 56);
	a1[19] = *(_DWORD*)(a2 + 60);
	nox_xxx_moveUpdateSpecial_517970((int)a1);
}

//----- (004FD090) --------------------------------------------------------
void  sub_4FD090(int a1) {
	int i;  // esi
	int v2; // eax

	for (i = *(_DWORD*)(a1 + 516); i; i = *(_DWORD*)(i + 512)) {
		if (*(unsigned __int16*)(i + 4) == *getMemU32Ptr(0x5D4594, 1569676)) {
			v2 = *(_DWORD*)(i + 16);
			if ((v2 & 0x8000) == 0 && !*(_DWORD*)(*(_DWORD*)(i + 748) + 4))
				nox_xxx_teleportPixie_4FD050((_DWORD*)i, a1);
		}
	}
}

//----- (004FD0E0) --------------------------------------------------------
int  sub_4FD0E0(int a1, int a2) {
	int v2; // ebx
	int v4; // eax

	nox_xxx_spellGetFlags_424A70(a2);
	v2 = nox_xxx_findParentChainPlayer_4EC580(a1);
	if (!nox_xxx_spellIsEnabled_424B70(a2))
		return 10;
	if (*(_BYTE*)(a1 + 8) & 4)
		return nox_xxx_playerCheckSpellClass_57AEA0(*(unsigned __int8*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276) + 2251), a2);
	v4 = -sub_57AEE0(a2, v2);
	LOBYTE(v4) = v4 & 0xF6;
	return v4 + 10;
}

//----- (004FD150) --------------------------------------------------------
int  nox_xxx_checkPlrCantCastSpell_4FD150(int a1, int a2, int a3) {
	int v3;     // eax
	int result; // eax
	int v5;     // eax
	int v6;     // eax
	int v7;     // edi
	double v8;  // st7
	int v9;     // eax
	int v10;    // edx
	int v11;    // [esp-14h] [ebp-20h]
	int v12;    // [esp-14h] [ebp-20h]

	nox_xxx_findParentChainPlayer_4EC580(a1);
	if (a3)
		goto LABEL_9;
	if (nox_common_gameFlags_check_40A5C0(16)) {
		if (!*getMemU32Ptr(0x5D4594, 1569704))
			*getMemU32Ptr(0x5D4594, 1569704) = nox_xxx_getNameId_4E3AA0("Crown");
		if (nox_xxx_spellDefHasFlags_424A50(a2, 0x80000)) {
			v3 = *(_DWORD*)(a1 + 516);
			if (v3) {
				while (*(unsigned __int16*)(v3 + 4) != *getMemU32Ptr(0x5D4594, 1569704)) {
					v3 = *(_DWORD*)(v3 + 512);
					if (!v3)
						goto LABEL_9;
				}
				if (nox_xxx_servObjectHasTeam_419130(a1 + 48))
					return 17;
			}
		}
		goto LABEL_9;
	}
	if (nox_common_gameFlags_check_40A5C0(64)) {
		if (!*getMemU32Ptr(0x5D4594, 1569708))
			*getMemU32Ptr(0x5D4594, 1569708) = nox_xxx_getNameId_4E3AA0("GameBall");
		if (nox_xxx_spellDefHasFlags_424A50(a2, 0x80000)) {
			v5 = *(_DWORD*)(a1 + 516);
			if (v5) {
				while (*(unsigned __int16*)(v5 + 4) != *getMemU32Ptr(0x5D4594, 1569708)) {
					v5 = *(_DWORD*)(v5 + 512);
					if (!v5)
						goto LABEL_9;
				}
				return 16;
			}
		}
	LABEL_9:
		if (nox_xxx_testUnitBuffs_4FF350(a1, 29))
			return 14;
		if (!sub_4D7100(a2))
			return 10;
		switch (a2) {
		case 29:
			if (nox_xxx_unitIsUnitTT_4E7C80(a1, *getMemIntPtr(0x5D4594, 1569692)) > 0)
				return 3;
			if (nox_xxx_unitIsUnitTT_4E7C80(a1, *getMemIntPtr(0x5D4594, 1569688)) <= 0) {
				v10 = *getMemU32Ptr(0x5D4594, 1569684);
				goto LABEL_43;
			}
			return 3;
		case 31:
			v9 = nox_xxx_unitIsUnitTT_4E7C80(a1, *getMemIntPtr(0x5D4594, 1569696));
			goto LABEL_44;
		case 50:
			v7 = nox_xxx_unitIsUnitTT_4E7C80(a1, *getMemIntPtr(0x5D4594, 1569680));
			v12 = nox_xxx_spellGetPower_4FE7B0(a2, a1) - 1;
			v8 = nox_xxx_loadFloatVar_419D70(getMemAt(0x587000, 217620), v12);
			goto LABEL_33;
		case 52:
			v10 = *getMemU32Ptr(0x5D4594, 1569700);
		LABEL_43:
			v9 = nox_xxx_unitIsUnitTT_4E7C80(a1, v10);
		LABEL_44:
			if (v9 <= 0)
				goto LABEL_46;
			return 3;
		case 58:
			v7 = nox_xxx_unitIsUnitTT_4E7C80(a1, *getMemIntPtr(0x5D4594, 1569676));
			v11 = nox_xxx_spellGetPower_4FE7B0(a2, a1) - 1;
			v8 = nox_xxx_loadFloatVar_419D70(getMemAt(0x587000, 217608), v11);
		LABEL_33:
			if (v7 < (int)(__int64)v8)
				goto LABEL_46;
			result = 3;
			break;
		default:
		LABEL_46:
			result = 0;
			break;
		}
		return result;
	}
	if (!nox_common_gameFlags_check_40A5C0(32))
		goto LABEL_9;
	if (!nox_xxx_spellDefHasFlags_424A50(a2, 0x80000))
		goto LABEL_9;
	v6 = *(_DWORD*)(a1 + 504);
	if (!v6)
		goto LABEL_9;
	while (!(*(_DWORD*)(v6 + 8) & 0x10000000)) {
		v6 = *(_DWORD*)(v6 + 496);
		if (!v6)
			goto LABEL_9;
	}
	return 13;
}

//----- (004FD400) --------------------------------------------------------
int  nox_xxx_spellAccept_4FD400(int a1, int a2, _DWORD* a3, int a4, int* a5, int a6) {
	int result;                                      // eax
	int( * v7)(int, int, int, int, int, int); // eax
	double v8;                                       // st7
	int v9;                                          // edi

	if (!a1)
		return 0;
	if (!a3)
		return 0;
	if (!a2)
		return 0;
	if (!a5)
		return 0;
	if (nox_xxx_spellDefHasFlags_424A50(a1, 128) && *a5 && !(*(_BYTE*)(*a5 + 8) & 6))
		return 0;
	if (!*a5 || nox_xxx_gameCaptureMagic_4FDC10(a1, *a5)) {
		switch (a1) {
		case 1:
			v7 = nox_xxx_castAnchor_52C390;
			goto LABEL_95;
		case 2:
			v7 = nox_xxx_spellArachna_52DC80;
			goto LABEL_95;
		case 3:
			v7 = sub_52C750;
			goto LABEL_95;
		case 4:
			return nox_xxx_spellDurationBased_4FEBA0(a1, a2, a3, a4, a5, a6, nox_xxx_spellBlink2_530310, nox_xxx_spellBlink1_530380, 0, 0);
		case 5:
			v7 = nox_xxx_castBurn_52C3E0;
			goto LABEL_95;
		case 6:
			v7 = sub_52BBA0;
			goto LABEL_95;
		case 8:
			return nox_xxx_spellDurationBased_4FEBA0(a1, a2, a3, a4, a5, a6, 0, sub_52F460, 0, 0);
		case 9:
			return nox_xxx_spellDurationBased_4FEBA0(a1, a2, a3, a4, a5, a6, nox_xxx_charmCreature1_5011F0, nox_xxx_charmCreatureFinish_5013E0, nox_xxx_charmCreature2_501690, 0);
		case 10:
		case 11:
			v7 = nox_xxx_spellCastCleansingFlame_52D5C0;
			goto LABEL_95;
		case 12:
			v7 = nox_xxx_castConfuse_52C1E0;
			goto LABEL_95;
		case 13:
			v7 = nox_xxx_castCounterSpell_52BBB0;
			goto LABEL_95;
		case 14:
			v7 = nox_xxx_castCurePoison_52CDB0;
			goto LABEL_95;
		case 15:
			v7 = nox_xxx_castDeath_52C920;
			goto LABEL_95;
		case 16:
			v7 = nox_xxx_castDeathRay_52D1E0;
			goto LABEL_95;
		case 17:
			v7 = sub_52C8D0;
			goto LABEL_95;
		case 18:
			v7 = sub_52BF00;
			goto LABEL_95;
		case 19:
			v7 = sub_537E60;
			goto LABEL_95;
		case 21:
			return nox_xxx_spellDurationBased_4FEBA0(a1, a2, a3, a4, a5, a6, nox_xxx_spellTurnUndeadCreate_531310, nox_xxx_spellTurnUndeadUpdate_531410, nox_xxx_spellTurnUndeadDelete_531420, 70);
		case 22:
			return nox_xxx_spellDurationBased_4FEBA0(a1, a2, a3, a4, a5, a6, 0, nox_xxx_spellDrainMana_52E210, 0, 0);
		case 23:
			v7 = nox_xxx_castEquake_52DE40;
			goto LABEL_95;
		case 24:
			return nox_xxx_spellDurationBased_4FEBA0(a1, a2, a3, a4, a5, a6, nox_xxx_spellEnergyBoltStop_52E820, nox_xxx_spellEnergyBoltTick_52E850, (int)nullsub_29, 30);
		case 26:
			v7 = nox_xxx_castFear_52DF40;
			goto LABEL_95;
		case 27:
			v7 = nox_xxx_castFireball_52C790;
			goto LABEL_95;
		case 28:
			return nox_xxx_spellDurationBased_4FEBA0(a1, a2, a3, a4, a5, a6, 0, nox_xxx_firewalkTick_52ED40, 0, 3 * nox_gameFPS);
		case 29:
			v7 = nox_xxx_castFist_52D3C0;
			goto LABEL_95;
		case 31:
			return nox_xxx_spellDurationBased_4FEBA0(a1, a2, a3, a4, a5, a6, sub_52EF30, sub_52EFD0, sub_52F1D0,
							  2 * nox_gameFPS / 3u);
		case 32:
			v7 = nox_xxx_castFreeze_52C350;
			goto LABEL_95;
		case 33:
			v7 = nox_xxx_castFumble_52C060;
			goto LABEL_95;
		case 34:
			v7 = nox_xxx_castGlyph_537FA0;
			goto LABEL_95;
		case 35:
			return nox_xxx_spellDurationBased_4FEBA0(a1, a2, a3, a4, a5, a6, sub_52F220, sub_52F2E0, 0, 0);
		case 36:
			v7 = nox_xxx_castHaste_52C640;
			goto LABEL_95;
		case 37:
			v7 = nox_xxx_castInfra_52CA30;
			goto LABEL_95;
		case 38:
			v7 = sub_52BEB0;
			goto LABEL_95;
		case 39:
			v7 = nox_xxx_castInvis_52C980;
			goto LABEL_95;
		case 40:
			v7 = nox_xxx_castInvul_52C9E0;
			goto LABEL_95;
		case 41:
			v7 = sub_52DD50;
			goto LABEL_95;
		case 42:
			v7 = nox_xxx_castLight_52C6D0;
			goto LABEL_95;
		case 43:
			return nox_xxx_spellDurationBased_4FEBA0(a1, a2, a3, a4, a5, a6, nox_xxx_onStartLightning_52F820, nox_xxx_onFrameLightning_52F8A0, sub_530100, 30);
		case 44:
			v7 = nox_xxx_castLock_52CE90;
			goto LABEL_95;
		case 45:
			v7 = sub_52CA80;
			goto LABEL_95;
		case 46:
		case 47:
		case 48:
		case 49:
			v7 = sub_52CBD0;
			goto LABEL_95;
		case 50:
			v7 = nox_xxx_castMissilesOM_540160;
			goto LABEL_95;
		case 51:
			return nox_xxx_spellDurationBased_4FEBA0(a1, a2, (_DWORD*)*a5, a4, a5, a6, nox_xxx_castShield1_52F5A0, sub_52F650, sub_52F670, 0);
		case 52:
			v7 = nox_xxx_castMeteor_52D9D0;
			goto LABEL_95;
		case 53:
			v7 = nox_xxx_castMeteorShower_52D8A0;
			goto LABEL_95;
		case 54:
			return nox_xxx_spellDurationBased_4FEBA0(a1, a2, (_DWORD*)*a5, a4, a5, a6, nox_xxx_spellCreateMoonglow_531A00, 0, sub_531AF0, 0);
		case 55:
			v7 = sub_52C230;
			goto LABEL_95;
		case 56:
			return nox_xxx_spellDurationBased_4FEBA0(a1, a2, a3, a4, a5, a6, nox_xxx_manaBomb_530F90, nox_xxx_manaBombBoom_5310C0, sub_531290, 0);
		case 57:
			v7 = sub_52CA70;
			goto LABEL_95;
		case 58:
			v7 = nox_xxx_castPixies_540440;
			goto LABEL_95;
		case 59:
			v8 = nox_xxx_gamedataGetFloat_419D40(getMemAt(0x587000, 217640));
			return nox_xxx_spellDurationBased_4FEBA0(a1, a2, a3, a4, a5, a6, nox_xxx_plasmaSmth_531580, nox_xxx_plasmaShot_531600, sub_5319E0, (__int64)v8);
		case 60:
			v7 = nox_xxx_castPoison_52C720;
			goto LABEL_95;
		case 61:
			v7 = nox_xxx_castProtectElect_52D150;
			goto LABEL_95;
		case 62:
			v7 = nox_xxx_castProtectFire_52D110;
			goto LABEL_95;
		case 63:
			v7 = sub_52D190;
			goto LABEL_95;
		case 64:
			v7 = nox_xxx_castProtectPosion_52D1A0;
			goto LABEL_95;
		case 65:
			v7 = nox_xxx_castPull_52BFA0;
			goto LABEL_95;
		case 66:
			v7 = nox_xxx_castPush_52C000;
			goto LABEL_95;
		case 67:
			return nox_xxx_spellDurationBased_4FEBA0(a1, a2, (_DWORD*)*a5, a4, a5, a6, sub_531490, sub_5314F0, sub_531560, 0);
		case 68:
		case 133:
			v7 = nox_xxx_castSpellWinkORrestoreHealth_52BF20;
			goto LABEL_95;
		case 69:
			v7 = sub_52BF50;
			goto LABEL_95;
		case 70:
			v7 = nox_xxx_castRun_52C680;
			goto LABEL_95;
		case 71:
			v7 = nox_xxx_useShock_52C5A0;
			goto LABEL_95;
		case 72:
			v7 = nox_xxx_castSlow_52C190;
			goto LABEL_95;
		case 74:
			v7 = nox_xxx_castStun_52C2C0;
			goto LABEL_95;
		case 75:
		case 76:
		case 77:
		case 78:
		case 80:
		case 81:
		case 82:
		case 83:
		case 84:
		case 85:
		case 86:
		case 87:
		case 88:
		case 89:
		case 90:
		case 91:
		case 92:
		case 93:
		case 94:
		case 95:
		case 96:
		case 97:
		case 98:
		case 99:
		case 100:
		case 101:
		case 102:
		case 103:
		case 104:
		case 105:
		case 106:
		case 107:
		case 108:
		case 109:
		case 110:
		case 111:
		case 112:
		case 113:
		case 114:
			return nox_xxx_spellDurationBased_4FEBA0(a1, a2, a3, a4, a5, a6, nox_xxx_summonStart_500DA0, nox_xxx_summonFinish_5010D0, nox_xxx_summonCancel_5011C0, 0);
		case 115:
			return nox_xxx_spellDurationBased_4FEBA0(a1, a2, a3, a4, a5, a6, sub_530CA0, sub_530D30, 0, 0);
		case 116:
			return nox_xxx_spellDurationBased_4FEBA0(a1, a2, a3, a4, a5, a6, nox_xxx_spellTagCreature_530160, sub_530250, sub_530270, 0);
		case 117:
		case 118:
		case 119:
		case 120:
		case 122:
		case 123:
		case 124:
		case 125:
			return nox_xxx_spellDurationBased_4FEBA0(a1, a2, a3, a4, a5, a6, sub_5305D0, sub_530650, 0, 0);
		case 121:
			return nox_xxx_spellDurationBased_4FEBA0(a1, a2, a3, a4, a5, a6, nox_xxx_castTele_530820, sub_530880, 0, 0);
		case 126:
			return nox_xxx_spellDurationBased_4FEBA0(a1, a2, a3, a4, a5, a6, sub_530A30_spell_execdur, nox_xxx_castTTT_530B70, 0, 0);
		case 127:
			v7 = nox_xxx_castTelekinesis_52D330;
			goto LABEL_95;
		case 128:
			v7 = nox_xxx_castToxicCloud_52DB60;
			goto LABEL_95;
		case 129:
			v7 = sub_52CCD0;
			goto LABEL_95;
		case 130:
			v7 = nox_xxx_castVamp_52C530;
			goto LABEL_95;
		case 131:
			v7 = sub_52C270;
		LABEL_95:
			v9 = v7(a1, a2, (int)a3, a4, (int)a5, a6);
			if (!v9)
				nox_xxx_aud_501960(231, a4, 0, 0);
			result = v9;
			break;
		case 132:
			result = nox_xxx_spellDurationBased_4FEBA0(a1, a2, a3, a4, a5, a6, nox_xxx_spellWallCreate_4FFA90, nox_xxx_spellWallUpdate_500070, nox_xxx_spellWallDestroy_500080, 0);
			break;
		default:
			result = 1;
			break;
		}
	} else {
		nox_xxx_aud_501960(231, *a5, 0, 0);
		result = 0;
	}
	return result;
}
// 52ED30: using guessed type void nullsub_29();

//----- (004FDC10) --------------------------------------------------------
int  nox_xxx_gameCaptureMagic_4FDC10(int a1, int a2) {
	int v3; // esi
	int v4; // eax
	int v5; // esi

	if (!*getMemU32Ptr(0x5D4594, 1569712)) {
		*getMemU32Ptr(0x5D4594, 1569712) = nox_xxx_getNameId_4E3AA0("GameBall");
		*getMemU32Ptr(0x5D4594, 1569716) = nox_xxx_getNameId_4E3AA0("Crown");
	}
	if (!a2)
		return 0;
	if (nox_xxx_spellDefHasFlags_424A50(a1, 0x80000) && *(_BYTE*)(a2 + 8) & 4) {
		v3 = *(_DWORD*)(a2 + 748);
		if (nox_common_gameFlags_check_40A5C0(32)) {
			if (*(_BYTE*)(*(_DWORD*)(v3 + 276) + 4) & 1)
				return 0;
		} else if (nox_common_gameFlags_check_40A5C0(64)) {
			v4 = *(_DWORD*)(a2 + 516);
			if (v4) {
				while (*(unsigned __int16*)(v4 + 4) != *getMemU32Ptr(0x5D4594, 1569712)) {
					v4 = *(_DWORD*)(v4 + 512);
					if (!v4)
						return 1;
				}
				return 0;
			}
		} else if (nox_common_gameFlags_check_40A5C0(16)) {
			v5 = *(_DWORD*)(a2 + 516);
			if (v5) {
				while (*(unsigned __int16*)(v5 + 4) != *getMemU32Ptr(0x5D4594, 1569716) || !nox_xxx_servObjectHasTeam_419130(a2 + 48)) {
					v5 = *(_DWORD*)(v5 + 512);
					if (!v5)
						return 1;
				}
				return 0;
			}
		}
	}
	return 1;
}

//----- (004FDD20) --------------------------------------------------------
int  nox_xxx_castSpellByUser_4FDD20(int a1, _DWORD* a2, int* a3) {
	int v3; // ebx

	v3 = nox_xxx_spellGetPower_4FE7B0(a1, (int)a2);
	if (nox_xxx_spellDefHasFlags_424A50(a1, 32)) {
		nox_xxx_spellBuffOff_4FF5B0((int)a2, 0);
		nox_xxx_spellBuffOff_4FF5B0((int)a2, 23);
		nox_xxx_spellCancelDurSpell_4FEB10(67, (int)a2);
	}
	if (!nox_xxx_spellDefHasFlags_424A50(a1, 4) || a2 == (_DWORD*)*a3)
		return nox_xxx_spellAccept_4FD400(a1, (int)a2, a2, (int)a2, a3, v3);
	nox_xxx_createSpellFly_4FDDA0((int)a2, *a3, a1);
	return 1;
}

//----- (004FDDA0) --------------------------------------------------------
_DWORD*  nox_xxx_createSpellFly_4FDDA0(int a1, int a2, int a3) {
	int v3;         // esi
	int v4;         // eax
	int v5;         // eax
	int v6;         // eax
	float v7;       // edx
	double v8;      // st7
	double v9;      // st7
	double v10;     // st6
	_DWORD* result; // eax
	_DWORD* v12;    // edi
	int* v13;       // ebx
	__int16 v14;    // ax
	int v15;        // ecx
	__int16 v16;    // ax
	int v17;        // eax
	int v18;        // [esp-10h] [ebp-34h]
	int v19;        // [esp-10h] [ebp-34h]
	char v20;       // [esp-4h] [ebp-28h]
	int2 v21;       // [esp+Ch] [ebp-18h]
	float4 v22;     // [esp+14h] [ebp-10h]
	float a2a;      // [esp+28h] [ebp+4h]

	v3 = a1;
	a2a = *(float*)(a1 + 176) + 4.0;
	if (!a2) {
		if (*(_BYTE*)(v3 + 8) & 4) {
			v4 = *(_DWORD*)(v3 + 748);
			*(float*)&v21.field_0 = (double)*(int*)(*(_DWORD*)(v4 + 276) + 2284);
			*(float*)&v21.field_4 = (double)*(int*)(*(_DWORD*)(v4 + 276) + 2288);
			v18 = nox_xxx_spellGetFlags_424A70(a3);
			v5 = nox_xxx_spellFlySearchTarget_540610((float2*)&v21, v3, v18, 600.0, 0, v3);
		} else {
			v19 = nox_xxx_spellGetFlags_424A70(a3);
			v5 = nox_xxx_spellFlySearchTarget_540610(0, v3, v19, 600.0, 0, v3);
		}
		a2 = v5;
	}
	v6 = 8 * *(__int16*)(v3 + 124);
	v7 = *(float*)(v3 + 60);
	v8 = a2a * *getMemFloatPtr(0x587000, v6 + 194136);
	v22.field_0 = *(float*)(v3 + 56);
	v9 = v8 + *(float*)(v3 + 56);
	v10 = a2a * *getMemFloatPtr(0x587000, v6 + 194140);
	v22.field_4 = v7;
	v22.field_C = v10 + *(float*)(v3 + 60);
	v22.field_8 = v9 + *(float*)(v3 + 80);
	v22.field_C = v22.field_C + *(float*)(v3 + 84);
	result = (_DWORD*)nox_xxx_mapTraceRay_535250(&v22, 0, 0, 5);
	if (result) {
		result = nox_xxx_objectCreateByName_4E3810("Magic");
		v12 = result;
		if (result) {
			v13 = (int*)result[187];
			v13[4] = nox_xxx_spellGetPower_4FE7B0(a3, v3);
			nox_xxx_createAt_4DAA50((int)v12, v3, v22.field_8, v22.field_C);
			v14 = *(_WORD*)(v3 + 124);
			*((_WORD*)v12 + 62) = v14;
			*((_WORD*)v12 + 63) = v14;
			*v13 = v3;
			v13[1] = a2;
			v13[2] = v3;
			v13[3] = a3;
			nox_xxx_xferIndexedDirection_509E20(*(__int16*)(v3 + 124), &v21);
			v15 = *((__int16*)v12 + 62);
			*((float*)v12 + 20) = *getMemFloatPtr(0x587000, 8 * v15 + 194136) * *((float*)v12 + 136);
			*((float*)v12 + 21) = *getMemFloatPtr(0x587000, 8 * v15 + 194140) * *((float*)v12 + 136);
			*((float*)v12 + 20) = *((float*)v12 + 20) + *(float*)(v3 + 80);
			*((float*)v12 + 21) = *((float*)v12 + 21) + *(float*)(v3 + 84);
			if (nox_xxx_testUnitBuffs_4FF350(v3, 21)) {
				v20 = nox_xxx_buffGetPower_4FF570(v3, 21);
				v16 = nox_xxx_unitGetBuffTimer_4FF550(v3, 21);
				nox_xxx_buffApplyTo_4FF380((int)v12, 21, v16, v20);
			}
			v17 = nox_xxx_spellGetAud44_424800(a3, 0);
			result = nox_xxx_aud_501960(v17, v3, 0, 0);
		}
	}
	return result;
}

//----- (004FDF90) --------------------------------------------------------
void  nox_xxx_collide_4FDF90(int a1, int a2) {
	int v2;     // edi
	int v3;     // eax
	int result; // eax
	float v5;   // [esp+0h] [ebp-10h]

	if (nox_xxx_testUnitBuffs_4FF350(a1, 22) && !(*(_DWORD*)(a2 + 16) & 0x8008) && *(_BYTE*)(a2 + 8) & 6 && nox_xxx_unitIsEnemyTo_5330C0(a1, a2)) {
		v2 = *(unsigned __int8*)(a1 + 430) - 1;
		nox_xxx_aud_501960(135, a1, 0, 0);
		nox_xxx_spellBuffOff_4FF5B0(a1, 22);
		v5 = nox_xxx_loadFloatVar_419D70(getMemAt(0x587000, 217688), v2);
		v3 = nox_float2int(v5);
		(*(void(**)(int, int, int, int, int))(a2 + 716))(a2, a1, a1, v3, 9);
	}
	result = *(_DWORD*)(a2 + 8);
	if (result & 0x20006) {
		if (!(*(_DWORD*)(a2 + 16) & 0x8020)) {
			if (!nox_xxx_unitsHaveSameTeam_4EC520(a2, a1))
				nox_xxx_spellBuffOff_4FF5B0(a1, 0);
		}
	}
	if (*(_BYTE*)(a1 + 8) & 4 && *(_DWORD*)(a2 + 8) & 0x20000 && !(*(_DWORD*)(a2 + 16) & 0x8020))
		nox_xxx_spellBuffOff_4FF5B0(a1, 0);
}

//----- (004FE060) --------------------------------------------------------
int  nox_xxx_unused_4FE060(int a1, int a2) {
	int v2;      // ebx
	int v3;      // esi
	int* v4;     // edi
	int v5;      // eax
	int result;  // eax
	int v7[137]; // [esp+8h] [ebp-224h]

	v2 = 0;
	v3 = nox_xxx_bookFirstKnownSpell_424AD0();
	if (!v3)
		goto LABEL_14;
	v4 = v7;
	do {
		if (!sub_4FE100(v3)) {
			v5 = nox_xxx_spellGetFlags_424A70(v3);
			if (v5 & a1 || v5 & 0x1000000) {
				if (v5 & a2) {
					*v4 = v3;
					++v2;
					++v4;
				}
			}
		}
		v3 = nox_xxx_bookNextEnabledSpell_424AF0(v3);
	} while (v3);
	if (v2)
		result = v7[nox_common_randomInt_415FA0(0, v2 - 1)];
	else
	LABEL_14:
		result = 0;
	return result;
}
// 4FE060: using guessed type int var_224[137];

//----- (004FE100) --------------------------------------------------------
int  sub_4FE100(int a1) {
	int result; // eax

	switch (a1) {
	case 1:
	case 2:
	case 6:
	case 13:
	case 15:
	case 18:
	case 19:
	case 20:
	case 30:
	case 32:
	case 33:
	case 34:
	case 38:
	case 51:
	case 57:
	case 68:
	case 69:
	case 70:
	case 73:
	case 129:
	case 133:
		result = 1;
		break;
	default:
		result = 0;
		break;
	}
	return result;
}

//----- (004FE1C0) --------------------------------------------------------
int  nox_xxx_spellGetPhoneme_4FE1C0(int a1, char a2) {
	char* v2;   // eax
	int result; // eax

	if (nox_common_gameFlags_check_40A5C0(1)) {
		if (*(_BYTE*)(nox_server_getObjectFromNetCode_4ECCB0(a1) + 8) & 4) {
		LABEL_5:
			v2 = nox_common_playerInfoGetByID_417040(a1);
			if (!v2)
				return 0;
			if (!v2[2252]) {
				switch (a2) {
				case 0:
					goto LABEL_25;
				case 1:
					goto LABEL_18;
				case 2:
					goto LABEL_19;
				case 3:
					goto LABEL_24;
				case 5:
					goto LABEL_20;
				case 6:
					goto LABEL_23;
				case 7:
					goto LABEL_22;
				case 8:
					goto LABEL_21;
				default:
					return 0;
				}
			}
			switch (a2) {
			case 0:
				result = 201;
				break;
			case 1:
				result = 194;
				break;
			case 2:
				result = 195;
				break;
			case 3:
				result = 200;
				break;
			case 5:
				result = 196;
				break;
			case 6:
				result = 199;
				break;
			case 7:
				result = 198;
				break;
			case 8:
				result = 197;
				break;
			default:
				return 0;
			}
			return result;
		}
	} else if (nox_xxx_netSpriteByCodeDynamic_45A6F0(a1)[28] & 4) {
		goto LABEL_5;
	}
	switch (a2) {
	case 0:
	LABEL_25:
		result = 193;
		break;
	case 1:
	LABEL_18:
		result = 186;
		break;
	case 2:
	LABEL_19:
		result = 187;
		break;
	case 3:
	LABEL_24:
		result = 192;
		break;
	case 5:
	LABEL_20:
		result = 188;
		break;
	case 6:
	LABEL_23:
		result = 191;
		break;
	case 7:
	LABEL_22:
		result = 190;
		break;
	case 8:
	LABEL_21:
		result = 189;
		break;
	default:
		return 0;
	}
	return result;
}

//----- (004FE340) --------------------------------------------------------
int  nox_xxx_spellByBookInsert_4FE340(int a1, int* a2, int a3, int a4, int a5) {
	_DWORD* v5;  // edi
	int* v6;     // ebp
	int v7;      // edx
	int* v8;     // ecx
	int v9;      // ebx
	int v10;     // edx
	int* v11;    // ecx
	int* v12;    // eax
	int v13;     // ecx
	BYTE v15;    // eax
	int v16;     // esi
	int* v17;    // esi
	int v18;     // ebp
	int v19;     // ecx
	_DWORD* v20; // esi
	int v21;     // eax
	int v22;     // edx
	int v23;     // eax
	int* v24;    // ecx
	int* v25;    // edx
	int v26;     // [esp+10h] [ebp-4h]

	v5 = (_DWORD*)a1;
	if (*(_DWORD*)(a1 + 16) & 0x8022)
		return 0;
	v6 = a2;
	v7 = 0;
	v8 = a2;
	do {
		if ((int)*v8 < 0 || (int)*v8 >= 137)
			return 0;
		++v7;
		++v8;
	} while (v7 < 5);
	if (!(*(_BYTE*)(a1 + 8) & 4))
		return 0;
	v9 = *(_DWORD*)(a1 + 748);
	if (*(_DWORD*)(v9 + 280))
		return 0;
	v10 = 0;
	v11 = a2;
	do {
		if (!*(_DWORD*)(*(_DWORD*)(v9 + 276) + 4 * *v11 + 3696) && *v11)
			return 0;
		++v10;
		++v11;
	} while (v10 < 5);
	if (*(_DWORD*)(v9 + 216))
		return 0;
	v26 = 0;
	if (a3 > 0) {
		v12 = a2;
		v13 = a3;
		do {
			if (*v12 == 34)
				v26 = 1;
			++v12;
			--v13;
		} while (v13);
		if (v26) {
			if (!nox_xxx_spellCheckSmth_4FCEF0(a1, a2, a3)) {
				a1 = 12;
				nox_xxx_netInformTextMsg_4DA0F0(*(unsigned __int8*)(*(_DWORD*)(v9 + 276) + 2064), 0, &a1);
				nox_xxx_aud_501960(232, (int)v5, 0, 0);
				return 0;
			}
			if (*(_BYTE*)(*(_DWORD*)(v9 + 276) + 2251) == 2) {
				v15 = nox_xxx_checkSummonedCreaturesLimit_500D70((int)v5, 5);
				if (!v15) {
					a1 = 4;
				LABEL_44:
					nox_xxx_netInformTextMsg_4DA0F0(*(unsigned __int8*)(*(_DWORD*)(v9 + 276) + 2064), 0, &a1);
					goto LABEL_29;
				}
				v16 = nox_xxx_unitCountSlaves_4E7CF0((int)v5, 2, 0x2000);
				if (v16 >= (int)(__int64)nox_xxx_gamedataGetFloat_419D40(getMemAt(0x587000, 217736))) {
					a1 = 5;
					goto LABEL_44;
				}
			} else if (*(unsigned __int8*)(v9 + 244) >= (int)(__int64)nox_xxx_gamedataGetFloat_419D40(getMemAt(0x587000, 217752))) {
				a1 = 5;
			LABEL_28:
				nox_xxx_netInformTextMsg_4DA0F0(*(unsigned __int8*)(*(_DWORD*)(v9 + 276) + 2064), 0, &a1);
			LABEL_29:
				nox_xxx_aud_501960(231, (int)v5, 0, 0);
				return 0;
			}
			v17 = a2;
			v18 = 0;
			while (1) {
				a1 = sub_4FD0E0((int)v5, *v17);
				if (a1)
					goto LABEL_28;
				a1 = nox_xxx_checkPlrCantCastSpell_4FD150((int)v5, *v17, v26);
				if (a1)
					goto LABEL_28;
				++v18;
				++v17;
				if (v18 >= a3) {
					v6 = a2;
					goto LABEL_36;
				}
			}
		}
	}
	a1 = sub_4FD0E0(a1, *a2);
	if (a1) {
		nox_xxx_netInformTextMsg_4DA0F0(*(unsigned __int8*)(*(_DWORD*)(v9 + 276) + 2064), 0, &a1);
		goto LABEL_29;
	}
	a1 = nox_xxx_checkPlrCantCastSpell_4FD150((int)v5, *v6, 0);
	if (a1)
		goto LABEL_44;
LABEL_36:
	nox_xxx_playerSetState_4FA020(v5, 2);
	v19 = *getMemU32Ptr(0x5D4594, 2598000);
	*(_BYTE*)(v9 + 188) = 1;
	*(_DWORD*)(v9 + 216) = v19;
	v20 = nox_alloc_class_new_obj_zero(*(_DWORD**)&mox_alloc_magicEnt_1569668);
	if (!v20)
		return 0;
	v21 = a5;
	v22 = a4;
	v20[1] = v5;
	v20[12] = v21;
	*((_BYTE*)v20 + 36) = 0;
	v20[10] = *getMemU32Ptr(0x5D4594, 2598000);
	v20[11] = v22;
	v20[8] = nox_xxx_spellGetDefArrayPtr_424820();
	*((_BYTE*)v20 + 28) = 0;
	*((_BYTE*)v20 + 29) = 0;
	v23 = 0;
	v24 = v6;
	v25 = v20 + 2;
	do {
		if (v23 >= a3) {
			*v25 = 0;
		} else {
			*v25 = *v24;
			if (*v24 == 34)
				*((_BYTE*)v20 + 29) = 1;
		}
		++v23;
		++v24;
		++v25;
	} while (v23 < 5);
	v20[14] = 0;
	v20[13] = dword_5d4594_1569672;
	if (dword_5d4594_1569672)
		*(_DWORD*)(dword_5d4594_1569672 + 56) = v20;
	dword_5d4594_1569672 = v20;
	return 1;
}
// 4FE46E: variable 'v15' is possibly undefined

//----- (004FE680) --------------------------------------------------------
void  nox_xxx_spell_4FE680(int a1, float a2) {
	int v2;    // esi
	int v3;    // ebp
	int v4;    // eax
	int v5;    // ecx
	double v6; // st7
	double v7; // st6
	int v8;    // eax
	int v9;    // eax
	int v10;   // eax
	int v11;   // eax
	int v12;   // edi

	v2 = dword_5d4594_1569672;
	if (dword_5d4594_1569672) {
		v3 = a1;
		do {
			v4 = *(_DWORD*)(v2 + 4);
			if (((*(_BYTE*)(v4 + 8) & 4) != 4 || !nox_xxx_servCompareTeams_419150(v3 + 48, v4 + 48)) &&
				(v5 = *(_DWORD*)(v2 + 4), v6 = *(float*)(v5 + 56) - *(float*)(v3 + 56),
				 v7 = *(float*)(v5 + 60) - *(float*)(v3 + 60), sqrt(v7 * v7 + v6 * v6) + 0.1 < a2) &&
				nox_xxx_mapCheck_537110(v3, *(_DWORD*)(v2 + 4))) {
				v8 = *(_DWORD*)(v2 + 4);
				if ((*(_BYTE*)(v8 + 8) & 4) == 4) {
					v9 = *(_DWORD*)(v8 + 748);
					*(_DWORD*)(v9 + 216) = 0;
					*(_BYTE*)(v9 + 188) = 0;
					a1 = 15;
					nox_xxx_netInformTextMsg_4DA0F0(*(unsigned __int8*)(*(_DWORD*)(v9 + 276) + 2064), 0, &a1);
					nox_xxx_aud_501960(231, *(_DWORD*)(v2 + 4), 0, 0);
					nox_xxx_playerSetState_4FA020(*(_DWORD**)(v2 + 4), 13);
				}
				v10 = *(_DWORD*)(v2 + 52);
				if (v10)
					*(_DWORD*)(v10 + 56) = *(_DWORD*)(v2 + 56);
				v11 = *(_DWORD*)(v2 + 56);
				if (v11)
					*(_DWORD*)(v11 + 52) = *(_DWORD*)(v2 + 52);
				else
					dword_5d4594_1569672 = *(_DWORD*)(v2 + 52);
				v12 = *(_DWORD*)(v2 + 52);
				nox_alloc_class_free_obj(*(unsigned int**)&mox_alloc_magicEnt_1569668, (_QWORD*)v2);
				v2 = v12;
			} else {
				v2 = *(_DWORD*)(v2 + 52);
			}
		} while (v2);
	}
}

//----- (004FE7B0) --------------------------------------------------------
int  nox_xxx_spellGetPower_4FE7B0(int a1, int a2) {
	int v2;     // eax
	int result; // eax
	int v4;     // eax

	v2 = *getMemU32Ptr(0x5D4594, 1569720);
	if (!*getMemU32Ptr(0x5D4594, 1569720)) {
		v2 = nox_xxx_getNameId_4E3AA0("ImaginaryCaster");
		*getMemU32Ptr(0x5D4594, 1569720) = v2;
	}
	if (*(unsigned __int16*)(a2 + 4) == v2)
		return 1;
	if (nox_common_gameFlags_check_40A5C0(1392))
		goto LABEL_15;
	if (!a2)
		return 2;
	v4 = *(_DWORD*)(a2 + 8);
	if (v4 & 4)
		return *(_DWORD*)(*(_DWORD*)(*(_DWORD*)(a2 + 748) + 276) + 4 * a1 + 3696);
	if (!(v4 & 2))
	LABEL_15:
		result = 3;
	else
		result = *(_DWORD*)(*(_DWORD*)(a2 + 748) + 2040);
	return result;
}

//----- (004FE850) --------------------------------------------------------
BOOL nox_xxx_spellCreateDurations_4FE850() {
	nox_alloc_spellDur_1569724 = nox_new_alloc_class("spellDuration", 120, 512);
	return nox_alloc_spellDur_1569724 != 0;
}

//----- (004FE880) --------------------------------------------------------
void sub_4FE880() {
	nox_free_alloc_class(*(LPVOID*)&nox_alloc_spellDur_1569724);
	dword_5d4594_1569728 = 0;
}

//----- (004FE8A0) --------------------------------------------------------
void  sub_4FE8A0(int a1) {
	int v1; // esi
	int v2; // eax
	int v3; // edi

	if (a1) {
		v1 = dword_5d4594_1569728;
		if (dword_5d4594_1569728) {
			do {
				v2 = *(_DWORD*)(v1 + 48);
				v3 = *(_DWORD*)(v1 + 116);
				if (!v2 || !(*(_BYTE*)(v2 + 8) & 4)) {
					sub_4FE900(v1);
					sub_4FE980(v1);
				}
				v1 = v3;
			} while (v3);
		}
	} else {
		nox_alloc_class_yyy_4144D0(*(_DWORD**)&nox_alloc_spellDur_1569724);
		dword_5d4594_1569728 = 0;
	}
}

//----- (004FE900) --------------------------------------------------------
int  sub_4FE900(int a1) {
	int result; // eax
	int v2;     // ecx
	int v3;     // ecx

	result = a1;
	v2 = *(_DWORD*)(a1 + 112);
	if (v2)
		*(_DWORD*)(v2 + 116) = *(_DWORD*)(a1 + 116);
	else
		dword_5d4594_1569728 = *(_DWORD*)(a1 + 116);
	v3 = *(_DWORD*)(a1 + 116);
	if (v3)
		*(_DWORD*)(v3 + 112) = *(_DWORD*)(a1 + 112);
	return result;
}

//----- (004FE930) --------------------------------------------------------
int nox_xxx_spellCastedFirst_4FE930() { return dword_5d4594_1569728; }

//----- (004FE940) --------------------------------------------------------
int  nox_xxx_spellCastedNext_4FE940(int a1) { return *(_DWORD*)(a1 + 116); }

//----- (004FE950) --------------------------------------------------------
_WORD* nox_xxx_spellDurationAdd_4FE950() {
	_WORD* result; // eax

	result = nox_alloc_class_new_obj_zero(*(_DWORD**)&nox_alloc_spellDur_1569724);
	if (result)
		*result = ++*getMemU16Ptr(0x5D4594, 1569732);
	return result;
}

//----- (004FE980) --------------------------------------------------------
void  sub_4FE980(int a1) {
	int v1; // eax
	int v2; // esi
	int v3; // eax
	int v4; // esi

	v1 = *(_DWORD*)(a1 + 108);
	if (v1) {
		do {
			v2 = *(_DWORD*)(v1 + 116);
			sub_4FE980(v1);
			v1 = v2;
		} while (v2);
	}
	v3 = *(_DWORD*)(a1 + 104);
	if (v3) {
		do {
			v4 = *(_DWORD*)(v3 + 116);
			sub_4FE980(v3);
			v3 = v4;
		} while (v4);
	}
	nox_alloc_class_free_obj(*(unsigned int**)&nox_alloc_spellDur_1569724, (_QWORD*)a1);
}

//----- (004FE9D0) --------------------------------------------------------
char  nox_xxx_spellCancelSpellDo_4FE9D0(int a1) {
	int v1;      // eax
	int v2;      // ecx
	int v3;      // eax
	char result; // al
	int i;       // esi

	v1 = *(_DWORD*)(a1 + 16);
	if (v1 && *(_BYTE*)(v1 + 8) & 4) {
		v2 = *(_DWORD*)(a1 + 4);
		v3 = *(_DWORD*)(v1 + 748);
		if (v2 == 43)
			nox_xxx_netReportSpellStat_4D9630(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), 43, 0);
		else
			nox_xxx_netReportSpellStat_4D9630(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), v2, 15);
	}
	if (*(_DWORD*)(a1 + 4) == 43) {
		for (i = *(_DWORD*)(a1 + 108); i; i = *(_DWORD*)(i + 116)) {
			if (*(_DWORD*)(i + 48))
				nox_xxx_netStopRaySpell_4FEF90(i, *(_DWORD**)(i + 48));
		}
	} else if (*(_DWORD*)(a1 + 48)) {
		nox_xxx_netStopRaySpell_4FEF90(a1, *(_DWORD**)(a1 + 48));
		result = *(_BYTE*)(a1 + 88) | 1;
		*(_BYTE*)(a1 + 88) = result;
		return result;
	}
	result = *(_BYTE*)(a1 + 88) | 1;
	*(_BYTE*)(a1 + 88) = result;
	return result;
}

//----- (004FEA70) --------------------------------------------------------
BOOL  sub_4FEA70(int a1, float2* a2) {
	double v2; // st7
	double v3; // st7
	float v5;  // [esp+0h] [ebp-8h]

	v2 = a2->field_0 - *(float*)(a1 + 56);
	if (v2 < 0.0)
		v2 = -v2;
	v5 = v2;
	v3 = a2->field_4 - *(float*)(a1 + 60);
	if (v3 < 0.0)
		v3 = -v3;
	return v5 >= 5.0 || v3 >= 5.0;
}

//----- (004FEAE0) --------------------------------------------------------
int  nox_xxx_playerCancelSpells_4FEAE0(int a1) {
	int result; // eax
	int v2;     // esi

	result = nox_xxx_spellCastedFirst_4FE930();
	if (result) {
		do {
			v2 = *(_DWORD*)(result + 116);
			if (*(_DWORD*)(result + 16) == a1)
				nox_xxx_spellCancelSpellDo_4FE9D0(result);
			result = v2;
		} while (v2);
	}
	return result;
}

//----- (004FEB10) --------------------------------------------------------
_DWORD*  nox_xxx_spellCancelDurSpell_4FEB10(int a1, int a2) {
	_DWORD* result; // eax
	int v3;         // ecx
	_DWORD* v4;     // esi

	result = *(_DWORD**)&dword_5d4594_1569728;
	if (dword_5d4594_1569728) {
		do {
			v3 = result[1];
			v4 = (_DWORD*)result[29];
			if (v3 == a1 && result[4] == a2 || a1 >= 75 && a1 <= 114 && v3 >= 75 && v3 <= 114 && result[4] == a2)
				nox_xxx_spellCancelSpellDo_4FE9D0((int)result);
			result = v4;
		} while (v4);
	}
	return result;
}

//----- (004FEB60) --------------------------------------------------------
unsigned int  sub_4FEB60(int a1, int a2) {
	unsigned int result; // eax

	result = *(_DWORD*)(a2 + 8);
	if (result & 0x1000) {
		result = *(_DWORD*)(a2 + 12);
		if (result & 0x40000)
			result = (unsigned int)nox_xxx_spellCancelDurSpell_4FEB10(43, a1);
		if (*(_DWORD*)(a2 + 12) & 0x4000000)
			result = (unsigned int)nox_xxx_spellCancelDurSpell_4FEB10(59, a1);
	}
	return result;
}

//----- (004FEBA0) --------------------------------------------------------
int  nox_xxx_spellDurationBased_4FEBA0(int a1, int a2, _DWORD* a3, int a4, _DWORD* a5, int a6, int(* a7)(_WORD*), int a8, int a9,
					   int a10) {
	int v10;    // eax
	_WORD* v12; // esi
	int v13;    // edx
	int v14;    // ecx
	int v15;    // ecx
	BOOL v16;   // eax
	int v17;    // eax

	v10 = dword_5d4594_1569736;
	if (!dword_5d4594_1569736) {
		v10 = nox_xxx_getNameId_4E3AA0("Glyph");
		dword_5d4594_1569736 = v10;
	}
	if (a3 && !(a3[4] & 0x8020) || !a4 || *(unsigned __int16*)(a4 + 4) == v10) {
		if (a3) {
			if ((a1 == 59 || a1 == 43) && sub_4FEE50(a1, (int)a3) == 1)
				return 1;
			nox_xxx_spellCancelDurSpell_4FEB10(a1, (int)a3);
		}
		sub_4FED70();
		v12 = nox_xxx_spellDurationAdd_4FE950();
		if (v12) {
			*((_DWORD*)v12 + 1) = a1;
			*((_DWORD*)v12 + 2) = a6;
			*((_DWORD*)v12 + 4) = a3;
			*((_DWORD*)v12 + 3) = a2;
			*((_DWORD*)v12 + 27) = 0;
			*((_DWORD*)v12 + 26) = 0;
			if (a4 && *(unsigned __int16*)(a4 + 4) == dword_5d4594_1569736) {
				*((_DWORD*)v12 + 5) = 1;
				*((_DWORD*)v12 + 6) = a4;
				*((_DWORD*)v12 + 7) = *(_DWORD*)(a4 + 56);
				v13 = *(_DWORD*)(a4 + 60);
			} else {
				*((_DWORD*)v12 + 5) = 0;
				*((_DWORD*)v12 + 6) = 0;
				*((_DWORD*)v12 + 7) = a3[14];
				v13 = a3[15];
			}
			*((_DWORD*)v12 + 9) = 0;
			*((_DWORD*)v12 + 8) = v13;
			*((_DWORD*)v12 + 12) = *a5;
			*((_DWORD*)v12 + 13) = a5[1];
			v14 = a5[2];
			*((_DWORD*)v12 + 23) = a7;
			*((_DWORD*)v12 + 14) = v14;
			*((_DWORD*)v12 + 24) = a8;
			*((_DWORD*)v12 + 25) = a9;
			*((_DWORD*)v12 + 15) = *getMemU32Ptr(0x5D4594, 2598000);
			*((_DWORD*)v12 + 16) = *getMemU32Ptr(0x5D4594, 2598000);
			v15 = a10 + *getMemU32Ptr(0x5D4594, 2598000);
			*((_BYTE*)v12 + 88) = 0;
			*((_DWORD*)v12 + 17) = v15;
			sub_4FED40((int)v12);
			v16 = nox_xxx_spellDefHasFlags_424A50(a1, 4);
			v17 = nox_xxx_spellGetAud44_424800(a1, v16);
			nox_xxx_aud_501960(v17, (int)a3, 0, 0);
			if (!a7 || !a7(v12))
				return 1;
			nox_xxx_spellCancelSpellDo_4FE9D0((int)v12);
		}
	}
	return 0;
}

//----- (004FED40) --------------------------------------------------------
int  sub_4FED40(int a1) {
	int result; // eax

	result = a1;
	if (dword_5d4594_1569728)
		*(_DWORD*)(dword_5d4594_1569728 + 112) = a1;
	*(_DWORD*)(a1 + 112) = 0;
	*(_DWORD*)(a1 + 116) = dword_5d4594_1569728;
	dword_5d4594_1569728 = a1;
	return result;
}

//----- (004FED70) --------------------------------------------------------
int sub_4FED70() {
	int result; // eax
	int v1;     // esi

	result = dword_5d4594_1569728;
	if (dword_5d4594_1569728) {
		do {
			v1 = *(_DWORD*)(result + 116);
			if (*(_BYTE*)(result + 88) & 1)
				nox_xxx_plrCastSmth_4FEDA0((int*)result);
			result = v1;
		} while (v1);
	}
	return result;
}

//----- (004FEDA0) --------------------------------------------------------
void  nox_xxx_plrCastSmth_4FEDA0(int* a1) {
	int v1;                   // eax
	void( * v2)(int*); // eax
	int v3;                   // eax
	int v4;                   // ecx
	int v5;                   // [esp-Ch] [ebp-10h]

	if (a1[4]) {
		v5 = a1[4];
		v1 = nox_xxx_spellGetAud44_424800(a1[1], 2);
		nox_xxx_aud_501960(v1, v5, 0, 0);
	}
	v2 = (void(*)(int*))a1[25];
	if (v2)
		v2(a1);
	v3 = a1[4];
	if (v3) {
		v4 = *(_DWORD*)(v3 + 8);
		if (v4 & 4) {
			if (*(_BYTE*)(*(_DWORD*)(*(_DWORD*)(v3 + 748) + 276) + 2251) ||
				!nox_common_playerIsAbilityActive_4FC250(v3, 1)) {
				nox_xxx_playerSetState_4FA020((_DWORD*)a1[4], 13);
				sub_4FE900((int)a1);
				sub_4FE980((int)a1);
				return;
			}
		} else if (v4 & 2) {
			sub_541630(v3, a1[1]);
		}
	}
	sub_4FE900((int)a1);
	sub_4FE980((int)a1);
}

//----- (004FEE50) --------------------------------------------------------
int  sub_4FEE50(int a1, int a2) {
	int v2;     // ecx
	int result; // eax

	v2 = dword_5d4594_1569728;
	if (!dword_5d4594_1569728)
		return 0;
	result = 1;
	while (*(_DWORD*)(v2 + 20) || *(_DWORD*)(v2 + 4) != a1 || *(_DWORD*)(v2 + 16) != a2 || *(_BYTE*)(v2 + 88) & 1) {
		v2 = *(_DWORD*)(v2 + 116);
		if (!v2)
			return 0;
	}
	return result;
}

//----- (004FEE90) --------------------------------------------------------
char  nox_xxx_cancelAllSpells_4FEE90(int a1) {
	int v1; // eax
	int v2; // esi
	int v3; // edi

	v1 = nox_xxx_spellCastedFirst_4FE930();
	v2 = v1;
	if (v1) {
		do {
			v3 = nox_xxx_spellCastedNext_4FE940(v2);
			v1 = *(_DWORD*)(v2 + 16);
			if (v1 == a1) {
				v1 = *(_DWORD*)(v2 + 4);
				if (v1 == 24 || v1 == 43 || v1 == 35 || v1 == 8 || v1 == 22 || v1 == 59 || v1 == 67)
					LOBYTE(v1) = nox_xxx_spellCancelSpellDo_4FE9D0(v2);
			}
			v2 = v3;
		} while (v3);
	}
	return v1;
}

//----- (004FEEF0) --------------------------------------------------------
void nox_xxx_clientMB_4FEEF0() {
	int v0;                 // esi
	int v1;                 // ebp
	int v2;                 // eax
	int v3;                 // eax
	int v4;                 // eax
	unsigned int v5;        // eax
	int( * v6)(int); // eax

	v0 = dword_5d4594_1569728;
	if (dword_5d4594_1569728) {
		do {
			v1 = *(_DWORD*)(v0 + 116);
			if (*(_BYTE*)(v0 + 88) & 1) {
				nox_xxx_plrCastSmth_4FEDA0((int*)v0);
			} else {
				v2 = *(_DWORD*)(v0 + 16);
				if (v2 && *(_DWORD*)(v2 + 16) & 0x8020)
					*(_DWORD*)(v0 + 16) = 0;
				v3 = *(_DWORD*)(v0 + 12);
				if (v3 && *(_BYTE*)(v3 + 16) & 0x20)
					*(_DWORD*)(v0 + 12) = 0;
				if (!*(_DWORD*)(v0 + 16) && !*(_DWORD*)(v0 + 20))
					goto LABEL_23;
				v4 = *(_DWORD*)(v0 + 24);
				if (v4 && *(_BYTE*)(v4 + 16) & 0x20)
					*(_DWORD*)(v0 + 24) = 0;
				v5 = *(_DWORD*)(v0 + 68);
				if (v5 != *(_DWORD*)(v0 + 60) && v5 <= *getMemIntPtr(0x5D4594, 2598000) ||
					(v6 = *(int(**)(int))(v0 + 96)) != 0 && v6(v0)) {
				LABEL_23:
					nox_xxx_spellCancelSpellDo_4FE9D0(v0);
				}
			}
			v0 = v1;
		} while (v1);
	}
}

//----- (004FEF90) --------------------------------------------------------
void  nox_xxx_netStopRaySpell_4FEF90(int a1, _DWORD* a2) {
	int v2;      // ecx
	int v3;      // eax
	char v4;     // cl
	int i;       // esi
	char v6;     // al
	char v7;     // cl
	char v8;     // dl
	__int16 v9;  // ax
	char v10;    // cl
	char v11[7]; // [esp+8h] [ebp-8h]

	if (a1) {
		v2 = *(_DWORD*)(a1 + 16);
		if (v2) {
			if (a2) {
				v3 = *(_DWORD*)(a1 + 4);
				v11[0] = -98;
				switch (v3) {
				case 7:
					v6 = *(_BYTE*)(a1 + 8);
					v11[1] = 10;
					v11[2] = v6;
					goto LABEL_13;
				case 9:
					v4 = *(_BYTE*)(a1 + 8);
					v11[1] = 9;
					v11[2] = v4;
					goto LABEL_13;
				case 22:
					v8 = *(_BYTE*)(a1 + 8);
					v11[1] = 12;
					v11[2] = v8;
					goto LABEL_13;
				case 24:
					v7 = *(_BYTE*)(a1 + 8);
					v11[1] = 11;
					v11[2] = v7;
					goto LABEL_13;
				case 35:
					if (v2 == *(_DWORD*)(a1 + 48))
						return;
					v11[1] = 13;
					*(_WORD*)&v11[3] = nox_xxx_netGetUnitCodeServ_578AC0(a2);
					v9 = nox_xxx_netGetUnitCodeServ_578AC0(*(_DWORD**)(a1 + 16));
					v10 = *(_BYTE*)(a1 + 8);
					*(_WORD*)&v11[5] = v9;
					v11[2] = v10;
					nox_xxx_netSendPacket1_4E5390(255, (int)v11, 7, 0, 1);
					nox_xxx_netUnmarkMinimapSpec_417470(*(_DWORD*)(a1 + 16), 2);
					goto LABEL_16;
				case 43:
					for (i = *(_DWORD*)(a1 + 108); i; i = *(_DWORD*)(i + 116))
						nox_xxx_netStopRaySpell_4FEF90(i, *(_DWORD**)(i + 48));
					return;
				case 59:
					v11[1] = 8;
					v11[2] = *(_BYTE*)(v2 + 124);
				LABEL_13:
					*(_WORD*)&v11[5] = nox_xxx_netGetUnitCodeServ_578AC0(a2);
					*(_WORD*)&v11[3] = nox_xxx_netGetUnitCodeServ_578AC0(*(_DWORD**)(a1 + 16));
					nox_xxx_netSendPacket1_4E5390(255, (int)v11, 7, 0, 1);
					nox_xxx_netUnmarkMinimapSpec_417470(*(_DWORD*)(a1 + 16), 2);
				LABEL_16:
					nox_xxx_netUnmarkMinimapSpec_417470((int)a2, 2);
					break;
				default:
					return;
				}
			}
		}
	}
}

//----- (004FF130) --------------------------------------------------------
char*  nox_xxx_netStartDurationRaySpell_4FF130(int a1) {
	char* result; // eax
	int v2;       // edx
	int i;        // esi
	char v4;      // dl
	char v5;      // al
	__int16 v6;   // ax
	_DWORD* v7;   // edx
	__int16 v8;   // ax
	char v9;      // cl
	_DWORD* v10;  // [esp-4h] [ebp-10h]
	char v11[7];  // [esp+4h] [ebp-8h]

	v11[0] = -98;
	result = (char*)(*(_DWORD*)(a1 + 4) - 7);
	switch (*(_DWORD*)(a1 + 4)) {
	case 7:
		v4 = *(_BYTE*)(a1 + 8);
		v11[1] = 3;
		v11[2] = v4;
		goto LABEL_11;
	case 9:
		v11[1] = 2;
		goto LABEL_10;
	case 0x16:
		v11[1] = 5;
	LABEL_10:
		v11[2] = *(_BYTE*)(a1 + 8);
		goto LABEL_11;
	case 0x18:
		v5 = *(_BYTE*)(a1 + 8);
		v11[1] = 4;
		v11[2] = v5;
		goto LABEL_11;
	case 0x23:
		result = *(char**)(a1 + 48);
		if (*(char**)(a1 + 16) != result) {
			v10 = *(_DWORD**)(a1 + 48);
			v11[1] = 6;
			*(_WORD*)&v11[3] = nox_xxx_netGetUnitCodeServ_578AC0(v10);
			v8 = nox_xxx_netGetUnitCodeServ_578AC0(*(_DWORD**)(a1 + 16));
			v9 = *(_BYTE*)(a1 + 8);
			*(_WORD*)&v11[5] = v8;
			v11[2] = v9;
			nox_xxx_netSendPacket1_4E5390(255, (int)v11, 7, 0, 1);
			nox_xxx_netMarkMinimapForAll_4174B0(*(_DWORD*)(a1 + 16), 2);
			result = nox_xxx_netMarkMinimapForAll_4174B0(*(_DWORD*)(a1 + 48), 2);
		}
		return result;
	case 0x2B:
		for (i = *(_DWORD*)(a1 + 108); i; i = *(_DWORD*)(i + 116))
			result = (char*)nox_xxx_netStartDurationRaySpell_4FF130(i);
		return result;
	case 0x3B:
		v2 = *(_DWORD*)(a1 + 16);
		v11[1] = 1;
		v11[2] = *(_BYTE*)(v2 + 124);
	LABEL_11:
		result = *(char**)(a1 + 48);
		if (result) {
			v6 = nox_xxx_netGetUnitCodeServ_578AC0(*(_DWORD**)(a1 + 48));
			v7 = *(_DWORD**)(a1 + 16);
			*(_WORD*)&v11[5] = v6;
			*(_WORD*)&v11[3] = nox_xxx_netGetUnitCodeServ_578AC0(v7);
			nox_xxx_netSendPacket1_4E5390(255, (int)v11, 7, 0, 1);
			nox_xxx_netMarkMinimapForAll_4174B0(*(_DWORD*)(a1 + 16), 2);
			result = nox_xxx_netMarkMinimapForAll_4174B0(*(_DWORD*)(a1 + 48), 2);
		}
		break;
	default:
		return result;
	}
	return result;
}

//----- (004FF2D0) --------------------------------------------------------
int  sub_4FF2D0(int a1, int a2) {
	int result; // eax
	int v3;     // ecx

	result = nox_xxx_spellCastedFirst_4FE930();
	if (!result)
		return 0;
	while (1) {
		if (!(*(_BYTE*)(result + 88) & 1) && *(_DWORD*)(result + 4) == a1) {
			v3 = *(_DWORD*)(result + 48);
			if (v3) {
				if (v3 == a2)
					break;
			}
		}
		result = nox_xxx_spellCastedNext_4FE940(result);
		if (!result)
			return 0;
	}
	return result;
}

//----- (004FF310) --------------------------------------------------------
void  sub_4FF310(int a1) {
	int* v1; // esi
	int* v2; // edi

	v1 = *(int**)&dword_5d4594_1569728;
	if (dword_5d4594_1569728) {
		do {
			v2 = (int*)v1[29];
			if (v1[4] == a1) {
				if (nox_xxx_spellGetFlags_424A70(v1[1]) & 0x20)
					nox_xxx_spellCancelSpellDo_4FE9D0((int)v1);
			}
			v1 = v2;
		} while (v2);
	}
}

//----- (004FF350) --------------------------------------------------------
BOOL  nox_xxx_testUnitBuffs_4FF350(int a1, char a2) {
	BOOL result; // eax

	result = a1;
	if (a1)
		result = ((1 << a2) & *(_DWORD*)(a1 + 340)) != 0;
	return result;
}

//----- (004FF380) --------------------------------------------------------
__int16  nox_xxx_buffApplyTo_4FF380(int a1, int a2, __int16 a3, char a4) {
	int v4; // eax
	int v5; // eax
	int v6; // eax

	LOWORD(v4) = *getMemU16Ptr(0x5D4594, 1569740);
	if (!*getMemU32Ptr(0x5D4594, 1569740)) {
		*getMemU32Ptr(0x5D4594, 1569740) = nox_xxx_getNameId_4E3AA0("Hecubah");
		v4 = nox_xxx_getNameId_4E3AA0("Necromancer");
		*getMemU32Ptr(0x5D4594, 1569744) = v4;
	}
	if (a1) {
		LOWORD(v4) = *(_WORD*)(a1 + 4);
		if ((unsigned __int16)v4 != *getMemU32Ptr(0x5D4594, 1569740) || a2 != 29) {
			if (nox_common_gameFlags_check_40A5C0(4096) &&
				*(unsigned __int16*)(a1 + 4) == *getMemU32Ptr(0x5D4594, 1569740) && a2 == 3) {
				LOWORD(v4) = (unsigned int)nox_xxx_aud_501960(582, a1, 0, 0);
			} else {
				v4 = nox_common_gameFlags_check_40A5C0(4096);
				if (v4 &&
					(LOWORD(v4) = *getMemU16Ptr(0x5D4594, 1569744),
					 *(unsigned __int16*)(a1 + 4) == *getMemU32Ptr(0x5D4594, 1569744)) &&
					a2 == 3) {
					LOWORD(v4) = (unsigned int)nox_xxx_aud_501960(595, a1, 0, 0);
				} else if (*(_BYTE*)(a1 + 8) & 2 && (v4 = *(_DWORD*)(a1 + 12), BYTE1(v4) & 0x10) && a2 == 11 &&
						   (v4 = nox_common_gameFlags_check_40A5C0(2048)) == 0) {
					LOWORD(v4) = *(_WORD*)(a1 + 4);
					if ((unsigned __int16)v4 == *getMemU32Ptr(0x5D4594, 1569740)) {
						LOWORD(v4) = (unsigned int)nox_xxx_aud_501960(582, a1, 0, 0);
					} else if (v4 == *getMemU32Ptr(0x5D4594, 1569744)) {
						LOWORD(v4) = (unsigned int)nox_xxx_aud_501960(595, a1, 0, 0);
					}
				} else if (!(*(_DWORD*)(a1 + 16) & 0x8022)) {
					if (!nox_xxx_testUnitBuffs_4FF350(a1, a2) || (v4 = nox_xxx_unitGetBuffTimer_4FF550(a1, a2)) != 0) {
						if (a2)
							nox_xxx_spellBuffOff_4FF5B0(a1, 0);
						*(_WORD*)(a1 + 2 * a2 + 344) = a3;
						*(_BYTE*)(a1 + a2 + 408) = a4;
						nox_xxx_setUnitBuffFlags_4E48F0(a1, (1 << a2) | *(_DWORD*)(a1 + 340));
						v5 = nox_xxx_getEnchantSpell_424920(a2);
						v6 = nox_xxx_spellGetAud44_424800(v5, 1);
						LOWORD(v4) = (unsigned int)nox_xxx_aud_501960(v6, a1, 0, 0);
					}
				}
			}
		}
	}
	return v4;
}

//----- (004FF550) --------------------------------------------------------
int  nox_xxx_unitGetBuffTimer_4FF550(int a1, int a2) { return *(unsigned __int16*)(a1 + 2 * a2 + 344); }

//----- (004FF570) --------------------------------------------------------
char  nox_xxx_buffGetPower_4FF570(int a1, int a2) { return *(_BYTE*)(a1 + a2 + 408); }

//----- (004FF580) --------------------------------------------------------
int  nox_xxx_unitClearBuffs_4FF580(int a1) {
	int result; // eax
	_WORD* v2;  // ecx

	nox_xxx_setUnitBuffFlags_4E48F0(a1, 0);
	result = 0;
	v2 = (_WORD*)(a1 + 344);
	do {
		*v2 = 0;
		*(_BYTE*)(a1 + result++ + 408) = 0;
		++v2;
	} while (result < 32);
	return result;
}

//----- (004FF5B0) --------------------------------------------------------
int  nox_xxx_spellBuffOff_4FF5B0(int a1, int a2) {
	int result; // eax
	int v3;     // ecx
	int v4;     // eax
	int v5;     // eax

	result = 1 << a2;
	v3 = *(_DWORD*)(a1 + 340);
	if (v3 & (1 << a2)) {
		nox_xxx_setUnitBuffFlags_4E48F0(a1, v3 & ~result);
		result = 0;
		*(_WORD*)(a1 + 2 * a2 + 344) = 0;
		*(_BYTE*)(a1 + a2 + 408) = 0;
		if (a2 != 16 && a2 != 30) {
			v4 = nox_xxx_getEnchantSpell_424920(a2);
			v5 = nox_xxx_spellGetAud44_424800(v4, 2);
			result = nox_xxx_aud_501960(v5, a1, 0, 0);
		}
	}
	return result;
}

//----- (004FF620) --------------------------------------------------------
void  nox_xxx_updateUnitBuffs_4FF620(int a1) {
	int v1;              // edi
	unsigned __int16 v2; // ax
	__int16 v3;          // ax
	int v4;              // eax

	if (*(_DWORD*)(a1 + 340)) {
		v1 = 0;
		do {
			if ((1 << v1) & *(_DWORD*)(a1 + 340)) {
				if (v1 == 16 && (unsigned int)*(unsigned __int16*)(a1 + 376) % nox_gameFPS ==
									nox_gameFPS - 1) {
					nox_xxx_aud_501960(26, a1, 0, 0);
				}
				v2 = *(_WORD*)(a1 + 2 * v1 + 344);
				if (v2 > 0u) {
					v3 = v2 - 1;
					*(_WORD*)(a1 + 2 * v1 + 344) = v3;
					if (!v3) {
						if (v1 == 7) {
							v4 = *(_DWORD*)(a1 + 16);
							LOBYTE(v4) = v4 & 0xBF;
							*(_DWORD*)(a1 + 16) = v4;
						} else if (v1 == 16) {
							*(_DWORD*)(a1 + 520) = 0;
							*(_DWORD*)(a1 + 524) = 13;
							nox_xxx_unitDamageClear_4EE5E0(a1, 9999999);
							nox_xxx_aud_501960(779, a1, 0, 0);
							if (*(_BYTE*)(a1 + 8) & 4) {
								nox_xxx_playerIncrementElimDeath_4D8D40(a1);
								nox_xxx_netReportLesson_4D8EF0(a1);
							}
						}
						nox_xxx_spellBuffOff_4FF5B0(a1, v1);
						*(_BYTE*)(v1 + a1 + 408) = 0;
					}
				}
			}
			++v1;
		} while (v1 < 32);
		if (nox_xxx_testUnitBuffs_4FF350(a1, 9))
			*(float*)(a1 + 544) = *(float*)(a1 + 544) * 1.25;
	}
}

//----- (004FF730) --------------------------------------------------------
BOOL nox_xxx_allocMagicWallArray_4FF730() {
	dword_5d4594_1569756 = 0;
	nox_alloc_magicWall_1569748 = nox_new_alloc_class("MagicWall", 32, (*getMemU32Ptr(0x587000, 217844) << 6) + 32);
	return nox_alloc_magicWall_1569748 != 0;
}

//----- (004FF770) --------------------------------------------------------
int sub_4FF770() {
	int result; // eax

	nox_free_alloc_class(*(LPVOID*)&nox_alloc_magicWall_1569748);
	result = 0;
	nox_alloc_magicWall_1569748 = 0;
	dword_5d4594_1569752 = 0;
	dword_5d4594_1569756 = 0;
	return result;
}

//----- (004FF790) --------------------------------------------------------
void nox_xxx_mapWall_4FF790() {
	nox_alloc_class_yyy_4144D0(*(_DWORD**)&nox_alloc_magicWall_1569748);
	dword_5d4594_1569752 = 0;
}

//----- (004FF7B0) --------------------------------------------------------
void  sub_4FF7B0(int a1) {
	char v1;    // cl
	int v2;     // edi
	_DWORD* v3; // esi
	char* v4;   // eax
	int v6;     // [esp-14h] [ebp-28h]
	char v7[6]; // [esp+Ch] [ebp-8h]

	v1 = *(_BYTE*)(a1 + 2064);
	v2 = 1 << v1;
	if (v1 != 31) {
		v3 = *(_DWORD**)&dword_5d4594_1569752;
		if (dword_5d4594_1569752) {
			do {
				if (*(_BYTE*)(a1 + 3680) & 0x10) {
					if (!(v2 & v3[4])) {
						v4 = (char*)v3[2];
						v7[0] = 61;
						v7[1] = v4[1];
						v7[2] = *v4;
						v7[3] = v4[2];
						v7[4] = v4[5];
						v6 = *(unsigned __int8*)(a1 + 2064);
						v7[5] = v4[6];
						nox_xxx_netSendPacket0_4E5420(v6, v7, 6, 0, 1);
						v3[4] = v2 | v3[4];
					}
				}
				v3 = (_DWORD*)v3[6];
			} while (v3);
		}
	}
}

//----- (004FF840) --------------------------------------------------------
int  nox_xxx_wallDestroyMagicwallSysuse_4FF840(int a1) {
	int result; // eax
	int v2;     // esi

	result = dword_5d4594_1569752;
	if (dword_5d4594_1569752) {
		do {
			v2 = *(_DWORD*)(result + 24);
			if (*(_DWORD*)(result + 8) == a1)
				nox_xxx_wallDestroy_4FF870(result);
			result = v2;
		} while (v2);
	}
	return result;
}

//----- (004FF870) --------------------------------------------------------
void  nox_xxx_wallDestroy_4FF870(int a1) {
	_BYTE* v1; // eax
	int v2;    // eax
	int v3;    // eax

	sub_4FF900(a1);
	if (nox_common_gameFlags_check_40A5C0(1)) {
		v1 = *(_BYTE**)(a1 + 8);
		if (*(_DWORD*)a1) {
			v1[1] = *(_BYTE*)(a1 + 12);
			**(_BYTE**)(a1 + 8) = *(_BYTE*)(a1 + 13);
			*(_BYTE*)(*(_DWORD*)(a1 + 8) + 2) = *(_BYTE*)(a1 + 14);
		} else {
			nox_xxx_mapDelWallAtPt_410430((unsigned __int8)v1[5], (unsigned __int8)v1[6]);
		}
	}
	v2 = *(_DWORD*)(a1 + 28);
	if (v2)
		*(_DWORD*)(v2 + 24) = *(_DWORD*)(a1 + 24);
	else
		dword_5d4594_1569752 = *(_DWORD*)(a1 + 24);
	v3 = *(_DWORD*)(a1 + 24);
	if (v3)
		*(_DWORD*)(v3 + 28) = *(_DWORD*)(a1 + 28);
	nox_alloc_class_free_obj(*(unsigned int**)&nox_alloc_magicWall_1569748, (_QWORD*)a1);
}

//----- (004FF900) --------------------------------------------------------
int  sub_4FF900(int a1) {
	int v1;         // esi
	unsigned int i; // edi
	int result;     // eax
	char v4;        // cl
	char v5;        // dl
	int v6;         // eax
	int v7;         // eax
	char v8[6];     // [esp+8h] [ebp-8h]

	v1 = a1;
	for (i = 0; i < 0x20; ++i) {
		result = 1 << i;
		if ((1 << i) & *(_DWORD*)(v1 + 16)) {
			if (*(_DWORD*)v1) {
				v4 = *(_BYTE*)(v1 + 12);
				v5 = *(_BYTE*)(v1 + 13);
				v8[3] = *(_BYTE*)(v1 + 14);
				v6 = *(_DWORD*)(v1 + 8);
				v8[0] = 61;
				v8[1] = v4;
				v8[2] = v5;
				v8[4] = *(_BYTE*)(v6 + 5);
				v8[5] = *(_BYTE*)(v6 + 6);
				result = nox_xxx_netSendPacket0_4E5420(i, v8, 6, 0, 1);
			} else {
				v7 = *(_DWORD*)(v1 + 8);
				LOBYTE(a1) = 62;
				*(_WORD*)((char*)&a1 + 1) = *(_WORD*)(v7 + 5);
				result = nox_xxx_netSendPacket0_4E5420(i, &a1, 3, 0, 1);
			}
		}
	}
	return result;
}

//----- (004FF990) --------------------------------------------------------
int  sub_4FF990(int a1) {
	int result; // eax

	for (result = dword_5d4594_1569752; result; result = *(_DWORD*)(result + 24))
		*(_DWORD*)(result + 16) &= ~a1;
	return result;
}

//----- (004FF9B0) --------------------------------------------------------
char  nox_xxx_spellWallCreateCalcDirMB_4FF9B0(int a1, int a2, int a3, int a4, int a5) {
	char result; // al

	result = sub_4FFA40(a1);
	switch (a1) {
	case 1:
		if (a5 != a3)
			result = sub_4FFA40(7);
		break;
	case 7:
		if (a5 != a3)
			result = sub_4FFA40(1);
		break;
	case 3:
		if (a4 != a2)
			result = sub_4FFA40(5);
		break;
	default:
		if (a1 == 5 && a4 != a2)
			result = sub_4FFA40(3);
		break;
	}
	return result;
}

//----- (004FFA40) --------------------------------------------------------
char  sub_4FFA40(int a1) {
	char result; // al

	switch (a1) {
	case 1:
		result = 7;
		break;
	case 2:
	case 6:
		result = 1;
		break;
	case 3:
		result = 8;
		break;
	case 5:
		result = 10;
		break;
	case 7:
		result = 9;
		break;
	default:
		result = 0;
		break;
	}
	return result;
}

//----- (004FFA90) --------------------------------------------------------
int  nox_xxx_spellWallCreate_4FFA90(int a1) {
	int v1;              // edi
	int v2;              // eax
	float v3;            // edx
	float v4;            // ecx
	float v5;            // edx
	int v6;              // edi
	int v7;              // edi
	int v9;              // eax
	int v10;             // esi
	int v11;             // ebx
	int v13;             // ebp
	int v14;             // ebx
	int v15;             // ebp
	int v16;             // [esp+4h] [ebp-28h]
	unsigned __int8 v17; // [esp+8h] [ebp-24h]
	unsigned __int8 v18; // [esp+8h] [ebp-24h]
	unsigned __int8 v19; // [esp+8h] [ebp-24h]
	int i;               // [esp+Ch] [ebp-20h]
	int j;               // [esp+Ch] [ebp-20h]
	int v22;             // [esp+10h] [ebp-1Ch]
	float2 v23;          // [esp+14h] [ebp-18h]
	float4 a1a;          // [esp+1Ch] [ebp-10h]

	v1 = a1;
	v22 = 60 * nox_gameFPS * (*(_DWORD*)(a1 + 8) + 5);
	v2 = *(_DWORD*)(a1 + 16);
	if (!v2 || *(_DWORD*)(v2 + 16) & 0x8020)
		return 1;
	v3 = *(float*)(a1 + 32);
	a1a.field_0 = *(float*)(a1 + 28);
	v4 = *(float*)(a1 + 52);
	a1a.field_4 = v3;
	v5 = *(float*)(a1 + 56);
	a1a.field_8 = v4;
	a1a.field_C = v5;
	if (!(unsigned __int8)nox_xxx_traceRay_5374B0(&a1a)) {
		v6 = *(_DWORD*)(v1 + 16);
		if (*(_BYTE*)(v6 + 8) & 4) {
			v7 = *(_DWORD*)(v6 + 748);
			a1 = 2;
			nox_xxx_netInformTextMsg_4DA0F0(*(unsigned __int8*)(*(_DWORD*)(v7 + 276) + 2064), 0, &a1);
		}
		return 1;
	}
	v23.field_0 = a1a.field_8 - a1a.field_0;
	v23.field_4 = a1a.field_C - a1a.field_4;
	v9 = nox_xxx_math_509ED0(&v23);
	v10 = nox_xxx_math_509EA0(v9);
	v11 = (__int64)*(float*)(v1 + 52) / 23;
	v13 = (__int64)*(float*)(v1 + 56) / 23;
	if ((((_BYTE)v11 + (_BYTE)v13) & 1) == 1)
		++v11;
	v16 = v11;
	a1 = (__int64)*(float*)(v1 + 56) / 23;
	v17 = sub_4FFA40(v10);
	if (sub_4FFD00(v1, v11, v13, v17)) {
		for (i = 0; i < *getMemIntPtr(0x587000, 4 * *(_DWORD*)(v1 + 8) + 217844); ++i) {
			v11 = (unsigned __int8)nox_xxx_spellWallCreateCalcXMB_4FFEF0(v10, v16, v11, 0);
			v13 = (unsigned __int8)nox_xxx_spellWallCreateCalcYMB_4FFFB0(v10, a1, v13, 0);
			v18 = nox_xxx_spellWallCreateCalcDirMB_4FF9B0(v10, v16, a1, v11, v13);
			if (!sub_4FFD00(v1, v11, v13, v18))
				break;
		}
		v14 = v16;
		v15 = a1;
		for (j = 0; j < *getMemIntPtr(0x587000, 4 * *(_DWORD*)(v1 + 8) + 217844); ++j) {
			v14 = (unsigned __int8)nox_xxx_spellWallCreateCalcXMB_4FFEF0(v10, v16, v14, 1);
			v15 = (unsigned __int8)nox_xxx_spellWallCreateCalcYMB_4FFFB0(v10, a1, v15, 1);
			v19 = nox_xxx_spellWallCreateCalcDirMB_4FF9B0(v10, v16, a1, v14, v15);
			if (!sub_4FFD00(v1, v14, v15, v19))
				break;
		}
	}
	*(_DWORD*)(v1 + 68) = v22 + *getMemU32Ptr(0x5D4594, 2598000);
	return 0;
}

//----- (004FFD00) --------------------------------------------------------
BOOL  sub_4FFD00(int a1, int a2, int a3, unsigned __int8 a4) {
	int v4;              // ebx
	int v5;              // eax
	unsigned __int8* v6; // esi
	char v7;             // al
	unsigned __int8* v9; // eax
	int v10;             // [esp-4h] [ebp-20h]
	char v11;            // [esp+10h] [ebp-Ch]
	char v12;            // [esp+14h] [ebp-8h]
	char v13;            // [esp+18h] [ebp-4h]

	v4 = 0;
	v13 = 0;
	v12 = 0;
	v11 = 0;
	if (!getMemByte(0x5D4594, 1570004)) {
		*getMemU8Ptr(0x5D4594, 1570004) = nox_xxx_wallTileByName_410D60("MagicWallSystemUseOnly");
		*getMemU8Ptr(0x5D4594, 1570005) = nox_xxx_wallTileByName_410D60("InvisibleWallSet");
		*getMemU8Ptr(0x5D4594, 1570006) = nox_xxx_wallTileByName_410D60("InvisibleBlockingWallSet");
	}
	v5 = nox_server_getWallAtPoint_410580(a2, a3);
	v6 = (unsigned __int8*)v5;
	if (v5) {
		v7 = *(_BYTE*)(v5 + 1);
		if (v7 == getMemByte(0x5D4594, 1570004))
			return 0;
		if (v7 != getMemByte(0x5D4594, 1570005) && v7 != getMemByte(0x5D4594, 1570006)) {
			if (v6[4] & 0x1C)
				return 0;
			v13 = v6[1];
			v4 = 1;
			v12 = *v6;
			v11 = v6[2];
			*v6 = nox_xxx_wall_42A6C0(*v6, a4);
			goto LABEL_11;
		}
	} else {
		v9 = (unsigned __int8*)nox_xxx_wallCreateAt_410250(a2, a3);
		v6 = v9;
		if (v9) {
			v9[1] = getMemByte(0x5D4594, 1570004);
			*v9 = a4;
			if (!a4 || a4 == 1) {
				v9[2] = v9[5] % (__int16)nox_xxx_map_410E00(getMemByte(0x5D4594, 1570004));
				goto LABEL_12;
			}
		LABEL_11:
			v6[2] = 0;
			if (v4) {
			LABEL_13:
				nox_xxx_netWallCreate_4FFE80(a1, v6, v4, v13, v12, v11);
				return v4 == 0;
			}
		LABEL_12:
			v10 = v6[1];
			v6[4] |= 8u;
			v6[7] = nox_xxx_mapWallGetHpByTile_410E20(v10);
			goto LABEL_13;
		}
	}
	return 0;
}

//----- (004FFE80) --------------------------------------------------------
_DWORD*  nox_xxx_netWallCreate_4FFE80(int a1, _BYTE* a2, int a3, char a4, char a5, char a6) {
	_DWORD* result; // eax

	result = nox_alloc_class_new_obj_zero(*(_DWORD**)&nox_alloc_magicWall_1569748);
	if (result) {
		result[2] = a2;
		*result = a3;
		*((_BYTE*)result + 4) = *a2;
		*((_BYTE*)result + 12) = a4;
		*((_BYTE*)result + 13) = a5;
		*((_BYTE*)result + 14) = a6;
		result[5] = a1;
		result[4] = 0;
		result[7] = 0;
		result[6] = dword_5d4594_1569752;
		if (dword_5d4594_1569752)
			*(_DWORD*)(dword_5d4594_1569752 + 28) = result;
		dword_5d4594_1569752 = result;
	}
	return result;
}

//----- (004FFEF0) --------------------------------------------------------
char  nox_xxx_spellWallCreateCalcXMB_4FFEF0(int a1, int a2, int a3, char a4) {
	char result; // al
	char v5;     // al

	if (!a4) {
		switch (a1) {
		case 0:
			goto LABEL_3;
		case 1:
			goto LABEL_4;
		case 2:
			goto LABEL_5;
		case 3:
			goto LABEL_12;
		case 5:
			goto LABEL_10;
		case 6:
			goto LABEL_9;
		case 7:
			goto LABEL_8;
		case 8:
			goto LABEL_7;
		default:
			goto LABEL_14;
		}
	}
	switch (a1) {
	case 0:
	LABEL_7:
		result = a3 - 1;
		break;
	case 1:
	LABEL_8:
		result = a3 - 1;
		break;
	case 2:
	LABEL_9:
		result = a3 - 1;
		break;
	case 3:
	LABEL_12:
		v5 = a3;
		if (a3 != a2)
			goto LABEL_11;
		goto LABEL_13;
	case 5:
	LABEL_10:
		v5 = a3;
		if (a3 == a2)
		LABEL_11:
			result = v5 - 1;
		else
		LABEL_13:
			result = v5 + 1;
		break;
	case 6:
	LABEL_5:
		result = a3 + 1;
		break;
	case 7:
	LABEL_4:
		result = a3 + 1;
		break;
	case 8:
	LABEL_3:
		result = a3 + 1;
		break;
	default:
	LABEL_14:
		result = a3;
		break;
	}
	return result;
}

//----- (004FFFB0) --------------------------------------------------------
char  nox_xxx_spellWallCreateCalcYMB_4FFFB0(int a1, int a2, int a3, char a4) {
	char v4;     // al
	char result; // al

	if (!a4) {
		switch (a1) {
		case 0:
			goto LABEL_3;
		case 1:
			goto LABEL_7;
		case 2:
			goto LABEL_13;
		case 3:
			goto LABEL_10;
		case 5:
			goto LABEL_14;
		case 6:
			goto LABEL_9;
		case 7:
			goto LABEL_11;
		case 8:
			goto LABEL_6;
		default:
			goto LABEL_15;
		}
	}
	switch (a1) {
	case 0:
	LABEL_6:
		result = a3 + 1;
		break;
	case 1:
	LABEL_7:
		v4 = a3;
		if (a3 != a2)
			goto LABEL_12;
		result = a3 - 1;
		break;
	case 2:
	LABEL_9:
		result = a3 - 1;
		break;
	case 3:
	LABEL_14:
		result = a3 + 1;
		break;
	case 5:
	LABEL_10:
		result = a3 - 1;
		break;
	case 6:
	LABEL_13:
		result = a3 + 1;
		break;
	case 7:
	LABEL_11:
		v4 = a3;
		if (a3 != a2)
			goto LABEL_4;
	LABEL_12:
		result = v4 + 1;
		break;
	case 8:
	LABEL_3:
		v4 = a3;
	LABEL_4:
		result = v4 - 1;
		break;
	default:
	LABEL_15:
		result = a3;
		break;
	}
	return result;
}

//----- (00500070) --------------------------------------------------------
int nox_xxx_spellWallUpdate_500070() { return 0; }

//----- (00500080) --------------------------------------------------------
int  nox_xxx_spellWallDestroy_500080(int a1) {
	int result; // eax
	int v2;     // esi

	result = dword_5d4594_1569752;
	if (dword_5d4594_1569752) {
		do {
			v2 = *(_DWORD*)(result + 24);
			if (*(_DWORD*)(result + 20) == a1)
				nox_xxx_wallDestroy_4FF870(result);
			result = v2;
		} while (v2);
	}
	return result;
}

//----- (005000B0) --------------------------------------------------------
int  sub_5000B0(_DWORD* a1) {
	int v1;  // eax
	int v2;  // esi
	int v4;  // esi
	int v5;  // [esp+0h] [ebp-2Ch]
	int v6;  // [esp+4h] [ebp-28h]
	int v7;  // [esp+8h] [ebp-24h]
	int v8;  // [esp+Ch] [ebp-20h]
	int v9;  // [esp+10h] [ebp-1Ch]
	int v10; // [esp+14h] [ebp-18h]
	int v11; // [esp+18h] [ebp-14h]
	int v12; // [esp+1Ch] [ebp-10h]
	int v13; // [esp+20h] [ebp-Ch]
	int v14; // [esp+24h] [ebp-8h]
	int v15; // [esp+28h] [ebp-4h]

	v6 = 1;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v6, 2u);
	if ((__int16)v6 > 1 || (__int16)v6 <= 0)
		return 0;
	v1 = dword_5d4594_1569752;
	for (LOBYTE(v5) = 0; v1; v1 = *(_DWORD*)(v1 + 24))
		LOBYTE(v5) = v5 + 1;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v5, 1u);
	if (*getMemU32Ptr(0x5D4594, 3803300)) {
		if ((_BYTE)v5) {
			sub_5002D0(a1);
			v4 = 0;
			dword_5d4594_1569756 = 0;
			if ((_BYTE)v5) {
				do {
					nox_xxx_fileReadWrite_426AC0_file3_fread(&v13, 4u);
					nox_xxx_fileReadWrite_426AC0_file3_fread(&v15, 1u);
					nox_xxx_fileReadWrite_426AC0_file3_fread(&v14, 1u);
					nox_xxx_fileReadWrite_426AC0_file3_fread(&v12, 1u);
					nox_xxx_fileReadWrite_426AC0_file3_fread(&v11, 1u);
					nox_xxx_fileReadWrite_426AC0_file3_fread(&v10, 1u);
					nox_xxx_fileReadWrite_426AC0_file3_fread(&v9, 1u);
					nox_xxx_fileReadWrite_426AC0_file3_fread(&v8, 1u);
					nox_xxx_fileReadWrite_426AC0_file3_fread(&v7, 1u);
					nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 1u);
					sub_500330(v15, v14, v13, v12, v11, v10, v9, v8, v7, (char)a1);
					++v4;
				} while (v4 < (unsigned __int8)v5);
			}
		}
		return 1;
	}
	v2 = dword_5d4594_1569752;
	if (!dword_5d4594_1569752)
		return 1;
	do {
		nox_xxx_fileReadWrite_426AC0_file3_fread((_BYTE*)v2, 4u);
		nox_xxx_fileReadWrite_426AC0_file3_fread((_BYTE*)(*(_DWORD*)(v2 + 8) + 5), 1u);
		nox_xxx_fileReadWrite_426AC0_file3_fread((_BYTE*)(*(_DWORD*)(v2 + 8) + 6), 1u);
		nox_xxx_fileReadWrite_426AC0_file3_fread((_BYTE*)(v2 + 12), 1u);
		nox_xxx_fileReadWrite_426AC0_file3_fread((_BYTE*)(v2 + 13), 1u);
		nox_xxx_fileReadWrite_426AC0_file3_fread((_BYTE*)(v2 + 14), 1u);
		nox_xxx_fileReadWrite_426AC0_file3_fread((_BYTE*)(*(_DWORD*)(v2 + 8) + 1), 1u);
		nox_xxx_fileReadWrite_426AC0_file3_fread((_BYTE*)(*(_DWORD*)(v2 + 8) + 2), 1u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(*(_BYTE**)(v2 + 8), 1u);
		nox_xxx_fileReadWrite_426AC0_file3_fread((_BYTE*)(*(_DWORD*)(v2 + 8) + 7), 1u);
		v2 = *(_DWORD*)(v2 + 24);
	} while (v2);
	return 1;
}

//----- (005002D0) --------------------------------------------------------
int  sub_5002D0(_DWORD* a1) {
	int v1;    // ecx
	int v3[3]; // [esp+0h] [ebp-Ch]

	v3[0] = (int)a1;
	v1 = a1[187];
	*(float*)&v3[1] = (double)*(int*)(*(_DWORD*)(v1 + 276) + 2284);
	*(float*)&v3[2] = (double)*(int*)(*(_DWORD*)(v1 + 276) + 2288);
	return nox_xxx_spellDurationBased_4FEBA0(132, (int)a1, a1, (int)a1, v3, 3, 0, 0, 0, 0);
}

//----- (00500330) --------------------------------------------------------
void  sub_500330(char a1, char a2, int a3, char a4, char a5, char a6, char a7, char a8, char a9, char a10) {
	int v11; // ecx
	int result;

	if (*(int*)&dword_5d4594_1569756 < 15) {
		result = 16 * dword_5d4594_1569756;
		v11 = dword_5d4594_1569756 + 1;
		*getMemU8Ptr( 0x5D4594, result + 1569764) = a1;
		*getMemU8Ptr( 0x5D4594, result + 1569765) = a2;
		*getMemU32Ptr(0x5D4594, result + 1569768) = a3;
		*getMemU8Ptr( 0x5D4594, result + 1569772) = a4;
		*getMemU8Ptr( 0x5D4594, result + 1569773) = a5;
		*getMemU8Ptr( 0x5D4594, result + 1569774) = a6;
		*getMemU8Ptr( 0x5D4594, result + 1569775) = a7;
		*getMemU8Ptr( 0x5D4594, result + 1569776) = a8;
		*getMemU8Ptr( 0x5D4594, result + 1569777) = a9;
		*getMemU8Ptr( 0x5D4594, result + 1569778) = a10;
		dword_5d4594_1569756 = v11;
	}
}

//----- (005004D0) --------------------------------------------------------
int nox_xxx_mapSetWallInGlobalDir0pr1_5004D0() {
	int result; // eax

	for (result = dword_5d4594_1569752; result; result = *(_DWORD*)(result + 24)) {
		if (*(_DWORD*)result == 1)
			**(_BYTE**)(result + 8) = *(_BYTE*)(result + 13);
	}
	return result;
}

//----- (005004F0) --------------------------------------------------------
int nox_xxx_map_5004F0() {
	int result; // eax

	for (result = dword_5d4594_1569752; result; result = *(_DWORD*)(result + 24)) {
		if (*(_DWORD*)result == 1)
			**(_BYTE**)(result + 8) = *(_BYTE*)(result + 4);
	}
	return result;
}

//----- (00500540) --------------------------------------------------------
char*  nox_xxx_journalQuestSet_500540(char* a1, int a2) {
	char* result; // eax
	char* v3;     // edx

	result = nox_xxx_scriptGetJournal_5005E0(a1);
	if (result) {
		*((_DWORD*)result + 34) = a2;
	} else {
		result = (char*)malloc(0x94u);
		v3 = result;
		if (result) {
			strcpy(result, (const char*)getMemAt(0x5D4594, 1570140));
			*((_DWORD*)result + 33) = 0;
			*((_DWORD*)result + 34) = a2;
			*((_DWORD*)result + 36) = 0;
			*((_DWORD*)result + 35) = dword_5d4594_1570272;
			result = *(char**)&dword_5d4594_1570272;
			if (dword_5d4594_1570272)
				*(_DWORD*)(dword_5d4594_1570272 + 144) = v3;
			dword_5d4594_1570272 = v3;
		}
	}
	return result;
}

//----- (005005E0) --------------------------------------------------------
char*  nox_xxx_scriptGetJournal_5005E0(char* a1) {
	unsigned int v1;     // edx
	unsigned __int8* v2; // edi
	unsigned __int8* v3; // edi
	char* v4;            // esi
	char v5;             // cl
	unsigned int v6;     // ecx
	char v7;             // al
	int i;               // esi

	if (strchr(a1, 58)) {
		v6 = strlen(a1) + 1;
		v7 = v6;
		v6 >>= 2;
		memcpy(getMemAt(0x5D4594, 1570140), a1, 4 * v6);
		v4 = &a1[4 * v6];
		v3 = getMemAt(0x5D4594, 4 * v6 + 1570140);
		v5 = v7;
	} else {
		strcpy((char*)getMemAt(0x5D4594, 1570140), (const char*)getMemAt(0x5D4594, 1570008));
		*getMemU16Ptr(0x5D4594, strlen((const char*)getMemAt(0x5D4594, 1570140)) + 1570140) = *getMemU16Ptr(0x587000, 217952);
		v1 = strlen(a1) + 1;
		v2 = getMemAt(0x5D4594, strlen((const char*)getMemAt(0x5D4594, 1570140)) + 1570140);
		memcpy(v2, a1, 4 * (v1 >> 2));
		v4 = &a1[4 * (v1 >> 2)];
		v3 = &v2[4 * (v1 >> 2)];
		v5 = v1;
	}
	memcpy(v3, v4, v5 & 3);
	for (i = dword_5d4594_1570272; i; i = *(_DWORD*)(i + 140)) {
		if (!_strcmpi((const char*)i, (const char*)getMemAt(0x5D4594, 1570140)))
			break;
	}
	return (char*)i;
}

//----- (005006B0) --------------------------------------------------------
char*  nox_xxx_journalQuestSetBool_5006B0(char* a1, int a2) {
	char* result; // eax
	char* v3;     // edx

	result = nox_xxx_scriptGetJournal_5005E0(a1);
	if (result) {
		*((_DWORD*)result + 34) = a2;
	} else {
		result = (char*)malloc(0x94u);
		v3 = result;
		if (result) {
			strcpy(result, (const char*)getMemAt(0x5D4594, 1570140));
			*((_DWORD*)result + 33) = 1;
			*((_DWORD*)result + 34) = a2;
			*((_DWORD*)result + 36) = 0;
			*((_DWORD*)result + 35) = dword_5d4594_1570272;
			result = *(char**)&dword_5d4594_1570272;
			if (dword_5d4594_1570272)
				*(_DWORD*)(dword_5d4594_1570272 + 144) = v3;
			dword_5d4594_1570272 = v3;
		}
	}
	return result;
}

//----- (00500750) --------------------------------------------------------
int  sub_500750(char* a1) {
	char* v1;   // eax
	int result; // eax

	v1 = nox_xxx_scriptGetJournal_5005E0(a1);
	if (v1)
		result = *((_DWORD*)v1 + 34);
	else
		result = 0;
	return result;
}

//----- (00500770) --------------------------------------------------------
double  sub_500770(char* a1) {
	char* v1;      // eax
	double result; // st7

	v1 = nox_xxx_scriptGetJournal_5005E0(a1);
	if (v1)
		result = *((float*)v1 + 34);
	else
		result = 0.0;
	return result;
}

//----- (00500790) --------------------------------------------------------
void  sub_500790(LPVOID lpMem) {
	int v1; // ecx
	int v2; // ecx

	v1 = *((_DWORD*)lpMem + 36);
	if (v1)
		*(_DWORD*)(v1 + 140) = *((_DWORD*)lpMem + 35);
	v2 = *((_DWORD*)lpMem + 35);
	if (v2)
		*(_DWORD*)(v2 + 144) = *((_DWORD*)lpMem + 36);
	if (lpMem == *(LPVOID*)&dword_5d4594_1570272)
		dword_5d4594_1570272 = *((_DWORD*)lpMem + 35);
	free(lpMem);
}

//----- (005007E0) --------------------------------------------------------
char*  sub_5007E0(char* a1) {
	unsigned __int8* v1; // edx
	char* result;        // eax
	unsigned int v3;     // kr04_4
	char* v4;            // esi
	int v5;              // esi
	int v6;              // edi
	int v7;              // esi
	int v8;              // ebx
	const char* v9;      // edi
	char* v10;           // edx
	const char* v11;     // ebx
	int v12;             // esi
	unsigned int v13;    // kr0C_4
	int v14;             // edi
	int v15;             // ebp
	unsigned int v16;    // kr10_4
	int v17;             // [esp+18h] [ebp+4h]

	sub_5009B0(a1);
	v1 = (unsigned __int8*)strchr((const char*)getMemAt(0x5D4594, 1570140), 42);
	if (v1) {
		v3 = strlen((const char*)getMemAt(0x5D4594, 1570140)) + 1;
		result = 0;
		if (!strcmp((const char*)getMemAt(0x5D4594, 1570140), "*:*")) {
			result = *(char**)&dword_5d4594_1570272;
			if (dword_5d4594_1570272) {
				do {
					v4 = (char*)*((_DWORD*)result + 35);
					sub_500790(result);
					result = v4;
				} while (v4);
			}
		} else if (v1 == getMemAt(0x5D4594, v3 + 1570138)) {
			v5 = dword_5d4594_1570272;
			if (dword_5d4594_1570272) {
				do {
					v6 = *(_DWORD*)(v5 + 140);
					result = (char*)_strnicmp((const char*)v5, (const char*)getMemAt(0x5D4594, 1570140), v3 - 2);
					if (!result)
						sub_500790((LPVOID)v5);
					v5 = v6;
				} while (v6);
			}
		} else if (v1 == getMemAt(0x5D4594, 1570140)) {
			v7 = dword_5d4594_1570272;
			if (dword_5d4594_1570272) {
				do {
					v8 = *(_DWORD*)(v7 + 140);
					result = strstr((const char*)v7, (const char*)getMemAt(0x5D4594, 1570141));
					if (result) {
						v9 = result;
						result = 0;
						if (v3 - 2 == strlen(v9))
							sub_500790((LPVOID)v7);
					}
					v7 = v8;
				} while (v8);
			}
		} else {
			v10 = strchr((const char*)getMemAt(0x5D4594, 1570140), 58);
			result = 0;
			v11 = v10 + 2;
			v12 = dword_5d4594_1570272;
			v13 = strlen(v10 + 2) + 1;
			if (dword_5d4594_1570272) {
				v14 = v10 - (char*)getMemAt(0x5D4594, 1570140);
				v17 = v10 - (char*)getMemAt(0x5D4594, 1570140);
				do {
					v15 = *(_DWORD*)(v12 + 140);
					result = (char*)_strnicmp((const char*)v12, (const char*)getMemAt(0x5D4594, 1570140), v14 + 1);
					if (!result) {
						result = strstr((const char*)(v14 + v12 + 2), v11);
						if (result) {
							v16 = strlen(result) + 1;
							result = (char*)(v13 - 1);
							if (v13 - 1 == v16 - 1)
								sub_500790((LPVOID)v12);
							v14 = v17;
						}
					}
					v12 = v15;
				} while (v15);
			}
		}
	} else {
		result = nox_xxx_scriptGetJournal_5005E0(a1);
		if (result)
			sub_500790(result);
	}
	return result;
}

//----- (005009B0) --------------------------------------------------------
unsigned int  sub_5009B0(char* a1) {
	unsigned int v1;     // ecx
	char v2;             // al
	unsigned __int8* v3; // edi
	unsigned __int8* v4; // esi
	unsigned int result; // eax

	if (strchr(a1, 58)) {
		result = strlen(a1) + 1;
		memcpy(getMemAt(0x5D4594, 1570140), a1, result);
	} else {
		v1 = strlen((const char*)getMemAt(0x5D4594, 1570008)) + 1;
		v2 = v1;
		v1 >>= 2;
		memcpy(getMemAt(0x5D4594, 1570140), getMemAt(0x5D4594, 1570008), 4 * v1);
		v4 = getMemAt(0x5D4594, 4 * v1 + 1570008);
		v3 = getMemAt(0x5D4594, 4 * v1 + 1570140);
		LOBYTE(v1) = v2;
		result = 0;
		memcpy(v3, v4, v1 & 3);
		*getMemU16Ptr(0x5D4594, strlen((const char*)getMemAt(0x5D4594, 1570140)) + 1570140) = *getMemU16Ptr(0x587000, 217960);
		strcat((char*)getMemAt(0x5D4594, 1570140), a1);
	}
	return result;
}

//----- (00500A60) --------------------------------------------------------
int sub_500A60() {
	int result; // eax
	int v1;     // eax
	int j;      // esi
	int v3;     // edi
	int i;      // [esp+0h] [ebp-Ch]
	int v5;     // [esp+4h] [ebp-8h]
	int v6;     // [esp+8h] [ebp-4h]

	v5 = 1;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v5, 2u);
	if ((__int16)v5 > 1)
		return 0;
	v1 = dword_5d4594_1570272;
	for (i = 0; v1; ++i)
		v1 = *(_DWORD*)(v1 + 140);
	if (nox_common_gameFlags_check_40A5C0(2048)) {
		nox_xxx_fileReadWrite_426AC0_file3_fread(&i, 4u);
		for (j = dword_5d4594_1570272; j; j = *(_DWORD*)(j + 140)) {
			LOBYTE(v6) = strlen((const char*)j);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v6, 1u);
			nox_xxx_fileReadWrite_426AC0_file3_fread((_BYTE*)j, (unsigned __int8)v6);
			nox_xxx_fileReadWrite_426AC0_file3_fread((_BYTE*)(j + 132), 4u);
			v3 = *(_DWORD*)(j + 132);
			if (v3) {
				if (v3 == 1)
					nox_xxx_fileReadWrite_426AC0_file3_fread((_BYTE*)(j + 136), 4u);
			} else {
				nox_xxx_fileReadWrite_426AC0_file3_fread((_BYTE*)(j + 136), 4u);
			}
		}
		result = 1;
	} else {
		i = 0;
		nox_xxx_fileReadWrite_426AC0_file3_fread(&i, 4u);
		result = 1;
	}
	return result;
}

//----- (00500B70) --------------------------------------------------------
int sub_500B70() {
	unsigned int i;  // esi
	int v2;          // [esp+0h] [ebp-118h]
	int v3;          // [esp+4h] [ebp-114h]
	unsigned int v4; // [esp+8h] [ebp-110h]
	int v5;          // [esp+Ch] [ebp-10Ch]
	int v6;          // [esp+10h] [ebp-108h]
	int v7;          // [esp+14h] [ebp-104h]
	char v8[256];    // [esp+18h] [ebp-100h]

	sub_5007E0("*:*");
	v3 = 1;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v3, 2u);
	if ((__int16)v3 > 1)
		return 0;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v4, 4u);
	for (i = 0; i < v4; ++i) {
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v2, 1u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(v8, (unsigned __int8)v2);
		v8[(unsigned __int8)v2] = 0;
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v5, 4u);
		if (v5) {
			if (v5 == 1) {
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v7, 4u);
				nox_xxx_journalQuestSetBool_5006B0(v8, v7);
			}
		} else {
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v6, 4u);
			nox_xxx_journalQuestSet_500540(v8, v6);
		}
	}
	return 1;
}
// 500B70: using guessed type char var_100[256];

//----- (00500C70) --------------------------------------------------------
int  sub_500C70(int a1, int a2) {
	*((_DWORD*)nox_common_playerInfoFromNum_417090(a1) + 912) = a2;
	return nox_xxx_netCreatureCmd_4D7EE0(a1, a2);
}

//----- (00500CA0) --------------------------------------------------------
int  sub_500CA0(int a1, int a2) {
	int result; // eax

	if (a2 && *(_BYTE*)(a2 + 8) & 4)
		result = *getMemU32Ptr(0x587000, 4 * a1 + 217668);
	else
		result = 0;
	return result;
}

//----- (00500CC0) --------------------------------------------------------
int  nox_xxx_creatureIsMonitored_500CC0(int a1, int a2) {
	int v2;     // eax
	int result; // eax

	if ((*(_BYTE*)(a2 + 8) & 2 && (v2 = *(_DWORD*)(a2 + 16), (v2 & 0x8000) == 0) || nox_xxx_unitIsZombie_534A40(a2)) &&
		(*(_BYTE*)(*(_DWORD*)(a2 + 748) + 1440) & 0x80)) {
		result = nox_xxx_unitHasThatParent_4EC4F0(a2, a1);
	} else {
		result = 0;
	}
	return result;
}

//----- (00500D10) --------------------------------------------------------
int  nox_xxx_countControlledCreatures_500D10(int a1) {
	int v1; // esi
	int i;  // edi

	v1 = *(_DWORD*)(a1 + 516);
	for (i = 0; v1; v1 = *(_DWORD*)(v1 + 512)) {
		if (nox_xxx_creatureIsMonitored_500CC0(a1, v1))
			i += sub_500D50(v1);
	}
	return i;
}

//----- (00500D50) --------------------------------------------------------
int  sub_500D50(int a1) {
	int v1; // eax
	int v3; // eax

	v1 = *(_DWORD*)(a1 + 12);
	if (v1 & 1)
		return 1;
	v3 = -((v1 & 2) != 0);
	LOBYTE(v3) = v3 & 0xFE;
	return v3 + 4;
}

//----- (00500D70) --------------------------------------------------------
bool  nox_xxx_checkSummonedCreaturesLimit_500D70(int a1, int a2) {
	int v2; // ebx

	v2 = nox_xxx_guideGetUnitSize_427460(a2);
	return nox_xxx_countControlledCreatures_500D10(a1) + v2 <= 4;
}

//----- (00500DA0) --------------------------------------------------------
int  nox_xxx_summonStart_500DA0(int a1) {
	int v1;                  // eax
	int v2;                  // edi
	int v3;                  // ebp
	BYTE v5;                 // eax
	char* v6;                // eax
	int v7;                  // eax
	int v8;                  // edx
	int v9;                  // eax
	int v10;                 // eax
	double v11;              // st7
	int v12;                 // eax
	int v13;                 // ecx
	char v14;                // al
	float v15;               // [esp+0h] [ebp-20h]
	__int16 v16;             // [esp+0h] [ebp-20h]
	unsigned __int8 v17[16]; // [esp+10h] [ebp-10h]

	v1 = *(_DWORD*)(a1 + 16);
	v2 = *(_DWORD*)(a1 + 4) - 74;
	if (!v1 || *(_DWORD*)(v1 + 16) & 0x8020 || *(_DWORD*)(a1 + 20))
		return 1;
	if (*(_BYTE*)(v1 + 8) & 4) {
		v3 = *(_DWORD*)(v1 + 748);
		if (nox_common_gameFlags_check_40A5C0(4608) && !*(_DWORD*)(*(_DWORD*)(v3 + 276) + 4 * v2 + 4244)) {
			nox_xxx_netPriMsgToPlayer_4DA2C0(*(_DWORD*)(a1 + 16), "Summon.c:NeedGuideToSummon", 0);
			return 1;
		}
		v5 = nox_xxx_checkSummonedCreaturesLimit_500D70(*(_DWORD*)(a1 + 16), v2);
		if (!v5) {
			nox_xxx_netPriMsgToPlayer_4DA2C0(*(_DWORD*)(a1 + 16), "Summon.c:CreatureControlFailed", 0);
			return 1;
		}
	}
	if (!sub_500F40(a1, COERCE_FLOAT(&v17[2])))
		return 1;
	v17[10] = *(_BYTE*)(*(_DWORD*)(a1 + 16) + 124);
	v6 = nox_xxx_guideNameByN_427230(v2);
	*(_WORD*)v17 = nox_xxx_getNameId_4E3AA0(v6);
	*(_WORD*)&v17[11] = (*getMemU16Ptr(0x5D4594, 1570276))++;
	if (*getMemU16Ptr(0x5D4594, 1570276) >= 0xFDE8u)
		*getMemU16Ptr(0x5D4594, 1570276) = 0;
	v7 = *(_DWORD*)&v17[4];
	v17[13] = 0;
	*(_DWORD*)(a1 + 72) = *(_DWORD*)v17;
	v8 = *(_DWORD*)&v17[8];
	*(_DWORD*)(a1 + 76) = v7;
	LOWORD(v7) = *(_WORD*)&v17[12];
	*(_DWORD*)(a1 + 80) = v8;
	*(_WORD*)(a1 + 84) = v7;
	v9 = nox_xxx_guideGetUnitSize_427460(v2) - 1;
	if (v9) {
		v10 = v9 - 1;
		if (v10) {
			if (v10 != 2) {
				v12 = a1;
				goto LABEL_22;
			}
			v11 = nox_xxx_loadFloatVar_419D70(getMemAt(0x587000, 218220), 2);
		} else {
			v11 = nox_xxx_loadFloatVar_419D70(getMemAt(0x587000, 218204), 1);
		}
	} else {
		v11 = nox_xxx_loadFloatVar_419D70(getMemAt(0x587000, 218188), 0);
	}
	v15 = v11;
	v12 = nox_float2int(v15);
LABEL_22:
	v13 = v12 + *getMemU32Ptr(0x5D4594, 2598000);
	v16 = v12;
	v14 = v17[10];
	*(_DWORD*)(a1 + 68) = v13;
	nox_xxx_sendSummonStartFX_5236F0(*(__int16*)&v17[11], (float*)&v17[2], v14, *(__int16*)v17, v16);
	return 0;
}
// 500E24: variable 'v5' is possibly undefined

//----- (00500F40) --------------------------------------------------------
int  sub_500F40(int a1, float a2) {
	_DWORD* v2;     // esi
	int v3;         // eax
	float v4;       // edi
	float v5;       // edx
	float v6;       // ecx
	double v7;      // st7
	double v8;      // st6
	long double v9; // st6
	float v10;      // edx
	int result;     // eax
	int v12;        // esi
	int v13;        // esi
	float v14;      // edx
	float v15;      // eax
	float v16;      // ecx
	int v17;        // eax
	int v18;        // edx
	float4 v19;     // [esp+8h] [ebp-10h]

	v2 = (_DWORD*)a1;
	if (*(float*)&a1 == 0.0)
		return 0;
	v3 = *(_DWORD*)(a1 + 16);
	if (!v3)
		return 0;
	v4 = a2;
	if (a2 == 0.0)
		return 0;
	if (*(_BYTE*)(v3 + 8) & 4) {
		v19.field_0 = *(float*)(v3 + 56);
		v5 = *(float*)(v3 + 60);
		v6 = *(float*)(a1 + 56);
		v19.field_8 = *(float*)(a1 + 52);
		v19.field_C = v6;
		v7 = v19.field_8 - v19.field_0;
		v19.field_4 = v5;
		v8 = v6 - v5;
		*(float*)&a1 = v8;
		v9 = sqrt(v8 * *(float*)&a1 + v7 * v7);
		a2 = v9;
		if (v9 > 50.0) {
			v19.field_8 = v7 * 50.0 / a2 + v19.field_0;
			v19.field_C = *(float*)&a1 * 50.0 / a2 + v19.field_4;
		}
		if (nox_xxx_mapTraceRay_535250(&v19, 0, 0, 9) && !nox_xxx_mapTileAllowTeleport_411A90((float2*)&v19.field_8)) {
			v10 = v19.field_C;
			*(_DWORD*)LODWORD(v4) = LODWORD(v19.field_8);
			*(float*)(LODWORD(v4) + 4) = v10;
			return 1;
		}
		v12 = v2[4];
		if (*(_BYTE*)(v12 + 8) & 4) {
			v13 = *(_DWORD*)(v12 + 748);
			a1 = 2;
			nox_xxx_netInformTextMsg_4DA0F0(*(unsigned __int8*)(*(_DWORD*)(v13 + 276) + 2064), 0, &a1);
		}
		return 0;
	}
	v19.field_0 = *(float*)(v3 + 56);
	v14 = *(float*)(v3 + 60);
	v15 = *(float*)(a1 + 52);
	v16 = *(float*)(a1 + 56);
	v19.field_4 = v14;
	v19.field_8 = v15;
	v19.field_C = v16;
	if (nox_xxx_mapTraceRay_535250(&v19, 0, 0, 9)) {
		*(_DWORD*)LODWORD(v4) = v2[13];
		*(_DWORD*)(LODWORD(v4) + 4) = v2[14];
		result = 1;
	} else {
		v17 = v2[4];
		*(_DWORD*)LODWORD(v4) = *(_DWORD*)(v17 + 56);
		v18 = *(_DWORD*)(v17 + 60);
		result = 1;
		*(_DWORD*)(LODWORD(v4) + 4) = v18;
	}
	return result;
}

//----- (005010D0) --------------------------------------------------------
int  nox_xxx_summonFinish_5010D0(int a1) {
	int v1;     // eax
	int v2;     // edi
	int v3;     // ebx
	int result; // eax
	BYTE v5;    // eax
	_DWORD* v6; // eax

	v1 = *(_DWORD*)(a1 + 16);
	if (!v1 || *(_DWORD*)(v1 + 16) & 0x8020)
		return 1;
	if (*(_DWORD*)(a1 + 68) - 1 != *getMemU32Ptr(0x5D4594, 2598000))
		return 0;
	v2 = *(_DWORD*)(a1 + 4) - 74;
	if (!(*(_BYTE*)(v1 + 8) & 4))
		goto LABEL_17;
	v3 = *(_DWORD*)(v1 + 748);
	if (nox_common_gameFlags_check_40A5C0(512) && !*(_DWORD*)(*(_DWORD*)(v3 + 276) + 4 * v2 + 4244)) {
		nox_xxx_netPriMsgToPlayer_4DA2C0(*(_DWORD*)(a1 + 16), "Summon.c:NeedGuideToSummon", 0);
		return 1;
	}
	v5 = nox_xxx_checkSummonedCreaturesLimit_500D70(*(_DWORD*)(a1 + 16), v2);
	if (v5) {
	LABEL_17:
		v6 = nox_xxx_unitDoSummonAt_5016C0(*(unsigned __int16*)(a1 + 72), (int*)(a1 + 74), *(_DWORD*)(a1 + 16), *(_BYTE*)(a1 + 82));
		if (v6)
			nox_xxx_aud_501960(899, (int)v6, 0, 0);
		*(_BYTE*)(a1 + 85) = 1;
		result = 1;
	} else {
		nox_xxx_netPriMsgToPlayer_4DA2C0(*(_DWORD*)(a1 + 16), "Summon.c:CreatureControlFailed", 0);
		result = 1;
	}
	return result;
}
// 50115B: variable 'v5' is possibly undefined

//----- (005011C0) --------------------------------------------------------
void  nox_xxx_summonCancel_5011C0(int a1) {
	if (!*(_BYTE*)(a1 + 85)) {
		nox_xxx_sendSummonCancelFX_523760(*(_WORD*)(a1 + 83));
		nox_xxx_audCreate_501A30(900, (float2*)(a1 + 74), 0, 0);
	}
}

//----- (005011F0) --------------------------------------------------------
int  nox_xxx_charmCreature1_5011F0(int* a1) {
	__int16 v1; // ax
	int v3;     // eax
	int v4;     // eax
	int v5;     // eax
	int v6;     // ecx
	int v7;     // eax
	int v8;     // eax
	double v9;  // st7
	int* v10;   // eax
	int v11;    // edx
	int v12;    // [esp-14h] [ebp-1Ch]
	int v13;    // [esp-8h] [ebp-10h]
	float v14;  // [esp+0h] [ebp-8h]
	int v15;    // [esp+0h] [ebp-8h]
	float v16;  // [esp+0h] [ebp-8h]

	if (a1[5]) {
		v14 = nox_xxx_gamedataGetFloat_419D40(getMemAt(0x587000, 218296));
		v1 = nox_float2int(v14);
		nox_xxx_buffApplyTo_4FF380(a1[12], 3, v1, a1[2]);
		sub_4E7540(a1[4], a1[12]);
		return 1;
	}
	v15 = a1[4];
	v3 = nox_xxx_spellGetFlags_424A70(a1[1]);
	v4 = nox_xxx_spellFlySearchTarget_540610((float2*)(a1 + 13), a1[4], v3, 300.0, 0, v15);
	a1[12] = v4;
	if (!v4) {
		nox_xxx_netPriMsgToPlayer_4DA2C0(a1[4], "Summon.c:CharmNoCreatureCloseEnough", 0);
		nox_xxx_aud_501960(16, a1[4], 0, 0);
		return 1;
	}
	if (*(_BYTE*)(v4 + 8) & 2 && !nox_xxx_creatureIsMonitored_500CC0(a1[4], v4)) {
		v5 = nox_xxx_creatureIsCharmableByTT_4272B0(*(unsigned __int16*)(a1[12] + 4));
		v6 = a1[4];
		if (*(_BYTE*)(v6 + 8) & 4) {
			if (!v5) {
				nox_xxx_netPriMsgToPlayer_4DA2C0(v6, "Summon.c:CreatureNotCharmable", 0);
				v12 = a1[4];
				a1[12] = 0;
				nox_xxx_aud_501960(16, v12, 0, 0);
				return 1;
			}
			if (!*(_DWORD*)(*(_DWORD*)(*(_DWORD*)(v6 + 748) + 276) + 4 * v5 + 4244)) {
				a1[12] = 0;
				nox_xxx_netPriMsgToPlayer_4DA2C0(v6, "Summon.c:NeedGuideToCharm", 0);
				nox_xxx_aud_501960(16, a1[4], 0, 0);
				return 1;
			}
		}
		v7 = nox_xxx_guideGetUnitSize_427460(v5) - 1;
		if (v7) {
			v8 = v7 - 1;
			if (v8) {
				if (v8 != 2) {
					v10 = a1;
					goto LABEL_20;
				}
				v9 = nox_xxx_loadFloatVar_419D70(getMemAt(0x587000, 218456), a1[2] - 1);
			} else {
				v9 = nox_xxx_loadFloatVar_419D70(getMemAt(0x587000, 218436), a1[2] - 1);
			}
		} else {
			v9 = nox_xxx_loadFloatVar_419D70(getMemAt(0x587000, 218416), a1[2] - 1);
		}
		v16 = v9;
		v10 = (int*)nox_float2int(v16);
	LABEL_20:
		v11 = a1[12];
		a1[17] = (int)v10 + *getMemU32Ptr(0x5D4594, 2598000);
		nox_xxx_buffApplyTo_4FF380(v11, 28, (_WORD)v10 + 1, 5);
		nox_xxx_netStartDurationRaySpell_4FF130((int)a1);
		return 0;
	}
	v13 = a1[4];
	a1[12] = 0;
	nox_xxx_aud_501960(16, v13, 0, 0);
	return 1;
}

//----- (005013E0) --------------------------------------------------------
int  nox_xxx_charmCreatureFinish_5013E0(int* a1) {
	int v1;               // eax
	int v2;               // eax
	int v4;               // eax
	int v5;               // ecx
	int v6;               // eax
	BYTE v7;              // eax
	int v8;               // eax
	int v9;               // ecx
	int v10;              // edi
	int v11;              // eax
	int v12;              // ebp
	unsigned __int16 v13; // ax
	int v14;              // edi
	unsigned __int16 v15; // di
	int v16;              // eax
	int v17;              // edi
	int v18;              // eax
	int v19;              // edx
	int v20;              // eax
	int v21;              // ecx
	int v22;              // eax
	int v23;              // [esp-10h] [ebp-14h]

	v1 = a1[12];
	if (!v1 || *(_DWORD*)(v1 + 16) & 0x8020)
		goto LABEL_6;
	if (nox_xxx_calcDistance_4E6C00(a1[4], a1[12]) > 300.0) {
		v2 = a1[4];
		if (*(_BYTE*)(v2 + 8) & 4)
			nox_xxx_netPriMsgToPlayer_4DA2C0(v2, "Summon.c:CharmBrokenDistance", 0);
	LABEL_6:
		nox_xxx_aud_501960(16, a1[4], 0, 0);
		return 1;
	}
	if (a1[17] - 1 != *getMemU32Ptr(0x5D4594, 2598000))
		return 0;
	v4 = a1[12];
	v5 = *(_DWORD*)(v4 + 12);
	if (v5 & 0x2000) {
		nox_xxx_netPriMsgToPlayer_4DA2C0(a1[4], "Summon.c:CreatureControlImpossible", 0);
	LABEL_13:
		nox_xxx_aud_501960(16, a1[4], 0, 0);
		return 1;
	}
	if (*(_BYTE*)(a1[4] + 8) & 4) {
		v6 = nox_xxx_creatureIsCharmableByTT_4272B0(*(unsigned __int16*)(v4 + 4));
		v7 = nox_xxx_checkSummonedCreaturesLimit_500D70(a1[4], v6);
		if (!v7) {
			nox_xxx_netPriMsgToPlayer_4DA2C0(a1[4], "Summon.c:CreatureControlFailed", 0);
			goto LABEL_13;
		}
	}
	nox_xxx_spellBuffOff_4FF5B0(a1[12], 28);
	v8 = nox_xxx_findParentChainPlayer_4EC580(a1[12]);
	v9 = a1[4];
	if (v8 == v9) {
		if (*(_BYTE*)(v9 + 8) & 4)
			nox_xxx_netPriMsgToPlayer_4DA2C0(v9, "Summon.c:CreatureAlreadyOwned", 0);
		goto LABEL_6;
	}
	nox_xxx_unitClearOwner_4EC300(a1[12]);
	nox_xxx_unitSetOwner_4EC290(a1[4], a1[12]);
	if (nox_xxx_servObjectHasTeam_419130(a1[12] + 48))
		nox_xxx_netChangeTeamMb_419570(a1[12] + 48, *(_DWORD*)(a1[12] + 36));
	v10 = *(_DWORD*)(a1[12] + 748);
	v11 = *(_DWORD*)(v10 + 1440);
	LOBYTE(v11) = v11 | 0x80;
	*(_DWORD*)(v10 + 1440) = v11;
	if (nox_common_gameFlags_check_40A5C0(4096)) {
		v12 = nox_xxx_unitDefGet_4E3B70(*(unsigned __int16*)(a1[12] + 4));
		v13 = nox_xxx_unitGetHP_4EE780(a1[12]);
		v14 = *(_DWORD*)(v10 + 484);
		v15 = v14 ? *(_WORD*)(v14 + 72) : *(_WORD*)(*(_DWORD*)(v12 + 136) + 4);
		*(_WORD*)(*(_DWORD*)(a1[12] + 556) + 4) = v15;
		if (v13 > v15)
			nox_xxx_unitSetHP_4E4560(a1[12], v15);
	}
	v16 = a1[4];
	if (*(_BYTE*)(v16 + 8) & 4) {
		v17 = *(_DWORD*)(v16 + 748);
		nox_xxx_orderUnit_533900(v16, a1[12], *(_DWORD*)(*(_DWORD*)(v17 + 276) + 3648));
		v18 = a1[12];
		v19 = *(_DWORD*)(v18 + 12);
		LOBYTE(v19) = v19 | 0x80;
		*(_DWORD*)(v18 + 12) = v19;
		v20 = a1[12];
		v21 = *(_DWORD*)(v20 + 12);
		BYTE1(v21) |= 1u;
		*(_DWORD*)(v20 + 12) = v21;
		nox_xxx_netReportAcquireCreature_4D91A0(*(unsigned __int8*)(*(_DWORD*)(v17 + 276) + 2064), a1[12]);
		nox_xxx_netMarkMinimapObject_417190(*(unsigned __int8*)(*(_DWORD*)(v17 + 276) + 2064), a1[12], 1);
		nox_xxx_netSendSimpleObject2_4DF360(*(unsigned __int8*)(*(_DWORD*)(v17 + 276) + 2064), a1[12]);
		if (nox_common_gameFlags_check_40A5C0(4096))
			sub_50E140(a1[12]);
	} else {
		nox_xxx_orderUnit_533900(v16, a1[12], 4);
	}
	v23 = a1[4];
	v22 = nox_xxx_spellGetAud44_424800(a1[1], 1);
	nox_xxx_aud_501960(v22, v23, 0, 0);
	return 1;
}
// 50148A: variable 'v7' is possibly undefined

//----- (00501690) --------------------------------------------------------
int  nox_xxx_charmCreature2_501690(int a1) {
	int result; // eax

	result = *(_DWORD*)(a1 + 48);
	if (result) {
		if (!(*(_DWORD*)(result + 16) & 0x8020)) {
			nox_xxx_spellBuffOff_4FF5B0(result, 5);
			result = nox_xxx_spellBuffOff_4FF5B0(*(_DWORD*)(a1 + 48), 28);
		}
	}
	return result;
}

//----- (005016C0) --------------------------------------------------------
_DWORD*  nox_xxx_unitDoSummonAt_5016C0(int a1, int* a2, int a3, unsigned __int8 a4) {
	_DWORD* result; // eax
	_DWORD* v5;     // esi
	int v6;         // ebp
	int v7;         // ecx
	int v8;         // ebx
	int v9;         // eax

	result = nox_new_objMem_2_4E3450(a1);
	v5 = result;
	if (!result)
		return result;
	nox_xxx_createAt_4DAA50((int)result, a3, *(float*)a2, *((float*)a2 + 1));
	v6 = v5[187];
	*((_WORD*)v5 + 63) = a4;
	*((_WORD*)v5 + 62) = a4;
	v7 = *(_DWORD*)(v6 + 1440);
	LOBYTE(v7) = v7 | 0x80;
	*(_DWORD*)(v6 + 1440) = v7;
	if (!a3)
		return v5;
	if (!(*(_BYTE*)(a3 + 8) & 4)) {
		nox_xxx_orderUnit_533900(a3, (int)v5, 4);
		*(_DWORD*)(v6 + 1360) = 38;
		return v5;
	}
	v8 = *(_DWORD*)(a3 + 748);
	nox_xxx_orderUnit_533900(a3, (int)v5, *(_DWORD*)(*(_DWORD*)(v8 + 276) + 3648));
	*(_DWORD*)(v6 + 1360) = 38;
	v5[3] |= 0x80u;
	nox_xxx_netReportAcquireCreature_4D91A0(*(unsigned __int8*)(*(_DWORD*)(v8 + 276) + 2064), (int)v5);
	nox_xxx_netMarkMinimapObject_417190(*(unsigned __int8*)(*(_DWORD*)(v8 + 276) + 2064), (int)v5, 1);
	nox_xxx_netSendSimpleObject2_4DF360(*(unsigned __int8*)(*(_DWORD*)(v8 + 276) + 2064), (int)v5);
	if (nox_xxx_servObjectHasTeam_419130(a3 + 48))
		nox_xxx_createAtImpl_4191D0(*(_BYTE*)(a3 + 52), a3 + 48, 1, v5[9], 0);
	v9 = v5[3];
	BYTE1(v9) |= 1u;
	v5[3] = v9;
	return v5;
}

//----- (005017F0) --------------------------------------------------------
void  sub_5017F0(int a1) {
	int v1; // eax
	int v2; // esi

	if (!*getMemU32Ptr(0x5D4594, 1570280))
		*getMemU32Ptr(0x5D4594, 1570280) = nox_xxx_getNameId_4E3AA0("Glyph");
	if (a1) {
		v1 = *(_DWORD*)(a1 + 504);
		if (v1) {
			do {
				v2 = *(_DWORD*)(v1 + 496);
				if (*(unsigned __int16*)(v1 + 4) == *getMemU32Ptr(0x5D4594, 1570280))
					nox_xxx_delayedDeleteObject_4E5CC0(v1);
				v1 = v2;
			} while (v2);
		}
		nox_xxx_netSendPointFx_522FF0(129, (float2*)(a1 + 56));
		nox_xxx_delayedDeleteObject_4E5CC0(a1);
	}
}

//----- (00501860) --------------------------------------------------------
int nox_xxx_allocAudEventArray_501860() {
	int result;          // eax
	unsigned __int8* v1; // eax

	if (dword_5d4594_1599064)
		return 1;
	*getMemU32Ptr(0x5D4594, 1599056) = nox_new_alloc_class("AudEvent", 36, 128);
	if (!*getMemU32Ptr(0x5D4594, 1599056))
		return 0;
	v1 = getMemAt(0x5D4594, 1570292);
	do {
		*((_DWORD*)v1 - 2) = 600;
		*(_DWORD*)v1 = 0;
		*((_DWORD*)v1 + 1) = 0;
		*((_DWORD*)v1 + 2) = 0;
		*((_DWORD*)v1 + 3) = 0;
		*((_DWORD*)v1 + 4) = 0;
		v1 += 28;
	} while ((int)v1 < (int)getMemAt(0x5D4594, 1598928 + 8));
	result = 1;
	dword_5d4594_1599064 = 1;
	return result;
}

//----- (005018D0) --------------------------------------------------------
void sub_5018D0() {
	if (dword_5d4594_1599064) {
		nox_free_alloc_class(*(LPVOID*)getMemAt(0x5D4594, 1599056));
		dword_5d4594_1599060 = 0;
		dword_5d4594_1599064 = 0;
	}
}

//----- (00501900) --------------------------------------------------------
int  sub_501900(int a1) { return *getMemU32Ptr(0x5D4594, 28 * a1 + 1570288); }

//----- (00501920) --------------------------------------------------------
int  sub_501920(int a1) { return *getMemU32Ptr(0x5D4594, 28 * a1 + 1570284); }

//----- (00501940) --------------------------------------------------------
int  nox_xxx_getSevenDwords3_501940(int a1) { return *getMemU32Ptr(0x5D4594, 28 * a1 + 1570296); }

//----- (00501960) --------------------------------------------------------
_DWORD*  nox_xxx_aud_501960(int a1, int a2, int a3, int a4) {
	_DWORD* result; // eax
	_DWORD* v5;     // esi

	result = (_DWORD*)nox_common_gameFlags_check_40A5C0(0x80000);
	if (result != (_DWORD*)1) {
		if (a2) {
			if (a1) {
				result = (_DWORD*)nox_xxx_getSevenDwords3_501940(a1);
				if ((int)result > 0) {
					if (!nox_common_gameFlags_check_40A5C0(4096) || !(*(_BYTE*)(a2 + 8) & 4) ||
						(result = (_DWORD*)sub_419E60(a2)) == 0) {
						result = nox_alloc_class_new_obj_zero(*(_DWORD**)getMemAt(0x5D4594, 1599056));
						v5 = result;
						if (result) {
							result[1] = a1;
							if (*(_BYTE*)(a2 + 16) & 0x20)
								result[4] = 0;
							else
								result[4] = a2;
							result[2] = *(_DWORD*)(a2 + 56);
							result[3] = *(_DWORD*)(a2 + 60);
							result[5] = a3;
							result[6] = a4;
							if (a3 != 2)
								nox_xxx_audioAddAIInteresting_50CD40(a1, a2, (_DWORD*)(a2 + 56));
							result = *(_DWORD**)&dword_5d4594_1599060;
							*v5 = dword_5d4594_1599060;
							dword_5d4594_1599060 = v5;
						}
					}
				}
			}
		}
	}
	return result;
}

//----- (00501A30) --------------------------------------------------------
void  nox_xxx_audCreate_501A30(int a1, float2* a2, int a3, int a4) {
	int* v4; // esi

	if (!nox_common_gameFlags_check_40A5C0(0x80000)) {
		if (a1) {
			if (nox_xxx_getSevenDwords3_501940(a1) > 0) {
				v4 = (int*)nox_alloc_class_new_obj_zero(*(_DWORD**)getMemAt(0x5D4594, 1599056));
				if (v4) {
					v4[1] = a1;
					*((float2*)v4 + 1) = *a2;
					v4[4] = 0;
					v4[5] = a3;
					v4[6] = a4;
					if (a3 != 2)
						nox_xxx_audioAddAIInteresting_50CD40(a1, 0, a2);
					*v4 = dword_5d4594_1599060;
					dword_5d4594_1599060 = v4;
				}
			}
		}
	}
}

//----- (00501AC0) --------------------------------------------------------
int  nox_xxx_gameSetAudioFadeoutMb_501AC0(int a1) {
	int result; // eax

	result = a1;
	if (a1 >= 0) {
		if (a1 > 100)
			result = 100;
		dword_5d4594_1599068 = result;
	} else {
		result = 0;
		dword_5d4594_1599068 = 0;
	}
	return result;
}

//----- (00501AE0) --------------------------------------------------------
int sub_501AE0() { return dword_5d4594_1599068; }

//----- (00501AF0) --------------------------------------------------------
int  sub_501AF0(int a1, float* a2, float* a3) {
	float* v3; // eax
	int v4;    // esi
	double v5; // st7
	int v6;    // eax
	int v7;    // eax
	int v9;    // [esp+Ch] [ebp-4h]
	float v10; // [esp+14h] [ebp+4h]
	float v11; // [esp+18h] [ebp+8h]

	v3 = a2;
	v4 = *getMemU32Ptr(0x5D4594, 28 * a1 + 1570284);
	v9 = *getMemU32Ptr(0x5D4594, 28 * a1 + 1570284);
	v11 = *a2 - *a3;
	v10 = v3[1] - a3[1];
	v5 = (double)v9;
	if (v11 >= v5)
		return 0;
	if (v10 >= v5)
		return 0;
	if (v4 <= 0)
		return 0;
	v6 = nox_double2int(sqrt(v10 * v10 + v11 * v11 + 0.1));
	if (v6 >= v4)
		return 0;
	v7 = 100 * (v4 - v6) / v4;
	if (v7 <= 100) {
		if (v7 < 0)
			v7 = 0;
	} else {
		v7 = 100;
	}
	return v7 <= *(int*)&dword_5d4594_1599068 ? 0 : v7;
}

//----- (00501BB0) --------------------------------------------------------
unsigned int  nox_xxx_unused_501BB0(int a1, float* a2, float* a3) {
	int v3; // eax
	int v4; // ecx

	v3 = sub_501AF0(a1, a2, a3);
	v4 = *getMemU32Ptr(0x5D4594, 28 * a1 + 1570292);
	if (!v4)
		return 0;
	return (v3 * v4) / 100;
}

//----- (00501C00) --------------------------------------------------------
char  sub_501C00(float* a1, int a2) {
	char v2;      // bl
	int v3;       // ecx
	char* v4;     // eax
	int v5;       // eax
	float v6;     // ecx
	struc_19* v7; // eax
	int2 v9;      // [esp+4h] [ebp-8h]

	v2 = 0;
	if (a2) {
		v3 = *(_DWORD*)(a2 + 8);
		if (v3 & 4) {
			v2 = *(_BYTE*)(*(_DWORD*)(*(_DWORD*)(a2 + 748) + 276) + 3668);
			goto LABEL_7;
		}
		if (v3 & 2) {
			v4 = nox_xxx_polygonGetByIdx_4214A0(**(_DWORD**)(a2 + 748));
			if (v4) {
				v2 = v4[130];
			LABEL_7:
				if (v2)
					return v2;
				goto LABEL_8;
			}
		}
	}
LABEL_8:
	v5 = nox_float2int(*a1);
	v6 = a1[1];
	v9.field_0 = v5;
	v9.field_4 = nox_float2int(v6);
	v7 = nox_xxx_polygonIsPlayerInPolygon_4217B0(&v9, 0);
	if (v7)
		return BYTE2(v7->field_0[32]);
	return v2;
}

//----- (00501CA0) --------------------------------------------------------
int  nox_xxx_netUpdateRemotePlr_501CA0(int a1) {
	int v1;       // ebx
	int v2;       // ebp
	int v3;       // eax
	int v4;       // ecx
	int v5;       // ecx
	int v6;       // eax
	int v7;       // edx
	struc_19* v8; // eax
	int i;        // esi
	int v10;      // eax
	char* v11;    // eax
	char v12;     // al
	int v13;      // eax
	int v14;      // eax
	char* v16;    // [esp+Ch] [ebp-Ch]
	int2 v17;     // [esp+10h] [ebp-8h]
	char v18;     // [esp+1Ch] [ebp+4h]

	v1 = a1;
	v2 = *(_DWORD*)(a1 + 748);
	v16 = 0;
	v3 = *(_DWORD*)(v2 + 276);
	if (!(*(_BYTE*)(v3 + 3680) & 3) || (v4 = *(_DWORD*)(v3 + 3628)) == 0) {
		if (*(int*)(v3 + 3664) == -559023410)
			nox_xxx_questCheckSecretArea_421C70(a1);
		v5 = *(_DWORD*)(v2 + 276);
		goto LABEL_11;
	}
	if (*(_BYTE*)(v4 + 8) & 4) {
		v5 = *(_DWORD*)(*(_DWORD*)(v4 + 748) + 276);
	LABEL_11:
		v18 = *(_BYTE*)(v5 + 3668);
		goto LABEL_12;
	}
	v6 = nox_float2int(*(float*)(*(_DWORD*)(v3 + 3628) + 56));
	v7 = *(_DWORD*)(v2 + 276);
	v17.field_0 = v6;
	v17.field_4 = nox_float2int(*(float*)(*(_DWORD*)(v7 + 3628) + 60));
	v8 = nox_xxx_polygonIsPlayerInPolygon_4217B0(&v17, 0);
	if (v8)
		v18 = BYTE2(v8->field_0[32]);
	else
		v18 = 0;
LABEL_12:
	sub_501E80();
	if (nox_xxx_servObjectHasTeam_419130(v1 + 48))
		v16 = nox_xxx_clientGetTeamColor_418AB0(*(unsigned __int8*)(v1 + 52));
	for (i = dword_5d4594_1599060; i; i = *(_DWORD*)i) {
		v10 = *(_DWORD*)(i + 20);
		if (v10 == 1) {
			v11 = nox_xxx_clientGetTeamColor_418AB0(*(_DWORD*)(i + 24));
			if (v16 && v11 && v16 == v11)
				goto LABEL_22;
		} else if (v10 != 2 || *(_DWORD*)(v1 + 36) == *(_DWORD*)(i + 24)) {
		LABEL_22:
			v12 = sub_501C00((float*)(i + 8), *(_DWORD*)(i + 16));
			if (v12 == v18 || !v12) {
				if (*(_BYTE*)(v2 + 188) || (v13 = *(_DWORD*)(i + 4), v13 < 186) || v13 > 193 ||
					v1 != *(_DWORD*)(i + 16)) {
					v14 = sub_501AF0(*(_DWORD*)(i + 4), (float*)(i + 8), (float*)(*(_DWORD*)(v2 + 276) + 3632)) >> 1;
					if (v14 > 0) {
						if (*getMemU32Ptr(0x5D4594, 28 * *(_DWORD*)(i + 4) + 1570304))
							sub_501EA0((_DWORD*)i, v14);
						else
							sub_501FD0(v1, i, v14);
					}
				}
			}
			continue;
		}
	}
	return sub_502060(v1);
}

//----- (00501E80) --------------------------------------------------------
int sub_501E80() {
	int result; // eax

	result = 0;
	memset(getMemAt(0x5D4594, 1598928), 0, 0x80u);
	return result;
}

//----- (00501EA0) --------------------------------------------------------
_DWORD*  sub_501EA0(_DWORD* a1, int a2) {
	unsigned int v2; // esi

	v2 = a1[1];
	if (!sub_501EF0(v2)) {
		sub_501F10(v2);
		*getMemU32Ptr(0x5D4594, 28 * v2 + 1570308) = 0;
	}
	a1[8] = a2;
	return sub_501F30((int)getMemAt(0x5D4594, 28 * v2 + 1570284), a1);
}

//----- (00501EF0) --------------------------------------------------------
int  sub_501EF0(unsigned int a1) { return *getMemU32Ptr(0x5D4594, 1598928 + 4 * (a1 >> 5)) & (1 << (a1 & 0x1F)); }

//----- (00501F10) --------------------------------------------------------
unsigned int  sub_501F10(unsigned int a1) {
	unsigned int result; // eax

	result = a1 >> 5;
	*getMemU32Ptr(0x5D4594, 1598928 + 4 * (a1 >> 5)) |= 1 << (a1 & 0x1F);
	return result;
}

//----- (00501F30) --------------------------------------------------------
_DWORD*  sub_501F30(int a1, _DWORD* a2) {
	_DWORD* result; // eax
	_DWORD* v3;     // ebp
	int v4;         // ebx
	int v5;         // esi
	int v6;         // edx
	int v7;         // ecx
	_DWORD* v8;     // [esp+10h] [ebp-4h]

	result = *(_DWORD**)(a1 + 24);
	v3 = *(_DWORD**)(a1 + 24);
	v8 = *(_DWORD**)(a1 + 24);
	if (result) {
		v4 = 1;
		v5 = a2[8];
		do {
			v6 = result[8];
			v7 = v5 - v6;
			if (v5 - v6 < 0)
				v7 = v6 - v5;
			if (v7 >= 5) {
				if (v5 > v6)
					break;
			} else if (getMemByte(0x5D4594, 28 * a2[1] + 1570300) & 0x10) {
				break;
			}
			if (++v4 > *(int*)(a1 + 20))
				return result;
			v3 = result;
			result = (_DWORD*)result[7];
		} while (result);
		a2[7] = result;
		if (result == v8)
			*(_DWORD*)(a1 + 24) = a2;
		else
			v3[7] = a2;
	} else {
		result = a2;
		a2[7] = v3;
		*(_DWORD*)(a1 + 24) = a2;
	}
	return result;
}

//----- (00501FD0) --------------------------------------------------------
int  sub_501FD0(int a1, int a2, __int16 a3) {
	int v3;     // esi
	double v4;  // st7
	__int16 v5; // dx
	float v7;   // [esp+0h] [ebp-Ch]

	v3 = *(_DWORD*)(a1 + 748);
	v4 = *(float*)(a2 + 8);
	v5 = *(_WORD*)(a2 + 4) | (a3 << 10);
	LOBYTE(a1) = (a1 == *(_DWORD*)(a2 + 16)) - 90;
	HIWORD(a1) = v5;
	v7 = v4 - *(float*)(*(_DWORD*)(v3 + 276) + 3632);
	BYTE1(a1) = 50 * nox_float2int(v7) / (nox_win_width / 2);
	return nox_xxx_netAddToMsgListCli_40EBC0(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), 1, &a1, 4);
}

//----- (00502060) --------------------------------------------------------
int  sub_502060(int a1) {
	int* v1;             // ecx
	int v2;              // ebx
	int result;          // eax
	int v4;              // edi
	int v5;              // esi
	int i;               // ebp
	int v7;              // edx
	unsigned int v8;     // [esp+10h] [ebp-8h]
	unsigned __int8* v9; // [esp+14h] [ebp-4h]

	v1 = getMemIntPtr(0x5D4594, 1598928);
	v2 = 0;
	v9 = getMemAt(0x5D4594, 1598928);
	do {
		result = *v1;
		v8 = *v1;
		if (*v1) {
			v4 = 0;
			do {
				if (result & 1) {
					v5 = *getMemU32Ptr(0x5D4594, 28 * (v2 + v4) + 1570308);
					for (i = *getMemU32Ptr(0x5D4594, 28 * (v2 + v4) + 1570304); v5; v5 = *(_DWORD*)(v5 + 28)) {
						v7 = i--;
						if (v7 <= 0)
							break;
						sub_501FD0(a1, v5, *(_DWORD*)(v5 + 32));
					}
				}
				result = v8 >> 1;
				++v4;
				v8 >>= 1;
			} while (v4 < 32);
			v1 = (int*)v9;
		}
		++v1;
		v2 += 32;
		v9 = (unsigned __int8*)v1;
	} while ((int)v1 < (int)getMemAt(0x5D4594, 1599056));
	return result;
}

//----- (00502120) --------------------------------------------------------
BOOL  nox_thing_read_AVNT_502120(int a1, void* a2) {
	int v2;              // esi
	int v3;              // ebp
	unsigned __int8* v4; // eax
	int v5;              // eax
	char* v6;            // ecx
	char v7;             // bl
	unsigned __int8* v8; // ecx
	unsigned __int8* v9; // ecx
	unsigned __int8 v10; // dl
	int v11;             // ecx
	__int16 v12;         // dx
	__int16 v13;         // dx
	BOOL result;         // eax
	int v15;             // [esp-4h] [ebp-20h]
	unsigned __int8 v16; // [esp+10h] [ebp-Ch]
	unsigned __int8 v17; // [esp+14h] [ebp-8h]
	unsigned __int8 v18; // [esp+18h] [ebp-4h]
	unsigned __int8 v19; // [esp+20h] [ebp+4h]

	v2 = a1;
	v3 = dword_5d4594_1599064;
	v4 = *(unsigned __int8**)(a1 + 8);
	v15 = a1;
	v19 = *v4;
	*(_DWORD*)(v15 + 8) = v4 + 1;
	nox_memfile_read(a2, 1u, v19, v15);
	*((_BYTE*)a2 + v19) = 0;
	v5 = nox_xxx_utilFindSound_40AF50(a2);
	if (!v5)
		v3 = 0;
	while (2) {
		v6 = *(char**)(v2 + 8);
		v7 = *v6;
		v8 = (unsigned __int8*)(v6 + 1);
		*(_DWORD*)(v2 + 8) = v8;
		switch (v7) {
		case 0:
			result = v7 == 0;
			break;
		case 1:
		case 5:
			*(_DWORD*)(v2 + 8) = v8 + 1;
			continue;
		case 2:
			v16 = *v8;
			*(_DWORD*)(v2 + 8) = v8 + 1;
			if (v3)
				*getMemU32Ptr(0x5D4594, 28 * v5 + 1570300) = v16;
			continue;
		case 3:
			v18 = *v8;
			*(_DWORD*)(v2 + 8) = v8 + 1;
			if (v3)
				*getMemU32Ptr(0x5D4594, 28 * v5 + 1570292) = v18;
			continue;
		case 4:
			v17 = *v8;
			*(_DWORD*)(v2 + 8) = v8 + 1;
			if (v3)
				*getMemU32Ptr(0x5D4594, 28 * v5 + 1570304) = v17;
			continue;
		case 6:
			*(_DWORD*)(v2 + 8) = v8 + 2;
			continue;
		case 7:
			while (1) {
				v9 = *(unsigned __int8**)(v2 + 8);
				v10 = *v9;
				v11 = (int)(v9 + 1);
				*(_DWORD*)(v2 + 8) = v11;
				if (!v10)
					break;
				*(_DWORD*)(v2 + 8) = v11 + v10;
				++*getMemU32Ptr(0x5D4594, 28 * v5 + 1570296);
			}
			continue;
		case 8:
			*(_DWORD*)(v2 + 8) = v8 + 8;
			continue;
		case 9:
			v12 = *(_WORD*)v8;
			*(_DWORD*)(v2 + 8) = v8 + 2;
			if (v3)
				*getMemU32Ptr(0x5D4594, 28 * v5 + 1570284) = 15 * v12;
			continue;
		case 0xA:
			v13 = *(_WORD*)v8;
			*(_DWORD*)(v2 + 8) = v8 + 2;
			if (v3)
				*getMemU32Ptr(0x5D4594, 28 * v5 + 1570288) = v13;
			continue;
		default:
			result = 0;
			break;
		}
		break;
	}
	return result;
}

//----- (00502320) --------------------------------------------------------
int  nox_thing_read_audio_502320(int a1, void* a2) {
	int v2;  // ebx
	int* v3; // eax
	int v4;  // edi

	v2 = 0;
	v3 = *(int**)(a1 + 8);
	v4 = *v3;
	*(_DWORD*)(a1 + 8) = v3 + 1;
	if (v4 <= 0)
		return 1;
	while (sub_502370(a1, a2)) {
		if (++v2 >= v4)
			return 1;
	}
	return 0;
}

//----- (00502370) --------------------------------------------------------
int  sub_502370(int a1, void* a2) {
	char* v2;            // eax
	int v3;              // edi
	int v4;              // eax
	unsigned __int8* v5; // ecx
	__int16 v6;          // bp
	unsigned __int8 v7;  // dl
	__int16 v8;          // di
	int v9;              // ecx
	char* v10;           // eax
	char v11;            // dl
	int v12;             // eax
	char* v14;           // eax
	char v15;            // cl
	int v16;             // eax
	unsigned __int8 v17; // [esp+14h] [ebp+8h]

	v2 = *(char**)(a1 + 8);
	v3 = *v2;
	*(_DWORD*)(a1 + 8) = v2 + 1;
	nox_memfile_read(a2, 1u, v3, a1);
	*((_BYTE*)a2 + v3) = 0;
	v4 = nox_xxx_utilFindSound_40AF50(a2);
	if (v4 && dword_5d4594_1599064) {
		v5 = *(unsigned __int8**)(a1 + 8);
		v6 = *(_WORD*)v5;
		v5 += 2;
		*(_DWORD*)(a1 + 8) = v5;
		v7 = *v5++;
		*(_DWORD*)(a1 + 8) = v5;
		v8 = *(_WORD*)v5;
		v5 += 2;
		*(_DWORD*)(a1 + 8) = v5;
		v17 = *v5;
		*(_DWORD*)(a1 + 8) = v5 + 1;
		if (v8 > 0)
			*getMemU32Ptr(0x5D4594, 28 * v4 + 1570284) = 15 * v8;
		v9 = 28 * v4;
		*getMemU32Ptr(0x5D4594, v9 + 1570288) = v6;
		*getMemU32Ptr(0x5D4594, v9 + 1570292) = v7;
		*getMemU32Ptr(0x5D4594, v9 + 1570304) = v17;
		*(_DWORD*)(a1 + 8) += 3;
		while (1) {
			v10 = *(char**)(a1 + 8);
			v11 = *v10;
			v12 = (int)(v10 + 1);
			*(_DWORD*)(a1 + 8) = v12;
			if (!v11)
				break;
			*(_DWORD*)(a1 + 8) = v12 + v11;
			++*getMemU32Ptr(0x5D4594, v9 + 1570296);
		}
		*getMemU32Ptr(0x5D4594, v9 + 1570300) = 2;
	} else {
		for (*(_DWORD*)(a1 + 8) += 9;; *(_DWORD*)(a1 + 8) = v16 + v15) {
			v14 = *(char**)(a1 + 8);
			v15 = *v14;
			v16 = (int)(v14 + 1);
			*(_DWORD*)(a1 + 8) = v16;
			if (!v15)
				break;
		}
	}
	return 1;
}

//----- (005025A0) --------------------------------------------------------
void  sub_5025A0(int a1, int a2, int a3) {
	int result; // eax
	int v4;     // ecx

	if (*getMemIntPtr(0x5D4594, 1599468) < 32) {
		result = 12 * *getMemU32Ptr(0x5D4594, 1599468);
		v4 = *getMemU32Ptr(0x5D4594, 1599468) + 1;
		*getMemU32Ptr(0x5D4594, result + 1599084) = a1;
		*getMemU32Ptr(0x5D4594, result + 1599088) = a2;
		*getMemU32Ptr(0x5D4594, result + 1599092) = a3;
		*getMemU32Ptr(0x5D4594, 1599468) = v4;
	}
}

//----- (005025E0) --------------------------------------------------------
int  sub_5025E0(int a1, int a2, int a3) {
	int result;          // eax
	int v4;              // edi
	int v5;              // ecx
	unsigned __int8* v6; // esi
	unsigned __int8* v7; // eax
	int v8;              // ecx
	int v9;              // [esp+4h] [ebp-4h]

	result = *getMemU32Ptr(0x5D4594, 1599468);
	if (*getMemU32Ptr(0x5D4594, 1599468)) {
		v4 = 0;
		if (*getMemU32Ptr(0x5D4594, 1599468) > 0) {
			v5 = *getMemU32Ptr(0x5D4594, 1599468) - 1;
			v9 = *getMemU32Ptr(0x5D4594, 1599468) - 1;
			v6 = getMemAt(0x5D4594, 1599084);
			do {
				if (*(_DWORD*)v6 == a1 && *((_DWORD*)v6 + 1) == a2 && *((_DWORD*)v6 + 2) == a3) {
					if ((int)v6 < (int)getMemAt(0x5D4594, 1599468) && v4 < v5) {
						v7 = v6;
						v8 = v5 - v4;
						do {
							--v8;
							*(_DWORD*)v7 = *((_DWORD*)v7 + 3);
							*((_DWORD*)v7 + 1) = *((_DWORD*)v7 + 4);
							*((_DWORD*)v7 + 2) = *((_DWORD*)v7 + 5);
							v7 += 12;
						} while (v8);
						result = *getMemU32Ptr(0x5D4594, 1599468);
						v5 = v9;
					}
					--result;
					--v5;
					*getMemU32Ptr(0x5D4594, 1599468) = result;
					v9 = v5;
				}
				++v4;
				v6 += 12;
			} while (v4 < result);
		}
	}
	return result;
}

//----- (00502670) --------------------------------------------------------
void  nox_server_scriptExecuteFnForEachGroupObj_502670(unsigned __int8* groupPtr, int expectedType,
															  void(* a3)(int, int), int a4) {
	int* i;               // esi
	int v5;               // eax
	int* j;               // esi
	_DWORD* v7;           // eax
	int* k;               // esi
	int v9;               // eax
	int* l;               // esi
	unsigned __int8* v11; // eax

	if (!groupPtr) {
		return;
	}
	switch (*groupPtr) {
		case 0u:
			if (expectedType != 0) {
				break;
			}
			for (i = (int*)*((_DWORD*)groupPtr + 21); i; i = (int*)i[2]) {
				v5 = nox_xxx_netGetUnitByExtent_4ED020(*i);
				if (v5)
					a3(v5, a4);
			}
			break;
		case 1u:
			if (expectedType != 1) {
				break;
			}
			for (j = (int*)*((_DWORD*)groupPtr + 21); j; j = (int*)j[2]) {
				v7 = nox_server_getWaypointById_579C40(*j);
				if (v7)
					a3((int)v7, a4);
			}
			break;
		case 2u:
			if (expectedType != 2) {
				break;
			}
			for (k = (int*)*((_DWORD*)groupPtr + 21); k; k = (int*)k[2]) {
				v9 = nox_server_getWallAtPoint_410580(*k, k[1]);
				if (v9)
					a3(v9, a4);
			}
			// fallthrough
		case 3u:
			for (l = (int*)*((_DWORD*)groupPtr + 21); l; l = (int*)l[2]) {
				v11 = (unsigned __int8*)nox_server_scriptGetGroup_57C0A0(*l);
				if (v11)
					nox_server_scriptExecuteFnForEachGroupObj_502670(v11, expectedType, a3, a4);
			}
			break;
		default:
			break;
	}
}

//----- (00502790) --------------------------------------------------------
int  nox_xxx_mapgenMakeScript_502790(FILE* a1, char* a2) {
	int result;     // eax
	int i;          // ebx
	int v4;         // edi
	int v5;         // eax
	int v6;         // [esp+8h] [ebp-410h]
	int v7;         // [esp+Ch] [ebp-40Ch]
	int v8;         // [esp+10h] [ebp-408h]
	int v9;         // [esp+14h] [ebp-404h]
	char v10[1024]; // [esp+18h] [ebp-400h]

	nox_xxx_fread_408E40_fread((char*)&v8, 4, 1, a1);
	nox_xxx_fread_408E40_fread(v10, 1, v8, a1);
	nox_xxx_fread_408E40_fread(a2, 4, 1, a1);
	nox_xxx_fread_408E40_fread((char*)&v7, 4, 1, a1);
	result = v7;
	for (i = 0; i < v7; ++i) {
		nox_xxx_fread_408E40_fread((char*)&v6, 1, 1, a1);
		nox_xxx_fseek_409050(a1, 1, SEEK_CUR);
		v4 = 0;
		v5 = 268 * (unsigned __int8)v6;
		if (getMemByte(0x587000, v5 + 218640)) {
			do {
				switch (*getMemU32Ptr(0x587000, 8 * v4 + 218648 + v5)) {
				case 0:
				case 3:
				case 4:
				case 5:
				case 6:
					nox_xxx_fseek_409050(a1, 4, SEEK_CUR);
					break;
				case 1:
					nox_xxx_fseek_409050(a1, 8, SEEK_CUR);
					break;
				case 2:
				case 7:
					nox_xxx_fread_408E40_fread((char*)&v9, 1, 1, a1);
					nox_xxx_fseek_409050(a1, (unsigned __int8)v9, SEEK_CUR);
					break;
				default:
					break;
				}
				++v4;
				v5 = 268 * (unsigned __int8)v6;
			} while (v4 < getMemByte(0x587000, v5 + 218640));
		}
		result = v7;
	}
	return result;
}

//----- (005028E0) --------------------------------------------------------
char* nox_xxx_mapReset_5028E0() {
	char* result; // eax

	dword_5d4594_1599480 = -1;
	*getMemU32Ptr(0x5D4594, 1599572) = -1;
	dword_5d4594_1599476 = 0;
	dword_5d4594_1599540 = 0;
	*getMemU32Ptr(0x5D4594, 1599544) = 0;
	dword_5d4594_1599532 = 0;
	*getMemU32Ptr(0x5D4594, 1599536) = 0;
	dword_5d4594_1599556 = 0;
	*getMemU32Ptr(0x5D4594, 1599560) = 0;
	dword_5d4594_1599548 = 0;
	*getMemU32Ptr(0x5D4594, 1599552) = 0;
	dword_5d4594_1599564 = 0;
	*getMemU32Ptr(0x5D4594, 1599568) = 0;
	*getMemU32Ptr(0x5D4594, 1599484) = 0;
	*getMemU32Ptr(0x5D4594, 1599488) = 0;
	*getMemU32Ptr(0x5D4594, 1599492) = 0;
	*getMemU32Ptr(0x5D4594, 1599496) = 0;
	memset(getMemAt(0x5D4594, 1599500), 0, 0x20u);
	if (!dword_5d4594_1599588)
		dword_5d4594_1599588 = malloc(0x800u);
	result = *(char**)&dword_5d4594_1599592;
	if (!dword_5d4594_1599592) {
		result = (char*)malloc(0x800u);
		dword_5d4594_1599592 = result;
	}
	return result;
}

//----- (005029A0) --------------------------------------------------------
int  sub_5029A0(char* a1) {
	int v1; // edi
	int i;  // esi

	v1 = 0;
	if (*(int*)&dword_5d4594_1599596 <= 0)
		return -1;
	for (i = 0; _strcmpi(a1, (const char*)(i + dword_5d4594_1599576)); i += 76) {
		if (++v1 >= *(int*)&dword_5d4594_1599596)
			return -1;
	}
	return v1;
}

//----- (005029F0) --------------------------------------------------------
int  sub_5029F0(int a1) {
	int result; // eax

	if (a1 < 0 || a1 > *(int*)&dword_5d4594_1599596)
		result = 0;
	else
		result = dword_5d4594_1599576 + 76 * a1;
	return result;
}

//----- (00502A20) --------------------------------------------------------
int sub_502A20() { return dword_5d4594_1599596; }

//----- (00502A30) --------------------------------------------------------
BOOL  sub_502A30(char* a1) {
	int v1; // eax

	v1 = sub_5029A0(a1);
	return sub_502D70(v1);
}

//----- (00502A50) --------------------------------------------------------
int  sub_502A50(char* a1) {
	int result; // eax

	sub_502DF0();
	if (a1) {
		strncpy(*(char**)&dword_5d4594_1599588, a1, 0x7FFu);
		result = 1;
	} else {
		**(_BYTE**)&dword_5d4594_1599588 = getMemByte(0x5D4594, 1599608);
		result = 0;
	}
	return result;
}

//----- (00502A90) --------------------------------------------------------
int sub_502A90() { return strlen(*(const char**)&dword_5d4594_1599588) != 0 ? dword_5d4594_1599588 : 0; }

//----- (00502AB0) --------------------------------------------------------
int  sub_502AB0(char* a1) {
	int result; // eax

	if (a1) {
		strncpy(*(char**)&dword_5d4594_1599592, a1, 0x7FFu);
		result = 1;
	} else {
		**(_BYTE**)&dword_5d4594_1599592 = getMemByte(0x5D4594, 1599612);
		result = 0;
	}
	return result;
}

//----- (00502AF0) --------------------------------------------------------
int sub_502AF0() { return strlen(*(const char**)&dword_5d4594_1599592) != 0 ? dword_5d4594_1599592 : 0; }

//----- (00502B10) --------------------------------------------------------
int sub_502B10() {
	int result;   // eax
	int v1;       // ebp
	int v2;       // ecx
	int v3;       // ebp
	char v4;      // [esp+12h] [ebp-56h]
	char v5;      // [esp+13h] [ebp-55h]
	int v6;       // [esp+14h] [ebp-54h]
	int v7;       // [esp+18h] [ebp-50h]
	int v8;       // [esp+1Ch] [ebp-4Ch]
	float v9;     // [esp+20h] [ebp-48h]
	float v10;    // [esp+24h] [ebp-44h]
	char v11[64]; // [esp+28h] [ebp-40h]

	dword_5d4594_1599596 = 0;
	if (!dword_5d4594_1599588)
		dword_5d4594_1599588 = malloc(0x800u);
	if (!dword_5d4594_1599592)
		dword_5d4594_1599592 = malloc(0x800u);
	if (!dword_5d4594_1599576)
		dword_5d4594_1599576 = malloc(0x26000u);
	result = 0;
	if (strlen(*(const char**)&dword_5d4594_1599588)) {
		result = sub_502DA0(*(char**)&dword_5d4594_1599588);
		if (result) {
			fread(&v8, 4u, 1u, nox_file_8);
			if (v8 == -889266515) {
				while (1) {
					v6 = 0;
					fread(&v6, 4u, 1u, nox_file_8);
					v1 = v6;
					if (!v6)
						break;
					if (dword_5d4594_1599596 >= 2048)
						goto LABEL_10;
					*(_DWORD*)(dword_5d4594_1599576 + 76 * dword_5d4594_1599596 + 72) = ftell(nox_file_8) - 4;
					fread(&v7, 1u, 1u, nox_file_8);
					fread(v11, (unsigned __int8)v7, 1u, nox_file_8);
					v2 = -1 - (unsigned __int8)v7;
					v11[(unsigned __int8)v7] = 0;
					v3 = v2 + v1;
					strcpy((char*)(dword_5d4594_1599576 + 76 * dword_5d4594_1599596), v11);
					fread(&v4, 1u, 1u, nox_file_8);
					fread(&v5, 1u, 1u, nox_file_8);
					fread(&v9, 4u, 1u, nox_file_8);
					fread(&v10, 4u, 1u, nox_file_8);
					*(float*)(dword_5d4594_1599576 + 76 * dword_5d4594_1599596 + 64) = v9;
					*(float*)(dword_5d4594_1599576 + 76 * (dword_5d4594_1599596)++ + 68) = v10;
					fseek(nox_file_8, v3 - 10, SEEK_CUR);
				}
				sub_502DF0();
				result = 1;
			} else {
			LABEL_10:
				sub_502DF0();
				result = 0;
			}
		}
	}
	return result;
}
// 502B10: using guessed type char var_40[64];

//----- (00502D70) --------------------------------------------------------
BOOL  sub_502D70(int a1) {
	if (a1 < 0 || a1 >= *(int*)&dword_5d4594_1599596)
		return 0;
	dword_5d4594_3835396 = a1;
	return nox_xxx_mapgenSaveMap_503830(a1) == 0;
}

//----- (00502DA0) --------------------------------------------------------
FILE*  sub_502DA0(char* a1) {
	FILE* result; // eax

	result = nox_file_8;
	if (nox_file_8 ||
		(result = (FILE*)nox_xxx_cryptOpen_426910(a1, 1, -1)) != 0 && (result = nox_xxx_mapgenGetSomeFile_426A60(), (nox_file_8 = result) != 0)) {
		fseek(result, 0, SEEK_SET);
		result = (FILE*)1;
	}
	return result;
}

//----- (00502DF0) --------------------------------------------------------
FILE* sub_502DF0() {
	FILE* result; // eax

	result = nox_file_8;
	if (nox_file_8) {
		result = nox_xxx_cryptClose_4269F0();
		nox_file_8 = 0;
	}
	return result;
}

//----- (00502E10) --------------------------------------------------------
FILE*  sub_502E10(int a1) {
	if (!nox_file_8 || a1 < 0 || a1 >= *(int*)&dword_5d4594_1599596)
		return 0;
	fseek(nox_file_8, *(_DWORD*)(dword_5d4594_1599576 + 76 * a1 + 72), SEEK_SET);
	return nox_file_8;
}

//----- (00502E50) --------------------------------------------------------
FILE*  sub_502E50(char* a1) {
	FILE* result; // eax
	int v2;       // eax

	result = (FILE*)a1;
	if (a1) {
		v2 = sub_5029A0(a1);
		result = sub_502E10(v2);
	}
	return result;
}

//----- (00502E70) --------------------------------------------------------
double  sub_502E70(int a1) {
	double result; // st7

	if (a1 < 0 || a1 >= *(int*)&dword_5d4594_1599596)
		result = -1.0;
	else
		result = *(float*)(dword_5d4594_1599576 + 76 * a1 + 64);
	return result;
}

//----- (00502EA0) --------------------------------------------------------
double  sub_502EA0(int a1) {
	double result; // st7

	if (a1 < 0 || a1 >= *(int*)&dword_5d4594_1599596)
		result = -1.0;
	else
		result = *(float*)(dword_5d4594_1599576 + 76 * a1 + 68);
	return result;
}

//----- (00502ED0) --------------------------------------------------------
FILE*  sub_502ED0(const char* a1) {
	FILE* result;       // eax
	int v2;             // edx
	int v3;             // eax
	char* v4;           // edi
	unsigned __int8 v5; // cl
	FILE* v6;           // edi
	FILE* v7;           // ebx
	int v8;             // ebp
	int v9;             // ecx
	int v10;            // ebp
	int v11;            // [esp+Ch] [ebp-854h]
	int v12;            // [esp+10h] [ebp-850h]
	int v13;            // [esp+14h] [ebp-84Ch]
	int v14;            // [esp+18h] [ebp-848h]
	int v15;            // [esp+1Ch] [ebp-844h]
	char v16[64];       // [esp+20h] [ebp-840h]
	char v17[2048];     // [esp+60h] [ebp-800h]

	v13 = 0;
	result = (FILE*)sub_503140();
	if (result) {
		v2 = *getMemU32Ptr(0x587000, 229712);
		strcpy(v17, (const char*)getMemAt(0x5D4594, 3841580));
		v3 = *getMemU32Ptr(0x587000, 229716);
		v4 = &v17[strlen(v17)];
		*(_DWORD*)v4 = *getMemU32Ptr(0x587000, 229708);
		v5 = getMemByte(0x587000, 229720);
		*((_DWORD*)v4 + 1) = v2;
		*((_DWORD*)v4 + 2) = v3;
		v4[12] = v5;
		result = nox_fs_open(v17);
		v6 = result;
		if (result) {
			result = nox_fs_create(*(const char**)&dword_5d4594_1599588);
			v7 = result;
			if (result) {
				fread(&v14, 4u, 1u, v6);
				if (v14 == -889266515) {
					fwrite(&v14, 4u, 1u, v7);
					while (1) {
						v12 = 0;
						fread(&v12, 4u, 1u, v6);
						v8 = v12;
						if (!v12)
							break;
						fread(&v11, 1u, 1u, v6);
						fread(v16, (unsigned __int8)v11, 1u, v6);
						v9 = -1 - (unsigned __int8)v11;
						v16[(unsigned __int8)v11] = 0;
						v10 = v9 + v8;
						if (!strcmp(v16, a1)) {
							fseek(v6, v10, SEEK_CUR);
						} else {
							v13 = 1;
							fwrite(&v12, 4u, 1u, v7);
							fwrite(&v11, 1u, 1u, v7);
							fwrite(v16, (unsigned __int8)v11, 1u, v7);
							for (; v10; --v10) {
								fread(&v11, 1u, 1u, v6);
								fwrite(&v11, 1u, 1u, v7);
							}
						}
					}
					v15 = 0;
					fwrite(&v15, 4u, 1u, v7);
					fclose(v6);
					fclose(v7);
					sub_502B10();
					result = (FILE*)(v13 != 0);
				} else {
					fclose(v6);
					fclose(v7);
					result = 0;
				}
			}
		}
	}
	return result;
}
// 502ED0: using guessed type char var_800[2048];
// 502ED0: using guessed type char var_840[64];

//----- (00503140) --------------------------------------------------------
BOOL sub_503140() {
	BOOL result;            // eax
	int v1;                 // edx
	int v2;                 // eax
	char* v3;               // edi
	unsigned __int8 v4;     // cl
	char NewFileName[2048]; // [esp+4h] [ebp-800h]

	sub_502DF0();
	result = 0;
	if (strlen(*(const char**)&dword_5d4594_1599588)) {
		result = 0;
		if (strlen((const char*)getMemAt(0x5D4594, 3841580))) {
			v1 = *getMemU32Ptr(0x587000, 229736);
			strcpy(NewFileName, (const char*)getMemAt(0x5D4594, 3841580));
			v2 = *getMemU32Ptr(0x587000, 229740);
			v3 = &NewFileName[strlen(NewFileName)];
			*(_DWORD*)v3 = *getMemU32Ptr(0x587000, 229732);
			v4 = getMemByte(0x587000, 229744);
			*((_DWORD*)v3 + 1) = v1;
			*((_DWORD*)v3 + 2) = v2;
			v3[12] = v4;
			if (remove(NewFileName) != -1 || errno != 13)
				result = rename(*(LPCSTR*)&dword_5d4594_1599588, NewFileName) != -1;
			else
				result = 0;
		}
	}
	return result;
}
// 503140: using guessed type CHAR NewFileName[2048];

//----- (00503230) --------------------------------------------------------
FILE*  sub_503230(const char* a1, char* a2) {
	FILE* result;       // eax
	int v3;             // edx
	int v4;             // eax
	char* v5;           // edi
	unsigned __int8 v6; // cl
	FILE* v7;           // ebx
	FILE* v8;           // ebp
	int v9;             // esi
	int v10;            // edx
	int v11;            // ecx
	int i;              // esi
	char v13;           // [esp+13h] [ebp-85Dh]
	int v14;            // [esp+14h] [ebp-85Ch]
	int v15;            // [esp+18h] [ebp-858h]
	int v16;            // [esp+1Ch] [ebp-854h]
	int v17;            // [esp+20h] [ebp-850h]
	int v18;            // [esp+24h] [ebp-84Ch]
	int v19;            // [esp+28h] [ebp-848h]
	int v20;            // [esp+2Ch] [ebp-844h]
	char v21[64];       // [esp+30h] [ebp-840h]
	char v22[2048];     // [esp+70h] [ebp-800h]

	result = (FILE*)sub_503140();
	if (result) {
		v3 = *getMemU32Ptr(0x587000, 229752);
		strcpy(v22, (const char*)getMemAt(0x5D4594, 3841580));
		v4 = *getMemU32Ptr(0x587000, 229756);
		v5 = &v22[strlen(v22)];
		*(_DWORD*)v5 = *getMemU32Ptr(0x587000, 229748);
		v6 = getMemByte(0x587000, 229760);
		*((_DWORD*)v5 + 1) = v3;
		*((_DWORD*)v5 + 2) = v4;
		v5[12] = v6;
		result = nox_fs_open(v22);
		v7 = result;
		if (result) {
			v8 = nox_fs_create(*(const char**)&dword_5d4594_1599588);
			if (v8) {
				fread(&v17, 4u, 1u, v7);
				fwrite(&v17, 4u, 1u, v8);
				while (1) {
					fread(&v16, 4u, 1u, v7);
					v9 = v16;
					if (!v16)
						break;
					fread(&v14, 1u, 1u, v7);
					fread(v21, (unsigned __int8)v14, 1u, v7);
					v10 = (unsigned __int8)v14;
					v11 = -1 - (unsigned __int8)v14;
					v21[(unsigned __int8)v14] = 0;
					v20 = v11 + v9;
					if (!strcmp(v21, a1)) {
						LOBYTE(v15) = strlen(a2);
						v19 = v16 + (unsigned __int8)v15 - v10;
						fwrite(&v19, 4u, 1u, v8);
						fwrite(&v15, 1u, 1u, v8);
						fwrite(a2, (unsigned __int8)v15, 1u, v8);
					} else {
						fwrite(&v16, 4u, 1u, v8);
						fwrite(&v14, 1u, 1u, v8);
						fwrite(v21, (unsigned __int8)v14, 1u, v8);
					}
					for (i = v20; i; --i) {
						fread(&v13, 1u, 1u, v7);
						fwrite(&v13, 1u, 1u, v8);
					}
				}
				v18 = 0;
				fwrite(&v18, 4u, 1u, v8);
				fclose(v7);
				fclose(v8);
				sub_502B10();
				result = (FILE*)1;
			} else {
				fclose(v7);
				result = 0;
			}
		}
	}
	return result;
}
// 503230: using guessed type char var_800[2048];
// 503230: using guessed type char var_840[64];

//----- (005034B0) --------------------------------------------------------
int  sub_5034B0(char* a1) {
	int v1;              // edx
	__int16 v2;          // ax
	char* v3;            // edi
	char* v4;            // eax
	FILE* v5;            // esi
	int result;          // eax
	FILE* v7;            // ebx
	int v8;              // edi
	int v9;              // edi
	int v10;             // edi
	int v11;             // edi
	unsigned __int8 v12; // [esp+Fh] [ebp-105Dh]
	int v13;             // [esp+10h] [ebp-105Ch]
	char v14;            // [esp+17h] [ebp-1055h]
	int v15;             // [esp+18h] [ebp-1054h]
	int v16;             // [esp+1Ch] [ebp-1050h]
	int v17;             // [esp+20h] [ebp-104Ch]
	int v18;             // [esp+24h] [ebp-1048h]
	int v19;             // [esp+28h] [ebp-1044h]
	char v20[64];        // [esp+2Ch] [ebp-1040h]
	char v21[4096];      // [esp+6Ch] [ebp-1000h]

	v1 = *getMemU32Ptr(0x587000, 229776);
	strcpy(v21, (const char*)getMemAt(0x5D4594, 3841580));
	v2 = *getMemU16Ptr(0x587000, 229780);
	v3 = &v21[strlen(v21)];
	*(_DWORD*)v3 = *getMemU32Ptr(0x587000, 229772);
	*((_DWORD*)v3 + 1) = v1;
	*((_WORD*)v3 + 4) = v2;
	v4 = (char*)sub_502A90();
	sub_502DA0(v4);
	v5 = sub_502E50(a1);
	if (v5) {
		v7 = nox_fs_create(v21);
		if (v7) {
			fread(&v17, 4u, 1u, v5);
			v8 = v17;
			fread(&v13, 1u, 1u, v5);
			fread(v20, (unsigned __int8)v13, 1u, v5);
			v9 = -1 - (unsigned __int8)v13 + v8;
			v20[(unsigned __int8)v13] = 0;
			fread(&v14, 1u, 1u, v5);
			fread(&v12, 1u, 1u, v5);
			fread(&v19, 4u, 1u, v5);
			fread(&v18, 4u, 1u, v5);
			v10 = v9 - 10;
			if (v12 > 1u) {
				fread(&v16, 4u, 1u, v5);
				fseek(v5, v16, SEEK_CUR);
				v10 += -4 - v16;
			}
			fread(&v15, 4u, 1u, v5);
			v11 = v10 - 4;
			if (v15 == -889266515) {
				v15 = -1410467122;
				fwrite(&v15, 4u, 1u, v7);
				for (; v11; --v11) {
					fread(&v13, 1u, 1u, v5);
					fwrite(&v13, 1u, 1u, v7);
				}
				sub_502DF0();
				fclose(v7);
				result = 1;
			} else {
				sub_502DF0();
				fclose(v7);
				result = 0;
			}
		} else {
			sub_502DF0();
			result = 0;
		}
	} else {
		sub_502DF0();
		result = 0;
	}
	return result;
}
// 5034B0: using guessed type char var_1000[4096];
// 5034B0: using guessed type char var_1040[64];

//----- (005036D0) --------------------------------------------------------
int  sub_5036D0(char* a1, LPCSTR lpFileName) {
	const char* v2; // edi
	char* v3;       // eax
	FILE* v4;       // eax
	FILE* v5;       // esi
	FILE* v7;       // edi
	char v8;        // [esp+Bh] [ebp-55h]
	int v9;         // [esp+Ch] [ebp-54h]
	int v10;        // [esp+10h] [ebp-50h]
	int v11;        // [esp+14h] [ebp-4Ch]
	int v12;        // [esp+18h] [ebp-48h]
	int v13;        // [esp+1Ch] [ebp-44h]
	char v14[64];   // [esp+20h] [ebp-40h]

	v2 = lpFileName;
	DeleteFileA(lpFileName);
	v3 = (char*)sub_502A90();
	sub_502DA0(v3);
	v4 = sub_502E50(a1);
	v5 = v4;
	if (!v4) {
		sub_502DF0();
		return 0;
	}
	fread(&v11, 4u, 1u, v4);
	fread(&v10, 1u, 1u, v5);
	fread(v14, (unsigned __int8)v10, 1u, v5);
	v14[(unsigned __int8)v10] = 0;
	fread(&v8, 1u, 1u, v5);
	fread(&lpFileName, 1u, 1u, v5);
	fread(&v12, 4u, 1u, v5);
	fread(&v13, 4u, 1u, v5);
	if ((unsigned __int8)lpFileName <= 1u)
		return 0;
	fread(&v9, 4u, 1u, v5);
	if (!v9)
		return 0;
	v7 = nox_fs_create(v2);
	if (!v7)
		return 0;
	for (; v9; --v9) {
		fread(&a1, 1u, 1u, v5);
		fwrite(&a1, 1u, 1u, v7);
	}
	sub_502DF0();
	fclose(v7);
	return 1;
}
// 5036D0: using guessed type char var_40[64];

//----- (00503830) --------------------------------------------------------
int  nox_xxx_mapgenSaveMap_503830(int a1) {
	FILE* v1;           // esi
	_DWORD* v2;         // eax
	int v3;             // esi
	unsigned __int8 v5; // [esp+Fh] [ebp-19Dh]
	int v6;             // [esp+10h] [ebp-19Ch]
	char v7;            // [esp+17h] [ebp-195h]
	int v8;             // [esp+18h] [ebp-194h]
	int v9;             // [esp+1Ch] [ebp-190h]
	int v10;            // [esp+20h] [ebp-18Ch]
	int v11[8];         // [esp+24h] [ebp-188h]
	int v19[2];         // [esp+44h] [ebp-168h]
	int v21;            // [esp+4Ch] [ebp-160h]
	int v22;            // [esp+50h] [ebp-15Ch]
	int v23;            // [esp+54h] [ebp-158h]
	char v24[4];        // [esp+58h] [ebp-154h]
	int4 v25;           // [esp+5Ch] [ebp-150h]
	char v26[64];       // [esp+6Ch] [ebp-140h]
	char v27[256];      // [esp+ACh] [ebp-100h]

	if (a1 < 0)
		return 0;
	if (a1 >= *(int*)&dword_5d4594_1599596)
		return 0;
	nox_xxx_free_503F40();
	*getMemU32Ptr(0x5D4594, 1599572) = -1;
	dword_5d4594_1599644 = 0;
	sub_502DA0(*(char**)&dword_5d4594_1599588);
	if (!sub_502E10(a1))
		return 0;
	v1 = nox_xxx_mapgenGetSomeFile_426A60();
	fread(&v22, 4u, 1u, v1);
	fread(&v9, 1u, 1u, v1);
	fread(v26, (unsigned __int8)v9, 1u, v1);
	fread(&v7, 1u, 1u, v1);
	fread(&v5, 1u, 1u, v1);
	fread(&v21, 4u, 1u, v1);
	fread(&v23, 4u, 1u, v1);
	if (v5 > 1u) {
		fread(&v6, 4u, 1u, v1);
		fseek(v1, v6, SEEK_CUR);
	}
	fread(&v10, 4u, 1u, v1);
	if (v10 != -889266515)
		return 0;
	fread(v19, 4u, 1u, v1);
	fread(&v19[1], 4u, 1u, v1);
	nox_xxx_mapWall_426A80(v19);
	fread(v11, 4u, 1u, v1);
	fread(&v11[1], 4u, 1u, v1);
	fread(&v11[6], 4u, 1u, v1);
	fread(&v11[7], 4u, 1u, v1);
	fread(&v11[2], 4u, 1u, v1);
	fread(&v11[3], 4u, 1u, v1);
	fread(&v11[4], 4u, 1u, v1);
	fread(&v11[5], 4u, 1u, v1);
	sub_4D3C80(v11);
	memcpy(getMemAt(0x5D4594, 1599500), v11, 0x20u);
	sub_428170(&v11, &v25);
	nox_xxx_cryptSetTypeMB_426A50(1);
	while (1) {
		v6 = 0;
		LOBYTE(v8) = 0;
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v8, 1u);
		if (!(_BYTE)v8)
			break;
		nox_xxx_fileReadWrite_426AC0_file3_fread(v27, (unsigned __int8)v8);
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v24, 4u);
		if (!nox_xxx_mapReadSection_426EA0((int)&v11, v27, &v6)) {
			if (v6 == 1)
				goto LABEL_15;
			v2 = nox_xxx_objectCreateByName_4E3810(v27);
			v3 = (int)v2;
			if (!v2)
				return 0;
			if (!((int(*)(_DWORD*, int4*))v2[176])(v2, &v25)) {
				nox_xxx_objectFreeMem_4E38A0(v3);
			LABEL_15:
				sub_502DF0();
				return 0;
			}
			nox_xxx_servMapLoadPlaceObj_4F3F50(v3, 0, &v25.field_0);
		}
	}
	nox_xxx_cryptSetTypeMB_426A50(0);
	dword_5d4594_1599480 = a1;
	dword_5d4594_1599476 = 0;
	dword_5d4594_3835396 = a1;
	sub_502DF0();
	return 1;
}

//----- (00503B30) --------------------------------------------------------
int  sub_503B30(float2* a1) {
	int result; // eax
	int v2;     // edi
	double v3;  // st7
	float v4;   // ecx
	char* v5;   // eax
	char* v6;   // ecx
	int v7;     // eax
	int v8;     // esi
	int v9;     // edi
	int i;      // eax
	int j;      // eax
	int k;      // eax
	float2 v13; // [esp+Ch] [ebp-50h]
	float2 v14; // [esp+14h] [ebp-48h]
	float2 a2;  // [esp+1Ch] [ebp-40h]
	int2 v16;   // [esp+24h] [ebp-38h]
	int4 v17;   // [esp+2Ch] [ebp-30h]
	int v18[8]; // [esp+3Ch] [ebp-20h]

	result = nox_xxx_mapGenFixCoords_4D3D90(a1, &a2);
	if (result) {
		v2 = dword_5d4594_3835396;
		if (dword_5d4594_1599480 != dword_5d4594_3835396 || *(int*)&dword_5d4594_1599480 == -1 ||
			dword_5d4594_1599476 == 1) {
			result = nox_xxx_mapgenSaveMap_503830(*(int*)&dword_5d4594_3835396);
			if (!result)
				return result;
			v2 = dword_5d4594_3835396;
		}
		v18[2] = (__int64)a2.field_0;
		v18[3] = (__int64)a2.field_4;
		v13.field_0 = *(float*)(dword_5d4594_1599576 + 76 * v2 + 64) + a1->field_0;
		v13.field_4 = *(float*)(dword_5d4594_1599576 + 76 * v2 + 68) + a1->field_4;
		nox_xxx_mapGenFixCoords_4D3D90(&v13, &v14);
		v18[4] = (__int64)v14.field_0;
		v18[5] = (__int64)v14.field_4;
		v3 = *(float*)(dword_5d4594_1599576 + 76 * dword_5d4594_3835396 + 64) + a1->field_0;
		v13.field_4 = a1->field_4;
		v13.field_0 = v3;
		nox_xxx_mapGenFixCoords_4D3D90(&v13, &v14);
		v18[0] = (__int64)v14.field_0;
		v4 = a1->field_0;
		v18[1] = (__int64)v14.field_4;
		v13.field_0 = v4;
		v13.field_4 = *(float*)(dword_5d4594_1599576 + 76 * dword_5d4594_3835396 + 68) + a1->field_4;
		nox_xxx_mapGenFixCoords_4D3D90(&v13, &v14);
		v18[6] = (__int64)v14.field_0;
		v18[7] = (__int64)v14.field_4;
		sub_4D3C80(v18);
		sub_428170(v18, &v17);
		v5 = nox_xxx_mapGetWallSize_426A70();
		v6 = v5;
		v7 = *(_DWORD*)v5;
		*getMemU32Ptr(0x5D4594, 1599484) = v7;
		*getMemU32Ptr(0x5D4594, 1599488) = *((_DWORD*)v6 + 1);
		*getMemFloatPtr(0x5D4594, 1599492) = (double)(23 * v7);
		*getMemFloatPtr(0x5D4594, 1599496) = (double)(int)(23 * *getMemU32Ptr(0x5D4594, 1599488));
		v8 = (__int64)(a2.field_0 - (double)*getMemIntPtr(0x5D4594, 1599500 + 8));
		v9 = (__int64)(a2.field_4 - (double)*getMemIntPtr(0x5D4594, 1599500 + 12));
		result = nox_xxx_tileInit_504150(v8, v9);
		if (result) {
			result = sub_504330(v8, v9);
			if (result) {
				result = sub_504560(v8, v9);
				if (result) {
					result = sub_504910(v8, v9);
					if (result) {
						sub_579D20();
						for (i = sub_579890(); i; i = sub_5798A0(i))
							*(_DWORD*)(i + 480) |= 0x80000000;
						dword_5d4594_3835392 = nox_xxx_interesting_xfer_4D0010(&v17, *(int*)&dword_5d4594_3835392);
						result = sub_504720(v8, v9);
						if (result) {
							for (j = sub_579890(); j; j = sub_5798A0(j))
								*(_DWORD*)(j + 4) = 0;
							for (k = nox_server_getFirstObjectUninited_4DA870(); k; k = nox_server_getNextObjectUninited_4DA880(k))
								*(_DWORD*)(k + 44) = 0;
							nox_xxx_waypoint_5799C0();
							nox_xxx_unitClearPendingMB_4DB030();
							dword_5d4594_1599476 = 1;
							if (dword_5d4594_1599644) {
								++*getMemU32Ptr(0x5D4594, 3835308);
								sub_542BF0(*(int*)&dword_5d4594_3835312, v8, v9);
								v16.field_0 = v8;
								v16.field_4 = v9;
								sub_543110((LPCSTR)getMemAt(0x5D4594, 3830188), &v16);
								if (*getMemU32Ptr(0x5D4594, 1599580)) {
									remove((LPCSTR)getMemAt(0x5D4594, 3835436));
									rename((LPCSTR)getMemAt(0x5D4594, 3837484), (LPCSTR)getMemAt(0x5D4594, 3835436));
									nox_script_readWriteZzz_541670((const char*)getMemAt(0x5D4594, 3835436), (const char*)getMemAt(0x5D4594, 3830188),
											   (const char*)getMemAt(0x5D4594, 3837484));
								} else {
									*getMemU32Ptr(0x5D4594, 1599580) = 1;
									rename((LPCSTR)getMemAt(0x5D4594, 3830188), (LPCSTR)getMemAt(0x5D4594, 3837484));
								}
							}
							++dword_5d4594_3835312;
							result = 1;
						}
					}
				}
			}
		}
	}
	return result;
}

//----- (00503EC0) --------------------------------------------------------
int  sub_503EC0(int a1, float* a2) {
	float2 a1a; // [esp+0h] [ebp-18h]
	float2 v4;  // [esp+8h] [ebp-10h]
	float2 a2a; // [esp+10h] [ebp-8h]

	if (dword_5d4594_1599480 != dword_5d4594_3835396 || *(int*)&dword_5d4594_1599480 == -1 ||
		dword_5d4594_1599476 == 1) {
		return 0;
	}
	a1a.field_0 = (double)*getMemIntPtr(0x5D4594, 1599500 + 8);
	a1a.field_4 = (double)*getMemIntPtr(0x5D4594, 1599500 + 12);
	sub_4D3E30(&a1a, &a2a);
	sub_4D3E30((float2*)(a1 + 56), &v4);
	*a2 = v4.field_0 - a2a.field_0;
	a2[1] = v4.field_4 - a2a.field_4;
	return 1;
}

//----- (00503F40) --------------------------------------------------------
char* nox_xxx_free_503F40() {
	int* v0;      // esi
	int* v1;      // edi
	int v2;       // esi
	int v3;       // edi
	LPVOID* v4;   // edi
	LPVOID* v5;   // ebx
	int v6;       // eax
	int v7;       // esi
	LPVOID* v8;   // esi
	LPVOID* v9;   // edi
	_QWORD** v10; // edi
	_QWORD** v11; // ebx
	int v12;      // eax
	int v13;      // esi

	v0 = *(int**)&dword_5d4594_1599540;
	if (dword_5d4594_1599540) {
		do {
			v1 = (int*)v0[1];
			if (!dword_5d4594_1599476)
				nox_xxx_objectFreeMem_4E38A0(*v0);
			free(v0);
			v0 = v1;
		} while (v1);
	}
	v2 = dword_5d4594_1599548;
	if (dword_5d4594_1599548) {
		do {
			v3 = *(_DWORD*)(v2 + 4);
			if (!dword_5d4594_1599476)
				free(*(LPVOID*)v2);
			free((LPVOID)v2);
			v2 = v3;
		} while (v3);
	}
	v4 = *(LPVOID**)&dword_5d4594_1599556;
	if (dword_5d4594_1599556) {
		do {
			v5 = (LPVOID*)v4[4];
			v6 = *((_DWORD*)*v4 + 4);
			if (v6) {
				do {
					v7 = *(_DWORD*)(v6 + 16);
					nox_xxx_tileFreeTileOne_4221E0(v6);
					v6 = v7;
				} while (v7);
			}
			free(*v4);
			free(v4);
			v4 = v5;
		} while (v5);
	}
	v8 = *(LPVOID**)&dword_5d4594_1599532;
	if (dword_5d4594_1599532) {
		do {
			v9 = (LPVOID*)v8[1];
			if (!dword_5d4594_1599476 && *((_BYTE*)*v8 + 4) & 4)
				free(*((LPVOID*)*v8 + 7));
			free(*v8);
			free(v8);
			v8 = v9;
		} while (v9);
	}
	v10 = *(_QWORD***)&dword_5d4594_1599564;
	if (dword_5d4594_1599564) {
		do {
			v11 = (_QWORD**)v10[1];
			if (dword_5d4594_1599476) {
				free(v10);
			} else {
				v12 = *((_DWORD*)*v10 + 21);
				if (v12) {
					do {
						v13 = *(_DWORD*)(v12 + 8);
						sub_57C390((_QWORD*)v12);
						v12 = v13;
					} while (v13);
				}
				sub_57C370(*v10);
				free(v10);
			}
			v10 = v11;
		} while (v11);
	}
	*getMemU32Ptr(0x5D4594, 1599568) = 0;
	dword_5d4594_1599564 = 0;
	return nox_xxx_mapReset_5028E0();
}

//----- (005040A0) --------------------------------------------------------
_DWORD*  nox_xxx_tileAllocTileInCoordList_5040A0(int a1, int a2, float a3) {
	_DWORD* result; // eax
	_DWORD* v4;     // esi
	void* v5;       // eax
	double v6;      // st7
	bool v7;        // zf
	float v8;       // [esp+10h] [ebp+Ch]

	result = malloc(0x18u);
	v4 = result;
	if (result) {
		v5 = malloc(0x14u);
		*v4 = v5;
		if (v5) {
			v4[5] = 0;
			v4[4] = dword_5d4594_1599556;
			if (dword_5d4594_1599556)
				*(_DWORD*)(dword_5d4594_1599556 + 20) = v4;
			dword_5d4594_1599556 = v4;
			v6 = (double)a1 * 46.0;
			++*getMemU32Ptr(0x5D4594, 1599560);
			v7 = LOBYTE(a3) == 1;
			*((_BYTE*)v4 + 12) = LOBYTE(a3);
			*((float*)v4 + 1) = v6;
			v8 = (double)a2 * 46.0;
			*((float*)v4 + 2) = v8;
			result = v4;
			if (v7)
				*((float*)v4 + 1) = v6 + 23.0;
			else
				*((float*)v4 + 2) = v8 + 23.0;
		} else {
			free(v4);
			result = 0;
		}
	}
	return result;
}

//----- (00504150) --------------------------------------------------------
int  nox_xxx_tileInit_504150(int a1, int a2) {
	int v2;         // eax
	const char* v3; // edx
	int v5;         // edi
	int* i;         // esi
	float2 a1a;     // [esp+Ch] [ebp-50h]
	char v8[72];    // [esp+14h] [ebp-48h]
	float v9;       // [esp+60h] [ebp+4h]
	float v10;      // [esp+64h] [ebp+8h]

	if (*getMemIntPtr(0x587000, 229704) == -1) {
		v2 = 0;
		if (*(int*)&dword_5d4594_251568 > 0) {
			v3 = (const char*)getMemAt(0x5D4594, 2682188);
			while (strcmp(v3, "TransparentFloor")) {
				++v2;
				v3 += 60;
				if (v2 >= *(int*)&dword_5d4594_251568)
					goto LABEL_8;
			}
			*getMemU32Ptr(0x587000, 229704) = v2;
		LABEL_8:
			if (v2 == -1)
				return 0;
		}
	}
	memcpy(v8, sub_4D3C70(), sizeof(v8));
	v5 = dword_5d4594_1599556;
	if (dword_5d4594_1599556) {
		v9 = (double)a1;
		v10 = (double)a2;
		do {
			a1a.field_0 = v9 + *(float*)(v5 + 4);
			a1a.field_4 = v10 + *(float*)(v5 + 8);
			nox_xxx_tileCheckImage_51D540(**(_DWORD**)v5);
			nox_xxx_tileCheckImageVari_51D570(*(_DWORD*)(*(_DWORD*)v5 + 4));
			nox_xxx_tile_51D5C0(1);
			if (**(_DWORD**)v5 != *getMemU32Ptr(0x587000, 229704))
				sub_51D8F0(&a1a);
			for (i = *(int**)(*(_DWORD*)v5 + 16); i; i = (int*)i[4]) {
				nox_xxx_tileCheckByte3_544070(i[2]);
				nox_xxx_tileCheckByte4_5440A0(i[3]);
				nox_xxx_tileCheckImage_51D540(*i);
				nox_xxx_tileCheckImageVari_51D570(i[1]);
				nox_xxx_tileSubtile_544310(&a1a);
			}
			v5 = *(_DWORD*)(v5 + 16);
		} while (v5);
	}
	nox_xxx_tileInitdataClear_4D3C50(v8);
	return 1;
}

//----- (00504290) --------------------------------------------------------
_DWORD*  sub_504290(char a1, char a2) {
	_DWORD* result; // eax
	_DWORD* v3;     // esi
	_BYTE* v4;      // eax

	result = malloc(0xCu);
	v3 = result;
	if (result) {
		result[2] = 0;
		result[1] = dword_5d4594_1599532;
		if (dword_5d4594_1599532)
			*(_DWORD*)(dword_5d4594_1599532 + 8) = result;
		dword_5d4594_1599532 = result;
		v4 = calloc(1u, 0x24u);
		*v3 = v4;
		v4[5] = a1;
		*(_BYTE*)(*v3 + 6) = a2;
		result = v3;
	}
	return result;
}

//----- (005042F0) --------------------------------------------------------
_DWORD*  nox_xxx_cliWallGet_5042F0(int a1, int a2) {
	_DWORD* result; // eax

	result = *(_DWORD**)&dword_5d4594_1599532;
	if (!dword_5d4594_1599532)
		return 0;
	while (*(unsigned __int8*)(*result + 5) != a1 || *(unsigned __int8*)(*result + 6) != a2) {
		result = (_DWORD*)result[1];
		if (!result)
			return 0;
	}
	return result;
}

//----- (00504330) --------------------------------------------------------
int  sub_504330(int a1, int a2) {
	unsigned __int8** v2; // edi
	int v3;               // ebp
	int v4;               // ecx
	int v6;               // ebx
	unsigned __int8* v7;  // esi
	unsigned __int8 v8;   // dl
	unsigned __int8 v9;   // al
	_DWORD* v11;          // [esp-4h] [ebp-14h]
	int v12;              // [esp-4h] [ebp-14h]

	v2 = *(unsigned __int8***)&dword_5d4594_1599532;
	if (!dword_5d4594_1599532)
		return 1;
	while (1) {
		v3 = (a1 + 23 * (*v2)[5]) / 23;
		v4 = a2 + 23 * (*v2)[6];
		v6 = v4 / 23;
		v7 = (unsigned __int8*)nox_server_getWallAtPoint_410580(v3, v6);
		if (v7) {
			v8 = **v2;
			if (dword_5d4594_3835368)
				*v7 = nox_xxx_wall_42A6C0(*v7, v8);
			else
				*v7 = v8;
			goto LABEL_8;
		}
		v7 = (unsigned __int8*)nox_xxx_wallCreateAt_410250(v3, v6);
		if (!v7)
			return 0;
		*v7 = **v2;
	LABEL_8:
		v7[1] = (*v2)[1];
		v7[2] = (*v2)[2];
		v7[7] = (*v2)[7];
		if (((*v2)[4] & 0x80u) != 0)
			v7[4] |= 0x80u;
		if (v7[2] >= nox_xxx_mapWallMaxVariation_410DD0(v7[1], *v7, 0))
			v7[2] = 0;
		if (v7[4] & 4)
			sub_4107A0(*((LPVOID*)v7 + 7));
		if ((*v2)[4] & 4) {
			v7[4] |= 4u;
			v11 = (_DWORD*)*((_DWORD*)*v2 + 7);
			*((_DWORD*)v7 + 7) = v11;
			nox_xxx_wallSecretBlock_410760(v11);
		}
		if ((*v2)[4] & 8) {
			v9 = v7[4];
			if (!(v9 & 8)) {
				v12 = *((_DWORD*)v7 + 7);
				v7[4] = v9 | 8;
				nox_xxx_wallBreackableListAdd_410840(v12);
			}
		}
		if ((*v2)[4] & 0x40)
			v7[4] |= 0x40u;
		v2 = (unsigned __int8**)v2[1];
		if (!v2)
			return 1;
	}
}

//----- (005044B0) --------------------------------------------------------
_DWORD*  sub_5044B0(int a1, float a2, float a3) {
	_DWORD* result; // eax
	_DWORD* v4;     // esi
	_DWORD* v5;     // eax
	_DWORD* v6;     // eax

	result = malloc(0xCu);
	v4 = result;
	if (result) {
		v5 = sub_579E70();
		*v4 = v5;
		if (v5) {
			v4[2] = 0;
			v4[1] = dword_5d4594_1599548;
			if (dword_5d4594_1599548)
				*(_DWORD*)(dword_5d4594_1599548 + 8) = v4;
			dword_5d4594_1599548 = v4;
			*(_DWORD*)*v4 = a1;
			*(float*)(*v4 + 8) = a2;
			*(float*)(*v4 + 12) = a3;
			*(_DWORD*)(*v4 + 488) = 0;
			v6 = (_DWORD*)v4[1];
			if (v6) {
				*(_DWORD*)(*v4 + 484) = *v6;
				*(_DWORD*)(*(_DWORD*)v4[1] + 488) = *v4;
				result = v4;
			} else {
				result = v4;
				*(_DWORD*)(*v4 + 484) = 0;
			}
		} else {
			free(v4);
			result = 0;
		}
	}
	return result;
}

//----- (00504560) --------------------------------------------------------
int  sub_504560(int a1, int a2) {
	int* v2;  // esi
	float v4; // [esp+8h] [ebp+4h]
	float v5; // [esp+Ch] [ebp+8h]

	v2 = *(int**)&dword_5d4594_1599548;
	if (dword_5d4594_1599548) {
		v4 = (double)a1;
		v5 = (double)a2;
		do {
			*(float*)(*v2 + 8) = v4 + *(float*)(*v2 + 8);
			*(float*)(*v2 + 12) = v5 + *(float*)(*v2 + 12);
			sub_579E90(*v2);
			v2 = (int*)v2[1];
		} while (v2);
	}
	return 1;
}

//----- (005045B0) --------------------------------------------------------
int sub_5045B0() {
	int result; // eax

	if (dword_5d4594_1599480 == dword_5d4594_3835396 && *(int*)&dword_5d4594_1599480 != -1 &&
			dword_5d4594_1599476 != 1 ||
		(result = nox_xxx_mapgenSaveMap_503830(*(int*)&dword_5d4594_3835396)) != 0) {
		result = **(_DWORD**)&dword_5d4594_1599548;
	}
	return result;
}

//----- (005045F0) --------------------------------------------------------
int  sub_5045F0(int a1) {
	int result; // eax

	result = a1;
	if (a1)
		result = *(_DWORD*)(a1 + 484);
	return result;
}

//----- (00504600) --------------------------------------------------------
_DWORD*  sub_504600(const char* a1, int a2, char a3) {
	_DWORD* v3;      // ebx
	_DWORD* result;  // eax
	void* v5;        // eax
	char* v6;        // edx
	unsigned int v7; // ecx
	char v8;         // al
	char* v9;        // edi
	const char* v10; // esi

	v3 = malloc(0xCu);
	if (!v3)
		return 0;
	v5 = sub_57C330();
	*v3 = v5;
	if (!v5)
		return 0;
	v3[2] = 0;
	v3[1] = dword_5d4594_1599564;
	if (dword_5d4594_1599564)
		*(_DWORD*)(dword_5d4594_1599564 + 8) = v3;
	dword_5d4594_1599564 = v3;
	*(_DWORD*)(*v3 + 88) = 0;
	*(_DWORD*)(*v3 + 92) = 0;
	*(_DWORD*)(*v3 + 84) = 0;
	*(_DWORD*)(*v3 + 4) = a2;
	*(_BYTE*)*v3 = a3;
	v6 = (char*)(*v3 + 8);
	v7 = strlen(a1) + 1;
	v8 = v7;
	v7 >>= 2;
	memcpy(v6, a1, 4 * v7);
	v10 = &a1[4 * v7];
	v9 = &v6[4 * v7];
	LOBYTE(v7) = v8;
	result = v3;
	memcpy(v9, v10, v7 & 3);
	return result;
}

//----- (005046A0) --------------------------------------------------------
int  sub_5046A0(_DWORD* a1, int a2) {
	char** v2;  // esi
	_DWORD* v4; // eax
	char v5;    // cl
	int v6;     // ecx

	v2 = *(char***)&dword_5d4594_1599564;
	if (!dword_5d4594_1599564)
		return 0;
	while (*((_DWORD*)*v2 + 1) != a2) {
		v2 = (char**)v2[1];
		if (!v2)
			return 0;
	}
	v4 = sub_57C360();
	if (!v4)
		return 0;
	v5 = **v2;
	if (!v5 || v5 == 1 || v5 == 3) {
		*v4 = *a1;
		goto LABEL_12;
	}
	if (v5 != 2)
		return 0;
	*v4 = *a1;
	v4[1] = a1[1];
LABEL_12:
	v4[3] = 0;
	v4[2] = *((_DWORD*)*v2 + 21);
	v6 = *((_DWORD*)*v2 + 21);
	if (v6)
		*(_DWORD*)(v6 + 12) = v4;
	*((_DWORD*)*v2 + 21) = v4;
	return 1;
}

//----- (00504720) --------------------------------------------------------
int  sub_504720(int a1, int a2) {
	int* v2; // esi

	sub_504760(a1, a2);
	v2 = *(int**)&dword_5d4594_1599564;
	if (dword_5d4594_1599564) {
		do {
			nox_server_addNewMapGroup_57C3B0(*v2);
			v2 = (int*)v2[1];
		} while (v2);
	}
	return 1;
}

//----- (00504760) --------------------------------------------------------
int  sub_504760(int a1, int a2) {
	int result;  // eax
	char** v3;   // ebp
	char v4;     // bl
	int* v5;     // esi
	int v6;      // eax
	int v7;      // ecx
	int v8;      // [esp+4h] [ebp-50h]
	char v9[76]; // [esp+8h] [ebp-4Ch]

	result = sub_57BF80();
	v3 = *(char***)&dword_5d4594_1599564;
	v8 = result;
	if (dword_5d4594_1599564) {
		while (1) {
			v4 = **v3;
			nox_sprintf(v9, "%s%%%d", *v3 + 8, dword_5d4594_3835312);
			strcpy(*v3 + 8, v9);
			result = (int)*v3;
			*((_DWORD*)*v3 + 1) += v8;
			v5 = (int*)*((_DWORD*)*v3 + 21);
			if (v5)
				break;
		LABEL_15:
			v3 = (char**)v3[1];
			if (!v3)
				return result;
		}
		while (1) {
			if (v4) {
				switch (v4) {
				case 1:
					result = sub_579C60(*v5);
					if (result)
						*v5 = *(_DWORD*)result;
					break;
				case 2:
					v6 = v5[1];
					*v5 = (a1 + 23 * *v5) / 23;
					v7 = a2 + 23 * v6;
					result = -1307163959 * v7;
					v5[1] = v7 / 23;
					break;
				case 3:
					result = v8 + *v5;
					goto LABEL_13;
				}
			} else {
				result = sub_4CFFE0(*v5);
				if (result) {
					result = *(_DWORD*)(result + 40);
				LABEL_13:
					*v5 = result;
					goto LABEL_14;
				}
			}
		LABEL_14:
			v5 = (int*)v5[2];
			if (!v5)
				goto LABEL_15;
		}
	}
	return result;
}

//----- (005048A0) --------------------------------------------------------
_DWORD*  nox_xxx_unitAddToList_5048A0(int a1) {
	_DWORD* result; // eax
	_DWORD* v2;     // ecx

	result = malloc(0xCu);
	if (!result)
		return 0;
	result[2] = 0;
	*result = a1;
	result[1] = dword_5d4594_1599540;
	if (dword_5d4594_1599540)
		*(_DWORD*)(dword_5d4594_1599540 + 8) = result;
	dword_5d4594_1599540 = result;
	*(_DWORD*)(*result + 448) = 0;
	v2 = (_DWORD*)result[1];
	if (v2) {
		*(_DWORD*)(*result + 444) = *v2;
		*(_DWORD*)(*(_DWORD*)result[1] + 448) = *result;
	} else {
		*(_DWORD*)(*result + 444) = 0;
	}
	return result;
}

//----- (00504910) --------------------------------------------------------
int  sub_504910(int a1, int a2) {
	int* v2;  // esi
	float v4; // [esp+8h] [ebp+4h]
	float v5; // [esp+Ch] [ebp+8h]

	v2 = *(int**)&dword_5d4594_1599540;
	if (dword_5d4594_1599540) {
		v4 = (double)a1;
		v5 = (double)a2;
		do {
			*(float*)(*v2 + 56) = v4 + *(float*)(*v2 + 56);
			*(float*)(*v2 + 60) = v5 + *(float*)(*v2 + 60);
			nox_xxx_createAt_4DAA50(*v2, 0, *(float*)(*v2 + 56), *(float*)(*v2 + 60));
			*(_DWORD*)(*v2 + 16) |= 0x80000000;
			v2 = (int*)v2[1];
		} while (v2);
	}
	return 1;
}

//----- (00504980) --------------------------------------------------------
int sub_504980() {
	int result; // eax

	if ((dword_5d4594_1599480 == dword_5d4594_3835396 && *(int*)&dword_5d4594_1599480 != -1 &&
			 dword_5d4594_1599476 != 1 ||
		 nox_xxx_mapgenSaveMap_503830(*(int*)&dword_5d4594_3835396)) &&
		dword_5d4594_1599540) {
		result = **(_DWORD**)&dword_5d4594_1599540;
	} else {
		result = 0;
	}
	return result;
}

//----- (005049C0) --------------------------------------------------------
int  sub_5049C0(int a1) {
	int result; // eax

	result = a1;
	if (a1)
		result = *(_DWORD*)(a1 + 444);
	return result;
}

//----- (005049D0) --------------------------------------------------------
LPVOID sub_5049D0() { return *(LPVOID*)&dword_5d4594_1599540; }

//----- (005049E0) --------------------------------------------------------
int  sub_5049E0(int a1) {
	int result; // eax

	result = a1;
	if (a1)
		result = *(_DWORD*)(a1 + 4);
	return result;
}

//----- (005049F0) --------------------------------------------------------
int  sub_5049F0(FILE* a1, int a2) { return fseek(a1, a2, SEEK_CUR); }

//----- (00504A10) --------------------------------------------------------
int  sub_504A10(int a1) {
	int* v1; // esi
	int v3;  // eax
	int v4;  // eax
	int v5;  // ecx
	int v6;  // ecx

	if (!a1)
		return 0;
	v1 = *(int**)&dword_5d4594_1599540;
	if (!dword_5d4594_1599540)
		return 0;
	while (*v1 != a1) {
		v1 = (int*)v1[1];
		if (!v1)
			return 0;
	}
	v3 = v1[1];
	if (v3)
		*(_DWORD*)(v3 + 8) = v1[2];
	v4 = v1[2];
	if (v4)
		*(_DWORD*)(v4 + 4) = v1[1];
	if (v1 == *(int**)&dword_5d4594_1599540)
		dword_5d4594_1599540 = v1[1];
	v5 = *(_DWORD*)(*v1 + 444);
	if (v5)
		*(_DWORD*)(v5 + 448) = *(_DWORD*)(*v1 + 448);
	v6 = *(_DWORD*)(*v1 + 448);
	if (v6)
		*(_DWORD*)(v6 + 444) = *(_DWORD*)(*v1 + 444);
	nox_xxx_objectFreeMem_4E38A0(*v1);
	free(v1);
	return 1;
}

//----- (00504AB0) --------------------------------------------------------
int  sub_504AB0(char* a1) {
	char* v1;       // eax
	const char* v2; // eax
	FILE* v3;       // ebp
	int result;     // eax
	FILE* v5;       // esi
	int v6;         // edi
	int v7;         // edi
	char v8;        // [esp+Fh] [ebp-851h]
	int v9;         // [esp+10h] [ebp-850h]
	int v10;        // [esp+14h] [ebp-84Ch]
	int v11;        // [esp+18h] [ebp-848h]
	int v12;        // [esp+1Ch] [ebp-844h]
	char v13[64];   // [esp+20h] [ebp-840h]
	char v14[2048]; // [esp+60h] [ebp-800h]

	v12 = 0;
	strcpy(v14, (const char*)sub_502A90());
	sub_502DF0();
	v1 = (char*)sub_502AF0();
	sub_502A50(v1);
	sub_502B10();
	v2 = (const char*)sub_502A90();
	v3 = nox_fs_open_rw(v2);
	if (v3) {
		v5 = nox_fs_open(a1);
		if (v5) {
			fseek(v3, -4, SEEK_END);
			fread(&v11, 4u, 1u, v5);
			if (v11 == -889266515) {
				while (1) {
					fread(&v10, 4u, 1u, v5);
					v6 = v10;
					if (!v10)
						break;
					fread(&v9, 1u, 1u, v5);
					fread(v13, (unsigned __int8)v9, 1u, v5);
					v7 = -1 - (unsigned __int8)v9 + v6;
					v13[(unsigned __int8)v9] = 0;
					if (sub_5029A0(v13) == -1) {
						fwrite(&v10, 4u, 1u, v3);
						fwrite(&v9, 1u, 1u, v3);
						fwrite(v13, (unsigned __int8)v9, 1u, v3);
						for (; v7; --v7) {
							fread(&v8, 1u, 1u, v5);
							fwrite(&v8, 1u, 1u, v3);
						}
					} else {
						fseek(v5, v7, SEEK_CUR);
					}
				}
				fwrite(&v12, 4u, 1u, v3);
				fclose(v3);
				fclose(v5);
				sub_502A50(v14);
				sub_502B10();
				result = 1;
			} else {
				fclose(v3);
				fclose(v5);
				sub_502A50(v14);
				sub_502B10();
				result = 0;
			}
		} else {
			fclose(v3);
			sub_502A50(v14);
			sub_502B10();
			result = 0;
		}
	} else {
		sub_502A50(v14);
		sub_502B10();
		result = 0;
	}
	return result;
}
// 504AB0: using guessed type char var_840[64];

//----- (00504CF0) --------------------------------------------------------
int  nox_server_mapRWObjectData_504CF0(_DWORD* a2) {
	int result;          // eax
	int i;               // esi
	int j;               // esi
	int v4;              // eax
	float v5;            // ecx
	int v6;              // eax
	_DWORD* v7;          // ebp
	unsigned __int16 v8; // ax
	_DWORD* v9;          // eax
	_DWORD* v10;         // edi
	int v11;             // ebx
	int v12;             // [esp+10h] [ebp-24h]
	int v13;             // [esp+14h] [ebp-20h]
	int v14;             // [esp+18h] [ebp-1Ch]
	int2 a1;             // [esp+1Ch] [ebp-18h]
	int4 v16;            // [esp+24h] [ebp-10h]

	v13 = 1;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v13, 2u);
	if ((__int16)v13 > 1)
		return 0;
	if (a2)
		sub_428170(a2, &v16);
	if (*getMemU32Ptr(0x5D4594, 3803300)) {
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v12, 2u);
		if ((_WORD)v12) {
			v7 = a2;
			while (1) {
				nox_xxx_fileCryptReadCrcMB_426C20(&a1, 4u);
				v8 = nox_xxx_objectTOCgetTT_42C2B0(v12);
				v9 = nox_new_objMem_2_4E3450(v8);
				v10 = v9;
				if (!v9)
					break;
				v11 = 0;
				if (!((int(*)(_DWORD*, unsigned int))v9[176])(v9, a2 != 0 ? (unsigned int)&v16 : 0))
					break;
				if (v10[4] & 0x400000) {
					v7 = (_DWORD*)v10[32];
					v11 = 1;
				}
				if (nox_xxx_servMapLoadPlaceObj_4F3F50((int)v10, 0, (int*)(a2 != 0 ? (unsigned int)&v16 : 0)) == 1 && v11 == 1)
					nox_xxx_unitSetDecayTime_511660(v10, (int)v7);
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v12, 2u);
				if (!(_WORD)v12)
					return 1;
			}
			nox_xxx_cryptClose_4269F0();
			return 0;
		}
		return 1;
	}
	for (i = nox_server_getFirstObject_4DA790(); i; i = nox_server_getNextObject_4DA7A0(i)) {
		if (!a2 || (a1.field_0 = nox_float2int(*(float*)(i + 56)), a1.field_4 = nox_float2int(*(float*)(i + 60)),
					sub_4280E0(&a1, a2))) {
			if (sub_4E3B80(*(unsigned __int16*)(i + 4)) && !nox_xxx_xfer_saveObj_51DF90(i))
				return 0;
		}
	}
	for (j = nox_xxx_getFirstUpdatable2Object_4DA840(); j; j = nox_xxx_getNextUpdatable2Object_4DA850(j)) {
		if (a2) {
			v4 = nox_float2int(*(float*)(j + 56));
			v5 = *(float*)(j + 60);
			a1.field_0 = v4;
			a1.field_4 = nox_float2int(v5);
			if (!sub_4280E0(&a1, a2))
				continue;
		}
		if (*(_DWORD*)(j + 8) & 0x1000000 && *(_BYTE*)(j + 12) & 0x40) {
			v6 = nox_xxx_inventoryGetFirst_4E7980(j);
			*(_DWORD*)(v6 + 56) = *(_DWORD*)(j + 56);
			*(_DWORD*)(v6 + 60) = *(_DWORD*)(j + 60);
			nox_xxx_xfer_saveObj_51DF90(v6);
		} else if (sub_4E3B80(*(unsigned __int16*)(j + 4)) && !nox_xxx_xfer_saveObj_51DF90(j)) {
			return 0;
		}
	}
	if (nox_common_gameFlags_check_40A5C0(0x200000) || !nox_common_gameFlags_check_40A5C0(1) ||
		nox_common_gameFlags_check_40A5C0(0x400000) || (result = sub_51DED0()) != 0) {
		v14 = 0;
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v14, 2u);
		return 1;
	}
	return result;
}

//----- (00505050) --------------------------------------------------------
LPVOID sub_505050() { return *(LPVOID*)&dword_5d4594_1599616; }

//----- (00505060) --------------------------------------------------------
LPVOID sub_505060() {
	LPVOID result; // eax

	result = *(LPVOID*)&dword_5d4594_1599616;
	if (dword_5d4594_1599616) {
		free(*(LPVOID*)&dword_5d4594_1599616);
		dword_5d4594_1599616 = 0;
	}
	return result;
}

//----- (00505080) --------------------------------------------------------
int nox_server_mapRWMapIntro_505080() {
	FILE* v0;           // ebx
	BOOL v1;            // ebp
	char* v2;           // edi
	__int16 v3;         // dx
	unsigned __int8 v4; // al
	char* v5;           // edi
	char* v6;           // edi
	unsigned __int8 v7; // cl
	__int16 v8;         // si
	int v9;             // edi
	FILE* v10;          // eax
	FILE* v11;          // esi
	int result;         // eax
	_BYTE* v13;         // eax
	_BYTE* v14;         // edi
	int i;              // esi
	char v16;           // [esp+13h] [ebp-409h]
	size_t v17;         // [esp+14h] [ebp-408h]
	int v18;            // [esp+18h] [ebp-404h]
	char v19[1024];     // [esp+1Ch] [ebp-400h]

	v0 = 0;
	v18 = 1;
	v17 = 0;
	v1 = nox_common_gameFlags_check_40A5C0(0x200000);
	sub_505060();
	v2 = nox_fs_root();
	v3 = *getMemU16Ptr(0x587000, 229832);
	strcpy(v19, v2);
	v4 = getMemByte(0x587000, 229834);
	v5 = &v19[strlen(v19)];
	*(_DWORD*)v5 = *getMemU32Ptr(0x587000, 229828);
	*((_WORD*)v5 + 2) = v3;
	v5[6] = v4;
	strcat(v19, nox_xxx_mapGetMapName_409B40());
	*(_WORD*)&v19[strlen(v19)] = *getMemU16Ptr(0x587000, 229836);
	strcat(v19, nox_xxx_mapGetMapName_409B40());
	v6 = &v19[strlen(v19) + 1];
	v7 = getMemByte(0x587000, 229844);
	v8 = v18;
	*(_DWORD*)--v6 = *getMemU32Ptr(0x587000, 229840);
	v6[4] = v7;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v18, 2u);
	if (v8 > (__int16)v18)
		return 0;
	v9 = 0;
	if (*getMemU32Ptr(0x5D4594, 3803300)) {
		if (*getMemU32Ptr(0x5D4594, 3803300) != 1) {
			return 0;
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v17, 4u);
		if ((int)v17 <= 0)
			return 1;
		if (nox_common_gameFlags_check_40A5C0(0x400000)) {
			sub_426AA0(v17);
			return 1;
		}
		if (v1) {
			v0 = nox_fs_create(v19);
			if (!v0) {
				return 0;
			}
			v14 = (_BYTE*)v18;
		} else {
			v13 = malloc(v17);
			dword_5d4594_1599616 = v13;
			if (!v13) {
				return 0;
			}
			v14 = v13;
		}
		for (i = 0; i < (int)v17; ++i) {
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v16, 1u);
			if (v1)
				fwrite(&v16, 1u, 1u, v0);
			else
				*v14++ = v16;
		}
		if (v0)
			fclose(v0);
		return 1;
	}
	if (v1 && (v10 = nox_fs_open(v19), (v11 = v10) != 0)) {
		fseek(v10, 0, SEEK_END);
		v17 = ftell(v11);
		fseek(v11, 0, SEEK_SET);
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v17, 4u);
		if ((int)v17 > 0) {
			do {
				fread(&v16, 1u, 1u, v11);
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v16, 1u);
				++v9;
			} while (v9 < (int)v17);
		}
		fclose(v11);
		result = 1;
	} else {
		v17 = 0;
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v17, 4u);
		result = 1;
	}
	return result;
}
// 505080: using guessed type char var_400[1024];

//----- (00505A40) --------------------------------------------------------
int nox_server_mapRWScriptObject_505A40() {
	int v0;   // edi
	char* v1; // eax
	FILE* v2; // eax
	FILE* v3; // esi
	FILE* v5; // esi
	int i;    // ebx
	int j;    // ebx
	char v8;  // [esp+Bh] [ebp-9h]
	int v9;   // [esp+Ch] [ebp-8h]
	int v10;  // [esp+10h] [ebp-4h]

	v0 = 0;
	v10 = 1;
	v9 = 0;
	nox_xxx_wallGet_426A30();
	v1 = nox_fs_root();
	nox_sprintf((char*)getMemAt(0x5D4594, 3830188), "%s\\nc.obj", v1);
	dword_5d4594_1599644 = 0;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v10, 2u);
	if ((__int16)v10 < 1)
		return 0;
	if (!*getMemU32Ptr(0x5D4594, 3803300)) {
		v2 = nox_fs_open((const char*)getMemAt(0x5D4594, 3830188));
		v3 = v2;
		if (!v2) {
			v9 = 0;
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v9, 4u);
			return 1;
		}
		fseek(v2, 0, SEEK_END);
		v9 = ftell(v3);
		fseek(v3, 0, SEEK_SET);
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v9, 4u);
		if (v9 > 0) {
			do {
				fread(&v8, 1u, 1u, v3);
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v8, 1u);
				++v0;
			} while (v0 < v9);
		}
		fclose(v3);
		return 1;
	}
	if (*getMemU32Ptr(0x5D4594, 3803300) != 1)
		return 0;
	v5 = nox_fs_create((const char*)getMemAt(0x5D4594, 3830188));
	if (!v5)
		return 0;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v9, 4u);
	dword_5d4594_1599644 = v9;
	if (nox_common_gameFlags_check_40A5C0(0x400000)) {
		for (i = 0; i < v9; ++i) {
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v8, 1u);
			fwrite(&v8, 1u, 1u, v5);
		}
	} else {
		for (j = 0; j < v9; ++j) {
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v8, 1u);
			fwrite(&v8, 1u, 1u, v5);
		}
	}
	fclose(v5);
	if (v9 <= 0 || nox_common_gameFlags_check_40A5C0(6291456))
		return 1;
	return nox_script_ncobj_parse_505360();
}

//----- (00505C30) --------------------------------------------------------
int nox_server_mapRWGroupData_505C30() {
	char v0;      // bp
	int i;        // eax
	int j;        // eax
	char v7;      // al
	bool v8;      // zf
	char* v9;     // eax
	char* v10;    // esi
	int v12;      // [esp+10h] [ebp-15Ch]
	char v14[2];  // [esp+1Ah] [ebp-152h]
	int v15;      // [esp+1Ch] [ebp-150h]
	int v16;      // [esp+20h] [ebp-14Ch]
	int v17;      // [esp+24h] [ebp-148h]
	int v18;      // [esp+28h] [ebp-144h]
	int v19[2];   // [esp+2Ch] [ebp-140h]
	int v21;      // [esp+34h] [ebp-138h]
	int v22;      // [esp+38h] [ebp-134h]
	char v23[76]; // [esp+3Ch] [ebp-130h]
	char v24[76]; // [esp+88h] [ebp-E4h]
	char v25[76]; // [esp+D4h] [ebp-98h]
	char v26[76]; // [esp+120h] [ebp-4Ch]

	v15 = 3;
	v0 = nox_xxx_wallGet_426A30();
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v15, 2u);
	if ((__int16)v15 > 3)
		return 0;

	if (*getMemU32Ptr(0x5D4594, 3803300)) {
		v21 = 0;
		v22 = 0;
		int v13;
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v13, 4u);
		if (v13 <= 0)
			return 1;
		for (int v2 = 0; v2 < v13; ++v2) {
			v17 = 0;
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v17, 1u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(v23, (unsigned __int8)v17);
			v23[v17] = 0; // null-term missing
			v8 = (_WORD)v15 == 2;
			if ((__int16)v15 < 2) {
				if (strlen(nox_server_currentMapGetFilename_409B30()) + 1 + strlen(v23) >= 0x35)
					return 0;
				v9 = nox_server_currentMapGetFilename_409B30();
				nox_sprintf(v25, "%s.map:%s", v9, v23);
				strcpy(v23, v25);
				v8 = (_WORD)v15 == 2;
			}
			if (v8) {
				strcpy(v14, ":");
				strcpy(v24, nox_server_currentMapGetFilename_409B30());
				*(_WORD*)&v24[strlen(v24)] = *getMemU16Ptr(0x587000, 229976);
				strcpy(v26, v23);
				strtok(v26, v14);
				v10 = strtok(0, v14);
				if (strlen(nox_server_currentMapGetFilename_409B30()) + 1 + strlen(v10) >= 0x35)
					return 0;
				strcat(v24, v10);
				strcpy(v23, v24);
			}
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v18, 1u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v16, 4u);
			if (!(v0 & 4)) {
				if (nox_common_gameFlags_check_40A5C0(0x400000)) {
					sub_504600(v23, v16, v18);
				} else if (nox_common_gameFlags_check_40A5C0(2097153)) {
					nox_server_mapLoadAddGroup_57C0C0(v23, v16, v18);
				}
			}
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v12, 4u);

			for (int v11 = 0; v11 < v12; ++v11) {
				if ((_BYTE)v18) {
					if ((_BYTE)v18 == 1) {
						nox_xxx_fileReadWrite_426AC0_file3_fread(&v19[0], 4u);
					} else if ((_BYTE)v18 != 2) {
						if ((_BYTE)v18 != 3)
							return 0;
						nox_xxx_fileReadWrite_426AC0_file3_fread(&v19[0], 4u);
					} else {
						nox_xxx_fileReadWrite_426AC0_file3_fread(&v19[0], 4u);
						nox_xxx_fileReadWrite_426AC0_file3_fread(&v19[1], 4u);
					}
				} else {
					nox_xxx_fileReadWrite_426AC0_file3_fread(&v19[0], 4u);
				}
				if (!(v0 & 4)) {
					if (nox_common_gameFlags_check_40A5C0(0x400000))
						sub_5046A0(v19, v16);
					else
						sub_57C130(v19, v16);
				}
			}
		}
		return 1;
	}
	int v13 = 0;
	for (i = nox_server_getFirstMapGroup_57C080(); i; i = nox_server_getNextMapGroup_57C090(i))
		++v13;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v13, 4u);
	for (int v4 = nox_server_getFirstMapGroup_57C080(); v4; v4 = nox_server_getNextMapGroup_57C090(v4)) {
		LOBYTE(v17) = strlen((const char*)(v4 + 8)) + 1;
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v17, 1u);
		nox_xxx_fileReadWrite_426AC0_file3_fread((_BYTE*)(v4 + 8), (unsigned __int8)v17);
		nox_xxx_fileReadWrite_426AC0_file3_fread((_BYTE*)v4, 1u);
		nox_xxx_fileReadWrite_426AC0_file3_fread((_BYTE*)(v4 + 4), 4u);
		v12 = 0;
		for (j = *(_DWORD*)(v4 + 84); j; j = *(_DWORD*)(j + 8))
			++v12;
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v12, 4u);
		for (int v6 = *(_DWORD*)(v4 + 84); v6; v6 = *(_DWORD*)(v6 + 8)) {
			v7 = *(_BYTE*)v4;
			if (!*(_BYTE*)v4 || v7 == 1) {
				nox_xxx_fileReadWrite_426AC0_file3_fread((_BYTE*)v6, 4u);
			} else if (v7 != 2) {
				if (v7 != 3)
					return 0;
				nox_xxx_fileReadWrite_426AC0_file3_fread((_BYTE*)v6, 4u);
			} else {
				nox_xxx_fileReadWrite_426AC0_file3_fread((_BYTE *) v6, 4u);
				nox_xxx_fileReadWrite_426AC0_file3_fread((_BYTE *) (v6 + 4), 4u);
			}
		}
	}
	return 1;
}
// 505C30: using guessed type char var_E4[76];

//----- (005060D0) --------------------------------------------------------
int nox_server_mapRWDebugData_5060D0() {
	int j;        // eax
	char* v2;     // esi
	int i;        // esi
	size_t v4;    // [esp+0h] [ebp-15Ch]
	int v5;       // [esp+4h] [ebp-158h]
	int v6;       // [esp+8h] [ebp-154h]
	char v7[80];  // [esp+Ch] [ebp-150h]
	char v8[256]; // [esp+5Ch] [ebp-100h]

	v6 = 1;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v6, 2u);
	if ((__int16)v6 < 1)
		return 0;
	if (*getMemU32Ptr(0x5D4594, 3803300)) {
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v5, 4u);
		for (i = 0; i < v5; ++i) {
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v4, 4u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(v7, v4);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v4, 4u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(v8, v4);
			if (!nox_common_gameFlags_check_40A5C0(0x400000) && nox_common_gameFlags_check_40A5C0(1))
				sub_57C500(v7, v8);
		}
		return 1;
	}
	v5 = 0;
	for (j = nox_xxx_getDebugData_57C3E0(); j; j = nox_xxx_nextDebugObject_57C3F0(j))
		++v5;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v5, 4u);
	v2 = (char*)nox_xxx_getDebugData_57C3E0();
	if (!v2)
		return 1;
	do {
		v4 = strlen(v2);
		++v4;
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v4, 4u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(v2, v4);
		v4 = strlen(v2 + 80);
		++v4;
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v4, 4u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(v2 + 80, v4);
		v2 = (char*)nox_xxx_nextDebugObject_57C3F0((int)v2);
	} while (v2);
	return 1;
}

//----- (00506260) --------------------------------------------------------
int  nox_server_mapRWWaypoints_506260(_DWORD* a1) {
	float* v2;        // esi
	_DWORD* v3;       // edi
	char* v4;         // esi
	int v5;           // ebx
	_BYTE* v6;        // edi
	char* v7;         // esi
	char** v8;        // eax
	char* v9;         // ebp
	_BYTE* v10;       // esi
	int v11;          // ebx
	_BYTE* v12;       // ebp
	_BYTE* v13;       // edi
	int v14;          // ebx
	_BYTE* v15;       // ebp
	_BYTE* v16;       // edi
	float* v17;       // [esp+10h] [ebp-9Ch]
	int v18;          // [esp+14h] [ebp-98h]
	int v19;          // [esp+18h] [ebp-94h]
	int v20;          // [esp+1Ch] [ebp-90h]
	unsigned int v21; // [esp+20h] [ebp-8Ch]
	float v22;        // [esp+24h] [ebp-88h]
	float v23;        // [esp+28h] [ebp-84h]
	int v24;          // [esp+2Ch] [ebp-80h]
	int v25;          // [esp+30h] [ebp-7Ch]
	int2 v26;         // [esp+34h] [ebp-78h]
	int v27;          // [esp+3Ch] [ebp-70h]
	__int64 v28;      // [esp+40h] [ebp-6Ch]
	__int64 v29;      // [esp+48h] [ebp-64h]
	int4 v30;         // [esp+50h] [ebp-5Ch]
	char v31[76];     // [esp+60h] [ebp-4Ch]

	v18 = 4;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v18, 2u);
	if ((__int16)v18 > 4)
		return 0;
	if (*getMemU32Ptr(0x5D4594, 3803300)) {
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v19, 4u);
		v24 = 0;
		if (v19 > 0) {
			while (1) {
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v25, 4u);
				if ((__int16)v18 < 4) {
					nox_xxx_fileReadWrite_426AC0_file3_fread(&v21, 4u);
					v28 = v21;
					v22 = (double)v21;
					nox_xxx_fileReadWrite_426AC0_file3_fread(&v21, 4u);
					v29 = v21;
					v23 = (double)v21;
				} else {
					nox_xxx_fileReadWrite_426AC0_file3_fread(&v22, 4u);
					nox_xxx_fileReadWrite_426AC0_file3_fread(&v23, 4u);
				}
				if ((__int16)v18 >= 3) {
					nox_xxx_fileReadWrite_426AC0_file3_fread(&v20, 1u);
					if ((_BYTE)v20) {
						nox_xxx_fileReadWrite_426AC0_file3_fread(v31, (unsigned __int8)v20);
						v31[(unsigned __int8)v20] = 0;
					} else {
						v31[0] = getMemByte(0x5D4594, 1599648);
					}
				}
				if (a1) {
					v7 = nox_xxx_mapGetWallSize_426A70();
					sub_428170(a1, &v30);
					v22 = v22 - (double)(int)(23 * *(_DWORD*)v7) + (double)v30.field_0 - 11.0;
					v23 = v23 - (double)(int)(23 * *((_DWORD*)v7 + 1)) + (double)v30.field_4 - 11.0;
				}
				if (nox_common_gameFlags_check_40A5C0(0x400000)) {
					v8 = (char**)sub_5044B0(v25, v22, v23);
					v9 = *v8;
					v17 = (float*)*v8;
				} else {
					v17 = nox_xxx_waypointNewNotMap_579970(v25, v22, v23);
					v9 = (char*)v17;
				}
				if (!v9)
					break;
				if ((__int16)v18 >= 3)
					strcpy(v9 + 16, v31);
				nox_xxx_fileReadWrite_426AC0_file3_fread(v9 + 480, 4u);
				if ((__int16)v18 < 4) {
					nox_xxx_fileReadWrite_426AC0_file3_fread(&v21, 4u);
					v10 = v9 + 476;
					v9[476] = v21;
				} else {
					v10 = v9 + 476;
					nox_xxx_fileReadWrite_426AC0_file3_fread(v9 + 476, 1u);
				}
				if ((__int16)v18 >= 2) {
					v14 = 0;
					if (*v10) {
						v15 = v9 + 96;
						v16 = v17 + 87;
						do {
							nox_xxx_fileReadWrite_426AC0_file3_fread(v16, 4u);
							nox_xxx_fileReadWrite_426AC0_file3_fread(v15, 1u);
							++v14;
							v16 += 4;
							v15 += 8;
						} while (v14 < (unsigned __int8)*v10);
					}
				} else {
					v11 = 0;
					if (*v10) {
						v12 = v9 + 96;
						v13 = v17 + 87;
						do {
							nox_xxx_fileReadWrite_426AC0_file3_fread(v13, 4u);
							*v12 = 2;
							++v11;
							v13 += 4;
							v12 += 8;
						} while (v11 < (unsigned __int8)*v10);
					}
				}
				if (++v24 >= v19)
					return 1;
			}
			return 0;
		}
		return 1;
	}
	v19 = 0;
	v2 = (float*)nox_xxx_waypointGetList_579860();
	if (v2) {
		do {
			v3 = a1;
			if (!a1 || (v26.field_0 = (__int64)v2[2], v26.field_4 = (__int64)v2[3], nox_xxx_wallMath_427F30(&v26, a1)))
				++v19;
			v2 = (float*)nox_xxx_waypointNext_579870((int)v2);
		} while (v2);
	} else {
		v3 = a1;
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v19, 4u);
	v4 = (char*)nox_xxx_waypointGetList_579860();
	if (!v4)
		return 1;
	do {
		if (!v3 || (v26.field_0 = (__int64)*((float*)v4 + 2), v26.field_4 = (__int64)*((float*)v4 + 3),
					nox_xxx_wallMath_427F30(&v26, v3))) {
			nox_xxx_fileReadWrite_426AC0_file3_fread(v4, 4u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(v4 + 8, 4u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(v4 + 12, 4u);
			LOBYTE(v20) = strlen(v4 + 16);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v20, 1u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(v4 + 16, (unsigned __int8)v20);
			v27 = *((_DWORD*)v4 + 120) & 1;
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v27, 4u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(v4 + 476, 1u);
			v5 = 0;
			if (v4[476]) {
				v6 = v4 + 96;
				do {
					nox_xxx_fileReadWrite_426AC0_file3_fread(*((_BYTE**)v6 - 1), 4u);
					nox_xxx_fileReadWrite_426AC0_file3_fread(v6, 1u);
					++v5;
					v6 += 8;
				} while (v5 < (unsigned __int8)v4[476]);
			}
			v3 = a1;
		}
		v4 = (char*)nox_xxx_waypointNext_579870((int)v4);
	} while (v4);
	return 1;
}
// 506260: using guessed type char var_4C[76];

//----- (005066D0) --------------------------------------------------------
int nox_xxx_allocVoteArray_5066D0() {
	int result; // eax

	result = nox_new_alloc_class("VoteClass", 52, 64);
	nox_alloc_vote_1599652 = result;
	if (result) {
		dword_5d4594_1599656 = 0;
		result = 1;
	}
	return result;
}

//----- (00506700) --------------------------------------------------------
void sub_506700() {
	nox_alloc_class_yyy_4144D0(*(_DWORD**)&nox_alloc_vote_1599652);
	dword_5d4594_1599656 = 0;
}

//----- (00506720) --------------------------------------------------------
int sub_506720() {
	int result; // eax

	nox_free_alloc_class(*(LPVOID*)&nox_alloc_vote_1599652);
	result = 0;
	nox_alloc_vote_1599652 = 0;
	dword_5d4594_1599656 = 0;
	return result;
}

//----- (00506740) --------------------------------------------------------
int  sub_506740(int a1) {
	int result; // eax
	int v2;     // esi
	int v3;     // ecx
	int v4;     // edi

	result = a1;
	if (a1) {
		if (*(_BYTE*)(a1 + 8) & 4) {
			result = dword_5d4594_1599656;
			v2 = 1 << *(_BYTE*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276) + 2064);
			if (dword_5d4594_1599656) {
				do {
					v3 = *(_DWORD*)(result + 8);
					v4 = *(_DWORD*)(result + 44);
					if (v3 & v2) {
						*(_DWORD*)(result + 8) = ~v2 & v3;
						--*(_BYTE*)(result + 4);
					}
					if (!*(_BYTE*)(result + 4))
						sub_5067B0(result);
					result = v4;
				} while (v4);
			}
		}
	}
	return result;
}

//----- (005067B0) --------------------------------------------------------
void  sub_5067B0(int a1) {
	int v1; // esi

	if (a1) {
		if (*(_DWORD*)a1 == 2) {
			v1 = 0;
			do {
				if ((1 << v1) & *(_DWORD*)(a1 + 8))
					nox_xxx_netSendVote_506840(v1);
				++v1;
			} while (v1 < 32);
		}
		sub_506810(a1);
		nox_alloc_class_free_obj(*(unsigned int**)&nox_alloc_vote_1599652, (_QWORD*)a1);
		if (!dword_5d4594_1599656)
			sub_507190(255, 0);
	}
}

//----- (00506810) --------------------------------------------------------
int  sub_506810(int a1) {
	int result; // eax
	int v2;     // ecx
	int v3;     // ecx

	result = a1;
	v2 = *(_DWORD*)(a1 + 44);
	if (v2)
		*(_DWORD*)(v2 + 48) = *(_DWORD*)(a1 + 48);
	v3 = *(_DWORD*)(a1 + 48);
	if (v3) {
		result = *(_DWORD*)(a1 + 44);
		*(_DWORD*)(v3 + 44) = result;
	} else {
		dword_5d4594_1599656 = *(_DWORD*)(a1 + 44);
	}
	return result;
}

//----- (00506840) --------------------------------------------------------
int  nox_xxx_netSendVote_506840(int a1) {
	char v2[2]; // [esp+0h] [ebp-2h]

	v2[0] = -18;
	v2[1] = 7;
	return nox_xxx_netSendPacket1_4E5390(a1, (int)v2, 2, 0, 1);
}

//----- (00506870) --------------------------------------------------------
char  sub_506870(int a1, int a2, wchar_t* a3) {
	char result; // al

	result = a2;
	if (a2 && *(_BYTE*)(a2 + 8) & 4) {
		switch (a1) {
		case 0:
			result = sub_5068E0(0, a2, a3);
			break;
		case 1:
			result = sub_5068E0(1, a2, a3);
			break;
		case 2:
			result = (unsigned int)sub_506B00(2, a2);
			break;
		case 3:
			result = (unsigned int)sub_506B80(3, a2, a3);
			break;
		default:
			return result;
		}
	}
	return result;
}

//----- (005068E0) --------------------------------------------------------
char  sub_5068E0(int a1, int a2, wchar_t* a3) {
	int v3; // eax
	int v4; // ebp
	int v5; // esi
	int v6; // edi
	int v7; // esi

	LOBYTE(v3) = getMemByte(0x587000, 229980);
	if (*getMemU32Ptr(0x587000, 229980) <= 0x20u) {
		if (*getMemU32Ptr(0x587000, 229980)) {
			if (a3) {
				if (a2) {
					v4 = 1 << *(_BYTE*)(*(_DWORD*)(*(_DWORD*)(a2 + 748) + 276) + 2064);
					v3 = nox_common_playerInfoGetFirst_416EA0();
					v5 = v3;
					if (v3) {
						while (1) {
							if (*(_DWORD*)(v5 + 2092) == 1) {
								v3 = nox_wcscmp((const wchar_t*)(v5 + 4704), a3);
								if (!v3)
									break;
							}
							v3 = nox_common_playerInfoGetNext_416EE0(v5);
							v5 = v3;
							if (!v3)
								return v3;
						}
						if (*(_BYTE*)(v5 + 2064) != 31) {
							v6 = *(_DWORD*)(v5 + 2056);
							if (v6) {
								if (a2 != v6) {
									if (!nox_xxx_CheckGameplayFlags_417DA0(4) || (v3 = nox_xxx_servCompareTeams_419150(a2 + 48, v6 + 48)) != 0) {
										v7 = dword_5d4594_1599656;
										if (!dword_5d4594_1599656)
											goto LABEL_21;
										while (*(_DWORD*)v7 != a1 || *(_DWORD*)(v7 + 28) != v6) {
											v7 = *(_DWORD*)(v7 + 44);
											if (!v7)
												goto LABEL_21;
										}
										if (!v7) {
										LABEL_21:
											v3 = sub_506A20(a1, a2);
											v7 = v3;
											if (!v3)
												return v3;
											*(_DWORD*)(v3 + 28) = v6;
											if (nox_xxx_CheckGameplayFlags_417DA0(4))
												*(_DWORD*)(v7 + 20) = 1;
										}
										v3 = *(_DWORD*)(v7 + 8);
										if (!(v4 & v3)) {
											LOBYTE(v3) = *(_BYTE*)(v7 + 4) + 1;
											*(_DWORD*)(v7 + 8) |= v4;
											*(_BYTE*)(v7 + 4) = v3;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return v3;
}

//----- (00506A20) --------------------------------------------------------
_DWORD*  sub_506A20(int a1, int a2) {
	int v2;     // ebx
	_DWORD* v3; // esi

	v2 = 0;
	if (!a2 || !(*(_BYTE*)(a2 + 8) & 4))
		return 0;
	if (!dword_5d4594_1599656)
		v2 = 1;
	v3 = nox_alloc_class_new_obj_zero(*(_DWORD**)&nox_alloc_vote_1599652);
	if (!v3)
		return 0;
	*v3 = a1;
	v3[6] = *getMemU32Ptr(0x5D4594, 2598000);
	v3[4] = a2 + 48;
	switch (a1) {
	case 0:
	case 1:
		*((_BYTE*)v3 + 12) = getMemByte(0x587000, 229980);
		break;
	case 2:
	case 3:
		*((_BYTE*)v3 + 12) = 6;
		break;
	default:
		*((_BYTE*)v3 + 12) = getMemByte(0x587000, 229984);
		break;
	}
	nox_xxx_voteAddMB_506AD0((int)v3);
	if (v2)
		sub_507190(255, 1);
	return v3;
}

//----- (00506AD0) --------------------------------------------------------
int  nox_xxx_voteAddMB_506AD0(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)(a1 + 48) = 0;
	*(_DWORD*)(a1 + 44) = dword_5d4594_1599656;
	if (dword_5d4594_1599656)
		*(_DWORD*)(dword_5d4594_1599656 + 48) = a1;
	dword_5d4594_1599656 = a1;
	return result;
}

//----- (00506B00) --------------------------------------------------------
_DWORD*  sub_506B00(int a1, int a2) {
	_DWORD* result; // eax
	int v3;         // esi
	char v4;        // cl

	result = *(_DWORD**)&nox_server_resetQuestMinVotes_229988;
	if (nox_server_resetQuestMinVotes_229988) {
		if (a2) {
			result = *(_DWORD**)(*(_DWORD*)(a2 + 748) + 276);
			v3 = 1 << *((_BYTE*)result + 2064);
			if (result[1198]) {
				result = *(_DWORD**)&dword_5d4594_1599656;
				if (!dword_5d4594_1599656)
					goto LABEL_9;
				while (*result != a1) {
					result = (_DWORD*)result[11];
					if (!result)
						goto LABEL_9;
				}
				if (!result) {
				LABEL_9:
					result = sub_506A20(a1, a2);
					if (!result)
						return result;
					result[5] = 0;
				}
				if (!(result[2] & v3)) {
					v4 = *((_BYTE*)result + 4) + 1;
					result[2] |= v3;
					*((_BYTE*)result + 4) = v4;
				}
			}
		}
	}
	return result;
}

//----- (00506B80) --------------------------------------------------------
_DWORD*  sub_506B80(int a1, int a2, wchar_t* a3) {
	_DWORD* result;    // eax
	int v4;            // edi
	const wchar_t* v5; // esi
	int v6;            // esi
	char v7;           // cl

	result = *(_DWORD**)&nox_server_kickQuestPlayerMinVotes_229992;
	if (nox_server_kickQuestPlayerMinVotes_229992) {
		if (a3) {
			result = (_DWORD*)a2;
			if (a2) {
				result = *(_DWORD**)(*(_DWORD*)(a2 + 748) + 276);
				v4 = 1 << *((_BYTE*)result + 2064);
				if (result[1198]) {
					result = nox_common_playerInfoGetFirst_416EA0();
					v5 = (const wchar_t*)result;
					if (result) {
						while (1) {
							if (*((_DWORD*)v5 + 523) == 1) {
								result = (_DWORD*)nox_wcscmp(v5 + 2352, a3);
								if (!result)
									break;
							}
							result = nox_common_playerInfoGetNext_416EE0((int)v5);
							v5 = (const wchar_t*)result;
							if (!result)
								return result;
						}
						if (*((_BYTE*)v5 + 2064) != 31) {
							result = (_DWORD*)*((_DWORD*)v5 + 1198);
							if (result) {
								v6 = *((_DWORD*)v5 + 514);
								if (v6) {
									if (a2 != v6) {
										result = *(_DWORD**)&dword_5d4594_1599656;
										if (!dword_5d4594_1599656)
											goto LABEL_20;
										while (*result != a1 || result[7] != v6) {
											result = (_DWORD*)result[11];
											if (!result)
												goto LABEL_20;
										}
										if (!result) {
										LABEL_20:
											result = sub_506A20(a1, a2);
											if (!result)
												return result;
											result[7] = v6;
										}
										if (!(result[2] & v4)) {
											v7 = *((_BYTE*)result + 4) + 1;
											result[2] |= v4;
											*((_BYTE*)result + 4) = v7;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return result;
}

//----- (00506C90) --------------------------------------------------------
void  sub_506C90(int a1, int a2, wchar_t* a3) {
	if (a2 && *(_BYTE*)(a2 + 8) & 4) {
		switch (a1) {
		case 0:
			sub_506D00(a2, a3);
			break;
		case 1:
			sub_506D00(a2, a3);
			break;
		case 2:
			sub_506DE0(a2);
			break;
		case 3:
			sub_506E50(a2, a3);
			break;
		default:
			return;
		}
	}
}

//----- (00506D00) --------------------------------------------------------
void  sub_506D00(int a1, wchar_t* a2) {
	char* v2; // esi
	int v3;   // esi
	int v4;   // eax
	int v5;   // edx
	int v6;   // esi
	bool v7;  // zf

	if (a1) {
		if (a2) {
			if (*(_BYTE*)(a1 + 8) & 4) {
				v2 = nox_common_playerInfoGetFirst_416EA0();
				if (v2) {
					while (*((_DWORD*)v2 + 523) != 1 || nox_wcscmp((const wchar_t*)v2 + 2352, a2)) {
						v2 = nox_common_playerInfoGetNext_416EE0((int)v2);
						if (!v2)
							return;
					}
					if (v2[2064] != 31) {
						v3 = *((_DWORD*)v2 + 514);
						if (v3) {
							v4 = dword_5d4594_1599656;
							v5 = 1 << *(_BYTE*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276) + 2064);
							if (dword_5d4594_1599656) {
								while (*(_DWORD*)v4 || *(_DWORD*)(v4 + 28) != v3 || !(v5 & *(_DWORD*)(v4 + 8))) {
									v4 = *(_DWORD*)(v4 + 44);
									if (!v4)
										return;
								}
								if (v4) {
									v6 = ~v5 & *(_DWORD*)(v4 + 8);
									v7 = (*(_BYTE*)(v4 + 4))-- == 1;
									*(_DWORD*)(v4 + 8) = v6;
									if (v7)
										sub_5067B0(v4);
								}
							}
						}
					}
				}
			}
		}
	}
}

//----- (00506DE0) --------------------------------------------------------
void  sub_506DE0(int a1) {
	int result;
	int v2;  // edx
	char v3; // cl
	int v4;  // esi

	if (a1) {
		if (*(_BYTE*)(a1 + 8) & 4) {
			result = dword_5d4594_1599656;
			v2 = 1 << *(_BYTE*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276) + 2064);
			if (dword_5d4594_1599656) {
				while (*(_DWORD*)result != 2) {
					result = *(_DWORD*)(result + 44);
					if (!result)
						return;
				}
				if (result && v2 & *(_DWORD*)(result + 8)) {
					v3 = *(_BYTE*)(result + 4) - 1;
					v4 = ~v2 & *(_DWORD*)(result + 8);
					*(_BYTE*)(result + 4) = v3;
					*(_DWORD*)(result + 8) = v4;
					if (!v3)
						sub_5067B0(result);
				}
			}
		}
	}
}

//----- (00506E50) --------------------------------------------------------
void  sub_506E50(int a1, wchar_t* a2) {
	char* v2; // esi
	int v3;   // esi
	int v4;   // eax
	int v5;   // edx
	int v6;   // esi
	bool v7;  // zf

	if (a1) {
		if (a2) {
			if (*(_BYTE*)(a1 + 8) & 4) {
				v2 = nox_common_playerInfoGetFirst_416EA0();
				if (v2) {
					while (*((_DWORD*)v2 + 523) != 1 || nox_wcscmp((const wchar_t*)v2 + 2352, a2)) {
						v2 = nox_common_playerInfoGetNext_416EE0((int)v2);
						if (!v2)
							return;
					}
					if (v2[2064] != 31) {
						v3 = *((_DWORD*)v2 + 514);
						if (v3) {
							v4 = dword_5d4594_1599656;
							v5 = 1 << *(_BYTE*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276) + 2064);
							if (dword_5d4594_1599656) {
								while (*(_DWORD*)v4 != 3 || *(_DWORD*)(v4 + 28) != v3 || !(v5 & *(_DWORD*)(v4 + 8))) {
									v4 = *(_DWORD*)(v4 + 44);
									if (!v4)
										return;
								}
								if (v4) {
									v6 = ~v5 & *(_DWORD*)(v4 + 8);
									v7 = (*(_BYTE*)(v4 + 4))-- == 1;
									*(_DWORD*)(v4 + 8) = v6;
									if (v7)
										sub_5067B0(v4);
								}
							}
						}
					}
				}
			}
		}
	}
}

//----- (00506F80) --------------------------------------------------------
void  sub_506F80(int a1) {
	int v1; // esi
	int v3; // esi

	v1 = *(_DWORD*)(a1 + 28);
	if (*(_BYTE*)(v1 + 16) & 0x20) {
		sub_5067B0(a1);
		return;
	}
	*(_DWORD*)(a1 + 16) = v1 + 48;
	if (sub_507000(a1) == 1) {
		v3 = *(_DWORD*)(v1 + 748);
		nox_xxx_playerCallDisconnect_4DEAB0(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), 4);
		sub_416770(15, (wchar_t*)(*(_DWORD*)(v3 + 276) + 4704), (const char*)(*(_DWORD*)(v3 + 276) + 2112));
		sub_5067B0(a1);
	}
}

//----- (00507000) --------------------------------------------------------
BOOL  sub_507000(int a1) {
	int v1; // edi
	int i;  // esi
	int j;  // eax

	v1 = 0;
	if (*(_BYTE*)(a1 + 4) >= *(_BYTE*)(a1 + 12))
		return 1;
	if (*(_DWORD*)(a1 + 20) == 1) {
		for (i = nox_xxx_getFirstPlayerUnit_4DA7C0(); i; i = nox_xxx_getNextPlayerUnit_4DA7F0(i)) {
			if (nox_xxx_servCompareTeams_419150(*(_DWORD*)(a1 + 16), i + 48))
				++v1;
		}
	} else {
		for (j = nox_xxx_getFirstPlayerUnit_4DA7C0(); j; j = nox_xxx_getNextPlayerUnit_4DA7F0(j))
			++v1;
	}
	return *(unsigned __int8*)(a1 + 4) >= (unsigned int)(v1 - 1) && *(_BYTE*)(a1 + 4) >= 2u;
}

//----- (00507090) --------------------------------------------------------
void  sub_507090(int a1) {
	int i;    // esi
	int v3;   // eax
	char* v4; // eax

	nox_xxx_player_4E3CE0();
	if (*(unsigned __int8*)(a1 + 4) >= nox_xxx_player_4E3CE0()) {
		for (i = nox_xxx_getFirstPlayerUnit_4DA7C0(); i; i = nox_xxx_getNextPlayerUnit_4DA7F0(i)) {
			v3 = *(_DWORD*)(*(_DWORD*)(i + 748) + 276);
			if (*(_DWORD*)(v3 + 4792) == 1)
				nox_xxx_playerRespawn_4F7EF0(*(_DWORD*)(v3 + 2056));
		}
		sub_4E3CD0(0);
		v4 = sub_4D0F60();
		nox_xxx_mapLoad_4D2450(v4);
		sub_5067B0(a1);
	}
}

//----- (00507100) --------------------------------------------------------
void  sub_507100(int a1) {
	int v1;              // edi
	int v2;              // ebx
	unsigned int v3;     // eax
	unsigned int result; // eax

	v1 = *(_DWORD*)(a1 + 28);
	if (!v1) {
		sub_5067B0(a1);
		return;
	}
	if (*(_BYTE*)(v1 + 16) & 0x20) {
		sub_5067B0(a1);
		return;
	}
	v2 = *(_DWORD*)(v1 + 748);
	if (!*(_DWORD*)(*(_DWORD*)(v2 + 276) + 4792)) {
		sub_5067B0(a1);
		return;
	}
	if (*(_BYTE*)(a1 + 4) >= *(_BYTE*)(a1 + 12)) {
	LABEL_8:
		sub_4DCFB0(v1);
		sub_416770(15, (wchar_t*)(*(_DWORD*)(v2 + 276) + 4704), (const char*)(*(_DWORD*)(v2 + 276) + 2112));
		sub_5067B0(a1);
		return;
	}
	v3 = nox_xxx_player_4E3CE0();
	if (v3 <= 1) {
		sub_5067B0(a1);
		return;
	}
	result = v3 - 1;
	if (*(unsigned __int8*)(a1 + 4) >= result && *(_BYTE*)(a1 + 4) >= 2u)
		goto LABEL_8;
}

//----- (00507190) --------------------------------------------------------
int  sub_507190(int a1, char a2) {
	int v2;     // ecx
	char v4[3]; // [esp+0h] [ebp-4h]
	char v5;    // [esp+3h] [ebp-1h]

	v5 = HIBYTE(v2);
	v4[0] = -18;
	v4[1] = 6;
	v4[2] = a2;
	return nox_xxx_netSendPacket1_4E5390(a1, (int)v4, 3, 0, 1);
}

//----- (005071C0) --------------------------------------------------------
BOOL sub_5071C0() { return dword_5d4594_1599656 != 0; }

//----- (00509120) --------------------------------------------------------
void  sub_509120(_DWORD* a1, int a2, const char* a3) {
	char* v3;   // ebx
	int v4;     // ecx
	_DWORD* v5; // esi
	char* v6;   // edx
	_DWORD* v7; // esi
	int v8;     // esi
	_DWORD* v9; // esi

	v3 = (char*)a1[189];
	if (v3) {
		if (a2 == 14) {
			if (nox_common_gameFlags_check_40A5C0(6291456))
				strcpy(v3, a3);
			else
				a1[192] = nox_script_indexByEvent(a3);
			return;
		}
		v4 = a1[2];
		if (v4 & 0x200) {
			v5 = (_DWORD*)a1[187];
			if (a2) {
				if (a2 == 1) {
					if (!nox_common_gameFlags_check_40A5C0(6291456)) {
						v5[6] = nox_script_indexByEvent(a3);
						return;
					}
					v6 = v3 + 256;
				} else {
					if (a2 != 2)
						return;
					if (!nox_common_gameFlags_check_40A5C0(6291456)) {
						v5[8] = nox_script_indexByEvent(a3);
						return;
					}
					v6 = v3 + 384;
				}
			} else {
				if (!nox_common_gameFlags_check_40A5C0(6291456)) {
					v5[4] = nox_script_indexByEvent(a3);
					return;
				}
				v6 = v3 + 512;
			}
		LABEL_66:
			strcpy(v6, a3);
			return;
		}
		if (v4 & 2) {
			v7 = (_DWORD*)a1[187];
			switch (a2) {
			case 3:
				if (nox_common_gameFlags_check_40A5C0(6291456)) {
					v6 = v3 + 640;
					goto LABEL_66;
				}
				v7[309] = nox_script_indexByEvent(a3);
				break;
			case 4:
				if (nox_common_gameFlags_check_40A5C0(6291456)) {
					v6 = v3 + 768;
					goto LABEL_66;
				}
				v7[307] = nox_script_indexByEvent(a3);
				break;
			case 5:
				if (nox_common_gameFlags_check_40A5C0(6291456)) {
					v6 = v3 + 896;
					goto LABEL_66;
				}
				v7[317] = nox_script_indexByEvent(a3);
				break;
			case 6:
				if (nox_common_gameFlags_check_40A5C0(6291456)) {
					v6 = v3 + 1024;
					goto LABEL_66;
				}
				v7[311] = nox_script_indexByEvent(a3);
				break;
			case 7:
				if (nox_common_gameFlags_check_40A5C0(6291456)) {
					v6 = v3 + 1152;
					goto LABEL_66;
				}
				v7[313] = nox_script_indexByEvent(a3);
				break;
			case 8:
				if (nox_common_gameFlags_check_40A5C0(6291456)) {
					v6 = v3 + 1280;
					goto LABEL_66;
				}
				v7[315] = nox_script_indexByEvent(a3);
				break;
			case 9:
				if (nox_common_gameFlags_check_40A5C0(6291456)) {
					v6 = v3 + 1408;
					goto LABEL_66;
				}
				v7[319] = nox_script_indexByEvent(a3);
				break;
			case 10:
				if (nox_common_gameFlags_check_40A5C0(6291456)) {
					v6 = v3 + 1536;
					goto LABEL_66;
				}
				v7[321] = nox_script_indexByEvent(a3);
				break;
			case 11:
				if (nox_common_gameFlags_check_40A5C0(6291456)) {
					v6 = v3 + 1664;
					goto LABEL_66;
				}
				v7[323] = nox_script_indexByEvent(a3);
				break;
			case 13:
				if (nox_common_gameFlags_check_40A5C0(6291456)) {
					v6 = v3 + 1792;
					goto LABEL_66;
				}
				v7[325] = nox_script_indexByEvent(a3);
				break;
			default:
				return;
			}
		} else {
			if (v4 & 0x800) {
				v8 = a1[175];
				if (a2 != 12)
					return;
				if (!nox_common_gameFlags_check_40A5C0(6291456)) {
					*(_DWORD*)(v8 + 4) = nox_script_indexByEvent(a3);
					return;
				}
				v6 = v3 + 128;
				goto LABEL_66;
			}
			if (v4 & 0x20000) {
				v9 = (_DWORD*)a1[187];
				switch (a2) {
				case 15:
					if (nox_common_gameFlags_check_40A5C0(6291456)) {
						v6 = v3 + 1920;
						goto LABEL_66;
					}
					v9[13] = nox_script_indexByEvent(a3);
					break;
				case 16:
					if (nox_common_gameFlags_check_40A5C0(6291456)) {
						v6 = v3 + 2048;
						goto LABEL_66;
					}
					v9[15] = nox_script_indexByEvent(a3);
					break;
				case 17:
					if (nox_common_gameFlags_check_40A5C0(6291456)) {
						v6 = v3 + 2304;
						goto LABEL_66;
					}
					v9[17] = nox_script_indexByEvent(a3);
					break;
				case 18:
					if (nox_common_gameFlags_check_40A5C0(6291456)) {
						v6 = v3 + 2176;
						goto LABEL_66;
					}
					v9[19] = nox_script_indexByEvent(a3);
					break;
				default:
					return;
				}
			}
		}
	}
}

//----- (005095E0) --------------------------------------------------------
int sub_5095E0() {
	int v0;     // ebp
	BOOL v1;    // ebx
	int v2;     // esi
	char* i;    // eax
	int v4;     // ecx
	int v5;     // edi
	int v6;     // ebp
	int v7;     // eax
	int v8;     // eax
	int result; // eax
	char* v10;  // [esp+10h] [ebp-8h]
	int v11;    // [esp+14h] [ebp-4h]

	v0 = 0;
	v11 = 0;
	v10 = 0;
	v1 = 0;
	v2 = 0x7FFFFFFF;
	for (i = nox_xxx_TeamGet_418B10(); i; i = nox_xxx_TeamNext_418B60((int)i)) {
		v4 = *((_DWORD*)i + 13);
		if (v4 <= v2) {
			v1 = v4 == v2 && v0;
			v2 = *((_DWORD*)i + 13);
			v10 = i;
			v0 = (int)i;
		}
	}
	v5 = nox_xxx_getFirstPlayerUnit_4DA7C0();
	if (v5) {
		do {
			v6 = *(_DWORD*)(v5 + 748);
			if (!nox_xxx_servObjectHasTeam_419130(v5 + 48)) {
				v7 = *(_DWORD*)(v6 + 276);
				if (!(*(_BYTE*)(v7 + 3680) & 1)) {
					v8 = *(_DWORD*)(v7 + 2140);
					if (v8 <= v2) {
						v1 = v8 == v2 && v11;
						v2 = v8;
						v11 = v5;
					}
				}
			}
			v5 = nox_xxx_getNextPlayerUnit_4DA7F0(v5);
		} while (v5);
		v0 = (int)v10;
	}
	nox_xxx_setGameFlags_40A4D0(8);
	if (v1)
		return nox_xxx_netSendDMTeamWinner_4D8BF0(0, 1);
	result = v11;
	if (v11)
		return nox_xxx_netSendDMWinner_4D8B90(v11, 1);
	if (v0)
		result = nox_xxx_netSendDMTeamWinner_4D8BF0(v0, 1);
	return result;
}

//----- (005096F0) --------------------------------------------------------
int sub_5096F0() {
	int result;          // eax
	unsigned __int8* v1; // eax
	int v2;              // esi
	int v3;              // eax
	int v4;              // esi
	int v5;              // edi
	char v6[5];          // [esp+0h] [ebp-8h]

	result = sub_40A1A0();
	if (!result)
		return result;
	if (nox_common_gameFlags_check_40A5C0(4096)) {
		v1 = sub_4E8E50();
		nox_xxx_mapLoad_4D2450((char*)v1);
		nox_xxx_netPrintLineToAll_4DA390("chklimit.c:AutoExitToNextMap");
		v2 = nox_xxx_getFirstPlayerUnit_4DA7C0();
		if (v2) {
			do {
				v3 = *(_DWORD*)(v2 + 748);
				if (!*(_DWORD*)(v3 + 312) && *(_DWORD*)(*(_DWORD*)(v3 + 276) + 4792) == 1)
					sub_4D60E0(v2);
				v2 = nox_xxx_getNextPlayerUnit_4DA7F0(v2);
			} while (v2);
			return sub_40A1F0(0);
		}
		return sub_40A1F0(0);
	}
	if (!sub_40A300()) {
		if (nox_common_gameFlags_check_40A5C0(96)) {
			sub_5099B0();
			return sub_40A1F0(0);
		}
		if (nox_common_gameFlags_check_40A5C0(272)) {
			sub_5098A0();
			return sub_40A1F0(0);
		}
		if (nox_common_gameFlags_check_40A5C0(1024))
			sub_5095E0();
		return sub_40A1F0(0);
	}
	nox_xxx_setGameFlags_40A4D0(0x4000000);
	v6[0] = -102;
	v4 = nox_xxx_getFirstPlayerUnit_4DA7C0();
	if (!v4)
		return sub_40A1F0(0);
	do {
		v5 = *(_DWORD*)(v4 + 748);
		if (v5) {
			*(_WORD*)&v6[1] = (__int64)*(float*)(*(_DWORD*)(v5 + 276) + 3632);
			*(_WORD*)&v6[3] = (__int64)*(float*)(*(_DWORD*)(v5 + 276) + 3636);
			nox_xxx_netAddToMsgListCli_40EBC0(*(unsigned __int8*)(*(_DWORD*)(v5 + 276) + 2064), 1, v6, 5);
		}
		nox_xxx_aud_501960(582, v4, 2, *(_DWORD*)(v4 + 36));
		v4 = nox_xxx_getNextPlayerUnit_4DA7F0(v4);
	} while (v4);
	return sub_40A1F0(0);
}
