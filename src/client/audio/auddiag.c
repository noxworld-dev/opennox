#include "auddiag.h"
#include "../../proto.h"
extern _DWORD dword_5d4594_831092;
extern _DWORD dword_5d4594_831084;
extern _DWORD dword_587000_122848;
extern _DWORD dword_5d4594_830864;
extern _DWORD dword_5d4594_830872;

//----- (0044D810) --------------------------------------------------------
int sub_44D810() {
	int v1; // [esp+4h] [ebp-4h]

	if (!*(unsigned int*)&byte_5D4594[831076]) {
		*(unsigned int*)&dword_5d4594_831092 = sub_43F130();
		*(unsigned int*)&dword_587000_122848 = *(unsigned int*)&dword_5d4594_831092 != 0;
		sub_4864A0(&byte_5D4594[830876]);
		sub_486380(&byte_5D4594[830876], 0x1F4u, 0, 0x4000);
		*(unsigned int*)&dword_5d4594_830864 = 0;
		*(unsigned int*)&byte_5D4594[830972] = 0;
		*(unsigned int*)&dword_5d4594_830872 = 0;
		*(unsigned int*)&byte_5D4594[831080] = 0;
		*(unsigned int*)&dword_5d4594_831084 = 0;
		*(unsigned int*)&byte_5D4594[831076] = 1;
		loadString_sub_40F1D0((char*)&byte_587000[122920], &v1, "C:\\NoxPost\\src\\client\\Audio\\AudDiag.c",
				      279);
		if (v1)
			sub_44D900(v1, 0);
	}
	return 1;
}
