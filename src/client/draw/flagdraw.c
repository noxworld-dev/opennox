#include "flagdraw.h"
#include "weapondraw.h"
#include "../../proto.h"

//----- (004B9500) --------------------------------------------------------
int __cdecl nox_thing_flag_draw(int* a1, nox_drawable* dr) {
	int v2;               // ebx
	int v3;               // edi
	int v4;               // esi
	int v5;               // eax
	unsigned __int16* v6; // ebx

	int a2 = dr;

	v2 = a2;
	nox_thing_weapon_animate_draw(a1, dr);
	if (nox_common_gameFlags_check_40A5C0(128)) {
		if (*(_DWORD*)(v2 + 120) & 0x1000000) {
			v3 = *a1 + *(_DWORD*)(v2 + 12) - a1[4];
			v4 = *(_DWORD*)(v2 + 16) + a1[1] - *(__int16*)(v2 + 104) - (unsigned __int64)(__int64)*(float*)(v2 + 100) -
			                                                                             a1[5];
			v5 = sub_4B94E0(dr);
			v6 = (unsigned __int16*)sub_418A80(v5);
			if (v6) {
				sub_434390(*getMemIntPtr(0x5D4594, 2618904));
				sub_43F840(0, v6, &a2, 0, 0);
				sub_43F6E0(0, (__int16*)v6, a2 / -2 + v3, v4);
			}
		}
	}
	return 1;
}
