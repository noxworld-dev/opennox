#include "animdraw.h"
#include "../../proto.h"

//----- (004BBD60) --------------------------------------------------------
int __cdecl nox_thing_animate_draw(unsigned int* a1, struct nox_drawable* dr) {
	int v2;     // edi
	int v3;     // esi
	int v4;     // ecx
	int result; // eax
	int v6;     // ebx
	int v7;     // eax

	v2 = dr->field_76;
	switch (*(unsigned int*)(v2 + 12)) {
	case 0:
		v3 = (*(unsigned int*)&byte_5D4594[2598000] - dr->field_79) / ((unsigned int)*(unsigned __int8*)(v2 + 9) + 1);
		v7 = *(unsigned __int8*)(v2 + 8);
		if (v3 >= v7)
			v3 = v7 - 1;
		goto LABEL_12;
	case 1:
		v3 = (*(unsigned int*)&byte_5D4594[2598000] - dr->field_79) / ((unsigned int)*(unsigned __int8*)(v2 + 9) + 1);
		if (v3 < *(unsigned __int8*)(v2 + 8))
			goto LABEL_12;
		sub_45A4E0_drawable(dr);
		return 0;
	case 2:
		if (dr->flags & 0x1000000)
			goto LABEL_9;
		if (!(dr->field_28 & 0x10000000))
			goto LABEL_8;
		if (nox_common_gameFlags_check_40A5C0(32)) {
		LABEL_9:
			v3 = (*(unsigned int*)&byte_5D4594[2598000] + dr->field_32) /
				 ((unsigned int)*(unsigned __int8*)(v2 + 9) + 1);
			goto LABEL_10;
		}
		if (dr->field_28 & 0x10000000)
			goto LABEL_14;
	LABEL_8:
		v3 = 0;
		goto LABEL_12;
	case 3:
		v6 = 2 * *(unsigned __int8*)(v2 + 8);
		nox_client_drawEnableAlpha_434560(1);
		v3 = (*(unsigned int*)&byte_5D4594[2598000] - dr->field_79) / ((unsigned int)*(unsigned __int8*)(v2 + 9) + 1);
		if (v3 < v6) {
			nox_client_drawSetAlpha_434580(-56 - 200 * v3 / v6);
		LABEL_10:
			v4 = *(unsigned __int8*)(v2 + 8);
			if (v3 >= v4)
				v3 %= v4;
		LABEL_12:
			sub_4C4770_draw(a1, dr, *(unsigned int*)(*(unsigned int*)(v2 + 4) + 4 * v3));
			if (*(unsigned int*)(v2 + 12) == 3)
				nox_client_drawEnableAlpha_434560(0);
		LABEL_14:
			result = 1;
		} else {
			sub_45A4E0_drawable(dr);
			result = 0;
		}
		return result;
	case 4:
		v3 = sub_415FF0(0, *(unsigned __int8*)(v2 + 8) - 1, "C:\\NoxPost\\src\\Client\\Draw\\animdraw.c", 24);
		goto LABEL_12;
	case 5:
		v3 = dr->field_77;
		goto LABEL_12;
	default:
		goto LABEL_14;
	}
}

//----- (004BBF10) --------------------------------------------------------
int __cdecl nox_thing_animate_state_draw(_DWORD* a1, nox_drawable* dr) {
	int v2;     // eax
	int v3;     // edx
	int v4;     // eax
	int v5;     // eax
	int result; // eax

	v2 = dr->field_70;
	v3 = dr->field_76;
	if (v2 & 2) {
		dr->field_79 = *(_DWORD*)&byte_5D4594[2598000];
		v4 = 0;
	} else if (v2 & 4) {
		v4 = 1;
	} else {
		v4 = ((unsigned __int8)v2 >> 2) & 2;
	}
	v5 = 48 * v4 + v3 + 4;
	if (*(_DWORD*)(v5 + 44) == 2)
		dr->field_79 = *(_DWORD*)&byte_5D4594[2598000];
	if (*(_WORD*)(v5 + 40))
		result = sub_4BC6B0(a1, dr, v5);
	else
		result = 1;
	return result;
}

