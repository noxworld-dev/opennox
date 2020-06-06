#include "server.h"

#include "../../client/gui/guiquit.h"
#include "../../common/system/settings.h"
#include "../../common/telnet/telnetd.h"
#include "../../proto.h"
#include "../network/mapsend.h"
#include "../network/playback.h"
#include "../network/sdecode.h"
#include "../xfer/savegame/savegame.h"
extern _DWORD dword_5d4594_600116;
extern _DWORD dword_5d4594_1556144;
extern _DWORD dword_5d4594_2386164;
extern _DWORD dword_5d4594_1569660;
extern _DWORD dword_5d4594_1568300;
extern _DWORD dword_5d4594_1548664;
extern _DWORD dword_5d4594_1548480;
extern _DWORD dword_5d4594_528260;
extern _DWORD dword_5d4594_1548704;
extern _DWORD dword_5d4594_1563096;
extern _DWORD dword_5d4594_1569652;
extern _DWORD dword_5d4594_1563052;
extern _DWORD dword_5d4594_1569644;
extern _DWORD dword_5d4594_1556148;
extern _DWORD dword_5d4594_825768;
extern _DWORD dword_5d4594_2386568;
extern _DWORD dword_587000_93196;
extern _DWORD dword_5d4594_2523744;
extern _DWORD dword_5d4594_608316;
extern _DWORD dword_5d4594_1599060;
extern _DWORD dword_5d4594_2386160;
extern _DWORD dword_5d4594_251744;
extern _DWORD dword_5d4594_528252;
extern _QWORD qword_581450_10392;
extern _QWORD qword_581450_10256;
extern _DWORD dword_5d4594_1569756;
extern _DWORD dword_5d4594_3843628;
extern _DWORD dword_5d4594_2495920;
extern _DWORD dword_5d4594_1568024;
extern _DWORD dword_5d4594_2388648;
extern _DWORD dword_5d4594_1599640;
extern _DWORD dword_5d4594_1548476;
extern _DWORD dword_5d4594_2487236;
extern _DWORD dword_5d4594_1599656;
extern _DWORD dword_5d4594_1569648;
extern _DWORD dword_5d4594_2650652;
extern _DWORD dword_5d4594_1599636;

void nullsub_21(void) {}
void nullsub_25(_DWORD a1) {}

//----- (00413980) --------------------------------------------------------
void __cdecl sub_413980(int a1) {
	if (a1) {
		sub_413A00(1);
		dword_5d4594_251744 = a1 + sub_430B40_get_mouse_prev_seq();
	} else {
		dword_5d4594_251744 = 0;
	}
}

//----- (004139C0) --------------------------------------------------------
void sub_4139C0() {
	if (dword_5d4594_251744) {
		if (sub_430B40_get_mouse_prev_seq() >= *(int*)&dword_5d4594_251744) {
			dword_5d4594_251744 = 0;
			if (!sub_450560())
				sub_413A00(0);
		}
	}
}

//----- (00417160) --------------------------------------------------------
char* sub_417160() {
	char* result; // eax
	int i;        // esi

	result = sub_416EA0();
	for (i = (int)result; result; i = (int)result) {
		sub_417530(i, 16);
		result = sub_416EE0(i);
	}
	return result;
}

//----- (00426060) --------------------------------------------------------
LPVOID sub_426060() {
	char* v0;      // eax
	char* i;       // eax
	char* v2;      // eax
	char* j;       // esi
	LPVOID result; // eax
	char* v5;      // edi
	char* v6;      // esi
	int v7;        // [esp-4h] [ebp-4h]

	dword_5d4594_608316 = 0;
	dword_5d4594_600116 = time(0);
	v7 = sub_5545A0();
	v0 = sub_554230();
	sub_4282D0(v0, v7);
	if (!nox_common_gameFlags_check_40A5C0(0x2000) || nox_common_gameFlags_check_40A5C0(4096)) {
		result = (LPVOID)nox_common_gameFlags_check_40A5C0(4096);
		if (result) {
			result = (LPVOID)nox_common_gameFlags_check_40A5C0(4096);
			if (result) {
				v5 = sub_416640();
				v6 = sub_416590(0);
				*(_WORD*)&byte_5D4594[739396] = sub_40A770();
				*(_DWORD*)&byte_5D4594[739400] = *((_DWORD*)v5 + 10);
				*(_DWORD*)&byte_5D4594[739404] = sub_4200E0();
				byte_5D4594[739412] = (v6[53] & 0xC0) != 0;
				*(_DWORD*)&byte_5D4594[739408] = 5;
				strncpy((char*)&byte_5D4594[739676], v6 + 9, 0xFu);
				byte_5D4594[739691] = 0;
				strncpy((char*)&byte_5D4594[739420], v6, 8u);
				byte_5D4594[739428] = 0;
				result = sub_4289D0((LPVOID*)&byte_5D4594[739396]);
			}
		}
	} else {
		for (i = sub_416EA0(); i; i = sub_416EE0((int)i))
			*((_DWORD*)i + 1162) = -1;
		v2 = sub_417090(31);
		if (v2)
			sub_425F10((int)v2);
		for (j = sub_416EA0(); j; j = sub_416EE0((int)j)) {
			if (j[2064] != 31)
				sub_425F10((int)j);
		}
		sub_426150();
		result = (LPVOID)sub_428810((int)&byte_5D4594[599476], 0);
		*(_WORD*)&byte_5D4594[599482] = 0;
	}
	return result;
}

//----- (0043DEA0) --------------------------------------------------------
BOOL sub_43DEA0() { return dword_587000_93196 == 0; }

//----- (00446040) --------------------------------------------------------
int sub_446040() { return dword_5d4594_825768; }

int sub_46DCB0(void) { return sub_46DCC0(); }

//----- (004CF5F0) --------------------------------------------------------
int __cdecl nox_server_loadMapFile_4CF5F0(char* a1, int a2) {
	char* v2;            // ebx
	char* v3;            // eax
	char* v4;            // eax
	int result;          // eax
	char* v6;            // eax
	int v7;              // esi
	char* v8;            // eax
	int v9;              // eax
	int v10;             // [esp+Ch] [ebp-65Ch]
	int v11;             // [esp+10h] [ebp-658h]
	char v12[20];        // [esp+14h] [ebp-654h]
	char v13[64];        // [esp+28h] [ebp-640h]
	CHAR FileName[1024]; // [esp+68h] [ebp-600h]
	CHAR v15[256];       // [esp+468h] [ebp-200h]
	char v16[256];       // [esp+568h] [ebp-100h]

	sub_481410();
	sub_4DAC00();
	sub_5799C0();
	v2 = a1;
	if (!a1)
		return 0;
	if (_strcmpi("#return", a1)) {
		if (*a1 == 35) {
			v3 = sub_409E10();
			sub_4D39F0(v3);
			strcpy(v13, a1 + 1);
			v4 = strchr(v13, 46);
			if (v4)
				*v4 = 0;
			sub_4D42E0(v13);
			nox_sprintf(v12, "$%s.map", v13);
			sub_409D70(v12);
			if (!sub_4D4320()) {
				sub_4D12E0(1);
				return 0;
			}
			sub_4D3C30();
			v2 = v12;
		}
	} else {
		v2 = (char*)&byte_5D4594[1523080];
	}
	if (strchr(v2, 92)) {
		strcpy(FileName, v2);
	} else {
		strcpy(FileName, "maps\\");
		strncat(FileName, v2, strlen(v2) - 4);
		*(_WORD*)&FileName[strlen(FileName)] = *(_WORD*)&byte_587000[191700];
		strcat(FileName, v2);
	}
	if (_access(FileName, 0) == -1) {
		v6 = strchr(FileName, 46);
		if (v6) {
			v7 = v6 - FileName;
			strncpy(v16, FileName, v6 - FileName);
			v16[v7] = 0;
			nox_sprintf(v15, "%s%s", v16, &byte_587000[191704]);
			if (_access(v15, 0) == -1)
				return 0;
			if (!sub_57BC50(v15, FileName))
				return 0;
		}
	}
	v8 = sub_409B40();
	sub_4CFE10(v8);
	if (a2)
		v9 = sub_426910(FileName, 1, -1);
	else
		v9 = sub_426910(FileName, 1, 19);
	if (!v9)
		return 0;
	sub_426AC0_file3_fread(&v10, 4u);
	if (v10 == -86065425) {
		sub_409B10(0);
	} else {
		if (v10 != -86050098) {
			sub_4269F0();
			return 0;
		}
		sub_426C20(&v11, 4u);
		sub_409B10(v11);
	}
	if (!sub_4CFCE0())
		return 0;
	sub_507290();
	sub_4269F0();
	if (!nox_common_gameFlags_check_40A5C0(0x200000)) {
		sub_4CF990();
		nullsub_21();
		if (sub_43AF70() == 1)
			sub_416690();
		nox_common_gameFlags_unset_40A540(0x4000000);
		sub_470680();
		sub_4D0550(FileName);
		sub_4161E0();
		if (!nox_common_gameFlags_check_40A5C0(128))
			sub_4165F0(0, 1);
	}
	result = 1;
	strcpy((char*)&byte_5D4594[1523080], v2);
	return result;
}
// 4CF980: using guessed type void nullsub_21(void);
// 4CF5F0: using guessed type char var_100[256];

//----- (004D0CF0) --------------------------------------------------------
char* sub_4D0CF0() {
	int v0; // eax
	int v1; // eax
	int v2; // edi
	int v4; // esi

	v0 = nox_common_gameFlags_getVal_40A5B0();
	v1 = sub_4D0D50(v0);
	v2 = *(_DWORD*)&byte_5D4594[4 * v1 + 1548428];
	if (!v2)
		return 0;
	v4 = *(_DWORD*)&byte_5D4594[4 * v1 + 1548452];
	if (v4 > v2) {
		*(_DWORD*)&byte_5D4594[4 * v1 + 1548452] = 0;
		v4 = 0;
	}
	*(_DWORD*)&byte_5D4594[4 * v1 + 1548452] = (*(_DWORD*)&byte_5D4594[4 * v1 + 1548452] + 1) % v2;
	return (char*)&byte_5D4594[128 * (v4 + 20 * v1 + 5 * v1) + 1529228];
}

//----- (004D10F0) --------------------------------------------------------
void __cdecl sub_4D10F0(char* a1) {
	int v1;              // esi
	const char* i;       // edi
	int v3;              // edi
	int v4;              // eax
	int v5;              // ebx
	int v6;              // edx
	unsigned __int8* v7; // ecx

	if (a1) {
		v1 = 0;
		if (dword_5d4594_1548476 > 0) {
			for (i = (const char*)&byte_5D4594[1525136]; _strcmpi(i, a1); i += 32) {
				if (++v1 >= *(int*)&dword_5d4594_1548476)
					return;
			}
			v3 = dword_5d4594_1548476;
			v4 = 32 * v1;
			v5 = dword_5d4594_1548480;
			*(_DWORD*)&byte_587000[191880] = v1;
			*(_DWORD*)&byte_5D4594[v4 + 1525156] = *(_DWORD*)&byte_5D4594[32 * v1 + 1525156] + 1;
			v6 = 0;
			*(_DWORD*)&byte_5D4594[v4 + 1525160] = v5;
			if (v3 > 0) {
				v7 = &byte_5D4594[1525156];
				do {
					if (*((_DWORD*)v7 - 6) == *(_DWORD*)&byte_5D4594[32 * v1 + 1525132] &&
					    v1 != v6) {
						++*(_DWORD*)v7;
						*((_DWORD*)v7 + 1) = v5;
					}
					++v6;
					v7 += 32;
				} while (v6 < v3);
			}
			dword_5d4594_1548480 = v5 + 1;
		}
	}
}

//----- (004D15F0) --------------------------------------------------------
void sub_4D15F0() { *(_DWORD*)&byte_5D4594[1548520] = 1; }

//----- (004D2160) --------------------------------------------------------
char* sub_4D2160() {
	char* result; // eax
	char* i;      // ebp
	int v2;       // edi
	char* j;      // esi
	int v4;       // eax
	int v5;       // [esp+4h] [ebp-4h]

	v5 = sub_416F40();
	result = sub_418B10();
	for (i = result; result; i = result) {
		if (!*(_DWORD*)(*((_DWORD*)i + 19) + 492) && sub_418BC0((int)i)) {
			do {
				v2 = nox_common_randomInt_415FA0(0, v5 - 1);
				for (j = sub_416EA0(); j; j = sub_416EE0((int)j)) {
					if (!v2)
						break;
					--v2;
				}
				v4 = *((_DWORD*)j + 514);
			} while (!v4 || !sub_419180(v4 + 48, i[57]));
			sub_4F3400(*((_DWORD*)j + 514), *((_DWORD*)i + 19), 1);
		}
		result = sub_418B60((int)i);
	}
	return result;
}

//----- (004D2230) --------------------------------------------------------
void sub_4D2230() {
	__int16 v0; // ax
	__int16 v1; // ax
	__int16 v2; // ax

	if (nox_common_gameFlags_check_40A5C0(49152)) {
		v0 = nox_common_gameFlags_getVal_40A5B0();
		if (!sub_40A020(v0)) {
			v1 = nox_common_gameFlags_getVal_40A5B0();
			if (!sub_40A180(v1)) {
				v2 = nox_common_gameFlags_getVal_40A5B0();
				sub_409FB0_settings(v2, 0xFu);
			}
		}
	} else if (nox_common_gameFlags_check_40A5C0(1024) && !sub_40A020(1024)) {
		sub_409FB0_settings(1024, 0xFu);
	}
}

