#include "client__gui__gui_ctf.h"
#include "client__gui__window.h"
#include "common__strman.h"

#include "client__gui__gamewin__gamewin.h"

#include "GAME1_2.h"
#include "GAME2.h"
#include "GAME2_3.h"
extern uint32_t dword_5d4594_1045604;

//----- (00455C30) --------------------------------------------------------
int sub_455C30() {
	int result;  // eax
	int v1;      // edi
	wchar_t* v2; // esi
	wchar_t* v3; // eax

	if (dword_5d4594_1045604) {
		return 1;
}
	result = nox_new_window_from_file("GUI_CTF.wnd", 0);
	dword_5d4594_1045604 = result;
	if (result) {
		v1 = 8811;
		while (1) {
			v2 = (wchar_t*)nox_xxx_wndGetChildByID_46B0C0((uint32_t*)result, v1);
			nox_window_set_all_funcs(v2, 0, sub_455CD0, 0);
			v3 = nox_strman_loadString_40F1D0("FlagHomeTT", 0, "C:\\NoxPost\\src\\client\\Gui\\GUI_CTF.c", 201);
			nox_xxx_wndWddSetTooltip_46B000(v2 + 18, v3);
			if (++v1 > 8826) {
				break;
}
			result = dword_5d4594_1045604;
		}
		sub_455A00(0);
		*getMemU32Ptr(0x5D4594, 1045632) = nox_xxx_gLoadImg_42F970("FlagTeamBorder");
		result = 1;
	}
	return result;
}

//----- (00455D80) --------------------------------------------------------
void  sub_455D80(unsigned char a1, char a2) {
	wchar_t* result; // eax
	wchar_t* v3;     // esi
	wchar_t* v4;     // eax

	*getMemU8Ptr(0x5D4594, 1045611 + a1) = a2;
	result = (wchar_t*)nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1045604, a1 + 8810);
	v3 = result;
	if (result) {
		if (result[2] & 0x20) {
			if (a2) {
				if (a2 == 1) {
					v4 = nox_strman_loadString_40F1D0("YourFlagCarriedTT", 0,
											   "C:\\NoxPost\\src\\client\\Gui\\GUI_CTF.c", 234);
				} else {
					if (a2 != 2) {
						return;
}
					v4 = nox_strman_loadString_40F1D0("FlagAwayTT", 0,
											   "C:\\NoxPost\\src\\client\\Gui\\GUI_CTF.c", 238);
				}
			} else {
				v4 = nox_strman_loadString_40F1D0("FlagHomeTT", 0, "C:\\NoxPost\\src\\client\\Gui\\GUI_CTF.c",
										   242);
			}
		} else if (a2) {
			if (a2 == 1) {
				v4 = nox_strman_loadString_40F1D0("TheirFlagCarriedTT", 0, "C:\\NoxPost\\src\\client\\Gui\\GUI_CTF.c",
										   252);
			} else {
				if (a2 != 2) {
					return;
}
				v4 = nox_strman_loadString_40F1D0("FlagAwayTT", 0, "C:\\NoxPost\\src\\client\\Gui\\GUI_CTF.c",
										   256);
			}
		} else {
			v4 = nox_strman_loadString_40F1D0("FlagHomeTT", 0, "C:\\NoxPost\\src\\client\\Gui\\GUI_CTF.c", 260);
		}
		nox_xxx_wndWddSetTooltip_46B000(v3 + 18, v4);
	}
}
