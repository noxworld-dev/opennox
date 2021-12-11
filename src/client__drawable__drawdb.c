#include <stdio.h>

#include "client__draw__debugdraw.h"
#include "client__drawable__drawable.h"
#include "client__drawable__drawdb.h"

#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME1_2.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME2_2.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4.h"
#include "GAME4_3.h"
#include "client__gui__window.h"
#include "client__video__draw_common.h"
#include "common__strman.h"
#include "operators.h"
#include "thing.h"

extern int nox_things_count;
extern nox_thing* nox_things_head;
extern nox_thing** nox_things_array;
extern nox_memfile* nox_loaded_thing_bin;

extern uint64_t qword_581450_9544;
extern uint64_t qword_581450_9552;
extern uint32_t dword_5d4594_251568;
extern uint32_t dword_5d4594_251572;
extern uint32_t dword_5d4594_251600;
extern uint32_t dword_5d4594_251608;
extern uint32_t dword_5d4594_741676;
extern uint32_t dword_5d4594_741680;
nox_objectType_t* nox_xxx_objectTypes_head_1563660 = 0;
extern uint32_t dword_5d4594_1563664;

bool nox_parse_thing_flags(nox_thing* obj, nox_memfile* f, const char* attr_value);
bool nox_parse_thing_class(nox_thing* obj, nox_memfile* f, const char* attr_value);
bool nox_parse_thing_subclass(nox_thing* obj, nox_memfile* f, const char* attr_value);
bool nox_parse_thing_extent(nox_thing* obj, nox_memfile* f, char* attr_value);
bool nox_parse_thing_light_intensity(nox_thing* obj, nox_memfile* f, char* attr_value);
bool nox_parse_thing_draw(nox_thing* obj, nox_memfile* f, char* attr_value);
bool nox_parse_thing_z(nox_thing* obj, nox_memfile* f, char* attr_value);
bool nox_parse_thing_zsize(nox_thing* obj, nox_memfile* f, char* attr_value);
bool nox_parse_thing_size(nox_thing* obj, nox_memfile* f, char* attr_value);
bool nox_parse_thing_menu_icon(nox_thing* obj, nox_memfile* f, char* attr_value);
bool nox_parse_thing_light_color(nox_thing* obj, nox_memfile* f, char* attr_value);
bool nox_parse_thing_light_dir(nox_thing* obj, nox_memfile* f, char* attr_value);
bool nox_parse_thing_light_penumbra(nox_thing* obj, nox_memfile* f, char* attr_value);
bool nox_parse_thing_audio_loop(nox_thing* obj, nox_memfile* f, char* attr_value);
bool nox_parse_thing_client_update(nox_thing* obj, nox_memfile* f, char* attr_value);
bool nox_parse_thing_lifetime(nox_thing* obj, nox_memfile* f, char* attr_value);
bool nox_parse_thing_weight(nox_thing* obj, nox_memfile* f, char* attr_value);
bool nox_parse_thing_pretty_name(nox_thing* obj, nox_memfile* f, char* attr_value);
bool nox_parse_thing_desc(nox_thing* obj, nox_memfile* f, char* attr_value);
bool nox_parse_thing_pretty_image(nox_thing* obj, nox_memfile* f, char* attr_value);
bool nox_parse_thing_health(nox_thing* obj, nox_memfile* f, char* attr_value);

nox_parse_thing_funcs_t nox_parse_thing_funcs[] = {
	{"FLAGS", &nox_parse_thing_flags},
	{"CLASS", &nox_parse_thing_class},
	{"SUBCLASS", &nox_parse_thing_subclass},
	{"EXTENT", &nox_parse_thing_extent},
	{"LIGHTINTENSITY", &nox_parse_thing_light_intensity},
	{"DRAW", &nox_parse_thing_draw},
	{"Z", &nox_parse_thing_z},
	{"ZSIZE", &nox_parse_thing_zsize},
	{"SIZE", &nox_parse_thing_size},
	{"MENUICON", &nox_parse_thing_menu_icon},
	{"LIGHTCOLOR", &nox_parse_thing_light_color},
	{"LIGHTDIRECTION", &nox_parse_thing_light_dir},
	{"LIGHTPENUMBRA", &nox_parse_thing_light_penumbra},
	{"AUDIOLOOP", &nox_parse_thing_audio_loop},
	{"CLIENTUPDATE", &nox_parse_thing_client_update},
	{"LIFETIME", &nox_parse_thing_lifetime},
	{"WEIGHT", &nox_parse_thing_weight},
	{"PRETTYNAME", &nox_parse_thing_pretty_name},
	{"DESCRIPTION", &nox_parse_thing_desc},
	{"PRETTYIMAGE", &nox_parse_thing_pretty_image},
	{"HEALTH", &nox_parse_thing_health},
};
int nox_parse_thing_funcs_cnt = sizeof(nox_parse_thing_funcs) / sizeof(nox_parse_thing_funcs_t);

//----- (0044B160) --------------------------------------------------------
bool nox_parse_thing_flags(nox_thing* obj, nox_memfile* f, const char* attr_value) {
	obj->flags = 0;
	set_bitmask_flags_from_plus_separated_names_423930(attr_value, &obj->flags,
													   (const char**)getMemAt(0x587000, 114076));
	return 1;
}

//----- (0044B190) --------------------------------------------------------
bool nox_parse_thing_class(nox_thing* obj, nox_memfile* f, const char* attr_value) {
	obj->pri_class = 0;
	set_bitmask_flags_from_plus_separated_names_423930(attr_value, &obj->pri_class,
													   (const char**)getMemAt(0x587000, 114208));
	return 1;
}

//----- (0044B1C0) --------------------------------------------------------
bool nox_parse_thing_subclass(nox_thing* obj, nox_memfile* f, const char* attr_value) {
	obj->sub_class = 0;
	set_bitmask_flags_from_plus_separated_names_multiple_423A10(attr_value, &obj->sub_class);
	return 1;
}

//----- (0044B1F0) --------------------------------------------------------
bool nox_parse_thing_extent(nox_thing* obj, nox_memfile* f, char* attr_value) {
	nox_shape s;
	bool res = nox_parse_shape(&s, attr_value);
	obj->shape_kind = s.kind;
	obj->shape_r = s.circle_r;
	obj->shape_w = s.box_w;
	obj->shape_h = s.box_h;
	return res;
}

