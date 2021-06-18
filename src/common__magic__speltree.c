#include "common__magic__speltree.h"

#include "proto.h"
void* dword_587000_66120 = 0;
extern _DWORD nox_xxx_polygonNextIdx_587000_60352;

//----- (00424850) --------------------------------------------------------
BOOL  nox_xxx_isArgB8EqSome_424850(void* a1) { return a1 == *(void**)&dword_587000_66120; }

//----- (00424820) --------------------------------------------------------
void* nox_xxx_spellGetDefArrayPtr_424820() { return *(void**)&dword_587000_66120; }

//----- (00424870) --------------------------------------------------------
char*  nox_xxx_spellNameByN_424870(int a1) { return *(char**)getMemAt(0x587000, 65448 + 4*a1); }

//----- (004243F0) --------------------------------------------------------
int  nox_xxx_spellNameToN_4243F0(const char* a1) {
	const char* v1;      // ecx
	int v2;              // ebp
	unsigned __int8* v3; // edi

	v1 = *(const char**)getMemAt(0x587000, 65448);
	v2 = 0;
	if (!*getMemU32Ptr(0x587000, 65448))
		return 0;
	v3 = getMemAt(0x587000, 65448);
	while (strcmp(v1, a1)) {
		v1 = (const char*)*((_DWORD*)v3 + 1);
		v3 += 4;
		++v2;
		if (!v1)
			return 0;
	}
	return v2;
}

