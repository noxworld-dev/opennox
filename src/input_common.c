//+build none

#include "input.h"
#include "GAME1.h"
#include "GAME1_3.h"
#include "GAME2_1.h"
#include "GAME2_2.h"
#include "client__gui__window.h"
#include "client__io__win95__focus.h"
#include "client__system__ctrlevnt.h"
#include "defs.h"
#include "input_common.h"
#include "legacy/input_ddraw.h"
#include "server__script__builtin.h"
#include "MixPatch.h"

#include "client__system__parsecmd.h"
#include "client__system__ctrlevnt.h"
#include "client__gui__window.h"

extern __int16 asc_9800B0[526];

extern nox_ctrlevent_key_t* dword_5d4594_754056;
extern int obj_5D4594_754104_switch;
extern unsigned int nox_frame_xxx_2598000;

extern int nox_win_width;
extern int nox_win_height;

nox_mouse_state_t nox_input_buffer[256] = {0};
int nox_input_buffer_cap = sizeof(nox_input_buffer) / sizeof(nox_mouse_state_t);

nox_mouse_state_t nox_mouse = {0};
nox_mouse_state_t nox_mouse_prev = {0};
_DWORD nox_mouse_prev_seq = 0;
_DWORD nox_mouse_prev_seq_2 = 0;
nox_point nox_mouse_prev_btn[3] = {0};

nox_point nox_mouse_min = {0, 0};
#ifdef __GNUC__
nox_point nox_mouse_max = {NOX_DEFAULT_WIDTH - 1, NOX_DEFAULT_HEIGHT - 1};
#else
nox_point nox_mouse_max = {639, 478}; // ugly hack for MSVC
#endif

#ifndef NOX_CGO
_DWORD dword_5d4594_1193132 = 0;
#endif // NOX_CGO

nox_keyboard_btn_t nox_input_arr_789276[256];
nox_keyboard_btn_t nox_input_arr_787228[256];

//----- (00430140) --------------------------------------------------------
void nox_input_reset_430140(int a1) {
	for (int i = 0; i < 256; i++) {
		nox_keyboard_btn_t* cur = &nox_input_arr_789276[i];
		cur->state = 1;
		cur->field_2 = 0;
		cur->seq = 0;
	}
	nox_input_buffer[0].btn[0].seq = 1;
	nox_input_buffer[0].btn[0].pressed = 0;
	nox_input_buffer[0].btn[1].seq = 1;
	nox_input_buffer[0].btn[1].pressed = 0;
	nox_input_buffer[0].btn[2].seq = 1;
	nox_input_buffer[0].btn[2].pressed = 0;
	nox_client_processMouseEvents_4302A0(1, 1);
}

//----- (00430210) --------------------------------------------------------
void nox_xxx_freeKeyboard_430210() {
	nox_xxx_freeKeyboard_47FCC0();
	*getMemU32Ptr(0x5D4594, 805808) = 0;
}

int nox_mouse_state(int btn, int st) {
	return 4*(btn+1) + st;
}

//----- (00430230) --------------------------------------------------------
void nox_client_mouseBtnStateReset(int ind) {
	nox_mouse_btn_t* cur = &nox_mouse.btn[ind];
	nox_mouse_btn_t* prev = &nox_mouse_prev.btn[ind];
	int btn = 4*(ind+1);

	if (cur->pressed && (prev->state == btn + NOX_MOUSE_DOWN || prev->state == btn + NOX_MOUSE_PRESSED)) {
		cur->state = btn + NOX_MOUSE_PRESSED;
	}
}
void nox_client_mouseBtnState_430230() {
	nox_client_mouseBtnStateReset(NOX_MOUSE_LEFT);
	nox_client_mouseBtnStateReset(NOX_MOUSE_RIGHT);
	nox_client_mouseBtnStateReset(NOX_MOUSE_MIDDLE);
}