//----- (004D22B0) --------------------------------------------------------
char* sub_4D22B0() {
	char* result; // eax
	int i;        // esi
	int v2;       // eax
	int v3;       // edi
	int v4;       // ecx
	int v5;       // eax
	int v6;       // [esp-8h] [ebp-10h]

	result = sub_416EA0();
	for (i = (int)result; result; i = (int)result) {
		v2 = *(_DWORD*)(i + 2056);
		if (v2) {
			v3 = *(_DWORD*)(v2 + 748);
			if (*(_DWORD*)(v3 + 280))
				sub_510DC0(*(_DWORD**)(v3 + 280));
			*(_DWORD*)(v3 + 280) = 0;
			sub_51AC30(*(unsigned __int8*)(i + 2064));
			if (nox_common_gameFlags_check_40A5C0(4096)) {
				v4 = *(_DWORD*)(i + 4676);
				*(_DWORD*)(i + 4676) = 0;
				*(_DWORD*)(i + 4680) = v4;
			}
			if (!sub_4FA020(*(_DWORD**)(i + 2056), 13) || !nox_common_gameFlags_check_40A5C0(512)) {
				*(_DWORD*)(i + 4700) = 0;
				v6 = ((unsigned int)sub_4CFE00() >> 1) & 1;
				v5 = sub_4DB240();
				sub_4EF7D0(*(_DWORD*)(i + 2056), v5 == 0, v6);
			}
			if (*(_BYTE*)(i + 3680) & 0x20) {
				sub_4E6AA0(i);
				sub_4E6040(*(_DWORD*)(i + 2056));
			}
			*(_DWORD*)(*(_DWORD*)(i + 2056) + 136) = *(_DWORD*)&byte_5D4594[2598000];
		}
		result = sub_416EE0(i);
	}
	return result;
}

//----- (004D2DA0) --------------------------------------------------------
int __cdecl sub_4D2DA0(__int64 a1) {
	int result;           // eax
	char* v2;             // eax
	int v3;               // ebx
	char* v4;             // esi
	double v5;            // st7
	int v6;               // esi
	int v7;               // eax
	char* v8;             // eax
	float v9;             // [esp+0h] [ebp-10h]
	unsigned __int8* v10; // [esp+4h] [ebp-Ch]

	if (dword_5d4594_528252 == 1 && *(_DWORD*)&byte_5D4594[2598000] == dword_5d4594_528260)
		sub_41E390();
	sub_5096F0();
	result = nox_common_gameFlags_check_40A5C0(8);
	if (!result) {
		if (nox_common_gameFlags_check_40A5C0(0x2000)) {
			sub_416720();
			if (!nox_common_gameFlags_check_40A5C0(128)) {
				if (sub_409F40(0x2000))
					sub_4D7CC0();
			}
		}
		if (!nox_common_gameFlags_check_40A5C0(1024))
			goto LABEL_31;
		if (sub_40AA00()) {
			if (!dword_5d4594_1548704)
				sub_4D2FF0();
		} else {
			dword_5d4594_1548704 = 0;
		}
		if (nox_common_gameFlags_check_40A5C0(0x4000000))
			goto LABEL_31;
		if (sub_40A300())
			goto LABEL_31;
		v2 = sub_416EA0();
		if (!v2)
			goto LABEL_31;
		while (*((int*)v2 + 535) <= 0) {
			v2 = sub_416EE0((int)v2);
			if (!v2)
				goto LABEL_31;
		}
		if (!sub_40AA00())
			goto LABEL_31;
		if (sub_417DA0(4)) {
			v3 = sub_417DD0();
			if (v3 >= sub_40AA40())
				goto LABEL_31;
			v4 = sub_418B10();
			if (!v4)
				goto LABEL_31;
			while (sub_40A830((int)v4) != 1) {
				v4 = sub_418B60((int)v4);
				if (!v4)
					goto LABEL_31;
			}
			v10 = &byte_587000[197200];
			v5 = sub_419D40(&byte_587000[197232]);
		} else {
			v6 = sub_40A770();
			if (v6 >= sub_40AA40()) {
			LABEL_31:
				if (sub_40A6B0()) {
					v8 = sub_416640();
					sub_4D9700(*(_DWORD*)(v8 + 66));
					sub_40A6A0(0);
				}
				if ((unsigned __int64)(a1 - *(_QWORD*)&byte_5D4594[1548692]) > 0x1F4) {
					sub_4D3050();
					*(_QWORD*)&byte_5D4594[1548692] = a1;
				}
				if (nox_common_gameFlags_check_40A5C0(128) && !sub_40A740() && sub_417DD0() &&
				    !sub_417DA0(2))
					sub_4183C0();
				result = nox_common_gameFlags_check_40A5C0(4096);
				if (result) {
					sub_4D7150();
					sub_4D71F0();
					sub_4D7600();
					sub_4DCE00();
					result = sub_4D7A80();
				}
				return result;
			}
			v10 = &byte_587000[197256];
			v5 = sub_419D40(&byte_587000[197288]);
		}
		v9 = v5;
		v7 = nox_float2int(v9);
		sub_40A2A0(v7, (const char*)v10);
		goto LABEL_31;
	}
	return result;
}

//----- (004D3130) --------------------------------------------------------
char* sub_4D3130() {
	char* result; // eax
	int i;        // esi
	int v2;       // [esp-14h] [ebp-24h]
	int v3;       // [esp-14h] [ebp-24h]
	int v4;       // [esp-10h] [ebp-20h]
	int v5;       // [esp-Ch] [ebp-1Ch]
	int v6;       // [esp-8h] [ebp-18h]
	int v7;       // [esp-4h] [ebp-14h]
	int v8;       // [esp+4h] [ebp-Ch]
	int v9;       // [esp+8h] [ebp-8h]
	int v10;      // [esp+Ch] [ebp-4h]

	sub_413C80((char*)&byte_587000[197312]);
	result = sub_416EA0();
	for (i = (int)result; result; i = (int)result) {
		sub_4E5630(*(_BYTE*)(i + 2064), &v10, &v9, &v8);
		v7 = v8;
		v6 = v9;
		v5 = v10;
		v4 = *(_DWORD*)&byte_5D4594[2598000];
		if (*(_BYTE*)(i + 2064) == 31) {
			v2 = sub_553ED0(0);
			sub_413C80((char*)&byte_587000[197316], i + 4704, v2, v4, v5, v6, v7);
		} else {
			v3 = sub_553ED0(*(unsigned __int8*)(i + 2064) + 1);
			sub_413C80((char*)&byte_587000[197340], i + 4704, v3, v4, v5, v6, v7);
		}
		result = sub_416EE0(i);
	}
	return result;
}

//----- (004D6FD0) --------------------------------------------------------
char* nox_server_switchQuestIfRequested_4D6FD0() {
	char* result;        // eax
	unsigned __int8* v1; // esi
	unsigned __int8 v2;  // dl
	char* v3;            // edi
	char* v4;            // eax
	char v5[64];         // [esp+0h] [ebp-40h]

	result = *(char**)&dword_5d4594_1556148;
	if (dword_5d4594_1556148) {
		result = (char*)(dword_5d4594_1556148 - 1);
		dword_5d4594_1556148 = result;
		if (!result) {
			v1 = sub_4DCED0();
			nox_server_setupQuestGame_4D6C70();
			if (v1 && strlen((const char*)v1)) {
				v2 = byte_587000[198596];
				strcpy(v5, (const char*)v1);
				v3 = &v5[strlen(v5)];
				v4 = v5;
				*(_DWORD*)v3 = *(_DWORD*)&byte_587000[198592];
				v3[4] = v2;
			} else {
				v4 = sub_4D0F60();
			}
			sub_4D2450(v4);
			sub_4DCE80(0);
			sub_4E3CD0(0);
			result = sub_4169F0();
		}
	}
	return result;
}
// 4D6FD0: using guessed type char var_40[64];

//----- (004D7140) --------------------------------------------------------
int __cdecl sub_4D7140(int a1) {
	int result; // eax

	result = a1;
	dword_5d4594_1556144 = a1;
	return result;
}

//----- (004DB160) --------------------------------------------------------
unsigned __int8* sub_4DB160() { return &byte_5D4594[1557900]; }

//----- (004DBA30) --------------------------------------------------------
char* __cdecl sub_4DBA30(int a1) {
	char* result; // eax
	char* v2;     // ebx
	int v3;       // ebp
	int v4;       // esi
	int v5;       // edi
	int v6;       // eax
	int v7;       // esi
	int v8;       // ebx
	int* v9;      // ebp
	int v10;      // eax
	int v11;      // eax
	int v12;      // eax
	int v13;      // ebx
	int* v14;     // edi
	int v15;      // eax
	int v16;      // ebx
	int v17;      // eax
	int v18;      // esi
	int v19;      // edi
	int v20;      // esi
	int v21;      // edi
	int i;        // esi
	int v23;      // eax
	char* v24;    // [esp+Ch] [ebp-8h]
	int v25;      // [esp+10h] [ebp-4h]
	int v26;      // [esp+18h] [ebp+4h]

	result = sub_417090(31);
	v2 = result;
	v3 = 0;
	v24 = result;
	if (result) {
		v4 = *((_DWORD*)result + 514);
		v25 = *((_DWORD*)result + 514);
		if (v4) {
			if (!*(_DWORD*)&byte_5D4594[1563128]) {
				*(_DWORD*)&byte_5D4594[1563128] = sub_4E3AA0((CHAR*)&byte_587000[199624]);
				*(_DWORD*)&byte_5D4594[1563132] = sub_4E3AA0((CHAR*)&byte_587000[199644]);
			}
			if (a1 == 1) {
				v5 = sub_4DA790();
				if (v5) {
					do {
						v26 = sub_4DA7A0(v5);
						if (*(unsigned __int16*)(v5 + 4) == *(_DWORD*)&byte_5D4594[1563128]) {
							sub_4E7010(*((_DWORD*)v2 + 514), (float2*)(v5 + 56));
							*(_DWORD*)(*((_DWORD*)v2 + 514) + 44) = *(_DWORD*)(v5 + 44);
							*(_DWORD*)(v5 + 44) = 0;
							sub_4E5CC0(v5);
						} else {
							v6 = *(_DWORD*)(v5 + 8);
							if (v6 & 2) {
								v7 = *(_DWORD*)(v5 + 748);
								v8 = 0;
								if (*(_BYTE*)(v7 + 1129)) {
									v9 = (int*)(v7 + 1132);
									do {
										v10 = sub_4ECF10(*v9);
										*v9 = v10;
										if (!v10)
											*(_BYTE*)(v7 + 1129) = 0;
										++v8;
										++v9;
									} while (v8 < *(unsigned __int8*)(v7 + 1129));
									v3 = 0;
								}
								*(_DWORD*)(v7 + 1196) =
								    sub_4ECF10(*(_DWORD*)(v7 + 1196));
								if ((int)*(_DWORD*)(v5 + 16) >= 0)
									sub_52BAF0(v5);
								v11 = sub_4ECF10(*(_DWORD*)(v7 + 392));
								if (v11)
									*(_DWORD*)(v7 + 392) = *(_DWORD*)(v11 + 36);
								else
									*(_DWORD*)(v7 + 392) = 0;
								v12 = sub_4ECF10(*(_DWORD*)(v7 + 1200));
								if (v12)
									*(_DWORD*)(v7 + 1200) = *(_DWORD*)(v12 + 36);
								else
									*(_DWORD*)(v7 + 1200) = 0;
								*(_DWORD*)(v7 + 1216) =
								    sub_4ECF10(*(_DWORD*)(v7 + 1216));
								v13 = 0;
								if (*(_BYTE*)(v7 + 2172)) {
									v14 = (int*)(v7 + 2140);
									do {
										v15 = sub_4ECF10(*v14);
										if (v15)
											*v14 = *(_DWORD*)(v15 + 36);
										else
											*(_BYTE*)(v7 + 2172) = 0;
										++v13;
										++v14;
									} while (v13 < *(unsigned __int8*)(v7 + 2172));
								}
								v2 = v24;
							} else if (v6 & 0x4000) {
								if (*(_DWORD*)(*(_DWORD*)(v5 + 748) + 16))
									sub_4E44F0(v5);
							} else if ((v6 & 0x8000) == 0) {
								if ((v6 & 0x80u) != 0 &&
								    *(_DWORD*)(*(_DWORD*)(v5 + 748) + 12) !=
									*(_DWORD*)(*(_DWORD*)(v5 + 748) + 4)) {
									sub_4DA8D0(v5);
								}
							} else {
								v23 = *(_DWORD*)(*(_DWORD*)(v5 + 748) + 4);
								if (v23 && *(_DWORD*)(*(_DWORD*)(v23 + 748) + 16))
									sub_4E44F0(v5);
							}
						}
						v5 = v26;
					} while (v26);
				}
				sub_51B0C0();
				sub_516FC0();
				if (dword_5d4594_1563096) {
					v16 = sub_4DA790();
					if (v16) {
						do {
							v3 = sub_4DA7A0(v16);
							if ((int)*(_DWORD*)(v16 + 16) >= 0 && sub_4E5B50(v16)) {
								if (*(_BYTE*)(v16 + 8) & 2) {
									v17 = *(_DWORD*)(v16 + 12);
									if (v17 & 0x2000) {
										v18 = sub_4E7980(v16);
										if (v18) {
											do {
												v19 = sub_4E7990(v18);
												if (*(unsigned __int16*)(v18 +
															 4) ==
												    *(_DWORD*)&byte_5D4594
													[1563132])
													sub_4E5CC0(v18);
												v18 = v19;
											} while (v19);
										}
									}
								}
								sub_4E5CC0(v16);
							}
							v16 = v3;
						} while (v3);
					}
					v20 = sub_4DA840();
					if (v20 != v3) {
						do {
							v21 = sub_4DA850(v20);
							if ((int)*(_DWORD*)(v20 + 16) >= 0) {
								if (sub_4E5B80(v20))
									sub_4E5CC0(v20);
							}
							v20 = v21;
						} while (v21 != v3);
					}
					v2 = v24;
				}
				sub_4DB090();
				v4 = v25;
			}
			for (i = *(_DWORD*)(v4 + 516); i != v3; i = *(_DWORD*)(i + 512)) {
				if (*(_BYTE*)(i + 8) & 2) {
					if (*(_BYTE*)(*(_DWORD*)(i + 748) + 1440) & 0x80) {
						sub_4D91A0((unsigned __int8)v2[2064], i);
						sub_417190((unsigned __int8)v2[2064], i, 1);
						continue;
					}
					if ((*(_BYTE*)(i + 12) & 0x80)) {
						sub_4D9250((unsigned __int8)v2[2064], i);
						sub_417190((unsigned __int8)v2[2064], i, 1);
						continue;
					}
				}
			}
			sub_4DB220(v3);
			dword_5d4594_1563096 = v3;
			result = (char*)sub_416D40();
		}
	}
	return result;
}

