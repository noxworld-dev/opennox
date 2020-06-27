#include "wolpatch.h"

#include "../../proto.h"

//----- (0041E5D0) --------------------------------------------------------
wchar_t* sub_41E5D0() {
	wchar_t* result; // eax

	switch (*(_DWORD*)&byte_587000[59168]) {
	case 1:
		result =
			loadString_sub_40F1D0((char*)&byte_587000[59212], 0, "C:\\NoxPost\\src\\common\\WolAPI\\wolpatch.c", 101);
		break;
	case 2:
		result =
			loadString_sub_40F1D0((char*)&byte_587000[59268], 0, "C:\\NoxPost\\src\\common\\WolAPI\\wolpatch.c", 105);
		break;
	case 3:
		result =
			loadString_sub_40F1D0((char*)&byte_587000[59324], 0, "C:\\NoxPost\\src\\common\\WolAPI\\wolpatch.c", 109);
		break;
	case 4:
		result =
			loadString_sub_40F1D0((char*)&byte_587000[59376], 0, "C:\\NoxPost\\src\\common\\WolAPI\\wolpatch.c", 113);
		break;
	case 5:
		result =
			loadString_sub_40F1D0((char*)&byte_587000[59428], 0, "C:\\NoxPost\\src\\common\\WolAPI\\wolpatch.c", 117);
		break;
	case 6:
		result =
			loadString_sub_40F1D0((char*)&byte_587000[59488], 0, "C:\\NoxPost\\src\\common\\WolAPI\\wolpatch.c", 121);
		break;
	case 7:
		result =
			loadString_sub_40F1D0((char*)&byte_587000[59544], 0, "C:\\NoxPost\\src\\common\\WolAPI\\wolpatch.c", 125);
		break;
	default:
		result =
			loadString_sub_40F1D0((char*)&byte_587000[59600], 0, "C:\\NoxPost\\src\\common\\WolAPI\\wolpatch.c", 129);
		break;
	}
	return result;
}
