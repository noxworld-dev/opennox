#include "client__shell__wolapi__wolchat.h"

#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2_1.h"
#include "GAME2_3.h"
#include "GAME3.h"
#include "client__gui__window.h"
#include "common__strman.h"
#include "common__wolapi__wolchnl.h"
extern uint32_t dword_5d4594_829532;
extern uint32_t dword_587000_109280;
extern uint32_t dword_5d4594_829544;
extern uint32_t dword_5d4594_829500;
extern nox_gui_animation* nox_wnd_xxx_829520;
extern uint32_t dword_5d4594_829516;
extern uint32_t dword_5d4594_829512;
extern uint32_t dword_5d4594_829484;
extern uint32_t dword_5d4594_829508;
extern uint32_t dword_5d4594_829488;
extern uint32_t dword_5d4594_829492;
extern uint32_t dword_5d4594_829480;

//----- (00446970) --------------------------------------------------------
char* sub_446970_wol_chat() {
	char* result;      // eax
	int v1;            // edi
	unsigned char* v2; // esi

	result = *(char**)getMemAt(0x5D4594, 829568);
	if (!*getMemU32Ptr(0x5D4594, 829568)) {
		result = *(char**)getMemAt(0x587000, 108852);
		v1 = 0;
		if (*getMemU32Ptr(0x587000, 108852)) {
			v2 = getMemAt(0x587000, 108848);
			do {
				*(uint32_t*)v2 = nox_strman_loadString_40F1D0(
					*((char**)v2 + 1), 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c", 181);
				result = (char*)*((uint32_t*)v2 + 3);
				v2 += 8;
				++v1;
			} while (result);
		}
		*getMemU32Ptr(0x5D4594, 826092) = v1;
		*getMemU32Ptr(0x5D4594, 829568) = 1;
	}
	return result;
}

//----- (00446A20) --------------------------------------------------------
int sub_446A20_wol_chat(wchar_t* a1) {
	wchar_t* v1; // eax
	wchar_t* v3; // [esp-10h] [ebp-10h]

	sub_446CC0(0);
	sub_41F140(a1);
	sub_44A400();
	v3 = nox_strman_loadString_40F1D0("UpdatingChannels", 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c", 212);
	v1 = nox_strman_loadString_40F1D0("PleaseWait", 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c", 211);
	nox_xxx_dialogMsgBoxCreate_449A10(*(int*)&dword_5d4594_829480, (int)v1, (int)v3, 288, 0, 0);
	sub_44A4B0();
	return 0;
}

//----- (00446AE0) --------------------------------------------------------
const char* sub_446AE0_wol_chat(int a1) {
	const char* result; // eax
	const char* v2;     // ebx
	char v3[108];       // [esp+8h] [ebp-6Ch]

	result = sub_446BC0(a1);
	v2 = result;
	if (result) {
		strcpy(&v3[36], result);
		if (sub_41F9E0((int)v3)) {
			result = (const char*)nox_strman_loadString_40F1D0(
				"cantignore", 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c", 293);
			if (result) {
				result = (const char*)sub_447310(0, (int)result);
			}
		} else if (sub_427880(v2)) {
			sub_427850((int)v3);
			sub_41F980(v2, 0);
			result = (const char*)sub_446C10(a1, 0);
		} else {
			sub_427820((int)v3);
			sub_41F980(v2, 1);
			result = (const char*)sub_446C10(a1, 1);
		}
	}
	return result;
}

//----- (00446F80) --------------------------------------------------------
void sub_446F80_wol_chat(wchar_t* a1) {
	wchar_t v1;     // ax
	int* v2;        // eax
	int* v3;        // edi
	int i;          // eax
	char* v5;       // eax
	const char* v6; // esi
	char* v7;       // eax
	wchar_t* v8;    // eax

	if (!a1) {
		return;
	}
	v1 = *a1;
	if (!*a1 || v1 == 10 || v1 == 13) {
		return;
	}
	if (sub_41EC00()) {
		if (sub_446C90()) {
			v2 = (int*)nox_window_call_field_94(*(int*)&dword_5d4594_829488, 16404, 0, 0);
			v3 = v2;
			for (i = *v2; i != -1; ++v3) {
				v5 = sub_446F40(i);
				v6 = v5;
				if (v5) {
					if (sub_41F860(v5, a1)) {
						sub_4471A0(v6, (int)a1, 1, 1);
					}
				}
				i = v3[1];
			}
			return;
		}
		sub_448680(a1, (char*)getMemAt(0x5D4594, 827176));
		if (sub_40D3E0((int)getMemAt(0x5D4594, 827176))) {
			v7 = sub_41FA40();
			sub_4471A0(v7, (int)a1, 0, 0);
			return;
		}
	}
	v8 = nox_strman_loadString_40F1D0("NotJoined", 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c", 1076);
	if (v8) {
		sub_447310(0, (int)v8);
	}
}

//----- (00447090) --------------------------------------------------------
void sub_447090_wol_chat(wchar_t* a1) {
	wchar_t v1;     // ax
	int* v2;        // eax
	int* v3;        // edi
	int i;          // eax
	char* v5;       // eax
	const char* v6; // esi
	char* v7;       // eax
	wchar_t* v8;    // eax

	if (!a1) {
		return;
	}
	v1 = *a1;
	if (!*a1 || v1 == 10 || v1 == 13) {
		return;
	}
	if (sub_41EC00()) {
		if (sub_446C90()) {
			v2 = (int*)nox_window_call_field_94(*(int*)&dword_5d4594_829488, 16404, 0, 0);
			v3 = v2;
			for (i = *v2; i != -1; ++v3) {
				v5 = sub_446F40(i);
				v6 = v5;
				if (v5) {
					if (sub_41F8F0(v5, a1)) {
						sub_447250(v6, (int)a1, 1, 1);
					}
				}
				i = v3[1];
			}
			return;
		}
		sub_448680(a1, (char*)getMemAt(0x5D4594, 827176));
		if (sub_40D4D0((int)getMemAt(0x5D4594, 827176))) {
			v7 = sub_41FA40();
			sub_447250(v7, (int)a1, 0, 0);
			return;
		}
	}
	v8 = nox_strman_loadString_40F1D0("NotJoined", 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c", 1123);
	if (v8) {
		sub_447310(0, (int)v8);
	}
}

//----- (00447470) --------------------------------------------------------
int sub_447470_wol_chat() {
	wchar_t* v0; // esi
	int result;  // eax

	v0 = nox_strman_loadString_40F1D0("joined", 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c", 1261);
	result = sub_41EC00();
	if (result) {
		nox_swprintf((wchar_t*)getMemAt(0x5D4594, 827176), v0, result);
		result = nox_window_call_field_94(*(int*)&dword_5d4594_829492, 16397, (int)getMemAt(0x5D4594, 827176), 9);
	}
	return result;
}

//----- (004474C0) --------------------------------------------------------
int sub_4474C0_wol_chat(int a1, int a2) {
	wchar_t* v2; // eax
	wchar_t* v3; // eax

	if (a1) {
		v2 = nox_strman_loadString_40F1D0("kicked", 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c", 1277);
		nox_swprintf((wchar_t*)getMemAt(0x5D4594, 827176), v2, a2, a1);
	} else {
		v3 = nox_strman_loadString_40F1D0("youwerekicked", 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c",
										  1281);
		nox_swprintf((wchar_t*)getMemAt(0x5D4594, 827176), v3, a2);
	}
	return nox_window_call_field_94(*(int*)&dword_5d4594_829492, 16397, (int)getMemAt(0x5D4594, 827176), 9);
}

//----- (00447540) --------------------------------------------------------
int sub_447540_wol_chat(int a1) {
	wchar_t* v1; // eax

	v1 = nox_strman_loadString_40F1D0("banned", 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c", 1296);
	nox_swprintf((wchar_t*)getMemAt(0x5D4594, 827176), v1, a1);
	return nox_window_call_field_94(*(int*)&dword_5d4594_829492, 16397, (int)getMemAt(0x5D4594, 827176), 9);
}

//----- (00447590) --------------------------------------------------------
int sub_447590_wol_chat() {
	wchar_t* v0; // esi
	int result;  // eax

	v0 = nox_strman_loadString_40F1D0("left", 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c", 1310);
	result = sub_41EC00();
	if (result) {
		nox_swprintf((wchar_t*)getMemAt(0x5D4594, 827176), v0, result);
		result = nox_window_call_field_94(*(int*)&dword_5d4594_829492, 16397, (int)getMemAt(0x5D4594, 827176), 9);
	}
	return result;
}

//----- (00447620) --------------------------------------------------------
int nox_game_showWolChat_447620() {
	int result;        // eax
	char** v1;         // eax
	unsigned char* v2; // esi
	wchar_t* v3;       // eax
	uint8_t* v4;       // ecx
	uint32_t* v5;      // edi
	char* v6;          // ebx
	char* v7;          // esi
	uint32_t* v8;      // edi
	uint32_t* v9;      // edi

	nox_game_addStateCode_43BDD0(1900);
	nox_game_SetCliDrawFunc(sub_41E210);
	nox_draw_setTabWidth_43FE20(150);
	dword_5d4594_829480 = nox_new_window_from_file("wolchat.wnd", sub_447CC0);
	sub_446970_wol_chat();
	result = dword_5d4594_829480;
	if (dword_5d4594_829480) {
		nox_xxx_wndShowModalMB_46A8C0(*(int*)&dword_5d4594_829480);
		sub_44A4B0();
		nox_window_set_all_funcs(*(uint32_t**)&dword_5d4594_829480, sub_447C70, 0, 0);
		nox_xxx_wndSetDrawFn_46B340(*(int*)&dword_5d4594_829480, sub_4483A0);
		result = nox_gui_makeAnimation_43C5B0(*(uint32_t**)&dword_5d4594_829480, 0, 0, 0, -480, 0, 20, 0, -40);
		nox_wnd_xxx_829520 = result;
		if (nox_wnd_xxx_829520) {
			nox_wnd_xxx_829520->field_0 = 1900;
			nox_wnd_xxx_829520->field_12 = sub_446A90;
			nox_wnd_xxx_829520->fnc_done_out = sub_447BD0;
			dword_5d4594_829484 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_829480, 1908);
			dword_5d4594_829488 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_829480, 1909);
			dword_5d4594_829492 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_829480, 1907);
			*getMemU32Ptr(0x5D4594, 829496) = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_829480, 1916);
			dword_5d4594_829500 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_829480, 1910);
			*getMemU32Ptr(0x5D4594, 829528) = nox_strman_loadString_40F1D0(
				"messageTitle", 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c", 1415);
			dword_5d4594_829532 = nox_strman_loadString_40F1D0(
				"NoChannel", 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c", 1416);
			*getMemU32Ptr(0x5D4594, 829536) = getMemAt(0x587000, 110992);
			*getMemU32Ptr(0x5D4594, 829540) =
				nox_strman_loadString_40F1D0("pageMsg", 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c", 1418);
			dword_5d4594_829544 = getMemAt(0x587000, 111056);
			*getMemU32Ptr(0x5D4594, 829548) = nox_strman_loadString_40F1D0(
				"PrivateMessage", 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c", 1420);
			*getMemU32Ptr(0x5D4594, 829552) = nox_strman_loadString_40F1D0(
				"PrivateToMessage", 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c", 1421);
			*getMemU32Ptr(0x5D4594, 829556) = getMemAt(0x587000, 111204);
			*getMemU32Ptr(0x5D4594, 829560) = nox_strman_loadString_40F1D0(
				"PrivateAction", 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c", 1423);
			*getMemU32Ptr(0x5D4594, 829564) = nox_strman_loadString_40F1D0(
				"PrivateToAction", 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c", 1424);
			*getMemU32Ptr(0x5D4594, 829524) =
				nox_strman_loadString_40F1D0("Stats", 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c", 1425);
			dword_587000_109280 = -1;
			sub_446D50();
			nox_xxx_wndRetNULL_46A8A0();
			sub_447600();
			sub_41EBB0(0);
			sub_446CC0(0);
			sub_41F100("Chat Channels");
			if (**(uint8_t**)getMemAt(0x587000, 108828)) {
				v1 = (char**)getMemAt(0x587000, 108828);
				v2 = getMemAt(0x587000, 108828);
				do {
					v3 = nox_strman_loadString_40F1D0(*v1, 0, "C:\\NoxPost\\src\\client\\shell\\WolApi\\wolchat.c",
													  1446);
					*((uint32_t*)v2 - 1) = v3;
					nox_wcslen(v3);
					v4 = (uint8_t*)*((uint32_t*)v2 + 3);
					v2 += 12;
					v1 = (char**)v2;
				} while (*v4);
			}
			sub_41FFF0();
			dword_5d4594_829508 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_829480, 1917);
			dword_5d4594_829512 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_829480, 1918);
			dword_5d4594_829516 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_829480, 1919);
			v5 = *(uint32_t**)(dword_5d4594_829492 + 32);
			v6 = nox_xxx_gLoadImg_42F970("ShopInventorySlider");
			v7 = nox_xxx_gLoadImg_42F970("ShopInventorySliderSelected");
			sub_4B5700(*(int*)&dword_5d4594_829508, 0, 0, (int)v6, (int)v7, (int)v7);
			nox_xxx_wnd_46B280(*(int*)&dword_5d4594_829508, *(int*)&dword_5d4594_829492);
			nox_xxx_wnd_46B280(*(int*)&dword_5d4594_829512, *(int*)&dword_5d4594_829492);
			nox_xxx_wnd_46B280(*(int*)&dword_5d4594_829516, *(int*)&dword_5d4594_829492);
			nox_xxx_wndSetWindowProc_46B300(*(int*)&dword_5d4594_829492, sub_447BF0);
			v5[9] = dword_5d4594_829508;
			v5[7] = dword_5d4594_829512;
			v5[8] = dword_5d4594_829516;
			*(uint32_t*)(*(uint32_t*)(dword_5d4594_829508 + 400) + 8) = 16;
			*(uint32_t*)(*(uint32_t*)(dword_5d4594_829508 + 400) + 12) = 46;
			dword_5d4594_829508 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_829480, 1920);
			dword_5d4594_829512 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_829480, 1921);
			dword_5d4594_829516 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_829480, 1922);
			v8 = *(uint32_t**)(dword_5d4594_829484 + 32);
			sub_4B5700(*(int*)&dword_5d4594_829508, 0, 0, (int)v6, (int)v7, (int)v7);
			nox_xxx_wnd_46B280(*(int*)&dword_5d4594_829508, *(int*)&dword_5d4594_829484);
			nox_xxx_wnd_46B280(*(int*)&dword_5d4594_829512, *(int*)&dword_5d4594_829484);
			nox_xxx_wnd_46B280(*(int*)&dword_5d4594_829516, *(int*)&dword_5d4594_829484);
			nox_xxx_wndSetWindowProc_46B300(*(int*)&dword_5d4594_829484, sub_447BF0);
			v8[9] = dword_5d4594_829508;
			v8[7] = dword_5d4594_829512;
			v8[8] = dword_5d4594_829516;
			*(uint32_t*)(*(uint32_t*)(dword_5d4594_829508 + 400) + 8) = 16;
			*(uint32_t*)(*(uint32_t*)(dword_5d4594_829508 + 400) + 12) = 46;
			dword_5d4594_829508 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_829480, 1923);
			dword_5d4594_829512 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_829480, 1924);
			dword_5d4594_829516 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_829480, 1925);
			v9 = *(uint32_t**)(dword_5d4594_829488 + 32);
			sub_4B5700(*(int*)&dword_5d4594_829508, 0, 0, (int)v6, (int)v7, (int)v7);
			nox_xxx_wnd_46B280(*(int*)&dword_5d4594_829508, *(int*)&dword_5d4594_829488);
			nox_xxx_wnd_46B280(*(int*)&dword_5d4594_829512, *(int*)&dword_5d4594_829488);
			nox_xxx_wnd_46B280(*(int*)&dword_5d4594_829516, *(int*)&dword_5d4594_829488);
			nox_xxx_wndSetWindowProc_46B300(*(int*)&dword_5d4594_829488, sub_447BF0);
			v9[9] = dword_5d4594_829508;
			v9[7] = dword_5d4594_829512;
			v9[8] = dword_5d4594_829516;
			*(uint32_t*)(*(uint32_t*)(dword_5d4594_829508 + 400) + 8) = 16;
			*(uint32_t*)(*(uint32_t*)(dword_5d4594_829508 + 400) + 12) = 46;
			sub_41F370(0);
			if (nox_common_gameFlags_check_40A5C0(0x2000000)) {
				sub_448450();
			} else {
				sub_41F3A0(-99999, 1);
			}
			result = 1;
		}
	}
	return result;
}
