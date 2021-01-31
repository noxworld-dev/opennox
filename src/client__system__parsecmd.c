#include "client__system__parsecmd.h"

#include "common__system__settings.h"
#include "client__gui__guimsg.h"
#include "client__gui__servopts__general.h"
#include "client__gui__servopts__guiserv.h"

#include "static.h"
#include "proto.h"

extern _DWORD dword_5d4594_823696;
extern _DWORD dword_5d4594_833728;
extern _DWORD dword_5d4594_833732;
extern _DWORD dword_5d4594_823708;
extern _DWORD dword_5d4594_823684;
extern _DWORD dword_5d4594_1563664;
extern _DWORD nox_xxx_useAudio_587000_80832;
extern _DWORD dword_5d4594_2523744;
extern _DWORD dword_5d4594_823700;
extern _DWORD nox_server_connectionType_3596;
extern _DWORD dword_587000_311480;
extern _DWORD dword_5d4594_805836;
extern _DWORD dword_5d4594_823692;
extern _DWORD nox_client_renderGUI_80828;
extern _DWORD dword_5d4594_2650652;

#ifdef NOX_DEBUG
int nox_cheats_disabled = 0;
#else
int nox_cheats_disabled = 1;
#endif

//#ifndef NOX_CGO
//----- (00440D70) --------------------------------------------------------
int nox_cmd_racoiaws() {
	nox_cheats_disabled = 0;
	return 1;
}
//#endif // NOX_CGO

//----- (00450B20) --------------------------------------------------------
wchar_t* __cdecl sub_450B20(wchar_t* a1) {
	wchar_t* result; // eax

	result = a1;
	if (a1) {
		if (*a1) {
			result = nox_wcscpy((wchar_t*)getMemAt(0x5D4594, 832552), a1);
			dword_5d4594_833728 = 1;
		}
	}
	return result;
}

//----- (00440D80) --------------------------------------------------------
int __cdecl nox_cmd_lock(int a1, char a2, int a3) {
	wchar_t* v4; // eax

	if (a2 != 2)
		return 0;
	sub_450B20(*(wchar_t**)(a3 + 4));
	nox_xxx_conClear_450B70();
	v4 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 101668), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1329);
	nox_xxx_consoleVPrint_450C00(4u, v4);
	return 1;
}

//----- (00450B50) --------------------------------------------------------
int sub_450B50() {
	int result; // eax

	result = 0;
	*getMemU16Ptr(0x5D4594, 832552) = 0;
	dword_5d4594_833728 = 0;
	dword_5d4594_833732 = 0;
	return result;
}

//----- (00440DD0) --------------------------------------------------------
int __cdecl nox_cmd_unlock(int a1, char a2) {
	wchar_t* v3; // eax

	if (a2 != 1)
		return 0;
	sub_450B50();
	v3 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 101724), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1340);
	nox_xxx_consoleVPrint_450C00(4u, v3);
	return 1;
}

//----- (00440E10) --------------------------------------------------------
int __cdecl nox_cmd_set_sysop(int a1, char a2, int a3) {
	wchar_t* v4; // eax

	if (a2 != 3)
		return 0;
	nox_xxx_sysopSetPass_40A610(*(wchar_t**)(a3 + 4 * a1));
	v4 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 101780), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1352);
	nox_xxx_consoleVPrint_450C00(6u, v4);
	return 1;
}

//----- (00578F30) --------------------------------------------------------
int sub_578F30() {
	int result;          // eax
	unsigned __int8* v1; // esi

	result = dword_587000_311480;
	if (*(int*)&dword_587000_311480 != -1) {
		shutdown(*(SOCKET*)&dword_587000_311480, 2);
		result = closesocket(*(SOCKET*)&dword_587000_311480);
	}
	dword_587000_311480 = -1;
	*getMemU16Ptr(0x5D4594, 2523738) = 0;
	v1 = getMemAt(0x5D4594, 2516484);
	do {
		if (*(int*)v1 != -1) {
			shutdown(*(SOCKET*)&dword_587000_311480, 2);
			result = closesocket(*(_DWORD*)v1);
		}
		*(_DWORD*)v1 = -1;
		v1[4] = 0;
		*((_WORD*)v1 + 514) = 0;
		*((_WORD*)v1 + 515) = 0;
		*((_WORD*)v1 + 516) = 0;
		*((_DWORD*)v1 + 260) = 0;
		v1 += 1044;
	} while ((int)v1 < (int)getMemAt(0x5D4594, 2520660));
	return result;
}

//----- (00579830) --------------------------------------------------------
int sub_579830() {
	int result; // eax

	result = dword_5d4594_2523744;
	if (dword_5d4594_2523744) {
		result = sub_578F30();
		dword_5d4594_2523744 = 0;
	}
	return result;
}

//----- (00440E60) --------------------------------------------------------
int __cdecl nox_cmd_telnet_off(int a1, char a2) {
	wchar_t* v3; // eax

	if (a2 != 2)
		return 0;
	if (!nox_common_gameFlags_check_40A5C0(2048)) {
		sub_579830();
		v3 =
			nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 101840), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1368);
		nox_xxx_consoleVPrint_450C00(6u, v3);
	}
	return 1;
}

//----- (005797F0) --------------------------------------------------------
void nox_xxx_setPort_5797F0(uint16_t port) {
	if (dword_5d4594_2523744 != 1) {
		if (port <= 1024) {
			port = 18500;
		}
		*getMemU16Ptr(0x5D4594, 2523736) = port;
		sub_578E10();
		dword_5d4594_2523744 = 1;
	}
}

//----- (00579850) --------------------------------------------------------
uint16_t nox_xxx_getPort_579850() { return *getMemU16Ptr(0x5D4594, 2523736); }

//----- (00440EB0) --------------------------------------------------------
int __cdecl nox_cmd_telnet_on(int a1, unsigned __int8 a2, int a3) {
	unsigned __int16 v4; // ax
	wchar_t* v5;         // eax
	int v6;              // [esp-4h] [ebp-8h]

	if (a2 < 2u || a2 > 3u)
		return 0;
	if (nox_common_gameFlags_check_40A5C0(2048))
		return 1;
	if (a2 == 2) {
		nox_xxx_setPort_5797F0(0);
	} else {
		v4 = nox_wcstol(*(const wchar_t**)(a3 + 4 * a2 - 4), 0, 10);
		nox_xxx_setPort_5797F0(v4);
	}
	v6 = nox_xxx_getPort_579850();
	v5 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 101892), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1388);
	nox_xxx_consoleVPrint_450C00(6u, v5, v6);
	return 1;
}

//----- (00440F50) --------------------------------------------------------
int __cdecl nox_cmd_macros_on(int a1, char a2) {
	wchar_t* v3; // eax

	if (a2 != 2)
		return 0;
	*getMemU32Ptr(0x587000, 95416) = 1;
	v3 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 101944), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1400);
	nox_xxx_consoleVPrint_450C00(6u, v3);
	return 1;
}

//----- (00440F90) --------------------------------------------------------
int __cdecl nox_cmd_macros_off(int a1, char a2) {
	wchar_t* v3; // eax

	if (a2 != 2)
		return 0;
	*getMemU32Ptr(0x587000, 95416) = 0;
	v3 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 101996), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1411);
	nox_xxx_consoleVPrint_450C00(6u, v3);
	return 1;
}

//----- (00441050) --------------------------------------------------------
int nox_cmd_list_weapons() {
	wchar_t* v0; // ebx
	wchar_t* v1; // ebp
	char** v2;   // edi
	int v3;      // eax
	int v4;      // esi
	wchar_t* v5; // eax
	int v7;      // [esp-Ch] [ebp-18h]
	wchar_t* v8; // [esp-8h] [ebp-14h]

	v0 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 102048), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1460);
	v1 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 102096), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1461);
	v2 = (char**)sub_4E3B30();
	if (!v2)
		return 1;
	do {
		if ((unsigned int)v2[6] & 0x1000000) {
			v3 = sub_415910(v2[1]);
			v4 = sub_4159F0(v3);
			if (v4) {
				if (nox_xxx_getUnitDefDd10_4E3BA0(*(unsigned __int16*)v2)) {
					v8 = v0;
					v7 = v4;
					v5 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 102148), 0,
											   "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1475);
				} else {
					v8 = v1;
					v7 = v4;
					v5 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 102200), 0,
											   "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1477);
				}
				nox_xxx_consoleVPrint_450C00(6u, v5, v7, v8);
			}
		}
		v2 = (char**)sub_4E3B40((int)v2);
	} while (v2);
	return 1;
}

//----- (00441130) --------------------------------------------------------
int nox_cmd_list_armor() {
	wchar_t* v0; // ebx
	wchar_t* v1; // ebp
	char** v2;   // edi
	int v3;      // eax
	int v4;      // esi
	wchar_t* v5; // eax
	int v7;      // [esp-Ch] [ebp-18h]
	wchar_t* v8; // [esp-8h] [ebp-14h]

	v0 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 102252), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1492);
	v1 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 102300), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1493);
	v2 = (char**)sub_4E3B30();
	if (!v2)
		return 1;
	do {
		if ((unsigned int)v2[6] & 0x2000000) {
			v3 = sub_415DF0(v2[1]);
			v4 = sub_415E80(v3);
			if (v4) {
				if (nox_xxx_getUnitDefDd10_4E3BA0(*(unsigned __int16*)v2)) {
					v8 = v0;
					v7 = v4;
					v5 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 102352), 0,
											   "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1508);
				} else {
					v8 = v1;
					v7 = v4;
					v5 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 102404), 0,
											   "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1510);
				}
				nox_xxx_consoleVPrint_450C00(6u, v5, v7, v8);
			}
		}
		v2 = (char**)sub_4E3B40((int)v2);
	} while (v2);
	return 1;
}

//----- (00441210) --------------------------------------------------------
int nox_cmd_list_spells() {
	wchar_t* v0; // edi
	wchar_t* v1; // ebx
	int v2;      // esi
	wchar_t* v3; // eax
	int v5;      // [esp-Ch] [ebp-18h]
	int v6;      // [esp-8h] [ebp-14h]
	wchar_t* v7; // [esp-4h] [ebp-10h]

	v0 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 102456), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1524);
	v1 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 102504), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1525);
	v2 = 1;
	do {
		if (nox_xxx_spellGetValidMB_424B50(v2)) {
			if (nox_xxx_spellIsEnabled_424B70(v2)) {
				v7 = v0;
				v6 = nox_xxx_getManaCost_4249A0(v2, 1);
				v5 = nox_xxx_spellLoadName_424930(v2);
				v3 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 102556), 0,
										   "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1531);
			} else {
				v7 = v1;
				v6 = nox_xxx_getManaCost_4249A0(v2, 1);
				v5 = nox_xxx_spellLoadName_424930(v2);
				v3 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 102608), 0,
										   "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1533);
			}
			nox_xxx_consoleVPrint_450C00(6u, v3, v5, v6, v7);
		}
		++v2;
	} while (v2 < 137);
	return 1;
}

