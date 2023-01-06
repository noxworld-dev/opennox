#include "client__gui__servopts__access.h"
#include "client__gui__window.h"
#include "common__strman.h"
#include "compat.h"

#include "GAME1.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME3_2.h"
extern uint32_t dword_5d4594_1045596;
extern uint32_t dword_5d4594_1045556;
extern uint32_t dword_5d4594_1045520;
extern uint32_t dword_5d4594_1045552;
extern uint32_t dword_5d4594_1045584;
extern uint32_t dword_5d4594_1045588;
extern uint32_t dword_5d4594_1045532;
extern uint32_t dword_5d4594_1045528;
extern uint32_t dword_5d4594_1045516;

//----- (00454640) --------------------------------------------------------
int sub_454640() {
	uint32_t* v0;       // eax
	uint32_t* v1;       // esi
	int v2;             // eax
	unsigned short* v3; // eax
	unsigned short* v4; // eax
	unsigned short* v5; // eax
	int v6;             // eax
	int v7;             // eax
	int result;         // eax
	int v9;             // [esp+4h] [ebp-8h]
	int v10;            // [esp+8h] [ebp-4h]

	v0 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1045516, 10123);
	v1 = v0;
	v2 = nox_xxx_guiFontHeightMB_43F320(v0[59]) + 1;
	v1[7] = v1[5] + 4 * v2 + 2;
	v1[3] = 4 * v2 + 2;
	v3 = nox_strman_loadString_40F1D0("WARRIOR", 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\access.c", 88);
	nox_xxx_drawGetStringSize_43F840(v1[59], v3, &v9, 0, 0);
	v4 = nox_strman_loadString_40F1D0("WIZARD", 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\access.c", 89);
	nox_xxx_drawGetStringSize_43F840(v1[59], v4, &v10, 0, 0);
	if (v10 > v9) {
		v9 = v10;
	}
	v5 = nox_strman_loadString_40F1D0("CONJURER", 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\access.c", 94);
	nox_xxx_drawGetStringSize_43F840(v1[59], v5, &v10, 0, 0);
	v6 = v9;
	if (v10 > v9) {
		v6 = v10;
	}
	v7 = v6 + 7;
	v9 = v7;
	v1[2] = v7;
	result = v9 + v1[4];
	v1[6] = result;
	return result;
}

//----- (00454740) --------------------------------------------------------
int* sub_454740() {
	char* v0;                // esi
	uint32_t* v1;            // edi
	wchar_t* v2;             // eax
	uint32_t* v3;            // eax
	uint32_t* v4;            // eax
	uint32_t* v5;            // eax
	wchar_t* v6;             // eax
	wchar_t* v7;             // eax
	wchar_t* v8;             // eax
	char v9;                 // dl
	int v10;                 // ecx
	int v11;                 // eax
	char* i;                 // esi
	wchar_t WideCharStr[18]; // [esp+Ch] [ebp-24h]

	v0 = sub_416640();
	v1 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1045516, 10136);
	v2 = nox_xxx_sysopGetPass_40A630();
	nox_window_call_field_94((int)v1, 16414, (int)v2, 0);
	if (*(short*)(v0 + 105) != -1) {
		nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1045584, 1);
		*(uint32_t*)(*getMemU32Ptr(0x5D4594, 1045568) + 36) |= 4u;
		_itow(*(unsigned short*)(v0 + 105), WideCharStr, 10);
		nox_window_call_field_94(*(int*)&dword_5d4594_1045584, 16414, (int)WideCharStr, 0);
	}
	if (*(short*)(v0 + 107) != -1) {
		nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1045588, 1);
		*(uint32_t*)(*getMemU32Ptr(0x5D4594, 1045572) + 36) |= 4u;
		_itow(*(unsigned short*)(v0 + 107), WideCharStr, 10);
		nox_window_call_field_94(*(int*)&dword_5d4594_1045588, 16414, (int)WideCharStr, 0);
	}
	v3 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1045516, 10124);
	if ((int)v0[102] < 0) {
		v3[9] |= 4u;
	}
	if (v0[100] & 0x20) {
		nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1045556, 1);
		*(uint32_t*)(*getMemU32Ptr(0x5D4594, 1045524) + 36) |= 4u;
	}
	nox_window_call_field_94(*(int*)&dword_5d4594_1045556, 16414, (int)(v0 + 78), 0);
	if (sub_4D6F30()) {
		nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1045520, 0);
	} else {
		nox_xxx_wnd_46ABB0(*(int*)&dword_5d4594_1045520, 1);
		if (v0[100] & 0x10) {
			*(uint32_t*)(dword_5d4594_1045520 + 36) = 4;
		} else {
			v4 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1045516, 10206);
			nox_xxx_wnd_46ABB0((int)v4, 0);
		}
	}
	v5 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1045516, 10207);
	v5[9] |= 4u;
	dword_5d4594_1045596 = dword_5d4594_1045528;
	v6 = nox_strman_loadString_40F1D0("WARRIOR", 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\access.c", 242);
	nox_window_call_field_94(*(int*)&dword_5d4594_1045552, 16397, (int)v6, -1);
	v7 = nox_strman_loadString_40F1D0("WIZARD", 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\access.c", 243);
	nox_window_call_field_94(*(int*)&dword_5d4594_1045552, 16397, (int)v7, -1);
	v8 = nox_strman_loadString_40F1D0("CONJURER", 0, "C:\\NoxPost\\src\\client\\Gui\\ServOpts\\access.c", 244);
	nox_window_call_field_94(*(int*)&dword_5d4594_1045552, 16397, (int)v8, -1);
	if (v0[100] & 0x10) {
		nox_window_set_hidden(*(int*)&dword_5d4594_1045532, 0);
		nox_window_set_hidden(*(int*)&dword_5d4594_1045528, 1);
	}
	v9 = v0[100];
	if (v9) {
		v10 = 0;
		v11 = *(uint32_t*)(dword_5d4594_1045552 + 32);
		if (v9 & 1) {
			**(uint32_t**)(v11 + 48) = 0;
			v10 = 1;
			*(uint32_t*)(*(uint32_t*)(v11 + 48) + 4) = -1;
		}
		if (v0[100] & 2) {
			*(uint32_t*)(*(uint32_t*)(v11 + 48) + 4 * ++v10 - 4) = 1;
			*(uint32_t*)(*(uint32_t*)(v11 + 48) + 4 * v10) = -1;
		}
		if (v0[100] & 4) {
			*(uint32_t*)(*(uint32_t*)(v11 + 48) + 4 * v10) = 2;
			*(uint32_t*)(*(uint32_t*)(v11 + 48) + 4 * v10 + 4) = -1;
		}
	}
	_itow((unsigned char)v0[104], WideCharStr, 10);
	nox_window_call_field_94(*getMemIntPtr(0x5D4594, 1045592), 16414, (int)WideCharStr, 0);
	for (i = nox_common_playerInfoGetFirst_416EA0(); i; i = nox_common_playerInfoGetNext_416EE0((int)i)) {
		if (i[2064] != 31 || !nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
			sub_455920((int)(i + 4704));
		}
	}
	return sub_455800();
}
