#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#include <emscripten/html5.h>
#endif

#include "client/io/console.h"

#include "proto.h"

extern int nox_win_width;
extern int nox_win_height;

#ifdef USE_SDL
#include "sdl2_scancode_to_dinput.h"
extern _DWORD dword_5d4594_1193132;

enum {
	MOUSE_MOTION,
	MOUSE_BUTTON0,
	MOUSE_BUTTON1,
	MOUSE_BUTTON2,
};

struct keyboard_event {
	BYTE code;
	BYTE state;
	DWORD seq;
};

struct mouse_event {
	unsigned int type;
	int x, y, z;
	DWORD state;
	DWORD seq;
};

struct finger_state {
	SDL_FingerID id;
	unsigned int timestamp;
	float x, y;
};

extern int g_rotated;
float input_sensitivity = 1.0;
static struct keyboard_event keyboard_event_queue[256];
static DWORD keyboard_event_ridx;
static DWORD keyboard_event_widx;
static struct mouse_event mouse_event_queue[256];
static DWORD mouse_event_ridx;
static DWORD mouse_event_widx;
static struct finger_state fingers[8];
static int mouse1_state;
static int seqnum;
#ifdef __EMSCRIPTEN__
static int mouse0_state;
static int orientation;
static int move_speed;
static int jump;
#endif
int g_mouse_aquired = 0;

int is_mouse_inside(HWND wnd) {
#ifdef __EMSCRIPTEN__
	return 1;
#else
	int mouseX, mouseY;
	int wndPosX, wndPosY;
	int wndSizeW, wndSizeH;
	SDL_GetGlobalMouseState(&mouseX, &mouseY);
	SDL_GetWindowPosition(wnd, &wndPosX, &wndPosY);
	SDL_GetWindowSize(wnd, &wndSizeW, &wndSizeH);

	if (mouseX >= wndPosX && mouseX <= wndPosX + wndSizeW && mouseY >= wndPosY && mouseY <= wndPosY + wndSizeH) {
		return 1;
	}
	return 0;
#endif
}

void process_window_event(const SDL_WindowEvent* event) {
	switch (event->event) {
	case SDL_WINDOWEVENT_FOCUS_LOST:
		unacquireMouse_sub_47D8B0();
		break;
	case SDL_WINDOWEVENT_FOCUS_GAINED:
		if (is_mouse_inside(getWindowHandle_sub_401FD0()))
			acquireMouse_sub_47D8C0();
		break;
	default:
		break;
	}
}

void process_keyboard_event(const SDL_KeyboardEvent* event) {
	struct keyboard_event* ke = &keyboard_event_queue[keyboard_event_widx];

	ke->code = scanCodeToKeyNum[event->keysym.scancode];
	ke->state = event->state == SDL_PRESSED;
	ke->seq = seqnum++;

	keyboard_event_widx = (keyboard_event_widx + 1) % 256;
}

void process_mouse_event(const SDL_MouseButtonEvent* event) {
	struct mouse_event* me = &mouse_event_queue[mouse_event_widx];

	switch (event->button) {
	case SDL_BUTTON_LEFT:
		me->type = MOUSE_BUTTON0;
		break;
	case SDL_BUTTON_RIGHT:
		me->type = MOUSE_BUTTON1;
		break;
	case SDL_BUTTON_MIDDLE:
		me->type = MOUSE_BUTTON2;
		break;
	default:
		return;
	}

	me->state = event->state == SDL_PRESSED;

	if (me->state) {
		SDL_WindowEvent wndEvt;
		wndEvt.event = SDL_WINDOWEVENT_FOCUS_GAINED;
		process_window_event(&wndEvt);
	}

	me->seq = seqnum++;

	mouse_event_widx = (mouse_event_widx + 1) % 256;
}

void process_motion_event(const SDL_MouseMotionEvent* event) {
	struct mouse_event* me = &mouse_event_queue[mouse_event_widx];

	me->type = MOUSE_MOTION;
	me->x = input_sensitivity * event->xrel;
	me->y = input_sensitivity * event->yrel;
	me->z = 0;
	me->seq = seqnum++;

	mouse_event_widx = (mouse_event_widx + 1) % 256;
}

