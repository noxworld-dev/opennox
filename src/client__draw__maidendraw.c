#include "client__draw__maidendraw.h"
#include "client__draw__mondraw.h"
#include "proto.h"

//----- (004BBF90) --------------------------------------------------------
int __cdecl nox_thing_maiden_draw(_DWORD* a1, nox_drawable* dr) {
	int v2;    // eax
	int v3;    // edx
	int v5;    // ecx
	int v6;    // eax
	_BYTE* v7; // esi
	int v8;    // edi
	char* v9;  // eax
	int v10;   // ecx
	int* v11;  // edi
	int v12;   // esi

	if (!nox_common_gameFlags_check_40A5C0(0x200000)) {
		v9 = nox_npc_by_id(dr->field_32);
		if (!v9)
			return 1;
		v10 = 0;
		v11 = (int*)(v9 + 8);
		do {
			v12 = v10 + 1;
			nox_xxx_drawPlayer_4341D0(v10 + 1, *v11);
			v10 = v12;
			++v11;
		} while (v12 < 6);
		return nox_thing_monster_draw(a1, dr);
	}
	v2 = nox_server_getFirstObject_4DA790();
	if (!v2)
		return nox_thing_monster_draw(a1, dr);
	while (1) {
		v3 = *(_DWORD*)(v2 + 40);
		if (dr->field_32 == v3)
			break;
		v2 = nox_server_getNextObject_4DA7A0(v2);
		if (!v2)
			return nox_thing_monster_draw(a1, dr);
	}
	v5 = *(_DWORD*)(v2 + 748);
	v6 = 0;
	v7 = (_BYTE*)(v5 + 2077);
	do {
		LOBYTE(v3) = v7[1];
		LOBYTE(v5) = *(v7 - 1);
		v8 = v6 + 1;
		LOBYTE(v6) = *v7;
		sub_4340A0(v8, v5, v6, v3);
		v6 = v8;
		v7 += 3;
	} while (v8 < 6);
	return nox_thing_monster_draw(a1, dr);
}

//----- (0044BD60) --------------------------------------------------------
bool __cdecl nox_things_maiden_draw_parse(nox_thing* obj, nox_memfile* f, char* attr_value) {
	int result = nox_things_monster_draw_parse(obj, f, attr_value);
	obj->draw_func = &nox_thing_maiden_draw;
	return result;
}