//----- (00424460) --------------------------------------------------------
int  nox_xxx_spellLoadSpells_424460(nox_memfile* f, void* a2) {
	int v3;               // ebx
	int v4;               // eax
	int result;           // eax
	unsigned __int8 v9;   // dl
	int* v10;             // edi
	unsigned __int8 v12;  // cl
	int** v13;            // edi
	int* v14;             // eax
	int v16;              // edi
	char v18;             // cl
	int v20;              // edi
	char v22;             // cl
	int v24;              // ecx
	int v27;              // edi
	unsigned __int8 v29;  // cl
	int v30;              // edi
	unsigned __int8 v33;  // [esp+10h] [ebp-138h]
	unsigned __int8 v34;  // [esp+10h] [ebp-138h]
	unsigned __int8 v35;  // [esp+10h] [ebp-138h]
	unsigned __int8 v36;  // [esp+10h] [ebp-138h]
	unsigned __int8 v37;  // [esp+10h] [ebp-138h]
	unsigned __int8 v38;  // [esp+10h] [ebp-138h]
	const char* v39;      // [esp+14h] [ebp-134h]
	unsigned __int8 v40;  // [esp+1Ch] [ebp-12Ch]
	int v41;              // [esp+20h] [ebp-128h]
	int v42;              // [esp+24h] [ebp-124h]
	char v43[256];        // [esp+28h] [ebp-120h]
	char v44[32];         // [esp+128h] [ebp-20h]

	v33 = nox_memfile_read_u8(f);
	nox_memfile_read(a2, 1, v33, f);
	v3 = 0;
	*((_BYTE*)a2 + v33) = 0;
	v4 = nox_xxx_spellNameToN_4243F0((const char*)a2);
	v41 = v4;
	if (!v4)
		return 0;
	nox_spell_t* sp = (nox_spell_t*)getMemAt(0x5D4594, 588124 + sizeof(nox_spell_t) * v4);
	v40 = 0;
	v39 = 0;
	sp->mana_cost = nox_memfile_read_u8(f);
	sp->price = nox_memfile_read_u16(f);
	v9 = nox_memfile_read_u8(f);
	sp->phonemes_cnt = v9;
	v10 = *(int**)&dword_587000_66120;
	v42 = v9;
	if ((int)v9 > 0) {
		do {
			v12 = nox_memfile_read_u8(f);
			if (v12 >= 9)
				return 0;
			v44[v40++] = v12;
			v13 = (int**)&v10[v12 + 1];
			if (*v13) {
				v10 = *v13;
			} else {
				v14 = (int*)calloc(1u, 0x28u);
				*v13 = v14;
				if (!v14)
					return 0;
				*v14 = 0;
				v10 = *v13;
				v4 = v41;
			}
		} while ((int)++v39 < v42);
	}
	*v10 = v4;
	v16 = nox_memfile_read_i32(f);
	sp->icon = 0;
	v43[0] = getMemByte(0x5D4594, 599124);
	if (v16 == -1) {
		v18 = nox_memfile_read_i8(f);
		LOBYTE(v39) = v18;
		v34 = nox_memfile_read_i8(f);
		nox_memfile_read(v43, 1, v34, f);
		v43[v34] = 0;
		v16 = -1;
	}
	if (nox_common_gameFlags_check_40A5C0(2))
		sp->icon = nox_xxx_readImgMB_42FAA0(v16, v39, v43);
	v20 = nox_memfile_read_i32(f);
	sp->icon_spent = 0;
	v43[0] = getMemByte(0x5D4594, 599128);
	if (v20 == -1) {
		v22 = nox_memfile_read_i8(f);
		LOBYTE(v39) = v22;
		v35 = nox_memfile_read_i8(f);
		nox_memfile_read(v43, 1, v35, f);
		v43[v35] = 0;
		v20 = -1;
	}
	if (nox_common_gameFlags_check_40A5C0(2))
		sp->icon_spent = nox_xxx_readImgMB_42FAA0(v20, v39, v43);
	v24 = nox_memfile_read_i32(f);
	sp->flags = v24;
	v36 = nox_memfile_read_u8(f);
	nox_memfile_read(v43, 1, v36, f);
	v43[v36] = 0;
	sp->title = nox_strman_loadString_40F1D0(v43, 0, "C:\\NoxPost\\src\\Common\\Magic\\Speltree.c", 481);
	v27 = nox_memfile_read_i16(f);
	nox_memfile_read(v43, 1, v27, f);
	v43[v27] = 0;
	sp->desc = nox_strman_loadString_40F1D0(v43, 0, "C:\\NoxPost\\src\\Common\\Magic\\Speltree.c", 488);
	v29 = nox_memfile_read_u8(f);
	v30 = v29;
	nox_memfile_read(v43, 1, v29, f);
	v43[v30] = 0;
	sp->cast_sound = nox_xxx_utilFindSound_40AF50(v43);
	v37 = nox_memfile_read_u8(f);
	nox_memfile_read(v43, 1, v37, f);
	v43[v37] = 0;
	sp->on_sound = nox_xxx_utilFindSound_40AF50(v43);
	v38 = nox_memfile_read_u8(f);
	nox_memfile_read(v43, 1, v38, f);
	v43[v38] = 0;
	sp->off_sound = nox_xxx_utilFindSound_40AF50(v43);
	if ((int)v40 > 0) {
		memcpy(sp->data_7, v44, v40);
		v3 = v40;
	}
	result = 1;
	sp->data_7[v3] = 4;
	sp->enabled = 1;
	sp->valid = 1;
	return result;
}

//----- (00421430) --------------------------------------------------------
LPVOID sub_421430() {
	unsigned __int8* v0; // esi
	LPVOID result;       // eax

	v0 = getMemAt(0x5D4594, 552476);
	do {
		if (*((_DWORD*)v0 - 27)) {
			if (*getMemU32Ptr(0x5D4594, 588076))
				free(*((LPVOID*)v0 - 27));
			*((_DWORD*)v0 - 27) = 0;
		}
		result = *(LPVOID*)v0;
		if (*(_DWORD*)v0) {
			if (*getMemU32Ptr(0x5D4594, 588076))
				free(*(LPVOID*)v0);
			*(_DWORD*)v0 = 0;
		}
		*((_WORD*)v0 + 10) = 0;
		*((_DWORD*)v0 - 7) = 0;
		*((_DWORD*)v0 + 2) = -1;
		*((_DWORD*)v0 + 4) = -1;
		*((_DWORD*)v0 - 6) = 0;
		v0 += 140;
	} while ((int)v0 < (int)getMemAt(0x5D4594, 588124 + 52));
	nox_xxx_polygonNextIdx_587000_60352 = 1;
	return result;
}

