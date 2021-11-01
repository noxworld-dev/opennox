#include "common__magic__speltree.h"

#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME1_2.h"
#include "client__gui__window.h"
#include "common__strman.h"
#include "operators.h"

void* dword_587000_66120 = 0;
extern uint32_t nox_xxx_polygonNextIdx_587000_60352;

const char* nox_spell_ids[NOX_SPELLS_MAX + 1] = {
	"SPELL_INVALID",                     // 0
	"SPELL_ANCHOR",                      // 1
	"SPELL_ARACHNAPHOBIA",               // 2
	"SPELL_BLIND",                       // 3
	"SPELL_BLINK",                       // 4
	"SPELL_BURN",                        // 5
	"SPELL_CANCEL",                      // 6
	"SPELL_CHAIN_LIGHTNING_BOLT",        // 7
	"SPELL_CHANNEL_LIFE",                // 8
	"SPELL_CHARM",                       // 9
	"SPELL_CLEANSING_FLAME",             // 10
	"SPELL_CLEANSING_MANA_FLAME",        // 11
	"SPELL_CONFUSE",                     // 12
	"SPELL_COUNTERSPELL",                // 13
	"SPELL_CURE_POISON",                 // 14
	"SPELL_DEATH",                       // 15
	"SPELL_DEATH_RAY",                   // 16
	"SPELL_DETECT_MAGIC",                // 17
	"SPELL_DETONATE",                    // 18
	"SPELL_DETONATE_GLYPHS",             // 19
	"SPELL_DISENCHANT_ALL",              // 20
	"SPELL_TURN_UNDEAD",                 // 21
	"SPELL_DRAIN_MANA",                  // 22
	"SPELL_EARTHQUAKE",                  // 23
	"SPELL_LIGHTNING",                   // 24
	"SPELL_EXPLOSION",                   // 25
	"SPELL_FEAR",                        // 26
	"SPELL_FIREBALL",                    // 27
	"SPELL_FIREWALK",                    // 28
	"SPELL_FIST",                        // 29
	"SPELL_FORCE_FIELD",                 // 30
	"SPELL_FORCE_OF_NATURE",             // 31
	"SPELL_FREEZE",                      // 32
	"SPELL_FUMBLE",                      // 33
	"SPELL_GLYPH",                       // 34
	"SPELL_GREATER_HEAL",                // 35
	"SPELL_HASTE",                       // 36
	"SPELL_INFRAVISION",                 // 37
	"SPELL_INVERSION",                   // 38
	"SPELL_INVISIBILITY",                // 39
	"SPELL_INVULNERABILITY",             // 40
	"SPELL_LESSER_HEAL",                 // 41
	"SPELL_LIGHT",                       // 42
	"SPELL_CHAIN_LIGHTNING",             // 43
	"SPELL_LOCK",                        // 44
	"SPELL_MARK",                        // 45
	"SPELL_MARK_1",                      // 46
	"SPELL_MARK_2",                      // 47
	"SPELL_MARK_3",                      // 48
	"SPELL_MARK_4",                      // 49
	"SPELL_MAGIC_MISSILE",               // 50
	"SPELL_SHIELD",                      // 51
	"SPELL_METEOR",                      // 52
	"SPELL_METEOR_SHOWER",               // 53
	"SPELL_MOONGLOW",                    // 54
	"SPELL_NULLIFY",                     // 55
	"SPELL_MANA_BOMB",                   // 56
	"SPELL_PHANTOM",                     // 57
	"SPELL_PIXIE_SWARM",                 // 58
	"SPELL_PLASMA",                      // 59
	"SPELL_POISON",                      // 60
	"SPELL_PROTECTION_FROM_ELECTRICITY", // 61
	"SPELL_PROTECTION_FROM_FIRE",        // 62
	"SPELL_PROTECTION_FROM_MAGIC",       // 63
	"SPELL_PROTECTION_FROM_POISON",      // 64
	"SPELL_PULL",                        // 65
	"SPELL_PUSH",                        // 67
	"SPELL_OVAL_SHIELD",                 // 68
	"SPELL_RESTORE_HEALTH",              // 69
	"SPELL_RESTORE_MANA",                // 70
	"SPELL_RUN",                         // 71
	"SPELL_SHOCK",                       // 72
	"SPELL_SLOW",                        // 73
	"SPELL_SMALL_ZAP",                   // 74
	"SPELL_STUN",                        // 75
	"SPELL_SUMMON_BAT",                  // 76
	"SPELL_SUMMON_BLACK_BEAR",           // 77
	"SPELL_SUMMON_BEAR",                 // 78
	"SPELL_SUMMON_BEHOLDER",             // 79
	"SPELL_SUMMON_BOMBER",               // 80
	"SPELL_SUMMON_CARNIVOROUS_PLANT",    // 81
	"SPELL_SUMMON_ALBINO_SPIDER",        // 82
	"SPELL_SUMMON_SMALL_ALBINO_SPIDER",  // 83
	"SPELL_SUMMON_EVIL_CHERUB",          // 84
	"SPELL_SUMMON_EMBER_DEMON",          // 85
	"SPELL_SUMMON_GHOST",                // 86
	"SPELL_SUMMON_GIANT_LEECH",          // 87
	"SPELL_SUMMON_IMP",                  // 88
	"SPELL_SUMMON_MECHANICAL_FLYER",     // 89
	"SPELL_SUMMON_MECHANICAL_GOLEM",     // 90
	"SPELL_SUMMON_MIMIC",                // 91
	"SPELL_SUMMON_OGRE",                 // 92
	"SPELL_SUMMON_OGRE_BRUTE",           // 93
	"SPELL_SUMMON_OGRE_WARLORD",         // 94
	"SPELL_SUMMON_SCORPION",             // 95
	"SPELL_SUMMON_SHADE",                // 96
	"SPELL_SUMMON_SKELETON",             // 97
	"SPELL_SUMMON_SKELETON_LORD",        // 98
	"SPELL_SUMMON_SPIDER",               // 99
	"SPELL_SUMMON_SMALL_SPIDER",         // 100
	"SPELL_SUMMON_SPITTING_SPIDER",      // 101
	"SPELL_SUMMON_STONE_GOLEM",          // 102
	"SPELL_SUMMON_TROLL",                // 103
	"SPELL_SUMMON_URCHIN",               // 104
	"SPELL_SUMMON_WASP",                 // 105
	"SPELL_SUMMON_WILLOWISP",            // 106
	"SPELL_SUMMON_WOLF",                 // 107
	"SPELL_SUMMON_BLACK_WOLF",           // 108
	"SPELL_SUMMON_WHITE_WOLF",           // 109
	"SPELL_SUMMON_ZOMBIE",               // 110
	"SPELL_SUMMON_VILE_ZOMBIE",          // 111
	"SPELL_SUMMON_DEMON",                // 112
	"SPELL_SUMMON_LICH",                 // 113
	"SPELL_SUMMON_DRYAD",                // 114
	"SPELL_SUMMON_URCHIN_SHAMAN",        // 115
	"SPELL_SWAP",                        // 116
	"SPELL_TAG",                         // 117
	"SPELL_TELEPORT_OTHER_TO_MARK_1",    // 118
	"SPELL_TELEPORT_OTHER_TO_MARK_2",    // 119
	"SPELL_TELEPORT_OTHER_TO_MARK_3",    // 120
	"SPELL_TELEPORT_OTHER_TO_MARK_4",    // 121
	"SPELL_TELEPORT_POP",                // 122
	"SPELL_TELEPORT_TO_MARK_1",          // 123
	"SPELL_TELEPORT_TO_MARK_2",          // 124
	"SPELL_TELEPORT_TO_MARK_3",          // 125
	"SPELL_TELEPORT_TO_MARK_4",          // 126
	"SPELL_TELEPORT_TO_TARGET",          // 127
	"SPELL_TELEKINESIS",                 // 128
	"SPELL_TOXIC_CLOUD",                 // 129
	"SPELL_TRIGGER_GLYPH",               // 130
	"SPELL_VAMPIRISM",                   // 131
	"SPELL_VILLAIN",                     // 132
	"SPELL_WALL",                        // 133
	"SPELL_WINK",                        // 134
	"SPELL_SUMMON_CREATURE",             // 135
	"SPELL_MARK_LOCATION",               // 136
	"SPELL_TELEPORT_TO_MARKER",          // 137
	0,
};

