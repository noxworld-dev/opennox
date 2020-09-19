#include "drawwin.h"

#include "../../proto.h"
#include "fx.h"

//----- (004746C0) --------------------------------------------------------
int __cdecl sub_4746C0(_DWORD* a1, int a2) {
	int v2;     // edi
	int v3;     // eax
	int v4;     // eax
	int v5;     // edi
	int v6;     // eax
	int v7;     // eax
	char v8;    // al
	int result; // eax
	int v10;    // [esp-24h] [ebp-34h]
	int v11;    // [esp-24h] [ebp-34h]
	int v12;    // [esp-24h] [ebp-34h]
	int v13;    // [esp-24h] [ebp-34h]
	char v14;   // [esp-1Ch] [ebp-2Ch]
	char v15;   // [esp-1Ch] [ebp-2Ch]
	char v16;   // [esp-1Ch] [ebp-2Ch]
	char v17;   // [esp-1Ch] [ebp-2Ch]
	char v18;   // [esp-18h] [ebp-28h]
	char v19;   // [esp-18h] [ebp-28h]
	char v20;   // [esp-18h] [ebp-28h]
	char v21;   // [esp-18h] [ebp-28h]
	int v22;    // [esp-8h] [ebp-18h]
	int v23;    // [esp-8h] [ebp-18h]
	int v24;    // [esp-8h] [ebp-18h]
	int v25;    // [esp-8h] [ebp-18h]
	int2 v26;   // [esp+8h] [ebp-8h]

	if (sub_4356C0(a2, 0) && !sub_474B40(a2))
		goto LABEL_37;
	if (sub_4356C0(a2, 14)) {
		sub_4739E0(a1, (int2*)(a2 + 12), &v26);
		sub_4B6720(&v26, *getMemIntPtr(0x5D4594, 2650684), 30, 31);
	}
	if (sub_4356C0(a2, 9) && !sub_413A50()) {
		if (!*getMemU32Ptr(0x5D4594, 1096524)) {
			*getMemU32Ptr(0x5D4594, 1096524) = sub_44CFC0((CHAR*)getMemAt(0x587000, 149612));
			*getMemU32Ptr(0x5D4594, 1096528) = sub_44CFC0((CHAR*)getMemAt(0x587000, 149632));
		}
		if (*(_DWORD*)(a2 + 12) != *(_DWORD*)(a2 + 32) || *(_DWORD*)(a2 + 16) != *(_DWORD*)(a2 + 36))
			v2 = 2;
		else
			v2 = 0;
		if (v2 > 0) {
			do {
				v22 = sub_415FF0(3, 5, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1055);
				v18 = sub_415FF0(3, 6, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1051);
				v14 = sub_415FF0(2, 4, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1050);
				v10 = *(_DWORD*)(a2 + 16) + *(__int16*)(a2 + 104) +
					  sub_415FF0(-10, 10, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1048);
				v3 = sub_415FF0(-10, 10, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1047);
				sub_499F60(*getMemIntPtr(0x5D4594, 1096524), *(_DWORD*)(a2 + 12) + v3, v10, 1, v14, v18, 0, 0, 0, v22);
				v23 = sub_415FF0(3, 5, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1066);
				v19 = sub_415FF0(3, 6, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1062);
				v15 = sub_415FF0(2, 4, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1061);
				v11 = *(_DWORD*)(a2 + 16) + *(__int16*)(a2 + 104) +
					  sub_415FF0(-10, 10, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1059);
				v4 = sub_415FF0(-10, 10, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1058);
				sub_499F60(*getMemIntPtr(0x5D4594, 1096528), *(_DWORD*)(a2 + 12) + v4, v11, 1, v15, v19, 0, 0, 0, v23);
				--v2;
			} while (v2);
		}
	}
	if (sub_4356C0(a2, 8) && !sub_413A50()) {
		if (!*getMemU32Ptr(0x5D4594, 1096532)) {
			*getMemU32Ptr(0x5D4594, 1096532) = sub_44CFC0((CHAR*)getMemAt(0x587000, 150056));
			*getMemU32Ptr(0x5D4594, 1096536) = sub_44CFC0((CHAR*)getMemAt(0x587000, 150076));
		}
		if (*(_DWORD*)(a2 + 12) != *(_DWORD*)(a2 + 32) || (v5 = 1, *(_DWORD*)(a2 + 16) != *(_DWORD*)(a2 + 36)))
			v5 = 2;
		do {
			v24 = sub_415FF0(3, 5, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1108);
			v20 = sub_415FF0(3, 6, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1104);
			v16 = sub_415FF0(2, 4, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1103);
			v12 = *(_DWORD*)(a2 + 16) + *(__int16*)(a2 + 104) +
				  sub_415FF0(-10, 10, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1101);
			v6 = sub_415FF0(-10, 10, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1100);
			sub_499F60(*getMemIntPtr(0x5D4594, 1096532), *(_DWORD*)(a2 + 12) + v6, v12, 1, v16, v20, 0, 0, 0, v24);
			v25 = sub_415FF0(3, 5, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1119);
			v21 = sub_415FF0(3, 6, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1115);
			v17 = sub_415FF0(2, 4, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1114);
			v13 = *(_DWORD*)(a2 + 16) + *(__int16*)(a2 + 104) +
				  sub_415FF0(-10, 10, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1112);
			v7 = sub_415FF0(-10, 10, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1111);
			sub_499F60(*getMemIntPtr(0x5D4594, 1096536), *(_DWORD*)(a2 + 12) + v7, v13, 1, v17, v21, 0, 0, 0, v25);
			--v5;
		} while (v5);
	}
	if (sub_4356C0(a2, 17))
		sub_474BE0(a1, (int*)(a2 + 12), a2, 0, 0, *getMemIntPtr(0x5D4594, 2650644), *getMemIntPtr(0x5D4594, 2589776), 1);
	if (sub_4356C0(a2, 18))
		sub_474BE0(a1, (int*)(a2 + 12), a2, 85, 1, *getMemIntPtr(0x5D4594, 2618904), *getMemIntPtr(0x5D4594, 2614268), 1);
	if (sub_4356C0(a2, 20))
		sub_474BE0(a1, (int*)(a2 + 12), a2, 170, 2, *getMemIntPtr(0x5D4594, 2650684), *getMemIntPtr(0x5D4594, 2523948), 1);
	if (!sub_4356C0(a2, 27) || (v8 = *(_BYTE*)(a2 + 297)) != 0 && v8 != 1 && v8 != 2)
	LABEL_37:
		result = 0;
	else
		result = sub_499810((int)a1, a2);
	return result;
}

