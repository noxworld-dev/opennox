#include "GAME1.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "cdrom.h"
#include "client__gui__window.h"
#include "common__strman.h"
extern uint32_t dword_5d4594_251728;
extern uint32_t dword_5d4594_251704;
extern uint32_t dword_5d4594_251712;
extern uint32_t dword_5d4594_251708;
extern uint32_t nox_game_cdState_251700;

//----- (00413520) --------------------------------------------------------
void sub_413520_gamedisk() {
	int v1;       // eax
	wchar_t* v2;  // eax
	long long v3; // rax
	wchar_t* v5;  // [esp-10h] [ebp-1Ch]
	int v6;       // [esp-Ch] [ebp-18h]
	void (*v7)(); // [esp-8h] [ebp-14h]
	void (*v8)(); // [esp-4h] [ebp-10h]

	switch (nox_game_cdState_251700) {
	case 1:
		// XXX NO CD
		// v1 = nox_xxx_noxCDinDriver_423CF0();
		v1 = 2;
		dword_5d4594_251704 = v1;
		if (!v1) {
			sub_4137C0();
			sub_44D8F0();
			if (nox_common_gameFlags_check_40A5C0(2048)) {
				sub_4137A0();
			}
			v8 = sub_413760;
			v7 = sub_413780;
			v6 = 35;
			v5 = nox_strman_loadString_40F1D0("CDFailText", 0, "C:\\NoxPost\\src\\common\\System\\gamedisk.c", 200);
			v2 = nox_strman_loadString_40F1D0("CDFailTitle", 0, "C:\\NoxPost\\src\\common\\System\\gamedisk.c", 199);
			goto LABEL_9;
		}
		if (v1 == 1 && nox_common_gameFlags_check_40A5C0(2048)) {
			sub_4137C0();
			sub_44D8F0();
			sub_4137A0();
			v8 = sub_413760;
			v7 = sub_413780;
			v6 = 35;
			v5 = nox_strman_loadString_40F1D0("BuddyText", 0, "C:\\NoxPost\\src\\common\\System\\gamedisk.c", 219);
			v2 = nox_strman_loadString_40F1D0("BuddyTitle", 0, "C:\\NoxPost\\src\\common\\System\\gamedisk.c", 218);
			goto LABEL_9;
		}
		sub_4137E0();
		nox_game_cdMaybeSwitchState_413800();
		nox_game_cdState_251700 = 6;
		dword_5d4594_251728 = 0;
		break;
	case 2:
		v3 = nox_platform_get_ticks();
		*getMemU64Ptr(0x5D4594, 251628) = v3;
		int v0 = v3 - *getMemU64Ptr(0x5D4594, 251732);
		if (v0 > 2000) {
			sub_423C60();
			nox_game_cdState_251700 = 3;
			*getMemU32Ptr(0x5D4594, 251732) = *getMemU32Ptr(0x5D4594, 251628);
			*getMemU32Ptr(0x5D4594, 251736) = *getMemU32Ptr(0x5D4594, 251632);
		}
		break;
	case 3:
		dword_5d4594_251708;
		if (dword_5d4594_251708) {
			dword_5d4594_251712;
			dword_5d4594_251708 = 0;
			if (dword_5d4594_251712) {
				dword_5d4594_251712 = 0;
				nox_game_cdState_251700 = 1;
			} else {
				nox_game_cdState_251700 = 2;
			}
		}
		break;
	case 4:
		v8 = 0;
		v7 = sub_413760;
		v6 = 33;
		v5 = nox_strman_loadString_40F1D0("DevFailText", 0, "C:\\NoxPost\\src\\common\\System\\gamedisk.c", 293);
		v2 = nox_strman_loadString_40F1D0("DevFailTitle", 0, "C:\\NoxPost\\src\\common\\System\\gamedisk.c", 292);
	LABEL_9:
		nox_xxx_dialogMsgBoxCreate_449A10(0, (int)v2, (int)v5, v6, v7, v8);
		sub_44A360(0);
		sub_44A4B0();
		nox_game_cdState_251700 = 6;
		break;
	case 6:
		break;
	default:
		nox_xxx_setContinueMenuOrHost_43DDD0(0);
		nox_game_exit_xxx_43DE60();
		break;
	}
}
