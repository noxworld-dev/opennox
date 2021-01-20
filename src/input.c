#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#include <emscripten/html5.h>
#include "client/system/ctrlevnt.h"
#endif

#include <limits.h>
#include "client/io/console.h"
#include "input.h"

#include "proto.h"

extern int nox_win_width;
extern int nox_win_height;

#ifdef USE_SDL
#include "sdl2_scancode_to_dinput.h"
extern _DWORD dword_5d4594_1193132;
extern int g_textinput;

SDL_GameController *gpad = NULL;
int gpad_ind = -1;

// from imm.c
void process_textediting_event(const SDL_TextEditingEvent* event);
void process_textinput_event(const SDL_TextInputEvent* event);
void process_textinput_keyboard_event(const SDL_KeyboardEvent* event);

enum {
	MOUSE_MOTION,
	MOUSE_WHEEL,
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
	int x, y, wheel;
	int pressed;
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

// size of the actual window
int input_window_width = NOX_DEFAULT_WIDTH;
int input_window_height = NOX_DEFAULT_HEIGHT;
// size of the image that Nox draws
int input_draw_window_width = NOX_DEFAULT_WIDTH;
int input_draw_window_height = NOX_DEFAULT_HEIGHT;
// scale factors calculated from sizes above
float input_scale_width = 1.0;
float input_scale_height = 1.0;

void input_update_scale() {
	input_scale_width = (float)input_draw_window_width / input_window_width;
	input_scale_height = (float)input_draw_window_height / input_window_height;
}

void input_set_win_size(int w, int h) {
	if (w == 0 || h == 0) {
		return;
	}
	input_window_width = w;
	input_window_height = h;
	input_update_scale();
}

void input_set_draw_win_size(int w, int h) {
	if (w == 0 || h == 0) {
		return;
	}
	input_draw_window_width = w;
	input_draw_window_height = h;
	input_update_scale();
}

// input_to_draw_space remaps window position to position on the video buffer
void input_to_draw_space(int* x, int* y) {
	*x = (float)*x * input_scale_width;
	*y = (float)*y * input_scale_height;
}

// input_clamp clamps window coords according to the current screen size.
void input_clamp(int* x, int* y) {
	if (*x < 0) {
		*x = 0;
	}
	if (*y < 0) {
		*y = 0;
	}
	if (input_window_width > 0 && *x > input_window_width) {
		*x = input_window_width;
	}
	if (input_window_height > 0 && *y > input_window_height) {
		*y = input_window_height;
	}
}

// input_clampf clamps window coords according to the current screen size.
void input_clampf(float* x, float* y) {
	if (*x < 0) {
		*x = 0;
	}
	if (*y < 0) {
		*y = 0;
	}
	if (input_window_width > 0 && *x > input_window_width) {
		*x = input_window_width;
	}
	if (input_window_height > 0 && *y > input_window_height) {
		*y = input_window_height;
	}
}

void process_window_event(const SDL_WindowEvent* event) {
	switch (event->event) {
	case SDL_WINDOWEVENT_FOCUS_LOST:
		unacquireMouse_sub_47D8B0();
		break;
	case SDL_WINDOWEVENT_FOCUS_GAINED:
		if (is_mouse_inside(getWindowHandle_nox_xxx_getHWND_401FD0()))
			acquireMouse_sub_47D8C0();
		break;
	default:
		break;
	}
}

struct keyboard_event* nox_newKeyboardEvent() {
	struct keyboard_event* ke = &keyboard_event_queue[keyboard_event_widx];
	ke->seq = seqnum++;
	keyboard_event_widx = (keyboard_event_widx + 1) % 256;
	return ke;
}

struct mouse_event* nox_newMouseEvent() {
	struct mouse_event* me = &mouse_event_queue[mouse_event_widx];
	me->seq = seqnum++;
	mouse_event_widx = (mouse_event_widx + 1) % 256;
	return me;
}

void input_keyboard(SDL_Scancode code, bool pressed) {
	struct keyboard_event* ke = nox_newKeyboardEvent();
	ke->code = scanCodeToKeyNum[code];
	ke->state = pressed;
}

void process_keyboard_event(const SDL_KeyboardEvent* event) {
	input_keyboard(event->keysym.scancode, event->state == SDL_PRESSED);
}

// last mouse coordinates (in window space)
int input_mouse_x = 0;
int input_mouse_y = 0;

// input_mouse_set sets mouse to a specific position in the window space.
void input_mouse_set(int x, int y) {
	input_mouse_x = x;
	input_mouse_y = y;
	input_to_draw_space(&x, &y);

	struct mouse_event* me = nox_newMouseEvent();
	me->type = MOUSE_MOTION;
	me->x = x;
	me->y = y;
	me->wheel = 0;
}

// input_mouse_move moves mouse by a specific amount in the window space.
void input_mouse_move(float dx, float dy) {
	input_mouse_x += dx;
	input_mouse_y += dy;
	// TODO: native support for relative events
	input_mouse_set(input_mouse_x, input_mouse_y);
}

// input_mouse_wheel moves mouse wheel by a specific amount.
void input_mouse_wheel(int dv) {
	int x = input_mouse_x;
	int y = input_mouse_y;
	input_to_draw_space(&x, &y);

	struct mouse_event* me = nox_newMouseEvent();
	me->type = MOUSE_WHEEL;
	me->x = x;
	me->y = y;
	me->wheel = dv;
}

// input_mouse_button_at sets mouse pos to a given position and sets a specified mouse button state.
void input_mouse_button_at(int x, int y, int button, bool pressed) {
	input_mouse_x = x;
	input_mouse_y = y;
	input_to_draw_space(&x, &y);

	struct mouse_event* me = nox_newMouseEvent();
	me->type = button;
	me->x = x;
	me->y = y;
	me->pressed = pressed;
}

// input_mouse_button_at sets a specified mouse button state.
void input_mouse_button(int button, bool pressed) {
	input_mouse_button_at(input_mouse_x, input_mouse_y, button, pressed);
}

void input_mouse_down_at(int x, int y, int button) {
	input_mouse_button_at(x, y, button, true);
}

void input_mouse_up_at(int x, int y, int button) {
	input_mouse_button_at(x, y, button, false);
}

void input_mouse_down(int button) {
	input_mouse_button(button, true);
}

void input_mouse_up(int button) {
	input_mouse_button(button, false);
}

void process_mouse_event(const SDL_MouseButtonEvent* event) {
	bool pressed = event->state == SDL_PRESSED;
	if (pressed) {
		SDL_WindowEvent wndEvt;
		wndEvt.event = SDL_WINDOWEVENT_FOCUS_GAINED;
		process_window_event(&wndEvt);
	}

	int button = 0;
	switch (event->button) {
	case SDL_BUTTON_LEFT:
		button = MOUSE_BUTTON0;
		break;
	case SDL_BUTTON_RIGHT:
		button = MOUSE_BUTTON1;
		break;
	case SDL_BUTTON_MIDDLE:
		button = MOUSE_BUTTON2;
		break;
	default:
		return;
	}
	input_mouse_button_at(event->x, event->y, button, pressed);
}

void process_motion_event(const SDL_MouseMotionEvent* event) {
	input_mouse_set(event->x, event->y);
}

void process_wheel_event(const SDL_MouseWheelEvent* event) {
	input_mouse_wheel(event->y);
}

void fake_keyup(void* arg) {
	input_keyboard(SDL_SCANCODE_SPACE, 0);
}

void fake_mouseup(void* arg) {
	input_mouse_up(MOUSE_BUTTON0);
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
	input_mouse_button(MOUSE_BUTTON1, mouse1_state /* && !mouse0_state */ );
}

float gpad_mouse_speed = 50.0;

nox_point gpad_left = {0};
nox_point gpad_left_dv = {0};
nox_point gpad_right = {0};
nox_point gpad_right_dv = {0};
int gpad_ltrig_v = 0;
int gpad_ltrig_dv = 0;
int gpad_rtrig_v = 0;
int gpad_rtrig_dv = 0;

bool gpad_trig_attack = false;

// acts like a relative mouse pointer
nox_point* gpad_stick_rel = &gpad_right;
bool gpad_stick_rel_running = false;
const float gpad_stick_rel_auto_run = 0.3;

// acts like an absolute mouse pointer
nox_point* gpad_stick_abs = &gpad_left;
nox_pointf gpad_stick_abs_mouse = {0};

bool controller_relative() {
	return abs(gpad_stick_rel->x) > 256 || abs(gpad_stick_rel->y) > 256;
}

nox_pointf controller_relative_pos() {
	nox_pointf p;
	p.x = ((float)gpad_stick_rel->x / SHRT_MAX);
	p.y = ((float)gpad_stick_rel->y / SHRT_MAX);
	return p;
}

void controller_tick() {
	// absolute stick acts as a mouse pointer, os it should move as long as stick has any values
	if (abs(gpad_stick_abs->x) > 256 || abs(gpad_stick_abs->y) > 256) {
		float dx = ((float)gpad_stick_abs->x / SHRT_MAX);
		float dy = ((float)gpad_stick_abs->y / SHRT_MAX);
		if (dx >= 0) {
			gpad_stick_abs_mouse.x += dx*dx * gpad_mouse_speed;
		} else {
			gpad_stick_abs_mouse.x -= dx*dx * gpad_mouse_speed;
		}
		if (dy >= 0) {
			gpad_stick_abs_mouse.y += dy*dy * gpad_mouse_speed;
		} else {
			gpad_stick_abs_mouse.y -= dy*dy * gpad_mouse_speed;
		}
		input_clampf(&gpad_stick_abs_mouse.x, &gpad_stick_abs_mouse.y);
		input_mouse_set(gpad_stick_abs_mouse.x, gpad_stick_abs_mouse.y);
	}
	// automatically start running on a specific threshold on relative stick
	nox_pointf rel = controller_relative_pos();
	float relV = rel.x*rel.x + rel.y*rel.y;
	if (gpad_stick_rel_running) {
		if (relV < gpad_stick_rel_auto_run) {
			input_mouse_up(MOUSE_BUTTON1); // stop running
			gpad_stick_rel_running = false;
		}
	} else {
		if (relV > gpad_stick_rel_auto_run) {
			input_mouse_down(MOUSE_BUTTON1); // start running
			gpad_stick_rel_running = true;
		}
	}
}

void process_gpad_axis_event(const SDL_ControllerAxisEvent* event) {
	int v = event->value;
	switch (event->axis) {
	case SDL_CONTROLLER_AXIS_LEFTX:
		gpad_left_dv.x = v - gpad_left.x;
		gpad_left.x = v;
		break;
	case SDL_CONTROLLER_AXIS_LEFTY:
		gpad_left_dv.y = v - gpad_left.y;
		gpad_left.y = v;
		break;
	case SDL_CONTROLLER_AXIS_RIGHTX:
		gpad_right_dv.x = v - gpad_right.x;
		gpad_right.x = v;
		break;
	case SDL_CONTROLLER_AXIS_RIGHTY:
		gpad_right_dv.y = v - gpad_right.y;
		gpad_right.y = v;
		break;
	case SDL_CONTROLLER_AXIS_TRIGGERLEFT:
		gpad_ltrig_dv = v - gpad_ltrig_v;
		gpad_ltrig_v = v;
		break;
	case SDL_CONTROLLER_AXIS_TRIGGERRIGHT:
		gpad_rtrig_dv = v - gpad_rtrig_v;
		gpad_rtrig_v = v;
		if (gpad_trig_attack) {
			if (gpad_rtrig_dv < 0) {
				input_mouse_up(MOUSE_BUTTON0);
				gpad_trig_attack = false;
			}
		} else {
			if (gpad_rtrig_dv > 0) {
				input_mouse_down(MOUSE_BUTTON0);
				gpad_trig_attack = true;
			}
		}
		break;
	}
}

void process_gpad_button_event(const SDL_ControllerButtonEvent* event) {
	bool pressed = event->state == SDL_PRESSED;
	switch (event->button) {
	// spells are on the dpad
	case SDL_CONTROLLER_BUTTON_DPAD_UP:
		input_keyboard(SDL_SCANCODE_S, pressed);
		break;
	case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
		input_keyboard(SDL_SCANCODE_W, pressed);
		break;
	case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
		input_keyboard(SDL_SCANCODE_A, pressed);
		break;
	case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
		input_keyboard(SDL_SCANCODE_D, pressed);
		break;
	// A is attack/action
	case SDL_CONTROLLER_BUTTON_A: // down button
		input_mouse_button(MOUSE_BUTTON0, pressed);
		break;
	// rest is for bottles
	case SDL_CONTROLLER_BUTTON_B:
		input_keyboard(SDL_SCANCODE_Z, pressed);
		break;
	case SDL_CONTROLLER_BUTTON_X:
		input_keyboard(SDL_SCANCODE_C, pressed);
		break;
	case SDL_CONTROLLER_BUTTON_Y: // up button
		input_keyboard(SDL_SCANCODE_X, pressed);
		break;
	// back is escape
	case SDL_CONTROLLER_BUTTON_BACK:
		input_keyboard(SDL_SCANCODE_ESCAPE, pressed);
		break;
	case SDL_CONTROLLER_BUTTON_GUIDE:
		break;
	// start is inventory
	case SDL_CONTROLLER_BUTTON_START:
		input_keyboard(SDL_SCANCODE_Q, pressed);
		break;
	case SDL_CONTROLLER_BUTTON_LEFTSTICK:
		break;
	case SDL_CONTROLLER_BUTTON_RIGHTSTICK:
		break;
	// left shoulder means run (in abs mode)
	case SDL_CONTROLLER_BUTTON_LEFTSHOULDER:
		input_mouse_button(MOUSE_BUTTON1, pressed);
		break;
	// right shoulder means jump
	case SDL_CONTROLLER_BUTTON_RIGHTSHOULDER:
		input_keyboard(SDL_SCANCODE_SPACE, pressed);
		break;
	}
}

#ifdef __EMSCRIPTEN__
void nox_xxx_clientControl_42D6B0_em_not_mouse_down() {
	nox_ctrlevent_action_42E670(CC_Orientation, orientation);
	if (move_speed)
		nox_ctrlevent_action_42E670(CC_MoveForward, 3);
	if (jump) {
		nox_ctrlevent_action_42E670(CC_MoveForward, 3);
		nox_ctrlevent_action_42E670(CC_Jump, 0);
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
        input_keyboard(SDL_SCANCODE_SPACE, 1);
    }
    else
    {
        input_mouse_button_at(event->x, event->y, MOUSE_BUTTON0, true);
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
				input_keyboard(SDL_SCANCODE_SPACE, 1);
				emscripten_set_timeout(fake_keyup, 90, NULL);
			} else {
				input_mouse_button(MOUSE_BUTTON0, true);
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
            input_mouse_set(event->x, event->y);
#endif
			orientation = ((int)((theta + 1) * 128 + 0.5)) & 255;
			if (dist < 0.05)
				move_speed = 0;
			else
				move_speed = 1;
		} else if ((event->timestamp - finger->timestamp) > 200) {
			input_mouse_set(event->x, event->y);
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
unsigned __int16 __cdecl nox_xxx_conScanCode2Alpha_47F950(unsigned __int16 a1) {
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
void nox_xxx_getKeyFromKeyboardImpl_47FA80(nox_keyboard_btn_t* ev) {
	struct keyboard_event* ke = &keyboard_event_queue[keyboard_event_ridx];

	ev->code = 0;
	ev->seq = 0;

	if (keyboard_event_ridx == keyboard_event_widx)
		return;

	ev->code = ke->code;
	ev->state = ke->state + 1;
	ev->field_2 = 0;
	ev->field_3 = 0;
	ev->seq = ke->seq;

	keyboard_event_ridx = (keyboard_event_ridx + 1) % 256;
}

// init mouse
int initMouse_sub_47D8D0() {
#ifndef NOX_NO_MOUSE_GRAB
	SDL_SetWindowGrab(getWindowHandle_nox_xxx_getHWND_401FD0(), SDL_TRUE);
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
		SDL_SetWindowGrab(getWindowHandle_nox_xxx_getHWND_401FD0(), SDL_TRUE);
		SDL_SetRelativeMouseMode(SDL_TRUE);
#endif
		g_mouse_aquired = 1;
	}
	return 0;
}

// unacquire mouse
int unacquireMouse_sub_47D8B0() {
#ifndef NOX_NO_MOUSE_GRAB
	SDL_SetRelativeMouseMode(SDL_FALSE);
	SDL_SetWindowGrab(getWindowHandle_nox_xxx_getHWND_401FD0(), SDL_FALSE);
#endif
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
BOOL nox_client_nextMouseEvent_47DB20(nox_mouse_state_t* e) {
	memset(e, 0, sizeof(nox_mouse_state_t));
	struct mouse_event* me = &mouse_event_queue[mouse_event_ridx];

	if (mouse_event_ridx == mouse_event_widx)
		return 0;
	e->pos.x = me->x;
	e->pos.y = me->y;

	switch (me->type) {
	case MOUSE_MOTION:
		e->wheel = me->wheel;
		break;
	case MOUSE_WHEEL:
		e->wheel = me->wheel;
		OnLibraryNotice(265, &e, 2, me->wheel); // mix event hanlder is triggered only for wheel events
		break;
	case MOUSE_BUTTON0:
		e->btn[NOX_MOUSE_LEFT].pressed = me->pressed;
		e->btn[NOX_MOUSE_LEFT].seq = me->seq;
		break;
	case MOUSE_BUTTON1:
		e->btn[NOX_MOUSE_RIGHT].pressed = me->pressed;
		e->btn[NOX_MOUSE_RIGHT].seq = me->seq;
		break;
	case MOUSE_BUTTON2:
		e->btn[NOX_MOUSE_MIDDLE].pressed = me->pressed;
		e->btn[NOX_MOUSE_MIDDLE].seq = me->seq;
		break;
	}

	mouse_event_ridx = (mouse_event_ridx + 1) % 256;
	return 1;
}

// init joystick
UINT __cdecl nox_xxx_initJoystick_47D660(UINT uJoyID, int a2) { return 0; }

void cleanupControllers() {
	if (gpad) { // Close if opened
		SDL_GameControllerClose(gpad);
		gpad = NULL;
		gpad_ind = -1;
	}
}

void process_gpad_device_event(const SDL_ControllerDeviceEvent* event) {
	int i = event->which;
	if (event->type == SDL_CONTROLLERDEVICEREMOVED) {
		if (i != gpad_ind) {
			return;
		}
		printf("Closed controller %d\n", i);
		SDL_GameControllerClose(gpad);
		gpad = NULL;
		gpad_ind = -1;
		// TODO: check if other devices are still available
		return;
	}
	if (!SDL_IsGameController(i)) {
		return;
	}
	const char* name = SDL_GameControllerNameForIndex(i);
	printf("Game controller connected %d: %s\n", i, name);
	if (gpad) {
		return; // already have one
	}
	gpad = SDL_GameControllerOpen(i);
	if (!gpad) {
		fprintf(stderr, "ERROR: Could not open gamecontroller %i: %s\n", i, SDL_GetError());
	} else {
		gpad_ind = i;
		printf("Opened controller %d\n", i);
	}
}

void input_events_tick() {
	controller_tick();
}

void process_event(const SDL_Event* event) {
	switch (event->type) {
		case SDL_TEXTEDITING:
			process_textediting_event(&event->edit);
			break;
		case SDL_TEXTINPUT:
			process_textinput_event(&event->text);
			break;
		case SDL_KEYDOWN:
		case SDL_KEYUP:
			if (g_textinput)
				process_textinput_keyboard_event(&event->key);
			else
				process_keyboard_event(&event->key);
			break;
		case SDL_MOUSEBUTTONDOWN:
		case SDL_MOUSEBUTTONUP:
			process_mouse_event(&event->button);
			break;
		case SDL_MOUSEMOTION:
			process_motion_event(&event->motion);
			break;
		case SDL_MOUSEWHEEL:
			process_wheel_event(&event->wheel);
			break;
		case SDL_CONTROLLERAXISMOTION:
			printf("SDL event: SDL_CONTROLLERAXISMOTION (%x): joy=%d, axis=%d, val=%d\n",
				   event->type, (int)event->caxis.which, (int)event->caxis.axis, (int)event->caxis.value);
			process_gpad_axis_event(&event->caxis);
			break;
		case SDL_CONTROLLERBUTTONDOWN:
		case SDL_CONTROLLERBUTTONUP:
			printf("SDL event: SDL_CONTROLLERBUTTON (%x): joy=%d, btn=%d, state=%d\n",
				   event->type, (int)event->cbutton.which, (int)event->cbutton.button, (int)event->cbutton.state);
			process_gpad_button_event(&event->cbutton);
			break;
		case SDL_CONTROLLERDEVICEADDED:
			printf("SDL event: SDL_CONTROLLERDEVICEADDED (%x): joy=%d\n",
				   event->type, (int)event->cdevice.which);
			process_gpad_device_event(&event->cdevice);
			break;
		case SDL_CONTROLLERDEVICEREMOVED:
			printf("SDL event: SDL_CONTROLLERDEVICEREMOVED (%x): joy=%d\n",
				   event->type, (int)event->cdevice.which);
			process_gpad_device_event(&event->cdevice);
			break;
		case SDL_CONTROLLERDEVICEREMAPPED:
			printf("SDL event: SDL_CONTROLLERDEVICEREMAPPED (%x)\n", event->type);
			break;
#ifdef __EMSCRIPTEN__
			case SDL_FINGERMOTION:
	case SDL_FINGERDOWN:
	case SDL_FINGERUP:
		process_touch_event(&event->tfinger);
		break;
#endif
		case SDL_WINDOWEVENT:
			process_window_event(&event->window);
			break;
		default:
			break;
	}
}

void input_cleanup() {
	cleanupControllers();
}

#else // USE_SDL

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
		v0 = nox_strman_loadString_40F1D0("Dxinput.c:IM_CreateFailed", 0,
								   (int)"C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c", 73);
		sub_4516C0(v0);
	}
	if (g_dinput_mouse->lpVtbl->CreateDevice(g_dinput_mouse, &GUID_SysMouse, &g_device_mouse, 0) < 0) {
		v0 = nox_strman_loadString_40F1D0("Dxinput.c:IM_CreateDeviceFailed", 0,
								   (int)"C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c", 87);
		sub_4516C0(v0);
	}
	if (g_device_mouse->lpVtbl->SetCooperativeLevel(g_device_mouse, getWindowHandle_nox_xxx_getHWND_401FD0(),
													DISCL_BACKGROUND | DISCL_NONEXCLUSIVE) < 0) {
		v0 = nox_strman_loadString_40F1D0("Dxinput.c:IM_SetCoopFailed", 0,
								   (int)"C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c", 105);
		sub_4516C0(v0);
	}
	v4.diph.dwSize = 20;
	v4.diph.dwHeaderSize = 16;
	v4.diph.dwObj = 0;
	v4.diph.dwHow = 0;
	v4.dwData = 256;
	if (g_device_mouse->lpVtbl->SetProperty(g_device_mouse, DIPROP_BUFFERSIZE, (LPCDIPROPHEADER)&v4) < 0) {
		v0 = nox_strman_loadString_40F1D0("Dxinput.c:IM_SetPropertyFailed", 0,
								   (int)"C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c", 123);
		sub_4516C0(v0);
	}
	if (g_device_mouse->lpVtbl->SetDataFormat(g_device_mouse, &c_dfDIMouse) < 0) {
		v0 = nox_strman_loadString_40F1D0("Dxinput.c:IM_SetFormatFailed", 0,
								   (int)"C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c", 135);
		sub_4516C0(v0);
	}
	if (g_device_mouse->lpVtbl->Acquire(g_device_mouse) < 0) {
		v0 = nox_strman_loadString_40F1D0("Dxinput.c:IM_AquireFailed", 0,
								   (int)"C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c", 147);
		sub_4516C0(v0);
	}
	v9.dwSize = 24;
	if (g_device_mouse->lpVtbl->GetCapabilities(g_device_mouse, (LPDIDEVCAPS)&v9) >= 0)
		*getMemU8Ptr(0x5D4594, 1193128) = v9.dwButtons;
	*getMemU32Ptr(0x5D4594, 1193108) = 1;
	sub_42EBB0(2, sub_47D890, 0, "DXInput");
	sub_42EBB0(1, nox_xxx_showWindow_47D8A0, 0, "DXInput");
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
UINT __cdecl nox_xxx_initJoystick_47D660(UINT uJoyID, int a2) {
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
				v4 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 153832), 0,
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
		v0 = nox_strman_loadString_40F1D0("Dxinput.c:OK_CreateFailed", 0, "C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c",
								   827);
		sub_4516C0(v0);
	}

	if (g_dinput_keyboard->lpVtbl->CreateDevice(g_dinput_keyboard, &GUID_SysKeyboard, &g_device_keyboard, NULL) < 0) {
		v1 = nox_strman_loadString_40F1D0("Dxinput.c:OK_CreateDeviceFailed", 0,
								   "C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c", 841);
		sub_4516C0(v1);
	}

	if (g_device_keyboard->lpVtbl->SetDataFormat(g_device_keyboard, &c_dfDIKeyboard) < 0) {
		v2 = nox_strman_loadString_40F1D0("Dxinput.c:OK_SetFormatFailed", 0, "C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c",
								   853);
		sub_4516C0(v2);
	}

	if (g_device_keyboard->lpVtbl->SetCooperativeLevel(g_device_keyboard, getWindowHandle_nox_xxx_getHWND_401FD0(),
													   DISCL_BACKGROUND | DISCL_NONEXCLUSIVE) < 0) {
		v5 = nox_strman_loadString_40F1D0("Dxinput.c:OK_SetCoopFailed", 0, "C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c",
								   868);
		sub_4516C0(v5);
	}

	v15.diph.dwSize = 20;
	v15.diph.dwHeaderSize = 16;
	v15.diph.dwObj = 0;
	v15.diph.dwHow = 0;
	v15.dwData = 256;
	if (g_device_keyboard->lpVtbl->SetProperty(g_device_keyboard, DIPROP_BUFFERSIZE, &v15) < 0) {
		v6 = nox_strman_loadString_40F1D0("Dxinput.c:OK_SetPropertyFailed", 0,
								   "C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c", 886);
		sub_4516C0(v6);
	}

	if (g_device_keyboard->lpVtbl->Acquire(g_device_keyboard) < 0) {
		v7 = nox_strman_loadString_40F1D0("Dxinput.c:OK_AquireFailed", 0, "C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c",
								   899);
		sub_4516C0(v7);
	}

	dword_5d4594_1193132 = GetKeyState(20) & 1;
	dword_5d4594_1193132 = dword_5d4594_1193132;
	sub_47DBD0();
}

// ORIGINAL
//----- (0047F950) --------------------------------------------------------
/*unsigned __int16 __cdecl nox_xxx_conScanCode2Alpha_47F950(unsigned __int16 a1)
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
void nox_xxx_getKeyFromKeyboardImpl_47FA80(nox_keyboard_btn_t* ev) {
	HRESULT v2;            // eax
	char v3;               // al
	char v4;               // dl
	HRESULT v5;            // eax
	DIDEVICEOBJECTDATA v6; // [esp+14h] [ebp-10h]
	DWORD dw;

	ev->code = 0;
	ev->seq = 0;
	if (g_device_keyboard) {
		dw = 1;
		v2 = g_device_keyboard->lpVtbl->GetDeviceData(g_device_keyboard, 16, &v6, &dw, 0);
		if (v2 == DIERR_INPUTLOST) {
			v5 = g_device_keyboard->lpVtbl->Acquire(g_device_keyboard);
			if (v5 >= 0 && v5 <= 1)
				ev->code = -1;
		} else if (!v2 && dw) {
			ev->code = v6.dwOfs; // key code
			ev->state = (v6.dwData & 0x80 != 0) + 1;
			ev->field_2 = 0;
			ev->field_3 = 0;
			ev->seq = v6.dwSequence;
		}
	}
}

int sub_47D890() { return unacquireMouse_sub_47D8B0(); }
#endif // USE_SDL