void process_wheel_event(const SDL_MouseWheelEvent* event) {
	struct mouse_event* me = &mouse_event_queue[mouse_event_widx];

	me->type = MOUSE_MOTION;
	me->x = 0;
	me->y = 0;
	me->z = event->y;
	me->seq = seqnum++;

	mouse_event_widx = (mouse_event_widx + 1) % 256;
}

void fake_keyup(void* arg) {
	struct keyboard_event* ke = &keyboard_event_queue[keyboard_event_widx];
	ke->code = scanCodeToKeyNum[SDL_SCANCODE_SPACE];
	ke->state = 0;
	ke->seq = seqnum++;
	keyboard_event_widx = (keyboard_event_widx + 1) % 256;
}

void fake_mouseup(void* arg) {
	struct mouse_event* me = &mouse_event_queue[mouse_event_widx];
	me->type = MOUSE_BUTTON0;
	me->state = 0;
	me->seq = seqnum++;
	mouse_event_widx = (mouse_event_widx + 1) % 256;
}

struct finger_state* find_finger(SDL_FingerID id, int alloc) {
	int i;
	for (i = 0; i < sizeof(fingers) / sizeof(fingers[0]); i++) {
		if (fingers[i].id == id)
			return &fingers[i];

		if (alloc && fingers[i].id == 0) {
			fingers[i].id = id;
			return &fingers[i];
		}
	}
	return NULL;
}

void send_mouse1_event() {
	struct mouse_event* me = &mouse_event_queue[mouse_event_widx];
	me->type = MOUSE_BUTTON1;
	me->state = mouse1_state; // && !mouse0_state;
	me->seq = seqnum++;
	mouse_event_widx = (mouse_event_widx + 1) % 256;
}

#ifdef __EMSCRIPTEN__
void sub_42D6B0_em_not_mouse_down() {
	sub_42E670(1, orientation);
	if (move_speed)
		sub_42E670(2, 3);
	if (jump) {
		sub_42E670(2, 3);
		sub_42E670(7, 0);
		jump = 0;
	}
}

