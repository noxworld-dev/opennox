#include <math.h>

void nox_xxx_unknown_libname_86_57F634() {}
void nullsub_45() {}
void nullsub_46() {}
void nullsub_47() {}
void nullsub_48() {}
void nullsub_62() {}
void nullsub_65() {}
void nullsub_66() {}
void nullsub_67() {}
void nullsub_69() {}
void nullsub_70() {}

#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME5.h"
#include "GAME5_2.h"
#include "client__shell__wolapi__wolchat.h"
#include "client__shell__wolapi__woldlgs.h"
#include "client__system__parsecmd.h"
#include "common__log.h"
#include "common__object__armrlook.h"
#include "common__object__weaplook.h"
#include "common__system__team.h"

#include "client__gui__servopts__playrlst.h"
#include "client__network__netclint.h"
#include "client__system__ctrlevnt.h"
#include "client__video__draw_common.h"
#include "common__binfile.h"
#include "common__magic__speltree.h"
#include "common__net_list.h"
#include "common__random.h"
#include "common__strman.h"

#include "client__gui__window.h"
#include "client__io__win95__focus.h"
#include "common/fs/nox_fs.h"
#include "input_common.h"
#include "operators.h"

extern uint32_t dword_5d4594_10988;
extern uint32_t dword_5d4594_527656;
extern uint32_t dword_5d4594_3592;
extern uint32_t dword_5d4594_526276;
extern uint32_t dword_5d4594_251712;
extern uint32_t dword_5d4594_251708;
extern uint32_t dword_5d4594_251716;
extern uint32_t dword_5d4594_10984;
extern uint32_t dword_5d4594_2660032;
extern uint32_t dword_5d4594_251720;
extern uint32_t dword_5d4594_3620;
extern uint32_t dword_5d4594_251744;
extern uint32_t dword_5d4594_251556;
extern uint32_t dword_5d4594_4808;
extern uint32_t dword_5d4594_251552;
extern uint32_t dword_5d4594_251564;
extern uint32_t dword_5d4594_528252;
extern uint32_t dword_5d4594_3484;
extern uint32_t dword_5d4594_251560;
extern uint32_t dword_5d4594_251600;
extern uint32_t dword_5d4594_251608;
extern uint32_t dword_5d4594_3632;
extern uint32_t dword_5d4594_3624;
extern uint32_t dword_5d4594_528256;
extern uint32_t dword_5d4594_371692;
extern uint32_t dword_5d4594_251540;
extern uint32_t dword_5d4594_251568;
extern uint32_t dword_5d4594_251572;
extern uint32_t dword_5d4594_10956;
extern uint32_t dword_5d4594_2660652;
extern uint32_t dword_5d4594_4668;
extern uint32_t nox_player_netCode_85319C;
extern unsigned int nox_frame_xxx_2598000;

int nox_enable_audio = 1;

int nox_server_gameSettingsUpdated; // If you define it as 1-byte bool, the game will crash

extern unsigned int nox_gameFPS;

uint32_t* dword_5D4594_251544 = 0;

obj_412ae0_t* byte_5D4594_251584[3] = {0};
int byte_5D4594_251596 = 0;

extern obj_5D4594_2650668_t** ptr_5D4594_2650668;
extern int ptr_5D4594_2650668_cap;

extern table_26792_t table_26792[];
extern int table_26792_cnt;

extern table_27104_t table_27104[];
extern int table_27104_cnt;

extern table_27008_t table_27008[];
extern int table_27008_cnt;

extern table_27168_t table_27168[];
extern int table_27168_cnt;

extern table_28760_t table_28760[];

void* dword_5d4594_251548 = 0;

void sub_41F620(int a1);

//----- (004093E0) --------------------------------------------------------
void nox_xxx_parseRead_4093E0(FILE* a1, char* a2, int a3) {
	int v3;   // edi
	int v4;   // ebx
	char* v5; // esi
	int v6;   // eax

	v3 = 0;
	v4 = 1;
	if (a3 <= 0) {
	LABEL_12:
		a2[a3 - 1] = 0;
		return;
	}
	v5 = a2;
	while (1) {
		nox_binfile_fread_408E40(v5, 1, 1, a1);
		v6 = isspace(*v5);
		if (!v6) {
			break;
		}
		if (!v4) {
			*v5 = 32;
		LABEL_10:
			++v3;
			++v5;
		}
		if (v3 >= a3) {
			goto LABEL_12;
		}
	}
	v4 = 0;
	if (*v5 != 59) {
		goto LABEL_10;
	}
	a2[v3] = 0;
}

//----- (00409470) --------------------------------------------------------
int nox_xxx_parseString_409470(FILE* a1, uint8_t* a2) {
	uint8_t* v2;          // ebx
	int v3;               // ecx
	int v4;               // edi
	int v5;               // ebp
	int v6;               // eax
	uint16_t CharType[2]; // [esp+10h] [ebp-4h]

	v2 = a2;
	v3 = 0;
	*(uint32_t*)CharType = 0;
	v4 = 1;
	do {
		while (1) {
			v5 = v3;
			nox_binfile_fread_408E40((char*)CharType, 1, 1, a1);
			if (nox_binfile_lastErr_409370(a1) == -1) {
				return 0;
			}
			if (*getMemU32Ptr(0x587000, 1668) <= 1) {
				v3 = *(uint32_t*)CharType;
				v6 = isspace(CharType[0]);
			} else {
				v6 = isspace(CharType[0]);
				v3 = *(uint32_t*)CharType;
			}
			if (v6) {
				break;
			}
			v4 = 0;
			if (v3 != '/' || v5 != '/') {
				*v2++ = v3;
			} else {
				nox_binfile_skipLine_409520(a1);
				v2 = a2;
				v3 = *(uint32_t*)CharType;
				v4 = 1;
			}
		}
	} while (v4);
	*v2 = 0;
	return 1;
}

//----- (00409A70) --------------------------------------------------------
int sub_409A70(short a1) {
	int result;        // eax
	unsigned char* v2; // ecx

	result = 0;
	v2 = getMemAt(0x587000, 4704);
	while (*(uint32_t*)v2 != (a1 & 0x17F0)) {
		v2 += 4;
		++result;
		if ((int)v2 >= (int)getMemAt(0x587000, 4728)) {
			return 0;
		}
	}
	return result;
}

//----- (00409AC0) --------------------------------------------------------
unsigned int nox_version_code = 0;
unsigned short nox_client_getVersionBuild_409AC0() { return nox_version_code & 0xffff; }

//----- (00409AA0) --------------------------------------------------------
unsigned char nox_client_getVersionMajor_409AA0() { return (nox_version_code >> 24) & 0xff; }

//----- (00409AB0) --------------------------------------------------------
unsigned char nox_client_getVersionMinor_409AB0() { return (nox_version_code >> 16) & 0xff; }

//----- (00409AD0) --------------------------------------------------------
unsigned int nox_client_getVersionCode_409AD0() { return nox_version_code; }

//----- (00409AE0) --------------------------------------------------------
void nox_client_setVersion_409AE0(unsigned int vers) {
	if (nox_version_code != vers) {
		nox_version_code = vers;
		nox_server_gameSettingsUpdated = 1;
	}
}

//----- (00409B00) --------------------------------------------------------
int nox_xxx_mapCrcGetMB_409B00() { return *getMemU32Ptr(0x5D4594, 3604); }

//----- (00409B10) --------------------------------------------------------
int nox_xxx_mapSetCrcMB_409B10(int a1) {
	int result; // eax

	result = a1;
	if (*getMemU32Ptr(0x5D4594, 3604) != a1) {
		*getMemU32Ptr(0x5D4594, 3604) = a1;
	}
	return result;
}

//----- (00409B30) --------------------------------------------------------
char* nox_server_currentMapGetFilename_409B30() { return (char*)getMemAt(0x5D4594, 2598188); }

//----- (00409B40) --------------------------------------------------------
char* nox_xxx_mapGetMapName_409B40() { return (char*)getMemAt(0x85B3FC, 36); }

//----- (00409B50) --------------------------------------------------------
unsigned int sub_409B50(const char* a1) {
	unsigned int result; // eax

	result = strlen(a1) + 1;
	memcpy(getMemAt(0x5D4594, 3452), a1, result);
	return result;
}

//----- (00409B80) --------------------------------------------------------
char* sub_409B80() { return (char*)getMemAt(0x5D4594, 3452); }

//----- (00409D70) --------------------------------------------------------
char* nox_xxx_gameSetMapPath_409D70(char* a1) {
	char* result;  // eax
	char* v2;      // eax
	signed int v3; // esi

	result = (char*)_strcmpi((const char*)getMemAt(0x5D4594, 2598188), a1);
	if (result) {
		strncpy((char*)getMemAt(0x5D4594, 2598188), a1, 0x50u);
		*getMemU8Ptr(0x5D4594, 2598267) = 0;
		v2 = strrchr(a1, 92);
		if (v2) {
			v3 = strlen(v2 + 1) - 4;
			result = strncpy((char*)getMemAt(0x85B3FC, 36), v2 + 1, v3);
		} else {
			v3 = strlen((const char*)getMemAt(0x5D4594, 2598188)) - 4;
			if (v3 < 0) {
				v3 = 0;
			}
			result = strncpy((char*)getMemAt(0x85B3FC, 36), (const char*)getMemAt(0x5D4594, 2598188), v3);
		}
		*getMemU8Ptr(0x85B3FC, 36 + v3) = 0;
		nox_server_gameSettingsUpdated = 1;
	}
	return result;
}

//----- (00409E40) --------------------------------------------------------
int sub_409E40(int a1) {
	int result; // eax

	result = a1;
	if (dword_5d4594_3484 != a1) {
		dword_5d4594_3484 = a1;
		nox_server_gameSettingsUpdated = 1;
	}
	return result;
}

//----- (00409E60) --------------------------------------------------------
int nox_xxx_getServerSubFlags_409E60() { return dword_5d4594_3484; }

//----- (00409E70) --------------------------------------------------------
int sub_409E70(int a1) {
	int result; // eax

	result = a1 & dword_5d4594_3484;
	if ((a1 & dword_5d4594_3484) != a1) {
		dword_5d4594_3484 |= a1;
		result = nox_common_gameFlags_check_40A5C0(1);
		if (result) {
			if (a1 & 0x2000) {
				result = sub_4D7EA0();
			}
		}
		nox_server_gameSettingsUpdated = 1;
	}
	return result;
}

//----- (00409EC0) --------------------------------------------------------
int sub_409EC0(int a1) {
	int result; // eax

	result = a1;
	if (dword_5d4594_3484 & a1) {
		result = ~a1;
		nox_server_gameSettingsUpdated = 1;
		dword_5d4594_3484 &= ~a1;
	}
	return result;
}

//----- (00409EF0) --------------------------------------------------------
int sub_409EF0(int a1) {
	int result; // eax

	dword_5d4594_3484 ^= a1;
	result = nox_common_gameFlags_check_40A5C0(1);
	if (result) {
		if (a1 & 0x2000) {
			result = dword_5d4594_3484;
			if (result & 0x2000) {
				result = sub_4D7EA0();
			}
		}
	}
	nox_server_gameSettingsUpdated = 1;
	return result;
}

//----- (00409F40) --------------------------------------------------------
int sub_409F40(int a1) {
	int result; // eax

	if (a1 == 0x2000 && nox_common_gameFlags_check_40A5C0(1056)) {
		result = 1;
	} else {
		result = (a1 & dword_5d4594_3484) != 0;
	}
	return result;
}

//----- (00409F80) --------------------------------------------------------
int nox_xxx_servSetPlrLimit_409F80(int a1) {
	int result; // eax

	result = a1;
	if (*getMemU32Ptr(0x5D4594, 3464) != a1) {
		*getMemU32Ptr(0x5D4594, 3464) = a1;
		nox_server_gameSettingsUpdated = 1;
	}
	return result;
}

//----- (00409FA0) --------------------------------------------------------
int nox_xxx_servGetPlrLimit_409FA0() { return *getMemU32Ptr(0x5D4594, 3464); }

//----- (0040A020) --------------------------------------------------------
short nox_xxx_servGamedataGet_40A020(short a1) { return *getMemU16Ptr(0x5D4594, 3488 + 2 * sub_409A70(a1)); }

//----- (0040A180) --------------------------------------------------------
unsigned char sub_40A180(short a1) { return getMemByte(0x5D4594, 3500 + sub_409A70(a1)); }

//----- (0040A1A0) --------------------------------------------------------
int sub_40A1A0() {
	short v0; // ax

	v0 = nox_common_gameFlags_getVal_40A5B0();
	return (sub_40A180(v0) || dword_5d4594_3592) && *getMemU32Ptr(0x587000, 4660) &&
		   (unsigned long long)nox_platform_get_ticks() > *getMemU64Ptr(0x5D4594, 3468);
}

//----- (0040A1F0) --------------------------------------------------------
int sub_40A1F0(int a1) {
	int result; // eax

	*getMemU32Ptr(0x587000, 4660) = a1;
	result = nox_common_gameFlags_check_40A5C0(1);
	if (result) {
		result = nox_xxx_netTimerStatus_4D8F50(159, a1);
	}
	return result;
}

//----- (0040A220) --------------------------------------------------------
int sub_40A220() { return *getMemU32Ptr(0x587000, 4660); }

//----- (0040A230) --------------------------------------------------------
int sub_40A230() { return *getMemU32Ptr(0x5D4594, 3468) - (unsigned long long)nox_platform_get_ticks(); }

//----- (0040A250) --------------------------------------------------------
long long sub_40A250() {
	short v0;         // ax
	int v1;           // esi
	long long v2;     // kr00_8
	long long result; // rax

	v0 = nox_common_gameFlags_getVal_40A5B0();
	v1 = sub_409A70(v0);
	v2 = nox_platform_get_ticks();
	result = 60000 * getMemByte(0x5D4594, 3500 + v1);
	*getMemU64Ptr(0x5D4594, 3468) = result + v2;
	return result;
}

//----- (0040A2A0) --------------------------------------------------------
const char* nox_xxx_servStartCountdown_40A2A0(int a1, const char* a2) {
	const char* result; // eax

	*getMemU64Ptr(0x5D4594, 3468) = 1000 * a1 + nox_platform_get_ticks();
	sub_40A1F0(1);
	result = a2;
	if (a2) {
		result = (const char*)nox_xxx_netPrintLineToAll_4DA390(a2);
	}
	dword_5d4594_3592 = 1;
	return result;
}

//----- (0040A300) --------------------------------------------------------
int sub_40A300() { return dword_5d4594_3592; }

//----- (0040A310) --------------------------------------------------------
long long sub_40A310(int a1) {
	long long v1;     // kr00_8
	long long result; // rax

	v1 = nox_platform_get_ticks();
	result = a1;
	*getMemU64Ptr(0x5D4594, 3468) = a1 + v1;
	return result;
}

//----- (0040A340) --------------------------------------------------------
void nox_xxx_set3512_40A340(int a1) { *getMemU32Ptr(0x5D4594, 3512) = a1; }

//----- (0040A350) --------------------------------------------------------
int nox_xxx_get3512_40A350() { return *getMemU32Ptr(0x5D4594, 3512); }

//----- (0040A3C0) --------------------------------------------------------
unsigned int sub_40A3C0(unsigned int a1) {
	unsigned int result; // eax

	result = a1;
	if (a1 > 0x800 && a1 < 0x8000) {
		*getMemU32Ptr(0x587000, 4652) = a1;
	}
	return result;
}

//----- (0040A410) --------------------------------------------------------
int nox_xxx_setClientNetPort_40A410(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 3528) = a1;
	return result;
}

//----- (0040A420) --------------------------------------------------------
int nox_client_getClientPort_40A420() { return *getMemU32Ptr(0x5D4594, 3528); }

//----- (0040A440) --------------------------------------------------------
char* nox_xxx_gameSetServername_40A440(char* a1) {
	char* result; // eax
	char v2[16];  // [esp+0h] [ebp-10h]

	result = a1;
	if (a1) {
		strncpy(v2, a1, 0xFu);
		v2[15] = 0;
		result = (char*)_strcmpi((const char*)getMemAt(0x5D4594, 1324), v2);
		if (result) {
			result = strncpy((char*)getMemAt(0x5D4594, 1324), v2, 0xFu);
			*getMemU8Ptr(0x5D4594, 1339) = 0;
			nox_server_gameSettingsUpdated = 1;
		}
	} else {
		*getMemU8Ptr(0x5D4594, 1324) = 0;
		nox_server_gameSettingsUpdated = 1;
	}
	return result;
}

//----- (0040A4C0) --------------------------------------------------------
char* nox_xxx_serverOptionsGetServername_40A4C0() { return (char*)getMemAt(0x5D4594, 1324); }

//----- (0040A5E0) --------------------------------------------------------
int nox_xxx_ruleSetNoRespawn_40A5E0(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 3584) = a1;
	return result;
}

//----- (0040A5F0) --------------------------------------------------------
int nox_server_doPlayersAutoRespawn_40A5F0() {
	return !nox_common_gameFlags_check_40A5C0(4096) ? *getMemU32Ptr(0x5D4594, 3584) : 0;
}

//----- (0040A610) --------------------------------------------------------
wchar_t* nox_xxx_sysopSetPass_40A610(wchar_t* a1) { return nox_wcscpy((wchar_t*)getMemAt(0x5D4594, 3540), a1); }

//----- (0040A630) --------------------------------------------------------
wchar_t* nox_xxx_sysopGetPass_40A630() { return (wchar_t*)getMemAt(0x5D4594, 3540); }

//----- (0040A670) --------------------------------------------------------
void nox_server_gameSettingsUpdated_40A670() { nox_server_gameSettingsUpdated = 1; }

//----- (0040A680) --------------------------------------------------------
int nox_server_gameDoSwitchMap_40A680() { return nox_server_gameSettingsUpdated; }

//----- (0040A690) --------------------------------------------------------
void nox_server_gameUnsetMapLoad_40A690() { nox_server_gameSettingsUpdated = 0; }

//----- (0040A6A0) --------------------------------------------------------
int sub_40A6A0(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 3588) = a1;
	return result;
}

//----- (0040A6B0) --------------------------------------------------------
int sub_40A6B0() { return *getMemU32Ptr(0x5D4594, 3588); }

//----- (0040A6C0) --------------------------------------------------------
int nox_xxx_rateGet_40A6C0() { return *getMemU32Ptr(0x587000, 4728); }

//----- (0040A6D0) --------------------------------------------------------
int nox_xxx_rateUpdate_40A6D0(int a1) {
	int result; // eax

	result = *getMemU32Ptr(0x587000, 4728);
	if (a1 != *getMemU32Ptr(0x587000, 4728)) {
		result = nox_common_gameFlags_check_40A5C0(0x20000);
		if (result == 1) {
			result = nox_xxx_netNotifyRate_4D7F10(159);
		}
	}
	*getMemU32Ptr(0x587000, 4728) = a1;
	return result;
}

//----- (0040A710) --------------------------------------------------------
int sub_40A710(int a1) {
	int v1;            // ecx
	unsigned char* v2; // eax

	v1 = 0;
	v2 = getMemAt(0x587000, 4664);
	while (*(uint32_t*)v2 != a1) {
		v2 += 8;
		++v1;
		if ((int)v2 >= (int)getMemAt(0x587000, 4704)) {
			return 1;
		}
	}
	return *getMemU32Ptr(0x587000, 4668 + 8 * v1);
}

//----- (0040A740) --------------------------------------------------------
int sub_40A740() {
	char* v0; // esi

	v0 = sub_4165B0();
	return nox_common_gameFlags_check_40A5C0(128) && v0[53] < 0;
}

//----- (0040A770) --------------------------------------------------------
int sub_40A770() {
	int v0;   // edi
	char* v1; // esi
	int v2;   // eax
	int v3;   // ecx
	char* i;  // eax

	v0 = 0;
	if (!nox_xxx_CheckGameplayFlags_417DA0(4)) {
		for (i = nox_common_playerInfoGetFirst_416EA0(); i; i = nox_common_playerInfoGetNext_416EE0((int)i)) {
			if (!(i[3680] & 1) &&
				(i[2064] != 31 || !nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING))) {
				++v0;
			}
		}
		return v0;
	}
	v1 = nox_server_teamFirst_418B10();
	if (!v1) {
		return v0;
	}
	do {
		v2 = nox_xxx_getFirstPlayerUnit_4DA7C0();
		if (v2) {
			while (1) {
				v3 = *(uint32_t*)(*(uint32_t*)(v2 + 748) + 276);
				if (!(*(uint8_t*)(v3 + 3680) & 1) &&
					(*(uint8_t*)(v3 + 2064) != 31 ||
					 !nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING))) {
					break;
				}
				v2 = nox_xxx_getNextPlayerUnit_4DA7F0(v2);
				if (!v2) {
					goto LABEL_10;
				}
			}
			++v0;
		}
	LABEL_10:
		v1 = nox_server_teamNext_418B60((int)v1);
	} while (v1);
	return v0;
}

//----- (0040A830) --------------------------------------------------------
int nox_xxx_countNonEliminatedPlayersInTeam_40A830(int a1) {
	int v1; // edi
	int v2; // esi
	int v3; // eax

	v1 = 0;
	v2 = nox_xxx_getFirstPlayerUnit_4DA7C0();
	if (!v2) {
		return 0;
	}
	do {
		if (nox_xxx_teamCompare2_419180(v2 + 48, *(uint8_t*)(a1 + 57))) {
			v3 = *(uint32_t*)(*(uint32_t*)(v2 + 748) + 276);
			if (!(*(uint8_t*)(v3 + 3680) & 1) &&
				(*(uint8_t*)(v3 + 2064) != 31 ||
				 !nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING))) {
				++v1;
			}
		}
		v2 = nox_xxx_getNextPlayerUnit_4DA7F0(v2);
	} while (v2);
	return v1;
}

//----- (0040A8A0) --------------------------------------------------------
int nox_xxx_gamePlayIsAnyPlayers_40A8A0() {
	int v0;     // ebx
	char* v1;   // edi
	int v2;     // esi
	int v3;     // eax
	int result; // eax
	char* i;    // eax
	int v6;     // ecx

	v0 = 0;
	if (!nox_xxx_CheckGameplayFlags_417DA0(4)) {
		for (i = nox_common_playerInfoGetFirst_416EA0(); i; i = nox_common_playerInfoGetNext_416EE0((int)i)) {
			if (*((uint32_t*)i + 514)) {
				v6 = *((uint32_t*)i + 920);
				if (!(v6 & 1) || v6 & 0x20) {
					++v0;
				}
			}
		}
		goto LABEL_18;
	}
	v1 = nox_server_teamFirst_418B10();
	if (!v1) {
	LABEL_18:
		result = v0 < 1;
		LOBYTE(result) = v0 > 1;
		return result;
	}
	do {
		v2 = nox_xxx_getFirstPlayerUnit_4DA7C0();
		if (v2) {
			while (1) {
				if (nox_xxx_teamCompare2_419180(v2 + 48, v1[57])) {
					v3 = *(uint32_t*)(*(uint32_t*)(*(uint32_t*)(v2 + 748) + 276) + 3680);
					if (!(v3 & 1) || v3 & 0x20) {
						break;
					}
				}
				v2 = nox_xxx_getNextPlayerUnit_4DA7F0(v2);
				if (!v2) {
					goto LABEL_10;
				}
			}
			++v0;
		}
	LABEL_10:
		v1 = nox_server_teamNext_418B60((int)v1);
	} while (v1);
	return v0 > 1;
}

//----- (0040A970) --------------------------------------------------------
void sub_40A970() {
	char* i;  // esi
	int v1;   // eax
	float v3; // [esp+0h] [ebp-8h]
	float v4; // [esp+0h] [ebp-8h]

	*getMemU32Ptr(0x5D4594, 3520) = nox_frame_xxx_2598000;
	*getMemU32Ptr(0x5D4594, 3536) = 0;
	v3 = nox_xxx_gamedataGetFloat_419D40("SuddenDeathPlayerThreshold");
	*getMemU32Ptr(0x5D4594, 3476) = nox_float2int(v3);
	v4 = nox_xxx_gamedataGetFloat_419D40("SuddenDeathLifeTime");
	*getMemU32Ptr(0x5D4594, 1392) = nox_float2int(v4);
	for (i = nox_common_playerInfoGetFirst_416EA0(); i; i = nox_common_playerInfoGetNext_416EE0((int)i)) {
		v1 = *((uint32_t*)i + 920);
		if (v1 & 0x100) {
			nox_xxx_playerUnsetStatus_417530((int)i, 256);
		}
	}
	nox_common_gameFlags_unset_40A540(0x4000000);
}

//----- (0040AA00) --------------------------------------------------------
int sub_40AA00() { return 20 * nox_gameFPS < (unsigned int)(nox_frame_xxx_2598000 - *getMemU32Ptr(0x5D4594, 3520)); }

//----- (0040AA20) --------------------------------------------------------
int sub_40AA20() { return *getMemU32Ptr(0x5D4594, 3536); }

//----- (0040AA30) --------------------------------------------------------
int sub_40AA30(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 3536) = a1;
	return result;
}

//----- (0040AA40) --------------------------------------------------------
int sub_40AA40() { return *getMemU32Ptr(0x5D4594, 3476); }

//----- (0040AA60) --------------------------------------------------------
int sub_40AA60(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 3508) = a1;
	return result;
}

//----- (0040AA70) --------------------------------------------------------
int sub_40AA70(nox_playerInfo* pl) {
	int a1 = pl;
	char* v1;   // edi
	int result; // eax
	int v3;     // eax
	int v4;     // esi
	int v5;     // ebx
	char* v6;   // eax

	v1 = sub_416640();
	if (!a1) {
		goto LABEL_31;
	}
	if (nox_common_gameFlags_check_40A5C0(4096)) {
		return sub_40A770() < 6;
	}
	v3 = *(uint32_t*)(a1 + 3680);
	if (v3 & 0x100 && !*getMemU32Ptr(0x5D4594, 3508)) {
		return 0;
	}
	if (!sub_40A740() && !nox_common_gameFlags_check_40A5C0(0x8000)) {
		goto LABEL_31;
	}
	result = *(uint32_t*)(a1 + 2068);
	if (!result) {
		return result;
	}
	if (nox_server_teamByXxx_418AE0(*(uint32_t*)(a1 + 2068))) {
		goto LABEL_31;
	}
	v4 = (unsigned char)v1[52];
	if ((nox_common_gameFlags_check_40A5C0(96) ||
		 nox_common_gameFlags_check_40A5C0(16) && nox_xxx_CheckGameplayFlags_417DA0(4)) &&
		v4 > 2) {
		v4 = 2;
	}
	if ((unsigned char)sub_417DE0() >= v4) {
		return 0;
	}
	if (nox_common_gameFlags_check_40A5C0(96)) {
		v5 = (unsigned char)sub_417DE0();
		if (v5 >= sub_417DC0()) {
			return 0;
		}
	}
LABEL_31:
	if (nox_common_gameFlags_check_40A5C0(128)) {
		goto LABEL_26;
	}
	if (!nox_common_gameFlags_check_40A5C0(1024)) {
		goto LABEL_26;
	}
	v6 = nox_common_playerInfoGetFirst_416EA0();
	if (!v6) {
		goto LABEL_26;
	}
	while (*((int*)v6 + 535) <= 0) {
		v6 = nox_common_playerInfoGetNext_416EE0((int)v6);
		if (!v6) {
			goto LABEL_26;
		}
	}
	if (sub_40AA00()) {
		result = 0;
	} else {
	LABEL_26:
		result = 1;
	}
	return result;
}

//----- (0040AF90) --------------------------------------------------------
int nox_xxx_savePlayerMB_41C8F0(char* a1, unsigned int a2);
void nox_xxx_soloGameEscMenuCallback_40AF90(int a1, int a2, char a3, int a4, uint8_t* a5, unsigned int a6) {
	char* v6;            // eax
	char* v7;            // edi
	char* v8;            // eax
	int v9;              // eax
	char FileName[1024]; // [esp+4h] [ebp-400h]

	switch (a3) {
	case 1:
		sub_446520(1, a5, a6);
		break;
	case 2:
		nox_xxx_savePlayerMB_41C8F0(a5, a6);
		if (nox_common_gameFlags_check_40A5C0(4096)) {
			if (sub_4460B0()) {
				sub_446140();
			} else {
				sub_41D170();
			}
		} else if (sub_446030() && sub_446090()) {
			nox_game_exit_xxx2();
			sub_446060();
		}
		break;
	case 3:
		v6 = nox_fs_root();
		nox_sprintf(FileName, "%s\\Save\\_temp_.dat", v6);
		if (nox_xxx_SavePlayerDataFromClient_41CD70(FileName, a5, a6)) {
			if (nox_xxx_isQuest_4D6F50() && a1 == 31) {
				sub_4DCEE0(FileName);
			} else {
				v7 = nox_xxx_cliPlrInfoLoadFromFile_41A2E0(FileName, a1);
				if (nox_common_gameFlags_check_40A5C0(4096)) {
					if (v7) {
						v8 = nox_common_playerInfoFromNum_417090(a1);
						if (v8) {
							v9 = *((uint32_t*)v8 + 514);
							if (v9) {
								*(uint32_t*)(*(uint32_t*)(v9 + 748) + 552) = 0;
							}
						}
					} else {
						nox_xxx_playerCallDisconnect_4DEAB0(a1, 4);
					}
				}
				nox_fs_remove(FileName);
			}
		} else if (nox_common_gameFlags_check_40A5C0(4096) && a1 != 31) {
			nox_xxx_playerCallDisconnect_4DEAB0(a1, 4);
		}
		break;
	default:
		return;
	}
}

//----- (0040B170) --------------------------------------------------------
int sub_40B170(int a1) {
	int v1;     // ecx
	int result; // eax

	v1 = a1;
	if (a1 >= 0) {
		if (a1 > 256) {
			v1 = 256;
		}
	} else {
		v1 = 16;
	}
	dword_5d4594_3624 = v1;
	dword_5d4594_3620 = calloc(v1, 168);
	result = dword_5d4594_3624;
	LOBYTE(a1) = 0;
	if (dword_5d4594_3624 > 0) {
		LOBYTE(result) = 0;
		do {
			sub_40B1F0(result);
			LOBYTE(a1) = a1 + 1;
			result = a1;
		} while ((int)(unsigned char)a1 < *(int*)&dword_5d4594_3624);
	}
	return result;
}

//----- (0040B1F0) --------------------------------------------------------
char* sub_40B1F0(unsigned char a1) {
	char* result; // eax

	result = (char*)(dword_5d4594_3620 + 168 * a1);
	result[4] = 0;
	result[5] = a1;
	*((uint32_t*)result + 4) = 0;
	*((uint32_t*)result + 3) = 0;
	result[24] = 0;
	*((uint32_t*)result + 40) = 0;
	*((uint32_t*)result + 41) = 0;
	*((uint32_t*)result + 5) = 0;
	*((uint32_t*)result + 38) = 0;
	*((uint32_t*)result + 2) = 1;
	*((uint32_t*)result + 39) = 0;
	return result;
}

