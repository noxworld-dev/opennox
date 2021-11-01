#include "client__shell__selcolor.h"

#include "common__strman.h"
#include "common/fs/nox_fs.h"
#include "GAME1.h"
#include "GAME1_2.h"
#include "GAME1_1.h"
#include "GAME1_3.h"
#include "GAME2_1.h"
#include "GAME2_3.h"
#include "GAME3.h"
#include "GAME3_1.h"
#include "GAME3_2.h"
#include "client__gui__window.h"
#include "client__shell__optsback.h"
extern uint32_t dword_5d4594_1308136;
extern uint32_t dword_5d4594_1308104;
extern uint32_t dword_5d4594_1308096;
extern uint32_t dword_5d4594_1308112;
extern uint32_t dword_5d4594_1308148;
extern uint32_t dword_587000_171388;
extern uint32_t dword_5d4594_1308140;
extern uint32_t dword_5d4594_1308144;
extern uint32_t dword_5d4594_1308152;
extern uint32_t dword_5d4594_1308116;
extern uint32_t dword_5d4594_1308100;
extern uint32_t dword_5d4594_1308132;
extern uint32_t dword_5d4594_1308108;
extern uint32_t dword_5d4594_1308120;
extern uint32_t dword_5d4594_1308128;
extern uint32_t dword_5d4594_1308124;
extern nox_gui_animation* nox_wnd_xxx_1308092;
extern uint32_t dword_5d4594_1308088;
extern uint32_t dword_5d4594_1308084;
extern uint32_t dword_5d4594_1307784;

