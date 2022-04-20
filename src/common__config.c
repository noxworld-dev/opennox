#include "common__config.h"
#include "GAME1.h"
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_2.h"
#include "GAME3_2.h"
#include "GAME5_2.h"
#include "client__gui__window.h"
#include "client__gui__guicon.h"
#include "client__system__ctrlevnt.h"
#include "client__video__draw_common.h"
#include "defs.h"
#include "input.h"
#include "server__script__builtin.h"

#include "client__video__draw_common.h"
#include "common/fs/nox_fs.h"
#include "common__system__settings.h"
#include "input.h"
#include "operators.h"

extern uint32_t dword_5d4594_1193156;
extern unsigned int nox_client_texturedFloors2_154960;
extern int nox_win_width_game;
extern int nox_win_height_game;
extern int nox_win_depth_game;
extern void* dword_587000_127004;
extern void* dword_587000_122852;
extern void* dword_587000_93164;
extern unsigned int nox_video_dxUnlockSurface;
extern uint32_t nox_client_drawFrontWalls_80812;
extern uint32_t nox_client_translucentFrontWalls_805844;
extern uint32_t nox_client_highResFrontWalls_80820;
extern uint32_t nox_client_highResFloors_154952;
extern uint32_t nox_client_lockHighResFloors_1193152;
extern uint32_t nox_client_texturedFloors_154956;
extern unsigned int nox_gui_console_translucent;
extern uint32_t nox_client_renderGlow_805852;
extern uint32_t nox_client_renderGUI_80828;
extern uint32_t nox_client_fadeObjects_80836;
extern uint32_t nox_client_renderBubbles_80844;
extern uint32_t nox_profiled_805856;
extern uint32_t nox_server_sanctuaryHelp_54276;
extern uint32_t nox_server_sendMotd_108752;
extern uint32_t nox_server_connectionType_3596;
extern uint32_t nox_server_resetQuestMinVotes_229988;
extern uint32_t nox_server_kickQuestPlayerMinVotes_229992;

int g_scaled_cfg = 0;
int g_fullscreen_cfg = 0;

