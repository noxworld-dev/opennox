#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif

#include "common/system/team.h"

#include "proto.h"

void cmain_loop(int);
// defined in GAME1.c
extern _DWORD nox_game_loop_xxx_805872;
extern _DWORD dword_5d4594_2660032;
extern _DWORD dword_5d4594_811372;
extern _DWORD dword_5d4594_815704;
extern _DWORD dword_5d4594_815708;
extern _DWORD dword_5d4594_3844304;
extern _DWORD dword_5d4594_2649712;
extern _DWORD dword_5d4594_815700;
extern void (*mainloop_enter)(void*);
extern void* mainloop_enter_args;
extern BOOL mainloop_exit_path;
extern int g_v20, g_v21;
extern int g_argc2;
extern char** g_argv2;

typedef union {
	struct {
		BYTE data[153];
		const char* hostname;
		WORD port;
	} connect_server;

	struct {
		BYTE data[153];
		unsigned int id;
		const char* hostname;
		WORD port;
	} net_connect;

	struct {
		BYTE data[153];
		unsigned int id;
		char val;
		unsigned int retries;
		unsigned int flags;
		unsigned int counter;
	} net_connect_wait_loop;

	struct {
		BYTE data[153];
		unsigned int id;
		int result;
	} net_connect_wait_then;

	struct {
		int result;
	} net_connect_then;

	struct {
		ULONGLONG timeout;
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

#define GOTO_(state)                                                                                              \
	{                                                                                                               \
		mainloop_enter = state;                                                                                        \
		mainloop_enter_args = args;                                                                                    \
		printf("goto %s\n", #state);                                                                                   \
		return;                                                                                                        \
	}

#define GOTO_CONNECT_PREPARE()                                                                                         \
	{                                                                                                               \
		GOTO_(CONNECT_PREPARE);                                                                                     \
	}

#define GOTO_CONNECT_SERVER(hostname_, port_, data_)                                                                   \
	{                                                                                                               \
		args->connect_server.hostname = hostname_;                                                                     \
		args->connect_server.port = port_;                                                                             \
		memmove(args->connect_server.data, data_, sizeof(args->connect_server.data));                                  \
		GOTO_(CONNECT_SERVER);                                                                                      \
	}

#define GOTO_NET_CONNECT(id_, hostname_, port_, data_)                                                                 \
	{                                                                                                               \
		args->net_connect.id = id_;                                                                                    \
		args->net_connect.hostname = hostname_;                                                                        \
		args->net_connect.port = port_;                                                                                \
		memmove(args->net_connect.data, data_, sizeof(args->net_connect.data));                                        \
		GOTO_(NET_CONNECT);                                                                                         \
	}

#define GOTO_NET_CONNECT_WAIT_LOOP(data_, id_, val_, retries_, flags_)                                                 \
	{                                                                                                               \
		memmove(args->net_connect_wait_loop.data, data_, sizeof(args->net_connect_wait_loop.data));                    \
		args->net_connect_wait_loop.id = id_;                                                                          \
		args->net_connect_wait_loop.val = val_;                                                                        \
		args->net_connect_wait_loop.retries = retries_;                                                                \
		args->net_connect_wait_loop.flags = flags_;                                                                    \
		args->net_connect_wait_loop.counter = 0;                                                                       \
		GOTO_(NET_CONNECT_WAIT_LOOP);                                                                               \
	}

#define GOTO_NET_CONNECT_WAIT_THEN(data_, id_, result_)                                                                \
	{                                                                                                               \
		memmove(args->net_connect_wait_then.data, data_, sizeof(args->net_connect_wait_then.data));                    \
		args->net_connect_wait_then.id = id_;                                                                          \
		args->net_connect_wait_then.result = result_;                                                                  \
		GOTO_(NET_CONNECT_WAIT_THEN);                                                                               \
	}

#define GOTO_NET_CONNECT_THEN(result_)                                                                                 \
	{                                                                                                               \
		args->net_connect_then.result = result_;                                                                       \
		GOTO_(NET_CONNECT_THEN);                                                                                    \
	}

#define GOTO_CONNECT_WAIT_LOOP(timeout_)                                                                               \
	{                                                                                                               \
		args->connect_wait_loop.timeout = timeout_;                                                                    \
		GOTO_(CONNECT_WAIT_LOOP);                                                                                   \
	}

#define GOTO_CONNECT_WAIT_THEN(result_)                                                                                \
	{                                                                                                               \
		args->connect_wait_then.result = result_;                                                                      \
		GOTO_(CONNECT_WAIT_THEN);                                                                                   \
	}

#define GOTO_CONNECT_RESULT(result_)                                                                                   \
	{                                                                                                               \
		args->connect_result.result = result_;                                                                         \
		GOTO_(CONNECT_RESULT);                                                                                      \
	}

void CONNECT_PREPARE(sm_args_t* args) {
	char* v1;            // ebx
	unsigned __int16 v3; // ax
	int v4;              // [esp+Ch] [ebp-A8h]
	int v5;              // [esp+10h] [ebp-A4h]
	int v6;              // [esp+14h] [ebp-A0h]
	BYTE Data[1024];     // [esp+18h] [ebp-9Ch]

	nox_xxx_gameGetScreenBoundaries_43BEB0_get_video_mode(&v5, &v4, &v6);
	v1 = nox_xxx_getHostInfoPtr_431770();
	nox_wcscpy((wchar_t*)v1, (const wchar_t*)getMemAt(0x5D4594, 2661908));
	v1[66] = getMemByte(0x5D4594, 2661958);
	*(_WORD*)(v1 + 71) = *getMemU16Ptr(0x5D4594, 2661888);
	v1[73] = getMemByte(0x5D4594, 2661890);
	*((_WORD*)v1 + 34) = *getMemU16Ptr(0x5D4594, 2661891);
	v1[70] = getMemByte(0x5D4594, 2661893);
	*((_WORD*)v1 + 37) = *getMemU16Ptr(0x5D4594, 2661894);
	v1[76] = getMemByte(0x5D4594, 2661896);
	*(_WORD*)(v1 + 77) = *getMemU16Ptr(0x5D4594, 2661897);
	v1[79] = getMemByte(0x5D4594, 2661899);
	*((_WORD*)v1 + 40) = *getMemU16Ptr(0x5D4594, 2661900);
	v1[82] = getMemByte(0x5D4594, 2661902);
	v1[83] = getMemByte(0x5D4594, 2661903);
	v1[84] = getMemByte(0x5D4594, 2661904);
	v1[85] = getMemByte(0x5D4594, 2661905);
	v1[86] = getMemByte(0x5D4594, 2661906);
	v1[87] = getMemByte(0x5D4594, 2661907);
	v1[67] = getMemByte(0x5D4594, 2661959);
	sub_48D740();
	*(_DWORD*)&Data[97] = v5;
	*(_DWORD*)&Data[101] = v4;
	nox_xxx_regGetSerial_420120(&Data[105]);
	if (!sub_43AF70()) {
		sub_40E0D0((int) &Data[105], (LPCSTR) getMemAt(0x587000, 86344), 0);
	}
	Data[152] = !nox_xxx_checkConjSoloMap_40ABD0();
	if (getMemByte(0x5D4594, 2660684) & 4) {
		Data[152] |= 0x80u;
	}
	strcpy((char*)&Data[142], (const char*)getMemAt(0x5D4594, 2660012 + 87));
	strcpy((char*)&Data[128], sub_41FA40());
	*(_DWORD*)&Data[138] = dword_5d4594_2660032;
	memcpy(Data, v1, 0x61u);

	if (nox_common_gameFlags_check_40A5C0(1)) {
		nox_xxx_replay_4D3860(Data);
		*getMemU32Ptr(0x5D4594, 2616328) = nox_xxx_playerNew_4DD320(31, Data);
		sub_409AE0(66458);
		nox_xxx_netlist_494E90(31);
		dword_5d4594_811372 = 2;
		GOTO_CONNECT_RESULT(0);
	} else {
		v3 = sub_43B320();
		GOTO_CONNECT_SERVER((char*)getMemAt(0x587000, 85680), v3, Data);
	}
}

void CONNECT_SERVER(sm_args_t* args) {
	int v4;      // eax
	char v7[40]; // [esp+8h] [ebp-28h]

	const char* cp = args->connect_server.hostname;
	int hostshort = args->connect_server.port;

	memset(v7, 0, sizeof(v7));
	dword_5d4594_815704 = 0;
	dword_5d4594_815708 = 0;
	*(_DWORD*)&v7[20] = 2048;
	*(_DWORD*)&v7[8] = hostshort;
	nox_xxx_allocNetGQueue_5520B0(200, 1024);
	*(_DWORD*)&v7[36] = nox_xxx_netHandleCliPacket_43C860;
	v4 = nox_xxx_netPreStructToFull_5546F0((size_t*)v7);
	dword_5d4594_815700 = v4;

	GOTO_NET_CONNECT(v4, cp, hostshort, args->connect_server.data);
}

void NET_CONNECT(sm_args_t* args) {
	int* v5;                // ebp
	int v7;                 // eax
	unsigned int v8;        // ebx
	struct hostent* v9;     // eax
	int v10;                // esi
	char v11;               // al
	char v12;               // [esp+12h] [ebp-1B2h]
	struct sockaddr_in name;   // [esp+14h] [ebp-1B0h]
	WORD v14[2];            // [esp+24h] [ebp-1A0h]
	int v15;                // [esp+28h] [ebp-19Ch]
	struct WSAData WSAData; // [esp+34h] [ebp-190h]

	int a1 = args->net_connect.id;
	const char* cp = args->net_connect.hostname;
	int hostshort = args->net_connect.port;

	v5 = *(int**)getMemAt(0x5D4594, 4 * a1 + 3843788);
	if ((unsigned int)a1 >= 0x80) {
		GOTO_NET_CONNECT_THEN(-3);
	}
	if (!v5) {
		GOTO_NET_CONNECT_THEN(-3);
	}
	if (!cp) {
		GOTO_NET_CONNECT_THEN(-4);
	}
	if (hostshort < 1024 || hostshort > 0x10000) {
		GOTO_NET_CONNECT_THEN(-15);
	}
	if (WSAStartup(0x101u, &WSAData) == -1) {
		GOTO_NET_CONNECT_THEN(-21);
	}
	v7 = socket(AF_INET, SOCK_DGRAM, 0);
	*v5 = v7;
	if (v7 == -1) {
		WSACleanup();
		GOTO_NET_CONNECT_THEN(-22);
	}
	if ((unsigned __int8)*cp < 0x30u || (unsigned __int8)*cp > 0x39u) {
		v9 = gethostbyname(cp);
		if (!v9) {
			WSACleanup();
			GOTO_NET_CONNECT_THEN(-4);
		}
		v8 = **(_DWORD**)v9->h_addr_list;
	} else {
		v8 = inet_addr(cp);
	}
	v15 = 0;
	v14[0] = 2;
	v14[1] = htons(hostshort);
	v5[1] = *(_DWORD*)v14;
	v5[2] = v8;
	v5[3] = 0;
	v5[4] = 0;
	v10 = sub_40A420();
	name.sin_family = AF_INET;
	name.sin_port = htons(v10);
	name.sin_addr.s_addr = 0;
	memset(name.sin_zero, 0, 8);
	while (bind(*v5, &name, 16) == -1) {
		if (WSAGetLastError() != 10048) {
			WSACleanup();
			GOTO_NET_CONNECT_THEN(-1);
		}
		name.sin_port = htons(++v10);
	}
	dword_5d4594_3844304 = 0;
	v12 = 0;
	v11 = nox_xxx_netSendSock_552640(a1, &v12, 1, 3);
	GOTO_NET_CONNECT_WAIT_LOOP(args->net_connect.data, a1, v11, 60, 6);
}

void NET_CONNECT_WAIT_LOOP(sm_args_t* args) {
	int v4; // edi

	unsigned int a1 = args->net_connect_wait_loop.id;
	char a2 = args->net_connect_wait_loop.val;
	int a3 = args->net_connect_wait_loop.retries;
	char a4 = args->net_connect_wait_loop.flags;
	int v6 = args->net_connect_wait_loop.counter;

	v4 = *getMemU32Ptr(0x5D4594, 4 * a1 + 3843788);
	if (a1 >= 0x80) {
		GOTO_NET_CONNECT_WAIT_THEN(args->net_connect_wait_loop.data, a1, -3);
	}
	if (!v4) {
		GOTO_NET_CONNECT_WAIT_THEN(args->net_connect_wait_loop.data, a1, -3);
	}
	v6 = 0;
	if (20 * a3 < ++v6) {
		GOTO_NET_CONNECT_WAIT_THEN(args->net_connect_wait_loop.data, a1, -23);
	}
	nox_xxx_servNetInitialPackets_552A80(a1, a4 | 1);
	sub_552460();
	if (*(char*)(v4 + 113) >= a2) {
		GOTO_NET_CONNECT_WAIT_THEN(args->net_connect_wait_loop.data, a1, 0);
	}

	args->net_connect_wait_loop.counter = v6;
}

void NET_CONNECT_WAIT_THEN(sm_args_t* args) {
	int* v5;

	unsigned int a1 = args->net_connect_wait_then.id;
	void* a4 = args->net_connect_wait_then.data;
	unsigned int a5 = sizeof(args->net_connect_wait_then.data);

	if (args->net_connect_wait_then.result) {
		GOTO_NET_CONNECT_THEN(-23);
	}

	v5 = *(int**)getMemAt(0x5D4594, 4 * a1 + 3843788);
	if (dword_5d4594_3844304 && (int)v5[5] >= 0) {
		memset(getMemAt(0x5D4594, 2512892), 0, 0x400u);
		*getMemU8Ptr(0x5D4594, 2512892) = 31;
		*getMemU8Ptr(0x5D4594, 2512892 + 1) = *(_BYTE*)(v5[12] + 1);
		*getMemU8Ptr(0x5D4594, 2512892 + 2) = 32;
		if (a4) {
			memcpy(getMemAt(0x5D4594, 2512892 + 3), (const void *) a4, a5);
		}
		nox_xxx_netSendSock_552640(a1, getMemAt(0x5D4594, 2512892), a5 + 3, 3);
	}
	GOTO_NET_CONNECT_THEN(v5[5]);
}

void NET_CONNECT_THEN(sm_args_t* args) {
	int v5 = args->net_connect_then.result;
	if (v5 < 0) {
		GOTO_CONNECT_RESULT(v5);
	}

	if (!nox_common_gameFlags_check_40A5C0(1)) {
		dword_5d4594_2649712 |= 0x80000000;
	}
	sub_40ED10(31, 0);
	sub_40A340(0);
	nox_xxx_mapCrcMb_40A360(0);
	GOTO_CONNECT_WAIT_LOOP(nox_call_get_ticks() + 10000);
}

void CONNECT_WAIT_LOOP(sm_args_t* args) {
	if (nox_call_get_ticks() >= args->connect_wait_loop.timeout) {
		GOTO_CONNECT_WAIT_THEN(0);
	}

	nox_xxx_servNetInitialPackets_552A80(*(unsigned int*)&dword_5d4594_815700, 1);
	nox_xxx_netSendBySock_40EE10(*(unsigned int*)&dword_5d4594_815700, 31, 0);
	sub_40ED10(31, 0);
	sub_552460();
	if (nox_xxx_crc_40A370()) {
		GOTO_CONNECT_WAIT_THEN(1);
	}
}

void CONNECT_WAIT_THEN(sm_args_t* args) {
	if (!args->connect_wait_then.result) {
		GOTO_CONNECT_RESULT(-19);
	}
	if (sub_409AD0() != 66458) {
		GOTO_CONNECT_RESULT(-20);
	}
	dword_5d4594_811372 = 2;
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
		if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_13)) {
			sub_413E30();
		}
		sub_43D0A0(result);
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
	if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_13)) {
		sub_413E30();
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
	*getMemU32Ptr(0x5D4594, 2598000) = nox_common_gameFlags_check_40A5C0(1);
	nox_ensure_thing_bin();
	*getMemU32Ptr(0x5D4594, 2650664) = 0;
	*getMemU32Ptr(0x5D4594, 2649708) = 0;
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
		v23 = nox_common_get_data_path_409E10();
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
