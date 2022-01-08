#include "client__draw__debugdraw.h"
#include "GAME1_1.h"
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_3.h"
#include "GAME3_1.h"

extern unsigned int nox_frame_xxx_2598000;
extern uint32_t nox_color_white_2523948;
extern uint32_t nox_color_yellow_2589772;
//----- (004BCC90) --------------------------------------------------------
int nox_thing_debug_draw(nox_draw_viewport_t* vp, nox_drawable* dr) {
	uint32_t* a1 = vp;
	int v2;    // edi
	int v3;    // ebx
	int v4;    // eax
	int v5;    // ecx
	int v6;    // edx
	int v7;    // eax
	int v8;    // edi
	int v9;    // ebx
	int v10;   // eax
	int v11;   // ebp
	float v16; // [esp-8h] [ebp-38h]
	int2 a2a;  // [esp+10h] [ebp-20h]
	int v18;   // [esp+1Ch] [ebp-14h]
	int v19;   // [esp+20h] [ebp-10h]
	int v20;   // [esp+28h] [ebp-8h]

	v2 = *getMemU32Ptr(0x8531A0, 2572);
	if (dr->field_72 >= nox_frame_xxx_2598000) {
		v2 = nox_color_yellow_2589772;
	}
	nox_client_drawSetColor_434460(v2);
	nox_xxx_drawSetTextColor_434390(nox_color_white_2523948);
	v3 = dr->pos.y;
	v4 = *a1 + dr->pos.x - a1[4];
	v5 = dr->flags28;
	v6 = a1[1] - a1[5];
	a2a.field_0 = *a1 + dr->pos.x - a1[4];
	a2a.field_4 = v3 + v6;
	if ((v5 & 0x80) == 0) {
		if (v5 & 0x2) {
			sub_4BD010(dr, &a2a, v2);
			nox_client_drawAddPoint_49F500(a2a.field_0, a2a.field_4);
			nox_xxx_rasterPointRel_49F570(*getMemU32Ptr(0x587000, 179880 + 8 * dr->field_74_2),
										  *getMemU32Ptr(0x587000, 179884 + 8 * dr->field_74_2));
			nox_client_drawLineFromPoints_49E4B0();
			nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1316540), L"%d", dr->field_32);
			nox_xxx_drawString_43F6E0(0, getMemI16Ptr(0x5D4594, 1316540), a2a.field_0, a2a.field_4 - 10);
			nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1316540), L"%S", nox_get_thing_name(dr->field_27));
			nox_xxx_drawString_43F6E0(0, getMemI16Ptr(0x5D4594, 1316540), a2a.field_0, a2a.field_4);
			nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1316540), L"%S",
						 *getMemU32Ptr(0x587000, 178920 + 4 * dr->field_69));
			nox_xxx_drawString_43F6E0(0, getMemI16Ptr(0x5D4594, 1316540), a2a.field_0, a2a.field_4 + 10);
		} else if (v5 & 0x4) {
			sub_4BD010(dr, &a2a, v2);
			nox_client_drawAddPoint_49F500(a2a.field_0, a2a.field_4);
			nox_xxx_rasterPointRel_49F570(*getMemU32Ptr(0x587000, 179880 + 8 * dr->field_74_2),
										  *getMemU32Ptr(0x587000, 179884 + 8 * dr->field_74_2));
			nox_client_drawLineFromPoints_49E4B0();
			nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1316540), L"%d", dr->field_32);
			nox_xxx_drawString_43F6E0(0, getMemI16Ptr(0x5D4594, 1316540), a2a.field_0, a2a.field_4 - 10);
			nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1316540), L"%S", nox_get_thing_name(dr->field_27));
			nox_xxx_drawString_43F6E0(0, getMemI16Ptr(0x5D4594, 1316540), a2a.field_0, a2a.field_4);
			nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1316540), L"%S",
						 *getMemU32Ptr(0x587000, 178696 + 4 * dr->field_69));
			nox_xxx_drawString_43F6E0(0, getMemI16Ptr(0x5D4594, 1316540), a2a.field_0, a2a.field_4 + 10);
		} else {
			sub_4BD010(dr, &a2a, v2);
		}
	} else {
		v20 = v4;
		v7 = nox_float2int(dr->field_25);
		v16 = dr->field_24;
		v8 = a2a.field_4 - v7;
		v19 = a2a.field_0;
		v9 = a2a.field_4 - nox_float2int(v16);
		v10 = 8 * dr->field_74_4;
		v11 = *getMemIntPtr(0x587000, 196184 + v10);
		v18 = *getMemIntPtr(0x587000, 196188 + v10);
		nox_client_drawAddPoint_49F500(a2a.field_0, v9);
		nox_xxx_rasterPointRel_49F570(v11, v18);
		nox_client_drawLineFromPoints_49E4B0();
		nox_client_drawAddPoint_49F500(v20, v8);
		nox_xxx_rasterPointRel_49F570(v11, v18);
		nox_client_drawLineFromPoints_49E4B0();
		nox_client_drawAddPoint_49F500(a2a.field_0, v9);
		nox_client_drawAddPoint_49F500(v20, v8);
		nox_client_drawLineFromPoints_49E4B0();
		nox_client_drawAddPoint_49F500(a2a.field_0 + v11, v9 + v18);
		nox_client_drawAddPoint_49F500(v20 + v11, v8 + v18);
		nox_client_drawLineFromPoints_49E4B0();
	}
	nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1316540), L"%d", dr->field_32);
	nox_xxx_drawString_43F6E0(0, getMemI16Ptr(0x5D4594, 1316540), a2a.field_0, a2a.field_4 - 10);
	nox_swprintf((wchar_t*)getMemAt(0x5D4594, 1316540), L"%S", nox_get_thing_name(dr->field_27));
	nox_xxx_drawString_43F6E0(0, getMemI16Ptr(0x5D4594, 1316540), a2a.field_0, a2a.field_4);
	return 1;
}