void process_touch_event(SDL_TouchFingerEvent* event) {
	if (g_rotated) {
		float tmp = event->x;
		event->x = 1.0 - event->y;
		event->y = tmp;

		tmp = event->dx;
		event->dx = -event->dy;
		event->dy = tmp;
	}

	if (event->type == SDL_FINGERDOWN) {
		struct finger_state* finger = find_finger(event->fingerId, 1);
		finger->timestamp = event->timestamp;
		finger->x = event->x;
		finger->y = event->y;

		if (finger->x < 0.5) {
			mouse1_state = 1;
			// send_mouse1_event();
		} else {
			mouse0_state = 1;
			// send_mouse1_event();
		}
#if 0
    else if (finger->y < 0.25)
    {
        struct keyboard_event* ke = &keyboard_event_queue[keyboard_event_widx];
        ke->code = scanCodeToKeyNum[SDL_SCANCODE_SPACE];
        ke->state = 1;
        ke->seq = event->timestamp;
        keyboard_event_widx = (keyboard_event_widx + 1) % 256;
    }
    else
    {
        struct mouse_event* me = &mouse_event_queue[mouse_event_widx];
        me->type = MOUSE_BUTTON0;
        me->state = 1;
        me->seq = event->timestamp;
        mouse_event_widx = (mouse_event_widx + 1) % 256;
    }
#endif
	} else if (event->type == SDL_FINGERUP) {
		unsigned int ms;
		float dist, theta;
		struct finger_state* finger = find_finger(event->fingerId, 0);
		if (!finger)
			return;

		dist = sqrtf((event->x - finger->x) * (event->x - finger->x) + (event->y - finger->y) * (event->y - finger->y));
		theta = atan2f(-event->y + finger->y, -event->x + finger->x) / M_PI;
		ms = event->timestamp - finger->timestamp;

		if (finger->x < 0.5) {
			mouse1_state = 0;
			// send_mouse1_event();

			move_speed = 0;

			if (ms < 250 && dist > 0.1)
				jump = 1;

			printf("%d\n", event->timestamp - finger->timestamp);
		} else {
			mouse0_state = 0;
			// send_mouse1_event();

			if (ms < 500 && dist > 0.1 && theta <= 0.7 && theta >= 0.3) {
				struct keyboard_event* ke = &keyboard_event_queue[keyboard_event_widx];
				ke->code = scanCodeToKeyNum[SDL_SCANCODE_SPACE];
				ke->state = 1;
				ke->seq = seqnum++;
				keyboard_event_widx = (keyboard_event_widx + 1) % 256;

				emscripten_set_timeout(fake_keyup, 90, NULL);
			} else {
				struct mouse_event* me = &mouse_event_queue[mouse_event_widx];
				me->type = MOUSE_BUTTON0;
				me->state = 1;
				me->seq = seqnum++;
				mouse_event_widx = (mouse_event_widx + 1) % 256;

				emscripten_set_timeout(fake_mouseup, 90, NULL);
			}
		}

		printf("up dist=%4d, theta=%4d\n", (int)(dist * 1000), (int)(theta * 1000));

		memset(finger, 0, sizeof(*finger));
	} else {
		unsigned int ms;
		float dist, theta;
		struct finger_state* finger = find_finger(event->fingerId, 0);
		if (!finger)
			return;

		dist = sqrtf((event->x - finger->x) * (event->x - finger->x) + (event->y - finger->y) * (event->y - finger->y));
		theta = atan2f(-event->y + finger->y, -event->x + finger->x) / M_PI;
		ms = event->timestamp - finger->timestamp;

		if (finger->x < 0.5) {
			dist = sqrtf((event->x - 0.1) * (event->x - 0.1) + (event->y - 0.5) * (event->y - 0.5));
			theta = atan2f(-event->y + 0.5, -event->x + 0.1) / M_PI;
#if 0
            struct mouse_event* me = &mouse_event_queue[mouse_event_widx];
            me->type = MOUSE_MOTION;
            me->x = 2000.0f * event->dx;
            me->y = 2000.0f * event->dy;
            me->z = 0;
            me->seq = seqnum++;
            mouse_event_widx = (mouse_event_widx + 1) % 256;
#endif
			orientation = ((int)((theta + 1) * 128 + 0.5)) & 255;
			if (dist < 0.05)
				move_speed = 0;
			else
				move_speed = 1;
		} else if ((event->timestamp - finger->timestamp) > 200) {
			struct mouse_event* me = &mouse_event_queue[mouse_event_widx];
			me->type = MOUSE_MOTION;
			me->x = 2000.0f * event->dx;
			me->y = 2000.0f * event->dy;
			me->z = 0;
			me->seq = seqnum++;
			mouse_event_widx = (mouse_event_widx + 1) % 256;
		}
	}
}
#endif

// init keyboard
void sub_47FB10() {
	keyboard_event_ridx = 0;
	keyboard_event_widx = 0;

	// On non-IME languages, Nox uses this input for text input. This sets up
	// current SHIFT state and the mapping from DIK code -> wide character.
	dword_5d4594_1193132 = (SDL_GetModState() & (KMOD_LSHIFT | KMOD_RSHIFT)) != 0;
	sub_47DBD0();
}

// SDLMODDED
//----- (0047F950) --------------------------------------------------------
unsigned __int16 __cdecl sub_47F950(unsigned __int16 a1) {
	unsigned __int16 result; // ax
	int scrollLockStatus;

	scrollLockStatus = ((SDL_GetModState() & KMOD_RALT) == (KMOD_RALT));
	if (a1 > 0xFFu)
		return a1;
	if (a1 == 42 || a1 == 54) {
		*getMemU32Ptr(0x5D4594, 1193136) = sub_430970(a1) == 2;
		return 0;
	}
	if (a1 != 58) {
		if ((_BYTE)a1 == getMemByte(0x5D4594, 1193144)) {
			*getMemU32Ptr(0x5D4594, 1193140) = sub_430970(a1) == 2;
			result = 0;
		} else if (*getMemU32Ptr(0x5D4594, 1193140)) {
			result = *getMemU16Ptr(0x5D4594, 6 * (unsigned __int8)a1 + 1191576);
		} else if (*getMemU32Ptr(0x5D4594, 1193136) ||
				   dword_5d4594_1193132 && iswalpha(*getMemU16Ptr(0x5D4594, 6 * (unsigned __int8)a1 + 1191572))) {

			if (scrollLockStatus) {
				result = asc_9800B0[3 * (unsigned __int8)a1 + 0x108];
			} else {
				result = *getMemU16Ptr(0x5D4594, 6 * (unsigned __int8)a1 + 1191574);
			}
		} else {
			if (scrollLockStatus) {
				result = asc_9800B0[3 * (unsigned __int8)a1];
			} else {
				result = *getMemU16Ptr(0x5D4594, 6 * (unsigned __int8)a1 + 1191572);
			}
		}
		return result;
	}
	if (sub_430950(a1))
		return 0;
	if (sub_430970(a1) == 2)
		dword_5d4594_1193132 = 1 - dword_5d4594_1193132;
	sub_4309B0(a1, 1);
	return 0;
}

