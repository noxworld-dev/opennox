#include "slavedraw.h"
#include "staticdraw.h"
#include "../../proto.h"

//----- (004BBD30) --------------------------------------------------------
int __cdecl nox_thing_slave_draw(int* a1, nox_drawable* dr) {
	sub_4C4770_draw(a1, dr, *(_DWORD*)(*(_DWORD*)(*(_DWORD*)&dr->field_76 + 4) + 4 * dr->field_77));
	if (nox_thing_slave_draw == nox_thing_static_random_draw) // AntiICFoptimization
	{
		return 0;
	}
	return 1;
}

//----- (0044C120) --------------------------------------------------------
bool __cdecl nox_things_slave_draw_parse(nox_thing* obj, nox_memfile* f, _BYTE* a3) {
	obj->draw_func = nox_thing_slave_draw;
	void* v3 = sub_44C000(a3, f);
	obj->field_5c = v3;
	obj->field_60 = 0;
	return v3 != 0;
}
