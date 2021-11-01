#include "client__system__parsecmd.h"
#include "common__strman.h"
#include "server__network__sdecode.h"

#ifdef _WIN32
#include <io.h>
#else
#include "windows_compat.h"
#endif

#include "GAME1.h"
#include "GAME1_3.h"
#include "GAME3_2.h"
#include "GAME5_2.h"
extern uint32_t dword_5d4594_1548736;
extern uint32_t dword_5d4594_1548732;
extern uint32_t nox_xxx_replayFile_587000_197428;
extern unsigned int nox_frame_xxx_2598000;

//----- (004D3580) --------------------------------------------------------
int nox_xxx_replayTickMB_4D3580_net_playback(int a1) {
	int v1;          // esi
	wchar_t* v2;     // esi
	wchar_t* v3;     // eax
	unsigned int v5; // [esp+8h] [ebp-264h]
	int v6;          // [esp+Ch] [ebp-260h]
	int v7;          // [esp+10h] [ebp-25Ch]
	int v8;          // [esp+14h] [ebp-258h]
	int v9;          // [esp+18h] [ebp-254h]
	char v10[80];    // [esp+1Ch] [ebp-250h]
	char v11[512];   // [esp+6Ch] [ebp-200h]

	v1 = 0;
	if (*(int*)&nox_xxx_replayFile_587000_197428 == -1) {
		v1 = 1;
	} else {
		if (!dword_5d4594_1548732) {
			if (_read(*(int*)&nox_xxx_replayFile_587000_197428, getMemAt(0x5D4594, 1548728), 4u)) {
				dword_5d4594_1548732 = 1;
			} else {
				v1 = 1;
			}
		}
		if (!dword_5d4594_1548736) {
			if (_read(*(int*)&nox_xxx_replayFile_587000_197428, getMemAt(0x5D4594, 1548724), 1u)) {
				dword_5d4594_1548736 = 1;
			} else {
				v1 = 1;
			}
		}
	}
	if (v1) {
		nox_xxx_replayStopReadMB_4D3530();
		nox_xxx_setContinueMenuOrHost_43DDD0(0);
		nox_game_exit_xxx_43DE60();
		return v1;
	}
	if (nox_frame_xxx_2598000 == *getMemU32Ptr(0x5D4594, 1548728)) {
		return v1;
	}
	while (1) {
		switch (getMemByte(0x5D4594, 1548724)) {
		case 1u:
			if (a1 == 1) {
				return v1;
			}
			_read(*(int*)&nox_xxx_replayFile_587000_197428, &v9, 1u);
			_read(*(int*)&nox_xxx_replayFile_587000_197428, &v5, 4u);
			_read(*(int*)&nox_xxx_replayFile_587000_197428, getMemAt(0x5D4594, 1548740), v5);
			nox_xxx_netOnPacketRecvServ_51BAD0_net_sdecode((unsigned char)v9, getMemAt(0x5D4594, 1548740), v5);
			break;
		case 2u:
			if (a1 == 1) {
				return v1;
			}
			_read(*(int*)&nox_xxx_replayFile_587000_197428, &v6, 1u);
			_read(*(int*)&nox_xxx_replayFile_587000_197428, v10, (unsigned char)v6);
			nox_xxx_gameSetMapPath_409D70(v10);
			_read(*(int*)&nox_xxx_replayFile_587000_197428, &v7, 4u);
			if ((v7 & 0xFF0000) != 0x10000) {
				v2 = nox_strman_loadString_40F1D0("vcheckfailed", 0, "C:\\NoxPost\\src\\Server\\Network\\playback.c",
												  355);
				v3 = nox_strman_loadString_40F1D0("playbackerror", 0, "C:\\NoxPost\\src\\Server\\Network\\playback.c",
												  356);
				nullsub_4(0, v2, v3, 1);
				nox_xxx_setContinueMenuOrHost_43DDD0(0);
				nox_game_exit_xxx_43DE60();
				v1 = 1;
			}
			break;
		case 3u:
			if (a1 == 1) {
				_read(*(int*)&nox_xxx_replayFile_587000_197428, &v8, 4u);
				_read(*(int*)&nox_xxx_replayFile_587000_197428, v11, 2 * v8);
				nox_server_parseCmdText_443C80((wchar_t*)v11, 0);
			}
			break;
		case 4u:
			if (a1 == 1) {
				return v1;
			}
			nox_xxx_setContinueMenuOrHost_43DDD0(0);
			nox_game_exit_xxx_43DE60();
			break;
		default:
			break;
		}
		if (!_read(*(int*)&nox_xxx_replayFile_587000_197428, getMemAt(0x5D4594, 1548728), 4u)) {
			dword_5d4594_1548732 = 0;
			return v1;
		}
		if (!_read(*(int*)&nox_xxx_replayFile_587000_197428, getMemAt(0x5D4594, 1548724), 1u)) {
			dword_5d4594_1548736 = 0;
			return v1;
		}
		if (v1) {
			break;
		}
		if (nox_frame_xxx_2598000 == *getMemU32Ptr(0x5D4594, 1548728)) {
			return v1;
		}
	}
	nox_xxx_replayStopReadMB_4D3530();
	nox_xxx_setContinueMenuOrHost_43DDD0(0);
	nox_game_exit_xxx_43DE60();
	return v1;
}
// 4514E0: using guessed type void  nullsub_4(uint32_t, uint32_t, uint32_t, uint32_t);