//----- (004DCC00) --------------------------------------------------------
int sub_4DCC00() { return *(_DWORD*)&byte_5D4594[1563064]; }

//----- (004DCC80) --------------------------------------------------------
int sub_4DCC80() { return *(_DWORD*)&byte_5D4594[1563072]; }

//----- (004DCF20) --------------------------------------------------------
int sub_4DCF20() {
	char* v0;   // esi
	int result; // eax

	v0 = sub_417090(31);
	result = dword_5d4594_1563052;
	if (dword_5d4594_1563052) {
		result = sub_4D6FC0();
		if (!result) {
			if (v0) {
				if (v0[3680] & 0x10) {
					sub_41A2E0((char*)&byte_5D4594[1560984], 31);
					dword_5d4594_1563052 = 0;
					result = DeleteFileA((LPCSTR)&byte_5D4594[1560984]);
				}
			}
		}
	}
	return result;
}

//----- (004DEB30) --------------------------------------------------------
void sub_4DEB30() {
	if (!(*(_DWORD*)&nox_common_engineFlags & 0x400000))
		sub_552A80(*(unsigned int*)&byte_5D4594[1563148], 1);
}

//----- (004DEB50) --------------------------------------------------------
void sub_4DEB50() {
	unsigned __int8* v2; // eax
	void* v3;            // [esp+0h] [ebp-4h]

	if (nox_common_gameFlags_check_40A5C0(2)) {
		if (*(_DWORD*)&nox_common_engineFlags & 0x400000) {
			sub_4D3580_net_playback(0);
			sub_40ED10(31, 0);
		} else {
			v2 = sub_40ED60(31, 0, &v3);
			if (v2)
				sub_51BAD0_net_sdecode(31, v2, (signed int)v3);
			sub_40ED10(31, 0);
		}
	}
}

//----- (004DEC80) --------------------------------------------------------
char* sub_4DEC80() {
	char* result;    // eax
	int i;           // esi
	int v2;          // eax
	unsigned int v3; // [esp-18h] [ebp-28h]
	int v4;          // [esp-10h] [ebp-20h]
	char v5[1];      // [esp+7h] [ebp-9h]
	char v6[3];      // [esp+8h] [ebp-8h]
	int v7;          // [esp+Ch] [ebp-4h]

	result = sub_416EA0();
	for (i = (int)result; result; i = (int)result) {
		if (*(_DWORD*)(i + 2056)) {
			v2 = -((*(_DWORD*)(i + 3680) & 0x10) != 0);
			LOBYTE(v2) = v2 & 0xC4;
			if (*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(i + 3596) >
			    (unsigned int)((v2 + 90) * *(_DWORD*)&byte_5D4594[2649704])) {
				v7 = *(_DWORD*)(i + 2060);
				sub_4DA180(3, &v7);
				v3 = *(unsigned __int8*)(i + 2064) + 1;
				v5[0] = -58;
				sub_552640(v3, v5, 1, 3);
				sub_4DEAB0(*(unsigned __int8*)(i + 2064), 3);
			}
			if ((*(_BYTE*)(i + 3680) & 0x80))
				sub_4DEAB0(*(unsigned __int8*)(i + 2064), 4);
			if (*(_BYTE*)(i + 3676) != 3 || (*(_BYTE*)(i + 3680) & 0x10) != 16) {
				v4 = *(unsigned __int8*)(i + 2064);
				v6[0] = 39;
				*(_WORD*)&v6[1] = *(_WORD*)&byte_5D4594[2598000];
				sub_40EBC0(v4, 1, v6, 3);
			} else {
				sub_518EE0(*(_DWORD**)(i + 2056));
			}
			if (*(_DWORD*)(i + 2056) == dword_5d4594_3843628) {
				sub_4E5770(*(_BYTE*)(i + 2064), 1);
			} else if (!dword_5d4594_2650652 ||
				   !(*(_DWORD*)&byte_5D4594[2598000] % (unsigned int)sub_40A6C0()) ||
				   nox_common_gameFlags_check_40A5C0(8)) {
				sub_5528B0(*(unsigned __int8*)(i + 2064) + 1, 0);
			}
		}
		result = sub_416EE0(i);
	}
	return result;
}

//----- (004DEE00) --------------------------------------------------------
_DWORD* __cdecl sub_4DEE00(const char* a1, int a2) {
	int v2;              // edx
	_DWORD* result;      // eax
	_DWORD* i;           // esi
	int v5;              // edi
	unsigned __int8* v6; // eax
	char v7[41];         // [esp+8h] [ebp-2Ch]

	v7[0] = 43;
	v2 = *(_DWORD*)&byte_5D4594[2598000];
	strcpy(&v7[1], a1);
	*(_DWORD*)&v7[37] = v2;
	*(_DWORD*)&v7[33] = a2;
	result = (_DWORD*)sub_4DA7C0();
	for (i = result; result; i = result) {
		v5 = i[187];
		sub_40EBC0(*(unsigned __int8*)(*(_DWORD*)(v5 + 276) + 2064), 1, v7, 41);
		sub_518C30((int)i, i, 0, 0);
		if (!nox_common_gameFlags_check_40A5C0(2) || *(_BYTE*)(*(_DWORD*)(v5 + 276) + 2064) != 31) {
			v6 = sub_40ED60(*(unsigned __int8*)(*(_DWORD*)(v5 + 276) + 2064), 1u, &a1);
			if (v6)
				sub_552640(*(unsigned __int8*)(*(_DWORD*)(v5 + 276) + 2064) + 1, v6, (signed int)a1, 3);
		}
		result = (_DWORD*)sub_4DA7F0((int)i);
	}
	return result;
}

//----- (004E4170) --------------------------------------------------------
void sub_4E4170() {
	float v0; // [esp+0h] [ebp-4h]

	if (!(*(_DWORD*)&byte_5D4594[2598000] % (unsigned int)(5 * *(_DWORD*)&byte_5D4594[2649704]))) {
		v0 = sub_4E3CA0();
		sub_4E3D50();
		if (sub_4E3CA0() != v0)
			sub_4E3DD0();
	}
}

//----- (004E5E20) --------------------------------------------------------
_DWORD* sub_4E5E20() {
	_DWORD* result; // eax
	_DWORD* v1;     // edi
	_DWORD* v2;     // esi

	result = *(_DWORD**)&byte_5D4594[1565588];
	v1 = 0;
	if (*(_DWORD*)&byte_5D4594[1565588]) {
		do {
			v2 = (_DWORD*)result[113];
			if (result[114] == *(_DWORD*)&byte_5D4594[2598000]) {
				result[113] = v1;
				v1 = result;
				sub_4DA920(result);
			} else {
				sub_4E5E80(result);
			}
			result = v2;
		} while (v2);
		*(_DWORD*)&byte_5D4594[1565588] = v1;
	} else {
		*(_DWORD*)&byte_5D4594[1565588] = 0;
	}
	return result;
}

//----- (004E76C0) --------------------------------------------------------
int sub_4E76C0() {
	int v0;     // edi
	int result; // eax
	int i;      // esi

	v0 = 0;
	result = sub_4DA790();
	for (i = result; result; i = result) {
		nullsub_25(i);
		v0 ^= sub_4E7700(i);
		result = sub_4DA7A0(i);
	}
	return result;
}
// 4E76F0: using guessed type void __cdecl nullsub_25(_DWORD);

//----- (004EC720) --------------------------------------------------------
void sub_4EC720() {
	int v0;     // esi
	int v1;     // eax
	int v2;     // edi
	int v3;     // ecx
	int v4;     // eax
	_DWORD* v5; // eax
	int v6;     // edi
	__int16 v7; // ax
	_BYTE* v8;  // eax
	int v9;     // eax
	int v10;    // eax
	double v11; // st7
	double v12; // st6
	int v13;    // eax
	int v14;    // ecx
	_BYTE* v15; // eax
	int v16;    // eax
	int v17;    // ecx
	int v18;    // eax

	if (!*(_DWORD*)&byte_5D4594[1568028])
		*(_DWORD*)&byte_5D4594[1568028] = sub_4E3AA0((CHAR*)&byte_587000[205204]);
	if (!nox_common_gameFlags_check_40A5C0(4608)) {
		v0 = dword_5d4594_1568024;
		*(_DWORD*)&byte_587000[205200] = 0;
		if (dword_5d4594_1568024) {
			while (1) {
				if (*(_DWORD*)(v0 + 24)) {
				LABEL_18:
					if (*(_DWORD*)&byte_5D4594[2598000] >= *(int*)(v0 + 20) &&
					    sub_4E3BA0(*(_DWORD*)v0)) {
						v5 = sub_4E3450(*(_DWORD*)v0);
						v6 = (int)v5;
						if (v5) {
							sub_4DAA50((int)v5, 0, *(float*)(v0 + 8), *(float*)(v0 + 12));
							sub_522FF0(129, (float2*)(v0 + 8));
							v7 = *(_WORD*)(v0 + 16);
							*(_WORD*)(v6 + 124) = v7;
							*(_WORD*)(v6 + 126) = v7;
							if (*(_DWORD*)(v6 + 8) & 0x13001000)
								sub_4E4990(v6, (int*)(v0 + 28));
							if (*(_DWORD*)(v6 + 8) & 0x1000000 && sub_415820(v6) & 0x82) {
								v8 = *(_BYTE**)(v6 + 736);
								v8[1] = *(_BYTE*)(v0 + 48);
								*v8 = *(_BYTE*)(v0 + 49);
							}
							sub_501960(283, v6, 0, 0);
						}
						v9 = *(_DWORD*)(v0 + 4);
						if (v9) {
							if (*(_BYTE*)(v9 + 8) & 2)
								sub_4E5CC0(*(_DWORD*)(v0 + 4));
						}
						*(_DWORD*)(v0 + 24) = 0;
						*(_DWORD*)(v0 + 4) = v6;
					}
					goto LABEL_31;
				}
				v1 = *(_DWORD*)(v0 + 4);
				v2 = 0;
				if (!v1)
					goto LABEL_16;
				v3 = *(_DWORD*)(v1 + 8);
				if (v3 & 2)
					break;
				if (*(_BYTE*)(v1 + 16) & 0x20) {
					if (sub_4E3BA0(*(unsigned __int16*)(v1 + 4)))
						v2 = 1;
					*(_DWORD*)(v0 + 4) = 0;
					if (v2)
						goto LABEL_16;
				} else if (v3 & 0x3001000 ||
					   *(unsigned __int16*)(v1 + 4) == *(_DWORD*)&byte_5D4594[1568028]) {
					if (*(_DWORD*)(v1 + 492) || !sub_4E3BA0(*(unsigned __int16*)(v1 + 4))) {
						v18 = *(_DWORD*)(v0 + 4);
						if (*(_DWORD*)(v18 + 492) &&
						    sub_4E3BA0(*(unsigned __int16*)(v18 + 4)) &&
						    *(unsigned __int16*)(*(_DWORD*)(v0 + 4) + 4) !=
							*(_DWORD*)&byte_5D4594[1568028] &&
						    sub_409F40(2)) {
							goto LABEL_16;
						}
					} else {
						v10 = *(_DWORD*)(v0 + 4);
						if (*(_DWORD*)&byte_5D4594[2598000] >
						    (unsigned int)(5 * *(_DWORD*)&byte_5D4594[2649704] +
								   *(_DWORD*)(v10 + 128))) {
							v11 = *(float*)(v0 + 8) - *(float*)(v10 + 56);
							v12 = *(float*)(v0 + 12) - *(float*)(v10 + 60);
							if (v12 * v12 + v11 * v11 > 2500.0) {
								sub_522FF0(129, (float2*)(v10 + 56));
								sub_501A30(283, (float2*)(*(_DWORD*)(v0 + 4) + 56), 0,
									   0);
								sub_4E7010(*(_DWORD*)(v0 + 4), (float2*)(v0 + 8));
								v13 = *(_DWORD*)(v0 + 4);
								v14 = *(_DWORD*)(v13 + 8);
								if (v14 & 0x1000) {
									sub_53C520(v13, 100);
								} else if (v14 & 0x1000000 &&
									   sub_415820(*(_DWORD*)(v0 + 4)) & 0x82) {
									v15 = *(_BYTE**)(*(_DWORD*)(v0 + 4) + 736);
									v15[1] = *(_BYTE*)(v0 + 48);
									*v15 = *(_BYTE*)(v0 + 49);
								}
								v16 = *(_DWORD*)(v0 + 4);
								v17 = *(_DWORD*)(v16 + 556);
								if (v17)
									sub_4E4560(v16, *(_WORD*)(v17 + 4));
								sub_522FF0(129, (float2*)(v0 + 8));
								sub_501A30(283, (float2*)(v0 + 8), 0, 0);
							}
						}
					}
				} else if (*(_DWORD*)(v1 + 492)) {
					goto LABEL_16;
				}
			LABEL_17:
				if (*(_DWORD*)(v0 + 24))
					goto LABEL_18;
			LABEL_31:
				v0 = *(_DWORD*)(v0 + 52);
				if (!v0)
					return;
			}
			v4 = *(_DWORD*)(v1 + 16);
			if (v4 & 0x20) {
				*(_DWORD*)(v0 + 4) = 0;
			} else if ((v4 & 0x8000) == 0) {
				goto LABEL_17;
			}
		LABEL_16:
			*(_DWORD*)(v0 + 24) = 1;
			*(_DWORD*)(v0 + 20) = *(_DWORD*)&byte_5D4594[2598000] + 30 * *(_DWORD*)&byte_5D4594[2649704];
			goto LABEL_17;
		}
	}
}

