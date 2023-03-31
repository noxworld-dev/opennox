#ifndef NOX_COMMON_SAVEGAME_H
#define NOX_COMMON_SAVEGAME_H

#include <stdint.h>

#include "defs.h"

#define NOX_SAVEGAME_XXX_MAX 14
#pragma pack(push, 1)
typedef struct nox_savegame_xxx {
	uint32_t flags; // 0
	char path[1024]; // 4
	uint8_t field_1028[128];
	char map_name[32]; // 1156
	noxSYSTEMTIME timestamp; // 1188
	uint8_t field_1204[20];
	wchar2_t player_name[25]; // 1224
	uint8_t player_class; // 1274
	uint8_t field_1275;
	uint8_t field_1276;
	uint8_t stage; // 1277
} nox_savegame_xxx;
#pragma pack(pop)
_Static_assert(sizeof(nox_savegame_xxx) == 1278, "wrong size of nox_savegame_xxx structure!");

#endif // NOX_COMMON_SAVEGAME_H
