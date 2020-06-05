#include "../../proto.h"
extern _DWORD dword_5d4594_251704;
extern _DWORD dword_5d4594_251712;
extern _DWORD dword_5d4594_251708;
extern _DWORD dword_5d4594_251700;

//----- (00413520) --------------------------------------------------------
int sub_413520_gamedisk() {
	unsigned __int64 v0; // rax
	int v1;              // eax
	wchar_t* v2;         // eax
	__int64 v3;          // rax
	wchar_t* v5;         // [esp-10h] [ebp-1Ch]
	int v6;              // [esp-Ch] [ebp-18h]
	int (*v7)();         // [esp-8h] [ebp-14h]
	int (*v8)();         // [esp-4h] [ebp-10h]

	LODWORD(v0) = dword_5d4594_251700;
	switch (dword_5d4594_251700) {
	case 1:
		// XXX NO CD
		// v1 = sub_423CF0();
		v1 = 2;
		dword_5d4594_251704 = v1;
		if (!v1) {
			sub_4137C0();
			sub_44D8F0();
			if (nox_common_gameFlags_check_40A5C0(2048))
				sub_4137A0();
			v8 = sub_413760;
			v7 = sub_413780;
			v6 = 35;
			v5 = loadString_sub_40F1D0((char*)&byte_587000[32036], 0,
						   "C:\\NoxPost\\src\\common\\System\\gamedisk.c", 200);
			v2 = loadString_sub_40F1D0((char*)&byte_587000[32088], 0,
						   "C:\\NoxPost\\src\\common\\System\\gamedisk.c", 199);
			goto LABEL_9;
		}
		if (v1 == 1 && nox_common_gameFlags_check_40A5C0(2048)) {
			sub_4137C0();
			sub_44D8F0();
			sub_4137A0();
			v8 = sub_413760;
			v7 = sub_413780;
			v6 = 35;
			v5 = loadString_sub_40F1D0((char*)&byte_587000[32140], 0,
						   "C:\\NoxPost\\src\\common\\System\\gamedisk.c", 219);
			v2 = loadString_sub_40F1D0((char*)&byte_587000[32192], 0,
						   "C:\\NoxPost\\src\\common\\System\\gamedisk.c", 218);
			goto LABEL_9;
		}
		sub_4137E0();
		LODWORD(v0) = sub_413800();
		dword_5d4594_251700 = 6;
		*(_DWORD*)&byte_5D4594[251728] = 0;
		break;
	case 2:
		v3 = sub_416BB0();
		*(_QWORD*)&byte_5D4594[251628] = v3;
		v0 = v3 - *(_QWORD*)&byte_5D4594[251732];
		if (v0 > 0x7D0) {
			sub_423C60();
			LODWORD(v0) = *(_DWORD*)&byte_5D4594[251628];
			dword_5d4594_251700 = 3;
			*(_DWORD*)&byte_5D4594[251732] = *(_DWORD*)&byte_5D4594[251628];
			*(_DWORD*)&byte_5D4594[251736] = *(_DWORD*)&byte_5D4594[251632];
		}
		break;
	case 3:
		LODWORD(v0) = dword_5d4594_251708;
		if (dword_5d4594_251708) {
			LODWORD(v0) = dword_5d4594_251712;
			dword_5d4594_251708 = 0;
			if (dword_5d4594_251712) {
				dword_5d4594_251712 = 0;
				dword_5d4594_251700 = 1;
			} else {
				dword_5d4594_251700 = 2;
			}
		}
		break;
	case 4:
		v8 = 0;
		v7 = sub_413760;
		v6 = 33;
		v5 = loadString_sub_40F1D0((char*)&byte_587000[32244], 0,
					   "C:\\NoxPost\\src\\common\\System\\gamedisk.c", 293);
		v2 = loadString_sub_40F1D0((char*)&byte_587000[32296], 0,
					   "C:\\NoxPost\\src\\common\\System\\gamedisk.c", 292);
	LABEL_9:
		sub_449A10(0, (int)v2, (int)v5, v6, v7, v8);
		sub_44A360(0);
		LODWORD(v0) = sub_44A4B0();
		dword_5d4594_251700 = 6;
		break;
	case 6:
		return v0;
	default:
		sub_43DDD0(0);
		LODWORD(v0) = sub_43DE60();
		break;
	}
	return v0;
}