//----- (004EDD70) --------------------------------------------------------
int sub_4EDD70() {
	int result; // eax
	int i;      // edi
	_DWORD* v2; // esi
	_DWORD* v3; // ebx
	float2 a3;  // [esp+4h] [ebp-8h]

	result = sub_4DA7C0();
	for (i = result; result; i = result) {
		v2 = *(_DWORD**)(i + 504);
		if (v2) {
			do {
				v3 = (_DWORD*)v2[124];
				if (v2[2] & 0x10000000) {
					sub_4ED970(50.0, (float2*)(i + 56), &a3);
					sub_4ED790(i, v2, &a3);
				}
				v2 = v3;
			} while (v3);
		}
		result = sub_4DA7F0(i);
	}
	return result;
}

//----- (004EF660) --------------------------------------------------------
int __cdecl sub_4EF660(int a1) {
	int v1; // esi
	int i;  // eax

	v1 = *(_DWORD*)(a1 + 748);
	*(_DWORD*)(v1 + 116) = 0;
	*(_DWORD*)(v1 + 120) = 0;
	*(_DWORD*)(v1 + 124) = 0;
	*(_DWORD*)(v1 + 128) = 0;
	*(_DWORD*)(v1 + 308) = 0;
	for (i = 4796; i < 4816; *(_DWORD*)(*(_DWORD*)(v1 + 276) + i - 4) = 0)
		i += 4;
	if (!nox_common_gameFlags_check_40A5C0(2048))
		*(_BYTE*)(v1 + 244) = sub_4EF6F0(a1);
	*(_DWORD*)(v1 + 264) = 0;
	*(_DWORD*)(a1 + 520) = 0;
	return sub_422140(*(_DWORD*)(v1 + 276));
}

//----- (004F1F20) --------------------------------------------------------
void sub_4F1F20() {
	int v0;     // ebp
	int v1;     // eax
	int v2;     // esi
	int v3;     // ebx
	int v4;     // eax
	_DWORD* v5; // edi
	_DWORD* v6; // eax
	_DWORD* v7; // esi
	_DWORD* v8; // edi
	int v9;     // [esp+0h] [ebp-10h]
	int v10;    // [esp+4h] [ebp-Ch]
	float2 a3;  // [esp+8h] [ebp-8h]

	v9 = sub_4E3CC0();
	if (!dword_5d4594_1568300) {
		dword_5d4594_1568300 = sub_4E3AA0((CHAR*)&byte_587000[214944]);
		*(_DWORD*)&byte_5D4594[1568304] = sub_4E3AA0((CHAR*)&byte_587000[214960]);
	}
	sub_4F2110();
	sub_4F2210();
	v0 = sub_4DA790();
	if (v0) {
		do {
			v10 = sub_4DA7A0(v0);
			v1 = *(unsigned __int16*)(v0 + 4);
			if ((unsigned __int16)v1 == dword_5d4594_1568300 ||
			    v1 == *(_DWORD*)&byte_5D4594[1568304]) {
				if (*(_BYTE*)(*(_DWORD*)(v0 + 692) + 216) & 0x80) {
					v7 = nox_server_rewardgen_activateMarker_4F0720(v0, v9);
					if (v7) {
						sub_4DAA50((int)v7, 0, *(float*)(v0 + 56), *(float*)(v0 + 60));
						if (v7[2] & 0x1000000) {
							if (v7[3] & 0xC) {
								v8 = sub_4E3810((CHAR*)&byte_587000[214980]);
								if (v8) {
									a3 = *((float2*)v7 + 7);
									sub_4ED970(30.0, (float2*)v7 + 7, &a3);
									sub_4DAA50((int)v8, 0, a3.field_0, a3.field_4);
								}
							}
						}
					}
				}
				sub_4E5CC0(v0);
			} else if (*(int*(__cdecl**)(int))(v0 + 688) == sub_4F0400) {
				v2 = sub_4E7980(v0);
				if (v2) {
					do {
						v3 = sub_4E7990(v2);
						v4 = *(unsigned __int16*)(v2 + 4);
						if ((unsigned __int16)v4 == dword_5d4594_1568300 ||
						    v4 == *(_DWORD*)&byte_5D4594[1568304]) {
							v5 = nox_server_rewardgen_activateMarker_4F0720(v2, v9 + 1);
							sub_4ED0C0(v0, (int*)v2);
							sub_4E5CC0(v2);
							if (v5) {
								sub_4F3070(v0, (int)v5, 0);
								if (v5[2] & 0x1000000) {
									if (v5[3] & 0xC) {
										v6 = sub_4E3810(
										    (CHAR*)&byte_587000[214988]);
										if (v6)
											sub_4F3070(v0, (int)v6, 0);
									}
								}
							}
						}
						v2 = v3;
					} while (v3);
				}
			}
			v0 = v10;
		} while (v10);
	}
}

//----- (004FBEE0) --------------------------------------------------------
void sub_4FBEE0() {
	char* i; // edi
	int j;   // esi
	int v2;  // eax
	int v3;  // ecx
	int* v4; // esi
	int v5;  // eax
	int* v6; // edi
	int v7;  // eax
	int v8;  // eax
	int v9;  // eax
	int v10; // eax
	int v11; // [esp-Ch] [ebp-14h]

	for (i = sub_416EA0(); i; i = sub_416EE0((int)i)) {
		if (*((_DWORD*)i + 514) && !i[2251]) {
			for (j = 0; j < 6; ++j) {
				v2 = j + 6 * (unsigned __int8)i[2064];
				v3 = *(_DWORD*)&byte_5D4594[4 * v2 + 1568876];
				if (v3) {
					*(_DWORD*)&byte_5D4594[4 * v2 + 1568876] = v3 - 1;
					if (!*(_DWORD*)&byte_5D4594[4 * (j + 6 * (unsigned __int8)i[2064]) + 1568876])
						sub_4D8100(*((_DWORD*)i + 514), j, 1);
				}
			}
		}
	}
	v4 = *(int**)&dword_5d4594_1569648;
	if (dword_5d4594_1569648) {
		while (1) {
			v5 = v4[4];
			v6 = (int*)v4[4];
			if (*(_DWORD*)(v4[1] + 16) & 0x8020)
				break;
			if (*(_DWORD*)&byte_5D4594[2598000] > (unsigned int)v4[2]) {
				v11 = v4[1];
				v8 = sub_425230(*v4, 2);
				sub_501960(v8, v11, 0, 0);
				sub_4FC3C0(v4[1], *v4, 0);
				if (*v4 == 1)
					sub_4FA020((_DWORD*)v4[1], 13);
				v9 = v4[4];
				if (v9)
					*(_DWORD*)(v9 + 20) = v4[5];
				v10 = v4[5];
				if (v10) {
					*(_DWORD*)(v10 + 16) = v4[4];
					goto LABEL_24;
				}
			LABEL_23:
				dword_5d4594_1569648 = v4[4];
				goto LABEL_24;
			}
		LABEL_25:
			v4 = v6;
			if (!v6)
				return;
		}
		if (v5)
			*(_DWORD*)(v5 + 20) = v4[5];
		v7 = v4[5];
		if (v7) {
			*(_DWORD*)(v7 + 16) = v4[4];
		LABEL_24:
			sub_414330(*(unsigned int**)&dword_5d4594_1569644, v4);
			goto LABEL_25;
		}
		goto LABEL_23;
	}
}

//----- (004FC590) --------------------------------------------------------
int sub_4FC590() {
	int result; // eax
	int v1;     // esi
	int v2;     // edi

	result = dword_5d4594_1569652;
	if (dword_5d4594_1569652) {
		result = sub_4DA7C0();
		if (result) {
			v1 = 0;
			if (dword_5d4594_1599640 > 0) {
				v2 = 0;
				do {
					if (!strncmp("MapInitialize",
						     *(const char**)(v2 + dword_5d4594_1599636), 0xDu))
						nox_server_doMapScript_507310(v1, 0, 0);
					++v1;
					v2 += 48;
				} while (v1 < *(int*)&dword_5d4594_1599640);
			}
			result = sub_4FC570(0);
		}
	}
	return result;
}

//----- (004FC600) --------------------------------------------------------
int sub_4FC600() {
	int result; // eax
	int v1;     // esi
	int v2;     // edi

	result = *(_DWORD*)&byte_5D4594[1569656];
	if (*(_DWORD*)&byte_5D4594[1569656]) {
		result = sub_4DA7C0();
		if (result) {
			v1 = 0;
			if (dword_5d4594_1599640 > 0) {
				v2 = 0;
				do {
					if (!strncmp("MapEntry", *(const char**)(v2 + dword_5d4594_1599636),
						     8u))
						nox_server_doMapScript_507310(v1, 0, 0);
					++v1;
					v2 += 48;
				} while (v1 < *(int*)&dword_5d4594_1599640);
			}
			result = sub_4FC580(0);
		}
	}
	return result;
}

//----- (004FC680) --------------------------------------------------------
void sub_4FC680() {
	int v0; // eax

	if (nox_common_gameFlags_check_40A5C0(2048) && !nox_common_gameFlags_check_40A5C0(0x80000) &&
	    dword_5d4594_1569660) {
		v0 = sub_4DA7C0();
		if (v0) {
			sub_4FBB70(v0, *(int*)&dword_5d4594_1569660);
			dword_5d4594_1569660 = 0;
		}
	}
}

//----- (004FC6D0) --------------------------------------------------------
int sub_4FC6D0() {
	int result;          // eax
	char* v1;            // eax
	int i;               // edi
	int v3;              // esi
	int v4;              // eax
	BOOL v5;             // ebp
	int j;               // esi
	int v7;              // eax
	CHAR FileName[1024]; // [esp+Ch] [ebp-400h]

	result = dword_5d4594_1569652;
	if (dword_5d4594_1569652 == 1 || *(_DWORD*)&byte_5D4594[1569656] == 1) {
		result = sub_4DA7C0();
		if (result) {
			if (nox_common_gameFlags_check_40A5C0(4096)) {
				if (sub_4E3CC0() == 1) {
					sub_4D6960(255);
					sub_4D7440(1);
					sub_4D60B0();
				} else if (!sub_4D6F30() || sub_4D7430()) {
					if (sub_4D76F0() == 1) {
						sub_4D6880(255, 1);
						sub_4D76E0(0);
						sub_4D7440(1);
						sub_4D60B0();
					} else {
						v1 = sub_409E10();
						nox_sprintf(FileName, "%s\\Save\\_temp_.dat", v1);
						for (i = sub_4DA7C0(); i; i = sub_4DA7F0(i)) {
							v3 = *(_DWORD*)(i + 748);
							v4 = *(_DWORD*)(v3 + 276);
							if (*(_DWORD*)(v4 + 4792) == 1 && !*(_DWORD*)(v3 + 552) &&
							    sub_41A140(FileName, *(unsigned __int8*)(v4 + 2064))) {
								v5 = sub_419EE0(*(_BYTE*)(*(_DWORD*)(v3 + 276) + 2064));
								sub_4DCF80(
								    *(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064),
								    1);
								if (!sub_41CFA0(
									FileName,
									*(unsigned __int8*)(*(_DWORD*)(v3 + 276) +
											    2064)) &&
								    !v5)
									sub_4DCF80(
									    *(unsigned __int8*)(*(_DWORD*)(v3 + 276) +
												2064),
									    0);
								DeleteFileA(FileName);
							}
							sub_4D6770(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064));
						}
						sub_4D6880(255, 0);
						sub_4D7440(1);
						sub_4D60B0();
					}
				} else {
					sub_4D6960(255);
					sub_4D7440(1);
					sub_4D60B0();
				}
			} else {
				sub_4D9800(1, 1);
			}
			result = nox_common_gameFlags_check_40A5C0(0x2000);
			if (result) {
				result = nox_common_gameFlags_check_40A5C0(128);
				if (!result) {
					result = sub_4DA7C0();
					for (j = result; result; j = result) {
						v7 = *(_DWORD*)(*(_DWORD*)(j + 748) + 276);
						if (*(_BYTE*)(v7 + 2064) != 31 && !(*(_BYTE*)(v7 + 3680) & 1))
							sub_4FF380(j, 23, 0, 5);
						result = sub_4DA7F0(j);
					}
				}
			}
		}
	}
	return result;
}

//----- (004FCB70) --------------------------------------------------------
// Microsoft VisualC 2-14/net runtime
void sub_4FCB70() {
	sub_4FCB80();
	sub_4FEEF0();
}

//----- (005003B0) --------------------------------------------------------
int __cdecl sub_5003B0(int a1) {
	int v1;              // edi
	int result;          // eax
	int v3;              // ebp
	unsigned __int8* v4; // esi
	_BYTE* v5;           // eax

	if (*(int*)&dword_5d4594_1569756 <= 0) {
		v1 = a1;
	} else {
		v1 = sub_4FE930();
		if (!v1)
			return 0;
		while (*(_DWORD*)(v1 + 4) != 132 || *(_DWORD*)(v1 + 16) != a1 || *(_BYTE*)(v1 + 88) & 1) {
			result = sub_4FE940(v1);
			v1 = result;
			if (!result)
				return result;
		}
		if (!v1)
			return 0;
		*(_DWORD*)(v1 + 92) = sub_4FFA90;
		*(_DWORD*)(v1 + 96) = sub_500070;
		*(_DWORD*)(v1 + 100) = sub_500080;
		*(_DWORD*)(v1 + 48) = 0;
	}
	v3 = 0;
	if (dword_5d4594_1569756 > 0) {
		v4 = &byte_5D4594[1569764];
		do {
			v5 = (_BYTE*)nox_server_getWallAtPoint_410580(*v4, v4[1]);
			if (v5) {
				*v5 = v4[13];
			} else {
				v5 = sub_410250(*v4, v4[1]);
				if (!v5)
					return 0;
				v5[4] |= 8u;
				v5[1] = v4[11];
				v5[2] = v4[12];
				*v5 = v4[13];
				v5[7] = v4[14];
			}
			sub_4FFE80(v1, v5, *((_DWORD*)v4 + 1), v4[8], v4[9], v4[10]);
			++v3;
			v4 += 16;
		} while (v3 < *(int*)&dword_5d4594_1569756);
	}
	dword_5d4594_1569756 = 0;
	return 1;
}