//----- (0044B230) --------------------------------------------------------
bool nox_parse_thing_light_intensity(nox_thing* obj, nox_memfile* f, char* attr_value) {
	sscanf(attr_value, "%f", &obj->light_intensity);
	return 1;
}

//----- (0044C200) --------------------------------------------------------
bool nox_parse_thing_draw(nox_thing* obj, nox_memfile* f, char* attr_value) {
	const uint8_t read_len = nox_memfile_read_u8(f);

	char read_str[256];
	nox_memfile_read(read_str, 1u, read_len, f);
	read_str[read_len] = 0;

	// TODO: After cleanup: Figure out if this value has any significance to the data in the file, or if the file was
	// simply 16byte-aligned
	uint32_t tmp;
	nox_memfile_read64align_40AD60((char*)&tmp, sizeof(tmp), 1, f);

	if (!*(uint32_t*)nox_parse_thing_draw_funcs) {
		return 1;
	}

	nox_parse_thing_draw_funcs_t* item = NULL;
	for (int i = 0; i < nox_parse_thing_draw_funcs_cnt; i++) {
		nox_parse_thing_draw_funcs_t* cur = &nox_parse_thing_draw_funcs[i];
		if (!strcmp(cur->name, read_str)) {
			item = cur;
			break;
		}
	}

	if (!item) {
		return 1;
	}

	if (item->parse_fnc) {
		item->parse_fnc(obj, f, attr_value);
	}
	obj->draw_func = item->draw;

	return 1;
}

//----- (0044C2F0) --------------------------------------------------------
bool nox_parse_thing_z(nox_thing* obj, nox_memfile* f, char* attr_value) {
	int z = 0;
	sscanf(attr_value, "%d", &z);
	obj->z = z;
	return 1;
}

//----- (0044C320) --------------------------------------------------------
bool nox_parse_thing_zsize(nox_thing* obj, nox_memfile* f, char* attr_value) {
	int min = 0;
	int max = 0;
	sscanf(attr_value, "%d %d", &min, &max);
	if (max < min) {
		max = min;
	}
	obj->zsize_min = (double)min;
	obj->zsize_max = (double)max;
	return 1;
}

//----- (0044C370) --------------------------------------------------------
bool nox_parse_thing_size(nox_thing* obj, nox_memfile* f, char* attr_value) {
	int w = 0;
	int h = 0;
	sscanf(attr_value, "%d %d", &w, &h);
	obj->hwidth = w / 2;
	obj->hheight = h / 2;
	return 1;
}

//----- (0044C3B0) --------------------------------------------------------
bool nox_parse_thing_menu_icon(nox_thing* obj, nox_memfile* f, char* attr_value) {
	obj->menuicon = nox_memfile_read_u32(f);
	if (obj->menuicon == -1) {
		// TODO: This branch doesnt seem to ever be taken. The meaning is not clear. Is this reading (and dropping) a
		// string?
		nox_memfile_skip(f, 1);
		int n = nox_memfile_read_u8(f);
		nox_memfile_skip(f, n);
	}
	return 1;
}

//----- (0044B250) --------------------------------------------------------
bool nox_parse_thing_light_color(nox_thing* obj, nox_memfile* f, char* attr_value) {
	int r;
	int g;
	int b;
	if (sscanf(attr_value, "%d %d %d", &r, &g, &b) != 3) {
		return 0;
	}
	obj->field_f = 2;
	obj->light_color_r = (r <= 255 ? r : 255);
	obj->light_color_g = (g <= 255 ? g : 255);
	obj->light_color_b = (b <= 255 ? b : 255);
	return 1;
}

//----- (0044B2D0) --------------------------------------------------------
bool nox_parse_thing_light_dir(nox_thing* obj, nox_memfile* f, char* attr_value) {
	int deg = 0;
	if (sscanf(attr_value, "%d", &deg) != 1) {
		return 0;
	}
	if (deg < 0 || deg >= 360) {
		return 0;
	}
	obj->light_dir = (long long)((double)deg * *getMemDoublePtr(0x581450, 9560) * *(double*)&qword_581450_9552 +
								 *(double*)&qword_581450_9544);
	obj->field_10 = 0;
	return 1;
}

//----- (0044B330) --------------------------------------------------------
bool nox_parse_thing_light_penumbra(nox_thing* obj, nox_memfile* f, char* attr_value) {
	int deg = 0;
	if (sscanf(attr_value, "%d", &deg) != 1) {
		return 0;
	}
	if (deg < 0 || deg >= 180) {
		return 0;
	}
	obj->light_penumbra = (long long)((double)deg * *getMemDoublePtr(0x581450, 9560) * *(double*)&qword_581450_9552 +
									  *(double*)&qword_581450_9544);
	return 1;
}

// 44C200: using guessed type char var_100[256];

//----- (0044C3F0) --------------------------------------------------------
bool nox_parse_thing_audio_loop(nox_thing* obj, nox_memfile* f, char* attr_value) {
	obj->audio_loop = nox_xxx_utilFindSound_40AF50(attr_value);
	return 1;
}

//----- (004B5C40) --------------------------------------------------------
bool nox_parse_thing_client_update(nox_thing* obj, nox_memfile* f, char* attr_value) {
	char* v3;          // eax
	const char* v4;    // ecx
	int v5;            // ebp
	unsigned char* v6; // edi

	v3 = strtok(attr_value, " \t\n\r");
	v4 = *(const char**)getMemAt(0x587000, 175072);
	v5 = 0;
	if (*getMemU32Ptr(0x587000, 175072)) {
		v6 = getMemAt(0x587000, 175072);
		do {
			if (!strcmp(v4, v3)) {
				break;
			}
			v4 = (const char*)*((uint32_t*)v6 + 2);
			v6 += 8;
			++v5;
		} while (v4);
	}
	if (!*getMemU32Ptr(0x587000, 175072 + 8 * v5)) {
		return 0;
	}
	obj->client_update = *getMemU32Ptr(0x587000, 175076 + 8 * v5);
	return 1;
}

//----- (0044C410) --------------------------------------------------------
bool nox_parse_thing_lifetime(nox_thing* obj, nox_memfile* f, char* attr_value) {
	int v = 0;
	sscanf(attr_value, "%d", &v);
	obj->lifetime = v;
	return 1;
}

//----- (0044C440) --------------------------------------------------------
bool nox_parse_thing_weight(nox_thing* obj, nox_memfile* f, char* attr_value) {
	int v = 0;
	sscanf(attr_value, "%d", &v);
	obj->weight = (uint8_t)v;
	obj->pri_class |= 0x80000000;
	return 1;
}

