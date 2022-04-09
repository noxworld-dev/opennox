#include "server__xfer__savegame__savegame.h"
#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME2_2.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4_2.h"
#include "client__gui__guicon.h"
#include "client__gui__window.h"
#include "common/fs/nox_fs.h"
#include "common__strman.h"
#include "operators.h"
#include "server__system__server.h"

#ifdef _WIN32
#include <io.h>
#else
#include "windows_compat.h"
#endif

extern uint32_t dword_5d4594_1563084;
extern uint32_t dword_5d4594_1563088;
extern uint32_t dword_5d4594_1563092;

//----- (004738D0) --------------------------------------------------------
int sub_4738D0() {
	nox_xxx_bookHideMB_45ACA0(1);
	return 1;
}

bool nox_xxx_saveMakeFolder_0_4DB1D0();
bool nox_client_makeSaveMapDir_4DB5A0(char* a1, char* a2);

//----- (004DB600) --------------------------------------------------------
int nox_xxx_saveMakePlayerLocation_4DB600(int a1) {
	char* v1;     // eax
	float* v2;    // esi
	uint32_t* v3; // edi
	float v4;     // eax
	float v5;     // ecx
	int v6;       // ecx
	int v7;       // eax
	int v8;       // esi

	v1 = nox_common_playerInfoFromNum_417090(31);
	if (!v1) {
		return 0;
	}
	v2 = (float*)*((uint32_t*)v1 + 514);
	if (!v2) {
		return 0;
	}
	v3 = nox_xxx_newObjectByTypeID_4E3810("SaveGameLocation");
	if (!v3) {
		return 0;
	}
	v4 = v2[14];
	v5 = v2[15];
	if (a1) {
		v6 = *(uint32_t*)(a1 + 700);
		v4 = *(float*)(v6 + 80);
		v5 = *(float*)(v6 + 84);
	}
	nox_xxx_createAt_4DAA50((int)v3, 0, v4, v5);
	nox_xxx_unitsNewAddToList_4DAC00();
	v3[11] = *((uint32_t*)v2 + 11);
	v7 = *((uint32_t*)v2 + 129);
	if (v7) {
		do {
			v8 = *(uint32_t*)(v7 + 512);
			if (*(uint8_t*)(v7 + 16) & 4) {
				nox_xxx_unitSetOwner_4EC290((int)v3, v7);
			}
			v7 = v8;
		} while (v8);
	}
	return 1;
}

//----- (004DB6A0) --------------------------------------------------------
void nox_xxx_monstersAllBelongToHost_4DB6A0() {
	char* v0; // eax
	char* v1; // edi
	int v2;   // ebx
	int v3;   // esi
	int v4;   // ebp
	int v5;   // eax

	v0 = nox_common_playerInfoFromNum_417090(31);
	v1 = v0;
	if (v0 && *((uint32_t*)v0 + 514)) {
		if (!*getMemU32Ptr(0x5D4594, 1563124)) {
			*getMemU32Ptr(0x5D4594, 1563124) = nox_xxx_getNameId_4E3AA0("SaveGameLocation");
		}
		v2 = nox_server_getFirstObject_4DA790();
		if (v2) {
			while (*(unsigned short*)(v2 + 4) != *getMemU32Ptr(0x5D4594, 1563124)) {
				v2 = nox_server_getNextObject_4DA7A0(v2);
				if (!v2) {
					return;
				}
			}
			v3 = *(uint32_t*)(v2 + 516);
			if (v3) {
				do {
					v4 = *(uint32_t*)(v3 + 512);
					nox_xxx_unitSetOwner_4EC290(*((uint32_t*)v1 + 514), v3);
					if (*(uint8_t*)(v3 + 8) & 2) {
						if (*(uint8_t*)(*(uint32_t*)(v3 + 748) + 1440) & 0x80) {
							v5 = *(uint32_t*)(v3 + 12);
							LOBYTE(v5) = v5 | 0x80;
							*(uint32_t*)(v3 + 12) = v5;
							nox_xxx_netReportAcquireCreature_4D91A0((unsigned char)v1[2064], v3);
							nox_xxx_netMarkMinimapObject_417190((unsigned char)v1[2064], v3, 1);
						}
					}
					v3 = v4;
				} while (v4);
			}
			*(uint32_t*)(v2 + 44) = 0;
			nox_xxx_delayedDeleteObject_4E5CC0(v2);
		}
	}
}

