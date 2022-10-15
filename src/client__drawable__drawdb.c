#include <stdio.h>

#include "client__draw__debugdraw.h"
#include "client__drawable__drawable.h"

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

extern uint64_t qword_581450_9544;
extern uint64_t qword_581450_9552;
extern uint32_t dword_5d4594_251568;
extern uint32_t dword_5d4594_251572;
extern uint32_t dword_5d4594_251600;
extern uint32_t dword_5d4594_251608;

extern int nox_parse_thing_draw_funcs_cnt;

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

//----- (004F0640) --------------------------------------------------------
int sub_4F0640() {
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