// free keyboard
int sub_47FCC0() { return 0; }

// get keyboard data
void __cdecl sub_47FA80(signed int a1) {
	struct keyboard_event* ke = &keyboard_event_queue[keyboard_event_ridx];

	*(_BYTE*)a1 = 0;
	*(_DWORD*)(a1 + 4) = 0;

	if (keyboard_event_ridx == keyboard_event_widx)
		return;

	*(_BYTE*)a1 = ke->code;
	*(_BYTE*)(a1 + 1) = ke->state + 1;
	*(_BYTE*)(a1 + 2) = 0;
	*(_DWORD*)(a1 + 4) = ke->seq;

	keyboard_event_ridx = (keyboard_event_ridx + 1) % 256;
}

// init mouse
int initMouse_sub_47D8D0() {
#ifndef NOX_NO_MOUSE_GRAB
	SDL_SetWindowGrab(getWindowHandle_sub_401FD0(), SDL_TRUE);
	SDL_SetRelativeMouseMode(SDL_TRUE);
#endif

	g_mouse_aquired = 1;

	mouse_event_ridx = 0;
	mouse_event_widx = 0;

	// indicates that mouse is present so cursor should be drawn
	*getMemU32Ptr(0x5D4594, 1193108) = 1;
	return 1;
}

// acquire mouse
int acquireMouse_sub_47D8C0() {
	if (!g_mouse_aquired) {
#ifndef NOX_NO_MOUSE_GRAB
		SDL_SetWindowGrab(getWindowHandle_sub_401FD0(), SDL_TRUE);
		SDL_SetRelativeMouseMode(SDL_TRUE);
#endif
		g_mouse_aquired = 1;
	}
	return 0;
}

// unacquire mouse
int unacquireMouse_sub_47D8B0() {
	SDL_SetRelativeMouseMode(SDL_FALSE);
	SDL_SetWindowGrab(getWindowHandle_sub_401FD0(), SDL_FALSE);
	g_mouse_aquired = 0;
	return 0;
}

typedef struct DIDEVICEOBJECTDATA {
	DWORD dwOfs;
	DWORD dwData;
	DWORD dwTimeStamp;
	DWORD dwSequence;
	UINT_PTR uAppData;
} DIDEVICEOBJECTDATA, *LPDIDEVICEOBJECTDATA;

// get mouse data
char __cdecl sub_47DB20_get_mouse_data(nox_mouse_state_t* e) {
	struct mouse_event* me = &mouse_event_queue[mouse_event_ridx];

	e->pos.x = 0;
	e->pos.y = 0;
	e->z = 0;
	e->left_state = 0;
	e->left_seq = 0;
	e->right_state = 0;
	e->right_seq = 0;
	e->middle_state = 0;
	e->middle_seq = 0;

	if (mouse_event_ridx == mouse_event_widx)
		return 0;

	switch (me->type) {
	case MOUSE_MOTION:
		e->pos.x = me->x;
		e->pos.y = me->y;
		e->z = me->z;
		DIDEVICEOBJECTDATA data;
		data.dwData = me->z;
		OnLibraryNotice(265, &e, 2, &data);
		break;
	case MOUSE_BUTTON0:
		e->left_state = me->state;
		e->left_seq = me->seq;
		break;
	case MOUSE_BUTTON1:
		e->right_state = me->state;
		e->right_seq = me->seq;
		break;
	case MOUSE_BUTTON2:
		e->middle_state = me->state;
		e->middle_seq = me->seq;
		break;
	}

	mouse_event_ridx = (mouse_event_ridx + 1) % 256;
	return 1;
}