//----- (00500510) --------------------------------------------------------
void __cdecl sub_500510(const char* a1) {
	if (a1)
		strcpy((char*)&byte_5D4594[1570008], a1);
}

//----- (00502100) --------------------------------------------------------
void sub_502100() {
	sub_4144D0(*(_DWORD**)&byte_5D4594[1599056]);
	dword_5d4594_1599060 = 0;
}

//----- (00506F30) --------------------------------------------------------
_DWORD* sub_506F30() {
	_DWORD* result; // eax
	_DWORD* v1;     // esi

	result = *(_DWORD**)&dword_5d4594_1599656;
	if (dword_5d4594_1599656) {
		do {
			v1 = (_DWORD*)result[11];
			switch (*result) {
			case 0:
			case 1:
				sub_506F80((int)result);
				break;
			case 2:
				sub_507090((int)result);
				break;
			case 3:
				sub_507100((int)result);
				break;
			default:
				break;
			}
			result = v1;
		} while (v1);
	}
	return result;
}

//----- (0050AFA0) --------------------------------------------------------
float* sub_50AFA0() {
	int i;                // edi
	int v1;               // eax
	int v2;               // esi
	int v3;               // eax
	int v4;               // esi
	int v5;               // eax
	int v6;               // esi
	int v7;               // eax
	int v8;               // esi
	int v9;               // eax
	int v10;              // eax
	double v11;           // st7
	int v12;              // ebx
	int v13;              // esi
	int v14;              // eax
	int v15;              // ecx
	unsigned __int8* v16; // ebp
	float* v17;           // esi
	__int16 v18;          // ax
	float* result;        // eax
	float* k;             // edi
	int v21;              // esi
	int v22;              // eax
	float v23;            // [esp+0h] [ebp-3Ch]
	float v24;            // [esp+0h] [ebp-3Ch]
	float v25;            // [esp+0h] [ebp-3Ch]
	float v26;            // [esp+0h] [ebp-3Ch]
	float v27;            // [esp+0h] [ebp-3Ch]
	float v28;            // [esp+0h] [ebp-3Ch]
	float v29;            // [esp+0h] [ebp-3Ch]
	float v30;            // [esp+0h] [ebp-3Ch]
	float v31;            // [esp+0h] [ebp-3Ch]
	float v32;            // [esp+0h] [ebp-3Ch]
	float v33;            // [esp+0h] [ebp-3Ch]
	float v34;            // [esp+0h] [ebp-3Ch]
	float v35;            // [esp+4h] [ebp-38h]
	float v36;            // [esp+4h] [ebp-38h]
	int j;                // [esp+14h] [ebp-28h]
	int v38;              // [esp+18h] [ebp-24h]
	int v39;              // [esp+1Ch] [ebp-20h]
	int v40;              // [esp+20h] [ebp-1Ch]
	float v41;            // [esp+24h] [ebp-18h]
	float v42;            // [esp+28h] [ebp-14h]
	float2 a2;            // [esp+2Ch] [ebp-10h]
	int v44;              // [esp+34h] [ebp-8h]

	dword_5d4594_2386160 = 0;
	memset(&byte_5D4594[1599716], 0, 0xC0000u);
	dword_5d4594_2386164 = 0;
	for (i = sub_4DA790(); i; i = sub_4DA7A0(i)) {
		sub_50B2C0(i);
		v1 = *(_DWORD*)(i + 8);
		if ((v1 & 0x80u) == 0) {
			if (v1 & 0x800) {
				v23 = *(float*)(i + 56) * 0.043478262;
				v2 = nox_float2int(v23);
				v24 = *(float*)(i + 60) * 0.043478262;
				v3 = nox_float2int(v24);
				byte_5D4594[12 * (v3 + (v2 << 8)) + 1599724] |= 0x10u;
			} else if (v1 & 0x400) {
				v25 = *(float*)(i + 56) * 0.043478262;
				v4 = nox_float2int(v25);
				v26 = *(float*)(i + 60) * 0.043478262;
				v5 = nox_float2int(v26);
				byte_5D4594[12 * (v5 + (v4 << 8)) + 1599724] |= 0x20u;
			} else if (v1 & 0x4000) {
				v27 = *(float*)(i + 56) * 0.043478262;
				v6 = nox_float2int(v27);
				v28 = *(float*)(i + 60) * 0.043478262;
				v7 = nox_float2int(v28);
				byte_5D4594[12 * (v7 + (v6 << 8)) + 1599724] |= 4u;
			} else if ((v1 & 0x8000) == 0) {
				if (!(*(_BYTE*)(i + 16) & 0x49)) {
					if (v1 & 0x400000) {
						v31 = *(float*)(i + 232) * 0.043478262;
						v10 = nox_float2int(v31);
						v11 = *(float*)(i + 236) * 0.043478262;
						v12 = v10;
						v44 = v10;
						v32 = v11;
						v13 = nox_float2int(v32);
						v33 = *(float*)(i + 240) * 0.043478262;
						v39 = nox_float2int(v33);
						v34 = *(float*)(i + 244) * 0.043478262;
						v14 = nox_float2int(v34);
						v15 = v13;
						v40 = v14;
						for (j = v13; v15 <= v14; j = v15) {
							v38 = v12;
							if (v12 <= v39) {
								v16 = &byte_5D4594[12 * (v15 + (v12 << 8)) + 1599724];
								do {
									v17 = (float*)&byte_587000[234108];
									while (1) {
										v41 = (double)v38 * 23.0;
										a2.field_0 = v41 + *(v17 - 1);
										v42 = (double)j * 23.0;
										a2.field_4 = v42 + *v17;
										if (sub_547DB0(i, &a2))
											break;
										v17 += 2;
										if ((int)v17 >=
										    (int)&byte_587000[234180])
											goto LABEL_22;
									}
									v18 = *(_WORD*)v16;
									LOBYTE(v18) = *(unsigned __int16*)v16 | 1;
									*(_WORD*)v16 = v18;
									if (!(*(_BYTE*)(i + 16) & 0x10)) {
										LOBYTE(v18) = v18 | 2;
										*(_WORD*)v16 = v18;
									}
								LABEL_22:
									++v12;
									v16 += 3072;
									v38 = v12;
								} while (v12 <= v39);
								v15 = j;
								v14 = v40;
								v12 = v44;
							}
							++v15;
						}
					}
				}
			} else {
				v29 = *(float*)(i + 56) * 0.043478262;
				v8 = nox_float2int(v29);
				v30 = *(float*)(i + 60) * 0.043478262;
				v9 = nox_float2int(v30);
				byte_5D4594[12 * (v9 + (v8 << 8)) + 1599724] |= 8u;
			}
		}
	}
	result = (float*)sub_579860();
	for (k = result; result; k = result) {
		if (sub_579EE0((int)k, 0x80u)) {
			v35 = k[2] * 0.043478262;
			v21 = nox_float2int(v35);
			v36 = k[3] * 0.043478262;
			v22 = nox_float2int(v36);
			*(_WORD*)&byte_5D4594[12 * (v22 + (v21 << 8)) + 1599724] |= 0x40u;
		}
		result = (float*)sub_579870((int)k);
	}
	return result;
}

//----- (0050D890) --------------------------------------------------------
unsigned int sub_50D890() {
	unsigned int result; // eax

	if (!(*(_DWORD*)&byte_5D4594[2598000] % (unsigned int)(5 * *(_DWORD*)&byte_5D4594[2649704])))
		sub_50D8D0();
	result = *(_DWORD*)&byte_5D4594[2598000] / 0xFu;
	if (!(*(_DWORD*)&byte_5D4594[2598000] % 0xFu))
		result = sub_50D960();
	return result;
}

//----- (00511590) --------------------------------------------------------
void __cdecl sub_511590(int a1, int a2) {
	int v2;         // ebx
	_DWORD* v3;     // eax
	int v4;         // esi
	double v5;      // st7
	double v6;      // st6
	char v7;        // dl
	long double v8; // st7
	float v9;       // [esp+10h] [ebp+4h]

	v2 = a1;
	if (a1) {
		if (a2) {
			if (!(*(_BYTE*)(a1 + 16) & 0x20) && !(*(_BYTE*)(a2 + 16) & 0x20)) {
				v3 = nox_alloc_class_new_obj_zero(*(_DWORD**)&dword_5d4594_2386568);
				v4 = (int)v3;
				if (v3) {
					v3[2] = a1;
					v3[3] = a2;
					v3[4] = 1114636288;
					v9 = sub_4E4A70(a1);
					if (sub_4E4A70(a2) >= v9)
						sub_4E4A70(a2);
					else
						sub_4E4A70(v2);
					*(_DWORD*)(v4 + 20) = 0;
					v5 = *(float*)(a2 + 56) - *(float*)(v2 + 56);
					v6 = *(float*)(a2 + 60) - *(float*)(v2 + 60);
					v7 = *(_BYTE*)(v4 + 40) | 1;
					*(_DWORD*)(v4 + 28) = 1132462080;
					*(_BYTE*)(v4 + 40) = v7;
					v8 = sqrt(v6 * v6 + v5 * v5);
					*(float*)(v4 + 32) = v8;
					*(float*)(v4 + 36) = v8;
					*(float*)(v4 + 24) = v8;
					sub_511560(v4);
				}
			}
		}
	}
}

//----- (00519990) --------------------------------------------------------
void sub_519990() {
	int v0;              // edi
	unsigned __int8* v1; // esi

	if (dword_5d4594_2388648) {
		if (!*(_DWORD*)&byte_5D4594[2388644])
			sub_519EB0_net_mapsend();
		v0 = 0;
		v1 = &byte_5D4594[2387180];
		do {
			if (*((_WORD*)v1 - 15) == 1) {
				if (sub_519930(v0 + 1) > *(v1 - 4))
					++*(_DWORD*)v1;
				else
					sub_5199F0_net_mapsend(v1 - 32);
			}
			v1 += 48;
			++v0;
		} while ((int)v1 < (int)&byte_5D4594[2388668]);
	}
}

//----- (0051A1F0) --------------------------------------------------------
void __cdecl sub_51A1F0(int a1) {
	int v1;           // ebx
	int v2;           // edi
	int v3;           // ebx
	int v4;           // eax
	int v5;           // ecx
	int v6;           // esi
	double v7;        // st7
	int v8;           // eax
	int v9;           // ebx
	int v10;          // ebp
	int v11;          // esi
	int v12;          // edi
	int v13;          // eax
	int v14;          // ebx
	int v15;          // edi
	int i;            // esi
	int v17;          // esi
	int v18;          // edi
	float v19;        // [esp+0h] [ebp-20h]
	float v20;        // [esp+0h] [ebp-20h]
	unsigned int v21; // [esp+10h] [ebp-10h]
	int v22;          // [esp+14h] [ebp-Ch]
	int v23;          // [esp+18h] [ebp-8h]
	unsigned int v24; // [esp+1Ch] [ebp-4h]
	int v25;          // [esp+24h] [ebp+4h]

	v21 = 0;
	v23 = 0;
	v1 = sub_4E3CC0();
	v22 = v1;
	v19 = sub_419D40(&byte_587000[252424]);
	v24 = nox_float2int(v19);
	if (!*(_DWORD*)&byte_5D4594[2388668]) {
		*(_DWORD*)&byte_5D4594[2388668] = sub_4E3AA0((CHAR*)&byte_587000[252444]);
		*(_DWORD*)&byte_5D4594[2388672] = sub_4E3AA0((CHAR*)&byte_587000[252460]);
	}
	v2 = sub_4DA790();
	if (v2) {
		v3 = a1;
		do {
			v4 = sub_4DA7A0(v2);
			v5 = *(_DWORD*)(v2 + 8);
			v25 = v4;
			if (v5 & 0x20 && *(_BYTE*)(v2 + 12) & 1) {
				++v21;
			} else if (*(unsigned __int16*)(v2 + 4) == *(_DWORD*)&byte_5D4594[2388668]) {
				++v23;
			}
			if (v5 & 0x20000) {
				v6 = *(_DWORD*)(v2 + 748);
				if (*(_DWORD*)(16 * v3 + v6)) {
					switch (*(unsigned __int8*)(v6 + v3 + 83)) {
					case 0u:
						v7 = sub_419D40(&byte_587000[252480]);
						goto LABEL_18;
					case 1u:
						v7 = sub_419D40(&byte_587000[252512]);
						goto LABEL_18;
					case 2u:
						v7 = sub_419D40(&byte_587000[252548]);
						goto LABEL_18;
					case 3u:
						v7 = sub_419D40(&byte_587000[252580]);
					LABEL_18:
						*(_BYTE*)(v6 + 87) = (__int64)v7;
						break;
					default:
						break;
					}
					if (sub_4E3CC0() >= v24 && *(_BYTE*)(v6 + v3 + 83) != 3)
						*(_BYTE*)(v6 + 87) *= 2;
					v8 = sub_51A500(*(_DWORD*)(16 * v3 + v6));
					if (v8)
						*(_WORD*)(v2 + 4) = v8;
				} else {
					sub_4E5CC0(v2);
				}
			}
			v2 = v25;
		} while (v25);
		if (v21 > 1) {
			v9 = nox_common_randomInt_415FA0(0, v21 - 1);
			v10 = 0;
			v11 = sub_4DA790();
			if (v11) {
				do {
					v12 = sub_4DA7A0(v11);
					if (*(_BYTE*)(v11 + 8) & 0x20 && *(_BYTE*)(v11 + 12) & 1) {
						if (v10 != v9)
							sub_4E5CC0(v11);
						++v10;
					}
					v11 = v12;
				} while (v12);
			}
		}
		v1 = v22;
	}
	sub_51A940(0);
	if (v1 >= 5) {
		v20 = sub_419D40(&byte_587000[252656]);
		v13 = nox_float2int(v20);
		if (v1 == 5 || v1 >= v13 || v1 & 1 && nox_common_randomInt_415FA0(1, 100) >= 50) {
			sub_51A940(1);
			if (v23) {
				v14 = nox_common_randomInt_415FA0(1, v23);
				v15 = 0;
				for (i = sub_4DA790(); i; i = sub_4DA7A0(i)) {
					if (*(unsigned __int16*)(i + 4) == *(_DWORD*)&byte_5D4594[2388668] &&
					    ++v15 == v14)
						sub_51A5A0((int*)(i + 56));
					if (*(unsigned __int16*)(i + 4) == *(_DWORD*)&byte_5D4594[2388672] &&
					    nox_common_randomInt_415FA0(1, 100) >= 50)
						sub_51A7A0((int*)(i + 56));
				}
			}
		}
	}
	v17 = sub_4DA790();
	if (v17) {
		do {
			v18 = sub_4DA7A0(v17);
			if (*(unsigned __int16*)(v17 + 4) == *(_DWORD*)&byte_5D4594[2388668])
				sub_4E5CC0(v17);
			if (*(unsigned __int16*)(v17 + 4) == *(_DWORD*)&byte_5D4594[2388672])
				sub_4E5CC0(v17);
			v17 = v18;
		} while (v18);
	}
}