//----- (0044C480) --------------------------------------------------------
bool nox_parse_thing_pretty_name(nox_thing* obj, nox_memfile* f, char* attr_value) {
	obj->pretty_name =
		nox_strman_loadString_40F1D0(attr_value, 0, "C:\\NoxPost\\src\\Client\\Drawable\\drawdb.c", 1396);
	return 1;
}

//----- (0044C4B0) --------------------------------------------------------
bool nox_parse_thing_desc(nox_thing* obj, nox_memfile* f, char* attr_value) {
	obj->desc = nox_strman_loadString_40F1D0(attr_value, 0, "C:\\NoxPost\\src\\Client\\Drawable\\drawdb.c", 1403);
	return 1;
}

//----- (0044C500) --------------------------------------------------------
bool nox_parse_thing_pretty_image(nox_thing* obj, nox_memfile* f, char* attr_value) {
	char v10[128];

	const uint32_t known_idx = nox_memfile_read_u32(f);
	if (known_idx != -1) {
		obj->pretty_image = nox_xxx_readImgMB_42FAA0(known_idx, 0, v10);
		return 1;
	}

	// TODO: After cleanup: This branch appears to never be taken. Figure out what these values are.
	const int v8 = nox_memfile_read_u8(f);
	const int n = nox_memfile_read_u8(f);
	nox_memfile_read(v10, 1u, n, f);
	obj->pretty_image = nox_xxx_readImgMB_42FAA0(known_idx, v8, v10);
	return 1;
}

//----- (0044C4E0) --------------------------------------------------------
bool nox_parse_thing_health(nox_thing* obj, nox_memfile* f, char* attr_value) {
	obj->health = atoi(attr_value);
	return 1;
}

//----- (0044CE00) --------------------------------------------------------
int nox_parse_thing(nox_memfile* thing_file, char* scratch_buffer, nox_thing* thing) {
	unsigned char entry_len;
	while ((entry_len = nox_memfile_read_u8(thing_file))) {
		nox_memfile_read(scratch_buffer, 1u, entry_len, thing_file);
		scratch_buffer[entry_len] = 0;
		const char* attr_name = strtok(scratch_buffer, " \t\n\r");
		for (int i = 0; i < nox_parse_thing_funcs_cnt; i++) {
			const nox_parse_thing_funcs_t* attr_parser = &nox_parse_thing_funcs[i];
			if (strcmp(attr_name, attr_parser->name) != 0) {
				continue;
			}

			const char* attr_value = strtok(0, "=");
			if (attr_value) {
				memmove(scratch_buffer, attr_value + 1, strlen(attr_value + 1) + 1);
			}
			attr_parser->parse_func(thing, thing_file, scratch_buffer);
			break;
		}
	}

	return 1;
}

//----- (0044CCA0) --------------------------------------------------------
int nox_xxx_spriteDefByAlphabetClear_44CCA0() {
	int result; // eax

	result = 0;
	memset(getMemAt(0x5D4594, 830616), 0, 0x6Cu);
	memset(getMemAt(0x5D4594, 830724), 0, 0x6Cu);
	memset(getMemAt(0x5D4594, 830296), 0, 0x6Cu);
	return result;
}

//----- (00485CF0) --------------------------------------------------------
int sub_485CF0() {
	int v0;    // edi
	void** v1; // esi

	v0 = 0;
	if (*(int*)&dword_5d4594_251568 <= 0) {
		return 1;
	}
	v1 = (void**)getMemAt(0x85B3FC, 32516);
	do {
		if (*v1) {
			free(*v1);
			*v1 = 0;
		}
		++v0;
		v1 += 15;
	} while (v0 < *(int*)&dword_5d4594_251568);
	return 1;
}

//----- (00485F30) --------------------------------------------------------
int sub_485F30() {
	int v0;    // edi
	void** v1; // esi

	v0 = 0;
	if (*(int*)&dword_5d4594_251572 <= 0) {
		return 1;
	}
	v1 = (void**)getMemAt(0x85B3FC, 28676);
	do {
		if (*v1) {
			free(*v1);
			*v1 = 0;
		}
		++v0;
		v1 += 15;
	} while (v0 < *(int*)&dword_5d4594_251572);
	return 1;
}

//----- (0046A360) --------------------------------------------------------
int sub_46A360() {
	int i;             // ebx
	int v1;            // edx
	int v2;            // esi
	unsigned char* v3; // edi

	for (i = 0; i < 986560; i += 12332) {
		v1 = 0;
		do {
			v2 = 15;
			do {
				v3 = getMemAt(0x85B3FC, 51476 + i + v1);
				v1 += 64;
				--v2;
				memset(v3, 0, 0x40u);
			} while (v2);
		} while (v1 < 3840);
	}
	return 1;
}

//----- (0044CCD0) --------------------------------------------------------
size_t nox_xxx_spriteDefByAlphabetAlloc_44CCD0() {
	int i;         // esi
	size_t result; // eax

	for (i = 0; i < 108; i += 4) {
		result = *getMemU32Ptr(0x5D4594, 830616 + i);
		if (result) {
			result = (size_t)calloc(1u, 8 * result);
			*getMemU32Ptr(0x5D4594, 830296 + i) = result;
		} else {
			*getMemU32Ptr(0x5D4594, 830296 + i) = 0;
		}
		*getMemU32Ptr(0x5D4594, 830724 + i) = 0;
	}
	return result;
}

//----- (0044CD60) --------------------------------------------------------
void nox_xxx_spriteDefByAlphabetAdd_0_44CD60(nox_thing* a1, int a2) {
	if (!a1) {
		return;
	}

	int v2 = nox_xxx_keyFirstLetterNumberCli_44CD30(a1->name);
	if (v2 < 0) {
		return;
	}

	int v3 = *getMemU32Ptr(0x5D4594, 830296 + 4 * v2);
	if (!v3) {
		return;
	}

	int v4 = *getMemU32Ptr(0x5D4594, 830724 + 4 * v2);
	*(uint32_t*)(v3 + 8 * v4) = a1;
	*(uint32_t*)(v3 + 8 * v4 + 4) = a2;
	++*getMemU32Ptr(0x5D4594, 830724 + 4 * v2);
}

//----- (0044CDE0) --------------------------------------------------------
int nox_xxx_spriteDefByAlphabetCompare_44CDE0(const void* a1, const void* a2) {
	return _strcmpi(**(const char***)a1, **(const char***)a2);
}

