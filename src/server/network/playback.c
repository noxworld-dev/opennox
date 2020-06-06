#include "../../client/system/parsecmd.h"
#include "sdecode.h"

#include "../../proto.h"
extern _DWORD dword_5d4594_1548736;
extern _DWORD dword_5d4594_1548732;
extern _DWORD dword_587000_197428;

//----- (004D3580) --------------------------------------------------------
int __cdecl sub_4D3580_net_playback(int a1) {
	int v1;          // esi
	wchar_t* v2;     // esi
	wchar_t* v3;     // eax
	int result;      // eax
	unsigned int v5; // [esp+8h] [ebp-264h]
	int v6;          // [esp+Ch] [ebp-260h]
	int v7;          // [esp+10h] [ebp-25Ch]
	int v8;          // [esp+14h] [ebp-258h]
	int v9;          // [esp+18h] [ebp-254h]
	char v10[80];    // [esp+1Ch] [ebp-250h]
	char v11[512];   // [esp+6Ch] [ebp-200h]

	v1 = 0;
	if (*(int*)&dword_587000_197428 == -1) {
		v1 = 1;
	LABEL_30:
		sub_4D3530();
		sub_43DDD0(0);
		sub_43DE60();
		return v1;
	}
	if (!dword_5d4594_1548732) {
		if (_read(*(int*)&dword_587000_197428, &byte_5D4594[1548728], 4u))
			dword_5d4594_1548732 = 1;
		else
			v1 = 1;
	}
	if (!dword_5d4594_1548736) {
		if (!_read(*(int*)&dword_587000_197428, &byte_5D4594[1548724], 1u)) {
			v1 = 1;
			goto LABEL_30;
		}
		dword_5d4594_1548736 = 1;
	}
	if (v1)
		goto LABEL_30;
	while (*(_DWORD*)&byte_5D4594[2598000] == *(_DWORD*)&byte_5D4594[1548728]) {
		switch (byte_5D4594[1548724]) {
		case 1u:
			if (a1 == 1)
				return v1;
			_read(*(int*)&dword_587000_197428, &v9, 1u);
			_read(*(int*)&dword_587000_197428, &v5, 4u);
			_read(*(int*)&dword_587000_197428, &byte_5D4594[1548740], v5);
			sub_51BAD0_net_sdecode((unsigned __int8)v9, &byte_5D4594[1548740], v5);
			break;
		case 2u:
			if (a1 == 1)
				return v1;
			_read(*(int*)&dword_587000_197428, &v6, 1u);
			_read(*(int*)&dword_587000_197428, v10, (unsigned __int8)v6);
			sub_409D70(v10);
			_read(*(int*)&dword_587000_197428, &v7, 4u);
			if ((v7 & 0xFF0000) != 0x10000) {
				v2 = loadString_sub_40F1D0((char*)&byte_587000[197480], 0,
							   "C:\\NoxPost\\src\\Server\\Network\\playback.c", 355);
				v3 = loadString_sub_40F1D0((char*)&byte_587000[197540], 0,
							   "C:\\NoxPost\\src\\Server\\Network\\playback.c", 356);
				nullsub_4(0, v2, v3, 1);
				sub_43DDD0(0);
				sub_43DE60();
				v1 = 1;
			}
			break;
		case 3u:
			if (a1 == 1) {
				_read(*(int*)&dword_587000_197428, &v8, 4u);
				_read(*(int*)&dword_587000_197428, v11, 2 * v8);
				nox_server_parseCmdText_443C80((wchar_t*)v11, 0);
			}
			break;
		case 4u:
			if (a1 == 1)
				return v1;
			sub_43DDD0(0);
			sub_43DE60();
			break;
		default:
			break;
		}
		if (!_read(*(int*)&dword_587000_197428, &byte_5D4594[1548728], 4u)) {
			result = v1;
			dword_5d4594_1548732 = 0;
			return result;
		}
		if (!_read(*(int*)&dword_587000_197428, &byte_5D4594[1548724], 1u)) {
			result = v1;
			dword_5d4594_1548736 = 0;
			return result;
		}
		if (v1)
			goto LABEL_30;
	}
	return v1;
}
// 4514E0: using guessed type void __cdecl nullsub_4(_DWORD, _DWORD, _DWORD, _DWORD);
