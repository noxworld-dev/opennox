#include "mondraw.h"

#include "../../proto.h"

extern int nox_backbuffer_depth;

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

//----- (004BC180) --------------------------------------------------------
int __cdecl nox_thing_monster_draw(int* a1, nox_drawable* dr) {
	int v2;    // esi
	int v3;    // edi
	char v4;   // cl
	int v5;    // eax
	int v6;    // eax
	int v7;    // ecx
	int v8;    // ebx
	int v10;   // edi
	int v11;   // ebp
	int* v12;  // edi
	char* v13; // eax
	int v14;   // eax
	int v15;   // eax
	int v16;   // ebp
	char* v17; // ebx
	int* v18;  // ebx
	int v19;   // ebp
	int v20;   // edi
	int v21;   // [esp+Ch] [ebp-Ch]
	int v22;   // [esp+10h] [ebp-8h]
	int v23;   // [esp+14h] [ebp-4h]

	int a2 = dr;

	v2 = dr;
	v23 = 1;
	v3 = *(_DWORD*)&dr->field_76;
	if (!nox_common_gameFlags_check_40A5C0(0x200000)) {
		v4 = *(_BYTE*)(v2 + 432);
		if (*(_BYTE*)(v2 + 297) != v4) {
			v5 = *(_DWORD*)(v2 + 276);
			if (v5 != 1 && v5 != 3 && v5 != 5) {
				if ((unsigned int)(*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)(v2 + 436)) >=
				    *(int*)&byte_5D4594[2649704] >> 2) {
					*(_DWORD*)(v2 + 436) = *(_DWORD*)&byte_5D4594[2598000];
					*(_BYTE*)(v2 + 432) = *(_BYTE*)(v2 + 297);
				} else {
					*(_BYTE*)(v2 + 297) = v4;
				}
			}
		}
	}
	v6 = *(_DWORD*)&byte_5D4594[1316536];
	if (!*(_DWORD*)&byte_5D4594[1316536]) {
		v6 = sub_44CFC0((CHAR*)&byte_587000[178376]);
		*(_DWORD*)&byte_5D4594[1316536] = v6;
	}
	v7 = 48 * *(_DWORD*)(v2 + 276);
	v8 = v7 + v3 + 4;
	if (!*(_WORD*)(v7 + v3 + 44))
		return 1;
	if (*(_DWORD*)(v2 + 108) != v6)
		goto LABEL_22;
	if (nox_common_gameFlags_check_40A5C0(0x200000)) {
		v10 = 0;
		v11 = 0;
	} else {
		v10 = *(_DWORD*)(v2 + 12) - *(_DWORD*)(*(_DWORD*)&byte_5D4594[2614252] + 12);
		v11 = *(_DWORD*)(v2 + 16) - *(_DWORD*)(*(_DWORD*)&byte_5D4594[2614252] + 16);
	}
	if (*(_DWORD*)&byte_5D4594[2614252] && sub_4356C0(*(int*)&byte_5D4594[2614252], 21)) {
		sub_434600(1);
		sub_433E40(*(int*)&byte_5D4594[2618904]);
		LOBYTE(a2) = nox_backbuffer_depth >= 16 ? -1 : -128;
		LABEL_21:
		nox_client_drawEnableAlpha_434560(1);
		nox_client_drawSetAlpha_434580(dr);
		LABEL_22:
		sub_4BC490(v2);
		v12 = a1;
		v23 = sub_4BC6B0(a1, v2, v8);
		sub_434600(0);
		goto LABEL_24;
	}
	if (v10 * v10 + v11 * v11 < 40000)
		goto LABEL_21;
	v12 = a1;
	LABEL_24:
	if (sub_4951F0(*(_DWORD*)(v2 + 128))) {
		v22 = 0;
		v21 = 0;
		LOBYTE(a2) = 0;
		sub_495180(*(_DWORD*)(v2 + 128), &v22, &v21, &a2);
		sub_4BC080(v12, v2, v22, v21, a2);
	}
	if (!sub_417DA0(4) && (!*(_DWORD*)&byte_5D4594[2614252] || !sub_419130(*(_DWORD*)&byte_5D4594[2614252] + 24)))
		goto LABEL_45;
	if (!nox_common_gameFlags_check_40A5C0(1)) {
		v15 = *(_DWORD*)&byte_5D4594[2614252] + 24;
		LABEL_34:
		if (v15) {
			v16 = 0;
			v17 = sub_418AB0(*(unsigned __int8*)(v15 + 4));
			if (v17 && sub_495A80(*(_DWORD*)(v2 + 128)))
				v16 = 1;
			if ((!nox_common_gameFlags_check_40A5C0(4096) || !(*(_BYTE*)(v2 + 112) & 2) ||
			     !(*(_BYTE*)(v2 + 116) & 8)) &&
			    v16) {
				v18 = (int*)sub_418D50((int)v17);
				v19 = *v12 + *(_DWORD*)(v2 + 12) - v12[4];
				v20 = *(_DWORD*)(v2 + 16) + v12[1] - *(__int16*)(v2 + 104) - a1[5] -
				      2 * nox_float2int(*(float*)(v2 + 100));
				if (v18)
					nox_client_drawSetColor_434460(*v18);
				sub_4B0BC0(v19, v20, 3);
			}
		}
		goto LABEL_45;
	}
	v13 = sub_417090(31);
	if (v13) {
		v14 = *((_DWORD*)v13 + 514);
		if (v14) {
			v15 = v14 + 48;
			goto LABEL_34;
		}
	}
	LABEL_45:
	nox_client_drawEnableAlpha_434560(0);
	return v23;
}

//----- (0044BB80) --------------------------------------------------------
bool __cdecl nox_things_monster_draw_parse(nox_thing* obj, nox_memfile* f, _BYTE* a3) {
	_DWORD* v2;          // ebx
	int v4;              // ecx
	unsigned __int8 v6;  // cl
	unsigned __int8* v8; // eax
	int v9;              // edi

	v2 = nox_calloc(1u, 0x304u);
	*v2 = 772;
	while (1) {
		v4 = nox_memfile_read_u32(f);
		if (v4 == 1162757152)
			break;
		v6 = nox_memfile_read_u8(f);
		if (v6 < 0x10u) {
			unsigned __int8* v7 = f->cur;
			v8 = &v7[*v7 + 1];
			f->cur = v8;
			f->cur += *v8 + 1;
			v9 = (int)&v2[12 * v6 + 1];
			if (sub_44B8B0(v9, f)) {
				if (sub_44BC50(v9, f))
					continue;
			}
		}
		return 0;
	}
	obj->draw_func = nox_thing_monster_draw;
	obj->field_5c = v2;
	return 1;
}
