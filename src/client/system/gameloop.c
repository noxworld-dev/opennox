#include "gameloop.h"

#include "../../common/system/gamedisk.h"
#include "../../proto.h"
#include "../gui/guimsg.h"
#include "../io/console.h"

#ifdef NOX_E2E_TEST
#include "../../platform.h"
#endif

extern _DWORD dword_5d4594_1556112;
extern _DWORD dword_587000_93200;
extern _DWORD dword_587000_93196;
extern _DWORD dword_587000_173328;
extern _DWORD dword_587000_173332;
extern _DWORD dword_5d4594_2618912;
extern _DWORD dword_5d4594_2650672;
extern _DWORD dword_5d4594_815132;
extern int nox_win_width;
extern int nox_win_height;

extern void (*mainloop_enter)(void*);
extern void* mainloop_enter_args;
extern void (*mainloop_exit)();

extern void mainloop_stop();
extern void mainloop_wait_and_exit(int flags);

extern int (*nox_draw_unk1)(void);
extern int (*func_5D4594_816388)(void);
extern int (*func_5D4594_816392)(void);

void map_download_start() {
	sub_467DF0(1);
	sub_4CC770();
	dword_587000_173328 = 1;
	dword_587000_173332 = 1;
	map_download_loop(1);
}

//----- (0043DEB0) --------------------------------------------------------
int sub_43DEB0() {
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
	if (sub_4DB250())
		v0 = sub_4DB260();
	else
		v0 = nox_server_currentMapGetFilename_409B30();
	v1 = v0;
	v2 = sub_409B00();
	v3 = sub_4CF470(v1, v2);
	v4 = v3;
	if (v3 & 2 && v3 & 4) {
		sub_43F140(500);
		v5 = sub_4AC2B0(v1);
		sub_43F1A0();
		if (!v5) {
			v13 = nox_server_currentMapGetFilename_409B30();
			v6 = loadString_sub_40F1D0((char*)&byte_587000[93352], 0, "C:\\NoxPost\\src\\Client\\System\\gameloop.c",
									   318);
			sub_4516C0(v6, v13);
			sub_4356E0();
			return 0;
		}
		if (nox_common_gameFlags_check_40A5C0(1))
			sub_4DD180(31);
		else
			sub_43C9F0();
		sub_43C720(1);
		if ((int)*(_DWORD*)&byte_5D4594[3803228] < 0) {
			v7 = loadString_sub_40F1D0((char*)&byte_587000[93408], 0, "C:\\NoxPost\\src\\Client\\System\\gameloop.c",
									   338);
			sub_445490(v7);
			v14 = sub_42E8E0(8, 1);
			v8 = loadString_sub_40F1D0((char*)&byte_587000[93468], 0, "C:\\NoxPost\\src\\Client\\System\\gameloop.c",
									   339);
			nox_swprintf(v15, v8, v14);
			sub_445490(v15);
		}
	} else {
		if (!nox_common_gameFlags_check_40A5C0(1)) {
			if (!(v4 & 1) || v4 & 4) {
				sub_40A4D0(0x100000);
			} else {
				nox_common_gameFlags_unset_40A540(9437184);
				sub_477530(1);
				sub_43E1A0(1);
				v12 = loadString_sub_40F1D0((char*)&byte_587000[93244], 0,
											"C:\\NoxPost\\src\\Client\\System\\gameloop.c", 298);
				v10 = loadString_sub_40F1D0((char*)&byte_587000[93304], 0,
											"C:\\NoxPost\\src\\Client\\System\\gameloop.c", 297);
				sub_449A10(0, (int)v10, (int)v12, 24, sub_43E230, sub_43E200);
			}
			goto LABEL_16;
		}
		sub_4DD180(31);
	}
	if (!(*(_DWORD*)&nox_common_engineFlags & 0x40000)) {
		dword_5d4594_2650672 = 1;
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

	sub_4CC930();
	result = dword_587000_173332;
	if (dword_587000_173332) {
		int v3; // [esp+4h] [ebp-Ch]
		int v4; // [esp+8h] [ebp-8h]
		int v5; // [esp+Ch] [ebp-4h]
		sub_43BEB0_get_video_mode(&v3, &v5, &v4);
		if (!v3)
			sub_43BEF0_set_video_mode(NOX_DEFAULT_WIDTH, NOX_DEFAULT_HEIGHT, v4);
		result = dword_587000_173332;
	}

	if (!result) {
		nox_common_gameFlags_unset_40A540(9437184);
		return 0;
	}
	sub_43E1A0(0);
	if (!(*(_DWORD*)&nox_common_engineFlags & 0x40000)) {
		dword_5d4594_2650672 = 1;
		sub_44DA60(1);
	}
	if (!sub_4AC2B0(nox_server_currentMapGetFilename_409B30())) {
		v13 = nox_server_currentMapGetFilename_409B30();
		v6 = loadString_sub_40F1D0((char*)&byte_587000[93528], 0, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 386);
		sub_4516C0(v6, v13);
		sub_4356E0();
		return 0;
	}
	if (nox_common_gameFlags_check_40A5C0(1))
		sub_4DD180(31);
	else
		sub_43C9F0();
	sub_43C720(1);

	if (nox_common_gameFlags_check_40A5C0(9437184))
		nox_common_gameFlags_unset_40A540(9437184);
	return 1;
}

//----- (0043E290) --------------------------------------------------------
void mainloop() {
#ifdef NOX_E2E_TEST
	time_hook();
#endif
	unsigned __int8* v0; // eax
	int2* v1;            // edi
	int v2;              // ebp
	int v3;              // ebx
	int v4;              // esi
	int v5;              // eax
	int v6;              // eax
	int v7;              // esi
	int v9;              // edi
	int v10;             // eax
	int v11;             // ebx
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
	int v26;             // [esp+18h] [ebp-40h]
	int2* v27;           // [esp+20h] [ebp-38h]
	int v28[10];         // [esp+24h] [ebp-34h]

	if (mainloop_enter) {
		mainloop_enter(mainloop_enter_args);
		return;
	}

#ifdef __EMSCRIPTEN__
	DWORD cur_tick;
	static DWORD last_tick;

	// rate limit to < 40 fps
	cur_tick = nox_get_ticks();
	if (cur_tick - last_tick < 1000 / 40)
		return;
	last_tick = cur_tick;
#endif

	if (dword_587000_173328) {
		int ret = map_download_loop(0);
		if (ret == -1) {
			return;
		} else if (ret == 0) {
			// map error
			dword_587000_93196 = 0;
			dword_587000_93200 = 0;
			mainloop_exit();
			return;
		}
	} else {
		_control87(0x300u, 0x300u);
		if (!sub_43DEB0()) {
			// XXX
			if (dword_587000_173328)
				return;
			dword_587000_93196 = 0;
			dword_587000_93200 = 0;
			mainloop_exit();
			return;
		}
	}
	if (sub_43AF70() == 1) {
		sub_40D250();
		sub_40DF90();
	}
	sub_416C70(30);
	sub_4453A0_poll_events();
	sub_413520_gamedisk();
	sub_435770();
	if (!func_5D4594_816388()) {
		mainloop_exit();
		return;
	}
	sub_435780();
	sub_435740();
	sub_430880(1);
	nox_client_processMouseInput_4308A0(1);
	sub_46B740();
	v0 = (unsigned __int8*)sub_430940();
	for (dword_5d4594_2618912 = v0; *v0; dword_5d4594_2618912 = v0) {
		sub_46B6B0(v0);
		v0 = (unsigned __int8*)(dword_5d4594_2618912 + 8);
	}
	if (!nox_draw_unk1()) {
		mainloop_exit();
		return;
	}
	sub_430880(0);
	if (!func_5D4594_816392()) {
		mainloop_exit();
		return;
	}
	sub_4519C0();
	sub_4312C0();
	sub_495430();
	if (nox_common_gameFlags_check_40A5C0(1) && dword_587000_93200 == 1) {
		if (!dword_5d4594_815132) {
			if (nox_common_gameFlags_check_40A5C0(0x2000)) {
				if (sub_40A680()) {
					sub_4DEF00();
					sub_40A690();
				} else if (sub_459D60() && !nox_common_gameFlags_check_40A5C0(9437184)) {
					if (sub_459DA0())
						sub_4DF020();
					sub_459D50(0);
				}
				if (*(int*)&byte_5D4594[2598000] >= *(int*)&byte_5D4594[816400]) {
					sub_4161E0();
					sub_416690();
					*(_DWORD*)&byte_5D4594[816400] = *(_DWORD*)&byte_5D4594[2598000] + 60 * *(_DWORD*)&byte_5D4594[2649704];
				}
			}
		}
	}
	if (dword_5d4594_815132) {
		sub_43C380();
		*(_DWORD*)&nox_common_engineFlags &= 0x7FFFFFFFu;
		if (!*(_DWORD*)&byte_5D4594[816408]) {
			v1 = nox_client_getMousePos_4309F0();
			v27 = v1;
			v2 = v1->field_0 - *(_DWORD*)&byte_5D4594[816420];
			v3 = v1->field_4 - *(_DWORD*)&byte_5D4594[816424];
			v4 = v2 * v2 + v3 * v3;
			if (*(_DWORD*)&byte_5D4594[816428]) {
				v5 = nox_double2int(sqrt((double)(v2 * v2 + v3 * v3))) / 4;
				if (v5 > 0) {
					v26 = v5;
					do {
						v6 = sub_415FF0(0, 100, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 570);
						v7 = *(_DWORD*)&byte_5D4594[816420] + v2 * v6 / 100;
						v9 = *(_DWORD*)&byte_5D4594[816424] + v3 * v6 / 100;
						v23 = sub_415FF0(2, 5, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 582);
						v22 = sub_415FF0(2, 5, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 581);
						v21 = sub_415FF0(-7, 2, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 579);
						v10 = sub_415FF0(-5, 5, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 578);
						nox_client_newScreenParticle_431540(4, v7, v9, v10, v21, 1, v22, v23, 2, 1);
						--v26;
					} while (v26);
					v4 = v2 * v2 + v3 * v3;
					v1 = v27;
				}
				if (v4 < 10)
					*(_DWORD*)&byte_5D4594[816428] = 0;
				*(_DWORD*)&byte_5D4594[816420] = v1->field_0;
				*(_DWORD*)&byte_5D4594[816424] = v1->field_4;
			} else if (v4 > 64) {
				*(_DWORD*)&byte_5D4594[816428] = 1;
			}
			if (v1[2].field_4 == 1) {
				sub_415FF0(0, 2, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 608);
				if (!*(_DWORD*)&byte_5D4594[816416]) {
					*(_DWORD*)&byte_5D4594[816416] = 1;
					sub_452D80(924, 100);
					v11 = 75;
					do {
						v12 = sub_415FF0(0, 255, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 620);
						v13 = sub_415FF0(6, 12, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 621);
						v14 = v13 * *(int*)&byte_587000[8 * v12 + 192088];
						v15 = v13 * *(int*)&byte_587000[8 * v12 + 192092] / 16 - 6;
						v24 = sub_415FF0(2, 5, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 633);
						v16 = sub_415FF0(2, 5, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 632);
						nox_client_newScreenParticle_431540(4, v14 / 16 + v27->field_0, v27->field_4 + v15, v14 / 16, v15, 1, v16, v24, 2, 1);
						--v11;
					} while (v11);
				}
			} else {
				*(_DWORD*)&byte_5D4594[816416] = 0;
			}
		}
	}
	if (!(*(_DWORD*)&nox_common_engineFlags & 0x80000000)) {
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
		if (!(nox_common_engineFlags & 0x40000) || nox_common_engineFlags & 0x100 || dword_5d4594_815132)
			nox_client_drawCursorAndTooltips_477830(); // Draw cursor
		sub_44D9F0(1);
		if (!sub_409F40(4096)) // CheckRuleFlags and smth
			sub_46D830();
		if (!(nox_common_engineFlags & 0x40000) || nox_common_engineFlags & 0x100 || dword_5d4594_815132) {
			sub_48A220();
			sub_4AD170_call_copy_backbuffer();
			sub_48A290_call_present();
		}
	}
	sub_435750();
	if (!*(_DWORD*)&byte_587000[93192]) {
		mainloop_stop();
		return;
	}
	int v17 = *(_DWORD*)&nox_common_engineFlags;
	if (!nox_common_gameFlags_check_40A5C0(1) || !nox_common_gameFlags_check_40A5C0(2)) {
		mainloop_wait_and_exit(v17);
		return;
	}
	if (!(v17 & 0x40000)) {
		if (nox_common_gameFlags_check_40A5C0(0x10000000)) {
			if (!(v17 & 0x80000000))
				sub_416DD0();
			mainloop_stop();
			return;
		}
	}
	mainloop_wait_and_exit(v17);
	return;
}