//----- (00424800) --------------------------------------------------------
int nox_xxx_spellGetAud44_424800(int a1, int a2) {
	if (a2 < 0 || a2 >= 3)
		return 0;
	return *getMemU32Ptr(0x5D4594, 588124 + sizeof(nox_spell_t)*a1 + 68 + 4*a2);
}

//----- (00424930) --------------------------------------------------------
int  nox_xxx_spellLoadName_424930(int a1) {
	int result; // eax

	if (a1 > 0 && a1 < 137 && *getMemU32Ptr(0x5D4594, 588124 + sizeof(nox_spell_t)*a1 + 24))
		result = *getMemU32Ptr(0x5D4594, 588124 + sizeof(nox_spell_t)*a1);
	else
		result = 0;
	return result;
}

//----- (00424960) --------------------------------------------------------
int  sub_424960(wchar_t* a1) {
	int v1;              // edi
	unsigned __int8* v2; // esi

	v1 = 1;
	v2 = getMemAt(0x5D4594, 588124 + sizeof(nox_spell_t)*1);
	while (!*((_DWORD*)v2 + 6) || nox_wcscmp(*(const wchar_t**)v2, a1)) {
		v2 += 80;
		++v1;
		if ((int)v2 >= (int)getMemAt(0x5D4594, 599084))
			return 0;
	}
	return v1;
}

//----- (004249A0) --------------------------------------------------------
int  nox_xxx_getManaCost_4249A0(int a1, int a2) {
	int result; // eax
	float v3;   // [esp+0h] [ebp-4h]
	float v4;   // [esp+0h] [ebp-4h]
	float v5;   // [esp+0h] [ebp-4h]

	if (a2 != 2)
		return getMemByte(0x5D4594, 588124 + sizeof(nox_spell_t)*a1 + 62);
	switch (a1) {
	case 24:
		v5 = nox_xxx_gamedataGetFloat_419D40("EnergyBoltTrapCost");
		result = nox_float2int(v5);
		break;
	case 43:
		v4 = nox_xxx_gamedataGetFloat_419D40("LightningTrapCost");
		result = nox_float2int(v4);
		break;
	case 56:
		v3 = nox_xxx_gamedataGetFloat_419D40("ManaBombTrapCost");
		result = nox_float2int(v3);
		break;
	default:
		result = getMemByte(0x5D4594, 588124 + sizeof(nox_spell_t)*a1 + 62);
		break;
	}
	return result;
}

//----- (00424A20) --------------------------------------------------------
char*  nox_xxx_spellGetPhonemeMB_424A20(int a1) { return (char*)getMemAt(0x5D4594, 588124 + sizeof(nox_spell_t)*a1 + 28); }

//----- (00424A30) --------------------------------------------------------
int  nox_xxx_spellGet_424A30(int a1) { return *getMemU32Ptr(0x5D4594, 588124 + sizeof(nox_spell_t)*a1 + 4); }

//----- (00424A50) --------------------------------------------------------
BOOL  nox_xxx_spellDefHasFlags_424A50(int a1, int a2) { return (a2 & *getMemU32Ptr(0x5D4594, 588124 + sizeof(nox_spell_t)*a1 + 16)) != 0; }

//----- (00424A70) --------------------------------------------------------
int  nox_xxx_spellGetFlags_424A70(int a1) { return *getMemU32Ptr(0x5D4594, 588124 + sizeof(nox_spell_t)*a1 + 16); }

//----- (00424A90) --------------------------------------------------------
int  nox_xxx_spellGetIcon_424A90(int a1) { return *getMemU32Ptr(0x5D4594, 588124 + sizeof(nox_spell_t)*a1 + 8); }

