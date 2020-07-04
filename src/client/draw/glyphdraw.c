#include "glyphdraw.h"
#include "animdraw.h"
#include "../../proto.h"

extern int nox_backbuffer_depth;

//----- (004B9C70) --------------------------------------------------------
int __cdecl nox_thing_glyph_draw(int* a1, nox_drawable* dr) {
	_DWORD* v2; // esi
	char v3;    // cl
	int v4;     // ecx
	int v5;     // eax
	int v6;     // eax
	int v7;     // esi

	_DWORD* a2 = dr;

	v2 = a2;
	if (!nox_common_gameFlags_check_40A5C0(2) || !*(_DWORD*)&byte_5D4594[2614252])
		goto LABEL_10;
	if (a2[30] & 0x40000000) {
		LOBYTE(a2) = -1;
		LABEL_10:
		nox_client_drawEnableAlpha_434560(1);
		nox_client_drawSetAlpha_434580((unsigned __int8)a2);
		v7 = nox_thing_animate_draw(a1, (int)v2);
		nox_client_drawEnableAlpha_434560(0);
		sub_434600(0);
		return v7;
	}
	if (sub_4356C0(*(int*)&byte_5D4594[2614252], 21)) {
		sub_434600(1);
		sub_433E40(*(int*)&byte_5D4594[2618904]);
		v3 = nox_backbuffer_depth >= 16 ? -1 : -128;
		LABEL_9:
		LOBYTE(a2) = v3;
		goto LABEL_10;
	}
	v4 = a2[3] - *(_DWORD*)(*(_DWORD*)&byte_5D4594[2614252] + 12);
	v5 = a2[4] - *(_DWORD*)(*(_DWORD*)&byte_5D4594[2614252] + 16);
	v6 = v4 * v4 + v5 * v5;
	if (v6 < 22500) {
		v3 = -56 - 200 * v6 / 22500;
		goto LABEL_9;
	}
	return 1;
}
