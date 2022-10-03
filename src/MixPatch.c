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

int mix_recvfrom(nox_socket_t s, char* buf, int len, struct nox_net_sockaddr_in* from) {
	int result = nox_net_recvfrom(s, buf, len, from);
	if (*(uint16_t*)buf != 0xF13A) { // extension packet code
		return result;
	}
	return MixRecvFromReplacer(s, buf, len, from);
}
