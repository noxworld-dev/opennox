#include "gameloop.h"

#include "../../common/random.h"
#include "../../common/system/gamedisk.h"
#include "../../proto.h"
#include "../gui/guimsg.h"
#include "../io/console.h"

#ifdef NOX_E2E_TEST
#include "../../platform.h"
#endif

extern _DWORD dword_5d4594_1556112;
extern _DWORD nox_game_continueMenuOrHost_93200;
extern _DWORD nox_game_loop_xxx_805872;
extern _DWORD nox_continue_mainloop_93196;
extern _DWORD nox_xxx_gameDownloadInProgress_587000_173328;
extern _DWORD nox_xxx_mapDownloadOK_587000_173332;
extern _DWORD dword_5d4594_2618912;
extern _DWORD nox_gameDisableMapDraw_5d4594_2650672;
extern _DWORD dword_5d4594_815132;
extern int nox_win_width;
extern int nox_win_height;
extern unsigned int nox_gameFPS;

#ifdef USE_SDL
extern SDL_GLContext g_ddraw;
#endif

void cmain_loop(int);
extern int g_v20, g_v21;

extern void (*mainloop_enter)(void*);
extern void* mainloop_enter_args;
extern BOOL mainloop_exit_path;

extern int (*nox_draw_unk1)(void);
extern int (*func_5D4594_816388)(void);
extern int (*func_5D4594_816392)(void);

void map_download_start() {
	nox_xxx_gameClearAll_467DF0(1);
	nox_xxx_gameDownloadShowDialog_4CC770();
	nox_xxx_gameDownloadInProgress_587000_173328 = 1;
	nox_xxx_mapDownloadOK_587000_173332 = 1;
	map_download_loop(1);
}

//----- (0043DEB0) --------------------------------------------------------
int nox_xxx_gameChangeMap_43DEB0() {
	char* v0;         // eax
	char* v1;         // esi
	int v2;           // eax
	char v3;          // al
	char v4;          // bl
	char* v5;         // esi
	wchar_t* v6;      // eax
	wchar_t* v7;      // eax
	wchar_t* v8;      // eax
	wchar_t* v10;     // eax
	wchar_t* v12;     // [esp-10h] [ebp-118h]
	char* v13;        // [esp-4h] [ebp-10Ch]
	char* v14;        // [esp-4h] [ebp-10Ch]
	wchar_t v15[128]; // [esp+8h] [ebp-100h]

	if (!nox_common_gameFlags_check_40A5C0(0x800000))
		goto LABEL_16;
	nox_client_setCursorType_477610(10);
	if (nox_xxx_gameIsNotMultiplayer_4DB250())
		v0 = nox_xxx_mapFilenameGetSolo_4DB260();
	else
		v0 = nox_server_currentMapGetFilename_409B30();
	v1 = v0;
	v2 = nox_xxx_mapCrcGetMB_409B00();
	v3 = nox_xxx_mapValidateMB_4CF470(v1, v2);
	v4 = v3;
	if (v3 & 2 && v3 & 4) {
		sub_43F140(500);
		v5 = nox_xxx_mapCliReadAll_4AC2B0(v1);
		sub_43F1A0();
		if (!v5) {
			v13 = nox_server_currentMapGetFilename_409B30();
			v6 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 93352), 0, "C:\\NoxPost\\src\\Client\\System\\gameloop.c",
									   318);
			sub_4516C0(v6, v13);
			nox_xxx_spriteLoadError_4356E0();
			return 0;
		}
		if (nox_common_gameFlags_check_40A5C0(1))
			nox_xxx_gameServerReadyMB_4DD180(31);
		else
			nox_xxx_netSendClientReady_43C9F0();
		nox_xxx_gameSetCliConnected_43C720(1);
		if ((int)*getMemU32Ptr(0x5D4594, 3801836 + 1392) < 0) {
			v7 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 93408), 0, "C:\\NoxPost\\src\\Client\\System\\gameloop.c",
									   338);
			nox_xxx_printCentered_445490(v7);
			v14 = sub_42E8E0(8, 1);
			v8 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 93468), 0, "C:\\NoxPost\\src\\Client\\System\\gameloop.c",
									   339);
			nox_swprintf(v15, v8, v14);
			nox_xxx_printCentered_445490(v15);
		}
	} else {
		if (!nox_common_gameFlags_check_40A5C0(1)) {
			if (!(v4 & 1) || v4 & 4) {
				nox_xxx_setGameFlags_40A4D0(0x100000);
			} else {
				nox_common_gameFlags_unset_40A540(9437184);
				sub_477530(1);
				nox_xxx_gui_43E1A0(1);
				v12 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 93244), 0,
											"C:\\NoxPost\\src\\Client\\System\\gameloop.c", 298);
				v10 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 93304), 0,
											"C:\\NoxPost\\src\\Client\\System\\gameloop.c", 297);
				nox_xxx_dialogMsgBoxCreate_449A10(0, (int)v10, (int)v12, 24, sub_43E230, sub_43E200);
			}
			goto LABEL_16;
		}
		nox_xxx_gameServerReadyMB_4DD180(31);
	}
	if (!nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
		nox_gameDisableMapDraw_5d4594_2650672 = 1;
		sub_44DA60(1);
	}
