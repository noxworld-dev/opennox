//+build none

#include "common__random.h"
#include "client__system__parsecmd.h"
#include "common__strman.h"
#include "server__network__sdecode.h"
#include "server__network__playback.h"

#ifdef _WIN32
#include <io.h>
#else
#include "windows_compat.h"
#endif

#include "GAME1.h"
#include "GAME1_3.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME5_2.h"
extern unsigned int nox_frame_xxx_2598000;

uint32_t dword_5d4594_1548732 = 0;
uint32_t dword_5d4594_1548736 = 0;
int nox_xxx_replayFile_587000_197428 = -1;
int nox_xxx_replayWriteFile_587000_197424 = -1;

//----- (004D3370) --------------------------------------------------------
int  nox_xxx_replayStartSave_4D3370(char* a1) {
	nox_xxx_replayWriteFile_587000_197424 = _open(a1, 33537, 384);
	if (nox_xxx_replayWriteFile_587000_197424 == -1) {
		return 0;
	}
	nox_common_setEngineFlag(NOX_ENGINE_FLAG_REPLAY_WRITE);
	return 1;
}

//----- (004D33B0) --------------------------------------------------------
void nox_xxx_replayStopSave_4D33B0() {
	if (nox_xxx_replayWriteFile_587000_197424 != -1) {
		_close(nox_xxx_replayWriteFile_587000_197424);
	}
	nox_xxx_replayWriteFile_587000_197424 = -1;
	nox_common_resetEngineFlag(NOX_ENGINE_FLAG_REPLAY_WRITE);
}

//----- (004D33E0) --------------------------------------------------------
void nox_xxx_replaySaveConsole_4D33E0(void* a1, int a2) {
	if (nox_xxx_replayWriteFile_587000_197424 != -1 && a1 && a2 >= 1) {
		_write(nox_xxx_replayWriteFile_587000_197424, &nox_frame_xxx_2598000, 4u);
		_write(nox_xxx_replayWriteFile_587000_197424, getMemAt(0x587000, 197432), 1u);
		_write(nox_xxx_replayWriteFile_587000_197424, &a2, 4u);
		_write(nox_xxx_replayWriteFile_587000_197424, a1, 2 * a2);
	}
}

//----- (004D3450) --------------------------------------------------------
void nox_xxx_replayWriteMSgMB_4D3450(nox_playerInfo* pl, void* a2, unsigned int a3) {
	int a1 = pl;
	if (nox_xxx_replayWriteFile_587000_197424 != -1) {
		_write(nox_xxx_replayWriteFile_587000_197424, &nox_frame_xxx_2598000, 4u);
		_write(nox_xxx_replayWriteFile_587000_197424, getMemAt(0x587000, 197433), 1u);
		_write(nox_xxx_replayWriteFile_587000_197424, (const void*)(a1 + 2064), 1u);
		_write(nox_xxx_replayWriteFile_587000_197424, &a3, 4u);
		_write(nox_xxx_replayWriteFile_587000_197424, a2, a3);
	}
}

//----- (004D34C0) --------------------------------------------------------
int  nox_xxx_replayFileOpen_4D34C0(char* a1) {
	char* v2; // eax

	nox_xxx_replayFile_587000_197428 = _open(a1, 0x8000);
	if (nox_xxx_replayFile_587000_197428 == -1) {
		return 0;
	}
	dword_5d4594_1548732 = 0;
	dword_5d4594_1548736 = 0;
	*getMemU32Ptr(0x5D4594, 1548728) = 0;
	*getMemU8Ptr(0x5D4594, 1548724) = 0;
	nox_common_setEngineFlag(NOX_ENGINE_FLAG_REPLAY_READ);
	v2 = nox_common_playerInfoGetByID_417040(255);
	nox_xxx_playerGoObserver_4E6860((int)v2, 0, 1);
	return 1;
}

//----- (004D3530) --------------------------------------------------------
void nox_xxx_replayStopReadMB_4D3530() {
	char* v0; // eax

	if (nox_xxx_replayFile_587000_197428 != -1) {
		_close(nox_xxx_replayFile_587000_197428);
	}
	nox_xxx_replayFile_587000_197428 = -1;
	dword_5d4594_1548732 = 0;
	dword_5d4594_1548736 = 0;
	nox_common_resetEngineFlag(NOX_ENGINE_FLAG_REPLAY_READ);
	v0 = nox_common_playerInfoGetByID_417040(255);
	nox_xxx_playerLeaveObserver_0_4E6AA0((int)v0);
}