//----- (00431890) --------------------------------------------------------
int nox_common_parsecfg_all(FILE* a1) {
	char* v1;          // eax
	char* v2;          // eax
	const char* v3;    // edi
	int v4;            // edx
	unsigned char* v5; // ebp

	sub_486670(0x4000, 0);
	sub_486670(0x4000, 1);
	sub_486670(0x4000, 2);
LABEL_2:
	while (nox_fs_fgets(a1, (char*)getMemAt(0x5D4594, 806084), 1024)) {
		if (getMemByte(0x5D4594, 806084) == '#') {
			continue;
		}
		v1 = strtok((char*)getMemAt(0x5D4594, 806084), " \r\t\n");
		if (!v1) {
			continue;
		}
		if (!strcmp(v1, "---")) {
			return 1;
		}
		if (!strcmp(v1, "Version")) {
			v2 = (char*)sub_432AD0(getMemIntPtr(0x587000, 81284));
			if (!v2) {
				return 0;
			}
		} else if (!strcmp(v1, "VideoMode")) {
			v2 = (char*)nox_common_parsecfg_videomode();
			if (!v2) {
				return 0;
			}
		} else if (!strcmp(v1, "VideoSize")) {
			v2 = (char*)nox_common_parsecfg_videosize();
			if (!v2) {
				return 0;
			}
		} else if (!strcmp(v1, "Gamma")) {
			v2 = (char*)sub_432C00();
			if (!v2) {
				return 0;
			}
		} else if (!strcmp(v1, "FXVolume")) {
			v2 = (char*)sub_432CB0(0);
			if (!v2) {
				return 0;
			}
		} else if (!strcmp(v1, "DialogVolume")) {
			v2 = (char*)sub_432CB0(1);
			if (!v2) {
				return 0;
			}
		} else if (!strcmp(v1, "MusicVolume")) {
			v2 = (char*)sub_432CB0(2);
			if (!v2) {
				return 0;
			}
		} else if (!strcmp(v1, "LastServer")) {
			v2 = (char*)sub_431FC0();
			if (!v2) {
				return 0;
			}
		} else if (!strcmp(v1, "ServerName")) {
			v2 = (char*)sub_432010();
			if (!v2) {
				return 0;
			}
		} else if (!strcmp(v1, "UnlockSurface")) {
			v2 = (char*)sub_4320B0();
			if (!v2) {
				return 0;
			}
		} else if (!strcmp(v1, "SoftShadowEdge")) {
			v2 = (char*)sub_432100();
			if (!v2) {
				return 0;
			}
		} else if (!strcmp(v1, "DrawFrontWalls")) {
			v2 = (char*)sub_432150();
			if (!v2) {
				return 0;
			}
		} else if (!strcmp(v1, "TranslucentFrontWalls")) {
			v2 = (char*)sub_4321A0();
			if (!v2) {
				return 0;
			}
		} else if (!strcmp(v1, "HighResFrontWalls")) {
			v2 = (char*)sub_4321F0();
			if (!v2) {
				return 0;
			}
		} else if (!strcmp(v1, "HighResFloors")) {
			v2 = (char*)sub_432240();
			if (!v2) {
				return 0;
			}
		} else if (!strcmp(v1, "LockHighResFloors")) {
			v2 = (char*)sub_432290();
			if (!v2) {
				return 0;
			}
		} else if (!strcmp(v1, "TexturedFloors")) {
			v2 = (char*)sub_4322E0();
			if (!v2) {
				return 0;
			}
		} else if (!strcmp(v1, "TranslucentConsole")) {
			v2 = (char*)sub_432340();
			if (!v2) {
				return 0;
			}
		} else if (!strcmp(v1, "RenderGlow")) {
			v2 = (char*)sub_432390();
			if (!v2) {
				return 0;
			}
		} else if (!strcmp(v1, "RenderGUI")) {
			v2 = (char*)sub_4323E0();
			if (!v2) {
				return 0;
			}
		} else if (!strcmp(v1, "FadeObjects")) {
			v2 = (char*)sub_432430();
			if (!v2) {
				return 0;
			}
		} else if (!strcmp(v1, "TrackData")) {
			v2 = (char*)sub_433190();
			if (!v2) {
				return 0;
			}
		} else if (!strcmp(v1, "RenderBubbles")) {
			v2 = (char*)sub_432480();
			if (!v2) {
				return 0;
			}
		} else if (!strcmp(v1, "SysopPassword")) {
			v2 = (char*)sub_4324D0();
			if (!v2) {
				return 0;
			}
		} else if (!strcmp(v1, "ServerPassword")) {
			v2 = (char*)sub_432520();
			if (!v2) {
				return 0;
			}
		} else if (!strcmp(v1, "Profiled")) {
			v2 = (char*)sub_432590();
			if (!v2) {
				return 0;
			}
		} else if (!strcmp(v1, "SanctuaryHelp")) {
			v2 = (char*)sub_432620();
			if (!v2) {
				return 0;
			}
		} else if (!strcmp(v1, "MaxPacketLossPct")) {
			v2 = (char*)sub_4325D0();
			if (!v2) {
				return 0;
			}
		} else if (!strcmp(v1, "SendMessageOfTheDay")) {
			v2 = (char*)sub_432A90();
			if (!v2) {
				return 0;
			}
		} else if (!strcmp(v1, "InternetUpdateRate")) {
			v2 = (char*)sub_432DF0();
			if (!v2) {
				return 0;
			}
		} else if (!strcmp(v1, "ConnectionType")) {
			v2 = (char*)sub_433050();
			if (!v2) {
				return 0;
			}
		} else if (!strcmp(v1, "MapCycle")) {
			v2 = (char*)sub_432C30();
			if (!v2) {
				return 0;
			}
		} else if (!strcmp(v1, "LANFilters")) {
			v2 = sub_432E50(0);
			if (!v2) {
				return 0;
			}
		} else if (!strcmp(v1, "INETFilters")) {
			v2 = sub_432E50(1);
			if (!v2) {
				return 0;
			}
		} else if (!strcmp(v1, "LessonLimit")) {
			if (!sub_432D10()) {
				return 0;
			}
		} else if (!strcmp(v1, "TimeLimit")) {
			if (!sub_432D80()) {
				return 0;
			}
		} else if (!strcmp(v1, "PlayerSkeletons")) {
			if (!sub_4327C0()) {
				return 0;
			}
		} else if (!strcmp(v1, "BroadcastGestures")) {
			if (!sub_432810()) {
				return 0;
			}
		} else if (!strcmp(v1, "LatencyCompensation")) {
			if (!sub_432970()) {
				return 0;
			}
		} else if (!strcmp(v1, "Closed")) {
			if (!sub_432860()) {
				return 0;
			}
		} else if (!strcmp(v1, "Private")) {
			if (!sub_4328C0()) {
				return 0;
			}
		} else if (!strcmp(v1, "AudioThreshold")) {
			if (!sub_433130()) {
				return 0;
			}
		} else if (!strcmp(v1, "MaxPlayers")) {
			if (!sub_4330C0()) {
				return 0;
			}
		} else if (!strcmp(v1, "RestrictedClasses")) {
			if (!sub_432920()) {
				return 0;
			}
		} else if (!strcmp(v1, "RestrictedPing")) {
			if (!sub_4329D0()) {
				return 0;
			}
		} else if (!strcmp(v1, "LimitMaxRes")) {
			if (!sub_432A30()) {
				return 0;
			}
		} else if (!strcmp(v1, "ItemRespawn")) {
			if (!sub_432660()) {
				return 0;
			}
		} else if (!strcmp(v1, "CamperAlarm")) {
			if (!sub_4326B0()) {
				return 0;
			}
		} else if (!strcmp(v1, "MinKickVotes")) {
			if (!sub_432700()) {
				return 0;
			}
		} else if (!strcmp(v1, "ResetQuestMinVotes")) {
			if (!sub_432740()) {
				return 0;
			}
		} else if (!strcmp(v1, "KickQuestPlayerMinVotes")) {
			if (!sub_432780()) {
				return 0;
			}
		} else if (!strcmp(v1, "Fullscreen")) {
			const char* token;
			strtok(NULL, " \r\t\n");
			token = strtok(NULL, " \r\t\n");
			if (token) {
				g_fullscreen_cfg = atoi(token);
				if (nox_video_getFullScreen() <= -4) {
					nox_video_setFullScreen(g_fullscreen_cfg);
				}
			}

			change_windowed_fullscreen();
		} else if (!strcmp(v1, "Gamma2")) {
			const char* token;
			strtok(NULL, " \r\t\n");
			token = strtok(NULL, " \r\t\n");
			if (token) {
				nox_video_setGamma(atof(token));
			}
		} else if (!strcmp(v1, "Stretched")) {
			const char* token;
			strtok(NULL, " \r\t\n");
			token = strtok(NULL, " \r\t\n");
			if (token) {
				g_scaled_cfg = atoi(token);
				if (nox_video_getScaled() >= 0) {
					nox_video_setScaled(g_scaled_cfg);
				}
			}
		} else if (!strcmp(v1, "InputSensitivity")) {
			const char* token;
			strtok(NULL, " \r\t\n");
			token = strtok(NULL, " \r\t\n");
			if (token) {
				nox_input_setSensitivity(atof(token));
			}
		} else {
			v3 = *(const char**)getMemAt(0x587000, 81168);
			v4 = 0;
			if (*getMemU32Ptr(0x587000, 81168)) {
				v5 = getMemAt(0x587000, 81168);
				while (strcmp(v1, v3)) {
					v3 = (const char*)*((uint32_t*)v5 + 2);
					v5 += 8;
					++v4;
					if (!v3) {
						goto LABEL_2;
					}
				}
				v2 = (char*)sub_432C70(*getMemU32Ptr(0x587000, 81172 + 8 * v4));
				if (!v2) {
					return 0;
				}
			}
		}
	}
	return 0;
}

