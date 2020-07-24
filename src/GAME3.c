#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif

#include "client/draw/animdraw.h"
#include "client/draw/vectdraw.h"
#include "client/drawable/drawable.h"
#include "client/shell/wolapi/locale.h"
#include "common/system/team.h"

#include "client/gui/guiquit.h"
#include "client/shell/arnamain.h"
#include "client/shell/mainmenu.h"
#include "client/shell/noxworld.h"
#include "client/shell/options.h"
#include "client/shell/optsback.h"
#include "client/shell/selchar.h"
#include "client/shell/selclass.h"
#include "client/shell/selcolor.h"

#include "client/draw/drawrays.h"
#include "client/draw/drawwin.h"
#include "client/draw/fx.h"
#include "client/draw/lvupdraw.h"

#include "proto.h"

extern _DWORD dword_5d4594_3798688;
extern _DWORD dword_5d4594_1307792;
extern _DWORD dword_587000_172876;
extern _DWORD dword_587000_172872;
extern _DWORD dword_5d4594_1313788;
extern _DWORD dword_5d4594_1308136;
extern _DWORD dword_587000_172880;
extern _DWORD dword_5d4594_1308104;
extern _DWORD dword_5d4594_1313532;
extern _DWORD dword_5d4594_3798672;
extern _DWORD dword_5d4594_1313564;
extern _DWORD dword_5d4594_1308096;
extern _DWORD dword_5d4594_1311924;
extern _DWORD dword_5d4594_805872;
extern _DWORD dword_5d4594_1307724;
extern _DWORD dword_5d4594_3798684;
extern _DWORD dword_5d4594_3798680;
extern _DWORD dword_5d4594_3798676;
extern _DWORD dword_5d4594_1308112;
extern _DWORD nox_server_sendMotd_108752;
extern _DWORD dword_5d4594_1309772;
extern _DWORD dword_5d4594_1308148;
extern _DWORD dword_5d4594_3798708;
extern _DWORD dword_587000_171388;
extern _DWORD dword_5d4594_1308140;
extern _DWORD dword_5d4594_1309704;
extern _DWORD dword_5d4594_1308144;
extern _DWORD dword_5d4594_1309696;
extern _DWORD dword_5d4594_1311936;
extern _DWORD dword_5d4594_1308152;
extern _DWORD dword_5d4594_1313536;
extern _DWORD dword_5d4594_1308116;
extern _DWORD dword_5d4594_1313740;
extern _DWORD dword_5d4594_1308100;
extern _DWORD dword_5d4594_1308132;
extern _DWORD dword_5d4594_3798644;
extern _DWORD dword_5d4594_1308108;
extern _DWORD dword_5d4594_1308120;
extern _DWORD dword_5d4594_1308156;
extern _DWORD dword_5d4594_1309764;
extern _DWORD dword_5d4594_1308128;
extern _DWORD dword_5d4594_1308124;
extern _DWORD dword_5d4594_1309768;
extern _DWORD dword_5d4594_1309736;
extern _DWORD dword_5d4594_1309756;
extern _DWORD dword_5d4594_1309832;
extern _DWORD dword_5d4594_1313540;
extern _DWORD dword_5d4594_1307732;
extern _DWORD dword_5d4594_1307292;
extern _DWORD dword_5d4594_1308160;
extern _DWORD dword_5d4594_1309824;
extern _DWORD dword_5d4594_1308092;
extern _DWORD dword_5d4594_1307720;
extern _DWORD dword_5d4594_1308164;
extern _DWORD dword_587000_173336;
extern _DWORD dword_587000_173328;
extern _DWORD dword_5d4594_1309784;
extern _DWORD dword_5d4594_1312476;
extern _DWORD dword_5d4594_1307748;
extern _DWORD dword_5d4594_1307736;
extern _DWORD dword_5d4594_3798648;
extern _DWORD dword_5d4594_1309776;
extern _DWORD dword_5d4594_1309708;
extern _DWORD nox_client_renderGlow_805852;
extern _DWORD dword_5d4594_3798716;
extern _DWORD dword_587000_173332;
extern _DWORD dword_5d4594_1312472;
extern _DWORD dword_5d4594_1309740;
extern _DWORD dword_5d4594_3596;
extern _DWORD dword_5d4594_1309716;
extern _DWORD dword_5d4594_1309780;
extern _DWORD dword_5d4594_1307768;
extern _DWORD dword_5d4594_1313792;
extern _DWORD dword_5d4594_1307744;
extern _DWORD dword_587000_122852;
extern _DWORD dword_5d4594_1307308;
extern _DWORD dword_5d4594_1309828;
extern _DWORD dword_5d4594_1309836;
extern _DWORD dword_5d4594_1312460;
extern _DWORD dword_5d4594_1309728;
extern _DWORD dword_5d4594_1309732;
extern _QWORD qword_581450_9552;
extern _DWORD dword_587000_93164;
extern _DWORD dword_5d4594_1311140;
extern _DWORD dword_5d4594_3798720;
extern _DWORD dword_5d4594_1307716;
extern _DWORD dword_5d4594_1312484;
extern _DWORD dword_587000_127004;
extern _DWORD dword_5d4594_1308088;
extern _DWORD dword_5d4594_1312480;
extern _DWORD dword_5d4594_3799492;
extern _DWORD dword_5d4594_2618912;
extern _DWORD dword_5d4594_3798640;
extern _DWORD dword_5d4594_1307776;
extern _DWORD dword_5d4594_3798632;
extern _DWORD dword_5d4594_1309748;
extern _DWORD dword_5d4594_1311148;
extern _DWORD dword_5d4594_1313796;
extern _DWORD dword_5d4594_1313800;
extern _DWORD dword_5d4594_1309720;
extern _DWORD dword_5d4594_1311144;
extern _DWORD dword_5d4594_3798636;
extern _DWORD dword_5d4594_1307764;
extern _DWORD dword_5d4594_3798696;
extern _DWORD dword_5d4594_815132;
extern _DWORD dword_5d4594_1307780;
extern _DWORD dword_5d4594_1308084;
extern _DWORD dword_5d4594_1309812;
extern _DWORD dword_5d4594_1309820;
extern _DWORD dword_5d4594_3799624;
extern _DWORD dword_5d4594_3801780;
extern _DWORD dword_5d4594_810632;
extern _DWORD dword_5d4594_2650652;
extern _DWORD dword_5d4594_1307784;
extern _DWORD dword_5d4594_3804672;
extern _DWORD dword_5d4594_3804656;
extern _DWORD dword_5d4594_3804664;
extern BYTE** nox_pixbuffer_rows_3798784;
extern int g_fullscreen;
extern float draw_gamma;
extern float input_sensitivity;
extern int nox_win_width;
extern int nox_win_height;
extern int nox_backbuffer_height;
extern int nox_win_depth_1;
extern int nox_win_depth_2;
extern char nox_savegame_name_1307752[9];

extern obj_5D4594_3799572_t* ptr_5D4594_3799572;

FILE* nox_file_9 = 0;

nox_window* nox_win_main_menu = 0;
nox_window* nox_win_main_bg = 0;

//----- (004A19D0) --------------------------------------------------------
int sub_4A19D0() {
	int result; // eax

	result = sub_43DDD0(0);
	dword_5d4594_815132 = 0;
	return result;
}

//----- (004A1A40) --------------------------------------------------------
int __cdecl sub_4A1A40(int a1) {
	_DWORD* v1; // eax

	v1 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1307292, 151);
	return sub_46ABB0((int)v1, a1);
}

//----- (004A1A60) --------------------------------------------------------
int sub_4A1A60() {
	_DWORD* v0; // eax

	v0 = nox_new_window_from_file("OptsBack.wnd", sub_4A1AA0);
	dword_5d4594_1307292 = v0;
	if (!v0)
		return 0;
	sub_46B300((int)v0, sub_4A18E0);
	return 1;
}
// 4A18E0: using guessed type int __cdecl sub_4A18E0(int, int, int, int);

//----- (004A1BD0) --------------------------------------------------------
int sub_4A1BD0() { return sub_46C4E0(*(_DWORD**)&dword_5d4594_1307292); }

//----- (004A1BE0) --------------------------------------------------------
int __cdecl sub_4A1BE0(int a1) { return sub_46ABB0(*(int*)&dword_5d4594_1307292, a1); }

//----- (004A1C00) --------------------------------------------------------
int sub_4A1C00() {
	int result; // eax
	_DWORD* v1; // esi
	_DWORD* v2; // esi
	_DWORD* v3; // eax

	sub_4D6F40(0);
	sub_4D6F90(0);
	sub_43BDD0(100);
	result = nox_new_window_from_file("MainMenu.wnd", sub_4A1DC0);
	nox_win_main_menu = result;
	if (result) {
		sub_46B300(result, sub_4A18E0);
		v1 = sub_46B0C0(nox_win_main_menu, 110);
		sub_46B2C0((int)v1, sub_4A1DC0);
		result = nox_wnd_sub_43C5B0(v1, 0, 0, 0, -270, 0, 20, 0, -40);
		dword_5d4594_1307308 = result;
		if (result) {
			*(_DWORD*)result = 100;
			*(_DWORD*)(dword_5d4594_1307308 + 48) = sub_4A1D40;
			*(_DWORD*)(dword_5d4594_1307308 + 56) = sub_4A1D80;
			v2 = sub_46B0C0(nox_win_main_menu, 120);
			sub_46B2C0((int)v2, sub_4A1DC0);
			result = nox_wnd_sub_43C5B0(v2, 0, 270, 0, 510, 0, -20, 0, 40);
			*(_DWORD*)&byte_5D4594[1307304] = result;
			if (result) {
				sub_4A19F0((char*)&byte_587000[169196]);
				sub_4D1650();
				sub_578CD0();
				sub_43D9B0(25, 100);
				if (nox_common_gameFlags_check_40A5C0(0x2000000)) {
					v3 = sub_46B0C0(nox_win_main_menu, 112);
					nox_window_call_field_94(nox_win_main_menu, 16391, (int)v3, 0);
				}
				result = 1;
			}
		}
	}
	return result;
}
// 4A18E0: using guessed type int __cdecl sub_4A18E0(int, int, int, int);

//----- (004A1D40) --------------------------------------------------------
int sub_4A1D40() {
	*(_BYTE*)(dword_5d4594_1307308 + 64) = 2;
	*(_BYTE*)(*(_DWORD*)&byte_5D4594[1307304] + 64) = 2;
	sub_43BE40(2);
	sub_452D80(923, 100);
	return 1;
}

//----- (004A1D80) --------------------------------------------------------
int sub_4A1D80() {
	int (*v0)(void); // esi

	v0 = *(int (**)(void))(dword_5d4594_1307308 + 52);
	sub_43C570(*(LPVOID*)&dword_5d4594_1307308);
	sub_43C570(*(LPVOID*)&byte_5D4594[1307304]);
	sub_46C4E0(nox_win_main_menu);
	v0();
	return 1;
}

// 4A203B: variable 'v6' is possibly undefined

//----- (004A2200) --------------------------------------------------------
int sub_4A2200() { return sub_4B0340(0); }

//----- (004A2210) --------------------------------------------------------
int sub_4A2210() {
	int result;          // eax
	_DWORD* v1;          // esi
	const char* v2;      // eax
	unsigned __int8* v3; // esi

	dword_5d4594_815132 = 1;
	nox_win_main_bg = nox_new_window_from_file("MainBG.wnd", sub_4A2490);
	result = sub_4A1A60();
	if (result) {
		v1 = sub_46B0C0(nox_win_main_bg, 98);
		sub_46B300((int)v1, sub_4A18E0);
		sub_46B340((int)v1, sub_4A22A0);
		v2 = *(const char**)&byte_587000[168832];
		if (*(_DWORD*)&byte_587000[168832]) {
			v3 = &byte_587000[168832];
			do {
				*((_DWORD*)v3 + 1) = sub_42F970(v2);
				v2 = (const char*)*((_DWORD*)v3 + 12);
				v3 += 48;
			} while (v2);
		}
		sub_46B500(nox_win_main_bg);
		result = 1;
	}
	return result;
}
// 4A18E0: using guessed type int __cdecl sub_4A18E0(int, int, int, int);

//----- (004A2490) --------------------------------------------------------
BOOL __cdecl sub_4A2490(int a1, int a2, int a3, int a4) { return a2 == 23; }

//----- (004A24A0) --------------------------------------------------------
int sub_4A24A0() {
	sub_4A1BD0();
	sub_46C5D0();
	dword_5d4594_815132 = 0;
	return 1;
}

//----- (004A24C0) --------------------------------------------------------
int __cdecl sub_4A24C0(int a1) {
	_DWORD* v1; // eax
	int result; // eax

	v1 = sub_46B0C0(nox_win_main_bg, 99);
	result = nox_window_set_hidden((int)v1, a1);
	if (!a1)
		result = sub_43E8C0(1);
	return result;
}

//----- (004A24F0) --------------------------------------------------------
int sub_4A24F0() { return sub_46B500(nox_win_main_bg); }

//----- (004A2500) --------------------------------------------------------
int sub_4A2500() {
	sub_43DDE0(1);
	nox_window_set_hidden(nox_win_main_bg, 0);
	nox_window_set_hidden(nox_win_main_menu, 0);
	return sub_4A24F0();
}

//----- (004A2530) --------------------------------------------------------
int sub_4A2530() {
	sub_43DDE0(0);
	nox_window_set_hidden(nox_win_main_bg, 1);
	return nox_window_set_hidden(nox_win_main_menu, 1);
}

//----- (004A2560) --------------------------------------------------------
BOOL __cdecl sub_4A2560(_DWORD* a1, int a2) {
	double v2; // st7
	double v3; // st6

	v2 = (double)(*(__int16*)(a2 + 44) - *a1);
	v3 = (double)(*(__int16*)(a2 + 46) - a1[1]);
	return sqrt(v3 * v3 + v2 * v2) <= *(double*)&byte_581450[9720];
}

//----- (004A25C0) --------------------------------------------------------
int __cdecl sub_4A25C0(_DWORD* a1, int* a2) {
	int v2;  // edi
	int* v3; // esi

	v2 = 0;
	v3 = sub_425890(a2);
	if (!v3)
		return 0;
	do {
		if (sub_4A2560(a1, (int)v3))
			++v2;
		v3 = sub_4258A0(v3);
	} while (v3);
	return v2;
}

//----- (004A2610) --------------------------------------------------------
int __cdecl sub_4A2610(int a1, _DWORD* a2, int* a3) {
	int* i;               // esi
	int v4;               // eax
	_DWORD* v5;           // esi
	_DWORD* v6;           // ebx
	_DWORD* v7;           // edi
	_DWORD* v8;           // ebp
	char* v9;             // eax
	int v10;              // ebx
	unsigned __int8* v11; // esi
	_DWORD* v13;          // [esp+Ch] [ebp-150h]
	char* v14;            // [esp+10h] [ebp-14Ch]
	int v15[2];           // [esp+14h] [ebp-148h]
	char v16[64];         // [esp+1Ch] [ebp-140h]
	wchar_t v17[128];     // [esp+5Ch] [ebp-100h]

	dword_5d4594_1307720 = 0;
	for (i = sub_425890(a3); i; i = sub_4258A0(i)) {
		if (sub_4A2560(a2, (int)i)) {
			v4 = dword_5d4594_1307720;
			*(_DWORD*)&byte_5D4594[4 * dword_5d4594_1307720 + 1307316] = i;
			dword_5d4594_1307720 = v4 + 1;
		}
	}
	if (dword_5d4594_1307720 > 0) {
		dword_5d4594_1307716 = nox_new_window_from_file("proxlist.wnd", *(_DWORD*)(a1 + 376));
		sub_4A2830(*a2 + 216, a2[1] + 27, v15);
		nox_wnd_sub_46A9B0(*(_DWORD**)&dword_5d4594_1307716, v15[0], v15[1]);
		sub_46B280(*(int*)&dword_5d4594_1307716, a1);
		v5 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1307716, 10064);
		v6 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1307716, 10062);
		v13 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1307716, 10063);
		v7 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1307716, 10061);
		v8 = (_DWORD*)v7[8];
		v14 = sub_42F970("UISlider");
		v9 = sub_42F970("UISliderLit");
		sub_4B5700((int)v5, 0, 0, (int)v14, (int)v9, (int)v9);
		sub_46B280((int)v5, (int)v7);
		sub_46B280((int)v6, (int)v7);
		sub_46B280((int)v13, (int)v7);
		v8[9] = v5;
		v8[7] = v6;
		v8[8] = v13;
		*(_DWORD*)(v5[100] + 8) = 16;
		*(_DWORD*)(v5[100] + 12) = 10;
		v10 = 0;
		if (dword_5d4594_1307720 > 0) {
			v11 = &byte_5D4594[1307316];
			do {
				if (*(_BYTE*)(*(_DWORD*)v11 + 120)) {
					strncpy(v16, (const char*)(*(_DWORD*)v11 + 120), 0xFu);
					v16[15] = 0;
				} else {
					sub_43BC80(*(_DWORD*)v11 + 12, *(_WORD*)(*(_DWORD*)v11 + 109), v16);
				}
				nox_swprintf(v17, L"%S   %dms", v16, *(_DWORD*)(*(_DWORD*)v11 + 96));
				nox_window_call_field_94((int)v7, 16397, (int)v17, -1);
				++v10;
				v11 += 4;
			} while (v10 < *(int*)&dword_5d4594_1307720);
		}
	}
	return dword_5d4594_1307716;
}

//----- (004A2830) --------------------------------------------------------
_DWORD* __cdecl sub_4A2830(int a1, int a2, _DWORD* a3) {
	_DWORD* result; // eax

	result = a3;
	*a3 = a1 - 100;
	a3[1] = a2 - 20;
	if (a1 - 100 + 200 > 600)
		*a3 = 400;
	if (a2 - 20 + 200 > 451)
		a3[1] = 251;
	if (a3[1] < 27)
		a3[1] = 27;
	if ((int)*a3 < 216)
		*a3 = 216;
	return result;
}

//----- (004A2890) --------------------------------------------------------
int sub_4A2890() {
	int result; // eax

	result = dword_5d4594_1307716;
	if (dword_5d4594_1307716) {
		result = sub_46C4E0(*(_DWORD**)&dword_5d4594_1307716);
		dword_5d4594_1307716 = 0;
	}
	return result;
}

//----- (004A28B0) --------------------------------------------------------
BOOL sub_4A28B0() { return dword_5d4594_1307716 != 0; }

//----- (004A28C0) --------------------------------------------------------
int __cdecl sub_4A28C0(int a1) {
	int result; // eax

	if (a1 < *(int*)&dword_5d4594_1307720)
		result = *(_DWORD*)&byte_5D4594[4 * a1 + 1307316];
	else
		result = 0;
	return result;
}

//----- (004A28E0) --------------------------------------------------------
int __cdecl sub_4A28E0(_DWORD* a1, int a2, unsigned int a3, int a4) {
	_DWORD* v4;       // edi
	int v5;           // esi
	int result;       // eax
	int v7;           // eax
	int v8;           // eax
	int v9;           // eax
	int v10;          // edx
	int v11;          // eax
	unsigned int v12; // ebx
	unsigned int v13; // ebx
	int v14;          // eax
	int v15;          // ecx
	int v16;          // eax
	unsigned int v17; // eax
	unsigned int v18; // ebx
	int v19;          // eax
	int v20;          // ecx
	int v21;          // eax
	int v22;          // eax

	v4 = a1;
	v5 = a1[8];
	switch (a2) {
	case 5:
	case 17:
	case 18:
		return 1;
	case 6:
	case 7:
		v12 = a3;
		a3 = *(_DWORD*)(v5 + 48);
		v13 = v12 >> 16;
		nox_client_wndGetPosition_46AA60(a1, &a1, &a4);
		if (*((_WORD*)v4 + 54)) {
			v14 = sub_43F320(v4[59]);
			a4 += v14 + 1;
		}
		v15 = 0;
		*(_DWORD*)(v5 + 48) = -2;
		v16 = 0;
		while (2) {
			if (v16 > 0 && *(int*)(v16 + *(_DWORD*)(v5 + 24) - 524) > *(__int16*)(v5 + 52) + *(__int16*)(v5 + 54) ||
				v15 == *(__int16*)(v5 + 44)) {
				*(_DWORD*)(v5 + 48) = -1;
			} else if (*(int*)(v16 + *(_DWORD*)(v5 + 24)) <= (int)(v13 + *(__int16*)(v5 + 54) - a4)) {
				++v15;
				v16 += 524;
				continue;
			}
			break;
		}
		v17 = a3;
		if (v15 == a3 && !*(_DWORD*)(v5 + 20))
			*(_DWORD*)(v5 + 48) = -1;
		if (*(int*)(v5 + 48) == -2 && v15 < *(__int16*)(v5 + 44))
			*(_DWORD*)(v5 + 48) = v15;
		if (*(int*)(v5 + 48) < 0) {
			if (*(_DWORD*)(v5 + 20))
				*(_DWORD*)(v5 + 48) = v17;
		}
		nox_window_call_field_94(v4[13], 16400, (int)v4, *(_DWORD*)(v5 + 48));
		return 1;
	case 8:
		v22 = a1[11];
		if (v22 & 0x100)
			nox_window_call_field_94(a1[13], 0x4000, (int)a1, 0);
		return 1;
	case 10:
	case 11:
		v18 = a3 >> 16;
		nox_client_wndGetPosition_46AA60(a1, &a3, &a4);
		if (*((_WORD*)v4 + 54)) {
			v19 = sub_43F320(v4[59]);
			a4 += v19 + 1;
		}
		v20 = 0;
		v21 = 0;
		break;
	case 19:
	LABEL_9:
		v8 = *(_DWORD*)(v5 + 48);
		if (v8 == -1) {
			*(_DWORD*)(v5 + 48) = 0;
			sub_4A2D10((int)v4, 0, 1);
		} else if (v8 > 0) {
			v11 = v8 - 1;
			*(_DWORD*)(v5 + 48) = v11;
			if (*(_DWORD*)(*(_DWORD*)(v5 + 24) + 524 * v11) < *(__int16*)(v5 + 54))
				sub_4A2D10((int)v4, -1, 1);
		}
		goto LABEL_21;
	case 20:
	LABEL_6:
		v7 = *(_DWORD*)(v5 + 48);
		if (v7 == -1) {
			*(_DWORD*)(v5 + 48) = 0;
			sub_4A2D10((int)v4, 0, 1);
		} else if (v7 < *(__int16*)(v5 + 44) - 1) {
			v9 = v7 + 1;
			v10 = *(__int16*)(v5 + 52) + *(__int16*)(v5 + 54);
			*(_DWORD*)(v5 + 48) = v9;
			if (*(_DWORD*)(*(_DWORD*)(v5 + 24) + 524 * v9) > v10)
				sub_4A2D10((int)v4, 1, 1);
		}
	LABEL_21:
		nox_window_call_field_94(v4[13], 16400, (int)v4, *(_DWORD*)(v5 + 48));
		return 1;
	case 21:
		switch (a3) {
		case 0xFu:
		case 0xCDu:
			if (a4 != 2)
				return 1;
			sub_46A8A0();
			result = 1;
			break;
		case 0x1Cu:
		case 0x39u:
			if (a4 != 1)
				return 1;
			nox_window_call_field_94(a1[13], 16400, (int)a1, *(_DWORD*)(v5 + 48));
			result = 1;
			break;
		case 0xC8u:
			if (a4 == 2)
				goto LABEL_9;
			return 1;
		case 0xCBu:
			if (a4 != 2)
				return 1;
			sub_46A8B0();
			result = 1;
			break;
		case 0xD0u:
			if (a4 == 2)
				goto LABEL_6;
			return 1;
		default:
			return 0;
		}
		return result;
	default:
		return 0;
	}
	while ((v21 <= 0 || *(_DWORD*)(v21 + *(_DWORD*)(v5 + 24) - 524) <= *(__int16*)(v5 + 52) + *(__int16*)(v5 + 54)) &&
		   v20 != *(__int16*)(v5 + 44)) {
		if (*(_DWORD*)(v21 + *(_DWORD*)(v5 + 24)) > (int)(v18 + *(__int16*)(v5 + 54) - a4))
			goto LABEL_50;
		++v20;
		v21 += 524;
	}
	v20 = -1;
LABEL_50:
	nox_window_call_field_94(v4[13], 16401, (int)v4, v20);
	return 1;
}

//----- (004A2D10) --------------------------------------------------------
int __cdecl sub_4A2D10(int a1, int a2, int a3) {
	int v3;     // esi
	int v4;     // eax
	int v5;     // ecx
	int result; // eax
	int v7;     // ecx

	v3 = *(_DWORD*)(a1 + 32);
	v4 = a2 + sub_4A4800(*(_DWORD*)(a1 + 32));
	if (v4 >= 0) {
		v5 = *(__int16*)(v3 + 44);
		if (v4 >= v5)
			v4 = v5 - 1;
	} else {
		v4 = 0;
	}
	if (a3) {
		if (v4 <= 0)
			*(_WORD*)(v3 + 54) = 0;
		else
			*(_WORD*)(v3 + 54) = *(_WORD*)(*(_DWORD*)(v3 + 24) + 524 * v4 - 524) + 1;
	}
	result = *(_DWORD*)(v3 + 36);
	if (result) {
		result = *(_DWORD*)(result + 32);
		v7 = *(_DWORD*)(v3 + 40) - *(__int16*)(v3 + 52) + 3;
		*(_DWORD*)(result + 4) = v7;
		if (v7 < 0)
			*(_DWORD*)(result + 4) = 0;
		*(float*)(result + 8) = (double)(int)(*(_DWORD*)(*(_DWORD*)(v3 + 36) + 12) -
											  *(_DWORD*)(*(_DWORD*)(*(_DWORD*)(v3 + 36) + 400) + 12)) /
								(double)*(int*)(result + 4);
		if (a3)
			result =
				nox_window_call_field_94(*(_DWORD*)(v3 + 36), 16394, *(_DWORD*)(result + 4) - *(__int16*)(v3 + 54), 0);
	}
	return result;
}

//----- (004A2DE0) --------------------------------------------------------
int __cdecl sub_4A2DE0(int a1, int a2, unsigned int a3, int a4) {
	int v4;           // ebp
	int v5;           // esi
	int result;       // eax
	unsigned int v7;  // edi
	int v8;           // eax
	unsigned int v9;  // ecx
	int v10;          // ebx
	int v11;          // eax
	int* v12;         // edi
	int v13;          // ecx
	int v14;          // eax
	int v15;          // edx
	unsigned int v16; // edi
	int v17;          // eax
	unsigned int v18; // edx
	int v19;          // ecx
	int v20;          // eax
	int v21;          // eax

	v4 = a1;
	v5 = *(_DWORD*)(a1 + 32);
	switch (a2) {
	case 5:
	case 17:
	case 18:
		return 1;
	case 6:
	case 7:
		v7 = a3 >> 16;
		nox_client_wndGetPosition_46AA60((_DWORD*)a1, &a2, &a3);
		if (*(_WORD*)(a1 + 108)) {
			v8 = sub_43F320(*(_DWORD*)(a1 + 236));
			v9 = a3 + v8 + 1;
			a3 += v8 + 1;
		} else {
			v9 = a3;
		}
		v10 = 0;
		v11 = 0;
		while (2) {
			if (v11 <= 0)
				goto LABEL_12;
			if (*(_DWORD*)(v11 + *(_DWORD*)(v5 + 24) - 524) > *(__int16*)(v5 + 52) + *(__int16*)(v5 + 54)) {
				v10 = -1;
			LABEL_16:
				v4 = a1;
				goto LABEL_17;
			}
			v4 = a1;
		LABEL_12:
			if (v10 != *(__int16*)(v5 + 44)) {
				if (*(_DWORD*)(v11 + *(_DWORD*)(v5 + 24)) <= (int)(v7 + *(__int16*)(v5 + 54) - v9)) {
					v4 = a1;
					++v10;
					v11 += 524;
					continue;
				}
				goto LABEL_16;
			}
			break;
		}
		v10 = -1;
	LABEL_17:
		v12 = *(int**)(v5 + 48);
		v13 = 0;
		v14 = *v12;
		if ((int)*v12 < 0) {
		LABEL_24:
			v12[v13] = v10;
			*(_DWORD*)(*(_DWORD*)(v5 + 48) + 4 * v13 + 4) = -1;
			nox_window_call_field_94(*(_DWORD*)(v4 + 52), 16400, v4, v10);
			result = 1;
		} else {
			v15 = *(_DWORD*)(v5 + 48);
			while (v14 != v10) {
				v14 = *(_DWORD*)(v15 + 4);
				v15 += 4;
				++v13;
				if (v14 < 0)
					goto LABEL_24;
			}
			sub_4A3090((__int16*)v5, v13);
			nox_window_call_field_94(*(_DWORD*)(v4 + 52), 16400, v4, v10);
			result = 1;
		}
		return result;
	case 8:
		v21 = *(_DWORD*)(a1 + 44);
		if (v21 & 0x100)
			nox_window_call_field_94(*(_DWORD*)(a1 + 52), 0x4000, a1, 0);
		return 1;
	case 10:
	case 11:
		v16 = a3 >> 16;
		nox_client_wndGetPosition_46AA60((_DWORD*)a1, &a2, &a3);
		if (*(_WORD*)(a1 + 108)) {
			v17 = sub_43F320(*(_DWORD*)(a1 + 236));
			v18 = a3 + v17 + 1;
			a3 += v17 + 1;
		} else {
			v18 = a3;
		}
		v19 = 0;
		v20 = 0;
		while (2) {
			if (v20 <= 0)
				goto LABEL_32;
			if (*(_DWORD*)(v20 + *(_DWORD*)(v5 + 24) - 524) > *(__int16*)(v5 + 52) + *(__int16*)(v5 + 54)) {
				v19 = -1;
			LABEL_36:
				nox_window_call_field_94(*(_DWORD*)(a1 + 52), 16401, a1, v19);
				return 1;
			}
			v4 = a1;
		LABEL_32:
			if (v19 != *(__int16*)(v5 + 44)) {
				if (*(_DWORD*)(v20 + *(_DWORD*)(v5 + 24)) <= (int)(v16 + *(__int16*)(v5 + 54) - v18)) {
					v4 = a1;
					++v19;
					v20 += 524;
					continue;
				}
				goto LABEL_36;
			}
			break;
		}
		nox_window_call_field_94(*(_DWORD*)(v4 + 52), 16401, v4, -1);
		return 1;
	case 19:
		if (!*(_DWORD*)(v5 + 28) || *(short*)(v5 + 54) <= 0)
			return 1;
		sub_4A2D10(a1, -1, 1);
		return 1;
	case 20:
		if (!*(_DWORD*)(v5 + 32) || *(__int16*)(v5 + 52) + *(__int16*)(v5 + 54) > *(int*)(v5 + 40))
			return 1;
		sub_4A2D10(a1, 1, 1);
		return 1;
	case 21:
		if (a3 != 15)
			return 0;
		if (a4 != 2)
			return 1;
		sub_46A8A0();
		return 1;
	default:
		return 0;
	}
}

//----- (004A3090) --------------------------------------------------------
__int16* __cdecl sub_4A3090(__int16* a1, int a2) {
	__int16* result; // eax

	result = a1;
	qmemcpy((void*)(*((_DWORD*)a1 + 12) + 4 * a2), (const void*)(*((_DWORD*)a1 + 12) + 4 * a2 + 4), 4 * (*a1 - a2));
	*(_DWORD*)(*((_DWORD*)a1 + 12) + 4 * *a1 - 4) = -1;
	return result;
}

//----- (004A30D0) --------------------------------------------------------
int __cdecl sub_4A30D0(int a1, unsigned int a2, wchar_t* a3, int a4) {
	_DWORD* v4;    // ebp
	__int16* v5;   // ebx
	int v6;        // eax
	int v7;        // eax
	int result;    // eax
	_DWORD* v9;    // eax
	_DWORD* v10;   // eax
	_DWORD* v11;   // eax
	int v12;       // eax
	__int16 v13;   // ax
	_DWORD* v14;   // eax
	int v15;       // esi
	wchar_t* v16;  // ecx
	wchar_t* v17;  // eax
	__int16 v18;   // cx
	__int16 v19;   // ax
	int v20;       // eax
	int v21;       // edx
	int v22;       // esi
	int v23;       // eax
	int v24;       // edx
	int v25;       // esi
	_DWORD* v26;   // eax
	int v27;       // ecx
	int v28;       // edx
	__int16 v29;   // cx
	__int16 v30;   // ax
	int v31;       // esi
	__int16 v32;   // ax
	wchar_t** v33; // esi
	int v34;       // edx
	wchar_t* v35;  // eax
	int v36;       // ecx
	int v37;       // esi
	int v38;       // ecx
	__int16 v39;   // di
	int v40;       // eax
	_DWORD* v41;   // eax
	int v42;       // esi
	int v43;       // ecx
	int v44;       // eax
	__int16 v45;   // ax
	int v46;       // edx

	v4 = (_DWORD*)a1;
	v5 = *(__int16**)(a1 + 32);
	if (a2 > 0x4012) {
		switch (a2) {
		case 0x4013u:
			if ((int)a3 < 0) {
				if (*((_DWORD*)v5 + 4))
					goto LABEL_117;
				*((_DWORD*)v5 + 12) = -1;
				return 0;
			}
			v37 = *((_DWORD*)v5 + 6) + 524 * (_DWORD)a3;
			if (!*(_WORD*)(v37 + 4))
				return 0;
			if (*((_DWORD*)v5 + 4)) {
				**((_DWORD**)v5 + 12) = a3;
				*(_DWORD*)(*((_DWORD*)v5 + 12) + 4) = -1;
				return 0;
			}
			v38 = v5[27];
			*((_DWORD*)v5 + 12) = a3;
			if (*(_DWORD*)v37 < v38) {
				nox_window_call_field_94(a1, 16412, (int)a3, 0);
				return 0;
			}
			v39 = v5[26];
			if (*(_DWORD*)v37 > v38 + v39) {
				if ((int)a3 <= 0)
					v5[27] = 0;
				else
					v5[27] = *(_WORD*)v37 - v39;
				sub_4A2D10(a1, 0, 1);
				return 0;
			}
			return 0;
		case 0x4014u:
			return *((_DWORD*)v5 + 12);
		case 0x4015u:
			if ((int)a3 >= 0) {
				if (!*(_WORD*)(*((_DWORD*)v5 + 6) + 524 * (_DWORD)a3 + 4) || !*((_DWORD*)v5 + 4))
					return 0;
				v33 = (wchar_t**)*((_DWORD*)v5 + 12);
				v34 = 0;
				v35 = *v33;
				if ((int)*v33 < 0) {
				LABEL_113:
					v33[v34] = a3;
					*(_DWORD*)(*((_DWORD*)v5 + 12) + 4 * v34 + 4) = -1;
					return 0;
				}
				v36 = *((_DWORD*)v5 + 12);
				while (v35 != a3) {
					v35 = *(wchar_t**)(v36 + 4);
					v36 += 4;
					++v34;
					if ((int)v35 < 0)
						goto LABEL_113;
				}
				sub_4A3090(v5, v34);
				result = 0;
			} else {
				if (!*((_DWORD*)v5 + 4))
					return 0;
			LABEL_117:
				memset(*((void**)v5 + 12), 0xFFu, 4 * *v5);
				result = 0;
			}
			break;
		case 0x4016u:
			return *((_DWORD*)v5 + 6) + 524 * (_DWORD)a3 + 4;
		case 0x4017u:
			nox_wcsncpy((wchar_t*)(*((_DWORD*)v5 + 6) + 524 * a4 + 4), a3, 0xFFu);
			*(_WORD*)(*((_DWORD*)v5 + 6) + 2 * (nox_wcslen(a3) + 262 * a4) + 4) = 0;
			return 0;
		case 0x4018u:
			*((_DWORD*)v5 + 7) = a3;
			return 0;
		case 0x4019u:
			*((_DWORD*)v5 + 8) = a3;
			return 0;
		case 0x401Au:
			*((_DWORD*)v5 + 9) = a3;
			return 0;
		case 0x401Bu:
			v40 = v5[22];
			if (v40 < (int)a3)
				return 0;
			memmove(*((void**)v5 + 6), (const void*)(*((_DWORD*)v5 + 6) + 524 * (_DWORD)a3),
					4 * ((unsigned int)(524 * (v40 - (_DWORD)a3)) >> 2));
			v5[22] -= (__int16)a3;
			v5[23] = v5[22];
			if (*((_DWORD*)v5 + 4)) {
				v41 = (_DWORD*)*((_DWORD*)v5 + 12);
				v42 = 0;
				if ((int)*v41 >= 0) {
					do {
						v43 = v41[v42];
						if ((int)a3 < v43)
							sub_4A3090(v5, v42--);
						else
							v41[v42] = v43 - (_DWORD)a3;
						v41 = (_DWORD*)*((_DWORD*)v5 + 12);
						++v42;
					} while ((int)v41[v42] >= 0);
				}
			} else {
				v44 = *((_DWORD*)v5 + 12);
				if (v44 > 0)
					*((_DWORD*)v5 + 12) = v44 - (_DWORD)a3;
			}
			if (v5[27] > 0)
				sub_4A2D10(a1, -(int)a3, 1);
			sub_4A3A70(a1);
			return 1;
		case 0x401Cu:
			if (a3)
				v5[27] = *(_WORD*)(*((_DWORD*)v5 + 6) + 524 * (_DWORD)a3 - 524) + 1;
			else
				v5[27] = 0;
			v45 = v5[26];
			v46 = *((_DWORD*)v5 + 10);
			if (v5[27] + v45 >= v46)
				v5[27] = v46 - v45;
			sub_4A2D10(a1, 0, 1);
			return 0;
		default:
			return 0;
		}
		return result;
	}
	if (a2 == 16402) {
		if ((int)a3 >= 0) {
			v32 = v5[22];
			if ((int)a3 <= v32)
				v5[23] = (__int16)a3;
			else
				v5[23] = v32;
			result = 0;
		} else {
			v5[23] = 0;
			result = 0;
		}
		return result;
	}
	if (a2 > 0x4007) {
		switch (a2) {
		case 0x4009u:
			v29 = v5[26];
			v30 = *(_WORD*)(*(_DWORD*)(*((_DWORD*)v5 + 9) + 32) + 4) - a4;
			v31 = *((_DWORD*)v5 + 10) - v29 + 1;
			v5[27] = v30;
			if (v30 > v31)
				v5[27] = v5[20] - v29 + 1;
			if ((int)v5[27] < 0)
				v5[27] = 0;
			sub_4A2D10(a1, 0, 0);
			return 0;
		case 0x400Du:
			v18 = v5[23];
			v19 = v5[22];
			if (v18 != v19) {
				if (v19 < *v5) {
					v20 = v19 - 1;
					if (v20 < v18) {
					LABEL_66:
						sub_4A3AC0(a3, a4, v4);
						goto LABEL_67;
					}
					v21 = 524 * v20;
					do {
						--v20;
						v22 = *((_DWORD*)v5 + 6) + v21;
						v21 -= 524;
						qmemcpy((void*)(v22 + 524), (const void*)v22, 0x20Cu);
					} while (v20 >= v5[23]);
				LABEL_65:
					v4 = (_DWORD*)a1;
					goto LABEL_66;
				}
				if (*((_DWORD*)v5 + 2)) {
					nox_window_call_field_94(a1, 16411, 1, 0);
					v23 = v5[22] - 1;
					if (v23 < v5[23])
						goto LABEL_66;
					v24 = 524 * v23;
					do {
						--v23;
						v25 = *((_DWORD*)v5 + 6) + v24;
						v24 -= 524;
						qmemcpy((void*)(v25 + 524), (const void*)v25, 0x20Cu);
					} while (v23 >= v5[23]);
					goto LABEL_65;
				}
				return 0;
			}
			if (v18 >= *v5) {
				if (!*((_DWORD*)v5 + 2))
					return 0;
				nox_window_call_field_94(a1, 16411, 1, 0);
				sub_4A3AC0(a3, a4, (_DWORD*)a1);
			} else {
				sub_4A3AC0(a3, a4, (_DWORD*)a1);
			}
		LABEL_67:
			if (*((_DWORD*)v5 + 1)) {
				while (*(_DWORD*)(*((_DWORD*)v5 + 6) + 524 * v5[23] - 524) >= v5[27] + v5[26])
					sub_4A2D10((int)v4, 1, 1);
			}
			v26 = (_DWORD*)*((_DWORD*)v5 + 12);
			if (*((_DWORD*)v5 + 4)) {
				if ((int)*v26 >= 0) {
					v27 = 0;
					do {
						v28 = v26[v27];
						if (v5[23] < v28)
							v26[v27] = v28 + 1;
						v26 = (_DWORD*)*((_DWORD*)v5 + 12);
						++v27;
					} while ((int)v26[v27] >= 0);
					return 1;
				}
			} else if (v5[23] < (int)v26) {
				*((_DWORD*)v5 + 12) = (char*)v26 + 1;
			}
			return 1;
		case 0x400Eu:
			v12 = v5[22];
			if (v12 <= (int)a3)
				return 0;
			qmemcpy((void*)(*((_DWORD*)v5 + 6) + 524 * (_DWORD)a3),
					(const void*)(*((_DWORD*)v5 + 6) + 524 * ((_DWORD)a3 + 1)),
					4 * ((unsigned int)(524 * (v12 - (_DWORD)a3 - 1)) >> 2));
			v13 = --v5[22];
			v5[23] = v13;
			*(_WORD*)(*((_DWORD*)v5 + 6) + 524 * v13 + 4) = 0;
			if (*((_DWORD*)v5 + 4)) {
				v14 = (_DWORD*)*((_DWORD*)v5 + 12);
				v15 = 0;
				if ((int)*v14 >= 0) {
					do {
						v16 = (wchar_t*)v14[v15];
						if ((int)a3 >= (int)v16) {
							if (a3 == v16)
								sub_4A3090(v5, v15--);
						} else {
							v14[v15] = (char*)v16 - 1;
						}
						v14 = (_DWORD*)*((_DWORD*)v5 + 12);
						++v15;
					} while ((int)v14[v15] >= 0);
					sub_4A3A70(a1);
					return 0;
				}
			} else {
				v17 = (wchar_t*)*((_DWORD*)v5 + 12);
				if ((int)a3 < (int)v17) {
					*((_DWORD*)v5 + 12) = (char*)v17 - 1;
					sub_4A3A70(a1);
					return 0;
				}
				if (a3 == v17)
					*((_DWORD*)v5 + 12) = -1;
			}
			sub_4A3A70(a1);
			return 0;
		case 0x400Fu:
			memset(*((void**)v5 + 6), 0, 524 * *v5);
			if (a3 != (wchar_t*)1)
				v5[27] = 0;
			if (*((_DWORD*)v5 + 4))
				memset(*((void**)v5 + 12), 0xFFu, 4 * *v5);
			else
				*((_DWORD*)v5 + 12) = -1;
			v5[23] = 0;
			v5[22] = 0;
			*((_DWORD*)v5 + 10) = 0;
			sub_4A2D10(a1, 0, 1);
			return 0;
		default:
			return 0;
		}
	}
	if (a2 == 16391) {
		if (a3 == *((wchar_t**)v5 + 7)) {
			if (v5[27] > 0) {
				sub_4A2D10(a1, -1, 1);
				return 0;
			}
		} else if (a3 == *((wchar_t**)v5 + 8) && v5[26] + v5[27] <= *((_DWORD*)v5 + 10)) {
			sub_4A2D10(a1, 1, 1);
			return 0;
		}
		return 0;
	}
	if (a2 > 0x4000) {
		if (a2 == 16385) {
			nox_wcsncpy((wchar_t*)(a1 + 108), a3, 0x3Fu);
			*(_WORD*)(a1 + 2 * nox_wcslen(a3) + 108) = 0;
			return 0;
		}
		if (a2 == 16388) {
			v9 = (_DWORD*)*((_DWORD*)v5 + 7);
			if (v9)
				nox_wnd_sub_46A9B0(v9, (int)a3 - v9[2], 0);
			v10 = (_DWORD*)*((_DWORD*)v5 + 8);
			if (v10)
				nox_wnd_sub_46A9B0(v10, (int)a3 - v10[2], a4 - v10[3]);
			v11 = (_DWORD*)*((_DWORD*)v5 + 9);
			if (v11) {
				nox_wnd_sub_46A9B0(v11, (int)a3 - v11[2], *(_DWORD*)(*((_DWORD*)v5 + 7) + 12));
				sub_46AB20(*((_DWORD**)v5 + 9), *(_DWORD*)(*((_DWORD*)v5 + 9) + 8),
						   a4 - 2 * *(_DWORD*)(*(_DWORD*)(*((_DWORD*)v5 + 9) + 400) + 12));
			}
			v5[26] = a4;
			if (*(_WORD*)(a1 + 108)) {
				v5[26] -= sub_43F320(*(_DWORD*)(a1 + 236));
				return 0;
			}
		}
		return 0;
	}
	if (a2 == 0x4000) {
		if (a3 == *((wchar_t**)v5 + 7)) {
			if (v5[27] > 0) {
				sub_4A2D10(a1, -1, 1);
				return 0;
			}
		} else if (a3 == *((wchar_t**)v5 + 8) && v5[26] + v5[27] <= *((_DWORD*)v5 + 10)) {
			sub_4A2D10(a1, 1, 1);
			return 0;
		}
		return 0;
	}
	if (a2 != 2) {
		if (a2 == 23) {
			v6 = *(_DWORD*)(a1 + 36);
			if (a3)
				LOBYTE(v6) = v6 | 2;
			else
				LOBYTE(v6) = v6 & 0xFD;
			*(_DWORD*)(a1 + 36) = v6;
			v7 = sub_46B0A0((int*)a1);
			nox_window_call_field_94(*(_DWORD*)(a1 + 52), 16387, (int)a3, v7);
			return 1;
		}
		return 0;
	}
	free(*((LPVOID*)v5 + 6));
	if (*((_DWORD*)v5 + 4))
		free(*((LPVOID*)v5 + 12));
	free(v5);
	return 0;
}

//----- (004A3A70) --------------------------------------------------------
int __cdecl sub_4A3A70(int a1) {
	int v1; // edi
	int v2; // eax
	int v3; // ecx
	int v4; // ebp
	int v5; // esi

	v1 = 0;
	v2 = 0;
	v3 = *(_DWORD*)(a1 + 32);
	if (*(_WORD*)(v3 + 44) > 0) {
		v4 = 0;
		do {
			v5 = v4 + *(_DWORD*)(v3 + 24);
			++v1;
			v4 += 524;
			v2 += *(unsigned __int8*)(v5 + 520) + 1;
			*(_DWORD*)v5 = v2;
		} while (v1 < *(__int16*)(v3 + 44));
	}
	*(_DWORD*)(v3 + 40) = v2;
	return sub_4A2D10(a1, 0, 1);
}

//----- (004A3AC0) --------------------------------------------------------
int __cdecl sub_4A3AC0(wchar_t* a1, int a2, _DWORD* a3) {
	_DWORD* v3;  // ebx
	int v4;      // esi
	int v5;      // ebp
	wchar_t* v6; // edi
	wchar_t* v7; // eax

	v3 = a3;
	v4 = a3[8];
	v5 = a3[2] - 7;
	if (*(_DWORD*)(v4 + 12))
		v5 = a3[2] - 17;
	if (a2 >= 17 || a2 < 0)
		*(_DWORD*)(*(_DWORD*)(v4 + 24) + 524 * *(__int16*)(v4 + 46) + 516) = a3[26];
	else
		*(_DWORD*)(*(_DWORD*)(v4 + 24) + 524 * *(__int16*)(v4 + 46) + 516) = **(_DWORD**)&byte_5D4594[4 * a2 + 2649836];
	v6 = (wchar_t*)(*(_DWORD*)(v4 + 24) + 524 * *(__int16*)(v4 + 46) + 4);
	if (a1) {
		nox_wcsncpy(v6, a1, 0xFFu);
		v6[255] = 0;
		v7 = &v6[nox_wcslen(v6) - 1];
		if (*v7 == 10)
			*v7 = 0;
	} else {
		*v6 = 32;
		v6[1] = 0;
	}
	if ((v3[1] & 0x4000) == 0x4000) {
		*(_BYTE*)(*(_DWORD*)(v4 + 24) + 524 * *(__int16*)(v4 + 46) + 520) = sub_43F320(v3[59]);
	} else {
		sub_43F840(v3[59], v6, 0, &a3, v5);
		*(_BYTE*)(*(_DWORD*)(v4 + 24) + 524 * *(__int16*)(v4 + 46) + 520) = (_BYTE)a3;
	}
	++*(_WORD*)(v4 + 46);
	++*(_WORD*)(v4 + 44);
	return sub_4A3A70((int)v3);
}

//----- (004A3C00) --------------------------------------------------------
void __cdecl sub_4A3C00(int a1, int a2) {
	if (a1) {
		if ((signed char)*(_BYTE*)(a1 + 4) >= 0)
			sub_46B340(a1, sub_4A3C50);
		else
			sub_46B340(a1, sub_4A3FC0);
		if (*(_DWORD*)(a2 + 16))
			sub_46B300(a1, sub_4A2DE0);
		else
			sub_46B300(a1, sub_4A28E0);
	}
}

//----- (004A3C50) --------------------------------------------------------
int __cdecl sub_4A3C50(_DWORD* a1, int a2) {
	int v2;           // ebp
	int v3;           // edi
	int v4;           // ebx
	int v5;           // eax
	int v6;           // edi
	int v7;           // edx
	int v8;           // edi
	int v9;           // ebx
	int v10;          // eax
	int v11;          // ecx
	int v12;          // edi
	int* v13;         // ecx
	int v14;          // eax
	__int16* v15;     // edi
	int v16;          // ebx
	int v17;          // ecx
	int v19;          // [esp-4h] [ebp-234h]
	int v20;          // [esp+10h] [ebp-220h]
	int v21;          // [esp+10h] [ebp-220h]
	int v22;          // [esp+14h] [ebp-21Ch]
	int v23;          // [esp+18h] [ebp-218h]
	int v24;          // [esp+18h] [ebp-218h]
	int yTop;         // [esp+1Ch] [ebp-214h]
	int xLeft;        // [esp+20h] [ebp-210h]
	int v27;          // [esp+24h] [ebp-20Ch]
	int i;            // [esp+28h] [ebp-208h]
	int v29;          // [esp+2Ch] [ebp-204h]
	__int16 v30[256]; // [esp+30h] [ebp-200h]

	v2 = a1[8];
	v20 = *(_DWORD*)(a2 + 28);
	v23 = *(_DWORD*)(a2 + 20);
	nox_client_wndGetPosition_46AA60(a1, &xLeft, &yTop);
	v3 = sub_43F320(*(_DWORD*)(a2 + 200));
	v4 = a1[3];
	v22 = a1[2];
	if ((a1[1] & 0x2000) == 0x2000)
		sub_43F670(1);
	sub_49F7F0();
	if (*(_DWORD*)(v2 + 12))
		v22 -= 10;
	if (*(_WORD*)(a2 + 72)) {
		sub_434390(*(_DWORD*)(a2 + 68));
		sub_43FAF0(*(_DWORD*)(a2 + 200), (_WORD*)(a2 + 72), xLeft + 1, yTop, v22, v3);
		v4 += -1 - v3;
		yTop += v3 + 1;
	}
	if (a1[1] & 8) {
		if (*(_BYTE*)a2 & 2) {
			v6 = *(_DWORD*)(a2 + 36);
			v5 = v23;
			goto LABEL_13;
		}
		v5 = v23;
	} else {
		v5 = *(_DWORD*)(a2 + 44);
	}
	v6 = v20;
LABEL_13:
	if (v5 != 0x80000000) {
		nox_client_drawSetColor_434460(v5);
		nox_client_drawRectFilledOpaque_49CE30(xLeft, yTop, v22, v4);
	}
	if (v6 != 0x80000000) {
		nox_client_drawSetColor_434460(v6);
		nox_client_drawBorderLines_49CC70(xLeft, yTop, v22, v4);
	}
	nox_client_copyRect_49F6F0(xLeft, yTop, v22, v4);
	v7 = *(__int16*)(v2 + 54);
	v8 = yTop - v7;
	v21 = yTop - v7;
	if (*(_DWORD*)(a2 + 68) != 0x80000000) {
		v9 = 0;
		v24 = 0;
		for (i = 0;; i = v9) {
			if (v9 > 0 && *(_DWORD*)(*(_DWORD*)(v2 + 24) + v9 - 524) > *(__int16*)(v2 + 54) + *(__int16*)(v2 + 52) ||
				v24 == *(__int16*)(v2 + 44)) {
				break;
			}
			v10 = *(_DWORD*)(v2 + 24) + v9;
			if (*(_DWORD*)v10 < *(__int16*)(v2 + 54)) {
				v21 = v8 + *(unsigned __int8*)(v10 + 520) + 1;
				goto LABEL_38;
			}
			v11 = *(unsigned __int8*)(v10 + 520);
			v19 = *(_DWORD*)(v10 + 516);
			v12 = v11 + 1;
			v27 = v11 + 1;
			sub_434390(v19);
			if (*(_DWORD*)(v2 + 16)) {
				v13 = *(int**)(v2 + 48);
				v14 = *v13;
				if ((int)*v13 >= 0) {
					while (v24 != v14) {
						v14 = v13[1];
						++v13;
						if (v14 < 0)
							goto LABEL_32;
					}
				LABEL_30:
					if (*(_DWORD*)(a2 + 52) != 0x80000000) {
						nox_client_drawSetColor_434460(*(_DWORD*)(a2 + 52));
						nox_client_drawRectFilledOpaque_49CE30(xLeft, v21, v22, v12);
					}
					goto LABEL_32;
				}
			} else if (v24 == *(_DWORD*)(v2 + 48)) {
				goto LABEL_30;
			}
		LABEL_32:
			sub_434390(*(_DWORD*)(*(_DWORD*)(v2 + 24) + v9 + 516));
			if ((a1[1] & 0x4000) == 0x4000) {
				nox_wcscpy((wchar_t*)v30, (const wchar_t*)(*(_DWORD*)(v2 + 24) + v9 + 4));
				v15 = &v30[nox_wcslen((const wchar_t*)v30)];
				v16 = v22 - 7;
				do {
					v17 = *(_DWORD*)(a2 + 200);
					*v15 = 0;
					--v15;
					sub_43F840(v17, (unsigned __int16*)v30, &v29, 0, 0);
				} while (v29 > v16);
				sub_43FAF0(*(_DWORD*)(a2 + 200), v30, xLeft + 5, v21 + 2, v16, v27);
				v9 = i;
				v12 = v27;
			} else {
				sub_43FAF0(*(_DWORD*)(a2 + 200), (_WORD*)(*(_DWORD*)(v2 + 24) + v9 + 4), xLeft + 5, v21 + 2, v22 - 7,
						   v12);
			}
			v21 += v12;
		LABEL_38:
			v8 = v21;
			v9 += 524;
			++v24;
		}
	}
	sub_49F860();
	sub_43F670(0);
	return 1;
}
// 4A3C50: using guessed type wchar_t var_200[256];

//----- (004A3FC0) --------------------------------------------------------
int __cdecl sub_4A3FC0(_DWORD* a1, int a2) {
	int v2;           // ecx
	int v3;           // ebp
	int v4;           // esi
	int v5;           // eax
	int v6;           // eax
	int v7;           // edx
	int v8;           // eax
	int v9;           // esi
	int v10;          // ebx
	int v11;          // eax
	int v12;          // ecx
	int v13;          // esi
	int* v14;         // ecx
	int v15;          // eax
	__int16* v16;     // esi
	int v17;          // ebx
	int v18;          // ecx
	int v20;          // [esp-24h] [ebp-254h]
	int v21;          // [esp-4h] [ebp-234h]
	int v22;          // [esp+10h] [ebp-220h]
	int yTop;         // [esp+14h] [ebp-21Ch]
	int xLeft;        // [esp+18h] [ebp-218h]
	int v25;          // [esp+1Ch] [ebp-214h]
	int v26;          // [esp+20h] [ebp-210h]
	int i;            // [esp+24h] [ebp-20Ch]
	int v28;          // [esp+28h] [ebp-208h]
	int v29;          // [esp+2Ch] [ebp-204h]
	__int16 v30[256]; // [esp+30h] [ebp-200h]

	v2 = *(_DWORD*)(a2 + 24);
	v3 = a1[8];
	v28 = *(_DWORD*)(a2 + 28);
	i = v2;
	nox_client_wndGetPosition_46AA60(a1, &xLeft, &yTop);
	v4 = a1[3];
	v22 = a1[2];
	if ((a1[1] & 0x2000) == 0x2000)
		sub_43F670(1);
	sub_49F7F0();
	if (*(_DWORD*)(v3 + 12))
		v22 -= 10;
	if (a1[1] & 8)
		v5 = i;
	else
		v5 = *(_DWORD*)(a2 + 48);
	if (v5)
		nox_client_drawImageAt_47D2C0(v5, xLeft, yTop);
	if (*(_WORD*)(a2 + 72)) {
		sub_434390(*(_DWORD*)(a2 + 68));
		sub_43FAF0(*(_DWORD*)(a2 + 200), (_WORD*)(a2 + 72), xLeft + 1, yTop, v22, 0);
		v6 = sub_43F320(*(_DWORD*)(a2 + 200));
		v20 = *(_DWORD*)(a2 + 200);
		yTop += v6 + 1;
		v4 += -1 - sub_43F320(v20);
	}
	if (v28 != 0x80000000) {
		nox_client_drawSetColor_434460(v28);
		nox_client_drawBorderLines_49CC70(xLeft, yTop, v22, v4);
	}
	nox_client_copyRect_49F6F0(xLeft, yTop, v22, v4);
	v7 = *(__int16*)(v3 + 54);
	v8 = *(_DWORD*)(a2 + 68);
	v9 = yTop - v7;
	v25 = yTop - v7;
	if (v8 != 0x80000000) {
		v10 = 0;
		v26 = 0;
		for (i = 0;; i = v10) {
			if (v10 > 0 && *(_DWORD*)(*(_DWORD*)(v3 + 24) + v10 - 524) > *(__int16*)(v3 + 54) + *(__int16*)(v3 + 52) ||
				v26 == *(__int16*)(v3 + 44)) {
				break;
			}
			v11 = v10 + *(_DWORD*)(v3 + 24);
			if (*(_DWORD*)v11 < *(__int16*)(v3 + 54)) {
				v25 = v9 + *(unsigned __int8*)(v11 + 520) + 1;
				goto LABEL_35;
			}
			v12 = *(unsigned __int8*)(v11 + 520);
			v21 = *(_DWORD*)(v11 + 516);
			v13 = v12 + 1;
			v28 = v12 + 1;
			sub_434390(v21);
			if (*(_DWORD*)(v3 + 16)) {
				v14 = *(int**)(v3 + 48);
				v15 = *v14;
				if ((int)*v14 >= 0) {
					while (v26 != v15) {
						v15 = v14[1];
						++v14;
						if (v15 < 0)
							goto LABEL_29;
					}
				LABEL_27:
					if (*(_DWORD*)(a2 + 52) != 0x80000000) {
						nox_client_drawSetColor_434460(*(_DWORD*)(a2 + 52));
						nox_client_drawRectFilledOpaque_49CE30(xLeft, v25, v22, v13);
					}
					goto LABEL_29;
				}
			} else if (v26 == *(_DWORD*)(v3 + 48)) {
				goto LABEL_27;
			}
		LABEL_29:
			sub_434390(*(_DWORD*)(v10 + *(_DWORD*)(v3 + 24) + 516));
			if ((a1[1] & 0x4000) == 0x4000) {
				nox_wcscpy((wchar_t*)v30, (const wchar_t*)(v10 + *(_DWORD*)(v3 + 24) + 4));
				v16 = &v30[nox_wcslen((const wchar_t*)v30)];
				v17 = v22 - 7;
				do {
					v18 = *(_DWORD*)(a2 + 200);
					*v16 = 0;
					--v16;
					sub_43F840(v18, (unsigned __int16*)v30, &v29, 0, 0);
				} while (v29 > v17);
				sub_43FAF0(*(_DWORD*)(a2 + 200), v30, xLeft + 5, v25 + 2, v17, v28);
				v10 = i;
				v13 = v28;
			} else {
				sub_43FAF0(*(_DWORD*)(a2 + 200), (_WORD*)(v10 + *(_DWORD*)(v3 + 24) + 4), xLeft + 5, v25 + 2, v22 - 7,
						   v13);
			}
			v25 += v13;
		LABEL_35:
			v9 = v25;
			v10 += 524;
			++v26;
		}
	}
	sub_49F860();
	sub_43F670(0);
	return 1;
}
// 4A3FC0: using guessed type wchar_t var_200[256];

//----- (004A4800) --------------------------------------------------------
int __cdecl sub_4A4800(int a1) {
	int result; // eax
	_DWORD* v2; // ecx
	int v3;     // esi
	int v4;     // edi

	result = 0;
	v2 = *(_DWORD**)(a1 + 24);
	v3 = *(__int16*)(a1 + 54);
	if (*v2 <= v3) {
		while (result < *(__int16*)(a1 + 44)) {
			v4 = v2[131];
			v2 += 131;
			++result;
			if (v4 > v3)
				return result;
		}
		result = 0;
	}
	return result;
}

//----- (004A4840) --------------------------------------------------------
int sub_4A4840() {
	int result; // eax
	_DWORD* v1; // eax
	_DWORD* v2; // eax
	_DWORD* v3; // eax

	sub_5007E0((char*)&byte_587000[170168]);
	sub_4A1BE0(1);
	dword_5d4594_1307724 = sub_431770();
	sub_43BDD0(600);
	result = nox_new_window_from_file("SelClass.wnd", sub_4A4A20);
	dword_5d4594_1307736 = result;
	if (result) {
		sub_46B300(result, sub_4A18E0);
		result = nox_wnd_sub_43C5B0(*(_DWORD**)&dword_5d4594_1307736, 0, 0, 0, -460, 0, 20, 0, -40);
		dword_5d4594_1307732 = result;
		if (result) {
			*(_DWORD*)result = 600;
			*(_DWORD*)(dword_5d4594_1307732 + 48) = sub_4A4970;
			*(_DWORD*)(dword_5d4594_1307732 + 56) = sub_4A49A0;
			v1 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1307736, 601);
			sub_46B340((int)v1, sub_4A49D0);
			v2 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1307736, 603);
			sub_46B340((int)v2, sub_4A49D0);
			v3 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1307736, 602);
			sub_46B340((int)v3, sub_4A49D0);
			*(_DWORD*)&byte_5D4594[1307728] = sub_46B0C0(*(_DWORD**)&dword_5d4594_1307736, 610);
			sub_46A8A0();
			*(_DWORD*)&byte_5D4594[1307740] = 0;
			sub_4A19F0((char*)&byte_587000[170188]);
			sub_4602F0();
			result = 1;
		}
	}
	return result;
}
// 4A18E0: using guessed type int __cdecl sub_4A18E0(int, int, int, int);

//----- (004A4970) --------------------------------------------------------
int sub_4A4970() {
	*(_BYTE*)(dword_5d4594_1307732 + 64) = 2;
	sub_43BE40(2);
	sub_452D80(923, 100);
	return 1;
}

//----- (004A49A0) --------------------------------------------------------
int sub_4A49A0() {
	int (*v0)(void); // esi

	v0 = *(int (**)(void))(dword_5d4594_1307732 + 52);
	sub_43C570(*(LPVOID*)&dword_5d4594_1307732);
	sub_46C4E0(*(_DWORD**)&dword_5d4594_1307736);
	v0();
	return 1;
}

//----- (004A49D0) --------------------------------------------------------
int __cdecl sub_4A49D0(int yTop, int a2) {
	_DWORD* v1; // esi
	int xLeft;  // [esp+4h] [ebp-4h]

	v1 = (_DWORD*)yTop;
	if (*(_DWORD*)&byte_5D4594[1307740] != *(_DWORD*)yTop) {
		nox_client_wndGetPosition_46AA60((_DWORD*)yTop, &xLeft, &yTop);
		nox_client_drawRectFilledAlpha_49CF10(xLeft, yTop, v1[6] - v1[4], v1[7] - v1[5]);
	}
	return 1;
}

//----- (004A4CB0) --------------------------------------------------------
int __cdecl sub_4A4CB0(const void* a1, const void* a2) {
	if (*((_WORD*)a1 + 594) != *((_WORD*)a2 + 594))
		return *((unsigned __int16*)a2 + 594) - *((unsigned __int16*)a1 + 594);
	if (*((_WORD*)a1 + 595) != *((_WORD*)a2 + 595))
		return *((unsigned __int16*)a2 + 595) - *((unsigned __int16*)a1 + 595);
	if (*((_WORD*)a1 + 597) != *((_WORD*)a2 + 597))
		return *((unsigned __int16*)a2 + 597) - *((unsigned __int16*)a1 + 597);
	if (*((_WORD*)a1 + 598) != *((_WORD*)a2 + 598))
		return *((unsigned __int16*)a2 + 598) - *((unsigned __int16*)a1 + 598);
	if (*((_WORD*)a1 + 599) != *((_WORD*)a2 + 599))
		return *((unsigned __int16*)a2 + 599) - *((unsigned __int16*)a1 + 599);
	if (*((_WORD*)a1 + 600) != *((_WORD*)a2 + 600))
		return *((unsigned __int16*)a2 + 600) - *((unsigned __int16*)a1 + 600);
	if (*((_WORD*)a1 + 601) == *((_WORD*)a2 + 601))
		return 0;
	return *((unsigned __int16*)a2 + 601) - *((unsigned __int16*)a1 + 601);
}

// 4A18E0: using guessed type int __cdecl sub_4A18E0(int, int, int, int);

//----- (004A50A0) --------------------------------------------------------
int sub_4A50A0() {
	*(_BYTE*)(dword_5d4594_1307748 + 64) = 2;
	sub_43BE40(2);
	sub_452D80(923, 100);
	return 1;
}

//----- (004A50D0) --------------------------------------------------------
int sub_4A50D0() {
	void (*v0)(void); // esi

	v0 = *(void (**)(void))(dword_5d4594_1307748 + 52);
	sub_43C570(*(LPVOID*)&dword_5d4594_1307748);
	sub_46C4E0(*(_DWORD**)&dword_5d4594_1307764);
	if (v0) {
		v0();
		return 1;
	}
	sub_431510();
	mainloop_draw();
	if (nox_common_gameFlags_check_40A5C0(0x2000)) {
		if (!sub_43AF70()) {
			sub_43B4D0();
			return 1;
		}
		if (sub_43AF70() == 1) {
			sub_43B670();
			return 1;
		}
	} else {
		sub_4A24A0();
	}
	return 1;
}

// 4A5150: using guessed type CHAR PathName[1024];

//----- (004A5690) --------------------------------------------------------
int __cdecl sub_4A5690(_BYTE* a1) {
	int result; // eax

	if (!(*a1 & 4)) {
		if (!sub_4D6F50() && !sub_4D6F70())
			return 1;
		if (!(*a1 & 4))
			goto LABEL_12;
	}
	if (sub_4D6F50() || sub_4D6F70())
		result = 1;
	else
	LABEL_12:
		result = 0;
	return result;
}

//----- (004A56E0) --------------------------------------------------------
void* sub_4A56E0() {
	int v0; // eax

	v0 = *(_DWORD*)&nox_common_engineFlags;
	LOBYTE(v0) = nox_common_engineFlags & 0xEF;
	*(_DWORD*)&nox_common_engineFlags = v0;
	return sub_4602F0();
}

//----- (004A5700) --------------------------------------------------------
int sub_4A5700() {
	int result; // eax

	result = *(_DWORD*)&nox_common_engineFlags;
	LOBYTE(result) = nox_common_engineFlags | 0x10;
	*(_DWORD*)&nox_common_engineFlags = result;
	return result;
}

//----- (004A5C70) --------------------------------------------------------
int sub_4A5C70() {
	if (nox_common_gameFlags_check_40A5C0(2048))
		nox_savegame_rm_4DBE10(nox_savegame_name_1307752, 1);
	else
		DeleteFileA((LPCSTR)(dword_5d4594_1307780 + 1278 * *(_DWORD*)&byte_5D4594[1307772] + 4));
	nox_window_call_field_94(*(int*)&dword_5d4594_1307744, 16399, 0, 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_1307776, 16399, 0, 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_1307768, 16399, 0, 0);
	return sub_4A5150();
}

// 4A18E0: using guessed type int __cdecl sub_4A18E0(int, int, int, int);

//----- (004A5E90) --------------------------------------------------------
int sub_4A5E90() {
	const char** i; // eax
	_DWORD* v1;     // eax
	_DWORD* v2;     // eax
	_DWORD* v3;     // eax
	_DWORD* v4;     // eax
	_DWORD* v5;     // eax
	_DWORD* v6;     // eax
	_DWORD* v7;     // eax
	_DWORD* v8;     // eax
	_DWORD* v9;     // eax
	_DWORD* v10;    // eax
	int result;     // eax

	if (*(_DWORD*)&byte_587000[171384])
		sub_4A62B0();
	for (i = (const char**)sub_413390(); i; i = (const char**)sub_4133A0((int)i)) {
		if (!strcmp(*i, "StreetPants")) {
			dword_5d4594_1308156 = i;
		} else if (!strcmp(*i, "StreetShirt")) {
			dword_5d4594_1308160 = i;
		} else if (!strcmp(*i, "StreetSneakers")) {
			dword_5d4594_1308164 = i;
		}
	}
	v1 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1308084, 720);
	dword_5d4594_1308096 = v1;
	v1[8] = 131074;
	v2 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1308084, 721);
	dword_5d4594_1308100 = v2;
	v2[8] = 589825;
	v3 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1308084, 722);
	dword_5d4594_1308104 = v3;
	v3[8] = 589825;
	v4 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1308084, 723);
	dword_5d4594_1308108 = v4;
	v4[8] = 589825;
	v5 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1308084, 724);
	dword_5d4594_1308112 = v5;
	v5[8] = 589825;
	v6 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1308084, 725);
	dword_5d4594_1308116 = v6;
	v6[8] = *(unsigned __int16*)&byte_587000[171372] << 16;
	v7 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1308084, 726);
	dword_5d4594_1308120 = v7;
	v7[8] = *(unsigned __int16*)&byte_587000[171374] << 16;
	v8 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1308084, 727);
	dword_5d4594_1308124 = v8;
	v8[8] = *(unsigned __int16*)&byte_587000[171376] << 16;
	v9 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1308084, 728);
	dword_5d4594_1308128 = v9;
	v9[8] = *(unsigned __int16*)&byte_587000[171378] << 16;
	v10 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1308084, 729);
	dword_5d4594_1308132 = v10;
	v10[8] = *(unsigned __int16*)&byte_587000[171380] << 16;
	dword_5d4594_1308136 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1308084, 711);
	dword_5d4594_1308140 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1308084, 712);
	dword_5d4594_1308144 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1308084, 713);
	dword_5d4594_1308148 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1308084, 714);
	dword_5d4594_1308152 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1308084, 751);
	result = dword_587000_171388;
	if (!dword_587000_171388) {
		nox_window_call_field_94(*(int*)&dword_5d4594_1308152, 16414, *(int*)&dword_5d4594_1307784, 0);
		sub_4A61E0(*(_DWORD**)&dword_5d4594_1308096, 2, (_BYTE*)(dword_5d4594_1307784 + 71));
		sub_4A61E0(*(_DWORD**)&dword_5d4594_1308100, 1, (_BYTE*)(dword_5d4594_1307784 + 68));
		sub_4A61E0(*(_DWORD**)&dword_5d4594_1308104, 1, (_BYTE*)(dword_5d4594_1307784 + 74));
		sub_4A61E0(*(_DWORD**)&dword_5d4594_1308108, 1, (_BYTE*)(dword_5d4594_1307784 + 77));
		sub_4A61E0(*(_DWORD**)&dword_5d4594_1308112, 1, (_BYTE*)(dword_5d4594_1307784 + 80));
		*(_DWORD*)(dword_5d4594_1308116 + 32) = *(unsigned __int8*)(dword_5d4594_1307784 + 83) << 16;
		*(_DWORD*)(dword_5d4594_1308120 + 32) = *(unsigned __int8*)(dword_5d4594_1307784 + 84) << 16;
		*(_DWORD*)(dword_5d4594_1308124 + 32) = *(unsigned __int8*)(dword_5d4594_1307784 + 85) << 16;
		*(_DWORD*)(dword_5d4594_1308128 + 32) = *(unsigned __int8*)(dword_5d4594_1307784 + 86) << 16;
		result = *(unsigned __int8*)(dword_5d4594_1307784 + 87) << 16;
		*(_DWORD*)(dword_5d4594_1308132 + 32) = result;
	}
	return result;
}

//----- (004A61E0) --------------------------------------------------------
unsigned __int8* __cdecl sub_4A61E0(_DWORD* a1, int a2, unsigned __int8* a3) {
	unsigned int v3;         // esi
	unsigned __int8* result; // eax
	_DWORD* v5;              // eax
	_DWORD* v6;              // eax

	v3 = 0;
	result = &byte_5D4594[96 * a2 + 1307797];
	while (*(result - 1) != *a3 || *result != a3[1] || result[1] != a3[2]) {
		++v3;
		result += 3;
		if (v3 >= 0x20)
			goto LABEL_9;
	}
	if (a2 == 1) {
		v5 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1308084, *a1 - 10);
		sub_46ABB0((int)v5, 1);
		result = (unsigned __int8*)sub_46B0C0(*(_DWORD**)&dword_5d4594_1308084, *a1 + 10);
		*((_DWORD*)result + 9) |= 6u;
	}
LABEL_9:
	if (v3 == 32 && a2 == 1) {
		v6 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1308084, *a1 - 10);
		result = (unsigned __int8*)sub_46ABB0((int)v6, 0);
		LOWORD(v3) = 9;
	}
	a1[8] = (unsigned __int16)a2 | ((unsigned __int16)v3 << 16);
	return result;
}

//----- (004A62B0) --------------------------------------------------------
char sub_4A62B0() {
	unsigned __int8* v0; // esi
	int v1;              // eax
	int v3;              // ebp
	char result;         // al
	unsigned __int8* v5; // [esp+10h] [ebp-18h]
	int v6;              // [esp+14h] [ebp-14h]
	char v7[16];         // [esp+18h] [ebp-10h]

	v0 = &byte_5D4594[1307796];
	v1 = 0;
	v5 = &byte_5D4594[1307796];
	do {
		*v0 = 0;
		v6 = v1 + 1;
		v0[1] = 0;
		v0[2] = 0;
		nox_sprintf(v7, "UserColor%d", v1 + 1);
		obj_412ae0_t* v2 = sub_4133B0(2);
		if (v2) {
			while (strcmp(v7, v2->field_0)) {
				v2 = sub_4133C0(v2);
				if (!v2)
					goto LABEL_7;
			}
			v3 = (int)(&v2->field_6);
			*(_WORD*)v5 = *(_WORD*)v3;
			v5[2] = *(_BYTE*)(v3 + 2);
		LABEL_7:
			v0 = v5;
		}
		v1 = v6;
		v0 += 3;
		v5 = v0;
	} while ((int)v0 < (int)&byte_5D4594[1307892]);
	byte_5D4594[1307989] = -34;
	byte_5D4594[1307991] = -34;
	byte_5D4594[1307995] = -102;
	byte_5D4594[1308000] = -102;
	byte_5D4594[1308038] = -102;
	byte_5D4594[1307988] = -23;
	byte_5D4594[1307990] = -51;
	byte_5D4594[1307992] = -74;
	byte_5D4594[1307993] = -88;
	byte_5D4594[1307994] = -38;
	byte_5D4594[1307996] = 110;
	byte_5D4594[1307997] = -20;
	byte_5D4594[1307998] = -54;
	byte_5D4594[1307999] = -78;
	byte_5D4594[1308001] = -125;
	byte_5D4594[1308002] = 105;
	byte_5D4594[1308003] = 117;
	byte_5D4594[1308004] = 95;
	byte_5D4594[1308005] = 74;
	byte_5D4594[1308006] = -17;
	byte_5D4594[1308007] = -23;
	byte_5D4594[1308008] = -63;
	byte_5D4594[1308009] = -28;
	byte_5D4594[1308010] = -28;
	byte_5D4594[1308011] = -63;
	byte_5D4594[1308012] = -53;
	byte_5D4594[1308013] = -71;
	byte_5D4594[1308014] = -100;
	byte_5D4594[1308015] = -56;
	byte_5D4594[1308016] = -92;
	byte_5D4594[1308017] = 110;
	byte_5D4594[1308018] = -87;
	byte_5D4594[1308019] = -125;
	byte_5D4594[1308020] = 79;
	byte_5D4594[1308021] = -13;
	byte_5D4594[1308022] = -98;
	byte_5D4594[1308023] = 119;
	byte_5D4594[1308024] = 115;
	byte_5D4594[1308025] = 77;
	byte_5D4594[1308026] = 34;
	byte_5D4594[1308027] = 91;
	byte_5D4594[1308028] = 55;
	byte_5D4594[1308029] = 20;
	byte_5D4594[1308030] = -7;
	byte_5D4594[1308031] = -51;
	byte_5D4594[1308032] = -118;
	byte_5D4594[1308033] = -16;
	byte_5D4594[1308034] = -21;
	byte_5D4594[1308035] = -85;
	byte_5D4594[1308036] = -122;
	byte_5D4594[1308037] = -113;
	byte_5D4594[1308039] = -121;
	byte_5D4594[1308040] = 102;
	byte_5D4594[1308041] = 67;
	byte_5D4594[1308042] = 115;
	byte_5D4594[1308043] = 80;
	byte_5D4594[1308044] = 46;
	byte_5D4594[1308045] = -91;
	byte_5D4594[1308046] = 93;
	byte_5D4594[1308047] = 70;
	byte_5D4594[1308048] = 99;
	byte_5D4594[1308049] = 65;
	byte_5D4594[1308050] = 37;
	byte_5D4594[1308051] = 83;
	byte_5D4594[1308052] = 52;
	byte_5D4594[1308053] = 29;
	byte_5D4594[1308054] = -88;
	byte_5D4594[1308055] = 127;
	byte_5D4594[1308056] = 84;
	byte_5D4594[1308057] = -85;
	byte_5D4594[1308058] = -96;
	byte_5D4594[1308059] = 96;
	byte_5D4594[1308060] = -115;
	byte_5D4594[1308061] = -120;
	byte_5D4594[1308062] = 118;
	byte_5D4594[1308063] = 127;
	byte_5D4594[1308065] = 82;
	byte_5D4594[1308064] = 116;
	byte_5D4594[1308080] = 116;
	byte_5D4594[1308082] = 116;
	byte_5D4594[1307898] = -1;
	byte_5D4594[1307904] = -1;
	byte_5D4594[1308066] = 96;
	byte_5D4594[1307908] = 68;
	byte_5D4594[1307909] = 68;
	byte_5D4594[1307926] = 68;
	byte_5D4594[1307936] = 68;
	byte_5D4594[1308067] = 84;
	byte_5D4594[1307937] = -42;
	byte_5D4594[1307938] = -42;
	byte_5D4594[1307939] = -42;
	byte_5D4594[1308068] = 51;
	byte_5D4594[1308069] = -94;
	byte_5D4594[1308070] = -127;
	byte_5D4594[1308071] = 100;
	byte_5D4594[1308072] = 78;
	byte_5D4594[1308073] = 64;
	byte_5D4594[1308074] = 46;
	byte_5D4594[1308075] = 65;
	byte_5D4594[1308076] = 50;
	byte_5D4594[1308077] = 45;
	byte_5D4594[1308078] = -85;
	byte_5D4594[1308079] = -98;
	byte_5D4594[1308081] = -81;
	byte_5D4594[1308083] = -125;
	byte_5D4594[1307892] = -13;
	byte_5D4594[1307893] = -73;
	byte_5D4594[1307894] = -97;
	byte_5D4594[1307895] = -57;
	byte_5D4594[1307896] = -124;
	byte_5D4594[1307897] = 58;
	byte_5D4594[1307899] = -86;
	byte_5D4594[1307900] = 86;
	byte_5D4594[1307901] = -110;
	byte_5D4594[1307902] = 121;
	byte_5D4594[1307903] = 106;
	byte_5D4594[1307905] = -5;
	byte_5D4594[1307906] = -70;
	byte_5D4594[1307907] = -9;
	byte_5D4594[1307910] = 63;
	byte_5D4594[1307911] = -69;
	byte_5D4594[1307912] = -17;
	byte_5D4594[1307913] = -60;
	byte_5D4594[1307914] = -62;
	byte_5D4594[1307915] = -79;
	byte_5D4594[1307916] = -3;
	byte_5D4594[1307917] = -10;
	byte_5D4594[1307918] = 102;
	byte_5D4594[1307919] = 115;
	byte_5D4594[1307920] = 77;
	byte_5D4594[1307921] = 34;
	byte_5D4594[1307922] = -27;
	byte_5D4594[1307923] = 121;
	byte_5D4594[1307924] = 25;
	byte_5D4594[1307925] = 82;
	byte_5D4594[1307927] = 60;
	byte_5D4594[1307928] = -21;
	byte_5D4594[1307929] = -27;
	byte_5D4594[1307930] = -119;
	byte_5D4594[1307931] = -109;
	byte_5D4594[1307932] = 0;
	byte_5D4594[1307933] = 0;
	byte_5D4594[1307934] = 0;
	byte_5D4594[1307935] = 37;
	byte_5D4594[1307940] = -107;
	byte_5D4594[1307941] = 108;
	byte_5D4594[1307942] = 43;
	byte_5D4594[1307943] = 52;
	byte_5D4594[1307944] = 25;
	byte_5D4594[1307945] = 0;
	byte_5D4594[1307946] = -106;
	byte_5D4594[1307947] = 55;
	byte_5D4594[1307952] = -106;
	byte_5D4594[1307955] = -125;
	byte_5D4594[1307956] = 104;
	byte_5D4594[1307961] = 117;
	byte_5D4594[1307962] = 117;
	byte_5D4594[1307963] = 117;
	byte_5D4594[1307981] = 104;
	result = 53;
	byte_5D4594[1307948] = 0;
	byte_5D4594[1307950] = 0;
	byte_5D4594[1307984] = 0;
	*(_DWORD*)&byte_587000[171384] = 0;
	byte_5D4594[1307949] = 9;
	byte_5D4594[1307951] = 12;
	byte_5D4594[1307953] = -110;
	byte_5D4594[1307954] = 81;
	byte_5D4594[1307957] = -77;
	byte_5D4594[1307958] = 121;
	byte_5D4594[1307959] = -91;
	byte_5D4594[1307960] = 66;
	byte_5D4594[1307964] = 100;
	byte_5D4594[1307965] = -126;
	byte_5D4594[1307966] = 125;
	byte_5D4594[1307967] = 56;
	byte_5D4594[1307968] = 48;
	byte_5D4594[1307969] = 40;
	byte_5D4594[1307970] = 108;
	byte_5D4594[1307971] = 81;
	byte_5D4594[1307972] = 58;
	byte_5D4594[1307973] = 52;
	byte_5D4594[1307974] = 40;
	byte_5D4594[1307975] = 39;
	byte_5D4594[1307976] = -113;
	byte_5D4594[1307977] = -114;
	byte_5D4594[1307978] = 124;
	byte_5D4594[1307979] = 56;
	byte_5D4594[1307980] = 29;
	byte_5D4594[1307982] = 15;
	byte_5D4594[1307983] = 88;
	byte_5D4594[1307985] = 87;
	byte_5D4594[1307986] = 53;
	byte_5D4594[1307987] = 53;
	return result;
}

//----- (004A6890) --------------------------------------------------------
int sub_4A6890() {
	*(_BYTE*)(dword_5d4594_1308092 + 64) = 2;
	sub_43BE40(2);
	sub_452D80(923, 100);
	sub_4A68C0();
	return 1;
}

//----- (004A6B50) --------------------------------------------------------
int __cdecl sub_4A6B50(wchar_t* a1) {
	wchar_t* v1;     // esi
	int v2;          // ebp
	int v3;          // ebx
	signed int v4;   // eax
	__int16* v5;     // edi
	wchar_t v6;      // ax
	signed int v7;   // esi
	WCHAR* i;        // edi
	int v10;         // [esp+10h] [ebp-3Ch]
	signed int v11;  // [esp+14h] [ebp-38h]
	__int16 v12[26]; // [esp+18h] [ebp-34h]

	v1 = a1;
	v2 = 0;
	v3 = 1;
	v10 = 0;
	v4 = nox_wcslen(a1);
	if (v4 >= 1) {
		v5 = v12;
		v11 = v4;
		do {
			if (iswspace(*v1)) {
				if (!v3) {
					*v5 = *v1;
					++v5;
					++v10;
				}
			} else {
				if (v3 == 1) {
					v6 = *v1;
					if (*v1 == 42 || v6 == 63 || v6 == 60 || v6 == 62 || v6 == 92 || v6 == 47 || v6 == 58 || v6 == 34 ||
						v6 == 124) {
						*v1 = 45;
					}
				}
				*v5 = *v1;
				++v5;
				++v10;
				v3 = 0;
				v2 = 1;
			}
			++v1;
			--v11;
		} while (v11);
		v12[v10] = 0;
		if (v2) {
			nox_wcscpy(a1, (const wchar_t*)v12);
			v7 = nox_wcslen((const wchar_t*)v12) - 1;
			if ((int)v7 >= 0) {
				for (i = &a1[v7]; iswspace(*i); --i) {
					if (--v7 < 0)
						return v2;
				}
				a1[v7 + 1] = 0;
			}
		}
	}
	return v2;
}
// 4A6B50: using guessed type wchar_t var_34[26];

//----- (004A6C90) --------------------------------------------------------
int sub_4A6C90() {
	void (*v0)(void); // esi

	v0 = *(void (**)(void))(dword_5d4594_1308092 + 52);
	sub_43C570(*(LPVOID*)&dword_5d4594_1308092);
	sub_46C4E0(*(_DWORD**)&dword_5d4594_1308084);
	sub_46C4E0(*(_DWORD**)&dword_5d4594_1308088);
	if (v0) {
		v0();
	} else {
		sub_431510();
		mainloop_draw();
		if (!nox_common_gameFlags_check_40A5C0(0x2000)) {
			sub_4A24A0();
			return 1;
		}
		if (!sub_43AF70()) {
			sub_43B4D0();
			return 1;
		}
		if (sub_43AF70() == 1) {
			sub_43B670();
			return 1;
		}
	}
	return 1;
}

//----- (004A6D20) --------------------------------------------------------
int __cdecl sub_4A6D20(int a1, int a2) {
	int v1;              // esi
	unsigned __int16 v2; // di
	int v3;              // ebx
	int v4;              // ecx
	int v5;              // edx
	int v6;              // edi
	int v7;              // ebp
	int v8;              // eax
	int v10;             // [esp-10h] [ebp-28h]
	int yTop;            // [esp+10h] [ebp-8h]
	int xLeft;           // [esp+14h] [ebp-4h]
	int v13;             // [esp+1Ch] [ebp+4h]

	v1 = a1;
	v2 = *(_WORD*)(a1 + 32);
	v3 = *(_DWORD*)(a1 + 32) >> 16;
	nox_client_wndGetPosition_46AA60((_DWORD*)a1, &xLeft, &yTop);
	v4 = *(_DWORD*)(a1 + 20);
	v5 = *(_DWORD*)(a1 + 16);
	v6 = (unsigned __int16)v3 + 32 * v2;
	v13 = *(_DWORD*)(a1 + 28) - v4;
	v7 = *(_DWORD*)(v1 + 24) - v5;
	LOBYTE(v5) = byte_5D4594[3 * v6 + 1307798];
	LOBYTE(v4) = byte_5D4594[3 * v6 + 1307797];
	v10 = v5;
	LOBYTE(v5) = byte_5D4594[3 * v6 + 1307796];
	v8 = sub_4344A0(v5, v4, v10);
	nox_client_drawSetColor_434460(v8);
	nox_client_drawRectFilledOpaque_49CE30(xLeft, yTop, v7, v13);
	return 1;
}

//----- (004A6DC0) --------------------------------------------------------
int __cdecl sub_4A6DC0(_DWORD* a1, int a2) {
	int v1;   // eax
	int v2;   // ecx
	int v3;   // edx
	int v4;   // esi
	int v5;   // eax
	int v6;   // ecx
	int v7;   // edx
	int v8;   // eax
	int v9;   // edx
	int v10;  // eax
	int v11;  // ecx
	int v12;  // eax
	int v13;  // edx
	int v14;  // ecx
	int v15;  // eax
	int v16;  // eax
	int v17;  // edx
	int v18;  // ecx
	int v19;  // eax
	int v20;  // eax
	int v21;  // ebx
	int v22;  // eax
	int v23;  // edx
	int* v24; // ebp
	int v25;  // ecx
	int v26;  // eax
	int v27;  // edi
	int i;    // esi
	int v29;  // eax
	int v30;  // eax
	int v31;  // ecx
	int v32;  // eax
	int v33;  // edi
	int j;    // esi
	int v35;  // eax
	int v36;  // eax
	int v37;  // ecx
	int v38;  // eax
	int v39;  // eax
	int v40;  // ecx
	int v41;  // edx
	int v42;  // edi
	int k;    // esi
	int v44;  // eax
	int v45;  // eax
	int v46;  // ecx
	int v47;  // eax
	int v48;  // eax
	int v49;  // ecx
	int v50;  // edx
	int v52;  // [esp-24h] [ebp-3Ch]
	int v53;  // [esp-24h] [ebp-3Ch]
	int v54;  // [esp+10h] [ebp-8h]
	int v55;  // [esp+14h] [ebp-4h]

	nox_client_wndGetPosition_46AA60(a1, &v54, &v55);
	v1 = ((unsigned __int16)(*(_DWORD*)(dword_5d4594_1308096 + 32) >> 16)) +
		 32 * *(unsigned __int16*)(dword_5d4594_1308096 + 32);
	v2 = byte_5D4594[3 * v1 + 1307798];
	LOBYTE(v3) = byte_5D4594[3 * v1 + 1307797];
	LOBYTE(v1) = byte_5D4594[3 * v1 + 1307796];
	v4 = sub_4344A0(v1, v3, v2);
	sub_4341D0(6, v4);
	v5 = ((unsigned __int16)(*(_DWORD*)(dword_5d4594_1308100 + 32) >> 16)) +
		 32 * *(unsigned __int16*)(dword_5d4594_1308100 + 32);
	v6 = byte_5D4594[3 * v5 + 1307798];
	LOBYTE(v7) = byte_5D4594[3 * v5 + 1307797];
	LOBYTE(v5) = byte_5D4594[3 * v5 + 1307796];
	v8 = sub_4344A0(v5, v7, v6);
	sub_4341D0(1, v8);
	v9 = dword_5d4594_1308144;
	if (*(_BYTE*)(dword_5d4594_1308144 + 4) & 8) {
		v10 = (unsigned __int16)(*(_DWORD*)(dword_5d4594_1308108 + 32) >> 16);
		v11 = v10 + 32 * *(unsigned __int16*)(dword_5d4594_1308108 + 32);
		LOBYTE(v9) = byte_5D4594[3 * v11 + 1307797];
		v12 = sub_4344A0(byte_5D4594[3 * v11 + 1307796], v9,
						 byte_5D4594[3 * (v10 + 32 * *(unsigned __int16*)(dword_5d4594_1308108 + 32)) + 1307798]);
		sub_4341D0(2, v12);
	} else {
		sub_4341D0(2, v4);
	}
	sub_4341D0(3, v4);
	v13 = dword_5d4594_1308148;
	if (*(_BYTE*)(dword_5d4594_1308148 + 4) & 8) {
		v14 = (unsigned __int16)(*(_DWORD*)(dword_5d4594_1308112 + 32) >> 16);
		v15 = v14 + 32 * *(unsigned __int16*)(dword_5d4594_1308112 + 32);
		LOBYTE(v13) = byte_5D4594[3 * v15 + 1307797];
		LOBYTE(v15) = byte_5D4594[3 * v15 + 1307796];
		v16 = sub_4344A0(v15, v13,
						 byte_5D4594[3 * (v14 + 32 * *(unsigned __int16*)(dword_5d4594_1308112 + 32)) + 1307798]);
		sub_4341D0(4, v16);
	} else {
		sub_4341D0(4, v4);
	}
	v17 = dword_5d4594_1308140;
	if (*(_BYTE*)(dword_5d4594_1308140 + 4) & 8) {
		v18 = (unsigned __int16)(*(_DWORD*)(dword_5d4594_1308104 + 32) >> 16);
		v19 = v18 + 32 * *(unsigned __int16*)(dword_5d4594_1308104 + 32);
		LOBYTE(v17) = byte_5D4594[3 * v19 + 1307797];
		LOBYTE(v19) = byte_5D4594[3 * v19 + 1307796];
		v20 = sub_4344A0(v19, v17,
						 byte_5D4594[3 * (v18 + 32 * *(unsigned __int16*)(dword_5d4594_1308104 + 32)) + 1307798]);
		sub_4341D0(5, v20);
	} else {
		sub_4341D0(5, v4);
	}
	if (*(_BYTE*)(dword_5d4594_1308136 + 4) & 8)
		nox_client_drawImageAt_47D2C0(
			*(_DWORD*)&byte_5D4594[4 * *(unsigned __int8*)(dword_5d4594_1307784 + 67) + 3798172], v54, v55);
	else
		nox_client_drawImageAt_47D2C0(
			*(_DWORD*)&byte_5D4594[4 * *(unsigned __int8*)(dword_5d4594_1307784 + 67) + 3798180], v54, v55);
	v21 = 0;
	v22 = *(unsigned __int8*)(dword_5d4594_1307784 + 67);
	v23 = 3 * v22;
	v24 = (int*)&byte_5D4594[104 * v22 + 3798188];
	do {
		v25 = v21;
		v26 = 1 << v21;
		if (1 << v21 == 4) {
			v27 = 1;
			for (i = 3; i < 21; i += 3) {
				v29 = dword_5d4594_1308156;
				LOBYTE(v25) = *(_BYTE*)(i + dword_5d4594_1308156 + 14);
				LOBYTE(v23) = *(_BYTE*)(i + dword_5d4594_1308156 + 13);
				LOBYTE(v29) = *(_BYTE*)(i + dword_5d4594_1308156 + 12);
				sub_4340A0(v27++, v29, v23, v25);
			}
			v30 = ((unsigned __int16)(*(_DWORD*)(dword_5d4594_1308116 + 32) >> 16)) +
				  32 * *(unsigned __int16*)(dword_5d4594_1308116 + 32);
			v31 = byte_5D4594[3 * v30 + 1307798];
			LOBYTE(v23) = byte_5D4594[3 * v30 + 1307797];
			LOBYTE(v30) = byte_5D4594[3 * v30 + 1307796];
			v32 = sub_4344A0(v30, v23, v31);
			sub_4341D0(*(_DWORD*)(dword_5d4594_1308156 + 40), v32);
		} else if (v26 == 1024) {
			v33 = 1;
			for (j = 3; j < 21; j += 3) {
				v35 = dword_5d4594_1308160;
				LOBYTE(v25) = *(_BYTE*)(dword_5d4594_1308160 + j + 14);
				LOBYTE(v23) = *(_BYTE*)(dword_5d4594_1308160 + j + 13);
				LOBYTE(v35) = *(_BYTE*)(dword_5d4594_1308160 + j + 12);
				sub_4340A0(v33++, v35, v23, v25);
			}
			v36 = ((unsigned __int16)(*(_DWORD*)(dword_5d4594_1308120 + 32) >> 16)) +
				  32 * *(unsigned __int16*)(dword_5d4594_1308120 + 32);
			v37 = byte_5D4594[3 * v36 + 1307798];
			LOBYTE(v23) = byte_5D4594[3 * v36 + 1307797];
			LOBYTE(v36) = byte_5D4594[3 * v36 + 1307796];
			v38 = sub_4344A0(v36, v23, v37);
			sub_4341D0(*(_DWORD*)(dword_5d4594_1308160 + 40), v38);
			v39 = ((unsigned __int16)(*(_DWORD*)(dword_5d4594_1308124 + 32) >> 16)) +
				  32 * *(unsigned __int16*)(dword_5d4594_1308124 + 32);
			v40 = byte_5D4594[3 * v39 + 1307798];
			LOBYTE(v41) = byte_5D4594[3 * v39 + 1307797];
			LOBYTE(v39) = byte_5D4594[3 * v39 + 1307796];
			v52 = sub_4344A0(v39, v41, v40);
			sub_4341D0(*(_DWORD*)(dword_5d4594_1308160 + 44), v52);
		} else {
			if (v26 != 1)
				goto LABEL_27;
			v42 = 1;
			for (k = 3; k < 21; k += 3) {
				v44 = dword_5d4594_1308164;
				LOBYTE(v25) = *(_BYTE*)(k + dword_5d4594_1308164 + 14);
				LOBYTE(v23) = *(_BYTE*)(k + dword_5d4594_1308164 + 13);
				LOBYTE(v44) = *(_BYTE*)(k + dword_5d4594_1308164 + 12);
				sub_4340A0(v42++, v44, v23, v25);
			}
			v45 = ((unsigned __int16)(*(_DWORD*)(dword_5d4594_1308128 + 32) >> 16)) +
				  32 * *(unsigned __int16*)(dword_5d4594_1308128 + 32);
			v46 = byte_5D4594[3 * v45 + 1307798];
			LOBYTE(v23) = byte_5D4594[3 * v45 + 1307797];
			LOBYTE(v45) = byte_5D4594[3 * v45 + 1307796];
			v47 = sub_4344A0(v45, v23, v46);
			sub_4341D0(*(_DWORD*)(dword_5d4594_1308164 + 40), v47);
			v48 = ((unsigned __int16)(*(_DWORD*)(dword_5d4594_1308132 + 32) >> 16)) +
				  32 * *(unsigned __int16*)(dword_5d4594_1308132 + 32);
			v49 = byte_5D4594[3 * v48 + 1307798];
			LOBYTE(v50) = byte_5D4594[3 * v48 + 1307797];
			LOBYTE(v48) = byte_5D4594[3 * v48 + 1307796];
			v53 = sub_4344A0(v48, v50, v49);
			sub_4341D0(*(_DWORD*)(dword_5d4594_1308164 + 36), v53);
		}
		nox_client_drawImageAt_47D2C0(*v24, v54, v55);
	LABEL_27:
		++v21;
		++v24;
	} while (v21 < 26);
	return 1;
}
// 4A6E13: variable 'v3' is possibly undefined
// 4A6E5A: variable 'v7' is possibly undefined
// 4A7032: variable 'v23' is possibly undefined
// 4A7032: variable 'v25' is possibly undefined
// 4A7158: variable 'v41' is possibly undefined
// 4A7227: variable 'v50' is possibly undefined

//----- (004A7270) --------------------------------------------------------
int __cdecl sub_4A7270(int a1, int a2, unsigned int a3, int a4) {
	int v3;  // eax
	int2 v5; // [esp+0h] [ebp-8h]

	if (a2 != 5)
		return 0;
	v5.field_4 = a3 >> 16;
	v5.field_0 = (unsigned __int16)a3;
	v3 = sub_4281F0(&v5, (int4*)(a1 + 16));
	if (v3)
		return 0;
	sub_4A72D0(0xDEADu);
	return 1;
}
// 4A72AA: variable 'v3' is possibly undefined

//----- (004A72D0) --------------------------------------------------------
_DWORD* __cdecl sub_4A72D0(unsigned __int16 a1) {
	_DWORD* result; // eax

	sub_46C6E0(*(int*)&dword_5d4594_1308088);
	result = (_DWORD*)nox_window_set_hidden(*(int*)&dword_5d4594_1308088, 1);
	if (a1 < 0x20u) {
		result = sub_46B0C0(*(_DWORD**)&dword_5d4594_1308088, *(int*)&dword_5d4594_1307792);
		if (result)
			result[8] = *(unsigned __int16*)&byte_5D4594[1307788] | (a1 << 16);
	}
	return result;
}

//----- (004A7330) --------------------------------------------------------
int __cdecl sub_4A7330(int a1, int a2, int* a3, unsigned int a4) {
	int result; // eax
	int v5;     // edi
	int v6;     // eax
	_DWORD* v7; // eax

	if (a2 == 16389) {
		sub_452D80(920, 100);
		result = 1;
	} else if (a2 == 16391) {
		v5 = a4 >> 16;
		v6 = sub_46B0A0(a3);
		switch (v6) {
		case 720:
			dword_5d4594_1307792 = v6;
			sub_4A7530(2u);
			sub_4A7580((unsigned __int16)a4, v5);
			break;
		case 721:
		case 722:
		case 723:
		case 724:
			dword_5d4594_1307792 = v6;
			sub_4A7530(1u);
			sub_4A7580((unsigned __int16)a4, v5);
			break;
		case 725:
		case 726:
		case 727:
		case 728:
		case 729:
			dword_5d4594_1307792 = v6;
			sub_4A7530(0);
			sub_4A7580((unsigned __int16)a4, v5);
			break;
		case 731:
		case 732:
		case 733:
		case 734:
			v7 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1308084, v6 - 20);
			if (v7)
				sub_46ABB0((int)v7, ((unsigned int)~v7[1] >> 3) & 1);
			break;
		case 761:
		case 762:
		case 763:
		case 764:
		case 765:
		case 766:
		case 767:
		case 768:
		case 769:
		case 770:
		case 771:
		case 772:
		case 773:
		case 774:
		case 775:
		case 776:
		case 777:
		case 778:
		case 779:
		case 780:
		case 781:
		case 782:
		case 783:
		case 784:
		case 785:
		case 786:
		case 787:
		case 788:
		case 789:
		case 790:
		case 791:
		case 792:
			sub_4A72D0(v6 - 761);
			break;
		case 799:
			if (*(_DWORD*)&byte_5D4594[1308168] == 1)
				sub_43BDC0();
			sub_43BDC0();
			sub_43BDC0();
			dword_587000_171388 = 1;
			if (sub_4A75C0()) {
				if (*(_BYTE*)(dword_5d4594_1307784 + 66)) {
					if (*(_BYTE*)(dword_5d4594_1307784 + 66) == 1) {
						sub_409D70((char*)&byte_587000[171628]);
					} else if (*(_BYTE*)(dword_5d4594_1307784 + 66) == 2) {
						sub_409D70((char*)&byte_587000[171640]);
					}
				} else {
					sub_409D70((char*)&byte_587000[171616]);
				}
				sub_4A24C0(0);
				sub_4A6890();
				*(_DWORD*)(dword_5d4594_1308092 + 52) = 0;
			}
			break;
		default:
			break;
		}
		sub_452D80(921, 100);
		result = 1;
	} else {
		result = 0;
	}
	return result;
}

//----- (004A7530) --------------------------------------------------------
_DWORD* __cdecl sub_4A7530(unsigned __int16 a1) {
	int v1;         // esi
	_DWORD* result; // eax

	v1 = 761;
	*(_DWORD*)&byte_5D4594[1307788] = a1;
	do {
		result = sub_46B0C0(*(_DWORD**)&dword_5d4594_1308088, v1);
		if (result)
			result[8] = a1 | ((unsigned __int16)(v1 - 761) << 16);
		++v1;
	} while (v1 <= 792);
	return result;
}

//----- (004A7580) --------------------------------------------------------
int __cdecl sub_4A7580(int a1, int a2) {
	sub_46A8C0(*(int*)&dword_5d4594_1308088);
	sub_46C690(*(int*)&dword_5d4594_1308088);
	return nox_wnd_sub_46A9B0(*(_DWORD**)&dword_5d4594_1308088, a1 - *(_DWORD*)(dword_5d4594_1308088 + 8),
							  a2 - *(_DWORD*)(dword_5d4594_1308088 + 12) / 2);
}

//----- (004A7A60) --------------------------------------------------------
int __cdecl sub_4A7A60(int a1) {
	int result; // eax

	result = a1;
	dword_587000_171388 = a1;
	return result;
}

//----- (004A7A70) --------------------------------------------------------
int __cdecl sub_4A7A70(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[1308168] = a1;
	return result;
}

//----- (004A7A80) --------------------------------------------------------
int __cdecl sub_4A7A80(const char* a1) {
	int result;          // eax
	unsigned int v2;     // ecx
	char v3;             // al
	unsigned __int8* v4; // edi
	const char* v5;      // esi

	if (!a1)
		return 0;
	v2 = strlen(a1) + 1;
	v3 = v2;
	v2 >>= 2;
	qmemcpy(&byte_5D4594[1308644], a1, 4 * v2);
	v5 = &a1[4 * v2];
	v4 = &byte_5D4594[4 * v2 + 1308644];
	LOBYTE(v2) = v3;
	result = 1;
	qmemcpy(v4, v5, v2 & 3);
	return result;
}

//----- (004A7AC0) --------------------------------------------------------
int __cdecl sub_4A7AC0(const char* a1) {
	int result;          // eax
	unsigned int v2;     // ecx
	char v3;             // al
	unsigned __int8* v4; // edi
	const char* v5;      // esi

	if (!a1)
		return 0;
	v2 = strlen(a1) + 1;
	v3 = v2;
	v2 >>= 2;
	qmemcpy(&byte_5D4594[1308172], a1, 4 * v2);
	v5 = &a1[4 * v2];
	v4 = &byte_5D4594[4 * v2 + 1308172];
	LOBYTE(v2) = v3;
	result = 1;
	qmemcpy(v4, v5, v2 & 3);
	return result;
}

//----- (004A7B00) --------------------------------------------------------
int __cdecl sub_4A7B00(const char* a1) {
	int result;          // eax
	unsigned int v2;     // ecx
	char v3;             // al
	unsigned __int8* v4; // edi
	const char* v5;      // esi

	if (!a1)
		return 0;
	v2 = strlen(a1) + 1;
	v3 = v2;
	v2 >>= 2;
	qmemcpy(&byte_5D4594[1308352], a1, 4 * v2);
	v5 = &a1[4 * v2];
	v4 = &byte_5D4594[4 * v2 + 1308352];
	LOBYTE(v2) = v3;
	result = 1;
	qmemcpy(v4, v5, v2 & 3);
	return result;
}

//----- (004A7B40) --------------------------------------------------------
int __cdecl sub_4A7B40(char* a1) {
	const char* v2;      // eax
	int v3;              // edi
	unsigned __int8* v4; // esi

	if (!a1)
		return 0;
	v2 = *(const char**)&byte_587000[171856];
	v3 = 0;
	if (*(_DWORD*)&byte_587000[171856]) {
		v4 = &byte_587000[171856];
		while (_strcmpi(v2, a1)) {
			v2 = (const char*)*((_DWORD*)v4 + 2);
			v4 += 8;
			++v3;
			if (!v2)
				return 1;
		}
		*(_DWORD*)&byte_5D4594[1308184] = *(_DWORD*)&byte_587000[8 * v3 + 171860];
	}
	return 1;
}

//----- (004A7BA0) --------------------------------------------------------
int __cdecl sub_4A7BA0(char* a1) {
	int result; // eax

	result = (int)a1;
	if (a1) {
		*(_DWORD*)&byte_5D4594[1308740] = atoi(a1);
		result = 1;
	}
	return result;
}

//----- (004A7BC0) --------------------------------------------------------
int __cdecl sub_4A7BC0(const char* a1) {
	int result;          // eax
	unsigned int v2;     // ecx
	char v3;             // al
	unsigned __int8* v4; // edi
	const char* v5;      // esi

	if (!a1)
		return 0;
	v2 = strlen(a1) + 1;
	v3 = v2;
	v2 >>= 2;
	qmemcpy(&byte_5D4594[1308324], a1, 4 * v2);
	v5 = &a1[4 * v2];
	v4 = &byte_5D4594[4 * v2 + 1308324];
	LOBYTE(v2) = v3;
	result = 1;
	qmemcpy(v4, v5, v2 & 3);
	return result;
}

//----- (004A7C00) --------------------------------------------------------
int __cdecl sub_4A7C00(const char* a1) {
	int result;          // eax
	unsigned int v2;     // ecx
	char v3;             // al
	unsigned __int8* v4; // edi
	const char* v5;      // esi

	if (!a1)
		return 0;
	v2 = strlen(a1) + 1;
	v3 = v2;
	v2 >>= 2;
	qmemcpy(&byte_5D4594[1308364], a1, 4 * v2);
	v5 = &a1[4 * v2];
	v4 = &byte_5D4594[4 * v2 + 1308364];
	LOBYTE(v2) = v3;
	result = 1;
	qmemcpy(v4, v5, v2 & 3);
	return result;
}

//----- (004A7C40) --------------------------------------------------------
int __cdecl sub_4A7C40(char* a1) {
	int result; // eax

	result = (int)a1;
	if (a1) {
		*(_DWORD*)&byte_5D4594[1308188] = atoi(a1);
		result = 1;
	}
	return result;
}

//----- (004A7C60) --------------------------------------------------------
int __cdecl sub_4A7C60(char* a1) {
	char* v1;   // eax
	char* v2;   // eax
	int result; // eax

	if (!a1)
		goto LABEL_12;
	*(_DWORD*)&byte_5D4594[1308736] = 0;
	*(_DWORD*)&byte_5D4594[1308732] = 0;
	v1 = strtok(a1, ",\t\r\n");
	if (v1)
		*(_DWORD*)&byte_5D4594[1308732] = atoi(v1);
	v2 = strtok(0, " \t\r\n");
	if (v2)
		*(_DWORD*)&byte_5D4594[1308736] = atoi(v2);
	if (*(_DWORD*)&byte_5D4594[1308732] && *(_DWORD*)&byte_5D4594[1308736])
		result = 1;
	else
	LABEL_12:
		result = 0;
	return result;
}

//----- (004A7CE0) --------------------------------------------------------
int __cdecl sub_4A7CE0(char* a1) {
	int result; // eax

	result = (int)a1;
	if (a1) {
		*(_DWORD*)&byte_5D4594[1308728] = atoi(a1);
		result = 1;
	}
	return result;
}

//----- (004A7D00) --------------------------------------------------------
int __cdecl sub_4A7D00(const char* a1) {
	int result;          // eax
	unsigned int v2;     // ecx
	char v3;             // al
	unsigned __int8* v4; // edi
	const char* v5;      // esi

	if (!a1)
		return 0;
	result = 0;
	if (strlen(a1) <= 0x80) {
		v2 = strlen(a1) + 1;
		v3 = v2;
		v2 >>= 2;
		qmemcpy(&byte_5D4594[1308192], a1, 4 * v2);
		v5 = &a1[4 * v2];
		v4 = &byte_5D4594[4 * v2 + 1308192];
		LOBYTE(v2) = v3;
		result = 1;
		qmemcpy(v4, v5, v2 & 3);
	}
	return result;
}

//----- (004A7D50) --------------------------------------------------------
int __cdecl sub_4A7D50(char* a1) {
	int result; // eax

	result = (int)a1;
	if (a1) {
		*(_DWORD*)&byte_5D4594[1308348] = atoi(a1);
		result = 1;
	}
	return result;
}

//----- (004A7D70) --------------------------------------------------------
int __cdecl sub_4A7D70(char* a1) {
	int result; // eax
	FILE* v2;   // eax
	FILE* v3;   // esi

	result = (int)a1;
	if (a1) {
		v2 = fopen(a1, "r");
		v3 = v2;
		if (!v2)
			return 0;
		fgets((char*)&byte_5D4594[1308388], 256, v2);
		if (!feof(v3)) {
			while (sub_4A7DF0((char*)&byte_5D4594[1308388])) {
				fgets((char*)&byte_5D4594[1308388], 256, v3);
				if (feof(v3))
					break;
			}
			return 0;
		}
		fclose(v3);
		result = 1;
	}
	return result;
}

//----- (004A7DF0) --------------------------------------------------------
int __cdecl sub_4A7DF0(char* a1) {
	char* v1;       // ebx
	int v2;         // edi
	const char* v3; // esi
	char* v5;       // eax

	v1 = strtok(a1, " \t\r\n");
	if (!v1)
		return 0;
	v2 = 0;
	v3 = "MAP";
	while (_strcmpi(v1, v3) || !strtok(0, " \t\r\n")) {
		v3 += 20;
		++v2;
		if ((int)v3 >= (int)&byte_587000[172172])
			return 0;
	}
	v5 = strtok(0, "\t\r\n");
	(*(void(__cdecl**)(const char*)) & byte_587000[20 * v2 + 171928])(v5);
	return 1;
}

//----- (004A7E70) --------------------------------------------------------
char* sub_4A7E70() { return (char*)&byte_5D4594[1308644]; }

//----- (004A7E80) --------------------------------------------------------
char* sub_4A7E80() { return (char*)&byte_5D4594[1308172]; }

//----- (004A7E90) --------------------------------------------------------
char* sub_4A7E90() { return (char*)&byte_5D4594[1308352]; }

//----- (004A7EA0) --------------------------------------------------------
int sub_4A7EA0() { return *(_DWORD*)&byte_5D4594[1308184]; }

//----- (004A7EB0) --------------------------------------------------------
int sub_4A7EB0() { return *(_DWORD*)&byte_5D4594[1308740]; }

//----- (004A7EC0) --------------------------------------------------------
char* sub_4A7EC0() { return (char*)&byte_5D4594[1308324]; }

//----- (004A7ED0) --------------------------------------------------------
char* sub_4A7ED0() { return (char*)&byte_5D4594[1308364]; }

//----- (004A7EE0) --------------------------------------------------------
int sub_4A7EE0() { return *(_DWORD*)&byte_5D4594[1308188]; }

//----- (004A7EF0) --------------------------------------------------------
char* sub_4A7EF0() { return (char*)&byte_5D4594[1308732]; }

//----- (004A7F00) --------------------------------------------------------
int sub_4A7F00() { return *(_DWORD*)&byte_5D4594[1308728]; }

//----- (004A7F10) --------------------------------------------------------
char* sub_4A7F10() { return (char*)&byte_5D4594[1308192]; }

//----- (004A7F20) --------------------------------------------------------
int sub_4A7F20() { return *(_DWORD*)&byte_5D4594[1308348]; }

//----- (004A7F30) --------------------------------------------------------
int sub_4A7F30() { return *(_DWORD*)&byte_5D4594[1308744]; }

//----- (004A7F40) --------------------------------------------------------
int __cdecl sub_4A7F40(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[1308744] = a1;
	return result;
}

//----- (004A7F50) --------------------------------------------------------
int __cdecl sub_4A7F50(_DWORD* a1, int a2, int a3, int a4) {
	int v4;      // eax
	int v5;      // eax
	int result;  // eax
	int v7;      // eax
	int v8;      // eax
	int v9;      // eax
	_DWORD* v10; // esi
	int v11;     // eax
	int v12;     // [esp-10h] [ebp-14h]

	switch (a2) {
	case 5:
	LABEL_9:
		a1[9] |= 4u;
		return 1;
	case 6:
	case 7:
		v10 = a1;
		if (!(a1[9] & 4))
			goto LABEL_22;
		nox_window_call_field_94(a1[13], 16391, (int)a1, a3);
		goto LABEL_16;
	case 8:
		nox_window_call_field_94(a1[13], 0x4000, (int)a1, a3);
		return 1;
	case 17:
		v4 = a1[11];
		if (!(v4 & 0x100))
			goto LABEL_21;
		v5 = a1[13];
		a1[9] |= 2u;
		nox_window_call_field_94(v5, 16389, (int)a1, a3);
		sub_46B500((int)a1);
		result = 1;
		break;
	case 18:
		v7 = a1[11];
		if (v7 & 0x100) {
			v8 = a1[9];
			LOBYTE(v8) = v8 & 0xFD;
			v12 = a1[13];
			a1[9] = v8;
			nox_window_call_field_94(v12, 16390, (int)a1, a3);
		}
		v9 = a1[9];
		if (v9 & 4) {
			LOBYTE(v9) = v9 & 0xFB;
			a1[9] = v9;
			result = 1;
		} else {
		LABEL_21:
			result = 1;
		}
		break;
	case 21:
		switch (a3) {
		case 15:
		case 205:
		case 208:
			if (a4 != 2)
				goto LABEL_21;
			sub_46A8A0();
			return 1;
		case 28:
		case 57:
			if (a4 != 1)
				goto LABEL_9;
			v10 = a1;
			if (!(a1[9] & 4))
				goto LABEL_21;
			nox_window_call_field_94(a1[13], 16391, (int)a1, 0);
			break;
		case 200:
		case 203:
			if (a4 == 2)
				sub_46A8B0();
			goto LABEL_21;
		default:
			goto LABEL_22;
		}
	LABEL_16:
		v11 = v10[9];
		LOBYTE(v11) = v11 & 0xFB;
		v10[9] = v11;
		result = 1;
		break;
	default:
	LABEL_22:
		result = 0;
		break;
	}
	return result;
}

//----- (004A81D0) --------------------------------------------------------
int __cdecl sub_4A81D0(int a1, int a2) {
	int v2;    // esi
	int v3;    // ebx
	int v4;    // edi
	int v5;    // edi
	int v6;    // ebx
	int v7;    // eax
	int v9;    // [esp-8h] [ebp-20h]
	int xLeft; // [esp+10h] [ebp-8h]
	int yTop;  // [esp+14h] [ebp-4h]

	v2 = a2;
	v3 = *(_DWORD*)(a2 + 28);
	v4 = *(_DWORD*)(a2 + 20);
	nox_client_wndGetPosition_46AA60((_DWORD*)a1, &xLeft, &yTop);
	if (*(_BYTE*)(a1 + 4) & 8) {
		if (*(_DWORD*)v2 & 4) {
			v4 = *(_DWORD*)(v2 + 52);
		} else if (*(_DWORD*)v2 & 2) {
			v3 = *(_DWORD*)(v2 + 36);
		}
	} else {
		v4 = *(_DWORD*)(v2 + 44);
	}
	if (v3 != 0x80000000) {
		nox_client_drawSetColor_434460(v3);
		nox_client_drawBorderLines_49CC70(xLeft, yTop, *(_DWORD*)(a1 + 8), *(_DWORD*)(a1 + 12));
	}
	if (v4 != 0x80000000) {
		nox_client_drawSetColor_434460(v4);
		nox_client_drawRectFilledOpaque_49CE30(xLeft + 1, yTop + 1, *(_DWORD*)(a1 + 8) - 2, *(_DWORD*)(a1 + 12) - 2);
	}
	if (*(_WORD*)(v2 + 72)) {
		v5 = xLeft + *(_DWORD*)(a1 + 8) / 2;
		v6 = yTop + *(_DWORD*)(a1 + 12) / 2;
		if ((*(_DWORD*)(a1 + 4) & 0x2000) == 0x2000)
			sub_43F670(1);
		sub_43F840(*(_DWORD*)(v2 + 200), (unsigned __int16*)(v2 + 72), &a2, 0, 0);
		if (*(_DWORD*)(v2 + 68) != 0x80000000) {
			sub_434390(*(_DWORD*)(v2 + 68));
			v9 = *(_DWORD*)(a1 + 8);
			v7 = sub_43F320(*(_DWORD*)(v2 + 200));
			sub_43FAF0(*(_DWORD*)(v2 + 200), (_WORD*)(v2 + 72), v5 - a2 / 2, v6 - v7 / 2, v9, 0);
		}
		sub_43F670(0);
	}
	return 1;
}

//----- (004A8340) --------------------------------------------------------
int __cdecl sub_4A8340(int a1) {
	int result; // eax

	if ((signed char)*(_BYTE*)(a1 + 4) >= 0)
		result = nox_window_set_all_funcs((_DWORD*)a1, sub_4A7F50, sub_4A81D0, 0);
	else
		result = nox_window_set_all_funcs((_DWORD*)a1, sub_4A7F50, sub_4A8380, 0);
	return result;
}

//----- (004A8380) --------------------------------------------------------
int __cdecl sub_4A8380(_DWORD* a1, int a2) {
	int v2;     // esi
	_DWORD* v3; // edi
	int v4;     // ebx
	int v5;     // ebp
	int v6;     // kr04_4
	int v7;     // eax
	int v8;     // eax
	int v10;    // [esp-8h] [ebp-1Ch]
	int v11;    // [esp+10h] [ebp-4h]

	v2 = a2;
	v3 = a1;
	v4 = *(_DWORD*)(a2 + 32);
	v5 = *(_DWORD*)(a2 + 24);
	nox_client_wndGetPosition_46AA60(a1, &a1, &a2);
	if (v3[1] & 8) {
		if (*(_DWORD*)v2 & 4) {
			v4 = *(_DWORD*)(v2 + 56);
		} else if (*(_DWORD*)v2 & 2) {
			v4 = *(_DWORD*)(v2 + 40);
		}
	} else {
		v5 = *(_DWORD*)(v2 + 48);
	}
	if (v5)
		nox_client_drawImageAt_47D2C0(v5, (int)a1 + v3[24], a2 + v3[25]);
	if (v4)
		nox_client_drawImageAt_47D2C0(v4, (int)a1 + v3[24], a2 + v3[25]);
	if (*(_WORD*)(v2 + 72)) {
		v6 = v3[3];
		a1 = (_DWORD*)((char*)a1 + v3[2] / 2);
		v7 = v3[1] & 0x2000;
		a2 += v6 / 2;
		if (v7 == 0x2000)
			sub_43F670(1);
		sub_43F840(*(_DWORD*)(v2 + 200), (unsigned __int16*)(v2 + 72), &v11, 0, 0);
		if (*(_DWORD*)(v2 + 68) != 0x80000000) {
			sub_434390(*(_DWORD*)(v2 + 68));
			v10 = v3[2];
			v8 = sub_43F320(*(_DWORD*)(v2 + 200));
			sub_43FAF0(*(_DWORD*)(v2 + 200), (_WORD*)(v2 + 72), (int)a1 - v11 / 2, a2 - v8 / 2, v10, 0);
		}
		sub_43F670(0);
	}
	return 1;
}

//----- (004A84E0) --------------------------------------------------------
int __cdecl sub_4A84E0(_DWORD* a1, int a2, int a3, int a4) {
	int v4;     // eax
	int v5;     // eax
	int result; // eax
	int v7;     // ecx
	int v8;     // edx
	int v9;     // eax
	int v10;    // edi
	_DWORD* i;  // eax
	int v12;    // eax
	int v13;    // edi
	_DWORD* j;  // eax

	switch (a2) {
	case 5:
		goto LABEL_31;
	case 6:
	case 7:
		v9 = a1[9];
		v10 = a1[99];
		if (v9 & 4) {
			if (v9 & 2)
			LABEL_31:
				result = 1;
			else
			LABEL_16:
				result = 0;
		} else {
			nox_window_call_field_94(a1[13], 16391, (int)a1, a3);
			if (v10) {
				for (i = *(_DWORD**)(v10 + 400); i; i = (_DWORD*)i[97]) {
					if (i != a1 && i[10] == a1[10])
						i[9] &= 0xFFFFFFFB;
				}
			}
			v12 = a1[9];
			LOBYTE(v12) = v12 | 4;
			a1[9] = v12;
			result = 1;
		}
		break;
	case 8:
		nox_window_call_field_94(a1[13], 0x4000, (int)a1, a3);
		return 1;
	case 17:
		v4 = a1[11];
		if (!(v4 & 0x100))
			goto LABEL_31;
		v5 = a1[9];
		LOBYTE(v5) = v5 | 2;
		a1[9] = v5;
		nox_window_call_field_94(a1[13], 16389, (int)a1, a3);
		sub_46B500((int)a1);
		result = 1;
		break;
	case 18:
		v7 = a1[11];
		if (!(v7 & 0x100))
			goto LABEL_31;
		v8 = a1[13];
		a1[9] &= 0xFFFFFFFD;
		nox_window_call_field_94(v8, 16390, (int)a1, a3);
		result = 1;
		break;
	case 21:
		switch (a3) {
		case 15:
		case 205:
		case 208:
			if (a4 != 2)
				goto LABEL_31;
			sub_46A8A0();
			result = 1;
			break;
		case 28:
		case 57:
			if (a4 != 2)
				goto LABEL_31;
			v13 = a1[99];
			if (a1[9] & 4)
				goto LABEL_31;
			nox_window_call_field_94(a1[13], 16391, (int)a1, 0);
			if (v13) {
				for (j = *(_DWORD**)(v13 + 400); j; j = (_DWORD*)j[97]) {
					if (j != a1 && j[10] == a1[10])
						j[9] &= 0xFFFFFFFB;
				}
			}
			a1[9] ^= 4u;
			result = 1;
			break;
		case 200:
		case 203:
			if (a4 == 2)
				sub_46A8B0();
			goto LABEL_31;
		default:
			goto LABEL_16;
		}
		return result;
	default:
		goto LABEL_16;
	}
	return result;
}

//----- (004A87E0) --------------------------------------------------------
int __cdecl sub_4A87E0(int a1) {
	int result; // eax

	if ((signed char)*(_BYTE*)(a1 + 4) >= 0)
		result = nox_window_set_all_funcs((_DWORD*)a1, sub_4A84E0, sub_4A8820, 0);
	else
		result = nox_window_set_all_funcs((_DWORD*)a1, sub_4A84E0, sub_4A8A20, 0);
	return result;
}

//----- (004A8820) --------------------------------------------------------
int __cdecl sub_4A8820(int a1, int a2) {
	int v2;  // esi
	int v3;  // ebx
	int v4;  // ebp
	int v5;  // edi
	int v6;  // eax
	int v7;  // edi
	int v8;  // eax
	int v9;  // eax
	int v11; // [esp-8h] [ebp-28h]
	int v12; // [esp+10h] [ebp-10h]
	int v13; // [esp+14h] [ebp-Ch]
	int v14; // [esp+18h] [ebp-8h]
	int v15; // [esp+1Ch] [ebp-4h]

	v2 = a2;
	v3 = a1;
	v12 = *(_DWORD*)(a2 + 28);
	a2 = *(_DWORD*)(a2 + 20);
	nox_client_wndGetPosition_46AA60((_DWORD*)a1, &v14, &v15);
	if (*(_BYTE*)(v3 + 4) & 8) {
		if (*(_BYTE*)v2 & 2)
			v12 = *(_DWORD*)(v2 + 36);
	} else {
		a2 = *(_DWORD*)(v2 + 44);
	}
	v4 = v14 + 4;
	v5 = *(_DWORD*)(v3 + 12) / 2 + v15 - 5;
	v13 = sub_43F320(*(_DWORD*)(v2 + 200));
	if (a2 != 0x80000000) {
		nox_client_drawSetColor_434460(a2);
		nox_client_drawRectFilledOpaque_49CE30(v4, v5, 10, 10);
	}
	if (v12 != 0x80000000) {
		nox_client_drawSetColor_434460(v12);
		nox_client_drawBorderLines_49CC70(v4, v5, 10, 10);
	}
	if (*(_BYTE*)v2 & 4 && *(_DWORD*)(v2 + 52) != 0x80000000) {
		nox_client_drawSetColor_434460(*(_DWORD*)(v2 + 52));
		nox_client_drawRectFilledOpaque_49CE30(v4 + 1, v5 + 1, 8, 8);
	}
	if ((*(_DWORD*)(v3 + 4) & 0x2000) == 0x2000)
		sub_43F670(1);
	if (**(_DWORD**)(v3 + 32)) {
		v6 = *(_DWORD*)(v3 + 12);
		v14 += *(_DWORD*)(v3 + 8) / 2;
		v7 = v6 / 2 + v15;
		v8 = *(_DWORD*)(v2 + 200);
		v15 = v7;
		sub_43F840(v8, (unsigned __int16*)(v2 + 72), &a1, 0, 0);
		if (*(_DWORD*)(v2 + 68) != 0x80000000) {
			sub_434390(*(_DWORD*)(v2 + 68));
			v11 = *(_DWORD*)(v3 + 8);
			v9 = sub_43F320(*(_DWORD*)(v2 + 200));
			sub_43FAF0(*(_DWORD*)(v2 + 200), (_WORD*)(v2 + 72), v14 - a1 / 2, v15 - v9 / 2, v11, 0);
		}
	} else if (*(_DWORD*)(v2 + 68) != 0x80000000) {
		sub_434390(*(_DWORD*)(v2 + 68));
		sub_43FAF0(*(_DWORD*)(v2 + 200), (_WORD*)(v2 + 72), v4 + 14, v5 - v13 / 2 + 5, *(_DWORD*)(v3 + 8), 0);
	}
	sub_43F670(0);
	return 1;
}

//----- (004A8A20) --------------------------------------------------------
int __cdecl sub_4A8A20(int a1, int a2) {
	int v2;  // esi
	int v3;  // ebp
	int v4;  // ebx
	int v5;  // eax
	int v6;  // kr00_4
	int v7;  // edx
	int v8;  // eax
	int v9;  // kr10_4
	int v10; // eax
	int v12; // [esp-8h] [ebp-20h]
	int v13; // [esp+10h] [ebp-8h]
	int v14; // [esp+14h] [ebp-4h]

	v2 = a2;
	v3 = *(_DWORD*)(a2 + 32);
	v4 = *(_DWORD*)(a2 + 24);
	nox_client_wndGetPosition_46AA60((_DWORD*)a1, &v13, &v14);
	if (*(_BYTE*)(a1 + 4) & 8) {
		if (*(_BYTE*)v2 & 2)
			v3 = *(_DWORD*)(v2 + 40);
	} else {
		v4 = *(_DWORD*)(v2 + 48);
	}
	if (v4)
		nox_client_drawImageAt_47D2C0(v4, v13 + *(_DWORD*)(v2 + 60), v14 + *(_DWORD*)(v2 + 64));
	if (*(_BYTE*)v2 & 4) {
		v5 = *(_DWORD*)(v2 + 56);
		if (v5)
			nox_client_drawImageAt_47D2C0(v5, v13 + *(_DWORD*)(v2 + 60), v14 + *(_DWORD*)(v2 + 64));
	} else if (v3) {
		nox_client_drawImageAt_47D2C0(v3, v13 + *(_DWORD*)(v2 + 60), v14 + *(_DWORD*)(v2 + 64));
	}
	if ((*(_DWORD*)(a1 + 4) & 0x2000) == 0x2000)
		sub_43F670(1);
	if (**(_DWORD**)(a1 + 32)) {
		v6 = *(_DWORD*)(a1 + 8);
		v7 = *(_DWORD*)(v2 + 200);
		v14 += *(_DWORD*)(a1 + 12) / 2;
		v13 += v6 / 2;
		sub_43F840(v7, (unsigned __int16*)(v2 + 72), &a2, 0, 0);
		if (*(_DWORD*)(v2 + 68) != 0x80000000) {
			sub_434390(*(_DWORD*)(v2 + 68));
			v12 = *(_DWORD*)(a1 + 8);
			v8 = sub_43F320(*(_DWORD*)(v2 + 200));
			sub_43FAF0(*(_DWORD*)(v2 + 200), (_WORD*)(v2 + 72), v13 - a2 / 2, v14 - v8 / 2, v12, 0);
		}
	} else {
		v9 = *(_DWORD*)(a1 + 12) - sub_43F320(*(_DWORD*)(v2 + 200));
		v10 = *(_DWORD*)(v2 + 68);
		v14 += v9 / 2;
		v13 += 28;
		if (v10 != 0x80000000) {
			sub_434390(v10);
			sub_43FAF0(*(_DWORD*)(v2 + 200), (_WORD*)(v2 + 72), v13, v14, *(_DWORD*)(a1 + 8), 0);
		}
	}
	sub_43F670(0);
	return 1;
}

//----- (004A8C00) --------------------------------------------------------
int __cdecl sub_4A8C00(int a1, int a2, int a3, int a4) {
	int v4;     // eax
	int v5;     // eax
	int result; // eax
	int v7;     // ecx
	int v8;     // esi
	int v9;     // [esp-10h] [ebp-14h]

	switch (a2) {
	case 5:
		goto LABEL_17;
	case 6:
	case 7:
		v8 = a1;
		if (!(*(_BYTE*)(a1 + 36) & 2))
			goto LABEL_18;
		nox_window_call_field_94(*(_DWORD*)(a1 + 52), 16391, a1, a3);
	LABEL_9:
		*(_DWORD*)(v8 + 36) ^= 4u;
		result = 1;
		break;
	case 8:
		nox_window_call_field_94(*(_DWORD*)(a1 + 52), 0x4000, a1, a3);
		return 1;
	case 17:
		v4 = *(_DWORD*)(a1 + 44);
		if (!(v4 & 0x100))
			goto LABEL_17;
		v5 = *(_DWORD*)(a1 + 52);
		*(_DWORD*)(a1 + 36) |= 2u;
		nox_window_call_field_94(v5, 16389, a1, a3);
		sub_46B500(a1);
		result = 1;
		break;
	case 18:
		v7 = *(_DWORD*)(a1 + 44);
		if (v7 & 0x100) {
			v9 = *(_DWORD*)(a1 + 52);
			*(_DWORD*)(a1 + 36) &= 0xFFFFFFFD;
			nox_window_call_field_94(v9, 16390, a1, a3);
			result = 1;
		} else {
		LABEL_17:
			result = 1;
		}
		break;
	case 21:
		switch (a3) {
		case 15:
		case 205:
		case 208:
			if (a4 != 2)
				goto LABEL_17;
			sub_46A8A0();
			return 1;
		case 28:
		case 57:
			if (a4 != 2)
				goto LABEL_17;
			v8 = a1;
			nox_window_call_field_94(*(_DWORD*)(v8 + 52), 16391, v8, 0);
			goto LABEL_9;
		case 200:
		case 203:
			if (a4 == 2)
				sub_46A8B0();
			goto LABEL_17;
		default:
			goto LABEL_18;
		}
	default:
	LABEL_18:
		result = 0;
		break;
	}
	return result;
}

//----- (004A8E60) --------------------------------------------------------
int __cdecl sub_4A8E60(int a1) {
	int result; // eax

	if ((signed char)*(_BYTE*)(a1 + 4) >= 0)
		result = nox_window_set_all_funcs((_DWORD*)a1, sub_4A8C00, sub_4A8EA0, 0);
	else
		result = nox_window_set_all_funcs((_DWORD*)a1, sub_4A8C00, sub_4A9050, 0);
	return result;
}

//----- (004A8EA0) --------------------------------------------------------
int __cdecl sub_4A8EA0(int a1, int a2) {
	int v2;    // esi
	int v3;    // ebp
	int v4;    // edi
	int v5;    // ebx
	int v6;    // edi
	int v7;    // ebx
	int v9;    // [esp+10h] [ebp-Ch]
	int xLeft; // [esp+14h] [ebp-8h]
	int yTop;  // [esp+18h] [ebp-4h]
	int v12;   // [esp+24h] [ebp+8h]

	v2 = a2;
	v3 = *(_DWORD*)(a2 + 28);
	v12 = *(_DWORD*)(a2 + 20);
	nox_client_wndGetPosition_46AA60((_DWORD*)a1, &xLeft, &yTop);
	if (*(_BYTE*)(a1 + 4) & 8) {
		if (*(_BYTE*)v2 & 2)
			v3 = *(_DWORD*)(v2 + 36);
	} else {
		v12 = *(_DWORD*)(v2 + 44);
	}
	v4 = yTop + *(_DWORD*)(a1 + 12) / 2 - 5;
	v5 = xLeft + 4;
	if (v12 != 0x80000000) {
		nox_client_drawSetColor_434460(v12);
		nox_client_drawRectFilledOpaque_49CE30(xLeft, yTop, *(_DWORD*)(a1 + 8), *(_DWORD*)(a1 + 12));
	}
	if (v3 != 0x80000000) {
		nox_client_drawSetColor_434460(v3);
		nox_client_drawBorderLines_49CC70(v5, v4, 10, 10);
	}
	if (*(_BYTE*)v2 & 4) {
		if (*(_DWORD*)(v2 + 52) != 0x80000000) {
			nox_client_drawSetColor_434460(*(_DWORD*)(v2 + 52));
			nox_client_drawRectFilledOpaque_49CE30(v5 + 1, v4 + 1, 8, 8);
			if (v3 != 0x80000000) {
				nox_client_drawSetColor_434460(v3);
				nox_client_drawAddPoint_49F500(v5, v4);
				sub_49F570(9, 9);
				nox_client_drawLineFromPoints_49E4B0();
				nox_client_drawAddPoint_49F500(v5, v4 + 9);
				sub_49F570(9, -9);
				nox_client_drawLineFromPoints_49E4B0();
			}
		}
	}
	v6 = 5 - sub_43F320(*(_DWORD*)(v2 + 200)) / 2 + v4;
	v7 = v5 + 14;
	sub_43F840(*(_DWORD*)(v2 + 200), (unsigned __int16*)(v2 + 72), &v9, 0, 0);
	if (*(_DWORD*)(v2 + 68) != 0x80000000) {
		if ((*(_DWORD*)(a1 + 4) & 0x2000) == 0x2000)
			sub_43F670(1);
		sub_434390(*(_DWORD*)(v2 + 68));
		sub_43FAF0(*(_DWORD*)(v2 + 200), (_WORD*)(v2 + 72), v7, v6, *(_DWORD*)(a1 + 8), 0);
		sub_43F670(0);
	}
	return 1;
}

//----- (004A9050) --------------------------------------------------------
int __cdecl sub_4A9050(_DWORD* a1, int a2) {
	int v2;     // esi
	_DWORD* v3; // ebx
	int v4;     // edi
	int v5;     // edi
	int v6;     // ebp
	int v7;     // eax
	int v8;     // edi
	int v9;     // ebp
	int v11;    // [esp+10h] [ebp-Ch]
	int v12;    // [esp+14h] [ebp-8h]
	int v13;    // [esp+18h] [ebp-4h]

	v2 = a2;
	v3 = a1;
	v11 = *(_DWORD*)(a2 + 32);
	a2 = *(_DWORD*)(a2 + 24);
	nox_client_wndGetPosition_46AA60(a1, &v12, &v13);
	v4 = v13 + v3[3] / 2;
	if (v3[1] & 8) {
		if (*(_BYTE*)v2 & 2)
			v11 = *(_DWORD*)(v2 + 40);
	} else {
		a2 = *(_DWORD*)(v2 + 48);
	}
	v5 = v4 - 5;
	v6 = v12 + 4;
	if (a2)
		nox_client_drawImageAt_47D2C0(a2, v6 + v3[24], v5 + v3[25]);
	if (*(_BYTE*)v2 & 4) {
		v7 = *(_DWORD*)(v2 + 56);
		if (!v7)
			goto LABEL_12;
	} else {
		v7 = v11;
		if (!v11)
			goto LABEL_12;
	}
	nox_client_drawImageAt_47D2C0(v7, v6 + v3[24], v5 + v3[25]);
LABEL_12:
	v8 = 5 - sub_43F320(*(_DWORD*)(v2 + 200)) / 2 + v5;
	v9 = v6 + 16;
	sub_43F840(*(_DWORD*)(v2 + 200), (unsigned __int16*)(v2 + 72), (int*)&a1, 0, 0);
	if (*(_DWORD*)(v2 + 68) != 0x80000000) {
		if ((v3[1] & 0x2000) == 0x2000)
			sub_43F670(1);
		sub_434390(*(_DWORD*)(v2 + 68));
		sub_43FAF0(*(_DWORD*)(v2 + 200), (_WORD*)(v2 + 72), v9, v8, v3[2], 0);
		sub_43F670(0);
	}
	return 1;
}

//----- (004A91A0) --------------------------------------------------------
int __cdecl sub_4A91A0(int a1, int a2, int a3, int a4, int a5, int a6, _DWORD* a7) {
	int v7;      // eax
	_DWORD* v8;  // eax
	int v9;      // esi
	_DWORD* v10; // eax

	v7 = a7[2];
	if (v7 & 1) {
		v8 = nox_window_new(a1, a2, a3, a4, a5, a6, sub_4A9250);
		v9 = (int)v8;
		if (v8) {
			sub_4A8340((int)v8);
		LABEL_7:
			if (!a7[4])
				a7[4] = v9;
			sub_46AF80_copy_window_part(v9, a7);
			return v9;
		}
		return v9;
	}
	if (v7 & 4) {
		v10 = nox_window_new(a1, a2, a3, a4, a5, a6, sub_4A92C0);
		v9 = (int)v10;
		if (v10) {
			sub_4A8E60((int)v10);
			goto LABEL_7;
		}
		return v9;
	}
	return 0;
}

//----- (004A9250) --------------------------------------------------------
int __cdecl sub_4A9250(int a1, int a2, wchar_t* a3, int a4) {
	int result; // eax
	int v4;     // eax
	int v5;     // eax

	if (a2 == 23) {
		if (!a3) {
			v4 = *(_DWORD*)(a1 + 36);
			LOBYTE(v4) = v4 & 0xFD;
			*(_DWORD*)(a1 + 36) = v4;
		}
		v5 = sub_46B0A0((int*)a1);
		nox_window_call_field_94(*(_DWORD*)(a1 + 52), 16387, (int)a3, v5);
		result = 1;
	} else {
		if (a2 == 16385) {
			nox_wcsncpy((wchar_t*)(a1 + 108), a3, 0x3Fu);
			*(_WORD*)(a1 + 234) = 0;
		}
		result = 0;
	}
	return result;
}

//----- (004A92C0) --------------------------------------------------------
int __cdecl sub_4A92C0(int a1, int a2, wchar_t* a3, int a4) {
	int result; // eax
	int v4;     // eax
	int v5;     // eax

	if (a2 == 23) {
		if (!a3) {
			v4 = *(_DWORD*)(a1 + 36);
			LOBYTE(v4) = v4 & 0xFD;
			*(_DWORD*)(a1 + 36) = v4;
		}
		v5 = sub_46B0A0((int*)a1);
		nox_window_call_field_94(*(_DWORD*)(a1 + 52), 16387, (int)a3, v5);
		result = 1;
	} else {
		if (a2 == 16385) {
			nox_wcsncpy((wchar_t*)(a1 + 108), a3, 0x3Fu);
			*(_WORD*)(a1 + 234) = 0;
		}
		result = 0;
	}
	return result;
}

//----- (004A9330) --------------------------------------------------------
int __cdecl sub_4A9330(int a1, int a2, int a3, int a4, int a5, int a6, int a7, _DWORD* a8) {
	_DWORD* v8;  // eax
	int v9;      // esi
	_DWORD* v10; // eax

	if (!(*(_BYTE*)(a7 + 8) & 2))
		return 0;
	v8 = nox_window_new(a1, a2, a3, a4, a5, a6, sub_4A93C0);
	v9 = (int)v8;
	if (v8) {
		sub_4A87E0((int)v8);
		if (!*(_DWORD*)(a7 + 16))
			*(_DWORD*)(a7 + 16) = v9;
		v10 = nox_malloc(4u);
		*v10 = 0;
		if (a8)
			*v10 = *a8;
		*(_DWORD*)(v9 + 32) = v10;
		sub_46AF80_copy_window_part(v9, (const void*)a7);
	}
	return v9;
}

//----- (004A93C0) --------------------------------------------------------
int __cdecl sub_4A93C0(int a1, int a2, wchar_t* a3, int a4) {
	int v3;    // edi
	_DWORD* i; // eax
	int v5;    // eax
	int v7;    // eax
	int v8;    // eax

	if (a2 != 23) {
		if (a2 == 16385) {
			nox_wcsncpy((wchar_t*)(a1 + 108), a3, 0x3Fu);
			*(_WORD*)(a1 + 234) = 0;
		} else if (a2 == 16392) {
			v3 = *(_DWORD*)(a1 + 396);
			if (!(*(_BYTE*)(a1 + 36) & 4)) {
				if (a3 == (wchar_t*)1)
					nox_window_call_field_94(*(_DWORD*)(a1 + 52), 16391, a1, 0);
				if (v3) {
					for (i = *(_DWORD**)(v3 + 400); i; i = (_DWORD*)i[97]) {
						if (i != (_DWORD*)a1 && i[10] == *(_DWORD*)(a1 + 40))
							i[9] &= 0xFFFFFFFB;
					}
				}
				v5 = *(_DWORD*)(a1 + 36);
				LOBYTE(v5) = v5 | 4;
				*(_DWORD*)(a1 + 36) = v5;
				return 0;
			}
		}
		return 0;
	}
	if (!a3) {
		v7 = *(_DWORD*)(a1 + 36);
		LOBYTE(v7) = v7 & 0xFD;
		*(_DWORD*)(a1 + 36) = v7;
	}
	v8 = sub_46B0A0((int*)a1);
	nox_window_call_field_94(*(_DWORD*)(a1 + 52), 16387, (int)a3, v8);
	return 1;
}

//----- (004A94A0) --------------------------------------------------------
int sub_4A94A0() // initListBoxColors, recall that one
{
	*(_DWORD*)&byte_5D4594[2650656] = sub_4344A0(0, 0, 0); // rgbatocompatiblecolor
	*(_DWORD*)&byte_5D4594[2614248] = sub_4344A0(8, 8, 8);
	*(_DWORD*)&byte_5D4594[2650660] = sub_4344A0(115, 115, 115);
	*(_DWORD*)&byte_5D4594[2597996] = sub_4344A0(212, 212, 212);
	*(_DWORD*)&byte_5D4594[2523948] = sub_4344A0(255, 255, 255);
	*(_DWORD*)&byte_5D4594[2598268] = sub_4344A0(100, 0, 0);
	*(_DWORD*)&byte_5D4594[2650644] = sub_4344A0(255, 0, 0);
	*(_DWORD*)&byte_5D4594[2589776] = sub_4344A0(255, 128, 128);
	*(_DWORD*)&byte_5D4594[2650688] = sub_4344A0(0, 100, 0);
	*(_DWORD*)&byte_5D4594[2618904] = sub_4344A0(0, 255, 0);
	*(_DWORD*)&byte_5D4594[2614268] = sub_4344A0(128, 255, 128);
	*(_DWORD*)&byte_5D4594[2650648] = sub_4344A0(0, 0, 140);
	*(_DWORD*)&byte_5D4594[2649820] = sub_4344A0(0, 0, 255);
	*(_DWORD*)&byte_5D4594[2650684] = sub_4344A0(0, 160, 255);
	*(_DWORD*)&byte_5D4594[2614256] = sub_4344A0(240, 180, 42);
	*(_DWORD*)&byte_5D4594[2589772] = sub_4344A0(255, 255, 0);
	*(_DWORD*)&byte_5D4594[2614244] = sub_4344A0(255, 255, 128);
	*(_DWORD*)&byte_5D4594[2649836] = &byte_5D4594[2650656];
	*(_DWORD*)&byte_5D4594[2649840] = &byte_5D4594[2614248];
	*(_DWORD*)&byte_5D4594[2649844] = &byte_5D4594[2650660];
	*(_DWORD*)&byte_5D4594[2649848] = &byte_5D4594[2597996];
	*(_DWORD*)&byte_5D4594[2649852] = &byte_5D4594[2523948];
	*(_DWORD*)&byte_5D4594[2649856] = &byte_5D4594[2598268];
	*(_DWORD*)&byte_5D4594[2649860] = &byte_5D4594[2650644];
	*(_DWORD*)&byte_5D4594[2649864] = &byte_5D4594[2589776];
	*(_DWORD*)&byte_5D4594[2649868] = &byte_5D4594[2650688];
	*(_DWORD*)&byte_5D4594[2649872] = &byte_5D4594[2618904];
	*(_DWORD*)&byte_5D4594[2649876] = &byte_5D4594[2614268];
	*(_DWORD*)&byte_5D4594[2649880] = &byte_5D4594[2650648];
	*(_DWORD*)&byte_5D4594[2649884] = &byte_5D4594[2649820];
	*(_DWORD*)&byte_5D4594[2649888] = &byte_5D4594[2650684];
	*(_DWORD*)&byte_5D4594[2649892] = &byte_5D4594[2614256];
	*(_DWORD*)&byte_5D4594[2649896] = &byte_5D4594[2589772];
	*(_DWORD*)&byte_5D4594[2649900] = &byte_5D4594[2614244];
	return 1;
}

//----- (004A96C0) --------------------------------------------------------
FILE* __cdecl sub_4A96C0_video_read_palette(char* a1) {
	FILE* result; // eax
	FILE* v2;     // ebp
	char v3[8];   // [esp+Ch] [ebp-40h]
	char v4[12];  // [esp+14h] [ebp-38h]
	char v5[12];  // [esp+20h] [ebp-2Ch]
	char v6[32];  // [esp+2Ch] [ebp-20h]

	strcpy(v4, "SHADEMAP");
	strcpy(v5, "TRANSMAP");
	strcpy(v3, "PALETTE");
	if (dword_5d4594_3801780 != 1) {
		result = fopen(a1, "rb");
		v2 = result;
		if (!result)
			return result;
		if (sub_40ADD0_fread(v6, 1u, strlen(v3), result) != strlen(v3)) {
			fclose(v2);
			return 0;
		}
		v6[strlen(v3)] = 0;
		if (strcmp(v6, v3)) {
			fclose(v2);
			return 0;
		}
		if (sub_40ADD0_fread((char*)&byte_5D4594[1308748], 1u, 0x300u, v2) != 768) {
			fclose(v2);
			return 0;
		}
		sub_4347F0((char*)&byte_5D4594[1308748], 256);
		sub_4348C0();
		if (!sub_42FFF0(v2)) {
			fclose(v2);
			return 0;
		}
		if (sub_40ADD0_fread(v6, 1u, strlen(v4), v2) != strlen(v4)) {
			fclose(v2);
			return 0;
		}
		v6[strlen(v4)] = 0;
		if (strcmp(v6, v4)) {
			fclose(v2);
			return 0;
		}
		if (sub_40ADD0_fread((char*)&byte_5D4594[2589804], 1u, 0x2000u, v2) != 0x2000) {
			fclose(v2);
			return 0;
		}
		sub_434610((int)&byte_5D4594[2589804]);
		if (sub_40ADD0_fread(v6, 1u, strlen(v5), v2) != strlen(v5)) {
			fclose(v2);
			return 0;
		}
		v6[strlen(v5)] = 0;
		if (strcmp(v6, v5)) {
			fclose(v2);
			return 0;
		}
		if (sub_40ADD0_fread((char*)&byte_5D4594[2524236], 1u, 0x10000u, v2) != 0x10000) {
			fclose(v2);
			return 0;
		}
		sub_434620((int)&byte_5D4594[2524236]);
		fclose(v2);
	}
	sub_4A94A0();
	sub_4A9A10();
	return (FILE*)1;
}
// 4A96C0: using guessed type char var_20[32];

//----- (004A9A10) --------------------------------------------------------
int sub_4A9A10() {
	int i; // esi

	for (i = 0; i < 6; ++i)
		sub_4341D0(i, *(int*)&byte_5D4594[2523948]);
	return 1;
}

//----- (004A9A30) --------------------------------------------------------
int __cdecl sub_4A9A30(unsigned __int8 a1, unsigned __int8 a2, unsigned __int8 a3) {
	int result;          // eax
	int v4;              // ebp
	unsigned __int8* v5; // edi
	int v6;              // edx
	int v7;              // ebx
	unsigned __int8 v8;  // [esp+10h] [ebp-10h]
	unsigned __int8 v9;  // [esp+14h] [ebp-Ch]
	unsigned __int8 v10; // [esp+18h] [ebp-8h]
	int v11;             // [esp+1Ch] [ebp-4h]

	result = 0;
	v4 = 0x1000000;
	v11 = 0;
	v5 = &byte_5D4594[1308749];
	while (*(v5 - 1) != a1 || *v5 != a2 || v5[1] != a3) {
		v6 = *(v5 - 1);
		if ((int)v6 - (int)a1 >= 0)
			v10 = v6 - a1;
		else
			v10 = a1 - v6;
		if ((int)*v5 - (int)a2 >= 0)
			v9 = *v5 - a2;
		else
			v9 = a2 - *v5;
		if ((int)v5[1] - (int)a3 >= 0)
			v8 = v5[1] - a3;
		else
			v8 = a3 - v5[1];
		v7 = v9 * v9;
		if (v8 * v8 + v7 + v10 * v10 < v4) {
			v4 = v8 * v8 + v7 + v10 * v10;
			v11 = result;
		}
		v5 += 3;
		++result;
		if ((int)v5 >= (int)&byte_5D4594[1309517])
			return v11;
	}
	return result;
}

//----- (004A9B20) --------------------------------------------------------
__int16 __cdecl sub_4A9B20(int a1) {
	int v1; // eax

	if (dword_5d4594_3801780 == 1)
		LOWORD(v1) = 0;
	else
		v1 = (byte_5D4594[3 * a1 + 1308750] >> 3) |
			 (4 * (byte_5D4594[3 * a1 + 1308749] & 0xF8 | (32 * (byte_5D4594[3 * a1 + 1308748] & 0xF8))));
	return v1;
}

//----- (004A9B70) --------------------------------------------------------
__int16 __cdecl sub_4A9B70(__int16* a1) {
	int v1; // eax

	if (dword_5d4594_3801780) {
		if (dword_5d4594_3799624 == 2)
			v1 = *a1 & 0x1F | (*a1 >> 1) & 0x7FE0;
		else
			LOWORD(v1) = *a1;
	} else {
		LOWORD(v1) = sub_4A9B20(*(unsigned __int8*)a1);
	}
	return v1;
}

//----- (004A9BC0) --------------------------------------------------------
int __cdecl sub_4A9BC0(unsigned __int8 a1, unsigned __int8 a2, unsigned __int8 a3) {
	if (dword_5d4594_3801780 != 1)
		return sub_4A9A30(a1, a2, a3);
	if (dword_5d4594_3799624 == 1)
		return (a3 >> 3) | (4 * (a2 & 0xF8 | (32 * (a1 & 0xF8))));
	return (a3 >> 3) | (8 * (a2 & 0xFC | (32 * (a1 & 0xF8))));
}

//----- (004A9C50) --------------------------------------------------------
int __cdecl sub_4A9C50(int a1) {
	unsigned __int16 v1; // cx

	HIBYTE(v1) = byte_5D4594[3 * a1 + 1308750];
	LOBYTE(v1) = byte_5D4594[3 * a1 + 1308749];
	return byte_5D4594[3 * a1 + 1308748] | (v1 << 8);
}

//----- (004A9C80) --------------------------------------------------------
int sub_4A9C80() {
	int v0;              // edi
	unsigned __int8* v1; // esi
	int v2;              // edi
	unsigned __int8* v3; // esi
	char v5[64];         // [esp+8h] [ebp-40h]

	*(_DWORD*)&byte_5D4594[1309664] = 0;
	v0 = 0;
	v1 = &byte_5D4594[1309644];
	do {
		nox_sprintf(v5, "Compass%d", ++v0);
		*(_DWORD*)v1 = sub_42F970(v5);
		v1 += 4;
	} while ((int)v1 < (int)&byte_5D4594[1309660]);
	v2 = 0;
	v3 = &byte_5D4594[1309516];
	do {
		nox_sprintf(v5, "CompassMainArrow%d", ++v2);
		*(_DWORD*)v3 = sub_42F970(v5);
		v3 += 4;
	} while ((int)v3 < (int)&byte_5D4594[1309644]);
	return 1;
}

// 4AD170: using guessed type int sub_4AD170_call_copy_backbuffer(void);

//----- (004A9E90) --------------------------------------------------------
__int16 __cdecl sub_4A9E90(int a1, int a2, int a3, int a4) {
	int v4;  // eax
	int v5;  // esi
	int v6;  // ebp
	int v7;  // edi
	int v8;  // ebx
	int v9;  // edi
	int v10; // esi
	int v11; // eax
	int v12; // esi
	// bool v13; // zf
	// bool v14; // of
	int v15; // ebp
	int v16; // esi
	int v18; // [esp+10h] [ebp-4h]
	int v19; // [esp+18h] [ebp+4h]
	int v20; // [esp+1Ch] [ebp+8h]
	int v21; // [esp+20h] [ebp+Ch]

	v4 = a1 + a3;
	v18 = a1;
	v5 = a1 + 10;
	v6 = a2 - 10;
	v7 = a1 + a3 - 30;
	v19 = a1 + a3;
	v21 = a2 - 10;
	v8 = a2 + a4 - 10;
	if (v5 <= v7) {
		do {
			nox_client_drawImageAt_47D2C0(*(int*)&byte_5D4594[1309692], v5, v6);
			nox_client_drawImageAt_47D2C0(*(int*)&byte_5D4594[1309692], v5, v8);
			v5 += 20;
		} while (v5 <= v7);
		v4 = v19;
	}
	v9 = v4 - 10;
	if (v4 - 10 - v5 >= 10) {
		nox_client_drawImageAt_47D2C0(*(int*)&dword_5d4594_1309696, v5, v6);
		nox_client_drawImageAt_47D2C0(*(int*)&dword_5d4594_1309696, v5, v8);
		v5 += 10;
	}
	if (v5 < v9) {
		v10 = v5 + ((v9 - v5 + 1) & 0xFFFFFFFE) - 10;
		nox_client_drawImageAt_47D2C0(*(int*)&dword_5d4594_1309696, v10, v6);
		nox_client_drawImageAt_47D2C0(*(int*)&dword_5d4594_1309696, v10, v8);
	}
	v11 = a2 + a4 - 30;
	v12 = a2 + 10;
	// v14 = __OFSUB__(a2 + 10, v11);
	// v13 = a2 + 10 == v11;
	v15 = v18 - 10;
	v20 = a2 + a4 - 30;
	// if ( (10 - (a4 - 30) < 0) ^ v14 | v13 )
	while (v12 <= v20) {
		nox_client_drawImageAt_47D2C0(*(int*)&byte_5D4594[1309700], v15, v12);
		nox_client_drawImageAt_47D2C0(*(int*)&byte_5D4594[1309700], v9, v12);
		v12 += 20;
	}
	if (v8 - v12 >= 10) {
		nox_client_drawImageAt_47D2C0(*(int*)&dword_5d4594_1309704, v15, v12);
		nox_client_drawImageAt_47D2C0(*(int*)&dword_5d4594_1309704, v9, v12);
		v12 += 10;
	}
	if (v12 < v8) {
		v16 = v12 + ((v8 - v12 + 1) & 0xFFFFFFFE) - 10;
		nox_client_drawImageAt_47D2C0(*(int*)&dword_5d4594_1309704, v15, v16);
		nox_client_drawImageAt_47D2C0(*(int*)&dword_5d4594_1309704, v9, v16);
	}
	nox_client_drawImageAt_47D2C0(*(int*)&byte_5D4594[1309676], v15, v21);
	nox_client_drawImageAt_47D2C0(*(int*)&byte_5D4594[1309680], v9, v21);
	nox_client_drawImageAt_47D2C0(*(int*)&byte_5D4594[1309684], v15, v8);
	return nox_client_drawImageAt_47D2C0(*(int*)&byte_5D4594[1309688], v9, v8);
}

//----- (004AA030) --------------------------------------------------------
__int16 __cdecl sub_4AA030(_DWORD* a1, int a2) {
	_DWORD* v2;       // esi
	int v3;           // edi
	int v4;           // eax
	unsigned int v5;  // ebx
	int v6;           // edx
	int v7;           // ecx
	int v8;           // eax
	_DWORD* v9;       // eax
	int v10;          // ebp
	bool v11;         // zf
	int v12;          // ebx
	_DWORD* v13;      // edi
	__int16 v14;      // cx
	int v16;          // [esp+10h] [ebp-10h]
	unsigned int v17; // [esp+14h] [ebp-Ch]
	int v18;          // [esp+18h] [ebp-8h]
	int v19;          // [esp+1Ch] [ebp-4h]

	v2 = a1;
	v3 = 0;
	LOWORD(v4) = nox_client_wndGetPosition_46AA60(a1, &a1, &v16);
	v5 = 0;
	v17 = 0;
	while (!v3) {
		v4 = (1 << v5) & v2[11];
		if (v4) {
			if (v4 <= 32) {
				if (v4 != 32) {
					switch (--v4) {
					case 0:
					case 1:
						goto LABEL_24;
					case 3:
					case 7:
					case 15:
						goto LABEL_25;
					default:
						goto LABEL_26;
					}
					goto LABEL_26;
				}
				v6 = v2[8];
				v7 = 0;
				v8 = 0;
				if (*(_DWORD*)(v6 + 12))
					v7 = *(_DWORD*)(*(_DWORD*)(*(_DWORD*)(v6 + 36) + 400) + 12);
				if (*((_WORD*)v2 + 54))
					v8 = 4;
				LOWORD(v4) = sub_4A9E90((int)a1 - 3, v16 - v8 - 3, v2[2] - v7 + 3, v2[3] + 6);
				goto LABEL_25;
			}
			if (v4 > 4096) {
				if (v4 == 0x2000)
					goto LABEL_24;
			} else {
				switch (v4) {
				case 4096:
					goto LABEL_24;
				case 128:
					v9 = a1;
					v10 = v2[8];
					v11 = *(_WORD*)(a2 + 72) == 0;
					v12 = v2[2];
					v19 = v16;
					v13 = a1;
					if (!v11) {
						sub_43F840(*(_DWORD*)(a2 + 200), (unsigned __int16*)(a2 + 72), &v18, 0, 0);
						v13 = (_DWORD*)((char*)v13 + v18 + 6);
						v9 = a1;
						v12 += -6 - v18;
					}
					v14 = *(_WORD*)(v10 + 1042);
					if (v14 > 0 && v12 > v14) {
						v12 = v14;
						v13 = (_DWORD*)((char*)v9 + v2[2] - v14);
					}
					LOWORD(v4) = sub_4A9E90((int)v13, v19, v12, v2[3]);
					v5 = v17;
					v3 = 1;
					break;
				case 2048:
				LABEL_24:
					LOWORD(v4) = sub_4A9E90((int)a1, v16, v2[2], v2[3]);
				LABEL_25:
					v3 = 1;
					break;
				}
			}
		}
	LABEL_26:
		v17 = ++v5;
		if (v5 >= 0x20)
			return v4;
	}
	return v4;
}

//----- (004AA1F0) --------------------------------------------------------
char* sub_4AA1F0() {
	char* result; // eax

	*(_DWORD*)&byte_5D4594[1309676] = sub_42F970("BorderCornerUL");
	*(_DWORD*)&byte_5D4594[1309680] = sub_42F970("BorderCornerUR");
	*(_DWORD*)&byte_5D4594[1309684] = sub_42F970("BorderCornerLL");
	*(_DWORD*)&byte_5D4594[1309688] = sub_42F970("BorderCornerLR");
	*(_DWORD*)&byte_5D4594[1309692] = sub_42F970("BorderHorizontal");
	dword_5d4594_1309696 = sub_42F970("BorderHorizontalShort");
	*(_DWORD*)&byte_5D4594[1309700] = sub_42F970("BorderVertical");
	result = sub_42F970("BorderVerticalShort");
	dword_5d4594_1309704 = result;
	return result;
}

//----- (004AA270) --------------------------------------------------------
int sub_4AA270() {
	int result; // eax
	_DWORD* v1; // esi
	_DWORD* v2; // esi
	_DWORD* v3; // eax
	_DWORD* v4; // eax
	_DWORD* v5; // eax
	int v6;     // esi
	_DWORD* v7; // eax

	sub_44A400();
	sub_43BDD0(400);
	sub_4A1A40(1);
	if (sub_40E0C0() && sub_43AF70() == 1)
		sub_41D4C0();
	sub_43AF50(2);
	result = nox_new_window_from_file("ArnaMain.wnd", sub_4AA4D0);
	dword_5d4594_1309716 = result;
	if (result) {
		sub_46B300(result, sub_4A18E0);
		v1 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1309716, 410);
		sub_46B2C0((int)v1, sub_4AA4D0);
		result = nox_wnd_sub_43C5B0(v1, 0, 0, 0, -240, 0, 20, 0, -40);
		dword_5d4594_1309708 = result;
		if (result) {
			*(_DWORD*)result = 400;
			*(_DWORD*)(dword_5d4594_1309708 + 48) = sub_4AA450;
			*(_DWORD*)(dword_5d4594_1309708 + 56) = sub_4AA490;
			v2 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1309716, 420);
			sub_46B2C0((int)v2, sub_4AA4D0);
			result = nox_wnd_sub_43C5B0(v2, 0, 240, 0, 480, 0, -20, 0, 40);
			*(_DWORD*)&byte_5D4594[1309712] = result;
			if (result) {
				sub_4A19F0((char*)&byte_587000[172636]);
				sub_46A8A0();
				if (nox_common_gameFlags_check_40A5C0(0x2000000)) {
					v3 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1309716, 411);
					nox_window_call_field_94(*(int*)&dword_5d4594_1309716, 16391, (int)v3, 0);
					result = 1;
				} else if (sub_4D6FA0() == 1) {
					v4 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1309716, 421);
					nox_window_call_field_94(*(int*)&dword_5d4594_1309716, 16391, (int)v4, 0);
					result = 1;
				} else {
					if (sub_4D6FA0() == 2) {
						v5 = sub_46B0C0(0, 150);
						v6 = (int)v5;
						v7 = sub_46B0C0(v5, 152);
						nox_window_call_field_94(v6, 16391, (int)v7, 0);
					}
					result = 1;
				}
			}
		}
	}
	return result;
}
// 4A18E0: using guessed type int __cdecl sub_4A18E0(int, int, int, int);

//----- (004AA450) --------------------------------------------------------
int sub_4AA450() {
	*(_BYTE*)(dword_5d4594_1309708 + 64) = 2;
	*(_BYTE*)(*(_DWORD*)&byte_5D4594[1309712] + 64) = 2;
	sub_43BE40(2);
	sub_452D80(923, 100);
	return 1;
}

//----- (004AA490) --------------------------------------------------------
int sub_4AA490() {
	int (*v0)(void); // esi

	v0 = *(int (**)(void))(dword_5d4594_1309708 + 52);
	sub_43C570(*(LPVOID*)&dword_5d4594_1309708);
	sub_43C570(*(LPVOID*)&byte_5D4594[1309712]);
	sub_46C4E0(*(_DWORD**)&dword_5d4594_1309716);
	v0();
	return 1;
}

//----- (004AA6B0) --------------------------------------------------------
int sub_4AA6B0() {
	int result;       // eax
	_DWORD* v1;       // esi
	char* v2;         // eax
	int v3;           // eax
	int v4;           // ecx
	unsigned int v5;  // ecx
	_DWORD* v6;       // esi
	char* v7;         // eax
	int v8;           // eax
	int v9;           // ecx
	unsigned int v10; // ecx
	_DWORD* v11;      // esi
	char* v12;        // eax
	int v13;          // eax
	int v14;          // ecx
	unsigned int v15; // ecx
	char* v16;        // [esp-Ch] [ebp-Ch]
	char* v17;        // [esp-Ch] [ebp-Ch]
	char* v18;        // [esp-Ch] [ebp-Ch]
	char* v19;        // [esp-8h] [ebp-8h]
	char* v20;        // [esp-8h] [ebp-8h]
	char* v21;        // [esp-8h] [ebp-8h]

	sub_43BDD0(300);
	result = nox_new_window_from_file("Options.wnd", sub_4AABE0);
	dword_5d4594_1309720 = result;
	if (result) {
		result = sub_4CB590(result);
		if (result) {
			sub_46B300(*(int*)&dword_5d4594_1309720, sub_4A18E0);
			sub_43FE20(15);
			result = nox_wnd_sub_43C5B0(*(_DWORD**)&dword_5d4594_1309720, 0, 0, 0, -480, 0, 20, 0, -40);
			dword_5d4594_1309740 = result;
			if (result) {
				*(_DWORD*)result = 300;
				*(_DWORD*)(dword_5d4594_1309740 + 48) = sub_4AA9C0;
				*(_DWORD*)(dword_5d4594_1309740 + 56) = sub_4AAA10;
				v1 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1309720, 351);
				*(_DWORD*)(v1[100] + 8) = 24;
				*(_DWORD*)(v1[100] + 12) = 20;
				v19 = sub_42F970("OptionsVolumeSliderLit");
				v16 = sub_42F970("OptionsVolumeSliderLit");
				v2 = sub_42F970("OptionsVolumeSlider");
				sub_4B5700((int)v1, 0, 0, (int)v2, (int)v16, (int)v19);
				nox_window_call_field_94((int)v1, 16395, 0, 0x4000);
				nox_window_call_field_94((int)v1, 16394, *(_DWORD*)(dword_587000_127004 + 4) >> 16, 0);
				dword_5d4594_1309728 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1309720, 361);
				v3 = sub_453070();
				v4 = *(_DWORD*)(dword_5d4594_1309728 + 36);
				if (v3 == 1)
					v5 = v4 | 4;
				else
					v5 = v4 & 0xFFFFFFFB;
				*(_DWORD*)(dword_5d4594_1309728 + 36) = v5;
				v6 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1309720, 352);
				*(_DWORD*)(v6[100] + 8) = 24;
				*(_DWORD*)(v6[100] + 12) = 20;
				v20 = sub_42F970("OptionsVolumeSliderLit");
				v17 = sub_42F970("OptionsVolumeSliderLit");
				v7 = sub_42F970("OptionsVolumeSlider");
				sub_4B5700((int)v6, 0, 0, (int)v7, (int)v17, (int)v20);
				nox_window_call_field_94((int)v6, 16395, 0, 0x4000);
				nox_window_call_field_94((int)v6, 16394, *(_DWORD*)(dword_587000_122852 + 4) >> 16, 0);
				dword_5d4594_1309732 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1309720, 362);
				v8 = sub_44D990();
				v9 = *(_DWORD*)(dword_5d4594_1309732 + 36);
				if (v8 == 1)
					v10 = v9 | 4;
				else
					v10 = v9 & 0xFFFFFFFB;
				*(_DWORD*)(dword_5d4594_1309732 + 36) = v10;
				v11 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1309720, 353);
				*(_DWORD*)(v11[100] + 8) = 24;
				*(_DWORD*)(v11[100] + 12) = 20;
				v21 = sub_42F970("OptionsVolumeSliderLit");
				v18 = sub_42F970("OptionsVolumeSliderLit");
				v12 = sub_42F970("OptionsVolumeSlider");
				sub_4B5700((int)v11, 0, 0, (int)v12, (int)v18, (int)v21);
				nox_window_call_field_94((int)v11, 16395, 0, 0x4000);
				nox_window_call_field_94((int)v11, 16394, *(_DWORD*)(dword_587000_93164 + 4) >> 16, 0);
				dword_5d4594_1309736 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1309720, 363);
				v13 = sub_43DC30();
				v14 = *(_DWORD*)(dword_5d4594_1309736 + 36);
				if (v13 == 1)
					v15 = v14 | 4;
				else
					v15 = v14 & 0xFFFFFFFB;
				*(_DWORD*)(dword_5d4594_1309736 + 36) = v15;
				sub_46A8A0();
				sub_4A19F0((char*)&byte_587000[173236]);
				sub_4A1A40(0);
				sub_4AAA70();
				result = 1;
			}
		}
	}
	return result;
}
// 4A18E0: using guessed type int __cdecl sub_4A18E0(int, int, int, int);

//----- (004AA9C0) --------------------------------------------------------
int sub_4AA9C0() {
	sub_44D8F0();
	sub_43BEF0_set_video_mode(*(int*)&dword_587000_172876, *(int*)&dword_587000_172872, *(int*)&dword_587000_172880);
	nox_common_writecfgfile((char*)&byte_587000[173256]);
	*(_BYTE*)(dword_5d4594_1309740 + 64) = 2;
	sub_43BE40(2);
	sub_452D80(923, 100);
	return 1;
}

//----- (004AAA10) --------------------------------------------------------
int sub_4AAA10() {
	void (*v0)(void); // esi

	v0 = *(void (**)(void))(dword_5d4594_1309740 + 52);
	sub_43C570(*(LPVOID*)&dword_5d4594_1309740);
	sub_46C4E0(*(_DWORD**)&dword_5d4594_1309720);
	sub_4A1A40(1);
	if (nox_win_depth_1 == nox_win_depth_2) {
		v0();
	} else {
		nox_win_depth_2 = nox_win_depth_1;
		dword_5d4594_805872 = 1;
	}
	return 1;
}

//----- (004AAA70) --------------------------------------------------------
_DWORD* sub_4AAA70() {
	_DWORD* v0;     // eax
	_DWORD* v1;     // eax
	int v4;         // eax
	_DWORD* result; // eax
	int v6;         // [esp-4h] [ebp-10h]
	int v7;         // [esp-4h] [ebp-10h]
	int v8;         // [esp+0h] [ebp-Ch]
	int v9;         // [esp+4h] [ebp-8h]
	int v10;        // [esp+8h] [ebp-4h]

	sub_43BEB0_get_video_mode(&v8, &v10, &v9);
	v9 = dword_587000_172880;
	if (v10 == 480)
		v6 = 321;
	else if (v10 == 576)
		v6 = 322;
	else
		v6 = 323;
	v0 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1309720, v6);
	nox_window_call_field_94((int)v0, 16392, 1, 0);
	if (v9 == 8) {
		v1 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1309720, 331);
	} else {
		v1 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1309720, 332);
	}
	nox_window_call_field_94((int)v1, 16392, 1, 0);
	if (g_fullscreen)
		v1 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1309720, 333);
	else
		v1 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1309720, 334);
	nox_window_call_field_94((int)v1, 16392, 1, 0);
	nox_window_call_field_94(sub_46B0C0(*(_DWORD**)&dword_5d4594_1309820, 316), 16394, (draw_gamma - 0.5f) * 50, 0);
	nox_window_call_field_94(sub_46B0C0(*(_DWORD**)&dword_5d4594_1309820, 318), 16394,
							 (log10f(input_sensitivity) + 1.0f) * 50, 0);
#if 0
    _DWORD* v2; // eax
    _DWORD* v3; // eax
    if (!sub_4300D0(0))
    {
        v2 = sub_46B0C0(*(_DWORD * *)& dword_5d4594_1309720, 331);
        sub_46AD80((int)v2, 8);
    }
    if (!sub_4300D0(1))
    {
        v3 = sub_46B0C0(*(_DWORD * *)& dword_5d4594_1309720, 332);
        sub_46AD80((int)v3, 8);
    }
#endif
	v4 = sub_4766D0();
	*(_DWORD*)&byte_587000[172884] = v4;
	if (v4 > 69) {
		if (v4 <= 79) {
			result = sub_46B0C0(*(_DWORD**)&dword_5d4594_1309720, 312);
			goto LABEL_22;
		}
		if (v4 <= 89) {
			result = sub_46B0C0(*(_DWORD**)&dword_5d4594_1309720, 313);
			goto LABEL_22;
		}
		v7 = 314;
	} else {
		v7 = 311;
	}
	result = sub_46B0C0(*(_DWORD**)&dword_5d4594_1309720, v7);
LABEL_22:
	if (result)
		result = (_DWORD*)nox_window_call_field_94((int)result, 16392, 1, 0);
	return result;
}

//----- (004AABE0) --------------------------------------------------------
int __cdecl sub_4AABE0(int a1, int a2, int* a3, int a4) {
	int v4;                                     // eax
	int v5;                                     // eax
	int result;                                 // eax
	int v7;                                     // edi
	int v8;                                     // esi
	void(__cdecl * v9)(_DWORD, int, int, int);  // eax
	void(__cdecl * v10)(_DWORD, int, int, int); // eax
	void(__cdecl * v11)(_DWORD, int, int, int); // eax
	void* v12;                                  // ecx
	void(__cdecl * v13)(void*, int, int, int);  // eax
	void(__cdecl * v14)(_DWORD, int, int, int); // eax
	int v15;                                    // ecx
	void(__cdecl * v16)(int, int, int, int);    // eax
	int v17;                                    // eax
	void(__cdecl * v18)(_DWORD, int, int, int); // eax
	void(__cdecl * v19)(_DWORD, int, int, int); // eax

	switch (a2) {
	case 16389:
		sub_452D80(920, 100);
		result = 1;
		break;
	case 16391:
		v4 = sub_46B0A0(a3);
		if (v4 > 341) {
			if (v4 > 363) {
				if (v4 == 2099)
					sub_4AAA70();
			} else if (v4 == 363) {
				if (sub_43DC30() == 1) {
					sub_43DC00();
				} else {
					sub_43DC10();
					sub_486320(*(_DWORD**)&dword_587000_93164, *(_DWORD*)(dword_587000_93164 + 4) >> 16);
				}
			} else {
				v5 = v4 - 361;
				if (v5) {
					if (v5 == 1) {
						if (sub_44D990() == 1)
							sub_44D960();
						else
							sub_44D970();
					}
				} else if (sub_453070() == 1) {
					sub_453050();
				} else {
					sub_453060();
				}
			}
		} else if (v4 == 341) {
			sub_4AA9C0();
			*(_DWORD*)(dword_5d4594_1309740 + 56) = sub_4AB0C0;
			*(_DWORD*)(dword_5d4594_1309740 + 52) = sub_4CB880;
		} else {
			switch (v4) {
			case 311:
				sub_4766A0(65);
				break;
			case 312:
				sub_4766A0(75);
				break;
			case 313:
				sub_4766A0(85);
				break;
			case 314:
				sub_4766A0(100);
				break;
			case 321:
				dword_587000_172876 = 848;
				dword_587000_172872 = 480;
				break;
			case 322:
				dword_587000_172876 = 1024;
				dword_587000_172872 = 576;
				break;
			case 323:
				dword_587000_172876 = 1024;
				dword_587000_172872 = 768;
				break;
			case 332:
				dword_587000_172880 = 16;
			case 333:
				g_fullscreen = 1;
				break;
			case 331:
				dword_587000_172880 = 8;
			case 334:
				g_fullscreen = 0;
				break;
			default:
				break;
			}
		}
		sub_452D80(921, 100);
		result = 1;
		break;
	case 16393:
		v7 = sub_46B0A0(a3);
		v8 = sub_46C720();
		switch (v7) {
		case 351:
			sub_486320(*(_DWORD**)&dword_587000_127004, a4);
			if (v8 && *(int**)(v8 + 396) == a3)
				goto LABEL_76;
			if (a4) {
				if (sub_453070())
					goto LABEL_75;
				v15 = dword_5d4594_1309728;
				v16 = *(void(__cdecl**)(int, int, int, int))(dword_5d4594_1309728 + 372);
				if (!v16)
					goto LABEL_75;
				goto LABEL_74;
			}
			if (sub_453070() != 1)
				goto LABEL_76;
			v14 = *(void(__cdecl**)(_DWORD, int, int, int))(dword_5d4594_1309728 + 372);
			if (!v14)
				goto LABEL_76;
			v14(dword_5d4594_1309728, 21, 28, 2);
			result = 0;
			break;
		case 352:
			sub_486320(*(_DWORD**)&dword_587000_122852, a4);
			if (a4) {
				if (sub_44D990())
					goto LABEL_49;
				v12 = *(void**)&dword_5d4594_1309732;
				v13 = *(void(__cdecl**)(void*, int, int, int))(dword_5d4594_1309732 + 372);
				if (!v13)
					goto LABEL_49;
				goto LABEL_48;
			}
			if (sub_44D990() != 1)
				goto LABEL_76;
			v11 = *(void(__cdecl**)(_DWORD, int, int, int))(dword_5d4594_1309732 + 372);
			if (!v11)
				goto LABEL_76;
			v11(dword_5d4594_1309732, 21, 28, 2);
			result = 0;
			break;
		case 353:
			sub_486320(*(_DWORD**)&dword_587000_93164, a4);
			if (a4) {
				if (sub_43DC30())
					goto LABEL_76;
				v10 = *(void(__cdecl**)(_DWORD, int, int, int))(dword_5d4594_1309736 + 372);
				if (!v10)
					goto LABEL_76;
				v10(dword_5d4594_1309736, 21, 28, 2);
				result = 0;
			} else {
				if (sub_43DC30() != 1)
					goto LABEL_76;
				v9 = *(void(__cdecl**)(_DWORD, int, int, int))(dword_5d4594_1309736 + 372);
				if (!v9)
					goto LABEL_76;
				v9(dword_5d4594_1309736, 21, 28, 2);
				result = 0;
			}
			break;
		case 316: // gamma slider
			draw_gamma = 0.5 + a4 / 50.0f;
			break;
		case 318: // input sensitivity slider
			input_sensitivity = powf(10.0, a4 / 50.0f - 1.0);
			break;
		default:
			goto LABEL_76;
		}
		break;
	case 16396:
		v17 = sub_46B0A0(a3) - 351;
		if (v17) {
			if (v17 != 1)
				goto LABEL_76;
			sub_486320(*(_DWORD**)&dword_587000_122852, a4);
			if (a4) {
				if (!sub_44D990()) {
					v12 = *(void**)&dword_5d4594_1309732;
					v13 = *(void(__cdecl**)(void*, int, int, int))(dword_5d4594_1309732 + 372);
					if (v13)
					LABEL_48:
						v13(v12, 21, 28, 2);
				}
			LABEL_49:
				sub_4AA650();
				result = 0;
			} else {
				if (sub_44D990() != 1)
					goto LABEL_76;
				v18 = *(void(__cdecl**)(_DWORD, int, int, int))(dword_5d4594_1309732 + 372);
				if (!v18)
					goto LABEL_76;
				v18(dword_5d4594_1309732, 21, 28, 2);
				result = 0;
			}
		} else {
			sub_486320(*(_DWORD**)&dword_587000_127004, a4);
			if (a4) {
				if (!sub_453070()) {
					v15 = dword_5d4594_1309728;
					v16 = *(void(__cdecl**)(int, int, int, int))(dword_5d4594_1309728 + 372);
					if (v16)
					LABEL_74:
						v16(v15, 21, 28, 2);
				}
			LABEL_75:
				sub_452D80(768, 100);
				goto LABEL_76;
			}
			if (sub_453070() != 1)
				goto LABEL_76;
			v19 = *(void(__cdecl**)(_DWORD, int, int, int))(dword_5d4594_1309728 + 372);
			if (!v19)
				goto LABEL_76;
			v19(dword_5d4594_1309728, 21, 28, 2);
			result = 0;
		}
		break;
	default:
	LABEL_76:
		result = 0;
		break;
	}
	return result;
}
// 4AAEC8: variable 'v12' is possibly undefined

//----- (004AB0C0) --------------------------------------------------------
int sub_4AB0C0() {
	void (*v0)(void); // esi

	v0 = *(void (**)(void))(dword_5d4594_1309740 + 52);
	sub_43C570(*(LPVOID*)&dword_5d4594_1309740);
	sub_46C4E0(*(_DWORD**)&dword_5d4594_1309720);
	v0();
	return 1;
}

//----- (004AB0F0) --------------------------------------------------------
int sub_4AB0F0() // playmovielogo
{
	int result;   // eax
	char v1[128]; // [esp+0h] [ebp-80h]

	if (nox_common_gameFlags_check_40A5C0(0x2000000) || !sub_4CB230("NoxLogo.vqa", v1)) {
		if (!sub_4CC4E0()) {
			sub_43DDD0(0);
			dword_5d4594_815132 = 0;
		}
		result = 1;
	} else {
		sub_4B0300(v1);
		sub_4B0640(sub_4CC4E0);
		sub_4B0340(0);
		result = 1;
	}
	return result;
}

//----- (004AB170) --------------------------------------------------------
int sub_4AB170() {
	unsigned __int8 v0; // al
	int result;         // eax
	char v2[128];       // [esp+0h] [ebp-80h]

	if ((sub_578DF0() & 0x80u) != 0 || nox_common_gameFlags_check_40A5C0(0x2000000) || !sub_4CB230("Intro.vqa", v2)) {
		sub_4AB0F0();
		result = 1;
	} else {
		sub_4B0300(v2);
		sub_4B0640(sub_4AB0F0);
		sub_4B0340(1);
		v0 = sub_578DF0();
		sub_578DE0(v0 | 0x80);
		result = 1;
	}
	return result;
}

//----- (004AB1F0) --------------------------------------------------------
int sub_4AB1F0() {
	int result;   // eax
	char v1[128]; // [esp+0h] [ebp-80h]

	sub_43BDC0();
	if (nox_common_gameFlags_check_40A5C0(0x2000000) || !sub_4CB230("WWLogo.vqa", v1)) {
		sub_4AB170();
		result = 1;
	} else {
		sub_4B0300(v1);
		sub_4B0640(sub_4AB170);
		sub_4B0340(0);
		result = 1;
	}
	return result;
}

//----- (004AB260) --------------------------------------------------------
int sub_4AB260() {
	*(_DWORD*)&byte_5D4594[1309752] = sub_42F970("DisconnectIcon");
	dword_5d4594_1309756 = nox_window_new(0, 136, nox_win_width - 50, nox_win_height / 2 + 3, 50, 50, 0);
	sub_46AE60(*(int*)&dword_5d4594_1309756, *(int*)&byte_5D4594[1309752]);
	nox_window_set_all_funcs(*(_DWORD**)&dword_5d4594_1309756, 0, sub_4AB420, 0);
	dword_5d4594_1309748 = nox_new_window_from_file("discon.wnd", sub_4AB390);
	sub_46B300(*(int*)&dword_5d4594_1309748, sub_4AB340);
	sub_46B120(*(_DWORD**)&dword_5d4594_1309748, 0);
	nox_wnd_sub_46A9B0(*(_DWORD**)&dword_5d4594_1309748, nox_win_width / 2 - *(_DWORD*)(dword_5d4594_1309748 + 24) / 2,
					   nox_win_height / 2 - *(_DWORD*)(dword_5d4594_1309748 + 28) / 2);
	return 1;
}

//----- (004AB340) --------------------------------------------------------
int __cdecl sub_4AB340(int a1, int a2, int a3, int a4) {
	int2* v4; // eax

	if (a2 != 21)
		return 0;
	if (a3 == 1)
		return 1;
	if (a3 == 57) {
		v4 = nox_client_getMousePos_4309F0();
		nox_window_call_field_93(a1, 5, v4->field_0 | (v4->field_4 << 16), 0);
	}
	return 0;
}

//----- (004AB390) --------------------------------------------------------
int __cdecl sub_4AB390(int a1, int a2, int* a3, int a4) {
	int v3;     // eax
	int result; // eax

	if (a2 == 23)
		return 1;
	if (a2 != 16391)
		return 0;
	v3 = sub_46B0A0(a3) - 576;
	if (!v3) {
		sub_43CF40();
		return 0;
	}
	if (v3 != 1)
		return 0;
	sub_446380();
	if (dword_5d4594_2650652 && sub_41E2F0() == 9) {
		sub_41F4B0();
		sub_41EC30();
		sub_446490(0);
		sub_44B000();
		sub_4AB4D0(0);
		result = 0;
	} else {
		sub_43B750();
		sub_4AB4D0(0);
		result = 0;
	}
	return result;
}

//----- (004AB420) --------------------------------------------------------
int __cdecl sub_4AB420(int* a1) {
	int* v1; // esi
	int v2;  // edx
	int v4;  // [esp+4h] [ebp-4h]

	v1 = a1;
	nox_client_wndGetPosition_46AA60(a1, &a1, &v4);
	v2 = v1[25];
	a1 = (int*)((char*)a1 + v1[24]);
	nox_client_drawImageAt_47D2C0(v1[15], (int)a1, v2 + v4);
	return 1;
}

//----- (004AB470) --------------------------------------------------------
int sub_4AB470() {
	int result; // eax

	sub_46C4E0(*(_DWORD**)&dword_5d4594_1309748);
	sub_46C4E0(*(_DWORD**)&dword_5d4594_1309756);
	result = 0;
	dword_5d4594_1309756 = 0;
	dword_5d4594_1309748 = 0;
	return result;
}

//----- (004AB4A0) --------------------------------------------------------
int __cdecl sub_4AB4A0(int a1) {
	int result; // eax

	if (a1)
		result = nox_window_set_hidden(*(int*)&dword_5d4594_1309756, 0);
	else
		result = nox_window_set_hidden(*(int*)&dword_5d4594_1309756, 1);
	return result;
}

//----- (004AB4D0) --------------------------------------------------------
int __cdecl sub_4AB4D0(int a1) {
	int result; // eax

	if (a1) {
		sub_44E040();
		nox_window_set_hidden(*(int*)&dword_5d4594_1309748, 0);
		sub_46A8C0(*(int*)&dword_5d4594_1309748);
		sub_46C690(*(int*)&dword_5d4594_1309748);
		sub_46B500(*(int*)&dword_5d4594_1309748);
		result = sub_46ABB0(*(int*)&dword_5d4594_1309748, 1);
	} else {
		nox_window_set_hidden(*(int*)&dword_5d4594_1309748, 1);
		sub_46C6E0(*(int*)&dword_5d4594_1309748);
		sub_46B500(0);
		result = sub_46ABB0(*(int*)&dword_5d4594_1309748, 0);
	}
	return result;
}

//----- (004AB560) --------------------------------------------------------
int __cdecl sub_4AB560(int a1) {
	int result; // eax

	result = a1;
	dword_587000_173328 = a1;
	return result;
}

//----- (004AB570) --------------------------------------------------------
int __cdecl sub_4AB570(int a1) {
	int result; // eax

	result = a1;
	dword_587000_173332 = a1;
	return result;
}

//----- (004AB580) --------------------------------------------------------
LPCSTR sub_4AB580() {
	LPCSTR result; // eax

	if (nox_file_9)
		fclose(nox_file_9);
	result = *(LPCSTR*)&dword_5d4594_1309776;
	nox_file_9 = 0;
	dword_5d4594_1309764 = 0;
	dword_5d4594_1309784 = 0;
	dword_5d4594_1309780 = 0;
	dword_5d4594_1309772 = 0;
	dword_5d4594_1309768 = 0;
	dword_587000_173336 = 1;
	if (dword_5d4594_1309776)
		free(*(LPVOID*)&dword_5d4594_1309776);
	return result;
}

//----- (004AB5E0) --------------------------------------------------------
int sub_4AB5E0() {
	int v0;              // esi
	unsigned __int8* v1; // eax
	int result;          // eax
	int v3;              // [esp+4h] [ebp-Ch]
	int v4;              // [esp+8h] [ebp-8h]
	int v5;              // [esp+Ch] [ebp-4h]

	v0 = 0;
	sub_467DF0(1);
	sub_4CC770();
	dword_587000_173328 = 1;
	dword_587000_173332 = 1;
	do {
		sub_416C70(30);
		sub_4453A0_poll_events();
		nox_client_processMouseInput_4308A0(1);
		sub_46B740();
		if (sub_43AF70() == 1) {
			sub_40D250();
			sub_40DF90();
		}
		v1 = (unsigned __int8*)sub_430940();
		for (dword_5d4594_2618912 = v1; *v1; dword_5d4594_2618912 = v1) {
			sub_46B6B0(v1);
			v1 = (unsigned __int8*)(dword_5d4594_2618912 + 8);
		}
		sub_43CCA0();
		if (!v0) {
			sub_43CA50();
			v0 = 1;
		}
		if (*(_DWORD*)&byte_5D4594[2598000] % 0x1Eu)
			sub_43CA20();
		mainloop_draw();
		nox_client_drawCursorAndTooltips_477830();
		sub_48A220();
		sub_4AD170_call_copy_backbuffer();
		sub_48A290_call_present();
		while (!sub_416CD0())
			;
	} while (dword_587000_173328);
	sub_4CC930();
	result = dword_587000_173332;
	if (dword_587000_173332) {
		sub_43BEB0_get_video_mode(&v3, &v5, &v4);
		if (!v3)
			sub_43BEF0_set_video_mode(NOX_DEFAULT_WIDTH, NOX_DEFAULT_HEIGHT, v4);
		result = dword_587000_173332;
	}
	return result;
}
// 4AD170: using guessed type int sub_4AD170_call_copy_backbuffer(void);

//----- (004AB720) --------------------------------------------------------
int sub_4AB720() {
	int v0; // esi
	int v1; // edi

	fclose(nox_file_9);
	_unlink(*(LPCSTR*)&dword_5d4594_1309776);
	v0 = dword_5d4594_1309780;
	nox_file_9 = 0;
	dword_5d4594_1309764 = 0;
	dword_587000_173336 = 1;
	dword_5d4594_1309772 = 0;
	dword_5d4594_1309768 = 0;
	if (dword_5d4594_1309780) {
		do {
			v1 = *(_DWORD*)(v0 + 12);
			free(*(LPVOID*)(v0 + 4));
			free((LPVOID)v0);
			v0 = v1;
		} while (v1);
	}
	if (dword_5d4594_1309776)
		free(*(LPVOID*)&dword_5d4594_1309776);
	dword_5d4594_1309784 = 0;
	dword_5d4594_1309780 = 0;
	sub_4AB560(0);
	return sub_4AB570(1);
}

//----- (004AB7C0) --------------------------------------------------------
void __cdecl sub_4AB7C0(unsigned __int16 a1, void* a2, size_t a3) {
	_DWORD* v3;           // ebx
	void* v4;             // eax
	unsigned __int16* v5; // esi
	int v6;               // eax
	int v7;               // eax

	// fprintf(stderr, "a1=%d, a2=%d, a3=%d, expected=%d\n", a1, a2, a3, *(_DWORD *)&dword_587000_173336);

	if (a2 && a3) {
		if (a1 == dword_587000_173336) {
			fwrite(a2, a3, 1u, nox_file_9);
			dword_5d4594_1309768 += a3;
			++dword_587000_173336;
		} else {
			v3 = nox_malloc(0x14u);
			if (v3) {
				v4 = nox_malloc(a3);
				v3[1] = v4;
				if (v4) {
					qmemcpy(v4, a2, a3);
					*(_WORD*)v3 = a1;
					v3[2] = a3;
					v3[3] = 0;
					v3[4] = dword_5d4594_1309784;
					if (dword_5d4594_1309784)
						*(_DWORD*)(dword_5d4594_1309784 + 12) = v3;
					dword_5d4594_1309784 = v3;
					if (!dword_5d4594_1309780)
						dword_5d4594_1309780 = v3;
				}
			}
		}
		v5 = *(unsigned __int16**)&dword_5d4594_1309780;
		if (dword_5d4594_1309780) {
			do {
				if (dword_587000_173336 == *v5) {
					fwrite(*((void**)v5 + 1), *((_DWORD*)v5 + 2), 1u, nox_file_9);
					dword_5d4594_1309768 += *((_DWORD*)v5 + 2);
					++dword_587000_173336;
					v6 = *((_DWORD*)v5 + 4);
					if (v6)
						*(_DWORD*)(v6 + 12) = *((_DWORD*)v5 + 3);
					else
						dword_5d4594_1309780 = *((_DWORD*)v5 + 3);
					v7 = *((_DWORD*)v5 + 3);
					if (v7)
						*(_DWORD*)(v7 + 16) = *((_DWORD*)v5 + 4);
					else
						dword_5d4594_1309784 = *((_DWORD*)v5 + 4);
					free(*((LPVOID*)v5 + 1));
					free(v5);
				}
				v5 = (unsigned __int16*)*((_DWORD*)v5 + 3);
			} while (v5);
		}
		// fprintf(stderr, "foo %d %d %d\n", *(_DWORD *)&dword_5d4594_1309764, *(_DWORD *)&dword_5d4594_1309768,
		// *(_DWORD *)&dword_5d4594_1309772);
		if (dword_5d4594_1309764 && *(unsigned int*)&dword_5d4594_1309768 >= *(unsigned int*)&dword_5d4594_1309772) {
			sub_4AB580();
			sub_4AB560(0);
			sub_4AB570(1);
			sub_4CC900(0x64u);
			sub_43CA80();
		} else {
			sub_4CC900((__int64)((double)*(unsigned int*)&dword_5d4594_1309768 / (double)*(int*)&dword_5d4594_1309772 *
								 100.0));
		}
	}
}

//----- (004AB9B0) --------------------------------------------------------
int __cdecl sub_4AB9B0(char* a1) {
	int result;         // eax
	CHAR FileName[256]; // [esp+8h] [ebp-100h]

	if (strchr(a1, 92)) {
		strcpy(FileName, a1);
	} else {
		strcpy(FileName, "maps\\");
		strncat(FileName, a1, strlen(a1) - 4);
		*(_WORD*)&FileName[strlen(FileName)] = *(_WORD*)&byte_587000[173348];
		strcat(FileName, a1);
	}
	result = _access(FileName, 0);
	if (result != -1)
		result = DeleteFileA(FileName);
	return result;
}

//----- (004ABA90) --------------------------------------------------------
LPCSTR sub_4ABA90() {
	LPCSTR result; // eax

	result = *(LPCSTR*)&dword_5d4594_1309764;
	if (dword_5d4594_1309764) {
		sub_43CAB0();
		if (nox_file_9)
			fclose(nox_file_9);
		sub_4AB9B0(*(char**)&dword_5d4594_1309776);
		result = sub_4AB580();
	}
	return result;
}

//----- (004ABAD0) --------------------------------------------------------
int __cdecl sub_4ABAD0(char* a1, unsigned int a2) {
	CHAR* v2;           // edi
	unsigned __int8 v3; // cl
	char* v4;           // ebx
	char* v5;           // eax
	CHAR* v6;           // edi
	unsigned __int8 v7; // cl
	char* v8;           // edx
	int result;         // eax
	int v10;            // [esp+10h] [ebp-204h]
	CHAR v11[256];      // [esp+14h] [ebp-200h]
	CHAR PathName[256]; // [esp+114h] [ebp-100h]

	if (!a1 || a2 <= 0)
		return 0;
	dword_5d4594_1309764 = 1;
	dword_587000_173336 = 1;
	dword_5d4594_1309772 = a2;
	dword_5d4594_1309768 = 0;
	dword_5d4594_1309780 = 0;
	dword_5d4594_1309784 = 0;
	if (strchr(a1, 92)) {
		strcpy(v11, "maps\\");
		v4 = strrchr(a1, 92) + 1;
		v5 = strrchr(a1, 46);
		if (!v4 || !v5)
			return 0;
		v10 = v5 - v4;
		strncat(v11, v4, v5 - v4);
		*(_WORD*)&v11[strlen(v11)] = *(_WORD*)&byte_587000[173380];
		strcpy(PathName, v11);
		strncat(v11, v4, v10);
		v6 = &v11[strlen(v11) + 1];
		v7 = byte_587000[173388];
		*(_DWORD*)--v6 = *(_DWORD*)&byte_587000[173384];
		v6[4] = v7;
		sub_409D70(v4);
	} else {
		sub_409D70(a1);
		strcpy(v11, "maps\\");
		strcat(v11, sub_409B40());
		*(_WORD*)&v11[strlen(v11)] = *(_WORD*)&byte_587000[173360];
		strcpy(PathName, v11);
		strcat(v11, sub_409B40());
		v2 = &v11[strlen(v11) + 1];
		v3 = byte_587000[173368];
		*(_DWORD*)--v2 = *(_DWORD*)&byte_587000[173364];
		v2[4] = v3;
	}
	sub_4AB9B0(a1);
	if (_access((LPCSTR)&byte_587000[173392], 0) == -1)
		CreateDirectoryA((LPCSTR)&byte_587000[173400], 0);
	if (_access(PathName, 0) == -1)
		CreateDirectoryA(PathName, 0);
	v8 = (char*)nox_malloc(strlen(v11) + 1);
	dword_5d4594_1309776 = v8;
	if (v8) {
		strcpy(v8, v11);
		nox_file_9 = fopen(*(const char**)&dword_5d4594_1309776, "wb");
		if (nox_file_9) {
			result = 1;
			dword_587000_173336 = 1;
			return result;
		}
	}
	return 0;
}

//----- (004ABDA0) --------------------------------------------------------
int __cdecl sub_4ABDA0(int a1, __int16 a2, __int16 a3, _DWORD* a4) {
	int v4;          // edi
	int result;      // eax
	int v6;          // esi
	unsigned int v7; // edx
	int v8;          // eax
	float v9;        // [esp-14h] [ebp-148h]
	char v10;        // [esp+Fh] [ebp-125h]
	float v11;       // [esp+10h] [ebp-124h]
	int v12;         // [esp+14h] [ebp-120h]
	int v13[2];      // [esp+18h] [ebp-11Ch]
	float v14;       // [esp+20h] [ebp-114h]
	int v15;         // [esp+24h] [ebp-110h]
	int v16;         // [esp+28h] [ebp-10Ch]
	float v17;       // [esp+2Ch] [ebp-108h]
	int v18;         // [esp+30h] [ebp-104h]
	char v19[256];   // [esp+34h] [ebp-100h]

	sub_426AC0_file3_fread(&v15, 4u);
	*a4 += 4;
	sub_426AC0_file3_fread(&v16, 4u);
	*a4 += 4;
	if (a3 < 40 || a2 < 4) {
		sub_426AC0_file3_fread(v13, 8u);
		*a4 += 8;
	} else {
		sub_426AC0_file3_fread(&v11, 4u);
		*a4 += 4;
		sub_426AC0_file3_fread(&v17, 4u);
		v9 = v11;
		*a4 += 4;
		v13[0] = nox_float2int(v9);
		v13[1] = nox_float2int(v17);
	}
	if (a3 >= 10) {
		sub_426AC0_file3_fread(&v12, 1u);
		++*a4;
		sub_426AC0_file3_fread(v19, (unsigned __int8)v12);
		*a4 += (unsigned __int8)v12;
	}
	if (a3 >= 20) {
		sub_426AC0_file3_fread(&v10, 1u);
		++*a4;
	}
	if (a3 >= 30) {
		sub_426AC0_file3_fread(&v12, 1u);
		++*a4;
	}
	if (a3 >= 40) {
		sub_426AA0(4);
		*a4 += 4;
		if (a2 >= 2) {
			if (a2 < 5) {
				sub_426AC0_file3_fread(&v14, 4u);
				*a4 += 4;
				v11 = v14;
			} else {
				sub_426AC0_file3_fread(&v11, 2u);
				*a4 += 2;
			}
			v4 = (unsigned __int16)(4 * LOWORD(v11));
			sub_426AA0(v4);
			*a4 += v4;
		}
		if (a2 >= 3) {
			sub_426AC0_file3_fread(&v18, 4u);
			*a4 += 4;
		}
	}
	result = sub_45A360_drawable(a1, v13[0], v13[1]);
	v6 = result;
	if (result) {
		v7 = *(_DWORD*)(result + 120) & 0xEEBF7E9D;
		*(_DWORD*)(result + 120) = v7;
		*(_DWORD*)(result + 120) = v16 | v7;
		v8 = *(_DWORD*)(result + 280);
		LOBYTE(v8) = v8 & 0xA1;
		*(_DWORD*)(v6 + 280) = v8;
		*(_DWORD*)(v6 + 280) = v18 | v8;
		*(_DWORD*)(v6 + 128) = v15;
		*(_BYTE*)(v6 + 28) = v10;
		if (!nox_common_gameFlags_check_40A5C0(1) && *(_BYTE*)(v6 + 28) &&
			(!(*(_DWORD*)(v6 + 112) & 0x10000000) || !nox_common_gameFlags_check_40A5C0(128)))
			sub_4191D0(*(_BYTE*)(v6 + 28), v6 + 24, 0, *(_DWORD*)(v6 + 128), 0);
		result = v6;
	}
	return result;
}

//----- (004AC020) --------------------------------------------------------
int __cdecl sub_4AC020(int thingInd, __int16 a2, _DWORD* a3) {
	_DWORD* v3;          // esi
	__int16 v4;          // di
	__int16 v5;          // ax
	bool v6;             // cc
	int v7;              // eax
	bool v10;            // zf
	int v11;             // ecx
	int v12;             // ebx
	char v13;            // dl
	int v14;             // ebx
	int v15;             // ecx
	int v16;             // eax
	int v17;             // eax
	unsigned __int8 v18; // cl
	int v19;             // [esp-30h] [ebp-60h]
	float v20;           // [esp-24h] [ebp-54h]
	int v21;             // [esp-14h] [ebp-44h]
	int v22;             // [esp-4h] [ebp-34h]
	int v23;             // [esp+Ch] [ebp-24h]
	int v24;             // [esp+10h] [ebp-20h]
	int v25;             // [esp+14h] [ebp-1Ch]
	int v26;             // [esp+18h] [ebp-18h]
	int v27;             // [esp+1Ch] [ebp-14h]
	int v28;             // [esp+20h] [ebp-10h]
	int v29;             // [esp+24h] [ebp-Ch]
	float v30;           // [esp+28h] [ebp-8h]
	float v31;           // [esp+2Ch] [ebp-4h]

	v3 = a3;
	v4 = a2;
	v5 = 1;
	v23 = 1;
	if (a2 < 40)
		return sub_4ABDA0(thingInd, v5, v4, v3);
	sub_426AC0_file3_fread(&v23, 2u);
	v5 = v23;
	v6 = (__int16)v23 < 61;
	*v3 += 2;
	if (v6)
		return sub_4ABDA0(thingInd, v5, v4, v3);
	sub_426AC0_file3_fread(&v25, 4u);
	*v3 += 4;
	sub_426AC0_file3_fread(&v29, 4u);
	*v3 += 4;
	sub_426AC0_file3_fread(&v30, 4u);
	*v3 += 4;
	sub_426AC0_file3_fread(&v31, 4u);
	v20 = v31;
	*v3 += 4;
	v22 = nox_float2int(v20);
	v7 = nox_float2int(v30);
	int v9 = sub_45A360_drawable(thingInd, v7, v22);
	if (!v9)
		return 0;

	*(_DWORD*)(v9 + 128) = v25;
	sub_426AC0_file3_fread(&a2, 1u);
	v10 = (_BYTE)a2 == 0;
	++*v3;
	if (!v10) {
		sub_426AC0_file3_fread(&v26, 4u);
		v11 = v26;
		*v3 += 4;
		*(_DWORD*)(v9 + 120) = v11 | *(_DWORD*)(v9 + 120) & 0xEEBF7E9D;
		sub_426AC0_file3_fread(&a3, 1u);
		v12 = (unsigned __int8)a3;
		v21 = (unsigned __int8)a3;
		++*v3;
		sub_426AA0(v21);
		*v3 += v12;
		sub_426AC0_file3_fread(&thingInd, 1u);
		v13 = thingInd;
		++*v3;
		*(_BYTE*)(v9 + 28) = v13;
		sub_426AC0_file3_fread(&a3, 1u);
		++*v3;
		sub_426AC0_file3_fread(&v27, 2u);
		v14 = 4 * (unsigned __int16)v27;
		v19 = 4 * (unsigned __int16)v27;
		*v3 += 2;
		sub_426AA0(v19);
		*v3 += v14;
		sub_426AC0_file3_fread(&v28, 4u);
		v15 = v28;
		*v3 += 4;
		v16 = *(_DWORD*)(v9 + 280);
		LOBYTE(v16) = v16 & 0xA1;
		*(_DWORD*)(v9 + 280) = v15 | v16;
		if ((__int16)v23 >= 63) {
			sub_426AA0(2);
			*v3 += 2;
			sub_426AC0_file3_fread(&v24, 4u);
			*v3 += 4;
			sub_426AA0(v24);
			*v3 += v24;
			sub_426AA0(4);
			*v3 += 4;
		}
		if ((__int16)v23 >= 64) {
			sub_426AA0(4);
			*v3 += 4;
		}
	}
	if (!nox_common_gameFlags_check_40A5C0(1)) {
		v17 = *(_DWORD*)&byte_5D4594[1309788];
		if (!*(_DWORD*)&byte_5D4594[1309788]) {
			v17 = sub_44CFC0((CHAR*)&byte_587000[173444]);
			*(_DWORD*)&byte_5D4594[1309788] = v17;
		}
		v18 = *(_BYTE*)(v9 + 28);
		if (v18) {
			if (*(_DWORD*)(v9 + 108) != v17)
				sub_4191D0(v18, v9 + 24, 0, *(_DWORD*)(v9 + 128), 0);
		}
	}
	return v9;
}

//----- (004AC2B0) --------------------------------------------------------
char* __cdecl sub_4AC2B0(char* a1) {
	char* result;       // eax
	char* v2;           // eax
	int v3;             // [esp+Ch] [ebp-628h]
	int v4;             // [esp+10h] [ebp-624h]
	int v5;             // [esp+14h] [ebp-620h]
	int v6;             // [esp+18h] [ebp-61Ch]
	int v7;             // [esp+1Ch] [ebp-618h]
	int v8;             // [esp+20h] [ebp-614h]
	int v9[2];          // [esp+24h] [ebp-610h]
	char v11[256];      // [esp+2Ch] [ebp-608h]
	char v12[256];      // [esp+12Ch] [ebp-508h]
	char v13[256];      // [esp+22Ch] [ebp-408h]
	char FileName[260]; // [esp+32Ch] [ebp-308h]
	char v15[260];      // [esp+430h] [ebp-204h]
	char v16[256];      // [esp+534h] [ebp-100h]

	result = a1;
	v7 = 0;
	if (a1) {
		_splitpath(a1, &v3, v11, v13, v16);
		if (!strlen(v11)) {
			strcpy(v11, *(const char**)&byte_587000[173412]);
			strcat(v11, *(const char**)&byte_587000[173420]);
			strcat(v11, v13);
		}
		_makepath(FileName, &v3, v11, v13, v16);
		if (_access(FileName, 0) == -1) {
			_makepath(v15, &v3, v11, v13, ".nxz");
			if (_access(v15, 0) == -1)
				return 0;
			result = (char*)sub_57BC50(v15, FileName);
			if (!result)
				return result;
		}
		result = (char*)sub_426910(FileName, 1, 19);
		if (!result)
			return result;
		sub_426AC0_file3_fread(&v5, 4u);
		if (v5 != -86065425) {
			if (v5 != -86050098) {
				sub_4269F0();
				return 0;
			}
			sub_426C20(&v7, 4u);
		}
		sub_426AC0_file3_fread(&v9[0], 4u);
		sub_426AC0_file3_fread(&v9[1], 4u);
		sub_426A80(v9);
		while (1) {
			sub_426AC0_file3_fread(&v6, 1u);
			if (!(_BYTE)v6)
				break;
			sub_426AC0_file3_fread(v12, (unsigned __int8)v6);
			sub_426C20(&v8, 4u);
			v4 = 0;
			if (!strcmp(v12, "ObjectData")) {
				sub_426F40(0, v12, &v4, (int(__cdecl*)(int))nox_client_mapSpecialRWObjectData_4AC610);
			} else if (nox_common_gameFlags_check_40A5C0(1)) {
				sub_426AA0(v8);
			} else {
				sub_426EA0(0, v12, &v4);
			}
			if (v4 == 1)
				return 0;
		}
		sub_4269F0();
		sub_4BAB30();
		nullsub_20();
		sub_4B64C0();
		sub_45AC40();
		sub_4C4FD0();
		sub_451100();
		sub_445FF0();
		sub_470680();
		sub_461520();
		sub_486060();
		v2 = sub_417040(*(int*)&byte_5D4594[2616328]);
		sub_422140((int)v2);
		sub_4DB230(0);
		if (*(int*)&byte_5D4594[3803228] < 0) {
			if (sub_461450() == 1) {
				sub_461400();
				sub_461440(0);
			}
			sub_470AA0(0);
		}
		result = (char*)1;
	}
	return result;
}
// 4BB9C0: using guessed type void nullsub_20(void);

//----- (004AC610) --------------------------------------------------------
int nox_client_mapSpecialRWObjectData_4AC610() {
	unsigned __int16 v1; // ax
	unsigned __int16 v2; // si
	int v3;              // eax
	int v4;              // [esp+4h] [ebp-Ch]
	int v5;              // [esp+8h] [ebp-8h]
	int v6;              // [esp+Ch] [ebp-4h]

	v6 = 1;
	sub_426AC0_file3_fread(&v6, 2u);
	if ((__int16)v6 > 1)
		return 0;
	if (!*(_DWORD*)&byte_5D4594[3803300])
		return 0;
	sub_426AC0_file3_fread(&v4, 2u);
	if ((_WORD)v4) {
		while (1) {
			sub_426C20(&v5, 4u);
			v1 = sub_42C2B0(v4);
			v2 = v1;
			if (!v1)
				break;
			if (sub_44D090(v1)) {
				v3 = sub_4AC6E0(v2);
				v5 -= v3;
			}
			if (v5 > 0)
				sub_426AA0(v5);
			sub_426AC0_file3_fread(&v4, 2u);
			if (!(_WORD)v4)
				return 1;
		}
		return 0;
	}
	return 1;
}

//----- (004AC6E0) --------------------------------------------------------
int __cdecl sub_4AC6E0(unsigned __int16 a1) {
	if (!*(_DWORD*)&byte_5D4594[1309792]) {
		*(_DWORD*)&byte_5D4594[1309792] = sub_44CFC0((CHAR*)&byte_587000[173476]);
		*(_DWORD*)&byte_5D4594[1309796] = sub_44CFC0((CHAR*)&byte_587000[173488]);
		*(_DWORD*)&byte_5D4594[1309800] = sub_44CFC0((CHAR*)&byte_587000[173508]);
		*(_DWORD*)&byte_5D4594[1309804] = sub_44CFC0((CHAR*)&byte_587000[173520]);
	}
	if (a1 == *(_DWORD*)&byte_5D4594[1309792] || a1 == *(_DWORD*)&byte_5D4594[1309796])
		return sub_4AC980(a1);
	if (a1 == *(_DWORD*)&byte_5D4594[1309800])
		return sub_4ACE00(a1);
	if (a1 == *(_DWORD*)&byte_5D4594[1309804])
		return sub_4ACEF0(a1);
	if (sub_44D060(a1))
		return sub_4AD040(a1);
	if (sub_44D040(a1))
		return sub_4AC7B0(a1);
	return 0;
}

//----- (004AC7B0) --------------------------------------------------------
int __cdecl sub_4AC7B0(int a1) {
	int v1;     // eax
	int v2;     // nox_drawable* ?
	int result; // eax
	int v4;     // eax
	char v5;    // al
	float v6;   // edi
	int v7;     // ecx
	double v9;  // st7
	double v10; // st7
	int v11;    // [esp+4h] [ebp-10h]
	int v12;    // [esp+8h] [ebp-Ch]
	float v13;  // [esp+Ch] [ebp-8h]
	int v14;    // [esp+10h] [ebp-4h]

	sub_426AC0_file3_fread(&v12, 2u);
	v11 = 2;
	v1 = sub_4AC020(a1, v12, &v11);
	v2 = v1;
	if (v1) {
		v4 = *(_DWORD*)(v1 + 112);
		if ((v4 & 0x80u) == 0) {
			if (v4 & 0x200) {
				sub_426AC0_file3_fread(&a1, 4u);
				sub_426AC0_file3_fread(&v14, 4u);
				v9 = (double)a1;
				v11 += 8;
				v13 = v9;
				*(float*)(v2 + 56) = v9;
				v10 = (double)v14;
				*(float*)(v2 + 60) = v10;
				if (v13 > 60.0)
					*(_DWORD*)(v2 + 56) = 1114636288;
				if (v10 > 60.0)
					*(_DWORD*)(v2 + 60) = 1114636288;
				nox_shape_box_calc((nox_shape*)(v2 + 44));
			}
		} else {
			sub_426AC0_file3_fread(&v13, 4u);
			v11 += 4;
			sub_426AC0_file3_fread(&v14, 4u);
			v5 = v14;
			v11 += 4;
			*(_BYTE*)(v2 + 433) = v14;
			*(_BYTE*)(v2 + 432) = 0;
			if (v5)
				*(_BYTE*)(v2 + 432) = 1;
			v6 = v13;
			a1 = LODWORD(v13);
			if ((__int16)v12 >= 41) {
				sub_426AC0_file3_fread(&a1, 4u);
				v6 = *(float*)&a1;
				v11 += 4;
			}
			*(_BYTE*)(v2 + 299) = LOBYTE(v13);
			v7 = *(_DWORD*)(v2 + 12) + *(int*)&byte_587000[8 * LODWORD(v6) + 196184] / 2;
			sub_410390(v2, v7 / 23, (*(_DWORD*)(v2 + 16) + *(int*)&byte_587000[8 * LODWORD(v6) + 196188] / 2) / 23);
		}
		*(_DWORD*)(v2 + 288) = 0;
		sub_45A990_drawable(v2);
		result = v11;
	} else {
		sub_4356E0();
		result = 0;
	}
	return result;
}

//----- (004AC980) --------------------------------------------------------
int __cdecl sub_4AC980(int a1) {
	int v1;               // eax
	int v2;               // esi
	unsigned __int16* v4; // edi
	_BYTE* v5;            // eax
	_BYTE* v6;            // ecx
	int v7;               // [esp+Ch] [ebp-8h]
	int v8;               // [esp+10h] [ebp-4h]

	sub_426AC0_file3_fread(&v8, 2u);
	v7 = 2;
	v1 = sub_4AC020(a1, v8, &v7);
	v2 = v1;
	if (!v1) {
		sub_4356E0();
		return 0;
	}
	if ((__int16)v8 >= 2) {
		sub_426AC0_file3_fread((_BYTE*)(v1 + 136), 4u);
		v7 += 4;
		sub_426AC0_file3_fread((_BYTE*)(v2 + 140), 4u);
		v7 += 4;
		sub_426AC0_file3_fread((_BYTE*)(v2 + 144), 4u);
		v7 += 4;
		sub_426AC0_file3_fread((_BYTE*)(v2 + 148), 4u);
		v7 += 4;
		sub_426AC0_file3_fread((_BYTE*)(v2 + 152), 0xCu);
		v4 = (unsigned __int16*)(v2 + 164);
		v7 += 12;
		sub_426AC0_file3_fread((_BYTE*)(v2 + 164), 2u);
		v7 += 2;
		sub_426AC0_file3_fread((_BYTE*)(v2 + 166), 2u);
		v7 += 2;
		sub_426AC0_file3_fread((_BYTE*)(v2 + 168), 4u);
		v7 += 4;
		sub_426AC0_file3_fread((_BYTE*)(v2 + 176), 2u);
		v7 += 2;
		sub_426AC0_file3_fread((_BYTE*)(v2 + 178), 0x30u);
		v7 += 48;
		sub_426AC0_file3_fread((_BYTE*)(v2 + 226), 0x10u);
		v7 += 16;
		sub_426AC0_file3_fread((_BYTE*)(v2 + 242), 0x10u);
		v7 += 16;
		sub_426AC0_file3_fread((_BYTE*)(v2 + 258), 2u);
		v7 += 2;
		sub_426AC0_file3_fread((_BYTE*)(v2 + 260), 2u);
		v7 += 2;
		sub_426AC0_file3_fread((_BYTE*)(v2 + 262), 2u);
		v7 += 2;
		sub_426AC0_file3_fread((_BYTE*)(v2 + 264), 4u);
		v7 += 4;
		sub_426AC0_file3_fread((_BYTE*)(v2 + 270), 2u);
		v7 += 2;
		sub_426AC0_file3_fread((_BYTE*)(v2 + 272), 2u);
		v7 += 2;
		sub_426AC0_file3_fread((_BYTE*)(v2 + 274), 1u);
		++v7;
		if ((__int16)v8 > 40) {
			if ((__int16)v8 >= 42) {
				sub_426AC0_file3_fread((_BYTE*)(v2 + 172), 4u);
				v7 += 4;
			} else {
				sub_426AC0_file3_fread(&a1, 1u);
				++v7;
				*(_DWORD*)(v2 + 172) = (unsigned __int8)a1;
			}
		}
	} else {
		sub_426AC0_file3_fread((_BYTE*)(v1 + 136), 4u);
		v7 += 4;
		sub_426AC0_file3_fread((_BYTE*)(v2 + 140), 4u);
		v7 += 4;
		sub_426AC0_file3_fread((_BYTE*)(v2 + 144), 4u);
		v7 += 4;
		sub_426AC0_file3_fread((_BYTE*)(v2 + 148), 4u);
		v7 += 4;
		sub_426AC0_file3_fread((_BYTE*)(v2 + 152), 0xCu);
		v4 = (unsigned __int16*)(v2 + 164);
		v7 += 12;
		sub_426AC0_file3_fread((_BYTE*)(v2 + 164), 2u);
		v7 += 2;
		sub_426AC0_file3_fread((_BYTE*)(v2 + 166), 2u);
		v7 += 2;
		sub_426AC0_file3_fread((_BYTE*)(v2 + 168), 4u);
		v7 += 4;
		*(_WORD*)(v2 + 176) = 0;
		*(_WORD*)(v2 + 258) = 0;
		*(_WORD*)(v2 + 260) = 0;
		*(_WORD*)(v2 + 262) = 0;
		*(_DWORD*)(v2 + 264) = 0;
		*(_WORD*)(v2 + 270) = 0;
		*(_BYTE*)(v2 + 274) = -128;
		if (*(_DWORD*)&byte_5D4594[3803300] != 1)
			goto LABEL_24;
		if (*(float*)(v2 + 140) <= 63.0 &&
			(double)*(int*)(v2 + 148) * *(double*)&byte_581450[9752] <= *(double*)&byte_581450[9744]) {
		LABEL_13:
			*(_BYTE*)(v2 + 432) = 0;
			*(_BYTE*)(v2 + 433) = 0;
			*(_BYTE*)(v2 + 434) = 0;
			v5 = (_BYTE*)(v2 + 242);
			v6 = (_BYTE*)(v2 + 179);
			do {
				if (*(v6 - 1) || *v6 || v6[1])
					++*(_BYTE*)(v2 + 432);
				if (*(v5 - 16))
					++*(_BYTE*)(v2 + 433);
				if (*v5)
					++*(_BYTE*)(v2 + 434);
				v6 += 3;
				++v5;
			} while ((int)&v5[-242 - v2] < 16);
			a1 = *v4;
			*(_WORD*)(v2 + 268) = (__int64)((double)a1 * *(double*)&byte_581450[9752] * *(double*)&byte_581450[9736]);
			goto LABEL_24;
		}
		sub_484CE0(v2 + 136, 63.0);
	}
	if (*(_DWORD*)&byte_5D4594[3803300] == 1)
		goto LABEL_13;
LABEL_24:
	*(_DWORD*)(v2 + 288) = 0;
	sub_45A990_drawable(v2);
	return v7;
}

//----- (004ACE00) --------------------------------------------------------
int __cdecl sub_4ACE00(int a1) {
	int v1;       // eax
	int v2;       // esi
	int result;   // eax
	int i;        // edi
	int v5;       // eax
	int v6;       // [esp+Ch] [ebp-10Ch]
	int v7;       // [esp+10h] [ebp-108h]
	int v8;       // [esp+14h] [ebp-104h]
	char v9[256]; // [esp+18h] [ebp-100h]

	sub_426AC0_file3_fread(&v8, 2u);
	v6 = 2;
	v1 = sub_4AC020(a1, v8, &v6);
	v2 = v1;
	if (v1) {
		*(_DWORD*)(v1 + 288) = 0;
		sub_45A990_drawable(v1);
		for (i = 0; i < 16; i += 4) {
			sub_426AC0_file3_fread(&v7, 1u);
			++v6;
			sub_426AC0_file3_fread(v9, (unsigned __int8)v7);
			v6 += (unsigned __int8)v7;
			v9[(unsigned __int8)v7] = 0;
			v5 = sub_413290(v9);
			*(_DWORD*)(i + v2 + 432) = sub_413330(v5);
			*(_WORD*)(v2 + 448) = -1;
			*(_WORD*)(v2 + 450) = -1;
		}
		result = v6;
	} else {
		sub_4356E0();
		result = 0;
	}
	return result;
}
// 4ACE00: using guessed type char var_100[256];

//----- (004ACEF0) --------------------------------------------------------
int __cdecl sub_4ACEF0(int a1) {
	int v1;     // eax
	int v2;     // edi
	int result; // eax
	_BYTE* v4;  // esi
	int v5;     // [esp+Ch] [ebp-10h]
	int v6;     // [esp+10h] [ebp-Ch]
	int v7;     // [esp+14h] [ebp-8h]
	_BYTE* v8;  // [esp+18h] [ebp-4h]

	sub_426AC0_file3_fread(&v7, 2u);
	v5 = 2;
	v1 = sub_4AC020(a1, v7, &v5);
	v2 = v1;
	if (v1) {
		v4 = (_BYTE*)(v1 + 432);
		*(_DWORD*)(v1 + 288) = 0;
		sub_45A990_drawable(v1);
		sub_426AC0_file3_fread(&v6, 4u);
		*(float*)(v2 + 56) = (double)v6;
		v5 += 4;
		sub_426AC0_file3_fread(&v6, 4u);
		*(float*)(v2 + 60) = (double)v6;
		v5 += 4;
		nox_shape_box_calc((nox_shape*)(v2 + 44));
		v4[4] = 10;
		*v4 = 90;
		v4[1] = 90;
		v4[2] = 90;
		v4[3] = 10;
		v4[5] = 10;
		v8 = v4 + 5;
		if ((__int16)v7 >= 41) {
			sub_426AC0_file3_fread(v4, 1u);
			++v5;
			sub_426AC0_file3_fread(v4 + 1, 1u);
			++v5;
			sub_426AC0_file3_fread(v4 + 2, 1u);
			++v5;
			sub_426AC0_file3_fread(v4 + 3, 1u);
			++v5;
			sub_426AC0_file3_fread(v4 + 4, 1u);
			++v5;
			sub_426AC0_file3_fread(v8, 1u);
			++v5;
		}
		result = v5;
	} else {
		sub_4356E0();
		result = 0;
	}
	return result;
}

//----- (004AD040) --------------------------------------------------------
int __cdecl sub_4AD040(int a1) {
	int v1;     // esi
	int result; // eax
	int v3;     // [esp+4h] [ebp-Ch]
	int v4;     // [esp+8h] [ebp-8h]
	int v5;     // [esp+Ch] [ebp-4h]

	sub_426AC0_file3_fread(&v4, 2u);
	v3 = 2;
	v1 = sub_4AC020(a1, v4, &v3);
	if (v1) {
		if ((__int16)v4 >= 61) {
			LOBYTE(a1) = 0;
			sub_426AC0_file3_fread(&v5, 4u);
			v3 += 4;
			sub_426AC0_file3_fread(&a1, 1u);
			++v3;
			if ((_BYTE)a1 == 1)
				sub_459DD0(v1, 1);
		}
		*(_DWORD*)(v1 + 288) = 0;
		sub_45A990_drawable(v1);
		result = v3;
	} else {
		sub_4356E0();
		result = 0;
	}
	return result;
}

//----- (004AD570) --------------------------------------------------------
int sub_4AD570() {
	int2* v0;   // edi
	_DWORD* v1; // esi

	v0 = nox_client_getMousePos_4309F0();
	if (sub_43AF70() == 1) {
		v1 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1309812, 10317);
		if (!wndIsShown_sub_46ACC0((int)v1) && !sub_46AAB0(v1, v0->field_0, v0->field_4)) {
			sub_46ADE0((int)v1);
			nox_window_set_hidden((int)v1, 1);
		}
	}
	return 1;
}

//----- (004AD5D0) --------------------------------------------------------
int __cdecl sub_4AD5D0(int a1, int a2, int* a3, int a4) {
	_DWORD* v4;  // ebx
	int v5;      // eax
	int v6;      // esi
	int v7;      // eax
	int v8;      // eax
	int v9;      // esi
	_DWORD* v10; // eax
	int result;  // eax
	int v12;     // esi
	_DWORD* v13; // esi

	if (a2 == 16391) {
		v12 = sub_46B0A0(a3);
		sub_452D80(766, 100);
		switch (v12) {
		case 10301:
			if (nox_server_doPlayersAutoRespawn_40A5F0())
				sub_40A5E0(0);
			else
				sub_40A5E0(1);
			result = 0;
			break;
		case 10302:
			nox_server_sendMotd_108752 ^= 1u;
			result = 0;
			break;
		case 10304:
			if (sub_4D0D70())
				sub_4D0D90(0);
			else
				sub_4D0D90(1);
			result = 0;
			break;
		case 10305:
			sub_409EF0(2);
			result = 0;
			break;
		case 10306:
			sub_409EF0(0x2000);
			if (sub_409F40(0x2000))
				goto LABEL_24;
			sub_4D7EA0();
			result = 0;
			break;
		case 10316:
			v13 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1309812, 10317);
			nox_window_set_hidden((int)v13, 0);
			sub_46A8C0((int)v13);
			sub_46ADC0((int)v13);
			result = 0;
			break;
		case 10319:
			sub_4BDFD0();
			goto LABEL_24;
		default:
			goto LABEL_24;
		}
	} else if (a2 == 16393) {
		sub_40A6D0(4 - a4);
		result = 0;
	} else if (a2 != 16400 || sub_46B0A0(a3) != 10317 ||
			   (v4 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1309812, 10316),
				v5 = nox_window_call_field_94((int)a3, 16404, 0, 0), v6 = v5, v5 < 0) ||
			   v5 >= *(__int16*)(a3[8] + 44)) {
	LABEL_24:
		result = 0;
	} else {
		v7 = nox_window_call_field_94((int)a3, 16406, a4, 0);
		nox_window_call_field_94((int)v4, 16385, v7, -1);
		dword_5d4594_3596 = v6 + 1;
		v8 = sub_40A710(v6 + 1);
		sub_40A6D0(v8);
		v9 = 4 - sub_40A6C0();
		v10 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1309812, 10312);
		nox_window_call_field_94((int)v10, 16394, v9, 0);
		nox_window_set_hidden((int)a3, 1);
		sub_46ADE0((int)a3);
		result = 0;
	}
	return result;
}

//----- (004AD820) --------------------------------------------------------
int sub_4AD820() {
	sub_46C4E0(*(_DWORD**)&dword_5d4594_1309812);
	dword_5d4594_1309812 = 0;
	return sub_4BE610();
}

//----- (004AD9B0) --------------------------------------------------------
int __cdecl sub_4AD9B0(int a1) {
	if (wndIsShown_sub_46ACC0(*(int*)&dword_5d4594_1309820))
		return 0;
	sub_413A00(0);
	sub_44D8F0();
	if (a1) {
		nox_window_set_hidden(*(int*)&dword_5d4594_1309820, 1);
		nox_window_set_hidden(*(int*)&dword_5d4594_1309824, 1);
	} else {
		nox_common_writecfgfile((char*)&byte_587000[174124]);
		nox_window_set_hidden(*(int*)&dword_5d4594_1309820, 1);
		nox_window_set_hidden(*(int*)&dword_5d4594_1309824, 1);
		sub_445C40();
	}
	return 1;
}

//----- (004ADA40) --------------------------------------------------------
int sub_4ADA40() {
	int v0;     // eax
	_DWORD* v1; // eax
	int v3;     // [esp-4h] [ebp-4h]

	sub_413A00(1);
	sub_46A8C0(*(int*)&dword_5d4594_1309820);
	sub_46A8C0(*(int*)&dword_5d4594_1309824);
	sub_4CB330();
	v0 = sub_4766D0();
	if (v0 > 69) {
		if (v0 <= 79) {
			v1 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1309820, 312);
			goto LABEL_9;
		}
		if (v0 <= 89) {
			v1 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1309820, 313);
			goto LABEL_9;
		}
		v3 = 314;
	} else {
		v3 = 311;
	}
	v1 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1309820, v3);
LABEL_9:
	if (v1)
		nox_window_call_field_94((int)v1, 16392, 0, 0);
	return sub_43FE20(15);
}

//----- (004ADAD0) --------------------------------------------------------
int sub_4ADAD0() {
	int result;       // eax
	_DWORD* v1;       // esi
	char* v2;         // eax
	int v3;           // eax
	int v4;           // ecx
	unsigned int v5;  // ecx
	_DWORD* v6;       // esi
	char* v7;         // eax
	int v8;           // eax
	int v9;           // ecx
	unsigned int v10; // ecx
	_DWORD* v11;      // esi
	char* v12;        // eax
	int v13;          // eax
	int v14;          // ecx
	unsigned int v15; // ecx
	_DWORD* v16;      // eax
	_DWORD* v17;      // eax
	int i;            // esi
	_DWORD* v19;      // eax
	int v20;          // eax
	int* v21;         // esi
	_DWORD* v22;      // eax
	int v23;          // kr00_4
	_DWORD* v24;      // eax
	char* v25;        // [esp-Ch] [ebp-18h]
	char* v26;        // [esp-Ch] [ebp-18h]
	char* v27;        // [esp-Ch] [ebp-18h]
	char* v28;        // [esp-8h] [ebp-14h]
	char* v29;        // [esp-8h] [ebp-14h]
	char* v30;        // [esp-8h] [ebp-14h]
	int v31;          // [esp-8h] [ebp-14h]
	int v32;          // [esp+0h] [ebp-Ch]
	int v33;          // [esp+4h] [ebp-8h]
	int v34;          // [esp+8h] [ebp-4h]

	result = nox_new_window_from_file("Options.wnd", sub_4ADF30);
	dword_5d4594_1309820 = result;
	if (result) {
		result = sub_4CB590(result);
		if (result) {
			v1 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1309820, 351);
			*(_DWORD*)(v1[100] + 8) = 24;
			*(_DWORD*)(v1[100] + 12) = 20;
			v28 = sub_42F970("OptionsVolumeSliderLit");
			v25 = sub_42F970("OptionsVolumeSliderLit");
			v2 = sub_42F970("OptionsVolumeSlider");
			sub_4B5700((int)v1, 0, 0, (int)v2, (int)v25, (int)v28);
			nox_window_call_field_94((int)v1, 16395, 0, 0x4000);
			nox_window_call_field_94((int)v1, 16394, *(_DWORD*)(dword_587000_127004 + 4) >> 16, 0);
			dword_5d4594_1309828 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1309820, 361);
			v3 = sub_453070();
			v4 = *(_DWORD*)(dword_5d4594_1309828 + 36);
			if (v3 == 1)
				v5 = v4 | 4;
			else
				v5 = v4 & 0xFFFFFFFB;
			*(_DWORD*)(dword_5d4594_1309828 + 36) = v5;
			v6 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1309820, 352);
			*(_DWORD*)(v6[100] + 8) = 24;
			*(_DWORD*)(v6[100] + 12) = 20;
			v29 = sub_42F970("OptionsVolumeSliderLit");
			v26 = sub_42F970("OptionsVolumeSliderLit");
			v7 = sub_42F970("OptionsVolumeSlider");
			sub_4B5700((int)v6, 0, 0, (int)v7, (int)v26, (int)v29);
			nox_window_call_field_94((int)v6, 16395, 0, 0x4000);
			nox_window_call_field_94((int)v6, 16394, *(_DWORD*)(dword_587000_122852 + 4) >> 16, 0);
			dword_5d4594_1309836 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1309820, 362);
			v8 = sub_44D990();
			v9 = *(_DWORD*)(dword_5d4594_1309836 + 36);
			if (v8 == 1)
				v10 = v9 | 4;
			else
				v10 = v9 & 0xFFFFFFFB;
			*(_DWORD*)(dword_5d4594_1309836 + 36) = v10;
			v11 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1309820, 353);
			*(_DWORD*)(v11[100] + 8) = 24;
			*(_DWORD*)(v11[100] + 12) = 20;
			v30 = sub_42F970("OptionsVolumeSliderLit");
			v27 = sub_42F970("OptionsVolumeSliderLit");
			v12 = sub_42F970("OptionsVolumeSlider");
			sub_4B5700((int)v11, 0, 0, (int)v12, (int)v27, (int)v30);
			nox_window_call_field_94((int)v11, 16395, 0, 0x4000);
			nox_window_call_field_94((int)v11, 16394, *(_DWORD*)(dword_587000_93164 + 4) >> 16, 0);
			dword_5d4594_1309832 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1309820, 363);
			v13 = sub_43DC30();
			v14 = *(_DWORD*)(dword_5d4594_1309832 + 36);
			if (v13 == 1)
				v15 = v14 | 4;
			else
				v15 = v14 & 0xFFFFFFFB;
			*(_DWORD*)(dword_5d4594_1309832 + 36) = v15;
			sub_43BEB0_get_video_mode(&v32, &v34, &v33);
			if (v34 == 480)
				v31 = 321;
			else if (v34 == 576)
				v31 = 322;
			else
				v31 = 323;
			v16 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1309820, v31);
			nox_window_call_field_94((int)v16, 16392, 1, 0);
			if (g_fullscreen)
				v17 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1309820, 333);
			else
				v17 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1309820, 334);
			nox_window_call_field_94((int)v17, 16392, 1, 0);
			nox_window_call_field_94(sub_46B0C0(*(_DWORD**)&dword_5d4594_1309820, 316), 16394, (draw_gamma - 0.5f) * 50,
									 0);
			nox_window_call_field_94(sub_46B0C0(*(_DWORD**)&dword_5d4594_1309820, 318), 16394,
									 (log10f(input_sensitivity) + 1.0f) * 50, 0);
			for (i = 320; i <= 332; ++i) {
				v19 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1309820, i);
				if (v19 && !(v19[9] & 4))
					sub_46AD80((int)v19, 8);
			}
			dword_5d4594_1309824 = nox_window_new(0, 32, 0, 0, 1, 1, 0);
			v20 = *(_DWORD*)&byte_587000[174072];
			if (*(int*)&byte_587000[174072] != -1) {
				v21 = (int*)&byte_587000[174080];
				do {
					v22 = nox_window_new(*(int*)&dword_5d4594_1309824, 0, v20, *(v21 - 1), *v21, v21[1], 0);
					sub_46B340((int)v22, sub_4ADEF0);
					v20 = v21[2];
					v21 += 4;
				} while (v20 != -1);
			}
			v23 = nox_win_width - *(_DWORD*)(dword_5d4594_1309820 + 8);
			nox_wnd_sub_46A9B0(*(_DWORD**)&dword_5d4594_1309820, v23 / 2, 0);
			nox_wnd_sub_46A9B0(*(_DWORD**)&dword_5d4594_1309824, v23 / 2, 0);
			v24 = sub_46B0C0(*(_DWORD**)&dword_5d4594_1309820, 371);
			nox_window_set_hidden((int)v24, 0);
			nox_window_set_hidden(*(int*)&dword_5d4594_1309820, 1);
			nox_window_set_hidden(*(int*)&dword_5d4594_1309824, 1);
			result = 1;
		}
	}
	return result;
}

//----- (004ADEF0) --------------------------------------------------------
int __cdecl sub_4ADEF0(_DWORD* a1, int a2) {
	int xLeft; // [esp+4h] [ebp-8h]
	int yTop;  // [esp+8h] [ebp-4h]

	nox_client_wndGetPosition_46AA60(a1, &xLeft, &yTop);
	nox_client_drawRectFilledAlpha_49CF10(xLeft, yTop, a1[2], a1[3]);
	return 1;
}

//----- (004ADF30) --------------------------------------------------------
int __cdecl sub_4ADF30(int a1, int a2, int* a3, int a4) {
	int result;                                 // eax
	int v5;                                     // edi
	int v6;                                     // esi
	void(__cdecl * v7)(_DWORD, int, int, int);  // eax
	void(__cdecl * v8)(_DWORD, int, int, int);  // eax
	void(__cdecl * v9)(_DWORD, int, int, int);  // eax
	void* v10;                                  // ecx
	void(__cdecl * v11)(void*, int, int, int);  // eax
	void(__cdecl * v12)(_DWORD, int, int, int); // eax
	int v13;                                    // ecx
	void(__cdecl * v14)(int, int, int, int);    // eax
	int v15;                                    // eax
	void(__cdecl * v16)(_DWORD, int, int, int); // eax
	void(__cdecl * v17)(_DWORD, int, int, int); // eax

	switch (a2) {
	case 16389:
		sub_452D80(920, 100);
		result = 1;
		break;
	case 16391:
		switch (sub_46B0A0(a3)) {
		case 311:
			sub_476700(65, 0);
			break;
		case 312:
			sub_476700(75, 0);
			break;
		case 313:
			sub_476700(85, 0);
			break;
		case 314:
			sub_476700(100, 0);
			break;
		case 341:
			sub_4AD9B0(0);
			sub_445C40();
			sub_4C4260();
			break;
		case 361:
			if (sub_453070() == 1)
				sub_453050();
			else
				sub_453060();
			break;
		case 362:
			if (sub_44D990() == 1)
				sub_44D960();
			else
				sub_44D970();
			break;
		case 363:
			if (sub_43DC30() == 1) {
				sub_43DC00();
			} else {
				sub_43DC10();
				sub_486320(*(_DWORD**)&dword_587000_93164, *(_DWORD*)(dword_587000_93164 + 4) >> 16);
			}
			break;
		case 371:
			sub_4AD9B0(0);
			break;
		default:
			break;
		}
		sub_452D80(921, 100);
		result = 1;
		break;
	case 16393:
		v5 = sub_46B0A0(a3);
		v6 = sub_46C720();
		switch (v5) {
		case 351:
			sub_486320(*(_DWORD**)&dword_587000_127004, a4);
			if (v6 && *(int**)(v6 + 396) == a3)
				goto LABEL_64;
			if (a4) {
				if (sub_453070())
					goto LABEL_63;
				v13 = dword_5d4594_1309828;
				v14 = *(void(__cdecl**)(int, int, int, int))(dword_5d4594_1309828 + 372);
				if (!v14)
					goto LABEL_63;
				goto LABEL_62;
			}
			if (sub_453070() != 1)
				goto LABEL_64;
			v12 = *(void(__cdecl**)(_DWORD, int, int, int))(dword_5d4594_1309828 + 372);
			if (!v12)
				goto LABEL_64;
			v12(dword_5d4594_1309828, 21, 28, 2);
			result = 0;
			break;
		case 352:
			sub_486320(*(_DWORD**)&dword_587000_122852, a4);
			if (a4) {
				if (sub_44D990())
					goto LABEL_37;
				v10 = *(void**)&dword_5d4594_1309836;
				v11 = *(void(__cdecl**)(void*, int, int, int))(dword_5d4594_1309836 + 372);
				if (!v11)
					goto LABEL_37;
				goto LABEL_36;
			}
			if (sub_44D990() != 1)
				goto LABEL_64;
			v9 = *(void(__cdecl**)(_DWORD, int, int, int))(dword_5d4594_1309836 + 372);
			if (!v9)
				goto LABEL_64;
			v9(dword_5d4594_1309836, 21, 28, 2);
			result = 0;
			break;
		case 353:
			sub_486320(*(_DWORD**)&dword_587000_93164, a4);
			if (a4) {
				if (sub_43DC30())
					goto LABEL_64;
				v8 = *(void(__cdecl**)(_DWORD, int, int, int))(dword_5d4594_1309832 + 372);
				if (!v8)
					goto LABEL_64;
				v8(dword_5d4594_1309832, 21, 28, 2);
				result = 0;
			} else {
				if (sub_43DC30() != 1)
					goto LABEL_64;
				v7 = *(void(__cdecl**)(_DWORD, int, int, int))(dword_5d4594_1309832 + 372);
				if (!v7)
					goto LABEL_64;
				v7(dword_5d4594_1309832, 21, 28, 2);
				result = 0;
			}
			break;
		case 316: // gamma slider
			draw_gamma = 0.5 + a4 / 50.0f;
			break;
		case 318: // input sensitivity slider
			input_sensitivity = powf(10.0, a4 / 50.0f - 1.0);
			break;
		default:
			goto LABEL_64;
		}
		break;
	case 16396:
		v15 = sub_46B0A0(a3) - 351;
		if (v15) {
			if (v15 != 1)
				goto LABEL_64;
			sub_486320(*(_DWORD**)&dword_587000_122852, a4);
			if (a4) {
				if (!sub_44D990()) {
					v10 = *(void**)&dword_5d4594_1309836;
					v11 = *(void(__cdecl**)(void*, int, int, int))(dword_5d4594_1309836 + 372);
					if (v11)
					LABEL_36:
						v11(v10, 21, 28, 2);
				}
			LABEL_37:
				sub_4AA650();
				result = 0;
			} else {
				if (sub_44D990() != 1)
					goto LABEL_64;
				v16 = *(void(__cdecl**)(_DWORD, int, int, int))(dword_5d4594_1309836 + 372);
				if (!v16)
					goto LABEL_64;
				v16(dword_5d4594_1309836, 21, 28, 2);
				result = 0;
			}
		} else {
			sub_486320(*(_DWORD**)&dword_587000_127004, a4);
			if (a4) {
				if (!sub_453070()) {
					v13 = dword_5d4594_1309828;
					v14 = *(void(__cdecl**)(int, int, int, int))(dword_5d4594_1309828 + 372);
					if (v14)
					LABEL_62:
						v14(v13, 21, 28, 2);
				}
			LABEL_63:
				sub_452D80(768, 100);
				goto LABEL_64;
			}
			if (sub_453070() != 1)
				goto LABEL_64;
			v17 = *(void(__cdecl**)(_DWORD, int, int, int))(dword_5d4594_1309828 + 372);
			if (!v17)
				goto LABEL_64;
			v17(dword_5d4594_1309828, 21, 28, 2);
			result = 0;
		}
		break;
	default:
	LABEL_64:
		result = 0;
		break;
	}
	return result;
}
// 4AE184: variable 'v10' is possibly undefined

//----- (004AE3B0) --------------------------------------------------------
int sub_4AE3B0() {
	int result; // eax

	result = sub_46C4E0(*(_DWORD**)&dword_5d4594_1309820);
	dword_5d4594_1309820 = 0;
	return result;
}

//----- (004AE3D0) --------------------------------------------------------
BOOL sub_4AE3D0() {
	BOOL result; // eax

	if (wndIsShown_sub_46ACC0(*(int*)&dword_5d4594_1309820))
		result = sub_4C4280();
	else
		result = 1;
	return result;
}

//----- (004AE400) --------------------------------------------------------
int sub_4AE400() { return 1; }

//----- (004AE420) --------------------------------------------------------
int sub_4AE420() {
	int result; // eax

	if (*(_DWORD*)&byte_5D4594[3798692] >= 3)
		nox_client_drawAddPoint_49F500(*(_DWORD*)(dword_5d4594_3798696 + 8 * *(_DWORD*)&byte_5D4594[3798692] - 24),
									   *(_DWORD*)(dword_5d4594_3798696 + 8 * *(_DWORD*)&byte_5D4594[3798692] - 20));
	result = (*(int(__cdecl**)(_DWORD)) & dword_5d4594_3798716)(1);
	if (result) {
		result = (*(int(__cdecl**)(_DWORD)) & dword_5d4594_3798716)(1);
		if (result)
			result = (*(int(__cdecl**)(_DWORD)) & dword_5d4594_3798716)(0);
	}
	return result;
}

//----- (004AE470) --------------------------------------------------------
int sub_4AE470() {
	int result;           // eax
	int v1;               // edx
	unsigned __int16* v2; // eax
	unsigned __int16* v3; // ecx

	sub_4AEBD0();
	if (*(_DWORD*)&byte_5D4594[3798692] >= 3)
		nox_client_drawAddPoint_49F500(*(_DWORD*)(dword_5d4594_3798696 + 8 * *(_DWORD*)&byte_5D4594[3798692] - 24),
									   *(_DWORD*)(dword_5d4594_3798696 + 8 * *(_DWORD*)&byte_5D4594[3798692] - 20));
	result = sub_4AEC20(1, 0);
	if (result) {
		result = sub_4AEC20(1, 0);
		if (result) {
			result = sub_4AEC20(0, 1);
			if (result) {
				v1 = dword_5d4594_3798636;
				for (result = dword_5d4594_3798640; v1 <= *(int*)&dword_5d4594_3798640; dword_5d4594_3798636 = v1) {
					v2 = *(unsigned __int16**)(dword_5d4594_3798632 + 4 * v1);
					v3 = (unsigned __int16*)*((_DWORD*)v2 + 1);
					if (*((_DWORD*)v3 + 1)) {
						(*(void(__cdecl**)(_DWORD, _DWORD, _DWORD)) & dword_5d4594_3798720)(*v2, v1, *v3);
						v1 = dword_5d4594_3798636;
					}
					result = dword_5d4594_3798640;
					++v1;
				}
			}
		}
	}
	return result;
}

//----- (004AE520) --------------------------------------------------------
int sub_4AE520() {
	int result; // eax

	result = sub_4AEDF0();
	if (result) {
		sub_4AEE30();
		result = 1;
	}
	return result;
}

//----- (004AE540) --------------------------------------------------------
void sub_4AE540() {
	if (dword_5d4594_3798632) {
		free(*(LPVOID*)&dword_5d4594_3798632);
		dword_5d4594_3798632 = 0;
	}
	if (dword_5d4594_3798644) {
		free(*(LPVOID*)&dword_5d4594_3798644);
		dword_5d4594_3798644 = 0;
	}
}

//----- (004AE580) --------------------------------------------------------
int __cdecl sub_4AE580(int a1) {
	if (*(_DWORD*)&byte_5D4594[3798692] >= a1)
		nox_client_drawAddPoint_49F500(
			*(_DWORD*)(dword_5d4594_3798696 + 8 * (*(_DWORD*)&byte_5D4594[3798692] - a1)),
			*(_DWORD*)(dword_5d4594_3798696 + 8 * (*(_DWORD*)&byte_5D4594[3798692] - a1) + 4));
	return sub_49E510(a1);
}

//----- (004AE5C0) --------------------------------------------------------
int __cdecl sub_4AE5C0(int a1) {
	int v1;              // edx
	int result;          // eax
	int v3;              // edi
	int v4;              // eax
	char* v5;            // ecx
	char* v6;            // esi
	unsigned int v7;     // edi
	unsigned __int16 v8; // ax
	unsigned __int16 v9; // cx
	char v10[16];        // [esp+0h] [ebp-10h]

	sub_4AE5E0(a1, 1);
	v1 = dword_5d4594_3798636;
	for (result = dword_5d4594_3798640; v1 <= *(int*)&dword_5d4594_3798640; dword_5d4594_3798636 = v1) {
		v3 = 0;
		v4 = *(_DWORD*)(dword_5d4594_3798632 + 4 * v1);
		if (v4) {
			v5 = v10;
			do {
				++v3;
				*(_WORD*)v5 = *(_WORD*)v4;
				v4 = *(_DWORD*)(v4 + 4);
				v5 += 2;
			} while (v4);
			if (v3 >= 2) {
				sub_48C5B0((__int16*)v10, v3);
				v6 = v10;
				v7 = (unsigned int)v3 >> 1;
				do {
					v8 = *(_WORD*)v6;
					v9 = *((_WORD*)v6 + 1);
					v6 += 4;
					(*(void(__cdecl**)(_DWORD, _DWORD, _DWORD)) & dword_5d4594_3798720)(v8, dword_5d4594_3798636, v9);
					--v7;
				} while (v7);
				v1 = dword_5d4594_3798636;
			}
		}
		result = dword_5d4594_3798640;
		++v1;
	}
	return result;
}

//----- (004AE5E0) --------------------------------------------------------
BOOL __cdecl sub_4AE5E0(int a1, int a2) {
	int v2; // esi

	v2 = a1;
	if (*(_DWORD*)&byte_5D4594[3798692] >= a1)
		nox_client_drawAddPoint_49F500(
			*(_DWORD*)(dword_5d4594_3798696 + 8 * (*(_DWORD*)&byte_5D4594[3798692] - a1)),
			*(_DWORD*)(dword_5d4594_3798696 + 8 * (*(_DWORD*)&byte_5D4594[3798692] - a1) + 4));
	if (a2)
		sub_4AEBD0();
	if (a1 <= 1)
		return sub_4AEC20(0, 1) != 0;
	while (sub_4AEC20(1, 0)) {
		if (--v2 <= 1)
			return sub_4AEC20(0, 1) != 0;
	}
	return 0;
}

//----- (004AE6F0) --------------------------------------------------------
int __cdecl sub_4AE6F0(int a1, int a2, int a3, int a4, int a5) {
	int result;                         // eax
	int v6;                             // ecx
	int v7;                             // ebp
	int v8;                             // edi
	int v9;                             // ebx
	void(__cdecl * v10)(int, int, int); // edi
	int v11;                            // ebp
	int v12;                            // edx
	int v13;                            // esi
	unsigned __int16* v14;              // ebx
	unsigned __int16* v15;              // ecx
	unsigned __int16 v16;               // ax
	unsigned __int16* v17;              // ebx
	unsigned __int16* v18;              // ecx
	unsigned __int16 v19;               // ax
	unsigned __int16* v20;              // ebx
	unsigned __int16* v21;              // ecx
	unsigned __int16 v22;               // ax
	int v23;                            // eax
	unsigned __int16* v24;              // ebx
	unsigned __int16* v25;              // ecx
	unsigned __int16 v26;               // ax
	bool v27;                           // cc
	int v28;                            // [esp-14h] [ebp-38h]
	int v29;                            // [esp-10h] [ebp-34h]
	int v30;                            // [esp+4h] [ebp-20h]
	int v31;                            // [esp+8h] [ebp-1Ch]
	int v32;                            // [esp+Ch] [ebp-18h]
	int v33;                            // [esp+10h] [ebp-14h]
	int v34;                            // [esp+14h] [ebp-10h]
	int v35;                            // [esp+18h] [ebp-Ch]
	int v36;                            // [esp+1Ch] [ebp-8h]
	int v37;                            // [esp+20h] [ebp-4h]
	int v38;                            // [esp+2Ch] [ebp+8h]
	int v39;                            // [esp+30h] [ebp+Ch]
	int v40;                            // [esp+34h] [ebp+10h]
	int v41;                            // [esp+38h] [ebp+14h]

	v31 = 1 - a3;
	v35 = 0;
	v37 = a3;
	v34 = 3;
	v32 = 5 - 2 * a3;
	result = nox_client_drawSetColor_434460(a5);
	v6 = a4;
	if (a4 < 0) {
		v6 = 0;
	LABEL_4:
		v7 = (a3 * *(int*)&byte_5D4594[4 * (256 - v6) + 1310096]) >> 16;
		v30 = (a3 * *(int*)&byte_5D4594[4 * (256 - v6) + 1310096]) >> 16;
		v8 = (a3 * *(int*)&byte_5D4594[4 * (256 - v6) + 1309840]) >> 16;
		sub_4AEBD0();
		v9 = a2;
		v41 = a2 - a3;
		nox_client_drawAddPoint_49F500(a1, a2 - a3);
		nox_client_drawAddPoint_49F500(a1, a2);
		sub_4AEC20(0, 0);
		nox_client_drawAddPoint_49F500(a1, a2);
		nox_client_drawAddPoint_49F500(a1 + v7, a2 + v8);
		sub_4AEC20(0, 1);
		v10 = *(void(__cdecl**)(int, int, int)) & dword_5d4594_3798708;
		if (!ptr_5D4594_3799572->data[13])
			v10 = *(void(__cdecl**)(int, int, int)) & dword_5d4594_3798720;
		v11 = a2 + a3;
		v12 = a2 - a3;
		v38 = 0;
		v39 = v9;
		v40 = v9;
		v36 = 4 * v9;
		v33 = 4 * v41;
		v13 = a1 - v9;
		while (1) {
			if (v38) {
				if (v12 < *(int*)&dword_5d4594_3798636 || v12 > *(int*)&dword_5d4594_3798640) {
					if (v30 <= 0)
						v10(v13 + v40, v12, v13 + v39);
				} else {
					v14 = *(unsigned __int16**)(v33 + dword_5d4594_3798632);
					v15 = (unsigned __int16*)*((_DWORD*)v14 + 1);
					if (v15) {
						if (*v14 > *v15) {
							v16 = *v14;
							*v14 = *v15;
							*v15 = v16;
						}
						if (v30 > 0) {
							v10(*v14, v41, **((unsigned __int16**)v14 + 1));
						} else {
							v10(v13 + v40, v41, *v14);
							v10(**((unsigned __int16**)v14 + 1), v41, v13 + v39);
						}
					} else {
						v10(*v14, v12, v13 + v39);
					}
				}
			}
			if (v35) {
				if (v40 < *(int*)&dword_5d4594_3798636 || v40 >= *(int*)&dword_5d4594_3798640) {
					if (v30 <= 0)
						v10(v13 + v41, v40, v13 + v11);
				} else {
					v17 = *(unsigned __int16**)(v36 + dword_5d4594_3798632);
					v18 = (unsigned __int16*)*((_DWORD*)v17 + 1);
					if (v18) {
						if (*v17 > *v18) {
							v19 = *v17;
							*v17 = *v18;
							*v18 = v19;
						}
						if (v30 > 0) {
							v10(*v17, v40, **((unsigned __int16**)v17 + 1));
						} else {
							v10(v13 + v41, v40, *v17);
							v10(**((unsigned __int16**)v17 + 1), v40, v13 + v11);
						}
					} else {
						v10(*v17, v40, v13 + v11);
					}
				}
			}
			if (v39 >= *(int*)&dword_5d4594_3798636 && v39 < *(int*)&dword_5d4594_3798640)
				break;
			if (v30 <= 0) {
				v29 = v13 + v11;
				v28 = v39;
				v23 = v13 + v41;
			LABEL_42:
				v10(v23, v28, v29);
			}
		LABEL_43:
			if (v38) {
				if (v11 < *(int*)&dword_5d4594_3798636 || v11 > *(int*)&dword_5d4594_3798640) {
					if (v30 <= 0)
						v10(v13 + v40, v11, v13 + v39);
				} else {
					v24 = *(unsigned __int16**)(dword_5d4594_3798632 + 4 * v11);
					v25 = (unsigned __int16*)*((_DWORD*)v24 + 1);
					if (v25) {
						if (*v24 > *v25) {
							v26 = *v24;
							*v24 = *v25;
							*v25 = v26;
						}
						if (v30 > 0) {
							v10(*v24, v11, **((unsigned __int16**)v24 + 1));
						} else {
							v10(v13 + v40, v11, *v24);
							v10(**((unsigned __int16**)v24 + 1), v11, v13 + v39);
						}
					} else {
						v10(*v24, v11, v13 + v39);
					}
				}
			}
			if ((int)v31 >= 0) {
				v31 += v32;
				v33 += 4;
				v12 = v41 + 1;
				v32 += 4;
				v38 = 1;
				--v37;
				++v41;
				--v11;
			} else {
				v31 += v34;
				v12 = v41;
				v32 += 2;
				v38 = 0;
			}
			v34 += 2;
			result = v35 + 1;
			++v39;
			v36 -= 4;
			v27 = v37 < ++v35;
			--v40;
			if (v27)
				return result;
		}
		v20 = *(unsigned __int16**)(dword_5d4594_3798632 + 4 * v39);
		v21 = (unsigned __int16*)*((_DWORD*)v20 + 1);
		if (v21) {
			if (*v20 > *v21) {
				v22 = *v20;
				*v20 = *v21;
				*v21 = v22;
			}
			if (v30 > 0) {
				v10(*v20, v39, **((unsigned __int16**)v20 + 1));
			} else {
				v10(v13 + v41, v39, *v20);
				v10(**((unsigned __int16**)v20 + 1), v39, v13 + v11);
			}
			goto LABEL_43;
		}
		v29 = v13 + v11;
		v28 = v39;
		v23 = *v20;
		goto LABEL_42;
	}
	if (a4 < 256)
		goto LABEL_4;
	return result;
}

//----- (004AEBD0) --------------------------------------------------------
int sub_4AEBD0() {
	int v0;     // eax
	int result; // eax

	dword_5d4594_3798648 = dword_5d4594_3798644;
	v0 = 0;
	dword_5d4594_3798640 = 0;
	for (dword_5d4594_3798636 = 0; dword_5d4594_3798636 < nox_backbuffer_height; ++dword_5d4594_3798636) {
		*(_DWORD*)(dword_5d4594_3798632 + 4 * v0) = 0;
		v0 = dword_5d4594_3798636 + 1;
	}
	result = v0 - 1;
	dword_5d4594_3798636 = result;
	return result;
}

//----- (004AEC20) --------------------------------------------------------
int __cdecl sub_4AEC20(int a1, int a2) {
	int result; // eax
	int v3;     // eax
	int v4;     // ecx
	int v5;     // eax
	int v6;     // ebx
	int v7;     // esi
	int v8;     // edi
	int v9;     // edx
	int v10;    // [esp+0h] [ebp-10h]
	int v11;    // [esp+4h] [ebp-Ch]
	int v12;    // [esp+8h] [ebp-8h]
	int v13;    // [esp+Ch] [ebp-4h]

	result = sub_49F5B0(&v12, &v13, 0);
	if (result) {
		result = sub_49F5B0(&v10, &v11, a1);
		if (result) {
			if (sub_49FC20(&v10, &v11, &v12, &v13)) {
				v3 = v12 - v10;
				v10 <<= 16;
				v4 = v11;
				v5 = v3 << 16;
				if (v11 > v13) {
					v6 = -1;
					v7 = v11 - v13;
					v5 /= v11 - v13;
					if (v13 < *(int*)&dword_5d4594_3798636)
						dword_5d4594_3798636 = v13;
					if (v11 > *(int*)&dword_5d4594_3798640)
						dword_5d4594_3798640 = v11;
				} else {
					v6 = 1;
					v7 = v13 - v11;
					if (v13 != v11)
						v5 /= v7;
					if (v11 < *(int*)&dword_5d4594_3798636)
						dword_5d4594_3798636 = v11;
					if (v13 > *(int*)&dword_5d4594_3798640)
						dword_5d4594_3798640 = v13;
				}
				if (v7 > 0) {
					do {
						v8 = *(_DWORD*)(dword_5d4594_3798632 + 4 * v4);
						*(_DWORD*)(dword_5d4594_3798632 + 4 * v4) = dword_5d4594_3798648;
						**(_WORD**)&dword_5d4594_3798648 = HIWORD(v10);
						*(_DWORD*)(dword_5d4594_3798648 + 4) = v8;
						dword_5d4594_3798648 += 8;
						v4 = v6 + v11;
						--v7;
						v10 += v5;
						v11 += v6;
					} while (v7);
				}
				if (a2) {
					v9 = *(_DWORD*)(dword_5d4594_3798632 + 4 * v4);
					*(_DWORD*)(dword_5d4594_3798632 + 4 * v4) = dword_5d4594_3798648;
					**(_WORD**)&dword_5d4594_3798648 = v12;
					*(_DWORD*)(dword_5d4594_3798648 + 4) = v9;
					dword_5d4594_3798648 += 8;
				}
				result = 1;
			} else {
				result = 1;
			}
		}
	}
	return result;
}

//----- (004AEDA0) --------------------------------------------------------
int __cdecl sub_4AEDA0(int* a1, int* a2, int a3, int a4) {
	int result; // eax

	result = a3;
	if (a3 >= 0) {
		if (a3 > 256)
			result = 256;
	} else {
		result = 0;
	}
	if (a1)
		*a1 = (a4 * *(int*)&byte_5D4594[4 * result + 1310096]) >> 16;
	if (a2) {
		result = (a4 * *(int*)&byte_5D4594[4 * result + 1309840]) >> 16;
		*a2 = result;
	}
	return result;
}

//----- (004AEDF0) --------------------------------------------------------
void* sub_4AEDF0() {
	void* result; // eax

	result = nox_malloc(4 * nox_backbuffer_height);
	dword_5d4594_3798632 = result;
	if (result) {
		dword_5d4594_3798644 = nox_malloc(nox_backbuffer_height << 6);
		result = (void*)(dword_5d4594_3798644 != 0);
	}
	return result;
}

//----- (004AEE30) --------------------------------------------------------
__int64 sub_4AEE30() {
	int v0;              // edi
	unsigned __int8* v1; // esi
	__int64 result;      // rax

	v0 = 0;
	v1 = &byte_5D4594[1309840];
	do {
		result = (__int64)(sin((double)(v0 + 192) * *(double*)&byte_581450[9768] * *(double*)&byte_581450[9760]) *
						   *(double*)&qword_581450_9552);
		*(_DWORD*)v1 = result;
		v1 += 4;
		++v0;
	} while ((int)v1 < (int)&byte_5D4594[1311120]);
	return result;
}

//----- (004AEE80) --------------------------------------------------------
int sub_4AEE80() { return 1; }

//----- (004AEEA0) --------------------------------------------------------
unsigned __int8* __cdecl sub_4AEEA0(unsigned __int8** a1) {
	unsigned __int8* result; // eax

	sub_4AF8C0(a1);
	result = a1[1];
	if (result) {
		sub_4AF890(a1);
		result = (unsigned __int8*)sub_4AF690(a1, sub_4AEED0);
	}
	return result;
}

//----- (004AEED0) --------------------------------------------------------
char* __cdecl sub_4AEED0(int* a1, int a2, int a3) {
	int v3;       // eax
	int* v4;      // edi
	int v5;       // esi
	int v6;       // eax
	char* result; // eax
	char* v8;     // esi
	int v9;       // eax

	sub_433F10(0xFFu, 0x80u, 0x20u);
	v3 = sub_48C5E0(2, 3);
	sub_434080(v3);
	v4 = sub_4B0680(0, 0xFFu);
	v5 = sub_48C5E0(0, 40);
	v6 = sub_48C5E0(0, a1[7]);
	result = sub_4AF990(a2, a3 + v5, v5, v6);
	v8 = result;
	if (result) {
		sub_4AFB00((int)result, (int)v4);
		sub_4AFB10((int)v8, *a1);
		sub_4AFB90((int)v8, 50);
		LOWORD(v9) = sub_48C610();
		sub_4AFBD0((int)v8, v9);
		sub_4AFC50((int)v8, -32768);
		result = (char*)sub_4AFC60((int)v8, 45875, 1);
	}
	return result;
}
// 4AEF5A: variable 'v9' is possibly undefined

//----- (004AEF80) --------------------------------------------------------
int __cdecl sub_4AEF80(int* a1) {
	int* v1;    // edi
	int v2;     // ebp
	int v3;     // ecx
	int result; // eax
	char* v5;   // esi
	int v6;     // eax
	int v7;     // eax
	int v8;     // [esp+8h] [ebp-4h]
	int v9;     // [esp+10h] [ebp+4h]

	v1 = a1;
	v2 = *(_DWORD*)(*a1 + 12);
	v8 = *(_DWORD*)(*a1 + 16);
	sub_434430(255, 255, 255);
	v3 = a1[5];
	result = v3 - 1;
	if (v3) {
		v9 = a1[5];
		do {
			v5 = sub_4AF990(v2, v8, 0, 128);
			if (v5) {
				*((_DWORD*)v5 + 17) = sub_48C5E0(-256, 256);
				*((_DWORD*)v5 + 18) = 0;
				*((_DWORD*)v5 + 19) = 0;
				sub_4AFB10((int)v5, *v1);
				v6 = sub_48C5E0(0, 128);
				sub_4AFB90((int)v5, v6);
				sub_4AFB50((int)v5, 2);
				LOWORD(v7) = sub_48C610();
				sub_4AFBE0((int)v5, -16384 - (v7 >> 2));
				sub_4AFB60((int)v5, sub_4AF060);
			}
			result = --v9;
		} while (v9);
	}
	return result;
}
// 4AF01E: variable 'v7' is possibly undefined

//----- (004AF060) --------------------------------------------------------
int __cdecl sub_4AF060(int a1) {
	int result; // eax
	int v2;     // edi
	int v3;     // ecx
	int v4;     // ebx
	int v5;     // ebp
	int v6;     // ecx
	int v7;     // ecx
	int v8;     // edx
	int v9;     // edx
	int v10;    // ecx
	int v11;    // esi
	int v12;    // ecx

	result = a1;
	v2 = *(_DWORD*)(a1 + 48);
	if (v2 >= 0) {
		v3 = *(_DWORD*)(a1 + 44);
		++*(_DWORD*)(a1 + 40);
		if (v3) {
			*(_DWORD*)(a1 + 44) = v3 - 1;
		} else {
			v4 = *(_DWORD*)(a1 + 84);
			v5 = *(_DWORD*)(a1 + 96);
			v6 = *(_DWORD*)(a1 + 72);
			if ((int)*(_DWORD*)(a1 + 68) >= 0)
				v7 = v6 - 4;
			else
				v7 = v6 + 4;
			v8 = *(_DWORD*)(a1 + 68);
			*(_DWORD*)(a1 + 72) = v7;
			v9 = v7 + v8;
			*(_DWORD*)(a1 + 68) = v9;
			v10 = v9 * *(_DWORD*)(a1 + 76);
			v11 = *(_DWORD*)(a1 + 28);
			*(_DWORD*)(a1 + 76) += 256;
			v12 = (v11 << 16) + (v10 >> 2);
			*(_DWORD*)(a1 + 48) = v2 - 1;
			if (v2 - 1 >= 0) {
				*(_DWORD*)(a1 + 84) = v4 + v5;
				*(_DWORD*)(a1 + 80) = v12;
			} else {
				result = (*(int(__cdecl**)(int))(a1 + 132))(a1);
			}
		}
	}
	return result;
}

//----- (004AF0F0) --------------------------------------------------------
unsigned __int8* __cdecl sub_4AF0F0(unsigned __int8** a1) {
	unsigned __int8** v1;    // ebp
	unsigned __int8* result; // eax
	unsigned __int8** v3;    // ecx
	__int64 v4;              // rax
	int v5;                  // kr00_4
	unsigned __int8* v6;     // ecx
	int v7;                  // ebx
	int v8;                  // eax
	int v9;                  // eax
	char* v10;               // eax
	int v11;                 // esi
	char* v12;               // [esp-10h] [ebp-28h]
	int v13;                 // [esp-8h] [ebp-20h]
	unsigned __int8* v14;    // [esp+Ch] [ebp-Ch]
	int v15;                 // [esp+10h] [ebp-8h]
	int v16;                 // [esp+14h] [ebp-4h]

	v1 = a1;
	sub_4AF8C0(a1);
	result = v1[1];
	if (result) {
		sub_4AF890(v1);
		v3 = (unsigned __int8**)v1[4];
		v14 = v1[3];
		a1 = v3;
		sub_47D5C0((int)v1[1], &v14, &a1, &v15, &v16);
		v4 = v15;
		v5 = v4;
		result = (unsigned __int8*)(v4 - HIDWORD(v4));
		v6 = v1[5];
		v7 = (int)(v6 - 1);
		if (v6) {
			do {
				if (v7 & 1)
					nox_client_drawSetColor_434460(*(int*)&byte_5D4594[2523948]);
				else
					nox_client_drawSetColor_434460(*(int*)&byte_5D4594[2589772]);
				v13 = (int)v1[7];
				v8 = sub_48C5E0(-8, -2);
				v12 = (char*)a1 + v8;
				v9 = sub_48C5E0((int)&v14[v5 / 2], (int)&v14[v15]);
				v10 = sub_4AF990(v9, (int)v12, 0, v13);
				v11 = (int)v10;
				if (v10) {
					sub_4AFB50((int)v10, 2);
					sub_4AFB10(v11, (int)*v1);
					*(_DWORD*)(v11 + 68) = sub_48C5E0(v5 / -2, v5 / 2);
					*(_DWORD*)(v11 + 72) = 0;
					sub_4AFB60(v11, sub_4AF200);
				}
				result = (unsigned __int8*)v7--;
			} while (result);
		}
	}
	return result;
}

//----- (004AF200) --------------------------------------------------------
int __cdecl sub_4AF200(int a1) {
	int result; // eax
	int v2;     // esi
	int v3;     // ecx
	_DWORD* v4; // ecx
	int v5;     // edx
	int v6;     // ecx
	int v7;     // ecx
	int v8;     // edi
	int v9;     // edi
	int v10;    // edx

	result = a1;
	v2 = *(_DWORD*)(a1 + 48);
	if (v2 >= 0) {
		v3 = *(_DWORD*)(a1 + 44);
		++*(_DWORD*)(a1 + 40);
		if (v3) {
			*(_DWORD*)(a1 + 44) = v3 - 1;
		} else {
			if (*(_BYTE*)(a1 + 56) & 4) {
				v4 = *(_DWORD**)(a1 + 8);
				if (v4) {
					v5 = v4[4] - v4[9];
					*(_DWORD*)(a1 + 28) += v4[3] - v4[8];
					*(_DWORD*)(a1 + 32) += v5;
				}
			}
			v6 = *(_DWORD*)(a1 + 72);
			if ((int)*(_DWORD*)(a1 + 68) >= 0)
				v7 = v6 - 1;
			else
				v7 = v6 + 1;
			v8 = *(_DWORD*)(a1 + 68);
			*(_DWORD*)(a1 + 72) = v7;
			v9 = v7 + v8;
			*(_DWORD*)(a1 + 68) = v9;
			*(_DWORD*)(a1 + 48) = v2 - 1;
			if (v2 - 1 >= 0) {
				v10 = *(_DWORD*)(a1 + 32) << 16;
				*(_DWORD*)(a1 + 80) = (v9 + *(_DWORD*)(a1 + 28)) << 16;
				*(_DWORD*)(a1 + 84) = v10;
			} else {
				result = (*(int(__cdecl**)(int))(a1 + 132))(a1);
			}
		}
	}
	return result;
}

//----- (004AF2A0) --------------------------------------------------------
unsigned __int8* __cdecl sub_4AF2A0(unsigned __int8** a1) {
	unsigned __int8* result; // eax

	sub_4AF8C0(a1);
	result = a1[1];
	if (result) {
		sub_4AF890(a1);
		result = (unsigned __int8*)sub_4AF690(a1, sub_4AF2D0);
	}
	return result;
}

//----- (004AF2D0) --------------------------------------------------------
void __cdecl sub_4AF2D0(int* a1, int a2, int a3) {
	int v3;   // eax
	int* v4;  // ebx
	int v5;   // eax
	char* v7; // esi
	int v8;   // [esp+0h] [ebp-8h]
	int v9;   // [esp+4h] [ebp-4h]

	if (!*(_DWORD*)&byte_5D4594[1311132]) {
		*(_DWORD*)&byte_5D4594[1311124] = sub_4344A0(64, 200, 64);
		*(_DWORD*)&byte_5D4594[1311128] = sub_4344A0(64, 64, 255);
		*(_DWORD*)&byte_5D4594[1311132] = 1;
	}
	sub_434040(*(_DWORD*)&byte_5D4594[4 * a1[6] + 1311124]);
	v3 = sub_48C5E0(2, 5);
	sub_434080(v3);
	v4 = sub_4B0680(0, 0xFFu);
	v9 = a2;
	v8 = a3;
	sub_48C650(0, 256, 120, &v9, &v8);
	v5 = sub_48C5E0(1, a1[7]);
	v7 = sub_4AF990(v9, v8, 0, v5);
	if (v7) {
		sub_4AFE20(v7, *(CHAR**)&byte_5D4594[3798628]);
		sub_4AFB10((int)v7, *a1);
		sub_4AFB00((int)v7, (int)v4);
		sub_4AFC90(v7, a2, a3, 0);
	}
}

//----- (004AF3D0) --------------------------------------------------------
_DWORD* __cdecl sub_4AF3D0(_DWORD* a1) {
	sub_434430(255, 255, 255);
	return sub_4AF690(a1, sub_4AF400);
}

//----- (004AF400) --------------------------------------------------------
int __cdecl sub_4AF400(int a1, int a2, int a3) {
	int v3;   // eax
	char* v4; // esi
	int v5;   // eax
	int v6;   // eax

	v3 = sub_48C5E0(0, 100);
	v4 = sub_4AF990(a2, a3, 0, v3);
	sub_4AFB50((int)v4, 1);
	v5 = sub_48C5E0(0, 64);
	sub_4AFB90((int)v4, v5);
	LOWORD(v6) = sub_48C610();
	return sub_4AFBE0((int)v4, v6 - 6553);
}
// 4AF444: variable 'v6' is possibly undefined

//----- (004AF450) --------------------------------------------------------
char* __cdecl sub_4AF450(int* a1) {
	int* v1;      // edi
	char* result; // eax
	char* v3;     // esi

	sub_433F10(0x32u, 0x32u, 0x32u);
	sub_434080(10);
	v1 = sub_4B0680(0, 0xFFu);
	result = sub_4AF990(0, 0, 0, 0x7FFFFFFF);
	v3 = result;
	if (result) {
		sub_4AFB10((int)result, *a1);
		sub_4AFB00((int)v3, (int)v1);
		result = (char*)sub_4AFCF0(sub_4AF4C0, (int)v3, 1, a1[7]);
	}
	return result;
}

//----- (004AF4C0) --------------------------------------------------------
int __cdecl sub_4AF4C0(int a1) {
	int v1;   // eax
	int v2;   // esi
	int v3;   // edi
	int v4;   // eax
	char* v5; // eax
	int v6;   // esi
	int v7;   // eax
	int v8;   // eax
	int v9;   // eax
	int v11;  // [esp-Ch] [ebp-18h]

	v1 = *(_DWORD*)(*(_DWORD*)(a1 + 20) + 8);
	v2 = *(_DWORD*)(v1 + 12);
	v3 = *(_DWORD*)(v1 + 16);
	nox_client_drawSetColor_434460(*(int*)&byte_5D4594[2589772]);
	v11 = sub_48C5E0(v3 - 2, v3 + 2);
	v4 = sub_48C5E0(v2 - 2, v2 + 2);
	v5 = sub_4AF990(v4, v11, 2, 10);
	v6 = (int)v5;
	if (!v5)
		return 0;
	sub_4AFE20(v5, *(CHAR**)&byte_5D4594[3798628]);
	sub_4AFB00(v6, *(_DWORD*)(*(_DWORD*)(a1 + 20) + 4));
	sub_4AFB50(v6, 1);
	sub_4AFC50(v6, -32768);
	sub_4AFC60(v6, 45875, 1);
	LOWORD(v7) = sub_48C610();
	sub_4AFBD0(v6, v7);
	LOWORD(v8) = sub_48C610();
	sub_4AFBE0(v6, v8);
	LOWORD(v9) = sub_48C610();
	sub_4AFBF0(v6, v9);
	return 1;
}
// 4AF55B: variable 'v7' is possibly undefined
// 4AF56E: variable 'v8' is possibly undefined
// 4AF57E: variable 'v9' is possibly undefined

//----- (004AF5A0) --------------------------------------------------------
char* __cdecl sub_4AF5A0(int* a1) {
	char* result; // eax
	char* v2;     // esi

	result = sub_4AF990(0, 0, 0, 0x7FFFFFFF);
	v2 = result;
	if (result) {
		sub_4AFB40((int)result, a1[2]);
		sub_4AFB10((int)v2, *a1);
		sub_4AFB60((int)v2, 0);
		sub_4AFB70((int)v2, 0);
		result = (char*)sub_4AFCF0(sub_4AF600, (int)v2, 1, 500);
	}
	return result;
}

int __cdecl sub_4AF650(int* a1) {
	nox_client_drawEnableAlpha_434560(1);
	nox_client_drawSetAlpha_434580(255 * a1[12] / a1[13]);
	sub_4AFEB0(a1);
	return nox_client_drawEnableAlpha_434560(0);
}

//----- (004AF600) --------------------------------------------------------
int __cdecl sub_4AF600(int a1) {
	char* v1; // esi

	v1 = sub_4AF990(0, 0, 0, 5);
	if (!v1)
		return 0;
	sub_4AFB40((int)v1, *(_DWORD*)(*(_DWORD*)(a1 + 20) + 16));
	sub_4AFB10((int)v1, *(_DWORD*)(*(_DWORD*)(a1 + 20) + 12));
	sub_4AFB70((int)v1, sub_4AF650);
	return 1;
}

//----- (004AF690) --------------------------------------------------------
_DWORD* __cdecl sub_4AF690(_DWORD* a1, void(__cdecl* a2)(_DWORD*, _DWORD*, int)) {
	_DWORD* result;                             // eax
	int v3;                                     // edx
	int v4;                                     // ebx
	int* v5;                                    // edi
	int v6;                                     // ebp
	int v7;                                     // edi
	int v8;                                     // esi
	int v9;                                     // ebp
	_BYTE* v10;                                 // ecx
	int v11;                                    // ebx
	int v12;                                    // eax
	int v13;                                    // edx
	int v14;                                    // esi
	_BYTE* v15;                                 // ecx
	void(__cdecl * v16)(_DWORD*, _DWORD*, int); // ebx
	_DWORD* v17;                                // edi
	int v18;                                    // edx
	int v19;                                    // eax
	_DWORD* v20;                                // [esp+10h] [ebp-20h]
	int v21;                                    // [esp+10h] [ebp-20h]
	int v22;                                    // [esp+14h] [ebp-1Ch]
	int v23;                                    // [esp+18h] [ebp-18h]
	int v24;                                    // [esp+18h] [ebp-18h]
	int v25;                                    // [esp+18h] [ebp-18h]
	int v26;                                    // [esp+1Ch] [ebp-14h]
	int v27;                                    // [esp+20h] [ebp-10h]
	int v28;                                    // [esp+20h] [ebp-10h]
	_DWORD* v29;                                // [esp+24h] [ebp-Ch]
	int v30;                                    // [esp+28h] [ebp-8h]
	int v31;                                    // [esp+2Ch] [ebp-4h]
	_BYTE* v32;                                 // [esp+38h] [ebp+8h]

	result = (_DWORD*)(*(int(__cdecl**)(_DWORD)) & dword_5d4594_3799492)(a1[1]);
	if (result) {
		v3 = *result;
		v4 = result[1];
		v5 = result + 3;
		result = (_DWORD*)(result[2] + a1[3]);
		v22 = a1[5];
		v30 = v3;
		v6 = *v5;
		v7 = (int)v5 + 5;
		v8 = v6 + a1[4];
		v9 = 0;
		v27 = v4;
		v29 = result;
		v10 = (_BYTE*)v7;
		if (v4) {
			v23 = v4;
			do {
				v20 = result;
				v11 = v3;
				if (v3 > 0) {
					do {
						v12 = (unsigned __int8)v10[1];
						v13 = *v10 & 0xF;
						v10 += 2;
						switch (v13) {
						case 1:
							v20 = (_DWORD*)((char*)v20 + v12);
							break;
						case 2:
						case 5:
						case 6:
							v9 += v12;
							v10 += 2 * v12;
							break;
						case 4:
							v9 += v12;
							v10 += v12;
							break;
						default:
							break;
						}
						v11 -= v12;
					} while (v11 > 0);
					result = v29;
					v3 = v30;
				}
				--v23;
			} while (v23);
			v4 = v27;
		}
		v21 = v8;
		v14 = a1[5];
		v15 = (_BYTE*)v7;
		if (v4) {
			v31 = v4;
			v16 = a2;
			do {
				v17 = result;
				v28 = v3;
				if (v3 > 0) {
					do {
						v18 = (unsigned __int8)v15[1];
						v19 = *v15 & 0xF;
						v15 += 2;
						v26 = v18;
						v32 = v15;
						switch (v19) {
						case 1:
							v17 = (_DWORD*)((char*)v17 + v18);
							break;
						case 2:
						case 5:
						case 6:
							if (v18 > 0) {
								v25 = v18;
								do {
									v14 += v22;
									if (v14 >= v9) {
										v14 -= v9;
										if (v16) {
											v16(a1, v17, v21);
											v15 = v32;
											v18 = v26;
										}
									}
									v17 = (_DWORD*)((char*)v17 + 1);
									--v25;
								} while (v25);
							}
							v15 += 2 * v18;
							break;
						case 4:
							if (v18 > 0) {
								v24 = v18;
								do {
									v14 += v22;
									if (v14 >= v9) {
										v14 -= v9;
										if (v16) {
											v16(a1, v17, v21);
											v15 = v32;
											v18 = v26;
										}
									}
									v17 = (_DWORD*)((char*)v17 + 1);
									--v24;
								} while (v24);
							}
							v15 += v18;
							break;
						default:
							break;
						}
						v28 -= v18;
					} while (v28 > 0);
					result = v29;
					v3 = v30;
				}
				++v21;
				--v31;
			} while (v31);
		}
	}
	return result;
}

//----- (004AF890) --------------------------------------------------------
unsigned __int8* __cdecl sub_4AF890(unsigned __int8** a1) {
	unsigned __int8* result; // eax

	result = *a1;
	a1[3] = (unsigned __int8*)(*((_DWORD*)*a1 + 3) - **a1);
	a1[4] =
		(unsigned __int8*)(*((_DWORD*)result + 4) - *((__int16*)result + 53) - *((__int16*)result + 52) - result[1]);
	return result;
}

//----- (004AF8C0) --------------------------------------------------------
int __cdecl sub_4AF8C0(_DWORD* a1) {
	int result; // eax

	result = *(_DWORD*)(*a1 + 8);
	a1[1] = result;
	return result;
}

//----- (004AF8D0) --------------------------------------------------------
int sub_4AF8D0() {
	unsigned __int8* v1; // eax

	*(_DWORD*)&byte_5D4594[3798628] = &byte_587000[174348];
	dword_5d4594_1311148 = 512;
	dword_5d4594_1311140 = nox_calloc(0x200u, 0x88u);
	if (!dword_5d4594_1311140)
		return 0;
	dword_5d4594_1311144 = nox_calloc(0x200u, 1u);
	if (!dword_5d4594_1311144)
		return 0;
	v1 = &byte_5D4594[1311160];
	do {
		*((_DWORD*)v1 - 1) = 0;
		*(_DWORD*)v1 = 0;
		*((_DWORD*)v1 + 1) = 0;
		*((_DWORD*)v1 + 2) = 0;
		v1 += 24;
	} while ((int)v1 < (int)&byte_5D4594[1311928]);
	return 1;
}

//----- (004AF950) --------------------------------------------------------
void sub_4AF950() {
	if (dword_5d4594_1311140) {
		free(*(LPVOID*)&dword_5d4594_1311140);
		dword_5d4594_1311140 = 0;
	}
	if (dword_5d4594_1311144) {
		free(*(LPVOID*)&dword_5d4594_1311144);
		dword_5d4594_1311144 = 0;
	}
	dword_5d4594_1311148 = 0;
}

//----- (004AF990) --------------------------------------------------------
char* __cdecl sub_4AF990(int a1, int a2, int a3, int a4) {
	char* result; // eax

	result = sub_4B01B0();
	if (result) {
		*(_DWORD*)result = 0;
		*((_DWORD*)result + 1) = 0;
		*((_DWORD*)result + 4) = 0;
		*((_DWORD*)result + 3) = 0;
		*((_DWORD*)result + 5) = 0;
		*((_DWORD*)result + 6) = ptr_5D4594_3799572->data[61];
		*((_DWORD*)result + 7) = a1;
		*((_DWORD*)result + 8) = a2;
		*((_DWORD*)result + 9) = a3;
		*((_DWORD*)result + 22) = a3 << 16;
		*((_DWORD*)result + 21) = a2 << 16;
		*((_DWORD*)result + 12) = a4;
		*((_DWORD*)result + 13) = a4;
		*((_DWORD*)result + 10) = 0;
		*((_DWORD*)result + 11) = 0;
		*((_DWORD*)result + 14) = 0;
		*((_DWORD*)result + 20) = a1 << 16;
		*((_DWORD*)result + 23) = 0;
		*((_DWORD*)result + 24) = 0;
		*((_DWORD*)result + 25) = 0;
		*((_DWORD*)result + 26) = 0;
		*((_DWORD*)result + 27) = 0;
		*((_DWORD*)result + 28) = 0;
		*((_DWORD*)result + 29) = 0;
		*((_DWORD*)result + 30) = 0;
		*((_DWORD*)result + 16) = 0;
		*((_DWORD*)result + 32) = sub_4B0020;
		*((_DWORD*)result + 31) = sub_4AFEB0;
		*((_DWORD*)result + 33) = sub_4B01A0;
	}
	return result;
}

//----- (004AFA40) --------------------------------------------------------
void __cdecl sub_4AFA40(int a1) {
	int v1;     // eax
	_DWORD* v2; // eax

	if (a1) {
		v1 = *(_DWORD*)(a1 + 60);
		if (v1 >= 0 && v1 < *(int*)&dword_5d4594_1311148) {
			*(_BYTE*)(dword_5d4594_1311144 + v1) = 0;
			v2 = *(_DWORD**)(a1 + 20);
			if (v2)
				*v2 = 0;
		}
	}
}

//----- (004AFA70) --------------------------------------------------------
char* __cdecl sub_4AFA70(int a1) {
	char* result; // eax
	char* i;      // edi
	int v3;       // esi

	result = (char*)memchr(*(const void**)&dword_5d4594_1311144, 255, *(size_t*)&dword_5d4594_1311148);
	for (i = result; result; i = result) {
		v3 = (int)&i[-dword_5d4594_1311144];
		if (*(_DWORD*)(dword_5d4594_1311140 + 136 * (_DWORD)&i[-dword_5d4594_1311144] + 8) == a1)
			sub_4AFA40(dword_5d4594_1311140 + 136 * (_DWORD)&i[-dword_5d4594_1311144]);
		result = (char*)(dword_5d4594_1311148 - v3 - 1);
		if (dword_5d4594_1311148 - v3 == 1)
			break;
		result = (char*)memchr(i + 1, 255, dword_5d4594_1311148 - v3 - 1);
	}
	return result;
}

//----- (004AFAF0) --------------------------------------------------------
int __cdecl sub_4AFAF0(_DWORD* a1, int a2) {
	int result; // eax

	result = a2;
	*a1 = a2;
	return result;
}

//----- (004AFB00) --------------------------------------------------------
int __cdecl sub_4AFB00(int a1, int a2) {
	int result; // eax

	result = a2;
	*(_DWORD*)(a1 + 4) = a2;
	return result;
}

//----- (004AFB10) --------------------------------------------------------
int __cdecl sub_4AFB10(int a1, int a2) {
	int result;      // eax
	int v3;          // edx
	unsigned int v4; // edx

	result = a1;
	v3 = *(_DWORD*)(a1 + 56);
	if (a2) {
		v4 = v3 | 4;
		*(_DWORD*)(a1 + 8) = a2;
	} else {
		v4 = v3 & 0xFFFFFFFB;
		*(_DWORD*)(a1 + 8) = 0;
	}
	*(_DWORD*)(a1 + 56) = v4;
	return result;
}

//----- (004AFB40) --------------------------------------------------------
int __cdecl sub_4AFB40(int a1, int a2) {
	int result; // eax

	result = a2;
	*(_DWORD*)(a1 + 16) = a2;
	return result;
}

//----- (004AFB50) --------------------------------------------------------
int __cdecl sub_4AFB50(int a1, int a2) {
	int result; // eax

	result = a2;
	*(_DWORD*)(a1 + 64) = a2;
	return result;
}

//----- (004AFB60) --------------------------------------------------------
int __cdecl sub_4AFB60(int a1, int a2) {
	int result; // eax

	result = a2;
	*(_DWORD*)(a1 + 128) = a2;
	return result;
}

//----- (004AFB70) --------------------------------------------------------
int __cdecl sub_4AFB70(int a1, int a2) {
	int result; // eax

	result = a2;
	*(_DWORD*)(a1 + 124) = a2;
	return result;
}

//----- (004AFB80) --------------------------------------------------------
int __cdecl sub_4AFB80(int a1, int a2) {
	int result; // eax

	result = a2;
	*(_DWORD*)(a1 + 132) = a2;
	return result;
}

//----- (004AFB90) --------------------------------------------------------
int __cdecl sub_4AFB90(int a1, int a2) {
	int result; // eax

	result = a2;
	*(_DWORD*)(a1 + 44) = a2;
	return result;
}

//----- (004AFBA0) --------------------------------------------------------
int __cdecl sub_4AFBA0(int a1, int a2) {
	int result; // eax

	result = a2;
	*(_DWORD*)(a1 + 48) = a2;
	*(_DWORD*)(a1 + 52) = a2;
	return result;
}

//----- (004AFBB0) --------------------------------------------------------
_DWORD* __cdecl sub_4AFBB0(_DWORD* a1, int a2, int a3, int a4) {
	_DWORD* result; // eax

	result = a1;
	a1[23] = a2;
	a1[24] = a3;
	a1[25] = a4;
	return result;
}

//----- (004AFBD0) --------------------------------------------------------
int __cdecl sub_4AFBD0(int a1, int a2) {
	int result; // eax

	result = a2;
	*(_DWORD*)(a1 + 92) = a2;
	return result;
}

//----- (004AFBE0) --------------------------------------------------------
int __cdecl sub_4AFBE0(int a1, int a2) {
	int result; // eax

	result = a2;
	*(_DWORD*)(a1 + 96) = a2;
	return result;
}

//----- (004AFBF0) --------------------------------------------------------
int __cdecl sub_4AFBF0(int a1, int a2) {
	int result; // eax

	result = a2;
	*(_DWORD*)(a1 + 100) = a2;
	return result;
}

//----- (004AFC00) --------------------------------------------------------
_DWORD* __cdecl sub_4AFC00(_DWORD* a1, int a2, int a3, int a4) {
	_DWORD* result; // eax

	result = a1;
	a1[26] = a2;
	a1[27] = a3;
	a1[28] = a4;
	return result;
}

//----- (004AFC20) --------------------------------------------------------
int __cdecl sub_4AFC20(int a1, int a2) {
	int result; // eax

	result = a2;
	*(_DWORD*)(a1 + 104) = a2;
	return result;
}

//----- (004AFC30) --------------------------------------------------------
int __cdecl sub_4AFC30(int a1, int a2) {
	int result; // eax

	result = a2;
	*(_DWORD*)(a1 + 108) = a2;
	return result;
}

//----- (004AFC40) --------------------------------------------------------
int __cdecl sub_4AFC40(int a1, int a2) {
	int result; // eax

	result = a2;
	*(_DWORD*)(a1 + 112) = a2;
	return result;
}

//----- (004AFC50) --------------------------------------------------------
int __cdecl sub_4AFC50(int a1, int a2) {
	int result; // eax

	result = a2;
	*(_DWORD*)(a1 + 116) = a2;
	return result;
}

//----- (004AFC60) --------------------------------------------------------
int __cdecl sub_4AFC60(int a1, int a2, int a3) {
	int result; // eax
	int v4;     // ecx

	result = a1;
	v4 = *(_DWORD*)(a1 + 56);
	if (a3)
		*(_DWORD*)(a1 + 56) = v4 | 2;
	else
		*(_DWORD*)(a1 + 56) = v4 & 0xFFFFFFFD;
	*(_DWORD*)(a1 + 120) = a2;
	return result;
}

//----- (004AFC90) --------------------------------------------------------
void __cdecl sub_4AFC90(_DWORD* a1, int a2, int a3, int a4) {
	int v4; // ecx
	int v5; // edx

	v4 = a4;
	if (!a4)
		v4 = a1[13];
	if (v4) {
		v5 = a1[8];
		a1[23] = ((a2 - a1[7]) << 16) / v4;
		a1[24] = ((a3 - v5) << 16) / v4;
	}
}

//----- (004AFCD0) --------------------------------------------------------
_DWORD* __cdecl sub_4AFCD0(_DWORD* a1) {
	_DWORD* result; // eax
	int v2;         // edx
	int v3;         // ecx

	result = a1;
	v2 = a1[21];
	a1[7] = a1[20] >> 16;
	v3 = a1[22] >> 16;
	a1[8] = v2 >> 16;
	a1[9] = v3;
	return result;
}

//----- (004AFCF0) --------------------------------------------------------
int __cdecl sub_4AFCF0(int a1, int a2, int a3, int a4) {
	unsigned __int8* v4; // eax
	int v5;              // ecx

	v4 = &byte_5D4594[1311156];
	v5 = 0;
	while (*(_DWORD*)v4) {
		v4 += 24;
		if (++v5 >= 32)
			return 0;
	}
	*(_DWORD*)v4 = a1;
	*((_DWORD*)v4 + 5) = a2;
	*(_DWORD*)(a2 + 20) = v4;
	*((_DWORD*)v4 + 2) = a3;
	*((_DWORD*)v4 + 1) = a3;
	*((_DWORD*)v4 + 3) = 0;
	*((_DWORD*)v4 + 4) = a4;
	return 1;
}

//----- (004AFD40) --------------------------------------------------------
void sub_4AFD40() {
	char* i;                 // ebp
	int v1;                  // esi
	int v2;                  // edi
	void(__cdecl * v3)(int); // eax
	void(__cdecl * v4)(int); // eax
	unsigned __int8* v5;     // esi
	int v6;                  // ebx
	int(__cdecl * *v7)(int); // edi
	int v8;                  // eax
	int v9;                  // ecx
	int v10;                 // eax
	int v11;                 // edx

	for (i = (char*)memchr(*(const void**)&dword_5d4594_1311144, 255, *(size_t*)&dword_5d4594_1311148); i;
		 i = (char*)memchr(i + 1, 255, dword_5d4594_1311148 - v1 - 1)) {
		v1 = (int)&i[-dword_5d4594_1311144];
		v2 = dword_5d4594_1311140 + 136 * (_DWORD)&i[-dword_5d4594_1311144];
		if (!(*(_BYTE*)(v2 + 56) & 8)) {
			v3 = *(void(__cdecl**)(int))(v2 + 124);
			if (v3)
				v3(dword_5d4594_1311140 + 136 * (_DWORD)&i[-dword_5d4594_1311144]);
		}
		v4 = *(void(__cdecl**)(int))(v2 + 128);
		if (v4)
			v4(v2);
		if (dword_5d4594_1311148 - v1 == 1)
			break;
	}
	v5 = &byte_5D4594[1311168];
	v6 = 32;
	do {
		v7 = (int(__cdecl**)(int))(v5 - 12);
		if (*((_DWORD*)v5 - 3)) {
			v8 = *((_DWORD*)v5 - 2);
			if (v8) {
				if (v8 == 1) {
					v9 = *((_DWORD*)v5 + 1);
					v10 = *(_DWORD*)v5 + 1;
					*(_DWORD*)v5 = v10;
					if (v10 <= v9 && (*v7)((int)(v5 - 12))) {
						*((_DWORD*)v5 - 2) = *((_DWORD*)v5 - 1);
					} else {
						v11 = *((_DWORD*)v5 + 2);
						*v7 = 0;
						sub_4AFA40(v11);
					}
				}
			}
		}
		v5 += 24;
		--v6;
	} while (v6);
}

//----- (004AFE20) --------------------------------------------------------
int __cdecl sub_4AFE20(_DWORD* a1, CHAR* a2) {
	int v2;     // eax
	_DWORD* v3; // eax
	_DWORD* v4; // edi
	int result; // eax

	v2 = sub_44CFC0(a2);
	v3 = (_DWORD*)sub_45A360_drawable(v2, a1[20] >> 16, a1[21] >> 16);
	v4 = v3;
	if (v3) {
		a1[3] = v3;
		v3[108] = a1;
		sub_49B950(v3, a1[13]);
		sub_45A110_drawable(v4);
	}
	result = a1[14];
	LOBYTE(result) = result | 8;
	a1[14] = result;
	return result;
}

//----- (004AFEB0) --------------------------------------------------------
int __cdecl sub_4AFEB0(int* a1) {
	int* v1;    // esi
	int v2;     // ecx
	int v3;     // edx
	int v4;     // edi
	int v5;     // ebx
	int v6;     // eax
	int v7;     // eax
	int v8;     // ebp
	int result; // eax
	int v10;    // ebx
	int2 a1a;   // [esp+10h] [ebp-10h]
	int2 a2;    // [esp+18h] [ebp-8h]
	int v13;    // [esp+24h] [ebp+4h]

	v1 = a1;
	v2 = a1[22] >> 16;
	v3 = a1[21] >> 16;
	a1a.field_0 = a1[20] >> 16;
	a1a.field_4 = v3 - v2;
	sub_4739A0(&a1a, &a2);
	v4 = a2.field_0;
	v5 = a2.field_4;
	if (*a1)
		nox_client_drawImageAt_47D2C0(*a1, a2.field_0, a2.field_4);
	v6 = a1[1];
	if (v6)
		sub_4B0820(v6, v4, v5);
	v7 = a1[3];
	if (v7 && a1[4]) {
		v8 = *(_DWORD*)(v7 + 12);
		v13 = *(_DWORD*)(v7 + 16);
		*(_DWORD*)(v7 + 12) = a1a.field_0;
		*(_DWORD*)(v1[3] + 16) = a1a.field_4;
		(*(void(__cdecl**)(int, int))(v1[3] + 300))(v1[4], v1[3]);
		*(_DWORD*)(v1[3] + 12) = v8;
		*(_DWORD*)(v1[3] + 16) = v13;
	}
	result = v1[16];
	if (result) {
		nox_client_drawSetColor_434460(v1[6]);
		switch (v1[16]) {
		case 1:
			result = sub_49EFA0(v4, v5);
			break;
		case 2:
			sub_49EFA0(v4, v5);
			sub_49EFA0(v4 + 1, v5);
			v10 = v5 + 1;
			sub_49EFA0(v4, v10);
			result = sub_49EFA0(v4 + 1, v10);
			break;
		case 3:
			sub_49EFA0(v4 + 1, v5);
			sub_49EFA0(v4, v5 + 1);
			sub_49EFA0(v4 + 1, v5 + 1);
			sub_49EFA0(v4 + 2, v5 + 1);
			result = sub_49EFA0(v4 + 1, v5 + 2);
			break;
		default:
			result = sub_4B0BC0(v4, v5, v1[16] / 2);
			break;
		}
	}
	return result;
}

//----- (004B0020) --------------------------------------------------------
int __cdecl sub_4B0020(_DWORD* a1) {
	_DWORD* v1;     // esi
	int result;     // eax
	int v3;         // eax
	int v4;         // edx
	int v5;         // ecx
	_DWORD* v6;     // eax
	int v7;         // eax
	int v8;         // ebp
	int v9;         // ebx
	int v10;        // edi
	bool v11;       // sf
	int v12;        // edx
	int v13;        // eax
	int v14;        // edx
	int v15;        // eax
	int v16;        // eax
	int v17;        // eax
	int v18;        // edi
	int v19;        // eax
	int v20;        // [esp+10h] [ebp-Ch]
	int v21;        // [esp+10h] [ebp-Ch]
	int v22;        // [esp+14h] [ebp-8h]
	int nNumerator; // [esp+18h] [ebp-4h]
	int v24;        // [esp+20h] [ebp+4h]
	int v25;        // [esp+20h] [ebp+4h]

	v1 = a1;
	result = a1[12];
	if (result >= 0) {
		v3 = a1[20];
		v4 = a1[22];
		++a1[10];
		v20 = a1[21];
		v5 = a1[14];
		v24 = v3;
		if (v5 & 4) {
			v6 = (_DWORD*)v1[2];
			if (v6) {
				v24 += (v6[3] - v6[8]) << 16;
				v20 += (v6[4] - v6[9]) << 16;
			}
		}
		v7 = v1[11];
		if (v7) {
			result = v7 - 1;
			v1[11] = result;
		} else {
			v8 = v1[23];
			v9 = v1[24];
			v10 = v1[25];
			v25 = v8 + v24;
			v11 = v10 + v4 < 0;
			v12 = v10 + v4;
			v21 = v9 + v20;
			v22 = v12;
			if (v11) {
				if (v5 & 2) {
					v13 = v1[30];
					v14 = v12 - v10;
					v10 = -v10;
					v22 = v14;
					nNumerator = v13;
					if (v13) {
						v8 = MulDiv(v8, v13, 0x10000);
						v9 = MulDiv(v9, nNumerator, 0x10000);
						v10 = MulDiv(v10, nNumerator, 0x10000);
					}
				} else {
					v10 = 0;
					v22 = 0;
				}
			}
			v15 = v1[26];
			if (v15)
				v8 = MulDiv(v8, v15, 0x10000);
			v16 = v1[27];
			if (v16)
				v9 = MulDiv(v9, v16, 0x10000);
			v17 = v1[28];
			if (v17)
				v10 = MulDiv(v10, v17, 0x10000);
			v18 = v1[29] + v10;
			v19 = v1[12] - 1;
			v1[12] = v19;
			if (v19 >= 0) {
				result = v22;
				v1[25] = v18;
				v1[20] = v25;
				v1[21] = v21;
				v1[22] = v22;
				v1[23] = v8;
				v1[24] = v9;
			} else {
				result = ((int(__cdecl*)(_DWORD*))v1[33])(v1);
			}
		}
	}
	return result;
}

//----- (004B01A0) --------------------------------------------------------
void __cdecl sub_4B01A0(int a1) { sub_4AFA40(a1); }

//----- (004B01B0) --------------------------------------------------------
char* sub_4B01B0() {
	char* v0;     // eax
	char* result; // eax
	int v2;       // ecx

	v0 = (char*)memchr(*(const void**)&dword_5d4594_1311144, 0, *(size_t*)&dword_5d4594_1311148);
	if (!v0) {
		result = (char*)sub_4B0220(dword_5d4594_1311148 + 512);
		if (!result)
			return result;
		v0 = (char*)memchr(*(const void**)&dword_5d4594_1311144, 0, *(size_t*)&dword_5d4594_1311148);
	}
	v2 = (int)&v0[-dword_5d4594_1311144];
	*(_BYTE*)(dword_5d4594_1311144 + v2) = -1;
	result = (char*)(dword_5d4594_1311140 + 136 * v2);
	*((_DWORD*)result + 15) = v2;
	return result;
}

//----- (004B0220) --------------------------------------------------------
int __cdecl sub_4B0220(size_t a1) {
	unsigned int v1; // esi
	int result;      // eax

	v1 = a1 - dword_5d4594_1311148;
	result = realloc(*(LPVOID*)&dword_5d4594_1311140, 136 * a1);
	if (result) {
		dword_5d4594_1311140 = result;
		memset((void*)(result + 136 * dword_5d4594_1311148), 0, 136 * v1);
		result = realloc(*(LPVOID*)&dword_5d4594_1311144, a1);
		if (result) {
			dword_5d4594_1311144 = result;
			memset((void*)(dword_5d4594_1311148 + result), 0, v1);
			dword_5d4594_1311148 = a1;
			result = 1;
		}
	}
	return result;
}

//----- (004B02D0) --------------------------------------------------------
int sub_4B02D0() {
	dword_5d4594_1311936 = 0;
	dword_5d4594_1311924 = 0;
	*(_DWORD*)&byte_5D4594[1311928] = 0;
	*(_DWORD*)&byte_5D4594[1311932] = 0;
	return 1;
}

//----- (004B0610) --------------------------------------------------------
void __cdecl sub_4B0610(int a1) {
	if (dword_5d4594_1311936 && (!*(_DWORD*)&byte_5D4594[1311932] || a1 == 1)) {
		sub_555500(1);
	}
}

//----- (004B0650) --------------------------------------------------------
int sub_4B0650() {
	dword_5d4594_1312460 = 0;
	return 1;
}

//----- (004B0660) --------------------------------------------------------
void sub_4B0660() {
	void* result; // eax
	for (result = *(void**)&dword_5d4594_1312460; dword_5d4594_1312460; result = *(void**)&dword_5d4594_1312460)
		sub_4B07D0(result);
}

//----- (004B0680) --------------------------------------------------------
int* __cdecl sub_4B0680(unsigned __int8 a1, unsigned __int8 a2) {
	int* result;        // eax
	unsigned __int8 v3; // bl
	int v4;             // edi
	int* v5;            // esi
	size_t v6;          // eax
	int* v7;            // [esp+14h] [ebp+4h]

	result = *(int**)&dword_5d4594_1312460;
	v3 = a1;
	v4 = ptr_5D4594_3799572->data[262];
	if (dword_5d4594_1312460) {
		while (1) {
			v7 = result;
			if (*result == v4 && result[1] == v3 && result[2] == a2 && result[12] == ptr_5D4594_3799572->data[54] &&
				result[13] == ptr_5D4594_3799572->data[55] && result[14] == ptr_5D4594_3799572->data[56]) {
				break;
			}
			result = (int*)result[18];
			if (!result) {
				v5 = (int*)nox_calloc(1u, 0x50u);
				v7[18] = (int)v5;
				v5[17] = (int)v7;
				goto LABEL_11;
			}
		}
		++result[4];
	} else {
		dword_5d4594_1312460 = nox_calloc(1u, 0x50u);
		v5 = *(int**)&dword_5d4594_1312460;
		*(_DWORD*)(dword_5d4594_1312460 + 68) = 0;
	LABEL_11:
		*v5 = v4;
		v5[1] = v3;
		v5[2] = a2;
		v5[4] = 0;
		v6 = 2 * (22 * v4 * (v4 + 1) / 7 + 6 * v4) + 17;
		v5[3] = v6;
		v5[12] = ptr_5D4594_3799572->data[54];
		v5[13] = ptr_5D4594_3799572->data[55];
		v5[14] = ptr_5D4594_3799572->data[56];
		v5[16] = (int)nox_calloc(1u, v6);
		v5[18] = 0;
		sub_4B0870(v5);
		result = v5;
	}
	return result;
}

//----- (004B07D0) --------------------------------------------------------
int __cdecl sub_4B07D0(LPVOID lpMem) {
	int result; // eax
	int v2;     // eax
	int v3;     // eax

	result = *((_DWORD*)lpMem + 4) - 1;
	*((_DWORD*)lpMem + 4) = result;
	if (result < 0) {
		v2 = *((_DWORD*)lpMem + 17);
		if (v2)
			*(_DWORD*)(v2 + 72) = *((_DWORD*)lpMem + 18);
		v3 = *((_DWORD*)lpMem + 18);
		if (v3)
			*(_DWORD*)(v3 + 68) = *((_DWORD*)lpMem + 17);
		if (lpMem == *(LPVOID*)&dword_5d4594_1312460)
			dword_5d4594_1312460 = *((_DWORD*)lpMem + 18);
		free(*((LPVOID*)lpMem + 16));
		free(lpMem);
	}
	return result;
}

//----- (004B0820) --------------------------------------------------------
int(__cdecl* __cdecl sub_4B0820(int a1, int a2, int a3))(_DWORD) {
	int(__cdecl * v3)(_DWORD); // esi
	char v5[12];               // [esp+4h] [ebp-Ch]

	v5[10] = 8;
	*(_DWORD*)v5 = *(_DWORD*)(a1 + 64);
	v3 = sub_47D5B0(sub_4B0B20);
	nox_client_drawImageAt_47D2C0((int)v5, a2, a3);
	return sub_47D5B0((int)v3);
}

//----- (004B0870) --------------------------------------------------------
int __cdecl sub_4B0870(int* a1) {
	int v1;              // ebx
	_DWORD* v2;          // esi
	int v3;              // ebp
	int v4;              // eax
	int v5;              // edx
	_BYTE* v6;           // esi
	int v7;              // ebp
	int result;          // eax
	int v9;              // ecx
	_BYTE* v10;          // esi
	_BYTE* v11;          // esi
	int v12;             // edi
	int v13;             // ebp
	int v14;             // edx
	_BYTE* v15;          // esi
	int v16;             // eax
	bool v17;            // zf
	int v18;             // [esp+10h] [ebp-44h]
	int v19;             // [esp+14h] [ebp-40h]
	int v20;             // [esp+18h] [ebp-3Ch]
	int v21;             // [esp+20h] [ebp-34h]
	int v22;             // [esp+24h] [ebp-30h]
	int v23;             // [esp+28h] [ebp-2Ch]
	int v24;             // [esp+28h] [ebp-2Ch]
	unsigned __int8 v25; // [esp+2Ch] [ebp-28h]
	int v26;             // [esp+2Ch] [ebp-28h]
	int v27;             // [esp+30h] [ebp-24h]
	int v28;             // [esp+34h] [ebp-20h]
	unsigned __int8 v29; // [esp+38h] [ebp-1Ch]
	int v30;             // [esp+38h] [ebp-1Ch]
	int v31;             // [esp+3Ch] [ebp-18h]
	unsigned __int8 v32; // [esp+40h] [ebp-14h]
	int v33;             // [esp+40h] [ebp-14h]
	int v34;             // [esp+48h] [ebp-Ch]
	int v35;             // [esp+4Ch] [ebp-8h]
	int v36;             // [esp+50h] [ebp-4h]
	int v37;             // [esp+58h] [ebp+4h]

	v1 = *a1;
	v2 = (_DWORD*)a1[16];
	v3 = a1[1];
	v4 = a1[2];
	*v2 = 2 * *a1;
	++v2;
	*v2 = 2 * v1;
	++v2;
	*v2 = -*a1;
	++v2;
	*v2 = -*a1;
	v32 = (unsigned __int16)(v3 * a1[12]) >> 8;
	v5 = a1[13];
	v23 = a1[14];
	v29 = (unsigned __int16)(v3 * v5) >> 8;
	v25 = (unsigned __int16)(v3 * v23) >> 8;
	v6 = (char*)v2 + 5;
	v34 = v32 << 16;
	v18 = v32 << 16;
	v7 = -v1;
	v31 = -v1;
	v27 = (int)(((((unsigned int)(v4 * a1[12]) >> 8) & 0xFF) - v32) << 16) / v1;
	v35 = v29 << 16;
	v19 = v29 << 16;
	v28 = (int)(((((unsigned int)(v4 * v5) >> 8) & 0xFF) - v29) << 16) / v1;
	v36 = v25 << 16;
	v20 = v25 << 16;
	v30 = (int)(((((unsigned int)(v4 * v23) >> 8) & 0xFF) - v25) << 16) / v1;
	result = 2 * v1;
	if (2 * v1) {
		v33 = 2 * v1;
		do {
			v9 = (__int64)sqrt((double)(v1 * v1 - v7 * v7));
			if (v9 < v1) {
				*v6 = 1;
				v10 = v6 + 1;
				*v10 = v1 - v9;
				v6 = v10 + 1;
			}
			v26 = 2 * v9;
			if (2 * v9) {
				*v6 = 7;
				v11 = v6 + 1;
				v12 = v34;
				v13 = v35;
				*v11 = 2 * v9;
				v6 = v11 + 1;
				v37 = v36;
				v21 = v18 / v9;
				v22 = v19 / v9;
				v14 = -v9;
				v24 = v20 / v9;
				do {
					*(_WORD*)v6 = (v37 >> 19) & 0x1F | (8 * (BYTE2(v13) & 0xFC | (32 * (HIWORD(v12) & 0xFFF8))));
					if (v14 >= 0) {
						v12 -= v21;
						v13 -= v22;
						v37 -= v24;
					} else {
						v12 += v21;
						v13 += v22;
						v37 += v24;
					}
					++v14;
					v6 += 2;
					--v26;
				} while (v26);
				v7 = v31;
			}
			if (v9 < v1) {
				*v6 = 1;
				v15 = v6 + 1;
				*v15 = v1 - v9;
				v6 = v15 + 1;
			}
			if (v7 >= 0) {
				v19 -= v28;
				v18 -= v27;
				v16 = v20 - v30;
			} else {
				v19 += v28;
				v18 += v27;
				v16 = v30 + v20;
			}
			v20 = v16;
			++v7;
			result = v33 - 1;
			v17 = v33 == 1;
			v31 = v7;
			--v33;
		} while (!v17);
	}
	return result;
}

//----- (004B0B20) --------------------------------------------------------
int __cdecl sub_4B0B20(int a1) { return *(_DWORD*)a1; }

//----- (004B0B30) --------------------------------------------------------
int nox_video_assignCircleDrawFuncs_4B0B30() {
	if (dword_5d4594_3801780) {
		if (dword_5d4594_3801780 == 1) {
			*(_DWORD*)&byte_5D4594[1312468] = nox_video_drawCircle16Opaque_4B1380;
			*(_DWORD*)&byte_5D4594[1312464] = nox_video_drawCircle16Alpha_4B2480;
			return 1;
		}
	} else {
		*(_DWORD*)&byte_5D4594[1312468] = nox_video_drawCircle8Opaque_4B0D30;
		*(_DWORD*)&byte_5D4594[1312464] = nox_video_drawCircle8Alpha_4B1A60;
	}
	return 1;
}

//----- (004B0B90) --------------------------------------------------------
int __cdecl nox_video_drawCircle_4B0B90(int a1, int a2, int a3) {
	int result; // eax

	if (ptr_5D4594_3799572->data[13])
		result = (*(int(__cdecl**)(_DWORD, _DWORD, _DWORD)) & byte_5D4594[1312464])(a1, a2, a3);
	else
		result = (*(int(__cdecl**)(_DWORD, _DWORD, _DWORD)) & byte_5D4594[1312468])(a1, a2, a3);
	return result;
}

//----- (004B0BC0) --------------------------------------------------------
int __cdecl sub_4B0BC0(int a1, int a2, int a3) {
	int v3;                           // ebp
	int(__cdecl * v4)(int, int, int); // esi
	int v5;                           // edi
	int v6;                           // ebx
	int result;                       // eax
	int v8;                           // ebp
	int v9;                           // edi
	int v10;                          // [esp+10h] [ebp-10h]
	int v11;                          // [esp+14h] [ebp-Ch]
	int v12;                          // [esp+18h] [ebp-8h]
	int v13;                          // [esp+1Ch] [ebp-4h]
	int v14;                          // [esp+24h] [ebp+4h]
	int v15;                          // [esp+28h] [ebp+8h]
	int v16;                          // [esp+2Ch] [ebp+Ch]

	v3 = a3;
	v16 = 1 - a3;
	v4 = *(int(__cdecl**)(int, int, int)) & dword_5d4594_3798708;
	v10 = 5 - 2 * v3;
	v12 = 0;
	v13 = v3;
	v11 = 3;
	if (!ptr_5D4594_3799572->data[13])
		v4 = *(int(__cdecl**)(int, int, int)) & dword_5d4594_3798720;
	v5 = a2;
	v6 = a1;
	v4(a1, a2 + v3, a1);
	v14 = a1 + v3;
	v15 = v6 - v3;
	v4(v6 - v3, v5, v6 + v3);
	v4(v6 - v3, v5, v14);
	result = v4(v6, v5 - v3, v6);
	if (v3 > 0) {
		v8 = v6;
		v9 = v5 - v6;
		do {
			if (v16 >= 0) {
				v16 += v10;
				v10 += 4;
				--v13;
				--v14;
				++v15;
			} else {
				v16 += v11;
				v10 += 2;
			}
			++v6;
			++v12;
			--v8;
			v11 += 2;
			v4(v8, v9 + v14, v6);
			v4(v15, v9 + v6, v14);
			v4(v15, v9 + v8, v14);
			v4(v8, v9 + v15, v6);
			result = v13;
		} while (v13 > v12);
	}
	return result;
}

//----- (004B0D30) --------------------------------------------------------
char __cdecl nox_video_drawCircle8Opaque_4B0D30(int a1, int a2, int a3) {
	int v3;      // esi
	int v4;      // edi
	char result; // al
	int v6;      // ecx
	int v7;      // edx
	int v8;      // edi
	int v9;      // [esp+10h] [ebp-10h]
	int v10;     // [esp+14h] [ebp-Ch]
	int v11;     // [esp+18h] [ebp-8h]
	int v12;     // [esp+1Ch] [ebp-4h]
	int v13;     // [esp+24h] [ebp+4h]
	int v14;     // [esp+28h] [ebp+8h]
	int v15;     // [esp+2Ch] [ebp+Ch]

	v3 = a1;
	v4 = a3;
	if (ptr_5D4594_3799572->data[0] && sub_49F8E0(a1, a2, a3))
		return sub_4B0F50(a1, a2, a3);
	v6 = 0;
	v9 = 1 - a3;
	v15 = 5 - 2 * a3;
	result = *(_BYTE*)(&ptr_5D4594_3799572->data[61]);
	v13 = 4 * (v4 + a2);
	v7 = v4;
	v10 = 3;
	nox_pixbuffer_rows_3798784[v13/4][v3] = result;
	*(_BYTE*)(v3 + *(_DWORD*)(4 * a2 + (_DWORD)nox_pixbuffer_rows_3798784) + v4) = result;
	nox_pixbuffer_rows_3798784[a2][v4 + v3] = result;
	v12 = 4 * (a2 - v4);
	nox_pixbuffer_rows_3798784[v12/4][v3] = result;
	nox_pixbuffer_rows_3798784[v12/4][v3] = result;
	nox_pixbuffer_rows_3798784[a2][v3 - v4] = result;
	nox_pixbuffer_rows_3798784[a2][v3 - v4] = result;
	nox_pixbuffer_rows_3798784[v13/4][v3] = result;
	if (v4 > 0) {
		v8 = 4 * a2;
		v14 = 4 * a2;
		v11 = v12;
		do {
			if (v9 >= 0) {
				v9 += v15;
				--v7;
				v15 += 4;
				v13 -= 4;
				v11 += 4;
			} else {
				v9 += v10;
				v15 += 2;
			}
			v8 += 4;
			++v6;
			v10 += 2;
			v14 -= 4;
			nox_pixbuffer_rows_3798784[v13/4][v6 + v3] = result;
			nox_pixbuffer_rows_3798784[v8/4][v7 + v3] = result;
			nox_pixbuffer_rows_3798784[v14/4][v7 + v3] = result;
			nox_pixbuffer_rows_3798784[v11/4][v3 + v6] = result;
			nox_pixbuffer_rows_3798784[v11/4][v3 - v6] = result;
			nox_pixbuffer_rows_3798784[v14/4][v3 - v7] = result;
			nox_pixbuffer_rows_3798784[v8/4][v3 - v7] = result;
			nox_pixbuffer_rows_3798784[v13/4][v3 - v6] = result;
		} while (v7 > v6);
	}
	return result;
}

//----- (004B0F50) --------------------------------------------------------
int __cdecl sub_4B0F50(int a1, int a2, int a3) {
	int v3;     // esi
	char v4;    // bl
	int v5;     // edx
	int result; // eax
	int v7;     // edi
	int v8;     // ebp
	int v9;     // edi
	int v10;    // esi
	int v11;    // ebx
	int v12;    // ebp
	int v13;    // edx
	int v14;    // ecx
	int v15;    // [esp+10h] [ebp-30h]
	int v16;    // [esp+14h] [ebp-2Ch]
	int v17;    // [esp+18h] [ebp-28h]
	int v18;    // [esp+1Ch] [ebp-24h]
	int v19;    // [esp+20h] [ebp-20h]
	int v20;    // [esp+24h] [ebp-1Ch]
	int v21;    // [esp+24h] [ebp-1Ch]
	int v22;    // [esp+28h] [ebp-18h]
	int v23;    // [esp+2Ch] [ebp-14h]
	int v24;    // [esp+30h] [ebp-10h]
	int v25;    // [esp+30h] [ebp-10h]
	int v26;    // [esp+34h] [ebp-Ch]
	int v27;    // [esp+38h] [ebp-8h]
	int v28;    // [esp+3Ch] [ebp-4h]
	int v29;    // [esp+44h] [ebp+4h]
	int v30;    // [esp+48h] [ebp+8h]
	char v31;   // [esp+4Ch] [ebp+Ch]

	v3 = a3;
	v28 = 0;
	v20 = 1 - a3;
	v19 = 5 - 2 * a3;
	v27 = a3;
	v26 = 3;
	v4 = *(_BYTE*)(&ptr_5D4594_3799572->data[61]);
	v17 = ptr_5D4594_3799572->data[1];
	v5 = a2;
	v15 = ptr_5D4594_3799572->data[4];
	v31 = *(_BYTE*)(&ptr_5D4594_3799572->data[61]);
	result = a2 + v27;
	v16 = ptr_5D4594_3799572->data[3];
	v18 = ptr_5D4594_3799572->data[2];
	v24 = a2 + v27;
	if (a1 >= v17 && a1 < ptr_5D4594_3799572->data[3] && result >= ptr_5D4594_3799572->data[2] && result < v15) {
		nox_pixbuffer_rows_3798784[result][a1] = v4;
	}
	v7 = a1 + v3;
	v30 = a1 + v3;
	if (a1 + v3 >= v17) {
		if (v7 < v16 && v5 >= v18 && v5 < v15) {
			nox_pixbuffer_rows_3798784[v5][v30] = v4;
			v7 = a1 + v3;
		}
		if (v7 >= v17 && v7 < v16 && v5 >= v18 && v5 < v15)
			nox_pixbuffer_rows_3798784[v5][v30] = v4;
	}
	v8 = v5 - v3;
	if (a1 >= v17) {
		if (a1 < v16 && v8 >= v18 && v8 < v15)
			nox_pixbuffer_rows_3798784[v8][a1] = v4;
		if (a1 >= v17 && a1 < v16 && v8 >= v18 && v8 < v15)
			nox_pixbuffer_rows_3798784[v8][a1] = v4;
	}
	v9 = a1 - v3;
	if (a1 - v3 >= v17) {
		if (v9 < v16 && v5 >= v18 && v5 < v15) {
			nox_pixbuffer_rows_3798784[v5][v9] = v31;
			result = v24;
		}
		if (v9 >= v17 && v9 < v16 && v5 >= v18 && v5 < v15) {
			nox_pixbuffer_rows_3798784[v5][v9] = v31;
			result = v24;
		}
	}
	if (a1 >= v17 && a1 < v16 && result >= v18 && result < v15) {
		nox_pixbuffer_rows_3798784[result][a1] = v31;
		result = v24;
	}
	if (v3 > 0) {
		v10 = a1;
		v23 = 4 * v5;
		v22 = 4 * v5;
		v25 = 4 * result;
		v11 = 4 * v8;
		v12 = v18;
		result = a1;
		v13 = v5 - a1;
		v14 = v20;
		v29 = v11;
		while (1) {
			if (v14 >= 0) {
				v21 = v19 + v14;
				v19 += 4;
				--v27;
				--v30;
				++v9;
				v29 += 4;
				v25 -= 4;
			} else {
				v21 = v26 + v14;
				v19 += 2;
			}
			v26 += 2;
			++v10;
			++v28;
			v23 += 4;
			--result;
			v22 -= 4;
			if (v10 >= v17 && v10 < v16 && v13 + v30 >= v12 && v13 + v30 < v15)
				nox_pixbuffer_rows_3798784[v25/4][v10] = v31;
			if (v30 >= v17) {
				if (v30 < v16 && v13 + v10 >= v12 && v13 + v10 < v15) {
					nox_pixbuffer_rows_3798784[v23/4][v30] = v31;
					v12 = v18;
				}
				if (v30 < v16 && v13 + result >= v12 && v13 + result < v15) {
					nox_pixbuffer_rows_3798784[v22/4][v30] = v31;
					v12 = v18;
				}
			}
			if (v10 >= v17 && v10 < v16 && v13 + v9 >= v12 && v13 + v9 < v15)
				nox_pixbuffer_rows_3798784[v29/4][v10] = v31;
			if (result >= v17 && result < v16 && v13 + v9 >= v12 && v13 + v9 < v15)
				nox_pixbuffer_rows_3798784[v29/4][result] = v31;
			if (v9 >= v17 && v9 < v16) {
				if (v13 + result >= v12 && v13 + result < v15)
					nox_pixbuffer_rows_3798784[v22/4][v9] = v31;
				if (v9 < v16 && v13 + v10 >= v12 && v13 + v10 < v15)
					nox_pixbuffer_rows_3798784[v23/4][v9] = v31;
			}
			if (result >= v17 && result < v16 && v13 + v30 >= v12 && v13 + v30 < v15)
				nox_pixbuffer_rows_3798784[v25/4][result] = v31;
			if (v27 <= v28)
				break;
			v14 = v21;
		}
	}
	return result;
}

//----- (004B1380) --------------------------------------------------------
__int16 __cdecl nox_video_drawCircle16Opaque_4B1380(int a1, int a2, int a3) {
	int v3;         // ebx
	int v4;         // esi
	__int16 result; // ax
	int v6;         // ecx
	int v7;         // edi
	int v8;         // ecx
	int v9;         // ecx
	int v10;        // edx
	int v11;        // ebx
	int v12;        // esi
	int v13;        // edi
	int v14;        // ebp
	int v15;        // [esp+10h] [ebp-18h]
	int v16;        // [esp+14h] [ebp-14h]
	int v17;        // [esp+18h] [ebp-10h]
	int v18;        // [esp+1Ch] [ebp-Ch]
	int v19;        // [esp+1Ch] [ebp-Ch]
	int v20;        // [esp+20h] [ebp-8h]
	int v21;        // [esp+24h] [ebp-4h]
	int v22;        // [esp+2Ch] [ebp+4h]
	int v23;        // [esp+30h] [ebp+8h]
	int v24;        // [esp+30h] [ebp+8h]
	int v25;        // [esp+34h] [ebp+Ch]

	v3 = a2;
	v4 = a3;
	if (ptr_5D4594_3799572->data[0] && sub_49F8E0(a1, a2, a3))
		return sub_4B15E0(a1, a2, a3);
	v15 = 1 - a3;
	v25 = 5 - 2 * a3;
	result = *(_WORD*)(&ptr_5D4594_3799572->data[61]);
	v6 = 2 * a1;
	v7 = 4 * (a2 + v4);
	v18 = v6;
	v20 = 0;
	v21 = v4;
	v16 = 3;
	*(_WORD*)((_DWORD)nox_pixbuffer_rows_3798784[v7/4] + v6) = result;
	v23 = 4 * a2;
	v8 = 2 * (v4 + a1);
	v17 = v8;
	*(_WORD*)(*(_DWORD*)(4 * v3 + (_DWORD)nox_pixbuffer_rows_3798784) + v8) = result;
	*(_WORD*)((_DWORD)nox_pixbuffer_rows_3798784[v3] + v8) = result;
	v9 = 4 * (v3 - v4);
	*(_WORD*)((_DWORD)nox_pixbuffer_rows_3798784[v9/4] + v18) = result;
	*(_WORD*)((_DWORD)nox_pixbuffer_rows_3798784[v9/4] + 2 * a1) = result;
	v10 = 2 * (a1 - v4);
	*(_WORD*)((_DWORD)nox_pixbuffer_rows_3798784[v3] + v10) = result;
	*(_WORD*)((_DWORD)nox_pixbuffer_rows_3798784[v3] + v10) = result;
	*(_WORD*)((_DWORD)nox_pixbuffer_rows_3798784[v7/4] + 2 * a1) = result;
	if (v4 > 0) {
		v11 = 4 * v3;
		v12 = v18;
		v22 = v7;
		v13 = v18;
		v19 = v10;
		v14 = v23;
		v24 = v9;
		do {
			if (v15 >= 0) {
				v15 += v25;
				v22 -= 4;
				v24 += 4;
				v25 += 4;
				--v21;
				v17 -= 2;
				v19 += 2;
			} else {
				v15 += v16;
				v25 += 2;
			}
			v12 += 2;
			v13 -= 2;
			v16 += 2;
			v11 += 4;
			v14 -= 4;
			++v20;
			*(_WORD*)((_DWORD)nox_pixbuffer_rows_3798784[v22/4] + v12) = result;
			*(_WORD*)((_DWORD)nox_pixbuffer_rows_3798784[v11/4] + v17) = result;
			*(_WORD*)((_DWORD)nox_pixbuffer_rows_3798784[v14/4] + v17) = result;
			*(_WORD*)((_DWORD)nox_pixbuffer_rows_3798784[v24/4] + v12) = result;
			*(_WORD*)((_DWORD)nox_pixbuffer_rows_3798784[v24/4] + v13) = result;
			*(_WORD*)((_DWORD)nox_pixbuffer_rows_3798784[v14/4] + v19) = result;
			*(_WORD*)((_DWORD)nox_pixbuffer_rows_3798784[v11/4] + v19) = result;
			*(_WORD*)((_DWORD)nox_pixbuffer_rows_3798784[v22/4] + v13) = result;
		} while (v21 > v20);
	}
	return result;
}

//----- (004B15E0) --------------------------------------------------------
int __cdecl sub_4B15E0(int a1, int a2, int a3) {
	int v3;      // esi
	__int16 v4;  // bp
	int v5;      // edi
	int v6;      // ecx
	int result;  // eax
	int v8;      // ebx
	int v9;      // edx
	int v10;     // edi
	int v11;     // edx
	int v12;     // ebp
	int v13;     // edi
	int v14;     // edx
	int v15;     // esi
	int v16;     // ecx
	int v17;     // edx
	int v18;     // [esp+10h] [ebp-44h]
	int v19;     // [esp+14h] [ebp-40h]
	int v20;     // [esp+18h] [ebp-3Ch]
	int v21;     // [esp+1Ch] [ebp-38h]
	int v22;     // [esp+20h] [ebp-34h]
	int v23;     // [esp+24h] [ebp-30h]
	__int16 v24; // [esp+28h] [ebp-2Ch]
	int v25;     // [esp+2Ch] [ebp-28h]
	int v26;     // [esp+30h] [ebp-24h]
	int v27;     // [esp+34h] [ebp-20h]
	int v28;     // [esp+38h] [ebp-1Ch]
	int v29;     // [esp+3Ch] [ebp-18h]
	int v30;     // [esp+40h] [ebp-14h]
	int v31;     // [esp+44h] [ebp-10h]
	int v32;     // [esp+48h] [ebp-Ch]
	int v33;     // [esp+4Ch] [ebp-8h]
	int v34;     // [esp+4Ch] [ebp-8h]
	int v35;     // [esp+58h] [ebp+4h]
	int v36;     // [esp+5Ch] [ebp+8h]
	int v37;     // [esp+5Ch] [ebp+8h]
	int v38;     // [esp+60h] [ebp+Ch]

	v3 = a3;
	v32 = 0;
	v21 = 1 - a3;
	v31 = a3;
	v22 = 5 - 2 * a3;
	v30 = 3;
	v4 = *(_WORD*)(&ptr_5D4594_3799572->data[61]);
	v5 = ptr_5D4594_3799572->data[1];
	v38 = ptr_5D4594_3799572->data[2];
	v6 = a2;
	v18 = ptr_5D4594_3799572->data[4];
	result = a1;
	v24 = *(_WORD*)(&ptr_5D4594_3799572->data[61]);
	v8 = a2 + v31;
	v20 = ptr_5D4594_3799572->data[1];
	v19 = ptr_5D4594_3799572->data[3];
	v36 = a2 + v31;
	if (a1 >= v5 && a1 < ptr_5D4594_3799572->data[3] && v8 >= v38 && v8 < v18)
		*(_WORD*)((_DWORD)nox_pixbuffer_rows_3798784[v8] + 2 * a1) = v4;
	v9 = a1 + v3;
	v33 = a1 + v3;
	if (a1 + v3 >= v5) {
		if (v9 < v19 && v6 >= v38 && v6 < v18)
			*(_WORD*)((_DWORD)nox_pixbuffer_rows_3798784[v6] + 2 * v9) = v4;
		if (v9 >= v20 && v9 < v19 && v6 >= v38 && v6 < v18)
			*(_WORD*)((_DWORD)nox_pixbuffer_rows_3798784[v6] + 2 * v9) = v4;
	}
	v10 = v6 - v3;
	if (a1 >= v20) {
		if (a1 < v19 && v10 >= v38 && v10 < v18)
			*(_WORD*)((_DWORD)nox_pixbuffer_rows_3798784[v10] + 2 * a1) = v4;
		if (a1 >= v20 && a1 < v19 && v10 >= v38 && v10 < v18)
			*(_WORD*)((_DWORD)nox_pixbuffer_rows_3798784[v10] + 2 * a1) = v4;
	}
	v11 = a1 - v3;
	if (a1 - v3 >= v20) {
		if (v11 < v19 && v6 >= v38 && v6 < v18) {
			*(_WORD*)((_DWORD)nox_pixbuffer_rows_3798784[v6] + 2 * v11) = v4;
			v8 = v36;
		}
		if (v11 >= v20 && v11 < v19 && v6 >= v38 && v6 < v18) {
			*(_WORD*)((_DWORD)nox_pixbuffer_rows_3798784[v6] + 2 * v11) = v4;
			v8 = v36;
		}
	}
	if (a1 >= v20 && a1 < v19 && v8 >= v38 && v8 < v18) {
		*(_WORD*)((_DWORD)nox_pixbuffer_rows_3798784[v8] + 2 * a1) = v4;
		v8 = v36;
	}
	if (v3 > 0) {
		v35 = a1 - v3;
		v28 = 2 * v11;
		v27 = 4 * v6;
		v23 = v8;
		v25 = 4 * v10;
		v37 = 2 * result;
		v12 = result - v3;
		v26 = v6 - result;
		v13 = 2 * v33;
		v29 = 2 * result;
		v34 = result - v6;
		v14 = v8;
		v15 = v6;
		do {
			if (v21 >= 0) {
				v13 -= 2;
				v21 += v22;
				v22 += 4;
				--v31;
				v25 += 4;
				--v14;
				v28 += 2;
				v35 = v12 + 1;
				v23 = v14;
			} else {
				v21 += v30;
				v22 += 2;
			}
			v30 += 2;
			++v32;
			++v15;
			v37 += 2;
			v27 -= 4;
			v29 -= 2;
			v16 = v15 + v34;
			--result;
			if (v15 + v34 >= v20 && v16 < v19 && v14 >= v38 && v14 < v18) {
				*(_WORD*)((_DWORD)nox_pixbuffer_rows_3798784[v14] + v37) = v24;
				v14 = v23;
			}
			v17 = v34 + v14;
			if (v17 >= v20) {
				if (v17 < v19 && v15 >= v38 && v15 < v18)
					*(_WORD*)(v13 + (_DWORD)nox_pixbuffer_rows_3798784[v15]) = v24;
				if (v17 >= v20 && v17 < v19 && result + v26 >= v38 && result + v26 < v18)
					*(_WORD*)((_DWORD)nox_pixbuffer_rows_3798784[v27/4] + v13) = v24;
			}
			if (v16 < v20 || v16 >= v19) {
				v12 = v35;
			} else {
				v12 = v35;
				if (v35 + v26 >= v38 && v35 + v26 < v18)
					*(_WORD*)((_DWORD)nox_pixbuffer_rows_3798784[v25/4] + v37) = v24;
			}
			if (result >= v20 && result < v19 && v26 + v12 >= v38 && v26 + v12 < v18)
				*(_WORD*)((_DWORD)nox_pixbuffer_rows_3798784[v25/4] + v29) = v24;
			if (v12 >= v20 && v12 < v19) {
				if (result + v26 >= v38 && result + v26 < v18)
					*(_WORD*)((_DWORD)nox_pixbuffer_rows_3798784[v27/4] + v28) = v24;
				if (v12 < v19 && v15 >= v38 && v15 < v18)
					*(_WORD*)((_DWORD)nox_pixbuffer_rows_3798784[v15] + v28) = v24;
			}
			if (result < v20 || result >= v19) {
				v14 = v23;
			} else {
				v14 = v23;
				if (v23 >= v38 && v23 < v18) {
					*(_WORD*)((_DWORD)nox_pixbuffer_rows_3798784[v23] + v29) = v24;
					v12 = v35;
				}
			}
		} while (v31 > v32);
	}
	return result;
}

//----- (004B1A60) --------------------------------------------------------
int __cdecl nox_video_drawCircle8Alpha_4B1A60(int a1, int a2, int a3) {
	int result; // eax
	int v4;     // edi
	int v5;     // esi
	int v6;     // ecx
	int v7;     // ebp
	int v8;     // eax
	_BYTE* v9;  // edx
	_BYTE* v10; // edx
	_BYTE* v11; // edx
	_BYTE* v12; // edx
	int v13;    // [esp+10h] [ebp-14h]
	int v14;    // [esp+14h] [ebp-10h]
	int v15;    // [esp+18h] [ebp-Ch]
	int v16;    // [esp+1Ch] [ebp-8h]
	int v17;    // [esp+20h] [ebp-4h]
	int v18;    // [esp+28h] [ebp+4h]
	int v19;    // [esp+2Ch] [ebp+8h]
	int v20;    // [esp+30h] [ebp+Ch]

	result = dword_5d4594_810632;
	if (dword_5d4594_810632) {
		v4 = a3;
		v5 = a1;
		if (ptr_5D4594_3799572->data[0] && sub_49F8E0(a1, a2, a3)) {
			result = sub_4B1E30(a1, a2, a3);
		} else {
			v6 = 0;
			v18 = 1 - a3;
			v7 = a3;
			v13 = 5 - 2 * a3;
			v16 = 3;
			v8 = 4 * (a2 + a3);
			v15 = v8;
			v9 = (_BYTE*)(v5 + (_DWORD)nox_pixbuffer_rows_3798784[v8/4]);
			result = *(unsigned __int8*)(&ptr_5D4594_3799572->data[61]);
			*v9 = *(_BYTE*)(result + ((unsigned __int8)*v9 << 8) + dword_5d4594_810632);
			v14 = 4 * a2;
			v10 = (_BYTE*)(a3 + v5 + *(_DWORD*)(4 * a2 + (_DWORD)nox_pixbuffer_rows_3798784));
			*v10 = *(_BYTE*)(result + ((unsigned __int8)*v10 << 8) + dword_5d4594_810632);
			v11 = (_BYTE*)(a3 + v5 + (_DWORD)nox_pixbuffer_rows_3798784[a2]);
			*v11 = *(_BYTE*)(result + ((unsigned __int8)*v11 << 8) + dword_5d4594_810632);
			v17 = 4 * (a2 - a3);
			nox_pixbuffer_rows_3798784[v17/4][v5] =
				*(_BYTE*)(result + (*(unsigned __int8*)((_DWORD)nox_pixbuffer_rows_3798784[v17/4] + v5) << 8) +
						  dword_5d4594_810632);
			nox_pixbuffer_rows_3798784[v17/4][v5] =
				*(_BYTE*)(result + (*(unsigned __int8*)(v5 + (_DWORD)nox_pixbuffer_rows_3798784[v17/4]) << 8) +
						  dword_5d4594_810632);
			v12 = (_BYTE*)(v5 + (_DWORD)nox_pixbuffer_rows_3798784[a2] - a3);
			*v12 = *(_BYTE*)(result + ((unsigned __int8)*v12 << 8) + dword_5d4594_810632);
			*(_BYTE*)(v5 + *(_DWORD*)(4 * a2 + (_DWORD)nox_pixbuffer_rows_3798784) - a3) =
				*(_BYTE*)(result + (*(unsigned __int8*)(v5 + *(_DWORD*)(4 * a2 + (_DWORD)nox_pixbuffer_rows_3798784) - a3) << 8) +
						  dword_5d4594_810632);
			nox_pixbuffer_rows_3798784[v15/4][v5] =
				*(_BYTE*)(result + (*(unsigned __int8*)((_DWORD)nox_pixbuffer_rows_3798784[v15/4] + v5) << 8) +
						  dword_5d4594_810632);
			if (a3 > 0) {
				v20 = 4 * a2;
				v19 = 4 * (a2 - v4);
				do {
					if (v18 >= 0) {
						v18 += v13;
						v13 += 4;
						--v7;
						v15 -= 4;
						v19 += 4;
					} else {
						v18 += v16;
						v13 += 2;
					}
					v16 += 2;
					v20 -= 4;
					++v6;
					v14 += 4;
					nox_pixbuffer_rows_3798784[v15/4][v5 + v6] = *(
						_BYTE*)(result + (*(unsigned __int8*)(v5 + v6 + (_DWORD)nox_pixbuffer_rows_3798784[v15/4]) << 8) +
								dword_5d4594_810632);
					nox_pixbuffer_rows_3798784[v14/4][v5 + v7] = *(
						_BYTE*)(result + (*(unsigned __int8*)(v5 + v7 + (_DWORD)nox_pixbuffer_rows_3798784[v14/4]) << 8) +
								dword_5d4594_810632);
					nox_pixbuffer_rows_3798784[v20/4][v5 + v7] = *(
						_BYTE*)(result + (*(unsigned __int8*)(v5 + v7 + (_DWORD)nox_pixbuffer_rows_3798784[v20/4]) << 8) +
								dword_5d4594_810632);
					nox_pixbuffer_rows_3798784[v19/4][v5 + v6] = *(
						_BYTE*)(result + (*(unsigned __int8*)(v5 + v6 + (_DWORD)nox_pixbuffer_rows_3798784[v19/4]) << 8) +
								dword_5d4594_810632);
					*(_BYTE*)(v5 + (_DWORD)nox_pixbuffer_rows_3798784[v19/4] - v6) = *(
						_BYTE*)(result + (*(unsigned __int8*)(v5 + (_DWORD)nox_pixbuffer_rows_3798784[v19/4] - v6) << 8) +
								dword_5d4594_810632);
					*(_BYTE*)(v5 + (_DWORD)nox_pixbuffer_rows_3798784[v20/4] - v7) = *(
						_BYTE*)(result + (*(unsigned __int8*)(v5 + (_DWORD)nox_pixbuffer_rows_3798784[v20/4] - v7) << 8) +
								dword_5d4594_810632);
					*(_BYTE*)(v5 + (_DWORD)nox_pixbuffer_rows_3798784[v14/4] - v7) = *(
						_BYTE*)(result + (*(unsigned __int8*)(v5 + (_DWORD)nox_pixbuffer_rows_3798784[v14/4] - v7) << 8) +
								dword_5d4594_810632);
					*(_BYTE*)(v5 + (_DWORD)nox_pixbuffer_rows_3798784[v15/4] - v6) = *(
						_BYTE*)(result + (*(unsigned __int8*)(v5 + (_DWORD)nox_pixbuffer_rows_3798784[v15/4] - v6) << 8) +
								dword_5d4594_810632);
				} while (v7 > v6);
			}
		}
	}
	return result;
}

//----- (004B1E30) --------------------------------------------------------
int __cdecl sub_4B1E30(int a1, int a2, int a3) {
	int result;          // eax
	int v4;              // edi
	int v5;              // ebp
	int v6;              // edx
	bool v7;             // cc
	unsigned __int8 v8;  // dl
	int v9;              // esi
	int v10;             // ebx
	int v11;             // ebx
	int v12;             // esi
	int v13;             // esi
	int v14;             // ebp
	int v15;             // edi
	int v16;             // ecx
	int v17;             // esi
	int v18;             // [esp+10h] [ebp-3Ch]
	int v19;             // [esp+14h] [ebp-38h]
	int v20;             // [esp+18h] [ebp-34h]
	int v21;             // [esp+1Ch] [ebp-30h]
	int v22;             // [esp+20h] [ebp-2Ch]
	unsigned __int8 v23; // [esp+24h] [ebp-28h]
	int v24;             // [esp+24h] [ebp-28h]
	int v25;             // [esp+28h] [ebp-24h]
	int v26;             // [esp+2Ch] [ebp-20h]
	int v27;             // [esp+30h] [ebp-1Ch]
	int v28;             // [esp+34h] [ebp-18h]
	int v29;             // [esp+38h] [ebp-14h]
	int v30;             // [esp+3Ch] [ebp-10h]
	int v31;             // [esp+3Ch] [ebp-10h]
	int v32;             // [esp+40h] [ebp-Ch]
	int v33;             // [esp+44h] [ebp-8h]
	int v34;             // [esp+48h] [ebp-4h]
	int i;               // [esp+50h] [ebp+4h]
	int v36;             // [esp+58h] [ebp+Ch]

	result = dword_5d4594_810632;
	if (dword_5d4594_810632) {
		v4 = a3;
		v32 = 0;
		v22 = 1 - a3;
		v25 = 5 - 2 * a3;
		v33 = a3;
		v29 = 3;
		v5 = ptr_5D4594_3799572->data[3];
		v23 = *(_BYTE*)(&ptr_5D4594_3799572->data[61]);
		v6 = ptr_5D4594_3799572->data[1];
		v18 = ptr_5D4594_3799572->data[4];
		result = a2;
		v21 = v6;
		v7 = a1 < v6;
		v8 = *(_BYTE*)(&ptr_5D4594_3799572->data[61]);
		v9 = a2 + a3;
		v19 = ptr_5D4594_3799572->data[3];
		v20 = ptr_5D4594_3799572->data[2];
		v30 = a2 + a3;
		if (!v7 && a1 < v5 && v9 >= ptr_5D4594_3799572->data[2] && v9 < v18) {
			v5 = ptr_5D4594_3799572->data[3];
			*(_BYTE*)(a1 + *(_DWORD*)((_DWORD)nox_pixbuffer_rows_3798784 + 4 * (a2 + a3))) =
				*(_BYTE*)(v23 + (*(unsigned __int8*)(a1 + *(_DWORD*)((_DWORD)nox_pixbuffer_rows_3798784 + 4 * (a2 + a3))) << 8) +
						  dword_5d4594_810632);
		}
		v10 = a1 + a3;
		if (a1 + a3 >= v21) {
			if (v10 < v5 && a2 >= v20 && a2 < v18) {
				v5 = v19;
				nox_pixbuffer_rows_3798784[a2][a1 + a3] =
					*(_BYTE*)(v23 + (*(unsigned __int8*)(a1 + a3 + (_DWORD)nox_pixbuffer_rows_3798784[a2]) << 8) +
							  dword_5d4594_810632);
				v10 = a1 + a3;
			}
			if (v10 >= v21 && v10 < v5 && a2 >= v20 && a2 < v18) {
				v5 = v19;
				nox_pixbuffer_rows_3798784[a2][v10] =
					*(_BYTE*)(v23 + (*(unsigned __int8*)(v10 + (_DWORD)nox_pixbuffer_rows_3798784[a2]) << 8) +
							  dword_5d4594_810632);
			}
		}
		v11 = a2 - a3;
		if (a1 >= v21) {
			if (a1 < v5 && v11 >= v20 && v11 < v18) {
				v5 = v19;
				*(_BYTE*)(a1 + *(_DWORD*)((_DWORD)nox_pixbuffer_rows_3798784 + 4 * (a2 - a3))) =
					*(_BYTE*)(v23 + (*(unsigned __int8*)(a1 + *(_DWORD*)((_DWORD)nox_pixbuffer_rows_3798784 + 4 * (a2 - a3))) << 8) +
							  dword_5d4594_810632);
				v11 = a2 - a3;
			}
			if (a1 >= v21 && a1 < v5 && v11 >= v20 && v11 < v18) {
				nox_pixbuffer_rows_3798784[v11][a1] =
					*(_BYTE*)(v23 + (*(unsigned __int8*)(a1 + (_DWORD)nox_pixbuffer_rows_3798784[v11]) << 8) +
							  dword_5d4594_810632);
				v11 = a2 - a3;
			}
		}
		v12 = a1 - a3;
		if (a1 - a3 >= v21) {
			if (v12 < v19 && a2 >= v20 && a2 < v18) {
				nox_pixbuffer_rows_3798784[a2][v12] =
					*(_BYTE*)(v23 + (*(unsigned __int8*)(v12 + (_DWORD)nox_pixbuffer_rows_3798784[a2]) << 8) +
							  dword_5d4594_810632);
				v8 = v23;
				v11 = a2 - a3;
			}
			if (v12 >= v21 && v12 < v19 && a2 >= v20 && a2 < v18) {
				nox_pixbuffer_rows_3798784[a2][v12] =
					*(_BYTE*)(v8 + (*(unsigned __int8*)(v12 + (_DWORD)nox_pixbuffer_rows_3798784[a2]) << 8) +
							  dword_5d4594_810632);
				v8 = v23;
				v11 = a2 - a3;
			}
		}
		if (a1 >= v21 && a1 < v19) {
			if (v30 >= v20 && v30 < v18) {
				nox_pixbuffer_rows_3798784[v30][a1] =
					*(_BYTE*)(v8 + (*(unsigned __int8*)(a1 + (_DWORD)nox_pixbuffer_rows_3798784[v30]) << 8) +
							  dword_5d4594_810632);
				v8 = v23;
			}
			v11 = a2 - a3;
		}
		if (a3 > 0) {
			v36 = a1 - a3;
			v31 = 4 * v30;
			v28 = a1 + v4;
			v24 = 4 * v11;
			v34 = a1 - a2;
			v13 = a2 - a1;
			result = v36;
			v14 = a1;
			v27 = 4 * a2;
			v26 = 4 * a2;
			for (i = a2 - a1;; v13 = i) {
				if (v22 >= 0) {
					v22 += v25;
					v25 += 4;
					--v33;
					v31 -= 4;
					v15 = v28 - 1;
					++result;
					--v28;
					v24 += 4;
					v36 = result;
				} else {
					v22 += v29;
					v15 = v28;
					v25 += 2;
				}
				v29 += 2;
				++v14;
				++v32;
				v26 -= 4;
				--a2;
				v27 += 4;
				if (v14 < v21 || v14 >= v19)
					goto LABEL_54;
				v16 = v13 + v15;
				v17 = v20;
				if (v16 >= v20 && v16 < v18)
					break;
			LABEL_55:
				if (v15 >= v21 && v15 < v19) {
					if (v14 + i >= v17 && v14 + i < v18) {
						v17 = v20;
						nox_pixbuffer_rows_3798784[v27/4][v15] =
							*(_BYTE*)(v8 + (*(unsigned __int8*)((_DWORD)nox_pixbuffer_rows_3798784[v27/4] + v15) << 8) +
									  dword_5d4594_810632);
						result = v36;
					}
					if (v15 < v19 && a2 >= v17 && a2 < v18) {
						nox_pixbuffer_rows_3798784[v26/4][v15] =
							*(_BYTE*)(v8 + (*(unsigned __int8*)((_DWORD)nox_pixbuffer_rows_3798784[v26/4] + v15) << 8) +
									  dword_5d4594_810632);
						result = v36;
					}
				}
				if (v14 >= v21 && v14 < v19 && result + i >= v17 && result + i < v18) {
					nox_pixbuffer_rows_3798784[v24/4][v14] =
						*(_BYTE*)(v8 + (*(unsigned __int8*)((_DWORD)nox_pixbuffer_rows_3798784[v24/4] + v14) << 8) +
								  dword_5d4594_810632);
					result = v36;
				}
				if (v34 + a2 >= v21 && v34 + a2 < v19 && result + i >= v17 && result + i < v18) {
					nox_pixbuffer_rows_3798784[v24/4][v34 + a2] =
						*(_BYTE*)(v8 + (*(unsigned __int8*)((_DWORD)nox_pixbuffer_rows_3798784[v24/4] + v34 + a2) << 8) +
								  dword_5d4594_810632);
					result = v36;
				}
				if (result >= v21 && result < v19) {
					if (a2 >= v17 && a2 < v18) {
						nox_pixbuffer_rows_3798784[v26/4][result] =
							*(_BYTE*)(v8 + (*(unsigned __int8*)(result + (_DWORD)nox_pixbuffer_rows_3798784[v26/4]) << 8) +
									  dword_5d4594_810632);
						result = v36;
					}
					if (result < v19 && v14 + i >= v17 && v14 + i < v18)
						nox_pixbuffer_rows_3798784[v27/4][result] =
							*(_BYTE*)(v8 + (*(unsigned __int8*)(result + (_DWORD)nox_pixbuffer_rows_3798784[v27/4]) << 8) +
									  dword_5d4594_810632);
				}
				if (v33 <= v32)
					return result;
			}
			nox_pixbuffer_rows_3798784[v31/4][v14] =
				*(_BYTE*)(v8 + (*(unsigned __int8*)((_DWORD)nox_pixbuffer_rows_3798784[v31/4] + v14) << 8) +
						  dword_5d4594_810632);
			result = v36;
		LABEL_54:
			v17 = v20;
			goto LABEL_55;
		}
	}
	return result;
}

//----- (004B2480) --------------------------------------------------------
_WORD* __cdecl nox_video_drawCircle16Alpha_4B2480(int a1, int a2, int a3) {
	_WORD* result;           // eax
	unsigned int colourBase; // esi
	int v5;                  // ecx
	_WORD* v6;               // ecx
	int redcol;              // ebp
	int bluecol2;            // esi
	int grencol2;            // edi
	_WORD* v10;              // ecx
	_WORD* v11;              // eax
	int v12;                 // eax
	_WORD* v13;              // eax
	_WORD* v14;              // eax
	_WORD* v15;              // eax
	_WORD* v16;              // eax
	_WORD* v17;              // eax
	int v19;                 // ecx
	_WORD* v20;              // eax
	_WORD* v21;              // eax
	_WORD* v22;              // eax
	_WORD* v23;              // eax
	_WORD* v24;              // eax
	_WORD* v25;              // eax
	_WORD* v26;              // eax
	_WORD* v27;              // eax
	int v44;                 // [esp+20h] [ebp-30h]
	int v45;                 // [esp+24h] [ebp-2Ch]
	int v46;                 // [esp+28h] [ebp-28h]
	int v47;                 // [esp+28h] [ebp-28h]
	int v48;                 // [esp+2Ch] [ebp-24h]
	int v49;                 // [esp+30h] [ebp-20h]
	int v50;                 // [esp+30h] [ebp-20h]
	int v51;                 // [esp+34h] [ebp-1Ch]
	int v52;                 // [esp+34h] [ebp-1Ch]
	int v53;                 // [esp+38h] [ebp-18h]
	int v54;                 // [esp+38h] [ebp-18h]
	int v55;                 // [esp+3Ch] [ebp-14h]
	int v56;                 // [esp+40h] [ebp-10h]
	int v57;                 // [esp+44h] [ebp-Ch]
	unsigned __int8 grencol; // [esp+48h] [ebp-8h]
	int v59;                 // [esp+48h] [ebp-8h]
	unsigned __int8 bluecol; // [esp+4Ch] [ebp-4h]
	int v61;                 // [esp+4Ch] [ebp-4h]
	int v62;                 // [esp+54h] [ebp+4h]
	int v63;                 // [esp+54h] [ebp+4h]
	int v64;                 // [esp+58h] [ebp+8h]

	if (ptr_5D4594_3799572->data[0] && sub_49F8E0(a1, a2, a3))
		return (_WORD*)sub_4B3450(a1, a2, a3);
	v57 = 0;
	v56 = a3; // Radius?
	colourBase = *(unsigned __int16*)(&ptr_5D4594_3799572->data[61]);
	v55 = 3;
	grencol = (*(_DWORD*)&byte_5D4594[3804368] & colourBase) >> byte_5D4594[3804380];
	v44 = 1 - a3;
	bluecol = ((unsigned __int8)*(_WORD*)(&ptr_5D4594_3799572->data[61]) & byte_5D4594[3804372])
			  << byte_5D4594[3804384];
	v45 = 5 - 2 * a3;
	v5 = 4 * (a3 + a2);
	v53 = v5;
	v46 = 2 * a1;
	v6 = 2 * a1 + (_DWORD)nox_pixbuffer_rows_3798784[v5/4];
	redcol = (unsigned __int8)((*(_DWORD*)&byte_5D4594[3804364] & colourBase) >> byte_5D4594[3804376]);
	bluecol2 = bluecol;
	grencol2 = grencol;
	*v6 =
		*(_WORD*)(dword_5d4594_3804664 +
				  2 * (unsigned __int8)((((unsigned __int8)*v6 & byte_5D4594[3804372]) << byte_5D4594[3804384]) +
										((bluecol - (unsigned __int8)(((unsigned __int8)*v6 & byte_5D4594[3804372])
																	  << byte_5D4594[3804384])) >>
										 2))) |
		*(_WORD*)(dword_5d4594_3804656 +
				  2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)&byte_5D4594[3804368] & *v6) >>
										 byte_5D4594[3804380]) +
										((grencol -
										  (unsigned __int8)((unsigned __int16)(*(_WORD*)&byte_5D4594[3804368] & *v6) >>
															byte_5D4594[3804380])) >>
										 2))) |
		*(_WORD*)(dword_5d4594_3804672 +
				  2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)&byte_5D4594[3804364] & *v6) >>
										 byte_5D4594[3804376]) +
										((redcol -
										  (unsigned __int8)((unsigned __int16)(*(_WORD*)&byte_5D4594[3804364] & *v6) >>
															byte_5D4594[3804376])) >>
										 2)));
	v49 = 4 * a2;
	v10 = 2 * (a1 + a3) + *(_DWORD*)(4 * a2 + (_DWORD)nox_pixbuffer_rows_3798784);
	v59 = 2 * (a1 + a3);
	*v10 =
		*(_WORD*)(dword_5d4594_3804664 +
				  2 * (unsigned __int8)((((unsigned __int8)*v10 & byte_5D4594[3804372]) << byte_5D4594[3804384]) +
										((bluecol - (unsigned __int8)(((unsigned __int8)*v10 & byte_5D4594[3804372])
																	  << byte_5D4594[3804384])) >>
										 2))) |
		*(_WORD*)(dword_5d4594_3804656 +
				  2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)&byte_5D4594[3804368] & *v10) >>
										 byte_5D4594[3804380]) +
										((grencol2 -
										  (unsigned __int8)((unsigned __int16)(*(_WORD*)&byte_5D4594[3804368] & *v10) >>
															byte_5D4594[3804380])) >>
										 2))) |
		*(_WORD*)(dword_5d4594_3804672 +
				  2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)&byte_5D4594[3804364] & *v10) >>
										 byte_5D4594[3804376]) +
										((redcol -
										  (unsigned __int8)((unsigned __int16)(*(_WORD*)&byte_5D4594[3804364] & *v10) >>
															byte_5D4594[3804376])) >>
										 2)));
	v11 = v59 + (_DWORD)nox_pixbuffer_rows_3798784[a2];
	*v11 =
		*(_WORD*)(dword_5d4594_3804664 +
				  2 * (unsigned __int8)((((unsigned __int8)*v11 & byte_5D4594[3804372]) << byte_5D4594[3804384]) +
										((bluecol - (unsigned __int8)(((unsigned __int8)*v11 & byte_5D4594[3804372])
																	  << byte_5D4594[3804384])) >>
										 2))) |
		*(_WORD*)(dword_5d4594_3804656 +
				  2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)&byte_5D4594[3804368] & *v11) >>
										 byte_5D4594[3804380]) +
										((grencol2 -
										  (unsigned __int8)((unsigned __int16)(*(_WORD*)&byte_5D4594[3804368] & *v11) >>
															byte_5D4594[3804380])) >>
										 2))) |
		*(_WORD*)(dword_5d4594_3804672 +
				  2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)&byte_5D4594[3804364] & *v11) >>
										 byte_5D4594[3804376]) +
										((redcol -
										  (unsigned __int8)((unsigned __int16)(*(_WORD*)&byte_5D4594[3804364] & *v11) >>
															byte_5D4594[3804376])) >>
										 2)));
	v12 = 4 * (a2 - a3);
	v61 = v12;
	v13 = 2 * a1 + (_DWORD)nox_pixbuffer_rows_3798784[v12/4];
	*v13 =
		*(_WORD*)(dword_5d4594_3804664 +
				  2 * (unsigned __int8)((((unsigned __int8)*v13 & byte_5D4594[3804372]) << byte_5D4594[3804384]) +
										((bluecol2 - (unsigned __int8)(((unsigned __int8)*v13 & byte_5D4594[3804372])
																	   << byte_5D4594[3804384])) >>
										 2))) |
		*(_WORD*)(dword_5d4594_3804656 +
				  2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)&byte_5D4594[3804368] & *v13) >>
										 byte_5D4594[3804380]) +
										((grencol2 -
										  (unsigned __int8)((unsigned __int16)(*(_WORD*)&byte_5D4594[3804368] & *v13) >>
															byte_5D4594[3804380])) >>
										 2))) |
		*(_WORD*)(dword_5d4594_3804672 +
				  2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)&byte_5D4594[3804364] & *v13) >>
										 byte_5D4594[3804376]) +
										((redcol -
										  (unsigned __int8)((unsigned __int16)(*(_WORD*)&byte_5D4594[3804364] & *v13) >>
															byte_5D4594[3804376])) >>
										 2)));
	v51 = 2 * a1;
	v14 = 2 * a1 + (_DWORD)nox_pixbuffer_rows_3798784[v61/4];
	*v14 =
		*(_WORD*)(dword_5d4594_3804664 +
				  2 * (unsigned __int8)((((unsigned __int8)*v14 & byte_5D4594[3804372]) << byte_5D4594[3804384]) +
										((bluecol2 - (unsigned __int8)(((unsigned __int8)*v14 & byte_5D4594[3804372])
																	   << byte_5D4594[3804384])) >>
										 2))) |
		*(_WORD*)(dword_5d4594_3804656 +
				  2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)&byte_5D4594[3804368] & *v14) >>
										 byte_5D4594[3804380]) +
										((grencol2 -
										  (unsigned __int8)((unsigned __int16)(*(_WORD*)&byte_5D4594[3804368] & *v14) >>
															byte_5D4594[3804380])) >>
										 2))) |
		*(_WORD*)(dword_5d4594_3804672 +
				  2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)&byte_5D4594[3804364] & *v14) >>
										 byte_5D4594[3804376]) +
										((redcol -
										  (unsigned __int8)((unsigned __int16)(*(_WORD*)&byte_5D4594[3804364] & *v14) >>
															byte_5D4594[3804376])) >>
										 2)));
	v62 = 2 * (a1 - a3);
	v15 = v62 + (_DWORD)nox_pixbuffer_rows_3798784[a2];
	*v15 =
		*(_WORD*)(dword_5d4594_3804664 +
				  2 * (unsigned __int8)((((unsigned __int8)*v15 & byte_5D4594[3804372]) << byte_5D4594[3804384]) +
										((bluecol2 - (unsigned __int8)(((unsigned __int8)*v15 & byte_5D4594[3804372])
																	   << byte_5D4594[3804384])) >>
										 2))) |
		*(_WORD*)(dword_5d4594_3804656 +
				  2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)&byte_5D4594[3804368] & *v15) >>
										 byte_5D4594[3804380]) +
										((grencol2 -
										  (unsigned __int8)((unsigned __int16)(*(_WORD*)&byte_5D4594[3804368] & *v15) >>
															byte_5D4594[3804380])) >>
										 2))) |
		*(_WORD*)(dword_5d4594_3804672 +
				  2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)&byte_5D4594[3804364] & *v15) >>
										 byte_5D4594[3804376]) +
										((redcol -
										  (unsigned __int8)((unsigned __int16)(*(_WORD*)&byte_5D4594[3804364] & *v15) >>
															byte_5D4594[3804376])) >>
										 2)));
	v16 = v62 + *(_DWORD*)(4 * a2 + (_DWORD)nox_pixbuffer_rows_3798784);
	*v16 =
		*(_WORD*)(dword_5d4594_3804664 +
				  2 * (unsigned __int8)((((unsigned __int8)*v16 & byte_5D4594[3804372]) << byte_5D4594[3804384]) +
										((bluecol2 - (unsigned __int8)(((unsigned __int8)*v16 & byte_5D4594[3804372])
																	   << byte_5D4594[3804384])) >>
										 2))) |
		*(_WORD*)(dword_5d4594_3804656 +
				  2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)&byte_5D4594[3804368] & *v16) >>
										 byte_5D4594[3804380]) +
										((grencol2 -
										  (unsigned __int8)((unsigned __int16)(*(_WORD*)&byte_5D4594[3804368] & *v16) >>
															byte_5D4594[3804380])) >>
										 2))) |
		*(_WORD*)(dword_5d4594_3804672 +
				  2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)&byte_5D4594[3804364] & *v16) >>
										 byte_5D4594[3804376]) +
										((redcol -
										  (unsigned __int8)((unsigned __int16)(*(_WORD*)&byte_5D4594[3804364] & *v16) >>
															byte_5D4594[3804376])) >>
										 2)));
	v17 = v51 + (_DWORD)nox_pixbuffer_rows_3798784[v53/4];
	*v17 =
		*(_WORD*)(dword_5d4594_3804664 +
				  2 * (unsigned __int8)((((unsigned __int8)*v17 & byte_5D4594[3804372]) << byte_5D4594[3804384]) +
										((bluecol2 - (unsigned __int8)(((unsigned __int8)*v17 & byte_5D4594[3804372])
																	   << byte_5D4594[3804384])) >>
										 2))) |
		*(_WORD*)(dword_5d4594_3804656 +
				  2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)&byte_5D4594[3804368] & *v17) >>
										 byte_5D4594[3804380]) +
										((grencol2 -
										  (unsigned __int8)((unsigned __int16)(*(_WORD*)&byte_5D4594[3804368] & *v17) >>
															byte_5D4594[3804380])) >>
										 2))) |
		*(_WORD*)(dword_5d4594_3804672 +
				  2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)&byte_5D4594[3804364] & *v17) >>
										 byte_5D4594[3804376]) +
										((redcol -
										  (unsigned __int8)((unsigned __int16)(*(_WORD*)&byte_5D4594[3804364] & *v17) >>
															byte_5D4594[3804376])) >>
										 2)));
	result = v17;
	if (a3 > 0) {
		v52 = v53;
		v19 = v46;
		v64 = v59;
		v48 = v49;
		v47 = v49;
		v50 = v62;
		v54 = v19;
		v63 = v61;
		while (1) {
			if (v44 >= 0) {
				v44 += v45;
				v45 += 4;
				v56 -= 1;
				v64 -= 2;
				v52 -= 4;
				v63 += 4;
				v50 += 2;
			} else {
				v44 += v55;
				v45 += 2;
			}
			v55 += 2;
			++v57;
			v48 += 4;
			v47 -= 4;
			v54 -= 2;
			v20 = v19 + 2 + (_DWORD)nox_pixbuffer_rows_3798784[v52/4];
			*v20 =
				*(_WORD*)(dword_5d4594_3804664 +
						  2 * (unsigned __int8)((((unsigned __int8)*v20 & byte_5D4594[3804372])
												 << byte_5D4594[3804384]) +
												((bluecol2 -
												  (unsigned __int8)(((unsigned __int8)*v20 & byte_5D4594[3804372])
																	<< byte_5D4594[3804384])) >>
												 2))) |
				*(_WORD*)(dword_5d4594_3804656 +
						  2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)&byte_5D4594[3804368] & *v20) >>
												 byte_5D4594[3804380]) +
												((grencol2 -
												  (unsigned __int8)((unsigned __int16)(*(_WORD*)&byte_5D4594[3804368] &
																					   *v20) >>
																	byte_5D4594[3804380])) >>
												 2))) |
				*(_WORD*)(dword_5d4594_3804672 +
						  2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)&byte_5D4594[3804364] & *v20) >>
												 byte_5D4594[3804376]) +
												((redcol -
												  (unsigned __int8)((unsigned __int16)(*(_WORD*)&byte_5D4594[3804364] &
																					   *v20) >>
																	byte_5D4594[3804376])) >>
												 2)));
			v21 = v64 + (_DWORD)nox_pixbuffer_rows_3798784[v48/4];
			*v21 =
				*(_WORD*)(dword_5d4594_3804664 +
						  2 * (unsigned __int8)((((unsigned __int8)*v21 & byte_5D4594[3804372])
												 << byte_5D4594[3804384]) +
												((bluecol2 -
												  (unsigned __int8)(((unsigned __int8)*v21 & byte_5D4594[3804372])
																	<< byte_5D4594[3804384])) >>
												 2))) |
				*(_WORD*)(dword_5d4594_3804656 +
						  2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)&byte_5D4594[3804368] & *v21) >>
												 byte_5D4594[3804380]) +
												((grencol2 -
												  (unsigned __int8)((unsigned __int16)(*(_WORD*)&byte_5D4594[3804368] &
																					   *v21) >>
																	byte_5D4594[3804380])) >>
												 2))) |
				*(_WORD*)(dword_5d4594_3804672 +
						  2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)&byte_5D4594[3804364] & *v21) >>
												 byte_5D4594[3804376]) +
												((redcol -
												  (unsigned __int8)((unsigned __int16)(*(_WORD*)&byte_5D4594[3804364] &
																					   *v21) >>
																	byte_5D4594[3804376])) >>
												 2)));
			v22 = v64 + (_DWORD)nox_pixbuffer_rows_3798784[v47/4];
			*v22 =
				*(_WORD*)(dword_5d4594_3804664 +
						  2 * (unsigned __int8)((((unsigned __int8)*v22 & byte_5D4594[3804372])
												 << byte_5D4594[3804384]) +
												((bluecol2 -
												  (unsigned __int8)(((unsigned __int8)*v22 & byte_5D4594[3804372])
																	<< byte_5D4594[3804384])) >>
												 2))) |
				*(_WORD*)(dword_5d4594_3804656 +
						  2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)&byte_5D4594[3804368] & *v22) >>
												 byte_5D4594[3804380]) +
												((grencol2 -
												  (unsigned __int8)((unsigned __int16)(*(_WORD*)&byte_5D4594[3804368] &
																					   *v22) >>
																	byte_5D4594[3804380])) >>
												 2))) |
				*(_WORD*)(dword_5d4594_3804672 +
						  2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)&byte_5D4594[3804364] & *v22) >>
												 byte_5D4594[3804376]) +
												((redcol -
												  (unsigned __int8)((unsigned __int16)(*(_WORD*)&byte_5D4594[3804364] &
																					   *v22) >>
																	byte_5D4594[3804376])) >>
												 2)));
			v23 = v19 + 2 + (_DWORD)nox_pixbuffer_rows_3798784[v63/4];
			*v23 =
				*(_WORD*)(dword_5d4594_3804664 +
						  2 * (unsigned __int8)((((unsigned __int8)*v23 & byte_5D4594[3804372])
												 << byte_5D4594[3804384]) +
												((bluecol2 -
												  (unsigned __int8)(((unsigned __int8)*v23 & byte_5D4594[3804372])
																	<< byte_5D4594[3804384])) >>
												 2))) |
				*(_WORD*)(dword_5d4594_3804656 +
						  2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)&byte_5D4594[3804368] & *v23) >>
												 byte_5D4594[3804380]) +
												((grencol2 -
												  (unsigned __int8)((unsigned __int16)(*(_WORD*)&byte_5D4594[3804368] &
																					   *v23) >>
																	byte_5D4594[3804380])) >>
												 2))) |
				*(_WORD*)(dword_5d4594_3804672 +
						  2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)&byte_5D4594[3804364] & *v23) >>
												 byte_5D4594[3804376]) +
												((redcol -
												  (unsigned __int8)((unsigned __int16)(*(_WORD*)&byte_5D4594[3804364] &
																					   *v23) >>
																	byte_5D4594[3804376])) >>
												 2)));
			v24 = v54 + (_DWORD)nox_pixbuffer_rows_3798784[v63/4];
			*v24 =
				*(_WORD*)(dword_5d4594_3804664 +
						  2 * (unsigned __int8)((((unsigned __int8)*v24 & byte_5D4594[3804372])
												 << byte_5D4594[3804384]) +
												((bluecol2 -
												  (unsigned __int8)(((unsigned __int8)*v24 & byte_5D4594[3804372])
																	<< byte_5D4594[3804384])) >>
												 2))) |
				*(_WORD*)(dword_5d4594_3804656 +
						  2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)&byte_5D4594[3804368] & *v24) >>
												 byte_5D4594[3804380]) +
												((grencol2 -
												  (unsigned __int8)((unsigned __int16)(*(_WORD*)&byte_5D4594[3804368] &
																					   *v24) >>
																	byte_5D4594[3804380])) >>
												 2))) |
				*(_WORD*)(dword_5d4594_3804672 +
						  2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)&byte_5D4594[3804364] & *v24) >>
												 byte_5D4594[3804376]) +
												((redcol -
												  (unsigned __int8)((unsigned __int16)(*(_WORD*)&byte_5D4594[3804364] &
																					   *v24) >>
																	byte_5D4594[3804376])) >>
												 2)));
			v25 = v50 + (_DWORD)nox_pixbuffer_rows_3798784[v47/4];
			*v25 =
				*(_WORD*)(dword_5d4594_3804664 +
						  2 * (unsigned __int8)((((unsigned __int8)*v25 & byte_5D4594[3804372])
												 << byte_5D4594[3804384]) +
												((bluecol2 -
												  (unsigned __int8)(((unsigned __int8)*v25 & byte_5D4594[3804372])
																	<< byte_5D4594[3804384])) >>
												 2))) |
				*(_WORD*)(dword_5d4594_3804656 +
						  2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)&byte_5D4594[3804368] & *v25) >>
												 byte_5D4594[3804380]) +
												((grencol2 -
												  (unsigned __int8)((unsigned __int16)(*(_WORD*)&byte_5D4594[3804368] &
																					   *v25) >>
																	byte_5D4594[3804380])) >>
												 2))) |
				*(_WORD*)(dword_5d4594_3804672 +
						  2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)&byte_5D4594[3804364] & *v25) >>
												 byte_5D4594[3804376]) +
												((redcol -
												  (unsigned __int8)((unsigned __int16)(*(_WORD*)&byte_5D4594[3804364] &
																					   *v25) >>
																	byte_5D4594[3804376])) >>
												 2)));
			v26 = v50 + (_DWORD)nox_pixbuffer_rows_3798784[v48/4];
			*v26 =
				*(_WORD*)(dword_5d4594_3804664 +
						  2 * (unsigned __int8)((((unsigned __int8)*v26 & byte_5D4594[3804372])
												 << byte_5D4594[3804384]) +
												((bluecol2 -
												  (unsigned __int8)(((unsigned __int8)*v26 & byte_5D4594[3804372])
																	<< byte_5D4594[3804384])) >>
												 2))) |
				*(_WORD*)(dword_5d4594_3804656 +
						  2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)&byte_5D4594[3804368] & *v26) >>
												 byte_5D4594[3804380]) +
												((grencol2 -
												  (unsigned __int8)((unsigned __int16)(*(_WORD*)&byte_5D4594[3804368] &
																					   *v26) >>
																	byte_5D4594[3804380])) >>
												 2))) |
				*(_WORD*)(dword_5d4594_3804672 +
						  2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)&byte_5D4594[3804364] & *v26) >>
												 byte_5D4594[3804376]) +
												((redcol -
												  (unsigned __int8)((unsigned __int16)(*(_WORD*)&byte_5D4594[3804364] &
																					   *v26) >>
																	byte_5D4594[3804376])) >>
												 2)));
			v27 = v54 + (_DWORD)nox_pixbuffer_rows_3798784[v52/4];
			*v27 =
				*(_WORD*)(dword_5d4594_3804664 +
						  2 * (unsigned __int8)((((unsigned __int8)*v27 & byte_5D4594[3804372])
												 << byte_5D4594[3804384]) +
												((bluecol2 -
												  (unsigned __int8)(((unsigned __int8)*v27 & byte_5D4594[3804372])
																	<< byte_5D4594[3804384])) >>
												 2))) |
				*(_WORD*)(dword_5d4594_3804656 +
						  2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)&byte_5D4594[3804368] & *v27) >>
												 byte_5D4594[3804380]) +
												((grencol2 -
												  (unsigned __int8)((unsigned __int16)(*(_WORD*)&byte_5D4594[3804368] &
																					   *v27) >>
																	byte_5D4594[3804380])) >>
												 2))) |
				*(_WORD*)(dword_5d4594_3804672 +
						  2 * (unsigned __int8)(((unsigned __int16)(*(_WORD*)&byte_5D4594[3804364] & *v27) >>
												 byte_5D4594[3804376]) +
												((redcol -
												  (unsigned __int8)((unsigned __int16)(*(_WORD*)&byte_5D4594[3804364] &
																					   *v27) >>
																	byte_5D4594[3804376])) >>
												 2)));
			result = v56;
			if (v56 <= v57)
				break;
			v19 += 2;
		}
	}
	return result;
}

//----- (004B3450) --------------------------------------------------------
int __cdecl sub_4B3450(int a1, int a2, int a3) {
	__int16 v3;          // ax
	unsigned __int8 v4;  // bp
	unsigned __int8 v5;  // dl
	unsigned __int8 v6;  // di
	char v7;             // bl
	unsigned __int8 v8;  // al
	unsigned __int8 v9;  // si
	int v10;             // ecx
	int v11;             // ecx
	int v12;             // ecx
	int v13;             // ecx
	int result;          // eax
	int v15;             // eax
	int v16;             // ebx
	int v17;             // edx
	int v18;             // ecx
	int v19;             // edx
	int v20;             // eax
	int v21;             // eax
	_WORD* v22;          // eax
	unsigned int v23;    // ebx
	int v24;             // ecx
	_WORD* v25;          // eax
	unsigned int v26;    // ebx
	_WORD* v27;          // eax
	unsigned int v28;    // ebx
	_WORD* v29;          // eax
	unsigned int v30;    // ebx
	_WORD* v31;          // eax
	unsigned int v32;    // ebx
	_WORD* v33;          // eax
	unsigned int v34;    // ebx
	_WORD* v35;          // eax
	unsigned int v36;    // ebx
	_WORD* v37;          // eax
	unsigned int v38;    // ebx
	_WORD* v39;          // [esp+1Ch] [ebp-54h]
	_WORD* v40;          // [esp+1Ch] [ebp-54h]
	_WORD* v41;          // [esp+1Ch] [ebp-54h]
	_WORD* v42;          // [esp+1Ch] [ebp-54h]
	_WORD* v43;          // [esp+1Ch] [ebp-54h]
	_WORD* v44;          // [esp+1Ch] [ebp-54h]
	_WORD* v45;          // [esp+1Ch] [ebp-54h]
	_WORD* v46;          // [esp+1Ch] [ebp-54h]
	int v47;             // [esp+1Ch] [ebp-54h]
	int v48;             // [esp+20h] [ebp-50h]
	int v49;             // [esp+24h] [ebp-4Ch]
	int v50;             // [esp+28h] [ebp-48h]
	unsigned int v51;    // [esp+2Ch] [ebp-44h]
	unsigned int v52;    // [esp+2Ch] [ebp-44h]
	unsigned int v53;    // [esp+2Ch] [ebp-44h]
	unsigned int v54;    // [esp+2Ch] [ebp-44h]
	unsigned int v55;    // [esp+2Ch] [ebp-44h]
	unsigned int v56;    // [esp+2Ch] [ebp-44h]
	unsigned int v57;    // [esp+2Ch] [ebp-44h]
	unsigned int v58;    // [esp+2Ch] [ebp-44h]
	int v59;             // [esp+2Ch] [ebp-44h]
	int v60;             // [esp+30h] [ebp-40h]
	int v61;             // [esp+34h] [ebp-3Ch]
	int v62;             // [esp+34h] [ebp-3Ch]
	int v63;             // [esp+38h] [ebp-38h]
	int v64;             // [esp+38h] [ebp-38h]
	int v65;             // [esp+3Ch] [ebp-34h]
	int v66;             // [esp+40h] [ebp-30h]
	int v67;             // [esp+44h] [ebp-2Ch]
	int v68;             // [esp+44h] [ebp-2Ch]
	int v69;             // [esp+48h] [ebp-28h]
	int v70;             // [esp+4Ch] [ebp-24h]
	unsigned __int8 v71; // [esp+50h] [ebp-20h]
	int v72;             // [esp+50h] [ebp-20h]
	int v73;             // [esp+54h] [ebp-1Ch]
	int v74;             // [esp+54h] [ebp-1Ch]
	int v75;             // [esp+58h] [ebp-18h]
	unsigned __int8 v76; // [esp+5Ch] [ebp-14h]
	int v77;             // [esp+5Ch] [ebp-14h]
	int v78;             // [esp+60h] [ebp-10h]
	int v79;             // [esp+64h] [ebp-Ch]
	unsigned __int8 v80; // [esp+68h] [ebp-8h]
	int i;               // [esp+68h] [ebp-8h]
	int v82;             // [esp+78h] [ebp+8h]
	int v83;             // [esp+7Ch] [ebp+Ch]

	v79 = a3;
	v65 = 1 - a3;
	v66 = 5 - 2 * a3;
	v60 = ptr_5D4594_3799572->data[1];
	v48 = ptr_5D4594_3799572->data[3];
	v3 = *(_WORD*)(&ptr_5D4594_3799572->data[61]);
	v49 = ptr_5D4594_3799572->data[2];
	v50 = ptr_5D4594_3799572->data[4];
	v78 = 0;
	v75 = 3;
	v71 = (unsigned __int16)(*(_WORD*)&byte_5D4594[3804364] & v3) >> byte_5D4594[3804376];
	v4 = (unsigned __int16)(*(_WORD*)&byte_5D4594[3804364] & v3) >> byte_5D4594[3804376];
	v76 = (unsigned __int16)(*(_WORD*)&byte_5D4594[3804368] & v3) >> byte_5D4594[3804380];
	v5 = byte_5D4594[3804372];
	v6 = (unsigned __int16)(*(_WORD*)&byte_5D4594[3804368] & v3) >> byte_5D4594[3804380];
	v7 = v3 & byte_5D4594[3804372];
	v8 = byte_5D4594[3804384];
	v73 = a3 + a2;
	v80 = v7 << byte_5D4594[3804384];
	v9 = v7 << byte_5D4594[3804384];
	if (a1 >= v60 && a1 < v48 && v73 >= v49 && v73 < v50) {
		v39 = (_WORD*)((_DWORD)nox_pixbuffer_rows_3798784[v73] + 2 * a1);
		v51 = (unsigned __int16)*v39;
		*v39 = *(_WORD*)(dword_5d4594_3804672 +
						 2 * (unsigned __int8)(((*(_DWORD*)&byte_5D4594[3804364] & v51) >> byte_5D4594[3804376]) +
											   ((v71 - (unsigned __int8)((*(_DWORD*)&byte_5D4594[3804364] & v51) >>
																		 byte_5D4594[3804376])) >>
												2))) |
			   *(_WORD*)(dword_5d4594_3804656 +
						 2 * (unsigned __int8)(((*(_DWORD*)&byte_5D4594[3804368] & v51) >> byte_5D4594[3804380]) +
											   ((v76 - (unsigned __int8)((*(_DWORD*)&byte_5D4594[3804368] & v51) >>
																		 byte_5D4594[3804380])) >>
												2))) |
			   *(_WORD*)(dword_5d4594_3804664 +
						 2 * (unsigned __int8)(((*(_BYTE*)v39 & byte_5D4594[3804372]) << byte_5D4594[3804384]) +
											   ((v80 - (unsigned __int8)((*(_BYTE*)v39 & byte_5D4594[3804372])
																		 << byte_5D4594[3804384])) >>
												2)));
		v8 = byte_5D4594[3804384];
		v5 = byte_5D4594[3804372];
	}
	v10 = a3 + a1;
	v63 = a3 + a1;
	if (a3 + a1 < v60)
		goto LABEL_17;
	if (v10 < v48) {
		if (a2 >= v49 && a2 < v50) {
			v40 = (_WORD*)((_DWORD)nox_pixbuffer_rows_3798784[a2] + 2 * v63);
			v52 = (unsigned __int16)*v40;
			*v40 = *(_WORD*)(dword_5d4594_3804672 +
							 2 * (unsigned __int8)(((*(_DWORD*)&byte_5D4594[3804364] & v52) >> byte_5D4594[3804376]) +
												   ((v71 - (unsigned __int8)((*(_DWORD*)&byte_5D4594[3804364] & v52) >>
																			 byte_5D4594[3804376])) >>
													2))) |
				   *(_WORD*)(dword_5d4594_3804656 +
							 2 * (unsigned __int8)(((*(_DWORD*)&byte_5D4594[3804368] & v52) >> byte_5D4594[3804380]) +
												   ((v76 - (unsigned __int8)((*(_DWORD*)&byte_5D4594[3804368] & v52) >>
																			 byte_5D4594[3804380])) >>
													2))) |
				   *(_WORD*)(dword_5d4594_3804664 +
							 2 * (unsigned __int8)(((*(_BYTE*)v40 & v5) << v8) +
												   ((v80 - (unsigned __int8)((*(_BYTE*)v40 & v5) << v8)) >> 2)));
			v8 = byte_5D4594[3804384];
			v5 = byte_5D4594[3804372];
		}
		v10 = a3 + a1;
	}
	if (v10 < v60 || v10 >= v48)
		goto LABEL_17;
	v11 = a2;
	if (a2 >= v49 && a2 < v50) {
		v41 = (_WORD*)((_DWORD)nox_pixbuffer_rows_3798784[a2] + 2 * v63);
		v53 = (unsigned __int16)*v41;
		*v41 = *(_WORD*)(dword_5d4594_3804672 +
						 2 * (unsigned __int8)(((*(_DWORD*)&byte_5D4594[3804364] & v53) >> byte_5D4594[3804376]) +
											   ((v71 - (unsigned __int8)((*(_DWORD*)&byte_5D4594[3804364] & v53) >>
																		 byte_5D4594[3804376])) >>
												2))) |
			   *(_WORD*)(dword_5d4594_3804656 +
						 2 * (unsigned __int8)(((*(_DWORD*)&byte_5D4594[3804368] & v53) >> byte_5D4594[3804380]) +
											   ((v76 - (unsigned __int8)((*(_DWORD*)&byte_5D4594[3804368] & v53) >>
																		 byte_5D4594[3804380])) >>
												2))) |
			   *(_WORD*)(dword_5d4594_3804664 +
						 2 * (unsigned __int8)(((*(_BYTE*)v41 & v5) << v8) +
											   ((v80 - (unsigned __int8)((*(_BYTE*)v41 & v5) << v8)) >> 2)));
		v8 = byte_5D4594[3804384];
		v5 = byte_5D4594[3804372];
	LABEL_17:
		v11 = a2;
	}
	v67 = v11 - a3;
	if (a1 >= v60 && a1 < v48 && v67 >= v49 && v67 < v50) {
		v42 = (_WORD*)((_DWORD)nox_pixbuffer_rows_3798784[v67] + 2 * a1);
		v54 = (unsigned __int16)*v42;
		*v42 = *(_WORD*)(dword_5d4594_3804672 +
						 2 * (unsigned __int8)(((*(_DWORD*)&byte_5D4594[3804364] & v54) >> byte_5D4594[3804376]) +
											   ((v71 - (unsigned __int8)((*(_DWORD*)&byte_5D4594[3804364] & v54) >>
																		 byte_5D4594[3804376])) >>
												2))) |
			   *(_WORD*)(dword_5d4594_3804656 +
						 2 * (unsigned __int8)(((*(_DWORD*)&byte_5D4594[3804368] & v54) >> byte_5D4594[3804380]) +
											   ((v76 - (unsigned __int8)((*(_DWORD*)&byte_5D4594[3804368] & v54) >>
																		 byte_5D4594[3804380])) >>
												2))) |
			   *(_WORD*)(dword_5d4594_3804664 +
						 2 * (unsigned __int8)(((*(_BYTE*)v42 & v5) << v8) +
											   ((v80 - (unsigned __int8)((*(_BYTE*)v42 & v5) << v8)) >> 2)));
		v8 = byte_5D4594[3804384];
		v5 = byte_5D4594[3804372];
	}
	if (a1 >= v60 && a1 < v48 && v67 >= v49 && v67 < v50) {
		v43 = (_WORD*)((_DWORD)nox_pixbuffer_rows_3798784[v67] + 2 * a1);
		v55 = (unsigned __int16)*v43;
		*v43 = *(_WORD*)(dword_5d4594_3804672 +
						 2 * (unsigned __int8)(((*(_DWORD*)&byte_5D4594[3804364] & v55) >> byte_5D4594[3804376]) +
											   ((v71 - (unsigned __int8)((*(_DWORD*)&byte_5D4594[3804364] & v55) >>
																		 byte_5D4594[3804376])) >>
												2))) |
			   *(_WORD*)(dword_5d4594_3804656 +
						 2 * (unsigned __int8)(((*(_DWORD*)&byte_5D4594[3804368] & v55) >> byte_5D4594[3804380]) +
											   ((v76 - (unsigned __int8)((*(_DWORD*)&byte_5D4594[3804368] & v55) >>
																		 byte_5D4594[3804380])) >>
												2))) |
			   *(_WORD*)(dword_5d4594_3804664 +
						 2 * (unsigned __int8)(((*(_BYTE*)v43 & v5) << v8) +
											   ((v80 - (unsigned __int8)((*(_BYTE*)v43 & v5) << v8)) >> 2)));
		v8 = byte_5D4594[3804384];
		v5 = byte_5D4594[3804372];
	}
	v12 = a1 - a3;
	v61 = a1 - a3;
	if (a1 - a3 >= v60) {
		if (v12 < v48) {
			if (a2 >= v49 && a2 < v50) {
				v44 = (_WORD*)((_DWORD)nox_pixbuffer_rows_3798784[a2] + 2 * v61);
				v56 = (unsigned __int16)*v44;
				*v44 =
					*(_WORD*)(dword_5d4594_3804672 +
							  2 * (unsigned __int8)(((*(_DWORD*)&byte_5D4594[3804364] & v56) >> byte_5D4594[3804376]) +
													((v71 - (unsigned __int8)((*(_DWORD*)&byte_5D4594[3804364] & v56) >>
																			  byte_5D4594[3804376])) >>
													 2))) |
					*(_WORD*)(dword_5d4594_3804656 +
							  2 * (unsigned __int8)(((*(_DWORD*)&byte_5D4594[3804368] & v56) >> byte_5D4594[3804380]) +
													((v76 - (unsigned __int8)((*(_DWORD*)&byte_5D4594[3804368] & v56) >>
																			  byte_5D4594[3804380])) >>
													 2))) |
					*(_WORD*)(dword_5d4594_3804664 +
							  2 * (unsigned __int8)(((*(_BYTE*)v44 & v5) << v8) +
													((v80 - (unsigned __int8)((*(_BYTE*)v44 & v5) << v8)) >> 2)));
				v8 = byte_5D4594[3804384];
				v5 = byte_5D4594[3804372];
			}
			v12 = a1 - a3;
		}
		if (v12 >= v60 && v12 < v48 && a2 >= v49 && a2 < v50) {
			v45 = (_WORD*)((_DWORD)nox_pixbuffer_rows_3798784[a2] + 2 * v61);
			v57 = (unsigned __int16)*v45;
			*v45 = *(_WORD*)(dword_5d4594_3804672 +
							 2 * (unsigned __int8)(((*(_DWORD*)&byte_5D4594[3804364] & v57) >> byte_5D4594[3804376]) +
												   ((v71 - (unsigned __int8)((*(_DWORD*)&byte_5D4594[3804364] & v57) >>
																			 byte_5D4594[3804376])) >>
													2))) |
				   *(_WORD*)(dword_5d4594_3804656 +
							 2 * (unsigned __int8)(((*(_DWORD*)&byte_5D4594[3804368] & v57) >> byte_5D4594[3804380]) +
												   ((v76 - (unsigned __int8)((*(_DWORD*)&byte_5D4594[3804368] & v57) >>
																			 byte_5D4594[3804380])) >>
													2))) |
				   *(_WORD*)(dword_5d4594_3804664 +
							 2 * (unsigned __int8)(((*(_BYTE*)v45 & v5) << v8) +
												   ((v80 - (unsigned __int8)((*(_BYTE*)v45 & v5) << v8)) >> 2)));
			v8 = byte_5D4594[3804384];
			v5 = byte_5D4594[3804372];
		}
	}
	v13 = a1;
	if (a1 >= v60 && a1 < v48) {
		if (v73 >= v49 && v73 < v50) {
			v46 = (_WORD*)((_DWORD)nox_pixbuffer_rows_3798784[v73] + 2 * a1);
			v58 = (unsigned __int16)*v46;
			*v46 = *(_WORD*)(dword_5d4594_3804672 +
							 2 * (unsigned __int8)(((*(_DWORD*)&byte_5D4594[3804364] & v58) >> byte_5D4594[3804376]) +
												   ((v71 - (unsigned __int8)((*(_DWORD*)&byte_5D4594[3804364] & v58) >>
																			 byte_5D4594[3804376])) >>
													2))) |
				   *(_WORD*)(dword_5d4594_3804656 +
							 2 * (unsigned __int8)(((*(_DWORD*)&byte_5D4594[3804368] & v58) >> byte_5D4594[3804380]) +
												   ((v76 - (unsigned __int8)((*(_DWORD*)&byte_5D4594[3804368] & v58) >>
																			 byte_5D4594[3804380])) >>
													2))) |
				   *(_WORD*)(dword_5d4594_3804664 +
							 2 * (unsigned __int8)(((*(_BYTE*)v46 & v5) << v8) +
												   ((v80 - (unsigned __int8)((*(_BYTE*)v46 & v5) << v8)) >> 2)));
		}
		v13 = a1;
	}
	result = a3;
	if (a3 > 0) {
		v59 = a3 + a2;
		v15 = a2;
		v82 = a1 - a3;
		v72 = 2 * v61;
		v69 = 4 * v15;
		v83 = v13;
		v62 = 2 * v13;
		v47 = 4 * v67;
		v64 = 2 * v63;
		v16 = 2 * v13;
		v17 = v15 - v13;
		v18 = v13 - v15;
		v70 = v15;
		v74 = v16;
		v68 = v17;
		for (i = v18;; v18 = i) {
			if (v65 >= 0) {
				v65 += v66;
				v66 += 4;
				--v79;
				v64 -= 2;
				v47 += 4;
				v72 += 2;
				++v82;
				v19 = --v59;
			} else {
				v65 += v75;
				v19 = v59;
				v66 += 2;
			}
			v75 += 2;
			++v78;
			v62 += 2;
			v69 -= 4;
			v20 = v70 + 1;
			v70 = v20;
			v74 -= 2;
			v21 = v18 + v20;
			--v83;
			v77 = v21;
			if (v21 >= v60 && v21 < v48 && v19 >= v49 && v19 < v50) {
				v22 = (_WORD*)(v62 + (_DWORD)nox_pixbuffer_rows_3798784[v19]);
				v23 = (unsigned __int16)*v22;
				*v22 =
					*(_WORD*)(dword_5d4594_3804672 +
							  2 * (unsigned __int8)(((*(_DWORD*)&byte_5D4594[3804364] & v23) >> byte_5D4594[3804376]) +
													((v4 - (unsigned __int8)((*(_DWORD*)&byte_5D4594[3804364] & v23) >>
																			 byte_5D4594[3804376])) >>
													 2))) |
					*(_WORD*)(dword_5d4594_3804656 +
							  2 * (unsigned __int8)(((*(_DWORD*)&byte_5D4594[3804368] & v23) >> byte_5D4594[3804380]) +
													((v6 - (unsigned __int8)((*(_DWORD*)&byte_5D4594[3804368] & v23) >>
																			 byte_5D4594[3804380])) >>
													 2))) |
					*(_WORD*)(dword_5d4594_3804664 +
							  2 * (unsigned __int8)((((unsigned __int8)*v22 & byte_5D4594[3804372])
													 << byte_5D4594[3804384]) +
													((v9 -
													  (unsigned __int8)(((unsigned __int8)*v22 & byte_5D4594[3804372])
																		<< byte_5D4594[3804384])) >>
													 2)));
				v21 = v77;
			}
			v24 = v59 + i;
			if (v59 + i >= v60) {
				if (v24 < v48 && v70 >= v49 && v70 < v50) {
					v25 = (_WORD*)(v64 + (_DWORD)nox_pixbuffer_rows_3798784[v70]);
					v26 = (unsigned __int16)*v25;
					v24 = v59 + i;
					*v25 =
						*(_WORD*)(dword_5d4594_3804672 +
								  2 * (unsigned __int8)(((*(_DWORD*)&byte_5D4594[3804364] & v26) >>
														 byte_5D4594[3804376]) +
														((v4 -
														  (unsigned __int8)((*(_DWORD*)&byte_5D4594[3804364] & v26) >>
																			byte_5D4594[3804376])) >>
														 2))) |
						*(_WORD*)(dword_5d4594_3804656 +
								  2 * (unsigned __int8)(((*(_DWORD*)&byte_5D4594[3804368] & v26) >>
														 byte_5D4594[3804380]) +
														((v6 -
														  (unsigned __int8)((*(_DWORD*)&byte_5D4594[3804368] & v26) >>
																			byte_5D4594[3804380])) >>
														 2))) |
						*(_WORD*)(dword_5d4594_3804664 +
								  2 * (unsigned __int8)((((unsigned __int8)*v25 & byte_5D4594[3804372])
														 << byte_5D4594[3804384]) +
														((v9 - (unsigned __int8)(((unsigned __int8)*v25 &
																				  byte_5D4594[3804372])
																				 << byte_5D4594[3804384])) >>
														 2)));
					v21 = v77;
				}
				if (v24 >= v60 && v24 < v48 && v68 + v83 >= v49 && v68 + v83 < v50) {
					v27 = (_WORD*)(v64 + (_DWORD)nox_pixbuffer_rows_3798784[v69/4]);
					v28 = (unsigned __int16)*v27;
					*v27 =
						*(_WORD*)(dword_5d4594_3804672 +
								  2 * (unsigned __int8)(((*(_DWORD*)&byte_5D4594[3804364] & v28) >>
														 byte_5D4594[3804376]) +
														((v4 -
														  (unsigned __int8)((*(_DWORD*)&byte_5D4594[3804364] & v28) >>
																			byte_5D4594[3804376])) >>
														 2))) |
						*(_WORD*)(dword_5d4594_3804656 +
								  2 * (unsigned __int8)(((*(_DWORD*)&byte_5D4594[3804368] & v28) >>
														 byte_5D4594[3804380]) +
														((v6 -
														  (unsigned __int8)((*(_DWORD*)&byte_5D4594[3804368] & v28) >>
																			byte_5D4594[3804380])) >>
														 2))) |
						*(_WORD*)(dword_5d4594_3804664 +
								  2 * (unsigned __int8)((((unsigned __int8)*v27 & byte_5D4594[3804372])
														 << byte_5D4594[3804384]) +
														((v9 - (unsigned __int8)(((unsigned __int8)*v27 &
																				  byte_5D4594[3804372])
																				 << byte_5D4594[3804384])) >>
														 2)));
					v21 = v77;
				}
			}
			if (v21 >= v60 && v21 < v48 && v68 + v82 >= v49 && v68 + v82 < v50) {
				v29 = (_WORD*)(v62 + (_DWORD)nox_pixbuffer_rows_3798784[v47/4]);
				v30 = (unsigned __int16)*v29;
				*v29 =
					*(_WORD*)(dword_5d4594_3804672 +
							  2 * (unsigned __int8)(((*(_DWORD*)&byte_5D4594[3804364] & v30) >> byte_5D4594[3804376]) +
													((v4 - (unsigned __int8)((*(_DWORD*)&byte_5D4594[3804364] & v30) >>
																			 byte_5D4594[3804376])) >>
													 2))) |
					*(_WORD*)(dword_5d4594_3804656 +
							  2 * (unsigned __int8)(((*(_DWORD*)&byte_5D4594[3804368] & v30) >> byte_5D4594[3804380]) +
													((v6 - (unsigned __int8)((*(_DWORD*)&byte_5D4594[3804368] & v30) >>
																			 byte_5D4594[3804380])) >>
													 2))) |
					*(_WORD*)(dword_5d4594_3804664 +
							  2 * (unsigned __int8)((((unsigned __int8)*v29 & byte_5D4594[3804372])
													 << byte_5D4594[3804384]) +
													((v9 -
													  (unsigned __int8)(((unsigned __int8)*v29 & byte_5D4594[3804372])
																		<< byte_5D4594[3804384])) >>
													 2)));
			}
			if (v83 >= v60 && v83 < v48 && v68 + v82 >= v49 && v68 + v82 < v50) {
				v31 = (_WORD*)(v74 + (_DWORD)nox_pixbuffer_rows_3798784[v47/4]);
				v32 = (unsigned __int16)*v31;
				*v31 =
					*(_WORD*)(dword_5d4594_3804672 +
							  2 * (unsigned __int8)(((*(_DWORD*)&byte_5D4594[3804364] & v32) >> byte_5D4594[3804376]) +
													((v4 - (unsigned __int8)((*(_DWORD*)&byte_5D4594[3804364] & v32) >>
																			 byte_5D4594[3804376])) >>
													 2))) |
					*(_WORD*)(dword_5d4594_3804656 +
							  2 * (unsigned __int8)(((*(_DWORD*)&byte_5D4594[3804368] & v32) >> byte_5D4594[3804380]) +
													((v6 - (unsigned __int8)((*(_DWORD*)&byte_5D4594[3804368] & v32) >>
																			 byte_5D4594[3804380])) >>
													 2))) |
					*(_WORD*)(dword_5d4594_3804664 +
							  2 * (unsigned __int8)((((unsigned __int8)*v31 & byte_5D4594[3804372])
													 << byte_5D4594[3804384]) +
													((v9 -
													  (unsigned __int8)(((unsigned __int8)*v31 & byte_5D4594[3804372])
																		<< byte_5D4594[3804384])) >>
													 2)));
			}
			if (v82 >= v60) {
				if (v82 < v48 && v68 + v83 >= v49 && v68 + v83 < v50) {
					v33 = (_WORD*)(v72 + (_DWORD)nox_pixbuffer_rows_3798784[v69/4]);
					v34 = (unsigned __int16)*v33;
					*v33 =
						*(_WORD*)(dword_5d4594_3804672 +
								  2 * (unsigned __int8)(((*(_DWORD*)&byte_5D4594[3804364] & v34) >>
														 byte_5D4594[3804376]) +
														((v4 -
														  (unsigned __int8)((*(_DWORD*)&byte_5D4594[3804364] & v34) >>
																			byte_5D4594[3804376])) >>
														 2))) |
						*(_WORD*)(dword_5d4594_3804656 +
								  2 * (unsigned __int8)(((*(_DWORD*)&byte_5D4594[3804368] & v34) >>
														 byte_5D4594[3804380]) +
														((v6 -
														  (unsigned __int8)((*(_DWORD*)&byte_5D4594[3804368] & v34) >>
																			byte_5D4594[3804380])) >>
														 2))) |
						*(_WORD*)(dword_5d4594_3804664 +
								  2 * (unsigned __int8)((((unsigned __int8)*v33 & byte_5D4594[3804372])
														 << byte_5D4594[3804384]) +
														((v9 - (unsigned __int8)(((unsigned __int8)*v33 &
																				  byte_5D4594[3804372])
																				 << byte_5D4594[3804384])) >>
														 2)));
				}
				if (v82 < v48 && v70 >= v49 && v70 < v50) {
					v35 = (_WORD*)(v72 + (_DWORD)nox_pixbuffer_rows_3798784[v70]);
					v36 = (unsigned __int16)*v35;
					*v35 =
						*(_WORD*)(dword_5d4594_3804672 +
								  2 * (unsigned __int8)(((*(_DWORD*)&byte_5D4594[3804364] & v36) >>
														 byte_5D4594[3804376]) +
														((v4 -
														  (unsigned __int8)((*(_DWORD*)&byte_5D4594[3804364] & v36) >>
																			byte_5D4594[3804376])) >>
														 2))) |
						*(_WORD*)(dword_5d4594_3804656 +
								  2 * (unsigned __int8)(((*(_DWORD*)&byte_5D4594[3804368] & v36) >>
														 byte_5D4594[3804380]) +
														((v6 -
														  (unsigned __int8)((*(_DWORD*)&byte_5D4594[3804368] & v36) >>
																			byte_5D4594[3804380])) >>
														 2))) |
						*(_WORD*)(dword_5d4594_3804664 +
								  2 * (unsigned __int8)((((unsigned __int8)*v35 & byte_5D4594[3804372])
														 << byte_5D4594[3804384]) +
														((v9 - (unsigned __int8)(((unsigned __int8)*v35 &
																				  byte_5D4594[3804372])
																				 << byte_5D4594[3804384])) >>
														 2)));
				}
			}
			if (v83 >= v60 && v83 < v48 && v59 >= v49 && v59 < v50) {
				v37 = (_WORD*)(v74 + (_DWORD)nox_pixbuffer_rows_3798784[v59]);
				v38 = (unsigned __int16)*v37;
				*v37 =
					*(_WORD*)(dword_5d4594_3804672 +
							  2 * (unsigned __int8)(((*(_DWORD*)&byte_5D4594[3804364] & v38) >> byte_5D4594[3804376]) +
													((v4 - (unsigned __int8)((*(_DWORD*)&byte_5D4594[3804364] & v38) >>
																			 byte_5D4594[3804376])) >>
													 2))) |
					*(_WORD*)(dword_5d4594_3804656 +
							  2 * (unsigned __int8)(((*(_DWORD*)&byte_5D4594[3804368] & v38) >> byte_5D4594[3804380]) +
													((v6 - (unsigned __int8)((*(_DWORD*)&byte_5D4594[3804368] & v38) >>
																			 byte_5D4594[3804380])) >>
													 2))) |
					*(_WORD*)(dword_5d4594_3804664 +
							  2 * (unsigned __int8)((((unsigned __int8)*v37 & byte_5D4594[3804372])
													 << byte_5D4594[3804384]) +
													((v9 -
													  (unsigned __int8)(((unsigned __int8)*v37 & byte_5D4594[3804372])
																		<< byte_5D4594[3804384])) >>
													 2)));
			}
			result = v79;
			if (v79 <= v78)
				break;
		}
	}
	return result;
}

//----- (004B4860) --------------------------------------------------------
int __cdecl sub_4B4860(int a1, int a2, int a3, int a4) {
	int v4;     // edi
	int v5;     // eax
	int result; // eax
	int v7;     // eax
	int v8;     // eax
	int v9;     // ebx
	int v10;    // edi
	int v11;    // eax
	int v12;    // eax
	int v13;    // eax
	int v14;    // eax

	v4 = *(_DWORD*)(a1 + 32);
	switch (a2) {
	case 5:
		goto LABEL_22;
	case 6:
	case 7:
		v9 = a3;
		v10 = (unsigned __int16)a3;
		nox_client_wndGetPosition_46AA60((_DWORD*)a1, &a4, &a3);
		if (v10 > *(int*)(a1 + 8) + a4 - 10)
			v10 = *(_DWORD*)(a1 + 8) + a4 - 10;
		nox_wnd_sub_46A9B0(*(_DWORD**)(a1 + 400), v10 - a4 - 5, 0);
		nox_window_call_field_94(a1, 0x4000, 0, v9);
		return 1;
	case 8:
		v8 = *(_DWORD*)(a1 + 44);
		if (!(v8 & 0x100))
			goto LABEL_22;
		nox_window_call_field_94(*(_DWORD*)(a1 + 52), 0x4000, a1, 0);
		result = 1;
		break;
	case 17:
		v5 = *(_DWORD*)(a1 + 44);
		if (!(v5 & 0x100))
			goto LABEL_22;
		sub_46AFE0(a1, *(_DWORD*)(a1 + 72));
		nox_window_call_field_94(*(_DWORD*)(a1 + 52), 16389, a1, 0);
		sub_46B500(a1);
		result = 1;
		break;
	case 18:
		v7 = *(_DWORD*)(a1 + 44);
		if (v7 & 0x100) {
			sub_46AFE0(a1, *(_DWORD*)(a1 + 64));
			nox_window_call_field_94(*(_DWORD*)(a1 + 52), 16390, a1, 0);
			result = 1;
		} else {
		LABEL_22:
			result = 1;
		}
		break;
	case 21:
		switch (a3) {
		case 15:
		case 208:
			if (a4 != 2)
				goto LABEL_22;
			sub_46A8A0();
			result = 1;
			break;
		case 200:
			if (a4 == 2)
				sub_46A8B0();
			goto LABEL_22;
		case 203:
			if (a4 != 2)
				goto LABEL_22;
			v13 = *(_DWORD*)(v4 + 12);
			if (v13 >= *(int*)(v4 + 4) - 1)
				goto LABEL_22;
			v14 = v13 + 2;
			*(_DWORD*)(v4 + 12) = v14;
			nox_window_call_field_94(*(_DWORD*)(a1 + 52), 16393, a1, v14);
			nox_wnd_sub_46A9B0(*(_DWORD**)(a1 + 400),
							   (__int64)((double)(int)(*(_DWORD*)(v4 + 12) - *(_DWORD*)v4) * *(float*)(v4 + 8)), 0);
			result = 1;
			break;
		case 205:
			if (a4 != 2)
				goto LABEL_22;
			v11 = *(_DWORD*)(v4 + 12);
			if (v11 <= *(int*)v4 + 1)
				goto LABEL_22;
			v12 = v11 - 2;
			*(_DWORD*)(v4 + 12) = v12;
			nox_window_call_field_94(*(_DWORD*)(a1 + 52), 16393, a1, v12);
			nox_wnd_sub_46A9B0(*(_DWORD**)(a1 + 400),
							   (__int64)((double)(int)(*(_DWORD*)(v4 + 12) - *(_DWORD*)v4) * *(float*)(v4 + 8)), 0);
			result = 1;
			break;
		default:
			goto LABEL_23;
		}
		break;
	default:
	LABEL_23:
		result = 0;
		break;
	}
	return result;
}

//----- (004B4BA0) --------------------------------------------------------
int __cdecl sub_4B4BA0(int a1, int a2, unsigned int a3, int a4) {
	int v4;         // edi
	int v5;         // eax
	int result;     // eax
	int v7;         // eax
	int v8;         // eax
	int v9;         // ebx
	signed int v10; // edi
	int v11;        // eax
	int v12;        // eax
	int v13;        // eax
	int v14;        // eax

	v4 = *(_DWORD*)(a1 + 32);
	switch (a2) {
	case 5:
		goto LABEL_22;
	case 6:
	case 7:
		v9 = a3;
		v10 = a3 >> 16;
		nox_client_wndGetPosition_46AA60((_DWORD*)a1, &a3, &a4);
		if (v10 > *(int*)(a1 + 12) + a4 - 10)
			v10 = *(_DWORD*)(a1 + 12) + a4 - 10;
		nox_wnd_sub_46A9B0(*(_DWORD**)(a1 + 400), 0, v10 - a4 - 5);
		nox_window_call_field_94(a1, 0x4000, 0, v9);
		return 1;
	case 8:
		v8 = *(_DWORD*)(a1 + 44);
		if (!(v8 & 0x100))
			goto LABEL_22;
		nox_window_call_field_94(*(_DWORD*)(a1 + 52), 0x4000, a1, 0);
		result = 1;
		break;
	case 17:
		v5 = *(_DWORD*)(a1 + 44);
		if (!(v5 & 0x100))
			goto LABEL_22;
		sub_46AFE0(a1, *(_DWORD*)(a1 + 72));
		nox_window_call_field_94(*(_DWORD*)(a1 + 52), 16389, a1, 0);
		sub_46B500(a1);
		result = 1;
		break;
	case 18:
		v7 = *(_DWORD*)(a1 + 44);
		if (v7 & 0x100) {
			sub_46AFE0(a1, *(_DWORD*)(a1 + 64));
			nox_window_call_field_94(*(_DWORD*)(a1 + 52), 16390, a1, 0);
			result = 1;
		} else {
		LABEL_22:
			result = 1;
		}
		break;
	case 21:
		switch (a3) {
		case 0xFu:
		case 0xCDu:
			if (a4 != 2)
				goto LABEL_22;
			sub_46A8A0();
			result = 1;
			break;
		case 0xC8u:
			if (a4 != 2)
				goto LABEL_22;
			v11 = *(_DWORD*)(v4 + 12);
			if (v11 >= *(int*)(v4 + 4) - 1)
				goto LABEL_22;
			v12 = v11 + 2;
			*(_DWORD*)(v4 + 12) = v12;
			nox_window_call_field_94(*(_DWORD*)(a1 + 52), 16393, a1, v12);
			nox_wnd_sub_46A9B0(*(_DWORD**)(a1 + 400), 0,
							   (__int64)((double)(int)(*(_DWORD*)(v4 + 4) - *(_DWORD*)(v4 + 12)) * *(float*)(v4 + 8)));
			result = 1;
			break;
		case 0xCBu:
			if (a4 == 2)
				sub_46A8B0();
			goto LABEL_22;
		case 0xD0u:
			if (a4 != 2)
				goto LABEL_22;
			v13 = *(_DWORD*)(v4 + 12);
			if (v13 <= *(int*)v4 + 1)
				goto LABEL_22;
			v14 = v13 - 2;
			*(_DWORD*)(v4 + 12) = v14;
			nox_window_call_field_94(*(_DWORD*)(a1 + 52), 16393, a1, v14);
			nox_wnd_sub_46A9B0(*(_DWORD**)(a1 + 400), 0,
							   (__int64)((double)(int)(*(_DWORD*)(v4 + 4) - *(_DWORD*)(v4 + 12)) * *(float*)(v4 + 8)));
			result = 1;
			break;
		default:
			goto LABEL_23;
		}
		break;
	default:
	LABEL_23:
		result = 0;
		break;
	}
	return result;
}

//----- (004B4EE0) --------------------------------------------------------
_DWORD* __cdecl sub_4B4EE0(int a1, int a2, int a3, int a4, int a5, int a6, _DWORD* a7, float* a8) {
	int v8;      // eax
	int v9;      // ebp
	_DWORD* v10; // edi
	int v11;     // eax
	double v12;  // st7
	float* v13;  // edx

	v8 = a7[2];
	if (v8 & 0x10) {
		v9 = a6;
		v10 = nox_window_new(a1, a2 | 0x100, a3, a4, a5, a6, sub_4B5010);
		sub_4B51A0((int)v10);
	} else {
		if (!(v8 & 8))
			return 0;
		v9 = a6;
		v10 = nox_window_new(a1, a2 | 0x100, a3, a4, a5, a6, sub_4B5320);
		sub_4B5500((int)v10);
	}
	if (v10) {
		if (!a7[4])
			a7[4] = v10;
		sub_46AF80_copy_window_part((int)v10, a7);
		sub_4B5640((int)v10, a2 | 0x100, (int)a7);
		v11 = *(_DWORD*)a8;
		if (*((_DWORD*)a8 + 1) == *(_DWORD*)a8)
			*((_DWORD*)a8 + 1) = v11 + 1;
		if (a7[2] & 0x10)
			v12 = (double)(a5 - 10) / (double)(int)(*((_DWORD*)a8 + 1) - v11);
		else
			v12 = (double)(v9 - 10) / (double)(int)(*((_DWORD*)a8 + 1) - v11);
		a8[2] = v12;
		v13 = (float*)nox_malloc(0x10u);
		*v13 = *a8;
		v13[1] = a8[1];
		v13[2] = a8[2];
		v13[3] = a8[3];
		v10[8] = v13;
	}
	return v10;
}

//----- (004B5010) --------------------------------------------------------
int __cdecl sub_4B5010(int a1, unsigned int a2, int a3, int a4) {
	int v4;      // edi
	int v5;      // esi
	int v6;      // esi
	int v7;      // eax
	int v8;      // eax
	int v10;     // ebx
	int v11;     // ecx
	int v12;     // eax
	__int64 v13; // rax
	int v14;     // ecx
	int v15;     // eax
	int v16;     // edx
	double v17;  // st7
	int* v18;    // [esp-4h] [ebp-Ch]

	v4 = a1;
	v5 = *(_DWORD*)(a1 + 32);
	if (a2 > 0x4000) {
		if (a2 == 16394) {
			if (a3 >= *(int*)v5 && a3 <= *(int*)(v5 + 4)) {
				v17 = (double)a3;
				*(_DWORD*)(v5 + 12) = a3;
				nox_wnd_sub_46A9B0(*(_DWORD**)(v4 + 400), (__int64)(v17 * *(float*)(v5 + 8)), 0);
			}
		} else if (a2 == 16395) {
			v14 = a3;
			v15 = a4;
			*(_DWORD*)v5 = a3;
			*(_DWORD*)(v5 + 4) = v15;
			v16 = *(_DWORD*)(v4 + 8) - 10;
			*(_DWORD*)(v5 + 12) = v14;
			a3 = v15 - v14;
			*(float*)(v5 + 8) = (double)v16 / (double)(v15 - v14);
			nox_wnd_sub_46A9B0(*(_DWORD**)(v4 + 400), 0, 0);
			return 0;
		}
		return 0;
	}
	if (a2 == 0x4000) {
		v10 = (unsigned __int16)a4;
		nox_client_wndGetPosition_46AA60((_DWORD*)a1, &a3, &a1);
		if (v10 < a3) {
			nox_wnd_sub_46A9B0(*(_DWORD**)(v4 + 400), 0, 0);
			v11 = *(_DWORD*)v5;
		LABEL_15:
			*(_DWORD*)(v5 + 12) = v11;
			goto LABEL_16;
		}
		v12 = *(_DWORD*)(v4 + 8);
		if (v10 < v12 + a3) {
			a4 = v10 - a3;
			v13 = (__int64)((double)(v10 - a3) / *(float*)(v5 + 8));
			v11 = *(_DWORD*)(v5 + 4);
			*(_DWORD*)(v5 + 12) = v13;
			if ((int)v13 > v11)
				goto LABEL_15;
		} else {
			nox_wnd_sub_46A9B0(*(_DWORD**)(v4 + 400), v12 - *(_DWORD*)(*(_DWORD*)(v4 + 400) + 8), 0);
			*(_DWORD*)(v5 + 12) = *(_DWORD*)(v5 + 4);
		}
	LABEL_16:
		nox_window_call_field_94(*(_DWORD*)(v4 + 52), 16393, v4, *(_DWORD*)(v5 + 12));
		return 0;
	}
	if (a2 == 2) {
		free(*(LPVOID*)(a1 + 32));
		return 0;
	}
	if (a2 != 23)
		return 0;
	v6 = a3;
	v7 = *(_DWORD*)(a1 + 36);
	if (a3)
		LOBYTE(v7) = v7 | 2;
	else
		LOBYTE(v7) = v7 & 0xFD;
	v18 = (int*)a1;
	*(_DWORD*)(a1 + 36) = v7;
	v8 = sub_46B0A0(v18);
	nox_window_call_field_94(*(_DWORD*)(v4 + 52), 16387, v6, v8);
	return 1;
}

//----- (004B51A0) --------------------------------------------------------
int __cdecl sub_4B51A0(int a1) {
	int result; // eax

	result = a1;
	if (a1) {
		if ((signed char)*(_BYTE*)(a1 + 4) >= 0)
			result = nox_window_set_all_funcs((_DWORD*)a1, sub_4B4860, sub_4B51E0, 0);
		else
			result = nox_window_set_all_funcs((_DWORD*)a1, sub_4B4860, sub_4B52C0, 0);
	}
	return result;
}

//----- (004B51E0) --------------------------------------------------------
int __cdecl sub_4B51E0(int a1, int a2) {
	int v2;    // ebp
	int v3;    // ebx
	int v4;    // edi
	int xLeft; // [esp+10h] [ebp-8h]
	int yTop;  // [esp+14h] [ebp-4h]

	v2 = *(_DWORD*)(a2 + 28);
	v3 = *(_DWORD*)(a2 + 20);
	nox_client_wndGetPosition_46AA60((_DWORD*)a1, &xLeft, &yTop);
	if (*(_BYTE*)(a1 + 4) & 8) {
		if (*(_BYTE*)a2 & 2 && *(_DWORD*)(a2 + 36) != 0x80000000) {
			nox_client_drawSetColor_434460(*(_DWORD*)(a2 + 36));
			nox_client_drawBorderLines_49CC70(xLeft, yTop, *(_DWORD*)(a1 + 8), *(_DWORD*)(a1 + 12));
		}
	} else {
		v3 = *(_DWORD*)(a2 + 44);
	}
	if (v3 != 0x80000000) {
		nox_client_drawSetColor_434460(v3);
		nox_client_drawRectFilledOpaque_49CE30(xLeft + 1, yTop + 1, *(_DWORD*)(a1 + 8) - 2, *(_DWORD*)(a1 + 12) - 2);
	}
	v4 = yTop + *(_DWORD*)(a1 + 12) / 2;
	if (v2 != 0x80000000) {
		nox_client_drawSetColor_434460(v2);
		nox_client_drawRectFilledOpaque_49CE30(xLeft, v4 - 1, *(_DWORD*)(a1 + 8), 3);
	}
	return 1;
}

//----- (004B52C0) --------------------------------------------------------
int __cdecl sub_4B52C0(int a1, int a2) {
	int v2; // esi
	int v4; // [esp+Ch] [ebp-8h]
	int v5; // [esp+10h] [ebp-4h]

	v2 = *(_DWORD*)(a2 + 24);
	nox_client_wndGetPosition_46AA60((_DWORD*)a1, &v4, &v5);
	if (!(*(_BYTE*)(a1 + 4) & 8))
		v2 = *(_DWORD*)(a2 + 48);
	if (v2)
		nox_client_drawImageAt_47D2C0(v2, v4, v5);
	return 1;
}

//----- (004B5320) --------------------------------------------------------
int __cdecl sub_4B5320(int a1, unsigned int a2, int a3, unsigned int a4) {
	int v4;           // edi
	int v5;           // esi
	signed int v6;    // ebx
	int v7;           // eax
	__int64 v8;       // rax
	int v9;           // ecx
	int v11;          // esi
	int v12;          // eax
	int v13;          // eax
	unsigned int v14; // eax
	int v15;          // ecx
	int v16;          // eax
	double v17;       // st7
	int v18;          // eax
	int v19;          // eax
	int* v20;         // [esp-4h] [ebp-Ch]

	v4 = a1;
	v5 = *(_DWORD*)(a1 + 32);
	if (a2 > 0x4007) {
		if (a2 == 16394) {
			if (a3 >= *(int*)v5) {
				v18 = *(_DWORD*)(v5 + 4);
				if (a3 <= v18) {
					v19 = v18 - a3;
					*(_DWORD*)(v5 + 12) = a3;
					a3 = v19;
					nox_wnd_sub_46A9B0(*(_DWORD**)(v4 + 400), 0, (__int64)((double)v19 * *(float*)(v5 + 8)));
				}
			}
		} else if (a2 == 16395) {
			v14 = a4;
			v15 = a3;
			*(_DWORD*)(v5 + 4) = a4;
			*(_DWORD*)v5 = v15;
			a3 = v14 - v15;
			v16 = *(_DWORD*)(v4 + 12);
			*(_DWORD*)(v5 + 12) = v15;
			v17 = (double)a3;
			a3 = v16 - 10;
			*(float*)(v5 + 8) = (double)(v16 - 10) / v17;
			nox_wnd_sub_46A9B0(*(_DWORD**)(v4 + 400), 0, (__int64)(v17 * *(float*)(v5 + 8)));
			return 0;
		}
		return 0;
	}
	switch (a2) {
	case 0x4007u:
		nox_window_call_field_94(*(_DWORD*)(a1 + 52), 16396, a1, *(_DWORD*)(v5 + 12));
		return 0;
	case 2u:
		free(*(LPVOID*)(a1 + 32));
		return 0;
	case 0x17u:
		v11 = a3;
		v12 = *(_DWORD*)(a1 + 36);
		if (a3)
			LOBYTE(v12) = v12 | 2;
		else
			LOBYTE(v12) = v12 & 0xFD;
		v20 = (int*)a1;
		*(_DWORD*)(a1 + 36) = v12;
		v13 = sub_46B0A0(v20);
		nox_window_call_field_94(*(_DWORD*)(v4 + 52), 16387, v11, v13);
		return 1;
	}
	if (a2 != 0x4000)
		return 0;
	v6 = a4 >> 16;
	nox_client_wndGetPosition_46AA60((_DWORD*)a1, &a1, &a3);
	if (v6 >= a3) {
		v7 = *(_DWORD*)(v4 + 12);
		if (v6 < v7 + a3) {
			a4 = v6 - a3;
			v8 = (__int64)((double)(v6 - a3) / *(float*)(v5 + 8));
			v9 = *(_DWORD*)(v5 + 4);
			*(_DWORD*)(v5 + 12) = v8;
			if ((int)v8 > v9)
				*(_DWORD*)(v5 + 12) = v9;
			*(_DWORD*)(v5 + 12) = v9 - *(_DWORD*)(v5 + 12);
		} else {
			nox_wnd_sub_46A9B0(*(_DWORD**)(v4 + 400), 0, v7 - *(_DWORD*)(*(_DWORD*)(v4 + 400) + 12));
			*(_DWORD*)(v5 + 12) = *(_DWORD*)v5;
		}
	} else {
		nox_wnd_sub_46A9B0(*(_DWORD**)(v4 + 400), 0, 0);
		*(_DWORD*)(v5 + 12) = *(_DWORD*)(v5 + 4);
	}
	nox_window_call_field_94(*(_DWORD*)(v4 + 52), 16393, v4, *(_DWORD*)(v5 + 12));
	return 0;
}

//----- (004B5500) --------------------------------------------------------
int __cdecl sub_4B5500(int a1) {
	int result; // eax

	result = a1;
	if (a1) {
		if ((signed char)*(_BYTE*)(a1 + 4) >= 0)
			result = nox_window_set_all_funcs((_DWORD*)a1, sub_4B4BA0, sub_4B5540, 0);
		else
			result = nox_window_set_all_funcs((_DWORD*)a1, sub_4B4BA0, sub_4B5620, 0);
	}
	return result;
}

//----- (004B5540) --------------------------------------------------------
int __cdecl sub_4B5540(int a1, int a2) {
	int v2;    // ebx
	int v3;    // ebp
	int v4;    // edi
	int xLeft; // [esp+10h] [ebp-8h]
	int yTop;  // [esp+14h] [ebp-4h]

	v2 = *(_DWORD*)(a2 + 28);
	v3 = *(_DWORD*)(a2 + 20);
	nox_client_wndGetPosition_46AA60((_DWORD*)a1, &xLeft, &yTop);
	if (*(_BYTE*)(a1 + 4) & 8) {
		if (*(_BYTE*)a2 & 2) {
			v2 = *(_DWORD*)(a2 + 52);
			if (*(_DWORD*)(a2 + 36) != 0x80000000) {
				nox_client_drawSetColor_434460(*(_DWORD*)(a2 + 36));
				nox_client_drawBorderLines_49CC70(xLeft, yTop, *(_DWORD*)(a1 + 8), *(_DWORD*)(a1 + 12));
			}
		}
	} else {
		v3 = *(_DWORD*)(a2 + 44);
	}
	if (v3 != 0x80000000) {
		nox_client_drawSetColor_434460(v3);
		nox_client_drawRectFilledOpaque_49CE30(xLeft + 1, yTop + 1, *(_DWORD*)(a1 + 8) - 2, *(_DWORD*)(a1 + 12) - 2);
	}
	v4 = xLeft + *(_DWORD*)(a1 + 8) / 2;
	if (v2 != 0x80000000) {
		nox_client_drawSetColor_434460(v2);
		nox_client_drawRectFilledOpaque_49CE30(v4 - 1, yTop + 4, 3, *(_DWORD*)(a1 + 12) - 8);
	}
	return 1;
}

//----- (004B5620) --------------------------------------------------------
int __cdecl sub_4B5620(_DWORD* a1, int a2) {
	int v2; // [esp+0h] [ebp-8h]
	int v3; // [esp+4h] [ebp-4h]

	nox_client_wndGetPosition_46AA60(a1, &v2, &v3);
	return 1;
}

//----- (004B5640) --------------------------------------------------------
int __cdecl sub_4B5640(int a1, int a2, int a3) {
	int v3;       // esi
	int v4;       // eax
	int result;   // eax
	char v6[332]; // [esp+Ch] [ebp-14Ch]

	v3 = *(_DWORD*)(a3 + 68);
	*(_DWORD*)v6 = 0;
	memset(&v6[4], 0, 0x148u);
	v4 = a2;
	*(_DWORD*)&v6[16] = a1;
	LOBYTE(v4) = a2 & 0xEF | 0xC;
	*(_DWORD*)&v6[8] = 1;
	*(_DWORD*)&v6[68] = v3;
	if ((v4 & 0x80u) == 0) {
		*(_DWORD*)&v6[52] = *(_DWORD*)(a3 + 52);
		*(_DWORD*)&v6[28] = *(_DWORD*)(a3 + 20);
		*(_DWORD*)&v6[20] = *(_DWORD*)(a3 + 28);
	} else {
		*(_DWORD*)&v6[32] = *(_DWORD*)(a3 + 32);
		*(_DWORD*)&v6[48] = *(_DWORD*)(a3 + 48);
		*(_DWORD*)&v6[56] = *(_DWORD*)(a3 + 56);
		*(_DWORD*)&v6[24] = *(_DWORD*)(a3 + 24);
		*(_DWORD*)&v6[40] = *(_DWORD*)(a3 + 40);
	}
	if (*(_BYTE*)(a3 + 8) & 0x10)
		result = sub_4A91A0(a1, v4, 0, 0, 10, *(_DWORD*)(a1 + 12), v6);
	else
		result = sub_4A91A0(a1, v4, 0, 0, *(_DWORD*)(a1 + 8), 10, v6);
	return result;
}

//----- (004B5700) --------------------------------------------------------
void __cdecl sub_4B5700(int a1, int a2, int a3, int a4, int a5, int a6) {
	int v6; // eax
	int v7; // edx

	if (a1) {
		v6 = *(_DWORD*)(a1 + 400);
		v7 = *(_DWORD*)(v6 + 4);
		LOBYTE(v7) = v7 | 0x80;
		*(_DWORD*)(v6 + 4) = v7;
		sub_4A8340(*(_DWORD*)(a1 + 400));
		*(_DWORD*)(*(_DWORD*)(a1 + 400) + 60) = a2;
		*(_DWORD*)(*(_DWORD*)(a1 + 400) + 68) = a4;
		*(_DWORD*)(*(_DWORD*)(a1 + 400) + 84) = a3;
		*(_DWORD*)(*(_DWORD*)(a1 + 400) + 92) = a5;
		*(_DWORD*)(*(_DWORD*)(a1 + 400) + 76) = a6;
	}
}

//----- (004B5990) --------------------------------------------------------
void* sub_4B5990() {
	int v0;              // esi
	int v1;              // ecx
	unsigned __int8* v2; // eax
	int v3;              // edx
	void* result;        // eax
	__int16* v5;         // ecx
	__int16 v6[16];      // [esp+8h] [ebp-20h]

	v0 = 0;
	v6[0] = 0;
	memset(&v6[1], 0, 0x1Cu);
	v6[15] = 0;
	v1 = 0;
	dword_5d4594_1312472 = 0;
	if (!*(_DWORD*)&byte_587000[174360])
		return *(void**)&dword_5d4594_1312476;
	v2 = &byte_587000[174360];
	do {
		v3 = *((_DWORD*)v2 + 2);
		v2 += 8;
		++v1;
	} while (v3);
	dword_5d4594_1312472 = v1;
	if (v1 <= 0)
		return *(void**)&dword_5d4594_1312476;
	result = nox_malloc(4 * v1);
	dword_5d4594_1312476 = result;
	v5 = v6;
	if (dword_5d4594_1312472 > 0) {
		do {
			*(_DWORD*)(dword_5d4594_1312476 + 4 * v0) = sub_4B5A30_wol_locale((wchar_t*)v5);
			result = *(void**)&dword_5d4594_1312476;
			v5 = *(__int16**)(dword_5d4594_1312476 + 4 * v0++);
		} while (v0 < *(int*)&dword_5d4594_1312472);
	}
	return result;
}

//----- (004B5AB0) --------------------------------------------------------
int __cdecl sub_4B5AB0(int a1, int a2, int* a3, int a4) {
	int* v4;     // edi
	int v5;      // eax
	wchar_t* v6; // eax
	int v7;      // esi
	int v8;      // eax
	int v9;      // eax

	if (a2 != 16391)
		return 0;
	v4 = a3;
	if (sub_46B0A0(a3) != 1985)
		return 0;
	a2 = 0;
	v5 = nox_window_call_field_94(*(int*)&dword_5d4594_1312484, 16404, 0, 0);
	v6 = (wchar_t*)nox_window_call_field_94(*(int*)&dword_5d4594_1312484, 16406, v5, 0);
	v7 = sub_4B5B70_wol_locale(v6);
	v8 = sub_41FC40();
	sub_40DB50(v8 + 1, (int)&a2);
	if (v7 != a2) {
		v9 = sub_41FC40();
		sub_40DB80(v9 + 1, v7);
	}
	nox_window_call_field_94(*(int*)&byte_5D4594[1312488], 16391, (int)v4, a4);
	sub_4B5BF0();
	return 0;
}

//----- (004B5BF0) --------------------------------------------------------
void sub_4B5BF0() {
	sub_46C6E0(*(int*)&dword_5d4594_1312480);
	sub_46ADE0(*(int*)&dword_5d4594_1312480);
	sub_46C4E0(*(_DWORD**)&dword_5d4594_1312480);
	dword_5d4594_1312480 = 0;
	*(_DWORD*)&byte_5D4594[1312488] = 0;
	dword_5d4594_1312484 = 0;
	free(*(LPVOID*)&dword_5d4594_1312476);
	dword_5d4594_1312472 = 0;
}

//----- (004B5CD0) --------------------------------------------------------
int sub_4B5CD0() {
	char v0;             // si
	unsigned __int8* v1; // edi
	int v2;              // edi
	unsigned __int8* v3; // esi
	int v4;              // eax
	int v5;              // edx
	int v6;              // esi
	unsigned __int8* v7; // edi
	int v8;              // esi
	unsigned __int8* v9; // edi
	int result;          // eax
	int v12;             // [esp+8h] [ebp-4h]

	v0 = 0;
	v1 = &byte_5D4594[1312500];
	do {
		LOBYTE(v12) = v0 / 63;
		*(_DWORD*)v1 = sub_4344A0((unsigned __int8)(v0 / 63) / 3, 3 * (unsigned __int8)(v0 / 63) / 5, v12);
		v1 += 4;
		--v0;
	} while ((int)v1 < (int)&byte_5D4594[1312756]);
	v2 = 0;
	v3 = &byte_5D4594[1312756];
	do {
		LOBYTE(v12) = v2 / 32;
		v4 = sub_4344A0(v12, v12, 0);
		LOBYTE(v5) = -1 - v12;
		*(_DWORD*)v3 = v4;
		*((_DWORD*)v3 + 32) = sub_4344A0(255, v5, 0);
		v3 += 4;
		v2 += 255;
	} while ((int)v3 < (int)&byte_5D4594[1312884]);
	v6 = 0;
	v7 = &byte_5D4594[1313012];
	do {
		LOBYTE(v12) = v6 / 63;
		*(_DWORD*)v7 = sub_4344A0(v12, v12, v12);
		v7 += 4;
		v6 += 255;
	} while ((int)v7 < (int)&byte_5D4594[1313268]);
	v8 = 0;
	v9 = &byte_5D4594[1313268];
	do {
		result = sub_4344A0(v8 / 63, 50, 50);
		*(_DWORD*)v9 = result;
		v9 += 4;
		v8 += 255;
	} while ((int)v9 < (int)&byte_5D4594[1313524]);
	return result;
}
// 4B5D21: variable 'v12' is possibly undefined
// 4B5D71: variable 'v5' is possibly undefined

//----- (004B63B0) --------------------------------------------------------
int __cdecl sub_4B63B0(int2* a1, int2* a2) {
	int v2; // ebx
	int v3; // ebp

	nox_client_drawSetColor_434460(*(int*)&byte_5D4594[1312492]);
	nox_client_drawAddPoint_49F500(a1->field_0, a1->field_4);
	nox_client_drawAddPoint_49F500(a2->field_0, a2->field_4);
	nox_client_drawLineFromPoints_49E4B0();
	v2 = a2->field_0 - a1->field_0;
	v3 = a2->field_4 - a1->field_4;
	nox_client_drawSetColor_434460(*(int*)&byte_5D4594[1312496]);
	if (v2 < 0)
		v2 = -v2;
	if (v3 < 0)
		v3 = -v3;
	if (v2 <= v3) {
		nox_client_drawAddPoint_49F500(a1->field_0 - 1, a1->field_4);
		nox_client_drawAddPoint_49F500(a2->field_0 - 1, a2->field_4);
		nox_client_drawLineFromPoints_49E4B0();
		nox_client_drawAddPoint_49F500(a1->field_0 + 1, a1->field_4);
		nox_client_drawAddPoint_49F500(a2->field_0 + 1, a2->field_4);
	} else {
		nox_client_drawAddPoint_49F500(a1->field_0, a1->field_4 - 1);
		nox_client_drawAddPoint_49F500(a2->field_0, a2->field_4 - 1);
		nox_client_drawLineFromPoints_49E4B0();
		nox_client_drawAddPoint_49F500(a1->field_0, a1->field_4 + 1);
		nox_client_drawAddPoint_49F500(a2->field_0, a2->field_4 + 1);
	}
	return nox_client_drawLineFromPoints_49E4B0();
}

//----- (004B64C0) --------------------------------------------------------
int sub_4B64C0() {
	unsigned __int8 v0;  // bl
	unsigned __int8* v1; // esi
	int v2;              // ebp
	int v3;              // edi
	int v5;              // [esp+10h] [ebp-10h]
	int v6;              // [esp+14h] [ebp-Ch]
	int v7;              // [esp+18h] [ebp-8h]
	int v8;              // [esp+1Ch] [ebp-4h]

	*(_DWORD*)&byte_5D4594[1313524] = sub_4344A0(255, 255, 0);
	*(_DWORD*)&byte_5D4594[1313528] = sub_4344A0(255, 100, 0);
	dword_5d4594_1313532 = sub_4344A0(255, 255, 0);
	dword_5d4594_1313536 = sub_4344A0(0, 0, 255);
	dword_5d4594_1313540 = sub_4344A0(0, 200, 255);
	*(_DWORD*)&byte_5D4594[1313544] = sub_4344A0(0, 200, 200);
	*(_DWORD*)&byte_5D4594[1313548] = sub_4344A0(50, 255, 255);
	*(_DWORD*)&byte_5D4594[1313552] = sub_4344A0(255, 0, 255);
	*(_DWORD*)&byte_5D4594[1313556] = sub_4344A0(255, 200, 255);
	*(_DWORD*)&byte_5D4594[1313560] = sub_4344A0(255, 200, 0);
	dword_5d4594_1313564 = sub_4344A0(255, 255, 100);
	*(_DWORD*)&byte_5D4594[1313568] = sub_4344A0(100, 255, 50);
	*(_DWORD*)&byte_5D4594[1313572] = sub_4344A0(150, 255, 150);
	*(_DWORD*)&byte_5D4594[1313576] = sub_4344A0(255, 255, 0);
	*(_DWORD*)&byte_5D4594[1313580] = sub_4344A0(0, 220, 0);
	*(_DWORD*)&byte_5D4594[1313584] = sub_4344A0(150, 255, 150);
	*(_DWORD*)&byte_5D4594[1313588] = sub_4344A0(200, 200, 200);
	*(_DWORD*)&byte_5D4594[1313592] = sub_4344A0(255, 255, 255);
	LOBYTE(v8) = -1;
	LOBYTE(v7) = -1;
	LOBYTE(v6) = -1;
	v0 = 0;
	v1 = &byte_5D4594[1313656];
	v2 = 1085;
	v5 = 600;
	v3 = 765;
	do {
		if (v0 > 3u) {
			if (v0 > 7u)
				LOBYTE(v8) = v2 / 9 - 1;
			else
				LOBYTE(v7) = v5 / 4 - 1;
		} else {
			LOBYTE(v6) = v3 / 3;
		}
		*(_DWORD*)v1 = sub_4344A0(v8, v7, v6);
		++v0;
		v3 -= 255;
		v2 -= 155;
		v1 -= 4;
		v5 -= 200;
	} while (v0 < 0x10u);
	return sub_4B5CD0();
}
// 4B66DF: variable 'v8' is possibly undefined
// 4B66DF: variable 'v7' is possibly undefined
// 4B66DF: variable 'v6' is possibly undefined

//----- (004B6720) --------------------------------------------------------
void __cdecl sub_4B6720(int2* a1, int a2, int a3, char a4) {
	int* v4; // eax

	if (nox_client_renderGlow_805852) {
		sub_434040(a2);
		sub_434080(a3 + 4);
		v4 = sub_4B0680(0, 32 * a4);
		sub_4B0820((int)v4, a1->field_0, a1->field_4);
	}
}

//----- (004B6880) --------------------------------------------------------
int __cdecl sub_4B6880(_DWORD* a1, int a2, int a3, int a4) {
	int v4;     // edx
	int v5;     // ebx
	int v6;     // eax
	int result; // eax
	int v8;     // ecx
	int v9;     // eax
	int v10;    // edx
	int v11;    // eax
	bool v12;   // cc
	int v13;    // esi
	int2 xLeft; // [esp+Ch] [ebp-8h]
	int v15;    // [esp+1Ch] [ebp+8h]

	v4 = a2;
	v5 = *(_DWORD*)(a2 + 448) - *(_DWORD*)(a2 + 444);
	v15 = *(_DWORD*)(a2 + 448) - *(_DWORD*)&byte_5D4594[2598000];
	v6 = v15;
	if (v15 == v5)
		v6 = --v15;
	if (v6 > 0) {
		v8 = *a1 + *(_DWORD*)(v4 + 12) - a1[4];
		v9 = *(_DWORD*)(v4 + 16) - *(__int16*)(v4 + 106) - *(__int16*)(v4 + 104) - a1[5];
		v10 = a1[1];
		v11 = v10 + v9;
		v12 = v8 - 10 < *a1;
		xLeft.field_0 = v8;
		xLeft.field_4 = v11;
		if (!v12 && v11 - 10 >= v10 && v8 + 10 < a1[2] && v11 + 10 < a1[3]) {
			v13 = 4 * v15 / v5;
			sub_4B6720(&xLeft, a4, 2 * v13 + 1, 5 * v15 / v5);
			nox_client_drawSetColor_434460(a3);
			sub_499B70(xLeft.field_0, xLeft.field_4, v13);
		}
		result = 1;
	} else {
		sub_45A4E0_drawable(v4);
		result = 0;
	}
	return result;
}

//----- (004B6970) --------------------------------------------------------
int __cdecl sub_4B6970(_DWORD* a1, nox_drawable* dr, int a3, int a4) {
	int v4; // eax
	int v5; // eax

	int a2 = dr;

	v4 = *(_DWORD*)(a2 + 440);
	*(_DWORD*)(a2 + 432) += v4 * *(int*)&byte_587000[8 * *(unsigned __int8*)(a2 + 299) + 192088];
	v5 = v4 * *(int*)&byte_587000[8 * *(unsigned __int8*)(a2 + 299) + 192092] + *(_DWORD*)(a2 + 436);
	*(_DWORD*)(a2 + 436) = v5;
	sub_49AA90((_DWORD*)a2, *(_DWORD*)(a2 + 432) >> 12, v5 >> 12);
	sub_4B69F0(a2);
	return sub_4B6880(a1, a2, a3, a4);
}

//----- (004B69F0) --------------------------------------------------------
__int16 __cdecl sub_4B69F0(int a1) {
	char v1;        // cl
	__int16 result; // ax
	int v3;         // edx

	v1 = *(_BYTE*)(a1 + 296);
	*(_WORD*)(a1 + 104) += v1;
	result = *(_WORD*)(a1 + 104);
	if (result >= 0) {
		if (byte_5D4594[2598000] & 1)
			*(_BYTE*)(a1 + 296) = v1 - 1;
	} else {
		*(_WORD*)(a1 + 104) = -result;
		result = 26209 * v1;
		v3 = -9 * v1 / 10;
		*(_BYTE*)(a1 + 296) = v3;
		if ((char)v3 < 2) {
			*(_WORD*)(a1 + 104) = 0;
			*(_BYTE*)(a1 + 296) = 0;
		}
	}
	return result;
}

//----- (004B6B80) --------------------------------------------------------
int __cdecl sub_4B6B80(int* a1, nox_drawable* dr, int a3) {
	int v3;     // esi
	int v4;     // eax
	int v5;     // ecx
	int v6;     // edi
	int v7;     // ebx
	int v8;     // eax
	int v10;    // edi
	int v11;    // ebp
	int v12;    // edx
	int v13;    // edx
	int v14;    // edi
	int v15;    // ebx
	char v16;   // al
	char v17;   // cl
	char v18;   // al
	int v19;    // [esp+10h] [ebp-Ch]
	int2 xLeft; // [esp+14h] [ebp-8h]
	int v21;    // [esp+24h] [ebp+8h]

	int a2 = dr;

	v3 = a2;
	if (!*(_DWORD*)&byte_5D4594[1313660]) {
		*(_DWORD*)&byte_5D4594[1313660] = sub_44CFC0((CHAR*)&byte_587000[176016]);
		*(_DWORD*)&byte_5D4594[1313664] = sub_44CFC0((CHAR*)&byte_587000[176032]);
		*(_DWORD*)&byte_5D4594[1313668] = sub_44CFC0((CHAR*)&byte_587000[176040]);
		*(_DWORD*)&byte_5D4594[1313672] = sub_44CFC0((CHAR*)&byte_587000[176052]);
		*(_DWORD*)&byte_5D4594[1313676] = sub_44CFC0((CHAR*)&byte_587000[176064]);
		*(_DWORD*)&byte_5D4594[1313680] = sub_44CFC0((CHAR*)&byte_587000[176076]);
		*(_DWORD*)&byte_5D4594[1313684] = sub_44CFC0((CHAR*)&byte_587000[176092]);
	}
	v4 = *(_DWORD*)(a2 + 108);
	if (v4 == *(_DWORD*)&byte_5D4594[1313660] || v4 == *(_DWORD*)&byte_5D4594[1313684]) {
		v5 = dword_5d4594_1313540;
		v21 = dword_5d4594_1313536;
		goto LABEL_13;
	}
	if (v4 == *(_DWORD*)&byte_5D4594[1313668]) {
		v5 = *(_DWORD*)&byte_5D4594[1313584];
		v21 = *(_DWORD*)&byte_5D4594[1313580];
	LABEL_13:
		v19 = v5;
		goto LABEL_14;
	}
	if (v4 == *(_DWORD*)&byte_5D4594[1313672] || v4 == *(_DWORD*)&byte_5D4594[1313676] ||
		v4 == *(_DWORD*)&byte_5D4594[1313680]) {
		v21 = *(_DWORD*)&byte_5D4594[1313588];
		v19 = *(_DWORD*)&byte_5D4594[1313592];
	} else {
		v21 = *(_DWORD*)&byte_5D4594[1313528];
		v19 = dword_5d4594_1313532;
	}
LABEL_14:
	if (a3) {
		v6 = *(unsigned __int16*)(v3 + 432) - *(_DWORD*)(v3 + 12);
		v7 = *(unsigned __int16*)(v3 + 434) - *(_DWORD*)(v3 + 16);
		v8 = sub_48C6B0(v6, v7);
		if (v8 + 1 <= 10) {
			sub_45A4E0_drawable(v3);
			return 0;
		}
		sub_49AA90((_DWORD*)v3, *(_DWORD*)(v3 + 12) + v6 * *(unsigned __int8*)(v3 + 443) / (v8 + 1),
				   *(_DWORD*)(v3 + 16) + v7 * *(unsigned __int8*)(v3 + 443) / (v8 + 1));
	}
	v10 = *a1;
	v11 = a1[1];
	v12 = *(_DWORD*)(v3 + 16) - a1[5];
	xLeft.field_0 = *(_DWORD*)(v3 + 12) + *a1 - a1[4];
	xLeft.field_4 = v12 + v11 - 22;
	v13 = *(unsigned __int8*)(v3 + 444);
	if (xLeft.field_0 - v13 < v10)
		return 1;
	if (xLeft.field_4 - v13 < v11)
		return 1;
	if (v13 + xLeft.field_0 >= a1[2])
		return 1;
	if (v13 + xLeft.field_4 >= a1[3])
		return 1;
	sub_4B6720(&xLeft, v21, v13, 5);
	nox_client_drawSetColor_434460(v19);
	sub_499B70(xLeft.field_0, xLeft.field_4, *(unsigned __int8*)(v3 + 444) >> 1);
	v14 = *(_DWORD*)(v3 + 32) - *(_DWORD*)(v3 + 12);
	v15 = *(_DWORD*)(v3 + 36) - *(_DWORD*)(v3 + 16);
	nox_client_drawSetColor_434460(v19);
	nox_client_drawAddPoint_49F500(xLeft.field_0, xLeft.field_4);
	sub_49F570(v14, v15);
	nox_client_drawLineFromPoints_49E4B0();
	v16 = *(_BYTE*)(v3 + 445);
	if (!v16)
		return 1;
	v17 = *(_BYTE*)(v3 + 446) - 1;
	*(_BYTE*)(v3 + 446) = v17;
	if (v17)
		return 1;
	*(_BYTE*)(v3 + 446) = v16;
	v18 = *(_BYTE*)(v3 + 444) - 1;
	*(_BYTE*)(v3 + 444) = v18;
	if (v18)
		return 1;
	sub_45A4E0_drawable(v3);
	return 0;
}
// 4B6CB4: variable 'v8' is possibly undefined

//----- (004B71A0) --------------------------------------------------------
int __cdecl sub_4B71A0(_DWORD* a1, int a2) {
	int v2;     // edx
	int v3;     // ecx
	int v4;     // ebx
	int v5;     // ebx
	int v6;     // edi
	int result; // eax
	int v8;     // eax
	int v9;     // esi
	int v10;    // ebp
	int2 v11;   // [esp+10h] [ebp-8h]
	int v12;    // [esp+20h] [ebp+8h]

	v2 = *(_DWORD*)(a2 + 16);
	v3 = *(__int16*)(a2 + 106);
	v11.field_0 = *a1 + *(_DWORD*)(a2 + 12) - a1[4];
	v11.field_4 = a1[1] + v2 - v3 - *(__int16*)(a2 + 104) - a1[5];
	*(_DWORD*)(a2 + 432) += *(_DWORD*)(a2 + 440) * *(_DWORD*)&byte_587000[8 * *(unsigned __int8*)(a2 + 299) + 192088];
	v4 = *(_DWORD*)(a2 + 440) * *(_DWORD*)&byte_587000[8 * *(unsigned __int8*)(a2 + 299) + 192092] +
		 *(_DWORD*)(a2 + 436);
	*(_DWORD*)(a2 + 436) = v4;
	sub_49AA90((_DWORD*)a2, *(_DWORD*)(a2 + 432) >> 12, v4 >> 12);
	v5 = *(_DWORD*)(a2 + 444) - *(_DWORD*)(a2 + 448);
	v6 = *(_DWORD*)(a2 + 444) - *(_DWORD*)&byte_5D4594[2598000];
	if (v6 == v5)
		--v6;
	if (v6 > 0) {
		if (v11.field_0 - 10 >= *a1 && v11.field_4 - 10 >= a1[1] && v11.field_0 + 10 < a1[2] &&
			v11.field_4 + 10 < a1[3]) {
			sub_4B69F0(a2);
			v8 = 4 * (16 * v6 / v5);
			v12 = *(_DWORD*)&byte_5D4594[v8 + 1313596];
			v9 = v8 / 16;
			v10 = (v8 / 16) >> 1;
			sub_4B6720(&v11, *(_DWORD*)&byte_5D4594[v8 + 1313596], 2 * (v8 / 16) + 1, 5 * v6 / v5);
			nox_client_drawSetColor_434460(v12);
			nox_client_drawRectFilledOpaque_49CE30(v11.field_0 - v10, v11.field_4 - v10, v9, v9);
		}
		result = 1;
	} else {
		sub_45A4E0_drawable(a2);
		result = 0;
	}
	return result;
}

// 4B7BE5: variable 'v9' is possibly undefined

//----- (004B7C40) --------------------------------------------------------
_DWORD* __cdecl sub_4B7C40(__int16 a1, unsigned __int16* a2, unsigned __int16 a3, unsigned __int8 a4, __int16 a5) {
	int v5;         // eax
	_DWORD* result; // eax
	_DWORD* v7;     // edi
	_DWORD* v8;     // esi
	int v9;         // [esp-8h] [ebp-1Ch]
	int v10;        // [esp-4h] [ebp-18h]
	int v11;        // [esp+10h] [ebp-4h]

	v10 = a2[1];
	v9 = *a2;
	v5 = sub_44CFC0((CHAR*)&byte_587000[177024]);
	result = (_DWORD*)sub_45A360_drawable(v5, v9, v10);
	v7 = result;
	if (result) {
		result = nox_new_drawable_for_thing(a3);
		v8 = result;
		if (result) {
			result[3] = *a2;
			result[4] = a2[1];
			*((_BYTE*)result + 297) = sub_509EA0(a4);
			HIWORD(v11) = a1;
			LOWORD(v11) = a5;
			v8[69] = 8;
			v7[108] = v8;
			v7[109] = v11;
			result = *(_DWORD**)&byte_5D4594[2598000];
			v7[79] = *(_DWORD*)&byte_5D4594[2598000];
		}
	}
	return result;
}

//----- (004B7EE0) --------------------------------------------------------
void __cdecl sub_4B7EE0(__int16 a1) {
	if (!*(_DWORD*)&byte_5D4594[1313744])
		*(_DWORD*)&byte_5D4594[1313744] = sub_44CFC0((CHAR*)&byte_587000[177052]);
	if (!dword_5d4594_1313740)
		dword_5d4594_1313740 = sub_44CFC0((CHAR*)&byte_587000[177068]);

	int v2 = sub_45A060();
	if (!v2)
		return;

	while (*(_DWORD*)(v2 + 108) != *(_DWORD*)&byte_5D4594[1313744] || *(_WORD*)(v2 + 438) != a1) {
		v2 = sub_45A070(v2);
		if (!v2)
			return;
	}
	sub_499610(*(int*)&dword_5d4594_1313740, 50, 1000, 30, *(_DWORD*)(v2 + 12), *(_DWORD*)(v2 + 16));
	sub_45A4B0(*(_QWORD**)(v2 + 432));
	sub_45A4E0_drawable(v2);
}

//----- (004B7F90) --------------------------------------------------------
int sub_4B7F90() {
	int result; // eax

	*(_DWORD*)&byte_5D4594[1313748] = sub_44CFC0((CHAR*)&byte_587000[177080]);
	*(_DWORD*)&byte_5D4594[1313752] = sub_44CFC0((CHAR*)&byte_587000[177100]);
	*(_DWORD*)&byte_5D4594[1313756] = sub_44CFC0((CHAR*)&byte_587000[177120]);
	*(_DWORD*)&byte_5D4594[1313760] = sub_44CFC0((CHAR*)&byte_587000[177140]);
	*(_DWORD*)&byte_5D4594[1313768] = sub_44CFC0((CHAR*)&byte_587000[177160]);
	*(_DWORD*)&byte_5D4594[1313772] = sub_44CFC0((CHAR*)&byte_587000[177180]);
	*(_DWORD*)&byte_5D4594[1313776] = sub_44CFC0((CHAR*)&byte_587000[177200]);
	result = sub_44CFC0((CHAR*)&byte_587000[177220]);
	*(_DWORD*)&byte_5D4594[1313780] = result;
	*(_DWORD*)&byte_5D4594[1313764] = 0;
	*(_DWORD*)&byte_5D4594[1313784] = 1;
	return result;
}
// 4B8040: variable 'v3' is possibly undefined
// 4B804D: variable 'v5' is possibly undefined

//----- (004B8090) --------------------------------------------------------
_DWORD* __cdecl sub_4B8090(unsigned int a1, int a2) {
	int v2;         // edi
	int v3;         // eax
	_DWORD* result; // eax
	int v5;         // eax
	_DWORD* v6;     // esi
	int4 v7;        // [esp+0h] [ebp-10h]

	if (!*(_DWORD*)&byte_5D4594[1313784])
		sub_4B7F90();
	v2 = a2;
	switch (a2) {
	case 0:
		sub_44CFC0((CHAR*)&byte_587000[177380]);
		break;
	case 1:
		sub_44CFC0((CHAR*)&byte_587000[177240]);
		break;
	case 2:
		sub_44CFC0((CHAR*)&byte_587000[177260]);
		break;
	case 3:
		sub_44CFC0((CHAR*)&byte_587000[177360]);
		break;
	case 5:
		sub_44CFC0((CHAR*)&byte_587000[177280]);
		break;
	case 6:
		sub_44CFC0((CHAR*)&byte_587000[177340]);
		break;
	case 7:
		sub_44CFC0((CHAR*)&byte_587000[177320]);
		break;
	case 8:
		sub_44CFC0((CHAR*)&byte_587000[177300]);
		break;
	default:
		break;
	}
	if (sub_578B70(a1)) {
		v3 = sub_578B30(a1);
		result = sub_45A720(v3);
	} else {
		v5 = sub_578B30(a1);
		result = sub_45A6F0(v5);
	}
	v6 = result;
	if (result) {
		v7.field_0 = result[3] - 10;
		v7.field_4 = result[4] - 10;
		v7.field_8 = result[3] + 10;
		v7.field_C = result[4] + 10;
		dword_5d4594_1313788 = 0;
		sub_49AB00(&v7, sub_4B81E0, (int)&a1);
		result = *(_DWORD**)&dword_5d4594_1313788;
		if (dword_5d4594_1313788 != 1) {
			result = (_DWORD*)sub_45A360_drawable(*(_DWORD*)&byte_5D4594[4 * v2 + 1313748], v6[3], v6[4] + 3);
			if (result)
				result[108] = a1;
		}
	}
	return result;
}
// 4B810D: variable 'v3' is possibly undefined
// 4B811F: variable 'v5' is possibly undefined

//----- (004B81E0) --------------------------------------------------------
void __cdecl sub_4B81E0(int a1, int a2) {
	unsigned __int8* v2; // eax

	v2 = &byte_5D4594[1313748];
	do {
		if (*(_DWORD*)(a1 + 108) == *(_DWORD*)v2 && *(_DWORD*)(a1 + 432) == *(_DWORD*)a2)
			dword_5d4594_1313788 = 1;
		v2 += 4;
	} while ((int)v2 < (int)&byte_5D4594[1313784]);
}

//----- (004B8220) --------------------------------------------------------
int sub_4B8220() {
	int result; // eax

	if (dword_5d4594_1313792)
		sub_45A4B0(*(_QWORD**)&dword_5d4594_1313792);
	dword_5d4594_1313792 = 0;
	if (dword_5d4594_1313796)
		sub_45A4B0(*(_QWORD**)&dword_5d4594_1313796);
	result = dword_5d4594_1313800;
	if (dword_5d4594_1313800)
		result = sub_45A4B0(*(_QWORD**)&dword_5d4594_1313800);
	dword_5d4594_1313796 = 0;
	dword_5d4594_1313800 = 0;
	return result;
}

//----- (004B8960) --------------------------------------------------------
__int16 __cdecl sub_4B8960(int* a1, nox_drawable* dr, int a3, _DWORD* a4, int a5, int a6) {
	int a2 = dr;
	unsigned __int8* v6; // esi
	int v7;              // ecx
	int v8;              // edx
	char v9;             // al
	int v10;             // eax
	int v11;             // edi
	int i;               // esi
	int v13;             // ebp
	int v14;             // eax
	int v15;             // ebx
	unsigned __int8 v16; // cl
	int v17;             // edi
	int j;               // esi
	int v19;             // ecx
	int v20;             // edi
	int k;               // esi
	int v22;             // eax
	int v23;             // ecx
	int v24;             // edi
	int l;               // esi
	int v27;             // [esp+8h] [ebp-18h]
	BOOL v28;            // [esp+Ch] [ebp-14h]
	int* v29;            // [esp+10h] [ebp-10h]
	int v30;             // [esp+14h] [ebp-Ch]
	int v31;             // [esp+18h] [ebp-8h]

	v6 = (unsigned __int8*)dr;
	v28 = sub_4356C0(dr, 23);
	v7 = 0;
	v30 = 0;
	v31 = 0;
	if (byte_5D4594[2598000] & 1)
		v27 = *(_DWORD*)&byte_5D4594[2523948];
	else
		v27 = *(_DWORD*)&byte_5D4594[2650684];
	v8 = a3;
	if (a3 & 2) {
		v9 = *(_BYTE*)(a2 + 297);
		if (v9 == 6 || v9 == 7 || v9 == 8) {
			v10 = *(_DWORD*)(a2 + 276);
			if (v10 != 6 && v10 != 35 && v10 != 39 && v10 != 40) {
				while (!((1 << v7) & 2)) {
					if (++v7 >= 26)
						goto LABEL_22;
				}
				v11 = *(_DWORD*)(a5 + 4 * v7 + 52);
				if (v11) {
					if (v28) {
						for (i = 1; i < 7; ++i)
							sub_4341D0(i, v27);
						v6 = (unsigned __int8*)dr;
					} else {
						sub_4B8CA0(a4, (char*)2);
					}
					sub_4C4770_draw(a1, v6, *(_DWORD*)(*(_DWORD*)(v11 + 4 * v6[297] + 4) + 4 * a6));
					v8 = a3;
					v30 = 1;
				}
			}
		}
	}
LABEL_22:
	v13 = 0;
	v29 = (int*)(a5 + 52);
	do {
		v14 = 1 << v13;
		if (!((1 << v13) & 2)) {
			v15 = v14 & 0x3000000;
			if (!(v14 & 0x3000000) || (v16 = v6[297], v16 != 3) && v16 && v16 != 6 && v16 != 7) {
				if (v14 & v8 && (!(v14 & 0xC00) || !(v8 & 0x4000))) {
					v17 = *v29;
					if (*v29) {
						if (v28) {
							for (j = 1; j < 7; ++j)
								sub_4341D0(j, v27);
							v6 = (unsigned __int8*)dr;
						} else {
							sub_4B8CA0(a4, (char*)(1 << v13));
						}
						sub_4C4770_draw(a1, v6, *(_DWORD*)(*(_DWORD*)(v17 + 4 * v6[297] + 4) + 4 * a6));
						if (v15)
							v31 = 1;
						v8 = a3;
					}
				}
			}
		}
		++v13;
		++v29;
	} while (v13 < 26);
	if (a3 & 2 && !v30) {
		v19 = 0;
		while (!((1 << v19) & 2)) {
			if (++v19 >= 26)
				goto LABEL_55;
		}
		v20 = *(_DWORD*)(a5 + 4 * v19 + 52);
		if (v20) {
			if (v28) {
				for (k = 1; k < 7; ++k)
					sub_4341D0(k, v27);
				v6 = (unsigned __int8*)dr;
			} else {
				sub_4B8CA0(a4, (char*)2);
			}
			sub_4C4770_draw(a1, v6, *(_DWORD*)(*(_DWORD*)(v20 + 4 * v6[297] + 4) + 4 * a6));
			v8 = a3;
		}
	}
LABEL_55:
	LOWORD(v22) = v31;
	if (!v31 && v8 & 0x3000000) {
		v23 = 0;
		v22 = (v8 & 0x1000000) != 0 ? 0x1000000 : 0x2000000;
		while (!((1 << v23) & v22)) {
			if (++v23 >= 26)
				return v22;
		}
		v24 = *(_DWORD*)(a5 + 4 * v23 + 52);
		if (v24) {
			if (v28) {
				for (l = 1; l < 7; ++l)
					sub_4341D0(l, v27);
				v6 = (unsigned __int8*)dr;
			} else {
				sub_4B8CA0(a4, (char*)v22);
			}
			LOWORD(v22) = sub_4C4770_draw(a1, v6, *(_DWORD*)(*(_DWORD*)(v24 + 4 * v6[297] + 4) + 4 * a6));
		}
	}
	return v22;
}

//----- (004B8CA0) --------------------------------------------------------
_DWORD* __cdecl sub_4B8CA0(_DWORD* a1, char* a2) {
	_DWORD* result; // eax
	int v3;         // ebx
	int v4;         // eax
	int v5;         // edx
	int v6;         // ecx
	_DWORD* v7;     // ebp
	int v8;         // edi
	_BYTE* v9;      // esi
	_DWORD* v10;    // ecx
	int v11;        // eax
	int* v12;       // edi
	int v13;        // ebx
	_DWORD** v14;   // esi
	int v15;        // [esp-Ch] [ebp-14h]

	result = a1;
	v3 = 0;
	while ((char*)*result != a2) {
		++v3;
		result += 6;
		if (v3 >= 26)
			return result;
	}
	v4 = sub_415CD0(a2);
	result = sub_413270(v4);
	v7 = result;
	if (result) {
		v8 = 1;
		v9 = result + 4;
		do {
			LOBYTE(result) = v9[1];
			LOBYTE(v6) = *v9;
			LOBYTE(v5) = *(v9 - 1);
			sub_4340A0(v8++, v5, v6, (int)result);
			v9 += 3;
		} while (v8 < 7);
		v10 = a1;
		v11 = 3 * v3;
		v12 = v7 + 9;
		v13 = 4;
		v14 = (_DWORD**)&a1[2 * v11 + 1];
		do {
			result = *v14;
			if (*v14) {
				LOBYTE(v5) = *((_BYTE*)result + 26);
				LOBYTE(v10) = *((_BYTE*)result + 25);
				v15 = v5;
				LOBYTE(v5) = *((_BYTE*)result + 24);
				sub_4340A0(*v12, v5, (int)v10, v15);
			}
			++v14;
			++v12;
			--v13;
		} while (v13);
	}
	return result;
}
// 4B8CE7: variable 'v5' is possibly undefined
// 4B8CE7: variable 'v6' is possibly undefined
// 4B8D20: variable 'v10' is possibly undefined

//----- (004B8D40) --------------------------------------------------------
__int16 __cdecl sub_4B8D40(int* a1, nox_drawable* dr, int a3, _DWORD* a4, int a5, int a6) {
	unsigned __int8* v6; // esi
	int v7;              // ebx
	int* v8;             // ebp
	int v9;              // eax
	int v10;             // edi
	int i;               // esi
	int v13;             // [esp+10h] [ebp-8h]
	BOOL v14;            // [esp+14h] [ebp-4h]

	v6 = (unsigned __int8*)dr;
	v14 = sub_4356C0(dr, 25);
	if (byte_5D4594[2598000] & 1)
		v13 = *(_DWORD*)&byte_5D4594[2523948];
	else
		v13 = *(_DWORD*)&byte_5D4594[2650684];
	v7 = 1;
	v8 = (int*)(a5 + 160);
	do {
		v9 = 1 << v7;
		if ((1 << v7) & a3) {
			v10 = *v8;
			if (*v8) {
				if (v14) {
					for (i = 1; i < 7; ++i)
						sub_4341D0(i, v13);
					v6 = (unsigned __int8*)dr;
				} else {
					sub_4B8E10(a4, (char*)(1 << v7));
				}
				LOWORD(v9) = sub_4C4770_draw(a1, v6, *(_DWORD*)(*(_DWORD*)(v10 + 4 * v6[297] + 4) + 4 * a6));
			}
		}
		++v7;
		++v8;
	} while (v7 < 27);
	return v9;
}

//----- (004B8E10) --------------------------------------------------------
_DWORD* __cdecl sub_4B8E10(_DWORD* a1, char* a2) {
	_DWORD* result; // eax
	int v3;         // ebx
	int v4;         // eax
	int v5;         // edx
	int v6;         // ecx
	_DWORD* v7;     // ebp
	int v8;         // edi
	_BYTE* v9;      // esi
	_DWORD* v10;    // ecx
	int v11;        // eax
	int* v12;       // edi
	int v13;        // ebx
	_DWORD** v14;   // esi
	int v15;        // [esp-Ch] [ebp-14h]

	result = a1;
	v3 = 0;
	while ((char*)*result != a2) {
		++v3;
		result += 6;
		if (v3 >= 27)
			return result;
	}
	v4 = sub_415840(a2);
	result = sub_413250(v4);
	v7 = result;
	if (result) {
		v8 = 1;
		v9 = result + 4;
		do {
			LOBYTE(result) = v9[1];
			LOBYTE(v6) = *v9;
			LOBYTE(v5) = *(v9 - 1);
			sub_4340A0(v8++, v5, v6, (int)result);
			v9 += 3;
		} while (v8 < 7);
		v10 = a1;
		v11 = 3 * v3;
		v12 = v7 + 9;
		v13 = 4;
		v14 = (_DWORD**)&a1[2 * v11 + 1];
		do {
			result = *v14;
			if (*v14) {
				LOBYTE(v5) = *((_BYTE*)result + 26);
				LOBYTE(v10) = *((_BYTE*)result + 25);
				v15 = v5;
				LOBYTE(v5) = *((_BYTE*)result + 24);
				sub_4340A0(*v12, v5, (int)v10, v15);
			}
			++v14;
			++v12;
			--v13;
		} while (v13);
	}
	return result;
}
// 4B8E57: variable 'v5' is possibly undefined
// 4B8E57: variable 'v6' is possibly undefined
// 4B8E90: variable 'v10' is possibly undefined

//----- (004B8EB0) --------------------------------------------------------
void __cdecl sub_4B8EB0(_DWORD* a1, nox_drawable* dr, unsigned __int16 a3, char a4) {
	int a2 = dr;
	int v4;   // esi
	int v5;   // esi
	int v6;   // edi
	float v7; // [esp+0h] [ebp-14h]

	if (a2) {
		v4 = *a1 + *(_DWORD*)(a2 + 12) - a1[4];
		v7 = *(float*)(a2 + 48) + *(float*)(a2 + 48);
		v5 = nox_float2int(v7) + v4;
		v6 = *(_DWORD*)(a2 + 16) + a1[1] - *(__int16*)(a2 + 104) - a1[5] - 48;
		nox_client_drawSetColor_434460(*(int*)&byte_5D4594[2650656]);
		nox_client_drawRectFilledOpaque_49CE30(v5, v6, 2, 48);
		if (a4)
			nox_client_drawSetColor_434460(*(int*)&byte_5D4594[2618904]);
		else
			nox_client_drawSetColor_434460(*(int*)&byte_5D4594[2650644]);
		nox_client_drawRectFilledOpaque_49CE30(v5, v6 - 48 * a3 / 100 + 48, 2, 48 * a3 / 100);
		if (a4)
			nox_client_drawSetColor_434460(*(int*)&byte_5D4594[2650688]);
		else
			nox_client_drawSetColor_434460(*(int*)&byte_5D4594[2598268]);
		nox_client_drawBorderLines_49CC70(v5 - 1, v6 - 1, 4, 50);
	}
}

//----- (004B8FA0) --------------------------------------------------------
int __cdecl sub_4B8FA0(nox_drawable* dr, int* a2, int* a3) {
	int a1 = dr;

	int v3;  // esi
	int v4;  // eax
	bool v5; // zf
	int v6;  // esi
	int v8;  // eax
	int v9;  // ecx

	v3 = *(_DWORD*)(a1 + 304);
	if (*(_DWORD*)(a1 + 276) || !sub_48D830(dr)) {
		if (*(_DWORD*)(a1 + 276) != 4 || (v5 = !sub_4356C0(dr, 31), v4 = 53, v5))
			v4 = *(_DWORD*)(a1 + 276);
	} else {
		v4 = 19;
	}
	v5 = *(_WORD*)(v3 + 264 * v4 + 44) == 0;
	v6 = v3 + 264 * v4 + 4;
	if (v5)
		return 0;
	v8 = sub_4BC5D0(dr, v6);
	if (v8 < 0)
		return 0;
	v9 = *(__int16*)(v6 + 40);
	if (v8 >= v9)
		v8 = v9 - 1;
	if (a2)
		*a2 = v6;
	if (a3)
		*a3 = v8;
	return *(_DWORD*)(*(_DWORD*)(*(_DWORD*)(v6 + 48) + 4 * *(unsigned __int8*)(a1 + 297) + 4) + 4 * v8);
}