//----- (0044CDB0) --------------------------------------------------------
void nox_xxx_spriteDefByAlphabetSort_44CDB0() {
	int i;         // esi
	signed int v1; // eax

	for (i = 0; i < 108; i += 4) {
		v1 = *getMemU32Ptr(0x5D4594, 830616 + i);
		if (v1 > 1) {
			qsort(*(void**)getMemAt(0x5D4594, 830296 + i), v1, 8u, nox_xxx_spriteDefByAlphabetCompare_44CDE0);
		}
	}
}

//----- (004131A0) --------------------------------------------------------
char* nox_xxx_equipWeapon_4131A0() {
	char* result; // eax
	int i;        // esi
	int j;        // esi

	result = *(char**)getMemAt(0x5D4594, 251616);
	if (*getMemU32Ptr(0x5D4594, 251616) != 1) {
		for (i = dword_5d4594_251600; i; i = *(uint32_t*)(i + 80)) {
			if (nox_common_gameFlags_check_40A5C0(2097153)) {
				result = (char*)nox_xxx_getNameId_4E3AA0(*(char**)i);
			} else {
				result = (char*)nox_common_gameFlags_check_40A5C0(2);
				if (!result) {
					return result;
				}
				result = (char*)nox_xxx_getTTByNameSpriteMB_44CFC0(*(char**)i);
			}
			*(uint32_t*)(i + 4) = result;
		}
		for (j = dword_5d4594_251608; j; j = *(uint32_t*)(j + 80)) {
			if (nox_common_gameFlags_check_40A5C0(2097153)) {
				result = (char*)nox_xxx_getNameId_4E3AA0(*(char**)j);
			} else {
				result = (char*)nox_common_gameFlags_check_40A5C0(2);
				if (!result) {
					return result;
				}
				result = (char*)nox_xxx_getTTByNameSpriteMB_44CFC0(*(char**)j);
			}
			*(uint32_t*)(j + 4) = result;
		}
		*getMemU32Ptr(0x5D4594, 251616) = 1;
	}
	return result;
}

//----- (00415AB0) --------------------------------------------------------
void nox_xxx_equipArmor_415AB0() {
	unsigned char* v0; // esi
	int v1;            // eax
	int v2;            // eax

	if (*getMemU32Ptr(0x5D4594, 371252) != 1) {
		if (*getMemU32Ptr(0x587000, 34848)) {
			v0 = getMemAt(0x587000, 34864);
			do {
				if (nox_common_gameFlags_check_40A5C0(2097153)) {
					*((uint32_t*)v0 - 2) = nox_xxx_getNameId_4E3AA0(*((char**)v0 - 4));
					v1 = nox_xxx_getNameId_4E3AA0(*(char**)v0);
				} else {
					*((uint32_t*)v0 - 2) = nox_xxx_getTTByNameSpriteMB_44CFC0(*((char**)v0 - 4));
					v1 = nox_xxx_getTTByNameSpriteMB_44CFC0(*(char**)v0);
				}
				*((uint32_t*)v0 + 1) = v1;
				v2 = *((uint32_t*)v0 + 2);
				v0 += 24;
			} while (v2);
		}
		*getMemU32Ptr(0x5D4594, 371252) = 1;
	}
}

//----- (004157C0) --------------------------------------------------------
void nox_xxx_equipWeapon_4157C0() {
	unsigned char* v0; // esi
	int v1;            // eax
	int v2;            // eax

	if (*getMemU32Ptr(0x5D4594, 371244) != 1) {
		if (*getMemU32Ptr(0x587000, 33064)) {
			v0 = getMemAt(0x587000, 33064);
			do {
				if (nox_common_gameFlags_check_40A5C0(2097153)) {
					v1 = nox_xxx_getNameId_4E3AA0(*(char**)v0);
				} else {
					v1 = nox_xxx_getTTByNameSpriteMB_44CFC0(*(char**)v0);
				}
				*((uint32_t*)v0 + 1) = v1;
				v2 = *((uint32_t*)v0 + 3);
				v0 += 12;
			} while (v2);
		}
		*getMemU32Ptr(0x5D4594, 371244) = 1;
	}
}

//----- (0044D390) --------------------------------------------------------
int nox_get_things_count() { return nox_things_count; }

//----- (0042BF10) --------------------------------------------------------
int sub_42BF10() {
	int v1; // eax

	if (dword_5d4594_741676) {
		return 1;
	}
	if (nox_common_gameFlags_check_40A5C0(2097153)) {
		v1 = nox_xxx_unitDefGetCount_4E3AC0();
	} else {
		if (!nox_common_gameFlags_check_40A5C0(2)) {
			return 0;
		}
		v1 = nox_get_things_count();
	}
	dword_5d4594_741680 = v1;
	dword_5d4594_741676 = calloc(v1, 2);
	if (dword_5d4594_741676) {
		sub_42BFB0();
		return 1;
	}
	return 0;
}

