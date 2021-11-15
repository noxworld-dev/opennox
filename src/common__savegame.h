#ifndef NOX_COMMON_SAVEGAME_H
#define NOX_COMMON_SAVEGAME_H

#include <stdint.h>

#ifdef _WIN32
#include <windows.h>
#else
#include "windows_compat.h"
#endif

#include "static_assert.h"

#define NOX_SAVEGAME_XXX_MAX 14
#pragma pack(push, 1)
typedef struct nox_savegame_xxx {
	uint32_t flags; // 0
	char path[1024]; // 4
	uint8_t field_1028[160];
	SYSTEMTIME timestamp; // 1188
	uint8_t field_1204[20];
	uint8_t player_name[50]; // 1224
	uint8_t player_class; // 1274
	uint8_t field_1275;
	uint8_t field_1276;
	uint8_t stage; // 1277
} nox_savegame_xxx;
#pragma pack(pop)
_Static_assert(sizeof(nox_savegame_xxx) == 1278, "wrong size of nox_savegame_xxx structure!");
_Static_assert(sizeof(SYSTEMTIME) == 16, "wrong size of SYSTEMTIME structure!");

#endif // NOX_COMMON_SAVEGAME_H