//----- (00431FC0) --------------------------------------------------------
int sub_431FC0() {
	char* v0; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0) {
		strncpy((char*)getMemAt(0x5D4594, 806060), v0, 0x16u);
	} else {
		*getMemU8Ptr(0x5D4594, 806060) = getMemByte(0x5D4594, 807272);
	}
	return 1;
}

//----- (00432010) --------------------------------------------------------
int sub_432010() {
	char* v0;       // eax
	const char* v1; // esi
	int result;     // eax
	char* v3;       // eax
	char v4;        // cl
	char v5[64];    // [esp+4h] [ebp-40h]

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	v1 = v0;
	if (v0) {
		if (*getMemU32Ptr(0x587000, 81284) == 0x10000 && !_strcmpi(v0, "NoxWorld")) {
			v1 = "User_Game";
		}
		strncpy(v5, v1, 0x3Fu);
		v3 = v5;
		if (v5[0]) {
			do {
				if (*v3 == 95) {
					*v3 = 32;
				}
				v4 = *++v3;
			} while (v4);
		}
		nox_xxx_gameSetServername_40A440(v5);
		result = 1;
	} else {
		nox_xxx_gameSetServername_40A440(0);
		result = 1;
	}
	return result;
}

//----- (004320B0) --------------------------------------------------------
int sub_4320B0() {
	char* v0;   // eax
	int v1;     // eax
	bool v2;    // zf
	int result; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (!v0) {
		return 1;
	}
	v1 = atoi(v0);
	nox_video_dxUnlockSurface = v1;
	v2 = v1 == 0;
	result = 1;
	if (!v2) {
		nox_video_dxUnlockSurface = 1;
	}
	return result;
}

//----- (00432100) --------------------------------------------------------
int sub_432100() {
	char* v0; // eax
	bool v1;  // zf

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0) {
		v1 = atoi(v0) == 0;
		if (!v1) {
			nox_common_setEngineFlag(NOX_ENGINE_FLAG_ENABLE_SOFT_SHADOW_EDGE);
			return 1;
		}
		nox_common_resetEngineFlag(NOX_ENGINE_FLAG_ENABLE_SOFT_SHADOW_EDGE);
	}
	return 1;
}

//----- (00432150) --------------------------------------------------------
int sub_432150() {
	char* v0;   // eax
	int v1;     // eax
	bool v2;    // zf
	int result; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (!v0) {
		return 1;
	}
	v1 = atoi(v0);
	nox_client_drawFrontWalls_80812 = v1;
	v2 = v1 == 0;
	result = 1;
	if (!v2) {
		nox_client_drawFrontWalls_80812 = 1;
	}
	return result;
}

//----- (004321A0) --------------------------------------------------------
int sub_4321A0() {
	char* v0;   // eax
	int v1;     // eax
	bool v2;    // zf
	int result; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (!v0) {
		return 1;
	}
	v1 = atoi(v0);
	nox_client_translucentFrontWalls_805844 = v1;
	v2 = v1 == 0;
	result = 1;
	if (!v2) {
		nox_client_translucentFrontWalls_805844 = 1;
	}
	return result;
}

//----- (004321F0) --------------------------------------------------------
int sub_4321F0() {
	char* v0;   // eax
	int v1;     // eax
	bool v2;    // zf
	int result; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (!v0) {
		return 1;
	}
	v1 = atoi(v0);
	nox_client_highResFrontWalls_80820 = v1;
	v2 = v1 == 0;
	result = 1;
	if (!v2) {
		nox_client_highResFrontWalls_80820 = 1;
	}
	return result;
}

//----- (00432240) --------------------------------------------------------
int sub_432240() {
	char* v0;   // eax
	int v1;     // eax
	bool v2;    // zf
	int result; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (!v0) {
		return 1;
	}
	v1 = atoi(v0);
	nox_client_highResFloors_154952 = v1;
	v2 = v1 == 0;
	result = 1;
	if (!v2) {
		nox_client_highResFloors_154952 = 1;
	}
	return result;
}

//----- (00432290) --------------------------------------------------------
int sub_432290() {
	char* v0;   // eax
	int v1;     // eax
	bool v2;    // zf
	int result; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (!v0) {
		return 1;
	}
	v1 = atoi(v0);
	nox_client_lockHighResFloors_1193152 = v1;
	v2 = v1 == 0;
	result = 1;
	if (!v2) {
		nox_client_lockHighResFloors_1193152 = 1;
	}
	return result;
}

//----- (004322E0) --------------------------------------------------------
int sub_4322E0() {
	char* v0; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0) {
		nox_client_texturedFloors_154956 = atoi(v0);
		nox_client_texturedFloors_154956 = nox_client_texturedFloors_154956 != 0;
		nox_xxx_tileSetDrawFn_481420();
		dword_5d4594_1193156 = 0;
		nox_client_texturedFloors2_154960 = nox_client_texturedFloors_154956;
	}
	return 1;
}