//----- (004412E0) --------------------------------------------------------
int nox_cmd_list_staffs() {
	wchar_t* v0;          // ebx
	wchar_t* v1;          // ebp
	unsigned __int16* v2; // edi
	int v3;               // eax
	int v4;               // eax
	int v5;               // esi
	wchar_t* v6;          // eax
	int v8;               // [esp-Ch] [ebp-18h]
	wchar_t* v9;          // [esp-8h] [ebp-14h]

	v0 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 102660), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1588);
	v1 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 102708), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1589);
	v2 = (unsigned __int16*)sub_4E3B30();
	if (!v2)
		return 1;
	do {
		v3 = *((_DWORD*)v2 + 6);
		if (v3 & 0x1000) {
			v4 = sub_415910(*((char**)v2 + 1));
			v5 = sub_4159F0(v4);
			if (v5) {
				if (nox_xxx_getUnitDefDd10_4E3BA0(*v2)) {
					v9 = v0;
					v8 = v5;
					v6 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 102760), 0,
											   "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1604);
				} else {
					v9 = v1;
					v8 = v5;
					v6 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 102812), 0,
											   "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1606);
				}
				nox_xxx_consoleVPrint_450C00(6u, v6, v8, v9);
			}
		}
		v2 = (unsigned __int16*)sub_4E3B40((int)v2);
	} while (v2);
	return 1;
}

//----- (004413C0) --------------------------------------------------------
int __cdecl nox_cmd_show_bindings(int a1, char a2) {
	unsigned __int8* v3; // esi
	wchar_t* v4;         // eax

	if (a2 != 2)
		return 0;
	v3 = getMemAt(0x587000, 94516);
	do {
		if (*(_WORD*)v3)
			nox_xxx_consoleVPrint_450C00(4u, (wchar_t*)getMemAt(0x587000, 102824), *((_DWORD*)v3 - 2), v3);
		v3 += 76;
	} while ((int)v3 < (int)getMemAt(0x587000, 95428));
	if (*getMemU32Ptr(0x587000, 95416))
		v4 =
			nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 102880), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1630);
	else
		v4 =
			nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 102932), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1632);
	nox_xxx_consoleVPrint_450C00(4u, v4);
	return 1;
}

//----- (00409AC0) --------------------------------------------------------
int nox_client_getBuildVersion_409AC0() { return *getMemU16Ptr(0x5D4594, 3480); }

//----- (00441550) --------------------------------------------------------
int __cdecl nox_cmd_show_game(int a1, char a2) {
	char* v2;           // esi
	int v4;             // edi
	int v5;             // eax
	wchar_t* v6;        // eax
	__int16 v7;         // ax
	wchar_t* v8;        // eax
	wchar_t* v9;        // eax
	struct in_addr v10; // eax
	char* v11;          // eax
	char* v12;          // [esp-18h] [ebp-5Ch]
	int v13;            // [esp-10h] [ebp-54h]
	int v14;            // [esp-Ch] [ebp-50h]
	char* v15;          // [esp-8h] [ebp-4Ch]
	int v16;            // [esp-8h] [ebp-4Ch]
	int v17;            // [esp-8h] [ebp-4Ch]
	wchar_t v18[32];    // [esp+4h] [ebp-40h]

	v2 = sub_4165B0();
	if (a2 != 2)
		return 0;
	v4 = nox_common_playerInfoCount_416F40();
	if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING))
		--v4;
	v5 = nox_client_getBuildVersion_409AC0();
	nox_xxx_consoleVPrint_450C00(6u, (wchar_t*)getMemAt(0x587000, 102952), nox_version_string_102944, v5);
	if (nox_common_gameFlags_check_40A5C0(0x2000)) {
		v15 = nox_xxx_serverOptionsGetServername_40A4C0();
		v6 =
			nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 103020), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1801);
		nox_xxx_consoleVPrint_450C00(6u, (wchar_t*)getMemAt(0x587000, 103028), v6, v15);
		v7 = nox_common_gameFlags_getVal_40A5B0();
		v16 = nox_xxx_guiServerOptionsGetGametypeName_4573C0(v7);
		v8 =
			nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 103080), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1802);
		nox_xxx_consoleVPrint_450C00(6u, (wchar_t*)getMemAt(0x587000, 103088), v8, v16);
		v17 = sub_40A180(*((_WORD*)v2 + 26));
		v14 = (unsigned __int16)nox_xxx_servGamedataGet_40A020(*((_WORD*)v2 + 26));
		v13 = nox_xxx_servGetPlrLimit_409FA0();
		v12 = nox_server_currentMapGetFilename_409B30();
		v9 =
			nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 103140), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1803);
		nox_xxx_consoleVPrint_450C00(6u, v9, v12, v4, v13, v14, v17);
		v10.S_un.S_addr = sub_554200(0);
		v11 = inet_ntoa(v10);
		nox_swprintf(v18, L"%S", v11);
		nox_xxx_consoleVPrint_450C00(6u, (wchar_t*)getMemAt(0x587000, 103160), v18);
	}
	return 1;
}

//----- (004416F0) --------------------------------------------------------
int nox_cmd_show_mmx() {
	wchar_t* v0; // eax

	if (dword_5d4594_805836)
		v0 =
			nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 103208), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1869);
	else
		v0 =
			nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 103260), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1871);
	nox_xxx_consoleVPrint_450C00(6u, v0);
	return 1;
}

//----- (00440A20) --------------------------------------------------------
void sub_440A20(wchar_t* a1, ...) {
	va_list va; // [esp+8h] [ebp+8h]

	va_start(va, a1);
	nox_vswprintf((wchar_t*)getMemAt(0x5D4594, 822660), a1, va);
	nox_xxx_printCentered_445490((wchar_t*)getMemAt(0x5D4594, 822660));
}

//----- (00441910) --------------------------------------------------------
int __cdecl nox_cmd_load(int a1, char a2, int a3) {
	int v4;             // eax
	int v5;             // ebx
	wchar_t* v6;        // eax
	unsigned int v7;    // kr04_4
	char* v8;           // ebx
	wchar_t* v9;        // eax
	char* v10;          // [esp-4h] [ebp-234h]
	char v11[260];      // [esp+8h] [ebp-228h]
	struct _stat v12;   // [esp+10Ch] [ebp-124h]
	CHAR FileName[256]; // [esp+130h] [ebp-100h]

	if (nox_common_gameFlags_check_40A5C0(4096))
		return 1;
	if (a2 != 2)
		return 0;
	nox_sprintf(&v11[4], "%S", *(_DWORD*)(a3 + 4));
	if (v11[4] != 35 && !sub_4CFE10(&v11[4]))
		return 1;
	v4 = nox_xxx_mapGetTypeMB_4CFFA0((int)getMemAt(0x5D4594, 3801836));
	v5 = v4;
	if (nox_common_gameFlags_check_40A5C0(0x2000)) {
		if (!(v5 && !(v5 & 0x200))) {
			return 1;
		}
		if (nox_common_gameFlags_check_40A5C0(128)) {
			if (v5 & 0x60 && nox_xxx_getTeamCounter_417DD0() != 2)
				nox_xxx_wndGuiTeamCreate_4185B0();
		} else if (!(nox_common_gameFlags_getVal_40A5B0() & v5)) {
			v6 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 103372), 0,
									   "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2005);
			sub_440A20(v6);
			return 1;
		}
	} else if (!(v5 & 0x200)) {
		return 1;
	}
	v7 = strlen(&v11[4]) + 1;
	if ((int)(v7 - 1) <= 4 || _strcmpi(&v11[v7 - 1], ".map")) {
		strcpy((char*)getMemAt(0x5D4594, 822324), &v11[4]);
		v8 = (char*)getMemAt(0x5D4594, 822324);
		strcat((char*)getMemAt(0x5D4594, 822324), ".map");
	} else {
		v8 = &v11[4];
	}
	if (!v8 || *v8 != 35 && (strcpy(FileName, "maps\\"), strncat(FileName, v8, strlen(v8) - 4),
			*(_WORD*)&FileName[strlen(FileName)] = *getMemU16Ptr(0x587000, 103416),
			strcat(FileName, v8), _stat(FileName, (int)&v12))) {
		v10 = v8;
		v9 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 103512), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
								   2076);
	} else {
		nox_xxx_mapLoadOrSaveMB_4DCC70(1);
		nox_xxx_mapLoad_4D2450(v8);
		sub_41D650();
		v10 = v8;
		v9 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 103460), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
								   2072);
	}
	sub_440A20(v9, v10);
	return 1;
}

// 44198D: variable 'v4' is possibly undefined

//----- (00441B90) --------------------------------------------------------
char** __cdecl sub_441B90(_DWORD* a1) {
	char** result; // eax
	char** v2;     // esi
	wchar_t* v3;   // eax

	result = (char**)a1;
	if (a1 && *a1) {
		v2 = (char**)(a1 + 2);
		do {
			if (!((_BYTE)result[3] & 4) && (!nox_cheats_disabled || !((_BYTE)v2[1] & 0x10))) {
				v3 = nox_strman_loadString_40F1D0(*v2, 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2097);
				nox_xxx_consoleVPrint_450C00(6u, (wchar_t*)getMemAt(0x587000, 103568), *(v2 - 1), v3);
			}
			v2 += 6;
			result = v2 - 2;
		} while (*(v2 - 2));
	}
	return result;
}

//----- (00441BF0) --------------------------------------------------------
int __cdecl sub_441BF0(int a1, int a2, int a3, const wchar_t** a4) {
	int result;          // eax
	int v5;              // edi
	const wchar_t** v6;  // eax
	const wchar_t** v7;  // esi
	char v8;             // al
	const wchar_t* v9;   // ecx
	const wchar_t** v10; // eax
	const wchar_t** v11; // esi
	wchar_t* v12;        // eax

	result = 0;
	if (*(_DWORD*)(a3 + 4 * a1)) {
		if (a4) {
			v5 = 0;
			if (*a4) {
				v6 = a4;
				v7 = a4;
				while (1) {
					if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 4 * a1), *v6)) {
						v8 = *((_BYTE*)v7 + 12);
						if (!(v8 & 4) && (!nox_cheats_disabled || !(v8 & 0x10)))
							break;
					}
					v9 = v7[6];
					v7 += 6;
					++v5;
					v6 = v7;
					if (!v9)
						return 0;
				}
				v10 = (const wchar_t**)a4[6 * v5 + 4];
				v11 = &a4[6 * v5];
				if (v10) {
					if ((unsigned __int8)a2 <= a1 + 1 || (result = sub_441BF0(a1 + 1, a2, a3, v10)) == 0) {
						sub_441B90(v11[4]);
						result = 1;
					}
				} else {
					v12 = nox_strman_loadString_40F1D0((char*)v11[2], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2135);
					nox_xxx_consoleVPrint_450C00(6u, v12);
					result = 1;
				}
			}
		}
	}
	return result;
}

//----- (00441CE0) --------------------------------------------------------
int __cdecl nox_cmd_help(int a1, int a2, int a3) {
	if ((unsigned __int8)a2 != 1)
		return sub_441BF0(1, a2, a3, (const wchar_t**)getMemAt(0x587000, 97368));
	sub_441B90(getMemAt(0x587000, 97368));
	return 1;
}

//----- (004421A0) --------------------------------------------------------
int nox_cmd_set_obs() {
	wchar_t* v0; // eax
	char* v2;    // eax

	v0 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 103680), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2440);
	nox_xxx_consoleVPrint_450C00(6u, v0);
	if (nox_common_gameFlags_check_40A5C0(1)) {
		v2 = nox_common_playerInfoGetByID_417040(*getMemIntPtr(0x5D4594, 2616328));
		nox_xxx_serverHandleClientConsole_443E90((int)v2, 0, *(wchar_t**)&dword_5d4594_823700);
	} else {
		nox_xxx_netServerCmd_440950(0, *(wchar_t**)&dword_5d4594_823700);
	}
	return 1;
}

