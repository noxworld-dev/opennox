#include "client__network__netclint.h"

#include "GAME1_3.h"
#include "client__gui__guimsg.h"
#include "client__gui__window.h"
#include "common__strman.h"

//----- (0043D0A0) --------------------------------------------------------
void nox_client_showConnError_43D0A0(int a1) {
	wchar_t* v1; // esi
	wchar_t* v2; // eax

	v1 = nox_strman_loadString_40F1D0("ConnectionError", 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 702);
	switch (a1 + 23) {
	case 0:
		v2 = nox_strman_loadString_40F1D0("ConnectAckTimeout", 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 762);
		break;
	case 1:
		v2 = nox_strman_loadString_40F1D0("SocketCreate", 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 757);
		break;
	case 2:
		v2 = nox_strman_loadString_40F1D0("WinsockInit", 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 752);
		break;
	case 3:
		v2 = nox_strman_loadString_40F1D0("VersionConflict", 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 732);
		break;
	case 4:
		v2 = nox_strman_loadString_40F1D0("Timeout", 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 727);
		break;
	case 5:
		v2 = nox_strman_loadString_40F1D0("JoinConnTooManyUsers", 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c",
										  718);
		break;
	case 8:
		v2 = nox_strman_loadString_40F1D0("InvalidPort", 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 747);
		break;
	case 10:
		v2 = nox_strman_loadString_40F1D0("JoinConnUserNotAllowed", 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c",
										  713);
		break;
	case 11:
		v2 =
			nox_strman_loadString_40F1D0("JoinConnUserBanned", 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 708);
		break;
	case 17:
		v2 = nox_strman_loadString_40F1D0("JoinConnRefused", 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 722);
		break;
	case 19:
		v2 = nox_strman_loadString_40F1D0("InvalidAddress", 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 742);
		break;
	case 20:
		v2 = nox_strman_loadString_40F1D0("InvalidHandle", 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 737);
		break;
	default:
		v2 = nox_strman_loadString_40F1D0("UnknownConnError", 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 767);
		break;
	}
	nox_xxx_dialogMsgBoxCreate_449A10(0, (int)v1, (int)v2, 33, 0, 0);
	sub_44A360(1);
}

//----- (0043D260) --------------------------------------------------------
void sub_43D260(int a1, int a2) {
	wchar_t* v2;     // eax
	wchar_t v3[256]; // [esp+8h] [ebp-200h]

	if (a1) {
		if (a2) {
			v2 = nox_strman_loadString_40F1D0("WolPage", 0, "C:\\NoxPost\\src\\Client\\Network\\netclint.c", 784);
			nox_swprintf(v3, v2, a1, a2);
			nox_xxx_printCentered_445490(v3);
		}
	}
}
