#include "netclint.h"

#include "../../proto.h"
#include "../gui/guimsg.h"

//----- (0043D0A0) --------------------------------------------------------
void __cdecl sub_43D0A0(int a1) {
	wchar_t* v1; // esi
	wchar_t* v2; // eax

	v1 = loadString_sub_40F1D0((char*)&byte_587000[91932], 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 702);
	switch (a1 + 23) {
	case 0:
		v2 = loadString_sub_40F1D0((char*)&byte_587000[92656], 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 762);
		break;
	case 1:
		v2 = loadString_sub_40F1D0((char*)&byte_587000[92596], 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 757);
		break;
	case 2:
		v2 = loadString_sub_40F1D0((char*)&byte_587000[92540], 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 752);
		break;
	case 3:
		v2 = loadString_sub_40F1D0((char*)&byte_587000[92304], 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 732);
		break;
	case 4:
		v2 = loadString_sub_40F1D0((char*)&byte_587000[92252], 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 727);
		break;
	case 5:
		v2 = loadString_sub_40F1D0((char*)&byte_587000[92124], 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 718);
		break;
	case 8:
		v2 = loadString_sub_40F1D0((char*)&byte_587000[92484], 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 747);
		break;
	case 10:
		v2 = loadString_sub_40F1D0((char*)&byte_587000[92056], 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 713);
		break;
	case 11:
		v2 = loadString_sub_40F1D0((char*)&byte_587000[91992], 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 708);
		break;
	case 17:
		v2 = loadString_sub_40F1D0((char*)&byte_587000[92192], 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 722);
		break;
	case 19:
		v2 = loadString_sub_40F1D0((char*)&byte_587000[92424], 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 742);
		break;
	case 20:
		v2 = loadString_sub_40F1D0((char*)&byte_587000[92364], 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 737);
		break;
	default:
		v2 = loadString_sub_40F1D0((char*)&byte_587000[92720], 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 767);
		break;
	}
	sub_449A10(0, (int)v1, (int)v2, 33, 0, 0);
	sub_44A360(1);
}

//----- (0043D260) --------------------------------------------------------
void __cdecl sub_43D260(int a1, int a2) {
	wchar_t* v2;     // eax
	wchar_t v3[256]; // [esp+8h] [ebp-200h]

	if (a1) {
		if (a2) {
			v2 = loadString_sub_40F1D0((char*)&byte_587000[92784], 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c",
									   784);
			nox_swprintf(v3, v2, a1, a2);
			sub_445490(v3);
		}
	}
}
