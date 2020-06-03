#include "selectdw.h"

#include "../../proto.h"

//----- (004773C0) --------------------------------------------------------
void __cdecl sub_4773C0(_DWORD* a1) {
	int v1;     // eax
	int v2;     // eax
	_DWORD* v3; // eax
	int v4;     // eax
	int v5;     // edx

	if (*(_DWORD*)&byte_5D4594[1096640]) {
		if (*(_BYTE*)(*(_DWORD*)&byte_5D4594[1096640] + 112) & 6 &&
		    !sub_495A80(*(_DWORD*)(*(_DWORD*)&byte_5D4594[1096640] + 128))) {
			v4 = sub_415FF0(0, 1, "C:\\NoxPost\\src\\Client\\Draw\\selectdw.c", 440);
			if (!v4) {
				v3 = *(_DWORD**)&byte_5D4594[2598268];
				goto LABEL_15;
			}
			if (v4 == 1) {
				v3 = *(_DWORD**)&byte_5D4594[2650644];
				goto LABEL_15;
			}
		} else {
			v1 = sub_415FF0(0, 2, "C:\\NoxPost\\src\\Client\\Draw\\selectdw.c", 423);
			if (!v1) {
				v3 = *(_DWORD**)&byte_5D4594[2523948];
				goto LABEL_15;
			}
			v2 = v1 - 1;
			if (!v2) {
				v3 = *(_DWORD**)&byte_5D4594[2650684];
				goto LABEL_15;
			}
			if (v2 == 1) {
				v3 = *(_DWORD**)&byte_5D4594[2649820];
				goto LABEL_15;
			}
		}
		v3 = a1;
	LABEL_15:
		v5 = *(_DWORD*)(*(_DWORD*)&byte_5D4594[1096640] + 112);
		if (!(v5 & 0x200))
			sub_477470(a1, (int)v3, *(int*)&byte_5D4594[1096640]);
	}
}
