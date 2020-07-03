#include "powderdraw.h"
#include "../../proto.h"

//----- (004B9ED0) --------------------------------------------------------
int __cdecl nox_thing_black_powder_draw(_DWORD* a1, int a2) {
	int v2; // esi
	int v3; // edi

	v2 = *a1 + *(_DWORD*)(a2 + 12) - a1[4];
	v3 = *(_DWORD*)(a2 + 16) + a1[1] - a1[5];
	nox_client_drawSetColor_434460(*(int*)&byte_5D4594[2650660]);
	nox_client_drawRectFilledOpaque_49CE30(v2 - 1, v3 - 1, 3, 3);
	nox_client_drawRectFilledOpaque_49CE30(v2 - 5, v3, 1, 1);
	nox_client_drawRectFilledOpaque_49CE30(v2, v3 + 7, 1, 1);
	nox_client_drawRectFilledOpaque_49CE30(v2 + 8, v3 - 2, 1, 1);
	return 1;
}