//----- (004DB9C0) --------------------------------------------------------
void sub_4DB9C0() {
	int v0; // esi
	int v1; // edi

	v0 = nox_server_getFirstObject_4DA790();
	if (v0) {
		do {
			v1 = nox_server_getNextObject_4DA7A0(v0);
			if (nox_xxx_isUnit_4E5B50(v0)) {
				nox_xxx_delayedDeleteObject_4E5CC0(v0);
			}
			v0 = v1;
		} while (v1);
	}
	nox_object_t* obj = nox_xxx_getFirstUpdatable2Object_4DA840();
	if (obj) {
		do {
			nox_object_t* v3 = nox_xxx_getNextUpdatable2Object_4DA850(obj);
			if (sub_4E5B80(obj)) {
				nox_xxx_delayedDeleteObject_4E5CC0(obj);
			}
			obj = v3;
		} while (obj);
	}
}

//----- (004DB370) --------------------------------------------------------
int nox_xxx_saveDoAutosaveMB_4DB370_savegame(const char* a1) {
	char* v1;        // eax
	char* v2;        // esi
	int v3;          // eax
	int v4;          // ecx
	char* v5;        // eax
	char* v6;        // eax
	char* v7;        // eax
	unsigned int v8; // ecx
	unsigned int v9; // eax
	wchar_t* v10;    // eax
	char* v12;       // [esp-8h] [ebp-810h]
	char* v13;       // [esp-4h] [ebp-80Ch]
	char v14[1024];  // [esp+8h] [ebp-800h]
	char v15[1024];  // [esp+408h] [ebp-400h]

	sub_478000();
	nox_xxx_quickBarClose_4606B0();
	v1 = nox_common_playerInfoFromNum_417090(31);
	v2 = v1;
	if (!v1) {
		return 0;
	}
	v3 = *((uint32_t*)v1 + 514);
	if (!v3) {
		return 0;
	}
	if (!a1) {
		return 0;
	}
	v4 = *(uint32_t*)(v3 + 16);
	if ((v4 & 0x8000) != 0) {
		return 0;
	}
	if (!nox_xxx_saveMakeFolder_0_4DB1D0()) {
		return 0;
	}
	if (!nox_client_makeSaveDir_4DB540("WORKING")) {
		return 0;
	}
	v5 = nox_xxx_mapGetMapName_409B40();
	if (!nox_client_makeSaveMapDir_4DB5A0("WORKING", (int)v5)) {
		return 0;
	}
	if (!nox_xxx_saveMakePlayerLocation_4DB600(dword_5d4594_1563084)) {
		return 0;
	}
	v13 = nox_xxx_mapGetMapName_409B40();
	v12 = nox_xxx_mapGetMapName_409B40();
	v6 = nox_fs_root();
	nox_sprintf(v15, "%s\\Save\\%s\\%s\\%s.map", v6, "WORKING", v12, v13);
	if (!nox_xxx_mapSaveMap_51E010(v15, 0)) {
		return 0;
	}
	nox_xxx_monstersAllBelongToHost_4DB6A0();
	v7 = nox_fs_root();
	nox_sprintf(v14, "%s\\Save\\%s\\Player.plr", v7, "WORKING");
	v8 = *getMemU32Ptr(0x85B3FC, 10980) & 0xFFFFFFF7;
	*getMemU32Ptr(0x85B3FC, 10980) &= 0xFFFFFFF7;
	if (*getMemU32Ptr(0x5D4594, 1563076)) {
		v9 = v8;
		LOBYTE(v9) = v8 | 8;
		*getMemU32Ptr(0x85B3FC, 10980) = v9;
	}
	*getMemU8Ptr(0x85B3FC, 12257) = sub_450750();
	if (!nox_xxx_playerSaveToFile_41A140(v14, (unsigned char)v2[2064])) {
		return 0;
	}
	if (!nox_xxx_mapSavePlayerDataMB_41A230(v14)) {
		return 0;
	}
	if (strcmp(a1, "WORKING")) {
		v10 = nox_strman_loadString_40F1D0("AutoSaveComplete", 0,
										   "C:\\NoxPost\\src\\Server\\Xfer\\SaveGame\\SaveGame.c", 661);
		nox_xxx_printToAll_4D9FD0(0, v10);
		if (!nox_client_copySave_4DC100("WORKING", a1)) {
			return 0;
		}
	}
	dword_5d4594_1563092 = 0;
	dword_5d4594_1563088 = 0;
	return 1;
}