//----- (004A5D00) --------------------------------------------------------
int nox_game_showSelColor_4A5D00() {
	char* v0;    // eax
	int result;  // eax
	int i;       // esi
	uint32_t* v3;  // eax
	int j;       // esi
	uint32_t* v5;  // edi
	wchar_t* v6; // eax
	uint32_t* v7;  // eax

	nox_game_addStateCode_43BDD0(700);
	v0 = nox_xxx_getHostInfoPtr_431770();
	dword_5d4594_1307784 = v0;
	v0[67] = 0;
	result = nox_new_window_from_file("SelColor.wnd", sub_4A7330);
	dword_5d4594_1308084 = result;
	if (result) {
		nox_xxx_wndSetWindowProc_46B300(result, sub_4A18E0);
		result = nox_gui_makeAnimation_43C5B0(*(uint32_t**)&dword_5d4594_1308084, 0, 0, 0, -440, 0, 20, 0, -40);
		nox_wnd_xxx_1308092 = result;
		if (result) {
			nox_wnd_xxx_1308092->field_0 = 700;
			nox_wnd_xxx_1308092->field_12 = sub_4A6890;
			nox_wnd_xxx_1308092->fnc_done_out = sub_4A6C90;
			sub_4A5E90();
			for (i = 720; i <= 729; ++i) {
				v3 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1308084, i);
				nox_xxx_wndSetDrawFn_46B340((int)v3, sub_4A6D20);
			}
			for (j = 761; j <= 792; ++j) {
				v5 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1308084, j);
				nox_xxx_wndSetDrawFn_46B340((int)v5, sub_4A6D20);
			}
			if (dword_587000_171388) {
				v6 = nox_strman_loadString_40F1D0("DefaultName", 0,
										   "C:\\NoxPost\\src\\client\\shell\\SelColor.c", 1138);
				nox_window_call_field_94(*(int*)&dword_5d4594_1308152, 16414, (int)v6, 0);
			}
			nox_xxx_wndRetNULL_46A8A0();
			dword_5d4594_1308088 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1308084, 760);
			nox_xxx_wndSetProc_46B2C0(*(int*)&dword_5d4594_1308088, sub_4A7330);
			nox_xxx_wndSetWindowProc_46B300(*(int*)&dword_5d4594_1308088, sub_4A7270);
			sub_46B120(*(uint32_t**)&dword_5d4594_1308088, 0);
			sub_4BFAD0();
			v7 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1308084, 740);
			nox_xxx_wndSetDrawFn_46B340((int)v7, sub_4A6DC0);
			result = 1;
		}
	}
	return result;
}
//----- (004A68C0) --------------------------------------------------------
wchar_t* sub_4A68C0() {
	wchar_t* v0;          // esi
	wchar_t* v1;          // eax
	wchar_t* v2;          // eax
	unsigned char* v3;  // edx
	int v4;               // eax
	int v5;               // ecx
	int v6;               // eax
	unsigned char* v7;  // eax
	int v8;               // ecx
	int v9;               // ecx
	int v10;              // eax
	int v11;              // ecx
	unsigned char* v12; // eax
	int v13;              // ecx
	int v14;              // eax
	int v15;              // ecx
	unsigned char* v16; // eax
	int v17;              // edx
	int v18;              // eax
	int v19;              // ecx
	unsigned char* v20; // eax
	wchar_t* result;      // eax

	v0 = (wchar_t*)nox_window_call_field_94(*(int*)&dword_5d4594_1308152, 16413, 0, 0);
	if (!*v0) {
		v1 = nox_strman_loadString_40F1D0("DefaultName", 0, "C:\\NoxPost\\src\\client\\shell\\SelColor.c", 225);
		nox_wcscpy(v0, v1);
	}
	nox_wcscpy(*(wchar_t**)&dword_5d4594_1307784, v0);
	if (!sub_4A6B50(*(wchar_t**)&dword_5d4594_1307784)) {
		v2 = nox_strman_loadString_40F1D0("DefaultName", 0, "C:\\NoxPost\\src\\client\\shell\\SelColor.c", 232);
		nox_wcscpy(*(wchar_t**)&dword_5d4594_1307784, v2);
	}
	v3 = getMemAt(0x5D4594, 1307796 + 3 * ((*(uint32_t*)(dword_5d4594_1308096 + 32) >> 16) +
						   32 * (unsigned short)*(uint32_t*)(dword_5d4594_1308096 + 32)));
	v4 = dword_5d4594_1307784 + 71;
	*(uint16_t*)(dword_5d4594_1307784 + 71) = *(uint16_t*)v3;
	*(uint8_t*)(v4 + 2) = v3[2];
	if (*(uint8_t*)(dword_5d4594_1308136 + 4) & 8) {
		v7 = getMemAt(0x5D4594, 1307796 + 3 * ((*(uint32_t*)(dword_5d4594_1308100 + 32) >> 16) +
							   32 * (unsigned short)*(uint32_t*)(dword_5d4594_1308100 + 32)));
		v8 = dword_5d4594_1307784 + 68;
		*(uint16_t*)(dword_5d4594_1307784 + 68) = *(uint16_t*)v7;
		*(uint8_t*)(v8 + 2) = v7[2];
	} else {
		v5 = dword_5d4594_1307784 + 71;
		v6 = dword_5d4594_1307784 + 68;
		*(uint16_t*)(dword_5d4594_1307784 + 68) = *(uint16_t*)(dword_5d4594_1307784 + 71);
		*(uint8_t*)(v6 + 2) = *(uint8_t*)(v5 + 2);
	}
	if (*(uint8_t*)(dword_5d4594_1308140 + 4) & 8) {
		v11 = dword_5d4594_1307784 + 74;
		v12 = getMemAt(0x5D4594, 1307796 + 3 * ((*(uint32_t*)(dword_5d4594_1308104 + 32) >> 16) +
								32 * (unsigned short)*(uint32_t*)(dword_5d4594_1308104 + 32)));
		*(uint16_t*)(dword_5d4594_1307784 + 74) = *(uint16_t*)v12;
		*(uint8_t*)(v11 + 2) = v12[2];
	} else {
		v9 = dword_5d4594_1307784 + 71;
		v10 = dword_5d4594_1307784 + 74;
		*(uint16_t*)(dword_5d4594_1307784 + 74) = *(uint16_t*)(dword_5d4594_1307784 + 71);
		*(uint8_t*)(v10 + 2) = *(uint8_t*)(v9 + 2);
	}
	if (*(uint8_t*)(dword_5d4594_1308144 + 4) & 8) {
		v15 = dword_5d4594_1307784 + 77;
		v16 = getMemAt(0x5D4594, 1307796 + 3 * ((*(uint32_t*)(dword_5d4594_1308108 + 32) >> 16) +
								32 * (unsigned short)*(uint32_t*)(dword_5d4594_1308108 + 32)));
		*(uint16_t*)(dword_5d4594_1307784 + 77) = *(uint16_t*)v16;
		*(uint8_t*)(v15 + 2) = v16[2];
	} else {
		v13 = dword_5d4594_1307784 + 71;
		v14 = dword_5d4594_1307784 + 77;
		*(uint16_t*)(dword_5d4594_1307784 + 77) = *(uint16_t*)(dword_5d4594_1307784 + 71);
		*(uint8_t*)(v14 + 2) = *(uint8_t*)(v13 + 2);
	}
	if (*(uint8_t*)(dword_5d4594_1308148 + 4) & 8) {
		v19 = dword_5d4594_1307784 + 80;
		v20 = getMemAt(0x5D4594, 1307796 + 3 * ((*(uint32_t*)(dword_5d4594_1308112 + 32) >> 16) +
								32 * (unsigned short)*(uint32_t*)(dword_5d4594_1308112 + 32)));
		*(uint16_t*)(dword_5d4594_1307784 + 80) = *(uint16_t*)v20;
		*(uint8_t*)(v19 + 2) = v20[2];
	} else {
		v17 = dword_5d4594_1307784 + 71;
		v18 = dword_5d4594_1307784 + 80;
		*(uint16_t*)(dword_5d4594_1307784 + 80) = *(uint16_t*)(dword_5d4594_1307784 + 71);
		*(uint8_t*)(v18 + 2) = *(uint8_t*)(v17 + 2);
	}
	*(uint8_t*)(dword_5d4594_1307784 + 83) = *(uint32_t*)(dword_5d4594_1308116 + 32) >> 16;
	*(uint8_t*)(dword_5d4594_1307784 + 84) = *(uint32_t*)(dword_5d4594_1308120 + 32) >> 16;
	*(uint8_t*)(dword_5d4594_1307784 + 85) = *(uint32_t*)(dword_5d4594_1308124 + 32) >> 16;
	*(uint8_t*)(dword_5d4594_1307784 + 86) = *(uint32_t*)(dword_5d4594_1308128 + 32) >> 16;
	result = *(wchar_t**)&dword_5d4594_1307784;
	*(uint8_t*)(dword_5d4594_1307784 + 87) = *(uint32_t*)(dword_5d4594_1308132 + 32) >> 16;
	return result;
}