//----- (0040B250) --------------------------------------------------------
void sub_40B250(int a1, unsigned char a2, unsigned short a3, const void* a4, size_t a5) {
	int v5;              // ebp
	int v6;              // eax
	uint32_t* v7;        // ebx
	void* v8;            // eax
	int v9;              // eax
	int v10;             // eax
	unsigned short* v11; // ebx
	unsigned short* v12; // eax
	int v13;             // edx
	int v14;             // eax
	int v15;             // eax
	int v16;             // eax
	int v17;             // ecx
	int v18;             // edx
	size_t v19;          // [esp+24h] [ebp+14h]

	if (!a4) {
		return;
	}
	if (!a5) {
		return;
	}
	if ((int)a2 >= *(int*)&dword_5d4594_3624) {
		return;
	}
	v5 = dword_5d4594_3620 + 168 * a2;
	if (!*(uint32_t*)(v5 + 16)) {
		return;
	}
	*(uint32_t*)(v5 + 156) = nox_frame_xxx_2598000;
	if (a3 == *(uint32_t*)(v5 + 8)) {
		memcpy((void*)(*(uint32_t*)(v5 + 12) + *(uint32_t*)(v5 + 20)), a4, a5);
		v6 = *(uint32_t*)(v5 + 8) + 1;
		*(uint32_t*)(v5 + 12) += a5;
		*(uint32_t*)(v5 + 8) = v6;
	} else {
		v7 = calloc(1, 0x1Cu);
		if (v7) {
			v8 = calloc(1, a5);
			v7[1] = v8;
			if (v8) {
				memcpy(v8, a4, a5);
				*(uint16_t*)v7 = a3;
				*((uint16_t*)v7 + 4) = a5;
				v7[5] = 0;
				v7[6] = *(uint32_t*)(v5 + 164);
				v9 = *(uint32_t*)(v5 + 164);
				if (v9) {
					*(uint32_t*)(v9 + 20) = v7;
				}
				v10 = *(uint32_t*)(v5 + 160);
				*(uint32_t*)(v5 + 164) = v7;
				if (!v10) {
					*(uint32_t*)(v5 + 160) = v7;
				}
			}
		}
	}
	v11 = *(unsigned short**)(v5 + 160);
	if (v11) {
		do {
			v12 = (unsigned short*)*((uint32_t*)v11 + 5);
			v19 = *((uint32_t*)v11 + 5);
			if (*(uint32_t*)(v5 + 8) == *v11) {
				memcpy((void*)(*(uint32_t*)(v5 + 12) + *(uint32_t*)(v5 + 20)), *((const void**)v11 + 1), (short)v11[4]);
				v13 = *(uint32_t*)(v5 + 8) + 1;
				*(uint32_t*)(v5 + 12) += (short)v11[4];
				*(uint32_t*)(v5 + 8) = v13;
				v14 = *((uint32_t*)v11 + 6);
				if (v14) {
					*(uint32_t*)(v14 + 20) = *((uint32_t*)v11 + 5);
				} else {
					*(uint32_t*)(v5 + 160) = *((uint32_t*)v11 + 5);
				}
				v15 = *((uint32_t*)v11 + 5);
				if (v15) {
					*(uint32_t*)(v15 + 24) = *((uint32_t*)v11 + 6);
				} else {
					*(uint32_t*)(v5 + 164) = *((uint32_t*)v11 + 6);
				}
				free(*((void**)v11 + 1));
				free(v11);
				v12 = (unsigned short*)v19;
			}
			v11 = v12;
		} while (v12);
	}
	v17 = *(uint32_t*)(v5 + 16);
	v16 = *(uint32_t*)(v5 + 12);
	*(float*)(v5 + 152) = (double)*(unsigned int*)(v5 + 12) / (double)v17 * 100.0;
	if (v16 == v17) {
		nox_xxx_netXfer_40B4B0(*(uint32_t*)v5, *(uint8_t*)(v5 + 5));
		v18 = *(uint32_t*)(v5 + 20);
		LOBYTE(v18) = *(uint8_t*)(v5 + 5);
		nox_xxx_soloGameEscMenuCallback_40AF90(a1 - 1, v18, *(uint8_t*)(v5 + 4), v5 + 24, *(uint8_t**)(v5 + 20),
											   *(uint32_t*)(v5 + 16));
		if (getMemByte(0x5D4594, 3628)) {
			--*getMemU8Ptr(0x5D4594, 3628);
		}
		free(*(void**)(v5 + 20));
		sub_40B4E0(a2);
		sub_40B1F0(a2);
	}
}

//----- (0040B4B0) --------------------------------------------------------
int nox_xxx_netXfer_40B4B0(unsigned int a1, char a2) {
	char v4[3]; // [esp+0h] [ebp-4h]

	v4[0] = -62;
	v4[1] = 4;
	v4[2] = a2;
	return nox_xxx_netSendSock_552640(a1, v4, 3, NOX_NET_SEND_NO_LOCK | NOX_NET_SEND_FLAG2);
}

//----- (0040B4E0) --------------------------------------------------------
int sub_40B4E0(unsigned char a1) {
	int result; // eax
	int v2;     // esi
	int v3;     // edi

	result = 21 * a1;
	v2 = *(uint32_t*)(dword_5d4594_3620 + 168 * a1 + 160);
	if (v2) {
		do {
			v3 = *(uint32_t*)(v2 + 20);
			free(*(void**)(v2 + 4));
			free((void*)v2);
			v2 = v3;
		} while (v3);
	}
	return result;
}

//----- (0040B530) --------------------------------------------------------
char* sub_40B530(unsigned char a1, char a2) {
	char* result; // eax

	result = (char*)(dword_5d4594_3620 + 168 * a1);
	if (*((uint32_t*)result + 4)) {
		nox_xxx_neXfer_40B590(*(uint32_t*)result, result[5], a2);
		if (getMemByte(0x5D4594, 3628)) {
			--*getMemU8Ptr(0x5D4594, 3628);
		}
		sub_40B4E0(a1);
		result = sub_40B1F0(a1);
	}
	return result;
}

//----- (0040B590) --------------------------------------------------------
int nox_xxx_neXfer_40B590(unsigned int a1, char a2, char a3) {
	char v4[4]; // [esp+0h] [ebp-4h]

	v4[2] = a2;
	v4[0] = -62;
	v4[1] = 6;
	v4[3] = a3;
	return nox_xxx_netSendSock_552640(a1, v4, 4, NOX_NET_SEND_NO_LOCK | NOX_NET_SEND_FLAG2);
}

//----- (0040B5D0) --------------------------------------------------------
int sub_40B5D0(unsigned int a1, char a2, const char* a3, size_t a4, char a5) {
	size_t v5; // esi
	char* v6;  // eax
	char* v7;  // ebx
	int v9;    // [esp+8h] [ebp-4h]

	v5 = a4;
	if (!a4) {
		return 0;
	}
	v6 = sub_40B6D0(&v9);
	v7 = v6;
	if (!v6) {
		return 0;
	}
	*(uint32_t*)v6 = a1;
	v6[4] = a2;
	if (*a3) {
		strcpy(v6 + 24, a3);
		v5 = a4;
	}
	*((uint32_t*)v6 + 4) = v5;
	v6[5] = v9;
	*((uint32_t*)v6 + 5) = calloc(v5, 1u);
	*((uint32_t*)v7 + 39) = nox_frame_xxx_2598000;
	++*getMemU8Ptr(0x5D4594, 3628);
	sub_40B690(a1, v9, a5);
	return 1;
}

//----- (0040B690) --------------------------------------------------------
int sub_40B690(unsigned int a1, char a2, char a3) {
	char v4[4]; // [esp+0h] [ebp-4h]

	v4[2] = a2;
	v4[0] = -62;
	v4[1] = 1;
	v4[3] = a3;
	return nox_xxx_netSendSock_552640(a1, v4, 4, NOX_NET_SEND_NO_LOCK | NOX_NET_SEND_FLAG2);
}

//----- (0040B6D0) --------------------------------------------------------
char* sub_40B6D0(uint8_t* a1) {
	int v1;       // eax
	uint32_t* v2; // ecx
	char* result; // eax

	v1 = 0;
	if (*(int*)&dword_5d4594_3624 <= 0) {
	LABEL_5:
		result = 0;
		*a1 = 0;
	} else {
		v2 = (uint32_t*)(dword_5d4594_3620 + 16);
		while (*v2) {
			++v1;
			v2 += 42;
			if (v1 >= *(int*)&dword_5d4594_3624) {
				goto LABEL_5;
			}
		}
		*a1 = v1;
		result = (char*)(dword_5d4594_3620 + 168 * v1);
	}
	return result;
}

//----- (0040B720) --------------------------------------------------------
char* sub_40B720(int a1, unsigned char a2) {
	sub_40B4E0(a2);
	return sub_40B1F0(a2);
}

//----- (0040B740) --------------------------------------------------------
void sub_40B740() {
	unsigned char v0; // al
	unsigned char v2; // [esp+0h] [ebp-4h]

	v2 = 0;
	if (dword_5d4594_3624 > 0) {
		v0 = 0;
		do {
			sub_40B4E0(v0);
			v0 = ++v2;
		} while ((int)v2 < *(int*)&dword_5d4594_3624);
	}
	free(*(void**)&dword_5d4594_3620);
}

//----- (0040B790) --------------------------------------------------------
int sub_40B790() {
	int result;       // eax
	unsigned char v1; // dl
	int v2;           // ecx
	int v3;           // eax
	unsigned char v4; // [esp+0h] [ebp-4h]

	result = dword_5d4594_3624;
	v4 = 0;
	if (dword_5d4594_3624 > 0) {
		v1 = 0;
		v2 = 0;
		do {
			v3 = dword_5d4594_3620 + 168 * v2;
			if (*(uint32_t*)(v3 + 16)) {
				if (nox_frame_xxx_2598000 > (unsigned int)(*(uint32_t*)(v3 + 156) + 900)) {
					sub_40B530(v1, 3);
				}
			}
			result = dword_5d4594_3624;
			v1 = ++v4;
			v2 = v4;
		} while ((int)v4 < *(int*)&dword_5d4594_3624);
	}
	return result;
}

//----- (0040B810) --------------------------------------------------------
void sub_40B810(int a1, int a2, int a3) {
	nox_xxx_soloGameEscMenuCallback_40AF90(31, 0, a1, (int)getMemAt(0x5D4594, 4664), (uint8_t*)a2, a3);
	sub_40B850(0, a1);
}

//----- (0040B890) --------------------------------------------------------
void* sub_40B890(int a1) {
	void* result; // eax
	int v2;       // esi
	int v3;       // edi

	if (a1 >= 0) {
		*getMemU16Ptr(0x5D4594, 4660) = 256;
		if (a1 <= 256) {
			*getMemU16Ptr(0x5D4594, 4660) = a1;
		}
	} else {
		*getMemU16Ptr(0x5D4594, 4660) = 16;
	}
	result = calloc(*getMemU16Ptr(0x5D4594, 4660), 160);
	v2 = 0;
	dword_5d4594_3632 = result;
	if (*getMemU16Ptr(0x5D4594, 4660)) {
		v3 = 0;
		do {
			sub_40B930(v3 + dword_5d4594_3632);
			++v2;
			result = (void*)*getMemU16Ptr(0x5D4594, 4660);
			v3 += 160;
		} while (v2 < *getMemU16Ptr(0x5D4594, 4660));
		*getMemU16Ptr(0x5D4594, 4662) = 0;
	} else {
		*getMemU16Ptr(0x5D4594, 4662) = 0;
	}
	return result;
}

//----- (0040B930) --------------------------------------------------------
int sub_40B930(int a1) {
	int result; // eax

	result = a1;
	*(uint32_t*)a1 = 0;
	*(uint8_t*)(a1 + 4) = 0;
	*(uint16_t*)(a1 + 6) = 0;
	*(uint32_t*)(a1 + 8) = 0;
	*(uint32_t*)(a1 + 12) = 1;
	*(uint16_t*)(a1 + 20) = 0;
	*(uint8_t*)(a1 + 22) = 0;
	*(uint8_t*)(a1 + 23) = 0;
	*(uint32_t*)(a1 + 16) = 0;
	*(uint32_t*)(a1 + 152) = 0;
	*(uint32_t*)(a1 + 156) = 0;
	return result;
}

//----- (0040B970) --------------------------------------------------------
void sub_40B970() {
	int v0; // ebp
	int v1; // edi
	int v2; // esi
	int v3; // ebx
	int v4; // eax
	int v5; // ecx
	int v6; // eax
	int v7; // [esp+4h] [ebp-4h]

	v0 = 0;
	if (*getMemU16Ptr(0x5D4594, 4662)) {
		v7 = 0;
		if (*getMemU16Ptr(0x5D4594, 4660) > 0u) {
			do {
				v1 = dword_5d4594_3632 + v0;
				if (*(uint16_t*)(dword_5d4594_3632 + v0 + 6) == 2) {
					v2 = *(uint32_t*)(v1 + 152);
					v3 = 0;
					if (v2) {
						while (v3 < 2) {
							v4 = *(uint32_t*)(v2 + 12);
							if (v4) {
								v5 = nox_frame_xxx_2598000;
								if ((unsigned int)(v4 + 90) < nox_frame_xxx_2598000) {
									if (*(uint16_t*)(v2 + 16) >= 20) {
										if (*(uint16_t*)(v1 + 6) == 2) {
											LOBYTE(v5) = *(uint8_t*)(v1 + 4);
											sub_40BB20(*(uint32_t*)v1, v5, 2);
											break;
										}
									} else {
										sub_40BA90(*(uint32_t*)v1, *(uint8_t*)(v1 + 4), *(uint16_t*)v2,
												   *(uint16_t*)(v2 + 8), *(const void**)(v2 + 4));
										v6 = nox_frame_xxx_2598000;
										++*(uint16_t*)(v2 + 16);
										*(uint32_t*)(v2 + 12) = v6;
									}
								}
							} else {
								sub_40BA90(*(uint32_t*)v1, *(uint8_t*)(v1 + 4), *(uint16_t*)v2, *(uint16_t*)(v2 + 8),
										   *(const void**)(v2 + 4));
								*(uint32_t*)(v2 + 12) = nox_frame_xxx_2598000;
								++*(uint32_t*)(v1 + 12);
							}
							v2 = *(uint32_t*)(v2 + 20);
							++v3;
							if (!v2) {
								break;
							}
						}
					}
				}
				v0 += 160;
				++v7;
			} while (v7 < *getMemU16Ptr(0x5D4594, 4660));
		}
	}
}

//----- (0040BA90) --------------------------------------------------------
int sub_40BA90(unsigned int a1, char a2, short a3, short a4, const void* a5) {
	int v6; // [esp+8h] [ebp-8h]
	int v7; // [esp+Ch] [ebp-4h]

	BYTE2(v6) = a2;
	HIWORD(v7) = a4;
	LOWORD(v7) = a3;
	LOWORD(v6) = 706;
	*getMemU32Ptr(0x5D4594, 3640) = v7;
	*getMemU32Ptr(0x5D4594, 3636) = v6;
	memcpy(getMemAt(0x5D4594, 3644), a5, a4);
	nox_xxx_netSendSock_552640(a1, getMemAt(0x5D4594, 3636), a4 + 8, 0);
	return nox_xxx_netSendReadPacket_5528B0(a1, 1);
}
// 40BACC: variable 'v6' is possibly undefined

//----- (0040BB20) --------------------------------------------------------
char* sub_40BB20(unsigned int a1, int a2, char a3) {
	char v3;      // bl
	char* result; // eax
	char* v5;     // edi
	int v6;       // esi
	int v7;       // ebx

	v3 = a2;
	result = sub_40BC10(a1, a2);
	v5 = result;
	if (result) {
		LOWORD(a2) = 1474;
		BYTE2(a2) = v3;
		HIBYTE(a2) = a3;
		nox_xxx_netSendSock_552640(a1, &a2, 4, NOX_NET_SEND_NO_LOCK | NOX_NET_SEND_FLAG2);
		sub_40BBC0(*(uint32_t*)v5, v5[22]);
		if (*getMemU16Ptr(0x5D4594, 4662)) {
			--*getMemU16Ptr(0x5D4594, 4662);
		}
		v6 = *((uint32_t*)v5 + 38);
		if (v6) {
			do {
				v7 = *(uint32_t*)(v6 + 20);
				free(*(void**)(v6 + 4));
				free((void*)v6);
				v6 = v7;
			} while (v7);
		}
		result = (char*)sub_40B930((int)v5);
	}
	return result;
}

//----- (0040BC10) --------------------------------------------------------
char* sub_40BC10(int a1, char a2) {
	int v2; // ecx
	int i;  // eax

	v2 = 0;
	if ((int)*getMemU16Ptr(0x5D4594, 4660) <= 0) {
		return 0;
	}
	for (i = dword_5d4594_3632; *(uint32_t*)i != a1 || *(uint8_t*)(i + 4) != a2; i += 160) {
		if (++v2 >= *getMemU16Ptr(0x5D4594, 4660)) {
			return 0;
		}
	}
	return (char*)(dword_5d4594_3632 + 160 * v2);
}

//----- (0040BC60) --------------------------------------------------------
int sub_40BC60(int a1, int a2, const char* a3, void* a4, int a5, int a6) {
	char* v6;         // ebx
	int v7;           // esi
	int v8;           // eax
	uint16_t* v10;    // eax
	uint16_t* v11;    // ebp
	short v12;        // ax
	char* v13;        // eax
	unsigned int v14; // ecx
	int v15;          // eax
	int v16;          // edx
	int v17;          // esi
	int v18;          // eax
	unsigned int v19; // [esp+10h] [ebp-Ch]
	int v20;          // [esp+18h] [ebp-4h]
	int v21;          // [esp+20h] [ebp+4h]
	int v22;          // [esp+2Ch] [ebp+10h]
	char* v23;        // [esp+34h] [ebp+18h]

	v6 = sub_40BF10(&v20);
	if (!v6) {
		return 0;
	}
	v7 = a5;
	if (!a5 || !a4) {
		return 0;
	}
	if (!nox_common_gameFlags_check_40A5C0(1)) {
		v8 = nox_xxx_netGet_43C750();
		goto LABEL_12;
	}
	if (!nox_common_gameFlags_check_40A5C0(2)) {
		return 0;
	}
	if (!a6) {
		sub_40B810(a2, a4, a5);
		return 1;
	}
	if (a1 == 31) {
		sub_40B810(a2, a4, a5);
		return 1;
	}
	v8 = a1 + 1;
LABEL_12:
	++*getMemU16Ptr(0x5D4594, 4662);
	v19 = v8;
	v21 = a5;
	v23 = (char*)a4;
	v22 = 0;
	if ((int)(((unsigned int)(a5 - 1) >> 9) + 1) > 0) {
		while (1) {
			v10 = calloc(1, 0x1Cu);
			v11 = v10;
			if (!v10) {
				return 0;
			}
			*v10 = v22 + 1;
			v12 = 512;
			if (v7 <= 512) {
				v12 = v7;
			}
			v11[4] = v12;
			v13 = (char*)calloc(1, v12);
			v14 = (short)v11[4];
			*((uint32_t*)v11 + 3) = 0;
			v11[8] = 0;
			*((uint32_t*)v11 + 1) = v13;
			memcpy(v13, v23, v14);
			v15 = (short)v11[4];
			v16 = v21 - v15;
			v17 = (int)&v23[v15];
			*((uint32_t*)v11 + 6) = *((uint32_t*)v6 + 39);
			*((uint32_t*)v11 + 5) = 0;
			v18 = *((uint32_t*)v6 + 39);
			v23 = (char*)v17;
			v21 = v16;
			if (v18) {
				*(uint32_t*)(v18 + 20) = v11;
			} else {
				*((uint32_t*)v6 + 38) = v11;
			}
			*((uint32_t*)v6 + 39) = v11;
			if (++v22 >= (int)(((unsigned int)(a5 - 1) >> 9) + 1)) {
				v7 = a5;
				break;
			}
			v7 = v16;
		}
	}
	*((uint32_t*)v6 + 4) = v22;
	v6[4] = 0;
	*((uint32_t*)v6 + 3) = 1;
	*((uint16_t*)v6 + 10) = 512;
	*((uint32_t*)v6 + 2) = v7;
	*(uint32_t*)v6 = v19;
	*((uint16_t*)v6 + 3) = 1;
	if (a3) {
		strcpy(v6 + 23, a3);
		v7 = a5;
	}
	v6[22] = a2;
	nox_xxx_netXferMsg_40BE80(v19, a2, a3, v7, v20);
	return 1;
}

//----- (0040BE80) --------------------------------------------------------
int nox_xxx_netXferMsg_40BE80(unsigned int a1, char a2, const char* a3, int a4, char a5) {
	char v6[140]; // [esp+4h] [ebp-8Ch]

	v6[0] = -62;
	v6[1] = 0;
	v6[2] = a2;
	*(uint32_t*)&v6[4] = a4;
	if (a3) {
		strcpy(&v6[8], a3);
	} else {
		v6[8] = 0;
	}
	v6[136] = a5;
	return nox_xxx_netSendSock_552640(a1, v6, 140, NOX_NET_SEND_NO_LOCK | NOX_NET_SEND_FLAG2);
}

//----- (0040BF10) --------------------------------------------------------
char* sub_40BF10(uint8_t* a1) {
	int v1;      // ecx
	uint32_t* i; // eax

	v1 = 0;
	if ((int)*getMemU16Ptr(0x5D4594, 4660) <= 0) {
		return 0;
	}
	for (i = (uint32_t*)(dword_5d4594_3632 + 8); *((uint16_t*)i - 1) || *i; i += 40) {
		if (++v1 >= *getMemU16Ptr(0x5D4594, 4660)) {
			return 0;
		}
	}
	*a1 = v1;
	return (char*)(dword_5d4594_3632 + 160 * v1);
}

//----- (0040BF60) --------------------------------------------------------
char* sub_40BF60(int a1, char a2, int a3) {
	char* result;       // eax
	unsigned short* v4; // esi
	int v5;             // ecx
	int v6;             // ecx

	result = sub_40BC10(a1, a2);
	if (result) {
		v4 = (unsigned short*)*((uint32_t*)result + 38);
		if (v4) {
			while (*v4 != a3) {
				v4 = (unsigned short*)*((uint32_t*)v4 + 5);
				if (!v4) {
					return result;
				}
			}
			v5 = *((uint32_t*)v4 + 5);
			if (v5) {
				*(uint32_t*)(v5 + 24) = *((uint32_t*)v4 + 6);
			} else {
				*((uint32_t*)result + 39) = *((uint32_t*)v4 + 6);
			}
			v6 = *((uint32_t*)v4 + 6);
			if (v6) {
				*(uint32_t*)(v6 + 20) = *((uint32_t*)v4 + 5);
			} else {
				*((uint32_t*)result + 38) = *((uint32_t*)v4 + 5);
			}
			free(*((void**)v4 + 1));
			free(v4);
		}
	}
	return result;
}

//----- (0040BFF0) --------------------------------------------------------
char* sub_40BFF0(int a1, char a2, char* a3) {
	char* result; // eax

	result = a3;
	if ((unsigned char)a3 < (unsigned int)*getMemU16Ptr(0x5D4594, 4660)) {
		result = (char*)(dword_5d4594_3632 + 160 * (unsigned char)a3);
		result[4] = a2;
		*((uint16_t*)result + 3) = 2;
	}
	return result;
}

//----- (0040C030) --------------------------------------------------------
char* sub_40C030(int a1, char a2) {
	char* result; // eax
	char* v3;     // esi

	result = sub_40BC10(a1, a2);
	v3 = result;
	if (result) {
		sub_40B850(a1, result[22]);
		--*getMemU16Ptr(0x5D4594, 4662);
		result = (char*)sub_40B930((int)v3);
	}
	return result;
}

//----- (0040C070) --------------------------------------------------------
char* sub_40C070(int a1, int a2, char a3) {
	char* result; // eax
	char* v4;     // ebx
	int v5;       // esi
	int v6;       // edi

	result = sub_40BC10(a1, a3);
	v4 = result;
	if (result) {
		sub_40BBC0(*(uint32_t*)result, result[22]);
		v5 = *((uint32_t*)v4 + 38);
		if (v5) {
			do {
				v6 = *(uint32_t*)(v5 + 20);
				free(*(void**)(v5 + 4));
				free((void*)v5);
				v5 = v6;
			} while (v6);
		}
		result = (char*)sub_40B930((int)v4);
	}
	return result;
}

//----- (0040C0D0) --------------------------------------------------------
void sub_40C0D0() { free(*(void**)&dword_5d4594_3632); }

//----- (0040C0E0) --------------------------------------------------------
void sub_40C0E0(int a1) {
	int v1; // edi
	int v2; // eax
	int v3; // esi

	v1 = 0;
	if (*getMemU16Ptr(0x5D4594, 4660)) {
		v2 = dword_5d4594_3632;
		v3 = 0;
		do {
			if (*(uint16_t*)(v3 + v2 + 6) == 2 && *(uint32_t*)(v3 + v2) == a1) {
				sub_40BB20(*(uint32_t*)(v3 + v2), *(uint8_t*)(v3 + v2 + 4), 1);
				v2 = dword_5d4594_3632;
			}
			++v1;
			v3 += 160;
		} while (v1 < *getMemU16Ptr(0x5D4594, 4660));
	}
}

//----- (0040C140) --------------------------------------------------------
int sub_40C140(int a1, int a2, uint32_t* a3) {
	int v3;     // eax
	int result; // eax
	int v5;     // eax
	int v6;     // eax

	if (a2 == -2147221396 || a2) {
		if (sub_41E300(11)) {
			dword_5d4594_2660652 = a2;
			v5 = sub_41E2F0();
			sub_41DA70(v5, 5);
			v6 = sub_41E2F0();
			sub_41DA70(v6, 9);
		}
		result = 0;
	} else {
		sub_41E4D0(a3);
		v3 = sub_41E2F0();
		sub_41DA70(v3, 2);
		result = 0;
	}
	return result;
}

//----- (0040C1B0) --------------------------------------------------------
int sub_40C1B0(int a1, int a2, int a3) {
	int v3; // eax

	if (a2 == -2147221402 && (sub_41E2F0() == 7 || sub_41E2F0() == 5)) {
		dword_5d4594_2660652 = -2147221402;
		v3 = sub_41E2F0();
		sub_41DA70(v3, 5);
	}
	return 0;
}

//----- (0040C1F0) --------------------------------------------------------
int sub_40C1F0(int a1, int a2, const void* a3) {
	if (a2 || sub_41E2F0() != 7 || !a3) {
		return 0;
	}
	sub_446520(0, a3, strlen((const char*)a3) + 1);
	sub_446D50();
	return 0;
}

//----- (0040C240) --------------------------------------------------------
int sub_40C240(int a1, int a2, int a3) {
	if (a2) {
		if (dword_5d4594_528252 && dword_5d4594_528256) {
			sub_41E470();
			return 0;
		}
	} else {
		if (sub_41E2F0() == 7) {
			sub_41ECB0(a3);
			sub_41EBB0(a3);
			sub_447470_wol_chat();
			sub_448640();
		} else if (sub_41E2F0() == 8) {
			sub_416690();
		}
		sub_41F230(0, 1);
		if (dword_5d4594_528252 && dword_5d4594_528256) {
			sub_41E370();
			sub_41E4B0(0);
		}
		*getMemU32Ptr(0x587000, 25736) = 0;
	}
	return 0;
}
// 448640: using guessed type int sub_448640(void);

//----- (0040C2E0) --------------------------------------------------------
int sub_40C2E0(int a1, int a2, int a3, const char* a4) {
	int result; // eax
	int v5;     // eax
	int v6;     // eax
	int v7;     // eax
	int v8;     // eax
	int v9;     // eax

	if (sub_41E2F0() != 7 && sub_41E2F0() != 8) {
		return 0;
	}
	if (a2 <= -2147221390) {
		if (a2 >= -2147221392) {
		LABEL_10:
			dword_5d4594_2660652 = a2;
			v7 = sub_41E2F0();
			sub_41DA70(v7, 5);
			return 0;
		}
		if (a2 != -2147221396) {
			if (a2 != -2147221394) {
				return 0;
			}
			goto LABEL_10;
		}
		if (sub_41E300(11)) {
			dword_5d4594_2660652 = -2147221396;
			v5 = sub_41E2F0();
			sub_41DA70(v5, 5);
			v6 = sub_41E2F0();
			sub_41DA70(v6, 9);
			return 0;
		}
		return 0;
	}
	if (a2) {
		return 0;
	}
	v8 = *(uint32_t*)a4;
	if ((v8 & 0x8000) == 0) {
	LABEL_15:
		sub_41F230(0, 1);
		sub_41F520(a4);
		return 0;
	}
	sub_41EBB0(a3);
	if (sub_41E2F0() == 7) {
		sub_447470_wol_chat();
		sub_448640();
		goto LABEL_15;
	}
	if (sub_41E2F0() != 8) {
		goto LABEL_15;
	}
	memcpy(getMemAt(0x85B3FC, 10308), a4, 0x6Cu);
	if (*((uint32_t*)a4 + 5)) {
		sub_40DB20(*((uint32_t*)a4 + 5));
		result = 1;
	} else {
		if (!(*a4 & 1)) {
			v9 = sub_41E2F0();
			sub_41DA70(v9, 19);
		}
		result = 1;
	}
	return result;
}
// 448640: using guessed type int sub_448640(void);

//----- (0040C420) --------------------------------------------------------
int sub_40C420(int a1, int a2, int a3, int* a4) {
	int v4; // eax
	int v6; // eax

	if (sub_41E2F0() == 7 || sub_41E2F0() == 8) {
		if (a2 == -2147220994) {
			dword_5d4594_2660652 = -2147220994;
			v6 = sub_41E2F0();
			sub_41DA70(v6, 5);
		} else if (!a2) {
			sub_41F620((int)a4);
			if (sub_41F9E0((int)a4)) {
				sub_41F4B0();
				if (sub_41E2F0() == 7) {
					sub_447590_wol_chat();
				}
				sub_41F230(0, -1);
				sub_41EBB0(0);
			} else {
				sub_41F230(0, -1);
			}
			if (sub_41E2F0() != 7) {
				if (*a4 & 1) {
					v4 = *a4;
					if ((v4 & 0x8000) == 0) {
						sub_40D380();
						return 0;
					}
				}
			}
		}
	}
	return 0;
}

//----- (0040C4E0) --------------------------------------------------------
int sub_40C4E0(int a1, int a2, int a3, int a4) { return 0; }

//----- (0040C4F0) --------------------------------------------------------
int sub_40C4F0(int a1, int a2, int a3) { return 0; }

//----- (0040C500) --------------------------------------------------------
int sub_40C500(int a1, int a2, int a3) { return 0; }

//----- (0040C510) --------------------------------------------------------
int sub_40C510(int a1, int a2, int a3) { return 0; }

//----- (0040C520) --------------------------------------------------------
int sub_40C520(int a1, int a2, int a3) { return 0; }

//----- (0040C530) --------------------------------------------------------
int sub_40C530(int a1, int a2, int a3, uint8_t* a4) {
	if (sub_41E2F0() == 7 && !a2 && !sub_41F9E0(a3)) {
		sub_448650(a4, (wchar_t*)getMemAt(0x5D4594, 8908));
		sub_447250((const char*)(a3 + 36), (int)getMemAt(0x5D4594, 8908), 1, 0);
	}
	return 0;
}

//----- (0040C580) --------------------------------------------------------
int sub_40C580(int a1, int a2, int a3, int a4, uint8_t* a5) {
	if (sub_41E2F0() == 7 && !a2) {
		sub_448650(a5, (wchar_t*)getMemAt(0x5D4594, 8908));
		sub_447250((const char*)(a4 + 36), (int)getMemAt(0x5D4594, 8908), 0, 0);
	}
	return 0;
}

//----- (0040C5C0) --------------------------------------------------------
int sub_40C5C0(int a1, int a2, int a3, int a4, uint8_t* a5) {
	if (sub_41E2F0() == 7 && !a2) {
		sub_448650(a5, (wchar_t*)getMemAt(0x5D4594, 8908));
		sub_4471A0((const char*)(a4 + 36), (int)getMemAt(0x5D4594, 8908), 0, 0);
	}
	return 0;
}

//----- (0040C600) --------------------------------------------------------
int sub_40C600(int a1, int a2, int a3, uint8_t* a4) {
	if (sub_41E2F0() == 7 && !a2 && !sub_41F9E0(a3)) {
		sub_448650(a4, (wchar_t*)getMemAt(0x5D4594, 8908));
		sub_4471A0((const char*)(a3 + 36), (int)getMemAt(0x5D4594, 8908), 1, 0);
	}
	return 0;
}

//----- (0040C650) --------------------------------------------------------
int sub_40C650(int a1, int a2, int a3, int a4) { return 0; }

//----- (0040C660) --------------------------------------------------------
int sub_40C660(int a1, int a2, int a3, int a4, int a5) { return 0; }

//----- (0040C670) --------------------------------------------------------
int sub_40C670(int a1, int a2, int a3, int a4, int a5) {
	if (!a2) {
		sub_416670(a5);
	}
	return 0;
}

//----- (0040C690) --------------------------------------------------------
int sub_40C690(int a1, int a2, int a3, int a4, int a5) {
	if (sub_41E2F0() == 7 && !a2) {
		sub_41F620(a4);
		if (sub_41F9E0(a4)) {
			sub_41F4B0();
			sub_41F230(0, -1);
			sub_41EBB0(0);
			sub_4474C0_wol_chat(0, a5 + 36);
			return 0;
		}
		sub_4474C0_wol_chat(a4 + 36, a5 + 36);
		sub_41F230(0, -1);
	}
	return 0;
}

//----- (0040C710) --------------------------------------------------------
int sub_40C710(int a1, int a2, int a3) { return 0; }

