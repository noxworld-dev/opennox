//+build none

#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif

#include "common__net_list.h"
#include "common__random.h"
#include "common__system__team.h"

#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2_3.h"
#include "GAME3_2.h"
#include "GAME5.h"
#include "GAME5_2.h"
#include "client__gui__window.h"
#include "client__network__netclint.h"
#include "client__video__draw_common.h"
#include "common/fs/nox_fs.h"
#include "thing.h"

void cmain_loop(int);
// defined in GAME1.c
extern uint32_t nox_game_loop_xxx_805872;
extern uint32_t dword_5d4594_2660032;
extern uint32_t dword_5d4594_815704;
extern uint32_t dword_5d4594_815708;
extern uint32_t dword_5d4594_3844304;
extern uint32_t dword_5d4594_2649712;
extern void (*mainloop_enter)(void*);
extern void* mainloop_enter_args;
extern int mainloop_exit_path;
extern int g_v20, g_v21;
extern int g_argc2;
extern char** g_argv2;
extern unsigned int nox_frame_xxx_2598000;
extern nox_net_struct_t* nox_net_struct_arr[NOX_NET_STRUCT_MAX];

typedef union {
	struct {
		uint8_t data[153];
		const char* hostname;
		uint16_t port;
	} connect_server;

	struct {
		uint8_t data[153];
		unsigned int id;
		const char* hostname;
		uint16_t port;
	} net_connect;

	struct {
		uint8_t data[153];
		unsigned int id;
		char val;
		unsigned int retries;
		unsigned int flags;
		unsigned int counter;
	} net_connect_wait_loop;

	struct {
		uint8_t data[153];
		unsigned int id;
		int result;
	} net_connect_wait_then;

	struct {
		int result;
	} net_connect_then;

	struct {
		unsigned long long timeout;
	} connect_wait_loop;

	struct {
		int result;
	} connect_wait_then;

	struct {
		int result;
	} connect_result;

} sm_args_t;

void CONNECT_PREPARE(sm_args_t* args);
void CONNECT_SERVER(sm_args_t* args);
void NET_CONNECT(sm_args_t* args);
void NET_CONNECT_WAIT_LOOP(sm_args_t* args);
void NET_CONNECT_WAIT_THEN(sm_args_t* args);
void NET_CONNECT_THEN(sm_args_t* args);
void CONNECT_WAIT_LOOP(sm_args_t* args);
void CONNECT_WAIT_THEN(sm_args_t* args);
void CONNECT_RESULT(sm_args_t* args);

