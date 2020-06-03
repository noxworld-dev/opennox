#include "optsback.h"

#include "../../proto.h"
#include "noxworld.h"

//----- (004A18E0) --------------------------------------------------------
int __cdecl sub_4A18E0(int a1, int a2, int a3, int a4) {
	wchar_t* v5; // eax
	wchar_t* v6; // [esp-10h] [ebp-10h]

	if (sub_450560())
		return 1;
	if (a2 == 21 && a3 == 1) {
		if (a4 != 2)
			return 1;
		if (sub_43BE30()) {
		LABEL_15:
			if (sub_4D6F30())
				sub_4D6F90(2);
			return 1;
		}
		if (!sub_44A4A0()) {
			if (sub_43BE10() == 10000) {
				sub_4373A0();
			} else if (sub_43BE10() == 100) {
				v6 = loadString_sub_40F1D0((char*)&byte_587000[168540], 0,
							   "C:\\NoxPost\\src\\client\\shell\\OptsBack.c", 65);
				v5 = loadString_sub_40F1D0((char*)&byte_587000[168608], 0,
							   "C:\\NoxPost\\src\\client\\shell\\OptsBack.c", 64);
				sub_449A10(*(int*)&byte_5D4594[1307292], (int)v5, (int)v6, 56, sub_4A19D0, 0);
			} else {
				if (sub_43BE10() == 700)
					sub_4A7A60(1);
				sub_43C1E0();
			}
			goto LABEL_15;
		}
	}
	return 0;
}
//----- (004A19F0) --------------------------------------------------------
int __cdecl sub_4A19F0(char* a1) {
	_DWORD* v1;  // esi
	wchar_t* v2; // eax

	v1 = sub_46B0C0(*(_DWORD**)&byte_5D4594[1307292], 152);
	v2 = loadString_sub_40F1D0(a1, 0, "C:\\NoxPost\\src\\client\\shell\\OptsBack.c", 171);
	return nox_window_call_field_94((int)v1, 16385, (int)v2, -1);
}

//----- (004A1AA0) --------------------------------------------------------
int __cdecl sub_4A1AA0(int a1, int a2, int* a3, int a4) {
	int v3;      // eax
	wchar_t* v4; // eax
	wchar_t* v6; // [esp-10h] [ebp-10h]

	if (a2 == 16389) {
		sub_452D80(920, 100);
	} else {
		if (a2 != 16391)
			return 0;
		if (sub_43BE30() != 2 && sub_43BE30() != 3 || sub_4D6F30()) {
			v3 = sub_46B0A0(a3) - 151;
			if (v3) {
				if (v3 == 1) {
					if (sub_43BE10() == 100) {
						v6 = loadString_sub_40F1D0(
						    (char*)&byte_587000[168732], 0,
						    "C:\\NoxPost\\src\\client\\shell\\OptsBack.c", 142);
						v4 = loadString_sub_40F1D0(
						    (char*)&byte_587000[168800], 0,
						    "C:\\NoxPost\\src\\client\\shell\\OptsBack.c", 141);
						sub_449A10(*(int*)&byte_5D4594[1307292], (int)v4, (int)v6, 56,
							   sub_4A19D0, 0);
					} else {
						if (sub_4D6F30())
							sub_4D6F90(2);
						if (sub_43BE10() == 700)
							sub_4A7A60(1);
						sub_43C1E0();
					}
				}
			} else {
				if (sub_43BE10() == 700)
					sub_4A7A60(0);
				sub_43C220();
			}
			sub_452D80(921, 100);
			return 0;
		}
	}
	return 1;
}