LABEL_16:
	if (nox_common_gameFlags_check_40A5C0(0x100000)) {
		map_download_start();
		return 0;
	}
	if (nox_common_gameFlags_check_40A5C0(9437184))
		nox_common_gameFlags_unset_40A540(9437184);
	return 1;
}

int map_download_finish() {
	int result;  // eax
	wchar_t* v6; // eax
	char* v13;   // [esp-4h] [ebp-10Ch]

	nox_xxx_guiDownloadClose_4CC930();
	result = nox_xxx_mapDownloadOK_587000_173332;
	if (nox_xxx_mapDownloadOK_587000_173332) {
		int v3; // [esp+4h] [ebp-Ch]
		int v4; // [esp+8h] [ebp-8h]
		int v5; // [esp+Ch] [ebp-4h]
		nox_xxx_gameGetScreenBoundaries_43BEB0_get_video_mode(&v3, &v5, &v4);
		if (!v3)
			nox_xxx_gameResizeScreen_43BEF0_set_video_mode(NOX_DEFAULT_WIDTH, NOX_DEFAULT_HEIGHT, v4);
		result = nox_xxx_mapDownloadOK_587000_173332;
	}

	if (!result) {
		nox_common_gameFlags_unset_40A540(9437184);
		return 0;
	}
	nox_xxx_gui_43E1A0(0);
	if (!nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
		nox_gameDisableMapDraw_5d4594_2650672 = 1;
		sub_44DA60(1);
	}
	if (!nox_xxx_mapCliReadAll_4AC2B0(nox_server_currentMapGetFilename_409B30())) {
		v13 = nox_server_currentMapGetFilename_409B30();
		v6 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 93528), 0, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 386);
		sub_4516C0(v6, v13);
		nox_xxx_spriteLoadError_4356E0();
		return 0;
	}
	if (nox_common_gameFlags_check_40A5C0(1))
		nox_xxx_gameServerReadyMB_4DD180(31);
	else
		nox_xxx_netSendClientReady_43C9F0();
	nox_xxx_gameSetCliConnected_43C720(1);

	if (nox_common_gameFlags_check_40A5C0(9437184))
		nox_common_gameFlags_unset_40A540(9437184);
	return 1;
}

//----- (0043E290) --------------------------------------------------------
#ifdef USE_SDL
void __cdecl sub_48B1B0(SDL_GLContext* a1);
#endif

