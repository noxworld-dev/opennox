#include "client/shell/wolapi/wolchat.h"
#include "client/shell/wolapi/wolprog.h"
#include "common/system/team.h"
#include "server/ability/ability.h"
#include "server/magic/plyrgide.h"
#include "server/magic/plyrspel.h"

#include "client/gui/guiinv.h"
#include "client/gui/guijourn.h"
#include "client/gui/servopts/guiserv.h"
#include "client/gui/servopts/playrlst.h"
#include "common/wolapi/wol.h"
#include "common/wolapi/wolchnl.h"
#include "common/wolapi/wolstate.h"
#include "common/wolapi/woluser.h"

#include "client/gui/guibook.h"

#include "proto.h"

FILE* nox_file_2 = 0;
FILE* nox_file_3 = 0;

extern _DWORD dword_5d4594_527712;
extern _DWORD dword_5d4594_534768;
extern _DWORD dword_5d4594_739392;
extern _DWORD dword_5d4594_527988;
extern _DWORD dword_5d4594_529332;
extern _DWORD dword_587000_60064;
extern _DWORD dword_5d4594_600116;
extern _DWORD dword_587000_60068;
extern _DWORD dword_5d4594_528264;
extern _DWORD dword_5d4594_741296;
extern _DWORD dword_5d4594_599496;
extern void* dword_587000_66120;
extern _DWORD dword_5d4594_739996;
extern _DWORD dword_5d4594_528260;
extern _DWORD dword_5d4594_741260;
extern _DWORD dword_5d4594_534816;
extern _DWORD dword_5d4594_740072;
extern _DWORD dword_5d4594_531652;
extern _DWORD dword_5d4594_741244;
extern _DWORD dword_587000_66116;
extern _DWORD dword_5d4594_741256;
extern _DWORD dword_5d4594_740004;
extern _DWORD dword_5d4594_528272;
extern _DWORD dword_5d4594_741252;
extern _DWORD dword_5d4594_741248;
extern _DWORD dword_5d4594_529336;
extern _DWORD dword_5d4594_2660032;
extern _DWORD dword_5d4594_531656;
extern _DWORD dword_5d4594_527684;
extern _DWORD dword_5d4594_741292;
extern _DWORD dword_5d4594_588068;
extern _DWORD dword_5d4594_608316;
extern _DWORD dword_5d4594_830276;
extern _DWORD dword_5d4594_588084;
extern _DWORD dword_5d4594_588120;
extern _DWORD dword_5d4594_529324;
extern _DWORD dword_5d4594_528252;
extern _DWORD dword_587000_60044;
extern _DWORD dword_5d4594_741284;
extern _DWORD dword_5d4594_529328;
extern _DWORD dword_5d4594_531648;
extern _DWORD dword_587000_60356;
extern _DWORD dword_5d4594_528256;
extern _DWORD dword_5d4594_534808;
extern _DWORD dword_5d4594_529340;
extern _DWORD dword_587000_60352;
extern _DWORD dword_5d4594_2660652;
extern _DWORD dword_5d4594_529316;
extern obj_5D4594_2650668_t** ptr_5D4594_2650668;
extern int ptr_5D4594_2650668_cap;

//----- (004187A0) --------------------------------------------------------
char sub_4187A0() {
	int i;    // ebx
	char* v1; // eax

	for (i = 1; i < 17; ++i) {
		v1 = sub_418B10();
		if (!v1)
			return i;
		while ((unsigned __int8)v1[57] != i) {
			v1 = sub_418B60((int)v1);
			if (!v1)
				return i;
		}
	}
	return 0;
}

//----- (004187E0) --------------------------------------------------------
int sub_4187E0() {
	int result;          // eax
	unsigned __int8* v1; // ecx

	result = 1;
	v1 = getMemAt(0x5D4594, 526292 + 144);
	while (*(_DWORD*)v1) {
		v1 += 80;
		++result;
		if ((int)v1 >= (int)getMemAt(0x5D4594, 527716))
			return 0;
	}
	return result;
}

//----- (00418800) --------------------------------------------------------
void __cdecl sub_418800(wchar_t* a1, wchar_t* a2, int a3) {
	if (a1) {
		nox_wcsncpy(a1, a2, 0x14u);
		a1[20] = 0;
		*((_DWORD*)a1 + 17) = a3;
	}
}

//----- (00418830) --------------------------------------------------------
int __cdecl sub_418830(int a1, int a2) {
	int result; // eax

	result = a1;
	if (a1)
		*(_DWORD*)(a1 + 60) = a2;
	return result;
}

//----- (00418840) --------------------------------------------------------
int sub_418840() {
	int v0;     // ebp
	char* v1;   // ebx
	char* v2;   // esi
	__int16 v3; // ax
	int* i;     // edi
	char* v5;   // eax
	int j;      // esi
	_DWORD* v7; // eax
	int v8;     // ecx
	int v9;     // eax
	int k;      // esi
	int v11;    // eax

	v0 = 0;
	v1 = sub_416640();
	v2 = sub_4165B0();
	sub_419030(1);
	v3 = *((_WORD*)v2 + 26) & 0x3FFF;
	HIBYTE(v3) |= 0x80u;
	*((_WORD*)v2 + 26) = v3;
	for (i = sub_425A50(); i; i = sub_425A60(i)) {
		if (v0 >= (unsigned __int8)v1[52])
			break;
		v5 = sub_4186D0(0);
		i[9] = (int)v5;
		if (v5) {
			sub_418800((wchar_t*)v5, (wchar_t*)i + 6, 0);
			sub_418830(i[9], i[8]);
			sub_4184D0((wchar_t*)i[9]);
			++v0;
			for (j = sub_4DA7C0(); j; j = sub_4DA7F0(j)) {
				v7 = *(_DWORD**)(*(_DWORD*)(j + 748) + 276);
				if (v7[515] != *getMemU32Ptr(0x5D4594, 2616328) || !nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
					v8 = v7[920];
					if (!(v8 & 1) || v8 & 0x20) {
						v9 = v7[517];
						if (v9) {
							if (v9 == i[8])
								sub_4191D0(*(_BYTE*)(i[9] + 57), j + 48, 1, *(_DWORD*)(j + 36), 0);
						}
					}
				}
			}
		}
	}
	for (k = sub_4DA7C0(); k; k = sub_4DA7F0(k)) {
		if (!sub_419130(k + 48)) {
			v11 = *(_DWORD*)(*(_DWORD*)(k + 748) + 276);
			if ((*(_DWORD*)(v11 + 2060) != *getMemU32Ptr(0x5D4594, 2616328) ||
				 !nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) &&
				!(*(_BYTE*)(v11 + 3680) & 1)) {
				sub_4E6860(v11, 0, 0);
			}
		}
	}
	return sub_417D50(4);
}

//----- (004189D0) --------------------------------------------------------
char* sub_4189D0() {
	char* v0;           // edi
	unsigned __int8 v1; // bl
	char* i;            // esi
	unsigned __int8 v3; // al

	v0 = 0;
	v1 = 32;
	for (i = sub_418B10(); i; i = sub_418B60((int)i)) {
		v3 = sub_418BC0((int)i);
		if (v3 < v1) {
			v1 = v3;
			v0 = i;
		}
	}
	return v0;
}

//----- (00418A10) --------------------------------------------------------
char* sub_418A10() {
	char* result; // eax

	result = sub_418B10();
	if (!result)
		return sub_4186D0(0);
	while (*((_DWORD*)result + 15)) {
		result = sub_418B60((int)result);
		if (!result)
			return sub_4186D0(0);
	}
	return result;
}

//----- (00418A40) --------------------------------------------------------
char* __cdecl sub_418A40(wchar_t* a1) {
	char* v1; // esi

	v1 = sub_418B10();
	if (!v1)
		return 0;
	while (_nox_wcsicmp((const wchar_t*)v1, a1)) {
		v1 = sub_418B60((int)v1);
		if (!v1)
			return 0;
	}
	return v1;
}

//----- (00418A80) --------------------------------------------------------
char* __cdecl sub_418A80(int a1) {
	char* result; // eax

	result = sub_418B10();
	if (!result)
		return 0;
	while ((unsigned __int8)result[56] != a1) {
		result = sub_418B60((int)result);
		if (!result)
			return 0;
	}
	return result;
}

//----- (00418AB0) --------------------------------------------------------
char* __cdecl sub_418AB0(int a1) {
	char* result; // eax

	result = sub_418B10();
	if (!result)
		return 0;
	while ((unsigned __int8)result[57] != a1) {
		result = sub_418B60((int)result);
		if (!result)
			return 0;
	}
	return result;
}

//----- (00418AE0) --------------------------------------------------------
char* __cdecl sub_418AE0(int a1) {
	char* result; // eax

	result = sub_418B10();
	if (!result)
		return 0;
	while (*((_DWORD*)result + 15) != a1) {
		result = sub_418B60((int)result);
		if (!result)
			return 0;
	}
	return result;
}

//----- (00418B10) --------------------------------------------------------
char* sub_418B10() {
	char v0;            // dl
	unsigned __int8 v2; // [esp+4h] [ebp-4h]

	v0 = 1;
	v2 = 1;
	while (!*getMemU32Ptr(0x5D4594, 526292 + 64 + 80 * v2)) {
		v2 = ++v0;
		if ((unsigned __int8)v0 >= 0x11u)
			return 0;
	}
	return (char*)getMemAt(0x5D4594, 526292 + 80 * v2);
}

//----- (00418B60) --------------------------------------------------------
char* __cdecl sub_418B60(int a1) {
	unsigned __int8 v1; // dl
	unsigned __int8 v3; // [esp+8h] [ebp+4h]

	if (!a1)
		return 0;
	v3 = *(_BYTE*)(a1 + 58) + 1;
	v1 = v3;
	if (v3 >= 0x11u)
		return 0;
	while (!*getMemU32Ptr(0x5D4594, 526292 + 64 + 80 * v3)) {
		v3 = ++v1;
		if (v1 >= 0x11u)
			return 0;
	}
	return (char*)getMemAt(0x5D4594, 526292 + 80 * v3);
}

//----- (00418BC0) --------------------------------------------------------
int __cdecl sub_418BC0(int a1) {
	int v1;     // ebx
	char* i;    // esi
	_DWORD* v4; // eax

	v1 = 0;
	if (!a1)
		return 0;
	for (i = nox_common_playerInfoGetFirst_416EA0(); i; i = nox_common_playerInfoGetNext_416EE0((int)i)) {
		v4 = sub_418C80(*((_DWORD*)i + 515));
		if (v4) {
			if (sub_419180((int)v4, *(_BYTE*)(a1 + 57)))
				++v1;
		}
	}
	return v1;
}

//----- (00418C60) --------------------------------------------------------
int __cdecl sub_418C60(int a1) {
	int result; // eax

	result = a1;
	if (a1)
		result = *(_DWORD*)(a1 + 44);
	return result;
}

//----- (00418C70) --------------------------------------------------------
_DWORD* __cdecl sub_418C70(_DWORD* a1) {
	_DWORD* result; // eax

	result = a1;
	if (a1)
		result = (_DWORD*)*a1;
	return result;
}

//----- (00418C80) --------------------------------------------------------
_DWORD* __cdecl sub_418C80(int a1) {
	int v1;     // eax
	_DWORD* v3; // eax

	if (nox_common_gameFlags_check_40A5C0(1)) {
		v1 = nox_server_getObjectFromNetCode_4ECCB0(a1);
		if (v1)
			return (_DWORD*)(v1 + 48);
	} else {
		v3 = sub_45A6F0(a1);
		if (v3)
			return v3 + 6;
	}
	return 0;
}

//----- (00418CD0) --------------------------------------------------------
void __cdecl sub_418CD0(wchar_t* a1, wchar_t* a2) {
	int v2;      // eax
	char v3[46]; // [esp+4h] [ebp-30h]

	if (a1) {
		sub_457010((int)a1, a2);
		*((_DWORD*)a1 + 17) = 0;
		if (nox_common_gameFlags_check_40A5C0(1)) {
			v2 = *((unsigned __int8*)a1 + 57);
			*(_WORD*)v3 = 1220;
			*(_DWORD*)&v3[2] = v2;
			nox_wcscpy((wchar_t*)&v3[6], a2);
			sub_4E5390(159, (int)v3, 46, 0, 1);
		}
		nox_wcscpy(a1, a2);
	}
}

//----- (00418D50) --------------------------------------------------------
void* __cdecl sub_418D50(int a1) {
	int v1;              // ecx
	unsigned __int8* v2; // eax

	if (!a1)
		return 0;
	v1 = 0;
	v2 = getMemAt(0x587000, 54600);
	while (*(unsigned __int8*)(a1 + 56) != *(_DWORD*)v2) {
		v2 += 16;
		++v1;
		if ((int)v2 >= (int)getMemAt(0x587000, 54760))
			return 0;
	}
	return *(void**)getMemAt(0x587000, 16 * v1 + 54604);
}

//----- (00418D80) --------------------------------------------------------
void __cdecl sub_418D80(int a1) {
	int v1;     // eax
	char* i;    // esi
	_DWORD* v3; // eax
	int v4;     // edi
	char v5[6]; // [esp+8h] [ebp-8h]

	if (a1 && sub_418BC0(a1) > 0) {
		if (nox_common_gameFlags_check_40A5C0(1)) {
			v1 = *(unsigned __int8*)(a1 + 57);
			v5[0] = -60;
			v5[1] = 5;
			*(_DWORD*)&v5[2] = v1;
			sub_4E5390(159, (int)v5, 6, 0, 1);
		}
		for (i = nox_common_playerInfoGetFirst_416EA0(); i; i = nox_common_playerInfoGetNext_416EE0((int)i)) {
			v3 = sub_418C80(*((_DWORD*)i + 515));
			v4 = (int)v3;
			if (v3) {
				if (*((_BYTE*)v3 + 4) == *(_BYTE*)(a1 + 57)) {
					sub_4571A0(*((_DWORD*)i + 515), 0);
					sub_418E40(a1, v4);
				}
			}
		}
	}
}

//----- (00418E40) --------------------------------------------------------
_DWORD* __cdecl sub_418E40(int a1, int a2) {
	_DWORD* result; // eax
	_DWORD* v3;     // esi
	int v4;         // edi
	int i;          // esi

	result = (_DWORD*)a1;
	if (a1 && a2) {
		if (*(_DWORD*)(a1 + 44) == a2) {
			*(_DWORD*)(a1 + 44) = *(_DWORD*)a2;
		} else {
			result = (_DWORD*)sub_418C60(a1);
			if (!result)
				return result;
			while (*result != a2) {
				result = sub_418C70(result);
				if (!result)
					return result;
			}
			*result = *(_DWORD*)a2;
		}
		*(_DWORD*)a2 = 0;
		*(_BYTE*)(a2 + 4) = 0;
		result = (_DWORD*)sub_4DA7C0();
		v3 = result;
		if (result) {
			while (v3 + 12 != (_DWORD*)a2) {
				result = (_DWORD*)sub_4DA7F0((int)v3);
				v3 = result;
				if (!result)
					return result;
			}
			v4 = v3[187];
			sub_4D97E0(*(unsigned __int8*)(*(_DWORD*)(v4 + 276) + 2064));
			sub_4E8110(*(unsigned __int8*)(*(_DWORD*)(v4 + 276) + 2064));
			result = sub_4E8020((int)v3);
			for (i = v3[129]; i; i = *(_DWORD*)(i + 512)) {
				if (*(_BYTE*)(i + 8) & 6)
					result = sub_4E8020(i);
			}
		}
	}
	return result;
}

//----- (00418F20) --------------------------------------------------------
void __cdecl sub_418F20(wchar_t* a1, int a2) {
	int v2;         // edx
	char* i;        // edi
	_DWORD* v4;     // eax
	char v5[6];     // [esp+8h] [ebp-30h]
	wchar_t v6[20]; // [esp+10h] [ebp-28h]

	if (a1 && sub_418AB0(*((unsigned __int8*)a1 + 57))) {
		nox_wcscpy(v6, a1);
		if (nox_common_gameFlags_check_40A5C0(1) && a2) {
			v2 = *((unsigned __int8*)a1 + 57);
			v5[0] = -60;
			v5[1] = 6;
			*(_DWORD*)&v5[2] = v2;
			sub_4E5390(159, (int)v5, 6, 0, 1);
		}
		for (i = nox_common_playerInfoGetFirst_416EA0(); i; i = nox_common_playerInfoGetNext_416EE0((int)i)) {
			v4 = sub_418C80(*((_DWORD*)i + 515));
			if (v4 && *((_BYTE*)v4 + 4) == *((_BYTE*)a1 + 57))
				sub_418E40((int)a1, (int)v4);
		}
		*((_DWORD*)a1 + 12) = 0;
		*((_DWORD*)a1 + 16) = 0;
		*a1 = 0;
		*((_DWORD*)a1 + 17) = 0;
		*((_DWORD*)a1 + 11) = 0;
		*((_DWORD*)a1 + 18) = 0;
		*((_DWORD*)a1 + 19) = 0;
		*((_BYTE*)a1 + 57) = 0;
		*((_DWORD*)a1 + 15) = 0;
		--*getMemU8Ptr( 0x5D4594, 526280);
		sub_459CD0();
		if (nox_common_gameFlags_check_40A5C0(1))
			sub_456EA0(v6);
	}
}

//----- (00419030) --------------------------------------------------------
int __cdecl sub_419030(int a1) {
	unsigned __int8* v1; // esi
	int result;          // eax

	sub_417D70(4);
	v1 = getMemAt(0x5D4594, 526292 + 80);
	do {
		if (*((_DWORD*)v1 + 16))
			sub_418F20((wchar_t*)v1, 0);
		v1 += 80;
	} while ((int)v1 < (int)getMemAt(0x5D4594, 527652));
	result = a1;
	if (a1) {
		LOWORD(a1) = 1988;
		sub_456FA0();
		result = sub_4E5390(159, (int)&a1, 2, 0, 1);
	}
	return result;
}

//----- (00419090) --------------------------------------------------------
void __cdecl sub_419090(int a1, int a2) {
	int v2;      // edx
	int v3;      // ecx
	char v4[10]; // [esp+4h] [ebp-Ch]

	if (a1) {
		*(_DWORD*)(a1 + 52) = a2;
		if (nox_common_gameFlags_check_40A5C0(1)) {
			v2 = *(_DWORD*)(a1 + 52);
			v3 = *(unsigned __int8*)(a1 + 57);
			v4[0] = -60;
			v4[1] = 8;
			*(_DWORD*)&v4[2] = v3;
			*(_DWORD*)&v4[6] = v2;
			sub_4E5390(159, (int)v4, 10, 0, 1);
		}
	}
}

//----- (004190F0) --------------------------------------------------------
int __cdecl sub_4190F0(wchar_t* a1) {
	char* v1; // esi

	v1 = sub_418B10();
	if (!v1)
		return 0;
	while (_nox_wcsicmp((const wchar_t*)v1, a1)) {
		v1 = sub_418B60((int)v1);
		if (!v1)
			return 0;
	}
	return 1;
}

//----- (00419130) --------------------------------------------------------
BOOL __cdecl sub_419130(int a1) {
	BOOL result; // eax

	result = a1;
	if (a1)
		result = *(_BYTE*)(a1 + 4) != 0;
	return result;
}

//----- (00419150) --------------------------------------------------------
BOOL __cdecl sub_419150(int a1, int a2) {
	char v2;     // cl
	char v3;     // al
	BOOL result; // eax

	result = 0;
	if (a1) {
		if (a2) {
			v2 = *(_BYTE*)(a1 + 4);
			if (v2) {
				v3 = *(_BYTE*)(a2 + 4);
				if (v3) {
					if (v2 == v3)
						result = 1;
				}
			}
		}
	}
	return result;
}

//----- (00419180) --------------------------------------------------------
int __cdecl sub_419180(int a1, unsigned __int8 a2) {
	char* v2;   // eax
	_DWORD* v3; // eax

	if (!a1)
		return 0;
	if (*(_BYTE*)(a1 + 4) != a2)
		return 0;
	v2 = sub_418AB0(a2);
	if (!v2)
		return 0;
	v3 = (_DWORD*)sub_418C60((int)v2);
	if (!v3)
		return 0;
	while (v3 != (_DWORD*)a1) {
		v3 = sub_418C70(v3);
		if (!v3)
			return 0;
	}
	return 1;
}

//----- (00419570) --------------------------------------------------------
void __cdecl sub_419570(int a1, int a2) {
	char* v2;   // esi
	char* v3;   // ebx
	char v4[6]; // [esp+8h] [ebp-8h]

	if (a1) {
		v2 = sub_418AB0(*(unsigned __int8*)(a1 + 4));
		if (v2) {
			if (sub_419180(a1, *(_BYTE*)(a1 + 4))) {
				if (nox_common_gameFlags_check_40A5C0(1) && nox_common_gameFlags_check_40A5C0(0x2000)) {
					v3 = nox_common_playerInfoGetByID_417040(a2);
					if (v3 && sub_43AF70() == 1 && !nox_common_gameFlags_check_40A5C0(128))
						sub_425ED0((int)v3, 0);
					sub_4571A0(a2, 0);
					v4[0] = -60;
					v4[1] = 2;
					*(_DWORD*)&v4[2] = a2;
					sub_4E5390(159, (int)v4, 6, 0, 1);
				}
				sub_418E40((int)v2, a1);
				--*((_DWORD*)v2 + 12);
				if ((sub_40A740() || nox_common_gameFlags_check_40A5C0(0x8000)) && !sub_418BC0((int)v2)) {
					if (nox_common_gameFlags_check_40A5C0(96) ||
						nox_common_gameFlags_check_40A5C0(16) && sub_417DA0(4)) {
						*((_DWORD*)v2 + 15) = 0;
						sub_418800((wchar_t*)v2, (wchar_t*)getMemAt(0x5D4594, 527664), 0);
					} else {
						sub_418F20((wchar_t*)v2, 1);
					}
				}
			}
		}
	}
}

//----- (004196D0) --------------------------------------------------------
int __cdecl sub_4196D0(int a1, int a2, int a3, int a4) {
	int v4;      // ecx
	char* v5;    // eax
	char v7[10]; // [esp+8h] [ebp-Ch]

	if (!a1 || !a2 || !sub_419180(a1, *(_BYTE*)(a1 + 4)))
		return 0;
	nox_common_playerInfoGetByID_417040(a3);
	if (nox_common_gameFlags_check_40A5C0(1) && nox_common_gameFlags_check_40A5C0(0x2000)) {
		v4 = *(unsigned __int8*)(a2 + 57);
		v7[0] = -60;
		v7[1] = 3;
		*(_DWORD*)&v7[2] = v4;
		*(_WORD*)&v7[6] = a3;
		sub_4E5390(159, (int)v7, 10, 0, 1);
		sub_4571A0(a3, *(unsigned __int8*)(a2 + 57));
	}
	v5 = sub_418AB0(*(unsigned __int8*)(a1 + 4));
	--*((_DWORD*)v5 + 12);
	sub_418E40((int)v5, a1);
	sub_4191D0(*(_BYTE*)(a2 + 57), a1, 0, a3, a4);
	if (a3 == *getMemU32Ptr(0x5D4594, 2616328))
		sub_455E70(*(_BYTE*)(a2 + 57));
	return 1;
}

//----- (004197C0) --------------------------------------------------------
void __cdecl sub_4197C0(wchar_t* a1, int a2) {
	int v2;      // edi
	_DWORD* v3;  // ebp
	char v4[18]; // [esp+4h] [ebp-14h]

	if (a1) {
		*(_DWORD*)&v4[6] = *((_DWORD*)a1 + 15);
		*(_DWORD*)&v4[2] = *((unsigned __int8*)a1 + 57);
		*(_WORD*)v4 = 196;
		*(_DWORD*)&v4[10] = *((_DWORD*)a1 + 13);
		v4[14] = 0;
		v4[16] = *((_BYTE*)a1 + 56);
		v4[17] = *((_BYTE*)a1 + 68);
		if (nox_common_gameFlags_check_40A5C0(512))
			v4[14] = 1;
		v4[15] = nox_wcslen(a1);
		v2 = 2 * (unsigned __int8)v4[15];
		v3 = malloc(v2 + 18);
		*(_QWORD*)v3 = *(_QWORD*)v4;
		v3[2] = *(_DWORD*)&v4[8];
		v3[3] = *(_DWORD*)&v4[12];
		*((_WORD*)v3 + 8) = *(_WORD*)&v4[16];
		memcpy((char*)v3 + 18, a1, 2 * (unsigned __int8)v4[15]);
		sub_4E5390(a2, (int)v3, v2 + 18, 0, 1);
		free(v3);
	}
}

//----- (004198A0) --------------------------------------------------------
void __cdecl sub_4198A0(int a1, int a2, int a3) {
	int v3;      // eax
	int v4;      // ecx
	char v5[10]; // [esp+8h] [ebp-Ch]

	if (a1) {
		v3 = nox_server_getObjectFromNetCode_4ECCB0(a3);
		if (v3) {
			v5[0] = -60;
			v4 = *(unsigned __int8*)(a1 + 4);
			v5[1] = 1;
			*(_WORD*)&v5[6] = a3;
			*(_DWORD*)&v5[2] = v4;
			*(_WORD*)&v5[8] = *(_WORD*)(v3 + 4);
			sub_4E5390(a2, (int)v5, 10, 0, 1);
		}
	}
}

//----- (00419900) --------------------------------------------------------
char __cdecl sub_419900(int a1, int a2, __int16 a3) {
	char result; // al
	char v4[10]; // [esp+0h] [ebp-Ch]

	result = a1;
	if (a1 && a2) {
		result = *(_BYTE*)(a1 + 57);
		if (*(_BYTE*)(a2 + 4) != result) {
			*(_DWORD*)&v4[2] = *(unsigned __int8*)(a1 + 57);
			v4[0] = -60;
			v4[1] = 10;
			*(_WORD*)&v4[6] = a3;
			result = sub_4E53C0(31, v4, 10, 0, 1);
		}
	}
	return result;
}

//----- (00419960) --------------------------------------------------------
char __cdecl sub_419960(int a1, int a2, __int16 a3) {
	char result; // al
	char v4[10]; // [esp+0h] [ebp-Ch]

	result = a1;
	if (a1 && a2) {
		result = *(_BYTE*)(a1 + 57);
		if (*(_BYTE*)(a2 + 4) != result) {
			*(_DWORD*)&v4[2] = *(unsigned __int8*)(a1 + 57);
			v4[0] = -60;
			v4[1] = 11;
			*(_WORD*)&v4[6] = a3;
			result = sub_4E53C0(31, v4, 10, 0, 1);
		}
	}
	return result;
}

//----- (004199C0) --------------------------------------------------------
int __cdecl sub_4199C0(int a1) {
	int v1; // esi

	if (!a1)
		return 0;
	v1 = sub_4DA7C0();
	if (!v1)
		return 0;
	while (*(_BYTE*)(v1 + 52) != *(_BYTE*)(a1 + 57) || !sub_4E7BE0(v1)) {
		v1 = sub_4DA7F0(v1);
		if (!v1)
			return 0;
	}
	return 1;
}

//----- (00419A10) --------------------------------------------------------
double __cdecl sub_419A10(float a1) {
	*getMemFloatPtr(0x5D4594, 527672) = a1;
	**(_DWORD**)getMemAt(0x587000, 55744) &= 0x7FFFFFFFu;
	return *getMemFloatPtr(0x5D4594, 527672);
}

//----- (00419A30) --------------------------------------------------------
unsigned int __cdecl sub_419A30(float a1) {
	unsigned int result; // eax

	if (a1 < 0.0)
		return 0;
	*getMemU32Ptr(0x5D4594, 527668) = getMemAt(0x5D4594, 527676);
	*getMemFloatPtr(0x5D4594, 527676) = a1 + 8388608.0;
	result = 0x7fffff & *getMemU32Ptr(0x5D4594, 527676);
	*getMemU32Ptr(0x5D4594, 527680) = 0x7fffff & *getMemU32Ptr(0x5D4594, 527676);
	return result;
}

//----- (00419A70) --------------------------------------------------------
int __cdecl nox_float2int(float a1) { return (int)a1; }

//----- (00419A90) --------------------------------------------------------
__int16 __cdecl nox_float2int16(float a1) { return (int)a1; }

//----- (00419AB0) --------------------------------------------------------
__int16 __cdecl nox_float2int16_abs(float a1) { return (int)fabs(a1); }

//----- (00419AD0) --------------------------------------------------------
char __cdecl nox_float2int8(float a1) { return (int)a1; }

//----- (00419AF0) --------------------------------------------------------
float __cdecl nox_double2float(double a1) { return (float)a1; }

//----- (00419B10) --------------------------------------------------------
int __cdecl nox_double2int(double a1) { return (int)a1; }

//----- (00419B30) --------------------------------------------------------
int sub_419B30() {
	int result;     // eax
	FILE* v1;       // edi
	int v2;         // ebx
	char* v3;       // eax
	int* v4;        // esi
	_DWORD* v5;     // eax
	_DWORD* v6;     // esi
	int i;          // eax
	char v8[256];   // [esp+Ch] [ebp-87Ch]
	char v9[256];   // [esp+4Ch] [ebp-83Ch]
	int v10[255];   // [esp+8Ch] [ebp-7FCh]
	char v11[1024]; // [esp+488h] [ebp-400h]

	result = sub_426590();
	dword_5d4594_527684 = result;
	if (result) {
		result = sub_408CC0_fopen((char*)getMemAt(0x587000, 55748), 0);
		v1 = (FILE*)result;
		if (result) {
			result = sub_408D40(result, 8);
			if (result) {
				while (1) {
					if (!sub_409470(v1, v8)) {
					LABEL_25:
						sub_408D90(v1);
						return 1;
					}
					if (v8[0] == 35)
						goto LABEL_5;
					if (nox_common_gameFlags_check_40A5C0(2048) || nox_common_gameFlags_check_40A5C0(0x200000)) {
						if (!_strcmpi("ARENA", v8))
							goto LABEL_5;
						if (!_strcmpi("SOLO", v8))
							continue;
					}
					if (!nox_common_gameFlags_check_40A5C0(0x2000))
						goto LABEL_15;
					if (_strcmpi("SOLO", v8)) {
						if (_strcmpi("ARENA", v8)) {
						LABEL_15:
							if (sub_409470(v1, v9) == -1)
								goto LABEL_25;
							sub_4093E0(v1, v11, 1024);
							v2 = 0;
							v3 = strtok(v11, " ,\r\n\t");
							if (v3) {
								v4 = v10;
								do {
									*(float*)v4 = atof(v3);
									++v2;
									++v4;
									if (v2 == 255)
										break;
									v3 = strtok(0, " ,\r\n\t");
								} while (v3);
							}
							v5 = malloc(8u);
							v6 = v5;
							if (!v5)
								goto LABEL_28;
							*((_BYTE*)v5 + 4) = v2;
							*v5 = malloc(4 * v2);
							for (i = 0; i < v2; ++i)
								*(_DWORD*)(*v6 + 4 * i) = v10[i];
							if (!sub_4267B0(*(int*)&dword_5d4594_527684, v8, (int)v6)) {
							LABEL_28:
								fclose(v1);
								return 0;
							}
						}
					} else {
					LABEL_5:
						sub_409520(v1);
					}
				}
			}
		}
	}
	return result;
}
// 419B30: using guessed type int var_7FC[255];

//----- (00419D40) --------------------------------------------------------
double __cdecl sub_419D40(void* a1) {
	float** v1;    // eax
	double result; // st7

	v1 = (float**)sub_426890(*(int*)&dword_5d4594_527684, a1);
	if (v1)
		result = **v1;
	else
		result = 0.0;
	return result;
}

//----- (00419D70) --------------------------------------------------------
double __cdecl sub_419D70(void* a1, int a2) {
	int v2;        // eax
	double result; // st7

	v2 = sub_426890(*(int*)&dword_5d4594_527684, a1);
	if (v2 && a2 < *(unsigned __int8*)(v2 + 4))
		result = *(float*)(*(_DWORD*)v2 + 4 * a2);
	else
		result = 0.0;
	return result;
}

//----- (00419DB0) --------------------------------------------------------
void sub_419DB0() {
	if (dword_5d4594_527684) {
		sub_426600(*(int*)&dword_5d4594_527684, sub_419DE0);
		sub_4265A0(*(LPVOID*)&dword_5d4594_527684);
		dword_5d4594_527684 = 0;
	}
}

//----- (00419DE0) --------------------------------------------------------
void __cdecl sub_419DE0(int a1, LPVOID* lpMem) {
	free(*lpMem);
	free(lpMem);
}

//----- (00419E00) --------------------------------------------------------
void sub_419E00() { nox_srand(0x9CEu); }

//----- (00419E10) --------------------------------------------------------
int __cdecl sub_419E10(int a1, int a2) {
	int result; // eax

	result = a1;
	if (a1 && !(*(_BYTE*)(a1 + 16) & 0x20)) {
		result = 1 << *(_BYTE*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276) + 2064);
		if (a2) {
			dword_5d4594_527712 |= result;
		} else {
			result = ~result;
			dword_5d4594_527712 &= result;
		}
	}
	return result;
}

//----- (00419E60) --------------------------------------------------------
BOOL __cdecl sub_419E60(int a1) {
	BOOL result; // eax

	if (a1 && *(_BYTE*)(a1 + 8) & 4)
		result = (dword_5d4594_527712 & (1 << *(_BYTE*)(*(_DWORD*)(*(_DWORD*)(a1 + 748) + 276) + 2064))) != 0;
	else
		result = 0;
	return result;
}

//----- (00419EA0) --------------------------------------------------------
BOOL sub_419EA0() { return dword_5d4594_527712 != 0; }

//----- (00419EB0) --------------------------------------------------------
int __cdecl sub_419EB0(char a1, int a2) {
	int result; // eax

	result = 1 << a1;
	if (a2 == 1) {
		*getMemU32Ptr(0x5D4594, 527716) |= result;
	} else {
		result = ~result;
		*getMemU32Ptr(0x5D4594, 527716) &= result;
	}
	return result;
}

//----- (00419EE0) --------------------------------------------------------
BOOL __cdecl sub_419EE0(char a1) { return (*getMemU32Ptr(0x5D4594, 527716) & (1 << a1)) != 0; }

//----- (00419F00) --------------------------------------------------------
BOOL sub_419F00() { return *getMemU32Ptr(0x5D4594, 527716) != 0; }

//----- (00419F10) --------------------------------------------------------
int __cdecl sub_419F10(const char* a1, const char* a2) {
	unsigned __int8 v2; // al
	char* v3;           // edi
	char* v4;           // eax
	int result;         // eax
	char v6[1024];      // [esp+8h] [ebp-400h]

	strcpy(v6, a1);
	if (!strchr(v6, 46)) {
		v2 = getMemByte(0x587000, 56164);
		v3 = &v6[strlen(v6)];
		*(_DWORD*)v3 = *getMemU32Ptr(0x587000, 56160);
		v3[4] = v2;
	}
	v4 = nox_common_get_data_path_409E10();
	nox_sprintf((char*)getMemAt(0x5D4594, 2660688), "%s\\Save\\%s", v4, v6);
	strcpy((char*)getMemAt(0x5D4594, 2661712), a2);
	GetLocalTime((LPSYSTEMTIME)getMemAt(0x5D4594, 2661872));
	result = nox_common_gameFlags_check_40A5C0(0x2000);
	if (result) {
		result = *getMemU32Ptr(0x5D4594, 2660684);
		LOBYTE(result) = getMemByte(0x5D4594, 2660684) & 0xFE | 2;
		*getMemU32Ptr(0x5D4594, 2660684) = result;
	} else {
		*getMemU32Ptr(0x5D4594, 2660684) = *getMemU32Ptr(0x5D4594, 2660684) & 0xFFFFFFFD | 1;
	}
	return result;
}
// 419F10: using guessed type char var_400[1024];

//----- (0041A000) --------------------------------------------------------
int __cdecl sub_41A000(char* a1, nox_savegame_xxx* sv) {
	int result;          // eax
	int v3;              // ecx
	unsigned __int8* v4; // eax
	int v5;              // edx
	unsigned int v6;     // ecx
	char v7;             // al
	_BYTE* v8;           // edi
	char* v9;            // esi
	int v10;             // [esp+10h] [ebp-508h]
	int v11;             // [esp+14h] [ebp-504h]
	char v12[1276];      // [esp+18h] [ebp-500h]
	__int16 v13;         // [esp+514h] [ebp-4h]

	sv->field_1028[0] = getMemByte(0x5D4594, 527728);
	result = sub_426910(a1, 1, 27);
	if (!result) {
		return 0;
	}
	while (1) {
		sub_426AC0_file3_fread(&v10, 4u);
		if (!v10)
			break;
		sub_426C20(&v11, 4u);
		if (v10 == 1) {
			memcpy(v12, getMemAt(0x5D4594, 2660684), sizeof(v12));
			v3 = 0;
			v13 = *getMemU16Ptr(0x5D4594, 2661960);
			if (*getMemU32Ptr(0x587000, 55936)) {
				v4 = getMemAt(0x587000, 55936);
				while (v4 != getMemAt(0x587000, 55948)) {
					v5 = *((_DWORD*)v4 + 3);
					v4 += 12;
					++v3;
					if (!v5)
						goto LABEL_10;
				}
				if (!(*(int(__cdecl**)(_DWORD)) getMemAt(0x587000, 55956))(0)) {
					sub_4269F0();
					return 0;
				}
			}
			LABEL_10:
			memcpy(sv, getMemAt(0x5D4594, 2660684), sizeof(nox_savegame_xxx));
			memcpy(getMemAt(0x5D4594, 2660684), v12, 0x4FCu);
			*getMemU16Ptr(0x5D4594, 2661960) = v13;
		} else {
			sub_426AA0(v11);
		}
	}
	sub_4269F0();
	v6 = strlen(a1) + 1;
	v7 = v6;
	v6 >>= 2;
	memcpy(&sv->field_4, a1, 4 * v6);
	v9 = &a1[4 * v6];
	v8 = &sv->field_4[4 * v6];
	LOBYTE(v6) = v7;
	memcpy(v8, v9, v6 & 3);
	return 1;
}

//----- (0041A140) --------------------------------------------------------
int __cdecl sub_41A140(char* a1, int a2) {
	int result;          // eax
	int v3;              // ebp
	int v4;              // ebx
	unsigned __int8* v5; // esi
	int v7;              // edi
	int v9;              // eax
	int v10;             // [esp+18h] [ebp+8h]

	result = nox_common_playerInfoGetXXX_417090(a2);
	if (result) {
		v3 = *(_DWORD*)(result + 2056);
		if (v3) {
			v4 = result + 2185;
			if (sub_426910(a1, 0, 27)) {
				v10 = 0;
				if (*getMemU32Ptr(0x587000, 55816)) {
					v5 = getMemAt(0x587000, 55824);
					while (1) {
						sub_426AC0_file3_fread(v5 - 4, 4u);
						sub_426C90();
						v7 = (*(int(__cdecl**)(int, int, _DWORD, _DWORD))v5)(v3, v4, 0, 0);
						sub_426D40();
						if (!v7)
							break;
						v9 = *((_DWORD*)v5 + 1);
						v5 += 12;
						++v10;
						if (!v9)
							goto LABEL_10;
					}
					sub_413D30((char*)getMemAt(0x587000, 56264), *getMemU32Ptr(0x587000, 12 * v10 + 55816));
					sub_4269F0();
					result = 0;
				} else {
				LABEL_10:
					sub_4269F0();
					result = 1;
				}
			} else {
				sub_413D30((char*)getMemAt(0x587000, 56224), a1);
				result = 0;
			}
		} else {
			sub_413D30((char*)getMemAt(0x587000, 56180));
			result = 0;
		}
	}
	return result;
}
// 41A1C9: variable 'v6' is possibly undefined
// 41A1DB: variable 'v8' is possibly undefined

//----- (0041A230) --------------------------------------------------------
int __cdecl sub_41A230(char* a1) {
	char* v1;            // edi
	int result;          // eax
	unsigned __int8* v3; // esi
	int v5;              // edi
	int v7;              // eax

	v1 = a1;
	result = sub_426910(a1, 2, 27);
	if (result) {
		if (sub_45D9B0())
			sub_45D870();
		if ((char*)getMemAt(0x5D4594, 2660688) != v1) { // FIXME: strcpy overlap
			strcpy((char*)getMemAt(0x5D4594, 2660688), v1);
		}
		if (*getMemU32Ptr(0x587000, 55936)) {
			v3 = getMemAt(0x587000, 55944);
			while (1) {
				sub_426AC0_file3_fread(v3 - 4, 4u);
				sub_426C90();
				v5 = (*(int(__cdecl**)(_DWORD))v3)(0);
				sub_426D40();
				if (!v5)
					break;
				v7 = *((_DWORD*)v3 + 1);
				v3 += 12;
				if (!v7)
					goto LABEL_8;
			}
			sub_4269F0();
			result = 0;
		} else {
		LABEL_8:
			a1 = 0;
			sub_426AC0_file3_fread(&a1, 4u);
			sub_4269F0();
			result = 1;
		}
	}
	return result;
}
// 41A291: variable 'v4' is possibly undefined
// 41A29F: variable 'v6' is possibly undefined

//----- (0041A2E0) --------------------------------------------------------
char* __cdecl sub_41A2E0(char* a1, int a2) {
	char* result;         // eax
	int v3;               // esi
	char* v4;             // edi
	int v5;               // ecx
	unsigned __int8* v6;  // eax
	int v7;               // ebx
	int v8;               // eax
	int v9;               // edi
	unsigned __int16 v10; // ax
	unsigned __int16 v11; // ax

	result = nox_common_playerInfoGetXXX_417090(a2);
	if (result) {
		v3 = *((_DWORD*)result + 514);
		if (v3) {
			v4 = result + 2185;
			result = (char*)sub_426910(a1, 1, 27);
			if (result) {
				if (nox_common_gameFlags_check_40A5C0(2048)) {
					sub_4EF500(0);
					nullsub_26(0);
				}
				*getMemU16Ptr(0x5D4594, 527696) = sub_4EE780(v3);
				*getMemU32Ptr(0x5D4594, 527696) = *getMemU16Ptr(0x5D4594, 527696);
				*getMemU16Ptr(0x5D4594, 527700) = sub_4EEC80(v3);
				*getMemU32Ptr(0x5D4594, 527700) = *getMemU16Ptr(0x5D4594, 527700);
				sub_4EFF10(v3);
				sub_419E10(v3, 1);
				do {
					while (1) {
						sub_426AC0_file3_fread(&a2, 4u);
						if (!a2) {
							sub_4269F0();
							sub_4EF140(v3);
							v10 = sub_4EE7A0(v3);
							sub_4EE5E0(v3, v10 - *getMemU32Ptr(0x5D4594, 527696));
							v11 = sub_4EECB0(v3);
							sub_4EEBF0(v3, v11 - *getMemU32Ptr(0x5D4594, 527700));
							sub_4EE730(v3);
							sub_419E10(v3, 0);
							return (char*)1;
						}
						sub_426C20(&a1, 4u);
						v5 = 0;
						if (*getMemU32Ptr(0x587000, 55816))
							break;
					LABEL_13:
						sub_426AA0((int)a1);
					}
					v6 = getMemAt(0x587000, 55816);
					while (a2 != *((_DWORD*)v6 + 1)) {
						v7 = *((_DWORD*)v6 + 3);
						v6 += 12;
						++v5;
						if (!v7)
							goto LABEL_13;
					}
				} while ((*(int(__cdecl**)(int, int)) getMemAt(0x587000, 12 * v5 + 55824))(v3, (int)v4));
				v8 = *(_DWORD*)(v3 + 504);
				if (v8) {
					do {
						v9 = *(_DWORD*)(v8 + 496);
						sub_4E5CC0(v8);
						v8 = v9;
					} while (v9);
				}
				sub_419E10(v3, 0);
				sub_4269F0();
				result = 0;
			}
		} else {
			result = 0;
		}
	}
	return result;
}
// 4EF4F0: using guessed type void __cdecl nullsub_26(_DWORD);

//----- (0041A480) --------------------------------------------------------
int __cdecl sub_41A480(char* a1) {
	int result;          // eax
	int v2;              // ecx
	unsigned __int8* v3; // eax
	int v4;              // esi
	int v5;              // [esp+Ch] [ebp-408h]
	int v6;              // [esp+10h] [ebp-404h]
	char v7[1024];       // [esp+14h] [ebp-400h]

	strcpy(v7, a1);
	result = sub_426910(a1, 1, 27);
	if (result) {
		sub_4602F0();
		while (1) {
			sub_426AC0_file3_fread(&v5, 4u);
			if (!v5)
				break;
			sub_426C20(&v6, 4u);
			v2 = 0;
			if (*getMemU32Ptr(0x587000, 55936)) {
				v3 = getMemAt(0x587000, 55936);
				while (v5 != *((_DWORD*)v3 + 1)) {
					v4 = *((_DWORD*)v3 + 3);
					v3 += 12;
					++v2;
					if (!v4)
						goto LABEL_8;
				}
				if (!(*(int(__cdecl**)(void*)) getMemAt(0x587000, 12 * v2 + 55944))(0)) {
					sub_4269F0();
					return 0;
				}
			} else {
			LABEL_8:
				sub_426AA0(v6);
			}
		}
		sub_4269F0();
		result = 1;
		strcpy((char*)getMemAt(0x5D4594, 2660688), v7);
	}
	return result;
}

//----- (0041A590) --------------------------------------------------------
int __cdecl sub_41A590(int a1, int a2) {
	int v2;    // esi
	int v3;    // edi
	int v4;    // ebx
	size_t v6; // eax
	int v7;    // eax
	int v8;    // ebx
	char* v9;  // eax
	int v10;   // eax
	int v11;   // esi
	float v12; // [esp+0h] [ebp-20h]
	int v13;   // [esp+14h] [ebp-Ch]
	int v14;   // [esp+18h] [ebp-8h]
	int v15;   // [esp+1Ch] [ebp-4h]

	v2 = a2;
	v3 = 0;
	v4 = 0;
	v15 = 0;
	if (!a2)
		return 0;
	if (a1) {
		v3 = *(_DWORD*)(a1 + 748);
		if (v3) {
			v15 = *(_DWORD*)(v3 + 276);
			v4 = v15;
		}
	}
	a2 = 5;
	sub_426AC0_file3_fread(&a2, 2u);
	if ((__int16)a2 > 5)
		return 0;
	if ((__int16)a2 >= 5) {
		v13 = nox_common_gameFlags_check_40A5C0(4096) ? 4 : 2 - nox_common_gameFlags_check_40A5C0(2048);
		sub_426AC0_file3_fread(&v13, 4u);
		if (v4) {
			if (*(_BYTE*)(v4 + 2064) != 31) {
				if (nox_common_gameFlags_check_40A5C0(4096)) {
					if (v13 != 4) {
						sub_4DEAB0(*(unsigned __int8*)(v4 + 2064), 1);
						return 0;
					}
				} else if (v13 != 4) {
					goto LABEL_20;
				}
				if (!nox_common_gameFlags_check_40A5C0(4096)) {
					sub_4DEAB0(*(unsigned __int8*)(v4 + 2064), 1);
					return 0;
				}
			}
		}
	}
LABEL_20:
	LOBYTE(v14) = nox_wcslen((const wchar_t*)v2);
	sub_426AC0_file3_fread(&v14, 1u);
	if ((unsigned __int8)v14 >= 0x19u)
		return 0;
	sub_426AC0_file3_fread((_BYTE*)v2, 2 * (unsigned __int8)v14);
	*(_WORD*)(v2 + 2 * (unsigned __int8)v14) = 0;
	if (v3)
		nox_wcscpy((wchar_t*)(*(_DWORD*)(v3 + 276) + 4704), (const wchar_t*)v2);
	if (*getMemU32Ptr(0x5D4594, 3803300) == 1 && v3) {
		v6 = nox_wcslen((const wchar_t*)v2);
		v7 = sub_56FAE0((int*)v2, 2 * v6);
		sub_56F7D0(*(_DWORD*)(*(_DWORD*)(v3 + 276) + 4628), v7);
	}
	sub_426AC0_file3_fread((_BYTE*)(v2 + 50), 4u);
	sub_426AC0_file3_fread((_BYTE*)(v2 + 54), 4u);
	if (*getMemU32Ptr(0x5D4594, 3803300) == 1 && v3) {
		sub_56F780(*(_DWORD*)(*(_DWORD*)(v3 + 276) + 4624), *(_DWORD*)(v2 + 54));
		sub_56F780(*(_DWORD*)(*(_DWORD*)(v3 + 276) + 4620), *(_DWORD*)(v2 + 50));
	}
	sub_426AC0_file3_fread((_BYTE*)(v2 + 58), 4u);
	sub_426AC0_file3_fread((_BYTE*)(v2 + 62), 4u);
	sub_426AC0_file3_fread((_BYTE*)(v2 + 66), 1u);
	if (*getMemU32Ptr(0x5D4594, 3803300) == 1 && v3)
		sub_56F820(*(_DWORD*)(*(_DWORD*)(v3 + 276) + 4616), *(_BYTE*)(v2 + 66));
	sub_426AC0_file3_fread((_BYTE*)(v2 + 67), 1u);
	sub_426AC0_file3_fread((_BYTE*)(v2 + 68), 3u);
	sub_426AC0_file3_fread((_BYTE*)(v2 + 71), 3u);
	sub_426AC0_file3_fread((_BYTE*)(v2 + 74), 3u);
	sub_426AC0_file3_fread((_BYTE*)(v2 + 77), 3u);
	sub_426AC0_file3_fread((_BYTE*)(v2 + 80), 3u);
	if ((__int16)a2 >= 2) {
		sub_426AC0_file3_fread((_BYTE*)(v2 + 83), 1u);
		sub_426AC0_file3_fread((_BYTE*)(v2 + 84), 1u);
		sub_426AC0_file3_fread((_BYTE*)(v2 + 85), 1u);
		sub_426AC0_file3_fread((_BYTE*)(v2 + 86), 1u);
		sub_426AC0_file3_fread((_BYTE*)(v2 + 87), 1u);
	}
	v8 = a1;
	if (*getMemU32Ptr(0x5D4594, 3803300) == 1) {
		if (a1) {
			v9 = nox_common_playerInfoGetByID_417040(*(_DWORD*)(a1 + 36));
			if (v9)
				sub_461460((int)v9);
		}
	}
	sub_426AC0_file3_fread((_BYTE*)(v2 + 88), 1u);
	if ((__int16)a2 >= 3) {
		v13 = 0;
		if (v3)
			v13 = *(_DWORD*)(v3 + 320);
		sub_426AC0_file3_fread(&v13, 4u);
		if (*getMemU32Ptr(0x5D4594, 3803300) == 1 && v3)
			*(_DWORD*)(v3 + 320) = v13;
		v12 = sub_419D40(getMemAt(0x587000, 56312));
		v10 = nox_float2int(v12);
		if (v3 && *(_DWORD*)(v3 + 320) > v10)
			return 0;
		if ((_WORD)a2 == 3) {
			sub_426AC0_file3_fread(&a1, 4u);
			sub_426AC0_file3_fread(&a1, 4u);
			sub_426AC0_file3_fread(&a1, 4u);
			sub_426AC0_file3_fread(&a1, 4u);
			sub_426AC0_file3_fread(&a1, 4u);
			sub_426AC0_file3_fread(&a1, 4u);
			sub_426AC0_file3_fread(&a1, 4u);
			sub_426AC0_file3_fread(&a1, 4u);
			sub_426AC0_file3_fread(&a1, 4u);
		}
	}
	if (*getMemU32Ptr(0x5D4594, 3803300) == 1)
		sub_4D6000(v8);
	if ((__int16)a2 >= 4) {
		v11 = v15;
		a1 = 0;
		if (v15)
			a1 = *(_DWORD*)(v15 + 4696);
		sub_426AC0_file3_fread(&a1, 4u);
		if (*getMemU32Ptr(0x5D4594, 3803300) == 1) {
			if (!v11 || (*(_DWORD*)(v11 + 4696) = a1, *getMemU32Ptr(0x5D4594, 3803300) == 1)) {
				if (v3)
					sub_4D7450(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064),
							   *(_DWORD*)(*(_DWORD*)(v3 + 276) + 4696));
			}
		}
	}
	return 1;
}

//----- (0041AA30) --------------------------------------------------------
char* __cdecl sub_41AA30(int a1) {
	int v1;       // esi
	int v2;       // ebp
	char* result; // eax
	int v4;       // eax
	int v5;       // eax
	int v6;       // [esp+10h] [ebp-Ch]
	int v7;       // [esp+14h] [ebp-8h]
	int v8;       // [esp+18h] [ebp-4h]

	v1 = a1;
	v2 = *(_DWORD*)(a1 + 748);
	result = nox_common_playerInfoGetByID_417040(*(_DWORD*)(a1 + 36));
	LOBYTE(a1) = 1;
	if (result) {
		v7 = 2;
		sub_426AC0_file3_fread(&v7, 2u);
		if ((__int16)v7 > 2)
			return 0;
		if (!nox_common_gameFlags_check_40A5C0(2048))
			LOBYTE(a1) = 0;
		sub_426AC0_file3_fread(&a1, 1u);
		if ((_BYTE)a1) {
			result = (char*)nox_common_gameFlags_check_40A5C0(2048);
			if (!result)
				return result;
			LOWORD(v4) = sub_4EE7A0(v1);
			v6 = v4;
			sub_426AC0_file3_fread(&v6, 2u);
			if (*getMemU32Ptr(0x5D4594, 3803300) == 1) {
				sub_4EE7C0(v1, v6);
				sub_4E4560(v1, v6);
			}
			LOWORD(v5) = sub_4EECB0(v1);
			v6 = v5;
			sub_426AC0_file3_fread(&v6, 2u);
			if (*getMemU32Ptr(0x5D4594, 3803300) == 1) {
				sub_4EECD0(v1, v6);
				sub_4EECF0(v1);
			}
			*getMemU32Ptr(0x5D4594, 527696) = **(unsigned __int16**)(v1 + 556);
			sub_426AC0_file3_fread(getMemAt(0x5D4594, 527696), 2u);
			*getMemU32Ptr(0x5D4594, 527700) = *(unsigned __int16*)(v2 + 4);
			sub_426AC0_file3_fread(getMemAt(0x5D4594, 527700), 2u);
			LOBYTE(v8) = *(_BYTE*)(v1 + 540);
			sub_426AC0_file3_fread(&v8, 1u);
			if (*getMemU32Ptr(0x5D4594, 3803300) == 1)
				sub_4EEA90(v1, (unsigned __int8)v8);
			sub_426AC0_file3_fread((_BYTE*)(v1 + 541), 1u);
			sub_426AC0_file3_fread((_BYTE*)(v1 + 542), 2u);
			sub_426AC0_file3_fread((_BYTE*)(v1 + 28), 4u);
			if (*getMemU32Ptr(0x5D4594, 3803300) == 1) {
				sub_56F8C0(*(_DWORD*)(*(_DWORD*)(v2 + 276) + 4604), *(float*)(v1 + 28));
				sub_4D81A0(v1);
			}
			if ((__int16)v7 >= 2) {
				sub_426AC0_file3_fread((_BYTE*)(v1 + 124), 2u);
				if (*getMemU32Ptr(0x5D4594, 3803300) == 1)
					*(_WORD*)(v1 + 126) = *(_WORD*)(v1 + 124);
			}
		}
		result = (char*)1;
	}
	return result;
}
// 41AAD8: variable 'v4' is possibly undefined
// 41AB12: variable 'v5' is possibly undefined

//----- (0041AC30) --------------------------------------------------------
BOOL __cdecl sub_41AC30(_DWORD* a1) {
	_DWORD* v1;    // ebp
	BOOL result;   // eax
	int v3;        // eax
	int v4;        // esi
	int v5;        // edi
	int v6;        // edi
	int v7;        // esi
	int v8;        // ebp
	char* v9;      // eax
	int v10;       // ebx
	int* v11;      // ebp
	int v12;       // eax
	int v13;       // esi
	_BYTE* v14;    // eax
	int v15;       // esi
	_BYTE* v16;    // eax
	int v17;       // eax
	int m;         // esi
	int v19;       // eax
	int v20;       // eax
	int v21;       // eax
	int v22;       // esi
	int v23;       // ebx
	_DWORD* v24;   // eax
	_DWORD* v25;   // esi
	int v26;       // eax
	int v27;       // edi
	int i;         // esi
	_DWORD* v29;   // eax
	_DWORD* v30;   // eax
	_DWORD* j;     // eax
	_BYTE* v32;    // esi
	size_t v33;    // [esp-4h] [ebp-13Ch]
	size_t v34;    // [esp-4h] [ebp-13Ch]
	char l;        // [esp+12h] [ebp-126h]
	char v36;      // [esp+13h] [ebp-125h]
	int v37;       // [esp+14h] [ebp-124h]
	int k;         // [esp+18h] [ebp-120h]
	int v39;       // [esp+1Ch] [ebp-11Ch]
	int v40;       // [esp+20h] [ebp-118h]
	int v41;       // [esp+24h] [ebp-114h]
	int v42;       // [esp+28h] [ebp-110h]
	int v43;       // [esp+2Ch] [ebp-10Ch]
	int v44;       // [esp+30h] [ebp-108h]
	int v45;       // [esp+34h] [ebp-104h]
	char v46[256]; // [esp+38h] [ebp-100h]

	v1 = a1;
	v36 = 1;
	v40 = a1[187];
	if (!*getMemU32Ptr(0x5D4594, 527704))
		*getMemU32Ptr(0x5D4594, 527704) = sub_4E3AA0((CHAR*)getMemAt(0x587000, 56328));
	if (*getMemU32Ptr(0x5D4594, 3803300) == 1)
		sub_4EF140((int)a1);
	v42 = 3;
	sub_426AC0_file3_fread(&v42, 2u);
	if ((__int16)v42 > 3)
		return 0;
	if (nox_common_gameFlags_check_40A5C0(0x2000) && !nox_common_gameFlags_check_40A5C0(4096))
		v36 = 0;
	sub_426AC0_file3_fread(&v36, 1u);
	if (!v36)
		goto LABEL_115;
	if (!nox_common_gameFlags_check_40A5C0(2048)) {
		result = nox_common_gameFlags_check_40A5C0(4096);
		if (!result)
			return result;
	}
	v44 = *(_DWORD*)(*(_DWORD*)(v40 + 276) + 2164);
	sub_426AC0_file3_fread(&v44, 4u);
	if (*getMemU32Ptr(0x5D4594, 3803300) == 1) {
		v3 = sub_4FA6B0((int)a1);
		sub_4FA5D0((int)a1, v3);
		sub_4FA590((int)a1, v44);
	}
	if (*getMemU32Ptr(0x5D4594, 3803300)) {
		v21 = a1[126];
		if (v21) {
			do {
				v22 = *(_DWORD*)(v21 + 496);
				sub_4E5CC0(v21);
				v21 = v22;
			} while (v22);
		}
		sub_426AC0_file3_fread(&k, 4u);
		if (nox_common_gameFlags_check_40A5C0(4096) && k > 2560)
			return 0;
		v23 = 0;
		if (k > 0) {
			do {
				sub_426AC0_file3_fread(&v39, 1u);
				sub_426AC0_file3_fread(v46, (unsigned __int8)v39);
				v46[(unsigned __int8)v39] = 0;
				v24 = sub_4E3810(v46);
				v25 = v24;
				if (!v24)
					return 0;
				if (!((int(__cdecl*)(_DWORD*, _DWORD))v24[176])(v24, 0))
					return 0;
				v25[14] = 1161297920;
				v25[15] = 1161297920;
				if (nox_common_gameFlags_check_40A5C0(4096)) {
					if (!sub_4F2590((int)v25))
						return 0;
				}
				sub_4F3F50((int)v25, (int)a1, 0);
				sub_4DAC00();
				if (!sub_4F36F0((int)a1, (int)v25, 1, 1)) {
					if (!nox_common_gameFlags_check_40A5C0(4096))
						return 0;
					sub_4E5CC0((int)v25);
				}
				v26 = v25[4];
				if (!(v26 & 0x20) && v26 & 0x100)
					sub_4F2FB0(a1, (int)v25);
			} while (++v23 < k);
		}
		sub_426AC0_file3_fread(&v41, 1u);
		v27 = 0;
		if ((_BYTE)v41) {
			do {
				sub_426AC0_file3_fread(&v37, 4u);
				for (i = a1[126]; i; i = *(_DWORD*)(i + 496)) {
					if (*(_DWORD*)(i + 44) == v37)
						sub_4F2F70(a1, i);
				}
				++v27;
			} while (v27 < (unsigned __int8)v41);
		}
		if (nox_common_gameFlags_check_40A5C0(2048)) {
			sub_467750(0, 0);
			sub_467740(0);
		}
		sub_426AC0_file3_fread(&v37, 4u);
		if (v37) {
			v29 = (_DWORD*)a1[126];
			if (v29) {
				while (v29[11] != v37) {
					v29 = (_DWORD*)v29[124];
					if (!v29)
						goto LABEL_99;
				}
				sub_4D9670(*(unsigned __int8*)(*(_DWORD*)(v40 + 276) + 2064), v29, 0);
			}
		}
	LABEL_99:
		if ((__int16)v42 >= 2) {
			sub_426AC0_file3_fread(&v37, 4u);
			if (v37) {
				v30 = (_DWORD*)a1[126];
				if (v30) {
					while (v30[11] != v37) {
						v30 = (_DWORD*)v30[124];
						if (!v30)
							goto LABEL_106;
					}
					sub_4D96B0(*(unsigned __int8*)(*(_DWORD*)(v40 + 276) + 2064), v30);
				}
			}
		}
	LABEL_106:
		if (nox_common_gameFlags_check_40A5C0(4096)) {
			for (j = (_DWORD*)sub_4E7980((int)a1); j; j = (_DWORD*)sub_4E7990((int)j)) {
				j[11] = (*getMemU32Ptr(0x587000, 201376))++;
				j[10] = j[9];
			}
		}
		goto LABEL_109;
	}
	v4 = a1[126];
	v5 = 0;
	for (k = 0; v4; v4 = *(_DWORD*)(v4 + 496)) {
		if (!nox_common_gameFlags_check_40A5C0(4096) || sub_41B3E0(v4))
			++k;
	}
	sub_426AC0_file3_fread(&k, 4u);
	if (nox_common_gameFlags_check_40A5C0(2048))
		v5 = sub_41B3B0();
	if (k != v5 || !nox_common_gameFlags_check_40A5C0(2048)) {
		v15 = a1[126];
		if (v15) {
			while (1) {
				if (!nox_common_gameFlags_check_40A5C0(4096) || sub_41B3E0(v15)) {
					LOBYTE(v39) = strlen((const char*)sub_4E39D0(v15));
					sub_426AC0_file3_fread(&v39, 1u);
					v34 = (unsigned __int8)v39;
					v16 = (_BYTE*)sub_4E39D0(v15);
					sub_426AC0_file3_fread(v16, v34);
					if (!(*(int(__cdecl**)(int, _DWORD))(v15 + 704))(v15, 0))
						return 0;
				}
				v15 = *(_DWORD*)(v15 + 496);
				if (!v15)
					goto LABEL_42;
			}
		}
	} else {
		v6 = 0;
		v41 = 0;
		while (2) {
			v7 = 0;
			v43 = 0;
			do {
				v8 = sub_467810(v7, v6);
				v45 = v8;
				if (v8) {
					v9 = sub_467870(v7, v6);
					v10 = 0;
					if (v8 > 0) {
						v11 = (int*)v9;
						while (1) {
							v12 = sub_4F7920((int)a1, *v11);
							v13 = v12;
							if (!v12)
								return 0;
							LOBYTE(v39) = strlen((const char*)sub_4E39D0(v12));
							sub_426AC0_file3_fread(&v39, 1u);
							v33 = (unsigned __int8)v39;
							v14 = (_BYTE*)sub_4E39D0(v13);
							sub_426AC0_file3_fread(v14, v33);
							if (!(*(int(__cdecl**)(int, _DWORD))(v13 + 704))(v13, 0))
								return 0;
							++v10;
							++v11;
							if (v10 >= v45) {
								v6 = v41;
								v7 = v43;
								break;
							}
						}
					}
				}
				v43 = ++v7;
			} while (v7 < 4);
			v41 = ++v6;
			if (v6 < 20)
				continue;
			break;
		}
	LABEL_42:
		v1 = a1;
	}
	v17 = v1[126];
	for (l = 0; v17; v17 = *(_DWORD*)(v17 + 496)) {
		if (*(_DWORD*)(v17 + 16) & 0x100)
			++l;
	}
	sub_426AC0_file3_fread(&l, 1u);
	for (m = v1[126]; m; m = *(_DWORD*)(m + 496)) {
		if (*(_DWORD*)(m + 16) & 0x100)
			sub_426AC0_file3_fread((_BYTE*)(m + 44), 4u);
	}
	v19 = sub_4678B0();
	v37 = v19;
	if (!v19) {
	LABEL_57:
		if (m)
			goto LABEL_59;
		goto LABEL_58;
	}
	m = v1[126];
	if (m) {
		while (*(_DWORD*)(m + 36) != v19) {
			m = *(_DWORD*)(m + 496);
			if (!m)
				goto LABEL_58;
		}
		v37 = *(_DWORD*)(m + 44);
		goto LABEL_57;
	}
LABEL_58:
	v37 = 0;
LABEL_59:
	sub_426AC0_file3_fread(&v37, 4u);
	v20 = sub_4678C0();
	v37 = v20;
	if (v20) {
		m = v1[126];
		if (!m) {
		LABEL_66:
			v37 = 0;
			goto LABEL_67;
		}
		while (*(_DWORD*)(m + 36) != v20) {
			m = *(_DWORD*)(m + 496);
			if (!m)
				goto LABEL_66;
		}
		v37 = *(_DWORD*)(m + 44);
	}
	if (!m)
		goto LABEL_66;
LABEL_67:
	sub_426AC0_file3_fread(&v37, 4u);
LABEL_109:
	v32 = (_BYTE*)(v40 + 244);
	if ((__int16)v42 < 3)
		*(_BYTE*)(v40 + 244) = 0;
	else
		sub_426AC0_file3_fread((_BYTE*)(v40 + 244), 1u);
	if (*getMemU32Ptr(0x5D4594, 3803300) == 1 && nox_common_gameFlags_check_40A5C0(4096))
		*v32 = 0;
LABEL_115:
	if (nox_common_gameFlags_check_40A5C0(4096) && !sub_4F2C30((int)v1))
		return 0;
	sub_4D96E0(*(unsigned __int8*)(*(_DWORD*)(v40 + 276) + 2064));
	return 1;
}
// 41AC30: using guessed type char var_100[256];

//----- (0041B3B0) --------------------------------------------------------
int sub_41B3B0() {
	int v0; // ebx
	int i;  // edi
	int j;  // esi

	v0 = 0;
	for (i = 0; i < 20; ++i) {
		for (j = 0; j < 4; ++j)
			v0 += sub_467810(j, i);
	}
	return v0;
}

//----- (0041B3E0) --------------------------------------------------------
BOOL __cdecl sub_41B3E0(int a1) {
	int v1;      // eax
	BOOL result; // eax

	v1 = *getMemU32Ptr(0x5D4594, 527724);
	if (!*getMemU32Ptr(0x5D4594, 527724)) {
		v1 = sub_4E3AA0((CHAR*)getMemAt(0x587000, 56336));
		*getMemU32Ptr(0x5D4594, 527724) = v1;
	}
	if ((*(_BYTE*)(a1 + 8) & 0x40) == 64)
		result = 0;
	else
		result = *(unsigned __int16*)(a1 + 4) != v1;
	return result;
}

//----- (0041B420) --------------------------------------------------------
BOOL __cdecl sub_41B420(int a1) {
	char* v1;      // esi
	BOOL result;   // eax
	_DWORD* v3;    // ebp
	_DWORD* v4;    // eax
	int v5;        // ecx
	int i;         // esi
	char* v7;      // eax
	int v8;        // esi
	int v9;        // eax
	int v10;       // eax
	size_t v11;    // [esp-4h] [ebp-124h]
	char v12;      // [esp+13h] [ebp-10Dh]
	int v13;       // [esp+14h] [ebp-10Ch]
	int v14;       // [esp+18h] [ebp-108h]
	int v15;       // [esp+1Ch] [ebp-104h]
	char v16[256]; // [esp+20h] [ebp-100h]

	v1 = nox_common_playerInfoGetByID_417040(*(_DWORD*)(a1 + 36));
	v12 = 1;
	if (!v1)
		return 0;
	v15 = 1;
	sub_426AC0_file3_fread(&v15, 2u);
	if ((__int16)v15 > 1)
		return 0;
	if (nox_common_gameFlags_check_40A5C0(0x2000) && !nox_common_gameFlags_check_40A5C0(4096))
		v12 = 0;
	sub_426AC0_file3_fread(&v12, 1u);
	if (!v12)
		return 1;
	if (!nox_common_gameFlags_check_40A5C0(2048)) {
		result = nox_common_gameFlags_check_40A5C0(4096);
		if (!result)
			return result;
	}
	if (*getMemU32Ptr(0x5D4594, 3803300)) {
		sub_426AC0_file3_fread(&v13, 1u);
		if ((unsigned __int8)v13 > 0x29u)
			return 0;
		v8 = 0;
		if ((unsigned __int8)v13 > 0u) {
			while (1) {
				sub_426AC0_file3_fread(&v14, 1u);
				if ((int)(unsigned __int8)v14 >= 256)
					break;
				sub_426AC0_file3_fread(v16, (unsigned __int8)v14);
				v16[(unsigned __int8)v14] = 0;
				if (nox_common_gameFlags_check_40A5C0(4096)) {
					v9 = sub_427010(v16);
					if (!sub_4F2EF0(v9))
						break;
				}
				v10 = sub_427010(v16);
				sub_4FAE80_magic_plyrgide(a1, v10, 0);
				if (++v8 >= (unsigned __int8)v13)
					return 1;
			}
			return 0;
		}
		return 1;
	}
	v3 = v1 + 4248;
	LOBYTE(v13) = 0;
	v4 = v1 + 4248;
	v5 = 40;
	do {
		if (*v4)
			LOBYTE(v13) = v13 + 1;
		++v4;
		--v5;
	} while (v5);
	sub_426AC0_file3_fread(&v13, 1u);
	for (i = 1; i < 41; ++i) {
		if (*v3) {
			LOBYTE(v14) = strlen(sub_427230(i));
			sub_426AC0_file3_fread(&v14, 1u);
			v11 = (unsigned __int8)v14;
			v7 = sub_427230(i);
			sub_426AC0_file3_fread(v7, v11);
		}
		++v3;
	}
	return 1;
}
// 41B420: using guessed type char var_100[256];

//----- (0041B660) --------------------------------------------------------
int __cdecl sub_41B660(int a1) {
	int result;    // eax
	int v2;        // esi
	_BYTE* v3;     // ebp
	_DWORD* v4;    // eax
	int v5;        // ecx
	int v6;        // ecx
	char v7;       // al
	int v8;        // esi
	char* v9;      // eax
	char* v10;     // eax
	int v11;       // ebp
	bool v12;      // cc
	int v13;       // eax
	int v14;       // eax
	int v15;       // eax
	size_t v16;    // [esp-4h] [ebp-128h]
	size_t v17;    // [esp-4h] [ebp-128h]
	int v18;       // [esp-4h] [ebp-128h]
	char v19;      // [esp+13h] [ebp-111h]
	int v20;       // [esp+14h] [ebp-110h]
	int v21;       // [esp+18h] [ebp-10Ch]
	int v22;       // [esp+1Ch] [ebp-108h]
	int v23;       // [esp+20h] [ebp-104h]
	char v24[256]; // [esp+24h] [ebp-100h]

	result = nox_common_playerInfoGetByID_417040(*(_DWORD*)(a1 + 36));
	v2 = result;
	v19 = 1;
	if (!result)
		return result;
	v22 = 3;
	sub_426AC0_file3_fread(&v22, 2u);
	if ((__int16)v22 > 3)
		return 0;
	if (nox_common_gameFlags_check_40A5C0(0x2000) && !nox_common_gameFlags_check_40A5C0(4096))
		v19 = 0;
	sub_426AC0_file3_fread(&v19, 1u);
	if (!v19)
		return 1;
	if (!nox_common_gameFlags_check_40A5C0(2048)) {
		result = nox_common_gameFlags_check_40A5C0(4096);
		if (!result)
			return result;
	}
	if (*getMemU32Ptr(0x5D4594, 3803300)) {
		sub_426AC0_file3_fread(&v20, 1u);
		if ((unsigned __int8)v20 > 0x89u)
			return 0;
		v11 = 0;
		if ((_BYTE)v20) {
			while (1) {
				sub_426AC0_file3_fread(&v21, 1u);
				if ((int)(unsigned __int8)v21 >= 256)
					break;
				sub_426AC0_file3_fread(v24, (unsigned __int8)v21);
				v12 = (__int16)v22 < 2;
				v23 = 3;
				v24[(unsigned __int8)v21] = 0;
				if (!v12)
					sub_426AC0_file3_fread(&v23, 4u);
				if (nox_common_gameFlags_check_40A5C0(4096) && v23 > 3 && *(_BYTE*)(v2 + 2251))
					break;
				if (nox_common_gameFlags_check_40A5C0(4096)) {
					if (*(_BYTE*)(v2 + 2251)) {
						v13 = sub_4243F0(v24);
						if (!sub_4F2E70(v13))
							break;
					}
				}
				if ((__int16)v22 < 3 || *(_BYTE*)(v2 + 2251)) {
					v18 = v23;
					v15 = sub_4243F0(v24);
					sub_4FB550_magic_plyrspel(a1, v15, 0, 0, v18);
				} else {
					v14 = sub_424D80(v24);
					sub_4FB9C0_ability(a1, v14, 0);
				}
				if (++v11 >= (unsigned __int8)v20)
					return 1;
			}
			return 0;
		}
		return 1;
	}
	LOBYTE(v20) = 0;
	v3 = (_BYTE*)(v2 + 3700);
	v4 = (_DWORD*)(v2 + 3700);
	if (*(_BYTE*)(v2 + 2251)) {
		v6 = 136;
		do {
			if (*v4)
				LOBYTE(v20) = v20 + 1;
			++v4;
			--v6;
		} while (v6);
	} else {
		v5 = 5;
		do {
			if (*v4)
				LOBYTE(v20) = v20 + 1;
			++v4;
			--v5;
		} while (v5);
	}
	sub_426AC0_file3_fread(&v20, 1u);
	v7 = *(_BYTE*)(v2 + 2251);
	v8 = 1;
	if (v7) {
		do {
			if (*(_DWORD*)v3) {
				LOBYTE(v21) = strlen(sub_424870(v8));
				sub_426AC0_file3_fread(&v21, 1u);
				v17 = (unsigned __int8)v21;
				v10 = sub_424870(v8);
				sub_426AC0_file3_fread(v10, v17);
				sub_426AC0_file3_fread(v3, 4u);
			}
			++v8;
			v3 += 4;
		} while (v8 < 137);
		result = 1;
	} else {
		do {
			if (*(_DWORD*)v3) {
				LOBYTE(v21) = strlen(sub_425250(v8));
				sub_426AC0_file3_fread(&v21, 1u);
				v16 = (unsigned __int8)v21;
				v9 = sub_425250(v8);
				sub_426AC0_file3_fread(v9, v16);
				sub_426AC0_file3_fread(v3, 4u);
			}
			++v8;
			v3 += 4;
		} while (v8 < 6);
		result = 1;
	}
	return result;
}
// 41B660: using guessed type char var_100[256];

//----- (0041B9C0) --------------------------------------------------------
BOOL __cdecl sub_41B9C0(_DWORD* a1) {
	BOOL result;   // eax
	int i;         // ebp
	char* v3;      // ebx
	int v4;        // eax
	int v5;        // ebp
	int v6;        // edi
	int v7;        // ecx
	int v8;        // eax
	__int16 v9;    // ax
	int v10;       // eax
	int j;         // edi
	int k;         // edi
	int v13;       // [esp-8h] [ebp-140h]
	char v14;      // [esp+Dh] [ebp-12Bh]
	char v15;      // [esp+Eh] [ebp-12Ah]
	char v16;      // [esp+Fh] [ebp-129h]
	int v17;       // [esp+10h] [ebp-128h]
	int v18;       // [esp+14h] [ebp-124h]
	int v19;       // [esp+18h] [ebp-120h]
	int v20;       // [esp+1Ch] [ebp-11Ch]
	int v21;       // [esp+20h] [ebp-118h]
	int v22;       // [esp+24h] [ebp-114h]
	int v23;       // [esp+28h] [ebp-110h]
	int v24[3];    // [esp+2Ch] [ebp-10Ch]
	char v27[256]; // [esp+38h] [ebp-100h]

	v19 = a1[187];
	v16 = 1;
	v18 = 5;
	sub_426AC0_file3_fread(&v18, 2u);
	if ((__int16)v18 > 5)
		return 0;
	if (*getMemU32Ptr(0x5D4594, 3803300) == 1 && nox_common_gameFlags_check_40A5C0(2048)) {
		sub_4FEEF0();
		sub_4FE8A0(0);
	}
	if (nox_common_gameFlags_check_40A5C0(0x2000))
		v16 = 0;
	sub_426AC0_file3_fread(&v16, 1u);
	if (v16) {
		result = nox_common_gameFlags_check_40A5C0(2048);
		if (!result)
			return result;
		if (*getMemU32Ptr(0x5D4594, 3803300)) {
			sub_426AC0_file3_fread(&v22, 1u);
			v5 = 0;
			if ((_BYTE)v22) {
				do {
					sub_426AC0_file3_fread(&v20, 1u);
					sub_426AC0_file3_fread(v27, (unsigned __int8)v20);
					v27[(unsigned __int8)v20] = 0;
					v6 = sub_424880(v27);
					sub_426AC0_file3_fread(&v17, 2u);
					LOBYTE(v21) = 2;
					if ((__int16)v18 >= 2)
						sub_426AC0_file3_fread(&v21, 1u);
					v7 = a1[15];
					v24[1] = a1[14];
					v13 = (unsigned __int8)v21;
					v24[0] = a1;
					v24[2] = v7;
					v8 = sub_424920(v6);
					sub_4FD400(v8, (int)a1, a1, (int)a1, (int*)&v24, v13);
					v9 = v17;
					if (!(_WORD)v17) {
						v9 = *getMemU16Ptr(0x5D4594, 2649704);
						v17 = *getMemU32Ptr(0x5D4594, 2649704);
					}
					*((_WORD*)a1 + v6 + 172) = v9;
					if (v6 == 26 && (__int16)v18 >= 3) {
						sub_426AC0_file3_fread(&v23, 4u);
						v10 = sub_4FF2D0(51, (int)a1);
						if (v10)
							*(_DWORD*)(v10 + 72) = v23;
					}
					++v5;
				} while (v5 < (unsigned __int8)v22);
			}
		} else {
			LOBYTE(v22) = sub_424CB0((int)a1);
			sub_426AC0_file3_fread(&v22, 1u);
			for (i = sub_424D00(); i != -1; i = sub_424D20(i)) {
				if (sub_4FF350((int)a1, i)) {
					v3 = sub_4248F0(i);
					LOBYTE(v20) = strlen(v3);
					sub_426AC0_file3_fread(&v20, 1u);
					sub_426AC0_file3_fread(v3, (unsigned __int8)v20);
					sub_426AC0_file3_fread((_BYTE*)a1 + 2 * i + 344, 2u);
					LOBYTE(v21) = sub_4FF570((int)a1, i);
					sub_426AC0_file3_fread(&v21, 1u);
					if (i == 26) {
						v4 = sub_4FF2D0(51, (int)a1);
						if (v4)
							v17 = *(_DWORD*)(v4 + 72);
						else
							v17 = 100;
						sub_426AC0_file3_fread(&v17, 4u);
					}
				}
			}
		}
		if ((__int16)v18 >= 5 && !*(_BYTE*)(*(_DWORD*)(v19 + 276) + 2251)) {
			v14 = nox_common_playerIsAbilityActive_4FC250((int)a1, 1);
			sub_426AC0_file3_fread(&v14, 1u);
			if (*getMemU32Ptr(0x5D4594, 3803300) == 1 && v14 == 1)
				sub_4FC670(1);
			v15 = nox_common_playerIsAbilityActive_4FC250((int)a1, 4);
			sub_426AC0_file3_fread(&v15, 1u);
			v23 = sub_4FC030((int)a1, 4);
			sub_426AC0_file3_fread(&v23, 4u);
			if (*getMemU32Ptr(0x5D4594, 3803300) == 1 && v15 == 1) {
				sub_4FBB70((int)a1, 4);
				sub_4FC070((int)a1, 4, v23);
			}
			for (j = 2 - (v14 != 1); j < 6; ++j) {
				v17 = sub_4FBE60((int)a1, j);
				sub_426AC0_file3_fread(&v17, 4u);
				if (*getMemU32Ptr(0x5D4594, 3803300) == 1) {
					sub_4FBEA0((int)a1, j, v17);
					if (v17)
						sub_4D8100((int)a1, j, 0);
				}
			}
		}
	}
	if ((_WORD)v18 == 4 && !*(_BYTE*)(*(_DWORD*)(v19 + 276) + 2251)) {
		v14 = nox_common_playerIsAbilityActive_4FC250((int)a1, 1);
		sub_426AC0_file3_fread(&v14, 1u);
		if (*getMemU32Ptr(0x5D4594, 3803300) == 1 && v14 == 1)
			sub_4FC670(1);
		v15 = nox_common_playerIsAbilityActive_4FC250((int)a1, 4);
		sub_426AC0_file3_fread(&v15, 1u);
		v19 = sub_4FC030((int)a1, 4);
		sub_426AC0_file3_fread(&v19, 4u);
		if (*getMemU32Ptr(0x5D4594, 3803300) == 1 && v15 == 1) {
			sub_4FBB70((int)a1, 4);
			sub_4FC070((int)a1, 4, v19);
		}
		for (k = 2 - (v14 != 1); k < 6; ++k) {
			v17 = sub_4FBE60((int)a1, k);
			sub_426AC0_file3_fread(&v17, 4u);
			if (*getMemU32Ptr(0x5D4594, 3803300) == 1) {
				sub_4FBEA0((int)a1, k, v17);
				if (v17)
					sub_4D8100((int)a1, k, 0);
			}
		}
	}
	return 1;
}
// 41B9C0: using guessed type char var_100[256];

//----- (0041BEC0) --------------------------------------------------------
BOOL __cdecl sub_41BEC0(int a1) {
	int v1;       // edi
	int v2;       // esi
	BOOL result;  // eax
	int i;        // eax
	int v5;       // esi
	int v6;       // esi
	int j;        // eax
	int v8;       // [esp+Ch] [ebp-50h]
	int v9;       // [esp+10h] [ebp-4Ch]
	int v10;      // [esp+14h] [ebp-48h]
	int v11;      // [esp+18h] [ebp-44h]
	char v12[64]; // [esp+1Ch] [ebp-40h]

	v1 = a1;
	v2 = *(_DWORD*)(*(_DWORD*)(a1 + 748) + 276);
	LOBYTE(a1) = 1;
	v10 = 1;
	sub_426AC0_file3_fread(&v10, 2u);
	if ((__int16)v10 > 1)
		return 0;
	if (nox_common_gameFlags_check_40A5C0(0x2000))
		LOBYTE(a1) = 0;
	sub_426AC0_file3_fread(&a1, 1u);
	if (!(_BYTE)a1)
		return 1;
	result = nox_common_gameFlags_check_40A5C0(2048);
	if (!result)
		return result;
	v8 = 0;
	for (i = *(_DWORD*)(v2 + 3644); i; i = *(_DWORD*)(i + 64))
		++v8;
	sub_426AC0_file3_fread(&v8, 2u);
	if (*getMemU32Ptr(0x5D4594, 3803300) != 1) {
		if ((unsigned __int16)v8 > 0u) {
			v6 = *(_DWORD*)(v2 + 3644);
			for (j = *(_DWORD*)(v6 + 64); j; j = *(_DWORD*)(j + 64))
				v6 = j;
			for (; v6; v6 = *(_DWORD*)(v6 + 68)) {
				LOBYTE(v9) = strlen((const char*)v6);
				sub_426AC0_file3_fread(&v9, 1u);
				sub_426AC0_file3_fread((_BYTE*)v6, (unsigned __int8)v9);
				sub_426AC0_file3_fread((_BYTE*)(v6 + 72), 2u);
			}
		}
		return 1;
	}
	sub_4277B0(v1, 0xFFFFu);
	v5 = 0;
	if ((unsigned __int16)v8 <= 0u)
		return 1;
	do {
		sub_426AC0_file3_fread(&v9, 1u);
		sub_426AC0_file3_fread(v12, (unsigned __int8)v9);
		v12[(unsigned __int8)v9] = 0;
		sub_426AC0_file3_fread(&v11, 2u);
		sub_427500(v1, v12, v11);
		++v5;
	} while (v5 < (unsigned __int16)v8);
	return 1;
}
// 41BEC0: using guessed type char var_40[64];

//----- (0041C080) --------------------------------------------------------
int __cdecl sub_41C080(int a1) {
	_DWORD* v1;      // ebp
	int v2;          // ebx
	int result;      // eax
	unsigned int v4; // [esp+8h] [ebp-Ch]
	int v5;          // [esp+Ch] [ebp-8h]
	char v6[4];      // [esp+10h] [ebp-4h]

	v1 = (_DWORD*)a1;
	v2 = *(_DWORD*)(*(_DWORD*)(a1 + 748) + 276);
	if (nox_common_gameFlags_check_40A5C0(0x2000))
		return 1;
	a1 = 5;
	sub_426AC0_file3_fread(&a1, 2u);
	if ((__int16)a1 > 5)
		return 0;
	if ((__int16)a1 >= 5) {
		if (*getMemU32Ptr(0x5D4594, 3803300))
			sub_426AC0_file3_fread(v6, 4u);
		else
			sub_426AC0_file3_fread(getMemAt(0x587000, 201376), 4u);
	}
	if (!*getMemU32Ptr(0x5D4594, 3803300))
		strcpy((char*)(v2 + 4760), sub_409B40());
	v4 = strlen((const char*)(v2 + 4760));
	sub_426AC0_file3_fread(&v4, 2u);
	sub_426AC0_file3_fread((_BYTE*)(v2 + 4760), 2 * (unsigned __int16)v4);
	*(_BYTE*)((unsigned __int16)v4 + v2 + 4760) = 0;
	if ((__int16)a1 < 2 ||
		(*getMemU32Ptr(0x5D4594, 3803300) ? (result = sub_500B70()) : (result = sub_500A60()), result)) {
		if ((__int16)a1 < 3 || (result = sub_5000B0(v1)) != 0) {
			if ((__int16)a1 >= 4) {
				LOBYTE(v5) = sub_450750();
				sub_426AC0_file3_fread(&v5, 1u);
				sub_450760(v5);
				return 1;
			}
			sub_450760(0);
			return 1;
		}
	}
	return result;
}

//----- (0041C200) --------------------------------------------------------
int sub_41C200() {
	signed int v1; // edx
	int v2;        // [esp+0h] [ebp-Ch]
	char v3[8];    // [esp+4h] [ebp-8h]

	v2 = 1;
	sub_426AC0_file3_fread(&v2, 2u);
	if ((__int16)v2 > 1)
		return 0;
	v1 = 8 - sub_409390() % 8;
	if (v1 > 0) {
		memset(v3, 0, v1);
		sub_426AC0_file3_fread(v3, v1);
	}
	return 1;
}

//----- (0041C280) --------------------------------------------------------
int __cdecl sub_41C280(void* a1) {
	int result; // eax
	char* v2;   // eax
	char* v3;   // esi
	int v4;     // [esp+4h] [ebp-4h]

	v4 = 3;
	sub_426AC0_file3_fread(&v4, 2u);
	if ((__int16)v4 > 3)
		return 0;
	result = sub_460940(a1);
	if (result) {
		if ((__int16)v4 >= 2) {
			LOBYTE(a1) = sub_45E180();
			sub_426AC0_file3_fread(&a1, 1u);
			if (*getMemU32Ptr(0x5D4594, 3803300) == 1)
				sub_45E110((unsigned __int8)a1);
			LOBYTE(a1) = sub_4604E0();
			sub_426AC0_file3_fread(&a1, 1u);
			if (*getMemU32Ptr(0x5D4594, 3803300) == 1)
				sub_4604B0((unsigned __int8)a1);
		}
		if ((__int16)v4 >= 3) {
			v2 = nox_common_playerInfoGetByID_417040(*getMemIntPtr(0x5D4594, 2616328));
			v3 = v2;
			if (v2)
				LOBYTE(a1) = v2[3648];
			else
				LOBYTE(a1) = 4;
			sub_426AC0_file3_fread(&a1, 1u);
			if (*getMemU32Ptr(0x5D4594, 3803300) == 1) {
				if (nox_common_gameFlags_check_40A5C0(2048))
					sub_500C70((unsigned __int8)v3[2064], (unsigned __int8)a1);
			}
		}
		result = 1;
	}
	return result;
}

//----- (0041C3B0) --------------------------------------------------------
int sub_41C3B0(int a1) {
	int v1;          // eax
	int v2;          // eax
	int v3;          // [esp+0h] [ebp-Ch]
	unsigned int v4; // [esp+4h] [ebp-8h]
	int v5;          // [esp+8h] [ebp-4h]

	v5 = 12;
	sub_426AC0_file3_fread(&v5, 2u);
	if ((__int16)v5 > 12)
		return 0;
	if (nox_common_gameFlags_check_40A5C0(0x2000)) {
		*getMemU32Ptr(0x5D4594, 2660684) &= 0xFFFFFFFE;
		if (nox_common_gameFlags_check_40A5C0(4096) || sub_4D6F50() || sub_4D6F70()) {
			v2 = *getMemU32Ptr(0x5D4594, 2660684);
			LOBYTE(v2) = getMemByte(0x5D4594, 2660684) | 4;
			*getMemU32Ptr(0x5D4594, 2660684) = v2;
		} else {
			v1 = *getMemU32Ptr(0x5D4594, 2660684);
			LOBYTE(v1) = getMemByte(0x5D4594, 2660684) | 2;
			*getMemU32Ptr(0x5D4594, 2660684) = v1;
		}
	} else {
		*getMemU32Ptr(0x5D4594, 2660684) = *getMemU32Ptr(0x5D4594, 2660684) & 0xFFFFFFF9 | 1;
	}
	sub_426AC0_file3_fread(getMemAt(0x5D4594, 2660684), 4u);
	if (*getMemU32Ptr(0x5D4594, 3803300)) {
		sub_426AC0_file3_fread(&v4, 2u);
		sub_426AC0_file3_fread(getMemAt(0x5D4594, 2660688), (__int16)v4);
		*getMemU8Ptr( 0x5D4594, (__int16)v4 + 2660688) = 0;
		sub_426AC0_file3_fread(&v3, 1u);
		sub_426AC0_file3_fread(getMemAt(0x5D4594, 2661712), (unsigned __int8)v3);
		*getMemU8Ptr( 0x5D4594, (unsigned __int8)v3 + 2661712) = 0;
	} else {
		v4 = strlen((const char*)getMemAt(0x5D4594, 2660688));
		sub_426AC0_file3_fread(&v4, 2u);
		sub_426AC0_file3_fread(getMemAt(0x5D4594, 2660688), (__int16)v4);
		LOBYTE(v3) = strlen((const char*)getMemAt(0x5D4594, 2661712));
		sub_426AC0_file3_fread(&v3, 1u);
		sub_426AC0_file3_fread(getMemAt(0x5D4594, 2661712), (unsigned __int8)v3);
	}
	GetLocalTime((LPSYSTEMTIME)getMemAt(0x5D4594, 2661872));
	sub_426AC0_file3_fread(getMemAt(0x5D4594, 2661872), 2u);
	sub_426AC0_file3_fread(getMemAt(0x5D4594, 2661874), 2u);
	sub_426AC0_file3_fread(getMemAt(0x5D4594, 2661876), 2u);
	sub_426AC0_file3_fread(getMemAt(0x5D4594, 2661878), 2u);
	sub_426AC0_file3_fread(getMemAt(0x5D4594, 2661880), 2u);
	sub_426AC0_file3_fread(getMemAt(0x5D4594, 2661882), 2u);
	sub_426AC0_file3_fread(getMemAt(0x5D4594, 2661884), 2u);
	sub_426AC0_file3_fread(getMemAt(0x5D4594, 2661886), 2u);
	sub_426AC0_file3_fread(getMemAt(0x5D4594, 2661891), 3u);
	sub_426AC0_file3_fread(getMemAt(0x5D4594, 2661888), 3u);
	sub_426AC0_file3_fread(getMemAt(0x5D4594, 2661894), 3u);
	sub_426AC0_file3_fread(getMemAt(0x5D4594, 2661897), 3u);
	sub_426AC0_file3_fread(getMemAt(0x5D4594, 2661900), 3u);
	sub_426AC0_file3_fread(getMemAt(0x5D4594, 2661903), 1u);
	sub_426AC0_file3_fread(getMemAt(0x5D4594, 2661904), 1u);
	sub_426AC0_file3_fread(getMemAt(0x5D4594, 2661905), 1u);
	sub_426AC0_file3_fread(getMemAt(0x5D4594, 2661906), 1u);
	sub_426AC0_file3_fread(getMemAt(0x5D4594, 2661907), 1u);
	if (*getMemU32Ptr(0x5D4594, 3803300)) {
		sub_426AC0_file3_fread(&v3, 1u);
		sub_426AC0_file3_fread(getMemAt(0x5D4594, 2661908), 2 * (unsigned __int8)v3);
		*getMemU16Ptr(0x5D4594, 2 * (unsigned __int8)v3 + 2661908) = 0;
	} else {
		LOBYTE(v3) = nox_wcslen((const wchar_t*)getMemAt(0x5D4594, 2661908));
		sub_426AC0_file3_fread(&v3, 1u);
		sub_426AC0_file3_fread(getMemAt(0x5D4594, 2661908), 2 * (unsigned __int8)v3);
	}
	sub_426AC0_file3_fread(getMemAt(0x5D4594, 2661958), 1u);
	*getMemU8Ptr(0x5D4594, 2661959) = 0;
	sub_426AC0_file3_fread(getMemAt(0x5D4594, 2661959), 1u);
	if (!*getMemU32Ptr(0x5D4594, 3803300))
		*getMemU8Ptr(0x5D4594, 2661960) = sub_467590();
	sub_426AC0_file3_fread(getMemAt(0x5D4594, 2661960), 1u);
	if ((__int16)v5 >= 11) {
		strcpy((char*)getMemAt(0x5D4594, 2661840), sub_409B40());
		LOBYTE(v3) = strlen((const char*)getMemAt(0x5D4594, 2661840));
		sub_426AC0_file3_fread(&v3, 1u);
		sub_426AC0_file3_fread(getMemAt(0x5D4594, 2661840), (unsigned __int8)v3);
		*getMemU8Ptr( 0x5D4594, (unsigned __int8)v3 + 2661840) = 0;
	}
	if ((__int16)v5 < 12)
		*getMemU8Ptr(0x5D4594, 2661961) = 0;
	else
		sub_426AC0_file3_fread(getMemAt(0x5D4594, 2661961), 1u);
	return 1;
}

//----- (0041C780) --------------------------------------------------------
int sub_41C780(int a1) {
	int i;    // edi
	char* v2; // esi
	bool v3;  // [esp+3h] [ebp-19h]
	int v4;   // [esp+4h] [ebp-18h]
	int v5;   // [esp+8h] [ebp-14h]
	int4 v6;  // [esp+Ch] [ebp-10h]

	v5 = 11;
	sub_426AC0_file3_fread(&v5, 2u);
	if ((__int16)v5 > 11)
		return 0;
	if ((__int16)v5 < 11 || (v3 = !nox_common_gameFlags_check_40A5C0(0x2000), sub_426AC0_file3_fread(&v3, 1u), v3)) {
		if (*getMemU32Ptr(0x5D4594, 3803300)) {
			v6.field_0 = 0;
			v6.field_4 = 0;
			v6.field_8 = 0;
			v6.field_C = 0;
		} else {
			sub_43DD10(&v6.field_0);
			v4 = sub_43DB20();
		}
		sub_426AC0_file3_fread(&v6.field_C, 4u);
		sub_426AC0_file3_fread(&v6.field_8, 4u);
		sub_426AC0_file3_fread(&v6, 4u);
		sub_426AC0_file3_fread(&v6.field_4, 4u);
		sub_426AC0_file3_fread(&v4, 4u);
		for (i = 0; i < v4; ++i) {
			v2 = sub_43DB40(i);
			if (*getMemU32Ptr(0x5D4594, 3803300) == 1) {
				*(_DWORD*)v2 = 0;
				*((_DWORD*)v2 + 1) = 0;
				*((_DWORD*)v2 + 2) = 0;
				*((_DWORD*)v2 + 3) = 0;
			}
			sub_426AC0_file3_fread(v2 + 12, 4u);
			sub_426AC0_file3_fread(v2 + 8, 4u);
			sub_426AC0_file3_fread(v2, 4u);
			sub_426AC0_file3_fread(v2 + 4, 4u);
		}
		if (*getMemU32Ptr(0x5D4594, 3803300) == 1 && !nox_common_gameFlags_check_40A5C0(0x2000)) {
			sub_43D9E0(&v6);
			sub_43DB30(v4);
		}
	}
	return 1;
}

//----- (0041CAC0) --------------------------------------------------------
FILE* __cdecl sub_41CAC0(char* a1, char** a2) {
	FILE* result;        // eax
	char** v3;           // esi
	int v4;              // ebx
	int v5;              // edi
	int v6;              // eax
	unsigned __int8* v7; // ecx
	int v8;              // ebp
	int v9;              // eax
	_DWORD* v10;         // esi
	int v11;             // edi
	int v12;             // [esp+0h] [ebp-8h]
	char* v13;           // [esp+4h] [ebp-4h]

	result = sub_408CC0_fopen(a1, 0);
	nox_file_2 = result;
	if (result) {
		result = (FILE*)sub_408D40((int)result, 27);
		if (result) {
			v3 = a2;
			v4 = 0;
			while (1) {
				sub_408E40_fread((char*)&v13, 4, 1, nox_file_2);
				if (!v13)
					break;
				v5 = sub_409390();
				sub_408FE0((char*)&v12, 4, 1, nox_file_2);
				v6 = sub_409390();
				if (*getMemU32Ptr(0x587000, 55816)) {
					v7 = getMemAt(0x587000, 55816);
					while (v13 != *((char**)v7 + 1)) {
						v8 = *((_DWORD*)v7 + 3);
						v7 += 12;
						if (!v8)
							goto LABEL_9;
					}
					v9 = v6 - v5;
					*v3 = v13;
					v10 = (char**)((char*)v3 + v9 - 4);
					v4 += v9 + 4;
					*v10 = v12;
					v3 = (char**)(v10 + 2);
					if (v12) {
						v11 = v12;
						v4 += v12;
						do {
							sub_408E40_fread((char*)&a1, 1, 1, nox_file_2);
							*(_BYTE*)v3 = (_BYTE)a1;
							v3 = (char**)((char*)v3 + 1);
							--v11;
						} while (v11);
					}
				} else {
				LABEL_9:
					sub_409050(nox_file_2, v12, SEEK_CUR);
				}
			}
			*v3 = 0;
			sub_408D90(nox_file_2);
			result = (FILE*)(v4 + 4);
		}
	}
	return result;
}

//----- (0041CC00) --------------------------------------------------------
int __cdecl sub_41CC00(char* a1) {
	int v1;     // eax
	int v2;     // esi
	int result; // eax
	int v4;     // edi

	nullsub_5();
	v1 = sub_41CC50(a1);
	v2 = v1 + 4;
	result = (int)malloc(v1 + 4);
	v4 = result;
	if (result) {
		sub_41CAC0(a1, (char**)result);
		sub_40BC60(31, 3, "SAVE_SERVER", v4, v2, 0);
		result = 1;
	}
	return result;
}
// 467F20: using guessed type void nullsub_5(void);

//----- (0041CC50) --------------------------------------------------------
int __cdecl sub_41CC50(char* a1) {
	char* v1;            // esi
	FILE* v2;            // eax
	int result;          // eax
	int v4;              // edi
	int v5;              // esi
	int v6;              // eax
	unsigned __int8* v7; // ecx
	int v8;              // ebx
	int v9;              // [esp+4h] [ebp-4h]

	v1 = a1;
	v2 = sub_408CC0_fopen(a1, 0);
	nox_file_2 = v2;
	if (v2) {
		if (sub_408D40((int)v2, 27)) {
			v4 = 0;
			while (1) {
				sub_408E40_fread((char*)&a1, 4, 1, nox_file_2);
				if (sub_409370() == -1)
					break;
				if (!a1) {
					v4 += 4;
					break;
				}
				v5 = sub_409390();
				sub_408FE0((char*)&v9, 4, 1, nox_file_2);
				v6 = sub_409390() - v5;
				if (*getMemU32Ptr(0x587000, 55816)) {
					v7 = getMemAt(0x587000, 55816);
					while (a1 != *((char**)v7 + 1)) {
						v8 = *((_DWORD*)v7 + 3);
						v7 += 12;
						if (!v8)
							goto LABEL_14;
					}
					v4 += v9 + v6 + 4;
				}
			LABEL_14:
				sub_409050(nox_file_2, v9, SEEK_CUR);
			}
			sub_408D90(nox_file_2);
			result = v4;
		} else {
			sub_413D30((char*)getMemAt(0x587000, 56904), v1);
			result = 0;
		}
	} else {
		sub_413D30((char*)getMemAt(0x587000, 56844), v1);
		result = 0;
	}
	return result;
}

//----- (0041CD70) --------------------------------------------------------
int __cdecl sub_41CD70(char* a1, _BYTE* a2, int a3) {
	char* v3;   // esi
	FILE* v4;   // eax
	int result; // eax
	int v6;     // edi
	_BYTE* v7;  // esi

	v3 = a1;
	v4 = sub_408CC0_fopen(a1, 1);
	nox_file_2 = v4;
	if (v4) {
		if (sub_408D40((int)v4, 27)) {
			v6 = a3;
			if (a3) {
				v7 = a2;
				do {
					LOBYTE(a1) = *v7++;
					sub_409200((char*)&a1, 1, 1, nox_file_2);
					--v6;
				} while (v6);
			}
			sub_408D90(nox_file_2);
			result = 1;
		} else {
			sub_413D30((char*)getMemAt(0x587000, 57008), v3);
			result = 0;
		}
	} else {
		sub_413D30((char*)getMemAt(0x587000, 56960));
		result = 0;
	}
	return result;
}

//----- (0041CE00) --------------------------------------------------------
int sub_41CE00() {
	char v2[3]; // [esp+0h] [ebp-4h]

	v2[0] = -63;
	*(_WORD*)&v2[1] = *getMemU16Ptr(0x5D4594, 2616328);
	sub_4E53C0(31, v2, 3, 0, 1);
	return 1;
}

//----- (0041CE30) --------------------------------------------------------
int __cdecl sub_41CE30(char* a1, wchar_t* a2) {
	int v2;              // ecx
	unsigned __int8* v3; // eax
	int v4;              // edx
	int v5;              // esi
	int v7;              // [esp+4h] [ebp-4h]

	if (!sub_426910(a1, 1, 27))
		return 0;
	do {
		while (1) {
		LABEL_2:
			sub_426AC0_file3_fread(&a1, 4u);
			if (!a1) {
				sub_4269F0();
				return 0;
			}
			sub_426AC0_file3_fread(&v7, 4u);
			if (a1 == (char*)2)
				break;
			sub_426AA0(v7);
		}
		v2 = 0;
	} while (!*getMemU32Ptr(0x587000, 55816));
	v3 = getMemAt(0x587000, 55816);
	while (*((_DWORD*)v3 + 1) != 2) {
		v4 = *((_DWORD*)v3 + 3);
		v3 += 12;
		++v2;
		if (!v4)
			goto LABEL_2;
	}
	v5 = (*(int(__cdecl**)(int, int)) getMemAt(0x587000, 12 * v2 + 55824))(0, (int)a2);
	sub_4269F0();
	return v5;
}

//----- (0041CEE0) --------------------------------------------------------
int __cdecl sub_41CEE0(int a1, int a2) {
	int result;          // eax
	int v3;              // ebx
	unsigned __int8* v4; // esi
	int v6;              // edi
	int v8;              // eax

	memcpy(getMemAt(0x5D4594, 2660684), (const void*)a1, sizeof(nox_savegame_xxx));
	result = sub_426910((char*)getMemAt(0x5D4594, 2660688), 0, 27);
	if (result) {
		v3 = a2;
		if (!a2)
			a1 = 1;
		if (*getMemU32Ptr(0x587000, 55936)) {
			v4 = getMemAt(0x587000, 55940);
			while (1) {
				if (v3 || *(_DWORD*)v4 == a1) {
					sub_426AC0_file3_fread(v4, 4u);
					sub_426C90();
					v6 = (*((int(__cdecl**)(_DWORD))v4 + 1))(0);
					sub_426D40();
					if (!v6)
						break;
				}
				v8 = *((_DWORD*)v4 + 2);
				v4 += 12;
				if (!v8)
					goto LABEL_10;
			}
			sub_4269F0();
			result = 0;
		} else {
		LABEL_10:
			a1 = 0;
			sub_426AC0_file3_fread(&a1, 4u);
			sub_4269F0();
			result = 1;
		}
	}
	return result;
}
// 41CF42: variable 'v5' is possibly undefined
// 41CF51: variable 'v7' is possibly undefined

//----- (0041CFA0) --------------------------------------------------------
int __cdecl sub_41CFA0(char* a1, int a2) {
	unsigned __int16 v2; // si
	FILE* v3;            // eax
	int result;          // eax
	char* v5;            // edi

	if (sub_419EE0(a2))
		return 0;
	v2 = sub_41CC50(a1);
	if (!v2)
		return 0;
	v3 = sub_408CC0_fopen(a1, 0);
	nox_file_2 = v3;
	if (!v3) {
		sub_413D30((char*)getMemAt(0x587000, 57056), a1);
		return 0;
	}
	if (sub_408D40((int)v3, 27)) {
		v5 = (char*)malloc(v2);
		if (v5) {
			sub_408E40_fread(v5, v2, 1, nox_file_2);
			sub_408D90(nox_file_2);
			sub_419EB0(a2, 1);
			sub_40BC60(a2, 2, "SAVEDATA", (int)v5, v2, 1);
			free(v5);
		} else {
			sub_408D90(nox_file_2);
		}
		result = 1;
	} else {
		sub_413D30((char*)getMemAt(0x587000, 57108), getMemAt(0x5D4594, 2660688));
		result = 0;
	}
	return result;
}

//----- (0041D090) --------------------------------------------------------
int __cdecl sub_41D090(char* a1) {
	int result; // eax
	int v2;     // [esp+0h] [ebp-8h]
	int v3;     // [esp+4h] [ebp-4h]

	v2 = 0;
	result = sub_426910(a1, 1, 27);
	if (result) {
		while (1) {
			sub_426AC0_file3_fread(&a1, 4u);
			if (!a1)
				break;
			sub_426C20(&v3, 4u);
			if (a1 == (char*)10) {
				sub_41D110(&v2);
				break;
			}
			sub_426AA0(v3);
		}
		sub_4269F0();
		result = v2;
	}
	return result;
}

//----- (0041D110) --------------------------------------------------------
int __cdecl sub_41D110(_DWORD* a1) {
	int result; // eax
	int v2;     // [esp+0h] [ebp-8h]
	int v3;     // [esp+4h] [ebp-4h]

	result = nox_common_gameFlags_check_40A5C0(2048);
	if (result) {
		v2 = 5;
		sub_426AC0_file3_fread(&v2, 2u);
		result = v2;
		if ((__int16)v2 <= 5 && (__int16)v2 >= 5) {
			sub_426AC0_file3_fread(&v3, 4u);
			result = v3;
			*a1 = v3;
		}
	}
	return result;
}

//----- (0041D170) --------------------------------------------------------
int sub_41D170() {
	char v1[2]; // [esp+0h] [ebp-2h]

	v1[0] = -16;
	v1[1] = 27;
	return sub_4E53C0(31, v1, 2, 0, 0);
}

//----- (0041D1A0) --------------------------------------------------------
int __cdecl sub_41D1A0(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 527720) = a1;
	return result;
}

//----- (0041D1B0) --------------------------------------------------------
int sub_41D1B0() { return *getMemU32Ptr(0x5D4594, 527720); }

//----- (0041D1C0) --------------------------------------------------------
void sub_41D1C0() { nox_srand(0x9CFu); }

//----- (0041D440) --------------------------------------------------------
int sub_41D440() {
	int result;   // eax
	int v1;       // eax
	char v2[128]; // [esp+0h] [ebp-80h]

	sub_41E370();
	sub_41E300(0);
	result = sub_40CE60();
	if (result) {
		sub_41FCF0();
		nox_set_draw_unk1(sub_41E210);
		sub_41EAC0();
		strcpy(v2, "SOFTWARE\\Westwood\\Nox");
		sub_40DA90((int)getMemAt(0x587000, 58096), (int)v2);
		v1 = sub_4200E0();
		sub_40D950(v1);
		result = 1;
	}
	return result;
}

//----- (0041D4C0) --------------------------------------------------------
int sub_41D4C0() {
	sub_41EB40();
	sub_41F4B0();
	nox_set_draw_unk1(0);
	sub_40D0F0();
	return 1;
}

//----- (0041D4E0) --------------------------------------------------------
int sub_41D4E0() {
	int v0; // eax
	int v1; // eax
	int v3; // [esp-10h] [ebp-18h]
	int v4; // [esp-Ch] [ebp-14h]
	int v5; // [esp-8h] [ebp-10h]
	int v6; // [esp+0h] [ebp-8h]
	int v7; // [esp+4h] [ebp-4h]

	if (sub_41FBE0(&v7, &v6) != 1)
		return 0;
	v0 = sub_420020();
	if (v0 == -1)
		return 0;
	v5 = v6;
	v4 = v7;
	v3 = v0;
	v1 = sub_4200E0();
	sub_40D280(v1, v3, v4, v5, 30);
	return 1;
}

//----- (0041D530) --------------------------------------------------------
int sub_41D530() {
	int v0;     // esi
	int v1;     // eax
	int result; // eax
	int v3;     // eax
	int v4;     // eax
	int v5;     // [esp-10h] [ebp-18h]
	int v6;     // [esp-Ch] [ebp-14h]
	int v7;     // [esp+0h] [ebp-8h]
	int v8;     // [esp+4h] [ebp-4h]

	if (sub_41FBE0(&v8, &v7) != 1)
		return 0;
	v0 = sub_420020();
	if (v0 == -1) {
		if (sub_41E300(11)) {
			dword_5d4594_2660652 = -2147221396;
			v3 = sub_41E2F0();
			sub_41DA70(v3, 5);
			v4 = sub_41E2F0();
			sub_41DA70(v4, 9);
		}
		result = 1;
	} else {
		sub_420580();
		v6 = v7;
		v5 = v8;
		v1 = sub_4200E0();
		sub_40D280(v1, v0, v5, v6, 30);
		result = 1;
	}
	return result;
}

//----- (0041D5D0) --------------------------------------------------------
int sub_41D5D0() { return 1; }

//----- (0041D5E0) --------------------------------------------------------
unsigned __int8* sub_41D5E0() {
	unsigned __int8* result; // eax
	unsigned __int8* v1;     // esi
	void* v2;                // eax

	result = (unsigned __int8*)nox_common_playerInfoGetXXX_417090(31);
	v1 = result;
	if (result) {
		result = *(unsigned __int8**)&dword_5d4594_2660032;
		if (dword_5d4594_2660032) {
			*((_DWORD*)v1 + 517) = dword_5d4594_2660032;
			nox_swprintf((wchar_t*)v1 + 1036, L"%S", getMemAt(0x5D4594, 2660012 + 87));
			v2 = sub_425A70(*((_DWORD*)v1 + 517));
			if (!v2)
				v2 = sub_425AD0(*((_DWORD*)v1 + 517), (wchar_t*)v1 + 1036);
			result = (unsigned __int8*)sub_425B30((int)v2, v1[2064]);
		}
	}
	return result;
}

//----- (0041D650) --------------------------------------------------------
int sub_41D650() {
	char* v0;   // eax
	int result; // eax

	v0 = sub_41FA40();
	result = sub_41F800(v0);
	if (result)
		result = sub_40D530(result);
	*getMemU32Ptr(0x5D4594, 371700) = 1;
	return result;
}

//----- (0041D670) --------------------------------------------------------
BOOL __cdecl sub_41D670(int a1) {
	int v1;      // eax
	__int16 v3;  // [esp+2h] [ebp-4Ah]
	char v4[72]; // [esp+4h] [ebp-48h]

	if (!sub_420230(v4, &v3))
		return 0;
	v1 = sub_4200E0();
	return sub_40DF20((int)v4, v3, a1, v1, -1, 0, 0);
}

//----- (0041D6C0) --------------------------------------------------------
int sub_41D6C0() {
	int v0;         // ebx
	char* v1;       // ebp
	int v2;         // eax
	int v3;         // ebp
	char* v4;       // ebx
	int v5;         // eax
	int result;     // eax
	char* v7;       // ebp
	int v8;         // eax
	__int16 v9;     // [esp+12h] [ebp-45Ah]
	char* v10;      // [esp+14h] [ebp-458h]
	BOOL v11;       // [esp+18h] [ebp-454h]
	int v12;        // [esp+1Ch] [ebp-450h]
	int v13;        // [esp+20h] [ebp-44Ch]
	char v14[72];   // [esp+24h] [ebp-448h]
	char v15[1024]; // [esp+6Ch] [ebp-400h]

	v0 = 1;
	memset(v15, 0, sizeof(v15));
	v11 = 1;
	v12 = 1;
	if (!sub_420230(v14, &v9))
		return 0;
	if ((unsigned int)nox_common_playerInfoCount_416F40() > 0x19) {
		v1 = nox_common_playerInfoGetFirst_416EA0();
		v13 = 25;
		while (1) {
			if (v1[2096]) {
				if (v0) {
					strcat(v15, v1 + 2096);
					v0 = 0;
				} else {
					*(_WORD*)&v15[strlen(v15)] = *getMemU16Ptr(0x587000, 58112);
					strcat(v15, v1 + 2096);
				}
			}
			v10 = nox_common_playerInfoGetNext_416EE0((int)v1);
			if (!--v13)
				break;
			v1 = v10;
		}
		if (!v0) {
			v2 = sub_4200E0();
			v11 = sub_40DF20((int)v14, v9, (int)v15, v2, -1, 0, 0);
		}
		v3 = 1;
		if (!v10)
			goto LABEL_37;
		v15[0] = 0;
		v4 = nox_common_playerInfoGetNext_416EE0((int)v10);
		if (!v4)
			goto LABEL_37;
		do {
			if (v4[2096]) {
				if (v3) {
					strcat(v15, v4 + 2096);
					v3 = 0;
				} else {
					*(_WORD*)&v15[strlen(v15)] = *getMemU16Ptr(0x587000, 58116);
					strcat(v15, v4 + 2096);
				}
			}
			v4 = nox_common_playerInfoGetNext_416EE0((int)v4);
		} while (v4);
		if (!v3) {
			v5 = sub_4200E0();
			result = sub_40DF20((int)v14, v9, (int)v15, v5, -1, 0, 0);
		} else {
		LABEL_37:
			result = v12;
		}
		if (v11 && result == 1)
			return result;
		return 0;
	}
	v7 = nox_common_playerInfoGetFirst_416EA0();
	if (v7) {
		do {
			if (v7[2096]) {
				if (v0) {
					strcat(v15, v7 + 2096);
					v0 = 0;
				} else {
					*(_WORD*)&v15[strlen(v15)] = *getMemU16Ptr(0x587000, 58120);
					strcat(v15, v7 + 2096);
				}
			}
			v7 = nox_common_playerInfoGetNext_416EE0((int)v7);
		} while (v7);
		if (!v0) {
			v8 = sub_4200E0();
			v11 = sub_40DF20((int)v14, v9, (int)v15, v8, -1, 0, 0);
		}
	}
	return v11;
}

//----- (0041D9F0) --------------------------------------------------------
void* sub_41D9F0() {
	unsigned __int8* v0; // esi
	void* result;        // eax

	v0 = getMemAt(0x587000, 58132);
	do {
		result = malloc(0x2Eu);
		*(_DWORD*)v0 = result;
		v0 += 16;
	} while ((int)v0 < (int)getMemAt(0x587000, 58340));
	return result;
}

//----- (0041DA10) --------------------------------------------------------
int __cdecl sub_41DA10(int a1) {
	_WORD* v1;  // edi
	int result; // eax

	v1 = *(_WORD**)getMemAt(0x587000, 16 * a1 + 58132);
	if (v1) {
		result = 0;
		memset(v1, 0, 0x2Cu);
		v1[22] = 0;
		*getMemU32Ptr(0x587000, 16 * a1 + 58136) = 0;
	}
	return result;
}

//----- (0041DA40) --------------------------------------------------------
LPVOID sub_41DA40() {
	LPVOID* v0;    // esi
	LPVOID result; // eax

	v0 = (LPVOID*)getMemAt(0x587000, 58132);
	do {
		result = *v0;
		if (*v0) {
			free(*v0);
			*v0 = 0;
		}
		v0 += 4;
	} while ((int)v0 < (int)getMemAt(0x587000, 58340));
	return result;
}

//----- (0041DA70) --------------------------------------------------------
int __cdecl sub_41DA70(int a1, __int16 a2) {
	int result; // eax
	int v3;     // ecx
	int v4;     // edx

	result = 16 * a1;
	v3 = *getMemU32Ptr(0x587000, 16 * a1 + 58132);
	if (v3 && (v4 = *getMemU32Ptr(0x587000, 16 * a1 + 58136), v4 < 23)) {
		*(_WORD*)(v3 + 2 * v4) = a2;
		++*getMemU32Ptr(0x587000, 16 * a1 + 58136);
	} else {
		result = sub_41E300(11);
		if (result)
			dword_5d4594_2660652 = 0;
	}
	return result;
}

//----- (0041DB90) --------------------------------------------------------
int sub_41DB90() {
	int v0; // edi
	int v1; // eax
	int v2; // eax
	int v3; // esi
	int v5; // [esp+4h] [ebp-4h]

	v0 = 1;
	v1 = *getMemU32Ptr(0x587000, 16 * sub_41E2F0() + 58136);
	if (v1) {
		v5 = v1;
		do {
			v2 = sub_41E2F0();
			switch (sub_41DCC0(v2)) {
			case 0:
				v0 = sub_41D530();
				break;
			case 1:
				sub_449530();
				break;
			case 2:
				v3 = sub_41E520();
				if (v3) {
					sub_468110_wol_prog();
					nox_sprintf((char*)getMemAt(0x5D4594, 527996), "%s/%s", v3 + 81, v3 + 337);
					nox_sprintf((char*)getMemAt(0x5D4594, 527732), "%s\\%s", v3 + 468, v3 + 337);
					CreateDirectoryA((LPCSTR)(v3 + 468), 0);
					v0 = sub_40DC90(v3 + 16, v3 + 370, v3 + 403, (int)getMemAt(0x5D4594, 527996), (int)getMemAt(0x5D4594, 527732),
									(int)getMemAt(0x587000, 58684));
					sub_41E300(4);
				} else {
					sub_41E300(5);
					sub_40DC70();
				}
				break;
			case 3:
				sub_468080();
				v0 = sub_41FDE0();
				sub_41E300(5);
				break;
			default:
				break;
			}
			--v5;
		} while (v5);
	}
	sub_40D250();
	return v0;
}

//----- (0041DCC0) --------------------------------------------------------
int __cdecl sub_41DCC0(int a1) {
	unsigned __int16* v1; // edx
	int v2;               // eax
	int v3;               // eax
	int v4;               // esi

	v1 = *(unsigned __int16**)getMemAt(0x587000, 16 * a1 + 58132);
	if (!v1)
		return a1;
	v2 = *getMemU32Ptr(0x587000, 16 * a1 + 58136);
	if (v2 <= 0)
		return a1;
	v3 = v2 - 1;
	v4 = *v1;
	*getMemU32Ptr(0x587000, 16 * a1 + 58136) = v3;
	if (v3)
		memmove((unsigned int)v1, (_BYTE*)v1 + 2, 2 * v3);
	return v4;
}

//----- (0041DD10) --------------------------------------------------------
int sub_41DD10() {
	int i;  // esi
	int v1; // eax

	for (i = *getMemU32Ptr(0x587000, 58216); i; --i) {
		v1 = sub_41E2F0();
		sub_41DCC0(v1);
	}
	return 1;
}

//----- (0041DD40) --------------------------------------------------------
int sub_41DD40() {
	int v0; // esi
	int v1; // eax
	int v2; // eax
	int v3; // eax
	int v4; // eax

	if (*getMemU32Ptr(0x587000, 58200)) {
		v0 = *getMemU32Ptr(0x587000, 58200);
		do {
			v1 = sub_41E2F0();
			v2 = sub_41DCC0(v1) - 16;
			if (v2) {
				v3 = v2 - 1;
				if (v3) {
					if (v3 == 1)
						sub_468170_wol_prog();
				} else {
					sub_468340();
					sub_41E300(5);
				}
			} else {
				sub_4682B0_wol_prog();
				sub_41E300(2);
				v4 = sub_41E2F0();
				sub_41DA70(v4, 2);
			}
			--v0;
		} while (v0);
	}
	sub_40DCD0();
	return 1;
}

//----- (0041DFC0) --------------------------------------------------------
int sub_41DFC0() {
	int v0; // esi
	int v1; // eax

	if (*getMemU32Ptr(0x587000, 58248)) {
		v0 = *getMemU32Ptr(0x587000, 58248);
		do {
			v1 = sub_41E2F0();
			switch (sub_41DCC0(v1)) {
			case 3:
				sub_41FF10();
				break;
			case 5:
				sub_41DAC0(*(int*)&dword_5d4594_2660652);
				break;
			case 10:
				sub_446E60();
				break;
			case 11:
				sub_446EB0();
				break;
			case 12:
				sub_41F3A0(-99999, 1);
				break;
			case 13:
				sub_40D3B0();
				break;
			case 14:
				sub_446D50();
				break;
			case 15:
				sub_41F4B0();
				sub_4475E0();
				break;
			default:
				break;
			}
			--v0;
		} while (v0);
	}
	sub_40D250();
	return 1;
}

//----- (0041E080) --------------------------------------------------------
int sub_41E080() {
	int v0; // esi
	int v1; // eax
	int v2; // eax

	if (*getMemU32Ptr(0x587000, 58184)) {
		v0 = *getMemU32Ptr(0x587000, 58184);
		do {
			v1 = sub_41E2F0();
			v2 = sub_41DCC0(v1);
			if (v2 == 3) {
				sub_41FF10();
			} else if (v2 == 7) {
				sub_41E300(7);
				sub_4207F0(3);
			}
			--v0;
		} while (v0);
	}
	sub_40D250();
	return 1;
}

//----- (0041E0D0) --------------------------------------------------------
int sub_41E0D0() {
	int v0; // esi
	int v1; // eax
	int v2; // eax

	if (*getMemU32Ptr(0x587000, 58264)) {
		v0 = *getMemU32Ptr(0x587000, 58264);
		do {
			v1 = sub_41E2F0();
			switch (sub_41DCC0(v1)) {
			case 5:
				if (*(int*)&dword_5d4594_2660652 == -2147221394)
					sub_43AFA0(11);
				break;
			case 10:
				sub_43ACC0();
				break;
			case 12:
				v2 = sub_420100();
				sub_41F3A0(v2, 1);
				break;
			case 19:
				sub_43B440();
				break;
			default:
				break;
			}
			--v0;
		} while (v0);
	}
	sub_40D250();
	return 1;
}

//----- (0041E170) --------------------------------------------------------
int sub_41E170() {
	int v0; // esi
	int v1; // eax

	if (*getMemU32Ptr(0x587000, 58280)) {
		v0 = *getMemU32Ptr(0x587000, 58280);
		do {
			v1 = sub_41E2F0();
			if (sub_41DCC0(v1) == 8)
				sub_41FF10();
			--v0;
		} while (v0);
	}
	sub_40D250();
	return 1;
}

//----- (0041E1B0) --------------------------------------------------------
int sub_41E1B0() {
	int v0; // esi
	int v1; // eax
	int v2; // eax
	int v3; // eax

	if (!*getMemU32Ptr(0x587000, 58312))
		return 1;
	v0 = *getMemU32Ptr(0x587000, 58312);
	do {
		v1 = sub_41E2F0();
		v2 = sub_41DCC0(v1) - 5;
		if (v2) {
			v3 = v2 - 1;
			if (v3) {
				if (v3 == 3) {
					sub_4207F0(1);
					sub_43C260();
				}
			} else {
				sub_41D1D0(1);
			}
		} else {
			sub_41D1D0(0);
		}
		--v0;
	} while (v0);
	return 1;
}

//----- (0041E210) --------------------------------------------------------
int sub_41E210() {
	int v0;     // eax
	int v1;     // edi
	int v2;     // eax
	int result; // eax
	int v4;     // [esp-8h] [ebp-Ch]

	switch (sub_41E2F0()) {
	case 0:
		sub_41D9F0();
		*getMemU32Ptr(0x5D4594, 2659992) = 0;
		sub_4207F0(1);
		sub_41E300(1);
		*getMemU32Ptr(0x5D4594, 527992) = sub_41E2F0();
		result = 1;
		break;
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	case 11:
		if (*getMemU32Ptr(0x587000, 16 * sub_41E2F0() + 58140)) {
			v0 = sub_41E2F0();
			v4 = *getMemU32Ptr(0x5D4594, 527992);
			v1 = 16 * v0;
			v2 = sub_41E2F0();
			(*(void(__cdecl**)(_DWORD, int)) getMemAt(0x587000, v1 + 58140))(*getMemU32Ptr(0x587000, 16 * v2 + 58132), v4);
		}
		*getMemU32Ptr(0x5D4594, 527992) = sub_41E2F0();
		result = 1;
		break;
	case 10:
		sub_41DA40();
		result = 1;
		break;
	case 12:
		sub_41D1D0(0);
		result = 1;
		break;
	default:
		result = 0;
		break;
	}
	return result;
}

//----- (0041E2F0) --------------------------------------------------------
int sub_41E2F0() { return dword_5d4594_527988; }

//----- (0041E300) --------------------------------------------------------
int __cdecl sub_41E300(int a1) {
	int result; // eax

	if (a1 == 11 && nox_common_gameFlags_check_40A5C0(0x2000000) && sub_43C710()) {
		if (dword_5d4594_528256)
			sub_41E470();
		else
			sub_41E400();
		result = 0;
	} else {
		if (dword_5d4594_527988 != a1) {
			dword_5d4594_527988 = a1;
			sub_41DA10(a1);
			if (dword_5d4594_527988 == 11)
				sub_40E0A0();
		}
		result = 1;
	}
	return result;
}

//----- (0041E370) --------------------------------------------------------
int sub_41E370() {
	int result; // eax

	result = 0;
	dword_5d4594_528252 = 0;
	dword_5d4594_528256 = 0;
	dword_5d4594_528260 = 0;
	dword_5d4594_528264 = 0;
	return result;
}

//----- (0041E390) --------------------------------------------------------
int sub_41E390() {
	int result; // eax

	if (*getMemU32Ptr(0x5D4594, 2598000) - dword_5d4594_528264 <=
		(unsigned int)(3600 * *getMemU32Ptr(0x5D4594, 2649704))) {
		result = dword_5d4594_528252;
		if (dword_5d4594_528252) {
			result = dword_5d4594_528256;
			if (!dword_5d4594_528256) {
				sub_413D30((char*)getMemAt(0x587000, 58968));
				sub_40E090();
				result = sub_41FDE0();
				if (result == 1)
					dword_5d4594_528256 = 1;
				else
					result = sub_41E470();
			}
		}
	} else {
		sub_41E370();
		result = sub_41E4B0(1);
	}
	return result;
}

//----- (0041E400) --------------------------------------------------------
void sub_41E400() {
	if (dword_5d4594_528252 != 1 && dword_5d4594_528256 != 1) {
		if (!dword_5d4594_528260) {
			if (!dword_5d4594_528264) {
				sub_413D30((char*)getMemAt(0x587000, 59000), *getMemU32Ptr(0x5D4594, 2598000));
				dword_5d4594_528252 = 1;
				dword_5d4594_528256 = 0;
				dword_5d4594_528264 = *getMemU32Ptr(0x5D4594, 2598000);
				dword_5d4594_528260 = *getMemU32Ptr(0x5D4594, 2598000) + 120 * *getMemU32Ptr(0x5D4594, 2649704);
			}
		}
	}
}

//----- (0041E470) --------------------------------------------------------
int sub_41E470() {
	int result; // eax

	sub_413D30((char*)getMemAt(0x587000, 59048), *getMemU32Ptr(0x5D4594, 2598000));
	dword_5d4594_528256 = 0;
	result = *getMemU32Ptr(0x5D4594, 2598000) + 120 * *getMemU32Ptr(0x5D4594, 2649704);
	dword_5d4594_528260 = *getMemU32Ptr(0x5D4594, 2598000) + 120 * *getMemU32Ptr(0x5D4594, 2649704);
	return result;
}

//----- (0041E4B0) --------------------------------------------------------
int __cdecl sub_41E4B0(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 528268) = a1;
	return result;
}

//----- (0041E4C0) --------------------------------------------------------
int sub_41E4C0() { return *getMemU32Ptr(0x5D4594, 528268); }

//----- (0041E4D0) --------------------------------------------------------
void __cdecl sub_41E4D0(_DWORD* a1) {
	_DWORD* v1; // ebx
	_DWORD* i;  // ebp
	_DWORD* v3; // eax

	v1 = a1;
	for (i = 0; v1; v1 = (_DWORD*)v1[3]) {
		v3 = malloc(0x2D4u);
		if (v3) {
			memcpy(v3, v1, 0x2D4u);
			v3[3] = 0;
			if (i)
				i[3] = v3;
			else
				dword_5d4594_528272 = v3;
			i = v3;
		}
	}
}

//----- (0041E520) --------------------------------------------------------
int sub_41E520() {
	int result; // eax

	result = dword_5d4594_528272;
	if (dword_5d4594_528272)
		dword_5d4594_528272 = *(_DWORD*)(dword_5d4594_528272 + 12);
	return result;
}

//----- (0041E540) --------------------------------------------------------
BOOL sub_41E540() { return dword_5d4594_528272 != 0; }

//----- (0041E560) --------------------------------------------------------
int __cdecl sub_41E560(int a1, int a2, int a3, int a4) {
	int result; // eax

	*getMemU32Ptr(0x5D4594, 528276) = a1;
	result = a4;
	*getMemU32Ptr(0x5D4594, 528280) = a2;
	*getMemU32Ptr(0x5D4594, 528284) = a3;
	*getMemU32Ptr(0x5D4594, 528288) = a4;
	return result;
}

//----- (0041E590) --------------------------------------------------------
_DWORD* __cdecl sub_41E590(_DWORD* a1, _DWORD* a2, _DWORD* a3, _DWORD* a4) {
	_DWORD* result; // eax

	*a1 = *getMemU32Ptr(0x5D4594, 528276);
	*a2 = *getMemU32Ptr(0x5D4594, 528280);
	result = a4;
	*a3 = *getMemU32Ptr(0x5D4594, 528284);
	*a4 = *getMemU32Ptr(0x5D4594, 528288);
	return result;
}

//----- (0041E5C0) --------------------------------------------------------
int __cdecl sub_41E5C0(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x587000, 59168) = a1;
	return result;
}

//----- (0041E6C0) --------------------------------------------------------
_DWORD* __cdecl sub_41E6C0(char* a1) {
	int v1;     // edi
	_DWORD* v2; // esi

	v1 = dword_5d4594_529316;
	if (!dword_5d4594_529316)
		return 0;
	while (1) {
		v2 = *(_DWORD**)(v1 + 28);
		if (v2)
			break;
	LABEL_5:
		v1 = *(_DWORD*)(v1 + 36);
		if (!v1)
			return 0;
	}
	while (_strcmpi(a1, (const char*)(*v2 + 52))) {
		v2 = (_DWORD*)v2[10];
		if (!v2)
			goto LABEL_5;
	}
	return (_DWORD*)v1;
}

//----- (0041E710) --------------------------------------------------------
void __cdecl sub_41E710(wchar_t* a1, int a2) {
	_DWORD* v2; // edi

	v2 = sub_41E6C0((char*)(*(_DWORD*)a1 + 52));
	if (v2[5] == sub_41F360())
		sub_4484D0(a1 + 2, *(_DWORD*)(*(_DWORD*)a1 + 12), a2);
}

//----- (0041E750) --------------------------------------------------------
int __cdecl sub_41E750(wchar_t* a1) {
	int v1; // edi
	int v2; // esi

	v1 = dword_5d4594_529316;
	if (!dword_5d4594_529316)
		return 0;
	while (1) {
		v2 = *(_DWORD*)(v1 + 28);
		if (v2)
			break;
	LABEL_5:
		v1 = *(_DWORD*)(v1 + 36);
		if (!v1)
			return 0;
	}
	while (nox_wcscmp(a1, (const wchar_t*)(v2 + 4))) {
		v2 = *(_DWORD*)(v2 + 40);
		if (!v2)
			goto LABEL_5;
	}
	return v2;
}

//----- (0041E7A0) --------------------------------------------------------
_DWORD* __cdecl sub_41E7A0(const char* a1) {
	int v1;     // edx
	_DWORD* v2; // edi

	v1 = dword_5d4594_529316;
	if (!dword_5d4594_529316)
		return 0;
	while (1) {
		v2 = *(_DWORD**)(v1 + 28);
		if (v2)
			break;
	LABEL_5:
		v1 = *(_DWORD*)(v1 + 36);
		if (!v1)
			return 0;
	}
	while (strcmp(a1, (const char*)(*v2 + 52))) {
		v2 = (_DWORD*)v2[10];
		if (!v2)
			goto LABEL_5;
	}
	return v2 + 1;
}

//----- (0041E810) --------------------------------------------------------
_DWORD* sub_41E810() {
	_DWORD* v0;     // eax
	_DWORD* v1;     // esi
	_DWORD* result; // eax
	int v3;         // ecx

	v0 = sub_41E990((char*)getMemAt(0x587000, 59620));
	v1 = v0;
	result = (_DWORD*)v0[7];
	if (result) {
		while (*(_DWORD*)(*result + 12) >= 0x19u) {
			result = (_DWORD*)result[10];
			if (!result)
				goto LABEL_4;
		}
	} else {
	LABEL_4:
		v3 = nox_common_randomInt_415FA0(0, v1[6] - 1);
		result = (_DWORD*)v1[7];
		if (result) {
			while (v3) {
				result = (_DWORD*)result[10];
				--v3;
				if (!result)
					goto LABEL_7;
			}
		} else {
		LABEL_7:
			result = 0;
		}
	}
	return result;
}

//----- (0041E870) --------------------------------------------------------
_DWORD* __cdecl sub_41E870(char* a1, _DWORD* a2) {
	int v2;         // ebx
	_DWORD* v3;     // esi
	int v4;         // edi
	_DWORD* result; // eax

	v2 = dword_5d4594_529316;
	if (!dword_5d4594_529316)
		return 0;
	while (1) {
		v3 = *(_DWORD**)(v2 + 28);
		v4 = 0;
		if (v3)
			break;
	LABEL_5:
		v2 = *(_DWORD*)(v2 + 36);
		if (!v2)
			return 0;
	}
	while (_strcmpi(a1, (const char*)(*v3 + 52))) {
		v3 = (_DWORD*)v3[10];
		++v4;
		if (!v3)
			goto LABEL_5;
	}
	result = v3;
	*a2 = v4;
	return result;
}

//----- (0041E8D0) --------------------------------------------------------
int __cdecl sub_41E8D0(int a1, int a2) {
	unsigned int v2; // eax
	unsigned int v3; // ecx

	if (!a1 || !a2)
		return 0;
	v2 = *(_DWORD*)(a1 + 16);
	v3 = *(_DWORD*)(a2 + 16);
	if (v2 > v3)
		return -1;
	if (v2 >= v3)
		return _strcmpi((const char*)(a1 + 52), (const char*)(a2 + 52));
	return 1;
}

//----- (0041E910) --------------------------------------------------------
char* __cdecl sub_41E910(char* a1) {
	char* v1; // ecx
	int v2;   // edx
	char v3;  // al

	v1 = a1;
	v2 = 0;
	if (*a1) {
		do {
			if ((unsigned __int8)*v1 < 0x80u)
				*getMemU8Ptr( 0x5D4594, v2++ + 528804) = *v1;
			v3 = *++v1;
		} while (v3);
	}
	*getMemU8Ptr( 0x5D4594, v2 + 528804) = 0;
	return (char*)getMemAt(0x5D4594, 528804);
}

//----- (0041E940) --------------------------------------------------------
_DWORD* __cdecl sub_41E940(int a1) {
	_DWORD* result; // eax

	result = *(_DWORD**)&dword_5d4594_529316;
	if (!dword_5d4594_529316)
		return 0;
	while (result[2] || result[1] != a1) {
		result = (_DWORD*)result[9];
		if (!result)
			return 0;
	}
	return result;
}

//----- (0041E970) --------------------------------------------------------
_DWORD* __cdecl sub_41E970(int a1) {
	_DWORD* result; // eax

	result = *(_DWORD**)&dword_5d4594_529316;
	if (!dword_5d4594_529316)
		return 0;
	while (result[2] != a1) {
		result = (_DWORD*)result[9];
		if (!result)
			return 0;
	}
	return result;
}

//----- (0041E990) --------------------------------------------------------
LPVOID __cdecl sub_41E990(char* a1) {
	int v1; // esi

	v1 = dword_5d4594_529316;
	if (!dword_5d4594_529316)
		return 0;
	while (_strcmpi(*(const char**)(v1 + 12), a1)) {
		v1 = *(_DWORD*)(v1 + 36);
		if (!v1)
			return 0;
	}
	return (LPVOID)v1;
}

//----- (0041E9D0) --------------------------------------------------------
int* __cdecl sub_41E9D0(int a1, const char* a2, const char* a3, int a4, int a5) {
	int* result; // eax
	int* v6;     // ebx
	char* v7;    // edx
	char* v8;    // edx

	result = 0;
	if (a2) {
		result = (int*)malloc(0x2Cu);
		v6 = result;
		if (result) {
			v7 = (char*)malloc(strlen(a2) + 1);
			v6[3] = (int)v7;
			if (v7)
				strcpy(v7, a2);
			else
				v6[3] = 0;
			v6[4] = 0;
			if (a3) {
				v8 = (char*)malloc(strlen(a3) + 1);
				v6[4] = (int)v8;
				if (v8)
					strcpy(v8, a3);
				else
					v6[4] = 0;
			}
			*v6 = a5;
			v6[6] = 0;
			v6[7] = 0;
			v6[8] = 0;
			v6[9] = 0;
			v6[10] = 0;
			v6[1] = a1;
			v6[2] = a4;
			result = v6;
		}
	}
	return result;
}

//----- (0041EAC0) --------------------------------------------------------
int* sub_41EAC0() {
	int* v0;     // eax
	int v1;      // eax
	int* result; // eax

	dword_5d4594_529340 = 0;
	*getMemU32Ptr(0x587000, 59616) = -1;
	v0 = sub_41E9D0(0, "Chat Channels", 0, 0, 1);
	dword_5d4594_529316 = v0;
	v0[5] = 0;
	dword_5d4594_529324 = v0;
	v1 = sub_420100();
	result = sub_41E9D0(0, "Nox", 0, v1, 0);
	if (result) {
		result[9] = dword_5d4594_529316;
		if (dword_5d4594_529316)
			*(_DWORD*)(dword_5d4594_529316 + 40) = result;
		dword_5d4594_529316 = result;
		result[5] = -1;
	}
	*getMemU32Ptr(0x587000, 59616) = -1;
	dword_5d4594_529340 = 0;
	return result;
}

//----- (0041EB40) --------------------------------------------------------
int sub_41EB40() {
	int v0;     // esi
	int result; // eax
	int v2;     // edi

	v0 = dword_5d4594_529316;
	result = sub_41EC30();
	if (v0) {
		do {
			v2 = *(_DWORD*)(v0 + 36);
			if (*(_DWORD*)(v0 + 12))
				free(*(LPVOID*)(v0 + 12));
			if (*(_DWORD*)(v0 + 16))
				free(*(LPVOID*)(v0 + 16));
			free((LPVOID)v0);
			v0 = v2;
		} while (v2);
		dword_5d4594_529316 = 0;
		dword_5d4594_529340 = 0;
	} else {
		dword_5d4594_529316 = 0;
		dword_5d4594_529340 = 0;
	}
	return result;
}

//----- (0041EBB0) --------------------------------------------------------
void* __cdecl sub_41EBB0(int a1) {
	void* result; // eax
	char* v2;     // [esp-8h] [ebp-8h]

	if (a1) {
		v2 = (char*)(a1 + 52);
		a1 = 0;
		result = sub_41E870(v2, &a1);
		dword_5d4594_529340 = result;
		*getMemU32Ptr(0x587000, 59616) = a1;
		if (result)
			result = sub_446CC0((int)result + 4);
	} else {
		dword_5d4594_529340 = 0;
		result = sub_446CC0(0);
	}
	return result;
}

//----- (0041EC00) --------------------------------------------------------
int sub_41EC00() {
	int result; // eax

	if (dword_5d4594_529340)
		result = dword_5d4594_529340 + 4;
	else
		result = 0;
	return result;
}

//----- (0041EC10) --------------------------------------------------------
int sub_41EC10() {
	int result; // eax

	if (dword_5d4594_529340)
		result = *getMemU32Ptr(0x587000, 59616);
	else
		result = -1;
	return result;
}

//----- (0041EC30) --------------------------------------------------------
int sub_41EC30() {
	_DWORD* v0; // ebx
	int v1;     // esi
	int v2;     // edi
	int result; // eax
	int v4;     // eax

	v0 = *(_DWORD**)&dword_5d4594_529316;
	dword_5d4594_529332 = 0;
	dword_5d4594_529336 = 0;
	if (dword_5d4594_529316) {
		do {
			v1 = v0[7];
			if (v1) {
				do {
					v2 = *(_DWORD*)(v1 + 40);
					if (*(_DWORD*)v1)
						free(*(LPVOID*)v1);
					free((LPVOID)v1);
					v1 = v2;
				} while (v2);
			}
			v0[7] = 0;
			v0[8] = 0;
			v0[6] = 0;
			v0 = (_DWORD*)v0[9];
		} while (v0);
	}
	result = sub_41E2F0();
	if (result == 7) {
		v4 = sub_41E2F0();
		result = sub_41DA70(v4, 10);
	}
	dword_5d4594_529340 = 0;
	return result;
}

//----- (0041ECB0) --------------------------------------------------------
void __cdecl sub_41ECB0(int a1) {
	int v1;      // esi
	_DWORD* v2;  // eax
	_DWORD* v3;  // ebp
	char* v4;    // edx
	wchar_t* v5; // ebx
	int v6;      // edi
	void* v7;    // eax
	int v8;      // eax
	wchar_t* v9; // eax
	int* v10;    // esi
	int v11;     // eax
	int v12;     // [esp-4h] [ebp-1Ch]
	int v13;     // [esp+10h] [ebp-8h]
	size_t v14;  // [esp+14h] [ebp-4h]

	v1 = a1;
	v13 = 0;
	if (a1 && (sub_41E2F0() == 8 && *(_DWORD*)a1 == sub_420100() || sub_41E2F0() == 7 && !*(_DWORD*)a1)) {
		if (sub_41E2F0() == 8) {
			v12 = sub_420100();
			v2 = sub_41E970(v12);
		} else {
			v2 = sub_41E970(0);
		}
		v3 = v2;
		if (v2) {
			if (!*(_DWORD*)a1) {
				v4 = sub_420110();
				v14 = strlen(v4);
				if (strncmp((const char*)(a1 + 52), v4, v14))
					return;
				nox_sprintf((char*)(a1 + 215), "zot0blat");
			}
			v5 = (wchar_t*)malloc(0x30u);
			v6 = 0;
			if (v5) {
				v7 = malloc(0x10Cu);
				*(_DWORD*)v5 = v7;
				if (v7) {
					memcpy(v7, (const void*)a1, 0x10Cu);
					v1 = a1;
					v6 = 0;
				} else {
					*(_DWORD*)v5 = 0;
				}
				sub_41E910((char*)(v1 + 52));
				if (!*(_DWORD*)v1) {
					v8 = atoi((const char*)(v14 + v1 + 52));
					v9 = sub_4469D0(v8);
					nox_swprintf(v5 + 2, v9);
					v5[19] = 0;
				}
				v10 = (int*)v3[7];
				if (v10) {
					while (sub_41E8D0(a1, *v10) > 0) {
						v10 = (int*)v10[10];
						++v6;
						if (!v10) {
							v13 = v6;
							*(_DWORD*)(v3[8] + 40) = v5;
							*((_DWORD*)v5 + 11) = v3[8];
							*((_DWORD*)v5 + 10) = 0;
							v3[8] = v5;
							goto LABEL_24;
						}
					}
					v13 = v6;
					v11 = v10[11];
					if (v11)
						*(_DWORD*)(v11 + 40) = v5;
					else
						v3[7] = v5;
					*((_DWORD*)v5 + 11) = v10[11];
					*((_DWORD*)v5 + 10) = v10;
					v10[11] = (int)v5;
				} else {
					v3[8] = v5;
					v3[7] = v5;
					*((_DWORD*)v5 + 11) = 0;
					*((_DWORD*)v5 + 10) = 0;
				}
			LABEL_24:
				++dword_5d4594_529332;
				dword_5d4594_529336 += *(_DWORD*)(*(_DWORD*)v5 + 12);
				++v3[6];
				if (sub_41E2F0() == 7)
					sub_41E710(v5, v13);
			}
		}
	}
}
// 41EDB3: variable 'v14' is possibly undefined

//----- (0041EEA0) --------------------------------------------------------
void __cdecl sub_41EEA0(int a1) {
	_DWORD* v1; // eax
	LPVOID* v2; // edi
	_DWORD* v3; // ecx
	_DWORD* v4; // ecx
	int v5;     // [esp+10h] [ebp-4h]

	v5 = 0;
	if (a1) {
		v1 = sub_41E940(*(_DWORD*)(a1 + 16));
		if (v1) {
			v2 = (LPVOID*)v1[7];
			if (v2) {
				while (strcmp((const char*)*v2 + 52, (const char*)(a1 + 52))) {
					v2 = (LPVOID*)v2[10];
					++v5;
					if (!v2)
						return;
				}
				v3 = v2[11];
				if (v3)
					v3[10] = v2[10];
				else
					v1[7] = v2[10];
				v4 = v2[10];
				if (v4)
					v4[11] = v2[11];
				else
					v1[8] = v2[11];
				--dword_5d4594_529332;
				dword_5d4594_529336 -= *(_DWORD*)(a1 + 12);
				--v1[6];
				if (sub_41E2F0() == 7)
					sub_448550(v5);
				free(*v2);
				free(v2);
			}
		}
	}
}

//----- (0041EFB0) --------------------------------------------------------
wchar_t* __cdecl sub_41EFB0(int a1) {
	int i;           // esi
	wchar_t* result; // eax
	char v3[20];     // [esp+4h] [ebp-14h]

	sub_446970_wol_chat();
	if (dword_5d4594_529340) {
		strcpy(v3, (const char*)(**(_DWORD**)&dword_5d4594_529340 + 52));
		dword_5d4594_529340 = 0;
	} else {
		v3[0] = 0;
	}
	sub_41EC30();
	for (i = a1; i; i = *(_DWORD*)(i + 48))
		sub_41ECB0(i);
	if (v3[0]) {
		result = (wchar_t*)sub_41E870(v3, getMemAt(0x587000, 59616));
		dword_5d4594_529340 = result;
	} else {
		result = (wchar_t*)sub_41E2F0();
		if (result == (wchar_t*)7) {
			result = (wchar_t*)sub_41E810();
			dword_5d4594_529340 = result;
			if (result)
				result = (wchar_t*)sub_446A20_wol_chat(result + 2);
		}
	}
	return result;
}

//----- (0041F070) --------------------------------------------------------
wchar_t* sub_41F070() {
	wchar_t* result; // eax

	if (!dword_5d4594_529328)
		return 0;
	result = sub_41F330(dword_5d4594_529328 + 4, *(_DWORD*)(**(_DWORD**)&dword_5d4594_529328 + 12));
	dword_5d4594_529328 = *(_DWORD*)(dword_5d4594_529328 + 40);
	return result;
}

//----- (0041F0A0) --------------------------------------------------------
wchar_t* sub_41F0A0() {
	dword_5d4594_529328 = *(_DWORD*)(dword_5d4594_529324 + 28);
	return sub_41F070();
}

//----- (0041F0C0) --------------------------------------------------------
int sub_41F0C0() {
	int result; // eax

	result = 0;
	if (dword_5d4594_529328) {
		result = **(_DWORD**)&dword_5d4594_529328;
		dword_5d4594_529328 = *(_DWORD*)(dword_5d4594_529328 + 40);
	}
	return result;
}

//----- (0041F0E0) --------------------------------------------------------
int sub_41F0E0() {
	if (!dword_5d4594_529324)
		return 0;
	dword_5d4594_529328 = *(_DWORD*)(dword_5d4594_529324 + 28);
	return sub_41F0C0();
}

//----- (0041F100) --------------------------------------------------------
int __cdecl sub_41F100(char* a1) {
	int result; // eax
	_DWORD* v2; // eax

	if (a1) {
		v2 = sub_41E990(a1);
		if (v2) {
			dword_5d4594_529324 = v2;
			dword_5d4594_529328 = v2[7];
			result = 1;
		} else {
			result = 0;
		}
	} else {
		dword_5d4594_529324 = dword_5d4594_529316;
		result = 1;
	}
	return result;
}

//----- (0041F140) --------------------------------------------------------
wchar_t* __cdecl sub_41F140(wchar_t* a1) {
	wchar_t* result; // eax

	result = a1;
	if (a1) {
		result = (wchar_t*)sub_41E750(a1);
		if (result)
			result = (wchar_t*)sub_40D350(*(_DWORD*)result);
	}
	return result;
}

//----- (0041F160) --------------------------------------------------------
BOOL __cdecl sub_41F160(const char* a1) {
	BOOL result;  // eax
	char v2[268]; // [esp+4h] [ebp-10Ch]

	result = 0;
	memset(v2, 0, sizeof(v2));
	if (a1) {
		strcpy(&v2[52], a1);
		*(_DWORD*)v2 = 0;
		result = sub_40D320((int)v2);
	}
	return result;
}

//----- (0041F1C0) --------------------------------------------------------
int __cdecl sub_41F1C0(int a1) {
	_DWORD* v1; // eax

	v1 = *(_DWORD**)&dword_5d4594_529316;
	if (!dword_5d4594_529316)
		return 0;
	while (a1 != v1[5]) {
		v1 = (_DWORD*)v1[9];
		if (!v1)
			return 0;
	}
	return v1[3];
}

//----- (0041F1E0) --------------------------------------------------------
int __cdecl sub_41F1E0(int a1) {
	int v1; // ecx
	int v2; // eax

	v1 = 0;
	v2 = *(_DWORD*)(dword_5d4594_529324 + 28);
	if (!v2)
		return 0;
	while (a1 != v1) {
		v2 = *(_DWORD*)(v2 + 40);
		++v1;
		if (!v2)
			return 0;
	}
	return v2 + 4;
}

//----- (0041F210) --------------------------------------------------------
int sub_41F210() { return dword_5d4594_529336; }

//----- (0041F220) --------------------------------------------------------
int sub_41F220() { return dword_5d4594_529332; }

//----- (0041F230) --------------------------------------------------------
void __cdecl sub_41F230(int a1, int a2) {
	int v2;      // ecx
	int* v3;     // eax
	wchar_t* v4; // esi
	int v5;      // ecx
	char* v6;    // [esp-8h] [ebp-Ch]

	if (a1) {
		v6 = (char*)(a1 + 52);
		a1 = 0;
		v3 = sub_41E870(v6, &a1);
		v4 = (wchar_t*)v3;
		if (v3) {
			v5 = a2;
			*(_DWORD*)(*v3 + 12) += a2;
			dword_5d4594_529336 += v5;
			if (!*(_DWORD*)(*v3 + 12))
				sub_41EEA0(*v3);
			if (sub_41E2F0() == 7)
				sub_41E710(v4, a1);
		}
	} else if (dword_5d4594_529340) {
		v2 = a2;
		*(_DWORD*)(**(_DWORD**)&dword_5d4594_529340 + 12) += a2;
		dword_5d4594_529336 += v2;
		if (*(_DWORD*)(**(_DWORD**)&dword_5d4594_529340 + 12)) {
			if (sub_41E2F0() == 7) {
				sub_448550(*getMemIntPtr(0x587000, 59616));
				sub_41E710(*(wchar_t**)&dword_5d4594_529340, *getMemIntPtr(0x587000, 59616));
			}
		} else {
			sub_41EEA0(**(_DWORD**)&dword_5d4594_529340);
			dword_5d4594_529340 = 0;
			*getMemU32Ptr(0x587000, 59616) = -1;
		}
	}
}

//----- (0041F330) --------------------------------------------------------
wchar_t* __cdecl sub_41F330(int a1, int a2) {
	if (!a1)
		return 0;
	nox_swprintf((wchar_t*)getMemAt(0x5D4594, 528292), L"%s\t%d", a1, a2);
	return (wchar_t*)getMemAt(0x5D4594, 528292);
}

//----- (0041F360) --------------------------------------------------------
int sub_41F360() { return *(_DWORD*)(dword_5d4594_529324 + 20); }

//----- (0041F370) --------------------------------------------------------
_DWORD* __cdecl sub_41F370(int a1) {
	_DWORD* result; // eax

	result = *(_DWORD**)&dword_5d4594_529316;
	if (dword_5d4594_529316) {
		while (result[5] != a1) {
			result = (_DWORD*)result[9];
			if (!result)
				goto LABEL_4;
		}
		dword_5d4594_529324 = result;
	} else {
	LABEL_4:
		dword_5d4594_529324 = dword_5d4594_529316;
	}
	return result;
}

//----- (0041F440) --------------------------------------------------------
void __cdecl sub_41F440(int a1, char a2, int a3) { sub_448570((const char*)(*(_DWORD*)a1 + 36), a2, a3); }

//----- (0041F460) --------------------------------------------------------
int __cdecl sub_41F460(int a1, int a2) {
	int v2; // ecx

	if (!a1 || !a2)
		return 0;
	v2 = *(_DWORD*)a2 & 1;
	if ((*(_DWORD*)a1 & 1) == 1) {
		if (!v2)
			return -1;
	} else if (v2 == 1) {
		return 1;
	}
	return _strcmpi((const char*)(a1 + 36), (const char*)(a2 + 36));
}

//----- (0041F4B0) --------------------------------------------------------
int sub_41F4B0() {
	int v0;     // esi
	int v1;     // edi
	int result; // eax
	int v3;     // eax

	v0 = dword_5d4594_531648;
	if (dword_5d4594_531648) {
		do {
			v1 = *(_DWORD*)(v0 + 20);
			if (*(_DWORD*)v0)
				free(*(LPVOID*)v0);
			free((LPVOID)v0);
			v0 = v1;
		} while (v1);
	}
	dword_5d4594_531648 = 0;
	dword_5d4594_531652 = 0;
	dword_5d4594_531656 = 0;
	result = sub_41E2F0();
	if (result == 7) {
		v3 = sub_41E2F0();
		result = sub_41DA70(v3, 11);
	}
	return result;
}

//----- (0041F520) --------------------------------------------------------
void __cdecl sub_41F520(const char* a1) {
	_DWORD* v1; // ebx
	char* v2;   // eax
	int* v3;    // esi
	int v4;     // edi
	int v5;     // eax

	v1 = malloc(0x1Cu);
	if (v1) {
		v2 = (char*)malloc(0x6Cu);
		*v1 = v2;
		if (v2)
			memcpy(v2, a1, 0x6Cu);
		else
			*v1 = 0;
		v1[4] = sub_427880(a1 + 36);
		v3 = *(int**)&dword_5d4594_531648;
		v4 = 0;
		if (dword_5d4594_531648) {
			while (sub_41F460((int)a1, *v3) > 0) {
				v3 = (int*)v3[5];
				++v4;
				if (!v3)
					goto LABEL_9;
			}
			if (!v3) {
			LABEL_9:
				*(_DWORD*)(dword_5d4594_531652 + 20) = v1;
				v1[6] = dword_5d4594_531652;
				v1[5] = 0;
				dword_5d4594_531652 = v1;
				goto LABEL_10;
			}
			v5 = v3[6];
			if (v5)
				*(_DWORD*)(v5 + 20) = v1;
			else
				dword_5d4594_531648 = v1;
			v1[6] = v3[6];
			v1[5] = v3;
			v3[6] = (int)v1;
		LABEL_10:
			if (sub_41E2F0() == 7)
				sub_41F440((int)v1, *(_DWORD*)*v1, v4);
		} else {
			dword_5d4594_531652 = v1;
			dword_5d4594_531648 = v1;
			v1[6] = 0;
			v1[5] = 0;
		}
	}
}

//----- (0041F6F0) --------------------------------------------------------
void __cdecl sub_41F6F0(int a1) {
	int i; // esi

	sub_41F4B0();
	for (i = a1; i; i = *(_DWORD*)(i + 32))
		sub_41F520((const char*)i);
}

//----- (0041F710) --------------------------------------------------------
char* sub_41F710() {
	char* result; // eax

	if (!dword_5d4594_531656)
		return 0;
	result = sub_41F740(**(_DWORD**)&dword_5d4594_531656 + 36, ***(_DWORD***)&dword_5d4594_531656);
	dword_5d4594_531656 = *(_DWORD*)(dword_5d4594_531656 + 20);
	return result;
}

//----- (0041F740) --------------------------------------------------------
char* __cdecl sub_41F740(int a1, char a2) {
	if (!a1)
		return 0;
	nox_sprintf((char*)getMemAt(0x5D4594, 531392), "%c%s", (a2 & 1) != 0 ? 64 : 32, a1);
	return (char*)getMemAt(0x5D4594, 531392);
}

//----- (0041F780) --------------------------------------------------------
char* sub_41F780() {
	dword_5d4594_531656 = dword_5d4594_531648;
	return sub_41F710();
}

//----- (0041F790) --------------------------------------------------------
_DWORD* __cdecl sub_41F790(const char* a1) {
	_DWORD* v1; // edi

	v1 = *(_DWORD**)&dword_5d4594_531648;
	if (!a1 || !dword_5d4594_531648)
		return 0;
	while (strcmp((const char*)(*v1 + 36), a1)) {
		v1 = (_DWORD*)v1[5];
		if (!v1)
			return 0;
	}
	return v1;
}

//----- (0041F800) --------------------------------------------------------
int __cdecl sub_41F800(const char* a1) {
	int* v1;    // eax
	int result; // eax

	v1 = sub_41F790(a1);
	if (v1)
		result = *v1;
	else
		result = 0;
	return result;
}

//----- (0041F820) --------------------------------------------------------
void __cdecl sub_41F820(const char* a1) {
	sub_41F620((int)a1);
	sub_41F520(a1);
}

//----- (0041F840) --------------------------------------------------------
_DWORD* __cdecl sub_41F840(const char* a1, int a2) {
	_DWORD* result; // eax

	result = a1;
	if (a1) {
		result = sub_41F790(a1);
		if (result) {
			result = (_DWORD*)*result;
			*result = a2;
		}
	}
	return result;
}

//----- (0041F860) --------------------------------------------------------
BOOL __cdecl sub_41F860(const char* a1, wchar_t* a2) {
	const char* v2; // eax
	_DWORD* v3;     // eax
	char v5[108];   // [esp+8h] [ebp-6Ch]

	memset(v5, 0, sizeof(v5));
	v2 = a1;
	if (!a1 || !a2)
		return 0;
	if (*a1 == 64 || *a1 == 32)
		v2 = a1 + 1;
	v3 = sub_41F790(v2);
	if (!v3)
		return 0;
	strcpy(&v5[36], (const char*)(*v3 + 36));
	sub_448680(a2, (char*)getMemAt(0x5D4594, 529344));
	return sub_40D410((int)v5, (int)getMemAt(0x5D4594, 529344));
}

//----- (0041F8F0) --------------------------------------------------------
BOOL __cdecl sub_41F8F0(const char* a1, wchar_t* a2) {
	const char* v2; // eax
	_DWORD* v3;     // eax
	char v5[108];   // [esp+8h] [ebp-6Ch]

	memset(v5, 0, sizeof(v5));
	v2 = a1;
	if (!a1 || !a2)
		return 0;
	if (*a1 == 64 || *a1 == 32)
		v2 = a1 + 1;
	v3 = sub_41F790(v2);
	if (!v3)
		return 0;
	strcpy(&v5[36], (const char*)(*v3 + 36));
	sub_448680(a2, (char*)getMemAt(0x5D4594, 529344));
	return sub_40D500((int)v5, (int)getMemAt(0x5D4594, 529344));
}

//----- (0041F980) --------------------------------------------------------
_DWORD* __cdecl sub_41F980(const char* a1, int a2) {
	_DWORD* result; // eax

	result = sub_41F790(a1);
	if (result)
		result[4] = a2;
	return result;
}

//----- (0041F9A0) --------------------------------------------------------
int sub_41F9A0() {
	int v0;  // edi
	int v1;  // eax
	int v2;  // esi
	char v4; // [esp+8h] [ebp-8h]
	char v5; // [esp+Ch] [ebp-4h]

	v0 = 0;
	v1 = 0;
	do {
		v2 = v1 + 1;
		if (!sub_40D980(v1 + 1, (int)&v5, (int)&v4))
			break;
		v1 = v2;
		++v0;
	} while (v2 < 128);
	return v0;
}

//----- (0041F9E0) --------------------------------------------------------
BOOL __cdecl sub_41F9E0(int a1) { return strcmp((const char*)getMemAt(0x5D4594, 534756), (const char*)(a1 + 36)) == 0; }

//----- (0041FA40) --------------------------------------------------------
char* sub_41FA40() { return (char*)getMemAt(0x5D4594, 534756); }

//----- (0041FA50) --------------------------------------------------------
void __cdecl sub_41FA50(const char* a1) {
	if (a1)
		strcpy((char*)getMemAt(0x5D4594, 534756), a1);
}

//----- (0041FA80) --------------------------------------------------------
int __cdecl sub_41FA80(const char* a1) {
	int result; // eax

	if (!a1 || strlen(a1) >= 0xA || *(int*)&dword_587000_60044 == -1)
		return 0;
	result = 1;
	strcpy((char*)getMemAt(0x5D4594, 24 * dword_587000_60044 + 531660), a1);
	return result;
}

//----- (0041FAE0) --------------------------------------------------------
int __cdecl sub_41FAE0(const char* a1) {
	int v1;     // esi
	int v2;     // eax
	int result; // eax

	v1 = 0;
	if (*a1) {
		if (a1 && strlen(a1) < 0xA && *(int*)&dword_587000_60044 != -1) {
			strcpy((char*)getMemAt(0x5D4594, 24 * dword_587000_60044 + 531670), a1);
			v1 = 1;
		}
		result = v1;
	} else {
		v2 = 24 * dword_587000_60044;
		*getMemU8Ptr( 0x5D4594, v2 + 531670) = 0;
		*getMemU32Ptr(0x5D4594, v2 + 531680) = 0;
		result = 1;
	}
	return result;
}

//----- (0041FB60) --------------------------------------------------------
int sub_41FB60() { return *getMemU32Ptr(0x5D4594, 24 * dword_587000_60044 + 531680); }

//----- (0041FB70) --------------------------------------------------------
int __cdecl sub_41FB70(int a1) {
	int result; // eax

	result = 3 * dword_587000_60044;
	*getMemU32Ptr(0x5D4594, 24 * dword_587000_60044 + 531680) = a1;
	return result;
}

//----- (0041FB90) --------------------------------------------------------
int __cdecl sub_41FB90(int a1, _DWORD* a2, _DWORD* a3) {
	int result; // eax

	if (a1 < 0 || a1 >= 128) {
		*a2 = 0;
		*a3 = 0;
		result = 0;
	} else {
		*a2 = getMemAt(0x5D4594, 24 * a1 + 531660);
		*a3 = getMemAt(0x5D4594, 24 * a1 + 531670);
		result = 1;
	}
	return result;
}

//----- (0041FBE0) --------------------------------------------------------
int __cdecl sub_41FBE0(_DWORD* a1, _DWORD* a2) {
	int result; // eax

	if (*(int*)&dword_587000_60044 == -1)
		return 0;
	*a1 = getMemAt(0x5D4594, 24 * dword_587000_60044 + 531660);
	result = 1;
	*a2 = getMemAt(0x5D4594, 24 * dword_587000_60044 + 531670);
	return result;
}

//----- (0041FC20) --------------------------------------------------------
int __cdecl sub_41FC20(int a1) {
	if (a1 < 0 || a1 > 128)
		return 0;
	dword_587000_60044 = a1;
	return 1;
}

//----- (0041FC40) --------------------------------------------------------
int sub_41FC40() { return dword_587000_60044; }

//----- (0041FC50) --------------------------------------------------------
int sub_41FC50() {
	int result; // eax

	result = 0;
	if (*(int*)&dword_587000_60044 != -1) {
		result = sub_40D9C0(dword_587000_60044 + 1, (int)getMemAt(0x5D4594, 24 * dword_587000_60044 + 531660),
							(int)getMemAt(0x5D4594, 24 * dword_587000_60044 + 531670),
							*getMemU32Ptr(0x5D4594, 24 * dword_587000_60044 + 531680) == 0);
		if (result)
			result = sub_41FCF0();
	}
	return result;
}

//----- (0041FCA0) --------------------------------------------------------
int __cdecl sub_41FCA0(const char* a1, const char* a2) {
	int v2; // eax

	v2 = sub_41F9A0();
	if (!sub_41FC20(v2))
		return 0;
	sub_41FA80(a1);
	sub_41FAE0(a2);
	*getMemU32Ptr(0x5D4594, 24 * dword_587000_60044 + 531680) = 0;
	sub_41FC50();
	return 1;
}

//----- (0041FCF0) --------------------------------------------------------
int sub_41FCF0() {
	int v0;              // eax
	unsigned __int8* v1; // ebp
	int v2;              // ebx
	const char* v3;      // edx
	int v4;              // eax
	const char* v6;      // [esp+10h] [ebp-8h]
	const char* v7;      // [esp+14h] [ebp-4h]

	v0 = 0;
	dword_5d4594_534768 = 0;
	v1 = getMemAt(0x5D4594, 531670);
	do {
		v2 = v0 + 1;
		if (sub_40D980(v0 + 1, (int)&v6, (int)&v7)) {
			v3 = v7;
			strcpy((char*)v1 - 10, v6);
			strcpy((char*)v1, v3);
			v4 = dword_5d4594_534768;
			if (*v3)
				*(_DWORD*)(v1 + 10) = 1;
			else
				*(_DWORD*)(v1 + 10) = 0;
			dword_5d4594_534768 = v4 + 1;
		} else {
			*(v1 - 10) = 0;
			*v1 = 0;
			*(_DWORD*)(v1 + 10) = 0;
		}
		v1 += 24;
		v0 = v2;
	} while ((int)v1 <= (int)getMemAt(0x5D4594, 534742));
	if (!dword_5d4594_534768)
		sub_41FC20(0);
	return 1;
}

//----- (0041FDE0) --------------------------------------------------------
int sub_41FDE0() {
	int v0;         // ebx
	size_t v1;      // eax
	const char* v3; // [esp+8h] [ebp-8h]
	const char* v4; // [esp+Ch] [ebp-4h]

	memset(getMemAt(0x5D4594, 2660012), 0, 0x6Cu);
	if (sub_41FBE0(&v3, &v4) != 1)
		return 0;
	v0 = sub_4207E0();
	if (v0) {
		strcpy((char*)(v0 + 228), v3);
		strcpy((char*)(v0 + 238), v4);
		sub_40D2C0(v0, 30, 0);
		sub_41FA50(v3);
		v1 = strcspn((const char*)(v0 + 24), ":");
		if (!strncmp("Official", (const char*)(v1 + v0 + 25), 8u))
			sub_40A4D0(0x1000000);
		else
			nox_common_gameFlags_unset_40A540(0x1000000);
	}
	if (!dword_5d4594_830276)
		sub_41FEE0();
	return 1;
}

//----- (0041FEE0) --------------------------------------------------------
BOOL sub_41FEE0() {
	sub_40D9C0(dword_587000_60044 + 1, (int)getMemAt(0x5D4594, 534776), (int)getMemAt(0x5D4594, 534772), 0);
	return sub_40DB80(dword_587000_60044 + 1, 0);
}

//----- (0041FF10) --------------------------------------------------------
int sub_41FF10() {
	sub_40D440();
	sub_41F4B0();
	sub_41EC30();
	sub_446490(0);
	return 1;
}

//----- (0041FF30) --------------------------------------------------------
void __cdecl sub_41FF30(const void* a1) {
	if (a1)
		sub_446520(0, a1, strlen((const char*)a1) + 1);
}

//----- (0041FF60) --------------------------------------------------------
int sub_41FF60() { return *getMemU32Ptr(0x5D4594, 534800); }

//----- (0041FF70) --------------------------------------------------------
BOOL __cdecl sub_41FF70(int a1) {
	*getMemU32Ptr(0x5D4594, 534800) = a1;
	return sub_40D890(a1);
}

//----- (0041FF90) --------------------------------------------------------
int sub_41FF90() { return dword_587000_60064; }

//----- (0041FFA0) --------------------------------------------------------
BOOL __cdecl sub_41FFA0(int a1) {
	dword_587000_60064 = a1;
	return sub_40D7A0(a1, *(int*)&dword_587000_60068);
}

//----- (0041FFC0) --------------------------------------------------------
int sub_41FFC0() { return dword_587000_60068; }

//----- (0041FFD0) --------------------------------------------------------
BOOL __cdecl sub_41FFD0(int a1) {
	dword_587000_60068 = a1;
	return sub_40D7A0(*(int*)&dword_587000_60064, a1);
}

//----- (0041FFF0) --------------------------------------------------------
BOOL sub_41FFF0() {
	sub_40D890(*getMemIntPtr(0x5D4594, 534800));
	return sub_40D7A0(*(int*)&dword_587000_60064, *(int*)&dword_587000_60068);
}

//----- (00420020) --------------------------------------------------------
int sub_420020() { return 65540; }

//----- (00420030) --------------------------------------------------------
LSTATUS sub_420030() {
	LSTATUS result;   // eax
	HKEY phkResult;   // [esp+8h] [ebp-90h]
	DWORD Type;       // [esp+Ch] [ebp-8Ch]
	BYTE Data[4];     // [esp+10h] [ebp-88h]
	DWORD cbData;     // [esp+14h] [ebp-84h]
	CHAR SubKey[128]; // [esp+18h] [ebp-80h]

	strcpy(SubKey, "SOFTWARE\\Westwood\\Nox");
	cbData = 4;
	*getMemU32Ptr(0x587000, 60072) = -1;
	result = RegOpenKeyExA(HKEY_LOCAL_MACHINE, SubKey, 0, 0xF003Fu, &phkResult);
	if (!result) {
		if (!RegQueryValueExA(phkResult, (LPCSTR)getMemAt(0x587000, 60100), 0, &Type, Data, &cbData) && Type == 4) {
			*getMemU32Ptr(0x587000, 60072) = *(_DWORD*)Data;
			nox_sprintf((char*)getMemAt(0x5D4594, 534780), "%s%d_", getMemAt(0x587000, 60104), *(_DWORD*)Data >> 8);
		}
		result = RegCloseKey(phkResult);
	}
	return result;
}

//----- (004200E0) --------------------------------------------------------
int sub_4200E0() { return *getMemU32Ptr(0x587000, 60072); }

//----- (004200F0) --------------------------------------------------------
int sub_4200F0() { return getMemByte(0x587000, 60072) & 0xF; }

//----- (00420100) --------------------------------------------------------
int sub_420100() { return *getMemU32Ptr(0x587000, 60072) >> 8; }

//----- (00420110) --------------------------------------------------------
char* sub_420110() { return (char*)getMemAt(0x5D4594, 534780); }

//----- (00420120) --------------------------------------------------------
int __cdecl sub_420120(LPBYTE lpData) {
	int v1;           // ebx
	HKEY phkResult;   // [esp+Ch] [ebp-8Ch]
	DWORD cbData;     // [esp+10h] [ebp-88h]
	DWORD Type;       // [esp+14h] [ebp-84h]
	CHAR SubKey[128]; // [esp+18h] [ebp-80h]
	DWORD res;

	strcpy(SubKey, "SOFTWARE\\Westwood\\Nox");
	v1 = 0;
	cbData = 23;
	res = RegOpenKeyExA(HKEY_LOCAL_MACHINE, SubKey, 0, 0xF003Fu, &phkResult);
	if (!res) {
		res = RegQueryValueExA(phkResult, (LPCSTR)getMemAt(0x587000, 60144), 0, &Type, lpData, &cbData);
		if (!res && Type == 1)
			v1 = 1;
		RegCloseKey(phkResult);
	}
	return v1;
}

//----- (004201B0) --------------------------------------------------------
void __cdecl sub_4201B0(_DWORD* a1) {
	_DWORD* i;  // ebx
	_DWORD* v2; // eax

	for (i = a1; i; i = (_DWORD*)i[5]) {
		v2 = malloc(0xF8u);
		if (v2) {
			memcpy(v2, i, 0xF8u);
			v2[5] = 0;
			if (dword_5d4594_534808)
				v2[5] = dword_5d4594_534808;
			dword_5d4594_534808 = v2;
		}
	}
}

//----- (00420200) --------------------------------------------------------
LPVOID sub_420200() {
	int v0; // esi

	v0 = dword_5d4594_534808;
	if (!dword_5d4594_534808)
		return 0;
	while (_strcmpi((const char*)(v0 + 24), "chat server")) {
		v0 = *(_DWORD*)(v0 + 20);
		if (!v0)
			return 0;
	}
	return (LPVOID)v0;
}

//----- (00420230) --------------------------------------------------------
int __cdecl sub_420230(char* a1, _WORD* a2) {
	int v2;       // ebx
	char* v3;     // eax
	char* v4;     // eax
	CHAR v6[128]; // [esp+10h] [ebp-80h]

	if (!a1)
		return 0;
	if (!a2)
		return 0;
	v2 = dword_5d4594_534808;
	if (!dword_5d4594_534808)
		return 0;
	while (1) {
		if (!_strcmpi((const char*)(v2 + 95), "LAD")) {
			strcpy(v6, (const char*)(v2 + 100));
			*a1 = 0;
			*a2 = 0;
			strtok(v6, ";");
			v3 = strtok(0, ";");
			if (v3)
				strcpy(a1, v3);
			v4 = strtok(0, ";");
			if (v4)
				*a2 = atoi(v4);
			if (*a1 && *a2)
				break;
		}
		v2 = *(_DWORD*)(v2 + 20);
		if (!v2)
			return 0;
	}
	return 1;
}

//----- (00420360) --------------------------------------------------------
int __cdecl sub_420360(char* a1, _WORD* a2) {
	int v2;       // ebx
	char* v3;     // eax
	char* v4;     // eax
	char* v5;     // eax
	char v7[128]; // [esp+10h] [ebp-80h]

	if (!a1)
		return 0;
	if (!a2)
		return 0;
	*a1 = 0;
	*a2 = 0;
	v2 = dword_5d4594_534808;
	if (!dword_5d4594_534808)
		return 0;
	while (_strcmpi((const char*)(v2 + 95), "GAM")) {
	LABEL_19:
		v2 = *(_DWORD*)(v2 + 20);
		if (!v2)
			return 0;
	}
	if (nox_common_gameFlags_check_40A5C0(4096)) {
		if (!_strcmpi((const char*)(v2 + 24), "Quest gameres server")) {
			strcpy(v7, (const char*)(v2 + 100));
			*a1 = 0;
			*a2 = 0;
			strtok(v7, ";");
			v3 = strtok(0, ";");
			if (v3)
				strcpy(a1, v3);
			v4 = strtok(0, ";");
			if (v4) {
			LABEL_16:
				*a2 = atoi(v4);
				goto LABEL_17;
			}
		}
	} else {
		if (!nox_common_gameFlags_check_40A5C0(0x2000))
			return 0;
		if (!_strcmpi((const char*)(v2 + 24), "Gameres server")) {
			strcpy(v7, (const char*)(v2 + 100));
			*a1 = 0;
			*a2 = 0;
			strtok(v7, ";");
			v5 = strtok(0, ";");
			if (v5)
				strcpy(a1, v5);
			v4 = strtok(0, ";");
			if (v4)
				goto LABEL_16;
		}
	}
LABEL_17:
	if (!*a1 || !*a2)
		goto LABEL_19;
	return 1;
}

//----- (00420580) --------------------------------------------------------
_DWORD* sub_420580() {
	_DWORD* result; // eax
	_DWORD* v1;     // esi

	result = *(_DWORD**)&dword_5d4594_534808;
	if (dword_5d4594_534808) {
		do {
			v1 = (_DWORD*)result[5];
			free(result);
			result = v1;
		} while (v1);
		dword_5d4594_534808 = 0;
	} else {
		dword_5d4594_534808 = 0;
	}
	return result;
}

//----- (004205B0) --------------------------------------------------------
const char* __cdecl sub_4205B0(int a1) {
	int v1;         // ebx
	const char* v2; // edi
	int v3;         // eax
	char* v4;       // eax
	char* v5;       // eax
	char v7[68];    // [esp+10h] [ebp-44h]

	v1 = dword_5d4594_534808;
	*getMemU32Ptr(0x5D4594, 534804) = a1;
	if (!dword_5d4594_534808)
		return 0;
	while (1) {
		if (!_strcmpi((const char*)(v1 + 95), "IRC")) {
			v2 = (const char*)(v1 + 24);
			v3 = isdigit(*(unsigned __int8*)v2);
			if (v3) {
				strcpy(v7, v2);
				v4 = strtok(v7, ":");
				if (v4) {
					v5 = strtok(v4, ",");
					if (v5)
						break;
				}
			}
		}
	LABEL_11:
		v1 = *(_DWORD*)(v1 + 20);
		if (!v1)
			return 0;
	}
	while (atoi(v5) != a1) {
		v5 = strtok(0, ",");
		if (!v5)
			goto LABEL_11;
	}
	return (const char*)v1;
}

//----- (004206B0) --------------------------------------------------------
int __cdecl sub_4206B0(int a1) {
	int v1;         // ebx
	const char* v2; // edi
	int v3;         // eax
	char* v4;       // eax
	char* v5;       // eax
	char v7[68];    // [esp+Ch] [ebp-44h]

	v1 = *(_DWORD*)(a1 + 20);
	if (!v1)
		return 0;
	while (1) {
		if (!_strcmpi((const char*)(v1 + 95), "IRC")) {
			v2 = (const char*)(v1 + 24);
			v3 = isdigit(*(unsigned __int8*)v2);
			if (v3) {
				strcpy(v7, v2);
				v4 = strtok(v7, ":");
				if (v4) {
					v5 = strtok(v4, ",");
					if (v5)
						break;
				}
			}
		}
	LABEL_11:
		v1 = *(_DWORD*)(v1 + 20);
		if (!v1)
			return 0;
	}
	while (atoi(v5) != *getMemU32Ptr(0x5D4594, 534804)) {
		v5 = strtok(0, ",");
		if (!v5)
			goto LABEL_11;
	}
	return v1;
}

//----- (004207A0) --------------------------------------------------------
int __cdecl sub_4207A0(int a1) {
	int v1;        // esi
	const char* i; // eax

	v1 = 0;
	for (i = sub_4205B0(a1); i; i = (const char*)sub_4206B0((int)i))
		++v1;
	return v1;
}

//----- (004207D0) --------------------------------------------------------
int __cdecl sub_4207D0(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 534812) = a1;
	return result;
}

//----- (004207E0) --------------------------------------------------------
int sub_4207E0() { return *getMemU32Ptr(0x5D4594, 534812); }

//----- (004207F0) --------------------------------------------------------
void __cdecl sub_4207F0(int a1) {
	void (*v1)(void); // eax
	void (*v2)(void); // eax

	if (a1 < 7) {
		v1 = *(void (**)(void)) getMemAt(0x587000, 8 * *getMemU32Ptr(0x5D4594, 2659992) + 60280);
		if (v1)
			v1();
		v2 = *(void (**)(void)) getMemAt(0x587000, 8 * a1 + 60284);
		*getMemU32Ptr(0x5D4594, 2659992) = a1;
		if (v2)
			v2();
	}
}

//----- (00420830) --------------------------------------------------------
void __cdecl sub_420830(_DWORD* a1) {
	_DWORD* v1; // esi
	_DWORD* v2; // eax

	if (dword_5d4594_534816) {
		v1 = (_DWORD*)*a1;
		if (*a1) {
			do {
				if (*v1)
					(*(void(__cdecl**)(_DWORD)) & dword_5d4594_534816)(*v1);
				*v1 = 0;
				v1[1] = 0;
				v1 = (_DWORD*)v1[3];
			} while (v1);
		}
	}
	v2 = (_DWORD*)a1[3];
	*a1 = 0;
	a1[1] = 0;
	a1[2] = 0;
	a1[4] = 0;
	a1[5] = 0;
	sub_4144D0(v2);
}

//----- (00420890) --------------------------------------------------------
_DWORD* __cdecl sub_420890(int a1, int a2) {
	_DWORD* v2;     // esi
	_DWORD* result; // eax
	char* v4;       // eax

	v2 = malloc(0x20u);
	if (!v2)
		return 0;
	v4 = nox_new_alloc_class("CreateMsgList", 16, a1);
	v2[3] = v4;
	if (!v4)
		return 0;
	*v2 = 0;
	v2[1] = 0;
	v2[2] = 0;
	v2[4] = 0;
	v2[5] = 0;
	result = v2;
	dword_5d4594_534816 = a2;
	return result;
}

//----- (004208F0) --------------------------------------------------------
void __cdecl sub_4208F0(LPVOID lpMem) {
	_DWORD* v1; // esi

	if (dword_5d4594_534816) {
		v1 = *(_DWORD**)lpMem;
		if (*(_DWORD*)lpMem) {
			do {
				if (*v1)
					(*(void(__cdecl**)(_DWORD)) & dword_5d4594_534816)(*v1);
				v1 = (_DWORD*)v1[3];
			} while (v1);
		}
	}
	nox_free_alloc_class(*((LPVOID*)lpMem + 3));
	free(lpMem);
}

//----- (00420940) --------------------------------------------------------
int __cdecl sub_420940(int a1, int a2, int a3, int a4) {
	_DWORD* v4; // eax
	int v6;     // ecx
	int v7;     // ecx
	int v8;     // eax

	// dprintf("len %d: %08X %08X", a3, ((_DWORD*)a2)[0], ((_DWORD*)a2)[1]);

	v4 = nox_alloc_class_new_obj_zero(*(_DWORD**)(a1 + 12));
	if (!v4)
		return 0;
	*v4 = a2;
	v4[1] = a3;
	if (a4) {
		v6 = *(_DWORD*)(a1 + 4);
		v4[3] = 0;
		v4[2] = v6;
		v7 = *(_DWORD*)(a1 + 4);
		if (v7)
			*(_DWORD*)(v7 + 12) = v4;
		else
			*(_DWORD*)a1 = v4;
		*(_DWORD*)(a1 + 4) = v4;
	} else {
		v4[2] = 0;
		v4[3] = *(_DWORD*)a1;
		if (*(_DWORD*)a1)
			*(_DWORD*)(*(_DWORD*)a1 + 8) = v4;
		else
			*(_DWORD*)(a1 + 4) = v4;
		*(_DWORD*)a1 = v4;
	}
	v8 = *(_DWORD*)(a1 + 20);
	++*(_DWORD*)(a1 + 16);
	*(_DWORD*)(a1 + 20) = a3 + v8;
	return 1;
}

//----- (004209C0) --------------------------------------------------------
void __cdecl sub_4209C0(int a1, _QWORD* a2) { sub_414330(*(unsigned int**)(a1 + 12), a2); }

//----- (004209E0) --------------------------------------------------------
void __cdecl sub_4209E0(int* a1, int a2) {
	int v2; // eax
	int v3; // esi
	int v4; // edx
	int v5; // edx

	v2 = *a1;
	if (*a1) {
		while (*(_DWORD*)v2 != a2) {
			v2 = *(_DWORD*)(v2 + 12);
			if (!v2)
				return;
		}
		if (v2) {
			v3 = a1[5];
			--a1[4];
			a1[5] = v3 - *(_DWORD*)(v2 + 4);
			v4 = *(_DWORD*)(v2 + 12);
			if (v4)
				*(_DWORD*)(v4 + 8) = *(_DWORD*)(v2 + 8);
			else
				a1[1] = *(_DWORD*)(v2 + 8);
			v5 = *(_DWORD*)(v2 + 8);
			if (v5)
				*(_DWORD*)(v5 + 12) = *(_DWORD*)(v2 + 12);
			else
				*a1 = *(_DWORD*)(v2 + 12);
			sub_4209C0((int)a1, (_QWORD*)v2);
		}
	}
}

//----- (00420A60) --------------------------------------------------------
_DWORD* __cdecl sub_420A60(_DWORD* a1, int(__cdecl* a2)(_DWORD, int), int a3) {
	_DWORD* result; // eax
	_DWORD* v4;     // esi

	result = (_DWORD*)*a1;
	if (*a1) {
		do {
			v4 = (_DWORD*)result[3];
			result = (_DWORD*)a2(*result, a3);
			if (result)
				break;
			result = v4;
		} while (v4);
	}
	return result;
}

//----- (00420A90) --------------------------------------------------------
_DWORD* __cdecl sub_420A90(int a1, int ListSizePtr) {
	_DWORD* result; // eax
	int v3;         // esi
	int v4;         // edx
	int v5;         // edx
	_DWORD* v6;     // esi

	result = *(_DWORD**)a1;
	if (*(_DWORD*)a1) {
		*(_DWORD*)ListSizePtr = result[1];
		v3 = *(_DWORD*)(a1 + 20);
		--*(_DWORD*)(a1 + 16);
		*(_DWORD*)(a1 + 20) = v3 - result[1];
		v4 = result[3];
		if (v4)
			*(_DWORD*)(v4 + 8) = result[2];
		else
			*(_DWORD*)(a1 + 4) = result[2];
		v5 = result[2];
		if (v5)
			*(_DWORD*)(v5 + 12) = result[3];
		else
			*(_DWORD*)a1 = result[3];
		v6 = (_DWORD*)*result;
		sub_4209C0(a1, (int)result);
		result = v6;
	}
	return result;
} /*
 int **__cdecl sub_420A90(int ***a1, _DWORD *a2)
 {
   int **result; // eax
   int **v3; // esi
   int *v4; // edx
   int *v5; // edx
   int **v6; // esi

   result = *a1;
   if ( *a1 )
   {
	 *a2 = result[1];
	 v3 = a1[5];
	 a1[4] = (int **)((char *)a1[4] - 1);
	 a1[5] = (int **)((char *)v3 - (char *)result[1]);
	 v4 = result[3];
	 if ( v4 )
	   v4[2] = (int)result[2];
	 else
	   a1[1] = (int **)result[2];
	 v5 = result[2];
	 if ( v5 )
	   v5[3] = (int)result[3];
	 else
	   *a1 = (int **)result[3];
	 v6 = (int **)*result;
	 sub_4209C0((int)a1, result);
	 result = v6;
   }
   return result;
 }*/

//----- (00420B00) --------------------------------------------------------
int******* __cdecl sub_420B00(_DWORD* a1, _DWORD* a2) {
	int******* result; // eax
	int v3;            // esi
	int***** v4;       // edx
	int***** v5;       // edx
	int****** v6;      // esi

	result = (int*******)a1[1];
	if (result) {
		*a2 = result[1];
		v3 = a1[5];
		--a1[4];
		a1[5] = v3 - (_DWORD)result[1];
		v4 = (int*****)result[3];
		if (v4)
			v4[2] = (int****)result[2];
		else
			a1[1] = result[2];
		v5 = (int*****)result[2];
		if (v5)
			v5[3] = (int****)result[3];
		else
			*a1 = result[3];
		v6 = *result;
		sub_4209C0((int)a1, result);
		result = (int*******)v6;
	}
	return result;
}

//----- (00420B70) --------------------------------------------------------
int __cdecl sub_420B70(_DWORD* a1, _DWORD* a2, int(__cdecl* a3)(_DWORD, int), int a4) {
	_DWORD* v4; // esi

	if (!a3)
		return 0;
	v4 = (_DWORD*)*a1;
	if (!*a1)
		return 0;
	while (a3(*v4, a4) != 1) {
		v4 = (_DWORD*)v4[3];
		if (!v4)
			return 0;
	}
	*a2 = v4[1];
	return *v4;
}

//----- (00420BC0) --------------------------------------------------------
int __cdecl sub_420BC0(int a1) {
	return *(_DWORD*)(a1 + 16); //_fileno(a1);
}

//----- (00420BD0) --------------------------------------------------------
int __cdecl sub_420BD0(int a1) { return *(_DWORD*)(a1 + 20); }

//----- (00420BE0) --------------------------------------------------------
int __cdecl sub_420BE0(int a1, _DWORD* a2) {
	int* v2;    // ecx
	bool v3;    // zf
	int result; // eax

	v2 = *(int**)a1;
	v3 = *(_DWORD*)a1 == 0;
	*(_DWORD*)(a1 + 8) = *(_DWORD*)a1;
	if (v3)
		return 0;
	*a2 = v2[1];
	result = *v2;
	*(_DWORD*)(a1 + 8) = v2[3];
	return result;
}

//----- (00420C10) --------------------------------------------------------
int __cdecl sub_420C10(int a1, _DWORD* a2) {
	int* v2;    // ecx
	int result; // eax

	v2 = *(int**)(a1 + 8);
	if (!v2)
		return 0;
	*a2 = v2[1];
	result = *v2;
	*(_DWORD*)(a1 + 8) = v2[3];
	return result;
}

//----- (00420C40) --------------------------------------------------------
_DWORD* __cdecl sub_420C40(int a1, int a2) {
	_DWORD* result; // eax

	result = malloc(0xCu);
	if (result) {
		*result = a1;
		result[1] = a2;
		result[2] = dword_5d4594_588068;
		dword_5d4594_588068 = result;
	}
	return result;
}

//----- (00420C70) --------------------------------------------------------
_DWORD* sub_420C70() {
	_DWORD* result; // eax
	_DWORD* v1;     // esi

	result = *(_DWORD**)&dword_5d4594_588068;
	if (dword_5d4594_588068) {
		do {
			v1 = (_DWORD*)result[2];
			free(result);
			result = v1;
		} while (v1);
		dword_5d4594_588068 = 0;
	} else {
		dword_5d4594_588068 = 0;
	}
	return result;
}

//----- (00420CA0) --------------------------------------------------------
char* sub_420CA0() {
	int v0;             // eax
	unsigned __int8* i; // ecx

	v0 = 1;
	if (dword_587000_60356 <= 1u)
		return 0;
	for (i = getMemAt(0x5D4594, 535872); !*(_DWORD*)i; i += 16) {
		if ((unsigned int)++v0 >= *(int*)&dword_587000_60356)
			return 0;
	}
	return (char*)getMemAt(0x5D4594, 16 * v0 + 535844);
}

//----- (00420CD0) --------------------------------------------------------
char* __cdecl sub_420CD0(_DWORD* a1) {
	unsigned int v1;    // eax
	unsigned __int8* i; // ecx

	v1 = *a1 + 1;
	if (v1 >= *(int*)&dword_587000_60356)
		return 0;
	for (i = getMemAt(0x5D4594, 16 * v1 + 535856); !*(_DWORD*)i; i += 16) {
		if (++v1 >= *(int*)&dword_587000_60356)
			return 0;
	}
	return (char*)getMemAt(0x5D4594, 16 * v1 + 535844);
}

//----- (00420D10) --------------------------------------------------------
int sub_420D10() {
	int result;         // eax
	unsigned __int8* i; // ecx

	result = 1;
	if (dword_587000_60356 <= 1u)
		return (dword_587000_60356)++;
	for (i = getMemAt(0x5D4594, 535872); *(_DWORD*)i; i += 16) {
		if ((unsigned int)++result >= *(int*)&dword_587000_60356)
			return (dword_587000_60356)++;
	}
	return result;
}

//----- (00420D40) --------------------------------------------------------
unsigned int* __cdecl sub_420D40(int a1, int a2, unsigned int a3, int a4) {
	bool v4;              // cf
	unsigned int* result; // eax

	if (a4)
		sub_420C40(a3, a4);
	v4 = a3 < *(int*)&dword_587000_60356;
	result = getMemUintPtr(0x5D4594, 16 * a3 + 535844);
	*result = a3;
	if (!v4)
		dword_587000_60356 = a3 + 1;
	*getMemU32Ptr(0x5D4594, 16 * a3 + 535848) = a1;
	*getMemU32Ptr(0x5D4594, 16 * a3 + 535852) = a2;
	*getMemU32Ptr(0x5D4594, 16 * a3 + 535856) = 1;
	return result;
}

//----- (00420DA0) --------------------------------------------------------
unsigned int* __cdecl sub_420DA0(float a1, float a2) {
	int* v2;              // eax
	int* v3;              // ebx
	int v4;               // eax
	unsigned int* result; // eax
	int v6;               // edx
	int v7;               // ecx
	int v8;               // ecx
	int v9;               // eax
	int2 v10;             // [esp+Ch] [ebp-8h]

	v10.field_0 = nox_float2int(a1);
	v10.field_4 = nox_float2int(a2);
	if (nox_common_gameFlags_check_40A5C0(0x200000) && (v2 = (int*)sub_420E80(a1, a2, 900.0), (v3 = v2) != 0)) {
		if (!sub_421B40(v2)) {
			v8 = *v3;
			v9 = *getMemU16Ptr(0x5D4594, 588072);
			++*getMemU16Ptr(0x5D4594, 588072);
			*getMemU32Ptr(0x5D4594, 4 * v9 + 534820) = v8;
		}
	} else if (!nox_common_gameFlags_check_40A5C0(0x200000) || !sub_4217B0(&v10, 0)) {
		v4 = sub_420D10();
		result = sub_420D40(SLODWORD(a1), SLODWORD(a2), v4, 0);
		v6 = *result;
		v7 = *getMemU16Ptr(0x5D4594, 588072);
		++*getMemU16Ptr(0x5D4594, 588072);
		*getMemU32Ptr(0x5D4594, 4 * v7 + 534820) = v6;
		return result;
	}
	return 0;
}

//----- (00420E80) --------------------------------------------------------
int __cdecl sub_420E80(float a1, float a2, float a3) {
	int v3;              // esi
	unsigned __int8* v4; // ecx
	int v5;              // edx
	double v6;           // st6
	double v7;           // st5

	v3 = 0;
	if (dword_587000_60356 > 1u) {
		v4 = getMemAt(0x5D4594, 535864);
		v5 = dword_587000_60356 - 1;
		do {
			if (*((_DWORD*)v4 + 2)) {
				v6 = *((float*)v4 + 1) - a2;
				v7 = v6 * v6 + (*(float*)v4 - a1) * (*(float*)v4 - a1);
				if (v7 < a3) {
					a3 = v7;
					v3 = (int)(v4 - 4);
				}
			}
			v4 += 16;
			--v5;
		} while (v5);
	}
	return v3;
}

//----- (00420EE0) --------------------------------------------------------
int __cdecl sub_420EE0(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)(a1 + 12) = 0;
	return result;
}

//----- (00420EF0) --------------------------------------------------------
int __cdecl sub_420EF0(_DWORD* a1) {
	unsigned int v1;     // ebp
	unsigned __int8* v2; // ebx
	int v3;              // edi
	_DWORD* v4;          // eax
	int v5;              // eax
	unsigned __int8* i;  // ecx

	v1 = 1;
	if (dword_587000_60352 > 1u) {
		v2 = getMemAt(0x5D4594, 552496);
		do {
			if (*((_DWORD*)v2 - 11)) {
				v3 = 0;
				if (*(_WORD*)v2) {
					v4 = (_DWORD*)*((_DWORD*)v2 - 5);
					while (*v4 != *a1) {
						++v3;
						++v4;
						if (v3 >= *(unsigned __int16*)v2)
							goto LABEL_12;
					}
					if (--*(_WORD*)v2 < 3u)
						sub_4212C0((int)(v2 - 128));
					memcpy((void*)(*((_DWORD*)v2 - 5) + 4 * v3), (const void*)(*((_DWORD*)v2 - 5) + 4 * v3 + 4),
							4 * (*(unsigned __int16*)v2 - v3));
				}
			}
		LABEL_12:
			++v1;
			v2 += 140;
		} while (v1 < *(int*)&dword_587000_60352);
	}
	v5 = 0;
	if ((int)*getMemU16Ptr(0x5D4594, 588072) > 0) {
		for (i = getMemAt(0x5D4594, 534820); *(_DWORD*)i != *a1; i += 4) {
			if (++v5 >= *getMemU16Ptr(0x5D4594, 588072))
				return sub_420EE0((int)a1);
		}
		--*getMemU16Ptr(0x5D4594, 588072);
		memcpy(getMemAt(0x5D4594, 4 * v5 + 534820), getMemAt(0x5D4594, 4 * v5 + 534824),
				4 * (*getMemU16Ptr(0x5D4594, 588072) - v5));
	}
	return sub_420EE0((int)a1);
}

//----- (00421010) --------------------------------------------------------
char* sub_421010() {
	char* result; // eax

	result = (char*)getMemAt(0x5D4594, 535872);
	do {
		*(_DWORD*)result = 0;
		result += 16;
	} while ((int)result < (int)getMemAt(0x5D4594, 552240));
	dword_587000_60356 = 1;
	return result;
}

//----- (00421030) --------------------------------------------------------
char* __cdecl sub_421030(int a1) { return (char*)getMemAt(0x5D4594, 16 * a1 + 535844); }

//----- (00421040) --------------------------------------------------------
void __cdecl sub_421040(int a1) {
	int v1;     // esi
	_DWORD* v2; // ebx
	_DWORD* v3; // eax
	int v4;     // ecx
	int v5;     // edx
	_DWORD* v6; // ecx

	v1 = 0;
	if (*(_WORD*)(a1 + 128)) {
		v2 = *(_DWORD**)&dword_5d4594_588068;
		do {
			v3 = v2;
			if (v2) {
				v4 = *(_DWORD*)(a1 + 108);
				v5 = *(_DWORD*)(v4 + 4 * v1);
				v6 = (_DWORD*)(v4 + 4 * v1);
				while (v5 != v3[1]) {
					v3 = (_DWORD*)v3[2];
					if (!v3)
						goto LABEL_9;
				}
				*v6 = *v3;
				v2 = *(_DWORD**)&dword_5d4594_588068;
			}
		LABEL_9:
			++v1;
		} while (v1 < *(unsigned __int16*)(a1 + 128));
	}
}

//----- (004210A0) --------------------------------------------------------
char* sub_4210A0() {
	int v0;             // eax
	unsigned __int8* i; // ecx

	v0 = 1;
	if (dword_587000_60352 <= 1u)
		return 0;
	for (i = getMemAt(0x5D4594, 552452); !*(_DWORD*)i; i += 140) {
		if ((unsigned int)++v0 >= *(int*)&dword_587000_60352)
			return 0;
	}
	return (char*)getMemAt(0x5D4594, 140 * v0 + 552228);
}

//----- (004210E0) --------------------------------------------------------
char* __cdecl sub_4210E0(int a1) {
	unsigned int v1;    // eax
	unsigned __int8* i; // ecx

	v1 = *(_DWORD*)(a1 + 80) + 1;
	if (v1 >= *(int*)&dword_587000_60352)
		return 0;
	for (i = getMemAt(0x5D4594, 140 * v1 + 552312); !*(_DWORD*)i; i += 140) {
		if (++v1 >= *(int*)&dword_587000_60352)
			return 0;
	}
	return (char*)getMemAt(0x5D4594, 140 * v1 + 552228);
}

//----- (00421130) --------------------------------------------------------
int sub_421130() {
	int result;         // eax
	unsigned __int8* i; // ecx

	result = 1;
	if (dword_587000_60352 <= 1u)
		return (dword_587000_60352)++;
	for (i = getMemAt(0x5D4594, 552452); *(_DWORD*)i; i += 140) {
		if ((unsigned int)++result >= *(int*)&dword_587000_60352)
			return (dword_587000_60352)++;
	}
	return result;
}

//----- (00421160) --------------------------------------------------------
int __cdecl sub_421160(int a1) {
	int result; // eax

	strcpy((char*)(a1 + 4), (const char*)getMemAt(0x587000, 60364));
	*(_BYTE*)(a1 + 104) = getMemByte(0x587000, 60464);
	*(_BYTE*)(a1 + 105) = getMemByte(0x587000, 60465);
	*(_BYTE*)(a1 + 106) = getMemByte(0x587000, 60466);
	*(_BYTE*)(a1 + 130) = getMemByte(0x587000, 60490);
	result = 0;
	*(_DWORD*)(a1 + 132) = 0;
	*(_DWORD*)(a1 + 136) = 0;
	return result;
}

//----- (004211D0) --------------------------------------------------------
int __cdecl sub_4211D0(int a1) {
	int result; // eax

	strcpy((char*)getMemAt(0x587000, 60364), (const char*)(a1 + 4));
	*getMemU8Ptr(0x587000, 60464) = *(_BYTE*)(a1 + 104);
	*getMemU8Ptr(0x587000, 60465) = *(_BYTE*)(a1 + 105);
	*getMemU8Ptr(0x587000, 60466) = *(_BYTE*)(a1 + 106);
	*getMemU8Ptr(0x587000, 60490) = *(_BYTE*)(a1 + 130);
	result = 0;
	*(_DWORD*)(a1 + 132) = 0;
	*(_DWORD*)(a1 + 136) = 0;
	return result;
}

//----- (00421230) --------------------------------------------------------
unsigned __int8* sub_421230() {
	int v0;              // edi
	unsigned __int8* v1; // esi
	_BYTE* v2;           // eax

	v0 = sub_421130();
	v1 = getMemAt(0x5D4594, 140 * v0 + 552228);
	*(_DWORD*)v1 = 0;
	if (nox_common_gameFlags_check_40A5C0(0x200000)) {
		v2 = calloc(1u, 0x100u);
		*(_DWORD*)v1 = v2;
		if (!v2) {
			free(v1);
			return 0;
		}
		*v2 = 0;
		*(_BYTE*)(*(_DWORD*)v1 + 128) = 0;
	}
	*((_DWORD*)v1 + 20) = v0;
	_itoa(v0, (char*)v1 + 4, 10);
	sub_421160((int)v1);
	*((_DWORD*)v1 + 21) = 1;
	return getMemAt(0x5D4594, 140 * v0 + 552228);
}

//----- (004212C0) --------------------------------------------------------
int __cdecl sub_4212C0(int a1) {
	int v1;               // ebx
	int v2;               // ebp
	unsigned int v3;      // edi
	int v4;               // ecx
	unsigned __int8* v5;  // eax
	int v6;               // edx
	_DWORD* v7;           // ecx
	int v8;               // eax
	unsigned __int8* v9;  // edx
	unsigned __int8* v10; // esi
	int result;           // eax
	int v12;              // [esp+Ch] [ebp-4h]
	int v13;              // [esp+14h] [ebp+4h]

	v1 = a1;
	v2 = 0;
	v12 = 0;
	if (*(_WORD*)(a1 + 128)) {
		do {
			v3 = 1;
			v4 = 0;
			v13 = 0;
			if (dword_587000_60352 <= 1u) {
			LABEL_16:
				v8 = 0;
				v9 = getMemAt(0x5D4594, 16 * *(_DWORD*)(*(_DWORD*)(v1 + 108) + 4 * v2) + 535844);
				if ((int)*getMemU16Ptr(0x5D4594, 588072) > 0) {
					v10 = getMemAt(0x5D4594, 534820);
					while (*(_DWORD*)v10 != *(_DWORD*)v9) {
						++v8;
						v10 += 4;
						if (v8 >= *getMemU16Ptr(0x5D4594, 588072))
							goto LABEL_22;
					}
					--*getMemU16Ptr(0x5D4594, 588072);
					memcpy(getMemAt(0x5D4594, 4 * v8 + 534820), getMemAt(0x5D4594, 4 * v8 + 534824),
							4 * (*getMemU16Ptr(0x5D4594, 588072) - v2));
				}
			LABEL_22:
				sub_420EE0((int)v9);
			} else {
				v5 = getMemAt(0x5D4594, 552496);
				while (!v4) {
					if (*((_DWORD*)v5 - 11)) {
						if (v5 - 128 != (unsigned __int8*)v1) {
							v6 = 0;
							if (*(_WORD*)v5) {
								v7 = (_DWORD*)*((_DWORD*)v5 - 5);
								while (*v7 != *(_DWORD*)(*(_DWORD*)(v1 + 108) + 4 * v2)) {
									++v6;
									++v7;
									if (v6 >= *(unsigned __int16*)v5) {
										v4 = v13;
										goto LABEL_14;
									}
								}
								v4 = 1;
								v13 = 1;
							}
						}
					}
				LABEL_14:
					++v3;
					v5 += 140;
					if (v3 >= *(int*)&dword_587000_60352) {
						v2 = v12;
						if (v4)
							break;
						goto LABEL_16;
					}
					v2 = v12;
				}
			}
			v12 = ++v2;
		} while (v2 < *(unsigned __int16*)(v1 + 128));
	}
	if (*(_DWORD*)v1) {
		free(*(LPVOID*)v1);
		*(_DWORD*)v1 = 0;
	}
	if (*(_DWORD*)(v1 + 108)) {
		free(*(LPVOID*)(v1 + 108));
		*(_DWORD*)(v1 + 108) = 0;
	}
	*(_WORD*)(v1 + 128) = 0;
	*(_DWORD*)(v1 + 80) = 0;
	result = -1;
	*(_DWORD*)(v1 + 84) = 0;
	*(_DWORD*)(v1 + 116) = -1;
	*(_DWORD*)(v1 + 124) = -1;
	return result;
}

//----- (00421430) --------------------------------------------------------
LPVOID sub_421430() {
	unsigned __int8* v0; // esi
	LPVOID result;       // eax

	v0 = getMemAt(0x5D4594, 552476);
	do {
		if (*((_DWORD*)v0 - 27)) {
			if (*getMemU32Ptr(0x5D4594, 588076))
				free(*((LPVOID*)v0 - 27));
			*((_DWORD*)v0 - 27) = 0;
		}
		result = *(LPVOID*)v0;
		if (*(_DWORD*)v0) {
			if (*getMemU32Ptr(0x5D4594, 588076))
				free(*(LPVOID*)v0);
			*(_DWORD*)v0 = 0;
		}
		*((_WORD*)v0 + 10) = 0;
		*((_DWORD*)v0 - 7) = 0;
		*((_DWORD*)v0 + 2) = -1;
		*((_DWORD*)v0 + 4) = -1;
		*((_DWORD*)v0 - 6) = 0;
		v0 += 140;
	} while ((int)v0 < (int)getMemAt(0x5D4594, 588176));
	dword_587000_60352 = 1;
	return result;
}

//----- (004214A0) --------------------------------------------------------
char* __cdecl sub_4214A0(int a1) {
	char* result; // eax

	if (a1 == -559023410)
		result = 0;
	else
		result = (char*)getMemAt(0x5D4594, 140 * a1 + 552228);
	return result;
}

//----- (004214D0) --------------------------------------------------------
void sub_4214D0() {
	unsigned __int8* v0; // esi
	int v1;              // eax
	unsigned __int8* v2; // edi
	int v3;              // eax
	int v4;              // ebx
	bool v5;             // cc
	unsigned __int8* v6; // edi

	if (*getMemU16Ptr(0x5D4594, 588072) >= 3u) {
		v0 = sub_421230();
		if (v0) {
			*((_DWORD*)v0 + 27) = calloc(*getMemU16Ptr(0x5D4594, 588072), 4u);
			v1 = 0;
			*((_WORD*)v0 + 64) = *getMemU16Ptr(0x5D4594, 588072);
			if (*getMemU16Ptr(0x5D4594, 588072)) {
				do {
					*(_DWORD*)(*((_DWORD*)v0 + 27) + 4 * v1) = *getMemU32Ptr(0x5D4594, 4 * v1 + 534820);
					++v1;
				} while (v1 < *getMemU16Ptr(0x5D4594, 588072));
			}
			v2 = getMemAt(0x5D4594, 16 * **((_DWORD**)v0 + 27) + 535844);
			*((_DWORD*)v0 + 22) = nox_float2int(*((float*)v2 + 1));
			*((_DWORD*)v0 + 23) = nox_float2int(*((float*)v2 + 2));
			*((_DWORD*)v0 + 24) = nox_float2int(*((float*)v2 + 1));
			v3 = nox_float2int(*((float*)v2 + 2));
			v4 = 1;
			v5 = *((_WORD*)v0 + 64) <= 1u;
			*((_DWORD*)v0 + 25) = v3;
			if (!v5) {
				do {
					v6 = getMemAt(0x5D4594, 16 * *(_DWORD*)(*((_DWORD*)v0 + 27) + 4 * v4) + 535844);
					if (*((float*)v6 + 1) >= (double)*((int*)v0 + 22)) {
						if (*((float*)v6 + 1) > (double)*((int*)v0 + 24))
							*((_DWORD*)v0 + 24) = nox_float2int(*((float*)v6 + 1));
					} else {
						*((_DWORD*)v0 + 22) = nox_float2int(*((float*)v6 + 1));
					}
					if (*((float*)v6 + 2) >= (double)*((int*)v0 + 23)) {
						if (*((float*)v6 + 2) > (double)*((int*)v0 + 25))
							*((_DWORD*)v0 + 25) = nox_float2int(*((float*)v6 + 2));
					} else {
						*((_DWORD*)v0 + 23) = nox_float2int(*((float*)v6 + 2));
					}
					++v4;
				} while (v4 < *((unsigned __int16*)v0 + 64));
			}
			*getMemU16Ptr(0x5D4594, 588072) = 0;
		}
	}
}

//----- (00421660) --------------------------------------------------------
int __cdecl sub_421660(int* a1, int a2) {
	char v2;              // bp
	int v4;               // edx
	int v5;               // ecx
	_DWORD* v6;           // edx
	unsigned __int8* v7;  // esi
	int v8;               // eax
	unsigned __int16 v9;  // cx
	unsigned __int16 v10; // bx
	unsigned __int8* v11; // esi
	int4 v12;             // [esp+8h] [ebp-20h]
	int4 v16;             // [esp+18h] [ebp-10h]

	v2 = 0;
	if (!a2)
		return 0;
	v4 = a1[1];
	v16.field_0 = *a1;
	v16.field_4 = v4;
	v5 = (getMemByte(0x5D4594, 588080) & 2) != 0 ? 0x1700 : 0;
	++*getMemU32Ptr(0x5D4594, 588080);
	v6 = *(_DWORD**)(a2 + 108);
	v16.field_8 = v5;
	v16.field_C = (getMemByte(0x5D4594, 588080) & 2) != 0 ? 0x1700 : 0;
	v7 = getMemAt(0x5D4594, 16 * *v6 + 535844);
	v12.field_0 = nox_float2int(*((float*)v7 + 1));
	v8 = nox_float2int(*((float*)v7 + 2));
	v9 = *(_WORD*)(a2 + 128);
	v10 = 1;
	for (v12.field_4 = v8; v10 <= v9; ++v10) {
		v11 = getMemAt(0x5D4594, 16 * *(_DWORD*)(*(_DWORD*)(a2 + 108) + 4 * (v10 % (int)v9)) + 535844);
		if (v10 & 1) {
			v12.field_8 = nox_float2int(*((float*)v11 + 1));
			v12.field_C = nox_float2int(*((float*)v11 + 2));
		} else {
			v12.field_0 = nox_float2int(*((float*)v11 + 1));
			v12.field_4 = nox_float2int(*((float*)v11 + 2));
		}
		if (sub_427C80(&v16, &v12))
			++v2;
		v9 = *(_WORD*)(a2 + 128);
	}
	return v2 & 1;
}

//----- (00421790) --------------------------------------------------------
int __cdecl sub_421790(int2* a1, int a2) {
	struc_19* v2; // eax
	int result;   // eax

	v2 = sub_4217B0(a1, a2);
	if (v2)
		result = v2->field_0[20];
	else
		result = 0;
	return result;
}

//----- (004217B0) --------------------------------------------------------
struc_19* __cdecl sub_4217B0(int2* a1, int a2) {
	int v2;             // eax
	int v4;             // edi
	unsigned __int8* i; // esi
	int v6;             // eax

	if (a2) {
		if (a2 != -559023410) {
			if (*getMemU32Ptr(0x5D4594, 140 * a2 + 552312)) {
				v2 = sub_4281F0(a1, (int4*)getMemAt(0x5D4594, 140 * a2 + 552316));
				if (v2) {
					if (sub_421660(&a1->field_0, (int)getMemAt(0x5D4594, 140 * a2 + 552228)))
						return (struc_19*)getMemAt(0x5D4594, 140 * a2 + 552228);
				}
			}
		}
	}
	v4 = 1;
	if (dword_587000_60352 <= 1u)
		return 0;
	for (i = getMemAt(0x5D4594, 552448);; i += 140) {
		if (*((_DWORD*)i + 1)) {
			if (*(_DWORD*)i != a2) {
				v6 = sub_4281F0(a1, (int4*)(i + 8));
				if (v6) {
					if (sub_421660(&a1->field_0, (int)(i - 80)))
						break;
				}
			}
		}
		if ((unsigned int)++v4 >= *(int*)&dword_587000_60352)
			return 0;
	}
	return (struc_19*)(i - 80);
}
// 4217F5: variable 'v2' is possibly undefined
// 421840: variable 'v6' is possibly undefined

//----- (00421880) --------------------------------------------------------
int __cdecl sub_421880(int a1, int a2, float a3) {
	unsigned __int8* v3; // esi
	int v4;              // eax
	int v5;              // ebx
	int v6;              // ecx
	unsigned __int8* v7; // esi
	int4 v9;             // [esp+10h] [ebp-10h]

	v3 = getMemAt(0x5D4594, 16 * **(_DWORD**)(a2 + 108) + 535844);
	v9.field_0 = nox_float2int(*((float*)v3 + 1));
	v4 = nox_float2int(*((float*)v3 + 2));
	v5 = 1;
	v6 = *(unsigned __int16*)(a2 + 128);
	v9.field_4 = v4;
	if ((int)(unsigned __int16)v6 < 1)
		return 0;
	while (1) {
		v7 = getMemAt(0x5D4594, 16 * *(_DWORD*)(*(_DWORD*)(a2 + 108) + 4 * (v5 % v6)) + 535844);
		if (v5 & 1) {
			v9.field_8 = nox_float2int(*((float*)v7 + 1));
			v9.field_C = nox_float2int(*((float*)v7 + 2));
		} else {
			v9.field_0 = nox_float2int(*((float*)v7 + 1));
			v9.field_4 = nox_float2int(*((float*)v7 + 2));
		}
		if (sub_427DF0(a1, &v9, a3))
			break;
		++v5;
		v6 = *(unsigned __int16*)(a2 + 128);
		if (v5 > (unsigned __int16)v6)
			return 0;
	}
	return 1;
}

//----- (00421960) --------------------------------------------------------
int __cdecl sub_421960(int a1, float a2, int a3) {
	int* v3;    // eax
	int result; // eax

	v3 = sub_421990((int2*)a1, a2, a3);
	if (v3)
		result = v3[20];
	else
		result = 0;
	return result;
}

//----- (00421990) --------------------------------------------------------
int* __cdecl sub_421990(int2* a1, float a2, int a3) {
	int* i; // esi
	int v5; // edi

	if (a3) {
		if (a3 != -559023410) {
			i = getMemIntPtr(0x5D4594, 140 * a3 + 552228);
			if (*getMemU32Ptr(0x5D4594, 140 * a3 + 552312)) {
				if (sub_421880((int)a1, (int)getMemAt(0x5D4594, 140 * a3 + 552228), a2))
					return i;
			}
		}
	}
	v5 = 1;
	if (dword_587000_60352 > 1u) {
		for (i = getMemIntPtr(0x5D4594, 552368); !i[21] || i[20] == a3 || !sub_421880((int)a1, (int)i, a2); i += 35) {
			if ((unsigned int)++v5 >= *(int*)&dword_587000_60352)
				return 0;
		}
		return i;
	}
	return 0;
}

//----- (00421A30) --------------------------------------------------------
__int16 sub_421A30() {
	__int16 result;      // ax
	unsigned int v1;     // edi
	int v2;              // ebx
	unsigned __int8* v3; // eax
	int v4;              // edx
	_DWORD* v5;          // ecx
	bool v6;             // cc
	unsigned __int8* v7; // [esp+0h] [ebp-8h]
	int v8;              // [esp+4h] [ebp-4h]

	result = *getMemU16Ptr(0x5D4594, 588072);
	if (*getMemU16Ptr(0x5D4594, 588072)) {
		v8 = 0;
		if (*getMemU16Ptr(0x5D4594, 588072)) {
			v7 = getMemAt(0x5D4594, 534820);
			do {
				v1 = 1;
				v2 = 0;
				if (dword_587000_60352 <= 1u) {
					sub_420EE0((int)getMemAt(0x5D4594, 16 * *(_DWORD*)v7 + 535844));
				} else {
					v3 = getMemAt(0x5D4594, 552496);
					while (!v2) {
						if (*((_DWORD*)v3 - 11)) {
							v4 = 0;
							if (*(_WORD*)v3) {
								v5 = (_DWORD*)*((_DWORD*)v3 - 5);
								while (*v5 != *(_DWORD*)v7) {
									++v4;
									++v5;
									if (v4 >= *(unsigned __int16*)v3)
										goto LABEL_14;
								}
								v2 = 1;
							}
						}
					LABEL_14:
						++v1;
						v3 += 140;
						if (v1 >= *(int*)&dword_587000_60352) {
							if (v2)
								break;
							sub_420EE0((int)getMemAt(0x5D4594, 16 * *(_DWORD*)v7 + 535844));
						}
					}
				}
				result = v8 + 1;
				v6 = ++v8 < *getMemU16Ptr(0x5D4594, 588072);
				v7 += 4;
			} while (v6);
		}
		*getMemU16Ptr(0x5D4594, 588072) = 0;
	}
	return result;
}

//----- (00421B10) --------------------------------------------------------
_DWORD* sub_421B10() {
	_DWORD* result; // eax

	sub_421430();
	sub_421010();
	result = sub_420C70();
	*getMemU32Ptr(0x5D4594, 588076) = 1;
	*getMemU16Ptr(0x5D4594, 588072) = 0;
	return result;
}

//----- (00421B40) --------------------------------------------------------
int __cdecl sub_421B40(_DWORD* a1) {
	int v1;             // eax
	unsigned __int8* i; // ecx

	v1 = 0;
	if ((int)*getMemU16Ptr(0x5D4594, 588072) <= 0)
		return 0;
	for (i = getMemAt(0x5D4594, 534820); *(_DWORD*)i != *a1; i += 4) {
		if (++v1 >= *getMemU16Ptr(0x5D4594, 588072))
			return 0;
	}
	return 1;
}

//----- (00421B80) --------------------------------------------------------
void sub_421B80() {
	int v0;       // esi
	char* v1;     // eax
	char* v2;     // esi
	struc_19* v3; // eax
	char* v4;     // eax
	int2 v5;      // [esp+4h] [ebp-10h]
	int2 v6;      // [esp+Ch] [ebp-8h]

	v0 = *getMemU32Ptr(0x5D4594, 2614252);
	if (*getMemU32Ptr(0x5D4594, 2614252)) {
		sub_435670(&v5);
		sub_435690(&v6);
		v1 = nox_common_playerInfoGetByID_417040(*(_DWORD*)(v0 + 128));
		v2 = v1;
		if (v1) {
			if (dword_587000_60352 <= 1u) {
			LABEL_8:
				v2[3668] = 1;
				*((_DWORD*)v2 + 915) = 0;
				v4 = sub_469BB0();
				sub_4349C0(v4);
				return;
			}
			if (*((int*)v1 + 915) == -559023410 || v5.field_0 != v6.field_0 || v5.field_4 != v6.field_4) {
				v3 = sub_4217B0(&v5, *((_DWORD*)v1 + 915));
				if (!v3)
					goto LABEL_8;
				if (*((_DWORD*)v2 + 915) != v3->field_0[20]) {
					v2[3668] = BYTE2(v3->field_0[32]);
					*((_DWORD*)v2 + 915) = v3->field_0[20];
					sub_434990(LOBYTE(v3->field_0[26]), BYTE1(v3->field_0[26]), BYTE2(v3->field_0[26]));
				}
			}
		}
	}
}

//----- (00421C70) --------------------------------------------------------
void __cdecl sub_421C70(int a1) {
	int v1;              // ebp
	int v2;              // eax
	float v3;            // edx
	unsigned __int8* v4; // esi
	int v5;              // ecx
	int v6;              // ecx
	int v7;              // ecx
	int i;               // edi
	int v9;              // eax
	int v10;             // eax
	int v11;             // eax
	int v12;             // ecx
	int2 v13;            // [esp+10h] [ebp-8h]

	if (!a1 || !(*(_BYTE*)(a1 + 8) & 4))
		return;
	v1 = *(_DWORD*)(*(_DWORD*)(a1 + 748) + 276);
	if (*(_BYTE*)(v1 + 2064) == 31) {
		v11 = *(_DWORD*)(v1 + 3660);
		if (!v11) {
			*(_DWORD*)(v1 + 3664) = 0;
			goto LABEL_33;
		}
		if (v11 == -559023410)
			goto LABEL_33;
		v4 = getMemAt(0x5D4594, 140 * v11 + 552228);
		goto LABEL_11;
	}
	if (*(int*)(v1 + 3664) != -559023410 && *(float*)(a1 + 56) == *(float*)(a1 + 72) &&
		*(float*)(a1 + 60) == *(float*)(a1 + 76)) {
		return;
	}
	v2 = nox_float2int(*(float*)(a1 + 56));
	v3 = *(float*)(a1 + 60);
	v13.field_0 = v2;
	v13.field_4 = nox_float2int(v3);
	v4 = (unsigned __int8*)sub_4217B0(&v13, *(_DWORD*)(v1 + 3664));
	if (v4)
		goto LABEL_12;
	v5 = *(_DWORD*)(v1 + 3664);
	if (v5 && v5 != -559023410) {
		v4 = getMemAt(0x5D4594, 140 * v5 + 552228);
	LABEL_11:
		if (v4) {
		LABEL_12:
			v6 = *(_DWORD*)(v1 + 3664);
			if (v6 != *((_DWORD*)v4 + 20)) {
				if (v6 != -559023410) {
					if (v6) {
						v7 = 35 * v6;
						if (*getMemIntPtr(0x5D4594, 4 * v7 + 552352) != -1)
							sub_502490(getMemIntPtr(0x5D4594, 4 * v7 + 552348), a1, 0);
					}
					if (!((1 << *(_BYTE*)(v1 + 2064)) & *((_DWORD*)v4 + 34)) && v4[132] & 1 &&
						nox_common_gameFlags_check_40A5C0(4096)) {
						sub_4D61F0(a1);
						sub_4DA2C0(a1, "GeneralPrint:SecretFound", 0);
						sub_501960(904, a1, 0, 0);
						for (i = sub_4DA7C0(); i; i = sub_4DA7F0(i)) {
							if (i != a1)
								sub_4DA0F0(*(unsigned __int8*)(*(_DWORD*)(*(_DWORD*)(i + 748) + 276) + 2064), 20,
										   (int*)(a1 + 36));
						}
						v9 = *((_DWORD*)v4 + 33);
						LOBYTE(v9) = v9 & 0xFE;
						*((_DWORD*)v4 + 33) = v9;
					}
					v10 = *((_DWORD*)v4 + 29);
					*((_DWORD*)v4 + 34) |= 1 << *(_BYTE*)(v1 + 2064);
					if (v10 != -1)
						sub_502490((int*)v4 + 28, a1, 0);
				}
				*(_DWORD*)(v1 + 3664) = *((_DWORD*)v4 + 20);
				*(_BYTE*)(v1 + 3668) = v4[130];
			}
			return;
		}
	}
LABEL_33:
	v12 = *(_DWORD*)(v1 + 3664);
	if (v12 && v12 != -559023410) {
		if (*getMemIntPtr(0x5D4594, 140 * v12 + 552352) != -1)
			sub_502490(getMemIntPtr(0x5D4594, 140 * v12 + 552348), a1, 0);
		*(_DWORD*)(v1 + 3664) = 0;
		*(_BYTE*)(v1 + 3668) = 1;
	}
}

//----- (00421F10) --------------------------------------------------------
unsigned __int8* __cdecl sub_421F10(int* a1, int a2) {
	unsigned __int8* v2; // esi
	int v3;              // eax
	int v5;              // edi
	unsigned __int8* i;  // esi
	int v7;              // eax

	if (a2) {
		if (a2 != 0xDEADFACE) {
			v2 = getMemAt(0x5D4594, 140 * a2 + 552228);
			if (*getMemU32Ptr(0x5D4594, 140 * a2 + 552312)) {
				if (*((int*)v2 + 29) != -1 || *((int*)v2 + 31) != -1) {
					v3 = sub_4281F0((int2*)a1, (int4*)(v2 + 88));
					if (v3) {
						if (sub_421660(a1, (int)getMemAt(0x5D4594, 140 * a2 + 552228)))
							return getMemAt(0x5D4594, 140 * a2 + 552228);
					}
				}
			}
		}
	}
	v5 = 1;
	if (dword_587000_60352 <= 1u)
		return 0;
	for (i = getMemAt(0x5D4594, 552448);; i += 140) {
		if (*((_DWORD*)i + 1) && *(int*)i != a2 && (*((int*)i + 9) != -1 || *((int*)i + 11) != -1)) {
			v7 = sub_4281F0((int2*)a1, (int4*)(i + 8));
			if (v7) {
				if (sub_421660(a1, (int)(i - 80)))
					break;
			}
		}
		if ((unsigned int)++v5 >= *(int*)&dword_587000_60352)
			return 0;
	}
	return i - 80;
}
// 421F64: variable 'v3' is possibly undefined
// 421FBE: variable 'v7' is possibly undefined

//----- (00421FF0) --------------------------------------------------------
void __cdecl sub_421FF0(int a1) {
	int* v1;             // ebp
	int v2;              // eax
	float v3;            // ecx
	_DWORD* v4;          // eax
	int v5;              // ecx
	_DWORD* v6;          // edi
	int v7;              // ecx
	int v8;              // ecx
	unsigned __int8* v9; // eax
	int2 v10;            // [esp+Ch] [ebp-8h]

	v1 = *(int**)(a1 + 748);
	if (a1 && *(_BYTE*)(a1 + 8) & 2 &&
		(*v1 == -559023410 || *(float*)(a1 + 56) != *(float*)(a1 + 72) || *(float*)(a1 + 60) != *(float*)(a1 + 76))) {
		v2 = nox_float2int(*(float*)(a1 + 56));
		v3 = *(float*)(a1 + 60);
		v10.field_0 = v2;
		v10.field_4 = nox_float2int(v3);
		if (*v1 == -559023410)
			v4 = sub_4217B0(&v10, 0);
		else
			v4 = sub_421F10(&v10.field_0, *v1);
		v5 = *v1;
		v6 = v4;
		if (v4) {
			if (v5 != v4[20]) {
				if (v5 != -559023410) {
					if (v5) {
						v7 = 35 * v5;
						if (*getMemIntPtr(0x5D4594, 4 * v7 + 552352) != -1)
							sub_502490(getMemIntPtr(0x5D4594, 4 * v7 + 552348), a1, 0);
					}
					if (v6[29] != -1)
						sub_502490(v6 + 28, a1, 0);
				}
				*v1 = v6[20];
			}
		} else if (v5 && v5 != -559023410) {
			v8 = 35 * v5;
			v9 = getMemAt(0x5D4594, 4 * v8 + 552228);
			if (*getMemU32Ptr(0x5D4594, 4 * v8 + 552312) && *((int*)v9 + 31) != -1)
				sub_502490((int*)v9 + 30, a1, 0);
			*v1 = 0;
		}
	}
}

//----- (00422140) --------------------------------------------------------
int __cdecl sub_422140(int a1) {
	int result; // eax

	result = a1;
	if (a1) {
		*(_DWORD*)(a1 + 3660) = -559023410;
		*(_DWORD*)(a1 + 3664) = -559023410;
	}
	return result;
}

//----- (00422160) --------------------------------------------------------
int* __cdecl sub_422160(int a1, int a2, int a3, int a4) {
	int* result; // eax
	char* v5;    // eax
	int i;       // ecx

	result = *(int**)&dword_5d4594_588084;
	if (!dword_5d4594_588084) {
		v5 = (char*)malloc(0xC8u);
		dword_5d4594_588084 = v5;
		for (i = 0; i < 180; i += 20) {
			*(_DWORD*)&v5[i + 16] = &v5[i + 20];
			v5 = *(char**)&dword_5d4594_588084;
		}
		*(_DWORD*)(dword_5d4594_588084 + 196) = 0;
		result = *(int**)&dword_5d4594_588084;
	}
	dword_5d4594_588084 = result[4];
	*result = a1;
	result[1] = a2;
	result[2] = a3;
	result[3] = a4;
	result[4] = 0;
	return result;
}

//----- (004221E0) --------------------------------------------------------
int __cdecl sub_4221E0(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)(a1 + 16) = dword_5d4594_588084;
	dword_5d4594_588084 = a1;
	return result;
}

//----- (00422200) --------------------------------------------------------
int __cdecl sub_422200(int a1) {
	int result; // eax
	int v2;     // esi

	result = *(_DWORD*)(a1 + 16);
	if (result) {
		do {
			v2 = *(_DWORD*)(result + 16);
			sub_4221E0(result);
			result = v2;
		} while (v2);
		*(_DWORD*)(a1 + 16) = 0;
	} else {
		*(_DWORD*)(a1 + 16) = 0;
	}
	return result;
}

//----- (00422230) --------------------------------------------------------
int __cdecl nox_server_mapRWFloorMap_422230(int a1) {
	int v2;               // ecx
	char v3;              // bl
	int v4;               // esi
	int l;                // edx
	_DWORD* v6;           // eax
	char v7;              // bl
	int v8;               // esi
	int m;                // edx
	int v10;              // ecx
	_DWORD* v11;          // eax
	char v12;             // bl
	int v13;              // edx
	_BYTE** v14;          // esi
	_BYTE* v15;           // ecx
	int v16;              // eax
	_BYTE** v17;          // esi
	int v18;              // ebp
	char v19;             // bl
	int n;                // edx
	_BYTE* v21;           // ecx
	int v22;              // eax
	int v23;              // edi
	int v24;              // eax
	int v25;              // esi
	int ii;               // ebx
	int v27;              // ecx
	unsigned __int16 v28; // dx
	int v29;              // ecx
	int v30;              // eax
	_BYTE* v31;           // ecx
	_BYTE* v32;           // ecx
	int v33;              // ebx
	int v34;              // ebp
	char v35;             // al
	int v36;              // esi
	_BYTE* v37;           // eax
	_BYTE* v38;           // edi
	_BYTE* v39;           // eax
	unsigned __int16 v40; // cx
	int v41;              // ebp
	int v42;              // esi
	unsigned __int16 v43; // cx
	unsigned __int16 k;   // cx
	__int16 v47;          // bx
	int v48;              // esi
	int v49;              // edi
	int v50;              // eax
	int v51;              // ebx
	int v52;              // edi
	int v53;              // esi
	_BYTE* v54;           // eax
	_BYTE* v55;           // ecx
	int v56;              // edi
	int v58;              // esi
	int v59;              // [esp+10h] [ebp-40h]
	int v60;              // [esp+14h] [ebp-3Ch]
	int v61;              // [esp+18h] [ebp-38h]
	int v62;              // [esp+1Ch] [ebp-34h]
	int v63;              // [esp+20h] [ebp-30h]
	int v64;              // [esp+24h] [ebp-2Ch]
	int v65;              // [esp+28h] [ebp-28h]
	int v66;              // [esp+2Ch] [ebp-24h]
	int v67;              // [esp+30h] [ebp-20h]
	int v68;              // [esp+34h] [ebp-1Ch]
	int2 v69;             // [esp+38h] [ebp-18h]
	int4 v70;             // [esp+40h] [ebp-10h]

	v62 = 4;
	sub_426AC0_file3_fread(&v62, 2u);
	if ((__int16)v62 > 4)
		return 0;
	if ((__int16)v62 <= 3)
		return sub_422C10(v62, a1);
	if (*getMemU32Ptr(0x5D4594, 3803300)) {
		sub_426AC0_file3_fread(&v60, 4u);
		sub_426AC0_file3_fread(&v61, 4u);
		sub_426AC0_file3_fread(&v66, 4u);
		sub_426AC0_file3_fread(&v67, 4u);
		if (a1) {
			sub_428170((_DWORD*)a1, &v70);
			v41 = v70.field_0 / 23 - v60;
			v42 = v70.field_4 / 23 - v61;
			a1 = v70.field_4 / 23 - v61;
			v61 = v70.field_4 / 23;
			v60 = v70.field_0 / 23;
			sub_426AC0_file3_fread(&v59, 2u);
			v43 = v59;
			if ((_WORD)v59 != (_WORD)-1) {
				while (1) {
					v50 = v41 + (v43 >> 8);
					v51 = v42 + (unsigned __int8)v43;
					if (((_BYTE)v42 + (_BYTE)v43) & 1) {
						v56 = (23 * v50 - 23) / 46;
						v58 = (23 * v51 + 23) / 46;
						if (nox_common_gameFlags_check_40A5C0(0x400000)) {
							v54 = (_BYTE*)*sub_5040A0(v56, v58, COERCE_FLOAT(1));
						} else {
							*(_BYTE*)(&ptr_5D4594_2650668[v56][v58].field_0) |= 0x1;
							v54 = (_BYTE*)(&ptr_5D4594_2650668[v56][v58].field_1);
						}
					} else {
						v52 = 23 * v50 / 46;
						v53 = 23 * v51 / 46;
						if (nox_common_gameFlags_check_40A5C0(0x400000)) {
							v54 = (_BYTE*)*sub_5040A0(v52, 23 * v51 / 46, COERCE_FLOAT(2));
						} else {
							v55 = (_BYTE*)(&ptr_5D4594_2650668[v52][v53].field_0);
							*v55 |= 0x2;
							v54 = (_BYTE*)(&ptr_5D4594_2650668[v52][v53].field_6);
						}
					}
					sub_422A40(v62, v54);
					sub_426AC0_file3_fread(&v59, 2u);
					v43 = v59;
					if ((_WORD)v59 == (_WORD)-1)
						break;
					v42 = a1;
				}
				return 1;
			}
		} else {
			for (int i = 0; i < ptr_5D4594_2650668_cap; i++) {
				for (int j = 0; j < ptr_5D4594_2650668_cap; j++) {
					*(_BYTE*)(&ptr_5D4594_2650668[j][i].field_0) = 0;
				}
			}
			sub_426AC0_file3_fread(&v59, 2u);
			for (k = v59; (_WORD)v59 != (_WORD)-1; k = v59) {
				v47 = 0;
				v48 = (k >> 8) & 0x7F;
				v49 = k & 0x7F;
				if ((k & 0x8000u) != 0)
					v47 = -32768;
				if ((k & 0x80u) != 0)
					LOBYTE(v47) = v47 | 0x80;
				if (v47 < 0) {
					*(_BYTE*)(&ptr_5D4594_2650668[v48][v49].field_0) |= 0x1;
					sub_422A40(v62, (_BYTE*)(&ptr_5D4594_2650668[v48][v49].field_1));
				}
				if (v47 & 0x80) {
					*(_BYTE*)(&ptr_5D4594_2650668[v48][v49].field_0) |= 0x2;
					sub_422A40(v62, (_BYTE*)(&ptr_5D4594_2650668[v48][v49].field_6));
				}
				sub_426AC0_file3_fread(&v59, 2u);
			}
		}
		return 1;
	}
	if (a1) {
		sub_428170((_DWORD*)a1, &v70);
		v60 = v70.field_0 / 23;
		v18 = v70.field_8 / 23;
		v64 = v70.field_8 / 23;
		v63 = v70.field_C / 23;
		v61 = v70.field_4 / 23;
		v66 = v70.field_8 / 23 - v70.field_0 / 23 + 1;
		v67 = v70.field_C / 23 - v70.field_4 / 23 + 1;
		goto LABEL_43;
	}
	v2 = v65;
	v3 = 0;
	v4 = 0;
	for (l = 0; l < ptr_5D4594_2650668_cap * 44; l += 44) {
		if (v3)
			break;
		v2 = 0;
		v65 = l;
		v6 = ptr_5D4594_2650668;
		while (!*(_BYTE*)(l + *v6)) {
			++v2;
			++v6;
			if (v2 >= ptr_5D4594_2650668_cap)
				goto LABEL_14;
		}
		v61 = v4;
		v3 = 1;
	LABEL_14:
		++v4;
	}
	if (v2 == ptr_5D4594_2650668_cap && v4 == ptr_5D4594_2650668_cap)
		return 1;
	v7 = 0;
	v8 = 127;
	for (m = 5588; m >= 0; m -= 44) {
		if (v7)
			break;
		v10 = 0;
		v65 = m;
		v11 = ptr_5D4594_2650668;
		while (!*(_BYTE*)(m + *v11)) {
			++v10;
			++v11;
			if (v10 >= ptr_5D4594_2650668_cap)
				goto LABEL_24;
		}
		v63 = v8;
		v7 = 1;
	LABEL_24:
		--v8;
	}
	v12 = 0;
	v13 = 0;
	v14 = ptr_5D4594_2650668;
	do {
		if (v12)
			break;
		v15 = *v14;
		v16 = 0;
		while (!*v15) {
			++v16;
			v15 += 44;
			if (v16 >= ptr_5D4594_2650668_cap)
				goto LABEL_32;
		}
		v60 = v13;
		v12 = 1;
	LABEL_32:
		++v13;
		++v14;
	} while (v13 < ptr_5D4594_2650668_cap);
	v17 = &ptr_5D4594_2650668[ptr_5D4594_2650668_cap - 1];
	v18 = v64;
	v19 = 0;
	for (n = ptr_5D4594_2650668_cap - 1; n >= 0; --n) {
		if (v19)
			break;
		v21 = *v17;
		v22 = 0;
		while (!*v21) {
			++v22;
			v21 += 44;
			if (v22 >= ptr_5D4594_2650668_cap)
				goto LABEL_40;
		}
		v18 = n;
		v19 = 1;
	LABEL_40:
		--v17;
	}
	v64 = v18;
	v66 = v18 - v60 + 1;
	v67 = v63 - v61 + 1;
LABEL_43:
	sub_426AC0_file3_fread(&v60, 4u);
	sub_426AC0_file3_fread(&v61, 4u);
	sub_426AC0_file3_fread(&v66, 4u);
	sub_426AC0_file3_fread(&v67, 4u);
	if (a1) {
		v33 = v61;
		if (v61 > v63) {
		LABEL_75:
			v59 = 0xFFFF;
			sub_426AC0_file3_fread(&v59, 2u);
			return 1;
		}
		v34 = v60;
		while (1) {
			v35 = v34;
			v65 = v34;
			if (v34 <= v64)
				break;
		LABEL_74:
			if (++v33 > v63)
				goto LABEL_75;
		}
		v36 = 23 * v34 + 11;
		while (1) {
			if (!(((_BYTE)v33 + v35) & 1)) {
				if (v33 & 1) {
					v39 = (_BYTE*)((_DWORD)(ptr_5D4594_2650668[(v36 - 34) / 46]) + 44 * (23 * (v33 + 1) / 46));
					if (*v39 & 1) {
						v38 = v39 + 4;
						goto LABEL_70;
					}
				} else {
					v37 = (_BYTE*)((_DWORD)(ptr_5D4594_2650668[(v36 - 11) / 46]) + 44 * (23 * v33 / 46));
					if (*v37 & 2) {
						v38 = v37 + 24;
					LABEL_70:
						v69.field_0 = v36;
						v69.field_4 = 23 * v33 + 34;
						if (sub_427F30(&v69, (_DWORD*)a1)) {
							LOBYTE(v40) = 0;
							HIBYTE(v40) = v65;
							v68 = v33 | v40;
							sub_426AC0_file3_fread(&v68, 2u);
							sub_422A40(v62, v38);
						}
						v34 = v60;
						goto LABEL_73;
					}
				}
			}
		LABEL_73:
			v35 = v65 + 1;
			v36 += 23;
			if (++v65 > v64)
				goto LABEL_74;
		}
	}
	v23 = v61;
	if (v61 <= v63) {
		v24 = ptr_5D4594_2650668;
		v25 = 44 * v61;
		do {
			for (ii = v60; ii <= v18; ++ii) {
				v27 = *(_DWORD*)(v24 + 4 * ii);
				if (*(_BYTE*)(v25 + v27) & 3) {
					LOBYTE(v28) = 0;
					HIBYTE(v28) = ii;
					a1 = v23 | v28;
					if (*(_BYTE*)(v25 + v27) & 1) {
						v29 = a1;
						BYTE1(v29) |= 0x80u;
						a1 = v29;
					}
					if (*(_BYTE*)(v25 + *(_DWORD*)(v24 + 4 * ii)) & 2) {
						v30 = a1;
						LOBYTE(v30) = a1 | 0x80;
						a1 = v30;
					}
					sub_426AC0_file3_fread(&a1, 2u);
					v24 = ptr_5D4594_2650668;
				}
				v31 = (_BYTE*)(v25 + *(_DWORD*)(v24 + 4 * ii));
				if (*v31 & 1) {
					sub_422A40(v62, v31 + 4);
					v24 = ptr_5D4594_2650668;
				}
				v32 = (_BYTE*)(v25 + *(_DWORD*)(v24 + 4 * ii));
				if (*v32 & 2) {
					sub_422A40(v62, v32 + 24);
					v24 = ptr_5D4594_2650668;
				}
			}
			++v23;
			v25 += 44;
		} while (v23 <= v63);
	}
	v59 = 0xFFFF;
	sub_426AC0_file3_fread(&v59, 2u);
	return 1;
}

//----- (00422A40) --------------------------------------------------------
unsigned __int8 __cdecl sub_422A40(int a1, _BYTE* a2) {
	_BYTE* v2;              // esi
	size_t v3;              // eax
	char v4;                // al
	char v5;                // al
	int v6;                 // eax
	unsigned __int8 result; // al
	int i;                  // esi
	size_t v9;              // eax
	int v10;                // ebx
	bool v11;               // zf
	int* v12;               // edi
	int* v13;               // esi
	size_t v14;             // [esp+Ch] [ebp-8h]
	int v15;                // [esp+10h] [ebp-4h]

	v2 = a2;
	LOBYTE(a2) = *a2;
	v3 = sub_426AC0_file3_fread(&a2, 1u);
	LOWORD(v3) = *((_WORD*)v2 + 2);
	*(_DWORD*)v2 = (unsigned __int8)a2;
	v14 = v3;
	sub_426AC0_file3_fread(&v14, 2u);
	v4 = v2[8];
	*((_DWORD*)v2 + 1) = (__int16)v14;
	LOBYTE(a2) = v4;
	sub_426AC0_file3_fread(&a2, 1u);
	v5 = v2[12];
	*((_DWORD*)v2 + 2) = (unsigned __int8)a2;
	LOBYTE(a2) = v5;
	sub_426AC0_file3_fread(&a2, 1u);
	v6 = *((_DWORD*)v2 + 4);
	*((_DWORD*)v2 + 3) = (unsigned __int8)a2;
	for (LOBYTE(v15) = 0; v6; v6 = *(_DWORD*)(v6 + 16))
		LOBYTE(v15) = v15 + 1;
	sub_426AC0_file3_fread(&v15, 1u);
	result = getMemByte(0x5D4594, 3803300);
	if (*getMemU32Ptr(0x5D4594, 3803300)) {
		result = v15;
		v10 = 0;
		v11 = (_BYTE)v15 == 0;
		*((_DWORD*)v2 + 4) = 0;
		v12 = (int*)v2;
		if (!v11) {
			do {
				v13 = sub_422160(0, 0, 0, 0);
				sub_426AC0_file3_fread(&a2, 1u);
				*v13 = (unsigned __int8)a2;
				sub_426AC0_file3_fread(&v14, 2u);
				v13[1] = (__int16)v14;
				sub_426AC0_file3_fread(&a2, 1u);
				v13[2] = (unsigned __int8)a2;
				result = sub_426AC0_file3_fread(&a2, 1u);
				++v10;
				v13[3] = (unsigned __int8)a2;
				v12[4] = (int)v13;
				v12 = v13;
			} while (v10 < (unsigned __int8)v15);
		}
	} else {
		for (i = *((_DWORD*)v2 + 4); i; i = *(_DWORD*)(i + 16)) {
			LOBYTE(a2) = *(_BYTE*)i;
			v9 = sub_426AC0_file3_fread(&a2, 1u);
			LOWORD(v9) = *(_WORD*)(i + 4);
			v14 = v9;
			sub_426AC0_file3_fread(&v14, 2u);
			LOBYTE(a2) = *(_BYTE*)(i + 8);
			sub_426AC0_file3_fread(&a2, 1u);
			LOBYTE(a2) = *(_BYTE*)(i + 12);
			result = sub_426AC0_file3_fread(&a2, 1u);
		}
	}
	return result;
}

//----- (00422C10) --------------------------------------------------------
int __cdecl sub_422C10(int a1, int a2) {
	int v3;      // ecx
	char v4;     // bl
	int v5;      // esi
	int i;       // edx
	_DWORD* v7;  // eax
	char v8;     // bl
	int v9;      // esi
	int j;       // edx
	int v11;     // ecx
	_DWORD* v12; // eax
	char v13;    // bl
	int v14;     // edx
	_BYTE** v15; // esi
	_BYTE* v16;  // ecx
	int v17;     // eax
	_BYTE** v18; // esi
	int v19;     // edi
	char v20;    // bl
	int k;       // edx
	_BYTE* v22;  // ecx
	int v23;     // eax
	int v24;     // esi
	int v26;     // edi
	int v27;     // ebp
	int l;       // eax
	int m;       // esi
	int n;       // eax
	int ii;      // esi
	int v35;     // ebx
	int v36;     // eax
	int v37;     // ebp
	int v38;     // edi
	_BYTE* v39;  // eax
	int v40;     // esi
	_BYTE* v41;  // eax
	int jj;      // eax
	int kk;      // esi
	int v44;     // ecx
	int v45;     // edx
	int v46;     // ebx
	int v47;     // edi
	int v48;     // esi
	int v49;     // edi
	int v51;     // esi
	int v52;     // esi
	int v55;     // ecx
	int v56;     // esi
	int v57;     // eax
	int v58;     // ebp
	int v59;     // esi
	_BYTE* v60;  // eax
	int v61;     // ebx
	int v62;     // edi
	int* v63;    // esi
	int v64;     // edi
	int v66;     // esi
	int v67;     // ebp
	int* v68;    // edi
	int* v69;    // esi
	bool v70;    // cc
	_BYTE* v71;  // eax
	int v72;     // ebx
	int v73;     // edi
	int* v74;    // esi
	int v75;     // [esp+10h] [ebp-34h]
	int v76;     // [esp+14h] [ebp-30h]
	int v77;     // [esp+18h] [ebp-2Ch]
	int v78;     // [esp+1Ch] [ebp-28h]
	int v79;     // [esp+20h] [ebp-24h]
	int v80;     // [esp+24h] [ebp-20h]
	int v81;     // [esp+28h] [ebp-1Ch]
	int2 v82;    // [esp+2Ch] [ebp-18h]
	int4 v83;    // [esp+34h] [ebp-10h]

	if ((__int16)a1 < 3)
		return 0;
	if (!*getMemU32Ptr(0x5D4594, 3803300)) {
		if (a2) {
			sub_428170((_DWORD*)a2, &v83);
			v76 = v83.field_0 / 23;
			v80 = v83.field_8 / 23;
			v77 = v83.field_4 / 23;
			v81 = v83.field_C / 23;
			v24 = v81;
			v78 = v83.field_8 / 23 - v83.field_0 / 23 + 1;
			v79 = v81 - v83.field_4 / 23 + 1;
		} else {
			v3 = 0;
			v4 = 0;
			v5 = 0;
			for (i = 0; i < ptr_5D4594_2650668_cap * 44; i += 44) {
				if (v4)
					break;
				v3 = 0;
				a1 = i;
				v7 = ptr_5D4594_2650668;
				while (!*(_BYTE*)(i + *v7)) {
					++v3;
					++v7;
					if (v3 >= ptr_5D4594_2650668_cap)
						goto LABEL_12;
				}
				v77 = v5;
				v4 = 1;
			LABEL_12:
				++v5;
			}
			if (v3 == ptr_5D4594_2650668_cap && v5 == ptr_5D4594_2650668_cap)
				return 1;
			v8 = 0;
			v9 = 127;
			for (j = 5588; j >= 0; j -= 44) {
				if (v8)
					break;
				v11 = 0;
				a1 = j;
				v12 = ptr_5D4594_2650668;
				while (!*(_BYTE*)(j + *v12)) {
					++v11;
					++v12;
					if (v11 >= ptr_5D4594_2650668_cap)
						goto LABEL_22;
				}
				v81 = v9;
				v8 = 1;
			LABEL_22:
				--v9;
			}
			v13 = 0;
			v14 = 0;
			v15 = ptr_5D4594_2650668;
			do {
				if (v13)
					break;
				v16 = *v15;
				v17 = 0;
				while (!*v16) {
					++v17;
					v16 += 44;
					if (v17 >= ptr_5D4594_2650668_cap)
						goto LABEL_30;
				}
				v76 = v14;
				v13 = 1;
			LABEL_30:
				++v14;
				++v15;
			} while (v14 < 128);
			v18 = (_BYTE**)(ptr_5D4594_2650668 + ptr_5D4594_2650668_cap - 1);
			v19 = v80;
			v20 = 0;
			for (k = ptr_5D4594_2650668_cap - 1; k >= 0; --k) {
				if (v20)
					break;
				v22 = *v18;
				v23 = 0;
				while (!*v22) {
					++v23;
					v22 += 44;
					if (v23 >= ptr_5D4594_2650668_cap)
						goto LABEL_38;
				}
				v19 = k;
				v20 = 1;
			LABEL_38:
				--v18;
			}
			v24 = v81;
			v80 = v19;
			v78 = v19 - v76 + 1;
			v79 = v81 - v77 + 1;
		}
		sub_426AC0_file3_fread(&v76, 4u);
		sub_426AC0_file3_fread(&v77, 4u);
		sub_426AC0_file3_fread(&v78, 4u);
		sub_426AC0_file3_fread(&v79, 4u);
		if (!a2) {
			if (v77 > v24)
				return 1;

			v26 = v76;
			v27 = v80;
			int v28 = v77;
			a2 = v81 - v77 + 1;
			do {
				if (v26 <= v27) {
					do {
						obj_5D4594_2650668_t* obj = &ptr_5D4594_2650668[v26][v28];

						sub_426AC0_file3_fread((_BYTE*)(&obj->field_0), 1);
						if (obj->field_0 & 0x1) {
							sub_426AC0_file3_fread(&obj->field_1, 16);
							LOBYTE(v75) = 0;
							for (l = obj->field_5; l; l = *(_DWORD*)(l + 16)) {
								LOBYTE(v75) = v75 + 1;
							}
							sub_426AC0_file3_fread(&v75, 1);
							for (m = obj->field_5; m; m = *(_DWORD*)(m + 16)) {
								sub_426AC0_file3_fread((_BYTE*)m, 16);
							}
						}
						if (obj->field_0 & 0x2) {
							sub_426AC0_file3_fread(&obj->field_6, 16);
							LOBYTE(v75) = 0;
							for (n = obj->field_10; n; n = *(_DWORD*)(n + 16)) {
								LOBYTE(v75) = v75 + 1;
							}
							sub_426AC0_file3_fread(&v75, 1);
							for (ii = obj->field_10; ii; ii = *(_DWORD*)(ii + 16)) {
								sub_426AC0_file3_fread((_BYTE*)ii, 16);
							}
						}
						++v26;
					} while (v26 <= v27);
					v26 = v76;
				}
				v28++;
				--a2;
			} while (a2);
			return 1;
		}
		v35 = v77;
		if (v77 > v24)
			return 1;
		v36 = v76;
	LABEL_61:
		v37 = v36;
		if (v36 > v80)
			goto LABEL_78;
		v38 = 23 * v36 + 11;
		while (1) {
			if (!(((_BYTE)v35 + (_BYTE)v37) & 1)) {
				if (v35 & 1) {
					v41 = (_BYTE*)((_DWORD)(ptr_5D4594_2650668[(v38 - 34) / 46]) + 44 * (23 * (v35 + 1) / 46));
					if (!(*v41 & 1))
						goto LABEL_75;
					v40 = (int)(v41 + 4);
				} else {
					v39 = (_BYTE*)((_DWORD)(ptr_5D4594_2650668[(v38 - 11) / 46]) + 44 * (23 * v35 / 46));
					if (!(*v39 & 2))
						goto LABEL_75;
					v40 = (int)(v39 + 24);
				}
				v82.field_0 = v38;
				v82.field_4 = 23 * v35 + 34;
				if (sub_427F30(&v82, (_DWORD*)a2)) {
					LOBYTE(a1) = 1;
					sub_426AC0_file3_fread(&a1, 1u);
					sub_426AC0_file3_fread((_BYTE*)v40, 0x10u);
					LOBYTE(v75) = 0;
					for (jj = *(_DWORD*)(v40 + 16); jj; jj = *(_DWORD*)(jj + 16))
						LOBYTE(v75) = v75 + 1;
					sub_426AC0_file3_fread(&v75, 1u);
					for (kk = *(_DWORD*)(v40 + 16); kk; kk = *(_DWORD*)(kk + 16))
						sub_426AC0_file3_fread((_BYTE*)kk, 0x10u);
					goto LABEL_76;
				}
			}
		LABEL_75:
			LOBYTE(a1) = 0;
			sub_426AC0_file3_fread(&a1, 1u);
		LABEL_76:
			++v37;
			v38 += 23;
			if (v37 > v80) {
				v36 = v76;
			LABEL_78:
				if (++v35 > v81)
					return 1;
				goto LABEL_61;
			}
		}
	}
	sub_426AC0_file3_fread(&v76, 4u);
	sub_426AC0_file3_fread(&v77, 4u);
	sub_426AC0_file3_fread(&v78, 4u);
	sub_426AC0_file3_fread(&v79, 4u);
	if (!a2) {
		for (int ll = 0; ll < ptr_5D4594_2650668_cap; ll++) {
			for (int mm = 0; mm < ptr_5D4594_2650668_cap; mm++) {
				*(_BYTE*)&ptr_5D4594_2650668[mm][ll] = 0;
			}
		}
		v55 = v77;
		v81 = v77;
		if (v77 < v77 + v79) {
			v56 = v78;
			a2 = 44 * v77;
			v57 = v76;
			do {
				v58 = v57;
				if (v57 < v56 + v57) {
					do {
						v59 = a2;
						sub_426AC0_file3_fread((_BYTE*)(a2 + (_DWORD)(ptr_5D4594_2650668[v58])), 1u);
						v60 = (_BYTE*)(v59 + (_DWORD)(ptr_5D4594_2650668[v58]));
						if (*v60 & 1) {
							sub_426AC0_file3_fread(v60 + 4, 0x10u);
							sub_426AC0_file3_fread(&v75, 1u);
							if ((_BYTE)v75) {
								v61 = 0;
								v62 = (_DWORD)(ptr_5D4594_2650668[v58]) + v59 + 4;
								if ((_BYTE)v75) {
									do {
										v63 = sub_422160(0, 0, 0, 0);
										sub_426AC0_file3_fread(v63, 0x10u);
										*(_DWORD*)(v62 + 16) = v63;
										++v61;
										v62 = (int)v63;
									} while (v61 < (unsigned __int8)v75);
								}
							} else {
								*(_DWORD*)((_DWORD)(ptr_5D4594_2650668[v58]) + a2 + 20) = 0;
							}
						}
						v71 = (_BYTE*)((_DWORD)(ptr_5D4594_2650668[v58]) + a2);
						if (*v71 & 2) {
							sub_426AC0_file3_fread(v71 + 24, 0x10u);
							sub_426AC0_file3_fread(&v75, 1u);
							if ((_BYTE)v75) {
								v72 = 0;
								v73 = (_DWORD)(ptr_5D4594_2650668[v58]) + a2 + 24;
								if ((_BYTE)v75) {
									do {
										v74 = sub_422160(0, 0, 0, 0);
										sub_426AC0_file3_fread(v74, 0x10u);
										*(_DWORD*)(v73 + 16) = v74;
										++v72;
										v73 = (int)v74;
									} while (v72 < (unsigned __int8)v75);
								}
							} else {
								*(_DWORD*)((_DWORD)(ptr_5D4594_2650668[v58]) + a2 + 40) = 0;
							}
						}
						v56 = v78;
						v57 = v76;
						++v58;
					} while (v58 < v78 + v76);
					v55 = v77;
				}
				v70 = ++v81 < v55 + v79;
				a2 += 44;
			} while (v70);
		}
		return 1;
	}
	sub_428170((_DWORD*)a2, &v83);
	v44 = v83.field_0 / 23;
	v76 = v83.field_0 / 23;
	v45 = v83.field_4 / 23;
	v77 = v83.field_4 / 23;
	v46 = v83.field_4 / 23;
	if (v83.field_4 / 23 >= v83.field_4 / 23 + v79)
		return 1;
	v47 = v78;
	do {
		a2 = v44;
		if (v44 < v47 + v44) {
			v81 = 23 * v44;
			v48 = 23 * v44;
			do {
				sub_426AC0_file3_fread(&a1, 1u);
				if ((_BYTE)a1) {
					if (v46 & 1) {
						v64 = (v48 - 23) / 46;
						v66 = (v46 + 23) / 46;
						if (nox_common_gameFlags_check_40A5C0(0x400000)) {
							v52 = *sub_5040A0(v64, v66, COERCE_FLOAT(1));
						} else {
							*(_BYTE*)((_DWORD)(ptr_5D4594_2650668[v64]) + 44 * v66) |= 1u;
							v52 = (_DWORD)(ptr_5D4594_2650668[v64]) + 44 * v66 + 4;
						}
					} else {
						v49 = v48 / 46;
						v51 = v46 / 46;
						if (nox_common_gameFlags_check_40A5C0(0x400000)) {
							v52 = *sub_5040A0(v49, v51, COERCE_FLOAT(2));
						} else {
							*(_BYTE*)((_DWORD)(ptr_5D4594_2650668[v49]) + 44 * v51) |= 2u;
							v52 = (_DWORD)(ptr_5D4594_2650668[v49]) + 44 * v51 + 24;
						}
					}
					sub_426AC0_file3_fread((_BYTE*)v52, 0x10u);
					sub_426AC0_file3_fread(&v75, 1u);
					if ((_BYTE)v75) {
						v67 = 0;
						v68 = (int*)v52;
						if ((_BYTE)v75) {
							do {
								v69 = sub_422160(0, 0, 0, 0);
								sub_426AC0_file3_fread(v69, 0x10u);
								v68[4] = (int)v69;
								++v67;
								v68 = v69;
							} while (v67 < (unsigned __int8)v75);
						}
					} else {
						*(_DWORD*)(v52 + 16) = 0;
					}
				}
				v47 = v78;
				v44 = v76;
				v48 = v81 + 23;
				v70 = ++a2 < v78 + v76;
				v81 += 23;
			} while (v70);
			v45 = v77;
		}
		++v46;
	} while (v46 < v45 + v79);
	return 1;
}

//----- (004235C0) --------------------------------------------------------
int __cdecl sub_4235C0(const char* a1, char* a2, obj_412ae0_t* a3) {
	float v4 = sub_423730_parse_float();
	sub_4235F0(a1, v4, a3);
	return 1;
}

//----- (004235F0) --------------------------------------------------------
int __cdecl sub_4235F0(const char* a1, float a2, obj_412ae0_t* a3) {
	if (!strcmp((const char*)a1, "ATTACKEFFECT")) {
		a3->field_11 = a2;
	} else if (!strcmp((const char*)a1, "ATTACKPREHITEFFECT")) {
		a3->field_14 = a2;
	} else if (!strcmp((const char*)a1, "ATTACKPREDAMAGEEFFECT")) {
		a3->field_17 = a2;
	} else if (!strcmp((const char*)a1, "DEFENDEFFECT")) {
		a3->field_20 = a2;
	} else if (!strcmp((const char*)a1, "DEFENDCOLLIDEEFFECT")) {
		a3->field_23 = a2;
	} else if (!strcmp((const char*)a1, "UPDATEEFFECT")) {
		a3->field_26 = a2;
	} else if (!strcmp((const char*)a1, "ENGAGEEFFECT")) {
		a3->field_30 = a2;
	} else if (!strcmp((const char*)a1, "DISENGAGEEFFECT")) {
		a3->field_32 = a2;
	} else {
		return 0;
	}
	return 1;
}

//----- (00423730) --------------------------------------------------------
double sub_423730_parse_float() {
	char v2[6];
	strcpy(v2, " =\n\r\t");
	char* v0 = strtok(0, v2);
	if (!v0)
		return -1.0;
	return atof(v0);
}

//----- (00423780) --------------------------------------------------------
int __cdecl sub_423780(const char* a1, char* a2, obj_412ae0_t* a3) {
	int v3 = sub_4238F0_parse_int();
	sub_4237B0(a1, v3, a3);
	return 1;
}

//----- (004237B0) --------------------------------------------------------
int __cdecl sub_4237B0(const char* a1, int a2, obj_412ae0_t* a3) {
	if (!strcmp(a1, "ATTACKEFFECT")) {
		a3->field_12 = a2;
	} else if (!strcmp(a1, "ATTACKPREHITEFFECT")) {
		a3->field_15 = a2;
	} else if (!strcmp(a1, "ATTACKPREDAMAGEEFFECT")) {
		a3->field_18 = a2;
	} else if (!strcmp(a1, "DEFENDEFFECT")) {
		a3->field_21 = a2;
	} else if (!strcmp(a1, "DEFENDCOLLIDEEFFECT")) {
		a3->field_24 = a2;
	} else if (!strcmp(a1, "UPDATEEFFECT")) {
		a3->field_27 = a2;
	} else if (!strcmp(a1, "ENGAGEEFFECT")) {
		a3->field_31 = a2;
	} else if (!strcmp(a1, "DISENGAGEEFFECT")) {
		a3->field_33 = a2;
	} else {
		return 0;
	}
	return 1;
}

//----- (004238F0) --------------------------------------------------------
int sub_4238F0_parse_int() {
	char v2[6];
	strcpy(v2, " =\n\r\t");
	char* v0 = strtok(0, v2);
	if (!v0)
		return -1;
	return atoi(v0);
}

//----- (00423930) --------------------------------------------------------
void __cdecl set_bitmask_flags_from_plus_separated_names_423930(const char* input, _DWORD* bitmask,
																const char** allowed_names) {
	char input_copy[256];
	strcpy(input_copy, input);
	if (strncmp(input_copy, "NULL", 4u) == 0) {
		return;
	}

	char* cur_value = strtok(input_copy, "+");
	while (cur_value) {
		set_one_bitmask_flag_by_name_4239C0(cur_value, bitmask, allowed_names);
		cur_value = strtok(0, "+");
	}
}

//----- (004239C0) --------------------------------------------------------
int __cdecl set_one_bitmask_flag_by_name_4239C0(char* name, _DWORD* bitmask, const char** allowed_names) {
	for (char i = 0; allowed_names[i]; ++i) {
		if (!_strcmpi(allowed_names[i], name)) {
			*bitmask |= 1 << i;
			return 1;
		}
	}

	return 0;
}

//----- (00423A10) --------------------------------------------------------
void __cdecl set_bitmask_flags_from_plus_separated_names_multiple_423A10(const char* input, _DWORD* bitmask) {
	char input_copy[256];
	strcpy(input_copy, input);
	if (strncmp(input_copy, "NULL", 4u) == 0) {
		return;
	}

	char* cur_value = strtok(input_copy, "+");
	while (cur_value) {
		// Set of arrays of various types of data. Clothing types, NPC types, etc.
		_DWORD* cur_allowed_values = getMemU32Ptr(0x587000, 61096);

		while (*cur_allowed_values) {
			if (set_one_bitmask_flag_by_name_4239C0(cur_value, bitmask, (const char**)cur_allowed_values)) {
				break;
			}
			cur_allowed_values += 32;
		}
		cur_value = strtok(0, "+");
	}
}

//----- (00423AD0) --------------------------------------------------------
int __cdecl nox_parse_shape(nox_shape* s, char* buf) {
	if (!strncmp(buf, "NULL", 4)) {
		s->kind = NOX_SHAPE_NONE;
		return 1;
	} else if (!strncmp(buf, "CENTER", 6)) {
		s->kind = NOX_SHAPE_CENTER;
		return 1;
	} else if (!strncmp(buf, "CIRCLE", 6)) {
		s->kind = NOX_SHAPE_CIRCLE;
		sscanf(buf, "%*s %f", &s->circle_r);
		s->circle_r2 = s->circle_r * s->circle_r;
		return 1;
	} else if (!strncmp(buf, "BOX", 3)) {
		s->kind = NOX_SHAPE_BOX;
		sscanf(buf, "%*s %f %f", &s->box_w, &s->box_h);
		nox_shape_box_calc(s);
		return 1;
	}
	return 0;
}

//----- (00423F80) --------------------------------------------------------
HANDLE __cdecl sub_423F80(LPCSTR lpFileName, int a2, int a3, int a4) {
	HANDLE result;                         // eax
	HANDLE v5;                             // esi
	char* v6;                              // edi
	unsigned __int8 v7;                    // cl
	HANDLE v8;                             // [esp+4h] [ebp-248h]
	char FileName[260];                    // [esp+8h] [ebp-244h]
	struct _WIN32_FIND_DATAA FindFileData; // [esp+10Ch] [ebp-140h]

	result = FindFirstFileA(lpFileName, &FindFileData);
	v5 = result;
	v8 = result;
	if (result != (HANDLE)-1) {
		do {
			if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
				++*(_DWORD*)a2;
				if (_strcmpi(FindFileData.cFileName, ".")) {
					if (_strcmpi(FindFileData.cFileName, "..")) {
						strcpy(FileName, lpFileName);
						*((_BYTE*)&v8 + strlen(FileName) + 3) = 0;
						strcat(FileName, FindFileData.cFileName);
						v6 = &FileName[strlen(FileName) + 1];
						v7 = getMemByte(0x587000, 64698);
						*(_WORD*)--v6 = *getMemU16Ptr(0x587000, 64696);
						v6[2] = v7;
						sub_423F80(FileName, a2, a3, a4);
						v5 = v8;
					}
				}
			} else {
				++*(_DWORD*)a3;
				*(_DWORD*)a4 += FindFileData.nFileSizeLow;
			}
		} while (FindNextFileA(v5, &FindFileData));
		result = (HANDLE)FindClose(v5);
	}
	return result;
}
// 423F80: using guessed type CHAR FileName[260];

//----- (004240F0) --------------------------------------------------------
int __cdecl sub_4240F0(int a1, const char* a2, int a3) {
	const char* v3;      // esi
	int v4;              // ebp
	unsigned __int8* v5; // edi

	v3 = *(const char**)getMemAt(0x587000, 64704);
	v4 = 0;
	if (!*getMemU32Ptr(0x587000, 64704))
		return 0;
	v5 = getMemAt(0x587000, 64704);
	while (strcmp(a2, v3)) {
		v3 = (const char*)*((_DWORD*)v5 + 2);
		v5 += 8;
		++v4;
		if (!v3)
			return 0;
	}
	*(_DWORD*)(*getMemU32Ptr(0x587000, 8 * v4 + 64708) + a1) = a3;
	return 1;
}

//----- (00424170) --------------------------------------------------------
int __cdecl sub_424170(char* a1) {
	FILE* v2;     // ebp
	_DWORD* v3;   // ebx
	char* v4;     // edx
	int v5;       // eax
	char v6[256]; // [esp+10h] [ebp-200h]
	char v7[256]; // [esp+110h] [ebp-100h]

	v2 = sub_408CC0_fopen(a1, 0);
	if (!v2) {
		return 0;
	}
	if (!sub_408D40(v2, 5)) {
		return 0;
	}
	while (sub_409470(v2, v6)) {
		v3 = calloc(1u, 0x54u);
		v3[19] = dword_5d4594_588120;
		v3[20] = 0;
		dword_5d4594_588120 = v3;
		v4 = (char*)malloc(strlen(v6) + 1);
		*v3 = v4;
		strcpy(v4, v6);
		while (sub_409470(v2, v6) && strcmp(v6, "END") && sub_409470(v2, v7)) {
			v5 = sub_40AF50(v7);
			if (!sub_4240F0((int)v3, v6, v5))
				return 0;
		}
	}
	sub_408D90(v2);
	return 1;
}

//----- (004242C0) --------------------------------------------------------
void sub_4242C0() {
	int v0; // esi
	int v1; // edi

	v0 = dword_5d4594_588120;
	if (dword_5d4594_588120) {
		do {
			v1 = *(_DWORD*)(v0 + 76);
			free(*(LPVOID*)v0);
			free((LPVOID)v0);
			v0 = v1;
		} while (v1);
		dword_5d4594_588120 = 0;
	} else {
		dword_5d4594_588120 = 0;
	}
}

//----- (00424300) --------------------------------------------------------
int __cdecl sub_424300(int a1) {
	int result; // eax

	result = a1;
	if (a1) {
		if (*(_BYTE*)(a1 + 8) & 2)
			result = *(_DWORD*)(*(_DWORD*)(a1 + 748) + 488);
		else
			result = 0;
	}
	return result;
}

//----- (00424320) --------------------------------------------------------
int __cdecl sub_424320(int a1, int a2) {
	int result; // eax

	result = a1;
	if (a1) {
		if (*(_BYTE*)(a1 + 8) & 2) {
			*(_DWORD*)(*(_DWORD*)(a1 + 748) + 488) = a2;
			result = 1;
		} else {
			result = 0;
		}
	}
	return result;
}

//----- (00424350) --------------------------------------------------------
const char** __cdecl sub_424350(const char* a1) {
	int v1; // edi

	if (!a1)
		return 0;
	v1 = dword_5d4594_588120;
	if (!dword_5d4594_588120)
		return 0;
	while (strcmp(*(const char**)v1, a1)) {
		v1 = *(_DWORD*)(v1 + 76);
		if (!v1)
			return 0;
	}
	return (const char**)v1;
}

//----- (004243C0) --------------------------------------------------------
LPVOID sub_4243C0() { return *(LPVOID*)&dword_5d4594_588120; }

//----- (004243D0) --------------------------------------------------------
int __cdecl sub_4243D0(int a1) {
	int result; // eax

	if (a1)
		result = *(_DWORD*)(a1 + 76);
	else
		result = 0;
	return result;
}

//----- (004243E0) --------------------------------------------------------
void sub_4243E0() { nox_srand(0x9DEu); }

//----- (004243F0) --------------------------------------------------------
int __cdecl sub_4243F0(const char* a1) {
	const char* v1;      // ecx
	int v2;              // ebp
	unsigned __int8* v3; // edi

	v1 = *(const char**)getMemAt(0x587000, 65448);
	v2 = 0;
	if (!*getMemU32Ptr(0x587000, 65448))
		return 0;
	v3 = getMemAt(0x587000, 65448);
	while (strcmp(v1, a1)) {
		v1 = (const char*)*((_DWORD*)v3 + 1);
		v3 += 4;
		++v2;
		if (!v1)
			return 0;
	}
	return v2;
}

// 424460: using guessed type char var_20[32];
// 424460: using guessed type char var_120[256];

//----- (00424800) --------------------------------------------------------
int __cdecl sub_424800(int a1, int a2) { return *getMemU32Ptr(0x5D4594, 4 * (a2 + 20 * a1) + 588192); }

//----- (00424820) --------------------------------------------------------
void* sub_424820() { return *(void**)&dword_587000_66120; }

//----- (00424830) --------------------------------------------------------
int __cdecl sub_424830(int a1, int a2) {
	int result; // eax

	if (a1 && a2 >= 0 && a2 <= 8)
		result = *(_DWORD*)(a1 + 4 * a2 + 4);
	else
		result = 0;
	return result;
}

//----- (00424870) --------------------------------------------------------
char* __cdecl sub_424870(int a1) { return *(char**)getMemAt(0x587000, 4 * a1 + 65448); }

//----- (00424880) --------------------------------------------------------
int __cdecl sub_424880(const char* a1) {
	const char* v1;      // ecx
	int v2;              // ebp
	unsigned __int8* v3; // edi
	int result;          // eax

	v1 = *(const char**)getMemAt(0x587000, 65316);
	v2 = 0;
	if (*getMemU32Ptr(0x587000, 65316)) {
		v3 = getMemAt(0x587000, 65316);
		do {
			if (!strcmp(v1, a1))
				break;
			v1 = (const char*)*((_DWORD*)v3 + 1);
			v3 += 4;
			++v2;
		} while (v1);
	}
	if (*getMemU32Ptr(0x587000, 4 * v2 + 65316))
		result = v2;
	else
		result = -1;
	return result;
}

//----- (004248F0) --------------------------------------------------------
char* __cdecl sub_4248F0(int a1) { return *(char**)getMemAt(0x587000, 4 * a1 + 65316); }

//----- (00424900) --------------------------------------------------------
int __cdecl sub_424900(int a1) {
	int result;         // eax
	unsigned __int8* i; // ecx

	result = 0;
	for (i = getMemAt(0x587000, 65188); *(_DWORD*)i != a1; i += 4)
		++result;
	return result;
}

//----- (00424920) --------------------------------------------------------
int __cdecl sub_424920(int a1) { return *getMemU32Ptr(0x587000, 4 * a1 + 65188); }

//----- (00424930) --------------------------------------------------------
int __cdecl sub_424930(int a1) {
	int result; // eax

	if (a1 > 0 && a1 < 137 && *getMemU32Ptr(0x5D4594, 80 * a1 + 588148))
		result = *getMemU32Ptr(0x5D4594, 80 * a1 + 588124);
	else
		result = 0;
	return result;
}

//----- (00424960) --------------------------------------------------------
int __cdecl sub_424960(wchar_t* a1) {
	int v1;              // edi
	unsigned __int8* v2; // esi

	v1 = 1;
	v2 = getMemAt(0x5D4594, 588204);
	while (!*((_DWORD*)v2 + 6) || nox_wcscmp(*(const wchar_t**)v2, a1)) {
		v2 += 80;
		++v1;
		if ((int)v2 >= (int)getMemAt(0x5D4594, 599084))
			return 0;
	}
	return v1;
}

//----- (004249A0) --------------------------------------------------------
int __cdecl sub_4249A0(int a1, int a2) {
	int result; // eax
	float v3;   // [esp+0h] [ebp-4h]
	float v4;   // [esp+0h] [ebp-4h]
	float v5;   // [esp+0h] [ebp-4h]

	if (a2 != 2)
		return getMemByte(0x5D4594, 80 * a1 + 588186);
	switch (a1) {
	case 24:
		v5 = sub_419D40(getMemAt(0x587000, 69668));
		result = nox_float2int(v5);
		break;
	case 43:
		v4 = sub_419D40(getMemAt(0x587000, 69688));
		result = nox_float2int(v4);
		break;
	case 56:
		v3 = sub_419D40(getMemAt(0x587000, 69648));
		result = nox_float2int(v3);
		break;
	default:
		result = getMemByte(0x5D4594, 80 * a1 + 588186);
		break;
	}
	return result;
}

//----- (00424A20) --------------------------------------------------------
char* __cdecl sub_424A20(int a1) { return (char*)getMemAt(0x5D4594, 80 * a1 + 588152); }

//----- (00424A30) --------------------------------------------------------
int __cdecl sub_424A30(int a1) { return *getMemU32Ptr(0x5D4594, 80 * a1 + 588128); }

//----- (00424A50) --------------------------------------------------------
BOOL __cdecl sub_424A50(int a1, int a2) { return (a2 & *getMemU32Ptr(0x5D4594, 80 * a1 + 588140)) != 0; }

//----- (00424A70) --------------------------------------------------------
int __cdecl sub_424A70(int a1) { return *getMemU32Ptr(0x5D4594, 80 * a1 + 588140); }

//----- (00424A90) --------------------------------------------------------
int __cdecl sub_424A90(int a1) { return *getMemU32Ptr(0x5D4594, 80 * a1 + 588132); }

//----- (00424AB0) --------------------------------------------------------
int __cdecl sub_424AB0(int a1) { return *getMemU32Ptr(0x5D4594, 80 * a1 + 588136); }

//----- (00424AD0) --------------------------------------------------------
int sub_424AD0() {
	int result;          // eax
	unsigned __int8* v1; // ecx

	result = 1;
	v1 = getMemAt(0x5D4594, 588228);
	while (!*(_DWORD*)v1) {
		v1 += 80;
		++result;
		if ((int)v1 >= (int)getMemAt(0x5D4594, 599108))
			return 0;
	}
	return result;
}

//----- (00424AF0) --------------------------------------------------------
int __cdecl sub_424AF0(int a1) {
	int result;          // eax
	unsigned __int8* v2; // ecx

	result = a1 + 1;
	if (a1 + 1 >= 137)
		return 0;
	v2 = getMemAt(0x5D4594, 80 * result + 588148);
	while (!*(_DWORD*)v2) {
		v2 += 80;
		++result;
		if ((int)v2 >= (int)getMemAt(0x5D4594, 599108))
			return 0;
	}
	return result;
}

//----- (00424B20) --------------------------------------------------------
int __cdecl sub_424B20(int a1) {
	int result;         // eax
	unsigned __int8* i; // ecx

	if (!a1)
		return 0;
	result = a1 - 1;
	if (a1 - 1 <= 0)
		return 0;
	for (i = getMemAt(0x5D4594, 80 * result + 588148); !*(_DWORD*)i; i -= 80) {
		if (--result <= 0)
			return 0;
	}
	return result;
}

//----- (00424B50) --------------------------------------------------------
int __cdecl sub_424B50(int a1) { return *getMemU32Ptr(0x5D4594, 80 * a1 + 588148); }

//----- (00424B70) --------------------------------------------------------
int __cdecl sub_424B70(int a1) { return *getMemU32Ptr(0x5D4594, 80 * a1 + 588144); }

//----- (00424B90) --------------------------------------------------------
int __cdecl sub_424B90(int a1) {
	int result; // eax

	result = 80 * a1;
	*getMemU32Ptr(0x5D4594, 80 * a1 + 588144) = 1;
	return result;
}

//----- (00424BB0) --------------------------------------------------------
int __cdecl sub_424BB0(int a1) {
	int result; // eax

	result = 80 * a1;
	*getMemU32Ptr(0x5D4594, 80 * a1 + 588144) = 0;
	return result;
}

//----- (00424BD0) --------------------------------------------------------
int sub_424BD0() {
	int v0;     // esi
	int v1;     // edi
	int result; // eax

	v0 = 1;
	v1 = 136;
	do {
		result = sub_424B90(v0++);
		--v1;
	} while (v1);
	return result;
}

//----- (00424BF0) --------------------------------------------------------
unsigned int __cdecl sub_424BF0(int a1) {
	unsigned int result; // eax

	if (a1 <= 0 || a1 >= 137 || nox_common_gameFlags_check_40A5C0(4096) && a1 == 4)
		result = 0;
	else
		result = ((unsigned int)~*getMemU32Ptr(0x5D4594, 80 * a1 + 588140) >> 22) & 1;
	return result;
}

//----- (00424C40) --------------------------------------------------------
__int16 __cdecl sub_424C40(float a1) {
	float v2; // [esp+4h] [ebp+4h]

	if ((int)SLODWORD(a1) <= 0 || SLODWORD(a1) >= 137)
		return 0;
	v2 = (double)*getMemU16Ptr(0x5D4594, 80 * LODWORD(a1) + 588188);
	if (nox_common_gameFlags_check_40A5C0(4096))
		v2 = sub_419D40(getMemAt(0x587000, 69708)) * v2;
	return nox_float2int(v2);
}

//----- (00424CB0) --------------------------------------------------------
char __cdecl sub_424CB0(int a1) {
	char v1;             // bl
	int v2;              // esi
	unsigned __int8* v3; // edi

	v1 = 0;
	v2 = 0;
	if (*(int*)&dword_587000_66116 <= 0)
		return 0;
	v3 = getMemAt(0x587000, 66000);
	do {
		if (sub_4FF350(a1, *(_DWORD*)v3))
			++v1;
		++v2;
		v3 += 4;
	} while (v2 < *(int*)&dword_587000_66116);
	return v1;
}

//----- (00424D00) --------------------------------------------------------
int sub_424D00() {
	int result; // eax

	if (*(int*)&dword_587000_66116 <= 0)
		result = -1;
	else
		result = *getMemU32Ptr(0x587000, 66000);
	return result;
}

//----- (00424D20) --------------------------------------------------------
int __cdecl sub_424D20(int a1) {
	int v1;             // eax
	unsigned __int8* i; // edx

	v1 = 0;
	if (*(int*)&dword_587000_66116 <= 0)
		return -1;
	for (i = getMemAt(0x587000, 66000); *(int*)i != a1 || v1 >= *(int*)&dword_587000_66116 - 1; i += 4) {
		if (++v1 >= *(int*)&dword_587000_66116)
			return -1;
	}
	return *getMemU32Ptr(0x587000, 4 * v1 + 66004);
}

//----- (00424D60) --------------------------------------------------------
void sub_424D60() { nox_srand(0x9DFu); }

//----- (00424D70) --------------------------------------------------------
void sub_424D70() { nox_srand(0x91Au); }

//----- (00424D80) --------------------------------------------------------
int __cdecl sub_424D80(const char* a1) {
	const char* v1;      // ecx
	int v2;              // ebp
	unsigned __int8* v3; // edi

	v1 = *(const char**)getMemAt(0x587000, 69736);
	v2 = 0;
	if (!*getMemU32Ptr(0x587000, 69736))
		return 0;
	v3 = getMemAt(0x587000, 69736);
	while (strcmp(v1, a1)) {
		v1 = (const char*)*((_DWORD*)v3 + 1);
		v3 += 4;
		++v2;
		if (!v1)
			return 0;
	}
	return v2;
}

//----- (00424DF0) --------------------------------------------------------
int sub_424DF0() {
	int result; // eax
	float v1;   // [esp+0h] [ebp-4h]
	float v2;   // [esp+0h] [ebp-4h]
	float v3;   // [esp+0h] [ebp-4h]
	float v4;   // [esp+0h] [ebp-4h]
	float v5;   // [esp+0h] [ebp-4h]
	float v6;   // [esp+0h] [ebp-4h]
	float v7;   // [esp+0h] [ebp-4h]
	float v8;   // [esp+0h] [ebp-4h]
	float v9;   // [esp+0h] [ebp-4h]
	float v10;  // [esp+0h] [ebp-4h]

	v1 = sub_419D40(getMemAt(0x587000, 69884));
	*getMemU32Ptr(0x5D4594, 599212) = nox_float2int(v1);
	v2 = sub_419D40(getMemAt(0x587000, 69908));
	*getMemU32Ptr(0x5D4594, 599216) = nox_float2int(v2);
	v3 = sub_419D40(getMemAt(0x587000, 69932));
	*getMemU32Ptr(0x5D4594, 599264) = nox_float2int(v3);
	v4 = sub_419D40(getMemAt(0x587000, 69944));
	*getMemU32Ptr(0x5D4594, 599268) = nox_float2int(v4);
	v5 = sub_419D40(getMemAt(0x587000, 69960));
	*getMemU32Ptr(0x5D4594, 599316) = nox_float2int(v5);
	v6 = sub_419D40(getMemAt(0x587000, 69976));
	*getMemU32Ptr(0x5D4594, 599320) = nox_float2int(v6);
	v7 = sub_419D40(getMemAt(0x587000, 69992));
	*getMemU32Ptr(0x5D4594, 599368) = nox_float2int(v7);
	v8 = sub_419D40(getMemAt(0x587000, 70012));
	*getMemU32Ptr(0x5D4594, 599372) = nox_float2int(v8);
	v9 = sub_419D40(getMemAt(0x587000, 70036));
	*getMemU32Ptr(0x5D4594, 599420) = nox_float2int(v9);
	v10 = sub_419D40(getMemAt(0x587000, 70056));
	result = nox_float2int(v10);
	*getMemU32Ptr(0x5D4594, 599424) = result;
	return result;
}

// 424FE7: variable 'v34' is possibly undefined
// 424F00: using guessed type char var_100[256];

//----- (00425230) --------------------------------------------------------
int __cdecl sub_425230(int a1, int a2) { return *getMemU32Ptr(0x5D4594, 4 * (a1 + a2 + 12 * a1) + 599172); }

//----- (00425250) --------------------------------------------------------
char* __cdecl sub_425250(int a1) { return *(char**)getMemAt(0x587000, 4 * a1 + 69736); }

//----- (00425260) --------------------------------------------------------
int __cdecl sub_425260(int a1) {
	int result; // eax

	if (a1 > 0 && a1 < 6 && *getMemU32Ptr(0x5D4594, 52 * a1 + 599156))
		result = *getMemU32Ptr(0x5D4594, 52 * a1 + 599132);
	else
		result = 0;
	return result;
}

//----- (00425290) --------------------------------------------------------
int __cdecl sub_425290(wchar_t* a1) {
	int v1;              // edi
	unsigned __int8* v2; // esi

	v1 = 1;
	v2 = getMemAt(0x5D4594, 599184);
	while (!*((_DWORD*)v2 + 6) || nox_wcscmp(*(const wchar_t**)v2, a1)) {
		v2 += 52;
		++v1;
		if ((int)v2 >= (int)getMemAt(0x5D4594, 599444))
			return 0;
	}
	return v1;
}

//----- (004252D0) --------------------------------------------------------
int __cdecl sub_4252D0(int a1) { return *getMemU32Ptr(0x5D4594, 52 * a1 + 599160); }

//----- (004252F0) --------------------------------------------------------
int __cdecl sub_4252F0(int a1) { return *getMemU32Ptr(0x5D4594, 52 * a1 + 599136); }

//----- (00425310) --------------------------------------------------------
int __cdecl sub_425310(int a1, int a2) { return *getMemU32Ptr(0x5D4594, 4 * (a1 + a2 + 12 * a1) + 599140); }

//----- (00425330) --------------------------------------------------------
int sub_425330() {
	int result;          // eax
	unsigned __int8* v1; // ecx

	result = 1;
	v1 = getMemAt(0x5D4594, 599208);
	while (!*(_DWORD*)v1) {
		v1 += 52;
		++result;
		if ((int)v1 >= (int)getMemAt(0x5D4594, 599468))
			return 0;
	}
	return result;
}

//----- (00425350) --------------------------------------------------------
int __cdecl sub_425350(int a1) {
	int result;          // eax
	unsigned __int8* v2; // ecx

	result = a1 + 1;
	if (a1 + 1 >= 6)
		return 0;
	v2 = getMemAt(0x5D4594, 52 * result + 599156);
	while (!*(_DWORD*)v2) {
		v2 += 52;
		++result;
		if ((int)v2 >= (int)getMemAt(0x5D4594, 599468))
			return 0;
	}
	return result;
}

//----- (00425380) --------------------------------------------------------
int __cdecl sub_425380(int a1) {
	int result;         // eax
	unsigned __int8* i; // ecx

	if (!a1)
		return 0;
	result = a1 - 1;
	if (a1 - 1 <= 0)
		return 0;
	for (i = getMemAt(0x5D4594, 52 * result + 599156); !*(_DWORD*)i; i -= 52) {
		if (--result <= 0)
			return 0;
	}
	return result;
}

//----- (004253B0) --------------------------------------------------------
int __cdecl sub_4253B0(int a1) { return *getMemU32Ptr(0x5D4594, 52 * a1 + 599156); }

//----- (004253D0) --------------------------------------------------------
int __cdecl sub_4253D0(int a1) { return *getMemU32Ptr(0x5D4594, 52 * a1 + 599152); }

//----- (004253F0) --------------------------------------------------------
int __cdecl sub_4253F0(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 52 * a1 + 599152) = 1;
	return result;
}

//----- (00425410) --------------------------------------------------------
int __cdecl sub_425410(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 52 * a1 + 599152) = 0;
	return result;
}

//----- (00425430) --------------------------------------------------------
BOOL __cdecl sub_425430(int a1, int a2) { return (a2 & *getMemU32Ptr(0x5D4594, 52 * a1 + 599168)) != 0; }

//----- (00425450) --------------------------------------------------------
int __cdecl sub_425450(int a1) { return *getMemU32Ptr(0x5D4594, 52 * a1 + 599168); }

//----- (00425470) --------------------------------------------------------
int __cdecl sub_425470(int a1) { return *getMemU32Ptr(0x5D4594, 52 * a1 + 599164); }

//----- (00425490) --------------------------------------------------------
void sub_425490() { nox_srand(0x91Bu); }

//----- (004254A0) --------------------------------------------------------
int __cdecl sub_4254A0(int a1, _BYTE* a2) {
	*(_DWORD*)a1 = a2;
	*(_BYTE*)(a1 + 4) = 0;
	return *a2 & 1;
}

//----- (004254C0) --------------------------------------------------------
bool __cdecl sub_4254C0(unsigned __int8** a1) {
	char v1;             // cl
	unsigned __int8* v2; // ecx

	v1 = *((_BYTE*)a1 + 4) + 1;
	*((_BYTE*)a1 + 4) = v1;
	if (v1 == 8) {
		v2 = *a1;
		*((_BYTE*)a1 + 4) = 0;
		*a1 = v2 + 1;
	}
	return ((1 << *((_BYTE*)a1 + 4)) & **a1) > 0;
}

//----- (00425500) --------------------------------------------------------
_BYTE* __cdecl sub_425500(int a1, _BYTE* a2, char a3) {
	_BYTE* result; // eax

	result = a2;
	*(_DWORD*)a1 = a2;
	*(_BYTE*)(a1 + 4) = 0;
	*a2 = a3;
	return result;
}

//----- (00425520) --------------------------------------------------------
char __cdecl sub_425520(int a1, char a2) {
	char v2;     // cl
	_BYTE* v3;   // ecx
	char result; // al

	v2 = *(_BYTE*)(a1 + 4) + 1;
	*(_BYTE*)(a1 + 4) = v2;
	if (v2 == 8) {
		v3 = *(_BYTE**)a1;
		*(_BYTE*)(a1 + 4) = 0;
		*(_DWORD*)a1 = ++v3;
		*v3 = 0;
	}
	result = a2 << *(_BYTE*)(a1 + 4);
	**(_BYTE**)a1 |= result;
	return result;
}

//----- (00425550) --------------------------------------------------------
int __cdecl sub_425550(_BYTE* a1, _BYTE* a2, int a3) {
	int v3;     // edi
	int v4;     // esi
	char v5;    // al
	int v6;     // ebx
	char v8[8]; // [esp+8h] [ebp-10h]
	char v9[8]; // [esp+10h] [ebp-8h]
	bool v10;   // [esp+1Ch] [ebp+4h]

	v3 = 1;
	v4 = 0;
	v5 = sub_4254A0((int)v9, a1);
	sub_425500((int)v8, a2, v5);
	if (a3 == 1)
		return 1;
	v6 = a3 - 1;
	do {
		if (!(++v4 % 7u)) {
			sub_425520((int)v8, 1);
			++v3;
		}
		v10 = sub_4254C0((unsigned __int8**)v9);
		sub_425520((int)v8, v10);
		--v6;
	} while (v6);
	return v3;
}

//----- (004255F0) --------------------------------------------------------
unsigned int __cdecl sub_4255F0(_BYTE* a1, _BYTE* a2, int a3) {
	unsigned int v3; // ebx
	char v4;         // al
	int v5;          // esi
	int v6;          // edi
	char v8[8];      // [esp+Ch] [ebp-10h]
	char v9[8];      // [esp+14h] [ebp-8h]
	bool v10;        // [esp+28h] [ebp+Ch]

	v3 = (unsigned int)(a3 + 7) >> 3;
	v4 = sub_4254A0((int)v8, a1);
	sub_425500((int)v9, a2, v4);
	v5 = 0;
	v6 = a3 - 1;
	if (a3 != 1) {
		do {
			if (!(++v5 % 7u))
				sub_4254C0((unsigned __int8**)v8);
			v10 = sub_4254C0((unsigned __int8**)v8);
			sub_425520((int)v9, v10);
			--v6;
		} while (v6);
	}
	return v3;
}

//----- (00425680) --------------------------------------------------------
int __cdecl sub_425680(_BYTE* a1, _BYTE* a2) {
	int v2;     // esi
	int result; // eax
	char v4[8]; // [esp+8h] [ebp-10h]
	char v5[8]; // [esp+10h] [ebp-8h]
	char v6;    // [esp+1Ch] [ebp+4h]
	bool v7;    // [esp+1Ch] [ebp+4h]

	v6 = sub_4254A0((int)v4, a1);
	sub_425500((int)v5, a2, v6);
	v2 = 0;
	do {
		if (!(++v2 % 7u))
			sub_4254C0((unsigned __int8**)v4);
		v7 = sub_4254C0((unsigned __int8**)v4);
		sub_425520((int)v5, v7);
		result = sub_425710((int)a2, (*(_DWORD*)v5 - (int)a2) >> 2);
	} while (!result);
	return result;
}

//----- (00425710) --------------------------------------------------------
int __cdecl sub_425710(int a1, int a2) {
	int v2; // ecx
	int v3; // eax

	v2 = 0;
	v3 = 0;
	if (a2 <= 0)
		return 0;
	while (1) {
		if (!(v3 % 2))
			v2 = 0;
		if (!*(_BYTE*)(v3 + a1))
			break;
		v2 = 0;
	LABEL_8:
		if (++v3 >= a2)
			return 0;
	}
	if (++v2 != 2)
		goto LABEL_8;
	return 1;
}

//----- (00425760) --------------------------------------------------------
_DWORD* __cdecl sub_425760(_DWORD* a1) {
	_DWORD* result; // eax

	result = a1;
	*a1 = a1;
	a1[1] = a1;
	a1[2] = a1;
	return result;
}

//----- (00425770) --------------------------------------------------------
_DWORD* __cdecl sub_425770(_DWORD* a1) {
	_DWORD* result; // eax

	result = a1;
	*a1 = a1;
	a1[1] = a1;
	a1[2] = 0;
	return result;
}

//----- (00425790) --------------------------------------------------------
int __cdecl sub_425790(int* a1, _DWORD* a2) {
	int v2;     // esi
	int v3;     // ebx
	int* v4;    // eax
	int result; // eax

	v2 = 0;
	v3 = a2[2];
	v4 = (int*)sub_425940(a1);
	if (v4) {
		while (v3 > v4[2]) {
			++v2;
			v4 = (int*)sub_425940(v4);
			if (!v4)
				goto LABEL_4;
		}
		sub_4258E0((int)v4, a2);
		result = v2;
	} else {
	LABEL_4:
		sub_4258E0((int)a1, a2);
		result = v2;
	}
	return result;
}

//----- (004257F0) --------------------------------------------------------
_DWORD* __cdecl sub_4257F0(int* a1, _DWORD* a2) {
	int v2;  // esi
	int* v3; // eax

	v2 = a2[2];
	v3 = (int*)sub_425940(a1);
	if (!v3)
		return sub_4258E0((int)a1, a2);
	while (v3[2] > v2) {
		v3 = (int*)sub_425940(v3);
		if (!v3)
			return sub_4258E0((int)a1, a2);
	}
	return sub_4258E0((int)v3, a2);
}

//----- (00425840) --------------------------------------------------------
_DWORD* __cdecl sub_425840(_DWORD* a1, int a2) {
	_DWORD* result; // eax
	int* v3;        // edi
	_DWORD* v4;     // edx

	result = (_DWORD*)*a1;
	v3 = (int*)a1[1];
	if ((_DWORD*)*a1 != a1) {
		v4 = *(_DWORD**)(a2 + 4);
		*v4 = result;
		result[1] = v4;
		*v3 = a2;
		*(_DWORD*)(a2 + 4) = v3;
		result = sub_425760(a1);
	}
	return result;
}

//----- (00425870) --------------------------------------------------------
int __cdecl sub_425870(_DWORD** a1) {
	int result;  // eax
	_DWORD** v2; // ecx

	result = 0;
	v2 = (_DWORD**)*a1;
	if (*a1 != a1) {
		do {
			v2 = (_DWORD**)*v2;
			++result;
		} while (v2 != a1);
	}
	return result;
}

//----- (00425890) --------------------------------------------------------
int* __cdecl sub_425890(int* a1) { return sub_4258A0(a1); }

//----- (004258A0) --------------------------------------------------------
int* __cdecl sub_4258A0(int* a1) {
	int* result; // eax

	result = a1;
	if (a1)
		result = (int*)sub_425940(a1);
	return result;
}

//----- (004258C0) --------------------------------------------------------
_DWORD* __cdecl sub_4258C0(_DWORD** a1, int a2) {
	_DWORD* result; // eax
	int v3;         // edx
	int v4;         // esi

	result = *a1;
	if (*a1 == a1)
		return 0;
	v3 = a2;
	while (1) {
		v4 = v3--;
		if (!v4)
			break;
		result = (_DWORD*)*result;
		if (result == a1)
			return 0;
	}
	return result;
}

//----- (004258E0) --------------------------------------------------------
_DWORD* __cdecl sub_4258E0(int a1, _DWORD* a2) {
	_DWORD* result; // eax
	int v3;         // edx

	result = a2;
	v3 = *(_DWORD*)(a1 + 4);
	*a2 = a1;
	a2[1] = v3;
	*(_DWORD*)(a1 + 4) = a2;
	*(_DWORD*)a2[1] = a2;
	return result;
}

//----- (00425900) --------------------------------------------------------
_DWORD* __cdecl sub_425900(_DWORD* a1, _DWORD* a2) {
	_DWORD* result; // eax

	result = a2;
	a2[1] = a1;
	*a2 = *a1;
	*a1 = a2;
	*(_DWORD*)(*a2 + 4) = a2;
	return result;
}

//----- (00425920) --------------------------------------------------------
_DWORD** __cdecl sub_425920(_DWORD** a1) {
	_DWORD** result; // eax

	result = a1;
	*a1[1] = *a1;
	(*a1)[1] = a1[1];
	*a1 = a1;
	a1[1] = a1;
	return result;
}

//----- (00425940) --------------------------------------------------------
int __cdecl sub_425940(int* a1) {
	int result; // eax

	result = *a1;
	if (*a1) {
		if (result == *(_DWORD*)(result + 8))
			result = 0;
	}
	return result;
}

//----- (00425960) --------------------------------------------------------
int __cdecl sub_425960(int a1) {
	return *(_DWORD*)(*(_DWORD*)(a1 + 4) + 8) != *(_DWORD*)(a1 + 4) ? *(_DWORD*)(a1 + 4) : 0;
}

//----- (00425980) --------------------------------------------------------
_DWORD* __cdecl sub_425980(_DWORD* a1) {
	_DWORD* result; // eax

	result = (_DWORD*)*a1;
	if (result == (_DWORD*)result[2]) {
		result = (_DWORD*)*result;
		if (result == (_DWORD*)result[2])
			result = 0;
	}
	return result;
}

//----- (004259A0) --------------------------------------------------------
int __cdecl sub_4259A0(int a1) {
	int result; // eax

	result = *(_DWORD*)(a1 + 4);
	if (result == *(_DWORD*)(result + 8)) {
		result = *(_DWORD*)(result + 4);
		if (result == *(_DWORD*)(result + 8))
			result = 0;
	}
	return result;
}

//----- (004259C0) --------------------------------------------------------
_DWORD* sub_4259C0() {
	_DWORD* result; // eax

	result = *(_DWORD**)getMemAt(0x5D4594, 599472);
	if (!*getMemU32Ptr(0x5D4594, 599472)) {
		result = sub_425760(getMemAt(0x5D4594, 599460));
		*getMemU32Ptr(0x5D4594, 599472) = 1;
	}
	return result;
}

//----- (004259F0) --------------------------------------------------------
int* sub_4259F0() {
	int* result; // eax
	int* v1;     // ebx
	int* v2;     // ebp
	int* v3;     // esi
	int* v4;     // edi

	result = sub_425A50();
	v1 = result;
	if (result) {
		do {
			v2 = sub_425A60(v1);
			v3 = sub_425BC0((int)v1);
			if (v3) {
				do {
					v4 = sub_425BE0(v3);
					sub_425920((_DWORD**)v3);
					free(v3);
					v3 = v4;
				} while (v4);
			}
			sub_425920((_DWORD**)v1);
			free(v1);
			v1 = v2;
		} while (v2);
	}
	return result;
}

//----- (00425A50) --------------------------------------------------------
int* sub_425A50() { return sub_425890(getMemIntPtr(0x5D4594, 599460)); }

//----- (00425A60) --------------------------------------------------------
int* __cdecl sub_425A60(int* a1) { return sub_4258A0(a1); }

//----- (00425A70) --------------------------------------------------------
int* __cdecl sub_425A70(int a1) {
	int* result; // eax

	result = sub_425A50();
	if (!result)
		return 0;
	while (result[8] != a1) {
		result = sub_425A60(result);
		if (!result)
			return 0;
	}
	return result;
}

//----- (00425AA0) --------------------------------------------------------
int __cdecl sub_425AA0(int a1) {
	int* v1; // eax

	v1 = sub_425A50();
	if (!v1)
		return 0;
	while (v1[8] != a1) {
		v1 = sub_425A60(v1);
		if (!v1)
			return 0;
	}
	return 1;
}

//----- (00425AD0) --------------------------------------------------------
wchar_t* __cdecl sub_425AD0(int a1, wchar_t* a2) {
	wchar_t* v2; // esi

	v2 = 0;
	if (!sub_425AA0(a1)) {
		v2 = (wchar_t*)malloc(0x34u);
		*((_DWORD*)v2 + 8) = a1;
		nox_wcscpy(v2 + 6, a2);
		*((_DWORD*)v2 + 9) = 0;
		sub_425770(v2);
		sub_425760((_DWORD*)v2 + 10);
		sub_4258E0((int)getMemAt(0x5D4594, 599460), v2);
	}
	return v2;
}

//----- (00425B30) --------------------------------------------------------
_DWORD* __cdecl sub_425B30(int a1, int a2) {
	_DWORD* v2; // eax
	_DWORD* v3; // esi

	v2 = malloc(0x10u);
	v3 = v2;
	v2[3] = a2;
	sub_425770(v2);
	return sub_4258E0(a1 + 40, v3);
}

//----- (00425B60) --------------------------------------------------------
char* __cdecl sub_425B60(LPVOID lpMem, int a2) {
	int* v2;      // esi
	char* result; // eax

	v2 = sub_425BC0((int)lpMem);
	if (v2) {
		while (v2[3] != a2) {
			v2 = sub_425BE0(v2);
			if (!v2)
				goto LABEL_6;
		}
		sub_425920((_DWORD**)v2);
		free(v2);
	}
LABEL_6:
	result = (char*)lpMem + 40;
	if (*((LPVOID*)lpMem + 11) == (char*)lpMem + 40) {
		sub_425920((_DWORD**)lpMem);
		free(lpMem);
	}
	return result;
}

//----- (00425BC0) --------------------------------------------------------
int* __cdecl sub_425BC0(int a1) { return sub_425890((int*)(a1 + 40)); }

//----- (00425BE0) --------------------------------------------------------
int* __cdecl sub_425BE0(int* a1) { return sub_4258A0(a1); }

//----- (00425BF0) --------------------------------------------------------
int sub_425BF0() {
	int v0;  // esi
	char* i; // eax
	int v2;  // ecx

	v0 = 0;
	if (nox_common_gameFlags_check_40A5C0(0x8000)) {
		for (i = nox_common_playerInfoGetFirst_416EA0(); i; i = nox_common_playerInfoGetNext_416EE0((int)i)) {
			v2 = *((_DWORD*)i + 920);
			if (v2 & 1 && !(v2 & 0x20) && i[2064] != 31)
				++v0;
		}
	}
	return v0;
}

//----- (00425C40) --------------------------------------------------------
char* sub_425C40() {
	char* result; // eax

	result = nox_common_playerInfoGetFirst_416EA0();
	if (!result)
		return 0;
	while (!(result[3680] & 1) || result[2064] == -1) {
		result = nox_common_playerInfoGetNext_416EE0((int)result);
		if (!result)
			return 0;
	}
	return result;
}

//----- (00425C70) --------------------------------------------------------
char* __cdecl sub_425C70(int a1) {
	char* result; // eax

	result = (char*)a1;
	if (!a1)
		return 0;
	while (!(result[3680] & 1) || result[2064] == -1) {
		result = nox_common_playerInfoGetNext_416EE0((int)result);
		if (!result)
			return 0;
	}
	return result;
}

//----- (00425CA0) --------------------------------------------------------
char* __cdecl sub_425CA0(int a1, int a2) {
	char* result; // eax
	int v3;       // ebx
	int v4;       // ebp
	int v5;       // ebp
	int v6;       // eax
	int v7;       // eax
	int v8;       // esi
	int v9;       // eax
	int v10;      // eax
	int v11;      // eax
	int v12;      // [esp+8h] [ebp+4h]
	int v13;      // [esp+Ch] [ebp+8h]

	result = (char*)nox_common_gameFlags_check_40A5C0(0x2000);
	if (result) {
		result = (char*)nox_common_gameFlags_check_40A5C0(4096);
		if (!result) {
			if (a1) {
				v3 = a2;
				if (*(int*)(a1 + 4648) == -1) {
					v4 = (dword_5d4594_608316)++;
					v13 = v4;
					v5 = 32 * v4;
					strcpy((char*)getMemAt(0x5D4594, 600124 + v5), (const char*)(a1 + 2096));
					if (*(_BYTE*)(v3 + 2064) == 31)
						v6 = sub_554200(0);
					else
						v6 = sub_554200(*(unsigned __int8*)(a1 + 2064) + 1);
					*getMemU32Ptr(0x5D4594, 600124 + 12 + v5) = htonl(v6);
					*getMemU32Ptr(0x5D4594, 600124 + 16 + v5) = *(_DWORD*)(a1 + 2068);
					*getMemU8Ptr(0x5D4594, 600124 + 20 + v5) = *(_BYTE*)(a1 + 2251);
					*(_DWORD*)(a1 + 4648) = v13;
				} else {
					v13 = *(_DWORD*)(a1 + 4648);
				}
				if (v3) {
					if (*(int*)(v3 + 4648) == -1) {
						v12 = (dword_5d4594_608316)++;
						strcpy((char*)getMemAt(0x5D4594, 600124 + 32 * v13), (const char*)(v3 + 2096));
						if (*(_BYTE*)(v3 + 2064) == 31) {
							v7 = sub_554200(0);
							v8 = v12;
							*getMemU32Ptr(0x5D4594, 600124 + 12 + 32 * v13) = htonl(v7);
						} else {
							v9 = sub_554200(*(unsigned __int8*)(v3 + 2064) + 1);
							v8 = v12;
							*getMemU32Ptr(0x5D4594, 600124 + 12 + 32 * v12) = htonl(v9);
						}
						v10 = 32 * v8;
						*getMemU32Ptr(0x5D4594, 600124 + 16 + v10) = *(_DWORD*)(v3 + 2068);
						*getMemU8Ptr(0x5D4594, 600124 + 20 + v10) = *(_BYTE*)(v3 + 2251);
						*(_DWORD*)(v3 + 4648) = v8;
					} else {
						v12 = *(_DWORD*)(v3 + 4648);
					}
				} else {
					LOBYTE(v12) = -1;
				}
				v11 = dword_5d4594_739392;
				*getMemU8Ptr(0x5D4594, 608320 + 2 * dword_5d4594_739392) = v13;
				*getMemU8Ptr(0x5D4594, 608320 + 1 + 2 * v11) = v12;
				dword_5d4594_739392 = v11 + 1;
				result = *(char**)&dword_5d4594_608316;
				if (dword_5d4594_608316 >= 0xFFu)
					result = sub_4263C0();
			}
		}
	}
	return result;
}

//----- (00425E90) --------------------------------------------------------
int __cdecl sub_425E90(int a1, char a2) {
	int result; // eax

	result = nox_common_gameFlags_check_40A5C0(0x2000);
	if (result) {
		result = nox_common_gameFlags_check_40A5C0(4096);
		if (!result) {
			result = *(_DWORD*)(a1 + 4648);
			if (result != -1) {
				result *= 32;
				*getMemU8Ptr(0x5D4594, 600124 + 21 + result) = a2;
			}
		}
	}
	return result;
}

//----- (00425ED0) --------------------------------------------------------
int __cdecl sub_425ED0(int a1, char a2) {
	int result; // eax

	result = nox_common_gameFlags_check_40A5C0(0x2000);
	if (result) {
		result = nox_common_gameFlags_check_40A5C0(4096);
		if (!result) {
			result = *(_DWORD*)(a1 + 4648);
			if (result != -1) {
				result *= 32;
				*getMemU8Ptr(0x5D4594, 600124 + 28 + result) = a2;
			}
		}
	}
	return result;
}

//----- (00425F10) --------------------------------------------------------
int __cdecl sub_425F10(int a1) {
	int result; // eax
	int v2;     // ebx
	int v3;     // ecx
	int v4;     // ebp
	_BYTE* v5;  // edi
	int v6;     // ebp
	bool v7;    // zf
	int v8;     // eax
	int v9;     // eax
	int v10;    // eax
	int v11;    // eax
	int v12;    // [esp+8h] [ebp+4h]

	result = nox_common_gameFlags_check_40A5C0(0x2000);
	if (result) {
		result = nox_common_gameFlags_check_40A5C0(4096);
		if (!result) {
			v2 = a1;
			if (a1) {
				result = *(_DWORD*)(a1 + 4648);
				v3 = -1;
				if (result == -1) {
					v4 = (dword_5d4594_608316)++;
					v12 = v4;
					v5 = (_BYTE*)(v2 + 2096);
					v6 = 32 * v4;
					do {
						if (!v3)
							break;
						v7 = *v5++ == 0;
						--v3;
					} while (!v7);
					memcpy(getMemAt(0x5D4594, 600124 + v6), &v5[v3 + 1], ~v3);
					if (*(_BYTE*)(v2 + 2064) == 31) {
						v8 = sub_554200(0);
						*getMemU32Ptr(0x5D4594, 600124 + 12 + v6) = htonl(v8);
						if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
							*getMemU8Ptr(0x5D4594, 600124 + 28 + v6) = 0;
							goto LABEL_18;
						}
						v9 = *(_DWORD*)(v2 + 3680);
						if (v9 & 1 && !(v9 & 0x20)) {
							*getMemU8Ptr(0x5D4594, 600124 + 28 + v6) = 0;
							goto LABEL_18;
						}
					} else {
						v10 = sub_554200(*(unsigned __int8*)(v2 + 2064) + 1);
						*getMemU32Ptr(0x5D4594, 600124 + 12 + v6) = htonl(v10);
						v11 = *(_DWORD*)(v2 + 3680);
						if (v11 & 1 && !(v11 & 0x20)) {
							*getMemU8Ptr(0x5D4594, 600124 + 28 + v6) = 0;
							goto LABEL_18;
						}
					}
					*getMemU8Ptr(0x5D4594, 600124 + 28 + v6) = 1;
				LABEL_18:
					*getMemU32Ptr(0x5D4594, 600124 + 16 + v6) = *(_DWORD*)(v2 + 2068);
					*getMemU8Ptr(0x5D4594, 600124 + 20 + v6) = *(_BYTE*)(v2 + 2251);
					*getMemU32Ptr(0x5D4594, 600124 + 24 + v6) = time(0);
					result = v12;
					*getMemU8Ptr(0x5D4594, 600124 + 21 + v6) = 1;
					*(_DWORD*)(v2 + 4648) = v12;
					return result;
				}
			}
		}
	}
	return result;
}

//----- (00426150) --------------------------------------------------------
char* sub_426150() {
	char* result; // eax
	char* v1;     // esi
	char* v2;     // ebp
	__int16 v3;   // ax
	int v4;       // edx

	result = (char*)nox_common_gameFlags_check_40A5C0(0x2000);
	if (result) {
		result = (char*)nox_common_gameFlags_check_40A5C0(4096);
		if (!result) {
			v1 = sub_416640();
			v2 = sub_416590(0);
			*getMemU16Ptr(0x5D4594, 599482) = (unsigned __int8)v1[103];
			*getMemU32Ptr(0x5D4594, 599484) = (unsigned __int8)v1[104];
			*getMemU32Ptr(0x5D4594, 599488) = *((_DWORD*)v1 + 10);
			*getMemU32Ptr(0x5D4594, 599492) = sub_4200E0();
			*getMemU8Ptr(0x5D4594, 599502) = (v2[53] & 0xC0) != 0;
			v3 = *((_WORD*)v2 + 26);
			if (v3 & 0x100) {
				dword_5d4594_599496 = 0;
			LABEL_14:
				*getMemU8Ptr(0x5D4594, 599500) = (v2[53] & 0x40) == 0;
				*getMemU32Ptr(0x5D4594, 599508) = *((unsigned __int16*)v2 + 27);
				*getMemU32Ptr(0x5D4594, 599512) = (unsigned __int8)v2[56];
				*getMemU8Ptr(0x5D4594, 599516) = v1[100];
				*getMemU32Ptr(0x5D4594, 599520) = v1[101] & 0xF;
				*getMemU32Ptr(0x5D4594, 599524) = (unsigned __int8)v1[101] >> 4;
				*getMemU32Ptr(0x5D4594, 599528) = *(unsigned __int16*)(v1 + 105);
				*getMemU32Ptr(0x5D4594, 599532) = *(unsigned __int16*)(v1 + 107);
				*getMemU8Ptr(0x5D4594, 599536) = v1[102];
				*getMemU8Ptr(0x5D4594, 599537) = v1[100] & 0x30;
				*getMemU8Ptr(0x5D4594, 599501) = sub_417DE0();
				strncpy((char*)getMemAt(0x5D4594, 599828), v2 + 9, 0xFu);
				*getMemU8Ptr(0x5D4594, 599843) = 0;
				memcpy(getMemAt(0x5D4594, 599540), v2 + 24, 0x64u);
				*getMemU32Ptr(0x5D4594, 599564) = *((_DWORD*)v2 + 12);
				*getMemU32Ptr(0x5D4594, 599560) = *((_DWORD*)v2 + 11);
				result = strncpy((char*)getMemAt(0x5D4594, 599572), v2, 8u);
				*getMemU8Ptr(0x5D4594, 599580) = 0;
				*getMemU32Ptr(0x5D4594, 600112) = 0;
				*getMemU32Ptr(0x5D4594, 600084) = 0;
				*getMemU32Ptr(0x5D4594, 600088) = 0;
				*getMemU32Ptr(0x5D4594, 600092) = 0;
				*getMemU32Ptr(0x5D4594, 600096) = 0;
				return result;
			}
			if (v3 & 0x20) {
				v4 = 1;
			} else {
				if (v3 & 0x40) {
					dword_5d4594_599496 = 2;
					goto LABEL_14;
				}
				if (v3 & 0x10) {
					dword_5d4594_599496 = 3;
					goto LABEL_14;
				}
				if (!(v3 & 0x400))
					goto LABEL_14;
				v4 = 4;
			}
			dword_5d4594_599496 = v4;
			goto LABEL_14;
		}
	}
	return result;
}

//----- (004263C0) --------------------------------------------------------
char* sub_4263C0() {
	char* result; // eax
	char* i;      // eax
	char* v2;     // eax
	int j;        // esi

	result = (char*)nox_common_gameFlags_check_40A5C0(0x2000);
	if (result) {
		result = (char*)nox_common_gameFlags_check_40A5C0(4096);
		if (!result) {
			sub_4282F0((int)getMemAt(0x5D4594, 599476), (int)getMemAt(0x5D4594, 600124), *(size_t*)&dword_5d4594_608316);
			sub_428540((int)getMemAt(0x5D4594, 599476), (char*)getMemAt(0x5D4594, 608320), *(int*)&dword_5d4594_739392);
			*getMemU32Ptr(0x5D4594, 599504) = time(0) - dword_5d4594_600116;
			sub_428810((int)getMemAt(0x5D4594, 599476), 1);
			memset(getMemAt(0x5D4594, 600124), 0, 0x2000u);
			memset(getMemAt(0x5D4594, 608320), 0, 0x20000u);
			dword_5d4594_608316 = 0;
			dword_5d4594_739392 = 0;
			for (i = nox_common_playerInfoGetFirst_416EA0(); i; i = nox_common_playerInfoGetNext_416EE0((int)i))
				*((_DWORD*)i + 1162) = -1;
			v2 = nox_common_playerInfoGetXXX_417090(31);
			if (v2)
				sub_425F10((int)v2);
			result = nox_common_playerInfoGetFirst_416EA0();
			for (j = (int)result; result; j = (int)result) {
				if (*(_BYTE*)(j + 2064) != 31)
					sub_425F10(j);
				result = nox_common_playerInfoGetNext_416EE0(j);
			}
		}
	}
	return result;
}

//----- (004264D0) --------------------------------------------------------
BOOL sub_4264D0() {
	char* i; // esi

	if (!nox_common_gameFlags_check_40A5C0(0x2000) || nox_common_gameFlags_check_40A5C0(4096)) {
		if (nox_common_gameFlags_check_40A5C0(4096))
			*getMemU32Ptr(0x5D4594, 739416) = time(0) - dword_5d4594_600116;
	} else {
		for (i = nox_common_playerInfoGetFirst_416EA0(); i; i = nox_common_playerInfoGetNext_416EE0((int)i))
			sub_425E90((int)i, 1);
		*getMemU32Ptr(0x5D4594, 599504) = time(0) - dword_5d4594_600116;
	}
	if (!nox_common_gameFlags_check_40A5C0(4096))
		return sub_428810((int)getMemAt(0x5D4594, 599476), 2);
	sub_4285C0(getMemI16Ptr(0x5D4594, 739396));
	return sub_428890(getMemI16Ptr(0x5D4594, 739396));
}

//----- (00426590) --------------------------------------------------------
void* sub_426590() { return calloc(1u, 0x144u); }

//----- (004265A0) --------------------------------------------------------
void __cdecl sub_4265A0(LPVOID lpMem) {
	LPVOID* v1; // esi
	int v2;     // ebx
	int i;      // edi

	if (lpMem) {
		v1 = (LPVOID*)lpMem;
		v2 = 27;
		do {
			if (*v1) {
				for (i = 0; i < (int)v1[1]; ++i)
					free(*((LPVOID*)*v1 + 2 * i));
				free(*v1);
			}
			v1 += 3;
			--v2;
		} while (v2);
		free(lpMem);
	}
}

//----- (00426600) --------------------------------------------------------
int __cdecl sub_426600(int a1, void(__cdecl* a2)(_DWORD, _DWORD)) {
	int* v2;    // edi
	int v3;     // ebp
	int result; // eax
	int i;      // esi

	v2 = (int*)(a1 + 4);
	v3 = 27;
	do {
		result = *v2;
		for (i = 0; i < *v2; ++i) {
			a2(*(_DWORD*)(*(v2 - 1) + 8 * i), *(_DWORD*)(*(v2 - 1) + 8 * i + 4));
			result = *v2;
		}
		v2 += 3;
		--v3;
	} while (v3);
	return result;
}

//----- (00426650) --------------------------------------------------------
int __cdecl sub_426650(int a1, char* a2, int a3) {
	CHAR* v3; // eax

	v3 = sub_426680(a1, a2);
	if (!v3)
		return 0;
	*((_DWORD*)v3 + 1) = a3;
	return 1;
}

//----- (00426680) --------------------------------------------------------
CHAR* __cdecl sub_426680(int a1, char* a2) {
	CHAR* result; // eax
	CHAR* v3;     // esi
	int i;        // edi
	int j;        // ecx
	int v6;       // ebp
	_DWORD* v7;   // edx
	int v8;       // eax
	int v9;       // edi

	result = sub_426740(a1, a2);
	v3 = result;
	if (result) {
		if (!*((_DWORD*)result + 2)) {
			*(_DWORD*)result = realloc(*(LPVOID*)result, 8 * (*((_DWORD*)result + 1) + 5));
			*((_DWORD*)v3 + 2) = 5;
		}
		for (i = 0; i < *((_DWORD*)v3 + 1); ++i) {
			if (_strcmpi(a2, *(const char**)(*(_DWORD*)v3 + 8 * i)) < 0)
				break;
		}
		for (j = *((_DWORD*)v3 + 1); j > i; v7[1] = *(v7 - 1)) {
			v6 = *(_DWORD*)(*(_DWORD*)v3 + 8 * j - 8);
			v7 = (_DWORD*)(*(_DWORD*)v3 + 8 * j--);
			*v7 = v6;
		}
		v8 = *((_DWORD*)v3 + 2) - 1;
		++*((_DWORD*)v3 + 1);
		*((_DWORD*)v3 + 2) = v8;
		v9 = 8 * i;
		*(_DWORD*)(*(_DWORD*)v3 + v9) = nox_clone_str(a2);
		result = (CHAR*)(v9 + *(_DWORD*)v3);
	}
	return result;
}

//----- (00426740) --------------------------------------------------------
CHAR* __cdecl sub_426740(int a1, CHAR* a2) {
	CHAR* result; // eax
	int v3;       // eax

	result = a2;
	if (a2) {
		v3 = toupper(*a2);
		if (v3 < 65 || v3 > 90)
			result = (CHAR*)(a1 + 312);
		else
			result = (CHAR*)(a1 + 12 * (v3 - 65));
	}
	return result;
}

//----- (00426780) --------------------------------------------------------
int __cdecl sub_426780(int a1, char* a2, int a3) {
	CHAR* v3; // eax

	v3 = sub_426680(a1, a2);
	if (!v3)
		return 0;
	*((_DWORD*)v3 + 1) = a3;
	return 1;
}

//----- (004267B0) --------------------------------------------------------
int __cdecl sub_4267B0(int a1, char* a2, int a3) {
	CHAR* v3; // eax

	v3 = sub_426680(a1, a2);
	if (!v3)
		return 0;
	*((_DWORD*)v3 + 1) = a3;
	return 1;
}

//----- (004267E0) --------------------------------------------------------
int __cdecl sub_4267E0(int a1, void* a2) {
	_DWORD* v2; // eax
	int result; // eax

	v2 = sub_426800(a1, a2);
	if (v2)
		result = v2[1];
	else
		result = 0;
	return result;
}

//----- (00426800) --------------------------------------------------------
void* __cdecl sub_426800(int a1, void* a2) {
	CHAR* v2;     // eax
	size_t v3;    // ecx
	void* result; // eax

	if (a2 && (v2 = sub_426740(a1, (CHAR*)a2)) != 0 && (v3 = *((_DWORD*)v2 + 1)) != 0)
		result = bsearch(a2, *(const void**)v2, v3, 8u, sub_426840);
	else
		result = 0;
	return result;
}

//----- (00426840) --------------------------------------------------------
int __cdecl sub_426840(const void* a1, const void* a2) { return _strcmpi((const char*)a1, *(const char**)a2); }

//----- (00426860) --------------------------------------------------------
double __cdecl sub_426860(int a1, void* a2) {
	float* v2;     // eax
	double result; // st7

	v2 = (float*)sub_426800(a1, a2);
	if (v2)
		result = v2[1];
	else
		result = 0.0;
	return result;
}

//----- (00426890) --------------------------------------------------------
int __cdecl sub_426890(int a1, void* a2) {
	_DWORD* v2; // eax
	int result; // eax

	v2 = sub_426800(a1, a2);
	if (v2)
		result = v2[1];
	else
		result = 0;
	return result;
}

//----- (004268B0) --------------------------------------------------------
int __cdecl sub_4268B0(int a1) {
	int v1;     // ecx
	int result; // eax

	v1 = 27;
	result = a1 + 4;
	do {
		result += 12;
		--v1;
	} while (v1);
	return result;
}

//----- (004268D0) --------------------------------------------------------
void sub_4268D0() { nox_srand(0x9C4u); }

//----- (004268E0) --------------------------------------------------------
int sub_4268E0() { return sub_409110(nox_file_3); }

//----- (00426910) --------------------------------------------------------
int __cdecl sub_426910(char* a1, int a2, int a3) {
	int v3;     // eax
	int result; // eax

	if (nox_file_3)
		sub_4269F0();
	sub_426A50(0);
	*getMemU32Ptr(0x5D4594, 3803300) = a2;
	*getMemU32Ptr(0x5D4594, 740000) = a3 == -1;
	dword_5d4594_739996 = -1;
	if (a2 == 1) {
		v3 = 0;
	} else if (a2 == 2) {
		*getMemU32Ptr(0x5D4594, 3803300) = 0;
		v3 = 2;
	} else {
		v3 = 1;
	}
	result = sub_408CC0_fopen(a1, v3);
	nox_file_3 = result;
	if (result) {
		result = sub_408D40(result, a3);
		if (result) {
			if (a2 == 2 && sub_409050(nox_file_3, 0, SEEK_END)) {
				result = 0;
			} else {
				dword_5d4594_740072 = 0;
				memset(getMemAt(0x5D4594, 740040), 0, 0x20u);
				memset(getMemAt(0x5D4594, 740008), 0, 0x20u);
				result = 1;
			}
		}
	}
	return result;
}

//----- (004269F0) --------------------------------------------------------
FILE* sub_4269F0() {
	FILE* result; // eax

	result = nox_file_3;
	if (nox_file_3) {
		sub_408D90(nox_file_3);
		result = (FILE*)sub_426A50(0);
		nox_file_3 = 0;
	}
	return result;
}

//----- (00426A20) --------------------------------------------------------
int __cdecl sub_426A20(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 739992) = a1;
	return result;
}

//----- (00426A30) --------------------------------------------------------
int sub_426A30() { return *getMemU32Ptr(0x5D4594, 739992); }

//----- (00426A40) --------------------------------------------------------
int sub_426A40() { return *getMemU32Ptr(0x5D4594, 740000); }

//----- (00426A50) --------------------------------------------------------
int __cdecl sub_426A50(int a1) {
	int result; // eax

	result = a1;
	dword_5d4594_740004 = a1;
	return result;
}

//----- (00426A60) --------------------------------------------------------
FILE* sub_426A60() { return nox_file_3; }

//----- (00426A70) --------------------------------------------------------
char* sub_426A70() { return (char*)getMemAt(0x5D4594, 739980); }

//----- (00426A80) --------------------------------------------------------
int* __cdecl sub_426A80(int* a1) {
	int* result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 739980) = *a1;
	*getMemU32Ptr(0x5D4594, 739984) = a1[1];
	return result;
}

//----- (00426AA0) --------------------------------------------------------
int __cdecl sub_426AA0(int a1) { return sub_409050(nox_file_3, a1, SEEK_CUR); }

//----- (00426AC0) --------------------------------------------------------
size_t __cdecl sub_426AC0_file3_fread(_BYTE* a1, size_t a2) {
	_BYTE* v2;     // ebx
	size_t v3;     // esi
	size_t result; // eax
	size_t v5;     // esi

	if (*getMemU32Ptr(0x5D4594, 3803300)) {
		if (dword_5d4594_740004) {
			v5 = fread(a1, a2, 1, nox_file_3);
			sub_56FDD0(126, a1, a2);
		} else {
			v5 = sub_408E40_fread(a1, a2, 1, nox_file_3);
		}
		if (v5)
			sub_426BD0(a1, a2);
		result = v5;
	} else {
		sub_426BD0(a1, a2);
		if (dword_5d4594_740004) {
			v2 = calloc(a2, 1u);
			if (v2) {
				memcpy(v2, a1, a2);
				sub_56FDD0(126, v2, a2);
				v3 = fwrite(v2, a2, 1, nox_file_3);
				free(v2);
				result = v3;
			} else {
				result = 0;
			}
		} else {
			result = sub_409200(a1, a2, 1, nox_file_3);
		}
	}
	return result;
}

//----- (00426BD0) --------------------------------------------------------
int __cdecl sub_426BD0(unsigned __int8* a1, int a2) {
	int result;          // eax
	unsigned int v3;     // ecx
	unsigned __int8* v4; // esi
	int i;               // edi
	int v6;              // edx

	result = nox_file_3;
	if (nox_file_3) {
		v3 = dword_5d4594_739996;
		v4 = a1;
		for (i = a2; i; dword_5d4594_739996 = v3) {
			v6 = *v4++;
			result = *getMemU32Ptr(0x581450, 4 * (v6 ^ (unsigned __int8)v3) + 7288);
			v3 = result ^ (v3 >> 8);
			--i;
		}
		dword_5d4594_739996 = ~v3;
	}
	return result;
}

//----- (00426C20) --------------------------------------------------------
void __cdecl sub_426C20(_BYTE* a1, size_t a2) {
	if (*getMemU32Ptr(0x5D4594, 3803300) == 1) {
		if (dword_5d4594_740004) {
			fread(a1, a2, 1u, nox_file_3);
			sub_56FDD0(126, a1, a2);
		} else if (sub_426A40()) {
			sub_408E40_fread(a1, a2, 1, nox_file_3);
		} else {
			sub_408FE0(a1, a2, 1, nox_file_3);
		}
	}
}

//----- (00426C90) --------------------------------------------------------
void __cdecl sub_426C90() {
	void* v2; // eax
	int v3;   // eax
	int v4;   // ecx
	void* v5; // [esp+0h] [ebp-4h]

	if (!*getMemU32Ptr(0x5D4594, 3803300)) {
		if (dword_5d4594_740004) {
			v2 = (void*)ftell(nox_file_3);
			*getMemU32Ptr(0x5D4594, 740008 + 4 * dword_5d4594_740072) = v2;
			v5 = v2;
			sub_56FDD0(126, &v5, 4);
			fwrite(&v5, 4u, 1u, nox_file_3);
			++dword_5d4594_740072;
		} else {
			*getMemU32Ptr(0x5D4594, 740040 + 4 * dword_5d4594_740072) = sub_409110(nox_file_3);
			v3 = sub_409390();
			v4 = dword_5d4594_740072;
			*getMemU32Ptr(0x5D4594, 740008 + 4 * dword_5d4594_740072) = v3;
			dword_5d4594_740072 = v4 + 1;
		}
	}
}

//----- (00426D40) --------------------------------------------------------
void __cdecl sub_426D40() {
	int v1;   // edi
	int v2;   // eax
	void* v3; // esi
	int v5;   // eax
	void* v6; // [esp+0h] [ebp-4h]

	--dword_5d4594_740072;
	if (*getMemU32Ptr(0x5D4594, 3803300))
		return;
	if (dword_5d4594_740004) {
		v1 = ftell(nox_file_3);
		v2 = *getMemU32Ptr(0x5D4594, 740008 + 4 * dword_5d4594_740072);
		v3 = (void*)(v1 - v2 - 4);
		fseek(nox_file_3, v2, SEEK_SET);
		v6 = v3;
		sub_56FDD0(126, &v6, 4);
		fwrite(&v6, 4u, 1u, nox_file_3);
		fseek(nox_file_3, v1, SEEK_SET);
	} else {
		v5 = sub_409390();
		v3 = (void*)(v5 - *getMemU32Ptr(0x5D4594, 740008 + 4 * dword_5d4594_740072));
		sub_409190(nox_file_3, v5 - *getMemU32Ptr(0x5D4594, 740008 + 4 * dword_5d4594_740072),
				   *getMemU32Ptr(0x5D4594, 740040 + 4 * dword_5d4594_740072));
	}
}

//----- (00426E20) --------------------------------------------------------
int __cdecl sub_426E20(int a1) {
	int v1;              // ebp
	const char** v2;     // ebx
	unsigned __int8* v3; // esi
	int v6;              // eax

	if (!*getMemU32Ptr(0x587000, 70168))
		return 1;
	v1 = a1;
	v2 = (const char**)getMemAt(0x587000, 70168);
	v3 = getMemAt(0x587000, 70168);
	while (1) {
		LOBYTE(a1) = strlen(*v2) + 1;
		sub_426AC0_file3_fread(&a1, 1u);
		sub_426AC0_file3_fread(*v2, (unsigned __int8)a1);
		sub_426C90();
		if (!(*((int(__cdecl**)(int))v3 + 1))(v1))
			break;
		sub_426D40();
		v6 = *((_DWORD*)v3 + 2);
		v3 += 8;
		v2 = (const char**)v3;
		if (!v6)
			return 1;
	}
	return 0;
}
// 426E69: variable 'v4' is possibly undefined
// 426E79: variable 'v5' is possibly undefined

//----- (00426EA0) --------------------------------------------------------
BOOL __cdecl sub_426EA0(int a1, const char* a2, _DWORD* a3) {
	int v3;              // ebp
	const char* v4;      // eax
	unsigned __int8* v5; // edi

	v3 = 0;
	*a3 = 0;
	v4 = *(const char**)getMemAt(0x587000, 70168);
	if (!*getMemU32Ptr(0x587000, 70168))
		return *getMemU32Ptr(0x587000, 8 * v3 + 70168) != 0;
	v5 = getMemAt(0x587000, 70168);
	while (strcmp(v4, a2)) {
		v4 = (const char*)*((_DWORD*)v5 + 2);
		v5 += 8;
		++v3;
		if (!v4)
			return *getMemU32Ptr(0x587000, 8 * v3 + 70168) != 0;
	}
	if ((*(int(__cdecl**)(int)) getMemAt(0x587000, 8 * v3 + 70172))(a1))
		return *getMemU32Ptr(0x587000, 8 * v3 + 70168) != 0;
	*a3 = 1;
	sub_4269F0();
	return 0;
}

//----- (00426F40) --------------------------------------------------------
BOOL __cdecl sub_426F40(int a1, const char* a2, _DWORD* a3, int(__cdecl* a4)(int)) {
	BOOL result;         // eax
	const char* v5;      // eax
	int v6;              // ebp
	unsigned __int8* v7; // edi

	*a3 = 0;
	if (a4) {
		v5 = *(const char**)getMemAt(0x587000, 70168);
		v6 = 0;
		if (!*getMemU32Ptr(0x587000, 70168))
			goto LABEL_7;
		v7 = getMemAt(0x587000, 70168);
		while (strcmp(v5, a2)) {
			v5 = (const char*)*((_DWORD*)v7 + 2);
			v7 += 8;
			++v6;
			if (!v5)
				goto LABEL_7;
		}
		if (a4(a1)) {
		LABEL_7:
			result = *getMemU32Ptr(0x587000, 8 * v6 + 70168) != 0;
		} else {
			*a3 = 1;
			sub_4269F0();
			result = 0;
		}
	} else {
		*a3 = 1;
		sub_4269F0();
		result = 0;
	}
	return result;
}

//----- (00426FF0) --------------------------------------------------------
void sub_426FF0() { nox_srand(0x9C5u); }

//----- (00427000) --------------------------------------------------------
void sub_427000() { nox_srand(0x9DAu); }

//----- (00427010) --------------------------------------------------------
int __cdecl sub_427010(const char* a1) {
	int v1;          // ebp
	const char** v2; // edi

	v1 = 0;
	v2 = (const char**)getMemAt(0x587000, 70500);
	while (strcmp(*v2, a1)) {
		++v2;
		++v1;
		if ((int)v2 >= (int)getMemAt(0x587000, 70664))
			return 0;
	}
	return v1;
}

//----- (00427230) --------------------------------------------------------
char* __cdecl sub_427230(int a1) { return *(char**)getMemAt(0x587000, 4 * a1 + 70500); }

//----- (00427240) --------------------------------------------------------
int __cdecl sub_427240(int a1) {
	int result; // eax

	if (a1 > 0 && a1 < 41 && *getMemU32Ptr(0x5D4594, 28 * a1 + 740080))
		result = *getMemU32Ptr(0x5D4594, 28 * a1 + 740076);
	else
		result = 0;
	return result;
}

//----- (00427270) --------------------------------------------------------
int __cdecl sub_427270(wchar_t* a1) {
	int v1;              // edi
	unsigned __int8* v2; // esi

	v1 = 1;
	v2 = getMemAt(0x5D4594, 740104);
	while (!*((_DWORD*)v2 + 1) || nox_wcscmp(*(const wchar_t**)v2, a1)) {
		v2 += 28;
		++v1;
		if ((int)v2 >= (int)getMemAt(0x5D4594, 741224))
			return 0;
	}
	return v1;
}

//----- (004272B0) --------------------------------------------------------
int __cdecl sub_4272B0(int a1) {
	int result;          // eax
	unsigned __int8* v2; // ecx

	result = 1;
	v2 = getMemAt(0x5D4594, 740108);
	while (!*(_DWORD*)v2 || *(_DWORD*)v2 != a1) {
		v2 += 28;
		++result;
		if ((int)v2 >= (int)getMemAt(0x5D4594, 741228))
			return 0;
	}
	return result;
}

//----- (004272E0) --------------------------------------------------------
int __cdecl sub_4272E0(int a1) { return *getMemU32Ptr(0x5D4594, 28 * a1 + 740084); }

//----- (00427300) --------------------------------------------------------
int sub_427300() {
	int result;          // eax
	unsigned __int8* v1; // ecx

	result = 1;
	v1 = getMemAt(0x5D4594, 740108);
	while (!*(_DWORD*)v1) {
		v1 += 28;
		++result;
		if ((int)v1 >= (int)getMemAt(0x5D4594, 741228))
			return 0;
	}
	return result;
}

//----- (00427320) --------------------------------------------------------
int __cdecl sub_427320(int a1) {
	int result;          // eax
	unsigned __int8* v2; // ecx

	result = a1 + 1;
	if (a1 + 1 >= 41)
		return 0;
	v2 = getMemAt(0x5D4594, 28 * result + 740080);
	while (!*(_DWORD*)v2) {
		v2 += 28;
		++result;
		if ((int)v2 >= (int)getMemAt(0x5D4594, 741228))
			return 0;
	}
	return result;
}

//----- (00427350) --------------------------------------------------------
int __cdecl sub_427350(int a1) {
	int result;         // eax
	unsigned __int8* i; // ecx

	if (!a1)
		return 0;
	result = a1 - 1;
	if (a1 - 1 <= 0)
		return 0;
	for (i = getMemAt(0x5D4594, 28 * result + 740080); !*(_DWORD*)i; i -= 28) {
		if (--result <= 0)
			return 0;
	}
	return result;
}

//----- (00427380) --------------------------------------------------------
BOOL __cdecl sub_427380(int a1) { return *getMemU32Ptr(0x5D4594, 28 * a1 + 740080) != 0; }

//----- (004273A0) --------------------------------------------------------
int __cdecl sub_4273A0(int a1) { return *getMemU32Ptr(0x5D4594, 28 * a1 + 740096); }

//----- (004273C0) --------------------------------------------------------
int __cdecl sub_4273C0(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 28 * a1 + 740096) = 1;
	return result;
}

//----- (004273E0) --------------------------------------------------------
int __cdecl sub_4273E0(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 28 * a1 + 740096) = 0;
	return result;
}

//----- (00427400) --------------------------------------------------------
int __cdecl sub_427400(int a1) {
	int result; // eax

	if (a1 <= 0 || a1 >= 41)
		result = 0;
	else
		result = *getMemU32Ptr(0x5D4594, 28 * a1 + 740092);
	return result;
}

//----- (00427430) --------------------------------------------------------
int __cdecl sub_427430(int a1) {
	int result; // eax

	if (a1 <= 0 || a1 >= 41)
		result = 0;
	else
		result = *getMemU32Ptr(0x5D4594, 28 * a1 + 740088);
	return result;
}

//----- (00427460) --------------------------------------------------------
unsigned __int8 __cdecl sub_427460(int a1) { return getMemByte(0x5D4594, 28 * a1 + 740100); }

//----- (00427480) --------------------------------------------------------
void sub_427480() { nox_srand(0x9DBu); }

//----- (00427490) --------------------------------------------------------
_BYTE* __cdecl sub_427490(int a1, char* a2, __int16 a3) {
	_BYTE* result; // eax
	_BYTE* v4;     // esi
	int v5;        // eax

	result = malloc(0x4Cu);
	v4 = result;
	if (result) {
		memset(result, 0, 0x4Cu);
		strncpy(result, a2, 0x3Fu);
		v4[63] = 0;
		*((_WORD*)v4 + 36) = a3;
		*((_DWORD*)v4 + 17) = 0;
		*((_DWORD*)v4 + 16) = *(_DWORD*)(a1 + 3644);
		v5 = *(_DWORD*)(a1 + 3644);
		if (v5)
			*(_DWORD*)(v5 + 68) = v4;
		*(_DWORD*)(a1 + 3644) = v4;
		result = v4;
	}
	return result;
}

//----- (00427500) --------------------------------------------------------
void __cdecl sub_427500(int a1, char* a2, __int16 a3) {
	int v3;    // esi
	_BYTE* v4; // eax

	v3 = *(_DWORD*)(*(_DWORD*)(a1 + 748) + 276);
	v4 = sub_427490(v3, a2, a3);
	if (v4) {
		if (*(_BYTE*)(v3 + 2064) == 31)
			sub_469BC0();
		else
			sub_4D9440(*(unsigned __int8*)(v3 + 2064), (int)v4);
	}
}

//----- (00427550) --------------------------------------------------------
int __cdecl sub_427550(char* a1, __int16 a2) {
	int result; // eax
	int i;      // esi

	result = sub_4DA7C0();
	for (i = result; result; i = result) {
		sub_427500(i, a1, a2);
		result = sub_4DA7F0(i);
	}
	return result;
}

//----- (00427590) --------------------------------------------------------
int __cdecl sub_427590(int a1, const char* a2) {
	int v2; // edi
	int v4; // eax
	int v5; // eax

	v2 = *(_DWORD*)(a1 + 3644);
	if (!v2)
		return 0;
	while (strcmp((const char*)v2, a2)) {
		v2 = *(_DWORD*)(v2 + 64);
		if (!v2)
			return 0;
	}
	v4 = *(_DWORD*)(v2 + 68);
	if (v4)
		*(_DWORD*)(v4 + 64) = *(_DWORD*)(v2 + 64);
	v5 = *(_DWORD*)(v2 + 64);
	if (v5)
		*(_DWORD*)(v5 + 68) = *(_DWORD*)(v2 + 68);
	if (v2 == *(_DWORD*)(a1 + 3644))
		*(_DWORD*)(a1 + 3644) = *(_DWORD*)(v2 + 64);
	free((LPVOID)v2);
	return 1;
}

//----- (00427630) --------------------------------------------------------
void __cdecl sub_427630(int a1, const char* a2) {
	int v2; // esi

	v2 = *(_DWORD*)(*(_DWORD*)(a1 + 748) + 276);
	if (sub_427590(v2, a2)) {
		if (*(_BYTE*)(v2 + 2064) == 31)
			sub_469BC0();
		else
			sub_4D94A0(*(unsigned __int8*)(v2 + 2064), a2);
	}
}

//----- (00427680) --------------------------------------------------------
int __cdecl sub_427680(const char* a1) {
	int result; // eax
	int i;      // esi

	result = sub_4DA7C0();
	for (i = result; result; i = result) {
		sub_427630(i, a1);
		result = sub_4DA7F0(i);
	}
	return result;
}

//----- (004276B0) --------------------------------------------------------
int __cdecl sub_4276B0(int a1, const char* a2, __int16 a3) {
	int v3;     // edi
	int result; // eax

	v3 = *(_DWORD*)(a1 + 3644);
	if (!v3)
		return 0;
	while (strcmp((const char*)v3, a2)) {
		v3 = *(_DWORD*)(v3 + 64);
		if (!v3)
			return 0;
	}
	result = v3;
	*(_WORD*)(v3 + 72) = a3;
	return result;
}

//----- (00427720) --------------------------------------------------------
int __cdecl sub_427720(int a1, const char* a2, __int16 a3) {
	int v3;     // esi
	int result; // eax

	v3 = *(_DWORD*)(*(_DWORD*)(a1 + 748) + 276);
	result = sub_4276B0(v3, a2, a3);
	if (result) {
		if (*(_BYTE*)(v3 + 2064) != 31)
			result = sub_4D9500(*(unsigned __int8*)(v3 + 2064), result);
	}
	return result;
}

//----- (00427770) --------------------------------------------------------
int __cdecl sub_427770(const char* a1, __int16 a2) {
	int result; // eax
	int i;      // esi

	result = sub_4DA7C0();
	for (i = result; result; i = result) {
		sub_427720(i, a1, a2);
		result = sub_4DA7F0(i);
	}
	return result;
}

//----- (004277B0) --------------------------------------------------------
int __cdecl sub_4277B0(int a1, unsigned __int16 a2) {
	int v2;     // edi
	int result; // eax
	int v4;     // esi
	int v5;     // edx
	int v6;     // ecx

	v2 = *(_DWORD*)(*(_DWORD*)(a1 + 748) + 276);
	result = *(_DWORD*)(v2 + 3644);
	if (result) {
		do {
			v4 = *(_DWORD*)(result + 64);
			if (a2 & *(_WORD*)(result + 72)) {
				v5 = *(_DWORD*)(result + 68);
				if (v5)
					*(_DWORD*)(v5 + 64) = *(_DWORD*)(result + 64);
				v6 = *(_DWORD*)(result + 64);
				if (v6)
					*(_DWORD*)(v6 + 68) = *(_DWORD*)(result + 68);
				if (result == *(_DWORD*)(v2 + 3644))
					*(_DWORD*)(v2 + 3644) = *(_DWORD*)(result + 64);
				free((LPVOID)result);
			}
			result = v4;
		} while (v4);
	}
	return result;
}

//----- (00427820) --------------------------------------------------------
_DWORD* __cdecl sub_427820(int a1) {
	_DWORD* result; // eax

	sub_40D7D0(a1, 1);
	result = (_DWORD*)sub_41F800((const char*)(a1 + 36));
	if (result)
		*result |= 4u;
	return result;
}

//----- (00427850) --------------------------------------------------------
_DWORD* __cdecl sub_427850(int a1) {
	_DWORD* result; // eax

	sub_40D7D0(a1, 0);
	result = (_DWORD*)sub_41F800((const char*)(a1 + 36));
	if (result)
		*result &= 0xFFFFFFFB;
	return result;
}

//----- (00427880) --------------------------------------------------------
BOOL __cdecl sub_427880(const char* a1) {
	const char* v1; // eax
	_BYTE* v2;      // eax

	v1 = a1;
	if (a1 && (*a1 == 64 || *a1 == 32))
		v1 = a1 + 1;
	v2 = (_BYTE*)sub_41F800(v1);
	return v2 && *v2 & 4;
}

//----- (004278B0) --------------------------------------------------------
int __cdecl sub_4278B0(float* a1, float* a2, float* a3) {
	double v3; // st7
	double v4; // st7

	*(float*)&dword_5d4594_741244 = a1[2] - *a1;
	*(float*)&dword_5d4594_741248 = a1[3] - a1[1];
	*(float*)&dword_5d4594_741252 = a2[2] - *a2;
	*(float*)&dword_5d4594_741256 = a2[3] - a2[1];
	*(float*)&dword_5d4594_741260 = *a2 - *a1;
	v3 = a2[1] - a1[1];
	*getMemFloatPtr(0x5D4594, 741264) = v3;
	*(float*)&dword_5d4594_741292 =
		v3 * *(float*)&dword_5d4594_741244 - *(float*)&dword_5d4594_741260 * *(float*)&dword_5d4594_741248;
	v4 = *(float*)&dword_5d4594_741252 * *(float*)&dword_5d4594_741248 -
		 *(float*)&dword_5d4594_741256 * *(float*)&dword_5d4594_741244;
	*(float*)&dword_5d4594_741284 = v4;
	if (v4 == 0.0)
		return 0;
	*a3 = *(float*)&dword_5d4594_741292 * *(float*)&dword_5d4594_741252 / *(float*)&dword_5d4594_741284 + *a2;
	a3[1] = *(float*)&dword_5d4594_741292 * *(float*)&dword_5d4594_741256 / *(float*)&dword_5d4594_741284 + a2[1];
	return 1;
}

//----- (00427980) --------------------------------------------------------
int __cdecl sub_427980(float4* a1, float4* a2) {
	double v2;  // st7
	float v3;   // ecx
	float v4;   // eax
	float v5;   // eax
	int result; // eax
	double v7;  // st7
	float v8;   // [esp+4h] [ebp+4h]
	float v9;   // [esp+4h] [ebp+4h]

	if (a1->field_0 >= (double)a1->field_8) {
		*getMemFloatPtr(0x5D4594, 741268) = a1->field_8;
		v2 = a1->field_0;
	} else {
		*getMemFloatPtr(0x5D4594, 741268) = a1->field_0;
		v2 = a1->field_8;
	}
	*getMemFloatPtr(0x5D4594, 741276) = v2;
	if (a1->field_4 >= (double)a1->field_C) {
		*getMemFloatPtr(0x5D4594, 741272) = a1->field_C;
		v3 = a1->field_4;
	} else {
		*getMemFloatPtr(0x5D4594, 741272) = a1->field_4;
		v3 = a1->field_C;
	}
	*getMemFloatPtr(0x5D4594, 741280) = v3;
	if (a2->field_0 >= (double)a2->field_8) {
		*getMemFloatPtr(0x5D4594, 741228) = a2->field_8;
		v4 = a2->field_0;
	} else {
		*getMemFloatPtr(0x5D4594, 741228) = a2->field_0;
		v4 = a2->field_8;
	}
	*getMemFloatPtr(0x5D4594, 741236) = v4;
	if (a2->field_4 >= (double)a2->field_C) {
		*getMemFloatPtr(0x5D4594, 741232) = a2->field_C;
		v5 = a2->field_4;
	} else {
		*getMemFloatPtr(0x5D4594, 741232) = a2->field_4;
		v5 = a2->field_C;
	}
	*getMemFloatPtr(0x5D4594, 741240) = v5;
	if (v2 < *getMemFloatPtr(0x5D4594, 741228) || *getMemFloatPtr(0x5D4594, 741268) > (double)*getMemFloatPtr(0x5D4594, 741236) ||
		*getMemFloatPtr(0x5D4594, 741280) < (double)*getMemFloatPtr(0x5D4594, 741232) ||
		*getMemFloatPtr(0x5D4594, 741272) > (double)*getMemFloatPtr(0x5D4594, 741240)) {
		goto LABEL_36;
	}
	if (a1->field_4 == a1->field_C && a2->field_4 == a2->field_C)
		return 1;
	*(float*)&dword_5d4594_741244 = a1->field_8 - a1->field_0;
	*(float*)&dword_5d4594_741248 = a1->field_C - a1->field_4;
	*(float*)&dword_5d4594_741252 = a2->field_8 - a2->field_0;
	*(float*)&dword_5d4594_741256 = a2->field_C - a2->field_4;
	*(float*)&dword_5d4594_741260 = a2->field_0 - a1->field_0;
	v7 = a2->field_4 - a1->field_4;
	*getMemFloatPtr(0x5D4594, 741264) = v7;
	*(float*)&dword_5d4594_741292 =
		v7 * *(float*)&dword_5d4594_741244 - *(float*)&dword_5d4594_741260 * *(float*)&dword_5d4594_741248;
	*(float*)&dword_5d4594_741284 = *(float*)&dword_5d4594_741252 * *(float*)&dword_5d4594_741248 -
									*(float*)&dword_5d4594_741256 * *(float*)&dword_5d4594_741244;
	if (*(float*)&dword_5d4594_741292 == 0.0 || *(float*)&dword_5d4594_741284 == 0.0 ||
		*(float*)&dword_5d4594_741292 < 0.0 && *(float*)&dword_5d4594_741284 > 0.0) {
		goto LABEL_36;
	}
	if (*(float*)&dword_5d4594_741292 > 0.0 && *(float*)&dword_5d4594_741284 < 0.0 ||
		(v8 = sub_419A10(*(float*)&dword_5d4594_741292), sub_419A10(*(float*)&dword_5d4594_741284) < v8) ||
		(*getMemU32Ptr(0x5D4594, 741288) = dword_5d4594_741284,
		 *(float*)& dword_5d4594_741296 = *getMemFloatPtr(0x5D4594, 741264) * *(float*)&dword_5d4594_741252 -
										  *(float*)&dword_5d4594_741260 * *(float*)&dword_5d4594_741256,
		 *(float*)&dword_5d4594_741296 < 0.0) &&
			*(float*)&dword_5d4594_741284 > 0.0 ||
		*(float*)&dword_5d4594_741296 > 0.0 && *(float*)&dword_5d4594_741284 < 0.0 ||
		(v9 = sub_419A10(*(float*)&dword_5d4594_741296), sub_419A10(*getMemFloatPtr(0x5D4594, 741288)) < v9)) {
	LABEL_36:
		result = 0;
	} else {
		result = 1;
	}
	return result;
}

//----- (00427C80) --------------------------------------------------------
int __cdecl sub_427C80(int4* a1, int4* a2) {
	int v2;    // eax
	int v3;    // ecx
	int v4;    // esi
	int v5;    // ebp
	int v6;    // edx
	int v7;    // edi
	int v8;    // ebx
	int v10;   // ebp
	int v11;   // edx
	int v12;   // ebp
	int v13;   // esi
	int v14;   // ecx
	int v15;   // eax
	int v16;   // esi
	int v17;   // [esp+10h] [ebp-10h]
	int v18;   // [esp+14h] [ebp-Ch]
	int v19;   // [esp+18h] [ebp-8h]
	int v20;   // [esp+1Ch] [ebp-4h]
	int v21;   // [esp+24h] [ebp+4h]
	int4* v22; // [esp+28h] [ebp+8h]
	int4* v23; // [esp+28h] [ebp+8h]

	v2 = a1->field_0;
	v3 = a1->field_4;
	v4 = a1->field_8;
	v19 = a1->field_C;
	v5 = a2->field_0;
	v21 = a2->field_4;
	v17 = a2->field_C;
	v6 = a2->field_8;
	v7 = v4 - v2;
	v8 = a2->field_0 - v6;
	v20 = a2->field_0;
	if (v4 - v2 >= 0) {
		v6 = a2->field_8;
		v22 = (int4*)v2;
	} else {
		v22 = (int4*)v4;
		v4 = v2;
	}
	if (v8 <= 0) {
		if (v4 < v5 || v6 < (int)v22)
			return 0;
	} else if (v4 < v6 || v5 < (int)v22) {
		return 0;
	}
	v10 = v19;
	v11 = v21 - v17;
	v18 = v19 - v3;
	if (v19 - v3 >= 0) {
		v23 = (int4*)v3;
	} else {
		v23 = (int4*)v19;
		v10 = v3;
	}
	if (v11 <= 0) {
		if (v10 < v21 || v17 < (int)v23)
			return 0;
	} else {
		if (v10 < v17)
			return 0;
		if (v21 < (int)v23)
			return 0;
	}
	v12 = v2 - v20;
	v13 = v3 - v21;
	v14 = v11 * (v2 - v20) - v8 * (v3 - v21);
	v15 = v8 * v18 - v7 * v11;
	if (v15 <= 0) {
		if (v14 > 0 || v14 < v15)
			return 0;
	} else {
		if (v14 < 0)
			return 0;
		if (v14 > v15)
			return 0;
	}
	v16 = v7 * v13 - v18 * v12;
	if (v15 <= 0) {
		if (v16 <= 0 && v16 >= v15)
			return 1;
		return 0;
	}
	if (v16 < 0)
		return 0;
	if (v16 > v15)
		return 0;
	return 1;
}

//----- (00427DF0) --------------------------------------------------------
int __cdecl sub_427DF0(int a1, int* a2, float a3) {
	double v3; // st7
	double v4; // st7
	double v6; // st7
	float v7;  // [esp+Ch] [ebp-1Ch]
	float v8;  // [esp+10h] [ebp-18h]
	float v9;  // [esp+10h] [ebp-18h]
	float v10; // [esp+10h] [ebp-18h]
	float v11; // [esp+14h] [ebp-14h]
	float v12; // [esp+14h] [ebp-14h]
	float v13; // [esp+14h] [ebp-14h]
	float v14; // [esp+18h] [ebp-10h]
	float v15; // [esp+1Ch] [ebp-Ch]
	float v16; // [esp+20h] [ebp-8h]
	float v17; // [esp+24h] [ebp-4h]
	float v18; // [esp+30h] [ebp+8h]

	v16 = (double)*a2;
	v17 = (double)a2[1];
	v8 = (double)a2[2] - v16;
	v3 = (double)a2[3] - v17;
	v11 = v3;
	v7 = nox_double2float(sqrt(v3 * v11 + v8 * v8));
	v14 = v8 / v7;
	v4 = v11 / v7;
	v15 = v4;
	v9 = (double)*(int*)a1 - v16;
	v12 = (double)*(int*)(a1 + 4) - v17;
	if (nox_double2float(fabs(v9 * -v4 + v12 * v14)) > a3)
		return 0;
	v6 = v12 * v15 + v9 * v14;
	v18 = v6;
	if (v6 > v7)
		return 0;
	if (v18 < 0.0)
		return 0;
	v10 = v18 * v14 + v16;
	v13 = v18 * v15 + v17;
	*(_DWORD*)a1 = nox_float2int(v10);
	*(_DWORD*)(a1 + 4) = nox_float2int(v13);
	return 1;
}
