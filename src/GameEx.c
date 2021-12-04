#define DG_DYNARR_IMPLEMENTATION
#include "GameEx.h"
#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_3.h"
#include "GAME3_1.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4.h"
#include "GAME5_2.h"
#include "client__gui__guimsg.h"
#include "client__gui__window.h"
#include "common/fs/nox_fs.h"
#include "memmap.h"

#include "client__shell__noxworld.h"
#include "common__config.h"
#include "operators.h"

#ifndef NOX_CGO
#include <SDL2/SDL.h>

#include "DG_dynarr.h"

typedef struct keyCodeStruct {
	unsigned char keyCode;
	char keyName[12];
} keyCodeStruct;

typedef struct smallPlayerStruct {
	char string[18];
} smallPlayerStruct;

DA_TYPEDEF(smallPlayerStruct, smallPlayerStructVector);
DA_TYPEDEF(int, intArray);
#endif // NOX_CGO

extern int nox_win_width_game;
extern int nox_win_height_game;
extern int dword_5d4594_3484;
extern nox_object_t* nox_xxx_host_player_unit_3843628;
extern nox_window* dword_5d4594_1064896;
extern void* nox_win_activeWindow_1064900;
extern unsigned int dword_587000_87404;
extern unsigned int dword_5d4594_1064868;
extern unsigned int dword_5d4594_1316972;
extern uint32_t nox_player_netCode_85319C;
extern nox_net_struct_t* nox_net_struct_arr[NOX_NET_STRUCT_MAX];
extern nox_window* nox_win_unk3;

//-------------------------------------------------------------------------
// Data declarations

unsigned int gameex_flags = 0x1E;

#ifndef NOX_CGO
keyCodeStruct keycodeArray[] = {
	{183u, "print scren"},
	{210u, "insert"},
	{211u, "delete"},
	{199u, "home"},
	{207u, "end"},
	{197u, "pause break"},
	{41u, "~"},
	{2u, "1"},
	{3u, "2"},
	{4u, "3"},
	{5u, "4"},
	{6u, "5"},
	{7u, "6"},
	{8u, "7"},
	{9u, "8"},
	{10u, "9"},
	{11u, "0"},
	{12u, "-"},
	{13u, "="},
	{14u, "backspace"},
	{181u, "num /"},
	{55u, "num *"},
	{74u, "num -"},
	{71u, "num 7"},
	{72u, "num 8"},
	{73u, "num 9"},
	{75u, "num 4"},
	{76u, "num 5"},
	{77u, "num 6"},
	{79u, "num 1"},
	{80u, "num 2"},
	{81u, "num 3"},
	{78u, "num +"},
	{82u, "num 0"},
	{83u, "del"},
	{156u, "enter2"},
	{15u, "tab"},
	{16u, "q"},
	{17u, "w"},
	{18u, "e"},
	{19u, "r"},
	{20u, "t"},
	{21u, "y"},
	{22u, "u"},
	{23u, "i"},
	{24u, "o"},
	{25u, "p"},
	{26u, "["},
	{27u, "]"},
	{28u, "enter"},
	{30u, "a"},
	{31u, "s"},
	{32u, "d"},
	{33u, "f"},
	{34u, "g"},
	{35u, "h"},
	{36u, "j"},
	{37u, "k"},
	{38u, "l"},
	{39u, ";"},
	{40u, "'"},
	{43u, "\\"},
	{42u, "left shift"},
	{86u, "|"},
	{44u, "z"},
	{45u, "x"},
	{46u, "c"},
	{47u, "v"},
	{48u, "b"},
	{49u, "n"},
	{50u, "m"},
	{51u, ","},
	{52u, "."},
	{53u, "/"},
	{54u, "right shift"},
	{29u, "left ctrl"},
	{56u, "left alt"},
	{57u, "spacebar"},
	{184u, "right alt"},
	{201u, "page up"},
	{209u, "page down"},
	{157u, "right ctrl"},
	{200u, "up"},
	{203u, "left"},
	{208u, "down"},
	{205u, "right"},
	{0, 0},
};
int keycodeArraySize = sizeof(keycodeArray) / sizeof(keyCodeStruct);
unsigned char functionalKeyCodes[] = {2u, 3u, 4u, 5u, 6u, 156u, 0u};
char* EndOfKeyCodeArray = 0; // weak
void* modifyWndPntr = 0;     // weak
unsigned char serverData[64];
intArray gameIps;
#endif                       // NOX_CGO

int DefaultPacket[4] = {171901697, 1, 347, 44391266}; // weak
wchar_t wndEntryNames[5][35] = {
	{119u, 97u,  114u, 114u, 105u, 111u, 114u, 115u, 32u, 108u, 105u, 107u, 101u, 32u, 115u, 104u, 105u, 101u,
	 108u, 100u, 115u, 0u,   0u,   0u,   0u,   0u,   0u,  0u,   0u,   0u,   0u,   0u,  0u,   0u,   0u},
	{119u, 97u, 108u, 107u, 105u, 110u, 103u, 32u, 119u, 105u, 116u, 104u, 32u, 115u, 119u, 111u, 114u, 100u,
	 32u,  98u, 108u, 111u, 99u,  107u, 0u,   0u,  0u,   0u,   0u,   0u,   0u,  0u,   0u,   0u,   0u},
	{119u, 101u, 97u, 112u, 111u, 110u, 32u, 114u, 111u, 108u, 108u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
	 0u,   0u,   0u,  0u,   0u,   0u,   0u,  0u,   0u,   0u,   0u,   0u, 0u, 0u, 0u, 0u, 0u},
	{115u, 104u, 105u, 101u, 108u, 100u, 32u,  38u,  32u,  98u, 101u, 114u, 115u, 101u, 114u, 107u, 101u, 114u,
	 32u,  98u,  108u, 111u, 99u,  107u, 105u, 110u, 103u, 0u,  0u,   0u,   0u,   0u,   0u,   0u,   0u},
	{101u, 120u, 116u, 101u, 110u, 115u, 105u, 111u, 110u, 32u, 109u, 101u, 115u, 115u, 97u, 103u, 101u, 115u,
	 0u,   0u,   0u,   0u,   0u,   0u,   0u,   0u,   0u,   0u,  0u,   0u,   0u,   0u,   0u,  0u,   0u}};
char someSwitch = 0;        // weak
char isInvalidIp = 0;       // weak
char inputNewIpMsgBox[512]; // weak


int nox_CharToOemW(const wchar_t* pSrc, char* pDst) { return nox_sprintf(pDst, "%S", pSrc); }

