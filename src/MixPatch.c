#include "MixPatch.h"
#include "GAME1.h"
#include "GAME3_3.h"
#include "GameEx.h"

void sub_980523(nox_object_t* unit) {
	if (!unit)
		return;
	for (nox_object_t* it = unit->field_126; it; it = it->field_124) {
		if ((it->obj_class & 0x2000000) && (it->obj_flags & 0x100)) {
			if (nox_xxx_unitArmorInventoryEquipFlags_415C70(it) & 0x3000000) {
				// TODO: it appears that it reuses some other field; this might make the game unstable
				*(uint32_t*)(*(uint32_t*)(((uint32_t)unit->data_update) + 276) + 2500) = it;
			}
		}
	}
}

nox_object_t* sub_9805EB(nox_object_t* unit) {
	if (!unit) {
		return 0;
	}
	for (nox_object_t* it = unit->field_126; it; it = it->field_124) {
		if ((it->obj_class & 0x2000000) && (it->obj_flags == 16)) {
			return it;
		}
	}
	return 0;
}