//----- (0040C720) --------------------------------------------------------
int sub_40C720(int a1, int a2, uint32_t* a3) {
	if (sub_41E2F0() == 7 || sub_41E2F0() == 8) {
		if (a2) {
			if (a2 <= 262447 || a2 > 262450) {
				sub_4490C0_wol_dialogs(0);
				return 0;
			}
		} else if (sub_41E2F0() == 8) {
			if (*a3 == sub_420100()) {
				sub_4490C0_wol_dialogs((int)a3);
				return 0;
			}
		} else if (!*a3) {
			sub_4490C0_wol_dialogs((int)a3);
			return 0;
		}
		sub_4491B0_wol_dialogs();
	}
	return 0;
}

//----- (0040C7A0) --------------------------------------------------------
int sub_40C7A0(int a1, int a2) {
	if (sub_41E2F0() == 7) {
		if (a2) {
			sub_449240_wol_dialogs();
			return 0;
		}
		sub_449200_wol_dialogs();
	}
	return 0;
}

//----- (0040C7D0) --------------------------------------------------------
int sub_40C7D0(int a1, int a2, int a3, uint8_t* a4) {
	if (sub_41E2F0() == 7) {
		if (!a2) {
			sub_448650(a4, (wchar_t*)getMemAt(0x5D4594, 8908));
			sub_447380((const char*)(a3 + 36), (char*)getMemAt(0x5D4594, 8908));
			return 0;
		}
	} else if (sub_43C710()) {
		sub_43D260(a3 + 36, (int)a4);
	}
	return 0;
}

//----- (0040C830) --------------------------------------------------------
int sub_40C830(int a1, int a2, int a3) {
	int v3; // eax
	int v4; // eax

	if (sub_41E2F0() == 7 && !a2 && sub_41E300(11)) {
		dword_5d4594_2660652 = 1;
		v3 = sub_41E2F0();
		sub_41DA70(v3, 5);
		v4 = sub_41E2F0();
		sub_41DA70(v4, 9);
	}
	return 0;
}

//----- (0040C880) --------------------------------------------------------
int sub_40C880(int a1, int a2, const char* a3, int a4, int a5) {
	int v5; // eax

	if (sub_41E2F0() == 7 && !a2) {
		sub_41F840(a3, a4);
		v5 = sub_41E2F0();
		sub_41DA70(v5, 11);
	}
	return 0;
}

//----- (0040C8C0) --------------------------------------------------------
int sub_40C8C0(int a1, int a2, int a3, int a4) {
	if (sub_41E2F0() == 7 && !a2 && a4) {
		sub_447540_wol_chat(a3);
	}
	return 0;
}

//----- (0040C8F0) --------------------------------------------------------
int sub_40C8F0(int a1, int a2, int a3, int a4) {
	int v5; // eax

	if (sub_41E2F0() == 8 && !a2) {
		dword_5d4594_2660032 = *(uint32_t*)a4;
		strncpy((char*)getMemAt(0x85B3FC, 10395), (const char*)(a4 + 401), 9u);
		*getMemU8Ptr(0x85B3FC, 10404) = 0;
		if (*getMemU32Ptr(0x5D4594, 10980)) {
			*getMemU32Ptr(0x5D4594, 10980) = 0;
			sub_41D5E0();
			return 0;
		}
		v5 = sub_41E2F0();
		sub_41DA70(v5, 19);
	}
	return 0;
}

//----- (0040C960) --------------------------------------------------------
int sub_40C960(int a1, int a2, uint32_t* a3) {
	int v3;   // eax
	int v4;   // eax
	short v6; // [esp-8h] [ebp-8h]

	if (sub_41E2F0() == 2 && sub_40E0B0()) {
		if (a2) {
			if (!sub_41E300(11)) {
				return 0;
			}
			dword_5d4594_2660652 = a2;
			v3 = sub_41E2F0();
			sub_41DA70(v3, 5);
			v6 = 9;
		} else {
			sub_4201B0(a3);
			v6 = 1;
		}
		v4 = sub_41E2F0();
		sub_41DA70(v4, v6);
		return 0;
	}
	return 0;
}

//----- (0040C9D0) --------------------------------------------------------
int sub_40C9D0(int a1, int a2, int* a3) {
	int v4; // eax

	if (a2) {
		return 0;
	}
	if (sub_41E2F0() != 7) {
		if (*a3 & 1) {
			v4 = *a3;
			if ((v4 & 0x8000) == 0) {
				sub_40D380();
			}
		}
		return 0;
	}
	sub_41F620((int)a3);
	if (sub_41F9E0((int)a3)) {
		sub_41EBB0(0);
		sub_447590_wol_chat();
	}
	sub_41F230(0, -1);
	return 0;
}

//----- (0040CA40) --------------------------------------------------------
int sub_40CA40(int a1, int a2) { return 0; }

//----- (0040CA50) --------------------------------------------------------
int sub_40CA50(int a1, int a2) { return 0; }

//----- (0040CA60) --------------------------------------------------------
int sub_40CA60(int a1, int a2, const void* a3) {
	int result; // eax
	int v4;     // eax
	int v5;     // eax
	int v6;     // eax
	int v7;     // eax
	int v8;     // eax

	result = sub_40E0B0();
	if (result) {
		if (a2) {
			if (dword_5d4594_528252 && dword_5d4594_528256) {
				sub_41E470();
				return 0;
			}
			if (sub_41E300(11)) {
				dword_5d4594_2660652 = a2;
				v4 = sub_41E2F0();
				sub_41DA70(v4, 6);
				v5 = sub_41E2F0();
				sub_41DA70(v5, 9);
				return 0;
			}
		} else {
			if (sub_41E2F0() == 5) {
				sub_41FF30(a3);
				sub_41E300(7);
				v6 = sub_41E2F0();
				sub_41DA70(v6, 7);
				sub_4207F0(3);
				v7 = sub_41FC40();
				sub_40DB50(v7 + 1, (int)&a3);
				sub_40D670((int)a3);
				return 0;
			}
			if (sub_41E2F0() == 3) {
				sub_446A90();
				sub_446AD0(nox_game_showWolChat_447620);
				sub_41FF30(a3);
				v8 = sub_41E2F0();
				sub_41DA70(v8, 7);
				return 0;
			}
			if (dword_5d4594_528252 && dword_5d4594_528256) {
				sub_43AA70();
			}
		}
		result = 0;
	}
	return result;
}

//----- (0040CB90) --------------------------------------------------------
int sub_40CB90(int a1, int a2, int a3) { return 0; }

//----- (0040CBA0) --------------------------------------------------------
int sub_40CBA0(int a1, int a2, int a3) {
	if (sub_41E2F0() == 7 && !a2) {
		nox_swprintf((wchar_t*)getMemAt(0x5D4594, 8908), L"%S", a3);
		sub_447310(0, (int)getMemAt(0x5D4594, 8908));
	}
	return 0;
}

//----- (0040CBE0) --------------------------------------------------------
void sub_44B010();
int sub_40CBE0(int a1, int a2) {
	int v2;     // eax
	int v3;     // eax
	int result; // eax

	if (a2 > 262447) {
		return 0;
	}
	if (a2 == 262447) {
		if (sub_40CD00()) {
			if (sub_43C710()) {
				sub_44B010();
				sub_40E0A0();
			} else {
				sub_41E300(9);
				sub_41F4B0();
				sub_41EC30();
				sub_446490(0);
				nox_xxx____setargv_4_44B000();
				sub_40E0A0();
				nox_game_checkStateWol_43C260();
				sub_44A400();
			}
			return 0;
		}
		if (sub_41E2F0() == 9) {
			sub_40E0A0();
			dword_5d4594_10988 = 0;
			return 0;
		}
		if (sub_41E2F0() == 3) {
			nox_xxx_officialStringCmp_41FDE0();
		}
		dword_5d4594_10988 = 0;
		return 0;
	}
	switch (a2 + 2147221401) {
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	case 14:
	case 15:
		if (!sub_41E300(11)) {
			return 0;
		}
		dword_5d4594_2660652 = a2;
		v2 = sub_41E2F0();
		sub_41DA70(v2, 5);
		v3 = sub_41E2F0();
		sub_41DA70(v3, 9);
		result = 0;
		break;
	default:
		return 0;
	}
	return result;
}

//----- (0040CD00) --------------------------------------------------------
int sub_40CD00() {
	int result; // eax

	if (sub_41E2F0() == 2 || sub_41E2F0() == 4 || sub_41E2F0() == 11 || sub_41E2F0() == 5 || sub_41E2F0() == 3 ||
		(result = 1, dword_5d4594_10988 == 1)) {
		result = 0;
	}
	return result;
}

//----- (0040CD50) --------------------------------------------------------
int sub_40CD50(int a1, int a2, int a3) { return 0; }

//----- (0040CD60) --------------------------------------------------------
int nox_xxx_somejoinproc_40CD60(int a1, int a2, int a3) {
	int v4; // eax

	if (sub_41E2F0() == 7 || sub_41E2F0() == 8) {
		if (a2) {
			if (a2 == 262459) {
				nox_xxx_failconn_43B0E0(a3);
				return 0;
			}
		} else {
			sub_448640();
			sub_41EFB0(a3);
			v4 = sub_41E2F0();
			sub_41DA70(v4, 10);
		}
	}
	return 0;
}
// 448640: using guessed type int sub_448640(void);

//----- (0040CDC0) --------------------------------------------------------
int sub_40CDC0(int a1, int a2, int a3, int a4) {
	int* v4; // esi
	int v5;  // eax
	int v7;  // eax

	if (!a2) {
		v4 = (int*)a4;
		sub_41F6F0(a4);
		if (sub_41E2F0() == 7) {
			v5 = sub_41E2F0();
			sub_41DA70(v5, 11);
			return 0;
		}
		if (sub_41E2F0() == 8 && a4) {
			while (1) {
				v7 = *v4;
				if ((v7 & 0x8000) != 0) {
					break;
				}
				v4 = (int*)v4[8];
				if (!v4) {
					return 0;
				}
			}
			if (*(uint8_t*)v4 & 1) {
				if (v4[5]) {
					sub_40DB20(v4[5]);
					*getMemU32Ptr(0x5D4594, 10980) = 1;
				}
				if (sub_416650()) {
					sub_40D530((int)v4);
				}
			}
		}
	}
	return 0;
}

//----- (0040D0F0) --------------------------------------------------------
void sub_40D0F0() {
	unsigned char* v0; // eax
	int v1;            // esi
	int v2;            // eax
	uint32_t* v3;      // esi
	uint32_t* v4;      // edi
	unsigned int v5;   // esi

	LOBYTE(v0) = getMemByte(0x5D4594, 10976);
	if (*getMemU32Ptr(0x5D4594, 10976)) {
		if (dword_5d4594_10956) {
			sub_40E320(*(int (****)(uint32_t, void*, int*)) & dword_5d4594_10956, (int)getMemAt(0x581450, 5704),
					   *getMemIntPtr(0x5D4594, 10968));
			(*(void (**)(uint32_t))(**(uint32_t**)&dword_5d4594_10956 + 8))(dword_5d4594_10956);
		}
		if (dword_5d4594_4808) {
			sub_40E320(*(int (****)(uint32_t, void*, int*)) & dword_5d4594_4808, (int)getMemAt(0x581450, 5672),
					   *getMemIntPtr(0x5D4594, 10964));
			(*(void (**)(uint32_t))(**(uint32_t**)&dword_5d4594_4808 + 8))(dword_5d4594_4808);
		}
		if (dword_5d4594_4668) {
			sub_40E320(*(int (****)(uint32_t, void*, int*)) & dword_5d4594_4668, (int)getMemAt(0x581450, 5640),
					   *getMemIntPtr(0x5D4594, 10960));
			(*(void (**)(uint32_t))(**(uint32_t**)&dword_5d4594_4668 + 8))(dword_5d4594_4668);
		}
		v0 = getMemAt(0x5D4594, 4676);
		if (true) // TODO: byte_5D4594 != (unsigned char*)-4676
		{
			v1 = *getMemU32Ptr(0x5D4594, 4692);
			if (*getMemU32Ptr(0x5D4594, 4692) && **(uint32_t**)getMemAt(0x5D4594, 4692)) {
				do {
					v2 = *(uint32_t*)(v1 + 16);
					if (v2) {
						(*(void (**)(uint32_t))(*(uint32_t*)v2 + 8))(*(uint32_t*)(v1 + 16));
					}
					*(uint32_t*)(v1 + 16) = 0;
					(*(void (**)(uint32_t))(v1 + 32))(0);
					if (*getMemU32Ptr(0x5D4594, 4676) == 100) {
						v1 += 28;
					} else {
						v1 += 36;
					}
				} while (*(uint32_t*)v1);
			}
			v3 = *(uint32_t**)getMemAt(0x5D4594, 4804);
			if (*getMemU32Ptr(0x5D4594, 4804)) {
				do {
					((void (*)(uint32_t)) * v3)(v3[1]);
					v4 = (uint32_t*)v3[2];
					operator_delete(v3);
					v3 = v4;
				} while (v4);
			}
			LOBYTE(v0) = getMemByte(0x5D4594, 4700);
			if (*getMemU32Ptr(0x5D4594, 4700)) {
				LOBYTE(v0) = getMemByte(0x5D4594, 4784);
				if (getMemByte(0x5D4594, 4784)) {
					if (*getMemU32Ptr(0x5D4594, 4796)) {
						v5 = 0;
						do {
							HeapDestroy(*(HANDLE*)(*getMemU32Ptr(0x5D4594, 4796) + 4 * v5++));
						} while (v5 <= *getMemIntPtr(0x5D4594, 4792));
					}
					LOBYTE(v0) = HeapDestroy(*(HANDLE*)getMemAt(0x5D4594, 4700));
				}
			}
		}
		*getMemU32Ptr(0x5D4594, 10976) = 0;
	}
}

//----- (0040D250) --------------------------------------------------------
int sub_40D250() {
	return *getMemU32Ptr(0x5D4594, 10976) && !dword_5d4594_10984 &&
		   (*(int (**)(uint32_t))(**(uint32_t**)&dword_5d4594_4668 + 12))(dword_5d4594_4668) >= 0;
}

//----- (0040D280) --------------------------------------------------------
int sub_40D280(int a1, int a2, int a3, int a4, int a5) {
	int result; // eax

	if (*getMemU32Ptr(0x5D4594, 10976)) {
		result = (*(int (**)(uint32_t, int, int, int, int, int))(**(uint32_t**)&dword_5d4594_4668 + 16))(
					 dword_5d4594_4668, a1, a2, a3, a4, a5) >= 0;
	} else {
		result = 0;
	}
	return result;
}

//----- (0040D2C0) --------------------------------------------------------
int sub_40D2C0(int a1, int a2, int a3) {
	int result; // eax

	if (*getMemU32Ptr(0x5D4594, 10976)) {
		result = (*(int (**)(uint32_t, int, int, int))(**(uint32_t**)&dword_5d4594_4668 + 20))(dword_5d4594_4668, a1,
																							   a2, a3) >= 0;
	} else {
		result = 0;
	}
	return result;
}

//----- (0040D2F0) --------------------------------------------------------
int sub_40D2F0(int a1, int a2) {
	int result; // eax

	if (*getMemU32Ptr(0x5D4594, 10976)) {
		result =
			(*(int (**)(uint32_t, int, int))(**(uint32_t**)&dword_5d4594_4668 + 24))(dword_5d4594_4668, a1, a2) >= 0;
	} else {
		result = 0;
	}
	return result;
}

//----- (0040D320) --------------------------------------------------------
int sub_40D320(int a1) {
	int result; // eax

	if (*getMemU32Ptr(0x5D4594, 10976)) {
		result = (*(int (**)(uint32_t, int))(**(uint32_t**)&dword_5d4594_4668 + 28))(dword_5d4594_4668, a1) >= 0;
	} else {
		result = 0;
	}
	return result;
}

//----- (0040D350) --------------------------------------------------------
int sub_40D350(int a1) {
	int result; // eax

	if (*getMemU32Ptr(0x5D4594, 10976)) {
		result = (*(int (**)(uint32_t, int))(**(uint32_t**)&dword_5d4594_4668 + 32))(dword_5d4594_4668, a1) >= 0;
	} else {
		result = 0;
	}
	return result;
}

//----- (0040D380) --------------------------------------------------------
void sub_40D380() {
	if (*getMemU32Ptr(0x5D4594, 10976)) {
		(*(int (**)(uint32_t))(**(uint32_t**)&dword_5d4594_4668 + 36))(dword_5d4594_4668);
	}
}

//----- (0040D3B0) --------------------------------------------------------
int sub_40D3B0() {
	int result; // eax

	if (*getMemU32Ptr(0x5D4594, 10976)) {
		result = (*(int (**)(uint32_t))(**(uint32_t**)&dword_5d4594_4668 + 40))(dword_5d4594_4668) >= 0;
	} else {
		result = 0;
	}
	return result;
}

//----- (0040D3E0) --------------------------------------------------------
int sub_40D3E0(int a1) {
	int result; // eax

	if (*getMemU32Ptr(0x5D4594, 10976)) {
		result = (*(int (**)(uint32_t, int))(**(uint32_t**)&dword_5d4594_4668 + 44))(dword_5d4594_4668, a1) >= 0;
	} else {
		result = 0;
	}
	return result;
}

//----- (0040D410) --------------------------------------------------------
int sub_40D410(int a1, int a2) {
	int result; // eax

	if (*getMemU32Ptr(0x5D4594, 10976)) {
		result =
			(*(int (**)(uint32_t, int, int))(**(uint32_t**)&dword_5d4594_4668 + 48))(dword_5d4594_4668, a1, a2) >= 0;
	} else {
		result = 0;
	}
	return result;
}

//----- (0040D440) --------------------------------------------------------
int sub_40D440() {
	int result; // eax

	if (!*getMemU32Ptr(0x5D4594, 10976) ||
		(*(int (**)(uint32_t))(**(uint32_t**)&dword_5d4594_4668 + 52))(dword_5d4594_4668) < 0) {
		return 0;
	}
	result = 1;
	dword_5d4594_10988 = 1;
	return result;
}

//----- (0040D4D0) --------------------------------------------------------
int sub_40D4D0(int a1) {
	int result; // eax

	if (*getMemU32Ptr(0x5D4594, 10976)) {
		result = (*(int (**)(uint32_t, int))(**(uint32_t**)&dword_5d4594_4668 + 64))(dword_5d4594_4668, a1) >= 0;
	} else {
		result = 0;
	}
	return result;
}

//----- (0040D500) --------------------------------------------------------
int sub_40D500(int a1, int a2) {
	int result; // eax

	if (*getMemU32Ptr(0x5D4594, 10976)) {
		result =
			(*(int (**)(uint32_t, int, int))(**(uint32_t**)&dword_5d4594_4668 + 68))(dword_5d4594_4668, a1, a2) >= 0;
	} else {
		result = 0;
	}
	return result;
}

//----- (0040D530) --------------------------------------------------------
int sub_40D530(int a1) {
	int result; // eax

	if (*getMemU32Ptr(0x5D4594, 10976)) {
		result = (*(int (**)(uint32_t, int))(**(uint32_t**)&dword_5d4594_4668 + 72))(dword_5d4594_4668, a1) >= 0;
	} else {
		result = 0;
	}
	return result;
}

//----- (0040D560) --------------------------------------------------------
int sub_40D560(int a1) {
	int v2; // eax

	if (!*getMemU32Ptr(0x5D4594, 10976)) {
		return 0;
	}
	v2 = (*(int (**)(uint32_t, int))(**(uint32_t**)&dword_5d4594_4668 + 76))(dword_5d4594_4668, a1);
	if (v2 <= -2147220995) {
		return 0;
	}
	if (v2) {
		return 0;
	}
	return 1;
}

//----- (0040D5B0) --------------------------------------------------------
int sub_40D5B0(int a1) {
	int result; // eax

	if (*getMemU32Ptr(0x5D4594, 10976)) {
		result = (*(int (**)(uint32_t, int))(**(uint32_t**)&dword_5d4594_4668 + 80))(dword_5d4594_4668, a1) >= 0;
	} else {
		result = 0;
	}
	return result;
}

//----- (0040D670) --------------------------------------------------------
int sub_40D670(int a1) {
	int result; // eax

	if (*getMemU32Ptr(0x5D4594, 10976)) {
		result = (*(int (**)(uint32_t, int))(**(uint32_t**)&dword_5d4594_4668 + 184))(dword_5d4594_4668, a1) >= 0;
	} else {
		result = 0;
	}
	return result;
}

//----- (0040D740) --------------------------------------------------------
int sub_40D740(int a1) {
	int result; // eax

	if (*getMemU32Ptr(0x5D4594, 10976)) {
		result = (*(int (**)(uint32_t, int))(**(uint32_t**)&dword_5d4594_4668 + 96))(dword_5d4594_4668, a1) >= 0;
	} else {
		result = 0;
	}
	return result;
}

//----- (0040D770) --------------------------------------------------------
int sub_40D770(int a1, int a2) {
	int result; // eax

	if (*getMemU32Ptr(0x5D4594, 10976)) {
		result =
			(*(int (**)(uint32_t, int, int))(**(uint32_t**)&dword_5d4594_4668 + 100))(dword_5d4594_4668, a1, a2) >= 0;
	} else {
		result = 0;
	}
	return result;
}

//----- (0040D7A0) --------------------------------------------------------
int sub_40D7A0(int a1, int a2) {
	int result; // eax

	if (*getMemU32Ptr(0x5D4594, 10976)) {
		result =
			(*(int (**)(uint32_t, int, int))(**(uint32_t**)&dword_5d4594_4668 + 104))(dword_5d4594_4668, a1, a2) >= 0;
	} else {
		result = 0;
	}
	return result;
}

//----- (0040D7D0) --------------------------------------------------------
int sub_40D7D0(int a1, int a2) {
	int result; // eax

	if (*getMemU32Ptr(0x5D4594, 10976)) {
		result =
			(*(int (**)(uint32_t, int, int))(**(uint32_t**)&dword_5d4594_4668 + 108))(dword_5d4594_4668, a1, a2) >= 0;
	} else {
		result = 0;
	}
	return result;
}

//----- (0040D890) --------------------------------------------------------
int sub_40D890(int a1) {
	int result; // eax

	if (*getMemU32Ptr(0x5D4594, 10976)) {
		result = (*(int (**)(uint32_t, int))(**(uint32_t**)&dword_5d4594_4668 + 124))(dword_5d4594_4668, a1) >= 0;
	} else {
		result = 0;
	}
	return result;
}

//----- (0040D950) --------------------------------------------------------
int sub_40D950(int a1) {
	int result; // eax

	if (*getMemU32Ptr(0x5D4594, 10976)) {
		result = (*(int (**)(uint32_t, int))(**(uint32_t**)&dword_5d4594_4668 + 140))(dword_5d4594_4668, a1) >= 0;
	} else {
		result = 0;
	}
	return result;
}

//----- (0040D980) --------------------------------------------------------
int sub_40D980(int a1, int a2, int a3) {
	int result; // eax

	if (*getMemU32Ptr(0x5D4594, 10976)) {
		result = (*(int (**)(uint32_t, int, int, int))(**(uint32_t**)&dword_5d4594_4668 + 144))(dword_5d4594_4668, a1,
																								a2, a3) >= 0;
	} else {
		result = 0;
	}
	return result;
}

//----- (0040D9C0) --------------------------------------------------------
int sub_40D9C0(int a1, int a2, int a3, int a4) {
	int result; // eax

	if (*getMemU32Ptr(0x5D4594, 10976)) {
		result = (*(int (**)(uint32_t, int, int, int, int))(**(uint32_t**)&dword_5d4594_4668 + 148))(
					 dword_5d4594_4668, a1, a2, a3, a4) >= 0;
	} else {
		result = 0;
	}
	return result;
}

//----- (0040DA90) --------------------------------------------------------
int sub_40DA90(int a1, int a2) {
	int result; // eax

	if (*getMemU32Ptr(0x5D4594, 10976)) {
		result =
			(*(int (**)(uint32_t, int, int))(**(uint32_t**)&dword_5d4594_4668 + 164))(dword_5d4594_4668, a1, a2) >= 0;
	} else {
		result = 0;
	}
	return result;
}

//----- (0040DB20) --------------------------------------------------------
int sub_40DB20(int a1) {
	int result; // eax

	if (*getMemU32Ptr(0x5D4594, 10976)) {
		result = (*(int (**)(uint32_t, int))(**(uint32_t**)&dword_5d4594_4668 + 176))(dword_5d4594_4668, a1) >= 0;
	} else {
		result = 0;
	}
	return result;
}

//----- (0040DB50) --------------------------------------------------------
int sub_40DB50(int a1, int a2) {
	int result; // eax

	if (*getMemU32Ptr(0x5D4594, 10976)) {
		result =
			(*(int (**)(uint32_t, int, int))(**(uint32_t**)&dword_5d4594_4668 + 196))(dword_5d4594_4668, a1, a2) >= 0;
	} else {
		result = 0;
	}
	return result;
}

//----- (0040DB80) --------------------------------------------------------
int sub_40DB80(int a1, int a2) {
	int result; // eax

	if (*getMemU32Ptr(0x5D4594, 10976)) {
		result =
			(*(int (**)(uint32_t, int, int))(**(uint32_t**)&dword_5d4594_4668 + 200))(dword_5d4594_4668, a1, a2) >= 0;
	} else {
		result = 0;
	}
	return result;
}

//----- (0040DBB0) --------------------------------------------------------
int sub_40DBB0(int a1) {
	int v1; // eax

	sub_41E560(0, 0, 0, 0);
	v1 = sub_41E2F0();
	sub_41DA70(v1, 16);
	return 0;
}

//----- (0040DBE0) --------------------------------------------------------
int sub_40DBE0(int a1, int a2) {
	int v2; // eax

	sub_41E560(0, 0, 0, 0);
	sub_41E5C0(a2);
	v2 = sub_41E2F0();
	sub_41DA70(v2, 17);
	return 0;
}

//----- (0040DC10) --------------------------------------------------------
int sub_40DC10(int a1, int a2, int a3, int a4, int a5) {
	int v5; // eax

	if (sub_40E0B0()) {
		sub_41E560(a2, a3, a4, a5);
		v5 = sub_41E2F0();
		sub_41DA70(v5, 18);
	}
	return 0;
}

//----- (0040DC50) --------------------------------------------------------
int sub_40DC50(int a1, int a2) {
	sub_40E0B0();
	return 0;
}

//----- (0040DC60) --------------------------------------------------------
int sub_40DC60(int a1) { return 0; }

//----- (0040DC70) --------------------------------------------------------
int sub_40DC70() { return (*(int (**)(uint32_t))(**(uint32_t**)&dword_5d4594_4808 + 16))(dword_5d4594_4808) >= 0; }

//----- (0040DC90) --------------------------------------------------------
int sub_40DC90(int a1, int a2, int a3, int a4, int a5, int a6) {
	return (*(int (**)(uint32_t, int, int, int, int, int, int))(**(uint32_t**)&dword_5d4594_4808 + 12))(
			   dword_5d4594_4808, a1, a2, a3, a4, a5, a6) >= 0;
}

//----- (0040DCD0) --------------------------------------------------------
int sub_40DCD0() {
	return !dword_5d4594_10984 &&
		   (*(int (**)(uint32_t))(**(uint32_t**)&dword_5d4594_4808 + 20))(dword_5d4594_4808) >= 0;
}

//----- (0040DD00) --------------------------------------------------------
int sub_40DD00(int a1, int a2, int a3, int a4, int a5) { return 0; }

//----- (0040DD10) --------------------------------------------------------
int sub_40DD10(int a1, int a2, int a3, int a4, int a5, int a6) {
	int i; // esi

	if (sub_41E2F0() != 8) {
		return 0;
	}
	if (!a2) {
		for (i = a3; i; i = *(uint32_t*)(i + 60)) {
			if (*(uint8_t*)(i + 64)) {
				sub_417C00((char*)(i + 64), *(uint32_t*)(i + 28));
			}
		}
	}
	return 0;
}

//----- (0040DD60) --------------------------------------------------------
int sub_40DD60(int a1, int a2) { return 0; }

//----- (0040DD70) --------------------------------------------------------
int sub_40DD70(int a1, int a2, int a3, const char* a4, const char* a5) {
	int v5;     // eax
	int result; // eax
	int v7;     // eax

	if (a2) {
		v5 = sub_41E2F0();
		sub_41DA70(v5, 5);
		result = a3;
		dword_5d4594_2660652 = a2;
		if (a3) {
			nox_swprintf((wchar_t*)getMemAt(0x85B3FC, 10436), L"%S", a3);
			result = 0;
		} else {
			*getMemU16Ptr(0x85B3FC, 10436) = 0;
		}
	} else {
		v7 = sub_41E2F0();
		sub_41DA70(v7, 22);
		sub_41FCA0(a4, a5);
		result = a3;
		if (a3) {
			nox_swprintf((wchar_t*)getMemAt(0x85B3FC, 10436), L"%S", a3);
			result = 0;
		} else {
			*getMemU16Ptr(0x85B3FC, 10436) = 0;
		}
	}
	return result;
}

//----- (0040DE10) --------------------------------------------------------
int sub_40DE10(int a1, int a2, int a3, int a4) {
	int v4; // eax
	int v6; // eax
	int v7; // eax
	int v8; // eax

	dword_5d4594_2660652 = a2;
	if (a2) {
		*getMemU16Ptr(0x85B3FC, 10436) = 0;
		v4 = sub_41E2F0();
		sub_41DA70(v4, 5);
		return 0;
	}
	if (a3 >= 13) {
		if (a3 < 18) {
			v7 = sub_41E2F0();
			sub_41DA70(v7, 21);
			return 0;
		}
	} else if (!a4) {
		v6 = sub_41E2F0();
		sub_41DA70(v6, 5);
		return 0;
	}
	v8 = sub_41E2F0();
	sub_41DA70(v8, 20);
	return 0;
}

//----- (0040DE90) --------------------------------------------------------
int sub_40DE90(int a1, int a2, int a3, int a4) {
	dword_5d4594_2660652 = a2;
	return 0;
}

//----- (0040DEA0) --------------------------------------------------------
int sub_40DEA0(int a1, int a2, int a3, int a4) {
	return (*(int (**)(uint32_t, int, int, int, int))(**(uint32_t**)&dword_5d4594_10956 + 12))(dword_5d4594_10956, a1,
																							   a2, a3, a4) >= 0;
}

//----- (0040DF20) --------------------------------------------------------
int sub_40DF20(int a1, int a2, int a3, int a4, int a5, int a6, int a7) {
	return (*(int (**)(uint32_t, int, int, int, int, int, int, int))(**(uint32_t**)&dword_5d4594_10956 + 20))(
			   dword_5d4594_10956, a1, a2, a3, a4, a5, a6, a7) >= 0;
}

//----- (0040DF90) --------------------------------------------------------
int sub_40DF90() {
	return !dword_5d4594_10984 &&
		   (*(int (**)(uint32_t))(**(uint32_t**)&dword_5d4594_10956 + 28))(dword_5d4594_10956) >= 0;
}

//----- (0040DFE0) --------------------------------------------------------
int sub_40DFE0(int a1, int a2, int a3, int a4, int a5, int a6) {
	return (*(int (**)(uint32_t, int, int, int, int, int, int))(**(uint32_t**)&dword_5d4594_10956 + 36))(
			   dword_5d4594_10956, a1, a2, a3, a4, a5, a6) >= 0;
}

//----- (0040E020) --------------------------------------------------------
int sub_40E020(int a1, int a2, int a3, int a4) {
	return (*(int (**)(uint32_t, int, int, int, int))(**(uint32_t**)&dword_5d4594_10956 + 40))(dword_5d4594_10956, a1,
																							   a2, a3, a4) >= 0;
}

//----- (0040E090) --------------------------------------------------------
void sub_40E090() { dword_5d4594_10984 = 0; }

//----- (0040E0A0) --------------------------------------------------------
void sub_40E0A0() { dword_5d4594_10984 = 1; }

//----- (0040E0B0) --------------------------------------------------------
int sub_40E0B0() { return dword_5d4594_10984 == 0; }

//----- (0040E0C0) --------------------------------------------------------
int sub_40E0C0() { return *getMemU32Ptr(0x5D4594, 10976); }