#ifndef NOX_CGO
//----- (10001000) --------------------------------------------------------
int GameEx_DllMain(uint32_t fdwReason) {
	static char isLoaded = 0;
	if (fdwReason && fdwReason == 1 && !isLoaded) {
		da_init(gameIps);
		isLoaded = 1;
		// MEMACCESS(0x581354) = MixRecvFromReplacer; // It is replaced elsewhere
		EndOfKeyCodeArray = &keycodeArray[keycodeArraySize - 1];
		if (!GameExCfgLoader())
			fprintf(stderr, "Failed to read game_ex.cfg !\n");
	}
	return 1;
}
// 10012BCC: using guessed type char isLoaded;

//----- (10001230) --------------------------------------------------------
unsigned char KeyCodeMatcher(char* a1) {
	int v1;   // ecx
	char* v2; // edi
	char* v3; // esi
	char* v4; // eax
	char v5;  // dl
	char v6;  // bl

	v1 = 0;
	v2 = keycodeArray[0].keyName;
	do {
		v3 = v2;
		v4 = a1;
		if (a1 && v2) {
			while (1) {
				v5 = *v4;
				v6 = *v3++;
				++v4;
				if (v5 != v6)
					break;
				if (!*v4)
					goto LABEL_8;
				if (!*v3) {
					if (*v4)
						break;
				LABEL_8:
					if (*v3)
						break;
					return keycodeArray[v1].keyCode;
				}
			}
		}
		v2 += 13;
		++v1;
	} while ((signed int)v2 < (signed int)&EndOfKeyCodeArray[1]);
	return -1;
}

//----- (10001290) --------------------------------------------------------
void GameExCfgSaver() {
	int result;         // eax
	void* v1;           // esi
	const char* v2;     // eax
	const char* v3;     // eax
	const char* v4;     // eax
	const char* v5;     // eax
	const char* v6;     // eax
	int v7;             // ecx
	keyCodeStruct* v8;  // eax
	char* v9;           // ecx
	int v10;            // ecx
	keyCodeStruct* v11; // eax
	char* v12;          // ecx
	int v13;            // ecx
	keyCodeStruct* v14; // eax
	char* v15;          // ecx
	int v16;            // ecx
	keyCodeStruct* v17; // eax
	char* v18;          // ecx
	int v19;            // ecx
	keyCodeStruct* v20; // eax
	char* v21;          // ecx
	int v22;            // ecx
	keyCodeStruct* v23; // eax
	char* v24;          // ecx
	// uint32_t NumberOfBytesWritten; // [esp+12Ch] [ebp-4h]
	// char v26; // [esp+134h] [ebp+4h]
	// char v27; // [esp+138h] [ebp+8h]

	result = nox_fs_create_text("game_ex.cfg");
	v1 = (void*)result;
	if (result == 0) {
		return;
	}
	nox_fs_fwrite(v1, "AUTO_SHIELD = ", 0xE);
	v2 = "1\r\n";
	if (!((gameex_flags >> 1) & 1))
		v2 = "0\r\n";
	nox_fs_fwrite(v1, v2, 3);
	nox_fs_fwrite(v1, "GREAT_SWORD_BLOKING_WALK = ", 0x1B);
	v3 = "1\r\n";
	if (!((gameex_flags >> 2) & 1))
		v3 = "0\r\n";
	nox_fs_fwrite(v1, v3, 3);
	nox_fs_fwrite(v1, "MOUSE_KEYBOARD_ROLL = ", 0x16);
	v4 = "1\r\n";
	if (!((gameex_flags >> 3) & 1))
		v4 = "0\r\n";
	nox_fs_fwrite(v1, v4, 3);
	nox_fs_fwrite(v1, "BERSERKER_SHIED_BLOCK = ", 0x18);
	v5 = "1\r\n";
	if (!((gameex_flags >> 4) & 1))
		v5 = "0\r\n";
	nox_fs_fwrite(v1, v5, 3);
	nox_fs_fwrite(v1, "EXTENSION_MESSAGES = ", 0x15);
	v6 = "1\r\n";
	if (!((gameex_flags >> 5) & 1))
		v6 = "0\r\n";
	nox_fs_fwrite(v1, v6, 3);
	nox_fs_fwrite(v1, "PANEL1 = ", 9);
	v7 = 0;
	v8 = keycodeArray;
	while (functionalKeyCodes[0] != v8->keyCode) {
		++v8;
		++v7;
		if ((signed int)v8 >= (signed int)EndOfKeyCodeArray) {
			v9 = 0;
			goto LABEL_17;
		}
	}
	v9 = keycodeArray[v7].keyName;
LABEL_17:
	nox_fs_fwrite(v1, v9, strlen(v9));
	nox_fs_fwrite(v1, "\r\n", 2);
	nox_fs_fwrite(v1, "PANEL2 = ", 9);
	v10 = 0;
	v11 = keycodeArray;
	while (functionalKeyCodes[1] != v11->keyCode) {
		++v11;
		++v10;
		if ((signed int)v11 >= (signed int)EndOfKeyCodeArray) {
			v12 = 0;
			goto LABEL_21;
		}
	}
	v12 = keycodeArray[v10].keyName;
LABEL_21:
	nox_fs_fwrite(v1, v12, strlen(v12));
	nox_fs_fwrite(v1, "\r\n", 2);
	nox_fs_fwrite(v1, "PANEL3 = ", 9);
	v13 = 0;
	v14 = keycodeArray;
	while (functionalKeyCodes[2] != v14->keyCode) {
		++v14;
		++v13;
		if ((signed int)v14 >= (signed int)EndOfKeyCodeArray) {
			v15 = 0;
			goto LABEL_25;
		}
	}
	v15 = keycodeArray[v13].keyName;
LABEL_25:
	nox_fs_fwrite(v1, v15, strlen(v15));
	nox_fs_fwrite(v1, "\r\n", 2);
	nox_fs_fwrite(v1, "PANEL4 = ", 9);
	v16 = 0;
	v17 = keycodeArray;
	while (functionalKeyCodes[3] != v17->keyCode) {
		++v17;
		++v16;
		if ((signed int)v17 >= (signed int)EndOfKeyCodeArray) {
			v18 = 0;
			goto LABEL_29;
		}
	}
	v18 = keycodeArray[v16].keyName;
LABEL_29:
	nox_fs_fwrite(v1, v18, strlen(v18));
	nox_fs_fwrite(v1, "\r\n", 2);
	nox_fs_fwrite(v1, "PANEL5 = ", 9);
	v19 = 0;
	v20 = keycodeArray;
	while (functionalKeyCodes[4] != v20->keyCode) {
		++v20;
		++v19;
		if ((signed int)v20 >= (signed int)EndOfKeyCodeArray) {
			v21 = 0;
			goto LABEL_33;
		}
	}
	v21 = keycodeArray[v19].keyName;
LABEL_33:
	nox_fs_fwrite(v1, v21, strlen(v21));
	nox_fs_fwrite(v1, "\r\n", 2);
	nox_fs_fwrite(v1, "TRAPKEY = ", 0xA);
	v22 = 0;
	v23 = keycodeArray;
	while (functionalKeyCodes[5] != v23->keyCode) {
		++v23;
		++v22;
		if ((signed int)v23 >= (signed int)EndOfKeyCodeArray) {
			v24 = 0;
			goto LABEL_37;
		}
	}
	v24 = keycodeArray[v22].keyName;
LABEL_37:
	nox_fs_fwrite(v1, v24, strlen(v24));
	nox_fs_fwrite(v1, "\r\n----------", 0xC);
	nox_fs_close(v1);
}
// 10001290: could not find valid save-restore pair for ebx
// 10001290: could not find valid save-restore pair for ebp