//----- (0044C840) --------------------------------------------------------
void* nox_xxx_parseThingBinClient_44C840_read_things(void) {
	char* scratch_buffer = calloc(256 * 1024, 1);
	nox_xxx_spriteDefByAlphabetClear_44CCA0();
	nox_things_free_44C580();
	nox_things_count = 1;
	sub_485CF0();
	sub_485F30();
	sub_46A360();

	nox_memfile* things = nox_open_thing_bin();
	if (!things) {
		return 0;
	}
	nox_memfile_seek_40AD10(things, 0, 0);

	int entry_type;
	while (nox_memfile_read(&entry_type, 4u, 1, things)) {
		switch (entry_type) {
		case 0x5350454C: // "SPEL"
			nox_thing_skip_spells_415100(things);
			break;
		case 0x4142494C: // "ABIL"
			nox_thing_read_ability_415320(things);
			break;
		case 0x41554420: // "AUD "
			nox_thing_skip_AUD_414D40(things);
			break;
		case 0x41564E54: // "AVNT"
			nox_thing_skip_AVNT_452B00(things);
			break;
		case 0x57414C4C: // "WALL"
			if (!nox_thing_read_wall_46A010(things, scratch_buffer)) {
				return 0;
			}
			break;
		case 0x464C4F52: // "FLOR"
			if (!nox_thing_read_floor_485B30(things, scratch_buffer)) {
				return 0;
			}
			break;
		case 0x45444745: // "EDGE"
			if (!nox_thing_read_edge_485D40(things, scratch_buffer)) {
				return 0;
			}
			break;
		case 0x494D4147: // "IMAG"
			nox_thing_read_image_415240(things);
			break;
		case 0x54484E47: // "THNG"
			;
			nox_thing* obj = (nox_thing*)calloc(1, sizeof(nox_thing));
			if (!obj) {
				return 0;
			}
			unsigned char v28 = nox_memfile_read_u8(things);
			nox_memfile_read(scratch_buffer, 1, v28, things);
			scratch_buffer[v28] = 0;
			obj->name = nox_clone_str(scratch_buffer);
			obj->menuicon = -1;
			obj->field_1c = nox_things_count++;
			obj->flags |= 0x1000000;
			*((uint8_t*)obj + 15) = 0;
			obj->field_10 = 0xFFFF;
			obj->audio_loop = 0;
			obj->draw_func = nox_thing_debug_draw;
			obj->zsize_min = 0;
			obj->zsize_max = 30.0f;
			if (!nox_parse_thing(things, scratch_buffer, obj)) {
				return 0;
			}
			obj->next = nox_things_head;
			nox_things_head = obj;
			nox_xxx_spriteDefByAlphabetAdd_44CD10(obj->name);
			break;
		}
	}
	*getMemU32Ptr(0x85B3FC, 4) = 1;
	if (nox_loaded_thing_bin) {
		if (nox_common_gameFlags_check_40A5C0(1) && *getMemU32Ptr(0x85B3FC, 960)) {
			nox_free_thing_bin();
		}
	} else {
		nox_memfile_free(things);
	}
	void* result = calloc(nox_things_count, sizeof(nox_thing*));
	nox_things_array = result;
	if (result) {
		nox_xxx_spriteDefByAlphabetAlloc_44CCD0();
		nox_thing* cur = nox_things_head;
		for (int i = 1; i < nox_things_count; i++) {
			nox_things_array[nox_things_count - i] = cur;
			nox_xxx_spriteDefByAlphabetAdd_0_44CD60(cur, nox_things_count - i);
			if (*((uint8_t*)cur + 0xe)) {
				// The large amount of logic in the following two branches is due to copying strings as WORDs.
				// If not loaded, set cur->pretty_name = load_string "thing.db:${cur->name}PrettyName"
				if (!cur->pretty_name) {
					strcpy((char*)getMemAt(0x5D4594, 830404), "thing.db:");
					char* cur_name = cur->name;
					unsigned int cur_name_len_plus_one = strlen(cur->name) + 1;
					unsigned char* v11 = getMemAt(0x5D4594, 830404 + strlen((const char*)getMemAt(0x5D4594, 830404)));
					memcpy(v11, cur->name, 4 * (cur_name_len_plus_one >> 2));
					char* v13 = &cur_name[4 * (cur_name_len_plus_one >> 2)];
					unsigned char* v12 = &v11[4 * (cur_name_len_plus_one >> 2)];
					char v14 = cur_name_len_plus_one;
					LOWORD(cur_name_len_plus_one) = *getMemU16Ptr(0x587000, 122728);
					memcpy(v12, v13, v14 & 3);
					unsigned char* v15 = getMemAt(0x5D4594, 830405 + strlen((const char*)getMemAt(0x5D4594, 830404)));
					int v16 = *getMemU32Ptr(0x587000, 122724);
					*(uint32_t*)--v15 = *getMemU32Ptr(0x587000, 122720);
					unsigned char v17 = getMemByte(0x587000, 122730);
					*((uint32_t*)v15 + 1) = v16;
					*((uint16_t*)v15 + 4) = cur_name_len_plus_one;
					v15[10] = v17;
					cur->pretty_name = nox_strman_loadString_40F1D0(
						(char*)getMemAt(0x5D4594, 830404), 0, "C:\\NoxPost\\src\\Client\\Drawable\\drawdb.c", 1926);
				}
				// if not loaded, set cur->desc = load_string "thing.db:${cur->name}Description"
				if (!cur->desc) {
					strcpy((char*)getMemAt(0x5D4594, 830404), "thing.db:");
					char* v18 = cur->name;
					unsigned int v19 = strlen(cur->name) + 1;
					unsigned char* v20 = getMemAt(0x5D4594, 830404 + strlen((const char*)getMemAt(0x5D4594, 830404)));
					memcpy(v20, cur->name, 4 * (v19 >> 2));
					char* v22 = &v18[4 * (v19 >> 2)];
					unsigned char* v21 = &v20[4 * (v19 >> 2)];
					char v23 = v19;
					int v24 = *getMemU32Ptr(0x587000, 122792);
					memcpy(v21, v22, v23 & 3);
					unsigned char* v25 = getMemAt(0x5D4594, 830405 + strlen((const char*)getMemAt(0x5D4594, 830404)));
					int v26 = *getMemU32Ptr(0x587000, 122788);
					*(uint32_t*)--v25 = *getMemU32Ptr(0x587000, 122784);
					*((uint32_t*)v25 + 1) = v26;
					*((uint32_t*)v25 + 2) = v24;
					cur->desc = nox_strman_loadString_40F1D0((char*)getMemAt(0x5D4594, 830404), 0,
															 "C:\\NoxPost\\src\\Client\\Drawable\\drawdb.c", 1933);
				}
			}
			cur = cur->next;
		}
		nox_xxx_spriteDefByAlphabetSort_44CDB0();
		free(scratch_buffer);
		nox_xxx_equipWeapon_4131A0();
		nox_xxx_equipArmor_415AB0();
		nox_xxx_equipWeapon_4157C0();
		result = (void*)(sub_42BF10() != 0);
	}
	return result;
}

//----- (0044C620) --------------------------------------------------------
void sub_44C620_free() {
	void** v0; // esi

	v0 = (void**)getMemAt(0x5D4594, 830296);
	do {
		if (*v0) {
			free(*v0);
		}
		*v0 = 0;
		++v0;
	} while ((int)v0 < (int)getMemAt(0x5D4594, 830404));
}

//----- (004E2B30) --------------------------------------------------------
void nox_xxx_unitDefByAlphabetFree_4E2B30() {
	void** v0;    // esi
	void* result; // eax

	v0 = (void**)getMemAt(0x5D4594, 1563348);
	do {
		result = *v0;
		if (*v0) {
			free(*v0);
		}
		*v0 = 0;
		++v0;
	} while ((int)v0 < (int)getMemAt(0x5D4594, 1563456));
}

