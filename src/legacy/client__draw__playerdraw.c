#include "client__draw__playerdraw.h"
#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME2_3.h"
#include "GAME3.h"
#include "GAME3_1.h"
#include "client__draw__parse__parse.h"
#include "client__drawable__drawable.h"
#include "client__gui__window.h"
#include "client__video__draw_common.h"
#include "common__system__team.h"
#include "operators.h"

extern int nox_win_width;
extern int nox_win_height;

extern uint32_t dword_8531A0_2576;
extern uint32_t nox_player_netCode_85319C;

extern uint32_t nox_color_white_2523948;
extern uint32_t nox_color_blue_2650684;

//----- (004B9790) --------------------------------------------------------
int nox_thing_player_waypoint_draw(int a1, nox_drawable* dr) {
	int v2; // esi
	int v3; // ebp
	int v4; // ebx
	int v5; // edi
	int v7; // [esp+14h] [ebp+4h]

	int a2 = dr;

	v2 = *getMemU32Ptr(0x85B3FC, 940);
	nox_xxx_spriteDrawCircleMB_4C32A0(*(uint32_t*)(a2 + 12) - *(uint32_t*)(a1 + 16),
									  *(uint32_t*)(a2 + 16) - *(uint32_t*)(a1 + 20), 10, *getMemIntPtr(0x85B3FC, 940));
	v3 = *(uint32_t*)(a2 + 16) - *(uint32_t*)(a1 + 20);
	v4 = *(uint32_t*)(a2 + 12) - *(uint32_t*)(a1 + 16);
	v5 = (unsigned char)(2 * (unsigned char)gameFrame());
	nox_client_drawEnableAlpha_434560(1);
	nox_client_drawSetColor_434460(v2);
	v7 = 5;
	do {
		nox_client_drawAddPoint_49F500(v4 + 10 * *getMemIntPtr(0x587000, 192088 + 8 * v5) / 16,
									   v3 + 10 * *getMemIntPtr(0x587000, 192092 + 8 * v5) / 16);
		nox_client_drawAddPoint_49F500(v4 + 10 * *getMemIntPtr(0x587000, 192088 + 8 * ((v5 + 102) % 256)) / 16,
									   v3 + 10 * *getMemIntPtr(0x587000, 192092 + 8 * ((v5 + 102) % 256)) / 16);
		nox_client_drawLineFromPoints_49E4B0();
		v5 = (v5 + 102) % 256;
		--v7;
	} while (v7);
	nox_client_drawEnableAlpha_434560(0);
	return 1;
}
