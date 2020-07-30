#include "partscrn.h"

#include "../../proto.h"

//----- (00489700) --------------------------------------------------------
int sub_489700(void* a1p, nox_screenParticle* a2p) {
	int a1 = a1p;
	int a2 = a2p;
	int v2;             // ecx
	char v3;            // al
	char v4;            // al
	unsigned __int8 v5; // al
	char v6;            // al
	int v7;             // eax
	int v8;             // eax
	int v10;            // [esp-20h] [ebp-30h]
	char v11;           // [esp-10h] [ebp-20h]
	char v12;           // [esp-Ch] [ebp-1Ch]
	int2 xLeft;         // [esp+8h] [ebp-8h]

	v2 = *(int*)(a2 + 28) >> 16;
	xLeft.field_0 = *(int*)(a2 + 24) >> 16;
	xLeft.field_4 = v2;
	if (xLeft.field_0 <= 0 || v2 <= 0 || xLeft.field_0 >= *(int*)(a1 + 32) || v2 >= *(int*)(a1 + 36))
		goto LABEL_19;
	sub_4B6720(&xLeft, *(_DWORD*)(a2 + 8), *(unsigned __int8*)(a2 + 40), *(_BYTE*)(a2 + 40));
	nox_client_drawSetColor_434460(*(_DWORD*)(a2 + 12));
	sub_499B70(xLeft.field_0, xLeft.field_4, *(unsigned __int8*)(a2 + 40) >> 1);
	v3 = *(_BYTE*)(a2 + 41);
	*(_DWORD*)(a2 + 20) += *(_DWORD*)(a2 + 36);
	if (!v3)
		goto LABEL_12;
	v4 = v3 - 1;
	*(_BYTE*)(a2 + 41) = v4;
	if (v4)
		goto LABEL_12;
	if (*(_BYTE*)(a2 + 42) == 1) {
		v5 = *(_BYTE*)(a2 + 40) + 1;
		*(_BYTE*)(a2 + 40) = v5;
		if (v5 >= 4u)
			*(_BYTE*)(a2 + 42) = 2;
		goto LABEL_11;
	}
	v6 = *(_BYTE*)(a2 + 40) - 1;
	*(_BYTE*)(a2 + 40) = v6;
	if (!v6) {
	LABEL_19:
		sub_431700((_QWORD*)a2);
		return 0;
	}
LABEL_11:
	*(_BYTE*)(a2 + 41) = *(_BYTE*)(a2 + 43);
LABEL_12:
	if (*(_BYTE*)(a2 + 32) == 1 && sub_415FF0(0, 10, "C:\\NoxPost\\src\\client\\Draw\\PartScrn.c", 105) >= 8) {
		v12 = sub_415FF0(3, 5, "C:\\NoxPost\\src\\client\\Draw\\PartScrn.c", 115);
		v11 = sub_415FF0(2, 3, "C:\\NoxPost\\src\\client\\Draw\\PartScrn.c", 114);
		v10 = xLeft.field_4;
		v7 = sub_415FF0(-2, 2, "C:\\NoxPost\\src\\client\\Draw\\PartScrn.c", 109);
		nox_client_newScreenParticle_431540(*(_DWORD*)(a2 + 4), xLeft.field_0 + v7, v10, 0, 0, 1, v11, v12, 2, 2);
	}
	v8 = *(_DWORD*)(a2 + 28);
	*(_DWORD*)(a2 + 24) += *(_DWORD*)(a2 + 16);
	*(_DWORD*)(a2 + 28) = *(_DWORD*)(a2 + 20) + v8;
	return 1;
}