//----- (0042BF80) --------------------------------------------------------
void nox_xxx_free_42BF80() {
	if (dword_5d4594_741676) {
		free(*(void**)&dword_5d4594_741676);
		dword_5d4594_741676 = 0;
	}
	dword_5d4594_741680 = 0;
}

//----- (004E2A20) --------------------------------------------------------
int nox_xxx_freeObjectTypes_4E2A20() {
	nox_objectType_t* next = 0;
	for (nox_objectType_t* typ = nox_xxx_objectTypes_head_1563660; typ; typ = next) {
		next = typ->next;
		if (typ->id) {
			free(typ->id);
		}
		if (typ->field_34) {
			free(typ->field_34);
		}
		if (typ->field_36) {
			free(typ->field_36);
		}
		if (typ->field_41) {
			free(typ->field_41);
		}
		if (typ->field_44) {
			free(typ->field_44);
		}
		void* v2 = typ->data_update;
		if (v2) {
			if (typ->obj_class & 0x2) {
				void* v3 = *(void**)((uint32_t)v2 + 476);
				if (v3) {
					free(v3);
				}
			}
			free(typ->data_update);
		}
		if (typ->field_51) {
			free(typ->field_51);
		}
		free(typ);
	}
	nox_xxx_objectTypes_head_1563660 = 0;
	if (*getMemU32Ptr(0x5D4594, 1563456)) {
		free(*(void**)getMemAt(0x5D4594, 1563456));
		*getMemU32Ptr(0x5D4594, 1563456) = 0;
	}
	*getMemU32Ptr(0x587000, 201384) = 1;
	nox_xxx_unitDefByAlphabetFree_4E2B30();
	nox_xxx_free_42BF80();
	return 1;
}

//----- (004E3010) --------------------------------------------------------
int sub_4E3010() {
	int result; // eax

	result = 0;
	memset(getMemAt(0x5D4594, 1563668), 0, 0x6Cu);
	memset(getMemAt(0x5D4594, 1563776), 0, 0x6Cu);
	memset(getMemAt(0x5D4594, 1563348), 0, 0x6Cu);
	return result;
}

//----- (004E3080) --------------------------------------------------------
char* nox_xxx_unitDefByAlphabetAdd_4E3080(char* a1) {
	char* result; // eax

	result = a1;
	if (a1) {
		result = (char*)nox_xxx_keyFirstLetterNumber_4E30A0(a1);
		if ((int)result >= 0) {
			++*getMemU32Ptr(0x5D4594, 1563668 + 4 * (uint32_t)result);
		}
	}
	return result;
}

//----- (004E3110) --------------------------------------------------------
int nox_xxx_objectTypes_allFit_4E3110() {
	int ret = 1;
	for (nox_objectType_t* typ = nox_xxx_getFirstObjectType_4E3B30(); typ; typ = nox_xxx_objectType_next_4E3B40(typ)) {
		if ((typ->field_8 & 0x40) != 0) {
			continue;
		}
		nox_shape* shape = &typ->shape;
		if (shape->kind == NOX_SHAPE_CIRCLE) {
			if (shape->circle_r + shape->circle_r >= 85.0) {
				ret = 0;
			}
		} else if (shape->kind == NOX_SHAPE_BOX) {
			nox_shape_box_calc(shape);
			if (shape->box_right_top - shape->box_left_bottom_2 >= 85.0 ||
				shape->box_right_top_2 - shape->box_left_bottom >= 85.0) {
				ret = 0;
			}
		}
	}
	return ret;
}

//----- (004E3040) --------------------------------------------------------
void nox_xxx_unitDefByAlphabetInit_4E3040() {
	for (int i = 0; i < 27; i++) {
		int cnt = *getMemU32Ptr(0x5D4594, 1563668 + 4 * i);
		if (cnt) {
			*getMemU32Ptr(0x5D4594, 1563348 + 4 * i) = calloc(1u, 4 * cnt);
		} else {
			*getMemU32Ptr(0x5D4594, 1563348 + 4 * i) = 0;
		}
		*getMemU32Ptr(0x5D4594, 1563776 + 4 * i) = 0;
	}
}

//----- (004E30D0) --------------------------------------------------------
void nox_xxx_objectTypeAddToNameInd_4E30D0(int a1) {
	int v1; // eax
	int v2; // ecx

	if (a1) {
		v1 = nox_xxx_keyFirstLetterNumber_4E30A0(*(char**)(a1 + 4));
		v2 = *getMemU32Ptr(0x5D4594, 1563348 + 4 * v1);
		if (v2) {
			*(uint32_t*)(v2 + 4 * *getMemU32Ptr(0x5D4594, 1563776 + 4 * v1)) = a1;
			++*getMemU32Ptr(0x5D4594, 1563776 + 4 * v1);
		}
	}
}

//----- (004E2A00) --------------------------------------------------------
int sub_4E2A00(const void* a1, const void* a2) {
	return _strcmpi(*(const char**)(*(uint32_t*)a1 + 4), *(const char**)(*(uint32_t*)a2 + 4));
}
//----- (004E29D0) --------------------------------------------------------
void sub_4E29D0() {
	int i;         // esi
	signed int v1; // eax

	for (i = 0; i < 108; i += 4) {
		v1 = *getMemU32Ptr(0x5D4594, 1563668 + i);
		if (v1 > 1) {
			qsort(*(void**)getMemAt(0x5D4594, 1563348 + i), v1, 4u, sub_4E2A00);
		}
	}
}

