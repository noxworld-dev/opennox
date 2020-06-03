#include "woluser.h"

#include "../../proto.h"

//----- (0041F620) --------------------------------------------------------
void __cdecl sub_41F620(int a1) {
	_DWORD* v1;  // esi
	int v2;      // ebp
	_DWORD* v3;  // edi
	int v4;      // eax
	int v5;      // eax
	int v6;      // edi
	wchar_t* v7; // eax

	v1 = *(_DWORD**)&byte_5D4594[531648];
	v2 = 0;
	if (*(_DWORD*)&byte_5D4594[531648]) {
		while (1) {
			v3 = (_DWORD*)v1[5];
			if (!_strcmpi((const char*)(*v1 + 36), (const char*)(a1 + 36)))
				break;
			++v2;
			v1 = v3;
			if (!v3)
				return;
		}
		v4 = v1[6];
		if (v4)
			*(_DWORD*)(v4 + 20) = v1[5];
		else
			*(_DWORD*)&byte_5D4594[531648] = v1[5];
		v5 = v1[5];
		if (v5)
			*(_DWORD*)(v5 + 24) = v1[6];
		else
			*(_DWORD*)&byte_5D4594[531652] = v1[6];
		if (sub_41E2F0() == 7) {
			v6 = sub_446C70();
			sub_448620(v2);
			if (v6 != -1 && sub_446C70() == -1) {
				sub_452D80(226, 100);
				v7 = loadString_sub_40F1D0((char*)&byte_587000[60020], 0,
							   "C:\\NoxPost\\src\\common\\WolAPI\\woluser.c", 208);
				sub_447310(0, (int)v7);
			}
		}
		free(v1);
	}
}
