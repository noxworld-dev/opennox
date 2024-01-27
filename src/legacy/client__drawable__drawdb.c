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
extern uint32_t dword_5d4594_251572;

extern int nox_parse_thing_draw_funcs_cnt;

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

//----- (00485CF0) --------------------------------------------------------
extern uint32_t nox_tile_def_cnt;
extern nox_tileDef_t nox_tile_defs_arr[176];
int nox_free_tile_defs() {
	for (int i = 0; i < nox_tile_def_cnt; i++) {
		nox_tileDef_t* it = &nox_tile_defs_arr[i];
		if (it->data_32) {
			free(it->data_32);
			it->data_32 = 0;
		}
	}
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
void nox_xxx_draw_44C650_free_kind(void* lpMem, int kind) {
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