//----- (004A75C0) --------------------------------------------------------
int sub_4A75C0() {
	wchar_t* v0;          // esi
	wchar_t* v1;          // eax
	wchar_t* v2;          // eax
	char v3;              // dl
	unsigned char* v4;  // edx
	short v5;           // si
	short v6;           // cx
	unsigned char v7;   // dl
	int v8;               // ecx
	char v9;              // dl
	unsigned char* v10; // eax
	int v11;              // eax
	unsigned char* v12; // ecx
	char* v13;            // edi
	short v14;          // dx
	unsigned char v15;  // al
	char* v16;            // edi
	int v17;              // edx
	char* v18;            // edi
	int i;                // esi
	FILE* v20;            // eax
	char* v21;            // eax
	char v23;             // [esp+2h] [ebp-512h]
	char v24[16];         // [esp+4h] [ebp-510h]
	char v25[sizeof(nox_savegame_xxx)];       // [esp+14h] [ebp-500h]

	if (nox_common_gameFlags_check_40A5C0(2048))
		nox_savegame_rm_4DBE10("WORKING", 0);
	memset(v25, 0, 0x4FCu);
	*(uint16_t*)&v25[1276] = 0;
	v0 = (wchar_t*)nox_window_call_field_94(*(int*)&dword_5d4594_1308152, 16413, 0, 0);
	if (!*v0) {
		v1 = nox_strman_loadString_40F1D0("DefaultName", 0, "C:\\NoxPost\\src\\client\\shell\\SelColor.c", 605);
		nox_wcscpy(v0, v1);
	}
	nox_wcscpy((wchar_t*)&v25[1224], v0);
	if (!sub_4A6B50((wchar_t*)&v25[1224])) {
		v2 = nox_strman_loadString_40F1D0("DefaultName", 0, "C:\\NoxPost\\src\\client\\shell\\SelColor.c", 612);
		nox_wcscpy((wchar_t*)&v25[1224], v2);
	}
	v3 = *(uint8_t*)(dword_5d4594_1307784 + 66);
	v25[1276] = 1;
	v25[1274] = v3;
	v4 = getMemAt(0x5D4594, 1307796 + 3 * ((*(uint32_t*)(dword_5d4594_1308096 + 32) >> 16) +
						   32 * (unsigned short)*(uint32_t*)(dword_5d4594_1308096 + 32)));
	*(uint16_t*)&v25[1204] = *(uint16_t*)v4;
	v5 = *(uint16_t*)v4;
	v25[1206] = v4[2];
	v23 = v4[2];
	if (*(uint8_t*)(dword_5d4594_1308136 + 4) & 8) {
		v8 = (*(uint32_t*)(dword_5d4594_1308100 + 32) >> 16) +
			 32 * (unsigned short)*(uint32_t*)(dword_5d4594_1308100 + 32);
		*(uint16_t*)&v25[1207] = *getMemU16Ptr(0x5D4594, 1307796 + 3 * v8);
		v7 = getMemByte(0x5D4594, 1307798 + 3 * v8);
	} else {
		v6 = *(uint16_t*)v4;
		v7 = v4[2];
		*(uint16_t*)&v25[1207] = v6;
	}
	v25[1209] = v7;
	if (*(uint8_t*)(dword_5d4594_1308140 + 4) & 8) {
		v10 = getMemAt(0x5D4594, 1307796 + 3 * ((*(uint32_t*)(dword_5d4594_1308104 + 32) >> 16) +
								32 * (unsigned short)*(uint32_t*)(dword_5d4594_1308104 + 32)));
		*(uint16_t*)&v25[1210] = *(uint16_t*)v10;
		v25[1212] = v10[2];
		v9 = v23;
	} else {
		v9 = v23;
		*(uint16_t*)&v25[1210] = v5;
		v25[1212] = v23;
	}
	if (*(uint8_t*)(dword_5d4594_1308144 + 4) & 8) {
		v11 = (*(uint32_t*)(dword_5d4594_1308108 + 32) >> 16) +
			  32 * (unsigned short)*(uint32_t*)(dword_5d4594_1308108 + 32);
		*(uint16_t*)&v25[1213] = *getMemU16Ptr(0x5D4594, 1307796 + 3 * v11);
		v25[1215] = getMemByte(0x5D4594, 1307798 + 3 * v11);
	} else {
		*(uint16_t*)&v25[1213] = v5;
		v25[1215] = v9;
	}
	if (*(uint8_t*)(dword_5d4594_1308148 + 4) & 8) {
		v12 = getMemAt(0x5D4594, 1307796 + 3 * ((*(uint32_t*)(dword_5d4594_1308112 + 32) >> 16) +
								32 * (unsigned short)*(uint32_t*)(dword_5d4594_1308112 + 32)));
		*(uint16_t*)&v25[1216] = *(uint16_t*)v12;
		v25[1218] = v12[2];
	} else {
		*(uint16_t*)&v25[1216] = v5;
		v25[1218] = v9;
	}
	v25[1219] = *(uint32_t*)(dword_5d4594_1308116 + 32) >> 16;
	v25[1220] = *(uint32_t*)(dword_5d4594_1308120 + 32) >> 16;
	v25[1221] = *(uint32_t*)(dword_5d4594_1308124 + 32) >> 16;
	v25[1222] = *(uint32_t*)(dword_5d4594_1308128 + 32) >> 16;
	v25[1223] = *(uint32_t*)(dword_5d4594_1308132 + 32) >> 16;
	v13 = nox_fs_root();
	v14 = *getMemU16Ptr(0x587000, 171768);
	strcpy(&v25[4], v13);
	v15 = getMemByte(0x587000, 171770);
	v16 = &v25[strlen(&v25[4]) + 4];
	*(uint32_t*)v16 = *getMemU32Ptr(0x587000, 171764);
	*((uint16_t*)v16 + 2) = v14;
	v16[6] = v15;
	if (nox_common_gameFlags_check_40A5C0(2048)) {
		v17 = *getMemU32Ptr(0x587000, 171776);
		v18 = &v25[strlen(&v25[4]) + 4];
		*(uint32_t*)v18 = *getMemU32Ptr(0x587000, 171772);
		*((uint32_t*)v18 + 1) = v17;
		*(uint16_t*)&v25[strlen(&v25[4]) + 4] = *getMemU16Ptr(0x587000, 171780);
	}
	nox_fs_mkdir(&v25[4]);
	nox_fs_set_workdir(&v25[4]);
	i = 0;
	if (nox_common_gameFlags_check_40A5C0(2048)) {
		strcpy(v24, "Player.plr");
	} else {
		for (i = 0; i < 100; ++i) {
			nox_sprintf(v24, "%.6s%2.2d.plr", &v25[1224], i);
			v20 = nox_fs_open(v24);
			if (!v20)
				break;
			nox_fs_close(v20);
		}
	}
	v21 = nox_fs_root();
	nox_fs_set_workdir(v21);
	if (i > 99)
		return 0;
	strcat(&v25[4], v24);
	if (nox_common_gameFlags_check_40A5C0(2048)) {
		if (v25[1274] == 0) {
			nox_xxx_gameSetMapPath_409D70("war01a.map");
		} else if (v25[1274] == 1) {
			nox_xxx_gameSetMapPath_409D70("wiz01a.map");
		} else if (v25[1274] == 2) {
			nox_xxx_gameSetMapPath_409D70("con01a.map");
		}
	}
	return sub_41CEE0((int)v25, 1);
}