//----- (004D3860) --------------------------------------------------------
void  nox_xxx_replay_4D3860(void* a1) {
	if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_REPLAY_WRITE) && (nox_xxx_replayWriteFile_587000_197424 != -1)) {
		nox_xxx_replayWriteRndCounter_415F30(nox_xxx_replayWriteFile_587000_197424);
		_write(nox_xxx_replayWriteFile_587000_197424, a1, 153);
	} else if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_REPLAY_READ)) {
		if (nox_xxx_replayFile_587000_197428 != -1) {
			nox_xxx_replayReadeRndCounter_415F50(nox_xxx_replayFile_587000_197428);
			_read(nox_xxx_replayFile_587000_197428, a1, 153);
		}
	}
}

//----- (004D38D0) --------------------------------------------------------
int nox_xxx_replayStartReadingOrSaving_4D38D0() {
	int result; // eax
	int v2;     // [esp+0h] [ebp-4h]

	if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_REPLAY_WRITE) && nox_xxx_replayWriteFile_587000_197424 != -1) {
		_write(nox_xxx_replayWriteFile_587000_197424, &nox_frame_xxx_2598000, 4u);
		_write(nox_xxx_replayWriteFile_587000_197424, getMemAt(0x587000, 197434), 1u);
		*getMemU32Ptr(0x5D4594, 1549764) = nox_server_currentMapGetFilename_409B30();
		*getMemU8Ptr(0x5D4594, 1548725) = strlen(*(const char**)getMemAt(0x5D4594, 1549764)) + 1;
		_write(nox_xxx_replayWriteFile_587000_197424, getMemAt(0x5D4594, 1548725), 1u);
		_write(nox_xxx_replayWriteFile_587000_197424, *(const void**)getMemAt(0x5D4594, 1549764), getMemByte(0x5D4594, 1548725));
		v2 = NOX_CLIENT_VERS_CODE;
		_write(nox_xxx_replayWriteFile_587000_197424, &v2, 4u);
		result = 0;
	} else if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_REPLAY_READ) && *(int*)&nox_xxx_replayFile_587000_197428 != -1) {
		result = nox_xxx_replayTickMB_4D3580_net_playback(0);
	} else {
		result = 0;
	}
	return result;
}

//----- (004D39B0) --------------------------------------------------------
void nox_xxx_replayWriteFrame_4D39B0() {
	if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_REPLAY_WRITE)) {
		if (nox_xxx_replayWriteFile_587000_197424 != -1) {
			_write(nox_xxx_replayWriteFile_587000_197424, &nox_frame_xxx_2598000, 4u);
			_write(nox_xxx_replayWriteFile_587000_197424, getMemAt(0x587000, 197435), 1u);
		}
	}
}

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
	if (nox_xxx_replayFile_587000_197428 == -1) {
		v1 = 1;
	} else {
		if (!dword_5d4594_1548732) {
			if (_read(nox_xxx_replayFile_587000_197428, getMemAt(0x5D4594, 1548728), 4u)) {
				dword_5d4594_1548732 = 1;
			} else {
				v1 = 1;
			}
		}
		if (!dword_5d4594_1548736) {
			if (_read(nox_xxx_replayFile_587000_197428, getMemAt(0x5D4594, 1548724), 1u)) {
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
			_read(nox_xxx_replayFile_587000_197428, &v9, 1u);
			_read(nox_xxx_replayFile_587000_197428, &v5, 4u);
			_read(nox_xxx_replayFile_587000_197428, getMemAt(0x5D4594, 1548740), v5);
			nox_xxx_netOnPacketRecvServ_51BAD0_net_sdecode((unsigned char)v9, getMemAt(0x5D4594, 1548740), v5);
			break;
		case 2u:
			if (a1 == 1) {
				return v1;
			}
			_read(nox_xxx_replayFile_587000_197428, &v6, 1u);
			_read(nox_xxx_replayFile_587000_197428, v10, (unsigned char)v6);
			nox_xxx_gameSetMapPath_409D70(v10);
			_read(nox_xxx_replayFile_587000_197428, &v7, 4u);
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
				_read(nox_xxx_replayFile_587000_197428, &v8, 4u);
				_read(nox_xxx_replayFile_587000_197428, v11, 2 * v8);
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
		if (!_read(nox_xxx_replayFile_587000_197428, getMemAt(0x5D4594, 1548728), 4u)) {
			dword_5d4594_1548732 = 0;
			return v1;
		}
		if (!_read(nox_xxx_replayFile_587000_197428, getMemAt(0x5D4594, 1548724), 1u)) {
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
