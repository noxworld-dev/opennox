#include "GAME1.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4.h"
#include "common__strman.h"

// TODO: convert table_272352

//----- (004F3A60) --------------------------------------------------------
int  nox_xxx_pickupGold_4F3A60_obj_pickup(int a1, int a2, int a3) {
	int* v3;     // edi
	wchar_t* v4; // eax
	int result;  // eax
	int v6;      // edi
	int v7;      // [esp-8h] [ebp-10h]

	if (*(uint8_t*)(a1 + 8) & 4) {
		v3 = *(int**)(a2 + 692);
		nox_xxx_playerAddGold_4FA590(a1, *v3);
		nox_xxx_delayedDeleteObject_4E5CC0(a2);
		v7 = *v3;
		v4 = nox_strman_loadString_40F1D0("GoldPickup", 0,
								   "C:\\NoxPost\\src\\Server\\Object\\pickdrop\\pickup.c", 709);
		nox_xxx_netSendLineMessage_4D9EB0(a1, v4, v7);
		nox_xxx_aud_501960(307, a1, 0, 0);
		result = 1;
	} else {
		v6 = nox_xxx_pickupDefault_4F31E0(a1, a2, a3);
		if (v6)
			nox_xxx_aud_501960(307, a1, 0, 0);
		result = v6;
	}
	return result;
}
