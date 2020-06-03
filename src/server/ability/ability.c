#include "../../client/gui/guimsg.h"

#include "../../proto.h"

//----- (004D8060) --------------------------------------------------------
int __cdecl sub_4D8060(int a1, int a2, int a3) {
	int result; // eax
	int v4;     // eax

	result = a1;
	if (*(_BYTE*)(a1 + 8) & 4) {
		v4 = *(_DWORD*)(a1 + 748);
		LOBYTE(a1) = -51;
		BYTE1(a1) = a2;
		BYTE2(a1) = *(_BYTE*)(*(_DWORD*)(v4 + 276) + 4 * a2 + 3696);
		if (a3)
			BYTE2(a1) |= 0x80u;
		result = sub_4E5390(*(unsigned __int8*)(*(_DWORD*)(v4 + 276) + 2064), (int)&a1, 3, 0, 1);
	}
	return result;
}

//----- (004FB960) --------------------------------------------------------
void __cdecl sub_4FB960_ability(int a1) {
	wchar_t* v1; // eax

	v1 = loadString_sub_40F1D0(*(char**)&byte_587000[4 * a1 + 217092], 0,
				   "C:\\NoxPost\\src\\Server\\Ability\\Ability.c", 75);
	sub_445490(v1);
}

//----- (004FB9C0) --------------------------------------------------------
int __cdecl sub_4FB9C0_ability(int a1, int a2, int a3) {
	int v3;       // eax
	int v4;       // ecx
	int v5;       // edx
	_DWORD* v6;   // ecx
	_DWORD* v7;   // ecx
	int i;        // edi
	int result;   // eax
	wchar_t* v10; // eax

	if (!(*(_BYTE*)(a1 + 8) & 4))
		return 0;
	if (a2 <= 0 || a2 >= 6) {
		v10 = loadString_sub_40F1D0((char*)&byte_587000[217368], 0,
					    "C:\\NoxPost\\src\\Server\\Ability\\Ability.c", 108);
		sub_4D9EB0(a1, v10);
		return 0;
	}
	v3 = *(_DWORD*)(a1 + 748);
	v4 = *(_DWORD*)(v3 + 276);
	v5 = *(_DWORD*)(v4 + 4 * a2 + 3696);
	v6 = (_DWORD*)(v4 + 4 * a2 + 3696);
	if (v5) {
		sub_4DA2C0(a1, "use.c:HadAbility", 0);
		result = 0;
	} else {
		*v6 = 5;
		v7 = (_DWORD*)(*(_DWORD*)(v3 + 276) + 4 * a2 + 3696);
		if (*v7 > 5)
			*v7 = 5;
		sub_56FCE0(*(_DWORD*)(*(_DWORD*)(v3 + 276) + 4636), a2,
			   *(_DWORD*)(*(_DWORD*)(v3 + 276) + 4 * a2 + 3696));
		sub_4D8060(a1, a2, a3);
		if (nox_common_gameFlags_check_40A5C0(4096)) {
			sub_4FAD50(a1, 2, a1, a2);
			if (!sub_419E60(a1)) {
				for (i = sub_4DA7C0(); i; i = sub_4DA7F0(i)) {
					if (i != a1)
						sub_4FAD50(i, 2, a1, a2);
				}
			}
		}
		result = 1;
	}
	return result;
}
