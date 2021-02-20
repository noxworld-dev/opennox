#define DG_DYNARR_IMPLEMENTATION
#include "memmap.h"
#include "GameEx.h"
#include "client__gui__guimsg.h"

#include "client__shell__noxworld.h"

extern int nox_win_width_1;
extern int nox_win_height_1;
extern int dword_5d4594_3484;
extern unsigned int dword_5d4594_3843628;
extern unsigned int dword_5d4594_1064896;
extern unsigned int dword_5d4594_1064900;
extern unsigned int nox_xxx_netStructID_815700;
extern unsigned int dword_587000_87404;
extern unsigned int dword_5d4594_1064868;
extern unsigned int dword_5d4594_1316972;
extern nox_net_struct_t* nox_net_struct_arr[NOX_NET_STRUCT_MAX];
extern nox_window* nox_win_unk3;

//-------------------------------------------------------------------------
// Data declarations

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
char* EndOfKeyCodeArray = 0;                          // weak
int DefaultPacket[4] = {171901697, 1, 347, 44391266}; // weak
unsigned __int8 functionalKeyCodes[] = {2u, 3u, 4u, 5u, 6u, 156u, 0u};
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
unsigned __int8 serverData[64];
char someSwitch = 0;        // weak
char isInvalidIp = 0;       // weak
char inputNewIpMsgBox[512]; // weak
char isLoaded = 0;          // weak
void* modifyWndPntr = 0;    // weak

intArray gameIps;

BOOL nox_CharToOemW(LPCWSTR pSrc, LPSTR pDst) { return nox_sprintf(pDst, "%S", pSrc); }

//----- (10001000) --------------------------------------------------------
BOOL __stdcall GameEx_DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
	if (fdwReason && fdwReason == 1 && !isLoaded) {
		da_init(gameIps);
		isLoaded = 1;
		// MEMACCESS(0x581354) = MixRecvFromReplacer; // It is replaced elsewhere
		EndOfKeyCodeArray = &keycodeArray[keycodeArraySize - 1];
		if (!GameExCfgLoader())
			fprintf(stderr, "Failed to read game_ex.cfg !");
	}
	return 1;
}
// 10012BCC: using guessed type char isLoaded;

