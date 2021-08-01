#include "client__draw__selectdw.h"
#include "common__random.h"

#include "proto.h"
extern void* dword_5d4594_1096640;

//----- (004773C0) --------------------------------------------------------
void  nox_video_drawCursorSelectCircle_4773C0(nox_draw_viewport_t* a1p) {
	_DWORD* a1 = a1p;
	int v1;     // eax
	int v2;     // eax
	_DWORD* v3; // eax
	int v4;     // eax
	int v5;     // edx

	if (dword_5d4594_1096640) {
		if (*(_BYTE*)((_DWORD)dword_5d4594_1096640 + 112) & 6 && !sub_495A80(*(_DWORD*)((_DWORD)dword_5d4594_1096640 + 128))) {
			v4 = nox_common_randomIntMinMax_415FF0(0, 1, "C:\\NoxPost\\src\\Client\\Draw\\selectdw.c", 440);
			if (!v4) {
				v3 = *(_DWORD**)getMemAt(0x5D4594, 2598268);
				goto LABEL_15;
			}
			if (v4 == 1) {
				v3 = *(_DWORD**)getMemAt(0x85B3FC, 940);
				goto LABEL_15;
			}
		} else {
			v1 = nox_common_randomIntMinMax_415FF0(0, 2, "C:\\NoxPost\\src\\Client\\Draw\\selectdw.c", 423);
			if (!v1) {
				v3 = *(_DWORD**)getMemAt(0x5D4594, 2523948);
				goto LABEL_15;
			}
			v2 = v1 - 1;
			if (!v2) {
				v3 = *(_DWORD**)getMemAt(0x85B3FC, 980);
				goto LABEL_15;
			}
			if (v2 == 1) {
				v3 = *(_DWORD**)getMemAt(0x85B3FC, 116);
				goto LABEL_15;
			}
		}
		v3 = a1;
	LABEL_15:
		v5 = *(_DWORD*)((_DWORD)dword_5d4594_1096640 + 112);
		if (!(v5 & 0x200))
			nox_video_drawCursorSelectCircle2_477470(a1, (int)v3, *(int*)&dword_5d4594_1096640);
	}
}