//----- (004423D0) --------------------------------------------------------
int nox_cmd_set_save_debug() {
	wchar_t* v0; // eax

	nox_common_setEngineFlag(NOX_ENGINE_FLAG_28);
	v0 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 103744), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2541);
	nox_xxx_consoleVPrint_450C00(6u, v0);
	return 1;
}

//----- (00442410) --------------------------------------------------------
int nox_cmd_set_god() {
	wchar_t* v0; // eax

	if (!nox_common_gameFlags_check_40A5C0(4096)) {
		nox_xxx_godSetOrUnSet_4EF500(1);
		v0 =
			nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 103800), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2557);
		nox_xxx_consoleVPrint_450C00(6u, v0);
	}
	return 1;
}

//----- (00442450) --------------------------------------------------------
int nox_cmd_unset_god() {
	wchar_t* v0; // eax

	nox_xxx_godSetOrUnSet_4EF500(0);
	v0 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 103848), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2568);
	nox_xxx_consoleVPrint_450C00(6u, v0);
	return 1;
}
//----- (00442480) --------------------------------------------------------
int nox_cmd_set_sage() {
	wchar_t* v0; // eax

	if (!nox_common_gameFlags_check_40A5C0(4096)) {
		nullsub_26(1);
		v0 =
			nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 103900), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2585);
		nox_xxx_consoleVPrint_450C00(6u, v0);
	}
	return 1;
}

// 4EF4F0: using guessed type void __cdecl nullsub_26(_DWORD);
//----- (004424C0) --------------------------------------------------------
int nox_cmd_unset_sage() {
	wchar_t* v0; // eax

	nullsub_26(0);
	v0 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 103948), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2597);
	nox_xxx_consoleVPrint_450C00(6u, v0);
	return 1;
}

// 4EF4F0: using guessed type void __cdecl nullsub_26(_DWORD);

//----- (004424F0) --------------------------------------------------------
int __cdecl nox_cmd_set_cycle(int a1, char a2, int a3) {
	wchar_t* v3; // eax

	if (a2 == 3) {
		if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 4 * a1), *(const wchar_t**)getMemAt(0x587000, 94468))) {
			sub_4D0D90(1);
			v3 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 104000), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
									   2614);
		LABEL_6:
			nox_xxx_consoleVPrint_450C00(6u, v3);
			sub_4AD840();
			return 1;
		}
		if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 4 * a1), *(const wchar_t**)getMemAt(0x587000, 94472))) {
			sub_4D0D90(0);
			v3 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 104052), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
									   2621);
			goto LABEL_6;
		}
	}
	return 0;
}

//----- (00442590) --------------------------------------------------------
int __cdecl nox_cmd_set_weapons(int a1, char a2, int a3) {
	wchar_t* v3; // eax
	wchar_t* v5; // [esp-4h] [ebp-Ch]

	if (a2 == 3) {
		if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 4 * a1), *(const wchar_t**)getMemAt(0x587000, 94468))) {
			sub_409E70(1);
			nox_xxx____setargv_40A670();
			v5 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 104104), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
									   2644);
			v3 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 104160), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
									   2645);
		LABEL_6:
			nox_xxx_consoleVPrint_450C00(6u, v3, v5);
			return 1;
		}
		if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 4 * a1), *(const wchar_t**)getMemAt(0x587000, 94472))) {
			sub_409EC0(1);
			nox_xxx____setargv_40A670();
			v5 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 104208), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
									   2652);
			v3 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 104264), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
									   2653);
			goto LABEL_6;
		}
	}
	return 0;
}

//----- (00442670) --------------------------------------------------------
int __cdecl nox_cmd_set_staffs(int a1, char a2, int a3) {
	wchar_t* v3; // eax
	wchar_t* v5; // [esp-4h] [ebp-Ch]

	if (a2 == 3) {
		if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 4 * a1), *(const wchar_t**)getMemAt(0x587000, 94468))) {
			sub_409E70(16);
			nox_xxx____setargv_40A670();
			v5 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 104312), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
									   2674);
			v3 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 104368), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
									   2675);
		LABEL_6:
			nox_xxx_consoleVPrint_450C00(6u, v3, v5);
			return 1;
		}
		if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 4 * a1), *(const wchar_t**)getMemAt(0x587000, 94472))) {
			sub_409EC0(16);
			nox_xxx____setargv_40A670();
			v5 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 104416), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
									   2682);
			v3 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 104472), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
									   2683);
			goto LABEL_6;
		}
	}
	return 0;
}
//----- (00442840) --------------------------------------------------------
int __cdecl nox_cmd_set_name(int a1, unsigned __int8 a2, int a3) {
	int v3;          // ebx
	unsigned int v5; // edx
	char* v6;        // edi
	char* v7;        // edi
	char* v8;        // esi
	char v9;         // cl
	int v10;         // edx
	wchar_t* v11;    // eax
	_DWORD* v12;     // [esp+4h] [ebp-104h]
	char v13[128];   // [esp+8h] [ebp-100h]
	char v14[128];   // [esp+88h] [ebp-80h]

	v3 = a1;
	if (a2 < 3u)
		return 0;
	v13[0] = 0;
	if (a1 < a2) {
		v12 = (_DWORD*)(a3 + 4 * a1);
		do {
			nox_sprintf(v14, "%S", *v12);
			v5 = strlen(v14) + 1;
			v6 = &v13[strlen(v13)];
			memcpy(v6, v14, 4 * (v5 >> 2));
			v8 = &v14[4 * (v5 >> 2)];
			v7 = &v6[4 * (v5 >> 2)];
			v9 = v5;
			v10 = v3 + 1;
			memcpy(v7, v8, v9 & 3);
			if (v3 + 1 < a2)
				*(_WORD*)&v13[strlen(v13)] = *getMemU16Ptr(0x587000, 104484);
			++v3;
			++v12;
		} while (v10 < a2);
		if (v13[0]) {
			nox_xxx_gameSetServername_40A440(v13);
			v11 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 104528), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
										2766);
			nox_xxx_consoleVPrint_450C00(6u, v11, v13);
		}
	}
	return 1;
}
// 442840: using guessed type char var_100[128];
// 442840: using guessed type char var_80[128];

//----- (00442950) --------------------------------------------------------
int __cdecl nox_cmd_set_mnstrs(int a1, char a2, int a3) {
	wchar_t* v3; // eax
	wchar_t* v5; // [esp-4h] [ebp-10h]

	if (a2 == 3 || a2 == 4) {
		if (_nox_wcsicmp(*(const wchar_t**)(a3 + 8), *(const wchar_t**)getMemAt(0x587000, 94492))) {
			if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 4 * a1), *(const wchar_t**)getMemAt(0x587000, 94468))) {
				sub_409E70(4);
				nox_xxx____setargv_40A670();
				v5 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 104804), 0,
										   "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2810);
				v3 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 104860), 0,
										   "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2811);
				goto LABEL_13;
			}
			if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 4 * a1), *(const wchar_t**)getMemAt(0x587000, 94472))) {
				sub_409EC0(4);
				nox_xxx____setargv_40A670();
				v5 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 104912), 0,
										   "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2818);
				v3 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 104968), 0,
										   "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2819);
				goto LABEL_13;
			}
		} else if (a2 != 3) {
			if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 12), *(const wchar_t**)getMemAt(0x587000, 94468))) {
				sub_409E70(8);
				nox_xxx____setargv_40A670();
				v5 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 104580), 0,
										   "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2788);
				v3 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 104636), 0,
										   "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2789);
			LABEL_13:
				nox_xxx_consoleVPrint_450C00(6u, v3, v5);
				return 1;
			}
			if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 12), *(const wchar_t**)getMemAt(0x587000, 94472))) {
				sub_409E70(8);
				nox_xxx____setargv_40A670();
				v5 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 104692), 0,
										   "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2796);
				v3 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 104748), 0,
										   "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2797);
				goto LABEL_13;
			}
		}
	}
	return 0;
}

//----- (00442B00) --------------------------------------------------------
int __cdecl nox_cmd_set_spell(int a1, char a2, int a3) {
	wchar_t* v3;   // eax
	int v4;        // esi
	char* v5;      // ebx
	wchar_t* v7;   // eax
	int v8;        // [esp-4h] [ebp-74h]
	int v9;        // [esp-4h] [ebp-74h]
	char v10[100]; // [esp+Ch] [ebp-64h]

	if (a2 == 4) {
		if (nox_common_gameFlags_check_40A5C0(128)) {
			v8 = *(_DWORD*)(a3 + 8);
			v3 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 105020), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
									   3293);
			goto LABEL_16;
		}
		v4 = sub_424960(*(wchar_t**)(a3 + 8));
		if (v4 || (nox_sprintf(v10, "%S", *(_DWORD*)(a3 + 8)), (v4 = nox_xxx_spellNameToN_4243F0(v10)) != 0)) {
			if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 12), *(const wchar_t**)getMemAt(0x587000, 94468))) {
				v5 = sub_4165B0();
				if ((nox_common_gameFlags_check_40A5C0(64) || v5[52] & 0x40) && v4 == 132)
					return 1;
				if (nox_xxx_spellIsEnabled_424B70(v4))
					return 1;
				sub_424B90(v4);
				nox_xxx____setargv_40A670();
				v8 = *(_DWORD*)(a3 + 8);
				v3 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 105076), 0,
										   "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3324);
				goto LABEL_16;
			}
			if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 12), *(const wchar_t**)getMemAt(0x587000, 94472))) {
				if (!nox_xxx_spellIsEnabled_424B70(v4))
					return 1;
				nox_xxx_spellDisable_424BB0(v4);
				nox_xxx____setargv_40A670();
				v8 = *(_DWORD*)(a3 + 8);
				v3 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 105132), 0,
										   "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3333);
			LABEL_16:
				nox_xxx_consoleVPrint_450C00(6u, v3, v8);
				return 1;
			}
		} else {
			v9 = *(_DWORD*)(a3 + 8);
			v7 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 105188), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
									   3342);
			nox_xxx_consoleVPrint_450C00(6u, v7, v9);
		}
	}
	return 0;
}

//----- (004E5DB0) --------------------------------------------------------
void __cdecl nox_xxx_deleteAllObjectsOfType_4E5DB0(int a1) {
	int v1; // edi
	int v2; // ebx
	int v3; // eax
	int v4; // esi

	v1 = nox_server_getFirstObject_4DA790();
	if (v1) {
		do {
			v2 = nox_server_getNextObject_4DA7A0(v1);
			v3 = *(_DWORD*)(v1 + 504);
			if (v3) {
				do {
					v4 = *(_DWORD*)(v3 + 496);
					if (*(unsigned __int16*)(v3 + 4) == a1)
						nox_xxx_delayedDeleteObject_4E5CC0(v3);
					v3 = v4;
				} while (v4);
			}
			if (*(unsigned __int16*)(v1 + 4) == a1)
				nox_xxx_delayedDeleteObject_4E5CC0(v1);
			v1 = v2;
		} while (v2);
	}
}

//----- (004E3BC0) --------------------------------------------------------
int __cdecl sub_4E3BC0(int a1) {
	int result; // eax

	result = a1;
	dword_5d4594_1563664 ^= *(_DWORD*)(a1 + 16);
	*(_DWORD*)(a1 + 16) = 0;
	return result;
}

//----- (00415A60) --------------------------------------------------------
int __cdecl sub_415A60(wchar_t* a1) {
	char* v1;   // eax
	int v2;     // eax
	int result; // eax

	v1 = (char*)sub_415960(a1);
	if (v1 && (v2 = sub_415840(v1)) != 0)
		result = nox_xxx_unitDefGet_4E3B70(v2);
	else
		result = 0;
	return result;
}