//----- (0040E320) --------------------------------------------------------
int sub_40E320(int (***a1)(uint32_t, void*, int*), int a2, int a3) {
	int (**v3)(uint32_t, void*, int*); // ecx
	int v4;                            // esi
	int v6;                            // [esp+20h] [ebp-14h]
	int v7[3];                         // [esp+24h] [ebp-10h]
	int v8;                            // [esp+30h] [ebp-4h]

	v7[0] = 0;
	v8 = 0;
	v6 = 0;
	v3 = *a1;
	LOBYTE(v8) = 1;
	v4 = (*v3)(a1, getMemAt(0x581450, 11152), v7);
	if (v4 >= 0) {
		v4 = (*(int (**)(int, int, int*))(*(uint32_t*)v7[0] + 16))(v7[0], a2, &v6);
		if (v4 >= 0) {
			v4 = (*(int (**)(int, int))(*(uint32_t*)v6 + 24))(v6, a3);
		}
	}
	LOBYTE(v8) = 0;
	if (v6) {
		(*(void (**)(int))(*(uint32_t*)v6 + 8))(v6);
	}
	v8 = -1;
	if (v7[0]) {
		(*(void (**)(int))(*(uint32_t*)v7[0] + 8))(v7[0]);
	}
	return v4;
}

//----- (0040E490) --------------------------------------------------------
int sub_40E490(int a1) { return InterlockedIncrement((volatile int*)(a1 + 4)); }

//----- (0040E4B0) --------------------------------------------------------
int sub_40E4B0(volatile int* lpMem) {
	int v1; // edi

	v1 = InterlockedDecrement(lpMem + 1);
	if (!v1 && lpMem) {
		sub_40E5F0(lpMem);
		operator_delete((void*)lpMem);
	}
	return v1;
}

//----- (0040E4F0) --------------------------------------------------------
int sub_40E4F0(int a1, uint32_t* a2, int* a3) {
	unsigned char* v3;                         // esi
	int result;                                // eax
	uint32_t* v5;                              // eax
	int v6;                                    // ebp
	int (*v7)(int, uint32_t*, int*, uint32_t); // eax
	int v8;                                    // eax
	int v9;                                    // esi

	v3 = getMemAt(0x581450, 5896);
	if (!a3) {
		return -2147467261;
	}
	*a3 = 0;
	if (!*a2 && !a2[1] && a2[2] == 192 && a2[3] == 1174405120) {
		(*(void (**)(int))(*(uint32_t*)a1 + 4))(a1);
		*a3 = a1;
		return 0;
	}
	while (1) {
		v5 = *(uint32_t**)v3;
		v6 = *(uint32_t*)v3 == 0;
		if (!*(uint32_t*)v3 || *v5 == *a2 && v5[1] == a2[1] && v5[2] == a2[2] && v5[3] == a2[3]) {
			break;
		}
	LABEL_17:
		v8 = *((uint32_t*)v3 + 5);
		v3 += 12;
		if (!v8) {
			return -2147467262;
		}
	}
	v7 = (int (*)(int, uint32_t*, int*, uint32_t)) * ((uint32_t*)v3 + 2);
	if ((int)v7 != 1) {
		result = v7(a1, a2, a3, *((uint32_t*)v3 + 1));
		if (!result || !v6 && result < 0) {
			return result;
		}
		goto LABEL_17;
	}
	v9 = a1 + *((uint32_t*)v3 + 1);
	(*(void (**)(int))(*(uint32_t*)v9 + 4))(v9);
	*a3 = v9;
	return 0;
}

//----- (0040E5F0) --------------------------------------------------------
void sub_40E5F0(uint32_t* a1) {
	uint32_t* v1; // esi
	uint32_t* v2; // edi

	v1 = a1;
	v2 = a1 + 1;
	*a1 = getMemAt(0x581450, 5920);
	a1[1] = 1;
	InterlockedDecrement((volatile int*)getMemAt(0x5D4594, 4696));
}

//----- (0040E680) --------------------------------------------------------
int sub_40E680(volatile int* lpMem) {
	int v1; // edi

	v1 = InterlockedDecrement(lpMem + 1);
	if (!v1 && lpMem) {
		sub_40E7C0(lpMem);
		operator_delete((void*)lpMem);
	}
	return v1;
}

//----- (0040E6C0) --------------------------------------------------------
int sub_40E6C0(int a1, uint32_t* a2, int* a3) {
	unsigned char* v3;                         // esi
	int result;                                // eax
	uint32_t* v5;                              // eax
	int v6;                                    // ebp
	int (*v7)(int, uint32_t*, int*, uint32_t); // eax
	int v8;                                    // eax
	int v9;                                    // esi

	v3 = getMemAt(0x581450, 5872);
	if (!a3) {
		return -2147467261;
	}
	*a3 = 0;
	if (!*a2 && !a2[1] && a2[2] == 192 && a2[3] == 1174405120) {
		(*(void (**)(int))(*(uint32_t*)a1 + 4))(a1);
		*a3 = a1;
		return 0;
	}
	while (1) {
		v5 = *(uint32_t**)v3;
		v6 = *(uint32_t*)v3 == 0;
		if (!*(uint32_t*)v3 || *v5 == *a2 && v5[1] == a2[1] && v5[2] == a2[2] && v5[3] == a2[3]) {
			break;
		}
	LABEL_17:
		v8 = *((uint32_t*)v3 + 5);
		v3 += 12;
		if (!v8) {
			return -2147467262;
		}
	}
	v7 = (int (*)(int, uint32_t*, int*, uint32_t)) * ((uint32_t*)v3 + 2);
	if ((int)v7 != 1) {
		result = v7(a1, a2, a3, *((uint32_t*)v3 + 1));
		if (!result || !v6 && result < 0) {
			return result;
		}
		goto LABEL_17;
	}
	v9 = a1 + *((uint32_t*)v3 + 1);
	(*(void (**)(int))(*(uint32_t*)v9 + 4))(v9);
	*a3 = v9;
	return 0;
}

//----- (0040E7C0) --------------------------------------------------------
void sub_40E7C0(uint32_t* a1) {
	uint32_t* v1; // esi
	uint32_t* v2; // edi

	v1 = a1;
	v2 = a1 + 1;
	*a1 = getMemAt(0x581450, 6084);
	a1[1] = 1;
	InterlockedDecrement((volatile int*)getMemAt(0x5D4594, 4696));
}

//----- (0040E850) --------------------------------------------------------
int sub_40E850(volatile int* lpMem) {
	int v1; // edi

	v1 = InterlockedDecrement(lpMem + 1);
	if (!v1 && lpMem) {
		sub_40E990(lpMem);
		operator_delete((void*)lpMem);
	}
	return v1;
}

//----- (0040E890) --------------------------------------------------------
int sub_40E890(int a1, uint32_t* a2, int* a3) {
	unsigned char* v3;                         // esi
	int result;                                // eax
	uint32_t* v5;                              // eax
	int v6;                                    // ebp
	int (*v7)(int, uint32_t*, int*, uint32_t); // eax
	int v8;                                    // eax
	int v9;                                    // esi

	v3 = getMemAt(0x581450, 5848);
	if (!a3) {
		return -2147467261;
	}
	*a3 = 0;
	if (!*a2 && !a2[1] && a2[2] == 192 && a2[3] == 1174405120) {
		(*(void (**)(int))(*(uint32_t*)a1 + 4))(a1);
		*a3 = a1;
		return 0;
	}
	while (1) {
		v5 = *(uint32_t**)v3;
		v6 = *(uint32_t*)v3 == 0;
		if (!*(uint32_t*)v3 || *v5 == *a2 && v5[1] == a2[1] && v5[2] == a2[2] && v5[3] == a2[3]) {
			break;
		}
	LABEL_17:
		v8 = *((uint32_t*)v3 + 5);
		v3 += 12;
		if (!v8) {
			return -2147467262;
		}
	}
	v7 = (int (*)(int, uint32_t*, int*, uint32_t)) * ((uint32_t*)v3 + 2);
	if ((int)v7 != 1) {
		result = v7(a1, a2, a3, *((uint32_t*)v3 + 1));
		if (!result || !v6 && result < 0) {
			return result;
		}
		goto LABEL_17;
	}
	v9 = a1 + *((uint32_t*)v3 + 1);
	(*(void (**)(int))(*(uint32_t*)v9 + 4))(v9);
	*a3 = v9;
	return 0;
}

//----- (0040E990) --------------------------------------------------------
void sub_40E990(uint32_t* a1) {
	uint32_t* v1; // esi
	uint32_t* v2; // edi

	v1 = a1;
	v2 = a1 + 1;
	*a1 = getMemAt(0x581450, 6116);
	a1[1] = 1;
	InterlockedDecrement((volatile int*)getMemAt(0x5D4594, 4696));
}

//----- (0040EE10) --------------------------------------------------------
int nox_xxx_netSendBySock_40EE10(unsigned int a1, int a2, unsigned int a3) {
	unsigned char* v3; // eax

	v3 = nox_netlist_copyPacketList_40ED60(a2, a3, &a3);
	if (v3) {
		nox_xxx_netSendSock_552640(a1, v3, a3, 0);
		nox_xxx_netSendReadPacket_5528B0(a1, 1);
	}
	return 1;
}

//----- (004100F0) --------------------------------------------------------
int nox_xxx_cliCanTalkMB_4100F0(short* a1) {
	short v1;  // ax
	short* v2; // ecx

	v1 = *a1;
	v2 = a1 + 1;
	if (!*a1) {
		return 1;
	}
	while (!HIBYTE(v1)) {
		v1 = *v2;
		++v2;
		if (!v1) {
			return 1;
		}
	}
	return 0;
}

//----- (00410250) --------------------------------------------------------
void* nox_xxx_wallCreateAt_410250(int a1, int a2) {
	void* result; // eax
	int v3;       // edx
	int v4;       // eax
	int v5;       // eax
	int v6;       // esi

	if (a1 < 0 || a1 >= 256 || a2 < 0 || a2 >= 256) {
		return 0;
	}
	result = (void*)nox_server_getWallAtGrid_410580(a1, a2);
	if (result) {
		return result;
	}
	v3 = dword_5d4594_251548;
	if (!dword_5d4594_251548) {
		return 0;
	}
	dword_5d4594_251548 = *(uint32_t*)((uint32_t)dword_5d4594_251548 + 20);
	memset((void*)v3, 0, 0x24u);
	*(uint8_t*)(v3 + 6) = a2;
	*(uint8_t*)(v3 + 5) = a1;
	v4 = ((uint16_t)a2 + ((uint16_t)a1 << 8)) & 0x1FFF;
	*(uint32_t*)(v3 + 16) = dword_5D4594_251544[v4];
	dword_5D4594_251544[v4] = v3;
	*(uint32_t*)(v3 + 20) = dword_5d4594_251552;
	dword_5d4594_251552 = v3;
	v5 = *(uint32_t*)(dword_5d4594_251556 + 4 * a2);
	if (v5) {
		v6 = 0;
		while (*(uint8_t*)(v3 + 5) >= *(uint8_t*)(v5 + 5)) {
			v6 = v5;
			v5 = *(uint32_t*)(v5 + 24);
			if (!v5) {
				*(uint32_t*)(v6 + 24) = v3;
				*(uint32_t*)(v3 + 24) = 0;
				return (void*)v3;
			}
		}
		if (v6) {
			*(uint32_t*)(v6 + 24) = v3;
		} else {
			*(uint32_t*)(dword_5d4594_251556 + 4 * a2) = v3;
		}
		*(uint32_t*)(v3 + 24) = v5;
		result = (void*)v3;
	} else {
		*(uint32_t*)(dword_5d4594_251556 + 4 * a2) = v3;
		*(uint32_t*)(v3 + 24) = 0;
		result = (void*)v3;
	}
	return result;
}

//----- (00410360) --------------------------------------------------------
uint8_t* nox_xxx_doorAttachWall_410360(int a1, int a2, int a3) {
	uint8_t* result; // eax
	char v4;         // cl

	result = nox_xxx_wallCreateAt_410250(a2, a3);
	if (result) {
		v4 = result[4] | 0x10;
		*((uint32_t*)result + 7) = a1;
		result[4] = v4;
	}
	return result;
}

//----- (00410390) --------------------------------------------------------
uint32_t* sub_410390(int a1, int a2, int a3) {
	uint32_t* v3;     // esi
	uint32_t* result; // eax
	int v5;           // edx
	char v6;          // cl
	int v7[2];        // [esp+Ch] [ebp-8h]

	v3 = (uint32_t*)nox_xxx_wall_4105E0(a2, a3);
	if (v3 || (result = nox_xxx_wallCreateAt_410250(a2, a3), (v3 = result) != 0)) {
		v5 = *(uint32_t*)(a1 + 16);
		v7[0] = *(uint32_t*)(a1 + 12);
		v6 = *((uint8_t*)v3 + 4);
		v3[8] = a1;
		v7[1] = v5;
		*((uint8_t*)v3 + 4) = v6 | 0x10;
		result = nox_xxx_polygonIsPlayerInPolygon_4217B0((int2*)v7, 0);
		if (result || (result = sub_421990((int2*)v7, 10.0, 0)) != 0) {
			*((uint8_t*)v3 + 8) = *((uint8_t*)result + 130);
		} else {
			*((uint8_t*)v3 + 8) = 1;
		}
	}
	return result;
}

//----- (00410430) --------------------------------------------------------
uint32_t* nox_xxx_mapDelWallAtPt_410430(int a1, int a2) {
	int v2;           // ecx
	uint32_t* v3;     // esi
	uint32_t* result; // eax
	uint32_t* v5;     // ecx
	uint32_t* v6;     // edx
	int v7;           // esi
	int v8;           // eax

	v2 = ((uint16_t)a2 + ((uint16_t)a1 << 8)) & 0x1FFF;
	v3 = 0;
	result = (uint32_t*)(dword_5D4594_251544[v2]);
	if (result) {
		while (*((unsigned char*)result + 5) != a1 || *((unsigned char*)result + 6) != a2) {
			v3 = result;
			result = (uint32_t*)result[4];
			if (!result) {
				return result;
			}
		}
		if (v3) {
			v3[4] = result[4];
		} else {
			dword_5D4594_251544[v2] = result[4];
		}
		v5 = *(uint32_t**)&dword_5d4594_251552;
		v6 = 0;
		if (!dword_5d4594_251552) {
			goto LABEL_24;
		}
		do {
			if (v5 == result) {
				break;
			}
			v6 = v5;
			v5 = (uint32_t*)v5[5];
		} while (v5);
		if (v6) {
			v6[5] = v5[5];
		} else {
		LABEL_24:
			dword_5d4594_251552 = v5[5];
		}
		v7 = 0;
		v8 = *(uint32_t*)(dword_5d4594_251556 + 4 * a2);
		if (!v8) {
			goto LABEL_25;
		}
		do {
			if (*(unsigned char*)(v8 + 5) == a1 && *(unsigned char*)(v8 + 6) == a2) {
				break;
			}
			v7 = v8;
			v8 = *(uint32_t*)(v8 + 24);
		} while (v8);
		if (v7) {
			*(uint32_t*)(v7 + 24) = v5[6];
			result = *(uint32_t**)&dword_5d4594_251548;
			v5[5] = dword_5d4594_251548;
			dword_5d4594_251548 = v5;
		} else {
		LABEL_25:
			*(uint32_t*)(dword_5d4594_251556 + 4 * a2) = v5[6];
			result = *(uint32_t**)&dword_5d4594_251548;
			v5[5] = dword_5d4594_251548;
			dword_5d4594_251548 = v5;
		}
	}
	return result;
}

//----- (00410520) --------------------------------------------------------
int* nox_xxx_wallDestroyedByWallid_410520(short a1) {
	int* result; // eax
	int v2;      // ecx

	result = (int*)nox_xxx_wallGetFirstBreakableCli_410870();
	if (result) {
		while (1) {
			v2 = result[1];
			if (*(uint16_t*)(v2 + 10) == a1) {
				break;
			}
			result = (int*)nox_xxx_wallGetNextBreakableCli_410880(result);
			if (!result) {
				return result;
			}
		}
		*(uint8_t*)(v2 + 4) |= 0x20u;
	}
	return result;
}

//----- (00410550) --------------------------------------------------------
int sub_410550(short a1) {
	int* v1; // eax

	v1 = (int*)nox_xxx_wallSecretGetFirstWall_410780();
	if (!v1) {
		return 0;
	}
	while (*(uint16_t*)(v1[3] + 10) != a1) {
		v1 = (int*)nox_xxx_wallSecretNext_410790(v1);
		if (!v1) {
			return 0;
		}
	}
	return v1[3];
}

//----- (00410640) --------------------------------------------------------
int nox_xxx_wallForeachFn_410640(void (*a1)(int, int), int a2) {
	int result; // eax
	int v3;     // esi

	result = dword_5d4594_251552;
	if (dword_5d4594_251552) {
		do {
			v3 = *(uint32_t*)(result + 20);
			if (!(*(uint8_t*)(result + 4) & 0x30)) {
				a1(result, a2);
			}
			result = v3;
		} while (v3);
	}
	return result;
}

//----- (004106A0) --------------------------------------------------------
int sub_4106A0(int a1) {
	int result; // eax

	if (a1 < 0 || a1 >= 256) {
		result = 0;
	} else {
		result = *(uint32_t*)(dword_5d4594_251556 + 4 * a1);
	}
	return result;
}

//----- (004106C0) --------------------------------------------------------
void sub_4106C0() {
	uint32_t* v1; // eax
	uint32_t* v2; // esi
	uint32_t* v3; // eax
	uint32_t* v4; // esi

	for (int i = 0; i < 8192; i++) {
		v1 = dword_5D4594_251544[i];
		if (v1) {
			do {
				v2 = (uint32_t*)v1[4];
				free(v1);
				v1 = v2;
			} while (v2);
		}
	}
	v3 = *(uint32_t**)&dword_5d4594_251548;
	if (dword_5d4594_251548) {
		do {
			v4 = (uint32_t*)v3[5];
			free(v3);
			v3 = v4;
		} while (v4);
	}
	free(dword_5D4594_251544);
	free(*(void**)&dword_5d4594_251556);
}

//----- (00410730) --------------------------------------------------------
uint32_t* sub_410730() {
	uint32_t* result; // eax
	uint32_t* v1;     // esi

	result = *(uint32_t**)&dword_5d4594_251560;
	if (dword_5d4594_251560) {
		do {
			v1 = (uint32_t*)*result;
			free(result);
			result = v1;
		} while (v1);
		dword_5d4594_251560 = 0;
	} else {
		dword_5d4594_251560 = 0;
	}
	return result;
}

//----- (00410760) --------------------------------------------------------
uint32_t* nox_xxx_wallSecretBlock_410760(uint32_t* a1) {
	uint32_t* result; // eax

	result = a1;
	*a1 = dword_5d4594_251560;
	dword_5d4594_251560 = a1;
	return result;
}

//----- (00410780) --------------------------------------------------------
void* nox_xxx_wallSecretGetFirstWall_410780() { return *(void**)&dword_5d4594_251560; }

//----- (00410790) --------------------------------------------------------
int nox_xxx_wallSecretNext_410790(int* a1) {
	int result; // eax

	if (a1) {
		result = *a1;
	} else {
		result = 0;
	}
	return result;
}

//----- (004107A0) --------------------------------------------------------
int* sub_4107A0(void* lpMem) {
	int* result; // eax
	int* v2;     // esi

	result = *(int**)&dword_5d4594_251560;
	v2 = 0;
	if (dword_5d4594_251560) {
		while (result != lpMem) {
			v2 = result;
			result = (int*)nox_xxx_wallSecretNext_410790(result);
			if (!result) {
				return result;
			}
		}
		if (result == *(int**)&dword_5d4594_251560) {
			dword_5d4594_251560 = nox_xxx_wallSecretNext_410790(result);
		} else {
			*v2 = nox_xxx_wallSecretNext_410790(result);
		}
		free(lpMem);
	}
	return result;
}

//----- (00410810) --------------------------------------------------------
uint32_t* nox_xxx_wallBreackableListClear_410810() {
	uint32_t* result; // eax
	uint32_t* v1;     // esi

	result = *(uint32_t**)&dword_5d4594_251564;
	if (dword_5d4594_251564) {
		do {
			v1 = (uint32_t*)*result;
			free(result);
			result = v1;
		} while (v1);
		dword_5d4594_251564 = 0;
	} else {
		dword_5d4594_251564 = 0;
	}
	return result;
}

//----- (00410840) --------------------------------------------------------
uint32_t* nox_xxx_wallBreackableListAdd_410840(int a1) {
	uint32_t* result; // eax

	result = calloc(1u, 8u);
	result[1] = a1;
	*result = dword_5d4594_251564;
	dword_5d4594_251564 = result;
	return result;
}

//----- (00410870) --------------------------------------------------------
void* nox_xxx_wallGetFirstBreakableCli_410870() { return *(void**)&dword_5d4594_251564; }

//----- (00410880) --------------------------------------------------------
int nox_xxx_wallGetNextBreakableCli_410880(int* a1) {
	int result; // eax

	if (a1) {
		result = *a1;
	} else {
		result = 0;
	}
	return result;
}

//----- (00410900) --------------------------------------------------------
int nox_thing_read_WALL_410900(nox_memfile* f, char* a2) {
	char* v4;          // ebx
	int v7;            // ecx
	int v9;            // ecx
	int v11;           // ecx
	int v14;           // ebp
	char v15;          // dl
	int v16;           // edi
	unsigned char v22; // cl
	int v23;           // eax
	int v24;           // ebp
	int v25;           // eax
	int v26;           // edi
	unsigned int v27;  // ecx
	int v29;           // edx
	int v31;           // edx
	int v33;           // edx
	int v39;           // [esp+10h] [ebp-10h]
	int v40;           // [esp+14h] [ebp-Ch]
	int v41;           // [esp+18h] [ebp-8h]
	int i;             // [esp+1Ch] [ebp-4h]
	unsigned char v43; // [esp+24h] [ebp+4h]
	unsigned char v44; // [esp+24h] [ebp+4h]
	unsigned char v45; // [esp+24h] [ebp+4h]
	unsigned char v46; // [esp+24h] [ebp+4h]
	unsigned char v47; // [esp+24h] [ebp+4h]
	unsigned int v48;  // [esp+28h] [ebp+8h]
	unsigned int v49;  // [esp+28h] [ebp+8h]

	if (dword_5d4594_251540 >= 80) {
		return 0;
	}
	v4 = a2;
	nox_memfile_skip(f, 4);
	v43 = nox_memfile_read_u8(f);
	nox_memfile_read(a2, 1u, v43, f);
	a2[v43] = 0;
	strncpy((char*)getMemAt(0x85B3FC, 43044 + 12332 * dword_5d4594_251540), a2, 0x1Fu);
	v7 = nox_memfile_read_i32(f);
	*getMemU32Ptr(0x85B3FC, 43076 + 12332 * dword_5d4594_251540) = v7;
	v9 = nox_memfile_read_i32(f);
	*getMemU16Ptr(0x85B3FC, 43080 + 12332 * dword_5d4594_251540) = v9;
	v11 = nox_memfile_read_i32(f);
	*getMemU16Ptr(0x85B3FC, 43082 + 12332 * dword_5d4594_251540) = v11;
	LOBYTE(v11) = nox_memfile_read_u8(f);
	*getMemU8Ptr(0x85B3FC, 43084 + 12332 * dword_5d4594_251540) = v11;
	LOBYTE(v11) = nox_memfile_read_u8(f);
	*getMemU8Ptr(0x85B3FC, 43085 + 12332 * dword_5d4594_251540) = v11;
	nox_memfile_read64align_40AD60((char*)&v39, 1, 1, f);
	v15 = v39;
	v16 = 12332 * dword_5d4594_251540;
	*getMemU8Ptr(0x85B3FC, 43086 + v16) = v39;
	memset(getMemAt(0x85B3FC, 43087 + v16), 0, 0x200u);
	if (v15) {
		v14 = 0;
		v48 = 0;
		while (1) {
			if ((int)v48 >= 512) {
				return 0;
			}
			v44 = nox_memfile_read_u8(f);
			nox_memfile_read(v4, 1u, v44, f);
			v4[v44] = 0;
			strncpy((char*)getMemAt(0x85B3FC, 43087 + 12332 * dword_5d4594_251540 + v48), v4, 0x40u);
			++v14;
			v48 += 64;
			if (v14 >= (unsigned char)v39) {
				break;
			}
		}
	}
	v45 = nox_memfile_read_u8(f);
	nox_memfile_read(v4, 1u, v45, f);
	v4[v45] = 0;
	strncpy((char*)getMemAt(0x85B3FC, 43599 + 12332 * dword_5d4594_251540), v4, 0x40u);
	v46 = nox_memfile_read_u8(f);
	nox_memfile_read(v4, 1u, v46, f);
	v4[v46] = 0;
	strncpy((char*)getMemAt(0x85B3FC, 43663 + 12332 * dword_5d4594_251540), v4, 0x40u);
	v47 = nox_memfile_read_u8(f);
	nox_memfile_read(v4, 1u, v47, f);
	v4[v47] = 0;
	strncpy((char*)getMemAt(0x85B3FC, 43727 + 12332 * dword_5d4594_251540), v4, 0x40u);
	v22 = nox_memfile_read_u8(f);
	v23 = 12332 * dword_5d4594_251540;
	*getMemU8Ptr(0x85B3FC, 43793 + v23) = v22;
	v24 = 0;
	memset(getMemAt(0x85B3FC, 51476 + v23), 0, 0xF00u);
	v49 = 0;
	do {
		nox_memfile_read64align_40AD60((char*)&v40, 1, 1, f);
		v25 = 0;
		i = (unsigned char)v40;
		for (v41 = 0; v41 < i; ++v41) {
			v26 = 0;
			v27 = 8 * (v25 + v49);
			do {
				*getMemU8Ptr(0x85B3FC, 55316 + 12332 * dword_5d4594_251540 + v26 + v24) = v40;
				v29 = nox_memfile_read_i32(f);
				*getMemU32Ptr(0x85B3FC, 43796 + 12332 * dword_5d4594_251540 + v27) = v29;
				v31 = nox_memfile_read_i32(f);
				*getMemU32Ptr(0x85B3FC, 43800 + 12332 * dword_5d4594_251540 + v27) = v31;
				v33 = nox_memfile_read_i32(f);
				if (v33 == -1) {
					nox_memfile_skip(f, 1);
					unsigned char v = nox_memfile_read_u8(f);
					nox_memfile_skip(f, v);
				}
				v26 += 15;
				v27 += 1920;
			} while (v26 < 60);
			v25 = v41 + 1;
		}
		++v24;
		v49 += 16;
	} while ((int)v49 < 240);
	unsigned int v37 = nox_memfile_read_i32(f);
	if (v37 != 0x454E4420) { // 'END '
		return 0;
	}
	++dword_5d4594_251540; // max ~80
	return 1;
}

//----- (00410D40) --------------------------------------------------------
char* sub_410D40(int a1) { return (char*)getMemAt(0x85B3FC, 43044 + 12332 * a1); }

//----- (00410D60) --------------------------------------------------------
int nox_xxx_wallTileByName_410D60(const char* a1) {
	int v1;        // ebp
	const char* i; // edi

	v1 = 0;
	if (dword_5d4594_251540 <= 0) {
		return -1;
	}
	for (i = (const char*)getMemAt(0x85B3FC, 43044); strcmp(a1, i); i += 12332) {
		if (++v1 >= dword_5d4594_251540) {
			return -1;
		}
	}
	return v1;
}

//----- (00410DD0) --------------------------------------------------------
unsigned char nox_xxx_mapWallMaxVariation_410DD0(int a1, int a2, int a3) {
	return getMemByte(0x85B3FC, 55316 + 12332 * a1 + 12 * a3 + 3 * a3 + a2);
}

//----- (00410E00) --------------------------------------------------------
unsigned char nox_xxx_map_410E00(int a1) { return getMemByte(0x85B3FC, 43793 + 12332 * a1); }

//----- (00410E20) --------------------------------------------------------
unsigned char nox_xxx_mapWallGetHpByTile_410E20(int a1) { return getMemByte(0x85B3FC, 43085 + 12332 * a1); }

//----- (00410E40) --------------------------------------------------------
unsigned char nox_xxx_wallGetBrickTypeMB_410E40(int a1) { return getMemByte(0x85B3FC, 43086 + 12332 * a1); }

//----- (00410E60) --------------------------------------------------------
char* nox_xxx_wallGetBrickObj_410E60(int a1, int a2) {
	char* result; // eax

	result = (char*)getMemAt(0x587000, 26432);
	if (strlen((const char*)getMemAt(0x85B3FC, 43087 + 12332 * a1 + 64 * a2))) {
		result = (char*)getMemAt(0x85B3FC, 43087 + 12332 * a1 + 64 * a2);
	}
	return result;
}

//----- (00410EA0) --------------------------------------------------------
char* nox_xxx_wallSoundByTile_410EA0(int a1) {
	char* result; // eax

	result = (char*)getMemAt(0x587000, 26440);
	if (strlen((const char*)getMemAt(0x85B3FC, 43727 + 12332 * a1))) {
		result = (char*)getMemAt(0x85B3FC, 43727 + 12332 * a1);
	}
	return result;
}

//----- (00410EE0) --------------------------------------------------------
char* nox_xxx_wallFindOpenSound_410EE0(int a1) {
	char* result; // eax

	result = (char*)getMemAt(0x587000, 26456);
	if (strlen((const char*)getMemAt(0x85B3FC, 43599 + 12332 * a1))) {
		result = (char*)getMemAt(0x85B3FC, 43599 + 12332 * a1);
	}
	return result;
}

//----- (00410F20) --------------------------------------------------------
char* nox_xxx_wallFindCloseSound_410F20(int a1) {
	char* result; // eax

	result = (char*)getMemAt(0x587000, 26472);
	if (strlen((const char*)getMemAt(0x85B3FC, 43663 + 12332 * a1))) {
		result = (char*)getMemAt(0x85B3FC, 43663 + 12332 * a1);
	}
	return result;
}

//----- (00410F60) --------------------------------------------------------
int nox_xxx_tileAlloc_410F60_init() {
	ptr_5D4594_2650668 = calloc(ptr_5D4594_2650668_cap, sizeof(void*));
	if (!ptr_5D4594_2650668) {
		return 0;
	}

	for (int i = 0; i < ptr_5D4594_2650668_cap; i++) {
		ptr_5D4594_2650668[i] = (obj_5D4594_2650668_t*)calloc(ptr_5D4594_2650668_cap, sizeof(obj_5D4594_2650668_t));
		if (!ptr_5D4594_2650668[i]) {
			return 0;
		}
	}
	return 1;
}

//----- (00410FC0) --------------------------------------------------------
void nox_xxx_tileFree_410FC0_free() {
	for (int i = 0; i < ptr_5D4594_2650668_cap; i++) {
		obj_5D4594_2650668_t* ptr = ptr_5D4594_2650668[i];
		if (ptr) {
			free(ptr);
		}
	}
}

//----- (00411160) --------------------------------------------------------
int nox_xxx_tileNFromPoint_411160(float2* a1) {
	float v12 = (a1->field_0 + 11.5) * 0.021739131;
	float v13 = (a1->field_4 + 11.5) * 0.021739131;

	int i = nox_float2int(v12);
	int j = nox_float2int(v13);

	float v14 = a1->field_0 + 11.5;
	float v15 = a1->field_4 + 11.5;

	int v4 = nox_float2int(v14) % 46;
	int v5 = nox_float2int(v15) % 46;

	if (i - 1 <= 0 || i >= 127 || j - 1 <= 0 || j >= 127) {
		return -1;
	}

	int result = 0;
	int v16[2] = {0};
	if (v4 <= v5) {
		if (46 - v4 <= v5) {
			obj_5D4594_2650668_t* obj = &ptr_5D4594_2650668[i][j];
			result = obj->field_6;
			if (obj->field_10) {
				v16[0] = v4;
				v16[1] = v5 - 23;
				result = sub_411350(obj->field_10, v16, result);
			}
		} else {
			obj_5D4594_2650668_t* obj = &ptr_5D4594_2650668[i - 1][j];
			result = obj->field_1;
			if (obj->field_5) {
				v16[1] = v5;
				v16[0] = v4 + 23;
				result = sub_411350(obj->field_5, v16, result);
			}
		}
	} else if (46 - v4 <= v5) {
		obj_5D4594_2650668_t* obj = &ptr_5D4594_2650668[i][j];
		result = obj->field_1;
		if (obj->field_5) {
			v16[1] = v5;
			v16[0] = v4 - 23;
			result = sub_411350(obj->field_5, v16, result);
		}
	} else {
		obj_5D4594_2650668_t* obj = &ptr_5D4594_2650668[i][j - 1];
		result = obj->field_6;
		if (obj->field_10) {
			v16[0] = v4;
			v16[1] = v5 + 23;
			result = sub_411350(obj->field_10, v16, result);
		}
	}
	return result;
}

