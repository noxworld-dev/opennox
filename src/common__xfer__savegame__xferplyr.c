// FIXME
#include "client__gui__guimsg.h"

#include "proto.h"

extern FILE* nox_file_2;

//----- (0041C8F0) --------------------------------------------------------
int __cdecl nox_xxx_savePlayerMB_41C8F0(char* a1, unsigned int a2) {
	wchar_t* v2;         // eax
	wchar_t* v3;         // eax
	int result;          // eax
	char* v5;            // eax
	FILE* v6;            // eax
	char* v7;            // esi
	int v8;              // edi
	wchar_t* v9;         // eax
	wchar_t* v10;        // eax
	CHAR PathName[1024]; // [esp+4h] [ebp-400h]

	if (nox_common_gameFlags_check_40A5C0(1) || a2 >= *getMemIntPtr(0x587000, 55984)) {
		v5 = nox_common_get_data_path_409E10();
		nox_sprintf(PathName, "%s\\Save\\", v5);
		CreateDirectoryA(PathName, 0);
		v6 = nox_xxx_openFileBin_408CC0((char*)getMemAt(0x5D4594, 2660688), 1);
		nox_file_2 = v6;
		if (v6) {
			if (nox_xxx_cryptOpen_408D40((int)v6, 27)) {
				v7 = a1;
				if ((_WORD)a2) {
					v8 = (unsigned __int16)a2;
					do {
						sub_409200(v7++, 1, 1, nox_file_2);
						--v8;
					} while (v8);
				}
				nox_xxx_fileBinClose_408D90(nox_file_2);
				if (nox_common_gameFlags_check_40A5C0(4096))
					*getMemU8Ptr(0x5D4594, 2661961) = sub_465DF0();
				else
					*getMemU8Ptr(0x5D4594, 2661961) = 0;
				if (nox_xxx_mapSavePlayerDataMB_41A230((char*)getMemAt(0x5D4594, 2660688))) {
					v9 = nox_strman_loadString_40F1D0("CharacterSaved", 0,
											   "C:\\NoxPost\\src\\common\\Xfer\\SaveGame\\XferPlyr.c", 3420);
					nox_xxx_consoleVPrint_450C00(0xCu, v9);
					v10 = nox_strman_loadString_40F1D0("CharacterSaved", 0,
												"C:\\NoxPost\\src\\common\\Xfer\\SaveGame\\XferPlyr.c", 3421);
					nox_xxx_printCentered_445490(v10);
					result = 1;
				} else {
					nox_xxx_networkLog_413D30((char*)getMemAt(0x587000, 56648));
					result = 0;
				}
			} else {
				nox_xxx_networkLog_413D30((char*)getMemAt(0x587000, 56600), getMemAt(0x5D4594, 2660688));
				result = 0;
			}
		} else {
			nox_xxx_networkLog_413D30((char*)getMemAt(0x587000, 56552), getMemAt(0x5D4594, 2660688));
			result = 0;
		}
	} else {
		v2 = nox_strman_loadString_40F1D0("Wol.c:WolApierror", 0,
								   "C:\\NoxPost\\src\\common\\Xfer\\SaveGame\\XferPlyr.c", 3341);
		nox_xxx_consoleVPrint_450C00(0xCu, v2);
		v3 = nox_strman_loadString_40F1D0("Wol.c:Wolapierror", 0,
								   "C:\\NoxPost\\src\\common\\Xfer\\SaveGame\\XferPlyr.c", 3342);
		nox_xxx_printCentered_445490(v3);
		nox_xxx_networkLog_413D30((char*)getMemAt(0x587000, 56480), getMemAt(0x5D4594, 2660688));
		result = 0;
	}
	return result;
}