//----- (0044B390) --------------------------------------------------------
bool __cdecl nox_things_animate_draw_parse(nox_thing* obj, nox_memfile* f, char* attr_value) {
	_BYTE* a3 = attr_value;
	_DWORD* v3;          // eax
	_DWORD* v5;          // edi
	_BYTE* v6;           // ebx
	char v8;             // cl
	char v10;            // cl
	int result;          // eax
	int v13;             // ebp
	int v15;             // ecx
	char v17;            // cl
	const char* v19;     // [esp+14h] [ebp-4h]
	unsigned __int8 v20; // [esp+20h] [ebp+8h]
	unsigned __int8 v21; // [esp+20h] [ebp+8h]
	int v22;             // [esp+24h] [ebp+Ch]

	v3 = nox_calloc(1u, 0x10u);
	v5 = v3;
	v6 = a3;
	*v3 = 16;
	v8 = nox_memfile_read_u8(f);
	*((_BYTE*)v5 + 8) = v8;
	v10 = nox_memfile_read_u8(f);
	*((_BYTE*)v5 + 9) = v10;
	v20 = nox_memfile_read_u8(f);
	nox_memfile_read(a3, 1u, v20, f);
	a3[v20] = 0;
	v5[3] = sub_44B4C0(a3);
	result = (int)nox_malloc(4 * *((unsigned __int8*)v5 + 8));
	v5[1] = result;
	if (!result)
		return 0;

	v13 = 0;
	v22 = 0;
	if (*((_BYTE*)v5 + 8)) {
		do {
			v15 = nox_memfile_read_u32(f);
			*v6 = byte_5D4594[830832];
			if (v15 == -1) {
				v17 = nox_memfile_read_u8(f);
				LOBYTE(v19) = v17;
				v21 = nox_memfile_read_u8(f);
				nox_memfile_read(v6, 1u, v21, f);
				v15 = -1;
				v6[v21] = 0;
				v13 = v22;
			}
			*(_DWORD*)(v5[1] + 4 * v13++) = sub_42FAA0(v15, v19, v6);
			v22 = v13;
		} while (v13 < *((unsigned __int8*)v5 + 8));
	}
	obj->field_5c = v5;
	obj->draw_func = &nox_thing_animate_draw;
	return 1;
}

//----- (0044BD90) --------------------------------------------------------
bool __cdecl nox_things_animate_state_draw_parse(nox_thing* obj, nox_memfile* f, char* attr_value) {
	_DWORD* v2;          // ebp
	int v4;              // ecx
	int v6;              // ecx
	unsigned __int8* v8; // eax
	int v9;              // edi
	unsigned __int8 v11; // [esp+Ch] [ebp-4h]

	v2 = nox_calloc(1u, 0x94u);
	*v2 = 148;
	while (1) {
		v4 = nox_memfile_read_u32(f);
		if (v4 == 0x454E4420) // "END "
			break;
		v6 = nox_memfile_read_u32(f);
		if (v6 & 0xE) {
			unsigned __int8* v7 = f->cur;
			v8 = &v7[*v7 + 1];
			f->cur = v8;
			f->cur += *v8 + 1;
			if (v6 & 2) {
				v11 = 0;
			} else if (v6 & 4) {
				v11 = 1;
			} else if (v6 & 8) {
				v11 = 2;
			}
			v9 = (int)&v2[12 * v11 + 1];
			if (sub_44B8B0(v9, f)) {
				if (sub_44BE90(v9, f))
					continue;
			}
		}
		return 0;
	}
	obj->field_54 = 2;
	obj->draw_func = &nox_thing_animate_state_draw;
	obj->field_5c = v2;
	return 1;
}
