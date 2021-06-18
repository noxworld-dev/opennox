#include "common__magic__speltree.h"

#include "proto.h"
void* dword_587000_66120 = 0;
extern _DWORD nox_xxx_polygonNextIdx_587000_60352;

const char* nox_spell_ids[] = {
    "SPELL_INVALID",						// 0
    "SPELL_ANCHOR",							// 1
    "SPELL_ARACHNAPHOBIA",					// 2
    "SPELL_BLIND",							// 3
    "SPELL_BLINK",							// 4
    "SPELL_BURN",							// 5
    "SPELL_CANCEL",							// 6
    "SPELL_CHAIN_LIGHTNING_BOLT",			// 7
    "SPELL_CHANNEL_LIFE",					// 8
    "SPELL_CHARM",							// 9
    "SPELL_CLEANSING_FLAME",				// 10
    "SPELL_CLEANSING_MANA_FLAME",			// 11
    "SPELL_CONFUSE",						// 12
    "SPELL_COUNTERSPELL",					// 13
    "SPELL_CURE_POISON",					// 14
    "SPELL_DEATH",							// 15
    "SPELL_DEATH_RAY",						// 16
    "SPELL_DETECT_MAGIC",					// 17
    "SPELL_DETONATE",						// 18
    "SPELL_DETONATE_GLYPHS",				// 19
    "SPELL_DISENCHANT_ALL",					// 20
    "SPELL_TURN_UNDEAD",					// 21
    "SPELL_DRAIN_MANA",						// 22
    "SPELL_EARTHQUAKE",						// 23
    "SPELL_LIGHTNING",						// 24
    "SPELL_EXPLOSION",						// 25
    "SPELL_FEAR",							// 26
    "SPELL_FIREBALL",						// 27
    "SPELL_FIREWALK",						// 28
    "SPELL_FIST",							// 29
    "SPELL_FORCE_FIELD",					// 30
    "SPELL_FORCE_OF_NATURE",				// 31
    "SPELL_FREEZE",							// 32
    "SPELL_FUMBLE",							// 33
    "SPELL_GLYPH",							// 34
    "SPELL_GREATER_HEAL",					// 35
    "SPELL_HASTE",							// 36
    "SPELL_INFRAVISION",					// 37
    "SPELL_INVERSION",						// 38
    "SPELL_INVISIBILITY",					// 39
    "SPELL_INVULNERABILITY",				// 40
    "SPELL_LESSER_HEAL",					// 41
    "SPELL_LIGHT",							// 42
    "SPELL_CHAIN_LIGHTNING",				// 43
    "SPELL_LOCK",							// 44
    "SPELL_MARK",							// 45
    "SPELL_MARK_1",							// 46
    "SPELL_MARK_2",							// 47
    "SPELL_MARK_3",							// 48
    "SPELL_MARK_4",							// 49
    "SPELL_MAGIC_MISSILE",					// 50
    "SPELL_SHIELD",							// 51
    "SPELL_METEOR",							// 52
    "SPELL_METEOR_SHOWER",					// 53
    "SPELL_MOONGLOW",						// 54
    "SPELL_NULLIFY",						// 55
    "SPELL_MANA_BOMB",						// 56
    "SPELL_PHANTOM",						// 57
    "SPELL_PIXIE_SWARM",					// 58
    "SPELL_PLASMA",							// 59
    "SPELL_POISON",							// 60
    "SPELL_PROTECTION_FROM_ELECTRICITY",	// 61
    "SPELL_PROTECTION_FROM_FIRE",			// 62
    "SPELL_PROTECTION_FROM_MAGIC",			// 63
    "SPELL_PROTECTION_FROM_POISON",			// 64
    "SPELL_PULL",							// 65
    "SPELL_PUSH",							// 67
    "SPELL_OVAL_SHIELD",					// 68
    "SPELL_RESTORE_HEALTH",					// 69
    "SPELL_RESTORE_MANA",					// 70
    "SPELL_RUN",							// 71
    "SPELL_SHOCK",							// 72
    "SPELL_SLOW",							// 73
    "SPELL_SMALL_ZAP",						// 74
    "SPELL_STUN",							// 75
    "SPELL_SUMMON_BAT",						// 76
    "SPELL_SUMMON_BLACK_BEAR",				// 77
    "SPELL_SUMMON_BEAR",					// 78
    "SPELL_SUMMON_BEHOLDER",				// 79
    "SPELL_SUMMON_BOMBER",					// 80
    "SPELL_SUMMON_CARNIVOROUS_PLANT",		// 81
    "SPELL_SUMMON_ALBINO_SPIDER",			// 82
    "SPELL_SUMMON_SMALL_ALBINO_SPIDER",		// 83
    "SPELL_SUMMON_EVIL_CHERUB",				// 84
    "SPELL_SUMMON_EMBER_DEMON",				// 85
    "SPELL_SUMMON_GHOST",					// 86
    "SPELL_SUMMON_GIANT_LEECH",				// 87
    "SPELL_SUMMON_IMP",						// 88
    "SPELL_SUMMON_MECHANICAL_FLYER",		// 89
    "SPELL_SUMMON_MECHANICAL_GOLEM",		// 90
    "SPELL_SUMMON_MIMIC",					// 91
    "SPELL_SUMMON_OGRE",					// 92
    "SPELL_SUMMON_OGRE_BRUTE",				// 93
    "SPELL_SUMMON_OGRE_WARLORD",			// 94
    "SPELL_SUMMON_SCORPION",				// 95
    "SPELL_SUMMON_SHADE",					// 96
    "SPELL_SUMMON_SKELETON",				// 97
    "SPELL_SUMMON_SKELETON_LORD",			// 98
    "SPELL_SUMMON_SPIDER",					// 99
    "SPELL_SUMMON_SMALL_SPIDER",			// 100
    "SPELL_SUMMON_SPITTING_SPIDER",			// 101
    "SPELL_SUMMON_STONE_GOLEM",				// 102
    "SPELL_SUMMON_TROLL",					// 103
    "SPELL_SUMMON_URCHIN",					// 104
    "SPELL_SUMMON_WASP",					// 105
    "SPELL_SUMMON_WILLOWISP",				// 106
    "SPELL_SUMMON_WOLF",					// 107
    "SPELL_SUMMON_BLACK_WOLF",				// 108
    "SPELL_SUMMON_WHITE_WOLF",				// 109
    "SPELL_SUMMON_ZOMBIE",					// 110
    "SPELL_SUMMON_VILE_ZOMBIE",				// 111
    "SPELL_SUMMON_DEMON",					// 112
    "SPELL_SUMMON_LICH",					// 113
    "SPELL_SUMMON_DRYAD",					// 114
    "SPELL_SUMMON_URCHIN_SHAMAN",			// 115
    "SPELL_SWAP",							// 116
    "SPELL_TAG",							// 117
    "SPELL_TELEPORT_OTHER_TO_MARK_1",		// 118
    "SPELL_TELEPORT_OTHER_TO_MARK_2",		// 119
    "SPELL_TELEPORT_OTHER_TO_MARK_3",		// 120
    "SPELL_TELEPORT_OTHER_TO_MARK_4",		// 121
    "SPELL_TELEPORT_POP",					// 122
    "SPELL_TELEPORT_TO_MARK_1",				// 123
    "SPELL_TELEPORT_TO_MARK_2",				// 124
    "SPELL_TELEPORT_TO_MARK_3",				// 125
    "SPELL_TELEPORT_TO_MARK_4",				// 126
    "SPELL_TELEPORT_TO_TARGET",				// 127
    "SPELL_TELEKINESIS",					// 128
    "SPELL_TOXIC_CLOUD",					// 129
    "SPELL_TRIGGER_GLYPH",					// 130
    "SPELL_VAMPIRISM",						// 131
    "SPELL_VILLAIN",						// 132
    "SPELL_WALL",							// 133
    "SPELL_WINK",							// 134
    "SPELL_SUMMON_CREATURE",				// 135
    "SPELL_MARK_LOCATION",					// 136
    "SPELL_TELEPORT_TO_MARKER",				// 137
    0,
};
int nox_spell_ids_cnt = (sizeof(nox_spell_ids) / sizeof(char*)) - 1;

//----- (00424850) --------------------------------------------------------
BOOL  nox_xxx_isArgB8EqSome_424850(void* a1) { return a1 == *(void**)&dword_587000_66120; }

//----- (00424820) --------------------------------------------------------
void* nox_xxx_spellGetDefArrayPtr_424820() { return *(void**)&dword_587000_66120; }

//----- (00424870) --------------------------------------------------------
char* nox_xxx_spellNameByN_424870(int ind) {
	if (ind < 0 || ind >= nox_spell_ids_cnt)
		return 0;
	return nox_spell_ids[ind];
}

//----- (004243F0) --------------------------------------------------------
int  nox_xxx_spellNameToN_4243F0(const char* id) {
	for (int i = 0; i < nox_spell_ids_cnt && nox_spell_ids[i]; i++) {
		if (strcmp(nox_spell_ids[i], id) == 0)
			return i;
	}
	return 0;
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
	sp->icon_enabled = 0;
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
		sp->icon_enabled = nox_xxx_readImgMB_42FAA0(v20, v39, v43);
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
