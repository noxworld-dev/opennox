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

extern uint32_t dword_5d4594_1313792;
extern uint32_t dword_5d4594_1313796;
extern uint32_t dword_5d4594_1313800;
extern uint32_t nox_player_netCode_85319C;
extern unsigned int nox_frame_xxx_2598000;

extern uint32_t nox_color_white_2523948;
extern uint32_t nox_color_red_2589776;
extern uint32_t nox_color_blue_2650684;
extern uint32_t nox_color_green_2614268;
extern uint32_t nox_color_cyan_2649820;
extern uint32_t nox_color_yellow_2589772;
extern uint32_t nox_color_violet_2598268;
extern uint32_t nox_color_black_2650656;
extern uint32_t nox_color_orange_2614256;

//----- (004B8270) --------------------------------------------------------
int nox_thing_player_draw(uint32_t* a1, nox_drawable* dr) {
	char* v3;         // esi
	uint32_t* v4;     // eax
	char* v5;         // eax
	uint32_t* v6;     // edi
	uint32_t* v7;     // eax
	uint32_t* v8;     // ebp
	unsigned char v9; // al
	int* v10;         // ebp
	uint32_t* v11;    // eax
	int v13;          // eax
	int v14;          // ecx
	uint32_t* v15;    // edx
	int* v17;         // edi
	int v18;          // eax
	char v20;         // al
	short* v21;       // edi
	int v22;          // esi
	int v23;         // eax
	int v24;          // eax
	int v25;          // eax
	int v26;          // [esp-4h] [ebp-6Ch]
	int v27;          // [esp+10h] [ebp-58h]
	int v28;          // [esp+14h] [ebp-54h]
	char* v29;        // [esp+18h] [ebp-50h]
	int v30;          // [esp+1Ch] [ebp-4Ch]
	int v31;          // [esp+20h] [ebp-48h]
	char* v32;        // [esp+24h] [ebp-44h]
	int v34;          // [esp+2Ch] [ebp-3Ch]
	int v35;          // [esp+30h] [ebp-38h]
	int v36[13];      // [esp+34h] [ebp-34h]

	v26 = dr->field_32;
	v31 = 0;
	v30 = 0;
	v29 = 0;
	v3 = nox_common_playerInfoGetByID_417040(v26);
	v32 = v3;
	if (!v3) {
		return 1;
	}
	if (*getMemU32Ptr(0x8531A0, 2576) && (*(uint8_t*)(*getMemU32Ptr(0x8531A0, 2576) + 3680) & 1)) {
		v30 = 1;
	}
	if (nox_player_netCode_85319C == dr->field_32) {
		v4 = nox_xxx_objGetTeamByNetCode_418C80(nox_player_netCode_85319C);
		if (v4) {
			v5 = nox_xxx_clientGetTeamColor_418AB0(*((unsigned char*)v4 + 4));
			v29 = v5;
		}
	} else {
		if (v3[3680] & 1) {
			return 1;
		}
		v6 = nox_xxx_objGetTeamByNetCode_418C80(nox_player_netCode_85319C);
		if (v6) {
			v7 = nox_xxx_objGetTeamByNetCode_418C80(dr->field_32);
			v8 = v7;
			if (v7) {
				if (nox_xxx_servCompareTeams_419150((int)v6, (int)v7)) {
					v31 = 1;
				}
				v5 = nox_xxx_clientGetTeamColor_418AB0(*((unsigned char*)v8 + 4));
				v29 = v5;
			}
		}
	}
	v9 = nox_xxx_getTeamCounter_417DD0();
	v10 = (int*)a1;
	v35 = v9 != 0;
	if ((v3[4] & 1)) {
		v36[2] = nox_win_width;
		v36[8] = nox_win_width;
		v11 = *(uint32_t**)&dword_5d4594_1313792;
		v36[0] = 0;
		v36[1] = 0;
		v36[3] = nox_win_height;
		v36[9] = nox_win_height;
		v36[4] = 0;
		v36[5] = 0;
		if (dword_5d4594_1313792 || (v13 = nox_xxx_getTTByNameSpriteMB_44CFC0("Flag"),
									 v11 = nox_new_drawable_for_thing(v13), (dword_5d4594_1313792 = v11) != 0)) {
			v15 = v3 + 2324;
			for (v14 = 0; v14 < 27; v14++) {
				if (*v15 == 1) {
					memcpy(v11 + 108, &v3[24 * v14 + 2328], 0x14u);
					v11 = *(uint32_t**)&dword_5d4594_1313792;
					v3 = v32;
					break;
				}
				v15 += 6;
			}
			v11[3] = dr->pos.x - v10[4] + *v10 + 15;
			*(uint32_t*)(dword_5d4594_1313792 + 16) = v10[1] - v10[5] + dr->pos.y - 25;
			(*(void (**)(int*, uint32_t))(dword_5d4594_1313792 + 300))(v36, dword_5d4594_1313792);
		}
	}
	uint32_t colors[6];
	colors[0] = 0;
	colors[1] = 0;
	colors[2] = 0;
	colors[3] = 0;
	colors[4] = 0;
	colors[5] = 0;
	if (nox_client_drawable_testBuff_4356C0(dr, 23)) { // ENCHANT_INVULNERABLE
		if (!((unsigned char)nox_frame_xxx_2598000 & 1)) {
			for (int i = 0; i < 6; i++) {
				colors[i] = nox_color_blue_2650684;
			}
		} else {
			for (int i = 0; i < 6; i++) {
				colors[i] = nox_color_white_2523948;
			}
		}
	} else if (nox_client_drawable_testBuff_4356C0(dr, 25)) { // ENCHANT_FREEZE
		for (int i = 0; i < 6; i++) {
			colors[i] = nox_color_blue_2650684;
		}
	} else {
		colors[0] = *((uint32_t*)v3 + 574);
		colors[1] = *((uint32_t*)v3 + 576);
		colors[2] = *((uint32_t*)v3 + 578);
		colors[3] = *((uint32_t*)v3 + 577);
		colors[4] = *((uint32_t*)v3 + 575);
		colors[5] = *((uint32_t*)v3 + 573);
		if (*((uint32_t*)v3 + 920) & 0x400) {
			for (int i = 0; i < 6; i++) {
				int r = 0;
				int g = 0;
				int b = 0;
				nox_draw_splitColor_435280(colors[i], &r, &g, &b);
				if (g >= 155) {
					g = 255;
				} else {
					g += 100;
				}
				colors[i] = nox_color_rgb_4344A0(r, g, b);
			}
		}
	}
	nox_draw_setMaterial_4341D0(1, colors[0]);
	nox_draw_setMaterial_4341D0(2, colors[1]);
	nox_draw_setMaterial_4341D0(3, colors[2]);
	nox_draw_setMaterial_4341D0(4, colors[3]);
	nox_draw_setMaterial_4341D0(5, colors[4]);
	nox_draw_setMaterial_4341D0(6, colors[5]);
	v18 = sub_4B8FA0(dr, &v28, &v27);
	if (!v18) {
		return 0;
	}
	nox_xxx_drawObject_4C4770_draw(v10, dr, v18);

	// A player in Nox has a 32-bit integer field that contains bits for each
	// type of armor / weapon. sub_4B8D40 is responsible for iterating over
	// each type and drawing it to the screen.
	//
	// To add support for drawing the quiver, we must modify sub_4B8D40 to
	// iterate from 1 instead of 2 (i.e. bit 1 indicates quiver equipped). We
	// must also modify how sub_4B8D40 is called because of Z ordering.
	//
	// The Z ordering is simple to understand. Usually Nox will draw the player
	// body, and then the armor / weapon on top (or vice versa depending on
	// rotation). The quiver is unique because it is on the player's back, e.g.
	// it must be drawn first, then the body, then the rest of the armor.
	v20 = dr->field_74_2;
	if (v20 != 1 && v20 && v20 != 2 && v20 != 3 && v20 != 6 || dr->field_69 == 37) {
		sub_4B8D40(v10, dr, *((uint32_t*)v3 + 1) & 2, (uint32_t*)v3 + 581, v28, v27);
		sub_4B8960(v10, dr, *(uint32_t*)v3, (uint32_t*)v3 + 743, v28, v27);
		sub_4B8D40(v10, dr, *((uint32_t*)v3 + 1) & ~2, (uint32_t*)v3 + 581, v28, v27);
	} else {
		sub_4B8D40(v10, dr, *((uint32_t*)v3 + 1) & ~2, (uint32_t*)v3 + 581, v28, v27);
		sub_4B8960(v10, dr, *(uint32_t*)v3, (uint32_t*)v3 + 743, v28, v27);
		sub_4B8D40(v10, dr, *((uint32_t*)v3 + 1) & 2, (uint32_t*)v3 + 581, v28, v27);
	}

	if (v30 || !nox_client_drawable_testBuff_4356C0(dr, 0) || (dr->field_32 == nox_player_netCode_85319C) ||
		*getMemU32Ptr(0x852978, 8) && (nox_client_drawable_testBuff_4356C0(*getMemIntPtr(0x852978, 8), 21) || v31)) {
		a1 = nox_color_rgb_4344A0(155, 155, 155);
		if (!sub_48D830(dr) && !nox_common_gameFlags_check_40A5C0(2048)) {
			v21 = (short*)(v3 + 4704);
			nox_xxx_drawGetStringSize_43F840(0, (unsigned short*)v3 + 2352, &v34, 0, 0);
			v22 = *v10 + dr->pos.x + v34 / -2 - v10[4];
			int a2 = v10[1] - v10[5] + dr->pos.y - 64;
			nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x852978, 4));
			nox_xxx_drawString_43F6E0(0, v21, v22 + 1, a2 + 1);
			nox_xxx_drawSetTextColor_434390(a1);
			if (v35) {
				if (v29) {
					v23 = nox_xxx_materialGetTeamColor_418D50((int)v29);
					nox_xxx_drawSetTextColor_434390(v23);
				}
			}
			nox_xxx_drawString_43F6E0(0, v21, v22, a2);
			v3 = v32;
		}
		if (nox_client_drawable_testBuff_4356C0(dr, 16)) {
			v36[2] = nox_win_width;
			v36[8] = nox_win_width;
			v36[0] = 0;
			v36[1] = 0;
			v36[3] = nox_win_height;
			v36[9] = nox_win_height;
			v36[4] = 0;
			v36[5] = 0;
			if (!dword_5d4594_1313796) {
				v24 = nox_xxx_getTTByNameSpriteMB_44CFC0("SpinningSkull");
				dword_5d4594_1313796 = nox_new_drawable_for_thing(v24);
				*(uint32_t*)(dword_5d4594_1313796 + 120) |= 0x1000000u;
			}
			*(uint32_t*)(dword_5d4594_1313796 + 12) = *v10 + dr->pos.x - v10[4];
			*(uint32_t*)(dword_5d4594_1313796 + 16) = v10[1] - v10[5] + dr->pos.y - 50;
			(*(void (**)(int*, uint32_t))(dword_5d4594_1313796 + 300))(v36, dword_5d4594_1313796);
		}
		if (nox_client_drawable_testBuff_4356C0(dr, 30)) {
			v36[2] = nox_win_width;
			v36[8] = nox_win_width;
			v36[0] = 0;
			v36[1] = 0;
			v36[3] = nox_win_height;
			v36[9] = nox_win_height;
			v36[4] = 0;
			v36[5] = 0;
			if (!dword_5d4594_1313800) {
				v25 = nox_xxx_getTTByNameSpriteMB_44CFC0("SpinningCrown");
				dword_5d4594_1313800 = nox_new_drawable_for_thing(v25);
				*(uint32_t*)(dword_5d4594_1313800 + 120) |= 0x1000000u;
			}
			*(uint32_t*)(dword_5d4594_1313800 + 12) = *v10 + dr->pos.x - v10[4];
			*(uint32_t*)(dword_5d4594_1313800 + 16) = v10[1] - v10[5] + dr->pos.y - 50;
			(*(void (**)(int*, uint32_t))(dword_5d4594_1313800 + 300))(v36, dword_5d4594_1313800);
		}
		for (int i = 0; i < 6; i++) {
			// TODO: shouldn't it be i+1 ?
			nox_draw_setMaterial_4341D0(i, nox_color_white_2523948);
		}
		if ((dr != *getMemU32Ptr(0x852978, 8)) && nox_xxx_playerGet_470A90()) {
			if (nox_common_gameFlags_check_40A5C0(4096)) {
				nox_xxx_drawOtherPlayerHP_4B8EB0(v10, dr, (unsigned char)v3[2282], (*((uint32_t*)v3 + 920) >> 10) & 1);
			}
		}
	}
	return 1;
}

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
	v5 = (unsigned char)(2 * (unsigned char)nox_frame_xxx_2598000);
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

