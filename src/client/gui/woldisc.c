#include "woldisc.h"

#include "../../proto.h"
#include "guimsg.h"

extern _DWORD dword_5d4594_830292;
extern int nox_win_width;
extern int nox_win_height;

//----- (0044B010) --------------------------------------------------------
void sub_44B010() {
	wchar_t* v0; // eax
	wchar_t* v1; // eax

	sub_43C260();
	sub_41E300(9);
	sub_44E040();
	if (nox_common_gameFlags_check_40A5C0(0x2000000)) {
		v0 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 113772), 0, "C:\\NoxPost\\src\\client\\Gui\\woldisc.c", 75);
		nox_xxx_networkLog_413D30((char*)getMemAt(0x587000, 113788), v0);
		if (sub_43C710())
			sub_41E400();
		else
			sub_4460C0();
	} else if (nox_common_gameFlags_check_40A5C0(1)) {
		dword_5d4594_830292 = nox_new_window_from_file("woldisc.wnd", sub_44B0F0);
		nox_wnd_sub_46A9B0(*(_DWORD**)&dword_5d4594_830292, nox_win_width / 2 - *(int*)(dword_5d4594_830292 + 24) / 2,
						   nox_win_height / 2 - *(int*)(dword_5d4594_830292 + 28) / 2);
	} else {
		v1 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 113840), 0, "C:\\NoxPost\\src\\client\\Gui\\woldisc.c", 100);
		sub_445490(v1);
	}
}