//----- (004DB7E0) --------------------------------------------------------
int nox_xxx_soloLoadGame_4DB7E0_savegame(const char* a1) {
	char* v1;            // ebp
	char* result;        // eax
	char* v3;            // eax
	wchar_t* v4;         // eax
	int v5;              // eax
	char* v6;            // eax
	wchar_t* v7;         // eax
	char v8[20];         // [esp+Ch] [ebp-414h]
	char FileName[1024]; // [esp+20h] [ebp-400h]

	v1 = nox_common_playerInfoFromNum_417090(31);
	if (!a1) {
		return 0;
	}
	if (!nox_common_gameFlags_check_40A5C0(2) || (result = (char*)sub_4738D0()) != 0) {
		sub_4DB9C0();
		if (!strcmp(a1, "WORKING") || (result = (char*)nox_client_copySave_4DC100(a1, "WORKING")) != 0) {
			v3 = nox_fs_root();
			nox_sprintf(FileName, "%s\\Save\\%s\\Player.plr", v3, getMemAt(0x587000, 199424));
			if (nox_fs_access(FileName, 0) == -1) {
				v4 = nox_strman_loadString_40F1D0("AutoSaveNotFound", 0,
												  "C:\\NoxPost\\src\\Server\\Xfer\\SaveGame\\SaveGame.c", 755);
				nox_xxx_printToAll_4D9FD0(0, v4);
				result = 0;
			} else {
				v5 = sub_41D090(FileName);
				nox_server_SetFirstObjectScriptID_4E3C60(v5);
				nox_server_ResetObjectGIDs_4E3C70();
				nox_xxx_gameSetSwitchSolo_4DB220(1);
				nox_xxx_gameSetNoMPFlag_4DB230(1);
				result = nox_xxx_cliPlrInfoLoadFromFile_41A2E0(FileName, 31);
				if (result) {
					nox_xxx_cliPrepareGameplay1_460E60();
					nox_xxx_cliPrepareGameplay2_4721D0();
					nox_sprintf(v8, "%s.map", v1 + 4760);
					nox_xxx_gameSetMapPath_409D70(v8);
					v6 = nox_fs_root();
					nox_sprintf((char*)getMemAt(0x5D4594, 1559960), "%s\\Save\\%s\\%s\\%s.map", v6,
								getMemAt(0x587000, 199532), v1 + 4760, v1 + 4760);
					nox_xxx_mapLoad_4D2450(v8);
					nox_xxx_cliPlayMapIntro_44E0B0(0);
					result = (char*)nox_xxx_plrLoad_41A480(FileName);
					if (result) {
						nox_gui_console_Clear_450B70();
						sub_445450();
						nox_xxx_destroyEveryChatMB_528D60();
						v7 = nox_strman_loadString_40F1D0("GameLoaded", 0,
														  "C:\\NoxPost\\src\\Server\\Xfer\\SaveGame\\SaveGame.c", 824);
						nox_xxx_printToAll_4D9FD0(0, v7);
						result = (char*)1;
					}
				}
			}
		}
	}
	return result;
}