// init joystick
UINT __cdecl sub_47D660(UINT uJoyID, int a2) { return 0; }

#else

void __cdecl sub_47DA70(_DWORD* a1, LPDIDEVICEOBJECTDATA a2);

LPDIRECTINPUTA g_dinput_keyboard;
LPDIRECTINPUTDEVICEA g_device_keyboard;

LPDIRECTINPUTA g_dinput_mouse;
LPDIRECTINPUTDEVICEA g_device_mouse;

//----- (0047D8B0) --------------------------------------------------------
int unacquireMouse_sub_47D8B0() { return g_device_mouse->lpVtbl->Unacquire(g_device_mouse); }

//----- (0047D8C0) --------------------------------------------------------
int acquireMouse_sub_47D8C0() { return g_device_mouse->lpVtbl->Acquire(g_device_mouse); }

//----- (0047D8D0) --------------------------------------------------------
signed int initMouse_sub_47D8D0() {
	wchar_t* v0;    // eax
	DIPROPDWORD v4; // [esp+20h] [ebp-2Ch]
	DIDEVCAPS_DX3 v9;

	if (DirectInputCreateA(*(HINSTANCE*)getMemAt(0x5D4594, 823784), 0x300u, &g_dinput_mouse, 0) < 0) {
		v0 = loadString_sub_40F1D0("Dxinput.c:IM_CreateFailed", 0,
								   (int)"C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c", 73);
		sub_4516C0(v0);
	}
	if (g_dinput_mouse->lpVtbl->CreateDevice(g_dinput_mouse, &GUID_SysMouse, &g_device_mouse, 0) < 0) {
		v0 = loadString_sub_40F1D0("Dxinput.c:IM_CreateDeviceFailed", 0,
								   (int)"C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c", 87);
		sub_4516C0(v0);
	}
	if (g_device_mouse->lpVtbl->SetCooperativeLevel(g_device_mouse, getWindowHandle_sub_401FD0(),
													DISCL_BACKGROUND | DISCL_NONEXCLUSIVE) < 0) {
		v0 = loadString_sub_40F1D0("Dxinput.c:IM_SetCoopFailed", 0,
								   (int)"C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c", 105);
		sub_4516C0(v0);
	}
	v4.diph.dwSize = 20;
	v4.diph.dwHeaderSize = 16;
	v4.diph.dwObj = 0;
	v4.diph.dwHow = 0;
	v4.dwData = 256;
	if (g_device_mouse->lpVtbl->SetProperty(g_device_mouse, DIPROP_BUFFERSIZE, (LPCDIPROPHEADER)&v4) < 0) {
		v0 = loadString_sub_40F1D0("Dxinput.c:IM_SetPropertyFailed", 0,
								   (int)"C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c", 123);
		sub_4516C0(v0);
	}
	if (g_device_mouse->lpVtbl->SetDataFormat(g_device_mouse, &c_dfDIMouse) < 0) {
		v0 = loadString_sub_40F1D0("Dxinput.c:IM_SetFormatFailed", 0,
								   (int)"C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c", 135);
		sub_4516C0(v0);
	}
	if (g_device_mouse->lpVtbl->Acquire(g_device_mouse) < 0) {
		v0 = loadString_sub_40F1D0("Dxinput.c:IM_AquireFailed", 0,
								   (int)"C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c", 147);
		sub_4516C0(v0);
	}
	v9.dwSize = 24;
	if (g_device_mouse->lpVtbl->GetCapabilities(g_device_mouse, (LPDIDEVCAPS)&v9) >= 0)
		*getMemU8Ptr(0x5D4594, 1193128) = v9.dwButtons;
	*getMemU32Ptr(0x5D4594, 1193108) = 1;
	sub_42EBB0(2, sub_47D890, 0, "DXInput");
	sub_42EBB0(1, sub_47D8A0, 0, "DXInput");
	return 1;
}
// 47D890: using guessed type int sub_47D890();