//----- (004F0640) --------------------------------------------------------
const char* sub_4F0640() {
	char* v0;           // eax
	unsigned char* v1;  // esi
	char v2;            // cl
	char* v3;           // eax
	const char* v4;     // eax
	unsigned char* v5;  // esi
	int v6;             // eax
	const char* v7;     // eax
	unsigned char* v8;  // esi
	int v9;             // eax
	const char* v10;    // eax
	unsigned char* v11; // esi
	int v12;            // eax
	const char* result; // eax
	unsigned char* v14; // esi
	int v15;            // eax

	v0 = *(char**)getMemAt(0x587000, 208180);
	if (*getMemU32Ptr(0x587000, 208180)) {
		v1 = getMemAt(0x587000, 208180);
		do {
			v2 = *v0;
			v3 = *(char**)v1;
			if (v2 == 35) {
				++v3;
			}
			*((uint32_t*)v1 + 1) = nox_xxx_getNameId_4E3AA0(v3);
			v0 = (char*)*((uint32_t*)v1 + 5);
			v1 += 20;
		} while (v0);
	}
	v4 = *(const char**)getMemAt(0x587000, 210712);
	if (*getMemU32Ptr(0x587000, 210712)) {
		v5 = getMemAt(0x587000, 210712);
		do {
			v6 = nox_xxx_modifGetIdByName_413290(v4);
			*((uint32_t*)v5 - 1) = nox_xxx_modifGetDescById_413330(v6);
			v4 = (const char*)*((uint32_t*)v5 + 6);
			v5 += 24;
		} while (v4);
	}
	v7 = *(const char**)getMemAt(0x587000, 210856);
	if (*getMemU32Ptr(0x587000, 210856)) {
		v8 = getMemAt(0x587000, 210856);
		do {
			v9 = nox_xxx_modifGetIdByName_413290(v7);
			*((uint32_t*)v8 - 1) = nox_xxx_modifGetDescById_413330(v9);
			v7 = (const char*)*((uint32_t*)v8 + 6);
			v8 += 24;
		} while (v7);
	}
	v10 = *(const char**)getMemAt(0x587000, 211000);
	if (*getMemU32Ptr(0x587000, 211000)) {
		v11 = getMemAt(0x587000, 211000);
		do {
			v12 = nox_xxx_modifGetIdByName_413290(v10);
			*((uint32_t*)v11 - 1) = nox_xxx_modifGetDescById_413330(v12);
			v10 = (const char*)*((uint32_t*)v11 + 6);
			v11 += 24;
		} while (v10);
	}
	result = *(const char**)getMemAt(0x587000, 209344);
	if (*getMemU32Ptr(0x587000, 209344)) {
		v14 = getMemAt(0x587000, 209344);
		do {
			v15 = nox_xxx_modifGetIdByName_413290(result);
			*((uint32_t*)v14 - 1) = nox_xxx_modifGetDescById_413330(v15);
			result = (const char*)*((uint32_t*)v14 + 6);
			v14 += 24;
		} while (result);
	}
	return result;
}

//----- (004E2B60) --------------------------------------------------------
int nox_read_things_alternative_4E2B60(void) {
	void* v1;     // eax
	void* v3;     // edi
	void* result; // eax
	int v17;      // ecx
	int v18;      // esi
	int v19;      // eax
	int i;        // [esp+0h] [ebp-8h]
	void* v21;    // [esp+4h] [ebp-4h]

	if (nox_xxx_objectTypes_head_1563660) {
		nox_xxx_freeObjectTypes_4E2A20();
	}
	sub_4E3010();
	dword_5d4594_1563664 = 0;
	v1 = calloc(1, 0x40000u);
	v3 = v1;
	v21 = v1;

	nox_memfile* things = nox_open_thing_bin();
	if (!things) {
		return 0;
	}
	nox_memfile_seek_40AD10(things, 0, 0);
	while (nox_memfile_read(&i, 4u, 1, things)) {
		switch (i) {
		case 0x5350454C: // SPEL
			nox_thing_skip_spells_415100(things);
			break;
		case 0x4142494C: // ABIL
			nox_thing_read_ability_415320(things);
			break;
		case 0x41554420: // AUD
			nox_thing_read_audio_502320(things, v3);
			break;
		case 0x41564E54: // AVNT
			nox_thing_read_AVNT_502120(things, v3);
			break;
		case 0x57414C4C: // WALL
			if (!nox_thing_read_WALL_414F60(things, v3)) {
				nox_memfile_free(things);
				return 0;
			}
			break;
		case 0x464C4F52: // FLOR
			if (!nox_thing_read_FLOR_414DB0(things)) {
				nox_memfile_free(things);
				return 0;
			}
			break;
		case 0x45444745: // EDGE
			if (!nox_thing_read_EDGE_414E70(things, v3)) {
				nox_memfile_free(things);
				return 0;
			}
			break;
		case 0x494D4147: // IMAG
			nox_thing_read_image_415240(things);
			break;
		case 0x54484E47: // THNG
		{
			nox_objectType_t* typ = calloc(1, sizeof(nox_objectType_t));
			if (!typ) {
				nox_memfile_free(things);
				return 0;
			}
			int n = nox_memfile_read_u8(things);
			nox_memfile_read(v3, 1, n, things);
			*((uint8_t*)v3 + n) = 0;
			typ->id = nox_clone_str(v3);

			typ->ind = *getMemU16Ptr(0x587000, 201384);
			++*getMemU32Ptr(0x587000, 201384);

			typ->field_2 = 0;
			typ->field_3 = -1;
			typ->field_10 = 0x4000;
			typ->mass = 1.0f;
			typ->field_28 = 0;
			typ->field_29 = 30.0f;
			typ->func_damage = nox_xxx_damageDefaultProc_4E0B30;
			typ->func_damage_sound = nox_xxx_soundDefaultDamageSound_532E20;
			typ->func_xfer = nox_xxx_XFerDefault_4F49A0;
			typ->field_30_0 = 0xff;
			if (!nox_thing_read_xxx_4E3220(things, v3, typ)) {
				nox_memfile_free(things);
				return 0;
			}
			if (!typ->field_35) {
				typ->field_8 |= 0x40;
			}
			*((uint16_t*)typ + 10) = typ->ind;
			typ->field_8 |= 0x1000000;
			if (typ->obj_class & 0x400000) {
				typ->mass = 1e10f;
			}
			if (typ->obj_class & 0x1) {
				typ->field_13 = 1.0f;
				typ->field_31 = typ->field_31 + typ->field_31;
				typ->field_32 = typ->field_32 + typ->field_32;
			} else {
				typ->field_13 = 0.5f;
			}
			if (!strcmp(typ->id, "Boulder") || !strcmp(typ->id, "RollingBoulder") ||
				!strcmp(typ->id, "BoulderIndestructible")) {
				typ->field_13 = 0.01f;
				typ->mass = 100.0f;
			}
			if (!strcmp(typ->id, "Rock7")) {
				typ->mass = 0.25f;
			}
			if (typ->obj_class & 0x2) {
				uint32_t* v13 = typ->data_update;
				v13[309] = -1;
				v13[307] = -1;
				v13[317] = -1;
			} else if (typ->obj_class & 0x200) {
				uint32_t* v14 = typ->data_update;
				v14[6] = -1;
				v14[8] = -1;
				v14[4] = -1;
			} else if (typ->obj_class & 0x800) {
				*(uint32_t*)((uint32_t)(typ->field_36) + 4) = -1;
			}
			if (typ->obj_class & 0x3000006) {
				if (!typ->field_34) {
					typ->field_34 = calloc(1, 20);
					if (!typ->field_34) {
						return 0;
					}
				}
			}
			typ->field_4 = 1;
			typ->mass *= 10.0f;
			dword_5d4594_1563664 ^= nox_xxx_unitDefProtectMB_4E31A0(typ);
			typ->next = nox_xxx_objectTypes_head_1563660;
			nox_xxx_objectTypes_head_1563660 = typ;
			nox_xxx_unitDefByAlphabetAdd_4E3080(typ->id);
			v3 = v21;
			break;
		}
		}
	}
	*getMemU32Ptr(0x85B3FC, 960) = 1;
	if (nox_loaded_thing_bin) {
		if (nox_common_gameFlags_check_40A5C0(2) && *getMemU32Ptr(0x85B3FC, 4)) {
			nox_free_thing_bin();
		}
	} else {
		nox_memfile_free(things);
	}
	if (!nox_xxx_objectTypes_allFit_4E3110()) {
		return 0;
	}
	nox_xxx_protectUnitDefUpdateMB_4E3C20();
	result = calloc(*getMemU32Ptr(0x587000, 201384), 4);
	*getMemU32Ptr(0x5D4594, 1563456) = result;
	if (!result) {
		return 0;
	}
	nox_xxx_unitDefByAlphabetInit_4E3040();
	v17 = *getMemU32Ptr(0x587000, 201384);
	v18 = nox_xxx_objectTypes_head_1563660;
	v19 = 1;
	for (i = 1; i < *getMemIntPtr(0x587000, 201384); ++i) {
		*(uint32_t*)(*getMemU32Ptr(0x5D4594, 1563456) + 4 * (v17 - v19)) = v18;
		nox_xxx_objectTypeAddToNameInd_4E30D0(v18);
		v17 = *getMemU32Ptr(0x587000, 201384);
		v18 = *(uint32_t*)(v18 + 220);
		v19 = i + 1;
	}
	sub_4E29D0();
	free(v3);
	nox_xxx_equipWeapon_4131A0();
	nox_xxx_equipArmor_415AB0();
	nox_xxx_equipWeapon_4157C0();
	sub_4F0640();
	if (!sub_42BF10()) {
		return 0;
	}
	return 1;
}