//----- (10001670) --------------------------------------------------------
const char* SomeStringSearcher(const char* result, const char* a2, char* a3) {
	char* v3;       // edi
	const char* v4; // esi
	char* v5;       // eax
	char i;         // cl

	v3 = a3;
	v4 = a2;
	if (result && a2) {
		v5 = strstr(result, a2);
		if (!v5)
			return result;

		for (result = &v5[strlen(v4)]; *result == 32 || *result == 61; ++result)
			;
		for (i = *result; *result != 13; ++v3) {
			if (i == 10)
				break;
			++result;
			*v3 = i;
			i = *result;
		}
	}
	return result;
}

//----- (100016D0) --------------------------------------------------------
char GameExCfgLoader() {
	HANDLE v0;   // eax
	void* v1;    // ebp
	char result; // al
	uint32_t v3; // edi
	char* v4;    // esi
	// uint32_t NumberOfBytesRead; // [esp+4h] [ebp-18h]
	char v6[32]; // [esp+8h] [ebp-6h]
	memset(v6, 0, sizeof(v6));

	v0 = nox_fs_open("game_ex.cfg");
	v1 = v0;
	if (!v0)
		return 0;
	v3 = nox_fs_fsize(v0);
	if (v3) {
		v4 = (char*)calloc(1, v3 + 1);
		if (nox_fs_fread(v1, v4, v3) == v3) {
			SomeStringSearcher(v4, "AUTO_SHIELD", (char*)&v6);
			if ((uint8_t)*v6 == 48)
				gameex_flags &= 0xFFFFFFFD;
			else
				gameex_flags |= 2u;
			SomeStringSearcher(v4, "GREAT_SWORD_BLOKING_WALK", (char*)&v6);
			if ((uint8_t)*v6 == 48)
				gameex_flags &= 0xFFFFFFFB;
			else
				gameex_flags |= 4u;
			SomeStringSearcher(v4, "MOUSE_KEYBOARD_ROLL", (char*)&v6);
			if ((uint8_t)*v6 == 48)
				gameex_flags &= 0xFFFFFFF7;
			else
				gameex_flags |= 8u;
			SomeStringSearcher(v4, "MOUSE_KEYBOARD_ROLL", (char*)&v6);
			if ((uint8_t)*v6 == 48)
				gameex_flags &= 0xFFFFFFF7;
			else
				gameex_flags |= 8u;
			SomeStringSearcher(v4, "BERSERKER_SHIED_BLOCK", (char*)&v6);
			if ((uint8_t)*v6 == 48)
				gameex_flags &= 0xFFFFFFEF;
			else
				gameex_flags |= 0x10u;
			SomeStringSearcher(v4, "EXTENSION_MESSAGES", (char*)&v6);
			if ((uint8_t)*v6 == 48)
				gameex_flags &= 0xFFFFFFDF;
			else
				gameex_flags |= 0x20u;
			v6[0] = 0;
			SomeStringSearcher(v4, "PANEL1", (char*)&v6);
			functionalKeyCodes[0] = KeyCodeMatcher((char*)&v6);
			v6[0] = 0;
			SomeStringSearcher(v4, "PANEL2", (char*)&v6);
			functionalKeyCodes[1] = KeyCodeMatcher((char*)&v6);
			v6[0] = 0;
			SomeStringSearcher(v4, "PANEL3", (char*)&v6);
			functionalKeyCodes[2] = KeyCodeMatcher((char*)&v6);
			v6[0] = 0;
			SomeStringSearcher(v4, "PANEL4", (char*)&v6);
			functionalKeyCodes[3] = KeyCodeMatcher((char*)&v6);
			v6[0] = 0;
			SomeStringSearcher(v4, "PANEL5", (char*)&v6);
			functionalKeyCodes[4] = KeyCodeMatcher((char*)&v6);
			v6[0] = 0;
			SomeStringSearcher(v4, "TRAPKEY", (char*)&v6);
			functionalKeyCodes[5] = KeyCodeMatcher((char*)&v6);
		}
		free(v4);
		nox_fs_close(v0);
		result = 1;
	} else {
		nox_fs_close(v1);
		result = 0;
	}
	return result;
}
#endif // NOX_CGO

//----- (10001A20) --------------------------------------------------------
int gameex_sendPacket(char* buf, int len, int smth) {
	if (!buf || !len || *getMemU32Ptr(0x5D4594, 815700) >= NOX_NET_STRUCT_MAX) {
		return 0;
	}
	// 0x69B7E8 = netSocketData
	nox_net_struct_t* ns = nox_net_struct_arr[*getMemU32Ptr(0x5D4594, 815700)];
	if (!ns) {
		return 0;
	}
	return nox_net_sendto(ns->sock, buf, len, &ns->addr);
}

//----- (10001AD0) --------------------------------------------------------
void gameex_makeExtensionPacket(int ptr, short opcode, bool needsPlayer) {
	*(uint16_t*)(ptr + 0) = 0xF13A; // extension packet code
	*(uint16_t*)(ptr + 2) = opcode;
	if (needsPlayer)
		*(uint32_t*)(ptr + 4) = (nox_player_netCode_85319C); // playerNetCode
}

//----- (10001B10) --------------------------------------------------------
#ifndef NOX_CGO
void DestroyNoxWindow() {
	uint32_t* v1 = modifyWndPntr;
	nox_xxx_wnd_46C6E0(modifyWndPntr);
	nox_xxx_windowDestroyMB_46C4E0(v1);
}