//----- (004302A0) --------------------------------------------------------
void nox_client_mouseBtnStateApply(nox_mouse_state_t* evt, nox_point pos, int ind) {
	nox_mouse_btn_t* ev = &evt->btn[ind];
	nox_mouse_btn_t* cur = &nox_mouse.btn[ind];
	nox_point prevPos = nox_mouse_prev_btn[ind];
	int btn = 4*(ind+1);

	if (ev->seq == 0) {
		nox_client_mouseBtnStateReset(ind);
		return;
	}
	if (cur->pressed == ev->pressed) {
		return;
	}
	int dx = pos.x - prevPos.x;
	int dy = pos.y - prevPos.y;
	if (ev->pressed) {
		if (cur->state != btn + NOX_MOUSE_UP) {
			cur->state = btn + NOX_MOUSE_DOWN;
			cur->pressed = 1;
			cur->seq = nox_mouse_prev_seq;
		}
	} else {
		if (((int)nox_mouse_prev_seq - cur->seq) >= 15 || (dx*dx + dy*dy >= 100)) {
			cur->state = btn + NOX_MOUSE_DRAG_END;
		} else {
			cur->state = btn + NOX_MOUSE_UP;
		}
		cur->pressed = 0;
		cur->seq = nox_mouse_prev_seq;
	}
}
void nox_client_mouseBtnStateFinal(nox_point pos, int ind) {
	nox_mouse_btn_t* cur = &nox_mouse.btn[ind];
	int btn = 4*(ind+1);

	if (cur->state == btn + NOX_MOUSE_DOWN) {
		nox_mouse_prev_btn[ind]= pos;
	}
}
void nox_client_processMouseEvents_4302A0(int evNum, int a2) {
	if (nox_mouse_prev_seq_2 != nox_mouse_prev_seq) {
		nox_mouse.btn[NOX_MOUSE_LEFT].state = 0;
		nox_mouse.btn[NOX_MOUSE_RIGHT].state = 0;
		nox_mouse.btn[NOX_MOUSE_MIDDLE].state = 0;
		nox_mouse.wheel = 0;
		nox_mouse_prev_seq_2 = nox_mouse_prev_seq;
	}
	int num = 0;
	if (obj_5D4594_754104_switch != 1) {
		num = evNum;
		if (num == 0) {
			nox_client_mouseBtnState_430230();
		}
	}
	nox_point pos = nox_mouse.pos;
	for (int i = 0; i < num; i++) {
		nox_mouse_state_t* ev = &nox_input_buffer[i];
		// apply absolute mouse pos
		nox_client_changeMousePos_430A00(ev->pos.x, ev->pos.y, true);
		nox_mouse.wheel += ev->wheel;

		// variable needs to be updated as well
		pos = nox_mouse.pos;

		// apply button states
		nox_client_mouseBtnStateApply(ev, pos, NOX_MOUSE_LEFT);
		nox_client_mouseBtnStateApply(ev, pos, NOX_MOUSE_RIGHT);
		nox_client_mouseBtnStateApply(ev, pos, NOX_MOUSE_MIDDLE);
	}
	// update button prev pos, if necessary
	nox_client_mouseBtnStateFinal(pos, NOX_MOUSE_LEFT);
	nox_client_mouseBtnStateFinal(pos, NOX_MOUSE_RIGHT);
	nox_client_mouseBtnStateFinal(pos, NOX_MOUSE_MIDDLE);

	nox_mouse.dpos.x = pos.x - nox_mouse_prev.pos.x;
	nox_mouse.dpos.y = pos.y - nox_mouse_prev.pos.y;
	if (nox_mouse.dpos.x * nox_mouse.dpos.x + nox_mouse.dpos.y * nox_mouse.dpos.y >= 4) {
		*getMemU32Ptr(0x5D4594, 805824) = 0;
		*getMemU32Ptr(0x5D4594, 805804) = 0;
	} else {
		++*getMemU32Ptr(0x5D4594, 805824);
		if (*getMemU32Ptr(0x5D4594, 805824) >= 10)
			*getMemU32Ptr(0x5D4594, 805804) = 1;
	}
	if (a2) {
		if (nox_mouse.wheel <= 0) {
			nox_mouse.wheel = nox_mouse.wheel >= 0 ? 0 : 20;
		} else {
			nox_mouse.wheel = 19;
		}
		nox_mouse_prev = nox_mouse;
	}
}