//----- (0044C780) --------------------------------------------------------
void* nox_xxx_draw_44C780(int a1) {
	int i;        // esi
	int v2;       // eax
	void* result; // eax

	for (i = 0; i < 32; i += 4) {
		v2 = i;
		if (i >= 16) {
			v2 = i + 4;
		}
		result = *(void**)(v2 + a1);
		if (result) {
			free(result);
		}
	}
	return result;
}

//----- (0044C7B0) --------------------------------------------------------
void* sub_44C7B0(int a1) {
	void** v1;    // ebx
	int v2;       // ebp
	void** v3;    // esi
	int v4;       // edi
	void** v5;    // esi
	int v6;       // edi
	void* result; // eax

	v1 = (void**)(a1 + 52);
	v2 = 55;
	do {
		if (*v1) {
			nox_xxx_draw_44C780((int)*v1 + 4);
			free(*v1);
		}
		v3 = v1 + 1;
		v4 = 26;
		do {
			if (*v3) {
				nox_xxx_draw_44C780((int)*v3 + 4);
				free(*v3);
			}
			++v3;
			--v4;
		} while (v4);
		v5 = v1 + 27;
		v6 = 27;
		do {
			result = *v5;
			if (*v5) {
				nox_xxx_draw_44C780((int)result + 4);
				free(*v5);
			}
			++v5;
			--v6;
		} while (v6);
		v1 += 66;
		--v2;
	} while (v2);
	return result;
}

//----- (0044C650) --------------------------------------------------------
void nox_xxx_draw_44C650_free(void* lpMem, void* draw) {
	int kind = 0;
	if (*(uint32_t*)nox_parse_thing_draw_funcs) {
		nox_parse_thing_draw_funcs_t* item = NULL;
		for (int i = 0; i < nox_parse_thing_draw_funcs_cnt; i++) {
			nox_parse_thing_draw_funcs_t* cur = &nox_parse_thing_draw_funcs[i];
			if (!cur->name) {
				break;
			}
			if (cur->draw == draw) {
				item = cur;
				break;
			}
		}
		if (item) {
			kind = item->kind;
		}
	}
	void** v7 = 0;
	int v8 = 0;
	char* v9 = 0;
	int v10 = 0;
	char* v11 = 0;
	int v12 = 0;

	switch (kind) {
	case 2:
	case 3:
		if (*((uint32_t*)lpMem + 1)) {
			free(*((void**)lpMem + 1));
		}
		free(lpMem);
		break;
	case 4:
		v7 = (void**)((char*)lpMem + 4);
		v8 = 5;
		do {
			if (*v7) {
				free(*v7);
			}
			++v7;
			--v8;
		} while (v8);
		free(lpMem);
		break;
	case 5:
		nox_xxx_draw_44C780((int)lpMem + 4);
		free(lpMem);
		break;
	case 6:
		sub_44C7B0((int)lpMem);
		free(lpMem);
		break;
	case 7:
		v9 = (char*)lpMem + 8;
		v10 = 16;
		do {
			nox_xxx_draw_44C780((int)v9);
			v9 += 48;
			--v10;
		} while (v10);
		free(lpMem);
		break;
	case 8:
		v11 = (char*)lpMem + 8;
		v12 = 3;
		do {
			nox_xxx_draw_44C780((int)v11);
			v11 += 48;
			--v12;
		} while (v12);
		free(lpMem);
		break;
	default:
		free(lpMem);
		break;
	}
}

//----- (0044C580) --------------------------------------------------------
void nox_things_free_44C580() {
	if (nox_things_head) {
		nox_thing* cur = nox_things_head;
		while (cur) {
			if (cur->name) {
				free(cur->name);
			}
			if (cur->field_5c) {
				nox_xxx_draw_44C650_free(cur->field_5c, cur->draw_func);
			}
			nox_thing* next = cur->next;
			free(cur);
			cur = next;
		}
	}
	nox_things_head = NULL;
	if (nox_things_array) {
		free(nox_things_array);
		nox_things_array = NULL;
	}
	nox_things_count = 0;
	sub_44C620_free();
	if (!nox_common_gameFlags_check_40A5C0(1)) {
		nox_xxx_free_42BF80();
	}
}
