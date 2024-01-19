#include "client__draw__maidendraw.h"
#include "GAME1.h"
#include "GAME2_3.h"
#include "GAME3_2.h"
#include "client__draw__mondraw.h"
#include "client__gui__window.h"
#include "client__video__draw_common.h"
#include "operators.h"

//----- (004BBF90) --------------------------------------------------------
int nox_thing_maiden_draw(uint32_t* a1, nox_drawable* dr) {
	if (!nox_common_gameFlags_check_40A5C0(0x200000)) {
		char* v9 = nox_npc_by_id(dr->field_32);
		if (!v9) {
			return 1;
		}
		int v10 = 0;
		int* v11 = (int*)(v9 + 8);
		int v12;
		do {
			v12 = v10 + 1;
			nox_draw_setMaterial_4341D0(v10 + 1, *v11);
			v10 = v12;
			++v11;
		} while (v12 < 6);
		return nox_thing_monster_draw(a1, dr);
	}
	const nox_object_t* v2 = nox_server_getFirstObject_4DA790();
	if (!v2) {
		return nox_thing_monster_draw(a1, dr);
	}
	int v3;
	while (1) {
		v3 = v2->extent;
		if (dr->field_32 == v3) {
			break;
		}
		v2 = nox_server_getNextObject_4DA7A0(v2);
		if (!v2) {
			return nox_thing_monster_draw(a1, dr);
		}
	}
	int v5 = v2->data_update;
	int v6 = 0;
	uint8_t* v7 = (uint8_t*)(v5 + 2077);
	int v8;
	do {
		LOBYTE(v3) = v7[1];
		LOBYTE(v5) = *(v7 - 1);
		v8 = v6 + 1;
		LOBYTE(v6) = *v7;
		nox_draw_setMaterial_4340A0(v8, v5, v6, v3);
		v6 = v8;
		v7 += 3;
	} while (v8 < 6);
	return nox_thing_monster_draw(a1, dr);
}