//----- (0051A920) --------------------------------------------------------
int __cdecl sub_51A920(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[2388660] = a1;
	return result;
}

//----- (0051ADF0) --------------------------------------------------------
void sub_51ADF0() {
	_DWORD* v0; // esi
	int v1;     // edi
	int v2;     // ebx
	int v3;     // ebp

	v0 = *(_DWORD**)&dword_5d4594_2487236;
	if (dword_5d4594_2487236) {
		do {
			if (*v0 > *(int*)&byte_5D4594[2598000]) {
				v0 = (_DWORD*)v0[6];
			} else {
				v1 = v0[1];
				v2 = v0[5];
				v3 = v0[4];
				if (*(_DWORD*)(48 * v1 + dword_5d4594_1599636 + 8))
					sub_507230(v0[2]);
				v0 = (_DWORD*)sub_51AD90((int)v0);
				nox_server_doMapScript_507310(v1, v2, v3);
			}
		} while (v0);
	}
}

//----- (0051B100) --------------------------------------------------------
char sub_51B100() {
	int i;                    // esi
	int v1;                   // edi
	int v2;                   // esi
	int v3;                   // ebx
	int v4;                   // eax
	int v5;                   // eax
	void(__cdecl * v6)(int);  // eax
	int v7;                   // edi
	_WORD* v8;                // eax
	double v9;                // st7
	int v10;                  // eax
	int v11;                  // ecx
	int v12;                  // eax
	int j;                    // esi
	void(__cdecl * v14)(int); // eax
	int v15;                  // eax
	int v16;                  // ecx
	int v17;                  // edx
	int v18;                  // eax
	int k;                    // esi
	int v20;                  // eax
	int v21;                  // edx
	int v22;                  // ecx
	__int16 v23;              // ax
	__int16 v24;              // ax
	char v25;                 // al
	int v26;                  // eax
	_WORD* v27;               // eax
	BOOL v28;                 // edi
	int v29;                  // ecx
	int v30;                  // edi
	unsigned __int8 v31;      // cl
	_BYTE* v32;               // esi
	char v33;                 // bl
	char v34;                 // al
	int v35;                  // edx
	char v36;                 // al
	int v37;                  // eax
	char v38;                 // al
	int v39;                  // eax
	int v40;                  // eax
	int v41;                  // ecx
	int v42;                  // eax
	double v43;               // st7
	int v44;                  // ecx
	char* v45;                // eax
	int v46;                  // eax
	char v47;                 // al
	int v48;                  // eax
	int v49;                  // eax
	int v50;                  // ecx
	int v51;                  // eax
	double v52;               // st7
	int v53;                  // ecx
	char* v54;                // eax
	int v55;                  // eax
	double v56;               // st7
	float v58;                // [esp+0h] [ebp-48h]
	float v59;                // [esp+0h] [ebp-48h]
	char v60;                 // [esp+17h] [ebp-31h]
	float v61;                // [esp+18h] [ebp-30h]
	float v62;                // [esp+1Ch] [ebp-2Ch]
	float2 v63;               // [esp+20h] [ebp-28h]
	float2 v64;               // [esp+28h] [ebp-20h]
	float v65;                // [esp+34h] [ebp-14h]
	float4 v66;

	for (i = sub_4DA7C0(); i; i = sub_4DA7F0(i)) {
		v1 = *(_DWORD*)(i + 748);
		sub_4FA490(i);
		*(_DWORD*)(v1 + 288) = sub_54AF40(i);
	}
	v2 = sub_4DA8A0();
	if (v2) {
		do {
			v3 = sub_4DA8B0(v2);
			if (!(*(_BYTE*)(v2 + 16) & 0x20)) {
				v4 = *(_DWORD*)(v2 + 520);
				if (v4 && *(_BYTE*)(v4 + 16) & 0x20) {
					v5 = *(_DWORD*)(v4 + 508);
					if (!v5 || *(_BYTE*)(v5 + 16) & 0x20)
						*(_DWORD*)(v2 + 520) = 0;
					else
						*(_DWORD*)(v2 + 520) = v5;
				}
				v6 = *(void(__cdecl**)(int))(v2 + 744);
				if (v6) {
					if (*(_BYTE*)(v2 + 8) & 4) {
						v7 = *(_DWORD*)(v2 + 748);
						if (!(*(_BYTE*)(v2 + 16) & 2))
							v6(v2);
						sub_51AC30(*(unsigned __int8*)(*(_DWORD*)(v7 + 276) + 2064));
					} else if (!(*(_BYTE*)(v2 + 16) & 2)) {
						v6(v2);
					}
				}
				if (*(_BYTE*)(v2 + 8) & 2)
					sub_4E44F0(v2);
				sub_51B870(v2);
				v8 = *(_WORD**)(v2 + 556);
				if (v8)
					v8[1] = *v8;
				v9 = *(float*)(v2 + 64) - *(float*)(v2 + 56);
				*(_DWORD*)(v2 + 16) &= 0xFFEFFFFF;
				v58 = v9;
				v61 = sub_419A10(v58);
				v59 = *(float*)(v2 + 68) - *(float*)(v2 + 60);
				v62 = sub_419A10(v59);
				if (*(float*)(v2 + 88) <= *(double*)&qword_581450_10392 ||
				    *(float*)(v2 + 88) >= *(double*)&qword_581450_10256 ||
				    *(float*)(v2 + 92) <= *(double*)&qword_581450_10392 ||
				    *(float*)(v2 + 92) >= *(double*)&qword_581450_10256 ||
				    *(float*)(v2 + 80) <= *(double*)&qword_581450_10392 ||
				    *(float*)(v2 + 80) >= *(double*)&qword_581450_10256 ||
				    *(float*)(v2 + 84) <= *(double*)&qword_581450_10392 ||
				    *(float*)(v2 + 84) >= *(double*)&qword_581450_10256 ||
				    v61 <= *(double*)&qword_581450_10392 || v61 >= *(double*)&qword_581450_10256 ||
				    v62 <= *(double*)&qword_581450_10392 || v62 >= *(double*)&qword_581450_10256 ||
				    *(float*)(v2 + 104) <= *(double*)&qword_581450_10392 ||
				    *(float*)(v2 + 104) >= *(double*)&qword_581450_10256 ||
				    *(float*)(v2 + 108) <= *(double*)&qword_581450_10392 ||
				    *(float*)(v2 + 108) >= *(double*)&qword_581450_10256) {
					sub_537610(v2);
					*(_DWORD*)(v2 + 16) &= 0xF7FFFFFF;
				} else {
					*(_DWORD*)(v2 + 88) = 0;
					*(_DWORD*)(v2 + 92) = 0;
					*(_DWORD*)(v2 + 80) = 0;
					*(_DWORD*)(v2 + 84) = 0;
					sub_4E46F0(v2, 0.0);
					v10 = *(_DWORD*)(v2 + 56);
					*(_DWORD*)(v2 + 68) = *(_DWORD*)(v2 + 60);
					v11 = *(_DWORD*)(v2 + 16);
					*(_DWORD*)(v2 + 64) = v10;
					v12 = *(_DWORD*)(v2 + 744);
					*(_DWORD*)(v2 + 108) = 0;
					*(_DWORD*)(v2 + 16) = v11 | 0x8000000;
					if (!v12)
						sub_4DA920((_DWORD*)v2);
				}
			}
			v2 = v3;
		} while (v3);
	}
	for (j = sub_4DA840(); j; j = sub_4DA850(j)) {
		if (!(*(_BYTE*)(j + 16) & 0x22)) {
			v14 = *(void(__cdecl**)(int))(j + 744);
			if (v14)
				v14(j);
			sub_51B870(j);
			sub_51B810(j);
			sub_537770(j);
			v15 = *(_DWORD*)(j + 56);
			v16 = *(_DWORD*)(j + 60);
			*(_WORD*)(j + 124) = *(_WORD*)(j + 126);
			v17 = *(_DWORD*)(j + 64);
			*(_DWORD*)(j + 72) = v15;
			v18 = *(_DWORD*)(j + 68);
			*(_DWORD*)(j + 56) = v17;
			*(_DWORD*)(j + 76) = v16;
			*(_DWORD*)(j + 60) = v18;
			*(_DWORD*)(j + 88) = 0;
			*(_DWORD*)(j + 92) = 0;
			sub_517970(j);
		}
	}
	sub_511850();
	for (k = sub_4DA8A0(); k; k = sub_4DA8B0(k)) {
		v20 = *(_DWORD*)(k + 64);
		v21 = *(_DWORD*)(k + 60);
		*(_DWORD*)(k + 72) = *(_DWORD*)(k + 56);
		v22 = *(_DWORD*)(k + 68);
		*(_DWORD*)(k + 56) = v20;
		LOBYTE(v20) = *(_BYTE*)(k + 541);
		*(_DWORD*)(k + 76) = v21;
		LOWORD(v21) = *(_WORD*)(k + 126);
		*(_DWORD*)(k + 60) = v22;
		*(_DWORD*)(k + 88) = 0;
		*(_DWORD*)(k + 92) = 0;
		*(_WORD*)(k + 124) = v21;
		if ((unsigned __int8)v20 > 4u)
			*(_BYTE*)(k + 541) = 4;
		*(float*)(k + 544) =
		    (*(float*)(k + 552) + *(float*)(k + 548)) * (5.0 - (double)*(unsigned __int8*)(k + 541)) * 0.2;
		if (sub_4FF350(k, 4))
			*(float*)(k + 544) = *(float*)(k + 544) * 0.5;
		if (*(_BYTE*)(k + 541) || *(_BYTE*)(k + 540)) {
			v23 = *(_WORD*)(k + 542);
			if (v23 > 0) {
				v24 = v23 - 1;
				*(_WORD*)(k + 542) = v24;
				if (!v24) {
					v25 = *(_BYTE*)(k + 541);
					if (v25)
						*(_BYTE*)(k + 541) = v25 - 1;
					if (*(_BYTE*)(k + 540)) {
						v26 = *(_DWORD*)(k + 16);
						if ((v26 & 0x8000) == 0)
							sub_4EE8F0(k, 1);
					}
					*(_WORD*)(k + 542) = 1000;
				}
			}
		}
		sub_4FF620(k);
		if (*(_BYTE*)(k + 540)) {
			v27 = *(_WORD**)(k + 556);
			if (v27) {
				if (v27[2] > 0u && *v27 > 0u) {
					v28 = nox_common_gameFlags_check_40A5C0(4096);
					v29 = *(_DWORD*)(*(_DWORD*)(k + 556) + 16);
					v30 = v28 + 1;
					if (!v29 || (unsigned int)(*(_DWORD*)&byte_5D4594[2598000] - v29) > 0x3C) {
						v31 = *(_BYTE*)(k + 540);
						if (v31 > 8u || !(*(_DWORD*)&byte_5D4594[2598000] %
								  (unsigned int)(128 >> (v31 - 1))))
							(*(void(__cdecl**)(int, _DWORD, _DWORD, int, int))(k + 716))(
							    k, 0, 0, v30, 5);
					}
				}
			}
		}
	}
	v32 = sub_410780();
	if (v32) {
		v33 = v60;
		while (v32) {
			switch (v32[21]) {
			case 1:
				v47 = v32[20];
				if (v47 & 4) {
					if ((v47 & 8) == 8) {
						v48 = *((_DWORD*)v32 + 6) - 1;
						*((_DWORD*)v32 + 6) = v48;
						if (!v48) {
							v49 = *((_DWORD*)v32 + 1);
							v32[21] = 4;
							v50 = 23 * v49;
							v51 = *((_DWORD*)v32 + 2);
							v52 = (double)(v50 + 11);
							v53 = *((_DWORD*)v32 + 3);
							v64.field_0 = v52;
							v64.field_4 = (double)(23 * v51 + 11);
							v54 = sub_410EE0(*(unsigned __int8*)(v53 + 1));
							v55 = sub_40AF50(v54);
							sub_501A30(v55, &v64, 0, 0);
						}
					}
				}
				goto LABEL_90;
			case 2:
				v36 = v32[22] - 1;
				v32[22] = v36;
				if (!v36) {
					v37 = *((_DWORD*)v32 + 4);
					v32[21] = 1;
					*((_DWORD*)v32 + 6) = *(_DWORD*)&byte_5D4594[2649704] * v37;
				}
				v33 = 1;
				goto LABEL_92;
			case 3:
				v38 = v32[20];
				if (!(v38 & 4) || v38 & 8 ||
				    (v39 = *((_DWORD*)v32 + 6) - 1, (*((_DWORD*)v32 + 6) = v39) != 0)) {
				LABEL_90:
					v33 = 0;
				} else {
					v40 = *((_DWORD*)v32 + 1);
					v32[21] = 2;
					v41 = 23 * v40;
					v42 = *((_DWORD*)v32 + 2);
					v43 = (double)(v41 + 11);
					v44 = *((_DWORD*)v32 + 3);
					v63.field_0 = v43;
					v63.field_4 = (double)(23 * v42 + 11);
					v45 = sub_410F20(*(unsigned __int8*)(v44 + 1));
					v46 = sub_40AF50(v45);
					sub_501A30(v46, &v63, 0, 0);
					v33 = 0;
				}
				break;
			case 4:
				v34 = v32[22] + 1;
				v32[22] = v34;
				if (v34 == 23) {
					v35 = *((_DWORD*)v32 + 4);
					v32[21] = 3;
					*((_DWORD*)v32 + 6) = *(_DWORD*)&byte_5D4594[2649704] * v35;
				}
				v33 = 1;
				goto LABEL_92;
			default:
				if (v33) {
				LABEL_92:
					v56 = (double)(int)(23 * *((_DWORD*)v32 + 1)) + 11.5;
					v65 = (double)(int)(23 * *((_DWORD*)v32 + 2)) + 11.5;
					v66.field_0 = v56 - 42.5;
					v66.field_4 = v65 - 42.5;
					v66.field_8 = v56 + 42.5;
					v66.field_C = v65 + 42.5;
					sub_517C10(&v66, (void(__cdecl*)(float*, int))sub_51B860, 0);
				}
				break;
			}
			v32 = (_BYTE*)sub_410790((int*)v32);
		}
	}
	sub_511750();
	return sub_509A60();
}
// 51B5E7: variable 'v60' is possibly undefined

