#include "wolchnl.h"

#include "../../proto.h"

//----- (0041F3A0) --------------------------------------------------------
BOOL __cdecl sub_41F3A0(int a1, int a2) {
	wchar_t* v2; // eax
	wchar_t* v4; // [esp-10h] [ebp-10h]

	if (sub_41E2F0() == 7) {
		v4 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 59760), 0, "C:\\NoxPost\\src\\common\\WolAPI\\wolchnl.c", 970);
		v2 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 59828), 0, "C:\\NoxPost\\src\\common\\WolAPI\\wolchnl.c", 969);
	} else {
		v4 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 59892), 0, "C:\\NoxPost\\src\\common\\WolAPI\\wolchnl.c", 976);
		v2 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 59956), 0, "C:\\NoxPost\\src\\common\\WolAPI\\wolchnl.c", 975);
	}
	nox_xxx_dialogMsgBoxCreate_449A10(0, (int)v2, (int)v4, 288, 0, 0);
	sub_44A4B0();
	return sub_40D2F0(a1, a2);
}
