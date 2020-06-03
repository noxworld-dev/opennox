#include "mondraw.h"

#include "../../proto.h"

//----- (004BC490) --------------------------------------------------------
char __cdecl sub_4BC490(int a1) {
	int v1;          // eax
	unsigned int v2; // ecx
	int v3;          // eax
	int v4;          // eax
	int v5;          // eax
	int v6;          // eax
	int v7;          // eax
	int v8;          // eax

	LOBYTE(v1) = byte_5D4594[2598000];
	if (!(byte_5D4594[2598000] & 3) && *(_DWORD*)(a1 + 276) == 8 && *(_DWORD*)(a1 + 116) & 0x40000) {
		v2 = *(_DWORD*)(a1 + 308);
		v3 = *(_DWORD*)(a1 + 308);
		if (v3) {
			v4 = v3 - 2;
			if (v4) {
				if (v4 == 2) {
					v1 = sub_415FF0(0, 100, "C:\\NoxPost\\src\\Client\\Draw\\mondraw.c", 74);
					if (v1 < 15) {
						v5 = *(_DWORD*)(a1 + 308);
						*(_BYTE*)(a1 + 299) = 0;
						v1 = v5 - 1;
						*(_DWORD*)(a1 + 308) = v1;
					}
				} else {
					LOBYTE(v1) = *(_BYTE*)(a1 + 299);
					switch ((_BYTE)v1) {
					case 0:
						if (v2 < 2) {
							*(_DWORD*)(a1 + 308) = v2 + 1;
							return v1;
						}
					LABEL_11:
						*(_DWORD*)(a1 + 308) = v2 - 1;
						return v1;
					case 1:
						goto LABEL_11;
					case 2:
						*(_DWORD*)(a1 + 308) = v2 + 1;
						break;
					default:
						*(_DWORD*)(a1 + 308) = 2;
						*(_BYTE*)(a1 + 299) = 0;
						break;
					}
				}
			} else {
				v1 = sub_415FF0(0, 100, "C:\\NoxPost\\src\\Client\\Draw\\mondraw.c", 52);
				if (v1 >= 5) {
					if (v1 < 10) {
						v7 = *(_DWORD*)(a1 + 308);
						*(_BYTE*)(a1 + 299) = 2;
						v1 = v7 + 1;
						*(_DWORD*)(a1 + 308) = v1;
					}
				} else {
					v6 = *(_DWORD*)(a1 + 308);
					*(_BYTE*)(a1 + 299) = 1;
					v1 = v6 - 1;
					*(_DWORD*)(a1 + 308) = v1;
				}
			}
		} else {
			v1 = sub_415FF0(0, 100, "C:\\NoxPost\\src\\Client\\Draw\\mondraw.c", 66);
			if (v1 < 15) {
				v8 = *(_DWORD*)(a1 + 308);
				*(_BYTE*)(a1 + 299) = 0;
				v1 = v8 + 1;
				*(_DWORD*)(a1 + 308) = v1;
			}
		}
	}
	return v1;
}