//----- (0044B700) --------------------------------------------------------
bool nox_things_player_draw_parse(nox_thing* obj, nox_memfile* f, char* attr_value) {
	uint8_t* a3 = attr_value;
	uint32_t* v3;      // eax
	uint32_t* v5;      // ebx
	int v7;            // ecx
	int v10;           // eax
	int v11;           // ebx
	int v13;           // ecx
	uint32_t* v14;     // eax
	int v15;           // ecx
	int v16;           // eax
	int v17;           // esi
	uint32_t* v18;     // eax
	int v19;           // esi
	uint32_t* v20;     // eax
	uint32_t* v21;     // [esp+10h] [ebp-4h]
	unsigned char v22; // [esp+1Ch] [ebp+8h]
	unsigned char v23; // [esp+1Ch] [ebp+8h]

	v3 = calloc(1u, 14524);
	v5 = v3;
	v21 = v3;
	*v3 = 14524;
	v7 = nox_memfile_read_u32(f);
	if (v7 == 0x454E4420) { // 'END '
		return 0;
	}
LABEL_3:
	v22 = nox_memfile_read_u8(f);
	nox_memfile_read(a3, 1u, v22, f);
	*((uint8_t*)a3 + v22) = 0;
	v10 = sub_44BB20((const char*)a3);
	if (v10 < 0) {
		return 0;
	}
	v11 = (int)&v5[66 * v10 + 1];
	if (!nox_xxx_loadVectorAnimated_44B8B0(v11, f)) {
		return 0;
	}
	while (1) {
		v13 = nox_memfile_read_u32(f);
		if (v13 == 0x454E4420) { // 'END '
			break;
		}
		if (v13 == 0x53544154) { // STAT
			v5 = v21;
			goto LABEL_3;
		}
		v23 = nox_memfile_read_u8(f);
		nox_memfile_read(a3, 1u, v23, f);
		*((uint8_t*)a3 + v23) = 0;
		if (!strcmp("NAKED", (const char*)a3)) {
			v14 = calloc(1u, 0x28u);
			v15 = *(short*)(v11 + 40);
			*(uint32_t*)(v11 + 48) = v14;
			v16 = sub_44B940(v14, v15, f);
		} else {
			v17 = nox_xxx_parse_Armor_44BA60((const char*)a3);
			if (v17 < 0) {
				v19 = sub_44BAC0((const char*)a3);
				if (v19 < 0) {
					return 0;
				}
				v20 = calloc(1u, 0x28u);
				*(uint32_t*)(v11 + 4 * v19 + 156) = v20;
				v16 = sub_44B940(v20, *(short*)(v11 + 40), f);
			} else {
				v18 = calloc(1u, 0x28u);
				*(uint32_t*)(v11 + 4 * v17 + 52) = v18;
				v16 = sub_44B940(v18, *(short*)(v11 + 40), f);
			}
		}
		if (!v16) {
			return 0;
		}
	}
	obj->draw_func = &nox_thing_player_draw;
	obj->field_5c = v21;
	return 1;
}