//----- (00442C90) --------------------------------------------------------
int __cdecl nox_cmd_set_weapon(int a1, char a2, int a3) {
	wchar_t* v3;          // eax
	wchar_t* v4;          // eax
	unsigned __int16* v6; // esi
	wchar_t* v7;          // eax
	int v8;               // [esp-4h] [ebp-70h]
	int v9;               // [esp-4h] [ebp-70h]
	int v10;              // [esp-4h] [ebp-70h]
	char v11[100];        // [esp+8h] [ebp-64h]

	if (a2 == 4) {
		if (nox_common_gameFlags_check_40A5C0(128)) {
			v8 = *(_DWORD*)(a3 + 8);
			v3 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 105244), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
									   3361);
			goto LABEL_19;
		}
		if (_nox_wcsicmp(*(const wchar_t**)(a3 + 8), *(const wchar_t**)getMemAt(0x587000, 94492))) {
			v6 = (unsigned __int16*)sub_415A60(*(wchar_t**)(a3 + 8));
			if (v6 || (nox_sprintf(v11, "%S", *(_DWORD*)(a3 + 8)), (v6 = (unsigned __int16*)sub_415A30(v11)) != 0)) {
				if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 12), *(const wchar_t**)getMemAt(0x587000, 94468))) {
					if (nox_xxx_getUnitDefDd10_4E3BA0(*v6))
						return 1;
					sub_4E3BF0((int)v6);
					nox_xxx____setargv_40A670();
					v8 = *(_DWORD*)(a3 + 8);
					v3 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 105412), 0,
											   "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3401);
				LABEL_19:
					nox_xxx_consoleVPrint_450C00(6u, v3, v8);
					return 1;
				}
				if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 12), *(const wchar_t**)getMemAt(0x587000, 94472))) {
					if (!nox_xxx_getUnitDefDd10_4E3BA0(*v6) || nox_xxx_ammoCheck_415880((char*)*v6) == 1)
						return 1;
					sub_4E3BC0((int)v6);
					nox_xxx_deleteAllObjectsOfType_4E5DB0(*v6);
					nox_xxx____setargv_40A670();
					v8 = *(_DWORD*)(a3 + 8);
					v3 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 105468), 0,
											   "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3414);
					goto LABEL_19;
				}
			} else {
				v10 = *(_DWORD*)(a3 + 8);
				v7 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 105524), 0,
										   "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3423);
				nox_xxx_consoleVPrint_450C00(6u, v7, v10);
			}
		} else {
			if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 12), *(const wchar_t**)getMemAt(0x587000, 94468))) {
				sub_409E70(2);
				v9 = *(_DWORD*)(a3 + 12);
				v4 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 105296), 0,
										   "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3370);
			LABEL_9:
				nox_xxx_consoleVPrint_450C00(6u, v4, v9);
				sub_4AD840();
				return 1;
			}
			if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 12), *(const wchar_t**)getMemAt(0x587000, 94472))) {
				sub_409E70(2);
				v9 = *(_DWORD*)(a3 + 12);
				v4 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 105352), 0,
										   "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3377);
				goto LABEL_9;
			}
		}
	}
	return 0;
}

//----- (00415EF0) --------------------------------------------------------
int __cdecl sub_415EF0(wchar_t* a1) {
	char* v1;   // eax
	int v2;     // eax
	int result; // eax

	v1 = (char*)sub_415DA0(a1);
	if (v1 && (v2 = sub_415CD0(v1)) != 0)
		result = nox_xxx_unitDefGet_4E3B70(v2);
	else
		result = 0;
	return result;
}

//----- (00442ED0) --------------------------------------------------------
int __cdecl nox_cmd_set_armor(int a1, char a2, int a3) {
	wchar_t* v3;          // eax
	unsigned __int16* v4; // esi
	wchar_t* v6;          // eax
	int v7;               // [esp-4h] [ebp-70h]
	int v8;               // [esp-4h] [ebp-70h]
	char v9[100];         // [esp+8h] [ebp-64h]

	if (a2 == 4) {
		if (nox_common_gameFlags_check_40A5C0(128)) {
			v7 = *(_DWORD*)(a3 + 8);
			v3 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 105580), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
									   3442);
		LABEL_12:
			nox_xxx_consoleVPrint_450C00(6u, v3, v7);
			return 1;
		}
		v4 = (unsigned __int16*)sub_415EF0(*(wchar_t**)(a3 + 8));
		if (v4 || (nox_sprintf(v9, "%S", *(_DWORD*)(a3 + 8)), (v4 = (unsigned __int16*)sub_415EC0(v9)) != 0)) {
			if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 12), *(const wchar_t**)getMemAt(0x587000, 94468))) {
				if (!nox_xxx_getUnitDefDd10_4E3BA0(*v4)) {
					sub_4E3BF0((int)v4);
					nox_xxx____setargv_40A670();
					v7 = *(_DWORD*)(a3 + 8);
					v3 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 105636), 0,
											   "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3462);
					goto LABEL_12;
				}
				return 1;
			}
			if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 12), *(const wchar_t**)getMemAt(0x587000, 94472))) {
				if (nox_xxx_getUnitDefDd10_4E3BA0(*v4)) {
					sub_4E3BC0((int)v4);
					nox_xxx_deleteAllObjectsOfType_4E5DB0(*v4);
					nox_xxx____setargv_40A670();
					v7 = *(_DWORD*)(a3 + 8);
					v3 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 105692), 0,
											   "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3473);
					goto LABEL_12;
				}
				return 1;
			}
		} else {
			v8 = *(_DWORD*)(a3 + 8);
			v6 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 105748), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
									   3481);
			nox_xxx_consoleVPrint_450C00(6u, v6, v8);
		}
	}
	return 0;
}

//----- (00443050) --------------------------------------------------------
int __cdecl nox_cmd_set_staff(int a1, char a2, int a3) {
	int v3;       // edi
	wchar_t* v4;  // eax
	wchar_t* v6;  // eax
	int v7;       // [esp-4h] [ebp-8Ch]
	int v8;       // [esp-4h] [ebp-8Ch]
	char v9[128]; // [esp+8h] [ebp-80h]

	if (a2 == 4) {
		nox_sprintf(v9, "%S", *(_DWORD*)(a3 + 8));
		v3 = nox_xxx_utilThingDefByName_4E3B60(v9);
		if (v3) {
			if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 12), *(const wchar_t**)getMemAt(0x587000, 94468))) {
				sub_4E3BF0(v3);
				v7 = *(_DWORD*)(a3 + 8);
				v4 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 105808), 0,
										   "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3535);
			LABEL_7:
				nox_xxx_consoleVPrint_450C00(6u, v4, v7);
				return 1;
			}
			if (!_nox_wcsicmp(*(const wchar_t**)(a3 + 12), *(const wchar_t**)getMemAt(0x587000, 94472))) {
				sub_4E3BC0(v3);
				v7 = *(_DWORD*)(a3 + 8);
				v4 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 105864), 0,
										   "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3541);
				goto LABEL_7;
			}
		} else {
			v8 = *(_DWORD*)(a3 + 8);
			v6 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 105920), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
									   3548);
			nox_xxx_consoleVPrint_450C00(6u, v6, v8);
		}
	}
	return 0;
}

//----- (00443160) --------------------------------------------------------
int __cdecl nox_cmd_ban(int a1, char a2, int a3) {
	wchar_t* v4; // edi
	char* v5;    // eax
	char* v6;    // esi
	wchar_t* v7; // eax
	wchar_t* v8; // eax
	int v9;      // [esp-Ch] [ebp-Ch]

	if (a2 != 2)
		return 0;
	v4 = *(wchar_t**)(a3 + 4 * a1);
	v5 = nox_xxx_playerByName_4170D0(*(wchar_t**)(a3 + 4 * a1));
	v6 = v5;
	if (v5) {
		if (v5[2064] == 31) {
			v8 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 106024), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
									   3580);
			sub_440A20(v8);
			return 1;
		}
		if (nox_common_gameFlags_check_40A5C0(4096))
			sub_4DCFB0(*((_DWORD*)v6 + 514));
		else
			nox_xxx_playerDisconnByPlrID_4DEB00((unsigned __int8)v6[2064]);
		sub_416770(0, v4, v6 + 2112);
		v9 = (int)(v6 + 4704);
		v7 =
			nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 105976), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3577);
	} else {
		sub_416770(0, v4, 0);
		v9 = (int)v4;
		v7 =
			nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 106080), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3585);
	}
	sub_440A20(v7, v9);
	return 1;
}

//----- (00443250) --------------------------------------------------------
int nox_cmd_allow_user() {
	wchar_t* v0; // eax

	v0 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 106132), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3698);
	nox_xxx_consoleVPrint_450C00(6u, v0);
	return 1;
}

//----- (00443280) --------------------------------------------------------
int nox_cmd_allow_ip() {
	wchar_t* v0; // eax

	v0 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 106192), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3704);
	nox_xxx_consoleVPrint_450C00(6u, v0);
	return 1;
}

//----- (004432B0) --------------------------------------------------------
int __cdecl nox_cmd_kick(int a1, char a2, int a3) {
	char* v4;    // eax
	char* v5;    // esi
	wchar_t* v6; // eax
	wchar_t* v7; // eax

	if (a2 != 2)
		return 0;
	v4 = nox_xxx_playerByName_4170D0(*(wchar_t**)(a3 + 4 * a1));
	v5 = v4;
	if (!v4)
		return 1;
	if (v4[2064] == 31) {
		v7 =
			nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 106300), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3745);
		sub_440A20(v7);
		return 1;
	}
	if (nox_common_gameFlags_check_40A5C0(4096)) {
		sub_4DCFB0(*((_DWORD*)v5 + 514));
	} else {
		nox_xxx_playerCallDisconnect_4DEAB0((unsigned __int8)v5[2064], 4);
		v6 =
			nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 106252), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3739);
		sub_440A20(v6, v5 + 4704);
	}
	return 1;
}

//----- (00443380) --------------------------------------------------------
int __cdecl nox_cmd_set_players(int a1, char a2, int a3) {
	int v3;            // esi
	const wchar_t* v5; // eax
	int v6;            // eax
	wchar_t* v7;       // eax

	v3 = 0;
	if (a2 != 3)
		return 0;
	v5 = *(const wchar_t**)(a3 + 8);
	if (v5) {
		v6 = nox_wcstol(v5, 0, 10);
		v3 = v6;
		if (v6 >= 0) {
			if (v6 > 999)
				v3 = 999;
		} else {
			v3 = 0;
		}
		if (nox_xxx_servGetPlrLimit_409FA0() == v3)
			return 1;
		nox_xxx_servSetPlrLimit_409F80(v3);
		sub_455800();
	}
	v7 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 106360), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3779);
	sub_440A20(v7, v3);
	return 1;
}

//----- (00443480) --------------------------------------------------------
int nox_cmd_set_spellpts() {
	wchar_t* v0; // eax

	v0 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 106412), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3830);
	nox_xxx_consoleVPrint_450C00(6u, v0);
	return 1;
}