//----- (004306A0) --------------------------------------------------------
int nox_readingMouseBuffer = 0;
void  nox_client_readMouseBuffer_4306A0(int a1) {
	if (nox_readingMouseBuffer) {
		return;
	}
	nox_readingMouseBuffer = 1;
	int n = 0;
	for (int i = 0; i < nox_input_buffer_cap; i++) {
		nox_mouse_state_t* e = &nox_input_buffer[i];
		if (!nox_client_nextMouseEvent_47DB20(e)) {
			break;
		}
		n++;
	}
	nox_client_processMouseEvents_4302A0(n, a1);
	nox_readingMouseBuffer = 0;
	if (n > 0) {
		*getMemU32Ptr(0x5D4594, 805816) = nox_mouse_prev_seq;
	}
}

// init keyboard
void nox_xxx_initKeyboard_47FB10() {
	nox_input_resetBuffers();

	// On non-IME languages, Nox uses this input for text input. This sets up
	// current SHIFT state and the mapping from DIK code -> wide character.
	dword_5d4594_1193132 = nox_input_shiftState();
	nox_xxx_keyboard_47DBD0();
}

void nox_xxx_initKeyboard_yyy();

//----- (00430190) --------------------------------------------------------
int nox_xxx_initInput_430190() {
	nox_xxx_initKeyboard_47FB10();
	nox_xxx_initKeyboard_yyy();
	nox_xxx_initMouse_47D8D0();
	nox_xxx_setMouseBounds_430A70(0, nox_win_width - 1, 0, nox_win_height - 1);
	sub_42EBB0(2u, nox_input_reset_430140, 0, "Input");
	return 1;
}

// SDLMODDED
//----- (0047F950) --------------------------------------------------------
unsigned short nox_input_scanCodeToAlpha_47F950(unsigned short a1) {
	unsigned __int16 result; // ax
	int scrollLockStatus;

	scrollLockStatus = nox_input_scrollLockState();
	if (a1 > 0xFFu)
		return a1;
	if (a1 == 42 || a1 == 54) {
		*getMemU32Ptr(0x5D4594, 1193136) = nox_input_keyboardGetKeyState_430970(a1) == 2;
		return 0;
	}
	if (a1 != 58) {
		if ((_BYTE)a1 == getMemByte(0x5D4594, 1193144)) {
			*getMemU32Ptr(0x5D4594, 1193140) = nox_input_keyboardGetKeyState_430970(a1) == 2;
			result = 0;
		} else if (*getMemU32Ptr(0x5D4594, 1193140)) {
			result = *getMemU16Ptr(0x5D4594, 1191572 + 6*(unsigned __int8)a1 + 4);
		} else if (*getMemU32Ptr(0x5D4594, 1193136) ||
				   dword_5d4594_1193132 && iswalpha(*getMemU16Ptr(0x5D4594, 1191572 + 6*(unsigned __int8)a1))) {

			if (scrollLockStatus) {
				result = asc_9800B0[3 * (unsigned __int8)a1 + 264];
			} else {
				result = *getMemU16Ptr(0x5D4594, 1191572 + 6*(unsigned __int8)a1 + 2);
			}
		} else {
			if (scrollLockStatus) {
				result = asc_9800B0[3 * (unsigned __int8)a1];
			} else {
				result = *getMemU16Ptr(0x5D4594, 1191572 + 6*(unsigned __int8)a1);
			}
		}
		return result;
	}
	if (sub_430950(a1))
		return 0;
	if (nox_input_keyboardGetKeyState_430970(a1) == 2)
		dword_5d4594_1193132 = 1 - dword_5d4594_1193132;
	sub_4309B0(a1, 1);
	return 0;
}