#define GOTO_(state)                                                                                                   \
	{                                                                                                                  \
		mainloop_enter = state;                                                                                        \
		mainloop_enter_args = args;                                                                                    \
		printf("goto %s\n", #state);                                                                                   \
		return;                                                                                                        \
	}

#define GOTO_CONNECT_PREPARE()                                                                                         \
	{ GOTO_(CONNECT_PREPARE); }

#define GOTO_CONNECT_SERVER(hostname_, port_, data_)                                                                   \
	{                                                                                                                  \
		args->connect_server.hostname = hostname_;                                                                     \
		args->connect_server.port = port_;                                                                             \
		memmove(args->connect_server.data, data_, sizeof(args->connect_server.data));                                  \
		GOTO_(CONNECT_SERVER);                                                                                         \
	}

#define GOTO_NET_CONNECT(id_, hostname_, port_, data_)                                                                 \
	{                                                                                                                  \
		args->net_connect.id = id_;                                                                                    \
		args->net_connect.hostname = hostname_;                                                                        \
		args->net_connect.port = port_;                                                                                \
		memmove(args->net_connect.data, data_, sizeof(args->net_connect.data));                                        \
		GOTO_(NET_CONNECT);                                                                                            \
	}

#define GOTO_NET_CONNECT_WAIT_LOOP(data_, id_, val_, retries_, flags_)                                                 \
	{                                                                                                                  \
		memmove(args->net_connect_wait_loop.data, data_, sizeof(args->net_connect_wait_loop.data));                    \
		args->net_connect_wait_loop.id = id_;                                                                          \
		args->net_connect_wait_loop.val = val_;                                                                        \
		args->net_connect_wait_loop.retries = retries_;                                                                \
		args->net_connect_wait_loop.flags = flags_;                                                                    \
		args->net_connect_wait_loop.counter = 0;                                                                       \
		GOTO_(NET_CONNECT_WAIT_LOOP);                                                                                  \
	}

#define GOTO_NET_CONNECT_WAIT_THEN(data_, id_, result_)                                                                \
	{                                                                                                                  \
		memmove(args->net_connect_wait_then.data, data_, sizeof(args->net_connect_wait_then.data));                    \
		args->net_connect_wait_then.id = id_;                                                                          \
		args->net_connect_wait_then.result = result_;                                                                  \
		GOTO_(NET_CONNECT_WAIT_THEN);                                                                                  \
	}

#define GOTO_NET_CONNECT_THEN(result_)                                                                                 \
	{                                                                                                                  \
		args->net_connect_then.result = result_;                                                                       \
		GOTO_(NET_CONNECT_THEN);                                                                                       \
	}

#define GOTO_CONNECT_WAIT_LOOP(timeout_)                                                                               \
	{                                                                                                                  \
		args->connect_wait_loop.timeout = timeout_;                                                                    \
		GOTO_(CONNECT_WAIT_LOOP);                                                                                      \
	}

#define GOTO_CONNECT_WAIT_THEN(result_)                                                                                \
	{                                                                                                                  \
		args->connect_wait_then.result = result_;                                                                      \
		GOTO_(CONNECT_WAIT_THEN);                                                                                      \
	}

#define GOTO_CONNECT_RESULT(result_)                                                                                   \
	{                                                                                                                  \
		args->connect_result.result = result_;                                                                         \
		GOTO_(CONNECT_RESULT);                                                                                         \
	}

void CONNECT_PREPARE(sm_args_t* args) {
	char* v1;           // ebx
	unsigned short v3;  // ax
	int v4;             // [esp+Ch] [ebp-A8h]
	int v5;             // [esp+10h] [ebp-A4h]
	int v6;             // [esp+14h] [ebp-A0h]
	uint8_t Data[1024]; // [esp+18h] [ebp-9Ch]

	nox_xxx_gameGetScreenBoundaries_43BEB0_get_video_mode(&v5, &v4, &v6);
	v1 = nox_xxx_getHostInfoPtr_431770();
	nox_wcscpy((wchar_t*)v1, (const wchar_t*)getMemAt(0x85B3FC, 12204));
	v1[66] = getMemByte(0x85B3FC, 12254);
	*(uint16_t*)(v1 + 71) = *getMemU16Ptr(0x85B3FC, 12184);
	v1[73] = getMemByte(0x85B3FC, 12186);
	*((uint16_t*)v1 + 34) = *getMemU16Ptr(0x85B3FC, 12187);
	v1[70] = getMemByte(0x85B3FC, 12189);
	*((uint16_t*)v1 + 37) = *getMemU16Ptr(0x85B3FC, 12190);
	v1[76] = getMemByte(0x85B3FC, 12192);
	*(uint16_t*)(v1 + 77) = *getMemU16Ptr(0x85B3FC, 12193);
	v1[79] = getMemByte(0x85B3FC, 12195);
	*((uint16_t*)v1 + 40) = *getMemU16Ptr(0x85B3FC, 12196);
	v1[82] = getMemByte(0x85B3FC, 12198);
	v1[83] = getMemByte(0x85B3FC, 12199);
	v1[84] = getMemByte(0x85B3FC, 12200);
	v1[85] = getMemByte(0x85B3FC, 12201);
	v1[86] = getMemByte(0x85B3FC, 12202);
	v1[87] = getMemByte(0x85B3FC, 12203);
	v1[67] = getMemByte(0x85B3FC, 12255);
	sub_48D740();
	*(uint32_t*)&Data[97] = v5;
	*(uint32_t*)&Data[101] = v4;
	nox_xxx_regGetSerial_420120(&Data[105]);
	if (!nox_xxx_check_flag_aaa_43AF70()) {
		nox_common_getInstallPath_40E0D0((int)&Data[105], "SOFTWARE\\Westwood\\Nox", 0);
	}
	Data[152] = !nox_xxx_checkHasSoloMaps_40ABD0();
	if (getMemByte(0x85B3FC, 10980) & 4) {
		Data[152] |= 0x80u;
	}
	strcpy((char*)&Data[142], (const char*)getMemAt(0x85B3FC, 10395));
	strcpy((char*)&Data[128], sub_41FA40());
	*(uint32_t*)&Data[138] = dword_5d4594_2660032;
	memcpy(Data, v1, 0x61u);

	if (nox_common_gameFlags_check_40A5C0(1)) {
		nox_xxx_replay_4D3860(Data);
		*getMemU32Ptr(0x85319C, 0) = nox_xxx_playerNew_4DD320(31, Data);
		nox_client_setVersion_409AE0(NOX_CLIENT_VERS_CODE);
		nox_netlist_receiveCli_494E90(31);
		nox_xxx_gameSetPlayState_4356B0(2);
		GOTO_CONNECT_RESULT(0);
	} else {
		v3 = nox_client_getServerPort_43B320();
		GOTO_CONNECT_SERVER(nox_client_getServerConnectAddr(), v3, Data);
	}
}

void CONNECT_SERVER(sm_args_t* args) {
	int v4; // eax

	const char* cp = args->connect_server.hostname;
	int hostshort = args->connect_server.port;

	nox_net_struct_arg_t narg;
	memset(&narg, 0, sizeof(nox_net_struct_arg_t));
	dword_5d4594_815704 = 0;
	dword_5d4594_815708 = 0;
	narg.data_size = 2048;
	narg.port = hostshort;
	nox_xxx_allocNetGQueue_5520B0(200, 1024);
	narg.func_yyy = nox_xxx_netHandleCliPacket_43C860;
	v4 = nox_xxx_netPreStructToFull_5546F0(&narg);
	*(uint32_t*)getMemAt(0x5D4594, 815700) = v4;

	GOTO_NET_CONNECT(v4, cp, hostshort, args->connect_server.data);
}

void NET_CONNECT(sm_args_t* args) {
	int v7;                          // eax
	unsigned int v8;                 // ebx
	struct hostent* v9;              // eax
	int v10;                         // esi
	char v11;                        // al
	char v12;                        // [esp+12h] [ebp-1B2h]
	struct nox_net_sockaddr_in name; // [esp+14h] [ebp-1B0h]
	int v15;                         // [esp+28h] [ebp-19Ch]

	int a1 = args->net_connect.id;
	const char* cp = args->net_connect.hostname;
	int hostshort = args->net_connect.port;

	if ((unsigned int)a1 >= NOX_NET_STRUCT_MAX) {
		GOTO_NET_CONNECT_THEN(-3);
	}
	nox_net_struct_t* ns = nox_net_struct_arr[a1];
	if (!ns) {
		GOTO_NET_CONNECT_THEN(-3);
	}
	if (!cp) {
		GOTO_NET_CONNECT_THEN(-4);
	}
	if (hostshort < 1024 || hostshort > 0x10000) {
		GOTO_NET_CONNECT_THEN(-15);
	}
	if (nox_net_init() == -1) {
		GOTO_NET_CONNECT_THEN(-21);
	}
	v7 = nox_net_socket_udp();
	ns->sock = v7;
	if (v7 == -1) {
		nox_net_stop();
		GOTO_NET_CONNECT_THEN(-22);
	}
	if ((unsigned char)*cp < '0' || (unsigned char)*cp > '9') {
		v9 = gethostbyname(cp);
		if (!v9) {
			nox_net_stop();
			GOTO_NET_CONNECT_THEN(-4);
		}
		v8 = **(uint32_t**)v9->h_addr_list;
	} else {
		v8 = inet_addr(cp);
	}
	v15 = 0;
	ns->addr.sin_family = NOX_AF_INET;
	ns->addr.sin_port = htons(hostshort);
	ns->addr.sin_addr = v8;
	memset(ns->addr.sin_zero, 0, 8);

	v10 = nox_client_getClientPort_40A420();
	name.sin_family = NOX_AF_INET;
	name.sin_port = htons(v10);
	name.sin_addr = 0;
	memset(name.sin_zero, 0, 8);
	while (nox_net_bind(ns->sock, &name) == -1) {
		if (nox_net_error(ns->sock) != NOX_NET_EADDRINUSE) {
			nox_net_stop();
			GOTO_NET_CONNECT_THEN(-1);
		}
		name.sin_port = htons(++v10);
	}
	dword_5d4594_3844304 = 0;
	v12 = 0;
	v11 = nox_xxx_netSendSock_552640(a1, &v12, 1, NOX_NET_SEND_NO_LOCK | NOX_NET_SEND_FLAG2);
	GOTO_NET_CONNECT_WAIT_LOOP(args->net_connect.data, a1, v11, 60, 6);
}

void NET_CONNECT_WAIT_LOOP(sm_args_t* args) {
	unsigned int a1 = args->net_connect_wait_loop.id;
	char a2 = args->net_connect_wait_loop.val;
	int a3 = args->net_connect_wait_loop.retries;
	char a4 = args->net_connect_wait_loop.flags;
	int v6 = args->net_connect_wait_loop.counter;

	if (a1 >= 0x80) {
		GOTO_NET_CONNECT_WAIT_THEN(args->net_connect_wait_loop.data, a1, -3);
	}
	nox_net_struct_t* ns = nox_net_struct_arr[a1];
	if (!ns) {
		GOTO_NET_CONNECT_WAIT_THEN(args->net_connect_wait_loop.data, a1, -3);
	}
	v6 = 0;
	if (20 * a3 < ++v6) {
		GOTO_NET_CONNECT_WAIT_THEN(args->net_connect_wait_loop.data, a1, -23);
	}
	nox_xxx_servNetInitialPackets_552A80(a1, a4 | 1);
	nox_xxx_netMaybeSendAll_552460();
	if (ns->field_28_1 >= a2) {
		GOTO_NET_CONNECT_WAIT_THEN(args->net_connect_wait_loop.data, a1, 0);
	}

	args->net_connect_wait_loop.counter = v6;
}

void NET_CONNECT_WAIT_THEN(sm_args_t* args) {
	unsigned int a1 = args->net_connect_wait_then.id;
	void* a4 = args->net_connect_wait_then.data;
	unsigned int a5 = sizeof(args->net_connect_wait_then.data);

	if (args->net_connect_wait_then.result) {
		GOTO_NET_CONNECT_THEN(-23);
	}

	nox_net_struct_t* ns = nox_net_struct_arr[a1];
	if (dword_5d4594_3844304 && ns->id >= 0) {
		memset(getMemAt(0x5D4594, 2512892), 0, 0x400u);
		*getMemU8Ptr(0x5D4594, 2512892) = 31;
		*getMemU8Ptr(0x5D4594, 2512893) = ns->data_2_base[1];
		*getMemU8Ptr(0x5D4594, 2512894) = 32;
		if (a4) {
			memcpy(getMemAt(0x5D4594, 2512895), (const void*)a4, a5);
		}
		nox_xxx_netSendSock_552640(a1, getMemAt(0x5D4594, 2512892), a5 + 3, NOX_NET_SEND_NO_LOCK | NOX_NET_SEND_FLAG2);
	}
	GOTO_NET_CONNECT_THEN(ns->id);
}

void NET_CONNECT_THEN(sm_args_t* args) {
	int v5 = args->net_connect_then.result;
	if (v5 < 0) {
		GOTO_CONNECT_RESULT(v5);
	}

	if (!nox_common_gameFlags_check_40A5C0(1)) {
		dword_5d4594_2649712 |= 0x80000000;
	}
	nox_netlist_resetByInd_40ED10(31, 0);
	nox_xxx_set3512_40A340(0);
	nox_xxx_setMapCRC_40A360(0);
	GOTO_CONNECT_WAIT_LOOP(nox_platform_get_ticks() + 10000);
}

void CONNECT_WAIT_LOOP(sm_args_t* args) {
	if (nox_platform_get_ticks() >= args->connect_wait_loop.timeout) {
		GOTO_CONNECT_WAIT_THEN(0);
	}

	nox_xxx_servNetInitialPackets_552A80(*(unsigned int*)getMemAt(0x5D4594, 815700), 1);
	nox_xxx_netSendBySock_40EE10(*(unsigned int*)getMemAt(0x5D4594, 815700), 31, 0);
	nox_netlist_resetByInd_40ED10(31, 0);
	nox_xxx_netMaybeSendAll_552460();
	if (nox_xxx_getMapCRC_40A370()) {
		GOTO_CONNECT_WAIT_THEN(1);
	}
}

void CONNECT_WAIT_THEN(sm_args_t* args) {
	if (!args->connect_wait_then.result) {
		GOTO_CONNECT_RESULT(-19);
	}
	if (nox_client_getVersionCode_409AD0() != NOX_CLIENT_VERS_CODE) {
		GOTO_CONNECT_RESULT(-20);
	}
	nox_xxx_gameSetPlayState_4356B0(2);
	if (!nox_common_gameFlags_check_40A5C0(1)) {
		sub_417C60();
	}
	GOTO_CONNECT_RESULT(0);
}

void CONNECT_RESULT(sm_args_t* args) {
	int result = args->connect_result.result;
	if (result) {
		nox_common_gameFlags_unset_40A540(0x100000);
		g_v21 = 0;
		if (nox_common_gameFlags_check_40A5C0(1)) {
			nox_xxx_servEndSession_4D3200();
		}
		if (nox_common_gameFlags_check_40A5C0(2)) {
			nox_xxx_cliSetupSession_437190();
		}
		nox_xxx_clear18hDD_416190();
		if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_GAMELOOP_MEMDUMP)) {
			nox_xxx_gameLoopMemDump_413E30();
		}
		nox_client_showConnError_43D0A0(result);
		cmain_loop(0);
		return;
	}
	g_v21 = 1;
	if (nox_xxx_replayStartReadingOrSaving_4D38D0() == 1) {
		cmain_loop(0);
		return;
	}
	if (!nox_common_gameFlags_check_40A5C0(1)) {
		nox_xxx_setGameState_43DDF0(0);
	} else if (!nox_xxx_servInitialMapLoad_4D17F0()) {
		cmain_loop(0);
		return;
	}
	if (!nox_common_gameFlags_check_40A5C0(2)) {
		nox_game_SetCliDrawFunc(0);
	} else {
		if (!nox_common_gameFlags_check_40A5C0(0x100000)) {
			int v25;
			int v26;
			int v28;
			nox_xxx_gameGetScreenBoundaries_43BEB0_get_video_mode(&v26, &v28, &v25);
			if (!v26) {
				nox_xxx_gameResizeScreen_43BEF0_set_video_mode(NOX_DEFAULT_WIDTH, NOX_DEFAULT_HEIGHT, v25);
			}
			if (!nox_xxx_video_43BF10_upd_video_mode(0)) {
				return;
			}
		}
		if (!nox_xxx_initGameSession_435CC0()) {
			cmain_loop(0);
			return;
		}
	}
	if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_GAMELOOP_MEMDUMP)) {
		nox_xxx_gameLoopMemDump_413E30();
	}
	if (nox_common_gameFlags_check_40A5C0(0x2000) && nox_common_gameFlags_check_40A5C0(1) && sub_43AF40()) {
		sub_43AA70();
	}
	sub_43F1A0();
	nox_video_setGammaSetting_434B30(*getMemIntPtr(0x587000, 80852));
	sub_434B60();
	nox_xxx_setGameFlags_40A4D0(0x10000000);
	mainloop_exit_path = 1;
	mainloop_43E290();
}