//----- (10001B40) --------------------------------------------------------
int copyServerMatchData(char* a1) {
	char* v1;   // eax
	char v2;    // cl
	char* v3;   // eax
	char v4;    // cl
	int result; // eax
	int cntr = 0;

	v1 = (char*)getMemAt(0x5D4594, 371389); // gameServerName
	do {
		v2 = *v1;
		a1[cntr] = v2;
		++v1;
	} while (v2);
	*((uint16_t*)a1 + 8) = *getMemU32Ptr(0x5D4594, 371490);
	v3 = (char*)getMemAt(0x5D4594, 371380);
	cntr = 18;
	do {
		v4 = *v3;
		a1[cntr] = v4;
		++v3;
		cntr++;
	} while (v4);
	void* info = sub_416630();
	a1[34] = *getMemU32Ptr(0x5D4594, 371620);
	a1[35] = *getMemU32Ptr(0x5D4594, 373872) + 1;
	a1[36] = *(uint32_t*)info;
	*((uint16_t*)a1 + 20) = *getMemU32Ptr(0x5D4594, 371621);
	*((uint16_t*)a1 + 21) = *getMemU32Ptr(0x5D4594, 371623);
	a1[44] = *getMemU32Ptr(0x5D4594, 371618);
	a1[45] = *(uint32_t*)info;
	a1[37] = sub_409F40(2);
	// a1[38] = MEMACCESS(0x5D5331); // serverRuleFlags + 1
	a1[38] = dword_5d4594_3484 >> 8;
	*((uint32_t*)a1 + 12) = 65540;
	*((uint16_t*)a1 + 26) = nox_win_height_game;
	*((uint16_t*)a1 + 27) = nox_win_width_game;
	*((uint16_t*)a1 + 28) = *getMemU32Ptr(0x5D4594, 371582);
	*((uint16_t*)a1 + 29) = *getMemU32Ptr(0x5D4594, 371586);
	a1[60] = *getMemU32Ptr(0x5D4594, 371494);
	result = *getMemU32Ptr(0x5D4594, 371434);
	*((uint16_t*)a1 + 31) = *getMemU32Ptr(0x5D4594, 371434);
	return result;
}
#endif // NOX_CGO

//----- (10001C20) --------------------------------------------------------
char getPlayerClassFromObjPtr(int a1) { return *(uint8_t*)(*(uint32_t*)(*(uint32_t*)(a1 + 748) + 276) + 2251); }


#ifndef NOX_CGO
//----- (10001C50) --------------------------------------------------------
int playerInfoStructsToVector(smallPlayerStructVector* vector) {
	char* result; // eax
	char* v7;     // esi
	// char v8; // [esp+10h] [ebp-24h]
	smallPlayerStruct pDst; // [esp+18h] [ebp-1Ch]

	result = nox_common_playerInfoGetFirst_416EA0();
	v7 = result;
	if (result) {
		do {
			pDst.string[1] = *((uint8_t*)nox_xxx_objGetTeamByNetCode_418C80(*((uint32_t*)v7 + 515)) + 4);
			pDst.string[0] = v7[2251];
			nox_CharToOemW((const wchar_t*)v7 + 2352, &(pDst.string[2]));
			da_add(*vector, pDst);
			v7 = nox_common_playerInfoGetNext_416EE0((int)v7);
		} while (v7);
		result = da_count(*vector);
	}
	return (int)result;
}
#endif // NOX_CGO

//----- (10001D40) --------------------------------------------------------
char playerInfoStructParser_0(char* a1) {
	char* v1;  // esi
	char pDst; // [esp+10h] [ebp-18h]

	if (a1 == (char*)-2)
		return 0;
	v1 = nox_common_playerInfoGetFirst_416EA0();
	if (!v1)
		return 0;
	while (1) {
		nox_CharToOemW((const wchar_t*)v1 + 2352, &pDst);
		if (!strcmp(&pDst, a1 + 2))
			break;
		v1 = nox_common_playerInfoGetNext_416EE0((int)v1);
		if (!v1)
			return 0;
	}
	a1[1] = *((uint8_t*)nox_xxx_objGetTeamByNetCode_418C80(*((uint32_t*)v1 + 515)) + 4);
	*a1 = v1[2251];
	return 1;
}

//----- (10001E10) --------------------------------------------------------
char playerInfoStructParser_1(int a1, int a2, int* a3) {
	char* v3;     // eax
	char* v4;     // eax
	uint32_t* v6; // eax
	char pDst;    // [esp+Ch] [ebp-18h]

	if (a1 == -2)
		return 0;
	v3 = nox_common_playerInfoGetFirst_416EA0();
	*(uint32_t*)a2 = v3;
	if (!v3)
		return 0;
	while (1) {
		nox_CharToOemW((const wchar_t*)(*(uint32_t*)a2 + 4704), &pDst);
		if (!strcmp(&pDst, (const char*)(a1 + 2)))
			break;
		v4 = nox_common_playerInfoGetNext_416EE0(a2);
		*(uint32_t*)a2 = v4;
		if (!v4)
			return 0;
	}
	v6 = nox_xxx_objGetTeamByNetCode_418C80(*(uint32_t*)(*(uint32_t*)a2 + 2060));
	*a3 = (int)v6;
	*(uint8_t*)(a1 + 1) = *((uint8_t*)v6 + 4);
	*(uint8_t*)a1 = *(uint8_t*)(*(uint32_t*)a2 + 2251);
	return 1;
}

//----- (10001EE0) --------------------------------------------------------
char mix_MouseKeyboardWeaponRoll(int playerObj, char a2) {
	int v2;        // esi
	signed int v4; // edi
	int i;         // esi MAPDST
	int v6;        // eax
	int v8;        // eax
	int weapFlags; // eax
	int v11;       // eax
	char v16;      // [esp+Fh] [ebp-1h]

	v16 = 0;
	v2 = *(uint32_t*)(playerObj + 748);
	if (!(*(uint8_t*)(*(uint32_t*)(v2 + 276) + 3680) & 3) && *(uint8_t*)(v2 + 88) != 1) {
		int cur = *(uint32_t*)(v2 + 104);
		v4 = 496;
		if (!a2)
			v4 = 500;
		if (cur) {
			int next = cur;
			while (1) {
				next = *(uint32_t*)(next + v4);
				if (!next)
					break;
				weapFlags = nox_xxx_weaponInventoryEquipFlags_415820(next); // weaponEquipFlags
				if (weapFlags && weapFlags != 2) {
					if (nox_xxx_playerClassCanUseItem_57B3D0(
							next, *(uint8_t*)(*(uint32_t*)(*(uint32_t*)(playerObj + 748) + 276) + 2251))) {
						v11 = nox_xxx_playerCheckStrength_4F3180(playerObj, next);
						if (v11) {
							if (nox_xxx_playerTryDequip_4F2FB0((uint32_t*)playerObj, (const nox_object_t*)cur) &&
								nox_xxx_playerTryEquip_4F2F70((uint32_t*)playerObj, next)) {
								v16 = 1;
							}
							return v16;
						}
					}
				}
			}
		} else {
			for (i = *(uint32_t*)(playerObj + 504); i; i = *(uint32_t*)(i + 496)) {
				v6 = nox_xxx_weaponInventoryEquipFlags_415820(i); // weaponEquipFlags
				if (v6 && v6 != 2) {
					if (nox_xxx_playerClassCanUseItem_57B3D0(
							i, *(uint8_t*)(*(uint32_t*)(*(uint32_t*)(playerObj + 0x2EC) + 0x114) + 0x8CB))) {
						v8 = nox_xxx_playerCheckStrength_4F3180(playerObj, i);
						if (v8) {
							if (nox_xxx_playerTryEquip_4F2F70((uint32_t*)playerObj, i)) {
								v16 = 1;
							}
							return v16;
						}
					}
				}
			}
		}
	}
	return v16;
}
/* Orphan comments:
playerCanUseItem
playerCheckStrength
*/