void cleanup() {
	printf("%s\n", __FUNCTION__);
	if (nox_common_gameFlags_check_40A5C0(0x2000000))
		sub_413D00();
	nox_common_writecfgfile("nox.cfg");
	sub_4314D0();
	sub_413960();
	sub_431380();
	sub_4134F0();
	nox_xxx_freeWeaponArmorDefAndModifs_413060();
	sub_4311B0();
	sub_430EF0();
	sub_430210();
	nox_xxx_tileFree_410FC0_free();
	sub_4106C0();
	sub_42F4D0();
	sub_42EDC0();
	sub_42CD90();
	sub_410020();
	nox_xxx_net_40EA70();
	sub_40D0F0();
	sub_40E070();
	sub_4D11D0();
	sub_4D0DA0();
	sub_40C0D0();
	sub_40B740();
	sub_4D0970();
	sub_4093D0();
	sub_40AF30();
#ifdef USE_SDL
	sub_48B1B0(&g_ddraw);
#endif
	nox_free_thing_bin();
}

void mainloop() {
#ifdef NOX_E2E_TEST
	nox_platform_time_hook();
#endif

#ifdef __EMSCRIPTEN__
	DWORD cur_tick;
	static DWORD last_tick;

	// rate limit to < 40 fps
	cur_tick = nox_platform_get_ticks();
	if (cur_tick - last_tick < 1000 / 40) {
		return;
	}
	last_tick = cur_tick;
#endif // __EMSCRIPTEN__

	if (mainloop_enter) {
		mainloop_enter(mainloop_enter_args);
		return;
	}
	unsigned __int8* v0; // eax
	int v6;              // eax
	int v7;              // esi
	int v9;              // edi
	int v10;             // eax
	int v12;             // esi
	int v13;             // eax
	int v14;             // kr00_4
	int v15;             // esi
	char v16;            // al
	int v21;             // [esp-10h] [ebp-68h]
	char v22;            // [esp-8h] [ebp-60h]
	char v23;            // [esp-4h] [ebp-5Ch]
	char v24;            // [esp-4h] [ebp-5Ch]
	int* v25;            // [esp+4h] [ebp-54h]
	int v28[10];         // [esp+24h] [ebp-34h]

	if (nox_xxx_gameDownloadInProgress_587000_173328) {
		int ret = map_download_loop(0);
		if (ret == -1) {
			return;
		} else if (ret == 0) {
			// map error
			nox_continue_mainloop_93196 = 0;
			nox_game_continueMenuOrHost_93200 = 0;
			goto MAINLOOP_EXIT;
		}
	} else {
		_control87(0x300u, 0x300u);
		if (!nox_xxx_gameChangeMap_43DEB0()) {
			// XXX
			if (nox_xxx_gameDownloadInProgress_587000_173328) {
				return;
			}
			nox_continue_mainloop_93196 = 0;
			nox_game_continueMenuOrHost_93200 = 0;
			goto MAINLOOP_EXIT;
		}
	}
	if (sub_43AF70() == 1) {
		sub_40D250();
		sub_40DF90();
	}
	nox_framerate_limit_416C70(30);
	nox_xxx_processWinMessages_4453A0_poll_events();
	sub_413520_gamedisk();
	nox_xxx_time_startProfile_435770();
	if (!func_5D4594_816388()) {
		goto MAINLOOP_EXIT;
	}
	nox_xxx_time_endProfile_435780();
	sub_435740();
	sub_430880(1);
	nox_client_processMouseInput_4308A0(1);
	nox_xxx_cursorUpdate_46B740();
	v0 = (unsigned __int8*)nox_xxx_wndKeyGet_430940();
	for (dword_5d4594_2618912 = v0; *v0; dword_5d4594_2618912 = v0) {
		nox_xxx_windowUpdateKeysMB_46B6B0(v0);
		v0 = (unsigned __int8*)(dword_5d4594_2618912 + 8);
	}
	if (!nox_draw_unk1()) {
		goto MAINLOOP_EXIT;
	}
	sub_430880(0);
	if (!func_5D4594_816392()) {
		goto MAINLOOP_EXIT;
	}
	sub_4519C0();
	sub_4312C0();
	sub_495430();
	if (nox_common_gameFlags_check_40A5C0(1) && nox_game_continueMenuOrHost_93200 == 1) {
		if (!dword_5d4594_815132) {
			if (nox_common_gameFlags_check_40A5C0(0x2000)) {
				if (nox_server_gameDoSwitchMap_40A680()) {
					nox_xxx_netGameSettings_4DEF00();
					nox_server_gameUnsetMapLoad_40A690();
				} else if (sub_459D60() && !nox_common_gameFlags_check_40A5C0(9437184)) {
					if (sub_459DA0()) {
						sub_4DF020();
					}
					sub_459D50(0);
				}
				if (*getMemIntPtr(0x5D4594, 2598000) >= *getMemIntPtr(0x5D4594, 816400)) {
					sub_4161E0();
					sub_416690();
					*getMemU32Ptr(0x5D4594, 816400) = *getMemU32Ptr(0x5D4594, 2598000) + 60 * nox_gameFPS;
				}
			}
		}
	}
	if (dword_5d4594_815132) {
		sub_43C380();
		nox_common_resetEngineFlag(NOX_ENGINE_FLAG_32);
		if (!*getMemU32Ptr(0x5D4594, 816408)) {
			nox_mouse_state_t* mouse = nox_client_getMousePos_4309F0();
			// emit sparks when passing a certain distance
			const double distance_sparks = 0.25;
			int dx = mouse->pos.x - *getMemU32Ptr(0x5D4594, 816420);
			int dy = mouse->pos.y - *getMemU32Ptr(0x5D4594, 816424);
			int r2 = dx * dx + dy * dy;
			if (*getMemU32Ptr(0x5D4594, 816428)) {
				int cnt = (int)(sqrt((double)r2) * distance_sparks);
				for (int i = cnt; i > 0; i--) {
					v6 = nox_common_randomIntMinMax_415FF0(0, 100, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 570);
					v7 = *getMemU32Ptr(0x5D4594, 816420) + dx * v6 / 100;
					v9 = *getMemU32Ptr(0x5D4594, 816424) + dy * v6 / 100;
					v23 = nox_common_randomIntMinMax_415FF0(2, 5, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 582);
					v22 = nox_common_randomIntMinMax_415FF0(2, 5, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 581);
					v21 = nox_common_randomIntMinMax_415FF0(-7, 2, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 579);
					v10 = nox_common_randomIntMinMax_415FF0(-5, 5, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 578);
					nox_client_newScreenParticle_431540(4, v7, v9, v10, v21, 1, v22, v23, 2, 1);
				}
				if (r2 < 10) {
					*getMemU32Ptr(0x5D4594, 816428) = 0;
				}
				*getMemU32Ptr(0x5D4594, 816420) = mouse->pos.x;
				*getMemU32Ptr(0x5D4594, 816424) = mouse->pos.y;
			} else if (r2 > 64) {
				*getMemU32Ptr(0x5D4594, 816428) = 1;
			}
			// explode with sparks when clicking
			const int explosion_sparks = 75;
			if (mouse->btn[NOX_MOUSE_LEFT].pressed == 1) {
				nox_common_randomIntMinMax_415FF0(0, 2, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 608);
				if (!*getMemU32Ptr(0x5D4594, 816416)) {
					*getMemU32Ptr(0x5D4594, 816416) = 1;
					nox_xxx_clientPlaySoundSpecial_452D80(924, 100);
					for (int i = explosion_sparks; i > 0; i--) {
						v12 = nox_common_randomIntMinMax_415FF0(0, 255, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 620);
						v13 = nox_common_randomIntMinMax_415FF0(6, 12, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 621);
						v14 = v13 * *getMemIntPtr(0x587000, 8 * v12 + 192088);
						v15 = v13 * *getMemIntPtr(0x587000, 8 * v12 + 192092) / 16 - 6;
						v24 = nox_common_randomIntMinMax_415FF0(2, 5, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 633);
						v16 = nox_common_randomIntMinMax_415FF0(2, 5, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 632);
						nox_client_newScreenParticle_431540(4, v14 / 16 + mouse->pos.x, mouse->pos.y + v15, v14 / 16, v15, 1, v16, v24, 2, 1);
					}
				}
			} else {
				*getMemU32Ptr(0x5D4594, 816416) = 0;
			}
		}
	}
	if (!nox_common_getEngineFlag(NOX_ENGINE_FLAG_32)) {
		sub_437180();
		if (!dword_5d4594_1556112)
			mainloop_draw(); // Draw game windows
		if (dword_5d4594_815132) {
			v28[0] = 0;
			v28[1] = 0;
			v28[2] = nox_win_width;
			v28[3] = nox_win_height;
			v28[8] = nox_win_width;
			v28[9] = nox_win_height;
			nox_client_screenParticlesDraw_431720(v28);
		} else {
			v25 = (int*)sub_437250();
			nox_client_screenParticlesDraw_431720(v25);
		}
		if (!nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) || nox_common_getEngineFlag(NOX_ENGINE_FLAG_9) || dword_5d4594_815132) {
			nox_client_drawCursorAndTooltips_477830(); // Draw cursor
		}
		sub_44D9F0(1);
		if (!sub_409F40(4096)) { // CheckRuleFlags and smth
			sub_46D830();
		}
		if (!nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) || nox_common_getEngineFlag(NOX_ENGINE_FLAG_9) || dword_5d4594_815132) {
			nox_xxx_directDrawBlitMB_48A220();
			sub_4AD170_call_copy_backbuffer();
			sub_48A290_call_present();
		}
	}
	sub_435750();
	if (!*getMemU32Ptr(0x587000, 93192)) {
		goto MAINLOOP_CHECK_STOP;
	}
	if (!nox_common_gameFlags_check_40A5C0(1) || !nox_common_gameFlags_check_40A5C0(2)) {
		goto MAINLOOP_WAIT;
	}
	if (!nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
		if (nox_common_gameFlags_check_40A5C0(0x10000000)) {
			if (!nox_common_getEngineFlag(NOX_ENGINE_FLAG_32)) {
				nox_ticks_maybe_sleep_416DD0();
			}
			goto MAINLOOP_CHECK_STOP;
		}
	}
	goto MAINLOOP_WAIT;
