#include "client__draw__vectdraw.h"
#include "client__draw__parse__parse.h"
#include "common__random.h"
#include "proto.h"

//----- (004BC5D0) --------------------------------------------------------
int __cdecl sub_4BC5D0(nox_drawable* dr, int a2) {
	_DWORD* a1 = dr;
	int result; // eax
	int v3;     // ecx
	int v4;     // ecx

	switch (*(unsigned int*)(a2 + 44)) {
	case 0:
		result = (*getMemUintPtr(0x5D4594, 2598000) - a1[79]) / (unsigned int)(*(__int16*)(a2 + 42) + 1);
		v4 = *(__int16*)(a2 + 40);
		if (result >= v4)
			result = v4 - 1;
		break;
	case 1:
		result = (*getMemUintPtr(0x5D4594, 2598000) - a1[79]) / (unsigned int)(*(__int16*)(a2 + 42) + 1);
		if (result >= *(__int16*)(a2 + 40)) {
			nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr);
			result = -1;
		}
		break;
	case 2:
		result = (*getMemUintPtr(0x5D4594, 2598000) + a1[32]) / (unsigned int)(*(__int16*)(a2 + 42) + 1);
		v3 = *(__int16*)(a2 + 40);
		if (result >= v3)
			result %= v3;
		break;
	case 4:
		result = nox_common_randomIntMinMax_415FF0(0, *(__int16*)(a2 + 40) - 1, "C:\\NoxPost\\src\\Client\\Draw\\vectdraw.c", 19);
		break;
	case 5:
		result = a1[77];
		break;
	default:
		result = 0;
		break;
	}
	return result;
}

//----- (004BC700) --------------------------------------------------------
int __cdecl nox_thing_vector_animate_draw(int* a1, nox_drawable* dr) { return sub_4BC6B0(a1, dr, *(_DWORD*)&dr->field_76); }

//----- (0044BF60) --------------------------------------------------------
bool __cdecl nox_things_vector_animate_draw_parse(nox_thing* obj, nox_memfile* f, char* attr_value) {
	_DWORD* v2; // eax
	_DWORD* v3; // esi
	int result; // eax

	v2 = calloc(1u, 0x30u);
	v3 = v2;
	*v2 = 48;
	result = nox_xxx_spriteLoadVectoAnimatedImpl_44BFA0((int)v2, f);
	if (result) {
		obj->draw_func = nox_thing_vector_animate_draw;
		obj->field_5c = v3;
		result = 1;
	}
	return result;
}