//----- (00474E60) --------------------------------------------------------
int __cdecl sub_474E60(_DWORD* a1, int a2) {
	int v2;      // esi
	int v3;      // eax
	_DWORD* v4;  // ebp
	int v5;      // edx
	char v6;     // al
	int v7;      // ecx
	int v8;      // eax
	int v9;      // edx
	int v10;     // eax
	int v11;     // ebx
	int v12;     // ebp
	int v13;     // eax
	int v14;     // eax
	int v15;     // eax
	int v16;     // ebx
	int v17;     // edi
	int v18;     // eax
	int v19;     // eax
	int v20;     // eax
	int v21;     // eax
	int v22;     // eax
	int v23;     // eax
	int v24;     // edx
	int v25;     // ebx
	int v26;     // eax
	char v27;    // al
	int result;  // eax
	int v29;     // [esp-20h] [ebp-44h]
	int v30;     // [esp-1Ch] [ebp-40h]
	int v31;     // [esp-1Ch] [ebp-40h]
	__int16 v32; // [esp-18h] [ebp-3Ch]
	__int16 v33; // [esp-18h] [ebp-3Ch]
	char v34;    // [esp-14h] [ebp-38h]
	char v35;    // [esp-14h] [ebp-38h]
	char v36;    // [esp-10h] [ebp-34h]
	char v37;    // [esp-10h] [ebp-34h]
	int v38;     // [esp-8h] [ebp-2Ch]
	float v39;   // [esp+0h] [ebp-24h]
	int v40;     // [esp+0h] [ebp-24h]
	int v41;     // [esp+0h] [ebp-24h]
	int2 xLeft;  // [esp+14h] [ebp-10h]
	int2 a3;     // [esp+1Ch] [ebp-8h]
	int v44;     // [esp+2Ch] [ebp+8h]

	v2 = a2;
	if (sub_4356C0(a2, 0) && !sub_474B40(a2))
		goto LABEL_54;
	if (sub_4356C0(a2, 22)) {
		v3 = *getMemU32Ptr(0x5D4594, 1096540);
		if (!*getMemU32Ptr(0x5D4594, 1096540)) {
			v3 = sub_44CFC0((CHAR*)getMemAt(0x587000, 150500));
			*getMemU32Ptr(0x5D4594, 1096540) = v3;
		}
		sub_499710(*(_DWORD*)(a2 + 12), *(_DWORD*)(a2 + 16), *(_WORD*)(a2 + 104), v3);
	}
	if (sub_4356C0(a2, 3) || sub_4356C0(a2, 5) || sub_4356C0(a2, 29) || sub_4356C0(a2, 28)) {
		v4 = a1;
		sub_4739E0(a1, (int2*)(a2 + 12), &xLeft);
		v5 = 5 - *(__int16*)(a2 + 106) - *(__int16*)(a2 + 104) - nox_float2int(*(float*)(a2 + 100));
		v6 = *(_BYTE*)(a2 + 112);
		v7 = v5 + xLeft.field_4;
		xLeft.field_4 += v5;
		if (v6 & 4 && *(_DWORD*)(a2 + 276) == 6) {
			v8 = 8 * *(unsigned __int8*)(a2 + 297);
			v9 = *getMemU32Ptr(0x587000, v8 + 149432);
			v10 = *getMemU32Ptr(0x587000, v8 + 149436);
			xLeft.field_0 += v9;
			xLeft.field_4 = v10 + v7;
		}
		if (sub_4356C0(a2, 29)) {
			sub_434600(1);
			sub_433E40(*getMemIntPtr(0x5D4594, 2650684));
		}
		nox_video_drawAnimatedImageOrCursorAt_4BE6D0(*getMemIntPtr(0x5D4594, 1096456), xLeft.field_0 - 64,
													 xLeft.field_4 - 64);
		sub_434600(0);
	} else {
		v4 = a1;
	}
	if (sub_4356C0(a2, 4) && !sub_413A50()) {
		v11 = nox_float2int(*(float*)(a2 + 48));
		v39 = *(float*)(a2 + 100) * 0.5;
		v44 = nox_float2int(v39);
		if (!*getMemU32Ptr(0x5D4594, 1096544))
			*getMemU32Ptr(0x5D4594, 1096544) = sub_44CFC0((CHAR*)getMemAt(0x587000, 150512));
		v12 = 2;
		do {
			v40 = sub_415FF0(3, 5, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1307);
			v36 = sub_415FF0(3, 6, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1303);
			v34 = sub_415FF0(1, 2, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1302);
			v32 = sub_415FF0(0, v44, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1301);
			v30 = *(_DWORD*)(v2 + 16) + sub_415FF0(-v11, v11, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1300);
			v13 = sub_415FF0(-v11, v11, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1299);
			sub_499F60(*getMemIntPtr(0x5D4594, 1096544), *(_DWORD*)(v2 + 12) + v13, v30, v32, v34, v36, -5, 0, 0, v40);
			--v12;
		} while (v12);
		v4 = a1;
	}
	if (sub_4356C0(v2, 21) && !sub_413A50()) {
		if (!*getMemU32Ptr(0x5D4594, 1096548))
			*getMemU32Ptr(0x5D4594, 1096548) = sub_44CFC0((CHAR*)getMemAt(0x587000, 150776));
		v41 = sub_415FF0(2, 3, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1335);
		v37 = sub_415FF0(3, 6, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1331);
		v35 = sub_415FF0(2, 4, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1330);
		v29 = nox_float2int(*(float*)(v2 + 100)) + 12;
		v14 = nox_float2int(*(float*)(v2 + 100));
		v33 = sub_415FF0(v14 + 8, v29, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1329);
		v31 = *(_DWORD*)(v2 + 16) + sub_415FF0(-10, 10, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1327);
		v15 = sub_415FF0(-6, 6, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1326);
		sub_499F60(*getMemIntPtr(0x5D4594, 1096548), *(_DWORD*)(v2 + 12) + v15, v31, v33, v35, v37, 1, 0, 0, v41);
	}
	if (sub_4356C0(v2, 13) && !sub_413A50()) {
		if (!*getMemU32Ptr(0x5D4594, 1096552)) {
			*getMemU32Ptr(0x5D4594, 1096452) = sub_4344A0(255, 0, 255);
			*getMemU32Ptr(0x5D4594, 1096436) = sub_4344A0(255, 180, 255);
			*getMemU32Ptr(0x5D4594, 1096552) = 1;
		}
		sub_4739E0(v4, (int2*)(v2 + 12), &a3);
		v16 = 10;
		do {
			v17 = sub_415FF0(1, 2, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1366);
			v38 = nox_float2int(*(float*)(v2 + 48));
			v18 = nox_float2int(*(float*)(v2 + 48));
			v19 = sub_415FF0(-v18, v38, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1369);
			xLeft.field_0 = a3.field_0 + v19;
			v20 = nox_float2int(*(float*)(v2 + 100));
			v21 = sub_415FF0(-10 - v20, 0, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1370);
			xLeft.field_4 = v21 + a3.field_4 + *(__int16*)(v2 + 104);
			v22 = sub_415FF0(3, 4, "C:\\NoxPost\\src\\Client\\Draw\\Drawwin.c", 1372);
			sub_4B6720(&xLeft, *getMemIntPtr(0x5D4594, 1096452), v17 + v22, v17 + 2);
			nox_client_drawSetColor_434460(*getMemIntPtr(0x5D4594, 1096436));
			sub_499B70(xLeft.field_0, xLeft.field_4, v17);
			--v16;
		} while (v16);
	}
	if (sub_4356C0(v2, 17))
		sub_474BE0(v4, (int*)(v2 + 12), v2, 0, 0, *getMemIntPtr(0x5D4594, 2650644), *getMemIntPtr(0x5D4594, 2589776), 0);
	if (sub_4356C0(v2, 18))
		sub_474BE0(v4, (int*)(v2 + 12), v2, 85, 1, *getMemIntPtr(0x5D4594, 2618904), *getMemIntPtr(0x5D4594, 2614268), 0);
	if (sub_4356C0(v2, 20))
		sub_474BE0(v4, (int*)(v2 + 12), v2, 170, 2, *getMemIntPtr(0x5D4594, 2650684), *getMemIntPtr(0x5D4594, 2523948), 0);
	if (sub_4356C0(v2, 26)) {
		sub_4739E0(v4, (int2*)(v2 + 12), &xLeft);
		v23 = *(_DWORD*)(v2 + 276);
		v24 = -90 - *(__int16*)(v2 + 104);
		v25 = xLeft.field_0 - 64;
		xLeft.field_0 -= 64;
		xLeft.field_4 += v24;
		if (v23 == 6) {
			v26 = 8 * *(unsigned __int8*)(v2 + 297);
			xLeft.field_0 = *getMemU32Ptr(0x587000, v26 + 149504) + v25;
			xLeft.field_4 += *getMemU32Ptr(0x587000, v26 + 149508);
		}
		nox_client_drawEnableAlpha_434560(1);
		nox_client_drawSetAlpha_434580(0x80u);
		nox_video_drawAnimatedImageOrCursorAt_4BE6D0(*getMemIntPtr(0x5D4594, 1096460), xLeft.field_0, xLeft.field_4);
		nox_client_drawEnableAlpha_434560(0);
	}
	if (sub_4356C0(v2, 27) && (v27 = *(_BYTE*)(v2 + 297)) != 0 && v27 != 1 && v27 != 2)
		result = sub_499810((int)v4, v2);
	else
	LABEL_54:
		result = 0;
	return result;
}
