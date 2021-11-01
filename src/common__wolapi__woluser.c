#include "common__wolapi__woluser.h"

#include "GAME1_1.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "client__gui__window.h"
#include "client__video__draw_common.h"
#include "common__strman.h"
extern uint32_t dword_5d4594_531652;
extern uint32_t dword_5d4594_531648;

//----- (0041F620) --------------------------------------------------------
void  sub_41F620(int a1) {
	uint32_t* v1;  // esi
	int v2;      // ebp
	uint32_t* v3;  // edi
	int v4;      // eax
	int v5;      // eax
	int v6;      // edi
	wchar_t* v7; // eax

	v1 = *(uint32_t**)&dword_5d4594_531648;
	v2 = 0;
	if (dword_5d4594_531648) {
		while (1) {
			v3 = (uint32_t*)v1[5];
			if (!_strcmpi((const char*)(*v1 + 36), (const char*)(a1 + 36)))
				break;
			++v2;
			v1 = v3;
			if (!v3)
				return;
		}
		v4 = v1[6];
		if (v4)
			*(uint32_t*)(v4 + 20) = v1[5];
		else
			dword_5d4594_531648 = v1[5];
		v5 = v1[5];
		if (v5)
			*(uint32_t*)(v5 + 24) = v1[6];
		else
			dword_5d4594_531652 = v1[6];
		if (sub_41E2F0() == 7) {
			v6 = sub_446C70();
			sub_448620(v2);
			if (v6 != -1 && sub_446C70() == -1) {
				nox_xxx_clientPlaySoundSpecial_452D80(226, 100);
				v7 = nox_strman_loadString_40F1D0("lostselection", 0, "C:\\NoxPost\\src\\common\\WolAPI\\woluser.c",
										   208);
				sub_447310(0, (int)v7);
			}
		}
		free(v1);
	}
}
