#include "weapondraw.h"
#include "staticdraw.h"
#include "animdraw.h"
#include "../../proto.h"

//----- (004B9690) --------------------------------------------------------
int __cdecl nox_thing_weapon_draw(int* a1, int a2) {
	sub_4B95D0(a2);
	return nox_thing_static_draw(a1, a2);
}

//----- (004B96B0) --------------------------------------------------------
int __cdecl nox_thing_weapon_animate_draw(int* a1, int a2) {
	sub_4B95D0(a2);
	return nox_thing_animate_draw(a1, a2);
}

//----- (004B8020) --------------------------------------------------------
int __cdecl nox_thing_spherical_shield_draw(int* a1, _DWORD* a2) {
	int v2;     // esi
	int v3;     // eax
	_DWORD* v4; // eax
	int v5;     // eax
	int result; // eax

	v2 = a2[108];
	if (sub_578B70(a2[108])) {
		v3 = sub_578B30(v2);
		v4 = sub_45A720(v3);
	} else {
		v5 = sub_578B30(v2);
		v4 = sub_45A6F0(v5);
	}
	if (v4) {
		sub_49AA90(a2, v4[3], v4[4] + 3);
		result = nox_thing_animate_draw(a1, (int)a2);
	} else {
		sub_45A4E0_drawable((int)a2);
		result = 0;
	}
	return result;
}