//----- (00432340) --------------------------------------------------------
int sub_432340() {
	char* v0;   // eax
	int v1;     // eax
	bool v2;    // zf
	int result; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (!v0) {
		return 1;
	}
	v1 = atoi(v0);
	nox_gui_console_translucent_set(v1);
	v2 = v1 == 0;
	result = 1;
	if (!v2) {
		nox_gui_console_translucent_set(1);
	}
	return result;
}

//----- (00432390) --------------------------------------------------------
int sub_432390() {
	char* v0;   // eax
	int v1;     // eax
	bool v2;    // zf
	int result; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (!v0) {
		return 1;
	}
	v1 = atoi(v0);
	nox_client_renderGlow_805852 = v1;
	v2 = v1 == 0;
	result = 1;
	if (!v2) {
		nox_client_renderGlow_805852 = 1;
	}
	return result;
}

//----- (004323E0) --------------------------------------------------------
int sub_4323E0() {
	char* v0;   // eax
	int v1;     // eax
	bool v2;    // zf
	int result; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (!v0) {
		return 1;
	}
	v1 = atoi(v0);
	nox_client_renderGUI_80828 = v1;
	v2 = v1 == 0;
	result = 1;
	if (!v2) {
		nox_client_renderGUI_80828 = 1;
	}
	return result;
}

//----- (00432430) --------------------------------------------------------
int sub_432430() {
	char* v0;   // eax
	int v1;     // eax
	bool v2;    // zf
	int result; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (!v0) {
		return 1;
	}
	v1 = atoi(v0);
	nox_client_fadeObjects_80836 = v1;
	v2 = v1 == 0;
	result = 1;
	if (!v2) {
		nox_client_fadeObjects_80836 = 1;
	}
	return result;
}

//----- (00432480) --------------------------------------------------------
int sub_432480() {
	char* v0;   // eax
	int v1;     // eax
	bool v2;    // zf
	int result; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (!v0) {
		return 1;
	}
	v1 = atoi(v0);
	nox_client_renderBubbles_80844 = v1;
	v2 = v1 == 0;
	result = 1;
	if (!v2) {
		nox_client_renderBubbles_80844 = 1;
	}
	return result;
}

//----- (004324D0) --------------------------------------------------------
int sub_4324D0() {
	char* v0;        // eax
	wchar_t v2[100]; // [esp+0h] [ebp-C8h]

	strtok(0, " \r\t\n");
	v0 = strtok(0, "\r\t\n");
	if (v0) {
		nox_swprintf(v2, L"%S", v0);
		nox_xxx_sysopSetPass_40A610(v2);
	}
	return 1;
}

//----- (00432520) --------------------------------------------------------
int sub_432520() {
	char* v0;        // esi
	char* v1;        // eax
	wchar_t v3[100]; // [esp+4h] [ebp-C8h]

	v0 = sub_416640();
	strtok(0, " \r\t\n");
	v1 = strtok(0, "\r\t\n");
	if (v1) {
		nox_swprintf(v3, L"%S", v1);
		nox_wcsncpy((wchar_t*)v0 + 39, v3, 8u);
		*((uint16_t*)v0 + 47) = 0;
	}
	return 1;
}

//----- (00432590) --------------------------------------------------------
int sub_432590() {
	char* v0; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0) {
		nox_profiled_805856 = atoi(v0) != 0;
	}
	return 1;
}

//----- (004325D0) --------------------------------------------------------
int sub_4325D0() {
	char* v0; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0) {
		*getMemU32Ptr(0x587000, 81280) = atoi(v0);
		*getMemU32Ptr(0x587000, 292940) = (long long)((double)*getMemIntPtr(0x587000, 81280) * 0.0099999998 * 10.0);
	}
	return 1;
}

//----- (00432620) --------------------------------------------------------
int sub_432620() {
	char* v0; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0) {
		nox_server_sanctuaryHelp_54276 = atoi(v0) != 0;
	}
	return 1;
}

//----- (00432660) --------------------------------------------------------
int sub_432660() {
	char* v0; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0) {
		if (atoi(v0)) {
			sub_409E70(2);
			return 1;
		}
		sub_409EC0(2);
	}
	return 1;
}

//----- (004326B0) --------------------------------------------------------
int sub_4326B0() {
	char* v0; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0) {
		if (atoi(v0)) {
			sub_409E70(0x2000);
			return 1;
		}
		sub_409EC0(0x2000);
	}
	return 1;
}

//----- (00432700) --------------------------------------------------------
int sub_432700() {
	char* v0; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0) {
		*getMemU32Ptr(0x587000, 229980) = atoi(v0);
	}
	return 1;
}

//----- (00432740) --------------------------------------------------------
int sub_432740() {
	char* v0; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0) {
		nox_server_resetQuestMinVotes_229988 = atoi(v0);
	}
	return 1;
}

//----- (00432780) --------------------------------------------------------
int sub_432780() {
	char* v0; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0) {
		nox_server_kickQuestPlayerMinVotes_229992 = atoi(v0);
	}
	return 1;
}

//----- (004327C0) --------------------------------------------------------
int sub_4327C0() {
	char* v0; // esi
	char* v1; // edi

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0) {
		v1 = sub_416640();
		*(uint32_t*)(v1 + 58) = atoi(v0) > 0;
	}
	return 1;
}

//----- (00432810) --------------------------------------------------------
int sub_432810() {
	char* v0; // esi
	char* v1; // edi

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0) {
		v1 = sub_416640();
		*(uint32_t*)(v1 + 62) = atoi(v0) > 0;
	}
	return 1;
}

//----- (00432860) --------------------------------------------------------
int sub_432860() {
	char* v0; // edi
	char* v1; // esi
	bool v2;  // cc
	char v3;  // al

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0) {
		v1 = sub_416640();
		v2 = atoi(v0) <= 0;
		v3 = v1[100];
		if (!v2) {
			v1[100] = v3 | 0x10;
			return 1;
		}
		v1[100] = v3 & 0xEF;
	}
	return 1;
}