//----- (004434B0) --------------------------------------------------------
int nox_cmd_list_users() {
	wchar_t* v0;     // eax
	char* i;         // esi
	wchar_t* v2;     // eax
	wchar_t* v3;     // eax
	wchar_t v5[128]; // [esp+4h] [ebp-100h]

	v0 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 106472), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3839);
	nox_xxx_consoleVPrint_450C00(6u, v0);
	for (i = nox_common_playerInfoGetFirst_416EA0(); i; i = nox_common_playerInfoGetNext_416EE0((int)i)) {
		v5[0] = 0;
		nox_wcscat(v5, (const wchar_t*)i + 2352);
		if (dword_5d4594_823684 && i[3680] & 4) {
			nox_wcscat(v5, L", ");
			v2 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 106532), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
									   3851);
			nox_wcscat(v5, v2);
		}
		if (i[3680] & 8) {
			nox_wcscat(v5, L", ");
			v3 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 106592), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
									   3857);
			nox_wcscat(v5, v3);
		}
		nox_xxx_consoleVPrint_450C00(6u, (wchar_t*)getMemAt(0x587000, 106604), v5);
	}
	return 1;
}

//----- (0057A0F0) --------------------------------------------------------
int __cdecl sub_57A0F0(wchar_t* a1) {
	char* v1; // eax

	if (!nox_common_gameFlags_check_40A5C0(2))
		return 0;
	if (!a1)
		return 0;
	v1 = nox_xxx_playerByName_4170D0(a1);
	if (!v1)
		return 0;
	nox_xxx_playerUnsetStatus_417530((int)v1, 8);
	return 1;
}

//----- (0057A130) --------------------------------------------------------
int __cdecl sub_57A130(wchar_t* a1) {
	char* v1; // eax

	if (!a1)
		return 0;
	v1 = nox_xxx_playerByName_4170D0(a1);
	if (!v1)
		return 0;
	nox_xxx_playerUnsetStatus_417530((int)v1, 4);
	return 1;
}

//----- (00443610) --------------------------------------------------------
int __cdecl nox_cmd_unmute(int a1, unsigned __int8 a2, int a3) {
	wchar_t** v3; // esi
	int v4;       // eax
	int v5;       // eax
	wchar_t* v6;  // eax
	wchar_t* v8;  // [esp-4h] [ebp-14h]

	if (a2 < 2u || a2 > 3u)
		return 0;
	if (!dword_5d4594_823684) {
		v3 = (wchar_t**)(a3 + 4 * a1);
		goto LABEL_8;
	}
	v3 = (wchar_t**)(a3 + 4 * a1);
	if (_nox_wcsicmp(*(const wchar_t**)(a3 + 4 * a1), *(const wchar_t**)getMemAt(0x587000, 94496))) {
	LABEL_8:
		v5 = sub_57A0F0(*v3);
		goto LABEL_9;
	}
	v4 = a1 + 1;
	if (a1 + 1 != a2 - 1)
		return 0;
	v3 = (wchar_t**)(a3 + 4 * v4);
	v5 = sub_57A130(*(wchar_t**)(a3 + 4 * v4));
LABEL_9:
	v8 = *v3;
	if (v5)
		v6 =
			nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 106708), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3923);
	else
		v6 =
			nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 106652), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3921);
	nox_xxx_consoleVPrint_450C00(6u, v6, v8);
	return 1;
}

//----- (0057A080) --------------------------------------------------------
int __cdecl sub_57A080(wchar_t* a1) {
	char* v1; // eax

	if (!nox_common_gameFlags_check_40A5C0(2))
		return 0;
	if (!a1)
		return 0;
	v1 = nox_xxx_playerByName_4170D0(a1);
	if (!v1 || v1[2064] == 31)
		return 0;
	nox_xxx_netNeedTimestampStatus_4174F0((int)v1, 8);
	return 1;
}

//----- (0057A0C0) --------------------------------------------------------
int __cdecl sub_57A0C0(wchar_t* a1) {
	char* v1; // eax

	if (!a1)
		return 0;
	v1 = nox_xxx_playerByName_4170D0(a1);
	if (!v1)
		return 0;
	nox_xxx_netNeedTimestampStatus_4174F0((int)v1, 4);
	return 1;
}

//----- (004436E0) --------------------------------------------------------
int __cdecl nox_cmd_mute(int a1, unsigned __int8 a2, int a3) {
	wchar_t** v3; // esi
	int v4;       // eax
	int v5;       // eax
	wchar_t* v6;  // eax
	wchar_t* v8;  // [esp-4h] [ebp-14h]

	if (a2 < 2u || a2 > 3u)
		return 0;
	if (!dword_5d4594_823684) {
		v3 = (wchar_t**)(a3 + 4 * a1);
		goto LABEL_8;
	}
	v3 = (wchar_t**)(a3 + 4 * a1);
	if (_nox_wcsicmp(*(const wchar_t**)(a3 + 4 * a1), *(const wchar_t**)getMemAt(0x587000, 94496))) {
	LABEL_8:
		v5 = sub_57A080(*v3);
		goto LABEL_9;
	}
	v4 = a1 + 1;
	if (a1 + 1 != a2 - 1)
		return 0;
	v3 = (wchar_t**)(a3 + 4 * v4);
	v5 = sub_57A0C0(*(wchar_t**)(a3 + 4 * v4));
LABEL_9:
	v8 = *v3;
	if (v5)
		v6 =
			nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 106812), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3961);
	else
		v6 =
			nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 106756), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3959);
	nox_xxx_consoleVPrint_450C00(6u, v6, v8);
	return 1;
}

//----- (004437B0) --------------------------------------------------------
int __cdecl nox_cmd_exec(int a1, char a2) {
	wchar_t* v3; // eax
	int v4;      // [esp-4h] [ebp-4h]

	if (a2 != 2)
		return 0;
	if (!nox_common_gameFlags_check_40A5C0(1)) {
		v4 = dword_5d4594_823700;
		v3 =
			nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 106860), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3979);
		nox_xxx_consoleVPrint_450C00(6u, v3, v4);
	}
	nox_xxx_netServerCmd_440950(1, *(wchar_t**)&dword_5d4594_823700);
	return 1;
}

//----- (00443810) --------------------------------------------------------
int __cdecl nox_cmd_exec_rul(int a1, char a2, int a3) {
	wchar_t* v4;     // eax
	wchar_t v5[128]; // [esp+0h] [ebp-100h]

	if (a2 != 2)
		return 0;
	nox_wcscpy(v5, *(const wchar_t**)(a3 + 4));
	if (!nox_wcschr(v5, 0x2Eu))
		nox_wcscat(v5, L".rul");
	v4 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 106924), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4002);
	nox_xxx_consoleVPrint_450C00(6u, v4, v5);
	nox_xxx_doExecrul_4438A0((int)v5);
	return 1;
}

//----- (004439B0) --------------------------------------------------------
int __cdecl nox_xxx_cmdSysop_4439B0(int a1, unsigned __int8 a2) {
	wchar_t* v2; // eax
	int result;  // eax
	wchar_t* v4; // eax

	if (a2 == 1) {
		dword_5d4594_823696 = 1;
		v2 =
			nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 107008), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4014);
		nox_xxx_consoleVPrint_450C00(6u, v2);
		result = 1;
	} else {
		if (a2 > 1u && *getMemU32Ptr(0x5D4594, 823688)) {
			v4 = nox_wcsstr(*(const wchar_t**)&dword_5d4594_823700, L" ");
			if (v4)
				nox_xxx_netServerCmd_440950(2, v4);
		}
		result = 1;
	}
	return result;
}

//----- (00443BF0) --------------------------------------------------------
void __cdecl sub_443BF0(unsigned __int16* a1, char* a2) {
	int v2;               // esi
	signed int v3;        // ebp
	unsigned __int16 v4;  // ax
	unsigned __int16* v5; // ecx
	int v6;               // edx

	v2 = 0;
	if (a1) {
		if (a2 && (v3 = nox_wcslen(*(const wchar_t**)getMemAt(0x587000, 98256)), (v4 = *a1) != 0)) {
			v5 = a1;
			do {
				++v5;
				v6 = (unsigned __int8)(v2++ * (v4 - 1) % v3);
				*(unsigned __int16*)((char*)v5 - (char*)a1 + a2 - 2) =
					*(_WORD*)(*getMemU32Ptr(0x587000, 98256) + 2 * v6);
				v4 = *v5;
			} while (*v5);
			*(_WORD*)&a2[2 * v2] = 0;
		} else {
			*(_WORD*)a2 = 0;
		}
	} else {
		*(_WORD*)a2 = 0;
	}
}

//----- (00443A20) --------------------------------------------------------
int nox_xxx_consoleParseToken_443A20(int a1, int a2, int a3, const wchar_t** a4, int a5) {
	if (!*(_DWORD*)(a3 + 4 * a1) || !a4 || !*a4)
		return 0;

	int v5 = a3;
	int v6 = a1;
	int v7 = 0;
	const wchar_t** v8 = a4;
	const wchar_t** v9 = a4;
	wchar_t v19[256];
	while (1) {
		if ((_BYTE)v8[3] & 0x40) {
			sub_443BF0(*(unsigned __int16**)(v5 + 4 * v6), (char*)v19);
		} else {
			nox_wcscpy(v19, *(const wchar_t**)(v5 + 4 * v6));
		}
		if (!_nox_wcsicmp(v19, *v8)) {
			break;
		}
		const wchar_t* v10 = v9[6];
		v9 += 6;
		++v7;
		v8 = v9;
		if (!v10) {
			return 0;
		}
		v6 = a1;
		v5 = a3;
	}
	if (!nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) && nox_cheats_disabled && (int)a4[6 * v7 + 3] & 0x10) {
		return 0;
	}
	const wchar_t** v12 = &a4[6 * v7];
	char v13 = (char)a4[6 * v7 + 3];
	if (dword_5d4594_823684) {
		if (!(v13 & 1)) {
			wchar_t* v14 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 107068), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
										4091);
			nox_xxx_consoleVPrint_450C00(6u, v14);
			return 1;
		}
	} else {
		if (!(v13 & 2)) {
			wchar_t* v14 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 107120), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
										4097);
			nox_xxx_consoleVPrint_450C00(6u, v14);
			return 1;
		}
	}
	if (v13 & 0x20 && !nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
		return 1;
	}
	const wchar_t** v15 = (const wchar_t**)v12[4];
	int v16;
	if (v15) {
		if ((unsigned __int8)a2 <= a1 + 1) {
			wchar_t* v17 = nox_strman_loadString_40F1D0((char*)v12[2], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4125);
			nox_xxx_consoleVPrint_450C00(6u, v17);
			return 1;
		}
		v16 = nox_xxx_consoleParseToken_443A20(a1 + 1, a2, a3, v15, a5);
	} else {
		// call console command handler?
		v16 = ((int(__cdecl*)(int, int, int))v12[5])(a1 + 1, a2, a3);
	}
	if (!v16) {
		wchar_t* v17 = nox_strman_loadString_40F1D0((char*)v12[2], 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4125);
		nox_xxx_consoleVPrint_450C00(6u, v17);
		return 1;
	}
	return v16;
}

//----- (004409D0) --------------------------------------------------------
int __cdecl sub_4409D0(wchar_t* a1) {
	char v2[21]; // [esp+0h] [ebp-18h]

	v2[0] = -68;
	nox_wcsncpy((wchar_t*)&v2[1], a1, 8u);
	*(_WORD*)&v2[17] = 0;
	*(_WORD*)&v2[19] = *getMemU16Ptr(0x5D4594, 2616328);
	return nox_xxx_netClientSend2_4E53C0(31, v2, 21, 0, 1);
}

