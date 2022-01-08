#include "client__gui__guigen.h"
#include "common__strman.h"

#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_2.h"
#include "client__gui__window.h"
#include "client__video__draw_common.h"

extern int nox_win_width;
extern int nox_win_height;
extern uint32_t nox_color_white_2523948;

//----- (004A9D00) --------------------------------------------------------
short nox_xxx_mapGenClientText_4A9D00(unsigned char* a1) {
	unsigned char* v1; // ebx
	int v2;            // eax
	int v3;            // edi
	int v4;            // esi
	wchar_t* v5;       // eax
	int v6;            // kr00_4
	int v7;            // esi

	v1 = a1;
	v2 = *(unsigned short*)(a1 + 1);
	if ((unsigned short)v2 == *getMemU32Ptr(0x5D4594, 1309668)) {
		return v2;
	}
	*getMemU32Ptr(0x5D4594, 1309668) = *(unsigned short*)(a1 + 1);
	nox_xxx_clientPlaySoundSpecial_452D80(897, 50);
	sub_430B50(0, 0, nox_win_width - 1, nox_win_height - 1);
	nox_client_clearScreen_440900();
	v3 = nox_win_height / 2 - 120;
	v4 = nox_win_width / 2 - 160;
	nox_client_drawImageAt_47D2C0(*getMemU32Ptr(0x5D4594, 1309644 + 4 * (*getMemU32Ptr(0x5D4594, 1309672) % 4)), v4,
								  v3);
	nox_client_drawImageAt_47D2C0(*getMemU32Ptr(0x5D4594, 1309516 + 4 * *getMemU32Ptr(0x5D4594, 1309672)), v4, v3);
	switch (*v1) {
	case 0x9Bu:
		v5 = nox_strman_loadString_40F1D0("Generating", 0, "C:\\NoxPost\\src\\client\\Gui\\guigen.c", 89);
		goto LABEL_8;
	case 0x9Cu:
		v5 = nox_strman_loadString_40F1D0("Assembling", 0, "C:\\NoxPost\\src\\client\\Gui\\guigen.c", 92);
		goto LABEL_8;
	case 0x9Du:
		v5 = nox_strman_loadString_40F1D0("Populating", 0, "C:\\NoxPost\\src\\client\\Gui\\guigen.c", 95);
	LABEL_8:
		*getMemU32Ptr(0x5D4594, 1309660) = v5;
		break;
	}
	nox_xxx_drawGetStringSize_43F840(0, *(unsigned short**)getMemAt(0x5D4594, 1309660), (int*)&a1, 0, 0);
	v6 = nox_win_width - (uint32_t)a1;
	v7 = nox_win_height / 2 - (2 * nox_xxx_guiFontHeightMB_43F320(0) + 70);
	nox_xxx_drawSetTextColor_434390(nox_color_white_2523948);
	nox_xxx_drawSetColor_4343E0(*getMemIntPtr(0x852978, 4));
	nox_draw_drawStringHL_43F730(0, *(short**)getMemAt(0x5D4594, 1309660), v6 / 2, v7);
	if (++*getMemU32Ptr(0x5D4594, 1309672) >= 32) {
		*getMemU32Ptr(0x5D4594, 1309672) = 0;
	}
#ifndef NOX_CGO
	nox_xxx_directDrawBlitMB_48A220();
#endif // NOX_CGO
	nox_video_callCopyBackBuffer_4AD170();
#ifndef NOX_CGO
	sub_48A290_call_present();
#endif // NOX_CGO
	return v2;
}
