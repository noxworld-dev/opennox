#include "client__gui__gamewin__gamewin.h"

#include "client__gui__guimsg.h"
#include "common__net_list.h"

#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME5_2.h"
#include "common__strman.h"
#include "operators.h"

//----- (0046C140) --------------------------------------------------------
void nox_xxx_clientPickup_46C140(nox_drawable* a1p) {
	int a1 = a1p;
	int v2;      // eax
	wchar2_t* v3; // eax
	int v4;      // [esp+0h] [ebp-4h]

	if (!*getMemU32Ptr(0x5D4594, 1064928)) {
		*getMemU32Ptr(0x5D4594, 1064928) = nox_xxx_getTTByNameSpriteMB_44CFC0("Gold");
		*getMemU32Ptr(0x5D4594, 1064932) = nox_xxx_getTTByNameSpriteMB_44CFC0("QuestGoldPile");
		*getMemU32Ptr(0x5D4594, 1064936) = nox_xxx_getTTByNameSpriteMB_44CFC0("QuestGoldChest");
	}
	if (a1) {
		v2 = *(uint32_t*)(a1 + 108);
		if (v2 == *getMemU32Ptr(0x5D4594, 1064928) || v2 == *getMemU32Ptr(0x5D4594, 1064932) ||
			v2 == *getMemU32Ptr(0x5D4594, 1064936) || sub_467B00(v2, 1)) {
			LOBYTE(v4) = 115;
			*(uint16_t*)((char*)&v4 + 1) = nox_xxx_netGetUnitCodeCli_578B00(a1);
			nox_netlist_addToMsgListCli_40EBC0(31, 0, &v4, 3);
		} else {
			nox_xxx_clientPlaySoundSpecial_452D80(925, 100);
			v3 = nox_strman_loadString_40F1D0("pickup.c:CarryingTooMuch", 0,
											  "C:\\NoxPost\\src\\Client\\Gui\\GameWin\\gamewin.c", 83);
			nox_xxx_printCentered_445490(v3);
		}
	}
}