//----- (00443E40) --------------------------------------------------------
int __cdecl sub_443E40(wchar_t* a1) {
	int v1;            // esi
	const wchar_t** i; // edi

	v1 = 0;
	if (*(int*)&dword_5d4594_823708 <= 0)
		return 0;
	for (i = (const wchar_t**)getMemAt(0x5D4594, 816504); _nox_wcsicmp(a1, *i); i += 2) {
		if (++v1 >= *(int*)&dword_5d4594_823708)
			return 0;
	}
	return *getMemU32Ptr(0x5D4594, 8 * v1 + 816500);
}

//----- (00443C80) --------------------------------------------------------
int __cdecl nox_server_parseCmdText_443C80(wchar_t* a1, int a2) {
	int v2;      // ebp
	char v3;     // bl
	int result;  // eax
	wchar_t* v5; // esi
	int v6;      // eax
	int v7;      // ecx
	wchar_t* v8; // eax
	wchar_t* v9; // eax
	int v10;     // [esp+10h] [ebp-88h]
	int v11;     // [esp+14h] [ebp-84h]
	int v12[32]; // [esp+18h] [ebp-80h]
	// !!! If the command is bigger than 31 symbol (w/0 \0), game will crash because of stack corruption (bug
	// persists in original image)

	v2 = 0;
	v3 = 0;
	v11 = 0;
	LOBYTE(v10) = 0;
	if (a1) {
		dword_5d4594_823700 = a1;
		memset(getMemAt(0x5D4594, 820276), 0, 0x800u);
		if (nox_common_gameFlags_check_40A5C0(1)) {
			dword_5d4594_823684 = 1;
			*getMemU32Ptr(0x5D4594, 823688) = 0;
		} else {
			dword_5d4594_823684 = 0;
			*getMemU32Ptr(0x5D4594, 823688) = 1;
		}
		if (dword_5d4594_823696) {
			sub_4409D0(a1);
			result = 1;
			dword_5d4594_823696 = 0;
			return result;
		}
		nox_wcscpy((wchar_t*)getMemAt(0x5D4594, 820276), a1);
		if (*getMemU16Ptr(0x5D4594, 820276) == 34) {
			v5 = nox_wcstok((wchar_t*)getMemAt(0x5D4594, 820276 + 2), L"\"\n\r");
			v2 = 1;
		} else {
			v5 = nox_wcstok((wchar_t*)getMemAt(0x5D4594, 820276), L" ");
		}
		if (v5) {
			do {
				v6 = (int)v5;
				if (!v2) {
					v6 = sub_443E40(v5);
					if (!v6)
						v6 = (int)v5;
				}
				v7 = (unsigned __int8)v10;
				LOBYTE(v10) = ++v3;
				v12[v7] = v6;
				v8 = &v5[nox_wcslen(v5) + 1];
				if (v2)
					++v8;
				if (*v8 == 34) {
					v5 = nox_wcstok(v8 + 1, L"\"\n\r");
					v2 = 1;
				} else {
					v5 = nox_wcstok(0, L" ");
					v2 = 0;
				}
			} while (v5);
			if (v3) {
				v11 = nox_xxx_consoleParseToken_443A20(0, v10, (int)v12, (const wchar_t**)getMemAt(0x587000, 97368), a2);
				if (!v11) {
					v9 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 107236), 0,
											   "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4226);
					nox_xxx_consoleVPrint_450C00(6u, v9);
				}
			}
		}
	}
	result = v11;
	dword_5d4594_823700 = 0;
	return result;
}
// 443DEE: variable 'v10' is possibly undefined
// 443C80: using guessed type int var_80[32];

//----- (00443E90) --------------------------------------------------------
int __cdecl nox_xxx_serverHandleClientConsole_443E90(int a1, char a2, wchar_t* a3) {
	int v3;        // ecx
	int result;    // eax
	BOOL v5;       // edi
	wchar_t* v6;   // ebx
	int v7;        // eax
	int v8;        // eax
	wchar_t* v9;   // eax
	wchar_t* v10;  // esi
	int v11;       // edi
	wchar_t* v12;  // eax
	wchar_t* v13;  // eax
	char* v14;     // esi
	int v15;       // eax
	wchar_t* v16;  // eax
	char* v17;     // esi
	wchar_t* v18;  // eax
	int v19;       // [esp-8h] [ebp-94h]
	int v20;       // [esp-8h] [ebp-94h]
	wchar_t* v21;  // [esp-4h] [ebp-90h]
	char v22[128]; // [esp+Ch] [ebp-80h]

	if (!a1 || !*(_DWORD*)(a1 + 2056))
		return 0;
	if (a3)
		nox_wcscpy((wchar_t*)getMemAt(0x5D4594, 818228), a3);
	else
		*getMemU16Ptr(0x5D4594, 818228) = 0;
	v3 = a1;
	dword_5d4594_823692 = a1;
	if (a2 != 4 && a2 != 5 && a2) {
		if (nox_common_gameFlags_check_40A5C0(49152))
			return 1;
		v3 = dword_5d4594_823692;
	}
	switch (a2) {
	case 0:
		if (nox_common_gameFlags_check_40A5C0(8) || nox_common_gameFlags_check_40A5C0(4096) || *(_BYTE*)(a1 + 3680) & 1)
			goto LABEL_61;
		v5 = *getMemI16Ptr(0x5D4594, 818228) == -4083 && *getMemI16Ptr(0x5D4594, 818230) == -3923 &&
			 !*getMemU16Ptr(0x5D4594, 818232);
		if (nox_xxx_playerGoObserver_4E6860(a1, v5, 0) != 1)
			goto LABEL_61;
		v6 =
			nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 107288), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4287);
		v7 = nox_xxx_gamePlayIsAnyPlayers_40A8A0();
		if (v7) {
			if (!v5)
				nox_xxx_netNeedTimestampStatus_4174F0(a1, 256);
			if (nox_common_gameFlags_check_40A5C0(1024) && sub_40A770() == 1)
				sub_5095E0();
		}
		v8 = *(_DWORD*)(a1 + 2056);
		if (v8)
			nox_xxx_netChangeTeamMb_419570(v8 + 48, *(_DWORD*)(a1 + 2060));
		v21 = v6;
		v9 =
			nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 107332), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4308);
		goto LABEL_38;
	case 1:
		if (!sub_4D12A0(*(unsigned __int8*)(a1 + 2064)) &&
			*(unsigned __int8*)(a1 + 2064) != *getMemU32Ptr(0x5D4594, 2616328) &&
			!nox_common_gameFlags_check_40A5C0(2048)) {
			goto LABEL_61;
		}
		nox_wcstok((wchar_t*)getMemAt(0x5D4594, 818228), L" ");
		v10 = nox_wcstok(0, L" ");
		nox_sprintf(v22, "%S", v10);
		v11 = nox_xxx_scriptByNameMB_5071D0(v22);
		if (v11 != -1 && dword_5d4594_823692) {
			v12 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 107456), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
										4332);
			nox_xxx_consoleVPrint_450C00(6u, v12, v10);
			nox_server_doMapScript_507310(v11, *(_DWORD*)(dword_5d4594_823692 + 2056),
										  *(_DWORD*)(dword_5d4594_823692 + 2056));
			dword_5d4594_823692 = 0;
			result = 1;
		} else {
			v21 = v10;
			v9 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 107400), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
									   4329);
		LABEL_38:
			nox_xxx_consoleVPrint_450C00(6u, v9, v21);
			dword_5d4594_823692 = 0;
			result = 1;
		}
		return result;
	case 2:
		if (!sub_4D12A0(*(unsigned __int8*)(a1 + 2064)) &&
			*(unsigned __int8*)(a1 + 2064) != *getMemU32Ptr(0x5D4594, 2616328) &&
			!nox_common_gameFlags_check_40A5C0(2048)) {
			goto LABEL_61;
		}
		v19 = dword_5d4594_823692 + 4704;
		v13 =
			nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 107516), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4345);
		nox_xxx_consoleVPrint_450C00(6u, v13, v19, a3);
		nox_server_parseCmdText_443C80(a3, 0);
		dword_5d4594_823692 = 0;
		return 1;
	case 3:
		nox_xxx_printToAll_4D9FD0(0, a3);
		dword_5d4594_823692 = 0;
		return 1;
	case 4:
		if (!(*(_BYTE*)(v3 + 3680) & 1) && !(nox_common_getEngineFlag(NOX_ENGINE_FLAG_23))) {
			if (nox_common_gameFlags_check_40A5C0(1)) {
				v16 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 107568), 0,
											"C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4392);
				nox_xxx_consoleVPrint_450C00(6u, v16);
				dword_5d4594_823692 = 0;
				return 1;
			}
		LABEL_61:
			dword_5d4594_823692 = 0;
			return 1;
		}
		if (!*a3) {
			nox_xxx_playerCameraUnlock_4E6040(*(_DWORD*)(v3 + 2056));
			dword_5d4594_823692 = 0;
			return 1;
		}
		v17 = nox_common_playerInfoGetFirst_416EA0();
		if (!v17)
			goto LABEL_61;
		do {
			if (!_nox_wcsicmp(a3, (const wchar_t*)v17 + 2352))
				nox_xxx_playerCameraFollow_4E6060(*(_DWORD*)(dword_5d4594_823692 + 2056), *((_DWORD*)v17 + 514));
			v17 = nox_common_playerInfoGetNext_416EE0((int)v17);
		} while (v17);
		dword_5d4594_823692 = 0;
		result = 1;
		break;
	case 5:
		nox_xxx_printToAll_4D9FD0(16, a3);
		v14 = nox_common_playerInfoGetFirst_416EA0();
		if (!v14)
			goto LABEL_61;
		do {
			v15 = *((_DWORD*)v14 + 514);
			if (v15)
				nox_xxx_aud_501960(902, v15, 0, 0);
			v14 = nox_common_playerInfoGetNext_416EE0((int)v14);
		} while (v14);
		dword_5d4594_823692 = 0;
		return 1;
	default:
		v20 = v3 + 4704;
		v18 =
			nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 107624), 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4400);
		nox_xxx_consoleVPrint_450C00(6u, v18, v20, a3);
		goto LABEL_61;
	}
	return result;
}
// 443FC8: variable 'v7' is possibly undefined

//----- (004444C0) --------------------------------------------------------
int __cdecl sub_4444C0(int a1, int a2) {
	int v2;     // eax
	int result; // eax

	v2 = dword_5d4594_823708;
	*getMemU32Ptr(0x5D4594, 8 * dword_5d4594_823708 + 816500) = a1;
	*getMemU32Ptr(0x5D4594, 8 * v2 + 816504) = a2;
	result = v2 + 1;
	dword_5d4594_823708 = result;
	return result;
}

//----- (00444440) --------------------------------------------------------
void __cdecl sub_444440(int* a1) {
	int* v1;     // edi
	int* v2;     // ebx
	wchar_t* v3; // esi
	int v4;      // eax
	char v5[64]; // [esp+4h] [ebp-40h]

	v1 = a1;
	if (*a1) {
		v2 = a1;
		do {
			nox_sprintf(v5, "cmd_token:%S", *v1);
			v3 = nox_strman_loadString_40F1D0(v5, 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4441);
			v1[1] = (int)v3;
			sub_4444C0(*v1, (int)v3);
			if (nox_wcslen(v3) < 0x20) {
				if (v2[4])
					sub_444440((int*)v2[4]);
			}
			v4 = v2[6];
			v2 += 6;
			v1 = v2;
		} while (v4);
	}
}

