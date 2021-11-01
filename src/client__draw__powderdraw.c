#include "client__draw__powderdraw.h"
#include "GAME1_2.h"
#include "GAME2_3.h"

//----- (004B9ED0) --------------------------------------------------------
int nox_thing_black_powder_draw(uint32_t* a1, nox_drawable* dr) {
	int v2; // esi
	int v3; // edi

	int a2 = dr;

	v2 = *a1 + *(uint32_t*)(a2 + 12) - a1[4];
	v3 = *(uint32_t*)(a2 + 16) + a1[1] - a1[5];
	nox_client_drawSetColor_434460(*getMemIntPtr(0x85B3FC, 956));
	nox_client_drawRectFilledOpaque_49CE30(v2 - 1, v3 - 1, 3, 3);
	nox_client_drawRectFilledOpaque_49CE30(v2 - 5, v3, 1, 1);
	nox_client_drawRectFilledOpaque_49CE30(v2, v3 + 7, 1, 1);
	nox_client_drawRectFilledOpaque_49CE30(v2 + 8, v3 - 2, 1, 1);
	return 1;
}
