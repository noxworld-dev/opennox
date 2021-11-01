#include "common__wolapi__wolpatch.h"

#include "common__strman.h"
#include "client__gui__window.h"

//----- (0041E5D0) --------------------------------------------------------
wchar_t* sub_41E5D0() {
	wchar_t* result; // eax

	switch (*getMemU32Ptr(0x587000, 59168)) {
	case 1:
		result =
			nox_strman_loadString_40F1D0("NoSuchServer", 0, "C:\\NoxPost\\src\\common\\WolAPI\\wolpatch.c", 101);
		break;
	case 2:
		result =
			nox_strman_loadString_40F1D0("CouldNotConnect", 0, "C:\\NoxPost\\src\\common\\WolAPI\\wolpatch.c", 105);
		break;
	case 3:
		result =
			nox_strman_loadString_40F1D0("LoginFailed", 0, "C:\\NoxPost\\src\\common\\WolAPI\\wolpatch.c", 109);
		break;
	case 4:
		result =
			nox_strman_loadString_40F1D0("NoSuchFile", 0, "C:\\NoxPost\\src\\common\\WolAPI\\wolpatch.c", 113);
		break;
	case 5:
		result =
			nox_strman_loadString_40F1D0("LocalFileOpenFailed", 0, "C:\\NoxPost\\src\\common\\WolAPI\\wolpatch.c", 117);
		break;
	case 6:
		result =
			nox_strman_loadString_40F1D0("InternalError", 0, "C:\\NoxPost\\src\\common\\WolAPI\\wolpatch.c", 121);
		break;
	case 7:
		result =
			nox_strman_loadString_40F1D0("disconnecterror", 0, "C:\\NoxPost\\src\\common\\WolAPI\\wolpatch.c", 125);
		break;
	default:
		result =
			nox_strman_loadString_40F1D0("UnknownError", 0, "C:\\NoxPost\\src\\common\\WolAPI\\wolpatch.c", 129);
		break;
	}
	return result;
}