//----- (10002030) --------------------------------------------------------
char playerDropATrap(int playerObj) {
	int v2; // eax
	int i;  // esi
	// int v5; // [esp+10h] [ebp-14h]
	char v7; // [esp+18h] [ebp-Ch]
	char v8; // [esp+1Fh] [ebp-5h]
	float pos[2] = {0};

	v7 = 17;
	if (!playerObj)
		return 0;
	v8 = 0;
	v2 = *(uint32_t*)(*(uint32_t*)(playerObj + 0x2EC) + 0x114);
	pos[0] = *(float*)(v2 + 0xE30);
	pos[1] = *(float*)(v2 + 0xE34);
	if (!(*(uint8_t*)(*(uint32_t*)(*(uint32_t*)(playerObj + 0x2EC) + 0x114) + 0xE60) &
		  3) // check playerGameStatus/isObs
		&& *(uint8_t*)(*(uint32_t*)(playerObj + 0x2EC) + 0x58) != 1) {
		for (i = *(uint32_t*)(playerObj + 0x1F8); i; i = *(uint32_t*)(i + 0x1F0)) {
			if (*(uint8_t*)(i + 0xA) == v7) // check if something from *(byte*)(unit+0xA)=17
			{
				nox_xxx_drop_4ED810(playerObj, i, pos); // drop this item
				return 1;
			}
		}
	}
	return v8;
}

//----- (100020F0) --------------------------------------------------------
#ifndef NOX_CGO
void* GameIpParser(int a1, int a2, int a3) {
	HANDLE result;                 // eax MAPDST
	uint32_t fileSize;             // esi MAPDST
	unsigned int fileBufferSize;   // ebp
	unsigned int fileBufferOffset; // esi
	unsigned int v9;               // ecx
	char currentFileBufferPntr;    // al
	uint32_t NumberOfBytesRead;    // [esp+4h] [ebp-28h]
	void* fileBuffer;              // [esp+8h] [ebp-24h]
	char cp[20];                   // [esp+14h] [ebp-18h]

	result = nox_fs_open_text("game_ip.txt");
	if (result) {
		fileSize = nox_fs_fsize(result);
		if (fileSize) {
			fileBufferSize = fileSize + 1;
			NumberOfBytesRead = 0;
			*(uint32_t*)cp = 0;
			*(uint32_t*)&cp[4] = 0;
			*(uint32_t*)&cp[8] = 0;
			*(uint32_t*)&cp[12] = 0;
			*(uint32_t*)&cp[16] = 0;
			fileBuffer = calloc(1, fileBufferSize);
			if (nox_fs_fread(result, fileBuffer, fileSize) == fileSize) {
				fileBufferOffset = 0;
				v9 = 0;
				if (fileBufferSize) {
					do {
						if (v9 > 0x14)
							break;
						currentFileBufferPntr = *((uint8_t*)fileBuffer + fileBufferOffset);
						if (currentFileBufferPntr == 44 || fileBufferOffset == fileSize ||
							currentFileBufferPntr == 32 || currentFileBufferPntr == 10) {
							if (v9) {
								NumberOfBytesRead = inet_addr(cp);
								nox_client_sendToServer_555010(NumberOfBytesRead, a2, (char*)a1, a3);
								*(uint32_t*)cp = 0;
								*(uint32_t*)&cp[4] = 0;
								*(uint32_t*)&cp[8] = 0;
								*(uint32_t*)&cp[12] = 0;
								*(uint32_t*)&cp[16] = 0;
								v9 = 0;
							}
						} else if (currentFileBufferPntr > 41 && currentFileBufferPntr < 64 ||
								   currentFileBufferPntr == 46) {
							cp[v9++] = currentFileBufferPntr;
						}
						++fileBufferOffset;
					} while (fileBufferOffset < fileBufferSize);
				}
			}
			free(fileBuffer);
		}
		nox_fs_close(result);
		result = 0;
	}
	return result;
}

//----- (10002240) --------------------------------------------------------
unsigned int pingAllServersInGameIp(int ebx0, int edi0, int a1, int a2, int a3) {
	int* it;
	int* end = da_end(gameIps);

	for (it = da_begin(gameIps), end = da_end(gameIps); it != end; ++it) {
		nox_client_sendToServer_555010(*it, a1, (char*)a2,
									   a3); // Вызывает какую-то функцию которая создаёт структуру сокета и отпр 16 байт
	}
	return end;
}
// 10012BE4: using guessed type int vectorEnd;

//----- (10002300) --------------------------------------------------------
signed int inputNewIp_(int a1, int ebx0, int a2, int a3, int a4) {
	unsigned int v6;     // [esp+10h] [ebp-2Ch]
	int v7;              // [esp+14h] [ebp-28h]
	const wchar_t* pSrc; // [esp+18h] [ebp-24h]
	char pDst[28];       // [esp+1Ch] [ebp-20h]

	v7 = nox_xxx_wndGetID_46B0A0((int*)a4);
	pSrc = (const wchar_t*)sub_449E60(-88);
	nox_xxx_clientPlaySoundSpecial_452D80(766, 100); // playSound
	if (v7 == 4001) {
		if (nox_CharToOemW(pSrc, pDst)) {
			v6 = inet_addr(pDst);
			if (v6 != -1 && &pDst[strlen(pDst) + 1] != &pDst[1]) {
				da_add(gameIps, v6);
				isInvalidIp = 0;
				return 1;
			}
		}
		nox_xxx_clientPlaySoundSpecial_452D80(925, 100); // playSound
	}
	isInvalidIp = 1;
	return 0;
}
#endif // NOX_CGO
// 100129C1: using guessed type char isInvalidIp;
// 10002300: using guessed type char pDst[28];

