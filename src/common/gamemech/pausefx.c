#include "pausefx.h"

#include "../../proto.h"
extern _DWORD dword_5d4594_2523776;
extern _DWORD dword_5d4594_2523780;

//----- (0057AF30) --------------------------------------------------------
void __cdecl sub_57AF30(int a1, int a2) {
	int v2;      // ecx
	_DWORD* v3;  // eax
	wchar_t* v4; // eax
	int v5;      // esi

	if (*(_DWORD*)&byte_5D4594[2523804] != 1 && !sub_413A50()) {
		v2 = a1;
		if (a1)
			dword_5d4594_2523780 = a1;
		else
			v2 = dword_5d4594_2523780;
		if (a2) {
			if (a2 != 1) {
				v3 = *(_DWORD**)&dword_5d4594_2523776;
			LABEL_12:
				if (v3) {
					if (v2) {
						sub_4DAA50((int)v3, 0, *(float*)(v2 + 56), *(float*)(v2 + 60));
					} else {
						sub_4E38A0((int)v3);
						dword_5d4594_2523776 = 0;
					}
					v2 = dword_5d4594_2523780;
				}
				if ((!a2 || a2 == 1) && v2) {
					sub_522FF0(154, (float2*)(v2 + 56));
					v2 = dword_5d4594_2523780;
				}
				if (!a2) {
					if (!v2) {
					LABEL_29:
						*(_DWORD*)&byte_5D4594[2523796] = 5000;
					LABEL_30:
						*(_DWORD*)&byte_5D4594[2523800] = 0;
						*(_DWORD*)&byte_5D4594[2523772] = a2;
						*(_DWORD*)&byte_5D4594[2523804] = 1;
						sub_413A00(1);
						*(_QWORD*)&byte_5D4594[2523788] = sub_416BB0();
						return;
					}
					sub_501960(902, v2, 2, *(_DWORD*)(v2 + 36));
					v4 =
					    loadString_sub_40F1D0((char*)&byte_587000[312764], 0,
								  "C:\\NoxPost\\src\\common\\GameMech\\PauseFX.c", 109);
					sub_4D9EB0(*(int*)&dword_5d4594_2523780, v4);
					v2 = dword_5d4594_2523780;
				}
				if (v2) {
					v5 = *(_DWORD*)(v2 + 748);
					if (sub_4FA020((_DWORD*)v2, 30) == 1)
						*(_BYTE*)(v5 + 236) = 4;
				}
				if (a2) {
					*(_DWORD*)&byte_5D4594[2523796] = 0;
					if (a2 != 1)
						goto LABEL_30;
				}
				goto LABEL_29;
			}
			v3 = sub_4E3810((CHAR*)&byte_587000[312708]);
		} else {
			v3 = sub_4E3810((CHAR*)&byte_587000[312700]);
		}
		v2 = dword_5d4594_2523780;
		dword_5d4594_2523776 = v3;
		goto LABEL_12;
	}
}