//----- (00430710) --------------------------------------------------------
void nox_xxx_getKeyFromKeyboard_430710() {
	nox_keyboard_btn_t* ev = &nox_input_arr_787228[0];
	unsigned __int8 code;
	do {
		do {
			nox_xxx_getKeyFromKeyboardImpl_47FA80(ev);
			code = ev->code;
		} while (code == -1);
		ev++;
	} while (code);

	int cnt = 0;
	ev = &nox_input_arr_787228[0];
	while (ev->code) {
		if (ev->code == 15) {
			if (nox_input_arr_789276[56].state == 2 || nox_input_arr_789276[184].state == 2) {
				ev->field_2 = 1;
			}
		} else if (ev->code == 58) {
			nox_input_scanCodeToAlpha_47F950(0x3Au);
		}
		if (obj_5D4594_754104_switch == 1) {
			ev->field_2 = 1;
		}
		int code = ev->code;
		nox_input_arr_789276[code].state = ev->state;
		nox_input_arr_789276[code].field_2 = ev->field_2;
		nox_input_arr_789276[code].seq = nox_mouse_prev_seq;
		ev++;
		cnt++;
	}

	if (sub_4307D0() == 1 || cnt != 0) {
		*getMemU32Ptr(0x5D4594, 805816) = nox_mouse_prev_seq;
	}
}

//----- (004307D0) --------------------------------------------------------
int sub_4307D0() {
	if (obj_5D4594_754104_switch == 1)
		return 0;
	int v0 = 0;
	for (v0 = 0; nox_input_arr_787228[v0].code; v0++) {}
	int li = -1;
	for (int i = 0; i < 256; i++) {
		nox_keyboard_btn_t* cur = &nox_input_arr_789276[i];
		if (cur->state == 2 && nox_mouse_prev_seq - cur->seq > 10) {
			li = i;
			break;
		}
	}
	if (li < 0) {
		return 0;
	}
	nox_input_arr_787228[v0].code = li;
	nox_input_arr_787228[v0].state = 2;
	nox_input_arr_787228[v0].field_2 = 0;
	nox_input_arr_787228[v0+1].code = 0;
	for (int i = 0; i < 256; i++) {
		nox_input_arr_789276[i].seq = nox_mouse_prev_seq;
	}
	nox_input_arr_789276[li].seq = nox_mouse_prev_seq - 12;
	return 1;
}
void nox_xxx_initKeyboard_yyy() {
	for (int i = 0; i < 256; i++) {
		nox_keyboard_btn_t* cur = &nox_input_arr_789276[i];
		cur->code = i;
		cur->state = 1;
		cur->field_2 = 0;
		cur->seq = 0;
	}
}

//----- (00430940) --------------------------------------------------------
char* nox_xxx_wndKeyGet_430940() { return &nox_input_arr_787228[0]; }

//----- (00430950) --------------------------------------------------------
unsigned char sub_430950(unsigned char i) { return nox_input_arr_789276[i].field_2; }

//----- (00430970) --------------------------------------------------------
unsigned char nox_input_keyboardGetKeyState_430970(unsigned char i) { return nox_input_arr_789276[i].state; }

//----- (00430990) --------------------------------------------------------
int nox_input_keyboardGetKeySeq_430990(unsigned char i) { return nox_input_arr_789276[i].seq; }

