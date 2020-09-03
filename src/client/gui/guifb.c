#include "guifb.h"

#include "../../proto.h"
#include "gamewin/gamewin.h"
extern _DWORD dword_5d4594_1045636;

//----- (00456140) --------------------------------------------------------
wchar_t* __cdecl sub_456140(unsigned __int8 a1) {
	wchar_t* result; // eax
	int v2;          // esi
	wchar_t* v3;     // eax
	wchar_t* v4;     // eax
	wchar_t* v5;     // eax
	wchar_t* v6;     // eax

	*getMemAt( 0x5D4594, 1045644) = a1;
	result = (wchar_t*)a1;
	v2 = dword_5d4594_1045636 + 36;
	switch (a1) {
	case 0u:
		*(_DWORD*)(v2 + 24) = sub_42F970("BallAtHome");
		v3 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 128780), 0, "C:\\NoxPost\\src\\client\\Gui\\guifb.c", 165);
		result = sub_46B000((wchar_t*)v2, v3);
		break;
	case 1u:
		*(_DWORD*)(v2 + 24) = sub_42F970("BallAway");
		v4 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 128840), 0, "C:\\NoxPost\\src\\client\\Gui\\guifb.c", 170);
		result = sub_46B000((wchar_t*)v2, v4);
		break;
	case 2u:
		*(_DWORD*)(v2 + 24) = sub_42F970("BallRed");
		v5 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 128896), 0, "C:\\NoxPost\\src\\client\\Gui\\guifb.c", 175);
		result = sub_46B000((wchar_t*)v2, v5);
		break;
	case 4u:
		*(_DWORD*)(v2 + 24) = sub_42F970("BallBlue");
		v6 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 128956), 0, "C:\\NoxPost\\src\\client\\Gui\\guifb.c", 180);
		result = sub_46B000((wchar_t*)v2, v6);
		break;
	default:
		return result;
	}
	return result;
}
