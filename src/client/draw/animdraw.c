#include "animdraw.h"
#include "parse/parse.h"
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
		v3 = (*getMemUintPtr(0x5D4594, 2598000) - dr->field_79) / ((unsigned int)*(unsigned __int8*)(v2 + 9) + 1);
		v7 = *(unsigned __int8*)(v2 + 8);
		if (v3 >= v7)
			v3 = v7 - 1;
		goto LABEL_12;
	case 1:
		v3 = (*getMemUintPtr(0x5D4594, 2598000) - dr->field_79) / ((unsigned int)*(unsigned __int8*)(v2 + 9) + 1);
		if (v3 < *(unsigned __int8*)(v2 + 8))
			goto LABEL_12;
		nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr);
		return 0;
	case 2:
		if (dr->flags & 0x1000000)
			goto LABEL_9;
		if (!(dr->field_28 & 0x10000000))
			goto LABEL_8;
		if (nox_common_gameFlags_check_40A5C0(32)) {
		LABEL_9:
			v3 = (*getMemUintPtr(0x5D4594, 2598000) + dr->field_32) /
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
		v3 = (*getMemUintPtr(0x5D4594, 2598000) - dr->field_79) / ((unsigned int)*(unsigned __int8*)(v2 + 9) + 1);
		if (v3 < v6) {
			nox_client_drawSetAlpha_434580(-56 - 200 * v3 / v6);
		LABEL_10:
			v4 = *(unsigned __int8*)(v2 + 8);
			if (v3 >= v4)
				v3 %= v4;
		LABEL_12:
			nox_xxx_drawObject_4C4770_draw(a1, dr, *(unsigned int*)(*(unsigned int*)(v2 + 4) + 4 * v3));
			if (*(unsigned int*)(v2 + 12) == 3)
				nox_client_drawEnableAlpha_434560(0);
		LABEL_14:
			result = 1;
		} else {
			nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr);
			result = 0;
		}
		return result;
	case 4:
		v3 = nox_xxx_randGetMinMax_415FF0(0, *(unsigned __int8*)(v2 + 8) - 1, "C:\\NoxPost\\src\\Client\\Draw\\animdraw.c", 24);
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
		dr->field_79 = *getMemU32Ptr(0x5D4594, 2598000);
		v4 = 0;
	} else if (v2 & 4) {
		v4 = 1;
	} else {
		v4 = ((unsigned __int8)v2 >> 2) & 2;
	}
	v5 = 48 * v4 + v3 + 4;
	if (*(_DWORD*)(v5 + 44) == 2)
		dr->field_79 = *getMemU32Ptr(0x5D4594, 2598000);
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

	v3 = calloc(1u, 0x10u);
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
	v5[3] = get_animation_kind_id_44B4C0(a3);
	result = (int)malloc(4 * *((unsigned __int8*)v5 + 8));
	v5[1] = result;
	if (!result)
		return 0;

	v13 = 0;
	v22 = 0;
	if (*((_BYTE*)v5 + 8)) {
		do {
			v15 = nox_memfile_read_u32(f);
			*v6 = getMemByte(0x5D4594, 830832);
			if (v15 == -1) {
				v17 = nox_memfile_read_u8(f);
				LOBYTE(v19) = v17;
				v21 = nox_memfile_read_u8(f);
				nox_memfile_read(v6, 1u, v21, f);
				v15 = -1;
				v6[v21] = 0;
				v13 = v22;
			}
			*(_DWORD*)(v5[1] + 4 * v13++) = nox_xxx_readImgMB_42FAA0(v15, v19, v6);
			v22 = v13;
		} while (v13 < *((unsigned __int8*)v5 + 8));
	}
	obj->field_5c = v5;
	obj->draw_func = &nox_thing_animate_draw;
	return 1;
}

//----- (0044BE90) --------------------------------------------------------
int __cdecl sub_44BE90(int a1, nox_memfile* f) {
	int a2 = f;
	int v2;              // esi
	int result;          // eax
	int v4;              // ebx
	int* v5;             // eax
	int v6;              // ebp
	_BYTE* v7;           // eax
	char v8;             // dl
	unsigned __int8* v9; // eax
	int v10;             // esi
	const char* v11;     // [esp+4h] [ebp-88h]
	char v12[128];       // [esp+Ch] [ebp-80h]

	v2 = a1;
	result = (int)malloc(4 * *(__int16*)(a1 + 40));
	*(_DWORD*)(a1 + 4) = result;
	if (result) {
		v4 = 0;
		if (*(_WORD*)(a1 + 40) > 0) {
			do {
				v5 = *(int**)(a2 + 8);
				v6 = *v5;
				v7 = v5 + 1;
				*(_DWORD*)(a2 + 8) = v7;
				v12[0] = getMemByte(0x5D4594, 830848);
				if (v6 == -1) {
					v8 = *v7;
					v9 = v7 + 1;
					*(_DWORD*)(a2 + 8) = v9;
					LOBYTE(v11) = v8;
					v10 = *v9;
					*(_DWORD*)(a2 + 8) = v9 + 1;
					nox_memfile_read(v12, 1u, v10, a2);
					v12[v10] = 0;
					v2 = a1;
				}
				*(_DWORD*)(*(_DWORD*)(v2 + 4) + 4 * v4++) = nox_xxx_readImgMB_42FAA0(v6, v11, v12);
			} while (v4 < *(__int16*)(v2 + 40));
		}
		result = 1;
	}
	return result;
}

//----- (0044BD90) --------------------------------------------------------
bool __cdecl nox_things_animate_state_draw_parse(nox_thing* obj, nox_memfile* f, char* attr_value) {
	const size_t data_sz = 0x94u;
	_DWORD* draw_cb_data = calloc(1u, data_sz);
	draw_cb_data[0] = data_sz;
	while (1) {
		int cmd = nox_memfile_read_u32(f);
		// "END "
		if (cmd == 0x454E4420) {
			break;
		}

		int params = nox_memfile_read_u32(f);
		if (!(params & 0xE)) {
			return 0;
		}

		// TODO: After cleanup: understand significance of these two strings.
		// The first one is always [len=4, data='NULL'], the second is always [len=1, data='']

		unsigned __int8 n;
		n = nox_memfile_read_u8(f);
		nox_memfile_skip(f, n);
		n = nox_memfile_read_u8(f);
		nox_memfile_skip(f, n);

		unsigned __int8 offset_idx;
		if (params & 2) {
			offset_idx = 0;
		} else if (params & 4) {
			offset_idx = 1;
		} else if (params & 8) {
			offset_idx = 2;
		}

		int v9 = (int)&draw_cb_data[12 * offset_idx + 1];

		if (!nox_xxx_loadVectorAnimated_44B8B0(v9, f)) {
			return 0;
		}

		if (!sub_44BE90(v9, f)) {
			return 0;
		}
	}

	obj->field_54 = 2;
	obj->draw_func = &nox_thing_animate_state_draw;
	obj->field_5c = draw_cb_data;
	return 1;
}
