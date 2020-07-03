#include "armordraw.h"
#include "staticdraw.h"
#include "animdraw.h"
#include "../../proto.h"

//----- (004B96D0) --------------------------------------------------------
int __cdecl nox_thing_armor_draw(int* a1, int a2) {
	sub_4B96F0(a2);
	return nox_thing_static_draw(a1, a2);
}

//----- (004B9770) --------------------------------------------------------
int __cdecl nox_thing_armor_animate_draw(int* a1, int a2) {
	sub_4B96F0(a2);
	return nox_thing_animate_draw(a1, a2);
}