//----- (004328C0) --------------------------------------------------------
int sub_4328C0() {
	char* v0; // edi
	char* v1; // esi
	bool v2;  // cc
	char v3;  // al

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0) {
		v1 = sub_416640();
		v2 = atoi(v0) <= 0;
		v3 = v1[100];
		if (!v2) {
			v1[100] = v3 | 0x20;
			return 1;
		}
		v1[100] = v3 & 0xDF;
	}
	return 1;
}

//----- (00432920) --------------------------------------------------------
int sub_432920() {
	char* v0; // edi
	char* v1; // esi

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0) {
		v1 = sub_416640();
		v1[100] |= atoi(v0) & 7;
	}
	return 1;
}

//----- (00432970) --------------------------------------------------------
int sub_432970() {
	char* v0; // edi
	char* v1; // esi
	char* v2; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0) {
		v1 = sub_416640();
		*(uint32_t*)(v1 + 66) = atoi(v0);
		v2 = strtok(0, " \r\t\n");
		if (v2) {
			*(uint32_t*)(v1 + 70) = atoi(v2);
		}
	}
	return 1;
}

//----- (004329D0) --------------------------------------------------------
int sub_4329D0() {
	char* v0; // edi
	char* v1; // esi
	char* v2; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0) {
		v1 = sub_416640();
		*(uint16_t*)(v1 + 105) = atoi(v0);
		v2 = strtok(0, " \r\t\n");
		if (v2) {
			*(uint16_t*)(v1 + 107) = atoi(v2);
		}
	}
	return 1;
}

//----- (00432A30) --------------------------------------------------------
int sub_432A30() {
	char* v0; // edi
	char* v1; // esi
	bool v2;  // cc
	char v3;  // al

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0) {
		v1 = sub_416640();
		v2 = atoi(v0) <= 0;
		v3 = v1[102];
		if (!v2) {
			v1[102] = v3 | 0x80;
			return 1;
		}
		v1[102] = v3 & 0x7F;
	}
	return 1;
}

//----- (00432A90) --------------------------------------------------------
int sub_432A90() {
	char* v0; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0) {
		nox_server_sendMotd_108752 = atoi(v0) != 0;
	}
	return 1;
}

//----- (00432AD0) --------------------------------------------------------
int sub_432AD0(int* a1) {
	char* v1; // eax

	strtok(0, " \r\t\n");
	v1 = strtok(0, " \r\t\n");
	*a1 = atoi(v1);
	return 1;
}

//----- (00432B00) --------------------------------------------------------
void nox_common_parsecfg_videomode_apply(int w, int h, int d);
int nox_common_parsecfg_videomode() {
	char* v0; // eax
	char* v2; // eax
	char* v4; // eax
	int v5;   // eax
	int v6;   // esi

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	int w = atoi(v0);
	v2 = strtok(0, " \r\t\n");
	int h = atoi(v2);
	v4 = strtok(0, " \r\t\n");
	v5 = atoi(v4);
	v6 = v5;
	v6 = 16;
	nox_common_parsecfg_videomode_apply(w, h, v6);
	return 1;
}

//----- (00432BD0) --------------------------------------------------------
int nox_common_parsecfg_videosize() {
	char* v0; // eax
	int v1;   // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	v1 = atoi(v0);
	nox_video_setCutSize_4766A0(v1);
	return 1;
}

//----- (00432C00) --------------------------------------------------------
int sub_432C00() {
	char* v0; // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	*getMemU32Ptr(0x587000, 80852) = atoi(v0);
	return 1;
}

//----- (00432C30) --------------------------------------------------------
int sub_432C30() {
	char* v0; // eax
	int v1;   // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0) {
		v1 = atoi(v0);
		sub_4D0D90(v1 != 0);
	}
	return 1;
}

//----- (00432C70) --------------------------------------------------------
int sub_432C70(int a1) {
	char* v1; // eax
	int v2;   // eax

	strtok(0, " \r\t\n");
	v1 = strtok(0, " \r\t\n");
	if (v1) {
		v2 = atoi(v1);
		sub_4D0DC0(a1, v2);
	}
	return 1;
}

//----- (00432CB0) --------------------------------------------------------
int sub_432CB0(int a1) {
	char* v1;        // eax
	unsigned int v2; // eax
	int result;      // eax

	strtok(0, " \r\t\n");
	v1 = strtok(0, " \r\t\n");
	v2 = atoi(v1);
	if ((v2 & 0x80000000) == 0) {
		if (v2 > 0x4000) {
			v2 = 0x4000;
		}
		sub_486670(v2, a1);
		result = 1;
	} else {
		sub_486670(0, a1);
		result = 1;
	}
	return result;
}

//----- (00432D10) --------------------------------------------------------
int sub_432D10() {
	char* v0;          // eax
	char* v1;          // eax
	unsigned char* v2; // esi
	unsigned short v3; // ax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (!v0) {
		return 1;
	}
	v1 = strtok(v0, ",\r\n");
	if (!v1) {
		return 1;
	}
	v2 = getMemAt(0x587000, 81224);
	do {
		v3 = atoi(v1);
		sub_409FB0_settings(*(uint32_t*)v2, v3);
		v2 += 4;
		v1 = strtok(0, ",\r\n");
	} while (v1);
	return 1;
}

//----- (00432D80) --------------------------------------------------------
int sub_432D80() {
	char* v0;          // eax
	char* v1;          // eax
	unsigned char* v2; // esi
	unsigned char v3;  // al

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (!v0) {
		return 1;
	}
	v1 = strtok(v0, ",\r\n");
	if (!v1) {
		return 1;
	}
	v2 = getMemAt(0x587000, 81224);
	do {
		v3 = atoi(v1);
		sub_40A040_settings(*(uint32_t*)v2, v3);
		v2 += 4;
		v1 = strtok(0, ",\r\n");
	} while (v1);
	return 1;
}