void cmain_loop(int reentrant) {
	static sm_args_t args_;
	sm_args_t* args = &args_;
	char* v23;
	printf("%s %d\n", __FUNCTION__, reentrant);
	if (!reentrant) {
		goto LOOP;
	}

	if (nox_game_loop_xxx_805872) {
		nox_xxx_cliSetupSession_437190();
		nox_xxx_video_43BF10_upd_video_mode(1);
		nox_client_initScreenParticles_431390();
		goto LOOP;
	}
	sub_43DB60();
	sub_43D990();
	g_v20 = 1;
	sub_43F140(800);
	nox_common_initRandom_415F70();
	nox_frame_xxx_2598000 = nox_common_gameFlags_check_40A5C0(1);
	nox_ensure_thing_bin();
	*getMemU32Ptr(0x85B3FC, 960) = 0;
	*getMemU32Ptr(0x85B3FC, 4) = 0;
	if (g_v21) {
		GOTO_CONNECT_RESULT(0);
	}
	if (nox_common_gameFlags_check_40A5C0(1)) {
		if (!nox_xxx_servNewSession_4D1660()) {
			return;
		}
	}
	if (!nox_xxx_clientResetSpriteAndGui_4357D0(g_argc2, g_argv2)) {
		return;
	}
	if (nox_common_gameFlags_check_40A5C0(1) && nox_common_gameFlags_check_40A5C0(0x400000) &&
		nox_common_getEngineFlag(NOX_ENGINE_FLAG_1)) {
		v23 = nox_fs_root();
		sub_4D39F0(v23);
		if (!nox_xxx_mapGenStart_4D4320()) {
			nox_xxx_mapSwitchLevel_4D12E0(0);
			return;
		}
		sub_4D3C30();
		nox_common_gameFlags_unset_40A540(0x400000);
	}
	GOTO_CONNECT_PREPARE();
LOOP:
	sub_43F140(300);
	if (!sub_43C060()) {
		return;
	}
	if (!nox_xxx_cliWaitForJoinData_43BFE0()) {
		return;
	}
	if (g_v20) {
		sub_43DBA0();
		g_v20 = 0;
	}
	sub_43F1A0();
	mainloop_exit_path = 0;
	mainloop_43E290();
}
