#include "client__draw__staticdraw.h"
#include "GAME1_2.h"
#include "GAME3_1.h"
#include "client__draw__parse__parse.h"
#include "operators.h"

//----- (004BCC20) --------------------------------------------------------
int nox_thing_static_draw(uint32_t* a1, nox_drawable* dr) {
	if (!(dr->flags28 & 0x40000) || dr->flags30 & 0x1000000) {
		nox_xxx_drawObject_4C4770_draw(a1, dr, *(uint32_t*)((char*)dr->field_76 + 4));
	}
	return 1;
}

//----- (004BCC60) --------------------------------------------------------
int nox_thing_static_random_draw(uint32_t* a1, nox_drawable* dr) {
	nox_xxx_drawObject_4C4770_draw(a1, dr, *(uint32_t*)(*(uint32_t*)((char*)dr->field_76 + 4) + 4 * dr->field_77));
	return 1;
}

//----- (0044C160) --------------------------------------------------------
bool nox_things_static_draw_parse(nox_thing* obj, nox_memfile* f, char* attr_value) {
	uint8_t* a3 = attr_value;
	char* v6;          // edi
	int v8;            // ebx
	unsigned char v11; // [esp+Ch] [ebp+8h]

	uint32_t* data = calloc(1u, 8u);
	if (!data) {
		return 0;
	}

	data[0] = 8;
	v6 = a3;
	v8 = nox_memfile_read_u32(f);
	*a3 = getMemByte(0x5D4594, 830856);
	if (v8 == -1) {
		LOBYTE(a3) = nox_memfile_read_u8(f);
		v11 = nox_memfile_read_u8(f);
		nox_memfile_read(v6, 1u, v11, f);
		v6[v11] = 0;
	}
	data[1] = nox_xxx_readImgMB_42FAA0(v8, a3, v6);
	obj->draw_func = &nox_thing_static_draw;
	obj->field_5c = data;
	return 1;
}

//----- (0044BFD0) --------------------------------------------------------
bool nox_things_static_random_draw_parse(nox_thing* obj, nox_memfile* f, char* attr_value) {
	obj->draw_func = nox_thing_static_random_draw;
	obj->field_5c = nox_xxx_spriteLoadStaticRandomData_44C000(attr_value, f);

	return obj->field_5c != 0;
}
