#include "client__draw__parse__parse.h"
#include "GAME1_2.h"
#include "operators.h"

//----- (0044C000) --------------------------------------------------------
void* nox_xxx_spriteLoadStaticRandomData_44C000(char* attr_value, nox_memfile* f) {
	uint32_t* v2;      // eax
	uint32_t* v4;      // ebp
	void* result;      // eax
	int v7;            // edi
	uint8_t* v8;       // ebx
	int v10;           // ecx
	char v12;          // cl
	const char* v13;   // [esp+Ch] [ebp-4h]
	unsigned char v14; // [esp+14h] [ebp+4h]
	unsigned char v15; // [esp+18h] [ebp+8h]
	int v16;           // [esp+18h] [ebp+8h]

	v2 = calloc(1u, 0xCu);
	v4 = v2;
	*v2 = 12;
	v15 = nox_memfile_read_u8(f);
	*((uint8_t*)v4 + 8) = v15;
	result = malloc(4 * v15);
	v4[1] = result;
	if (result) {
		v7 = 0;
		v16 = 0;
		if (*((uint8_t*)v4 + 8)) {
			v8 = attr_value;
			do {
				v10 = nox_memfile_read_i32(f);
				*v8 = getMemByte(0x5D4594, 830852);
				if (v10 == -1) {
					v12 = nox_memfile_read_i8(f);
					LOBYTE(v13) = v12;
					v14 = nox_memfile_read_i8(f);
					nox_memfile_read(v8, 1u, v14, f);
					v10 = -1;
					v8[v14] = 0;
					v7 = v16;
				}
				*(uint32_t*)(v4[1] + 4 * v7++) = nox_xxx_readImgMB_42FAA0(v10, v13, v8);
				v16 = v7;
			} while (v7 < *((unsigned char*)v4 + 8));
		}
		result = v4;
	}
	return result;
}

//----- (0044BFA0) --------------------------------------------------------
int nox_xxx_spriteLoadVectoAnimatedImpl_44BFA0(int a1, nox_memfile* f) {
	if (!nox_xxx_loadVectorAnimated_44B8B0(a1, f)) {
		return 0;
	}

	return nox_xxx_loadVectorAnimated_44BC50(a1, f);
}

//----- (0044B8B0) --------------------------------------------------------
int nox_xxx_loadVectorAnimated_44B8B0(int a1, nox_memfile* f) {
	*(uint16_t*)(a1 + 40) = nox_memfile_read_u8(f);

	*(uint16_t*)(a1 + 42) = nox_memfile_read_u8(f);

	const uint8_t anim_kind_length = nox_memfile_read_u8(f);

	char animation_kind[256];
	nox_memfile_read(animation_kind, 1u, anim_kind_length, f);
	animation_kind[anim_kind_length] = 0;

	*(uint32_t*)(a1 + 44) = get_animation_kind_id_44B4C0(animation_kind);

	return 1;
}

//----- (0044BC50) --------------------------------------------------------
int nox_xxx_loadVectorAnimated_44BC50(int a1, nox_memfile* f) {
	int v2;          // ebp
	int v3;          // esi
	void* v4;        // eax
	int v5;          // ebx
	int v7;          // ebp
	char v9;         // dl
	int v11;         // esi
	int v13;         // [esp+10h] [ebp-90h]
	int v14;         // [esp+14h] [ebp-8Ch]
	const char* v15; // [esp+1Ch] [ebp-84h]
	char v16[128];   // [esp+20h] [ebp-80h]

	v2 = 0;
	v14 = 0;
	while (1) {
		v13 = v2 >= 16 ? v2 + 4 : v2;
		v3 = a1;
		v4 = malloc(4 * *(short*)(a1 + 40));
		*(uint32_t*)(v13 + a1 + 4) = v4;
		if (!v4) {
			break;
		}
		v5 = 0;
		if (*(uint16_t*)(a1 + 40) > 0) {
			do {
				v7 = nox_memfile_read_i32(f);
				v16[0] = getMemByte(0x5D4594, 830844);
				if (v7 == -1) {
					v9 = nox_memfile_read_i8(f);
					LOBYTE(v15) = v9;
					v11 = nox_memfile_read_u8(f);
					nox_memfile_read(v16, 1u, v11, f);
					v16[v11] = 0;
					v3 = a1;
				}
				*(uint32_t*)(*(uint32_t*)(v13 + v3 + 4) + 4 * ++v5 - 4) = nox_xxx_readImgMB_42FAA0(v7, v15, v16);
			} while (v5 < *(short*)(v3 + 40));
			v2 = v14;
		}
		v2 += 4;
		v14 = v2;
		if (v2 >= 32) {
			return 1;
		}
	}
	return 0;
}

//----- (0044B4C0) --------------------------------------------------------
int get_animation_kind_id_44B4C0(const char* a1) {
	if (!strcmp(a1, "OneShot")) {
		return 0;
	}
	if (!strcmp(a1, "OneShotRemove")) {
		return 1;
	}
	if (!strcmp(a1, "Loop")) {
		return 2;
	}
	if (!strcmp(a1, "LoopAndFade")) {
		return 3;
	}
	if (!strcmp(a1, "Random")) {
		return 4;
	}
	return strcmp(a1, "Slave") != 0 ? 0 : 5;
}
