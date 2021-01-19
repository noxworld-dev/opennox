#include "arnamain.h"

#include "../../proto.h"
#include "noxworld.h"
#include "wolapi/wollogin.h"
extern _DWORD dword_5d4594_1309708;
extern _DWORD dword_5d4594_1309716;

//----- (004AA4D0) --------------------------------------------------------
int __cdecl nox_xxx_windowArenaSub_4AA4D0(int a1, unsigned int a2, int* a3, int a4) {
	int v4;      // eax
	wchar_t* v5; // eax
	wchar_t* v6; // eax
	wchar_t* v7; // [esp-10h] [ebp-10h]
	wchar_t* v8; // [esp-10h] [ebp-10h]

	if (a2 != 16389) {
		if (a2 != 16391)
			return 0;
		if (*(_BYTE*)(dword_5d4594_1309708 + 64) && !nox_common_gameFlags_check_40A5C0(0x2000000) && !sub_4D6F30())
			goto LABEL_17;
		v4 = nox_xxx_wndGetID_46B0A0(a3) - 411;
		if (v4) {
			if (v4 != 10) {
			LABEL_17:
				nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
				return 1;
			}
			sub_4AA450();
			*(_DWORD*)(dword_5d4594_1309708 + 52) = sub_4379F0;
			sub_43AF50(0);
		} else {
			if (!sub_41D440()) {
				v7 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 172696), 0,
										   "C:\\NoxPost\\src\\client\\shell\\ArnaMain.c", 100);
				v5 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 172756), 0,
										   "C:\\NoxPost\\src\\client\\shell\\ArnaMain.c", 100);
				nox_xxx_dialogMsgBoxCreate_449A10(*(int*)&dword_5d4594_1309716, (int)v5, (int)v7, 33, 0, 0);
				return 0;
			}
			if (sub_40D5B0((int)&a2) && a2 < 0x10009) {
				sub_41D4C0();
				v8 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 172804), 0,
										   "C:\\NoxPost\\src\\client\\shell\\ArnaMain.c", 111);
				v6 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 172864), 0,
										   "C:\\NoxPost\\src\\client\\shell\\ArnaMain.c", 111);
				nox_xxx_dialogMsgBoxCreate_449A10(*(int*)&dword_5d4594_1309716, (int)v6, (int)v8, 33, 0, 0);
				return 0;
			}
			sub_4A1A40(0);
			sub_4AA450();
			*(_DWORD*)(dword_5d4594_1309708 + 52) = sub_44A560_wol_login;
		}
		nox_common_gameFlags_unset_40A540(0x1000000);
		goto LABEL_17;
	}
	nox_xxx_clientPlaySoundSpecial_452D80(920, 100);
	return 1;
}