//----- (00411350) --------------------------------------------------------
int sub_411350(int* a1, int* a2, int a3) {
	int* v3; // esi
	int v4;  // ebx
	int v5;  // eax

	v3 = a1;
	if (!a1) {
		return a3;
	}
	v4 = a3;
	do {
		v5 = sub_411490(v3[2], v3[3]);
		if (sub_4113A0(a2, v5)) {
			v4 = *v3;
		}
		v3 = (int*)v3[4];
	} while (v3);
	return v4;
}

//----- (004113A0) --------------------------------------------------------
int sub_4113A0(int* a1, int a2) {
	int v2 = *a1;
	int v3 = a1[1];

	bool v4;
	bool v5;
	if (*a1 == v3) {
		v4 = 1;
		v5 = 1;
	} else if (*a1 >= v3) {
		v4 = 1;
		v5 = 0;
	} else {
		v4 = 0;
		v5 = 1;
	}

	bool v6;
	bool v7;
	if (v2 == 46 - v3) {
		v6 = 1;
		v7 = 1;
	} else if (v2 >= 46 - v3) {
		v6 = 1;
		v7 = 0;
	} else {
		v6 = 0;
		v7 = 1;
	}

	switch (a2) {
	case 0:
		if (!v5 || !v6) {
			return 0;
		}
		return 1;
	case 1:
		if (!v5) {
			return 0;
		}
		return 1;
	case 2:
		if (!v5 || !v7) {
			return 0;
		}
		return 1;
	case 3:
		if (!v6) {
			return 0;
		}
		return 1;
	case 4:
		if (!v7) {
			return 0;
		}
		return 1;
	case 5:
		if (!v6 || !v4) {
			return 0;
		}
		return 1;
	case 6:
		if (!v4) {
			return 0;
		}
		return 1;
	case 7:
		if (!v4 || !v7) {
			return 0;
		}
		return 1;
	case 8:
		if (v5) {
			return 1;
		}
		if (!v6) {
			return 0;
		}
		return 1;
	case 9:
		if (!v5 && !v7) {
			return 0;
		}
		return 1;
	case 10:
		if (!v4 && !v7) {
			return 0;
		}
		return 1;
	case 11:
		if (v4) {
			return 1;
		}
		if (!v6) {
			return 0;
		}
		return 1;
	}
	return 0;
}

//----- (00411490) --------------------------------------------------------
int sub_411490(int a1, int a2) {
	int v2; // ecx
	int v3; // edx
	int v5; // esi

	v2 = getMemByte(0x85B3FC, 28696 + 60 * a1);
	v3 = getMemByte(0x85B3FC, 28697 + 60 * a1);
	if (v2 == 3 && v3 == 3) {
		return a2;
	}
	if (!a2) {
		return 0;
	}
	if (a2 <= v2 - 2) {
		return 1;
	}
	if (a2 == v2 - 1) {
		return 2;
	}
	v5 = v2 + 2 * v3 - 4;
	if (a2 < v5) {
		return ((((unsigned char)v2 ^ (unsigned char)a2) & 1) != 0) + 3;
	}
	if (a2 == v5) {
		return 5;
	} else if (a2 > 2 * (v3 + v2) - 6) {
		if (a2 == 2 * (v3 + v2) - 5) {
			return 7;
		}
		return a2 + 2 * (6 - v3 - v2);
	}
	return 6;
}

//----- (00411540) --------------------------------------------------------
int nox_thing_read_FLOR_411540(nox_memfile* f, uint8_t* a2) {
	int v5;            // eax
	char v7;           // cl
	char v8;           // dl
	char v9;           // dl
	int v22;           // ecx
	int v23;           // edx
	int v24;           // ecx
	int v26;           // ecx
	uint8_t v29[6];    // [esp+0h] [ebp-28h]
	int v30;           // [esp+0h] [ebp-28h]
	char v31[32];      // [esp+8h] [ebp-20h]
	unsigned char v32; // [esp+2Ch] [ebp+4h]
	unsigned char v33; // [esp+2Ch] [ebp+4h]

	if (dword_5d4594_251568 >= 176) {
		return 0;
	}
	nox_memfile_skip(f, 4);
	v32 = nox_memfile_read_u8(f);
	nox_memfile_read(v31, 1, v32, f);
	v31[v32] = 0;
	v5 = 3 * dword_5d4594_251568;
	strncpy((char*)getMemAt(0x85B3FC, 32484 + 20 * v5), v31, 0x1Fu);
	v7 = nox_memfile_read_i8(f);
	v29[0] = v7;
	v8 = nox_memfile_read_i8(f);
	v29[1] = v8;
	v9 = nox_memfile_read_i8(f);
	v29[2] = v9;
	if (v7 != -1 || v29[1] || v9 != -1) {
		*getMemU32Ptr(0x85B3FC, 32532 + 60 * dword_5d4594_251568) =
			nox_color_rgb_4344A0(*(int*)v29, *(int*)&v29[1], *(int*)&v29[2]);
	} else {
		*getMemU32Ptr(0x85B3FC, 32532 + 60 * dword_5d4594_251568) = 2147483648;
	}
	*getMemU8Ptr(0x85B3FC, 32542 + 60 * dword_5d4594_251568) = 0;
	if (nox_xxx_checkFacade_4117E0((const char*)getMemAt(0x85B3FC, 32484 + 60 * dword_5d4594_251568)) == 1) {
		*getMemU8Ptr(0x85B3FC, 32542 + 60 * dword_5d4594_251568) |= 1u;
	}

	*getMemU32Ptr(0x85B3FC, 32520 + 60 * dword_5d4594_251568) = nox_memfile_read_i32(f);
	*getMemU32Ptr(0x85B3FC, 32524 + 60 * dword_5d4594_251568) = nox_memfile_read_i32(f);

	uint8_t v14 = nox_memfile_read_u8(f);
	*getMemU8Ptr(0x85B3FC, 32541 + 60 * dword_5d4594_251568) = v14;
	v14 = nox_memfile_read_u8(f);
	*getMemU8Ptr(0x85B3FC, 32537 + 60 * dword_5d4594_251568) = v14;
	v14 = nox_memfile_read_u8(f);
	*getMemU8Ptr(0x85B3FC, 32536 + 60 * dword_5d4594_251568) = v14;
	v14 = nox_memfile_read_u8(f);
	*getMemU8Ptr(0x85B3FC, 32538 + 60 * dword_5d4594_251568) = v14;
	*getMemU16Ptr(0x85B3FC, 32530 + 60 * dword_5d4594_251568) = 0;
	v14 = nox_memfile_read_u8(f);
	*getMemU8Ptr(0x85B3FC, 32539 + 60 * dword_5d4594_251568) = v14;
	*getMemU8Ptr(0x85B3FC, 32540 + 60 * dword_5d4594_251568) = v14;
	*getMemU16Ptr(0x85B3FC, 32528 + 60 * dword_5d4594_251568) =
		getMemByte(0x85B3FC, 32536 + 60 * dword_5d4594_251568) * getMemByte(0x85B3FC, 32537 + 60 * dword_5d4594_251568);
	v22 =
		getMemByte(0x85B3FC, 32537 + 60 * dword_5d4594_251568) * getMemByte(0x85B3FC, 32538 + 60 * dword_5d4594_251568);
	v23 = getMemByte(0x85B3FC, 32536 + 60 * dword_5d4594_251568);
	*getMemU32Ptr(0x85B3FC, 32516 + 60 * dword_5d4594_251568) = 0;
	v24 = v23 * v22;
	if (v24 > 0) {
		v30 = v24;
		do {
			v26 = nox_memfile_read_i32(f);
			*a2 = getMemByte(0x5D4594, 251576);
			if (v26 == -1) {
				nox_memfile_skip(f, 1);
				v33 = nox_memfile_read_u8(f);
				nox_memfile_read(a2, 1, v33, f);
				a2[v33] = 0;
			}
			--v30;
		} while (v30);
	}
	++dword_5d4594_251568;
	return 1;
}
// 411618: variable 'v29' is possibly undefined
// 411540: using guessed type char var_20[32];

//----- (004117E0) --------------------------------------------------------
int nox_xxx_checkFacade_4117E0(const char* a1) {
	const char* v1;    // eax
	unsigned char* v2; // edi

	v1 = *(const char**)getMemAt(0x587000, 26488);
	if (!*getMemU32Ptr(0x587000, 26488)) {
		return 0;
	}
	v2 = getMemAt(0x587000, 26488);
	while (strcmp(v1, a1)) {
		v1 = (const char*)*((uint32_t*)v2 + 1);
		v2 += 4;
		if (!v1) {
			return 0;
		}
	}
	return 1;
}

//----- (00411850) --------------------------------------------------------
int nox_thing_read_EDGE_411850(nox_memfile* f, uint8_t* a2) {
	int v5;            // eax
	int v7;            // ecx
	int v9;            // ecx
	int v12;           // eax
	int v14;           // eax
	unsigned char v17; // dl
	unsigned char v19; // bl
	int v20;           // ecx
	int v21;           // ebx
	int v23;           // ecx
	int v26;           // ecx
	unsigned char v28; // [esp+14h] [ebp-24h]
	char v29[32];      // [esp+18h] [ebp-20h]
	unsigned char v30; // [esp+3Ch] [ebp+4h]
	unsigned char v31; // [esp+3Ch] [ebp+4h]

	if (dword_5d4594_251572 >= 64) {
		return 0;
	}
	nox_memfile_skip(f, 4);
	v30 = nox_memfile_read_u8(f);
	nox_memfile_read(v29, 1u, v30, f);
	v5 = 3 * dword_5d4594_251572;
	v29[v30] = 0;
	strcpy((char*)getMemAt(0x85B3FC, 28644 + 20 * v5), v29);
	v7 = nox_memfile_read_i32(f);
	*getMemU32Ptr(0x85B3FC, 28680 + 60 * dword_5d4594_251572) = v7;
	v9 = nox_memfile_read_i32(f);
	*getMemU32Ptr(0x85B3FC, 28684 + 60 * dword_5d4594_251572) = v9;
	LOBYTE(v9) = nox_memfile_read_u8(f);
	*getMemU8Ptr(0x85B3FC, 28701 + 60 * dword_5d4594_251572) = v9;
	LOBYTE(v9) = nox_memfile_read_u8(f);
	v28 = v9;
	v12 = 60 * dword_5d4594_251572;
	*getMemU8Ptr(0x85B3FC, 28698 + v12) = v9;
	*getMemU16Ptr(0x85B3FC, 28690 + v12) = 0;
	LOBYTE(v9) = nox_memfile_read_u8(f);
	v14 = 60 * dword_5d4594_251572;
	*getMemU8Ptr(0x85B3FC, 28699 + v14) = v9;
	*getMemU8Ptr(0x85B3FC, 28700 + v14) = v9;
	LOBYTE(v9) = nox_memfile_read_u8(f);
	if ((uint8_t)v9 == 1) {
		return 0;
	}
	v17 = nox_memfile_read_u8(f);
	*getMemU8Ptr(0x85B3FC, 28697 + 60 * dword_5d4594_251572) = v17;
	v19 = nox_memfile_read_u8(f);
	v20 = 60 * dword_5d4594_251572;
	*getMemU8Ptr(0x85B3FC, 28696 + v20) = v19;
	*getMemU16Ptr(0x85B3FC, 28688 + v20) = 2 * (v17 + v19);
	*getMemU32Ptr(0x85B3FC, 28676 + v20) = 0;
	if (2 * v28 * (v17 + v19) > 0) {
		v21 = 2 * v28 * (v17 + v19);
		do {
			v23 = nox_memfile_read_i32(f);
			*a2 = getMemByte(0x5D4594, 251580);
			if (v23 == -1) {
				nox_memfile_skip(f, 1);
				v31 = nox_memfile_read_u8(f);
				nox_memfile_read(a2, 1u, v31, f);
				a2[v31] = 0;
			}
			--v21;
		} while (v21);
	}
	v26 = nox_memfile_read_i32(f);
	if (v26 != 0x454E4420) { // "END "
		return 0;
	}
	++dword_5d4594_251572;
	return 1;
}
// 411850: using guessed type char var_20[32];

//----- (00411A90) --------------------------------------------------------
int nox_xxx_mapTileAllowTeleport_411A90(float2* a1) {
	int v1;         // edx
	const char* v2; // eax
	int v3;         // eax

	if (*getMemIntPtr(0x587000, 26520) == -1) {
		v1 = 0;
		v2 = (const char*)getMemAt(0x85B3FC, 32484);
		do {
			if (!strcmp(v2, "WaterNoTeleport")) {
				*getMemU32Ptr(0x587000, 26516) = v1;
			} else if (!strcmp(v2, "WaterDeepNoTeleport")) {
				*getMemU32Ptr(0x587000, 26520) = v1;
			} else if (!strcmp(v2, "WaterShallowNoTeleport")) {
				*getMemU32Ptr(0x587000, 26524) = v1;
			} else if (!strcmp(v2, "WaterSwampDeepNoTeleport")) {
				*getMemU32Ptr(0x587000, 26528) = v1;
			} else if (!strcmp(v2, "WaterSwampShallowNoTeleport")) {
				*getMemU32Ptr(0x587000, 26532) = v1;
			}
			v2 += 60;
			++v1;
		} while ((int)v2 < (int)getMemAt(0x85B3FC, 43044));
	}
	v3 = nox_xxx_tileNFromPoint_411160(a1);
	return v3 == *getMemU32Ptr(0x587000, 26516) || v3 == *getMemU32Ptr(0x587000, 26520) ||
		   v3 == *getMemU32Ptr(0x587000, 26524) || v3 == *getMemU32Ptr(0x587000, 26528) ||
		   v3 == *getMemU32Ptr(0x587000, 26532);
}

//----- (00411C40) --------------------------------------------------------
int nox_xxx_parseWeapColor_411C40(const char* a1, char* a2, int a3) {
	int v3;     // eax
	int result; // eax

	v3 = sub_411C80(a1);
	if (v3 == -1) {
		result = 0;
	} else {
		result = nox_xxx_parseBinColor_411CF0(a2, (uint8_t*)(a3 + 2 * (v3 + 4) + v3 + 4)) != 0;
	}
	return result;
}

//----- (00411C80) --------------------------------------------------------
int sub_411C80(const char* a1) {
	const char* v1;    // ecx
	int v2;            // ebp
	unsigned char* v3; // edi

	v1 = *(const char**)getMemAt(0x587000, 31096);
	v2 = 0;
	if (!*getMemU32Ptr(0x587000, 31096)) {
		return -1;
	}
	v3 = getMemAt(0x587000, 31096);
	while (strcmp(v1, a1)) {
		v1 = (const char*)*((uint32_t*)v3 + 1);
		v3 += 4;
		++v2;
		if (!v1) {
			return -1;
		}
	}
	return v2;
}

//----- (00411CF0) --------------------------------------------------------
char* nox_xxx_parseBinColor_411CF0(char* a1, uint8_t* a2) {
	char* result; // eax
	char v3;      // bl
	char v4;      // al
	char v5[8];   // [esp+4h] [ebp-8h]
	char v6;      // [esp+10h] [ebp+4h]

	strcpy(v5, " =\t\n\r");
	result = strtok(a1, v5);
	if (result) {
		v6 = atoi(result);
		result = strtok(0, v5);
		if (result) {
			v3 = atoi(result);
			result = strtok(0, v5);
			if (result) {
				v4 = atoi(result);
				a2[1] = v3;
				a2[2] = v4;
				*a2 = v6;
				result = (char*)1;
			}
		}
	}
	return result;
}

//----- (00411D90) --------------------------------------------------------
int sub_411D90(const char* a1, char* a2, int a3) {
	char* v3;   // eax
	int v4;     // esi
	int v5;     // eax
	char v7[8]; // [esp+Ch] [ebp-8h]

	strcpy(v7, " =\n\r\t");
	v3 = strtok(a2, v7);
	if (v3) {
		if (!strcmp(a1, "EFFECTIVENESS")) {
			v4 = 0;
		LABEL_10:
			v5 = sub_411C80(v3);
			*(uint32_t*)(a3 + 4 * v4 + 36) = v5;
			return v5 != -1;
		}
		if (!strcmp(a1, "MATERIAL")) {
			v4 = 1;
			goto LABEL_10;
		}
		if (!strcmp(a1, "PRIMARYENCHANTMENT")) {
			v4 = 2;
			goto LABEL_10;
		}
		if (!strcmp(a1, "SECONDARYENCHANTMENT")) {
			v4 = 3;
			goto LABEL_10;
		}
	}
	return 0;
}

//----- (00411E60) --------------------------------------------------------
int sub_411E60(int a1, char* a2, int a3) {
	size_t v3;  // edx
	int result; // eax
	int v5;     // [esp+8h] [ebp-4h]

	v5 = 0;
	v3 = strspn(a2, "= ");
	if (v3 >= strlen(a2)) {
		*(uint8_t*)(a3 + 62) = v5;
		result = 1;
	} else {
		set_bitmask_flags_from_plus_separated_names_423930(&a2[v3], &v5, (const char**)getMemAt(0x587000, 29456));
		result = 1;
		*(uint8_t*)(a3 + 62) = v5;
	}
	return result;
}

//----- (00411ED0) --------------------------------------------------------
char* sub_411ED0(int a1, char* a2, int a3) {
	char* result; // eax
	char v4[8];   // [esp+0h] [ebp-8h]

	strcpy(v4, " =\n\r\t");
	result = strtok(a2, v4);
	if (result) {
		*(uint32_t*)(a3 + 52) = atoi(result);
		result = (char*)1;
	}
	return result;
}

//----- (00411F20) --------------------------------------------------------
char* sub_411F20(int a1, char* a2, int a3) {
	char* result; // eax
	char v4[8];   // [esp+0h] [ebp-8h]

	strcpy(v4, " =\n\r\t");
	result = strtok(a2, v4);
	if (result) {
		*(uint16_t*)(a3 + 60) = atoi(result);
		result = (char*)1;
	}
	return result;
}

//----- (00411F70) --------------------------------------------------------
char* sub_411F70(int a1, char* a2, int a3) {
	char* result; // eax
	char v4[8];   // [esp+0h] [ebp-8h]

	strcpy(v4, " =\n\r\t");
	result = strtok(a2, v4);
	if (result) {
		*(uint16_t*)(a3 + 72) = atoi(result);
		result = (char*)1;
	}
	return result;
}

//----- (00411FC0) --------------------------------------------------------
char* sub_411FC0(int a1, char* a2, int a3) {
	char* result; // eax
	double v4;    // st7
	char v5[8];   // [esp+0h] [ebp-8h]

	strcpy(v5, " =\n\r\t");
	result = strtok(a2, v5);
	if (result) {
		v4 = atof(result);
		result = (char*)1;
		*(float*)(a3 + 64) = v4;
	}
	return result;
}

//----- (00412010) --------------------------------------------------------
const char* nox_xxx_parseWeapDamageType_412010(int a1, char* a2, int a3) {
	const char* result; // eax
	int v4;             // eax
	char v5[8];         // [esp+0h] [ebp-8h]

	strcpy(v5, " =\n\r\t");
	result = strtok(a2, v5);
	if (result) {
		v4 = nox_xxx_parseDamageTypeByName_4E0A00(result);
		*(uint32_t*)(a3 + 76) = v4;
		result = (const char*)(v4 != 18);
	}
	return result;
}

//----- (00412060) --------------------------------------------------------
char* sub_412060(int a1, char* a2, int a3) {
	char* result; // eax
	double v4;    // st7
	char v5[8];   // [esp+0h] [ebp-8h]

	strcpy(v5, " =\n\r\t");
	result = strtok(a2, v5);
	if (result) {
		v4 = atof(result);
		result = (char*)1;
		*(float*)(a3 + 68) = v4;
	}
	return result;
}

//----- (004120B0) --------------------------------------------------------
char* sub_4120B0(int a1, char* a2, int a3) {
	char* result; // eax
	double v4;    // st7
	char v5[8];   // [esp+0h] [ebp-8h]

	strcpy(v5, " =\n\r\t");
	result = strtok(a2, v5);
	if (result) {
		v4 = atof(result);
		result = (char*)1;
		*(float*)(a3 + 64) = v4;
	}
	return result;
}

//----- (00412310) --------------------------------------------------------
int nox_xxx_parseEnchWorth_412310_parse_worth(const char* a1, char* a2, obj_412ae0_t* a3) {
	char* result; // eax
	char v4[8];   // [esp+0h] [ebp-8h]

	strcpy(v4, " =\n\r\t");
	result = strtok(a2, v4);
	if (!result) {
		return 0;
	}
	a3->field_5 = atoi(result);
	return 1;
}

//----- (00412360) --------------------------------------------------------
int nox_xxx_parseEnchColor_412360_parse_color(const char* a1, char* a2, obj_412ae0_t* a3) {
	return nox_xxx_parseBinColor_411CF0(a2, (uint8_t*)(&a3->field_6)) != 0;
}

//----- (00412380) --------------------------------------------------------
int nox_xxx_parseEnchEffect_412380_parse_attack_effect(const char* a1, char* a2, obj_412ae0_t* obj) {
	char v9[8];
	strcpy(v9, " \n\r\t=");
	char* v3 = strtok(a2, v9);
	if (!v3) {
		return 0;
	}
	//	if (!table_26792)
	//		return 0;

	table_26792_t* ent = 0;
	for (int i = 0; i < table_26792_cnt; i++) {
		if (strcmp(table_26792[i].name, v3) == 0) {
			ent = &table_26792[i];
			break;
		}
	}
	if (!ent) {
		return 0;
	}

	if (!strcmp(a1, "ATTACKEFFECT")) {
		obj->field_10 = ent->fnc;
	} else if (!strcmp(a1, "ATTACKPREHITEFFECT")) {
		obj->field_13 = ent->fnc;
	} else {
		if (strcmp(a1, "ATTACKPREDAMAGEEFFECT")) {
			return 0;
		}
		obj->field_16 = ent->fnc;
	}
	if (ent->parse_fnc && !ent->parse_fnc(a1, a2, obj)) {
		return 0;
	}
	return 1;
}

//----- (00412490) --------------------------------------------------------
int nox_xxx_parseEnchDefend_412490_parse_defend_effect(const char* a1, char* a2, obj_412ae0_t* obj) {
	char v9[8];
	strcpy(v9, " \n\r\t=");
	char* v3 = strtok(a2, v9);
	if (!v3) {
		return 0;
	}

	table_27008_t* ent = 0;
	//	if (!table_27008)
	//		return 0;
	for (int i = 0; i < table_27008_cnt; i++) {
		if (strcmp(table_27008[i].name, v3) == 0) {
			ent = &table_27008[i];
			break;
		}
	}
	if (!ent) {
		return 0;
	}
	if (!strcmp(a1, "DEFENDEFFECT")) {
		obj->field_19 = ent->fnc;
	} else {
		if (strcmp(a1, "DEFENDCOLLIDEEFFECT")) {
			return 0;
		}
		obj->field_22 = ent->fnc;
	}
	if (ent->parse_fnc && !ent->parse_fnc(a1, a2, obj)) {
		return 0;
	}
	return 1;
}

//----- (00412580) --------------------------------------------------------
int nox_xxx_parseEnchEngageOrDisEng_412580_parse_engage_effect(const char* a1, char* a2, obj_412ae0_t* obj) {
	char v9[8];
	strcpy(v9, " =\n\r\t");
	char* v3 = strtok(a2, v9);
	if (!v3) {
		return 0;
	}
	//	if (!table_27168)
	//		return 0;

	table_27168_t* ent = 0;
	for (int i = 0; i < table_27168_cnt; i++) {
		if (strcmp(table_27168[i].name, v3) == 0) {
			ent = &table_27168[i];
			break;
		}
	}
	if (!ent) {
		return 0;
	}
	if (!strcmp(a1, "ENGAGEEFFECT")) {
		obj->field_28 = ent->fnc;
	} else {
		if (strcmp(a1, "DISENGAGEEFFECT")) {
			return 0;
		}
		obj->field_29 = ent->fnc;
	}
	if (ent->parse_fnc && !ent->parse_fnc(a1, a2, obj)) {
		return 0;
	}
	return 1;
}

//----- (00412670) --------------------------------------------------------
int nox_xxx_parseEnchUpdate_412670_parse_update_effect(const char* a1, char* a2, obj_412ae0_t* obj) {
	char v8[8];
	strcpy(v8, " =\n\r\t");
	char* v3 = strtok(a2, v8);
	if (!v3) {
		return 0;
	}
	//	if (!table_27104)
	//		return 0;

	table_27104_t* ent = 0;
	for (int i = 0; i < table_27104_cnt; i++) {
		if (strcmp(table_27104[i].name, v3) == 0) {
			ent = &table_27104[i];
			break;
		}
	}
	if (!ent) {
		return 0;
	}

	if (strcmp(a1, "UPDATEEFFECT")) {
		return 0;
	}
	obj->field_25 = ent->fnc;
	if ((ent->parse_fnc == 0) || ent->parse_fnc(a1, a2, obj)) {
		return 1;
	}
	return 0;
}

//----- (00412740) --------------------------------------------------------
int nox_xxx_parseEnchAllowedWeapon_412740_parse_allowed_weapons(const char* a1, char* a2, obj_412ae0_t* a3) {
	a3->field_7 = 0;
	return nox_xxx_parseAllowedWeaponArmor_412760(a2, &a3->field_7);
}

//----- (00412760) --------------------------------------------------------
int nox_xxx_parseAllowedWeaponArmor_412760(char* a1, int* a2) {
	char* v2;          // eax
	int* v4;           // ebx
	const char* v5;    // ecx
	int v6;            // edx
	int v7;            // ebp
	unsigned char* v8; // edi
	int v9;            // eax
	char* v10;         // eax
	int v11;           // [esp+10h] [ebp-Ch]
	char v12[8];       // [esp+14h] [ebp-8h]

	strcpy(v12, " =\r\n\t");
	v11 = 1;
	v2 = strtok(a1, v12);
	if (v2) {
		v4 = a2;
		while (1) {
			v5 = *(const char**)getMemAt(0x587000, 28904);
			v6 = 0;
			v7 = 0;
			if (*getMemU32Ptr(0x587000, 28904)) {
				v8 = getMemAt(0x587000, 28904);
				while (strcmp(v5, v2)) {
					v5 = (const char*)*((uint32_t*)v8 + 2);
					v8 += 8;
					++v7;
					if (!v5) {
						v4 = a2;
						v6 = 0;
						goto LABEL_10;
					}
				}
				v6 = *getMemU32Ptr(0x587000, 28908 + 8 * v7);
				v4 = a2;
			}
		LABEL_10:
			if (!*getMemU32Ptr(0x587000, 28904 + 8 * v7)) {
				break;
			}
			if (v11 == 1) {
				v9 = v6 | *v4;
			} else {
				v9 = ~v6 & *v4;
			}
			*v4 = v9;
			v10 = strtok(0, v12);
			if (v10) {
				if (!strcmp(v10, "+")) {
					v11 = 1;
				} else {
					if (strcmp(v10, "-")) {
						return 0;
					}
					v11 = 0;
				}
				v2 = strtok(0, v12);
				if (v2) {
					continue;
				}
			}
			return 1;
		}
	}
	return 0;
}

//----- (004128A0) --------------------------------------------------------
int nox_xxx_parseEnchAllowedArmor_4128A0_parse_allowed_armor(const char* a1, char* a2, obj_412ae0_t* a3) {
	a3->field_8 = 0;
	return nox_xxx_parseAllowedWeaponArmor_412760(a2, &a3->field_8);
}

//----- (004128C0) --------------------------------------------------------
int nox_xxx_parseAllowedPosition_4128C0_parse_allowed_pos(const char* a1, char* a2, obj_412ae0_t* a3) {
	size_t v3; // edx
	int v5;    // [esp+8h] [ebp-4h]

	v5 = 0;
	v3 = strspn(a2, "= ");
	if (v3 >= strlen(a2)) {
		*(uint8_t*)(&a3->field_9) = v5;
		return 1;
	}
	set_bitmask_flags_from_plus_separated_names_423930(&a2[v3], &v5, (const char**)getMemAt(0x587000, 26776));
	*(uint8_t*)(&a3->field_9) = v5;
	return 1;
}

//----- (00412930) --------------------------------------------------------
int nox_xxx_parseModifierBin_412930(char* a1, char* a2) {
	FILE* v2;      // eax
	FILE* v3;      // ebx
	char v10[256]; // [esp+10h] [ebp-100h]

	byte_5D4594_251584[0] = 0;
	byte_5D4594_251584[1] = 0;
	byte_5D4594_251584[2] = 0;
	byte_5D4594_251596 = 0;
	dword_5d4594_251600 = 0;
	*getMemU32Ptr(0x5D4594, 251604) = 0;
	dword_5d4594_251608 = 0;
	*getMemU32Ptr(0x5D4594, 251612) = 0;
	v2 = nox_binfile_open_408CC0(a1, 0);
	v3 = v2;
	if (!v2) {
		return 0;
	}
	if (!nox_binfile_cryptSet_408D40((int)v2, 13)) {
		return 0;
	}
	while (nox_xxx_parseString_409470(v3, v10)) {
		if (!strcmp(v10, "WEAPON_DEFINITIONS")) {
			if (!nox_xxx_parseWeaponDef_412D40((int)v10, v3, a2)) {
				return 0;
			}
		} else if (!strcmp(v10, "ARMOR_DEFINITIONS")) {
			if (!sub_412ED0((int)v10, v3, a2)) {
				return 0;
			}
		} else if (strcmp(v10, "EFFECTIVENESS") && strcmp(v10, "MATERIAL") && strcmp(v10, "ENCHANTMENT") ||
				   !nox_xxx_parseModifDesc_412AE0(v10, v3, a2)) {
			return 0;
		}
	}
	nox_binfile_close_408D90(v3);
	for (void* i = sub_413370(); i; i = (void*)sub_413380((int)i)) {
		;
	}
	for (void* j = sub_413390(); j; j = (void*)sub_4133A0((int)j)) {
		;
	}
	int v7 = 0;
	for (int k = 0; k < 3; k++) {
		for (obj_412ae0_t* l = nox_xxx_modifGetModifListByType_4133B0(k); l; l = nox_xxx_modifNext_4133C0(l)) {
			++v7;
		}
	}
	return 1;
}

//----- (00412AE0) --------------------------------------------------------
int nox_xxx_parseModifDesc_412AE0(const char* a1, FILE* a2, char* a3) {
	char v9[256];

	while (1) {
		nox_xxx_parseString_409470(a2, v9);
		if (!strcmp(v9, "END")) {
			return 1;
		}
		obj_412ae0_t* v3 = (obj_412ae0_t*)calloc(1, sizeof(obj_412ae0_t));
		if (!v3) {
			return 0;
		}
		v3->field_1 = byte_5D4594_251596++;
		if (!nox_xxx_parseModifAddByType_412C60(a1, v3)) {
			return 0;
		}
		char* v5 = (char*)calloc(strlen(v9) + 1, 1);
		if (!v5) {
			return 0;
		}
		strcpy(v5, v9);
		v3->field_0 = v5;
		while (1) {
			nox_xxx_parseString_409470(a2, v9);
			if (!strcmp(v9, "END")) {
				break;
			}
			table_28760_t* v6 = &table_28760[0];
			if (v6->parse_fnc) {
				while (strcmp(v6->name, v9)) {
					v6++;
					if (!v6->parse_fnc) {
						goto LABEL_12;
					}
				}
				nox_xxx_parseRead_4093E0(a2, a3, 0x40000);
				if (!v6->parse_fnc(v9, a3, v3)) {
					return 0;
				}
			}
		LABEL_12:
			if (!*((uint32_t*)v6 + 1)) {
				return 0;
			}
		}
	}
}

//----- (00412C60) --------------------------------------------------------
int nox_xxx_parseModifAddByType_412C60(const char* a1, obj_412ae0_t* a2) {
	if (!strcmp(a1, "EFFECTIVENESS")) {
		a2->field_35 = 0;
		a2->field_34 = byte_5D4594_251584[0];
		if (byte_5D4594_251584[0]) {
			byte_5D4594_251584[0]->field_35 = a2;
		}
		byte_5D4594_251584[0] = a2;
	} else if (!strcmp(a1, "MATERIAL")) {
		a2->field_35 = 0;
		a2->field_34 = byte_5D4594_251584[1];
		if (byte_5D4594_251584[1]) {
			byte_5D4594_251584[1]->field_35 = a2;
		}
		byte_5D4594_251584[1] = a2;
	} else if (!strcmp(a1, "ENCHANTMENT")) {
		a2->field_35 = 0;
		a2->field_34 = byte_5D4594_251584[2];
		if (byte_5D4594_251584[2]) {
			byte_5D4594_251584[2] = a2;
		}
		byte_5D4594_251584[2] = a2;
	} else {
		return 0;
	}
	return 1;
}