//----- (00424AB0) --------------------------------------------------------
int  nox_xxx_spellGetIconHighlight_424AB0(int a1) { return *getMemU32Ptr(0x5D4594, 588124 + sizeof(nox_spell_t)*a1 + 12); }

//----- (00424AD0) --------------------------------------------------------
int nox_xxx_bookFirstKnownSpell_424AD0() {
	int result;          // eax
	unsigned __int8* v1; // ecx

	result = 1;
	v1 = getMemAt(0x5D4594, 588124 + sizeof(nox_spell_t)*1 + 24);
	while (!*(_DWORD*)v1) {
		v1 += 80;
		++result;
		if ((int)v1 >= (int)getMemAt(0x5D4594, 599108))
			return 0;
	}
	return result;
}

//----- (00424AF0) --------------------------------------------------------
int  nox_xxx_bookNextEnabledSpell_424AF0(int a1) {
	int result;          // eax
	unsigned __int8* v2; // ecx

	result = a1 + 1;
	if (a1 + 1 >= 137)
		return 0;
	v2 = getMemAt(0x5D4594, 588124 + sizeof(nox_spell_t)*result + 24);
	while (!*(_DWORD*)v2) {
		v2 += 80;
		++result;
		if ((int)v2 >= (int)getMemAt(0x5D4594, 599108))
			return 0;
	}
	return result;
}

//----- (00424B20) --------------------------------------------------------
int  sub_424B20(int a1) {
	int result;         // eax
	unsigned __int8* i; // ecx

	if (!a1)
		return 0;
	result = a1 - 1;
	if (a1 - 1 <= 0)
		return 0;
	for (i = getMemAt(0x5D4594, 588124 + sizeof(nox_spell_t)*result + 24); !*(_DWORD*)i; i -= sizeof(nox_spell_t)) {
		if (--result <= 0)
			return 0;
	}
	return result;
}

//----- (00424B50) --------------------------------------------------------
int  nox_xxx_spellGetValidMB_424B50(int a1) { return *getMemU32Ptr(0x5D4594, 588124 + sizeof(nox_spell_t)*a1 + 24); }

//----- (00424B70) --------------------------------------------------------
int  nox_xxx_spellIsEnabled_424B70(int a1) { return *getMemU32Ptr(0x5D4594, 588124 + sizeof(nox_spell_t)*a1 + 20); }

//----- (00424B90) --------------------------------------------------------
int  nox_xxx_spellEnable_424B90(int a1) {
	int result; // eax

	result = 80 * a1;
	*getMemU32Ptr(0x5D4594, 588124 + sizeof(nox_spell_t)*a1 + 20) = 1;
	return result;
}

//----- (00424BB0) --------------------------------------------------------
int  nox_xxx_spellDisable_424BB0(int a1) {
	int result; // eax

	result = 80 * a1;
	*getMemU32Ptr(0x5D4594, 588124 + sizeof(nox_spell_t)*a1 + 20) = 0;
	return result;
}

//----- (00424BF0) --------------------------------------------------------
unsigned int  nox_xxx_spellMayTrap_424BF0(int a1) {
	unsigned int result; // eax

	if (a1 <= 0 || a1 >= 137 || nox_common_gameFlags_check_40A5C0(4096) && a1 == 4)
		result = 0;
	else
		result = ((unsigned int)~*getMemU32Ptr(0x5D4594, 588124 + sizeof(nox_spell_t)*a1 + 16) >> 22) & 1;
	return result;
}

//----- (00424C40) --------------------------------------------------------
__int16  nox_xxx_spellGetWorth_424C40(int a1) {
	float v2; // [esp+4h] [ebp+4h]

	if (a1 <= 0 || a1 >= 137)
		return 0;
	v2 = (double)*getMemU16Ptr(0x5D4594, 588124 + sizeof(nox_spell_t)*a1 + 64);
	if (nox_common_gameFlags_check_40A5C0(4096))
		v2 = nox_xxx_gamedataGetFloat_419D40("QuestSpellWorthMultiplier") * v2;
	return nox_float2int(v2);
}