//----- (004308A0) --------------------------------------------------------
int  nox_client_processMouseInput_4308A0(int a1) {
	nox_client_readMouseBuffer_4306A0(a1);
	nox_xxx_getKeyFromKeyboard_430710();
	if (nox_input_arr_787228[0].code) {
		if (!nox_input_arr_787228[0].field_2) {
			OnKeyboardEvent(&nox_input_arr_787228[0]);
		}
	}
	++nox_mouse_prev_seq;
	if (nox_common_gameFlags_check_40A5C0(0x2000) && !nox_common_gameFlags_check_40A5C0(4096) &&
		(unsigned int)(nox_mouse_prev_seq - *getMemU32Ptr(0x5D4594, 805816)) > 0xA8C) {
		if (!nox_common_gameFlags_check_40A5C0(1)) {
			nox_xxx_netServerCmd_440950(0, (wchar_t*)getMemAt(0x587000, 80784));
			return 1;
		}
		if (*getMemU32Ptr(0x8531A0, 2576))
			nox_xxx_serverHandleClientConsole_443E90(*getMemIntPtr(0x8531A0, 2576), 0, (wchar_t*)getMemAt(0x587000, 80792));
	}
	return 1;
}

//----- (004309B0) --------------------------------------------------------
void sub_4309B0(unsigned char i, unsigned char v) {
	nox_input_arr_789276[i].field_2 = v;
}

//----- (004309F0) --------------------------------------------------------
nox_point nox_client_getMousePos_4309F0() { return nox_mouse.pos; }
nox_mouse_state_t* nox_client_getMouseState_4309F0() { return &nox_mouse; }

//----- (00430B40) --------------------------------------------------------
int nox_xxx_bookGet_430B40_get_mouse_prev_seq() { return nox_mouse_prev_seq; }

//----- (00430A00) --------------------------------------------------------
void nox_client_changeMousePos_430A00(int x, int y, bool isAbs) {
	nox_point p;
	p.x = x;
	p.y = y;

	if (!isAbs) {
		p.x += nox_mouse.pos.x;
		p.y += nox_mouse.pos.y;
	}

	if (p.x > nox_mouse_max.x)
		p.x = nox_mouse_max.x;

	if (p.x < nox_mouse_min.x)
		p.x = nox_mouse_min.x;

	if (p.y > nox_mouse_max.y)
		p.y = nox_mouse_max.y;

	if (p.y < nox_mouse_min.y)
		p.y = nox_mouse_min.y;

	nox_mouse.pos = p;
}

//----- (00430A70) --------------------------------------------------------
void nox_xxx_setMouseBounds_430A70(int x_min, int x_max, int y_min, int y_max) {
	nox_mouse_min.x = x_min;
	nox_mouse_min.y = y_min;
	nox_mouse_max.x = x_max;
	nox_mouse_max.y = y_max;
}

