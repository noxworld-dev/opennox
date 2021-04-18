#include "proto.h"
#include "common__net_list.h"

//----- (00528AC0) --------------------------------------------------------
int  nox_xxx_netSendChat_528AC0(int a1, wchar_t* a2, wchar_t a3) {
	char v3;       // al
	__int16 v4;    // ax
	double v5;     // st7
	__int64 v6;    // rax
	double v7;     // st7
	int v8;        // edi
	int result;    // eax
	int i;         // esi
	char v11[520]; // [esp+8h] [ebp-208h]

	v11[0] = -88;
	v11[3] = 0;
	if (nox_xxx_cliCanTalkMB_4100F0((__int16*)a2))
		v3 = v11[3] | 2;
	else
		v3 = v11[3] | 4;
	v11[3] = v3;
	v4 = nox_xxx_netGetUnitCodeServ_578AC0((_DWORD*)a1);
	v5 = *(float*)(a1 + 56);
	*(_WORD*)&v11[1] = v4;
	v6 = (__int64)v5;
	v7 = *(float*)(a1 + 60);
	*(_WORD*)&v11[4] = v6;
	*(_WORD*)&v11[6] = (__int64)v7;
	*(_WORD*)&v11[9] = a3;
	v11[8] = nox_wcslen(a2) + 1;
	if (v11[3] & 4) {
		nox_wcscpy((wchar_t*)&v11[11], a2);
		v8 = 2;
	} else {
		nox_sprintf(&v11[11], "%S", a2);
		v8 = 1;
	}
	result = nox_xxx_getFirstPlayerUnit_4DA7C0();
	for (i = result; result; i = result) {
		nox_netlist_addToMsgListCli_40EBC0(*(unsigned __int8*)(*(_DWORD*)(*(_DWORD*)(i + 748) + 276) + 2064), 1, v11,
				   v8 * (unsigned __int8)v11[8] + 11);
		result = nox_xxx_getNextPlayerUnit_4DA7F0(i);
	}
	return result;
}
