#include "basedraw.h"
#include "weapondraw.h"

//----- (004B95B0) --------------------------------------------------------
int __cdecl nox_thing_base_draw(int* a1, nox_drawable* dr) {
	nox_thing_weapon_draw(a1, dr);
	return 1;
}