//----- (0042D220) --------------------------------------------------------
void nox_xxx_input_42D220() {
	int v0;      // ebx
	int v2;      // esi
	int* v3;     // edi
	int v4;      // ebx
	int v10;     // edx
	_DWORD* v11; // ebp
	int v12;     // esi
	int v13;     // edx
	int v14;     // eax
	_DWORD* v15; // ecx
	int v16;     // ecx
	int i;       // eax
	int v19;     // [esp+10h] [ebp-Ch]
	int v20;     // [esp+10h] [ebp-Ch]
	int v21;     // [esp+14h] [ebp-8h]

	v0 = 0;
	v21 = 0;
	nox_mouse_state_t* mouse = nox_client_getMouseState_4309F0();
	v2 = dword_5d4594_754056;
	if (v2) {
		while (1) {
			v19 = 0;
			if (*(_DWORD*)(v2 + 32) > 0) {
				v3 = (int*)v2;
				while (1) {
					v4 = *v3;
					if (!(*v3 & 0xFFFF0000)) {
						if (nox_xxx_wndGetFocus_46B4F0() || sub_46A4A0() || nox_input_keyboardGetKeyState_430970(v4) == 1) {
							break;
						}
						if (sub_430950(v4) == 1) {
							break;
						}
					} else if (v4 & 0x10000 && getMemByte(0x5D4594, 747848) != 2) {
						if (v4 == 65536) {
							int btn = NOX_MOUSE_LEFT;
							int state = mouse->btn[btn].state;
							if (state != nox_mouse_state(btn, NOX_MOUSE_DOWN) && state != nox_mouse_state(btn, NOX_MOUSE_PRESSED)) {
								break;
							}
							if (state == nox_mouse_state(btn, NOX_MOUSE_PRESSED) && *(_DWORD*)(v2 + 36) == 1) {
								break;
							}
						} else if (v4 == 65537) {
							int btn = NOX_MOUSE_MIDDLE;
							int state = mouse->btn[btn].state;
							if (state != nox_mouse_state(btn, NOX_MOUSE_DOWN) && state != nox_mouse_state(btn, NOX_MOUSE_PRESSED)) {
								break;
							}
							if (state == nox_mouse_state(btn, NOX_MOUSE_PRESSED) && *(_DWORD*)(v2 + 36) == 1) {
								break;
							}
						} else if (v4 == 65538) {
							int btn = NOX_MOUSE_RIGHT;
							int state = mouse->btn[NOX_MOUSE_RIGHT].state;
							if (state != nox_mouse_state(btn, NOX_MOUSE_DOWN) && state != nox_mouse_state(btn, NOX_MOUSE_PRESSED)) {
								break;
							}
							if (state == nox_mouse_state(btn, NOX_MOUSE_PRESSED) && *(_DWORD*)(v2 + 36) == 1) {
								break;
							}
						} else if (v4 == 65539) {
							if (mouse->wheel != 19) {
								break;
							}
						} else if (v4 == 65540) {
							if (mouse->wheel != 20) {
								break;
							}
						}
					} else if (v4 & 0x20000 && (getMemByte(0x5D4594, 750956) || !((1 << v4) & *getMemU32Ptr(0x5D4594, 747844)))) {
						break;
					}
					++v3;
					if (++v19 >= *(int*)(v2 + 32)) {
						break;
					}
				}
			}
			if (v19 == *(_DWORD*)(v2 + 32)) {
				v10 = v21;
				v21 = v2;
				*(_DWORD*)(v2 + 80) = v10;
				*(_BYTE*)(v2 + 88) = 1;
			}
			v2 = *(_DWORD*)(v2 + 76);
			if (!v2) {
				v0 = v21;
				break;
			}
		}
	}
	if (v0) {
		for ( ;v0; v0 = *(_DWORD*)(v0 + 80)) {
			if (!*(_BYTE*)(v0 + 88)) {
				continue;
			}
			v20 = 0;
			if (*(_DWORD*)(v0 + 32) <= 0) {
				continue;
			}
			v11 = (_DWORD*)v0;
			while (v20 < *(int*)(v0 + 32)) {
				v12 = v21;
				do {
					if (*(_BYTE*)(v12 + 88) && v12 != v0) {
						v13 = *(_DWORD*)(v12 + 32);
						v14 = 0;
						if (v13 > 0) {
							v15 = (_DWORD*)v12;
							while (v14 >= v13) {
								if (*v11 == *v15) {
									if (*(int*)(v0 + 32) >= v13)
										*(_BYTE*)(v12 + 88) = 0;
									else
										*(_BYTE*)(v0 + 88) = 0;
									break;
								}
								++v14;
								++v15;
							}
						}
					}
					v12 = *(_DWORD*)(v12 + 80);
				} while (v12);
				++v11;
				++v20;
			}
		}
		v0 = v21;
	}
	v16 = 0;
	for (i = v0; i; i = *(_DWORD*)(i + 80)) {
		if (*(_BYTE*)(i + 88)) {
			*(_DWORD*)(i + 84) = v16;
			v16 = i;
			*(_DWORD*)(i + 92) = nox_frame_xxx_2598000;
		}
	}
	nox_xxx_clientControl_42D6B0(mouse, v16);
	nox_xxx_netBuf_42D510();
}
