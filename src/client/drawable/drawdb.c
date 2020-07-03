#include "drawdb.h"
#include "drawable.h"
#include "../draw/debugdraw.h"

#include "../../proto.h"

extern int nox_things_count;
extern nox_thing* nox_things_head;
extern nox_thing** nox_things_array;
extern nox_memfile* nox_loaded_thing_bin;

extern _QWORD qword_581450_9544;
extern _QWORD qword_581450_9552;
extern _DWORD dword_5d4594_251568;
extern _DWORD dword_5d4594_251572;
extern _DWORD dword_5d4594_251600;
extern _DWORD dword_5d4594_251608;
extern _DWORD dword_5d4594_741676;
extern _DWORD dword_5d4594_741680;
extern _DWORD dword_5d4594_1563660;
extern _DWORD dword_5d4594_1563664;

bool __cdecl nox_parse_thing_flags(nox_thing* obj, nox_memfile* f, const char* attr_value);
bool __cdecl nox_parse_thing_class(nox_thing* obj, nox_memfile* f, const char* attr_value);
bool __cdecl nox_parse_thing_subclass(nox_thing* obj, nox_memfile* f, const char* attr_value);
bool __cdecl nox_parse_thing_extent(nox_thing* obj, nox_memfile* f, char* attr_value);
bool __cdecl nox_parse_thing_light_intensity(nox_thing* obj, nox_memfile* f, char* attr_value);
bool __cdecl nox_parse_thing_draw(nox_thing* obj, nox_memfile* f, char* attr_value);
bool __cdecl nox_parse_thing_z(nox_thing* obj, nox_memfile* f, char* attr_value);
bool __cdecl nox_parse_thing_zsize(nox_thing* obj, nox_memfile* f, char* attr_value);
bool __cdecl nox_parse_thing_size(nox_thing* obj, nox_memfile* f, char* attr_value);
bool __cdecl nox_parse_thing_menu_icon(nox_thing* obj, nox_memfile* f, char* attr_value);
bool __cdecl nox_parse_thing_light_color(nox_thing* obj, nox_memfile* f, char* attr_value);
bool __cdecl nox_parse_thing_light_dir(nox_thing* obj, nox_memfile* f, char* attr_value);
bool __cdecl nox_parse_thing_light_penumbra(nox_thing* obj, nox_memfile* f, char* attr_value);
bool __cdecl nox_parse_thing_audio_loop(nox_thing* obj, nox_memfile* f, char* attr_value);
bool __cdecl nox_parse_thing_client_update(nox_thing* obj, nox_memfile* f, char* attr_value);
bool __cdecl nox_parse_thing_lifetime(nox_thing* obj, nox_memfile* f, char* attr_value);
bool __cdecl nox_parse_thing_weight(nox_thing* obj, nox_memfile* f, char* attr_value);
bool __cdecl nox_parse_thing_pretty_name(nox_thing* obj, nox_memfile* f, char* attr_value);
bool __cdecl nox_parse_thing_desc(nox_thing* obj, nox_memfile* f, char* attr_value);
bool __cdecl nox_parse_thing_pretty_image(nox_thing* obj, nox_memfile* f, char* attr_value);
bool __cdecl nox_parse_thing_health(nox_thing* obj, nox_memfile* f, char* attr_value);

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
bool __cdecl nox_parse_thing_flags(nox_thing* obj, nox_memfile* f, const char* attr_value) {
	obj->flags = 0;
	set_bitmask_flags_from_plus_separated_names_423930(attr_value, &obj->flags, (const char**)&byte_587000[114076]);
	return 1;
}

//----- (0044B190) --------------------------------------------------------
bool __cdecl nox_parse_thing_class(nox_thing* obj, nox_memfile* f, const char* attr_value) {
	obj->pri_class = 0;
	set_bitmask_flags_from_plus_separated_names_423930(attr_value, &obj->pri_class, (const char**)&byte_587000[114208]);
	return 1;
}

//----- (0044B1C0) --------------------------------------------------------
bool __cdecl nox_parse_thing_subclass(nox_thing* obj, nox_memfile* f, const char* attr_value) {
	obj->sub_class = 0;
	set_bitmask_flags_from_plus_separated_names_multiple_423A10(attr_value, &obj->sub_class);
	return 1;
}

//----- (0044B1F0) --------------------------------------------------------
bool __cdecl nox_parse_thing_extent(nox_thing* obj, nox_memfile* f, char* attr_value) {
	nox_shape s;
	bool res = nox_parse_shape(&s, attr_value);
	obj->shape_kind = s.kind;
	obj->shape_r = s.circle_r;
	obj->shape_w = s.box_w;
	obj->shape_h = s.box_h;
	return res;
}

//----- (0044B230) --------------------------------------------------------
bool __cdecl nox_parse_thing_light_intensity(nox_thing* obj, nox_memfile* f, char* attr_value) {
	sscanf(attr_value, "%f", &obj->light_intensity);
	return 1;
}

