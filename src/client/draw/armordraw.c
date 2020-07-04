#include "armordraw.h"
#include "staticdraw.h"
#include "animdraw.h"
#include "../../proto.h"

//----- (004B96D0) --------------------------------------------------------
int __cdecl nox_thing_armor_draw(int* a1, nox_drawable* dr) {
	sub_4B96F0(dr);
	return nox_thing_static_draw(a1, dr);
}

//----- (004B9770) --------------------------------------------------------
int __cdecl nox_thing_armor_animate_draw(int* a1, nox_drawable* dr) {
	sub_4B96F0(dr);
	return nox_thing_animate_draw(a1, dr);
}