//----- (00432DF0) --------------------------------------------------------
int sub_432DF0() {
	char* v0; // eax
	int v1;   // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0) {
		v1 = atoi(v0);
		nox_xxx_rateUpdate_40A6D0(v1);
		if (nox_xxx_rateGet_40A6C0() <= 0 || nox_xxx_rateGet_40A6C0() > 3) {
			nox_xxx_rateUpdate_40A6D0(1);
		}
	}
	return 1;
}

//----- (00432E50) --------------------------------------------------------
char* sub_432E50(int a1) {
	char* v1;     // eax
	char* result; // eax
	int v3;       // esi
	char* v4;     // eax
	int v5[11];   // [esp+4h] [ebp-2Ch]

	strtok(0, " \r\t\n");
	v1 = strtok(0, " \r\t\n");
	if (!v1) {
		return (char*)1;
	}
	result = strtok(v1, ",\r\n");
	if (result) {
		v3 = atoi(result);
		result = strtok(0, ",\r\n");
		if (result) {
			v5[0] = atoi(result);
			result = strtok(0, ",\r\n");
			if (result) {
				v5[1] = *result == 49;
				result = strtok(0, ",\r\n");
				if (result) {
					v5[2] = *result == 49;
					result = strtok(0, ",\r\n");
					if (result) {
						v5[3] = atoi(result);
						result = strtok(0, ",\r\n");
						if (result) {
							v5[4] = atoi(result);
							result = strtok(0, ",\r\n");
							if (result) {
								v5[5] = *result == 49;
								result = strtok(0, ",\r\n");
								if (result) {
									v5[6] = *result == 49;
									result = strtok(0, ",\r\n");
									if (result) {
										v5[7] = *result == 49;
										result = strtok(0, ",\r\n");
										if (result) {
											v5[8] = *result == 49;
											result = strtok(0, ",\r\n");
											if (result) {
												v5[9] = *result == 49;
												v4 = strtok(0, ",\r\n");
												if (v4) {
													v5[10] = *v4 == 49;
												} else {
													v5[10] = 0;
												}
												sub_489FF0(a1, v3, v5);
												return (char*)1;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return result;
}

//----- (00433050) --------------------------------------------------------
int sub_433050() {
	char* v0;         // eax
	int v1;           // eax
	unsigned char* i; // ecx
	int v3;           // edx

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0) {
		v1 = atoi(v0);
		if (*getMemU32Ptr(0x587000, 81248)) {
			for (i = getMemAt(0x587000, 81248); *((uint32_t*)i + 1) != v1; i += 8) {
				v3 = *((uint32_t*)i + 2);
				if (!v3) {
					return 1;
				}
			}
			if (v1 < 0 && v1 > 4) {
				v1 = 4;
			}
			nox_server_connectionType_3596 = v1;
		}
	}
	return 1;
}

//----- (004330C0) --------------------------------------------------------
int sub_4330C0() {
	char* v0; // edi
	char* v1; // esi
	char v2;  // al

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (!v0) {
		return 1;
	}
	v1 = sub_416640();
	v2 = atoi(v0);
	v1[104] = v2;
	if ((unsigned char)v2 <= 0x20u) {
		if ((unsigned char)v2 < 1u) {
			v1[104] = 1;
		}
	} else {
		v1[104] = 32;
	}
	nox_xxx_servSetPlrLimit_409F80((unsigned char)v1[104]);
	return 1;
}

//----- (00433130) --------------------------------------------------------
int sub_433130() {
	char* v0; // edi
	char* v1; // esi
	int v2;   // eax

	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0) {
		v1 = sub_416640();
		v2 = atoi(v0);
		*(uint32_t*)(v1 + 74) = v2;
		if (v2 > 100) {
			*(uint32_t*)(v1 + 74) = 100;
			return 1;
		}
		if (v2 < 0) {
			*(uint32_t*)(v1 + 74) = 0;
		}
	}
	return 1;
}

//----- (00433190) --------------------------------------------------------
int sub_433190() {
	char* v0; // eax
	char v2;  // [esp+0h] [ebp-4h]

	v2 = 0;
	strtok(0, " \r\t\n");
	v0 = strtok(0, " \r\t\n");
	if (v0) {
		v2 = atoi(v0);
	}
	sub_578DE0(v2);
	return 1;
}

//----- (004331E0) --------------------------------------------------------
int nox_common_skipcfgfile_4331E0(FILE* a1, int a2) {
	int v2;     // edi
	int result; // eax

	v2 = 0;
	if (a2) {
		while (nox_fs_fgets(a1, (char*)getMemAt(0x5D4594, 806084), 1024)) {
			if (!strncmp("---", (const char*)getMemAt(0x5D4594, 806084), 3u)) {
				goto LABEL_6;
			}
		}
		result = 1;
	} else {
	LABEL_6:
		do {
			do {
				if (!nox_fs_fgets(a1, (char*)getMemAt(0x5D4594, 806084), 1024)) {
					return v2;
				}
			} while (getMemByte(0x5D4594, 806084) == 35);
			if (!strncmp("---", (const char*)getMemAt(0x5D4594, 806084), 3u)) {
				return 1;
			}
		} while (nox_client_parseConfigHotkeysLine_42CF50((const char*)getMemAt(0x5D4594, 806084)));
		result = 0;
	}
	return result;
}

//----- (00433290) --------------------------------------------------------
void nox_common_writecfgfile(char* a1) {
	FILE* f = nox_fs_create_text(a1);
	if (!f) {
		return;
	}
	sub_4332E0(f);
	nox_client_writeConfigHotkeys_42CDF0(f);
	nox_fs_fprintf(f, "---\n");
	nox_fs_close(f);
}

//----- (004332E0) --------------------------------------------------------
int sub_4332E0(FILE* a1) {
	char* v1;           // edi
	int v2;             // eax
	int v3;             // eax
	int v4;             // eax
	int v5;             // eax
	char* v6;           // eax
	unsigned char v7;   // al
	wchar_t* v8;        // eax
	int v9;             // eax
	int v10;            // eax
	unsigned int v11;   // eax
	unsigned int v12;   // ecx
	int v13;            // eax
	unsigned int v14;   // eax
	int v15;            // eax
	int v16;            // eax
	int v17;            // eax
	unsigned char* v18; // ebx
	unsigned char* v19; // edi
	int v20;            // eax
	int v21;            // eax
	uint32_t* v23;      // [esp+8h] [ebp-4h]

	v1 = sub_416640();
	nox_fs_fprintf(a1, "Version = %d\n", 65540);
	nox_fs_fprintf(a1, "VideoMode = %d %d %d\n", nox_win_width_game, nox_win_height_game, nox_win_depth_game);
	nox_fs_fprintf(a1, "Stretched = %d\n", g_scaled_cfg);
	nox_fs_fprintf(a1, "Fullscreen = %d\n", g_fullscreen_cfg);
	v2 = nox_video_getCutSize_4766D0();
	nox_fs_fprintf(a1, "VideoSize = %d\n", v2);
	// nox_fs_fprintf(a1, "Gamma = %d\n", *(uint32_t *)getMemAt(0x587000, 80852));
	nox_fs_fprintf(a1, "Gamma2 = %f\n", nox_video_getGamma());
	nox_fs_fprintf(a1, "InputSensitivity = %f\n", nox_input_getSensitivity());
	if (sub_453070() == 1) {
		v3 = *(uint32_t*)((uint32_t)dword_587000_127004 + 4) >> 16;
	} else {
		v3 = 0;
	}
	nox_fs_fprintf(a1, "FXVolume = %d\n", v3);
	if (sub_44D990() == 1) {
		v4 = *(uint32_t*)((uint32_t)dword_587000_122852 + 4) >> 16;
	} else {
		v4 = 0;
	}
	nox_fs_fprintf(a1, "DialogVolume = %d\n", v4);
	if (sub_43DC30() == 1) {
		v5 = *(uint32_t*)((uint32_t)dword_587000_93164 + 4) >> 16;
	} else {
		v5 = 0;
	}
	nox_fs_fprintf(a1, "MusicVolume = %d\n", v5);
	nox_fs_fprintf(a1, "LastServer = %s\n", getMemAt(0x5D4594, 806060));
	v6 = sub_433890();
	nox_fs_fprintf(a1, "ServerName = %s\n", v6);
	nox_fs_fprintf(a1, "UnlockSurface = %d\n", nox_video_dxUnlockSurface);
	nox_fs_fprintf(a1, "SoftShadowEdge = %d\n",
				   nox_common_getEngineFlag(NOX_ENGINE_FLAG_ENABLE_SOFT_SHADOW_EDGE) ? 1 : 0);
	nox_fs_fprintf(a1, "DrawFrontWalls = %d\n", nox_client_drawFrontWalls_80812);
	nox_fs_fprintf(a1, "TranslucentFrontWalls = %d\n", nox_client_translucentFrontWalls_805844);
	nox_fs_fprintf(a1, "HighResFrontWalls = %d\n", nox_client_highResFrontWalls_80820);
	nox_fs_fprintf(a1, "HighResFloors = %d\n", nox_client_highResFloors_154952);
	nox_fs_fprintf(a1, "LockHighResFloors = %d\n", nox_client_lockHighResFloors_1193152);
	nox_fs_fprintf(a1, "TexturedFloors = %d\n", nox_client_texturedFloors_154956);
	nox_fs_fprintf(a1, "TranslucentConsole = %d\n", nox_gui_console_translucent_get());
	nox_fs_fprintf(a1, "RenderGlow = %d\n", nox_client_renderGlow_805852);
	nox_fs_fprintf(a1, "RenderGUI = %d\n", nox_client_renderGUI_80828);
	nox_fs_fprintf(a1, "FadeObjects = %d\n", nox_client_fadeObjects_80836);
	nox_fs_fprintf(a1, "RenderBubbles = %d\n", nox_client_renderBubbles_80844);
	v7 = sub_578DF0();
	nox_fs_fprintf(a1, "TrackData = %d\n", v7);
	v8 = nox_xxx_sysopGetPass_40A630();
	nox_fs_fprintf(a1, "SysopPassword = %S\n", v8);
	nox_fs_fprintf(a1, "ServerPassword = %S\n", v1 + 78);
	nox_fs_fprintf(a1, "Profiled = %d\n", nox_profiled_805856 != 0);
	nox_fs_fprintf(a1, "SanctuaryHelp = %d\n", nox_server_sanctuaryHelp_54276);
	nox_fs_fprintf(a1, "MaxPacketLossPct = %d\n", *getMemU32Ptr(0x587000, 81280));
	nox_fs_fprintf(a1, "SendMessageOfTheDay = %d\n", nox_server_sendMotd_108752);
	v9 = sub_4D0D70();
	nox_fs_fprintf(a1, "MapCycle = %d\n", v9);
	nox_fs_fprintf(a1, "ConnectionType = %d\n", nox_server_connectionType_3596);
	v10 = nox_xxx_rateGet_40A6C0();
	nox_fs_fprintf(a1, "InternetUpdateRate = %d\n", v10);
	nox_fs_fprintf(a1, "LessonLimit =");
	sub_4337B0(a1);
	nox_fs_fprintf(a1, "TimeLimit =");
	sub_433820(a1);
	nox_fs_fprintf(a1, "PlayerSkeletons = %d\n", *(uint32_t*)(v1 + 58));
	nox_fs_fprintf(a1, "BroadcastGestures = %d\n", *(uint32_t*)(v1 + 62));
	v11 = nox_fs_fprintf(a1, "LatencyCompensation = %d %d\n", *(uint32_t*)(v1 + 66), *(uint32_t*)(v1 + 70));
	LOBYTE(v11) = v1[100];
	nox_fs_fprintf(a1, "Closed = %d\n", (v11 >> 4) & 1);
	LOBYTE(v12) = v1[100];
	nox_fs_fprintf(a1, "Private = %d\n", (v12 >> 5) & 1);
	nox_fs_fprintf(a1, "AudioThreshold = %d\n", *(uint32_t*)(v1 + 74));
	v13 = nox_xxx_servGetPlrLimit_409FA0();
	nox_fs_fprintf(a1, "MaxPlayers = %d\n", v13);
	nox_fs_fprintf(a1, "RestrictedClasses = %d\n", v1[100] & 7);
	nox_fs_fprintf(a1, "RestrictedPing = %d %d\n", *(unsigned short*)(v1 + 105), *(unsigned short*)(v1 + 107));
	nox_fs_fprintf(a1, "LimitMaxRes = %d\n", (unsigned char)v1[102] >> 7);
	v14 = nox_xxx_getServerSubFlags_409E60();
	nox_fs_fprintf(a1, "CamperAlarm = %d\n", (v14 >> 13) & 1);
	v15 = sub_409F40(2);
	nox_fs_fprintf(a1, "ItemRespawn = %d\n", v15);
	nox_fs_fprintf(a1, "MinKickVotes = %d\n", *getMemU32Ptr(0x587000, 229980));
	nox_fs_fprintf(a1, "ResetQuestMinVotes = %d\n", nox_server_resetQuestMinVotes_229988);
	nox_fs_fprintf(a1, "KickQuestPlayerMinVotes = %d\n", nox_server_kickQuestPlayerMinVotes_229992);
	v16 = sub_48A020(0, &v23);
	nox_fs_fprintf(a1, "LANFilters = %d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n", v16, *v23, v23[1], v23[2], v23[3], v23[4],
				   v23[5], v23[6], v23[7], v23[8], v23[9], v23[10]);
	v17 = sub_48A020(1, &v23);
	nox_fs_fprintf(a1, "INETFilters = %d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n", v17, *v23, v23[1], v23[2], v23[3], v23[4],
				   v23[5], v23[6], v23[7], v23[8], v23[9], v23[10]);
	if (*getMemU32Ptr(0x587000, 81168)) {
		v18 = getMemAt(0x587000, 81168);
		v19 = getMemAt(0x587000, 81168);
		do {
			v20 = sub_4D0DE0(*((uint32_t*)v19 + 1));
			nox_fs_fprintf(a1, "%s = %d\n", *(uint32_t*)v18, v20);
			v21 = *((uint32_t*)v19 + 2);
			v19 += 8;
			v18 = v19;
		} while (v21);
	}
	return nox_fs_fprintf(a1, "---\n");
}

//----- (004337B0) --------------------------------------------------------
int sub_4337B0(FILE* a1) {
	unsigned short v1; // ax
	int v2;            // eax
	unsigned char* v3; // esi
	unsigned short v4; // ax

	v1 = nox_xxx_servGamedataGet_40A020(*getMemI16Ptr(0x587000, 81224));
	nox_fs_fprintf(a1, " %d", v1);
	LOWORD(v2) = *getMemU16Ptr(0x587000, 81228);
	if (*getMemU32Ptr(0x587000, 81228)) {
		v3 = getMemAt(0x587000, 81228);
		do {
			v4 = nox_xxx_servGamedataGet_40A020(v2);
			nox_fs_fprintf(a1, ",%d", v4);
			v2 = *((uint32_t*)v3 + 1);
			v3 += 4;
		} while (v2);
	}
	return nox_fs_fprintf(a1, "\n");
}

//----- (00433820) --------------------------------------------------------
int sub_433820(FILE* a1) {
	unsigned char v1;  // al
	int v2;            // eax
	unsigned char* v3; // esi
	unsigned char v4;  // al

	v1 = sub_40A180(*getMemI16Ptr(0x587000, 81224));
	nox_fs_fprintf(a1, " %d", v1);
	LOWORD(v2) = *getMemU16Ptr(0x587000, 81228);
	if (*getMemU32Ptr(0x587000, 81228)) {
		v3 = getMemAt(0x587000, 81228);
		do {
			v4 = sub_40A180(v2);
			nox_fs_fprintf(a1, ",%d", v4);
			v2 = *((uint32_t*)v3 + 1);
			v3 += 4;
		} while (v2);
	}
	return nox_fs_fprintf(a1, "\n");
}

//----- (00433890) --------------------------------------------------------
char* sub_433890() {
	char* v0;          // eax
	unsigned char* v1; // eax
	char v2;           // cl

	v0 = nox_xxx_serverOptionsGetServername_40A4C0();
	strncpy((char*)getMemAt(0x5D4594, 807108), v0, 0x3Fu);
	v1 = getMemAt(0x5D4594, 807108);
	if (getMemByte(0x5D4594, 807108)) {
		do {
			if (*v1 == 32) {
				*v1 = 95;
			}
			v2 = *++v1;
		} while (v2);
	}
	return (char*)getMemAt(0x5D4594, 807108);
}