//----- (00444570) --------------------------------------------------------
int sub_444570() {
	int* v0;     // esi
	wchar_t* v1; // eax
	int result;  // eax
	char v3[80]; // [esp+4h] [ebp-50h]

	v0 = getMemIntPtr(0x587000, 94504);
	do {
		nox_sprintf(v3, "keybind:%S", *v0);
		v1 = nox_strman_loadString_40F1D0(v3, 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 874);
		v0[1] = (int)v1;
		result = sub_4444C0(*v0, (int)v1);
		v0 += 19;
	} while ((int)v0 < (int)getMemAt(0x587000, 95416));
	return result;
}

//----- (00444560) --------------------------------------------------------
void sub_444560() { dword_5d4594_823708 = 0; }

//----- (004444F0) --------------------------------------------------------
int nox_xxx_cmdTokensLoad_4444F0() {
	int* v0;     // esi
	wchar_t* v1; // eax
	char v3[80]; // [esp+4h] [ebp-50h]

	sub_444560();
	v0 = getMemIntPtr(0x587000, 94468);
	do {
		nox_sprintf(v3, "cmd_token:%S", *v0);
		v1 = nox_strman_loadString_40F1D0(v3, 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4476);
		sub_4444C0(*v0, (int)v1);
		++v0;
	} while ((int)v0 < (int)getMemAt(0x587000, 94500));
	dword_5d4594_823696 = 0;
	sub_444440(getMemIntPtr(0x587000, 97368));
	return sub_444570();
}

//----- (00440B00) --------------------------------------------------------
int __cdecl nox_cmd_unbind(int a1, char a2, int a3) {
	int v3; // eax

	if (a2 != 2)
		return 0;
	if (nox_wcslen(*(const wchar_t**)(a3 + 4)) >= 0x20)
		return 0;
	v3 = sub_440AC0(*(wchar_t**)(a3 + 4));
	if (v3 == -1)
		return 0;
	*getMemU16Ptr(0x587000, 76 * v3 + 94516) = 0;
	return 1;
}

//----- (00440B50) --------------------------------------------------------
int __cdecl nox_cmd_broadcast(int a1, unsigned __int8 a2, int a3) {
	int result;      // eax
	wchar_t v4[128]; // [esp+0h] [ebp-100h]

	if (a2 == 1)
		return 0;
	result = sub_440BC0(a1, a2, a3);
	if (result) {
		nox_swprintf(v4, L"%S", result);
		nox_xxx_netServerCmd_440950(5, v4);
		result = 1;
	}
	return result;
}

//----- (00440C90) --------------------------------------------------------
int __cdecl nox_cmd_say(int a1, char a2) {
	if (a2 == 1)
		return 0;
	nox_xxx_cmdSayDo_46A4B0((wchar_t*)(dword_5d4594_823700 + 8), 0);
	return 1;
}

//----- (00440CC0) --------------------------------------------------------
int __cdecl nox_cmd_offonly1(int a1, char a2) {
	if (a2 != 2)
		return 0;
	nox_xxx_wndGuiTeamCreate_4185B0();
	return 1;
}

//----- (00440CE0) --------------------------------------------------------
int __cdecl nox_cmd_offonly2(int a1, char a2, int a3) {
	int result;          // eax
	char* v4;            // ebx
	const wchar_t* v5;   // eax
	int v6;              // edi
	unsigned __int8* v7; // esi

	if (a2 != 3)
		return 0;
	result = (int)getMemAt(0x5D4594, 822660);
	if (true) // TODO: byte_5D4594 != (unsigned __int8*)-822660
	{
		v4 = nox_xxx_cliGamedataGet_416590(1);
		v5 = *(const wchar_t**)getMemAt(0x587000, 94400);
		v6 = 0;
		if (*getMemU32Ptr(0x587000, 94400)) {
			v7 = getMemAt(0x587000, 94400);
			while (_nox_wcsicmp(v5, *(const wchar_t**)(a3 + 4 * a1))) {
				v5 = (const wchar_t*)*((_DWORD*)v7 + 2);
				v7 += 8;
				++v6;
				if (!v5)
					return 1;
			}
			*((_WORD*)v4 + 26) &= 0xE80Fu;
			*((_WORD*)v4 + 26) |= *getMemU16Ptr(0x587000, 8 * v6 + 94404);
		}
		result = 1;
	}
	return result;
}

//----- (00440FD0) --------------------------------------------------------
int __cdecl nox_cmd_set_fr(int a1, char a2) {
	if (a2 != 2)
		return 0;
	sub_43DDE0(1);
	return 1;
}

//----- (00440FF0) --------------------------------------------------------
int __cdecl nox_cmd_unset_fr(int a1, char a2) {
	if (a2 != 2)
		return 0;
	sub_43DDE0(0);
	return 1;
}

//----- (00441010) --------------------------------------------------------
int __cdecl nox_cmd_set_net_debug(int a1, char a2) {
	if (a2 != 2)
		return 0;

	nox_common_setEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG);
	return 1;
}

//----- (00441030) --------------------------------------------------------
int __cdecl nox_cmd_unset_net_debug(int a1, char a2) {
	if (a2 != 2)
		return 0;

	nox_common_resetEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG);
	return 1;
}

//----- (00441440) --------------------------------------------------------
int nox_cmd_show_ai() {
	nox_common_toggleEngineFlag(NOX_ENGINE_FLAG_ENABLE_SHOW_AI);
	return 1;
}

//----- (00441460) --------------------------------------------------------
int nox_cmd_show_gui() {
	int v0; // eax

	v0 = nox_client_renderGUI_80828 ^ 1;
	nox_client_renderGUI_80828 = v0;
	nox_xxx_useAudio_587000_80832 = v0;
	return 1;
}

//----- (00441480) --------------------------------------------------------
int nox_cmd_show_extents() {
	nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
	nox_common_toggleEngineFlag(NOX_ENGINE_FLAG_ENABLE_SHOW_EXTENTS);
	return 1;
}

//----- (004414B0) --------------------------------------------------------
int nox_cmd_show_perfmon() {
	nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
	sub_435F40();
	return 1;
}

//----- (004414D0) --------------------------------------------------------
int nox_cmd_show_netstat() {
	sub_470A60();
	return 1;
}

//----- (004414E0) --------------------------------------------------------
int nox_cmd_show_info() {
	nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
	sub_435F60();
	return 1;
}

//----- (00441500) --------------------------------------------------------
int nox_cmd_show_mem() {
	nox_server_currentMapGetFilename_409B30();
	sub_413E30();
	return 1;
}

//----- (00441530) --------------------------------------------------------
int nox_cmd_show_rank() {
	if (nox_common_gameFlags_check_40A5C0(0x2000))
		sub_4703F0();
	return 1;
}

//----- (004416B0) --------------------------------------------------------
int __cdecl nox_cmd_show_motd(int a1, char a2) {
	if (a2 != 2)
		return 0;
	nox_xxx_motd_4467F0();
	return 1;
}

//----- (004416D0) --------------------------------------------------------
int __cdecl nox_cmd_show_seq(int a1, char a2) {
	if (a2 != 2)
		return 0;
	sub_48D7B0();
	return 1;
}

//----- (00441740) --------------------------------------------------------
int nox_cmd_list_maps() {
	int* v0;       // esi
	int i;         // edi
	bool v2;       // zf
	signed int v3; // edi

	memset(getMemAt(0x5D4594, 822404), 0, 0x100u);
	v0 = nox_xxx_validateMapList_4D09B0();
	for (i = 1; v0; ++i) {
		sub_4417E0((wchar_t*)getMemAt(0x5D4594, 822404), (const char*)v0 + 12);
		if (!(i % 4)) {
			nox_xxx_consoleVPrint_450C00(6u, (wchar_t*)getMemAt(0x587000, 103276), getMemAt(0x5D4594, 822404));
			*getMemU16Ptr(0x5D4594, 822404) = 0;
		}
		v0 = sub_4D09C0(v0);
	}
	v3 = (i - 1) & 0x80000003;
	v2 = v3 == 0;
	if (v3 < 0)
		v2 = (((_BYTE)v3 - 1) | 0xFFFFFFFC) == (unsigned int)-1;
	if (!v2)
		nox_xxx_consoleVPrint_450C00(6u, (wchar_t*)getMemAt(0x587000, 103284), getMemAt(0x5D4594, 822404));
	return 1;
}

//----- (00441870) --------------------------------------------------------
int __cdecl nox_cmd_log_file(int a1, char a2, int a3) {
	int result;   // eax
	char v4[256]; // [esp+0h] [ebp-100h]

	result = 0;
	if (a2 == 3) {
		if (*(_DWORD*)(a3 + 8)) {
			nox_common_setEngineFlag(NOX_ENGINE_FLAG_24);
			nox_sprintf(v4, "%S", *(_DWORD*)(a3 + 8));
			result = sub_413A80(v4);
		}
	}
	return result;
}

//----- (004418D0) --------------------------------------------------------
int __cdecl nox_cmd_log_console(int a1, char a2) {
	if (a2 != 2)
		return 0;
	nox_common_setEngineFlag(NOX_ENGINE_FLAG_25);
	return 1;
}

//----- (004418F0) --------------------------------------------------------
int __cdecl nox_cmd_log_stop(int a1, char a2) {
	if (a2 != 2)
		return 0;
	sub_413C00();
	return 1;
}

//----- (00441D20) --------------------------------------------------------
int nox_cmd_set() { return 1; }

//----- (00441D30) --------------------------------------------------------
int nox_cmd_cheat_ability() {
	char* i; // esi

	if (!nox_common_gameFlags_check_40A5C0(0x2000)) {
		for (i = nox_common_playerInfoGetFirst_416EA0(); i; i = nox_common_playerInfoGetNext_416EE0((int)i)) {
			if (*((_DWORD*)i + 514))
				nox_xxx_playerCancelAbils_4FC180(*((_DWORD*)i + 514));
		}
	}
	return 1;
}

//----- (00441D80) --------------------------------------------------------
int __cdecl nox_cmd_cheat_goto(int a1, unsigned __int8 a2, int a3) {
	const char* v4; // edi
	char* v5;       // esi
	int v6;         // eax
	char* v7;       // eax
	char* v8;       // esi
	double v9;      // st7
	int v10;        // eax
	float2 v11;     // [esp+8h] [ebp-54h]
	char v12[76];   // [esp+10h] [ebp-4Ch]

	if (nox_common_gameFlags_check_40A5C0(0x2000))
		return 1;
	if (a2 >= 4u) {
		v7 = nox_common_playerInfoGetByID_417040(*getMemIntPtr(0x5D4594, 2616328));
		v8 = v7;
		if (!v7 || !*((_DWORD*)v7 + 514))
			return 0;
		nox_sprintf(v12, "%S", *(_DWORD*)(a3 + 8));
		v9 = atof(v12);
		v10 = *(_DWORD*)(a3 + 12);
		v11.field_0 = v9;
		nox_sprintf(v12, "%S", v10);
		v11.field_4 = atof(v12);
		nox_xxx_unitMove_4E7010(*((_DWORD*)v8 + 514), &v11);
		return 1;
	}
	if (a2 < 3u)
		return 0;
	nox_sprintf(v12, "%S", *(_DWORD*)(a3 + 8));
	v4 = nox_xxx_waypointByName_579E30(v12);
	if (!v4)
		return 1;
	v5 = nox_common_playerInfoGetFirst_416EA0();
	if (!v5)
		return 1;
	do {
		v6 = *((_DWORD*)v5 + 514);
		if (v6)
			nox_xxx_unitMove_4E7010(v6, (float2*)v4 + 1);
		v5 = nox_common_playerInfoGetNext_416EE0((int)v5);
	} while (v5);
	return 1;
}

