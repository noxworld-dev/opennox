#include "client/drawable/drawable.h"
#include "client/gui/chaticon.h"
#include "client/gui/guiobs.h"
#include "client/shell/wolapi/wollogin.h"
#include "client/shell/wolapi/wolreg.h"
#include "common/object/modifier.h"

#include "client/gui/gamewin/gamewin.h"
#include "client/gui/gui_ctf.h"
#include "client/gui/guiinput.h"
#include "client/gui/guiinv.h"
#include "client/gui/guijourn.h"
#include "client/gui/guimeter.h"
#include "client/gui/guiquit.h"
#include "client/gui/guirank.h"
#include "client/gui/guisave.h"
#include "client/gui/guispell.h"
#include "client/gui/guisumn.h"
#include "client/gui/guitrade.h"
#include "client/gui/tooltip.h"
#include "common/wolapi/wolpatch.h"

#include "client/draw/drawwin.h"
#include "client/draw/selectdw.h"

#include "proto.h"

extern _DWORD dword_587000_80820;
extern _DWORD dword_5d4594_1049800;
extern _DWORD dword_5d4594_1064296;
extern _DWORD dword_5d4594_1064888;
extern _DWORD dword_587000_149232;
extern _DWORD dword_5d4594_2650672;
extern _DWORD dword_5d4594_1062456;
extern _DWORD dword_5d4594_1063636;
extern _DWORD dword_5d4594_815132;
extern _DWORD dword_5d4594_1049796;
extern _DWORD dword_5d4594_1049508;
extern _DWORD dword_5d4594_1090048;
extern _DWORD dword_5d4594_1049500;
extern _DWORD dword_5d4594_1062512;
extern _DWORD dword_5d4594_1049864;
extern _DWORD dword_5d4594_1062508;
extern _DWORD dword_5d4594_1064816;
extern _DWORD dword_5d4594_1064192;
extern _DWORD dword_5d4594_3799624;
extern _DWORD dword_5d4594_1082856;
extern _DWORD dword_5d4594_1049504;
extern _DWORD dword_5d4594_1090120;
extern _DWORD dword_5d4594_1063116;
extern _DWORD dword_5d4594_3801780;
extern _DWORD dword_5d4594_1064916;
extern _DWORD dword_587000_80828;
extern _DWORD dword_5d4594_1062480;
extern _DWORD dword_587000_133480;
extern _DWORD dword_5d4594_3798784;
extern int nox_win_width;
extern int nox_win_height;
extern int nox_backbuffer_width;
extern int nox_backbuffer_height;

nox_alloc_class* nox_alloc_window = 0;

nox_window* nox_win_unk2 = 0;
nox_window* nox_win_unk3 = 0;
nox_window* nox_win_unk4 = 0;
nox_window* nox_win_unk5 = 0;
nox_window* nox_win_cur_weapon = 0;

const nox_drawable_lists_cap = 512;

nox_drawable** nox_drawable_list_2 = 0;
int nox_drawable_list_2_size = 0;

nox_drawable** nox_drawable_list_3 = 0;
int nox_drawable_list_3_size = 0;

nox_drawable** nox_drawable_list_4 = 0;
int nox_drawable_list_4_size = 0;

const nox_drawable_list_1_cap = 8192;
nox_drawable** nox_drawable_list_1 = 0;
int nox_drawable_list_1_size = 0;

obj_5D4594_2650668_t** ptr_5D4594_2650668 = 0;
const int ptr_5D4594_2650668_cap = 128;

//----- (00460D40) --------------------------------------------------------
BOOL sub_460D40() { return dword_5d4594_1049508 != 0; }

//----- (00460D50) --------------------------------------------------------
int sub_460D50() {
	unsigned __int8* v0; // edi
	_DWORD** v1;         // esi
	int v2;              // ebx
	unsigned __int8* v3; // esi
	int result;          // eax

	sub_46C4E0(*(_DWORD**)&dword_5d4594_1049500);
	dword_5d4594_1049500 = 0;
	sub_46C4E0(*(_DWORD**)&dword_5d4594_1049504);
	dword_5d4594_1049504 = 0;
	sub_46C4E0(*(_DWORD**)&byte_5D4594[1049520]);
	*(_DWORD*)&byte_5D4594[1049520] = 0;
	sub_46C4E0(*(_DWORD**)&dword_5d4594_1049508);
	dword_5d4594_1049508 = 0;
	sub_46C4E0(*(_DWORD**)&byte_5D4594[1049512]);
	*(_DWORD*)&byte_5D4594[1049512] = 0;
	sub_46C4E0(*(_DWORD**)&byte_5D4594[1049516]);
	*(_DWORD*)&byte_5D4594[1049516] = 0;
	v0 = &byte_5D4594[1048404];
	do {
		sub_46C4E0(*(_DWORD**)v0);
		*(_DWORD*)v0 = 0;
		v1 = (_DWORD**)(v0 + 24);
		v2 = 5;
		do {
			sub_46C4E0(*(v1 - 5));
			*(v1 - 5) = 0;
			sub_46C4E0(*v1);
			*v1 = 0;
			++v1;
			--v2;
		} while (v2);
		v0 += 256;
	} while ((int)v0 < (int)&byte_5D4594[1049684]);
	sub_46C4E0(*(_DWORD**)&byte_5D4594[1048148]);
	*(_DWORD*)&byte_5D4594[1048148] = 0;
	v3 = &byte_5D4594[1048152];
	do {
		result = sub_46C4E0(*(_DWORD**)v3);
		*(_DWORD*)v3 = 0;
		v3 += 4;
	} while ((int)v3 < (int)&byte_5D4594[1048164]);
	*(_DWORD*)&byte_5D4594[1049532] = 0;
	*(_DWORD*)&byte_5D4594[1047928] = 0;
	*(_DWORD*)&byte_5D4594[1047932] = 0;
	return result;
}

//----- (00460E60) --------------------------------------------------------
int sub_460E60() {
	int result; // eax

	if (sub_460D40())
		sub_460D50();
	result = sub_45E190();
	if (result) {
		sub_460EA0(*(int*)&dword_587000_80828);
		result = 1;
	}
	return result;
}

//----- (00460E90) --------------------------------------------------------
int sub_460E90() {
	int result; // eax

	result = sub_460D40();
	if (result == 1)
		result = sub_460D50();
	return result;
}

//----- (00460EA0) --------------------------------------------------------
int __cdecl sub_460EA0(int a1) { return sub_460B90(a1); }

//----- (00460EB0) --------------------------------------------------------
char __cdecl sub_460EB0(int a1, char a2) {
	char result; // al

	result = a2;
	byte_5D4594[a1 + 1049544] = a2;
	return result;
}

//----- (00461010) --------------------------------------------------------
_DWORD* sub_461010() {
	_DWORD* result; // eax

	result = *(_DWORD**)&byte_5D4594[1049484];
	if (*(_DWORD*)&byte_5D4594[1049484]) {
		nox_window_set_hidden(*(int*)&byte_5D4594[1048148], 1);
		nox_window_set_hidden(*(int*)&byte_5D4594[1049512], 0);
		sub_46AE10(*(int*)&dword_5d4594_1049500, 0);
		result = sub_452D80(797, 100);
		*(_DWORD*)&byte_5D4594[1049484] = 0;
	}
	return result;
}

//----- (00461060) --------------------------------------------------------
_DWORD* sub_461060() {
	_DWORD* result; // eax

	if (*(_DWORD*)&byte_5D4594[1049484] == 1)
		return sub_461010();
	if (*(_DWORD*)&byte_5D4594[1049476] == 1)
		sub_4606B0();
	nox_window_set_hidden(*(int*)&byte_5D4594[1048148], 0);
	nox_window_set_hidden(*(int*)&byte_5D4594[1049512], 1);
	sub_46AE10(*(int*)&dword_5d4594_1049500, 1);
	result = sub_452D80(796, 100);
	*(_DWORD*)&byte_5D4594[1049484] = 1;
	return result;
}

//----- (00461080) --------------------------------------------------------
int sub_461080() { return *(_DWORD*)&byte_5D4594[1049484]; }

//----- (00461090) --------------------------------------------------------
char* __cdecl sub_461090(int a1, int a2) {
	int v2;       // edx
	char* result; // eax

	v2 = *(_DWORD*)&byte_5D4594[2598000];
	result = (char*)&byte_5D4594[1047808];
	do {
		if (*((_DWORD*)result - 5) == a1) {
			*(_DWORD*)result = a2 == 0 ? v2 : 0;
			*((_DWORD*)result - 3) = a2;
		}
		result += 24;
	} while ((int)result < (int)&byte_5D4594[1047928]);
	return result;
}

//----- (004610D0) --------------------------------------------------------
char* __cdecl sub_4610D0(unsigned __int8 a1) {
	int* v1;      // esi
	char* result; // eax

	if (a1 != 6)
		return sub_461090(*(_DWORD*)&byte_5D4594[24 * a1 + 1047764], 1);
	v1 = (int*)&byte_5D4594[1047788];
	do {
		result = sub_461090(*v1, 1);
		v1 += 6;
	} while ((int)v1 < (int)&byte_5D4594[1047908]);
	return result;
}

//----- (00461120) --------------------------------------------------------
char* __cdecl sub_461120(int a1, int a2) {
	int v2;       // edx
	char* result; // eax

	v2 = 1 << a1;
	result = (char*)&byte_5D4594[1047800];
	do {
		if (*((_DWORD*)result - 3) == a1) {
			if (a2)
				*(_DWORD*)result |= v2;
			else
				*(_DWORD*)result &= ~v2;
		}
		result += 24;
	} while ((int)result < (int)&byte_5D4594[1047920]);
	return result;
}

//----- (00461160) --------------------------------------------------------
BOOL __cdecl sub_461160(int a1) {
	int v1;              // edx
	unsigned __int8* v2; // eax

	v1 = 1;
	v2 = &byte_5D4594[1047788];
	while (*(_DWORD*)v2 != a1) {
		v2 += 24;
		++v1;
		if ((int)v2 >= (int)&byte_5D4594[1047908])
			return 0;
	}
	return ((1 << a1) & *(_DWORD*)&byte_5D4594[24 * v1 + 1047776]) != 0;
}

//----- (004611A0) --------------------------------------------------------
int sub_4611A0() { return *(_DWORD*)&byte_5D4594[1047932]; }

//----- (004611B0) --------------------------------------------------------
int sub_4611B0() {
	int result; // eax

	result = *(_DWORD*)&byte_5D4594[1047936];
	if (*(_DWORD*)&byte_5D4594[1047936]) {
		result = sub_45DAF0(*(int*)&byte_5D4594[1047936]);
		*(_DWORD*)&byte_5D4594[1047936] = 0;
		*(_DWORD*)&byte_5D4594[1047932] = 0;
	}
	return result;
}

//----- (004611E0) --------------------------------------------------------
void __cdecl sub_4611E0(int a1, int a2, char* a3) {
	unsigned __int8* v3; // esi

	if (a1 >= 1 && a1 < 6) {
		v3 = &byte_5D4594[1047804];
		do {
			if (*((_DWORD*)v3 - 4) == a1 && *(_DWORD*)v3 != a2) {
				if (nox_common_gameFlags_check_40A5C0(2) && *(_DWORD*)&byte_5D4594[2618908])
					*(_DWORD*)(*(_DWORD*)&byte_5D4594[2618908] + 4 * a1 + 3696) = a2;
				*(_DWORD*)v3 = a2;
				if (a2)
					sub_45D290(a1, a3, (int)a3);
			}
			v3 += 24;
		} while ((int)v3 < (int)&byte_5D4594[1047924]);
	}
}

//----- (00461250) --------------------------------------------------------
int sub_461250() {
	int v0;     // ecx
	int v1;     // esi
	_DWORD* v2; // eax

	v0 = *(unsigned __int8*)(dword_587000_133480 + 200);
	do {
		v1 = 0;
		v2 = (_DWORD*)(dword_587000_133480 + 40 * v0);
		do {
			if (!*v2) {
				sub_45E110(v0);
				return v1;
			}
			++v1;
			v2 += 2;
		} while (v1 < 5);
		if (++v0 >= 5)
			v0 = 0;
	} while (v0 != *(unsigned __int8*)(dword_587000_133480 + 200));
	return -1;
}

//----- (004612A0) --------------------------------------------------------
int sub_4612A0() {
	int result; // eax
	_DWORD* i;  // ecx

	result = 0;
	for (i = (_DWORD*)(dword_587000_133480 +
			   40 * *(unsigned __int8*)(dword_587000_133480 + 200));
	     *i; i += 2) {
		if (++result >= 5)
			return -1;
	}
	return result;
}

//----- (004612D0) --------------------------------------------------------
int __cdecl sub_4612D0(int a1) {
	int v1;     // edx
	int v2;     // eax
	_DWORD* v3; // ecx

	v1 = *(unsigned __int8*)(dword_587000_133480 + 200);
	do {
		v2 = 0;
		v3 = (_DWORD*)(dword_587000_133480 + 40 * v1);
		do {
			if (*v3 == a1)
				return 1;
			++v2;
			v3 += 2;
		} while (v2 < 5);
		if (++v1 >= 5)
			v1 = 0;
	} while (v1 != *(unsigned __int8*)(dword_587000_133480 + 200));
	return 0;
}

//----- (00461320) --------------------------------------------------------
void __cdecl sub_461320(int a1, _DWORD* a2) {
	if (a2) {
		if (a1 >= 0 && a1 < 5)
			nox_client_wndGetPosition_46AA60(*(_DWORD**)(dword_587000_133480 + 4 * a1 + 212), a2, a2 + 1);
	}
}

//----- (00461360) --------------------------------------------------------
int __cdecl sub_461360(int a1) {
	int v1;     // edx
	int v2;     // ecx
	int v3;     // ebx
	int v4;     // esi
	int result; // eax

	v1 = dword_587000_133480;
	v2 = *(unsigned __int8*)(dword_587000_133480 + 200);
	v3 = *(unsigned __int8*)(dword_587000_133480 + 200);
	do {
		v4 = 5;
		result = 40 * v2;
		do {
			if (*(_DWORD*)(result + v1) == a1) {
				*(_DWORD*)(result + v1) = 0;
				v1 = dword_587000_133480;
			}
			result += 8;
			--v4;
		} while (v4);
		if (++v2 >= 5)
			v2 = 0;
	} while (v2 != v3);
	return result;
}

//----- (004613B0) --------------------------------------------------------
int sub_4613B0() {
	int v0;     // ebp
	int v1;     // edx
	int v2;     // eax
	int v3;     // edi
	int result; // eax
	int v5;     // [esp+10h] [ebp-4h]

	v0 = dword_587000_133480;
	v1 = dword_587000_133480;
	v5 = 5;
	do {
		v2 = v1;
		v3 = 5;
		do {
			*(_DWORD*)&byte_5D4594[v2 + 1047564 - v0] = *(_DWORD*)v2;
			byte_5D4594[v2 + 1047568 - v0] = *(_BYTE*)(v2 + 4);
			v2 += 40;
			--v3;
		} while (v3);
		v1 += 8;
		result = --v5;
	} while (v5);
	return result;
}

//----- (00461400) --------------------------------------------------------
int sub_461400() {
	int i;      // esi
	int result; // eax
	int v2;     // ecx

	for (i = 0; i < 40; i += 8) {
		result = i;
		v2 = 5;
		do {
			*(_DWORD*)(result + dword_587000_133480) = *(_DWORD*)&byte_5D4594[result + 1047564];
			*(_BYTE*)(result + dword_587000_133480 + 4) = byte_5D4594[result + 1047568];
			result += 40;
			--v2;
		} while (v2);
	}
	return result;
}

//----- (00461440) --------------------------------------------------------
int __cdecl sub_461440(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[1049688] = a1;
	return result;
}

//----- (00461450) --------------------------------------------------------
int sub_461450() { return *(_DWORD*)&byte_5D4594[1049688]; }

//----- (00461460) --------------------------------------------------------
int __cdecl sub_461460(int a1) {
	int v1;     // eax
	char v2;    // cl
	char v3;    // dl
	int v4;     // eax
	char v5;    // cl
	char v6;    // dl
	int v7;     // eax
	char v8;    // cl
	char v9;    // dl
	int v10;    // eax
	char v11;   // cl
	char v12;   // dl
	int result; // eax

	v1 = sub_4344A0(*(_BYTE*)(a1 + 2253), *(_BYTE*)(a1 + 2254), *(_BYTE*)(a1 + 2255));
	v2 = *(_BYTE*)(a1 + 2257);
	v3 = *(_BYTE*)(a1 + 2256);
	*(_DWORD*)(a1 + 2296) = v1;
	v4 = sub_4344A0(v3, v2, *(_BYTE*)(a1 + 2258));
	v5 = *(_BYTE*)(a1 + 2260);
	v6 = *(_BYTE*)(a1 + 2259);
	*(_DWORD*)(a1 + 2292) = v4;
	v7 = sub_4344A0(v6, v5, *(_BYTE*)(a1 + 2261));
	v8 = *(_BYTE*)(a1 + 2263);
	v9 = *(_BYTE*)(a1 + 2262);
	*(_DWORD*)(a1 + 2300) = v7;
	v10 = sub_4344A0(v9, v8, *(_BYTE*)(a1 + 2264));
	v11 = *(_BYTE*)(a1 + 2266);
	v12 = *(_BYTE*)(a1 + 2265);
	*(_DWORD*)(a1 + 2304) = v10;
	*(_DWORD*)(a1 + 2308) = sub_4344A0(v12, v11, *(_BYTE*)(a1 + 2267));
	result = *(_DWORD*)&byte_5D4594[2523948];
	*(_DWORD*)(a1 + 2312) = *(_DWORD*)&byte_5D4594[2523948];
	return result;
}

//----- (00461520) --------------------------------------------------------
char* sub_461520() {
	char* result; // eax
	int i;        // esi

	result = sub_416EA0();
	for (i = (int)result; result; i = (int)result) {
		sub_461460(i);
		result = sub_416EE0(i);
	}
	return result;
}

//----- (00461550) --------------------------------------------------------
int __cdecl sub_461550(int a1) {
	if (dword_5d4594_1062480)
		*(_DWORD*)&byte_5D4594[1062484] = *(_DWORD*)(dword_5d4594_1062480 + 4);
	else
		*(_DWORD*)&byte_5D4594[1062484] = 0;
	dword_5d4594_1062480 = a1;
	sub_4619F0();
	if (!dword_5d4594_1062480)
		return sub_4BF010(0);
	*(_DWORD*)(**(_DWORD**)&dword_5d4594_1062480 + 128) = *(_DWORD*)(a1 + 4);
	*(_DWORD*)(dword_5d4594_1062480 + 136) = 1;
	return sub_4BF010(**(_DWORD**)&dword_5d4594_1062480);
}

//----- (004615C0) --------------------------------------------------------
int sub_4615C0() {
	int v0; // eax
	int v1; // ecx

	v0 = *(_DWORD*)&byte_5D4594[1063640];
	if (!*(_DWORD*)&byte_5D4594[1063640]) {
		v0 = sub_44CFC0((CHAR*)&byte_587000[136416]);
		*(_DWORD*)&byte_5D4594[1063640] = v0;
	}
	if (!*(_DWORD*)&byte_5D4594[1049904])
		return *(_DWORD*)&byte_5D4594[1049900];
	v1 = *(_DWORD*)&byte_5D4594[1049904];
	while (*(_DWORD*)(v1 + 108) != v0) {
		v1 = *(_DWORD*)(v1 + 368);
		if (!v1)
			return *(_DWORD*)&byte_5D4594[1049900];
	}
	return *(_DWORD*)&byte_5D4594[1049904];
}

//----- (00461600) --------------------------------------------------------
int __cdecl sub_461600(int a1) {
	int* v1;    // ecx
	int result; // eax

	v1 = (int*)&byte_5D4594[1049872];
	while (1) {
		result = *v1;
		if (*v1)
			break;
	LABEL_5:
		++v1;
		if ((int)v1 >= (int)&byte_5D4594[1049908])
			return 0;
	}
	while (*(_DWORD*)(result + 108) != a1) {
		result = *(_DWORD*)(result + 368);
		if (!result)
			goto LABEL_5;
	}
	return result;
}

//----- (00461630) --------------------------------------------------------
int __cdecl sub_461630(__int16 a1) {
	int v1;     // ecx
	char v3[3]; // [esp+0h] [ebp-4h]
	char v4;    // [esp+3h] [ebp-1h]

	v4 = HIBYTE(v1);
	v3[0] = -15;
	*(_WORD*)&v3[1] = a1;
	return sub_4E53C0(31, v3, 3, 0, 0);
}

//----- (00461930) --------------------------------------------------------
int sub_461930() {
	unsigned __int8* v0; // ecx
	int v1;              // eax

	v0 = &byte_5D4594[1049872];
	while (1) {
		v1 = *(_DWORD*)v0;
		if (*(_DWORD*)v0)
			break;
	LABEL_5:
		v0 += 4;
		if ((int)v0 >= (int)&byte_5D4594[1049908])
			return 0;
	}
	while (!(*(_DWORD*)(v1 + 112) & 0x1001000)) {
		v1 = *(_DWORD*)(v1 + 368);
		if (!v1)
			goto LABEL_5;
	}
	return 1;
}

//----- (00461970) --------------------------------------------------------
int* __cdecl sub_461970(int a1, int a2) {
	int* v2;     // edx
	int v3;      // ecx
	int* result; // eax

	if (!(*(_DWORD*)(nox_get_thing(a2) + 32) & 0x4000000)) {
		v2 = (int*)&byte_5D4594[1050020];
		while (1) {
			v3 = 0;
			result = v2;
			do {
				if (*((_BYTE*)result + 140) && *(_DWORD*)(*result + 108) == a2 &&
				    *((_BYTE*)result + 140) < 0x20u) {
					result[(unsigned __int8)(*((_BYTE*)result + 140))++ + 1] = a1;
					return result;
				}
				++v3;
				result += 777;
			} while (v3 < 4);
			v2 += 37;
			if ((int)v2 < (int)&byte_5D4594[1052980])
				continue;
			break;
		}
	}
	return 0;
}

//----- (004619F0) --------------------------------------------------------
char* sub_4619F0() {
	char* v0;     // edi
	char* result; // eax
	int v2;       // esi
	int v3;       // ecx

	v0 = (char*)&byte_5D4594[1050160];
	do {
		result = v0;
		v2 = 4;
		do {
			v3 = 0;
			if ((unsigned __int8)*result > 0u) {
				do {
					*((_DWORD*)result - 1) = 0;
					++v3;
				} while (v3 < (unsigned __int8)*result);
			}
			result += 3108;
			--v2;
		} while (v2);
		v0 += 148;
	} while ((int)v0 <= (int)&byte_5D4594[1053120]);
	return result;
}

//----- (00461B50) --------------------------------------------------------
unsigned __int8* sub_461B50() {
	int v0;                  // ebx
	unsigned __int8* result; // eax
	int v2;                  // ebp
	int v3;                  // ecx
	int v4;                  // edi
	int v5;                  // esi
	int v6;                  // ebx
	int v7;                  // eax
	unsigned __int8* v8;     // edx
	unsigned __int8* v9;     // eax
	int v10;                 // ecx
	int v11;                 // ecx
	int v12;                 // edx
	int i;                   // eax
	int v14;                 // ebp
	bool v15;                // cc
	int j;                   // esi
	int v17;                 // edx
	int v18;                 // ecx
	int* v19;                // [esp+10h] [ebp-38h]
	unsigned __int8* v20;    // [esp+14h] [ebp-34h]
	int* v21;                // [esp+18h] [ebp-30h]
	int v22;                 // [esp+1Ch] [ebp-2Ch]
	int v23;                 // [esp+20h] [ebp-28h]
	int v24;                 // [esp+24h] [ebp-24h]
	int v25;                 // [esp+28h] [ebp-20h]
	int* v26;                // [esp+2Ch] [ebp-1Ch]
	int v27;                 // [esp+30h] [ebp-18h]
	unsigned __int8* v28;    // [esp+38h] [ebp-10h]
	unsigned __int8* v29;    // [esp+3Ch] [ebp-Ch]
	int v30;                 // [esp+40h] [ebp-8h]

	v0 = 0;
	result = &byte_5D4594[1050156];
	v25 = 0;
	v26 = (int*)&byte_5D4594[1050156];
LABEL_2:
	v2 = 0;
	v24 = 0;
	v21 = (int*)(result - 136);
	v20 = result;
	v19 = (int*)(result + 4);
	while (*(_BYTE*)v19) {
	LABEL_35:
		v24 = ++v2;
		v19 += 777;
		v20 += 3108;
		v21 += 777;
		if (v2 >= 4) {
			result += 148;
			v25 = ++v0;
			v26 = (int*)result;
			if ((int)result >= (int)&byte_5D4594[1053116])
				return result;
			goto LABEL_2;
		}
	}
	v3 = v0;
	v27 = v0;
	if ((int)result < (int)&byte_5D4594[1053116]) {
	LABEL_5:
		if (v3 == v0) {
			v4 = v2;
			v22 = v2;
		} else {
			v4 = 0;
			v22 = 0;
		}
		result = &byte_5D4594[148 * (v3 + 14 * v4 + 7 * v4) + 1050160];
		while (!*result) {
			++v4;
			result += 3108;
			v22 = v4;
			if (v4 >= 4) {
				v27 = ++v3;
				if (v3 >= 20)
					goto LABEL_38;
				goto LABEL_5;
			}
		}
		v5 = 7 * v4 + v3 + 14 * v4;
		v6 = 148 * v5;
		v7 = *(_DWORD*)&byte_5D4594[148 * v5 + 1050020];
		v8 = &byte_5D4594[148 * v5 + 1050020];
		v29 = &byte_5D4594[148 * v5 + 1050020];
		v30 = *(_DWORD*)(v7 + 108);
		if (!(*(_DWORD*)(v7 + 112) & 0x4000000)) {
			v9 = &byte_5D4594[1050160];
			v23 = 0;
			v28 = &byte_5D4594[1050160];
			while (1) {
				v10 = 0;
				while (!*v9 || *v9 == 32 || *(_DWORD*)(*((_DWORD*)v9 - 35) + 108) != v30 ||
				       v10 == v4 && v23 == v27) {
					++v10;
					v9 += 3108;
					if (v10 >= 4)
						goto LABEL_28;
				}
				v11 = 7 * v10 + v23 + 14 * v10;
				v12 = byte_5D4594[148 * v11 + 1050160];
				for (i = byte_5D4594[v6 + 1050160]; i > 0; v6 = 148 * v5) {
					if (v12 == 32)
						break;
					--i;
					v14 = v12++ + v11;
					*(_DWORD*)&byte_5D4594[4 * (v14 + 36 * v11) + 1050024] =
					    *(_DWORD*)&byte_5D4594[4 * (i + v5 + 36 * v5) + 1050024];
					v4 = v22;
				}
				byte_5D4594[148 * v11 + 1050160] = v12;
				if (i <= 0) {
					byte_5D4594[v6 + 1050160] = 0;
					sub_45A4B0(*(_QWORD**)v29);
					v0 = v25;
					*(_DWORD*)v29 = 0;
					v2 = v24 - 1;
					v21 -= 777;
					result = (unsigned __int8*)v26;
					v19 -= 777;
					v20 -= 3108;
					goto LABEL_35;
				}
				byte_5D4594[v6 + 1050160] = i;
			LABEL_28:
				v9 = v28 + 148;
				v15 = (int)(v28 + 148) < (int)&byte_5D4594[1053120];
				++v23;
				v28 += 148;
				if (v15)
					continue;
				break;
			}
			v2 = v24;
			v8 = &byte_5D4594[148 * v5 + 1050020];
		}
		qmemcpy(v21, v8, 0x94u);
		if (*(_DWORD*)v20)
			dword_5d4594_1062480 = v21;
		result = (unsigned __int8*)v26;
		byte_5D4594[v6 + 1050160] = 0;
		*(_DWORD*)v8 = 0;
		*(_DWORD*)&byte_5D4594[v6 + 1050152] = 0;
		v0 = v25;
		goto LABEL_35;
	}
LABEL_38:
	for (j = v0; j < 20; ++j) {
		if (j == v0)
			v17 = v2;
		else
			v17 = 0;
		v18 = 4 - v17;
		result = &byte_5D4594[148 * (j + 14 * v17 + 7 * v17) + 1050156];
		do {
			*((_DWORD*)result - 1) = 0;
			*(_DWORD*)result = 0;
			result += 3108;
			--v18;
		} while (v18);
	}
	return result;
}

//----- (00461E60) --------------------------------------------------------
_QWORD** __cdecl sub_461E60(_QWORD*** a1) {
	_QWORD** v1;     // eax
	int v2;          // edi
	int v3;          // ecx
	_QWORD** result; // eax

	v1 = *a1;
	v2 = (int)a1[1];
	if (v2 < *((unsigned __int8*)*a1 + 140) - 1) {
		v3 = 4 * v2 + 4;
		do {
			++v2;
			*(_QWORD**)((char*)v1 + v3) = *(_QWORD**)((char*)v1 + v3 + 4);
			v1 = *a1;
			v3 += 4;
		} while (v2 < *((unsigned __int8*)*a1 + 140) - 1);
	}
	if (!--*((_BYTE*)*a1 + 140)) {
		sub_45A4B0(**a1);
		**a1 = 0;
	}
	result = (_QWORD**)(*a1)[34];
	if (result) {
		sub_461550(0);
		result = *a1;
		(*a1)[34] = 0;
	}
	return result;
}

//----- (00461EF0) --------------------------------------------------------
char* __cdecl sub_461EF0(int a1) {
	unsigned __int8* v1; // ebx
	int v2;              // edi
	unsigned __int8* v3; // esi
	int v4;              // eax
	int v5;              // edx
	unsigned __int8* v6; // ecx
	char* result;        // eax
	int v8;              // [esp+10h] [ebp-4h]

	v8 = 0;
	v1 = &byte_5D4594[1050160];
	while (1) {
		v2 = 0;
		v3 = v1;
		do {
			v4 = 0;
			v5 = *v3;
			if (v5 > 0) {
				v6 = v3 - 136;
				while (*(_DWORD*)v6 != a1) {
					++v4;
					v6 += 4;
					if (v4 >= v5)
						goto LABEL_7;
				}
				*(_DWORD*)&byte_5D4594[1049792] = v4;
				result = (char*)&byte_5D4594[1049788];
				*(_DWORD*)&byte_5D4594[1049788] = &byte_5D4594[148 * (v8 + 14 * v2 + 7 * v2) + 1050020];
				return result;
			}
		LABEL_7:
			++v2;
			v3 += 3108;
		} while (v2 < 4);
		v1 += 148;
		++v8;
		if ((int)v1 <= (int)&byte_5D4594[1053120])
			continue;
		return 0;
	}
}

//----- (00461F90) --------------------------------------------------------
int __cdecl sub_461F90(int a1) {
	int v1;              // ecx
	unsigned __int8* v2; // eax
	int v3;              // esi
	int v5;              // eax
	int v6;              // eax
	int v7;              // eax

	v1 = 0;
	v2 = &byte_5D4594[1049872];
	while (1) {
		v3 = *(_DWORD*)v2;
		if (*(_DWORD*)v2)
			break;
	LABEL_5:
		v2 += 4;
		++v1;
		if ((int)v2 >= (int)&byte_5D4594[1049908])
			return 0;
	}
	while (*(_DWORD*)(v3 + 128) != a1) {
		v3 = *(_DWORD*)(v3 + 368);
		if (!v3)
			goto LABEL_5;
	}
	v5 = *(_DWORD*)(v3 + 372);
	if (v5)
		*(_DWORD*)(v5 + 368) = *(_DWORD*)(v3 + 368);
	else
		*(_DWORD*)&byte_5D4594[4 * v1 + 1049872] = *(_DWORD*)(v3 + 368);
	v6 = *(_DWORD*)(v3 + 368);
	if (v6)
		*(_DWORD*)(v6 + 372) = *(_DWORD*)(v3 + 372);
	v7 = *(_DWORD*)(v3 + 112);
	if (v7 & 0x1000 || sub_415880(*(char**)(v3 + 108)) == 2 || sub_415880(*(char**)(v3 + 108)) == 128)
		sub_470D70();
	return v3;
}

//----- (004622E0) --------------------------------------------------------
int __cdecl sub_4622E0(int a1) {
	int v1;     // edi
	int result; // eax

	v1 = *(_DWORD*)(a1 + 112);
	if (*(_DWORD*)(a1 + 112) & 0x1000000 && *(_BYTE*)(a1 + 116) & 2)
		return 0;
	if (!(v1 & 0x2000000) || (result = 1, !(*(_BYTE*)(a1 + 116) & 1))) {
		if (v1 & 0x2000000) {
			if (*(_DWORD*)(a1 + 116) & 0x144)
				return 2;
			if (*(_BYTE*)(a1 + 116) & 0x90)
				return 3;
			if (*(_BYTE*)(a1 + 116) & 0x20)
				return 4;
			if (*(_BYTE*)(a1 + 116) & 2)
				return 8;
			if (*(_BYTE*)(a1 + 116) & 8)
				return 5;
		}
		if (*(_DWORD*)(a1 + 112) & 0x1000000) {
			if (*(_BYTE*)(a1 + 116) & 4)
				return 8;
			return 7;
		}
		if (v1 & 0x1000)
			return 7;
		result = 9;
	}
	return result;
}

//----- (004623B0) --------------------------------------------------------
int __cdecl sub_4623B0(int a1) {
	int v1;     // ecx
	char v3[3]; // [esp+0h] [ebp-4h]
	char v4;    // [esp+3h] [ebp-1h]

	v4 = HIBYTE(v1);
	v3[0] = 117;
	*(_WORD*)&v3[1] = sub_578B00(a1);
	return sub_40EBC0(31, 0, v3, 3);
}

//----- (004623E0) --------------------------------------------------------
_DWORD* __cdecl sub_4623E0(_DWORD* a1, int a2) {
	int v2;         // ebx
	_DWORD* result; // eax
	int v4;         // ecx
	int v5;         // ecx

	if (!(a1[28] & 0x2000000))
		goto LABEL_19;
	v2 = a1[29];
	if (v2 & 0x140) {
		result = *(_DWORD**)&byte_5D4594[4 * a2 + 1049872];
		if (!result)
			goto LABEL_19;
		while (result[92])
			result = (_DWORD*)result[92];
		if (!result)
			goto LABEL_19;
		if (v2 & 0x40) {
			if (result[28] & 0x2000000) {
				v4 = result[29];
				if (v4 & 0x100)
					result = (_DWORD*)result[93];
			}
		}
	} else {
		if (!(v2 & 0x10))
			goto LABEL_19;
		result = *(_DWORD**)&byte_5D4594[4 * a2 + 1049872];
		if (!result)
			goto LABEL_19;
		while (result[92])
			result = (_DWORD*)result[92];
	}
	if (result) {
		v5 = result[92];
		if (v5)
			*(_DWORD*)(v5 + 372) = a1;
		a1[92] = result[92];
		result[92] = a1;
		a1[93] = result;
		return result;
	}
LABEL_19:
	a1[93] = 0;
	a1[92] = *(_DWORD*)&byte_5D4594[4 * a2 + 1049872];
	result = *(_DWORD**)&byte_5D4594[4 * a2 + 1049872];
	if (result)
		result[93] = a1;
	*(_DWORD*)&byte_5D4594[4 * a2 + 1049872] = a1;
	return result;
}

//----- (004624D0) --------------------------------------------------------
int __cdecl sub_4624D0(int a1) {
	int result; // eax
	int v2;     // edi
	int* v3;    // eax
	int* v4;    // esi

	result = sub_461F90(a1);
	v2 = result;
	if (!result)
		return result;
	v3 = (int*)sub_461EF0(a1);
	v4 = v3;
	if (!v3)
		return sub_45A4B0((_QWORD*)v2);
	*(_DWORD*)(*v3 + 132) = 0;
	if (*(_DWORD*)&byte_5D4594[1062492] != v2) {
		if (sub_415880(*(char**)(v2 + 108)) & 0xC && dword_5d4594_1062480 &&
		    sub_415880(*(char**)(**(_DWORD**)&dword_5d4594_1062480 + 108)) == 2) {
			*(_DWORD*)(dword_5d4594_1062480 + 136) = 0;
			sub_461550(0);
		}
		return sub_45A4B0((_QWORD*)v2);
	}
	*(_DWORD*)&byte_5D4594[1062492] = 0;
	if (dword_5d4594_1062480) {
		*(_DWORD*)&byte_5D4594[1062496] = *(_DWORD*)(v2 + 128);
		*(_DWORD*)(**(_DWORD**)&dword_5d4594_1062480 + 128) = *(_DWORD*)(dword_5d4594_1062480 + 4);
		sub_4623B0(**(_DWORD**)&dword_5d4594_1062480);
	} else {
		sub_461550(*v3);
		*(_DWORD*)(*v4 + 136) = 1;
	}
	return sub_45A4B0((_QWORD*)v2);
}

//----- (004625D0) --------------------------------------------------------
int __cdecl sub_4625D0(_DWORD* a1) {
	__int16* v2; // eax
	int v3;      // [esp+0h] [ebp-10h]
	int v4;      // [esp+4h] [ebp-Ch]
	int v5;      // [esp+8h] [ebp-8h]
	int v6;      // [esp+Ch] [ebp-4h]

	if (dword_5d4594_1049864 == 5)
		return 1;
	nox_client_wndGetPosition_46AA60(a1, &v3, &v4);
	nox_window_get_size((int)a1, &v5, &v6);
	if (v4 + v6 > 0) {
		sub_434390(*(int*)&byte_5D4594[2523948]);
		if (dword_5d4594_1062480 && **(_DWORD**)&dword_5d4594_1062480) {
			*(_DWORD*)(**(_DWORD**)&dword_5d4594_1062480 + 12) = v3 + v5 / 2;
			*(_DWORD*)(**(_DWORD**)&dword_5d4594_1062480 + 16) = v4 + v6 / 2;
			(*(void(__cdecl**)(unsigned __int8*, _DWORD))(**(_DWORD**)&dword_5d4594_1062480 + 300))(
			    &byte_5D4594[1049732], **(_DWORD**)&dword_5d4594_1062480);
		}
		v2 = (__int16*)sub_42E8E0(35, 1);
		if (v2)
			sub_43F6E0(*(int*)&dword_5d4594_1063636, v2, v3 + 22, v4 + 41);
	}
	return 1;
}

//----- (004626C0) --------------------------------------------------------
double __cdecl sub_4626C0(int a1) {
	int v1; // edx
	int* i; // ecx
	int v3; // eax

	if (!a1 || !(*(_DWORD*)(a1 + 112) & 0x13001000))
		return 0.0;
	v1 = 2;
	for (i = (int*)(a1 + 440);; ++i) {
		v3 = *i;
		if (*i) {
			if (*(void(__cdecl**)(int, int, int, int))(v3 + 52) == sub_4E06F0)
				break;
		}
		if (++v1 >= 4)
			return 0.0;
	}
	return *(float*)(v3 + 56);
}

//----- (00462700) --------------------------------------------------------
double __cdecl sub_462700(int a1) {
	int v1; // edx
	int* i; // ecx
	int v3; // eax

	if (!a1 || !(*(_DWORD*)(a1 + 112) & 0x13001000))
		return 0.0;
	v1 = 2;
	for (i = (int*)(a1 + 440);; ++i) {
		v3 = *i;
		if (*i) {
			if (*(_DWORD * (__cdecl**)(int, int, int, int))(v3 + 52) == sub_4E0550)
				break;
		}
		if (++v1 >= 4)
			return 0.0;
	}
	return *(float*)(v3 + 56);
}

// 462878: variable 'v3' is possibly undefined
// 46288E: variable 'v4' is possibly undefined
// 4628A4: variable 'v5' is possibly undefined
// 4628CE: variable 'v6' is possibly undefined
// 4628E8: variable 'v7' is possibly undefined

//----- (00463370) --------------------------------------------------------
int __cdecl sub_463370(_DWORD* a1, _DWORD* a2, _DWORD* a3) {
	_DWORD* v4; // eax
	_DWORD* v5; // ecx
	int result; // eax
	int v7;     // [esp+0h] [ebp-4h]

	nox_client_wndGetPosition_46AA60(a1, &a1, &v7);
	v4 = a2;
	v5 = a3;
	*a3 = *a2 - (_DWORD)a1;
	result = v4[1] - v7;
	v5[1] = result;
	return result;
}

//----- (004633B0) --------------------------------------------------------
int __cdecl sub_4633B0(int a1, float* a2, float* a3) {
	int result; // eax
	int v4;     // esi
	float v5;   // [esp+0h] [ebp-10h]
	float v6;   // [esp+0h] [ebp-10h]

	result = a1;
	*a2 = *(unsigned __int16*)(a1 + 292);
	*a3 = *(unsigned __int16*)(a1 + 294);
	if (*(_DWORD*)(a1 + 112) & 0x13001000) {
		v4 = *(_DWORD*)(a1 + 436);
		if (v4) {
			if (*(float*(__cdecl**)(int, int, int, int, int, float*))(v4 + 76) == sub_4E0380) {
				v5 = (double)*a2 * *(float*)(v4 + 80);
				*a2 = nox_float2int(v5);
				v6 = (double)*a3 * *(float*)(v4 + 80);
				result = nox_float2int(v6);
				*a3 = result;
			}
		}
	}
	return result;
}

//----- (00463420) --------------------------------------------------------
int __cdecl sub_463420(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[1050012] = a1;
	return result;
}

//----- (00463430) --------------------------------------------------------
int __cdecl sub_463430(int a1) {
	int v1;          // et1
	int v2;          // ebp
	int v3;          // esi
	int v4;          // edi
	int v5;          // eax
	int v6;          // eax
	int v7;          // ebp
	int v8;          // eax
	int v9;          // edi
	int v10;         // esi
	int v11;         // esi
	int v12;         // edi
	int v13;         // et1
	int v14;         // et1
	int2 v16;        // [esp+10h] [ebp-28h]
	wchar_t v17[16]; // [esp+18h] [ebp-20h]

	v1 = *(_DWORD*)&byte_587000[136184];
	sub_46A9B0(*(_DWORD**)(a1 + 396), 0, v1);
	nox_client_wndGetPosition_46AA60((_DWORD*)a1, &v16, &v16.field_4);
	sub_43F320(0);
	v2 = 0;
	v3 = v16.field_0 + 10;
	v4 = v16.field_4 + 234;
	do {
		if ((1 << v2) & *(_DWORD*)&byte_5D4594[1062540] && v2 != 31 && v2 != 30) {
			v5 = sub_424920(v2);
			v6 = sub_424A90(v5);
			nox_client_drawImageAt_47D2C0(v6, v3, v4);
			v3 += 35;
		}
		++v2;
	} while (v2 < 32);
	v7 = 0;
	do {
		if (byte_5D4594[1062536] & (unsigned __int8)(1 << v7)) {
			v8 = sub_413420(1 << v7);
			nox_client_drawImageAt_47D2C0(v8, v3, v4);
			v3 += 35;
		}
		++v7;
	} while (v7 < 6);
	if (nox_common_gameFlags_check_40A5C0(4096) && *(_DWORD*)&byte_5D4594[1050008]) {
		v4 += 5;
		v3 += 6;
		nox_client_drawImageAt_47D2C0(
		    *(_DWORD*)(*(_DWORD*)(*(_DWORD*)(*(_DWORD*)&byte_5D4594[1050008] + 96) + 4) +
			       4 * (*(_DWORD*)&byte_5D4594[2598000] %
				    (unsigned int)*(unsigned __int8*)(*(_DWORD*)(*(_DWORD*)&byte_5D4594[1050008] + 96) +
								      8))),
		    v3 - 58, v4 - 53);
		nox_swprintf(v17, L"X %d", *(_DWORD*)&byte_5D4594[1050012]);
		sub_434390(*(int*)&byte_5D4594[2614244]);
		sub_43F6E0(*(int*)&dword_5d4594_1063636, (__int16*)v17, v3 + 20, v4 + 9);
		*(_DWORD*)&byte_5D4594[1049812] = v3 - 30;
		*(_DWORD*)&byte_5D4594[1049816] = v4 - 20;
		*(_DWORD*)&byte_5D4594[1049820] = v3 + 30;
		*(_DWORD*)&byte_5D4594[1049824] = v4 + 20;
	}
	if (nox_common_gameFlags_check_40A5C0(4096) && sub_4BFD30()) {
		v9 = v4 + 5;
		v10 = v3 + 66;
		nox_client_drawImageAt_47D2C0(*(int*)&byte_5D4594[1050004], v10 - 64, v9 - 58);
		*(_DWORD*)&byte_5D4594[1049828] = v10 - 30;
		*(_DWORD*)&byte_5D4594[1049832] = v9 - 20;
		*(_DWORD*)&byte_5D4594[1049836] = v10 + 30;
		*(_DWORD*)&byte_5D4594[1049840] = v9 + 20;
	}
	if (byte_5D4594[1049868]) {
		v11 = v16.field_4 + 13;
		v12 = v16.field_0 + 254;
		if (v16.field_4 + 163 > 0) {
			sub_49F7F0();
			nox_client_copyRect_49F6F0(v12, v11, 260, 150);
			if (byte_5D4594[1049869]) {
				if (byte_5D4594[1049869] == 1)
					sub_469D40(v12, v11, *(int*)&dword_5d4594_1062512);
			} else {
				sub_4643B0(v12, v11);
			}
			sub_49F860();
		}
		if (dword_5d4594_1049864 == 5) {
			sub_4627F0(&v16);
			nox_client_drawImageAt_47D2C0(*(int*)&byte_5D4594[1049912], v16.field_0, v16.field_4);
		} else {
			if (byte_5D4594[1049870]) {
				if (byte_5D4594[1049870] == 1) {
					sub_463880(&v16.field_0);
					nox_client_drawImageAt_47D2C0(*(int*)&byte_5D4594[1049912], v16.field_0, v16.field_4);
				}
			} else {
				sub_4BF7E0(&v16);
				nox_client_drawImageAt_47D2C0(*(int*)&byte_5D4594[1049908], v16.field_0, v16.field_4);
			}
			sub_434390(*(int*)&byte_5D4594[2523948]);
			sub_43FAF0(0, &byte_5D4594[1062588], v16.field_0 + 13, v16.field_4 + 17, 196, 0);
		}
	}
	if (byte_5D4594[1049868] == 1) {
		v14 = *(_DWORD*)&byte_587000[136184];
		*(_DWORD*)&byte_587000[136184] = v14 + 64;
		if (v14 + 64 > 0) {
			*(_DWORD*)&byte_587000[136184] = 0;
			byte_5D4594[1049868] = 2;
		}
	} else if (byte_5D4594[1049868] == 3) {
		v13 = *(_DWORD*)&byte_587000[136184];
		*(_DWORD*)&byte_587000[136184] = v13 - 32;
		if (v13 - 32 <= -225) {
			*(_DWORD*)&byte_587000[136184] = -225;
			byte_5D4594[1049868] = 0;
			if (byte_5D4594[1049869]) {
				if (byte_5D4594[1049869] == 1)
					*(_DWORD*)&byte_5D4594[1062520] = dword_5d4594_1062512;
			} else {
				*(_DWORD*)&byte_5D4594[1062516] = dword_5d4594_1062512;
			}
			byte_5D4594[1049869] = 0;
			dword_5d4594_1062512 = *(_DWORD*)&byte_5D4594[1062516];
			nox_window_call_field_94(*(int*)&dword_5d4594_1062508, 16395, 0, 850);
			nox_window_call_field_94(*(int*)&dword_5d4594_1062508, 16394,
						 *(_DWORD*)(*(_DWORD*)(dword_5d4594_1062508 + 32) + 4) -
						     dword_5d4594_1062512,
						 0);
			sub_46AE60(*(int*)&byte_5D4594[1062528], 0);
			sub_46AEC0(*(int*)&byte_5D4594[1062528], *(int*)&byte_5D4594[1049976]);
			sub_46B080(*(_DWORD**)&byte_5D4594[1062528], 9105);
			byte_5D4594[1049870] = 0;
			sub_46AE60(*(int*)&byte_5D4594[1062524], *(int*)&byte_5D4594[1049992]);
			sub_46AEC0(*(int*)&byte_5D4594[1062524], *(int*)&byte_5D4594[1049996]);
			sub_46B080(*(_DWORD**)&byte_5D4594[1062524], 9107);
			nox_window_set_hidden(*(int*)&byte_5D4594[1062468], 0);
		}
	}
	if (sub_467C80() && sub_4372B0())
		sub_467C10();
	return 1;
}

//----- (004643B0) --------------------------------------------------------
int __cdecl sub_4643B0(int a1, int a2) {
	int v2;                // ebx
	int v3;                // esi
	unsigned __int8* v4;   // ebp
	int v5;                // edi
	int v6;                // ebx
	int v7;                // esi
	double v8;             // st7
	double v9;             // st6
	int v10;               // eax
	int v11;               // edx
	int v12;               // eax
	__int16 v13;           // ax
	__int16 v14;           // ax
	__int16 v15;           // si
	bool v16;              // zf
	int result;            // eax
	int v18;               // [esp-8h] [ebp-5Ch]
	int v19;               // [esp-4h] [ebp-58h]
	int v20;               // [esp+10h] [ebp-44h]
	int v21;               // [esp+14h] [ebp-40h]
	int v22;               // [esp+18h] [ebp-3Ch]
	unsigned __int8* v23;  // [esp+1Ch] [ebp-38h]
	int v24;               // [esp+20h] [ebp-34h]
	int v25;               // [esp+24h] [ebp-30h]
	int v26;               // [esp+28h] [ebp-2Ch]
	int v27;               // [esp+2Ch] [ebp-28h]
	WCHAR WideCharStr[16]; // [esp+34h] [ebp-20h]
	unsigned __int8* v29;  // [esp+58h] [ebp+4h]

	v2 = a2;
	nox_client_drawImageAt_47D2C0(*(int*)&byte_5D4594[1049928], a1, a2);
	_itow(*(int*)&byte_5D4594[1062552], WideCharStr, 10);
	sub_434390(*(int*)&byte_5D4594[2589772]);
	sub_43F840(*(int*)&dword_5d4594_1063636, WideCharStr, &v24, 0, 0);
	sub_43F6E0(*(int*)&dword_5d4594_1063636, (__int16*)WideCharStr, a1 - v24 + 43, a2 + 36);
	if (dword_5d4594_1049864 == 5)
		nox_client_drawImageAt_47D2C0(*(int*)&byte_5D4594[1049932], a1, a2 + 50);
	if (sub_473670())
		nox_client_drawImageAt_47D2C0(*(int*)&byte_5D4594[1049936], a1, a2 + 100);
	v3 = a1 + 60;
	v4 = &byte_5D4594[1050160];
	v27 = a1 + 60;
	v5 = a2 - dword_5d4594_1062512;
	v20 = 0;
	v23 = &byte_5D4594[1050160];
	do {
		if (v5 > v2 - 50) {
			v6 = v3;
			nox_client_drawImageAt_47D2C0(*(_DWORD*)&byte_5D4594[4 * (v20 % 3) + 1049916], v3, v5);
			v29 = v4;
			v22 = 4;
			while (1) {
				if (*v4) {
					v7 = *((_DWORD*)v4 - 35);
					if (v7)
						break;
				}
			LABEL_43:
				v6 += 50;
				v4 += 3108;
				v16 = v22 == 1;
				v29 = v4;
				--v22;
				if (v16) {
					v2 = a2;
					v4 = v23;
					v3 = v27;
					goto LABEL_45;
				}
			}
			v21 = 0;
			nox_client_drawEnableAlpha_434560(1);
			nox_client_drawSetAlpha_434580(0x40u);
			v8 = (double)*(unsigned __int16*)(v7 + 292);
			v25 = *(unsigned __int16*)(v7 + 294);
			v9 = (double)v25;
			if (v8 >= v9 * *(double*)&byte_581450[9608]) {
				if (v8 >= v9 * *(double*)&byte_581450[9544])
					goto LABEL_16;
				v10 = *(_DWORD*)&byte_5D4594[2589772];
			} else {
				v10 = *(_DWORD*)&byte_5D4594[2650644];
			}
			if (v10 != 0x80000000) {
				nox_client_drawSetColor_434460(v10);
				nox_client_drawRectFilledOpaque_49CE30(v6, v5, 50, 50);
			}
		LABEL_16:
			nox_client_drawSetAlpha_434580(0x80u);
			if (*((_DWORD*)v4 - 2)) {
				v11 = *(_DWORD*)&byte_5D4594[1049964];
				v19 = v5;
				v18 = v6;
			} else {
				if (*((_DWORD*)v4 - 1)) {
					nox_client_drawImageAt_47D2C0(*(int*)&byte_5D4594[1049968], v6, v5);
				LABEL_27:
					nox_client_drawEnableAlpha_434560(0);
					*(_DWORD*)(v7 + 16) = v5 + 25;
					*(_DWORD*)(v7 + 12) = v6 + 25;
					(*(void(__cdecl**)(unsigned __int8*, int))(v7 + 300))(&byte_5D4594[1049732],
											      v7);
					if (dword_5d4594_1049864 == 6) {
						if (*(_DWORD*)(v7 + 112) & 0x13001000) {
							if ((*(_DWORD*)(v7 + 112) & 0x1000) == 4096) {
								v13 = *(_WORD*)(v7 + 450);
								if (*(_WORD*)(v7 + 448) < v13) {
									if (v13)
										v21 = 1;
								}
							}
						}
						v14 = *(_WORD*)(v7 + 294);
						if ((*(_WORD*)(v7 + 292) == v14 || !v14) && !v21)
							nox_client_drawRectFilledAlpha_49CF10(v6, v5, 50, 50);
					}
					if (*v29 > 1u) {
						nox_swprintf(WideCharStr, L"%d", *v29);
						sub_434390(*(int*)&byte_5D4594[2523948]);
						sub_43F6E0(*(int*)&dword_5d4594_1063636, (__int16*)WideCharStr, v6 + 6,
							   v5 + 6);
					}
					if (*(_DWORD*)(v7 + 112) & 0x13001000) {
						v15 = *(_WORD*)(v7 + 448);
						if (v15 >= 0) {
							nox_swprintf(WideCharStr, L"%d", v15);
							sub_434390(*(int*)&byte_5D4594[2650684]);
							sub_43F840(*(int*)&dword_5d4594_1063636, WideCharStr, &v26, 0,
								   0);
							sub_43F6E0(*(int*)&dword_5d4594_1063636, (__int16*)WideCharStr,
								   v6 - v26 + 44, v5 + 6);
						}
					}
					v4 = v29;
					goto LABEL_43;
				}
				if (*((_DWORD*)v4 - 34) != *(_DWORD*)&byte_5D4594[1062488])
					goto LABEL_27;
				if (!dword_5d4594_1062480)
					goto LABEL_27;
				v12 = **(_DWORD**)&dword_5d4594_1062480;
				if (!**(_DWORD**)&dword_5d4594_1062480 || !(*(_DWORD*)(v12 + 112) & 0x1000000) ||
				    !(*(_BYTE*)(v12 + 116) & 0xC)) {
					goto LABEL_27;
				}
				v11 = *(_DWORD*)&byte_5D4594[1049968];
				v19 = v5;
				v18 = v6;
			}
			nox_client_drawImageAt_47D2C0(v11, v18, v19);
			goto LABEL_27;
		}
	LABEL_45:
		v5 += 50;
		result = v2 + 150;
		if (v5 > v2 + 150)
			break;
		v4 += 148;
		++v20;
		v23 = v4;
	} while ((int)v4 < (int)&byte_5D4594[1053120]);
	return result;
}

//----- (00464770) --------------------------------------------------------
int __cdecl sub_464770(int a1, int a2, unsigned int a3) {
	int v3;     // eax
	int v4;     // esi
	int v5;     // eax
	int v6;     // eax
	int result; // eax

	if (dword_5d4594_1049864 == 6)
		return 1;
	switch (a2) {
	case 5:
	case 8:
		return 1;
	case 6:
		if (!*(_DWORD*)&byte_5D4594[1049848])
			goto LABEL_25;
		if (!sub_46AAB0(*(_DWORD**)&dword_5d4594_1062456, (unsigned __int16)a3, a3 >> 16))
			goto LABEL_22;
		if (*(_DWORD*)&byte_5D4594[1049856]) {
			if (*(_DWORD*)(*(_DWORD*)&byte_5D4594[1049848] + 112) & 0x1001000) {
				if (dword_5d4594_1062480) {
					sub_4672C0();
				} else {
					*(_DWORD*)&byte_5D4594[1062492] = *(_DWORD*)&byte_5D4594[1049848];
					sub_464B70(*(int*)&byte_5D4594[1049848]);
				}
			}
		} else if (!(*(_DWORD*)(*(_DWORD*)&byte_5D4594[1049848] + 112) & 0x1001000) ||
			   *(_DWORD*)&byte_5D4594[148 * (dword_5d4594_1049800 +
							 14 * dword_5d4594_1049796 +
							 7 * dword_5d4594_1049796) +
						  1050152]) {
			sub_4649B0(*(int*)&byte_5D4594[1049848], *(int*)&dword_5d4594_1049796,
				   *(int*)&dword_5d4594_1049800);
		} else {
			if (sub_415880(*(char**)(*(_DWORD*)&byte_5D4594[1049848] + 108)) == 2) {
				v3 = sub_415840((char*)4);
				v4 = sub_461600(v3);
				v5 = sub_415840((char*)8);
				v6 = sub_461600(v5);
				if (!v4 && !v6) {
					sub_4649B0(*(int*)&byte_5D4594[1049848], *(int*)&dword_5d4594_1049796,
						   *(int*)&dword_5d4594_1049800);
					sub_4776A0();
					if (!*(_DWORD*)&byte_5D4594[1049856])
						sub_45A4B0(*(_QWORD**)&byte_5D4594[1049848]);
					*(_DWORD*)&byte_5D4594[1049848] = 0;
					*(_DWORD*)&byte_5D4594[1049856] = 0;
					return 1;
				}
			}
			if (dword_5d4594_1062480)
				*(_DWORD*)(dword_5d4594_1062480 + 136) = 0;
			sub_4649B0(*(int*)&byte_5D4594[1049848], *(int*)&dword_5d4594_1049796,
				   *(int*)&dword_5d4594_1049800);
			sub_461550((int)&byte_5D4594[148 * (dword_5d4594_1049800 +
							    14 * dword_5d4594_1049796 +
							    7 * dword_5d4594_1049796) +
						     1050020]);
			*(_DWORD*)(dword_5d4594_1062480 + 136) = 1;
		}
	LABEL_22:
		sub_4776A0();
		if (!*(_DWORD*)&byte_5D4594[1049856])
			sub_45A4B0(*(_QWORD**)&byte_5D4594[1049848]);
		*(_DWORD*)&byte_5D4594[1049848] = 0;
		*(_DWORD*)&byte_5D4594[1049856] = 0;
	LABEL_25:
		sub_46ADE0(*(int*)&dword_5d4594_1062456);
		result = 1;
		break;
	case 7:
		if (dword_5d4594_1062480)
			sub_4672C0();
		return 1;
	default:
		return 0;
	}
	return result;
}

//----- (00464B40) --------------------------------------------------------
BOOL __cdecl sub_464B40(int a1, int a2) { return a1 >= 0 && a1 < 4 && a2 >= 0 && a2 < 21; }

//----- (00464B70) --------------------------------------------------------
int __cdecl sub_464B70(int a1) {
	int v1;     // ecx
	char v3[3]; // [esp+0h] [ebp-4h]
	char v4;    // [esp+3h] [ebp-1h]

	v4 = HIBYTE(v1);
	v3[0] = 118;
	*(_WORD*)&v3[1] = sub_578B00(a1);
	return sub_40EBC0(31, 0, v3, 3);
}

//----- (00464BA0) --------------------------------------------------------
int sub_464BA0() { return 0; }

//----- (00464BB0) --------------------------------------------------------
BOOL __cdecl sub_464BB0(int a1, int a2) { return a2 != 8 && a2 != 12 && a2 != 16; }

// 464C71: variable 'v4' is possibly undefined
// 464C8B: variable 'v5' is possibly undefined
// 464CD6: variable 'v6' is possibly undefined
// 464CF0: variable 'v7' is possibly undefined
// 464D4C: variable 'v8' is possibly undefined
// 464E24: variable 'v14' is possibly undefined
// 464E64: variable 'v15' is possibly undefined
// 464F2B: variable 'v21' is possibly undefined
// 464F52: variable 'v22' is possibly undefined
// 464F6C: variable 'v23' is possibly undefined
// 465009: variable 'v24' is possibly undefined
// 465020: variable 'v25' is possibly undefined
// 465066: variable 'v26' is possibly undefined
// 465200: variable 'v30' is possibly undefined
// 46521A: variable 'v31' is possibly undefined
// 465281: variable 'v34' is possibly undefined
// 46535F: variable 'v36' is possibly undefined
// 4653B8: variable 'v37' is possibly undefined

//----- (004657B0) --------------------------------------------------------
int __cdecl sub_4657B0(__int16 a1) {
	char v2[4]; // [esp+0h] [ebp-4h]

	v2[0] = -55;
	v2[1] = 30;
	*(_WORD*)&v2[2] = a1;
	return sub_40EBC0(31, 0, v2, 4);
}

//----- (004657E0) --------------------------------------------------------
char __cdecl sub_4657E0(_DWORD* a1) {
	int v1; // eax

	v1 = sub_4281F0((int2*)a1, (int4*)&byte_587000[136352]);
	if (v1) {
		LOBYTE(v1) = byte_5D4594[148 * ((a1[1] + dword_5d4594_1062512 - 13) / 50 +
						14 * ((*a1 - 314) / 50) + 7 * ((*a1 - 314) / 50)) +
					 1050160];
		if ((_BYTE)v1)
			LOBYTE(v1) =
			    sub_465870(*(_DWORD*)&byte_5D4594
					   [148 * ((a1[1] + dword_5d4594_1062512 - 13) / 50 +
						   14 * ((*a1 - 314) / 50) + 7 * ((*a1 - 314) / 50)) +
					    1050020 +
					    4 * byte_5D4594[148 * ((a1[1] + dword_5d4594_1062512 - 13) / 50 +
								   14 * ((*a1 - 314) / 50) + 7 * ((*a1 - 314) / 50)) +
							    1050160]]);
	}
	return v1;
}
// 4657F5: variable 'v1' is possibly undefined

//----- (00465870) --------------------------------------------------------
int __cdecl sub_465870(__int16 a1) {
	char v2[4]; // [esp+0h] [ebp-4h]

	v2[0] = -55;
	v2[1] = 28;
	*(_WORD*)&v2[2] = a1;
	return sub_40EBC0(31, 0, v2, 4);
}

//----- (004658A0) --------------------------------------------------------
void __cdecl sub_4658A0(int a1, int2* a2) {
	if (byte_5D4594[1049868] == 2) {
		if (sub_4281F0(a2, (int4*)&byte_587000[136336])) {
			*(_DWORD*)&byte_5D4594[1049848] = *(_DWORD*)&byte_5D4594[4 * sub_465990(a2) + 1049872];
			*(_DWORD*)&byte_5D4594[1049856] = 1;
		} else {
			*(_DWORD*)&byte_5D4594[1049856] = 0;
			if (sub_4281F0(a2, (int4*)&byte_587000[136368])) {
				if ((a2->field_4 - 13) / 50 == 2)
					sub_473610();
			} else if (sub_4281F0(a2, (int4*)&byte_587000[136352])) {
				dword_5d4594_1049796 = (a2->field_0 - 314) / 50;
				dword_5d4594_1049800 =
				    (a2->field_4 + *(int*)&dword_5d4594_1062512 - 13) / 50;
				if (sub_464B40(*(int*)&dword_5d4594_1049796, *(int*)&dword_5d4594_1049800))
					sub_465A30();
			}
		}
	}
}
// 4658C2: variable 'v2' is possibly undefined
// 4658FF: variable 'v3' is possibly undefined
// 465934: variable 'v5' is possibly undefined

//----- (00465990) --------------------------------------------------------
int __cdecl sub_465990(_DWORD* a1) {
	int v1;  // eax
	int v2;  // esi
	int v3;  // eax
	int v5;  // eax
	int2 v6; // [esp+4h] [ebp-8h]

	v1 = a1[1] - 15;
	v6.field_0 = *a1 - 11;
	v6.field_4 = v1;
	v2 = 0;
	while (1) {
		v3 = sub_4281F0(&v6, (int4*)&byte_587000[16 * v2 + 136192]);
		if (!v3)
			goto LABEL_6;
		if (v2 == 6)
			break;
		if (v2)
			return v2;
		if (*(_DWORD*)&byte_5D4594[1049872])
			return 0;
	LABEL_6:
		if (++v2 >= 9)
			return -1;
	}
	v5 = *(_DWORD*)&byte_5D4594[1049904];
	if (!*(_DWORD*)&byte_5D4594[1049904])
		return 5;
	while (!(*(_DWORD*)(v5 + 112) & 0x2000000) || !(*(_BYTE*)(v5 + 116) & 2)) {
		v5 = *(_DWORD*)(v5 + 368);
		if (!v5)
			return 5;
	}
	return 8;
}
// 4659C7: variable 'v3' is possibly undefined

//----- (00465BE0) --------------------------------------------------------
int __cdecl sub_465BE0(int2* a1) {
	int result; // eax
	__int16 v2; // dx
	char v3[7]; // [esp+0h] [ebp-8h]

	result = *(_DWORD*)&byte_5D4594[1049848];
	if (*(_DWORD*)&byte_5D4594[1049848]) {
		v3[0] = 114;
		*(_WORD*)&v3[1] = sub_578B00(*(int*)&byte_5D4594[1049848]);
		v2 = a1->field_4;
		*(_WORD*)&v3[3] = a1->field_0;
		*(_WORD*)&v3[5] = v2;
		result = sub_40EBC0(31, 0, v3, 7);
	}
	return result;
}

//----- (00465C30) --------------------------------------------------------
BOOL __cdecl sub_465C30(int a1, int a2) {
	dword_5d4594_1049796 = a1;
	dword_5d4594_1049800 = a2;
	sub_465A30();
	sub_4623B0(*(int*)&byte_5D4594[1049848]);
	return sub_4649B0(*(int*)&byte_5D4594[1049848], a1, a2);
}

//----- (00465C70) --------------------------------------------------------
void __cdecl sub_465C70(int a1) {
	int v2; // [esp-4h] [ebp-4h]

	if (a1) {
		v2 = a1;
		LOBYTE(a1) = 116;
		*(_WORD*)((char*)&a1 + 1) = sub_578B00(v2);
		sub_40EBC0(31, 0, &a1, 3);
	}
}

//----- (00465CA0) --------------------------------------------------------
int sub_465CA0() {
	nox_window_set_hidden(*(int*)&byte_5D4594[1062476], 0);
	dword_5d4594_1049864 = 5;
	nox_client_setCursorType_477610(6);
	return sub_46ADC0(*(int*)&dword_5d4594_1062456);
}

//----- (00465CD0) --------------------------------------------------------
void __cdecl sub_465CD0(_DWORD* a1, int a2, int a3, int a4) {
	int v4;   // edi
	char* v5; // ebx
	int v6;   // esi
	int2 v7;  // [esp+8h] [ebp-8h]

	v4 = a4;
	if (a4) {
		sub_473970((int2*)a1, &v7);
		v5 = sub_461EF0(a2);
		if (v5) {
			v6 = 4;
			do {
				*(_DWORD*)&byte_5D4594[1049848] = **(_DWORD**)v5;
				*(_DWORD*)(*(_DWORD*)&byte_5D4594[1049848] + 128) = *(_DWORD*)(*(_DWORD*)v5 + v6);
				if (!sub_4C12C0())
					sub_465BE0(&v7);
				v6 += 4;
				--v4;
				*(_DWORD*)&byte_5D4594[1049848] = 0;
			} while (v4);
		}
	}
}

//----- (00465D50) --------------------------------------------------------
int __cdecl sub_465D50_draw(int a1) {
	int v2;     // eax
	int result; // eax
	int v4;     // [esp+0h] [ebp-4h]

	nox_client_wndGetPosition_46AA60(*(_DWORD**)(a1 + 396), &v4, &a1);
	v2 = sub_4615C0();
	if (v2) {
		*(_DWORD*)(v2 + 12) = v4 + 51;
		*(_DWORD*)(v2 + 16) = a1 + 81;
		(*(void(__cdecl**)(unsigned __int8*, int))(v2 + 300))(&byte_5D4594[1049732], v2);
		result = 1;
	} else {
		if (!*(_DWORD*)&byte_5D4594[1062496] && !*(_DWORD*)&byte_5D4594[1062492])
			nox_client_drawImageAt_47D2C0(*(int*)&byte_5D4594[1050000], v4 + 21, a1 + 50);
		result = 1;
	}
	return result;
}

//----- (00465DE0) --------------------------------------------------------
int __cdecl sub_465DE0(int a1) {
	*(_DWORD*)&byte_5D4594[1049844] = a1;
	return sub_467460();
}
// 467460: using guessed type int sub_467460(void);

//----- (00465DF0) --------------------------------------------------------
int sub_465DF0() { return *(_DWORD*)&byte_5D4594[1049844]; }

//----- (00465E00) --------------------------------------------------------
int sub_465E00() {
	_DWORD* v0; // eax
	int result; // eax
	_DWORD* v2; // eax
	char* v3;   // eax
	char* v4;   // eax
	_DWORD* v5; // eax
	int v6;     // eax
	int v7;     // eax

	sub_467050();
	sub_4671E0();
	dword_5d4594_1063636 = sub_43F360((char*)&byte_587000[139424]);
	*(_DWORD*)&byte_5D4594[1049732] = 0;
	*(_DWORD*)&byte_5D4594[1049736] = 0;
	*(_DWORD*)&byte_5D4594[1049740] = nox_win_width;
	*(_DWORD*)&byte_5D4594[1049744] = nox_win_height;
	*(_DWORD*)&byte_5D4594[1049764] = nox_win_width;
	*(_DWORD*)&byte_5D4594[1049768] = nox_win_height;
	*(_DWORD*)&byte_5D4594[1049748] = 0;
	*(_DWORD*)&byte_5D4594[1049752] = 0;
	*(_DWORD*)&byte_5D4594[1062452] = nox_window_new(0, 552, 0, 0, 563, 264, 0);
	nox_window_set_all_funcs(*(_DWORD**)&byte_5D4594[1062452], 0, sub_4661C0, 0);
	v0 = nox_window_new(*(int*)&byte_5D4594[1062452], 8, 0, 224, nox_win_width, 40, 0);
	nox_window_set_all_funcs(v0, sub_464BA0, sub_4661C0, sub_4667E0);
	dword_5d4594_1062456 = nox_window_new(*(int*)&byte_5D4594[1062452], 40, 0, 0, 563, 224, sub_466220);
	nox_window_set_all_funcs(*(_DWORD**)&dword_5d4594_1062456, sub_464BD0, sub_463430, sub_466620);
	*(_DWORD*)(dword_5d4594_1062456 + 44) |= 0x100u;
	*(_DWORD*)&byte_5D4594[1062472] = nox_window_new(*(int*)&byte_5D4594[1062452], 40, 0, 0, 1, 1, 0);
	nox_window_set_all_funcs(*(_DWORD**)&byte_5D4594[1062472], sub_464BD0, sub_4661C0, 0);
	*(_DWORD*)&byte_5D4594[1062468] = nox_window_new(*(int*)&dword_5d4594_1062456, 40, 173, 174, 50, 50, 0);
	nox_window_set_all_funcs(*(_DWORD**)&byte_5D4594[1062468], sub_464770, sub_4625D0, sub_4661D0);
	*(_DWORD*)(*(_DWORD*)&byte_5D4594[1062468] + 44) |= 0x100u;
	result = sub_466950(*(int*)&dword_5d4594_1062456);
	if (!result)
		return 0;

	result = sub_466C40(*(int*)&dword_5d4594_1062456);
	if (!result)
		return 0;

	result = sub_466ED0(*(int*)&dword_5d4594_1062456);
	if (!result)
		return 0;

	nox_win_unk5 = nox_window_new(0, 0x408 | NOX_WIN_LAYER_BACK, -1, nox_win_height - 127, 111, 127, 0);
	if (!nox_win_unk5)
		return 0;

	nox_window_set_all_funcs(nox_win_unk5, sub_464BB0, sub_466580, 0);
	v3 = sub_42F970("CurrentWeapon");
	sub_46AE60(nox_win_unk5, (int)v3);
	v4 = sub_42F970("CurrentWeaponLit");
	sub_46AEA0(nox_win_unk5, (int)v4);
	sub_46AE40(nox_win_unk5, -1, 0);
	nox_win_init_cur_weapon(nox_win_unk5, 24, 51, 53, 53);
	sub_471160(nox_win_unk5, 79, 40, 20, 127);
	sub_470D70();
	v5 = nox_window_new(nox_win_unk5, 8, 5, 11, 28, 29, 0);
	nox_window_set_all_funcs(v5, sub_466550, sub_4661C0, sub_466160);
	memset(&byte_5D4594[1050020], 0, 0x3090u);
	if (!*(_DWORD*)&byte_5D4594[1062560]) {
		*(_DWORD*)&byte_5D4594[1062560] = sub_44CFC0((CHAR*)&byte_587000[139468]);
		*(_DWORD*)&byte_5D4594[1049728] = sub_44CFC0((CHAR*)&byte_587000[139476]);
		*(_DWORD*)&byte_5D4594[1049724] = sub_44CFC0((CHAR*)&byte_587000[139492]);
	}
	*(_DWORD*)&byte_5D4594[1052980] = nox_new_drawable_for_thing(*(int*)&byte_5D4594[1062560]);
	if (*(_DWORD*)&byte_5D4594[1052980])
		byte_5D4594[1053120] = 1;
	v6 = *(_DWORD*)&byte_5D4594[1062564];
	if (!*(_DWORD*)&byte_5D4594[1062564]) {
		v6 = sub_44CFC0((CHAR*)&byte_587000[139508]);
		*(_DWORD*)&byte_5D4594[1062564] = v6;
	}
	*(_DWORD*)&byte_5D4594[1056088] = nox_new_drawable_for_thing(v6);
	if (*(_DWORD*)&byte_5D4594[1056088])
		byte_5D4594[1056228] = 1;
	v7 = *(_DWORD*)&byte_5D4594[1062556];
	if (!*(_DWORD*)&byte_5D4594[1062556]) {
		v7 = sub_44CFC0((CHAR*)&byte_587000[139520]);
		*(_DWORD*)&byte_5D4594[1062556] = v7;
	}
	*(_DWORD*)&byte_5D4594[1059196] = nox_new_drawable_for_thing(v7);
	if (*(_DWORD*)&byte_5D4594[1059196])
		byte_5D4594[1059336] = 1;

	return dword_5d4594_1062456;
}

//----- (004661C0) --------------------------------------------------------
int sub_4661C0() { return 1; }

//----- (00466220) --------------------------------------------------------
int __cdecl sub_466220(int a1, int a2, int* a3, int a4) {
	int result; // eax
	int v5;     // ecx
	int v6;     // ecx
	int v7;     // ecx
	int v8;     // eax

	if (a2 == 16391) {
		switch (sub_46B0A0(a3)) {
		case 9102:
			if (*(int*)&dword_5d4594_1062512 - 25 >= 0)
				v5 = *(int*)&dword_5d4594_1062512 - 25 - (*(int*)&dword_5d4594_1062512 - 25) % 50;
			else
				v5 = 0;
			dword_5d4594_1062512 = v5;
			nox_window_call_field_94(*(int*)&dword_5d4594_1062508, 16394,
						 *(_DWORD*)(*(_DWORD*)(dword_5d4594_1062508 + 32) + 4) - v5,
						 0);
			sub_452D80(766, 100);
			result = 0;
			break;
		case 9103:
			v6 = dword_5d4594_1062512 + 50;
			dword_5d4594_1062512 = v6;
			if (v6 <= *(int*)(*(_DWORD*)(dword_5d4594_1062508 + 32) + 4))
				v7 = v6 - v6 % 50;
			else
				v7 = *(_DWORD*)(*(_DWORD*)(dword_5d4594_1062508 + 32) + 4);
			dword_5d4594_1062512 = v7;
			nox_window_call_field_94(*(int*)&dword_5d4594_1062508, 16394,
						 *(_DWORD*)(*(_DWORD*)(dword_5d4594_1062508 + 32) + 4) - v7,
						 0);
			sub_452D80(766, 100);
			result = 0;
			break;
		case 9105:
			v8 = sub_469FA0() - 150;
			if (dword_5d4594_1049864 == 5)
				goto LABEL_23;
			if (v8 < 0)
				v8 = 0;
			byte_5D4594[1049869] = 1;
			*(_DWORD*)&byte_5D4594[1062516] = dword_5d4594_1062512;
			dword_5d4594_1062512 = *(_DWORD*)&byte_5D4594[1062520];
			nox_window_call_field_94(*(int*)&dword_5d4594_1062508, 16395, 0, v8);
			nox_window_call_field_94(*(int*)&dword_5d4594_1062508, 16394,
						 *(_DWORD*)(*(_DWORD*)(dword_5d4594_1062508 + 32) + 4) -
						     dword_5d4594_1062512,
						 0);
			sub_46AE60(*(int*)&byte_5D4594[1062528], *(int*)&byte_5D4594[1049980]);
			sub_46AEC0(*(int*)&byte_5D4594[1062528], *(int*)&byte_5D4594[1049984]);
			sub_46B080(*(_DWORD**)&byte_5D4594[1062528], 9106);
			result = 0;
			break;
		case 9106:
			byte_5D4594[1049869] = 0;
			*(_DWORD*)&byte_5D4594[1062520] = dword_5d4594_1062512;
			dword_5d4594_1062512 = *(_DWORD*)&byte_5D4594[1062516];
			nox_window_call_field_94(*(int*)&dword_5d4594_1062508, 16395, 0, 850);
			nox_window_call_field_94(*(int*)&dword_5d4594_1062508, 16394,
						 *(_DWORD*)(*(_DWORD*)(dword_5d4594_1062508 + 32) + 4) -
						     dword_5d4594_1062512,
						 0);
			sub_46AE60(*(int*)&byte_5D4594[1062528], 0);
			sub_46AEC0(*(int*)&byte_5D4594[1062528], *(int*)&byte_5D4594[1049976]);
			sub_46B080(*(_DWORD**)&byte_5D4594[1062528], 9105);
			result = 0;
			break;
		case 9107:
			if (dword_5d4594_1049864 == 5)
				goto LABEL_23;
			byte_5D4594[1049870] = 1;
			sub_46AE60(*(int*)&byte_5D4594[1062524], 0);
			sub_46AEC0(*(int*)&byte_5D4594[1062524], *(int*)&byte_5D4594[1049988]);
			sub_46B080(*(_DWORD**)&byte_5D4594[1062524], 9108);
			nox_window_set_hidden(*(int*)&byte_5D4594[1062468], 1);
			result = 0;
			break;
		case 9108:
			if (dword_5d4594_1049864 != 5) {
				byte_5D4594[1049870] = 0;
				sub_46AE60(*(int*)&byte_5D4594[1062524], *(int*)&byte_5D4594[1049992]);
				sub_46AEC0(*(int*)&byte_5D4594[1062524], *(int*)&byte_5D4594[1049996]);
				sub_46B080(*(_DWORD**)&byte_5D4594[1062524], 9107);
				nox_window_set_hidden(*(int*)&byte_5D4594[1062468], 0);
			}
			goto LABEL_23;
		case 9111:
			sub_467C10();
			result = 0;
			break;
		default:
			goto LABEL_23;
		}
	} else if (a2 == 16393) {
		result = 0;
		dword_5d4594_1062512 = *(_DWORD*)(*(_DWORD*)(dword_5d4594_1062508 + 32) + 4) - a4;
	} else {
	LABEL_23:
		result = 0;
	}
	return result;
}

//----- (00466550) --------------------------------------------------------
int __cdecl sub_466550(int a1, unsigned int a2) {
	if (a2 >= 5) {
		if (a2 <= 6)
			return 1;
		if (a2 == 7) {
			sub_467C60();
			return 1;
		}
	}
	return 0;
}

//----- (00466580) --------------------------------------------------------
int __cdecl sub_466580(_DWORD* a1) {
	_DWORD* v1;  // esi
	int v2;      // eax
	__int16* v3; // eax
	int v5;      // [esp+4h] [ebp-Ch]
	int v6;      // [esp+8h] [ebp-8h]
	int v7;      // [esp+Ch] [ebp-4h]

	v1 = a1;
	nox_client_wndGetPosition_46AA60(a1, &v5, &a1);
	nox_window_get_size((int)v1, &v7, &v6);
	if (byte_5D4594[1049868])
		v2 = v1[19];
	else
		v2 = v1[15];
	nox_client_drawImageAt_47D2C0(v2, v5, (int)a1);
	sub_434390(*(int*)&byte_5D4594[2523948]);
	v3 = (__int16*)sub_42E8E0(35, 1);
	if (v3)
		sub_43F6E0(*(int*)&dword_5d4594_1063636, v3, v5 + 19, (int)a1 + 102);
	return 1;
}

//----- (00466620) --------------------------------------------------------
int __cdecl sub_466620(int a1, int a2, unsigned int a3) {
	wchar_t* v3; // eax
	int2 a2a;    // [esp+0h] [ebp-8h]

	a2a.field_4 = a3 >> 16;
	a2a.field_0 = (unsigned __int16)a3;
	v3 = sub_466660(a1, &a2a);
	sub_4776B0(v3);
	return 1;
}

// 466676: variable 'v2' is possibly undefined
// 4666FF: variable 'v6' is possibly undefined
// 466737: variable 'v10' is possibly undefined

// 4668C0: variable 'v11' is possibly undefined
// 466900: variable 'v13' is possibly undefined

//----- (00466950) --------------------------------------------------------
int __cdecl sub_466950(int a1) {
	_DWORD* v1;   // eax
	_DWORD* v3;   // eax
	_DWORD* v4;   // eax
	int v5[4];    // [esp+10h] [ebp-15Ch]
	char v6[332]; // [esp+20h] [ebp-14Ch]

	v5[1] = 0;
	v5[2] = 0;
	memset(v6, 0, sizeof(v6));
	v5[3] = 0;
	v5[0] = 0;
	*(_DWORD*)&v6[24] = 0;
	*(_DWORD*)&v6[48] = 0;
	*(_DWORD*)&v6[32] = *(_DWORD*)&byte_5D4594[1049940];
	*(_DWORD*)&v6[40] = *(_DWORD*)&byte_5D4594[1049944];
	*(_DWORD*)&v6[56] = *(_DWORD*)&byte_5D4594[1049944];
	*(_DWORD*)&v6[68] = 0x80000000;
	*(_DWORD*)&v6[8] = 1;
	*(_WORD*)&v6[72] = 0;
	*(_DWORD*)&v6[16] = a1;
	v1 = (_DWORD*)sub_4A91A0(a1, 1161, 522, 2, 20, 25, v6);
	*(_DWORD*)&byte_5D4594[1062500] = v1;
	if (!v1)
		return 0;
	sub_46B080(v1, 9102);
	memset(v6, 0, sizeof(v6));
	*(_DWORD*)&v6[32] = *(_DWORD*)&byte_5D4594[1049948];
	*(_DWORD*)&v6[24] = 0;
	*(_DWORD*)&v6[48] = 0;
	*(_DWORD*)&v6[40] = *(_DWORD*)&byte_5D4594[1049952];
	*(_DWORD*)&v6[56] = *(_DWORD*)&byte_5D4594[1049952];
	*(_DWORD*)&v6[68] = 0x80000000;
	*(_DWORD*)&v6[8] = 1;
	*(_WORD*)&v6[72] = 0;
	*(_DWORD*)&v6[16] = a1;
	v3 = (_DWORD*)sub_4A91A0(a1, 1161, 522, 148, 20, 25, v6);
	*(_DWORD*)&byte_5D4594[1062504] = v3;
	if (!v3)
		return 0;
	sub_46B080(v3, 9103);
	memset(v6, 0, sizeof(v6));
	v5[2] = 0;
	*(_DWORD*)&v6[20] = 0x80000000;
	*(_DWORD*)&v6[44] = 0x80000000;
	*(_DWORD*)&v6[28] = 0x80000000;
	*(_DWORD*)&v6[36] = 0x80000000;
	*(_DWORD*)&v6[52] = 0x80000000;
	*(_DWORD*)&v6[8] = 8;
	*(_DWORD*)&v6[16] = a1;
	v5[3] = 0;
	v5[0] = 0;
	v5[1] = 850;
	v4 = sub_4B4EE0(a1, 1033, 524, 42, 16, 91, v6, (float*)v5);
	dword_5d4594_1062508 = v4;
	if (!v4)
		return 0;
	sub_46B300((int)v4, sub_466BF0);
	sub_46B300(*(_DWORD*)(dword_5d4594_1062508 + 400), sub_466BA0);
	*(_DWORD*)(*(_DWORD*)(dword_5d4594_1062508 + 400) + 8) = 16;
	*(_DWORD*)(*(_DWORD*)(dword_5d4594_1062508 + 400) + 12) = 16;
	sub_46AE40(*(_DWORD*)(dword_5d4594_1062508 + 400), 0, -15);
	sub_4B5700(*(int*)&dword_5d4594_1062508, 0, 0, *(int*)&byte_5D4594[1049956], *(int*)&byte_5D4594[1049960],
		   *(int*)&byte_5D4594[1049960]);
	return 1;
}

//----- (00466BA0) --------------------------------------------------------
int __cdecl sub_466BA0(_DWORD* a1, int a2, unsigned int a3, int a4) {
	int result; // eax

	if (*(_DWORD*)&byte_5D4594[1049848])
		result = sub_464BD0((int)a1, a2, a3);
	else
		result = sub_4A7F50(a1, a2, a3, a4);
	return result;
}

//----- (00466BF0) --------------------------------------------------------
int __cdecl sub_466BF0(int a1, int a2, unsigned int a3, int a4) {
	int result; // eax

	if (*(_DWORD*)&byte_5D4594[1049848])
		result = sub_464BD0(a1, a2, a3);
	else
		result = sub_4B4BA0(a1, a2, a3, a4);
	return result;
}

//----- (00466C40) --------------------------------------------------------
int __cdecl sub_466C40(int a1) {
	_DWORD* v1;   // eax
	_DWORD* v3;   // eax
	_DWORD* v4;   // eax
	char v5[332]; // [esp+Ch] [ebp-14Ch]

	memset(v5, 0, sizeof(v5));
	*(_DWORD*)&v5[24] = 0;
	*(_DWORD*)&v5[48] = 0;
	*(_DWORD*)&v5[32] = 0;
	*(_DWORD*)&v5[40] = 0;
	*(_DWORD*)&v5[56] = *(_DWORD*)&byte_5D4594[1049976];
	*(_DWORD*)&v5[60] = -243;
	*(_DWORD*)&v5[64] = -170;
	*(_DWORD*)&v5[16] = a1;
	*(_DWORD*)&v5[8] = 1;
	v1 = (_DWORD*)sub_4A91A0(a1, 1161, 243, 170, 34, 34, v5);
	*(_DWORD*)&byte_5D4594[1062528] = v1;
	if (!v1)
		return 0;
	sub_46B080(v1, 9105);
	sub_46B070(*(int*)&byte_5D4594[1062528], sub_466E20);
	memset(v5, 0, sizeof(v5));
	*(_DWORD*)&v5[24] = *(_DWORD*)&byte_5D4594[1049992];
	*(_DWORD*)&v5[48] = 0;
	*(_DWORD*)&v5[32] = 0;
	*(_DWORD*)&v5[40] = 0;
	*(_DWORD*)&v5[56] = *(_DWORD*)&byte_5D4594[1049996];
	*(_DWORD*)&v5[60] = -5;
	*(_DWORD*)&v5[64] = -186;
	*(_DWORD*)&v5[16] = a1;
	*(_DWORD*)&v5[8] = 1;
	v3 = (_DWORD*)sub_4A91A0(a1, 1161, 5, 186, 34, 34, v5);
	*(_DWORD*)&byte_5D4594[1062524] = v3;
	if (!v3)
		return 0;
	sub_46B080(v3, 9107);
	sub_46B070(*(int*)&byte_5D4594[1062524], sub_466E20);
	memset(v5, 0, sizeof(v5));
	*(_DWORD*)&v5[24] = 0;
	*(_DWORD*)&v5[48] = 0;
	*(_DWORD*)&v5[32] = 0;
	*(_DWORD*)&v5[40] = 0;
	*(_DWORD*)&v5[56] = *(_DWORD*)&byte_5D4594[1049972];
	*(_DWORD*)&v5[60] = -547;
	*(_DWORD*)&v5[64] = -2;
	*(_DWORD*)&v5[16] = a1;
	*(_DWORD*)&v5[8] = 1;
	v4 = (_DWORD*)sub_4A91A0(a1, 1161, 547, 2, 16, 16, v5);
	*(_DWORD*)&byte_5D4594[1062532] = v4;
	if (!v4)
		return 0;
	sub_46B080(v4, 9111);
	sub_46B070(*(int*)&byte_5D4594[1062532], sub_466E20);
	return 1;
}

//----- (00466ED0) --------------------------------------------------------
int __cdecl sub_466ED0(int a1) {
	int result; // eax
	_DWORD* v2; // eax

	result = nox_new_window_from_file("identify.wnd", 0);
	*(_DWORD*)&byte_5D4594[1062476] = result;
	if (result) {
		sub_46AB20((_DWORD*)result, 200, 200);
		sub_46B120(*(_DWORD**)&byte_5D4594[1062476], a1);
		sub_46A9B0(*(_DWORD**)&byte_5D4594[1062476], 51, 15);
		v2 = sub_46B0C0(*(_DWORD**)&byte_5D4594[1062476], 9155);
		sub_46B340((int)v2, sub_466F50);
		result = 1;
	}
	return result;
}

//----- (00466F50) --------------------------------------------------------
int __cdecl sub_466F50(_DWORD* a1, int* a2) {
	int v3;      // ecx
	_DWORD* v4;  // eax
	int v5;      // ecx
	_DWORD* v6;  // ebx
	int v7;      // edx
	int v8;      // edi
	int v9;      // ebp
	_BYTE* v10;  // esi
	int* v11;    // edi
	_BYTE** v12; // esi
	int v13;     // ebx
	_BYTE* v14;  // eax
	int v15;     // [esp+0h] [ebp-8h]
	int v16;     // [esp+4h] [ebp-4h]

	if (!dword_5d4594_1063116)
		return 1;
	v3 = *(_DWORD*)(dword_5d4594_1063116 + 112);
	if (v3 & 0x13001000) {
		v4 = v3 & 0x11001000 ? sub_413250(*(_DWORD*)(dword_5d4594_1063116 + 108))
				     : sub_413270(*(_DWORD*)(dword_5d4594_1063116 + 108));
		v6 = v4;
		if (v4) {
			v7 = dword_5d4594_1063116;
			v8 = 1;
			v9 = dword_5d4594_1063116 + 432;
			v10 = v4 + 4;
			do {
				LOBYTE(v4) = v10[1];
				LOBYTE(v5) = *v10;
				LOBYTE(v7) = *(v10 - 1);
				sub_4340A0(v8++, v7, v5, (int)v4);
				v10 += 3;
			} while (v8 < 7);
			v11 = v6 + 9;
			v12 = (_BYTE**)v9;
			v13 = 4;
			do {
				v14 = *v12;
				if (*v12) {
					LOBYTE(v5) = v14[26];
					LOBYTE(v7) = v14[25];
					LOBYTE(v14) = v14[24];
					sub_4340A0(*v11, (int)v14, v7, v5);
				}
				++v12;
				++v11;
				--v13;
			} while (v13);
		}
	}
	nox_client_wndGetPosition_46AA60(a1, &v15, &v16);
	nox_client_drawImageAt_47D2C0(a2[6], a2[15] + v15, a2[16] + v16);
	return 1;
}
// 466FBD: variable 'v7' is possibly undefined
// 466FBD: variable 'v5' is possibly undefined

//----- (00467050) --------------------------------------------------------
char* sub_467050() {
	char* result; // eax

	*(_DWORD*)&byte_5D4594[1049908] = sub_42F970("InventoryBase");
	*(_DWORD*)&byte_5D4594[1049912] = sub_42F970("InventoryIdentifyBase");
	*(_DWORD*)&byte_5D4594[1049916] = sub_42F970("InventoryTray1");
	*(_DWORD*)&byte_5D4594[1049920] = sub_42F970("InventoryTray2");
	*(_DWORD*)&byte_5D4594[1049924] = sub_42F970("InventoryTray3");
	*(_DWORD*)&byte_5D4594[1049928] = sub_42F970("InventoryTraySpecial");
	*(_DWORD*)&byte_5D4594[1049932] = sub_42F970("InventoryTrayIdentifyLit");
	*(_DWORD*)&byte_5D4594[1049936] = sub_42F970("InventoryTrayMapLit");
	*(_DWORD*)&byte_5D4594[1049940] = sub_42F970("InventoryUpButton");
	*(_DWORD*)&byte_5D4594[1049944] = sub_42F970("InventoryUpButtonLit");
	*(_DWORD*)&byte_5D4594[1049948] = sub_42F970("InventoryDownButton");
	*(_DWORD*)&byte_5D4594[1049952] = sub_42F970("InventoryDownButtonLit");
	*(_DWORD*)&byte_5D4594[1049956] = sub_42F970("InventorySliderButton");
	*(_DWORD*)&byte_5D4594[1049960] = sub_42F970("InventorySliderButtonLit");
	*(_DWORD*)&byte_5D4594[1049964] = sub_42F970("InventoryEquipRing");
	*(_DWORD*)&byte_5D4594[1049968] = sub_42F970("InventoryQuickItemRing");
	*(_DWORD*)&byte_5D4594[1049972] = sub_42F970("InventoryCloseButtonLit");
	*(_DWORD*)&byte_5D4594[1049976] = sub_42F970("InventoryJournalButtonLit");
	*(_DWORD*)&byte_5D4594[1049980] = sub_42F970("InventoryInventoryButton");
	*(_DWORD*)&byte_5D4594[1049984] = sub_42F970("InventoryInventoryButtonLit");
	*(_DWORD*)&byte_5D4594[1049988] = sub_42F970("InventoryDollButtonLit");
	*(_DWORD*)&byte_5D4594[1049992] = sub_42F970("InventoryStatsButton");
	*(_DWORD*)&byte_5D4594[1049996] = sub_42F970("InventoryStatsButtonLit");
	*(_DWORD*)&byte_5D4594[1050000] = sub_42F970("GUIFist");
	*(_DWORD*)&byte_5D4594[1050004] = sub_42F970("SharedKeyMode");
	result = sub_42FA20("ExtraLives");
	*(_DWORD*)&byte_5D4594[1050008] = result;
	return result;
}

//----- (004672C0) --------------------------------------------------------
int sub_4672C0() {
	int result; // eax
	int v1;     // edi
	int v2;     // eax
	_DWORD* v3; // edx
	int v4;     // eax
	int i;      // esi
	int v6;     // eax

	result = *(_DWORD*)&byte_5D4594[2614252];
	if (!*(_DWORD*)&byte_5D4594[2614252])
		return result;
	result = sub_477600();
	if (result)
		return result;
	result = sub_461160(1);
	if (result)
		return result;
	v1 = *(_DWORD*)&byte_5D4594[2618908];
	if (!*(_DWORD*)&byte_5D4594[2618908])
		return result;
	result = *(_DWORD*)&byte_5D4594[2614252];
	if (*(_DWORD*)(*(_DWORD*)&byte_5D4594[2614252] + 276) == 34)
		return result;
	v2 = sub_4281F0((int2*)&byte_5D4594[1062572], (int4*)&byte_587000[136336]);
	if (v2 == 1)
		sub_477690(0);
	v3 = *(_DWORD**)&dword_5d4594_1062480;
	if (dword_5d4594_1062480) {
		if (sub_415880(*(char**)(**(_DWORD**)&dword_5d4594_1062480 + 108)) == 2) {
			v4 = sub_415840((char*)2);
			result = sub_461600(v4);
			if (result) {
			LABEL_11:
				*(_DWORD*)&byte_5D4594[1062492] = result;
				sub_464B70(result);
				result = sub_452D80(895, 100);
			}
			return result;
		}
		v3 = *(_DWORD**)&dword_5d4594_1062480;
	}
	for (i = 1; i < 27; ++i) {
		result = 1 << i;
		if (1 << i != 2 && result & *(_DWORD*)(v1 + 4)) {
			v6 = sub_415840((char*)(1 << i));
			result = sub_461600(v6);
			if (result)
				goto LABEL_11;
			v3 = *(_DWORD**)&dword_5d4594_1062480;
		}
	}
	if (v3) {
		*(_DWORD*)(*v3 + 128) = v3[1];
		sub_4623B0(**(_DWORD**)&dword_5d4594_1062480);
		result = sub_452D80(895, 100);
	}
	return result;
}
// 467323: variable 'v2' is possibly undefined

//----- (004673F0) --------------------------------------------------------
int __cdecl sub_4673F0(int a1, int a2) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[1062580] = a1;
	*(_DWORD*)&byte_5D4594[1062584] = a2;
	return result;
}

//----- (00467410) --------------------------------------------------------
int __cdecl sub_467410(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[1062540] = a1;
	return result;
}

//----- (00467420) --------------------------------------------------------
char __cdecl sub_467420(char a1) {
	char result; // al

	result = a1;
	byte_5D4594[1062536] = a1;
	return result;
}

//----- (00467430) --------------------------------------------------------
unsigned __int8 sub_467430() { return byte_5D4594[1062536]; }

//----- (00467440) --------------------------------------------------------
int __cdecl sub_467440(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[1062544] = a1;
	return result;
}

//----- (00467450) --------------------------------------------------------
int __cdecl sub_467450(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[1062548] = a1;
	return result;
}

//----- (00467470) --------------------------------------------------------
int __cdecl sub_467470(int a1, float a2) {
	int result; // eax

	result = (unsigned __int8)a1;
	*(float*)&byte_5D4594[4 * (unsigned __int8)a1 + 1063100] = a2;
	return result;
}

//----- (00467490) --------------------------------------------------------
int __cdecl sub_467490(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[1062552] = a1;
	return result;
}

//----- (004674A0) --------------------------------------------------------
int sub_4674A0() { return *(_DWORD*)&byte_5D4594[1062552]; }

//----- (004674B0) --------------------------------------------------------
void __cdecl nox_window_set_visible_unk5(int visible) {
	if (visible)
		nox_window_set_hidden(nox_win_unk5, 0);
	else
		nox_window_set_hidden(nox_win_unk5, 1);
}

//----- (004674E0) --------------------------------------------------------
void __cdecl sub_4674E0(int a1) {
	if (sub_477600() != 1) {
		if (!sub_413A50()) {
			int result = sub_467520(a1);
			if (result) {
				*(_DWORD*)(*(_DWORD*)result + 128) = *((_DWORD*)result + 1);
				sub_465C70(*(_DWORD*)result);
			}
		}
	}
}

//----- (00467520) --------------------------------------------------------
char* __cdecl sub_467520(int a1) {
	int v1;              // esi
	unsigned __int8* v2; // edx
	int v3;              // eax
	unsigned __int8* v4; // ecx

	v1 = 0;
	v2 = &byte_5D4594[1050020];
	while (1) {
		v3 = 0;
		v4 = v2;
		do {
			if (v4[140] && *(_DWORD*)(*(_DWORD*)v4 + 108) == a1)
				return (char*)&byte_5D4594[148 * (v1 + 14 * v3 + 7 * v3) + 1050020];
			++v3;
			v4 += 3108;
		} while (v3 < 4);
		v2 += 148;
		++v1;
		if ((int)v2 <= (int)&byte_5D4594[1052980])
			continue;
		break;
	}
	return 0;
}

//----- (00467590) --------------------------------------------------------
int sub_467590() {
	int result; // eax

	if (*(_DWORD*)&byte_5D4594[2618908])
		result = *(char*)(*(_DWORD*)&byte_5D4594[2618908] + 3684);
	else
		result = 1;
	return result;
}

//----- (004675B0) --------------------------------------------------------
int sub_4675B0() { return dword_5d4594_1049864; }

//----- (004675C0) --------------------------------------------------------
int __cdecl sub_4675C0(int a1) {
	int result; // eax

	dword_5d4594_1049864 = a1;
	if (a1 == 5)
		result = sub_465CA0();
	else
		result = sub_462740();
	return result;
}

//----- (004675E0) --------------------------------------------------------
__int16 __cdecl sub_4675E0(int a1, __int16 a2, __int16 a3) {
	char* v3; // eax
	int v4;   // eax

	v3 = sub_461EF0(a1);
	if (v3) {
		*(_WORD*)(**(_DWORD**)v3 + 292) = a2;
		v4 = **(_DWORD**)v3;
		*(_WORD*)(v4 + 294) = a3;
	} else {
		LOWORD(v4) = *(_WORD*)&byte_5D4594[1049848];
		if (*(_DWORD*)&byte_5D4594[1049848] && *(_DWORD*)(*(_DWORD*)&byte_5D4594[1049848] + 128) == a1) {
			*(_WORD*)(*(_DWORD*)&byte_5D4594[1049848] + 292) = a2;
			LOWORD(v4) = a3;
			*(_WORD*)(*(_DWORD*)&byte_5D4594[1049848] + 294) = a3;
		}
	}
	return v4;
}

//----- (00467650) --------------------------------------------------------
int sub_467650() {
	int result; // eax

	sub_462740();
	dword_5d4594_1049864 = 6;
	nox_client_setCursorType_477610(8);
	result = sub_467C80();
	if (!result)
		result = sub_467BB0();
	return result;
}

//----- (00467680) --------------------------------------------------------
void sub_467680() {
	if (dword_5d4594_1049864 == 6)
		dword_5d4594_1049864 = 0;
}

//----- (004676A0) --------------------------------------------------------
int sub_4676A0() { return *(_DWORD*)&byte_5D4594[1062452]; }

//----- (004676B0) --------------------------------------------------------
char* sub_4676B0() { return (char*)&byte_587000[136384]; }

//----- (004676C0) --------------------------------------------------------
char* sub_4676C0() { return (char*)&byte_587000[136400]; }

//----- (004676D0) --------------------------------------------------------
int __cdecl sub_4676D0(int a1) {
	char* v1;   // eax
	int result; // eax

	v1 = sub_461EF0(a1);
	if (v1)
		return **(_DWORD**)v1;
	result = *(_DWORD*)&byte_5D4594[1049848];
	if (!*(_DWORD*)&byte_5D4594[1049848] || *(_DWORD*)(*(_DWORD*)&byte_5D4594[1049848] + 128) != a1)
		result = 0;
	return result;
}

//----- (00467700) --------------------------------------------------------
int __cdecl sub_467700(int a1) {
	char* v1; // eax

	v1 = sub_461EF0(a1);
	if (v1)
		return *(unsigned __int8*)(*(_DWORD*)v1 + 140);
	if (*(_DWORD*)&byte_5D4594[1049848] && *(_DWORD*)(*(_DWORD*)&byte_5D4594[1049848] + 128) == a1)
		return 1;
	return 0;
}

//----- (00467740) --------------------------------------------------------
int __cdecl sub_467740(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[1062488] = a1;
	return result;
}

//----- (00467810) --------------------------------------------------------
int __cdecl sub_467810(int a1, int a2) {
	int result; // eax

	if (a1 < 0 || a2 < 0 || a1 >= 4 || a2 >= 20)
		result = 0;
	else
		result = byte_5D4594[148 * (a2 + 14 * a1 + 7 * a1) + 1050160];
	return result;
}

//----- (00467850) --------------------------------------------------------
int __cdecl sub_467850(int a1) {
	char* v1;   // eax
	int result; // eax

	v1 = sub_467520(a1);
	if (v1)
		result = (unsigned __int8)v1[140];
	else
		result = 0;
	return result;
}

//----- (00467870) --------------------------------------------------------
char* __cdecl sub_467870(int a1, int a2) {
	char* result; // eax

	if (a1 < 0 || a2 < 0 || a1 >= 4 || a2 >= 20)
		result = 0;
	else
		result = (char*)&byte_5D4594[148 * (a2 + 14 * a1 + 7 * a1) + 1050024];
	return result;
}

//----- (004678B0) --------------------------------------------------------
int sub_4678B0() {
	int result; // eax

	if (dword_5d4594_1062480)
		result = *(_DWORD*)(dword_5d4594_1062480 + 4);
	else
		result = 0;
	return result;
}

//----- (004678C0) --------------------------------------------------------
int sub_4678C0() { return *(_DWORD*)&byte_5D4594[1062488]; }

//----- (004678D0) --------------------------------------------------------
int sub_4678D0() {
	int v0;     // edi
	int v1;     // esi
	int v2;     // eax
	int v3;     // eax
	int result; // eax
	char* v5;   // eax

	v0 = *(_DWORD*)&byte_5D4594[2618908];
	if (!*(_DWORD*)&byte_5D4594[2618908])
		goto LABEL_7;
	v1 = 1;
	while (1) {
		if (1 << v1 != 2) {
			if ((1 << v1) & *(_DWORD*)(v0 + 4)) {
				v2 = sub_415840((char*)(1 << v1));
				v3 = sub_461600(v2);
				if (v3)
					break;
			}
		}
		if (++v1 >= 27)
			goto LABEL_7;
	}
	v5 = sub_461EF0(*(_DWORD*)(v3 + 128));
	if (v5)
		result = **(_DWORD**)v5;
	else
	LABEL_7:
		result = 0;
	return result;
}

//----- (00467930) --------------------------------------------------------
char* __cdecl sub_467930(int a1, int a2, int a3) {
	char* result; // eax
	int v4;       // ecx

	result = (char*)a1;
	if (a1) {
		result = sub_461EF0(a1);
		if (result) {
			v4 = **(_DWORD**)result;
			*(_WORD*)(v4 + 448) = a2;
			*(_WORD*)(v4 + 450) = a3;
			result = *(char**)result;
			if (*((_DWORD*)result + 33) == 1)
				result = (char*)sub_470D90(a2, a3);
		}
	}
	return result;
}

//----- (00467980) --------------------------------------------------------
int sub_467980() {
	unsigned __int8* v0; // ebp
	unsigned __int8* v1; // esi
	int v2;              // edi

	v0 = &byte_5D4594[1050020];
	do {
		v1 = v0;
		v2 = 4;
		do {
			if (*(_DWORD*)v1) {
				sub_45A4B0(*(_QWORD**)v1);
				*(_DWORD*)v1 = 0;
			}
			v1[140] = 0;
			*((_DWORD*)v1 + 33) = 0;
			*((_DWORD*)v1 + 34) = 0;
			v1 += 3108;
			--v2;
		} while (v2);
		v0 += 148;
	} while ((int)v0 <= (int)&byte_5D4594[1052980]);
	sub_462740();
	dword_5d4594_1049864 = 0;
	sub_461550(0);
	*(_DWORD*)&byte_5D4594[1062488] = 0;
	memset(&byte_5D4594[1049872], 0, 0x24u);
	*(_DWORD*)&byte_5D4594[1062492] = 0;
	*(_DWORD*)&byte_5D4594[1062496] = 0;
	byte_5D4594[1062536] = 0;
	*(_DWORD*)&byte_5D4594[1062540] = 0;
	*(_DWORD*)&byte_5D4594[1062544] = 0;
	*(_DWORD*)&byte_5D4594[1062548] = 0;
	*(_DWORD*)&byte_5D4594[1062552] = 0;
	sub_472310();
	*(_DWORD*)&byte_587000[136184] = -225;
	byte_5D4594[1049868] = 0;
	byte_5D4594[1049869] = 0;
	*(_DWORD*)&byte_5D4594[1062516] = 0;
	*(_DWORD*)&byte_5D4594[1062520] = 0;
	dword_5d4594_1062512 = 0;
	nox_window_call_field_94(*(int*)&dword_5d4594_1062508, 16395, 0, 850);
	nox_window_call_field_94(
	    *(int*)&dword_5d4594_1062508, 16394,
	    *(_DWORD*)(*(_DWORD*)(dword_5d4594_1062508 + 32) + 4) - dword_5d4594_1062512, 0);
	sub_46AE60(*(int*)&byte_5D4594[1062528], 0);
	sub_46AEC0(*(int*)&byte_5D4594[1062528], *(int*)&byte_5D4594[1049976]);
	sub_46B080(*(_DWORD**)&byte_5D4594[1062528], 9105);
	byte_5D4594[1049870] = 0;
	sub_46AE60(*(int*)&byte_5D4594[1062524], *(int*)&byte_5D4594[1049992]);
	sub_46AEC0(*(int*)&byte_5D4594[1062524], *(int*)&byte_5D4594[1049996]);
	sub_46B080(*(_DWORD**)&byte_5D4594[1062524], 9107);
	return nox_window_set_hidden(*(int*)&byte_5D4594[1062468], 0);
}

//----- (00467B00) --------------------------------------------------------
int __cdecl sub_467B00(int a1, int a2) {
	int v2;              // ebx
	unsigned __int8* v3; // ebp
	int i;               // esi
	int v5;              // edi
	int v6;              // eax
	int v8;              // [esp+10h] [ebp-8h]
	unsigned __int8* v9; // [esp+14h] [ebp-4h]

	v2 = 0;
	v8 = 0;
	v9 = &byte_5D4594[1050020];
	do {
		v3 = v9;
		for (i = 0; i < 4; ++i) {
			v5 = sub_467810(i, v2);
			if (!v5)
				goto LABEL_15;
			if (*(_DWORD*)(*(_DWORD*)v3 + 108) == a1) {
				v6 = 31;
				if (*(_BYTE*)(*(_DWORD*)v3 + 112) & 0x10)
					v6 = nox_common_gameFlags_check_40A5C0(6144) ? 9 : 3;
				if (!(*(_DWORD*)(*(_DWORD*)v3 + 112) & 0x4000000) && a2 + v5 <= v6)
				LABEL_15:
					++v8;
			}
			v3 += 3108;
		}
		++v2;
		v9 += 148;
	} while ((int)v9 < (int)&byte_5D4594[1052980]);
	return v8;
}

//----- (00467BB0) --------------------------------------------------------
int sub_467BB0() {
	int result; // eax

	result = sub_446360();
	if (!result) {
		result = sub_4AE3D0();
		if (!result) {
			result = sub_477600();
			if (!result) {
				result = sub_4372B0();
				if (!result) {
					result = sub_57AF20();
					if (!result) {
						if (byte_5D4594[1049868] == 3 || !byte_5D4594[1049868]) {
							byte_5D4594[1049868] = 1;
							sub_452D80(789, 100);
						}
						result = *(_DWORD*)&byte_5D4594[1062516];
						dword_5d4594_1062512 = *(_DWORD*)&byte_5D4594[1062516];
					}
				}
			}
		}
	}
	return result;
}

//----- (00467C10) --------------------------------------------------------
int sub_467C10() {
	if (dword_5d4594_1049864 == 6)
		return 1;
	if (!sub_467C80())
		return 0;
	byte_5D4594[1049868] = 3;
	sub_452D80(790, 100);
	if (dword_5d4594_1049864 == 5)
		sub_462740();
	sub_467CD0();
	return 1;
}

//----- (00467C60) --------------------------------------------------------
int sub_467C60() {
	int result; // eax

	if (sub_467C80())
		result = sub_467C10();
	else
		result = sub_467BB0();
	return result;
}

//----- (00467C80) --------------------------------------------------------
BOOL sub_467C80() { return byte_5D4594[1049868] == 1 || byte_5D4594[1049868] == 2; }

//----- (00467CA0) --------------------------------------------------------
int sub_467CA0() {
	int result; // eax

	result = sub_467C80();
	if (!result) {
		*(_DWORD*)&byte_5D4594[1062516] = 0;
		result = dword_5d4594_1062508;
		if (dword_5d4594_1062508)
			result = nox_window_call_field_94(
			    *(int*)&dword_5d4594_1062508, 16394,
			    *(_DWORD*)(*(_DWORD*)(dword_5d4594_1062508 + 32) + 4), 0);
	}
	return result;
}

//----- (00467CD0) --------------------------------------------------------
int sub_467CD0() {
	int v0;              // esi
	char* v1;            // eax
	char* v2;            // edi
	unsigned __int8* v3; // ebx
	int v4;              // eax
	int v5;              // eax
	int v6;              // eax

	v0 = 0;
	if (*(_DWORD*)&byte_5D4594[1049848]) {
		if (!*(_DWORD*)&byte_5D4594[1049856] &&
		    !sub_4649B0(*(int*)&byte_5D4594[1049848], *(int*)&dword_5d4594_1049796,
				*(int*)&dword_5d4594_1049800)) {
			sub_461660(*(_DWORD*)(*(_DWORD*)&byte_5D4594[1049848] + 128),
				   *(_DWORD*)(*(_DWORD*)&byte_5D4594[1049848] + 108),
				   (const void*)(*(_DWORD*)&byte_5D4594[1049848] + 432));
			v1 = sub_461EF0(*(_DWORD*)(*(_DWORD*)&byte_5D4594[1049848] + 128));
			v2 = v1;
			if (v1) {
				v3 = &byte_5D4594[1049872];
				*(_DWORD*)(*(_DWORD*)v1 + 132) = 0;
				do {
					v4 = *(_DWORD*)v3;
					if (*(_DWORD*)v3) {
						while (*(_DWORD*)(v4 + 128) !=
						       *(_DWORD*)(*(_DWORD*)&byte_5D4594[1049848] + 128)) {
							v4 = *(_DWORD*)(v4 + 368);
							if (!v4)
								goto LABEL_12;
						}
						*(_DWORD*)(*(_DWORD*)v2 + 132) = 1;
						if (*(_DWORD*)(*(_DWORD*)v2 + 136)) {
							sub_461550(0);
							*(_DWORD*)(*(_DWORD*)v2 + 136) = 0;
						}
					}
				LABEL_12:
					v3 += 4;
				} while ((int)v3 < (int)&byte_5D4594[1049908]);
			}
		}
		*(_DWORD*)&byte_5D4594[1049848] = 0;
		*(_DWORD*)&byte_5D4594[1049856] = 0;
		sub_4776A0();
		v0 = 1;
	}
	v5 = sub_46AE00();
	if (nox_window_is_child(*(int*)&byte_5D4594[1062452], v5) == 1) {
		v6 = sub_46AE00();
		sub_46ADE0(v6);
	}
	return v0;
}

//----- (00467DF0) --------------------------------------------------------
int __cdecl sub_467DF0(int a1) {
	int result; // eax
	int v4[3];  // [esp+0h] [ebp-Ch]

	v4[0] = 25;
	v4[1] = 25;
	v4[2] = 25;
	sub_4460A0(0);
	if (sub_47A260() == 1)
		sub_47A1F0();
	if (sub_478030() == 1)
		sub_479280();
	sub_45D810();
	sub_4B8220();
	nox_alloc_npcs_2();
	sub_4573B0();
	if (!nox_common_gameFlags_check_40A5C0(1)) {
		sub_469B90(v4);
		sub_4349C0(v4);
		sub_421B10();
	}
	sub_49C4B0();
	sub_49C4F0();
	sub_49A630();
	sub_49BBB0();
	sub_431510();
	sub_45A5E0(a1);
	result = nox_common_gameFlags_check_40A5C0(1);
	if (!result) {
		sub_410160();
		for (int i = 0; i < ptr_5D4594_2650668_cap * 44; i += 44) {
			for (int j = 0; j < ptr_5D4594_2650668_cap; j++) {
				*(_BYTE*)((_DWORD)(ptr_5D4594_2650668[j]) + i) = 0;
				*(_DWORD*)((_DWORD)(ptr_5D4594_2650668[j]) + i + 4) = 255;
				*(_DWORD*)((_DWORD)(ptr_5D4594_2650668[j]) + i + 24) = 255;
				sub_422200((_DWORD)(ptr_5D4594_2650668[j]) + i + 4);
				result = sub_422200((_DWORD)(ptr_5D4594_2650668[j]) + i + 24);
			}
		}
	}
	return result;
}
// 49A2F0: using guessed type int __cdecl nox_alloc_npcs_2(_DWORD, _DWORD, _DWORD);

//----- (00467F30) --------------------------------------------------------
int sub_467F30() {
	dword_5d4594_1064192 = nox_new_window_from_file("wolProg.wnd", sub_467FC0);
	nox_window_set_all_funcs(*(_DWORD**)&dword_5d4594_1064192, sub_467F70, 0, 0);
	sub_46A8A0();
	sub_4680B0();
	return 1;
}

//----- (00467F70) --------------------------------------------------------
int __cdecl sub_467F70(int a1, int a2, int a3, int a4) {
	if (a2 != 21)
		return 0;
	if (a3 != 1)
		return 0;
	if (a4 == 2) {
		sub_452D80(231, 100);
		if (dword_5d4594_815132)
			sub_4207F0(1);
	}
	return 1;
}

//----- (00467FC0) --------------------------------------------------------
int __cdecl sub_467FC0(int a1, int a2, int* a3, int a4) {
	int result; // eax
	int v4;     // eax

	if (a2 == 16389) {
		sub_452D80(920, 100);
		result = 1;
	} else if (a2 == 16391) {
		v4 = sub_46B0A0(a3);
		if (v4 >= 1806 && v4 <= 1807)
			sub_468020();
		sub_452D80(921, 100);
		result = 1;
	} else {
		result = 0;
	}
	return result;
}

//----- (00468020) --------------------------------------------------------
void sub_468020() {
	sub_46B0C0(0, 1700);
	if (dword_5d4594_815132) {
		sub_468060();
		sub_4207F0(1);
		sub_44A560_wol_login();
		sub_40E0A0();
	}
}

//----- (00468060) --------------------------------------------------------
int sub_468060() {
	int result; // eax

	result = dword_5d4594_1064192;
	if (dword_5d4594_1064192) {
		result = sub_46C4E0(*(_DWORD**)&dword_5d4594_1064192);
		dword_5d4594_1064192 = 0;
	}
	return result;
}

//----- (00468080) --------------------------------------------------------
int sub_468080() {
	int result; // eax
	_DWORD* v1; // esi

	result = dword_5d4594_1064192;
	if (dword_5d4594_1064192) {
		v1 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1064192, 1802);
		nox_window_set_hidden((int)v1, 0);
		result = v1[9];
		LOBYTE(result) = result | 4;
		v1[9] = result;
	}
	return result;
}

//----- (004680B0) --------------------------------------------------------
int sub_4680B0() {
	int result; // eax
	_DWORD* v1; // esi

	result = dword_5d4594_1064192;
	if (dword_5d4594_1064192) {
		v1 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1064192, 1801);
		nox_window_set_hidden((int)v1, 0);
		result = v1[9];
		LOBYTE(result) = result | 4;
		v1[9] = result;
	}
	return result;
}

//----- (004680E0) --------------------------------------------------------
int sub_4680E0() {
	int result; // eax
	_DWORD* v1; // esi

	result = dword_5d4594_1064192;
	if (dword_5d4594_1064192) {
		v1 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1064192, 1803);
		nox_window_set_hidden((int)v1, 0);
		result = v1[9];
		LOBYTE(result) = result | 4;
		v1[9] = result;
	}
	return result;
}

//----- (00468340) --------------------------------------------------------
int sub_468340() {
	_DWORD* v0;  // esi
	wchar_t* v1; // eax
	_DWORD* v2;  // eax
	_DWORD* v3;  // eax

	if (dword_5d4594_1064192) {
		v0 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1064192, 1805);
		v1 = sub_41E5D0();
		if (v1)
			nox_window_call_field_94((int)v0, 16385, (int)v1, 0);
	}
	v2 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1064192, 1806);
	nox_window_set_hidden((int)v2, 1);
	v3 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1064192, 1807);
	return nox_window_set_hidden((int)v3, 0);
}

//----- (004683B0) --------------------------------------------------------
int sub_4683B0() {
	_DWORD* v0; // eax
	_DWORD* v1; // eax

	nox_set_draw_unk1(sub_41E210);
	dword_5d4594_1064816 = nox_new_window_from_file("wolreg.wnd", sub_4685D0);
	nox_window_set_all_funcs(*(_DWORD**)&dword_5d4594_1064816, sub_468480, 0, 0);
	*(_DWORD*)&byte_5D4594[1064820] = sub_46B0C0(*(_DWORD**)&dword_5d4594_1064816, 1755);
	*(_DWORD*)&byte_5D4594[1064824] = sub_46B0C0(*(_DWORD**)&dword_5d4594_1064816, 1756);
	*(_DWORD*)&byte_5D4594[1064828] = sub_46B0C0(*(_DWORD**)&dword_5d4594_1064816, 1754);
	v0 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1064816, 1766);
	v0[9] |= 4u;
	v1 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1064816, 1767);
	v1[9] |= 4u;
	dword_5d4594_1064296 = 0;
	sub_46ABB0(*(int*)&dword_5d4594_1064816, 1);
	return 1;
}

//----- (00468480) --------------------------------------------------------
int __cdecl sub_468480(int a1, int a2, int a3, int a4) {
	if (a2 != 21)
		return 0;
	if (a3 != 1)
		return 0;
	if (a4 == 2) {
		sub_452D80(231, 100);
		sub_4684C0();
	}
	return 1;
}

//----- (004684C0) --------------------------------------------------------
int sub_4684C0() {
	_DWORD* v0; // esi
	int result; // eax

	v0 = sub_46B0C0(0, 1700);
	result = dword_5d4594_1064296;
	switch (dword_5d4594_1064296) {
	case 0:
		sub_41E300(5);
		sub_4207F0(1);
		sub_46ABB0((int)v0, 1);
		sub_4A1BE0(1);
		result = sub_4A1A40(0);
		break;
	case 1:
		dword_5d4594_1064296 = 0;
		nox_window_set_hidden(*(int*)&byte_5D4594[1064824], 1);
		result = nox_window_set_hidden(*(int*)&byte_5D4594[1064820], 0);
		break;
	case 2:
		dword_5d4594_1064296 = 0;
		nox_window_set_hidden(*(int*)&byte_5D4594[1064828], 1);
		result = nox_window_set_hidden(*(int*)&byte_5D4594[1064820], 0);
		break;
	case 3:
		dword_5d4594_1064296 = 1;
		nox_window_set_hidden(*(int*)&byte_5D4594[1064828], 1);
		result = nox_window_set_hidden(*(int*)&byte_5D4594[1064824], 0);
		break;
	case 4:
		sub_41E300(5);
		sub_4207F0(1);
		sub_46ABB0((int)v0, 1);
		result = sub_4A1BE0(1);
		break;
	default:
		return result;
	}
	return result;
}

//----- (004685D0) --------------------------------------------------------
int __cdecl sub_4685D0(int a1, int a2, int* a3, int a4) {
	int result;        // eax
	int v4;            // esi
	int v5;            // eax
	int v6;            // [esp+0h] [ebp-2FCh]
	int v7;            // [esp+4h] [ebp-2F8h]
	int v8;            // [esp+8h] [ebp-2F4h]
	char v9[80];       // [esp+Ch] [ebp-2F0h]
	char v10[80];      // [esp+5Ch] [ebp-2A0h]
	char v11[80];      // [esp+ACh] [ebp-250h]
	wchar_t File[256]; // [esp+FCh] [ebp-200h]

	if (a2 == 16389) {
		sub_452D80(920, 100);
		return 1;
	}
	if (a2 != 16391) {
		if (a2 == 16415)
			sub_46B0A0(a3);
		return 0;
	}
	v4 = sub_46B0A0(a3);
	sub_452D80(921, 100);
	if (v4 != 1752) {
		if (v4 == 1753) {
			sub_4684C0();
			return 1;
		}
		return 1;
	}
	switch (dword_5d4594_1064296) {
	case 0:
		if (sub_468BB0_wol_reg(&v7, &v6, &v8, File)) {
			*(_DWORD*)&byte_5D4594[1064300] = 0;
			sub_40E020(v7, v6, v8, (int)&byte_5D4594[1064196]);
			sub_46ABB0(*(int*)&dword_5d4594_1064816, 0);
		} else {
			nox_window_set_hidden(*(int*)&byte_5D4594[1064820], 1);
			sub_468840(File);
			dword_5d4594_1064296 = 2;
		}
		result = 1;
		break;
	case 1:
		if (sub_468890_wol_reg(v10, v11, v9, &v6, &v7, File)) {
			sub_40DFE0((int)v10, (int)v11, (int)&byte_5D4594[1064196], (int)v9, (unsigned __int8)v6,
				   (unsigned __int8)v7);
			sub_46ABB0(*(int*)&dword_5d4594_1064816, 0);
		} else {
			nox_window_set_hidden(*(int*)&byte_5D4594[1064824], 1);
			sub_468840(File);
			dword_5d4594_1064296 = 3;
		}
		result = 1;
		break;
	case 4:
		v5 = sub_4200F0();
		nox_sprintf((char*)File, "http://apiregister.westwood.com/consent_form/index_%d.html", v5);
		ShellExecuteA(0, 0, (LPCSTR)File, 0, (LPCSTR)&byte_587000[141188], 3);
		result = 1;
		break;
	case 5:
		sub_41E300(5);
		sub_4207F0(1);
		sub_44A560_wol_login();
		result = 1;
		break;
	default:
		return 1;
	}
	return result;
}

//----- (00468840) --------------------------------------------------------
int __cdecl sub_468840(wchar_t* a1) {
	_DWORD* v1; // eax

	nox_wcscpy((wchar_t*)&byte_5D4594[1064304], a1);
	nox_window_set_hidden(*(int*)&byte_5D4594[1064828], 0);
	v1 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1064816, 1768);
	return nox_window_call_field_94((int)v1, 16385, (int)&byte_5D4594[1064304], 6);
}

//----- (00468DC0) --------------------------------------------------------
int sub_468DC0() {
	int result; // eax

	result = dword_5d4594_1064816;
	if (dword_5d4594_1064816) {
		result = sub_46C4E0(*(_DWORD**)&dword_5d4594_1064816);
		dword_5d4594_1064816 = 0;
		*(_DWORD*)&byte_5D4594[1064820] = 0;
		*(_DWORD*)&byte_5D4594[1064824] = 0;
		*(_DWORD*)&byte_5D4594[1064828] = 0;
	}
	return result;
}

//----- (00468DF0) --------------------------------------------------------
int __cdecl sub_468DF0(wchar_t* a1) {
	sub_46ABB0(*(int*)&dword_5d4594_1064816, 1);
	if (dword_5d4594_1064296) {
		if (dword_5d4594_1064296 == 1) {
			dword_5d4594_1064296 = 3;
			nox_window_set_hidden(*(int*)&byte_5D4594[1064824], 1);
			return sub_468840(a1);
		}
	} else {
		dword_5d4594_1064296 = 2;
		nox_window_set_hidden(*(int*)&byte_5D4594[1064820], 1);
	}
	return sub_468840(a1);
}

//----- (00468E60) --------------------------------------------------------
int __cdecl sub_468E60(int a1) {
	int result; // eax
	_DWORD* v2; // esi
	_DWORD* v3; // eax

	sub_46ABB0(*(int*)&dword_5d4594_1064816, 1);
	result = dword_5d4594_1064296;
	if (dword_5d4594_1064296) {
		if (dword_5d4594_1064296 == 1) {
			v3 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1064816, 1753);
			nox_window_set_hidden((int)v3, 1);
			nox_window_set_hidden(*(int*)&byte_5D4594[1064824], 1);
			result = sub_468840((wchar_t*)&byte_5D4594[2660140]);
			dword_5d4594_1064296 = 5;
		}
	} else {
		v2 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1064816, 1765);
		*(_DWORD*)&byte_5D4594[1064300] = a1;
		dword_5d4594_1064296 = 1;
		nox_window_set_hidden(*(int*)&byte_5D4594[1064820], 1);
		nox_window_set_hidden(*(int*)&byte_5D4594[1064824], 0);
		if (*(_DWORD*)&byte_5D4594[1064300])
			result = nox_window_set_hidden((int)v2, 0);
		else
			result = nox_window_set_hidden((int)v2, 1);
	}
	return result;
}

//----- (00469920) --------------------------------------------------------
char* __cdecl sub_469920(_DWORD* a1) {
	int v1;       // esi
	int v2;       // edi
	int v3;       // ecx
	int v4;       // ebx
	int v5;       // esi
	int v6;       // ecx
	int v7;       // ebp
	int v10;      // ebx
	int v11;      // eax
	int v12;      // edi
	int v13;      // ecx
	char* result; // eax
	int v16;      // [esp+18h] [ebp-Ch]
	int v17;      // [esp+1Ch] [ebp-8h]
	int v18;      // [esp+20h] [ebp-4h]

	if (nox_common_engineFlags & 0x800)
		return (char*)&byte_587000[142336];
	v1 = *a1 - *(_DWORD*)&byte_5D4594[2650676];
	v2 = a1[1] - *(_DWORD*)&byte_5D4594[2650680];
	v3 = v1 / 23;
	v4 = v2 / 23;
	if (v1 / 23 < 0 || v4 < 0 || v3 > 56 || v4 > 44)
		return (char*)&byte_587000[142336];
	v5 = v1 % 23;
	v6 = 12 * (v4 + 40 * v3 + 5 * v3);
	v7 = v2 % 23;
	v16 = *(_DWORD*)&byte_5D4594[v6 + 2618924] +
	      v5 * (*(int*)&byte_5D4594[v6 + 2619464] - *(int*)&byte_5D4594[v6 + 2618924]) / 23;
	v17 = *(_DWORD*)&byte_5D4594[v6 + 2618928] +
	      v5 * (*(int*)&byte_5D4594[v6 + 2619468] - *(int*)&byte_5D4594[v6 + 2618928]) / 23;
	v18 = *(_DWORD*)&byte_5D4594[v6 + 2618932] +
	      v5 * (*(int*)&byte_5D4594[v6 + 2619472] - *(int*)&byte_5D4594[v6 + 2618932]) / 23;
	v10 = *(_DWORD*)&byte_5D4594[v6 + 2618936];
	v11 = v5 * (*(_DWORD*)&byte_5D4594[v6 + 2619476] - v10);
	v12 = v2 % 23 *
	      (*(_DWORD*)&byte_5D4594[v6 + 2618940] +
	       v5 * (*(int*)&byte_5D4594[v6 + 2619480] - *(int*)&byte_5D4594[v6 + 2618940]) / 23 - v17);
	v13 = v7 * (*(_DWORD*)&byte_5D4594[v6 + 2618944] +
		    v5 * (*(int*)&byte_5D4594[v6 + 2619484] - *(int*)&byte_5D4594[v6 + 2618944]) / 23 - v18);
	*(_DWORD*)&byte_5D4594[1064836] = (v16 + v7 * (v10 + v11 / 23 - v16) / 23) >> 16;
	*(_DWORD*)&byte_5D4594[1064840] = (v17 + v12 / 23) >> 16;
	result = (char*)&byte_5D4594[1064836];
	*(_DWORD*)&byte_5D4594[1064844] = (v18 + v13 / 23) >> 16;
	return result;
}

//----- (00469B90) --------------------------------------------------------
int __cdecl sub_469B90(int* a1) {
	int result; // eax

	*(_DWORD*)&byte_587000[142296] = *a1;
	*(_DWORD*)&byte_587000[142300] = a1[1];
	result = a1[2];
	*(_DWORD*)&byte_587000[142304] = a1[2];
	return result;
}

//----- (00469BB0) --------------------------------------------------------
char* sub_469BB0() { return (char*)&byte_587000[142296]; }

//----- (00469FA0) --------------------------------------------------------
int sub_469FA0() { return *(_DWORD*)&byte_5D4594[1064848]; }

//----- (00469FB0) --------------------------------------------------------
int __cdecl sub_469FB0(const char* a1) {
	int v1;          // ebp
	const char** v2; // edi

	v1 = 0;
	v2 = (const char**)&byte_587000[142868];
	while (strcmp(*v2, a1)) {
		++v2;
		++v1;
		if ((int)v2 >= (int)&byte_587000[142928])
			return -1;
	}
	return v1;
}

//----- (0046A010) --------------------------------------------------------
BOOL __cdecl sub_46A010(_DWORD* a1, char* a2) {
	_DWORD* v2;           // esi
	char* v3;             // ebx
	unsigned __int8* v4;  // edx
	int v5;               // ecx
	const char* v6;       // edi
	int v8;               // ebp
	unsigned __int8* v9;  // eax
	unsigned __int8* v10; // eax
	unsigned __int8* v11; // eax
	unsigned __int8* v12; // eax
	int v13;              // ebp
	int v14;              // edi
	unsigned __int8* v15; // ebp
	int* v16;             // eax
	int v17;              // ecx
	int* v18;             // eax
	int v19;              // ecx
	int* v20;             // eax
	int v21;              // ecx
	char* v22;            // eax
	char v23;             // cl
	int v24;              // edi
	char* v25;            // eax
	unsigned __int8* v26; // ecx
	bool v27;             // zf
	int* v28;             // eax
	int v29;              // ecx
	_DWORD* v30;          // [esp-4h] [ebp-40h]
	int v31;              // [esp+10h] [ebp-2Ch]
	unsigned __int8* v32; // [esp+14h] [ebp-28h]
	int v33;              // [esp+18h] [ebp-24h]
	int v34;              // [esp+1Ch] [ebp-20h]
	int v35;              // [esp+20h] [ebp-1Ch]
	int v36;              // [esp+24h] [ebp-18h]
	int v37;              // [esp+28h] [ebp-14h]
	int v38;              // [esp+2Ch] [ebp-10h]
	int v39;              // [esp+30h] [ebp-Ch]
	int v40;              // [esp+34h] [ebp-8h]
	const char* v41;      // [esp+38h] [ebp-4h]
	unsigned __int8 v42;  // [esp+40h] [ebp+4h]
	unsigned __int8 v43;  // [esp+40h] [ebp+4h]
	unsigned __int8 v44;  // [esp+40h] [ebp+4h]
	unsigned __int8 v45;  // [esp+40h] [ebp+4h]
	unsigned __int8 v46;  // [esp+40h] [ebp+4h]
	const char** v47;     // [esp+40h] [ebp+4h]
	unsigned __int8* v48; // [esp+44h] [ebp+8h]
	int v49;              // [esp+44h] [ebp+8h]

	v2 = a1;
	v3 = a2;
	v30 = a1;
	v4 = (unsigned __int8*)(a1[2] + 4);
	a1[2] = v4;
	v42 = *v4;
	v2[2] = v4 + 1;
	nox_memfile_read(a2, 1u, v42, (int)v30);
	a2[v42] = 0;
	v5 = 0;
	if (*(_DWORD*)&byte_5D4594[251540] > 0) {
		v6 = (const char*)&byte_5D4594[2692748];
		v48 = &byte_5D4594[2692748];
		while (strcmp(v6, v3)) {
			++v5;
			v6 = (const char*)(v48 + 12332);
			v48 += 12332;
			if (v5 >= *(int*)&byte_5D4594[251540])
				return 0;
		}
		v49 = v5;
		if (v5 != -1) {
			v38 = 12332 * v5;
			memset(&byte_5D4594[12332 * v5 + 2701180], 0, 0xF00u);
			v2[2] += 14;
			sub_40AD60((char*)&v31, 1, 1, v2);
			v8 = 0;
			if ((_BYTE)v31) {
				while (v8 < 8) {
					v9 = (unsigned __int8*)v2[2];
					v43 = *v9;
					v2[2] = v9 + 1;
					nox_memfile_read(v3, 1u, v43, (int)v2);
					v3[v43] = 0;
					if (++v8 >= (unsigned __int8)v31)
						goto LABEL_11;
				}
			} else {
			LABEL_11:
				v10 = (unsigned __int8*)v2[2];
				v44 = *v10;
				v2[2] = v10 + 1;
				nox_memfile_read(v3, 1u, v44, (int)v2);
				v3[v44] = 0;
				v11 = (unsigned __int8*)v2[2];
				v45 = *v11;
				v2[2] = v11 + 1;
				nox_memfile_read(v3, 1u, v45, (int)v2);
				v3[v45] = 0;
				v12 = (unsigned __int8*)v2[2];
				v46 = *v12;
				v2[2] = v12 + 1;
				nox_memfile_read(v3, 1u, v46, (int)v2);
				v3[v46] = 0;
				++v2[2];
				v47 = (const char**)&byte_587000[142868];
				while (1) {
					v13 = sub_469FB0(*v47);
					v36 = v13;
					if (v13 < 0)
						break;
					sub_40AD60((char*)&v35, 1, 1, v2);
					if ((unsigned __int8)v35 >= 0x10u)
						break;
					v14 = 0;
					v34 = 0;
					if ((_BYTE)v35) {
						v37 = 3083 * v49;
						while (1) {
							v33 = 4;
							v32 = &byte_5D4594[4 * (v14 + 16 * v13 + v37) + 2701180];
							v15 = &byte_5D4594[8 * (v14 + 16 * v13) + 2693504 + v38];
							do {
								v16 = (int*)v2[2];
								v17 = *v16;
								v2[2] = v16 + 1;
								*((_DWORD*)v15 - 1) = v17;
								v18 = (int*)v2[2];
								v19 = *v18;
								v2[2] = v18 + 1;
								*(_DWORD*)v15 = v19;
								v20 = (int*)v2[2];
								v21 = *v20;
								v2[2] = v20 + 1;
								v40 = v21;
								*v3 = byte_5D4594[1064852];
								if (v21 == -1) {
									v22 = (char*)v2[2];
									v23 = *v22++;
									v2[2] = v22;
									LOBYTE(v41) = v23;
									LOBYTE(v39) = *v22;
									v2[2] = v22 + 1;
									v24 = (unsigned __int8)v39;
									nox_memfile_read(v3, (unsigned __int8)v39, 1,
											 (int)v2);
									v21 = v40;
									v3[v24] = 0;
									v14 = v34;
								}
								v25 = sub_42FAA0(v21, v41, v3);
								v26 = v32;
								v15 += 1920;
								*(_DWORD*)v32 = v25;
								v27 = v33 == 1;
								v32 = v26 + 960;
								--v33;
							} while (!v27);
							v34 = ++v14;
							if (v14 >= (unsigned __int8)v35)
								break;
							v13 = v36;
						}
					}
					++v47;
					if ((int)v47 >= (int)&byte_587000[142928]) {
						v28 = (int*)v2[2];
						v29 = *v28;
						v2[2] = v28 + 1;
						return v29 == 1162757152;
					}
				}
			}
		}
	}
	return 0;
}

//----- (0046A360) --------------------------------------------------------
int sub_46A360() {
	int i;               // ebx
	int v1;              // edx
	int v2;              // esi
	unsigned __int8* v3; // edi

	for (i = 0; i < 986560; i += 12332) {
		v1 = 0;
		do {
			v2 = 15;
			do {
				v3 = &byte_5D4594[i + 2701180 + v1];
				v1 += 64;
				--v2;
				memset(v3, 0, 0x40u);
			} while (v2);
		} while (v1 < 3840);
	}
	return 1;
}

//----- (0046A3B0) --------------------------------------------------------
int __cdecl sub_46A3B0(int a1, int a2, int a3, int a4) {
	return *(_DWORD*)&byte_5D4594[4 * (16 * (a2 + 12 * a4 + 3 * a4) + a3 + 3083 * a1) + 2701180];
}

//----- (0046A3F0) --------------------------------------------------------
char* __cdecl sub_46A3F0(int a1, int a2, int a3, int a4) {
	return (char*)&byte_5D4594[12332 * a1 + 2693500 + 8 * (a3 + 16 * (a2 + 12 * a4 + 3 * a4))];
}

//----- (0046A430) --------------------------------------------------------
void __cdecl sub_46A430(int a1) {
	if (!nox_common_gameFlags_check_40A5C0(2048)) {
		if (!*(_DWORD*)&byte_5D4594[1064868]) {
			**(_WORD**)&byte_5D4594[1064864] = 0;
			*(_WORD*)(*(_DWORD*)&byte_5D4594[1064864] + 1052) = 0;
			sub_46A8C0(*(int*)&byte_5D4594[1064856]);
			sub_46C690(*(int*)&byte_5D4594[1064856]);
			sub_46B500(*(int*)&byte_5D4594[1064860]);
			*(_DWORD*)&byte_5D4594[1064868] = 1;
			*(_DWORD*)&byte_5D4594[1064872] = a1;
		}
	}
}

//----- (0046A4A0) --------------------------------------------------------
int sub_46A4A0() { return *(_DWORD*)&byte_5D4594[1064868]; }

//----- (0046A4B0) --------------------------------------------------------
size_t __cdecl sub_46A4B0(wchar_t* a1, int a2) {
	_DWORD* v2;        // ebp
	size_t v3;         // edi
	size_t result;     // eax
	const wchar_t* v5; // edi
	char v6;           // al
	int v7;            // eax
	char v8[520];      // [esp+Ch] [ebp-208h]

	v2 = sub_45A6F0(*(int*)&byte_5D4594[2616328]);
	v3 = nox_wcsspn(a1, L" ");
	result = nox_wcslen(a1);
	if (v3 != result) {
		v5 = &a1[v3];
		v8[0] = -88;
		*(_WORD*)&v8[9] = 0;
		*(_WORD*)&v8[1] = *(_WORD*)&byte_5D4594[2616328];
		v8[3] = 0;
		if (sub_4100F0((__int16*)a1))
			v6 = v8[3] | 2;
		else
			v6 = v8[3] | 4;
		v8[3] = v6;
		if (a2)
			v8[3] |= 1u;
		v8[8] = nox_wcslen(v5) + 1;
		if (v8[3] & 4) {
			nox_wcscpy((wchar_t*)&v8[11], v5);
			v7 = 2;
		} else {
			nox_sprintf(&v8[11], "%S", v5);
			v7 = 1;
		}
		if (v2) {
			*(_WORD*)&v8[4] = *((_WORD*)v2 + 6);
			*(_WORD*)&v8[6] = *((_WORD*)v2 + 8);
		} else {
			*(_WORD*)&v8[6] = -1;
			*(_WORD*)&v8[4] = -1;
		}
		result = sub_40EBC0(31, 0, v8, v7 * (unsigned __int8)v8[8] + 11);
	}
	return result;
}

//----- (0046A5D0) --------------------------------------------------------
int __cdecl sub_46A5D0(_DWORD* a1, int a2) {
	int v2;  // ecx
	bool v3; // sf
	int v5;  // [esp+4h] [ebp-8h]
	int v6;  // [esp+8h] [ebp-4h]

	v5 = 0;
	v6 = 0;
	sub_46A8C0(*(int*)&byte_5D4594[1064856]);
	sub_46B500(*(int*)&byte_5D4594[1064860]);
	sub_43F840(0, *(unsigned __int16**)&byte_5D4594[1064864], &v5, 0, 0);
	sub_43F840(0, (unsigned __int16*)(*(_DWORD*)&byte_5D4594[1064864] + 512), &v6, 0, 0);
	v3 = v5 + v6 - 90 < 0;
	v5 += v6 + 10;
	v2 = v5;
	if (v5 < 100) {
		v2 = 100;
	LABEL_5:
		v5 = v2;
		goto LABEL_6;
	}
	if (v5 > 320) {
		v2 = 320;
		goto LABEL_5;
	}
LABEL_6:
	sub_46A9B0(*(_DWORD**)&byte_5D4594[1064856], (nox_win_width - v2) / 2,
		   *(_DWORD*)(*(_DWORD*)&byte_5D4594[1064856] + 20));
	sub_46AB20(a1, v5, 20);
	return sub_488160((int)a1, a2);
}

//----- (0046A6A0) --------------------------------------------------------
int sub_46A6A0() {
	if (wndIsShown_sub_46ACC0(*(int*)&byte_5D4594[1064856]))
		return 0;
	if (sub_46B4F0() == *(_DWORD*)&byte_5D4594[1064860])
		sub_46B500(0);
	sub_46C6E0(*(int*)&byte_5D4594[1064856]);
	nox_window_set_hidden(*(int*)&byte_5D4594[1064856], 1);
	*(_DWORD*)(*(_DWORD*)&byte_5D4594[1064856] + 4) &= 0xFFFFFFF7;
	*(_DWORD*)(*(_DWORD*)&byte_5D4594[1064860] + 4) &= 0xFFFFFFF7;
	*(_DWORD*)&byte_5D4594[3799524] = 1;
	*(_DWORD*)&byte_5D4594[1064868] = 0;
	return 1;
}

//----- (0046A730) --------------------------------------------------------
_DWORD* sub_46A730() {
	_DWORD* result; // eax

	*(_DWORD*)&byte_5D4594[1064876] = nox_win_width / 2;
	*(_DWORD*)&byte_5D4594[1064880] = 2 * nox_win_height / 3;
	result = nox_new_window_from_file("GuiChat.wnd", sub_46A820);
	*(_DWORD*)&byte_5D4594[1064856] = result;
	if (result) {
		sub_46A9B0(result, *(int*)&byte_5D4594[1064876], *(int*)&byte_5D4594[1064880]);
		result = sub_46B0C0(*(_DWORD**)&byte_5D4594[1064856], 9201);
		*(_DWORD*)&byte_5D4594[1064860] = result;
		if (result) {
			sub_46B340((int)result, sub_46A5D0);
			sub_46B300(*(int*)&byte_5D4594[1064860], sub_46A7E0);
			result = *(_DWORD**)&byte_5D4594[1064856];
			*(_DWORD*)&byte_5D4594[1064864] = *(_DWORD*)(*(_DWORD*)&byte_5D4594[1064860] + 32);
		}
	}
	return result;
}

//----- (0046A7E0) --------------------------------------------------------
int __cdecl sub_46A7E0(_DWORD* a1, int a2, int a3, int a4) {
	if (a2 != 21 || a3 != 1)
		return sub_487D70(a1, a2, a3, a4);
	if (a4 == 2)
		sub_49B7A0();
	return 1;
}

//----- (0046A820) --------------------------------------------------------
int __cdecl sub_46A820(int a1, int a2, int a3, int a4) {
	if (a2 == 16415) {
		if (*(_WORD*)(*(_DWORD*)&byte_5D4594[1064864] + 1052))
			sub_46A4B0(*(wchar_t**)&byte_5D4594[1064864], *(int*)&byte_5D4594[1064872]);
		sub_46A6A0();
	}
	return 0;
}

//----- (0046A860) --------------------------------------------------------
int sub_46A860() {
	int result; // eax

	result = *(_DWORD*)&byte_5D4594[1064856];
	if (*(_DWORD*)&byte_5D4594[1064856]) {
		result = sub_46C4E0(*(_DWORD**)&byte_5D4594[1064856]);
		*(_DWORD*)&byte_5D4594[1064856] = 0;
	}
	*(_DWORD*)&byte_5D4594[1064860] = 0;
	*(_DWORD*)&byte_5D4594[1064864] = 0;
	*(_DWORD*)&byte_5D4594[1064868] = 0;
	*(_DWORD*)&byte_5D4594[1064872] = 0;
	return result;
}

//----- (0046A8A0) --------------------------------------------------------
int sub_46A8A0() { return 0; }

//----- (0046A8B0) --------------------------------------------------------
int sub_46A8B0() { return 0; }

//----- (0046A8C0) --------------------------------------------------------
int __cdecl sub_46A8C0(int a1) {
	int result; // eax
	int v2;     // eax
	int v3;     // eax

	if (!a1)
		return -2;
	v2 = dword_5d4594_1064888;
	if (dword_5d4594_1064888 == a1) {
	LABEL_6:
		sub_46A960(a1);
		sub_46A920(a1);
		v3 = *(_DWORD*)(a1 + 4);
		LOBYTE(v3) = v3 | 1;
		*(_DWORD*)(a1 + 4) = v3;
		nox_window_set_hidden(a1, 0);
		result = 0;
	} else {
		while (v2) {
			v2 = *(_DWORD*)(v2 + 388);
			if (v2 == a1)
				goto LABEL_6;
		}
		result = -3;
	}
	return result;
}

//----- (0046A920) --------------------------------------------------------
int __cdecl sub_46A920(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)(a1 + 392) = 0;
	*(_DWORD*)(a1 + 388) = dword_5d4594_1064888;
	if (dword_5d4594_1064888)
		*(_DWORD*)(dword_5d4594_1064888 + 392) = a1;
	else
		nox_win_unk4 = a1;
	dword_5d4594_1064888 = a1;
	return result;
}

//----- (0046A960) --------------------------------------------------------
void __cdecl sub_46A960(nox_window* win) {
	nox_window* v2 = win->field_97;
	if (v2) {
		v2->field_98 = win->field_98;
	} else {
		nox_win_unk4 = win->field_98;
	}
	nox_window* v3 = win->field_98;
	if (v3) {
		v3->field_97 = win->field_97;
	} else {
		dword_5d4594_1064888 = win->field_97;
	}
}

//----- (0046A9B0) --------------------------------------------------------
int __cdecl sub_46A9B0(_DWORD* a1, int a2, int a3) {
	int v4; // esi
	int v5; // ecx

	if (!a1)
		return -2;
	v4 = a1[2];
	a1[4] = a2;
	v5 = a3 + a1[3];
	a1[5] = a3;
	a1[6] = a2 + v4;
	a1[7] = v5;
	sub_46A9F0(a1);
	return 0;
}

//----- (0046A9F0) --------------------------------------------------------
_DWORD* __cdecl sub_46A9F0(_DWORD* a1) {
	_DWORD* result; // eax
	int v2;         // ecx
	int v3;         // edx
	int v4;         // ecx
	int v5;         // edx

	result = a1;
	v2 = a1[4];
	v3 = a1[6];
	if (v2 > v3) {
		a1[4] = v3;
		a1[6] = v2;
	}
	v4 = a1[5];
	v5 = a1[7];
	if (v4 > v5) {
		a1[5] = v5;
		a1[7] = v4;
	}
	return result;
}

//----- (0046AA20) --------------------------------------------------------
int __cdecl sub_46AA20(int a1, _DWORD* a2, _DWORD* a3) {
	int result; // eax

	if (a1) {
		*a2 = *(_DWORD*)(a1 + 16);
		*a3 = *(_DWORD*)(a1 + 20);
		result = 0;
	} else {
		*a3 = 0;
		*a2 = 0;
		result = -2;
	}
	return result;
}

//----- (0046AA60) --------------------------------------------------------
int __cdecl nox_client_wndGetPosition_46AA60(nox_window* win, _DWORD* a2, _DWORD* a3) {
	if (!win)
		return -2;

	*a2 = win->field_4;
	*a3 = win->field_5;
	for (nox_window* i = win->field_99; i; i = i->field_99) {
		*a2 += i->field_4;
		*a3 += i->field_5;
	}
	return 0;
}

//----- (0046AAB0) --------------------------------------------------------
BOOL __cdecl sub_46AAB0(_DWORD* a1, int a2, int a3) {
	_DWORD* v3; // esi
	int v5;     // [esp+4h] [ebp-Ch]
	int v6;     // [esp+8h] [ebp-8h]
	int v7;     // [esp+Ch] [ebp-4h]

	v3 = a1;
	nox_client_wndGetPosition_46AA60(a1, &a1, &v6);
	nox_window_get_size((int)v3, &v5, &v7);
	return a2 >= (int)a1 && a2 <= (int)a1 + v5 && a3 >= v6 && a3 <= v6 + v7;
}

//----- (0046AB20) --------------------------------------------------------
int __cdecl sub_46AB20(_DWORD* a1, int a2, int a3) {
	int v4; // esi

	if (!a1)
		return -2;
	a1[6] = a2 + a1[4];
	v4 = a3 + a1[5];
	a1[2] = a2;
	a1[3] = a3;
	a1[7] = v4;
	nox_window_call_field_94((int)a1, 16388, a2, a3);
	return 0;
}

//----- (0046AB70) --------------------------------------------------------
int __cdecl nox_window_get_size(nox_window* win, int* outW, int* outH) {
	if (!win) {
		*outW = 0;
		*outH = 0;
		return -2;
	}
	*outW = win->width;
	*outH = win->height;
	return 0;
}

//----- (0046ABB0) --------------------------------------------------------
int __cdecl sub_46ABB0(int a1, int a2) {
	int v3;          // ecx
	unsigned int v4; // ecx
	int v5;          // esi

	if (!a1)
		return -2;
	v3 = *(_DWORD*)(a1 + 4);
	if (a2)
		v4 = v3 | 8;
	else
		v4 = v3 & 0xFFFFFFF7;
	v5 = *(_DWORD*)(a1 + 400);
	for (*(_DWORD*)(a1 + 4) = v4; v5; v5 = *(_DWORD*)(v5 + 388))
		sub_46ABB0(v5, a2);
	return 0;
}

//----- (0046AC00) --------------------------------------------------------
int __cdecl nox_window_set_hidden(nox_window* win, int hidden) {
	if (!win)
		return -2;

	if (!hidden) {
		win->flags &= ~NOX_WIN_HIDDEN;
		return 0;
	}

	if ((win->flags & 0x8000) == 0)
		sub_46AC60(win);

	if (*(_DWORD*)&byte_5D4594[3799468]) {
		if (!(win->flags & NOX_WIN_HIDDEN))
			*(_DWORD*)&byte_5D4594[3799524] = 1;
	}
	win->flags |= NOX_WIN_HIDDEN;
	return 0;
}

//----- (0046AC60) --------------------------------------------------------
void __cdecl sub_46AC60(int a1) {
	int v2; // esi

	if (*(_BYTE*)(a1 + 4) & 0x80) {
		if (*(_DWORD*)(a1 + 60))
			sub_42FAE0(*(_DWORD*)(a1 + 60));
		if (*(_DWORD*)(a1 + 84))
			sub_42FAE0(*(_DWORD*)(a1 + 84));
		if (*(_DWORD*)(a1 + 68))
			sub_42FAE0(*(_DWORD*)(a1 + 68));
		if (*(_DWORD**)(a1 + 92))
			sub_42FAE0(*(_DWORD*)(a1 + 92));
		v2 = *(_DWORD*)(a1 + 76);
		if (v2)
			sub_42FAE0(v2);
	}
}

//----- (0046ACC0) --------------------------------------------------------
int __cdecl wndIsShown_sub_46ACC0(int a1) {
	int result; // eax

	if (a1)
		result = (*(_DWORD*)(a1 + 4) >> 4) & 1;
	else
		result = 1;
	return result;
}

//----- (0046ACE0) --------------------------------------------------------
void __cdecl sub_46ACE0(_DWORD* a1, int a2, int a3, int a4) {
	for (int i = a2; i <= a3; i++) {
		_DWORD* v5 = sub_46B0C0(a1, i);
		nox_window_set_hidden((int)v5, a4);
	}
}

//----- (0046AD20) --------------------------------------------------------
void __cdecl sub_46AD20(_DWORD* a1, int a2, int a3, int a4) {
	int i;      // esi
	_DWORD* v5; // eax

	for (i = a2; i <= a3; ++i) {
		v5 = sub_46B0C0(a1, i);
		sub_46ABB0((int)v5, a4);
	}
}

//----- (0046AD60) --------------------------------------------------------
int __cdecl sub_46AD60(int a1, int a2) {
	int result; // eax

	if (!a1)
		return -2;
	result = *(_DWORD*)(a1 + 4);
	*(_DWORD*)(a1 + 4) = a2 | result;
	return result;
}

//----- (0046AD80) --------------------------------------------------------
int __cdecl sub_46AD80(int a1, int a2) {
	int result; // eax

	if (!a1)
		return -2;
	result = *(_DWORD*)(a1 + 4);
	*(_DWORD*)(a1 + 4) = result & ~a2;
	return result;
}

//----- (0046ADA0) --------------------------------------------------------
int __cdecl sub_46ADA0(int a1) {
	int result; // eax

	if (a1)
		result = *(_DWORD*)(a1 + 4);
	else
		result = -2;
	return result;
}

//----- (0046ADC0) --------------------------------------------------------
int __cdecl sub_46ADC0(int a1) {
	if (nox_win_unk3)
		return -4;
	nox_win_unk3 = a1;
	return 0;
}

//----- (0046ADE0) --------------------------------------------------------
int __cdecl sub_46ADE0(int a1) {
	if (a1 == nox_win_unk3)
		nox_win_unk3 = 0;
	return 0;
}

//----- (0046AE00) --------------------------------------------------------
int sub_46AE00() { return nox_win_unk3; }

//----- (0046AE10) --------------------------------------------------------
int __cdecl sub_46AE10(int a1, int a2) {
	int result; // eax
	int v3;     // ecx

	result = a1;
	if (a1) {
		v3 = *(_DWORD*)(a1 + 36);
		if (a2)
			*(_DWORD*)(a1 + 36) = v3 | 2;
		else
			*(_DWORD*)(a1 + 36) = v3 & 0xFFFFFFFD;
	}
	return result;
}

//----- (0046AE40) --------------------------------------------------------
int __cdecl sub_46AE40(int a1, int a2, int a3) {
	int result; // eax

	result = a1;
	if (a1) {
		*(_DWORD*)(a1 + 96) = a2;
		*(_DWORD*)(a1 + 100) = a3;
	}
	return result;
}

//----- (0046AE60) --------------------------------------------------------
int __cdecl sub_46AE60(int a1, int a2) {
	if (!a1)
		return -2;
	*(_DWORD*)(a1 + 60) = a2;
	return 0;
}

//----- (0046AE80) --------------------------------------------------------
int __cdecl sub_46AE80(int a1, int a2) {
	if (!a1)
		return -2;
	*(_DWORD*)(a1 + 84) = a2;
	return 0;
}

//----- (0046AEA0) --------------------------------------------------------
int __cdecl sub_46AEA0(int a1, int a2) {
	if (!a1)
		return -2;
	*(_DWORD*)(a1 + 76) = a2;
	return 0;
}

//----- (0046AEC0) --------------------------------------------------------
int __cdecl sub_46AEC0(int a1, int a2) {
	if (!a1)
		return -2;
	*(_DWORD*)(a1 + 92) = a2;
	return 0;
}

//----- (0046AEE0) --------------------------------------------------------
int __cdecl sub_46AEE0(int a1, int a2) {
	nox_window_call_field_94(a1, 16385, a2, 0);
	return 0;
}

//----- (0046AF00) --------------------------------------------------------
int __cdecl sub_46AF00(int a1) {
	int v1;     // ecx
	int result; // eax

	if (!a1)
		goto LABEL_9;
	v1 = *(_DWORD*)(a1 + 44);
	if (v1 & 0x800)
		return nox_window_call_field_94(a1, 16386, 0, 0);
	if ((v1 & 0x80u) != 0)
		result = nox_window_call_field_94(a1, 16413, 0, 0);
	else
	LABEL_9:
		result = 0;
	return result;
}

//----- (0046AF40) --------------------------------------------------------
int __cdecl sub_46AF40(int a1) {
	int result; // eax

	result = a1;
	if (a1)
		result = *(_DWORD*)(a1 + 236);
	return result;
}

//----- (0046AF50) --------------------------------------------------------
int __cdecl sub_46AF50(int a1, int a2) {
	int result; // eax

	if (a1 && *(_BYTE*)(a1 + 44) & 0x20)
		result = nox_window_call_field_94(a1, 16406, a2, 0);
	else
		result = 0;
	return result;
}

//----- (0046AF80) --------------------------------------------------------
int __cdecl sub_46AF80_copy_window_part(nox_window* win, const void* p) {
	if (!win)
		return -2;
	if (!p)
		return -3;
	qmemcpy(win->field_9, p, 83 * 4);
	return 0;
}

//----- (0046AFB0) --------------------------------------------------------
int __cdecl sub_46AFB0(int a1, void* a2) {
	int result; // eax

	if (!a1)
		return -2;
	if (!a2)
		return -3;
	result = 0;
	qmemcpy(a2, (const void*)(a1 + 36), 0x14Cu);
	return result;
}

//----- (0046AFE0) --------------------------------------------------------
int __cdecl sub_46AFE0(int a1, int a2) {
	if (!a1)
		return -2;
	*(_DWORD*)(a1 + 56) = a2;
	return 0;
}

//----- (0046B070) --------------------------------------------------------
int __cdecl sub_46B070(int a1, int a2) {
	int result; // eax

	result = a2;
	*(_DWORD*)(a1 + 384) = a2;
	return result;
}

//----- (0046B080) --------------------------------------------------------
int __cdecl sub_46B080(_DWORD* a1, int a2) {
	if (!a1)
		return -2;
	*a1 = a2;
	return 0;
}

//----- (0046B0A0) --------------------------------------------------------
int __cdecl sub_46B0A0(int* a1) {
	int result; // eax

	if (a1)
		result = *a1;
	else
		result = -2;
	return result;
}

//----- (0046B0C0) --------------------------------------------------------
_DWORD* __cdecl sub_46B0C0(_DWORD* a1, int a2) {
	_DWORD* v2;     // esi
	_DWORD* v3;     // eax
	_DWORD* result; // eax

	v2 = a1;
	if (!a1) {
		v2 = *(_DWORD**)&dword_5d4594_1064888;
		if (!dword_5d4594_1064888)
			return 0;
	}
	while (*v2 != a2) {
		v3 = (_DWORD*)v2[100];
		if (v3) {
			result = sub_46B0C0(v3, a2);
			if (result)
				return result;
		}
		v2 = (_DWORD*)v2[97];
		if (!v2)
			return 0;
	}
	return v2;
}

//----- (0046B110) --------------------------------------------------------
int sub_46B110() { return dword_5d4594_1064888; }

//----- (0046B120) --------------------------------------------------------
int __cdecl sub_46B120(nox_window* win, int a2) {
	if (!win)
		return -2;
	if (win->field_99)
		sub_46B180(win);
	else
		sub_46A960(win);
	if (a2) {
		nox_window_set_ptrs_97(win, a2);
	} else {
		sub_46A920((int)win);
		win->field_99 = 0;
	}
	return 0;
}

//----- (0046B180) --------------------------------------------------------
void __cdecl sub_46B180(nox_window* win) {
	nox_window* v2 = win->field_98;
	if (v2) {
		nox_window* v3 = win->field_97;
		v2->field_97 = v3;
		if (v3) {
			v3->field_98 = win->field_98;
		}
	} else {
		if (win->field_97) {
			win->field_99->field_100 = win->field_97;
			win->field_97->field_98 = win->field_98;
			win->field_97 = 0;
		} else {
			win->field_99->field_100 = 0;
		}
	}
}

//----- (0046B200) --------------------------------------------------------
void __cdecl nox_window_set_ptrs_97(nox_window* win, nox_window* a2) {
	if (!a2)
		return;

	win->field_98 = 0;
	nox_window* v2 = a2->field_100;
	win->field_97 = v2;
	if (v2)
		v2->field_98 = win;
	a2->field_100 = win;
	win->field_99 = a2;
}

//----- (0046B240) --------------------------------------------------------
int __cdecl sub_46B240(int a1) {
	int result; // eax

	result = a1;
	if (a1)
		result = *(_DWORD*)(a1 + 396);
	return result;
}

//----- (0046B250) --------------------------------------------------------
int __cdecl nox_window_is_child(nox_window* a1, nox_window* a2) {
	if (!a1)
		return 0;
	if (!a2)
		return 0;

	nox_window* cur = a2;
	while (1) {
		cur = cur->field_99;
		if (a1 == cur)
			break;
		if (!cur)
			return 0;
	}
	return 1;
}

//----- (0046B280) --------------------------------------------------------
int __cdecl sub_46B280(int a1, int a2) {
	if (!a1)
		return -2;
	if (a2)
		*(_DWORD*)(a1 + 52) = a2;
	else
		*(_DWORD*)(a1 + 52) = a1;
	return 0;
}

//----- (0046B2B0) --------------------------------------------------------
int __cdecl sub_46B2B0(int a1) {
	int result; // eax

	result = a1;
	if (a1)
		result = *(_DWORD*)(a1 + 52);
	return result;
}

//----- (0046B2C0) --------------------------------------------------------
int __cdecl sub_46B2C0(int a1, int (*a2)(int, int, int, int)) {
	if (!a1)
		return -2;
	if (a2)
		*(_DWORD*)(a1 + 376) = a2;
	else
		*(_DWORD*)(a1 + 376) = sub_46B2F0;
	return 0;
}

//----- (0046B2F0) --------------------------------------------------------
int sub_46B2F0(int a1, int a2, int a3, int a4) { return 0; }

//----- (0046B300) --------------------------------------------------------
int __cdecl sub_46B300(int a1, int (*a2)(int, int, int, int)) {
	if (!a1)
		return -2;
	if (a2)
		*(_DWORD*)(a1 + 372) = a2;
	else
		*(_DWORD*)(a1 + 372) = sub_46B330;
	return 0;
}

//----- (0046B330) --------------------------------------------------------
int sub_46B330(int a1, int a2, int a3, int a4) { return 0; }

//----- (0046B340) --------------------------------------------------------
int __cdecl sub_46B340(int a1, int (*a2)(int, int)) {
	if (!a1)
		return -2;
	if (a2)
		*(_DWORD*)(a1 + 380) = a2;
	else
		*(_DWORD*)(a1 + 380) = sub_46B370;
	return 0;
}

//----- (0046B370) --------------------------------------------------------
int __cdecl sub_46B370(int a1, int* a2) {
	int v2;     // edx
	int v3;     // ecx
	int result; // eax
	int xLeft;  // [esp+4h] [ebp-8h]
	int yTop;   // [esp+8h] [ebp-4h]

	nox_client_wndGetPosition_46AA60((_DWORD*)a1, &xLeft, &yTop);
	if ((signed char)*(_BYTE*)(a1 + 4) >= 0) {
		if (a2[5] != 0x80000000) {
			nox_client_drawSetColor_434460(a2[5]);
			nox_client_drawRectFilledOpaque_49CE30(xLeft, yTop, *(_DWORD*)(a1 + 8), *(_DWORD*)(a1 + 12));
		}
		result = 1;
	} else {
		v2 = *(_DWORD*)(a1 + 100);
		xLeft += *(_DWORD*)(a1 + 96);
		v3 = v2 + yTop;
		LOBYTE(v2) = *(_BYTE*)(a1 + 36);
		yTop = v3;
		if (v2 & 2)
			nox_client_drawImageAt_47D2C0(a2[10], xLeft, v3);
		else
			nox_client_drawImageAt_47D2C0(a2[6], xLeft, v3);
		result = 1;
	}
	return result;
}

//----- (0046B430) --------------------------------------------------------
int __cdecl nox_window_set_all_funcs(nox_window* win, int (*a2)(int, int, int, int), int (*draw)(nox_window*, void*),
				     void* a4) {
	if (!win)
		return -2;
	if (a2)
		win->field_93 = a2;
	else
		win->field_93 = sub_46B330;
	if (draw)
		win->draw_func = draw;
	else
		win->draw_func = sub_46B370;
	win->field_96 = a4;
	return 0;
}

//----- (0046B490) --------------------------------------------------------
int __cdecl nox_window_call_field_94(nox_window* win, int a2, int a3, int a4) {
	if (!win)
		return 0;
	return win->field_94(win, a2, a3, a4);
}

//----- (0046B4C0) --------------------------------------------------------
int __cdecl nox_window_call_field_93(nox_window* win, int a2, int a3, int a4) {
	if (!win)
		return 0;
	return win->field_93(win, a2, a3, a4);
}

//----- (0046B4F0) --------------------------------------------------------
int sub_46B4F0() { return nox_win_unk2; }

//----- (0046B500) --------------------------------------------------------
int __cdecl sub_46B500(nox_window* win) {
	if (win) {
		if (win->flags & 0x400)
			return 0;
	}
	if (nox_win_unk2) {
		if (nox_win_unk2 != win)
			nox_window_call_field_94(nox_win_unk2, 23, 0, 0);
	}
	nox_win_unk2 = win;
	if (!win) {
		nox_win_unk2 = 0;
		return 0;
	}
	if (!nox_window_call_field_94(win, 23, 1, 0)) {
		nox_window* cur = win;
		while (1) {
			cur = cur->field_99;
			if (!cur)
				break;
			if (nox_window_call_field_94(cur, 23, 1, 0))
				return 0;
		}
		nox_win_unk2 = 0;
	}
	return 0;
}

//----- (0046B580) --------------------------------------------------------
int __cdecl sub_46B580(int a1) {
	if (!a1)
		return -2;
	if (!(*(_BYTE*)(a1 + 4) & 0x10))
		sub_46B370(a1, (int*)(a1 + 36));
	return 0;
}

//----- (0046B5B0) --------------------------------------------------------
_DWORD* __cdecl sub_46B5B0(_DWORD* a1, int a2, int a3) {
	_DWORD* result; // eax
	_DWORD* i;      // esi
	_DWORD* v5;     // ecx
	int v6;         // edx
	int j;          // edi
	int v8;         // ecx

	result = a1;
	if (a1) {
	LABEL_2:
		for (i = (_DWORD*)result[100]; i; i = (_DWORD*)i[97]) {
			v5 = (_DWORD*)i[99];
			v6 = i[4];
			for (j = i[5]; v5; v5 = (_DWORD*)v5[99]) {
				v6 += v5[4];
				j += v5[5];
			}
			if (a2 >= v6 && a2 <= v6 + (signed int)(i[2]) && a3 >= j && a3 <= j + (signed int)(i[3])) {
				v8 = i[1];
				if (v8 & 8) {
					if (!(v8 & 0x10)) {
						result = i;
						goto LABEL_2;
					}
				}
			}
		}
	}
	return result;
}

//----- (0046B630) --------------------------------------------------------
int __cdecl sub_46B630(int a1, int a2, int a3) {
	int result; // eax
	int i;      // esi
	_DWORD* v5; // ecx
	int v6;     // edx
	int j;      // edi

	result = a1;
	if (a1) {
	LABEL_2:
		for (i = *(_DWORD*)(result + 400); i; i = *(_DWORD*)(i + 388)) {
			v5 = *(_DWORD**)(i + 396);
			v6 = *(_DWORD*)(i + 16);
			for (j = *(_DWORD*)(i + 20); v5; v5 = (_DWORD*)v5[99]) {
				v6 += v5[4];
				j += v5[5];
			}
			if (a2 >= v6 && a2 <= v6 + *(_DWORD*)(i + 8) && a3 >= j && a3 <= j + *(_DWORD*)(i + 12) &&
			    !(*(_BYTE*)(i + 4) & 0x10)) {
				result = i;
				goto LABEL_2;
			}
		}
	}
	return result;
}

//----- (0046B6B0) --------------------------------------------------------
void __cdecl sub_46B6B0(unsigned __int8* a1) {
	int v1;              // edi
	unsigned __int8* v2; // esi
	char v3;             // bl
	int v4;              // eax
	int v5;              // ecx
	unsigned __int8 v6;  // [esp-8h] [ebp-14h]
	char v7;             // [esp+10h] [ebp+4h]

	v1 = nox_win_unk2;
	if (v1) {
		v2 = a1;
		if (*a1) {
			v3 = 1;
			if (a1[2] != 1) {
				v4 = *a1;
				v5 = a1[1];
				v7 = 1;
				if (!nox_window_call_field_93(nox_win_unk2, 21, v4, v5)) {
					while (1) {
						v1 = *(_DWORD*)(v1 + 396);
						if (!v1)
							break;
						if (nox_window_call_field_93(v1, 21, *v2, v2[1]))
							goto LABEL_9;
					}
					v3 = 0;
					v7 = 0;
				}
			LABEL_9:
				v6 = *v2;
				v2[2] = v3;
				sub_4309B0(v6, v7);
			}
		}
	}
}

//----- (0046B740) --------------------------------------------------------
void sub_46B740() {
	wchar_t* v0;                                  // edi
	wchar_t* v1;                                  // ebx
	int2* v2;                                     // ebp
	unsigned __int16 v3;                          // si
	int v4;                                       // eax
	int v5;                                       // edx
	unsigned __int16 v6;                          // cx
	int v7;                                       // eax
	int v8;                                       // esi
	int v9;                                       // edi
	int v10;                                      // esi
	int v11;                                      // esi
	int v12;                                      // edx
	int v13;                                      // edi
	int v14;                                      // ecx
	int v15;                                      // ebp
	int v16;                                      // ecx
	int v17;                                      // ecx
	int v18;                                      // ecx
	int v19;                                      // ebp
	int v20;                                      // ecx
	_DWORD* v21;                                  // eax
	_DWORD* v22;                                  // eax
	wchar_t* v23;                                 // eax
	_DWORD* v24;                                  // esi
	int v25;                                      // eax
	int v26;                                      // ecx
	int v27;                                      // eax
	int v28;                                      // eax
	int v29;                                      // esi
	int v30;                                      // ecx
	int v31;                                      // eax
	int v32;                                      // eax
	int v33;                                      // eax
	int v34;                                      // ecx
	int v35;                                      // eax
	int v36;                                      // eax
	int v37;                                      // eax
	int i;                                        // ebp
	int v39;                                      // edi
	int v40;                                      // esi
	void(__cdecl * v41)(wchar_t*, wchar_t*, int); // eax
	int v42;                                      // eax
	int v43;                                      // eax
	int v44;                                      // edi
	int v45;                                      // eax
	int v46;                                      // eax
	int v47;                                      // esi
	int v48;                                      // ecx
	int v49;                                      // ecx
	char* v50;                                    // eax
	int v51;                                      // eax
	char* v52;                                    // eax
	int v53;                                      // eax
	int v54;                                      // esi
	wchar_t* v55;                                 // eax
	int v56;                                      // esi
	int v57;                                      // ecx
	int v58;                                      // ecx
	int v59;                                      // edx
	int v60;                                      // [esp+0h] [ebp-2Ch]
	wchar_t* v61;                                 // [esp+4h] [ebp-28h]
	int v62;                                      // [esp+4h] [ebp-28h]
	int v63;                                      // [esp+8h] [ebp-24h]
	int v64;                                      // [esp+Ch] [ebp-20h]
	int2 v65;                                     // [esp+14h] [ebp-18h]
	int v66[4];                                   // [esp+1Ch] [ebp-10h]

	v0 = 0;
	v1 = 0;
	v63 = 0;
	v61 = 0;
	v64 = 0;
	v2 = nox_client_getMousePos_4309F0();
	v65.field_0 = (int)v2;
	v3 = v2->field_4;
	v4 = v2[3].field_0;
	v5 = v2[6].field_0;
	v66[1] = v2[4].field_4;
	v6 = v2->field_0;
	v66[0] = v4;
	v7 = v2[1].field_0;
	v66[2] = v5;
	v8 = v6 | (v3 << 16);
	v66[3] = v7;
	v60 = v8;
	sub_4776B0(0);
	if (dword_5d4594_815132 || sub_477600())
		nox_client_setCursorType_477610(0);
	else
		nox_client_setCursorType_477610(14);
	if (nox_win_unk3) {
		nox_client_setCursorType_477610(0);
		dword_5d4594_1064916 = 0;
		v1 = (wchar_t*)sub_46B5B0(nox_win_unk3, v2->field_0, v2->field_4);
		v62 = 0;
		while (1) {
			v9 = v66[v62];
			if (!v9) {
				if (!v62 && v2[2].field_4 == 1)
					nox_window_call_field_93((int)v1, 8, v60, 0);
				goto LABEL_18;
			}
			v10 = (int)v1;
			if (v1)
				break;
			if (nox_window_call_field_93(nox_win_unk3, v9, v60, 0))
				goto LABEL_14;
		LABEL_18:
			if (++v62 >= 4)
				goto LABEL_123;
		}
		while (!nox_window_call_field_93(v10, v9, v60, 0)) {
			if (v10 != nox_win_unk3) {
				v10 = *(_DWORD*)(v10 + 396);
				if (v10)
					continue;
			}
			goto LABEL_18;
		}
	LABEL_14:
		v66[v62] = 0;
		goto LABEL_18;
	}
	if (dword_5d4594_1064916) {
		nox_client_setCursorType_477610(0);
		switch (v66[0]) {
		case 0:
		case 8:
			if (!(*(_BYTE*)(dword_5d4594_1064916 + 4) & 4) || sub_45D9B0())
				goto LABEL_50;
			v11 = v2[1].field_4;
			v12 = v2[2].field_0;
			v13 = *(_DWORD*)(dword_5d4594_1064916 + 396);
			if (!v13)
				goto LABEL_41;
			v14 = *(_DWORD*)(dword_5d4594_1064916 + 16);
			if (v14 + v11 >= 0) {
				v15 = *(_DWORD*)(dword_5d4594_1064916 + 24);
				v16 = *(_DWORD*)(v13 + 8);
				if (v11 + v15 > v16)
					v11 = v16 - v15;
				v1 = 0;
			} else {
				v11 = -v14;
			}
			v17 = *(_DWORD*)(dword_5d4594_1064916 + 20);
			if (v17 + v12 >= 0) {
				v19 = *(_DWORD*)(dword_5d4594_1064916 + 28);
				v20 = *(_DWORD*)(v13 + 12);
				if (v12 + v19 <= v20) {
				LABEL_41:
					*(_DWORD*)(dword_5d4594_1064916 + 16) += v11;
					*(_DWORD*)(dword_5d4594_1064916 + 20) += v12;
					v21 = *(_DWORD**)&dword_5d4594_1064916;
					if (*(int*)(dword_5d4594_1064916 + 16) < 0) {
						*(_DWORD*)(dword_5d4594_1064916 + 16) = 0;
						v21 = *(_DWORD**)&dword_5d4594_1064916;
					}
					if ((int)v21[5] < 0) {
						v21[5] = 0;
						v21 = *(_DWORD**)&dword_5d4594_1064916;
					}
					v21[6] = v21[2] + v21[4];
					*(_DWORD*)(dword_5d4594_1064916 + 28) =
					    *(_DWORD*)(dword_5d4594_1064916 + 12) +
					    *(_DWORD*)(dword_5d4594_1064916 + 20);
					v22 = *(_DWORD**)&dword_5d4594_1064916;
					if (*(_DWORD*)(dword_5d4594_1064916 + 24) > nox_win_width) {
						*(_DWORD*)(dword_5d4594_1064916 + 24) = nox_win_width;
						v22 = *(_DWORD**)&dword_5d4594_1064916;
					}
					if (v22[7] > nox_win_height) {
						v22[7] = nox_win_height;
						v22 = *(_DWORD**)&dword_5d4594_1064916;
					}
					v2 = (int2*)v65.field_0;
					v22[4] = v22[6] - v22[2];
					v8 = v60;
					*(_DWORD*)(dword_5d4594_1064916 + 20) =
					    *(_DWORD*)(dword_5d4594_1064916 + 28) -
					    *(_DWORD*)(dword_5d4594_1064916 + 12);
				LABEL_50:
					nox_window_call_field_93(*(int*)&dword_5d4594_1064916, 8, v8, 0);
					goto LABEL_51;
				}
				v18 = v20 - v19;
			} else {
				v18 = -v17;
			}
			v12 = v18;
			goto LABEL_41;
		case 6:
			*(_DWORD*)(dword_5d4594_1064916 + 4) &= 0xFFFFFFFE;
			if (sub_46AAB0(*(_DWORD**)&dword_5d4594_1064916, v2->field_0, v2->field_4)) {
				nox_window_call_field_93(*(int*)&dword_5d4594_1064916, 6, v8, 0);
			} else if (*(_BYTE*)(dword_5d4594_1064916 + 4) & 4) {
				nox_window_call_field_93(*(int*)&dword_5d4594_1064916, 6, v8, 0);
			}
			v64 = 1;
			v66[0] = 0;
			goto LABEL_123;
		case 7:
			sub_46B500(*(int*)&dword_5d4594_1064916);
			nox_window_call_field_93(*(int*)&dword_5d4594_1064916, 7, v8, 0);
			v64 = 1;
			v66[0] = 0;
			goto LABEL_123;
		default:
		LABEL_51:
			v66[0] = 0;
			goto LABEL_123;
		}
	}
	if (*(_DWORD*)&byte_5D4594[1064912]) {
		v23 = (wchar_t*)sub_46B5B0(**(_DWORD***)&byte_5D4594[1064912], v2->field_0, v2->field_4);
		goto LABEL_98;
	}
	v24 = *(_DWORD**)&dword_5d4594_1064888;
	if (!dword_5d4594_1064888)
		goto LABEL_69;
	while (1) {
		v25 = v24[1];
		if (v25 & 0x20) {
			if (!(v25 & 0x10)) {
				v26 = v2->field_0;
				if (v2->field_0 >= (int)v24[4] && v26 <= (int)v24[6]) {
					v27 = v2->field_4;
					if (v27 >= (int)v24[5] && v27 <= (int)v24[7]) {
						v28 = sub_46B630((int)v24, v26, v27);
						if (!v0 && (*(_DWORD*)(v28 + 384) || *(_WORD*)(v28 + 240)))
							v0 = (wchar_t*)v28;
						if (v24[1] & 8)
							break;
					}
				}
			}
		}
		v24 = (_DWORD*)v24[97];
		if (!v24)
			goto LABEL_69;
	}
	v61 = v0;
	v1 = (wchar_t*)sub_46B5B0(v24, v2->field_0, v2->field_4);
	if (!v1) {
	LABEL_69:
		v29 = dword_5d4594_1064888;
		if (!dword_5d4594_1064888)
			goto LABEL_83;
		while (1) {
			if (!(*(_BYTE*)(v29 + 4) & 0x70)) {
				v30 = v2->field_0;
				if (v2->field_0 >= *(int*)(v29 + 16) && v30 <= *(int*)(v29 + 24)) {
					v31 = v2->field_4;
					if (v31 >= *(int*)(v29 + 20) && v31 <= *(int*)(v29 + 28)) {
						v32 = sub_46B630(v29, v30, v31);
						if (!v0 && (*(_DWORD*)(v32 + 384) || *(_WORD*)(v32 + 240)))
							v0 = (wchar_t*)v32;
						if (*(_BYTE*)(v29 + 4) & 8)
							break;
					}
				}
			}
			v29 = *(_DWORD*)(v29 + 388);
			if (!v29)
				goto LABEL_83;
		}
		v61 = v0;
		v1 = (wchar_t*)sub_46B5B0((_DWORD*)v29, v2->field_0, v2->field_4);
		if (!v1) {
		LABEL_83:
			v1 = *(wchar_t**)&dword_5d4594_1064888;
			if (!dword_5d4594_1064888)
				goto LABEL_113;
			while (1) {
				v33 = *((_DWORD*)v1 + 1);
				if (v33 & 0x40) {
					if (!(v33 & 0x10)) {
						v34 = v2->field_0;
						if (v2->field_0 >= *((int*)v1 + 4) && v34 <= *((int*)v1 + 6)) {
							v35 = v2->field_4;
							if (v35 >= *((int*)v1 + 5) && v35 <= *((int*)v1 + 7)) {
								v36 = sub_46B630((int)v1, v34, v35);
								if (!v0 &&
								    (*(_DWORD*)(v36 + 384) || *(_WORD*)(v36 + 240)))
									v0 = (wchar_t*)v36;
								if (v1[2] & 8)
									break;
							}
						}
					}
				}
				v1 = (wchar_t*)*((_DWORD*)v1 + 97);
				if (!v1)
					goto LABEL_113;
			}
			v61 = v0;
			v23 = (wchar_t*)sub_46B5B0(v1, v2->field_0, v2->field_4);
		LABEL_98:
			v1 = v23;
			if (!v23)
				goto LABEL_113;
			goto LABEL_99;
		}
	}
LABEL_99:
	v37 = *((_DWORD*)v1 + 1);
	v61 = v1;
	if (v37 & 0x200) {
		v1 = 0;
	} else if (v1) {
		nox_client_setCursorType_477610(0);
		for (i = 0; i < 4; ++i) {
			v39 = v66[i];
			if (v39) {
				v40 = (int)v1;
				if (nox_window_call_field_93((int)v1, v39, v60, 0)) {
				LABEL_107:
					if (!i && v66[0] == 5)
						dword_5d4594_1064916 = v40;
					v66[i] = 0;
				} else {
					while (1) {
						v40 = *(_DWORD*)(v40 + 396);
						if (!v40)
							break;
						if (nox_window_call_field_93(v40, v39, v60, 0))
							goto LABEL_107;
					}
				}
			}
		}
		v0 = v61;
		v2 = (int2*)v65.field_0;
	}
LABEL_113:
	if (!v0 && !sub_46C2A0((int)v1))
		v0 = v1;
	if (sub_430B30()) {
		if (v0) {
			v41 = (void(__cdecl*)(wchar_t*, wchar_t*, int)) * ((_DWORD*)v0 + 96);
			if (v41) {
				v41(v0, v0 + 18, v60);
			} else if (v0[120]) {
				sub_4776B0(v0 + 120);
			}
		} else {
			v63 = 1;
		}
	}
LABEL_123:
	if (!dword_5d4594_1064916 && v1 != *(wchar_t**)&byte_5D4594[1064900]) {
		if (nox_win_unk3) {
			if (nox_window_is_child(nox_win_unk3, *(int*)&byte_5D4594[1064900]))
				nox_window_call_field_93(*(int*)&byte_5D4594[1064900], 18, v60, 0);
		} else if (*(_DWORD*)&byte_5D4594[1064900]) {
			nox_window_call_field_93(*(int*)&byte_5D4594[1064900], 18, v60, 0);
		}
		if (v1)
			nox_window_call_field_93((int)v1, 17, v60, 0);
		*(_DWORD*)&byte_5D4594[1064900] = v1;
	}
	if (sub_4356B0() == 3 && !*(_DWORD*)&byte_5D4594[1064940] && !sub_4372B0() && !sub_413A50() && !sub_477600() &&
	    !sub_4372E0()) {
		v42 = sub_4675B0();
		if (v42 == 5) {
			nox_client_setCursorType_477610(6);
			goto LABEL_201;
		}
		if (v42 == 6) {
			nox_client_setCursorType_477610(8);
			goto LABEL_201;
		}
		v43 = sub_476F90();
		v44 = v43;
		if (v43) {
			if (!(*(_DWORD*)(v43 + 112) & 0x400006) || sub_4C3220(v43) ||
			    *(_DWORD*)(v44 + 112) & 2 && *(_BYTE*)(v44 + 116) & 8 ||
			    *(_DWORD*)(v44 + 112) & 2 && *(_BYTE*)(v44 + 280) & 0x10) {
				v46 = sub_4676A0();
				v47 = dword_5d4594_1064888;
				if (dword_5d4594_1064888) {
					while (1) {
						if (!(*(_BYTE*)(v47 + 4) & 0x10) && v2->field_0 >= *(int*)(v47 + 16) &&
						    v2->field_0 <= *(int*)(v47 + 24)) {
							v48 = v2->field_4;
							if (v48 >= *(int*)(v47 + 20) && v48 <= *(int*)(v47 + 28))
								break;
						}
						v47 = *(_DWORD*)(v47 + 388);
						if (!v47)
							goto LABEL_175;
					}
					if (v47 == v46 &&
					    ((v49 = v2->field_4, v65.field_0 = v2->field_0, v65.field_4 = v49,
					      v50 = sub_4676B0(), v51 = sub_4281F0(&v65, (int4*)v50), v51) ||
					     (v52 = sub_4676C0(), v53 = sub_4281F0(&v65, (int4*)v52), v53))) {
						v63 = 1;
					} else if (v47 && sub_46C2A0(v47) != 1) {
						goto LABEL_201;
					}
				}
			LABEL_175:
				sub_435670(&v65);
				v54 = (v65.field_0 - *(_DWORD*)(v44 + 12)) * (v65.field_0 - *(_DWORD*)(v44 + 12)) +
				      (v65.field_4 - *(_DWORD*)(v44 + 16)) * (v65.field_4 - *(_DWORD*)(v44 + 16));
				if ((int)*(_DWORD*)(v44 + 112) >= 0 || sub_477680()) {
					if (v54 < 15625) {
						if (*(_DWORD*)&byte_5D4594[2618908]) {
							v57 = *(_DWORD*)(*(_DWORD*)&byte_5D4594[2618908] + 3680);
							if (!(v57 & 0x200) && !sub_478030()) {
								if (*(_DWORD*)(v44 + 112) & 2 &&
								    *(_BYTE*)(v44 + 280) & 0x10) {
									nox_client_setCursorType_477610(4);
								} else if (*(_DWORD*)(v44 + 112) & 2 &&
									   *(_BYTE*)(v44 + 116) & 8) {
									nox_client_setCursorType_477610(3);
								}
							}
						}
					}
				} else {
					if (v63 == 1) {
						v55 = sub_4BF050((wchar_t*)v44);
						sub_4776B0(v55);
					}
					if (v54 >= 5625) {
						nox_client_setCursorType_477610(15);
					} else {
						if (nox_common_gameFlags_check_40A5C0(6144) || sub_57B450((int*)v44))
							nox_client_setCursorType_477610(2);
						else
							nox_client_setCursorType_477610(16);
						v56 = sub_430AF0();
						if (v66[v56] == sub_430B00()) {
							sub_46C140(v44);
							v66[sub_430AF0()] = 0;
						}
					}
				}
			} else {
				v45 = *(_DWORD*)&byte_5D4594[1064944];
				if (!*(_DWORD*)&byte_5D4594[1064944]) {
					v45 = sub_44CFC0((CHAR*)&byte_587000[143184]);
					*(_DWORD*)&byte_5D4594[1064944] = v45;
				}
				if (*(_DWORD*)(v44 + 112) & 0x400000 && (*(_BYTE*)(v44 + 116) & 0x80) &&
					!(*(_BYTE*)(v44 + 280) & 0xC) ||
				    *(_DWORD*)(v44 + 108) == v45 && !*(_DWORD*)(v44 + 276)) {
					sub_435670(&v65);
					if ((v65.field_0 - *(_DWORD*)(v44 + 12)) *
							(v65.field_0 - *(_DWORD*)(v44 + 12)) +
						    (v65.field_4 - *(_DWORD*)(v44 + 16)) *
							(v65.field_4 - *(_DWORD*)(v44 + 16)) <
						5625 &&
					    (*(_DWORD*)(v44 + 120) & 0x1000000) == 0x1000000 &&
					    !(*(_BYTE*)(v44 + 280) & 0xC)) {
						nox_client_setCursorType_477610(13);
					}
				}
			}
		} else if (sub_479590() == 2) {
			nox_client_setCursorType_477610(11);
		} else if (sub_479590() == 3) {
			nox_client_setCursorType_477610(12);
		}
	}
LABEL_201:
	v58 = v66[1];
	v59 = v66[2];
	v2[3].field_0 = v66[0];
	v2[1].field_0 = v66[3];
	v2[4].field_4 = v58;
	v2[6].field_0 = v59;
	if (v64 == 1)
		dword_5d4594_1064916 = 0;
	sub_46C200();
}
// 46BF71: variable 'v51' is possibly undefined
// 46BF88: variable 'v53' is possibly undefined

//----- (0046C200) --------------------------------------------------------
void sub_46C200() {
	int v0;  // esi
	bool v1; // zf
	int v2;  // edi

	v0 = *(_DWORD*)&byte_5D4594[1064896];
	v1 = *(_DWORD*)&byte_5D4594[1064896] == 0;
	*(_DWORD*)&byte_5D4594[1064896] = 0;
	if (!v1) {
		do {
			v2 = *(_DWORD*)(v0 + 388);
			if (nox_win_unk3 == v0)
				sub_46ADE0(v0);
			if (nox_win_unk2 == v0)
				sub_46B500(0);
			if (*(_DWORD*)&byte_5D4594[1064912] && v0 == **(_DWORD**)&byte_5D4594[1064912])
				sub_46C6E0(**(_DWORD**)&byte_5D4594[1064912]);
			if (*(_DWORD*)&byte_5D4594[1064900] == v0)
				*(_DWORD*)&byte_5D4594[1064900] = 0;
			if (dword_5d4594_1064916 == v0)
				dword_5d4594_1064916 = 0;
			nox_window_call_field_94(v0, 2, 0, 0);
			sub_414330(nox_alloc_window, (_QWORD*)v0);
			v0 = v2;
		} while (v2);
	}
}

//----- (0046C2A0) --------------------------------------------------------
int __cdecl sub_46C2A0(int a1) {
	int v2; // eax

	if (!a1)
		return 1;
	if (*(_BYTE*)(a1 + 4) & 0x10)
		return 1;
	v2 = *(_DWORD*)(a1 + 396);
	if (v2) {
		while (!(*(_BYTE*)(v2 + 4) & 0x10)) {
			v2 = *(_DWORD*)(v2 + 396);
			if (!v2)
				return 0;
		}
		return 1;
	}
	return 0;
}

//----- (0046C2E0) --------------------------------------------------------
void mainloop_draw() {
	if (nox_win_unk4) {
		// background and some UI parts
		nox_window* v1 = nox_win_unk4;
		nox_window* v2 = 0;
		do {
			v2 = v1->field_98;
			if (v1->flags & NOX_WIN_LAYER_BACK) {
				nox_window_draw_recursive(v1);
			}
			v1 = v2;
		} while (v2);
	}
	if (nox_win_unk4) {
		nox_window* v3 = nox_win_unk4;
		nox_window* v4 = 0;
		do {
			v4 = v3->field_98;
			if ((v3->flags & (NOX_WIN_LAYER_BACK | NOX_WIN_LAYER_FRONT)) == 0) {
				nox_window_draw_recursive(v3);
			}
			v3 = v4;
		} while (v4);
	}
	if (nox_win_unk4) {
		nox_window* v5 = nox_win_unk4;
		nox_window* v6 = 0;
		do {
			v6 = v5->field_98;
			if (v5->flags & NOX_WIN_LAYER_FRONT)
				nox_window_draw_recursive(v5);
			v5 = v6;
		} while (v6);
	}
}

//----- (0046C370) --------------------------------------------------------
int __cdecl nox_window_draw_recursive(nox_window* win) {
	if (!win)
		return -2;
	if (win->flags & NOX_WIN_HIDDEN)
		return 0;

	if (win->draw_func)
		win->draw_func(win, win->field_9);
	if ((win->flags & 0x1000) == 0x1000)
		sub_4AA030(win, win->field_9);

	for (nox_window* i = win->field_100; i; i = i->field_97)
		nox_window_draw_recursive(i);
	return 0;
}

//----- (0046C3E0) --------------------------------------------------------
nox_window* __cdecl nox_window_new(nox_window* a1, int flags, int a3, int a4, int w, int h,
				   int (*fnc)(int, int, int, int)) {
	nox_alloc_class* al = nox_alloc_window;
	if (!al) {
		al = nox_new_alloc_class("Window", sizeof(nox_window), 576);
		nox_alloc_window = al;
	}
	if (!al)
		return 0;

	nox_window* win = (nox_window*)nox_alloc_class_new_obj_zero(al);
	if (!win)
		return 0;

	if (a1) {
		nox_window_set_ptrs_97(win, a1);
	} else {
		sub_46A920((int)win);
	}
	win->field_0 = 0;
	win->flags = flags;
	win->width = w;
	win->height = h;
	win->field_4 = a3;
	win->field_5 = a4;
	*((_WORD*)win + 120) = 0;
	win->field_6 = w + a3;
	win->field_7 = h + a4;
	sub_46A9F0(win);
	win->draw_func = sub_46B370;
	win->field_93 = sub_46B330;
	if (fnc) {
		win->field_94 = fnc;
		nox_window_call_field_94((int)win, 1, 0, 0);
	} else {
		win->field_94 = sub_46B2F0;
	}
	memset(win->field_9, 0, 332);
	win->field_92 = 0;
	return win;
}

//----- (0046C4E0) --------------------------------------------------------
int __cdecl sub_46C4E0(_DWORD* a1) {
	int v2;     // eax
	_DWORD* v3; // eax
	_DWORD* v4; // edi

	if (!a1)
		return -2;
	v2 = a1[1];
	if (!(v2 & 0x800)) {
		BYTE1(v2) |= 8u;
		a1[1] = v2;
		sub_46AC60((int)a1);
		if (nox_win_unk3 == a1)
			sub_46ADE0((int)a1);
		if (nox_win_unk2 == a1)
			sub_46B500(0);
		if (*(_DWORD*)&byte_5D4594[1064912] && a1 == **(_DWORD***)&byte_5D4594[1064912])
			sub_46C6E0(**(_DWORD**)&byte_5D4594[1064912]);
		if (*(_DWORD**)&byte_5D4594[1064900] == a1)
			*(_DWORD*)&byte_5D4594[1064900] = 0;
		if (*(_DWORD**)&dword_5d4594_1064916 == a1)
			dword_5d4594_1064916 = 0;
		v3 = (_DWORD*)a1[100];
		if (v3) {
			do {
				v4 = (_DWORD*)v3[97];
				sub_46C4E0(v3);
				v3 = v4;
			} while (v4);
		}
		if (a1[99])
			sub_46B180(a1);
		else
			sub_46A960((int)a1);
		a1[98] = 0;
		a1[97] = *(_DWORD*)&byte_5D4594[1064896];
		*(_DWORD*)&byte_5D4594[1064896] = a1;
	}
	return 0;
}

//----- (0046C5D0) --------------------------------------------------------
int sub_46C5D0() {
	_DWORD* v0; // eax
	_DWORD* v1; // esi

	v0 = *(_DWORD**)&dword_5d4594_1064888;
	if (dword_5d4594_1064888) {
		do {
			v1 = (_DWORD*)v0[97];
			sub_46C4E0(v0);
			v0 = v1;
		} while (v1);
	}
	sub_46C200();
	sub_4144D0(nox_alloc_window);
	return 0;
}

//----- (0046C610) --------------------------------------------------------
int sub_46C610() {
	_DWORD* v0;   // eax
	_DWORD* v1;   // eax
	char v3[332]; // [esp+0h] [ebp-14Ch]

	v0 = nox_window_new(0, 12, 100, 100, 200, 200, 0);
	*(_DWORD*)&v3[20] = 4;
	sub_46AF80_copy_window_part((int)v0, v3);
	v1 = nox_window_new(0, 12, 150, 150, 200, 200, 0);
	*(_DWORD*)&v3[20] = 8;
	sub_46AF80_copy_window_part((int)v1, v3);
	return 1;
}

//----- (0046C690) --------------------------------------------------------
int __cdecl sub_46C690(int a1) {
	_DWORD* v2; // eax

	if (!a1)
		return -2;
	if (*(_DWORD*)(a1 + 396))
		return -3;
	v2 = nox_malloc(8u);
	if (!v2)
		return -1;
	*v2 = a1;
	v2[1] = *(_DWORD*)&byte_5D4594[1064912];
	*(_DWORD*)&byte_5D4594[1064912] = v2;
	return 0;
}

//----- (0046C6E0) --------------------------------------------------------
int __cdecl sub_46C6E0(int a1) {
	int v2; // esi

	if (!a1)
		return -2;
	if (!*(_DWORD*)&byte_5D4594[1064912] || **(_DWORD**)&byte_5D4594[1064912] != a1)
		return -1;
	v2 = *(_DWORD*)(*(_DWORD*)&byte_5D4594[1064912] + 4);
	free(*(LPVOID*)&byte_5D4594[1064912]);
	*(_DWORD*)&byte_5D4594[1064912] = v2;
	return 0;
}

//----- (0046C720) --------------------------------------------------------
int sub_46C720() { return dword_5d4594_1064916; }

//----- (0046CC70) --------------------------------------------------------
int sub_46CC70() {
	sub_4DB130((const char*)&byte_5D4594[1082840]);
	sub_4DB170(1, 0, 0);
	return sub_46D6F0();
}

//----- (0046CC90) --------------------------------------------------------
int sub_46CC90() { return sub_46ADC0(*(int*)&dword_5d4594_1082856); }

//----- (0046CCA0) --------------------------------------------------------
int sub_46CCA0(int a1, int a2, int a3, int a4) { return 1; }

//----- (0046CCB0) --------------------------------------------------------
int sub_46CCB0() {
	int result; // eax

	sub_46C4E0(*(_DWORD**)&dword_5d4594_1082856);
	result = 0;
	dword_5d4594_1082856 = 0;
	*(_DWORD*)&byte_5D4594[1082864] = 0;
	*(_DWORD*)&byte_5D4594[1082868] = 0;
	return result;
}

//----- (0046CCD0) --------------------------------------------------------
int __cdecl sub_46CCD0(int a1, int a2) {
	int result;  // eax
	char* v3;    // esi
	char* v4;    // eax
	char v5[12]; // [esp+Ch] [ebp-18h]
	char v6[12]; // [esp+18h] [ebp-Ch]

	sub_4DC970((char*)(a1 + 4), v5);
	sub_4DC970((char*)(a1 + 4), v6);
	if (!strcmp(v5, "AUTOSAVE"))
		return -1;
	if (!strcmp(v6, "AUTOSAVE"))
		return 1;
	v3 = sub_4DC9B0((char*)(a1 + 4));
	v4 = sub_4DC9B0((char*)(a2 + 4));
	if (v3 == v4)
		result = 0;
	else
		result = (int)v3 <= (int)v4 ? -1 : 1;
	return result;
}

//----- (0046CD70) --------------------------------------------------------
int __cdecl sub_46CD70(_BYTE* a1) {
	char v2[12]; // [esp+0h] [ebp-Ch]

	if (*a1 & 8)
		return 10;
	sub_4DC970(a1 + 4, v2);
	return (strcmp(v2, "AUTOSAVE") != 0) + 13;
}

//----- (0046CDC0) --------------------------------------------------------
int __cdecl sub_46CDC0(int a1) {
	int v1;                    // ebp
	int v2;                    // ebx
	const SYSTEMTIME* v3;      // esi
	struct _FILETIME FileTime; // [esp+10h] [ebp-10h]
	FILETIME FileTime2;        // [esp+18h] [ebp-8h]

	v1 = -1;
	v2 = 0;
	v3 = (const SYSTEMTIME*)(a1 + 1188);
	do {
		if (strlen((const char*)&v3[-74])) {
			SystemTimeToFileTime(v3, &FileTime);
			if (v1 == -1 || CompareFileTime(&FileTime, &FileTime2) == 1) {
				v1 = v2;
				FileTime2 = FileTime;
			}
		}
		++v2;
		v3 = (const SYSTEMTIME*)((char*)v3 + 1278);
	} while (v2 < 14);
	return v1;
}

//----- (0046D6F0) --------------------------------------------------------
int sub_46D6F0() {
	memset(&byte_5D4594[1064948], 0, 0x45E4u);
	if (wndIsShown_sub_46ACC0(*(int*)&dword_5d4594_1082856))
		return 0;
	nox_window_set_hidden(*(int*)&dword_5d4594_1082856, 1);
	sub_46ABB0(*(int*)&dword_5d4594_1082856, 0);
	sub_46ADE0(*(int*)&dword_5d4594_1082856);
	sub_413A00(0);
	return 1;
}

//----- (0046D750) --------------------------------------------------------
int __cdecl sub_46D750(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10) {
	int v10; // edi
	int v11; // ecx
	int v12; // esi

	if (!a1 || a4 - a2 <= 0 || a5 - a3 <= 0)
		return -1;
	v10 = a6;
	if (a6 < 1)
		v10 = 1;
	v11 = a7;
	if (a7 < 0)
		v11 = 0;
	v12 = a8;
	if (a8 < 0)
		v12 = 0;
	*(_DWORD*)&byte_5D4594[1082924] = a5 - a3;
	*(_DWORD*)&byte_5D4594[1082916] = a1;
	*(_DWORD*)&byte_5D4594[1082920] = a4 - a2 - (a4 - a2) % 4;
	*(_DWORD*)&byte_5D4594[1082896] = a2;
	*(_DWORD*)&byte_587000[145540] = v10;
	*(_DWORD*)&byte_5D4594[1082892] = a3;
	*(_DWORD*)&byte_587000[145544] = v11;
	*(_DWORD*)&byte_587000[145548] = v11;
	*(_DWORD*)&byte_587000[145552] = v12;
	*(_DWORD*)&byte_5D4594[1082908] = a4;
	*(_DWORD*)&byte_5D4594[1082912] = a5;
	*(_DWORD*)&byte_5D4594[1082904] = a9;
	*(_DWORD*)&byte_5D4594[1082900] = a10;
	return 0;
}

//----- (0046D830) --------------------------------------------------------
int sub_46D830() {
	__int16* v1; // ebp
	int v2;      // ebx
	int v3;      // edi
	__int16* v4; // esi
	int v5;      // [esp+4h] [ebp-Ch]
	int v6;      // [esp+8h] [ebp-8h]
	int v7;      // [esp+Ch] [ebp-4h]

	if ((int)*(_DWORD*)&byte_587000[145548] < 0)
		return 0;
	if ((int)--*(_DWORD*)&byte_587000[145548] >= 0)
		goto LABEL_15;
	v1 = *(__int16**)&byte_5D4594[1082916];
	if (!*(_DWORD*)&byte_5D4594[1082916])
		return 0;
	v5 = *(_DWORD*)&byte_5D4594[1082896];
	v7 = *(_DWORD*)&byte_587000[145540];
	if (dword_5d4594_3801780 == 1) {
		v7 = 2 * *(_DWORD*)&byte_587000[145540];
		v5 = 2 * *(_DWORD*)&byte_5D4594[1082896];
	}
	v2 = *(_DWORD*)&byte_5D4594[1082892];
	v3 = 0;
	v4 = (__int16*)(v5 + *(_DWORD*)(dword_5d4594_3798784 + 4 * *(_DWORD*)&byte_5D4594[1082892]));
	v6 = 0;
	while (v6 < *(int*)&byte_5D4594[1082924]) {
		*v1 = sub_4A9B70(v4);
		v4 = (__int16*)((char*)v4 + v7);
		v3 += *(_DWORD*)&byte_587000[145540];
		++v1;
		if (v3 >= *(int*)&byte_5D4594[1082920]) {
			v2 += *(_DWORD*)&byte_587000[145540];
			v3 = 0;
			v6 += *(_DWORD*)&byte_587000[145540];
			v4 = (__int16*)(v5 + *(_DWORD*)(dword_5d4594_3798784 + 4 * v2));
		}
	}
	if ((int)*(_DWORD*)&byte_587000[145552] >= 0) {
		if (--*(int*)&byte_587000[145552] >= 0)
			*(_DWORD*)&byte_587000[145548] = *(_DWORD*)&byte_587000[145544];
	LABEL_15:
		if (*(_DWORD*)&byte_5D4594[1082904])
			(*(void(__cdecl**)(_DWORD)) & byte_5D4594[1082904])(*(_DWORD*)&byte_5D4594[1082900]);
	}
	return 1;
}

//----- (0046D950) --------------------------------------------------------
void __cdecl sub_46D950(_DWORD* a1) {
	int v2;        // edx
	char v3[1024]; // [esp+0h] [ebp-400h]

	v2 = ++*(_DWORD*)&byte_5D4594[1082928];
	if (!a1[257]) {
		if (a1[256])
			nox_sprintf(v3, "%s%d.bmp", a1, v2);
		else
			nox_sprintf(v3, "%s.bmp", a1);
		sub_46D9D0((int)v3, *(int*)&byte_5D4594[1082916], *(LPVOID*)&byte_5D4594[1082920],
			   *(int*)&byte_5D4594[1082924]);
	}
}

//----- (0046D9D0) --------------------------------------------------------
FILE* __cdecl sub_46D9D0(int a1, int a2, LPVOID lpMem, int a4) {
	int v4;                  // ebp
	size_t v5;               // edi
	int v6;                  // esi
	size_t v7;               // eax
	char* v8;                // eax
	unsigned int v9;         // edx
	_BYTE* v10;              // ecx
	unsigned int v11;        // edx
	_BYTE* v12;              // eax
	FILE* result;            // eax
	FILE* v14;               // esi
	char* v15;               // ebx
	unsigned __int8 v16[14]; // [esp+10h] [ebp-38h]
	unsigned __int8 v17[40]; // [esp+20h] [ebp-28h]
	char* lpMema;            // [esp+54h] [ebp+Ch]

	v4 = a4;
	v5 = (size_t)lpMem;
	v6 = a4 * (_DWORD)lpMem;
	*(_DWORD*)v17 = 40;
	*(_DWORD*)&v17[4] = lpMem;
	v7 = 3 * a4 * (_DWORD)lpMem;
	*(_DWORD*)&v17[8] = a4;
	*(_WORD*)&v17[12] = 1;
	*(_WORD*)&v17[14] = 24;
	*(_DWORD*)&v17[32] = 0;
	*(_DWORD*)&v17[16] = 0;
	*(_DWORD*)&v17[20] = 3 * a4 * (_DWORD)lpMem;
	*(_DWORD*)&v17[24] = 0;
	*(_DWORD*)&v17[28] = 0;
	*(_DWORD*)&v17[36] = 0;
	*(_WORD*)v16 = 19778;
	*(_WORD*)&v16[6] = 0;
	*(_WORD*)&v16[8] = 0;
	*(_DWORD*)&v16[10] = 54;
	*(_DWORD*)&v16[2] = v7 + 54;
	v8 = (char*)nox_malloc(v7);
	v10 = (_BYTE*)a2;
	lpMema = v8;
	if (v6 > 0) {
		do {
			LOBYTE(v9) = *v10;
			v10 += 2;
			*v8 = 8 * v9;
			LOWORD(v9) = *((_WORD*)v10 - 1);
			v11 = v9 >> 2;
			v12 = v8 + 1;
			*v12 = v11 & 0xF8;
			LOWORD(v11) = *((_WORD*)v10 - 1);
			v9 = v11 >> 7;
			*++v12 = v9 & 0xF8;
			v8 = v12 + 1;
			--v6;
		} while (v6);
	}
	result = fopen((const char*)a1, "wb");
	v14 = result;
	if (result) {
		fwrite(v16, 0xEu, 1u, result);
		fwrite(v17, 0x28u, 1u, v14);
		v15 = &lpMema[2 * v5 * (a4 - 1) + v5 * (a4 - 1)];
		if (a4 > 0) {
			do {
				fwrite(v15, v5, 3u, v14);
				v15 -= 3 * v5;
				--v4;
			} while (v4);
		}
		fclose(v14);
		free(lpMema);
	}
	return result;
}
// 46DA62: variable 'v9' is possibly undefined

//----- (0046DB00) --------------------------------------------------------
int sub_46DB00() {
	if (!*(_DWORD*)&byte_5D4594[1083964]) {
		*(_DWORD*)&byte_5D4594[1083964] = nox_malloc(2 * nox_win_width * nox_win_height);
		strcpy((char*)&byte_5D4594[1082932], "nox");
		*(_DWORD*)&byte_5D4594[1083956] = 1;
		*(_DWORD*)&byte_5D4594[1083960] = 0;
	}
	sub_409EC0(4096);
	return sub_46D750(*(int*)&byte_5D4594[1083964], 0, 0, nox_win_width, nox_win_height, 1, 0, 0, sub_46D950,
			  (int)&byte_5D4594[1082932]);
}

//----- (0046DB80) --------------------------------------------------------
int sub_46DB80() {
	int i;      // esi
	int result; // eax

	for (i = 0; i < 8; i += 4) {
		nox_window_call_field_94(*(_DWORD*)&byte_5D4594[i + 1090060], 16399, 1, 0);
		nox_window_call_field_94(*(_DWORD*)&byte_5D4594[i + 1090068], 16399, 1, 0);
		nox_window_call_field_94(*(_DWORD*)&byte_5D4594[i + 1090076], 16399, 1, 0);
		nox_window_call_field_94(*(_DWORD*)&byte_5D4594[i + 1090084], 16399, 1, 0);
		result = nox_window_call_field_94(*(_DWORD*)&byte_5D4594[i + 1090092], 16399, 1, 0);
	}
	return result;
}

//----- (0046DC00) --------------------------------------------------------
int __cdecl sub_46DC00(int a1, unsigned __int8 a2, int a3) {
	nox_window_call_field_94(a1, 16397, a3, a2);
	return 1;
}

//----- (0046DC30) --------------------------------------------------------
int sub_46DC30(int a1, unsigned __int8 a2, wchar_t* a3, ...) {
	va_list va; // [esp+10h] [ebp+10h]

	va_start(va, a3);
	nox_vswprintf((wchar_t*)&byte_5D4594[1089000], a3, va);
	return sub_46DC00(a1, a2, (int)&byte_5D4594[1089000]);
}

//----- (0046DCC0) --------------------------------------------------------
char* sub_46DCC0() {
	char* result;        // eax
	signed int v1;       // ebx
	unsigned int v2;     // esi
	unsigned int v3;     // edi
	int v4;              // ebp
	char* k;             // esi
	int v6;              // eax
	char* l;             // eax
	int v8;              // ecx
	int v9;              // ebx
	int v10;             // esi
	char* v11;           // edi
	int m;               // ebp
	unsigned __int8 v13; // dl
	int v14;             // eax
	int v15;             // ecx
	int v16;             // edi
	_DWORD* v17;         // eax
	_DWORD* v18;         // edi
	char* v19;           // eax
	int v20;             // edx
	unsigned __int8 v21; // al
	int v22;             // ecx
	unsigned int v23;    // esi
	char* i;             // eax
	int v25;             // ecx
	unsigned int v26;    // ebp
	int v27;             // esi
	char* v28;           // edi
	unsigned int j;      // ebx
	unsigned __int8 v30; // dl
	int v31;             // eax
	int v32;             // ecx
	int v33;             // ecx
	int v34;             // edi
	_DWORD* v35;         // eax
	_DWORD* v36;         // edi
	char* v37;           // eax
	int v38;             // edx
	unsigned __int8 v39; // al
	int v40;             // ecx
	unsigned int v41;    // [esp+0h] [ebp-8h]
	wchar_t* v42;        // [esp+4h] [ebp-4h]
	wchar_t* v43;        // [esp+4h] [ebp-4h]

	if (dword_5d4594_1090120 == 5) {
		v23 = sub_416F40();
		v43 = (wchar_t*)v23;
		byte_5D4594[1090117] = 0;
		byte_5D4594[1090118] = 0;
		if (nox_common_gameFlags_check_40A5C0(1) && *(_DWORD*)&nox_common_engineFlags & 0x40000)
			v43 = (wchar_t*)--v23;
		for (i = sub_416EA0(); i; i = sub_416EE0((int)i)) {
			v25 = *((_DWORD*)i + 920);
			if (!(v25 & 1) || v25 & 0x20) {
				if (!*((_DWORD*)i + 527))
					*((_DWORD*)i + 527) = 0x8000000;
			} else {
				*((_DWORD*)i + 527) |= 0x80000000;
			}
		}
		v26 = 0;
		if (byte_5D4594[1090117] < v23) {
			v27 = (int)v43;
			do {
				v28 = sub_416EA0();
				for (j = -1; v28; v28 = sub_416EE0((int)v28)) {
					if ((v28[2064] != 31 || !(*(_DWORD*)&nox_common_engineFlags & 0x40000)) &&
					    *((int*)v28 + 527) >= v26 && !sub_46E1E0(*((_DWORD*)v28 + 515)) &&
					    *((int*)v28 + 527) < j) {
						j = *((_DWORD*)v28 + 527);
						v27 = (int)v28;
					}
				}
				v30 = byte_5D4594[1090117];
				v31 = 80 * byte_5D4594[1090117];
				*(_DWORD*)&byte_5D4594[v31 + 1084192] = *(_DWORD*)(v27 + 2060);
				v32 = *(_DWORD*)(v27 + 3680);
				if (!(v32 & 1) || v32 & 0x20) {
					v33 = *(_DWORD*)(v27 + 2108);
					if (v33 == 0x8000000) {
						*(_DWORD*)&byte_5D4594[v31 + 1084196] = 0;
					} else {
						*(_DWORD*)&byte_5D4594[v31 + 1084196] = v33;
						++byte_5D4594[1090118];
					}
				} else {
					*(_DWORD*)&byte_5D4594[v31 + 1084196] = *(_DWORD*)(v27 + 2108) + 0x80000000;
				}
				*(_DWORD*)&byte_5D4594[v31 + 1084200] = *(unsigned __int16*)(v27 + 2148);
				*(_DWORD*)&byte_5D4594[v31 + 1084208] = *(_DWORD*)(v27 + 3680);
				v34 = 80 * v30;
				*(_DWORD*)&byte_5D4594[v34 + 1084204] = sub_46E080(v27);
				nox_wcscpy((wchar_t*)&byte_5D4594[v34 + 1084132], (const wchar_t*)(v27 + 4704));
				sub_46E170((wchar_t*)&byte_5D4594[80 * byte_5D4594[1090117] + 1084132]);
				byte_5D4594[80 * byte_5D4594[1090117] + 1084188] = *(_BYTE*)(v27 + 2251);
				v35 = sub_418C80(*(_DWORD*)(v27 + 2060));
				v36 = v35;
				if (v35 && sub_419130((int)v35)) {
					v37 = sub_418AB0(*((unsigned __int8*)v36 + 4));
					if (v37) {
						v38 = (unsigned __int8)v37[57];
						v39 = byte_5D4594[1090117];
						*(_DWORD*)&byte_5D4594[80 * byte_5D4594[1090117] + 1084184] = v38;
					} else {
						v39 = byte_5D4594[1090117];
						*(_DWORD*)&byte_5D4594[80 * byte_5D4594[1090117] + 1084184] = -1;
					}
				} else {
					v39 = byte_5D4594[1090117];
					*(_DWORD*)&byte_5D4594[80 * byte_5D4594[1090117] + 1084184] = -1;
				}
				byte_5D4594[1090117] = v39 + 1;
				v26 = j;
			} while ((unsigned __int8)(v39 + 1) < (unsigned int)v43);
		}
		for (result = sub_416EA0(); result; result = sub_416EE0((int)result)) {
			v40 = *((_DWORD*)result + 920);
			if (!(v40 & 1) || v40 & 0x20) {
				if (*((_DWORD*)result + 527) == 0x8000000)
					*((_DWORD*)result + 527) = 0;
			} else {
				*((_DWORD*)result + 527) &= 0x7FFFFFFFu;
			}
		}
	} else if (nox_common_gameFlags_check_40A5C0(1024)) {
		v1 = 0x80000000;
		v41 = sub_416F40();
		v2 = sub_417DD0();
		byte_5D4594[1090116] = 0;
		v42 = (wchar_t*)v2;
		byte_5D4594[1090117] = 0;
		byte_5D4594[1090118] = 0;
		if (nox_common_gameFlags_check_40A5C0(1) && *(_DWORD*)&nox_common_engineFlags & 0x40000)
			--v41;
		if (byte_5D4594[1090116] < v2) {
			v3 = v2;
			do {
				v4 = 0x7FFFFFFF;
				for (k = sub_418B10(); k; k = sub_418B60((int)k)) {
					if (*((int*)k + 13) >= v1 && !sub_46E130((unsigned __int8)k[57]) &&
					    *((int*)k + 13) < v4) {
						v4 = *((_DWORD*)k + 13);
						v3 = (unsigned int)k;
					}
				}
				v6 = 56 * byte_5D4594[1090116];
				*(_DWORD*)&byte_5D4594[v6 + 1087252] = *(_DWORD*)(v3 + 52);
				*(_DWORD*)&byte_5D4594[v6 + 1087248] = *(unsigned __int8*)(v3 + 57);
				byte_5D4594[v6 + 1087256] = *(_BYTE*)(v3 + 56);
				nox_wcscpy((wchar_t*)&byte_5D4594[v6 + 1087204], (const wchar_t*)v3);
				sub_46E170((wchar_t*)&byte_5D4594[56 * byte_5D4594[1090116] + 1087204]);
				++byte_5D4594[1090116];
				v1 = v4;
			} while (byte_5D4594[1090116] < (unsigned int)v42);
		}
		for (l = sub_416EA0(); l; l = sub_416EE0((int)l)) {
			v8 = *((_DWORD*)l + 920);
			if (v8 & 1 && !(v8 & 0x20))
				*((_DWORD*)l + 535) += 0xFFFF;
		}
		v9 = -1;
		if (byte_5D4594[1090117] < v41) {
			v10 = (int)v42;
			do {
				v11 = sub_416EA0();
				for (m = 0x7FFFFFFF; v11; v11 = sub_416EE0((int)v11)) {
					if ((v11[2064] != 31 || !(*(_DWORD*)&nox_common_engineFlags & 0x40000)) &&
					    *((int*)v11 + 535) >= v9 && !sub_46E1E0(*((_DWORD*)v11 + 515)) &&
					    *((int*)v11 + 535) < m) {
						m = *((_DWORD*)v11 + 535);
						v10 = (int)v11;
					}
				}
				v13 = byte_5D4594[1090117];
				v14 = 80 * byte_5D4594[1090117];
				*(_DWORD*)&byte_5D4594[v14 + 1084192] = *(_DWORD*)(v10 + 2060);
				v15 = *(_DWORD*)(v10 + 3680);
				if (!(v15 & 1) || v15 & 0x20) {
					*(_DWORD*)&byte_5D4594[v14 + 1084196] = *(_DWORD*)(v10 + 2140);
					++byte_5D4594[1090118];
				} else {
					*(_DWORD*)&byte_5D4594[v14 + 1084196] = *(_DWORD*)(v10 + 2140) - 0xFFFF;
				}
				*(_DWORD*)&byte_5D4594[v14 + 1084200] = *(unsigned __int16*)(v10 + 2148);
				*(_DWORD*)&byte_5D4594[v14 + 1084208] = *(_DWORD*)(v10 + 3680);
				v16 = 80 * v13;
				*(_DWORD*)&byte_5D4594[v16 + 1084204] = sub_46E080(v10);
				nox_wcscpy((wchar_t*)&byte_5D4594[v16 + 1084132], (const wchar_t*)(v10 + 4704));
				sub_46E170((wchar_t*)&byte_5D4594[80 * byte_5D4594[1090117] + 1084132]);
				byte_5D4594[80 * byte_5D4594[1090117] + 1084188] = *(_BYTE*)(v10 + 2251);
				v17 = sub_418C80(*(_DWORD*)(v10 + 2060));
				v18 = v17;
				if (v17 && sub_419130((int)v17)) {
					v19 = sub_418AB0(*((unsigned __int8*)v18 + 4));
					if (v19) {
						v20 = (unsigned __int8)v19[57];
						v21 = byte_5D4594[1090117];
						*(_DWORD*)&byte_5D4594[80 * byte_5D4594[1090117] + 1084184] = v20;
					} else {
						v21 = byte_5D4594[1090117];
						*(_DWORD*)&byte_5D4594[80 * byte_5D4594[1090117] + 1084184] = -1;
					}
				} else {
					v21 = byte_5D4594[1090117];
					*(_DWORD*)&byte_5D4594[80 * byte_5D4594[1090117] + 1084184] = -1;
				}
				byte_5D4594[1090117] = v21 + 1;
				v9 = m;
			} while ((unsigned __int8)(v21 + 1) < v41);
		}
		for (result = sub_416EA0(); result; result = sub_416EE0((int)result)) {
			v22 = *((_DWORD*)result + 920);
			if (v22 & 1) {
				if (!(v22 & 0x20))
					*((_DWORD*)result + 535) -= 0xFFFF;
			}
		}
	} else {
		result = sub_46E4E0();
	}
	return result;
}

//----- (0046E080) --------------------------------------------------------
int __cdecl sub_46E080(int a1) {
	int v1;     // eax
	_DWORD* v3; // eax

	if (nox_common_gameFlags_check_40A5C0(32)) {
		v1 = *(_DWORD*)(a1 + 2060);
		if (v1 == *(unsigned __int16*)&byte_5D4594[1090128])
			return 2;
		if (v1 == *(unsigned __int16*)&byte_5D4594[1090130])
			return 3;
	} else if (nox_common_gameFlags_check_40A5C0(64)) {
		if (*(_DWORD*)(a1 + 2060) == *(unsigned __int16*)&byte_5D4594[1090132])
			return 4;
	} else if (nox_common_gameFlags_check_40A5C0(16)) {
		v3 = sub_45A6F0(*(_DWORD*)(a1 + 2060));
		if (v3) {
			if (sub_4356C0((int)v3, 30))
				return 1;
		}
	}
	return 0;
}

//----- (0046E130) --------------------------------------------------------
int __cdecl sub_46E130(int a1) {
	int v1;             // eax
	unsigned __int8* i; // ecx

	v1 = 0;
	if (!byte_5D4594[1090116])
		return 0;
	for (i = &byte_5D4594[1087248]; *(_DWORD*)i != a1; i += 56) {
		if (++v1 >= (unsigned int)byte_5D4594[1090116])
			return 0;
	}
	return 1;
}

//----- (0046E170) --------------------------------------------------------
unsigned __int16* __cdecl sub_46E170(wchar_t* a1) {
	unsigned __int16* v1; // esi
	size_t v2;            // edi
	unsigned __int16* v3; // edi

	v1 = a1;
	v2 = nox_wcslen(a1);
	sub_43F840(0, v1, (int*)&a1, 0, 0);
	if ((int)(a1 + 5) > *(int*)&byte_5D4594[1084036]) {
		v3 = &v1[v2];
		do {
			*v3 = 0;
			--v3;
			sub_43F840(0, v1, (int*)&a1, 0, 0);
		} while ((int)(a1 + 5) > *(int*)&byte_5D4594[1084036]);
	}
	return v1;
}

//----- (0046E1E0) --------------------------------------------------------
int __cdecl sub_46E1E0(int a1) {
	int v1;             // eax
	unsigned __int8* i; // ecx

	v1 = 0;
	if (!byte_5D4594[1090117])
		return 0;
	for (i = &byte_5D4594[1084192]; *(_DWORD*)i != a1; i += 80) {
		if (++v1 >= (unsigned int)byte_5D4594[1090117])
			return 0;
	}
	return 1;
}

//----- (0046E4E0) --------------------------------------------------------
char* sub_46E4E0() {
	int v0;              // ebx
	unsigned int v1;     // esi
	unsigned int v2;     // edi
	signed int v3;       // ebp
	char* i;             // esi
	int v5;              // eax
	char* j;             // eax
	int v7;              // ecx
	int v8;              // ebx
	int v9;              // esi
	char* v10;           // edi
	signed int k;        // ebp
	unsigned __int8 v12; // dl
	int v13;             // eax
	int v14;             // ecx
	int v15;             // edi
	_DWORD* v16;         // eax
	_DWORD* v17;         // edi
	char* v18;           // eax
	int v19;             // edx
	unsigned __int8 v20; // al
	char* result;        // eax
	int v22;             // ecx
	unsigned int v23;    // [esp+10h] [ebp-8h]
	wchar_t* v24;        // [esp+14h] [ebp-4h]

	v0 = 0x7FFFFFFF;
	v1 = sub_417DD0();
	v24 = (wchar_t*)v1;
	v23 = sub_416F40();
	byte_5D4594[1090116] = 0;
	byte_5D4594[1090117] = 0;
	byte_5D4594[1090118] = 0;
	if (nox_common_gameFlags_check_40A5C0(1) && *(_DWORD*)&nox_common_engineFlags & 0x40000)
		--v23;
	if (byte_5D4594[1090116] < v1) {
		v2 = v1;
		do {
			v3 = 0x80000000;
			for (i = sub_418B10(); i; i = sub_418B60((int)i)) {
				if (*((int*)i + 13) <= v0 && !sub_46E130((unsigned __int8)i[57]) &&
				    *((int*)i + 13) > v3) {
					v3 = *((_DWORD*)i + 13);
					v2 = (unsigned int)i;
				}
			}
			v5 = 56 * byte_5D4594[1090116];
			*(_DWORD*)&byte_5D4594[v5 + 1087252] = *(_DWORD*)(v2 + 52);
			*(_DWORD*)&byte_5D4594[v5 + 1087248] = *(unsigned __int8*)(v2 + 57);
			byte_5D4594[v5 + 1087256] = *(_BYTE*)(v2 + 56);
			nox_wcscpy((wchar_t*)&byte_5D4594[v5 + 1087204], (const wchar_t*)v2);
			sub_46E170((wchar_t*)&byte_5D4594[56 * byte_5D4594[1090116] + 1087204]);
			++byte_5D4594[1090116];
			v0 = v3;
		} while (byte_5D4594[1090116] < (unsigned int)v24);
	}
	for (j = sub_416EA0(); j; j = sub_416EE0((int)j)) {
		v7 = *((_DWORD*)j + 920);
		if (v7 & 1 && !(v7 & 0x20))
			*((_DWORD*)j + 534) -= 0xFFFF;
	}
	v8 = 0x7FFFFFFF;
	if (byte_5D4594[1090117] < v23) {
		v9 = (int)v24;
		do {
			v10 = sub_416EA0();
			for (k = 0x80000000; v10; v10 = sub_416EE0((int)v10)) {
				if ((v10[2064] != 31 || !(*(_DWORD*)&nox_common_engineFlags & 0x40000)) &&
				    *((int*)v10 + 534) <= v8 && !sub_46E1E0(*((_DWORD*)v10 + 515)) &&
				    *((int*)v10 + 534) > k) {
					k = *((_DWORD*)v10 + 534);
					v9 = (int)v10;
				}
			}
			v12 = byte_5D4594[1090117];
			v13 = 80 * byte_5D4594[1090117];
			*(_DWORD*)&byte_5D4594[v13 + 1084192] = *(_DWORD*)(v9 + 2060);
			v14 = *(_DWORD*)(v9 + 3680);
			if (!(v14 & 1) || v14 & 0x20) {
				*(_DWORD*)&byte_5D4594[v13 + 1084196] = *(_DWORD*)(v9 + 2136);
				++byte_5D4594[1090118];
			} else {
				*(_DWORD*)&byte_5D4594[v13 + 1084196] = *(_DWORD*)(v9 + 2136) + 0xFFFF;
			}
			*(_DWORD*)&byte_5D4594[v13 + 1084200] = *(unsigned __int16*)(v9 + 2148);
			v15 = 80 * v12;
			*(_DWORD*)&byte_5D4594[v15 + 1084204] = sub_46E080(v9);
			*(_DWORD*)&byte_5D4594[v15 + 1084208] = *(_DWORD*)(v9 + 3680);
			nox_wcscpy((wchar_t*)&byte_5D4594[v15 + 1084132], (const wchar_t*)(v9 + 4704));
			sub_46E170((wchar_t*)&byte_5D4594[80 * byte_5D4594[1090117] + 1084132]);
			byte_5D4594[80 * byte_5D4594[1090117] + 1084188] = *(_BYTE*)(v9 + 2251);
			v16 = sub_418C80(*(_DWORD*)(v9 + 2060));
			v17 = v16;
			if (v16 && sub_419130((int)v16)) {
				v18 = sub_418AB0(*((unsigned __int8*)v17 + 4));
				if (v18) {
					v19 = (unsigned __int8)v18[57];
					v20 = byte_5D4594[1090117];
					*(_DWORD*)&byte_5D4594[80 * byte_5D4594[1090117] + 1084184] = v19;
				} else {
					v20 = byte_5D4594[1090117];
					*(_DWORD*)&byte_5D4594[80 * byte_5D4594[1090117] + 1084184] = -1;
				}
			} else {
				v20 = byte_5D4594[1090117];
				*(_DWORD*)&byte_5D4594[80 * byte_5D4594[1090117] + 1084184] = -1;
			}
			byte_5D4594[1090117] = v20 + 1;
			v8 = k;
		} while ((unsigned __int8)(v20 + 1) < v23);
	}
	for (result = sub_416EA0(); result; result = sub_416EE0((int)result)) {
		v22 = *((_DWORD*)result + 920);
		if (v22 & 1) {
			if (!(v22 & 0x20))
				*((_DWORD*)result + 534) += 0xFFFF;
		}
	}
	return result;
}

//----- (0046F060) --------------------------------------------------------
int sub_46F060() { return 0; }

//----- (0046F070) --------------------------------------------------------
int sub_46F070() { return 0; }

//----- (0046FAE0) --------------------------------------------------------
void sub_46FAE0() {
	int yTop; // [esp+0h] [ebp-8h]
	int v1;   // [esp+4h] [ebp-4h]

	nox_client_wndGetPosition_46AA60(*(_DWORD**)&byte_5D4594[4 * *(_DWORD*)&byte_5D4594[1088996] + 1090060], &v1, &yTop);
	yTop +=
	    *(_DWORD*)&byte_587000[145672] *
		*(__int16*)(*(_DWORD*)(*(_DWORD*)&byte_5D4594[4 * *(_DWORD*)&byte_5D4594[1088996] + 1090060] + 32) +
			    2) +
	    *(__int16*)(*(_DWORD*)(*(_DWORD*)&byte_5D4594[4 * *(_DWORD*)&byte_5D4594[1088996] + 1090060] + 32) + 2) / 2;
	nox_client_drawSetColor_434460(*(int*)&byte_5D4594[2589772]);
	sub_499B70(v1 + 1, yTop, 3);
}

//----- (0046FE60) --------------------------------------------------------
unsigned __int8 __cdecl sub_46FE60(int a1) {
	unsigned __int8 result; // al
	unsigned __int8 v2;     // [esp+8h] [ebp-4h]

	result = 0;
	v2 = 0;
	if (!byte_5D4594[1090116])
		return 0;
	while (*(_DWORD*)&byte_5D4594[56 * v2 + 1087248] != a1) {
		v2 = ++result;
		if (result >= byte_5D4594[1090116])
			return 0;
	}
	return result;
}

//----- (0046FEB0) --------------------------------------------------------
unsigned __int8 __cdecl sub_46FEB0(unsigned __int8 a1) {
	return byte_587000[8 * (byte_5D4594[56 * a1 + 1087256] % 10) + 145584];
}

//----- (0046FEE0) --------------------------------------------------------
char sub_46FEE0() {
	int v0;              // eax
	char v1;             // bl
	unsigned __int8* i;  // edx
	int v4;              // esi
	int v5;              // ecx
	unsigned __int8* v6; // eax
	int v7;              // ecx
	unsigned __int8* v8; // eax

	v0 = 0;
	v1 = 1;
	if (!byte_5D4594[1090117])
		return 0;
	for (i = &byte_5D4594[1084192]; *(_DWORD*)i != *(_DWORD*)&byte_5D4594[2616328]; i += 80) {
		if (++v0 >= (unsigned int)byte_5D4594[1090117])
			return 0;
	}
	v4 = *(_DWORD*)&byte_5D4594[80 * v0 + 1084196];
	if (!nox_common_gameFlags_check_40A5C0(1024)) {
		v7 = byte_5D4594[1090117];
		if (byte_5D4594[1090117]) {
			v8 = &byte_5D4594[1084196];
			do {
				if (*(_DWORD*)v8 > v4)
					++v1;
				v8 += 80;
				--v7;
			} while (v7);
		}
		return v1;
	}
	v5 = byte_5D4594[1090117];
	if (!byte_5D4594[1090117])
		return v1;
	v6 = &byte_5D4594[1084196];
	do {
		if (*(_DWORD*)v6 < v4)
			++v1;
		v6 += 80;
		--v5;
	} while (v5);
	return v1;
}

//----- (0046FF70) --------------------------------------------------------
char __cdecl sub_46FF70(int a1) {
	char v1;             // bl
	int v2;              // ecx
	unsigned __int8* v3; // eax
	int v5;              // ecx
	unsigned __int8* v6; // eax

	v1 = 1;
	if (!nox_common_gameFlags_check_40A5C0(1024)) {
		v5 = byte_5D4594[1090116];
		if (byte_5D4594[1090116]) {
			v6 = &byte_5D4594[1087252];
			do {
				if (*(_DWORD*)v6 > a1)
					++v1;
				v6 += 56;
				--v5;
			} while (v5);
		}
		return v1;
	}
	v2 = byte_5D4594[1090116];
	if (!byte_5D4594[1090116])
		return v1;
	v3 = &byte_5D4594[1087252];
	do {
		if (*(_DWORD*)v3 < a1)
			++v1;
		v3 += 56;
		--v2;
	} while (v2);
	return v1;
}

//----- (0046FFD0) --------------------------------------------------------
unsigned __int8 sub_46FFD0() {
	unsigned __int8 result; // al
	int v1;                 // ebx
	unsigned __int8* v2;    // ebp
	char* v3;               // eax
	unsigned __int8* v4;    // esi
	unsigned __int8 v5;     // al
	unsigned __int8 v6;     // di
	int v7;                 // edx
	int v8;                 // eax
	int v9;                 // eax
	int v10;                // eax
	wchar_t* v11;           // eax
	int v12;                // eax
	int v13;                // edx
	int v14;                // eax
	unsigned __int8 v15;    // cl
	float v16;              // [esp+0h] [ebp-4Ch]
	int v17;                // [esp+14h] [ebp-38h]
	int v18;                // [esp+18h] [ebp-34h]
	int v19;                // [esp+1Ch] [ebp-30h]
	int v20;                // [esp+20h] [ebp-2Ch]
	int v21;                // [esp+24h] [ebp-28h]
	int v22;                // [esp+28h] [ebp-24h]
	int v23;                // [esp+2Ch] [ebp-20h]
	int v24;                // [esp+30h] [ebp-1Ch]
	float v25;              // [esp+34h] [ebp-18h]
	int v26;                // [esp+38h] [ebp-14h]
	int v27;                // [esp+3Ch] [ebp-10h]
	int v28;                // [esp+40h] [ebp-Ch]
	int v29;                // [esp+44h] [ebp-8h]
	int v30;                // [esp+48h] [ebp-4h]

	sub_46DB80();
	sub_46F8F0(0, 0);
	result = byte_5D4594[1090117];
	v23 = 0;
	if (byte_5D4594[1090117]) {
		v1 = 1;
		v2 = &byte_5D4594[1084184];
		do {
			v3 = sub_417040(*((_DWORD*)v2 + 2));
			v4 = (unsigned __int8*)v3;
			if (v3 && *((_DWORD*)v3 + 1198)) {
				if (v2[24] & 1) {
					LOBYTE(v21) = 9;
				} else if (*(int*)v2 == -1) {
					LOBYTE(v21) = 4;
				} else {
					v5 = sub_46FE60(*(_DWORD*)v2);
					LOBYTE(v21) = sub_46FEB0(v5);
				}
				if (*((_DWORD*)v2 + 2) == *(_DWORD*)&byte_5D4594[2616328]) {
					*(_DWORD*)&byte_587000[145672] =
					    *(__int16*)(*(_DWORD*)(*(_DWORD*)&byte_5D4594[1090060] + 32) + 46);
					*(_DWORD*)&byte_5D4594[1088996] = 0;
				}
				v6 = v21;
				sub_46DC30(*(int*)&byte_5D4594[1090060], v21, (wchar_t*)&byte_587000[147828], v2 - 52);
				sub_46DC30(*(int*)&byte_5D4594[1090076], v6, (wchar_t*)&byte_587000[147836], v4[4816]);
				v7 = *((_DWORD*)v2 + 2);
				v8 = v4[2282];
				LOBYTE(v22) = 4;
				if (v7 == *(_DWORD*)&byte_5D4594[2616328]) {
					v9 = sub_470CD0();
					v24 = v9;
					v25 = (double)v9;
					v10 = sub_470CC0();
					v24 = v10;
					v16 = (double)v10 / v25 * 100.0;
					v8 = nox_float2int(v16);
				}
				if (v8 > 25) {
					if (v8 <= 50)
						LOBYTE(v22) = 15;
				} else {
					LOBYTE(v22) = 6;
				}
				sub_46DC30(*(int*)&byte_5D4594[1090084], v22, (wchar_t*)&byte_587000[147844], v8);
				sub_46DC30(*(int*)&byte_5D4594[1090092], v6, (wchar_t*)&byte_587000[147856],
					   *(_DWORD*)&byte_5D4594[4 * v2[4] + 1084056]);
				v11 = sub_46FB50(*((_DWORD*)v2 + 5), &v26);
				sub_46DC60(*(int*)&byte_5D4594[1090068], v26, (int)v11);
				if (v4[4824]) {
					nox_client_wndGetPosition_46AA60(*(_DWORD**)&byte_5D4594[1090068], &v19, &v18);
					nox_window_get_size(*(int*)&byte_5D4594[1090068], &v28, &v27);
					v12 = *(_DWORD*)(*(_DWORD*)&byte_5D4594[1090068] + 32);
					v19 += 5;
					v18 = v18 + *(__int16*)(v12 + 2) / 2 + *(__int16*)(v12 + 2) * v1 - 1;
					nox_client_drawSetColor_434460(*(int*)&byte_5D4594[2523948]);
					sub_4C3270(v19, v18, 2, *(int*)&byte_5D4594[2523948]);
					nox_client_drawAddPoint_49F500(v19 + 2, v18);
					nox_client_drawAddPoint_49F500(v19 + 9, v18);
					nox_client_drawLineFromPoints_49E4B0();
					nox_client_drawAddPoint_49F500(v19 + 9, v18);
					nox_client_drawAddPoint_49F500(v19 + 9, v18 + 3);
					nox_client_drawLineFromPoints_49E4B0();
					nox_client_drawAddPoint_49F500(v19 + 7, v18);
					nox_client_drawAddPoint_49F500(v19 + 7, v18 + 2);
					nox_client_drawLineFromPoints_49E4B0();
				}
				if (v4[4825]) {
					nox_client_wndGetPosition_46AA60(*(_DWORD**)&byte_5D4594[1090068], &v17, &v20);
					nox_window_get_size(*(int*)&byte_5D4594[1090068], &v30, &v29);
					v13 = v17 + 5;
					v14 = *(_DWORD*)(*(_DWORD*)&byte_5D4594[1090068] + 32);
					v15 = v4[4824];
					v17 += 5;
					if (v15 == 1)
						v17 = v13 + 15;
					v20 = v20 + *(__int16*)(v14 + 2) / 2 + *(__int16*)(v14 + 2) * v1 - 1;
					nox_client_drawSetColor_434460(*(int*)&byte_5D4594[2589772]);
					sub_4C3270(v17, v20, 2, *(int*)&byte_5D4594[2589772]);
					nox_client_drawAddPoint_49F500(v17 + 2, v20);
					nox_client_drawAddPoint_49F500(v17 + 9, v20);
					nox_client_drawLineFromPoints_49E4B0();
					nox_client_drawAddPoint_49F500(v17 + 9, v20);
					nox_client_drawAddPoint_49F500(v17 + 9, v20 + 3);
					nox_client_drawLineFromPoints_49E4B0();
					nox_client_drawAddPoint_49F500(v17 + 7, v20);
					nox_client_drawAddPoint_49F500(v17 + 7, v20 + 2);
					nox_client_drawLineFromPoints_49E4B0();
				}
				++v1;
			}
			result = v23 + 1;
			v2 += 80;
			++v23;
		} while (v23 < byte_5D4594[1090117]);
		*(_DWORD*)&byte_587000[145664] = 1;
	} else {
		*(_DWORD*)&byte_587000[145664] = 1;
	}
	return result;
}

//----- (004703F0) --------------------------------------------------------
int sub_4703F0() {
	int result; // eax
	int v1;     // edx

	dword_5d4594_1090120 = (dword_5d4594_1090120 + 1) % 6;
	result = sub_43AF70();
	v1 = dword_5d4594_1090120;
	if (result || dword_5d4594_1090120 != 5) {
		if (dword_5d4594_1090120 == 1) {
			result = nox_common_gameFlags_check_40A5C0(4096);
			v1 = dword_5d4594_1090120;
			if (!result) {
				result = (dword_5d4594_1090120 + 1) / 6;
				v1 = (dword_5d4594_1090120 + 1) % 6;
				dword_5d4594_1090120 = (dword_5d4594_1090120 + 1) % 6;
			}
		}
	} else {
		v1 = 0;
		dword_5d4594_1090120 = 0;
	}
	switch (v1) {
	case 0:
		sub_46B500(0);
		nox_window_set_hidden(*(int*)&dword_5d4594_1090048, 1);
		nox_window_set_hidden(*(int*)&byte_5D4594[1090100], 1);
		*(_DWORD*)(*(_DWORD*)&byte_5D4594[1090052] + 4) &= 0xFFFFFFF7;
		result = *(_DWORD*)&byte_5D4594[1090056];
		*(_DWORD*)(*(_DWORD*)&byte_5D4594[1090056] + 4) &= 0xFFFFFFF7;
		break;
	case 1:
	case 2:
		sub_46A8C0(*(int*)&dword_5d4594_1090048);
		sub_46A8C0(*(int*)&byte_5D4594[1090100]);
		nox_window_set_hidden(*(int*)&byte_5D4594[1090100], 0);
		*(_DWORD*)(*(_DWORD*)&byte_5D4594[1090052] + 4) |= 8u;
		result = *(_DWORD*)&byte_5D4594[1090056];
		*(_DWORD*)(*(_DWORD*)&byte_5D4594[1090056] + 4) |= 8u;
		goto LABEL_10;
	case 3:
	case 4:
	case 5:
	LABEL_10:
		*(_DWORD*)&byte_587000[145664] = 1;
		break;
	default:
		return result;
	}
	return result;
}

//----- (00470510) --------------------------------------------------------
int sub_470510() {
	int result; // eax

	result = dword_5d4594_1090048;
	if (dword_5d4594_1090048) {
		result = dword_5d4594_1090120;
		if (dword_5d4594_1090120 == 2) {
			*(_DWORD*)&byte_587000[145664] = 1;
		} else {
			*(_DWORD*)&byte_587000[145668] = dword_5d4594_1090120;
			dword_5d4594_1090120 = 0;
			result = sub_4703F0();
		}
	}
	return result;
}

//----- (00470550) --------------------------------------------------------
int sub_470550() {
	int result; // eax

	result = dword_5d4594_1090048;
	if (dword_5d4594_1090048) {
		result = dword_5d4594_1090120;
		if (dword_5d4594_1090120) {
			dword_5d4594_1090120 = 4;
			result = sub_4703F0();
		}
	}
	return result;
}

//----- (00470580) --------------------------------------------------------
BOOL sub_470580() {
	return dword_5d4594_1090120 && wndIsShown_sub_46ACC0(*(int*)&dword_5d4594_1090048) != 1;
}

//----- (004705B0) --------------------------------------------------------
int sub_4705B0() {
	int result; // eax

	result = dword_5d4594_1090048;
	if (dword_5d4594_1090048) {
		if (wndIsShown_sub_46ACC0(*(int*)&dword_5d4594_1090048))
			nox_window_set_hidden(*(int*)&dword_5d4594_1090048, 0);
		dword_5d4594_1090120 = 0;
		result = sub_4703F0();
	}
	return result;
}

//----- (004705F0) --------------------------------------------------------
char __cdecl sub_4705F0(char a1, char a2, __int16 a3) {
	char result; // al

	result = a2;
	if (a2 == 1) {
		result = a1;
		if (a1 != 2 && a1) {
			if (a1 == 1) {
				result = a3;
				*(_WORD*)&byte_5D4594[1090128] = a3;
			}
		} else {
			*(_WORD*)&byte_5D4594[1090128] = 0;
		}
	} else if (a2 == 2) {
		result = a1;
		if (a1 != 2 && a1) {
			if (a1 == 1)
				*(_WORD*)&byte_5D4594[1090130] = a3;
		} else {
			*(_WORD*)&byte_5D4594[1090130] = 0;
		}
	}
	return result;
}

//----- (00470650) --------------------------------------------------------
char __cdecl sub_470650(char a1, __int16 a2) {
	char result; // al

	result = a1;
	if (a1 && a1 != 1) {
		if (a1 == 4 || a1 == 2) {
			result = a2;
			*(_WORD*)&byte_5D4594[1090132] = a2;
		}
	} else {
		*(_WORD*)&byte_5D4594[1090132] = 0;
	}
	return result;
}

//----- (00470680) --------------------------------------------------------
int sub_470680() {
	int result; // eax

	result = 0;
	*(_WORD*)&byte_5D4594[1090128] = 0;
	*(_WORD*)&byte_5D4594[1090130] = 0;
	*(_WORD*)&byte_5D4594[1090132] = 0;
	return result;
}

//----- (004706A0) --------------------------------------------------------
BOOL sub_4706A0() { return dword_5d4594_1090048 && dword_5d4594_1090120; }

//----- (004706C0) --------------------------------------------------------
int __cdecl sub_4706C0(int a1) {
	int result; // eax

	if (a1 && *(_DWORD*)&byte_5D4594[1090180] && sub_46ADA0(*(int*)&byte_5D4594[1090176]) & 0x10)
		result = sub_46A8C0(*(int*)&byte_5D4594[1090176]);
	else
		result = nox_window_set_hidden(*(int*)&byte_5D4594[1090176], 1);
	return result;
}

//----- (00470710) --------------------------------------------------------
int sub_470710() {
	int result; // eax

	result = nox_new_window_from_file("GuiFps.wnd", 0);
	*(_DWORD*)&byte_5D4594[1090176] = result;
	if (result) {
		sub_46B340(result, sub_470770);
		sub_46A9B0(*(_DWORD**)&byte_5D4594[1090176], 121,
			   nox_win_height - *(_DWORD*)(*(_DWORD*)&byte_5D4594[1090176] + 12) - 5);
		*(_DWORD*)&byte_5D4594[1090140] = sub_43F360((char*)&byte_587000[147880]);
		sub_4706C0(0);
		result = 1;
	}
	return result;
}

//----- (00470770) --------------------------------------------------------
int __cdecl sub_470770(int a1, int a2) {
	int v1;             // ebx
	DWORD v2;           // eax
	DWORD v3;           // ecx
	unsigned int v4;    // eax
	unsigned __int8 v5; // cl
	int v6;             // esi
	int v7;             // ebp
	int i;              // edi
	int v9;             // eax
	int v10;            // eax
	int xLeft;          // [esp+Ch] [ebp-8h]
	int yTop;           // [esp+10h] [ebp-4h]

	v1 = a1;
	nox_client_wndGetPosition_46AA60((_DWORD*)a1, &xLeft, &yTop);
	if (*(int*)&byte_5D4594[1090256] >= *(int*)&byte_587000[147864]) {
		*(_DWORD*)&byte_587000[147864] = *(_DWORD*)&byte_5D4594[1090256] + 10;
		v2 = nox_get_ticks();
		v3 = v2;
		v4 = 0x2710 / (v2 - *(_DWORD*)&byte_5D4594[1090268]);
		*(_DWORD*)&byte_5D4594[1090264] = v3;
		*(_DWORD*)&byte_5D4594[1090268] = v3;
		*(_DWORD*)&byte_5D4594[1090260] = v4;
	}
	v5 = byte_5D4594[1090248];
	if (*(_WORD*)&byte_5D4594[1090246]) {
		*(_WORD*)&byte_5D4594[1090246] = 0;
		++*(_WORD*)&byte_5D4594[2 * byte_5D4594[1090248] + 1090184];
	}
	*(_DWORD*)&byte_5D4594[1090252] = (*(_DWORD*)&byte_5D4594[1090252] + 1) % 3u;
	if (!*(_DWORD*)&byte_5D4594[1090252])
		byte_5D4594[1090248] = (v5 + 1) % 31;
	nox_client_drawRectFilledAlpha_49CF10(xLeft, yTop, *(_DWORD*)(v1 + 8), *(_DWORD*)(v1 + 12));
	sub_434390(*(int*)&byte_5D4594[2523948]);
	nox_swprintf((wchar_t*)&byte_5D4594[1090144], L"%d", *(_DWORD*)&byte_5D4594[1090260]);
	sub_43F840(*(int*)&byte_5D4594[1090140], (unsigned __int16*)&byte_5D4594[1090144], &a1, 0, 0);
	sub_43F6E0(*(int*)&byte_5D4594[1090140], (__int16*)&byte_5D4594[1090144], xLeft + (*(int*)(v1 + 8) - a1) / 2,
		   yTop + 3);
	v6 = xLeft + 1;
	v7 = yTop + 14;
	nox_client_drawSetColor_434460(*(int*)&byte_5D4594[2650656]);
	nox_client_drawRectFilledOpaque_49CE30(v6, v7, 30, 3);
	for (i = 1; i < 31; ++i) {
		v9 = *(unsigned __int16*)&byte_5D4594[2 * ((i + byte_5D4594[1090248]) % 31) + 1090184];
		if ((_WORD)v9) {
			v10 = v9 - 1;
			if (v10) {
				if (v10 == 1) {
					a1 = 2;
					nox_client_drawSetColor_434460(*(int*)&byte_5D4594[2589772]);
				} else {
					a1 = 3;
					nox_client_drawSetColor_434460(*(int*)&byte_5D4594[2618904]);
				}
			} else {
				a1 = 1;
				nox_client_drawSetColor_434460(*(int*)&byte_5D4594[2650644]);
			}
			if (a1)
				nox_client_drawBorderLines_49CC70(v6, v7 - a1 + 3, 1, a1);
		} else {
			a1 = 0;
		}
		++v6;
	}
	if (*(_DWORD*)&byte_5D4594[2614264] / 0xFAu) {
		if (*(_DWORD*)&byte_5D4594[2614264] / 0xFAu == 1)
			sub_434390(*(int*)&byte_5D4594[2589772]);
		else
			sub_434390(*(int*)&byte_5D4594[2650644]);
	} else {
		sub_434390(*(int*)&byte_5D4594[2618904]);
	}
	nox_swprintf((wchar_t*)&byte_5D4594[1090144], L"%d", *(_DWORD*)&byte_5D4594[2614264]);
	sub_43F840(*(int*)&byte_5D4594[1090140], (unsigned __int16*)&byte_5D4594[1090144], &a1, 0, 0);
	sub_43F6E0(*(int*)&byte_5D4594[1090140], (__int16*)&byte_5D4594[1090144], xLeft + (*(int*)(v1 + 8) - a1) / 2,
		   yTop + 22);
	nox_client_drawSetColor_434460(*(int*)&byte_5D4594[2614248]);
	nox_client_drawBorderLines_49CC70(xLeft, yTop, *(_DWORD*)(v1 + 8), *(_DWORD*)(v1 + 12));
	++*(_DWORD*)&byte_5D4594[1090256];
	return 1;
}

//----- (00470A50) --------------------------------------------------------
int __cdecl sub_470A50(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[1090180] = a1;
	return result;
}

//----- (00470A60) --------------------------------------------------------
int sub_470A60() {
	*(_DWORD*)&byte_5D4594[1090180] = *(_DWORD*)&byte_5D4594[1090180] == 0;
	return sub_4706C0(1);
}

//----- (00470A80) --------------------------------------------------------
void sub_470A80() { ++*(_WORD*)&byte_5D4594[1090246]; }

//----- (00470A90) --------------------------------------------------------
int sub_470A90() { return *(_DWORD*)&byte_5D4594[1096252]; }

//----- (00470AA0) --------------------------------------------------------
int __cdecl sub_470AA0(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[1096252] = a1;
	if (*(_DWORD*)&byte_5D4594[1093176]) {
		if (a1) {
			nox_window_set_hidden(*(int*)&byte_5D4594[1093076], 0);
			result = nox_window_set_hidden(*(int*)&byte_5D4594[1093096], 0);
		} else {
			nox_window_set_hidden(*(int*)&byte_5D4594[1093076], 1);
			result = nox_window_set_hidden(*(int*)&byte_5D4594[1093096], 1);
		}
	}
	return result;
}

//----- (00470B00) --------------------------------------------------------
unsigned __int8* sub_470B00() {
	unsigned __int8* result; // eax

	*(_DWORD*)&byte_5D4594[1090284] = sub_4344A0(255, 0, 0);
	*(_DWORD*)&byte_5D4594[1090280] = sub_4344A0(100, 0, 0);
	*(_DWORD*)&byte_5D4594[1091964] = sub_4344A0(0, 255, 0);
	*(_DWORD*)&byte_5D4594[1092992] = sub_4344A0(0, 100, 0);
	*(_DWORD*)&byte_5D4594[1093048] = *(_DWORD*)&byte_5D4594[1090284];
	*(_DWORD*)&byte_5D4594[1093052] = *(_DWORD*)&byte_5D4594[1090280];
	*(_DWORD*)&byte_5D4594[1093068] = sub_4344A0(0, 0, 255);
	*(_DWORD*)&byte_5D4594[1093072] = sub_4344A0(0, 0, 100);
	*(_DWORD*)&byte_5D4594[1093128] = sub_4344A0(240, 0, 240);
	*(_DWORD*)&byte_5D4594[1093132] = sub_4344A0(50, 0, 50);
	*(_DWORD*)&byte_5D4594[1093148] = sub_4344A0(255, 0, 255);
	*(_DWORD*)&byte_5D4594[1093152] = sub_4344A0(50, 0, 50);
	*(_DWORD*)&byte_5D4594[1093168] = sub_4344A0(255, 0, 255);
	*(_DWORD*)&byte_5D4594[1093172] = sub_4344A0(50, 0, 50);
	result = &byte_5D4594[1094732];
	do {
		*((_DWORD*)result - 384) = 0;
		*(_DWORD*)result = 0;
		result += 24;
	} while ((int)result < (int)&byte_5D4594[1096268]);
	return result;
}

//----- (00470C20) --------------------------------------------------------
int __cdecl sub_470C20(_DWORD* a1, _DWORD* a2) {
	int result; // eax

	*a1 = *(_DWORD*)&byte_5D4594[1090280];
	result = *(_DWORD*)&byte_5D4594[1090284];
	*a2 = *(_DWORD*)&byte_5D4594[1090284];
	return result;
}

//----- (00470C40) --------------------------------------------------------
int __cdecl sub_470C40(int a1) {
	int result; // eax

	*(_DWORD*)&byte_5D4594[1096264] = a1;
	if (a1) {
		result = *(_DWORD*)&byte_5D4594[1091964];
		*(_DWORD*)&byte_5D4594[1093048] = *(_DWORD*)&byte_5D4594[1091964];
		*(_DWORD*)&byte_5D4594[1093052] = *(_DWORD*)&byte_5D4594[1092992];
	} else {
		result = *(_DWORD*)&byte_5D4594[1090280];
		*(_DWORD*)&byte_5D4594[1093048] = *(_DWORD*)&byte_5D4594[1090284];
		*(_DWORD*)&byte_5D4594[1093052] = *(_DWORD*)&byte_5D4594[1090280];
	}
	return result;
}

//----- (00470C80) --------------------------------------------------------
int __cdecl sub_470C80(int a1, int a2) {
	int result; // eax

	if (*(_DWORD*)&byte_5D4594[2618908])
		*(_DWORD*)(*(_DWORD*)&byte_5D4594[2618908] + 2247) = a2;
	result = a1;
	*(_DWORD*)&byte_5D4594[1093044] = a2;
	*(_DWORD*)&byte_5D4594[1093040] = a1;
	*(_DWORD*)&byte_5D4594[1096260] = 32;
	return result;
}

//----- (00470CB0) --------------------------------------------------------
int __cdecl sub_470CB0(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[1093040] = a1;
	return result;
}

//----- (00470CC0) --------------------------------------------------------
int sub_470CC0() { return *(_DWORD*)&byte_5D4594[1093040]; }

//----- (00470CD0) --------------------------------------------------------
int sub_470CD0() { return *(_DWORD*)&byte_5D4594[1093044]; }

//----- (00470CE0) --------------------------------------------------------
int __cdecl sub_470CE0(int a1, int a2) {
	int result; // eax

	if (*(_DWORD*)&byte_5D4594[2618908])
		*(_DWORD*)(*(_DWORD*)&byte_5D4594[2618908] + 2243) = a2;
	result = a1;
	*(_DWORD*)&byte_5D4594[1093064] = a2;
	*(_DWORD*)&byte_5D4594[1093060] = a1;
	*(_DWORD*)&byte_5D4594[1096260] = 32;
	return result;
}

//----- (00470D10) --------------------------------------------------------
int __cdecl sub_470D10(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[1093060] = a1;
	return result;
}

//----- (00470D20) --------------------------------------------------------
int __cdecl sub_470D20(int a1, int a2) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[1093120] = a1;
	*(_DWORD*)&byte_5D4594[1093124] = a2;
	if (a1 != a2)
		result = sub_4160D0(17);
	return result;
}

//----- (00470D40) --------------------------------------------------------
BOOL sub_470D40() {
	return !wndIsShown_sub_46ACC0(*(int*)&byte_5D4594[1093136]) ||
	       !wndIsShown_sub_46ACC0(*(int*)&byte_5D4594[1093156]);
}

//----- (00470D70) --------------------------------------------------------
int sub_470D70() {
	nox_window_set_hidden(*(int*)&byte_5D4594[1093136], 1);
	return nox_window_set_hidden(*(int*)&byte_5D4594[1093156], 1);
}

//----- (00470D90) --------------------------------------------------------
int __cdecl sub_470D90(int a1, int a2) {
	int result; // eax

	nox_window_set_hidden(*(int*)&byte_5D4594[1093136], 0);
	nox_window_set_hidden(*(int*)&byte_5D4594[1093156], 0);
	result = a1;
	*(_DWORD*)&byte_5D4594[1093140] = a1;
	*(_DWORD*)&byte_5D4594[1093144] = a2;
	*(_DWORD*)&byte_5D4594[1093160] = a1;
	*(_DWORD*)&byte_5D4594[1093164] = a2;
	return result;
}

//----- (00470DD0) --------------------------------------------------------
int sub_470DD0() { return *(_DWORD*)&byte_5D4594[1093060]; }

//----- (00470DE0) --------------------------------------------------------
int sub_470DE0() {
	int result; // eax
	int v1;     // ebp
	int v2;     // edx
	int v3;     // esi

	result = *(_DWORD*)&byte_5D4594[2616328];
	if (*(_DWORD*)&byte_5D4594[2616328]) {
		v1 = *(_DWORD*)&byte_5D4594[1093040];
		if (*(int*)&byte_5D4594[1093040] >= 1) {
			result = -858993458 * *(_DWORD*)&byte_5D4594[1093044];
			v2 = 2 * *(_DWORD*)&byte_5D4594[1093044] / 5;
			v3 = v2;
			if (*(_DWORD*)&byte_5D4594[1093040] < v2) {
				*(_DWORD*)&byte_5D4594[1091960] =
				    *(_DWORD*)&byte_5D4594[2649704] / 3u +
				    *(_DWORD*)&byte_5D4594[1093040] *
					((unsigned int)(3 * *(_DWORD*)&byte_5D4594[2649704]) >> 2) / v2;
				result = sub_4160F0(4u, *(_DWORD*)&byte_5D4594[1091960] - 1);
				if (result) {
					sub_452D80(896, 66 * (v3 - v1) / v3 + 33);
					result = sub_4160D0(4);
				}
			}
		}
	}
	return result;
}

//----- (00470E90) --------------------------------------------------------
int __cdecl sub_470E90(int a1, int a2) {
	int result; // eax

	switch (a2) {
	case 5:
		sub_4672C0();
		goto LABEL_4;
	case 8:
	case 12:
	case 16:
		result = 0;
		break;
	default:
	LABEL_4:
		result = 1;
		break;
	}
	return result;
}

//----- (00470EE0) --------------------------------------------------------
void __cdecl nox_win_init_cur_weapon(nox_window* a1, int a2, int a3, int w, int h) {
	nox_win_cur_weapon = nox_window_new(a1, 0x408, a2, a3, w, h, 0);
	nox_window_set_all_funcs(nox_win_cur_weapon, sub_470E90, sub_470F40_draw, sub_4710B0);
	nox_win_cur_weapon->field_8 = 4;
}

//----- (00470F40) --------------------------------------------------------
int __cdecl sub_470F40_draw(nox_window* win) {
	int v2;              // eax
	unsigned __int8* v3; // edi
	int v4;              // ebx
	int v5;              // esi
	int v6;              // ecx
	int v7;              // eax
	double v8;           // st7
	double v9;           // st6
	int v12;             // [esp+10h] [ebp-1Ch]
	int v14;             // [esp+18h] [ebp-14h]
	int v16;             // [esp+20h] [ebp-Ch]
	int v17;             // [esp+24h] [ebp-8h]
	int v18;             // [esp+30h] [ebp+4h]

	v2 = 5 * win->field_8;
	v18 = 1;
	v3 = &byte_5D4594[4 * v2 + 1093036];
	nox_client_wndGetPosition_46AA60(win, &v14, &v16);

	int w;
	int h;
	nox_window_get_size(win, &w, &h);
	v4 = w / 2;
	v17 = w / 2 + v14;
	v5 = h / 2 + v16;

	v6 = *((int*)v3 + 2);
	if (v6)
		v12 = (*((int*)v3 + 1) << 8) / v6;
	else
		v18 = 0;
	*((_DWORD*)v3 + 4) = *((_DWORD*)v3 + 3);
	if (!v18) {
		sub_465D50_draw(win);
		return 1;
	}
	if (v12 >= 256) {
		v7 = sub_4678D0();
		if (v7) {
			v8 = (double)*(unsigned __int16*)(v7 + 292);
			v9 = (double)*(unsigned __int16*)(v7 + 294);
			if (v8 < v9 * *(double*)&byte_581450[9608]) {
				*((_DWORD*)v3 + 4) = *(_DWORD*)&byte_5D4594[2650644];
				v12 = 1;
			} else if (v8 < v9 * *(double*)&byte_581450[9544]) {
				*((_DWORD*)v3 + 4) = *(_DWORD*)&byte_5D4594[2589772];
				v12 = 1;
			} else {
				v18 = 0;
				v12 = 1;
			}
		} else {
			v18 = 0;
			v12 = 1;
		}
	}
	if (v18) {
		nox_client_drawEnableAlpha_434560(1);
		nox_client_drawSetAlpha_434580(0x40u);
		sub_4AE6F0(v17, v5, v4, v12, *((_DWORD*)v3 + 4));
		nox_client_drawEnableAlpha_434560(0);
	}
	sub_465D50_draw(win);
	return 1;
}
// 470FE2: variable 'v12' is possibly undefined

//----- (00471250) --------------------------------------------------------
int __cdecl sub_471250(_DWORD* a1) {
	unsigned __int8* v1;  // esi
	int v2;               // edi
	unsigned __int8* v3;  // esi
	int result;           // eax
	int v5;               // eax
	int v6;               // ecx
	int v7;               // ebx
	int v8;               // ebp
	int v9;               // ecx
	int v10;              // esi
	int v11;              // edi
	double v12;           // st7
	int v13;              // eax
	unsigned __int8* v14; // esi
	int v15;              // [esp+10h] [ebp-1Ch]
	int v16;              // [esp+14h] [ebp-18h]
	int v17;              // [esp+18h] [ebp-14h]
	int v18;              // [esp+1Ch] [ebp-10h]
	int v19;              // [esp+20h] [ebp-Ch]
	unsigned __int8* v20; // [esp+24h] [ebp-8h]
	float v21;            // [esp+28h] [ebp-4h]
	float v22;            // [esp+30h] [ebp+4h]

	v20 = &byte_5D4594[20 * a1[8] + 1093036];
	v1 = v20;
	nox_client_wndGetPosition_46AA60(a1, &v18, &v17);
	v2 = 1;
	if (*((int*)v1 + 2) >= 1) {
		v15 = 1;
		v5 = sub_430B40_get_mouse_prev_seq();
		v6 = *((_DWORD*)v1 + 2);
		v19 = v5;
		if (v6 > 30) {
			v15 = 0;
			v2 = 0;
		}
		v7 = (v2 + 61) / v6 - v2;
		v8 = 61 - v7;
		v22 = 0.001;
		v16 = 0;
		v21 = (double)(v2 - v6 * ((v2 + 61) / v6) + 61) / (double)v6;
		if (v6 > 0) {
			while (1) {
				if (v16 >= *((_DWORD*)v1 + 1))
					v9 = *((_DWORD*)v1 + 4);
				else
					v9 = *((_DWORD*)v1 + 3);
				v10 = v8;
				v8 -= v7 + v2;
				v11 = v7;
				if (v7 <= 0)
					v11 = 1;
				v12 = v22 + v21;
				v22 = v12;
				if (v12 >= *(double*)&byte_581450[9512]) {
					--v8;
					--v10;
					++v11;
					v22 = v22 - *(double*)&byte_581450[9512];
				}
				nox_client_drawSetColor_434460(v9);
				nox_client_drawEnableAlpha_434560(1);
				if (v10 < 0) {
					v13 = -v10;
					v10 = 0;
					v11 -= v13;
				}
				if (v11 > 0) {
					v14 = &byte_587000[8 * v10 + 147905];
					do {
						if ((int)v14 >= (int)&byte_587000[148393])
							break;
						if (*(_DWORD*)(v14 + 3) != v19) {
							nox_client_drawRectFilledOpaque_49CE30(v18 + *(v14 - 1), v17 + *v14, v14[1], 1);
							*(_DWORD*)(v14 + 3) = v19;
						}
						v14 += 8;
						--v11;
					} while (v11 > 0);
				}
				nox_client_drawEnableAlpha_434560(0);
				if (++v16 >= *((_DWORD*)v20 + 2))
					break;
				v2 = v15;
				v1 = v20;
			}
		}
		result = 1;
	} else {
		nox_client_drawSetColor_434460(*((_DWORD*)v1 + 3));
		nox_client_drawEnableAlpha_434560(1);
		v3 = &byte_587000[147905];
		do {
			nox_client_drawRectFilledOpaque_49CE30(v18 + *(v3 - 1), v17 + *v3, v3[1], 1);
			v3 += 8;
		} while ((int)v3 < (int)&byte_587000[148393]);
		nox_client_drawEnableAlpha_434560(0);
		result = 1;
	}
	return result;
}

//----- (00471450) --------------------------------------------------------
int __cdecl sub_471450(_DWORD* a1) {
	_DWORD* v1;           // esi
	int v3;               // [esp+4h] [ebp-10h]
	int v4;               // [esp+8h] [ebp-Ch]
	WCHAR WideCharStr[4]; // [esp+Ch] [ebp-8h]

	v1 = a1;
	_itow(*(_DWORD*)&byte_5D4594[20 * a1[8] + 1093040], WideCharStr, 10);
	sub_434390(*(int*)&byte_5D4594[2523948]);
	sub_43F840(*(int*)&byte_5D4594[1096288], WideCharStr, &v3, 0, 0);
	nox_client_wndGetPosition_46AA60(v1, &v4, &a1);
	sub_43F6E0(*(int*)&byte_5D4594[1096288], (__int16*)WideCharStr, v4 - v3 / 2 + 8, (int)a1 + 1);
	return 1;
}

//----- (00471A80) --------------------------------------------------------
int __cdecl sub_471A80(_DWORD* a1) {
	int v1;        // esi
	int v2;        // esi
	int v3;        // eax
	int v4;        // eax
	__int16* v5;   // esi
	int v6;        // eax
	int v8;        // [esp+4h] [ebp-14h]
	wchar_t v9[8]; // [esp+8h] [ebp-10h]

	v1 = a1[8];
	nox_client_wndGetPosition_46AA60(a1, &v8, &a1);
	v2 = 536 * v1;
	if (*(_WORD*)&byte_5D4594[v2 + 1090312]) {
		v3 = *(_DWORD*)&byte_5D4594[v2 + 1090296];
		if (v3) {
			*(_DWORD*)(v3 + 12) = v8 + 14;
			*(_DWORD*)(*(_DWORD*)&byte_5D4594[v2 + 1090296] + 16) = (char*)a1 + 15;
			(*(void(__cdecl**)(unsigned __int8*, _DWORD))(*(_DWORD*)&byte_5D4594[v2 + 1090296] + 300))(
			    &byte_5D4594[1091908], *(_DWORD*)&byte_5D4594[v2 + 1090296]);
		}
		sub_434390(*(int*)&byte_5D4594[2523948]);
		nox_swprintf(v9, L"%d", *(unsigned __int16*)&byte_5D4594[v2 + 1090312]);
		v4 = sub_43F320(*(int*)&byte_5D4594[1096288]);
		sub_43F6E0(*(int*)&byte_5D4594[1096288], (__int16*)v9, v8 - 2, (int)((char*)a1 - v4 + 10));
	}
	v5 = (__int16*)&byte_5D4594[v2 + 1090300];
	if (v5) {
		v6 = sub_43F320(*(int*)&byte_5D4594[1096288]);
		sub_43F6E0(*(int*)&byte_5D4594[1096288], v5, v8 - 2, (int)((char*)a1 - v6 + 33));
	}
	return 1;
}

//----- (00471B90) --------------------------------------------------------
int __cdecl sub_471B90(int a1, int a2) {
	int result; // eax

	switch (a2) {
	case 5:
		if (*(_DWORD*)&byte_5D4594[536 * *(_DWORD*)(a1 + 32) + 1090308])
			sub_4674E0(*(_DWORD*)&byte_5D4594[536 * *(_DWORD*)(a1 + 32) + 1090308]);
		goto LABEL_5;
	case 8:
	case 12:
	case 16:
		result = 0;
		break;
	default:
	LABEL_5:
		result = 1;
		break;
	}
	return result;
}

//----- (00471C00) --------------------------------------------------------
int __cdecl sub_471C00(int a1) {
	int v1;              // esi
	unsigned __int8* v2; // ebp
	int v3;              // edi
	int v4;              // esi
	int v5;              // ebx
	int v7;              // [esp+Ch] [ebp+4h]

	v1 = *(_DWORD*)(a1 + 32);
	v7 = v1;
	v2 = &byte_5D4594[20 * v1 + 1093036];
	if (sub_4372E0() || dword_5d4594_2650672 || nox_common_gameFlags_check_40A5C0(9437184))
		return 1;
	if (v1)
		v3 = nox_win_width / 2 + 21;
	else
		v3 = nox_win_width / 2 + 15;
	v4 = nox_win_height / 2 - 48;
	v5 = 48 * *((int*)v2 + 1) / *((int*)v2 + 2);
	nox_client_drawSetColor_434460(*(int*)&byte_5D4594[2650656]);
	nox_client_drawRectFilledOpaque_49CE30(v3, v4, 2, 48);
	nox_client_drawSetColor_434460(*((_DWORD*)v2 + 3));
	nox_client_drawRectFilledOpaque_49CE30(v3, v4 - v5 + 48, 2, v5);
	if (v7) {
		nox_client_drawSetColor_434460(*(int*)&byte_5D4594[2650648]);
	} else if (*(_DWORD*)&byte_5D4594[1096264]) {
		nox_client_drawSetColor_434460(*(int*)&byte_5D4594[2650688]);
	} else {
		nox_client_drawSetColor_434460(*(int*)&byte_5D4594[2598268]);
	}
	nox_client_drawBorderLines_49CC70(v3 - 1, v4 - 1, 4, 50);
	return 1;
}

//----- (00472080) --------------------------------------------------------
int sub_472080() {
	int result; // eax

	result = *(int*)&byte_5D4594[1093120];
	if (*(int*)&byte_5D4594[1093120] != *(int*)&byte_5D4594[1093124]) {
		result = sub_416120(0x11u);
		if (result) {
			result = 0x64u / *(int*)&byte_5D4594[2649704];
			*(int*)&byte_5D4594[1093120] += 0x64u / *(int*)&byte_5D4594[2649704];
		}
	}
	return result;
}

//----- (004720C0) --------------------------------------------------------
int __cdecl sub_4720C0(int xLeft, int a2) {
	sub_49EFA0(xLeft + 1, a2);
	nox_client_drawRectFilledOpaque_49CE30(xLeft, a2 + 1, 3, 1);
	return sub_49EFA0(xLeft + 1, a2 + 2);
}

//----- (00472100) --------------------------------------------------------
int __cdecl sub_472100(int a1, int a2) {
	int result; // eax
	int v3;     // [esp-4h] [ebp-4h]

	switch (a2) {
	case 7:
		v3 = *(_DWORD*)&byte_5D4594[1096252] == 1;
		*(_DWORD*)&byte_5D4594[1096252] = 1 - *(_DWORD*)&byte_5D4594[1096252];
		nox_window_set_hidden(*(int*)&byte_5D4594[1093076], v3);
		if (byte_5D4594[2661958])
			nox_window_set_hidden(*(int*)&byte_5D4594[1093096], *(_DWORD*)&byte_5D4594[1096252] == 0);
		sub_452D80(901, 100);
		goto LABEL_6;
	case 8:
	case 12:
	case 16:
		result = 0;
		break;
	default:
	LABEL_6:
		result = 1;
		break;
	}
	return result;
}

//----- (004721A0) --------------------------------------------------------
int __cdecl sub_4721A0(int a1) {
	int result; // eax

	if (a1)
		result = nox_window_set_hidden(*(int*)&byte_5D4594[1090276], 0);
	else
		result = nox_window_set_hidden(*(int*)&byte_5D4594[1090276], 1);
	return result;
}

//----- (004721D0) --------------------------------------------------------
int sub_4721D0() {
	sub_46C4E0(*(_DWORD**)&byte_5D4594[1090276]);
	sub_46C4E0(*(_DWORD**)&byte_5D4594[1093076]);
	if (*(_DWORD*)&byte_5D4594[1093096])
		sub_46C4E0(*(_DWORD**)&byte_5D4594[1093096]);
	sub_4714E0();
	sub_472310();
	return sub_4721A0(*(int*)&dword_587000_80828);
}

//----- (00472220) --------------------------------------------------------
void sub_472220() {
	if (!sub_477600()) {
		if (*(_DWORD*)&byte_5D4594[1090308])
			sub_4674E0(*(int*)&byte_5D4594[1090308]);
	}
}

//----- (00472240) --------------------------------------------------------
void sub_472240() {
	if (!sub_477600()) {
		if (*(_DWORD*)&byte_5D4594[1090844])
			sub_4674E0(*(int*)&byte_5D4594[1090844]);
	}
}

//----- (00472260) --------------------------------------------------------
void sub_472260() {
	if (!sub_477600()) {
		if (*(_DWORD*)&byte_5D4594[1091380])
			sub_4674E0(*(int*)&byte_5D4594[1091380]);
	}
}

//----- (00472280) --------------------------------------------------------
wchar_t* sub_472280() {
	wchar_t* result; // eax
	char* v1;        // eax
	char* v2;        // eax
	char* v3;        // eax

	result = *(wchar_t**)&byte_5D4594[2618908];
	if (*(_DWORD*)&byte_5D4594[2618908]) {
		v1 = sub_42E8E0(38, 1);
		nox_wcsncpy((wchar_t*)&byte_5D4594[1091372], (const wchar_t*)v1, 3u);
		*(_WORD*)&byte_5D4594[1091378] = 0;
		v2 = sub_42E8E0(36, 1);
		nox_wcsncpy((wchar_t*)&byte_5D4594[1090300], (const wchar_t*)v2, 3u);
		result = *(wchar_t**)&byte_5D4594[2618908];
		*(_WORD*)&byte_5D4594[1090306] = 0;
		if (*(_BYTE*)(*(_DWORD*)&byte_5D4594[2618908] + 2251)) {
			v3 = sub_42E8E0(37, 1);
			result = nox_wcsncpy((wchar_t*)&byte_5D4594[1090836], (const wchar_t*)v3, 3u);
			*(_WORD*)&byte_5D4594[1090842] = 0;
		}
	}
	return result;
}

//----- (00472310) --------------------------------------------------------
unsigned __int8* sub_472310() {
	unsigned __int8* result; // eax

	*(_WORD*)&byte_5D4594[1091384] = sub_467850(*(int*)&byte_5D4594[1096276]);
	*(_WORD*)&byte_5D4594[1090848] = sub_467850(*(int*)&byte_5D4594[1096272]);
	*(_WORD*)&byte_5D4594[1091384] = sub_467850(*(int*)&byte_5D4594[1096276]);
	*(_WORD*)&byte_5D4594[1090312] = sub_467850(*(int*)&byte_5D4594[1096268]);
	if (*(_WORD*)&byte_5D4594[1090312]) {
		result = (unsigned __int8*)nox_get_thing(*(int*)&byte_5D4594[1096268]);
		if (result) {
			nox_drawable_link_thing(&byte_5D4594[1090316], *((_DWORD*)result + 7));
			result = &byte_5D4594[1090316];
			*(_DWORD*)&byte_5D4594[1090296] = &byte_5D4594[1090316];
			if (true) // TODO: byte_5D4594 != (unsigned __int8*)-1090316
			{
				result = (unsigned __int8*)(*(_DWORD*)&byte_5D4594[1090436] | 0x40000000);
				*(_DWORD*)&byte_5D4594[1090308] = *(_DWORD*)&byte_5D4594[1096268];
				*(_DWORD*)&byte_5D4594[1090436] |= 0x40000000u;
				return result;
			}
		} else {
			*(_DWORD*)&byte_5D4594[1090296] = 0;
		}
		*(_DWORD*)&byte_5D4594[1090308] = *(_DWORD*)&byte_5D4594[1096268];
	} else {
		*(_WORD*)&byte_5D4594[1090312] = sub_467850(*(int*)&byte_5D4594[1096284]);
		if (*(_WORD*)&byte_5D4594[1090312]) {
			nox_thing* t1 = nox_get_thing(*(int*)&byte_5D4594[1096284]);
			if (t1) {
				nox_drawable_link_thing(&byte_5D4594[1090316], t1->field_1c);
				*(_DWORD*)&byte_5D4594[1090296] = &byte_5D4594[1090316];
				if (true) // TODO: byte_5D4594 != (unsigned __int8*)-1090316
				{
					*(_DWORD*)&byte_5D4594[1090436] |= 0x40000000u;
					result = *(unsigned __int8**)&byte_5D4594[1096284];
					*(_DWORD*)&byte_5D4594[1090308] = *(_DWORD*)&byte_5D4594[1096284];
					return result;
				}
			} else {
				*(_DWORD*)&byte_5D4594[1090296] = 0;
			}
			result = *(unsigned __int8**)&byte_5D4594[1096284];
			*(_DWORD*)&byte_5D4594[1090308] = *(_DWORD*)&byte_5D4594[1096284];
		} else {
			result = (unsigned __int8*)sub_467850(*(int*)&byte_5D4594[1096280]);
			*(_WORD*)&byte_5D4594[1090312] = (_WORD)result;
			if ((_WORD)result) {
				result = (unsigned __int8*)nox_get_thing(*(int*)&byte_5D4594[1096280]);
				if (result) {
					result = (unsigned __int8*)nox_drawable_link_thing(&byte_5D4594[1090316],
											   *((_DWORD*)result + 7));
					*(_DWORD*)&byte_5D4594[1090296] = &byte_5D4594[1090316];
					if (true) // TODO: byte_5D4594 != (unsigned __int8*)-1090316
					{
						result =
						    (unsigned __int8*)(*(_DWORD*)&byte_5D4594[1090436] | 0x40000000);
						*(_DWORD*)&byte_5D4594[1090308] = *(_DWORD*)&byte_5D4594[1096280];
						*(_DWORD*)&byte_5D4594[1090436] |= 0x40000000u;
						return result;
					}
				} else {
					*(_DWORD*)&byte_5D4594[1090296] = 0;
				}
				*(_DWORD*)&byte_5D4594[1090308] = *(_DWORD*)&byte_5D4594[1096280];
			} else {
				*(_DWORD*)&byte_5D4594[1090296] = 0;
				*(_DWORD*)&byte_5D4594[1090308] = 0;
			}
		}
	}
	return result;
}

//----- (004724E0) --------------------------------------------------------
void sub_4724E0() {
	dword_587000_149232 -= 10;
	if (*(int*)&dword_587000_149232 < 500)
		dword_587000_149232 = 500;
}

//----- (00472500) --------------------------------------------------------
void sub_472500() {
	dword_587000_149232 += 10;
	if (dword_587000_149232 > 4000)
		dword_587000_149232 = 4000;
}

//----- (00472520) --------------------------------------------------------
int __cdecl sub_472520(int a1) {
	int result; // eax

	result = a1;
	dword_587000_149232 = a1;
	return result;
}

//----- (00472530) --------------------------------------------------------
int sub_472530() { return dword_587000_149232; }

//----- (00472540) --------------------------------------------------------
int __cdecl sub_472540(int a1) {
	int v1;     // edx
	int v2;     // eax
	int result; // eax
	int2 a1a;   // [esp+0h] [ebp-8h]

	if (a1 == *(_DWORD*)&byte_5D4594[2614252]) {
		sub_435670(&a1a);
	} else {
		v1 = *(_DWORD*)(a1 + 16);
		a1a.field_0 = *(_DWORD*)(a1 + 12);
		a1a.field_4 = v1;
	}
	v2 = sub_421790(&a1a, *(int*)&byte_5D4594[1096312]);
	if (v2)
		*(_DWORD*)&byte_5D4594[1096312] = v2;
	else
		v2 = *(_DWORD*)&byte_5D4594[1096312];
	if (v2)
		result = (unsigned __int8)sub_4214A0(v2)[130];
	else
		result = 1;
	return result;
}

//----- (004725C0) --------------------------------------------------------
int4* __cdecl sub_4725C0(int a1) {
	int4* result; // eax

	result = (int4*)sub_4356C0(*(int*)&byte_5D4594[2614252], 2);
	if (!result) {
		sub_437260();
		*(_DWORD*)&byte_5D4594[1096316] = sub_472540(a1);
		sub_472600(a1, *(int*)&byte_5D4594[1096316]);
		result = sub_437290();
	}
	return result;
}

//----- (00472600) --------------------------------------------------------
int __cdecl sub_472600(int a1, int a2) {
	char* v2;             // ebp
	int v3;               // esi
	int v4;               // kr08_4
	int v5;               // ebx
	int v6;               // et1
	int v7;               // esi
	int v8;               // ebx
	int v9;               // ebp
	int v10;              // eax
	int v11;              // edi
	char v12;             // al
	int v13;              // eax
	int v14;              // esi
	int v15;              // ebp
	unsigned __int8* v16; // esi
	int v17;              // eax
	int v18;              // eax
	int v19;              // eax
	int v20;              // et1
	int v21;              // ecx
	int v22;              // ebx
	int v23;              // ebp
	int v24;              // esi
	int v25;              // ecx
	int v26;              // et1
	char v27;             // al
	char v28;             // dl
	int v29;              // edi
	char* v30;            // esi
	float* v31;           // esi
	int v32;              // et1
	double v33;           // st7
	int v34;              // et1
	double v35;           // st7
	float* j;             // esi
	int v37;              // et1
	double v38;           // st7
	_DWORD* v39;          // eax
	int k;                // esi
	struc_19* v41;        // eax
	int v42;              // et1
	int v43;              // eax
	int v44;              // eax
	int v45;              // edi
	_DWORD* v46;          // eax
	char* v47;            // eax
	int* v48;             // eax
	_DWORD* v49;          // eax
	_DWORD* v50;          // edi
	char* v51;            // eax
	int* v52;             // eax
	int v53;              // eax
	int v54;              // eax
	char* v55;            // eax
	char* v56;            // eax
	_DWORD* v57;          // eax
	int* v58;             // eax
	int l;                // esi
	BOOL v60;             // eax
	int v61;              // edx
	_DWORD* v62;          // edi
	struc_19* v63;        // eax
	int v64;              // et1
	char* v65;            // eax
	int* v66;             // eax
	int v68;              // [esp-10h] [ebp-70h]
	int v69;              // [esp+10h] [ebp-50h]
	int v70;              // [esp+10h] [ebp-50h]
	int i;                // [esp+14h] [ebp-4Ch]
	int v72;              // [esp+14h] [ebp-4Ch]
	int v73;              // [esp+14h] [ebp-4Ch]
	int v74;              // [esp+18h] [ebp-48h]
	char* v75;            // [esp+18h] [ebp-48h]
	int2 v76;             // [esp+20h] [ebp-40h]
	int v77;              // [esp+28h] [ebp-38h]
	int v78;              // [esp+2Ch] [ebp-34h]
	int v79;              // [esp+30h] [ebp-30h]
	int v80;              // [esp+34h] [ebp-2Ch]
	int v81;              // [esp+38h] [ebp-28h]
	int2 xLeft;           // [esp+40h] [ebp-20h]
	int yTop;             // [esp+4Ch] [ebp-14h]
	int2 v84;             // [esp+50h] [ebp-10h]
	int v85;              // [esp+5Ch] [ebp-4h]

	v2 = sub_437250();
	if (!byte_5D4594[1096300]) {
		byte_5D4594[1096300] = sub_410D60("InvisibleWallSet");
		byte_5D4594[1096301] = sub_410D60("InvisibleBlockingWallSet");
	}
	nox_client_drawEnableAlpha_434560(0);
	sub_49F7F0();
	v3 = nox_win_width / 6;
	v4 = nox_win_height - nox_win_width / 6;
	yTop = v4 / 2;
	nox_client_copyRect_49F6F0(0, 0, nox_win_width, nox_win_height);
	v5 = *(_DWORD*)v2;
	if (*(_DWORD*)v2 <= 0) {
		nox_client_drawRectFilledAlpha_49CF10(0, v4 / 2, v3, v3);
	} else {
		nox_client_drawSetColor_434460(*(int*)&byte_5D4594[2650656]);
		if (v5 >= v3) {
			nox_client_drawRectFilledOpaque_49CE30(0, v4 / 2, v3, v3);
		} else {
			nox_client_drawRectFilledOpaque_49CE30(0, v4 / 2, v5, v3);
			nox_client_drawRectFilledAlpha_49CF10(v5, v4 / 2, v3 - v5, v3);
		}
	}
	nox_client_drawEnableAlpha_434560(1);
	nox_client_drawSetColor_434460(*(int*)&byte_5D4594[2650656]);
	nox_client_drawSetAlpha_434580(0x5Au);
	nox_client_drawRectLines_473510(-1, yTop - 1, v3 + 2, v3 + 2);
	nox_client_drawSetAlpha_434580(0x3Cu);
	nox_client_drawRectLines_473510(-2, yTop - 2, v3 + 4, v3 + 4);
	nox_client_drawSetAlpha_434580(0x28u);
	nox_client_drawRectLines_473510(-3, yTop - 3, v3 + 6, v3 + 6);
	nox_client_drawEnableAlpha_434560(0);
	nox_client_copyRect_49F6F0(0, yTop, v3, v3);
	v6 = dword_587000_149232;
	v7 = v3 * v6 / 100;
	sub_435670(&v84);
	v8 = v84.field_0 - v7 / 2;
	v9 = v84.field_4 - v7 / 2;
	xLeft.field_0 = v84.field_0 - v7 / 2;
	xLeft.field_4 = v9;
	v81 = v8 / 23;
	v77 = (v8 + v7) / 23;
	v78 = (v9 + v7) / 23;
	v74 = 23 * (v8 / 23);
	v80 = 23 * (v9 / 23);
	v10 = v9 / 23;
	for (i = v9 / 23; i <= v78; ++i) {
		v11 = sub_4106A0(v10);
		while (v11) {
			v12 = *(_BYTE*)(v11 + 1);
			if (v12 == byte_5D4594[1096300])
				goto LABEL_37;
			if (v12 == byte_5D4594[1096301])
				goto LABEL_37;
			if (*(_BYTE*)(v11 + 8) && *(unsigned __int8*)(v11 + 8) != a2)
				goto LABEL_37;
			v13 = *(unsigned __int8*)(v11 + 5);
			if (v13 < v81)
				goto LABEL_37;
			if (v13 > v77)
				break;
			v14 = v74 + 23 * (v13 - v81);
			if (*(_BYTE*)(v11 + 4) & 0x10) {
				v15 = *(_DWORD*)(v11 + 32);
				if (!v15)
					goto LABEL_37;
				v69 = 0;
				v16 = &byte_587000[149244];
				while (1) {
					v17 = nox_server_getWallAtPoint_410580(*((_DWORD*)v16 - 1) + *(unsigned __int8*)(v11 + 5),
							 *(_DWORD*)v16 + *(unsigned __int8*)(v11 + 6));
					if (v17) {
						if (*(_DWORD*)(v17 + 12))
							goto LABEL_28;
					} else {
						v18 = nox_server_getWallAtPoint_410580(*((_DWORD*)v16 - 1) + *(unsigned __int8*)(v11 + 5),
								 *(unsigned __int8*)(v11 + 6));
						if (v18 && *(_DWORD*)(v18 + 12) ||
						    (v19 = nox_server_getWallAtPoint_410580(*(unsigned __int8*)(v11 + 5),
								      *(_DWORD*)v16 + *(unsigned __int8*)(v11 + 6))) !=
							    0 &&
							*(_DWORD*)(v19 + 12)) {
						LABEL_28:
							if (v69 < 4) {
								v20 = dword_587000_149232;
								v21 = 8 * *(unsigned __int8*)(v15 + 299);
								v22 = 100 * (*(int*)(v15 + 12) - xLeft.field_0) / v20;
								v85 = 100 * (*(int*)(v15 + 16) - xLeft.field_4) / v20;
								v23 = 100 * *(int*)&byte_587000[v21 + 196184] / v20;
								v24 = 100 * *(int*)&byte_587000[v21 + 196188] / v20;
								nox_client_drawSetColor_434460(*(int*)&byte_5D4594[2650644]);
								nox_client_drawAddPoint_49F500(v22, yTop + v85);
								sub_49F570(v23, v24);
								nox_client_drawLineFromPoints_49E4B0();
								v8 = xLeft.field_0;
							}
							goto LABEL_37;
						}
					}
					v16 += 8;
					++v69;
					if ((int)v16 >= (int)&byte_587000[149276])
						goto LABEL_37;
				}
			}
			if (nox_common_gameFlags_check_40A5C0(0x10000) || *(_DWORD*)(v11 + 12)) {
				v26 = dword_587000_149232;
				v25 = v26;
				v76.field_0 = 100 * (v14 - v8) / v26;
				v76.field_4 = yTop + 100 * (v80 - v9) / v26;
				v27 = *(_BYTE*)(v11 + 4);
				if (!(v27 & 4) || (v28 = *(_BYTE*)(*(_DWORD*)(v11 + 28) + 21), v28 != 3) && v28 != 2) {
					if (!(v27 & 0x20))
						sub_4730D0(&v76, *(_BYTE*)v11, 2300 / v25);
				}
			}
		LABEL_37:
			v11 = *(_DWORD*)(v11 + 24);
			v9 = xLeft.field_4;
		}
		v10 = i + 1;
		v80 += 23;
	}
	if (nox_common_engineFlags & 8) {
		v29 = sub_50CB00();
		v30 = (char*)sub_50CB10();
		if (v29 >= 2) {
			nox_client_drawSetColor_434460(*(int*)&byte_5D4594[2618904]);
			if (v29 - 1 > 0) {
				v31 = (float*)(v30 + 8);
				v72 = v29 - 1;
				do {
					v32 = dword_587000_149232;
					v33 = *(v31 - 1);
					xLeft.field_0 = (int)(100 * ((unsigned __int64)(__int64)*(v31 - 2) - v8)) / v32;
					nox_client_drawAddPoint_49F500(xLeft.field_0,
						   yTop + (int)(100 * ((unsigned __int64)(__int64)v33 - v9)) / v32);
					v34 = dword_587000_149232;
					v35 = v31[1];
					xLeft.field_0 = (int)(100 * ((unsigned __int64)(__int64)*v31 - v8)) / v34;
					nox_client_drawAddPoint_49F500(xLeft.field_0,
						   yTop + (int)(100 * ((unsigned __int64)(__int64)v35 - v9)) / v34);
					nox_client_drawLineFromPoints_49E4B0();
					v31 += 2;
					--v72;
				} while (v72);
			}
		}
		for (j = (float*)sub_50AAE0(); j; j = (float*)sub_50AB10()) {
			nox_client_drawSetColor_434460(*(int*)&byte_5D4594[2650644]);
			v37 = dword_587000_149232;
			v38 = j[1];
			xLeft.field_0 = (int)(100 * ((unsigned __int64)(__int64)*j - v8)) / v37;
			sub_473570(xLeft.field_0, yTop + (int)(100 * ((unsigned __int64)(__int64)v38 - v9)) / v37);
		}
	}
	v73 = 0;
	if (!*(_DWORD*)&byte_5D4594[1096304]) {
		*(_DWORD*)&byte_5D4594[1096304] = sub_44CFC0((CHAR*)&byte_587000[149320]);
		*(_DWORD*)&byte_5D4594[1096308] = sub_44CFC0((CHAR*)&byte_587000[149328]);
	}
	v39 = sub_418C80(*(int*)&byte_5D4594[2616328]);
	v70 = (int)v39;
	if (v39 && sub_419130((int)v39))
		v73 = 1;
	for (k = sub_459EB0(); k; k = sub_459EC0(k)) {
		v41 = sub_4217B0((int2*)(k + 12), 0);
		if (v41) {
			if (BYTE2(v41->field_0[32]) != a2)
				continue;
		} else if (a2 != 1) {
			continue;
		}
		v42 = dword_587000_149232;
		xLeft.field_0 = 100 * (*(int*)(k + 12) - v8) / v42;
		xLeft.field_4 = yTop + 100 * (*(int*)(k + 16) - v9) / v42;
		if (!(*(_DWORD*)(k + 112) & 0x400000) ||
		    (v43 = *(_DWORD*)&byte_5D4594[2650684], !(*(_BYTE*)(k + 116) & 8)))
			v43 = *(_DWORD*)&byte_5D4594[2650644];
		nox_client_drawSetColor_434460(v43);
		v44 = *(_DWORD*)(k + 108);
		if (v44 == *(int*)&byte_5D4594[1096304]) {
			if (sub_418B10() || (v45 = sub_45A000()) == 0) {
			LABEL_64:
				nox_client_drawSetColor_434460(*(int*)&byte_5D4594[2618904]);
				v46 = sub_418C80(*(_DWORD*)(k + 128));
				if (v46) {
					v47 = sub_418AB0(*((unsigned __int8*)v46 + 4));
					if (v47) {
						v48 = (int*)sub_418D50((int)v47);
						nox_client_drawSetColor_434460(*v48);
					}
				}
				sub_473420(&xLeft);
			} else {
				while (!sub_4356C0(v45, 30)) {
					v45 = sub_45A010(v45);
					if (!v45)
						goto LABEL_64;
				}
			}
			continue;
		}
		if (v44 == *(int*)&byte_5D4594[1096308]) {
			v49 = sub_418C80(*(_DWORD*)(k + 128));
			v50 = v49;
			if (v49 && sub_419130((int)v49)) {
				v51 = sub_418AB0(*((unsigned __int8*)v50 + 4));
				if (v51) {
					v52 = (int*)sub_418D50((int)v51);
					nox_client_drawSetColor_434460(*v52);
				}
			} else {
				nox_client_drawSetColor_434460(*(int*)&byte_5D4594[2523948]);
			}
			nox_video_drawCircleRad3_4734F0(&xLeft.field_0);
			continue;
		}
		v53 = *(_DWORD*)(k + 112);
		if (v53 & 0x10000000) {
			if (*(_DWORD*)(k + 120) & 0x1000000) {
				nox_client_drawSetColor_434460(*(int*)&byte_5D4594[2523948]);
				v54 = sub_4B9470(*(const char***)(k + 436));
				v55 = sub_418AB0(v54);
				if (v55)
					goto LABEL_88;
				goto LABEL_89;
			}
		} else {
			if (!(v53 & 4)) {
				sub_473570(xLeft.field_0, xLeft.field_4);
				continue;
			}
			if (!nox_common_gameFlags_check_40A5C0(32)) {
				if (k == *(int*)&byte_5D4594[2614252])
					sub_4735C0(xLeft.field_0, xLeft.field_4);
				else
					sub_473570(xLeft.field_0, xLeft.field_4);
				continue;
			}
			v56 = sub_417040(*(_DWORD*)(k + 128));
			if (v56) {
				v81 = *((_DWORD*)v56 + 1) & 1;
				if (v81) {
					nox_client_drawSetColor_434460(*(int*)&byte_5D4594[2523948]);
					v57 = sub_418C80(*(_DWORD*)(k + 128));
					if (v57) {
						v55 = *((_BYTE*)v57 + 4) == 1 ? sub_418AB0(2) : sub_418AB0(1);
						if (v55) {
						LABEL_88:
							v58 = (int*)sub_418D50((int)v55);
							nox_client_drawSetColor_434460(*v58);
						}
					}
				LABEL_89:
					sub_4733B0(&xLeft);
					continue;
				}
			}
		}
	}
	v79 = *(_DWORD*)&byte_5D4594[2618904];
	for (l = sub_45A000(); l; l = sub_45A010(l)) {
		v60 = sub_4356C0(l, 30);
		v61 = *(_DWORD*)(l + 128);
		v77 = v60;
		v62 = sub_418C80(v61);
		v68 = *(_DWORD*)(l + 128);
		v81 = (int)v62;
		v75 = sub_417040(v68);
		if (v70 && v62 && v73) {
			v76.field_0 = sub_419150(v70, (int)v62);
			if (v76.field_0)
				goto LABEL_103;
		} else {
			v76.field_0 = 0;
		}
		if (v77 || l == *(_DWORD*)&byte_5D4594[2614252] ||
		    *(_BYTE*)(*(_DWORD*)&byte_5D4594[2618908] + 3680) & 1) {
		LABEL_103:
			v63 = sub_4217B0((int2*)(l + 12), 0);
			if ((!v63 || BYTE2(v63->field_0[32]) == a2) && v75 && (v75[3680] & 1) != 1) {
				v64 = dword_587000_149232;
				xLeft.field_0 = 100 * (*(int*)(l + 12) - v8) / v64;
				xLeft.field_4 = yTop + 100 * (*(int*)(l + 16) - v9) / v64;
				if (l == *(_DWORD*)&byte_5D4594[2614252] || v76.field_0)
					nox_client_drawSetColor_434460(v79);
				else
					nox_client_drawSetColor_434460(*(int*)&byte_5D4594[2650644]);
				if (v77) {
					if (v81) {
						v65 = sub_418AB0(*(unsigned __int8*)(v81 + 4));
						if (v65) {
							v66 = (int*)sub_418D50((int)v65);
							nox_client_drawSetColor_434460(*v66);
						}
					}
					sub_473420(&xLeft);
				} else {
					sub_473570(xLeft.field_0, xLeft.field_4);
				}
			}
		}
	}
	return sub_49F860();
}

//----- (004730D0) --------------------------------------------------------
int __cdecl sub_4730D0(int2* a1, unsigned __int8 a2, int a3) {
	int result; // eax
	int v4;     // ebx
	int v5;     // edi
	int2* v6;   // ebp

	if (dword_587000_149232 <= 2000) {
		v4 = *(_DWORD*)&byte_5D4594[2650660];
		result = a2;
		v5 = a3 / 2;
		switch (a2) {
		case 0u:
			result = sub_473380(a1->field_0, a3 + a1->field_4, a1->field_0 + a3, a1->field_4,
					    *(int*)&byte_5D4594[2650660]);
			break;
		case 1u:
			result = sub_473380(a1->field_0, a1->field_4, a1->field_0 + a3, a1->field_4 + a3,
					    *(int*)&byte_5D4594[2650660]);
			break;
		case 2u:
			sub_473380(a1->field_0, a3 + a1->field_4, a1->field_0 + a3, a1->field_4,
				   *(int*)&byte_5D4594[2650660]);
			result = sub_473380(a1->field_0, a1->field_4, a1->field_0 + a3, a1->field_4 + a3, v4);
			break;
		case 3u:
			sub_473380(a1->field_0, a1->field_4, a1->field_0 + v5, a1->field_4 + v5,
				   *(int*)&byte_5D4594[2650660]);
			result = sub_473380(a1->field_0, a3 + a1->field_4, a3 + a1->field_0, a1->field_4, v4);
			break;
		case 4u:
			sub_473380(a1->field_0, a1->field_4, a1->field_0 + a3, a1->field_4 + a3,
				   *(int*)&byte_5D4594[2650660]);
			result = sub_473380(v5 + a1->field_0, v5 + a1->field_4, a3 + a1->field_0, a1->field_4, v4);
			break;
		case 5u:
			sub_473380(a1->field_0, a3 + a1->field_4, a1->field_0 + a3, a1->field_4,
				   *(int*)&byte_5D4594[2650660]);
			result = sub_473380(v5 + a1->field_0, v5 + a1->field_4, a3 + a1->field_0, a1->field_4 + a3, v4);
			break;
		case 6u:
			v6 = a1;
			sub_473380(a1->field_0, a1->field_4, a1->field_0 + a3, a1->field_4 + a3,
				   *(int*)&byte_5D4594[2650660]);
			goto LABEL_15;
		case 7u:
			sub_473380(a1->field_0, a1->field_4, a1->field_0 + v5, a1->field_4 + v5,
				   *(int*)&byte_5D4594[2650660]);
			result = sub_473380(v5 + a1->field_0, v5 + a1->field_4, a3 + a1->field_0, a1->field_4, v4);
			break;
		case 8u:
			sub_473380(v5 + a1->field_0, v5 + a1->field_4, a1->field_0 + a3, a1->field_4 + a3,
				   *(int*)&byte_5D4594[2650660]);
			result = sub_473380(v5 + a1->field_0, v5 + a1->field_4, a3 + a1->field_0, a1->field_4, v4);
			break;
		case 9u:
			sub_473380(v5 + a1->field_0, v5 + a1->field_4, a1->field_0 + a3, a1->field_4 + a3,
				   *(int*)&byte_5D4594[2650660]);
			result = sub_473380(v5 + a1->field_0, v5 + a1->field_4, a1->field_0, a1->field_4 + a3, v4);
			break;
		case 0xAu:
			v6 = a1;
			sub_473380(a1->field_0, a1->field_4, a1->field_0 + v5, a1->field_4 + v5,
				   *(int*)&byte_5D4594[2650660]);
		LABEL_15:
			result = sub_473380(v6->field_0, a3 + v6->field_4, v5 + v6->field_0, v6->field_4 + v5, v4);
			break;
		default:
			return result;
		}
	} else {
		nox_client_drawSetColor_434460(*(int*)&byte_5D4594[2650660]);
		result = sub_49EFA0(a1->field_0, a1->field_4);
	}
	return result;
}

//----- (00473380) --------------------------------------------------------
int __cdecl sub_473380(int a1, int a2, int a3, int a4, int a5) {
	nox_client_drawSetColor_434460(a5);
	nox_client_drawAddPoint_49F500(a1, a2);
	nox_client_drawAddPoint_49F500(a3, a4);
	return nox_client_drawLineFromPoints_49E4B0();
}

//----- (004733B0) --------------------------------------------------------
int __cdecl sub_4733B0(_DWORD* a1) {
	int v1; // esi
	int v2; // edi

	v1 = a1[1] + 4;
	v2 = *a1 - 2;
	nox_client_drawAddPoint_49F500(v2, v1);
	v1 -= 8;
	nox_client_drawAddPoint_49F500(v2, v1);
	nox_client_drawLineFromPoints_49E4B0();
	nox_client_drawAddPoint_49F500(v2, v1);
	v2 += 4;
	nox_client_drawAddPoint_49F500(v2, v1);
	nox_client_drawLineFromPoints_49E4B0();
	nox_client_drawAddPoint_49F500(v2, v1);
	v1 += 4;
	nox_client_drawAddPoint_49F500(v2, v1);
	nox_client_drawLineFromPoints_49E4B0();
	nox_client_drawAddPoint_49F500(v2, v1);
	nox_client_drawAddPoint_49F500(v2 - 4, v1);
	return nox_client_drawLineFromPoints_49E4B0();
}

//----- (00473420) --------------------------------------------------------
int __cdecl sub_473420(_DWORD* a1) {
	int v1; // edi
	int v2; // esi

	v1 = a1[1] + 6;
	v2 = *a1 - 4;
	nox_client_drawAddPoint_49F500(v2, v1);
	v1 -= 12;
	v2 -= 2;
	nox_client_drawAddPoint_49F500(v2, v1);
	nox_client_drawLineFromPoints_49E4B0();
	nox_client_drawAddPoint_49F500(v2, v1);
	v1 += 6;
	v2 += 4;
	nox_client_drawAddPoint_49F500(v2, v1);
	nox_client_drawLineFromPoints_49E4B0();
	nox_client_drawAddPoint_49F500(v2, v1);
	v1 -= 6;
	v2 += 2;
	nox_client_drawAddPoint_49F500(v2, v1);
	nox_client_drawLineFromPoints_49E4B0();
	nox_client_drawAddPoint_49F500(v2, v1);
	v1 += 6;
	v2 += 2;
	nox_client_drawAddPoint_49F500(v2, v1);
	nox_client_drawLineFromPoints_49E4B0();
	nox_client_drawAddPoint_49F500(v2, v1);
	v1 -= 6;
	v2 += 4;
	nox_client_drawAddPoint_49F500(v2, v1);
	nox_client_drawLineFromPoints_49E4B0();
	nox_client_drawAddPoint_49F500(v2, v1);
	v1 += 12;
	v2 -= 2;
	nox_client_drawAddPoint_49F500(v2, v1);
	nox_client_drawLineFromPoints_49E4B0();
	nox_client_drawAddPoint_49F500(v2, v1);
	nox_client_drawAddPoint_49F500(v2 - 8, v1);
	return nox_client_drawLineFromPoints_49E4B0();
}

//----- (004734F0) --------------------------------------------------------
int __cdecl nox_video_drawCircleRad3_4734F0(int* a1) { return nox_video_drawCircle_4B0B90(*a1, a1[1], 3); }

//----- (00473510) --------------------------------------------------------
int __cdecl nox_client_drawRectLines_473510(int a1, int a2, int a3, int a4) {
	int v4; // esi
	int v5; // edi

	nox_client_drawAddPoint_49F500(a1, a2);
	v4 = a1 + a3 - 1;
	nox_client_drawAddPoint_49F500(v4, a2);
	nox_client_drawLineFromPoints_49E4B0();
	nox_client_drawAddPoint_49F500(v4, a2);
	v5 = a4 - 1 + a2;
	nox_client_drawAddPoint_49F500(v4, v5);
	nox_client_drawLineFromPoints_49E4B0();
	nox_client_drawAddPoint_49F500(v4, v5);
	nox_client_drawAddPoint_49F500(a1, v5);
	return nox_client_drawLineFromPoints_49E4B0();
}

//----- (00473570) --------------------------------------------------------
void __cdecl sub_473570(int xLeft, int yTop) {
	if (dword_587000_149232 > 1200)
		sub_499B70(xLeft, yTop, (dword_587000_149232 < 1750) + 2);
	else
		sub_499B70(xLeft, yTop, 4);
}

//----- (004735C0) --------------------------------------------------------
void __cdecl sub_4735C0(int xLeft, int yTop) {
	if (dword_587000_149232 > 1200)
		sub_499B70(xLeft, yTop, (dword_587000_149232 < 1750) + 4);
	else
		sub_499B70(xLeft, yTop, 6);
}

//----- (00473610) --------------------------------------------------------
char sub_473610() {
	int v0; // eax

	v0 = sub_477600();
	if (v0 != 1) {
		if (byte_5D4594[1096424] & 1) {
			sub_452D80(785, 100);
			v0 = *(_DWORD*)&byte_5D4594[1096424];
			LOBYTE(v0) = byte_5D4594[1096424] & 0xFE;
		} else {
			sub_452D80(784, 100);
			v0 = *(_DWORD*)&byte_5D4594[1096424];
			LOBYTE(v0) = byte_5D4594[1096424] | 1;
		}
		*(_DWORD*)&byte_5D4594[3799524] = 1;
		*(_DWORD*)&byte_5D4594[1096424] = v0;
	}
	return v0;
}

//----- (00473670) --------------------------------------------------------
int sub_473670() { return byte_5D4594[1096424] & 1; }

//----- (00473680) --------------------------------------------------------
int sub_473680() {
	int result; // eax

	*(_DWORD*)&byte_5D4594[1096420] = sub_42F970("CursorBitmap");
	result = sub_455C30();
	if (result) {
		result = sub_456070();
		if (result) {
			result = sub_470710();
			if (result) {
				result = sub_4714E0();
				if (result) {
					result = sub_45B9D0();
					if (result) {
						result = sub_476E20();
						if (result) {
							result = sub_4BFAD0();
							if (result) {
								result = sub_465E00();
								*(_DWORD*)&byte_5D4594[1096328] = result;
								if (result) {
									result = sub_4ADAD0();
									if (result) {
										result = sub_48D000();
										if (result) {
											result = sub_4C3760();
											if (result) {
												result = sub_46C730();
												if (result) {
													result =
													    sub_4C09D0();
													if (result) {
														result =
														    sub_478110();
														if (result) {
															result =
															    sub_49B3E0();
															if (result) {
																result =
																    sub_4BFC90();
																if (result) {
																	result =
																	    sub_4BFEF0();
																	if (result) {
																		result =
																		    sub_4799A0();
																		if (result) {
																			result =
																			    sub_460E60();
																			if (result) {
																				result =
																				    sub_450C70();
																				*(_DWORD*)&byte_5D4594
																				    [1096352] =
																				    result;
																				if (result) {
																					result =
																					    sub_46A730();
																					if (result) {
																						result =
																						    sub_44E560();
																						if (result) {
																							result =
																							    sub_4C3500();
																							if (result) {
																								result =
																								    sub_46E870();
																								*(_DWORD*)&byte_5D4594
																								    [1096340] =
																								    result;
																								if (result) {
																									result =
																									    sub_4465C0();
																									*(_DWORD*)&byte_5D4594
																									    [1096324] =
																									    result;
																									if (result) {
																										result =
																										    sub_4C1D80();
																										if (result) {
																											result =
																											    sub_445790();
																											if (result) {
																												result =
																												    sub_4AB260();
																												if (result) {
																													result =
																													    sub_445650();
																													if (result) {
																														result =
																														    sub_4C3390();
																														if (result) {
																															result =
																															    sub_48C980();
																															if (result) {
																																sub_450BE0();
																																sub_4AB4A0(
																																    0);
																																sub_4AB4D0(
																																    0);
																																if (!dword_587000_80828 ||
																																    *(_DWORD*)&nox_common_engineFlags &
																																	0x40000) {
																																	sub_4721A0(
																																	    0);
																																	sub_460EA0(
																																	    0);
																																	nox_window_set_visible_unk5(
																																	    0);
																																	sub_45D500(
																																	    0);
																																	sub_455A00(
																																	    0);
																																	sub_455F10(
																																	    0);
																																}
																																result =
																																    1;
																															}
																														}
																													}
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return result;
}

//----- (00473840) --------------------------------------------------------
int sub_473840() {
	sub_450BF0();
	sub_4C03E0();
	sub_46CCB0();
	sub_4AE3B0();
	sub_48D450();
	sub_4C4220();
	sub_4C12A0();
	sub_4BFD10();
	sub_49B490();
	sub_478F80();
	sub_479D10();
	sub_4AB470();
	sub_4C34A0();
	sub_445770();
	sub_456240();
	sub_455EE0();
	sub_460E90();
	sub_4505E0();
	sub_46A860();
	sub_49C7A0();
	sub_4597E0(1);
	sub_467980();
	sub_46C5D0();
	dword_587000_80828 = *(_DWORD*)&byte_587000[80832];
	return 1;
}

//----- (004738E0) --------------------------------------------------------
int sub_4738E0() {
	int result; // eax
	_DWORD* v1; // eax

	result = 1;
	if (*(_DWORD*)&byte_5D4594[1556112] != 1) {
		if (byte_5D4594[1096424] & 1) {
			v1 = sub_45A6F0(*(int*)&byte_5D4594[2616328]);
			sub_4725C0((int)v1);
		}
		result = sub_445530();
	}
	return result;
}

//----- (00473920) --------------------------------------------------------
void sub_473920() { *(_DWORD*)&byte_5D4594[1096520] = 1; }

//----- (00473930) --------------------------------------------------------
char* sub_473930() {
	char* result; // eax

	*(_DWORD*)&byte_5D4594[1096456] = sub_42FA20("ConfusedBirdies");
	result = sub_42FA20("SphericalShieldAnim");
	*(_DWORD*)&byte_5D4594[1096460] = result;
	return result;
}

//----- (00473960) --------------------------------------------------------
int sub_473960() {
	int result; // eax

	result = 0;
	*(_DWORD*)&byte_5D4594[1096456] = 0;
	*(_DWORD*)&byte_5D4594[1096460] = 0;
	return result;
}

//----- (00473970) --------------------------------------------------------
void __cdecl sub_473970(int2* a1, int2* a2) {
	a2->field_0 = *(_DWORD*)&byte_5D4594[1096428] + a1->field_0;
	a2->field_4 = *(_DWORD*)&byte_5D4594[1096432] + a1->field_4;
}

//----- (004739A0) --------------------------------------------------------
int __cdecl sub_4739A0(int2* a1, int2* a2) {
	int result; // eax

	a2->field_0 = a1->field_0 - *(_DWORD*)&byte_5D4594[1096428];
	result = a1->field_4 - *(_DWORD*)&byte_5D4594[1096432];
	a2->field_4 = result;
	return result;
}

//----- (004739D0) --------------------------------------------------------
int __cdecl sub_4739D0(int a1) { return a1 - *(_DWORD*)&byte_5D4594[1096432]; }

//----- (004739E0) --------------------------------------------------------
int __cdecl sub_4739E0(_DWORD* a1, int2* a2, int2* a3) {
	int result; // eax

	a3->field_0 = a2->field_0 + *a1 - a1[4];
	result = a2->field_4;
	a3->field_4 = result + a1[1] - a1[5];
	return result;
}

//----- (00473A10) --------------------------------------------------------
int __cdecl sub_473A10(_DWORD* a1, int2* a2, _DWORD* a3) {
	int result; // eax

	*a3 = a2->field_0 + a1[4] - *a1;
	result = a2->field_4;
	a3[1] = result + a1[5] - a1[1];
	return result;
}

//----- (00473A40) --------------------------------------------------------
int sub_473A40() {
	nox_drawable_list_1 = nox_malloc(sizeof(void*) * nox_drawable_list_1_cap);
	if (!nox_drawable_list_1)
		return 0;
	nox_drawable_list_1_size = 0;

	nox_drawable_list_3 = nox_malloc(nox_drawable_lists_cap * sizeof(void*));
	if (!nox_drawable_list_3)
		return 0;
	nox_drawable_list_3_size = 0;

	nox_drawable_list_2 = nox_malloc(nox_drawable_lists_cap * sizeof(void*));
	if (!nox_drawable_list_2)
		return 0;
	nox_drawable_list_2_size = 0;

	nox_drawable_list_4 = nox_malloc(nox_drawable_lists_cap * sizeof(void*));
	if (!nox_drawable_list_4)
		return 0;
	nox_drawable_list_4_size = 0;

	*(_DWORD*)&byte_5D4594[1096496] = nox_malloc(0x400u);
	if (!*(_DWORD*)&byte_5D4594[1096496])
		return 0;
	*(_DWORD*)&byte_5D4594[1096500] = 0;
	*(_DWORD*)&byte_5D4594[1096504] = nox_malloc(0x400u);
	if (!*(_DWORD*)&byte_5D4594[1096504])
		return 0;
	*(_DWORD*)&byte_5D4594[1096508] = 0;
	*(_DWORD*)&byte_5D4594[1096512] = nox_malloc(0x400u);
	if (!*(_DWORD*)&byte_5D4594[1096512])
		return 0;
	*(_DWORD*)&byte_5D4594[1096516] = 0;
	return 1;
}

//----- (00473B30) --------------------------------------------------------
int sub_473B30_free() {
	if (nox_drawable_list_1) {
		free(nox_drawable_list_1);
		nox_drawable_list_1 = 0;
		nox_drawable_list_1_size = 0;
	}
	if (nox_drawable_list_3) {
		free(nox_drawable_list_3);
		nox_drawable_list_3 = 0;
		nox_drawable_list_3_size = 0;
	}
	if (nox_drawable_list_2) {
		free(nox_drawable_list_2);
		nox_drawable_list_2 = 0;
		nox_drawable_list_2_size = 0;
	}
	if (nox_drawable_list_4) {
		free(nox_drawable_list_4);
		nox_drawable_list_4 = 0;
		nox_drawable_list_4_size = 0;
	}
	if (*(_DWORD*)&byte_5D4594[1096496]) {
		free(*(LPVOID*)&byte_5D4594[1096496]);
		*(_DWORD*)&byte_5D4594[1096496] = 0;
		*(_DWORD*)&byte_5D4594[1096500] = 0;
	}
	if (*(_DWORD*)&byte_5D4594[1096504]) {
		free(*(LPVOID*)&byte_5D4594[1096504]);
		*(_DWORD*)&byte_5D4594[1096504] = 0;
		*(_DWORD*)&byte_5D4594[1096508] = 0;
	}
	if (*(_DWORD*)&byte_5D4594[1096512]) {
		free(*(LPVOID*)&byte_5D4594[1096512]);
		*(_DWORD*)&byte_5D4594[1096512] = 0;
		*(_DWORD*)&byte_5D4594[1096516] = 0;
	}
	return 1;
}

//----- (00473C10) --------------------------------------------------------
char __cdecl sub_473C10(_DWORD* a1, unsigned __int8* a2) {
	int v2;              // eax
	unsigned __int8* v3; // esi
	unsigned __int8 v4;  // dl
	int v5;              // ecx
	int v6;              // ebx
	int v7;              // ebp
	int v8;              // eax
	int v9;              // edi
	int v10;             // eax
	int v11;             // ecx
	int v12;             // eax
	int v13;             // ecx
	int v14;             // eax
	int v15;             // edx
	int v16;             // eax
	int v17;             // ecx
	int v18;             // eax
	int v19;             // ecx
	bool v20;            // zf
	BOOL v21;            // edx
	int v22;             // ebx
	int v23;             // ecx
	int v24;             // edx
	int v25;             // eax
	unsigned __int8 v26; // al
	unsigned __int8 v27; // al
	char v28;            // cl
	int v29;             // eax
	int v30;             // eax
	int v31;             // eax
	int* v32;            // edi
	int v33;             // eax
	int v34;             // eax
	int v35;             // eax
	int v36;             // edx
	int v37;             // eax
	int v38;             // eax
	int v39;             // eax
	int v40;             // edx
	int v41;             // eax
	int v42;             // eax
	int v43;             // eax
	int v44;             // edx
	char* v45;           // eax
	int v46;             // ebx
	int v47;             // ebp
	int v48;             // eax
	int v49;             // ecx
	int v50;             // edx
	int v51;             // eax
	int v52;             // eax
	int v53;             // eax
	_BYTE* v54;          // edi
	char* v55;           // eax
	int v56;             // ebx
	int v57;             // ebp
	int v58;             // eax
	int v59;             // edx
	int v60;             // ecx
	int v61;             // eax
	int v63;             // [esp-18h] [ebp-80h]
	int v64;             // [esp-14h] [ebp-7Ch]
	int v65;             // [esp-10h] [ebp-78h]
	int v66;             // [esp-Ch] [ebp-74h]
	int v67;             // [esp-8h] [ebp-70h]
	int v68;             // [esp-4h] [ebp-6Ch]
	int v69;             // [esp-4h] [ebp-6Ch]
	int a3;              // [esp+10h] [ebp-58h]
	int a4;              // [esp+14h] [ebp-54h]
	int v72;             // [esp+18h] [ebp-50h]
	int v73;             // [esp+1Ch] [ebp-4Ch]
	int v74;             // [esp+20h] [ebp-48h]
	int v75;             // [esp+24h] [ebp-44h]
	int v76;             // [esp+28h] [ebp-40h]
	int2 v77;            // [esp+2Ch] [ebp-3Ch]
	int2 a2a;            // [esp+34h] [ebp-34h]
	int2 a1a;            // [esp+3Ch] [ebp-2Ch]
	int2 v80;            // [esp+44h] [ebp-24h]
	int2 v81;            // [esp+4Ch] [ebp-1Ch]
	int v82;             // [esp+54h] [ebp-14h]
	int v83[3];          // [esp+5Ch] [ebp-Ch]
	int v84;             // [esp+70h] [ebp+8h]

	LOBYTE(v2) = nox_win_width;
	v3 = a2;
	a4 = nox_win_width;
	v72 = 0;
	a3 = 0;
	if (!a2)
		return v2;
	v4 = a2[4];
	if (!(v4 & 1))
		return v2;
	v5 = a2[6];
	v6 = *a1 + 23 * a2[5] - a1[4];
	v82 = *a1 + 23 * a2[5] - a1[4];
	v7 = a1[1] + 23 * v5 - a1[5];
	v74 = *(_DWORD*)&byte_587000[4 * a2[3] + 149364];
	v8 = v74;
	if (v74 == -1) {
		v8 = *a2;
		v74 = *a2;
	}
	v84 = v8;
	if (v8) {
		if (v8 == 1 && v4 & 0x40)
			v84 = 12;
	} else if (v4 & 0x40) {
		v84 = 11;
	}
	if (!*(_DWORD*)&byte_587000[80808])
		goto LABEL_54;
	v9 = 16 * v74;
	v10 = *(_DWORD*)&byte_587000[16 * v74 + 85440];
	v11 = *(_DWORD*)&byte_587000[16 * v74 + 85448];
	a1a.field_4 = v7 + *(_DWORD*)&byte_587000[16 * v74 + 85444];
	v12 = v6 + v10;
	a2a.field_4 = v7 + *(_DWORD*)&byte_587000[16 * v74 + 85452];
	v13 = v6 + v11;
	a1a.field_0 = v12;
	a2a.field_0 = v13;
	if (v74 == 7 || v74 == 9) {
		if (sub_4C42A0(&a1a, &a2a, &a3, &a4)) {
			v22 = 1;
		} else {
			v22 = 0;
			a3 = a2a.field_0;
		}
		v23 = *(_DWORD*)&byte_587000[v9 + 85508];
		a1a.field_0 = v82 + *(_DWORD*)&byte_587000[v9 + 85504];
		v24 = v82 + *(_DWORD*)&byte_587000[v9 + 85512];
		v25 = *(_DWORD*)&byte_587000[v9 + 85516];
		a1a.field_4 = v7 + v23;
		a2a.field_0 = v24;
		a2a.field_4 = v7 + v25;
		v2 = sub_4C42A0(&a1a, &a2a, &a3, &a4);
		if (v2) {
		LABEL_51:
			v19 = a3;
			v2 = a4;
			goto LABEL_52;
		}
		if (!v22)
			return v2;
		v2 = a4;
		if (a4 > a1a.field_0) {
			v2 = a1a.field_0;
			a4 = a1a.field_0;
		}
		v19 = a3;
	LABEL_52:
		if (v19 >= v2) {
			v26 = v3[4];
			v3[3] = 0;
			LOBYTE(v2) = v26 & 0xFC;
			v3[4] = v2;
			return v2;
		}
	LABEL_54:
		v27 = v3[4];
		v28 = v3[4] & 2;
		if (!v28) {
			v29 = (v3[4] >> 2) & 2;
			goto LABEL_64;
		}
		if (*(_DWORD*)&byte_5D4594[805848] && *(_DWORD*)&byte_5D4594[805844]) {
			if (!dword_587000_80820 && *(_DWORD*)&byte_587000[154952])
				goto LABEL_61;
			v72 = 8;
		}
		if (dword_587000_80820) {
		LABEL_62:
			v29 = (v27 & 8 | 4u) >> 2;
		LABEL_64:
			v73 = v29;
			if (v28 && *(_DWORD*)&byte_5D4594[805844] && !(byte_5D4594[12332 * v3[1] + 2692780] & 4)) {
				v30 = v72;
				LOBYTE(v30) = v72 | 2;
				v72 = v30;
			} else {
				v72 |= 1u;
			}
			if (*(_DWORD*)&byte_587000[80816]) {
				switch (v74) {
				case 0:
				case 3:
					v31 = v3[6];
					v77.field_0 = 23 * v3[5];
					v77.field_4 = 23 * (v31 + 1);
					v32 = (int*)(*(int(__cdecl**)(int2*)) & byte_5D4594[3807156])(&v77);
					if (dword_5d4594_3801780 == 1 && v32 != (int*)31) {
						v83[0] = *v32;
						v83[1] = v32[1];
						v33 = v32[2];
						v32 = v83;
						v83[2] = v33;
					}
					v77.field_0 += 23;
					v77.field_4 -= 23;
					v34 = (*(int(__cdecl**)(int2*)) & byte_5D4594[3807156])(&v77);
					goto LABEL_96;
				case 1:
				case 4:
					v35 = v3[6];
					v77.field_0 = 23 * v3[5];
					v77.field_4 = 23 * v35;
					v32 = (int*)(*(int(__cdecl**)(int2*)) & byte_5D4594[3807156])(&v77);
					if (dword_5d4594_3801780 == 1 && v32 != (int*)31) {
						v83[0] = *v32;
						v83[1] = v32[1];
						v36 = v32[2];
						v32 = v83;
						v83[2] = v36;
					}
					v77.field_0 += 23;
					v77.field_4 += 23;
					goto LABEL_95;
				case 7:
					v37 = v3[6];
					v77.field_0 = 23 * v3[5];
					v77.field_4 = 23 * v37;
					v32 = (int*)(*(int(__cdecl**)(int2*)) & byte_5D4594[3807156])(&v77);
					if (dword_5d4594_3801780 == 1 && v32 != (int*)31) {
						v83[0] = *v32;
						v83[1] = v32[1];
						v38 = v32[2];
						v32 = v83;
						v83[2] = v38;
					}
					v77.field_0 += 23;
					v34 = (*(int(__cdecl**)(int2*)) & byte_5D4594[3807156])(&v77);
					goto LABEL_96;
				case 8:
					v39 = v3[6];
					v77.field_0 = 23 * v3[5] + 11;
					v77.field_4 = 23 * v39 + 11;
					v32 = (int*)(*(int(__cdecl**)(int2*)) & byte_5D4594[3807156])(&v77);
					if (dword_5d4594_3801780 == 1 && v32 != (int*)31) {
						v83[0] = *v32;
						v83[1] = v32[1];
						v40 = v32[2];
						v32 = v83;
						v83[2] = v40;
					}
					v77.field_0 -= 34;
					v77.field_4 -= 34;
					goto LABEL_95;
				case 10:
					v41 = v3[6];
					v77.field_0 = 23 * v3[5];
					v77.field_4 = 23 * (v41 + 1);
					v32 = (int*)(*(int(__cdecl**)(int2*)) & byte_5D4594[3807156])(&v77);
					if (dword_5d4594_3801780 == 1 && v32 != (int*)31) {
						v83[0] = *v32;
						v83[1] = v32[1];
						v42 = v32[2];
						v32 = v83;
						v83[2] = v42;
					}
					v77.field_0 += 11;
					v77.field_4 -= 11;
					v34 = (*(int(__cdecl**)(int2*)) & byte_5D4594[3807156])(&v77);
					goto LABEL_96;
				default:
					v43 = v3[6];
					v77.field_0 = 23 * v3[5];
					v77.field_4 = 23 * (v43 + 1);
					v32 = (int*)(*(int(__cdecl**)(int2*)) & byte_5D4594[3807156])(&v77);
					if (dword_5d4594_3801780 == 1 && v32 != (int*)31) {
						v83[0] = *v32;
						v83[1] = v32[1];
						v44 = v32[2];
						v32 = v83;
						v83[2] = v44;
					}
					v77.field_0 += 23;
				LABEL_95:
					v34 = (*(int(__cdecl**)(int2*)) & byte_5D4594[3807156])(&v77);
				LABEL_96:
					v74 = v34;
					v45 = sub_46A3F0(v3[1], v84, v3[2], v73);
					v46 = v82 + *(_DWORD*)v45 - 51;
					v47 = -73 - *((_DWORD*)v45 + 1) + v7;
					v48 = sub_4345F0(1);
					LOBYTE(v48) = *((_BYTE*)v32 + 8);
					LOBYTE(v49) = *((_BYTE*)v32 + 4);
					LOBYTE(v50) = *(_BYTE*)v32;
					sub_433CD0(v50, v49, v48);
					if (!(v72 & 2)) {
						v69 = v72;
						v66 = a4;
						v65 = a3;
						v64 = nox_win_height;
						v63 = v74;
						v52 = sub_46A3B0(v3[1], v84, v3[2], v73);
						(*(void(__cdecl**)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD,
								   _DWORD, _DWORD, _DWORD, _DWORD)) &
						 byte_5D4594[3807128])(v52, v46, v47, v32, v63, v64, v65, v66, 0, v69);
						goto LABEL_106;
					}
					if (!sub_47D380(a3, a4))
						goto LABEL_106;
					nox_client_drawEnableAlpha_434560(1);
					nox_client_drawSetAlpha_434580(0x80u);
					sub_47D400(dword_587000_80820 == 0, a1[5]);
					v68 = v47;
					v67 = v46;
					v51 = sub_46A3B0(v3[1], v84, v3[2], v73);
					break;
				}
			} else {
				v53 = v3[6];
				v77.field_0 = 23 * v3[5] + 11;
				v77.field_4 = 23 * v53 + 11;
				v54 = (_BYTE*)(*(int(__cdecl**)(int2*)) & byte_5D4594[3807156])(&v77);
				v55 = sub_46A3F0(v3[1], v84, v3[2], v73);
				v56 = v82 + *(_DWORD*)v55 - 50;
				v57 = -72 - *((_DWORD*)v55 + 1) + v7;
				v58 = sub_4345F0(1);
				LOBYTE(v59) = v54[8];
				LOBYTE(v58) = v54[4];
				LOBYTE(v60) = *v54;
				sub_433CD0(v60, v58, v59);
				if (!(v72 & 2)) {
					if (sub_47D380(a3, a4)) {
						sub_47D400(dword_587000_80820 == 0, a1[5]);
						v61 = sub_46A3B0(v3[1], v84, v3[2], v73);
						nox_client_drawImageAt_47D2C0(v61, v56, v57);
						sub_47D400(0, 0);
					}
					goto LABEL_106;
				}
				if (!sub_47D380(a3, a4)) {
				LABEL_106:
					sub_4345F0(0);
					LOBYTE(v2) = v3[4] & 0xFC;
					v3[3] = 0;
					v3[4] = v2;
					*((_DWORD*)v3 + 3) = 1;
					return v2;
				}
				nox_client_drawEnableAlpha_434560(1);
				nox_client_drawSetAlpha_434580(0x80u);
				sub_47D400(dword_587000_80820 == 0, a1[5]);
				v68 = v57;
				v67 = v56;
				v51 = sub_46A3B0(v3[1], v84, v3[2], v73);
			}
			nox_client_drawImageAt_47D2C0(v51, v67, v68);
			sub_47D400(0, 0);
			nox_client_drawEnableAlpha_434560(0);
			goto LABEL_106;
		}
	LABEL_61:
		v72 |= 4u;
		goto LABEL_62;
	}
	if (v74 != 8 && v74 != 10) {
		v2 = sub_4C42A0(&a1a, &a2a, &a3, &a4);
		if (!v2)
			return v2;
		goto LABEL_51;
	}
	v76 = v13;
	v75 = v12;
	if (sub_4C42A0(&a1a, &a2a, &v75, &v76))
		v73 = v76 - v75 >= 3;
	else
		v73 = 0;
	v14 = *(_DWORD*)&byte_587000[16 * v74 + 85504];
	v15 = *(_DWORD*)&byte_587000[16 * v74 + 85516];
	v80.field_4 = v7 + *(_DWORD*)&byte_587000[16 * v74 + 85508];
	v16 = v6 + v14;
	v17 = v6 + *(_DWORD*)&byte_587000[16 * v74 + 85512];
	v80.field_0 = v16;
	a3 = v16;
	v81.field_0 = v17;
	a4 = v17;
	v81.field_4 = v7 + v15;
	v18 = sub_4C42A0(&v80, &v81, &a3, &a4);
	v19 = a3;
	v20 = v18 == 0;
	v2 = a4;
	if (v20)
		v21 = 0;
	else
		v21 = a4 - a3 >= 3;
	if (v73) {
		if (v21) {
			if (a3 > v75) {
				v19 = v75;
				a3 = v75;
			}
			if (v19 <= v80.field_0) {
				v19 = 0;
				a3 = 0;
			}
			if (a4 < v76) {
				v2 = v76;
				a4 = v76;
			}
			if (v2 >= v81.field_0) {
				v2 = nox_win_width;
				a4 = nox_win_width;
			}
		} else {
			v19 = v75;
			v2 = v76;
			a3 = v75;
			a4 = v76;
			if (v74 != 8) {
				v84 = 1;
			LABEL_33:
				if (v19 == v80.field_0) {
					v19 = 0;
					a3 = 0;
				}
				goto LABEL_52;
			}
			v84 = 0;
			if (v76 == v81.field_0) {
				v2 = nox_win_width;
				a4 = nox_win_width;
			}
		}
		goto LABEL_52;
	}
	if (v21) {
		v84 = (v74 != 8) + 13;
		if (a4 == v81.field_0) {
			v2 = nox_win_width;
			a4 = nox_win_width;
		}
		goto LABEL_33;
	}
	return v2;
}
// 474366: variable 'v50' is possibly undefined
// 474366: variable 'v49' is possibly undefined
// 4744A3: variable 'v60' is possibly undefined
// 4744A3: variable 'v59' is possibly undefined

//----- (004745F0) --------------------------------------------------------
int __cdecl sub_4745F0(_DWORD* a1) {
	void(__cdecl * v1)(int, unsigned __int8*); // ebx
	int result;                                // eax
	int* i;                                    // ebp
	int v4;                                    // esi
	int v5;                                    // eax

	v1 = sub_476850;
	if (dword_5d4594_3799624)
		v1 = (void(__cdecl*)(int, unsigned __int8*))sub_476AE0;
	result = nox_drawable_list_2_size;
	for (i = nox_drawable_list_2; nox_drawable_list_2_size > 0; --nox_drawable_list_2_size) {
		v4 = *i;
		++i;
		sub_4746C0(a1, v4);
		if (sub_4984B0_drawable(v4)) {
			*(_DWORD*)(v4 + 484) = 1;
			v1((int)a1, (unsigned __int8*)v4);
			if (*(_BYTE*)(v4 + 280) & 0x40)
				sub_4C4F40(a1, v4);
			sub_474E60(a1, v4);
			sub_495BB0((_DWORD*)v4, a1);
			if (nox_common_engineFlags & 2)
				nox_thing_debug_draw(a1, v4);
			v5 = *(_DWORD*)(v4 + 480);
			*(_DWORD*)(v4 + 132) = 0;
			if (!v5 && !*(_DWORD*)(v4 + 488))
				*(_DWORD*)(v4 + 340) = *(_DWORD*)&byte_5D4594[2598000];
		}
		result = nox_drawable_list_2_size - 1;
	}
	return result;
}

//----- (00474B40) --------------------------------------------------------
int __cdecl sub_474B40(int a1) {
	_DWORD* v1; // edi
	_DWORD* v2; // eax
	int v3;     // eax

	v1 = sub_418C80(*(int*)&byte_5D4594[2616328]);
	if (v1) {
		v2 = sub_418C80(*(_DWORD*)(a1 + 128));
		if (v2) {
			if (*(_DWORD*)&byte_5D4594[2616328] == *(_DWORD*)(a1 + 128) || sub_419150((int)v1, (int)v2))
				return 1;
		}
	}
	v3 = *(_DWORD*)&byte_5D4594[2614252];
	if (a1 == *(_DWORD*)&byte_5D4594[2614252])
		return 1;
	if (*(_DWORD*)&byte_5D4594[2614252]) {
		if (!sub_4356C0(*(int*)&byte_5D4594[2614252], 21)) {
			v3 = *(_DWORD*)&byte_5D4594[2614252];
			goto LABEL_9;
		}
		return 1;
	}
LABEL_9:
	if (*(_BYTE*)(a1 + 112) & 4) {
		if (a1 != v3)
			sub_417040(*(_DWORD*)(a1 + 128));
	}
	return 0;
}

//----- (00474BE0) --------------------------------------------------------
int __cdecl sub_474BE0(_DWORD* a1, int* a2, int a3, int a4, int a5, int a6, int a7, int a8) {
	int* v8;    // ebp
	int v9;     // esi
	int v10;    // eax
	int v11;    // edx
	int v12;    // edi
	int v13;    // eax
	int v14;    // ecx
	int v15;    // eax
	int v16;    // edi
	int v17;    // ebx
	int v18;    // eax
	int v19;    // ecx
	int v20;    // eax
	int v21;    // ecx
	int v22;    // eax
	int v23;    // eax
	int result; // eax
	float v25;  // [esp+0h] [ebp-2Ch]
	float v26;  // [esp+0h] [ebp-2Ch]
	float v27;  // [esp+0h] [ebp-2Ch]
	float v28;  // [esp+0h] [ebp-2Ch]
	int i;      // [esp+14h] [ebp-18h]
	int2 v30;   // [esp+1Ch] [ebp-10h]
	int2 v31;   // [esp+24h] [ebp-8h]
	float v32;  // [esp+34h] [ebp+8h]

	v8 = a2;
	v9 = a8;
	for (i = 0; i < 2; ++i) {
		if (i) {
			v9 += 128;
			if (v9 < 256)
				goto LABEL_7;
		} else {
			v9 = a4 + (unsigned __int8)(10 * (byte_5D4594[2598000] + *(_BYTE*)(a3 + 128)));
			if (v9 < 256)
				goto LABEL_7;
		}
		v9 -= 256;
	LABEL_7:
		v32 = 0.70709997;
		if (!a5)
			v32 = 1.0;
		v25 = (double)(2 * *(int*)&byte_587000[8 * v9 + 192088]) * v32 + (double)*v8;
		v10 = nox_float2int(v25);
		v11 = *(int*)&byte_587000[8 * v9 + 192092];
		v30.field_0 = v10;
		v26 = (double)(2 * v11) * v32 + (double)v8[1];
		v30.field_4 = nox_float2int(v26);
		v12 = v9 - 6 + (v9 - 6 < 0 ? 0x100 : 0);
		v27 = (double)(2 * *(int*)&byte_587000[8 * v12 + 192088]) * v32 + (double)*v8;
		v13 = nox_float2int(v27);
		v14 = *(int*)&byte_587000[8 * v12 + 192092];
		v31.field_0 = v13;
		v28 = (double)(2 * v14) * v32 + (double)v8[1];
		v15 = nox_float2int(v28);
		v16 = v30.field_4;
		v17 = v15;
		v18 = v8[1];
		v19 = 0;
		v31.field_4 = v17;
		if (v30.field_4 >= v18)
			goto LABEL_25;
		if (a8 == 1)
			v19 = 1;
		if (v30.field_4 >= v18) {
		LABEL_25:
			if (!a8)
				goto LABEL_24;
		}
		if (v19) {
		LABEL_24:
			if (a5 == 1) {
				v20 = *v8;
				v21 = v30.field_0;
				goto LABEL_19;
			}
			if (a5 == 2) {
				v20 = v30.field_0;
				v21 = *v8;
			LABEL_19:
				v22 = 35 * (v20 - v21) / (2 * *(_DWORD*)&byte_587000[192088]);
				v16 = v22 + v30.field_4;
				v17 += v22;
			}
			v23 = *(__int16*)(a3 + 104);
			v30.field_4 = -20 - v23 + v16;
			v31.field_4 = -20 - v23 + v17;
			sub_474DD0(a1, &v30, &v31, a6, a7);
		}
		result = i + 1;
	}
	return result;
}

//----- (00474DD0) --------------------------------------------------------
int __cdecl sub_474DD0(_DWORD* a1, int2* a2, int2* a3, int a4, int a5) {
	int2 xLeft; // [esp+8h] [ebp-8h]

	sub_4739E0(a1, a2, &xLeft);
	sub_4B6720(&xLeft, a4, 10, 12);
	nox_client_drawSetColor_434460(a5);
	sub_499B70(xLeft.field_0, xLeft.field_4, 3);
	nox_client_drawAddPoint_49F500(xLeft.field_0, xLeft.field_4);
	sub_4739E0(a1, a3, &xLeft);
	nox_client_drawAddPoint_49F500(xLeft.field_0, xLeft.field_4);
	nox_client_drawSetColor_434460(a5);
	return nox_client_drawLineFromPoints_49E4B0();
}

//----- (004754C0) --------------------------------------------------------
size_t __cdecl sub_4754C0(int a1) {
	size_t result; // eax

	result = *(_DWORD*)&byte_5D4594[1096516];
	if (*(int*)&byte_5D4594[1096516] < 256) {
		*(_DWORD*)(*(_DWORD*)&byte_5D4594[1096512] + 4 * *(_DWORD*)&byte_5D4594[1096516]) = a1;
		result = ++*(_DWORD*)&byte_5D4594[1096516];
	}
	return result;
}

//----- (004754F0) --------------------------------------------------------
void __cdecl sub_4754F0(_DWORD* a1) {
	int v1;  // edx
	int v2;  // ecx
	int v3;  // edx
	int4 v4; // [esp+0h] [ebp-10h]

	v1 = a1[4] + a1[8];
	v4.field_0 = a1[4];
	v2 = a1[5];
	v4.field_8 = v1;
	v3 = a1[9];
	v4.field_4 = v2;
	v4.field_C = v3 + v2 + 128;
	nox_drawable_list_1_size = 0;
	nox_drawable_list_3_size = 0;
	nox_drawable_list_2_size = 0;
	nox_drawable_list_4_size = 0;
	*(_DWORD*)&byte_5D4594[1096500] = 0;
	*(_DWORD*)&byte_5D4594[1096508] = 0;
	sub_49AB00(&v4, sub_475560_draw, (int)a1);
}

//----- (00475560) --------------------------------------------------------
void __cdecl sub_475560_draw(nox_drawable* dr, int a2) {
	if (sub_4756E0_drawable(dr)) {
		if (nox_drawable_list_2_size < nox_drawable_lists_cap)
			nox_drawable_list_2[nox_drawable_list_2_size++] = dr;
		return;
	}
	if (sub_475740_drawable(dr)) {
		if (nox_drawable_list_3_size < nox_drawable_lists_cap)
			nox_drawable_list_3[nox_drawable_list_3_size++] = dr;
	} else if (sub_4757A0_drawable(dr)) {
		if (nox_drawable_list_4_size < nox_drawable_lists_cap)
			nox_drawable_list_4[nox_drawable_list_4_size++] = dr;
	} else if (sub_4757D0_drawable(dr) && (*(_DWORD*)&byte_587000[80836] || dr == *(_DWORD*)&byte_5D4594[2614252] ||
					       sub_4984B0_drawable(dr))) {
		if (!dr->field_122) {
			if (sub_4984B0_drawable(dr)) {
				dr->field_121 = 1;
				dr->field_120 = 0;
			} else {
				if (!dr->field_121 || (LOBYTE(dr->field_28) & 0x6))
					return;
				dr->field_120 = 1;
			}
		}
		if ((dr->field_120 || dr->field_122) &&
		    (unsigned int)(*(_DWORD*)&byte_5D4594[2598000] - dr->field_85) > *(int*)&byte_5D4594[2649704]) {
			dr->field_120 = 0;
		} else if (nox_drawable_list_1_size < nox_drawable_list_1_cap) {
			nox_drawable_list_1[nox_drawable_list_1_size++] = dr;
		}
	}
}

//----- (004756E0) --------------------------------------------------------
int __cdecl sub_4756E0_drawable(_DWORD* a1) {
	int result;                   // eax
	int(__cdecl * v2)(int*, int); // esi
	int v3;                       // edx
	int v4;                       // ecx

	result = 0;
	v2 = (int(__cdecl*)(int*, int))a1[75];
	if (v2) {
		v3 = a1[30];
		v4 = a1[28];
		if (!(v3 & 0x1000) && v3 & 1 && (v2 == nox_thing_static_draw || v2 == nox_thing_static_random_draw) &&
		    !(v4 & 0x80800000) && (v3 & 0x48 || v4 & 0x400000) && !(v3 & 0x800)) {
			result = 1;
		}
	}
	return result;
}

//----- (00475740) --------------------------------------------------------
int __cdecl sub_475740_drawable(_DWORD* a1) {
	int result;                   // eax
	int(__cdecl * v2)(int*, int); // edx
	int v3;                       // ebx
	int v4;                       // ecx

	result = 0;
	v2 = (int(__cdecl*)(int*, int))a1[75];
	if (v2) {
		v3 = a1[30];
		v4 = a1[28];
		if (!(v3 & 0x1000)) {
			if (v3 & 1) {
				result = 1;
				if ((v2 == nox_thing_static_draw || v2 == nox_thing_static_random_draw) &&
				    !(v4 & 0x80800000) && !(v3 & 0x800) && (v3 & 0x48 || v4 & 0x400000)) {
					result = 0;
				}
			}
		}
	}
	return result;
}

//----- (004757A0) --------------------------------------------------------
int __cdecl sub_4757A0_drawable(int a1) {
	int result; // eax
	int v2;     // ecx

	result = 0;
	if (*(_DWORD*)(a1 + 300)) {
		v2 = *(_DWORD*)(a1 + 120);
		if (!(v2 & 0x1000)) {
			if (v2 & 0x4000) {
				if (v2 & 0x40)
					result = 1;
			}
		}
	}
	return result;
}

//----- (004757D0) --------------------------------------------------------
int __cdecl sub_4757D0_drawable(_DWORD* a1) {
	int result; // eax
	int v2;     // ecx

	result = 0;
	if (a1[75]) {
		v2 = a1[30];
		if (!(v2 & 1) && (!(a1[28] & 0x2000) || v2 & 0x1000000) && !(v2 & 0x1000))
			result = 1;
	}
	return result;
}

//----- (00475810) --------------------------------------------------------
int4* __cdecl sub_475810_draw(int* a1) {
	int* v1;               // edi
	int v2;                // ebx
	int v3;                // ebp
	int v4;                // esi
	int v5;                // eax
	int v6;                // ecx
	int v7;                // esi
	int v8;                // ebp
	int4* result;          // eax
	int v10;               // ebp
	int v11;               // eax
	int v13;               // edx
	int v14;               // ebx
	int v15;               // eax
	int i;                 // ebp
	int v17;               // eax
	unsigned __int8** v18; // esi
	bool j;                // zf
	unsigned __int8* v20;  // eax
	int v21;               // ebx
	unsigned __int8* v22;  // ecx
	int v24;               // eax
	int v25;               // ebp
	int v26;               // eax
	int v27;               // eax
	char v28;              // al
	unsigned __int8** v29; // esi
	unsigned __int8** v30; // esi
	int v31;               // edx
	unsigned __int8* v32;  // eax
	unsigned __int8* v33;  // eax
	unsigned __int8 v34;   // dl
	int v36;               // [esp+14h] [ebp-10h]
	unsigned __int8** v37; // [esp+14h] [ebp-10h]
	float2 v38;            // [esp+1Ch] [ebp-8h]
	int v39;               // [esp+28h] [ebp+4h]
	int v40;               // [esp+28h] [ebp+4h]
	int v41;               // [esp+28h] [ebp+4h]

	if (!*(_DWORD*)&byte_5D4594[1096448])
		*(_DWORD*)&byte_5D4594[1096448] = sub_44CFC0((CHAR*)&byte_587000[151196]);
	sub_477F80();
	v1 = a1;
	*(_DWORD*)&byte_5D4594[3799496] = 0;
	v2 = a1[1];
	v39 = a1[0];
	if (v39) {
		*(_DWORD*)&byte_5D4594[3799468] = 1;
		v3 = v1[3];
		v4 = v1[2] + 1;
		sub_437290();
		if (*(_DWORD*)&byte_5D4594[3799524]) {
			nox_client_drawSetColor_434460(*(int*)&byte_5D4594[2650656]);
			nox_client_drawRectFilledOpaque_49CE30(0, 0, nox_backbuffer_width, v2);
			nox_client_drawRectFilledOpaque_49CE30(0, v3, nox_backbuffer_width, nox_backbuffer_height - v3);
			nox_client_drawRectFilledOpaque_49CE30(0, v2, v39, v3 - v2);
			nox_client_drawRectFilledOpaque_49CE30(v4, v2, nox_backbuffer_width - v4, v3 - v2);
			*(_DWORD*)&byte_5D4594[3799524] = 0;
		}
		nox_client_drawSetColor_434460(*(int*)&byte_5D4594[2650660]);
		nox_client_drawBorderLines_49CC70(v39 - 2, v2 - 2, v4 - v39 + 4, v3 - v2 + 4);
	} else {
		*(_DWORD*)&byte_5D4594[3799468] = 0;
	}
	sub_437260();
	v5 = v1[12];
	if (v5) {
		if (v5 <= 0)
			v1[12] = -1 - v5;
		else
			v1[12] = 1 - v5;
	}
	*(_DWORD*)&byte_5D4594[1096428] = v1[4] - *v1;
	*(_DWORD*)&byte_5D4594[1096432] = v1[5] - v1[1];
	v6 = v1[5];
	v36 = v1[4] / 23;
	*(_DWORD*)&byte_5D4594[1096516] = 0;
	v7 = v6 / 23;
	sub_496150(v1);
	v8 = 0;
	if (!nox_common_gameFlags_check_40A5C0(2048) && !sub_413830() ||
	    nox_common_gameFlags_check_40A5C0(2048) && !sub_413840() || sub_4356C0(*(int*)&byte_5D4594[2614252], 2) ||
	    dword_5d4594_2650672) {
		v8 = 1;
	}
	if (*(_DWORD*)&byte_5D4594[1556112] || v8) {
		sub_434350(*(int*)&byte_5D4594[2650656]);
		sub_440900();
		result = sub_437290();
		*(_DWORD*)&byte_5D4594[3799524] = 1;
		return result;
	}
	if (*(_DWORD*)&byte_5D4594[1096520]) {
		sub_434350(*(int*)&byte_5D4594[2523948]);
		sub_440900();
		sub_434350(*(int*)&byte_5D4594[2650656]);
		*(_DWORD*)&byte_5D4594[1096520] = 0;
		result = sub_437290();
		*(_DWORD*)&byte_5D4594[3799524] = 1;
		return result;
	}
	(*(void(__cdecl**)(_DWORD)) & byte_5D4594[3807132])(v1);
	v10 = 1;
	if (*(_DWORD*)&nox_common_engineFlags & 0x100000 ||
	    (v38.field_0 = (double)v1[6], v38.field_4 = (double)v1[7], v11 = sub_411160(&v38), v11 == 255) ||
	    v11 == -1) {
		v10 = 0;
	}
	sub_4765F0((int)v1);
	sub_4754F0(v1);
	if (v10) {
		sub_481C20(v1);
		sub_4C5500(v1);
	} else {
		sub_440900();
	}
	sub_475F10(v1);
	v13 = (int)v1[9] / 23 + 4;
	v14 = v13 + v7;
	if (v7 <= v13 + v7) {
		v15 = v36;
		v40 = v36 + v1[8] / 23 + 2;
		while (1) {
			for (i = v15; i <= v40; ++i) {
				v17 = nox_server_getWallAtPoint_410580(i, v7);
				if (v17 && !(byte_5D4594[12332 * *(unsigned __int8*)(v17 + 1) + 2692780] & 4)) {
					if (*(_BYTE*)(v17 + 4) & 2) {
						if (*(int*)&byte_5D4594[1096508] < 256)
							*(_DWORD*)(*(_DWORD*)&byte_5D4594[1096504] +
								   4 * (*(_DWORD*)&byte_5D4594[1096508])++) = v17;
					} else if (*(int*)&byte_5D4594[1096500] < 256) {
						*(_DWORD*)(*(_DWORD*)&byte_5D4594[1096496] +
							   4 * (*(_DWORD*)&byte_5D4594[1096500])++) = v17;
					}
				}
			}
			if (++v7 > v14)
				break;
			v15 = v36;
		}
	}
	v18 = *(unsigned __int8***)&byte_5D4594[1096496];
	for (j = (*(_DWORD*)&byte_5D4594[1096500])-- == 0; !j; --*(_DWORD*)&byte_5D4594[1096500]) {
		v20 = *v18;
		++v18;
		sub_473C10(v1, v20);
		j = *(_DWORD*)&byte_5D4594[1096500] == 0;
	}
	sub_475FE0(v1);
	nox_video_drawCursorSelectCircle_4773C0(v1);
	qsort(nox_drawable_list_1, (size_t)nox_drawable_list_1_size, sizeof(void*), sub_476160);
	qsort(*(void**)&byte_5D4594[1096512], *(size_t*)&byte_5D4594[1096516], 4u, sub_476240);
	v37 = *(unsigned __int8***)&byte_5D4594[1096512];
	v21 = 0x7FFFFFFF;
	if (nox_drawable_list_1_size)
		v41 = *(_DWORD*)(*(_DWORD*)nox_drawable_list_1 + 16);
	else
		v41 = 0x7FFFFFFF;
	nox_drawable** v35 = nox_drawable_list_1;
	if (*(_DWORD*)&byte_5D4594[1096516]) {
		v22 = **(unsigned __int8***)&byte_5D4594[1096512];
	LABEL_51:
		v21 = sub_476080(v22);
	}
	while (nox_drawable_list_1_size || *(_DWORD*)&byte_5D4594[1096516]) {
		if (v41 >= v21) {
			if (*(_DWORD*)&byte_5D4594[1096516]) {
				sub_473C10(v1, *v37);
				v29 = v37 + 1;
				j = *(_DWORD*)&byte_5D4594[1096516] == 1;
				++v37;
				--*(_DWORD*)&byte_5D4594[1096516];
				if (!j) {
					v22 = *v29;
					goto LABEL_51;
				}
			}
			v21 = 0x7FFFFFFF;
		} else if (nox_drawable_list_1_size) {
			nox_drawable* dr = v35[0];
			v24 = &v35[1];
			v35++;
			if (--nox_drawable_list_1_size)
				v41 = *(_DWORD*)(*(_DWORD*)v24 + 16);
			else
				v41 = 0x7FFFFFFF;
			if (dr->field_27 != *(_DWORD*)&byte_5D4594[1096448] || sub_418B10() ||
			    (v25 = sub_45A000()) == 0) {
			LABEL_64:
				v26 = dr->field_28;
				if (!(v26 & 6) || (unsigned int)(*(_DWORD*)&byte_5D4594[2598000] - dr->field_72) <= 5)
					goto LABEL_71;
				if (v26 & 2) {
					v27 = dr->field_69;
					if (v27 == 9 || v27 == 10)
						goto LABEL_71;
				} else if (*(_DWORD*)&byte_5D4594[2614252] == dr) {
				LABEL_71:
					sub_4746C0(v1, dr);
					if (dr->draw_func(v1, dr)) {
						if (nox_common_engineFlags & 2)
							nox_thing_debug_draw(v1, dr);
						v28 = *(_BYTE*)(&dr->field_70);
						dr->field_33 = 0;
						if (v28 & 0x40)
							sub_4C4F40(v1, dr);
						sub_474E60(v1, dr);
						sub_495BB0(dr, v1);
						if (!dr->field_120 && !dr->field_122)
							dr->field_85 = *(_DWORD*)&byte_5D4594[2598000];
						if (sub_459DB0(dr))
							sub_459DD0(dr, 1);
						if (dr->field_28 & 0x20006)
							sub_49A6A0(v1, dr);
					}
				}
			} else {
				while (!sub_4356C0(v25, 30)) {
					v25 = sub_45A010(v25);
					if (!v25)
						goto LABEL_64;
				}
			}
		} else {
			v41 = 0x7FFFFFFF;
		}
	}
	sub_4AFD40();
	sub_4C5060(v1);
	v30 = *(unsigned __int8***)&byte_5D4594[1096504];
	v31 = *(_DWORD*)&byte_5D4594[1096508];
	if (*(_DWORD*)&byte_587000[80812]) {
		--*(_DWORD*)&byte_5D4594[1096508];
		if (v31) {
			do {
				v32 = *v30;
				++v30;
				sub_473C10(v1, v32);
				j = (*(_DWORD*)&byte_5D4594[1096508])-- == 0;
			} while (!j);
		}
	} else {
		--*(_DWORD*)&byte_5D4594[1096508];
		if (v31) {
			do {
				v33 = *v30;
				++v30;
				v34 = v33[4];
				v33[3] = 0;
				v33[4] = v34 & 0xFC;
				j = (*(_DWORD*)&byte_5D4594[1096508])-- == 0;
			} while (!j);
		}
	}
	sub_44D9F0(0);
	if (nox_common_engineFlags & 8)
		sub_476270(v1);
	sub_45AB40();
	sub_437290();
	*(_DWORD*)&byte_5D4594[3799496] = 1;
	return (int4*)sub_476680();
}
