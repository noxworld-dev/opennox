#include "client__draw__basedraw.h"
#include "client__draw__weapondraw.h"

//----- (004B95B0) --------------------------------------------------------
int nox_thing_base_draw(int* a1, nox_drawable* dr) {
	nox_thing_weapon_draw(a1, dr);
	return 1;
}
