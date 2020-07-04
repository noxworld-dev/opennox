#include "boulderdraw.h"
#include "../../proto.h"

//----- (004B9B50) --------------------------------------------------------
int __cdecl nox_thing_boulder_draw(int* a1, nox_drawable* dr) {
	int v2;          // edi
	int v3;          // ecx
	int v4;          // edx
	unsigned int v5; // ecx
	int v6;          // ecx

	int a2 = dr;

	v2 = *(_DWORD*)(a2 + 304);
	if (!*(_DWORD*)(a2 + 432) && !*(_DWORD*)(a2 + 436)) {
		*(_DWORD*)(a2 + 432) = *(_DWORD*)(a2 + 12);
		*(_DWORD*)(a2 + 436) = *(_DWORD*)(a2 + 16);
	}
	v3 = *(_DWORD*)(a2 + 12) - *(_DWORD*)(a2 + 432);
	v4 = *(_DWORD*)(a2 + 16) - *(_DWORD*)(a2 + 436);
	if (v3 * v3 + v4 * v4 >= 100) {
		if (v3 <= 0) {
			if (v4 > 0) {
				*(_DWORD*)(a2 + 444) = 0;
				LABEL_8:
				v5 = *(_DWORD*)(a2 + 440) + 1;
				*(_DWORD*)(a2 + 440) = v5;
				if (v5 >= 0x10)
					*(_DWORD*)(a2 + 440) = 0;
				goto LABEL_17;
			}
			*(_DWORD*)(a2 + 444) = 16;
		} else {
			if (v4 > 0) {
				*(_DWORD*)(a2 + 444) = 16;
				goto LABEL_8;
			}
			*(_DWORD*)(a2 + 444) = 0;
		}
		v6 = *(_DWORD*)(a2 + 440);
		if (v6)
			*(_DWORD*)(a2 + 440) = v6 - 1;
		else
			*(_DWORD*)(a2 + 440) = 15;
		LABEL_17:
		*(_DWORD*)(a2 + 432) = *(_DWORD*)(a2 + 12);
		*(_DWORD*)(a2 + 436) = *(_DWORD*)(a2 + 16);
	}
	sub_4C4770_draw(a1, (unsigned __int8*)a2,
		*(_DWORD*)(*(_DWORD*)(v2 + 4) + 4 * (*(_DWORD*)(a2 + 440) + *(_DWORD*)(a2 + 444))));
	return 1;
}
