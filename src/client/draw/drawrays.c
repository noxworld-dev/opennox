#include "drawrays.h"

#include "../../proto.h"
#include "fx.h"
extern _DWORD dword_5d4594_1304328;

//----- (0049BDD0) --------------------------------------------------------
int __cdecl sub_49BDD0(unsigned __int8* a1) {
	int result;          // eax
	unsigned __int8* v2; // esi
	unsigned __int8* v3; // edi
	int v4;              // ebx
	int v5;              // ebp
	int v6;              // eax
	int v7;              // ecx
	int v8;              // eax
	int v9;              // eax
	int v10;             // eax
	int v11;             // ecx
	int v12;             // [esp-Ch] [ebp-28h]
	int v13;             // [esp-Ch] [ebp-28h]
	int v14;             // [esp-Ch] [ebp-28h]
	int v15;             // [esp-Ch] [ebp-28h]
	char v16;            // [esp+10h] [ebp-Ch]
	char v17;            // [esp+10h] [ebp-Ch]
	char v18;            // [esp+10h] [ebp-Ch]
	WORD v19[4];         // [esp+14h] [ebp-8h]
	int v20;             // [esp+20h] [ebp+4h]

	result = *getMemU32Ptr(0x5D4594, 1304308);
	if (*(int*)getMemAt(0x5D4594, 1304308) < 96) {
		if (!*getMemU32Ptr(0x5D4594, 1304316)) {
			*getMemU32Ptr(0x5D4594, 1304316) = sub_44CFC0((CHAR*)getMemAt(0x587000, 163612));
			*getMemU32Ptr(0x5D4594, 1304320) = sub_44CFC0((CHAR*)getMemAt(0x587000, 163632));
			*getMemU32Ptr(0x5D4594, 1304324) = sub_44CFC0((CHAR*)getMemAt(0x587000, 163656));
			*getMemU32Ptr(0x5D4594, 1304348) = sub_44CFC0((CHAR*)getMemAt(0x587000, 163676));
			dword_5d4594_1304328 = sub_44CFC0((CHAR*)getMemAt(0x587000, 163688));
			*getMemU32Ptr(0x5D4594, 1304332) = sub_44CFC0((CHAR*)getMemAt(0x587000, 163696));
			*getMemU32Ptr(0x5D4594, 1304336) = sub_44CFC0((CHAR*)getMemAt(0x587000, 163708));
			*getMemU32Ptr(0x5D4594, 1304340) = sub_44CFC0((CHAR*)getMemAt(0x587000, 163724));
			*getMemU32Ptr(0x5D4594, 1304344) = sub_44CFC0((CHAR*)getMemAt(0x587000, 163732));
		}
		v2 = a1;
		v3 = a1 + 1;
		v4 = *(unsigned __int16*)(a1 + 1) + (*(unsigned __int16*)(a1 + 5) - *(unsigned __int16*)(a1 + 1)) / 2;
		result = *a1 - 125;
		v5 = *(unsigned __int16*)(a1 + 3) + (*(unsigned __int16*)(a1 + 7) - *(unsigned __int16*)(a1 + 3)) / 2;
		switch (*a1) {
		case 0x7Du:
			v20 = *getMemU32Ptr(0x5D4594, 1304332);
			goto LABEL_17;
		case 0x8Cu:
			v20 = *getMemU32Ptr(0x5D4594, 1304316);
			goto LABEL_17;
		case 0x8Du:
			v20 = *getMemU32Ptr(0x5D4594, 1304324);
			goto LABEL_17;
		case 0x8Eu:
			v20 = *getMemU32Ptr(0x5D4594, 1304320);
			goto LABEL_17;
		case 0x8Fu:
			v18 = sub_415FF0(6, 12, "C:\\NoxPost\\src\\Client\\Draw\\drawrays.c", 137);
			v20 = dword_5d4594_1304328;
			if (sub_415FF0(0, 100, "C:\\NoxPost\\src\\Client\\Draw\\drawrays.c", 140) < 50) {
				v15 = sub_415FF0(-20, 20, "C:\\NoxPost\\src\\Client\\Draw\\drawrays.c", 143);
				v10 = sub_415FF0(-20, 20, "C:\\NoxPost\\src\\Client\\Draw\\drawrays.c", 142);
				sub_499490(*(int*)getMemAt(0x5D4594, 1304336), v3, v10, v15, v18, 0);
			}
			goto LABEL_17;
		case 0x90u:
			v16 = sub_415FF0(6, 12, "C:\\NoxPost\\src\\Client\\Draw\\drawrays.c", 101);
			v20 = dword_5d4594_1304328;
			if (sub_415FF0(0, 100, "C:\\NoxPost\\src\\Client\\Draw\\drawrays.c", 104) < 50) {
				v12 = sub_415FF0(-20, 20, "C:\\NoxPost\\src\\Client\\Draw\\drawrays.c", 107);
				v6 = sub_415FF0(-20, 20, "C:\\NoxPost\\src\\Client\\Draw\\drawrays.c", 106);
				sub_499490(*(int*)getMemAt(0x5D4594, 1304344), v3, v6, v12, v16, 0);
			}
			v7 = *(_DWORD*)v3;
			*(_DWORD*)v19 = *(_DWORD*)(v2 + 5);
			*(_DWORD*)&v19[2] = v7;
			if (sub_415FF0(0, 100, "C:\\NoxPost\\src\\Client\\Draw\\drawrays.c", 112) < 50) {
				v13 = sub_415FF0(-20, 20, "C:\\NoxPost\\src\\Client\\Draw\\drawrays.c", 115);
				v8 = sub_415FF0(-20, 20, "C:\\NoxPost\\src\\Client\\Draw\\drawrays.c", 114);
				sub_499490(*(int*)getMemAt(0x5D4594, 1304344), v19, v8, v13, v16, 0);
			}
			goto LABEL_17;
		case 0x91u:
			v17 = sub_415FF0(6, 12, "C:\\NoxPost\\src\\Client\\Draw\\drawrays.c", 123);
			v20 = dword_5d4594_1304328;
			if (sub_415FF0(0, 100, "C:\\NoxPost\\src\\Client\\Draw\\drawrays.c", 126) < 50) {
				v14 = sub_415FF0(-20, 20, "C:\\NoxPost\\src\\Client\\Draw\\drawrays.c", 129);
				v9 = sub_415FF0(-20, 20, "C:\\NoxPost\\src\\Client\\Draw\\drawrays.c", 128);
				sub_499490(*(int*)getMemAt(0x5D4594, 1304340), v3, v9, v14, v17, 0);
			}
		LABEL_17:
			result = sub_45A360_drawable(v20, v4, v5);
			if (result) {
				*(_BYTE*)(result + 432) = 0;
				*(_DWORD*)(result + 437) = *(_DWORD*)v3;
				*(_DWORD*)(result + 441) = *((_DWORD*)v3 + 1);
				v11 = *getMemU32Ptr(0x5D4594, 1304308);
				*getMemU32Ptr(0x5D4594, 4 * *getMemU32Ptr(0x5D4594, 1304308) + 1303540) = result;
				*getMemU32Ptr(0x5D4594, 1304308) = v11 + 1;
			}
			break;
		default:
			return result;
		}
	}
	return result;
}
