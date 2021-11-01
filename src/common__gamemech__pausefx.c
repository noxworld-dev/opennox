#include "common__gamemech__pausefx.h"

#include "common__strman.h"
#include "GAME1.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4.h"
#include "GAME4_2.h"
extern uint32_t dword_5d4594_2523804;
extern uint32_t dword_5d4594_2523776;
extern uint32_t dword_5d4594_2523780;

//----- (0057AF30) --------------------------------------------------------
void  sub_57AF30(int a1, int a2) {
	int v2;      // ecx
	uint32_t* v3;  // eax
	wchar_t* v4; // eax
	int v5;      // esi

	if (!(dword_5d4594_2523804 != 1 && !nox_xxx_checkGameFlagPause_413A50())) {
		return;
	}
	v2 = a1;
	if (a1)
		dword_5d4594_2523780 = a1;
	else
		v2 = dword_5d4594_2523780;
	if (a2) {
		if (a2 != 1) {
			v3 = *(uint32_t**)&dword_5d4594_2523776;
		} else {
			v3 = nox_xxx_newObjectByTypeID_4E3810("OblivionUp");
			v2 = dword_5d4594_2523780;
			dword_5d4594_2523776 = v3;
		}
	} else {
		v3 = nox_xxx_newObjectByTypeID_4E3810("LevelUp");
		v2 = dword_5d4594_2523780;
		dword_5d4594_2523776 = v3;
	}
	if (v3) {
		if (v2) {
			nox_xxx_createAt_4DAA50((int)v3, 0, *(float*)(v2 + 56), *(float*)(v2 + 60));
		} else {
			nox_xxx_objectFreeMem_4E38A0((int)v3);
			dword_5d4594_2523776 = 0;
		}
		v2 = dword_5d4594_2523780;
	}
	if ((!a2 || a2 == 1) && v2) {
		nox_xxx_netSendPointFx_522FF0(154, (float2*)(v2 + 56));
		v2 = dword_5d4594_2523780;
	}
	if (!a2) {
		if (!v2) {
			goto LABEL_29;
		}
		nox_xxx_aud_501960(902, v2, 2, *(uint32_t *) (v2 + 36));
		v4 = nox_strman_loadString_40F1D0("expLevel.c:LevelUP", 0,
								   "C:\\NoxPost\\src\\common\\GameMech\\PauseFX.c", 109);
		nox_xxx_netSendLineMessage_4D9EB0(*(int *) &dword_5d4594_2523780, v4);
		v2 = dword_5d4594_2523780;
	}
	if (v2) {
		v5 = *(uint32_t*)(v2 + 748);
		if (nox_xxx_playerSetState_4FA020((uint32_t*)v2, 30) == 1)
			*(uint8_t*)(v5 + 236) = 4;
	}
	if (a2) {
		*getMemU32Ptr(0x5D4594, 2523796) = 0;
		if (a2 != 1) {
			goto LABEL_30;
		}
	}
	LABEL_29:
	*getMemU32Ptr(0x5D4594, 2523796) = 5000;
	LABEL_30:
	*getMemU32Ptr(0x5D4594, 2523800) = 0;
	*getMemU32Ptr(0x5D4594, 2523772) = a2;
	dword_5d4594_2523804 = 1;
	sub_413A00(1);
	*getMemU64Ptr(0x5D4594, 2523788) = nox_platform_get_ticks();
}