//----- (100023E0) --------------------------------------------------------
void playErrSoundClient() { nox_xxx_clientPlaySoundSpecial_452D80(766, 100); }

//----- (10002400) --------------------------------------------------------
#ifndef NOX_CGO
unsigned int invalidIpChecker(unsigned int interval, void* param) {
	while (sub_44A4A0())
		return 1;
	if (isInvalidIp) {
		nox_xxx_dialogMsgBoxCreate_449A10(0, 0, (int)L"Invalid Address", 33, playErrSoundClient, 0);
		return 0;
	}
	nox_client_refreshServerList_4378B0();
	return 0;
}
// 1000F110: using guessed type wchar_t aInvalidAddress[16];
// 100129C1: using guessed type char isInvalidIp;

//----- (10002470) --------------------------------------------------------
int startInvalidIpChecker() {
	int result = 0; // eax

	if (!dword_587000_87404)
		result = SDL_AddTimer(300, invalidIpChecker, NULL);
	return result;
}

//----- (100024A0) --------------------------------------------------------
int modifyWndInputHandler(int a1, int a2, int a3, int a4) {
	unsigned int v4; // eax
	int result;      // eax
	uint32_t* v6;    // edi

	if (a2 != 16391)
		return 0;
	nox_xxx_clientPlaySoundSpecial_452D80(766, 100);
	v4 = nox_xxx_wndGetID_46B0A0((int*)a3);
	if (v4 > 0x791) {
		if (v4 == 1938 && !nox_common_gameFlags_check_40A5C0(512)) {
			sub_4BDFD0();
			nox_window_setPos_46A9B0(dword_5d4594_1316972, 200, 100);
		}
		return 0;
	}
	if (v4 == 1937) {
		GameExCfgSaver();
		v6 = modifyWndPntr;
		nox_xxx_wnd_46C6E0((int)modifyWndPntr);
		nox_xxx_windowDestroyMB_46C4E0(v6);
		modifyWndPntr = 0;
		result = 0;
	} else {
		switch (v4) {
		case 0x5F0u:
			if ((gameex_flags >> 1) & 1)
				gameex_flags &= 0xFFFFFFFD;
			else
				gameex_flags |= 2u;
			result = 0;
			break;
		case 0x5F1u:
			if ((gameex_flags >> 2) & 1)
				gameex_flags &= 0xFFFFFFFB;
			else
				gameex_flags |= 4u;
			result = 0;
			break;
		case 0x5F2u:
			if ((gameex_flags >> 3) & 1)
				gameex_flags &= 0xFFFFFFF7;
			else
				gameex_flags |= 8u;
			result = 0;
			break;
		case 0x5F3u:
			if ((gameex_flags >> 4) & 1)
				gameex_flags &= 0xFFFFFFEF;
			else
				gameex_flags |= 0x10u;
			result = 0;
			break;
		case 0x5F4u:
			if ((gameex_flags >> 5) & 1)
				gameex_flags &= 0xFFFFFFDF;
			else
				gameex_flags |= 0x20u;
			result = 0;
			break;
		default:
			return 0;
		}
	}
	return result;
}
#endif // NOX_CGO