//----- (00412D40) --------------------------------------------------------
int nox_xxx_parseWeaponDef_412D40(int a1, FILE* a2, char* a3) {
	char** v3;         // eax
	char** v4;         // ebp
	char* v5;          // edx
	unsigned char* v6; // edi
	int v7;            // eax
	char v9[256];      // [esp+Ch] [ebp-100h]

	while (1) {
		nox_xxx_parseString_409470(a2, v9);
		if (!strcmp(v9, "END")) {
			return 1;
		}
		v3 = (char**)calloc(1u, 0x58u);
		v4 = v3;
		if (!v3) {
			return 0;
		}
		v3[21] = 0;
		v3[20] = *(char**)&dword_5d4594_251600;
		if (dword_5d4594_251600) {
			*(uint32_t*)(dword_5d4594_251600 + 84) = v3;
		}
		++*getMemU32Ptr(0x5D4594, 251604);
		dword_5d4594_251600 = v3;
		v5 = (char*)calloc(strlen(v9) + 1, 1);
		*v4 = v5;
		if (!v5) {
			return 0;
		}
		strcpy(v5, v9);
		while (1) {
			nox_xxx_parseString_409470(a2, v9);
			if (!strcmp(v9, "END")) {
				break;
			}
			v6 = getMemAt(0x587000, 28600);
			if (*getMemU32Ptr(0x587000, 28604)) {
				while (strcmp(*(const char**)v6, v9)) {
					v7 = *((uint32_t*)v6 + 3);
					v6 += 8;
					if (!v7) {
						goto LABEL_13;
					}
				}
				nox_xxx_parseRead_4093E0(a2, a3, 0x40000);
				if (!(*((int (**)(char*, char*, char**))v6 + 1))(v9, a3, v4)) {
					return 0;
				}
			}
		LABEL_13:
			if (!*((uint32_t*)v6 + 1)) {
				return 0;
			}
		}
	}
}

//----- (00412ED0) --------------------------------------------------------
int sub_412ED0(int a1, FILE* a2, char* a3) {
	char** v3;         // eax
	char** v4;         // ebp
	char* v5;          // edx
	unsigned char* v6; // edi
	int v7;            // eax
	char v9[256];      // [esp+Ch] [ebp-100h]

	while (1) {
		nox_xxx_parseString_409470(a2, v9);
		if (!strcmp(v9, "END")) {
			return 1;
		}
		v3 = (char**)calloc(1u, 0x58u);
		v4 = v3;
		if (!v3) {
			return 0;
		}
		v3[21] = 0;
		v3[20] = *(char**)&dword_5d4594_251608;
		if (dword_5d4594_251608) {
			*(uint32_t*)(dword_5d4594_251608 + 84) = v3;
		}
		++*getMemU32Ptr(0x5D4594, 251612);
		dword_5d4594_251608 = v3;
		v5 = (char*)calloc(strlen(v9) + 1, 1);
		*v4 = v5;
		if (!v5) {
			return 0;
		}
		strcpy(v5, v9);
		while (1) {
			nox_xxx_parseString_409470(a2, v9);
			if (!strcmp(v9, "END")) {
				break;
			}
			v6 = getMemAt(0x587000, 28600);
			if (*getMemU32Ptr(0x587000, 28604)) {
				while (strcmp(*(const char**)v6, v9)) {
					v7 = *((uint32_t*)v6 + 3);
					v6 += 8;
					if (!v7) {
						goto LABEL_13;
					}
				}
				nox_xxx_parseRead_4093E0(a2, a3, 0x40000);
				if (!(*((int (**)(char*, char*, char**))v6 + 1))(v9, a3, v4)) {
					return 0;
				}
			}
		LABEL_13:
			if (!*((uint32_t*)v6 + 1)) {
				return 0;
			}
		}
	}
}

//----- (00413060) --------------------------------------------------------
void nox_xxx_freeWeaponArmorDefAndModifs_413060() {
	sub_4130C0(*(void**)&dword_5d4594_251600);
	dword_5d4594_251600 = 0;
	*getMemU32Ptr(0x5D4594, 251604) = 0;
	sub_413100(*(void**)&dword_5d4594_251608);
	dword_5d4594_251608 = 0;
	*getMemU32Ptr(0x5D4594, 251612) = 0;
	for (int i = 0; i < 3; i++) {
		nox_xxx_modifFreeOne_413140(byte_5D4594_251584[i]);
		byte_5D4594_251584[i] = 0;
	}
	byte_5D4594_251596 = 0;
}

//----- (004130C0) --------------------------------------------------------
void sub_4130C0(void* lpMem) {
	void* v1; // esi
	void* v2; // edi

	v1 = lpMem;
	if (lpMem) {
		do {
			v2 = (void*)*((uint32_t*)v1 + 20);
			if (*(uint32_t*)v1) {
				free(*(void**)v1);
			}
			if (*((uint32_t*)v1 + 2)) {
				free(*((void**)v1 + 2));
			}
			free(v1);
			v1 = v2;
		} while (v2);
	}
}

//----- (00413100) --------------------------------------------------------
void sub_413100(void* lpMem) {
	void* v1; // esi
	void* v2; // edi

	v1 = lpMem;
	if (lpMem) {
		do {
			v2 = (void*)*((uint32_t*)v1 + 20);
			if (*(uint32_t*)v1) {
				free(*(void**)v1);
			}
			if (*((uint32_t*)v1 + 2)) {
				free(*((void**)v1 + 2));
			}
			free(v1);
			v1 = v2;
		} while (v2);
	}
}

//----- (00413140) --------------------------------------------------------
void nox_xxx_modifFreeOne_413140(void* lpMem) {
	void* v1; // esi
	void* v2; // edi

	v1 = lpMem;
	if (lpMem) {
		do {
			v2 = (void*)*((uint32_t*)v1 + 34);
			if (*(uint32_t*)v1) {
				free(*(void**)v1);
			}
			if (*((uint32_t*)v1 + 2)) {
				free(*((void**)v1 + 2));
			}
			if (*((uint32_t*)v1 + 3)) {
				free(*((void**)v1 + 3));
			}
			free(v1);
			v1 = v2;
		} while (v2);
	}
}

//----- (00413250) --------------------------------------------------------
uint32_t* nox_xxx_getProjectileClassById_413250(int a1) {
	uint32_t* result; // eax

	result = *(uint32_t**)&dword_5d4594_251600;
	if (!dword_5d4594_251600) {
		return 0;
	}
	while (result[1] != a1) {
		result = (uint32_t*)result[20];
		if (!result) {
			return 0;
		}
	}
	return result;
}

//----- (00413270) --------------------------------------------------------
uint32_t* nox_xxx_equipClothFindDefByTT_413270(int a1) {
	uint32_t* result; // eax

	result = *(uint32_t**)&dword_5d4594_251608;
	if (!dword_5d4594_251608) {
		return 0;
	}
	while (result[1] != a1) {
		result = (uint32_t*)result[20];
		if (!result) {
			return 0;
		}
	}
	return result;
}

//----- (00413290) --------------------------------------------------------
int nox_xxx_modifGetIdByName_413290(const char* a1) {
	if (!a1) {
		return 255;
	}
	for (int i = 0; i < 3; i++) {
		for (obj_412ae0_t* it = byte_5D4594_251584[i]; it; it = it->field_34) {
			if (strcmp(it->field_0, a1) == 0) {
				return it->field_1;
			}
		}
	}
	return 255;
}

//----- (00413330) --------------------------------------------------------
obj_412ae0_t* nox_xxx_modifGetDescById_413330(int a1) {
	if (a1 == 255) {
		return 0;
	}
	for (int i = 0; i < 3; i++) {
		for (obj_412ae0_t* it = byte_5D4594_251584[i]; it; it = it->field_34) {
			if (it->field_1 == a1) {
				return it;
			}
		}
	}
	return 0;
}

//----- (00413370) --------------------------------------------------------
void* sub_413370() { return *(void**)&dword_5d4594_251600; }

//----- (00413380) --------------------------------------------------------
int sub_413380(int a1) { return *(uint32_t*)(a1 + 80); }

//----- (00413390) --------------------------------------------------------
void* sub_413390() { return *(void**)&dword_5d4594_251608; }

//----- (004133A0) --------------------------------------------------------
int sub_4133A0(int a1) { return *(uint32_t*)(a1 + 80); }

//----- (004133B0) --------------------------------------------------------
obj_412ae0_t* nox_xxx_modifGetModifListByType_4133B0(int a1) { return byte_5D4594_251584[a1]; }

//----- (004133C0) --------------------------------------------------------
obj_412ae0_t* nox_xxx_modifNext_4133C0(obj_412ae0_t* a1) { return a1->field_34; }

//----- (004133D0) --------------------------------------------------------
int sub_4133D0(int a1) {
	int v1; // eax
	int v2; // esi
	int v3; // eax

	v1 = *getMemU32Ptr(0x5D4594, 251620);
	v2 = *(uint32_t*)(a1 + 692);
	if (!*getMemU32Ptr(0x5D4594, 251620)) {
		v3 = nox_xxx_modifGetIdByName_413290("Material7");
		v1 = nox_xxx_modifGetDescById_413330(v3);
		*getMemU32Ptr(0x5D4594, 251620) = v1;
	}
	return *(uint32_t*)(a1 + 8) & 0x13001000 && *(uint32_t*)(v2 + 4) == v1;
}

//----- (00413420) --------------------------------------------------------
int sub_413420(char a1) {
	unsigned char* v1; // esi
	int v2;            // ecx
	unsigned char* v3; // eax

	if (!*getMemU32Ptr(0x5D4594, 251624)) {
		v1 = getMemAt(0x587000, 27340);
		do {
			*(uint32_t*)v1 = nox_xxx_gLoadImg_42F970(*((const char**)v1 - 1));
			v1 += 20;
		} while ((int)v1 < (int)getMemAt(0x587000, 27460));
		*getMemU32Ptr(0x5D4594, 251624) = 1;
	}
	v2 = 0;
	v3 = getMemAt(0x587000, 27332);
	while (*v3 != a1) {
		v3 += 20;
		++v2;
		if ((int)v3 >= (int)getMemAt(0x587000, 27452)) {
			return 0;
		}
	}
	return *getMemU32Ptr(0x587000, 27340 + 20 * v2);
}

//----- (004134D0) --------------------------------------------------------
int sub_4134D0() {
	dword_5d4594_251708 = 0;
	dword_5d4594_251712 = 0;
	dword_5d4594_251716 = 0;
	dword_5d4594_251720 = 0;
	return 0;
}

//----- (004137E0) --------------------------------------------------------
int sub_4137E0() {
	int result; // eax

	result = dword_5d4594_251720;
	if (dword_5d4594_251720) {
		dword_5d4594_251720 = 0;
		result = sub_43DBE0();
	}
	return result;
}

//----- (00413890) --------------------------------------------------------
char* sub_413890() {
	unsigned char* v0; // edi
	int v1;            // ecx
	short v2;          // dx
	unsigned char v3;  // al

	*getMemU8Ptr(0x5D4594, 251636) = 0;
	*getMemU8Ptr(0x5D4594, 251637) = 0;
	if (!getMemByte(0x5D4594, 251636)) {
		return 0;
	}
	v0 = getMemAt(0x5D4594, 251637 + strlen((const char*)getMemAt(0x5D4594, 251636)));
	v1 = *getMemU32Ptr(0x587000, 32316);
	v2 = *getMemU16Ptr(0x587000, 32320);
	*(uint32_t*)--v0 = *getMemU32Ptr(0x587000, 32312);
	v3 = getMemByte(0x587000, 32322);
	*((uint32_t*)v0 + 1) = v1;
	*((uint16_t*)v0 + 4) = v2;
	v0[10] = v3;
	return (char*)getMemAt(0x5D4594, 251636);
}

//----- (004138E0) --------------------------------------------------------
void sub_4138E0(int a1) {
	*getMemU32Ptr(0x5D4594, 251740) = nox_xxx_checkGameFlagPause_413A50();
	sub_413A00(1);
}

//----- (00413900) --------------------------------------------------------
void sub_413900(int a1) {
	if (!nox_video_inFadeTransition_44E0D0()) {
		if (!*getMemU32Ptr(0x5D4594, 251740)) {
			sub_413A00(0);
		}
	}
}

//----- (00413920) --------------------------------------------------------
int sub_413920() {
	sub_42EBB0(1u, sub_413900, 0, "Pause");
	sub_42EBB0(2u, sub_4138E0, 0, "Pause");
	dword_5d4594_251744 = 0;
	return 1;
}

//----- (004139B0) --------------------------------------------------------
int sub_4139B0() { return dword_5d4594_251744 != 0; }

//----- (00413A50) --------------------------------------------------------
int nox_xxx_checkGameFlagPause_413A50() { return nox_common_gameFlags_check_40A5C0(0x40000); }

//----- (00413E30) --------------------------------------------------------
void nox_xxx_gameLoopMemDump_413E30() {
	signed int v0;     // ebx
	int v1;            // esi
	unsigned char* v2; // eax
	int v3;            // edx
	signed int v4;     // edi
	const char* v5;    // ebp
	unsigned char* v6; // eax
	signed int v7;     // ecx
	int v8;            // ebx
	signed int v9;     // [esp+8h] [ebp-8h]

	v0 = 0;
	v1 = 0;
	v9 = 0;
	v2 = getMemAt(0x5D4594, 252364);
	do {
		*(uint32_t*)v2 = 0;
		v2 += 84;
	} while ((int)v2 < (int)getMemAt(0x5D4594, 338380));
	v3 = *getMemU32Ptr(0x5D4594, 338304);
	if (*getMemU32Ptr(0x5D4594, 338304)) {
		do {
			v4 = 0;
			if (v0 > 0) {
				v5 = (const char*)getMemAt(0x5D4594, 252284);
				while (strcmp(v5, (const char*)(v3 + 20))) {
					v0 = v9;
					++v4;
					v5 += 84;
					if (v4 >= v9) {
						goto LABEL_10;
					}
				}
				v0 = v9;
				*getMemU32Ptr(0x5D4594, 252364 + 84 * v4) += *(uint32_t*)(v3 + 16);
			}
		LABEL_10:
			if (v4 == v0) {
				*getMemU32Ptr(0x5D4594, 252364 + 84 * v4) = *(uint32_t*)(v3 + 16);
				strcpy((char*)getMemAt(0x5D4594, 252284 + 84 * v4), (const char*)(v3 + 20));
				v9 = ++v0;
			}
			v3 = *(uint32_t*)(v3 + 4);
		} while (v3);
		v1 = 0;
	}
	qsort(getMemAt(0x5D4594, 252284), v0, 0x54u, sub_413F60);
	if (v0 > 0) {
		v6 = getMemAt(0x5D4594, 252364);
		v7 = v0;
		do {
			v8 = *(uint32_t*)v6;
			v6 += 84;
			v1 += v8;
			--v7;
		} while (v7);
	}
}

//----- (00413F60) --------------------------------------------------------
int sub_413F60(const void* a1, const void* a2) { return *((uint32_t*)a1 + 20) - *((uint32_t*)a2 + 20); }

//----- (00413F90) --------------------------------------------------------
char* nox_clone_str(const char* a1) {
	char* result; // eax

	result = (char*)calloc(strlen(a1) + 1, 1);
	if (result) {
		strcpy(result, a1);
	}
	return result;
}

//----- (00414BD0) --------------------------------------------------------
int sub_414BD0(signed int a1) {
	signed int v1; // ecx

	v1 = a1;
	if (a1 < 0) {
		v1 = a1 + 25736 * ((25735 - a1) / 0x6488u);
	}
	if (v1 >= 25736) {
		v1 %= 0x6488u;
	}
	return *getMemU32Ptr(0x85B3FC, 12260 + 4 * ((v1 << 12) / 25736));
}

//----- (00414C50) --------------------------------------------------------
int sub_414C50(signed int a1) {
	int v1;     // edi
	int v2;     // eax
	int result; // eax

	v1 = sub_414BD0(a1);
	v2 = sub_414BD0(6434 - a1);
	if (v2) {
		result = (v1 << 12) / v2;
	} else {
		result = (v1 <= 0) + 0x7FFFFFFF;
	}
	return result;
}

//----- (00414C90) --------------------------------------------------------
char nox_xxx_initSinCosTables_414C90() {
	long long v0;      // rax
	unsigned char* v1; // esi
	unsigned char* v2; // esi
	int v4;            // [esp+0h] [ebp-4h]
	int v5;            // [esp+0h] [ebp-4h]

	LOBYTE(v0) = getMemByte(0x5D4594, 371240);
	if (!getMemByte(0x5D4594, 371240)) {
		*getMemU8Ptr(0x5D4594, 371240) = 1;
		v4 = 0;
		v1 = getMemAt(0x85B3FC, 12260);
		do {
			*(uint32_t*)v1 = (long long)(sin((double)v4 * 0.0015339808) * *getMemDoublePtr(0x581450, 7200));
			v1 += 4;
			++v4;
		} while ((int)v1 < (int)getMemAt(0x85B3FC, 28644));
		v5 = 0;
		v2 = getMemAt(0x5D4594, 338472);
		do {
			v0 = (long long)(acos((double)v5 * 0.00024414062 - 1.0) * *getMemDoublePtr(0x581450, 7184));
			*(uint32_t*)v2 = v0;
			v2 += 4;
			++v5;
		} while ((int)v2 < (int)getMemAt(0x5D4594, 371240));
	}
	return v0;
}

//----- (00414D40) --------------------------------------------------------
int nox_thing_skip_AUD_414D40(nox_memfile* f) {
	int v2;           // edx
	int v3;           // esi
	unsigned char v5; // dl

	v2 = nox_memfile_read_i32(f);
	if (v2 <= 0) {
		return 1;
	}
	v3 = v2;
	do {
		v5 = nox_memfile_read_u8(f);
		nox_memfile_skip(f, v5 + 9);
		while (1) {
			v5 = nox_memfile_read_u8(f);
			if (!v5) {
				break;
			}
			nox_memfile_skip(f, v5);
		}
		--v3;
	} while (v3);
	return 1;
}

//----- (00414DB0) --------------------------------------------------------
int nox_thing_read_FLOR_414DB0(nox_memfile* f) {
	unsigned char* v2;  // ecx
	unsigned char* v3;  // ecx
	unsigned char* v4;  // esi
	int v5;             // edx
	int v6;             // ecx
	int* v7;            // edx
	int v8;             // esi
	int v9;             // edx
	unsigned char* v10; // edx
	int* v11;           // ecx
	int v12;            // edx
	unsigned char v14;  // [esp+8h] [ebp+4h]
	unsigned char v15;  // [esp+8h] [ebp+4h]

	v2 = (unsigned char*)(f->cur + 4);
	f->cur = v2;
	v3 = &v2[*v2 + 13];
	f->cur = v3;
	v4 = (unsigned char*)(f->cur + 1);
	v14 = *v3;
	f->cur = v4;
	v15 = *v4;
	f->cur = v4 + 1;
	v4 += 3;
	v5 = v14 * v15;
	v14 = *(v4 - 2);
	f->cur = v4;
	v6 = v5 * v14;
	if (v6 > 0) {
		do {
			v7 = f->cur;
			v8 = *v7;
			v9 = (int)(v7 + 1);
			f->cur = v9;
			if (v8 == -1) {
				v10 = (unsigned char*)(v9 + 1);
				f->cur = v10;
				f->cur += *v10 + 1;
			}
			--v6;
		} while (v6);
	}
	v11 = f->cur;
	v12 = *v11;
	f->cur = v11 + 1;
	return v12 == 1162757152;
}

//----- (00414E70) --------------------------------------------------------
int nox_thing_read_EDGE_414E70(nox_memfile* f, void* a2) {
	int a1 = f;
	int v2;             // esi
	unsigned char* v3;  // edx
	unsigned char* v4;  // eax
	unsigned char v5;   // cl
	unsigned char v6;   // cl
	unsigned char* v7;  // eax
	unsigned char v9;   // dl
	unsigned char* v10; // eax
	int v11;            // eax
	int* v12;           // ecx
	int v13;            // edx
	int v14;            // ecx
	unsigned char* v15; // ecx
	int* v16;           // eax
	int v17;            // ecx
	int v18;            // [esp-4h] [ebp-10h]
	unsigned char v19;  // [esp+8h] [ebp-4h]
	unsigned char v20;  // [esp+10h] [ebp+4h]
	unsigned char v21;  // [esp+14h] [ebp+8h]

	v2 = a1;
	v18 = a1;
	v3 = (unsigned char*)(*(uint32_t*)(a1 + 8) + 4);
	*(uint32_t*)(a1 + 8) = v3;
	v20 = *v3;
	*(uint32_t*)(v2 + 8) = v3 + 1;
	nox_memfile_read(a2, 1u, v20, v18);
	v4 = (unsigned char*)(*(uint32_t*)(v2 + 8) + 9);
	*(uint32_t*)(v2 + 8) = v4;
	v5 = *v4;
	v4 += 2;
	v19 = v5;
	*(uint32_t*)(v2 + 8) = v4;
	v6 = *v4;
	v7 = v4 + 1;
	*(uint32_t*)(v2 + 8) = v7;
	if (v6 == 1) {
		return 0;
	}
	v9 = *v7;
	v10 = v7 + 1;
	*(uint32_t*)(v2 + 8) = v10;
	v21 = *v10;
	*(uint32_t*)(v2 + 8) = v10 + 1;
	v11 = 2 * v19 * (v9 + v21);
	if (v11 > 0) {
		do {
			v12 = *(int**)(v2 + 8);
			v13 = *v12;
			v14 = (int)(v12 + 1);
			*(uint32_t*)(v2 + 8) = v14;
			if (v13 == -1) {
				v15 = (unsigned char*)(v14 + 1);
				*(uint32_t*)(v2 + 8) = v15;
				*(uint32_t*)(v2 + 8) = &v15[*v15 + 1];
			}
			--v11;
		} while (v11);
	}
	v16 = *(int**)(v2 + 8);
	v17 = *v16;
	*(uint32_t*)(v2 + 8) = v16 + 1;
	return v17 == 1162757152;
}

//----- (00414F60) --------------------------------------------------------
int nox_thing_read_WALL_414F60(nox_memfile* f, void* a2) {
	uint32_t* a1 = f;
	uint32_t* v2;       // esi
	void* v3;           // edi
	unsigned char* v4;  // eax
	int v5;             // ebp
	unsigned char* v6;  // eax
	unsigned char* v7;  // eax
	unsigned char* v8;  // eax
	unsigned char* v9;  // eax
	int v10;            // ebp
	int v11;            // edi
	int v12;            // edx
	int* v13;           // eax
	int v14;            // ecx
	int v15;            // eax
	unsigned char* v16; // eax
	int* v17;           // eax
	int v18;            // ecx
	int result;         // eax
	uint32_t* v20;      // [esp-4h] [ebp-18h]
	int v21;            // [esp+10h] [ebp-4h]
	unsigned char v22;  // [esp+18h] [ebp+4h]
	unsigned char v23;  // [esp+18h] [ebp+4h]
	unsigned char v24;  // [esp+18h] [ebp+4h]
	unsigned char v25;  // [esp+18h] [ebp+4h]
	unsigned char v26;  // [esp+18h] [ebp+4h]

	v2 = a1;
	v3 = a2;
	v20 = a1;
	v4 = (unsigned char*)(a1[2] + 4);
	a1[2] = v4;
	v22 = *v4;
	v2[2] = v4 + 1;
	nox_memfile_read(v3, 1u, v22, (int)v20);
	*((uint8_t*)v3 + v22) = 0;
	v2[2] += 14;
	nox_memfile_read64align_40AD60((char*)&a2, 1, 1, v2);
	v5 = 0;
	if ((uint8_t)a2) {
		while (v5 < 8) {
			v6 = (unsigned char*)v2[2];
			v23 = *v6;
			v2[2] = v6 + 1;
			nox_memfile_read(v3, 1u, v23, (int)v2);
			*((uint8_t*)v3 + v23) = 0;
			if (++v5 >= (unsigned char)a2) {
				goto LABEL_4;
			}
		}
		result = 0;
	} else {
	LABEL_4:
		v7 = (unsigned char*)v2[2];
		v24 = *v7;
		v2[2] = v7 + 1;
		nox_memfile_read(v3, 1u, v24, (int)v2);
		*((uint8_t*)v3 + v24) = 0;
		v8 = (unsigned char*)v2[2];
		v25 = *v8;
		v2[2] = v8 + 1;
		nox_memfile_read(v3, 1u, v25, (int)v2);
		*((uint8_t*)v3 + v25) = 0;
		v9 = (unsigned char*)v2[2];
		v26 = *v9;
		v2[2] = v9 + 1;
		nox_memfile_read(v3, 1u, v26, (int)v2);
		*((uint8_t*)v3 + v26) = 0;
		++v2[2];
		v10 = 15;
		do {
			nox_memfile_read64align_40AD60((char*)&v21, 1, 1, v2);
			if ((int)(unsigned char)v21 > 0) {
				v11 = (unsigned char)v21;
				do {
					v12 = 4;
					do {
						v13 = (int*)(v2[2] + 8);
						v2[2] = v13;
						v14 = *v13;
						v15 = (int)(v13 + 1);
						v2[2] = v15;
						if (v14 == -1) {
							v16 = (unsigned char*)(v15 + 1);
							v2[2] = v16;
							v2[2] = &v16[*v16 + 1];
						}
						--v12;
					} while (v12);
					--v11;
				} while (v11);
			}
			--v10;
		} while (v10);
		v17 = (int*)v2[2];
		v18 = *v17;
		v2[2] = v17 + 1;
		result = v18 == 1162757152;
	}
	return result;
}

//----- (00415100) --------------------------------------------------------
int nox_thing_skip_spells_415100(nox_memfile* f) {
	int a1 = f;
	int* v1;            // ecx
	int v2;             // edx
	int v3;             // esi
	unsigned char* v4;  // edx
	int* v5;            // ecx
	int v6;             // edx
	int v7;             // ecx
	unsigned char* v8;  // ecx
	int* v9;            // ecx
	int v10;            // edx
	int v11;            // ecx
	unsigned char* v12; // ecx
	unsigned char* v13; // ecx
	short* v14;         // edx
	unsigned char* v15; // ecx
	unsigned char* v16; // ecx
	unsigned char* v17; // ecx

	v1 = *(int**)(a1 + 8);
	v2 = *v1;
	*(uint32_t*)(a1 + 8) = v1 + 1;
	if (v2 <= 0) {
		return 1;
	}
	v3 = v2;
	do {
		v4 = (unsigned char*)(**(unsigned char**)(a1 + 8) + 4 + *(uint32_t*)(a1 + 8));
		*(uint32_t*)(a1 + 8) = v4;
		v5 = (int*)(*v4 + 1 + *(uint32_t*)(a1 + 8));
		*(uint32_t*)(a1 + 8) = v5;
		v6 = *v5;
		v7 = (int)(v5 + 1);
		*(uint32_t*)(a1 + 8) = v7;
		if (v6 == -1) {
			v8 = (unsigned char*)(v7 + 1);
			*(uint32_t*)(a1 + 8) = v8;
			*(uint32_t*)(a1 + 8) += *v8 + 1;
		}
		v9 = *(int**)(a1 + 8);
		v10 = *v9;
		v11 = (int)(v9 + 1);
		*(uint32_t*)(a1 + 8) = v11;
		if (v10 == -1) {
			v12 = (unsigned char*)(v11 + 1);
			*(uint32_t*)(a1 + 8) = v12;
			*(uint32_t*)(a1 + 8) += *v12 + 1;
		}
		v13 = (unsigned char*)(*(uint32_t*)(a1 + 8) + 4);
		*(uint32_t*)(a1 + 8) = v13;
		v14 = (short*)(*v13 + 1 + *(uint32_t*)(a1 + 8));
		*(uint32_t*)(a1 + 8) = v14;
		v15 = (unsigned char*)v14 + *v14 + 2;
		*(uint32_t*)(a1 + 8) = v15;
		v16 = (unsigned char*)(*v15 + 1 + *(uint32_t*)(a1 + 8));
		*(uint32_t*)(a1 + 8) = v16;
		v17 = (unsigned char*)(*v16 + 1 + *(uint32_t*)(a1 + 8));
		*(uint32_t*)(a1 + 8) = v17;
		--v3;
		*(uint32_t*)(a1 + 8) += *v17 + 1;
	} while (v3);
	return 1;
}

//----- (00415240) --------------------------------------------------------
int nox_thing_read_image_415240(nox_memfile* f) {
	int a1 = f;
	int v1;             // ecx
	int* v2;            // eax
	int v3;             // edx
	int v4;             // ebp
	int result;         // eax
	uint8_t* v6;        // esi
	unsigned char* v7;  // esi
	unsigned char v8;   // bl
	int v9;             // edi
	int* v10;           // edx
	int v11;            // esi
	int v12;            // edx
	unsigned char* v13; // edx
	unsigned char v14;  // [esp+0h] [ebp-4h]
	char v15;           // [esp+8h] [ebp+4h]

	v1 = a1;
	v2 = *(int**)(a1 + 8);
	v3 = *v2;
	*(uint32_t*)(a1 + 8) = v2 + 1;
	if (v3 > 0) {
		v4 = v3;
		result = 1;
		while (1) {
			v6 = (uint8_t*)(**(unsigned char**)(v1 + 8) + 1 + *(uint32_t*)(v1 + 8));
			*(uint32_t*)(v1 + 8) = v6;
			v15 = *v6;
			*(uint32_t*)(v1 + 8) = v6 + 1;
			v7 = v6 + 1;
			if (v15 == 1 || v15 != 2) {
				break;
			}
			v8 = *v7;
			*(uint32_t*)(v1 + 8) = v7 + 2;
			v14 = v8;
			*(uint32_t*)(v1 + 8) += v7[2] + 1;
			if (v8) {
				goto LABEL_7;
			}
		LABEL_11:
			if (!--v4) {
				return result;
			}
		}
		v14 = 1;
	LABEL_7:
		v9 = v14;
		do {
			v10 = *(int**)(v1 + 8);
			v11 = *v10;
			v12 = (int)(v10 + 1);
			*(uint32_t*)(v1 + 8) = v12;
			if (v11 == -1) {
				v13 = (unsigned char*)(v12 + 1);
				*(uint32_t*)(v1 + 8) = v13;
				*(uint32_t*)(v1 + 8) += *v13 + 1;
			}
			--v9;
		} while (v9);
		goto LABEL_11;
	}
	return 1;
}

//----- (00415320) --------------------------------------------------------
int nox_thing_read_ability_415320(nox_memfile* f) {
	int a1 = f;
	int* v1;            // ecx
	int v2;             // edx
	int v3;             // esi
	int* v4;            // ecx
	int v5;             // edx
	int v6;             // ecx
	unsigned char* v7;  // ecx
	int* v8;            // ecx
	int v9;             // edx
	int v10;            // ecx
	unsigned char* v11; // ecx
	int* v12;           // ecx
	int v13;            // edx
	int v14;            // ecx
	unsigned char* v15; // ecx
	short* v16;         // ecx
	unsigned char* v17; // ecx
	unsigned char* v18; // ecx
	unsigned char* v19; // ecx

	v1 = *(int**)(a1 + 8);
	v2 = *v1;
	*(uint32_t*)(a1 + 8) = v1 + 1;
	if (v2 <= 0) {
		return 1;
	}
	v3 = v2;
	do {
		v4 = (int*)(**(unsigned char**)(a1 + 8) + 2 + *(uint32_t*)(a1 + 8));
		*(uint32_t*)(a1 + 8) = v4;
		v5 = *v4;
		v6 = (int)(v4 + 1);
		*(uint32_t*)(a1 + 8) = v6;
		if (v5 == -1) {
			v7 = (unsigned char*)(v6 + 1);
			*(uint32_t*)(a1 + 8) = v7;
			*(uint32_t*)(a1 + 8) += *v7 + 1;
		}
		v8 = *(int**)(a1 + 8);
		v9 = *v8;
		v10 = (int)(v8 + 1);
		*(uint32_t*)(a1 + 8) = v10;
		if (v9 == -1) {
			v11 = (unsigned char*)(v10 + 1);
			*(uint32_t*)(a1 + 8) = v11;
			*(uint32_t*)(a1 + 8) += *v11 + 1;
		}
		v12 = *(int**)(a1 + 8);
		v13 = *v12;
		v14 = (int)(v12 + 1);
		*(uint32_t*)(a1 + 8) = v14;
		if (v13 == -1) {
			v15 = (unsigned char*)(v14 + 1);
			*(uint32_t*)(a1 + 8) = v15;
			*(uint32_t*)(a1 + 8) += *v15 + 1;
		}
		v16 = (short*)(**(unsigned char**)(a1 + 8) + 1 + *(uint32_t*)(a1 + 8));
		*(uint32_t*)(a1 + 8) = v16;
		v17 = (unsigned char*)v16 + *v16 + 2;
		*(uint32_t*)(a1 + 8) = v17;
		v18 = (unsigned char*)(*v17 + 1 + *(uint32_t*)(a1 + 8));
		*(uint32_t*)(a1 + 8) = v18;
		v19 = (unsigned char*)(*v18 + 1 + *(uint32_t*)(a1 + 8));
		*(uint32_t*)(a1 + 8) = v19;
		--v3;
		*(uint32_t*)(a1 + 8) += *v19 + 1;
	} while (v3);
	return 1;
}

