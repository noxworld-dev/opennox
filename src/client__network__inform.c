#include "client__network__inform.h"

#include "common__system__team.h"
#include "proto.h"
#include "server__ability__ability.h"
#include "server__magic__plyrspel.h"
#include "client__gui__guimsg.h"

//----- (004C9BF0) --------------------------------------------------------
int __cdecl nox_xxx_cliHandlePacketInform_4C9BF0(int a1) {
	int result;       // eax
	wchar_t* v2;      // eax
	wchar_t* v3;      // eax
	wchar_t* v4;      // eax
	wchar_t* v5;      // eax
	wchar_t* v6;      // eax
	char* v7;         // eax
	wchar_t* v8;      // eax
	wchar_t* v9;      // eax
	wchar_t* v10;     // eax
	wchar_t* v11;     // eax
	wchar_t* v12;     // eax
	char* v13;        // eax
	wchar_t* v14;     // eax
	char* v15;        // eax
	wchar_t* v16;     // eax
	wchar_t* v17;     // eax
	char* v18;        // edi
	wchar_t* v19;     // eax
	char* v20;        // edi
	wchar_t* v21;     // eax
	char* v22;        // edi
	wchar_t* v23;     // eax
	char* v24;        // eax
	wchar_t* v25;     // eax
	char* v26;        // eax
	wchar_t* v27;     // eax
	wchar_t* v28;     // eax
	wchar_t* v29;     // eax
	char* v30;        // edi
	char* v31;        // eax
	wchar_t* v32;     // eax
	wchar_t* v33;     // eax
	char* v34;        // edi
	char* v35;        // eax
	wchar_t* v36;     // eax
	wchar_t* v37;     // eax
	char* v38;        // edi
	char* v39;        // eax
	wchar_t* v40;     // eax
	wchar_t* v41;     // eax
	unsigned int v42; // kr04_4
	wchar_t* v43;     // eax
	wchar_t* v44;     // eax
	wchar_t* v45;     // [esp-10h] [ebp-418h]
	int v46;          // [esp-8h] [ebp-410h]
	wchar_t* v47;     // [esp-8h] [ebp-410h]
	int v48;          // [esp-4h] [ebp-40Ch]
	wchar_t* v49;     // [esp-4h] [ebp-40Ch]
	int v50;          // [esp-4h] [ebp-40Ch]
	int v51;          // [esp-4h] [ebp-40Ch]
	int v52;          // [esp-4h] [ebp-40Ch]
	wchar_t* v53;     // [esp-4h] [ebp-40Ch]
	wchar_t* v54;     // [esp-4h] [ebp-40Ch]
	wchar_t* v55;     // [esp-4h] [ebp-40Ch]
	wchar_t* v56;     // [esp-4h] [ebp-40Ch]
	int v57;          // [esp-4h] [ebp-40Ch]
	int v58;          // [esp-4h] [ebp-40Ch]
	int v59;          // [esp-4h] [ebp-40Ch]
	char* v60;        // [esp-4h] [ebp-40Ch]
	char* v61;        // [esp-4h] [ebp-40Ch]
	wchar_t v62[256]; // [esp+8h] [ebp-400h]
	wchar_t v63[256]; // [esp+208h] [ebp-200h]

	result = 0;
	switch (*(unsigned __int8*)(a1 + 1)) {
	case 0u:
		nox_xxx_abilGetError_4FB0B0_magic_plyrspel(*(_DWORD*)(a1 + 2));
		return 6;
	case 1u:
		v50 = nox_xxx_spellLoadName_424930(*(_DWORD*)(a1 + 2));
		v10 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 186124), 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 117);
		nox_swprintf(v62, v10, v50);
		nox_xxx_printCentered_445490(v62);
		return 6;
	case 2u:
		nox_xxx_abilGetSuccess_4FB960_ability(*(_DWORD*)(a1 + 2));
		return 6;
	case 3u:
		v13 = nox_common_playerInfoGetByID_417040(*(_DWORD*)(a1 + 2));
		if (!v13)
			return 6;
		v51 = (int)(v13 + 4704);
		v14 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 186320), 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 147);
		nox_swprintf(v62, v14, v51);
		nox_xxx_printCentered_445490(v62);
		return 6;
	case 4u:
		v15 = nox_common_playerInfoGetByID_417040(*(_DWORD*)(a1 + 2));
		if (!v15)
			return 6;
		v52 = (int)(v15 + 4704);
		v16 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 186384), 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 164);
		nox_swprintf(v62, v16, v52);
		goto LABEL_22;
	case 5u:
		v18 = nox_common_playerInfoGetByID_417040(*(_DWORD*)(a1 + 2));
		if (!v18)
			return 10;
		v54 = sub_418C20(*(_DWORD*)(a1 + 6));
		v19 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 186524), 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 196);
		nox_swprintf(v62, v19, v18 + 4704, v54);
		nox_xxx_printCentered_445490(v62);
		nox_xxx_clientPlaySoundSpecial_452D80(306, 100);
		return 10;
	case 6u:
		v20 = nox_common_playerInfoGetByID_417040(*(_DWORD*)(a1 + 2));
		if (!v20)
			return 10;
		v55 = sub_418C20(*(_DWORD*)(a1 + 6));
		v21 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 186592), 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 213);
		nox_swprintf(v62, v21, v20 + 4704, v55);
		nox_xxx_printCentered_445490(v62);
		nox_xxx_clientPlaySoundSpecial_452D80(303, 100);
		return 10;
	case 7u:
		v22 = nox_common_playerInfoGetByID_417040(*(_DWORD*)(a1 + 2));
		if (v22) {
			v56 = sub_418C20(*(_DWORD*)(a1 + 6));
			v23 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 186660), 0, "C:\\NoxPost\\src\\client\\Network\\inform.c",
										230);
			nox_swprintf(v62, v23, v22 + 4704, v56);
			nox_xxx_printCentered_445490(v62);
			nox_xxx_clientPlaySoundSpecial_452D80(304, 100);
		}
		return 10;
	case 8u:
		v53 = sub_418C20(*(_DWORD*)(a1 + 2));
		v17 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 186456), 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 179);
		nox_swprintf(v62, v17, v53);
	LABEL_22:
		nox_xxx_printCentered_445490(v62);
		nox_xxx_clientPlaySoundSpecial_452D80(305, 100);
		return 6;
	case 9u:
		v38 = nox_xxx_clientGetTeamColor_418AB0(*(_DWORD*)(a1 + 6));
		v39 = nox_common_playerInfoGetByID_417040(*(_DWORD*)(a1 + 2));
		if (!v39) {
			if (v38) {
				v41 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 187308), 0,
											"C:\\NoxPost\\src\\client\\Network\\inform.c", 374);
				nox_swprintf(v62, v41, v38);
				nox_xxx_printCentered_445490(v62);
			}
			return 10;
		}
		if (!v38)
			return 10;
		v46 = (int)(v39 + 4704);
		v40 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 187240), 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 365);
		nox_swprintf(v62, v40, v46, v38);
		nox_xxx_printCentered_445490(v62);
		return 10;
	case 0xAu:
		v34 = nox_common_playerInfoGetByID_417040(*(_DWORD*)(a1 + 2));
		v35 = nox_xxx_clientGetTeamColor_418AB0(*(_DWORD*)(a1 + 6));
		if (v35) {
			if (!v34)
				return 10;
			v61 = v35;
			v36 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 187108), 0, "C:\\NoxPost\\src\\client\\Network\\inform.c",
										334);
			nox_swprintf(v62, v36, v34 + 4704, v61);
			nox_xxx_printCentered_445490(v62);
			result = 10;
		} else {
			if (!v34)
				return 10;
			v37 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 187176), 0, "C:\\NoxPost\\src\\client\\Network\\inform.c",
										343);
			nox_swprintf(v62, v37, v34 + 4704);
			nox_xxx_printCentered_445490(v62);
			result = 10;
		}
		return result;
	case 0xBu:
		v30 = nox_common_playerInfoGetByID_417040(*(_DWORD*)(a1 + 2));
		v31 = nox_xxx_clientGetTeamColor_418AB0(*(_DWORD*)(a1 + 6));
		if (v31) {
			if (v30) {
				v60 = v31;
				v32 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 186984), 0,
											"C:\\NoxPost\\src\\client\\Network\\inform.c", 303);
				nox_swprintf(v62, v32, v30 + 4704, v60);
				nox_xxx_printCentered_445490(v62);
				return 10;
			}
		} else if (v30) {
			v33 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 187048), 0, "C:\\NoxPost\\src\\client\\Network\\inform.c",
										312);
			nox_swprintf(v62, v33, v30 + 4704);
			nox_xxx_printCentered_445490(v62);
			return 10;
		}
		return 10;
	case 0xCu:
		v11 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 186192), 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 128);
		nox_xxx_printCentered_445490(v11);
		if (!*(_DWORD*)(a1 + 2))
			return 6;
		v12 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 186260), 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 132);
		nox_xxx_printCentered_445490(v12);
		return 6;
	case 0xDu:
		switch (*(_DWORD*)(a1 + 2)) {
		case 0:
			v2 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 185600), 0, "C:\\NoxPost\\src\\client\\Network\\inform.c",
									   27);
			nox_xxx_printCentered_445490(v2);
			result = 6;
			break;
		case 1:
			v3 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 185668), 0, "C:\\NoxPost\\src\\client\\Network\\inform.c",
									   31);
			nox_xxx_printCentered_445490(v3);
			result = 6;
			break;
		case 2:
			v4 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 185736), 0, "C:\\NoxPost\\src\\client\\Network\\inform.c",
									   35);
			nox_xxx_printCentered_445490(v4);
			result = 6;
			break;
		case 3:
			v5 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 185804), 0, "C:\\NoxPost\\src\\client\\Network\\inform.c",
									   39);
			nox_xxx_printCentered_445490(v5);
			result = 6;
			break;
		default:
			return 6;
		}
		return result;
	case 0xEu:
		sub_495210(a1);
		return 11;
	case 0xFu:
		v42 = strlen((const char*)(a1 + 3)) + 1;
		if (nox_xxx_gameGetPlayState_4356B0() != 3)
			goto LABEL_57;
		if (*(_BYTE*)(a1 + 2)) {
			v47 = nox_strman_loadString_40F1D0((char*)(a1 + 3), 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 397);
			v43 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 187420), 0, "C:\\NoxPost\\src\\client\\Network\\inform.c",
										396);
			nox_swprintf(v63, v43, v47);
			nox_xxx_printCentered_445490(v63);
			result = v42 + 3;
		} else {
			v44 = nox_strman_loadString_40F1D0((char*)(a1 + 3), 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 402);
			nox_xxx_printCentered_445490(v44);
		LABEL_57:
			result = v42 + 3;
		}
		return result;
	case 0x10u:
		v49 = sub_418C20(*(_DWORD*)(a1 + 2));
		v9 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 186064), 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 105);
		nox_swprintf(v62, v9, v49);
		nox_xxx_printCentered_445490(v62);
		return 6;
	case 0x11u:
		v45 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 185864), 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 51);
		v6 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 185932), 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 50);
		nox_xxx_dialogMsgBoxCreate_449A10(0, (int)v6, (int)v45, 33, 0, 0);
		return 2;
	case 0x12u:
		v24 = nox_common_playerInfoGetByID_417040(*(_DWORD*)(a1 + 2));
		if (!v24)
			return 6;
		v57 = (int)(v24 + 4704);
		v25 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 186724), 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 247);
		nox_swprintf(v62, v25, v57);
		nox_xxx_printCentered_445490(v62);
		return 6;
	case 0x13u:
		v26 = nox_common_playerInfoGetByID_417040(*(_DWORD*)(a1 + 2));
		if (v26) {
			v58 = (int)(v26 + 4704);
			v27 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 186788), 0, "C:\\NoxPost\\src\\client\\Network\\inform.c",
										265);
			nox_swprintf(v62, v27, v58);
			nox_xxx_printCentered_445490(v62);
		}
		return 6;
	case 0x14u:
		v7 = nox_common_playerInfoGetByID_417040(*(_DWORD*)(a1 + 2));
		if (!v7)
			return 6;
		v48 = (int)(v7 + 4704);
		v8 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 185992), 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 90);
		nox_swprintf(v62, v8, v48);
		nox_xxx_printCentered_445490(v62);
		return 6;
	case 0x15u:
		v59 = *(_DWORD*)(a1 + 2);
		v28 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 186856), 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 281);
		nox_swprintf(v62, v28, v59);
		v29 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 186928), 0, "C:\\NoxPost\\src\\client\\Network\\inform.c", 282);
		nox_swprintf(v63, v29, v62);
		nox_xxx_printCentered_445490(v63);
		return 6;
	default:
		return result;
	}
}