nox_spell_t nox_spells_arr_588124[NOX_SPELLS_MAX + 1] = {0};

//----- (00424850) --------------------------------------------------------
int nox_xxx_isArgB8EqSome_424850(void* a1) { return a1 == *(void**)&dword_587000_66120; }

//----- (00424820) --------------------------------------------------------
void* nox_xxx_spellGetDefArrayPtr_424820() { return *(void**)&dword_587000_66120; }

//----- (00424870) --------------------------------------------------------
char* nox_xxx_spellNameByN_424870(int ind) {
	if (ind < 0 || ind >= NOX_SPELLS_MAX) {
		return 0;
	}
	return nox_spell_ids[ind];
}

//----- (004243F0) --------------------------------------------------------
int nox_xxx_spellNameToN_4243F0(const char* id) {
	for (int i = 0; i < NOX_SPELLS_MAX && nox_spell_ids[i]; i++) {
		if (strcmp(nox_spell_ids[i], id) == 0) {
			return i;
		}
	}
	return 0;
}

//----- (00424460) --------------------------------------------------------
int nox_xxx_spellLoadSpells_424460(nox_memfile* f, void* a2) {
	int v3;            // ebx
	int v4;            // eax
	unsigned char v9;  // dl
	int* v10;          // edi
	unsigned char v12; // cl
	int** v13;         // edi
	int* v14;          // eax
	int v16;           // edi
	char v18;          // cl
	int v20;           // edi
	char v22;          // cl
	int v24;           // ecx
	int v27;           // edi
	unsigned char v29; // cl
	int v30;           // edi
	unsigned char v33; // [esp+10h] [ebp-138h]
	unsigned char v34; // [esp+10h] [ebp-138h]
	unsigned char v35; // [esp+10h] [ebp-138h]
	unsigned char v36; // [esp+10h] [ebp-138h]
	unsigned char v37; // [esp+10h] [ebp-138h]
	unsigned char v38; // [esp+10h] [ebp-138h]
	const char* v39;   // [esp+14h] [ebp-134h]
	unsigned char v40; // [esp+1Ch] [ebp-12Ch]
	int v41;           // [esp+20h] [ebp-128h]
	int v42;           // [esp+24h] [ebp-124h]
	char v43[256];     // [esp+28h] [ebp-120h]
	char v44[32];      // [esp+128h] [ebp-20h]

	v33 = nox_memfile_read_u8(f);
	nox_memfile_read(a2, 1, v33, f);
	v3 = 0;
	*((uint8_t*)a2 + v33) = 0;
	v4 = nox_xxx_spellNameToN_4243F0((const char*)a2);
	v41 = v4;
	if (!v4) {
		return 0;
	}
	nox_spell_t* sp = &nox_spells_arr_588124[v4];
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
			if (v12 >= 9) {
				return 0;
			}
			v44[v40++] = v12;
			v13 = (int**)&v10[v12 + 1];
			if (*v13) {
				v10 = *v13;
			} else {
				v14 = (int*)calloc(1u, 0x28u);
				*v13 = v14;
				if (!v14) {
					return 0;
				}
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
	if (nox_common_gameFlags_check_40A5C0(2)) {
		sp->icon = nox_xxx_readImgMB_42FAA0(v16, v39, v43);
	}
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
	if (nox_common_gameFlags_check_40A5C0(2)) {
		sp->icon_enabled = nox_xxx_readImgMB_42FAA0(v20, v39, v43);
	}
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
		memcpy(sp->phonemes, v44, v40);
		v3 = v40;
	}
	sp->phonemes[v3] = 4;
	sp->enabled = 1;
	sp->valid = 1;
	return 1;
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

//----- (00424800) --------------------------------------------------------
void* nox_xxx_spellGetAud44_424800(int ind, int a2) {
	if (ind <= 0 || ind >= NOX_SPELLS_MAX) {
		return 0;
	}
	nox_spell_t* sp = &nox_spells_arr_588124[ind];
	switch (a2) {
	case 0:
		return sp->cast_sound;
	case 1:
		return sp->on_sound;
	case 2:
		return sp->off_sound;
	}
	return 0;
}

//----- (00424930) --------------------------------------------------------
wchar_t* nox_xxx_spellTitle_424930(int ind) {
	if (ind <= 0 || ind >= NOX_SPELLS_MAX) {
		return 0;
	}
	nox_spell_t* sp = &nox_spells_arr_588124[ind];
	if (!sp->valid) {
		return 0;
	}
	return sp->title;
}

//----- (00424960) --------------------------------------------------------
int nox_xxx_spellByTitle_424960(wchar_t* title) {
	for (int i = 1; i < NOX_SPELLS_MAX; i++) {
		nox_spell_t* sp = &nox_spells_arr_588124[i];
		if (nox_wcscmp(sp->title, title) == 0) {
			return i;
		}
	}
	return 0;
}

//----- (004249A0) --------------------------------------------------------
int nox_xxx_spellManaCost_4249A0(int ind, int a2) {
	if (ind <= 0 || ind >= NOX_SPELLS_MAX) {
		return 0;
	}

	if (a2 == 2) {
		switch (ind) {
		case 24:
			return (int)nox_xxx_gamedataGetFloat_419D40("EnergyBoltTrapCost");
		case 43:
			return (int)nox_xxx_gamedataGetFloat_419D40("LightningTrapCost");
		case 56:
			return (int)nox_xxx_gamedataGetFloat_419D40("ManaBombTrapCost");
		}
	}
	nox_spell_t* sp = &nox_spells_arr_588124[ind];
	return sp->mana_cost;
}

//----- (00424A20) --------------------------------------------------------
char* nox_xxx_spellPhonemes_424A20(int ind) {
	if (ind <= 0 || ind >= NOX_SPELLS_MAX) {
		return 0;
	}
	nox_spell_t* sp = &nox_spells_arr_588124[ind];
	return sp->phonemes;
}

//----- (00424A30) --------------------------------------------------------
wchar_t* nox_xxx_spellDescription_424A30(int ind) {
	if (ind <= 0 || ind >= NOX_SPELLS_MAX) {
		return 0;
	}
	nox_spell_t* sp = &nox_spells_arr_588124[ind];
	return sp->desc;
}

//----- (00424A50) --------------------------------------------------------
bool nox_xxx_spellHasFlags_424A50(int ind, int flags) {
	if (ind <= 0 || ind >= NOX_SPELLS_MAX) {
		return 0;
	}
	nox_spell_t* sp = &nox_spells_arr_588124[ind];
	return (sp->flags & flags) != 0;
}

//----- (00424A70) --------------------------------------------------------
unsigned int nox_xxx_spellFlags_424A70(int ind) {
	if (ind <= 0 || ind >= NOX_SPELLS_MAX) {
		return 0;
	}
	nox_spell_t* sp = &nox_spells_arr_588124[ind];
	return sp->flags;
}

//----- (00424A90) --------------------------------------------------------
void* nox_xxx_spellIcon_424A90(int ind) {
	if (ind <= 0 || ind >= NOX_SPELLS_MAX) {
		return 0;
	}
	nox_spell_t* sp = &nox_spells_arr_588124[ind];
	return sp->icon;
}

//----- (00424AB0) --------------------------------------------------------
void* nox_xxx_spellIconHighlight_424AB0(int ind) {
	if (ind <= 0 || ind >= NOX_SPELLS_MAX) {
		return 0;
	}
	nox_spell_t* sp = &nox_spells_arr_588124[ind];
	return sp->icon_enabled;
}

//----- (00424AD0) --------------------------------------------------------
int nox_xxx_spellFirstValid_424AD0() {
	for (int i = 1; i < NOX_SPELLS_MAX; i++) {
		nox_spell_t* sp = &nox_spells_arr_588124[i];
		if (sp->valid) {
			return i;
		}
	}
	return 0;
}

//----- (00424AF0) --------------------------------------------------------
int nox_xxx_spellNextValid_424AF0(int ind) {
	ind++;
	if (ind <= 0 || ind >= NOX_SPELLS_MAX) {
		return 0;
	}
	for (int i = ind; i < NOX_SPELLS_MAX; i++) {
		nox_spell_t* sp = &nox_spells_arr_588124[i];
		if (sp->valid) {
			return i;
		}
	}
	return 0;
}

//----- (00424B50) --------------------------------------------------------
bool nox_xxx_spellIsValid_424B50(int ind) {
	if (ind <= 0 || ind >= NOX_SPELLS_MAX) {
		return 0;
	}
	nox_spell_t* sp = &nox_spells_arr_588124[ind];
	return sp->valid;
}

//----- (00424B70) --------------------------------------------------------
bool nox_xxx_spellIsEnabled_424B70(int ind) {
	if (ind <= 0 || ind >= NOX_SPELLS_MAX) {
		return 0;
	}
	nox_spell_t* sp = &nox_spells_arr_588124[ind];
	return sp->enabled;
}

//----- (00424B90) --------------------------------------------------------
bool nox_xxx_spellEnable_424B90(int ind) {
	if (ind <= 0 || ind >= NOX_SPELLS_MAX) {
		return 0;
	}
	nox_spell_t* sp = &nox_spells_arr_588124[ind];
	sp->enabled = 1;
	return 1;
}

//----- (00424BB0) --------------------------------------------------------
bool nox_xxx_spellDisable_424BB0(int ind) {
	if (ind <= 0 || ind >= NOX_SPELLS_MAX) {
		return 0;
	}
	nox_spell_t* sp = &nox_spells_arr_588124[ind];
	sp->enabled = 0;
	return 1;
}

//----- (00424BF0) --------------------------------------------------------
bool nox_xxx_spellCanUseInTrap_424BF0(int ind) {
	if (ind <= 0 || ind >= NOX_SPELLS_MAX) {
		return 0;
	}
	if (nox_common_gameFlags_check_40A5C0(4096) && ind == 4) {
		return 0;
	}
	nox_spell_t* sp = &nox_spells_arr_588124[ind];
	return ((sp->flags >> 22) & 0x1) == 0; // NO_TRAP
}

//----- (00424C40) --------------------------------------------------------
int nox_xxx_spellPrice_424C40(int ind) {
	if (ind <= 0 || ind >= NOX_SPELLS_MAX) {
		return 0;
	}
	nox_spell_t* sp = &nox_spells_arr_588124[ind];
	double price = sp->price;
	if (nox_common_gameFlags_check_40A5C0(4096)) {
		price *= nox_xxx_gamedataGetFloat_419D40("QuestSpellWorthMultiplier");
	}
	return (int)price;
}

//----- (00424BD0) --------------------------------------------------------
void nox_xxx_spellEnableAll_424BD0() {
	for (int i = 1; i < NOX_SPELLS_MAX; i++) {
		nox_spell_t* sp = &nox_spells_arr_588124[i];
		sp->enabled = 1;
	}
}