//----- (00415660) --------------------------------------------------------
int nox_thing_read_audio_415660(nox_memfile* a1p, char* a2) {
	int a1 = a1p;
	int v2;  // ebx
	int* v3; // eax
	int v4;  // edi

	v2 = 0;
	v3 = *(int**)(a1 + 8);
	v4 = *v3;
	*(uint32_t*)(a1 + 8) = v3 + 1;
	if (v4 <= 0) {
		return 1;
	}
	while (sub_452BD0(a1, a2)) {
		if (++v2 >= v4) {
			return 1;
		}
	}
	return 0;
}

//----- (00415820) --------------------------------------------------------
int nox_xxx_weaponInventoryEquipFlags_415820(nox_object_t* item) {
	if (!item) {
		return 0;
	}
	return nox_xxx_ammoCheck_415880(item->typ_ind);
}

//----- (00415840) --------------------------------------------------------
int sub_415840(char* a1) {
	int v1;           // ecx
	unsigned char* i; // eax
	int v3;           // esi

	v1 = 0;
	if (!*getMemU32Ptr(0x587000, 33064)) {
		return 0;
	}
	for (i = getMemAt(0x587000, 33064); *((char**)i + 2) != a1; i += 12) {
		v3 = *((uint32_t*)i + 3);
		++v1;
		if (!v3) {
			return 0;
		}
	}
	return *getMemU32Ptr(0x587000, 33068 + 12 * v1);
}

//----- (00415880) --------------------------------------------------------
int nox_xxx_ammoCheck_415880(unsigned short typ_ind) {
	int v1;           // ecx
	unsigned char* i; // eax
	int v3;           // esi

	v1 = 0;
	if (!*getMemU32Ptr(0x587000, 33064)) {
		return 0;
	}
	for (i = getMemAt(0x587000, 33064); *((char**)i + 1) != typ_ind; i += 12) {
		v3 = *((uint32_t*)i + 3);
		++v1;
		if (!v3) {
			return 0;
		}
	}
	return *getMemU32Ptr(0x587000, 33072 + 12 * v1);
}

//----- (00415910) --------------------------------------------------------
int sub_415910(char* a1) {
	int v1;            // edi
	const char** v2;   // eax
	unsigned char* v3; // esi
	int v4;            // ecx

	v1 = 0;
	if (!*getMemU32Ptr(0x587000, 33064)) {
		return 0;
	}
	v2 = (const char**)getMemAt(0x587000, 33064);
	v3 = getMemAt(0x587000, 33064);
	while (_strcmpi(a1, *v2)) {
		v4 = *((uint32_t*)v3 + 3);
		v3 += 12;
		++v1;
		v2 = (const char**)v3;
		if (!v4) {
			return 0;
		}
	}
	return *getMemU32Ptr(0x587000, 33072 + 12 * v1);
}

//----- (00415960) --------------------------------------------------------
int sub_415960(wchar_t* a1) {
	int v1;             // edi
	const wchar_t** v2; // eax
	unsigned char* v3;  // esi
	int v4;             // ecx

	v1 = 0;
	if (!*getMemU32Ptr(0x587000, 33392)) {
		return 0;
	}
	v2 = (const wchar_t**)getMemAt(0x587000, 33392);
	v3 = getMemAt(0x587000, 33392);
	while (_nox_wcsicmp(a1, *v2)) {
		v4 = *((uint32_t*)v3 + 3);
		v3 += 12;
		++v1;
		v2 = (const wchar_t**)v3;
		if (!v4) {
			return 0;
		}
	}
	return *getMemU32Ptr(0x587000, 33400 + 12 * v1);
}

//----- (004159B0) --------------------------------------------------------
char* sub_4159B0(char* a1) {
	int v1;           // ecx
	unsigned char* i; // eax
	int v3;           // esi

	v1 = 0;
	if (!*getMemU32Ptr(0x587000, 33064)) {
		return 0;
	}
	for (i = getMemAt(0x587000, 33064); *((char**)i + 2) != a1; i += 12) {
		v3 = *((uint32_t*)i + 3);
		++v1;
		if (!v3) {
			return 0;
		}
	}
	return *(char**)getMemAt(0x587000, 33064 + 12 * v1);
}

//----- (004159F0) --------------------------------------------------------
int sub_4159F0(int a1) {
	int v1;           // ecx
	unsigned char* i; // eax
	int v3;           // esi

	v1 = 0;
	if (!*getMemU32Ptr(0x587000, 33392)) {
		return 0;
	}
	for (i = getMemAt(0x587000, 33392); *((uint32_t*)i + 2) != a1; i += 12) {
		v3 = *((uint32_t*)i + 3);
		++v1;
		if (!v3) {
			return 0;
		}
	}
	return *getMemU32Ptr(0x587000, 33392 + 12 * v1);
}

//----- (00415A30) --------------------------------------------------------
int sub_415A30(char* a1) {
	char* v1;   // eax
	int v2;     // eax
	int result; // eax

	v1 = (char*)sub_415910(a1);
	if (v1 && (v2 = sub_415840(v1)) != 0) {
		result = nox_xxx_objectTypeByInd_4E3B70(v2);
	} else {
		result = 0;
	}
	return result;
}

//----- (00415BD0) --------------------------------------------------------
double sub_415BD0(int a1) {
	float* v1;     // eax
	double result; // st7

	if (*(uint32_t*)(a1 + 8) & 0x2000000 &&
		(v1 = (float*)nox_xxx_equipClothFindDefByTT_413270(*(unsigned short*)(a1 + 4))) != 0) {
		result = v1[16];
	} else {
		result = 0.0;
	}
	return result;
}

//----- (00415C00) --------------------------------------------------------
double nox_xxx_itemApplyDefendEffect_415C00(int a1) {
	int* v1;                                               // edi
	float* v2;                                             // eax
	int v4;                                                // eax
	void (*v5)(int, int, uint32_t, int, uint32_t, float*); // ecx
	float v6;                                              // [esp+8h] [ebp-4h]

	v6 = 0.0;
	if (!(*(uint32_t*)(a1 + 8) & 0x2000000)) {
		return 0.0;
	}
	v1 = *(int**)(a1 + 692);
	v2 = (float*)nox_xxx_equipClothFindDefByTT_413270(*(unsigned short*)(a1 + 4));
	if (!v2) {
		return v6;
	}
	v6 = v2[16];
	v4 = *v1;
	if (*v1) {
		v5 = *(void (**)(int, int, uint32_t, int, uint32_t, float*))(v4 + 76);
		if (v5) {
			v5(v4, a1, 0, a1, 0, &v6);
		}
	}
	return v6;
}

//----- (00415C70) --------------------------------------------------------
int nox_xxx_unitArmorInventoryEquipFlags_415C70(nox_object_t* item) {
	int v1;     // eax
	int result; // eax

	v1 = sub_415C90(item);
	if (v1 < 0) {
		result = 0;
	} else {
		result = *getMemU32Ptr(0x587000, 34860 + 24 * v1);
	}
	return result;
}

//----- (00415C90) --------------------------------------------------------
int sub_415C90(const nox_object_t* item) {
	int result;       // eax
	int v2;           // edx
	unsigned char* i; // ecx
	int v4;           // esi

	if (!item) {
		return -1;
	}
	result = 0;
	if (!*getMemU32Ptr(0x587000, 34848)) {
		return -1;
	}
	HIWORD(v2) = 0;
	for (i = getMemAt(0x587000, 34848);; i += 24) {
		LOWORD(v2) = item->typ_ind;
		if (v2 == *((uint32_t*)i + 2)) {
			break;
		}
		v4 = *((uint32_t*)i + 6);
		++result;
		if (!v4) {
			return -1;
		}
	}
	return result;
}

//----- (00415CD0) --------------------------------------------------------
int sub_415CD0(char* a1) {
	int v1;           // ecx
	unsigned char* i; // eax
	int v3;           // esi

	v1 = 0;
	if (!*getMemU32Ptr(0x587000, 34848)) {
		return 0;
	}
	for (i = getMemAt(0x587000, 34848); a1 != *((char**)i + 3); i += 24) {
		v3 = *((uint32_t*)i + 6);
		++v1;
		if (!v3) {
			return 0;
		}
	}
	return *getMemU32Ptr(0x587000, 34856 + 24 * v1);
}

//----- (00415D10) --------------------------------------------------------
int sub_415D10(int a1) {
	int v1;           // ecx
	unsigned char* i; // eax
	int v3;           // esi

	v1 = 0;
	if (!*getMemU32Ptr(0x587000, 34848)) {
		return 0;
	}
	for (i = getMemAt(0x587000, 34848); a1 != *((char**)i + 2); i += 24) {
		v3 = *((uint32_t*)i + 6);
		++v1;
		if (!v3) {
			return 0;
		}
	}
	return *getMemU32Ptr(0x587000, 34860 + 24 * v1);
}

//----- (00415DA0) --------------------------------------------------------
int sub_415DA0(wchar_t* a1) {
	int v1;             // edi
	const wchar_t** v2; // eax
	unsigned char* v3;  // esi
	int v4;             // ecx

	v1 = 0;
	if (!*getMemU32Ptr(0x587000, 35496)) {
		return 0;
	}
	v2 = (const wchar_t**)getMemAt(0x587000, 35496);
	v3 = getMemAt(0x587000, 35496);
	while (_nox_wcsicmp(a1, *v2)) {
		v4 = *((uint32_t*)v3 + 3);
		v3 += 12;
		++v1;
		v2 = (const wchar_t**)v3;
		if (!v4) {
			return 0;
		}
	}
	return *getMemU32Ptr(0x587000, 35504 + 12 * v1);
}

//----- (00415DF0) --------------------------------------------------------
int sub_415DF0(char* a1) {
	int v1;            // edi
	const char** v2;   // eax
	unsigned char* v3; // esi
	int v4;            // ecx

	v1 = 0;
	if (!*getMemU32Ptr(0x587000, 34848)) {
		return 0;
	}
	v2 = (const char**)getMemAt(0x587000, 34848);
	v3 = getMemAt(0x587000, 34848);
	while (_strcmpi(a1, *v2)) {
		v4 = *((uint32_t*)v3 + 6);
		v3 += 24;
		++v1;
		v2 = (const char**)v3;
		if (!v4) {
			return 0;
		}
	}
	return *getMemU32Ptr(0x587000, 34860 + 24 * v1);
}

//----- (00415E40) --------------------------------------------------------
char* sub_415E40(char* a1) {
	int v1;           // ecx
	unsigned char* i; // eax
	int v3;           // esi

	v1 = 0;
	if (!*getMemU32Ptr(0x587000, 34852)) {
		return 0;
	}
	for (i = getMemAt(0x587000, 34852); *((char**)i + 2) != a1; i += 24) {
		v3 = *((uint32_t*)i + 6);
		++v1;
		if (!v3) {
			return 0;
		}
	}
	return *(char**)getMemAt(0x587000, 34848 + 24 * v1);
}

//----- (00415E80) --------------------------------------------------------
int sub_415E80(int a1) {
	int v1;           // ecx
	unsigned char* i; // eax
	int v3;           // esi

	v1 = 0;
	if (!*getMemU32Ptr(0x587000, 35496)) {
		return 0;
	}
	for (i = getMemAt(0x587000, 35496); *((uint32_t*)i + 2) != a1; i += 12) {
		v3 = *((uint32_t*)i + 3);
		++v1;
		if (!v3) {
			return 0;
		}
	}
	return *getMemU32Ptr(0x587000, 35496 + 12 * v1);
}

//----- (00415EC0) --------------------------------------------------------
int sub_415EC0(char* a1) {
	char* v1;   // eax
	int v2;     // eax
	int result; // eax

	v1 = (char*)sub_415DF0(a1);
	if (v1 && (v2 = sub_415CD0(v1)) != 0) {
		result = nox_xxx_objectTypeByInd_4E3B70(v2);
	} else {
		result = 0;
	}
	return result;
}

//----- (004161E0) --------------------------------------------------------
int sub_4161E0() {
	int v0;            // ebx
	int v1;            // eax
	char v2;           // al
	unsigned short v3; // dx
	short v4;          // ax
	char* v5;          // eax
	unsigned char v6;  // cl
	unsigned char v7;  // cl
	int result;        // eax
	unsigned char v9;  // [esp+8h] [ebp-3Ch]
	unsigned char v10; // [esp+8h] [ebp-3Ch]
	char v11[4];       // [esp+Ch] [ebp-38h]
	int v12;           // [esp+10h] [ebp-34h]
	char v13[12];      // [esp+14h] [ebp-30h]
	char v14[16];      // [esp+20h] [ebp-24h]
	int v15[5];        // [esp+30h] [ebp-14h]

	sub_454040(v15);
	sub_4536B0(v11);
	v12 = sub_453710();
	v0 = nox_common_playerInfoCount_416F40();
	v1 = nox_xxx_servGetPlrLimit_409FA0();
	if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
		--v0;
		--v1;
	}
	if (getMemByte(0x5D4594, 371619) != v0) {
		*getMemU8Ptr(0x5D4594, 371619) = v0;
		dword_5d4594_371692 = 1;
	}
	if (getMemByte(0x5D4594, 371620) != v1) {
		*getMemU8Ptr(0x5D4594, 371620) = v1;
		dword_5d4594_371692 = 1;
	}
	if ((getMemByte(0x5D4594, 371618) & 0xEF) != sub_43BE50_get_video_mode_id()) {
		v2 = sub_43BE50_get_video_mode_id();
		dword_5d4594_371692 = 1;
		*getMemU8Ptr(0x5D4594, 371618) = getMemByte(0x5D4594, 371618) & 0x80 | v2;
	}
	v3 = nox_common_gameFlags_getVal_40A5B0();
	v4 = *getMemU16Ptr(0x5D4594, 371432);
	if ((*getMemU16Ptr(0x5D4594, 371432) ^ v3) & 0xFFF0) {
		*getMemU16Ptr(0x5D4594, 371432) = nox_common_gameFlags_getVal_40A5B0();
		v4 = *getMemU16Ptr(0x5D4594, 371432);
		dword_5d4594_371692 = 1;
	}
	if (*getMemU16Ptr(0x5D4594, 371434) != nox_xxx_servGamedataGet_40A020(v4)) {
		*getMemU16Ptr(0x5D4594, 371434) = nox_xxx_servGamedataGet_40A020(*getMemI16Ptr(0x5D4594, 371432));
		dword_5d4594_371692 = 1;
	}
	if (getMemByte(0x5D4594, 371436) != sub_40A180(*getMemI16Ptr(0x5D4594, 371432))) {
		*getMemU8Ptr(0x5D4594, 371436) = sub_40A180(*getMemI16Ptr(0x5D4594, 371432));
		dword_5d4594_371692 = 1;
	}
	strncpy(v14, (const char*)getMemAt(0x5D4594, 371389), 0xFu);
	v14[15] = 0;
	if (strcmp(v14, nox_xxx_serverOptionsGetServername_40A4C0())) {
		v5 = nox_xxx_serverOptionsGetServername_40A4C0();
		strncpy((char*)getMemAt(0x5D4594, 371389), v5, 0xFu);
		dword_5d4594_371692 = 1;
	}
	strcpy(v13, (const char*)getMemAt(0x5D4594, 371380));
	if (strcmp(v13, nox_xxx_mapGetMapName_409B40())) {
		strcpy((char*)getMemAt(0x5D4594, 371380), nox_xxx_mapGetMapName_409B40());
		dword_5d4594_371692 = 1;
	}
	v6 = 0;
	v9 = 0;
	do {
		if (*getMemU32Ptr(0x5D4594, 371404 + 4 * v9) != v15[v9]) {
			break;
		}
		v9 = ++v6;
	} while (v6 < 5u);
	if (v6 != 5) {
		dword_5d4594_371692 = 1;
		memcpy(getMemAt(0x5D4594, 371404), v15, 0x14u);
	}
	if (!nox_common_gameFlags_check_40A5C0(1)) {
		return dword_5d4594_371692;
	}
	if (*getMemU32Ptr(0x5D4594, 371428) != v12) {
		*getMemU32Ptr(0x5D4594, 371428) = v12;
		dword_5d4594_371692 = 1;
	}
	v7 = 0;
	v10 = 0;
	do {
		if (getMemByte(0x5D4594, 371424 + v10) != v11[v10]) {
			break;
		}
		v10 = ++v7;
	} while (v7 < 4u);
	if (v7 == 4) {
		return dword_5d4594_371692;
	}
	*getMemU32Ptr(0x5D4594, 371424) = *(uint32_t*)v11;
	result = 1;
	dword_5d4594_371692 = 1;
	return result;
}
// 4161E0: using guessed type int var_14[5];

//----- (004164F0) --------------------------------------------------------
void sub_4164F0() { dword_5d4594_371692 = 0; }

//----- (00416500) --------------------------------------------------------
void nox_xxx_mapSetDataDefault_416500() {
	memset(getMemAt(0x5D4594, 371380), 0, 116);
	memset(getMemAt(0x5D4594, 371516), 0, 168);
	*getMemU8Ptr(0x5D4594, 371684) = 0;
	*getMemU16Ptr(0x5D4594, 371621) = -1;
	*getMemU16Ptr(0x5D4594, 371623) = -1;
	*getMemU32Ptr(0x5D4594, 371688) = 0;
	*getMemU8Ptr(0x5D4594, 371617) = -1;
	*getMemU8Ptr(0x5D4594, 371568) = 32;
	*getMemU8Ptr(0x5D4594, 371569) = 32;
	*getMemU32Ptr(0x5D4594, 371578) = 1;
	*getMemU32Ptr(0x5D4594, 371574) = 0;
	*getMemU32Ptr(0x5D4594, 371582) = 0;
	*getMemU32Ptr(0x5D4594, 371586) = 0;
	*getMemU32Ptr(0x5D4594, 371590) = 20;
	*getMemU32Ptr(0x5D4594, 371696) = 0;
}

//----- (00416580) --------------------------------------------------------
int sub_416580() { return *getMemU32Ptr(0x5D4594, 371688); }

//----- (00416590) --------------------------------------------------------
char* nox_xxx_cliGamedataGet_416590(int a1) { return (char*)getMemAt(0x5D4594, 371380 + 58 * a1); }

//----- (004165B0) --------------------------------------------------------
char* sub_4165B0() { return (char*)getMemAt(0x5D4594, 371380 + 58 * *getMemU32Ptr(0x5D4594, 371688)); }

//----- (004165D0) --------------------------------------------------------
char* sub_4165D0(int a1) {
	*getMemU32Ptr(0x5D4594, 371688) = a1;
	return (char*)getMemAt(0x5D4594, 371380 + 58 * a1);
}

//----- (004165F0) --------------------------------------------------------
int sub_4165F0(int a1, int a2) {
	int result; // eax

	result = a2;
	memcpy(getMemAt(0x5D4594, 371380 + 58 * a2), getMemAt(0x5D4594, 371380 + 58 * a1), 0x3Au);
	return result;
}

//----- (00416630) --------------------------------------------------------
char* sub_416630() { return (char*)getMemAt(0x5D4594, 371616); }

//----- (00416640) --------------------------------------------------------
void* sub_416640() { return getMemAt(0x5D4594, 371516); }

//----- (00416650) --------------------------------------------------------
int sub_416650() { return *getMemU32Ptr(0x5D4594, 371700); }

//----- (00416670) --------------------------------------------------------
int sub_416670(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 371700) = 0;
	*getMemU32Ptr(0x5D4594, 371556) = a1;
	return result;
}

//----- (00416690) --------------------------------------------------------
void sub_416690() {
	char* v0;    // esi
	char* v1;    // ebx
	short v2;    // ax
	char v3[84]; // [esp+0h] [ebp-54h]

	if (nox_xxx_check_flag_aaa_43AF70() == 1) {
		v0 = nox_xxx_cliGamedataGet_416590(0);
		sub_4161E0();
		v1 = sub_416630();
		memcpy(v1 + 11, v0, 0x3Au);
		if (nox_xxx_isQuest_4D6F50()) {
			v2 = *(uint16_t*)(v1 + 63) & 0xFF7F;
			HIBYTE(v2) |= 0x10u;
			*(uint16_t*)(v1 + 63) = v2;
			*(uint16_t*)(v1 + 65) = nox_game_getQuestStage_4E3CC0();
		}
		v3[sub_425550(v1, v3, 552)] = 0;
		sub_40D560((int)v3);
		sub_4164F0();
	}
}
// 416690: using guessed type char var_54[84];

//----- (00416720) --------------------------------------------------------
void sub_416720() {
	int v0 = 0;
	int v2 = sub_416900();
	while (v2) {
		int* v3 = sub_416910((int*)v2);
		if (*(uint32_t*)(v2 + 68) || (*(uint32_t*)(v2 + 64))) {
			if (nox_platform_get_ticks() > *(uint64_t*)(v2 + 64)) {
				sub_416820(v0);
			}
		}
		++v0;
		v2 = (int)v3;
	}
}

//----- (00416770) --------------------------------------------------------
int* sub_416770(int a1, wchar_t* a2, const char* a3) {
	uint32_t* v3; // ebp

	v3 = calloc(1, 0x60u);
	sub_425770(v3);
	nox_wcscpy((wchar_t*)v3 + 6, a2);
	if (a3) {
		strcpy((char*)v3 + 72, a3);
	} else {
		*((uint8_t*)v3 + 72) = 0;
	}
	nox_common_list_append_4258E0((int)getMemAt(0x5D4594, 371500), v3);
	if (a1) {
		*((uint64_t*)v3 + 8) = 60000 * a1 + nox_platform_get_ticks();
	} else {
		v3[16] = 0;
		v3[17] = 0;
	}
	return sub_455800();
}

//----- (00416820) --------------------------------------------------------
void sub_416820(int a1) {
	int* v2; // esi
	int v3;  // edi
	int v4;  // eax

	v2 = sub_416900();
	if (!v2) {
		return;
	}
	v3 = a1;
	while (1) {
		v4 = v3--;
		if (!v4) {
			break;
		}
		v2 = sub_416910(v2);
		if (!v2) {
			return;
		}
	}
	sub_425920((uint32_t**)v2);
	free(v2);
}

//----- (00416860) --------------------------------------------------------
int* sub_416860(int a1) {
	int* result; // eax
	int* v2;     // esi
	int v3;      // edi
	int v4;      // eax

	result = sub_4168E0();
	v2 = result;
	if (result) {
		v3 = a1;
		while (1) {
			v4 = v3--;
			if (!v4) {
				break;
			}
			result = sub_4168F0(v2);
			v2 = result;
			if (!result) {
				return result;
			}
		}
		sub_425920((uint32_t**)v2);
		free(v2);
	}
	return result;
}

//----- (004168A0) --------------------------------------------------------
int* sub_4168A0(wchar_t* a1) {
	wchar_t* v1; // esi

	v1 = (wchar_t*)calloc(1, 0x40u);
	sub_425770(v1);
	nox_wcscpy(v1 + 6, a1);
	nox_common_list_append_4258E0((int)getMemAt(0x5D4594, 371364), v1);
	return sub_455800();
}

//----- (004168E0) --------------------------------------------------------
int* sub_4168E0() { return nox_common_list_getFirstSafe_425890(getMemIntPtr(0x5D4594, 371364)); }

//----- (004168F0) --------------------------------------------------------
int* sub_4168F0(int* a1) { return nox_common_list_getNextSafe_4258A0(a1); }

//----- (00416900) --------------------------------------------------------
int* sub_416900() { return nox_common_list_getFirstSafe_425890(getMemIntPtr(0x5D4594, 371500)); }

//----- (00416910) --------------------------------------------------------
int* sub_416910(int* a1) { return nox_common_list_getNextSafe_4258A0(a1); }

//----- (00416920) --------------------------------------------------------
int sub_416920() {
	nox_common_list_clear_425760(getMemAt(0x5D4594, 371364));
	nox_common_list_clear_425760(getMemAt(0x5D4594, 371500));
	return sub_4E41B0((char*)getMemAt(0x587000, 54280));
}

//----- (00416950) --------------------------------------------------------
int* sub_416950() {
	int* v0;     // esi
	int* v1;     // edi
	int* result; // eax
	int* v3;     // esi
	int* v4;     // edi

	sub_4E43F0("ban.txt");
	v0 = sub_4168E0();
	if (v0) {
		do {
			v1 = sub_4168F0(v0);
			sub_425920((uint32_t**)v0);
			free(v0);
			v0 = v1;
		} while (v1);
	}
	result = sub_416900();
	v3 = result;
	if (result) {
		do {
			v4 = sub_416910(v3);
			sub_425920((uint32_t**)v3);
			free(v3);
			v3 = v4;
		} while (v4);
	}
	return result;
}

//----- (004169C0) --------------------------------------------------------
int sub_4169C0() { return *getMemU32Ptr(0x5D4594, 371704); }

//----- (004169D0) --------------------------------------------------------
int nox_xxx_cliSetSettingsAcquired_4169D0(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 371704) = a1;
	return result;
}

//----- (004169E0) --------------------------------------------------------
char* sub_4169E0() {
	char* result; // eax

	result = sub_416640();
	result[100] |= 0x10u;
	return result;
}

//----- (004169F0) --------------------------------------------------------
char* sub_4169F0() {
	char* result; // eax

	result = sub_416640();
	result[100] &= 0xEFu;
	return result;
}

//----- (00416A00) --------------------------------------------------------
unsigned int sub_416A00() {
	char* v0; // eax

	v0 = sub_416640();
	LOBYTE(v0) = v0[100];
	return ((unsigned int)v0 >> 4) & 1;
}

//----- (00416E50) --------------------------------------------------------
char* nox_xxx_playerForceSendLessons_416E50(int a1) {
	char* result; // eax
	int* i;       // esi

	result = nox_common_playerInfoGetFirst_416EA0();
	for (i = (int*)result; result; i = (int*)result) {
		i[534] = 0;
		i[535] = 0;
		if (a1) {
			if (i[514]) {
				nox_xxx_netReportLesson_4D8EF0(i[514]);
			}
		}
		result = nox_common_playerInfoGetNext_416EE0((int)i);
	}
	return result;
}

//----- (004170D0) --------------------------------------------------------
char* nox_xxx_playerByName_4170D0(wchar_t* a1) {
	char* v1; // esi

	if (!a1) {
		return 0;
	}
	v1 = nox_common_playerInfoGetFirst_416EA0();
	if (!v1) {
		return 0;
	}
	while (_nox_wcsicmp((const wchar_t*)v1 + 2352, a1)) {
		v1 = nox_common_playerInfoGetNext_416EE0((int)v1);
		if (!v1) {
			return 0;
		}
	}
	return v1;
}

//----- (00417190) --------------------------------------------------------
int nox_xxx_netMarkMinimapObject_417190(int a1, int a2, int a3) {
	int v3;            // ebx
	uint32_t* v4;      // ecx
	unsigned char* v5; // esi
	uint32_t* v6;      // eax
	uint32_t* v8;      // eax
	int v9;            // ecx
	int v10;           // ecx

	v3 = 0;
	if (!(a1 >= 0 && a1 < NOX_PLAYERINFO_MAX && a2)) {
		return v3;
	}
	nox_playerInfo* pl = nox_common_playerInfoFromNumRaw(a1);
	v4 = pl->field_4580;
	v5 = pl;
	if (v4) {
		if (v4[1] == a2) {
			v6 = pl->field_4580;
			*v6 |= a3;
			return 1;
		}
		v6 = (uint32_t*)v4[2];
		while (v6 != v4) {
			if (v6[1] == a2) {
				*v6 |= a3;
				return 1;
			}
			v6 = (uint32_t*)v6[2];
		}
	}
	v8 = calloc(1, 0x10u);
	if (!v8) {
		return v3;
	}
	v8[1] = a2;
	*v8 = a3;
	v9 = *((uint32_t*)v5 + 1145);
	if (v9) {
		v8[2] = v9;
		v10 = v8[2];
		v8[3] = *(uint32_t*)(*((uint32_t*)v5 + 1145) + 12);
		*(uint32_t*)(v10 + 12) = v8;
		*(uint32_t*)(v8[3] + 8) = v8;
		*((uint32_t*)v5 + 1145) = v8;
	} else {
		*((uint32_t*)v5 + 1145) = v8;
		v8[3] = v8;
		v8[2] = v8;
	}
	nox_xxx_unitSetXStatus_4E4800(a2, (int*)1);
	v3 = 1;
	return v3;
}

//----- (00417270) --------------------------------------------------------
int sub_417270(int a1) {
	int result; // eax
	int v2;     // edx
	int v3;     // ecx

	result = 0;
	if (a1 >= 0 && a1 < NOX_PLAYERINFO_MAX) {
		nox_playerInfo* pl = nox_common_playerInfoFromNumRaw(a1);
		v2 = pl->field_4580;
		if (v2) {
			v3 = *(uint32_t*)(v2 + 8);
			for (result = 1; v3 != v2; ++result) {
				v3 = *(uint32_t*)(v3 + 8);
			}
		}
	}
	return result;
}

//----- (004172C0) --------------------------------------------------------
int sub_4172C0(int a1) {
	int result; // eax
	int v2;     // ecx

	result = 0;
	if (a1 >= 0 && a1 < NOX_PLAYERINFO_MAX) {
		nox_playerInfo* pl = nox_common_playerInfoFromNumRaw(a1);
		v2 = pl->field_4580;
		if (v2) {
			result = *(uint32_t*)(v2 + 4);
			pl->field_4580 = *(uint32_t*)(v2 + 8);
		}
	}
	return result;
}

//----- (00417300) --------------------------------------------------------
int nox_xxx_netUnmarkMinimapObj_417300(int a1, int a2, int a3) {
	int result;        // eax
	unsigned char* v4; // edi
	uint32_t* v5;      // ecx
	int v6;            // edx
	bool v7;           // zf
	uint32_t* v8;      // eax
	int v9;            // eax

	result = 0;
	if (a1 >= 0 && a1 < NOX_PLAYERINFO_MAX) {
		if (a2) {
			nox_playerInfo* pl = nox_common_playerInfoFromNumRaw(a1);
			v4 = pl;
			v5 = pl->field_4580;
			if (v5) {
				while (1) {
					v6 = v5[2];
					if (v5[1] == a2) {
						break;
					}
					if (v6 != pl->field_4580) {
						v5 = (uint32_t*)v5[2];
						if (v6) {
							continue;
						}
					}
					return result;
				}
				v7 = (~a3 & *v5) == 0;
				*v5 &= ~a3;
				if (v7) {
					v8 = (uint32_t*)*((uint32_t*)v4 + 1145);
					if ((uint32_t*)v8[2] == v8) {
						*((uint32_t*)v4 + 1145) = 0;
					} else {
						if (v8 == v5) {
							*((uint32_t*)v4 + 1145) = v5[2];
						}
						*(uint32_t*)(v5[2] + 12) = v5[3];
						*(uint32_t*)(v5[3] + 8) = v5[2];
					}
					free(v5);
					v9 = *(uint32_t*)(a2 + 20);
					LOBYTE(v9) = v9 & 0xFE;
					*(uint32_t*)(a2 + 20) = v9;
					result = 1;
				} else {
					result = 0;
				}
			}
		}
	}
	return result;
}

