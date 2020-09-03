#include "explevel.h"

#include "../../common/gamemech/pausefx.h"
#include "../../proto.h"
extern _DWORD dword_5d4594_2516328;
extern _DWORD dword_5d4594_2516348;

//----- (0056F980) --------------------------------------------------------
_DWORD* __cdecl sub_56F980(int a1, unsigned __int8 a2) {
	_DWORD* result; // eax
	int v3;         // ecx

	result = (_DWORD*)a1;
	if (a1 >= 657757279) {
		result = sub_56F590(a1);
		if (result) {
			dword_5d4594_2516328 ^= result[1];
			v3 = dword_5d4594_2516348 ^ (a2 + (dword_5d4594_2516348 ^ result[1]));
			result[1] = v3;
			dword_5d4594_2516328 ^= v3;
			result = (_DWORD*)sub_56F5C0();
		}
	}
	return result;
}

//----- (004EF2E0) --------------------------------------------------------
void __cdecl sub_4EF2E0_exp_level(int a1) {
	int v1;      // esi
	wchar_t* v2; // eax

	v1 = *(_DWORD*)(*(_DWORD*)(a1 + 748) + 276);
	if ((sub_4DB1B0() != 1 || !sub_4DB1C0()) &&
		sub_419D70(getMemAt(0x587000, 206192), *(char*)(v1 + 3684) + 1) <= *(float*)(a1 + 28)) {
		++*(_BYTE*)(v1 + 3684);
		sub_56F980(*(_DWORD*)(v1 + 4644), 1u);
		sub_4EEDC0(a1, 1);
		if (nox_common_gameFlags_check_40A5C0(2048)) {
			sub_57AF30(a1, 0);
		} else {
			sub_501960(902, a1, 2, *(_DWORD*)(a1 + 36));
			v2 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 206244), 0, "C:\\NoxPost\\src\\Server\\GameMech\\explevel.c",
									   253);
			sub_4D9EB0(a1, v2);
		}
	}
}

//----- (004EF3A0) --------------------------------------------------------
void __cdecl sub_4EF3A0_exp_level(int a1, float a2) {
	int v2;      // ecx
	wchar_t* v3; // eax

	v2 = *(_DWORD*)(a1 + 748);
	*(float*)(a1 + 28) = a2 + *(float*)(a1 + 28);
	sub_56FA40(*(_DWORD*)(*(_DWORD*)(v2 + 276) + 4604), a2);
	sub_4D81A0(a1);
	v3 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 206296), 0, "C:\\NoxPost\\src\\Server\\GameMech\\explevel.c", 381);
	sub_4D9EB0(a1, v3, (unsigned int)(__int64)a2);
	sub_4EF2E0_exp_level(a1);
}
