#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif
#include <math.h>

#ifdef _WIN32
#include <io.h>
#else
#include "windows_compat.h"
#endif

#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME2_2.h"
#include "GAME2_3.h"
#include "GAME3.h"
#include "GAME3_1.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4.h"
#include "GAME4_1.h"
#include "GAME4_2.h"
#include "GAME4_3.h"
#include "GAME5.h"
#include "GAME5_2.h"
#include "client__system__parsecmd.h"
#include "common__log.h"
#include "common__net_list.h"
#include "common__random.h"
#include "common__system__team.h"
#include "server__mapgen__generate__populate.h"
#include "server__network__playback.h"
#include "server__network__sdecode.h"
#include "server__system__server.h"
#include "server__xfer__savegame__savegame.h"

#include "client__gui__chathelp.h"
#include "client__gui__conntype.h"
#include "client__gui__servopts__guiserv.h"
#include "client__gui__window.h"

#include "client__drawable__drawdb.h"
#include "client__drawable__update__cloud.h"
#include "client__drawable__update__dball.h"

#include "MixPatch.h"
#include "client__video__draw_common.h"
#include "common/fs/nox_fs.h"
#include "common__crypt.h"
#include "common__magic__speltree.h"
#include "defs.h"
#include "operators.h"
#include "server__script__builtin.h"

extern uint32_t dword_5d4594_3835368;
extern uint32_t dword_5d4594_3835360;
extern uint32_t dword_5d4594_1549844;
extern uint32_t dword_5d4594_3835364;
extern uint32_t dword_5d4594_1563064;
extern void* dword_5d4594_1548532;
extern uint32_t dword_5d4594_1556128;
extern uint32_t dword_5d4594_1556316;
extern uint32_t dword_5d4594_1548524;
extern uint32_t dword_5d4594_1556136;
extern uint32_t dword_5d4594_3835372;
extern uint32_t dword_5d4594_1556144;
extern uint32_t dword_5d4594_1523040;
extern uint32_t dword_5d4594_1563276;
extern uint32_t dword_5d4594_1548664;
extern uint32_t dword_5d4594_3835392;
extern uint32_t nox_server_sendMotd_108752;
extern uint32_t dword_5d4594_1548736;
extern uint32_t dword_5d4594_1563084;
extern uint32_t dword_5d4594_1563080;
extern uint32_t dword_5d4594_1556856;
extern uint32_t dword_5d4594_1548480;
extern uint32_t dword_5d4594_1563044;
extern uint32_t dword_5d4594_1548732;
extern uint32_t dword_5d4594_1548704;
extern uint32_t dword_5d4594_1523048;
extern uint32_t dword_5d4594_1563096;
extern uint32_t dword_5d4594_1523044;
extern uint32_t dword_5d4594_1523032;
extern uint32_t dword_5d4594_1563088;
extern uint32_t nox_xxx_warriorMaxSpeed_587000_312796;
extern uint32_t nox_server_sanctuaryHelp_54276;
extern uint32_t dword_5d4594_3835312;
extern uint32_t dword_5d4594_1563052;
extern uint32_t nox_xxx_conjurerSpeed_587000_312812;
extern uint32_t nox_xxx_wizardSpeed_587000_312828;
extern uint32_t nox_xxx_wizardStrength_587000_312824;
extern uint32_t nox_xxx_warriorMaxStrength_587000_312792;
extern uint32_t nox_xxx_questFlag_1556148;
extern uint32_t dword_5d4594_3835388;
extern uint32_t nox_xxx_conjurerStrength_587000_312808;
extern uint32_t dword_5d4594_1563092;
extern uint32_t dword_5d4594_3835348;
extern uint32_t nox_client_gui_flag_1556112;
extern uint32_t dword_5d4594_3835352;
extern uint32_t dword_5d4594_1550912;
extern uint32_t dword_5d4594_1523036;
extern uint32_t dword_5d4594_1548700;
extern uint32_t dword_5d4594_3835356;
extern uint32_t nox_xxx_warriorMaxMana_587000_312788;
extern uint32_t nox_server_connectionType_3596;
extern uint32_t nox_xxx_warriorMaxHealth_587000_312784;
extern uint32_t nox_xxx_conjurerMaxHealth_587000_312800;
extern uint32_t nox_xxx_wizardMaxHealth_587000_312816;
extern uint32_t nox_xxx_conjurerMaxMana_587000_312804;
extern uint32_t dword_5d4594_1550916;
extern uint32_t nox_xxx_wizardMaximumMana_587000_312820;
extern uint32_t dword_5d4594_2649712;
extern uint32_t dword_5d4594_3835396;
extern uint32_t dword_5d4594_1523024;
extern uint32_t dword_5d4594_1523028;
extern uint32_t dword_5d4594_1548476;
extern uint32_t dword_5d4594_2650652;
extern int nox_win_width;
extern int nox_win_height;
extern unsigned int nox_gameFPS;
extern unsigned int nox_frame_xxx_2598000;

extern obj_5D4594_2650668_t** ptr_5D4594_2650668;
extern int ptr_5D4594_2650668_cap;

nox_object_t* nox_server_object_updateable_1556852 = 0;
nox_object_t* nox_server_objects_uninited_1556860 = 0;
nox_object_t* nox_server_objects_updatable2_1556848 = 0;
nox_object_t* nox_server_objects_1556844 = 0;

nox_object_t* nox_xxx_host_player_unit_3843628 = 0;

nox_list_item_t nox_common_maplist = {0};

// 4CD756: variable 'v5' is possibly undefined
// 4CD767: variable 'v7' is possibly undefined
// 4CD78B: variable 'v9' is possibly undefined
// 4CD79C: variable 'v11' is possibly undefined

//----- (004CDF80) --------------------------------------------------------
int nox_xxx_updDrawDBall_4CDF80(int a1, int a2) {
	nox_xxx_updDrawAddRndSpark_4CDFA0(a2, (uint32_t*)3);
	return 1;
}

//----- (004CE0A0) --------------------------------------------------------
int sub_4CE0A0(int a1, int a2) {
	nox_xxx_updDrawAddRndSpark_4CDFA0(a2, (uint32_t*)1);
	return 1;
}

//----- (004CE1D0) --------------------------------------------------------
int nox_xxx_updDrawCloud_4CE1D0(int a1, int a2) {
	if ((unsigned char)nox_frame_xxx_2598000 & 1) {
		sub_4CE200(a1, a2, 1, 75);
	}
	return 1;
}

//----- (004CE340) --------------------------------------------------------
int sub_4CE340(int a1, int a2) {
	*(uint16_t*)(a2 + 104) += *(unsigned char*)(a2 + 432);
	return 1;
}

//----- (004CE360) --------------------------------------------------------
int sub_4CE360(int a1, int a2) {
	if ((unsigned char)nox_frame_xxx_2598000 & 1) {
		sub_4CE200(a1, a2, 1, 35);
	}
	return 1;
}

//----- (004CE390) --------------------------------------------------------
int nox_xxx_updDrawColorlight_4CE390(uint32_t* a1, int a2) {
	int result; // eax
	int v3;     // edx
	int v4;     // ecx
	int v5;     // ecx
	int v6;     // edx

	if (*(uint8_t*)(a2 + 432) || *(uint8_t*)(a2 + 433) || *(uint8_t*)(a2 + 434)) {
		v3 = *(uint32_t*)(a2 + 12);
		v4 = a1[4];
		if (v3 >= v4 - 100 && v3 <= a1[8] + v4 + 100) {
			v5 = a1[5];
			v6 = *(uint32_t*)(a2 + 16);
			if (v6 >= v5 - 100 && v6 <= a1[9] + v5 + 100 && !nox_common_gameFlags_check_40A5C0(0x200000)) {
				nox_xxx_colorLightAlterB0ArrayColor_4CE440(a2);
				nox_xxx_colorLightAlterIntensity_4CE610(a2);
				nox_xxx_colorLightAlterRadius_4CE760(a2);
				sub_4CE960(a2);
				sub_4CE8C0(a2);
			}
		}
		result = 1;
	} else {
		sub_49BCD0((uint32_t*)a2);
		result = 1;
	}
	return result;
}

//----- (004CE440) --------------------------------------------------------
void nox_xxx_colorLightAlterB0ArrayColor_4CE440(int a1) {
	int v1;       // esi
	char v2;      // bl
	double v3;    // st7
	long long v4; // rax
	double v5;    // st7
	double v6;    // st7
	char v7;      // bl
	char v8;      // bl
	int v9;       // eax
	double v10;   // st7
	int v11;      // ecx
	char v12;     // [esp+Fh] [ebp-15h]
	float v13;    // [esp+10h] [ebp-14h]
	int v14;      // [esp+18h] [ebp-Ch]
	char v15;     // [esp+28h] [ebp+4h]

	v1 = a1;
	v2 = *(uint8_t*)(a1 + 432);
	v12 = *(uint8_t*)(a1 + 432);
	if (v2 > 1 && *(uint16_t*)(a1 + 258)) {
		v3 = (double)nox_frame_xxx_2598000 / (double)(*(unsigned short*)(a1 + 258) * v2);
		v4 = (long long)v3;
		v5 = v3 - (double)(int)(long long)v3;
		if (*(uint8_t*)(a1 + 176) & 1) {
			v6 = v5 * (double)v2;
			v15 = (long long)v6;
			v7 = v15 + 1;
			if ((char)(v15 + 1) >= v12) {
				v7 = 0;
			}
		} else {
			v6 = v5 * (double)v2;
			if (v4 & 1) {
				v8 = v2 - (unsigned long long)(long long)v6 - 1;
				v15 = v8;
				v7 = v8 - 1;
				if (v7 < 0) {
					v7 = 0;
				}
			} else {
				v15 = (long long)v6;
				v7 = v15 + 1;
				if ((char)(v15 + 1) >= v12) {
					v7 = v12 - 1;
				}
			}
		}
		v13 = (double)*(unsigned short*)(v1 + 258);
		v9 = v7;
		v10 = (double)(unsigned char)(long long)((v6 - (double)(int)(long long)v6) * v13);
		v11 = v1 + 2 * v15 + v15;
		v14 = *(unsigned char*)(v15 + v1 + 2 * v15 + 120 + 60);
		nox_xxx_spriteChangeLightColor_484BE0(
			(uint32_t*)(v1 + 136),
			(long long)((double)(*(unsigned char*)(v9 + v1 + 2 * v9 + 178) - *(unsigned char*)(v11 + 178)) / v13 * v10 +
						(double)*(unsigned char*)(v11 + 178)),
			(long long)((double)(*(unsigned char*)(v9 + v1 + 2 * v9 + 179) - *(unsigned char*)(v11 + 179)) / v13 * v10 +
						(double)*(unsigned char*)(v11 + 179)),
			(long long)((double)(*(unsigned char*)(v9 + v1 + 2 * v9 + 120 + 60) - v14) / v13 * v10 + (double)v14));
	}
}

//----- (004CE610) --------------------------------------------------------
void nox_xxx_colorLightAlterIntensity_4CE610(int a1) {
	int v1;       // esi
	double v2;    // st7
	long long v3; // rax
	double v4;    // st7
	double v5;    // st7
	long long v6; // rax
	char v7;      // bl
	float v8;     // [esp+0h] [ebp-20h]
	char v9;      // [esp+24h] [ebp+4h]
	float v10;    // [esp+24h] [ebp+4h]

	v1 = a1;
	v9 = *(uint8_t*)(a1 + 433);
	if (v9 > 1 && *(uint16_t*)(v1 + 260)) {
		v2 = (double)nox_frame_xxx_2598000 / (double)(*(unsigned short*)(v1 + 260) * v9);
		v3 = (long long)v2;
		v4 = v2 - (double)(int)(long long)v2;
		if (*(uint8_t*)(v1 + 176) & 4) {
			v5 = v4 * (double)v9;
			v6 = (long long)v5;
			v7 = (unsigned long long)(long long)v5 + 1;
			if (v7 >= v9) {
				v7 = 0;
			}
		} else {
			v5 = v4 * (double)v9;
			if (v3 & 1) {
				LOBYTE(v6) = v9 - (unsigned long long)(long long)v5 - 1;
				v7 = v9 - (unsigned long long)(long long)v5 - 2;
				if (v7 < 0) {
					v7 = 0;
				}
			} else {
				v6 = (long long)v5;
				v7 = (unsigned long long)(long long)v5 + 1;
				if (v7 >= v9) {
					v7 = v9 - 1;
				}
			}
		}
		v10 = (double)*(unsigned short*)(v1 + 260);
		v8 = (double)(unsigned char)(long long)((v5 - (double)(int)(long long)v5) * v10) *
				 ((double)(*(unsigned char*)(v7 + v1 + 226) - *(unsigned char*)((char)v6 + v1 + 226)) / v10) +
			 (double)*(unsigned char*)((char)v6 + v1 + 226);
		nox_xxx_spriteChangeIntensity_484D70_light_intensity(v1 + 136, v8);
	}
}

//----- (004CE760) --------------------------------------------------------
int nox_xxx_colorLightAlterRadius_4CE760(int a1) {
	int v1;       // esi
	int result;   // eax
	char v3;      // bl
	double v4;    // st7
	long long v5; // rax
	double v6;    // st7
	double v7;    // st7
	long long v8; // rax
	char v9;      // bl
	char v10;     // bl
	char v11;     // [esp+20h] [ebp+4h]
	float v12;    // [esp+20h] [ebp+4h]

	v1 = a1;
	result = *(uint32_t*)(a1 + 168);
	v3 = *(uint8_t*)(a1 + 434);
	v11 = *(uint8_t*)(a1 + 434);
	if (!result && *(uint16_t*)(v1 + 262) > 0u && v3 > 1) {
		v4 = (double)nox_frame_xxx_2598000 / (double)(*(unsigned short*)(v1 + 262) * v3);
		v5 = (long long)v4;
		v6 = v4 - (double)(int)(long long)v4;
		if (*(uint8_t*)(v1 + 176) & 0x10) {
			v7 = v6 * (double)v3;
			v8 = (long long)v7;
			v9 = (unsigned long long)(long long)v7 + 1;
			if (v9 >= v11) {
				v9 = 0;
			}
		} else {
			v7 = v6 * (double)v3;
			if (v5 & 1) {
				v10 = v3 - (unsigned long long)(long long)v7 - 1;
				LOBYTE(v8) = v10;
				v9 = v10 - 1;
				if (v9 < 0) {
					v9 = 0;
				}
			} else {
				v8 = (long long)v7;
				v9 = (unsigned long long)(long long)v7 + 1;
				if (v9 >= v11) {
					v9 = v11 - 1;
				}
			}
		}
		v12 = (double)*(unsigned short*)(v1 + 262);
		result = nox_xxx_spriteChangeLightSize_484C30(
			v1 + 136,
			(long long)((double)(unsigned char)(long long)((v7 - (double)(int)(long long)v7) * v12) *
							((double)(*(unsigned char*)(v9 + v1 + 242) - *(unsigned char*)((char)v8 + v1 + 242)) /
							 v12) +
						(double)*(unsigned char*)((char)v8 + v1 + 242)));
	}
	return result;
}

//----- (004CE8C0) --------------------------------------------------------
void sub_4CE8C0(int a1) {
	uint32_t* v1; // eax
	int v2;       // esi
	double v3;    // st7
	int v4;       // [esp+10h] [ebp-8h]

	if (*(uint8_t*)(a1 + 176) & 0x40) {
		v1 = nox_xxx_netSpriteByCodeStatic_45A720(*(uint32_t*)(a1 + 264));
		if (v1) {
			v2 = v1[4] - *(uint32_t*)(a1 + 16);
			v4 = v1[3] - *(uint32_t*)(a1 + 12);
			v3 = nox_double2float(acos((double)v4 / sqrt((double)(v4 * v4 + v2 * v2)))) * 57.295776;
			if (v2 < 0) {
				v3 = 360.0 - v3;
			}
			sub_484C00(a1 + 136, (long long)v3);
		}
	}
}

//----- (004CE960) --------------------------------------------------------
void sub_4CE960(int a1) {
	short v2;  // cx
	double v3; // st7
	double v4; // st6
	double v5; // st5

	if (!*(uint32_t*)(a1 + 168)) {
		return;
	}
	v2 = *(uint16_t*)(a1 + 176);
	if ((v2 & 0x80u) == 0) {
		return;
	}
	short v1 = *(uint16_t*)(a1 + 270);
	if (!v1) {
		return;
	}
	if ((v2 & 0x100) == 256) {
		v5 = (double)(*(unsigned short*)(a1 + 272) - *(unsigned short*)(a1 + 268));
	} else {
		v5 = 360.0;
	}
	v4 = (double)nox_gameFPS;
	v3 = (double)v1;
	int v6 = (int)(((double)nox_frame_xxx_2598000 / (v5 / v3 * v4) -
					(double)(int)(long long)((double)nox_frame_xxx_2598000 / (v5 / v3 * v4))) *
					   (v5 / v3 * v4) * (v3 / v4) +
				   (double)*(unsigned short*)(a1 + 268));
	if (v6 >= 0) {
		if (v6 >= 360) {
			v6 -= 360;
		}
	} else {
		v6 += 360;
	}
	sub_484C00(a1 + 136, v6);
}

//----- (004CEA90) --------------------------------------------------------
int sub_4CEA90(float* a1, int2* a2, int a3) {
	int v3;  // ebx
	int v4;  // ebp
	int v5;  // esi
	int v7;  // [esp+10h] [ebp-18h]
	int v8;  // [esp+14h] [ebp-14h]
	int v9;  // [esp+18h] [ebp-10h]
	int v10; // [esp+1Ch] [ebp-Ch]
	int v11; // [esp+20h] [ebp-8h]

	v3 = a2->field_0 + nox_float2int(*a1);
	v4 = a2->field_4 + nox_float2int(a1[1]);
	v9 = a2->field_0 + nox_float2int(a1[2]);
	v10 = a2->field_4 + nox_float2int(a1[3]);
	v7 = a2->field_0 + nox_float2int(a1[4]);
	v8 = a2->field_4 + nox_float2int(a1[5]);
	v11 = a2->field_0 + nox_float2int(a1[6]);
	v5 = a2->field_4 + nox_float2int(a1[7]);
	nox_client_drawSetColor_434460(a3);
	nox_client_drawAddPoint_49F500(v3, v4);
	nox_client_drawAddPoint_49F500(v7, v8);
	nox_client_drawLineFromPoints_49E4B0();
	nox_client_drawAddPoint_49F500(v11, v5);
	nox_client_drawAddPoint_49F500(v7, v8);
	nox_client_drawLineFromPoints_49E4B0();
	nox_client_drawAddPoint_49F500(v3, v4);
	nox_client_drawAddPoint_49F500(v9, v10);
	nox_client_drawLineFromPoints_49E4B0();
	nox_client_drawAddPoint_49F500(v11, v5);
	nox_client_drawAddPoint_49F500(v9, v10);
	return nox_client_drawLineFromPoints_49E4B0();
}

//----- (004CEBA0) --------------------------------------------------------
int sub_4CEBA0(int a1, char* a2) {
	uint32_t* v2; // eax
	uint32_t* v3; // edi
	char* v4;     // ebx
	uint32_t* v5; // esi
	uint32_t* v6; // ebp
	uint32_t* v8; // [esp+10h] [ebp-4h]
	char* v9;     // [esp+18h] [ebp+4h]

	dword_5d4594_1523024 = nox_new_window_from_file("rulelist.wnd", sub_4CF060);
	dword_5d4594_1523028 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1523024, 10170);
	dword_5d4594_1523032 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1523024, 10171);
	dword_5d4594_1523036 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1523024, 10172);
	dword_5d4594_1523040 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1523024, 10173);
	dword_5d4594_1523044 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1523024, 10174);
	dword_5d4594_1523048 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1523024, 10175);
	v2 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1523024, 10176);
	nox_xxx_wndSetDrawFn_46B340((int)v2, sub_4CEED0);
	sub_46B120(*(uint32_t**)&dword_5d4594_1523024, a1);
	v3 = *(uint32_t**)(dword_5d4594_1523028 + 32);
	v9 = nox_xxx_gLoadImg_42F970("UISlider");
	v4 = nox_xxx_gLoadImg_42F970("UISliderLit");
	v5 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1523024, 10179);
	v6 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1523024, 10177);
	v8 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1523024, 10178);
	*(uint32_t*)(v5[100] + 8) = 16;
	*(uint32_t*)(v5[100] + 12) = 10;
	sub_4B5700((int)v5, 0, 0, (int)v9, (int)v4, (int)v4);
	nox_xxx_wnd_46B280((int)v5, *(int*)&dword_5d4594_1523028);
	nox_xxx_wnd_46B280((int)v6, *(int*)&dword_5d4594_1523028);
	nox_xxx_wnd_46B280((int)v8, *(int*)&dword_5d4594_1523028);
	v3[9] = v5;
	v3[7] = v6;
	v3[8] = v8;
	sub_4CED40(a2);
	return dword_5d4594_1523024;
}

//----- (004CED40) --------------------------------------------------------
void* sub_4CED40(char* a1) {
	HANDLE result;                         // eax
	HANDLE v2;                             // ebp
	struct _WIN32_FIND_DATAA FindFileData; // [esp+8h] [ebp-248h]
	char FileName[64];                     // [esp+148h] [ebp-108h]
	wchar_t v5[100];                       // [esp+188h] [ebp-C8h]

	nox_window_call_field_94(*(int*)&dword_5d4594_1523028, 16399, 0, 0);
	nox_sprintf(FileName, "maps\\%s\\*.rul", a1);
	result = FindFirstFileA(FileName, &FindFileData);
	v2 = result;
	if (result != (HANDLE)-1) {
		FindFileData.cFileName[strlen(FindFileData.cAlternateFileName) + 256] = 0;
		if (_strcmpi(a1, FindFileData.cAlternateFileName) && _strcmpi("user", FindFileData.cAlternateFileName)) {
			nox_swprintf(v5, L"%S", FindFileData.cAlternateFileName);
			nox_window_call_field_94(*(int*)&dword_5d4594_1523028, 16397, (int)v5, -1);
		}
		while (FindNextFileA(v2, &FindFileData)) {
			FindFileData.cFileName[strlen(FindFileData.cAlternateFileName) + 256] = 0;
			if (_strcmpi(a1, FindFileData.cAlternateFileName)) {
				if (_strcmpi("user", FindFileData.cAlternateFileName)) {
					nox_swprintf(v5, L"%S", FindFileData.cAlternateFileName);
					nox_window_call_field_94(*(int*)&dword_5d4594_1523028, 16397, (int)v5, -1);
				}
			}
		}
		result = (HANDLE)FindClose(v2);
	}
	return result;
}

//----- (004CEED0) --------------------------------------------------------
int sub_4CEED0(int a1, int a2) {
	int v2;       // eax
	char v3;      // cl
	uint16_t* v4; // esi
	uint32_t* v5; // eax
	int xLeft;    // [esp+8h] [ebp-8h]
	int yTop;     // [esp+Ch] [ebp-4h]

	nox_client_wndGetPosition_46AA60((uint32_t*)a1, &xLeft, &yTop);
	if ((signed char)*(uint8_t*)(a1 + 4) >= 0) {
		if (*(uint32_t*)(a2 + 20) != 0x80000000) {
			nox_client_drawRectFilledOpaque_49CE30(xLeft, yTop, *(uint32_t*)(a1 + 8), *(uint32_t*)(a1 + 12));
		}
	} else {
		nox_client_drawImageAt_47D2C0(*(uint32_t*)(a2 + 24), xLeft, yTop);
	}
	v2 = nox_window_call_field_94(*(int*)&dword_5d4594_1523028, 16404, 0, 0);
	v3 = *(uint8_t*)(dword_5d4594_1523040 + 4);
	if (v2 < 0) {
		if (v3 & 8) {
			nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1523040, 0);
		}
		if (*(uint8_t*)(dword_5d4594_1523044 + 4) & 8) {
			nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1523044, 0);
		}
		if (*(uint8_t*)(dword_5d4594_1523048 + 4) & 8) {
			nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1523048, 0);
		}
	} else {
		if (!(v3 & 8)) {
			nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1523040, 1);
		}
		if (!(*(uint8_t*)(dword_5d4594_1523044 + 4) & 8) && !nox_common_gameFlags_check_40A5C0(49152)) {
			nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1523044, 1);
		}
		if (!(*(uint8_t*)(dword_5d4594_1523048 + 4) & 8)) {
			nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1523048, 1);
		}
	}
	v4 = (uint16_t*)nox_window_call_field_94(*(int*)&dword_5d4594_1523032, 16413, 0, 0);
	v5 = (uint32_t*)nox_xxx_wndGetFocus_46B4F0();
	if (v5 && *v5 == 10171) {
		if (v4 && *v4) {
			if (!(*(uint8_t*)(dword_5d4594_1523036 + 4) & 8)) {
				nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1523036, 1);
				return 1;
			}
		} else if (*(uint8_t*)(dword_5d4594_1523036 + 4) & 8) {
			nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1523036, 0);
		}
	}
	return 1;
}

//----- (004CF060) --------------------------------------------------------
int sub_4CF060(int a1, unsigned int a2, int* a3, int a4) {
	uint32_t* v4;       // esi
	const char* v6;     // eax
	const char* v7;     // esi
	char* v8;           // eax
	int v9;             // esi
	int v10;            // eax
	int v11;            // eax
	char* v12;          // eax
	char* v13;          // eax
	char* v14;          // esi
	int v15;            // eax
	int v16;            // eax
	char* v17;          // eax
	char* v18;          // edi
	int v19;            // eax
	int v20;            // esi
	int v21;            // eax
	const wchar_t* v22; // edi
	char* v23;          // eax
	char* v24;          // eax
	int v25;            // esi
	int v26;            // ebx
	const wchar_t* v27; // eax
	char v28[16];       // [esp+Ch] [ebp-10h]

	if (a2 > 0x4007) {
		if (a2 == 16400) {
			nox_xxx_wndGetID_46B0A0(a3);
		}
		return 1;
	}
	if (a2 != 16391) {
		if (a2 != 23 && a2 == 16387) {
			v4 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1523024, a4);
			if (!v4) {
				return 0;
			}
			if ((unsigned short)a3 == 1) {
				return 0;
			}
			v6 = (const char*)nox_window_call_field_94((int)v4, 16413, 0, 0);
			v7 = v6;
			if (v6) {
				if (*v6) {
					atoi(v6);
					if (a4 == 10171) {
						v8 = sub_4165B0();
						if (!_strcmpi(v7, v8) || !_strcmpi(v7, "user")) {
							nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1523036, 0);
							return 1;
						}
					}
				}
			}
		}
		return 1;
	}
	v9 = nox_xxx_wndGetID_46B0A0(a3);
	nox_xxx_clientPlaySoundSpecial_452D80(766, 100);
	switch (v9) {
	case 10172:
		sub_416580();
		v22 = (const wchar_t*)nox_window_call_field_94(*(int*)&dword_5d4594_1523032, 16413, 0, 0);
		nox_sprintf(v28, "%S%s", v22, getMemAt(0x587000, 191640));
		v23 = sub_4165B0();
		sub_459AA0((int)v23);
		v24 = sub_4165B0();
		sub_57AAA0(v28, v24, 0);
		v25 = 0;
		v26 = *(uint32_t*)(dword_5d4594_1523028 + 32);
		if (*(short*)(v26 + 44) <= 0) {
			goto LABEL_22;
		}
		break;
	case 10173:
		sub_416580();
		v10 = nox_window_call_field_94(*(int*)&dword_5d4594_1523028, 16404, 0, 0);
		v11 = nox_window_call_field_94(*(int*)&dword_5d4594_1523028, 16406, v10, 0);
		nox_sprintf(v28, "%S%s", v11, getMemAt(0x587000, 191592));
		v12 = sub_4165B0();
		sub_459AA0((int)v12);
		v13 = sub_4165B0();
		sub_57AAA0(v28, v13, 0);
		nox_window_call_field_94(*(int*)&dword_5d4594_1523028, 16403, -1, 0);
		return 1;
	case 10174:
		sub_416580();
		v14 = sub_4165B0();
		v15 = nox_window_call_field_94(*(int*)&dword_5d4594_1523028, 16404, 0, 0);
		v16 = nox_window_call_field_94(*(int*)&dword_5d4594_1523028, 16406, v15, 0);
		nox_sprintf(v28, "%S%s", v16, getMemAt(0x587000, 191608));
		sub_57A1E0((int*)v14, v28, 0, 7, *((uint16_t*)v14 + 26));
		sub_453F70(v14 + 24);
		sub_4535E0((int*)v14 + 11);
		sub_4535F0(*((uint32_t*)v14 + 12));
		v17 = sub_4165B0();
		sub_459880((int)v17);
		nox_window_call_field_94(*(int*)&dword_5d4594_1523028, 16403, -1, 0);
		sub_459D50(1);
		return 1;
	case 10175:
		v18 = sub_4165B0();
		v19 = nox_window_call_field_94(*(int*)&dword_5d4594_1523028, 16404, 0, 0);
		v20 = v19;
		v21 = nox_window_call_field_94(*(int*)&dword_5d4594_1523028, 16406, v19, 0);
		nox_sprintf(v28, "%S%s", v21, getMemAt(0x587000, 191624));
		sub_57A9F0(v18, v28);
		nox_window_call_field_94(*(int*)&dword_5d4594_1523028, 16398, v20, 0);
		return 1;
	default:
		return 1;
	}
	while (1) {
		v27 = (const wchar_t*)nox_window_call_field_94(*(int*)&dword_5d4594_1523028, 16406, v25, 0);
		if (!_nox_wcsicmp(v22, v27)) {
			break;
		}
		if (++v25 >= *(short*)(v26 + 44)) {
		LABEL_22:
			nox_window_call_field_94(*(int*)&dword_5d4594_1523028, 16397, (int)v22, -1);
			nox_window_call_field_94(*(int*)&dword_5d4594_1523032, 16414, (int)getMemAt(0x5D4594, 1523056), 0);
			nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1523036, 0);
			return 1;
		}
	}
	nox_window_call_field_94(*(int*)&dword_5d4594_1523032, 16414, (int)getMemAt(0x5D4594, 1523052), 0);
	return 1;
}

//----- (004CF470) --------------------------------------------------------
int nox_xxx_mapValidateMB_4CF470(char* a1, int a2) {
	int v2;              // ebx
	int v4;              // [esp+8h] [ebp-408h]
	int v5;              // [esp+Ch] [ebp-404h]
	char FileName[1024]; // [esp+10h] [ebp-400h]

	v2 = 0;
	if (!a2) {
		return 6;
	}
	if (a1) {
		if (strchr(a1, 92)) {
			strcpy(FileName, a1);
		} else {
			strcpy(FileName, "maps\\");
			strncat(FileName, a1, (strlen(a1) - 4 < 1024 ? strlen(a1) - 4 : 1024));
			*(uint16_t*)&FileName[strlen(FileName)] = *getMemU16Ptr(0x587000, 191672);
			strcat(FileName, a1);
		}
		if (_access(FileName, 0) != -1) {
			v4 = 0;
			if (_access(FileName, 2) == -1) {
				v2 = 1;
			}
			if (nox_xxx_cryptOpen_426910(FileName, 1, 19)) {
				v2 |= 2u;
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v5, 4u);
				if (v5 != -86065425 && v5 == -86050098) {
					nox_xxx_fileCryptReadCrcMB_426C20(&v4, 4u);
					if (v4 == a2) {
						v2 |= 4u;
					}
				}
				nox_xxx_cryptClose_4269F0();
			}
		}
	}
	return v2;
}

//----- (004CF990) --------------------------------------------------------
char nox_xxx_mapReadSetFlags_4CF990() {
	char* v0;          // esi
	char* v1;          // eax
	unsigned short v2; // ax
	int v3 = 0;        // eax
	int v4;            // esi
	short v5;          // ax

	v0 = sub_4165B0();
	if (nox_common_gameFlags_check_40A5C0(1024) && (*getMemIntPtr(0x973F18, 3800) < 0 || !(v0[53] & 4))) {
		nox_xxx_ruleSetNoRespawn_40A5E0(0);
	}
	sub_455C10();
	sub_456050();
	if (nox_common_gameFlags_check_40A5C0(4096) && *getMemIntPtr(0x973F18, 3800) < 0) {
		sub_4D6B10(1);
		sub_419030(1);
	}
	v1 = nox_xxx_mapGetMapName_409B40();
	if (nox_common_checkMapFile_4CFE10(v1)) {
		v2 = nox_xxx_mapGetTypeMB_4CFFA0((int)getMemAt(0x973F18, 2408));
		if (getMemByte(0x973F18, 3800) & 1) {
			nox_common_gameFlags_unset_40A540(6128);
			nox_xxx_createCoopTeam_417E10();
			nox_xxx_setGameFlags_40A4D0(2048);
		} else if (getMemByte(0x973F18, 3800) & 2) {
			v4 = nox_common_gameFlags_check_40A5C0(128);
			nox_common_gameFlags_unset_40A540(6128);
			nox_xxx_setGameFlags_40A4D0(4096);
			if (v4) {
				LOBYTE(v3) = nox_server_setupQuestGame_4D6C70();
			}
		} else if ((int)*getMemU32Ptr(0x973F18, 3800) >= 0) {
			if (!(*((uint16_t*)v0 + 26) & v2)) {
				*((uint16_t*)v0 + 26) = sub_4CFC90((int)getMemAt(0x973F18, 2408)) | *((uint16_t*)v0 + 26) & 0xE80F;
			}
			if (!(v0[52] & 0x10)) {
				nox_xxx_mapFindCrown_4CFC30();
			}
			v5 = *((uint16_t*)v0 + 26);
			if (v5 & 0x20) {
				v3 = nox_xxx_mapInfoSetCapflag_417EA0();
				if (v3) {
					nox_common_gameFlags_unset_40A540(6128);
					nox_xxx_setGameFlags_40A4D0(32);
				}
			} else if (v5 & 0x40) {
				LOBYTE(v3) = nox_xxx_mapInfoSetFlagball_417F30();
				if (v3) {
					nox_common_gameFlags_unset_40A540(6128);
					nox_xxx_setGameFlags_40A4D0(64);
					LOBYTE(v3) = nox_xxx_spellDisable_424BB0(132);
				}
			} else if (v5 & 0x10) {
				v3 = nox_xxx_mapInfoSetKotr_4180D0();
				if (v3) {
					nox_common_gameFlags_unset_40A540(6128);
					nox_xxx_setGameFlags_40A4D0(16);
				}
			} else if (v5 & 0x400) {
				if (!nox_common_gameFlags_check_40A5C0(1024)) {
					nox_xxx_ruleSetNoRespawn_40A5E0(1);
				}
				nox_common_gameFlags_unset_40A540(6128);
				nox_xxx_setGameFlags_40A4D0(1024);
			} else {
				nox_common_gameFlags_unset_40A540(6128);
				nox_xxx_setGameFlags_40A4D0(256);
			}
		} else {
			sub_40A1F0(0);
			nox_common_gameFlags_unset_40A540(6128);
			nox_xxx_setGameFlags_40A4D0(128);
			LOBYTE(v3) = nox_xxx_getTeamCounter_417DD0();
			if ((uint8_t)v3) {
				nox_xxx_teamAssignFlags_418640();
				v3 = nox_xxx_CheckGameplayFlags_417DA0(2);
				if (!v3) {
					v3 = nox_common_gameFlags_check_40A5C0(0x8000);
					if (!v3) {
						LOBYTE(v3) = (unsigned int)nox_xxx_toggleAllTeamFlags_418690(1);
					}
				}
			}
		}
	} else {
		v3 = nox_common_gameFlags_check_40A5C0(512);
		if (!v3) {
			nox_common_gameFlags_unset_40A540(6128);
			nox_xxx_setGameFlags_40A4D0(256);
			LOBYTE(v3) = sub_4D0D90(1);
		}
	}
	return v3;
}
// 4CFAF1: variable 'v2' is possibly undefined
// 4CFB53: variable 'v3' is possibly undefined

//----- (004CFC30) --------------------------------------------------------
void nox_xxx_mapFindCrown_4CFC30() {
	int v0; // esi
	int v1; // edi

	if (!*getMemU32Ptr(0x5D4594, 1523076)) {
		*getMemU32Ptr(0x5D4594, 1523076) = nox_xxx_getNameId_4E3AA0("Crown");
	}
	v0 = nox_server_getFirstObject_4DA790();
	if (v0) {
		do {
			v1 = nox_server_getNextObject_4DA7A0(v0);
			if (*(unsigned short*)(v0 + 4) == *getMemU32Ptr(0x5D4594, 1523076)) {
				nox_xxx_delayedDeleteObject_4E5CC0(v0);
				sub_4EC6A0(v0);
			}
			v0 = v1;
		} while (v1);
	}
}

//----- (004CFC90) --------------------------------------------------------
int sub_4CFC90(int a1) {
	int v1; // eax

	v1 = *(uint32_t*)(a1 + 1392);
	if (v1 & 4) {
		return 256;
	}
	if (v1 & 0x20) {
		return 1024;
	}
	if (v1 & 8) {
		return 32;
	}
	if (v1 & 0x10) {
		return 16;
	}
	if (v1 & 0x40) {
		return 64;
	}
	return (v1 & 2) != 0 ? 4096 : 128;
}

//----- (004CFCE0) --------------------------------------------------------
int nox_xxx_serverParseEntireMap_4CFCE0() {
	uint32_t* v0; // eax
	int v1;       // esi
	int v3;       // [esp+4h] [ebp-114h]
	int v4;       // [esp+8h] [ebp-110h]
	int v5[2];
	int v7;       // [esp+14h] [ebp-104h]
	char v8[256]; // [esp+18h] [ebp-100h]

	nox_xxx_fileReadWrite_426AC0_file3_fread(&v5[0], 4u);
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v5[1], 4u);
	nox_xxx_mapWall_426A80(&v5);
	while (1) {
		LOBYTE(v3) = 0;
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v3, 1u);
		if (!(uint8_t)v3) {
			break;
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread(v8, (unsigned char)v3);
		nox_xxx_fileCryptReadCrcMB_426C20(&v7, 4u);
		if (!nox_xxx_mapReadSection_426EA0(0, v8, &v4)) {
			if (v4 == 1) {
				return 0;
			}
			v0 = nox_xxx_newObjectByTypeID_4E3810(v8);
			v1 = (int)v0;
			if (!v0 || !((int (*)(uint32_t*, uint32_t))v0[176])(v0, 0)) {
				goto LABEL_9;
			}
			nox_xxx_servMapLoadPlaceObj_4F3F50(v1, 0, 0);
		}
	}
	if (!sub_579CA0()) {
	LABEL_9:
		nox_xxx_cryptClose_4269F0();
		return 0;
	}
	sub_4DAF10();
	if (nox_common_gameFlags_check_40A5C0(1)) {
		nox_xxx_waypoint_5799C0();
		nox_xxx_unitsNewAddToList_4DAC00();
	}
	return 1;
}

//----- (004CFDF0) --------------------------------------------------------
int sub_4CFDF0(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 1523072) = a1;
	return result;
}

//----- (004CFE00) --------------------------------------------------------
int sub_4CFE00() { return *getMemU32Ptr(0x5D4594, 1523072); }

//----- (004CFE10) --------------------------------------------------------
int nox_common_checkMapFile_4CFE10(const char* a1) {
	char pbuf[256];
	strcpy(pbuf, "maps\\");
	strcat(pbuf, a1);
	strcat(pbuf, "\\");
	strcat(pbuf, a1);
	strcat(pbuf, ".map");

	if (!nox_xxx_cryptOpen_426910(pbuf, 1, 19)) {
		return 0;
	}
	int magic = 0;
	int crc = 0;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&magic, 4);
	if (magic != -86065425) {     // 0xFADEBEEF
		if (magic != -86050098) { // 0xFADEFACE
			nox_xxx_cryptClose_4269F0();
			return 0;
		}
		nox_xxx_fileCryptReadCrcMB_426C20(&crc, 4);
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread(pbuf, 32);
	if (!nox_server_mapRWMapInfo_42A6E0()) {
		nox_xxx_cryptClose_4269F0();
		return 0;
	}
	nox_xxx_cryptClose_4269F0();
	return 1;
}

//----- (004CFF50) --------------------------------------------------------
int sub_4CFF50(int a1) {
	int result; // eax

	result = 0;
	if (a1 & 1) {
		result = 512;
	}
	if (a1 & 2) {
		BYTE1(result) |= 0x10u;
	}
	if (a1 & 4) {
		BYTE1(result) |= 1u;
	}
	if (a1 & 0x20) {
		BYTE1(result) |= 4u;
	}
	if (a1 & 8) {
		LOBYTE(result) = result | 0x20;
	}
	if (a1 & 0x10) {
		LOBYTE(result) = result | 0x10;
	}
	if (a1 & 0x40) {
		LOBYTE(result) = result | 0x40;
	}
	if (a1 < 0) {
		LOBYTE(result) = result | 0x80;
	}
	return result;
}

//----- (004CFFA0) --------------------------------------------------------
int nox_xxx_mapGetTypeMB_4CFFA0(int a1) { return sub_4CFF50(*(uint32_t*)(a1 + 1392)); }

//----- (004CFFC0) --------------------------------------------------------
int sub_4CFFC0(int a1) { return sub_4CFF50(*(uint32_t*)(a1 + 28)); }

//----- (004CFFE0) --------------------------------------------------------
int sub_4CFFE0(int a1) {
	int result; // eax

	result = nox_server_getFirstObjectUninited_4DA870();
	if (!result) {
		return 0;
	}
	while (*(uint32_t*)(result + 44) != a1) {
		result = nox_server_getNextObjectUninited_4DA880(result);
		if (!result) {
			return 0;
		}
	}
	return result;
}

//----- (004D0010) --------------------------------------------------------
int nox_xxx_interesting_xfer_4D0010(uint32_t* a1, int a2) {
	int i;          // eax
	uint32_t* v3;   // edi
	char* v4;       // eax
	int (*v5)(int); // eax
	int v6;         // esi
	int v7;         // eax
	int v8;         // ecx
	int v9;         // eax
	int v10;        // ecx
	int v11;        // esi
	int v12;        // eax
	int v13;        // ecx
	int v14;        // esi
	char* v15;      // eax
	int v16;        // ecx
	int v17;        // esi
	char* v18;      // eax
	int v19;        // esi
	uint32_t* v20;  // eax
	int v21;        // eax
	int v22;        // esi
	char* v23;      // eax

	for (i = nox_server_getFirstObjectUninited_4DA870(); i; i = nox_server_getNextObjectUninited_4DA880(i)) {
		*(uint32_t*)(i + 44) = *(uint32_t*)(i + 40);
		*(uint32_t*)(i + 40) = a2++;
	}
	v3 = (uint32_t*)nox_server_getFirstObjectUninited_4DA870();
	if (v3) {
		while (1) {
			v4 = (char*)nox_xxx_getUnitName_4E39D0((int)v3);
			v5 = *(int (**)(int))(nox_xxx_objectTypeByID_4E3B60(v4) + 212);
			if (v5 != nox_xxx_XFerElevator_4F53D0) {
				break;
			}
			v6 = v3[187];
			v7 = sub_4CFFE0(*(uint32_t*)(v6 + 8));
			if (!v7) {
				goto LABEL_7;
			}
			v8 = *(uint32_t*)(v7 + 40);
			*(uint32_t*)(v6 + 4) = v7;
			*(uint32_t*)(v6 + 8) = v8;
		LABEL_28:
			v3 = (uint32_t*)nox_server_getNextObjectUninited_4DA880((int)v3);
			if (!v3) {
				return a2;
			}
		}
		if (v5 != nox_xxx_XFerElevatorShaft_4F54A0) {
			if (v5 == nox_xxx_XFerTransporter_4F5300) {
				v11 = v3[187];
				v12 = sub_4CFFE0(*(uint32_t*)(v11 + 16));
				if (v12) {
					v13 = *(uint32_t*)(v12 + 40);
					*(uint32_t*)(v11 + 12) = v12;
					*(uint32_t*)(v11 + 16) = v13;
				} else {
					*(uint32_t*)(v11 + 16) = 0;
					*(uint32_t*)(v11 + 12) = 0;
				}
			} else if (v5 == nox_xxx_XFerHole_4F51D0) {
				v14 = v3[175];
				v15 = nox_xxx_mapGetWallSize_426A70();
				v16 = *(uint32_t*)(v14 + 12);
				*(uint32_t*)(v14 + 8) += *a1 - 23 * *(uint32_t*)v15;
				*(uint32_t*)(v14 + 12) = a1[1] - 23 * *((uint32_t*)v15 + 1) + v16;
			} else if (v5 == nox_xxx_XFerExit_4F4B90) {
				v17 = v3[175];
				v18 = nox_xxx_mapGetWallSize_426A70();
				*(float*)(v17 + 80) = (double)(int)(*a1 - 23 * *(uint32_t*)v18) + *(float*)(v17 + 80);
				*(float*)(v17 + 84) = (double)(int)(a1[1] - 23 * *((uint32_t*)v18 + 1)) + *(float*)(v17 + 84);
			} else if (v5 == nox_xxx_XFerMover_4F5730) {
				v19 = v3[187];
				v20 = (uint32_t*)sub_579C60(*(uint32_t*)(v19 + 8));
				if (v20) {
					*(uint32_t*)(v19 + 8) = *v20;
				} else {
					*(uint32_t*)(v19 + 8) = 0;
				}
				v21 = sub_4CFFE0(*(uint32_t*)(v19 + 32));
				if (v21) {
					*(uint32_t*)(v19 + 32) = *(uint32_t*)(v21 + 40);
				} else {
					*(uint32_t*)(v19 + 32) = 0;
				}
			} else if (v5 == nox_xxx_XFerGlyph_4F5890) {
				v22 = v3[173];
				v23 = nox_xxx_mapGetWallSize_426A70();
				*(float*)(v22 + 28) = (double)(int)(*a1 - 23 * *(uint32_t*)v23) + *(float*)(v22 + 28);
				*(float*)(v22 + 32) = (double)(int)(a1[1] - 23 * *((uint32_t*)v23 + 1)) + *(float*)(v22 + 32);
			}
			goto LABEL_28;
		}
		v6 = v3[187];
		v9 = sub_4CFFE0(*(uint32_t*)(v6 + 8));
		if (v9) {
			v10 = *(uint32_t*)(v9 + 40);
			*(uint32_t*)(v6 + 4) = v9;
			*(uint32_t*)(v6 + 8) = v10;
			goto LABEL_28;
		}
	LABEL_7:
		*(uint32_t*)(v6 + 8) = 0;
		*(uint32_t*)(v6 + 4) = 0;
		goto LABEL_28;
	}
	return a2;
}

//----- (004D0250) --------------------------------------------------------
int sub_4D0250(char* a1, char* a2, int a3, int a4) {
	int result;    // eax
	FILE* v5;      // esi
	uint32_t* v6;  // edi
	int v7;        // ebp
	uint32_t* v8;  // esi
	int i;         // eax
	int j;         // eax
	int v11;       // esi
	int k;         // eax
	int l;         // eax
	int v14;       // [esp+10h] [ebp-148h]
	int v15;       // [esp+14h] [ebp-144h]
	int v16;       // [esp+18h] [ebp-140h]
	int v17[2];    // [esp+1Ch] [ebp-13Ch]
	int v19;       // [esp+24h] [ebp-134h]
	int v20;       // [esp+28h] [ebp-130h]
	int v21;       // [esp+2Ch] [ebp-12Ch]
	int v22;       // [esp+30h] [ebp-128h]
	int v23;       // [esp+34h] [ebp-124h]
	int v24;       // [esp+38h] [ebp-120h]
	int v25;       // [esp+3Ch] [ebp-11Ch]
	int v26;       // [esp+40h] [ebp-118h]
	int v27;       // [esp+44h] [ebp-114h]
	int4 v28;      // [esp+48h] [ebp-110h]
	char v29[256]; // [esp+58h] [ebp-100h]

	if (a3 <= 0) {
		return 0;
	}
	result = nox_xxx_cryptOpen_426910(a1, 1, -1);
	if (result) {
		v5 = nox_xxx_mapgenGetSomeFile_426A60();
		nox_fs_fread(v5, &v16, 4);
		if (v16 == a4) {
			nox_fs_fread(v5, &v17[0], 4);
			nox_fs_fread(v5, &v17[1], 4);
			nox_xxx_mapWall_426A80(v17);
			nox_fs_fread(v5, &v19, 4);
			nox_fs_fread(v5, &v20, 4);
			nox_fs_fread(v5, &v25, 4);
			nox_fs_fread(v5, &v26, 4);
			nox_fs_fread(v5, &v21, 4);
			nox_fs_fread(v5, &v22, 4);
			nox_fs_fread(v5, &v23, 4);
			nox_fs_fread(v5, &v24, 4);
			v6 = a2;
			if (!a2) {
				v6 = &v19;
			}
			sub_428170(v6, &v28);
			v7 = nox_xxx_wallGet_426A30();
			sub_426A20(5);
			nox_xxx_cryptSetTypeMB_426A50(1);
			while (1) {
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v15, 1u);
				if (!(uint8_t)v15) {
					break;
				}
				nox_xxx_fileReadWrite_426AC0_file3_fread(v29, (unsigned char)v15);
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v27, 4u);
				if (!nox_xxx_mapReadSection_426EA0((int)v6, v29, &v14)) {
					if (v14 == 1) {
						goto LABEL_20;
					}
					v8 = nox_xxx_newObjectByTypeID_4E3810(v29);
					if (!v8) {
						nox_xxx_cryptSetTypeMB_426A50(0);
						return 0;
					}
					if (!((int (*)(uint32_t*, int4*))v8[176])(v8, &v28)) {
						sub_426A20(v7);
						nox_xxx_objectFreeMem_4E38A0((int)v8);
						nox_xxx_cryptClose_4269F0();
						return 0;
					}
					nox_xxx_servMapLoadPlaceObj_4F3F50((int)v8, 0, &v28.field_0);
				}
			}
			for (i = nox_server_getFirstObjectUninited_4DA870(); i; i = nox_server_getNextObjectUninited_4DA880(i)) {
				*(uint32_t*)(i + 16) |= 0x80000000;
			}
			nox_xxx_cryptSetTypeMB_426A50(0);
			sub_426A20(v7);
			nox_xxx_cryptClose_4269F0();
			if (!sub_579D20()) {
			LABEL_20:
				sub_426A20(v7);
				nox_xxx_cryptClose_4269F0();
				return 0;
			}
			for (j = sub_579890(); j; j = sub_5798A0(j)) {
				*(uint32_t*)(j + 480) |= 0x80000000;
			}
			v11 = nox_xxx_interesting_xfer_4D0010(&v28, a3);
			for (k = sub_579890(); k; k = sub_5798A0(k)) {
				*(uint32_t*)(k + 4) = 0;
			}
			for (l = nox_server_getFirstObjectUninited_4DA870(); l; l = nox_server_getNextObjectUninited_4DA880(l)) {
				*(uint32_t*)(l + 44) = 0;
			}
			nox_xxx_waypoint_5799C0();
			nox_xxx_unitClearPendingMB_4DB030();
			result = v11;
		} else {
			result = 0;
		}
	}
	return result;
}

//----- (004D0550) --------------------------------------------------------
int sub_4D0550(char* a1) {
	int result;       // eax
	unsigned int v2;  // kr08_4
	char v3;          // cl
	int v4;           // edx
	unsigned char v5; // al
	char* v6;         // edi
	char* v7;         // edi
	unsigned char v8; // cl
	unsigned char v9; // [esp+4h] [ebp-104h]
	char v10[256];    // [esp+8h] [ebp-100h]

	result = 0;
	if (a1) {
		v10[0] = 0;
		strncat(v10, a1, (strlen(a1) - 4 < 256 ? strlen(a1) - 4 : 256));
		v2 = strlen(v10) + 1;
		v3 = v2 - 1;
		v9 = v2 - 1;
		if ((uint8_t)v2 != 1) {
			while (v10[v9] != 92) {
				v9 = --v3;
				if (!v3) {
					goto LABEL_7;
				}
			}
			v10[v9 + 1] = 0;
		}
	LABEL_7:
		v4 = *getMemU32Ptr(0x587000, 191752);
		v5 = getMemByte(0x587000, 191756);
		v6 = &v10[strlen(v10)];
		*(uint32_t*)v6 = *getMemU32Ptr(0x587000, 191748);
		*((uint32_t*)v6 + 1) = v4;
		v6[8] = v5;
		if (!sub_4D0670(v10)) {
			v10[0] = 0;
			strncat(v10, a1, (strlen(a1) - 4 < 256 ? strlen(a1) - 4 : 256));
			v7 = &v10[strlen(v10) + 1];
			v8 = getMemByte(0x587000, 191764);
			*(uint32_t*)--v7 = *getMemU32Ptr(0x587000, 191760);
			v7[4] = v8;
			sub_4D0670(v10);
		}
		if (nox_xxx_check_flag_aaa_43AF70() == 1) {
			sub_4D0670((char*)getMemAt(0x587000, 191768));
		}
		result = 1;
	}
	return result;
}

//----- (004D0670) --------------------------------------------------------
int sub_4D0670(char* a1) {
	int v1;          // ebp
	FILE* v2;        // eax
	FILE* v3;        // esi
	char* v4;        // eax
	int v5;          // eax
	char v7[255];    // [esp+Ch] [ebp-300h]
	wchar_t v8[256]; // [esp+10Ch] [ebp-200h]

	v1 = 6128;
	v2 = nox_fs_open_text(a1);
	v3 = v2;
	if (!v2) {
		return 0;
	}
	if (!nox_fs_feof(v3)) {
		do {
			memset(v7, 0, 0xFCu);
			*(uint16_t*)&v7[252] = 0;
			v7[254] = 0;
			nox_fs_fgets(v3, v7, 255);
			v4 = strchr(v7, 10);
			if (v4) {
				*v4 = 0;
			}
			if (v7[0]) {
				nox_swprintf(v8, L"%S", v7);
				v5 = sub_57AE30(v7);
				if (v5) {
					v1 = v5;
				} else if (nox_common_gameFlags_check_40A5C0(v1)) {
					nox_server_parseCmdText_443C80(v8, 1);
				}
			}
		} while (!nox_fs_feof(v3));
	}
	nox_fs_close(v3);
	return 1;
}

//----- (004D0760) --------------------------------------------------------
void nox_common_maplist_add_4D0760(nox_map_list_item* map) {
	nox_map_list_item* it = nox_common_list_getFirstSafe_425890(&nox_common_maplist);
	if (!it) {
		nox_common_list_append_4258E0(&nox_common_maplist, map);
		return;
	}
	while (strcmp(map->name, it->name) > 0) {
		it = nox_common_list_getNextSafe_4258A0(it);
		if (!it) {
			nox_common_list_append_4258E0(&nox_common_maplist, map);
			return;
		}
	}
	nox_common_list_append_4258E0(it, map);
}

//----- (004D07F0) --------------------------------------------------------
void nox_common_scanAddMap(char* filename) {
	char name[12];
	strncpy(name, filename, 8);
	name[8] = 0;
	if (!nox_common_checkMapFile_4CFE10(name)) {
		return;
	}
	nox_map_list_item* map = calloc(1, sizeof(nox_map_list_item));
	sub_425770(map);
	strcpy(map->name, name);
	map->field_6 = 1;
	map->field_7 = *getMemU32Ptr(0x973F18, 3800);
	map->field_8_0 = getMemByte(0x973F18, 3804);
	map->field_8_1 = getMemByte(0x973F18, 3805);
	nox_common_maplist_add_4D0760(map);
}

#ifndef NOX_CGO
int nox_common_scanAllMaps_4D07F0() {
	nox_common_list_clear_425760(&nox_common_maplist);

	struct _WIN32_FIND_DATAA FindFileData;
	HANDLE v1 = FindFirstFileA((const char*)"maps\\*.*", &FindFileData);
	if (v1 == -1) {
		return -1;
	}
	do {
		if (FindFileData.dwFileAttributes & 0x10 &&
			((_strnicmp(FindFileData.cFileName, "wiz", 3u) != 0 && _strnicmp(FindFileData.cFileName, "war", 3u) != 0 &&
			  _strnicmp(FindFileData.cFileName, "con", 3u) != 0) ||
			 FindFileData.cFileName[3] < 48 || FindFileData.cFileName[3] > 57) &&
			strcmp(FindFileData.cFileName, ".") != 0 && strcmp(FindFileData.cFileName, "..") != 0) {

			nox_common_scanAddMap(FindFileData.cFileName);
		}
	} while (FindNextFileA(v1, &FindFileData));
	return FindClose(v1);
}
#endif // NOX_CGO

//----- (004D0970) --------------------------------------------------------
void nox_common_maplist_free_4D0970() {
	int* result; // eax
	int* v1;     // esi
	int* v2;     // edi

	result = nox_common_list_getFirstSafe_425890(&nox_common_maplist);
	v1 = result;
	if (result) {
		do {
			v2 = nox_common_list_getNextSafe_4258A0(v1);
			sub_425920((uint32_t**)v1);
			free(v1);
			v1 = v2;
		} while (v2);
	}
}

//----- (004D09B0) --------------------------------------------------------
nox_map_list_item* nox_common_maplist_first_4D09B0() {
	return nox_common_list_getFirstSafe_425890(&nox_common_maplist);
}

//----- (004D09C0) --------------------------------------------------------
nox_map_list_item* nox_common_maplist_next_4D09C0(nox_map_list_item* list) {
	return nox_common_list_getNextSafe_4258A0(list);
}

//----- (004D09D0) --------------------------------------------------------
nox_map_list_item* nox_common_maplist_mapByName_4D09D0(char* a1) {
	int* v1; // esi

	v1 = nox_common_maplist_first_4D09B0();
	if (!v1) {
		return 0;
	}
	while (_strcmpi(a1, (const char*)v1 + 12) || !v1[6]) {
		v1 = nox_common_maplist_next_4D09C0(v1);
		if (!v1) {
			return 0;
		}
	}
	return v1;
}

//----- (004D0A30) --------------------------------------------------------
FILE* nox_xxx_loadMapCycle_4D0A30() {
	int v0;        // ebp
	FILE* result;  // eax
	FILE* v7;      // ebx
	int v8;        // eax
	int v9;        // edx
	int v10;       // eax
	int v11;       // ebx
	char* v12;     // eax
	int v13;       // eax
	int v14;       // ebx
	FILE* v15;     // [esp+10h] [ebp-108h]
	char v16[128]; // [esp+18h] [ebp-100h]
	char v17[128]; // [esp+98h] [ebp-80h]

	v0 = 1;
	memset(getMemAt(0x5D4594, 1548428), 0, 0x18u);
	strcpy((char*)getMemAt(0x5D4594, 1524108), nox_fs_root());
	strcat((char*)getMemAt(0x5D4594, 1524108), "\\mapcycle.txt");
	result = nox_fs_open_text((const char*)getMemAt(0x5D4594, 1524108));
	v7 = result;
	v15 = result;
	if (result) {
		if (nox_fs_fgets(result, v16, 127)) {
			sub_4D0CC0(v16);
			v8 = sub_4D0C80(v16);
			if (v8 < 0) {
				v9 = *getMemU32Ptr(0x5D4594, 1548432);
				strcpy((char*)getMemAt(0x5D4594, 1532428 + 128 * *getMemU32Ptr(0x5D4594, 1548432)), v16);
				*getMemU32Ptr(0x5D4594, 1548432) = v9 + 1;
			} else {
				v0 = v8;
			}
		}
		while (!nox_fs_feof(v7)) {
			if (nox_fs_fgets(v7, v16, 127)) {
				sub_4D0CC0(v16);
				v10 = sub_4D0C80(v16);
				if (v10 < 0) {
					if (*getMemIntPtr(0x5D4594, 1548428 + 4 * v0) < 25 && v16[0]) {
						v11 = sub_4D0C70(v0);
						strcpy(v17, v16);
						v12 = strtok(v17, ".\n");
						if (nox_common_checkMapFile_4CFE10(v12)) {
							v13 = nox_xxx_mapGetTypeMB_4CFFA0((int)getMemAt(0x973F18, 2408));
							if (v13 & v11) {
								v14 = *getMemU32Ptr(0x5D4594, 1548428 + 4 * v0);
								strcpy((char*)getMemAt(0x5D4594, 1529228 + 128 * (v14 + 20 * v0 + 5 * v0)), v16);
								*getMemU32Ptr(0x5D4594, 1548428 + 4 * v0) = v14 + 1;
							}
						}
						v7 = v15;
					}
				} else {
					v0 = v10;
				}
			}
		}
		nox_fs_close(v7);
		result = 0;
	} else {
		*getMemU32Ptr(0x5D4594, 1548484) = 0;
	}
	return result;
}
// 4D0BF1: variable 'v13' is possibly undefined

//----- (004D0C70) --------------------------------------------------------
int sub_4D0C70(int a1) { return *getMemU32Ptr(0x587000, 191836 + 8 * a1); }

//----- (004D0C80) --------------------------------------------------------
int sub_4D0C80(char* a1) {
	int v1;          // edi
	const char** v2; // esi

	v1 = 0;
	v2 = (const char**)getMemAt(0x587000, 191832);
	while (_strcmpi(*v2, a1)) {
		v2 += 2;
		++v1;
		if ((int)v2 >= (int)getMemAt(0x587000, 191880)) {
			return -1;
		}
	}
	return v1;
}

//----- (004D0CC0) --------------------------------------------------------
void sub_4D0CC0(char* a1) {
	char* v1; // eax
	char* v2; // eax

	if (a1) {
		v1 = strchr(a1, 13);
		if (v1) {
			*v1 = 0;
		}
		v2 = strchr(a1, 10);
		if (v2) {
			*v2 = 0;
		}
	}
}

//----- (004D0D50) --------------------------------------------------------
int sub_4D0D50(int a1) {
	int result;        // eax
	unsigned char* v2; // ecx

	result = 0;
	v2 = getMemAt(0x587000, 191836);
	while (!(a1 & *(uint32_t*)v2)) {
		v2 += 8;
		++result;
		if ((int)v2 >= (int)getMemAt(0x587000, 191884)) {
			return 0;
		}
	}
	return result;
}

//----- (004D0D70) --------------------------------------------------------
int sub_4D0D70() {
	return *getMemU32Ptr(0x5D4594, 1548484) || nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING);
}

//----- (004D0D90) --------------------------------------------------------
int sub_4D0D90(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 1548484) = a1;
	return result;
}

//----- (004D0DA0) --------------------------------------------------------
void sub_4D0DA0() {
	memset(getMemAt(0x5D4594, 1548452), 0, 0x18u);
	memset(getMemAt(0x5D4594, 1548428), 0, 0x18u);
}

//----- (004D0DC0) --------------------------------------------------------
int sub_4D0DC0(int a1, int a2) {
	int result; // eax

	result = sub_4D0D50(a1);
	*getMemU32Ptr(0x5D4594, 1548452 + 4 * result) = a2;
	return result;
}

//----- (004D0DE0) --------------------------------------------------------
int sub_4D0DE0(int a1) { return *getMemU32Ptr(0x5D4594, 1548452 + 4 * sub_4D0D50(a1)); }

//----- (004D0E00) --------------------------------------------------------
int nox_xxx_mapSelectFirst_4D0E00() {
	int* i;             // ebp
	int v3;             // edx
	unsigned char v4;   // al
	unsigned char* v5;  // edi
	int v6;             // eax
	int result;         // eax
	int v8;             // ecx
	int v9;             // ebp
	unsigned char* v10; // ebx
	int v11;            // edi
	int v12;            // esi
	int v13;            // [esp+10h] [ebp-4h]

	nox_platform_srand_time();
	dword_5d4594_1548476 = 0;
	for (i = nox_common_maplist_first_4D09B0(); i; i = nox_common_maplist_next_4D09C0(i)) {
		if (i[6]) {
			if (sub_4CFFC0((int)i) & 0x1000) {
				if (*(int*)&dword_5d4594_1548476 < 128) {
					v3 = 32 * dword_5d4594_1548476;
					strcpy((char*)getMemAt(0x5D4594, 1525136 + 32 * dword_5d4594_1548476), (const char*)i + 12);
					v4 = getMemByte(0x587000, 192004);
					v5 = getMemAt(0x5D4594, 1525136 + v3 + strlen((const char*)getMemAt(0x5D4594, 1525136 + v3)));
					*(uint32_t*)v5 = *getMemU32Ptr(0x587000, 192000);
					v5[4] = v4;
					v6 = dword_5d4594_1548476 + 1;
					*getMemU32Ptr(0x5D4594, 1525132 + v3) = 0;
					dword_5d4594_1548476 = v6;
				}
			}
		}
	}
	result = dword_5d4594_1548476;
	v8 = 1;
	if (dword_5d4594_1548476 > 0) {
		v9 = 1;
		v10 = getMemAt(0x5D4594, 1525132);
		do {
			if (!*(uint32_t*)v10) {
				*(uint32_t*)v10 = v8++;
				v13 = v8;
				v11 = v9;
				if (v9 < result) {
					v12 = (int)(v10 + 32);
					do {
						if (!_strnicmp((const char*)v10 + 4, (const char*)(v12 + 4), 6u)) {
							*(uint32_t*)v12 = *(uint32_t*)v10;
						}
						result = dword_5d4594_1548476;
						++v11;
						v12 += 32;
					} while (v11 < *(int*)&dword_5d4594_1548476);
					v8 = v13;
				}
			}
			++v9;
			v10 += 32;
		} while (v9 - 1 < result);
	}
	return result;
}
// 4D0E3E: variable 'v2' is possibly undefined

//----- (004D0F30) --------------------------------------------------------
void sub_4D0F30() {
	int v0;            // ecx
	unsigned char* v1; // eax

	v0 = dword_5d4594_1548476;
	dword_5d4594_1548480 = 1000;
	if (dword_5d4594_1548476 > 0) {
		v1 = getMemAt(0x5D4594, 1525160);
		do {
			*((uint32_t*)v1 - 1) = 0;
			*(uint32_t*)v1 = 0;
			v1 += 32;
			--v0;
		} while (v0);
	}
}

//----- (004D0F60) --------------------------------------------------------
char* nox_xxx_getQuestMapFile_4D0F60() // quest setup 2
{
	int v1;             // esi
	unsigned char* v2;  // ecx
	int v3;             // edx
	int v4;             // ebx
	unsigned char* v5;  // esi
	int v6;             // ebp
	unsigned char* v7;  // eax
	int v8;             // ecx
	int v9;             // edx
	int v10;            // ecx
	unsigned char* v11; // eax
	int v12;            // eax
	int v13;            // edi
	int v14;            // edx
	unsigned char* i;   // ecx
	int v16;            // [esp+4h] [ebp-8h]

	if (!dword_5d4594_1548476) {
		return 0;
	}
	if (dword_5d4594_1548476 == 1) {
		return (char*)getMemAt(0x5D4594, 1525136);
	}
	v1 = 0;
	v16 = 0;
	if (*(int*)&dword_5d4594_1548476 <= 0) {
		return (char*)getMemAt(0x5D4594, 1525136 + 32 * nox_common_randomInt_415FA0(0, dword_5d4594_1548476 - 1));
	}
	v2 = getMemAt(0x5D4594, 1525156);
	v3 = dword_5d4594_1548476;
	do {
		if (*(uint32_t*)v2 > v1) {
			v16 = *(uint32_t*)v2;
			v1 = *(uint32_t*)v2;
		}
		v2 += 32;
		--v3;
	} while (v3);
	if (!v1) {
		return (char*)getMemAt(0x5D4594, 1525136 + 32 * nox_common_randomInt_415FA0(0, dword_5d4594_1548476 - 1));
	}
	v4 = 1;
	v5 = getMemAt(0x5D4594, 1525156);
	v6 = dword_5d4594_1548476;
	do {
		if (dword_5d4594_1548476 > 1) {
			v7 = getMemAt(0x5D4594, 1525188);
			v8 = dword_5d4594_1548476 - 1;
			do {
				if (*(uint32_t*)v5 != *(uint32_t*)v7) {
					v4 = 0;
				}
				v7 += 32;
				--v8;
			} while (v8);
		}
		v5 += 32;
		--v6;
	} while (v6);
	if (v4 == 1) {
		++v16;
	}
	v9 = 0;
	v10 = 0;
	v11 = getMemAt(0x5D4594, 1525132);
	do {
		if (*((uint32_t*)v11 + 6) < v16 && v10 != *getMemU32Ptr(0x587000, 191880) &&
			*(uint32_t*)v11 != *getMemU32Ptr(0x5D4594, 1525132 + 32 * *getMemU32Ptr(0x587000, 191880)) &&
			dword_5d4594_1548480 - *((uint32_t*)v11 + 7) > 4) {
			++v9;
		}
		++v10;
		v11 += 32;
	} while (v10 < *(int*)&dword_5d4594_1548476);
	v12 = nox_common_randomInt_415FA0(0, v9 - 1);
	v13 = 0;
	v14 = 0;
	if (*(int*)&dword_5d4594_1548476 <= 0) {
		return (char*)getMemAt(0x5D4594, 1525136 + 32 * v12);
	}
	for (i = getMemAt(0x5D4594, 1525132);; i += 32) {
		if (*((uint32_t*)i + 6) >= v16 || v14 == *getMemU32Ptr(0x587000, 191880) ||
			*(uint32_t*)i == *getMemU32Ptr(0x5D4594, 1525132 + 32 * *getMemU32Ptr(0x587000, 191880)) ||
			dword_5d4594_1548480 - *((uint32_t*)i + 7) <= 4) {
			goto LABEL_36;
		}
		if (v13 == v12) {
			break;
		}
		++v13;
	LABEL_36:
		if (++v14 >= *(int*)&dword_5d4594_1548476) {
			return (char*)getMemAt(0x5D4594, 1525136 + 32 * v12);
		}
	}
	return (char*)getMemAt(0x5D4594, 1525136 + 32 * v14);
}

//----- (004D11A0) --------------------------------------------------------
void sub_4D11A0() {
	if (!*getMemU32Ptr(0x5D4594, 1548504)) {
		nox_common_list_clear_425760(getMemAt(0x5D4594, 1548492));
		*getMemU32Ptr(0x5D4594, 1548504) = 1;
	}
}

//----- (004D11D0) --------------------------------------------------------
void sub_4D11D0() {
	int* result; // eax
	int* v1;     // esi
	int* v2;     // edi

	result = nox_common_list_getFirstSafe_425890(getMemIntPtr(0x5D4594, 1548492));
	v1 = result;
	if (result) {
		do {
			v2 = nox_common_list_getNextSafe_4258A0(v1);
			sub_425920((uint32_t**)v1);
			free(v1);
			v1 = v2;
		} while (v2);
	}
}

//----- (004D1210) --------------------------------------------------------
void sub_4D1210(int a1) {
	void* result; // eax
	void* v2;     // esi
	uint32_t* v3; // eax

	result = (void*)sub_4D12A0(a1);
	if (!result) {
		result = nox_common_playerInfoFromNum_417090(a1);
		v2 = result;
		if (result) {
			v3 = calloc(1, 0x10u);
			v3[3] = v2;
			nox_common_list_append_4258E0((int)getMemAt(0x5D4594, 1548492), v3);
		}
	}
}

//----- (004D1250) --------------------------------------------------------
int* sub_4D1250(int a1) {
	int* result; // eax
	int* v2;     // esi

	result = nox_common_list_getFirstSafe_425890(getMemIntPtr(0x5D4594, 1548492));
	v2 = result;
	if (result) {
		while (*(unsigned char*)(v2[3] + 2064) != a1) {
			result = nox_common_list_getNextSafe_4258A0(v2);
			v2 = result;
			if (!result) {
				return result;
			}
		}
		sub_425920((uint32_t**)v2);
		free(v2);
	}
	return result;
}

//----- (004D12A0) --------------------------------------------------------
int sub_4D12A0(int a1) {
	int* v1; // eax

	v1 = nox_common_list_getFirstSafe_425890(getMemIntPtr(0x5D4594, 1548492));
	if (!v1) {
		return 0;
	}
	while (*(unsigned char*)(v1[3] + 2064) != a1) {
		v1 = nox_common_list_getNextSafe_4258A0(v1);
		if (!v1) {
			return 0;
		}
	}
	return 1;
}

//----- (004D12E0) --------------------------------------------------------
void nox_xxx_mapSwitchLevel_4D12E0(int a1) {
	int v1;       // edi
	int v2;       // esi
	int v3;       // edi
	uint32_t* v4; // eax
	int v5;       // esi
	uint32_t* v6; // eax
	int v11[3];   // [esp+0h] [ebp-Ch]

	v11[0] = 25;
	v11[1] = 25;
	v11[2] = 25;
	nox_xxx_setGameFlags_40A4D0(0x80000);
	sub_516F30();
	sub_421B10();
	sub_469B90(v11);
	if (nox_common_gameFlags_check_40A5C0(2)) {
		sub_4349C0(v11);
	}
	sub_511E60();
	if (nox_common_gameFlags_check_40A5C0(2048)) {
		v1 = a1;
		sub_4FCEB0(a1);
	} else {
		sub_4FCEB0(0);
		v1 = a1;
	}
	nox_xxx_mapWall_4FF790();
	v2 = nox_xxx_getFirstPlayerUnit_4DA7C0();
	if (v2) {
		do {
			v3 = *(uint32_t*)(v2 + 748);
			sub_4F7950(v2);
			*(uint32_t*)(v3 + 296) = 0;
			nox_xxx_unitUnFreeze_4E7A60(v2, 1);
			v4 = *(uint32_t**)(v3 + 280);
			*(uint16_t*)(v3 + 160) = 0;
			if (v4) {
				nox_xxx_shopCancelSession_510DC0(v4);
			}
			*(uint32_t*)(v3 + 280) = 0;
			if (*(int (**)(uint32_t*))(v2 + 744) == nox_xxx_updatePlayerMonsterBot_4FAB20) {
				nox_xxx_playerBotCreate_4FA700(v2);
			}
			v2 = nox_xxx_getNextPlayerUnit_4DA7F0(v2);
		} while (v2);
		v1 = a1;
	}
	do {
		nox_xxx_unitsNewAddToList_4DAC00();
		sub_4E5BF0(v1);
		nox_xxx_spellCastByPlayer_4FEEF0();
		nox_xxx_finalizeDeletingUnits_4E5EC0();
	} while (nox_server_getFirstObjectUninited_4DA870());
	v5 = nox_server_getFirstObject_4DA790();
	if (v5) {
		do {
			*(uint32_t*)(v5 + 520) = 0;
			if (nox_xxx_isUnit_4E5B50(v5) && *(uint8_t*)(v5 + 8) & 2) {
				v6 = *(uint32_t**)(v5 + 748);
				v6[309] = -1;
				v6[307] = -1;
				v6[317] = -1;
				v6[311] = -1;
				v6[313] = -1;
				v6[315] = -1;
				v6[319] = -1;
				v6[321] = -1;
				v6[323] = -1;
				v6[325] = -1;
				v6[98] = 0;
				v6[101] = 0;
			}
			v5 = nox_server_getNextObject_4DA7A0(v5);
		} while (v5);
		v1 = a1;
	}
	sub_50D1C0();
	for (nox_object_t* obj = nox_xxx_getFirstUpdatable2Object_4DA840(); obj;
		 obj = nox_xxx_getNextUpdatable2Object_4DA850(obj)) {
		if (sub_4E5B80(obj)) {
			sub_4E81D0(obj);
		}
	}
	sub_4ECFE0();
	sub_511E20();
	nox_xxx_wall_410160();
	if (v1) {
		nox_xxx_Fn_4FCAC0(v1, 1);
	} else {
		nox_xxx_Fn_4FCAC0(0, 0);
	}
	for (int j = 0; j < ptr_5D4594_2650668_cap * 44; j += 44) {
		for (int k = 0; k < ptr_5D4594_2650668_cap; k++) {
			*(uint8_t*)((uint32_t)(ptr_5D4594_2650668[k]) + j) = 0;
			*(uint32_t*)((uint32_t)(ptr_5D4594_2650668[k]) + j + 4) = 255;
			*(uint32_t*)((uint32_t)(ptr_5D4594_2650668[k]) + j + 24) = 255;
			nox_xxx_tileFreeTile_422200((uint32_t)(ptr_5D4594_2650668[k]) + j + 4);
			nox_xxx_tileFreeTile_422200((uint32_t)(ptr_5D4594_2650668[k]) + j + 24);
		}
	}
	sub_410730();
	nox_xxx_wallBreackableListClear_410810();
	nox_xxx_waypointDeleteAll_579DD0();
	nox_xxx_j_allocHitArray_511840();
	nox_xxx_decayDestroy_5117B0();
	sub_5112F0();
	sub_57C440();
	sub_57C000();
	sub_510E50();
	sub_4D1610();
	sub_4EC5B0();
	sub_50E360();
	sub_50D7E0();
	sub_4E4F80();
	nox_common_gameFlags_unset_40A540(0x80000);
}
// 511840: using guessed type int nox_xxx_j_allocHitArray_511840(void);

//----- (004D15B0) --------------------------------------------------------
void nox_xxx____setargv_13_4D15B0() { *getMemU32Ptr(0x5D4594, 1548508) = 1; }

//----- (004D15C0) --------------------------------------------------------
void sub_4D15C0() { *getMemU32Ptr(0x5D4594, 1548508) = 0; }

//----- (004D15D0) --------------------------------------------------------
int sub_4D15D0() { return *getMemU32Ptr(0x5D4594, 1548508); }

//----- (004D1600) --------------------------------------------------------
int nox_xxx_scavengerTreasureMax_4D1600() { return *getMemU32Ptr(0x5D4594, 1548528); }

//----- (004D1610) --------------------------------------------------------
void sub_4D1610() { *getMemU32Ptr(0x5D4594, 1548528) = 0; }

//----- (004D1620) --------------------------------------------------------
int sub_4D1620() {
	int result; // eax

	if (dword_5d4594_1548532) {
		result = (uint32_t)dword_5d4594_1548532 + 56;
	} else {
		result = 0;
	}
	return result;
}

//----- (004D1630) --------------------------------------------------------
int nox_xxx_parseGamedataBinPre_4D1630() {
	int result; // eax

	result = nox_xxx_parseGamedataBin_419B30();
	if (result) {
		nox_xxx_loadWariorParams_424DF0();
		nox_xxx_loadBaseValues_57B200();
		result = nox_xxx_loadMonsterBin_517010() != 0;
	}
	return result;
}

//----- (004D1650) --------------------------------------------------------
// Microsoft VisualC 2-14/net runtime
void nox_xxx_unknown_libname_11_4D1650() {
	nox_xxx_gamedataFree_419DB0();
	nox_xxx_monsterListFree_5174F0();
}

//----- (004D1660) --------------------------------------------------------
#ifndef NOX_CGO
int nox_xxx_servNewSession_4D1660() {
	sub_4D15C0();
	dword_5d4594_2649712 = 2147483648;
	nox_xxx_host_player_unit_3843628 = 0;
	sub_4D7B40();
	sub_41E4B0(0);
	nox_server_ResetObjectGIDs_4E3C70();
	sub_56F1C0();
	nox_xxx_cliResetAllPlayers_416E30();
	nox_netlist_resetAll_40EE60();
	sub_4E4EF0();
	sub_4E4ED0();
	if (!nox_xxx_allocAudEventArray_501860()) {
		return 0;
	}
	if (!nox_read_things_alternative_4E2B60()) {
		return 0;
	}
	nox_motd_4463E0(1);
	sub_417C60();
	sub_4259C0();
	sub_4D7C60();
	nox_xxx_unitDefFindMaxDataSize_4E3320();
	if (!sub_518770()) {
		return 0;
	}
	nox_common_gameFlags_check_40A5C0(0x200000);
	if (!nox_xxx_allocClassArrayObjects_4E3360(0x1388u)) {
		return 0;
	}
	if (!sub_517AE0()) {
		return 0;
	}
	if (!nox_xxx_allocVisitNodesArray_50AB90()) {
		return 0;
	}
	if (!nox_xxx_allocSpellRelatedArrays_4FC9B0()) {
		return 0;
	}
	if (!nox_xxx_allocSpringsArray_5112C0()) {
		return 0;
	}
	if (!nox_xxx_allocDebugDataArray_57C410()) {
		return 0;
	}
	if (!nox_xxx_allocGroupRelatedArrays_57BFB0()) {
		return 0;
	}
	if (!nox_xxx_allocItemRespawnArray_4ECA60()) {
		return 0;
	}
	if (!nox_xxx_registerShopClasses_50E2A0()) {
		return 0;
	}
	if (!nox_xxx_allocMonsterRelatedArrays_50D780()) {
		return 0;
	}
	if (!nox_xxx_allocVoteArray_5066D0()) {
		return 0;
	}
	if (!nox_xxx_allocMagicWallArray_4FF730()) {
		return 0;
	}
	if (!nox_xxx_monsterList_517520()) {
		return 0;
	}
	sub_416920();
	if (!nox_common_gameFlags_check_40A5C0(2048)) {
		int v1 = nox_xxx_servGetPort_40A430();
		*getMemU32Ptr(0x5D4594, 1548516) = nox_xxx_netAddPlayerHandler_4DEBC0(v1);
		if (!nox_common_gameFlags_check_40A5C0(0x2000000)) {
			nox_xxx_networkLog_init_413CC0();
		}
	}
	nox_xxx_allocArrayExecAbilities_4FB990();
	if (!nox_xxx_allocPendingOwnsArray_516EE0()) {
		return 0;
	}
	sub_421B10();
	sub_4DB0A0();
	sub_4D0F30();
	return 1;
}

//----- (004D17F0) --------------------------------------------------------
int nox_xxx_servInitialMapLoad_4D17F0() {
	sub_4E79B0(0);
	if (!memcmp(nox_server_currentMapGetFilename_409B30(), getMemAt(0x5D4594, 1548720), 1u)) {
		nox_xxx_gameSetMapPath_409D70("tutorial.map");
	}
	nox_xxx_netMapSendStop_519870();
	if (!nox_xxx_mapExitAndCheckNext_4D1860_server()) {
		return 0;
	}
	nox_xxx_setGameState_43DDF0(nox_xxx_gameTick_4D2580_server);
	nox_netlist_resetAllInList_40EE90(1);
	nox_xxx_setGameFlags_40A4D0(0x20000);
	nox_xxx_netGameSettings_4DEF00();
	nox_server_gameUnsetMapLoad_40A690();
	return 1;
}
#endif // NOX_CGO

//----- (004D23C0) --------------------------------------------------------
int nox_xxx_servResetPlayers_4D23C0() {
	char* i; // esi
	int v2;  // [esp-Ch] [ebp-14h]

	for (i = nox_common_playerInfoGetFirst_416EA0(); i; i = nox_common_playerInfoGetNext_416EE0((int)i)) {
		if (*((uint32_t*)i + 514)) {
			dword_5d4594_2649712 &= ~(1 << i[2064]);
			v2 = *((uint32_t*)i + 514);
			i[3676] = 2;
			nox_xxx_playerMakeDefItems_4EF7D0(v2, 1, 0);
			*((uint32_t*)i + 535) = 0;
			*((uint32_t*)i + 534) = 0;
		}
	}
	sub_51A100();
	nox_common_gameFlags_unset_40A540(0x20000);
	nox_xxx_netGameSettings_4DEF00();
	nox_server_gameUnsetMapLoad_40A690();
	return 1;
}

//----- (004D2450) --------------------------------------------------------
char* nox_xxx_mapLoad_4D2450(char* a1) {
	char* v1;      // eax
	char v3[1024]; // [esp+4h] [ebp-DB8h]
	char v4[1024]; // [esp+404h] [ebp-9B8h]
	char v5[1464]; // [esp+804h] [ebp-5B8h]

	memcpy(v5, getMemAt(0x973F18, 2408), sizeof(v5));
	strncpy(v4, a1, (strlen(a1) - 4 < 1024 ? strlen(a1) - 4 : 1024));
	v4[strlen(a1) - 4] = 0;
	nox_common_checkMapFile_4CFE10(v4);
	sub_4CFDF0(*getMemIntPtr(0x973F18, 3800));
	memcpy(getMemAt(0x973F18, 2408), v5, 0x5B8u);
	dword_5d4594_1548524 = 1;
	strcpy(v3, a1);
	v1 = strchr(v3, 58);
	if (v1) {
		*v1 = 0;
		strcpy((char*)getMemAt(0x5D4594, 1548536), v1 + 1);
		dword_5d4594_1548664 = 1;
	} else {
		dword_5d4594_1548664 = 0;
	}
	if (sub_51A130()) {
		nox_xxx_mapSendCancelAll_5198B0(0);
	}
	return nox_xxx_gameSetMapPath_409D70(v3);
}

//----- (004D2FF0) --------------------------------------------------------
char* sub_4D2FF0() {
	char* result; // eax
	int v1;       // esi

	result = (char*)sub_40AA70(0);
	if (result || (result = nox_common_playerInfoGetFirst_416EA0(), (v1 = (int)result) == 0)) {
		dword_5d4594_1548704 = 1;
	} else {
		do {
			if (*(uint8_t*)(v1 + 3680) & 1) {
				nox_xxx_netNeedTimestampStatus_4174F0(v1, 256);
			}
			result = nox_common_playerInfoGetNext_416EE0(v1);
			v1 = (int)result;
		} while (result);
		dword_5d4594_1548704 = 1;
	}
	return result;
}

//----- (004D3050) --------------------------------------------------------
char* nox_xxx_netReportAllLatency_4D3050() {
	char* result; // eax
	bool v1;      // zf
	int i;        // esi
	char v3[5];   // [esp+0h] [ebp-8h]

	v3[0] = -41;
	if (!dword_5d4594_1548700 || (result = nox_common_playerInfoGetNext_416EE0(*(int*)&dword_5d4594_1548700),
								  (dword_5d4594_1548700 = result) == 0)) {
		result = nox_common_playerInfoGetFirst_416EA0();
		dword_5d4594_1548700 = result;
	}
	if (result) {
		for (int k = 0; result[2064] != 31 && k < 32; k++) {
			v1 = sub_554240((unsigned char)result[2064]) == 0;
			result = *(char**)&dword_5d4594_1548700;
			if (!v1) {
				break;
			}
			result = nox_common_playerInfoGetNext_416EE0(*(int*)&dword_5d4594_1548700);
			dword_5d4594_1548700 = result;
			if (!result) {
				result = nox_common_playerInfoGetFirst_416EA0();
				dword_5d4594_1548700 = result;
			}
		}
		if (result) {
			*(uint16_t*)&v3[1] = *((uint16_t*)result + 1030);
			*(uint16_t*)&v3[3] = sub_554240((unsigned char)result[2064]);
			result = nox_common_playerInfoGetFirst_416EA0();
			for (i = (int)result; result; i = (int)result) {
				nox_netlist_addToMsgListCli_40EBC0(*(unsigned char*)(i + 2064), 1, v3, 5);
				result = nox_common_playerInfoGetNext_416EE0(i);
			}
		}
	}
	return result;
}

//----- (004D3200) --------------------------------------------------------
#ifndef NOX_CGO
int nox_xxx_servEndSession_4D3200() {
	char* v0;            // eax
	char FileName[1024]; // [esp+0h] [ebp-400h]

	sub_50D1E0();
	sub_4DB100();
	sub_421B10();
	sub_516F10();
	sub_4FF770();
	nox_xxx_replayStopSave_4D33B0();
	nox_xxx_replayStopReadMB_4D3530();
	nox_xxx_cliResetAllPlayers_416E30();
	sub_446490(1);
	sub_4259F0();
	nox_xxx_mapSwitchLevel_4D12E0(0);
	nox_xxx_mapLoad_40A380();
	sub_4E4DE0();
	sub_57C460();
	sub_57C030();
	sub_511310();
	nox_xxx_freeSpellRelated_4FCA80();
	sub_50ABF0();
	sub_517B30();
	sub_5018D0();
	sub_4ECA90();
	sub_506720();
	sub_50D820();
	nox_xxx_deleteShopInventories_50E300();
	sub_416950();
	nox_xxx_freeGameObjectClass_4E3420();
	nox_xxx_freeObjectTypes_4E2A20();
	if (!nox_common_gameFlags_check_40A5C0(2048)) {
		nox_server_netCloseHandler_4DEC60(*getMemUintPtr(0x5D4594, 1548516));
		if (!nox_common_gameFlags_check_40A5C0(0x2000000)) {
			nox_xxx_networkLog_close_413D00();
		}
	}
	sub_56F3B0();
	nullsub_23();
	nox_netlist_resetAll_40EE60();
	v0 = nox_fs_root();
	nox_sprintf(FileName, "%s\\Save\\_temp_.dat", v0);
	return nox_fs_remove(FileName);
}
#endif // NOX_CGO
// 4E3440: using guessed type void nullsub_23(void);

//----- (004D3310) --------------------------------------------------------
int sub_4D3310(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 1548716) = a1;
	return result;
}

//----- (004D3320) --------------------------------------------------------
int sub_4D3320() { return *getMemU32Ptr(0x5D4594, 1548716); }

//----- (004D3330) --------------------------------------------------------
void nox_xxx_unused_4D3330() {
	if (nox_common_gameFlags_check_40A5C0(0x2000000)) {
		nox_xxx_networkLog_printf_413D30("Failed to create channel, exiting game.");
		nox_xxx_setContinueMenuOrHost_43DDD0(0);
		nox_game_exit_xxx_43DE60();
	}
}

//----- (004D39F0) --------------------------------------------------------
int sub_4D39F0(const char* a3) {
	unsigned int v1;    // ecx
	char v2;            // dl
	unsigned char* v3;  // edi
	const char* v4;     // esi
	int v5;             // edx
	int v6;             // eax
	unsigned char* v7;  // edi
	unsigned int v8;    // ecx
	unsigned char* v9;  // edi
	const char* v10;    // esi
	unsigned char* v11; // edi
	int v12;            // ecx
	int v13;            // edx
	int v14;            // eax
	char* v15;          // edi
	unsigned char v16;  // cl
	int result;         // eax
	char v18[2048];     // [esp+10h] [ebp-800h]

	*getMemU64Ptr(0x5D4594, 1549772) = nox_platform_get_ticks();
	memset(getMemAt(0x973F18, 35912), 0, 0x48u);
	*getMemU32Ptr(0x973F18, 35912) = 0;
	*getMemU32Ptr(0x973F18, 35916) = 0;
	dword_5d4594_3835348 = 0;
	dword_5d4594_3835356 = 255;
	dword_5d4594_3835352 = 0;
	dword_5d4594_3835360 = 0;
	dword_5d4594_3835364 = 1;
	dword_5d4594_3835368 = 1;
	dword_5d4594_3835372 = 1;
	*getMemU32Ptr(0x973F18, 35948) = 0;
	*getMemU32Ptr(0x973F18, 35952) = 0;
	*getMemU32Ptr(0x973F18, 35956) = 0;
	dword_5d4594_3835388 = 0;
	dword_5d4594_3835392 = 1;
	dword_5d4594_3835396 = -1;
	*getMemU8Ptr(0x973F18, 35972) = 2;
	*getMemU32Ptr(0x973F18, 35976) = 0;
	*getMemU32Ptr(0x973F18, 35980) = 0;
	sub_51D0E0();
	if (a3) {
		v1 = strlen(a3) + 1;
		v2 = v1;
		v1 >>= 2;
		memcpy(getMemAt(0x973F18, 42152), a3, 4 * v1);
		v4 = &a3[4 * v1];
		v3 = getMemAt(0x973F18, 42152 + 4 * v1);
		LOBYTE(v1) = v2;
		v5 = *getMemU32Ptr(0x587000, 197560);
		memcpy(v3, v4, v1 & 3);
		strcpy((char*)getMemAt(0x973F18, 36008), a3);
		v6 = *getMemU32Ptr(0x587000, 197564);
		v7 = getMemAt(0x973F18, 36008 + strlen((const char*)getMemAt(0x973F18, 36008)));
		*(uint32_t*)v7 = *getMemU32Ptr(0x587000, 197556);
		*((uint32_t*)v7 + 1) = v5;
		*((uint32_t*)v7 + 2) = v6;
		v8 = strlen(a3) + 1;
		LOBYTE(v5) = v8;
		v8 >>= 2;
		memcpy(getMemAt(0x973F18, 38056), a3, 4 * v8);
		v10 = &a3[4 * v8];
		v9 = getMemAt(0x973F18, 38056 + 4 * v8);
		LOBYTE(v8) = v5;
		LOWORD(v5) = *getMemU16Ptr(0x587000, 197576);
		memcpy(v9, v10, v8 & 3);
		v11 = getMemAt(0x973F18, 38057 + strlen((const char*)getMemAt(0x973F18, 38056)));
		v12 = *getMemU32Ptr(0x587000, 197572);
		*(uint32_t*)--v11 = *getMemU32Ptr(0x587000, 197568);
		LOBYTE(v6) = getMemByte(0x587000, 197578);
		*((uint32_t*)v11 + 1) = v12;
		*((uint16_t*)v11 + 4) = v5;
		v11[10] = v6;
		nox_fs_remove((const char*)getMemAt(0x973F18, 36008));
		nox_fs_remove((const char*)getMemAt(0x973F18, 38056));
	} else {
		*getMemU8Ptr(0x973F18, 42152) = getMemByte(0x5D4594, 1549780);
		*getMemU8Ptr(0x973F18, 40104) = getMemByte(0x5D4594, 1549784);
		*getMemU8Ptr(0x973F18, 36008) = getMemByte(0x5D4594, 1549788);
		*getMemU8Ptr(0x973F18, 38056) = getMemByte(0x5D4594, 1549792);
	}
	nox_xxx_mapReset_5028E0();
	v13 = *getMemU32Ptr(0x587000, 197584);
	strcpy(v18, a3);
	v14 = *getMemU32Ptr(0x587000, 197588);
	v15 = &v18[strlen(v18)];
	*(uint32_t*)v15 = *getMemU32Ptr(0x587000, 197580);
	v16 = getMemByte(0x587000, 197592);
	*((uint32_t*)v15 + 1) = v13;
	*((uint32_t*)v15 + 2) = v14;
	v15[12] = v16;
	sub_502A50(v18);
	sub_502AB0(v18);
	result = sub_502B10();
	dword_5d4594_3835312 = 0;
	*getMemU32Ptr(0x973F18, 35880) = 0;
	*getMemU32Ptr(0x5D4594, 1599580) = 0;
	return result;
}
// 4D39F0: using guessed type char var_800[2048];

//----- (004D3C30) --------------------------------------------------------
long long sub_4D3C30() {
	nox_xxx_free_503F40();
	sub_51D0E0();
	sub_502DF0();
	return nox_platform_get_ticks();
}

//----- (004D3C50) --------------------------------------------------------
void nox_xxx_tileInitdataClear_4D3C50(const void* a1) { memcpy(getMemAt(0x973F18, 35912), a1, 0x48u); }

//----- (004D3C70) --------------------------------------------------------
unsigned char* sub_4D3C70() { return getMemAt(0x973F18, 35912); }

//----- (004D3C80) --------------------------------------------------------
uint32_t* sub_4D3C80(uint32_t* a1) {
	uint32_t* result; // eax
	int v2;           // ebp
	int v3;           // ecx
	int v4;           // edi
	int v5;           // esi
	int v6;           // edx
	int v7;           // ebx
	int v8;           // ecx
	int v9;           // esi
	int v10;          // [esp+10h] [ebp-10h]
	int v11;          // [esp+14h] [ebp-Ch]
	int v12;          // [esp+1Ch] [ebp-4h]

	result = a1;
	v2 = a1[3];
	v10 = *a1;
	v3 = a1[1];
	v11 = a1[1];
	if (v2 < v3) {
		v3 = a1[3];
		v10 = a1[2];
		v11 = a1[3];
	}
	if (a1[5] < v3) {
		v10 = a1[4];
		v3 = a1[5];
		v11 = a1[5];
	}
	if (a1[7] < v3) {
		v10 = a1[6];
		v11 = a1[7];
	}
	v4 = a1[2];
	v12 = a1[3];
	if (*a1 < v4) {
		v4 = *a1;
		v12 = a1[1];
	}
	if (a1[4] < v4) {
		v4 = a1[4];
		v12 = a1[5];
	}
	v5 = a1[6];
	if (v5 < v4) {
		v4 = a1[6];
		v12 = a1[7];
	}
	v6 = a1[4];
	v7 = a1[5];
	if (*a1 > v6) {
		v6 = *a1;
		v7 = a1[1];
	}
	if (a1[2] > v6) {
		v7 = a1[3];
		v6 = a1[2];
	}
	if (v5 > v6) {
		v6 = a1[6];
		v7 = a1[7];
	}
	v8 = a1[7];
	v9 = a1[6];
	if (a1[1] > v8) {
		v9 = *a1;
		v8 = a1[1];
	}
	if (v2 > v8) {
		v9 = a1[2];
		v8 = a1[3];
	}
	if (a1[5] > v8) {
		v9 = a1[4];
		v8 = a1[5];
	}
	a1[6] = v9;
	*a1 = v10;
	a1[2] = v4;
	a1[7] = v8;
	a1[1] = v11;
	a1[4] = v6;
	a1[5] = v7;
	a1[3] = v12;
	return result;
}

//----- (004D3D90) --------------------------------------------------------
int nox_xxx_mapGenFixCoords_4D3D90(float2* a1, float2* a2) {
	if (!a1 || !a2) {
		return 0;
	}
	a2->field_0 = (a1->field_4 + a1->field_0) * 0.70710677 + 2957.0;
	a2->field_4 = (a1->field_4 - a1->field_0) * 0.70710677 + 2956.0;
	if (a2->field_0 <= 80.5) {
		a2->field_0 = 82.5;
	}
	if (a2->field_4 <= 80.5) {
		a2->field_4 = 81.5;
	}
	if (a2->field_0 >= 5853.5) {
		a2->field_0 = 5851.5;
	}
	if (a2->field_4 >= 5853.5) {
		a2->field_4 = 5852.5;
	}
	return 1;
}

//----- (004D3E30) --------------------------------------------------------
int sub_4D3E30(float2* a1, float2* a2) {
	int result; // eax

	if (!a1 || !a2) {
		return 0;
	}
	if (a1->field_0 <= 80.5) {
		a1->field_0 = 82.5;
	}
	if (a1->field_4 <= 80.5) {
		a1->field_4 = 81.5;
	}
	if (a1->field_0 >= 5853.5) {
		a1->field_0 = 5851.5;
	}
	if (a1->field_4 >= 5853.5) {
		a1->field_4 = 5852.5;
	}
	result = 1;
	a2->field_0 = (a1->field_0 - 1.0 - a1->field_4) * 0.70710677;
	a2->field_4 = (a1->field_4 + a1->field_0 - 5912.0) * 0.70710677;
	return result;
}

//----- (004D3ED0) --------------------------------------------------------
int sub_4D3ED0(float2* a1) {
	int result; // eax
	float v2;   // [esp+0h] [ebp-8h]
	float v3;   // [esp+4h] [ebp-4h]

	result = 0;
	if (a1) {
		v2 = (a1->field_4 + a1->field_0) * 0.70710677 + 2957.0;
		v3 = (a1->field_4 - a1->field_0) * 0.70710677 + 2956.0;
		if (v2 > 80.5 && v3 > 80.5 && v2 < 5853.5 && v3 < 5853.5) {
			result = 1;
		}
	}
	return result;
}

//----- (004D3F60) --------------------------------------------------------
int sub_4D3F60(int a1) {
	if (a1 != 1 && a1) {
		return 0;
	}
	*getMemU32Ptr(0x973F18, 35980) = 1;
	return 1;
}

//----- (004D3F80) --------------------------------------------------------
int sub_4D3F80(int a1) {
	int result; // eax

	switch (a1) {
	case 0:
		result = 1;
		break;
	case 1:
		result = 2;
		break;
	case 2:
		result = 5;
		break;
	case 3:
		result = 0;
		break;
	case 5:
		result = 8;
		break;
	case 6:
		result = 3;
		break;
	case 7:
		result = 6;
		break;
	case 8:
		result = 7;
		break;
	default:
		result = -1;
		break;
	}
	return result;
}

//----- (004D3FF0) --------------------------------------------------------
int sub_4D3FF0(int a1) {
	int result; // eax

	switch (a1) {
	case 0:
		result = 3;
		break;
	case 1:
		result = 0;
		break;
	case 2:
		result = 1;
		break;
	case 3:
		result = 6;
		break;
	case 5:
		result = 2;
		break;
	case 6:
		result = 7;
		break;
	case 7:
		result = 8;
		break;
	case 8:
		result = 5;
		break;
	default:
		result = -1;
		break;
	}
	return result;
}

//----- (004D4060) --------------------------------------------------------
float2* sub_4D4060(float2* a1, float2* a2, int a3) {
	double v3;      // st7
	double v4;      // st6
	int v5;         // esi
	int v6;         // edx
	int v7;         // ecx
	double v8;      // st7
	float2* result; // eax
	double v10;     // st7
	int v11;        // [esp+Ch] [ebp-8h]
	float v12;      // [esp+10h] [ebp-4h]
	float2* v13;    // [esp+18h] [ebp+4h]

	v3 = a1->field_0 + 11.5;
	v4 = a1->field_4 + 11.5;
	v13 = (float2*)(long long)(v3 * 0.021739131);
	v12 = v4;
	v11 = (long long)(v4 * 0.021739131);
	v5 = (int)(long long)v3 % 46;
	v6 = (long long)v12 % 46;
	v7 = 2 * a3;
	if (v5 <= v6) {
		if (v7 - v5 <= v6) {
			result = a2;
			a2->field_0 = (double)(int)v13 * 46.0 + 11.0;
			v10 = (double)v11;
			goto LABEL_8;
		}
		v8 = (double)(int)((unsigned long long)(long long)(v3 * 0.021739131) - 1) * 46.0;
	LABEL_6:
		result = a2;
		a2->field_0 = v8 + 34.0;
		a2->field_4 = (double)v11 * 46.0 + 11.0;
		return result;
	}
	v8 = (double)(int)v13 * 46.0;
	if (v7 - v5 <= v6) {
		goto LABEL_6;
	}
	result = a2;
	a2->field_0 = v8 + 11.0;
	v10 = (double)(int)((unsigned long long)(long long)(v4 * 0.021739131) - 1);
LABEL_8:
	result->field_4 = v10 * 46.0 + 34.0;
	return result;
}

//----- (004D4160) --------------------------------------------------------
void sub_4D4160() {
	int v0;                      // edi
	int v1;                      // esi
	int v2;                      // eax
	int v3;                      // eax
	int v4;                      // eax
	char* v5;                    // eax
	char* v6;                    // eax
	float2 v8;                   // [esp+8h] [ebp-808h]
	char FileName[1024];         // [esp+10h] [ebp-800h]
	char ExistingFileName[1024]; // [esp+410h] [ebp-400h]

	nox_xxx_setGameFlags_40A4D0(0x400000);
	nox_xxx_tileGetDefByName_51D4D0("BrickLight");
	v8.field_4 = 0.0;
	v8.field_0 = 0.0;
	v0 = 20;
	do {
		v1 = 20;
		do {
			sub_51D5E0(&v8);
			--v1;
			v8.field_0 = v8.field_0 + 32.526913;
		} while (v1);
		--v0;
		v8.field_0 = 0.0;
		v8.field_4 = v8.field_4 + 32.526913;
	} while (v0);
	v8.field_4 = 0.0;
	v8.field_0 = 0.0;
	v2 = sub_5029A0("CBD-aTest-C");
	nox_xxx_mapgenSaveMap_503830(v2);
	sub_503B30(&v8);
	v8.field_4 = 65.053825;
	v8.field_0 = 65.053825;
	v3 = sub_5029A0("CBD-aTest-C");
	nox_xxx_mapgenSaveMap_503830(v3);
	sub_503B30(&v8);
	v8.field_4 = 195.16147;
	v8.field_0 = 195.16147;
	v4 = sub_5029A0("CBD-aTest2-C");
	nox_xxx_mapgenSaveMap_503830(v4);
	sub_503B30(&v8);
	v5 = nox_fs_root();
	nox_sprintf(FileName, "%s\\nc.obj", v5);
	v6 = nox_fs_root();
	nox_sprintf(ExistingFileName, "%s\\blend.obj", v6);
	nox_fs_remove(FileName);
	nox_fs_move(ExistingFileName, FileName);
	nox_common_gameFlags_unset_40A540(0x400000);
}

//----- (004D42D0) --------------------------------------------------------
int sub_4D42D0(int a1) {
	int result; // eax

	result = a1;
	dword_5d4594_1550916 = a1;
	return result;
}

//----- (004D42E0) --------------------------------------------------------
unsigned int sub_4D42E0(const char* a1) {
	unsigned int result; // eax

	result = strlen(a1) + 1;
	memcpy(getMemAt(0x587000, 197860), a1, result);
	return result;
}

//----- (004D4310) --------------------------------------------------------
char* nox_xxx_getRandMapName_4D4310() { return (char*)getMemAt(0x587000, 197860); }

//----- (004D4320) --------------------------------------------------------
int nox_xxx_mapGenStart_4D4320() {
	int v0;                      // esi
	int v1;                      // eax
	char* v2;                    // eax
	char* v3;                    // eax
	int result;                  // eax
	int i;                       // eax
	char* v6;                    // eax
	char* v7;                    // eax
	char* v8;                    // [esp-8h] [ebp-C10h]
	char* v9;                    // [esp-4h] [ebp-C0Ch]
	char* v10;                   // [esp-4h] [ebp-C0Ch]
	char PathName[1024];         // [esp+8h] [ebp-C00h]
	char FileName[1024];         // [esp+408h] [ebp-800h]
	char ExistingFileName[1024]; // [esp+808h] [ebp-400h]

	v0 = 100;
	nox_xxx_mapSwitchLevel_4D12E0(1);
	nox_xxx_setGameFlags_40A4D0(0x400000);
	*getMemU32Ptr(0x5D4594, 1550924) = nox_get_and_zero_server_objects_4DA3C0();
	memset(getMemAt(0x973F18, 2408), 0, 0x5B8u);
	while (1) {
		v1 = nox_xxx_mapGenStep_4D44E0();
		if (v1 == 1) {
			break;
		}
		if (v1) {
			if (--v0) {
				continue;
			}
		}
		return 0;
	}
	v2 = nox_fs_root();
	nox_sprintf(FileName, "%s\\nc.obj", v2);
	v3 = nox_fs_root();
	nox_sprintf(ExistingFileName, "%s\\blend.obj", v3);
	if (_access(FileName, 0) == -1 || (result = nox_fs_remove(FileName))) {
		if (_access(ExistingFileName, 0) == -1 || (result = nox_fs_move(ExistingFileName, FileName))) {
			for (i = nox_server_getFirstObject_4DA790(); i; i = nox_server_getNextObject_4DA7A0(i)) {
				*(uint32_t*)(i + 44) = 0;
			}
			nox_xxx_mapGenMakeInfo_4D5DB0((int)getMemAt(0x973F18, 2408));
			v9 = nox_xxx_getRandMapName_4D4310();
			v6 = nox_fs_root();
			nox_sprintf(PathName, "%s\\Maps\\$%s", v6, v9);
			nox_fs_mkdir(PathName);
			v10 = nox_xxx_getRandMapName_4D4310();
			v8 = nox_xxx_getRandMapName_4D4310();
			v7 = nox_fs_root();
			nox_sprintf(PathName, "%s\\Maps\\$%s\\$%s.map", v7, v8, v10);
			if (!nox_xxx_mapSaveMap_51E010(PathName, 1)) {
				return 0;
			}
			nox_xxx_mapSwitchLevel_4D12E0(1);
			nox_set_server_objects_4DA3E0(*getMemIntPtr(0x5D4594, 1550924));
			*getMemU32Ptr(0x5D4594, 1550924) = 0;
			nox_common_gameFlags_unset_40A540(0x400000);
			result = 1;
		}
	}
	return result;
}

//----- (004D44E0) --------------------------------------------------------
int nox_xxx_mapGenStep_4D44E0() {
	const char* v0; // eax
	int result;     // eax
	int v2;         // esi
	int v3;         // esi
	float* v4;      // edi
	double v5;      // st7
	char* i;        // esi
	int* j;         // esi
	int* k;         // esi
	float2 a2;      // [esp+4h] [ebp-8h]

	dword_5d4594_1550916 = 0;
	v0 = (const char*)sub_57C490("theme");
	if (v0) {
		sub_4D42E0(v0);
	}
	sub_526C40(0);
	sub_51D100(0);
	result = nox_xxx_mapGenReadTheme_51E260(getMemIntPtr(0x5D4594, 1549796), (int)getMemAt(0x587000, 197860));
	if (result) {
		*getMemU32Ptr(0x5D4594, 1549864) = (long long)(*getMemFloatPtr(0x5D4594, 1549860) * 0.030743772);
		nox_xxx_mapGenSetRngSeed_526AB0(*getMemUintPtr(0x5D4594, 1549872));
		sub_526950();
		result = nox_xxx_mapgenAllocBuffer_5213E0();
		if (result) {
			result = sub_520EA0((int)getMemAt(0x5D4594, 1549796));
			if (result) {
				nox_xxx_mapGenMkSmallRoom_4D4F40(getMemAt(0x5D4594, 1549796));
				if (nox_xxx_mapGen_InPrefab1_525D20((int)getMemAt(0x5D4594, 1549796))) {
					sub_4D52F0();
					if (nox_xxx_mapGen_InPrefab2_5266F0((int)getMemAt(0x5D4594, 1549796))) {
						if (!nox_xxx_mapGenPlacePrefabs_526830((int)getMemAt(0x5D4594, 1549796))) {
							v2 = 0;
						LABEL_25:
							nox_xxx_mapGenFreeTopRoom_521A40();
							nox_xxx_mapgenFreeBuffer_521400();
							sub_520F80();
							sub_520D50(getMemAt(0x5D4594, 1549796));
							return v2;
						}
						sub_5259F0(*(int*)&dword_5d4594_1550916, 0, 0.0);
						sub_525AF0(*(int*)&dword_5d4594_1550916);
						if (*getMemU32Ptr(0x5D4594, 1549980)) {
							v3 = (long long)(*getMemFloatPtr(0x5D4594, 1549860) * 0.030743772);
							v4 = nox_xxx_mapGenMakeRoomStruct_521940(2 * v3 + 1, 2 * v3 + 1);
							v5 = (double)-v3 * 32.526913;
							a2.field_0 = v5;
							a2.field_4 = v5;
							nox_xxx_mapGenSetRoomPos_521880(v4, &a2);
							for (i = (char*)nox_xxx_mapGenGetTopRoom_521710(); i; i = (char*)sub_521720((int)i)) {
								sub_521BC0((int)v4, (float2*)(i + 20), *((float*)i + 7), *((float*)i + 8));
							}
							sub_524070((int)getMemAt(0x5D4594, 1549796), (int)v4);
							nox_xxx_gen_524E00((int)getMemAt(0x5D4594, 1549796), (int)v4);
							nox_xxx_mapgen_522340((int)getMemAt(0x5D4594, 1549796), (int)v4);
							sub_521A10(v4);
						}
						if (nox_xxx_mapGenMakeRooms_524310((int)getMemAt(0x5D4594, 1549796))) {
							for (j = (int*)nox_xxx_mapGenGetTopRoom_521710(); j; j = (int*)sub_521720((int)j)) {
								if (nox_xxx_mapGenCheckRoomType_5238F0(j)) {
									nox_xxx_mapGenSetFlags_5235F0(156);
									nox_xxx_gen_524E00((int)getMemAt(0x5D4594, 1549796), (int)j);
								}
							}
							for (k = (int*)nox_xxx_mapGenGetTopRoom_521710(); k; k = (int*)sub_521720((int)k)) {
								if (!nox_xxx_mapGenCheckRoomType_5238F0(k)) {
									nox_xxx_mapGenSetFlags_5235F0(156);
									nox_xxx_gen_524E00((int)getMemAt(0x5D4594, 1549796), (int)k);
								}
							}
							sub_522D30((int)getMemAt(0x5D4594, 1549796));
							nox_xxx_mapgen_Doors_4D4790();
							nox_xxx_mapGenTryNextRoom_522F40(getMemAt(0x5D4594, 1549796));
							nox_xxx_mapGenGetTopRoom_521710();
							nox_xxx_mapGenFinishPopulate_5228B0_mapgen_populate((int)getMemAt(0x5D4594, 1549796));
							v2 = 1;
							goto LABEL_25;
						}
					}
				}
				v2 = 2;
				goto LABEL_25;
			}
		}
	}
	return result;
}

//----- (004D4790) --------------------------------------------------------
float* nox_xxx_mapgen_Doors_4D4790() {
	float* result; // eax
	float* v1;     // edi
	int* v2;       // esi
	int v3;        // ebx
	int v4;        // ebp
	int v5;        // eax
	int* v6;       // ebp
	int v7;        // eax
	float* v8;     // eax
	double v9;     // st7
	double v10;    // st7
	float* v11;    // eax
	double v12;    // st7
	double v13;    // st7
	double v14;    // st7
	double v15;    // st7
	int v16;       // eax
	int v17;       // eax
	int* v18;      // ebp
	int v19;       // ecx
	float* v20;    // eax
	double v21;    // st7
	double v22;    // st7
	double v23;    // st7
	float* v24;    // eax
	double v25;    // st7
	double v26;    // st7
	double v27;    // st7
	int v28;       // eax
	int v29 = 0;   // [esp+8h] [ebp-40h]
	int v30;       // [esp+Ch] [ebp-3Ch]
	int v31;       // [esp+Ch] [ebp-3Ch]
	int v32;       // [esp+10h] [ebp-38h]
	int v33 = 0;   // [esp+14h] [ebp-34h]
	float2 v34;    // [esp+18h] [ebp-30h]
	float2 a2;     // [esp+20h] [ebp-28h]
	float v36;     // [esp+28h] [ebp-20h]
	float v37;     // [esp+2Ch] [ebp-1Ch]
	float2 v38;    // [esp+30h] [ebp-18h]
	float2 v39;    // [esp+38h] [ebp-10h]
	int2 a1;       // [esp+40h] [ebp-8h]

	result = (float*)nox_xxx_mapGenGetTopRoom_521710();
	v1 = result;
	v2 = 0;
	if (!result) {
		return result;
	}
	v3 = v33;
	do {
		if (*(uint32_t*)v1 != 1) {
			goto LABEL_117;
		}
		nox_xxx_mapGenSetFlags_5235F0(156);
		v4 = 0;
		v32 = 0;
		while (1) {
			if (!*((uint8_t*)v1 + v4 + 216) &&
				nox_xxx_mapGenRandFunc_526AC0(1, 100) <= *getMemIntPtr(0x5D4594, 1549848)) {
				switch (v4) {
				case 0:
				case 1:
					a1.field_0 = (int)v1[1];
					if (v4 == 1) {
						a1.field_4 = *((uint32_t*)v1 + 2) + *((uint32_t*)v1 + 4);
					} else {
						a1.field_4 = *((uint32_t*)v1 + 2) - 1;
					}
					v31 = 0;
					if (*((int*)v1 + 3) <= 0) {
						goto LABEL_115;
					}
					while (1) {
						v17 = sub_521290(&a1);
						v18 = (int*)v17;
						if (v17) {
							if ((int*)v17 != v2) {
								goto LABEL_72;
							}
							if (*(uint8_t*)(v17 + 52) & 2) {
								++v29;
							}
						}
						if ((int*)v17 != v2 || (v19 = v31, v31 == *((uint32_t*)v1 + 3) - 1)) {
						LABEL_72:
							if (v2 && v29 >= 3) {
								v34.field_0 = (double)((v3 + v31) / 2) * 32.526913 + v1[9];
								if (v32 == 1) {
									v34.field_4 = v1[12];
								} else {
									v34.field_4 = v1[10];
								}
								sub_527030(&v34);
								v34.field_0 = v34.field_0 - 16.263456;
								if (v29 < 4) {
									nox_xxx_mapGenGetObjID_527940("ArchedDoor");
								} else {
									nox_xxx_mapGenGetObjID_527940("ArchedHalfDoor");
								}
								v20 = nox_xxx_mapGenPlaceObj_5279B0(&v34.field_0);
								if (v20) {
									nox_xxx_mapGenOrientObj_527C60((int)v20, 5);
								}
								a2.field_0 = v34.field_0;
								if (v32 == 1) {
									a2.field_4 = v34.field_4 - 32.526913;
								} else {
									a2.field_4 = v34.field_4;
								}
								sub_521BC0((int)v1, &a2, 32.526913, 32.526913);
								if (nox_xxx_mapGenCheckRoomType_5238F0(v2)) {
									v21 = a2.field_4;
									if (v32 == 1) {
										v22 = v21 + 32.526913;
									} else {
										v22 = v21 - 32.526913;
									}
									a2.field_4 = v22;
									sub_521BC0((int)v2, &a2, 32.526913, 32.526913);
								}
								v23 = v34.field_0 + 16.263456;
								if (v29 < 4) {
									v37 = v34.field_4;
								} else {
									v34.field_0 = v23 + 32.526913;
									sub_527030(&v34);
									v34.field_0 = v34.field_0 + 16.263456;
									nox_xxx_mapGenGetObjID_527940("ArchedHalfDoor");
									v24 = nox_xxx_mapGenPlaceObj_5279B0(&v34.field_0);
									if (v24) {
										nox_xxx_mapGenOrientObj_527C60((int)v24, 3);
									}
									v25 = v34.field_0 - 32.526913;
									v37 = v34.field_4;
									v36 = v25;
									a2.field_0 = v25;
									if (v32 == 1) {
										a2.field_4 = v34.field_4 - 32.526913;
									} else {
										a2.field_4 = v34.field_4;
									}
									sub_521BC0((int)v1, &a2, 32.526913, 32.526913);
									if (nox_xxx_mapGenCheckRoomType_5238F0(v2)) {
										v26 = a2.field_4;
										if (v32 == 1) {
											v27 = v26 + 32.526913;
										} else {
											v27 = v26 - 32.526913;
										}
										a2.field_4 = v27;
										sub_521BC0((int)v2, &a2, 32.526913, 32.526913);
									}
									v23 = v36;
								}
								v39.field_0 = v23;
								v39.field_4 = v37 - 32.526913;
								v38.field_0 = v23;
								v38.field_4 = v37 + 32.526913;
								sub_522C80(&v39.field_0);
								sub_522C80(&v38.field_0);
								sub_51D3F0(&v39, &v38);
								sub_51D3F0(&v38, &v39);
								if (v32 == 1) {
									sub_522CA0((int)v1, &v39.field_0);
									if (*v2 == 1) {
										sub_522CA0((int)v2, &v38.field_0);
									}
								} else {
									sub_522CA0((int)v1, &v38.field_0);
									if (*v2 == 1) {
										sub_522CA0((int)v2, &v39.field_0);
									}
								}
								sub_521900((int)v1, (int)v2, v32);
								v28 = sub_523960(v32);
								sub_521900((int)v2, (int)v1, v28);
							}
							v19 = v31;
							v3 = v31;
							v29 = 1;
							v2 = v18;
							if (v18 && *v18 == 1 && v32 == 1) {
								v2 = 0;
							}
						}
						++a1.field_0;
						v31 = v19 + 1;
						if (v19 + 1 >= *((uint32_t*)v1 + 3)) {
							goto LABEL_114;
						}
					}
				case 2:
				case 3:
					if (v4 == 2) {
						a1.field_0 = *((uint32_t*)v1 + 1) + *((uint32_t*)v1 + 3);
					} else {
						a1.field_0 = *((uint32_t*)v1 + 1) - 1;
					}
					v30 = 0;
					a1.field_4 = (int)v1[2];
					if (*((int*)v1 + 4) <= 0) {
						goto LABEL_115;
					}
					break;
				default:
					goto LABEL_115;
				}
				while (1) {
					v5 = sub_521290(&a1);
					v6 = (int*)v5;
					if (v5) {
						if ((int*)v5 != v2) {
							goto LABEL_19;
						}
						if (*(uint8_t*)(v5 + 52) & 2) {
							++v29;
						}
					}
					if ((int*)v5 != v2 || (v7 = v30, v30 == *((uint32_t*)v1 + 4) - 1)) {
					LABEL_19:
						if (v2 && v29 >= 3) {
							if (v32 == 2) {
								v34.field_0 = v1[11];
							} else {
								v34.field_0 = v1[9];
							}
							v34.field_4 = (double)((v3 + v30) / 2) * 32.526913 + v1[10];
							sub_527030(&v34);
							v34.field_4 = v34.field_4 - 16.263456;
							if (v29 < 4) {
								nox_xxx_mapGenGetObjID_527940("ArchedDoor");
							} else {
								nox_xxx_mapGenGetObjID_527940("ArchedHalfDoor");
							}
							v8 = nox_xxx_mapGenPlaceObj_5279B0(&v34.field_0);
							if (v8) {
								nox_xxx_mapGenOrientObj_527C60((int)v8, 7);
							}
							if (v32 == 2) {
								a2.field_0 = v34.field_0 - 32.526913;
							} else {
								a2.field_0 = v34.field_0;
							}
							a2.field_4 = v34.field_4;
							sub_521BC0((int)v1, &a2, 32.526913, 32.526913);
							if (nox_xxx_mapGenCheckRoomType_5238F0(v2)) {
								v9 = a2.field_0;
								if (v32 == 2) {
									v10 = v9 + 32.526913;
								} else {
									v10 = v9 - 32.526913;
								}
								a2.field_0 = v10;
								sub_521BC0((int)v2, &a2, 32.526913, 32.526913);
							}
							if (v29 < 4) {
								v15 = v34.field_4 + 16.263456;
								v36 = v34.field_0;
							} else {
								v34.field_4 = v34.field_4 + 16.263456 + 32.526913;
								sub_527030(&v34);
								v34.field_4 = v34.field_4 + 16.263456;
								nox_xxx_mapGenGetObjID_527940("ArchedHalfDoor");
								v11 = nox_xxx_mapGenPlaceObj_5279B0(&v34.field_0);
								if (v11) {
									nox_xxx_mapGenOrientObj_527C60((int)v11, 1);
								}
								v12 = v34.field_4 - 32.526913;
								v36 = v34.field_0;
								v37 = v12;
								if (v32 == 2) {
									a2.field_0 = v34.field_0 - 32.526913;
								} else {
									a2.field_0 = v34.field_0;
								}
								a2.field_4 = v12;
								sub_521BC0((int)v1, &a2, 32.526913, 32.526913);
								if (nox_xxx_mapGenCheckRoomType_5238F0(v2)) {
									v13 = a2.field_0;
									if (v32 == 2) {
										v14 = v13 + 32.526913;
									} else {
										v14 = v13 - 32.526913;
									}
									a2.field_0 = v14;
									sub_521BC0((int)v2, &a2, 32.526913, 32.526913);
								}
								v15 = v37;
							}
							v39.field_0 = v36 - 32.526913;
							v39.field_4 = v15;
							v38.field_0 = v36 + 32.526913;
							v38.field_4 = v15;
							sub_522C80(&v39.field_0);
							sub_522C80(&v38.field_0);
							sub_51D3F0(&v39, &v38);
							sub_51D3F0(&v38, &v39);
							if (v32 == 2) {
								sub_522CA0((int)v1, &v39.field_0);
								if (*v2 == 1) {
									sub_522CA0((int)v2, &v38.field_0);
								}
							} else {
								sub_522CA0((int)v1, &v38.field_0);
								if (*v2 == 1) {
									sub_522CA0((int)v2, &v39.field_0);
								}
							}
							sub_521900((int)v1, (int)v2, v32);
							v16 = sub_523960(v32);
							sub_521900((int)v2, (int)v1, v16);
						}
						v7 = v30;
						v29 = 1;
						v3 = v30;
						v2 = v6;
						if (v6 && *v6 == 1 && v32 == 3) {
							v2 = 0;
						}
					}
					++a1.field_4;
					v30 = v7 + 1;
					if (v7 + 1 >= *((uint32_t*)v1 + 4)) {
					LABEL_114:
						v4 = v32;
						break;
					}
				}
			}
		LABEL_115:
			v32 = ++v4;
			if (v4 >= 4) {
				break;
			}
			v2 = 0;
		}
		v2 = 0;
	LABEL_117:
		result = (float*)sub_521720((int)v1);
		v1 = result;
	} while (result);
	return result;
}
// 4D47A7: variable 'v33' is possibly undefined
// 4D4853: variable 'v29' is possibly undefined

//----- (004D4F40) --------------------------------------------------------
float* nox_xxx_mapGenMkSmallRoom_4D4F40(uint32_t* a1) {
	float* v1;      // edi
	float* result;  // eax
	double v3;      // st7
	int v4;         // ebp
	int* v5;        // ebx
	float* v6;      // esi
	int v7;         // eax
	double v8;      // st7
	int v9;         // esi
	int v10;        // edi
	int v11;        // ecx
	int v12;        // esi
	int* v13;       // ebp
	int v14;        // edi
	int v15;        // ebx
	float* v16;     // esi
	int v17;        // esi
	int v18;        // ebx
	int v19;        // edi
	signed int v20; // esi
	int v21;        // eax
	float2 v22;     // [esp+10h] [ebp-220h]
	int v24;        // [esp+18h] [ebp-218h]
	int* v25;       // [esp+1Ch] [ebp-214h]
	float* v26;     // [esp+20h] [ebp-210h]
	int v27;        // [esp+24h] [ebp-20Ch]
	float2 v28;     // [esp+28h] [ebp-208h]
	int v30[128];   // [esp+30h] [ebp-200h]

	v1 = 0;
	dword_5d4594_1550912 = 0;
	if (*a1 == 1) {
		v26 = 0;
		v24 = 0;
		v22.field_0 = 0.0;
		v22.field_4 = 0.0;
		v25 = getMemIntPtr(0x587000, 197924);
	LABEL_5:
		v4 = 0;
		v5 = &v30[v24];
		v27 = *v25;
		while (1) {
			result = (float*)calloc(1u, 0x178u);
			v6 = result;
			*v5 = (int)result;
			if (!result) {
				break;
			}
			v7 = v27;
			*(uint32_t*)v6 = v27;
			switch (v7) {
			case 2:
				v22.field_4 = v22.field_4 - 162.63457;
				*((uint32_t*)v6 + 3) = 4;
				*((uint32_t*)v6 + 4) = 5;
				sub_521900((int)v6, (int)v1, 1);
				sub_521900((int)v1, (int)v6, 0);
				break;
			case 3:
				if (*(uint32_t*)v1 == 4) {
					v22.field_0 = v22.field_0 + 32.526913;
					v8 = v22.field_4 + 130.10765;
				} else {
					v8 = v22.field_4 + 162.63457;
				}
				v22.field_4 = v8;
				*((uint32_t*)v6 + 3) = 4;
				*((uint32_t*)v6 + 4) = 5;
				sub_521900((int)v6, (int)v1, 0);
				sub_521900((int)v1, (int)v6, 1);
				break;
			case 4:
				if (v1) {
					v22.field_0 = v22.field_0 + 162.63457;
					sub_521900((int)v6, (int)v1, 3);
					sub_521900((int)v1, (int)v6, 2);
				}
				*((uint32_t*)v6 + 3) = 5;
				*((uint32_t*)v6 + 4) = 4;
				break;
			case 5:
				if (*(uint32_t*)v1 == 3) {
					v22.field_4 = v22.field_4 + 32.526913;
				}
				v22.field_0 = v22.field_0 - 162.63457;
				*((uint32_t*)v6 + 3) = 5;
				*((uint32_t*)v6 + 4) = 4;
				sub_521900((int)v6, (int)v1, 2);
				sub_521900((int)v1, (int)v6, 3);
				if (v4 == 5) {
					v26 = v6;
				}
				break;
			default:
				break;
			}
			v28.field_0 = v22.field_0 - 878.22662;
			v28.field_4 = v22.field_4 - 878.22662;
			v6[7] = (double)*((int*)v6 + 3) * 32.526913;
			v6[8] = (double)*((int*)v6 + 4) * 32.526913;
			nox_xxx_mapGenSetRoomPos_521880(v6, &v28);
			nox_xxx_mapGenAddNewRoom_521730(v6);
			v1 = v6;
			v9 = v24 + 1;
			++v5;
			++v4;
			++v24;
			if (v4 >= 10) {
				++v25;
				if ((int)v25 < (int)getMemAt(0x587000, 197940)) {
					goto LABEL_5;
				}
				v10 = v30[0];
				v11 = v9;
				v12 = v30[v9 - 1];
				v13 = &v30[v11];
				sub_521900(v12, v30[0], 2);
				sub_521900(v10, v12, 3);
				v14 = (int)v26;
				v15 = 0;
				v22.field_0 = v26[5];
				v22.field_4 = v26[8] + v26[6];
				while (1) {
					result = (float*)calloc(1u, 0x178u);
					v16 = result;
					*v13 = (int)result;
					if (!result) {
						break;
					}
					*(uint32_t*)result = 3;
					*((uint32_t*)result + 3) = 4;
					*((uint32_t*)result + 4) = 5;
					sub_521900((int)result, v14, 0);
					sub_521900(v14, (int)v16, 1);
					v16[7] = (double)*((int*)v16 + 3) * 32.526913;
					v16[8] = (double)*((int*)v16 + 4) * 32.526913;
					nox_xxx_mapGenSetRoomPos_521880(v16, &v22);
					nox_xxx_mapGenAddNewRoom_521730(v16);
					v14 = (int)v16;
					v17 = v24 + 1;
					++v13;
					++v15;
					v22.field_4 = v22.field_4 + 162.63457;
					++v24;
					if (v15 >= 8) {
						v18 = v17;
						v19 = v17 / 5;
						if (v17 / 5 < 1) {
							v19 = 1;
						}
						v20 = nox_xxx_mapGenRandFunc_526AC0(0, v19);
						do {
							v21 = v30[v20];
							*(uint32_t*)(v21 + 84) = dword_5d4594_1550912;
							dword_5d4594_1550912 = v21;
							v20 += nox_xxx_mapGenRandFunc_526AC0(1, v19);
						} while (v20 < v18);
						result = (float*)v30[v18 - 1];
						dword_5d4594_1550916 = v30[v18 - 1];
						return result;
					}
				}
				return result;
			}
		}
	} else {
		result = nox_xxx_mapGenPrepareRoom_521990((int)a1);
		dword_5d4594_1550916 = result;
		if (result) {
			v3 = (double)(int)a1[17];
			v22.field_0 = 0.0;
			v22.field_4 = v3 * 32.526913 - result[8] + 97.580734;
			nox_xxx_mapGenSetRoomPos_521880(result, &v22);
			nox_xxx_mapGenAddNewRoom_521730(*(uint32_t**)&dword_5d4594_1550916);
			result = *(float**)&dword_5d4594_1550916;
			*(uint32_t*)(dword_5d4594_1550916 + 84) = dword_5d4594_1550912;
			dword_5d4594_1550912 = dword_5d4594_1550916;
		}
	}
	return result;
}
// 4D4F40: using guessed type int var_200[128];

//----- (004D52F0) --------------------------------------------------------
void sub_4D52F0() {
	uint32_t* v0; // esi

	v0 = *(uint32_t**)&dword_5d4594_1550912;
	if (dword_5d4594_1550912) {
		do {
			switch (*v0) {
			case 1:
				sub_4D5350(v0, 0, 0, 0, 0);
				break;
			case 2:
			case 3:
				sub_4D5350(v0, 0, 0, v0[3], 0);
				break;
			case 4:
			case 5:
				sub_4D5350(v0, 0, 0, v0[4], 0);
				break;
			default:
				break;
			}
			v0 = (uint32_t*)v0[21];
		} while (v0);
	}
}

//----- (004D5350) --------------------------------------------------------
int sub_4D5350(uint32_t* a1, int a2, int a3, int a4, int a5) {
	int v5;     // esi
	int result; // eax

	v5 = a2 + 1;
	if (a2 + 1 >= *getMemIntPtr(0x5D4594, 1549868)) {
		return 0;
	}
	nox_xxx_mapGenSetFlags_5235F0(155);
	if (*a1 == 1) {
		result = nox_xxx_mapGenFillRoom_4D53B0((int)a1, v5, a3, a4, a5);
	} else {
		result = sub_4D5630((int)a1, v5, a3, a4, a5);
	}
	return result;
}

//----- (004D53B0) --------------------------------------------------------
int nox_xxx_mapGenFillRoom_4D53B0(int a1, int a2, int a3, int a4, int a5) {
	float* v5;      // ebx
	int v6;         // eax
	int v7;         // esi
	int v8;         // eax
	int v9;         // edi
	int v10;        // eax
	int v11;        // ebp
	int v12;        // eax
	int v13;        // eax
	signed int v14; // eax
	int v15;        // eax
	int v16;        // esi
	int v17;        // ebp
	float* v18;     // esi
	double v19;     // st7
	double v20;     // st7
	int v21;        // eax
	int v22;        // eax
	int* v23;       // eax
	int v24;        // edi
	int v25;        // eax
	int v26;        // eax
	int v28;        // [esp+10h] [ebp-1Ch]
	float2 a2a;     // [esp+14h] [ebp-18h]
	int v30;        // [esp+1Ch] [ebp-10h]
	int v31;        // [esp+20h] [ebp-Ch]
	int v32;        // [esp+24h] [ebp-8h]
	int v33;        // [esp+28h] [ebp-4h]
	int v34;        // [esp+30h] [ebp+4h]

	v5 = (float*)a1;
	v6 = sub_5218B0(a1, 0);
	v7 = v6 != 0 ? 0 : 2;
	v30 = v6 != 0 ? 0 : 2;
	v8 = sub_5218B0(a1, 1);
	v9 = v8 != 0 ? 0 : 3;
	v31 = v8 != 0 ? 0 : 3;
	v10 = sub_5218B0(a1, 2);
	v11 = v10 != 0 ? 0 : 4;
	v32 = v10 != 0 ? 0 : 4;
	v12 = -(sub_5218B0(a1, 3) != 0);
	LOBYTE(v12) = v12 & 0xFB;
	v13 = v12 + 5;
	v33 = v13;
	if (v7 || v9 || v11 || v13) {
		v14 = nox_xxx_mapGenRandFunc_526AC0(0, 3);
		v34 = 0;
		while (1) {
			v15 = (v14 + 1) % 4;
			v16 = *(&v30 + v15);
			v28 = v15;
			if (!v16) {
				goto LABEL_6;
			}
			v17 = nox_xxx_mapGenRandFunc_526AC0(*getMemU32Ptr(0x5D4594, 1549808) - *getMemU32Ptr(0x5D4594, 1549812),
												*getMemU32Ptr(0x5D4594, 1549812) + *getMemU32Ptr(0x5D4594, 1549808));
			v18 = nox_xxx_mapGenMakeHall_523EC0((int)getMemAt(0x5D4594, 1549796), v16, v17);
			if (!v18) {
				return 0;
			}
			switch (*(uint32_t*)v18) {
			case 2:
				a2a.field_0 = sub_521B00((int)v5, (int)v18);
				v19 = v5[6] - v18[8];
				goto LABEL_15;
			case 3:
				a2a.field_0 = sub_521B00((int)v5, (int)v18);
				v19 = v5[8] + v5[6];
				goto LABEL_15;
			case 4:
				v20 = v5[7] + v5[5];
				goto LABEL_14;
			case 5:
				v20 = v5[5] - v18[7];
			LABEL_14:
				a2a.field_0 = v20;
				v19 = sub_521B30((int)v5, (int)v18);
			LABEL_15:
				a2a.field_4 = v19;
				break;
			default:
				break;
			}
			nox_xxx_mapGenSetRoomPos_521880(v18, &a2a);
			if (!sub_5217A0((int)getMemAt(0x5D4594, 1549796), (int)v18)) {
			LABEL_17:
				sub_521A10(v18);
				goto LABEL_26;
			}
			v21 = sub_523920(*(uint32_t*)v18);
			v22 = sub_523960(v21);
			sub_521900((int)v18, (int)v5, v22);
			v23 = (int*)sub_521200((int)v18);
			v24 = (int)v23;
			if (v23) {
				break;
			}
			nox_xxx_mapGenAddNewRoom_521730(v18);
			if (sub_4D5350(v18, a2, 1, v17, (int)v5)) {
				goto LABEL_25;
			}
			sub_521760((int)v18);
			sub_521A10(v18);
		LABEL_26:
			if (++v34 >= 8) {
				return 1;
			}
		LABEL_6:
			v14 = v28;
		}
		if (nox_xxx_mapGenCheckRoomType_5238F0(v23) || *(uint8_t*)(v24 + 52) & 2 || v24 == a5 ||
			nox_xxx_mapGenRandFunc_526AC0(1, 100) > *(int*)&dword_5d4594_1549844 ||
			!sub_523A10((int)v18, (float*)v24)) {
			goto LABEL_17;
		}
		nox_xxx_mapGenAddNewRoom_521730(v18);
		v25 = sub_523920(*(uint32_t*)v18);
		sub_521A70((int)v18, v24, v25);
	LABEL_25:
		v26 = sub_523920(*(uint32_t*)v18);
		sub_521900((int)v5, (int)v18, v26);
		goto LABEL_26;
	}
	return 1;
}

//----- (004D5630) --------------------------------------------------------
int sub_4D5630(int a1, int a2, int a3, int a4, int a5) {
	int v5;     // esi
	int v6;     // eax
	int v7;     // ebp
	float* v8;  // edi
	double v9;  // st7
	double v10; // st7
	int v11;    // eax
	float* v13; // eax
	float* v14; // edi
	double v15; // st7
	double v16; // st7
	int v17;    // eax
	float* v18; // ebp
	int v19;    // ebx
	int v20;    // eax
	int v21;    // eax
	float* v22; // edi
	double v23; // st7
	double v24; // st7
	double v25; // st7
	int v26;    // eax
	float* v27; // ebp
	int v28;    // ebx
	int v29;    // eax
	int v30;    // eax
	float* v31; // eax
	int* v32;   // edi
	double v33; // st7
	double v34; // st7
	double v35; // st7
	double v36; // st7
	int v37;    // eax
	int v38;    // eax
	float* v39; // ebp
	int v40;    // ebx
	int v41;    // eax
	int v42;    // eax
	int v43;    // [esp+10h] [ebp-14h]
	int v44;    // [esp+14h] [ebp-10h]
	int v45;    // [esp+18h] [ebp-Ch]
	float2 a2a; // [esp+1Ch] [ebp-8h]
	int v47;    // [esp+28h] [ebp+4h]
	int v48;    // [esp+28h] [ebp+4h]
	int v49;    // [esp+28h] [ebp+4h]

	v5 = a1;
	v43 = 0;
	v44 = 0;
	if (a3 >= *getMemIntPtr(0x5D4594, 1549816) || (v6 = sub_4D5D20((uint32_t*)a1), v45 = v6, v6 == 1)) {
		v7 = 0;
		while (1) {
			v8 = nox_xxx_mapGenPrepareRoom_521990((int)getMemAt(0x5D4594, 1549796));
			if (!v8) {
				return 0;
			}
			switch (*(uint32_t*)a1) {
			case 2:
				a2a.field_0 = sub_521B60((int)v8, a1);
				v9 = *(float*)(a1 + 24) - v8[8];
				goto LABEL_11;
			case 3:
				a2a.field_0 = sub_521B60((int)v8, a1);
				v9 = *(float*)(a1 + 32) + *(float*)(a1 + 24);
				goto LABEL_11;
			case 4:
				v10 = *(float*)(a1 + 28) + *(float*)(a1 + 20);
				goto LABEL_10;
			case 5:
				v10 = *(float*)(a1 + 20) - v8[7];
			LABEL_10:
				a2a.field_0 = v10;
				v9 = sub_521B90((int)v8, a1);
			LABEL_11:
				a2a.field_4 = v9;
				break;
			default:
				break;
			}
			nox_xxx_mapGenSetRoomPos_521880(v8, &a2a);
			if (!sub_521820((int)getMemAt(0x5D4594, 1549796), (int)v8)) {
				sub_521A10(v8);
				if (++v7 < 10) {
					continue;
				}
			}
			if (v7 == 10) {
				return 0;
			}
			nox_xxx_mapGenAddNewRoom_521730(v8);
			v11 = sub_523920(*(uint32_t*)a1);
			sub_521A70(a1, (int)v8, v11);
			sub_4D5350(v8, a2, 0, 0, (int)v8);
			return 1;
		}
	}
	if (v6 != 2 && v6 != 8 && v6 != 32 && v6 != 64) {
		goto LABEL_43;
	}
	v13 = nox_xxx_mapGenMakeHall_523EC0((int)getMemAt(0x5D4594, 1549796),
										*getMemU32Ptr(0x587000, 197812 + 4 * *(uint32_t*)a1), a4);
	v14 = v13;
	if (!v13) {
		return 0;
	}
	switch (*(uint32_t*)a1) {
	case 2:
		v15 = *(float*)(a1 + 20) - v13[7];
		a2a.field_4 = *(float*)(a1 + 24);
		a2a.field_0 = v15;
		break;
	case 3:
		a2a.field_0 = *(float*)(a1 + 28) + *(float*)(a1 + 20);
		v16 = *(float*)(a1 + 32) + *(float*)(a1 + 24) - v13[8];
		goto LABEL_26;
	case 4:
		a2a.field_0 = *(float*)(a1 + 28) + *(float*)(a1 + 20) - v13[7];
		v16 = *(float*)(a1 + 24) - v13[8];
		goto LABEL_26;
	case 5:
		v16 = *(float*)(a1 + 32) + *(float*)(a1 + 24);
		a2a.field_0 = *(float*)(a1 + 20);
	LABEL_26:
		a2a.field_4 = v16;
		break;
	default:
		break;
	}
	nox_xxx_mapGenSetRoomPos_521880(v13, &a2a);
	v47 = sub_5239B0(*(uint32_t*)a1);
	sub_521900((int)v14, v5, v47);
	if (!sub_5217A0((int)getMemAt(0x5D4594, 1549796), (int)v14)) {
		goto LABEL_100;
	}
	v17 = sub_521200((int)v14);
	v18 = (float*)v17;
	if (!v17) {
		v43 = 1;
		v19 = 0;
		goto LABEL_34;
	}
	if (*(uint32_t*)v17 != 1 || *(uint8_t*)(v17 + 52) & 2 || v17 == a5 ||
		nox_xxx_mapGenRandFunc_526AC0(1, 100) > *(int*)&dword_5d4594_1549844) {
	LABEL_100:
		v43 = 0;
		goto LABEL_41;
	}
	v43 = sub_523A10((int)v14, v18);
	v19 = 1;
	if (!v43) {
		goto LABEL_41;
	}
LABEL_34:
	nox_xxx_mapGenAddNewRoom_521730(v14);
	if (!v19) {
		if (sub_4D5350(v14, a2, a3 + 1, a4, a5)) {
			goto LABEL_39;
		}
		sub_521760((int)v14);
		v43 = 0;
	LABEL_41:
		sub_521A10(v14);
		if (v45 == 2 || v45 == 8) {
			return 0;
		}
		goto LABEL_43;
	}
	v20 = sub_523920(*(uint32_t*)v14);
	sub_521A70((int)v14, (int)v18, v20);
LABEL_39:
	v21 = sub_523960(v47);
	sub_521900(v5, (int)v14, v21);
LABEL_43:
	if (v45 != 4 && v45 != 16 && v45 != 32 && v45 != 64) {
		goto LABEL_71;
	}
	v22 = nox_xxx_mapGenMakeHall_523EC0((int)getMemAt(0x5D4594, 1549796),
										*getMemU32Ptr(0x587000, 197836 + 4 * *(uint32_t*)v5), a4);
	if (!v22) {
		return 0;
	}
	switch (*(uint32_t*)v5) {
	case 2:
		v23 = *(float*)(v5 + 28) + *(float*)(v5 + 20);
		a2a.field_4 = *(float*)(v5 + 24);
		a2a.field_0 = v23;
		break;
	case 3:
		a2a.field_0 = *(float*)(v5 + 20) - v22[7];
		v24 = *(float*)(v5 + 32) + *(float*)(v5 + 24);
		goto LABEL_53;
	case 4:
		a2a.field_0 = *(float*)(v5 + 28) + *(float*)(v5 + 20) - v22[7];
		v25 = *(float*)(v5 + 32) + *(float*)(v5 + 24);
		goto LABEL_54;
	case 5:
		v24 = *(float*)(v5 + 24);
		a2a.field_0 = *(float*)(v5 + 20);
	LABEL_53:
		v25 = v24 - v22[8];
	LABEL_54:
		a2a.field_4 = v25;
		break;
	default:
		break;
	}
	nox_xxx_mapGenSetRoomPos_521880(v22, &a2a);
	v48 = sub_523970(*(uint32_t*)v5);
	sub_521900((int)v22, v5, v48);
	if (!sub_5217A0((int)getMemAt(0x5D4594, 1549796), (int)v22)) {
		goto LABEL_101;
	}
	v26 = sub_521200((int)v22);
	v27 = (float*)v26;
	if (!v26) {
		v44 = 1;
		v28 = 0;
		goto LABEL_62;
	}
	if (*(uint32_t*)v26 != 1 || *(uint8_t*)(v26 + 52) & 2 || v26 == a5 ||
		nox_xxx_mapGenRandFunc_526AC0(1, 100) > *(int*)&dword_5d4594_1549844) {
	LABEL_101:
		v44 = 0;
		goto LABEL_69;
	}
	v44 = sub_523A10((int)v22, v27);
	v28 = 1;
	if (!v44) {
		goto LABEL_69;
	}
LABEL_62:
	nox_xxx_mapGenAddNewRoom_521730(v22);
	if (!v28) {
		if (sub_4D5350(v22, a2, a3 + 1, a4, a5)) {
			goto LABEL_67;
		}
		sub_521760((int)v22);
		v44 = 0;
	LABEL_69:
		sub_521A10(v22);
		if (v45 == 4 || v45 == 16) {
			return 0;
		}
		goto LABEL_71;
	}
	v29 = sub_523920(*(uint32_t*)v22);
	sub_521A70((int)v22, (int)v27, v29);
LABEL_67:
	v30 = sub_523960(v48);
	sub_521900(v5, (int)v22, v30);
LABEL_71:
	if (v43 || v44) {
		if (v45 != 32 && v45 != 8 && v45 != 16) {
			return 1;
		}
		v31 = nox_xxx_mapGenMakeHall_523EC0((int)getMemAt(0x5D4594, 1549796), *(uint32_t*)v5, a4);
		v32 = (int*)v31;
		if (v31) {
			switch (*(uint32_t*)v5) {
			case 2:
				v33 = *(float*)(v5 + 24);
				a2a.field_0 = *(float*)(v5 + 20);
				a2a.field_4 = v33 - v31[8];
				break;
			case 3:
				v34 = *(float*)(v5 + 32) + *(float*)(v5 + 24);
				a2a.field_0 = *(float*)(v5 + 20);
				a2a.field_4 = v34;
				break;
			case 4:
				v35 = *(float*)(v5 + 28) + *(float*)(v5 + 20);
				a2a.field_4 = *(float*)(v5 + 24);
				a2a.field_0 = v35;
				break;
			case 5:
				v36 = *(float*)(v5 + 20) - v31[7];
				a2a.field_4 = *(float*)(v5 + 24);
				a2a.field_0 = v36;
				break;
			default:
				break;
			}
			nox_xxx_mapGenSetRoomPos_521880(v31, &a2a);
			v37 = sub_523920(*(uint32_t*)v5);
			v49 = sub_523960(v37);
			sub_521900((int)v32, v5, v49);
			if (sub_5217A0((int)getMemAt(0x5D4594, 1549796), (int)v32)) {
				v38 = sub_521200((int)v32);
				v39 = (float*)v38;
				if (!v38) {
					v40 = 0;
				LABEL_89:
					nox_xxx_mapGenAddNewRoom_521730(v32);
					if (v40) {
						v41 = sub_523920(*v32);
						sub_521A70((int)v32, (int)v39, v41);
					LABEL_96:
						v42 = sub_523960(v49);
						sub_521900(v5, (int)v32, v42);
						return 1;
					}
					if (sub_4D5350(v32, a2, a3 + 1, a4, a5)) {
						goto LABEL_96;
					}
					sub_521760((int)v32);
					goto LABEL_94;
				}
				if (*(uint32_t*)v38 == 1 && !(*(uint8_t*)(v38 + 52) & 2) && v38 != a5 &&
					nox_xxx_mapGenRandFunc_526AC0(1, 100) <= *(int*)&dword_5d4594_1549844) {
					v40 = 1;
					if (sub_523A10((int)v32, v39)) {
						goto LABEL_89;
					}
				}
			}
		LABEL_94:
			sub_521A10(v32);
			return 1;
		}
	}
	return 0;
}

//----- (004D5D20) --------------------------------------------------------
int sub_4D5D20(uint32_t* a1) {
	int result; // eax

	if (*a1 == 2 || *a1 == 3) {
		if (a1[3] >= a1[4]) {
			return 1;
		}
	} else if (a1[4] >= a1[3]) {
		return 1;
	}
	if (nox_xxx_mapGenRandFunc_526AC0(1, 100) > *getMemIntPtr(0x5D4594, 1549820)) {
		if (nox_xxx_mapGenRandFunc_526AC0(1, 100) > *getMemIntPtr(0x5D4594, 1549824)) {
			result = nox_xxx_mapGenRandFunc_526AC0(1, 100) >= 50 ? 4 : 2;
		} else {
			result = 1;
		}
	} else {
		nox_xxx_mapGenRandFunc_526AC0(1, 100);
		result = 32;
	}
	return result;
}

//----- (004D5DB0) --------------------------------------------------------
unsigned int nox_xxx_mapGenMakeInfo_4D5DB0(int a1) {
	unsigned int result;           // eax
	struct _SYSTEMTIME SystemTime; // [esp+Ch] [ebp-410h]
	char DateStr[1024];            // [esp+1Ch] [ebp-400h]

	strcpy((char*)a1, "Generated Map");
	strcpy((char*)(a1 + 64), "Generated Map");
	*(uint16_t*)(a1 + 576) = *getMemU16Ptr(0x587000, 198380);
	*(uint32_t*)(a1 + 592) = *getMemU32Ptr(0x587000, 198384);
	strcpy((char*)(a1 + 656), "http://www.westwood.com");
	strcpy((char*)(a1 + 720), "http://www.westwood.com");
	strcpy((char*)(a1 + 848), "http://www.westwood.com");
	strcpy((char*)(a1 + 976), "Generated Map");
	strcpy((char*)(a1 + 1232), "Westwood Studios");
	GetLocalTime(&SystemTime);
	GetDateFormatA(0x800u, 0, &SystemTime, (const char*)getMemAt(0x587000, 198496), DateStr, 1024);
	result = strlen(DateStr) + 1;
	memcpy((void*)(a1 + 1360), DateStr, result);
	*(uint32_t*)(a1 + 1392) = 3;
	return result;
}

//----- (004D5F30) --------------------------------------------------------
int nox_xxx_mapGenStartAlt_4D5F30() {
	int v0;                      // esi
	int v1;                      // eax
	char* v2;                    // eax
	char* v3;                    // eax
	int result;                  // eax
	char FileName[1024];         // [esp+8h] [ebp-800h]
	char ExistingFileName[1024]; // [esp+408h] [ebp-400h]

	v0 = 100;
	nox_xxx_setGameFlags_40A4D0(0x400000);
	memset(getMemAt(0x973F18, 2408), 0, 0x5B8u);
	while (1) {
		v1 = nox_xxx_mapGenStep_4D44E0();
		if (v1 == 1) {
			break;
		}
		if (v1) {
			if (--v0) {
				continue;
			}
		}
		return 0;
	}
	v2 = nox_fs_root();
	nox_sprintf(FileName, "%s\\nc.obj", v2);
	v3 = nox_fs_root();
	nox_sprintf(ExistingFileName, "%s\\blend.obj", v3);
	result = nox_fs_remove(FileName);
	if (!result) {
		return result;
	}
	if (!nox_fs_move(ExistingFileName, FileName)) {
		return 0;
	}
	nox_xxx_mapGenMakeInfo_4D5DB0((int)getMemAt(0x973F18, 2408));
	nox_common_gameFlags_unset_40A540(0x400000);
	return 1;
}

//----- (004D6000) --------------------------------------------------------
int sub_4D6000(int a1) {
	int result; // eax
	int v2;     // esi

	result = 0;
	if (a1) {
		v2 = *(uint32_t*)(a1 + 748);
		*(uint32_t*)(*(uint32_t*)(v2 + 276) + 4652) = 0;
		*(uint32_t*)(*(uint32_t*)(v2 + 276) + 4656) = 0;
		*(uint32_t*)(*(uint32_t*)(v2 + 276) + 4660) = 0;
		*(uint32_t*)(*(uint32_t*)(v2 + 276) + 4664) = 0;
		*(uint32_t*)(*(uint32_t*)(v2 + 276) + 4668) = 0;
		*(uint32_t*)(*(uint32_t*)(v2 + 276) + 4672) = 0;
		*(uint32_t*)(*(uint32_t*)(v2 + 276) + 4676) = 0;
		*(uint32_t*)(*(uint32_t*)(v2 + 276) + 4680) = 0;
		*(uint32_t*)(*(uint32_t*)(v2 + 276) + 4684) = 0;
		*(uint32_t*)(*(uint32_t*)(v2 + 276) + 4688) = nox_game_getQuestStage_4E3CC0();
		result = *(uint32_t*)(v2 + 276);
		*(uint32_t*)(result + 4692) = 63;
	}
	return result;
}

//----- (004D60B0) --------------------------------------------------------
int sub_4D60B0() {
	int result; // eax
	int i;      // esi

	result = nox_xxx_getFirstPlayerUnit_4DA7C0();
	for (i = result; result; i = result) {
		sub_4D6000(i);
		result = nox_xxx_getNextPlayerUnit_4DA7F0(i);
	}
	return result;
}

//----- (004D60E0) --------------------------------------------------------
uint32_t* sub_4D60E0(int a1) {
	uint32_t* result; // eax
	int v2;           // ecx

	result = (uint32_t*)a1;
	if ((*(uint8_t*)(a1 + 16) & 0x20) != 32) {
		v2 = *(uint32_t*)(a1 + 748);
		result = *(uint32_t**)(v2 + 276);
		if (result[1198] == 1) {
			++result[1163];
			result = *(uint32_t**)(v2 + 276);
			result[1173] |= 1u;
		}
	}
	return result;
}

//----- (004D6130) --------------------------------------------------------
int sub_4D6130(int a1) {
	int result; // eax
	int v2;     // eax

	result = a1;
	if (a1) {
		if ((*(uint8_t*)(a1 + 16) & 0x20) != 32) {
			v2 = *(uint32_t*)(a1 + 748);
			++*(uint32_t*)(*(uint32_t*)(v2 + 276) + 4660);
			result = *(uint32_t*)(v2 + 276);
			*(uint32_t*)(result + 4692) |= 2u;
		}
	}
	return result;
}

//----- (004D6170) --------------------------------------------------------
int sub_4D6170(int a1) {
	int result; // eax
	int v2;     // eax

	result = a1;
	if (a1) {
		if ((*(uint8_t*)(a1 + 16) & 0x20) != 32) {
			v2 = *(uint32_t*)(a1 + 748);
			++*(uint32_t*)(*(uint32_t*)(v2 + 276) + 4664);
			result = *(uint32_t*)(v2 + 276);
			*(uint32_t*)(result + 4692) |= 4u;
		}
	}
	return result;
}

//----- (004D61B0) --------------------------------------------------------
void sub_4D61B0(int a1) {
	int v2; // eax
	if (a1) {
		if ((*(uint8_t*)(a1 + 16) & 0x20) != 32) {
			v2 = *(uint32_t*)(a1 + 748);
			++*(uint32_t*)(*(uint32_t*)(v2 + 276) + 4668);
			int result = *(uint32_t*)(v2 + 276);
			*(uint32_t*)(result + 4692) |= 8u;
		}
	}
}

//----- (004D61F0) --------------------------------------------------------
int sub_4D61F0(int a1) {
	int result; // eax
	int v2;     // eax

	result = a1;
	if (a1) {
		if ((*(uint8_t*)(a1 + 16) & 0x20) != 32) {
			v2 = *(uint32_t*)(a1 + 748);
			++*(uint32_t*)(*(uint32_t*)(v2 + 276) + 4672);
			++*(uint32_t*)(*(uint32_t*)(v2 + 276) + 4676);
			result = *(uint32_t*)(v2 + 276);
			*(uint32_t*)(result + 4692) |= 0x10u;
		}
	}
	return result;
}

//----- (004D6240) --------------------------------------------------------
int nox_xxx_unused_4D6240(int a1, int a2) {
	int result; // eax
	int v3;     // eax

	result = a1;
	if (a1) {
		if ((*(uint8_t*)(a1 + 16) & 0x20) != 32) {
			v3 = *(uint32_t*)(a1 + 748);
			*(uint32_t*)(*(uint32_t*)(v3 + 276) + 4684) += a2;
			result = *(uint32_t*)(v3 + 276);
			*(uint32_t*)(result + 4692) |= 0x20u;
		}
	}
	return result;
}

//----- (004D6290) --------------------------------------------------------
int nox_xxx_unused_4D6290(int a1) {
	int result;  // eax
	int v2;      // eax
	char v3[16]; // [esp+0h] [ebp-10h]

	result = a1;
	if (a1) {
		v2 = *(uint32_t*)(a1 + 748);
		v3[0] = -16;
		v3[1] = 11;
		*(uint16_t*)&v3[2] = *(uint16_t*)(*(uint32_t*)(v2 + 276) + 4652);
		*(uint16_t*)&v3[4] = *(uint16_t*)(*(uint32_t*)(v2 + 276) + 4656);
		*(uint16_t*)&v3[6] = *(uint16_t*)(*(uint32_t*)(v2 + 276) + 4660);
		*(uint16_t*)&v3[8] = *(uint16_t*)(*(uint32_t*)(v2 + 276) + 4664);
		*(uint16_t*)&v3[10] = *(uint16_t*)(*(uint32_t*)(v2 + 276) + 4668);
		*(uint16_t*)&v3[12] = *(uint16_t*)(*(uint32_t*)(v2 + 276) + 4672);
		*(uint16_t*)&v3[14] = *(uint16_t*)(*(uint32_t*)(v2 + 276) + 4684);
		result = nox_xxx_netSendPacket0_4E5420(*(unsigned char*)(*(uint32_t*)(v2 + 276) + 2064), v3, 16, 0, 1);
	}
	return result;
}

//----- (004D6360) --------------------------------------------------------
int sub_4D6360(int a1) {
	int result; // eax
	int v2;     // eax

	result = a1;
	if (a1) {
		v2 = *(uint32_t*)(a1 + 748);
		LOWORD(a1) = 1520;
		HIWORD(a1) = *(uint16_t*)(*(uint32_t*)(v2 + 276) + 4652);
		result = nox_xxx_netSendPacket0_4E5420(*(unsigned char*)(*(uint32_t*)(v2 + 276) + 2064), &a1, 4, 0, 1);
	}
	return result;
}

//----- (004D63B0) --------------------------------------------------------
int sub_4D63B0(int a1) {
	int result; // eax
	int v2;     // eax

	result = a1;
	if (a1) {
		v2 = *(uint32_t*)(a1 + 748);
		LOWORD(a1) = 1776;
		HIWORD(a1) = *(uint16_t*)(*(uint32_t*)(v2 + 276) + 4660);
		result = nox_xxx_netSendPacket0_4E5420(*(unsigned char*)(*(uint32_t*)(v2 + 276) + 2064), &a1, 4, 0, 1);
	}
	return result;
}

//----- (004D6400) --------------------------------------------------------
int nox_xxx_unused_4D6400(int a1) {
	int result; // eax
	int v2;     // eax

	result = a1;
	if (a1) {
		v2 = *(uint32_t*)(a1 + 748);
		LOWORD(a1) = 2032;
		HIWORD(a1) = *(uint16_t*)(*(uint32_t*)(v2 + 276) + 4664);
		result = nox_xxx_netSendPacket0_4E5420(*(unsigned char*)(*(uint32_t*)(v2 + 276) + 2064), &a1, 4, 0, 1);
	}
	return result;
}

//----- (004D6450) --------------------------------------------------------
int nox_xxx_unused_4D6450(int a1) {
	int result; // eax
	int v2;     // eax

	result = a1;
	if (a1) {
		v2 = *(uint32_t*)(a1 + 748);
		LOWORD(a1) = 2288;
		HIWORD(a1) = *(uint16_t*)(*(uint32_t*)(v2 + 276) + 4668);
		result = nox_xxx_netSendPacket0_4E5420(*(unsigned char*)(*(uint32_t*)(v2 + 276) + 2064), &a1, 4, 0, 1);
	}
	return result;
}

//----- (004D64A0) --------------------------------------------------------
int nox_xxx_unused_4D64A0(int a1) {
	int result; // eax
	int v2;     // eax

	result = a1;
	if (a1) {
		v2 = *(uint32_t*)(a1 + 748);
		LOWORD(a1) = 2544;
		HIWORD(a1) = *(uint16_t*)(*(uint32_t*)(v2 + 276) + 4672);
		result = nox_xxx_netSendPacket0_4E5420(*(unsigned char*)(*(uint32_t*)(v2 + 276) + 2064), &a1, 4, 0, 1);
	}
	return result;
}

//----- (004D64F0) --------------------------------------------------------
int nox_xxx_unused_4D64F0(int a1) {
	int result; // eax
	int v2;     // eax

	result = a1;
	if (a1) {
		v2 = *(uint32_t*)(a1 + 748);
		LOWORD(a1) = 2800;
		HIWORD(a1) = *(uint16_t*)(*(uint32_t*)(v2 + 276) + 4684);
		result = nox_xxx_netSendPacket0_4E5420(*(unsigned char*)(*(uint32_t*)(v2 + 276) + 2064), &a1, 4, 0, 1);
	}
	return result;
}

//----- (004D6540) --------------------------------------------------------
unsigned int sub_4D6540(int a1) {
	int v1;              // edi
	unsigned int* v2;    // eax
	unsigned int* v3;    // ebx
	unsigned int result; // eax
	unsigned int v5;     // ebp
	int i;               // edi
	unsigned int* v7;    // esi
	unsigned int v8;     // eax
	int v9;              // eax
	float v10;           // [esp+0h] [ebp-28h]
	unsigned int v11;    // [esp+14h] [ebp-14h]
	unsigned int v12;    // [esp+18h] [ebp-10h]
	float v13;           // [esp+20h] [ebp-8h]
	unsigned int v14;    // [esp+2Ch] [ebp+4h]

	v1 = nox_xxx_player_4E3CE0();
	v2 = (unsigned int*)nox_common_playerInfoFromNum_417090(a1);
	v3 = v2;
	if (!v2 || !v2[1198]) {
		return 0;
	}
	if (v1 == 1) {
		result = sub_4D66E0(v2[1167], v2[1168], v2[1166], v2[1172]);
	} else {
		v5 = 0;
		v11 = 0;
		v14 = 0;
		v12 = 1;
		v13 = 1.0;
		for (i = nox_xxx_getFirstPlayerUnit_4DA7C0(); i; i = nox_xxx_getNextPlayerUnit_4DA7F0(i)) {
			v7 = *(unsigned int**)(*(uint32_t*)(i + 748) + 276);
			if (v3[1198]) {
				v8 = sub_4D66E0(v7[1167], v7[1168], 0, v7[1172]);
				if (v8 > v5) {
					v5 = v8;
				}
				v11 += v7[1167];
				v12 = v7[1172];
				v14 += v7[1168];
			}
		}
		v9 = sub_4D66E0(v11, v14, 0, v12);
		if (v5 > 0) {
			v13 = (double)(unsigned int)v9 / (double)v5;
		}
		v10 = (double)(unsigned int)sub_4D66E0(v3[1167], v3[1168], v3[1166], v3[1172]) * v13;
		result = nox_float2int(v10);
	}
	if (result > 0x3B9AC9FF) {
		result = 999999999;
	}
	return result;
}

//----- (004D66E0) --------------------------------------------------------
int sub_4D66E0(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4) {
	float v5; // [esp+4h] [ebp-10h]

	v5 = nox_double2float(pow((double)a4, *(long double*)getMemAt(0x581450, 10088))) *
		 ((double)a1 * 10.0 + (double)a2 * 35.0 + (double)a3 * 0.1);
	return nox_float2int(v5);
}

//----- (004D6770) --------------------------------------------------------
int sub_4D6770(int a1) {
	char* v1;    // ebp
	int v2;      // ebx
	int v3;      // edi
	char* v4;    // esi
	int v5;      // eax
	char v7[90]; // [esp+Ch] [ebp-5Ch]

	v1 = nox_common_playerInfoFromNum_417090(a1);
	memset(v7, 0, 0x58u);
	*(uint16_t*)&v7[88] = 0;
	v7[0] = -16;
	v7[1] = 12;
	*(uint16_t*)&v7[2] = sub_4D7300();
	v2 = 0;
	v3 = nox_xxx_getFirstPlayerUnit_4DA7C0();
	if (v3) {
		v4 = &v7[8];
		do {
			v5 = *(uint32_t*)(v3 + 748);
			if (*(uint32_t*)(*(uint32_t*)(v5 + 276) + 4792) == 1 && v2 < 6) {
				*((uint16_t*)v4 - 1) = *(uint16_t*)(v3 + 36);
				*(uint16_t*)v4 = *(uint16_t*)(*(uint32_t*)(v5 + 276) + 4668);
				*((uint16_t*)v4 + 3) = *(uint16_t*)(*(uint32_t*)(v5 + 276) + 4664);
				*((uint16_t*)v4 + 1) = *(uint16_t*)(*(uint32_t*)(v5 + 276) + 4672);
				*((uint16_t*)v4 + 2) = *(uint16_t*)(*(uint32_t*)(v5 + 276) + 4680);
				*((uint32_t*)v4 + 2) = sub_4D6540(*(unsigned char*)(*(uint32_t*)(v5 + 276) + 2064));
				++v2;
				v4 += 14;
				*(uint16_t*)&v7[4] = *((uint16_t*)v1 + 2344);
			}
			v3 = nox_xxx_getNextPlayerUnit_4DA7F0(v3);
		} while (v3);
	}
	return nox_xxx_netSendPacket1_4E5390(a1, (int)v7, 90, 0, 1);
}

//----- (004D6880) --------------------------------------------------------
int sub_4D6880(int a1, int a2) {
	char v3[69]; // [esp+8h] [ebp-48h]

	memset(v3, 0, 0x44u);
	v3[68] = 0;
	v3[0] = -16;
	v3[1] = 13;
	if (a2) {
		v3[4] |= 1u;
	}
	if (sub_51A950()) {
		v3[4] |= 2u;
	}
	*(uint16_t*)&v3[2] = nox_game_getQuestStage_4E3CC0();
	nox_server_currentMapGetFilename_409B30();
	strcpy(&v3[5], sub_4D6940());
	nox_server_currentMapGetFilename_409B30();
	strcpy(&v3[37], sub_4D6950());
	return nox_xxx_netSendPacket1_4E5390(a1, (int)v3, 69, 0, 1);
}

//----- (004D6940) --------------------------------------------------------
char* sub_4D6940() { return (char*)getMemAt(0x973F18, 3838); }

//----- (004D6950) --------------------------------------------------------
char* sub_4D6950() { return (char*)getMemAt(0x973F18, 3806); }

//----- (004D6960) --------------------------------------------------------
int nox_game_sendQuestStage_4D6960(int a1) {
	char v2[69] = {0};
	v2[0] = -16;
	v2[1] = 14;
	v2[4] = 0;
	if (sub_51A950()) {
		v2[4] |= 2u;
	}
	*(uint16_t*)&v2[2] = nox_game_getQuestStage_4E3CC0();
	nox_server_currentMapGetFilename_409B30();
	strcpy(&v2[5], sub_4D6940());
	nox_server_currentMapGetFilename_409B30();
	strcpy(&v2[37], sub_4D6950());
	return nox_xxx_netSendPacket1_4E5390(a1, (int)v2, 69, 0, 1);
}

//----- (004D6A20) --------------------------------------------------------
int sub_4D6A20(int a1, int a2) {
	short v3; // cx
	int v5;   // [esp+0h] [ebp-4h]

	v3 = *(uint16_t*)(a2 + 40);
	LOWORD(v5) = 4080;
	HIWORD(v5) = v3;
	return nox_xxx_netSendPacket0_4E5420(a1, &v5, 4, 0, 1);
}

//----- (004D6A60) --------------------------------------------------------
int sub_4D6A60() {
	int result; // eax
	int i;      // esi

	nox_xxx_warriorMaxHealth_587000_312784 = 1077936128;
	nox_xxx_warriorMaxMana_587000_312788 = 1065353216;
	nox_xxx_warriorMaxStrength_587000_312792 = 1065353216;
	nox_xxx_warriorMaxSpeed_587000_312796 = 1065353216;
	nox_xxx_conjurerMaxHealth_587000_312800 = 1077936128;
	nox_xxx_conjurerMaxMana_587000_312804 = 1077936128;
	nox_xxx_conjurerStrength_587000_312808 = 1065353216;
	nox_xxx_conjurerSpeed_587000_312812 = 1065353216;
	nox_xxx_wizardMaxHealth_587000_312816 = 1077936128;
	nox_xxx_wizardMaximumMana_587000_312820 = 1077936128;
	nox_xxx_wizardStrength_587000_312824 = 1065353216;
	nox_xxx_wizardSpeed_587000_312828 = 1065353216;
	nox_xxx_loadBaseValues_57B200();
	result = nox_xxx_getFirstPlayerUnit_4DA7C0();
	for (i = result; result; i = result) {
		nox_xxx_plrReadVals_4EEDC0(i, 0);
		nox_xxx_netStatsMultiplier_4D9C20(i);
		result = nox_xxx_getNextPlayerUnit_4DA7F0(i);
	}
	return result;
}

//----- (004D6B10) --------------------------------------------------------
int sub_4D6B10(int a1) {
	int result; // eax
	int i;      // esi

	nox_xxx_warriorMaxHealth_587000_312784 = *getMemU32Ptr(0x5D4594, 1556076);
	nox_xxx_warriorMaxMana_587000_312788 = *getMemU32Ptr(0x5D4594, 1556084);
	nox_xxx_warriorMaxStrength_587000_312792 = *getMemU32Ptr(0x5D4594, 1556064);
	nox_xxx_warriorMaxSpeed_587000_312796 = *getMemU32Ptr(0x5D4594, 1556072);
	nox_xxx_conjurerMaxHealth_587000_312800 = *getMemU32Ptr(0x5D4594, 1556060);
	nox_xxx_conjurerMaxMana_587000_312804 = *getMemU32Ptr(0x5D4594, 1556096);
	nox_xxx_conjurerStrength_587000_312808 = *getMemU32Ptr(0x5D4594, 1550932);
	nox_xxx_conjurerSpeed_587000_312812 = *getMemU32Ptr(0x5D4594, 1556080);
	nox_xxx_wizardMaxHealth_587000_312816 = *getMemU32Ptr(0x5D4594, 1556088);
	nox_xxx_wizardMaximumMana_587000_312820 = *getMemU32Ptr(0x5D4594, 1556068);
	nox_xxx_wizardStrength_587000_312824 = *getMemU32Ptr(0x5D4594, 1556100);
	nox_xxx_wizardSpeed_587000_312828 = *getMemU32Ptr(0x5D4594, 1556092);
	nox_xxx_loadBaseValues_57B200();
	result = nox_xxx_getFirstPlayerUnit_4DA7C0();
	for (i = result; result; i = result) {
		nox_xxx_plrReadVals_4EEDC0(i, 0);
		if (a1) {
			nox_xxx_netStatsMultiplier_4D9C20(i);
		}
		result = nox_xxx_getNextPlayerUnit_4DA7F0(i);
	}
	return result;
}

//----- (004D6BE0) --------------------------------------------------------
int sub_4D6BE0() {
	int result; // eax

	*getMemU32Ptr(0x5D4594, 1556076) = nox_xxx_warriorMaxHealth_587000_312784;
	*getMemU32Ptr(0x5D4594, 1556084) = nox_xxx_warriorMaxMana_587000_312788;
	*getMemU32Ptr(0x5D4594, 1556064) = nox_xxx_warriorMaxStrength_587000_312792;
	*getMemU32Ptr(0x5D4594, 1556072) = nox_xxx_warriorMaxSpeed_587000_312796;
	*getMemU32Ptr(0x5D4594, 1556060) = nox_xxx_conjurerMaxHealth_587000_312800;
	*getMemU32Ptr(0x5D4594, 1556096) = nox_xxx_conjurerMaxMana_587000_312804;
	*getMemU32Ptr(0x5D4594, 1550932) = nox_xxx_conjurerStrength_587000_312808;
	result = nox_xxx_wizardMaximumMana_587000_312820;
	*getMemU32Ptr(0x5D4594, 1556080) = nox_xxx_conjurerSpeed_587000_312812;
	*getMemU32Ptr(0x5D4594, 1556088) = nox_xxx_wizardMaxHealth_587000_312816;
	*getMemU32Ptr(0x5D4594, 1556068) = nox_xxx_wizardMaximumMana_587000_312820;
	*getMemU32Ptr(0x5D4594, 1556100) = nox_xxx_wizardStrength_587000_312824;
	*getMemU32Ptr(0x5D4594, 1556092) = nox_xxx_wizardSpeed_587000_312828;
	return result;
}

//----- (004D6C70) --------------------------------------------------------
int nox_server_setupQuestGame_4D6C70() {
	int* v0;               // ebp
	int v3;                // edi
	int v4;                // ebx
	int v5;                // eax
	int v6;                // esi
	int v7;                // eax
	int v8;                // eax
	char v9;               // al
	uint32_t* v10;         // esi
	int v11;               // eax
	int v12;               // eax
	char* v13;             // eax
	char* v14;             // edi
	wchar_t* v15;          // eax
	int j;                 // esi
	unsigned char v18[20]; // [esp+10h] [ebp-14h]

	nox_common_gameFlags_unset_40A540(6128);
	nox_xxx_setGameFlags_40A4D0(4096);
	v0 = 0;
	if (!sub_4D6F30()) {
		nox_game_setQuestStage_4E3CD0(0);
	}
	sub_4D0F30();
	nox_common_resetEngineFlag(NOX_ENGINE_FLAG_ADMIN);
	nox_common_gameFlags_unset_40A540(0x10000);
	sub_4D9CF0(255);
	for (int i = nox_xxx_getFirstPlayerUnit_4DA7C0(); i; i = nox_xxx_getNextPlayerUnit_4DA7F0(i)) {
		*(uint32_t*)(*(uint32_t*)(*(uint32_t*)(i + 748) + 276) + 4792) = 0;
	}
	v3 = nox_xxx_getFirstPlayerUnit_4DA7C0();
	if (v3) {
		while (1) {
			sub_4D6000(v3);
			v4 = *(uint32_t*)(v3 + 748);
			if (nox_common_gameFlags_check_40A5C0(1) &&
				nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) &&
				(v5 = *(uint32_t*)(v4 + 276), *(uint8_t*)(v5 + 2064) == 31)) {
				*(uint32_t*)(v5 + 4792) = v0;
			} else {
				*(uint32_t*)(*(uint32_t*)(v4 + 276) + 4792) = sub_4E4100();
			}
			if (*(uint32_t*)(*(uint32_t*)(v4 + 276) + 4792) == 1) {
				sub_4D9D20(255, v3);
			}
			nox_xxx_unitInitPlayer_4EFE80(v3);
			nox_xxx_playerSubGold_4FA5D0(v3, *(uint32_t*)(*(uint32_t*)(v4 + 276) + 2164));
			v6 = *(uint32_t*)(v3 + 504);
			if ((int*)v6 != v0) {
				while (1) {
					v7 = *(uint32_t*)(v6 + 8);
					v0 = *(int**)(v6 + 496);
					if (!(v7 & 0x1000000)) {
						if (!(!(v7 & 0x2000000) || sub_415D10((char*)*(unsigned short*)(v6 + 4)) & 0x405)) {
							nox_xxx_delayedDeleteObject_4E5CC0(v6);
						}
					} else {
						v8 = *(uint32_t*)(v6 + 12);
						if (v8 & 0x8200) {
							nox_xxx_delayedDeleteObject_4E5CC0(v6);
						}
					}
					v6 = (int)v0;
					if (!v0) {
						break;
					}
				}
			}
			v9 = *(uint8_t*)(*(uint32_t*)(v4 + 276) + 2251);
			if (v9) {
				if (v9 == 1) {
					v10 = nox_xxx_playerRespawnItem_4EF750(v3, "SulphorousFlareWand", v0, 1, 1);
					*(uint32_t*)v18 = v0;
					*(uint32_t*)&v18[4] = v0;
					v11 = nox_xxx_modifGetIdByName_413290("Replenishment1");
					*(uint32_t*)&v18[8] = nox_xxx_modifGetDescById_413330(v11);
					*(uint32_t*)&v18[12] = v0;
					*(uint16_t*)&v18[16] = (uint16_t)v0;
					*(uint16_t*)&v18[18] = (uint16_t)v0;
					nox_xxx_modifSetItemAttrs_4E4990((int)v10, (int*)v18);
				} else if (v9 == 2) {
					nox_xxx_playerRespawnItem_4EF750(v3, "Bow", v0, 1, 1);
				}
			} else {
				nox_xxx_playerRespawnItem_4EF750(v3, "Sword", v0, 1, 1);
			}
			v12 = *(uint32_t*)(v4 + 276);
			if (*(int**)(v12 + 4792) == v0) {
				nox_xxx_playerGoObserver_4E6860(v12, (char)v0, (int)v0);
			}
			v3 = nox_xxx_getNextPlayerUnit_4DA7F0(v3);
			if ((int*)v3 == v0) {
				break;
			}
		}
	}
	nox_xxx_SetGameplayFlag_417D50(4);
	sub_419030(1);
	v13 = nox_xxx_teamCreate_4186D0((char)v0);
	v14 = v13;
	v13[56] = 9;
	v15 = sub_418C20(9);
	if (v15 != (wchar_t*)v0) {
		sub_418800((wchar_t*)v14, v15, 1);
	}
	sub_4184D0((wchar_t*)v14);
	for (j = nox_xxx_getFirstPlayerUnit_4DA7C0(); (int*)j != v0; j = nox_xxx_getNextPlayerUnit_4DA7F0(j)) {
		if (*(uint32_t*)(*(uint32_t*)(*(uint32_t*)(j + 748) + 276) + 4792) == 1) {
			nox_xxx_createAtImpl_4191D0(v14[57], j + 48, 1, *(uint32_t*)(j + 36), (int)v0);
		}
	}
	sub_4D6BE0();
	return sub_4D6A60();
}

//----- (004D6F30) --------------------------------------------------------
int sub_4D6F30() { return *getMemU32Ptr(0x5D4594, 1556156); }

//----- (004D6F40) --------------------------------------------------------
int sub_4D6F40(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 1556156) = a1;
	return result;
}

//----- (004D6F50) --------------------------------------------------------
int nox_xxx_isQuest_4D6F50() { return *getMemU32Ptr(0x5D4594, 1556160); }

//----- (004D6F60) --------------------------------------------------------
int nox_xxx_setQuest_4D6F60(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 1556160) = a1;
	return result;
}

//----- (004D6F70) --------------------------------------------------------
int sub_4D6F70() { return *getMemU32Ptr(0x5D4594, 1556164); }

//----- (004D6F80) --------------------------------------------------------
int sub_4D6F80(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 1556164) = a1;
	return result;
}

//----- (004D6F90) --------------------------------------------------------
int sub_4D6F90(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 1556104) = a1;
	return result;
}

//----- (004D6FA0) --------------------------------------------------------
int sub_4D6FA0() { return *getMemU32Ptr(0x5D4594, 1556104); }

//----- (004D6FB0) --------------------------------------------------------
int nox_xxx_setQuestFlag_4D6FB0(int f) {
	nox_xxx_questFlag_1556148 = f;
	return f;
}

//----- (004D6FC0) --------------------------------------------------------
int nox_xxx_getQuestFlag_4D6FC0() { return nox_xxx_questFlag_1556148; }

//----- (004D7080) --------------------------------------------------------
int nox_server_conCmdHandler_startSoloQuest_4D7080() {
	nox_client_gui_flag_1556112 = 1;
	nox_xxx_cliPlayMapIntro_44E0B0(1);
	*getMemU32Ptr(0x5D4594, 1556152) = sub_416A00();
	sub_4169E0();
	return nox_xxx_setQuestFlag_4D6FB0(30);
}

//----- (004D70B0) --------------------------------------------------------
char* sub_4D70B0() {
	char* result; // eax

	result = *(char**)getMemAt(0x5D4594, 1556152);
	if (!*getMemU32Ptr(0x5D4594, 1556152)) {
		result = sub_4169F0();
	}
	return result;
}

//----- (004D70C0) --------------------------------------------------------
int nox_xxx_bookCreatureTest_4D70C0(int a1) {
	return nox_common_gameFlags_check_40A5C0(4096) || a1 != 37 && a1 != 38 && a1 != 40 && a1 != 39;
}

//----- (004D7100) --------------------------------------------------------
int sub_4D7100(int a1) {
	return nox_common_gameFlags_check_40A5C0(4096) || a1 != 111 && a1 != 112 && a1 != 114 && a1 != 113;
}

//----- (004D7150) --------------------------------------------------------
int sub_4D7150() {
	int result; // eax
	int i;      // edi
	int* v2;    // esi
	int v3;     // eax

	result = dword_5d4594_1556144;
	if (dword_5d4594_1556144) {
		if (nox_frame_xxx_2598000 > *(int*)&dword_5d4594_1556144) {
			result = nox_xxx_getFirstPlayerUnit_4DA7C0();
			for (i = result; result; i = result) {
				v2 = *(int**)(i + 748);
				v3 = v2[69];
				if ((*(uint8_t*)(v3 + 3680) & 1) == 1 && *(uint32_t*)(v3 + 4792) == 1 && !v2[78] && !v2[79] &&
					(*(uint32_t*)(v3 + 3680) & 0x10) == 16) {
					sub_4DF3C0(v2[69]);
					nox_xxx_playerLeaveObserver_0_4E6AA0(v2[69]);
					nox_xxx_playerCameraUnlock_4E6040(i);
				}
				result = nox_xxx_getNextPlayerUnit_4DA7F0(i);
			}
		}
	}
	return result;
}

//----- (004D71E0) --------------------------------------------------------
int sub_4D71E0(int a1) {
	int result; // eax

	result = a1;
	dword_5d4594_1556136 = a1;
	return result;
}

//----- (004D71F0) --------------------------------------------------------
unsigned int sub_4D71F0() {
	unsigned int result; // eax
	int v1;              // esi
	char v2;             // al

	result = dword_5d4594_1556136;
	if (dword_5d4594_1556136) {
		if ((unsigned int)(nox_frame_xxx_2598000 - dword_5d4594_1556136) >= 0x2328) {
			v1 = 0;
			result = nox_xxx_getFirstPlayerUnit_4DA7C0();
			if (result) {
				do {
					if (*(uint32_t*)(*(uint32_t*)(result + 748) + 308)) {
						v1 = 1;
					}
					result = nox_xxx_getNextPlayerUnit_4DA7F0(result);
				} while (result);
				if (v1) {
					result = nox_xxx_player_4E3CE0();
					if (result > 1) {
						sub_4D71E0(0);
						result = sub_4D72C0();
						if (!result) {
							sub_4D72B0(1);
							v2 = sub_4D72C0();
							result = sub_4D7280(255, v2);
						}
					}
				}
			}
		}
	}
	return result;
}

//----- (004D7280) --------------------------------------------------------
int sub_4D7280(int a1, char a2) {
	char v4[3]; // [esp+0h] [ebp-4h]
	v4[0] = -16;
	v4[1] = 24;
	v4[2] = a2;
	return nox_xxx_netSendPacket1_4E5390(a1, (int)v4, 3, 0, 1);
}

//----- (004D72B0) --------------------------------------------------------
int sub_4D72B0(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 1556140) = a1;
	return result;
}

//----- (004D72C0) --------------------------------------------------------
int sub_4D72C0() { return *getMemU32Ptr(0x5D4594, 1556140); }

//----- (004D72D0) --------------------------------------------------------
int sub_4D72D0(int a1) {
	int result; // eax

	result = dword_5d4594_1556128;
	*getMemU32Ptr(0x5D4594, 1556132) = dword_5d4594_1556128;
	dword_5d4594_1556128 = a1;
	return result;
}

//----- (004D72F0) --------------------------------------------------------
int sub_4D72F0() { return dword_5d4594_1556128; }

//----- (004D7300) --------------------------------------------------------
int sub_4D7300() { return *getMemU32Ptr(0x5D4594, 1556132); }

//----- (004D7310) --------------------------------------------------------
int sub_4D7310() {
	int v0; // ebx
	int v1; // ebp
	int v2; // esi
	int v3; // edi
	int i;  // eax

	v0 = 0;
	v1 = 99999;
	v2 = nox_xxx_getFirstPlayerUnit_4DA7C0();
	if (!v2) {
		return 0;
	}
	do {
		if (*(uint32_t*)(*(uint32_t*)(*(uint32_t*)(v2 + 748) + 276) + 4792) == 1) {
			v3 = 0;
			for (i = nox_xxx_inventoryGetFirst_4E7980(v2); i; i = nox_xxx_inventoryGetNext_4E7990(i)) {
				if (*(uint8_t*)(i + 8) & 0x40) {
					++v3;
				}
			}
			if (v3 <= v1) {
				v1 = v3;
				v0 = v2;
			}
		}
		v2 = nox_xxx_getNextPlayerUnit_4DA7F0(v2);
	} while (v2);
	return v0;
}

//----- (004D7390) --------------------------------------------------------
void sub_4D7390(int a1) {
	int v1; // esi
	int v2; // ebx
	int v3; // edi

	if (a1) {
		if (nox_xxx_player_4E3CE0()) {
			v1 = nox_xxx_inventoryGetFirst_4E7980(a1);
			if (v1) {
				do {
					v2 = nox_xxx_inventoryGetNext_4E7990(v1);
					if (*(uint8_t*)(v1 + 8) & 0x40) {
						v3 = sub_4D7310();
						if (v3) {
							sub_4ED0C0(a1, (int*)v1);
							nox_xxx_inventoryPutImpl_4F3070(v3, v1, 1);
							nox_xxx_netPriMsgToPlayer_4DA2C0(v3, "GeneralPrint:GainedKey", 0);
							nox_xxx_aud_501960(820, v3, 0, 0);
						}
					}
					v1 = v2;
				} while (v2);
			}
			sub_4EDD00(a1, 64);
		} else {
			sub_4EDD00(a1, 64);
		}
	}
}

//----- (004D7430) --------------------------------------------------------
int sub_4D7430() { return *getMemU32Ptr(0x5D4594, 1556116); }

//----- (004D7440) --------------------------------------------------------
int sub_4D7440(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 1556116) = a1;
	return result;
}

//----- (004D7450) --------------------------------------------------------
int sub_4D7450(int a1, short a2) {
	char v3[4]; // [esp+0h] [ebp-4h]

	v3[0] = -16;
	v3[1] = 29;
	*(uint16_t*)&v3[2] = a2;
	return nox_xxx_netSendPacket0_4E5420(a1, v3, 4, 0, 1);
}

//----- (004D7480) --------------------------------------------------------
void sub_4D7480(int a1) {
	int v1;     // edi
	int v2;     // eax
	float2* v3; // ebx

	if (a1 && *(uint8_t*)(a1 + 8) & 4) {
		v1 = *(uint32_t*)(a1 + 748);
		v2 = *(uint32_t*)(v1 + 316);
		if (v2) {
			v3 = *(float2**)(v2 + 700);
			nox_xxx_playerLeaveObserver_0_4E6AA0(*(uint32_t*)(v1 + 276));
			nox_xxx_playerCameraUnlock_4E6040(a1);
			*(uint32_t*)(v1 + 316) = 0;
			nox_xxx_unitMove_4E7010(a1, v3 + 10);
			nox_xxx_aud_501960(312, a1, 2, *(uint32_t*)(a1 + 36));
			nox_xxx_netSendPointFx_522FF0(129, v3 + 10);
		}
	}
}

//----- (004D74F0) --------------------------------------------------------
#ifndef NOX_CGO
int nox_server_questNextStageThreshold_4D74F0(int lvl) {
	if (lvl <= 4) {
		return 5;
	}
	if (lvl <= 9) {
		return 10;
	}
	if (lvl <= 14) {
		return 15;
	}
	if (lvl <= 19) {
		return 20;
	}
	return lvl;
}
#endif // NOX_CGO

//----- (004D7520) --------------------------------------------------------
char sub_4D7520(int a1) {
	int v1; // eax
	int i;  // esi
	int v3; // eax
	int v4; // esi
	int v5; // edi

	LOBYTE(v1) = getMemByte(0x5D4594, 1556120);
	if (*getMemU32Ptr(0x5D4594, 1556120) == 1) {
		if (a1) {
			goto LABEL_19;
		}
		for (i = nox_xxx_getFirstPlayerUnit_4DA7C0(); i; i = nox_xxx_getNextPlayerUnit_4DA7F0(i)) {
			v3 = *(uint32_t*)(i + 748);
			if (*(uint32_t*)(*(uint32_t*)(v3 + 276) + 4792) && *(uint32_t*)(v3 + 316)) {
				sub_4D7480(i);
			}
		}
		v1 = nox_server_getFirstObject_4DA790();
		v4 = v1;
		if (!v1) {
		LABEL_19:
			*getMemU32Ptr(0x5D4594, 1556120) = a1;
		} else {
			do {
				v5 = nox_server_getNextObject_4DA7A0(v4);
				LOBYTE(v1) = *(uint8_t*)(v4 + 8);
				if (v1 & 0x20 && *(uint8_t*)(v4 + 12) & 2) {
					LOBYTE(v1) = nox_xxx_objectSetOff_4E7600(v4);
				}
				v4 = v5;
			} while (v5);
			*getMemU32Ptr(0x5D4594, 1556120) = 0;
		}
	} else {
		*getMemU32Ptr(0x5D4594, 1556120) = a1;
	}
	return v1;
}

//----- (004D75E0) --------------------------------------------------------
int sub_4D75E0() { return *getMemU32Ptr(0x5D4594, 1556120); }

//----- (004D75F0) --------------------------------------------------------
int sub_4D75F0(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 1556108) = a1;
	return result;
}

//----- (004D7600) --------------------------------------------------------
void nox_server_checkWarpGate_4D7600() {
	int exp = nox_xxx_player_4E3CE0();
	if (!exp) {
		return;
	}
	if ((unsigned int)(nox_frame_xxx_2598000 - *getMemU32Ptr(0x5D4594, 1556108)) < 30) {
		return;
	}
	int inGate = 0;
	for (void* unit = nox_xxx_getFirstPlayerUnit_4DA7C0(); unit; unit = nox_xxx_getNextPlayerUnit_4DA7F0(unit)) {
		int v3 = *(uint32_t*)((int)unit + 748);
		if (*(uint32_t*)(*(uint32_t*)(v3 + 276) + 4792) && *(uint32_t*)(v3 + 316)) {
			++inGate;
		}
	}
	if (exp != inGate) {
		// not all players are in the gate
		return;
	}
	if (!nox_server_questMaybeWarp_4E8F60()) {
		// warp failed
		for (void* unit = nox_xxx_getFirstPlayerUnit_4DA7C0(); unit; unit = nox_xxx_getNextPlayerUnit_4DA7F0(unit)) {
			int v5 = *(uint32_t*)((int)unit + 748);
			if (*(uint32_t*)(*(uint32_t*)(v5 + 276) + 4792) && *(uint32_t*)(v5 + 316)) {
				sub_4D7480(unit);
				if (exp <= 1) {
					nox_xxx_netPriMsgToPlayer_4DA2C0(unit, "Gauntlet.c:WarpRestrictedSolo", 0);
				} else {
					nox_xxx_netPriMsgToPlayer_4DA2C0(unit, "Gauntlet.c:WarpRestrictedMulti", 0);
				}
			}
		}
	}
}

//----- (004D76E0) --------------------------------------------------------
int sub_4D76E0(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 1556124) = a1;
	return result;
}

//----- (004D76F0) --------------------------------------------------------
int sub_4D76F0() { return *getMemU32Ptr(0x5D4594, 1556124); }

//----- (004D7700) --------------------------------------------------------
bool nox_client_checkQuestExp_SKU2_4D7700() {
	return true; // License checks, we just allow it
#if 0
	HKEY phkResult;   // [esp+8h] [ebp-90h]
	uint8_t Data[4];     // [esp+Ch] [ebp-8Ch]
	uint32_t cbData;     // [esp+10h] [ebp-88h]
	uint32_t Type;       // [esp+14h] [ebp-84h]
	char SubKey[128]; // [esp+18h] [ebp-80h]

	strcpy(SubKey, "SOFTWARE\\Westwood\\Nox");
	*(uint32_t*)Data = -1;
	cbData = 4;
	if (!RegOpenKeyExA(HKEY_LOCAL_MACHINE, SubKey, 0, 0xF003Fu, &phkResult)) {
		RegQueryValueExA(phkResult, "SKU", 0, &Type, Data, &cbData);
		RegCloseKey(phkResult);
	}
	return *(uint32_t*)Data >= 9472;
#endif
}

//----- (004D7790) --------------------------------------------------------
int nox_xxx_checkAccessToGLava_4D7790() {
	char* v0;            // eax
	char FileName[1024]; // [esp+0h] [ebp-400h]

	v0 = nox_fs_root();
	nox_sprintf(FileName, "%s\\Maps\\G_Lava", v0);
	return _access(FileName, 0) == 0;
}

//----- (004D77D0) --------------------------------------------------------
int sub_4D77D0(int a1) {
	int result;       // eax
	uint8_t Data[4];  // [esp+0h] [ebp-88h]
	HKEY phkResult;   // [esp+4h] [ebp-84h]
	char SubKey[128]; // [esp+8h] [ebp-80h]

	result = a1 - 4096;
	switch (a1) {
	case 4096:
		*(uint32_t*)Data = 9472;
		goto LABEL_8;
	case 4098:
		*(uint32_t*)Data = 9474;
		goto LABEL_8;
	case 4099:
		*(uint32_t*)Data = 9475;
		goto LABEL_8;
	case 4101:
		*(uint32_t*)Data = 9477;
		goto LABEL_8;
	case 4102:
		*(uint32_t*)Data = 9478;
		goto LABEL_8;
	case 4105:
		*(uint32_t*)Data = 9481;
	LABEL_8:
		strcpy(SubKey, "SOFTWARE\\Westwood\\Nox");
		result = RegOpenKeyExA(HKEY_LOCAL_MACHINE, SubKey, 0, 0xF003Fu, &phkResult);
		if (!result) {
			RegSetValueExA(phkResult, "SKU", 0, 4u, Data, 4u);
			result = RegCloseKey(phkResult);
		}
		break;
	default:
		return result;
	}
	return result;
}

//----- (004D78C0) --------------------------------------------------------
int nox_common_readSKU_fromRegistry_4D78C0() {
	int result;       // eax
	uint8_t Data[4];  // [esp+8h] [ebp-90h]
	HKEY phkResult;   // [esp+Ch] [ebp-8Ch]
	uint32_t cbData;  // [esp+10h] [ebp-88h]
	uint32_t Type;    // [esp+14h] [ebp-84h]
	char SubKey[128]; // [esp+18h] [ebp-80h]

	strcpy(SubKey, "SOFTWARE\\Westwood\\Nox");
	*(uint32_t*)Data = -1;
	cbData = 4;
	result = RegOpenKeyExA(HKEY_LOCAL_MACHINE, SubKey, 0, 0xF003Fu, &phkResult);
	if (!result) {
		RegQueryValueExA(phkResult, "SKU", 0, &Type, Data, &cbData);
		result = RegCloseKey(phkResult);
	}
	if (*(int*)Data < 9472) {
		result = nox_xxx_checkAccessToGLava_4D7790();
		if (result == 1) {
			result = sub_4D77D0(*(int*)Data);
		}
	}
	return result;
}

//----- (004D7960) --------------------------------------------------------
int nox_xxx_player_4D7960(char a1) {
	int result; // eax

	result = 1 << a1;
	*getMemU32Ptr(0x5D4594, 1556300) |= 1 << a1;
	return result;
}

//----- (004D7980) --------------------------------------------------------
int nox_xxx_player_4D7980(char a1) { return (*getMemU32Ptr(0x5D4594, 1556300) & (1 << a1)) != 0; }

//----- (004D79A0) --------------------------------------------------------
int sub_4D79A0(char a1) {
	int result; // eax

	result = ~(1 << a1);
	*getMemU32Ptr(0x5D4594, 1556300) &= result;
	return result;
}

//----- (004D79C0) --------------------------------------------------------
int sub_4D79C0(int a1) {
	int v1;     // esi
	int result; // eax
	int v3;     // ecx

	v1 = *(uint32_t*)(a1 + 748);
	sub_4D9D20(255, a1);
	sub_4D6000(a1);
	for (result = nox_xxx_getFirstPlayerUnit_4DA7C0(); result; result = nox_xxx_getNextPlayerUnit_4DA7F0(result)) {
		v3 = *(uint32_t*)(result + 748);
		*(uint8_t*)(*(unsigned char*)(*(uint32_t*)(v1 + 276) + 2064) + v3 + 452) = 0;
		*(uint32_t*)(v3 + 4 * *(unsigned char*)(*(uint32_t*)(v1 + 276) + 2064) + 324) = 0;
		*(uint8_t*)(*(unsigned char*)(*(uint32_t*)(v1 + 276) + 2064) + v3 + 484) = 0;
		*(uint8_t*)(*(unsigned char*)(*(uint32_t*)(v1 + 276) + 2064) + v3 + 516) = 0;
	}
	return result;
}

//----- (004D7A60) --------------------------------------------------------
int sub_4D7A60(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 1556172 + 4 * a1) = nox_frame_xxx_2598000;
	return result;
}

//----- (004D7A80) --------------------------------------------------------
int sub_4D7A80() {
	unsigned char* v0; // ebp
	int v1;            // edi
	int v2;            // esi
	char* v3;          // eax
	int v4;            // eax
	int v5;            // edi
	int v6;            // ecx
	int result;        // eax

	v0 = getMemAt(0x5D4594, 1556172);
	v1 = 324 - (uint32_t)getMemAt(0x5D4594, 1556172);
	v2 = 484;
	do {
		v3 = nox_common_playerInfoFromNum_417090(v2 - 484);
		if (v3 && *((uint32_t*)v3 + 523) && *((uint32_t*)v3 + 514) && *((uint32_t*)v3 + 1198) == 1) {
			goto LABEL_12;
		}
		if (*(uint32_t*)v0 && nox_frame_xxx_2598000 - *(uint32_t*)v0 > (unsigned int)(30 * nox_gameFPS)) {
			v4 = nox_xxx_getFirstPlayerUnit_4DA7C0();
			if (v4) {
				v5 = (int)&v0[v1];
				do {
					v6 = *(uint32_t*)(v4 + 748);
					*(uint8_t*)(v2 + v6 - 32) = 0;
					*(uint32_t*)(v5 + v6) = 0;
					*(uint8_t*)(v2 + v6) = 0;
					*(uint8_t*)(v2 + v6 + 32) = 0;
					v4 = nox_xxx_getNextPlayerUnit_4DA7F0(v4);
				} while (v4);
				v1 = 324 - (uint32_t)getMemAt(0x5D4594, 1556172);
			}
		LABEL_12:
			*(uint32_t*)v0 = 0;
		}
		++v2;
		v0 += 4;
		result = v2 - 484;
	} while (v2 - 484 < 32);
	return result;
}

//----- (004D7B40) --------------------------------------------------------
int sub_4D7B40() {
	int result; // eax

	result = 0;
	memset(getMemAt(0x5D4594, 1556172), 0, 0x80u);
	return result;
}

//----- (004D7B60) --------------------------------------------------------
int sub_4D7B60(int a1) {
	int result; // eax
	int i;      // esi
	char v3[7]; // [esp+4h] [ebp-8h]

	v3[0] = -46;
	*(uint16_t*)&v3[1] = nox_xxx_netGetUnitCodeServ_578AC0((uint32_t*)a1);
	*(uint16_t*)&v3[3] = *(uint16_t*)(a1 + 4);
	v3[5] = 1;
	v3[6] = 2;
	result = nox_xxx_getFirstPlayerUnit_4DA7C0();
	for (i = result; result; i = result) {
		nox_xxx_netSendPacket0_4E5420(*(unsigned char*)(*(uint32_t*)(*(uint32_t*)(i + 748) + 276) + 2064), v3, 7, 0, 1);
		result = nox_xxx_getNextPlayerUnit_4DA7F0(i);
	}
	return result;
}

//----- (004D7BE0) --------------------------------------------------------
int nox_xxx_netSendInterestingId_4D7BE0(int a1) {
	int result; // eax
	int i;      // esi
	char v3[7]; // [esp+4h] [ebp-8h]

	v3[0] = -46;
	*(uint16_t*)&v3[1] = nox_xxx_netGetUnitCodeServ_578AC0((uint32_t*)a1);
	*(uint16_t*)&v3[3] = *(uint16_t*)(a1 + 4);
	v3[5] = 2;
	v3[6] = 2;
	result = nox_xxx_getFirstPlayerUnit_4DA7C0();
	for (i = result; result; i = result) {
		nox_xxx_netSendPacket0_4E5420(*(unsigned char*)(*(uint32_t*)(*(uint32_t*)(i + 748) + 276) + 2064), v3, 7, 0, 1);
		result = nox_xxx_getNextPlayerUnit_4DA7F0(i);
	}
	return result;
}

//----- (004D7C60) --------------------------------------------------------
int sub_4D7C60() {
	int result; // eax
	float v1;   // [esp+0h] [ebp-4h]
	float v2;   // [esp+0h] [ebp-4h]

	dword_5d4594_1556316 = 0;
	*getMemFloatPtr(0x5D4594, 1556308) = nox_xxx_gamedataGetFloat_419D40("CamperRadiusSq");
	v1 = nox_xxx_gamedataGetFloat_419D40("CamperStartTime");
	*getMemU32Ptr(0x5D4594, 1556312) = nox_float2int(v1);
	v2 = nox_xxx_gamedataGetFloat_419D40("CamperFadeTime");
	result = nox_float2int(v2);
	*getMemU32Ptr(0x5D4594, 1556304) = result;
	return result;
}

//----- (004D7CC0) --------------------------------------------------------
int sub_4D7CC0() {
	int result;   // eax
	int i;        // ecx
	int v2;       // edx
	double v3;    // st7
	double v4;    // st6
	int j;        // esi
	uint32_t* v6; // edi
	int v7;       // eax

	nox_platform_get_ticks();
	result = sub_409F40(0x2000);
	if (result) {
		if ((unsigned int)(nox_frame_xxx_2598000 - dword_5d4594_1556316) > *getMemIntPtr(0x5D4594, 1556312)) {
			for (i = nox_xxx_getFirstPlayerUnit_4DA7C0(); i; i = nox_xxx_getNextPlayerUnit_4DA7F0(i)) {
				if (!(*(uint32_t*)(i + 16) & 0x8020)) {
					v2 = *(uint32_t*)(i + 748);
					if (!(*(uint8_t*)(*(uint32_t*)(v2 + 276) + 3680) & 1)) {
						v3 = *(float*)(i + 60) - *(float*)(v2 + 252);
						v4 = *(float*)(i + 56) - *(float*)(v2 + 248);
						if (v4 * v4 + v3 * v3 < *getMemFloatPtr(0x5D4594, 1556308)) {
							*(uint32_t*)(v2 + 256) = nox_frame_xxx_2598000;
						}
						*(uint32_t*)(v2 + 248) = *(uint32_t*)(i + 56);
						*(uint32_t*)(v2 + 252) = *(uint32_t*)(i + 60);
					}
				}
			}
			dword_5d4594_1556316 = nox_frame_xxx_2598000;
		}
		result = nox_xxx_getFirstPlayerUnit_4DA7C0();
		for (j = result; result; j = result) {
			if (!(*(uint32_t*)(j + 16) & 0x8020)) {
				v6 = *(uint32_t**)(j + 748);
				if (!(*(uint8_t*)(v6[69] + 3680) & 1)) {
					v7 = v6[65];
					if ((unsigned int)(dword_5d4594_1556316 - v6[64]) > *getMemIntPtr(0x5D4594, 1556304)) {
						if (v7) {
							nox_xxx_netSendInterestingId_4D7BE0(j);
							v6[65] = 0;
						}
					} else if (!v7) {
						if (!nox_common_gameFlags_check_40A5C0(32) || *(uint8_t*)(v6[69] + 4) & 1) {
							nox_xxx_aud_501960(774, j, 0, 0);
						}
						sub_4D7B60(j);
						v6[65] = 1;
					}
				}
			}
			result = nox_xxx_getNextPlayerUnit_4DA7F0(j);
		}
	}
	return result;
}

//----- (004D7E50) --------------------------------------------------------
int sub_4D7E50(int a1) {
	int result;   // eax
	uint32_t* v2; // esi

	result = a1;
	if (*(uint8_t*)(a1 + 8) & 4) {
		v2 = *(uint32_t**)(a1 + 748);
		v2[62] = 0;
		v2[63] = 0;
		v2[64] = nox_frame_xxx_2598000;
		if (v2[65]) {
			result = nox_xxx_netSendInterestingId_4D7BE0(a1);
		}
		v2[65] = 0;
	}
	return result;
}

//----- (004D7EA0) --------------------------------------------------------
int sub_4D7EA0() {
	int result; // eax
	int i;      // esi

	result = nox_xxx_getFirstPlayerUnit_4DA7C0();
	for (i = result; result; i = result) {
		sub_4D7E50(i);
		result = nox_xxx_getNextPlayerUnit_4DA7F0(i);
	}
	return result;
}

//----- (004D7EE0) --------------------------------------------------------
int nox_xxx_netCreatureCmd_4D7EE0(int player, char orderType) {
	char buf[2]; // [esp+0h] [ebp-2h]

	buf[0] = -19;
	buf[1] = orderType;
	return nox_xxx_netSendPacket1_4E5390(player, (int)buf, 2, 0, 1);
}

//----- (004D7F10) --------------------------------------------------------
int nox_xxx_netNotifyRate_4D7F10(int a1) {
	char v2[2]; // [esp+0h] [ebp-2h]

	v2[0] = -20;
	v2[1] = nox_xxx_rateGet_40A6C0();
	return nox_xxx_netSendPacket1_4E5390(a1, (int)v2, 2, 0, 1);
}

//----- (004D7F40) --------------------------------------------------------
int nox_xxx_netReportObjectPoison_4D7F40(int a1, uint32_t* a2, char a3) {
	int v3; // esi

	v3 = *(uint32_t*)(a1 + 748);
	LOBYTE(a1) = -38;
	*(uint16_t*)((char*)&a1 + 1) = nox_xxx_netGetUnitCodeServ_578AC0(a2);
	HIBYTE(a1) = a3;
	return nox_xxx_netSendPacket0_4E5420(*(unsigned char*)(*(uint32_t*)(v3 + 276) + 2064), &a1, 4, 0, 1);
}

//----- (004D80C0) --------------------------------------------------------
int sub_4D80C0(int a1, char a2) {
	int result; // eax
	int v3;     // eax

	result = a1;
	if (*(uint8_t*)(a1 + 8) & 4) {
		v3 = *(uint32_t*)(a1 + 748);
		LOBYTE(a1) = -21;
		BYTE1(a1) = a2;
		result = nox_xxx_netSendPacket0_4E5420(*(unsigned char*)(*(uint32_t*)(v3 + 276) + 2064), &a1, 2, 0, 1);
	}
	return result;
}

//----- (004D8100) --------------------------------------------------------
int nox_xxx_netAbilRepotState_4D8100(int a1, char a2, char a3) {
	int result; // eax
	int v4;     // edx

	result = a1;
	if (*(uint8_t*)(a1 + 8) & 4) {
		BYTE2(a1) = a3;
		v4 = *(uint32_t*)(result + 748);
		BYTE1(a1) = a2;
		LOBYTE(a1) = -50;
		result = nox_xxx_netSendPacket0_4E5420(*(unsigned char*)(*(uint32_t*)(v4 + 276) + 2064), &a1, 3, 0, 1);
	}
	return result;
}

//----- (004D8150) --------------------------------------------------------
int nox_xxx_netReportActiveAbils_4D8150(int a1, char a2, char a3) {
	int result; // eax
	int v4;     // edx

	result = a1;
	if (*(uint8_t*)(a1 + 8) & 4) {
		BYTE2(a1) = a3;
		v4 = *(uint32_t*)(result + 748);
		BYTE1(a1) = a2;
		LOBYTE(a1) = -49;
		result = nox_xxx_netSendPacket0_4E5420(*(unsigned char*)(*(uint32_t*)(v4 + 276) + 2064), &a1, 3, 0, 1);
	}
	return result;
}

//----- (004D81A0) --------------------------------------------------------
void sub_4D81A0(int a1) {
	double v1;  // st7
	int v2;     // ecx
	char v3[5]; // [esp+4h] [ebp-8h]

	if (*(uint8_t*)(a1 + 8) & 4) {
		v1 = *(float*)(a1 + 28);
		v3[0] = 110;
		v2 = *(uint32_t*)(a1 + 748);
		*(uint32_t*)&v3[1] = (long long)v1;
		nox_xxx_netSendPacket0_4E5420(*(unsigned char*)(*(uint32_t*)(v2 + 276) + 2064), v3, 5, 0, 1);
	}
}

//----- (004D81F0) --------------------------------------------------------
int nox_xxx_netReportAnimFrame_4D81F0(int a1, uint32_t* a2) {
	char v3[7]; // [esp+4h] [ebp-8h]

	v3[0] = 107;
	*(uint16_t*)&v3[1] = nox_xxx_netGetUnitCodeServ_578AC0(a2);
	*(uint32_t*)&v3[3] = a2[33];
	return nox_xxx_netSendPacket0_4E5420(a1, v3, 7, 0, 1);
}

//----- (004D8230) --------------------------------------------------------
int nox_xxx_netReportXStatus_4D8230(int a1, uint32_t* a2) {
	char v3[7]; // [esp+4h] [ebp-8h]

	v3[0] = 101;
	*(uint16_t*)&v3[1] = nox_xxx_netGetUnitCodeServ_578AC0(a2);
	*(uint32_t*)&v3[3] = a2[5];
	return nox_xxx_netSendPacket0_4E5420(a1, v3, 7, 0, 1);
}

//----- (004D8270) --------------------------------------------------------
int nox_xxx_netReportPlrStatus_4D8270(int a1) {
	int v1;     // ecx
	int v2;     // eax
	char v4[5]; // [esp+0h] [ebp-8h]

	v1 = *(uint32_t*)(a1 + 16);
	v2 = *(uint32_t*)(a1 + 748);
	v4[0] = 102;
	*(uint32_t*)&v4[1] = v1;
	return nox_xxx_netSendPacket0_4E5420(*(unsigned char*)(*(uint32_t*)(v2 + 276) + 2064), v4, 5, 0, 1);
}

//----- (004D82B0) --------------------------------------------------------
int nox_xxx_netReportCharges_4D82B0(int a1, nox_object_t* item, char a3, char a4) {
	char v5[5]; // [esp+0h] [ebp-8h]

	v5[0] = 100;
	*(uint16_t*)&v5[1] = nox_xxx_netGetUnitCodeServ_578AC0(item);
	v5[3] = a3;
	v5[4] = a4;
	return nox_xxx_netSendPacket1_4E5390(a1, (int)v5, 5, 0, 0);
}

//----- (004D82F0) --------------------------------------------------------
uint32_t* sub_4D82F0(int a1, uint32_t* a2) {
	uint32_t* result; // eax
	int v3;           // ecx
	int v4;           // edi
	int v5;           // esi
	int v6;           // edx
	uint32_t* v7;     // ecx
	int v8;           // ecx
	int v9;           // eax
	int v10;          // edx
	int v11;          // ecx
	int v12;          // esi
	int v13;          // edx
	uint32_t* v14;    // ecx
	int v15;          // ecx
	int v16;          // eax
	int v17;          // edx
	int v18;          // ecx
	char v19[11];     // [esp+8h] [ebp-Ch]

	result = a2;
	v3 = a2[2];
	v4 = 0;
	if (v3 & 0x11001000) {
		v5 = a2[173];
		v6 = 4;
		v7 = (uint32_t*)a2[173];
		do {
			if (*v7) {
				v4 = 1;
			}
			++v7;
			--v6;
		} while (v6);
		if (v4) {
			v8 = a2[123];
			v19[0] = 81;
			*(uint16_t*)&v19[1] = *(uint16_t*)(v8 + 36);
			if (*(uint8_t*)(v8 + 8) & 4) {
				v19[2] |= 0x80u;
			}
			*(uint32_t*)&v19[3] = nox_xxx_weaponInventoryEquipFlags_415820((int)a2);
			v9 = 0;
			v10 = v5;
			do {
				if (*(uint32_t*)v10) {
					v19[v9 + 7] = *(uint8_t*)(*(uint32_t*)v10 + 4);
				} else {
					v19[v9 + 7] = -1;
				}
				++v9;
				v10 += 4;
			} while (v9 < 4);
			result = (uint32_t*)nox_xxx_netSendPacket1_4E5390(a1, (int)v19, 11, 0, 0);
		} else {
			v11 = a2[123];
			v19[0] = 80;
			*(uint16_t*)&v19[1] = *(uint16_t*)(v11 + 36);
			if (*(uint8_t*)(v11 + 8) & 4) {
				v19[2] |= 0x80u;
			}
			*(uint32_t*)&v19[3] = nox_xxx_weaponInventoryEquipFlags_415820((int)a2);
			result = (uint32_t*)nox_xxx_netSendPacket1_4E5390(a1, (int)v19, 7, 0, 0);
		}
	} else if (v3 & 0x2000000) {
		v12 = a2[173];
		v13 = 4;
		v14 = (uint32_t*)a2[173];
		do {
			if (*v14) {
				v4 = 1;
			}
			++v14;
			--v13;
		} while (v13);
		if (v4) {
			v15 = a2[123];
			v19[0] = 82;
			*(uint16_t*)&v19[1] = *(uint16_t*)(v15 + 36);
			if (*(uint8_t*)(v15 + 8) & 4) {
				v19[2] |= 0x80u;
			}
			*(uint32_t*)&v19[3] = nox_xxx_unitArmorInventoryEquipFlags_415C70((int)a2);
			v16 = 0;
			v17 = v12;
			do {
				if (*(uint32_t*)v17) {
					v19[v16 + 7] = *(uint8_t*)(*(uint32_t*)v17 + 4);
				} else {
					v19[v16 + 7] = -1;
				}
				++v16;
				v17 += 4;
			} while (v16 < 4);
			result = (uint32_t*)nox_xxx_netSendPacket1_4E5390(a1, (int)v19, 11, 0, 0);
		} else {
			v18 = a2[123];
			v19[0] = 79;
			*(uint16_t*)&v19[1] = *(uint16_t*)(v18 + 36);
			if (*(uint8_t*)(v18 + 8) & 4) {
				v19[2] |= 0x80u;
			}
			*(uint32_t*)&v19[3] = nox_xxx_unitArmorInventoryEquipFlags_415C70((int)a2);
			result = (uint32_t*)nox_xxx_netSendPacket1_4E5390(a1, (int)v19, 7, 0, 0);
		}
	}
	return result;
}

//----- (004D84C0) --------------------------------------------------------
int nox_xxx_netReportDequip_4D84C0(int a1, const nox_object_t* object) {
	int result; // eax
	int v3;     // ecx
	int v4;     // ecx
	int v5;     // eax
	int v6;     // ecx
	char v7[7]; // [esp+0h] [ebp-8h]

	result = object;
	v3 = object->obj_class;
	if (v3 & 0x11001000) {
		v4 = object->field_123;
		v7[0] = 84;
		*(uint16_t*)&v7[1] = *(uint16_t*)(v4 + 36);
		v5 = nox_xxx_weaponInventoryEquipFlags_415820(object);
	} else {
		if (!(v3 & 0x2000000)) {
			return result;
		}
		v6 = object->field_123;
		v7[0] = 83;
		*(uint16_t*)&v7[1] = *(uint16_t*)(v6 + 36);
		v5 = nox_xxx_unitArmorInventoryEquipFlags_415C70(object);
	}
	*(uint32_t*)&v7[3] = v5;
	return nox_xxx_netSendPacket1_4E5390(a1, (int)v7, 7, 0, 0);
}

//----- (004D8540) --------------------------------------------------------
uint32_t* nox_xxx_netReportEquip_4D8540(int a1, uint32_t* a2, int a3) {
	uint32_t* result; // eax
	char v4[3];       // [esp+4h] [ebp-4h]

	v4[0] = 96;
	*(uint16_t*)&v4[1] = nox_xxx_netGetUnitCodeServ_578AC0(a2);
	nox_xxx_netSendPacket1_4E5390(a1, (int)v4, 3, 0, 0);
	result = (uint32_t*)a3;
	if (a3) {
		result = sub_4D82F0(255, a2);
	}
	return result;
}

//----- (004D8590) --------------------------------------------------------
int nox_xxx_netReportDequip_4D8590(int a1, const nox_object_t* object) {
	uint32_t* a2 = object;
	char v4[3]; // [esp+0h] [ebp-4h]
	v4[0] = 97;
	*(uint16_t*)&v4[1] = nox_xxx_netGetUnitCodeServ_578AC0(a2);
	return nox_xxx_netSendPacket1_4E5390(a1, (int)v4, 3, 0, 0);
}

//----- (004D85C0) --------------------------------------------------------
int nox_xxx_netReportTotalHealth_4D85C0(int a1, uint32_t* a2) {
	int result;   // eax
	uint16_t* v3; // eax
	char v4[7];   // [esp+4h] [ebp-8h]

	result = a2[139];
	if (result) {
		v4[0] = -35;
		*(uint16_t*)&v4[1] = nox_xxx_netGetUnitCodeServ_578AC0(a2);
		v3 = (uint16_t*)a2[139];
		*(uint16_t*)&v4[3] = *v3;
		*(uint16_t*)&v4[5] = v3[2];
		result = nox_xxx_netSendPacket1_4E5390(a1, (int)v4, 7, 0, 1);
	}
	return result;
}

//----- (004D8620) --------------------------------------------------------
int nox_xxx_netReportUnitCurrentHP_4D8620(int a1, uint32_t* a2) {
	uint32_t* v2;    // esi
	int result;      // eax
	unsigned int v4; // ecx
	uint32_t* v5;    // [esp-4h] [ebp-8h]

	v2 = a2;
	result = a2[139];
	if (result) {
		v5 = a2;
		LOBYTE(a2) = 65;
		*(uint16_t*)((char*)&a2 + 1) = nox_xxx_netGetUnitCodeServ_578AC0(v5);
		LOWORD(v4) = *(uint16_t*)v2[139];
		HIBYTE(a2) = v4 >> 1;
		result = nox_xxx_netSendPacket1_4E5390(a1, (int)&a2, 4, 0, 1);
	}
	return result;
}
// 4D8656: variable 'v4' is possibly undefined

//----- (004D8670) --------------------------------------------------------
int nox_xxx_netSendTeam_4D8670(int a1, uint32_t* a2) {
	int result;         // eax
	short v3;           // ax
	unsigned short* v4; // ecx
	char v5[5];         // [esp+4h] [ebp-8h]

	result = a2[139];
	if (result) {
		v5[0] = -60;
		v5[1] = 12;
		v3 = nox_xxx_netGetUnitCodeServ_578AC0(a2);
		v4 = (unsigned short*)a2[139];
		*(uint16_t*)&v5[2] = v3;
		v5[4] = 100 * *v4 / v4[2];
		result = nox_xxx_netSendPacket1_4E5390(a1, (int)v5, 5, 0, 1);
	}
	return result;
}

//----- (004D86E0) --------------------------------------------------------
char* nox_xxx_netSendPlrHealthToTeam_4D86E0(int a1) {
	int v1;       // edi
	char* result; // eax
	char* v3;     // esi

	v1 = a1;
	result = nox_common_playerInfoFromNum_417090(a1);
	v3 = result;
	if (result) {
		result = (char*)*((uint32_t*)result + 514);
		if (result) {
			if (*((uint32_t*)result + 139)) {
				LOBYTE(a1) = 67;
				*(uint16_t*)((char*)&a1 + 1) = **(uint16_t**)(*((uint32_t*)v3 + 514) + 556);
				nox_xxx_netSendPacket1_4E5390(v1, (int)&a1, 3, 0, 1);
				result = (char*)nox_common_gameFlags_check_40A5C0(4096);
				if (result) {
					result = (char*)nox_xxx_netSendTeam_4D8670(v1 | 0x80, *((uint32_t**)v3 + 514));
				}
			}
		}
	}
	return result;
}

//----- (004D8760) --------------------------------------------------------
short nox_xxx_netReportHealthDelta_4D8760(int a1, short a2, short a3) {
	short result; // ax
	char v4[5];   // [esp+0h] [ebp-8h]

	result = a3;
	if (a3 < 0) {
		*(uint16_t*)&v4[3] = a3;
		v4[0] = 66;
		*(uint16_t*)&v4[1] = a2;
		result = nox_xxx_netSendPacket0_4E5420(a1, v4, 5, 0, 1);
	}
	return result;
}

//----- (004D87A0) --------------------------------------------------------
int nox_xxx_itemReportHealth_4D87A0(int a1, nox_object_t* item) {
	int result;   // eax
	uint16_t* v3; // eax
	char v4[7];   // [esp+4h] [ebp-8h]

	result = item->field_139;
	if (result) {
		if (*(uint16_t*)(result + 4)) {
			v4[0] = 68;
			*(uint16_t*)&v4[1] = nox_xxx_netGetUnitCodeServ_578AC0(item);
			v3 = (uint16_t*)item->field_139;
			*(uint16_t*)&v4[3] = *v3;
			*(uint16_t*)&v4[5] = v3[2];
			result = nox_xxx_netSendPacket1_4E5390(a1, (int)v4, 7, 0, 0);
		}
	}
	return result;
}

//----- (004D8800) --------------------------------------------------------
int nox_xxx_netReportStamina_4D8800(int a1, int a2) {
	int result; // eax
	int v3;     // eax

	result = a2;
	if (*(uint8_t*)(a2 + 8) & 4) {
		v3 = *(uint32_t*)(a2 + 748);
		LOBYTE(a2) = 71;
		BYTE1(a2) = *(uint8_t*)(v3 + 91);
		result = nox_xxx_netSendPacket1_4E5390(a1, (int)&a2, 2, 0, 1);
	}
	return result;
}

//----- (004D8840) --------------------------------------------------------
int sub_4D8840(int a1, int a2) {
	char v3;  // cl
	short v5; // [esp+0h] [ebp-2h]

	v3 = *(uint8_t*)(a2 + 440);
	LOBYTE(v5) = 91;
	HIBYTE(v5) = v3;
	return nox_xxx_netSendPacket0_4E5420(a1, &v5, 2, 0, 1);
}

//----- (004D8870) --------------------------------------------------------
int sub_4D8870(int a1, int a2) {
	int result; // eax
	int v3;     // eax
	char v4[5]; // [esp+0h] [ebp-8h]

	result = a2;
	if (*(uint8_t*)(a2 + 8) & 4) {
		v3 = *(uint32_t*)(a2 + 748);
		v4[0] = 74;
		*(uint32_t*)&v4[1] = *(uint32_t*)(*(uint32_t*)(v3 + 276) + 2164);
		result = nox_xxx_netSendPacket0_4E5420(a1, v4, 5, 0, 1);
	}
	return result;
}

//----- (004D88C0) --------------------------------------------------------
int nox_xxx_netReportTotalMana_4D88C0(int a1, int a2) {
	int result; // eax
	int v3;     // esi
	char v4[7]; // [esp+4h] [ebp-8h]

	result = a2;
	v3 = *(uint32_t*)(a2 + 748);
	if (*(uint8_t*)(a2 + 8) & 4 && (!v3 || *(uint8_t*)(*(uint32_t*)(v3 + 276) + 2251))) {
		v4[0] = -34;
		*(uint16_t*)&v4[1] = nox_xxx_netGetUnitCodeServ_578AC0((uint32_t*)a2);
		*(uint16_t*)&v4[3] = *(uint16_t*)(v3 + 4);
		*(uint16_t*)&v4[5] = *(uint16_t*)(v3 + 8);
		result = sub_4E5450(a1, v4, 7, 0, 1);
	}
	return result;
}

//----- (004D8930) --------------------------------------------------------
int nox_xxx_netReportMana_4D8930(int a1, int a2) {
	int result; // eax
	int v3;     // esi
	char v4[5]; // [esp+4h] [ebp-8h]

	result = a2;
	v3 = *(uint32_t*)(a2 + 748);
	if (*(uint8_t*)(a2 + 8) & 4 && (!v3 || *(uint8_t*)(*(uint32_t*)(v3 + 276) + 2251))) {
		v4[0] = 69;
		*(uint16_t*)&v4[1] = nox_xxx_netGetUnitCodeServ_578AC0((uint32_t*)a2);
		*(uint16_t*)&v4[3] = *(uint16_t*)(v3 + 4);
		result = sub_4E5450(a1, v4, 5, 0, 1);
	}
	return result;
}

//----- (004D8990) --------------------------------------------------------
char nox_xxx_servSendStats_4D8990(int a1, int a2, char a3) {
	char result; // al
	int v4;      // edi
	short v5;    // ax
	int v6;      // ecx
	short v7;    // ax
	char v8[14]; // [esp+8h] [ebp-10h]

	result = *(uint8_t*)(a2 + 8);
	v4 = *(uint32_t*)(a2 + 748);
	if (result & 4) {
		v8[0] = 72;
		v5 = nox_xxx_netGetUnitCodeServ_578AC0((uint32_t*)a2);
		v6 = *(uint32_t*)(a2 + 556);
		*(uint16_t*)&v8[1] = v5;
		*(uint16_t*)&v8[5] = *(uint16_t*)(v4 + 8);
		v7 = *(uint16_t*)(a2 + 490);
		*(uint16_t*)&v8[3] = *(uint16_t*)(v6 + 4);
		*(uint16_t*)&v8[7] = v7;
		*(uint16_t*)&v8[9] = *(uint16_t*)(*(uint32_t*)(v4 + 276) + 2235);
		*(uint16_t*)&v8[11] = *(uint16_t*)(*(uint32_t*)(v4 + 276) + 2239);
		v8[13] = a3;
		result = nox_xxx_netSendPacket0_4E5420(a1, v8, 14, 0, 1);
	}
	return result;
}

//----- (004D8A30) --------------------------------------------------------
int nox_xxx_netReportArmorVal_4D8A30(int a1, int a2) {
	char v3[5]; // [esp+0h] [ebp-8h]

	v3[0] = 73;
	*(uint32_t*)&v3[1] = a2;
	return nox_xxx_netSendPacket0_4E5420(a1, v3, 5, 0, 1);
}

//----- (004D8A60) --------------------------------------------------------
int nox_xxx_netReportPickup_4D8A60(int a1, nox_object_t* item) {
	short v3;   // ax
	short v4;   // cx
	char v5[5]; // [esp+4h] [ebp-8h]

	if (*(uint32_t*)&item->obj_class & 0x13001000) {
		return nox_xxx_netReportModifiablePickup_4D8AD0(a1, item);
	}
	v5[0] = 75;
	v3 = nox_xxx_netGetUnitCodeServ_578AC0(item);
	v4 = *(uint16_t*)&item->typ_ind;
	*(uint16_t*)&v5[1] = v3;
	*(uint16_t*)&v5[3] = v4;
	nox_xxx_netSendPacket1_4E5390(a1, (int)v5, 5, 0, 0);
	return nox_xxx_itemReportHealth_4D87A0(a1, item);
}

//----- (004D8AD0) --------------------------------------------------------
int nox_xxx_netReportModifiablePickup_4D8AD0(int a1, nox_object_t* item) {
	int v2;     // esi
	int v3;     // eax
	int v4;     // edx
	char v6[9]; // [esp+8h] [ebp-Ch]

	v6[0] = 76;
	v2 = *(uint32_t*)&item->field_173;
	*(uint16_t*)&v6[1] = nox_xxx_netGetUnitCodeServ_578AC0(item);
	*(uint16_t*)&v6[3] = *(uint16_t*)&item->typ_ind;
	v3 = 0;
	v4 = v2;
	do {
		if (*(uint32_t*)v4) {
			v6[v3 + 5] = *(uint8_t*)(*(uint32_t*)v4 + 4);
		} else {
			v6[v3 + 5] = -1;
		}
		++v3;
		v4 += 4;
	} while (v3 < 4);
	nox_xxx_netSendPacket1_4E5390(a1, (int)v6, 9, 0, 0);
	return nox_xxx_itemReportHealth_4D87A0(a1, item);
}

//----- (004D8B50) --------------------------------------------------------
int nox_xxx_netReportDrop_4D8B50(int a1, const nox_object_t* object) {
	int a2 = object;
	char v3[5]; // [esp+4h] [ebp-8h]

	v3[0] = 77;
	*(uint16_t*)&v3[1] = nox_xxx_netGetUnitCodeServ_578AC0((uint32_t*)a2);
	*(uint16_t*)&v3[3] = *(uint16_t*)(a2 + 4);
	return nox_xxx_netSendPacket1_4E5390(a1, (int)v3, 5, 0, 0);
}

//----- (004D8B90) --------------------------------------------------------
int nox_xxx_netSendDMWinner_4D8B90(int a1, char a2) {
	int result; // eax
	char v3[8]; // [esp+0h] [ebp-8h]

	result = a1;
	if (a1) {
		if (!(*(uint8_t*)(a1 + 8) & 4)) {
			return result;
		}
		v3[0] = 88;
		*(uint16_t*)&v3[1] = nox_xxx_netGetUnitCodeServ_578AC0((uint32_t*)a1);
	} else {
		v3[0] = 88;
		*(uint16_t*)&v3[1] = 0;
	}
	v3[3] = a2;
	*(uint32_t*)&v3[4] = nox_frame_xxx_2598000;
	return nox_xxx_netSendPacket1_4E5390(255, (int)v3, 8, 0, 1);
}

//----- (004D8BF0) --------------------------------------------------------
int nox_xxx_netSendDMTeamWinner_4D8BF0(int a1, char a2) {
	char v3[8]; // [esp+0h] [ebp-8h]

	v3[0] = 89;
	if (a1) {
		*(uint16_t*)&v3[1] = *(unsigned char*)(a1 + 57);
	} else {
		*(uint16_t*)&v3[1] = 0;
	}
	v3[3] = a2;
	*(uint32_t*)&v3[4] = nox_frame_xxx_2598000;
	return nox_xxx_netSendPacket1_4E5390(255, (int)v3, 8, 0, 1);
}

//----- (004D8C40) --------------------------------------------------------
int nox_xxx_netFlagballWinner_4D8C40(int a1) {
	short v1;   // cx
	char v3[8]; // [esp+0h] [ebp-8h]

	v1 = *(unsigned char*)(a1 + 57);
	v3[0] = 86;
	*(uint16_t*)&v3[1] = v1;
	v3[3] = 0;
	*(uint32_t*)&v3[4] = nox_frame_xxx_2598000;
	return nox_xxx_netSendPacket1_4E5390(255, (int)v3, 8, 0, 1);
}

//----- (004D8C80) --------------------------------------------------------
int nox_xxx_netFlagWinner_4D8C40_4D8C80(int a1, char a2) {
	char v3[8]; // [esp+0h] [ebp-8h]

	v3[0] = 87;
	if (a1) {
		*(uint16_t*)&v3[1] = *(unsigned char*)(a1 + 57);
	} else {
		*(uint16_t*)&v3[1] = -1;
	}
	v3[3] = a2;
	*(uint32_t*)&v3[4] = nox_frame_xxx_2598000;
	return nox_xxx_netSendPacket1_4E5390(255, (int)v3, 8, 0, 1);
}

//----- (004D8CD0) --------------------------------------------------------
int nox_xxx_scavengerHuntReport_4D8CD0(int a1) {
	int result; // eax
	int v2;     // esi
	char v3[7]; // [esp+4h] [ebp-8h]

	result = a1;
	v2 = *(uint32_t*)(a1 + 748);
	if (*(uint8_t*)(a1 + 8) & 4) {
		v3[0] = 85;
		*(uint16_t*)&v3[1] = nox_xxx_netGetUnitCodeServ_578AC0((uint32_t*)a1);
		*(uint16_t*)&v3[3] = *(uint16_t*)(*(uint32_t*)(v2 + 276) + 2152);
		*(uint16_t*)&v3[5] = *(uint16_t*)(*(uint32_t*)(v2 + 276) + 2156);
		result = nox_xxx_netSendPacket0_4E5420(255, v3, 7, 0, 1);
	}
	return result;
}

//----- (004D8D40) --------------------------------------------------------
char* nox_xxx_playerIncrementElimDeath_4D8D40(int a1) {
	char* result;      // eax
	char* i;           // esi
	char* v3;          // esi
	double v4;         // st7
	int v5;            // esi
	int v6;            // eax
	float v7;          // [esp+0h] [ebp-Ch]
	unsigned char* v8; // [esp+4h] [ebp-8h]
	int v9;            // [esp+10h] [ebp+4h]

	result = (char*)a1;
	if (*(uint8_t*)(a1 + 8) & 4) {
		++*(uint32_t*)(*(uint32_t*)(*(uint32_t*)(a1 + 748) + 276) + 2140);
		result = (char*)nox_common_gameFlags_check_40A5C0(1024);
		if (result) {
			if (sub_40AA00() && !sub_40AA20()) {
				for (i = nox_common_playerInfoGetFirst_416EA0(); i; i = nox_common_playerInfoGetNext_416EE0((int)i)) {
					if (i[3680] & 1) {
						nox_xxx_netNeedTimestampStatus_4174F0((int)i, 256);
					}
				}
				sub_40AA30(1);
			}
			result = (char*)nox_common_gameFlags_check_40A5C0(0x4000000);
			if (!result) {
				result = (char*)sub_40A300();
				if (!result) {
					result = (char*)sub_40AA00();
					if (result) {
						if (!nox_xxx_CheckGameplayFlags_417DA0(4)) {
							v5 = sub_40A770();
							result = (char*)sub_40AA40();
							if (v5 >= (int)result) {
								return result;
							}
							v8 = getMemAt(0x587000, 198928);
							v4 = nox_xxx_gamedataGetFloat_419D40("SuddenDeathCountdown");
							goto LABEL_22;
						}
						v9 = nox_xxx_getTeamCounter_417DD0();
						result = (char*)sub_40AA40();
						if (v9 < (int)result) {
							result = nox_xxx_TeamGet_418B10();
							v3 = result;
							if (result) {
								while (nox_xxx_countNonEliminatedPlayersInTeam_40A830((int)v3) != 1) {
									result = nox_xxx_TeamNext_418B60((int)v3);
									v3 = result;
									if (!result) {
										return result;
									}
								}
								v8 = getMemAt(0x587000, 198872);
								v4 = nox_xxx_gamedataGetFloat_419D40("SuddenDeathCountdown");
							LABEL_22:
								v7 = v4;
								v6 = nox_float2int(v7);
								return (char*)nox_xxx_servStartCountdown_40A2A0(v6, (const char*)v8);
							}
						}
					}
				}
			}
		}
	}
	return result;
}

//----- (004D8E90) --------------------------------------------------------
int nox_xxx_changeScore_4D8E90(int a1, int a2) {
	int result; // eax

	result = a1;
	if (*(uint8_t*)(a1 + 8) & 4) {
		result = *(uint32_t*)(*(uint32_t*)(a1 + 748) + 276);
		*(uint32_t*)(result + 2136) += a2;
	}
	return result;
}

//----- (004D8EC0) --------------------------------------------------------
int nox_xxx_playerSubLessons_4D8EC0(int a1, int a2) {
	int result; // eax

	result = a1;
	if (*(uint8_t*)(a1 + 8) & 4) {
		result = *(uint32_t*)(*(uint32_t*)(a1 + 748) + 276);
		*(uint32_t*)(result + 2136) -= a2;
	}
	return result;
}

//----- (004D8EF0) --------------------------------------------------------
int nox_xxx_netReportLesson_4D8EF0(nox_object_t* a1p) {
	int a1 = a1p;
	int v1;      // eax
	char v3[11]; // [esp+0h] [ebp-Ch]

	v3[0] = 78;
	v1 = *(uint32_t*)(a1 + 748);
	*(uint16_t*)&v3[1] = *(uint16_t*)(a1 + 36);
	*(uint32_t*)&v3[3] = *(uint32_t*)(*(uint32_t*)(v1 + 276) + 2136);
	*(uint32_t*)&v3[7] = *(uint32_t*)(*(uint32_t*)(v1 + 276) + 2140);
	return nox_xxx_netSendPacket1_4E5390(255, (int)v3, 11, 0, 1);
}

//----- (004D8F50) --------------------------------------------------------
int nox_xxx_netTimerStatus_4D8F50(int a1, int a2) {
	char v3[13]; // [esp+0h] [ebp-10h]

	v3[0] = -45;
	*(uint32_t*)&v3[1] = a2;
	*(uint32_t*)&v3[5] = sub_40A230();
	*(uint32_t*)&v3[9] = nox_frame_xxx_2598000;
	return nox_xxx_netSendPacket1_4E5390(a1, (int)v3, 13, 0, 1);
}

//----- (004D8F90) --------------------------------------------------------
int nox_xxx_netReportEnchant_4D8F90(int a1, uint32_t* a2) {
	char v3[7]; // [esp+4h] [ebp-8h]

	v3[0] = 90;
	*(uint16_t*)&v3[1] = nox_xxx_netGetUnitCodeServ_578AC0(a2);
	*(uint32_t*)&v3[3] = a2[85];
	return nox_xxx_netSendPacket1_4E5390(a1, (int)v3, 7, 0, 1);
}

//----- (004D8FD0) --------------------------------------------------------
void nox_xxx_netReportObjHidden_4D8FD0(int a1, uint32_t* a2) {
	uint32_t* v2; // esi

	v2 = a2;
	if ((unsigned int)0x800000 & a2[2]) {
		*(uint16_t*)((char*)&a2 + 1) = nox_xxx_netGetUnitCodeServ_578AC0(a2);
		LOBYTE(a2) = 56 - ((v2[4] & 0x1000000) != 0);
		nox_xxx_netSendPacket0_4E5420(a1, &a2, 3, 0, 1);
	}
}

//----- (004D9020) --------------------------------------------------------
int nox_xxx_netReportUnitHeight_4D9020(int a1, int a2) {
	int v2;        // esi
	short v3;      // ax
	double v4;     // st7
	long long v5;  // rax
	double v6;     // st7
	long long v7;  // rax
	double v8;     // st7
	int result;    // eax
	short v10;     // ax
	double v11;    // st7
	short v12;     // ax
	double v13;    // st7
	uint32_t* v14; // [esp-4h] [ebp-10h]
	char v15[6];   // [esp+4h] [ebp-8h]

	v2 = a2;
	if (*(uint8_t*)(a2 + 20) & 0x20) {
		v3 = *(uint16_t*)(a2 + 36);
		v15[0] = -97;
		v4 = *(float*)(a2 + 104);
		*(uint16_t*)&v15[1] = v3;
		v5 = (long long)v4;
		v6 = *(float*)(a2 + 108);
		v15[3] = v5;
		v7 = (long long)v6;
		v8 = *(float*)(a2 + 116);
		v15[4] = v7;
		v15[5] = (long long)v8;
		result = nox_netlist_addToMsgListCli_40EBC0(a1, 1, v15, 6);
	} else {
		v14 = (uint32_t*)a2;
		if (*(float*)(a2 + 104) < 0.0) {
			LOBYTE(a2) = 95;
			v12 = nox_xxx_netGetUnitCodeServ_578AC0(v14);
			v13 = *(float*)(v2 + 104);
			*(uint16_t*)((char*)&a2 + 1) = v12;
			v11 = -v13;
		} else {
			LOBYTE(a2) = 94;
			v10 = nox_xxx_netGetUnitCodeServ_578AC0(v14);
			v11 = *(float*)(v2 + 104);
			*(uint16_t*)((char*)&a2 + 1) = v10;
		}
		HIBYTE(a2) = (long long)v11;
		result = nox_netlist_addToMsgListCli_40EBC0(a1, 1, &a2, 4);
	}
	return result;
}

//----- (004D90E0) --------------------------------------------------------
int sub_4D90E0(int a1, char a2) {
	char v3[2]; // [esp+0h] [ebp-2h]

	v3[0] = -105;
	v3[1] = a2;
	return nox_netlist_addToMsgListCli_40EBC0(a1, 1, v3, 2);
}

//----- (004D9110) --------------------------------------------------------
int nox_xxx_earthquakeSend_4D9110(float* a1, int a2) {
	int result; // eax
	int i;      // edi
	int v4;     // esi
	double v5;  // st7
	double v6;  // st6
	double v7;  // st5

	result = nox_xxx_getFirstPlayerUnit_4DA7C0();
	for (i = result; result; i = result) {
		v4 = *(uint32_t*)(*(uint32_t*)(i + 748) + 276);
		v5 = *a1 - *(float*)(v4 + 3632);
		v6 = a1[1] - *(float*)(v4 + 3636);
		v7 = v6 * v6 + v5 * v5;
		if (v7 < 90000.0) {
			sub_4D90E0(*(unsigned char*)(v4 + 2064), (long long)((1.0 - v7 * 0.000011111111) * (double)a2));
		}
		result = nox_xxx_getNextPlayerUnit_4DA7F0(i);
	}
	return result;
}

//----- (004D91A0) --------------------------------------------------------
int nox_xxx_netReportAcquireCreature_4D91A0(int a1, int a2) {
	char v3[5]; // [esp+8h] [ebp-8h]

	v3[0] = 108;
	*(uint16_t*)&v3[1] = nox_xxx_netGetUnitCodeServ_578AC0((uint32_t*)a2);
	*(uint16_t*)&v3[3] = *(uint16_t*)(a2 + 4);
	if (nox_common_gameFlags_check_40A5C0(0x8000000)) {
		v3[4] |= 0x80u;
	}
	nox_xxx_netSendPacket1_4E5390(a1, (int)v3, 5, 0, 1);
	return nox_xxx_netReportTotalHealth_4D85C0(a1, (uint32_t*)a2);
}

//----- (004D9200) --------------------------------------------------------
int nox_xxx_netFxShield_0_4D9200(int a1, int a2) {
	int v4; // [esp+0h] [ebp-4h]

	LOBYTE(v4) = 109;
	*(uint16_t*)((char*)&v4 + 1) = *(uint16_t*)(a2 + 36);
	if (nox_common_gameFlags_check_40A5C0(0x8000000)) {
		BYTE2(v4) |= 0x80u;
	}
	return nox_xxx_netSendPacket1_4E5390(a1, (int)&v4, 3, 0, 1);
}

//----- (004D9250) --------------------------------------------------------
int nox_xxx_netMonitorCreature_4D9250(int a1, int a2) {
	char v3[5]; // [esp+8h] [ebp-8h]

	v3[0] = -37;
	*(uint16_t*)&v3[1] = nox_xxx_netGetUnitCodeServ_578AC0((uint32_t*)a2);
	*(uint16_t*)&v3[3] = *(uint16_t*)(a2 + 4);
	nox_xxx_netSendPacket1_4E5390(a1, (int)v3, 5, 0, 1);
	return nox_xxx_netReportTotalHealth_4D85C0(a1, (uint32_t*)a2);
}

//----- (004D92A0) --------------------------------------------------------
int nox_xxx_netSendUnMonitorCrea_4D92A0(int a1, uint32_t* a2) {
	char v4[3]; // [esp+0h] [ebp-4h]
	v4[0] = -36;
	*(uint16_t*)&v4[1] = nox_xxx_netGetUnitCodeServ_578AC0(a2);
	return nox_xxx_netSendPacket1_4E5390(a1, (int)v4, 3, 0, 1);
}

//----- (004D92D0) --------------------------------------------------------
int nox_xxx_netReportTeamBase_4D92D0(int a1, int a2) {
	int result; // eax
	int v3;     // edi
	int v4;     // eax
	int v5;     // edx
	char v6[7]; // [esp+8h] [ebp-8h]

	result = *getMemU32Ptr(0x5D4594, 1556320);
	v3 = *(uint32_t*)(a2 + 692);
	if (!*getMemU32Ptr(0x5D4594, 1556320)) {
		result = nox_xxx_getNameId_4E3AA0("TeamBase");
		*getMemU32Ptr(0x5D4594, 1556320) = result;
	}
	if (*(uint32_t*)(a2 + 8) & 0x13001000 || *(unsigned short*)(a2 + 4) == result) {
		v6[0] = 103;
		*(uint16_t*)&v6[1] = nox_xxx_netGetUnitCodeServ_578AC0((uint32_t*)a2);
		v4 = 0;
		v5 = v3;
		do {
			if (*(uint32_t*)v5) {
				v6[v4 + 3] = *(uint8_t*)(*(uint32_t*)v5 + 4);
			} else {
				v6[v4 + 3] = -1;
			}
			++v4;
			v5 += 4;
		} while (v4 < 4);
		result = nox_xxx_netSendPacket0_4E5420(a1, v6, 7, 0, 1);
	}
	return result;
}

//----- (004D9360) --------------------------------------------------------
int nox_xxx_netReportStatsSpeed_4D9360(int a1, uint32_t* a2, char a3, int a4) {
	char v5[8]; // [esp+0h] [ebp-8h]

	v5[0] = 104;
	*(uint16_t*)&v5[1] = nox_xxx_netGetUnitCodeServ_578AC0(a2);
	v5[7] = a3;
	*(uint32_t*)&v5[3] = a4;
	return nox_xxx_netSendPacket0_4E5420(a1, v5, 8, 0, 1);
}

//----- (004D93A0) --------------------------------------------------------
uint32_t* nox_xxx_netSendReportNPC_4D93A0(int a1, int a2) {
	int v2;           // eax
	char* v3;         // ecx
	int v4;           // eax
	int v5;           // esi
	int v6;           // edx
	char* v7;         // ebx
	uint32_t* result; // eax
	uint32_t* i;      // esi
	char v10[21];     // [esp+10h] [ebp-18h]

	v10[0] = 105;
	v2 = *(uint32_t*)(a2 + 748);
	*(uint16_t*)&v10[1] = *(uint16_t*)(a2 + 36);
	if (*(uint8_t*)(a2 + 540)) {
		v10[2] |= 0x80u;
	}
	v3 = &v10[3];
	v4 = v2 + 2076;
	v5 = 6;
	do {
		v6 = v4;
		v7 = v3;
		v4 += 3;
		v3 += 3;
		--v5;
		*(uint16_t*)v7 = *(uint16_t*)v6;
		v7[2] = *(uint8_t*)(v6 + 2);
	} while (v5);
	result = (uint32_t*)nox_xxx_netSendPacket1_4E5390(a1, (int)v10, 21, 0, 1);
	for (i = *(uint32_t**)(a2 + 504); i; i = (uint32_t*)i[124]) {
		if (i[4] & 0x100) {
			result = sub_4D82F0(a1, i);
		}
	}
	return result;
}

//----- (004D9440) --------------------------------------------------------
int nox_xxx_netSendJournalAdd_4D9440(int a1, int a2) {
	char v3[68]; // [esp+Ch] [ebp-44h]

	v3[0] = -43;
	v3[1] = 1;
	strcpy(&v3[2], (const char*)a2);
	*(uint16_t*)&v3[66] = *(uint16_t*)(a2 + 72);
	return nox_xxx_netSendPacket0_4E5420(a1, v3, 68, 0, 1);
}

//----- (004D94A0) --------------------------------------------------------
int nox_xxx_netSendJournalRemove_4D94A0(int a1, const char* a2) {
	char v3[68]; // [esp+8h] [ebp-44h]

	v3[0] = -43;
	v3[1] = 2;
	strcpy(&v3[2], a2);
	return nox_xxx_netSendPacket0_4E5420(a1, v3, 68, 0, 1);
}

//----- (004D9500) --------------------------------------------------------
int nox_xxx_netSendJournalUpdate_4D9500(int a1, int a2) {
	char v3[68]; // [esp+Ch] [ebp-44h]

	v3[0] = -43;
	v3[1] = 3;
	strcpy(&v3[2], (const char*)a2);
	*(uint16_t*)&v3[66] = *(uint16_t*)(a2 + 72);
	return nox_xxx_netSendPacket0_4E5420(a1, v3, 68, 0, 1);
}

//----- (004D9560) --------------------------------------------------------
int nox_xxx_netSendChapterEnd_4D9560(int a1, char a2, int a3) {
	char v5[3]; // [esp+0h] [ebp-4h]
	v5[1] = a2;
	v5[0] = -42;
	v5[2] = a3 == 1;
	return nox_xxx_netSendPacket0_4E5420(a1, v5, 3, 0, 1);
}

//----- (004D95A0) --------------------------------------------------------
int nox_xxx_netSendFlagStatus_4D95A0(int a1, char a2, char a3, char a4, short a5) {
	char v6[6]; // [esp+0h] [ebp-8h]

	v6[1] = a3;
	v6[3] = a4;
	v6[2] = a2;
	v6[0] = -40;
	*(uint16_t*)&v6[4] = a5;
	return nox_xxx_netSendPacket1_4E5390(a1, (int)v6, 6, 0, 1);
}

//----- (004D95F0) --------------------------------------------------------
int nox_xxx_netSendBallStatus_4D95F0(int a1, char a2, short a3) {
	char v4[4]; // [esp+0h] [ebp-4h]

	v4[1] = a2;
	v4[0] = -39;
	*(uint16_t*)&v4[2] = a3;
	return nox_xxx_netSendPacket1_4E5390(a1, (int)v4, 4, 0, 1);
}

//----- (004D9630) --------------------------------------------------------
int nox_xxx_netReportSpellStat_4D9630(int a1, int a2, char a3) {
	char v4[6]; // [esp+0h] [ebp-8h]

	*(uint32_t*)&v4[1] = a2;
	v4[0] = -33;
	v4[5] = a3;
	return nox_xxx_netSendPacket0_4E5420(a1, v4, 6, 0, 1);
}

//----- (004D9670) --------------------------------------------------------
int nox_xxx_netSendSecondaryWeapon_4D9670(int a1, uint32_t* a2, char a3) {
	char v4[4]; // [esp+0h] [ebp-4h]

	v4[0] = -32;
	*(uint16_t*)&v4[1] = nox_xxx_netGetUnitCodeServ_578AC0(a2);
	v4[3] = a3;
	return nox_xxx_netSendPacket1_4E5390(a1, (int)v4, 4, 0, 0);
}

//----- (004D96B0) --------------------------------------------------------
int nox_xxx_netMsgLastQuiver_4D96B0(int a1, uint32_t* a2) {
	char v4[3]; // [esp+0h] [ebp-4h]
	v4[0] = -31;
	*(uint16_t*)&v4[1] = nox_xxx_netGetUnitCodeServ_578AC0(a2);
	return nox_xxx_netSendPacket1_4E5390(a1, (int)v4, 3, 0, 0);
}

//----- (004D96E0) --------------------------------------------------------
int nox_xxx_netMsgInventoryLoaded_4D96E0(int a1) {
	char v2[1]; // [esp+1h] [ebp-1h]

	v2[0] = 113;
	return nox_xxx_netSendPacket1_4E5390(a1, (int)v2, 1, 0, 0);
}

//----- (004D9700) --------------------------------------------------------
int sub_4D9700(int a1) {
	int result; // eax

	result = a1;
	switch (a1) {
	case 0:
		result = nox_xxx_netPrintLineToAll_4DA390("report.c:NoComp");
		break;
	case 1:
		result = nox_xxx_netPrintLineToAll_4DA390("report.c:MinComp");
		break;
	case 2:
		result = nox_xxx_netPrintLineToAll_4DA390("report.c:AveComp");
		break;
	case 3:
		result = nox_xxx_netPrintLineToAll_4DA390("report.c:UserComp");
		break;
	default:
		return result;
	}
	return result;
}

//----- (004D9760) --------------------------------------------------------
int nox_xxx_netScriptMessageKill_4D9760(int a1) {
	int result; // eax
	int v2;     // edx

	result = a1;
	if (*(uint8_t*)(a1 + 8) & 4) {
		v2 = *(uint32_t*)(a1 + 748);
		LOBYTE(a1) = -53;
		result = nox_xxx_netSendPacket0_4E5420(*(unsigned char*)(*(uint32_t*)(v2 + 276) + 2064), &a1, 1, 0, 1);
	}
	return result;
}

//----- (004D97A0) --------------------------------------------------------
int nox_xxx_netFriendAddRemove_4D97A0(int a1, uint32_t* a2, int a3) {
	LOBYTE(a3) = (a3 != 1) + 52;
	*(uint16_t*)((char*)&a3 + 1) = nox_xxx_netGetUnitCodeServ_578AC0(a2);
	return nox_xxx_netSendPacket1_4E5390(a1, (int)&a3, 3, 0, 1);
}

//----- (004D97E0) --------------------------------------------------------
int sub_4D97E0(int a1) {
	char v2[1]; // [esp+1h] [ebp-1h]

	v2[0] = 54;
	return nox_xxx_netSendPacket1_4E5390(a1, (int)v2, 1, 0, 1);
}

//----- (004D9800) --------------------------------------------------------
int nox_xxx_netMsgFadeBegin_4D9800(int a1, int a2) {
	char v4[3]; // [esp+0h] [ebp-4h]
	v4[0] = 0xE4;
	v4[1] = a1 != 0;
	v4[2] = a2 != 0;
	return nox_xxx_netSendPacket1_4E5390(255, (int)v4, 3, 0, 1);
}

//----- (004D9800) --------------------------------------------------------
int nox_xxx_netMsgFadeBeginPlayer(int pl, int a1, int a2) {
	char v4[3]; // [esp+0h] [ebp-4h]
	v4[0] = 0xE4;
	v4[1] = a1 != 0;
	v4[2] = a2 != 0;
	return nox_xxx_netSendPacket1_4E5390(pl, (int)v4, 3, 0, 1);
}

//----- (004D9840) --------------------------------------------------------
void nox_xxx_netHarpoonAttach_4D9840(uint32_t* a1, uint32_t* a2) {
	char v3[7]; // [esp+4h] [ebp-8h]

	if (a1 && a2) {
		v3[0] = -98;
		v3[1] = 7;
		v3[2] = 0;
		*(uint16_t*)&v3[3] = nox_xxx_netGetUnitCodeServ_578AC0(a1);
		*(uint16_t*)&v3[5] = nox_xxx_netGetUnitCodeServ_578AC0(a2);
	}
	nox_xxx_netSendPacket1_4E5390(255, (int)v3, 7, 0, 1);
}

//----- (004D98A0) --------------------------------------------------------
int nox_xxx_netHarpoonBreak_4D98A0(uint32_t* a1, uint32_t* a2) {
	char v3[7]; // [esp+4h] [ebp-8h]

	if (a1 && a2) {
		v3[0] = -98;
		v3[1] = 14;
		v3[2] = 0;
		*(uint16_t*)&v3[3] = nox_xxx_netGetUnitCodeServ_578AC0(a1);
		*(uint16_t*)&v3[5] = nox_xxx_netGetUnitCodeServ_578AC0(a2);
	}
	return nox_xxx_netSendPacket1_4E5390(255, (int)v3, 7, 0, 1);
}

//----- (004D9900) --------------------------------------------------------
void nox_xxx_playerReportAnything_4D9900(int a1) {
	int v1;        // ebp
	int v2;        // esi
	uint16_t* v3;  // edi
	int v4;        // eax
	int v5;        // eax
	int i;         // edi
	char* v7;      // eax
	int j;         // edi
	int v9;        // ebx
	int v10;       // eax
	int k;         // edi
	int v12;       // ebx
	int v13;       // eax
	int v14;       // eax
	uint16_t* v15; // [esp+Ch] [ebp-4h]
	int v16;       // [esp+14h] [ebp+4h]

	v1 = a1;
	if (a1 && *(uint8_t*)(a1 + 8) & 4) {
		v2 = *(uint32_t*)(a1 + 748);
		v3 = *(uint16_t**)(a1 + 556);
		v15 = *(uint16_t**)(a1 + 556);
		v16 = *(int*)(v2 + 228);
		if (*(float*)(v2 + 232) != *(float*)&v16) {
			nox_xxx_netReportArmorVal_4D8A30(*(unsigned char*)(*(uint32_t*)(v2 + 276) + 2064), v16);
			*(uint32_t*)(v2 + 232) = *(uint32_t*)(v2 + 228);
		}
		v4 = *(uint32_t*)(v2 + 276);
		if (*(uint32_t*)(v4 + 2168) != *(uint32_t*)(v4 + 2164)) {
			sub_4D8870(*(unsigned char*)(v4 + 2064), v1);
			*(uint32_t*)(*(uint32_t*)(v2 + 276) + 2168) = *(uint32_t*)(*(uint32_t*)(v2 + 276) + 2164);
		}
		v5 = *(uint32_t*)(v2 + 276);
		if (*(uint8_t*)(v5 + 2172) != *(uint8_t*)(v1 + 440)) {
			sub_4D8840(*(unsigned char*)(v5 + 2064), v1);
			*(uint8_t*)(*(uint32_t*)(v2 + 276) + 2172) = *(uint8_t*)(v1 + 440);
		}
		if (nox_common_gameFlags_check_40A5C0(4096)) {
			for (i = 0; i < 32; ++i) {
				v7 = nox_common_playerInfoFromNum_417090(i);
				if (v7 && *((uint32_t*)v7 + 514) && *(uint32_t*)(v2 + 320) != *(unsigned char*)(i + v2 + 452)) {
					sub_4D9D60(i, v1);
					*(uint8_t*)(i + v2 + 452) = *(uint8_t*)(v2 + 320);
				}
			}
			for (j = 0; j < 32; ++j) {
				v9 = 0;
				if (!*getMemU32Ptr(0x5D4594, 1556324)) {
					*getMemU32Ptr(0x5D4594, 1556324) = nox_xxx_getNameId_4E3AA0("SilverKey");
				}
				if (nox_common_playerInfoFromNum_417090(j)) {
					v10 = nox_xxx_inventoryGetFirst_4E7980(v1);
					if (v10) {
						while (*(unsigned short*)(v10 + 4) != *getMemU32Ptr(0x5D4594, 1556324)) {
							v10 = nox_xxx_inventoryGetNext_4E7990(v10);
							if (!v10) {
								goto LABEL_25;
							}
						}
						v9 = 1;
					}
				LABEL_25:
					if (v9 != *(unsigned char*)(j + v2 + 484)) {
						sub_4D9DF0(j, v1, v9);
						*(uint8_t*)(j + v2 + 484) = v9;
					}
				}
			}
			for (k = 0; k < 32; ++k) {
				v12 = 0;
				if (!*getMemU32Ptr(0x5D4594, 1556328)) {
					*getMemU32Ptr(0x5D4594, 1556328) = nox_xxx_getNameId_4E3AA0("GoldKey");
				}
				if (nox_common_playerInfoFromNum_417090(k)) {
					v13 = nox_xxx_inventoryGetFirst_4E7980(v1);
					if (v13) {
						while (*(unsigned short*)(v13 + 4) != *getMemU32Ptr(0x5D4594, 1556328)) {
							v13 = nox_xxx_inventoryGetNext_4E7990(v13);
							if (!v13) {
								goto LABEL_37;
							}
						}
						v12 = 1;
					}
				LABEL_37:
					if (v12 != *(unsigned char*)(k + v2 + 516)) {
						sub_4D9E30(k, v1, v12);
						*(uint8_t*)(k + v2 + 516) = v12;
					}
				}
			}
			v3 = v15;
		}
		v14 = *(uint32_t*)(v2 + 276);
		if (*(uint8_t*)(v14 + 2184)) {
			nox_xxx_netReportTotalHealth_4D85C0(*(unsigned char*)(v14 + 2064), (uint32_t*)v1);
			nox_xxx_netReportTotalMana_4D88C0(*(unsigned char*)(*(uint32_t*)(v2 + 276) + 2064), v1);
			nox_xxx_servSendStats_4D8990(*(unsigned char*)(*(uint32_t*)(v2 + 276) + 2064), v1,
										 *(uint8_t*)(*(uint32_t*)(v2 + 276) + 3684));
			*(uint8_t*)(*(uint32_t*)(v2 + 276) + 2184) = 0;
		}
		if (nox_xxx_check_flag_aaa_43AF70() == 1) {
			sub_528030(v1);
		} else {
			if (v3 && *v3 != *(uint16_t*)(v2 + 10)) {
				nox_xxx_netSendPlrHealthToTeam_4D86E0(*(unsigned char*)(*(uint32_t*)(v2 + 276) + 2064));
				*(uint16_t*)(v2 + 10) = *v3;
			}
			if (*(uint16_t*)(v2 + 4) != *(uint16_t*)(v2 + 6)) {
				nox_xxx_netReportMana_4D8930(*(unsigned char*)(*(uint32_t*)(v2 + 276) + 2064), v1);
				*(uint16_t*)(v2 + 6) = *(uint16_t*)(v2 + 4);
			}
		}
	}
}

//----- (004D9C20) --------------------------------------------------------
int nox_xxx_netStatsMultiplier_4D9C20(int a1) {
	int result;  // eax
	int v2;      // ecx
	int v3;      // edx
	char v4[17]; // [esp+0h] [ebp-14h]

	result = a1;
	if (a1) {
		v2 = *(uint32_t*)(a1 + 748);
		v4[0] = -17;
		if (*(uint8_t*)(*(uint32_t*)(v2 + 276) + 2251)) {
			if (*(uint8_t*)(*(uint32_t*)(v2 + 276) + 2251) == 1) {
				*(uint32_t*)&v4[1] = nox_xxx_wizardMaxHealth_587000_312816;
				*(uint32_t*)&v4[5] = nox_xxx_wizardMaximumMana_587000_312820;
				v3 = nox_xxx_wizardSpeed_587000_312828;
				*(uint32_t*)&v4[9] = nox_xxx_wizardStrength_587000_312824;
			} else {
				result = *(unsigned char*)(*(uint32_t*)(v2 + 276) + 2251) - 2;
				if (*(uint8_t*)(*(uint32_t*)(v2 + 276) + 2251) != 2) {
					return result;
				}
				*(uint32_t*)&v4[1] = nox_xxx_conjurerMaxHealth_587000_312800;
				*(uint32_t*)&v4[5] = nox_xxx_conjurerMaxMana_587000_312804;
				v3 = nox_xxx_conjurerSpeed_587000_312812;
				*(uint32_t*)&v4[9] = nox_xxx_conjurerStrength_587000_312808;
			}
		} else {
			*(uint32_t*)&v4[1] = nox_xxx_warriorMaxHealth_587000_312784;
			*(uint32_t*)&v4[5] = nox_xxx_warriorMaxMana_587000_312788;
			v3 = nox_xxx_warriorMaxSpeed_587000_312796;
			*(uint32_t*)&v4[9] = nox_xxx_warriorMaxStrength_587000_312792;
		}
		*(uint32_t*)&v4[13] = v3;
		result = nox_xxx_netSendPacket0_4E5420(*(unsigned char*)(*(uint32_t*)(v2 + 276) + 2064), v4, 17, 0, 1);
	}
	return result;
}

//----- (004D9CF0) --------------------------------------------------------
int sub_4D9CF0(int a1) {
	char v2[2]; // [esp+0h] [ebp-2h]

	v2[0] = -16;
	v2[1] = 0;
	return nox_xxx_netSendPacket1_4E5390(a1, (int)v2, 2, 0, 1);
}

//----- (004D9D20) --------------------------------------------------------
int sub_4D9D20(int a1, int a2) {
	short v3;   // cx
	char v5[4]; // [esp+0h] [ebp-4h]

	v3 = *(uint16_t*)(a2 + 36);
	*(uint16_t*)v5 = 496;
	*(uint16_t*)&v5[2] = v3;
	return nox_xxx_netSendPacket1_4E5390(a1, (int)v5, 4, 0, 1);
}

//----- (004D9D60) --------------------------------------------------------
int sub_4D9D60(int a1, int a2) {
	int v2;     // edx
	char v4[5]; // [esp+0h] [ebp-8h]

	v4[0] = -16;
	v4[1] = 4;
	v2 = *(uint32_t*)(a2 + 748);
	*(uint16_t*)&v4[3] = *(uint16_t*)(a2 + 36);
	v4[2] = *(uint8_t*)(v2 + 320);
	return nox_xxx_netSendPacket0_4E5420(a1, v4, 5, 0, 1);
}

//----- (004D9DB0) --------------------------------------------------------
int nox_xxx_unused_4D9DB0(int a1, int a2, int a3) {
	char v4[8]; // [esp+0h] [ebp-8h]

	*(uint16_t*)&v4[6] = *(uint16_t*)(a2 + 36);
	v4[0] = -16;
	v4[1] = 21;
	*(uint32_t*)&v4[2] = a3;
	return nox_xxx_netSendPacket0_4E5420(a1, v4, 8, 0, 1);
}

//----- (004D9DF0) --------------------------------------------------------
int sub_4D9DF0(int a1, int a2, char a3) {
	char v4[5]; // [esp+0h] [ebp-8h]

	*(uint16_t*)&v4[3] = *(uint16_t*)(a2 + 36);
	v4[0] = -16;
	v4[1] = 22;
	v4[2] = a3;
	return nox_xxx_netSendPacket0_4E5420(a1, v4, 5, 0, 1);
}

//----- (004D9E30) --------------------------------------------------------
int sub_4D9E30(int a1, int a2, char a3) {
	char v4[5]; // [esp+0h] [ebp-8h]

	*(uint16_t*)&v4[3] = *(uint16_t*)(a2 + 36);
	v4[0] = -16;
	v4[1] = 23;
	v4[2] = a3;
	return nox_xxx_netSendPacket0_4E5420(a1, v4, 5, 0, 1);
}

//----- (004D9E70) --------------------------------------------------------
int nox_xxx_netGauntlet_4D9E70(int a1) {
	char v2[2]; // [esp+0h] [ebp-2h]

	v2[0] = -16;
	v2[1] = 20;
	return nox_xxx_netSendPacket0_4E5420(a1, v2, 2, 0, 1);
}

//----- (004D9EB0) --------------------------------------------------------
int nox_xxx_netSendLineMessage_4D9EB0(int a1, wchar_t* a2, ...) {
	int result;      // eax
	int v3;          // esi
	char v4;         // al
	int v5;          // eax
	wchar_t v6[516]; // [esp+4h] [ebp-408h]
	va_list va;      // [esp+418h] [ebp+Ch]

	va_start(va, a2);
	result = a1;
	if (a1 && *(uint8_t*)(a1 + 8) & 4) {
		v3 = *(uint32_t*)(a1 + 748);
		nox_vswprintf(&v6[260], a2, va);
		LOBYTE(v6[0]) = -88;
		*(wchar_t*)((char*)v6 + 1) = 0;
		HIBYTE(v6[1]) = 0;
		if (nox_xxx_cliCanTalkMB_4100F0((short*)&v6[260])) {
			v4 = HIBYTE(v6[1]) | 2;
		} else {
			v4 = HIBYTE(v6[1]) | 4;
		}
		HIBYTE(v6[1]) = v4;
		v6[2] = 0;
		v6[3] = 0;
		LOBYTE(v6[5]) = 0;
		v6[4] = (unsigned char)(nox_wcslen(&v6[260]) + 1);
		if (v6[1] & 0x400) {
			nox_wcscpy((wchar_t*)((char*)&v6[5] + 1), &v6[260]);
			v5 = 2;
		} else {
			nox_sprintf((char*)&v6[5] + 1, "%S", &v6[260]);
			v5 = 1;
		}
		result = nox_netlist_addToMsgListCli_40EBC0(*(unsigned char*)(*(uint32_t*)(v3 + 276) + 2064), 1, v6,
													v5 * LOBYTE(v6[4]) + 11);
	}
	return result;
}

//----- (004D9FD0) --------------------------------------------------------
int nox_xxx_printToAll_4D9FD0(char a1, wchar_t* a2, ...) {
	char v2;         // al
	int v3;          // edi
	int result;      // eax
	int i;           // esi
	wchar_t v6[516]; // [esp+Ch] [ebp-408h]
	va_list va;      // [esp+420h] [ebp+Ch]

	va_start(va, a2);
	nox_vswprintf(&v6[260], a2, va);
	LOBYTE(v6[0]) = -88;
	*(wchar_t*)((char*)v6 + 1) = 0;
	HIBYTE(v6[1]) = a1;
	if (nox_xxx_cliCanTalkMB_4100F0((short*)&v6[260])) {
		v2 = HIBYTE(v6[1]) | 2;
	} else {
		v2 = HIBYTE(v6[1]) | 4;
	}
	HIBYTE(v6[1]) = v2;
	v6[2] = 0;
	v6[3] = 0;
	LOBYTE(v6[5]) = 0;
	v6[4] = (unsigned char)(nox_wcslen(&v6[260]) + 1);
	if (v6[1] & 0x400) {
		nox_wcscpy((wchar_t*)((char*)&v6[5] + 1), &v6[260]);
		v3 = 2;
	} else {
		nox_sprintf((char*)&v6[5] + 1, "%S", &v6[260]);
		v3 = 1;
	}
	result = nox_xxx_getFirstPlayerUnit_4DA7C0();
	for (i = result; result; i = result) {
		nox_netlist_addToMsgListCli_40EBC0(*(unsigned char*)(*(uint32_t*)(*(uint32_t*)(i + 748) + 276) + 2064), 1, v6,
										   v3 * LOBYTE(v6[4]) + 11);
		result = nox_xxx_getNextPlayerUnit_4DA7F0(i);
	}
	return result;
}

//----- (004DA0F0) --------------------------------------------------------
int nox_xxx_netInformTextMsg_4DA0F0(int a1, int a2, int* a3) {
	int result; // eax
	int v4;     // edx
	char v5[6]; // [esp+0h] [ebp-8h]

	result = a2;
	switch (a2) {
	case 0:
	case 1:
	case 2:
	case 12:
	case 13:
	case 16:
	case 20:
	case 21:
		v5[1] = a2;
		v4 = *a3;
		v5[0] = -87;
		*(uint32_t*)&v5[2] = v4;
		result = nox_netlist_addToMsgListCli_40EBC0(a1, 1, v5, 6);
		break;
	case 17:
		LOWORD(a2) = 4521;
		result = nox_netlist_addToMsgListCli_40EBC0(a1, 1, &a2, 2);
		break;
	default:
		return result;
	}
	return result;
}

//----- (004DA180) --------------------------------------------------------
int nox_xxx_netInformTextMsg2_4DA180(int a1, uint8_t* a2) {
	int result; // eax
	int i;      // esi
	int j;      // esi
	int k;      // esi
	char v6[6]; // [esp+8h] [ebp-8h]

	result = a1;
	switch (a1) {
	case 3:
	case 4:
	case 8:
	case 18:
	case 19:
	case 21:
		v6[1] = a1;
		v6[0] = -87;
		*(uint32_t*)&v6[2] = *(uint32_t*)a2;
		result = nox_xxx_getFirstPlayerUnit_4DA7C0();
		for (i = result; result; i = result) {
			nox_netlist_addToMsgListCli_40EBC0(*(unsigned char*)(*(uint32_t*)(*(uint32_t*)(i + 748) + 276) + 2064), 1,
											   v6, 6);
			result = nox_xxx_getNextPlayerUnit_4DA7F0(i);
		}
		break;
	case 5:
	case 6:
	case 7:
	case 9:
	case 10:
	case 11:
		*a2 = -87;
		a2[1] = a1;
		result = nox_xxx_getFirstPlayerUnit_4DA7C0();
		for (j = result; result; j = result) {
			nox_netlist_addToMsgListCli_40EBC0(*(unsigned char*)(*(uint32_t*)(*(uint32_t*)(j + 748) + 276) + 2064), 1,
											   a2, 10);
			result = nox_xxx_getNextPlayerUnit_4DA7F0(j);
		}
		break;
	case 14:
		*a2 = -87;
		a2[1] = a1;
		result = nox_xxx_getFirstPlayerUnit_4DA7C0();
		for (k = result; result; k = result) {
			nox_netlist_addToMsgListCli_40EBC0(*(unsigned char*)(*(uint32_t*)(*(uint32_t*)(k + 748) + 276) + 2064), 1,
											   a2, 11);
			result = nox_xxx_getNextPlayerUnit_4DA7F0(k);
		}
		break;
	default:
		return result;
	}
	return result;
}

//----- (004DA2C0) --------------------------------------------------------
void nox_xxx_netPriMsgToPlayer_4DA2C0(int a1, const char* a2, char a3) {
	int v3;      // edx
	char v4[52]; // [esp+Ch] [ebp-34h]

	if (a1 && *(uint8_t*)(a1 + 8) & 4 && a2 && !sub_419E60(a1) && strlen(a2) && strlen(a2) <= 0x30) {
		v4[2] = a3;
		v4[0] = -87;
		v4[1] = 15;
		v3 = *(uint32_t*)(a1 + 748);
		strcpy(&v4[3], a2);
		nox_netlist_addToMsgListCli_40EBC0(*(unsigned char*)(*(uint32_t*)(v3 + 276) + 2064), 1, v4, strlen(a2) + 4);
	}
}

//----- (004DA390) --------------------------------------------------------
int nox_xxx_netPrintLineToAll_4DA390(const char* a1) {
	int result; // eax
	int i;      // esi

	result = nox_xxx_getFirstPlayerUnit_4DA7C0();
	for (i = result; result; i = result) {
		nox_xxx_netPriMsgToPlayer_4DA2C0(i, a1, 0);
		result = nox_xxx_getNextPlayerUnit_4DA7F0(i);
	}
	return result;
}

//----- (004DA3C0) --------------------------------------------------------
uint32_t* nox_get_and_zero_server_objects_4DA3C0(void) {
	uint32_t* p = nox_server_objects_1556844;
	nox_server_objects_1556844 = 0;
	return p;
}

//----- (004DA3E0) --------------------------------------------------------
void nox_set_server_objects_4DA3E0(void* p) { nox_server_objects_1556844 = p; }

//----- (004DA3F0) --------------------------------------------------------
int nox_server_strcmpWithoutMapname_4DA3F0(const char* a1, const char* a2) {
	char* v2;       // eax
	const char* v3; // edi
	const char* v4; // ebx
	char* v5;       // eax
	const char* v6; // ecx
	const char* v7; // esi
	int result;     // eax

	strcpy((char*)getMemAt(0x5D4594, 1556332), a1);
	strcpy((char*)getMemAt(0x5D4594, 1556588), a2);
	v2 = strchr((const char*)getMemAt(0x5D4594, 1556332), 58);
	if (v2) {
		v3 = (const char*)getMemAt(0x5D4594, 1556332);
		*v2 = 0;
		v4 = v2 + 1;
	} else {
		v3 = 0;
		v4 = (const char*)getMemAt(0x5D4594, 1556332);
	}
	v5 = strchr((const char*)getMemAt(0x5D4594, 1556588), 58);
	if (v5) {
		v6 = (const char*)getMemAt(0x5D4594, 1556588);
		*v5 = 0;
		v7 = v5 + 1;
	} else {
		v6 = 0;
		v7 = (const char*)getMemAt(0x5D4594, 1556588);
	}
	if (v3 && v6 && _strcmpi(v3, v6)) {
		result = 0;
	} else {
		result = strcmp(v4, v7) == 0;
	}
	return result;
}

//----- (004DA4F0) --------------------------------------------------------
int nox_xxx_getObjectByScrName_4DA4F0(char* a1) {
	int i;      // esi
	int result; // eax
	int v3;     // esi
	int v4;     // esi
	int v5;     // esi

	if (strchr(a1, ':')) {
		for (i = nox_server_getFirstObject_4DA790(); i; i = nox_server_getNextObject_4DA7A0(i)) {
			result = sub_4DA5C0(i, a1);
			if (result) {
				return result;
			}
		}
		v3 = nox_server_getFirstObjectUninited_4DA870();
		if (v3) {
			do {
				result = sub_4DA5C0(v3, a1);
				if (result) {
					break;
				}
				result = nox_server_getNextObjectUninited_4DA880(v3);
				v3 = result;
			} while (result);
			return result;
		}
		return 0;
	}
	v4 = nox_server_getFirstObject_4DA790();
	if (v4) {
		while (1) {
			result = sub_4DA660(v4, a1);
			if (result) {
				break;
			}
			v4 = nox_server_getNextObject_4DA7A0(v4);
			if (!v4) {
				goto LABEL_12;
			}
		}
	} else {
	LABEL_12:
		v5 = nox_server_getFirstObjectUninited_4DA870();
		if (!v5) {
			return 0;
		}
		while (1) {
			result = sub_4DA660(v5, a1);
			if (result) {
				break;
			}
			v5 = nox_server_getNextObjectUninited_4DA880(v5);
			if (!v5) {
				return 0;
			}
		}
	}
	return result;
}

//----- (004DA5C0) --------------------------------------------------------
int sub_4DA5C0(int a1, const char* a2) {
	int v2; // edi

	v2 = a1;
	if (*(uint32_t*)a1 && !strcmp(*(const char**)a1, a2)) {
		return v2;
	}
	v2 = *(uint32_t*)(a1 + 504);
	if (v2) {
		while (!*(uint32_t*)v2 || strcmp(*(const char**)v2, a2)) {
			v2 = *(uint32_t*)(v2 + 496);
			if (!v2) {
				return 0;
			}
		}
		return v2;
	}
	return 0;
}

//----- (004DA660) --------------------------------------------------------
int sub_4DA660(int a1, const char* a2) {
	int i;             // edi
	char* v3;          // eax
	const char* v4;    // esi
	const char* v5;    // eax
	bool v6;           // cf
	unsigned char v7;  // dl
	unsigned char v8;  // bl
	int v9;            // eax
	const char* v10;   // eax
	unsigned char v11; // dl
	unsigned char v12; // bl
	char* v14;         // eax

	i = a1;
	if (*(uint32_t*)a1) {
		v3 = strchr(*(const char**)a1, 58);
		v4 = a2;
		if (v3) {
			v5 = v3 + 1;
			while (1) {
				v6 = *v5 < (unsigned int)*v4;
				if (*v5 != *v4) {
					break;
				}
				if (*v5) {
					v7 = v5[1];
					v8 = v4[1];
					v6 = v7 < v8;
					if (v7 != v8) {
						break;
					}
					v5 += 2;
					v4 += 2;
					if (v7) {
						continue;
					}
				}
				v9 = 0;
				goto LABEL_16;
			}
		} else {
			v10 = *(const char**)a1;
			while (1) {
				v6 = *v10 < (unsigned int)*v4;
				if (*v10 != *v4) {
					break;
				}
				if (*v10) {
					v11 = v10[1];
					v12 = v4[1];
					v6 = v11 < v12;
					if (v11 != v12) {
						break;
					}
					v10 += 2;
					v4 += 2;
					if (v11) {
						continue;
					}
				}
				v9 = 0;
				goto LABEL_16;
			}
		}
		v9 = -(int)v6 - ((int)v6 - 1);
	LABEL_16:
		if (!v9) {
			return i;
		}
	}
	for (i = *(uint32_t*)(a1 + 504); i; i = *(uint32_t*)(i + 496)) {
		if (*(uint32_t*)i) {
			v14 = strchr(*(const char**)i, 58);
			if (v14) {
				if (!strcmp(v14 + 1, a2)) {
					return i;
				}
			} else if (!strcmp(*(const char**)i, a2)) {
				return i;
			}
		}
	}
	return 0;
}

//----- (004DA790) --------------------------------------------------------
nox_object_t* nox_server_getFirstObject_4DA790() { return nox_server_objects_1556844; }

//----- (004DA7A0) --------------------------------------------------------
nox_object_t* nox_server_getNextObject_4DA7A0(const nox_object_t* obj) {
	const int a1 = obj;
	int result; // eax

	if (a1) {
		result = *(uint32_t*)(a1 + 444);
	} else {
		result = 0;
	}
	return result;
}

//----- (004DA7C0) --------------------------------------------------------
nox_object_t* nox_xxx_getFirstPlayerUnit_4DA7C0() {
	for (nox_playerInfo* p = nox_common_playerInfoGetFirst_416EA0(); p; p = nox_common_playerInfoGetNext_416EE0(p)) {
		if (p->playerUnit) {
			return p->playerUnit;
		}
	}
	return 0;
}

//----- (004DA7F0) --------------------------------------------------------
nox_object_t* nox_xxx_getNextPlayerUnit_4DA7F0(const nox_object_t* obj) {
	const int a1 = obj;
	char* v1; // eax

	if (!a1) {
		return 0;
	}
	if (!(*(uint8_t*)(a1 + 8) & 4)) {
		return 0;
	}
	v1 = nox_common_playerInfoGetNext_416EE0(*(uint32_t*)(*(uint32_t*)(a1 + 748) + 276));
	if (!v1) {
		return 0;
	}
	while (!*((uint32_t*)v1 + 514)) {
		v1 = nox_common_playerInfoGetNext_416EE0((int)v1);
		if (!v1) {
			return 0;
		}
	}
	return *((uint32_t*)v1 + 514);
}

//----- (004DA840) --------------------------------------------------------
nox_object_t* nox_xxx_getFirstUpdatable2Object_4DA840() { return nox_server_objects_updatable2_1556848; }

//----- (004DA850) --------------------------------------------------------
nox_object_t* nox_xxx_getNextUpdatable2Object_4DA850(const nox_object_t* obj) {
	int a1 = (int)obj;
	int result; // eax

	if (a1) {
		result = *(uint32_t*)(a1 + 444);
	} else {
		result = 0;
	}
	return result;
}

//----- (004DA870) --------------------------------------------------------
nox_object_t* nox_server_getFirstObjectUninited_4DA870() { return nox_server_objects_uninited_1556860; }

//----- (004DA880) --------------------------------------------------------
nox_object_t* nox_server_getNextObjectUninited_4DA880(const nox_object_t* obj) {
	const int a1 = obj;
	int result; // eax

	if (a1) {
		result = *(uint32_t*)(a1 + 444);
	} else {
		result = 0;
	}
	return result;
}

//----- (004DA8A0) --------------------------------------------------------
nox_object_t* nox_xxx_getFirstUpdatableObject_4DA8A0() { return nox_server_object_updateable_1556852; }

//----- (004DA8B0) --------------------------------------------------------
nox_object_t* nox_xxx_getNextUpdatableObject_4DA8B0(const nox_object_t* obj) {
	const int a1 = obj;
	int result; // eax

	if (a1) {
		result = *(uint32_t*)(a1 + 476);
	} else {
		result = 0;
	}
	return result;
}

//----- (004DA8D0) --------------------------------------------------------
nox_object_t* nox_xxx_unitAddToUpdatable_4DA8D0(const nox_object_t* obj) {
	const int a1 = obj;
	int result; // eax

	result = a1;
	if (!*(uint32_t*)(a1 + 484) && !(*(uint8_t*)(a1 + 8) & 1)) {
		*(uint32_t*)(a1 + 480) = 0;
		*(uint32_t*)(a1 + 476) = nox_server_object_updateable_1556852;
		if (nox_server_object_updateable_1556852) {
			nox_server_object_updateable_1556852->field_120 = a1;
		}
		nox_server_object_updateable_1556852 = a1;
		*(uint32_t*)(a1 + 484) = 1;
		*(uint32_t*)(a1 + 520) = 0;
	}
	return result;
}

//----- (004DA920) --------------------------------------------------------
uint32_t* nox_xxx_unitRemoveFromUpdatable_4DA920(uint32_t* a1) {
	uint32_t* result; // eax
	int v2;           // ecx
	int v3;           // ecx
	int v4;           // ecx

	result = a1;
	if (a1[121]) {
		v2 = a1[120];
		if (v2) {
			*(uint32_t*)(v2 + 476) = a1[119];
			v3 = a1[119];
			if (v3) {
				*(uint32_t*)(v3 + 480) = a1[120];
				a1[121] = 0;
				a1[130] = 0;
				return result;
			}
		} else {
			nox_server_object_updateable_1556852 = a1[119];
			v4 = a1[119];
			if (v4) {
				*(uint32_t*)(v4 + 480) = 0;
			}
		}
		a1[121] = 0;
		a1[130] = 0;
	}
	return result;
}

//----- (004DA9A0) --------------------------------------------------------
uint32_t* nox_xxx_unitNewAddShadow_4DA9A0(uint32_t* a1) {
	uint32_t* result; // eax
	int v2;           // ecx

	result = a1;
	v2 = a1[4];
	if (!(v2 & 0x410000)) {
		a1[118] = 0;
		a1[4] = v2 | 0x10000;
		a1[117] = dword_5d4594_1556856;
		if (dword_5d4594_1556856) {
			*(uint32_t*)(dword_5d4594_1556856 + 472) = a1;
		}
		dword_5d4594_1556856 = a1;
	}
	return result;
}

//----- (004DA9F0) --------------------------------------------------------
uint32_t* nox_xxx_action_4DA9F0(uint32_t* a1) {
	uint32_t* result; // eax
	int v2;           // ecx
	int v3;           // ecx
	int v4;           // ecx

	result = a1;
	v2 = a1[4];
	if (v2 & 0x10000) {
		a1[4] = v2 & 0xFFFEFFFF;
		v3 = a1[118];
		if (v3) {
			*(uint32_t*)(v3 + 468) = a1[117];
		} else {
			dword_5d4594_1556856 = a1[117];
		}
		v4 = a1[117];
		if (v4) {
			*(uint32_t*)(v4 + 472) = a1[118];
		}
	}
	return result;
}

//----- (004DAA50) --------------------------------------------------------
void nox_xxx_createAt_4DAA50(nox_object_t* obj, int a2, float a3, float a4) {
	int a1 = obj;
	int v4; // eax
	int v5; // eax
	int v6; // ecx
	int v7; // eax

	if (!*getMemU32Ptr(0x5D4594, 1556864)) {
		*getMemU32Ptr(0x5D4594, 1556864) = nox_xxx_getNameId_4E3AA0("Gold");
		*getMemU32Ptr(0x5D4594, 1556868) = nox_xxx_getNameId_4E3AA0("QuestGoldPile");
		*getMemU32Ptr(0x5D4594, 1556872) = nox_xxx_getNameId_4E3AA0("QuestGoldChest");
	}
	v4 = *(uint32_t*)(a1 + 16);
	if (v4 & 0x24) {
		return;
	}
	*(uint32_t*)(a1 + 16) = v4 & 0x35E9FEDB;
	*(float*)(a1 + 72) = a3;
	*(float*)(a1 + 56) = a3;
	*(float*)(a1 + 64) = a3;
	*(float*)(a1 + 76) = a4;
	*(float*)(a1 + 60) = a4;
	v5 = *(uint32_t*)(a1 + 56);
	*(float*)(a1 + 68) = a4;
	*(uint32_t*)(a1 + 156) = v5;
	*(float*)(a1 + 160) = a4;
	nox_xxx_objectUnkUpdateCoords_4E7290(a1);
	if (*(uint8_t*)(a1 + 8) & 6) {
		nox_xxx_unitPostCreateNotify_4E7F10(a1);
	}
	if (a2) {
		nox_xxx_unitSetOwner_4EC290(a2, a1);
	}
	v6 = *(uint32_t*)(a1 + 16);
	*(uint32_t*)(a1 + 80) = 0;
	*(uint32_t*)(a1 + 84) = 0;
	*(uint32_t*)(a1 + 88) = 0;
	*(uint32_t*)(a1 + 92) = 0;
	*(uint32_t*)(a1 + 16) = v6 | 4;
	*(uint32_t*)(a1 + 136) = nox_frame_xxx_2598000;
	*(uint32_t*)(a1 + 128) = nox_frame_xxx_2598000;
	if (nox_common_gameFlags_check_40A5C0(0x2000) && !nox_common_gameFlags_check_40A5C0(4096) &&
		(*(unsigned short*)(a1 + 4) == *getMemU32Ptr(0x5D4594, 1556864) || *(uint32_t*)(a1 + 8) & 0x3001110) &&
		!(*(uint8_t*)(a1 + 8) & 1)) {
		v7 = *(uint32_t*)(a1 + 16);
		LOBYTE(v7) = v7 | 0x40;
		*(uint32_t*)(a1 + 16) = v7;
	}
	*(uint32_t*)(a1 + 448) = 0;
	*(uint32_t*)(a1 + 444) = nox_server_objects_uninited_1556860;
	if (nox_server_objects_uninited_1556860) {
		*(uint32_t*)((uintptr_t)nox_server_objects_uninited_1556860 + 448) = a1;
	}
	nox_server_objects_uninited_1556860 = a1;
	uint8_t v4b = *(uint8_t*)(a1 + 52);
	*(uint32_t*)(a1 + 16) |= 0x2000000u;
	if (v4b && (!(*(uint32_t*)(a1 + 8) & 0x10000000) || (int)*getMemU32Ptr(0x973F18, 3800) >= 0)) {
		if (nox_common_gameFlags_check_40A5C0(2048) || nox_xxx_CheckGameplayFlags_417DA0(4) != 0) {
			nox_xxx_createAtImpl_4191D0(*(uint8_t*)(a1 + 52), a1 + 48, 0, *(uint32_t*)(a1 + 36), 0);
		}
	}
}

//----- (004DAC00) --------------------------------------------------------
void nox_xxx_unitsNewAddToList_4DAC00() {
	int i;                     // ebp
	int v3;                    // eax
	void (*v4)(int, uint32_t); // eax
	unsigned int v5;           // ecx
	int v6;                    // eax

	if (!nox_server_objects_uninited_1556860) {
		nox_server_objects_uninited_1556860 = 0;
		return;
	}

	for (int v0 = nox_server_objects_uninited_1556860; v0; v0 = i) {
		i = *(uint32_t*)(v0 + 444);
		for (int j = *(uint32_t*)(v0 + 508); j; j = *(uint32_t*)(v0 + 508)) {
			if (!(*(uint8_t*)(j + 16) & 0x20)) {
				break;
			}
			nox_xxx_unitSetOwner_4EC290(*(uint32_t*)(j + 508), v0);
		}
		if (*(uint8_t*)(v0 + 8) & 1) {
			*(uint32_t*)(v0 + 448) = 0;
			*(uint32_t*)(v0 + 444) = nox_server_objects_updatable2_1556848;
			if (nox_server_objects_updatable2_1556848) {
				*(uint32_t*)((uint32_t)nox_server_objects_updatable2_1556848 + 448) = v0;
			}
			nox_server_objects_updatable2_1556848 = v0;
		} else {
			v3 = *(uint32_t*)(v0 + 16);
			if (v3 & 0x10000) {
				*(uint32_t*)(v0 + 16) = v3 & 0xFFFEFFFF;
				nox_xxx_unitNewAddShadow_4DA9A0((uint32_t*)v0);
			}
			if (*(uint32_t*)(v0 + 16) & 0x80000 && !nox_common_gameFlags_check_40A5C0(4096)) {
				nox_xxx_respawnAdd_4EC5E0(v0);
			}
			if ((*(uint32_t*)(v0 + 744) || *(float*)(v0 + 80) != 0.0 || *(float*)(v0 + 84) != 0.0) &&
				(signed char)*(uint8_t*)(v0 + 8) >= 0) {
				nox_xxx_unitAddToUpdatable_4DA8D0(v0);
			}
			*(uint32_t*)(v0 + 448) = 0;
			*(uint32_t*)(v0 + 444) = nox_server_objects_1556844;
			if (nox_server_objects_1556844) {
				*(uint32_t*)((uintptr_t)nox_server_objects_1556844 + 448) = v0;
			}
			nox_set_server_objects_4DA3E0(v0);
		}
		nox_xxx_unitCreateMissileSmth_517640(v0);
		if (*(uint32_t*)(v0 + 696)) {
			sub_5117F0(v0);
		}
		v4 = *(void (**)(int, uint32_t))(v0 + 688);
		if (v4) {
			v4(v0, 0);
		}
		v5 = *(uint32_t*)(v0 + 8);
		if (v5 & 0x400000) {
			if (*(uint32_t*)(v0 + 12) & 0x18) {
				v6 = 0;
			} else {
				v6 = (unsigned char)~*(uint8_t*)(v0 + 12) >> 7;
			}
		} else {
			v6 = (v5 >> 29) & 1;
		}
		if (0x800000 & v5 || !v6) {
			nox_xxx_unitNeedSync_4E44F0(v0);
			if (!(*(uint32_t*)(v0 + 8) & 0x20400000)) {
				*(uint32_t*)(v0 + 148) = 0;
			}
		} else {
			nox_xxx_objectMakeUnseenByNoone_4E44E0(v0);
			sub_527E00(v0);
			*(uint32_t*)(v0 + 148) = -1;
		}
		*(uint32_t*)(v0 + 16) &= 0xFDFFFFFF;
	}
	nox_server_objects_uninited_1556860 = 0;
}

//----- (004DADE0) --------------------------------------------------------
char nox_xxx_servFinalizeDelObject_4DADE0(nox_object_t* item) {
	const int a1 = (int)item;
	int v1; // eax

	v1 = *(uint32_t*)&item->field_4;
	if (v1 & 4) {
		LOBYTE(v1) = v1 & 0xFB;
		*(uint32_t*)&item->field_4 = v1;
		nox_xxx_playerLeaveObsByObserved_4E60A0(a1);
		if (!nox_common_gameFlags_check_40A5C0(0x80000)) {
			nox_xxx_netReportDestroyObject_5289D0(a1);
		}
		nox_xxx_unit_511810(a1);
		nox_xxx_unitClearOwner_4EC300(item);
		nox_xxx_unitRemoveChild_4EC470(a1);
		sub_517870(a1);
		sub_4DAE50(a1);
		sub_4ECFA0(a1);
		sub_511DE0(a1);
		LOBYTE(v1) = *(uint8_t*)&item->obj_class;
		if (v1 & 6) {
			LOBYTE(v1) = sub_528990(a1);
		}
	}
	return v1;
}

//----- (004DAE50) --------------------------------------------------------
int sub_4DAE50(int a1) {
	int v1;     // eax
	int result; // eax
	int v3;     // esi
	int v4;     // eax
	int v5;     // esi

	nox_xxx_action_4DA9F0((uint32_t*)a1);
	if (*(uint8_t*)(a1 + 8) & 1) {
		v1 = *(uint32_t*)(a1 + 448);
		if (v1) {
			*(uint32_t*)(v1 + 444) = *(uint32_t*)(a1 + 444);
			result = *(uint32_t*)(a1 + 444);
			if (result) {
				*(uint32_t*)(result + 448) = *(uint32_t*)(a1 + 448);
			}
		} else {
			result = *(uint32_t*)(a1 + 444);
			nox_server_objects_updatable2_1556848 = *(uint32_t*)(a1 + 444);
			v3 = *(uint32_t*)(a1 + 444);
			if (v3) {
				*(uint32_t*)(v3 + 448) = 0;
			}
		}
	} else {
		nox_xxx_unitRemoveFromUpdatable_4DA920((uint32_t*)a1);
		v4 = *(uint32_t*)(a1 + 448);
		if (v4) {
			*(uint32_t*)(v4 + 444) = *(uint32_t*)(a1 + 444);
			result = *(uint32_t*)(a1 + 444);
			if (result) {
				*(uint32_t*)(result + 448) = *(uint32_t*)(a1 + 448);
			}
		} else {
			result = *(uint32_t*)(a1 + 444);
			nox_set_server_objects_4DA3E0(*(uint32_t*)(a1 + 444));
			v5 = *(uint32_t*)(a1 + 444);
			if (v5) {
				*(uint32_t*)(v5 + 448) = 0;
			}
		}
	}
	return result;
}

//----- (004DAF10) --------------------------------------------------------
void sub_4DAF10() {
	uint32_t* v0; // edi
	uint32_t* v1; // esi
	int v2;       // eax
	int v3;       // ecx
	uint32_t* v4; // eax
	int v5;       // edx
	int v6;       // edx
	int v7;       // ecx
	int v8;       // edx
	uint32_t* v9; // eax

	v0 = *(uint32_t**)&nox_server_objects_uninited_1556860;
	v1 = *(uint32_t**)&nox_server_objects_uninited_1556860;
	if (nox_server_objects_uninited_1556860) {
		do {
			v2 = v1[2];
			if (v2 & 0x4000) {
				v3 = v1[187];
				v4 = v0;
				if (v0) {
					while (1) {
						v5 = v4[2];
						if ((v5 & 0x8000) != 0) {
							v6 = v4[187];
							if (*(uint32_t*)(v3 + 8) == v4[10]) {
								break;
							}
						}
						v4 = (uint32_t*)v4[111];
						if (!v4) {
							goto LABEL_9;
						}
					}
					*(uint32_t*)(v3 + 4) = v4;
					*(uint32_t*)(v6 + 4) = v1;
					v0 = *(uint32_t**)&nox_server_objects_uninited_1556860;
				}
			}
		LABEL_9:
			if (v1[2] & 0x400) {
				v7 = v1[187];
				v8 = *(uint32_t*)(v7 + 16);
				*(uint32_t*)(v7 + 12) = 0;
				v0 = *(uint32_t**)&nox_server_objects_uninited_1556860;
				if (v8) {
					v9 = *(uint32_t**)&nox_server_objects_uninited_1556860;
					if (nox_server_objects_uninited_1556860) {
						while (!(v9[2] & 0x400) || v8 != v9[10]) {
							v9 = (uint32_t*)v9[111];
							if (!v9) {
								goto LABEL_17;
							}
						}
						*(uint32_t*)(v7 + 12) = v9;
						v0 = *(uint32_t**)&nox_server_objects_uninited_1556860;
					}
				}
			}
		LABEL_17:
			v1 = (uint32_t*)v1[111];
		} while (v1);
	}
}

//----- (004DAFD0) --------------------------------------------------------
void sub_4DAFD0(uint32_t* a1) {
	int v2; // ecx
	int v3; // ecx
	int v4; // ecx

	v2 = a1[4];
	if (!(v2 & 4)) {
		return;
	}
	a1[4] = v2 & 0xFFFFFFFB;
	v3 = a1[112];
	if (v3) {
		*(uint32_t*)(v3 + 444) = a1[111];
		v4 = a1[111];
		if (v4) {
			*(uint32_t*)(v4 + 448) = (uint32_t*)a1[112];
		}
	} else {
		uint32_t* p = (uint32_t*)a1[111];
		nox_set_server_objects_4DA3E0(p);
		if (p) {
			p[112] = 0;
		}
	}
}

//----- (004DB030) --------------------------------------------------------
uint32_t* nox_xxx_unitClearPendingMB_4DB030() {
	uint32_t* result; // eax
	uint32_t* v1;     // ecx
	int v2;           // edx

	result = *(uint32_t**)&nox_server_objects_uninited_1556860;
	if (nox_server_objects_uninited_1556860) {
		do {
			v1 = (uint32_t*)result[111];
			result[4] &= 0xFDFFFFFF;
			v2 = nox_server_objects_1556844;
			if (nox_server_objects_1556844) {
				*(uint32_t*)((uintptr_t)nox_server_objects_1556844 + 448) = result;
				v2 = nox_server_objects_1556844;
			}
			result[111] = v2;
			result[112] = 0;
			nox_set_server_objects_4DA3E0(result);
			result = v1;
		} while (v1);
	}
	nox_server_objects_uninited_1556860 = 0;
	return result;
}

//----- (004DB0A0) --------------------------------------------------------
int sub_4DB0A0() {
	*getMemU8Ptr(0x5D4594, 1560984) = getMemByte(0x5D4594, 1563136);
	dword_5d4594_1563080 = 0;
	dword_5d4594_1563084 = 0;
	dword_5d4594_1563096 = 0;
	dword_5d4594_1563064 = 0;
	dword_5d4594_1563092 = 0;
	dword_5d4594_1563088 = 0;
	dword_5d4594_1563044 = 0;
	*getMemU32Ptr(0x5D4594, 1563048) = 0;
	dword_5d4594_1563052 = 0;
	*getMemU32Ptr(0x5D4594, 1563100) = 0;
	*getMemU8Ptr(0x5D4594, 1563104) = getMemByte(0x5D4594, 1563140);
	return 1;
}

//----- (004DB100) --------------------------------------------------------
int sub_4DB100() {
	int result; // eax

	result = 0;
	dword_5d4594_1563080 = 0;
	dword_5d4594_1563084 = 0;
	dword_5d4594_1563096 = 0;
	dword_5d4594_1563064 = 0;
	dword_5d4594_1563092 = 0;
	dword_5d4594_1563088 = 0;
	*getMemU32Ptr(0x5D4594, 1563072) = 0;
	*getMemU32Ptr(0x5D4594, 1563068) = 0;
	return result;
}

//----- (004DB130) --------------------------------------------------------
unsigned int sub_4DB130(const char* a1) {
	unsigned int result; // eax

	result = strlen(a1) + 1;
	memcpy(getMemAt(0x5D4594, 1557900), a1, result);
	return result;
}

//----- (004DB170) --------------------------------------------------------
int sub_4DB170(int a1, int a2, int a3) {
	int result; // eax

	dword_5d4594_1563092 = a3;
	dword_5d4594_1563088 = nox_frame_xxx_2598000;
	result = a1;
	dword_5d4594_1563084 = a2;
	dword_5d4594_1563080 = a1;
	dword_5d4594_1563096 = a2 != 0;
	if (!a1) {
		result = sub_4DCBD0(0);
	}
	return result;
}

//----- (004DB1B0) --------------------------------------------------------
int nox_xxx_gameGet_4DB1B0() { return dword_5d4594_1563080; }

//----- (004DB1C0) --------------------------------------------------------
int sub_4DB1C0() { return dword_5d4594_1563084; }

//----- (004DB220) --------------------------------------------------------
int nox_xxx_gameSetSwitchSolo_4DB220(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 1563056) = a1;
	return result;
}

//----- (004DB230) --------------------------------------------------------
int nox_xxx_gameSetNoMPFlag_4DB230(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 1563060) = a1;
	return result;
}

//----- (004DB240) --------------------------------------------------------
int nox_xxx_gameIsSwitchToSolo_4DB240() { return *getMemU32Ptr(0x5D4594, 1563056); }

//----- (004DB250) --------------------------------------------------------
int nox_xxx_gameIsNotMultiplayer_4DB250() { return *getMemU32Ptr(0x5D4594, 1563060); }

//----- (004DB260) --------------------------------------------------------
char* nox_xxx_mapFilenameGetSolo_4DB260() { return (char*)getMemAt(0x5D4594, 1559960); }

//----- (004DB270) --------------------------------------------------------
unsigned int nox_xxx_gameSetSoloSavePath_4DB270(const char* a1) {
	unsigned int result; // eax

	result = strlen(a1) + 1;
	memcpy(getMemAt(0x5D4594, 1559960), a1, result);
	return result;
}

//----- (004DB2A0) --------------------------------------------------------
char* nox_client_checkSaveMapExistsTmp_4DB2A0(char* a1) {
	char* v1;      // eax
	char* v2;      // eax
	char v4[24];   // [esp+4h] [ebp-418h]
	char v5[1024]; // [esp+1Ch] [ebp-400h]

	strcpy(v5, a1);
	v1 = strrchr(v5, ':');
	if (v1) {
		*v1 = 0;
	}
	strcpy(&v4[4], v5);
	v4[strlen(v5)] = 0;
	v2 = nox_fs_root();
	nox_sprintf((char*)getMemAt(0x5D4594, 1558936), "%s\\Save\\%s\\%s\\%s", v2, "WORKING", &v4[4], v5);
	return _access((const char*)getMemAt(0x5D4594, 1558936), 0) != -1 ? getMemAt(0x5D4594, 1558936) : 0;
}

//----- (004DB540) --------------------------------------------------------
bool nox_client_makeSaveDir_4DB540(char* saveName) {
	char PathName[1024]; // [esp+0h] [ebp-400h]
	nox_sprintf(PathName, "%s\\Save\\%s", nox_fs_root(), saveName);
	return nox_fs_mkdir(PathName);
}

#ifndef NOX_CGO
//----- (004DB790) --------------------------------------------------------
int sub_4DB790(char* a1) {
	nox_xxx_mapLoadOrSaveMB_4DCC70(1);
	nox_xxx_setGameFlags_40A4D0(0x8000000);
	sub_43F140(500);
	int v1 = nox_xxx_soloLoadGame_4DB7E0_savegame(a1);
	sub_43F1A0();
	nox_common_gameFlags_unset_40A540(0x8000000);
	*getMemU32Ptr(0x5D4594, 1563068) = nox_frame_xxx_2598000;
	return v1;
}
#endif // NOX_CGO

//----- (004DBE10) --------------------------------------------------------
void nox_savegame_rm_4DBE10(char* saveName, int rmDir) {
	char* v8;                         // esi
	int v9;                           // ebp
	HANDLE v10;                       // ebx
	char* v11;                        // ebx
	char* v12;                        // edx
	char* v13;                        // esi
	bool v14;                         // zf
	char* v18;                        // [esp+4h] [ebp-24948h]
	int v19;                          // [esp+8h] [ebp-24944h]
	char saveDir[NOX_FILEPATH_MAX];   // [esp+14Ch] [ebp-24800h]
	char FileName[NOX_FILEPATH_MAX];  // [esp+54Ch] [ebp-24400h]
	char v23[16 * NOX_FILEPATH_MAX];  // [esp+94Ch] [ebp-24000h]
	char v24[128 * NOX_FILEPATH_MAX]; // [esp+494Ch] [ebp-20000h]

	if (!saveName) {
		return;
	}
	nox_sprintf(saveDir, "%s\\Save\\%s", nox_fs_root(), saveName);
	if (_access(saveDir, 0) == -1) {
		return;
	}
	nox_sprintf(&FileName, "%s\\Player.plr", saveDir);
	nox_fs_remove(&FileName);
	nox_fs_set_workdir(saveDir);

	int fileCnt = 0;
	struct _WIN32_FIND_DATAA find; // [esp+Ch] [ebp-24940h]
	HANDLE v5 = FindFirstFileA("*", &find);
	if (v5 != -1) {
		if (find.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY && strcmp(find.cFileName, ".") &&
			strcmp(find.cFileName, "..")) {
			strcpy(&v24[NOX_FILEPATH_MAX * fileCnt], find.cFileName);
			++fileCnt;
		}
		while (FindNextFileA(v5, &find)) {
			if (find.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY && strcmp(find.cFileName, ".") &&
				strcmp(find.cFileName, "..")) {
				strcpy(&v24[NOX_FILEPATH_MAX * fileCnt], find.cFileName);
				++fileCnt;
			}
		}
		FindClose(v5);
	}
	if (fileCnt > 0) {
		v8 = v24;
		v19 = fileCnt;
		v18 = v24;
		do {
			nox_fs_set_workdir(v8);
			v9 = 0;
			v10 = FindFirstFileA("*", &find);
			if (v10 != -1) {
				if (!(find.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
					v9 = 1;
					strcpy(v23, find.cFileName);
				}
				if (FindNextFileA(v10, &find)) {
					v11 = &v23[NOX_FILEPATH_MAX * v9];
					do {
						if (!(find.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
							v12 = v11;
							++v9;
							v11 += NOX_FILEPATH_MAX;
							strcpy(v12, find.cFileName);
						}
					} while (FindNextFileA(v10, &find));
				}
				FindClose(v10);
				if (v9 > 0) {
					v13 = v23;
					do {
						nox_fs_remove(v13);
						v13 += NOX_FILEPATH_MAX;
						--v9;
					} while (v9);
				}
				v8 = v18;
			}
			nox_fs_set_workdir("..");
			nox_fs_remove_dir(v8);
			v8 += NOX_FILEPATH_MAX;
			v14 = v19 == 1;
			v18 = v8;
			--v19;
		} while (!v14);
	}
	nox_fs_set_workdir(nox_fs_root());
	if (rmDir) {
		nox_fs_remove_dir(saveDir);
	}
}
// 4DBE10: using guessed type char var_20000[131072];
// 4DBE10: using guessed type char var_24000[16384];

//----- (004DC100) --------------------------------------------------------
int nox_client_copySave_4DC100(char* from, char* saveName) {
	int result;                            // eax
	int v5;                                // ebp
	HANDLE v6;                             // ebx
	char* v7;                              // ebx
	char* v8;                              // edx
	int v9;                                // esi
	char* v10;                             // edi
	char* v11;                             // edi
	int v12;                               // ebp
	HANDLE v13;                            // ebx
	char* v14;                             // ebx
	char* v15;                             // edx
	char* v16;                             // esi
	bool v17;                              // cc
	char* v18;                             // eax
	HANDLE hFindFile;                      // [esp+10h] [ebp-25154h]
	HANDLE hFindFilea;                     // [esp+10h] [ebp-25154h]
	int v21;                               // [esp+14h] [ebp-25150h]
	char* v22;                             // [esp+18h] [ebp-2514Ch]
	int v23;                               // [esp+1Ch] [ebp-25148h]
	int v24;                               // [esp+20h] [ebp-25144h]
	struct _WIN32_FIND_DATAA FindFileData; // [esp+24h] [ebp-25140h]
	char fromDir[1024];                   // [esp+164h] [ebp-25000h]
	char toFile[1024];                // [esp+564h] [ebp-24C00h]
	char fromFile[1024];           // [esp+964h] [ebp-24800h]
	char toDir[1024];                        // [esp+D64h] [ebp-24400h]
	char v30[16384];                       // [esp+1164h] [ebp-24000h]
	char v31[131072];                      // [esp+5164h] [ebp-20000h]

	v24 = 1;
	nox_sprintf(&fromDir, "%s\\Save\\%s", nox_fs_root(), from);
	nox_sprintf(&toDir, "%s\\Save\\%s", nox_fs_root(), saveName);
	if (!nox_client_makeSaveDir_4DB540(saveName)) {
		return 0;
	}
	nox_savegame_rm_4DBE10(saveName, 0);
	nox_sprintf(&fromFile, "%s\\Player.plr", &fromDir);
	nox_sprintf(&toFile, "%s\\Player.plr", &toDir);
	result = nox_fs_copy(&fromFile, &toFile);
	if (result) {
		result = nox_fs_set_workdir(&fromDir);
		if (result) {
			v5 = 0;
			v21 = 0;
			v6 = FindFirstFileA("*", &FindFileData);
			hFindFile = v6;
			if (v6 == (HANDLE)-1) {
				goto LABEL_48;
			}
			if (FindFileData.dwFileAttributes & 0x10 && strcmp(FindFileData.cFileName, ".") &&
				strcmp(FindFileData.cFileName, "..")) {
				v21 = 1;
				strcpy(v31, FindFileData.cFileName);
				v5 = 1;
			}
			if (FindNextFileA(v6, &FindFileData)) {
				v7 = &v31[1024 * v5];
				do {
					if (FindFileData.dwFileAttributes & 0x10 && strcmp(FindFileData.cFileName, ".") &&
						strcmp(FindFileData.cFileName, "..")) {
						v8 = v7;
						++v5;
						v7 += 1024;
						strcpy(v8, FindFileData.cFileName);
					}
				} while (FindNextFileA(hFindFile, &FindFileData));
				v6 = hFindFile;
				v21 = v5;
			}
			result = FindClose(v6);
			if (result) {
			LABEL_48:
				result = nox_fs_set_workdir(&toDir);
				if (result) {
					v9 = 0;
					if (v5 > 0) {
						v10 = v31;
						while (nox_fs_mkdir(v10)) {
							++v9;
							v10 += 1024;
							if (v9 >= v5) {
								goto LABEL_24;
							}
						}
						return 0;
					}
				LABEL_24:
					result = nox_fs_set_workdir(&fromDir);
					if (result) {
						v23 = 0;
						if (v5 > 0) {
							v11 = v31;
							v22 = v31;
							while (nox_fs_set_workdir(v11)) {
								v12 = 0;
								v13 = FindFirstFileA("*", &FindFileData);
								hFindFilea = v13;
								if (v13 != (HANDLE)-1) {
									if (!(FindFileData.dwFileAttributes & 0x10)) {
										v12 = 1;
										strcpy(v30, FindFileData.cFileName);
										v11 = v22;
									}
									if (FindNextFileA(v13, &FindFileData)) {
										v14 = &v30[1024 * v12];
										do {
											if (!(FindFileData.dwFileAttributes & 0x10)) {
												v15 = v14;
												++v12;
												v14 += 1024;
												strcpy(v15, FindFileData.cFileName);
											}
										} while (FindNextFileA(hFindFilea, &FindFileData));
										v13 = hFindFilea;
										v11 = v22;
									}
									if (!FindClose(v13)) {
										return 0;
									}
									if (v12 > 0) {
										v16 = v30;
										do {
											nox_sprintf(&fromFile, "%s\\%s\\%s", &fromDir, v11, v16);
											nox_sprintf(&toFile, "%s\\%s\\%s", &toDir, v11, v16);
											if (!nox_fs_copy(&fromFile, &toFile)) {
												v24 = 0;
											}
											v16 += 1024;
											--v12;
										} while (v12);
									}
								}
								if (!nox_fs_set_workdir("..")) {
									return 0;
								}
								v11 += 1024;
								v17 = ++v23 < v21;
								v22 = v11;
								if (!v17) {
									goto LABEL_45;
								}
							}
							return 0;
						}
					LABEL_45:
						v18 = nox_fs_root();
						result = nox_fs_set_workdir(v18) ? v24 : 0;
					}
				}
			}
		}
	}
#ifdef __EMSCRIPTEN__
	EM_ASM(FS.syncfs(false, function(err){}));
#endif
	return result;
}
// 4DC100: using guessed type char var_20000[131072];
// 4DC100: using guessed type char var_24000[16384];

//----- (004DC550) --------------------------------------------------------
int nox_client_countSaveFiles_4DC550() {
	int v0;              // ebx
	char* v1;            // edi
	char* v5;            // eax
	int v6;              // esi
	char* v7;            // eax
	char PathName[1024]; // [esp+Ch] [ebp-400h]

	v0 = 0;
	v1 = nox_fs_root();
	strcpy(PathName, v1);
	strcat(PathName, "\\Save\\");
	nox_fs_mkdir(PathName);
	v5 = nox_fs_root();
	nox_sprintf(PathName, "%s\\Save\\AUTOSAVE\\Player.plr", v5);
	if (_access(PathName, 0) != -1) {
		v0 = 1;
	}
	v6 = 13;
	do {
		v7 = nox_fs_root();
		nox_sprintf(PathName, "%s\\Save\\SAVE%04d\\Player.plr", v7, v0);
		if (_access(PathName, 0) != -1) {
			++v0;
		}
		--v6;
	} while (v6);
	return v0;
}
// 4DC550: using guessed type char PathName[1024];

//----- (004DC630) --------------------------------------------------------
int nox_client_countPlayerFiles02_4DC630() {
	int v0;                                // ebp
	char* v1;                              // edi
	HANDLE v5;                             // esi
	char* v6;                              // eax
	struct _WIN32_FIND_DATAA FindFileData; // [esp+10h] [ebp-E40h]
	char PathName[1024];                   // [esp+150h] [ebp-D00h]
	char v10[1280];                        // [esp+550h] [ebp-900h]
	char v11[1024];                        // [esp+A50h] [ebp-400h]

	v0 = 0;
	v1 = nox_fs_root();
	strcpy(PathName, v1);
	strcat(PathName, "\\Save\\");
	strcpy(v11, PathName);
	nox_fs_mkdir(PathName);
	nox_fs_set_workdir(PathName);
	v5 = FindFirstFileA("*.plr", &FindFileData);
	if (v5 != (HANDLE)-1) {
		if (!(FindFileData.dwFileAttributes & 0x10)) {
			nox_sprintf(PathName, "%s%s", v11, FindFileData.cFileName);
			sub_41A000(PathName, v10);
			if (v10[0] & 2) {
				v0 = 1;
			}
		}
		while (FindNextFileA(v5, &FindFileData)) {
			if (!(FindFileData.dwFileAttributes & 0x10)) {
				nox_sprintf(PathName, "%s%s", v11, FindFileData.cFileName);
				sub_41A000(PathName, v10);
				if (v10[0] & 2) {
					++v0;
				}
			}
		}
		FindClose(v5);
	}
	v6 = nox_fs_root();
	nox_fs_set_workdir(v6);
	return v0;
}
// 4DC630: using guessed type char PathName[1024];

//----- (004DC7D0) --------------------------------------------------------
int nox_client_countPlayerFiles04_4DC7D0() {
	int v0;                                // ebp
	char* v1;                              // edi
	HANDLE v5;                             // esi
	char* v6;                              // eax
	struct _WIN32_FIND_DATAA FindFileData; // [esp+10h] [ebp-E40h]
	char PathName[1024];                   // [esp+150h] [ebp-D00h]
	char v10[1280];                        // [esp+550h] [ebp-900h]
	char v11[1024];                        // [esp+A50h] [ebp-400h]

	v0 = 0;
	v1 = nox_fs_root();
	strcpy(PathName, v1);
	strcat(PathName, "\\Save\\");
	strcpy(v11, PathName);
	nox_fs_mkdir(PathName);
	nox_fs_set_workdir(PathName);
	v5 = FindFirstFileA("*.plr", &FindFileData);
	if (v5 != (HANDLE)-1) {
		if (!(FindFileData.dwFileAttributes & 0x10)) {
			nox_sprintf(PathName, "%s%s", v11, FindFileData.cFileName);
			sub_41A000(PathName, v10);
			if (v10[0] & 4) {
				v0 = 1;
			}
		}
		while (FindNextFileA(v5, &FindFileData)) {
			if (!(FindFileData.dwFileAttributes & 0x10)) {
				nox_sprintf(PathName, "%s%s", v11, FindFileData.cFileName);
				sub_41A000(PathName, v10);
				if (v10[0] & 4) {
					++v0;
				}
			}
		}
		FindClose(v5);
	}
	v6 = nox_fs_root();
	nox_fs_set_workdir(v6);
	return v0;
}
// 4DC7D0: using guessed type char PathName[1024];

//----- (004DC970) --------------------------------------------------------
void nox_savegame_nameFromPath_4DC970(char* src, char* dst) {
	if (!src || !dst) {
		return;
	}
	char* p = strrchr(src, '\\');
	if (!p) {
		return;
	}
	strncpy(dst, p - 8, 8);
	dst[8] = 0;
}

//----- (004DC9B0) --------------------------------------------------------
char* sub_4DC9B0(char* a1) {
	char* result; // eax
	char v2[12];  // [esp+0h] [ebp-Ch]

	if (!a1) {
		return (char*)-1;
	}
	result = strrchr(a1, 92);
	if (result) {
		strncpy(v2, result - 4, 4u);
		v2[4] = 0;
		result = (char*)atoi(v2);
	}
	return result;
}

//----- (004DCA00) --------------------------------------------------------
char* nox_xxx_unused_4DCA00() {
	unsigned int v0;                       // ebp
	char* v1;                              // eax
	HANDLE v2;                             // ebx
	char* v3;                              // eax
	char* v4;                              // eax
	struct _WIN32_FIND_DATAA FindFileData; // [esp+8h] [ebp-D40h]
	char FileName[1024];                   // [esp+148h] [ebp-C00h]
	char PathName[1024];                   // [esp+548h] [ebp-800h]
	char Buffer[1024];                     // [esp+948h] [ebp-400h]

	v0 = 2;
	nox_fs_workdir(Buffer, 1024);
	v1 = nox_fs_root();
	nox_sprintf(PathName, "%s\\Save\\", v1);
	nox_fs_set_workdir(PathName);
	v2 = FindFirstFileA("*", &FindFileData);
	if (v2 != (HANDLE)-1) {
		if (FindFileData.dwFileAttributes & 0x10) {
			if (strcmp(FindFileData.cFileName, "..")) {
				if (strcmp(FindFileData.cFileName, ".")) {
					nox_sprintf(FileName, "%s%s\\Player.plr", PathName, FindFileData.cFileName);
					if (_access(FileName, 0) != -1) {
						v3 = sub_4DC9B0(FileName);
						if ((unsigned int)v3 >= 2) {
							v0 = (unsigned int)(v3 + 1);
						}
					}
				}
			}
		}
		while (FindNextFileA(v2, &FindFileData)) {
			if (FindFileData.dwFileAttributes & 0x10) {
				if (strcmp(FindFileData.cFileName, "..")) {
					if (strcmp(FindFileData.cFileName, ".")) {
						nox_sprintf(FileName, "%s%s\\Player.plr", PathName, FindFileData.cFileName);
						if (_access(FileName, 0) != -1) {
							v4 = sub_4DC9B0(FileName);
							if ((unsigned int)v4 >= v0) {
								v0 = (unsigned int)(v4 + 1);
							}
						}
					}
				}
			}
		}
		FindClose(v2);
	}
	nox_fs_set_workdir(Buffer);
	if (v0 > 0x270F) {
		return 0;
	}
	nox_sprintf((char*)getMemAt(0x5D4594, 1563032), "SAVE%04d", v0);
	return (char*)getMemAt(0x5D4594, 1563032);
}

//----- (004DCBD0) --------------------------------------------------------
int sub_4DCBD0(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 1563076) = a1;
	return result;
}

//----- (004DCBE0) --------------------------------------------------------
int sub_4DCBE0() { return *getMemU32Ptr(0x5D4594, 1563076); }

//----- (004DCBF0) --------------------------------------------------------
int sub_4DCBF0(int a1) {
	int result; // eax

	result = a1;
	dword_5d4594_1563064 = a1;
	return result;
}

//----- (004DCC10) --------------------------------------------------------
int sub_4DCC10(nox_object_t* a1p) {
	int a1 = a1p;
	int v1;     // esi
	int v2;     // eax
	int result; // eax

	v1 = 1;
	if (dword_5d4594_1563092 && (unsigned int)(dword_5d4594_1563092 + dword_5d4594_1563088) > nox_frame_xxx_2598000) {
		v1 = 0;
	}
	if (*(uint32_t*)(*(uint32_t*)(a1 + 748) + 284)) {
		v1 = 0;
	}
	v2 = *(uint32_t*)(a1 + 16);
	if (v2 & 2) {
		v1 = 0;
	}
	if ((v2 & 0x8000) != 0) {
		v1 = 0;
	}
	if (sub_45D9B0() == 1) {
		result = 0;
	} else {
		result = v1;
	}
	return result;
}

//----- (004DCC70) --------------------------------------------------------
int nox_xxx_mapLoadOrSaveMB_4DCC70(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 1563072) = a1;
	return result;
}

//----- (004DCC90) --------------------------------------------------------
int sub_4DCC90() {
	int result; // eax

	result = 1;
	if (dword_5d4594_1563080 != 1) {
		result = dword_5d4594_1563092 != 0;
	}
	return result;
}

//----- (004DCCB0) --------------------------------------------------------
int nox_xxx_game_4DCCB0() {
	int result; // eax
	char* v1;   // eax
	int v2;     // esi
	int v3;     // eax

	if (!nox_common_gameFlags_check_40A5C0(2048)) {
		return 1;
	}
	v1 = nox_common_playerInfoFromNum_417090(31);
	if (!v1 || (v2 = *((uint32_t*)v1 + 514)) == 0 || sub_4DCC90() || sub_4139B0() ||
		(unsigned int)(nox_frame_xxx_2598000 - *getMemU32Ptr(0x5D4594, 1563068)) < 0x1E || nox_xxx_guiCursor_477600() ||
		(v3 = *(uint32_t*)(v2 + 16), BYTE1(v3) & 0x40)) {
		result = 0;
	} else {
		result = sub_4DCC10(v2) != 0;
	}
	return result;
}

//----- (004DCD40) --------------------------------------------------------
int sub_4DCD40() {
	char* v0;            // eax
	int result;          // eax
	int i;               // esi
	int v3;              // eax
	int v4;              // edi
	char FileName[1024]; // [esp+4h] [ebp-400h]

	*getMemU32Ptr(0x5D4594, 1563048) = sub_416A00();
	sub_4169E0();
	dword_5d4594_1563044 = 1;
	v0 = nox_fs_root();
	nox_sprintf(FileName, "%s\\Save\\_temp_.dat", v0);
	result = nox_xxx_getFirstPlayerUnit_4DA7C0();
	for (i = result; result; i = result) {
		v3 = *(uint32_t*)(i + 748);
		v4 = *(uint32_t*)(v3 + 276);
		if (*(uint32_t*)(v4 + 4792) && *(uint32_t*)(v3 + 552) != 1) {
			if (nox_xxx_playerSaveToFile_41A140(FileName, *(unsigned char*)(v4 + 2064))) {
				sub_41CFA0(FileName, *(unsigned char*)(v4 + 2064));
			}
			nox_fs_remove(FileName);
		}
		result = nox_xxx_getNextPlayerUnit_4DA7F0(i);
	}
	return result;
}

//----- (004DCE00) --------------------------------------------------------
int sub_4DCE00() {
	int result; // eax

	result = dword_5d4594_1563044;
	if (dword_5d4594_1563044) {
		result = sub_419F00();
		if (!result) {
			result = sub_4DCE30();
			dword_5d4594_1563044 = 0;
		}
	}
	return result;
}

//----- (004DCE30) --------------------------------------------------------
int sub_4DCE30() {
	if (!*getMemU32Ptr(0x5D4594, 1563048)) {
		sub_4169F0();
	}
	return sub_446140();
}

//----- (004DCE60) --------------------------------------------------------
int sub_4DCE60(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 1563100) = a1;
	return result;
}

//----- (004DCE70) --------------------------------------------------------
int sub_4DCE70() { return *getMemU32Ptr(0x5D4594, 1563100); }

//----- (004DCE80) --------------------------------------------------------
int sub_4DCE80(const char* a1) {
	int result; // eax

	result = 0;
	if (a1) {
		strcpy((char*)getMemAt(0x5D4594, 1563104), a1);
	} else {
		*getMemU32Ptr(0x5D4594, 1563104) = 0;
		*getMemU32Ptr(0x5D4594, 1563108) = 0;
		*getMemU32Ptr(0x5D4594, 1563112) = 0;
		*getMemU32Ptr(0x5D4594, 1563116) = 0;
		*getMemU32Ptr(0x5D4594, 1563120) = 0;
	}
	return result;
}

//----- (004DCED0) --------------------------------------------------------
char* nox_xxx_getQuestMapName_4DCED0() { return getMemAt(0x5D4594, 1563104); }

//----- (004DCEE0) --------------------------------------------------------
void sub_4DCEE0(const char* a1) {
	if (a1) {
		strcpy((char*)getMemAt(0x5D4594, 1560984), a1);
		dword_5d4594_1563052 = 1;
	} else {
		dword_5d4594_1563052 = 0;
	}
}

//----- (004DCF80) --------------------------------------------------------
int nox_xxx_sendGauntlet_4DCF80(int a1, char a2) {
	char v4[3]; // [esp+0h] [ebp-4h]
	v4[0] = -16;
	v4[1] = 28;
	v4[2] = a2;
	return nox_xxx_netSendPacket1_4E5390(a1, (int)v4, 3, 0, 0);
}

//----- (004DCFB0) --------------------------------------------------------
char sub_4DCFB0(int a1) {
	char result;         // al
	int v2;              // edi
	int v3;              // esi
	int v4;              // ecx
	char* v5;            // eax
	char FileName[1024]; // [esp+8h] [ebp-400h]

	result = a1;
	v2 = 1;
	if (a1) {
		v3 = *(uint32_t*)(a1 + 748);
		v4 = *(uint32_t*)(v3 + 276);
		result = *(uint8_t*)(v4 + 2064);
		if (result != 31) {
			if (*(uint32_t*)(v4 + 4792) && *(uint32_t*)(v3 + 552) != 1) {
				if (sub_419EE0(*(uint8_t*)(v4 + 2064))) {
					goto LABEL_13;
				}
				v5 = nox_fs_root();
				nox_sprintf(FileName, "%s\\Save\\_temp_.dat", v5);
				if (nox_xxx_playerSaveToFile_41A140(FileName, *(unsigned char*)(*(uint32_t*)(v3 + 276) + 2064))) {
					v2 = sub_41CFA0(FileName, *(unsigned char*)(*(uint32_t*)(v3 + 276) + 2064));
				}
				result = nox_fs_remove(FileName);
				if (v2) {
				LABEL_13:
					result = nox_xxx_player_4D7960(*(uint8_t*)(*(uint32_t*)(v3 + 276) + 2064));
				}
			} else {
				result = (unsigned int)nox_xxx_playerCallDisconnect_4DEAB0(*(unsigned char*)(v4 + 2064), 4);
			}
		}
	}
	return result;
}

//----- (004DD0B0) --------------------------------------------------------
char* sub_4DD0B0(int a1) {
	char* result; // eax
	int v2;       // esi

	result = (char*)a1;
	if (a1) {
		v2 = *(uint32_t*)(a1 + 748);
		if (nox_xxx_player_4D7980(*(uint8_t*)(*(uint32_t*)(v2 + 276) + 2064))) {
			result = nox_xxx_playerCallDisconnect_4DEAB0(*(unsigned char*)(*(uint32_t*)(v2 + 276) + 2064), 4);
		} else {
			sub_419EB0(*(uint8_t*)(*(uint32_t*)(v2 + 276) + 2064), 0);
			result = (char*)nox_xxx_sendGauntlet_4DCF80(*(unsigned char*)(*(uint32_t*)(v2 + 276) + 2064), 0);
		}
	}
	return result;
}

//----- (004DD140) --------------------------------------------------------
void* nox_xxx_playerSendMOTD_4DD140(int a1) {
	void* result; // eax
	int v3;       // [esp+0h] [ebp-4h]

	result = sub_4464D0(1, &v3);
	if (result) {
		result = (void*)sub_40BC60(a1, 1, "MOTD", (int)result, v3, 1);
	}
	return result;
}

//----- (004DD180) --------------------------------------------------------
char* nox_xxx_gameServerReadyMB_4DD180(int a1) {
	char* result; // eax
	char* v2;     // edi
	int v3;       // eax
	int i;        // esi
	int v5;       // eax

	result = nox_common_playerInfoFromNum_417090(a1);
	v2 = result;
	if (result) {
		nox_xxx_netNeedTimestampStatus_4174F0((int)result, 16);
		if (nox_common_gameFlags_check_40A5C0(0x2000) && !nox_common_gameFlags_check_40A5C0(128)) {
			v3 = *((uint32_t*)v2 + 514);
			if (v3) {
				nox_xxx_spellBuffOff_4FF5B0(v3, 23);
				nox_xxx_buffApplyTo_4FF380(*((uint32_t*)v2 + 514), 23, 5 * (uint16_t)nox_gameFPS, 5);
			}
			for (i = nox_server_getFirstObject_4DA790(); i; i = nox_server_getNextObject_4DA7A0(i)) {
				if (*(uint32_t*)(i + 8) & 0x10000000) {
					nox_xxx_netMarkMinimapObject_417190(a1, i, 1);
				}
			}
		}
		if ((v2[3680] & 1) == 1) {
			v5 = *((uint32_t*)v2 + 514);
			*((uint32_t*)v2 + 908) = *(uint32_t*)(v5 + 56);
			*((uint32_t*)v2 + 909) = *(uint32_t*)(v5 + 60);
			if (nox_common_gameFlags_check_40A5C0(512)) {
				nox_xxx_playerLeaveObserver_0_4E6AA0((int)v2);
			}
		}
		nox_xxx_wall_4DF1E0(a1);
		if (nox_common_gameFlags_check_40A5C0(4096) && sub_40A300() == 1) {
			nox_xxx_netGauntlet_4D9E70(a1);
		}
		if (a1 == 31 && nox_common_gameFlags_check_40A5C0(128)) {
			if (!nox_server_connectionType_3596 && nox_xxx_check_flag_aaa_43AF70() == 1) {
				sub_49C820();
				return (char*)nox_xxx_netStatsMultiplier_4D9C20(*((uint32_t*)v2 + 514));
			}
			if (nox_server_sanctuaryHelp_54276 == 1) {
				nox_xxx_cliShowHelpGui_49C560();
				return (char*)nox_xxx_netStatsMultiplier_4D9C20(*((uint32_t*)v2 + 514));
			}
			nox_xxx_guiServerOptsLoad_457500();
		}
		result = (char*)nox_xxx_netStatsMultiplier_4D9C20(*((uint32_t*)v2 + 514));
	}
	return result;
}

//----- (004DD310) --------------------------------------------------------
void nox_xxx____setargv_15_4DD310() { *getMemU32Ptr(0x5D4594, 1563280) = 1; }

//----- (004DD320) --------------------------------------------------------
#ifndef NOX_CGO
int nox_xxx_playerNew_4DD320(int ind, unsigned char* data) {
	unsigned char v2 = data[152];
	data[152] &= 0x7F;
	int v3 = v2 >> 7;
	if (ind != 31) {
		if (!nox_common_gameFlags_check_40A5C0(4096) && v3 == 1) {
			return 0;
		}
		if (nox_common_gameFlags_check_40A5C0(4096) && !v3) {
			return 0;
		}
	}
	char* v5 = sub_416640();
	nox_netlist_resetByInd_40ED10(ind, 1);
	nox_xxx_playerResetImportantCtr_4E4F40(ind);
	sub_4E4F30(ind);

	const char* ptyp;
	if (data[67]) {
		ptyp = "PlayerFemale";
	} else if (*getMemU32Ptr(0x5D4594, 1563280)) {
		ptyp = "Player";
	} else {
		ptyp = "NewPlayer";
	}
	nox_object_t* punit = nox_xxx_newObjectByTypeID_4E3810(ptyp);
	if (!punit) {
		return 0;
	}
	if (ind != 31) {
		if (v5[100]) {
			if ((unsigned char)(1 << data[66]) & (unsigned char)v5[100]) {
				return 0;
			}
		}
	}
	nox_playerInfo* pl = nox_common_playerInfoResetInd_417000(ind);
	if ((int)v5[102] >= 0) {
		pl->field_10 = *(uint32_t*)(&data[97]) >> 1;
		pl->field_12 = *(uint32_t*)(&data[101]) >> 1;
	} else {
		unsigned int v9 = *(uint32_t*)(&data[97]);
		if (nox_win_width >= (int)v9) {
			pl->field_10 = v9 >> 1;
			pl->field_12 = *(uint32_t*)(&data[101]) >> 1;
		} else {
			pl->field_10 = nox_win_width / 2;
			pl->field_12 = nox_win_height / 2;
		}
	}
	strcpy(pl->serial, &data[105]);
	pl->field_2135 = data[152];
	nox_swprintf(pl->field_2072, L"%S", &data[142]);
	strcpy(pl->field_2096, &data[128]);
	pl->field_2068 = *(uint32_t*)(&data[138]);
	if (pl->field_2068) {
		void* v12 = sub_425A70(pl->field_2068);
		if (!v12) {
			v12 = sub_425AD0(pl->field_2068, pl->field_2072);
		}
		sub_425B30(v12, ind);
	}
	pl->frame_3596 = nox_frame_xxx_2598000;
	pl->field_3676 = 2;
	pl->field_3680 = 0;
	memcpy(&pl->info, &data[0], 97);
	nox_wcscpy(pl->name_full, pl->info.name);
	pl->info.name_suff[0] = 0;
	nox_xxx_playerCheckName_4DDA00(pl);
	nox_xxx_playerInitColors_461460(pl);
	pl->playerUnit = punit;
	pl->field_2152 = 0;
	pl->netCode = punit->field_9;
	pl->field_2156 = nox_xxx_scavengerTreasureMax_4D1600();
	int v15 = punit->field_187;
	*(uint32_t*)(v15 + 276) = pl;
	pl->field_4584 = nox_xxx_protectionCreateInt_56F400(*(unsigned short*)((int)punit->field_139 + 0));
	pl->field_4592 = nox_xxx_protectionCreateInt_56F400(*(unsigned short*)((int)punit->field_139 + 4));
	pl->field_4596 = nox_xxx_protectionCreateInt_56F400(*(unsigned short*)(v15 + 4));
	pl->field_4600 = nox_xxx_protectionCreateInt_56F400(*(unsigned short*)(v15 + 8));
	pl->field_4604 = nox_xxx_protectionCreateFloat_56F440(*(float*)(&punit->field_7));
	pl->field_4608 = nox_xxx_protectionCreateFloat_56F440(*(float*)(&punit->float_30));
	pl->field_4612 = nox_xxx_protectionCreateInt_56F400(*(uint32_t*)(&punit->field_85));
	pl->field_4616 = nox_xxx_protectionCreateInt_56F400(pl->info.playerClass);
	pl->field_4620 = nox_xxx_protectionCreateInt_56F400(pl->info.field_2235);
	pl->field_4624 = nox_xxx_protectionCreateInt_56F400(pl->info.field_2239);
	int v20 = nox_wcslen(pl->info.name);
	int v21 = nox_xxx_protectionStringCRCLen_56FAE0(pl->info.name, 2 * v20);
	pl->field_4628 = nox_xxx_protectionCreateInt_56F400(v21);
	pl->field_4632 = nox_xxx_protectionCreateInt_56F400(0);
	pl->field_4636 = nox_xxx_protectionCreateInt_56F400(0);
	pl->field_4588 = nox_xxx_protectionCreateInt_56F400(pl->field_2164);
	pl->field_4640 = nox_xxx_protectionCreateInt_56F400(0);
	pl->field_4644 = nox_xxx_protectionCreateInt_56F400(pl->field_3684); // level
	pl->field_4648 = -1;
	pl->field_4700 = 1;
	if (dword_5d4594_2650652) {
		sub_41D670(pl->field_2096);
	}
	nox_xxx_netNotifyRate_4D7F10(ind);
	if (nox_common_gameFlags_check_40A5C0(4096)) {
		nox_xxx_playerGoObserver_4E6860(pl, 0, 1);
	} else if (nox_common_gameFlags_check_40A5C0(512)) {
		nox_xxx_netReportPlayerStatus_417630(pl);
	} else if (pl->playerInd == 31 && nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
		nox_xxx_playerGoObserver_4E6860(pl, 0, 1);
	} else if (nox_common_gameFlags_check_40A5C0(128)) {
		if (sub_40A740()) {
			if (!sub_40AA70(pl)) {
				nox_xxx_playerGoObserver_4E6860(pl, 0, 1);
			}
		} else if (nox_xxx_CheckGameplayFlags_417DA0(4)) {
			sub_4DF3C0(pl);
		}
	} else if (!nox_common_gameFlags_check_40A5C0(2048)) {
		nox_xxx_playerGoObserver_4E6860(pl, 1, 1);
	}
	nox_xxx_servSendSettings_4DDB40(punit);
	if (pl->playerInd == 31) {
		nox_xxx_host_player_unit_3843628 = punit;
	}
	char v30[132];
	nox_xxx_netNewPlayerMakePacket_4DDA90(v30, pl);
	nox_xxx_netSendPacket0_4E5420(ind | 0x80, v30, 129, 0, 0);
	pl->field_3676 = 2;
	if (nox_xxx_check_flag_aaa_43AF70() == 1 && !nox_common_gameFlags_check_40A5C0(128)) {
		sub_425F10(pl);
	}
	nox_xxx_createAt_4DAA50(punit, 0, 2944.0, 2944.0);
	nox_xxx_unitsNewAddToList_4DAC00();
	float2 v28;
	if (nox_common_gameFlags_check_40A5C0(4096)) {
		if (!sub_4E8210(punit, &v28)) {
			nox_xxx_mapFindPlayerStart_4F7AB0(&v28, punit);
		}
	} else {
		nox_xxx_mapFindPlayerStart_4F7AB0(&v28, punit);
	}
	nox_xxx_unitMove_4E7010(punit, &v28);
	sub_422140(pl);
	if (ind != 31) {
		if (sub_459D70() == 2) {
			char* v24 = nox_xxx_cliGamedataGet_416590(1);
			nox_xxx_netGuiGameSettings_4DD9B0(1, v24, pl->playerInd);
		} else {
			char v29[60];
			sub_459AA0(v29);
			nox_xxx_netGuiGameSettings_4DD9B0(1, v29, pl->playerInd);
		}
	}
	if (nox_common_gameFlags_check_40A5C0(49152)) {
		if ((pl->field_3680 & 1) == 0) {
			sub_509C30(pl);
		}
	}
	if (!nox_common_gameFlags_check_40A5C0(2048)) {
		if (nox_common_gameFlags_check_40A5C0(4096)) {
			nox_game_sendQuestStage_4D6960(ind);
			return punit->field_9;
		}
		unsigned char v27b[3];
		v27b[0] = 0xE4; // MSG_FADE_BEGIN
		v27b[1] = 1;
		v27b[2] = 1;
		nox_xxx_netSendPacket0_4E5420(ind, v27b, 3, 0, 0);
	}
	return punit->field_9;
}
#endif // NOX_CGO

//----- (004DD9B0) --------------------------------------------------------
int nox_xxx_netGuiGameSettings_4DD9B0(char a1, const void* a2, int a3) {
	char v4[60]; // [esp+8h] [ebp-3Ch]

	v4[0] = -79;
	v4[1] = a1;
	memcpy(&v4[2], a2, 0x3Au);
	return nox_xxx_netSendPacket1_4E5390(a3, (int)v4, 60, 0, 0);
}

//----- (004DDA00) --------------------------------------------------------
void nox_xxx_playerCheckName_4DDA00(nox_playerInfo* pl) {
	for (int i = 2;; i++) {
		bool ok = true;
		for (nox_playerInfo* pl2 = nox_common_playerInfoGetFirst_416EA0(); pl2; pl2 = nox_common_playerInfoGetNext_416EE0(pl2)) {
			if (pl->playerInd == pl2->playerInd) {
				continue;
			}
			if (nox_wcscmp(pl->name_final, pl2->name_final) == 0) {
				ok = false;
				break;
			}
		}
		if (ok) {
			return;
		}
		nox_swprintf(pl->info.name_suff, L" %d", i);
		nox_swprintf(pl->name_final, L"%s%s", pl->info.name, pl->info.name_suff);
	}
}

//----- (004DDA90) --------------------------------------------------------
void nox_xxx_netNewPlayerMakePacket_4DDA90(unsigned char* buf, nox_playerInfo* pl) {
	buf[0] = 45; // MSG_NEW_PLAYER
	*(uint16_t*)(&buf[1]) = pl->netCode;
	*(uint16_t*)(&buf[100]) = pl->field_2136;
	*(uint16_t*)(&buf[102]) = pl->field_2140;
	*(uint32_t*)(&buf[104]) = pl->field_0;
	*(uint32_t*)(&buf[108]) = pl->field_4;
	buf[116] = pl->field_2152;
	buf[117] = pl->field_2156;
	buf[118] = pl->field_3676 == 3;
	*(uint32_t*)(&buf[112]) = pl->field_3680 & 0x423;
	memcpy(&buf[119], pl->field_2096, strlen(pl->field_2096) + 1);
	memcpy(&buf[3], &pl->info, 91);
}

//----- (004DDB40) --------------------------------------------------------
void nox_xxx_servSendSettings_4DDB40(nox_object_t* punit) {
	uint32_t* a1 = punit;
	int v1;       // ebx
	int v2;       // eax
	char* v3;     // ebp
	char v5[256]; // [esp+10h] [ebp-100h]

	*(uint32_t*)&v5[1] = nox_frame_xxx_2598000;
	v1 = a1[187];
	v5[0] = 40;
	nox_netlist_addToMsgListCli_40EBC0(*(unsigned char*)(*(uint32_t*)(v1 + 276) + 2064), 1, v5, 5);
	v5[0] = 44;
	*(uint16_t*)&v5[1] = nox_xxx_netGetUnitCodeServ_578AC0(a1);
	v2 = *(uint32_t*)(v1 + 276);
	*(uint32_t*)&v5[3] = *(uint32_t*)(v2 + 2068);
	nox_netlist_addToMsgListCli_40EBC0(*(unsigned char*)(v2 + 2064), 1, v5, 7);
	sub_4161E0();
	v3 = nox_xxx_cliGamedataGet_416590(0);
	v5[8] = -81;
	*(uint32_t*)&v5[9] = nox_frame_xxx_2598000;
	*(uint32_t*)&v5[17] = nox_common_gameFlags_getVal_40A5B0() & 0x7FFF0;
	*(uint32_t*)&v5[21] = nox_xxx_getServerSubFlags_409E60();
	*(uint32_t*)&v5[13] = NOX_CLIENT_VERS_CODE;
	v5[25] = nox_xxx_servGetPlrLimit_409FA0();
	v5[26] = nox_xxx_servGamedataGet_40A020(*((uint16_t*)v3 + 26));
	v5[27] = sub_40A180(*((uint16_t*)v3 + 26));
	nox_netlist_addToMsgListCli_40EBC0(*(unsigned char*)(*(uint32_t*)(v1 + 276) + 2064), 1, &v5[8], 20);
	v5[28] = -80;
	strcpy(&v5[29], nox_xxx_serverOptionsGetServername_40A4C0());
	memcpy(&v5[45], v3 + 24, 0x1Cu);
	if (sub_40A220() && (sub_40A300() || sub_40A180(*((uint16_t*)v3 + 26)))) {
		*(uint32_t*)&v5[73] = sub_40A230();
	} else {
		*(uint32_t*)&v5[73] = 0;
	}
	nox_netlist_addToMsgListCli_40EBC0(*(unsigned char*)(*(uint32_t*)(v1 + 276) + 2064), 1, &v5[28], 49);
	nox_xxx_netNewPlayerMakePacket_4DDA90((int)&v5[124], *(uint32_t*)(v1 + 276));
	nox_netlist_addToMsgListCli_40EBC0(*(unsigned char*)(*(uint32_t*)(v1 + 276) + 2064), 1, &v5[124], 129);
	nox_xxx_netSendBySock_4DDDC0(*(unsigned char*)(*(uint32_t*)(v1 + 276) + 2064));
	v5[80] = 43;
	strcpy(&v5[81], nox_server_currentMapGetFilename_409B30());
	*(uint32_t*)&v5[113] = nox_xxx_mapCrcGetMB_409B00();
	*(uint32_t*)&v5[117] = nox_frame_xxx_2598000;
	nox_xxx_netSendSock_552640(*(unsigned char*)(*(uint32_t*)(v1 + 276) + 2064) + 1, &v5[80], 41,
							   NOX_NET_SEND_NO_LOCK | NOX_NET_SEND_FLAG2);
	sub_4DDE10(*(unsigned char*)(*(uint32_t*)(v1 + 276) + 2064), *(uint32_t*)(v1 + 276));
}

//----- (004DDDC0) --------------------------------------------------------
void nox_xxx_netSendBySock_4DDDC0(int a1) {
	int v2;            // esi
	unsigned char* v3; // eax

	v2 = a1;
	if (!nox_common_gameFlags_check_40A5C0(2) || a1 != 31) {
		v3 = nox_netlist_copyPacketList_40ED60(a1, 1u, &a1);
		if (v3) {
			nox_xxx_netSendSock_552640(v2 + 1, v3, a1, NOX_NET_SEND_NO_LOCK | NOX_NET_SEND_FLAG2);
		}
		nox_netlist_resetByInd_40ED10(v2, 1);
	}
}

//----- (004DDE10) --------------------------------------------------------
uint32_t* sub_4DDE10(int a1, int a2) {
	uint32_t* result; // eax
	int i;            // esi
	int v4;           // eax

	result = *(uint32_t**)(a2 + 2056);
	if (result) {
		if (!dword_5d4594_1563276) {
			dword_5d4594_1563276 = nox_xxx_getNameId_4E3AA0("Flag");
		}
		result = *(uint32_t**)(a2 + 2056);
		for (i = result[126]; i; i = *(uint32_t*)(i + 496)) {
			v4 = *(uint32_t*)(i + 16);
			if (!(v4 & 0x100)) {
				result = *(uint32_t**)&dword_5d4594_1563276;
				if (*(unsigned short*)(i + 4) != dword_5d4594_1563276) {
					continue;
				}
			}
			result = sub_4D82F0(a1, (uint32_t*)i);
		}
	}
	return result;
}

//----- (004DDE80) --------------------------------------------------------
int nox_xxx_playerObserveMonster_4DDE80(int player, int unit) {
	int v2;     // edi
	int result; // eax

	v2 = *(uint32_t*)(player + 748);
	if (*(uint8_t*)(*(uint32_t*)(v2 + 276) + 3680) & 1) {
		nox_xxx_playerLeaveObserver_0_4E6AA0(*(uint32_t*)(v2 + 276));
	}
	if (*(uint8_t*)(*(uint32_t*)(v2 + 276) + 3680) & 2) {
		nox_xxx_playerObserveClear_4DDEF0(player);
	}
	nox_xxx_netNeedTimestampStatus_4174F0(*(uint32_t*)(v2 + 276), 2);
	nox_xxx_playerCameraUnlock_4E6040(player);
	result = nox_xxx_playerCameraFollow_4E6060(player, unit);
	*(uint32_t*)(player + 744) = nox_xxx_updatePlayerObserver_4E62F0;
	return result;
}

//----- (004DDEF0) --------------------------------------------------------
int nox_xxx_playerObserveClear_4DDEF0(int player) {
	int result; // eax

	result = *(uint32_t*)(*(uint32_t*)(player + 748) + 276);
	if (*(uint8_t*)(result + 3680) & 2) {
		nox_xxx_playerUnsetStatus_417530(result, 2);
		result = nox_xxx_playerCameraUnlock_4E6040(player);
		*(uint32_t*)(player + 744) = nox_xxx_updatePlayer_4F8100;
	}
	return result;
}

//----- (004DDF30) --------------------------------------------------------
int nox_xxx_playerGetPossess_4DDF30(int a1) {
	int v1;     // eax
	int result; // eax

	v1 = *(uint32_t*)(*(uint32_t*)(a1 + 748) + 276);
	if (*(uint8_t*)(v1 + 3680) & 2) {
		result = *(uint32_t*)(v1 + 3628);
	} else {
		result = 0;
	}
	return result;
}

//----- (004DDF60) --------------------------------------------------------
int nox_xxx_netPlayerIncomingServ_4DDF60(int a1) {
	int v1;             // ebx
	char* v2;           // esi
	int v3;             // eax
	int v4;             // edi
	int v5;             // ebp
	char* i;            // edi
	int v7;             // eax
	char* v8;           // eax
	char* j;            // edi
	unsigned char* v10; // eax
	int k;              // esi
	int v13;            // [esp+Ch] [ebp+4h]

	v1 = a1;
	v2 = nox_common_playerInfoFromNum_417090(a1);
	if (!v2) {
		abort();
	}
	if (nox_common_gameFlags_check_40A5C0(4096)) {
		if (a1 != 31) {
			if (v2) {
				v3 = *((uint32_t*)v2 + 514);
				if (v3) {
					*(uint32_t*)(*(uint32_t*)(v3 + 748) + 552) = 1;
				}
			}
		}
		sub_4D9CF0(a1);
		if (v2 && *((uint32_t*)v2 + 514)) {
			sub_4D6000(*((uint32_t*)v2 + 514));
		}
	}
	sub_57B920(v2 + 16);
	v13 = *((uint32_t*)v2 + 514);
	dword_5d4594_2649712 |= 1 << v1;
	v4 = *(uint32_t*)(v13 + 56);
	v5 = *(uint32_t*)(v13 + 60);
	nox_xxx_newPlayerSendAllPlayers_4DE300(v1);
	*((uint32_t*)v2 + 1175) = 0;
	(*(void (**)(int, uint32_t))(v13 + 688))(v13, 0);
	v2[3676] = 3;
	if (!nox_common_gameFlags_check_40A5C0(512)) {
		*((uint32_t*)v2 + 908) = v4;
		*((uint32_t*)v2 + 909) = v5;
	}
	if (nox_server_sendMotd_108752 && nox_common_gameFlags_check_40A5C0(0x2000) &&
		!nox_common_gameFlags_check_40A5C0(4096)) {
		nox_xxx_playerSendMOTD_4DD140(v1);
	}
	for (i = nox_common_playerInfoGetFirst_416EA0(); i; i = nox_common_playerInfoGetNext_416EE0((int)i)) {
		v7 = *((uint32_t*)i + 514);
		if (v7) {
			if (i != v2) {
				nox_xxx_netMarkMinimapObject_417190(v1, v7, 1);
				nox_xxx_netMarkMinimapObject_417190((unsigned char)i[2064], *((uint32_t*)v2 + 514), 1);
				nox_xxx_netSendSimpleObject2_4DF360((unsigned char)i[2064], *((uint32_t*)v2 + 514));
				if (nox_common_gameFlags_check_40A5C0(4096)) {
					nox_xxx_netSendTeam_4D8670((unsigned char)i[2064], *((uint32_t**)v2 + 514));
					nox_xxx_netSendTeam_4D8670(v1, *((uint32_t**)i + 514));
				}
			}
		}
	}
	nox_xxx_servMinimapRevealFlag_4DE380(v1);
	sub_4DF2E0(v1);
	if (nox_common_gameFlags_check_40A5C0(1024) && !sub_40AA70((int)v2)) {
		nox_xxx_netNeedTimestampStatus_4174F0((int)v2, 256);
	}
	if (nox_xxx_check_flag_aaa_43AF70() == 1) {
		sub_4161E0();
		sub_416690();
	}
	sub_4E8110(v1);
	if (nox_common_gameFlags_check_40A5C0(64)) {
		v8 = sub_4E8310();
		nox_xxx_netSendBallStatus_4D95F0(v1, *v8, *((uint16_t*)v8 + 1));
	} else if (nox_common_gameFlags_check_40A5C0(32)) {
		for (j = nox_xxx_TeamGet_418B10(); j; j = nox_xxx_TeamNext_418B60((int)j)) {
			v10 = sub_4E8320(j[57]);
			nox_xxx_netSendFlagStatus_4D95A0(v1, *v10, v10[2], v10[1], *((uint16_t*)v10 + 2));
		}
	}
	nox_xxx_sendAllClientStatus_4175C0((int)v2);
	if (sub_409F40(0x2000)) {
		nox_xxx_sendAllPlayerIDs_4DE270((int)v2);
	}
	if (nox_common_gameFlags_check_40A5C0(4096)) {
		for (k = nox_xxx_getFirstPlayerUnit_4DA7C0(); k; k = nox_xxx_getNextPlayerUnit_4DA7F0(k)) {
			if (*(uint32_t*)(*(uint32_t*)(*(uint32_t*)(k + 748) + 276) + 4792) == 1) {
				sub_4D9D20(v1, k);
			}
		}
	}
	if (nox_common_gameFlags_check_40A5C0(4096)) {
		sub_4D7A60(v1);
	}
	return *(uint32_t*)(v13 + 36);
}

//----- (004DE270) --------------------------------------------------------
int nox_xxx_sendAllPlayerIDs_4DE270(int a1) {
	int result; // eax
	int i;      // esi
	int v3;     // [esp-1Ch] [ebp-28h]
	char v4[7]; // [esp+4h] [ebp-8h]

	result = nox_xxx_getFirstPlayerUnit_4DA7C0();
	for (i = result; result; i = result) {
		if (*(uint32_t*)(i + 36) != *(uint32_t*)(a1 + 2060)) {
			if (*(uint32_t*)(*(uint32_t*)(i + 748) + 260)) {
				v4[0] = -46;
				*(uint16_t*)&v4[1] = nox_xxx_netGetUnitCodeServ_578AC0((uint32_t*)i);
				v3 = *(unsigned char*)(a1 + 2064);
				*(uint16_t*)&v4[3] = *(uint16_t*)(i + 4);
				v4[5] = 1;
				v4[6] = 2;
				nox_xxx_netSendPacket0_4E5420(v3, v4, 7, 0, 1);
			}
		}
		result = nox_xxx_getNextPlayerUnit_4DA7F0(i);
	}
	return result;
}

//----- (004DE300) --------------------------------------------------------
char* nox_xxx_newPlayerSendAllPlayers_4DE300(int a1) {
	char* result; // eax
	int i;        // esi
	char v3[132]; // [esp+4h] [ebp-84h]

	result = nox_common_playerInfoGetFirst_416EA0();
	for (i = (int)result; result; i = (int)result) {
		if (*(unsigned char*)(i + 2064) != a1 &&
			(*(uint8_t*)(i + 2064) != 31 || !nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING))) {
			nox_xxx_netNewPlayerMakePacket_4DDA90((int)v3, i);
			nox_xxx_netSendPacket1_4E5390(a1, (int)v3, 129, 0, 0);
			sub_4DDE10(a1, i);
		}
		result = nox_common_playerInfoGetNext_416EE0(i);
	}
	return result;
}

//----- (004DE380) --------------------------------------------------------
int nox_xxx_servMinimapRevealFlag_4DE380(int a1) {
	int result; // eax
	int i;      // esi
	int v3;     // eax

	if (!*getMemU32Ptr(0x5D4594, 1563284)) {
		*getMemU32Ptr(0x5D4594, 1563284) = nox_xxx_getNameId_4E3AA0("GameBall");
	}
	if (!*getMemU32Ptr(0x5D4594, 1563272)) {
		*getMemU32Ptr(0x5D4594, 1563272) = nox_xxx_getNameId_4E3AA0("Crown");
	}
	result = nox_server_getFirstObject_4DA790();
	for (i = result; result; i = result) {
		if (*(uint8_t*)(i + 16) & 4) {
			v3 = *(unsigned short*)(i + 4);
			if ((unsigned short)v3 == *getMemU32Ptr(0x5D4594, 1563284) || v3 == *getMemU32Ptr(0x5D4594, 1563272)) {
				nox_xxx_netMarkMinimapObject_417190(a1, i, 1);
			}
		}
		result = nox_server_getNextObject_4DA7A0(i);
	}
	return result;
}

//----- (004DE410) --------------------------------------------------------
uint32_t* sub_4DE410(int a1) {
	int v1;           // ebp
	int v2;           // edi
	uint32_t* result; // eax
	uint32_t* i;      // esi
	int v5;           // ecx
	int v6;           // ebx
	unsigned int v7;  // edi
	int v8;           // [esp+10h] [ebp+4h]

	v1 = a1;
	v2 = 1 << a1;
	v8 = 1 << a1;
	result = (uint32_t*)nox_server_getFirstObject_4DA790();
	for (i = result; result; i = result) {
		v5 = i[2];
		i[38] |= v2;
		if (!(v5 & 0x20400000)) {
			i[37] &= ~v2;
		}
		i[v1 + 140] &= 0xFFFu;
		if (i[2] & 0x20400000) {
			v6 = 0x10000;
			v7 = 1;
			do {
				if (sub_4E4C90((int)i, v7)) {
					i[v1 + 140] |= v6;
				}
				v7 *= 2;
				v6 *= 2;
			} while (v7 < 0x10000);
			v2 = v8;
		}
		result = (uint32_t*)nox_server_getNextObject_4DA7A0((int)i);
	}
	return result;
}

//----- (004DE4D0) --------------------------------------------------------
int sub_4DE4D0(char a1) {
	int v1;     // esi
	int result; // eax
	char v3;    // cl

	v1 = 1 << a1;
	for (result = nox_server_getFirstObject_4DA790(); result; result = nox_server_getNextObject_4DA7A0(result)) {
		v3 = *(uint8_t*)(result + 16);
		*(uint32_t*)(result + 152) |= v1;
		if (!(v3 & 0x20) && !(*(uint32_t*)(result + 8) & 0x20400006)) {
			*(uint32_t*)(result + 148) &= ~v1;
		}
	}
	return result;
}

//----- (004DE530) --------------------------------------------------------
char nox_xxx_playerDisconnFinish_4DE530(int a1, char a2) {
	int v2;      // ebp
	char* v3;    // eax
	int v4;      // esi
	char* v5;    // edi
	char* i;     // edi
	int v7;      // eax
	int j;       // eax
	char result; // al
	int v11;     // eax
	int v13;     // [esp+14h] [ebp-4h]

	v2 = a1;
	v13 = 1 << a1;
	sub_4D79A0(a1);
	sub_419EB0(v2, 0);
	sub_4E80C0(v2);
	v3 = nox_common_playerInfoFromNum_417090(v2);
	v4 = (int)v3;
	if (v3) {
		if (*((uint32_t*)v3 + 514)) {
			sub_506740(*((uint32_t*)v3 + 514));
		}
		if (*(uint32_t*)(v4 + 4792) && *(uint32_t*)(v4 + 2056) && nox_common_gameFlags_check_40A5C0(4096)) {
			nox_xxx_aud_501960(1011, *(uint32_t*)(v4 + 2056), 0, 0);
			*(uint32_t*)(v4 + 4792) = 0;
			if (!nox_xxx_player_4E3CE0()) {
				v5 = nox_xxx_getQuestMapFile_4D0F60();
				nox_game_setQuestStage_4E3CD0(0);
				nox_xxx_mapLoad_4D2450(v5);
			}
			sub_4D7390(*(uint32_t*)(v4 + 2056));
			sub_4DE790(*(uint32_t*)(v4 + 2056));
		}
	}
	if (nox_xxx_check_flag_aaa_43AF70() == 1 && !nox_common_gameFlags_check_40A5C0(128)) {
		sub_425E90(v4, a2);
	}
	for (i = nox_common_playerInfoGetFirst_416EA0(); i; i = nox_common_playerInfoGetNext_416EE0((int)i)) {
		v7 = *((uint32_t*)i + 514);
		if (v7 && i != (char*)v4) {
			nox_xxx_netUnmarkMinimapObj_417300(v2, v7, 3);
			nox_xxx_netUnmarkMinimapObj_417300((unsigned char)i[2064], *(uint32_t*)(v4 + 2056), 3);
		}
	}
	if (*(uint32_t*)(v4 + 2056)) {
		for (j = nox_server_getFirstObject_4DA790(); j; j = nox_server_getNextObject_4DA7A0(j)) {
			if ((*(uint8_t*)(j + 8) & 0x80) && *(uint32_t*)(j + 508) == *(uint32_t*)(v4 + 2056)) {
				*(uint32_t*)(j + 508) = 0;
			}
		}
	}
	sub_40C0E0(v2 + 1);
	sub_4DE410(v2);
	if (v4) {
		char v12[3] = {0};
		v12[0] = -82;
		// TODO: this can be nil for some reason; should we sent this at all?
		if (*(uint32_t*)(v4 + 2056)) {
			*(uint16_t*)&v12[1] = *(uint16_t*)(*(uint32_t*)(v4 + 2056) + 36);
		}
		nox_xxx_netSendPacket0_4E5420(v2 | 0x80, v12, 3, 0, 0);
	}
	if (a2 == 4) {
		LOBYTE(a1) = -59;
		nox_xxx_netSendSock_552640(v2 + 1, &a1, 1, NOX_NET_SEND_NO_LOCK | NOX_NET_SEND_FLAG2);
	}
	result = sub_4E55F0(v2);
	if (v4) {
		nox_xxx_playerRemoveSpawnedStuff_4E5AD0(*(uint32_t*)(v4 + 2056));
		if (nox_common_gameFlags_check_40A5C0(4096)) {
			sub_4DE790(*(uint32_t*)(v4 + 2056));
		} else {
			nox_xxx_dropAllItems_4EDA40(*(uint32_t**)(v4 + 2056));
		}
		v11 = v13;
		*(uint32_t*)(v4 + 2140) = 0;
		*(uint32_t*)(v4 + 2136) = 0;
		dword_5d4594_2649712 &= ~v11;
		*(uint8_t*)(v4 + 3676) = 2;
		result = nox_xxx_playerUnsetStatus_417530(v4, 16);
	}
	return result;
}

//----- (004DE790) --------------------------------------------------------
void sub_4DE790(int a1) {
	int v1; // esi
	int v2; // edi

	v1 = nox_xxx_inventoryGetFirst_4E7980(a1);
	if (v1) {
		do {
			v2 = nox_xxx_inventoryGetNext_4E7990(v1);
			nox_xxx_delayedDeleteObject_4E5CC0(v1);
			v1 = v2;
		} while (v2);
	}
}

//----- (004DE7C0) --------------------------------------------------------
#ifdef NOX_CGO
void nox_script_callByEvent_cgo(int eventCode, void* a1, void* a2);
#endif // NOX_CGO
void nox_xxx_playerForceDisconnect_4DE7C0(int ind) {
	nox_playerInfo* plr = nox_common_playerInfoFromNum_417090(ind);
#ifdef NOX_CGO
	nox_script_callByEvent_cgo(31, plr, 0); // player leave
#endif                                      // NOX_CGO
	if (sub_4D12A0(ind)) {
		sub_4D1250(ind);
	}
	if (plr->field_2068) {
		int* v3 = sub_425A70(plr->field_2068);
		if (v3) {
			sub_425B60(v3, ind);
		}
	}
	int v4 = *(uint32_t*)((uint32_t)(plr->playerUnit) + 748);
	if (*(uint32_t*)(v4 + 280)) {
		nox_xxx_shopCancelSession_510DC0(*(uint32_t**)(v4 + 280));
	}
	*(uint32_t*)(v4 + 280) = 0;
	sub_510E20(plr->playerInd);
	sub_4FF990(1 << plr->playerInd);

#ifndef NOX_SERVER
	if (!nox_common_gameFlags_check_40A5C0(2))
#endif // NOX_SERVER
	{
		plr->active = 0;
	}

	char* pl = plr;
	sub_56F4F0((int*)pl + 1146);
	sub_56F4F0((int*)pl + 1148);
	sub_56F4F0((int*)pl + 1149);
	sub_56F4F0((int*)pl + 1150);
	sub_56F4F0((int*)pl + 1151);
	sub_56F4F0((int*)pl + 1152);
	sub_56F4F0((int*)pl + 1153);
	sub_56F4F0((int*)pl + 1154);
	sub_56F4F0((int*)pl + 1155);
	sub_56F4F0((int*)pl + 1156);
	sub_56F4F0((int*)pl + 1157);
	sub_56F4F0((int*)pl + 1158);
	sub_56F4F0((int*)pl + 1159);
	sub_56F4F0((int*)pl + 1147);
	sub_56F4F0((int*)pl + 1160);
	sub_56F4F0((int*)pl + 1161);

	char buf[3];
	buf[0] = 46;
	*(uint16_t*)(&buf[1]) = nox_xxx_netGetUnitCodeServ_578AC0(plr->playerUnit);
	nox_xxx_netSendPacket0_4E5420(ind | 0x80, buf, 3, 0, 0);
	nox_xxx_delayedDeleteObject_4E5CC0(plr->playerUnit);
	plr->playerUnit = 0;
	for (int i = nox_xxx_getFirstPlayerUnit_4DA7C0(); i; i = nox_xxx_getNextPlayerUnit_4DA7F0(i)) {
		int v7 = *(uint32_t*)(i + 748);
		*(uint8_t*)(ind + v7 + 452) = 0;
		*(uint32_t*)(v7 + 4 * ind + 324) = 0;
		*(uint8_t*)(ind + v7 + 484) = 0;
		*(uint8_t*)(ind + v7 + 516) = 0;
	}
	if (nox_xxx_gamePlayIsAnyPlayers_40A8A0()) {
		if (nox_common_gameFlags_check_40A5C0(1024) && !nox_xxx_serverIsClosing_446180() && sub_40A770() == 1) {
			sub_5095E0();
		}
	} else {
		sub_40A1F0(0);
		nox_xxx_playerForceSendLessons_416E50(1);
		sub_417D00();
		sub_40A970();
	}
	sub_4E55F0(ind);
	nox_xxx_playerResetImportantCtr_4E4F40(ind);
	sub_4E4F30(ind);
	if (nox_xxx_check_flag_aaa_43AF70() == 1) {
		sub_4161E0();
		sub_416690();
	}
	if (!nox_common_gameFlags_check_40A5C0(4096)) {
		return;
	}
	if (sub_4E9010() == 1) {
		nox_xxx_mapLoad_4D2450(sub_4E8E50());
	} else if (nox_server_questMaybeWarp_4E8F60()) {
		sub_4D60B0();
		sub_4D76E0(1);
		int v12 = nox_game_getQuestStage_4E3CC0();
		int v13 = nox_server_questNextStageThreshold_4D74F0(v12);
		nox_game_setQuestStage_4E3CD0(v13 - 1);
		nox_xxx_mapLoad_4D2450(sub_4E8E50());
	} else {
		char* result = nox_xxx_getFirstPlayerUnit_4DA7C0();
		if (result) {
			while (!*(uint32_t*)(*((uint32_t*)result + 187) + 312)) {
				result = (char*)nox_xxx_getNextPlayerUnit_4DA7F0((int)result);
				if (!result) {
					return;
				}
			}
			result = (char*)sub_4E8E60();
		}
	}
}

//----- (004DEAB0) --------------------------------------------------------
#ifndef NOX_CGO
char* nox_xxx_playerCallDisconnect_4DEAB0(int a1, char a2) {
	char* result; // eax
	char* v3;     // esi

	result = nox_common_playerInfoFromNum_417090(a1);
	v3 = result;
	if (result) {
		nox_xxx_playerDisconnFinish_4DE530((unsigned char)result[2064], a2);
		nox_xxx_playerForceDisconnect_4DE7C0((unsigned char)v3[2064]);
		result = (char*)nox_xxx_netStructReadPackets2_4DEC50((unsigned char)v3[2064]);
	}
	return result;
}

//----- (004DEB00) --------------------------------------------------------
void nox_xxx_playerDisconnByPlrID_4DEB00(int a1) {
	char* result = nox_common_playerInfoFromNum_417090(a1);
	if (result) {
		nox_xxx_playerCallDisconnect_4DEAB0((unsigned char)result[2064], 4);
	}
}

//----- (004DEBC0) --------------------------------------------------------
int nox_xxx_netAddPlayerHandler_4DEBC0(int port) {
	int result; // eax

	nox_net_struct_arg_t narg;
	memset(&narg, 0, sizeof(nox_net_struct_arg_t));
	narg.port = port;
	narg.data_3_size = 0;
	narg.field_4 = nox_xxx_servGetPlrLimit_409FA0();
	narg.data_size = 2048;
	nox_xxx_allocNetGQueue_5520B0(200, 1024);
	narg.func_yyy = nox_xxx_netlist_ServRecv_4DEC30;
	narg.func_xxx = nox_xxx_netFn_UpdateStream_4DF630;
	result = nox_xxx_netInit_554380(&narg);
	OnLibraryNotice_256();
	*getMemU32Ptr(0x5D4594, 1563148) = result;
	return result;
}

//----- (004DEC30) --------------------------------------------------------
int nox_xxx_netlist_ServRecv_4DEC30(int a1, unsigned char* a2, signed int a3, void* a4) {
	nox_xxx_netOnPacketRecvServ_51BAD0_net_sdecode(a1 - 1, a2, a3);
	return 1;
}

//----- (004DEC50) --------------------------------------------------------
int nox_xxx_netStructReadPackets2_4DEC50(int a1) { return nox_xxx_netStructReadPackets_5545B0(a1 + 1); }

//----- (004DEC60) --------------------------------------------------------
void nox_server_netCloseHandler_4DEC60(unsigned int a1) {
	nox_xxx_netStructReadPackets_5545B0(a1);
	nox_server_netClose_5546A0(a1);
	OnLibraryNotice_257();
	sub_552450();
}
#endif // NOX_CGO

//----- (004DEF00) --------------------------------------------------------
int nox_xxx_netGameSettings_4DEF00() {
	char* v0;    // ebx
	char v2[20]; // [esp+Ch] [ebp-48h]
	char v3[49]; // [esp+20h] [ebp-34h]

	v0 = nox_xxx_cliGamedataGet_416590(0);
	v2[0] = -81;
	*(uint32_t*)&v2[1] = nox_frame_xxx_2598000;
	*(uint32_t*)&v2[9] = nox_common_gameFlags_getVal_40A5B0() & 0x7FFF0;
	*(uint32_t*)&v2[13] = nox_xxx_getServerSubFlags_409E60();
	*(uint32_t*)&v2[5] = NOX_CLIENT_VERS_CODE;
	v2[17] = nox_xxx_servGetPlrLimit_409FA0();
	v2[18] = nox_xxx_servGamedataGet_40A020(*((uint16_t*)v0 + 26));
	v2[19] = sub_40A180(*((uint16_t*)v0 + 26));
	v3[0] = -80;
	strcpy(&v3[1], nox_xxx_serverOptionsGetServername_40A4C0());
	memcpy(&v3[17], v0 + 24, 0x1Cu);
	if (sub_40A220() && (sub_40A300() || sub_40A180(*((uint16_t*)v0 + 26)))) {
		*(uint32_t*)&v3[45] = sub_40A230();
	} else {
		*(uint32_t*)&v3[45] = 0;
	}
	nox_xxx_netSendPacket1_4E5390(159, (int)v2, 20, 0, 0);
	return nox_xxx_netSendPacket1_4E5390(159, (int)v3, 49, 0, 0);
}

//----- (004DF020) --------------------------------------------------------
char* sub_4DF020() {
	char* result;      // eax
	int v1;            // ecx
	unsigned char* v2; // edi
	char* v3;          // esi
	bool v4;           // zf
	char* i;           // esi
	char v6[60];       // [esp+8h] [ebp-3Ch]

	result = sub_459AA0((int)v6);
	v1 = 29;
	v2 = getMemAt(0x5D4594, 1563214);
	v3 = v6;
	v4 = 1;
	do {
		if (!v1) {
			break;
		}
		v4 = *(uint16_t*)v3 == *(uint16_t*)v2;
		v3 += 2;
		v2 += 2;
		--v1;
	} while (v4);
	if (!v4) {
		result = nox_common_playerInfoGetFirst_416EA0();
		for (i = result; result; i = result) {
			if (i[2064] != 31) {
				nox_xxx_netGuiGameSettings_4DD9B0(1, v6, (unsigned char)i[2064]);
			}
			result = nox_common_playerInfoGetNext_416EE0((int)i);
		}
		memcpy(getMemAt(0x5D4594, 1563214), v6, 0x38u);
		*getMemU16Ptr(0x5D4594, 1563270) = *(uint16_t*)&v6[56];
	}
	return result;
}

//----- (004DF0A0) --------------------------------------------------------
int nox_xxx_wallSendDestroyed_4DF0A0(int a1, int a2) {
	int result; // eax
	int i;      // esi
	char v4[3]; // [esp+4h] [ebp-4h]

	v4[0] = 58;
	*(uint16_t*)&v4[1] = *(uint16_t*)(a1 + 10);
	if (a2 != 32) {
		return nox_xxx_netSendPacket0_4E5420(a2, v4, 3, 0, 1);
	}
	result = nox_xxx_getFirstPlayerUnit_4DA7C0();
	for (i = result; result; i = result) {
		nox_xxx_netSendPacket0_4E5420(*(unsigned char*)(*(uint32_t*)(*(uint32_t*)(i + 748) + 276) + 2064), v4, 3, 0, 1);
		result = nox_xxx_getNextPlayerUnit_4DA7F0(i);
	}
	return result;
}

//----- (004DF120) --------------------------------------------------------
int sub_4DF120(int a1) {
	int result; // eax
	int i;      // esi
	char v3[3]; // [esp+4h] [ebp-4h]

	v3[0] = 59;
	*(uint16_t*)&v3[1] = *(uint16_t*)(a1 + 10);
	result = nox_xxx_getFirstPlayerUnit_4DA7C0();
	for (i = result; result; i = result) {
		nox_xxx_netSendPacket0_4E5420(*(unsigned char*)(*(uint32_t*)(*(uint32_t*)(i + 748) + 276) + 2064), v3, 3, 0, 1);
		result = nox_xxx_getNextPlayerUnit_4DA7F0(i);
	}
	return result;
}

//----- (004DF180) --------------------------------------------------------
int sub_4DF180(int a1) {
	int result; // eax
	int i;      // esi
	char v3[3]; // [esp+4h] [ebp-4h]

	v3[0] = 60;
	*(uint16_t*)&v3[1] = *(uint16_t*)(a1 + 10);
	result = nox_xxx_getFirstPlayerUnit_4DA7C0();
	for (i = result; result; i = result) {
		nox_xxx_netSendPacket0_4E5420(*(unsigned char*)(*(uint32_t*)(*(uint32_t*)(i + 748) + 276) + 2064), v3, 3, 0, 1);
		result = nox_xxx_getNextPlayerUnit_4DA7F0(i);
	}
	return result;
}

//----- (004DF1E0) --------------------------------------------------------
int nox_xxx_wall_4DF1E0(int a1) {
	int* i;     // esi
	int v2;     // eax
	int result; // eax
	int j;      // esi
	char v5;    // al

	for (i = (int*)nox_xxx_wallGetFirstBreakableCli_410870(); i; i = (int*)nox_xxx_wallGetNextBreakableCli_410880(i)) {
		v2 = i[1];
		if (*(uint8_t*)(v2 + 4) & 0x20) {
			nox_xxx_wallSendDestroyed_4DF0A0(v2, a1);
		}
	}
	sub_4DF2A0(a1);
	if (sub_5071C0()) {
		sub_507190(a1, 1);
	}
	result = nox_common_gameFlags_check_40A5C0(4096);
	if (result) {
		for (j = nox_server_getFirstObject_4DA790(); j; j = nox_server_getNextObject_4DA7A0(j)) {
			if ((*(uint8_t*)(j + 8) & 0x80) && *(uint8_t*)(*(uint32_t*)(j + 748) + 48)) {
				sub_4D6A20(a1, j);
			}
		}
		result = sub_4D72C0();
		if (result == 1) {
			v5 = sub_4D72C0();
			result = sub_4D7280(a1, v5);
		}
	}
	return result;
}

//----- (004DF2A0) --------------------------------------------------------
int* sub_4DF2A0(char a1) {
	int v1;      // esi
	int* result; // eax

	v1 = 1 << a1;
	for (result = (int*)nox_xxx_wallSecretGetFirstWall_410780(); result;
		 result = (int*)nox_xxx_wallSecretNext_410790(result)) {
		if (result[5] & 8) {
			result[7] |= v1;
		} else {
			result[7] &= ~v1;
		}
	}
	return result;
}

//----- (004DF2E0) --------------------------------------------------------
void sub_4DF2E0(int a1) {
	char* i; // ebx
	int j;   // esi

	if (a1 != 31) {
		for (i = nox_xxx_TeamGet_418B10(); i; i = nox_xxx_TeamNext_418B60((int)i)) {
			sub_4197C0((wchar_t*)i, a1);
			for (j = nox_xxx_getFirstPlayerUnit_4DA7C0(); j; j = nox_xxx_getNextPlayerUnit_4DA7F0(j)) {
				if (nox_xxx_teamCompare2_419180(j + 48, i[57])) {
					sub_4198A0(j + 48, a1, *(uint32_t*)(j + 36));
				}
			}
		}
	}
}

//----- (004DF360) --------------------------------------------------------
int nox_xxx_netSendSimpleObject2_4DF360(int a1, int a2) {
	short v2;   // ax
	float v3;   // ecx
	short v4;   // ax
	float v5;   // edx
	char v7[9]; // [esp+4h] [ebp-Ch]

	v7[0] = 47;
	*(uint16_t*)&v7[3] = *(uint16_t*)(a2 + 4);
	v2 = nox_xxx_netGetUnitCodeServ_578AC0((uint32_t*)a2);
	v3 = *(float*)(a2 + 56);
	*(uint16_t*)&v7[1] = v2;
	v4 = nox_float2int(v3);
	v5 = *(float*)(a2 + 60);
	*(uint16_t*)&v7[5] = v4;
	*(uint16_t*)&v7[7] = nox_float2int(v5);
	return nox_xxx_netSendPacket1_4E5390(a1, (int)v7, 9, 0, 1);
}

//----- (004DF3C0) --------------------------------------------------------
void sub_4DF3C0(nox_playerInfo* pl) {
	int a1 = pl;
	int v1;   // edi
	char* v2; // eax
	char* v3; // ebx
	char* v4; // ebx
	char* v5; // esi
	int v6;   // ebx
	int v7;   // eax
	int v8;   // esi
	int v9;   // ebx

	v1 = *(uint32_t*)(a1 + 2056);
	v2 = sub_416640();
	v3 = v2;
	if (!v1) {
		return;
	}
	if (!sub_40A740() && !nox_common_gameFlags_check_40A5C0(0x8000)) {
		uint8_t v2b = nox_xxx_getTeamCounter_417DD0();
		if (v2b) {
			v2 = sub_4189D0();
			v4 = v2;
			if (v2) {
				v2 = (char*)nox_xxx_servObjectHasTeam_419130(v1 + 48);
				if (!v2) {
					nox_xxx_createAtImpl_4191D0(v4[57], v1 + 48, 1, *(uint32_t*)(v1 + 36), 1);
				}
			}
		}
		return;
	}
	v2 = *(char**)(a1 + 2068);
	if (!v2) {
		return;
	}
	v5 = sub_418AE0(*(uint32_t*)(a1 + 2068));
	if (v5) {
		v6 = v1 + 48;
		v7 = nox_xxx_servObjectHasTeam_419130(v1 + 48);
	} else {
		v8 = (unsigned char)v3[52];
		if ((nox_common_gameFlags_check_40A5C0(96) ||
			 nox_common_gameFlags_check_40A5C0(16) && nox_xxx_CheckGameplayFlags_417DA0(4)) &&
			v8 > 2) {
			v8 = 2;
		}
		v2 = (char*)(unsigned char)sub_417DE0();
		if ((int)v2 >= v8) {
			return;
		}
		if (!nox_common_gameFlags_check_40A5C0(96) ||
			(v9 = (unsigned char)sub_417DE0(), v2 = (char*)sub_417DC0(), v9 < (int)v2)) {
			v2 = sub_418A10();
			v5 = v2;
			if (!v2) {
				return;
			}
			sub_418800((wchar_t*)v2, (wchar_t*)(a1 + 2072), 0);
			sub_418830((int)v5, *(uint32_t*)(a1 + 2068));
			sub_4184D0((wchar_t*)v5);
			v6 = v1 + 48;
			v7 = nox_xxx_servObjectHasTeam_419130(v1 + 48);
		} else {
			return;
		}
	}
	if (v7) {
		sub_4196D0(v6, (int)v5, *(uint32_t*)(v1 + 36), 0);
	} else {
		nox_xxx_createAtImpl_4191D0(v5[57], v6, 1, *(uint32_t*)(v1 + 36), 0);
	}
	return;
}

//----- (004DF550) --------------------------------------------------------
int sub_4DF550() { return *getMemU32Ptr(0x5D4594, 1563148); }

//----- (004DF580) --------------------------------------------------------
int sub_4DF580(int a1, uint32_t* a2) {
	int v2; // eax
	int v3; // ecx
	int v4; // ebx
	int v5; // ecx
	int v6; // eax
	int v7; // ecx

	v2 = *(unsigned short*)(a1 + 5);
	if ((unsigned short)v2 - (int)*a2 >= 0) {
		v3 = (unsigned short)v2 - *a2;
	} else {
		v3 = *a2 - v2;
	}
	v4 = a2[2];
	if (v3 >= v4) {
		return 0;
	}
	v5 = a2[1];
	v6 = *(unsigned short*)(a1 + 7);
	v7 = (unsigned short)v6 - v5 >= 0 ? (unsigned short)v6 - v5 : v5 - v6;
	if (v7 >= v4) {
		return 0;
	}
	*getMemU32Ptr(0x5D4594, 1563300) = a1;
	return 1;
}

//----- (004DF5E0) --------------------------------------------------------
int sub_4DF5E0(int a1, int a2) {
	int v3[3]; // [esp+0h] [ebp-Ch]

	v3[0] = *getMemU32Ptr(0x5D4594, 1563292);
	v3[1] = *getMemU32Ptr(0x5D4594, 1563296);
	v3[2] = a2;
	*getMemU32Ptr(0x5D4594, 1563300) = 0;
	nox_netlist_forEach2_40F0F0(a1, sub_4DF580, (int)v3);
	return *getMemU32Ptr(0x5D4594, 1563300);
}

//----- (004DF630) --------------------------------------------------------
int nox_xxx_netFn_UpdateStream_4DF630(int a1, char* a2, unsigned int a3, void* a4) {
	char* v3;        // edi
	int v4;          // ebx
	char* v5;        // ebp
	char* v6;        // eax
	int** v7;        // esi
	unsigned int v8; // eax
	int** v9;        // eax
	char* v10;       // edi
	int v11;         // eax
	char* v13;       // edi
	uint8_t* v14;    // eax
	int** i;         // esi
	signed int v16;  // eax
	int** j;         // eax
	signed int v18;  // eax

	v3 = a2;
	v4 = a1 - 1;
	v5 = &a2[a3];
	v6 = nox_common_playerInfoFromNum_417090(a1 - 1);
	*getMemU32Ptr(0x5D4594, 1563308) = 0;
	*getMemU32Ptr(0x5D4594, 1563312) = 0;
	*getMemU32Ptr(0x5D4594, 1563304) = v6 + 16;
	v7 = nox_netlist_getByInd2_40F080(a1 - 1, &a3);
	if (nox_xxx_chkIsMsgTimestamp_4DF7F0(v7)) {
		v8 = a3;
		memcpy(a2, v7, a3);
		v3 = &a2[v8];
		v9 = nox_netlist_getByInd2_40F080(v4, &a3);
		if (v9) {
			*v3 = -92;
			v10 = v3 + 1;
			v11 = sub_4DF810(v10, (int)v5, (int)v9);
			if (!v11) {
				return v10 - a2 - 1;
			}
			v13 = &v10[v11];
			do {
				v14 = sub_4DF8F0(v4, v13, (int)v5);
				v13 = &v13[(uint32_t)v14];
			} while (v14);
			v3 = &v13[sub_4DF8C0(v13, (int)v5)];
		}
	}
	for (i = nox_netlist_getInd_40EEB0(v4, 1, &a3); i; i = nox_netlist_getInd_40EEB0(v4, 1, &a3)) {
		if (*(char*)i != -107 || *(int*)&dword_5d4594_2650652 != 1 ||
			!(nox_frame_xxx_2598000 % (unsigned int)nox_xxx_rateGet_40A6C0())) {
			v16 = sub_4DFAF0(v3, (int)v5, i, a3);
			if (!v16) {
				return v3 - a2;
			}
			v3 += v16;
		}
	}
	*getMemU32Ptr(0x5D4594, 1563312) = v3 - a2;
	if (!dword_5d4594_2650652 || !(nox_frame_xxx_2598000 % (unsigned int)nox_xxx_rateGet_40A6C0()) ||
		nox_common_gameFlags_check_40A5C0(8)) {
		nox_xxx_netImportant_4E5770(v4, 1);
		for (j = nox_netlist_getInd_40EEB0(v4, 1, &a3); j; j = nox_netlist_getInd_40EEB0(v4, 1, &a3)) {
			v18 = sub_4DFAF0(v3, (int)v5, j, a3);
			if (!v18) {
				break;
			}
			v3 += v18;
		}
	}
	return v3 - a2;
}

//----- (004DF7F0) --------------------------------------------------------
int nox_xxx_chkIsMsgTimestamp_4DF7F0(uint8_t* a1) { return a1 && (*a1 == 39 || *a1 == 40); }

//----- (004DF810) --------------------------------------------------------
int sub_4DF810(char* a1, int a2, int a3) {
	char v4;     // al
	bool v5;     // zf
	char* v6;    // eax
	char v7;     // cl
	uint8_t* v8; // eax
	uint8_t* v9; // eax

	if (*(char*)a3 != -61) {
		return 0;
	}
	if (a2 - (int)a1 < 16) {
		return 0;
	}
	*(uint16_t*)(a3 + 5) &= 0xFFFEu;
	*(uint16_t*)(a3 + 7) &= 0xFFFEu;
	v4 = sub_57B930(*getMemIntPtr(0x5D4594, 1563304), *(unsigned short*)(a3 + 1), *(unsigned short*)(a3 + 3),
					nox_frame_xxx_2598000);
	v5 = v4 == -1;
	*a1 = v4;
	v6 = a1 + 1;
	if (v5) {
		*(uint32_t*)v6 = *(uint32_t*)(a3 + 1);
		v6 = a1 + 5;
	}
	*(uint32_t*)v6 = *(uint32_t*)(a3 + 5);
	v7 = *(uint8_t*)(a3 + 9);
	v8 = v6 + 4;
	*v8 = v7;
	if (*(char*)(a3 + 10) != -1) {
		*v8++ = v7 | 0x80;
		*v8 = *(uint8_t*)(a3 + 10);
	}
	v9 = v8 + 1;
	*v9 = *(uint8_t*)(a3 + 11);
	*getMemU32Ptr(0x5D4594, 1563292) = *(unsigned short*)(a3 + 5);
	*getMemU32Ptr(0x5D4594, 1563296) = *(unsigned short*)(a3 + 7);
	return (char*)v9 - a1 + 1;
}

//----- (004DF8C0) --------------------------------------------------------
int sub_4DF8C0(uint8_t* a1, int a2) {
	if (a2 - (int)a1 < 3) {
		return 0;
	}
	*a1 = 0;
	a1[1] = 0;
	a1[2] = 0;
	return 3;
}

//----- (004DF8F0) --------------------------------------------------------
uint8_t* sub_4DF8F0(int a1, uint8_t* a2, int a3) {
	uint8_t* v3; // ebp
	int v4;      // edi
	int v6;      // esi
	int v7;      // eax
	int v8;      // edi

	v3 = a2;
	v4 = 127;
	if (!nox_netlist_countByInd2_40F0B0(a1)) {
		return 0;
	}
	v6 = sub_4DF5E0(a1, 127);
	if (!v6) {
		while (1) {
			v4 += 127;
			if (v4 > 4064) {
				return 0;
			}
			v6 = sub_4DF5E0(a1, v4);
			if (v6) {
				if (v4 <= 127) {
					break;
				}
				*a2 = 0;
				v7 = 1;
				v3 = a2 + 1;
				goto LABEL_9;
			}
		}
	}
	v7 = 0;
LABEL_9:
	v8 = sub_4DF9B0((int)v3, a3, v6, v7);
	if (v8 == -1) {
		return (uint8_t*)(v3 - a2);
	}
	nox_netlist_findAndFreeBuf_40F000(a1, v6);
	return &v3[v8 - (uint32_t)a2];
}

//----- (004DF9B0) --------------------------------------------------------
int sub_4DF9B0(int a1, int a2, int a3, int a4) {
	char v4;            // al
	unsigned short* v5; // esi
	unsigned short v6;  // ax
	uint16_t* v7;       // esi
	uint8_t* v8;        // esi
	uint8_t* v10;       // esi
	char v11;           // al
	float v12;          // [esp+0h] [ebp-14h]
	float v13;          // [esp+0h] [ebp-14h]

	if (a2 - a1 < 8 || a4 && a2 - a1 < 10) {
		return -1;
	}
	v4 = sub_57B930(*getMemIntPtr(0x5D4594, 1563304), *(unsigned short*)(a3 + 1), *(unsigned short*)(a3 + 3),
					nox_frame_xxx_2598000);
	*(uint8_t*)a1 = v4;
	v5 = (unsigned short*)(a1 + 1);
	if (v4 == -1) {
		*v5 = *(uint16_t*)(a3 + 1);
		*(uint16_t*)(a1 + 3) = *(uint16_t*)(a3 + 3);
		v5 = (unsigned short*)(a1 + 5);
	}
	if (a4) {
		v6 = *(uint16_t*)(a3 + 5);
		if (v6 > 0x1770u || *(uint16_t*)(a3 + 7) > 0x1770u) {
			return 0;
		}
		*v5 = v6;
		v7 = v5 + 1;
		*v7 = *(uint16_t*)(a3 + 7);
		v8 = v7 + 1;
	} else {
		v12 = (double)*(unsigned short*)(a3 + 5);
		*(uint8_t*)v5 = nox_float2int(v12) - getMemByte(0x5D4594, 1563292);
		v10 = (char*)v5 + 1;
		v13 = (double)*(unsigned short*)(a3 + 7);
		*v10 = nox_float2int(v13) - getMemByte(0x5D4594, 1563296);
		v8 = v10 + 1;
	}
	*getMemU32Ptr(0x5D4594, 1563292) = *(unsigned short*)(a3 + 5);
	*getMemU32Ptr(0x5D4594, 1563296) = *(unsigned short*)(a3 + 7);
	if (*(char*)a3 == 48 || *(char*)a3 == -61) {
		v11 = *(uint8_t*)(a3 + 9);
		*v8 = v11;
		if (*(char*)(a3 + 10) != -1) {
			*v8++ = v11 | 0x80;
			*v8 = *(uint8_t*)(a3 + 10);
		}
		if (*(char*)a3 == -61) {
			*++v8 = *(uint8_t*)(a3 + 11);
		}
		++v8;
	}
	return (int)&v8[-a1];
}

//----- (004DFAF0) --------------------------------------------------------
signed int sub_4DFAF0(void* a1, int a2, const void* a3, signed int a4) {
	signed int result; // eax

	result = a4;
	if (a2 - (int)a1 < a4) {
		return 0;
	}
	memcpy(a1, a3, a4);
	return result;
}

//----- (004DFB50) --------------------------------------------------------
uint32_t* sub_4DFB50(int a1, int a2) {
	*(uint8_t*)(a2 + 440) |= 8u;
	return nox_xxx_aud_501960(75, a2, 0, 0);
}

//----- (004DFB80) --------------------------------------------------------
uint32_t* sub_4DFB80(int a1, int a2) {
	if (!nox_xxx_enchantItemTestInventory_4DFBB0(a2, 8)) {
		*(uint8_t*)(a2 + 440) &= 0xF7u;
	}
	return nox_xxx_aud_501960(76, a2, 0, 0);
}

//----- (004DFBB0) --------------------------------------------------------
int nox_xxx_enchantItemTestInventory_4DFBB0(int a1, char a2) {
	uint32_t* v2;      // ebp
	int v3;            // eax
	int v4;            // edi
	int v5;            // esi
	unsigned char* v6; // eax

	if (!a1) {
		return 0;
	}
	if (!a2) {
		return 0;
	}
	v2 = *(uint32_t**)(a1 + 504);
	if (!v2) {
		return 0;
	}
	while (1) {
		v3 = v2[4];
		if (v3 & 0x100) {
			if (v2[2] & 0x13001000) {
				break;
			}
		}
	LABEL_13:
		v2 = (uint32_t*)v2[124];
		if (!v2) {
			return 0;
		}
	}
	v4 = 0;
	v5 = v2[173];
	while (!*(uint32_t*)v5) {
	LABEL_12:
		++v4;
		v5 += 4;
		if (v4 >= 4) {
			goto LABEL_13;
		}
	}
	v6 = getMemAt(0x587000, 200164);
	while (*(uint32_t*)(*(uint32_t*)v5 + 112) != *((uint32_t*)v6 - 1) || a2 != *v6) {
		v6 += 20;
		if ((int)v6 >= (int)getMemAt(0x587000, 200284)) {
			goto LABEL_12;
		}
	}
	return 1;
}

//----- (004DFC30) --------------------------------------------------------
void nox_xxx_effectSpeedEngage_4DFC30(int a1, int a2) {
	int v2; // esi
	int v3; // edx
	int v5; // [esp+Ch] [ebp+8h]

	v2 = a2;
	if (a2) {
		if (*(uint8_t*)(a2 + 8) & 4) {
			v3 = *(uint32_t*)(a2 + 748);
			*(uint8_t*)(a2 + 440) |= 0x10u;
			*(float*)&v5 = *(float*)(a1 + 120) + *(float*)(a2 + 552);
			*(float*)(v2 + 552) = *(float*)&v5;
			nox_xxx_netReportStatsSpeed_4D9360(*(unsigned char*)(*(uint32_t*)(v3 + 276) + 2064), (uint32_t*)v2, 0, v5);
			nox_xxx_aud_501960(59, v2, 0, 0);
		}
	}
}

//----- (004DFCA0) --------------------------------------------------------
void nox_xxx_effectSpeedDisengage_4DFCA0(int a1, int a2) {
	int v2; // esi
	int v3; // edx
	int v4; // [esp+Ch] [ebp+8h]

	v2 = a2;
	if (a2 && *(uint8_t*)(a2 + 8) & 4) {
		if (!nox_xxx_enchantItemTestInventory_4DFBB0(a2, 16)) {
			*(uint8_t*)(a2 + 440) &= 0xEFu;
		}
		v3 = *(uint32_t*)(a2 + 748);
		*(float*)&v4 = *(float*)(a2 + 552) - *(float*)(a1 + 120);
		*(float*)(v2 + 552) = *(float*)&v4;
		nox_xxx_netReportStatsSpeed_4D9360(*(unsigned char*)(*(uint32_t*)(v3 + 276) + 2064), (uint32_t*)v2, 0, v4);
		nox_xxx_aud_501960(60, v2, 0, 0);
	}
}

//----- (004DFD10) --------------------------------------------------------
uint32_t* sub_4DFD10(int a1, int a2) {
	*(uint8_t*)(a2 + 440) |= 1u;
	return nox_xxx_aud_501960(102, a2, 0, 0);
}

//----- (004DFD40) --------------------------------------------------------
void nox_xxx_modifFireProtection_4DFD40(int a1, int a2, int a3) {
	if (a2 && a3) {
		if (!nox_xxx_enchantItemTestInventory_4DFBB0(a2, 1)) {
			*(uint8_t*)(a2 + 440) &= 0xFEu;
		}
		nox_xxx_aud_501960(103, a2, 0, 0);
	}
}

//----- (004DFD80) --------------------------------------------------------
uint32_t* nox_xxx_buff_4DFD80(int a1, int a2) {
	*(uint8_t*)(a2 + 440) |= 4u;
	return nox_xxx_aud_501960(106, a2, 0, 0);
}

//----- (004DFDB0) --------------------------------------------------------
uint32_t* sub_4DFDB0(int a1, int a2) {
	if (!nox_xxx_enchantItemTestInventory_4DFBB0(a2, 4)) {
		*(uint8_t*)(a2 + 440) &= 0xFBu;
	}
	return nox_xxx_aud_501960(107, a2, 0, 0);
}

//----- (004DFDE0) --------------------------------------------------------
uint32_t* nox_xxx_checkPoisonProtectEnch_4DFDE0(int a1, int a2) {
	*(uint8_t*)(a2 + 440) |= 2u;
	return nox_xxx_aud_501960(110, a2, 0, 0);
}

//----- (004DFE10) --------------------------------------------------------
uint32_t* sub_4DFE10(int a1, int a2) {
	if (!nox_xxx_enchantItemTestInventory_4DFBB0(a2, 2)) {
		*(uint8_t*)(a2 + 440) &= 0xFDu;
	}
	return nox_xxx_aud_501960(111, a2, 0, 0);
}

//----- (004DFE40) --------------------------------------------------------
double nox_xxx_checkFireProtect_4DFE40(uint32_t* a1) {
	double v1;         // st7
	double result;     // st7
	uint32_t* v3;      // edx
	int v4;            // eax
	int* v5;           // ecx
	int v6;            // esi
	int v7;            // eax
	int* v8;           // ecx
	int v9;            // edx
	int v10;           // eax
	unsigned char v11; // al
	float v12;         // [esp+4h] [ebp-4h]

	v1 = 0.0;
	v12 = 0.0;
	if (!a1) {
		return 0.0;
	}
	v3 = (uint32_t*)a1[126];
	if (v3) {
		do {
			v4 = v3[4];
			if (v4 & 0x100 && v3[2] & 0x13001000) {
				v5 = (int*)v3[173];
				v6 = 4;
				do {
					v7 = *v5;
					if (*v5 && *(uint32_t * (**)(int, int))(v7 + 112) == sub_4DFD10) {
						v1 = v1 + *(float*)(v7 + 120);
					}
					++v5;
					--v6;
				} while (v6);
			}
			v3 = (uint32_t*)v3[124];
		} while (v3);
		v12 = v1;
	}
	if (a1[2] & 0x13001000) {
		v8 = (int*)a1[173];
		v9 = 4;
		do {
			v10 = *v8;
			if (*v8 && *(uint32_t * (**)(int, int))(v10 + 112) == sub_4DFD10) {
				v1 = v1 + *(float*)(v10 + 120);
			}
			++v8;
			--v9;
		} while (v9);
		v12 = v1;
	}
	if (v1 > 0.5) {
		v12 = 0.5;
	}
	if (nox_xxx_testUnitBuffs_4FF350((int)a1, 17)) {
		v11 = nox_xxx_buffGetPower_4FF570((int)a1, 17);
		result = nox_xxx_gamedataGetFloatTable_419D70("FireSpellProtection", (unsigned int)v11 - 1) + v12;
	} else {
		result = v12;
	}
	if (result > 0.60000002) {
		result = 0.60000002;
	}
	return result;
}

//----- (004DFF40) --------------------------------------------------------
double nox_xxx_checkElectrProtect_4DFF40(uint32_t* a1) {
	double v1;         // st7
	double result;     // st7
	uint32_t* v3;      // edx
	int v4;            // eax
	int* v5;           // ecx
	int v6;            // esi
	int v7;            // eax
	int* v8;           // ecx
	int v9;            // edx
	int v10;           // eax
	unsigned char v11; // al
	float v12;         // [esp+4h] [ebp-4h]

	v1 = 0.0;
	v12 = 0.0;
	if (!a1) {
		return 0.0;
	}
	v3 = (uint32_t*)a1[126];
	if (v3) {
		do {
			v4 = v3[4];
			if (v4 & 0x100 && v3[2] & 0x13001000) {
				v5 = (int*)v3[173];
				v6 = 4;
				do {
					v7 = *v5;
					if (*v5 && *(uint32_t * (**)(int, int))(v7 + 112) == nox_xxx_buff_4DFD80) {
						v1 = v1 + *(float*)(v7 + 120);
					}
					++v5;
					--v6;
				} while (v6);
			}
			v3 = (uint32_t*)v3[124];
		} while (v3);
		v12 = v1;
	}
	if (a1[2] & 0x13001000) {
		v8 = (int*)a1[173];
		v9 = 4;
		do {
			v10 = *v8;
			if (*v8 && *(uint32_t * (**)(int, int))(v10 + 112) == nox_xxx_buff_4DFD80) {
				v1 = v1 + *(float*)(v10 + 120);
			}
			++v8;
			--v9;
		} while (v9);
		v12 = v1;
	}
	if (v1 >= 0.5) {
		v12 = 0.5;
	}
	if (nox_xxx_testUnitBuffs_4FF350((int)a1, 20)) {
		v11 = nox_xxx_buffGetPower_4FF570((int)a1, 20);
		result = nox_xxx_gamedataGetFloatTable_419D70("ElectricitySpellProtection", (unsigned int)v11 - 1) + v12;
	} else {
		result = v12;
	}
	if (result > 0.60000002) {
		result = 0.60000002;
	}
	return result;
}

//----- (004E0040) --------------------------------------------------------
double nox_xxx_getPoisonDmg_4E0040(uint32_t* a1) {
	double v1;         // st7
	double result;     // st7
	uint32_t* v3;      // edx
	int v4;            // eax
	int* v5;           // ecx
	int v6;            // esi
	int v7;            // eax
	int* v8;           // ecx
	int v9;            // edx
	int v10;           // eax
	unsigned char v11; // al
	float v12;         // [esp+4h] [ebp-4h]

	v1 = 0.0;
	v12 = 0.0;
	if (!a1) {
		return 0.0;
	}
	v3 = (uint32_t*)a1[126];
	if (v3) {
		do {
			v4 = v3[4];
			if (v4 & 0x100 && v3[2] & 0x13001000) {
				v5 = (int*)v3[173];
				v6 = 4;
				do {
					v7 = *v5;
					if (*v5 && *(uint32_t * (**)(int, int))(v7 + 112) == nox_xxx_checkPoisonProtectEnch_4DFDE0) {
						v1 = v1 + *(float*)(v7 + 120);
					}
					++v5;
					--v6;
				} while (v6);
			}
			v3 = (uint32_t*)v3[124];
		} while (v3);
		v12 = v1;
	}
	if (a1[2] & 0x13001000) {
		v8 = (int*)a1[173];
		v9 = 4;
		do {
			v10 = *v8;
			if (*v8 && *(uint32_t * (**)(int, int))(v10 + 112) == nox_xxx_checkPoisonProtectEnch_4DFDE0) {
				v1 = v1 + *(float*)(v10 + 120);
			}
			++v8;
			--v9;
		} while (v9);
		v12 = v1;
	}
	if (v1 > 0.69999999) {
		v12 = 0.69999999;
	}
	if (nox_xxx_testUnitBuffs_4FF350((int)a1, 18)) {
		v11 = nox_xxx_buffGetPower_4FF570((int)a1, 18);
		result = nox_xxx_gamedataGetFloatTable_419D70("PoisonSpellProtection", (unsigned int)v11 - 1) + v12;
	} else {
		result = v12;
	}
	if (result > 0.89999998) {
		result = 0.89999998;
	}
	return result;
}

//----- (004E0140) --------------------------------------------------------
uint32_t* sub_4E0140(int a1, int a2) {
	*(uint8_t*)(a2 + 440) |= 0x20u;
	return nox_xxx_aud_501960(123, a2, 0, 0);
}

//----- (004E0170) --------------------------------------------------------
void sub_4E0170(int a1, int a2) {
	if (a2 && *(uint8_t*)(a2 + 8) & 4) {
		if (!nox_xxx_enchantItemTestInventory_4DFBB0(a2, 32)) {
			*(uint8_t*)(a2 + 440) &= 0xDFu;
		}
		nox_xxx_aud_501960(124, a2, 0, 0);
	}
}

//----- (004E01D0) --------------------------------------------------------
void nox_xxx_effectRegeneration_4E01D0(int a1, int a2) {
	uint32_t* v2;      // esi
	unsigned short v3; // di
	unsigned int v4;   // edi
	int v5;            // eax

	if (a2) {
		v2 = *(uint32_t**)(a2 + 492);
		if (v2) {
			if (v2[139]) {
				if ((unsigned int)(nox_frame_xxx_2598000 - v2[134]) >= (int)nox_gameFPS && !(v2[4] & 0x8020)) {
					v3 = nox_xxx_unitGetMaxHP_4EE7A0(*(uint32_t*)(a2 + 492));
					if ((unsigned short)nox_xxx_unitGetHP_4EE780((int)v2) < v3) {
						v4 = *(uint32_t*)(a1 + 108);
						if (*(uint32_t*)(a2 + 8) & 0x2000000) {
							v5 = nox_xxx_unitArmorInventoryEquipFlags_415C70(a2);
							if (v5 & 0x4000) {
								v4 /= 3u;
							}
						}
						if (!(nox_frame_xxx_2598000 %
							  (v4 * nox_gameFPS / (unsigned short)nox_xxx_unitGetMaxHP_4EE7A0((int)v2)))) {
							nox_xxx_unitAdjustHP_4EE460((int)v2, 1);
						}
					}
				}
			}
		}
	}
}

//----- (004E02C0) --------------------------------------------------------
void nox_xxx_attribContinualReplen_4E02C0(int a1, uint32_t* a2) {
	int v2;           // eax
	int v3;           // ecx
	unsigned char v4; // dl
	unsigned char v5; // al
	int v6;           // esi
	int v7;           // edx
	int v8;           // ecx

	if (a2) {
		if (!(nox_frame_xxx_2598000 % *(uint32_t*)(a1 + 108))) {
			v2 = a2[2];
			v3 = a2[184];
			if (v2 & 0x1000) {
				v4 = *(uint8_t*)(v3 + 108);
				v5 = *(uint8_t*)(v3 + 109);
				v6 = v4++;
				*(uint8_t*)(v3 + 108) = v4;
				if (v4 > v5) {
					*(uint8_t*)(v3 + 108) = v5;
				}
				v7 = *(unsigned char*)(v3 + 108);
				if (v6 != v7) {
					v8 = a2[123];
					if (v8) {
						if (*(uint8_t*)(v8 + 8) & 4) {
							nox_xxx_netReportCharges_4D82B0(
								*(unsigned char*)(*(uint32_t*)(*(uint32_t*)(v8 + 748) + 276) + 2064), a2, v7, v5);
						}
					}
				}
			}
		}
	}
}

//----- (004E0370) --------------------------------------------------------
float* sub_4E0370(int a1, int a2, int a3, int a4, int a5, float* a6) {
	float* result; // eax

	result = a6;
	*a6 = *(float*)(a1 + 80) * *a6;
	return result;
}

//----- (004E0380) --------------------------------------------------------
float* sub_4E0380(int a1, int a2, int a3, int a4, int a5, float* a6) {
	float* result; // eax

	result = a6;
	*a6 = (1.0 - *(float*)(a1 + 80) + 1.0) * *a6;
	return result;
}

//----- (004E03D0) --------------------------------------------------------
int nox_xxx_inversionEffect_4E03D0(int a1, int a2, int a3, int a4, int a5, int* a6) {
	int result; // eax

	result = *(uint32_t*)(a1 + 96) >= 1;
	*a6 = result;
	return result;
}

//----- (004E03F0) --------------------------------------------------------
int nox_xxx_unusedCheckGripEffect_4E03F0(int a1, int a2, int a3, int a4) {
	int v4;                                   // esi
	int v5;                                   // edi
	uint32_t* v6;                             // eax
	int v7;                                   // eax
	int (*v8)(int, int, int, int, int, int*); // ecx
	bool v9;                                  // cc
	uint32_t* i;                              // [esp+10h] [ebp-4h]
	int v12;                                  // [esp+20h] [ebp+Ch]

	v4 = a3;
	if (!a3 || !(*(uint32_t*)(a3 + 8) & 0x3001000)) {
		return 0;
	}
	v5 = a4;
	v6 = (uint32_t*)(*(uint32_t*)(a3 + 692) + 8);
	v12 = 2;
	for (i = v6;; ++i) {
		v7 = *v6;
		if (v7) {
			v8 = *(int (**)(int, int, int, int, int, int*))(v7 + 88);
			if (v8 == nox_xxx_gripEffect_4E0480) {
				v8(v7, v4, a2, v5, a1, &a4);
				if (!a4) {
					break;
				}
			}
		}
		v6 = i + 1;
		v9 = ++v12 < 4;
		if (!v9) {
			return 0;
		}
	}
	return 1;
}

//----- (004E0480) --------------------------------------------------------
int nox_xxx_gripEffect_4E0480(int a1, int a2, int a3, int a4, int a5, int* a6) {
	int result; // eax

	result = *(uint32_t*)(a1 + 96) < 1;
	*a6 = result;
	return result;
}

//----- (004E04C0) --------------------------------------------------------
float* nox_xxx_effectDamageMultiplier_4E04C0(int a1, int a2, int a3, int a4, float* a5) {
	float* result; // eax

	result = a5;
	*a5 = *(float*)(a1 + 44) * *a5;
	return result;
}

//----- (004E04D0) --------------------------------------------------------
void nox_xxx_stunEffect_4E04D0(int a1, int a2, int a3, int a4) {
	int v4;    // esi
	int v5;    // ecx
	int v6;    // eax
	int v8;    // eax
	int v9[3]; // [esp+4h] [ebp-Ch]

	v4 = a4;
	if (*(uint8_t*)(a4 + 8) & 6) {
		v5 = *(uint32_t*)(a4 + 60);
		v9[1] = *(uint32_t*)(a4 + 56);
		v6 = *(uint32_t*)(a1 + 60);
		v9[2] = v5;
		v9[0] = a4;
		nox_xxx_castStun_52C2C0(74, a3, a3, a3, v9, v6);
		if (*(uint8_t*)(v4 + 8) & 4) {
			v8 = *(uint32_t*)(v4 + 748);
			a4 = 0;
			nox_xxx_netInformTextMsg_4DA0F0(*(unsigned char*)(*(uint32_t*)(v8 + 276) + 2064), 13, &a4);
		}
	}
}

//----- (004E0550) --------------------------------------------------------
uint32_t* nox_xxx_fireEffect_4E0550(int a1, int a2, int a3, int a4) {
	uint32_t* result; // eax
	float v5;         // [esp+8h] [ebp+4h]

	result = (uint32_t*)a1;
	v5 = *(float*)(a1 + 56);
	if (a4) {
		(*(void (**)(int, int, int, uint32_t, int))(a4 + 716))(a4, a3, a2, (long long)v5, 7);
		nox_xxx_netSparkExplosionFx_5231B0((float*)(a4 + 56), (long long)(v5 * 10.0));
		result = nox_xxx_aud_501960(224, a4, 0, 0);
	}
	return result;
}

//----- (004E05B0) --------------------------------------------------------
int nox_xxx_fireRingEffect_4E05B0(int a1, int a2, int a3) {
	int result; // eax
	int v4;     // edx
	int v5[3];  // [esp+0h] [ebp-Ch]

	result = a3;
	if (a3) {
		v4 = *(uint32_t*)(a3 + 60);
		v5[1] = *(uint32_t*)(a3 + 56);
		v5[2] = v4;
		v5[0] = 0;
		result = nox_xxx_spellCastCleansingFlame_52D5C0(10, a3, a3, a3, (int)v5, *(uint32_t*)(a1 + 48));
	}
	return result;
}

//----- (004E05F0) --------------------------------------------------------
int nox_xxx_blueFREffect_4E05F0(int a1, int a2, int a3) {
	int result; // eax
	int v4;     // edx
	int v5[3];  // [esp+0h] [ebp-Ch]

	result = a3;
	if (a3) {
		v4 = *(uint32_t*)(a3 + 60);
		v5[1] = *(uint32_t*)(a3 + 56);
		v5[2] = v4;
		v5[0] = 0;
		result = nox_xxx_spellCastCleansingFlame_52D5C0(11, a3, a3, a3, (int)v5, *(uint32_t*)(a1 + 48));
	}
	return result;
}

//----- (004E0640) --------------------------------------------------------
void nox_xxx_recoilEffect_4E0640(int a1, int a2, int a3, int a4) {
	if (a2) {
		if (a4) {
			nox_xxx_objectApplyForce_52DF80(a2 + 56, a4, *(float*)(a1 + 56));
		}
	}
}

//----- (004E0670) --------------------------------------------------------
void nox_xxx_confuseEffect_4E0670(int a1, int a2, int a3, int a4) {
	int v4;    // esi
	int v5;    // ecx
	int v6;    // eax
	int v8;    // eax
	int v9[3]; // [esp+4h] [ebp-Ch]

	v4 = a4;
	if (*(uint8_t*)(a4 + 8) & 6) {
		v5 = *(uint32_t*)(a4 + 60);
		v9[1] = *(uint32_t*)(a4 + 56);
		v6 = *(uint32_t*)(a1 + 60);
		v9[2] = v5;
		v9[0] = a4;
		nox_xxx_castConfuse_52C1E0(12, a3, a3, a3, v9, v6);
		if (*(uint8_t*)(v4 + 8) & 4) {
			v8 = *(uint32_t*)(v4 + 748);
			a4 = 1;
			nox_xxx_netInformTextMsg_4DA0F0(*(unsigned char*)(*(uint32_t*)(v8 + 276) + 2064), 13, &a4);
		}
	}
}

//----- (004E06F0) --------------------------------------------------------
void nox_xxx_lightngEffect_4E06F0(int a1, int a2, int a3, int a4) {
	if (a4) {
		(*(void (**)(int, int, int, uint32_t, int))(a4 + 716))(a4, a3, a2, (long long)*(float*)(a1 + 56), 9);
		nox_xxx_netSendPointFx_522FF0(129, (float2*)(a4 + 56));
		nox_xxx_aud_501960(225, a4, 0, 0);
	}
}

//----- (004E0740) --------------------------------------------------------
void nox_xxx_drainMEffect_4E0740(int a1, int a2, int a3, int a4, int* a5) {
	int v5;            // edi
	unsigned short v6; // ax
	short v7;          // si

	if (a3 && a4 && *(uint8_t*)(a4 + 8) & 6) {
		v5 = (long long)(*(float*)(a1 + 68) * (double)*a5);
		if (!v5) {
			v5 = 1;
		}
		v6 = nox_xxx_unitGetOldMana_4EEC80(a4);
		v7 = v6;
		if (v6 < v5) {
			nox_xxx_playerManaSub_4EEBF0(a4, v6);
			nox_xxx_playerManaAdd_4EEB80(a3, v7);
		} else {
			nox_xxx_playerManaSub_4EEBF0(a4, v5);
			nox_xxx_playerManaAdd_4EEB80(a3, v5);
		}
	}
}

//----- (004E07C0) --------------------------------------------------------
void nox_xxx_vampirismEffect_4E07C0(int a1, int a2, int a3, int a4, int* a5) {
	int v5; // eax
	int v6; // esi
	int v7; // eax

	if (a3) {
		if (a4) {
			v5 = *(uint32_t*)(a4 + 8);
			if (v5 & 6) {
				if (!(v5 & 2) || !(*(uint8_t*)(a4 + 12) & 0x40)) {
					v6 = (long long)((double)*a5 * *(float*)(a1 + 68));
					if (!v6) {
						v6 = 1;
					}
					v7 = (unsigned short)nox_xxx_unitGetHP_4EE780(a4);
					if (v7 < v6) {
						nox_xxx_unitAdjustHP_4EE460(a3, v7);
					} else {
						nox_xxx_unitAdjustHP_4EE460(a3, v6);
					}
				}
			}
		}
	}
}

//----- (004E0850) --------------------------------------------------------
void nox_xxx_poisonEffect_4E0850(int a1, int a2, int a3, int a4) {
	int v4; // esi
	int v5; // eax

	v4 = a4;
	if ((!(*(uint8_t*)(a4 + 8) & 4) || *(uint8_t*)(*(uint32_t*)(a4 + 748) + 88) != 16 ||
		 !(nox_server_testTwoPointsAndDirection_4E6E50((float2*)(a4 + 56), *(short*)(a4 + 124), (float2*)(a3 + 56)) &
		   1)) &&
		*(uint8_t*)(v4 + 8) & 6 && nox_xxx_activatePoison_4EE7E0(v4, 1, *(uint32_t*)(a1 + 72))) {
		if (*(uint8_t*)(v4 + 8) & 4) {
			v5 = *(uint32_t*)(v4 + 748);
			a4 = 2;
			nox_xxx_netInformTextMsg_4DA0F0(*(unsigned char*)(*(uint32_t*)(v5 + 276) + 2064), 13, &a4);
		}
	}
}

//----- (004E08E0) --------------------------------------------------------
void nox_xxx_sympathyEffect_4E08E0(int a1, int a2, int a3, int a4, int* a5) {
	int v5;    // edi
	int v6;    // esi
	int v7;    // eax
	int v8;    // [esp-8h] [ebp-Ch]
	int v9;    // [esp+10h] [ebp+Ch]
	float v10; // [esp+14h] [ebp+10h]

	v5 = a3;
	if (a3 && a4 && *(uint8_t*)(a4 + 8) & 6) {
		v8 = a4;
		v10 = *(float*)(a1 + 68);
		v6 = *a5;
		v9 = *a5;
		v7 = (unsigned short)nox_xxx_unitGetHP_4EE780(v8);
		if (v7 < v6) {
			v9 = v7;
		}
		nox_xxx_unitDamageClear_4EE5E0(v5, (long long)((double)v9 * v10));
	}
}

//----- (004E0960) --------------------------------------------------------
int nox_xxx_itemCheckReadinessEffect_4E0960(int a1) {
	int v1; // esi
	int v2; // edx
	int i;  // ecx

	v1 = *(uint32_t*)(a1 + 692);
	if (!a1 || !(*(uint32_t*)(a1 + 8) & 0x13001000)) {
		return 0;
	}
	v2 = 2;
	for (i = v1 + 8; !*(uint32_t*)i || *(int (**)())(*(uint32_t*)i + 40) != nullsub_22; i += 4) {
		if (++v2 >= 4) {
			return 0;
		}
	}
	return *(uint32_t*)(*(uint32_t*)(v1 + 4 * v2) + 48);
}
// 4E0950: using guessed type void nullsub_22();

//----- (004E09B0) --------------------------------------------------------
int nox_xxx_effectProjectileSpeed_4E09B0(int a1, int a2, int a3, int a4, int a5) {
	int result; // eax

	result = a5;
	*(float*)(a5 + 544) = *(float*)(a1 + 44) * *(float*)(a5 + 544);
	return result;
}

//----- (004E0A00) --------------------------------------------------------
int nox_xxx_parseDamageTypeByName_4E0A00(const char* a1) {
	int v1;          // ebp
	const char** v2; // edi

	v1 = 0;
	v2 = (const char**)getMemAt(0x587000, 200728);
	do {
		if (!strcmp(a1, *v2)) {
			break;
		}
		++v2;
		++v1;
	} while ((int)v2 < (int)getMemAt(0x587000, 200800));
	return v1;
}

//----- (004E0A70) --------------------------------------------------------
int nox_xxx_projectileReflect_4E0A70(int a1, int a2) {
	int result; // eax
	double v3;  // st7
	double v4;  // st6
	short v5;   // cx
	double v6;  // st5
	double v7;  // st6
	int v8;     // edx
	float v9;   // [esp+0h] [ebp-10h]
	float v10;  // [esp+4h] [ebp-Ch]
	float v11;  // [esp+8h] [ebp-8h]
	float v12;  // [esp+8h] [ebp-8h]
	float v13;  // [esp+14h] [ebp+4h]

	result = a1;
	v3 = *(float*)(a1 + 56) - *(float*)(a2 + 56);
	v4 = *(float*)(a1 + 60) - *(float*)(a2 + 60);
	*(uint16_t*)(a1 + 124) += 128;
	v5 = *(uint16_t*)(a1 + 124);
	v11 = -v4;
	v13 = sqrt(v4 * v4 + v3 * v3) + 0.1;
	v6 = (v4 * *(float*)(result + 84) + v3 * *(float*)(result + 80)) / v13;
	v9 = v6 * v3 / v13;
	v10 = v6 * v4 / v13;
	v7 = (v11 * *(float*)(result + 80) + v3 * *(float*)(result + 84)) / v13;
	v12 = v7 * v11 / v13;
	*(float*)(result + 80) = v12 - v9;
	*(float*)(result + 84) = v3 * v7 / v13 - v10;
	if (v5 >= 256) {
		*(uint16_t*)(result + 124) = v5 - 256;
	}
	v8 = *(uint32_t*)(result + 76);
	*(uint32_t*)(result + 64) = *(uint32_t*)(result + 72);
	*(uint32_t*)(result + 68) = v8;
	return result;
}

//----- (004E0B30) --------------------------------------------------------
int nox_xxx_damageDefaultProc_4E0B30(int a1, int a2, int a3, int a4, int a5) {
	int v6;                // edi
	int v7;                // eax
	int v8;                // eax
	int v9;                // eax
	int v10;               // edi
	int v11;               // eax
	int v12;               // ebp
	int v13;               // eax
	int v14;               // eax
	int v15;               // ebp
	double v16;            // st7
	double v17;            // st7
	int v18;               // eax
	int v19;               // ebx
	int v20;               // eax
	int v21;               // edx
	int v22;               // eax
	char v23;              // al
	uint32_t* v24;         // eax
	int v25;               // edx
	int v26;               // ecx
	int v27;               // eax
	int v28;               // eax
	void (*v29)(int, int); // eax
	unsigned char v30;     // al
	double v31;            // st7
	unsigned short v32;    // bp
	int v33;               // eax
	float v34;             // ecx
	int v35;               // eax
	float v36;             // edx
	char v37;              // al
	int v38;               // ebp
	int v39;               // eax
	int v40;               // eax
	float v41;             // [esp+0h] [ebp-28h]
	float v42;             // [esp+4h] [ebp-24h]
	float v43;             // [esp+4h] [ebp-24h]
	float v44;             // [esp+4h] [ebp-24h]
	int v45[4];            // [esp+18h] [ebp-10h]
	float v46;             // [esp+30h] [ebp+8h]
	float v47;             // [esp+30h] [ebp+8h]

	if (!a1) {
		return 1;
	}
	if (nox_xxx_testUnitBuffs_4FF350(a1, 23)) {
		if (!((unsigned char)nox_frame_xxx_2598000 & 3)) {
			nox_xxx_aud_501960(71, a1, 0, 0);
			return 1;
		}
		return 1;
	}
	v6 = a5;
	if (*(uint8_t*)(a1 + 8) & 2) {
		v7 = *(uint32_t*)(a1 + 748);
		*(uint32_t*)(v7 + 2188) = 0;
		if (v6 == 1 || v6 == 12 || v6 == 7 || v6 == 14 || v6 == 6) {
			*(uint32_t*)(v7 + 1440) |= 0x80000u;
		}
	}
	v8 = *(uint32_t*)(a1 + 16);
	if ((v8 & 0x8000) == 0) {
		v10 = a2;
		if (!nox_xxx_CheckGameplayFlags_417DA0(1)) {
			v11 = nox_xxx_findParentChainPlayer_4EC580(a2);
			v12 = v11;
			if (v11) {
				if (*(uint8_t*)(v11 + 8) & 6 && !nox_xxx_unitIsEnemyTo_5330C0(a1, v11) &&
					(a1 != v12 || nox_common_gameFlags_check_40A5C0(4096))) {
					return 1;
				}
			}
		}
		if (a2 && a3 && !nox_xxx_unitIsEnemyTo_5330C0(a1, a2) && *(uint8_t*)(a1 + 8) & 6 &&
				sub_4E1400(a2, (uint32_t*)a3) && !sub_4E1470(a3) ||
			*(uint8_t*)(a1 + 16) & 2) {
			return 1;
		}
		if (a2) {
			if (nox_xxx_testUnitBuffs_4FF350(a1, 22)) {
				if (*(uint8_t*)(a2 + 8) & 6) {
					if (a3) {
						if (sub_4E1400(a2, (uint32_t*)a3)) {
							nox_xxx_aud_501960(135, a2, 0, 0);
							nox_xxx_spellBuffOff_4FF5B0(a1, 22);
							v41 = nox_xxx_gamedataGetFloatTable_419D70("ShockDamage", 4);
							v13 = nox_float2int(v41);
							(*(void (**)(int, int, uint32_t, int, int))(a2 + 716))(a2, a1, 0, v13, 9);
							if (*(uint8_t*)(a2 + 8) & 4) {
								nox_xxx_playerSetState_4FA020((uint32_t*)a2, 23);
							}
						}
					}
				}
			}
		}
		if (*(uint8_t*)(a1 + 8) & 2) {
			v14 = *(uint32_t*)(a1 + 12);
			v15 = a5;
			if (v14 & 0x200 && a5 == 5) {
				return 1;
			}
			if (v14 & 0x400) {
				if (a5 == 1 || a5 == 12) {
					return 1;
				}
				if (a5 == 7) {
					a4 /= 2;
				LABEL_53:
					v16 = nox_xxx_checkFireProtect_4DFE40((uint32_t*)a1);
					if (v16 != 0.0 && !((unsigned char)nox_frame_xxx_2598000 & 3)) {
						nox_xxx_aud_501960(104, a1, 0, 0);
					}
					v46 = v16;
					v42 = (1.0 - v46) * (double)a4;
					a4 = nox_float2int(v42);
					if (!a4) {
						a4 = 1;
					}
				LABEL_58:
					if (v15 == 9 || v15 == 17) {
						v17 = nox_xxx_checkElectrProtect_4DFF40((uint32_t*)a1);
						if (v17 != 0.0 && !((unsigned char)nox_frame_xxx_2598000 & 3)) {
							nox_xxx_aud_501960(108, a1, 0, 0);
						}
						v47 = v17;
						v43 = (1.0 - v47) * (double)a4;
						a4 = nox_float2int(v43);
						if (!a4) {
							a4 = 1;
						}
						v18 = *(uint32_t*)(a1 + 8);
						if (v18 & 4) {
							*(uint16_t*)(*(uint32_t*)(a1 + 748) + 160) = 2;
						} else if (v18 & 2 && *(uint8_t*)(a1 + 12) & 0x10) {
							*(uint8_t*)(*(uint32_t*)(a1 + 748) + 2094) = 2;
						}
					}
					if (!v10) {
						*(uint32_t*)(a1 + 528) = 0;
						*(uint32_t*)(a1 + 532) = 0;
						if (v15 == 12) {
							nox_xxx_spellBuffOff_4FF5B0(a1, 0);
						}
						v19 = a3;
					LABEL_87:
						v22 = *(uint32_t*)(a1 + 8);
						if (v22 & 4 || v22 & 2 && *(uint8_t*)(a1 + 12) & 0x10) {
							nox_xxx_itemApplyDefendEffect2_4E1320(a1, v10, v19, &a4, v15);
						}
						if (v19) {
							*(uint32_t*)(a1 + 520) = v19;
						} else {
							*(uint32_t*)(a1 + 520) = v10;
						}
						v23 = *(uint8_t*)(a1 + 8);
						*(uint32_t*)(a1 + 524) = v15;
						*(uint32_t*)(a1 + 536) = nox_frame_xxx_2598000;
						if (v23 & 2) {
							v24 = *(uint32_t**)(a1 + 748);
							v25 = v24[360];
							v26 = v24[547];
							BYTE1(v25) |= 2u;
							v24[360] = v25;
							if (!v26) {
								v24[547] = 2;
								v24[546] = v15;
							}
						}
						if (v19 && *(uint32_t*)(v19 + 8) & 0x1001000) {
							nox_xxx_itemApplyPreDamageEffect_4E13B0(a1, v10, v19, (int)&a4);
						}
						if (a1 != v19 || !(*(uint32_t*)(a1 + 8) & 0x1001000)) {
							if (!v10 || !(*(uint8_t*)(v10 + 8) & 2) || !*(uint32_t*)(v10 + 748) ||
								(v27 = nox_xxx_monsterGetSoundSet_424300(v10)) == 0 ||
								(v28 = *(uint32_t*)(v27 + 32)) == 0 || nox_xxx_getSevenDwords3_501940(v28) <= 0) {
								v29 = *(void (**)(int, int))(a1 + 720);
								if (v29) {
									if (v19) {
										v29(a1, v19);
									} else {
										v29(a1, v10);
									}
								} else if (v19) {
									nox_xxx_soundDefaultDamageSound_532E20(a1, v19);
								} else {
									nox_xxx_soundDefaultDamageSound_532E20(a1, v10);
								}
							}
						}
						if (v10 && *(uint8_t*)(a1 + 8) & 6 && nox_xxx_testUnitBuffs_4FF350(v10, 13)) {
							nox_xxx_aud_501960(163, a3, 0, 0);
							v30 = nox_xxx_buffGetPower_4FF570(v10, 13);
							v31 = nox_xxx_gamedataGetFloatTable_419D70("VampirismCoeff", (unsigned int)v30 - 1);
							v44 = v31 * (double)a4;
							v32 = nox_float2int(v44);
							if (v32 < 1u) {
								v32 = 1;
							}
							nox_xxx_unitAdjustHP_4EE460(v10, v32);
							v45[0] = nox_float2int(*(float*)(v10 + 56));
							v33 = nox_float2int(*(float*)(v10 + 60));
							v34 = *(float*)(a1 + 56);
							v45[1] = v33;
							v35 = nox_float2int(v34);
							v36 = *(float*)(a1 + 60);
							v45[2] = v35;
							v45[3] = nox_float2int(v36);
							nox_xxx_netSendVampFx_523270(162, (short*)v45, v32);
						}
						nox_xxx_gameballOnPlayerDamage_4E1230(v10, a1, a4);
						if (*(uint8_t*)(a1 + 8) & 4) {
							if (a4 >= 20) {
								v37 = *(uint8_t*)(*(uint32_t*)(a1 + 748) + 88);
								if (v37 != 1 && v37 != 15) {
									nox_xxx_playerSetState_4FA020((uint32_t*)a1, 30);
								}
							}
						}
						if (nox_common_gameFlags_check_40A5C0(6144)) {
							sub_4FB050(v10, a1, &a4);
						}
						if (!v10) {
							goto LABEL_137;
						}
						if (*(uint8_t*)(v10 + 8) & 2) {
							v38 = v10;
						} else {
							v39 = *(uint32_t*)(v10 + 508);
							if (!v39 || !(*(uint8_t*)(v39 + 8) & 2)) {
							LABEL_137:
								if (nox_xxx_testUnitBuffs_4FF350(a1, 26) && a5 != 5) {
									v40 = a3;
									if (!a3) {
										v40 = v10;
									}
									if (a5 != 15 || v10 != a1) {
										nox_xxx_unitShieldReduceDamage_52F710(a1, &a4, a5, v40);
									}
									if (!a4) {
										return 0;
									}
								}
								nox_xxx_unitDamageClear_4EE5E0(a1, a4);
								return 1;
							}
							v38 = *(uint32_t*)(v10 + 508);
						}
						if (v38 && nox_xxx_unitIsEnemyTo_5330C0(a1, v38)) {
							sub_532880(v38);
						}
						goto LABEL_137;
					}
					v19 = a3;
					if (a3) {
						if (*(uint32_t*)(a3 + 8) & 0x1001000) {
							*(uint32_t*)(a1 + 528) = *(uint32_t*)(v10 + 72);
							*(uint32_t*)(a1 + 532) = *(uint32_t*)(v10 + 76);
						} else {
							*(uint32_t*)(a1 + 528) = *(uint32_t*)(a3 + 72);
							*(uint32_t*)(a1 + 532) = *(uint32_t*)(a3 + 76);
						}
						if (a3 == v10 || !(*(uint8_t*)(a1 + 8) & 2)) {
							goto LABEL_83;
						}
						v20 = *(uint32_t*)(a1 + 748);
						HIWORD(v21) = 0;
						*(uint32_t*)(v20 + 2188) = 1;
						LOWORD(v21) = *(uint16_t*)(a3 + 4);
					} else {
						*(uint32_t*)(a1 + 528) = *(uint32_t*)(v10 + 72);
						*(uint32_t*)(a1 + 532) = *(uint32_t*)(v10 + 76);
						if (v15 != 10 && v15 != 2 || !(*(uint8_t*)(a1 + 8) & 2)) {
							goto LABEL_83;
						}
						v20 = *(uint32_t*)(a1 + 748);
						HIWORD(v21) = 0;
						*(uint32_t*)(v20 + 2188) = 1;
						LOWORD(v21) = *(uint16_t*)(v10 + 4);
					}
					*(uint32_t*)(v20 + 2184) = v21;
				LABEL_83:
					nox_xxx_spellBuffOff_4FF5B0(a1, 0);
					goto LABEL_87;
				}
			} else if (v14 & 0x800) {
				if (a5 == 9) {
					return 1;
				}
				if (a5 == 17) {
					return 1;
				}
			}
		} else {
			v15 = a5;
		}
		if (v15 != 1 && v15 != 12 && v15 != 7) {
			goto LABEL_58;
		}
		goto LABEL_53;
	}
	if (!nox_xxx_unitIsZombie_534A40(a1)) {
		return 1;
	}
	v9 = a3;
	if (!a3) {
		v9 = a2;
	}
	*(uint32_t*)(a1 + 520) = v9;
	*(uint32_t*)(a1 + 524) = v6;
	*(uint32_t*)(a1 + 536) = nox_frame_xxx_2598000;
	return 1;
}

//----- (004E1230) --------------------------------------------------------
void nox_xxx_gameballOnPlayerDamage_4E1230(int a1, int a2, int a3) {
	int v3;   // eax
	int v4;   // esi
	char* v5; // eax

	if (*(uint8_t*)(a2 + 8) & 4 && a3 >= 30) {
		v3 = *getMemU32Ptr(0x5D4594, 1563316);
		if (!*getMemU32Ptr(0x5D4594, 1563316)) {
			v3 = nox_xxx_getNameId_4E3AA0("GameBall");
			*getMemU32Ptr(0x5D4594, 1563316) = v3;
		}
		v4 = *(uint32_t*)(a2 + 516);
		if (v4) {
			while (*(unsigned short*)(v4 + 4) != v3) {
				v4 = *(uint32_t*)(v4 + 512);
				if (!v4) {
					return;
				}
			}
			*(uint32_t*)(v4 + 16) &= 0xFFFFFFBF;
			nox_xxx_objectApplyForce_52DF80(a2 + 56, v4, 30.0);
			nox_xxx_unitClearOwner_4EC300(v4);
			sub_4EB9B0(v4, a2);
			if (nox_xxx_servObjectHasTeam_419130(v4 + 48)) {
				v5 = nox_xxx_clientGetTeamColor_418AB0(*(unsigned char*)(a1 + 52));
				if (v5) {
					sub_4196D0(v4 + 48, (int)v5, *(uint32_t*)(v4 + 36), 0);
				}
			} else {
				nox_xxx_createAtImpl_4191D0(*(uint8_t*)(a1 + 52), v4 + 48, 1, *(uint32_t*)(v4 + 36), 0);
			}
			nox_xxx_aud_501960(926, a2, 0, 0);
		}
	}
}

//----- (004E1320) --------------------------------------------------------
int nox_xxx_itemApplyDefendEffect2_4E1320(int a1, int a2, int a3, int* a4, int a5) {
	int result;   // eax
	uint32_t* v6; // esi
	int v7;       // ebp
	int* v8;      // ebx
	int v9;       // eax
	int2 v10;     // [esp+4h] [ebp-8h]
	int v11;      // [esp+20h] [ebp+14h]

	result = a1;
	v6 = *(uint32_t**)(a1 + 504);
	if (v6) {
		v7 = a5;
		do {
			result = v6[4];
			if (result & 0x100) {
				v11 = 2;
				v8 = (int*)(v6[173] + 8);
				do {
					v9 = *v8;
					if (*v8) {
						if (*(uint32_t*)(v9 + 76)) {
							v10.field_0 = *a4;
							v10.field_4 = v7;
							(*(void (**)(int, uint32_t*, int, int, int, int2*))(v9 + 76))(v9, v6, a1, a3, a2, &v10);
							*a4 = v10.field_0;
						}
					}
					++v8;
					result = --v11;
				} while (v11);
			}
			v6 = (uint32_t*)v6[124];
		} while (v6);
	}
	return result;
}

//----- (004E13B0) --------------------------------------------------------
int nox_xxx_itemApplyPreDamageEffect_4E13B0(int a1, int a2, int a3, int a4) {
	int v4;                              // edi
	int* v5;                             // esi
	int v6;                              // eax
	void (*v7)(int, int, int, int, int); // ecx
	int result;                          // eax
	int v9;                              // [esp+1Ch] [ebp+Ch]

	v4 = a3;
	v9 = 4;
	v5 = *(int**)(v4 + 692);
	do {
		v6 = *v5;
		if (*v5) {
			v7 = *(void (**)(int, int, int, int, int))(v6 + 64);
			if (v7) {
				v7(v6, v4, a2, a1, a4);
			}
		}
		++v5;
		result = --v9;
	} while (v9);
	return result;
}

//----- (004E1400) --------------------------------------------------------
int sub_4E1400(int a1, uint32_t* a2) {
	int v2;     // eax
	int result; // eax
	int v4;     // eax

	if (a2) {
		v4 = a2[2];
		if (v4 & 0x1000) {
			if (!(a2[3] & 0x47F0000)) {
				return 1;
			}
			if (*(uint8_t*)(a2[184] + 96) & 2) {
				return 1;
			}
		} else if (v4 & 0x1000000 && !(a2[3] & 0x47F00FE)) {
			return 1;
		}
		result = ((unsigned char)v4 >> 1) & 1;
	} else {
		v2 = *(uint32_t*)(a1 + 8);
		if (v2 & 4) {
			return 1;
		}
		result = v2 & 2 && *(uint8_t*)(a1 + 12) & 0x10;
	}
	return result;
}

//----- (004E1470) --------------------------------------------------------
int sub_4E1470(int a1) {
	int v1;     // ecx
	int result; // eax

	result = 0;
	if (a1) {
		if (*(uint32_t*)(a1 + 8) & 0x1000000) {
			v1 = *(uint32_t*)(a1 + 12);
			if (v1 & 0x4000) {
				result = 1;
			}
		}
	}
	return result;
}

//----- (004E14A0) --------------------------------------------------------
int sub_4E14A0() { return 0; }

//----- (004E14B0) --------------------------------------------------------
int sub_4E14B0(int a1, int a2, int a3, int a4, int a5) {
	int result; // eax

	if (a1 && *(uint32_t*)(a1 + 8) & 0x1001000 && (*(uint32_t*)(a1 + 492) || a5 == 12)) {
		result = nox_xxx_damageDefaultProc_4E0B30(a1, a2, a3, a4, a5);
	} else {
		result = 0;
	}
	return result;
}

//----- (004E1500) --------------------------------------------------------
int nox_xxx_damageArmor_4E1500(int a1, int a2, int a3, int a4, int a5) {
	int v5;     // eax
	int result; // eax

	if (*(uint32_t*)(a1 + 8) & 0x2000000 && (*(uint32_t*)(a1 + 492) || a5 == 12) &&
		(a5 != 2 || !(*(uint8_t*)(a1 + 24) & 0x10) ? (v5 = a4) : (v5 = 2 * a4), v5)) {
		result = nox_xxx_damageDefaultProc_4E0B30(a1, a2, a3, v5, a5);
	} else {
		result = 0;
	}
	return result;
}

//----- (004E1560) --------------------------------------------------------
void nox_xxx_playerDamageWeapon_4E1560(int a1, int a2, int a3, int a4, float a5, int a6) {
	float* v6;                                   // edi
	int v7;                                      // eax
	void (*v8)(int, int, int, int, int, float*); // ecx
	int v9;                                      // eax
	unsigned short v10;                          // di
	unsigned short v11;                          // ax

	if (a1) {
		if (*(uint32_t*)(a1 + 556)) {
			v6 = *(float**)(a1 + 748);
			if (!(*(uint32_t*)(a1 + 8) & 0x1000000) || !(*(uint32_t*)(a1 + 12) & 0x7800000)) {
				v7 = *(uint32_t*)(*(uint32_t*)(a1 + 692) + 4);
				if (v7) {
					v8 = *(void (**)(int, int, int, int, int, float*))(v7 + 76);
					if (v8) {
						v8(v7, a1, a2, a4, a3, &a5);
					}
				}
				a5 = a5 + *v6;
				v9 = nox_float2int(a5);
				*v6 = a5 - (double)v9;
				if (v9 > 0) {
					v10 = **(uint16_t**)(a1 + 556);
					(*(void (**)(int, int, int, int, int))(a1 + 716))(a1, a3, a4, v9, a6);
					if (a2) {
						if (*(uint8_t*)(a2 + 8) & 4) {
							v11 = **(uint16_t**)(a1 + 556);
							if (v10 != v11) {
								nox_xxx_itemDestroyed_4E1650(
									*(unsigned char*)(*(uint32_t*)(*(uint32_t*)(a2 + 748) + 276) + 2064), (uint32_t*)a1,
									v10, v11);
							}
						}
					}
				}
			}
		}
	}
}

//----- (004E1650) --------------------------------------------------------
int nox_xxx_itemDestroyed_4E1650(int a1, uint32_t* a2, unsigned short a3, unsigned short a4) {
	int result; // eax
	int v5;     // edi

	result = a2[139];
	if (result) {
		if (nox_common_gameFlags_check_40A5C0(2048)) {
			result = nox_xxx_itemReportHealth_4D87A0(a1, a2);
		} else {
			v5 = sub_57B190(a3, *(uint16_t*)(a2[139] + 4));
			result = sub_57B190(a4, *(uint16_t*)(a2[139] + 4));
			if (v5 != result) {
				result = nox_xxx_itemReportHealth_4D87A0(a1, a2);
			}
		}
	}
	return result;
}

//----- (004E16D0) --------------------------------------------------------
void nox_xxx_equipDamage_4E16D0(int a1, int a2, int a3, int a4, float a5, int a6) {
	float* v6;                                   // edi
	int v7;                                      // eax
	void (*v8)(int, int, int, int, int, float*); // ecx
	int v9;                                      // eax
	unsigned short v10;                          // di
	unsigned short v11;                          // ax

	if (a1 && *(uint32_t*)(a1 + 556)) {
		v6 = *(float**)(a1 + 748);
		v7 = *(uint32_t*)(*(uint32_t*)(a1 + 692) + 4);
		if (v7) {
			v8 = *(void (**)(int, int, int, int, int, float*))(v7 + 76);
			if (v8) {
				v8(v7, a1, a2, a4, a3, &a5);
			}
		}
		a5 = a5 + *v6;
		v9 = nox_float2int(a5);
		*v6 = a5 - (double)v9;
		if (v9 > 0) {
			v10 = **(uint16_t**)(a1 + 556);
			(*(void (**)(int, int, int, int, int))(a1 + 716))(a1, a3, a4, v9, a6);
			if (*(uint8_t*)(a2 + 8) & 4) {
				v11 = **(uint16_t**)(a1 + 556);
				if (v10 != v11) {
					nox_xxx_itemDestroyed_4E1650(*(unsigned char*)(*(uint32_t*)(*(uint32_t*)(a2 + 748) + 276) + 2064),
												 (uint32_t*)a1, v10, v11);
				}
			}
		}
	}
}