//----- (0047DA70) --------------------------------------------------------
void __cdecl sub_47DA70(_DWORD* a1, LPDIDEVICEOBJECTDATA a2) {
	switch (a2->dwOfs) {
	case DIMOFS_X:
		*a1 = a2->dwData;
		break;
	case DIMOFS_Y:
		a1[1] = a2->dwData;
		break;
	case DIMOFS_Z:
		OnLibraryNotice(265, &a1, 2, a2);
		a1[2] = a2->dwData;
		break;
	case DIMOFS_BUTTON0:
		a1[5] = (a2->dwData >> 7) & 1;
		a1[7] = a2->dwSequence;
		break;
	case DIMOFS_BUTTON1:
		a1[8] = (a2->dwData >> 7) & 1;
		a1[10] = a2->dwSequence;
		break;
	case DIMOFS_BUTTON2:
		a1[11] = (a2->dwData >> 7) & 1;
		a1[13] = a2->dwSequence;
		break;
	default:
		return;
	}
}

//----- (0047DB20) --------------------------------------------------------
char __cdecl sub_47DB20(signed int* a1) {
	HRESULT v2;            // eax
	HRESULT v4;            // eax
	DIDEVICEOBJECTDATA v5; // [esp+14h] [ebp-10h]
	DWORD dw;

	a1[0] = 0;
	a1[1] = 0;
	a1[2] = 0;
	a1[5] = 0;
	a1[7] = 0;
	a1[8] = 0;
	a1[10] = 0;
	a1[11] = 0;
	a1[13] = 0;

	if (g_device_mouse) {
		dw = 1;
		v2 = g_device_mouse->lpVtbl->GetDeviceData(g_device_mouse, 16, &v5, &dw, 0);
		if (v2 == DIERR_NOTACQUIRED || v2 == DIERR_INPUTLOST) {
			v4 = g_device_mouse->lpVtbl->Acquire(g_device_mouse);
			if (v4 >= 0 && v4 <= 1)
				return -1;
		} else if (!v2 && dw) {
			sub_47DA70(a1, &v5);
			return 1;
		}
	}
	return 0;
}

//----- (0047D660) --------------------------------------------------------
UINT __cdecl sub_47D660(UINT uJoyID, int a2) {
	UINT result;              // eax
	UINT v3;                  // esi
	wchar_t* v4;              // eax
	__int64 v5;               // rax
	__int64 v6;               // [esp+10h] [ebp-3Ch]
	struct joyinfoex_tag pji; // [esp+18h] [ebp-34h]

	result = joyGetNumDevs();
	if (result) {
		pji.dwSize = 52;
		pji.dwFlags = 255;
		if (joyGetPosEx(uJoyID, &pji)) {
			result = 0;
		} else {
			v3 = 48 * uJoyID;
			*getMemU32Ptr(0x5D4594, v3 + 1189612) = 200;
			*getMemU32Ptr(0x5D4594, v3 + 1189620) = 0;
			*getMemU32Ptr(0x5D4594, v3 + 1189604) = -100;
			*getMemU32Ptr(0x5D4594, v3 + 1189628) = 0;
			*getMemU32Ptr(0x5D4594, v3 + 1189616) = 200;
			*getMemU32Ptr(0x5D4594, v3 + 1189624) = 0;
			*getMemU32Ptr(0x5D4594, v3 + 1189608) = -100;
			*getMemU32Ptr(0x5D4594, v3 + 1189632) = 0;
			if (joyGetDevCapsA(uJoyID, (LPJOYCAPSA)getMemAt(0x5D4594, 404 * uJoyID + 1189700), 0x194u)) {
				v4 = loadString_sub_40F1D0((char*)getMemAt(0x587000, 153832), 0,
										   "C:\\NoxPost\\src\\Client\\Io\\Win95\\Jstick.c", 79);
				sub_4517A0(v4, uJoyID);
				result = 0;
			} else {
				v6 = *getMemUintPtr(0x5D4594, 404 * uJoyID + 1189748);
				*getMemU32Ptr(0x5D4594, 48 * uJoyID + 1189636) =
					(__int64)(200.0 / (double)*getMemUintPtr(0x5D4594, 404 * uJoyID + 1189740) * 1000000.0);
				v5 = (__int64)(200.0 / (double)v6 * 1000000.0);
				HIDWORD(v5) = *getMemU32Ptr(0x5D4594, 404 * uJoyID + 1189760);
				*getMemU32Ptr(0x5D4594, 48 * uJoyID + 1189640) = v5;
				*(_DWORD*)a2 = HIDWORD(v5);
				result = 2;
			}
		}
	}
	return result;
}