// mark spell -- is tracked
//----- (004173D0) --------------------------------------------------------
int nox_xxx_playerMapTracksObj_4173D0(int a1, int a2) {
	int result; // eax
	int v3;     // ecx

	result = 0;
	if (a1 >= 0 && a1 < NOX_PLAYERINFO_MAX) {
		if (a2) {
			nox_playerInfo* pl = nox_common_playerInfoFromNumRaw(a1);
			v3 = pl->field_4580;
			if (v3) {
				while (*(uint32_t*)(v3 + 4) != a2) {
					v3 = *(uint32_t*)(v3 + 8);
					if (v3 == pl->field_4580 || !v3) {
						return result;
					}
				}
				result = 1;
			}
		}
	}
	return result;
}

//----- (00417430) --------------------------------------------------------
char* nox_xxx_netMinimapUnmark4All_417430(int a1) {
	char* result; // eax
	int i;        // esi

	result = nox_common_playerInfoGetFirst_416EA0();
	for (i = (int)result; result; i = (int)result) {
		nox_xxx_netUnmarkMinimapObj_417300(*(unsigned char*)(i + 2064), a1, 3);
		result = nox_common_playerInfoGetNext_416EE0(i);
	}
	return result;
}

//----- (00417470) --------------------------------------------------------
char* nox_xxx_netUnmarkMinimapSpec_417470(int a1, int a2) {
	char* result; // eax
	int i;        // esi

	result = nox_common_playerInfoGetFirst_416EA0();
	for (i = (int)result; result; i = (int)result) {
		nox_xxx_netUnmarkMinimapObj_417300(*(unsigned char*)(i + 2064), a1, a2);
		result = nox_common_playerInfoGetNext_416EE0(i);
	}
	return result;
}

//----- (004174B0) --------------------------------------------------------
char* nox_xxx_netMarkMinimapForAll_4174B0(int a1, int a2) {
	char* result; // eax
	int i;        // esi

	result = nox_common_playerInfoGetFirst_416EA0();
	for (i = (int)result; result; i = (int)result) {
		nox_xxx_netMarkMinimapObject_417190(*(unsigned char*)(i + 2064), a1, a2);
		result = nox_common_playerInfoGetNext_416EE0(i);
	}
	return result;
}

//----- (004174F0) --------------------------------------------------------
int nox_xxx_netNeedTimestampStatus_4174F0(int a1, int a2) {
	int result; // eax

	*(uint32_t*)(a1 + 3680) |= a2;
	result = nox_common_gameFlags_check_40A5C0(1);
	if (result) {
		if (a2 & 0x423) {
			result = nox_xxx_netReportPlayerStatus_417630(a1);
		}
	}
	return result;
}

//----- (00417530) --------------------------------------------------------
char nox_xxx_playerUnsetStatus_417530(nox_playerInfo* a1p, int a2) {
	int a1 = a1p;
	int v2;   // eax
	short v3; // ax

	*(uint32_t*)(a1 + 3680) &= ~a2;
	v2 = nox_common_gameFlags_check_40A5C0(1);
	if (v2) {
		if (a2 & 1) {
			v2 = nox_common_gameFlags_check_40A5C0(128);
			if (!v2) {
				v2 = nox_xxx_gamePlayIsAnyPlayers_40A8A0();
				if (v2) {
					v2 = sub_40A220();
					if (!v2) {
						v3 = nox_common_gameFlags_getVal_40A5B0();
						LOBYTE(v2) = sub_40A180(v3);
						if ((uint8_t)v2) {
							sub_40A250();
							LOBYTE(v2) = sub_40A1F0(1);
						}
					}
				}
			}
		}
		if (a2 & 0x423) {
			LOBYTE(v2) = nox_xxx_netReportPlayerStatus_417630(a1);
		}
	}
	return v2;
}
// 417577: variable 'v2' is possibly undefined

//----- (004175C0) --------------------------------------------------------
char* nox_xxx_sendAllClientStatus_4175C0(int a1) {
	char* result; // eax
	int i;        // esi
	int v3;       // [esp-18h] [ebp-24h]
	char v4[7];   // [esp+4h] [ebp-8h]

	result = nox_common_playerInfoGetFirst_416EA0();
	for (i = (int)result; result; i = (int)result) {
		v4[0] = 106;
		*(uint16_t*)&v4[1] = *(uint16_t*)(i + 2060);
		v3 = *(unsigned char*)(a1 + 2064);
		*(uint32_t*)&v4[3] = *(uint32_t*)(i + 3680) & 0x423;
		nox_xxx_netSendPacket1_4E5390(v3, (int)v4, 7, 0, 0);
		result = nox_common_playerInfoGetNext_416EE0(i);
	}
	return result;
}

//----- (00417630) --------------------------------------------------------
int nox_xxx_netReportPlayerStatus_417630(nox_playerInfo* pl) {
	int a1 = pl;
	short v1;   // cx
	int v2;     // edx
	char v4[7]; // [esp+0h] [ebp-8h]

	v1 = *(uint16_t*)(a1 + 2060);
	v2 = *(uint32_t*)(a1 + 3680) & 0x423;
	v4[0] = 106;
	*(uint16_t*)&v4[1] = v1;
	*(uint32_t*)&v4[3] = v2;
	return nox_xxx_netSendPacket1_4E5390(255, (int)v4, 7, 0, 0);
}

//----- (00417680) --------------------------------------------------------
void nox_xxx_cliPlayerRespawn_417680(int a1, char a2) {
	int v2;       // esi
	int v3;       // eax
	int v4;       // ecx
	uint32_t* v5; // edi
	int v6;       // eax
	int v7;       // ecx
	uint32_t* v8; // edi
	int v9;       // eax
	int v10;      // edi
	int v11;      // eax
	int v12;      // edx
	char v13;     // dl
	int v14;      // eax
	char v15;     // al
	int v16;      // eax
	int v17;      // eax
	int v18;      // eax
	int v19;      // eax
	char v20;     // cl
	int v21;      // eax
	int v22;      // eax
	char v23;     // cl
	int v24;      // eax
	int v25;      // [esp-Ch] [ebp-18h]
	int v26;      // [esp-Ch] [ebp-18h]

	v2 = a1;
	if (!a1) {
		return;
	}
	if (!nox_common_gameFlags_check_40A5C0(1)) {
		*(uint32_t*)(v2 + 4) = 0;
	}
	v3 = v2 + 2328;
	v4 = 27;
	do {
		v5 = (uint32_t*)v3;
		*(uint32_t*)(v3 - 4) = 0;
		v3 += 24;
		*v5 = 0;
		--v4;
		v5[1] = 0;
		v5[2] = 0;
		v5[3] = 0;
	} while (v4);
	if (!nox_common_gameFlags_check_40A5C0(1)) {
		*(uint32_t*)v2 = 0;
	}
	v6 = v2 + 2976;
	v7 = 26;
	do {
		v8 = (uint32_t*)v6;
		*(uint32_t*)(v6 - 4) = 0;
		v6 += 24;
		*v8 = 0;
		--v7;
		v8[1] = 0;
		v8[2] = 0;
		v8[3] = 0;
	} while (v7);
	v9 = nox_xxx_modifGetIdByName_413290("UserColor1");
	v10 = nox_xxx_modifGetDescById_413330(v9);
	if (!v10) {
		return;
	}
	if (*(uint8_t*)(v2 + 2251) || nox_common_gameFlags_check_40A5C0(2048)) {
		LOBYTE(a1) = -1;
		v11 = nox_xxx_modifGetDescById_413330(*(uint32_t*)(v10 + 4) + *(unsigned char*)(v2 + 2269));
		v12 = *(unsigned char*)(v2 + 2270);
		BYTE1(a1) = *(uint8_t*)(v11 + 4);
		BYTE2(a1) = *((uint8_t*)nox_xxx_modifGetDescById_413330(*(uint32_t*)(v10 + 4) + v12) + 4);
		HIBYTE(a1) = -1;
		if (a2 & 1) {
			nox_xxx_clientEquipWeaponArmor_417AA0(82, *(uint32_t*)(v2 + 2060), 1024, (int)&a1);
		}
	}
	LOBYTE(a1) = -1;
	BYTE1(a1) = *((uint8_t*)nox_xxx_modifGetDescById_413330(*(uint32_t*)(v10 + 4) + *(unsigned char*)(v2 + 2268)) + 4);
	HIWORD(a1) = -1;
	if (a2 & 2) {
		nox_xxx_clientEquipWeaponArmor_417AA0(82, *(uint32_t*)(v2 + 2060), 4, (int)&a1);
	}
	v13 = *((uint8_t*)nox_xxx_modifGetDescById_413330(*(uint32_t*)(v10 + 4) + *(unsigned char*)(v2 + 2272)) + 4);
	v14 = *(unsigned char*)(v2 + 2271);
	LOBYTE(a1) = v13;
	BYTE1(a1) = *((uint8_t*)nox_xxx_modifGetDescById_413330(*(uint32_t*)(v10 + 4) + v14) + 4);
	HIWORD(a1) = -1;
	if (a2 & 4) {
		nox_xxx_clientEquipWeaponArmor_417AA0(82, *(uint32_t*)(v2 + 2060), 1, (int)&a1);
	}
	v15 = *(uint8_t*)(v2 + 2251);
	a1 = -1;
	if (v15 == 1) {
		if (nox_common_gameFlags_check_40A5C0(2048)) {
			if (a2 & 8) {
				v16 = nox_xxx_modifGetIdByName_413290("ArmorQuality1");
				LOBYTE(a1) = *((uint8_t*)nox_xxx_modifGetDescById_413330(v16) + 4);
				nox_xxx_clientEquipWeaponArmor_417AA0(80, *(uint32_t*)(v2 + 2060), 0x8000, (int)&a1);
			}
		} else if (nox_common_gameFlags_check_40A5C0(4096)) {
			a1 = -1;
			v17 = nox_xxx_modifGetIdByName_413290("Replenishment1");
			BYTE2(a1) = *((uint8_t*)nox_xxx_modifGetDescById_413330(v17) + 4);
			nox_xxx_clientEquipWeaponArmor_417AA0(80, *(uint32_t*)(v2 + 2060), 0x10000, (int)&a1);
		} else if (a2 & 0x10) {
			nox_xxx_clientEquipWeaponArmor_417AA0(79, *(uint32_t*)(v2 + 2060), 0x4000, (int)&a1);
		}
	}
	if (!*(uint8_t*)(v2 + 2251)) {
		if (nox_common_gameFlags_check_40A5C0(2048)) {
			if (a2 & 0x20) {
				v18 = nox_xxx_modifGetIdByName_413290("ArmorQuality1");
				LOBYTE(a1) = *((uint8_t*)nox_xxx_modifGetDescById_413330(v18) + 4);
				v19 = nox_xxx_modifGetIdByName_413290("Material1");
				v20 = *((uint8_t*)nox_xxx_modifGetDescById_413330(v19) + 4);
				v21 = *(uint32_t*)(v2 + 2060);
				LOBYTE(a1) = v20;
				nox_xxx_clientEquipWeaponArmor_417AA0(80, v21, 256, (int)&a1);
			}
		} else if (nox_common_gameFlags_check_40A5C0(4096)) {
			v25 = *(uint32_t*)(v2 + 2060);
			a1 = -1;
			nox_xxx_clientEquipWeaponArmor_417AA0(80, v25, 256, (int)&a1);
		} else {
			if (a2 & 0x40) {
				nox_xxx_clientEquipWeaponArmor_417AA0(80, *(uint32_t*)(v2 + 2060), 512, (int)&a1);
			}
			if (a2 < 0) {
				nox_xxx_clientEquipWeaponArmor_417AA0(79, *(uint32_t*)(v2 + 2060), 0x1000000, (int)&a1);
			}
		}
	}
	if (*(uint8_t*)(v2 + 2251) == 2) {
		if (nox_common_gameFlags_check_40A5C0(2048)) {
			if (a2 & 8) {
				v22 = nox_xxx_modifGetIdByName_413290("ArmorQuality1");
				v23 = *((uint8_t*)nox_xxx_modifGetDescById_413330(v22) + 4);
				v24 = *(uint32_t*)(v2 + 2060);
				LOBYTE(a1) = v23;
				nox_xxx_clientEquipWeaponArmor_417AA0(80, v24, 0x8000, (int)&a1);
			}
		} else if (nox_common_gameFlags_check_40A5C0(4096)) {
			v26 = *(uint32_t*)(v2 + 2060);
			a1 = -1;
			nox_xxx_clientEquipWeaponArmor_417AA0(80, v26, 4, (int)&a1);
		}
	}
}

//----- (00417AA0) --------------------------------------------------------
char* nox_xxx_clientEquipWeaponArmor_417AA0(char a1, int a2, int a3, int a4) {
	char* result; // eax
	char* v5;     // edx
	int v6;       // ecx
	int v7;       // esi
	char* v8;     // edi
	char* v9;     // edx
	int v10;      // ecx
	int v11;      // esi
	char* v12;    // edi

	result = nox_common_playerInfoGetByID_417040(a2);
	if (result) {
		if (a1 == 81 || a1 == 80) {
			v9 = result + 2324;
			*((uint32_t*)result + 1) |= a3;
			v10 = 0;
			while (*(uint32_t*)v9) {
				++v10;
				v9 += 24;
				if (v10 >= 27) {
					return result;
				}
			}
			*(uint32_t*)&result[24 * v10 + 2324] = a3;
			v11 = 0;
			v12 = &result[24 * v10 + 2328];
			do {
				result = (char*)nox_xxx_modifGetDescById_413330(*(unsigned char*)(v11 + a4));
				*(uint32_t*)v12 = result;
				++v11;
				v12 += 4;
			} while (v11 < 4);
		} else {
			v5 = result + 2972;
			*(uint32_t*)result |= a3;
			v6 = 0;
			while (*(uint32_t*)v5) {
				++v6;
				v5 += 24;
				if (v6 >= 26) {
					return result;
				}
			}
			*(uint32_t*)&result[24 * v6 + 2972] = a3;
			v7 = 0;
			v8 = &result[24 * v6 + 2976];
			do {
				result = (char*)nox_xxx_modifGetDescById_413330(*(unsigned char*)(v7 + a4));
				*(uint32_t*)v8 = result;
				++v7;
				v8 += 4;
			} while (v7 < 4);
		}
	}
	return result;
}

//----- (00417B80) --------------------------------------------------------
char* sub_417B80(char a1, int a2, int a3) {
	char* result; // eax
	int v4;       // ecx
	int v5;       // edx
	int v6;       // ecx
	char* i;      // edx
	int v8;       // edx
	int v9;       // ecx
	char* j;      // edx

	result = nox_common_playerInfoGetByID_417040(a2);
	if (result) {
		v4 = ~a3;
		if (a1 == 84) {
			v5 = v4 & *((uint32_t*)result + 1);
			v6 = 0;
			*((uint32_t*)result + 1) = v5;
			for (i = result + 2324; *(uint32_t*)i != a3; i += 24) {
				if (++v6 >= 27) {
					return result;
				}
			}
			*(uint32_t*)&result[24 * v6 + 2324] = 0;
		} else {
			v8 = v4 & *(uint32_t*)result;
			v9 = 0;
			*(uint32_t*)result = v8;
			for (j = result + 2972; *(uint32_t*)j != a3; j += 24) {
				if (++v9 >= 26) {
					return result;
				}
			}
			*(uint32_t*)&result[24 * v9 + 2972] = 0;
		}
	}
	return result;
}

//----- (00417C00) --------------------------------------------------------
char* sub_417C00(char* a1, int a2) {
	char* result; // eax
	int i;        // esi

	result = nox_common_playerInfoGetFirst_416EA0();
	for (i = (int)result; result; i = (int)result) {
		if (!_strcmpi((const char*)(i + 2096), a1)) {
			*(uint32_t*)(i + 2108) = a2;
		}
		result = nox_common_playerInfoGetNext_416EE0(i);
	}
	return result;
}

//----- (00417CF0) --------------------------------------------------------
int sub_417CF0() { return nox_server_teamsZzz_419030(0); }

//----- (00417DC0) --------------------------------------------------------
int sub_417DC0() { return dword_5d4594_526276; }

//----- (00417DE0) --------------------------------------------------------
char sub_417DE0() {
	char v0; // bl
	char* i; // eax

	v0 = 0;
	for (i = nox_server_teamFirst_418B10(); i; i = nox_server_teamNext_418B60((int)i)) {
		if (*((uint32_t*)i + 15)) {
			++v0;
		}
	}
	return v0;
}

//----- (00417EA0) --------------------------------------------------------
int nox_xxx_mapInfoSetCapflag_417EA0() {
	int v0; // eax
	int v1; // esi

	LOBYTE(v0) = sub_417EC0();
	v1 = v0;
	if (v0) {
		sub_455A50(2);
	}
	return v1;
}
// 417EA6: variable 'v0' is possibly undefined

//----- (00417EC0) --------------------------------------------------------
bool sub_417EC0() {
	int i; // eax

	dword_5d4594_526276 = 0;
	for (i = nox_server_getFirstObject_4DA790(); i; i = nox_server_getNextObject_4DA7A0(i)) {
		if (*(uint32_t*)(i + 8) & 0x10000000) {
			++dword_5d4594_526276;
		}
	}
	if (dword_5d4594_526276 > 0 && !nox_common_gameFlags_check_40A5C0(0x8000)) {
		sub_4181F0(0);
	}
	return dword_5d4594_526276 > 0;
}

//----- (00417F30) --------------------------------------------------------
char nox_xxx_mapInfoSetFlagball_417F30() {
	int v0; // eax

	LOBYTE(v0) = sub_417EC0();
	if (v0) {
		sub_455F60();
		LOBYTE(v0) = sub_417F50(0);
	}
	return v0;
}
// 417F37: variable 'v0' is possibly undefined

//----- (00417F50) --------------------------------------------------------
int sub_417F50(int a1) {
	int v1;       // esi
	int v2;       // eax
	int v3;       // esi
	int v4;       // ebx
	uint32_t* v6; // eax
	uint32_t* v7; // esi
	int v8;       // edi
	int i;        // edi
	float v10;    // [esp+0h] [ebp-14h]

	if (!dword_5d4594_527656) {
		dword_5d4594_527656 = nox_xxx_getNameId_4E3AA0("GameBallStart");
	}
	v1 = 0;
	v2 = nox_server_getFirstObject_4DA790();
	if (!v2) {
		return 0;
	}
	do {
		if (*(unsigned short*)(v2 + 4) == dword_5d4594_527656) {
			++v1;
		}
		v2 = nox_server_getNextObject_4DA7A0(v2);
	} while (v2);
	if (!v1) {
		return 0;
	}
	v3 = nox_common_randomInt_415FA0(0, v1 - 1);
	v4 = nox_server_getFirstObject_4DA790();
	if (!v4) {
		return 0;
	}
	while (*(unsigned short*)(v4 + 4) != dword_5d4594_527656) {
	LABEL_12:
		v4 = nox_server_getNextObject_4DA7A0(v4);
		if (!v4) {
			return 0;
		}
	}
	if (v3) {
		--v3;
		goto LABEL_12;
	}
	v6 = nox_xxx_newObjectByTypeID_4E3810("GameBall");
	v7 = v6;
	if (!v6) {
		return 0;
	}
	v8 = v6[187];
	*(uint64_t*)(v8 + 8) = nox_platform_get_ticks();
	v10 = nox_xxx_gamedataGetFloat_419D40("FlagballPossDuration");
	*(uint32_t*)(v8 + 20) = nox_float2int(v10);
	*(float*)(v8 + 24) = nox_xxx_gamedataGetFloat_419D40("FlagballResetVel");
	nox_xxx_netMarkMinimapForAll_4174B0((int)v7, 1);
	nox_xxx_createAt_4DAA50((int)v7, 0, 0.0, 0.0);
	nox_xxx_unitClearOwner_4EC300((int)v7);
	sub_4EB9B0((int)v7, 0);
	sub_4E8290(0, 0);
	nox_xxx_unitMove_4E7010((int)v7, (float2*)(v4 + 56));
	v7[20] = 0;
	v7[21] = 0;
	v7[22] = 0;
	v7[25] = 0;
	if (a1) {
		for (i = nox_xxx_getFirstPlayerUnit_4DA7C0(); i; i = nox_xxx_getNextPlayerUnit_4DA7F0(i)) {
			if (*(uint32_t*)(*(uint32_t*)(*(uint32_t*)(i + 748) + 276) + 3628) == a1) {
				nox_xxx_playerCameraUnlock_4E6040(i);
				nox_xxx_playerCameraFollow_4E6060(i, (int)v7);
			}
		}
		nox_xxx_delayedDeleteObject_4E5CC0(a1);
	}
	return 1;
}

//----- (004180D0) --------------------------------------------------------
int nox_xxx_mapInfoSetKotr_4180D0() {
	int v0;   // esi
	int v1;   // edi
	char* i;  // eax
	int v3;   // ebp
	int v4;   // esi
	int v5;   // edi
	bool v6;  // zf
	char v7;  // al
	char* v8; // eax

	if (!*getMemU32Ptr(0x5D4594, 527652)) {
		*getMemU32Ptr(0x5D4594, 527652) = nox_xxx_getNameId_4E3AA0("Crown");
	}
	v0 = nox_server_getFirstObject_4DA790();
	if (v0) {
		do {
			v1 = nox_server_getNextObject_4DA7A0(v0);
			if (*(uint32_t*)(v0 + 8) & 0x10000000) {
				nox_xxx_delayedDeleteObject_4E5CC0(v0);
			}
			v0 = v1;
		} while (v1);
	}
	for (i = nox_server_teamFirst_418B10(); i; i = nox_server_teamNext_418B60((int)i)) {
		*((uint32_t*)i + 19) = 0;
	}
	v3 = 0;
	v4 = nox_server_getFirstObject_4DA790();
	if (!v4) {
		return 0;
	}
	do {
		v5 = nox_server_getNextObject_4DA7A0(v4);
		if (*(unsigned short*)(v4 + 4) != *getMemU32Ptr(0x5D4594, 527652)) {
			v4 = v5;
			continue;
		}
		++v3;
		*(uint32_t*)(*(uint32_t*)(v4 + 748) + 4) = 0;
		v6 = !nox_xxx_CheckGameplayFlags_417DA0(4);
		v7 = *(uint8_t*)(v4 + 52);
		if (v6) {
			if (v7) {
				nox_xxx_delayedDeleteObject_4E5CC0(v4);
				sub_4EC6A0(v4);
				v4 = v5;
				continue;
			}
			nox_xxx_netMarkMinimapForAll_4174B0(v4, 1);
			v4 = v5;
			continue;
		}
		if (!v7) {
			nox_xxx_delayedDeleteObject_4E5CC0(v4);
			sub_4EC6A0(v4);
			v4 = v5;
			continue;
		}
		v8 = nox_xxx_clientGetTeamColor_418AB0(*(unsigned char*)(v4 + 52));
		if (v8) {
			*((uint32_t*)v8 + 19) = v4;
			nox_xxx_netMarkMinimapForAll_4174B0(v4, 1);
		}
		v4 = v5;
	} while (v5);
	if (!v3) {
		return 0;
	}
	return 1;
}

//----- (004181F0) --------------------------------------------------------
void sub_4181F0(int a1) {
	unsigned char v1;  // bl
	char* i;           // esi
	char* result;      // eax
	char* v4;          // esi
	int v5;            // ecx
	int v6;            // eax
	int v7;            // ecx
	bool v8;           // cc
	unsigned char v9;  // bl
	int v10;           // edi
	int* v11;          // eax
	int v12;           // edx
	int* v13;          // ebx
	char* v14;         // ebp
	int v15;           // esi
	int v16;           // edi
	int v17;           // edx
	char* v18;         // eax
	unsigned char v19; // [esp+10h] [ebp-88h]
	unsigned char v20; // [esp+10h] [ebp-88h]
	unsigned char v21; // [esp+14h] [ebp-84h]
	int v22[32];       // [esp+18h] [ebp-80h]

	v1 = 0;
	v19 = 0;
	if (a1) {
		for (i = nox_server_teamFirst_418B10(); i; i = nox_server_teamNext_418B60((int)i)) {
			sub_418D80((int)i);
		}
	}
	result = nox_common_playerInfoGetFirst_416EA0();
	v4 = result;
	if (!result) {
		return;
	}
	do {
		v5 = *((uint32_t*)v4 + 514);
		if (v5 && (*((uint32_t*)v4 + 515) != nox_player_netCode_85319C ||
				   !nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING))) {
			v6 = *((uint32_t*)v4 + 920);
			if ((!(v6 & 1) || v6 & 0x20) && !nox_xxx_servObjectHasTeam_419130(v5 + 48)) {
				v7 = v19;
				v19 = ++v1;
				v22[v7] = *((uint32_t*)v4 + 514);
			}
		}
		result = nox_common_playerInfoGetNext_416EE0((int)v4);
		v4 = result;
	} while (result);
	if (!v1) {
		return;
	}
	v8 = v1 <= 1u;
	v9 = v19;
	if (!v8) {
		v10 = 50;
		do {
			v20 = nox_common_randomInt_415FA0(0, v9 - 1);
			v21 = nox_common_randomInt_415FA0(0, v9 - 1);
			v11 = &v22[v20];
			--v10;
			v12 = *v11;
			*v11 = v22[v21];
			v22[v21] = v12;
		} while (v10);
	}
	result = (char*)v9;
	if ((int)v9 <= 0) {
		return;
	}
	v13 = v22;
	v14 = result;
	do {
		v15 = *v13;
		v16 = *(uint32_t*)(*v13 + 748);
		if (sub_40A740()) {
			v17 = *(uint32_t*)(v16 + 276);
			result = *(char**)(v17 + 2068);
			if (result) {
				result = nox_server_teamByXxx_418AE0(*(uint32_t*)(v17 + 2068));
				if (result) {
					nox_xxx_createAtImpl_4191D0(result[57], v15 + 48, 1, *(uint32_t*)(v15 + 36), 0);
				}
			}
		} else {
			v18 = sub_4189D0();
			nox_xxx_createAtImpl_4191D0(v18[57], v15 + 48, 1, *(uint32_t*)(v15 + 36), 1);
		}
		++v13;
		--v14;
	} while (v14);
}
// 4181F0: using guessed type int var_80[32];

//----- (00418390) --------------------------------------------------------
int sub_418390() {
	if (!nox_xxx_getTeamCounter_417DD0()) {
		return 0;
	}
	nox_xxx_SetGameplayFlag_417D50(2);
	sub_4181F0(0);
	return 1;
}

//----- (004183C0) --------------------------------------------------------
int sub_4183C0() {
	int result; // eax
	int i;      // esi
	int v2;     // eax
	int v3;     // eax
	int v4;     // eax
	char* v5;   // ebp
	int v6;     // edi
	char* v7;   // ecx
	int v8;     // eax
	double v9;  // st7
	double v10; // st6
	double v11; // st5
	float v12;  // [esp+0h] [ebp-4h]

	result = nox_xxx_getFirstPlayerUnit_4DA7C0();
	for (i = result; result; i = result) {
		v2 = *(uint32_t*)(i + 748);
		if (!v2 || ((v3 = *(uint32_t*)(v2 + 276), *(uint32_t*)(v3 + 2060) != nox_player_netCode_85319C) ||
					!nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) &&
					   ((v4 = *(uint32_t*)(v3 + 3680), !(v4 & 1)) || v4 & 0x20)) {
			v5 = nox_xxx_clientGetTeamColor_418AB0(*(unsigned char*)(i + 52));
			v6 = 0;
			v12 = 1000000000.0;
			v7 = nox_server_teamFirst_418B10();
			if (v7) {
				do {
					v8 = *((uint32_t*)v7 + 18);
					if (v8) {
						v9 = *(float*)(v8 + 60) - *(float*)(i + 60);
						v10 = *(float*)(v8 + 56) - *(float*)(i + 56);
						v11 = v10 * v10 + v9 * v9;
						if (v11 < v12) {
							v12 = v11;
							v6 = (int)v7;
						}
					}
					v7 = nox_server_teamNext_418B60((int)v7);
				} while (v7);
				if (v6) {
					if (v5) {
						if ((char*)v6 != v5) {
							sub_4196D0(i + 48, v6, *(uint32_t*)(i + 36), 0);
						}
					} else {
						nox_xxx_createAtImpl_4191D0(*(uint8_t*)(v6 + 57), i + 48, 1, *(uint32_t*)(i + 36), 0);
					}
				}
			}
		}
		result = nox_xxx_getNextPlayerUnit_4DA7F0(i);
	}
	return result;
}

//----- (004184D0) --------------------------------------------------------
void sub_4184D0(nox_team_t* a1p) {
	wchar_t* a1 = a1p;
	int v1;       // edi
	uint32_t* v2; // ebp
	char v3[18];  // [esp+4h] [ebp-14h]

	if (a1) {
		sub_457230(a1);
		*(uint32_t*)&v3[6] = *((uint32_t*)a1 + 15);
		*(uint32_t*)&v3[2] = *((unsigned char*)a1 + 57);
		*(uint16_t*)v3 = 196;
		*(uint32_t*)&v3[10] = *((uint32_t*)a1 + 13);
		v3[14] = 0;
		v3[16] = *((uint8_t*)a1 + 56);
		v3[17] = *((uint8_t*)a1 + 68);
		if (nox_common_gameFlags_check_40A5C0(512)) {
			v3[14] = 1;
		}
		v3[15] = nox_wcslen(a1);
		v1 = 2 * (unsigned char)v3[15];
		v2 = calloc(1, v1 + 18);
		*(uint64_t*)v2 = *(uint64_t*)v3;
		v2[2] = *(uint32_t*)&v3[8];
		v2[3] = *(uint32_t*)&v3[12];
		*((uint16_t*)v2 + 8) = *(uint16_t*)&v3[16];
		memcpy((char*)v2 + 18, a1, 2 * (unsigned char)v3[15]);
		nox_xxx_netSendPacket1_4E5390(159, (int)v2, v1 + 18, 0, 1);
		free(v2);
	}
}

//----- (004185B0) --------------------------------------------------------
int nox_xxx_wndGuiTeamCreate_4185B0() {
	int result;  // eax
	int i;       // esi
	char* v2;    // edi
	int v3;      // eax
	char v4;     // bl
	wchar_t* v5; // eax

	nox_xxx_SetGameplayFlag_417D50(4);
	nox_xxx_teamCreate_4186D0(0);
	nox_xxx_teamCreate_4186D0(0);
	result = nox_server_getFirstObject_4DA790();
	for (i = result; result; i = result) {
		if (*(uint32_t*)(i + 8) & 0x10000000) {
			v2 = nox_xxx_clientGetTeamColor_418AB0(*(unsigned char*)(i + 52));
			if (v2) {
				v3 = sub_4ECBD0(i);
				v4 = v3;
				v5 = nox_server_teamTitle_418C20(v3);
				if (v5) {
					sub_418800((wchar_t*)v2, v5, 1);
				}
				v2[56] = v4;
				sub_4184D0((wchar_t*)v2);
				*((uint32_t*)v2 + 18) = i;
			}
		}
		result = nox_server_getNextObject_4DA7A0(i);
	}
	return result;
}

//----- (00418640) --------------------------------------------------------
int nox_xxx_teamAssignFlags_418640() {
	int result; // eax
	int i;      // esi
	char v2;    // bl
	char* v3;   // eax

	result = nox_server_getFirstObject_4DA790();
	for (i = result; result; i = result) {
		if (*(uint32_t*)(i + 8) & 0x10000000) {
			v2 = sub_4ECBD0(i);
			v3 = nox_xxx_clientGetTeamColor_418AB0(*(unsigned char*)(i + 52));
			if (v3) {
				v3[56] = v2;
				*((uint32_t*)v3 + 18) = i;
			}
		}
		result = nox_server_getNextObject_4DA7A0(i);
	}
	return result;
}

//----- (00418690) --------------------------------------------------------
char* nox_xxx_toggleAllTeamFlags_418690(int a1) {
	char* result; // eax
	char* i;      // esi
	int v3;       // [esp-8h] [ebp-Ch]

	result = nox_server_teamFirst_418B10();
	for (i = result; result; i = result) {
		if (*((uint32_t*)i + 18)) {
			v3 = *((uint32_t*)i + 18);
			if (a1) {
				nox_xxx_objectSetOn_4E75B0(v3);
			} else {
				nox_xxx_objectSetOff_4E7600(v3);
			}
		}
		result = nox_server_teamNext_418B60((int)i);
	}
	return result;
}
