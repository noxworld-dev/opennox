#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif

#include "client/shell/wolapi/wolchat.h"
#include "client/shell/wolapi/woldlgs.h"
#include "client/system/parsecmd.h"
#include "common/object/armrlook.h"
#include "common/object/weaplook.h"
#include "common/system/team.h"
#include "common/xfer/savegame/xferplyr.h"

#include "client/gui/servopts/playrlst.h"
#include "client/gui/woldisc.h"
#include "client/network/netclint.h"
#include "client/system/ctrlevnt.h"
#include "common/ability/comablty.h"
#include "common/magic/speltree.h"
#include "common/wolapi/woluser.h"

#include "proto.h"

#ifdef USE_SDL
extern _DWORD dword_5d4594_805860;
extern _DWORD dword_5d4594_526276;
extern _DWORD dword_5d4594_251704;
extern _DWORD dword_5d4594_1304;
extern _DWORD dword_5d4594_371756;
extern _DWORD dword_5d4594_251712;
extern _DWORD dword_5d4594_1280;
extern _DWORD dword_587000_80800;
extern _DWORD dword_5d4594_251708;
extern _DWORD dword_5d4594_251716;
extern _DWORD dword_5d4594_10984;
extern _DWORD dword_5d4594_371264;
extern _DWORD dword_5d4594_1308;
extern _DWORD dword_5d4594_2660032;
extern _DWORD dword_5d4594_3616;
extern _DWORD dword_587000_93200;
extern _DWORD dword_5d4594_252276;
extern _DWORD dword_5d4594_251720;
extern _DWORD dword_5d4594_3804680;
extern _DWORD dword_5d4594_251496;
extern _DWORD dword_5d4594_3620;
extern _DWORD dword_5d4594_251508;
extern _DWORD dword_5d4594_251744;
extern _DWORD dword_5d4594_251504;
extern _DWORD dword_5d4594_251556;
extern _DWORD dword_5d4594_4808;
extern _DWORD dword_5d4594_251552;
extern _DWORD dword_5d4594_251700;
extern _DWORD dword_5d4594_251564;
extern _DWORD dword_5d4594_528252;
extern _DWORD dword_5d4594_3484;
extern _DWORD dword_5d4594_251560;
extern _DWORD dword_5d4594_251600;
extern _DWORD dword_5d4594_251608;
extern _DWORD dword_5d4594_3632;
extern _DWORD dword_5d4594_3624;
extern _DWORD dword_5d4594_528256;
extern _DWORD dword_5d4594_371692;
extern _DWORD dword_5d4594_251540;
extern _DWORD dword_5d4594_251548;
extern _DWORD dword_5d4594_251568;
extern _DWORD dword_5d4594_251572;
extern _DWORD dword_5d4594_2650672;
extern _DWORD dword_5d4594_10956;
extern _DWORD dword_5d4594_2660652;
extern _DWORD dword_587000_26048;
extern _DWORD dword_5d4594_2650652;
extern _DWORD dword_5d4594_4668;
extern SDL_GLContext g_ddraw;
#endif

int nox_enable_audio = 1;
int nox_enable_threads = 1;
int nox_video_dxFullScreen = 0;
int nox_video_dxUnlockSurface = 0;
HANDLE* nox_video_cursorDrawThreadHandle;

_DWORD nox_common_engineFlags;
_DWORD nox_common_gameFlags;        // & 1 = host server; & 0x800 = solo game
int nox_server_gameSettingsUpdated; // If you define it as 1-byte bool, the game will crash

void f(int);
int g_v20, g_v21;
int g_argc2;
char** g_argv2;

int map_download_finish();

nox_missing_string* missing_strings = 0;
nox_string_entry* string_entries = 0;
size_t string_entries_cnt = 0;

char file_buffer[4096] = {0};
wchar_t file_buffer_w[4096 * 2] = {0};

FILE* nox_file_1 = 0;
FILE* nox_file_4 = 0;
FILE* nox_file_5 = 0;
FILE* nox_file_10 = 0;
int nox_file_10_mode = 0;
FILE* nox_file_net_log = 0;

_DWORD* dword_5D4594_251544 = 0;

obj_412ae0_t* byte_5D4594_251584[3] = {0};
int byte_5D4594_251596 = 0;

extern obj_5D4594_2650668_t** ptr_5D4594_2650668;
extern int ptr_5D4594_2650668_cap;

extern int nox_win_width;
extern int nox_win_height;
extern int nox_win_width_1;
extern int nox_win_height_1;
extern int nox_win_depth_1;
extern int nox_win_width_2;
extern int nox_win_height_2;
extern int nox_win_depth_2;

extern const char* table_5184[];

extern table_26792_t table_26792[];
extern int table_26792_cnt;

extern table_27104_t table_27104[];
extern int table_27104_cnt;

extern table_27008_t table_27008[];
extern int table_27008_cnt;

extern table_27168_t table_27168[];
extern int table_27168_cnt;

extern table_28760_t table_28760[];

#ifdef DEBUG_MALLOCS
void* nox_malloc2(size_t x, char* func, int line, char* file) {
	void* buf = malloc(100 + x);
	memset(buf, 0, 100 + x);
	strcpy((char*)((int)buf + x), func);
	memcpy((char*)((int)buf + x + strlen(func)), &line, sizeof(line));
	strncpy((char*)((int)buf + x + strlen(func) + sizeof(line)), file,
		((strlen(file) > (100 - strlen(func) - sizeof(line))) ? (100 - strlen(func) - sizeof(line))
								      : strlen(file)));
	return buf;
}
#endif

void nox_exit(int exitCode) {
#ifdef __EMSCRIPTEN__
	nox_sleep(0x32u);
#endif
	exit(exitCode);
}

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
	sub_413060();
	sub_4311B0();
	sub_430EF0();
	sub_430210();
	sub_410FC0_free();
	sub_4106C0();
	sub_42F4D0();
	sub_42EDC0();
	sub_42CD90();
	sub_410020();
	sub_40EA70();
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

void mainloop_exit_1() {
	if (!dword_587000_93200) {
		cleanup();
		nox_exit(0);
	}

	// repeat
	f(1);
}

void mainloop_exit_2() {
	nox_common_gameFlags_unset_40A540(0x10000000);
	nox_common_gameFlags_unset_40A540(55280);
	nox_common_gameFlags_unset_40A540(9437184);
	sub_43F140(300);
	sub_43D990();
	sub_4D39B0();
	if (nox_common_gameFlags_check_40A5C0(1))
		sub_4D23C0();
	if (nox_common_gameFlags_check_40A5C0(2))
		sub_435EB0();
	if (!sub_43BF10_upd_video_mode(1))
		return;
	*(_DWORD*)&byte_587000[80852] = nox_video_getGammaSetting_434B00();
	nox_video_setGammaSetting_434B30(1);
	sub_434B60();
	g_v21 = 0;
	if (nox_common_gameFlags_check_40A5C0(1))
		sub_4D3200();
	if (nox_common_gameFlags_check_40A5C0(2))
		sub_437190();
	sub_416190();
	if (*(_WORD*)&nox_common_engineFlags & 0x1000)
		sub_413E30();
	nullsub_2();

	// repeat
	f(0);
}

//----- (00401000) --------------------------------------------------------
int nox_get_audio_enabled() { return nox_enable_audio; }

//----- (00401010) --------------------------------------------------------
void sub_401010() { nox_srand(1u); }

//----- (00401020) --------------------------------------------------------
wchar_t* sub_401020() {
	wchar_t* buf = (wchar_t*)&byte_5D4594[0];
	nox_swprintf(buf, L"V:%S", &byte_587000[180]);
	return buf;
}

//----- (00401040) --------------------------------------------------------
BOOL sub_401040() {
	BOOL result; // eax

	result = nox_common_gameFlags_check_40A5C0(1);
	*(_DWORD*)&byte_5D4594[2598000] = result;
	return result;
}

//----- (00401060) --------------------------------------------------------
int sub_401060() { return *(_DWORD*)&byte_5D4594[264]; }

//----- (00401070) --------------------------------------------------------
int __cdecl cmain(int argc, const char* argv[]) {
	int result; // eax
	// int v20; // ebx
	// int v21; // esi
	// char* v23; // eax
	// int v24; // [esp+10h] [ebp-434h]
	// int v25; // [esp+14h] [ebp-430h]
	// int v26; // [esp+18h] [ebp-42Ch]
	// int v27; // [esp+1Ch] [ebp-428h]
	// int v28; // [esp+20h] [ebp-424h]

	// v24 = 0;
	// v27 = 0;
	sub_416B20();
	*(_DWORD*)&byte_5D4594[2650640] = 0;
	*(_DWORD*)&byte_5D4594[2618916] = 0;
	dword_5d4594_2650672 = 0;
	sub_43BDD0(10);
	nox_common_gameFlags_unset_40A540(-1);
	sub_40A4D0(3);
	nox_common_engineFlags = 1024;
	dword_5d4594_2650652 = 0;
	BOOL v2 = nox_common_gameFlags_check_40A5C0(1);
	*(_DWORD*)&byte_5D4594[2649704] = 30;
	*(_DWORD*)&byte_5D4594[2598000] = v2;
	sub_416D40();
	bool isServer = 0;
	for (int i = 0; i < argc; i++) {
		if (!_strcmpi(argv[i], "-serveronly")) {
			isServer = 1;
			break;
		}
	}
	if (!isServer) {
		result = sub_416A10();
		if (!result)
			return result;
	}
	sub_43DDF0(0);
	nox_set_draw_unk1(0);
	sub_43DE40(0);
	sub_40A4D0(256);
	for (int i = 1; i < argc; i++) {
		char* flag = argv[i];
		if (!_strcmpi(flag, "-nolimit")) {
			sub_43DDE0(0);
			*(_DWORD*)&byte_587000[84] = 0;
		} else if (!_strcmpi(flag, "-serveronly")) {
			nox_enable_audio = 0;
			*(_DWORD*)&nox_common_engineFlags |= 0x40040000u;
			sub_416B20();
		} else if (!_strcmpi(flag, "-sleep")) {
			*(_DWORD*)&nox_common_engineFlags |= 0x40000000;
		} else if (!_strcmpi(flag, "-drop")) {
			++i;
			int v = atoi(argv[i]);
			sub_552010(v);
		} else if (!_strcmpi(flag, "-notext")) {
			*(_DWORD*)&nox_common_engineFlags |= 0x10000;
		} else if (!_strcmpi(flag, "-nolog")) {
			sub_413C00();
		} else if (!_strcmpi(flag, "-lock")) {
			*(_DWORD*)&nox_common_engineFlags |= 0x2000000;
		} else if (!_strcmpi(flag, "-safe")) {
			int v11 = *(_DWORD*)&nox_common_engineFlags;
			BYTE1(v11) = BYTE1(v11) & 0xFB | 2;
			nox_enable_audio = 0;
			nox_video_dxUnlockSurface = 1;
			nox_common_engineFlags = v11;
			dword_587000_80800 = 0;
			*(_DWORD*)&byte_5D4594[805840] = 1;
			nox_enable_threads = 0;
			int v12 = 16;
			if (!sub_4300D0(1))
				v12 = 8;
			nox_win_width_1 = NOX_DEFAULT_WIDTH;
			nox_win_height_1 = NOX_DEFAULT_HEIGHT;
			nox_win_depth_1 = v12;
			nox_win_width_2 = NOX_DEFAULT_WIDTH;
			nox_win_height_2 = NOX_DEFAULT_HEIGHT;
			nox_win_depth_2 = v12;
		} else if (!_strcmpi(flag, "-noaudio")) {
			nox_enable_audio = 0;
		} else if (!_strcmpi(flag, "-noMMX")) {
			dword_587000_80800 = 0;
			*(_DWORD*)&byte_5D4594[805840] = 1;
		} else if (!_strcmpi(flag, "-nothread")) {
			nox_enable_threads = 0;
		} else if (!_strcmpi(flag, "-vol")) {
			byte_587000[88] = atoi(argv[i]);
		} else if (!_strcmpi(flag, "-noFloor")) {
			*(_DWORD*)&nox_common_engineFlags |= 0x100000;
		} else if (!_strcmpi(flag, "-noDraw")) {
			*(_DWORD*)&nox_common_engineFlags |= 0x40000;
		} else if (!_strcmpi(flag, "-port")) {
			++i;
			int v = atoi(argv[i]);
			sub_40A3E0(v);
		} else if (!_strcmpi(flag, "-clientport")) {
			++i;
			int v = atoi(argv[i]);
			sub_40A410(v);
		} else if (!_strcmpi(flag, "-nosoft")) {
			int v8 = *(_DWORD*)&nox_common_engineFlags;
			BYTE1(v8) &= 0xFBu;
			*(_DWORD*)&nox_common_engineFlags = v8;
		}
	}
	char cwd[1024]; // [esp+44h] [ebp-400h]
	_getcwd(cwd, 1023);
	sub_409E20(cwd);

	nox_common_readSKU_fromRegistry_4D78C0();
	_controlfp(0x300u, 0x300u);
	nox_win_width = 0;
	sub_409F80(32);
	*(_DWORD*)&byte_5D4594[2614260] = *(_DWORD*)&byte_5D4594[2649704] >> 1;
	sub_4093A0();
	nox_ensure_thing_bin();
	result = nox_strman_readfile("nox.str"); // strange, should be .csf but it works anyway
	if (!result) {
		return result;
	}
	sub_4D07F0();
	sub_40AED0();
	sub_416500();
	result = nox_common_readcfgfile("nox.cfg", 0);
	if (!result) {
		return result;
	}
	if (!*(_DWORD*)&byte_5D4594[805856])
		sub_4445C0();
	sub_416190();
	sub_415F70();
	sub_42EAE0();
	sub_415D50();
	sub_4158C0();
	sub_4444F0();
	sub_4D11A0();
	nox_video_resizewnd(0, 0, 16);
	result = sub_43BF10_upd_video_mode(1);
	if (!result) {
		return result;
	}
	sub_434350(*(int*)&byte_5D4594[2650656]);
	sub_440900();
	result = nox_video_read_videobag(*(int*)&dword_5d4594_3804680);
	if (!result) {
		return result;
	}
	result = sub_431370();
	if (!result) {
		return result;
	}
	result = nox_audio_initall(nox_enable_audio);
	if (!(result || !nox_enable_audio)) {
		return result;
	}
	result = sub_415470();
	if (!result) {
		return result;
	}
	result = sub_430190();
	if (!result) {
		return result;
	}
	result = sub_4101D0();
	if (!result) {
		return result;
	}
	result = sub_410F60_init();
	if (!result) {
		return result;
	}
	sub_414C90();
	sub_4D0A30();
	sub_4D0E00();
	sub_40EA10();
	sub_40B890(32);
	sub_40B170(32);
	sub_4134D0();
	if (dword_587000_26048 == 6 || dword_587000_26048 == 8)
		sub_43F680(0);
	sub_413920();
	result = sub_431390();
	if (!result) {
		return result;
	}
	sub_4147E0(getWindowHandle_sub_401FD0());
	g_argc2 = argc;
	g_argv2 = argv;
	g_v20 = 0;
	g_v21 = 0;
	f(0);
	return result;
}
// 4015E2: variable 'v18' is possibly undefined
// 4017F7: variable 'v22' is possibly undefined
// 4093D0: using guessed type int sub_4093D0(void);
// 413F80: using guessed type void nullsub_2(void);

//----- (00401B10) --------------------------------------------------------
void sub_401B10() { nox_srand(0xCu); }

//----- (00401B20) --------------------------------------------------------
void __cdecl sub_401B20(char* a1) {
	char* v1; // edi
	int v2;   // eax

	strcpy((char*)&byte_5D4594[272], "\xecqX");
	*(_DWORD*)&byte_5D4594[404] = 1;
	v1 = strtok(a1, " \t");
	sub_43BEF0_set_video_mode(0, 0, 0);
	if (v1) {
		do {
			if (!strcmp("-window", v1)) {
				*(_DWORD*)&nox_video_dxFullScreen = 0;
				dword_5d4594_805860 = 0;
			} else if (!strcmp("-swindow", v1)) {
				*(_DWORD*)&nox_video_dxFullScreen = 0;
				dword_5d4594_805860 = 1;
			} else if (!strcmp("-minimize", v1)) {
				*(_DWORD*)&byte_5D4594[805864] = 1;
			} else {
				v2 = *(_DWORD*)&byte_5D4594[404];
				*(_DWORD*)&byte_5D4594[4 * *(_DWORD*)&byte_5D4594[404] + 272] = v1;
				*(_DWORD*)&byte_5D4594[404] = v2 + 1;
			}
			v1 = strtok(0, " \t");
		} while (v1);
		*(_DWORD*)&byte_5D4594[4 * *(_DWORD*)&byte_5D4594[404] + 272] = 0;
	} else {
		*(_DWORD*)&byte_5D4594[4 * *(_DWORD*)&byte_5D4594[404] + 272] = 0;
	}
}

//----- (00408CC0) --------------------------------------------------------
FILE* __cdecl sub_408CC0_fopen(const char* path, int mode) {
	FILE* f = 0;
	if (mode) {
		if (mode == 1) {
			f = fopen(path, "wb");
		} else if (mode == 2) {
			f = fopen(path, "r+b");
		}
	} else {
		f = fopen(path, "rb");
	}
	nox_file_10_mode = mode;

	if (!f)
		return 0;

	*(_DWORD*)&byte_5D4594[1288] = 0;
	*(_DWORD*)&byte_5D4594[1276] = 0;
	nox_file_10 = f;
	*(_DWORD*)&byte_5D4594[1284] = 0;
	*(_DWORD*)&byte_5D4594[1292] = 0;
	dword_5d4594_1280 = 0;
	dword_5d4594_1304 = 0;
	return f;
}

//----- (00408D40) --------------------------------------------------------
int __cdecl sub_408D40(FILE* f, int a2) {
	if (sub_409A60())
		return 0;
	if (a2 == -1)
		sub_409580(0, 0);
	else
		sub_409580((int*)&byte_587000[28 * a2 + 3744], 56);
	return 1;
}

//----- (00408D90) --------------------------------------------------------
int __cdecl sub_408D90(FILE* a1) {
	int v1; // esi

	if (sub_409A60()) {
		if (byte_5D4594[1284] & 7) {
			v1 = 8 - (byte_5D4594[1284] & 7);
			if (nox_file_10_mode) {
				sub_4097C0(&byte_5D4594[1288], 8, &byte_5D4594[1276]);
				fwrite(&byte_5D4594[1276], 8u, 1u, a1);
			}
			*(_DWORD*)&byte_5D4594[1284] += v1;
		}
		ftell(a1);
	}
	fclose(a1);
	*(_DWORD*)&byte_5D4594[1276] = 0;
	*(_DWORD*)&byte_5D4594[1288] = 0;
	nox_file_10 = 0;
	*(_DWORD*)&byte_5D4594[1284] = 0;
	*(_DWORD*)&byte_5D4594[1292] = 0;
	dword_5d4594_1280 = 0;
	sub_409580(0, 0);
	return 1;
}

//----- (00408E40) --------------------------------------------------------
signed int __cdecl sub_408E40_fread(char* a1, int a2, signed int a3, FILE* a4) {
	unsigned int v4; // ebp
	unsigned int v5; // edi
	signed int v6;   // ebx
	signed int v7;   // esi
	bool v8;         // zf
	int v9;          // eax
	int v10;         // eax
	signed int v11;  // edi
	signed int v12;  // eax
	int v14;         // [esp+18h] [ebp+8h]

	v4 = 0;
	v5 = a3 * a2;
	v6 = 0;
	v7 = 0;
	v8 = a2 == 0;
	v14 = a3 * a2;
	if (v8 || !a3)
		return 0;
	v9 = byte_5D4594[1284] & 7;
	if (byte_5D4594[1284] & 7) {
		v4 = 8 - v9;
		if (v5 < 8 - v9)
			v4 = v5;
		sub_4099C0(&byte_5D4594[1288], 8, &byte_5D4594[1276]);
		qmemcpy(a1, &byte_5D4594[(byte_5D4594[1284] & 7) + 1276], v4);
		v7 = a3;
		v5 = v14;
		*(_DWORD*)&byte_5D4594[1276] = 0;
		dword_5d4594_1280 = 0;
		*(_DWORD*)&byte_5D4594[1284] += v4;
	}
	v10 = v5 - v4;
	if ((int)(v5 - v4) > 8) {
		v6 = 8 * (v10 / 8);
		v7 = sub_40ADD0_fread(&a1[v4], 1u, 8 * (v10 / 8), a4);
		sub_4099C0(&a1[v4], v6, &a1[v4]);
		if (v7 <= 0) {
			dword_5d4594_1304 = 1;
		} else {
			v7 = a3;
			*(_DWORD*)&byte_5D4594[1284] += v6;
		}
	}
	v11 = v5 - v6 - v4;
	if (v11 > 0) {
		ftell(a4);
		v12 = sub_40ADD0_fread((char*)&byte_5D4594[1288], 1u, 8u, a4);
		v7 = v12;
		if (v12 > 0) {
			sub_4099C0(&byte_5D4594[1288], v12, &byte_5D4594[1276]);
			qmemcpy(&a1[v6 + v4], &byte_5D4594[1276], v11);
			*(_DWORD*)&byte_5D4594[1276] = 0;
			dword_5d4594_1280 = 0;
			*(_DWORD*)&byte_5D4594[1284] += v11;
			return a3;
		}
		dword_5d4594_1304 = 1;
	}
	return v7;
}

//----- (00408FE0) --------------------------------------------------------
signed int __cdecl sub_408FE0(char* a1, int a2, int a3, FILE* a4) {
	signed int result; // eax
	char v5[8];        // [esp+4h] [ebp-8h]

	if (byte_5D4594[1284] & 7)
		sub_408E40_fread(v5, 8 - (byte_5D4594[1284] & 7), 1, a4);
	result = sub_408E40_fread(v5, 8, 1, a4);
	if (result == 1)
		qmemcpy(a1, v5, a3 * a2);
	return result;
}

//----- (00409050) --------------------------------------------------------
int __cdecl sub_409050(FILE* a1, int a2, int a3) {
	int v3; // edi
	int v4; // eax
	int v5; // edi

	dword_5d4594_1304 = 0;
	if (nox_file_10_mode) {
		if (!a2) {
			fseek(a1, 0, 2);
			*(_DWORD*)&byte_5D4594[1284] = ftell(a1);
		}
		return 0;
	}
	v3 = a2;
	if (a3 == 1) {
		if (!a2)
			return 0;
		v3 = *(_DWORD*)&byte_5D4594[1284] - ftell(a1) + a2;
	}
	fseek(a1, v3, a3);
	v4 = ftell(a1);
	v5 = v4 & 7;
	*(_DWORD*)&byte_5D4594[1284] = v4;
	if (v4 & 7) {
		fseek(a1, -v5, 1);
		if (sub_40ADD0_fread((char*)&byte_5D4594[1288], 1u, 8u, a1) <= 0) {
			*(_DWORD*)&byte_5D4594[1284] -= v5;
			return 0;
		}
	}
	return 0;
}

//----- (00409110) --------------------------------------------------------
int __cdecl sub_409110(FILE* a1) {
	int v1; // esi
	int v2; // esi

	if (byte_5D4594[1284] & 7) {
		v1 = 8 - (byte_5D4594[1284] & 7);
		sub_4097C0(&byte_5D4594[1288], 8, &byte_5D4594[1276]);
		fwrite(&byte_5D4594[1276], 8u, 1u, a1);
		*(_DWORD*)&byte_5D4594[1284] += v1;
	}
	v2 = *(_DWORD*)&byte_5D4594[1284];
	*(_DWORD*)&byte_5D4594[1276] = 0;
	dword_5d4594_1280 = 0;
	fwrite(&byte_5D4594[1276], 8u, 1u, a1);
	*(_DWORD*)&byte_5D4594[1284] += 8;
	return v2;
}

//----- (00409190) --------------------------------------------------------
int __cdecl sub_409190(FILE* a1, int a2, int a3) {
	int v4[2];
	char v6[8]; // [esp+8h] [ebp-8h]

	v4[0] = a2;
	v4[1] = 0;
	if (a3 >= 0) {
		fseek(a1, a3, 0);
		sub_4097C0(&v4, 8, v6);
		fwrite(v6, 8u, 1u, a1);
		fseek(a1, 0, 2);
	}
	return 0;
}

//----- (00409200) --------------------------------------------------------
size_t __cdecl sub_409200(char* a1, int a2, int a3, FILE* a4) {
	int v4;               // ecx
	unsigned int v5;      // ebx
	int v6;               // esi
	size_t v7;            // ebp
	int v8;               // eax
	unsigned int v9;      // edx
	unsigned __int8* v10; // edi
	int v11;              // eax
	size_t v12;           // eax
	int v13;              // ecx
	int v14;              // edi
	int v15;              // ebx
	char* v16;            // esi
	signed int v17;       // eax
	int v19;              // [esp+14h] [ebp+8h]
	int v20;              // [esp+14h] [ebp+8h]
	int v21;              // [esp+18h] [ebp+Ch]

	v4 = a3;
	v5 = a3 * a2;
	v6 = 0;
	v7 = -1;
	v21 = a3 * a2;
	if (!a2 || !v4) // TODO: byte_5D4594 == (unsigned __int8*)-1288 || ...
		return 0;
	v8 = byte_5D4594[1284] & 7;
	if (byte_5D4594[1284] & 7) {
		if (v5 >= 8 - v8) {
			v19 = 8 - v8;
			v9 = 8 - v8;
		} else {
			v9 = v5;
			v19 = v5;
		}
		qmemcpy(&byte_5D4594[v8 + 1288], a1, 4 * (v9 >> 2));
		v10 = &byte_5D4594[4 * (v9 >> 2) + 1288 + v8];
		v11 = v9 + *(_DWORD*)&byte_5D4594[1284];
		qmemcpy(v10, &a1[4 * (v9 >> 2)], v9 & 3);
		*(_DWORD*)&byte_5D4594[1284] = v11;
		if (!(v11 & 7)) {
			sub_4097C0(&byte_5D4594[1288], 8, &byte_5D4594[1276]);
			v12 = fwrite(&byte_5D4594[1276], 8u, 1u, a4);
			*(_DWORD*)&byte_5D4594[1288] = 0;
			v7 = v12;
			*(_DWORD*)&byte_5D4594[1292] = 0;
		}
		v6 = v19;
	}
	v13 = v5 - v6;
	v20 = v5 - v6;
	if (v5 != v6) {
		v14 = v13 / 8;
		if (v13 / 8 > 0) {
			v15 = v13 / 8;
			v16 = &a1[v6];
			do {
				sub_4097C0(v16, 8, &byte_5D4594[1276]);
				v16 += 8;
				--v15;
				v7 = fwrite(&byte_5D4594[1276], 8u, 1u, a4);
				*(_DWORD*)&byte_5D4594[1284] += 8;
			} while (v15);
			v13 = v20;
			v5 = v21;
		}
		v17 = v13 - 8 * v14;
		if (v17 > 0) {
			v7 = 1;
			qmemcpy(&byte_5D4594[1288], &a1[v5 - v17], v17);
			*(_DWORD*)&byte_5D4594[1284] += v17;
		}
	}
	return v7;
}

//----- (00409370) --------------------------------------------------------
int sub_409370() { return -(dword_5d4594_1304 != 0); }

//----- (00409390) --------------------------------------------------------
int sub_409390() { return *(_DWORD*)&byte_5D4594[1284]; }

//----- (004093A0) --------------------------------------------------------
void sub_4093A0() {
	nox_file_10 = 0;
	*(_DWORD*)&byte_5D4594[1284] = 0;
	*(_DWORD*)&byte_5D4594[1288] = 0;
	*(_DWORD*)&byte_5D4594[1276] = 0;
	*(_DWORD*)&byte_5D4594[1292] = 0;
	dword_5d4594_1280 = 0;
	dword_5d4594_1308 = 0;
}

//----- (004093E0) --------------------------------------------------------
void __cdecl sub_4093E0(FILE* a1, char* a2, int a3) {
	int v3;   // edi
	int v4;   // ebx
	char* v5; // esi
	int v6;   // eax

	v3 = 0;
	v4 = 1;
	if (a3 <= 0) {
	LABEL_12:
		a2[a3 - 1] = 0;
		return;
	}
	v5 = a2;
	while (1) {
		sub_408E40_fread(v5, 1, 1, a1);
		v6 = isspace(*v5);
		if (!v6)
			break;
		if (!v4) {
			*v5 = 32;
		LABEL_10:
			++v3;
			++v5;
		}
		if (v3 >= a3)
			goto LABEL_12;
	}
	v4 = 0;
	if (*v5 != 59)
		goto LABEL_10;
	a2[v3] = 0;
}

//----- (00409470) --------------------------------------------------------
int __cdecl sub_409470(FILE* a1, _BYTE* a2) {
	_BYTE* v2;        // ebx
	int v3;           // ecx
	int v4;           // edi
	int v5;           // ebp
	int v6;           // eax
	WORD CharType[2]; // [esp+10h] [ebp-4h]

	v2 = a2;
	v3 = 0;
	*(_DWORD*)CharType = 0;
	v4 = 1;
	do {
		while (1) {
			v5 = v3;
			sub_408E40_fread((char*)CharType, 1, 1, a1);
			if (sub_409370() == -1)
				return 0;
			if (*(_DWORD*)&byte_587000[1668] <= 1) {
				v3 = *(_DWORD*)CharType;
				v6 = isspace(CharType[0]);
			} else {
				v6 = isspace(CharType[0]);
				v3 = *(_DWORD*)CharType;
			}
			if (v6)
				break;
			v4 = 0;
			if (v3 != 47 || v5 != 47) {
				*v2++ = v3;
			} else {
				sub_409520(a1);
				v2 = a2;
				v3 = *(_DWORD*)CharType;
				v4 = 1;
			}
		}
	} while (v4);
	*v2 = 0;
	return 1;
}

//----- (00409520) --------------------------------------------------------
int __cdecl sub_409520(FILE* a1) {
	FILE* v1;   // esi
	int result; // eax

	v1 = a1;
	do {
		LOBYTE(a1) = 0;
		sub_408E40_fread((char*)&a1, 1, 1, v1);
		result = sub_409370();
	} while (result != -1 && (_BYTE)a1 != 10);
	return result;
}

//----- (00409560) --------------------------------------------------------
void sub_409560() {
	if (dword_5d4594_1308)
		sub_409580(0, 0);
}

//----- (00409580) --------------------------------------------------------
void __cdecl sub_409580(int* a1, int a2) {
	int* v2;              // ebx
	int v3;               // ecx
	int v4;               // ebp
	int v5;               // edx
	int v6;               // ecx
	int v7;               // esi
	int v8;               // edi
	int v9;               // eax
	int* v10;             // edx
	int v11;              // edi
	int v12;              // eax
	unsigned __int8* v13; // esi
	unsigned __int8* v14; // edi
	int v15;              // ebx
	int* v16;             // eax
	int v17;              // ecx
	int* v18;             // esi
	int* v19;             // edi
	unsigned __int8* v20; // esi
	int v21;              // edi

	v2 = a1;
	qmemcpy(&byte_5D4594[2659820], &byte_581450[1416], 0x48u);
	qmemcpy(&byte_5D4594[2659916], &byte_581450[1416], 0x48u);
	qmemcpy(&byte_5D4594[2655724], &byte_581450[1488], 0x1000u);
	v3 = 0;
	if (a1 && (v4 = a2) != 0) {
		a1 = (int*)&byte_5D4594[2659820];
		a2 = 18;
		do {
			v5 = v3 % v4;
			v6 = v3 + 1;
			v7 = (*((unsigned __int8*)v2 + v5) << 8) | *((unsigned __int8*)v2 + v6++ % v4);
			v8 = (v7 << 8) | *((unsigned __int8*)v2 + v6++ % v4);
			v9 = (v8 << 8) | *((unsigned __int8*)v2 + v6 % v4);
			v3 = v6 + 1;
			v10 = a1 + 1;
			v11 = v9 ^ *a1;
			v12 = a2;
			*a1 = v11;
			a1 = v10;
			a2 = v12 - 1;
		} while (v12 != 1);
		v13 = &byte_5D4594[2659820];
		a1 = 0;
		a2 = 0;
		v14 = &byte_5D4594[2659984];
		v15 = 9;
		do {
			sub_4096E0((int*)&a1, &a2);
			v16 = a1;
			v17 = a2;
			*(_DWORD*)v13 = a1;
			*(_DWORD*)v14 = v16;
			v18 = (int*)(v13 + 4);
			v19 = (int*)(v14 - 4);
			*v18 = v17;
			*v19 = v17;
			v13 = (unsigned __int8*)(v18 + 1);
			v14 = (unsigned __int8*)(v19 - 1);
			--v15;
		} while (v15);
		v20 = &byte_5D4594[2655728];
		do {
			v21 = 128;
			do {
				sub_4096E0((int*)&a1, &a2);
				*((_DWORD*)v20 - 1) = a1;
				*(_DWORD*)v20 = a2;
				v20 += 8;
				--v21;
			} while (v21);
		} while ((int)v20 < (int)&byte_5D4594[2659824]);
		dword_5d4594_1308 = 1;
	} else {
		dword_5d4594_1308 = 0;
	}
}

//----- (004096E0) --------------------------------------------------------
int __cdecl sub_4096E0(int* a1, int* a2) {
	unsigned __int8* v2; // ecx
	int result;          // eax
	int v4;              // edx
	int v5;              // ebx
	int v6;              // eax

	v2 = &byte_5D4594[2659824];
	result = *a1;
	v4 = *a2;
	do {
		v5 = *((_DWORD*)v2 - 1);
		v2 += 8;
		v6 = v5 ^ result;
		v4 ^= (*(_DWORD*)&byte_5D4594[4 * (unsigned __int8)v6 + 2658796] +
		       (*(_DWORD*)&byte_5D4594[4 * BYTE1(v6) + 2657772] ^
			(*(_DWORD*)&byte_5D4594[4 * HIBYTE(v6) + 2655724] +
			 *(_DWORD*)&byte_5D4594[4 * BYTE2(v6) + 2656748]))) ^
		      *((_DWORD*)v2 - 2);
		result = (*(_DWORD*)&byte_5D4594[4 * (unsigned __int8)v4 + 2658796] +
			  (*(_DWORD*)&byte_5D4594[4 * BYTE1(v4) + 2657772] ^
			   (*(_DWORD*)&byte_5D4594[4 * HIBYTE(v4) + 2655724] +
			    *(_DWORD*)&byte_5D4594[4 * BYTE2(v4) + 2656748]))) ^
			 v6;
	} while ((int)v2 < (int)&byte_5D4594[2659888]);
	*a1 = v4 ^ *(_DWORD*)&byte_5D4594[2659888];
	*a2 = result ^ *(_DWORD*)&byte_5D4594[2659884];
	return result;
}

//----- (004097C0) --------------------------------------------------------
int __cdecl sub_4097C0(_BYTE* a1, signed int a2, _BYTE* a3) {
	_BYTE* v3;  // edi
	_BYTE* v4;  // esi
	int v5;     // eax
	int v6;     // ebp
	int v7;     // ebp
	int result; // eax

	v3 = a1;
	if (!a1 || !a2)
		return 0;
	v4 = a3;
	if (!a3)
		v4 = a1;
	if (dword_5d4594_1308) {
		v5 = a2 / 8;
		if (a2 / 8 > 0) {
			v6 = a2 / 8;
			do {
				sub_409860(v3, v4, &byte_5D4594[2659820]);
				v3 += 8;
				v4 += 8;
				--v6;
			} while (v6);
			v5 = a2 / 8;
		}
		v7 = 8 * v5;
		if (8 * v5 < a2)
			memmove((unsigned int)v4, v3, a2 - v7);
		result = v7;
	} else {
		if (a1 != v4)
			memmove((unsigned int)v4, a1, a2);
		result = a2;
	}
	return result;
}

//----- (00409860) --------------------------------------------------------
_BYTE* __cdecl sub_409860(_BYTE* a1, _BYTE* a2, _DWORD* a3) {
	int v3;        // esi
	int v4;        // eax
	_DWORD* v5;    // ecx
	int v6;        // edx
	int v7;        // eax
	_BYTE* result; // eax
	int v9;        // [esp+10h] [ebp-10h]
	int v10;       // [esp+10h] [ebp-10h]
	int v11;       // [esp+18h] [ebp-8h]
	int v12;       // [esp+18h] [ebp-8h]

	HIBYTE(v11) = *a1;
	BYTE2(v11) = a1[1];
	v3 = 8;
	BYTE1(v11) = a1[2];
	LOBYTE(v11) = a1[3];
	HIBYTE(v9) = a1[4];
	BYTE2(v9) = a1[5];
	v4 = v11;
	BYTE1(v9) = a1[6];
	v5 = a3;
	LOBYTE(v9) = a1[7];
	v6 = v9;
	do {
		v7 = *v5 ^ v4;
		v5 += 2;
		v6 ^= *(v5 - 1) ^ (*(_DWORD*)&byte_5D4594[4 * (unsigned __int8)v7 + 2658796] +
				   (*(_DWORD*)&byte_5D4594[4 * BYTE1(v7) + 2657772] ^
				    (*(_DWORD*)&byte_5D4594[4 * HIBYTE(v7) + 2655724] +
				     *(_DWORD*)&byte_5D4594[4 * BYTE2(v7) + 2656748])));
		v4 = (*(_DWORD*)&byte_5D4594[4 * (unsigned __int8)v6 + 2658796] +
		      (*(_DWORD*)&byte_5D4594[4 * BYTE1(v6) + 2657772] ^
		       (*(_DWORD*)&byte_5D4594[4 * HIBYTE(v6) + 2655724] +
			*(_DWORD*)&byte_5D4594[4 * BYTE2(v6) + 2656748]))) ^
		     v7;
		--v3;
	} while (v3);
	v12 = *v5 ^ v4;
	v10 = v5[1] ^ v6;
	*a2 = HIBYTE(v10);
	a2[1] = BYTE2(v10);
	a2[2] = BYTE1(v10);
	a2[3] = v10;
	a2[4] = HIBYTE(v12);
	a2[5] = BYTE2(v12);
	result = a2 + 6;
	a2[6] = BYTE1(v12);
	a2[7] = v12;
	return result;
}

//----- (004099C0) --------------------------------------------------------
int __cdecl sub_4099C0(_BYTE* a1, signed int a2, _BYTE* a3) {
	_BYTE* v3;  // edi
	_BYTE* v4;  // esi
	int v5;     // eax
	int v6;     // ebp
	int v7;     // ebp
	int result; // eax

	v3 = a1;
	if (!a1 || !a2)
		return 0;
	v4 = a3;
	if (!a3)
		v4 = a1;
	if (dword_5d4594_1308) {
		v5 = a2 / 8;
		if (a2 / 8 > 0) {
			v6 = a2 / 8;
			do {
				sub_409860(v3, v4, &byte_5D4594[2659916]);
				v3 += 8;
				v4 += 8;
				--v6;
			} while (v6);
			v5 = a2 / 8;
		}
		v7 = 8 * v5;
		if (8 * v5 < a2)
			memmove((unsigned int)v4, v3, a2 - v7);
		result = v7;
	} else {
		if (v4 != a1)
			memmove((unsigned int)v4, a1, a2);
		result = a2;
	}
	return result;
}

//----- (00409A60) --------------------------------------------------------
int sub_409A60() { return dword_5d4594_1308; }

//----- (00409A70) --------------------------------------------------------
int __cdecl sub_409A70(__int16 a1) {
	int result;          // eax
	unsigned __int8* v2; // ecx

	result = 0;
	v2 = &byte_587000[4704];
	while (*(_DWORD*)v2 != (a1 & 0x17F0)) {
		v2 += 4;
		++result;
		if ((int)v2 >= (int)&byte_587000[4728])
			return 0;
	}
	return result;
}

//----- (00409AA0) --------------------------------------------------------
unsigned int sub_409AA0() { return byte_5D4594[3483]; }

//----- (00409AB0) --------------------------------------------------------
int sub_409AB0() { return byte_5D4594[3482]; }

//----- (00409AD0) --------------------------------------------------------
int sub_409AD0() { return *(_DWORD*)&byte_5D4594[3480]; }

//----- (00409AE0) --------------------------------------------------------
int __cdecl sub_409AE0(int a1) {
	int result; // eax

	result = a1;
	if (*(_DWORD*)&byte_5D4594[3480] != a1) {
		*(_DWORD*)&byte_5D4594[3480] = a1;
		*(_DWORD*)&nox_server_gameSettingsUpdated = 1;
	}
	return result;
}

//----- (00409B00) --------------------------------------------------------
int sub_409B00() { return *(_DWORD*)&byte_5D4594[3604]; }

//----- (00409B10) --------------------------------------------------------
int __cdecl sub_409B10(int a1) {
	int result; // eax

	result = a1;
	if (*(_DWORD*)&byte_5D4594[3604] != a1)
		*(_DWORD*)&byte_5D4594[3604] = a1;
	return result;
}

//----- (00409B30) --------------------------------------------------------
char* nox_server_currentMapGetFilename_409B30() { return (char*)&byte_5D4594[2598188]; }

//----- (00409B40) --------------------------------------------------------
char* sub_409B40() { return (char*)&byte_5D4594[2649740]; }

//----- (00409B50) --------------------------------------------------------
unsigned int __cdecl sub_409B50(const char* a1) {
	unsigned int result; // eax

	result = strlen(a1) + 1;
	qmemcpy(&byte_5D4594[3452], a1, result);
	return result;
}

//----- (00409B80) --------------------------------------------------------
char* sub_409B80() { return (char*)&byte_5D4594[3452]; }

//----- (00409B90) --------------------------------------------------------
char* sub_409B90() {
	char* v0;            // eax
	__int16 v1;          // dx
	unsigned __int8 v2;  // al
	unsigned __int8* v3; // edi

	v0 = sub_409E10();
	if (!v0)
		return 0;
	v1 = *(_WORD*)&byte_587000[4736];
	strcpy((char*)&byte_5D4594[2424], v0);
	v2 = byte_587000[4738];
	v3 = &byte_5D4594[strlen((const char*)&byte_5D4594[2424]) + 2424];
	*(_DWORD*)v3 = *(_DWORD*)&byte_587000[4732];
	*((_WORD*)v3 + 2) = v1;
	v3[6] = v2;
	strcat((char*)&byte_5D4594[2424], sub_409B40());
	*(_WORD*)&byte_5D4594[strlen((const char*)&byte_5D4594[2424]) + 2424] = *(_WORD*)&byte_587000[4740];
	strcat((char*)&byte_5D4594[2424], nox_server_currentMapGetFilename_409B30());
	return (char*)&byte_5D4594[2424];
}

//----- (00409C70) --------------------------------------------------------
char* sub_409C70() {
	char* v0;            // eax
	__int16 v1;          // dx
	unsigned __int8 v2;  // al
	unsigned __int8* v3; // edi
	unsigned __int8* v4; // edi
	unsigned __int8 v5;  // cl
	char* result;        // eax

	v0 = sub_409E10();
	if (!v0)
		return 0;
	v1 = *(_WORD*)&byte_587000[4748];
	strcpy((char*)&byte_5D4594[2424], v0);
	v2 = byte_587000[4750];
	v3 = &byte_5D4594[strlen((const char*)&byte_5D4594[2424]) + 2424];
	*(_DWORD*)v3 = *(_DWORD*)&byte_587000[4744];
	*((_WORD*)v3 + 2) = v1;
	v3[6] = v2;
	strcat((char*)&byte_5D4594[2424], sub_409B40());
	*(_WORD*)&byte_5D4594[strlen((const char*)&byte_5D4594[2424]) + 2424] = *(_WORD*)&byte_587000[4752];
	strcat((char*)&byte_5D4594[2424], sub_409B40());
	v4 = &byte_5D4594[strlen((const char*)&byte_5D4594[2424]) + 2425];
	v5 = byte_587000[4760];
	*(_DWORD*)--v4 = *(_DWORD*)&byte_587000[4756];
	result = (char*)&byte_5D4594[2424];
	v4[4] = v5;
	return result;
}

//----- (00409D70) --------------------------------------------------------
char* __cdecl sub_409D70(char* a1) {
	char* result;  // eax
	char* v2;      // eax
	signed int v3; // esi

	result = (char*)_strcmpi((const char*)&byte_5D4594[2598188], a1);
	if (result) {
		strncpy((char*)&byte_5D4594[2598188], a1, 0x50u);
		byte_5D4594[2598267] = 0;
		v2 = strrchr(a1, 92);
		if (v2) {
			v3 = strlen(v2 + 1) - 4;
			result = strncpy((char*)&byte_5D4594[2649740], v2 + 1, v3);
		} else {
			v3 = strlen((const char*)&byte_5D4594[2598188]) - 4;
			if (v3 < 0)
				v3 = 0;
			result = strncpy((char*)&byte_5D4594[2649740], (const char*)&byte_5D4594[2598188], v3);
		}
		byte_5D4594[v3 + 2649740] = 0;
		*(_DWORD*)&nox_server_gameSettingsUpdated = 1;
	}
	return result;
}

//----- (00409E10) --------------------------------------------------------
char* sub_409E10() { return (char*)&byte_5D4594[1396]; }

//----- (00409E20) --------------------------------------------------------
char* __cdecl sub_409E20(char* a1) {
	char* result; // eax

	result = strncpy((char*)&byte_5D4594[1396], a1, 0x400u);
	byte_5D4594[2420] = 0;
	return result;
}

//----- (00409E40) --------------------------------------------------------
int __cdecl sub_409E40(int a1) {
	int result; // eax

	result = a1;
	if (dword_5d4594_3484 != a1) {
		dword_5d4594_3484 = a1;
		*(_DWORD*)&nox_server_gameSettingsUpdated = 1;
	}
	return result;
}

//----- (00409E60) --------------------------------------------------------
int sub_409E60() { return dword_5d4594_3484; }

//----- (00409E70) --------------------------------------------------------
int __cdecl sub_409E70(int a1) {
	int result; // eax

	result = a1 & dword_5d4594_3484;
	if ((a1 & dword_5d4594_3484) != a1) {
		dword_5d4594_3484 |= a1;
		result = nox_common_gameFlags_check_40A5C0(1);
		if (result) {
			if (a1 & 0x2000)
				result = sub_4D7EA0();
		}
		*(_DWORD*)&nox_server_gameSettingsUpdated = 1;
	}
	return result;
}

//----- (00409EC0) --------------------------------------------------------
int __cdecl sub_409EC0(int a1) {
	int result; // eax

	result = a1;
	if (dword_5d4594_3484 & a1) {
		result = ~a1;
		*(_DWORD*)&nox_server_gameSettingsUpdated = 1;
		dword_5d4594_3484 &= ~a1;
	}
	return result;
}

//----- (00409EF0) --------------------------------------------------------
int __cdecl sub_409EF0(int a1) {
	int result; // eax

	dword_5d4594_3484 ^= a1;
	result = nox_common_gameFlags_check_40A5C0(1);
	if (result) {
		if (a1 & 0x2000) {
			result = dword_5d4594_3484;
			if (result & 0x2000)
				result = sub_4D7EA0();
		}
	}
	*(_DWORD*)&nox_server_gameSettingsUpdated = 1;
	return result;
}

//----- (00409F40) --------------------------------------------------------
BOOL __cdecl sub_409F40(int a1) {
	BOOL result; // eax

	if (a1 == 0x2000 && nox_common_gameFlags_check_40A5C0(1056))
		result = 1;
	else
		result = (a1 & dword_5d4594_3484) != 0;
	return result;
}

//----- (00409F80) --------------------------------------------------------
int __cdecl sub_409F80(int a1) {
	int result; // eax

	result = a1;
	if (*(_DWORD*)&byte_5D4594[3464] != a1) {
		*(_DWORD*)&byte_5D4594[3464] = a1;
		*(_DWORD*)&nox_server_gameSettingsUpdated = 1;
	}
	return result;
}

//----- (00409FA0) --------------------------------------------------------
int sub_409FA0() { return *(_DWORD*)&byte_5D4594[3464]; }

//----- (0040A020) --------------------------------------------------------
__int16 __cdecl sub_40A020(__int16 a1) { return *(_WORD*)&byte_5D4594[2 * sub_409A70(a1) + 3488]; }

//----- (0040A180) --------------------------------------------------------
unsigned __int8 __cdecl sub_40A180(__int16 a1) { return byte_5D4594[sub_409A70(a1) + 3500]; }

//----- (0040A1A0) --------------------------------------------------------
BOOL sub_40A1A0() {
	__int16 v0; // ax

	v0 = nox_common_gameFlags_getVal_40A5B0();
	return (sub_40A180(v0) || *(_DWORD*)&byte_5D4594[3592]) && *(_DWORD*)&byte_587000[4660] &&
	       (unsigned __int64)sub_416BB0() > *(_QWORD*)&byte_5D4594[3468];
}

//----- (0040A1F0) --------------------------------------------------------
int __cdecl sub_40A1F0(int a1) {
	int result; // eax

	*(_DWORD*)&byte_587000[4660] = a1;
	result = nox_common_gameFlags_check_40A5C0(1);
	if (result)
		result = sub_4D8F50(159, a1);
	return result;
}

//----- (0040A220) --------------------------------------------------------
int sub_40A220() { return *(_DWORD*)&byte_587000[4660]; }

//----- (0040A230) --------------------------------------------------------
int sub_40A230() { return *(_DWORD*)&byte_5D4594[3468] - (unsigned __int64)sub_416BB0(); }

//----- (0040A250) --------------------------------------------------------
__int64 sub_40A250() {
	__int16 v0;     // ax
	int v1;         // esi
	__int64 v2;     // kr00_8
	__int64 result; // rax

	v0 = nox_common_gameFlags_getVal_40A5B0();
	v1 = sub_409A70(v0);
	v2 = sub_416BB0();
	result = 60000 * byte_5D4594[v1 + 3500];
	*(_QWORD*)&byte_5D4594[3468] = result + v2;
	return result;
}

//----- (0040A2A0) --------------------------------------------------------
const char* __cdecl sub_40A2A0(int a1, const char* a2) {
	const char* result; // eax

	*(_QWORD*)&byte_5D4594[3468] = 1000 * a1 + sub_416BB0();
	sub_40A1F0(1);
	result = a2;
	if (a2)
		result = (const char*)sub_4DA390(a2);
	*(_DWORD*)&byte_5D4594[3592] = 1;
	return result;
}

//----- (0040A300) --------------------------------------------------------
int sub_40A300() { return *(_DWORD*)&byte_5D4594[3592]; }

//----- (0040A310) --------------------------------------------------------
__int64 __cdecl sub_40A310(int a1) {
	__int64 v1;     // kr00_8
	__int64 result; // rax

	v1 = sub_416BB0();
	result = a1;
	*(_QWORD*)&byte_5D4594[3468] = a1 + v1;
	return result;
}

//----- (0040A340) --------------------------------------------------------
int __cdecl sub_40A340(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[3512] = a1;
	return result;
}

//----- (0040A350) --------------------------------------------------------
int sub_40A350() { return *(_DWORD*)&byte_5D4594[3512]; }

//----- (0040A360) --------------------------------------------------------
int __cdecl sub_40A360(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[3516] = a1;
	return result;
}

//----- (0040A370) --------------------------------------------------------
int sub_40A370() { return *(_DWORD*)&byte_5D4594[3516]; }

//----- (0040A380) --------------------------------------------------------
void sub_40A380() {
	sub_40A340(0);
	sub_40A360(0);
	sub_409D70((char*)&byte_5D4594[3608]);
	sub_40A4D0(3);
	nox_common_gameFlags_unset_40A540(137212);
	*(_DWORD*)&nox_server_gameSettingsUpdated = 1;
}

//----- (0040A3C0) --------------------------------------------------------
unsigned int __cdecl sub_40A3C0(unsigned int a1) {
	unsigned int result; // eax

	result = a1;
	if (a1 > 0x800 && a1 < 0x8000)
		*(_DWORD*)&byte_587000[4652] = a1;
	return result;
}

//----- (0040A3E0) --------------------------------------------------------
void __cdecl sub_40A3E0(int a1) {
	CHAR String[64]; // [esp+0h] [ebp-40h]

	*(_DWORD*)&byte_5D4594[3524] = a1;
	nox_sprintf(String, "Nox - %d", a1);
	sub_401FE0(String);
}

//----- (0040A410) --------------------------------------------------------
int __cdecl sub_40A410(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[3528] = a1;
	return result;
}

//----- (0040A420) --------------------------------------------------------
int sub_40A420() { return *(_DWORD*)&byte_5D4594[3528]; }

//----- (0040A430) --------------------------------------------------------
int sub_40A430() {
	int result; // eax

	result = *(_DWORD*)&byte_5D4594[3524];
	if (!*(_DWORD*)&byte_5D4594[3524])
		result = *(_DWORD*)&byte_587000[4652];
	return result;
}

//----- (0040A440) --------------------------------------------------------
char* __cdecl sub_40A440(char* a1) {
	char* result; // eax
	char v2[16];  // [esp+0h] [ebp-10h]

	result = a1;
	if (a1) {
		strncpy(v2, a1, 0xFu);
		v2[15] = 0;
		result = (char*)_strcmpi((const char*)&byte_5D4594[1324], v2);
		if (result) {
			result = strncpy((char*)&byte_5D4594[1324], v2, 0xFu);
			byte_5D4594[1339] = 0;
			*(_DWORD*)&nox_server_gameSettingsUpdated = 1;
		}
	} else {
		byte_5D4594[1324] = 0;
		*(_DWORD*)&nox_server_gameSettingsUpdated = 1;
	}
	return result;
}

//----- (0040A4C0) --------------------------------------------------------
char* sub_40A4C0() { return (char*)&byte_5D4594[1324]; }

//----- (0040A4D0) --------------------------------------------------------
int __cdecl sub_40A4D0(int a1) {
	int result; // eax

	result = *(_DWORD*)&nox_common_gameFlags;
	if ((a1 & *(_DWORD*)&nox_common_gameFlags) != a1) {
		if (a1 & 0x7FFF0)
			*(_DWORD*)&nox_server_gameSettingsUpdated = 1;
		*(_DWORD*)&nox_common_gameFlags |= a1;
		result = sub_445730((*(_WORD*)&nox_common_gameFlags & 0x17F0) != 128);
		if (a1 & 0x4000000) {
			if (nox_common_gameFlags & 1)
				result = sub_4DA390("Settings.c:SuddenDeathStart");
		}
	}
	return result;
}

//----- (0040A540) --------------------------------------------------------
void __cdecl nox_common_gameFlags_unset_40A540(int a1) {
	if (nox_common_gameFlags & a1) {
		nox_common_gameFlags &= ~a1;
		if (a1 & 0x7FFF0)
			*(_DWORD*)&nox_server_gameSettingsUpdated = 1;
	}
	if (a1 & 0x4000000)                       // sudden death
		*(_DWORD*)&byte_5D4594[3592] = 0; // countdown is ticking/set
}

//----- (0040A590) --------------------------------------------------------
int __cdecl sub_40A590(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&nox_server_gameSettingsUpdated = 1;
	*(_DWORD*)&nox_common_gameFlags ^= a1;
	return result;
}

//----- (0040A5B0) --------------------------------------------------------
int nox_common_gameFlags_getVal_40A5B0() { return nox_common_gameFlags; }

// Tests bitfield against gameFlags variable
// I once called this variable mapFlags, but it is actually used for storing the current game mode (chat/DM/elim/ctf...)
// as well whenether sudden death started and much more for ex. if this game client instance is hosting a server the
// 1'st bit of this value is set
//----- (0040A5C0) --------------------------------------------------------
BOOL __cdecl nox_common_gameFlags_check_40A5C0(int a1) { return (a1 & nox_common_gameFlags) != 0; }

//----- (0040A5E0) --------------------------------------------------------
int __cdecl sub_40A5E0(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[3584] = a1;
	return result;
}

//----- (0040A5F0) --------------------------------------------------------
int nox_server_doPlayersAutoRespawn_40A5F0() {
	return !nox_common_gameFlags_check_40A5C0(4096) ? *(_DWORD*)&byte_5D4594[3584] : 0;
}

//----- (0040A610) --------------------------------------------------------
wchar_t* __cdecl sub_40A610(wchar_t* a1) { return nox_wcscpy((wchar_t*)&byte_5D4594[3540], a1); }

//----- (0040A630) --------------------------------------------------------
wchar_t* sub_40A630() { return (wchar_t*)&byte_5D4594[3540]; }

//----- (0040A640) --------------------------------------------------------
wchar_t* __cdecl sub_40A640(wchar_t* a1) {
	wchar_t* result; // eax

	result = nox_wcsncpy((wchar_t*)&byte_5D4594[3560], a1, 8u);
	*(_WORD*)&byte_5D4594[3576] = 0;
	return result;
}

//----- (0040A660) --------------------------------------------------------
wchar_t* sub_40A660() { return (wchar_t*)&byte_5D4594[3560]; }

//----- (0040A670) --------------------------------------------------------
void sub_40A670() { *(_DWORD*)&nox_server_gameSettingsUpdated = 1; }

//----- (0040A680) --------------------------------------------------------
int sub_40A680() { return *(_DWORD*)&nox_server_gameSettingsUpdated; }

//----- (0040A690) --------------------------------------------------------
void sub_40A690() { *(_DWORD*)&nox_server_gameSettingsUpdated = 0; }

//----- (0040A6A0) --------------------------------------------------------
int __cdecl sub_40A6A0(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[3588] = a1;
	return result;
}

//----- (0040A6B0) --------------------------------------------------------
int sub_40A6B0() { return *(_DWORD*)&byte_5D4594[3588]; }

//----- (0040A6C0) --------------------------------------------------------
int sub_40A6C0() { return *(_DWORD*)&byte_587000[4728]; }

//----- (0040A6D0) --------------------------------------------------------
int __cdecl sub_40A6D0(int a1) {
	int result; // eax

	result = *(_DWORD*)&byte_587000[4728];
	if (a1 != *(_DWORD*)&byte_587000[4728]) {
		result = nox_common_gameFlags_check_40A5C0(0x20000);
		if (result == 1)
			result = sub_4D7F10(159);
	}
	*(_DWORD*)&byte_587000[4728] = a1;
	return result;
}

//----- (0040A710) --------------------------------------------------------
int __cdecl sub_40A710(int a1) {
	int v1;              // ecx
	unsigned __int8* v2; // eax

	v1 = 0;
	v2 = &byte_587000[4664];
	while (*(_DWORD*)v2 != a1) {
		v2 += 8;
		++v1;
		if ((int)v2 >= (int)&byte_587000[4704])
			return 1;
	}
	return *(_DWORD*)&byte_587000[8 * v1 + 4668];
}

//----- (0040A740) --------------------------------------------------------
BOOL sub_40A740() {
	char* v0; // esi

	v0 = sub_4165B0();
	return nox_common_gameFlags_check_40A5C0(128) && v0[53] < 0;
}

//----- (0040A770) --------------------------------------------------------
int sub_40A770() {
	int v0;   // edi
	char* v1; // esi
	int v2;   // eax
	int v3;   // ecx
	char* i;  // eax

	v0 = 0;
	if (!sub_417DA0(4)) {
		for (i = sub_416EA0(); i; i = sub_416EE0((int)i)) {
			if (!(i[3680] & 1) && (i[2064] != 31 || !(*(_DWORD*)&nox_common_engineFlags & 0x40000)))
				++v0;
		}
		return v0;
	}
	v1 = sub_418B10();
	if (!v1)
		return v0;
	do {
		v2 = sub_4DA7C0();
		if (v2) {
			while (1) {
				v3 = *(_DWORD*)(*(_DWORD*)(v2 + 748) + 276);
				if (!(*(_BYTE*)(v3 + 3680) & 1) &&
				    (*(_BYTE*)(v3 + 2064) != 31 || !(*(_DWORD*)&nox_common_engineFlags & 0x40000))) {
					break;
				}
				v2 = sub_4DA7F0(v2);
				if (!v2)
					goto LABEL_10;
			}
			++v0;
		}
	LABEL_10:
		v1 = sub_418B60((int)v1);
	} while (v1);
	return v0;
}

//----- (0040A830) --------------------------------------------------------
int __cdecl sub_40A830(int a1) {
	int v1; // edi
	int v2; // esi
	int v3; // eax

	v1 = 0;
	v2 = sub_4DA7C0();
	if (!v2)
		return 0;
	do {
		if (sub_419180(v2 + 48, *(_BYTE*)(a1 + 57))) {
			v3 = *(_DWORD*)(*(_DWORD*)(v2 + 748) + 276);
			if (!(*(_BYTE*)(v3 + 3680) & 1) &&
			    (*(_BYTE*)(v3 + 2064) != 31 || !(*(_DWORD*)&nox_common_engineFlags & 0x40000))) {
				++v1;
			}
		}
		v2 = sub_4DA7F0(v2);
	} while (v2);
	return v1;
}

//----- (0040A8A0) --------------------------------------------------------
int __cdecl sub_40A8A0() {
	int v0;     // ebx
	char* v1;   // edi
	int v2;     // esi
	int v3;     // eax
	int result; // eax
	char* i;    // eax
	int v6;     // ecx

	v0 = 0;
	if (!sub_417DA0(4)) {
		for (i = sub_416EA0(); i; i = sub_416EE0((int)i)) {
			if (*((_DWORD*)i + 514)) {
				v6 = *((_DWORD*)i + 920);
				if (!(v6 & 1) || v6 & 0x20)
					++v0;
			}
		}
		goto LABEL_18;
	}
	v1 = sub_418B10();
	if (!v1) {
	LABEL_18:
		result = v0 < 1;
		LOBYTE(result) = v0 > 1;
		return result;
	}
	do {
		v2 = sub_4DA7C0();
		if (v2) {
			while (1) {
				if (sub_419180(v2 + 48, v1[57])) {
					v3 = *(_DWORD*)(*(_DWORD*)(*(_DWORD*)(v2 + 748) + 276) + 3680);
					if (!(v3 & 1) || v3 & 0x20)
						break;
				}
				v2 = sub_4DA7F0(v2);
				if (!v2)
					goto LABEL_10;
			}
			++v0;
		}
	LABEL_10:
		v1 = sub_418B60((int)v1);
	} while (v1);
	return v0 > 1;
}

//----- (0040A970) --------------------------------------------------------
void sub_40A970() {
	char* i;  // esi
	int v1;   // eax
	float v3; // [esp+0h] [ebp-8h]
	float v4; // [esp+0h] [ebp-8h]

	*(_DWORD*)&byte_5D4594[3520] = *(_DWORD*)&byte_5D4594[2598000];
	*(_DWORD*)&byte_5D4594[3536] = 0;
	v3 = sub_419D40(&byte_587000[5112]);
	*(_DWORD*)&byte_5D4594[3476] = nox_float2int(v3);
	v4 = sub_419D40(&byte_587000[5140]);
	*(_DWORD*)&byte_5D4594[1392] = nox_float2int(v4);
	for (i = sub_416EA0(); i; i = sub_416EE0((int)i)) {
		v1 = *((_DWORD*)i + 920);
		if (v1 & 0x100)
			sub_417530((int)i, 256);
	}
	nox_common_gameFlags_unset_40A540(0x4000000);
}

//----- (0040AA00) --------------------------------------------------------
BOOL sub_40AA00() {
	return 20 * *(_DWORD*)&byte_5D4594[2649704] <
	       (unsigned int)(*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)&byte_5D4594[3520]);
}

//----- (0040AA20) --------------------------------------------------------
int sub_40AA20() { return *(_DWORD*)&byte_5D4594[3536]; }

//----- (0040AA30) --------------------------------------------------------
int __cdecl sub_40AA30(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[3536] = a1;
	return result;
}

//----- (0040AA40) --------------------------------------------------------
int sub_40AA40() { return *(_DWORD*)&byte_5D4594[3476]; }

//----- (0040AA50) --------------------------------------------------------
int sub_40AA50() { return *(_DWORD*)&byte_5D4594[1392]; }

//----- (0040AA60) --------------------------------------------------------
int __cdecl sub_40AA60(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[3508] = a1;
	return result;
}

//----- (0040AA70) --------------------------------------------------------
int __cdecl sub_40AA70(int a1) {
	char* v1;   // edi
	int result; // eax
	int v3;     // eax
	int v4;     // esi
	int v5;     // ebx
	char* v6;   // eax

	v1 = sub_416640();
	if (!a1)
		goto LABEL_31;
	if (nox_common_gameFlags_check_40A5C0(4096))
		return sub_40A770() < 6;
	v3 = *(_DWORD*)(a1 + 3680);
	if (v3 & 0x100 && !*(_DWORD*)&byte_5D4594[3508])
		return 0;
	if (!sub_40A740() && !nox_common_gameFlags_check_40A5C0(0x8000))
		goto LABEL_31;
	result = *(_DWORD*)(a1 + 2068);
	if (!result)
		return result;
	if (sub_418AE0(*(_DWORD*)(a1 + 2068)))
		goto LABEL_31;
	v4 = (unsigned __int8)v1[52];
	if ((nox_common_gameFlags_check_40A5C0(96) || nox_common_gameFlags_check_40A5C0(16) && sub_417DA0(4)) && v4 > 2)
		v4 = 2;
	if ((unsigned __int8)sub_417DE0() >= v4)
		return 0;
	if (nox_common_gameFlags_check_40A5C0(96)) {
		v5 = (unsigned __int8)sub_417DE0();
		if (v5 >= sub_417DC0())
			return 0;
	}
LABEL_31:
	if (nox_common_gameFlags_check_40A5C0(128))
		goto LABEL_26;
	if (!nox_common_gameFlags_check_40A5C0(1024))
		goto LABEL_26;
	v6 = sub_416EA0();
	if (!v6)
		goto LABEL_26;
	while (*((int*)v6 + 535) <= 0) {
		v6 = sub_416EE0((int)v6);
		if (!v6)
			goto LABEL_26;
	}
	if (sub_40AA00())
		result = 0;
	else
	LABEL_26:
		result = 1;
	return result;
}

//----- (0040ABD0) --------------------------------------------------------
BOOL sub_40ABD0() {
	struct _stat v1; // [esp+0h] [ebp-24h]

	return _stat((LPCSTR)&byte_587000[5160], (int)&v1) == 0;
}

//----- (0040AD10) --------------------------------------------------------
unsigned int __cdecl sub_40AD10(unsigned int* a1, int a2, int a3) {
	unsigned int v3;     // ecx
	int v4;              // edx
	unsigned int v5;     // ecx
	unsigned int v6;     // esi
	unsigned int result; // eax
	unsigned int v8;     // edx

	if (!a3) {
		v3 = *a1;
		v4 = a2;
		goto LABEL_8;
	}
	if (a3 != 1) {
		if (a3 != 2)
			goto LABEL_9;
		v3 = a1[3];
		v4 = a2;
		goto LABEL_8;
	}
	v4 = a2;
	v3 = a1[2];
LABEL_8:
	a1[2] = v4 + v3;
LABEL_9:
	v5 = a1[2];
	v6 = *a1;
	if (v5 >= *a1) {
		v8 = a1[3];
		if (v5 > v8)
			a1[2] = v8;
		result = a1[2] - v6;
	} else {
		a1[2] = v6;
		result = 0;
	}
	return result;
}

//----- (0040AD60) --------------------------------------------------------
unsigned int __cdecl sub_40AD60(char* a1, int a2, int a3, _DWORD* a4) {
	unsigned int result; // eax
	char v5[8];          // [esp+4h] [ebp-8h]

	if (((unsigned __int8)a4[2] - (unsigned __int8)*a4) & 7)
		nox_memfile_read(&v5, 8 - (((unsigned __int8)a4[2] - (unsigned __int8)*a4) & 7), 1, (int)a4);
	result = nox_memfile_read(&v5, 8u, 1, (int)a4);
	if (result == 1)
		qmemcpy(a1, &v5, a3 * a2);
	return result;
}

//----- (0040ADD0) --------------------------------------------------------
signed int __cdecl sub_40ADD0_fread(char* buf, size_t size, size_t count, FILE* file) {

	int left = count * size;
	if (*(_DWORD*)&byte_5D4594[3612])
		return fread(buf, size, count, file);
	*(_DWORD*)&byte_5D4594[3612] = 1;
	if (left == 0) {
		*(_DWORD*)&byte_5D4594[3612] = 0;
		return 0;
	}
	unsigned int total = 0;
	int result;
	while (1) {
		sub_4312C0();
		size_t n = left;
		if (left > 204800)
			n = 204800;
		result = fread(buf, 1, n, file);
		if (result < 0)
			break;
		total += result;
		if (result == n) {
			left -= result;
			buf += result;
			if (left > 0)
				continue;
		}
		result = total / size;
		break;
	}
	*(_DWORD*)&byte_5D4594[3612] = 0;
	return result;
}

//----- (0040AE90) --------------------------------------------------------
int __cdecl sub_40AE90(const void* a1, const void* a2) {
	return _strcmpi(*((const char**)a1 + 1), *((const char**)a2 + 1));
}

//----- (0040AEB0) --------------------------------------------------------
int __cdecl sub_40AEB0(const void* a1, const void* a2) { return _strcmpi((const char*)a1, *((const char**)a2 + 1)); }

//----- (0040AED0) --------------------------------------------------------
void sub_40AED0() {
	if (dword_5d4594_3616) {
		return;
	}
	_DWORD* v0 = nox_calloc(1023, 8);
	dword_5d4594_3616 = v0;
	for (int i = 0; i < 1023; i++) {
		v0[2 * i + 0] = i;
		v0[2 * i + 1] = (_DWORD)table_5184[i];
	}
	qsort(*(void**)&dword_5d4594_3616, 1023, 8, sub_40AE90);
}

//----- (0040AF30) --------------------------------------------------------
void sub_40AF30() {
	if (dword_5d4594_3616) {
		free(*(LPVOID*)&dword_5d4594_3616);
		dword_5d4594_3616 = 0;
	}
}

//----- (0040AF50) --------------------------------------------------------
int __cdecl sub_40AF50(void* a1) {
	int* v1;    // eax
	int result; // eax

	v1 = (int*)bsearch(a1, *(const void**)&dword_5d4594_3616, 0x3FFu, 8u, sub_40AEB0);
	if (v1)
		result = *v1;
	else
		result = 0;
	return result;
}

//----- (0040AF80) --------------------------------------------------------
const char* __cdecl sub_40AF80(int a1) { return table_5184[a1]; }

//----- (0040AF90) --------------------------------------------------------
void __cdecl sub_40AF90(int a1, int a2, char a3, int a4, _BYTE* a5, unsigned int a6) {
	char* v6;            // eax
	char* v7;            // edi
	char* v8;            // eax
	int v9;              // eax
	CHAR FileName[1024]; // [esp+4h] [ebp-400h]

	switch (a3) {
	case 1:
		sub_446520(1, a5, a6);
		break;
	case 2:
		sub_41C8F0(a5, a6);
		if (nox_common_gameFlags_check_40A5C0(4096)) {
			if (sub_4460B0())
				sub_446140();
			else
				sub_41D170();
		} else if (sub_446030() && sub_446090()) {
			sub_43DDD0(0);
			sub_43DE60();
			sub_446060();
		}
		break;
	case 3:
		v6 = sub_409E10();
		nox_sprintf(FileName, "%s\\Save\\_temp_.dat", v6);
		if (sub_41CD70(FileName, a5, a6)) {
			if (sub_4D6F50() && a1 == 31) {
				sub_4DCEE0(FileName);
			} else {
				v7 = sub_41A2E0(FileName, a1);
				if (nox_common_gameFlags_check_40A5C0(4096)) {
					if (v7) {
						v8 = sub_417090(a1);
						if (v8) {
							v9 = *((_DWORD*)v8 + 514);
							if (v9)
								*(_DWORD*)(*(_DWORD*)(v9 + 748) + 552) = 0;
						}
					} else {
						sub_4DEAB0(a1, 4);
					}
				}
				DeleteFileA(FileName);
			}
		} else if (nox_common_gameFlags_check_40A5C0(4096) && a1 != 31) {
			sub_4DEAB0(a1, 4);
		}
		break;
	default:
		return;
	}
}

//----- (0040B170) --------------------------------------------------------
int __cdecl sub_40B170(int a1) {
	int v1;     // ecx
	int result; // eax

	v1 = a1;
	if (a1 >= 0) {
		if (a1 > 256)
			v1 = 256;
	} else {
		v1 = 16;
	}
	dword_5d4594_3624 = v1;
	dword_5d4594_3620 = nox_malloc(168 * v1);
	result = dword_5d4594_3624;
	LOBYTE(a1) = 0;
	if (dword_5d4594_3624 > 0) {
		LOBYTE(result) = 0;
		do {
			sub_40B1F0(result);
			LOBYTE(a1) = a1 + 1;
			result = a1;
		} while ((int)(unsigned __int8)a1 < *(int*)&dword_5d4594_3624);
	}
	return result;
}

//----- (0040B1F0) --------------------------------------------------------
char* __cdecl sub_40B1F0(unsigned __int8 a1) {
	char* result; // eax

	result = (char*)(dword_5d4594_3620 + 168 * a1);
	result[4] = 0;
	result[5] = a1;
	*((_DWORD*)result + 4) = 0;
	*((_DWORD*)result + 3) = 0;
	result[24] = 0;
	*((_DWORD*)result + 40) = 0;
	*((_DWORD*)result + 41) = 0;
	*((_DWORD*)result + 5) = 0;
	*((_DWORD*)result + 38) = 0;
	*((_DWORD*)result + 2) = 1;
	*((_DWORD*)result + 39) = 0;
	return result;
}

//----- (0040B250) --------------------------------------------------------
void __cdecl sub_40B250(int a1, unsigned __int8 a2, unsigned __int16 a3, const void* a4, size_t a5) {
	int v5;                // ebp
	int v6;                // eax
	_DWORD* v7;            // ebx
	void* v8;              // eax
	int v9;                // eax
	int v10;               // eax
	unsigned __int16* v11; // ebx
	unsigned __int16* v12; // eax
	int v13;               // edx
	int v14;               // eax
	int v15;               // eax
	int v16;               // eax
	int v17;               // ecx
	int v18;               // edx
	size_t v19;            // [esp+24h] [ebp+14h]

	if (a4) {
		if (a5) {
			if ((int)a2 < *(int*)&dword_5d4594_3624) {
				v5 = dword_5d4594_3620 + 168 * a2;
				if (*(_DWORD*)(v5 + 16)) {
					*(_DWORD*)(v5 + 156) = *(_DWORD*)&byte_5D4594[2598000];
					if (a3 == *(_DWORD*)(v5 + 8)) {
						qmemcpy((void*)(*(_DWORD*)(v5 + 12) + *(_DWORD*)(v5 + 20)), a4, a5);
						v6 = *(_DWORD*)(v5 + 8) + 1;
						*(_DWORD*)(v5 + 12) += a5;
						*(_DWORD*)(v5 + 8) = v6;
					} else {
						v7 = nox_malloc(0x1Cu);
						if (v7) {
							v8 = nox_malloc(a5);
							v7[1] = v8;
							if (v8) {
								qmemcpy(v8, a4, a5);
								*(_WORD*)v7 = a3;
								*((_WORD*)v7 + 4) = a5;
								v7[5] = 0;
								v7[6] = *(_DWORD*)(v5 + 164);
								v9 = *(_DWORD*)(v5 + 164);
								if (v9)
									*(_DWORD*)(v9 + 20) = v7;
								v10 = *(_DWORD*)(v5 + 160);
								*(_DWORD*)(v5 + 164) = v7;
								if (!v10)
									*(_DWORD*)(v5 + 160) = v7;
							}
						}
					}
					v11 = *(unsigned __int16**)(v5 + 160);
					if (v11) {
						do {
							v12 = (unsigned __int16*)*((_DWORD*)v11 + 5);
							v19 = *((_DWORD*)v11 + 5);
							if (*(_DWORD*)(v5 + 8) == *v11) {
								qmemcpy(
								    (void*)(*(_DWORD*)(v5 + 12) + *(_DWORD*)(v5 + 20)),
								    *((const void**)v11 + 1), (__int16)v11[4]);
								v13 = *(_DWORD*)(v5 + 8) + 1;
								*(_DWORD*)(v5 + 12) += (__int16)v11[4];
								*(_DWORD*)(v5 + 8) = v13;
								v14 = *((_DWORD*)v11 + 6);
								if (v14)
									*(_DWORD*)(v14 + 20) = *((_DWORD*)v11 + 5);
								else
									*(_DWORD*)(v5 + 160) = *((_DWORD*)v11 + 5);
								v15 = *((_DWORD*)v11 + 5);
								if (v15)
									*(_DWORD*)(v15 + 24) = *((_DWORD*)v11 + 6);
								else
									*(_DWORD*)(v5 + 164) = *((_DWORD*)v11 + 6);
								free(*((LPVOID*)v11 + 1));
								free(v11);
								v12 = (unsigned __int16*)v19;
							}
							v11 = v12;
						} while (v12);
					}
					v17 = *(_DWORD*)(v5 + 16);
					v16 = *(_DWORD*)(v5 + 12);
					*(float*)(v5 + 152) = (double)*(unsigned int*)(v5 + 12) / (double)v17 * 100.0;
					if (v16 == v17) {
						sub_40B4B0(*(_DWORD*)v5, *(_BYTE*)(v5 + 5));
						v18 = *(_DWORD*)(v5 + 20);
						LOBYTE(v18) = *(_BYTE*)(v5 + 5);
						sub_40AF90(a1 - 1, v18, *(_BYTE*)(v5 + 4), v5 + 24, *(_BYTE**)(v5 + 20),
							   *(_DWORD*)(v5 + 16));
						if (byte_5D4594[3628])
							--byte_5D4594[3628];
						free(*(LPVOID*)(v5 + 20));
						sub_40B4E0(a2);
						sub_40B1F0(a2);
					}
				}
			}
		}
	}
}

//----- (0040B4B0) --------------------------------------------------------
int __cdecl sub_40B4B0(unsigned int a1, char a2) {
	char v4[3]; // [esp+0h] [ebp-4h]

	v4[0] = -62;
	v4[1] = 4;
	v4[2] = a2;
	return sub_552640(a1, v4, 3, 3);
}

//----- (0040B4E0) --------------------------------------------------------
int __cdecl sub_40B4E0(unsigned __int8 a1) {
	int result; // eax
	int v2;     // esi
	int v3;     // edi

	result = 21 * a1;
	v2 = *(_DWORD*)(dword_5d4594_3620 + 168 * a1 + 160);
	if (v2) {
		do {
			v3 = *(_DWORD*)(v2 + 20);
			free(*(LPVOID*)(v2 + 4));
			free((LPVOID)v2);
			v2 = v3;
		} while (v3);
	}
	return result;
}

//----- (0040B530) --------------------------------------------------------
char* __cdecl sub_40B530(unsigned __int8 a1, char a2) {
	char* result; // eax

	result = (char*)(dword_5d4594_3620 + 168 * a1);
	if (*((_DWORD*)result + 4)) {
		sub_40B590(*(_DWORD*)result, result[5], a2);
		if (byte_5D4594[3628])
			--byte_5D4594[3628];
		sub_40B4E0(a1);
		result = sub_40B1F0(a1);
	}
	return result;
}

//----- (0040B590) --------------------------------------------------------
int __cdecl sub_40B590(unsigned int a1, char a2, char a3) {
	char v4[4]; // [esp+0h] [ebp-4h]

	v4[2] = a2;
	v4[0] = -62;
	v4[1] = 6;
	v4[3] = a3;
	return sub_552640(a1, v4, 4, 3);
}

//----- (0040B5D0) --------------------------------------------------------
int __cdecl sub_40B5D0(unsigned int a1, char a2, const char* a3, size_t a4, char a5) {
	size_t v5; // esi
	char* v6;  // eax
	char* v7;  // ebx
	int v9;    // [esp+8h] [ebp-4h]

	v5 = a4;
	if (!a4)
		return 0;
	v6 = sub_40B6D0(&v9);
	v7 = v6;
	if (!v6)
		return 0;
	*(_DWORD*)v6 = a1;
	v6[4] = a2;
	if (*a3) {
		strcpy(v6 + 24, a3);
		v5 = a4;
	}
	*((_DWORD*)v6 + 4) = v5;
	v6[5] = v9;
	*((_DWORD*)v6 + 5) = nox_calloc(v5, 1u);
	*((_DWORD*)v7 + 39) = *(_DWORD*)&byte_5D4594[2598000];
	++byte_5D4594[3628];
	sub_40B690(a1, v9, a5);
	return 1;
}

//----- (0040B690) --------------------------------------------------------
int __cdecl sub_40B690(unsigned int a1, char a2, char a3) {
	char v4[4]; // [esp+0h] [ebp-4h]

	v4[2] = a2;
	v4[0] = -62;
	v4[1] = 1;
	v4[3] = a3;
	return sub_552640(a1, v4, 4, 3);
}

//----- (0040B6D0) --------------------------------------------------------
char* __cdecl sub_40B6D0(_BYTE* a1) {
	int v1;       // eax
	_DWORD* v2;   // ecx
	char* result; // eax

	v1 = 0;
	if (*(int*)&dword_5d4594_3624 <= 0) {
	LABEL_5:
		result = 0;
		*a1 = 0;
	} else {
		v2 = (_DWORD*)(dword_5d4594_3620 + 16);
		while (*v2) {
			++v1;
			v2 += 42;
			if (v1 >= *(int*)&dword_5d4594_3624)
				goto LABEL_5;
		}
		*a1 = v1;
		result = (char*)(dword_5d4594_3620 + 168 * v1);
	}
	return result;
}

//----- (0040B720) --------------------------------------------------------
char* __cdecl sub_40B720(int a1, unsigned __int8 a2) {
	sub_40B4E0(a2);
	return sub_40B1F0(a2);
}

//----- (0040B740) --------------------------------------------------------
void sub_40B740() {
	unsigned __int8 v0; // al
	unsigned __int8 v2; // [esp+0h] [ebp-4h]

	v2 = 0;
	if (dword_5d4594_3624 > 0) {
		v0 = 0;
		do {
			sub_40B4E0(v0);
			v0 = ++v2;
		} while ((int)v2 < *(int*)&dword_5d4594_3624);
	}
	free(*(LPVOID*)&dword_5d4594_3620);
}

//----- (0040B790) --------------------------------------------------------
int sub_40B790() {
	int result;         // eax
	unsigned __int8 v1; // dl
	int v2;             // ecx
	int v3;             // eax
	unsigned __int8 v4; // [esp+0h] [ebp-4h]

	result = dword_5d4594_3624;
	v4 = 0;
	if (dword_5d4594_3624 > 0) {
		v1 = 0;
		v2 = 0;
		do {
			v3 = dword_5d4594_3620 + 168 * v2;
			if (*(_DWORD*)(v3 + 16)) {
				if (*(_DWORD*)&byte_5D4594[2598000] > (unsigned int)(*(_DWORD*)(v3 + 156) + 900))
					sub_40B530(v1, 3);
			}
			result = dword_5d4594_3624;
			v1 = ++v4;
			v2 = v4;
		} while ((int)v4 < *(int*)&dword_5d4594_3624);
	}
	return result;
}

//----- (0040B810) --------------------------------------------------------
void __cdecl sub_40B810(int a1, int a2, int a3) {
	sub_40AF90(31, 0, a1, (int)&byte_5D4594[4664], (_BYTE*)a2, a3);
	sub_40B850(0, a1);
}

//----- (0040B850) --------------------------------------------------------
void __cdecl sub_40B850(int a1, char a2) {
	if (a2 == 2 && sub_446030()) {
		sub_446070();
		if (sub_446090()) {
			sub_43DDD0(0);
			sub_43DE60();
			sub_446060();
		}
	}
}

//----- (0040B890) --------------------------------------------------------
void* __cdecl sub_40B890(int a1) {
	void* result; // eax
	int v2;       // esi
	int v3;       // edi

	if (a1 >= 0) {
		*(_WORD*)&byte_5D4594[4660] = 256;
		if (a1 <= 256)
			*(_WORD*)&byte_5D4594[4660] = a1;
	} else {
		*(_WORD*)&byte_5D4594[4660] = 16;
	}
	result = nox_malloc(160 * *(unsigned __int16*)&byte_5D4594[4660]);
	v2 = 0;
	dword_5d4594_3632 = result;
	if (*(_WORD*)&byte_5D4594[4660]) {
		v3 = 0;
		do {
			sub_40B930(v3 + dword_5d4594_3632);
			++v2;
			result = (void*)*(unsigned __int16*)&byte_5D4594[4660];
			v3 += 160;
		} while (v2 < *(unsigned __int16*)&byte_5D4594[4660]);
		*(_WORD*)&byte_5D4594[4662] = 0;
	} else {
		*(_WORD*)&byte_5D4594[4662] = 0;
	}
	return result;
}

//----- (0040B930) --------------------------------------------------------
int __cdecl sub_40B930(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)a1 = 0;
	*(_BYTE*)(a1 + 4) = 0;
	*(_WORD*)(a1 + 6) = 0;
	*(_DWORD*)(a1 + 8) = 0;
	*(_DWORD*)(a1 + 12) = 1;
	*(_WORD*)(a1 + 20) = 0;
	*(_BYTE*)(a1 + 22) = 0;
	*(_BYTE*)(a1 + 23) = 0;
	*(_DWORD*)(a1 + 16) = 0;
	*(_DWORD*)(a1 + 152) = 0;
	*(_DWORD*)(a1 + 156) = 0;
	return result;
}

//----- (0040B970) --------------------------------------------------------
void sub_40B970() {
	int v0; // ebp
	int v1; // edi
	int v2; // esi
	int v3; // ebx
	int v4; // eax
	int v5; // ecx
	int v6; // eax
	int v7; // [esp+4h] [ebp-4h]

	v0 = 0;
	if (*(_WORD*)&byte_5D4594[4662]) {
		v7 = 0;
		if (*(_WORD*)&byte_5D4594[4660] > 0u) {
			do {
				v1 = dword_5d4594_3632 + v0;
				if (*(_WORD*)(dword_5d4594_3632 + v0 + 6) == 2) {
					v2 = *(_DWORD*)(v1 + 152);
					v3 = 0;
					if (v2) {
						while (v3 < 2) {
							v4 = *(_DWORD*)(v2 + 12);
							if (v4) {
								v5 = *(_DWORD*)&byte_5D4594[2598000];
								if ((unsigned int)(v4 + 90) <
								    *(int*)&byte_5D4594[2598000]) {
									if (*(_WORD*)(v2 + 16) >= 20) {
										if (*(_WORD*)(v1 + 6) == 2) {
											LOBYTE(v5) = *(_BYTE*)(v1 + 4);
											sub_40BB20(*(_DWORD*)v1, v5, 2);
											break;
										}
									} else {
										sub_40BA90(
										    *(_DWORD*)v1, *(_BYTE*)(v1 + 4),
										    *(_WORD*)v2, *(_WORD*)(v2 + 8),
										    *(const void**)(v2 + 4));
										v6 = *(_DWORD*)&byte_5D4594[2598000];
										++*(_WORD*)(v2 + 16);
										*(_DWORD*)(v2 + 12) = v6;
									}
								}
							} else {
								sub_40BA90(*(_DWORD*)v1, *(_BYTE*)(v1 + 4), *(_WORD*)v2,
									   *(_WORD*)(v2 + 8), *(const void**)(v2 + 4));
								*(_DWORD*)(v2 + 12) = *(_DWORD*)&byte_5D4594[2598000];
								++*(_DWORD*)(v1 + 12);
							}
							v2 = *(_DWORD*)(v2 + 20);
							++v3;
							if (!v2)
								break;
						}
					}
				}
				v0 += 160;
				++v7;
			} while (v7 < *(unsigned __int16*)&byte_5D4594[4660]);
		}
	}
}

//----- (0040BA90) --------------------------------------------------------
int __cdecl sub_40BA90(unsigned int a1, char a2, __int16 a3, __int16 a4, const void* a5) {
	int v6; // [esp+8h] [ebp-8h]
	int v7; // [esp+Ch] [ebp-4h]

	BYTE2(v6) = a2;
	HIWORD(v7) = a4;
	LOWORD(v7) = a3;
	LOWORD(v6) = 706;
	*(_DWORD*)&byte_5D4594[3640] = v7;
	*(_DWORD*)&byte_5D4594[3636] = v6;
	qmemcpy(&byte_5D4594[3644], a5, a4);
	sub_552640(a1, &byte_5D4594[3636], a4 + 8, 0);
	return sub_5528B0(a1, 1);
}
// 40BACC: variable 'v6' is possibly undefined

//----- (0040BB20) --------------------------------------------------------
char* __cdecl sub_40BB20(unsigned int a1, int a2, char a3) {
	char v3;      // bl
	char* result; // eax
	char* v5;     // edi
	int v6;       // esi
	int v7;       // ebx

	v3 = a2;
	result = sub_40BC10(a1, a2);
	v5 = result;
	if (result) {
		LOWORD(a2) = 1474;
		BYTE2(a2) = v3;
		HIBYTE(a2) = a3;
		sub_552640(a1, &a2, 4, 3);
		sub_40BBC0(*(_DWORD*)v5, v5[22]);
		if (*(_WORD*)&byte_5D4594[4662])
			--*(_WORD*)&byte_5D4594[4662];
		v6 = *((_DWORD*)v5 + 38);
		if (v6) {
			do {
				v7 = *(_DWORD*)(v6 + 20);
				free(*(LPVOID*)(v6 + 4));
				free((LPVOID)v6);
				v6 = v7;
			} while (v7);
		}
		result = (char*)sub_40B930((int)v5);
	}
	return result;
}

//----- (0040BBC0) --------------------------------------------------------
void __cdecl sub_40BBC0(int a1, char a2) {
	if (a2 == 2) {
		if (sub_446030()) {
			sub_446070();
			if (sub_446090()) {
				sub_43DDD0(0);
				sub_43DE60();
				sub_446060();
			}
		}
	} else if (a2 == 3) {
		sub_43DDD0(0);
		sub_43DE60();
	}
}

//----- (0040BC10) --------------------------------------------------------
char* __cdecl sub_40BC10(int a1, char a2) {
	int v2; // ecx
	int i;  // eax

	v2 = 0;
	if ((int)*(unsigned __int16*)&byte_5D4594[4660] <= 0)
		return 0;
	for (i = dword_5d4594_3632; *(_DWORD*)i != a1 || *(_BYTE*)(i + 4) != a2; i += 160) {
		if (++v2 >= *(unsigned __int16*)&byte_5D4594[4660])
			return 0;
	}
	return (char*)(dword_5d4594_3632 + 160 * v2);
}

//----- (0040BC60) --------------------------------------------------------
int __cdecl sub_40BC60(int a1, int a2, const char* a3, int a4, int a5, int a6) {
	char* v6;         // ebx
	int v7;           // esi
	int v8;           // eax
	_WORD* v10;       // eax
	_WORD* v11;       // ebp
	__int16 v12;      // ax
	char* v13;        // eax
	unsigned int v14; // ecx
	int v15;          // eax
	int v16;          // edx
	int v17;          // esi
	int v18;          // eax
	unsigned int v19; // [esp+10h] [ebp-Ch]
	int v20;          // [esp+18h] [ebp-4h]
	int v21;          // [esp+20h] [ebp+4h]
	int v22;          // [esp+2Ch] [ebp+10h]
	char* v23;        // [esp+34h] [ebp+18h]

	v6 = sub_40BF10(&v20);
	if (!v6)
		return 0;
	v7 = a5;
	if (!a5 || !a4)
		return 0;
	if (!nox_common_gameFlags_check_40A5C0(1)) {
		v8 = sub_43C750();
		goto LABEL_12;
	}
	if (!nox_common_gameFlags_check_40A5C0(2))
		return 0;
	if (!a6) {
		sub_40B810(a2, a4, a5);
		return 1;
	}
	if (a1 == 31) {
		sub_40B810(a2, a4, a5);
		return 1;
	}
	v8 = a1 + 1;
LABEL_12:
	++*(_WORD*)&byte_5D4594[4662];
	v19 = v8;
	v21 = a5;
	v23 = (char*)a4;
	v22 = 0;
	if ((int)(((unsigned int)(a5 - 1) >> 9) + 1) > 0) {
		while (1) {
			v10 = nox_malloc(0x1Cu);
			v11 = v10;
			if (!v10)
				return 0;
			*v10 = v22 + 1;
			v12 = 512;
			if (v7 <= 512)
				v12 = v7;
			v11[4] = v12;
			v13 = (char*)nox_malloc(v12);
			v14 = (__int16)v11[4];
			*((_DWORD*)v11 + 3) = 0;
			v11[8] = 0;
			*((_DWORD*)v11 + 1) = v13;
			qmemcpy(v13, v23, v14);
			v15 = (__int16)v11[4];
			v16 = v21 - v15;
			v17 = (int)&v23[v15];
			*((_DWORD*)v11 + 6) = *((_DWORD*)v6 + 39);
			*((_DWORD*)v11 + 5) = 0;
			v18 = *((_DWORD*)v6 + 39);
			v23 = (char*)v17;
			v21 = v16;
			if (v18)
				*(_DWORD*)(v18 + 20) = v11;
			else
				*((_DWORD*)v6 + 38) = v11;
			*((_DWORD*)v6 + 39) = v11;
			if (++v22 >= (int)(((unsigned int)(a5 - 1) >> 9) + 1)) {
				v7 = a5;
				break;
			}
			v7 = v16;
		}
	}
	*((_DWORD*)v6 + 4) = v22;
	v6[4] = 0;
	*((_DWORD*)v6 + 3) = 1;
	*((_WORD*)v6 + 10) = 512;
	*((_DWORD*)v6 + 2) = v7;
	*(_DWORD*)v6 = v19;
	*((_WORD*)v6 + 3) = 1;
	if (a3) {
		strcpy(v6 + 23, a3);
		v7 = a5;
	}
	v6[22] = a2;
	sub_40BE80(v19, a2, a3, v7, v20);
	return 1;
}

//----- (0040BE80) --------------------------------------------------------
int __cdecl sub_40BE80(unsigned int a1, char a2, const char* a3, int a4, char a5) {
	char v6[140]; // [esp+4h] [ebp-8Ch]

	v6[0] = -62;
	v6[1] = 0;
	v6[2] = a2;
	*(_DWORD*)&v6[4] = a4;
	if (a3)
		strcpy(&v6[8], a3);
	else
		v6[8] = 0;
	v6[136] = a5;
	return sub_552640(a1, v6, 140, 3);
}

//----- (0040BF10) --------------------------------------------------------
char* __cdecl sub_40BF10(_BYTE* a1) {
	int v1;    // ecx
	_DWORD* i; // eax

	v1 = 0;
	if ((int)*(unsigned __int16*)&byte_5D4594[4660] <= 0)
		return 0;
	for (i = (_DWORD*)(dword_5d4594_3632 + 8); *((_WORD*)i - 1) || *i; i += 40) {
		if (++v1 >= *(unsigned __int16*)&byte_5D4594[4660])
			return 0;
	}
	*a1 = v1;
	return (char*)(dword_5d4594_3632 + 160 * v1);
}

//----- (0040BF60) --------------------------------------------------------
char* __cdecl sub_40BF60(int a1, char a2, int a3) {
	char* result;         // eax
	unsigned __int16* v4; // esi
	int v5;               // ecx
	int v6;               // ecx

	result = sub_40BC10(a1, a2);
	if (result) {
		v4 = (unsigned __int16*)*((_DWORD*)result + 38);
		if (v4) {
			while (*v4 != a3) {
				v4 = (unsigned __int16*)*((_DWORD*)v4 + 5);
				if (!v4)
					return result;
			}
			v5 = *((_DWORD*)v4 + 5);
			if (v5)
				*(_DWORD*)(v5 + 24) = *((_DWORD*)v4 + 6);
			else
				*((_DWORD*)result + 39) = *((_DWORD*)v4 + 6);
			v6 = *((_DWORD*)v4 + 6);
			if (v6)
				*(_DWORD*)(v6 + 20) = *((_DWORD*)v4 + 5);
			else
				*((_DWORD*)result + 38) = *((_DWORD*)v4 + 5);
			free(*((LPVOID*)v4 + 1));
			free(v4);
		}
	}
	return result;
}

//----- (0040BFF0) --------------------------------------------------------
char* __cdecl sub_40BFF0(int a1, char a2, char* a3) {
	char* result; // eax

	result = a3;
	if ((unsigned __int8)a3 < (unsigned int)*(_WORD*)&byte_5D4594[4660]) {
		result = (char*)(dword_5d4594_3632 + 160 * (unsigned __int8)a3);
		result[4] = a2;
		*((_WORD*)result + 3) = 2;
	}
	return result;
}

//----- (0040C030) --------------------------------------------------------
char* __cdecl sub_40C030(int a1, char a2) {
	char* result; // eax
	char* v3;     // esi

	result = sub_40BC10(a1, a2);
	v3 = result;
	if (result) {
		sub_40B850(a1, result[22]);
		--*(_WORD*)&byte_5D4594[4662];
		result = (char*)sub_40B930((int)v3);
	}
	return result;
}

//----- (0040C070) --------------------------------------------------------
char* __cdecl sub_40C070(int a1, int a2, char a3) {
	char* result; // eax
	char* v4;     // ebx
	int v5;       // esi
	int v6;       // edi

	result = sub_40BC10(a1, a3);
	v4 = result;
	if (result) {
		sub_40BBC0(*(_DWORD*)result, result[22]);
		v5 = *((_DWORD*)v4 + 38);
		if (v5) {
			do {
				v6 = *(_DWORD*)(v5 + 20);
				free(*(LPVOID*)(v5 + 4));
				free((LPVOID)v5);
				v5 = v6;
			} while (v6);
		}
		result = (char*)sub_40B930((int)v4);
	}
	return result;
}

//----- (0040C0D0) --------------------------------------------------------
void sub_40C0D0() { free(*(LPVOID*)&dword_5d4594_3632); }

//----- (0040C0E0) --------------------------------------------------------
void __cdecl sub_40C0E0(int a1) {
	int v1; // edi
	int v2; // eax
	int v3; // esi

	v1 = 0;
	if (*(_WORD*)&byte_5D4594[4660]) {
		v2 = dword_5d4594_3632;
		v3 = 0;
		do {
			if (*(_WORD*)(v3 + v2 + 6) == 2 && *(_DWORD*)(v3 + v2) == a1) {
				sub_40BB20(*(_DWORD*)(v3 + v2), *(_BYTE*)(v3 + v2 + 4), 1);
				v2 = dword_5d4594_3632;
			}
			++v1;
			v3 += 160;
		} while (v1 < *(unsigned __int16*)&byte_5D4594[4660]);
	}
}

//----- (0040C140) --------------------------------------------------------
int __stdcall sub_40C140(int a1, int a2, _DWORD* a3) {
	int v3;     // eax
	int result; // eax
	int v5;     // eax
	int v6;     // eax

	if (a2 == -2147221396 || a2) {
		if (sub_41E300(11)) {
			dword_5d4594_2660652 = a2;
			v5 = sub_41E2F0();
			sub_41DA70(v5, 5);
			v6 = sub_41E2F0();
			sub_41DA70(v6, 9);
		}
		result = 0;
	} else {
		sub_41E4D0(a3);
		v3 = sub_41E2F0();
		sub_41DA70(v3, 2);
		result = 0;
	}
	return result;
}

//----- (0040C1B0) --------------------------------------------------------
int __stdcall sub_40C1B0(int a1, int a2, int a3) {
	int v3; // eax

	if (a2 == -2147221402 && (sub_41E2F0() == 7 || sub_41E2F0() == 5)) {
		dword_5d4594_2660652 = -2147221402;
		v3 = sub_41E2F0();
		sub_41DA70(v3, 5);
	}
	return 0;
}

//----- (0040C1F0) --------------------------------------------------------
int __stdcall sub_40C1F0(int a1, int a2, const void* a3) {
	if (a2 || sub_41E2F0() != 7 || !a3)
		return 0;
	sub_446520(0, a3, strlen((const char*)a3) + 1);
	sub_446D50();
	return 0;
}

//----- (0040C240) --------------------------------------------------------
int __stdcall sub_40C240(int a1, int a2, int a3) {
	if (a2) {
		if (dword_5d4594_528252 && dword_5d4594_528256) {
			sub_41E470();
			return 0;
		}
	} else {
		if (sub_41E2F0() == 7) {
			sub_41ECB0(a3);
			sub_41EBB0(a3);
			sub_447470_wol_chat();
			sub_448640();
		} else if (sub_41E2F0() == 8) {
			sub_416690();
		}
		sub_41F230(0, 1);
		if (dword_5d4594_528252 && dword_5d4594_528256) {
			sub_41E370();
			sub_41E4B0(0);
		}
		*(_DWORD*)&byte_587000[25736] = 0;
	}
	return 0;
}
// 448640: using guessed type int sub_448640(void);

//----- (0040C2E0) --------------------------------------------------------
int __stdcall sub_40C2E0(int a1, int a2, int a3, const char* a4) {
	int result; // eax
	int v5;     // eax
	int v6;     // eax
	int v7;     // eax
	int v8;     // eax
	int v9;     // eax

	if (sub_41E2F0() != 7 && sub_41E2F0() != 8)
		return 0;
	if (a2 <= -2147221390) {
		if (a2 >= -2147221392) {
		LABEL_10:
			dword_5d4594_2660652 = a2;
			v7 = sub_41E2F0();
			sub_41DA70(v7, 5);
			return 0;
		}
		if (a2 != -2147221396) {
			if (a2 != -2147221394)
				return 0;
			goto LABEL_10;
		}
		if (sub_41E300(11)) {
			dword_5d4594_2660652 = -2147221396;
			v5 = sub_41E2F0();
			sub_41DA70(v5, 5);
			v6 = sub_41E2F0();
			sub_41DA70(v6, 9);
			return 0;
		}
		return 0;
	}
	if (a2)
		return 0;
	v8 = *(_DWORD*)a4;
	if ((v8 & 0x8000) == 0) {
	LABEL_15:
		sub_41F230(0, 1);
		sub_41F520(a4);
		return 0;
	}
	sub_41EBB0(a3);
	if (sub_41E2F0() == 7) {
		sub_447470_wol_chat();
		sub_448640();
		goto LABEL_15;
	}
	if (sub_41E2F0() != 8)
		goto LABEL_15;
	qmemcpy(&byte_5D4594[2660012], a4, 0x6Cu);
	if (*((_DWORD*)a4 + 5)) {
		sub_40DB20(*((_DWORD*)a4 + 5));
		result = 1;
	} else {
		if (!(*a4 & 1)) {
			v9 = sub_41E2F0();
			sub_41DA70(v9, 19);
		}
		result = 1;
	}
	return result;
}
// 448640: using guessed type int sub_448640(void);

//----- (0040C420) --------------------------------------------------------
int __stdcall sub_40C420(int a1, int a2, int a3, int* a4) {
	int v4; // eax
	int v6; // eax

	if (sub_41E2F0() == 7 || sub_41E2F0() == 8) {
		if (a2 == -2147220994) {
			dword_5d4594_2660652 = -2147220994;
			v6 = sub_41E2F0();
			sub_41DA70(v6, 5);
		} else if (!a2) {
			sub_41F620((int)a4);
			if (sub_41F9E0((int)a4)) {
				sub_41F4B0();
				if (sub_41E2F0() == 7)
					sub_447590_wol_chat();
				sub_41F230(0, -1);
				sub_41EBB0(0);
			} else {
				sub_41F230(0, -1);
			}
			if (sub_41E2F0() != 7) {
				if (*a4 & 1) {
					v4 = *a4;
					if ((v4 & 0x8000) == 0) {
						sub_40D380();
						return 0;
					}
				}
			}
		}
	}
	return 0;
}

//----- (0040C4E0) --------------------------------------------------------
int __stdcall sub_40C4E0(int a1, int a2, int a3, int a4) { return 0; }

//----- (0040C4F0) --------------------------------------------------------
int __stdcall sub_40C4F0(int a1, int a2, int a3) { return 0; }

//----- (0040C500) --------------------------------------------------------
int __stdcall sub_40C500(int a1, int a2, int a3) { return 0; }

//----- (0040C510) --------------------------------------------------------
int __stdcall sub_40C510(int a1, int a2, int a3) { return 0; }

//----- (0040C520) --------------------------------------------------------
int __stdcall sub_40C520(int a1, int a2, int a3) { return 0; }

//----- (0040C530) --------------------------------------------------------
int __stdcall sub_40C530(int a1, int a2, int a3, _BYTE* a4) {
	if (sub_41E2F0() == 7 && !a2 && !sub_41F9E0(a3)) {
		sub_448650(a4, (wchar_t*)&byte_5D4594[8908]);
		sub_447250((const char*)(a3 + 36), (int)&byte_5D4594[8908], 1, 0);
	}
	return 0;
}

//----- (0040C580) --------------------------------------------------------
int __stdcall sub_40C580(int a1, int a2, int a3, int a4, _BYTE* a5) {
	if (sub_41E2F0() == 7 && !a2) {
		sub_448650(a5, (wchar_t*)&byte_5D4594[8908]);
		sub_447250((const char*)(a4 + 36), (int)&byte_5D4594[8908], 0, 0);
	}
	return 0;
}

//----- (0040C5C0) --------------------------------------------------------
int __stdcall sub_40C5C0(int a1, int a2, int a3, int a4, _BYTE* a5) {
	if (sub_41E2F0() == 7 && !a2) {
		sub_448650(a5, (wchar_t*)&byte_5D4594[8908]);
		sub_4471A0((const char*)(a4 + 36), (int)&byte_5D4594[8908], 0, 0);
	}
	return 0;
}

//----- (0040C600) --------------------------------------------------------
int __stdcall sub_40C600(int a1, int a2, int a3, _BYTE* a4) {
	if (sub_41E2F0() == 7 && !a2 && !sub_41F9E0(a3)) {
		sub_448650(a4, (wchar_t*)&byte_5D4594[8908]);
		sub_4471A0((const char*)(a3 + 36), (int)&byte_5D4594[8908], 1, 0);
	}
	return 0;
}

//----- (0040C650) --------------------------------------------------------
int __stdcall sub_40C650(int a1, int a2, int a3, int a4) { return 0; }

//----- (0040C660) --------------------------------------------------------
int __stdcall sub_40C660(int a1, int a2, int a3, int a4, int a5) { return 0; }

//----- (0040C670) --------------------------------------------------------
int __stdcall sub_40C670(int a1, int a2, int a3, int a4, int a5) {
	if (!a2)
		sub_416670(a5);
	return 0;
}

//----- (0040C690) --------------------------------------------------------
int __stdcall sub_40C690(int a1, int a2, int a3, int a4, int a5) {
	if (sub_41E2F0() == 7 && !a2) {
		sub_41F620(a4);
		if (sub_41F9E0(a4)) {
			sub_41F4B0();
			sub_41F230(0, -1);
			sub_41EBB0(0);
			sub_4474C0_wol_chat(0, a5 + 36);
			return 0;
		}
		sub_4474C0_wol_chat(a4 + 36, a5 + 36);
		sub_41F230(0, -1);
	}
	return 0;
}

//----- (0040C710) --------------------------------------------------------
int __stdcall sub_40C710(int a1, int a2, int a3) { return 0; }

//----- (0040C720) --------------------------------------------------------
int __stdcall sub_40C720(int a1, int a2, _DWORD* a3) {
	if (sub_41E2F0() == 7 || sub_41E2F0() == 8) {
		if (a2) {
			if (a2 <= 262447 || a2 > 262450) {
				sub_4490C0_wol_dialogs(0);
				return 0;
			}
		} else if (sub_41E2F0() == 8) {
			if (*a3 == sub_420100()) {
				sub_4490C0_wol_dialogs((int)a3);
				return 0;
			}
		} else if (!*a3) {
			sub_4490C0_wol_dialogs((int)a3);
			return 0;
		}
		sub_4491B0_wol_dialogs();
	}
	return 0;
}

//----- (0040C7A0) --------------------------------------------------------
int __stdcall sub_40C7A0(int a1, int a2) {
	if (sub_41E2F0() == 7) {
		if (a2) {
			sub_449240_wol_dialogs();
			return 0;
		}
		sub_449200_wol_dialogs();
	}
	return 0;
}

//----- (0040C7D0) --------------------------------------------------------
int __stdcall sub_40C7D0(int a1, int a2, int a3, _BYTE* a4) {
	if (sub_41E2F0() == 7) {
		if (!a2) {
			sub_448650(a4, (wchar_t*)&byte_5D4594[8908]);
			sub_447380((const char*)(a3 + 36), (char*)&byte_5D4594[8908]);
			return 0;
		}
	} else if (sub_43C710()) {
		sub_43D260(a3 + 36, (int)a4);
	}
	return 0;
}

//----- (0040C830) --------------------------------------------------------
int __stdcall sub_40C830(int a1, int a2, int a3) {
	int v3; // eax
	int v4; // eax

	if (sub_41E2F0() == 7 && !a2 && sub_41E300(11)) {
		dword_5d4594_2660652 = 1;
		v3 = sub_41E2F0();
		sub_41DA70(v3, 5);
		v4 = sub_41E2F0();
		sub_41DA70(v4, 9);
	}
	return 0;
}

//----- (0040C880) --------------------------------------------------------
int __stdcall sub_40C880(int a1, int a2, const char* a3, int a4, int a5) {
	int v5; // eax

	if (sub_41E2F0() == 7 && !a2) {
		sub_41F840(a3, a4);
		v5 = sub_41E2F0();
		sub_41DA70(v5, 11);
	}
	return 0;
}

//----- (0040C8C0) --------------------------------------------------------
int __stdcall sub_40C8C0(int a1, int a2, int a3, int a4) {
	if (sub_41E2F0() == 7 && !a2 && a4)
		sub_447540_wol_chat(a3);
	return 0;
}

//----- (0040C8F0) --------------------------------------------------------
int __stdcall sub_40C8F0(int a1, int a2, int a3, int a4) {
	int v5; // eax

	if (sub_41E2F0() == 8 && !a2) {
		dword_5d4594_2660032 = *(_DWORD*)a4;
		strncpy((char*)&byte_5D4594[2660099], (const char*)(a4 + 401), 9u);
		byte_5D4594[2660108] = 0;
		if (*(_DWORD*)&byte_5D4594[10980]) {
			*(_DWORD*)&byte_5D4594[10980] = 0;
			sub_41D5E0();
			return 0;
		}
		v5 = sub_41E2F0();
		sub_41DA70(v5, 19);
	}
	return 0;
}

//----- (0040C960) --------------------------------------------------------
int __stdcall sub_40C960(int a1, int a2, _DWORD* a3) {
	int v3;     // eax
	int v4;     // eax
	__int16 v6; // [esp-8h] [ebp-8h]

	if (sub_41E2F0() == 2 && sub_40E0B0()) {
		if (a2) {
			if (!sub_41E300(11))
				return 0;
			dword_5d4594_2660652 = a2;
			v3 = sub_41E2F0();
			sub_41DA70(v3, 5);
			v6 = 9;
		} else {
			sub_4201B0(a3);
			v6 = 1;
		}
		v4 = sub_41E2F0();
		sub_41DA70(v4, v6);
		return 0;
	}
	return 0;
}

//----- (0040C9D0) --------------------------------------------------------
int __stdcall sub_40C9D0(int a1, int a2, int* a3) {
	int v4; // eax

	if (a2)
		return 0;
	if (sub_41E2F0() != 7) {
		if (*a3 & 1) {
			v4 = *a3;
			if ((v4 & 0x8000) == 0)
				sub_40D380();
		}
		return 0;
	}
	sub_41F620((int)a3);
	if (sub_41F9E0((int)a3)) {
		sub_41EBB0(0);
		sub_447590_wol_chat();
	}
	sub_41F230(0, -1);
	return 0;
}

//----- (0040CA40) --------------------------------------------------------
int __stdcall sub_40CA40(int a1, int a2) { return 0; }

//----- (0040CA50) --------------------------------------------------------
int __stdcall sub_40CA50(int a1, int a2) { return 0; }

//----- (0040CA60) --------------------------------------------------------
BOOL __stdcall sub_40CA60(int a1, int a2, const void* a3) {
	BOOL result; // eax
	int v4;      // eax
	int v5;      // eax
	int v6;      // eax
	int v7;      // eax
	int v8;      // eax

	result = sub_40E0B0();
	if (result) {
		if (a2) {
			if (dword_5d4594_528252 && dword_5d4594_528256) {
				sub_41E470();
				return 0;
			}
			if (sub_41E300(11)) {
				dword_5d4594_2660652 = a2;
				v4 = sub_41E2F0();
				sub_41DA70(v4, 6);
				v5 = sub_41E2F0();
				sub_41DA70(v5, 9);
				return 0;
			}
		} else {
			if (sub_41E2F0() == 5) {
				sub_41FF30(a3);
				sub_41E300(7);
				v6 = sub_41E2F0();
				sub_41DA70(v6, 7);
				sub_4207F0(3);
				v7 = sub_41FC40();
				sub_40DB50(v7 + 1, (int)&a3);
				sub_40D670((int)a3);
				return 0;
			}
			if (sub_41E2F0() == 3) {
				sub_446A90();
				sub_446AD0(sub_447620_wol_chat);
				sub_41FF30(a3);
				v8 = sub_41E2F0();
				sub_41DA70(v8, 7);
				return 0;
			}
			if (dword_5d4594_528252 && dword_5d4594_528256)
				sub_43AA70();
		}
		result = 0;
	}
	return result;
}

//----- (0040CB90) --------------------------------------------------------
int __stdcall sub_40CB90(int a1, int a2, int a3) { return 0; }

//----- (0040CBA0) --------------------------------------------------------
int __stdcall sub_40CBA0(int a1, int a2, int a3) {
	if (sub_41E2F0() == 7 && !a2) {
		nox_swprintf((wchar_t*)&byte_5D4594[8908], L"%S", a3);
		sub_447310(0, (int)&byte_5D4594[8908]);
	}
	return 0;
}

//----- (0040CBE0) --------------------------------------------------------
int __stdcall sub_40CBE0(int a1, int a2) {
	int v2;     // eax
	int v3;     // eax
	int result; // eax

	if (a2 > 262447)
		return 0;
	if (a2 == 262447) {
		if (sub_40CD00()) {
			if (sub_43C710()) {
				sub_44B010();
				sub_40E0A0();
			} else {
				sub_41E300(9);
				sub_41F4B0();
				sub_41EC30();
				sub_446490(0);
				sub_44B000();
				sub_40E0A0();
				sub_43C260();
				sub_44A400();
			}
			return 0;
		}
		if (sub_41E2F0() == 9) {
			sub_40E0A0();
			*(_DWORD*)&byte_5D4594[10988] = 0;
			return 0;
		}
		if (sub_41E2F0() == 3)
			sub_41FDE0();
		*(_DWORD*)&byte_5D4594[10988] = 0;
		return 0;
	}
	switch (a2 + 2147221401) {
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	case 14:
	case 15:
		if (!sub_41E300(11))
			return 0;
		dword_5d4594_2660652 = a2;
		v2 = sub_41E2F0();
		sub_41DA70(v2, 5);
		v3 = sub_41E2F0();
		sub_41DA70(v3, 9);
		result = 0;
		break;
	default:
		return 0;
	}
	return result;
}

//----- (0040CD00) --------------------------------------------------------
int sub_40CD00() {
	int result; // eax

	if (sub_41E2F0() == 2 || sub_41E2F0() == 4 || sub_41E2F0() == 11 || sub_41E2F0() == 5 || sub_41E2F0() == 3 ||
	    (result = 1, *(_DWORD*)&byte_5D4594[10988] == 1)) {
		result = 0;
	}
	return result;
}

//----- (0040CD50) --------------------------------------------------------
int __stdcall sub_40CD50(int a1, int a2, int a3) { return 0; }

//----- (0040CD60) --------------------------------------------------------
int __stdcall sub_40CD60(int a1, int a2, int a3) {
	int v4; // eax

	if (sub_41E2F0() == 7 || sub_41E2F0() == 8) {
		if (a2) {
			if (a2 == 262459) {
				sub_43B0E0(a3);
				return 0;
			}
		} else {
			sub_448640();
			sub_41EFB0(a3);
			v4 = sub_41E2F0();
			sub_41DA70(v4, 10);
		}
	}
	return 0;
}
// 448640: using guessed type int sub_448640(void);

//----- (0040CDC0) --------------------------------------------------------
int __stdcall sub_40CDC0(int a1, int a2, int a3, int a4) {
	int* v4; // esi
	int v5;  // eax
	int v7;  // eax

	if (!a2) {
		v4 = (int*)a4;
		sub_41F6F0(a4);
		if (sub_41E2F0() == 7) {
			v5 = sub_41E2F0();
			sub_41DA70(v5, 11);
			return 0;
		}
		if (sub_41E2F0() == 8 && a4) {
			while (1) {
				v7 = *v4;
				if ((v7 & 0x8000) != 0)
					break;
				v4 = (int*)v4[8];
				if (!v4)
					return 0;
			}
			if (*(_BYTE*)v4 & 1) {
				if (v4[5]) {
					sub_40DB20(v4[5]);
					*(_DWORD*)&byte_5D4594[10980] = 1;
				}
				if (sub_416650())
					sub_40D530((int)v4);
			}
		}
	}
	return 0;
}

//----- (0040CE60) --------------------------------------------------------
int sub_40CE60() {
#ifdef NO_WOLAPI
	return 0;
#else
	int v0;       // esi
	int v1;       // edx
	int result;   // eax
	char* v3;     // [esp+10h] [ebp-8Ch]
	int v4;       // [esp+14h] [ebp-88h]
	int v5;       // [esp+18h] [ebp-84h]
	char v6[128]; // [esp+1Ch] [ebp-80h]

	if (*(_DWORD*)&byte_5D4594[10972] || CoInitialize(0) < 0) {
		if (*(_DWORD*)&byte_5D4594[10972] != 1)
			return 0;
	} else {
		*(_DWORD*)&byte_5D4594[10972] = 1;
	}
	if (*(_DWORD*)&byte_5D4594[10976])
		return 0;
	*(_DWORD*)&byte_5D4594[4788] = &byte_587000[25824];
	*(_DWORD*)&byte_5D4594[10992] = &byte_5D4594[4676];
	*(_DWORD*)&byte_5D4594[4676] = 132;
	*(_DWORD*)&byte_5D4594[4776] = 768;
	if (byte_5D4594 != (unsigned __int8*)-4676) {
		*(_DWORD*)&byte_5D4594[4692] = 0;
		*(_DWORD*)&byte_5D4594[4684] = *(_DWORD*)&byte_5D4594[823784];
		*(_DWORD*)&byte_5D4594[4688] = *(_DWORD*)&byte_5D4594[823784];
		*(_DWORD*)&byte_5D4594[4680] = *(_DWORD*)&byte_5D4594[823784];
		*(_DWORD*)&byte_5D4594[4696] = 0;
		*(_DWORD*)&byte_5D4594[4700] = 0;
		InitializeCriticalSection((LPCRITICAL_SECTION)&byte_5D4594[4704]);
		InitializeCriticalSection((LPCRITICAL_SECTION)&byte_5D4594[4728]);
		InitializeCriticalSection((LPCRITICAL_SECTION)&byte_5D4594[4752]);
		v0 = *(_DWORD*)&byte_5D4594[4692];
		*(_DWORD*)&byte_5D4594[4780] = 0;
		byte_5D4594[4784] = 1;
		*(_DWORD*)&byte_5D4594[4792] = 0;
		*(_DWORD*)&byte_5D4594[4800] = 0;
		*(_DWORD*)&byte_5D4594[4796] = 0;
		*(_DWORD*)&byte_5D4594[4804] = 0;
		if (*(_DWORD*)&byte_5D4594[4692]) {
			if (**(_DWORD**)&byte_5D4594[4692]) {
				do {
					(*(void(__stdcall**)(int))(v0 + 32))(1);
					if (*(_DWORD*)&byte_5D4594[4676] == 100)
						v0 += 28;
					else
						v0 += 36;
				} while (*(_DWORD*)v0);
			}
		}
	}
	CoCreateInstance((const IID* const) & byte_581450[5784], 0, 1u, (const IID* const) & byte_581450[5624],
			 (LPVOID*)&dword_5d4594_4668);
	if (dword_5d4594_4668) {
		sub_40E3E0(&v5);
		sub_40E260(*(int(__stdcall****)(_DWORD, void*, int*)) & dword_5d4594_4668, v5, (int)&byte_581450[5640],
			   (int)&byte_5D4594[10960]);
	}
	CoCreateInstance((const IID* const) & byte_581450[5800], 0, 1u, (const IID* const) & byte_581450[5656],
			 (LPVOID*)&dword_5d4594_4808);
	if (dword_5d4594_4808) {
		sub_40E630(&v4);
		sub_40E260(*(int(__stdcall****)(_DWORD, void*, int*)) & dword_5d4594_4808, v4, (int)&byte_581450[5672],
			   (int)&byte_5D4594[10964]);
	}
	CoCreateInstance((const IID* const) & byte_581450[5816], 0, 1u, (const IID* const) & byte_581450[5688],
			 (LPVOID*)&dword_5d4594_10956);
	if (!dword_5d4594_10956)
		goto LABEL_27;
	sub_40E800(&v3);
	sub_40E260(*(int(__stdcall****)(_DWORD, void*, int*)) & dword_5d4594_10956, (int)v3, (int)&byte_581450[5704],
		   (int)&byte_5D4594[10968]);
	if (!dword_5d4594_10956)
		goto LABEL_27;
	if (dword_5d4594_4808 && (v1 = dword_5d4594_4668) != 0 &&
	    (v3 = v6, *(_DWORD*)&byte_5D4594[10976] = 1, strcpy(v6, "SOFTWARE\\Westwood\\Nox"),
	     (*(void(__stdcall**)(int, unsigned __int8*, char*))(*(_DWORD*)v1 + 164))(v1, &byte_587000[25772], v6),
	     sub_420030(), sub_4200E0() != -1)) {
		result = 1;
	} else {
	LABEL_27:
		result = 0;
	}
	return result;
#endif
}

//----- (0040D0F0) --------------------------------------------------------
void sub_40D0F0() {
	unsigned __int8* v0; // eax
	int v1;              // esi
	int v2;              // eax
	_DWORD* v3;          // esi
	_DWORD* v4;          // edi
	unsigned int v5;     // esi

	LOBYTE(v0) = byte_5D4594[10976];
	if (*(_DWORD*)&byte_5D4594[10976]) {
		if (dword_5d4594_10956) {
			sub_40E320(*(int(__stdcall****)(_DWORD, void*, int*)) & dword_5d4594_10956,
				   (int)&byte_581450[5704], *(int*)&byte_5D4594[10968]);
			(*(void(__stdcall**)(_DWORD))(**(_DWORD**)&dword_5d4594_10956 + 8))(
			    dword_5d4594_10956);
		}
		if (dword_5d4594_4808) {
			sub_40E320(*(int(__stdcall****)(_DWORD, void*, int*)) & dword_5d4594_4808,
				   (int)&byte_581450[5672], *(int*)&byte_5D4594[10964]);
			(*(void(__stdcall**)(_DWORD))(**(_DWORD**)&dword_5d4594_4808 + 8))(
			    dword_5d4594_4808);
		}
		if (dword_5d4594_4668) {
			sub_40E320(*(int(__stdcall****)(_DWORD, void*, int*)) & dword_5d4594_4668,
				   (int)&byte_581450[5640], *(int*)&byte_5D4594[10960]);
			(*(void(__stdcall**)(_DWORD))(**(_DWORD**)&dword_5d4594_4668 + 8))(
			    dword_5d4594_4668);
		}
		v0 = &byte_5D4594[4676];
		if (true) // TODO: byte_5D4594 != (unsigned __int8*)-4676
		{
			v1 = *(_DWORD*)&byte_5D4594[4692];
			if (*(_DWORD*)&byte_5D4594[4692] && **(_DWORD**)&byte_5D4594[4692]) {
				do {
					v2 = *(_DWORD*)(v1 + 16);
					if (v2)
						(*(void(__stdcall**)(_DWORD))(*(_DWORD*)v2 + 8))(*(_DWORD*)(v1 + 16));
					*(_DWORD*)(v1 + 16) = 0;
					(*(void(__stdcall**)(_DWORD))(v1 + 32))(0);
					if (*(_DWORD*)&byte_5D4594[4676] == 100)
						v1 += 28;
					else
						v1 += 36;
				} while (*(_DWORD*)v1);
			}
			DeleteCriticalSection((LPCRITICAL_SECTION)&byte_5D4594[4704]);
			DeleteCriticalSection((LPCRITICAL_SECTION)&byte_5D4594[4728]);
			DeleteCriticalSection((LPCRITICAL_SECTION)&byte_5D4594[4752]);
			v3 = *(_DWORD**)&byte_5D4594[4804];
			if (*(_DWORD*)&byte_5D4594[4804]) {
				do {
					((void(__stdcall*)(_DWORD)) * v3)(v3[1]);
					v4 = (_DWORD*)v3[2];
					operator_delete(v3);
					v3 = v4;
				} while (v4);
			}
			LOBYTE(v0) = byte_5D4594[4700];
			if (*(_DWORD*)&byte_5D4594[4700]) {
				LOBYTE(v0) = byte_5D4594[4784];
				if (byte_5D4594[4784]) {
					if (*(_DWORD*)&byte_5D4594[4796]) {
						v5 = 0;
						do
							HeapDestroy(
							    *(HANDLE*)(*(_DWORD*)&byte_5D4594[4796] + 4 * v5++));
						while (v5 <= *(int*)&byte_5D4594[4792]);
					}
					LOBYTE(v0) = HeapDestroy(*(HANDLE*)&byte_5D4594[4700]);
				}
			}
		}
		*(_DWORD*)&byte_5D4594[10976] = 0;
	}
}

//----- (0040D250) --------------------------------------------------------
BOOL sub_40D250() {
	return *(_DWORD*)&byte_5D4594[10976] && !dword_5d4594_10984 &&
	       (*(int(__stdcall**)(_DWORD))(**(_DWORD**)&dword_5d4594_4668 + 12))(dword_5d4594_4668) >= 0;
}

//----- (0040D280) --------------------------------------------------------
BOOL __cdecl sub_40D280(int a1, int a2, int a3, int a4, int a5) {
	BOOL result; // eax

	if (*(_DWORD*)&byte_5D4594[10976])
		result = (*(int(__stdcall**)(_DWORD, int, int, int, int, int))(**(_DWORD**)&dword_5d4594_4668 + 16))(
			     dword_5d4594_4668, a1, a2, a3, a4, a5) >= 0;
	else
		result = 0;
	return result;
}

//----- (0040D2C0) --------------------------------------------------------
BOOL __cdecl sub_40D2C0(int a1, int a2, int a3) {
	BOOL result; // eax

	if (*(_DWORD*)&byte_5D4594[10976])
		result = (*(int(__stdcall**)(_DWORD, int, int, int))(**(_DWORD**)&dword_5d4594_4668 + 20))(
			     dword_5d4594_4668, a1, a2, a3) >= 0;
	else
		result = 0;
	return result;
}

//----- (0040D2F0) --------------------------------------------------------
BOOL __cdecl sub_40D2F0(int a1, int a2) {
	BOOL result; // eax

	if (*(_DWORD*)&byte_5D4594[10976])
		result = (*(int(__stdcall**)(_DWORD, int, int))(**(_DWORD**)&dword_5d4594_4668 + 24))(
			     dword_5d4594_4668, a1, a2) >= 0;
	else
		result = 0;
	return result;
}

//----- (0040D320) --------------------------------------------------------
BOOL __cdecl sub_40D320(int a1) {
	BOOL result; // eax

	if (*(_DWORD*)&byte_5D4594[10976])
		result = (*(int(__stdcall**)(_DWORD, int))(**(_DWORD**)&dword_5d4594_4668 + 28))(
			     dword_5d4594_4668, a1) >= 0;
	else
		result = 0;
	return result;
}

//----- (0040D350) --------------------------------------------------------
BOOL __cdecl sub_40D350(int a1) {
	BOOL result; // eax

	if (*(_DWORD*)&byte_5D4594[10976])
		result = (*(int(__stdcall**)(_DWORD, int))(**(_DWORD**)&dword_5d4594_4668 + 32))(
			     dword_5d4594_4668, a1) >= 0;
	else
		result = 0;
	return result;
}

//----- (0040D380) --------------------------------------------------------
BOOL sub_40D380() {
	BOOL result; // eax

	if (*(_DWORD*)&byte_5D4594[10976])
		result = (*(int(__stdcall**)(_DWORD))(**(_DWORD**)&dword_5d4594_4668 + 36))(
			     dword_5d4594_4668) >= 0;
	else
		result = 0;
	return result;
}

//----- (0040D3B0) --------------------------------------------------------
BOOL sub_40D3B0() {
	BOOL result; // eax

	if (*(_DWORD*)&byte_5D4594[10976])
		result = (*(int(__stdcall**)(_DWORD))(**(_DWORD**)&dword_5d4594_4668 + 40))(
			     dword_5d4594_4668) >= 0;
	else
		result = 0;
	return result;
}

//----- (0040D3E0) --------------------------------------------------------
BOOL __cdecl sub_40D3E0(int a1) {
	BOOL result; // eax

	if (*(_DWORD*)&byte_5D4594[10976])
		result = (*(int(__stdcall**)(_DWORD, int))(**(_DWORD**)&dword_5d4594_4668 + 44))(
			     dword_5d4594_4668, a1) >= 0;
	else
		result = 0;
	return result;
}

//----- (0040D410) --------------------------------------------------------
BOOL __cdecl sub_40D410(int a1, int a2) {
	BOOL result; // eax

	if (*(_DWORD*)&byte_5D4594[10976])
		result = (*(int(__stdcall**)(_DWORD, int, int))(**(_DWORD**)&dword_5d4594_4668 + 48))(
			     dword_5d4594_4668, a1, a2) >= 0;
	else
		result = 0;
	return result;
}

//----- (0040D440) --------------------------------------------------------
int sub_40D440() {
	int result; // eax

	if (!*(_DWORD*)&byte_5D4594[10976] ||
	    (*(int(__stdcall**)(_DWORD))(**(_DWORD**)&dword_5d4594_4668 + 52))(dword_5d4594_4668) < 0) {
		return 0;
	}
	result = 1;
	*(_DWORD*)&byte_5D4594[10988] = 1;
	return result;
}

//----- (0040D470) --------------------------------------------------------
BOOL __cdecl sub_40D470(int a1, int a2) {
	BOOL result; // eax

	if (*(_DWORD*)&byte_5D4594[10976])
		result = (*(int(__stdcall**)(_DWORD, int, int))(**(_DWORD**)&dword_5d4594_4668 + 56))(
			     dword_5d4594_4668, a1, a2) >= 0;
	else
		result = 0;
	return result;
}

//----- (0040D4A0) --------------------------------------------------------
BOOL __cdecl sub_40D4A0(int a1) {
	BOOL result; // eax

	if (*(_DWORD*)&byte_5D4594[10976])
		result = (*(int(__stdcall**)(_DWORD, int))(**(_DWORD**)&dword_5d4594_4668 + 60))(
			     dword_5d4594_4668, a1) >= 0;
	else
		result = 0;
	return result;
}

//----- (0040D4D0) --------------------------------------------------------
BOOL __cdecl sub_40D4D0(int a1) {
	BOOL result; // eax

	if (*(_DWORD*)&byte_5D4594[10976])
		result = (*(int(__stdcall**)(_DWORD, int))(**(_DWORD**)&dword_5d4594_4668 + 64))(
			     dword_5d4594_4668, a1) >= 0;
	else
		result = 0;
	return result;
}

//----- (0040D500) --------------------------------------------------------
BOOL __cdecl sub_40D500(int a1, int a2) {
	BOOL result; // eax

	if (*(_DWORD*)&byte_5D4594[10976])
		result = (*(int(__stdcall**)(_DWORD, int, int))(**(_DWORD**)&dword_5d4594_4668 + 68))(
			     dword_5d4594_4668, a1, a2) >= 0;
	else
		result = 0;
	return result;
}

//----- (0040D530) --------------------------------------------------------
BOOL __cdecl sub_40D530(int a1) {
	BOOL result; // eax

	if (*(_DWORD*)&byte_5D4594[10976])
		result = (*(int(__stdcall**)(_DWORD, int))(**(_DWORD**)&dword_5d4594_4668 + 72))(
			     dword_5d4594_4668, a1) >= 0;
	else
		result = 0;
	return result;
}

//----- (0040D560) --------------------------------------------------------
int __cdecl sub_40D560(int a1) {
	int v2; // eax

	if (!*(_DWORD*)&byte_5D4594[10976])
		return 0;
	v2 = (*(int(__stdcall**)(_DWORD, int))(**(_DWORD**)&dword_5d4594_4668 + 76))(dword_5d4594_4668, a1);
	if (v2 <= -2147220995) {
		return 0;
	}
	if (v2)
		return 0;
	return 1;
}

//----- (0040D5B0) --------------------------------------------------------
BOOL __cdecl sub_40D5B0(int a1) {
	BOOL result; // eax

	if (*(_DWORD*)&byte_5D4594[10976])
		result = (*(int(__stdcall**)(_DWORD, int))(**(_DWORD**)&dword_5d4594_4668 + 80))(
			     dword_5d4594_4668, a1) >= 0;
	else
		result = 0;
	return result;
}

//----- (0040D5E0) --------------------------------------------------------
BOOL __cdecl sub_40D5E0(int a1) {
	BOOL result; // eax

	if (*(_DWORD*)&byte_5D4594[10976])
		result = (*(int(__stdcall**)(_DWORD, int))(**(_DWORD**)&dword_5d4594_4668 + 84))(
			     dword_5d4594_4668, a1) >= 0;
	else
		result = 0;
	return result;
}

//----- (0040D610) --------------------------------------------------------
BOOL __cdecl sub_40D610(int a1) {
	BOOL result; // eax

	if (*(_DWORD*)&byte_5D4594[10976])
		result = (*(int(__stdcall**)(_DWORD, int))(**(_DWORD**)&dword_5d4594_4668 + 88))(
			     dword_5d4594_4668, a1) >= 0;
	else
		result = 0;
	return result;
}

//----- (0040D640) --------------------------------------------------------
BOOL __cdecl sub_40D640(int a1) {
	BOOL result; // eax

	if (*(_DWORD*)&byte_5D4594[10976])
		result = (*(int(__stdcall**)(_DWORD, int))(**(_DWORD**)&dword_5d4594_4668 + 188))(
			     dword_5d4594_4668, a1) >= 0;
	else
		result = 0;
	return result;
}

//----- (0040D670) --------------------------------------------------------
BOOL __cdecl sub_40D670(int a1) {
	BOOL result; // eax

	if (*(_DWORD*)&byte_5D4594[10976])
		result = (*(int(__stdcall**)(_DWORD, int))(**(_DWORD**)&dword_5d4594_4668 + 184))(
			     dword_5d4594_4668, a1) >= 0;
	else
		result = 0;
	return result;
}

//----- (0040D6A0) --------------------------------------------------------
BOOL __cdecl sub_40D6A0(int a1) {
	BOOL result; // eax

	if (*(_DWORD*)&byte_5D4594[10976])
		result = (*(int(__stdcall**)(_DWORD, int))(**(_DWORD**)&dword_5d4594_4668 + 192))(
			     dword_5d4594_4668, a1) >= 0;
	else
		result = 0;
	return result;
}

//----- (0040D6D0) --------------------------------------------------------
BOOL __cdecl sub_40D6D0(int a1) {
	BOOL result; // eax

	if (*(_DWORD*)&byte_5D4594[10976])
		result = (*(int(__stdcall**)(_DWORD, int))(**(_DWORD**)&dword_5d4594_4668 + 180))(
			     dword_5d4594_4668, a1) >= 0;
	else
		result = 0;
	return result;
}

//----- (0040D700) --------------------------------------------------------
BOOL __cdecl sub_40D700(int a1, int a2, int a3, int a4, int a5, int a6) {
	BOOL result; // eax

	if (*(_DWORD*)&byte_5D4594[10976])
		result =
		    (*(int(__stdcall**)(_DWORD, int, int, int, int, int, int))(**(_DWORD**)&dword_5d4594_4668 + 92))(
			dword_5d4594_4668, a1, a2, a3, a4, a5, a6) >= 0;
	else
		result = 0;
	return result;
}

//----- (0040D740) --------------------------------------------------------
BOOL __cdecl sub_40D740(int a1) {
	BOOL result; // eax

	if (*(_DWORD*)&byte_5D4594[10976])
		result = (*(int(__stdcall**)(_DWORD, int))(**(_DWORD**)&dword_5d4594_4668 + 96))(
			     dword_5d4594_4668, a1) >= 0;
	else
		result = 0;
	return result;
}

//----- (0040D770) --------------------------------------------------------
BOOL __cdecl sub_40D770(int a1, int a2) {
	BOOL result; // eax

	if (*(_DWORD*)&byte_5D4594[10976])
		result = (*(int(__stdcall**)(_DWORD, int, int))(**(_DWORD**)&dword_5d4594_4668 + 100))(
			     dword_5d4594_4668, a1, a2) >= 0;
	else
		result = 0;
	return result;
}

//----- (0040D7A0) --------------------------------------------------------
BOOL __cdecl sub_40D7A0(int a1, int a2) {
	BOOL result; // eax

	if (*(_DWORD*)&byte_5D4594[10976])
		result = (*(int(__stdcall**)(_DWORD, int, int))(**(_DWORD**)&dword_5d4594_4668 + 104))(
			     dword_5d4594_4668, a1, a2) >= 0;
	else
		result = 0;
	return result;
}

//----- (0040D7D0) --------------------------------------------------------
BOOL __cdecl sub_40D7D0(int a1, int a2) {
	BOOL result; // eax

	if (*(_DWORD*)&byte_5D4594[10976])
		result = (*(int(__stdcall**)(_DWORD, int, int))(**(_DWORD**)&dword_5d4594_4668 + 108))(
			     dword_5d4594_4668, a1, a2) >= 0;
	else
		result = 0;
	return result;
}

//----- (0040D800) --------------------------------------------------------
BOOL __cdecl sub_40D800(int a1) {
	BOOL result; // eax

	if (*(_DWORD*)&byte_5D4594[10976])
		result = (*(int(__stdcall**)(_DWORD, int))(**(_DWORD**)&dword_5d4594_4668 + 112))(
			     dword_5d4594_4668, a1) >= 0;
	else
		result = 0;
	return result;
}

//----- (0040D830) --------------------------------------------------------
BOOL __cdecl sub_40D830(int a1) {
	BOOL result; // eax

	if (*(_DWORD*)&byte_5D4594[10976])
		result = (*(int(__stdcall**)(_DWORD, int))(**(_DWORD**)&dword_5d4594_4668 + 116))(
			     dword_5d4594_4668, a1) >= 0;
	else
		result = 0;
	return result;
}

//----- (0040D860) --------------------------------------------------------
BOOL sub_40D860() {
	BOOL result; // eax

	if (*(_DWORD*)&byte_5D4594[10976])
		result = (*(int(__stdcall**)(_DWORD))(**(_DWORD**)&dword_5d4594_4668 + 120))(
			     dword_5d4594_4668) >= 0;
	else
		result = 0;
	return result;
}

//----- (0040D890) --------------------------------------------------------
BOOL __cdecl sub_40D890(int a1) {
	BOOL result; // eax

	if (*(_DWORD*)&byte_5D4594[10976])
		result = (*(int(__stdcall**)(_DWORD, int))(**(_DWORD**)&dword_5d4594_4668 + 124))(
			     dword_5d4594_4668, a1) >= 0;
	else
		result = 0;
	return result;
}

//----- (0040D8C0) --------------------------------------------------------
BOOL __cdecl sub_40D8C0(int a1, int a2) {
	BOOL result; // eax

	if (*(_DWORD*)&byte_5D4594[10976])
		result = (*(int(__stdcall**)(_DWORD, int, int))(**(_DWORD**)&dword_5d4594_4668 + 128))(
			     dword_5d4594_4668, a1, a2) >= 0;
	else
		result = 0;
	return result;
}

//----- (0040D8F0) --------------------------------------------------------
BOOL __cdecl sub_40D8F0(int a1) {
	BOOL result; // eax

	if (*(_DWORD*)&byte_5D4594[10976])
		result = (*(int(__stdcall**)(_DWORD, int))(**(_DWORD**)&dword_5d4594_4668 + 132))(
			     dword_5d4594_4668, a1) >= 0;
	else
		result = 0;
	return result;
}

//----- (0040D920) --------------------------------------------------------
BOOL __cdecl sub_40D920(int a1) {
	BOOL result; // eax

	if (*(_DWORD*)&byte_5D4594[10976])
		result = (*(int(__stdcall**)(_DWORD, int))(**(_DWORD**)&dword_5d4594_4668 + 136))(
			     dword_5d4594_4668, a1) >= 0;
	else
		result = 0;
	return result;
}

//----- (0040D950) --------------------------------------------------------
BOOL __cdecl sub_40D950(int a1) {
	BOOL result; // eax

	if (*(_DWORD*)&byte_5D4594[10976])
		result = (*(int(__stdcall**)(_DWORD, int))(**(_DWORD**)&dword_5d4594_4668 + 140))(
			     dword_5d4594_4668, a1) >= 0;
	else
		result = 0;
	return result;
}

//----- (0040D980) --------------------------------------------------------
BOOL __cdecl sub_40D980(int a1, int a2, int a3) {
	BOOL result; // eax

	if (*(_DWORD*)&byte_5D4594[10976])
		result = (*(int(__stdcall**)(_DWORD, int, int, int))(**(_DWORD**)&dword_5d4594_4668 + 144))(
			     dword_5d4594_4668, a1, a2, a3) >= 0;
	else
		result = 0;
	return result;
}

//----- (0040D9C0) --------------------------------------------------------
BOOL __cdecl sub_40D9C0(int a1, int a2, int a3, int a4) {
	BOOL result; // eax

	if (*(_DWORD*)&byte_5D4594[10976])
		result = (*(int(__stdcall**)(_DWORD, int, int, int, int))(**(_DWORD**)&dword_5d4594_4668 + 148))(
			     dword_5d4594_4668, a1, a2, a3, a4) >= 0;
	else
		result = 0;
	return result;
}

//----- (0040DA00) --------------------------------------------------------
BOOL __cdecl sub_40DA00(int a1) {
	BOOL result; // eax

	if (*(_DWORD*)&byte_5D4594[10976])
		result = (*(int(__stdcall**)(_DWORD, int))(**(_DWORD**)&dword_5d4594_4668 + 152))(
			     dword_5d4594_4668, a1) >= 0;
	else
		result = 0;
	return result;
}

//----- (0040DA30) --------------------------------------------------------
BOOL __cdecl sub_40DA30(int a1) {
	BOOL result; // eax

	if (*(_DWORD*)&byte_5D4594[10976])
		result = (*(int(__stdcall**)(_DWORD, int))(**(_DWORD**)&dword_5d4594_4668 + 156))(
			     dword_5d4594_4668, a1) >= 0;
	else
		result = 0;
	return result;
}

//----- (0040DA60) --------------------------------------------------------
BOOL __cdecl sub_40DA60(int a1, int a2) {
	BOOL result; // eax

	if (*(_DWORD*)&byte_5D4594[10976])
		result = (*(int(__stdcall**)(_DWORD, int, int))(**(_DWORD**)&dword_5d4594_4668 + 160))(
			     dword_5d4594_4668, a1, a2) >= 0;
	else
		result = 0;
	return result;
}

//----- (0040DA90) --------------------------------------------------------
BOOL __cdecl sub_40DA90(int a1, int a2) {
	BOOL result; // eax

	if (*(_DWORD*)&byte_5D4594[10976])
		result = (*(int(__stdcall**)(_DWORD, int, int))(**(_DWORD**)&dword_5d4594_4668 + 164))(
			     dword_5d4594_4668, a1, a2) >= 0;
	else
		result = 0;
	return result;
}

//----- (0040DAC0) --------------------------------------------------------
BOOL __cdecl sub_40DAC0(int a1) {
	BOOL result; // eax

	if (*(_DWORD*)&byte_5D4594[10976])
		result = (*(int(__stdcall**)(_DWORD, int))(**(_DWORD**)&dword_5d4594_4668 + 168))(
			     dword_5d4594_4668, a1) >= 0;
	else
		result = 0;
	return result;
}

//----- (0040DAF0) --------------------------------------------------------
BOOL sub_40DAF0() {
	BOOL result; // eax

	if (*(_DWORD*)&byte_5D4594[10976])
		result = (*(int(__stdcall**)(_DWORD))(**(_DWORD**)&dword_5d4594_4668 + 172))(
			     dword_5d4594_4668) >= 0;
	else
		result = 0;
	return result;
}

//----- (0040DB20) --------------------------------------------------------
BOOL __cdecl sub_40DB20(int a1) {
	BOOL result; // eax

	if (*(_DWORD*)&byte_5D4594[10976])
		result = (*(int(__stdcall**)(_DWORD, int))(**(_DWORD**)&dword_5d4594_4668 + 176))(
			     dword_5d4594_4668, a1) >= 0;
	else
		result = 0;
	return result;
}

//----- (0040DB50) --------------------------------------------------------
BOOL __cdecl sub_40DB50(int a1, int a2) {
	BOOL result; // eax

	if (*(_DWORD*)&byte_5D4594[10976])
		result = (*(int(__stdcall**)(_DWORD, int, int))(**(_DWORD**)&dword_5d4594_4668 + 196))(
			     dword_5d4594_4668, a1, a2) >= 0;
	else
		result = 0;
	return result;
}

//----- (0040DB80) --------------------------------------------------------
BOOL __cdecl sub_40DB80(int a1, int a2) {
	BOOL result; // eax

	if (*(_DWORD*)&byte_5D4594[10976])
		result = (*(int(__stdcall**)(_DWORD, int, int))(**(_DWORD**)&dword_5d4594_4668 + 200))(
			     dword_5d4594_4668, a1, a2) >= 0;
	else
		result = 0;
	return result;
}

//----- (0040DBB0) --------------------------------------------------------
int __stdcall sub_40DBB0(int a1) {
	int v1; // eax

	sub_41E560(0, 0, 0, 0);
	v1 = sub_41E2F0();
	sub_41DA70(v1, 16);
	return 0;
}

//----- (0040DBE0) --------------------------------------------------------
int __stdcall sub_40DBE0(int a1, int a2) {
	int v2; // eax

	sub_41E560(0, 0, 0, 0);
	sub_41E5C0(a2);
	v2 = sub_41E2F0();
	sub_41DA70(v2, 17);
	return 0;
}

//----- (0040DC10) --------------------------------------------------------
int __stdcall sub_40DC10(int a1, int a2, int a3, int a4, int a5) {
	int v5; // eax

	if (sub_40E0B0()) {
		sub_41E560(a2, a3, a4, a5);
		v5 = sub_41E2F0();
		sub_41DA70(v5, 18);
	}
	return 0;
}

//----- (0040DC50) --------------------------------------------------------
int __stdcall sub_40DC50(int a1, int a2) {
	sub_40E0B0();
	return 0;
}

//----- (0040DC60) --------------------------------------------------------
int __stdcall sub_40DC60(int a1) { return 0; }

//----- (0040DC70) --------------------------------------------------------
BOOL sub_40DC70() {
	return (*(int(__stdcall**)(_DWORD))(**(_DWORD**)&dword_5d4594_4808 + 16))(dword_5d4594_4808) >= 0;
}

//----- (0040DC90) --------------------------------------------------------
BOOL __cdecl sub_40DC90(int a1, int a2, int a3, int a4, int a5, int a6) {
	return (*(int(__stdcall**)(_DWORD, int, int, int, int, int, int))(**(_DWORD**)&dword_5d4594_4808 + 12))(
		   dword_5d4594_4808, a1, a2, a3, a4, a5, a6) >= 0;
}

//----- (0040DCD0) --------------------------------------------------------
BOOL sub_40DCD0() {
	return !dword_5d4594_10984 &&
	       (*(int(__stdcall**)(_DWORD))(**(_DWORD**)&dword_5d4594_4808 + 20))(dword_5d4594_4808) >= 0;
}

//----- (0040DD00) --------------------------------------------------------
int __stdcall sub_40DD00(int a1, int a2, int a3, int a4, int a5) { return 0; }

//----- (0040DD10) --------------------------------------------------------
int __stdcall sub_40DD10(int a1, int a2, int a3, int a4, int a5, int a6) {
	int i; // esi

	if (sub_41E2F0() != 8)
		return 0;
	if (!a2) {
		for (i = a3; i; i = *(_DWORD*)(i + 60)) {
			if (*(_BYTE*)(i + 64))
				sub_417C00((char*)(i + 64), *(_DWORD*)(i + 28));
		}
	}
	return 0;
}

//----- (0040DD60) --------------------------------------------------------
int __stdcall sub_40DD60(int a1, int a2) { return 0; }

//----- (0040DD70) --------------------------------------------------------
int __stdcall sub_40DD70(int a1, int a2, int a3, const char* a4, const char* a5) {
	int v5;     // eax
	int result; // eax
	int v7;     // eax

	if (a2) {
		v5 = sub_41E2F0();
		sub_41DA70(v5, 5);
		result = a3;
		dword_5d4594_2660652 = a2;
		if (a3) {
			nox_swprintf((wchar_t*)&byte_5D4594[2660140], L"%S", a3);
			result = 0;
		} else {
			*(_WORD*)&byte_5D4594[2660140] = 0;
		}
	} else {
		v7 = sub_41E2F0();
		sub_41DA70(v7, 22);
		sub_41FCA0(a4, a5);
		result = a3;
		if (a3) {
			nox_swprintf((wchar_t*)&byte_5D4594[2660140], L"%S", a3);
			result = 0;
		} else {
			*(_WORD*)&byte_5D4594[2660140] = 0;
		}
	}
	return result;
}

//----- (0040DE10) --------------------------------------------------------
int __stdcall sub_40DE10(int a1, int a2, int a3, int a4) {
	int v4; // eax
	int v6; // eax
	int v7; // eax
	int v8; // eax

	dword_5d4594_2660652 = a2;
	if (a2) {
		*(_WORD*)&byte_5D4594[2660140] = 0;
		v4 = sub_41E2F0();
		sub_41DA70(v4, 5);
		return 0;
	}
	if (a3 >= 13) {
		if (a3 < 18) {
			v7 = sub_41E2F0();
			sub_41DA70(v7, 21);
			return 0;
		}
	} else if (!a4) {
		v6 = sub_41E2F0();
		sub_41DA70(v6, 5);
		return 0;
	}
	v8 = sub_41E2F0();
	sub_41DA70(v8, 20);
	return 0;
}

//----- (0040DE90) --------------------------------------------------------
int __stdcall sub_40DE90(int a1, int a2, int a3, int a4) {
	dword_5d4594_2660652 = a2;
	return 0;
}

//----- (0040DEA0) --------------------------------------------------------
BOOL __cdecl sub_40DEA0(int a1, int a2, int a3, int a4) {
	return (*(int(__stdcall**)(_DWORD, int, int, int, int))(**(_DWORD**)&dword_5d4594_10956 + 12))(
		   dword_5d4594_10956, a1, a2, a3, a4) >= 0;
}

//----- (0040DED0) --------------------------------------------------------
BOOL __cdecl sub_40DED0(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9) {
	return (*(int(__stdcall**)(_DWORD, int, int, int, int, int, int, int, int, int))(
		   **(_DWORD**)&dword_5d4594_10956 + 16))(dword_5d4594_10956, a1, a2, a3, a4, a5, a6, a7, a8,
							  a9) >= 0;
}

//----- (0040DF20) --------------------------------------------------------
BOOL __cdecl sub_40DF20(int a1, int a2, int a3, int a4, int a5, int a6, int a7) {
	return (*(int(__stdcall**)(_DWORD, int, int, int, int, int, int, int))(**(_DWORD**)&dword_5d4594_10956 + 20))(
		   dword_5d4594_10956, a1, a2, a3, a4, a5, a6, a7) >= 0;
}

//----- (0040DF60) --------------------------------------------------------
BOOL __cdecl sub_40DF60(int a1, int a2, int a3) {
	return (*(int(__stdcall**)(_DWORD, int, int, int))(**(_DWORD**)&dword_5d4594_10956 + 24))(
		   dword_5d4594_10956, a1, a2, a3) >= 0;
}

//----- (0040DF90) --------------------------------------------------------
BOOL sub_40DF90() {
	return !dword_5d4594_10984 &&
	       (*(int(__stdcall**)(_DWORD))(**(_DWORD**)&dword_5d4594_10956 + 28))(dword_5d4594_10956) >= 0;
}

//----- (0040DFC0) --------------------------------------------------------
BOOL __cdecl sub_40DFC0(int a1, int a2) {
	return (*(int(__stdcall**)(_DWORD, int, int))(**(_DWORD**)&dword_5d4594_10956 + 32))(
		   dword_5d4594_10956, a1, a2) >= 0;
}

//----- (0040DFE0) --------------------------------------------------------
BOOL __cdecl sub_40DFE0(int a1, int a2, int a3, int a4, int a5, int a6) {
	return (*(int(__stdcall**)(_DWORD, int, int, int, int, int, int))(**(_DWORD**)&dword_5d4594_10956 + 36))(
		   dword_5d4594_10956, a1, a2, a3, a4, a5, a6) >= 0;
}

//----- (0040E020) --------------------------------------------------------
BOOL __cdecl sub_40E020(int a1, int a2, int a3, int a4) {
	return (*(int(__stdcall**)(_DWORD, int, int, int, int))(**(_DWORD**)&dword_5d4594_10956 + 40))(
		   dword_5d4594_10956, a1, a2, a3, a4) >= 0;
}

//----- (0040E050) --------------------------------------------------------
BOOL __cdecl sub_40E050(int a1, int a2) {
	return (*(int(__stdcall**)(_DWORD, int, int))(**(_DWORD**)&dword_5d4594_10956 + 44))(
		   dword_5d4594_10956, a1, a2) >= 0;
}

//----- (0040E070) --------------------------------------------------------
void sub_40E070() {
#ifndef NO_WOLAPI
	if (*(_DWORD*)&byte_5D4594[10972] == 1) {
		CoUninitialize();
		*(_DWORD*)&byte_5D4594[10972] = 0;
	}
#endif
}

//----- (0040E090) --------------------------------------------------------
void sub_40E090() { dword_5d4594_10984 = 0; }

//----- (0040E0A0) --------------------------------------------------------
void sub_40E0A0() { dword_5d4594_10984 = 1; }

//----- (0040E0B0) --------------------------------------------------------
BOOL sub_40E0B0() { return dword_5d4594_10984 == 0; }

//----- (0040E0C0) --------------------------------------------------------
int sub_40E0C0() { return *(_DWORD*)&byte_5D4594[10976]; }

//----- (0040E0D0) --------------------------------------------------------
int __cdecl sub_40E0D0(int a1, LPCSTR lpSubKey, int a3) {
	int result;     // eax
	signed int i;   // ecx
	char* v5;       // edi
	int v6;         // eax
	int v7;         // ecx
	FILE* v8;       // edi
	int v9;         // esi
	int v10;        // ebp
	int v11;        // ecx
	HKEY phkResult; // [esp+4h] [ebp-214h]
	FILE* v13;      // [esp+8h] [ebp-210h]
	DWORD cbData;   // [esp+Ch] [ebp-20Ch]
	DWORD Type;     // [esp+10h] [ebp-208h]
	char Data[516]; // [esp+14h] [ebp-204h]

	if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, lpSubKey, 0, 0x20019u, &phkResult))
		return 0;
	Data[0] = 0;
	cbData = 513;
	if (RegQueryValueExA(phkResult, (LPCSTR)&byte_587000[25796], 0, &Type, (LPBYTE)Data, &cbData)) {
		RegCloseKey(phkResult);
		result = 0;
	} else {
		RegCloseKey(phkResult);
		for (i = strlen(Data) - 1; i >= 0; Data[i--] = 0) {
			if (Data[i] == 92)
				break;
		}
		v5 = &Data[strlen(Data) + 1];
		v6 = *(_DWORD*)&byte_587000[25812];
		v7 = *(_DWORD*)&byte_587000[25816];
		*(_DWORD*)--v5 = *(_DWORD*)&byte_587000[25808];
		*((_DWORD*)v5 + 1) = v6;
		*((_DWORD*)v5 + 2) = v7;
		result = (int)fopen(Data, "r");
		v8 = (FILE*)result;
		v13 = (FILE*)result;
		if (result) {
			v9 = 0;
			v10 = 1;
			if (!a3)
				v10 = -1;
			v11 = fgetc((FILE*)result);
			if (v11 != -1) {
				do {
					*(_BYTE*)(v9 + a1) =
					    ((*(char*)(v9 + a1) - 48) % 10 + v10 * v11 + 1000) % 10 + 48;
					if (++v9 == strlen((const char*)a1))
						v9 = 0;
					v11 = fgetc(v13);
				} while (v11 != -1);
				v8 = v13;
			}
			fclose(v8);
			result = 1;
		}
	}
	return result;
}
// 40E0D0: using guessed type BYTE Data[516];

//----- (0040E260) --------------------------------------------------------
int __stdcall sub_40E260(int(__stdcall*** a1)(_DWORD, void*, int*), int a2, int a3, int a4) {
	int(__stdcall * *v4)(_DWORD, void*, int*); // ecx
	int v5;                                    // esi
	int v7;                                    // [esp+24h] [ebp-14h]
	int v8[3];                                 // [esp+28h] [ebp-10h]
	int v9;                                    // [esp+34h] [ebp-4h]

	v8[0] = 0;
	v9 = 0;
	v7 = 0;
	v4 = *a1;
	LOBYTE(v9) = 1;
	v5 = (*v4)(a1, &byte_581450[11152], v8);
	if (v5 >= 0) {
		v5 = (*(int(__stdcall**)(int, int, int*))(*(_DWORD*)v8[0] + 16))(v8[0], a3, &v7);
		if (v5 >= 0)
			v5 = (*(int(__stdcall**)(int, int, int))(*(_DWORD*)v7 + 20))(v7, a2, a4);
	}
	LOBYTE(v9) = 0;
	if (v7)
		(*(void(__stdcall**)(int))(*(_DWORD*)v7 + 8))(v7);
	v9 = -1;
	if (v8[0])
		(*(void(__stdcall**)(int))(*(_DWORD*)v8[0] + 8))(v8[0]);
	return v5;
}

//----- (0040E320) --------------------------------------------------------
int __stdcall sub_40E320(int(__stdcall*** a1)(_DWORD, void*, int*), int a2, int a3) {
	int(__stdcall * *v3)(_DWORD, void*, int*); // ecx
	int v4;                                    // esi
	int v6;                                    // [esp+20h] [ebp-14h]
	int v7[3];                                 // [esp+24h] [ebp-10h]
	int v8;                                    // [esp+30h] [ebp-4h]

	v7[0] = 0;
	v8 = 0;
	v6 = 0;
	v3 = *a1;
	LOBYTE(v8) = 1;
	v4 = (*v3)(a1, &byte_581450[11152], v7);
	if (v4 >= 0) {
		v4 = (*(int(__stdcall**)(int, int, int*))(*(_DWORD*)v7[0] + 16))(v7[0], a2, &v6);
		if (v4 >= 0)
			v4 = (*(int(__stdcall**)(int, int))(*(_DWORD*)v6 + 24))(v6, a3);
	}
	LOBYTE(v8) = 0;
	if (v6)
		(*(void(__stdcall**)(int))(*(_DWORD*)v6 + 8))(v6);
	v8 = -1;
	if (v7[0])
		(*(void(__stdcall**)(int))(*(_DWORD*)v7[0] + 8))(v7[0]);
	return v4;
}

//----- (0040E3D0) --------------------------------------------------------
int __thiscall sub_40E3D0(int* this) {
	int result; // eax

	result = *this;
	if (*this)
		result = (*(int(__stdcall**)(int))(*(_DWORD*)result + 8))(result);
	return result;
}

//----- (0040E3E0) --------------------------------------------------------
int __stdcall sub_40E3E0(_DWORD* a1) {
	void* v1;   // eax
	_DWORD* v2; // esi
	int result; // eax

	v1 = operator_new(0x20u);
	v2 = v1;
	if (v1) {
		sub_40E470((char*)v1 + 4);
		*v2 = &byte_581450[5920];
		InterlockedIncrement((volatile LONG*)&byte_5D4594[4696]);
		result = 0;
		*a1 = v2;
	} else {
		*a1 = 0;
		result = -2147024882;
	}
	return result;
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (0040E470) --------------------------------------------------------
char* __thiscall sub_40E470(char* this) {
	char* v1; // esi

	v1 = this;
	*(_DWORD*)this = 0;
	InitializeCriticalSection((LPCRITICAL_SECTION)(this + 4));
	return v1;
}

//----- (0040E490) --------------------------------------------------------
LONG __stdcall sub_40E490(int a1) { return InterlockedIncrement((volatile LONG*)(a1 + 4)); }

//----- (0040E4B0) --------------------------------------------------------
LONG __stdcall sub_40E4B0(volatile LONG* lpMem) {
	LONG v1; // edi

	v1 = InterlockedDecrement(lpMem + 1);
	if (!v1 && lpMem) {
		sub_40E5F0(lpMem);
		operator_delete((LPVOID)lpMem);
	}
	return v1;
}

//----- (0040E4F0) --------------------------------------------------------
int __stdcall sub_40E4F0(int a1, _DWORD* a2, int* a3) {
	unsigned __int8* v3;                             // esi
	int result;                                      // eax
	_DWORD* v5;                                      // eax
	BOOL v6;                                         // ebp
	int(__stdcall * v7)(int, _DWORD*, int*, _DWORD); // eax
	int v8;                                          // eax
	int v9;                                          // esi

	v3 = &byte_581450[5896];
	if (!a3)
		return -2147467261;
	*a3 = 0;
	if (!*a2 && !a2[1] && a2[2] == 192 && a2[3] == 1174405120) {
		(*(void(__stdcall**)(int))(*(_DWORD*)a1 + 4))(a1);
		*a3 = a1;
		return 0;
	}
	while (1) {
		v5 = *(_DWORD**)v3;
		v6 = *(_DWORD*)v3 == 0;
		if (!*(_DWORD*)v3 || *v5 == *a2 && v5[1] == a2[1] && v5[2] == a2[2] && v5[3] == a2[3])
			break;
	LABEL_17:
		v8 = *((_DWORD*)v3 + 5);
		v3 += 12;
		if (!v8)
			return -2147467262;
	}
	v7 = (int(__stdcall*)(int, _DWORD*, int*, _DWORD)) * ((_DWORD*)v3 + 2);
	if ((int)v7 != 1) {
		result = v7(a1, a2, a3, *((_DWORD*)v3 + 1));
		if (!result || !v6 && result < 0)
			return result;
		goto LABEL_17;
	}
	v9 = a1 + *((_DWORD*)v3 + 1);
	(*(void(__stdcall**)(int))(*(_DWORD*)v9 + 4))(v9);
	*a3 = v9;
	return 0;
}

//----- (0040E5F0) --------------------------------------------------------
void __fastcall sub_40E5F0(_DWORD* a1) {
	_DWORD* v1; // esi
	_DWORD* v2; // edi

	v1 = a1;
	v2 = a1 + 1;
	*a1 = &byte_581450[5920];
	a1[1] = 1;
	InterlockedDecrement((volatile LONG*)&byte_5D4594[4696]);
	DeleteCriticalSection((LPCRITICAL_SECTION)(v1 != 0 ? v2 + 1 : 4));
}

//----- (0040E630) --------------------------------------------------------
int __stdcall sub_40E630(_DWORD* a1) {
	void* v1;   // eax
	_DWORD* v2; // esi
	int result; // eax

	v1 = operator_new(0x20u);
	v2 = v1;
	if (v1) {
		sub_40E470((char*)v1 + 4);
		*v2 = &byte_581450[6084];
		InterlockedIncrement((volatile LONG*)&byte_5D4594[4696]);
		result = 0;
		*a1 = v2;
	} else {
		*a1 = 0;
		result = -2147024882;
	}
	return result;
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (0040E680) --------------------------------------------------------
LONG __stdcall sub_40E680(volatile LONG* lpMem) {
	LONG v1; // edi

	v1 = InterlockedDecrement(lpMem + 1);
	if (!v1 && lpMem) {
		sub_40E7C0(lpMem);
		operator_delete((LPVOID)lpMem);
	}
	return v1;
}

//----- (0040E6C0) --------------------------------------------------------
int __stdcall sub_40E6C0(int a1, _DWORD* a2, int* a3) {
	unsigned __int8* v3;                             // esi
	int result;                                      // eax
	_DWORD* v5;                                      // eax
	BOOL v6;                                         // ebp
	int(__stdcall * v7)(int, _DWORD*, int*, _DWORD); // eax
	int v8;                                          // eax
	int v9;                                          // esi

	v3 = &byte_581450[5872];
	if (!a3)
		return -2147467261;
	*a3 = 0;
	if (!*a2 && !a2[1] && a2[2] == 192 && a2[3] == 1174405120) {
		(*(void(__stdcall**)(int))(*(_DWORD*)a1 + 4))(a1);
		*a3 = a1;
		return 0;
	}
	while (1) {
		v5 = *(_DWORD**)v3;
		v6 = *(_DWORD*)v3 == 0;
		if (!*(_DWORD*)v3 || *v5 == *a2 && v5[1] == a2[1] && v5[2] == a2[2] && v5[3] == a2[3])
			break;
	LABEL_17:
		v8 = *((_DWORD*)v3 + 5);
		v3 += 12;
		if (!v8)
			return -2147467262;
	}
	v7 = (int(__stdcall*)(int, _DWORD*, int*, _DWORD)) * ((_DWORD*)v3 + 2);
	if ((int)v7 != 1) {
		result = v7(a1, a2, a3, *((_DWORD*)v3 + 1));
		if (!result || !v6 && result < 0)
			return result;
		goto LABEL_17;
	}
	v9 = a1 + *((_DWORD*)v3 + 1);
	(*(void(__stdcall**)(int))(*(_DWORD*)v9 + 4))(v9);
	*a3 = v9;
	return 0;
}

//----- (0040E7C0) --------------------------------------------------------
void __fastcall sub_40E7C0(_DWORD* a1) {
	_DWORD* v1; // esi
	_DWORD* v2; // edi

	v1 = a1;
	v2 = a1 + 1;
	*a1 = &byte_581450[6084];
	a1[1] = 1;
	InterlockedDecrement((volatile LONG*)&byte_5D4594[4696]);
	DeleteCriticalSection((LPCRITICAL_SECTION)(v1 != 0 ? v2 + 1 : 4));
}

//----- (0040E800) --------------------------------------------------------
int __stdcall sub_40E800(_DWORD* a1) {
	void* v1;   // eax
	_DWORD* v2; // esi
	int result; // eax

	v1 = operator_new(0x20u);
	v2 = v1;
	if (v1) {
		sub_40E470((char*)v1 + 4);
		*v2 = &byte_581450[6116];
		InterlockedIncrement((volatile LONG*)&byte_5D4594[4696]);
		result = 0;
		*a1 = v2;
	} else {
		*a1 = 0;
		result = -2147024882;
	}
	return result;
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (0040E850) --------------------------------------------------------
LONG __stdcall sub_40E850(volatile LONG* lpMem) {
	LONG v1; // edi

	v1 = InterlockedDecrement(lpMem + 1);
	if (!v1 && lpMem) {
		sub_40E990(lpMem);
		operator_delete((LPVOID)lpMem);
	}
	return v1;
}

//----- (0040E890) --------------------------------------------------------
int __stdcall sub_40E890(int a1, _DWORD* a2, int* a3) {
	unsigned __int8* v3;                             // esi
	int result;                                      // eax
	_DWORD* v5;                                      // eax
	BOOL v6;                                         // ebp
	int(__stdcall * v7)(int, _DWORD*, int*, _DWORD); // eax
	int v8;                                          // eax
	int v9;                                          // esi

	v3 = &byte_581450[5848];
	if (!a3)
		return -2147467261;
	*a3 = 0;
	if (!*a2 && !a2[1] && a2[2] == 192 && a2[3] == 1174405120) {
		(*(void(__stdcall**)(int))(*(_DWORD*)a1 + 4))(a1);
		*a3 = a1;
		return 0;
	}
	while (1) {
		v5 = *(_DWORD**)v3;
		v6 = *(_DWORD*)v3 == 0;
		if (!*(_DWORD*)v3 || *v5 == *a2 && v5[1] == a2[1] && v5[2] == a2[2] && v5[3] == a2[3])
			break;
	LABEL_17:
		v8 = *((_DWORD*)v3 + 5);
		v3 += 12;
		if (!v8)
			return -2147467262;
	}
	v7 = (int(__stdcall*)(int, _DWORD*, int*, _DWORD)) * ((_DWORD*)v3 + 2);
	if ((int)v7 != 1) {
		result = v7(a1, a2, a3, *((_DWORD*)v3 + 1));
		if (!result || !v6 && result < 0)
			return result;
		goto LABEL_17;
	}
	v9 = a1 + *((_DWORD*)v3 + 1);
	(*(void(__stdcall**)(int))(*(_DWORD*)v9 + 4))(v9);
	*a3 = v9;
	return 0;
}

//----- (0040E990) --------------------------------------------------------
void __fastcall sub_40E990(_DWORD* a1) {
	_DWORD* v1; // esi
	_DWORD* v2; // edi

	v1 = a1;
	v2 = a1 + 1;
	*a1 = &byte_581450[6116];
	a1[1] = 1;
	InterlockedDecrement((volatile LONG*)&byte_5D4594[4696]);
	DeleteCriticalSection((LPCRITICAL_SECTION)(v1 != 0 ? v2 + 1 : 4));
}

//----- (0040E9D0) --------------------------------------------------------
int __cdecl sub_40E9D0(int a1, int a2) { return sub_420BC0(*(FILE**)&byte_5D4594[4 * (a1 + 32 * a2) + 210036]); }

//----- (0040E9F0) --------------------------------------------------------
int __cdecl sub_40E9F0(int a1, int a2) { return sub_420BD0(*(_DWORD*)&byte_5D4594[4 * (a1 + 32 * a2) + 210036]); }

//----- (0040EA10) --------------------------------------------------------
_DWORD* sub_40EA10() {
	int i;          // esi
	_DWORD* result; // eax

	for (i = 0; i < 128; i += 4) {
		*(_DWORD*)&byte_5D4594[i + 210164] = sub_420890(512, 0);
		*(_DWORD*)&byte_5D4594[i + 210036] = 0;
		*(_DWORD*)&byte_5D4594[i + 210292] = sub_420890(512, 0);
	}
	result = sub_420890(512, 0);
	*(_DWORD*)&byte_5D4594[210160] = result;
	return result;
}

//----- (0040EA70) --------------------------------------------------------
void sub_40EA70() {
	int v0; // esi

	v0 = 0;
	do {
		if (*(_DWORD*)&byte_5D4594[v0 + 210164])
			sub_4208F0(*(LPVOID*)&byte_5D4594[v0 + 210164]);
		if (*(_DWORD*)&byte_5D4594[v0 + 210036])
			sub_4208F0(*(LPVOID*)&byte_5D4594[v0 + 210036]);
		if (*(LPVOID*)&byte_5D4594[v0 + 210292])
			sub_4208F0(*(LPVOID*)&byte_5D4594[v0 + 210292]);
		v0 += 4;
	} while (v0 < 128);
}

//----- (0040EAC0) --------------------------------------------------------
BOOL __cdecl sub_40EAC0(int a1, int a2, int a3) {
	int v3; // edi
	int v4; // ebx

	if (a2 == 1) {
		v3 = a1;
		v4 = sub_420BD0(*(_DWORD*)&byte_5D4594[4 * a1 + 210164]);
		if ((unsigned int)(v4 + a3 + sub_420BD0(*(_DWORD*)&byte_5D4594[4 * a1 + 210292])) > 0x7F0)
			return 0;
	} else {
		v3 = a1;
		if ((unsigned int)(a3 + sub_420BD0(*(_DWORD*)&byte_5D4594[4 * (a1 + 32 * a2) + 210036])) > 0x7F0)
			return 0;
	}
	return sub_420BC0(*(FILE**)&byte_5D4594[4 * (v3 + 32 * a2) + 210036]) < 512;
}

//----- (0040EB60) --------------------------------------------------------
BOOL __cdecl sub_40EB60(int a1, int a2, int a3) {
	int* v3;     // esi
	int v4;      // edi
	BOOL result; // eax

	v3 = (int*)&byte_5D4594[4 * (a1 + 32 * a2) + 210036];
	v4 = sub_420BD0(*v3);
	if ((unsigned int)(a3 + v4 + sub_4DFB20()) <= 0x7F0)
		result = sub_420BC0((FILE*)*v3) < 512;
	else
		result = 0;
	return result;
}

//----- (0040EBC0) --------------------------------------------------------
int __cdecl sub_40EBC0(int a1, int a2, const void* a3, int a4) {
	int v4;   // ebp
	char* v6; // eax

	v4 = *(_DWORD*)&byte_5D4594[4 * (a1 + 32 * a2) + 210036];
	if (a4 <= 0)
		return 1;
	if (!sub_40EAC0(a1, a2, a4))
		return 0;
	v6 = sub_40EC30(a1, a2, a3, a4);
	if (!v6)
		return 0;
	sub_420940(v4, (int)v6, a4, 1);
	return 1;
}

//----- (0040EC30) --------------------------------------------------------
char* __cdecl sub_40EC30(int a1, int a2, const void* a3, signed int a4) {
	char* result;        // eax
	int v5;              // ecx
	unsigned __int8* v6; // edx

	result = 0;
	if (a3 && a4 > 0) {
		v5 = *(_DWORD*)&byte_5D4594[2052 * (a1 + 32 * a2) + 78708];
		v6 = &byte_5D4594[2052 * (a1 + 32 * a2) + 76660];
		if ((unsigned int)(v5 + a4) <= 0x800) {
			result = (char*)&v6[v5];
			qmemcpy(&v6[v5], a3, a4);
			*((_DWORD*)v6 + 512) += a4;
		}
	}
	return result;
}

//----- (0040ECA0) --------------------------------------------------------
int __cdecl sub_40ECA0(int a1, int a2, const void* a3, int a4) {
	int v4;   // ebp
	char* v6; // eax

	v4 = *(_DWORD*)&byte_5D4594[4 * (a1 + 32 * a2) + 210036];
	if (a4 <= 0)
		return 1;
	if (!sub_40EB60(a1, a2, a4))
		return 0;
	v6 = sub_40EC30(a1, a2, a3, a4);
	if (!v6)
		return 0;
	sub_420940(v4, (int)v6, a4, 1);
	return 1;
}

//----- (0040ED10) --------------------------------------------------------
FILE* __cdecl sub_40ED10(int a1, int a2) {
	FILE* result; // eax

	result = *(FILE**)&byte_5D4594[4 * (a1 + 32 * a2) + 210036];
	if (result) {
		sub_420830(*(_DWORD**)&byte_5D4594[4 * (a1 + 32 * a2) + 210036]);
		result = (FILE*)sub_40ED40(a1, a2);
	}
	return result;
}

//----- (0040ED40) --------------------------------------------------------
int __cdecl sub_40ED40(int a1, int a2) {
	int result; // eax

	result = a1 + 32 * a2;
	*(_DWORD*)&byte_5D4594[2052 * (a1 + 32 * a2) + 78708] = 0;
	return result;
}

//----- (0040ED60) --------------------------------------------------------
unsigned __int8* __cdecl sub_40ED60(int a1, unsigned int a2, _DWORD* a3) {
	int*** v3;               // ebp
	int v4;                  // ebx
	int** v5;                // eax
	unsigned int v6;         // edx
	unsigned __int8* v7;     // edi
	unsigned __int8* result; // eax

	v3 = *(int****)&byte_5D4594[4 * (a1 + 32 * a2) + 210036];
	v4 = 0;
	memset(&byte_5D4594[207988], 0, 0x800u);
	v5 = sub_420A90(v3, &a2);
	if (v5) {
		v6 = a2;
		while (1) {
			qmemcpy(&byte_5D4594[v4 + 207988], v5, 4 * (v6 >> 2));
			v7 = &byte_5D4594[4 * (v6 >> 2) + 207988 + v4];
			v4 += v6;
			qmemcpy(v7, &v5[v6 >> 2], v6 & 3);
			v5 = sub_420A90(v3, &a2);
			if (!v5)
				break;
			v6 = a2;
			if (a2 + v4 > 0x800) {
				*a3 = v4;
				return &byte_5D4594[207988];
			}
		}
		*a3 = v4;
		result = &byte_5D4594[207988];
	} else {
		*a3 = 0;
		result = &byte_5D4594[207988];
	}
	return result;
}

//----- (0040EE10) --------------------------------------------------------
int __cdecl sub_40EE10(unsigned int a1, int a2, unsigned int a3) {
	unsigned __int8* v3; // eax

	v3 = sub_40ED60(a2, a3, &a3);
	if (v3) {
		sub_552640(a1, v3, a3, 0);
		sub_5528B0(a1, 1);
	}
	return 1;
}

//----- (0040EE60) --------------------------------------------------------
int sub_40EE60() {
	int i;      // esi
	int result; // eax

	for (i = 0; i < 32; ++i) {
		sub_40ED10(i, 1);
		sub_40ED10(i, 0);
		result = sub_40F020(i);
	}
	return result;
}

//----- (0040EE90) --------------------------------------------------------
FILE* __cdecl sub_40EE90(int a1) {
	int i;        // esi
	FILE* result; // eax

	for (i = 0; i < 32; ++i)
		result = sub_40ED10(i, a1);
	return result;
}

//----- (0040EEB0) --------------------------------------------------------
int** __cdecl sub_40EEB0(int a1, int a2, _DWORD* a3) {
	int** result; // eax

	result = sub_420A90(*(int****)&byte_5D4594[4 * (a1 + 32 * a2) + 210036], &a2);
	if (!result)
		return 0;
	*a3 = a2;
	return result;
}

//----- (0040EEF0) --------------------------------------------------------
BOOL __cdecl sub_40EEF0(int a1, int a2) {
	BOOL result; // eax

	if ((unsigned int)(a2 + sub_420BD0(*(_DWORD*)&byte_5D4594[4 * a1 + 210292])) <= 0x7F0)
		result = sub_420BC0(*(FILE**)&byte_5D4594[4 * a1 + 210292]) < 512;
	else
		result = 0;
	return result;
}

//----- (0040EF40) --------------------------------------------------------
int __cdecl sub_40EF40(int a1, const void* a2, int a3) {
	int v3;   // ebx
	char* v5; // eax

	v3 = *(_DWORD*)&byte_5D4594[4 * a1 + 210292];
	if (a3 <= 0)
		return 1;
	// If there are too many updates, then we may run out of space in a single
	// packet. Instead of fragmenting, we can instead send additional packets.
	if (!sub_40EEF0(a1, a3) || !(v5 = sub_40EFA0(a1, a2, a3))) {
		char* buffer = &byte_5D4594[2052 * a1 + 10996];
		unsigned int len1, len2;

		// The new update packet needs to have correct bytes at the
		// beginning. Save the length of the first two queued datas so we
		// can replay them.
		len1 = *((DWORD*)((DWORD*)(*((DWORD*)v3)) + 1));                  // head->len
		len2 = *((DWORD*)(*((DWORD*)((DWORD*)(*((DWORD*)v3)) + 3)) + 4)); // head->next->len

		// Flush old data to network.
		if (a1 == 31)
			sub_494E90(a1);
		else
			sub_5528B0(*((DWORD*)sub_417090(a1) + 516) + 1, 0);

		// Set buffer length and re-queue updates.
		*(DWORD*)(buffer + 0x800) = len1 + len2;
		sub_420940(v3, buffer, len1, 1);
		sub_420940(v3, buffer + len1, len2, 1);

		// Retry original allocation.
		v5 = sub_40EFA0(a1, a2, a3);
	}
	if (!v5)
		return 0;
	sub_420940(v3, (int)v5, a3, 1);
	return 1;
}

//----- (0040EFA0) --------------------------------------------------------
char* __cdecl sub_40EFA0(int a1, const void* a2, signed int a3) {
	char* result;        // eax
	int v4;              // ecx
	unsigned __int8* v5; // edx

	result = 0;
	if (a2 && a3 > 0) {
		v4 = *(_DWORD*)&byte_5D4594[2052 * a1 + 13044];
		v5 = &byte_5D4594[2052 * a1 + 10996];
		if ((unsigned int)(v4 + a3) <= 0x800) {
			result = (char*)&v5[v4];
			qmemcpy(&v5[v4], a2, a3);
			*((_DWORD*)v5 + 512) += a3;
		}
	}
	return result;
}

//----- (0040F000) --------------------------------------------------------
void __cdecl sub_40F000(int a1, int a2) { sub_4209E0(*(int**)&byte_5D4594[4 * a1 + 210292], a2); }

//----- (0040F020) --------------------------------------------------------
int __cdecl sub_40F020(int a1) {
	sub_420830(*(_DWORD**)&byte_5D4594[4 * a1 + 210292]);
	return sub_40F040(a1);
}

//----- (0040F040) --------------------------------------------------------
int __cdecl sub_40F040(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[2052 * a1 + 13044] = 0;
	return result;
}

//----- (0040F060) --------------------------------------------------------
int sub_40F060() {
	int i;      // esi
	int result; // eax

	for (i = 0; i < 32; ++i)
		result = sub_40F020(i);
	return result;
}

//----- (0040F080) --------------------------------------------------------
int** __cdecl sub_40F080(int a1, _DWORD* a2) {
	int** result; // eax

	result = sub_420A90(*(int****)&byte_5D4594[4 * a1 + 210292], &a1);
	if (!result)
		return 0;
	*a2 = a1;
	return result;
}

//----- (0040F0B0) --------------------------------------------------------
int __cdecl sub_40F0B0(int a1) { return sub_420BC0(*(FILE**)&byte_5D4594[4 * a1 + 210292]); }

//----- (0040F0D0) --------------------------------------------------------
int __cdecl sub_40F0D0(int a1) { return sub_420BD0(*(_DWORD*)&byte_5D4594[4 * a1 + 210292]); }

//----- (0040F0F0) --------------------------------------------------------
void __cdecl sub_40F0F0(int a1, int(__cdecl* a2)(_DWORD, int), int a3) {
	if (a2) {
		if (a3)
			sub_420A60(*(_DWORD**)&byte_5D4594[4 * a1 + 210292], a2, a3);
	}
}

//----- (0040F120) --------------------------------------------------------
unsigned __int8* __cdecl sub_40F120(int a1, _DWORD* a2) {
	// int origSize;
	int*** v2;            // ebp
	unsigned int v3;      // ebx
	int** v4;             // eax
	unsigned int v5;      // edx
	unsigned int* v6;     // edi
	unsigned int* result; // eax
	void* dest;
	void* src;
	size_t size;

	// origSize = a1;
	v2 = *(int****)&byte_5D4594[4 * a1 + 210292];
	v3 = 0;
	memset(&byte_5D4594[207988], 0, 0x800u);
	v4 = sub_420A90(v2, &a1);
	if (v4) {
		v5 = a1;
		while (1) {
			dest = &byte_5D4594[v3 + 207988];
			src = v4;
			size = 4 * (v5 >> 2);
			qmemcpy(dest, src, size);
			v6 = &byte_5D4594[4 * (v5 >> 2) + 207988 + v3];
			v3 += v5;
			qmemcpy(v6, &v4[v5 >> 2], v5 & 3);
			v4 = sub_420A90(v2, &a1);
			if (!v4)
				break;
			v5 = a1;
			if ((unsigned int)(a1 + v3) > 0x800) {
				sub_420940((int)v2, (int)v4, a1, 0);
				result = &byte_5D4594[207988];
				*a2 = v3;
				return result;
			}
		}
		*a2 = v3;
		result = &byte_5D4594[207988];
	} else {
		*a2 = 0;
		result = &byte_5D4594[207988];
	}
	return result;
}

//----- (0040F1D0) --------------------------------------------------------
wchar_t* __cdecl loadString_sub_40F1D0(char* a1, _DWORD* a2, const char* a3, int a4) {
	char* v5;        // ebx
	unsigned int v6; // ecx
	char v7;         // al
	const char* v8;  // edi
	_BYTE* v9;       // eax
	_BYTE* v10;      // esi
	int v11;         // eax

	if (a2)
		*a2 = 0;
	if (!string_entries)
		return (wchar_t*)&byte_587000[26204];
	v5 = a1;
	if (strchr(a1, ':')) {
		v8 = a3;
	} else {
		v6 = strlen(a3) - 1;
		if (a3[v6] != '\\') {
			do
				v7 = a3[--v6];
			while (v7 != '\\');
		}
		v8 = &a3[v6 + 1];
		nox_sprintf((char*)&byte_5D4594[243288], "%s:%s", v8, a1);
		v5 = (char*)&byte_5D4594[243288];
	}
	v9 = bsearch(v5, (const void*)string_entries, string_entries_cnt, sizeof(nox_string_entry),
		     (int(__cdecl*)(const void*, const void*))_strcmpi);
	v10 = v9;
	if (v9) {
		if (v9[49] <= 1u)
			v11 = 0;
		else
			v11 = nox_common_randomInt_415FA0(0, (unsigned __int8)v9[49] - 1);
		if (a2)
			*a2 = *(_DWORD*)(dword_5d4594_251508 + 4 * (v11 + *((unsigned __int16*)v10 + 25)));
		return *(wchar_t**)(dword_5d4594_251504 + 4 * (v11 + *((unsigned __int16*)v10 + 25)));
	}
	nox_missing_string* v12 = (nox_missing_string*)nox_malloc(sizeof(nox_missing_string));
	nox_swprintf(v12->data, L"MISSING:'%S'", v5, v8, a4);
	v12->next = missing_strings;
	missing_strings = v12;
	return v12->data;
}

//----- (0040F300) --------------------------------------------------------
int __cdecl nox_strman_readfile(char* a1) {
	char* v2;            // eax
	unsigned __int8 v3;  // dl
	unsigned __int8* v4; // edi
	bool v5;             // zf
	int v6;              // esi

	if (*(_DWORD*)&byte_5D4594[251512])
		return 1;
	*(_DWORD*)&byte_5D4594[251512] = 1;
	*(_DWORD*)&byte_5D4594[251480] = 0;
	if (!a1 || !*a1)
		return 0;
	strcpy((char*)&byte_5D4594[226804], a1);
	v2 = strchr((const char*)&byte_5D4594[226804], 46);
	if (v2)
		*v2 = 0;
	v3 = byte_587000[26400];
	v4 = &byte_5D4594[strlen((const char*)&byte_5D4594[226804]) + 226804];
	v5 = *(_DWORD*)&byte_5D4594[251484] == 0;
	*(_DWORD*)v4 = *(_DWORD*)&byte_587000[26396];
	v4[4] = v3;
	if (v5 || (nox_file_1 = fopen(a1, "r")) == 0) {
		if (!sub_40F7A0((char*)&byte_5D4594[226804]))
			return 0;
		v6 = 1;
	} else {
		if (!sub_40F4E0()) {
			fclose(nox_file_1);
			return 0;
		}
		fclose(nox_file_1);
		v6 = 0;
	}
	if (!dword_5d4594_251496)
		return 0;
	if (!string_entries_cnt)
		return 0;
	string_entries = (nox_string_entry*)nox_calloc(string_entries_cnt, sizeof(nox_string_entry));
	if (!string_entries)
		return 0;
	dword_5d4594_251504 = nox_calloc(*(size_t*)&dword_5d4594_251496, 4);
	if (!dword_5d4594_251504)
		return 0;
	dword_5d4594_251508 = nox_calloc(*(size_t*)&dword_5d4594_251496, 4);
	if (!dword_5d4594_251508)
		return 0;
	if (v6) {
		sub_40F830((int)&byte_5D4594[226804]);
	} else {
		nox_file_1 = fopen(a1, "r");
		if (!nox_file_1)
			return 0;
		if (!sub_40FBE0()) {
			fclose(nox_file_1);
			return 0;
		}
		fclose(nox_file_1);
	}
	qsort((void*)string_entries, string_entries_cnt, sizeof(nox_string_entry),
	      (int(__cdecl*)(const void*, const void*))_strcmpi);
	return 1;
}

//----- (0040F4E0) --------------------------------------------------------
int sub_40F4E0() {
	int v0;          // eax
	unsigned int v1; // ecx

	v0 = 0;
	string_entries_cnt = 0;
LABEL_2:
	dword_5d4594_251496 = v0;
	while (fgets(file_buffer, sizeof(file_buffer) - 1, nox_file_1)) {
		sub_40F5C0(file_buffer);
		if (file_buffer[0] == '"') {
			v1 = strlen((const char*)file_buffer);
			file_buffer[v1 + 0] = 10;
			file_buffer[v1 + 1] = 0;
			sub_40F640(nox_file_1, (char*)file_buffer + 1, (char*)&byte_5D4594[218612],
				   &byte_5D4594[222708], 4096);
			v0 = dword_5d4594_251496 + 1;
			goto LABEL_2;
		}
		if (!_strcmpi((const char*)file_buffer, "END"))
			++*(_DWORD*)&byte_5D4594[251492];
	}
	dword_5d4594_251496 += 1000;
	string_entries_cnt += 500;
	return 1;
}

//----- (0040F5C0) --------------------------------------------------------
char __cdecl sub_40F5C0(_BYTE* a1) {
	char v1;   // al
	_BYTE* i;  // edi
	int v3;    // eax
	_BYTE* v4; // edi
	_BYTE* j;  // esi
	_BYTE* k;  // esi

	v1 = *a1;
	for (i = a1; v1; v1 = *++i) {
		if (!iswspace(v1))
			break;
	}
	LOBYTE(v3) = *i;
	v4 = i + 1;
	*a1 = v3;
	for (j = a1 + 1; (_BYTE)v3; ++v4) {
		LOBYTE(v3) = *v4;
		*j++ = *v4;
	}
	for (k = j - 2; k > a1; --k) {
		LOBYTE(v3) = *k;
		if (!*k)
			break;
		v3 = iswspace((char)v3);
		if (!v3)
			break;
	}
	k[1] = 0;
	return v3;
}

//----- (0040F640) --------------------------------------------------------
char __cdecl sub_40F640(FILE* a1, char* a2, char* a3, _BYTE* a4, int a5) {
	int v5;     // eax
	char* v6;   // ebp
	BOOL v7;    // esi
	char* v8;   // edi
	char v9;    // bl
	_BYTE* v10; // esi
	char v11;   // bl
	char v12;   // al
	int v14;    // [esp+10h] [ebp-8h]
	int v15;    // [esp+14h] [ebp-4h]

	LOBYTE(v5) = a5;
	v6 = a2;
	v7 = 0;
	v8 = a3;
	v14 = 0;
	v15 = 0;
	if (a5) {
		while (v6) {
			v9 = *v6++;
			if (!v9) {
				v6 = 0;
				LOBYTE(v5) = getc(a1);
			LABEL_6:
				v9 = v5;
			}
			switch (v9) {
			case 0xff:
				return v5;
			case 10:
				v7 = 0;
				v9 = 32;
				break;
			case 92:
				v7 = !v7;
				break;
			default:
				if (v9 == 34 && !v7)
					goto LABEL_18;
				v7 = 0;
				break;
			}
			if (iswspace(v9))
				v9 = 32;
			*v8++ = v9;
			v5 = a5 - 1;
			a5 = v5;
			if (!v5)
				goto LABEL_18;
		}
		LOBYTE(v5) = getc(a1);
		goto LABEL_6;
	}
LABEL_18:
	v10 = a4;
	*v8 = 0;
	while (1) {
		if (!v6) {
			v12 = getc(a1);
			goto LABEL_23;
		}
		v11 = *v6++;
		if (!v11) {
			v6 = 0;
			v12 = getc(a1);
		LABEL_23:
			v11 = v12;
		}
		if (v11 == 10)
			break;
		if (v11 == -1)
			break;
		if (v14) {
			if (v14 == 1) {
			LABEL_32:
				if ((v11 < 97 || v11 > 122) && (v11 < 65 || v11 > 90) && (v11 < 48 || v11 > 57) &&
				    v11 != 95) {
					v14 = 2;
				} else {
					*v10++ = v11;
					++v15;
				}
			}
		} else if (!iswspace(v11) && v11 != 61) {
			v14 = 1;
			goto LABEL_32;
		}
	}
	LOBYTE(v5) = v15;
	*v10 = 0;
	if (v15) {
		LOBYTE(v5) = *(v10 - 1);
		if ((char)v5 >= 48 && (char)v5 <= 57) {
			*v10 = 101;
			v10[1] = 0;
		}
	}
	return v5;
}

//----- (0040F7A0) --------------------------------------------------------
int __cdecl sub_40F7A0(char* a1) {
	int v1;                 // edi
	FILE* v2;               // eax
	FILE* v3;               // esi
	unsigned __int8 v5[24]; // [esp+8h] [ebp-18h]

	v1 = 0;
	v2 = fopen(a1, "rb");
	v3 = v2;
	if (!v2)
		return 0;
	if (sub_40ADD0_fread((char*)v5, 0x18u, 1u, v2) == 1 && *(_DWORD*)v5 == 1129530912) {
		dword_5d4594_251496 = *(_DWORD*)&v5[12];
		string_entries_cnt = *(_DWORD*)&v5[8];
		v1 = 1;
		dword_587000_26048 = *(int*)&v5[4] < 2 ? 0 : *(_DWORD*)&v5[20];
	}
	fclose(v3);
	return v1;
}

//----- (0040F830) --------------------------------------------------------
int __cdecl sub_40F830(const char* path) {
	int v7;               // ecx
	int v8;               // eax
	int v9;               // ebx
	int v11;              // ecx
	unsigned __int8* v12; // eax
	size_t v13;           // eax
	int v16;              // [esp+10h] [ebp-28h]
	int v17;              // [esp+14h] [ebp-24h]
	int v19;              // [esp+1Ch] [ebp-1Ch]

	FILE* file = fopen(path, "rb");
	if (!file)
		return 0;

	char hbuf[20];
	if (sub_40ADD0_fread(hbuf, 20, 1, file) != 1) {
		fclose(file);
		return 0;
	}
	if (*(int*)&hbuf[4] < 2)
		fseek(file, 20, 0);
	else
		fseek(file, 24, 0);

	int i = 0;
	int previ = 0;
	int v18 = 0;
	while (sub_40ADD0_fread((char*)&v16, 4, 1, file) == 1) {
		if (v16 != 0x4C424C20) // "LBL "
		{
			fclose(file);
			return 0;
		}
		sub_40ADD0_fread((char*)&v17, 4, 1, file);
		int sz = 0;
		sub_40ADD0_fread((char*)&sz, 4, 1, file);
		if (sz > 0) {
			sub_40ADD0_fread(file_buffer, sz, 1, file);
		}
		file_buffer[sz] = 0;
		strcpy((char*)(string_entries[i].data), (const char*)file_buffer);
		if (sz > *(int*)&byte_5D4594[251480])
			*(_DWORD*)&byte_5D4594[251480] = sz;
		v7 = v18;
		v19 = 0;
		*(_BYTE*)(&string_entries[i].data[49]) = v17;
		string_entries[i].field_50 = v18;
		v8 = v17;
		if (v17 > 0) {
			v9 = 4 * v7;
			while (1) {
				sub_40ADD0_fread((char*)&v16, 4, 1, file);
				if (v16 != 0x53545220 && v16 != 0x53545257 && v16 != 0x53747220 &&
				    v16 != 0x53747257) // "STR ", "STRW", "Str ", "StrW"
				{
					fclose(file);
					return 0;
				}
				int sz = 0;
				sub_40ADD0_fread((char*)&sz, 4, 1, file);
				if (sz > 0) {
					sub_40ADD0_fread((char*)file_buffer_w, 2 * sz, 1, file);
				}
				file_buffer_w[sz] = 0;
				if (v16 == 0x53747220 || v16 == 0x53747257) // "Str " || "StrW"
				{
					v11 = *(_DWORD*)&file_buffer_w[0];
					v12 = file_buffer_w;
					if (*(_WORD*)&file_buffer_w[0]) {
						do {
							v11 = ~v11;
							*(_WORD*)v12 = v11;
							LOWORD(v11) = *((_WORD*)v12 + 1);
							v12 += 2;
						} while ((_WORD)v11);
					}
				}
				sub_40FB60(file_buffer_w);
				v13 = nox_wcslen((const wchar_t*)file_buffer_w);
				*(_DWORD*)(v9 + dword_5d4594_251504) = nox_calloc(v13 + 1, 2);
				nox_wcscpy(*(wchar_t**)(v9 + dword_5d4594_251504),
					   (const wchar_t*)file_buffer_w);
				if (v16 == 0x53545257 || v16 == 0x53747257) // "STRW" || "StrW"
				{
					int sz = 0;
					sub_40ADD0_fread((char*)&sz, 4, 1, file);
					if (sz > 0) {
						sub_40ADD0_fread(file_buffer, sz, 1, file);
					}
					file_buffer[sz] = 0;
					if (sz > 0) {
						*(_DWORD*)(v9 + dword_5d4594_251508) = nox_calloc(sz + 1, 1);
						strcpy(*(char**)(v9 + dword_5d4594_251508),
						       (const char*)file_buffer);
					}
				}
				v8 = v17;
				v9 += 4;
				if (++v19 >= v17) {
					i = previ;
					break;
				}
			}
		}
		i++;
		previ = i;
		v18 += v8;
	}
	fclose(file);
	return 1;
}

//----- (0040FB60) --------------------------------------------------------
void __cdecl sub_40FB60(wchar_t* a1) {
	wchar_t* v1;    // ecx
	wchar_t result; // ax

	v1 = a1;
	result = *a1;
	wchar_t v2 = -1; // dx
	bool v4 = 1;     // esi
	while (result) {
		if (result == ' ') {
			if (v2 != ' ' && !v4) {
				*v1 = result;
				++v1;
				v2 = result;
				v4 = 0;
			}
		} else {
			if (result != '\n' && result != '\t') {
				*v1 = result;
				++v1;
				v2 = result;
				v4 = 0;
			} else {
				if (v2 == ' ')
					--v1;
				*v1 = result;
				v2 = result;
				v4 = 1;
				++v1;
			}
		}
		++a1;
		result = *a1;
	}
	if (v2 == ' ')
		--v1;
	*v1 = 0;
}

//----- (0040FBE0) --------------------------------------------------------
int sub_40FBE0() {
	unsigned int v2; // kr08_4
	int v3;          // ebx
	int v4;          // ebp
	unsigned int v5; // ecx
	size_t v6;       // eax
	signed int v7;   // ecx
	int v8;          // eax

	int v0 = 0;
	int v1 = 0;
	int v10 = 0;
	int v11 = 0;
	do {
	LABEL_2:
		if (!fgets(file_buffer, sizeof(file_buffer), nox_file_1))
			return 1;
		sub_40F5C0(file_buffer);
	} while (*(_WORD*)file_buffer == 12079 || !file_buffer[0]);
	strcpy((char*)(string_entries[v1].data), (const char*)file_buffer);
	v2 = strlen((const char*)file_buffer) + 1;
	if ((int)(v2 - 1) > *(int*)&byte_5D4594[251480])
		*(_DWORD*)&byte_5D4594[251480] = v2 - 1;
	string_entries[v1].field_50 = v0;
	v3 = 0;
	v4 = 4 * v0;

	while (fgets(file_buffer, sizeof(file_buffer) - 1, nox_file_1)) {
		sub_40F5C0(file_buffer);
		if (file_buffer[0] == '"') {
			v5 = strlen((const char*)file_buffer);
			file_buffer[v5 + 0] = 10;
			file_buffer[v5 + 1] = 0;
			sub_40F640(nox_file_1, (char*)file_buffer + 1, (char*)&byte_5D4594[218612],
				   &byte_5D4594[222708], 4096);
			sub_40FE00(file_buffer_w, &byte_5D4594[218612]);
			sub_40FB60(file_buffer_w);
			v6 = nox_wcslen((const wchar_t*)file_buffer_w);
			*(_DWORD*)(dword_5d4594_251504 + v4) = nox_calloc(v6 + 1, 2u);
			nox_wcscpy(*(wchar_t**)(dword_5d4594_251504 + v4), (const wchar_t*)file_buffer_w);
			v7 = strlen((const char*)&byte_5D4594[222708]) + 1;
			if (v7 > 1) {
				*(_DWORD*)(dword_5d4594_251508 + v4) = nox_calloc(v7, 1u);
				strcpy(*(char**)(dword_5d4594_251508 + v4),
				       (const char*)&byte_5D4594[222708]);
			}
			++v3;
			v4 += 4;
		} else if (!_strcmpi((const char*)file_buffer, "END")) {
			*(_BYTE*)(&string_entries[v10].data[49]) = v3;
			v10++;
			v8 = v3 + v11;
			v1 = v10;
			v11 = v8;
			v0 = v8;
			goto LABEL_2;
		}
	}
	return 0;
}

//----- (0040FE00) --------------------------------------------------------
_WORD* __cdecl sub_40FE00(_WORD* a1, _BYTE* a2) {
	int v2;              // ebp
	char* v3;            // ecx
	unsigned __int8* v4; // esi
	unsigned __int8 v5;  // bl
	unsigned __int8* v6; // edi
	unsigned __int8 i;   // al
	unsigned __int8* v8; // edi
	unsigned __int8 v9;  // cl
	_WORD* result;       // eax

	v2 = 0;
	if (!*(_DWORD*)&byte_5D4594[251516]) {
		v8 = a2;
		goto LABEL_28;
	}
	v3 = 0;
	v4 = &byte_5D4594[210420];
	v5 = *a2;
	v6 = a2 + 1;
	if (!*a2)
		goto LABEL_26;
	do {
		if ((char)v5 >= 97 && (char)v5 <= 122 || (char)v5 >= 65 && (char)v5 <= 90) {
			if (!v3)
				v3 = (char*)v4;
			*v4 = v5;
			++v4;
			goto LABEL_23;
		}
		if (v3) {
			sub_40FFE0(v3, (char*)v4 - 1);
			v3 = 0;
		}
		*v4++ = v5;
		if (v5 == 92) {
			*v4++ = *v6++;
			goto LABEL_23;
		}
		if (v5 == 37) {
			for (i = *v6++; i; ++v6) {
				if ((char)i >= 97 && (char)i <= 122)
					break;
				if ((char)i >= 65 && (char)i <= 90)
					break;
				*v4 = i;
				i = *v6;
				++v4;
			}
			*v4 = i;
			++v4;
		}
	LABEL_23:
		v5 = *v6++;
	} while (v5);
	if (v3)
		sub_40FFE0(v3, (char*)v4 - 1);
LABEL_26:
	*v4 = 0;
	v8 = &byte_5D4594[210420];
LABEL_28:
	v9 = *v8;
	result = a1;
	if (*v8) {
		while (v2 != 1) {
			if (v9 == 92) {
				v2 = 1;
			} else {
			LABEL_38:
				*result = v9;
				++result;
			}
		LABEL_40:
			v9 = *++v8;
			if (!v9)
				goto LABEL_41;
		}
		v2 = 0;
		switch (v9) {
		case 0u:
			return result;
		case 34u:
			*result = 34;
			++result;
			goto LABEL_40;
		case 39u:
			*result = 39;
			++result;
			goto LABEL_40;
		case 63u:
			*result = 63;
			++result;
			goto LABEL_40;
		case 92u:
			*result = 92;
			++result;
			goto LABEL_40;
		case 110u:
			*result = 10;
			++result;
			goto LABEL_40;
		case 116u:
			*result = 9;
			++result;
			goto LABEL_40;
		default:
			goto LABEL_38;
		}
	} else {
	LABEL_41:
		*result = 0;
	}
	return result;
}

//----- (0040FFE0) --------------------------------------------------------
void __cdecl sub_40FFE0(char* a1, char* a2) {
	char* v2; // edx
	char* v3; // esi
	int v4;   // edi
	char v5;  // al
	char v6;  // cl

	v2 = a2;
	v3 = a1;
	v4 = 1;
	while (v3 < v2) {
		v5 = *v3;
		v6 = *v2;
		if (v4) {
			if (v5 >= 65 && v5 <= 90 && v6 >= 97 && v6 <= 122) {
				v5 += 32;
				v6 -= 32;
			}
			v4 = 0;
		}
		*v2-- = v5;
		*v3++ = v6;
	}
}

//----- (00410020) --------------------------------------------------------
void sub_410020() {
	LPVOID* v0; // ecx
	int i;      // esi
	LPVOID* v2; // ecx
	int j;      // esi

	v0 = *(LPVOID**)&dword_5d4594_251504;
	if (dword_5d4594_251504) {
		for (i = 0; i < *(int*)&dword_5d4594_251496; ++i) {
			if (v0[i]) {
				free(v0[i]);
				v0 = *(LPVOID**)&dword_5d4594_251504;
			}
		}
		free(v0);
	}
	v2 = *(LPVOID**)&dword_5d4594_251508;
	if (dword_5d4594_251508) {
		for (j = 0; j < *(int*)&dword_5d4594_251496; ++j) {
			if (v2[j]) {
				free(v2[j]);
				v2 = *(LPVOID**)&dword_5d4594_251508;
			}
		}
		free(v2);
	}
	if (string_entries)
		free(string_entries);

	nox_missing_string* v4 = *(nox_missing_string**)&byte_5D4594[251520];
	while (v4) {
		nox_missing_string* v5 = v4->next;
		free(v4);
		v4 = v5;
	}

	*(_DWORD*)&byte_5D4594[251520] = 0;
	*(_DWORD*)&byte_5D4594[251512] = 0;
}

//----- (004100F0) --------------------------------------------------------
int __cdecl sub_4100F0(__int16* a1) {
	__int16 v1;  // ax
	__int16* v2; // ecx

	v1 = *a1;
	v2 = a1 + 1;
	if (!*a1)
		return 1;
	while (!HIBYTE(v1)) {
		v1 = *v2;
		++v2;
		if (!v1)
			return 1;
	}
	return 0;
}

//----- (00410120) --------------------------------------------------------
BOOL sub_410120() {
	const char* v0; // eax
	BOOL result;    // eax

	v0 = *(const char**)&byte_587000[16 * dword_587000_26048 + 25900];
	if (v0)
		result = _strcmpi(v0, "e") == 0;
	else
		result = 1;
	return result;
}

//----- (00410150) --------------------------------------------------------
void sub_410150() { *(_DWORD*)&byte_5D4594[251516] = 1; }

//----- (00410160) --------------------------------------------------------
int sub_410160() {
	for (int i = 0; i < 8192; i++) {
		int v1 = dword_5D4594_251544[i];
		if (v1) {
			int v2 = dword_5d4594_251548;
			int v3 = 0;
			do {
				v3 = *(_DWORD*)(v1 + 16);
				*(_DWORD*)(v1 + 20) = v2;
				v2 = v1;
				v1 = v3;
				dword_5d4594_251548 = v2;
			} while (v3);
		}
		dword_5D4594_251544[i] = 0;
	}
	dword_5d4594_251552 = 0;
	int j = 0;
	for (j = 0; j < 1024; j += 4) {
		*(_DWORD*)(j + dword_5d4594_251556) = 0;
	}
	return j;
}

//----- (004101D0) --------------------------------------------------------
int sub_4101D0() {
	dword_5D4594_251544 = (_DWORD*)nox_calloc(8192, 4);
	if (!dword_5D4594_251544) {
		return 0;
	}
	dword_5d4594_251556 = nox_calloc(256, 4);
	if (!dword_5d4594_251556) {
		return 0;
	}
	dword_5d4594_251552 = 0;
	int v1 = 0;
	while (1) {
		_DWORD* v2 = nox_malloc(36);
		if (!v2)
			break;
		++v1;
		v2[5] = dword_5d4594_251548;
		dword_5d4594_251548 = v2;
		if (v1 >= 0x2000) {
			sub_410160();
			return 1;
		}
	}
	return 0;
}

//----- (00410250) --------------------------------------------------------
LPVOID __cdecl sub_410250(int a1, int a2) {
	LPVOID result; // eax
	int v3;        // edx
	int v4;        // eax
	int v5;        // eax
	int v6;        // esi

	if (a1 < 0 || a1 >= 256 || a2 < 0 || a2 >= 256)
		return 0;
	result = (LPVOID)nox_server_getWallAtPoint_410580(a1, a2);
	if (result)
		return result;
	v3 = dword_5d4594_251548;
	if (!dword_5d4594_251548)
		return 0;
	dword_5d4594_251548 = *(_DWORD*)(dword_5d4594_251548 + 20);
	memset((void*)v3, 0, 0x24u);
	*(_BYTE*)(v3 + 6) = a2;
	*(_BYTE*)(v3 + 5) = a1;
	v4 = ((_WORD)a2 + ((_WORD)a1 << 8)) & 0x1FFF;
	*(_DWORD*)(v3 + 16) = dword_5D4594_251544[v4];
	dword_5D4594_251544[v4] = v3;
	*(_DWORD*)(v3 + 20) = dword_5d4594_251552;
	dword_5d4594_251552 = v3;
	v5 = *(_DWORD*)(dword_5d4594_251556 + 4 * a2);
	if (v5) {
		v6 = 0;
		while (*(_BYTE*)(v3 + 5) >= *(_BYTE*)(v5 + 5)) {
			v6 = v5;
			v5 = *(_DWORD*)(v5 + 24);
			if (!v5) {
				*(_DWORD*)(v6 + 24) = v3;
				*(_DWORD*)(v3 + 24) = 0;
				return (LPVOID)v3;
			}
		}
		if (v6)
			*(_DWORD*)(v6 + 24) = v3;
		else
			*(_DWORD*)(dword_5d4594_251556 + 4 * a2) = v3;
		*(_DWORD*)(v3 + 24) = v5;
		result = (LPVOID)v3;
	} else {
		*(_DWORD*)(dword_5d4594_251556 + 4 * a2) = v3;
		*(_DWORD*)(v3 + 24) = 0;
		result = (LPVOID)v3;
	}
	return result;
}

//----- (00410360) --------------------------------------------------------
_BYTE* __cdecl sub_410360(int a1, int a2, int a3) {
	_BYTE* result; // eax
	char v4;       // cl

	result = sub_410250(a2, a3);
	if (result) {
		v4 = result[4] | 0x10;
		*((_DWORD*)result + 7) = a1;
		result[4] = v4;
	}
	return result;
}

//----- (00410390) --------------------------------------------------------
_DWORD* __cdecl sub_410390(int a1, int a2, int a3) {
	_DWORD* v3;     // esi
	_DWORD* result; // eax
	int v5;         // edx
	char v6;        // cl
	int v7[2];      // [esp+Ch] [ebp-8h]

	v3 = (_DWORD*)sub_4105E0(a2, a3);
	if (v3 || (result = sub_410250(a2, a3), (v3 = result) != 0)) {
		v5 = *(_DWORD*)(a1 + 16);
		v7[0] = *(_DWORD*)(a1 + 12);
		v6 = *((_BYTE*)v3 + 4);
		v3[8] = a1;
		v7[1] = v5;
		*((_BYTE*)v3 + 4) = v6 | 0x10;
		result = sub_4217B0((int2*)v7, 0);
		if (result || (result = sub_421990((int2*)v7, 10.0, 0)) != 0)
			*((_BYTE*)v3 + 8) = *((_BYTE*)result + 130);
		else
			*((_BYTE*)v3 + 8) = 1;
	}
	return result;
}

//----- (00410430) --------------------------------------------------------
_DWORD* __cdecl sub_410430(int a1, int a2) {
	int v2;         // ecx
	_DWORD* v3;     // esi
	_DWORD* result; // eax
	_DWORD* v5;     // ecx
	_DWORD* v6;     // edx
	int v7;         // esi
	int v8;         // eax

	v2 = ((_WORD)a2 + ((_WORD)a1 << 8)) & 0x1FFF;
	v3 = 0;
	result = (_DWORD*)(dword_5D4594_251544[v2]);
	if (result) {
		while (*((unsigned __int8*)result + 5) != a1 || *((unsigned __int8*)result + 6) != a2) {
			v3 = result;
			result = (_DWORD*)result[4];
			if (!result)
				return result;
		}
		if (v3)
			v3[4] = result[4];
		else
			dword_5D4594_251544[v2] = result[4];
		v5 = *(_DWORD**)&dword_5d4594_251552;
		v6 = 0;
		if (!dword_5d4594_251552)
			goto LABEL_24;
		do {
			if (v5 == result)
				break;
			v6 = v5;
			v5 = (_DWORD*)v5[5];
		} while (v5);
		if (v6)
			v6[5] = v5[5];
		else
		LABEL_24:
			dword_5d4594_251552 = v5[5];
		v7 = 0;
		v8 = *(_DWORD*)(dword_5d4594_251556 + 4 * a2);
		if (!v8)
			goto LABEL_25;
		do {
			if (*(unsigned __int8*)(v8 + 5) == a1 && *(unsigned __int8*)(v8 + 6) == a2)
				break;
			v7 = v8;
			v8 = *(_DWORD*)(v8 + 24);
		} while (v8);
		if (v7) {
			*(_DWORD*)(v7 + 24) = v5[6];
			result = *(_DWORD**)&dword_5d4594_251548;
			v5[5] = dword_5d4594_251548;
			dword_5d4594_251548 = v5;
		} else {
		LABEL_25:
			*(_DWORD*)(dword_5d4594_251556 + 4 * a2) = v5[6];
			result = *(_DWORD**)&dword_5d4594_251548;
			v5[5] = dword_5d4594_251548;
			dword_5d4594_251548 = v5;
		}
	}
	return result;
}

//----- (00410520) --------------------------------------------------------
int* __cdecl sub_410520(__int16 a1) {
	int* result; // eax
	int v2;      // ecx

	result = (int*)sub_410870();
	if (result) {
		while (1) {
			v2 = result[1];
			if (*(_WORD*)(v2 + 10) == a1)
				break;
			result = (int*)sub_410880(result);
			if (!result)
				return result;
		}
		*(_BYTE*)(v2 + 4) |= 0x20u;
	}
	return result;
}

//----- (00410550) --------------------------------------------------------
int __cdecl sub_410550(__int16 a1) {
	int* v1; // eax

	v1 = (int*)sub_410780();
	if (!v1)
		return 0;
	while (*(_WORD*)(v1[3] + 10) != a1) {
		v1 = (int*)sub_410790(v1);
		if (!v1)
			return 0;
	}
	return v1[3];
}

//----- (00410580) --------------------------------------------------------
int __cdecl nox_server_getWallAtPoint_410580(int a1, int a2) {
	int result; // eax
	int v3;     // eax

	if (((_BYTE)a1 + (_BYTE)a2) & 1)
		return 0;
	v3 = ((_WORD)a2 + ((_WORD)a1 << 8)) & 0x1FFF;
	*(_DWORD*)&byte_5D4594[251528] = v3;
	result = dword_5D4594_251544[v3];
	for (*(_DWORD*)&byte_5D4594[251524] = result; result; *(_DWORD*)&byte_5D4594[251524] = result) {
		if (*(unsigned __int8*)(result + 5) == a1 && *(unsigned __int8*)(result + 6) == a2 &&
		    !(*(_BYTE*)(result + 4) & 0x30)) {
			break;
		}
		result = *(_DWORD*)(result + 16);
	}
	return result;
}

//----- (004105E0) --------------------------------------------------------
int __cdecl sub_4105E0(int a1, int a2) {
	int v2;     // eax
	int result; // eax

	v2 = ((_WORD)a2 + ((_WORD)a1 << 8)) & 0x1FFF;
	*(_DWORD*)&byte_5D4594[251536] = v2;
	result = dword_5D4594_251544[v2];
	*(_DWORD*)&byte_5D4594[251532] = result;
	if (!result)
		return 0;
	while (*(unsigned __int8*)(result + 5) != a1 || *(unsigned __int8*)(result + 6) != a2 ||
	       *(_BYTE*)(result + 4) & 0x20) {
		result = *(_DWORD*)(result + 16);
		*(_DWORD*)&byte_5D4594[251532] = result;
		if (!result)
			return 0;
	}
	return result;
}

//----- (00410640) --------------------------------------------------------
int __cdecl sub_410640(void(__cdecl* a1)(int, int), int a2) {
	int result; // eax
	int v3;     // esi

	result = dword_5d4594_251552;
	if (dword_5d4594_251552) {
		do {
			v3 = *(_DWORD*)(result + 20);
			if (!(*(_BYTE*)(result + 4) & 0x30))
				a1(result, a2);
			result = v3;
		} while (v3);
	}
	return result;
}

//----- (00410670) --------------------------------------------------------
int __cdecl sub_410670(void(__cdecl* a1)(int, int), int a2) {
	int result; // eax
	int v3;     // esi

	result = dword_5d4594_251552;
	if (dword_5d4594_251552) {
		do {
			v3 = *(_DWORD*)(result + 20);
			if (*(_BYTE*)(result + 4) & 0x20)
				a1(result, a2);
			result = v3;
		} while (v3);
	}
	return result;
}

//----- (004106A0) --------------------------------------------------------
int __cdecl sub_4106A0(int a1) {
	int result; // eax

	if (a1 < 0 || a1 >= 256)
		result = 0;
	else
		result = *(_DWORD*)(dword_5d4594_251556 + 4 * a1);
	return result;
}

//----- (004106C0) --------------------------------------------------------
void sub_4106C0() {
	_DWORD* v1; // eax
	_DWORD* v2; // esi
	_DWORD* v3; // eax
	_DWORD* v4; // esi

	for (int i = 0; i < 8192; i++) {
		v1 = dword_5D4594_251544[i];
		if (v1) {
			do {
				v2 = (_DWORD*)v1[4];
				free(v1);
				v1 = v2;
			} while (v2);
		}
	}
	v3 = *(_DWORD**)&dword_5d4594_251548;
	if (dword_5d4594_251548) {
		do {
			v4 = (_DWORD*)v3[5];
			free(v3);
			v3 = v4;
		} while (v4);
	}
	free(dword_5D4594_251544);
	free(*(LPVOID*)&dword_5d4594_251556);
}

//----- (00410730) --------------------------------------------------------
_DWORD* sub_410730() {
	_DWORD* result; // eax
	_DWORD* v1;     // esi

	result = *(_DWORD**)&dword_5d4594_251560;
	if (dword_5d4594_251560) {
		do {
			v1 = (_DWORD*)*result;
			free(result);
			result = v1;
		} while (v1);
		dword_5d4594_251560 = 0;
	} else {
		dword_5d4594_251560 = 0;
	}
	return result;
}

//----- (00410760) --------------------------------------------------------
_DWORD* __cdecl sub_410760(_DWORD* a1) {
	_DWORD* result; // eax

	result = a1;
	*a1 = dword_5d4594_251560;
	dword_5d4594_251560 = a1;
	return result;
}

//----- (00410780) --------------------------------------------------------
LPVOID sub_410780() { return *(LPVOID*)&dword_5d4594_251560; }

//----- (00410790) --------------------------------------------------------
int __cdecl sub_410790(int* a1) {
	int result; // eax

	if (a1)
		result = *a1;
	else
		result = 0;
	return result;
}

//----- (004107A0) --------------------------------------------------------
int* __cdecl sub_4107A0(LPVOID lpMem) {
	int* result; // eax
	int* v2;     // esi

	result = *(int**)&dword_5d4594_251560;
	v2 = 0;
	if (dword_5d4594_251560) {
		while (result != lpMem) {
			v2 = result;
			result = (int*)sub_410790(result);
			if (!result)
				return result;
		}
		if (result == *(int**)&dword_5d4594_251560)
			dword_5d4594_251560 = sub_410790(result);
		else
			*v2 = sub_410790(result);
		free(lpMem);
	}
	return result;
}

//----- (00410810) --------------------------------------------------------
_DWORD* sub_410810() {
	_DWORD* result; // eax
	_DWORD* v1;     // esi

	result = *(_DWORD**)&dword_5d4594_251564;
	if (dword_5d4594_251564) {
		do {
			v1 = (_DWORD*)*result;
			free(result);
			result = v1;
		} while (v1);
		dword_5d4594_251564 = 0;
	} else {
		dword_5d4594_251564 = 0;
	}
	return result;
}

//----- (00410840) --------------------------------------------------------
_DWORD* __cdecl sub_410840(int a1) {
	_DWORD* result; // eax

	result = nox_calloc(1u, 8u);
	result[1] = a1;
	*result = dword_5d4594_251564;
	dword_5d4594_251564 = result;
	return result;
}

//----- (00410870) --------------------------------------------------------
LPVOID sub_410870() { return *(LPVOID*)&dword_5d4594_251564; }

//----- (00410880) --------------------------------------------------------
int __cdecl sub_410880(int* a1) {
	int result; // eax

	if (a1)
		result = *a1;
	else
		result = 0;
	return result;
}

//----- (00410890) --------------------------------------------------------
int* __cdecl sub_410890(int* lpMem) {
	int* result; // eax
	int* v2;     // esi

	result = *(int**)&dword_5d4594_251564;
	v2 = 0;
	if (dword_5d4594_251564) {
		while (result != lpMem) {
			v2 = result;
			result = (int*)sub_410880(result);
			if (!result)
				return result;
		}
		if (result == *(int**)&dword_5d4594_251564)
			dword_5d4594_251564 = sub_410880(result);
		else
			*v2 = sub_410880(result);
		free(lpMem);
	}
	return result;
}

//----- (00410900) --------------------------------------------------------
int __cdecl sub_410900(_DWORD* a1, char* a2) {
	_DWORD* v3;           // esi
	char* v4;             // ebx
	unsigned __int8* v5;  // ebp
	int* v6;              // eax
	int v7;               // ecx
	int* v8;              // eax
	int v9;               // ecx
	int* v10;             // eax
	int v11;              // ecx
	_BYTE* v12;           // eax
	_BYTE* v13;           // eax
	int v14;              // ebp
	char v15;             // dl
	int v16;              // edi
	unsigned __int8* v17; // eax
	unsigned __int8* v18; // eax
	unsigned __int8* v19; // eax
	unsigned __int8* v20; // eax
	unsigned __int8* v21; // eax
	unsigned __int8 v22;  // cl
	int v23;              // eax
	int v24;              // ebp
	int v25;              // eax
	int v26;              // edi
	unsigned int v27;     // ecx
	int* v28;             // eax
	int v29;              // edx
	int* v30;             // eax
	int v31;              // edx
	int* v32;             // eax
	int v33;              // edx
	int v34;              // eax
	unsigned __int8* v35; // eax
	int* v36;             // eax
	int v37;              // ecx
	_DWORD* v38;          // [esp-4h] [ebp-24h]
	int v39;              // [esp+10h] [ebp-10h]
	int v40;              // [esp+14h] [ebp-Ch]
	int v41;              // [esp+18h] [ebp-8h]
	int i;                // [esp+1Ch] [ebp-4h]
	unsigned __int8 v43;  // [esp+24h] [ebp+4h]
	unsigned __int8 v44;  // [esp+24h] [ebp+4h]
	unsigned __int8 v45;  // [esp+24h] [ebp+4h]
	unsigned __int8 v46;  // [esp+24h] [ebp+4h]
	unsigned __int8 v47;  // [esp+24h] [ebp+4h]
	unsigned int v48;     // [esp+28h] [ebp+8h]
	unsigned int v49;     // [esp+28h] [ebp+8h]

	if (dword_5d4594_251540 >= 80)
		return 0;
	v3 = a1;
	v4 = a2;
	v38 = a1;
	v5 = (unsigned __int8*)(a1[2] + 4);
	a1[2] = v5;
	v43 = *v5;
	v3[2] = v5 + 1;
	nox_memfile_read(a2, 1u, v43, (int)v38);
	a2[v43] = 0;
	strncpy((char*)&byte_5D4594[12332 * dword_5d4594_251540 + 2692748], a2, 0x1Fu);
	v6 = (int*)v3[2];
	v7 = *v6;
	v3[2] = v6 + 1;
	*(_DWORD*)&byte_5D4594[12332 * dword_5d4594_251540 + 2692780] = v7;
	v8 = (int*)v3[2];
	v9 = *v8;
	v3[2] = v8 + 1;
	*(_WORD*)&byte_5D4594[12332 * dword_5d4594_251540 + 2692784] = v9;
	v10 = (int*)v3[2];
	v11 = *v10;
	v3[2] = v10 + 1;
	*(_WORD*)&byte_5D4594[12332 * dword_5d4594_251540 + 2692786] = v11;
	v12 = (_BYTE*)v3[2];
	LOBYTE(v11) = *v12;
	v3[2] = v12 + 1;
	byte_5D4594[12332 * dword_5d4594_251540 + 2692788] = v11;
	v13 = (_BYTE*)v3[2];
	LOBYTE(v11) = *v13;
	v3[2] = v13 + 1;
	byte_5D4594[12332 * dword_5d4594_251540 + 2692789] = v11;
	sub_40AD60((char*)&v39, 1, 1, v3);
	v14 = 0;
	v15 = v39;
	v16 = 12332 * dword_5d4594_251540;
	byte_5D4594[v16 + 2692790] = v39;
	memset(&byte_5D4594[v16 + 2692791], 0, 0x200u);
	if (v15) {
		v48 = 0;
		while ((int)v48 < 512) {
			v17 = (unsigned __int8*)v3[2];
			v44 = *v17;
			v3[2] = v17 + 1;
			nox_memfile_read(v4, 1u, v44, (int)v3);
			v4[v44] = 0;
			strncpy((char*)&byte_5D4594[12332 * dword_5d4594_251540 + 2692791 + v48], v4, 0x40u);
			++v14;
			v48 += 64;
			if (v14 >= (unsigned __int8)v39)
				goto LABEL_7;
		}
		return 0;
	}
LABEL_7:
	v18 = (unsigned __int8*)v3[2];
	v45 = *v18;
	v3[2] = v18 + 1;
	nox_memfile_read(v4, 1u, v45, (int)v3);
	v4[v45] = 0;
	strncpy((char*)&byte_5D4594[12332 * dword_5d4594_251540 + 2693303], v4, 0x40u);
	v19 = (unsigned __int8*)v3[2];
	v46 = *v19;
	v3[2] = v19 + 1;
	nox_memfile_read(v4, 1u, v46, (int)v3);
	v4[v46] = 0;
	strncpy((char*)&byte_5D4594[12332 * dword_5d4594_251540 + 2693367], v4, 0x40u);
	v20 = (unsigned __int8*)v3[2];
	v47 = *v20;
	v3[2] = v20 + 1;
	nox_memfile_read(v4, 1u, v47, (int)v3);
	v4[v47] = 0;
	strncpy((char*)&byte_5D4594[12332 * dword_5d4594_251540 + 2693431], v4, 0x40u);
	v21 = (unsigned __int8*)v3[2];
	v22 = *v21;
	v3[2] = v21 + 1;
	v23 = 12332 * dword_5d4594_251540;
	byte_5D4594[v23 + 2693497] = v22;
	v24 = 0;
	memset(&byte_5D4594[v23 + 2701180], 0, 0xF00u);
	v49 = 0;
	do {
		sub_40AD60((char*)&v40, 1, 1, v3);
		v25 = 0;
		v41 = 0;
		for (i = (unsigned __int8)v40; v41 < i; ++v41) {
			v26 = 0;
			v27 = 8 * (v25 + v49);
			do {
				byte_5D4594[12332 * dword_5d4594_251540 + 2705020 + v26 + v24] = v40;
				v28 = (int*)v3[2];
				v29 = *v28;
				v3[2] = v28 + 1;
				*(_DWORD*)&byte_5D4594[12332 * dword_5d4594_251540 + 2693500 + v27] = v29;
				v30 = (int*)v3[2];
				v31 = *v30;
				v3[2] = v30 + 1;
				*(_DWORD*)&byte_5D4594[12332 * dword_5d4594_251540 + 2693504 + v27] = v31;
				v32 = (int*)v3[2];
				v33 = *v32;
				v34 = (int)(v32 + 1);
				v3[2] = v34;
				if (v33 == -1) {
					v35 = (unsigned __int8*)(v34 + 1);
					v3[2] = v35;
					v3[2] = &v35[*v35 + 1];
				}
				v26 += 15;
				v27 += 1920;
			} while (v26 < 60);
			v25 = v41 + 1;
		}
		++v24;
		v49 += 16;
	} while ((int)v49 < 240);
	v36 = (int*)v3[2];
	v37 = *v36;
	v3[2] = v36 + 1;
	if (v37 != 0x454E4420) // 'END '
		return 0;
	++dword_5d4594_251540;
	return 1;
}

//----- (00410D40) --------------------------------------------------------
char* __cdecl sub_410D40(int a1) { return (char*)&byte_5D4594[12332 * a1 + 2692748]; }

//----- (00410D60) --------------------------------------------------------
int __cdecl sub_410D60(const char* a1) {
	int v1;        // ebp
	const char* i; // edi

	v1 = 0;
	if (*(int*)&dword_5d4594_251540 <= 0)
		return -1;
	for (i = (const char*)&byte_5D4594[2692748]; strcmp(a1, i); i += 12332) {
		if (++v1 >= *(int*)&dword_5d4594_251540)
			return -1;
	}
	return v1;
}

//----- (00410DD0) --------------------------------------------------------
unsigned __int8 __cdecl sub_410DD0(int a1, int a2, int a3) {
	return byte_5D4594[12332 * a1 + 2705020 + 12 * a3 + 3 * a3 + a2];
}

//----- (00410E00) --------------------------------------------------------
unsigned __int8 __cdecl sub_410E00(int a1) { return byte_5D4594[12332 * a1 + 2693497]; }

//----- (00410E20) --------------------------------------------------------
unsigned __int8 __cdecl sub_410E20(int a1) { return byte_5D4594[12332 * a1 + 2692789]; }

//----- (00410E40) --------------------------------------------------------
unsigned __int8 __cdecl sub_410E40(int a1) { return byte_5D4594[12332 * a1 + 2692790]; }

//----- (00410E60) --------------------------------------------------------
char* __cdecl sub_410E60(int a1, int a2) {
	char* result; // eax

	result = (char*)&byte_587000[26432];
	if (strlen((const char*)&byte_5D4594[12332 * a1 + 2692791 + 64 * a2]))
		result = (char*)&byte_5D4594[12332 * a1 + 2692791 + 64 * a2];
	return result;
}

//----- (00410EA0) --------------------------------------------------------
char* __cdecl sub_410EA0(int a1) {
	char* result; // eax

	result = (char*)&byte_587000[26440];
	if (strlen((const char*)&byte_5D4594[12332 * a1 + 2693431]))
		result = (char*)&byte_5D4594[12332 * a1 + 2693431];
	return result;
}

//----- (00410EE0) --------------------------------------------------------
char* __cdecl sub_410EE0(int a1) {
	char* result; // eax

	result = (char*)&byte_587000[26456];
	if (strlen((const char*)&byte_5D4594[12332 * a1 + 2693303]))
		result = (char*)&byte_5D4594[12332 * a1 + 2693303];
	return result;
}

//----- (00410F20) --------------------------------------------------------
char* __cdecl sub_410F20(int a1) {
	char* result; // eax

	result = (char*)&byte_587000[26472];
	if (strlen((const char*)&byte_5D4594[12332 * a1 + 2693367]))
		result = (char*)&byte_5D4594[12332 * a1 + 2693367];
	return result;
}

//----- (00410F60) --------------------------------------------------------
int sub_410F60_init() {
	ptr_5D4594_2650668 = nox_calloc(ptr_5D4594_2650668_cap, sizeof(void*));
	if (!ptr_5D4594_2650668)
		return 0;

	for (int i = 0; i < ptr_5D4594_2650668_cap; i++) {
		ptr_5D4594_2650668[i] =
		    (obj_5D4594_2650668_t*)nox_calloc(ptr_5D4594_2650668_cap, sizeof(obj_5D4594_2650668_t));
		if (!ptr_5D4594_2650668[i])
			return 0;
	}
	return 1;
}

//----- (00410FC0) --------------------------------------------------------
void sub_410FC0_free() {
	for (int i = 0; i < ptr_5D4594_2650668_cap; i++) {
		obj_5D4594_2650668_t* ptr = ptr_5D4594_2650668[i];
		if (ptr)
			free(ptr);
	}
}

//----- (00410FF0) --------------------------------------------------------
int sub_410FF0() {
	int v0;     // edi
	int v2;     // esi
	char v3;    // al
	_DWORD* v5; // eax
	int v6;     // ecx
	_DWORD* v7; // eax
	int v8;     // ecx

	v0 = 0;
	for (int i = 0; i < ptr_5D4594_2650668_cap; i++) {
		for (int j = 0; j < ptr_5D4594_2650668_cap; j++) {
			obj_5D4594_2650668_t* obj = &ptr_5D4594_2650668[j][i];
			v3 = *(_BYTE*)(&obj->field_0);
			if (v3 & 1) {
				if (obj->field_1 >= *(int*)&dword_5d4594_251568) {
					v0 = 1;
					obj->field_1 = 0;
				}
				if (obj->field_2 >=
				    (int)*(unsigned __int16*)&byte_5D4594[60 * obj->field_1 + 2682232]) {
					v0 = 1;
					obj->field_2 = 0;
				}
				v5 = obj->field_5;
				while (v5) {
					v6 = v5[2];
					if (v6 >= *(int*)&dword_5d4594_251572 ||
					    v5[3] >= (int)*(unsigned __int16*)&byte_5D4594[60 * v6 + 2678392]) {
						v0 = 1;
						obj->field_5 = v5[4];
						sub_4221E0((int)v5);
						v5 = obj->field_5;
					} else {
						v5 = (_DWORD*)v5[4];
					}
				}
			}
			if (v3 & 2) {
				if (obj->field_6 >= *(int*)&dword_5d4594_251568) {
					v0 = 1;
					obj->field_6 = 0;
				}
				if (obj->field_7 >=
				    (int)*(unsigned __int16*)&byte_5D4594[60 * obj->field_6 + 2682232]) {
					v0 = 1;
					obj->field_7 = 0;
				}
				v7 = obj->field_10;
				while (v7) {
					v8 = v7[2];
					if (v8 >= *(int*)&dword_5d4594_251572 ||
					    v7[3] >= (int)*(unsigned __int16*)&byte_5D4594[60 * v8 + 2678392]) {
						v0 = 1;
						obj->field_10 = v7[4];
						sub_4221E0((int)v7);
						v7 = obj->field_10;
					} else {
						v7 = (_DWORD*)v7[4];
					}
				}
			}
		}
	}
	return v0;
}

//----- (00411160) --------------------------------------------------------
int __cdecl sub_411160(float2* a1) {
	float v12 = (a1->field_0 + 11.5) * 0.021739131;
	float v13 = (a1->field_4 + 11.5) * 0.021739131;

	int i = nox_float2int(v12);
	int j = nox_float2int(v13);

	float v14 = a1->field_0 + 11.5;
	float v15 = a1->field_4 + 11.5;

	int v4 = nox_float2int(v14) % 46;
	int v5 = nox_float2int(v15) % 46;

	if (i - 1 <= 0 || i >= 127 || j - 1 <= 0 || j >= 127)
		return -1;

	int result = 0;
	int v16[2] = {0};
	if (v4 <= v5) {
		if (46 - v4 <= v5) {
			obj_5D4594_2650668_t* obj = &ptr_5D4594_2650668[i][j];
			result = obj->field_6;
			if (obj->field_10) {
				v16[0] = v4;
				v16[1] = v5 - 23;
				result = sub_411350(obj->field_10, v16, result);
			}
		} else {
			obj_5D4594_2650668_t* obj = &ptr_5D4594_2650668[i - 1][j];
			result = obj->field_1;
			if (obj->field_5) {
				v16[1] = v5;
				v16[0] = v4 + 23;
				result = sub_411350(obj->field_5, v16, result);
			}
		}
	} else if (46 - v4 <= v5) {
		obj_5D4594_2650668_t* obj = &ptr_5D4594_2650668[i][j];
		result = obj->field_1;
		if (obj->field_5) {
			v16[1] = v5;
			v16[0] = v4 - 23;
			result = sub_411350(obj->field_5, v16, result);
		}
	} else {
		obj_5D4594_2650668_t* obj = &ptr_5D4594_2650668[i][j - 1];
		result = obj->field_6;
		if (obj->field_10) {
			v16[0] = v4;
			v16[1] = v5 + 23;
			result = sub_411350(obj->field_10, v16, result);
		}
	}
	return result;
}

//----- (00411350) --------------------------------------------------------
int __cdecl sub_411350(int* a1, int* a2, int a3) {
	int* v3; // esi
	int v4;  // ebx
	int v5;  // eax

	v3 = a1;
	if (!a1)
		return a3;
	v4 = a3;
	do {
		v5 = sub_411490(v3[2], v3[3]);
		if (sub_4113A0(a2, v5))
			v4 = *v3;
		v3 = (int*)v3[4];
	} while (v3);
	return v4;
}

//----- (004113A0) --------------------------------------------------------
int __cdecl sub_4113A0(int* a1, int a2) {
	int v2 = *a1;
	int v3 = a1[1];

	bool v4;
	bool v5;
	if (*a1 == v3) {
		v4 = 1;
		v5 = 1;
	} else if (*a1 >= v3) {
		v4 = 1;
		v5 = 0;
	} else {
		v4 = 0;
		v5 = 1;
	}

	bool v6;
	bool v7;
	if (v2 == 46 - v3) {
		v6 = 1;
		v7 = 1;
	} else if (v2 >= 46 - v3) {
		v6 = 1;
		v7 = 0;
	} else {
		v6 = 0;
		v7 = 1;
	}

	switch (a2) {
	case 0:
		if (!v5 || !v6)
			return 0;
		return 1;
	case 1:
		if (!v5)
			return 0;
		return 1;
	case 2:
		if (!v5 || !v7)
			return 0;
		return 1;
	case 3:
		if (!v6)
			return 0;
		return 1;
	case 4:
		if (!v7)
			return 0;
		return 1;
	case 5:
		if (!v6 || !v4)
			return 0;
		return 1;
	case 6:
		if (!v4)
			return 0;
		return 1;
	case 7:
		if (!v4 || !v7)
			return 0;
		return 1;
	case 8:
		if (v5)
			return 1;
		if (!v6)
			return 0;
		return 1;
	case 9:
		if (!v5 && !v7)
			return 0;
		return 1;
	case 10:
		if (!v4 && !v7)
			return 0;
		return 1;
	case 11:
		if (v4)
			return 1;
		if (!v6)
			return 0;
		return 1;
	}
	return 0;
}

//----- (00411490) --------------------------------------------------------
int __cdecl sub_411490(int a1, int a2) {
	int v2; // ecx
	int v3; // edx
	int v5; // esi

	v2 = byte_5D4594[60 * a1 + 2678400];
	v3 = byte_5D4594[60 * a1 + 2678401];
	if (v2 == 3 && v3 == 3)
		return a2;
	if (!a2) {
		return 0;
	}
	if (a2 <= v2 - 2) {
		return 1;
	}
	if (a2 == v2 - 1) {
		return 2;
	}
	v5 = v2 + 2 * v3 - 4;
	if (a2 < v5) {
		return ((((unsigned __int8)v2 ^ (unsigned __int8)a2) & 1) != 0) + 3;
	}
	if (a2 == v5) {
		return 5;
	} else if (a2 > 2 * (v3 + v2) - 6) {
		if (a2 == 2 * (v3 + v2) - 5)
			return 7;
		return a2 + 2 * (6 - v3 - v2);
	}
	return 6;
}

//----- (00411540) --------------------------------------------------------
int __cdecl sub_411540(int a1, _BYTE* a2) {
	int v3;               // esi
	unsigned __int8* v4;  // edi
	int v5;               // eax
	char* v6;             // eax
	char v7;              // cl
	char v8;              // dl
	char v9;              // dl
	int v10;              // edi
	int* v11;             // eax
	int v12;              // ecx
	int* v13;             // eax
	int v14;              // ecx
	_BYTE* v15;           // eax
	_BYTE* v16;           // eax
	_BYTE* v17;           // eax
	_BYTE* v18;           // eax
	int v19;              // eax
	_BYTE* v20;           // eax
	int v21;              // eax
	int v22;              // ecx
	int v23;              // edx
	int v24;              // ecx
	int* v25;             // eax
	int v26;              // ecx
	unsigned __int8* v27; // edi
	int v28;              // [esp-10h] [ebp-38h]
	_BYTE v29[6];         // [esp+0h] [ebp-28h]
	int v30;              // [esp+0h] [ebp-28h]
	char v31[32];         // [esp+8h] [ebp-20h]
	unsigned __int8 v32;  // [esp+2Ch] [ebp+4h]
	unsigned __int8 v33;  // [esp+2Ch] [ebp+4h]

	if (*(int*)&dword_5d4594_251568 >= 176)
		return 0;
	v3 = a1;
	v28 = a1;
	v4 = (unsigned __int8*)(*(_DWORD*)(a1 + 8) + 4);
	*(_DWORD*)(a1 + 8) = v4;
	v32 = *v4;
	*(_DWORD*)(v3 + 8) = v4 + 1;
	nox_memfile_read(v31, 1u, v32, v28);
	v5 = 3 * dword_5d4594_251568;
	v31[v32] = 0;
	strncpy((char*)&byte_5D4594[20 * v5 + 2682188], v31, 0x1Fu);
	v6 = *(char**)(v3 + 8);
	v7 = *v6++;
	*(_DWORD*)(v3 + 8) = v6;
	v29[0] = v7;
	v8 = *v6++;
	v29[1] = v8;
	*(_DWORD*)(v3 + 8) = v6;
	v9 = *v6;
	v29[2] = *v6;
	*(_DWORD*)(v3 + 8) = v6 + 1;
	if (v7 != -1 || v29[1] || v9 != -1) {
		v10 = 60 * dword_5d4594_251568;
		*(_DWORD*)&byte_5D4594[v10 + 2682236] = sub_4344A0(*(int*)v29, *(int*)&v29[1], *(int*)&v29[2]);
	} else {
		v10 = 60 * dword_5d4594_251568;
		*(_DWORD*)&byte_5D4594[60 * dword_5d4594_251568 + 2682236] = 2147483648;
	}
	byte_5D4594[v10 + 2682246] = 0;
	if (sub_4117E0((const char*)&byte_5D4594[v10 + 2682188]) == 1)
		byte_5D4594[60 * dword_5d4594_251568 + 2682246] |= 1u;
	v11 = *(int**)(v3 + 8);
	v12 = *v11;
	*(_DWORD*)(v3 + 8) = v11 + 1;
	*(_DWORD*)&byte_5D4594[60 * dword_5d4594_251568 + 2682224] = v12;
	v13 = *(int**)(v3 + 8);
	v14 = *v13;
	*(_DWORD*)(v3 + 8) = v13 + 1;
	*(_DWORD*)&byte_5D4594[60 * dword_5d4594_251568 + 2682228] = v14;
	v15 = *(_BYTE**)(v3 + 8);
	LOBYTE(v14) = *v15;
	*(_DWORD*)(v3 + 8) = v15 + 1;
	byte_5D4594[60 * dword_5d4594_251568 + 2682245] = v14;
	v16 = *(_BYTE**)(v3 + 8);
	LOBYTE(v14) = *v16;
	*(_DWORD*)(v3 + 8) = v16 + 1;
	byte_5D4594[60 * dword_5d4594_251568 + 2682241] = v14;
	v17 = *(_BYTE**)(v3 + 8);
	LOBYTE(v14) = *v17;
	*(_DWORD*)(v3 + 8) = v17 + 1;
	byte_5D4594[60 * dword_5d4594_251568 + 2682240] = v14;
	v18 = *(_BYTE**)(v3 + 8);
	LOBYTE(v14) = *v18;
	*(_DWORD*)(v3 + 8) = v18 + 1;
	v19 = 60 * dword_5d4594_251568;
	byte_5D4594[v19 + 2682242] = v14;
	*(_WORD*)&byte_5D4594[v19 + 2682234] = 0;
	v20 = *(_BYTE**)(v3 + 8);
	LOBYTE(v14) = *v20;
	*(_DWORD*)(v3 + 8) = v20 + 1;
	v21 = 60 * dword_5d4594_251568;
	byte_5D4594[v21 + 2682243] = v14;
	byte_5D4594[v21 + 2682244] = v14;
	*(_WORD*)&byte_5D4594[v21 + 2682232] = byte_5D4594[v21 + 2682240] * byte_5D4594[v21 + 2682241];
	v22 = byte_5D4594[v21 + 2682241] * byte_5D4594[v21 + 2682242];
	v23 = byte_5D4594[v21 + 2682240];
	*(_DWORD*)&byte_5D4594[v21 + 2682220] = 0;
	v24 = v23 * v22;
	if (v24 > 0) {
		v30 = v24;
		do {
			v25 = *(int**)(v3 + 8);
			v26 = *v25;
			*(_DWORD*)(v3 + 8) = v25 + 1;
			*a2 = byte_5D4594[251576];
			if (v26 == -1) {
				v27 = (unsigned __int8*)(*(_DWORD*)(v3 + 8) + 1);
				*(_DWORD*)(v3 + 8) = v27;
				v33 = *v27;
				*(_DWORD*)(v3 + 8) = v27 + 1;
				nox_memfile_read(a2, 1u, v33, v3);
				a2[v33] = 0;
			}
			--v30;
		} while (v30);
	}
	++dword_5d4594_251568;
	return 1;
}
// 411618: variable 'v29' is possibly undefined
// 411540: using guessed type char var_20[32];

//----- (004117E0) --------------------------------------------------------
int __cdecl sub_4117E0(const char* a1) {
	const char* v1;      // eax
	unsigned __int8* v2; // edi

	v1 = *(const char**)&byte_587000[26488];
	if (!*(_DWORD*)&byte_587000[26488])
		return 0;
	v2 = &byte_587000[26488];
	while (strcmp(v1, a1)) {
		v1 = (const char*)*((_DWORD*)v2 + 1);
		v2 += 4;
		if (!v1)
			return 0;
	}
	return 1;
}

//----- (00411850) --------------------------------------------------------
int __cdecl sub_411850(int a1, _BYTE* a2) {
	int v3;               // ebp
	unsigned __int8* v4;  // eax
	int v5;               // eax
	int* v6;              // eax
	int v7;               // ecx
	int* v8;              // eax
	int v9;               // ecx
	_BYTE* v10;           // eax
	_BYTE* v11;           // eax
	int v12;              // eax
	_BYTE* v13;           // eax
	int v14;              // eax
	_BYTE* v15;           // eax
	unsigned __int8* v16; // eax
	unsigned __int8 v17;  // dl
	unsigned __int8* v18; // eax
	unsigned __int8 v19;  // bl
	int v20;              // ecx
	int v21;              // ebx
	int* v22;             // eax
	int v23;              // ecx
	unsigned __int8* v24; // esi
	int* v25;             // eax
	int v26;              // ecx
	int v27;              // [esp-4h] [ebp-3Ch]
	unsigned __int8 v28;  // [esp+14h] [ebp-24h]
	char v29[32];         // [esp+18h] [ebp-20h]
	unsigned __int8 v30;  // [esp+3Ch] [ebp+4h]
	unsigned __int8 v31;  // [esp+3Ch] [ebp+4h]

	if (*(int*)&dword_5d4594_251572 >= 64)
		return 0;
	v3 = a1;
	v27 = a1;
	v4 = (unsigned __int8*)(*(_DWORD*)(a1 + 8) + 4);
	*(_DWORD*)(a1 + 8) = v4;
	v30 = *v4;
	*(_DWORD*)(v3 + 8) = v4 + 1;
	nox_memfile_read(v29, 1u, v30, v27);
	v5 = 3 * dword_5d4594_251572;
	v29[v30] = 0;
	strcpy((char*)&byte_5D4594[20 * v5 + 2678348], v29);
	v6 = *(int**)(v3 + 8);
	v7 = *v6;
	*(_DWORD*)(v3 + 8) = v6 + 1;
	*(_DWORD*)&byte_5D4594[60 * dword_5d4594_251572 + 2678384] = v7;
	v8 = *(int**)(v3 + 8);
	v9 = *v8;
	*(_DWORD*)(v3 + 8) = v8 + 1;
	*(_DWORD*)&byte_5D4594[60 * dword_5d4594_251572 + 2678388] = v9;
	v10 = *(_BYTE**)(v3 + 8);
	LOBYTE(v9) = *v10;
	*(_DWORD*)(v3 + 8) = v10 + 1;
	byte_5D4594[60 * dword_5d4594_251572 + 2678405] = v9;
	v11 = *(_BYTE**)(v3 + 8);
	LOBYTE(v9) = *v11;
	*(_DWORD*)(v3 + 8) = v11 + 1;
	v28 = v9;
	v12 = 60 * dword_5d4594_251572;
	byte_5D4594[v12 + 2678402] = v9;
	*(_WORD*)&byte_5D4594[v12 + 2678394] = 0;
	v13 = *(_BYTE**)(v3 + 8);
	LOBYTE(v9) = *v13;
	*(_DWORD*)(v3 + 8) = v13 + 1;
	v14 = 60 * dword_5d4594_251572;
	byte_5D4594[v14 + 2678403] = v9;
	byte_5D4594[v14 + 2678404] = v9;
	v15 = *(_BYTE**)(v3 + 8);
	LOBYTE(v9) = *v15;
	v16 = v15 + 1;
	*(_DWORD*)(v3 + 8) = v16;
	if ((_BYTE)v9 == 1)
		return 0;
	v17 = *v16;
	*(_DWORD*)(v3 + 8) = v16 + 1;
	byte_5D4594[60 * dword_5d4594_251572 + 2678401] = v17;
	v18 = *(unsigned __int8**)(v3 + 8);
	v19 = *v18;
	*(_DWORD*)(v3 + 8) = v18 + 1;
	v20 = 60 * dword_5d4594_251572;
	byte_5D4594[v20 + 2678400] = v19;
	*(_WORD*)&byte_5D4594[v20 + 2678392] = 2 * (v17 + v19);
	*(_DWORD*)&byte_5D4594[v20 + 2678380] = 0;
	if (2 * v28 * (v17 + v19) > 0) {
		v21 = 2 * v28 * (v17 + v19);
		do {
			v22 = *(int**)(v3 + 8);
			v23 = *v22;
			*(_DWORD*)(v3 + 8) = v22 + 1;
			*a2 = byte_5D4594[251580];
			if (v23 == -1) {
				v24 = (unsigned __int8*)(*(_DWORD*)(v3 + 8) + 1);
				*(_DWORD*)(v3 + 8) = v24;
				v31 = *v24;
				*(_DWORD*)(v3 + 8) = v24 + 1;
				nox_memfile_read(a2, 1u, v31, v3);
				a2[v31] = 0;
			}
			--v21;
		} while (v21);
	}
	v25 = *(int**)(v3 + 8);
	v26 = *v25;
	*(_DWORD*)(v3 + 8) = v25 + 1;
	if (v26 != 1162757152)
		return 0;
	++dword_5d4594_251572;
	return 1;
}
// 411850: using guessed type char var_20[32];

//----- (00411A90) --------------------------------------------------------
BOOL __cdecl sub_411A90(float2* a1) {
	int v1;         // edx
	const char* v2; // eax
	int v3;         // eax

	if (*(int*)&byte_587000[26520] == -1) {
		v1 = 0;
		v2 = (const char*)&byte_5D4594[2682188];
		do {
			if (!strcmp(v2, "WaterNoTeleport")) {
				*(_DWORD*)&byte_587000[26516] = v1;
			} else if (!strcmp(v2, "WaterDeepNoTeleport")) {
				*(_DWORD*)&byte_587000[26520] = v1;
			} else if (!strcmp(v2, "WaterShallowNoTeleport")) {
				*(_DWORD*)&byte_587000[26524] = v1;
			} else if (!strcmp(v2, "WaterSwampDeepNoTeleport")) {
				*(_DWORD*)&byte_587000[26528] = v1;
			} else if (!strcmp(v2, "WaterSwampShallowNoTeleport")) {
				*(_DWORD*)&byte_587000[26532] = v1;
			}
			v2 += 60;
			++v1;
		} while ((int)v2 < (int)&byte_5D4594[2692748]);
	}
	v3 = sub_411160(a1);
	return v3 == *(_DWORD*)&byte_587000[26516] || v3 == *(_DWORD*)&byte_587000[26520] ||
	       v3 == *(_DWORD*)&byte_587000[26524] || v3 == *(_DWORD*)&byte_587000[26528] ||
	       v3 == *(_DWORD*)&byte_587000[26532];
}

//----- (00411B80) --------------------------------------------------------
void sub_411B80() { nox_srand(0x962u); }

//----- (00411C40) --------------------------------------------------------
BOOL __cdecl sub_411C40(const char* a1, char* a2, int a3) {
	int v3;      // eax
	BOOL result; // eax

	v3 = sub_411C80(a1);
	if (v3 == -1)
		result = 0;
	else
		result = sub_411CF0(a2, (_BYTE*)(a3 + 2 * (v3 + 4) + v3 + 4)) != 0;
	return result;
}

//----- (00411C80) --------------------------------------------------------
int __cdecl sub_411C80(const char* a1) {
	const char* v1;      // ecx
	int v2;              // ebp
	unsigned __int8* v3; // edi

	v1 = *(const char**)&byte_587000[31096];
	v2 = 0;
	if (!*(_DWORD*)&byte_587000[31096])
		return -1;
	v3 = &byte_587000[31096];
	while (strcmp(v1, a1)) {
		v1 = (const char*)*((_DWORD*)v3 + 1);
		v3 += 4;
		++v2;
		if (!v1)
			return -1;
	}
	return v2;
}

//----- (00411CF0) --------------------------------------------------------
char* __cdecl sub_411CF0(char* a1, _BYTE* a2) {
	char* result; // eax
	char v3;      // bl
	char v4;      // al
	char v5[8];   // [esp+4h] [ebp-8h]
	char v6;      // [esp+10h] [ebp+4h]

	strcpy(v5, " =\t\n\r");
	result = strtok(a1, v5);
	if (result) {
		v6 = atoi(result);
		result = strtok(0, v5);
		if (result) {
			v3 = atoi(result);
			result = strtok(0, v5);
			if (result) {
				v4 = atoi(result);
				a2[1] = v3;
				a2[2] = v4;
				*a2 = v6;
				result = (char*)1;
			}
		}
	}
	return result;
}

//----- (00411D90) --------------------------------------------------------
BOOL __cdecl sub_411D90(const char* a1, char* a2, int a3) {
	char* v3;   // eax
	int v4;     // esi
	int v5;     // eax
	char v7[8]; // [esp+Ch] [ebp-8h]

	strcpy(v7, " =\n\r\t");
	v3 = strtok(a2, v7);
	if (v3) {
		if (!strcmp(a1, "EFFECTIVENESS")) {
			v4 = 0;
		LABEL_10:
			v5 = sub_411C80(v3);
			*(_DWORD*)(a3 + 4 * v4 + 36) = v5;
			return v5 != -1;
		}
		if (!strcmp(a1, "MATERIAL")) {
			v4 = 1;
			goto LABEL_10;
		}
		if (!strcmp(a1, "PRIMARYENCHANTMENT")) {
			v4 = 2;
			goto LABEL_10;
		}
		if (!strcmp(a1, "SECONDARYENCHANTMENT")) {
			v4 = 3;
			goto LABEL_10;
		}
	}
	return 0;
}

//----- (00411E60) --------------------------------------------------------
int __cdecl sub_411E60(int a1, char* a2, int a3) {
	size_t v3;  // edx
	int result; // eax
	int v5;     // [esp+8h] [ebp-4h]

	v5 = 0;
	v3 = strspn(a2, "= ");
	if (v3 >= strlen(a2)) {
		*(_BYTE*)(a3 + 62) = v5;
		result = 1;
	} else {
		sub_423930(&a2[v3], &v5, (const char**)&byte_587000[29456]);
		result = 1;
		*(_BYTE*)(a3 + 62) = v5;
	}
	return result;
}

//----- (00411ED0) --------------------------------------------------------
char* __cdecl sub_411ED0(int a1, char* a2, int a3) {
	char* result; // eax
	char v4[8];   // [esp+0h] [ebp-8h]

	strcpy(v4, " =\n\r\t");
	result = strtok(a2, v4);
	if (result) {
		*(_DWORD*)(a3 + 52) = atoi(result);
		result = (char*)1;
	}
	return result;
}

//----- (00411F20) --------------------------------------------------------
char* __cdecl sub_411F20(int a1, char* a2, int a3) {
	char* result; // eax
	char v4[8];   // [esp+0h] [ebp-8h]

	strcpy(v4, " =\n\r\t");
	result = strtok(a2, v4);
	if (result) {
		*(_WORD*)(a3 + 60) = atoi(result);
		result = (char*)1;
	}
	return result;
}

//----- (00411F70) --------------------------------------------------------
char* __cdecl sub_411F70(int a1, char* a2, int a3) {
	char* result; // eax
	char v4[8];   // [esp+0h] [ebp-8h]

	strcpy(v4, " =\n\r\t");
	result = strtok(a2, v4);
	if (result) {
		*(_WORD*)(a3 + 72) = atoi(result);
		result = (char*)1;
	}
	return result;
}

//----- (00411FC0) --------------------------------------------------------
char* __cdecl sub_411FC0(int a1, char* a2, int a3) {
	char* result; // eax
	double v4;    // st7
	char v5[8];   // [esp+0h] [ebp-8h]

	strcpy(v5, " =\n\r\t");
	result = strtok(a2, v5);
	if (result) {
		v4 = atof(result);
		result = (char*)1;
		*(float*)(a3 + 64) = v4;
	}
	return result;
}

//----- (00412010) --------------------------------------------------------
const char* __cdecl sub_412010(int a1, char* a2, int a3) {
	const char* result; // eax
	int v4;             // eax
	char v5[8];         // [esp+0h] [ebp-8h]

	strcpy(v5, " =\n\r\t");
	result = strtok(a2, v5);
	if (result) {
		v4 = sub_4E0A00(result);
		*(_DWORD*)(a3 + 76) = v4;
		result = (const char*)(v4 != 18);
	}
	return result;
}

//----- (00412060) --------------------------------------------------------
char* __cdecl sub_412060(int a1, char* a2, int a3) {
	char* result; // eax
	double v4;    // st7
	char v5[8];   // [esp+0h] [ebp-8h]

	strcpy(v5, " =\n\r\t");
	result = strtok(a2, v5);
	if (result) {
		v4 = atof(result);
		result = (char*)1;
		*(float*)(a3 + 68) = v4;
	}
	return result;
}

//----- (004120B0) --------------------------------------------------------
char* __cdecl sub_4120B0(int a1, char* a2, int a3) {
	char* result; // eax
	double v4;    // st7
	char v5[8];   // [esp+0h] [ebp-8h]

	strcpy(v5, " =\n\r\t");
	result = strtok(a2, v5);
	if (result) {
		v4 = atof(result);
		result = (char*)1;
		*(float*)(a3 + 64) = v4;
	}
	return result;
}

//----- (00412310) --------------------------------------------------------
int __cdecl sub_412310_parse_worth(const char* a1, char* a2, obj_412ae0_t* a3) {
	char* result; // eax
	char v4[8];   // [esp+0h] [ebp-8h]

	strcpy(v4, " =\n\r\t");
	result = strtok(a2, v4);
	if (!result) {
		return 0;
	}
	a3->field_5 = atoi(result);
	return 1;
}

//----- (00412360) --------------------------------------------------------
int __cdecl sub_412360_parse_color(const char* a1, char* a2, obj_412ae0_t* a3) {
	return sub_411CF0(a2, (_BYTE*)(&a3->field_6)) != 0;
}

//----- (00412380) --------------------------------------------------------
int __cdecl sub_412380_parse_attack_effect(const char* a1, char* a2, obj_412ae0_t* obj) {
	char v9[8];
	strcpy(v9, " \n\r\t=");
	char* v3 = strtok(a2, v9);
	if (!v3)
		return 0;
	if (!table_26792)
		return 0;

	table_26792_t* ent = 0;
	for (int i = 0; i < table_26792_cnt; i++) {
		if (strcmp(table_26792[i].name, v3) == 0) {
			ent = &table_26792[i];
			break;
		}
	}
	if (!ent)
		return 0;

	if (!strcmp(a1, "ATTACKEFFECT")) {
		obj->field_10 = ent->fnc;
	} else if (!strcmp(a1, "ATTACKPREHITEFFECT")) {
		obj->field_13 = ent->fnc;
	} else {
		if (strcmp(a1, "ATTACKPREDAMAGEEFFECT"))
			return 0;
		obj->field_16 = ent->fnc;
	}
	if (ent->parse_fnc && !ent->parse_fnc(a1, a2, obj))
		return 0;
	return 1;
}

//----- (00412490) --------------------------------------------------------
int __cdecl sub_412490_parse_defend_effect(const char* a1, char* a2, obj_412ae0_t* obj) {
	char v9[8];
	strcpy(v9, " \n\r\t=");
	char* v3 = strtok(a2, v9);
	if (!v3)
		return 0;

	table_27008_t* ent = 0;
	if (!table_27008)
		return 0;
	for (int i = 0; i < table_27008_cnt; i++) {
		if (strcmp(table_27008[i].name, v3) == 0) {
			ent = &table_27008[i];
			break;
		}
	}
	if (!ent)
		return 0;
	if (!strcmp(a1, "DEFENDEFFECT")) {
		obj->field_19 = ent->fnc;
	} else {
		if (strcmp(a1, "DEFENDCOLLIDEEFFECT"))
			return 0;
		obj->field_22 = ent->fnc;
	}
	if (ent->parse_fnc && !ent->parse_fnc(a1, a2, obj))
		return 0;
	return 1;
}

//----- (00412580) --------------------------------------------------------
int __cdecl sub_412580_parse_engage_effect(const char* a1, char* a2, obj_412ae0_t* obj) {
	char v9[8];
	strcpy(v9, " =\n\r\t");
	char* v3 = strtok(a2, v9);
	if (!v3)
		return 0;
	if (!table_27168)
		return 0;

	table_27168_t* ent = 0;
	for (int i = 0; i < table_27168_cnt; i++) {
		if (strcmp(table_27168[i].name, v3) == 0) {
			ent = &table_27168[i];
			break;
		}
	}
	if (!ent)
		return 0;
	if (!strcmp(a1, "ENGAGEEFFECT")) {
		obj->field_28 = ent->fnc;
	} else {
		if (strcmp(a1, "DISENGAGEEFFECT"))
			return 0;
		obj->field_29 = ent->fnc;
	}
	if (ent->parse_fnc && !ent->parse_fnc(a1, a2, obj))
		return 0;
	return 1;
}

//----- (00412670) --------------------------------------------------------
int __cdecl sub_412670_parse_update_effect(const char* a1, char* a2, obj_412ae0_t* obj) {
	char v8[8];
	strcpy(v8, " =\n\r\t");
	char* v3 = strtok(a2, v8);
	if (!v3)
		return 0;
	if (!table_27104)
		return 0;

	table_27104_t* ent = 0;
	for (int i = 0; i < table_27104_cnt; i++) {
		if (strcmp(table_27104[i].name, v3) == 0) {
			ent = &table_27104[i];
			break;
		}
	}
	if (!ent)
		return 0;

	if (strcmp(a1, "UPDATEEFFECT"))
		return 0;
	obj->field_25 = ent->fnc;
	if ((ent->parse_fnc == 0) || ent->parse_fnc(a1, a2, obj)) {
		return 1;
	}
	return 0;
}

//----- (00412740) --------------------------------------------------------
int __cdecl sub_412740_parse_allowed_weapons(const char* a1, char* a2, obj_412ae0_t* a3) {
	a3->field_7 = 0;
	return sub_412760(a2, &a3->field_7);
}

//----- (00412760) --------------------------------------------------------
int __cdecl sub_412760(char* a1, int* a2) {
	char* v2;            // eax
	int* v4;             // ebx
	const char* v5;      // ecx
	int v6;              // edx
	int v7;              // ebp
	unsigned __int8* v8; // edi
	int v9;              // eax
	char* v10;           // eax
	int v11;             // [esp+10h] [ebp-Ch]
	char v12[8];         // [esp+14h] [ebp-8h]

	strcpy(v12, " =\r\n\t");
	v11 = 1;
	v2 = strtok(a1, v12);
	if (v2) {
		v4 = a2;
		while (1) {
			v5 = *(const char**)&byte_587000[28904];
			v6 = 0;
			v7 = 0;
			if (*(_DWORD*)&byte_587000[28904]) {
				v8 = &byte_587000[28904];
				while (strcmp(v5, v2)) {
					v5 = (const char*)*((_DWORD*)v8 + 2);
					v8 += 8;
					++v7;
					if (!v5) {
						v4 = a2;
						v6 = 0;
						goto LABEL_10;
					}
				}
				v6 = *(_DWORD*)&byte_587000[8 * v7 + 28908];
				v4 = a2;
			}
		LABEL_10:
			if (!*(_DWORD*)&byte_587000[8 * v7 + 28904])
				break;
			if (v11 == 1)
				v9 = v6 | *v4;
			else
				v9 = ~v6 & *v4;
			*v4 = v9;
			v10 = strtok(0, v12);
			if (v10) {
				if (!strcmp(v10, "+")) {
					v11 = 1;
				} else {
					if (strcmp(v10, "-"))
						return 0;
					v11 = 0;
				}
				v2 = strtok(0, v12);
				if (v2)
					continue;
			}
			return 1;
		}
	}
	return 0;
}

//----- (004128A0) --------------------------------------------------------
int __cdecl sub_4128A0_parse_allowed_armor(const char* a1, char* a2, obj_412ae0_t* a3) {
	a3->field_8 = 0;
	return sub_412760(a2, &a3->field_8);
}

//----- (004128C0) --------------------------------------------------------
int __cdecl sub_4128C0_parse_allowed_pos(const char* a1, char* a2, obj_412ae0_t* a3) {
	size_t v3; // edx
	int v5;    // [esp+8h] [ebp-4h]

	v5 = 0;
	v3 = strspn(a2, "= ");
	if (v3 >= strlen(a2)) {
		*(_BYTE*)(&a3->field_9) = v5;
		return 1;
	}
	sub_423930(&a2[v3], &v5, (const char**)&byte_587000[26776]);
	*(_BYTE*)(&a3->field_9) = v5;
	return 1;
}

//----- (00412930) --------------------------------------------------------
int __cdecl sub_412930(char* a1, char* a2) {
	FILE* v2;      // eax
	FILE* v3;      // ebx
	char v10[256]; // [esp+10h] [ebp-100h]

	byte_5D4594_251584[0] = 0;
	byte_5D4594_251584[1] = 0;
	byte_5D4594_251584[2] = 0;
	byte_5D4594_251596 = 0;
	dword_5d4594_251600 = 0;
	*(_DWORD*)&byte_5D4594[251604] = 0;
	dword_5d4594_251608 = 0;
	*(_DWORD*)&byte_5D4594[251612] = 0;
	v2 = sub_408CC0_fopen(a1, 0);
	v3 = v2;
	if (!v2)
		return 0;
	if (!sub_408D40((int)v2, 13))
		return 0;
	while (sub_409470(v3, v10)) {
		if (!strcmp(v10, "WEAPON_DEFINITIONS")) {
			if (!sub_412D40((int)v10, v3, a2))
				return 0;
		} else if (!strcmp(v10, "ARMOR_DEFINITIONS")) {
			if (!sub_412ED0((int)v10, v3, a2))
				return 0;
		} else if (strcmp(v10, "EFFECTIVENESS") && strcmp(v10, "MATERIAL") && strcmp(v10, "ENCHANTMENT") ||
			   !sub_412AE0(v10, v3, a2)) {
			return 0;
		}
	}
	sub_408D90(v3);
	for (LPVOID i = sub_413370(); i; i = (LPVOID)sub_413380((int)i))
		;
	for (LPVOID j = sub_413390(); j; j = (LPVOID)sub_4133A0((int)j))
		;
	int v7 = 0;
	for (int k = 0; k < 3; k++) {
		for (obj_412ae0_t* l = sub_4133B0(k); l; l = sub_4133C0(l))
			++v7;
	}
	return 1;
}

//----- (00412AE0) --------------------------------------------------------
int __cdecl sub_412AE0(const char* a1, FILE* a2, char* a3) {
	char v9[256];

	while (1) {
		sub_409470(a2, v9);
		if (!strcmp(v9, "END"))
			return 1;
		obj_412ae0_t* v3 = (obj_412ae0_t*)nox_calloc(1, sizeof(obj_412ae0_t));
		if (!v3)
			return 0;
		v3->field_1 = byte_5D4594_251596++;
		if (!sub_412C60(a1, v3))
			return 0;
		char* v5 = (char*)nox_malloc(strlen(v9) + 1);
		if (!v5)
			return 0;
		strcpy(v5, v9);
		v3->field_0 = v5;
		while (1) {
			sub_409470(a2, v9);
			if (!strcmp(v9, "END"))
				break;
			table_28760_t* v6 = &table_28760[0];
			if (v6->parse_fnc) {
				while (strcmp(v6->name, v9)) {
					v6++;
					if (!v6->parse_fnc)
						goto LABEL_12;
				}
				sub_4093E0(a2, a3, 0x40000);
				if (!v6->parse_fnc(v9, a3, v3))
					return 0;
			}
		LABEL_12:
			if (!*((_DWORD*)v6 + 1))
				return 0;
		}
	}
}

//----- (00412C60) --------------------------------------------------------
int __cdecl sub_412C60(const char* a1, obj_412ae0_t* a2) {
	if (!strcmp(a1, "EFFECTIVENESS")) {
		a2->field_35 = 0;
		a2->field_34 = byte_5D4594_251584[0];
		if (byte_5D4594_251584[0])
			byte_5D4594_251584[0]->field_35 = a2;
		byte_5D4594_251584[0] = a2;
	} else if (!strcmp(a1, "MATERIAL")) {
		a2->field_35 = 0;
		a2->field_34 = byte_5D4594_251584[1];
		if (byte_5D4594_251584[1])
			byte_5D4594_251584[1]->field_35 = a2;
		byte_5D4594_251584[1] = a2;
	} else if (!strcmp(a1, "ENCHANTMENT")) {
		a2->field_35 = 0;
		a2->field_34 = byte_5D4594_251584[2];
		if (byte_5D4594_251584[2])
			byte_5D4594_251584[2] = a2;
		byte_5D4594_251584[2] = a2;
	} else {
		return 0;
	}
	return 1;
}

//----- (00412D40) --------------------------------------------------------
int __cdecl sub_412D40(int a1, FILE* a2, char* a3) {
	char** v3;           // eax
	char** v4;           // ebp
	char* v5;            // edx
	unsigned __int8* v6; // edi
	int v7;              // eax
	char v9[256];        // [esp+Ch] [ebp-100h]

	while (1) {
		sub_409470(a2, v9);
		if (!strcmp(v9, "END"))
			return 1;
		v3 = (char**)nox_calloc(1u, 0x58u);
		v4 = v3;
		if (!v3)
			return 0;
		v3[21] = 0;
		v3[20] = *(char**)&dword_5d4594_251600;
		if (dword_5d4594_251600)
			*(_DWORD*)(dword_5d4594_251600 + 84) = v3;
		++*(_DWORD*)&byte_5D4594[251604];
		dword_5d4594_251600 = v3;
		v5 = (char*)nox_malloc(strlen(v9) + 1);
		*v4 = v5;
		if (!v5)
			return 0;
		strcpy(v5, v9);
		while (1) {
			sub_409470(a2, v9);
			if (!strcmp(v9, "END"))
				break;
			v6 = &byte_587000[28600];
			if (*(_DWORD*)&byte_587000[28604]) {
				while (strcmp(*(const char**)v6, v9)) {
					v7 = *((_DWORD*)v6 + 3);
					v6 += 8;
					if (!v7)
						goto LABEL_13;
				}
				sub_4093E0(a2, a3, 0x40000);
				if (!(*((int(__cdecl**)(char*, char*, char**))v6 + 1))(v9, a3, v4))
					return 0;
			}
		LABEL_13:
			if (!*((_DWORD*)v6 + 1))
				return 0;
		}
	}
}

//----- (00412ED0) --------------------------------------------------------
int __cdecl sub_412ED0(int a1, FILE* a2, char* a3) {
	char** v3;           // eax
	char** v4;           // ebp
	char* v5;            // edx
	unsigned __int8* v6; // edi
	int v7;              // eax
	char v9[256];        // [esp+Ch] [ebp-100h]

	while (1) {
		sub_409470(a2, v9);
		if (!strcmp(v9, "END"))
			return 1;
		v3 = (char**)nox_calloc(1u, 0x58u);
		v4 = v3;
		if (!v3)
			return 0;
		v3[21] = 0;
		v3[20] = *(char**)&dword_5d4594_251608;
		if (dword_5d4594_251608)
			*(_DWORD*)(dword_5d4594_251608 + 84) = v3;
		++*(_DWORD*)&byte_5D4594[251612];
		dword_5d4594_251608 = v3;
		v5 = (char*)nox_malloc(strlen(v9) + 1);
		*v4 = v5;
		if (!v5)
			return 0;
		strcpy(v5, v9);
		while (1) {
			sub_409470(a2, v9);
			if (!strcmp(v9, "END"))
				break;
			v6 = &byte_587000[28600];
			if (*(_DWORD*)&byte_587000[28604]) {
				while (strcmp(*(const char**)v6, v9)) {
					v7 = *((_DWORD*)v6 + 3);
					v6 += 8;
					if (!v7)
						goto LABEL_13;
				}
				sub_4093E0(a2, a3, 0x40000);
				if (!(*((int(__cdecl**)(char*, char*, char**))v6 + 1))(v9, a3, v4))
					return 0;
			}
		LABEL_13:
			if (!*((_DWORD*)v6 + 1))
				return 0;
		}
	}
}

//----- (00413060) --------------------------------------------------------
void sub_413060() {
	sub_4130C0(*(LPVOID*)&dword_5d4594_251600);
	dword_5d4594_251600 = 0;
	*(_DWORD*)&byte_5D4594[251604] = 0;
	sub_413100(*(LPVOID*)&dword_5d4594_251608);
	dword_5d4594_251608 = 0;
	*(_DWORD*)&byte_5D4594[251612] = 0;
	for (int i = 0; i < 3; i++) {
		sub_413140(byte_5D4594_251584[i]);
		byte_5D4594_251584[i] = 0;
	}
	byte_5D4594_251596 = 0;
}

//----- (004130C0) --------------------------------------------------------
void __cdecl sub_4130C0(LPVOID lpMem) {
	LPVOID v1; // esi
	void* v2;  // edi

	v1 = lpMem;
	if (lpMem) {
		do {
			v2 = (void*)*((_DWORD*)v1 + 20);
			if (*(_DWORD*)v1)
				free(*(LPVOID*)v1);
			if (*((_DWORD*)v1 + 2))
				free(*((LPVOID*)v1 + 2));
			free(v1);
			v1 = v2;
		} while (v2);
	}
}

//----- (00413100) --------------------------------------------------------
void __cdecl sub_413100(LPVOID lpMem) {
	LPVOID v1; // esi
	void* v2;  // edi

	v1 = lpMem;
	if (lpMem) {
		do {
			v2 = (void*)*((_DWORD*)v1 + 20);
			if (*(_DWORD*)v1)
				free(*(LPVOID*)v1);
			if (*((_DWORD*)v1 + 2))
				free(*((LPVOID*)v1 + 2));
			free(v1);
			v1 = v2;
		} while (v2);
	}
}

//----- (00413140) --------------------------------------------------------
void __cdecl sub_413140(LPVOID lpMem) {
	LPVOID v1; // esi
	void* v2;  // edi

	v1 = lpMem;
	if (lpMem) {
		do {
			v2 = (void*)*((_DWORD*)v1 + 34);
			if (*(_DWORD*)v1)
				free(*(LPVOID*)v1);
			if (*((_DWORD*)v1 + 2))
				free(*((LPVOID*)v1 + 2));
			if (*((_DWORD*)v1 + 3))
				free(*((LPVOID*)v1 + 3));
			free(v1);
			v1 = v2;
		} while (v2);
	}
}

//----- (004131A0) --------------------------------------------------------
CHAR* sub_4131A0() {
	CHAR* result; // eax
	int i;        // esi
	int j;        // esi

	result = *(CHAR**)&byte_5D4594[251616];
	if (*(_DWORD*)&byte_5D4594[251616] != 1) {
		for (i = dword_5d4594_251600; i; i = *(_DWORD*)(i + 80)) {
			if (nox_common_gameFlags_check_40A5C0(2097153)) {
				result = (CHAR*)sub_4E3AA0(*(CHAR**)i);
			} else {
				result = (CHAR*)nox_common_gameFlags_check_40A5C0(2);
				if (!result)
					return result;
				result = (CHAR*)sub_44CFC0(*(CHAR**)i);
			}
			*(_DWORD*)(i + 4) = result;
		}
		for (j = dword_5d4594_251608; j; j = *(_DWORD*)(j + 80)) {
			if (nox_common_gameFlags_check_40A5C0(2097153)) {
				result = (CHAR*)sub_4E3AA0(*(CHAR**)j);
			} else {
				result = (CHAR*)nox_common_gameFlags_check_40A5C0(2);
				if (!result)
					return result;
				result = (CHAR*)sub_44CFC0(*(CHAR**)j);
			}
			*(_DWORD*)(j + 4) = result;
		}
		*(_DWORD*)&byte_5D4594[251616] = 1;
	}
	return result;
}

//----- (00413250) --------------------------------------------------------
_DWORD* __cdecl sub_413250(int a1) {
	_DWORD* result; // eax

	result = *(_DWORD**)&dword_5d4594_251600;
	if (!dword_5d4594_251600)
		return 0;
	while (result[1] != a1) {
		result = (_DWORD*)result[20];
		if (!result)
			return 0;
	}
	return result;
}

//----- (00413270) --------------------------------------------------------
_DWORD* __cdecl sub_413270(int a1) {
	_DWORD* result; // eax

	result = *(_DWORD**)&dword_5d4594_251608;
	if (!dword_5d4594_251608)
		return 0;
	while (result[1] != a1) {
		result = (_DWORD*)result[20];
		if (!result)
			return 0;
	}
	return result;
}

//----- (00413290) --------------------------------------------------------
int __cdecl sub_413290(const char* a1) {
	if (!a1)
		return 255;
	for (int i = 0; i < 3; i++) {
		for (obj_412ae0_t* it = byte_5D4594_251584[i]; it; it = it->field_34) {
			if (strcmp(it->field_0, a1) == 0)
				return it->field_1;
		}
	}
	return 255;
}

//----- (00413300) --------------------------------------------------------
int __cdecl sub_413300(int a1) {
	for (int i = 0; i < 3; i++) {
		for (obj_412ae0_t* it = byte_5D4594_251584[i]; it; it = it->field_34) {
			if (it->field_1 == a1)
				return it->field_0;
		}
	}
	return 0;
}

//----- (00413330) --------------------------------------------------------
obj_412ae0_t* __cdecl sub_413330(int a1) {
	if (a1 == 255)
		return 0;
	for (int i = 0; i < 3; i++) {
		for (obj_412ae0_t* it = byte_5D4594_251584[i]; it; it = it->field_34) {
			if (it->field_1 == a1)
				return it;
		}
	}
	return 0;
}

//----- (00413370) --------------------------------------------------------
LPVOID sub_413370() { return *(LPVOID*)&dword_5d4594_251600; }

//----- (00413380) --------------------------------------------------------
int __cdecl sub_413380(int a1) { return *(_DWORD*)(a1 + 80); }

//----- (00413390) --------------------------------------------------------
LPVOID sub_413390() { return *(LPVOID*)&dword_5d4594_251608; }

//----- (004133A0) --------------------------------------------------------
int __cdecl sub_4133A0(int a1) { return *(_DWORD*)(a1 + 80); }

//----- (004133B0) --------------------------------------------------------
obj_412ae0_t* __cdecl sub_4133B0(int a1) { return byte_5D4594_251584[a1]; }

//----- (004133C0) --------------------------------------------------------
obj_412ae0_t* __cdecl sub_4133C0(obj_412ae0_t* a1) { return a1->field_34; }

//----- (004133D0) --------------------------------------------------------
BOOL __cdecl sub_4133D0(int a1) {
	int v1; // eax
	int v2; // esi
	int v3; // eax

	v1 = *(_DWORD*)&byte_5D4594[251620];
	v2 = *(_DWORD*)(a1 + 692);
	if (!*(_DWORD*)&byte_5D4594[251620]) {
		v3 = sub_413290("Material7");
		v1 = sub_413330(v3);
		*(_DWORD*)&byte_5D4594[251620] = v1;
	}
	return *(_DWORD*)(a1 + 8) & 0x13001000 && *(_DWORD*)(v2 + 4) == v1;
}

//----- (00413420) --------------------------------------------------------
int __cdecl sub_413420(char a1) {
	unsigned __int8* v1; // esi
	int v2;              // ecx
	unsigned __int8* v3; // eax

	if (!*(_DWORD*)&byte_5D4594[251624]) {
		v1 = &byte_587000[27340];
		do {
			*(_DWORD*)v1 = sub_42F970(*((const char**)v1 - 1));
			v1 += 20;
		} while ((int)v1 < (int)&byte_587000[27460]);
		*(_DWORD*)&byte_5D4594[251624] = 1;
	}
	v2 = 0;
	v3 = &byte_587000[27332];
	while (*v3 != a1) {
		v3 += 20;
		++v2;
		if ((int)v3 >= (int)&byte_587000[27452])
			return 0;
	}
	return *(_DWORD*)&byte_587000[20 * v2 + 27340];
}

//----- (004134C0) --------------------------------------------------------
void sub_4134C0() { nox_srand(0x963u); }

//----- (004134D0) --------------------------------------------------------
int sub_4134D0() {
	dword_5d4594_251704 = 0;
	dword_5d4594_251708 = 0;
	dword_5d4594_251712 = 0;
	dword_5d4594_251716 = 0;
	dword_5d4594_251720 = 0;
	return sub_413850();
}

//----- (004134F0) --------------------------------------------------------
void sub_4134F0() {
	dword_5d4594_251700 = 0;
	dword_5d4594_251704 = 0;
	dword_5d4594_251708 = 0;
	dword_5d4594_251712 = 0;
	dword_5d4594_251716 = 0;
	dword_5d4594_251720 = 0;
}

//----- (00413760) --------------------------------------------------------
int sub_413760() {
	int result; // eax

	sub_43DDD0(0);
	result = sub_43DE60();
	dword_5d4594_251700 = 5;
	return result;
}

//----- (00413780) --------------------------------------------------------
int sub_413780() {
	int result; // eax

	result = dword_5d4594_251716;
	dword_5d4594_251700 = 1;
	if (dword_5d4594_251716)
		dword_5d4594_251716 = 0;
	return result;
}

//----- (004137A0) --------------------------------------------------------
BOOL sub_4137A0() {
	BOOL result; // eax

	result = sub_413A50();
	if (!result)
		dword_5d4594_251716 = 1;
	return result;
}

//----- (004137C0) --------------------------------------------------------
int sub_4137C0() {
	int result; // eax

	result = dword_5d4594_251720;
	if (!dword_5d4594_251720) {
		dword_5d4594_251720 = 1;
		result = sub_43DBD0();
	}
	return result;
}

//----- (004137E0) --------------------------------------------------------
int sub_4137E0() {
	int result; // eax

	result = dword_5d4594_251720;
	if (dword_5d4594_251720) {
		dword_5d4594_251720 = 0;
		result = sub_43DBE0();
	}
	return result;
}

//----- (00413800) --------------------------------------------------------
int sub_413800() {
	int result; // eax

	result = *(_DWORD*)&byte_5D4594[251724];
	if (!*(_DWORD*)&byte_5D4594[251724]) {
		*(_DWORD*)&byte_5D4594[251724] = 1;
		result = sub_43C0A0();
		if (!result)
			result = sub_413760();
	}
	return result;
}

//----- (00413830) --------------------------------------------------------
BOOL sub_413830() { return dword_5d4594_251704 != 0; }

//----- (00413840) --------------------------------------------------------
BOOL sub_413840() { return dword_5d4594_251704 == 2; }

//----- (00413850) --------------------------------------------------------
int sub_413850() {
	int result; // eax

	result = *(_DWORD*)&byte_5D4594[251728];
	if (!*(_DWORD*)&byte_5D4594[251728]) {
		result = 1;
		*(_DWORD*)&byte_5D4594[251728] = 1;
		dword_5d4594_251700 = 1;
	}
	return result;
}

//----- (00413870) --------------------------------------------------------
BOOL __cdecl sub_413870(int a1) {
	BOOL result; // eax

	dword_5d4594_251708 = 1;
	result = sub_423CC0(a1);
	dword_5d4594_251712 = result;
	return result;
}

//----- (00413890) --------------------------------------------------------
char* sub_413890() {
	unsigned __int8* v0; // edi
	int v1;              // ecx
	__int16 v2;          // dx
	unsigned __int8 v3;  // al

	byte_5D4594[251636] = sub_423EC0();
	byte_5D4594[251637] = 0;
	if (!byte_5D4594[251636])
		return 0;
	v0 = &byte_5D4594[strlen((const char*)&byte_5D4594[251636]) + 251637];
	v1 = *(_DWORD*)&byte_587000[32316];
	v2 = *(_WORD*)&byte_587000[32320];
	*(_DWORD*)--v0 = *(_DWORD*)&byte_587000[32312];
	v3 = byte_587000[32322];
	*((_DWORD*)v0 + 1) = v1;
	*((_WORD*)v0 + 4) = v2;
	v0[10] = v3;
	return (char*)&byte_5D4594[251636];
}

//----- (004138E0) --------------------------------------------------------
void sub_4138E0(int a1) {
	*(_DWORD*)&byte_5D4594[251740] = sub_413A50();
	sub_413A00(1);
}

//----- (00413900) --------------------------------------------------------
void sub_413900(int a1) {
	if (!sub_44E0D0()) {
		if (!*(_DWORD*)&byte_5D4594[251740])
			sub_413A00(0);
	}
}

//----- (00413920) --------------------------------------------------------
int sub_413920() {
	sub_42EBB0(1u, sub_413900, 0, "Pause");
	sub_42EBB0(2u, sub_4138E0, 0, "Pause");
	dword_5d4594_251744 = 0;
	return 1;
}

//----- (00413960) --------------------------------------------------------
void sub_413960() {
	dword_5d4594_251744 = 0;
	sub_413A00(0);
}

//----- (004139B0) --------------------------------------------------------
BOOL sub_4139B0() { return dword_5d4594_251744 != 0; }

//----- (00413A00) --------------------------------------------------------
int __cdecl sub_413A00(int a1) {
	int result; // eax

	result = nox_common_gameFlags_check_40A5C0(2048);
	if (result == 1) {
		if (a1) {
			result = sub_40A4D0(0x40000);
		} else {
			result = dword_5d4594_251744;
			if (!dword_5d4594_251744) {
				nox_common_gameFlags_unset_40A540(0x40000);
				result = sub_416D40();
			}
		}
	}
	return result;
}

//----- (00413A50) --------------------------------------------------------
BOOL sub_413A50() { return nox_common_gameFlags_check_40A5C0(0x40000); }

//----- (00413A60) --------------------------------------------------------
unsigned int sub_413A60() {
	unsigned int result; // eax

	nox_file_4 = 0;
	result = *(_DWORD*)&nox_common_engineFlags & 0xFE7FFFFF;
	*(_DWORD*)&nox_common_engineFlags &= 0xFE7FFFFF;
	return result;
}

//----- (00413A80) --------------------------------------------------------
int __cdecl sub_413A80(char* a1) {
	int result; // eax

	result = 0;
	if (0x800000 & *(_DWORD*)&nox_common_engineFlags) {
		sub_413AD0(nox_file_4);
		nox_file_4 = 0;
		sub_413B20(&nox_file_4, a1, (char*)&byte_587000[32340]);
		result = 1;
	}
	return result;
}

//----- (00413AD0) --------------------------------------------------------
void __cdecl sub_413AD0(FILE* a1) {
	char* v2; // eax

	if (a1) {
		v2 = sub_413B00();
		fprintf(a1, "Log closed: %s", v2);
		fflush(a1);
		fclose(a1);
	}
}

//----- (00413B00) --------------------------------------------------------
char* sub_413B00() {
	struct tm* v1; // eax
	time_t v3;     // [esp+0h] [ebp-4h]

	time(&v3);
	v1 = localtime(&v3);
	return asctime(v1);
}

//----- (00413B20) --------------------------------------------------------
int __cdecl sub_413B20(FILE** a1, char* a2, char* a3) {
	char* v4; // eax

	if (!a2)
		return 0;
	*a1 = fopen(a2, a3);
	if (!a1)
		return 0;
	v4 = sub_413B00();
	fprintf(*a1, "Log opened: %s", v4);
	fflush(*a1);
	return 1;
}
// 413B44: variable 'v3' is possibly undefined

//----- (00413B70) --------------------------------------------------------
void sub_413B70(char* a1, ...) {
	va_list va; // [esp+8h] [ebp+8h]

	va_start(va, a1);
	nox_vsprintf((char*)&byte_5D4594[251752], a1, va);
	if (0x800000 & *(_DWORD*)&nox_common_engineFlags)
		sub_413BD0(nox_file_4, (int)&byte_5D4594[251752]);
	if (*(_DWORD*)&nox_common_engineFlags & 0x1000000)
		sub_450C00(9u, (wchar_t*)&byte_587000[32376], &byte_5D4594[251752]);
}

//----- (00413BD0) --------------------------------------------------------
void __cdecl sub_413BD0(FILE* a1, int a2) {
	if (a1) {
		fprintf(a1, "%s", a2);
		fflush(a1);
	}
}

//----- (00413C00) --------------------------------------------------------
void sub_413C00() {
	*(_DWORD*)&nox_common_engineFlags &= 0xFE7FFFFF;
	if (nox_file_4) {
		sub_413AD0(nox_file_4);
		nox_file_4 = 0;
	}
}

//----- (00413C30) --------------------------------------------------------
void sub_413C30() {
	sub_413B20(&nox_file_5, (char*)&byte_587000[32392], (char*)&byte_587000[32388]);
	sub_413BD0(nox_file_5, (int)&byte_587000[32404]);
}

//----- (00413C60) --------------------------------------------------------
void sub_413C60() {
	sub_413AD0(nox_file_5);
	nox_file_5 = 0;
}

//----- (00413C80) --------------------------------------------------------
void sub_413C80(char* a1, ...) {
	va_list va; // [esp+8h] [ebp+8h]

	va_start(va, a1);
	nox_vsprintf((char*)&byte_5D4594[251752], a1, va);
	if (*(_DWORD*)&nox_common_engineFlags & 0x20000000)
		sub_413BD0(nox_file_5, (int)&byte_5D4594[251752]);
}

//----- (00413CC0) --------------------------------------------------------
FILE* sub_413CC0() {
	FILE* result; // eax

	result = fopen("network.log", "a");
	nox_file_net_log = result;
	if (result)
		result = (FILE*)sub_413D30("StartLog%c%s", 240, "1.0");
	return result;
}

//----- (00413D00) --------------------------------------------------------
void sub_413D00() {
	sub_413D30((char*)&byte_587000[32528]);
	fclose(nox_file_net_log);
	nox_file_net_log = 0;
}

//----- (00413D30) --------------------------------------------------------
int sub_413D30(char* a1, ...) {
	struct tm* v1;       // esi
	int result;          // eax
	unsigned __int8* v3; // edi
	unsigned __int8 v4;  // cl
	FILE* v5;            // [esp-2Ch] [ebp-34h]
	time_t v6;           // [esp+4h] [ebp-4h]
	va_list va;          // [esp+10h] [ebp+8h]

	va_start(va, a1);
	time(&v6);
	v1 = localtime(&v6);
	result = nox_common_gameFlags_check_40A5C0(4);
	if (result) {
		nox_vsprintf((char*)&byte_5D4594[251752], a1, va);
		nox_sprintf((char*)&byte_5D4594[251752], "%s%c(", &byte_5D4594[251752], 240);
		strcat((char*)&byte_5D4594[251752], asctime(v1));
		v5 = nox_file_net_log;
		byte_5D4594[strlen((const char*)&byte_5D4594[251752]) + 251751] = 0;
		v3 = &byte_5D4594[strlen((const char*)&byte_5D4594[251752]) + 251753];
		v4 = byte_587000[32546];
		*(_WORD*)--v3 = *(_WORD*)&byte_587000[32544];
		v3[2] = v4;
		sub_413BD0(v5, (int)&byte_5D4594[251752]);
		result = sub_450C00(9u, (wchar_t*)&byte_587000[32548], &byte_5D4594[251752]);
	}
	return result;
}

//----- (00413E10) --------------------------------------------------------
int sub_413E10() {
	int result; // eax

	for (result = *(_DWORD*)&byte_5D4594[338304]; result; result = *(_DWORD*)(result + 4))
		;
	return result;
}

//----- (00413E30) --------------------------------------------------------
void sub_413E30() {
	signed int v0;       // ebx
	int v1;              // esi
	unsigned __int8* v2; // eax
	int v3;              // edx
	signed int v4;       // edi
	const char* v5;      // ebp
	unsigned __int8* v6; // eax
	signed int v7;       // ecx
	int v8;              // ebx
	signed int v9;       // [esp+8h] [ebp-8h]

	v0 = 0;
	v1 = 0;
	v9 = 0;
	v2 = &byte_5D4594[252364];
	do {
		*(_DWORD*)v2 = 0;
		v2 += 84;
	} while ((int)v2 < (int)&byte_5D4594[338380]);
	v3 = *(_DWORD*)&byte_5D4594[338304];
	if (*(_DWORD*)&byte_5D4594[338304]) {
		do {
			v4 = 0;
			if (v0 > 0) {
				v5 = (const char*)&byte_5D4594[252284];
				while (strcmp(v5, (const char*)(v3 + 20))) {
					v0 = v9;
					++v4;
					v5 += 84;
					if (v4 >= v9)
						goto LABEL_10;
				}
				v0 = v9;
				*(_DWORD*)&byte_5D4594[84 * v4 + 252364] += *(_DWORD*)(v3 + 16);
			}
		LABEL_10:
			if (v4 == v0) {
				*(_DWORD*)&byte_5D4594[84 * v4 + 252364] = *(_DWORD*)(v3 + 16);
				strcpy((char*)&byte_5D4594[84 * v4 + 252284], (const char*)(v3 + 20));
				v9 = ++v0;
			}
			v3 = *(_DWORD*)(v3 + 4);
		} while (v3);
		v1 = 0;
	}
	qsort(&byte_5D4594[252284], v0, 0x54u, sub_413F60);
	if (v0 > 0) {
		v6 = &byte_5D4594[252364];
		v7 = v0;
		do {
			v8 = *(_DWORD*)v6;
			v6 += 84;
			v1 += v8;
			--v7;
		} while (v7);
	}
}

//----- (00413F60) --------------------------------------------------------
int __cdecl sub_413F60(const void* a1, const void* a2) { return *((_DWORD*)a1 + 20) - *((_DWORD*)a2 + 20); }

//----- (00413F90) --------------------------------------------------------
char* __cdecl nox_clone_str(const char* a1) {
	char* result; // eax

	result = (char*)nox_malloc(strlen(a1) + 1);
	if (result)
		strcpy(result, a1);
	return result;
}

//----- (00413FE0) --------------------------------------------------------
nox_alloc_class* __cdecl nox_new_alloc_class(const char* name, int size, int cnt) {
	nox_alloc_class* p = (nox_alloc_class*)nox_calloc(1, sizeof(nox_alloc_class));
	if (!p)
		return 0;
	if (!name)
		return 0;
	if (size <= 0)
		return 0;
	if (cnt <= 0)
		return 0;
	strcpy(&p->name[0], name);

	char sbuf[80];
	nox_sprintf(sbuf, "%s (Allocation Class)", name);

	int isize = size + sizeof(nox_alloc_hdr);
	void* items = nox_calloc(cnt, isize);
	p->items = items;

	if (!items)
		return 0;

	for (int i = 0; i < cnt; i++) {
		nox_alloc_hdr* h = (nox_alloc_hdr*)((char*)p->items + isize * i);

		h->field_0 = 0;
		h->field_1 = 0;
		h->field_2 = p->field_24;
		p->field_24 = h;
		if (i != 0)
			p->field_25 = h;
	}
	p->size = size;
	p->cnt1 = cnt;
	p->cnt2 = cnt;
	p->field_32 = 0;
	p->field_26 = 0;
	p->field_27 = 0;
	p->field_31 = 0;
	p->field_33 = 0;
	return p;
}

//----- (004140D0) --------------------------------------------------------
nox_alloc_class* __cdecl nox_new_alloc_class_f30(const char* name, int size, int cnt) {
	nox_alloc_class* p = nox_new_alloc_class(name, size, cnt);
	if (!p)
		return 0;
	p->field_30 = 1;
	return p;
}

//----- (00414100) --------------------------------------------------------
void __cdecl nox_free_alloc_class(nox_alloc_class* p) {
	if (!p)
		return;
	if (p->field_30)
		nox_free_alloc_class_f30(p);
	free(p->items);
	free(p);
}

//----- (00414130) --------------------------------------------------------
void __cdecl nox_free_alloc_class_f30(nox_alloc_class* p) {
	if (!p)
		return;

	if (p->field_26) {
		_DWORD* v1 = (_DWORD*)p->field_26;
		_DWORD* v2;
		do {
			v2 = (_DWORD*)v1[2];
			free(v1);
			v1 = v2;
		} while (v2);
	}

	if (p->field_28) {
		_DWORD* v3 = (_DWORD*)p->field_28;
		_DWORD* v4;
		do {
			v4 = (_DWORD*)v3[2];
			if (*(_QWORD*)v3)
				free(v3);
			v3 = v4;
		} while (v4);
	}

	p->field_26 = 0;
	p->field_27 = 0;
}

//----- (00414190) --------------------------------------------------------
int __cdecl nox_alloc_class_new_obj(_DWORD* a1) {
	_DWORD* v1;           // esi
	int v2;               // eax
	int v3;               // edx
	_DWORD* v4;           // ecx
	_DWORD* v5;           // eax
	int v6;               // edx
	_DWORD* v7;           // ecx
	int v8;               // edx
	int v9;               // edx
	int v10;              // ecx
	unsigned __int64 v11; // kr00_8
	_DWORD* v12;          // eax
	int v13;              // ecx
	_DWORD* v14;          // edi
	int v15;              // edx
	int v16;              // ecx
	int v17;              // ecx
	int v18;              // edx
	int v20;              // [esp+Ch] [ebp+4h]

	v1 = a1;
	if (!a1)
		return 0;
	v2 = a1[24];
	if (v2) {
		v3 = *(_DWORD*)(v2 + 8);
		v4 = (_DWORD*)(v2 + 8);
		a1[24] = v3;
		if (!v3)
			a1[25] = 0;
	} else {
		if (!a1[26]) {
			if (!a1[30])
				return 0;
			v5 = nox_malloc(a1[22] + 16);
			v6 = a1[31] + 1;
			a1[26] = v5;
			a1[31] = v6;
			if (!v5)
				return 0;
			++a1[36];
			v5[2] = 0;
			*(_DWORD*)(a1[26] + 12) = 0;
			v7 = (_DWORD*)a1[26];
			*v7 = 1;
			v7[1] = 0;
			a1[27] = a1[26];
		}
		v2 = a1[26];
		v8 = *(_DWORD*)(v2 + 8);
		v4 = (_DWORD*)(v2 + 8);
		a1[26] = v8;
		if (!v8)
			a1[27] = 0;
	}
	if (!v2)
		return 0;
	v9 = a1[28];
	*(_DWORD*)(v2 + 12) = 0;
	*v4 = v9;
	v10 = a1[28];
	if (v10)
		*(_DWORD*)(v10 + 12) = v2;
	a1[28] = v2;
	v20 = v2 + 16;
	v11 = sub_416BB0();
	if (v11 != *((_QWORD*)v1 + 16)) {
		v12 = (_DWORD*)v1[26];
		if (v12) {
			do {
				v13 = v12[2];
				v14 = (_DWORD*)v12[2];
				if (v11 > *(_QWORD*)v12) {
					v15 = v12[3];
					if (v15)
						*(_DWORD*)(v15 + 8) = v13;
					else
						v1[26] = v13;
					v16 = v12[2];
					if (v16)
						*(_DWORD*)(v16 + 12) = v12[3];
					else
						v1[27] = v12[3];
					--v1[31];
					free(v12);
				}
				v12 = v14;
			} while (v14);
		}
		*((_QWORD*)v1 + 16) = v11;
	}
	v17 = v1[34];
	v18 = v1[35] + 1;
	v1[35] = v18;
	if (v18 > v17)
		v1[34] = v18;
	return v20;
}

//----- (004142F0) --------------------------------------------------------
void* __cdecl nox_alloc_class_new_obj_zero(nox_alloc_class* al) {
	void* v1 = (void*)nox_alloc_class_new_obj(al);
	if (!v1)
		return 0;
	memset(v1, 0, al->size);
	return v1;
}

//----- (00414330) --------------------------------------------------------
void __cdecl sub_414330(unsigned int* a1, _QWORD* a2) {
	_QWORD* v2;      // esi
	unsigned int v3; // ecx
	unsigned int v4; // edx

	if (a2) {
		v2 = a2 - 2;
		sub_4143D0((int)a1, (int)a2);
		--a1[35];
		if (*(a2 - 2)) {
			if (!a1[27])
				a1[27] = (unsigned int)v2;
			v4 = a1[26];
			*((_DWORD*)v2 + 3) = 0;
			*((_DWORD*)v2 + 2) = v4;
			a1[26] = (unsigned int)v2;
			*v2 = sub_416BB0() + 10000;
		} else {
			if (!a1[25])
				a1[25] = (unsigned int)v2;
			v3 = a1[24];
			*((_DWORD*)v2 + 3) = 0;
			*((_DWORD*)v2 + 2) = v3;
			a1[24] = (unsigned int)v2;
		}
		memset(a2, 0xACu, a1[22]);
	}
}

//----- (004143D0) --------------------------------------------------------
int __cdecl sub_4143D0(int a1, int a2) {
	int result; // eax
	int v3;     // ecx
	int v4;     // ecx

	result = a2;
	if (a2) {
		v3 = *(_DWORD*)(a2 - 4);
		if (v3)
			*(_DWORD*)(v3 + 8) = *(_DWORD*)(a2 - 8);
		else
			*(_DWORD*)(a1 + 112) = *(_DWORD*)(a2 - 8);
		v4 = *(_DWORD*)(a2 - 8);
		if (v4) {
			result = *(_DWORD*)(a2 - 4);
			*(_DWORD*)(v4 + 12) = result;
		}
	}
	return result;
}

//----- (00414400) --------------------------------------------------------
void __cdecl sub_414400(unsigned int* a1, _QWORD* a2) {
	_QWORD* v2;      // esi
	unsigned int v3; // eax
	unsigned int v4; // eax

	if (a2) {
		v2 = a2 - 2;
		sub_4143D0((int)a1, (int)a2);
		--a1[35];
		if (*(a2 - 2)) {
			if (!a1[26])
				a1[26] = (unsigned int)v2;
			*((_DWORD*)v2 + 2) = 0;
			*((_DWORD*)v2 + 3) = a1[27];
			v4 = a1[27];
			if (v4)
				*(_DWORD*)(v4 + 8) = v2;
			a1[27] = (unsigned int)v2;
			*v2 = sub_416BB0() + 10000;
		} else {
			if (!a1[24])
				a1[24] = (unsigned int)v2;
			*((_DWORD*)v2 + 2) = 0;
			*((_DWORD*)v2 + 3) = a1[25];
			v3 = a1[25];
			if (v3)
				*(_DWORD*)(v3 + 8) = v2;
			a1[25] = (unsigned int)v2;
		}
		memset(a2, 0xACu, a1[22]);
	}
}

//----- (004144B0) --------------------------------------------------------
int __cdecl sub_4144B0(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)(a1 + 136) = *(_DWORD*)(a1 + 140);
	return result;
}

//----- (004144D0) --------------------------------------------------------
void __cdecl sub_4144D0(_DWORD* a1) {
	int v1; // edx
	int v2; // eax

	if (a1) {
		if (a1[30])
			nox_free_alloc_class_f30(a1);
		dword_5d4594_252276 = a1[28];
		v1 = dword_5d4594_252276;
		if (dword_5d4594_252276) {
			do {
				*(_DWORD*)&byte_5D4594[338300] = *(_DWORD*)(v1 + 8);
				memset((void*)(v1 + 16), 0xACu, a1[22]);
				v2 = a1[24];
				if (!v2)
					a1[25] = dword_5d4594_252276;
				*(_DWORD*)(dword_5d4594_252276 + 8) = v2;
				a1[24] = dword_5d4594_252276;
				v1 = *(_DWORD*)&byte_5D4594[338300];
				dword_5d4594_252276 = *(_DWORD*)&byte_5D4594[338300];
			} while (*(_DWORD*)&byte_5D4594[338300]);
		}
		a1[28] = 0;
		a1[26] = 0;
		a1[27] = 0;
		a1[35] = 0;
	}
}

//----- (00414580) --------------------------------------------------------
int sub_414580() { return *(_DWORD*)&byte_5D4594[338312]; }

//----- (00414590) --------------------------------------------------------
int sub_414590() { return *(_DWORD*)&byte_5D4594[338308]; }

//----- (004145A0) --------------------------------------------------------
int sub_4145A0() { return *(_DWORD*)&byte_5D4594[338320]; }

//----- (004145B0) --------------------------------------------------------
int sub_4145B0() { return *(_DWORD*)&byte_5D4594[338316]; }

//----- (004145C0) --------------------------------------------------------
void* __cdecl sub_4145C0(size_t a1, size_t a2) { return nox_calloc(a1, a2); }

//----- (004145E0) --------------------------------------------------------
void __cdecl sub_4145E0(LPVOID lpMem) { free(lpMem); }

//----- (004145F0) --------------------------------------------------------
int __cdecl sub_4145F0(_DWORD* a1) {
	int v1;                  // edi
	HANDLE v2;               // eax
	void* v3;                // esi
	char Buffer[8];          // [esp+8h] [ebp-110h]
	DWORD NumberOfBytesRead; // [esp+10h] [ebp-108h]
	CHAR Filename[260];      // [esp+14h] [ebp-104h]

	v1 = 0;
	GetModuleFileNameA(0, Filename, 0x104u);
	v2 = CreateFileA(Filename, 0x80000000, 1u, 0, 3u, 0x80u, 0);
	v3 = v2;
	if (v2 != (HANDLE)-1) {
		SetFilePointer(v2, 28, 0, 0);
		if (!GetLastError() && ReadFile(v3, Buffer, 8u, &NumberOfBytesRead, 0)) {
			sub_414B30((int)Buffer, a1);
			v1 = 1;
		}
		CloseHandle(v3);
	}
	return v1;
}

//----- (00414690) --------------------------------------------------------
char __cdecl sub_414690(unsigned int* a1, void(__stdcall* a2)(char*)) {
	unsigned int v2;  // esi
	unsigned int v3;  // eax
	unsigned int v4;  // eax
	unsigned int v5;  // eax
	bool v6;          // zf
	unsigned int v7;  // eax
	int Buffer;       // [esp+8h] [ebp-200h]
	unsigned int v10; // [esp+Ch] [ebp-1FCh]
	unsigned int v11; // [esp+10h] [ebp-1F8h]
	char v12[16];
	BYTE Data[32];      // [esp+24h] [ebp-1E4h]
	CHAR ValueName[64]; // [esp+44h] [ebp-1C4h]
	CHAR SubKey[128];   // [esp+84h] [ebp-184h]
	CHAR Filename[260]; // [esp+104h] [ebp-104h]

	GetModuleFileNameA(0, Filename, 0x104u);
	a2(v12);
	v2 = *(unsigned __int16*)&v12[6] | (32 * (*(unsigned __int16*)&v12[2] | (16 * *(unsigned __int16*)v12)));
	if (sub_4149A0(Filename, &Buffer, &v10, &v11)) {
		if (v10 && v11 && (v2 < v10 || v2 >= v11)) {
			v3 = *a1;
			LOBYTE(v3) = *a1 | 1;
			*a1 = v3;
		}
		if (Buffer) {
			v4 = sub_4148D0(Filename);
			if (Buffer != v4) {
				v5 = *a1;
				LOBYTE(v5) = *a1 | 2;
				*a1 = v5;
			}
		}
	}
	sub_414B00(*(LPCWSTR*)&byte_587000[32592], SubKey, 128);
	sub_414B00(*(LPCWSTR*)&byte_587000[32596], ValueName, 64);
	sub_414B00(*(LPCWSTR*)&byte_587000[32600], (LPSTR)Data, 32);
	v6 = sub_414A40(SubKey, ValueName) == 0;
	v7 = *a1;
	if (v6) {
		if (v7)
			LOBYTE(v7) = sub_414A90(SubKey, ValueName, Data);
	} else {
		LOBYTE(v7) = v7 | 4;
		*a1 = v7;
	}
	return v7;
}

//----- (00414800) --------------------------------------------------------
int sub_414800() {
	CHAR MultiByteStr[128]; // [esp+0h] [ebp-500h]
	CHAR v2[128];           // [esp+80h] [ebp-480h]
	CHAR v3[256];           // [esp+100h] [ebp-400h]
	wchar_t v4[128];        // [esp+200h] [ebp-300h]
	wchar_t v5[128];        // [esp+300h] [ebp-200h]

	if (!*(_DWORD*)&byte_5D4594[338464])
		return 0;
	sub_414B00(*(LPCWSTR*)&byte_587000[32584], MultiByteStr, 128);
	sub_414B00(*(LPCWSTR*)&byte_587000[32588], v3, 256);
	nox_wsprintfA(v2, MultiByteStr, *(_DWORD*)&byte_5D4594[338464]);
	nox_swprintf(v5, L"%S", v3);
	nox_swprintf(v4, L"%S", v2);
	nullsub_4(0, v5, v4, 262192);
	return 1;
}
// 4514E0: using guessed type void __cdecl nullsub_4(_DWORD, _DWORD, _DWORD, _DWORD);

//----- (004148D0) --------------------------------------------------------
unsigned int __cdecl sub_4148D0(LPCSTR lpFileName) {
	unsigned int v1;    // esi
	HANDLE v2;          // ebx
	_DWORD* v3;         // ebp
	const CHAR* i;      // edi
	unsigned __int8* j; // ecx
	int v6;             // edx

	v1 = -1;
	v2 = CreateFileA(lpFileName, 0x80000000, 1u, 0, 3u, 0x80u, 0);
	if (v2 == (HANDLE)-1)
		return -1;
	v3 = nox_malloc(0x2000u);
	ReadFile(v2, v3, 0x2000u, (LPDWORD)&lpFileName, 0);
	v3[10] = 0;
	for (i = lpFileName; lpFileName; i = lpFileName) {
		for (j = (unsigned __int8*)v3; i; lpFileName = i) {
			v6 = *j++;
			v1 = *(_DWORD*)&byte_581450[4 * (v6 ^ (unsigned __int8)v1) + 6160] ^ (v1 >> 8);
			--i;
		}
		ReadFile(v2, v3, 0x2000u, (LPDWORD)&lpFileName, 0);
	}
	CloseHandle(v2);
	free(v3);
	return ~v1;
}

//----- (004149A0) --------------------------------------------------------
int __cdecl sub_4149A0(LPCSTR lpFileName, LPVOID lpBuffer, LPVOID a3, LPVOID a4) {
	int v4;    // ebx
	HANDLE v5; // eax
	void* v6;  // esi

	v4 = 0;
	v5 = CreateFileA(lpFileName, 0x80000000, 1u, 0, 3u, 0x80u, 0);
	v6 = v5;
	if (v5 == (HANDLE)-1)
		return 0;
	SetFilePointer(v5, 40, 0, 0);
	if (!GetLastError() && ReadFile(v6, lpBuffer, 4u, (LPDWORD)&lpFileName, 0) &&
	    ReadFile(v6, a3, 4u, (LPDWORD)&lpFileName, 0)) {
		if (ReadFile(v6, a4, 4u, (LPDWORD)&lpFileName, 0))
			v4 = 1;
	}
	CloseHandle(v6);
	return v4;
}

//----- (00414A40) --------------------------------------------------------
int __cdecl sub_414A40(LPCSTR lpSubKey, LPCSTR lpValueName) {
	int v2; // esi

	v2 = 0;
	if (!RegOpenKeyExA(HKEY_LOCAL_MACHINE, lpSubKey, 0, 0xF003Fu, (PHKEY)&lpSubKey)) {
		if (!RegQueryValueExA((HKEY)lpSubKey, lpValueName, 0, 0, 0, 0))
			v2 = 1;
		RegCloseKey((HKEY)lpSubKey);
	}
	return v2;
}

//----- (00414A90) --------------------------------------------------------
int __cdecl sub_414A90(LPCSTR lpSubKey, LPCSTR lpValueName, BYTE* lpData) {
	int v3;              // esi
	DWORD dwDisposition; // [esp+4h] [ebp-4h]

	v3 = 0;
	if (!RegCreateKeyExA(HKEY_LOCAL_MACHINE, lpSubKey, 0, 0, 0, 0xF003Fu, 0, (PHKEY)&lpSubKey, &dwDisposition)) {
		if (!RegSetValueExA((HKEY)lpSubKey, lpValueName, 0, 1u, lpData, strlen((const char*)lpData) + 1))
			v3 = 1;
		RegCloseKey((HKEY)lpSubKey);
	}
	return v3;
}

//----- (00414B00) --------------------------------------------------------
char* __cdecl sub_414B00(LPCWSTR lpWideCharStr, LPSTR lpMultiByteStr, int cbMultiByte) {
	WideCharToMultiByte(0, 0, lpWideCharStr, -1, lpMultiByteStr, cbMultiByte, 0, 0);
	return _strrev(lpMultiByteStr);
}

//----- (00414B30) --------------------------------------------------------
int __cdecl sub_414B30(int a1, _DWORD* a2) {
	_DWORD* v2; // ebp
	_DWORD* v3; // ecx
	int v4;     // edx
	int result; // eax
	int v6;     // esi
	int v7;     // ecx
	int v8;     // edi
	int v9;     // [esp+18h] [ebp+8h]

	v2 = a2;
	v3 = a2;
	*a2 = 0;
	v4 = 0;
	v9 = 12;
	v3[1] = 0;
	v3[2] = 0;
	*((_BYTE*)v3 + 12) = 0;
	result = 128;
	do {
		v6 = 0;
		v7 = 16;
		v8 = 5;
		do {
			if ((unsigned __int8)result & *(_BYTE*)(v4 + a1))
				v6 |= v7;
			result >>= 1;
			v7 >>= 1;
			if (!result) {
				result = 128;
				++v4;
			}
			--v8;
		} while (v8);
		v2 = (_DWORD*)((char*)v2 + 1);
		*((_BYTE*)v2 - 1) = *(_BYTE*)(*(_DWORD*)&byte_587000[32604] + v6);
		--v9;
	} while (v9);
	return result;
}

//----- (00414BA0) --------------------------------------------------------
int __cdecl sub_414BA0(int a1) {
	int v1; // eax

	v1 = a1 + 4096;
	if (a1 + 4096 < 0)
		return *(_DWORD*)&byte_5D4594[338472];
	if (v1 >= 0x2000)
		v1 = 0x1FFF;
	return *(_DWORD*)&byte_5D4594[4 * v1 + 338472];
}

//----- (00414BD0) --------------------------------------------------------
int __cdecl sub_414BD0(signed int a1) {
	signed int v1; // ecx

	v1 = a1;
	if (a1 < 0)
		v1 = a1 + 25736 * ((25735 - a1) / 0x6488u);
	if (v1 >= 25736)
		v1 %= 0x6488u;
	return *(_DWORD*)&byte_5D4594[4 * ((v1 << 12) / 25736) + 2661964];
}

//----- (00414C50) --------------------------------------------------------
int __cdecl sub_414C50(signed int a1) {
	int v1;     // edi
	int v2;     // eax
	int result; // eax

	v1 = sub_414BD0(a1);
	v2 = sub_414BD0(6434 - a1);
	if (v2)
		result = (v1 << 12) / v2;
	else
		result = (v1 <= 0) + 0x7FFFFFFF;
	return result;
}

//----- (00414C90) --------------------------------------------------------
char sub_414C90() {
	__int64 v0;          // rax
	unsigned __int8* v1; // esi
	unsigned __int8* v2; // esi
	int v4;              // [esp+0h] [ebp-4h]
	int v5;              // [esp+0h] [ebp-4h]

	LOBYTE(v0) = byte_5D4594[371240];
	if (!byte_5D4594[371240]) {
		byte_5D4594[371240] = 1;
		v4 = 0;
		v1 = &byte_5D4594[2661964];
		do {
			*(_DWORD*)v1 = (__int64)(sin((double)v4 * 0.0015339808) * *(double*)&byte_581450[7200]);
			v1 += 4;
			++v4;
		} while ((int)v1 < (int)&byte_5D4594[2678348]);
		v5 = 0;
		v2 = &byte_5D4594[338472];
		do {
			v0 = (__int64)(acos((double)v5 * 0.00024414062 - 1.0) * *(double*)&byte_581450[7184]);
			*(_DWORD*)v2 = v0;
			v2 += 4;
			++v5;
		} while ((int)v2 < (int)&byte_5D4594[371240]);
	}
	return v0;
}

//----- (00414D30) --------------------------------------------------------
void sub_414D30() { nox_srand(0x9E0u); }

//----- (00414D40) --------------------------------------------------------
int __cdecl sub_414D40(int a1) {
	int* v1;             // ecx
	int v2;              // edx
	int v3;              // esi
	unsigned __int8* v4; // ecx
	unsigned __int8 v5;  // dl
	int v6;              // ecx

	v1 = *(int**)(a1 + 8);
	v2 = *v1;
	*(_DWORD*)(a1 + 8) = v1 + 1;
	if (v2 <= 0)
		return 1;
	v3 = v2;
	do {
		for (*(_DWORD*)(a1 + 8) += **(unsigned __int8**)(a1 + 8) + 10;; *(_DWORD*)(a1 + 8) = v6 + v5) {
			v4 = *(unsigned __int8**)(a1 + 8);
			v5 = *v4;
			v6 = (int)(v4 + 1);
			*(_DWORD*)(a1 + 8) = v6;
			if (!v5)
				break;
		}
		--v3;
	} while (v3);
	return 1;
}

//----- (00414DB0) --------------------------------------------------------
BOOL __cdecl sub_414DB0(int a1) {
	int v1;               // eax
	unsigned __int8* v2;  // ecx
	unsigned __int8* v3;  // ecx
	unsigned __int8* v4;  // esi
	int v5;               // edx
	int v6;               // ecx
	int* v7;              // edx
	int v8;               // esi
	int v9;               // edx
	unsigned __int8* v10; // edx
	int* v11;             // ecx
	int v12;              // edx
	unsigned __int8 v14;  // [esp+8h] [ebp+4h]
	unsigned __int8 v15;  // [esp+8h] [ebp+4h]

	v1 = a1;
	v2 = (unsigned __int8*)(*(_DWORD*)(a1 + 8) + 4);
	*(_DWORD*)(a1 + 8) = v2;
	v3 = &v2[*v2 + 13];
	*(_DWORD*)(a1 + 8) = v3;
	v4 = (unsigned __int8*)(*(_DWORD*)(a1 + 8) + 1);
	v14 = *v3;
	*(_DWORD*)(v1 + 8) = v4;
	LOBYTE(v3) = v14;
	v15 = *v4;
	*(_DWORD*)(v1 + 8) = v4 + 1;
	v4 += 3;
	v5 = (unsigned __int8)v3 * v15;
	LOBYTE(v3) = *(v4 - 2);
	*(_DWORD*)(v1 + 8) = v4;
	v6 = v5 * (unsigned __int8)v3;
	if (v6 > 0) {
		do {
			v7 = *(int**)(v1 + 8);
			v8 = *v7;
			v9 = (int)(v7 + 1);
			*(_DWORD*)(v1 + 8) = v9;
			if (v8 == -1) {
				v10 = (unsigned __int8*)(v9 + 1);
				*(_DWORD*)(v1 + 8) = v10;
				*(_DWORD*)(v1 + 8) += *v10 + 1;
			}
			--v6;
		} while (v6);
	}
	v11 = *(int**)(v1 + 8);
	v12 = *v11;
	*(_DWORD*)(v1 + 8) = v11 + 1;
	return v12 == 1162757152;
}

//----- (00414E70) --------------------------------------------------------
BOOL __cdecl sub_414E70(int a1, void* a2) {
	int v2;               // esi
	unsigned __int8* v3;  // edx
	unsigned __int8* v4;  // eax
	unsigned __int8 v5;   // cl
	unsigned __int8 v6;   // cl
	unsigned __int8* v7;  // eax
	unsigned __int8 v9;   // dl
	unsigned __int8* v10; // eax
	int v11;              // eax
	int* v12;             // ecx
	int v13;              // edx
	int v14;              // ecx
	unsigned __int8* v15; // ecx
	int* v16;             // eax
	int v17;              // ecx
	int v18;              // [esp-4h] [ebp-10h]
	unsigned __int8 v19;  // [esp+8h] [ebp-4h]
	unsigned __int8 v20;  // [esp+10h] [ebp+4h]
	unsigned __int8 v21;  // [esp+14h] [ebp+8h]

	v2 = a1;
	v18 = a1;
	v3 = (unsigned __int8*)(*(_DWORD*)(a1 + 8) + 4);
	*(_DWORD*)(a1 + 8) = v3;
	v20 = *v3;
	*(_DWORD*)(v2 + 8) = v3 + 1;
	nox_memfile_read(a2, 1u, v20, v18);
	v4 = (unsigned __int8*)(*(_DWORD*)(v2 + 8) + 9);
	*(_DWORD*)(v2 + 8) = v4;
	v5 = *v4;
	v4 += 2;
	v19 = v5;
	*(_DWORD*)(v2 + 8) = v4;
	v6 = *v4;
	v7 = v4 + 1;
	*(_DWORD*)(v2 + 8) = v7;
	if (v6 == 1)
		return 0;
	v9 = *v7;
	v10 = v7 + 1;
	*(_DWORD*)(v2 + 8) = v10;
	v21 = *v10;
	*(_DWORD*)(v2 + 8) = v10 + 1;
	v11 = 2 * v19 * (v9 + v21);
	if (v11 > 0) {
		do {
			v12 = *(int**)(v2 + 8);
			v13 = *v12;
			v14 = (int)(v12 + 1);
			*(_DWORD*)(v2 + 8) = v14;
			if (v13 == -1) {
				v15 = (unsigned __int8*)(v14 + 1);
				*(_DWORD*)(v2 + 8) = v15;
				*(_DWORD*)(v2 + 8) = &v15[*v15 + 1];
			}
			--v11;
		} while (v11);
	}
	v16 = *(int**)(v2 + 8);
	v17 = *v16;
	*(_DWORD*)(v2 + 8) = v16 + 1;
	return v17 == 1162757152;
}

//----- (00414F60) --------------------------------------------------------
BOOL __cdecl sub_414F60(_DWORD* a1, void* a2) {
	_DWORD* v2;           // esi
	void* v3;             // edi
	unsigned __int8* v4;  // eax
	int v5;               // ebp
	unsigned __int8* v6;  // eax
	unsigned __int8* v7;  // eax
	unsigned __int8* v8;  // eax
	unsigned __int8* v9;  // eax
	int v10;              // ebp
	int v11;              // edi
	int v12;              // edx
	int* v13;             // eax
	int v14;              // ecx
	int v15;              // eax
	unsigned __int8* v16; // eax
	int* v17;             // eax
	int v18;              // ecx
	BOOL result;          // eax
	_DWORD* v20;          // [esp-4h] [ebp-18h]
	int v21;              // [esp+10h] [ebp-4h]
	unsigned __int8 v22;  // [esp+18h] [ebp+4h]
	unsigned __int8 v23;  // [esp+18h] [ebp+4h]
	unsigned __int8 v24;  // [esp+18h] [ebp+4h]
	unsigned __int8 v25;  // [esp+18h] [ebp+4h]
	unsigned __int8 v26;  // [esp+18h] [ebp+4h]

	v2 = a1;
	v3 = a2;
	v20 = a1;
	v4 = (unsigned __int8*)(a1[2] + 4);
	a1[2] = v4;
	v22 = *v4;
	v2[2] = v4 + 1;
	nox_memfile_read(v3, 1u, v22, (int)v20);
	*((_BYTE*)v3 + v22) = 0;
	v2[2] += 14;
	sub_40AD60((char*)&a2, 1, 1, v2);
	v5 = 0;
	if ((_BYTE)a2) {
		while (v5 < 8) {
			v6 = (unsigned __int8*)v2[2];
			v23 = *v6;
			v2[2] = v6 + 1;
			nox_memfile_read(v3, 1u, v23, (int)v2);
			*((_BYTE*)v3 + v23) = 0;
			if (++v5 >= (unsigned __int8)a2)
				goto LABEL_4;
		}
		result = 0;
	} else {
	LABEL_4:
		v7 = (unsigned __int8*)v2[2];
		v24 = *v7;
		v2[2] = v7 + 1;
		nox_memfile_read(v3, 1u, v24, (int)v2);
		*((_BYTE*)v3 + v24) = 0;
		v8 = (unsigned __int8*)v2[2];
		v25 = *v8;
		v2[2] = v8 + 1;
		nox_memfile_read(v3, 1u, v25, (int)v2);
		*((_BYTE*)v3 + v25) = 0;
		v9 = (unsigned __int8*)v2[2];
		v26 = *v9;
		v2[2] = v9 + 1;
		nox_memfile_read(v3, 1u, v26, (int)v2);
		*((_BYTE*)v3 + v26) = 0;
		++v2[2];
		v10 = 15;
		do {
			sub_40AD60((char*)&v21, 1, 1, v2);
			if ((int)(unsigned __int8)v21 > 0) {
				v11 = (unsigned __int8)v21;
				do {
					v12 = 4;
					do {
						v13 = (int*)(v2[2] + 8);
						v2[2] = v13;
						v14 = *v13;
						v15 = (int)(v13 + 1);
						v2[2] = v15;
						if (v14 == -1) {
							v16 = (unsigned __int8*)(v15 + 1);
							v2[2] = v16;
							v2[2] = &v16[*v16 + 1];
						}
						--v12;
					} while (v12);
					--v11;
				} while (v11);
			}
			--v10;
		} while (v10);
		v17 = (int*)v2[2];
		v18 = *v17;
		v2[2] = v17 + 1;
		result = v18 == 1162757152;
	}
	return result;
}

//----- (00415100) --------------------------------------------------------
int __cdecl sub_415100_read_spells(int a1) {
	int* v1;              // ecx
	int v2;               // edx
	int v3;               // esi
	unsigned __int8* v4;  // edx
	int* v5;              // ecx
	int v6;               // edx
	int v7;               // ecx
	unsigned __int8* v8;  // ecx
	int* v9;              // ecx
	int v10;              // edx
	int v11;              // ecx
	unsigned __int8* v12; // ecx
	unsigned __int8* v13; // ecx
	__int16* v14;         // edx
	unsigned __int8* v15; // ecx
	unsigned __int8* v16; // ecx
	unsigned __int8* v17; // ecx

	v1 = *(int**)(a1 + 8);
	v2 = *v1;
	*(_DWORD*)(a1 + 8) = v1 + 1;
	if (v2 <= 0)
		return 1;
	v3 = v2;
	do {
		v4 = (unsigned __int8*)(**(unsigned __int8**)(a1 + 8) + 4 + *(_DWORD*)(a1 + 8));
		*(_DWORD*)(a1 + 8) = v4;
		v5 = (int*)(*v4 + 1 + *(_DWORD*)(a1 + 8));
		*(_DWORD*)(a1 + 8) = v5;
		v6 = *v5;
		v7 = (int)(v5 + 1);
		*(_DWORD*)(a1 + 8) = v7;
		if (v6 == -1) {
			v8 = (unsigned __int8*)(v7 + 1);
			*(_DWORD*)(a1 + 8) = v8;
			*(_DWORD*)(a1 + 8) += *v8 + 1;
		}
		v9 = *(int**)(a1 + 8);
		v10 = *v9;
		v11 = (int)(v9 + 1);
		*(_DWORD*)(a1 + 8) = v11;
		if (v10 == -1) {
			v12 = (unsigned __int8*)(v11 + 1);
			*(_DWORD*)(a1 + 8) = v12;
			*(_DWORD*)(a1 + 8) += *v12 + 1;
		}
		v13 = (unsigned __int8*)(*(_DWORD*)(a1 + 8) + 4);
		*(_DWORD*)(a1 + 8) = v13;
		v14 = (__int16*)(*v13 + 1 + *(_DWORD*)(a1 + 8));
		*(_DWORD*)(a1 + 8) = v14;
		v15 = (unsigned __int8*)v14 + *v14 + 2;
		*(_DWORD*)(a1 + 8) = v15;
		v16 = (unsigned __int8*)(*v15 + 1 + *(_DWORD*)(a1 + 8));
		*(_DWORD*)(a1 + 8) = v16;
		v17 = (unsigned __int8*)(*v16 + 1 + *(_DWORD*)(a1 + 8));
		*(_DWORD*)(a1 + 8) = v17;
		--v3;
		*(_DWORD*)(a1 + 8) += *v17 + 1;
	} while (v3);
	return 1;
}

//----- (00415240) --------------------------------------------------------
int __cdecl sub_415240(int a1) {
	int v1;               // ecx
	int* v2;              // eax
	int v3;               // edx
	int v4;               // ebp
	int result;           // eax
	_BYTE* v6;            // esi
	unsigned __int8* v7;  // esi
	unsigned __int8 v8;   // bl
	int v9;               // edi
	int* v10;             // edx
	int v11;              // esi
	int v12;              // edx
	unsigned __int8* v13; // edx
	unsigned __int8 v14;  // [esp+0h] [ebp-4h]
	char v15;             // [esp+8h] [ebp+4h]

	v1 = a1;
	v2 = *(int**)(a1 + 8);
	v3 = *v2;
	*(_DWORD*)(a1 + 8) = v2 + 1;
	if (v3 > 0) {
		v4 = v3;
		result = 1;
		while (1) {
			v6 = (_BYTE*)(**(unsigned __int8**)(v1 + 8) + 1 + *(_DWORD*)(v1 + 8));
			*(_DWORD*)(v1 + 8) = v6;
			v15 = *v6;
			*(_DWORD*)(v1 + 8) = v6 + 1;
			v7 = v6 + 1;
			if (v15 == 1 || v15 != 2)
				break;
			v8 = *v7;
			*(_DWORD*)(v1 + 8) = v7 + 2;
			v14 = v8;
			*(_DWORD*)(v1 + 8) += v7[2] + 1;
			if (v8)
				goto LABEL_7;
		LABEL_11:
			if (!--v4)
				return result;
		}
		v14 = 1;
	LABEL_7:
		v9 = v14;
		do {
			v10 = *(int**)(v1 + 8);
			v11 = *v10;
			v12 = (int)(v10 + 1);
			*(_DWORD*)(v1 + 8) = v12;
			if (v11 == -1) {
				v13 = (unsigned __int8*)(v12 + 1);
				*(_DWORD*)(v1 + 8) = v13;
				*(_DWORD*)(v1 + 8) += *v13 + 1;
			}
			--v9;
		} while (v9);
		goto LABEL_11;
	}
	return 1;
}

//----- (00415320) --------------------------------------------------------
int __cdecl sub_415320(int a1) {
	int* v1;              // ecx
	int v2;               // edx
	int v3;               // esi
	int* v4;              // ecx
	int v5;               // edx
	int v6;               // ecx
	unsigned __int8* v7;  // ecx
	int* v8;              // ecx
	int v9;               // edx
	int v10;              // ecx
	unsigned __int8* v11; // ecx
	int* v12;             // ecx
	int v13;              // edx
	int v14;              // ecx
	unsigned __int8* v15; // ecx
	__int16* v16;         // ecx
	unsigned __int8* v17; // ecx
	unsigned __int8* v18; // ecx
	unsigned __int8* v19; // ecx

	v1 = *(int**)(a1 + 8);
	v2 = *v1;
	*(_DWORD*)(a1 + 8) = v1 + 1;
	if (v2 <= 0)
		return 1;
	v3 = v2;
	do {
		v4 = (int*)(**(unsigned __int8**)(a1 + 8) + 2 + *(_DWORD*)(a1 + 8));
		*(_DWORD*)(a1 + 8) = v4;
		v5 = *v4;
		v6 = (int)(v4 + 1);
		*(_DWORD*)(a1 + 8) = v6;
		if (v5 == -1) {
			v7 = (unsigned __int8*)(v6 + 1);
			*(_DWORD*)(a1 + 8) = v7;
			*(_DWORD*)(a1 + 8) += *v7 + 1;
		}
		v8 = *(int**)(a1 + 8);
		v9 = *v8;
		v10 = (int)(v8 + 1);
		*(_DWORD*)(a1 + 8) = v10;
		if (v9 == -1) {
			v11 = (unsigned __int8*)(v10 + 1);
			*(_DWORD*)(a1 + 8) = v11;
			*(_DWORD*)(a1 + 8) += *v11 + 1;
		}
		v12 = *(int**)(a1 + 8);
		v13 = *v12;
		v14 = (int)(v12 + 1);
		*(_DWORD*)(a1 + 8) = v14;
		if (v13 == -1) {
			v15 = (unsigned __int8*)(v14 + 1);
			*(_DWORD*)(a1 + 8) = v15;
			*(_DWORD*)(a1 + 8) += *v15 + 1;
		}
		v16 = (__int16*)(**(unsigned __int8**)(a1 + 8) + 1 + *(_DWORD*)(a1 + 8));
		*(_DWORD*)(a1 + 8) = v16;
		v17 = (unsigned __int8*)v16 + *v16 + 2;
		*(_DWORD*)(a1 + 8) = v17;
		v18 = (unsigned __int8*)(*v17 + 1 + *(_DWORD*)(a1 + 8));
		*(_DWORD*)(a1 + 8) = v18;
		v19 = (unsigned __int8*)(*v18 + 1 + *(_DWORD*)(a1 + 8));
		*(_DWORD*)(a1 + 8) = v19;
		--v3;
		*(_DWORD*)(a1 + 8) += *v19 + 1;
	} while (v3);
	return 1;
}

//----- (00415470) --------------------------------------------------------
bool __cdecl sub_415470(void) {
	unsigned int* v3; // esi
	int v4;           // [esp+8h] [ebp-4h]

	int result = sub_424170("SoundSet.bin");
	if (!result)
		return 0;

	char* v1 = (char*)nox_malloc(0x40000u);
	result = (size_t*)sub_412930("Modifier.bin", v1);
	if (!result)
		return 0;

	nox_memfile* things = nox_open_thing_bin();
	if (!things)
		return 0;

	sub_40AD10(things, 0, 0);
	dword_5d4594_251540 = 0;
	dword_5d4594_251568 = 0;
	dword_5d4594_251572 = 0;
	while (nox_memfile_read(&v4, 4u, 1, things)) {
		switch (v4) {
		case 1397769548:
			if (!sub_4156B0(things, v1))
				goto LABEL_34;
			break;
		case 1096107040:
			if (nox_common_gameFlags_check_40A5C0(0x200000)) {
				sub_414D40(things);
			} else if (!sub_415660(things, v1)) {
				goto LABEL_34;
			}
			break;
		case 1096175188:
			if (nox_common_gameFlags_check_40A5C0(0x200000)) {
				sub_452B00(things);
			} else if (!sub_452890(things, v1)) {
				goto LABEL_34;
			}
			break;
		case 1463897164:
			if (!sub_410900(things, v1))
				goto LABEL_34;
			break;
		case 1179406162:
			if (!sub_411540(things, v1))
				goto LABEL_34;
			break;
		case 1162102597:
			if (!sub_411850(things, v1))
				goto LABEL_34;
			break;
		case 1094863180:
			if (!sub_415750(things, v1))
				goto LABEL_34;
			break;
		case 1229799751:
			if (!sub_415700(things, v1)) {
			LABEL_34:
				nox_memfile_free(things);
				return 0;
			}
			goto LABEL_35;
		}
	}
LABEL_35:
	nox_free_thing_bin();
	free(v1);

	return 1;
}

//----- (00415660) --------------------------------------------------------
int __cdecl sub_415660(int a1, char* a2) {
	int v2;  // ebx
	int* v3; // eax
	int v4;  // edi

	v2 = 0;
	v3 = *(int**)(a1 + 8);
	v4 = *v3;
	*(_DWORD*)(a1 + 8) = v3 + 1;
	if (v4 <= 0)
		return 1;
	while (sub_452BD0(a1, a2)) {
		if (++v2 >= v4)
			return 1;
	}
	return 0;
}

//----- (004156B0) --------------------------------------------------------
int __cdecl sub_4156B0(int a1, void* a2) {
	int v2;  // ebx
	int* v3; // eax
	int v4;  // edi

	v2 = 0;
	v3 = *(int**)(a1 + 8);
	v4 = *v3;
	*(_DWORD*)(a1 + 8) = v3 + 1;
	if (v4 <= 0)
		return 1;
	while (sub_424460(a1, a2)) {
		if (++v2 >= v4)
			return 1;
	}
	return 0;
}

//----- (00415700) --------------------------------------------------------
int __cdecl sub_415700(int a1, void* a2) {
	int* v2; // eax
	int v3;  // esi
	int v5;  // edi

	v2 = *(int**)(a1 + 8);
	v3 = *v2;
	*(_DWORD*)(a1 + 8) = v2 + 1;
	if (!sub_42F610(v3))
		return 0;
	v5 = 0;
	if (v3 > 0) {
		while (sub_42F660(a1, a2)) {
			if (++v5 >= v3)
				return 1;
		}
		return 0;
	}
	return 1;
}

//----- (00415750) --------------------------------------------------------
int __cdecl sub_415750(int a1, void* a2) {
	int v2;  // ebx
	int* v3; // eax
	int v4;  // edi

	v2 = 0;
	v3 = *(int**)(a1 + 8);
	v4 = *v3;
	*(_DWORD*)(a1 + 8) = v3 + 1;
	if (v4 <= 0)
		return 1;
	while (sub_424F00(a1, a2)) {
		if (++v2 >= v4)
			return 1;
	}
	return 0;
}

//----- (004157A0) --------------------------------------------------------
void sub_4157A0() { nox_srand(0x9E1u); }

//----- (004157B0) --------------------------------------------------------
void sub_4157B0() { nox_srand(0x964u); }

//----- (004157C0) --------------------------------------------------------
void sub_4157C0() {
	unsigned __int8* v0; // esi
	int v1;              // eax
	int v2;              // eax

	if (*(_DWORD*)&byte_5D4594[371244] != 1) {
		if (*(_DWORD*)&byte_587000[33064]) {
			v0 = &byte_587000[33064];
			do {
				if (nox_common_gameFlags_check_40A5C0(2097153))
					v1 = sub_4E3AA0(*(CHAR**)v0);
				else
					v1 = sub_44CFC0(*(CHAR**)v0);
				*((_DWORD*)v0 + 1) = v1;
				v2 = *((_DWORD*)v0 + 3);
				v0 += 12;
			} while (v2);
		}
		*(_DWORD*)&byte_5D4594[371244] = 1;
	}
}

//----- (00415820) --------------------------------------------------------
int __cdecl sub_415820(int a1) {
	int result; // eax

	result = a1;
	if (a1)
		result = sub_415880((char*)*(unsigned __int16*)(a1 + 4));
	return result;
}

//----- (00415840) --------------------------------------------------------
int __cdecl sub_415840(char* a1) {
	int v1;             // ecx
	unsigned __int8* i; // eax
	int v3;             // esi

	v1 = 0;
	if (!*(_DWORD*)&byte_587000[33064])
		return 0;
	for (i = &byte_587000[33064]; *((char**)i + 2) != a1; i += 12) {
		v3 = *((_DWORD*)i + 3);
		++v1;
		if (!v3)
			return 0;
	}
	return *(_DWORD*)&byte_587000[12 * v1 + 33068];
}

//----- (00415880) --------------------------------------------------------
int __cdecl sub_415880(char* a1) {
	int v1;             // ecx
	unsigned __int8* i; // eax
	int v3;             // esi

	v1 = 0;
	if (!*(_DWORD*)&byte_587000[33064])
		return 0;
	for (i = &byte_587000[33064]; *((char**)i + 1) != a1; i += 12) {
		v3 = *((_DWORD*)i + 3);
		++v1;
		if (!v3)
			return 0;
	}
	return *(_DWORD*)&byte_587000[12 * v1 + 33072];
}

//----- (00415910) --------------------------------------------------------
int __cdecl sub_415910(char* a1) {
	int v1;              // edi
	const char** v2;     // eax
	unsigned __int8* v3; // esi
	int v4;              // ecx

	v1 = 0;
	if (!*(_DWORD*)&byte_587000[33064])
		return 0;
	v2 = (const char**)&byte_587000[33064];
	v3 = &byte_587000[33064];
	while (_strcmpi(a1, *v2)) {
		v4 = *((_DWORD*)v3 + 3);
		v3 += 12;
		++v1;
		v2 = (const char**)v3;
		if (!v4)
			return 0;
	}
	return *(_DWORD*)&byte_587000[12 * v1 + 33072];
}

//----- (00415960) --------------------------------------------------------
int __cdecl sub_415960(wchar_t* a1) {
	int v1;              // edi
	const wchar_t** v2;  // eax
	unsigned __int8* v3; // esi
	int v4;              // ecx

	v1 = 0;
	if (!*(_DWORD*)&byte_587000[33392])
		return 0;
	v2 = (const wchar_t**)&byte_587000[33392];
	v3 = &byte_587000[33392];
	while (_nox_wcsicmp(a1, *v2)) {
		v4 = *((_DWORD*)v3 + 3);
		v3 += 12;
		++v1;
		v2 = (const wchar_t**)v3;
		if (!v4)
			return 0;
	}
	return *(_DWORD*)&byte_587000[12 * v1 + 33400];
}

//----- (004159B0) --------------------------------------------------------
char* __cdecl sub_4159B0(char* a1) {
	int v1;             // ecx
	unsigned __int8* i; // eax
	int v3;             // esi

	v1 = 0;
	if (!*(_DWORD*)&byte_587000[33064])
		return 0;
	for (i = &byte_587000[33064]; *((char**)i + 2) != a1; i += 12) {
		v3 = *((_DWORD*)i + 3);
		++v1;
		if (!v3)
			return 0;
	}
	return *(char**)&byte_587000[12 * v1 + 33064];
}

//----- (004159F0) --------------------------------------------------------
int __cdecl sub_4159F0(int a1) {
	int v1;             // ecx
	unsigned __int8* i; // eax
	int v3;             // esi

	v1 = 0;
	if (!*(_DWORD*)&byte_587000[33392])
		return 0;
	for (i = &byte_587000[33392]; *((_DWORD*)i + 2) != a1; i += 12) {
		v3 = *((_DWORD*)i + 3);
		++v1;
		if (!v3)
			return 0;
	}
	return *(_DWORD*)&byte_587000[12 * v1 + 33392];
}

//----- (00415A30) --------------------------------------------------------
int __cdecl sub_415A30(char* a1) {
	char* v1;   // eax
	int v2;     // eax
	int result; // eax

	v1 = (char*)sub_415910(a1);
	if (v1 && (v2 = sub_415840(v1)) != 0)
		result = sub_4E3B70(v2);
	else
		result = 0;
	return result;
}

//----- (00415A90) --------------------------------------------------------
void sub_415A90() { nox_srand(0x965u); }

//----- (00415AA0) --------------------------------------------------------
void sub_415AA0() { nox_srand(0x960u); }

//----- (00415AB0) --------------------------------------------------------
void sub_415AB0() {
	unsigned __int8* v0; // esi
	int v1;              // eax
	int v2;              // eax

	if (*(_DWORD*)&byte_5D4594[371252] != 1) {
		if (*(_DWORD*)&byte_587000[34848]) {
			v0 = &byte_587000[34864];
			do {
				if (nox_common_gameFlags_check_40A5C0(2097153)) {
					*((_DWORD*)v0 - 2) = sub_4E3AA0(*((CHAR**)v0 - 4));
					v1 = sub_4E3AA0(*(CHAR**)v0);
				} else {
					*((_DWORD*)v0 - 2) = sub_44CFC0(*((CHAR**)v0 - 4));
					v1 = sub_44CFC0(*(CHAR**)v0);
				}
				*((_DWORD*)v0 + 1) = v1;
				v2 = *((_DWORD*)v0 + 2);
				v0 += 24;
			} while (v2);
		}
		*(_DWORD*)&byte_5D4594[371252] = 1;
	}
}

//----- (00415B20) --------------------------------------------------------
int __cdecl sub_415B20(char* a1) {
	int v1;             // ecx
	unsigned __int8* i; // eax
	int v3;             // esi

	v1 = 0;
	if (!*(_DWORD*)&byte_587000[34848])
		return 0;
	for (i = &byte_587000[34848]; *((char**)i + 2) != a1; i += 24) {
		v3 = *((_DWORD*)i + 6);
		++v1;
		if (!v3)
			return 0;
	}
	return *(_DWORD*)&byte_587000[24 * v1 + 34868];
}

//----- (00415BD0) --------------------------------------------------------
double __cdecl sub_415BD0(int a1) {
	float* v1;     // eax
	double result; // st7

	if (*(_DWORD*)(a1 + 8) & 0x2000000 && (v1 = (float*)sub_413270(*(unsigned __int16*)(a1 + 4))) != 0)
		result = v1[16];
	else
		result = 0.0;
	return result;
}

//----- (00415C00) --------------------------------------------------------
double __cdecl sub_415C00(int a1) {
	int* v1;                                                   // edi
	float* v2;                                                 // eax
	int v4;                                                    // eax
	void(__cdecl * v5)(int, int, _DWORD, int, _DWORD, float*); // ecx
	float v6;                                                  // [esp+8h] [ebp-4h]

	v6 = 0.0;
	if (!(*(_DWORD*)(a1 + 8) & 0x2000000))
		return 0.0;
	v1 = *(int**)(a1 + 692);
	v2 = (float*)sub_413270(*(unsigned __int16*)(a1 + 4));
	if (!v2)
		return v6;
	v6 = v2[16];
	v4 = *v1;
	if (*v1) {
		v5 = *(void(__cdecl**)(int, int, _DWORD, int, _DWORD, float*))(v4 + 76);
		if (v5)
			v5(v4, a1, 0, a1, 0, &v6);
	}
	return v6;
}

//----- (00415C70) --------------------------------------------------------
int __cdecl sub_415C70(int a1) {
	int v1;     // eax
	int result; // eax

	v1 = sub_415C90(a1);
	if (v1 < 0)
		result = 0;
	else
		result = *(_DWORD*)&byte_587000[24 * v1 + 34860];
	return result;
}

//----- (00415C90) --------------------------------------------------------
int __cdecl sub_415C90(int a1) {
	int result;         // eax
	int v2;             // edx
	unsigned __int8* i; // ecx
	int v4;             // esi

	if (!a1)
		return -1;
	result = 0;
	if (!*(_DWORD*)&byte_587000[34848])
		return -1;
	HIWORD(v2) = 0;
	for (i = &byte_587000[34848];; i += 24) {
		LOWORD(v2) = *(_WORD*)(a1 + 4);
		if (v2 == *((_DWORD*)i + 2))
			break;
		v4 = *((_DWORD*)i + 6);
		++result;
		if (!v4)
			return -1;
	}
	return result;
}

//----- (00415CD0) --------------------------------------------------------
int __cdecl sub_415CD0(char* a1) {
	int v1;             // ecx
	unsigned __int8* i; // eax
	int v3;             // esi

	v1 = 0;
	if (!*(_DWORD*)&byte_587000[34848])
		return 0;
	for (i = &byte_587000[34848]; a1 != *((char**)i + 3); i += 24) {
		v3 = *((_DWORD*)i + 6);
		++v1;
		if (!v3)
			return 0;
	}
	return *(_DWORD*)&byte_587000[24 * v1 + 34856];
}

//----- (00415D10) --------------------------------------------------------
int __cdecl sub_415D10(char* a1) {
	int v1;             // ecx
	unsigned __int8* i; // eax
	int v3;             // esi

	v1 = 0;
	if (!*(_DWORD*)&byte_587000[34848])
		return 0;
	for (i = &byte_587000[34848]; a1 != *((char**)i + 2); i += 24) {
		v3 = *((_DWORD*)i + 6);
		++v1;
		if (!v3)
			return 0;
	}
	return *(_DWORD*)&byte_587000[24 * v1 + 34860];
}

//----- (00415DA0) --------------------------------------------------------
int __cdecl sub_415DA0(wchar_t* a1) {
	int v1;              // edi
	const wchar_t** v2;  // eax
	unsigned __int8* v3; // esi
	int v4;              // ecx

	v1 = 0;
	if (!*(_DWORD*)&byte_587000[35496])
		return 0;
	v2 = (const wchar_t**)&byte_587000[35496];
	v3 = &byte_587000[35496];
	while (_nox_wcsicmp(a1, *v2)) {
		v4 = *((_DWORD*)v3 + 3);
		v3 += 12;
		++v1;
		v2 = (const wchar_t**)v3;
		if (!v4)
			return 0;
	}
	return *(_DWORD*)&byte_587000[12 * v1 + 35504];
}

//----- (00415DF0) --------------------------------------------------------
int __cdecl sub_415DF0(char* a1) {
	int v1;              // edi
	const char** v2;     // eax
	unsigned __int8* v3; // esi
	int v4;              // ecx

	v1 = 0;
	if (!*(_DWORD*)&byte_587000[34848])
		return 0;
	v2 = (const char**)&byte_587000[34848];
	v3 = &byte_587000[34848];
	while (_strcmpi(a1, *v2)) {
		v4 = *((_DWORD*)v3 + 6);
		v3 += 24;
		++v1;
		v2 = (const char**)v3;
		if (!v4)
			return 0;
	}
	return *(_DWORD*)&byte_587000[24 * v1 + 34860];
}

//----- (00415E40) --------------------------------------------------------
char* __cdecl sub_415E40(char* a1) {
	int v1;             // ecx
	unsigned __int8* i; // eax
	int v3;             // esi

	v1 = 0;
	if (!*(_DWORD*)&byte_587000[34852])
		return 0;
	for (i = &byte_587000[34852]; *((char**)i + 2) != a1; i += 24) {
		v3 = *((_DWORD*)i + 6);
		++v1;
		if (!v3)
			return 0;
	}
	return *(char**)&byte_587000[24 * v1 + 34848];
}

//----- (00415E80) --------------------------------------------------------
int __cdecl sub_415E80(int a1) {
	int v1;             // ecx
	unsigned __int8* i; // eax
	int v3;             // esi

	v1 = 0;
	if (!*(_DWORD*)&byte_587000[35496])
		return 0;
	for (i = &byte_587000[35496]; *((_DWORD*)i + 2) != a1; i += 12) {
		v3 = *((_DWORD*)i + 3);
		++v1;
		if (!v3)
			return 0;
	}
	return *(_DWORD*)&byte_587000[12 * v1 + 35496];
}

//----- (00415EC0) --------------------------------------------------------
int __cdecl sub_415EC0(char* a1) {
	char* v1;   // eax
	int v2;     // eax
	int result; // eax

	v1 = (char*)sub_415DF0(a1);
	if (v1 && (v2 = sub_415CD0(v1)) != 0)
		result = sub_4E3B70(v2);
	else
		result = 0;
	return result;
}

//----- (00415F20) --------------------------------------------------------
void sub_415F20() { nox_srand(0x961u); }

//----- (00415F30) --------------------------------------------------------
int __cdecl sub_415F30(int a1) { return _write(a1, &byte_5D4594[371260], 4u); }

//----- (00415F50) --------------------------------------------------------
int __cdecl sub_415F50(int a1) { return _read(a1, &byte_5D4594[371260], 4u); }

//----- (00415F70) --------------------------------------------------------
int sub_415F70() {
	int result; // eax

	result = time(0) % 4096;
	*(_DWORD*)&byte_5D4594[371260] = result;
	dword_5d4594_371264 = result;
	return result;
}

//----- (00415FA0) --------------------------------------------------------
int __cdecl nox_common_randomInt_415FA0(int a1, int a2) {
	int result; // eax
	int v3;     // edx

	result = a2;
	v3 = *(_DWORD*)&byte_5D4594[371260];
	if (a2 - a1 != -1) {
		if (++*(int*)&byte_5D4594[371260] >= 4096)
			*(_DWORD*)&byte_5D4594[371260] = 0;
		result = a1 + *(_DWORD*)&byte_587000[4 * v3 + 37892] % (a2 - a1 + 1);
	}
	return result;
}

//----- (00415FF0) --------------------------------------------------------
int __cdecl sub_415FF0(int a1, int a2, const char* a3, int a4) {
	int v4; // edx

	v4 = (*(int*)&dword_5d4594_371264)++;
	if (*(int*)&dword_5d4594_371264 >= 4096)
		*(int*)&dword_5d4594_371264 = 0;
	return a1 + *(int*)&byte_587000[4 * v4 + 37892] % (a2 - a1 + 1);
}

//----- (00416030) --------------------------------------------------------
double __cdecl sub_416030(float a1, float a2) {
	double v2; // st7
	int v3;    // edx

	v2 = a2 - a1;
	v3 = *(int*)&byte_5D4594[371260];
	if (v2 == 0.0)
		return a2;
	if (++*(int*)&byte_5D4594[371260] >= 4096)
		*(int*)&byte_5D4594[371260] = 0;
	return v2 * ((double)*(int*)&byte_587000[4 * v3 + 37892] * 0.000030518509) + a1;
}

//----- (00416090) --------------------------------------------------------
double __cdecl sub_416090(float a1, float a2) {
	int v2; // ecx

	v2 = (dword_5d4594_371264)++;
	if (*(int*)&dword_5d4594_371264 >= 4096)
		dword_5d4594_371264 = 0;
	return (a2 - a1) * ((double)*(int*)&byte_587000[4 * v2 + 37892] * 0.000030518509) + a1;
}

//----- (004160D0) --------------------------------------------------------
int __cdecl sub_4160D0(int a1) {
	int result; // eax

	result = a1;
	if ((unsigned __int8)a1 < 0x18u) {
		result = (unsigned __int8)a1;
		*(_DWORD*)&byte_5D4594[4 * (unsigned __int8)a1 + 371268] = *(_DWORD*)&byte_5D4594[2598000];
	}
	return result;
}

//----- (004160F0) --------------------------------------------------------
BOOL __cdecl sub_4160F0(unsigned __int8 a1, unsigned int a2) {
	return a1 < 0x18u && *(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)&byte_5D4594[4 * a1 + 371268] > a2;
}

//----- (00416120) --------------------------------------------------------
BOOL __cdecl sub_416120(unsigned __int8 a1) {
	return a1 < 0x18u && *(_DWORD*)&byte_5D4594[2598000] != *(_DWORD*)&byte_5D4594[4 * a1 + 371268];
}

//----- (00416150) --------------------------------------------------------
int __cdecl sub_416150(int a1, int a2) {
	int result; // eax

	result = a1;
	if ((unsigned __int8)a1 < 0x18u) {
		result = (unsigned __int8)a1;
		*(_DWORD*)&byte_5D4594[4 * (unsigned __int8)a1 + 371268] = a2;
	}
	return result;
}

//----- (00416170) --------------------------------------------------------
int __cdecl sub_416170(int a1) {
	int result; // eax

	result = a1;
	if ((unsigned __int8)a1 < 0x18u) {
		result = (unsigned __int8)a1;
		*(_DWORD*)&byte_5D4594[4 * (unsigned __int8)a1 + 371268] = 0;
	}
	return result;
}

//----- (00416190) --------------------------------------------------------
int sub_416190() {
	int result; // eax

	result = 0;
	memset(&byte_5D4594[371268], 0, 0x60u);
	return result;
}

//----- (004161B0) --------------------------------------------------------
BOOL __cdecl sub_4161B0(unsigned __int8 a1) { return a1 < 0x18u && !*(_DWORD*)&byte_5D4594[4 * a1 + 371268]; }

//----- (004161E0) --------------------------------------------------------
int sub_4161E0() {
	int v0;              // ebx
	int v1;              // eax
	char v2;             // al
	unsigned __int16 v3; // dx
	__int16 v4;          // ax
	char* v5;            // eax
	unsigned __int8 v6;  // cl
	unsigned __int8 v7;  // cl
	int result;          // eax
	unsigned __int8 v9;  // [esp+8h] [ebp-3Ch]
	unsigned __int8 v10; // [esp+8h] [ebp-3Ch]
	char v11[4];         // [esp+Ch] [ebp-38h]
	int v12;             // [esp+10h] [ebp-34h]
	char v13[12];        // [esp+14h] [ebp-30h]
	char v14[16];        // [esp+20h] [ebp-24h]
	int v15[5];          // [esp+30h] [ebp-14h]

	sub_454040(v15);
	sub_4536B0(v11);
	v12 = sub_453710();
	v0 = sub_416F40();
	v1 = sub_409FA0();
	if (*(_DWORD*)&nox_common_engineFlags & 0x40000) {
		--v0;
		--v1;
	}
	if (byte_5D4594[371619] != v0) {
		byte_5D4594[371619] = v0;
		dword_5d4594_371692 = 1;
	}
	if (byte_5D4594[371620] != v1) {
		byte_5D4594[371620] = v1;
		dword_5d4594_371692 = 1;
	}
	if ((byte_5D4594[371618] & 0xEF) != sub_43BE50_get_video_mode_id()) {
		v2 = sub_43BE50_get_video_mode_id();
		dword_5d4594_371692 = 1;
		byte_5D4594[371618] = byte_5D4594[371618] & 0x80 | v2;
	}
	v3 = nox_common_gameFlags_getVal_40A5B0();
	v4 = *(_WORD*)&byte_5D4594[371432];
	if ((*(_WORD*)&byte_5D4594[371432] ^ v3) & 0xFFF0) {
		*(_WORD*)&byte_5D4594[371432] = nox_common_gameFlags_getVal_40A5B0();
		v4 = *(_WORD*)&byte_5D4594[371432];
		dword_5d4594_371692 = 1;
	}
	if (*(_WORD*)&byte_5D4594[371434] != sub_40A020(v4)) {
		*(_WORD*)&byte_5D4594[371434] = sub_40A020(*(__int16*)&byte_5D4594[371432]);
		dword_5d4594_371692 = 1;
	}
	if (byte_5D4594[371436] != sub_40A180(*(__int16*)&byte_5D4594[371432])) {
		byte_5D4594[371436] = sub_40A180(*(__int16*)&byte_5D4594[371432]);
		dword_5d4594_371692 = 1;
	}
	strncpy(v14, (const char*)&byte_5D4594[371389], 0xFu);
	v14[15] = 0;
	if (strcmp(v14, sub_40A4C0())) {
		v5 = sub_40A4C0();
		strncpy((char*)&byte_5D4594[371389], v5, 0xFu);
		dword_5d4594_371692 = 1;
	}
	strcpy(v13, (const char*)&byte_5D4594[371380]);
	if (strcmp(v13, sub_409B40())) {
		strcpy((char*)&byte_5D4594[371380], sub_409B40());
		dword_5d4594_371692 = 1;
	}
	v6 = 0;
	v9 = 0;
	do {
		if (*(_DWORD*)&byte_5D4594[4 * v9 + 371404] != v15[v9])
			break;
		v9 = ++v6;
	} while (v6 < 5u);
	if (v6 != 5) {
		dword_5d4594_371692 = 1;
		qmemcpy(&byte_5D4594[371404], v15, 0x14u);
	}
	if (!nox_common_gameFlags_check_40A5C0(1))
		return dword_5d4594_371692;
	if (*(_DWORD*)&byte_5D4594[371428] != v12) {
		*(_DWORD*)&byte_5D4594[371428] = v12;
		dword_5d4594_371692 = 1;
	}
	v7 = 0;
	v10 = 0;
	do {
		if (byte_5D4594[v10 + 371424] != v11[v10])
			break;
		v10 = ++v7;
	} while (v7 < 4u);
	if (v7 == 4)
		return dword_5d4594_371692;
	*(_DWORD*)&byte_5D4594[371424] = *(_DWORD*)v11;
	result = 1;
	dword_5d4594_371692 = 1;
	return result;
}
// 4161E0: using guessed type int var_14[5];

//----- (004164F0) --------------------------------------------------------
void sub_4164F0() { dword_5d4594_371692 = 0; }

//----- (00416500) --------------------------------------------------------
int sub_416500() {
	int result; // eax

	memset(&byte_5D4594[371380], 0, 0x74u);
	memset(&byte_5D4594[371516], 0, 0xA8u);
	byte_5D4594[371684] = 0;
	*(_WORD*)&byte_5D4594[371621] = -1;
	*(_WORD*)&byte_5D4594[371623] = -1;
	result = 0;
	*(_DWORD*)&byte_5D4594[371688] = 0;
	byte_5D4594[371617] = -1;
	byte_5D4594[371568] = 32;
	byte_5D4594[371569] = 32;
	*(_DWORD*)&byte_5D4594[371578] = 1;
	*(_DWORD*)&byte_5D4594[371574] = 0;
	*(_DWORD*)&byte_5D4594[371582] = 0;
	*(_DWORD*)&byte_5D4594[371586] = 0;
	*(_DWORD*)&byte_5D4594[371590] = 20;
	*(_DWORD*)&byte_5D4594[371696] = 0;
	return result;
}

//----- (00416580) --------------------------------------------------------
int sub_416580() { return *(_DWORD*)&byte_5D4594[371688]; }

//----- (00416590) --------------------------------------------------------
char* __cdecl sub_416590(int a1) { return (char*)&byte_5D4594[58 * a1 + 371380]; }

//----- (004165B0) --------------------------------------------------------
char* sub_4165B0() { return (char*)&byte_5D4594[58 * *(_DWORD*)&byte_5D4594[371688] + 371380]; }

//----- (004165D0) --------------------------------------------------------
char* __cdecl sub_4165D0(int a1) {
	*(_DWORD*)&byte_5D4594[371688] = a1;
	return (char*)&byte_5D4594[58 * a1 + 371380];
}

//----- (004165F0) --------------------------------------------------------
int __cdecl sub_4165F0(int a1, int a2) {
	int result; // eax

	result = a2;
	qmemcpy(&byte_5D4594[58 * a2 + 371380], &byte_5D4594[58 * a1 + 371380], 0x3Au);
	return result;
}

//----- (00416630) --------------------------------------------------------
char* sub_416630() { return (char*)&byte_5D4594[371616]; }

//----- (00416640) --------------------------------------------------------
char* sub_416640() { return (char*)&byte_5D4594[371516]; }

//----- (00416650) --------------------------------------------------------
int sub_416650() { return *(_DWORD*)&byte_5D4594[371700]; }

//----- (00416670) --------------------------------------------------------
int __cdecl sub_416670(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[371700] = 0;
	*(_DWORD*)&byte_5D4594[371556] = a1;
	return result;
}

//----- (00416690) --------------------------------------------------------
void sub_416690() {
	char* v0;    // esi
	char* v1;    // ebx
	__int16 v2;  // ax
	char v3[84]; // [esp+0h] [ebp-54h]

	if (sub_43AF70() == 1) {
		v0 = sub_416590(0);
		sub_4161E0();
		v1 = sub_416630();
		qmemcpy(v1 + 11, v0, 0x3Au);
		if (sub_4D6F50()) {
			v2 = *(_WORD*)(v1 + 63) & 0xFF7F;
			HIBYTE(v2) |= 0x10u;
			*(_WORD*)(v1 + 63) = v2;
			*(_WORD*)(v1 + 65) = sub_4E3CC0();
		}
		v3[sub_425550(v1, v3, 552)] = 0;
		sub_40D560((int)v3);
		sub_4164F0();
	}
}
// 416690: using guessed type char var_54[84];

//----- (00416720) --------------------------------------------------------
int sub_416720() {
	int v0;              // ebx
	unsigned __int64 v1; // rax
	int v2;              // esi
	int* v3;             // edi

	v0 = 0;
	LODWORD(v1) = sub_416900();
	v2 = v1;
	if ((_DWORD)v1) {
		do {
			v3 = sub_416910((int*)v2);
			if (*(_DWORD*)(v2 + 68) || (LODWORD(v1) = *(_DWORD*)(v2 + 64), (_DWORD)v1)) {
				v1 = sub_416BB0();
				if (v1 > *(_QWORD*)(v2 + 64))
					LODWORD(v1) = sub_416820(v0);
			}
			++v0;
			v2 = (int)v3;
		} while (v3);
	}
	return v1;
}

//----- (00416770) --------------------------------------------------------
int* __cdecl sub_416770(int a1, wchar_t* a2, const char* a3) {
	_DWORD* v3; // ebp

	v3 = nox_malloc(0x60u);
	sub_425770(v3);
	nox_wcscpy((wchar_t*)v3 + 6, a2);
	if (a3)
		strcpy((char*)v3 + 72, a3);
	else
		*((_BYTE*)v3 + 72) = 0;
	sub_4258E0((int)&byte_5D4594[371500], v3);
	if (a1) {
		*((_QWORD*)v3 + 8) = 60000 * a1 + sub_416BB0();
	} else {
		v3[16] = 0;
		v3[17] = 0;
	}
	return sub_455800();
}

//----- (00416820) --------------------------------------------------------
int* __cdecl sub_416820(int a1) {
	int* result; // eax
	int* v2;     // esi
	int v3;      // edi
	int v4;      // eax

	result = sub_416900();
	v2 = result;
	if (result) {
		v3 = a1;
		while (1) {
			v4 = v3--;
			if (!v4)
				break;
			result = sub_416910(v2);
			v2 = result;
			if (!result)
				return result;
		}
		sub_425920((_DWORD**)v2);
		free(v2);
	}
	return result;
}

//----- (00416860) --------------------------------------------------------
int* __cdecl sub_416860(int a1) {
	int* result; // eax
	int* v2;     // esi
	int v3;      // edi
	int v4;      // eax

	result = sub_4168E0();
	v2 = result;
	if (result) {
		v3 = a1;
		while (1) {
			v4 = v3--;
			if (!v4)
				break;
			result = sub_4168F0(v2);
			v2 = result;
			if (!result)
				return result;
		}
		sub_425920((_DWORD**)v2);
		free(v2);
	}
	return result;
}

//----- (004168A0) --------------------------------------------------------
int* __cdecl sub_4168A0(wchar_t* a1) {
	wchar_t* v1; // esi

	v1 = (wchar_t*)nox_malloc(0x40u);
	sub_425770(v1);
	nox_wcscpy(v1 + 6, a1);
	sub_4258E0((int)&byte_5D4594[371364], v1);
	return sub_455800();
}

//----- (004168E0) --------------------------------------------------------
int* sub_4168E0() { return sub_425890((int*)&byte_5D4594[371364]); }

//----- (004168F0) --------------------------------------------------------
int* __cdecl sub_4168F0(int* a1) { return sub_4258A0(a1); }

//----- (00416900) --------------------------------------------------------
int* sub_416900() { return sub_425890((int*)&byte_5D4594[371500]); }

//----- (00416910) --------------------------------------------------------
int* __cdecl sub_416910(int* a1) { return sub_4258A0(a1); }

//----- (00416920) --------------------------------------------------------
int sub_416920() {
	sub_425760(&byte_5D4594[371364]);
	sub_425760(&byte_5D4594[371500]);
	return sub_4E41B0((char*)&byte_587000[54280]);
}

//----- (00416950) --------------------------------------------------------
int* sub_416950() {
	int* v0;     // esi
	int* v1;     // edi
	int* result; // eax
	int* v3;     // esi
	int* v4;     // edi

	sub_4E43F0((char*)&byte_587000[54288]);
	v0 = sub_4168E0();
	if (v0) {
		do {
			v1 = sub_4168F0(v0);
			sub_425920((_DWORD**)v0);
			free(v0);
			v0 = v1;
		} while (v1);
	}
	result = sub_416900();
	v3 = result;
	if (result) {
		do {
			v4 = sub_416910(v3);
			sub_425920((_DWORD**)v3);
			free(v3);
			v3 = v4;
		} while (v4);
	}
	return result;
}

//----- (004169C0) --------------------------------------------------------
int sub_4169C0() { return *(_DWORD*)&byte_5D4594[371704]; }

//----- (004169D0) --------------------------------------------------------
int __cdecl sub_4169D0(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[371704] = a1;
	return result;
}

//----- (004169E0) --------------------------------------------------------
char* sub_4169E0() {
	char* result; // eax

	result = sub_416640();
	result[100] |= 0x10u;
	return result;
}

//----- (004169F0) --------------------------------------------------------
char* sub_4169F0() {
	char* result; // eax

	result = sub_416640();
	result[100] &= 0xEFu;
	return result;
}

//----- (00416A00) --------------------------------------------------------
unsigned int sub_416A00() {
	char* v0; // eax

	v0 = sub_416640();
	LOBYTE(v0) = v0[100];
	return ((unsigned int)v0 >> 4) & 1;
}

//----- (00416B20) --------------------------------------------------------
__int64 sdl_get_ticks() { return nox_get_ticks(); }
void __cdecl sub_416B20() {
#ifdef USE_SDL
	*(_DWORD*)&byte_5D4594[371716] = sdl_get_ticks;
#else
	LARGE_INTEGER Frequency; // [esp+0h] [ebp-8h]
	if (sub_416B80() && QueryPerformanceFrequency(&Frequency)) {
		*(_QWORD*)&byte_5D4594[371724] = Frequency.QuadPart / 1000;
		*(_DWORD*)&byte_5D4594[371716] = sub_416BC0;
	} else {
		*(_DWORD*)&byte_5D4594[371716] = sub_416BF0;
	}
#endif
}

//----- (00416B80) --------------------------------------------------------
BOOL sub_416B80() {
	return *(_DWORD*)&nox_common_engineFlags & 0x40000000 && *(_DWORD*)&nox_common_engineFlags & 0x40000 &&
	       !nox_get_audio_enabled();
}

//----- (00416BC0) --------------------------------------------------------
LONGLONG sub_416BC0() {
	LARGE_INTEGER PerformanceCount; // [esp+0h] [ebp-8h]

	QueryPerformanceCounter(&PerformanceCount);
	return PerformanceCount.QuadPart / *(_QWORD*)&byte_5D4594[371724];
}

//----- (00416BF0) --------------------------------------------------------
__int64 sub_416BF0() {
	int v0;   // esi
	int v1;   // edi
	DWORD i;  // ebx
	DWORD v3; // eax

	v0 = ++dword_5d4594_371756;
	v1 = *(_DWORD*)&byte_587000[54420];
	for (i = *(_DWORD*)&byte_587000[54416]; dword_5d4594_371756 != dword_5d4594_371756;
	     v0 = dword_5d4594_371756) {
		;
	}
	while (1) {
		v3 = nox_get_ticks();
		if (v3 < i)
			++v1;
		*(_DWORD*)&byte_587000[54420] = v1;
		*(_DWORD*)&byte_587000[54416] = v3;
		if (v0 == dword_5d4594_371756)
			break;
		v0 = dword_5d4594_371756;
	}
	return *(_QWORD*)&byte_587000[54416];
}

//----- (00416C70) --------------------------------------------------------
__int64 __cdecl sub_416C70(int a1) // frameratelimiter
{
	__int64 v1;     // rax
	__int64 result; // rax

	if (a1) {
		*(_QWORD*)&byte_5D4594[371740] = 1000 / a1;
	} else {
		*(_DWORD*)&byte_5D4594[371740] = 0;
		*(_DWORD*)&byte_5D4594[371744] = 0;
	}
	v1 = sub_416BB0();
	*(_QWORD*)&byte_5D4594[371732] = v1;
	*(_DWORD*)&byte_5D4594[371748] = *(_DWORD*)&byte_5D4594[371740] + v1;
	result = *(_QWORD*)&byte_5D4594[371740] + v1;
	*(_DWORD*)&byte_5D4594[371752] = HIDWORD(result);
	return result;
}

//----- (00416CD0) --------------------------------------------------------
BOOL sub_416CD0() {
	*(_QWORD*)&byte_5D4594[371732] = sub_416BB0();
	return *(_QWORD*)&byte_5D4594[371732] >= *(_QWORD*)&byte_5D4594[371748];
}

//----- (00416D00) --------------------------------------------------------
int sub_416D00() {
	int v0 = *(_DWORD*)&byte_5D4594[371748] - (unsigned __int64)sub_416BB0();
	if (v0 < 0 || (unsigned __int64)v0 > *(_QWORD*)&byte_5D4594[371748])
		return 0;
	return v0;
}

//----- (00416D40) --------------------------------------------------------
int sub_416D40() {
	int result; // eax

	*(_QWORD*)&byte_5D4594[371764] = sub_416BB0();
	*(_DWORD*)&byte_5D4594[371772] = *(_DWORD*)&byte_5D4594[2598000];
	result = *(_DWORD*)&nox_common_engineFlags & 0x7FFFFFFF;
	*(_DWORD*)&nox_common_engineFlags &= 0x7FFFFFFFu;
	return result;
}

//----- (00416D70) --------------------------------------------------------
BOOL sub_416D70() {
	float v2; // [esp+4h] [ebp-8h]

	v2 = (double)(unsigned int)(*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)&byte_5D4594[371772]) *
	     *(float*)&byte_587000[54424];
	return (double)(int)((unsigned __int64)sub_416BB0() - *(_DWORD*)&byte_5D4594[371764]) * 0.001 <= v2;
}

//----- (00416DD0) --------------------------------------------------------
void sub_416DD0() {
	int v1 = (__int64)((double)(unsigned int)(*(_DWORD*)&byte_5D4594[2598000] - *(_DWORD*)&byte_5D4594[371772]) *
			   *(float*)&byte_587000[54428]);
	int ms = v1 + *(_DWORD*)&byte_5D4594[371764] - (unsigned __int64)sub_416BB0();
	if (ms > 0)
		nox_sleep(ms);
}

//----- (00416E20) --------------------------------------------------------
void sub_416E20() { nox_srand(0x9D8u); }

//----- (00416E30) --------------------------------------------------------
void sub_416E30() { memset(&byte_5D4594[371780], 0, 32 * 4828); }

//----- (00416E50) --------------------------------------------------------
char* __cdecl sub_416E50(int a1) {
	char* result; // eax
	int* i;       // esi

	result = sub_416EA0();
	for (i = (int*)result; result; i = (int*)result) {
		i[534] = 0;
		i[535] = 0;
		if (a1) {
			if (i[514])
				sub_4D8EF0(i[514]);
		}
		result = sub_416EE0((int)i);
	}
	return result;
}

//----- (00416EA0) --------------------------------------------------------
char* sub_416EA0() {
	int v0;              // ecx
	unsigned __int8* v1; // eax

	v0 = 0;
	v1 = &byte_5D4594[373872];
	while (!*(_DWORD*)v1) {
		v1 += 4828;
		++v0;
		if ((int)v1 >= (int)&byte_5D4594[528368])
			return 0;
	}
	return (char*)&byte_5D4594[4828 * v0 + 371780];
}

//----- (00416EE0) --------------------------------------------------------
char* __cdecl sub_416EE0(int a1) {
	int v1;              // eax
	unsigned __int8* v2; // ecx

	if (!a1)
		return 0;
	v1 = *(unsigned __int8*)(a1 + 2064) + 1;
	if (v1 >= 32)
		return 0;
	v2 = &byte_5D4594[4828 * v1 + 373872];
	while (!*(_DWORD*)v2) {
		v2 += 4828;
		++v1;
		if ((int)v2 >= (int)&byte_5D4594[528368])
			return 0;
	}
	return (char*)&byte_5D4594[4828 * v1 + 371780];
}

//----- (00416F40) --------------------------------------------------------
int sub_416F40() {
	int result;          // eax
	unsigned __int8* v1; // ecx

	result = 0;
	v1 = &byte_5D4594[373872];
	do {
		if (*(_DWORD*)v1)
			++result;
		v1 += 4828;
	} while ((int)v1 < (int)&byte_5D4594[528368]);
	return result;
}

//----- (00416F60) --------------------------------------------------------
char* __cdecl sub_416F60(int a1) {
	char* result;        // eax
	int v2;              // ebx
	unsigned __int8* v3; // eax

	result = sub_417040(a1);
	if (!result) {
		v2 = 0;
		v3 = &byte_5D4594[373872];
		while (*(_DWORD*)v3) {
			v3 += 4828;
			++v2;
			if ((int)v3 >= (int)&byte_5D4594[528368])
				return 0;
		}
		sub_416FD0(&byte_5D4594[4828 * v2 + 371780]);
		byte_5D4594[4828 * v2 + 373844] = v2;
		result = (char*)&byte_5D4594[4828 * v2 + 371780];
		*(_DWORD*)&byte_5D4594[4828 * v2 + 373840] = a1;
	}
	return result;
}

//----- (00416FD0) --------------------------------------------------------
int __cdecl sub_416FD0(_DWORD* a1) {
	int result; // eax

	result = 0;
	memset(a1, 0, 0x12DCu);
	a1[523] = 1;
	a1[912] = 4;
	return result;
}

//----- (00417000) --------------------------------------------------------
char* __cdecl sub_417000(int a1) {
	char* result; // eax

	sub_416FD0(&byte_5D4594[4828 * a1 + 371780]);
	result = (char*)&byte_5D4594[4828 * a1 + 371780];
	byte_5D4594[4828 * a1 + 373844] = a1;
	return result;
}

//----- (00417040) --------------------------------------------------------
char* __cdecl sub_417040(int a1) {
	int v1;              // ecx
	unsigned __int8* v2; // eax

	v1 = 0;
	v2 = &byte_5D4594[373840];
	while (!*((_DWORD*)v2 + 8) || *(_DWORD*)v2 != a1) {
		v2 += 4828;
		++v1;
		if ((int)v2 >= (int)&byte_5D4594[528336])
			return 0;
	}
	byte_5D4594[4828 * v1 + 373844] = v1;
	return (char*)&byte_5D4594[4828 * v1 + 371780];
}

//----- (00417090) --------------------------------------------------------
char* __cdecl sub_417090(int a1) {
	if (!*(_DWORD*)&byte_5D4594[4828 * a1 + 373872])
		return 0;
	byte_5D4594[4828 * a1 + 373844] = a1;
	return (char*)&byte_5D4594[4828 * a1 + 371780];
}

//----- (004170D0) --------------------------------------------------------
char* __cdecl sub_4170D0(wchar_t* a1) {
	char* v1; // esi

	if (!a1)
		return 0;
	v1 = sub_416EA0();
	if (!v1)
		return 0;
	while (_nox_wcsicmp((const wchar_t*)v1 + 2352, a1)) {
		v1 = sub_416EE0((int)v1);
		if (!v1)
			return 0;
	}
	return v1;
}

//----- (00417120) --------------------------------------------------------
wchar_t* __cdecl sub_417120(int a1) {
	char* v1;        // eax
	wchar_t* result; // eax

	v1 = sub_417040(a1);
	if (v1)
		result = (wchar_t*)(v1 + 4704);
	else
		result = loadString_sub_40F1D0((char*)&byte_587000[54476], 0, (const char*)&byte_587000[54432], 204);
	return result;
}

//----- (00417190) --------------------------------------------------------
int __cdecl sub_417190(int a1, int a2, int a3) {
	int v3;              // ebx
	_DWORD* v4;          // ecx
	unsigned __int8* v5; // esi
	_DWORD* v6;          // eax
	_DWORD* v8;          // eax
	int v9;              // ecx
	int v10;             // ecx

	v3 = 0;
	if (a1 >= 0 && a1 < 32 && a2) {
		v4 = *(_DWORD**)&byte_5D4594[4828 * a1 + 376360];
		v5 = &byte_5D4594[4828 * a1 + 371780];
		if (v4) {
			if (v4[1] == a2) {
				v6 = *(_DWORD**)&byte_5D4594[4828 * a1 + 376360];
			LABEL_7:
				*v6 |= a3;
				return 1;
			}
			v6 = (_DWORD*)v4[2];
			if (v6 != v4) {
				while (v6[1] != a2) {
					v6 = (_DWORD*)v6[2];
					if (v6 == v4)
						goto LABEL_11;
				}
				goto LABEL_7;
			}
		}
	LABEL_11:
		v8 = nox_malloc(0x10u);
		if (v8) {
			v8[1] = a2;
			*v8 = a3;
			v9 = *((_DWORD*)v5 + 1145);
			if (v9) {
				v8[2] = v9;
				v10 = v8[2];
				v8[3] = *(_DWORD*)(*((_DWORD*)v5 + 1145) + 12);
				*(_DWORD*)(v10 + 12) = v8;
				*(_DWORD*)(v8[3] + 8) = v8;
				*((_DWORD*)v5 + 1145) = v8;
			} else {
				*((_DWORD*)v5 + 1145) = v8;
				v8[3] = v8;
				v8[2] = v8;
			}
			sub_4E4800(a2, (int*)1);
			v3 = 1;
		}
	}
	return v3;
}

//----- (00417270) --------------------------------------------------------
int __cdecl sub_417270(int a1) {
	int result; // eax
	int v2;     // edx
	int v3;     // ecx

	result = 0;
	if (a1 >= 0 && a1 < 32) {
		v2 = *(_DWORD*)&byte_5D4594[4828 * a1 + 376360];
		if (v2) {
			v3 = *(_DWORD*)(v2 + 8);
			for (result = 1; v3 != v2; ++result)
				v3 = *(_DWORD*)(v3 + 8);
		}
	}
	return result;
}

//----- (004172C0) --------------------------------------------------------
int __cdecl sub_4172C0(int a1) {
	int result; // eax
	int v2;     // ecx

	result = 0;
	if (a1 >= 0 && a1 < 32) {
		v2 = *(_DWORD*)&byte_5D4594[4828 * a1 + 376360];
		if (v2) {
			result = *(_DWORD*)(v2 + 4);
			*(_DWORD*)&byte_5D4594[4828 * a1 + 376360] = *(_DWORD*)(v2 + 8);
		}
	}
	return result;
}

//----- (00417300) --------------------------------------------------------
int __cdecl sub_417300(int a1, int a2, int a3) {
	int result;          // eax
	unsigned __int8* v4; // edi
	_DWORD* v5;          // ecx
	int v6;              // edx
	bool v7;             // zf
	_DWORD* v8;          // eax
	int v9;              // eax

	result = 0;
	if (a1 >= 0 && a1 < 32) {
		if (a2) {
			v4 = &byte_5D4594[4828 * a1 + 371780];
			v5 = *(_DWORD**)&byte_5D4594[4828 * a1 + 376360];
			if (v5) {
				while (1) {
					v6 = v5[2];
					if (v5[1] == a2)
						break;
					if (v6 != *(_DWORD*)&byte_5D4594[4828 * a1 + 376360]) {
						v5 = (_DWORD*)v5[2];
						if (v6)
							continue;
					}
					return result;
				}
				v7 = (~a3 & *v5) == 0;
				*v5 &= ~a3;
				if (v7) {
					v8 = (_DWORD*)*((_DWORD*)v4 + 1145);
					if ((_DWORD*)v8[2] == v8) {
						*((_DWORD*)v4 + 1145) = 0;
					} else {
						if (v8 == v5)
							*((_DWORD*)v4 + 1145) = v5[2];
						*(_DWORD*)(v5[2] + 12) = v5[3];
						*(_DWORD*)(v5[3] + 8) = v5[2];
					}
					free(v5);
					v9 = *(_DWORD*)(a2 + 20);
					LOBYTE(v9) = v9 & 0xFE;
					*(_DWORD*)(a2 + 20) = v9;
					result = 1;
				} else {
					result = 0;
				}
			}
		}
	}
	return result;
}

// mark spell -- is tracked
//----- (004173D0) --------------------------------------------------------
int __cdecl sub_4173D0(int a1, int a2) {
	int result; // eax
	int v3;     // ecx

	result = 0;
	if (a1 >= 0 && a1 < 32) {
		if (a2) {
			v3 = *(_DWORD*)&byte_5D4594[4828 * a1 + 376360];
			if (v3) {
				while (*(_DWORD*)(v3 + 4) != a2) {
					v3 = *(_DWORD*)(v3 + 8);
					if (v3 == *(_DWORD*)&byte_5D4594[4828 * a1 + 376360] || !v3)
						return result;
				}
				result = 1;
			}
		}
	}
	return result;
}

//----- (00417430) --------------------------------------------------------
char* __cdecl sub_417430(int a1) {
	char* result; // eax
	int i;        // esi

	result = sub_416EA0();
	for (i = (int)result; result; i = (int)result) {
		sub_417300(*(unsigned __int8*)(i + 2064), a1, 3);
		result = sub_416EE0(i);
	}
	return result;
}

//----- (00417470) --------------------------------------------------------
char* __cdecl sub_417470(int a1, int a2) {
	char* result; // eax
	int i;        // esi

	result = sub_416EA0();
	for (i = (int)result; result; i = (int)result) {
		sub_417300(*(unsigned __int8*)(i + 2064), a1, a2);
		result = sub_416EE0(i);
	}
	return result;
}

//----- (004174B0) --------------------------------------------------------
char* __cdecl sub_4174B0(int a1, int a2) {
	char* result; // eax
	int i;        // esi

	result = sub_416EA0();
	for (i = (int)result; result; i = (int)result) {
		sub_417190(*(unsigned __int8*)(i + 2064), a1, a2);
		result = sub_416EE0(i);
	}
	return result;
}

//----- (004174F0) --------------------------------------------------------
int __cdecl sub_4174F0(int a1, int a2) {
	int result; // eax

	*(_DWORD*)(a1 + 3680) |= a2;
	result = nox_common_gameFlags_check_40A5C0(1);
	if (result) {
		if (a2 & 0x423)
			result = sub_417630(a1);
	}
	return result;
}

//----- (00417530) --------------------------------------------------------
char __cdecl sub_417530(int a1, int a2) {
	int v2;     // eax
	__int16 v3; // ax

	*(_DWORD*)(a1 + 3680) &= ~a2;
	v2 = nox_common_gameFlags_check_40A5C0(1);
	if (v2) {
		if (a2 & 1) {
			v2 = nox_common_gameFlags_check_40A5C0(128);
			if (!v2) {
				v2 = sub_40A8A0();
				if (v2) {
					v2 = sub_40A220();
					if (!v2) {
						v3 = nox_common_gameFlags_getVal_40A5B0();
						LOBYTE(v2) = sub_40A180(v3);
						if ((_BYTE)v2) {
							sub_40A250();
							LOBYTE(v2) = sub_40A1F0(1);
						}
					}
				}
			}
		}
		if (a2 & 0x423)
			LOBYTE(v2) = sub_417630(a1);
	}
	return v2;
}
// 417577: variable 'v2' is possibly undefined

//----- (004175C0) --------------------------------------------------------
char* __cdecl sub_4175C0(int a1) {
	char* result; // eax
	int i;        // esi
	int v3;       // [esp-18h] [ebp-24h]
	char v4[7];   // [esp+4h] [ebp-8h]

	result = sub_416EA0();
	for (i = (int)result; result; i = (int)result) {
		v4[0] = 106;
		*(_WORD*)&v4[1] = *(_WORD*)(i + 2060);
		v3 = *(unsigned __int8*)(a1 + 2064);
		*(_DWORD*)&v4[3] = *(_DWORD*)(i + 3680) & 0x423;
		sub_4E5390(v3, (int)v4, 7, 0, 0);
		result = sub_416EE0(i);
	}
	return result;
}

//----- (00417630) --------------------------------------------------------
int __cdecl sub_417630(int a1) {
	__int16 v1; // cx
	int v2;     // edx
	char v4[7]; // [esp+0h] [ebp-8h]

	v1 = *(_WORD*)(a1 + 2060);
	v2 = *(_DWORD*)(a1 + 3680) & 0x423;
	v4[0] = 106;
	*(_WORD*)&v4[1] = v1;
	*(_DWORD*)&v4[3] = v2;
	return sub_4E5390(255, (int)v4, 7, 0, 0);
}

//----- (00417680) --------------------------------------------------------
void __cdecl sub_417680(int a1, char a2) {
	int v2;     // esi
	int v3;     // eax
	int v4;     // ecx
	_DWORD* v5; // edi
	int v6;     // eax
	int v7;     // ecx
	_DWORD* v8; // edi
	int v9;     // eax
	int v10;    // edi
	int v11;    // eax
	int v12;    // edx
	char v13;   // dl
	int v14;    // eax
	char v15;   // al
	int v16;    // eax
	int v17;    // eax
	int v18;    // eax
	int v19;    // eax
	char v20;   // cl
	int v21;    // eax
	int v22;    // eax
	char v23;   // cl
	int v24;    // eax
	int v25;    // [esp-Ch] [ebp-18h]
	int v26;    // [esp-Ch] [ebp-18h]

	v2 = a1;
	if (!a1) {
		return;
	}
	if (!nox_common_gameFlags_check_40A5C0(1))
		*(_DWORD*)(v2 + 4) = 0;
	v3 = v2 + 2328;
	v4 = 27;
	do {
		v5 = (_DWORD*)v3;
		*(_DWORD*)(v3 - 4) = 0;
		v3 += 24;
		*v5 = 0;
		--v4;
		v5[1] = 0;
		v5[2] = 0;
		v5[3] = 0;
	} while (v4);
	if (!nox_common_gameFlags_check_40A5C0(1))
		*(_DWORD*)v2 = 0;
	v6 = v2 + 2976;
	v7 = 26;
	do {
		v8 = (_DWORD*)v6;
		*(_DWORD*)(v6 - 4) = 0;
		v6 += 24;
		*v8 = 0;
		--v7;
		v8[1] = 0;
		v8[2] = 0;
		v8[3] = 0;
	} while (v7);
	v9 = sub_413290("UserColor1");
	v10 = sub_413330(v9);
	if (!v10) {
		return;
	}
	if (*(_BYTE*)(v2 + 2251) || nox_common_gameFlags_check_40A5C0(2048)) {
		LOBYTE(a1) = -1;
		v11 = sub_413330(*(_DWORD*)(v10 + 4) + *(unsigned __int8*)(v2 + 2269));
		v12 = *(unsigned __int8*)(v2 + 2270);
		BYTE1(a1) = *(_BYTE*)(v11 + 4);
		BYTE2(a1) = *((_BYTE*)sub_413330(*(_DWORD*)(v10 + 4) + v12) + 4);
		HIBYTE(a1) = -1;
		if (a2 & 1)
			sub_417AA0(82, *(_DWORD*)(v2 + 2060), 1024, (int)&a1);
	}
	LOBYTE(a1) = -1;
	BYTE1(a1) = *((_BYTE*)sub_413330(*(_DWORD*)(v10 + 4) + *(unsigned __int8*)(v2 + 2268)) + 4);
	HIWORD(a1) = -1;
	if (a2 & 2)
		sub_417AA0(82, *(_DWORD*)(v2 + 2060), 4, (int)&a1);
	v13 = *((_BYTE*)sub_413330(*(_DWORD*)(v10 + 4) + *(unsigned __int8*)(v2 + 2272)) + 4);
	v14 = *(unsigned __int8*)(v2 + 2271);
	LOBYTE(a1) = v13;
	BYTE1(a1) = *((_BYTE*)sub_413330(*(_DWORD*)(v10 + 4) + v14) + 4);
	HIWORD(a1) = -1;
	if (a2 & 4)
		sub_417AA0(82, *(_DWORD*)(v2 + 2060), 1, (int)&a1);
	v15 = *(_BYTE*)(v2 + 2251);
	a1 = -1;
	if (v15 == 1) {
		if (nox_common_gameFlags_check_40A5C0(2048)) {
			if (a2 & 8) {
				v16 = sub_413290("ArmorQuality1");
				LOBYTE(a1) = *((_BYTE*)sub_413330(v16) + 4);
				sub_417AA0(80, *(_DWORD*)(v2 + 2060), 0x8000, (int)&a1);
			}
		} else if (nox_common_gameFlags_check_40A5C0(4096)) {
			a1 = -1;
			v17 = sub_413290("Replenishment1");
			BYTE2(a1) = *((_BYTE*)sub_413330(v17) + 4);
			sub_417AA0(80, *(_DWORD*)(v2 + 2060), 0x10000, (int)&a1);
		} else if (a2 & 0x10) {
			sub_417AA0(79, *(_DWORD*)(v2 + 2060), 0x4000, (int)&a1);
		}
	}
	if (!*(_BYTE*)(v2 + 2251)) {
		if (nox_common_gameFlags_check_40A5C0(2048)) {
			if (a2 & 0x20) {
				v18 = sub_413290("ArmorQuality1");
				LOBYTE(a1) = *((_BYTE*)sub_413330(v18) + 4);
				v19 = sub_413290("Material1");
				v20 = *((_BYTE*)sub_413330(v19) + 4);
				v21 = *(_DWORD*)(v2 + 2060);
				LOBYTE(a1) = v20;
				sub_417AA0(80, v21, 256, (int)&a1);
			}
		} else if (nox_common_gameFlags_check_40A5C0(4096)) {
			v25 = *(_DWORD*)(v2 + 2060);
			a1 = -1;
			sub_417AA0(80, v25, 256, (int)&a1);
		} else {
			if (a2 & 0x40)
				sub_417AA0(80, *(_DWORD*)(v2 + 2060), 512, (int)&a1);
			if (a2 < 0)
				sub_417AA0(79, *(_DWORD*)(v2 + 2060), 0x1000000, (int)&a1);
		}
	}
	if (*(_BYTE*)(v2 + 2251) == 2) {
		if (nox_common_gameFlags_check_40A5C0(2048)) {
			if (a2 & 8) {
				v22 = sub_413290("ArmorQuality1");
				v23 = *((_BYTE*)sub_413330(v22) + 4);
				v24 = *(_DWORD*)(v2 + 2060);
				LOBYTE(a1) = v23;
				sub_417AA0(80, v24, 0x8000, (int)&a1);
			}
		} else if (nox_common_gameFlags_check_40A5C0(4096)) {
			v26 = *(_DWORD*)(v2 + 2060);
			a1 = -1;
			sub_417AA0(80, v26, 4, (int)&a1);
		}
	}
}

//----- (00417AA0) --------------------------------------------------------
char* __cdecl sub_417AA0(char a1, int a2, int a3, int a4) {
	char* result; // eax
	char* v5;     // edx
	int v6;       // ecx
	int v7;       // esi
	char* v8;     // edi
	char* v9;     // edx
	int v10;      // ecx
	int v11;      // esi
	char* v12;    // edi

	result = sub_417040(a2);
	if (result) {
		if (a1 == 81 || a1 == 80) {
			v9 = result + 2324;
			*((_DWORD*)result + 1) |= a3;
			v10 = 0;
			while (*(_DWORD*)v9) {
				++v10;
				v9 += 24;
				if (v10 >= 27)
					return result;
			}
			*(_DWORD*)&result[24 * v10 + 2324] = a3;
			v11 = 0;
			v12 = &result[24 * v10 + 2328];
			do {
				result = (char*)sub_413330(*(unsigned __int8*)(v11 + a4));
				*(_DWORD*)v12 = result;
				++v11;
				v12 += 4;
			} while (v11 < 4);
		} else {
			v5 = result + 2972;
			*(_DWORD*)result |= a3;
			v6 = 0;
			while (*(_DWORD*)v5) {
				++v6;
				v5 += 24;
				if (v6 >= 26)
					return result;
			}
			*(_DWORD*)&result[24 * v6 + 2972] = a3;
			v7 = 0;
			v8 = &result[24 * v6 + 2976];
			do {
				result = (char*)sub_413330(*(unsigned __int8*)(v7 + a4));
				*(_DWORD*)v8 = result;
				++v7;
				v8 += 4;
			} while (v7 < 4);
		}
	}
	return result;
}

//----- (00417B80) --------------------------------------------------------
char* __cdecl sub_417B80(char a1, int a2, int a3) {
	char* result; // eax
	int v4;       // ecx
	int v5;       // edx
	int v6;       // ecx
	char* i;      // edx
	int v8;       // edx
	int v9;       // ecx
	char* j;      // edx

	result = sub_417040(a2);
	if (result) {
		v4 = ~a3;
		if (a1 == 84) {
			v5 = v4 & *((_DWORD*)result + 1);
			v6 = 0;
			*((_DWORD*)result + 1) = v5;
			for (i = result + 2324; *(_DWORD*)i != a3; i += 24) {
				if (++v6 >= 27)
					return result;
			}
			*(_DWORD*)&result[24 * v6 + 2324] = 0;
		} else {
			v8 = v4 & *(_DWORD*)result;
			v9 = 0;
			*(_DWORD*)result = v8;
			for (j = result + 2972; *(_DWORD*)j != a3; j += 24) {
				if (++v9 >= 26)
					return result;
			}
			*(_DWORD*)&result[24 * v9 + 2972] = 0;
		}
	}
	return result;
}

//----- (00417C00) --------------------------------------------------------
char* __cdecl sub_417C00(char* a1, int a2) {
	char* result; // eax
	int i;        // esi

	result = sub_416EA0();
	for (i = (int)result; result; i = (int)result) {
		if (!_strcmpi((const char*)(i + 2096), a1))
			*(_DWORD*)(i + 2108) = a2;
		result = sub_416EE0(i);
	}
	return result;
}

//----- (00417C50) --------------------------------------------------------
void sub_417C50() { nox_srand(0x9D9u); }

//----- (00417CF0) --------------------------------------------------------
int sub_417CF0() { return sub_419030(0); }

//----- (00417D00) --------------------------------------------------------
int sub_417D00() {
	unsigned __int8* v1; // eax
	int result;          // eax
	__int16 v3;          // [esp+0h] [ebp-2h]

	v1 = &byte_5D4594[526424];
	do {
		*(_DWORD*)v1 = 0;
		v1 += 80;
	} while ((int)v1 < (int)&byte_5D4594[527704]);
	result = nox_common_gameFlags_check_40A5C0(1);
	if (result == 1) {
		v3 = 2500;
		result = sub_4E5390(159, (int)&v3, 2, 0, 1);
	}
	return result;
}

//----- (00417D50) --------------------------------------------------------
int __cdecl sub_417D50(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[526284] |= a1;
	return result;
}

//----- (00417D70) --------------------------------------------------------
int __cdecl sub_417D70(int a1) {
	int result; // eax

	result = ~a1;
	*(_DWORD*)&byte_5D4594[526284] &= ~a1;
	return result;
}

//----- (00417D90) --------------------------------------------------------
int sub_417D90() { return *(_DWORD*)&byte_5D4594[526284]; }

//----- (00417DA0) --------------------------------------------------------
BOOL __cdecl sub_417DA0(int a1) { return (a1 & *(_DWORD*)&byte_5D4594[526284]) != 0; }

//----- (00417DC0) --------------------------------------------------------
int sub_417DC0() { return dword_5d4594_526276; }

//----- (00417DD0) --------------------------------------------------------
unsigned __int8 sub_417DD0() { return byte_5D4594[526280]; }

//----- (00417DE0) --------------------------------------------------------
char sub_417DE0() {
	char v0; // bl
	char* i; // eax

	v0 = 0;
	for (i = sub_418B10(); i; i = sub_418B60((int)i)) {
		if (*((_DWORD*)i + 15))
			++v0;
	}
	return v0;
}

//----- (00417EA0) --------------------------------------------------------
int sub_417EA0() {
	int v0; // eax
	int v1; // esi

	LOBYTE(v0) = sub_417EC0();
	v1 = v0;
	if (v0)
		sub_455A50(2);
	return v1;
}
// 417EA6: variable 'v0' is possibly undefined

//----- (00417EC0) --------------------------------------------------------
bool sub_417EC0() {
	int i; // eax

	sub_416640();
	dword_5d4594_526276 = 0;
	for (i = sub_4DA790(); i; i = sub_4DA7A0(i)) {
		if (*(_DWORD*)(i + 8) & 0x10000000)
			++dword_5d4594_526276;
	}
	if (dword_5d4594_526276 > 0 && !nox_common_gameFlags_check_40A5C0(0x8000))
		sub_4181F0(0);
	return dword_5d4594_526276 > 0;
}

//----- (00417F30) --------------------------------------------------------
char sub_417F30() {
	int v0; // eax

	LOBYTE(v0) = sub_417EC0();
	if (v0) {
		sub_455F60();
		LOBYTE(v0) = sub_417F50(0);
	}
	return v0;
}
// 417F37: variable 'v0' is possibly undefined

//----- (00417F50) --------------------------------------------------------
int __cdecl sub_417F50(int a1) {
	int v1;     // esi
	int v2;     // eax
	int v3;     // esi
	int v4;     // ebx
	_DWORD* v6; // eax
	_DWORD* v7; // esi
	int v8;     // edi
	int i;      // edi
	float v10;  // [esp+0h] [ebp-14h]

	if (!*(_DWORD*)&byte_5D4594[527656])
		*(_DWORD*)&byte_5D4594[527656] = sub_4E3AA0((CHAR*)&byte_587000[55172]);
	v1 = 0;
	v2 = sub_4DA790();
	if (!v2)
		return 0;
	do {
		if (*(unsigned __int16*)(v2 + 4) == *(_DWORD*)&byte_5D4594[527656])
			++v1;
		v2 = sub_4DA7A0(v2);
	} while (v2);
	if (!v1)
		return 0;
	v3 = nox_common_randomInt_415FA0(0, v1 - 1);
	v4 = sub_4DA790();
	if (!v4)
		return 0;
	while (*(unsigned __int16*)(v4 + 4) != *(_DWORD*)&byte_5D4594[527656]) {
	LABEL_12:
		v4 = sub_4DA7A0(v4);
		if (!v4)
			return 0;
	}
	if (v3) {
		--v3;
		goto LABEL_12;
	}
	v6 = sub_4E3810((CHAR*)&byte_587000[55224]);
	v7 = v6;
	if (!v6)
		return 0;
	v8 = v6[187];
	*(_QWORD*)(v8 + 8) = sub_416BB0();
	v10 = sub_419D40(&byte_587000[55236]);
	*(_DWORD*)(v8 + 20) = nox_float2int(v10);
	*(float*)(v8 + 24) = sub_419D40(&byte_587000[55260]);
	sub_4174B0((int)v7, 1);
	sub_4DAA50((int)v7, 0, 0.0, 0.0);
	sub_4EC300((int)v7);
	sub_4EB9B0((int)v7, 0);
	sub_4E8290(0, 0);
	sub_4E7010((int)v7, (float2*)(v4 + 56));
	v7[20] = 0;
	v7[21] = 0;
	v7[22] = 0;
	v7[25] = 0;
	if (a1) {
		for (i = sub_4DA7C0(); i; i = sub_4DA7F0(i)) {
			if (*(_DWORD*)(*(_DWORD*)(*(_DWORD*)(i + 748) + 276) + 3628) == a1) {
				sub_4E6040(i);
				sub_4E6060(i, (int)v7);
			}
		}
		sub_4E5CC0(a1);
	}
	return 1;
}

//----- (004180D0) --------------------------------------------------------
int sub_4180D0() {
	int v0;   // esi
	int v1;   // edi
	char* i;  // eax
	int v3;   // ebp
	int v4;   // esi
	int v5;   // edi
	bool v6;  // zf
	char v7;  // al
	char* v8; // eax

	if (!*(_DWORD*)&byte_5D4594[527652])
		*(_DWORD*)&byte_5D4594[527652] = sub_4E3AA0((CHAR*)&byte_587000[55280]);
	v0 = sub_4DA790();
	if (v0) {
		do {
			v1 = sub_4DA7A0(v0);
			if (*(_DWORD*)(v0 + 8) & 0x10000000)
				sub_4E5CC0(v0);
			v0 = v1;
		} while (v1);
	}
	for (i = sub_418B10(); i; i = sub_418B60((int)i))
		*((_DWORD*)i + 19) = 0;
	v3 = 0;
	v4 = sub_4DA790();
	if (!v4)
		return 0;
	do {
		v5 = sub_4DA7A0(v4);
		if (*(unsigned __int16*)(v4 + 4) != *(_DWORD*)&byte_5D4594[527652])
			goto LABEL_19;
		++v3;
		*(_DWORD*)(*(_DWORD*)(v4 + 748) + 4) = 0;
		v6 = !sub_417DA0(4);
		v7 = *(_BYTE*)(v4 + 52);
		if (v6) {
			if (v7) {
				sub_4E5CC0(v4);
				sub_4EC6A0(v4);
				goto LABEL_19;
			}
			goto LABEL_18;
		}
		if (!v7) {
			sub_4E5CC0(v4);
			sub_4EC6A0(v4);
			goto LABEL_19;
		}
		v8 = sub_418AB0(*(unsigned __int8*)(v4 + 52));
		if (v8) {
			*((_DWORD*)v8 + 19) = v4;
		LABEL_18:
			sub_4174B0(v4, 1);
		}
	LABEL_19:
		v4 = v5;
	} while (v5);
	if (!v3)
		return 0;
	return 1;
}

//----- (004181F0) --------------------------------------------------------
char* __cdecl sub_4181F0(int a1) {
	unsigned __int8 v1;  // bl
	char* i;             // esi
	char* result;        // eax
	char* v4;            // esi
	int v5;              // ecx
	int v6;              // eax
	int v7;              // ecx
	bool v8;             // cc
	unsigned __int8 v9;  // bl
	int v10;             // edi
	int* v11;            // eax
	int v12;             // edx
	int* v13;            // ebx
	char* v14;           // ebp
	int v15;             // esi
	int v16;             // edi
	int v17;             // edx
	char* v18;           // eax
	unsigned __int8 v19; // [esp+10h] [ebp-88h]
	unsigned __int8 v20; // [esp+10h] [ebp-88h]
	unsigned __int8 v21; // [esp+14h] [ebp-84h]
	int v22[32];         // [esp+18h] [ebp-80h]

	v1 = 0;
	v19 = 0;
	if (a1) {
		for (i = sub_418B10(); i; i = sub_418B60((int)i))
			sub_418D80((int)i);
	}
	result = sub_416EA0();
	v4 = result;
	if (result) {
		do {
			v5 = *((_DWORD*)v4 + 514);
			if (v5 && (*((_DWORD*)v4 + 515) != *(_DWORD*)&byte_5D4594[2616328] ||
				   !(*(_DWORD*)&nox_common_engineFlags & 0x40000))) {
				v6 = *((_DWORD*)v4 + 920);
				if ((!(v6 & 1) || v6 & 0x20) && !sub_419130(v5 + 48)) {
					v7 = v19;
					v19 = ++v1;
					v22[v7] = *((_DWORD*)v4 + 514);
				}
			}
			result = sub_416EE0((int)v4);
			v4 = result;
		} while (result);
		if (v1) {
			v8 = v1 <= 1u;
			v9 = v19;
			if (!v8) {
				v10 = 50;
				do {
					v20 = nox_common_randomInt_415FA0(0, v9 - 1);
					v21 = nox_common_randomInt_415FA0(0, v9 - 1);
					v11 = &v22[v20];
					--v10;
					v12 = *v11;
					*v11 = v22[v21];
					v22[v21] = v12;
				} while (v10);
			}
			result = (char*)v9;
			if ((int)v9 > 0) {
				v13 = v22;
				v14 = result;
				do {
					v15 = *v13;
					v16 = *(_DWORD*)(*v13 + 748);
					if (sub_40A740()) {
						v17 = *(_DWORD*)(v16 + 276);
						result = *(char**)(v17 + 2068);
						if (result) {
							result = sub_418AE0(*(_DWORD*)(v17 + 2068));
							if (result)
								result = sub_4191D0(result[57], v15 + 48, 1,
										    *(_DWORD*)(v15 + 36), 0);
						}
					} else {
						v18 = sub_4189D0();
						result = sub_4191D0(v18[57], v15 + 48, 1, *(_DWORD*)(v15 + 36), 1);
					}
					++v13;
					--v14;
				} while (v14);
			}
		}
	}
	return result;
}
// 4181F0: using guessed type int var_80[32];

//----- (00418390) --------------------------------------------------------
int sub_418390() {
	if (!byte_5D4594[526280])
		return 0;
	sub_417D50(2);
	sub_4181F0(0);
	return 1;
}

//----- (004183C0) --------------------------------------------------------
int sub_4183C0() {
	int result; // eax
	int i;      // esi
	int v2;     // eax
	int v3;     // eax
	int v4;     // eax
	char* v5;   // ebp
	int v6;     // edi
	char* v7;   // ecx
	int v8;     // eax
	double v9;  // st7
	double v10; // st6
	double v11; // st5
	float v12;  // [esp+0h] [ebp-4h]

	result = sub_4DA7C0();
	for (i = result; result; i = result) {
		v2 = *(_DWORD*)(i + 748);
		if (!v2 || ((v3 = *(_DWORD*)(v2 + 276), *(_DWORD*)(v3 + 2060) != *(_DWORD*)&byte_5D4594[2616328]) ||
			    !(*(_DWORD*)&nox_common_engineFlags & 0x40000)) &&
			       ((v4 = *(_DWORD*)(v3 + 3680), !(v4 & 1)) || v4 & 0x20)) {
			v5 = sub_418AB0(*(unsigned __int8*)(i + 52));
			v6 = 0;
			v12 = 1000000000.0;
			v7 = sub_418B10();
			if (v7) {
				do {
					v8 = *((_DWORD*)v7 + 18);
					if (v8) {
						v9 = *(float*)(v8 + 60) - *(float*)(i + 60);
						v10 = *(float*)(v8 + 56) - *(float*)(i + 56);
						v11 = v10 * v10 + v9 * v9;
						if (v11 < v12) {
							v12 = v11;
							v6 = (int)v7;
						}
					}
					v7 = sub_418B60((int)v7);
				} while (v7);
				if (v6) {
					if (v5) {
						if ((char*)v6 != v5)
							sub_4196D0(i + 48, v6, *(_DWORD*)(i + 36), 0);
					} else {
						sub_4191D0(*(_BYTE*)(v6 + 57), i + 48, 1, *(_DWORD*)(i + 36), 0);
					}
				}
			}
		}
		result = sub_4DA7F0(i);
	}
	return result;
}

//----- (004184D0) --------------------------------------------------------
void __cdecl sub_4184D0(wchar_t* a1) {
	int v1;      // edi
	_DWORD* v2;  // ebp
	char v3[18]; // [esp+4h] [ebp-14h]

	if (a1) {
		sub_457230(a1);
		*(_DWORD*)&v3[6] = *((_DWORD*)a1 + 15);
		*(_DWORD*)&v3[2] = *((unsigned __int8*)a1 + 57);
		*(_WORD*)v3 = 196;
		*(_DWORD*)&v3[10] = *((_DWORD*)a1 + 13);
		v3[14] = 0;
		v3[16] = *((_BYTE*)a1 + 56);
		v3[17] = *((_BYTE*)a1 + 68);
		if (nox_common_gameFlags_check_40A5C0(512))
			v3[14] = 1;
		v3[15] = nox_wcslen(a1);
		v1 = 2 * (unsigned __int8)v3[15];
		v2 = nox_malloc(v1 + 18);
		*(_QWORD*)v2 = *(_QWORD*)v3;
		v2[2] = *(_DWORD*)&v3[8];
		v2[3] = *(_DWORD*)&v3[12];
		*((_WORD*)v2 + 8) = *(_WORD*)&v3[16];
		qmemcpy((char*)v2 + 18, a1, 2 * (unsigned __int8)v3[15]);
		sub_4E5390(159, (int)v2, v1 + 18, 0, 1);
		free(v2);
	}
}

//----- (004185B0) --------------------------------------------------------
int sub_4185B0() {
	int result;  // eax
	int i;       // esi
	char* v2;    // edi
	int v3;      // eax
	char v4;     // bl
	wchar_t* v5; // eax

	sub_417D50(4);
	sub_4186D0(0);
	sub_4186D0(0);
	result = sub_4DA790();
	for (i = result; result; i = result) {
		if (*(_DWORD*)(i + 8) & 0x10000000) {
			v2 = sub_418AB0(*(unsigned __int8*)(i + 52));
			if (v2) {
				v3 = sub_4ECBD0(i);
				v4 = v3;
				v5 = sub_418C20(v3);
				if (v5)
					sub_418800((wchar_t*)v2, v5, 1);
				v2[56] = v4;
				sub_4184D0((wchar_t*)v2);
				*((_DWORD*)v2 + 18) = i;
			}
		}
		result = sub_4DA7A0(i);
	}
	return result;
}

//----- (00418640) --------------------------------------------------------
int sub_418640() {
	int result; // eax
	int i;      // esi
	char v2;    // bl
	char* v3;   // eax

	result = sub_4DA790();
	for (i = result; result; i = result) {
		if (*(_DWORD*)(i + 8) & 0x10000000) {
			v2 = sub_4ECBD0(i);
			v3 = sub_418AB0(*(unsigned __int8*)(i + 52));
			if (v3) {
				v3[56] = v2;
				*((_DWORD*)v3 + 18) = i;
			}
		}
		result = sub_4DA7A0(i);
	}
	return result;
}

//----- (00418690) --------------------------------------------------------
char* __cdecl sub_418690(int a1) {
	char* result; // eax
	char* i;      // esi
	int v3;       // [esp-8h] [ebp-Ch]

	result = sub_418B10();
	for (i = result; result; i = result) {
		if (*((_DWORD*)i + 18)) {
			v3 = *((_DWORD*)i + 18);
			if (a1)
				sub_4E75B0(v3);
			else
				sub_4E7600(v3);
		}
		result = sub_418B60((int)i);
	}
	return result;
}