//----- (0047D7A0) --------------------------------------------------------
DWORD* __cdecl sub_47D7A0(DWORD* a1, UINT uJoyID) {
	DWORD* result;            // eax
	DWORD v3;                 // ebx
	DWORD v4;                 // edi
	struct joyinfoex_tag pji; // [esp+8h] [ebp-34h]

	pji.dwSize = 52;
	pji.dwFlags = 131;
	if (joyGetPosEx(uJoyID, &pji) == 167) {
		result = a1;
		a1[2] = 0;
		*a1 = 0;
		a1[1] = 0;
	} else {
		a1[2] = pji.dwButtons;
		*a1 = *getMemU32Ptr(0x5D4594, 48 * uJoyID + 1189636) *
			  (pji.dwXpos - *getMemU32Ptr(0x5D4594, 404 * uJoyID + 1189736)) / 0xF4240;
		v3 = *a1;
		a1[1] = *getMemU32Ptr(0x5D4594, 48 * uJoyID + 1189640) *
				(pji.dwYpos - *getMemU32Ptr(0x5D4594, 404 * uJoyID + 1189744)) / 0xF4240;
		v4 = a1[1];
		*a1 = *getMemU32Ptr(0x5D4594, 48 * uJoyID + 1189604) + v3;
		a1[1] = *getMemU32Ptr(0x5D4594, 48 * uJoyID + 1189608) + v4;
		if (*getMemU32Ptr(0x5D4594, 48 * uJoyID + 1189620))
			*a1 = -*a1;
		result = *(DWORD**)getMemAt(0x5D4594, 48 * uJoyID + 1189624);
		if (result)
			a1[1] = -a1[1];
	}
	return result;
}

//----- (0047FB10) --------------------------------------------------------
void sub_47FB10() {
	wchar_t* v0;     // eax
	wchar_t* v1;     // eax
	wchar_t* v2;     // eax
	int v3;          // edi
	HWND v4;         // eax
	wchar_t* v5;     // eax
	wchar_t* v6;     // eax
	wchar_t* v7;     // eax
	DIPROPDWORD v15; // [esp+24h] [ebp-14h]

	if (DirectInputCreateA(*(HINSTANCE*)getMemAt(0x5D4594, 823784), 0x300u, &g_dinput_keyboard, 0) < 0) {
		v0 = loadString_sub_40F1D0("Dxinput.c:OK_CreateFailed", 0, "C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c",
								   827);
		sub_4516C0(v0);
	}

	if (g_dinput_keyboard->lpVtbl->CreateDevice(g_dinput_keyboard, &GUID_SysKeyboard, &g_device_keyboard, NULL) < 0) {
		v1 = loadString_sub_40F1D0("Dxinput.c:OK_CreateDeviceFailed", 0,
								   "C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c", 841);
		sub_4516C0(v1);
	}

	if (g_device_keyboard->lpVtbl->SetDataFormat(g_device_keyboard, &c_dfDIKeyboard) < 0) {
		v2 = loadString_sub_40F1D0("Dxinput.c:OK_SetFormatFailed", 0, "C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c",
								   853);
		sub_4516C0(v2);
	}

	if (g_device_keyboard->lpVtbl->SetCooperativeLevel(g_device_keyboard, getWindowHandle_sub_401FD0(),
													   DISCL_BACKGROUND | DISCL_NONEXCLUSIVE) < 0) {
		v5 = loadString_sub_40F1D0("Dxinput.c:OK_SetCoopFailed", 0, "C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c",
								   868);
		sub_4516C0(v5);
	}

	v15.diph.dwSize = 20;
	v15.diph.dwHeaderSize = 16;
	v15.diph.dwObj = 0;
	v15.diph.dwHow = 0;
	v15.dwData = 256;
	if (g_device_keyboard->lpVtbl->SetProperty(g_device_keyboard, DIPROP_BUFFERSIZE, &v15) < 0) {
		v6 = loadString_sub_40F1D0("Dxinput.c:OK_SetPropertyFailed", 0,
								   "C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c", 886);
		sub_4516C0(v6);
	}

	if (g_device_keyboard->lpVtbl->Acquire(g_device_keyboard) < 0) {
		v7 = loadString_sub_40F1D0("Dxinput.c:OK_AquireFailed", 0, "C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c",
								   899);
		sub_4516C0(v7);
	}

	dword_5d4594_1193132 = GetKeyState(20) & 1;
	dword_5d4594_1193132 = dword_5d4594_1193132;
	sub_47DBD0();
}