MAINLOOP_WAIT:
	if (!nox_common_getEngineFlag(NOX_ENGINE_FLAG_31)) {
		while (!nox_ticks_should_update_416CD0()) {}
	} else {
		int ms = nox_ticks_until_next_416D00();
		*getMemU32Ptr(0x5D4594, 816404) = ms;
		if (ms > 0) {
			nox_platform_sleep(ms);
		}
	}
MAINLOOP_CHECK_STOP:
	if (nox_game_loop_xxx_805872) {
		nox_game_continueMenuOrHost_93200 = 1;
	} else {
		if (nox_continue_mainloop_93196) {
			// unwind the stack and continue the mainloop
			return;
		}
	}
MAINLOOP_EXIT:
	if (!mainloop_exit_path) {
		if (!nox_game_continueMenuOrHost_93200) {
			cleanup();
			nox_exit(0);
		}
		// repeat
		cmain_loop(1);
		return;
	}
	nox_common_gameFlags_unset_40A540(0x10000000);
	nox_common_gameFlags_unset_40A540(55280);
	nox_common_gameFlags_unset_40A540(9437184);
	sub_43F140(300);
	sub_43D990();
	nox_xxx_replayWriteSomeInt_4D39B0();
	if (nox_common_gameFlags_check_40A5C0(1)) {
		nox_xxx_servResetPlayers_4D23C0();
	}
	if (nox_common_gameFlags_check_40A5C0(2)) {
		sub_435EB0();
	}
	if (!nox_xxx_video_43BF10_upd_video_mode(1)) {
		return;
	}
	*getMemU32Ptr(0x587000, 80852) = nox_video_getGammaSetting_434B00();
	nox_video_setGammaSetting_434B30(1);
	sub_434B60();
	g_v21 = 0;
	if (nox_common_gameFlags_check_40A5C0(1)) {
		nox_xxx_servEndSession_4D3200();
	}
	if (nox_common_gameFlags_check_40A5C0(2)) {
		nox_xxx_cliSetupSession_437190();
	}
	nox_xxx_clear18hDD_416190();
	if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_13)) {
		sub_413E30();
	}
	nullsub_2();

	// repeat
	cmain_loop(0);
	return;
}
