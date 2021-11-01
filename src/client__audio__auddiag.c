#include "client__audio__auddiag.h"
#include "GAME1.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_2.h"
#include "common__strman.h"
extern uint32_t dword_5d4594_831076;
extern uint32_t dword_5d4594_830972;
extern uint32_t dword_5d4594_831092;
extern uint32_t dword_5d4594_831084;
extern uint32_t dword_587000_122848;
extern uint32_t dword_5d4594_830864;
extern uint32_t dword_5d4594_830872;

//----- (0044D810) --------------------------------------------------------
int nox_xxx_WorkerHurt_44D810() {
	int v1; // [esp+4h] [ebp-4h]

	if (!*(unsigned int*)&dword_5d4594_831076) {
		*(unsigned int*)&dword_5d4594_831092 = sub_43F130();
		*(unsigned int*)&dword_587000_122848 = *(unsigned int*)&dword_5d4594_831092 != 0;
		sub_4864A0(getMemAt(0x5D4594, 830876));
		sub_486380(getMemAt(0x5D4594, 830876), 0x1F4u, 0, 0x4000);
		*(unsigned int*)&dword_5d4594_830864 = 0;
		*(unsigned int*)&dword_5d4594_830972 = 0;
		*(unsigned int*)&dword_5d4594_830872 = 0;
		*getMemUintPtr(0x5D4594, 831080) = 0;
		*(unsigned int*)&dword_5d4594_831084 = 0;
		*(unsigned int*)&dword_5d4594_831076 = 1;
		nox_strman_loadString_40F1D0("Con03B.scr:WorkerHurt", &v1, "C:\\NoxPost\\src\\client\\Audio\\AudDiag.c", 279);
		if (v1)
			nox_xxx_playDialogFile_44D900(v1, 0);
	}
	return 1;
}