// ORIGINAL
//----- (0047F950) --------------------------------------------------------
/*unsigned __int16 __cdecl sub_47F950(unsigned __int16 a1)
{
  unsigned __int16 result; // ax
  int scrollLockStatus;

  scrollLockStatus = GetKeyState(145);
  if ( a1 > 0xFFu )
	return a1;
  if ( a1 == 42 || a1 == 54 )
  {
	*(_DWORD *)getMemAt(0x5D4594, 1193136) = sub_430970(a1) == 2;
	return 0;
  }
  if ( a1 != 58 )
  {
	if ( (_BYTE)a1 == getMemByte(0x5D4594, 1193144) )
	{
	  *(_DWORD *)getMemAt(0x5D4594, 1193140) = sub_430970(a1) == 2;
	  result = 0;
	}
	else if ( *(_DWORD *)getMemAt(0x5D4594, 1193140) )
	{
	  result = *(_WORD *)getMemAt(0x5D4594, 6 * (unsigned __int8)a1 + 1191576);
	}
	else if ( *(_DWORD *)getMemAt(0x5D4594, 1193136)
	   || *(_DWORD *)&dword_5d4594_1193132
	   && iswalpha(*(_WORD *)getMemAt(0x5D4594, 6 * (unsigned __int8)a1 + 1191572)) )
	{

	if (scrollLockStatus)
	{
		result = asc_9800B0[3 * (unsigned __int8)a1 + 0x108];
	}
	else
	{
	  result = *(_WORD *)getMemAt(0x5D4594, 6 * (unsigned __int8)a1 + 1191574);
	}
	}
	else
	{
	if (scrollLockStatus)
	{
		result = asc_9800B0[3 * (unsigned __int8)a1];
	}
	else
	{
		result = *(_WORD *)getMemAt(0x5D4594, 6 * (unsigned __int8)a1 + 1191572);
	}
	}
	return result;
  }
  if ( sub_430950(a1) )
	return 0;
  if ( sub_430970(a1) == 2 )
	*(_DWORD *)&dword_5d4594_1193132 = 1 - *(_DWORD *)&dword_5d4594_1193132;
  sub_4309B0(a1, 1);
  return 0;
}*/

//----- (0047FCC0) --------------------------------------------------------
int sub_47FCC0() {
	g_device_keyboard->lpVtbl->Unacquire(g_device_keyboard);
	return g_dinput_keyboard->lpVtbl->Release(g_dinput_keyboard);
}

//----- (0047FA80) --------------------------------------------------------
void __cdecl sub_47FA80(signed int a1) {
	HRESULT v2;            // eax
	char v3;               // al
	char v4;               // dl
	HRESULT v5;            // eax
	DIDEVICEOBJECTDATA v6; // [esp+14h] [ebp-10h]
	DWORD dw;

	*(_BYTE*)a1 = 0;
	*(_DWORD*)(a1 + 4) = 0;
	if (g_device_keyboard) {
		dw = 1;
		v2 = g_device_keyboard->lpVtbl->GetDeviceData(g_device_keyboard, 16, &v6, &dw, 0);
		if (v2 == DIERR_INPUTLOST) {
			v5 = g_device_keyboard->lpVtbl->Acquire(g_device_keyboard);
			if (v5 >= 0 && v5 <= 1)
				*(_BYTE*)a1 = -1;
		} else if (!v2 && dw) {
			*(_BYTE*)a1 = v6.dwOfs; // key code
			*(_BYTE*)(a1 + 1) = (v6.dwData & 0x80 != 0) + 1;
			*(_BYTE*)(a1 + 2) = 0;
			*(_DWORD*)(a1 + 4) = v6.dwSequence;
		}
	}
}

int sub_47D890() { return unacquireMouse_sub_47D8B0(); }
#endif
