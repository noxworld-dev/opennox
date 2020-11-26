#include "canidraw.h"
#include "parse/parse.h"
#include "../../proto.h"

//----- (004BC930) --------------------------------------------------------
int __cdecl nox_thing_cond_animate_draw(unsigned int* a1, struct nox_drawable* dr) {
	int v2;         // eax
	int v3;         // edi
	int v4;         // ecx
	int v5;         // esi
	int v6;         // edx
	int v7;         // edx
	int v8;         // edx
	signed int v10; // eax

	v2 = dr->field_76;
	if (dr->flags & 0x1000000) {
		v3 = *(unsigned int*)(v2 + 4);
		v4 = *(unsigned __int8*)(v2 + 24);
		v5 = *(unsigned __int8*)(v2 + 29);
		v6 = *(unsigned int*)(v2 + 36);
	} else {
		v3 = *(unsigned int*)(v2 + 8);
		v4 = *(unsigned __int8*)(v2 + 25);
		v5 = *(unsigned __int8*)(v2 + 30);
		v6 = *(unsigned int*)(v2 + 40);
	}
	v7 = v6 - 2;
	if (v7) {
		v8 = v7 - 2;
		if (v8) {
			if (v8 != 1)
				return 0;
			v10 = dr->field_77;
		} else {
			v10 = nox_xxx_randGetMinMax_415FF0(0, v4, "C:\\NoxPost\\src\\client\\Draw\\CAniDraw.c", 57);
		}
	} else {
		v10 = (*getMemUintPtr(0x5D4594, 2598000) + dr->field_32) / (unsigned int)(v5 + 1);
		if (v10 >= v4)
			v10 %= v4;
	}
	nox_xxx_drawObject_4C4770_draw(a1, dr, *(unsigned int*)(v3 + 4 * v10));
	return 1;
}

//----- (0044B560) --------------------------------------------------------
bool __cdecl nox_things_cond_animate_draw_parse(nox_thing* obj, nox_memfile* f, char* attr_value) {
	_DWORD* v3;           // eax
	_BYTE* v6;            // edi
	unsigned __int8* v7;  // ebp
	unsigned __int8 v9;   // cl
	unsigned __int8 v11;  // cl
	_DWORD* v13;          // ebx
	void* v14;            // eax
	int v16;              // ecx
	char v18;             // cl
	_DWORD* v20;          // [esp+10h] [ebp-18h]
	const char* v21;      // [esp+18h] [ebp-10h]
	int v22;              // [esp+1Ch] [ebp-Ch]
	int v23;              // [esp+20h] [ebp-8h]
	_DWORD* v24;          // [esp+24h] [ebp-4h]
	unsigned __int8 v25;  // [esp+30h] [ebp+8h]
	unsigned __int8 v26;  // [esp+30h] [ebp+8h]
	unsigned __int8 v27;  // [esp+30h] [ebp+8h]
	int v28;              // [esp+34h] [ebp+Ch]

	v3 = calloc(1u, 0x38u);
	*v3 = 16;
	v24 = v3;
	v25 = nox_memfile_read_u8(f);
	v23 = v25;
	if ((int)v25 <= 0) {
		obj->field_5c = v3;
		obj->draw_func = &nox_thing_cond_animate_draw;
		obj->field_60 = 0;
		return 1;
	}
	v6 = attr_value;
	v20 = v3 + 1;
	v7 = (unsigned __int8*)(v3 + 6);
	v22 = -24 - (_DWORD)v3;
	while (1) {
		v9 = nox_memfile_read_u8(f);
		*v7 = v9;
		v11 = nox_memfile_read_u8(f);
		v7[5] = v11;
		v26 = nox_memfile_read_u8(f);
		nox_memfile_read(v6, 1u, v26, f);
		v6[v26] = 0;
		v13 = v20;
		v20[8] = get_animation_kind_id_44B4C0(v6);
		v14 = malloc(4 * *v7);
		*v20 = v14;
		if (!v14)
			break;
		v28 = 0;
		if (*v7) {
			do {
				v16 = nox_memfile_read_u32(f);
				*v6 = getMemByte(0x5D4594, 830836);
				if (v16 == -1) {
					v18 = nox_memfile_read_u8(f);
					LOBYTE(v21) = v18;
					v27 = nox_memfile_read_u8(f);
					nox_memfile_read(v6, 1u, v27, f);
					v16 = -1;
					v6[v27] = 0;
					v13 = v20;
				}
				*(_DWORD*)(*v13 + 4 * v28++) = nox_xxx_readImgMB_42FAA0(v16, v21, v6);
			} while (v28 < *v7);
		}
		++v7;
		v20 = v13 + 1;
		if ((int)&v7[v22] >= v23) {
			v3 = v24;
			obj->field_5c = v3;
			obj->draw_func = &nox_thing_cond_animate_draw;
			obj->field_60 = 0;
			return 1;
		}
	}
	return 0;
}