//----- (005524C0) --------------------------------------------------------
void sub_5524C0() {
	unsigned int v0;  // edi
	unsigned int* v1; // esi

	dword_5d4594_2495920 = nox_get_ticks();
	v0 = 0;
	v1 = (unsigned int*)&byte_5D4594[3843788];
	do {
		unsigned int result = *v1;
		if (*v1 && *(_DWORD*)(result + 152) == 1) {
			_DWORD result = *(_DWORD*)(result + 160) + 300;
			if (result < *(int*)&byte_5D4594[2598000])
				result = sub_5545B0(v0);
		}
		++v1;
		++v0;
	} while ((int)v1 < (int)&byte_5D4594[3844300]);
}

//----- (00578FC0) --------------------------------------------------------
char* sub_578FC0() {
	char* result; // eax

	result = *(char**)&dword_5d4594_2523744;
	if (dword_5d4594_2523744) {
		result = (char*)sub_578FF0();
		if (*(_WORD*)&byte_5D4594[2523738] > 0) {
			if (byte_5D4594[2598000] & 1)
				result = sub_579190();
		}
	}
	return result;
}

//----- (0057B140) --------------------------------------------------------
BOOL sub_57B140() {
	unsigned __int64 v0; // rdi
	BOOL result;         // eax

	result = 0;
	if (*(_QWORD*)&byte_5D4594[2523796]) {
		v0 = sub_57B180() + 5000;
		if (v0 < sub_416BB0())
			result = 1;
	}
	return result;
}

//----- (004D1860) --------------------------------------------------------
int sub_4D1860_server() {
	int v0;           // esi
	int v1;           // edi
	char* v2;         // eax
	int i;            // eax
	int j;            // eax
	char* v5;         // eax
	int v6;           // esi
	char* v7;         // ebx
	int* v8;          // eax
	int* v9;          // eax
	char* v10;        // eax
	int v11;          // eax
	__int16 v12;      // ax
	int v13;          // eax
	int* v14;         // eax
	int k;            // esi
	char* v17;        // eax
	int v18;          // eax
	int v19;          // esi
	int v20;          // edi
	int v21;          // ebx
	int v22;          // eax
	int v23;          // ecx
	wchar_t* v24;     // eax
	int l;            // ebx
	char* v27;        // eax
	int v28;          // eax
	int v29;          // esi
	char* v30;        // eax
	int v31;          // eax
	int v32;          // eax
	char* v33;        // eax
	int v34;          // eax
	int v35;          // eax
	float* v36;       // esi
	char* v37;        // eax
	double v38;       // st7
	char* v39;        // eax
	double v40;       // st7
	char* v41;        // eax
	int v42;          // eax
	const char* v43;  // edi
	int v44;          // esi
	float2* v45;      // edi
	int m;            // ebx
	int n;            // esi
	int v48;          // edi
	int* v49;         // eax
	int ii;           // eax
	int jj;           // eax
	int v52;          // eax
	int v53;          // eax
	int v54;          // eax
	char* v55;        // eax
	unsigned int v56; // esi
	char v57;         // al
	int* v58;         // [esp-1Ch] [ebp-68h]
	__int16 v59;      // [esp-14h] [ebp-60h]
	__int16 v60;      // [esp-14h] [ebp-60h]
	float2 v61;       // [esp+0h] [ebp-4Ch]
	__int64 v62;      // [esp+8h] [ebp-44h]
	int v63[15];      // [esp+10h] [ebp-3Ch]

	if (nox_common_gameFlags_check_40A5C0(2))
		nox_client_setCursorType_477610(10);
	sub_4D22B0();
	sub_4D9800(0, 1);
	v0 = 0;
	if (dword_5d4594_1599640 > 0) {
		v1 = 0;
		do {
			if (!strncmp("MapExit", *(const char**)(v1 + dword_5d4594_1599636), 7u))
				nox_server_doMapScript_507310(v0, 0, 0);
			++v0;
			v1 += 48;
		} while (v0 < *(int*)&dword_5d4594_1599640);
	}
	v2 = sub_409B40();
	sub_500510(v2);
	sub_4D12E0(1);
	for (i = sub_4DA790(); i; i = sub_4DA7A0(i))
		*(_DWORD*)(i + 16) |= 0x80000000;
	for (j = sub_4DA840(); j; j = sub_4DA850(j))
		*(_DWORD*)(j + 16) |= 0x80000000;
	if (nox_common_gameFlags_check_40A5C0(2048)) {
		sub_424BD0();
		sub_4537F0();
	}
	if (sub_4DB240()) {
		v5 = sub_4DB260();
		v6 = nox_server_loadMapFile_4CF5F0(v5, 0);
	} else {
		v7 = sub_4165B0();
		if (nox_common_gameFlags_check_40A5C0(0x2000)) {
			if (!v7[57]) {
				strcpy((char*)v63, v7);
				v59 = *((_WORD*)v7 + 26);
				v8 = (int*)sub_459870();
				sub_57A1E0(v63, "user.rul", v8, 3, v59);
				v9 = (int*)sub_459870();
				sub_57AAA0("user.rul", v7, v9);
			}
			sub_424BD0();
			sub_4537F0();
		}
		v10 = nox_server_currentMapGetFilename_409B30();
		v6 = nox_server_loadMapFile_4CF5F0(v10, 0);
		if (nox_common_gameFlags_check_40A5C0(0x2000) && !nox_common_gameFlags_check_40A5C0(128)) {
			v11 = sub_40A8A0();
			v13 = 0;
			if (v11) {
				v12 = nox_common_gameFlags_getVal_40A5B0();
				if (sub_40A180(v12))
					v13 = 1;
			}
			sub_40A1F0(v13);
			sub_40A250();
			v60 = nox_common_gameFlags_getVal_40A5B0();
			v58 = (int*)sub_459870();
			v14 = (int*)sub_416590(0);
			sub_57A1E0(v14, "user.rul", v58, 3, v60);
			sub_4D2230();
		}
	}
	if (!v6) {
		sub_4D15F0();
		return 0;
	}
	if (!nox_common_gameFlags_check_40A5C0(2048))
		sub_519EB0_net_mapsend();
	sub_4DAC00();
	for (k = sub_4DA7C0(); k; k = sub_4DA7F0(k)) {
		sub_4EF660(k);
		sub_4F7AB0(&v61, k);
		if (nox_common_gameFlags_check_40A5C0(128)) {
			if (sub_417DD0()) {
				if (!sub_417DA0(2) && !nox_common_gameFlags_check_40A5C0(0x8000)) {
					v17 = sub_418AB0(*(unsigned __int8*)(k + 52));
					if (v17)
						sub_4ED970(50.0, (float2*)(*((_DWORD*)v17 + 18) + 56), &v61);
				}
			}
		}
		sub_4E7010(k, &v61);
		if (!nox_common_gameFlags_check_40A5C0(512)) {
			v18 = *(_DWORD*)(k + 748);
			*(_DWORD*)(*(_DWORD*)(v18 + 276) + 2136) = 0;
			*(_DWORD*)(*(_DWORD*)(v18 + 276) + 2140) = 0;
			*(_DWORD*)(*(_DWORD*)(v18 + 276) + 2144) = *(_DWORD*)&byte_5D4594[2598000];
			sub_4D8EF0(k);
		}
	}
	sub_50AFA0();
	sub_50B520();
	v19 = 0;
	v20 = 0;
	v21 = 0;
	*(_DWORD*)&byte_5D4594[1548528] = 0;
	*(_DWORD*)&byte_5D4594[1548532] = 0;
	if (!*(_DWORD*)&byte_5D4594[1548708])
		*(_DWORD*)&byte_5D4594[1548708] = sub_4E3AA0((CHAR*)&byte_587000[196512]);
	if (!*(_DWORD*)&byte_5D4594[1548712])
		*(_DWORD*)&byte_5D4594[1548712] = sub_4E3AA0((CHAR*)&byte_587000[196524]);
	v22 = sub_4DA790();
	if (!v22)
		goto LABEL_120;
	do {
		if (*(_DWORD*)(v22 + 8) & 0x10000000) {
			*(_DWORD*)(v22 + 136) = 0;
			*(_DWORD*)&byte_5D4594[1548532] = v22;
			++v19;
		}
		v23 = *(unsigned __int16*)(v22 + 4);
		if ((unsigned __int16)v23 == *(_DWORD*)&byte_5D4594[1548712])
			++v21;
		if (v23 == *(_DWORD*)&byte_5D4594[1548708])
			++v20;
		v22 = sub_4DA7A0(v22);
	} while (v22);
	if (!v20) {
	LABEL_120:
		v24 = loadString_sub_40F1D0((char*)&byte_587000[196580], 0,
					    "C:\\NoxPost\\src\\Server\\System\\server.c", 792);
	LABEL_61:
		sub_4D9FD0(0, v24);
		return 0;
	}
	if (nox_common_gameFlags_check_40A5C0(96) && v19 < 2) {
		v24 = loadString_sub_40F1D0((char*)&byte_587000[196644], 0,
					    "C:\\NoxPost\\src\\Server\\System\\server.c", 799);
		goto LABEL_61;
	}
	if (nox_common_gameFlags_check_40A5C0(64) && v21 < 1) {
		v24 = loadString_sub_40F1D0((char*)&byte_587000[196700], 0,
					    "C:\\NoxPost\\src\\Server\\System\\server.c", 806);
		goto LABEL_61;
	}
	if (sub_417DA0(4) || nox_common_gameFlags_check_40A5C0(0x8000))
		sub_417D00();
	for (l = sub_57C3E0(); l; l = sub_57C3F0(l)) {
		if (!strcmp((const char*)l, "spring")) {
			v27 = strtok((char*)(l + 80), " ");
			v28 = atoi(v27);
			v29 = sub_4ED020(v28);
			v30 = strtok(0, " ");
			v31 = atoi(v30);
			v32 = sub_4ED020(v31);
			if (v29 && v32)
				sub_511590(v29, v32);
		} else if (!strcmp((const char*)l, "SentryGlobe")) {
			v33 = strtok((char*)(l + 80), " ");
			v34 = atoi(v33);
			v35 = sub_4ED020(v34);
			if (v35) {
				v36 = *(float**)(v35 + 748);
				v37 = strtok(0, " ");
				v38 = atof(v37) * *(double*)&byte_581450[10008];
				v36[1] = v38;
				*v36 = v38;
				v39 = strtok(0, " ");
				v40 = atof(v39);
				v62 = *(unsigned int*)&byte_5D4594[2649704];
				v36[2] =
				    v40 * *(double*)&byte_581450[10000] / (double)*(unsigned int*)&byte_5D4594[2649704];
			}
		}
	}
	*(_DWORD*)&byte_5D4594[1548524] = 0;
	v41 = sub_409B40();
	sub_500510(v41);
	if (!sub_4DB240())
		sub_4FC570(1);
	sub_40A4D0(0x8000000);
	sub_43F140(500);
	v42 = sub_4DB240();
	sub_4DBA30(v42);
	sub_43F1A0();
	nox_common_gameFlags_unset_40A540(0x8000000);
	sub_4FC580(1);
	if (dword_5d4594_1548664) {
		v43 = sub_579E30((const char*)&byte_5D4594[1548536]);
		if (v43) {
			v44 = sub_4DA7C0();
			if (v44) {
				v45 = (float2*)(v43 + 8);
				do {
					sub_4E7010(v44, v45);
					v44 = sub_4DA7F0(v44);
				} while (v44);
			}
		}
	}
	dword_5d4594_1548664 = 0;
	if (sub_4DCC00() == 1) {
		for (m = sub_4DA7C0(); m; m = sub_4DA7F0(m)) {
			for (n = *(_DWORD*)(m + 516); n; n = *(_DWORD*)(n + 512)) {
				if (sub_4E5B50(n)) {
					v48 = *(_DWORD*)(n + 748);
					sub_4ED970(50.0, (float2*)(m + 56), &v61);
					sub_4E7010(n, &v61);
					*(_DWORD*)(v48 + 388) = 0;
					sub_50A3A0(n);
					*(_DWORD*)(n + 520) = 0;
					*(_DWORD*)(v48 + 1196) = 0;
					*(_DWORD*)(v48 + 1216) = 0;
					*(_BYTE*)(v48 + 1129) = 0;
					*(_DWORD*)v48 = -559023410;
					v49 = sub_50A260(n, 3);
					if (v49) {
						v49[1] = *(_DWORD*)(m + 56);
						v49[2] = *(_DWORD*)(m + 60);
						v49[3] = m;
					}
					if (*(_BYTE*)(n + 8) & 2 && *(_BYTE*)(n + 12) & 0x30)
						sub_4E4A90(n, 0, *(_DWORD*)(n + 748) + 2076);
				} else if (*(_BYTE*)(m + 8) & 1 && sub_4E5B80(m)) {
					sub_4E81D0(m);
				}
			}
		}
		sub_4DCBF0(0);
	}
	for (ii = sub_4DA790(); ii; ii = sub_4DA7A0(ii))
		*(_DWORD*)(ii + 16) &= 0x7FFFFFFFu;
	for (jj = sub_4DA840(); jj; jj = sub_4DA850(jj))
		*(_DWORD*)(jj + 16) &= 0x7FFFFFFFu;
	if (nox_common_gameFlags_check_40A5C0(16) && sub_417DA0(4))
		sub_4D2160();
	if (nox_common_gameFlags_check_40A5C0(4096)) {
		sub_51A930();
		v52 = nox_common_randomInt_415FA0(0, 2);
		sub_51A920(v52);
		v53 = sub_4E3CC0();
		sub_4E3CD0(v53 + 1);
		v54 = sub_51A930();
		sub_51A1F0(v54);
		sub_4E3D50();
		sub_4E3DD0();
		sub_4F1F20();
		v55 = nox_server_currentMapGetFilename_409B30();
		sub_4D10F0(v55);
		sub_4D7520(1);
		v56 = (__int64)sub_419D40(&byte_587000[196800]);
		if (sub_4E3CC0() >= v56)
			sub_4D7520(0);
	}
	if (nox_common_gameFlags_check_40A5C0(2048) && !sub_4DCC80()) {
		sub_4DB130("AUTOSAVE");
		sub_4DB170(1, 0, 30);
	}
	sub_4DCC70(0);
	if (nox_common_gameFlags_check_40A5C0(2048))
		sub_413980(30);
	if (nox_common_gameFlags_check_40A5C0(4096))
		sub_4D7140(*(_DWORD*)&byte_5D4594[2598000] + *(_DWORD*)&byte_5D4594[2649704]);
	else
		sub_4D7140(0);
	sub_416D40();
	sub_40A970();
	dword_5d4594_1548704 = 0;
	if (nox_common_gameFlags_check_40A5C0(4096)) {
		sub_4D71E0(0);
		if (sub_4D72C0() == 1) {
			sub_4D72B0(0);
			v57 = sub_4D72C0();
			sub_4D7280(255, v57);
		}
	}
	sub_413850();
	return 1;
}
// 4D1A17: variable 'v11' is possibly undefined
// 4D1CBA: variable 'v25' is possibly undefined