//----- (0044C200) --------------------------------------------------------
bool __cdecl nox_parse_thing_draw(nox_thing* obj, nox_memfile* f, char* attr_value) {
	const uint8_t read_len = nox_memfile_read_u8(f);

	char read_str[256];
	nox_memfile_read(read_str, 1u, read_len, f);
	read_str[read_len] = 0;

	// TODO: After cleanup: Figure out if this value has any significance to the data in the file, or if the file was
	// simply 16byte-aligned
	uint32_t tmp;
	sub_40AD60((char*)&tmp, sizeof(tmp), 1, f);

	if (!*(_DWORD*)nox_parse_thing_draw_funcs) {
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
bool __cdecl nox_parse_thing_z(nox_thing* obj, nox_memfile* f, char* attr_value) {
	int z = 0;
	sscanf(attr_value, "%d", &z);
	obj->z = z;
	return 1;
}

//----- (0044C320) --------------------------------------------------------
bool __cdecl nox_parse_thing_zsize(nox_thing* obj, nox_memfile* f, char* attr_value) {
	int min = 0;
	int max = 0;
	sscanf(attr_value, "%d %d", &min, &max);
	if (max < min)
		max = min;
	obj->zsize_min = (double)min;
	obj->zsize_max = (double)max;
	return 1;
}

//----- (0044C370) --------------------------------------------------------
bool __cdecl nox_parse_thing_size(nox_thing* obj, nox_memfile* f, char* attr_value) {
	int w = 0;
	int h = 0;
	sscanf(attr_value, "%d %d", &w, &h);
	obj->hwidth = w / 2;
	obj->hheight = h / 2;
	return 1;
}

//----- (0044C3B0) --------------------------------------------------------
bool __cdecl nox_parse_thing_menu_icon(nox_thing* obj, nox_memfile* f, char* attr_value) {
	obj->menuicon = nox_memfile_read_u32(f);
	if (obj->menuicon == -1) {
		// TODO: This branch doesnt seem to ever be taken. It roughly translates to the following, but the meaning is
		// not clear:
		/*
		// Drop one byte, read one byte (sz), skip sz+1 bytes. Is this reading (and dropping) a string?
		const uint8_t skip = nox_memfile_read_u8(f);
		const uint8_t sz = nox_memfile_read_u8(f);
		printf("skipped %d, sz %d\n", skip, sz);
		f->cur += (sz + 1);
		 */
		unsigned __int8* p = (unsigned __int8*)(f->cur + 1);
		f->cur = p;
		int sz = *p;
		f->cur = &p[sz + 1];
	}
	return 1;
}

//----- (0044B250) --------------------------------------------------------
bool __cdecl nox_parse_thing_light_color(nox_thing* obj, nox_memfile* f, char* attr_value) {
	int r;
	int g;
	int b;
	if (sscanf(attr_value, "%d %d %d", &r, &g, &b) != 3)
		return 0;
	obj->field_f = 2;
	obj->light_color_r = (r <= 255 ? r : 255);
	obj->light_color_g = (g <= 255 ? g : 255);
	obj->light_color_b = (b <= 255 ? b : 255);
	return 1;
}

//----- (0044B2D0) --------------------------------------------------------
bool __cdecl nox_parse_thing_light_dir(nox_thing* obj, nox_memfile* f, char* attr_value) {
	int deg = 0;
	if (sscanf(attr_value, "%d", &deg) != 1)
		return 0;
	if (deg < 0 || deg >= 360)
		return 0;
	obj->light_dir = (__int64)((double)deg * *(double*)&byte_581450[9560] * *(double*)&qword_581450_9552 +
							   *(double*)&qword_581450_9544);
	obj->field_10 = 0;
	return 1;
}

//----- (0044B330) --------------------------------------------------------
bool __cdecl nox_parse_thing_light_penumbra(nox_thing* obj, nox_memfile* f, char* attr_value) {
	int deg = 0;
	if (sscanf(attr_value, "%d", &deg) != 1)
		return 0;
	if (deg < 0 || deg >= 180)
		return 0;
	obj->light_penumbra = (__int64)((double)deg * *(double*)&byte_581450[9560] * *(double*)&qword_581450_9552 +
									*(double*)&qword_581450_9544);
	return 1;
}

// 44C200: using guessed type char var_100[256];

//----- (0044C3F0) --------------------------------------------------------
bool __cdecl nox_parse_thing_audio_loop(nox_thing* obj, nox_memfile* f, char* attr_value) {
	obj->audio_loop = sub_40AF50(attr_value);
	return 1;
}

//----- (004B5C40) --------------------------------------------------------
bool __cdecl nox_parse_thing_client_update(nox_thing* obj, nox_memfile* f, char* attr_value) {
	char* v3;            // eax
	const char* v4;      // ecx
	int v5;              // ebp
	unsigned __int8* v6; // edi

	v3 = strtok(attr_value, " \t\n\r");
	v4 = *(const char**)&byte_587000[175072];
	v5 = 0;
	if (*(_DWORD*)&byte_587000[175072]) {
		v6 = &byte_587000[175072];
		do {
			if (!strcmp(v4, v3))
				break;
			v4 = (const char*)*((_DWORD*)v6 + 2);
			v6 += 8;
			++v5;
		} while (v4);
	}
	if (!*(_DWORD*)&byte_587000[8 * v5 + 175072])
		return 0;
	obj->client_update = *(_DWORD*)&byte_587000[8 * v5 + 175076];
	return 1;
}

//----- (0044C410) --------------------------------------------------------
bool __cdecl nox_parse_thing_lifetime(nox_thing* obj, nox_memfile* f, char* attr_value) {
	int v = 0;
	sscanf(attr_value, "%d", &v);
	obj->lifetime = v;
	return 1;
}

//----- (0044C440) --------------------------------------------------------
bool __cdecl nox_parse_thing_weight(nox_thing* obj, nox_memfile* f, char* attr_value) {
	int v = 0;
	sscanf(attr_value, "%d", &v);
	obj->weight = (_BYTE)v;
	obj->pri_class |= 0x80000000;
	return 1;
}

//----- (0044C480) --------------------------------------------------------
bool __cdecl nox_parse_thing_pretty_name(nox_thing* obj, nox_memfile* f, char* attr_value) {
	obj->pretty_name = loadString_sub_40F1D0(attr_value, 0, "C:\\NoxPost\\src\\Client\\Drawable\\drawdb.c", 1396);
	return 1;
}

//----- (0044C4B0) --------------------------------------------------------
bool __cdecl nox_parse_thing_desc(nox_thing* obj, nox_memfile* f, char* attr_value) {
	obj->desc = loadString_sub_40F1D0(attr_value, 0, "C:\\NoxPost\\src\\Client\\Drawable\\drawdb.c", 1403);
	return 1;
}

//----- (0044C500) --------------------------------------------------------
bool __cdecl nox_parse_thing_pretty_image(nox_thing* obj, nox_memfile* f, char* attr_value) {
	char v10[128];

	const uint32_t known_idx = nox_memfile_read_u32(f);
	if (known_idx != -1) {
		obj->pretty_image = sub_42FAA0(known_idx, 0, v10);
		return 1;
	}

	// TODO: After cleanup: This branch appears to never be taken. Figure out what these values are.
	const int v8 = nox_memfile_read_u8(f);
	const int n = nox_memfile_read_u8(f);
	nox_memfile_read(v10, 1u, n, f);
	obj->pretty_image = sub_42FAA0(known_idx, v8, v10);
	return 1;
}

//----- (0044C4E0) --------------------------------------------------------
bool __cdecl nox_parse_thing_health(nox_thing* obj, nox_memfile* f, char* attr_value) {
	obj->health = atoi(attr_value);
	return 1;
}

//----- (0044CE00) --------------------------------------------------------
int __cdecl nox_parse_thing(nox_memfile* thing_file, char* scratch_buffer, nox_thing* thing) {
	unsigned __int8 entry_len;
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
int sub_44CCA0() {
	int result; // eax

	result = 0;
	memset(&byte_5D4594[830616], 0, 0x6Cu);
	memset(&byte_5D4594[830724], 0, 0x6Cu);
	memset(&byte_5D4594[830296], 0, 0x6Cu);
	return result;
}

//----- (00485CF0) --------------------------------------------------------
int sub_485CF0() {
	int v0;     // edi
	LPVOID* v1; // esi

	v0 = 0;
	if (*(int*)&dword_5d4594_251568 <= 0)
		return 1;
	v1 = (LPVOID*)&byte_5D4594[2682220];
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
	int v0;     // edi
	LPVOID* v1; // esi

	v0 = 0;
	if (*(int*)&dword_5d4594_251572 <= 0)
		return 1;
	v1 = (LPVOID*)&byte_5D4594[2678380];
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
	int i;               // ebx
	int v1;              // edx
	int v2;              // esi
	unsigned __int8* v3; // edi

	for (i = 0; i < 986560; i += 12332) {
		v1 = 0;
		do {
			v2 = 15;
			do {
				v3 = &byte_5D4594[i + 2701180 + v1];
				v1 += 64;
				--v2;
				memset(v3, 0, 0x40u);
			} while (v2);
		} while (v1 < 3840);
	}
	return 1;
}

//----- (0044CCD0) --------------------------------------------------------
size_t sub_44CCD0() {
	int i;         // esi
	size_t result; // eax

	for (i = 0; i < 108; i += 4) {
		result = *(_DWORD*)&byte_5D4594[i + 830616];
		if (result) {
			result = (size_t)nox_calloc(1u, 8 * result);
			*(_DWORD*)&byte_5D4594[i + 830296] = result;
		} else {
			*(_DWORD*)&byte_5D4594[i + 830296] = 0;
		}
		*(_DWORD*)&byte_5D4594[i + 830724] = 0;
	}
	return result;
}

//----- (0044CD60) --------------------------------------------------------
void __cdecl sub_44CD60(nox_thing* a1, int a2) {
	if (!a1)
		return;

	int v2 = sub_44CD30(a1->name);
	if (v2 < 0)
		return;

	int v3 = *(_DWORD*)&byte_5D4594[4 * v2 + 830296];
	if (!v3)
		return;

	int v4 = *(_DWORD*)&byte_5D4594[4 * v2 + 830724];
	*(_DWORD*)(v3 + 8 * v4) = a1;
	*(_DWORD*)(v3 + 8 * v4 + 4) = a2;
	++*(_DWORD*)&byte_5D4594[4 * v2 + 830724];
}

//----- (0044CDE0) --------------------------------------------------------
int __cdecl sub_44CDE0(const void* a1, const void* a2) { return _strcmpi(**(const char***)a1, **(const char***)a2); }

//----- (0044CDB0) --------------------------------------------------------
void sub_44CDB0() {
	int i;         // esi
	signed int v1; // eax

	for (i = 0; i < 108; i += 4) {
		v1 = *(_DWORD*)&byte_5D4594[i + 830616];
		if (v1 > 1)
			qsort(*(void**)&byte_5D4594[i + 830296], v1, 8u, sub_44CDE0);
	}
}

//----- (004131A0) --------------------------------------------------------
CHAR* sub_4131A0() {
	CHAR* result; // eax
	int i;        // esi
	int j;        // esi

	result = *(CHAR**)&byte_5D4594[251616];
	if (*(_DWORD*)&byte_5D4594[251616] != 1) {
		for (i = dword_5d4594_251600; i; i = *(_DWORD*)(i + 80)) {
			if (nox_common_gameFlags_check_40A5C0(2097153)) {
				result = (CHAR*)sub_4E3AA0(*(CHAR**)i);
			} else {
				result = (CHAR*)nox_common_gameFlags_check_40A5C0(2);
				if (!result)
					return result;
				result = (CHAR*)sub_44CFC0(*(CHAR**)i);
			}
			*(_DWORD*)(i + 4) = result;
		}
		for (j = dword_5d4594_251608; j; j = *(_DWORD*)(j + 80)) {
			if (nox_common_gameFlags_check_40A5C0(2097153)) {
				result = (CHAR*)sub_4E3AA0(*(CHAR**)j);
			} else {
				result = (CHAR*)nox_common_gameFlags_check_40A5C0(2);
				if (!result)
					return result;
				result = (CHAR*)sub_44CFC0(*(CHAR**)j);
			}
			*(_DWORD*)(j + 4) = result;
		}
		*(_DWORD*)&byte_5D4594[251616] = 1;
	}
	return result;
}

//----- (00415AB0) --------------------------------------------------------
void sub_415AB0() {
	unsigned __int8* v0; // esi
	int v1;              // eax
	int v2;              // eax

	if (*(_DWORD*)&byte_5D4594[371252] != 1) {
		if (*(_DWORD*)&byte_587000[34848]) {
			v0 = &byte_587000[34864];
			do {
				if (nox_common_gameFlags_check_40A5C0(2097153)) {
					*((_DWORD*)v0 - 2) = sub_4E3AA0(*((CHAR**)v0 - 4));
					v1 = sub_4E3AA0(*(CHAR**)v0);
				} else {
					*((_DWORD*)v0 - 2) = sub_44CFC0(*((CHAR**)v0 - 4));
					v1 = sub_44CFC0(*(CHAR**)v0);
				}
				*((_DWORD*)v0 + 1) = v1;
				v2 = *((_DWORD*)v0 + 2);
				v0 += 24;
			} while (v2);
		}
		*(_DWORD*)&byte_5D4594[371252] = 1;
	}
}

//----- (004157C0) --------------------------------------------------------
void sub_4157C0() {
	unsigned __int8* v0; // esi
	int v1;              // eax
	int v2;              // eax

	if (*(_DWORD*)&byte_5D4594[371244] != 1) {
		if (*(_DWORD*)&byte_587000[33064]) {
			v0 = &byte_587000[33064];
			do {
				if (nox_common_gameFlags_check_40A5C0(2097153))
					v1 = sub_4E3AA0(*(CHAR**)v0);
				else
					v1 = sub_44CFC0(*(CHAR**)v0);
				*((_DWORD*)v0 + 1) = v1;
				v2 = *((_DWORD*)v0 + 3);
				v0 += 12;
			} while (v2);
		}
		*(_DWORD*)&byte_5D4594[371244] = 1;
	}
}

//----- (0044D390) --------------------------------------------------------
int nox_get_things_count() { return nox_things_count; }

//----- (0042BF10) --------------------------------------------------------
int sub_42BF10() {
	int v1; // eax

	if (dword_5d4594_741676)
		return 1;
	if (nox_common_gameFlags_check_40A5C0(2097153)) {
		v1 = sub_4E3AC0();
	} else {
		if (!nox_common_gameFlags_check_40A5C0(2))
			return 0;
		v1 = nox_get_things_count();
	}
	dword_5d4594_741680 = v1;
	dword_5d4594_741676 = nox_malloc(2 * v1);
	if (dword_5d4594_741676) {
		sub_42BFB0();
		return 1;
	}
	return 0;
}

//----- (0044C840) --------------------------------------------------------
void* __cdecl sub_44C840_read_things(void) {
	char* scratch_buffer = (char*)nox_malloc(256 * 1024);
	sub_44CCA0();
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
			nox_thing_read_spells_415100(things);
			break;
		case 0x4142494C: // "ABIL"
			nox_thing_read_ability_415320(things);
			break;
		case 0x41554420: // "AUD "
			nox_thing_read_audio_414D40(things);
			break;
		case 0x41564E54: // "AVNT"
			nox_thing_read_AVNT_452B00(things);
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
			nox_thing* obj = (nox_thing*)nox_calloc(1, sizeof(nox_thing));
			if (!obj) {
				return 0;
			}
			unsigned __int8 v28 = *(unsigned __int8*)things->cur;
			things->cur++;
			nox_memfile_read(scratch_buffer, 1u, v28, things);
			scratch_buffer[v28] = 0;
			obj->name = nox_clone_str(scratch_buffer);
			obj->menuicon = -1;
			obj->field_1c = nox_things_count++;
			obj->flags |= 0x1000000;
			*((_BYTE*)obj + 15) = 0;
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
			sub_44CD10(obj->name);
			break;
		}
	}
	*(_DWORD*)&byte_5D4594[2649708] = 1;
	if (nox_loaded_thing_bin) {
		if (nox_common_gameFlags_check_40A5C0(1) && *(_DWORD*)&byte_5D4594[2650664]) {
			nox_free_thing_bin();
		}
	} else {
		nox_memfile_free(things);
	}
	void* result = nox_malloc(sizeof(nox_thing*) * nox_things_count);
	nox_things_array = result;
	if (result) {
		sub_44CCD0();
		nox_thing* cur = nox_things_head;
		for (int i = 1; i < nox_things_count; i++) {
			nox_things_array[nox_things_count - i] = cur;
			sub_44CD60(cur, nox_things_count - i);
			if (*((_BYTE*)cur + 0xe)) {
				// The large amount of logic in the following two branches is due to copying strings as WORDs.
				// If not loaded, set cur->pretty_name = load_string "thing.db:${cur->name}PrettyName"
				if (!cur->pretty_name) {
					strcpy((char*)&byte_5D4594[830404], "thing.db:");
					CHAR* cur_name = cur->name;
					unsigned int cur_name_len_plus_one = strlen(cur->name) + 1;
					unsigned __int8* v11 = &byte_5D4594[strlen((const char*)&byte_5D4594[830404]) + 830404];
					qmemcpy(v11, cur->name, 4 * (cur_name_len_plus_one >> 2));
					CHAR* v13 = &cur_name[4 * (cur_name_len_plus_one >> 2)];
					unsigned __int8* v12 = &v11[4 * (cur_name_len_plus_one >> 2)];
					char v14 = cur_name_len_plus_one;
					LOWORD(cur_name_len_plus_one) = *(_WORD*)&byte_587000[122728];
					qmemcpy(v12, v13, v14 & 3);
					unsigned __int8* v15 = &byte_5D4594[strlen((const char*)&byte_5D4594[830404]) + 830405];
					int v16 = *(_DWORD*)&byte_587000[122724];
					*(_DWORD*)--v15 = *(_DWORD*)&byte_587000[122720];
					unsigned __int8 v17 = byte_587000[122730];
					*((_DWORD*)v15 + 1) = v16;
					*((_WORD*)v15 + 4) = cur_name_len_plus_one;
					v15[10] = v17;
					cur->pretty_name = loadString_sub_40F1D0((char*)&byte_5D4594[830404], 0,
															 "C:\\NoxPost\\src\\Client\\Drawable\\drawdb.c", 1926);
				}
				// if not loaded, set cur->desc = load_string "thing.db:${cur->name}Description"
				if (!cur->desc) {
					strcpy((char*)&byte_5D4594[830404], "thing.db:");
					CHAR* v18 = cur->name;
					unsigned int v19 = strlen(cur->name) + 1;
					unsigned __int8* v20 = &byte_5D4594[strlen((const char*)&byte_5D4594[830404]) + 830404];
					qmemcpy(v20, cur->name, 4 * (v19 >> 2));
					CHAR* v22 = &v18[4 * (v19 >> 2)];
					unsigned __int8* v21 = &v20[4 * (v19 >> 2)];
					char v23 = v19;
					int v24 = *(_DWORD*)&byte_587000[122792];
					qmemcpy(v21, v22, v23 & 3);
					unsigned __int8* v25 = &byte_5D4594[strlen((const char*)&byte_5D4594[830404]) + 830405];
					int v26 = *(_DWORD*)&byte_587000[122788];
					*(_DWORD*)--v25 = *(_DWORD*)&byte_587000[122784];
					*((_DWORD*)v25 + 1) = v26;
					*((_DWORD*)v25 + 2) = v24;
					cur->desc = loadString_sub_40F1D0((char*)&byte_5D4594[830404], 0,
													  "C:\\NoxPost\\src\\Client\\Drawable\\drawdb.c", 1933);
				}
			}
			cur = cur->next;
		}
		sub_44CDB0();
		free(scratch_buffer);
		sub_4131A0();
		sub_415AB0();
		sub_4157C0();
		result = (void*)(sub_42BF10() != 0);
	}
	return result;
}

//----- (0044C620) --------------------------------------------------------
void sub_44C620_free() {
	LPVOID* v0; // esi

	v0 = (LPVOID*)&byte_5D4594[830296];
	do {
		if (*v0)
			free(*v0);
		*v0 = 0;
		++v0;
	} while ((int)v0 < (int)&byte_5D4594[830404]);
}

//----- (004E2B30) --------------------------------------------------------
LPVOID sub_4E2B30() {
	LPVOID* v0;    // esi
	LPVOID result; // eax

	v0 = (LPVOID*)&byte_5D4594[1563348];
	do {
		result = *v0;
		if (*v0)
			free(*v0);
		*v0 = 0;
		++v0;
	} while ((int)v0 < (int)&byte_5D4594[1563456]);
	return result;
}

//----- (0042BF80) --------------------------------------------------------
LPVOID sub_42BF80() {
	LPVOID result; // eax

	result = *(LPVOID*)&dword_5d4594_741676;
	if (dword_5d4594_741676) {
		free(*(LPVOID*)&dword_5d4594_741676);
		dword_5d4594_741676 = 0;
	}
	dword_5d4594_741680 = 0;
	return result;
}

//----- (004E2A20) --------------------------------------------------------
int sub_4E2A20() {
	int v0;   // esi
	int v1;   // ebp
	int v2;   // eax
	void* v3; // eax

	v0 = dword_5d4594_1563660;
	if (dword_5d4594_1563660) {
		do {
			v1 = *(_DWORD*)(v0 + 220);
			if (*(_DWORD*)(v0 + 4))
				free(*(LPVOID*)(v0 + 4));
			if (*(_DWORD*)(v0 + 136))
				free(*(LPVOID*)(v0 + 136));
			if (*(_DWORD*)(v0 + 144))
				free(*(LPVOID*)(v0 + 144));
			if (*(_DWORD*)(v0 + 164))
				free(*(LPVOID*)(v0 + 164));
			if (*(_DWORD*)(v0 + 176))
				free(*(LPVOID*)(v0 + 176));
			v2 = *(_DWORD*)(v0 + 192);
			if (v2) {
				if (*(_BYTE*)(v0 + 24) & 2) {
					v3 = *(void**)(v2 + 476);
					if (v3)
						free(v3);
				}
				free(*(LPVOID*)(v0 + 192));
			}
			if (*(_DWORD*)(v0 + 204))
				free(*(LPVOID*)(v0 + 204));
			free((LPVOID)v0);
			v0 = v1;
		} while (v1);
	}
	dword_5d4594_1563660 = 0;
	if (*(_DWORD*)&byte_5D4594[1563456]) {
		free(*(LPVOID*)&byte_5D4594[1563456]);
		*(_DWORD*)&byte_5D4594[1563456] = 0;
	}
	*(_DWORD*)&byte_587000[201384] = 1;
	sub_4E2B30();
	sub_42BF80();
	return 1;
}

//----- (004E3010) --------------------------------------------------------
int sub_4E3010() {
	int result; // eax

	result = 0;
	memset(&byte_5D4594[1563668], 0, 0x6Cu);
	memset(&byte_5D4594[1563776], 0, 0x6Cu);
	memset(&byte_5D4594[1563348], 0, 0x6Cu);
	return result;
}

//----- (004E3080) --------------------------------------------------------
CHAR* __cdecl sub_4E3080(CHAR* a1) {
	CHAR* result; // eax

	result = a1;
	if (a1) {
		result = (CHAR*)sub_4E30A0(a1);
		if ((int)result >= 0)
			++*(_DWORD*)&byte_5D4594[4 * (_DWORD)result + 1563668];
	}
	return result;
}

//----- (004E3110) --------------------------------------------------------
int sub_4E3110() {
	int ret = 1;

	for (char* cur = (char*)sub_4E3B30(); cur; cur = (char*)sub_4E3B40((int)cur)) {
		char char_0x20 = *((char*)cur + 32);
		if ((char_0x20 & 0x40) != 0) {
			continue;
		}

		int dword_0x3c = *((_DWORD*)cur + 15);
		float dword_0x40 = *((float*)cur + 16);
		float dword_0x54 = *((float*)cur + 21);
		float dword_0x58 = *((float*)cur + 22);
		float dword_0x60 = *((float*)cur + 24);
		float dword_0x6c = *((float*)cur + 27);
		nox_shape* p_shape_0x3c = (nox_shape*)(cur + 60);
		if (dword_0x3c == 2) {
			if (dword_0x40 + dword_0x40 >= 85.0) {
				ret = 0;
			}
		} else if (dword_0x3c == 3) {
			nox_shape_box_calc(p_shape_0x3c);

			if (dword_0x60 - dword_0x58 >= 85.0 || dword_0x6c - dword_0x54 >= 85.0) {
				ret = 0;
			}
		}
	}

	return ret;
}

//----- (004E3040) --------------------------------------------------------
size_t sub_4E3040() {
	int i;         // esi
	size_t result; // eax

	for (i = 0; i < 108; i += 4) {
		result = *(_DWORD*)&byte_5D4594[i + 1563668];
		if (result) {
			result = (size_t)nox_calloc(1u, 4 * result);
			*(_DWORD*)&byte_5D4594[i + 1563348] = result;
		} else {
			*(_DWORD*)&byte_5D4594[i + 1563348] = 0;
		}
		*(_DWORD*)&byte_5D4594[i + 1563776] = 0;
	}
	return result;
}

//----- (004E30D0) --------------------------------------------------------
void __cdecl sub_4E30D0(int a1) {
	int v1; // eax
	int v2; // ecx

	if (a1) {
		v1 = sub_4E30A0(*(CHAR**)(a1 + 4));
		v2 = *(_DWORD*)&byte_5D4594[4 * v1 + 1563348];
		if (v2) {
			*(_DWORD*)(v2 + 4 * *(_DWORD*)&byte_5D4594[4 * v1 + 1563776]) = a1;
			++*(_DWORD*)&byte_5D4594[4 * v1 + 1563776];
		}
	}
}

//----- (004E2A00) --------------------------------------------------------
int __cdecl sub_4E2A00(const void* a1, const void* a2) {
	return _strcmpi(*(const char**)(*(_DWORD*)a1 + 4), *(const char**)(*(_DWORD*)a2 + 4));
}
//----- (004E29D0) --------------------------------------------------------
void sub_4E29D0() {
	int i;         // esi
	signed int v1; // eax

	for (i = 0; i < 108; i += 4) {
		v1 = *(_DWORD*)&byte_5D4594[i + 1563668];
		if (v1 > 1)
			qsort(*(void**)&byte_5D4594[i + 1563348], v1, 4u, sub_4E2A00);
	}
}

//----- (004F0640) --------------------------------------------------------
const char* sub_4F0640() {
	char* v0;             // eax
	unsigned __int8* v1;  // esi
	char v2;              // cl
	CHAR* v3;             // eax
	const char* v4;       // eax
	unsigned __int8* v5;  // esi
	int v6;               // eax
	const char* v7;       // eax
	unsigned __int8* v8;  // esi
	int v9;               // eax
	const char* v10;      // eax
	unsigned __int8* v11; // esi
	int v12;              // eax
	const char* result;   // eax
	unsigned __int8* v14; // esi
	int v15;              // eax

	v0 = *(char**)&byte_587000[208180];
	if (*(_DWORD*)&byte_587000[208180]) {
		v1 = &byte_587000[208180];
		do {
			v2 = *v0;
			v3 = *(CHAR**)v1;
			if (v2 == 35)
				++v3;
			*((_DWORD*)v1 + 1) = sub_4E3AA0(v3);
			v0 = (char*)*((_DWORD*)v1 + 5);
			v1 += 20;
		} while (v0);
	}
	v4 = *(const char**)&byte_587000[210712];
	if (*(_DWORD*)&byte_587000[210712]) {
		v5 = &byte_587000[210712];
		do {
			v6 = sub_413290(v4);
			*((_DWORD*)v5 - 1) = sub_413330(v6);
			v4 = (const char*)*((_DWORD*)v5 + 6);
			v5 += 24;
		} while (v4);
	}
	v7 = *(const char**)&byte_587000[210856];
	if (*(_DWORD*)&byte_587000[210856]) {
		v8 = &byte_587000[210856];
		do {
			v9 = sub_413290(v7);
			*((_DWORD*)v8 - 1) = sub_413330(v9);
			v7 = (const char*)*((_DWORD*)v8 + 6);
			v8 += 24;
		} while (v7);
	}
	v10 = *(const char**)&byte_587000[211000];
	if (*(_DWORD*)&byte_587000[211000]) {
		v11 = &byte_587000[211000];
		do {
			v12 = sub_413290(v10);
			*((_DWORD*)v11 - 1) = sub_413330(v12);
			v10 = (const char*)*((_DWORD*)v11 + 6);
			v11 += 24;
		} while (v10);
	}
	result = *(const char**)&byte_587000[209344];
	if (*(_DWORD*)&byte_587000[209344]) {
		v14 = &byte_587000[209344];
		do {
			v15 = sub_413290(result);
			*((_DWORD*)v14 - 1) = sub_413330(v15);
			result = (const char*)*((_DWORD*)v14 + 6);
			v14 += 24;
		} while (result);
	}
	return result;
}

//----- (004E2B60) --------------------------------------------------------
void* __cdecl nox_read_things_alternative_4E2B60(void) {
	void* v1;            // eax
	void* v3;            // edi
	void* result;        // eax
	void* v5;            // ebp
	int v7;              // eax
	int v8;              // eax
	int v9;              // edx
	double v10;          // st7
	const char* v11;     // eax
	int v12;             // eax
	_DWORD* v13;         // eax
	_DWORD* v14;         // eax
	void* v15;           // eax
	double v16;          // st7
	int v17;             // ecx
	int v18;             // esi
	int v19;             // eax
	int i;               // [esp+0h] [ebp-8h]
	void* v21;           // [esp+4h] [ebp-4h]
	unsigned __int8 v22; // [esp+Ch] [ebp+4h]

	if (dword_5d4594_1563660)
		sub_4E2A20();
	sub_4E3010();
	dword_5d4594_1563664 = 0;
	v1 = nox_malloc(0x40000u);
	v3 = v1;
	v21 = v1;

	nox_memfile* things = nox_open_thing_bin();
	if (!things)
		return 0;
	nox_memfile_seek_40AD10(things, 0, 0);
	while (nox_memfile_read(&i, 4u, 1, things)) {
		switch (i) {
		case 1397769548:
			nox_thing_read_spells_415100(things);
			break;
		case 1094863180:
			nox_thing_read_ability_415320(things);
			break;
		case 1096107040:
			sub_502320(things, v3);
			break;
		case 1096175188:
			sub_502120(things, v3);
			break;
		case 1463897164:
			if (!sub_414F60(things, v3))
				goto LABEL_53;
			break;
		case 1179406162:
			if (!sub_414DB0(things))
				goto LABEL_53;
			break;
		case 1162102597:
			if (!sub_414E70(things, v3))
				goto LABEL_53;
			break;
		case 1229799751:
			nox_thing_read_image_415240(things);
			break;
		case 1414024775:
			v5 = nox_calloc(1u, 0xE0u);
			if (!v5)
				goto LABEL_53;
			v22 = *(unsigned __int8*)things->cur;
			things->cur++;
			nox_memfile_read(v3, 1u, v22, things);
			*((_BYTE*)v3 + v22) = 0;
			*((_DWORD*)v5 + 1) = nox_clone_str((const char*)v3);
			*((_DWORD*)v5 + 2) = 0;
			*(_WORD*)v5 = *(_WORD*)&byte_587000[201384];
			++*(_DWORD*)&byte_587000[201384];
			*((_DWORD*)v5 + 14) = 1065353216;
			*((_BYTE*)v5 + 120) = -1;
			*((_DWORD*)v5 + 28) = 0;
			*((_DWORD*)v5 + 29) = 1106247680;
			*((_DWORD*)v5 + 3) = -1;
			*((_WORD*)v5 + 20) = 0x4000;
			*((_DWORD*)v5 + 38) = sub_4E0B30;
			*((_DWORD*)v5 + 39) = sub_532E20;
			*((_DWORD*)v5 + 53) = sub_4F49A0;
			if (!sub_4E3220(things, (char*)v3, (int)v5)) {
			LABEL_53:
				nox_memfile_free(things);
				return 0;
			}
			if (!*((_DWORD*)v5 + 35)) {
				v7 = *((_DWORD*)v5 + 8);
				LOBYTE(v7) = v7 | 0x40;
				*((_DWORD*)v5 + 8) = v7;
			}
			v8 = *((_DWORD*)v5 + 6);
			v9 = *((_DWORD*)v5 + 8) | 0x1000000;
			*((_WORD*)v5 + 10) = *(_WORD*)v5;
			*((_DWORD*)v5 + 8) = v9;
			if (v8 & 0x400000)
				*((_DWORD*)v5 + 14) = 1343554297;
			if (v8 & 1) {
				v10 = *((float*)v5 + 31) + *((float*)v5 + 31);
				*((_DWORD*)v5 + 13) = 1065353216;
				*((float*)v5 + 31) = v10;
				*((float*)v5 + 32) = *((float*)v5 + 32) + *((float*)v5 + 32);
			} else {
				*((_DWORD*)v5 + 13) = 1056964608;
			}
			v11 = (const char*)*((_DWORD*)v5 + 1);
			if (!strcmp(*((const char**)v5 + 1), "Boulder") || !strcmp(*((const char**)v5 + 1), "RollingBoulder") ||
				!strcmp(*((const char**)v5 + 1), "BoulderIndestructible")) {
				*((_DWORD*)v5 + 13) = 1008981770;
				*((_DWORD*)v5 + 14) = 1120403456;
			}
			if (!strcmp(v11, "Rock7"))
				*((_DWORD*)v5 + 14) = 1048576000;
			v12 = *((_DWORD*)v5 + 6);
			if (v12 & 2) {
				v13 = (_DWORD*)*((_DWORD*)v5 + 48);
				v13[309] = -1;
				v13[307] = -1;
				v13[317] = -1;
			} else if (v12 & 0x200) {
				v14 = (_DWORD*)*((_DWORD*)v5 + 48);
				v14[6] = -1;
				v14[8] = -1;
				v14[4] = -1;
			} else if (v12 & 0x800) {
				*(_DWORD*)(*((_DWORD*)v5 + 36) + 4) = -1;
			}
			if (*((_DWORD*)v5 + 6) & 0x3000006) {
				if (!*((_DWORD*)v5 + 34)) {
					v15 = nox_calloc(1u, 0x14u);
					*((_DWORD*)v5 + 34) = v15;
					if (!v15)
						return 0;
				}
			}
			v16 = *((float*)v5 + 14) * 10.0;
			*((_DWORD*)v5 + 4) = 1;
			*((float*)v5 + 14) = v16;
			dword_5d4594_1563664 ^= sub_4E31A0((int)v5);
			*((_DWORD*)v5 + 55) = dword_5d4594_1563660;
			dword_5d4594_1563660 = v5;
			sub_4E3080(*((CHAR**)v5 + 1));
			v3 = v21;
			break;
		}
	}
	*(_DWORD*)&byte_5D4594[2650664] = 1;
	if (nox_loaded_thing_bin) {
		if (nox_common_gameFlags_check_40A5C0(2) && *(_DWORD*)&byte_5D4594[2649708]) {
			nox_free_thing_bin();
		}
	} else {
		nox_memfile_free(things);
	}
	result = (void*)sub_4E3110();
	if (result) {
		sub_4E3C20();
		result = nox_malloc(4 * *(_DWORD*)&byte_587000[201384]);
		*(_DWORD*)&byte_5D4594[1563456] = result;
		if (result) {
			sub_4E3040();
			v17 = *(_DWORD*)&byte_587000[201384];
			v18 = dword_5d4594_1563660;
			v19 = 1;
			for (i = 1; i < *(int*)&byte_587000[201384]; ++i) {
				*(_DWORD*)(*(_DWORD*)&byte_5D4594[1563456] + 4 * (v17 - v19)) = v18;
				sub_4E30D0(v18);
				v17 = *(_DWORD*)&byte_587000[201384];
				v18 = *(_DWORD*)(v18 + 220);
				v19 = i + 1;
			}
			sub_4E29D0();
			free(v3);
			sub_4131A0();
			sub_415AB0();
			sub_4157C0();
			sub_4F0640();
			result = (void*)(sub_42BF10() != 0);
		}
	}
	return result;
}

//----- (0044C580) --------------------------------------------------------
void nox_things_free_44C580() {
	if (nox_things_head) {
		nox_thing* cur = nox_things_head;
		while (cur) {
			if (cur->name)
				free(cur->name);
			if (cur->field_5c)
				sub_44C650_free(cur->field_5c, cur->draw_func);
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
	if (!nox_common_gameFlags_check_40A5C0(1))
		sub_42BF80();
}