//----- (10002680) --------------------------------------------------------
int MixRecvFromReplacer(nox_socket_t s, char* buf, int len, struct nox_net_sockaddr* from) {
	uint32_t* v8; // esi
	char v9;      // al
	int v10;      // esi
	int v11;      // edx
	// uint32_t *v12; // esi
	char* v13; // edi
	// int v14; // eax
	// unsigned int v15; // esi
	// int *v16; // eax
	// int v17; // eax
	char* v18;          // eax
	char v19;           // cl
	char* v20;          // eax
	char* v21;          // edx
	char v22;           // cl
	int v23;            // edx
	int v24;            // eax
	int v25;            // ecx
	char* v26;          // edi
	char* v27;          // eax
	char v28;           // cl
	unsigned int v29;   // kr00_4
	char* v30;          // edx
	unsigned int v31;   // ecx
	unsigned char* v32; // esi
	char v33;           // bl
	uint32_t* v35;      // eax
	char v36;           // [esp+17h] [ebp-CDh]
	// int a1[2]; // [esp+1Ch] [ebp-C8h]
	struct nox_net_sockaddr* to; // [esp+24h] [ebp-C0h]
	int v39;                     // [esp+28h] [ebp-BCh]
	// int a2[2]; // [esp+34h] [ebp-B0h]
	int v43[6];              // [esp+3Ch] [ebp-A8h]
	unsigned char v44[0x80]; // [esp+54h] [ebp-90h]
	// int v45; // [esp+E0h] [ebp-4h]

	to = from;
	int op = *((unsigned short*)buf + 1);
	switch (op) {
	case 0: // warrior weapon scroll
		if ((gameex_flags >> 3) & 1) {
			v8 = nox_xxx_objGetTeamByNetCode_418C80(*((uint32_t*)buf + 1));
			v9 = buf[8];
			v10 = (int)(v8 - 12);
			v36 = ((unsigned int)v9 >> 4) & 1;
			if (v36)
				buf[8] = v9 & 0xEF;
			if (!getPlayerClassFromObjPtr(v10) || v36) {
				if (mix_MouseKeyboardWeaponRoll(v10, buf[8])) {
					*((uint16_t*)buf + 1) = 2;
					nox_net_sendto(s, buf, 4, from);
				}
			}
		}
		break;
	case 1u:
	case 6u:
		break;
	case 2u: // clientPlaySoundSpecial
		nox_xxx_clientPlaySoundSpecial_452D80(895, 100);
		break;
#ifndef NOX_CGO
	case 3u: // Send back playerInfoStructs
		if (nox_common_gameFlags_check_40A5C0(1) && (gameex_flags >> 5) & 1) {
			smallPlayerStructVector vector;
			smallPlayerStruct* it;
			smallPlayerStruct* end;

			da_init(vector);
			// v45 = 0;
			if (playerInfoStructsToVector(&vector)) {
				copyServerMatchData((char*)v44);
				v11 = gameex_flags;
				v39 = 18 * da_count(vector) + 68;
				memcpy(buf + 8, v44, 0x40u);
				*((uint32_t*)buf + 1) = v11;
				if (da_count(vector) > 0) {
					v13 = buf + 72;
					for (it = da_begin(vector), end = da_end(vector); it != end; ++it) {
						*(uint32_t*)v13 = *(uint32_t*)(it->string);
						*((uint32_t*)v13 + 1) = *(uint32_t*)((it->string) + 4);
						*((uint32_t*)v13 + 2) = *(uint32_t*)((it->string) + 8);
						*((uint32_t*)v13 + 3) = *(uint32_t*)((it->string) + 12);
						*((uint16_t*)v13 + 8) = *(uint16_t*)((it->string) + 16);
						v13 += 18;
					}
				}
				nox_net_sendto(s, buf, v39, to);
			}
			da_free(vector);
		}
		break;
#endif // NOX_CGO
	case 4u:
		if (nox_common_gameFlags_check_40A5C0(1)) {
			if ((gameex_flags >> 5) & 1) {
				v18 = buf + 4;
				do {
					v19 = *v18;
					v18[(char*)v43 + 2 - (buf + 4)] = *v18;
					++v18;
				} while (v19);
				if (playerInfoStructParser_0((char*)v43)) {
					buf[2] = 6;
					v20 = sub_433890();
					v21 = (char*)v43 + 2;
					do {
						v22 = *v20;
						*v21++ = *v20++;
					} while (v22);
					v23 = v43[1];
					v24 = v43[2];
					*((uint32_t*)buf + 1) = v43[0];
					v25 = v43[3];
					*((uint32_t*)buf + 2) = v23;
					LOWORD(v23) = v43[4];
					*((uint32_t*)buf + 3) = v24;
					*((uint32_t*)buf + 4) = v25;
					*((uint16_t*)buf + 10) = v23;
					nox_net_sendto(s, buf, 22, from);
				}
			}
		}
		break;
	case 5u:
		if ((gameex_flags >> 5) & 1) {
			memset(v44, 0, 0x80u);
			mbstowcs((wchar_t*)v44, buf + 4, strlen(buf + 4));
			nox_xxx_printCentered_445490((wchar_t*)v44);
			nox_xxx_clientPlaySoundSpecial_452D80(901, 100);
		}
		break;
	case 7u:
		memset(v44, 0, 0x80u);
		mbstowcs((wchar_t*)v44, buf + 4, strlen(buf + 4));
		nox_xxx_printCentered_445490((wchar_t*)v44);
		nox_xxx_clientPlaySoundSpecial_452D80(901, 100);
		break;
	case 8u:
		if (nox_common_gameFlags_check_40A5C0(1) && (gameex_flags >> 5) & 1) {
			v26 = buf + 4;
			v27 = buf + 4;
			do {
				v28 = *v27;
				v27[(char*)v43 + 2 - (buf + 4)] = *v27;
				++v27;
			} while (v28);
			if (playerInfoStructParser_1((int)v43, (int)&to, &v39)) {
				buf[2] = 7;
				v29 = strlen((const char*)v43 + 2);
				v30 = &buf[v29 + 4];
				v31 = strlen(v30);
				if (v31) {
					v32 = (unsigned char*)(v44 - (unsigned char*)v30);
					do {
						v33 = *v30;
						v30[(uint32_t)v32] = *v30;
						++v30;
					} while (v33);
					memset(v26, 0, v29 + v31);
					strcpy(v26, (const char*)v44);
				}
			}
		}
		break;
	case 9u:
		if ((gameex_flags >> 3) & 1) {
			v35 = nox_xxx_objGetTeamByNetCode_418C80(*((uint32_t*)buf + 1));
			playerDropATrap((int)(v35 - 12));
		}
		break;
	}
	// replace Mix packet with a placeholder
	*((uint32_t*)buf + 0) = DefaultPacket[0];
	*((uint32_t*)buf + 1) = DefaultPacket[1];
	*((uint32_t*)buf + 2) = DefaultPacket[2];
	*((uint32_t*)buf + 3) = DefaultPacket[3];
	return 16;
}
// 1000EF00: using guessed type int DefaultPacket[4];

//----- (10002C30) --------------------------------------------------------
void OnLibraryNotice_256() {}
void OnLibraryNotice_258() {
	// is called from exe from here: 0x980650
	someSwitch = 1;
}
void OnLibraryNotice_259(uint32_t arg1) {}

#ifndef NOX_CGO
void OnLibraryNotice_257() { nox_xxx_host_player_unit_3843628 = 0; }

void OnLibraryNotice_260(uint32_t arg1, uint32_t arg2, uint32_t arg3) {
	// pings all servers from game_ip.txt
	int v1 = 0;
	GameIpParser(arg2, arg1, arg3);
	pingAllServersInGameIp(arg2, v1, arg1, arg2, arg3);
}

void OnLibraryNotice_261() {
	unsigned char v24[64]; // [esp+1Ch] [ebp-50h]
	// is called when game parameters change via UI
	// it just copies server data to a serverData variable
	copyServerMatchData((char*)v24);
	uint32_t* result = (uint32_t*)64;
	int v5 = 0;
	while (*(uint32_t*)&serverData[v5] == *(uint32_t*)&v24[v5]) {
		--result;
		v5 += 4;
		if ((unsigned int)result < 4)
			return;
	}
	memcpy(serverData, v24, sizeof(serverData));
}
#endif // NOX_CGO