//----- (004D2580) --------------------------------------------------------
int sub_4D2580_server() {
	__int64 v0;           // rax
	unsigned int v1;      // edi
	int v2;               // ebx
	unsigned int v3;      // ebp
	unsigned int v4;      // esi
	_DWORD* i;            // esi
	char* v7;             // ebp
	char* v8;             // edi
	unsigned __int8 v9;   // dl
	char* v10;            // edi
	char* v11;            // esi
	char* v12;            // eax
	int v13;              // esi
	wchar_t* v14;         // eax
	wchar_t* v15;         // eax
	char* v17;            // eax
	int v18;              // eax
	char* v20;            // eax
	char* v21;            // esi
	int v22;              // ebx
	int v23;              // ebp
	int v24;              // edi
	int v25;              // esi
	unsigned __int8* v26; // eax
	wchar_t* v27;         // eax
	int v28;              // eax
	int v29;              // esi
	char* v30;            // ebp
	const char* v31;      // edi
	char* v33;            // eax
	int v34;              // eax
	wchar_t* v35;         // [esp-10h] [ebp-50h]
	wchar_t* v36;         // [esp-8h] [ebp-48h]
	char* v37;            // [esp-4h] [ebp-44h]
	char v38[16];         // [esp+10h] [ebp-30h]
	char v39[32];         // [esp+20h] [ebp-20h]

	v0 = sub_416BB0();
	v1 = v0;
	v2 = 0;
	v3 = HIDWORD(v0);
	if (!dword_5d4594_2650652)
		goto LABEL_115;
	v4 = sub_40A6C0();
	if (sub_416650() && sub_41E2F0() == 8)
		v2 = 1;
	if (v4 == 1 || nox_common_gameFlags_check_40A5C0(8) || *(_DWORD*)&byte_5D4594[2598000] % v4 == 1)
	LABEL_115:
		sub_40EE90(1);
	sub_502100();
	sub_5524C0();
	sub_552460();
	if (*(_DWORD*)&nox_common_engineFlags & 0x400000)
		sub_4D3580_net_playback(1);
	if (*(_DWORD*)&nox_common_engineFlags & 0x20000000) {
		*(_DWORD*)&v38[4] = (__PAIR64__(v3, v1) - *(_QWORD*)&byte_5D4594[1548684]) >> 32;
		if (__PAIR64__(v3, v1) - *(_QWORD*)&byte_5D4594[1548684] > 0x3E8) {
			sub_4D3130();
			*(_DWORD*)&byte_5D4594[1548684] = v1;
			*(_DWORD*)&byte_5D4594[1548688] = v3;
		}
	}
	if (!nox_common_gameFlags_check_40A5C0(2048))
		sub_578FC0();
	if (nox_common_gameFlags_check_40A5C0(8)) {
		if (!*(_QWORD*)&byte_5D4594[1548676]) {
			*(_QWORD*)&byte_5D4594[1548676] = sub_416BB0() + 10000;
			sub_4597E0(0);
			if (sub_43AF70() == 1) {
				if (!nox_common_gameFlags_check_40A5C0(128)) {
					sub_4263C0();
					sub_40DF90();
					sub_4264D0();
				}
				if (!sub_4165B0()[57])
					sub_41D650();
			}
			sub_413D30((char*)&byte_587000[196872]);
			sub_46DCB0();
		}
		sub_4DEB30();
		sub_4DEB50();
		if ((unsigned __int64)sub_416BB0() > *(_QWORD*)&byte_5D4594[1548676] && !v2) {
			*(_DWORD*)&byte_5D4594[1548676] = 0;
			*(_DWORD*)&byte_5D4594[1548680] = 0;
			*(_DWORD*)&byte_5D4594[1548524] = 1;
			sub_416170(12);
			nox_common_gameFlags_unset_40A540(8);
			for (i = (_DWORD*)sub_4DA7C0(); i; i = (_DWORD*)sub_4DA7F0((int)i)) {
				sub_4EDA40(i);
				sub_4EF7D0((int)i, 1, 0);
			}
			sub_4DAC00();
			if (!nox_common_gameFlags_check_40A5C0(512)) {
				v7 = sub_416590(0);
				if (v7[57]) {
					v38[0] = 0;
					*(_DWORD*)&v38[1] = 0;
					*(_DWORD*)&v38[5] = 0;
					*(_DWORD*)&v38[9] = 0;
					v8 = sub_409B80();
					v9 = byte_587000[196884];
					strcpy(v38, v8);
					v10 = &v38[strlen(v38)];
					*(_DWORD*)v10 = *(_DWORD*)&byte_587000[196880];
					v10[4] = v9;
					sub_409D70(v38);
					v7[57] = 0;
				} else if (sub_4D0D70()) {
					sub_4D0A30();
					v11 = sub_4D0CF0();
					if (v11) {
						v12 = nox_server_currentMapGetFilename_409B30();
						if (!_strcmpi(v11, v12))
							v11 = sub_4D0CF0();
						if (v11)
							sub_409D70(v11);
					}
				}
			}
		}
		goto LABEL_72;
	}
	if (*(_DWORD*)&byte_5D4594[1548524]) {
		if (!sub_43AF70() || !v2) {
			sub_4EDD70();
			sub_417160();
			sub_4573B0();
			if (sub_417DA0(2) && !nox_common_gameFlags_check_40A5C0(49152) && sub_417DA0(4) &&
			    !nox_common_gameFlags_check_40A5C0(128))
				sub_4181F0(1);
			if (nox_common_gameFlags_check_40A5C0(4096) && sub_43AF70() == 1 &&
			    !nox_common_gameFlags_check_40A5C0(128))
				sub_4264D0();
			sub_40A4D0(0x8000000);
			sub_43F140(500);
			v13 = sub_4D1860_server();
			sub_43F1A0();
			nox_common_gameFlags_unset_40A540(0x8000000);
			if (!v13) {
				v37 = sub_409B40();
				v14 = loadString_sub_40F1D0((char*)&byte_587000[196928], 0,
							    "C:\\NoxPost\\src\\Server\\System\\server.c", 1702);
				sub_4D9FD0(0, v14, v37);
				v36 = loadString_sub_40F1D0((char*)&byte_587000[196984], 0,
							    "C:\\NoxPost\\src\\Server\\System\\server.c", 1703);
				v15 = loadString_sub_40F1D0((char*)&byte_587000[197032], 0,
							    "C:\\NoxPost\\src\\Server\\System\\server.c", 1703);
				nullsub_4(0, v15, v36, 1);
				sub_43DDD0(0);
				return 0;
			}
			v17 = sub_409B40();
			nox_sprintf(v39, "%s.map", v17);
			v18 = sub_409B00();
			sub_4DEE00(v39, v18);
			if (sub_43AF70() == 1) {
				sub_416690();
				if (nox_common_gameFlags_check_40A5C0(128)) {
					if (nox_common_gameFlags_check_40A5C0(0x8000))
						sub_419030(1);
					nox_common_gameFlags_unset_40A540(49152);
					sub_4597E0(0);
					goto LABEL_72;
				}
				sub_426060();
				sub_41D6C0();
				sub_4160D0(15);
			}
			sub_4597E0(0);
		}
	LABEL_72:
		if (*(_DWORD*)&nox_common_engineFlags & 0x600000)
			sub_4E76C0();
		if (sub_4DB1B0()) {
			v20 = sub_417090(31);
			v21 = v20;
			if (v20) {
				if (*((_DWORD*)v20 + 514) && sub_4DCC10(*((_DWORD*)v20 + 514)) == 1) {
					v22 = *((_DWORD*)v21 + 514);
					v23 = 0;
					v24 = (*(_DWORD*)(v22 + 16) >> 15) & 1;
					if (!v24) {
						if (dword_5d4594_1599640 > 0) {
							v25 = 0;
							do {
								if (!strncmp(
									"MapShutdown",
									*(const char**)(v25 + dword_5d4594_1599636),
									0xBu))
									nox_server_doMapScript_507310(v23, 0, 0);
								++v23;
								v25 += 48;
							} while (v23 < *(int*)&dword_5d4594_1599640);
						}
						sub_40A4D0(0x8000000);
						v26 = sub_4DB160();
						v23 = sub_4DB370_savegame((const char*)v26);
						nox_common_gameFlags_unset_40A540(0x8000000);
						if (!v23 && nox_common_gameFlags_check_40A5C0(2)) {
							v35 = loadString_sub_40F1D0(
							    (char*)&byte_587000[197104], 0,
							    "C:\\NoxPost\\src\\Server\\System\\server.c", 1931);
							v27 = loadString_sub_40F1D0(
							    (char*)&byte_587000[197172], 0,
							    "C:\\NoxPost\\src\\Server\\System\\server.c", 1930);
							sub_449A10(0, (int)v27, (int)v35, 33, 0, 0);
						}
					}
					v28 = sub_4DB1C0();
					v29 = v28;
					if (v24 || v23 != 1) {
						if (v28 && !v23)
							sub_4E7010(v22, (float2*)(*(_DWORD*)(v28 + 700) + 80));
					} else if (v28) {
						v30 = *(char**)(v28 + 700);
						v31 = (const char*)sub_4DB2A0(*(const char**)(v28 + 700));
						if (v31) {
							sub_4DB220(1);
							sub_4DB230(1);
							sub_4DB270(v31);
						}
						sub_4D2450(v30);
					}
					sub_4DB170(0, v29, 0);
				}
			}
		}
		sub_4139C0();
		if (sub_446180())
			sub_446190();
		if (sub_446030() && *(_DWORD*)&byte_5D4594[2598000] >
					(unsigned int)(5 * *(_DWORD*)&byte_5D4594[2649704] + sub_446040())) {
			sub_446380();
		}
		if (!sub_413A50())
			++*(_DWORD*)&byte_5D4594[2598000];
		sub_56F5C0();
		sub_4FC6D0();
		sub_4FC590();
		sub_4FC600();
		sub_4FC680();
		v33 = sub_417090(31);
		if (v33) {
			v34 = *((_DWORD*)v33 + 514);
			if (v34)
				sub_5003B0(v34);
		}
		if (sub_57AF20() && sub_57B140())
			sub_57B0A0();
		if (sub_4D6F50()) {
			nox_server_switchQuestIfRequested_4D6FD0();
			sub_4DCF20();
		}
		return 1;
	}
	sub_4D2DA0(__SPAIR64__(v3, v1));
	sub_4DEB30();
	sub_4DEB50();
	if (!sub_43DEA0()) {
		if (!(byte_5D4594[2598000] & 1))
			sub_519990();
		sub_40B970();
		sub_40B790();
		if (!sub_413A50()) {
			sub_51B100();
			sub_4EC720();
			if (nox_common_gameFlags_check_40A5C0(4096)) {
				sub_50D890();
				sub_4E4170();
			}
			sub_4FCB70();
			sub_4FBEE0();
			sub_51ADF0();
			sub_506F30();
			sub_4E5E20();
		}
		sub_4DEC80();
		sub_4DAC00();
		if (sub_4160F0(0x10u, 10 * *(_DWORD*)&byte_5D4594[2649704])) {
			sub_4E3C20();
			sub_4160D0(16);
		}
		if (nox_common_gameFlags_check_40A5C0(0x2000) && sub_43AF70() == 1 &&
		    !nox_common_gameFlags_check_40A5C0(128) && sub_4160F0(0xFu, 60 * *(_DWORD*)&byte_5D4594[2649704])) {
			sub_4263C0();
			sub_4160D0(15);
		}
		goto LABEL_72;
	}
	return 1;
}
// 4D26F3: variable 'v5' is possibly undefined
// 4D2A52: variable 'v19' is possibly undefined
// 4D2CEB: variable 'v32' is possibly undefined
// 4514E0: using guessed type void __cdecl nullsub_4(_DWORD, _DWORD, _DWORD, _DWORD);
// 46DCB0: using guessed type int sub_46DCB0(void);