//----- (00441EB0) --------------------------------------------------------
int nox_cmd_cheat_health() {
	char* i; // esi

	if (!nox_common_gameFlags_check_40A5C0(0x2000)) {
		for (i = nox_common_playerInfoGetFirst_416EA0(); i; i = nox_common_playerInfoGetNext_416EE0((int)i)) {
			if (*((_DWORD*)i + 514))
				nox_xxx_unitHPsetOnMax_4EE6F0(*((_DWORD*)i + 514));
		}
	}
	return 1;
}

//----- (00441F00) --------------------------------------------------------
int nox_cmd_cheat_mana() {
	char* i; // esi
	int v1;  // eax

	if (!nox_common_gameFlags_check_40A5C0(0x2000)) {
		for (i = nox_common_playerInfoGetFirst_416EA0(); i; i = nox_common_playerInfoGetNext_416EE0((int)i)) {
			v1 = *((_DWORD*)i + 514);
			if (v1)
				nox_xxx_playerManaAdd_4EEB80(v1, 2000);
		}
	}
	return 1;
}

//----- (00441F50) --------------------------------------------------------
int __cdecl nox_cmd_cheat_level(int a1, unsigned __int8 a2, int a3) {
	char* i;            // esi
	unsigned __int8 v5; // al

	if (!nox_common_gameFlags_check_40A5C0(0x2000)) {
		if (a2 < 3u)
			return 0;
		for (i = nox_common_playerInfoGetFirst_416EA0(); i; i = nox_common_playerInfoGetNext_416EE0((int)i)) {
			if (*((_DWORD*)i + 514)) {
				v5 = nox_wcstol(*(const wchar_t**)(a3 + 8), 0, 10);
				sub_4EF410(*((_DWORD*)i + 514), v5);
			}
		}
	}
	return 1;
}

//----- (00441FC0) --------------------------------------------------------
int __cdecl nox_cmd_cheat_spells(int a1, unsigned __int8 a2, int a3) {
	int v4;  // eax
	int v5;  // edi
	char* i; // ebp
	int v7;  // esi
	int* v8; // ebx

	if (!nox_common_gameFlags_check_40A5C0(0x2000)) {
		if (a2 < 3u)
			return 0;
		v4 = nox_wcstol(*(const wchar_t**)(a3 + 8), 0, 10);
		v5 = v4;
		if (v4 > 0) {
			if (v4 > 5)
				v5 = 5;
		} else {
			v5 = 1;
		}
		for (i = nox_common_playerInfoGetFirst_416EA0(); i; i = nox_common_playerInfoGetNext_416EE0((int)i)) {
			v7 = 0;
			v8 = (int*)(i + 3696);
			do {
				*v8 = v5;
				nox_xxx_playerAwardSpellProtection_56FCE0(*((_DWORD*)i + 1159), v7, v5);
				*v8 = v5;
				nox_xxx_playerAwardSpellProtection_56FCE0(*((_DWORD*)i + 1159), v7++, v5);
				++v8;
			} while (v7 < 137);
		}
	}
	return 1;
}

//----- (00442070) --------------------------------------------------------
int __cdecl nox_cmd_cheat_gold(int a1, unsigned __int8 a2, int a3) {
	int v4;  // edi
	char* i; // esi
	int v6;  // eax

	if (!nox_common_gameFlags_check_40A5C0(0x2000)) {
		if (a2 < 3u)
			return 0;
		v4 = nox_wcstol(*(const wchar_t**)(a3 + 8), 0, 10);
		for (i = nox_common_playerInfoGetFirst_416EA0(); i; i = nox_common_playerInfoGetNext_416EE0((int)i)) {
			v6 = *((_DWORD*)i + 514);
			if (v6) {
				if (v4 < 0)
					nox_xxx_playerSubGold_4FA5D0(v6, v4);
				else
					nox_xxx_playerAddGold_4FA590(v6, v4);
			}
		}
	}
	return 1;
}

//----- (00442120) --------------------------------------------------------
int nox_cmd_image() {
	sub_46DB00();
	return 1;
}

//----- (00442130) --------------------------------------------------------
int nox_cmd_quit() {
	sub_4460C0();
	return 1;
}

//----- (00442140) --------------------------------------------------------
int nox_cmd_exit() {
	if (nox_common_gameFlags_check_40A5C0(4096) && nox_common_gameFlags_check_40A5C0(1))
		sub_4D6B10(0);
	if (nox_common_gameFlags_check_40A5C0(0x2000000))
		sub_4460C0();
	nox_xxx_setContinueMenuOrHost_43DDD0(0);
	nox_game_exit_xxx_43DE60();
	return 1;
}

//----- (00442210) --------------------------------------------------------
int __cdecl nox_cmd_watch(int a1, unsigned __int8 a2, int a3) {
	int result;      // eax
	char* v4;        // eax
	wchar_t v5[128]; // [esp+4h] [ebp-100h]

	result = sub_440BC0(a1, a2, a3);
	if (result) {
		nox_swprintf(v5, L"%S", result);
		if (nox_common_gameFlags_check_40A5C0(1)) {
			v4 = nox_common_playerInfoGetByID_417040(*getMemIntPtr(0x5D4594, 2616328));
			if (a2 <= 1u)
				nox_xxx_serverHandleClientConsole_443E90((int)v4, 4, (wchar_t*)getMemAt(0x5D4594, 823768));
			else
				nox_xxx_serverHandleClientConsole_443E90((int)v4, 4, v5);
			result = 1;
		} else {
			if (a2 <= 1u)
				nox_xxx_netServerCmd_440950(4, (wchar_t*)getMemAt(0x5D4594, 823764));
			else
				nox_xxx_netServerCmd_440950(4, v5);
			result = 1;
		}
	}
	return result;
}

//----- (004422D0) --------------------------------------------------------
int __cdecl nox_cmd_gamma(int a1, unsigned __int8 a2, int a3) {
	const wchar_t* v3; // eax
	int v4;            // esi
	int v5;            // esi
	int v6;            // eax
	int v8;            // [esp-14h] [ebp-14h]

	if (a2 <= 1u)
		return 1;
	v3 = *(const wchar_t**)(a3 + 4 * a1);
	if (*v3 == 43) {
		v4 = nox_wcstol(v3, 0, 10);
		v8 = nox_video_getGammaSetting_434B00() + v4;
		nox_video_setGammaSetting_434B30(v8);
	} else {
		if (*v3 == 45) {
			v5 = nox_wcstol(v3, 0, 10);
			v6 = nox_video_getGammaSetting_434B00() - v5;
		} else {
			v6 = nox_wcstol(v3, 0, 10);
		}
		nox_video_setGammaSetting_434B30(v6);
	}
	sub_434B60();
	return 1;
}

//----- (00442340) --------------------------------------------------------
int __cdecl nox_cmd_window(int a1, unsigned __int8 a2, int a3) {
	const wchar_t* v3; // eax
	int v4;            // eax
	int v6;            // eax

	if (a2 > 1u) {
		v3 = *(const wchar_t**)(a3 + 4 * a1);
		if (*v3 != 43 && *v3 != 45) {
			v4 = nox_wcstol(v3, 0, 10);
			sub_476700(v4, 0);
			return 1;
		}
		v6 = nox_wcstol(v3, 0, 10);
		sub_476700(0, v6);
	}
	return 1;
}

//----- (00442750) --------------------------------------------------------
int nox_cmd_set_qual_modem() {
	int v0; // eax

	dword_5d4594_2650652 = 1;
	v0 = sub_40A710(4);
	nox_xxx_rateUpdate_40A6D0(v0);
	nox_server_connectionType_3596 = 4;
	sub_4AD840();
	return 1;
}

//----- (00442780) --------------------------------------------------------
int nox_cmd_set_qual_isdn() {
	int v0; // eax

	dword_5d4594_2650652 = 1;
	v0 = sub_40A710(3);
	nox_xxx_rateUpdate_40A6D0(v0);
	nox_server_connectionType_3596 = 3;
	sub_4AD840();
	return 1;
}

//----- (004427B0) --------------------------------------------------------
int nox_cmd_set_qual_cable() {
	int v0; // eax

	dword_5d4594_2650652 = 1;
	v0 = sub_40A710(2);
	nox_xxx_rateUpdate_40A6D0(v0);
	nox_server_connectionType_3596 = 2;
	sub_4AD840();
	return 1;
}

//----- (004427E0) --------------------------------------------------------
int nox_cmd_set_qual_t1() {
	int v0; // eax

	dword_5d4594_2650652 = 1;
	v0 = sub_40A710(1);
	nox_xxx_rateUpdate_40A6D0(v0);
	nox_server_connectionType_3596 = 1;
	sub_4AD840();
	return 1;
}

//----- (00442810) --------------------------------------------------------
int nox_cmd_set_qual_lan() {
	int v0; // eax

	dword_5d4594_2650652 = 0;
	v0 = sub_40A710(1);
	nox_xxx_rateUpdate_40A6D0(v0);
	nox_server_connectionType_3596 = 1;
	sub_4AD840();
	return 1;
}

//----- (00443400) --------------------------------------------------------
int __cdecl nox_cmd_set_time(int a1, char a2, int a3) {
	char* v4;           // esi
	const wchar_t* v5;  // eax
	unsigned __int8 v6; // al

	if (a2 != 3)
		return 0;
	v4 = sub_4165B0();
	v5 = *(const wchar_t**)(a3 + 8);
	if (v5) {
		v6 = nox_wcstol(v5, 0, 10);
		sub_40A040_settings(*((_WORD*)v4 + 26), v6);
	}
	return 1;
}

//----- (00443440) --------------------------------------------------------
int __cdecl nox_cmd_set_lessons(int a1, char a2, int a3) {
	const wchar_t* v4;   // esi
	char* v5;            // edi
	unsigned __int16 v6; // ax

	if (a2 != 3)
		return 0;
	v4 = *(const wchar_t**)(a3 + 8);
	v5 = sub_4165B0();
	if (v4) {
		v6 = nox_wcstol(v4, 0, 10);
		sub_409FB0_settings(*((_WORD*)v5 + 26), v6);
	}
	return 1;
}

//----- (004435C0) --------------------------------------------------------
int nox_cmd_clear() {
	nox_xxx_conClear_450B70();
	return 1;
}

//----- (004435D0) --------------------------------------------------------
int nox_cmd_menu_options() {
	if (!nox_common_gameFlags_check_40A5C0(8) && nox_common_gameFlags_check_40A5C0(0x2000))
		nox_xxx_guiServerOptsLoad_457500();
	return 1;
}

//----- (00443600) --------------------------------------------------------
int nox_cmd_menu_vidopt() {
	sub_4ADA40();
	return 1;
}

//----- (00440A50) --------------------------------------------------------
int __cdecl nox_cmd_bind(int a1, char a2, int a3) {
	int v3; // esi

	if (a2 != 3)
		return 0;
	if (nox_wcslen(*(const wchar_t**)(a3 + 4)) >= 0x20)
		return 0;
	v3 = sub_440AC0(*(wchar_t**)(a3 + 4));
	if (v3 == -1 || nox_wcslen(*(const wchar_t**)(a3 + 8)) >= 0x80)
		return 0;
	nox_wcscpy((wchar_t*)getMemAt(0x587000, 76 * v3 + 94516), *(const wchar_t**)(a3 + 8));
	return 1;
}