void OnLibraryNotice_262(uint32_t arg1) {}
void OnLibraryNotice_263(uint32_t arg1) { nox_common_gameFlags_check_40A5C0(1); }
void OnLibraryNotice_264(uint32_t arg1) { nox_common_gameFlags_check_40A5C0(1); }
#ifdef NOX_CGO
bool gameexSomeWeirdCheckFixmePlease();
#else  // NOX_CGO
bool gameexSomeWeirdCheckFixmePlease() {
	return (((uint32_t)dword_5d4594_1064896 >> 8) | ((unsigned int)nox_win_activeWindow_1064900 << 24)) == 0;
}
#endif // NOX_CGO
void OnLibraryNotice_265(unsigned int arg1, unsigned int arg2, int arg3) {
	// toggles weapons by mouse wheel
	// autoshield is actually implemented in appendix of nox_xxx_playerDequipWeapon_53A140
	// a2a = (*(uint32_t*)(vaArg3 + 4) >> 7) & 1;
	char a2a = arg3 > 0; // scroll weapons back or forth
	if (arg2 == 2 && gameexSomeWeirdCheckFixmePlease()) {
		if ((gameex_flags >> 3) & 1) {
			if (nox_common_gameFlags_check_40A5C0(516)) {
				if (nox_common_gameFlags_check_40A5C0(1)) {
					if (nox_xxx_host_player_unit_3843628) { // playerObjServerHost
						if (!getPlayerClassFromObjPtr(nox_xxx_host_player_unit_3843628)) {
							if (mix_MouseKeyboardWeaponRoll(nox_xxx_host_player_unit_3843628, a2a))
								nox_xxx_clientPlaySoundSpecial_452D80(895, 100); // clientPlaySound
						}
					}
				} else {
					char buf[10];
					gameex_makeExtensionPacket((int)&buf, 0, 1);
					buf[8] = a2a;
					gameex_sendPacket(&buf, 9, 0);
				}
			}
		}
	}
}
#ifndef NOX_CGO
void OnKeyboardEvent(nox_keyboard_btn_t* ev) {
	if (ev->state != 2)
		return;
	if (((gameex_flags >> 3) & 1) && (ev->code == 26 || ev->code == 27)) {
		char v8 = ev->code == 26;
		// checks some gameFlags that are yet undiscovered
		if (nox_common_gameFlags_check_40A5C0(0x204)) {
			if (dword_5d4594_1064868 || nox_win_unk3)
				return;
			if (nox_common_gameFlags_check_40A5C0(1)) { // isServer
				if (nox_xxx_host_player_unit_3843628 &&
					mix_MouseKeyboardWeaponRoll(nox_xxx_host_player_unit_3843628, v8))
					nox_xxx_clientPlaySoundSpecial_452D80(895, 100);
			} else {
				char buf[10];
				gameex_makeExtensionPacket((int)&buf, 0, 1);
				buf[8] = v8 | 0x10; // TODO: should it be just v8?
				gameex_sendPacket(&buf, 9, 0);
			}
		}
	}
	if (ev->code == functionalKeyCodes[5]) {
		if ((gameex_flags >> 3) & 1) {
			if (nox_common_gameFlags_check_40A5C0(516)) {
				if (dword_5d4594_1064868 || nox_win_unk3)
					return;
				if (nox_common_gameFlags_check_40A5C0(1)) { // checkGameFlags isServer
					uint32_t* v9 = nox_xxx_objGetTeamByNetCode_418C80(nox_player_netCode_85319C);
					playerDropATrap((int)(v9 - 12));
				} else {
					char buf[10];
					gameex_makeExtensionPacket((int)&buf, 9, 1);
					gameex_sendPacket(&buf, 8, 0);
				}
			}
		}
	}
	if (ev->code == 66) {
		if (!nox_common_gameFlags_check_40A5C0(1)) {
			nox_xxx_printCentered_445490(L"only server can change these options");
			nox_xxx_clientPlaySoundSpecial_452D80(231, 100);
			return;
		}
		if (!nox_common_gameFlags_check_40A5C0(516)) {
			return;
		}
		nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
		if (modifyWndPntr) {
			GameExCfgSaver();
			DestroyNoxWindow();
			modifyWndPntr = 0;
		} else {
			modifyWndPntr = nox_new_window_from_file("modify.wnd", modifyWndInputHandler);
			if (!modifyWndPntr)
				return;
			if (nox_common_gameFlags_check_40A5C0(512)) {
				uint32_t* v10 = nox_xxx_wndGetChildByID_46B0C0(modifyWndPntr, 1938);
				nox_window_set_hidden((int)v10, 1);
				uint32_t* v11 = nox_xxx_wndGetChildByID_46B0C0(modifyWndPntr, 1524);
				nox_xxx_wnd_46ABB0((int)v11, 0);
			}
			sub_46B120(modifyWndPntr, 0);
			uint32_t* a2b = nox_xxx_wndGetChildByID_46B0C0(modifyWndPntr, 1981);
			int v12 = 1520;
			wchar_t(*v13)[35] = wndEntryNames;
			uint32_t va1 = 5;
			do {
				nox_window_call_field_94((int)a2b, 16397, (int)v13, -1);
				if (getFlagValueFromFlagIndex(v12 - 1519) & gameex_flags) {
					uint32_t* v14 = nox_xxx_wndGetChildByID_46B0C0(modifyWndPntr, v12);
					v14[9] |= 4u;
				} else {
					uint32_t* v15 = nox_xxx_wndGetChildByID_46B0C0(modifyWndPntr, v12);
					v15[9] &= 0xFBu;
				}
				++v13;
				++v12;
				--va1;
			} while (va1);
		}
	}
	uint32_t* result = 0;
	while (ev->code != functionalKeyCodes[(uint32_t)result]) {
		result = (uint32_t*)((char*)result + 1);
		if ((signed int)result >= 5)
			return;
	}
	nox_xxx_clientUpdateButtonRow_45E110((int)result);
}
void OnLibraryNotice_418() {
	if (!sub_44A4A0()) {
		memset(inputNewIpMsgBox, 0, 0x200u);
		*(uint32_t*)&inputNewIpMsgBox[376] = inputNewIp_;
		nox_xxx_dialogMsgBoxCreate_449A10((int)inputNewIpMsgBox, (int)L"Ip Address", (int)L"Enter address", 163,
										  (int (*)(void))startInvalidIpChecker, 0);
	}
}
#endif // NOX_CGO
void OnLibraryNotice_420(uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4) {
	int v23 = arg1;
	int v19 = arg2;
	uint32_t* v16 = getPlayerClassFromObjPtr(arg1);
	if (*(uint8_t*)(v19 + 0xA) != 17) {
		nox_xxx_inventoryServPlace_4F36F0(v23, v19, 1, 1);
		return;
	}
	char v17 = *(uint8_t*)(v19 + 4);
	if (v17 != 0x6A) {
		if ((v17 == 0x6B || v17 == 0x6D) && (uint8_t)v16) {
			goto ifIsWarrior;
		}
		nox_xxx_inventoryServPlace_4F36F0(v23, v19, 1, 1);
		return;
	}
	if ((uint8_t)v16 == 1) {
		nox_xxx_inventoryServPlace_4F36F0(v23, v19, 1, 1);
		return;
	}
ifIsWarrior:
	nox_xxx_netPriMsgToPlayer_4DA2C0(v23, (const char*)getMemAt(0x587000, 215732),
									 0); // 0x5BBAB4 = pickup.c:ObjectEquipClassFail
	nox_xxx_aud_501960(925, v23, 2, *(uint32_t*)(v23 + 36));
}

//----- (10004330) --------------------------------------------------------
int getFlagValueFromFlagIndex(signed int a1) {
	signed int v1;   // edx
	unsigned int v2; // eax
	signed int v3;   // ecx
	int result;      // eax

	v1 = 2;
	v2 = a1;
	if (a1 < 0)
		v2 = -a1;
	v3 = 1;
	while (1) {
		if (v2 & 1)
			v3 *= v1;
		v2 >>= 1;
		if (!v2)
			break;
		v1 *= v1;
	}
	if (a1 >= 0)
		result = v3;
	else
		result = 1 / v3;
	return result;
}