//----- (10001230) --------------------------------------------------------
unsigned __int8  KeyCodeMatcher(char* a1) {
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
int  GameExCfgSaver() {
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
	// DWORD NumberOfBytesWritten; // [esp+12Ch] [ebp-4h]
	// char v26; // [esp+134h] [ebp+4h]
	// char v27; // [esp+138h] [ebp+8h]

	result = (int)fopen("game_ex.cfg", "w");
	v1 = (void*)result;
	if (result == 0) {
		return 0;
	}
	fwrite("AUTO_SHIELD = ", 0xEu, 1, v1);
	v2 = "1\r\n";
	if (!((*getMemU32Ptr(0x980858, 2) >> 1) & 1))
		v2 = "0\r\n";
	fwrite(v2, 3u, 1, v1);
	fwrite("GREAT_SWORD_BLOKING_WALK = ", 0x1Bu, 1, v1);
	v3 = "1\r\n";
	if (!((*getMemU32Ptr(0x980858, 2) >> 2) & 1))
		v3 = "0\r\n";
	fwrite(v3, 3u, 1, v1);
	fwrite("MOUSE_KEYBOARD_ROLL = ", 0x16u, 1, v1);
	v4 = "1\r\n";
	if (!((*getMemU32Ptr(0x980858, 2) >> 3) & 1))
		v4 = "0\r\n";
	fwrite(v4, 3u, 1, v1);
	fwrite("BERSERKER_SHIED_BLOCK = ", 0x18u, 1, v1);
	v5 = "1\r\n";
	if (!((*getMemU32Ptr(0x980858, 2) >> 4) & 1))
		v5 = "0\r\n";
	fwrite(v5, 3u, 1, v1);
	fwrite("EXTENSION_MESSAGES = ", 0x15u, 1, v1);
	v6 = "1\r\n";
	if (!((*getMemU32Ptr(0x980858, 2) >> 5) & 1))
		v6 = "0\r\n";
	fwrite(v6, 3u, 1, v1);
	fwrite("PANEL1 = ", 9u, 1, v1);
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
	fwrite(v9, strlen(v9), 1, v1);
	fwrite("\r\n", 2u, 1, v1);
	fwrite("PANEL2 = ", 9u, 1, v1);
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
	fwrite(v12, strlen(v12), 1, v1);
	fwrite("\r\n", 2u, 1, v1);
	fwrite("PANEL3 = ", 9u, 1, v1);
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
	fwrite(v15, strlen(v15), 1, v1);
	fwrite("\r\n", 2u, 1, v1);
	fwrite("PANEL4 = ", 9u, 1, v1);
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
	fwrite(v18, strlen(v18), 1, v1);
	fwrite("\r\n", 2u, 1, v1);
	fwrite("PANEL5 = ", 9u, 1, v1);
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
	fwrite(v21, strlen(v21), 1, v1);
	fwrite("\r\n", 2u, 1, v1);
	fwrite("TRAPKEY = ", 0xAu, 1, v1);
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
	fwrite(v24, strlen(v24), 1, v1);
	fwrite("\r\n----------", 0xCu, 1, v1);
	fclose(v1);
	return 1;
}
// 10001290: could not find valid save-restore pair for ebx
// 10001290: could not find valid save-restore pair for ebp

//----- (10001670) --------------------------------------------------------
const char* __usercall SomeStringSearcher(const char* result, const char* a2, char* a3) {
	char* v3;       // edi
	const char* v4; // esi
	char* v5;       // eax
	char i;         // cl

	v3 = a3;
	v4 = a2;
	if (result && a2) {
		v5 = strstr(result, a2);
		if(!v5)
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
	DWORD v3;    // edi
	char* v4;    // esi
	// DWORD NumberOfBytesRead; // [esp+4h] [ebp-18h]
	char v6[32]; // [esp+8h] [ebp-6h]
	memset(v6, 0, sizeof(v6));

	v0 = fopen("game_ex.cfg", "rb");
	v1 = v0;
	if (!v0)
		return 0;
	fseek(v0, 0, SEEK_END);
	v3 = ftell(v0);
	fseek(v0, 0, SEEK_SET);
	if (v3) {
		v4 = (char*)malloc(v3 + 1);
		if (fread(v4, 1, v3, v1) == v3) {
			SomeStringSearcher(v4, "AUTO_SHIELD", (char*)&v6);
			if ((_BYTE)*v6 == 48)
				*getMemU32Ptr(0x980858, 2) &= 0xFFFFFFFD;
			else
				*getMemU32Ptr(0x980858, 2) |= 2u;
			SomeStringSearcher(v4, "GREAT_SWORD_BLOKING_WALK", (char*)&v6);
			if ((_BYTE)*v6 == 48)
				*getMemU32Ptr(0x980858, 2) &= 0xFFFFFFFB;
			else
				*getMemU32Ptr(0x980858, 2) |= 4u;
			SomeStringSearcher(v4, "MOUSE_KEYBOARD_ROLL", (char*)&v6);
			if ((_BYTE)*v6 == 48)
				*getMemU32Ptr(0x980858, 2) &= 0xFFFFFFF7;
			else
				*getMemU32Ptr(0x980858, 2) |= 8u;
			SomeStringSearcher(v4, "MOUSE_KEYBOARD_ROLL", (char*)&v6);
			if ((_BYTE)*v6 == 48)
				*getMemU32Ptr(0x980858, 2) &= 0xFFFFFFF7;
			else
				*getMemU32Ptr(0x980858, 2) |= 8u;
			SomeStringSearcher(v4, "BERSERKER_SHIED_BLOCK", (char*)&v6);
			if ((_BYTE)*v6 == 48)
				*getMemU32Ptr(0x980858, 2) &= 0xFFFFFFEF;
			else
				*getMemU32Ptr(0x980858, 2) |= 0x10u;
			SomeStringSearcher(v4, "EXTENSION_MESSAGES", (char*)&v6);
			if ((_BYTE)*v6 == 48)
				*getMemU32Ptr(0x980858, 2) &= 0xFFFFFFDF;
			else
				*getMemU32Ptr(0x980858, 2) |= 0x20u;
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
		fclose(v0);
		result = 1;
	} else {
		fclose(v1);
		result = 0;
	}
	return result;
}

//----- (10001A20) --------------------------------------------------------
int  sendtoWrapper(char* buf, int len, int smth) {
	if (!buf || !len || nox_xxx_netStructID_815700 >= NOX_NET_STRUCT_MAX) {
		return 0;
	}
	// 0x69B7E8 = netSocketData
	nox_net_struct_t* ns = nox_net_struct_arr[nox_xxx_netStructID_815700];
	if (!ns) {
		// A call here is lost? - nope, as somehow the checks in ASM denies it completely
		return 0;
	}
	return sendto(ns->sock, buf, len, 0, &ns->addr, 16);
}

//----- (10001AD0) --------------------------------------------------------
void  notifyThisIsServeronly(int ptr, __int16 shortval, BOOL boolval) {
	LOBYTE(boolval) = 1;
	*(_WORD*)ptr = 0xF13Au;        // packet id
	*(_WORD*)(ptr + 2) = shortval; // always zero
	if (boolval)
		*(_DWORD*)(ptr + 4) = (*getMemU32Ptr(0x5D4594, 2616328)); // playerNetCode
}

//----- (10001B10) --------------------------------------------------------
int __usercall DestroyNoxWindow() {
	_DWORD* v1; // edi MAPDST

	v1 = modifyWndPntr;
	v1 = modifyWndPntr;
	nox_xxx_wnd_46C6E0((int)modifyWndPntr);
	nox_xxx_windowDestroyMB_46C4E0(v1);
	return (int)v1;
}

//----- (10001B40) --------------------------------------------------------
int __usercall copyServerMatchData(char* a1) {
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
	*((_WORD*)a1 + 8) = *getMemU32Ptr(0x5D4594, 371490);
	v3 = (char*)getMemAt(0x5D4594, 371380);
	cntr = 18;
	do {
		v4 = *v3;
		a1[cntr] = v4;
		++v3;
		cntr++;
	} while (v4);
	a1[34] = *getMemU32Ptr(0x5D4594, 371620);
	a1[35] = *getMemU32Ptr(0x5D4594, 373872) + 1;
	a1[36] = *getMemU32Ptr(0x5D4594, 371616);
	*((_WORD*)a1 + 20) = *getMemU32Ptr(0x5D4594, 371621);
	*((_WORD*)a1 + 21) = *getMemU32Ptr(0x5D4594, 371623);
	a1[44] = *getMemU32Ptr(0x5D4594, 371618);
	a1[45] = *getMemU32Ptr(0x5D4594, 371616);
	a1[37] = sub_409F40(2);
	// a1[38] = MEMACCESS(0x5D5331); // serverRuleFlags + 1
	a1[38] = *(int*)((char*)&dword_5d4594_3484 + 1);
	*((_DWORD*)a1 + 12) = 65540;
	*((_WORD*)a1 + 26) = nox_win_height_1;
	*((_WORD*)a1 + 27) = nox_win_width_1;
	*((_WORD*)a1 + 28) = *getMemU32Ptr(0x5D4594, 371582);
	*((_WORD*)a1 + 29) = *getMemU32Ptr(0x5D4594, 371586);
	a1[60] = *getMemU32Ptr(0x5D4594, 371494);
	result = *getMemU32Ptr(0x5D4594, 371434);
	*((_WORD*)a1 + 31) = *getMemU32Ptr(0x5D4594, 371434);
	return result;
}

//----- (10001C20) --------------------------------------------------------
char  getPlayerClassFromObjPtr(int a1) { return *(_BYTE*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276) + 2251); }

//----- (10001C50) --------------------------------------------------------
int __usercall playerInfoStructsToVector(smallPlayerStructVector* vector) {
	char* result; // eax
	char* v7;     // esi
	// char v8; // [esp+10h] [ebp-24h]
	smallPlayerStruct pDst; // [esp+18h] [ebp-1Ch]

	result = nox_common_playerInfoGetFirst_416EA0();
	v7 = result;
	if (result) {
		do {
			pDst.string[1] = *((_BYTE*)nox_xxx_objGetTeamByNetCode_418C80(*((_DWORD*)v7 + 515)) + 4);
			pDst.string[0] = v7[2251];
			nox_CharToOemW((LPCWSTR)v7 + 2352, &(pDst.string[2]));
			da_add(*vector, pDst);
			v7 = nox_common_playerInfoGetNext_416EE0((int)v7);
		} while (v7);
		result = da_count(*vector);
	}
	return (int)result;
}

//----- (10001D40) --------------------------------------------------------
char  playerInfoStructParser_0(char* a1) {
	char* v1;  // esi
	CHAR pDst; // [esp+10h] [ebp-18h]

	if (a1 == (char*)-2)
		return 0;
	v1 = nox_common_playerInfoGetFirst_416EA0();
	if (!v1)
		return 0;
	while (1) {
		nox_CharToOemW((LPCWSTR)v1 + 2352, &pDst);
		if (!strcmp(&pDst, a1 + 2))
			break;
		v1 = nox_common_playerInfoGetNext_416EE0((int)v1);
		if (!v1)
			return 0;
	}
	a1[1] = *((_BYTE*)nox_xxx_objGetTeamByNetCode_418C80(*((_DWORD*)v1 + 515)) + 4);
	*a1 = v1[2251];
	return 1;
}

//----- (10001E10) --------------------------------------------------------
char __usercall playerInfoStructParser_1(int a1, int a2, int* a3) {
	char* v3;   // eax
	char* v4;   // eax
	_DWORD* v6; // eax
	CHAR pDst;  // [esp+Ch] [ebp-18h]

	if (a1 == -2)
		return 0;
	v3 = nox_common_playerInfoGetFirst_416EA0();
	*(_DWORD*)a2 = v3;
	if (!v3)
		return 0;
	while (1) {
		nox_CharToOemW((LPCWSTR)(*(_DWORD*)a2 + 4704), &pDst);
		if (!strcmp(&pDst, (const char*)(a1 + 2)))
			break;
		v4 = nox_common_playerInfoGetNext_416EE0(a2);
		*(_DWORD*)a2 = v4;
		if (!v4)
			return 0;
	}
	v6 = nox_xxx_objGetTeamByNetCode_418C80(*(_DWORD*)(*(_DWORD*)a2 + 2060));
	*a3 = (int)v6;
	*(_BYTE*)(a1 + 1) = *((_BYTE*)v6 + 4);
	*(_BYTE*)a1 = *(_BYTE*)(*(_DWORD*)a2 + 2251);
	return 1;
}

//----- (10001EE0) --------------------------------------------------------
char  mix_MouseKeyboardWeaponRoll(int playerObj, char a2) {
	int v2;        // esi
	int v3;        // esi MAPDST
	signed int v4; // edi
	int i;         // esi MAPDST
	int v6;        // eax
	int v8;        // eax
	int weapFlags; // eax
	int v11;       // eax
	char v16;      // [esp+Fh] [ebp-1h]

	v16 = 0;
	v2 = *(_DWORD*)(playerObj + 748);
	if (!(*(_BYTE*)(*(_DWORD*)(v2 + 276) + 3680) & 3) && *(_BYTE*)(v2 + 88) != 1) {
		v3 = *(_DWORD*)(v2 + 104);
		v4 = 496;
		if (v3) {
			if (!a2)
				v4 = 500;
			while (1) {
				v3 = *(_DWORD*)(v3 + v4);
				if (!v3)
					break;
				weapFlags = nox_xxx_unitWeaponInventoryEquipFlags_415820(v3); // weaponEquipFlags
				if (weapFlags) {
					if (weapFlags != 2) {
						if (nox_xxx_playerClassCanUseItem_57B3D0(v3, *(_BYTE*)(*(_DWORD*)(*(_DWORD*)(playerObj + 748) + 276) + 2251))) {
							v11 = nox_xxx_playerCheckStrength_4F3180(playerObj, v3);
							if (v11) {
								// It will surely fail to work if left this way (4F2FB0 will return 0 if given weapon is not currently equipped)
								// but in asm it's almost the same (4F2FB0; >0?: and 4F2F70)
								if (nox_xxx_playerTryDequip_4F2FB0((_DWORD*)playerObj, v3) && nox_xxx_playerTryEquip_4F2F70((_DWORD*)playerObj, v3)) {
									v16 = 1;
								}
								return v16;
							}
						}
					}
				}
			}
		} else {
			for (i = *(_DWORD*)(playerObj + 504); i; i = *(_DWORD*)(i + 496)) {
				v6 = nox_xxx_unitWeaponInventoryEquipFlags_415820(i); // weaponEquipFlags
				if (v6) {
					if (v6 != 2) {
						if (nox_xxx_playerClassCanUseItem_57B3D0(i, *(_BYTE*)(*(_DWORD*)(*(_DWORD*)(playerObj + 0x2EC) + 0x114) + 0x8CB))) {
							v8 = nox_xxx_playerCheckStrength_4F3180(playerObj, i);
							if (v8) {
								if (nox_xxx_playerTryEquip_4F2F70((_DWORD*)playerObj, i))
									v16 = 1;
								return v16;
							}
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
char  playerDropATrap(int playerObj) {
	int v2;   // eax
	int i;    // esi
	float v4; // [esp+Ch] [ebp-18h]
	// int v5; // [esp+10h] [ebp-14h]
	float* v6; // [esp+14h] [ebp-10h]
	char v7;   // [esp+18h] [ebp-Ch]
	char v8;   // [esp+1Fh] [ebp-5h]

	v7 = 17;
	if (!playerObj)
		return 0;
	v8 = 0;
	v6 = &v4;
	v2 = *(_DWORD*)(*(_DWORD*)(playerObj + 0x2EC) + 0x114);
	v4 = *(float*)(v2 + 0xE30);
	// v5 = *(_DWORD *)(v2 + 0xE34);
	v6 = &v4;
	if (!(*(_BYTE*)(*(_DWORD*)(*(_DWORD*)(playerObj + 0x2EC) + 0x114) + 0xE60) & 3) // check playerGameStatus/isObs
		&& *(_BYTE*)(*(_DWORD*)(playerObj + 0x2EC) + 0x58) != 1) {
		for (i = *(_DWORD*)(playerObj + 0x1F8); i; i = *(_DWORD*)(i + 0x1F0)) {
			if (*(_BYTE*)(i + 0xA) == v7) // check if something from *(byte*)(unit+0xA)=17
			{
				nox_xxx_drop_4ED810(playerObj, i, v6); // drop this item
				return 1;
			}
		}
	}
	return v8;
}

//----- (100020F0) --------------------------------------------------------
HANDLE __usercall GameIpParser(int a1, int a2, int a3) {
	HANDLE result;                 // eax MAPDST
	DWORD fileSize;                // esi MAPDST
	unsigned int fileBufferSize;   // ebp
	unsigned int fileBufferOffset; // esi
	unsigned int v9;               // ecx
	char currentFileBufferPntr;    // al
	DWORD NumberOfBytesRead;       // [esp+4h] [ebp-28h]
	void* fileBuffer;              // [esp+8h] [ebp-24h]
	char cp[20];                   // [esp+14h] [ebp-18h]

	result = fopen("game_ip.txt", "r");
	if (result) {
		fseek(result, 0, SEEK_END);
		fileSize = ftell(result);
		fseek(result, 0, SEEK_SET);
		if (fileSize) {
			fileBufferSize = fileSize + 1;
			NumberOfBytesRead = 0;
			*(_DWORD*)cp = 0;
			*(_DWORD*)&cp[4] = 0;
			*(_DWORD*)&cp[8] = 0;
			*(_DWORD*)&cp[12] = 0;
			*(_DWORD*)&cp[16] = 0;
			fileBuffer = malloc(fileBufferSize);
			if (fread(fileBuffer, 1, fileSize, result) == fileSize) {
				fileBufferOffset = 0;
				v9 = 0;
				if (fileBufferSize) {
					do {
						if (v9 > 0x14)
							break;
						currentFileBufferPntr = *((_BYTE*)fileBuffer + fileBufferOffset);
						if (currentFileBufferPntr == 44 || fileBufferOffset == fileSize ||
							currentFileBufferPntr == 32 || currentFileBufferPntr == 10) {
							if (v9) {
								NumberOfBytesRead = inet_addr(cp);
								nox_client_sendToServer_555010(NumberOfBytesRead, a2, (char*)a1, a3);
								*(_DWORD*)cp = 0;
								*(_DWORD*)&cp[4] = 0;
								*(_DWORD*)&cp[8] = 0;
								*(_DWORD*)&cp[12] = 0;
								*(_DWORD*)&cp[16] = 0;
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
		result = fclose(result);
	}
	return result;
}

//----- (10002240) --------------------------------------------------------
unsigned int __usercall pingAllServersInGameIp(int ebx0, int edi0, int a1, int a2, int a3) {
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
signed int __usercall inputNewIp_(int a1, int ebx0, int a2, int a3, int a4) {
	unsigned int v6; // [esp+10h] [ebp-2Ch]
	int v7;          // [esp+14h] [ebp-28h]
	LPCWSTR pSrc;    // [esp+18h] [ebp-24h]
	char pDst[28];   // [esp+1Ch] [ebp-20h]

	v7 = nox_xxx_wndGetID_46B0A0((int*)a4);
	pSrc = (LPCWSTR)sub_449E60(-88);
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
// 100129C1: using guessed type char isInvalidIp;
// 10002300: using guessed type CHAR pDst[28];

//----- (100023E0) --------------------------------------------------------
void playErrSoundClient() { nox_xxx_clientPlaySoundSpecial_452D80(766, 100); }

//----- (10002400) --------------------------------------------------------
unsigned int invalidIpChecker(unsigned int interval, void* param) {
	while (sub_44A4A0())
		return 1;
	if (isInvalidIp) {
		nox_xxx_dialogMsgBoxCreate_449A10(0, 0, (int)L"Invalid Address", 33, playErrSoundClient, 0);
		return 0;
	}
	sub_4378B0();
	return 0;
}
// 1000F110: using guessed type wchar_t aInvalidAddress[16];
// 100129C1: using guessed type char isInvalidIp;

//----- (10002470) --------------------------------------------------------
HANDLE __usercall startInvalidIpChecker() {
	HANDLE result; // eax

	if (!dword_587000_87404)
		result = SDL_AddTimer(0x12Cu, invalidIpChecker, NULL);
	return result;
}

//----- (100024A0) --------------------------------------------------------
int  modifyWndInputHandler(int a1, int a2, int a3, int a4) {
	unsigned int v4; // eax
	int result;      // eax
	_DWORD* v6;      // edi

	if (a2 != 16391)
		return 0;
	nox_xxx_clientPlaySoundSpecial_452D80(766, 100);
	v4 = nox_xxx_wndGetID_46B0A0((int*)a3);
	if (v4 > 0x791) {
		if (v4 == 1938 && !nox_common_gameFlags_check_40A5C0(512)) {
			sub_4BDFD0();
			nox_wnd_nox_xxx_wndDraw_46A9B0(dword_5d4594_1316972, 200, 100);
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
			if ((*getMemU32Ptr(0x980858, 2) >> 1) & 1)
				*getMemU32Ptr(0x980858, 2) &= 0xFFFFFFFD;
			else
				*getMemU32Ptr(0x980858, 2) |= 2u;
			result = 0;
			break;
		case 0x5F1u:
			if ((*getMemU32Ptr(0x980858, 2) >> 2) & 1)
				*getMemU32Ptr(0x980858, 2) &= 0xFFFFFFFB;
			else
				*getMemU32Ptr(0x980858, 2) |= 4u;
			result = 0;
			break;
		case 0x5F2u:
			if ((*getMemU32Ptr(0x980858, 2) >> 3) & 1)
				*getMemU32Ptr(0x980858, 2) &= 0xFFFFFFF7;
			else
				*getMemU32Ptr(0x980858, 2) |= 8u;
			result = 0;
			break;
		case 0x5F3u:
			if ((*getMemU32Ptr(0x980858, 2) >> 4) & 1)
				*getMemU32Ptr(0x980858, 2) &= 0xFFFFFFEF;
			else
				*getMemU32Ptr(0x980858, 2) |= 0x10u;
			result = 0;
			break;
		case 0x5F4u:
			if ((*getMemU32Ptr(0x980858, 2) >> 5) & 1)
				*getMemU32Ptr(0x980858, 2) &= 0xFFFFFFDF;
			else
				*getMemU32Ptr(0x980858, 2) |= 0x20u;
			result = 0;
			break;
		default:
			return 0;
		}
	}
	return result;
}

//----- (10002680) --------------------------------------------------------
int __stdcall MixRecvFromReplacer(SOCKET s, char* buf, int len, int flags, struct sockaddr* from, int* fromlen) {
	char* v6;   // ebx
	int result; // eax
	_DWORD* v8; // esi
	char v9;    // al
	int v10;    // esi
	int v11;    // edx
	//_DWORD *v12; // esi
	char* v13; // edi
	// int v14; // eax
	// unsigned int v15; // esi
	// int *v16; // eax
	// int v17; // eax
	char* v18;            // eax
	char v19;             // cl
	char* v20;            // eax
	char* v21;            // edx
	char v22;             // cl
	int v23;              // edx
	int v24;              // eax
	int v25;              // ecx
	char* v26;            // edi
	char* v27;            // eax
	char v28;             // cl
	unsigned int v29;     // kr00_4
	char* v30;            // edx
	unsigned int v31;     // ecx
	unsigned __int8* v32; // esi
	char v33;             // bl
	int* v34;             // eax
	_DWORD* v35;          // eax
	char v36;             // [esp+17h] [ebp-CDh]
	// int a1[2]; // [esp+1Ch] [ebp-C8h]
	struct sockaddr* to; // [esp+24h] [ebp-C0h]
	int v39;             // [esp+28h] [ebp-BCh]
	int* v40;            // [esp+2Ch] [ebp-B8h]
	int v41;             // [esp+30h] [ebp-B4h]
	// int a2[2]; // [esp+34h] [ebp-B0h]
	int v43[6];                // [esp+3Ch] [ebp-A8h]
	unsigned __int8 v44[0x80]; // [esp+54h] [ebp-90h]
	// int v45; // [esp+E0h] [ebp-4h]

	v6 = buf;
	v40 = fromlen;
	to = from;
	result = recvfrom(s, buf, len, flags, from, fromlen);
	v41 = result;
	if (*(_WORD*)buf == -3782) {
		switch (*((unsigned __int16*)buf + 1)) // packet id
		{
		case 0u:
			if ((*getMemU32Ptr(0x980858, 2) >> 3) & 1) {
				v8 = nox_xxx_objGetTeamByNetCode_418C80(*((_DWORD*)buf + 1));
				v9 = buf[8];
				v10 = (int)(v8 - 12);
				v36 = ((unsigned int)v9 >> 4) & 1;
				if (v36)
					buf[8] = v9 & 0xEF;
				if (!getPlayerClassFromObjPtr(v10) || v36) {
					if (mix_MouseKeyboardWeaponRoll(v10, buf[8])) {
						*((_WORD*)buf + 1) = 2;
						sendto(s, buf, 4, 0, from, 16);
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
		case 3u: // Send back playerInfoStructs
			if (nox_common_gameFlags_check_40A5C0(1) && (*getMemU32Ptr(0x980858, 2) >> 5) & 1) {
				smallPlayerStructVector vector;
				smallPlayerStruct* it;
				smallPlayerStruct* end;

				da_init(vector);
				// v45 = 0;
				if (playerInfoStructsToVector(&vector)) {
					copyServerMatchData((char*)v44);
					v11 = *getMemU32Ptr(0x980858, 2);
					v39 = 18 * da_count(vector) + 68;
					memcpy(buf + 8, v44, 0x40u);
					*((_DWORD*)buf + 1) = v11;
					if (da_count(vector) > 0) {
						v13 = buf + 72;
						for (it = da_begin(vector), end = da_end(vector); it != end; ++it) {
							*(_DWORD*)v13 = *(_DWORD*)(it->string);
							*((_DWORD*)v13 + 1) = *(_DWORD*)((it->string) + 4);
							*((_DWORD*)v13 + 2) = *(_DWORD*)((it->string) + 8);
							*((_DWORD*)v13 + 3) = *(_DWORD*)((it->string) + 12);
							*((_WORD*)v13 + 8) = *(_WORD*)((it->string) + 16);
							v13 += 18;
						}
					}
					sendto(s, buf, v39, 0, to, 16);
				}
				da_free(vector);
			}
			break;
		case 4u:
			if (nox_common_gameFlags_check_40A5C0(1)) {
				if ((*getMemU32Ptr(0x980858, 2) >> 5) & 1) {
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
						*((_DWORD*)buf + 1) = v43[0];
						v25 = v43[3];
						*((_DWORD*)buf + 2) = v23;
						LOWORD(v23) = v43[4];
						*((_DWORD*)buf + 3) = v24;
						*((_DWORD*)buf + 4) = v25;
						*((_WORD*)buf + 10) = v23;
						sendto(s, buf, 22, 0, from, 16);
					}
				}
			}
			break;
		case 5u:
			if ((*getMemU32Ptr(0x980858, 2) >> 5) & 1) {
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
			if (nox_common_gameFlags_check_40A5C0(1) && (*getMemU32Ptr(0x980858, 2) >> 5) & 1) {
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
						v32 = (unsigned __int8*)(v44 - (unsigned __int8*)v30);
						do {
							v33 = *v30;
							v30[(_DWORD)v32] = *v30;
							++v30;
						} while (v33);
						memset(v26, 0, v29 + v31);
						strcpy(v26, (const char*)v44);
					}
				}
				v6 = buf;
			}
			break;
		case 9u:
			if ((*getMemU32Ptr(0x980858, 2) >> 3) & 1) {
				v35 = nox_xxx_objGetTeamByNetCode_418C80(*((_DWORD*)buf + 1));
				playerDropATrap((int)(v35 - 12));
			}
			break;
		}
		*(_DWORD*)v6 = DefaultPacket[0]; // Placeholder Packet inserted instead of Mix one?
		*((_DWORD*)v6 + 1) = DefaultPacket[1];
		v34 = v40;
		*((_DWORD*)v6 + 2) = DefaultPacket[2];
		*((_DWORD*)v6 + 3) = DefaultPacket[3];
		*v34 = 16;
		result = v41;
	}
	return result;
}
// 1000EF00: using guessed type int DefaultPacket[4];

//----- (10002C30) --------------------------------------------------------
void OnLibraryNotice_256() {

}
void OnLibraryNotice_257() {
	dword_5d4594_3843628 = 0;
}
void OnLibraryNotice_258() {
	// is called from exe from here: 0x980650
	someSwitch = 1;
}
void OnLibraryNotice_259(DWORD arg1) {

}
void OnLibraryNotice_260(DWORD arg1, DWORD arg2, DWORD arg3) {
	// pings all servers from game_ip.txt
	int v1 = 0;
	GameIpParser(arg2, arg1, arg3);
	pingAllServersInGameIp(arg2, v1, arg1, arg2, arg3);
}
void OnLibraryNotice_261() {
	unsigned __int8 v24[64]; // [esp+1Ch] [ebp-50h]
	// is called when game parameters change via UI
	// it just copies server data to a serverData variable
	copyServerMatchData((char*)v24);
	_DWORD* result = (_DWORD*)64;
	int v5 = 0;
	while (*(_DWORD*)&serverData[v5] == *(_DWORD*)&v24[v5]) {
		--result;
		v5 += 4;
		if ((unsigned int)result < 4)
			return;
	}
	memcpy(serverData, v24, sizeof(serverData));
}
void OnLibraryNotice_262(DWORD arg1) {

}
void OnLibraryNotice_263(DWORD arg1) {
	nox_common_gameFlags_check_40A5C0(1);
}
void OnLibraryNotice_264(DWORD arg1) {
	nox_common_gameFlags_check_40A5C0(1);
}
void OnLibraryNotice_265(DWORD arg1, DWORD arg2, DWORD arg3) {
	// toggles weapons by mouse wheel
	// autoshield is actually implemented in appendix of nox_xxx_playerDequipWeapon_53A140
	//a2a = (*(_DWORD*)(vaArg3 + 4) >> 7) & 1;
	char a2a = arg3 > 0; // scroll weapons back or forth
	_DWORD* result = (_DWORD*)(arg2 - 2);
	if (arg2 == 2 &&
		// FIXME: checked in asm (cmp ds:6D8555, eax)
		((dword_5d4594_1064896 >> 8) | (dword_5d4594_1064900 << 24)) == result) {
		if ((*getMemU32Ptr(0x980858, 2) >> 3) & 1) {
			if (nox_common_gameFlags_check_40A5C0(516)) {
				if (nox_common_gameFlags_check_40A5C0(1)) {
					if (dword_5d4594_3843628) { // playerObjServerHost
						if (!getPlayerClassFromObjPtr(dword_5d4594_3843628)) {
							if (mix_MouseKeyboardWeaponRoll(dword_5d4594_3843628, a2a))
								nox_xxx_clientPlaySoundSpecial_452D80(895, 100); // clientPlaySound
						}
					}
				} else {
					char buf[10];
					notifyThisIsServeronly((int)&buf, 0, 1);
					// v27 = a2a;
					sendtoWrapper(&buf, 9, 0);
				}
			}
		}
	}
}
void OnLibraryNotice_417(DWORD arg1) {
	char* vaArg1_1 = &arg1;
	__int16 v7 = *(_WORD*)vaArg1_1;
	if (vaArg1_1[1] != 2)
		return;
	char v8 = 0;
	if (vaArg1_1[0] == 26) {
		v8 = 1;
	} else if (vaArg1_1[0] == 27) {
		v8 = 0;
	} else {
		goto LABEL_37;
	}
	vaArg1_1[1] = v8;
	if ((*getMemU32Ptr(0x980858, 2) >> 3) & 1) {
		// checks some gameFlags that are yet undiscovered
		if (nox_common_gameFlags_check_40A5C0(0x204)) {
			if (dword_5d4594_1064868 || nox_win_unk3)
				return;
			if (nox_common_gameFlags_check_40A5C0(1)) // isServer
			{
				if (dword_5d4594_3843628 && mix_MouseKeyboardWeaponRoll(dword_5d4594_3843628, vaArg1_1[1]))
					nox_xxx_clientPlaySoundSpecial_452D80(895, 100);
			} else {
				char buf[10];
				notifyThisIsServeronly((int)&buf, 0, 1);
				// v27 = v8 | 0x10;
				sendtoWrapper(&buf, 9, 0);
			}
		}
	}
LABEL_37:
	if ((_BYTE)v7 == functionalKeyCodes[5]) {
		if ((*getMemU32Ptr(0x980858, 2) >> 3) & 1) {
			if (nox_common_gameFlags_check_40A5C0(516)) {
				if (dword_5d4594_1064868 || nox_win_unk3)
					return;
				if (nox_common_gameFlags_check_40A5C0(1)) // checkGameFlags isServer
				{
					_DWORD* v9 = nox_xxx_objGetTeamByNetCode_418C80(*getMemU32Ptr(0x5D4594, 2616328));
					playerDropATrap((int)(v9 - 12));
				} else {
					char buf[10];
					notifyThisIsServeronly((int)&buf, 9, 1);
					sendtoWrapper(&buf, 8, 0);
				}
			}
		}
	}
	if ((_BYTE)v7 != 66) {
		goto LABEL_60;
	}
	if (!nox_common_gameFlags_check_40A5C0(1)) {
		nox_xxx_printCentered_445490(L"only server can change these options");
		nox_xxx_clientPlaySoundSpecial_452D80(231, 100);
		return;
	}
	if (nox_common_gameFlags_check_40A5C0(516)) {
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
				_DWORD* v10 = nox_xxx_wndGetChildByID_46B0C0(modifyWndPntr, 1938);
				nox_window_set_hidden((int)v10, 1);
				_DWORD* v11 = nox_xxx_wndGetChildByID_46B0C0(modifyWndPntr, 1524);
				nox_xxx_wnd_46ABB0((int)v11, 0);
			}
			sub_46B120(modifyWndPntr, 0);
			_DWORD* a2b = nox_xxx_wndGetChildByID_46B0C0(modifyWndPntr, 1981);
			int v12 = 1520;
			wchar_t(*v13)[35] = wndEntryNames;
			*(_DWORD*)vaArg1_1 = 5;
			do {
				nox_window_call_field_94((int)a2b, 16397, (int)v13, -1);
				if (getFlagValueFromFlagIndex(v12 - 1519) & *getMemU32Ptr(0x980858, 2)) {
					_DWORD* v14 = nox_xxx_wndGetChildByID_46B0C0(modifyWndPntr, v12);
					v14[9] |= 4u;
				} else {
					_DWORD* v15 = nox_xxx_wndGetChildByID_46B0C0(modifyWndPntr, v12);
					v15[9] &= 0xFBu;
				}
				++v13;
				++v12;
				--*(_DWORD*)vaArg1_1;
			} while (*(_DWORD*)vaArg1_1);
		}
	LABEL_60:;
		_DWORD* result = 0;
		while ((_BYTE)v7 != functionalKeyCodes[(_DWORD)result]) {
			result = (_DWORD*)((char*)result + 1);
			if ((signed int)result >= 5)
				return;
		}
		nox_xxx_clientUpdateButtonRow_45E110((int)result);
	}
}
void OnLibraryNotice_418() {
	if (!sub_44A4A0()) {
		memset(inputNewIpMsgBox, 0, 0x200u);
		*(_DWORD*)&inputNewIpMsgBox[376] = inputNewIp_;
		nox_xxx_dialogMsgBoxCreate_449A10((int)inputNewIpMsgBox, (int)L"Ip Address", (int)L"Enter address", 163,
							(int (*)(void))startInvalidIpChecker, 0);
	}
}
void OnLibraryNotice_420(DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4) {
	int v23 = arg1;
	int v19 = arg2;
	_DWORD* v16 = getPlayerClassFromObjPtr(arg1);
	if (*(_BYTE*)(v19 + 0xA) != 17) {
		nox_xxx_inventoryServPlace_4F36F0(v23, v19, 1, 1);
		return;
	}
	char v17 = *(_BYTE*)(v19 + 4);
	if (v17 != 0x6A) {
		if ((v17 == 0x6B || v17 == 0x6D) && (_BYTE)v16) {
			goto ifIsWarrior;
		}
		nox_xxx_inventoryServPlace_4F36F0(v23, v19, 1, 1);
		return;
	}
	if ((_BYTE)v16 == 1) {
		nox_xxx_inventoryServPlace_4F36F0(v23, v19, 1, 1);
		return;
	}
ifIsWarrior:
	nox_xxx_netPriMsgToPlayer_4DA2C0(v23, (const char*)getMemAt(0x587000, 215732), 0); // 0x5BBAB4 = pickup.c:ObjectEquipClassFail
	nox_xxx_aud_501960(925, v23, 2, *(_DWORD*)(v23 + 36));
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
