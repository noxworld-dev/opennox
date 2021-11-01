//+build none

#ifdef __EMSCRIPTEN__
#include "client__system__ctrlevnt.h"
#include <emscripten/emscripten.h>
#include <emscripten/html5.h>
#endif

#include "ConvertUTF.h"
#include "client__io__console.h"
#include "input.h"
#include <SDL2/SDL.h>
#include <limits.h>

#include "client__video__draw_common.h" // for nox_video_getWindow_401FD0

#include "GAME2_2.h"
#include "MixPatch.h"
#include "client__gui__window.h"
#include "defs.h"
#include "server__script__builtin.h"

float input_sensitivity = 1.0;
void nox_input_setSensitivity(float v) { input_sensitivity = v; }
float nox_input_getSensitivity() { return input_sensitivity; }

#include "sdl2_scancode_to_dinput.h"
extern uint32_t dword_5d4594_1193132;
extern int g_textinput;

SDL_GameController* gpad = NULL;
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
	unsigned char code;
	unsigned char state;
	unsigned int seq;
};

struct mouse_event {
	unsigned int type;
	int x, y, wheel;
	int pressed;
	unsigned int seq;
};

static int seqnum;
static struct keyboard_event keyboard_event_queue[256];
static uint32_t keyboard_event_ridx;
static uint32_t keyboard_event_widx;
static struct mouse_event mouse_event_queue[256];
uint32_t mouse_event_ridx = 0;
uint32_t mouse_event_widx = 0;

struct finger_state {
	SDL_FingerID id;
	unsigned int timestamp;
	float x, y;
};

extern int g_rotated;
static struct finger_state fingers[8];
int mouse1_finger_state;
#ifdef __EMSCRIPTEN__
static int mouse0_state;
static int orientation;
static int move_speed;
static int jump;
#endif
int g_mouse_aquired = 0;

bool nox_input_isMouseDown() { return SDL_GetEventState(SDL_MOUSEBUTTONDOWN); }

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
		if (is_mouse_inside(nox_video_getWindow_401FD0()))
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

void input_mouse_down_at(int x, int y, int button) { input_mouse_button_at(x, y, button, true); }

void input_mouse_up_at(int x, int y, int button) { input_mouse_button_at(x, y, button, false); }

void input_mouse_down(int button) { input_mouse_button(button, true); }

void input_mouse_up(int button) { input_mouse_button(button, false); }

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

void process_motion_event(const SDL_MouseMotionEvent* event) { input_mouse_set(event->x, event->y); }

void process_wheel_event(const SDL_MouseWheelEvent* event) { input_mouse_wheel(event->y); }

void fake_keyup(void* arg) { input_keyboard(SDL_SCANCODE_SPACE, 0); }

void fake_mouseup(void* arg) { input_mouse_up(MOUSE_BUTTON0); }

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

void send_mouse1_event() { input_mouse_button(MOUSE_BUTTON1, mouse1_finger_state /* && !mouse0_state */); }

float gpad_mouse_speed = 50.0;
int gpad_dead_zone = 1500;

nox_point gpad_left = {0};
nox_point gpad_left_dv = {0};
nox_point gpad_right = {0};
nox_point gpad_right_dv = {0};
int gpad_ltrig_v = 0;
int gpad_ltrig_dv = 0;
bool gpad_ltrig_click = false;
int gpad_rtrig_v = 0;
int gpad_rtrig_dv = 0;
bool gpad_rtrig_click = false;

bool gpad_trig_attack = false;

// acts like a relative mouse pointer
nox_point* gpad_stick_rel = &gpad_left;
bool gpad_stick_rel_running = false;
const float gpad_stick_rel_auto_run = 0.3;

// acts like an absolute mouse pointer
nox_point* gpad_stick_abs = &gpad_right;
nox_pointf gpad_stick_abs_mouse = {0};

bool controller_relative() {
	return abs(gpad_stick_rel->x) > gpad_dead_zone || abs(gpad_stick_rel->y) > gpad_dead_zone;
}

nox_pointf controller_relative_pos() {
	nox_pointf p;
	p.x = ((float)gpad_stick_rel->x / SHRT_MAX);
	p.y = ((float)gpad_stick_rel->y / SHRT_MAX);
	return p;
}

void controller_tick() {
	// absolute stick acts as a mouse pointer, os it should move as long as stick has any values
	if (abs(gpad_stick_abs->x) > gpad_dead_zone || abs(gpad_stick_abs->y) > gpad_dead_zone) {
		float dx = ((float)gpad_stick_abs->x / SHRT_MAX);
		float dy = ((float)gpad_stick_abs->y / SHRT_MAX);
		if (dx >= 0) {
			gpad_stick_abs_mouse.x += dx * dx * gpad_mouse_speed;
		} else {
			gpad_stick_abs_mouse.x -= dx * dx * gpad_mouse_speed;
		}
		if (dy >= 0) {
			gpad_stick_abs_mouse.y += dy * dy * gpad_mouse_speed;
		} else {
			gpad_stick_abs_mouse.y -= dy * dy * gpad_mouse_speed;
		}
		input_clampf(&gpad_stick_abs_mouse.x, &gpad_stick_abs_mouse.y);
		input_mouse_set(gpad_stick_abs_mouse.x, gpad_stick_abs_mouse.y);
	}
	// automatically start running on a specific threshold on relative stick
	nox_pointf rel = controller_relative_pos();
	float relV = rel.x * rel.x + rel.y * rel.y;
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

void gamepad_trigger_click(int value, bool* clicked, SDL_Scancode button) {
	if (*clicked) {
		if (value < SHRT_MAX / 2) {
			input_keyboard(button, false);
			*clicked = false;
		}
	} else {
		if (value > SHRT_MAX / 2) {
			input_keyboard(button, true);
			*clicked = true;
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
		gamepad_trigger_click(gpad_ltrig_v, &gpad_ltrig_click, SDL_SCANCODE_W);
		break;
	case SDL_CONTROLLER_AXIS_TRIGGERRIGHT:
		gpad_rtrig_dv = v - gpad_rtrig_v;
		gpad_rtrig_v = v;
		gamepad_trigger_click(gpad_rtrig_v, &gpad_rtrig_click, SDL_SCANCODE_E);
		break;
	}
}

void process_gpad_button_event(const SDL_ControllerButtonEvent* event) {
	bool pressed = event->state == SDL_PRESSED;
	switch (event->button) {
	// spells are on the dpad
	case SDL_CONTROLLER_BUTTON_DPAD_UP:
		input_keyboard(SDL_SCANCODE_S, pressed); // spell 2
		break;
	case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
		input_keyboard(SDL_SCANCODE_F, pressed); // spell 4
		break;
	case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
		input_keyboard(SDL_SCANCODE_A, pressed); // spell 1
		break;
	case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
		input_keyboard(SDL_SCANCODE_D, pressed); // spell 3
		break;
	case SDL_CONTROLLER_BUTTON_A:                    // down button
		input_keyboard(SDL_SCANCODE_SPACE, pressed); // jump
		break;
	case SDL_CONTROLLER_BUTTON_B:                // right button
		input_keyboard(SDL_SCANCODE_Z, pressed); // poison potion
		break;
	case SDL_CONTROLLER_BUTTON_X:                // left button
		input_keyboard(SDL_SCANCODE_Q, pressed); // inventory
		break;
	case SDL_CONTROLLER_BUTTON_Y:                // up button
		input_keyboard(SDL_SCANCODE_V, pressed); // switch weapons
		break;
	case SDL_CONTROLLER_BUTTON_BACK:
		input_keyboard(SDL_SCANCODE_ESCAPE, pressed); // back
		break;
	case SDL_CONTROLLER_BUTTON_GUIDE:
		break;
	case SDL_CONTROLLER_BUTTON_START:
		input_keyboard(SDL_SCANCODE_TAB, pressed); // map
		break;
	case SDL_CONTROLLER_BUTTON_LEFTSTICK:
		input_keyboard(SDL_SCANCODE_X, pressed); // health potion
		break;
	case SDL_CONTROLLER_BUTTON_RIGHTSTICK:
		input_keyboard(SDL_SCANCODE_C, pressed); // mana potion
		break;
	case SDL_CONTROLLER_BUTTON_LEFTSHOULDER:
		input_keyboard(SDL_SCANCODE_G, pressed); // spell 5
		break;
	case SDL_CONTROLLER_BUTTON_RIGHTSHOULDER:
		input_mouse_button(MOUSE_BUTTON0, pressed); // attack
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
			mouse1_finger_state = 1;
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
			mouse1_finger_state = 0;
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

void nox_input_resetBuffers() {
	keyboard_event_ridx = 0;
	keyboard_event_widx = 0;
}

bool nox_input_shiftState() { return (SDL_GetModState() & (KMOD_LSHIFT | KMOD_RSHIFT)) != 0; }

bool nox_input_scrollLockState() {
	// TODO: why it uses RALT?
	return (SDL_GetModState() & KMOD_RALT) == (KMOD_RALT);
}

// free keyboard
int nox_xxx_freeKeyboard_47FCC0() { return 0; }

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
int nox_xxx_initMouse_47D8D0() {
#ifndef NOX_NO_MOUSE_GRAB
	SDL_SetWindowGrab(nox_video_getWindow_401FD0(), SDL_TRUE);
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
		SDL_SetWindowGrab(nox_video_getWindow_401FD0(), SDL_TRUE);
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
	SDL_SetWindowGrab(nox_video_getWindow_401FD0(), SDL_FALSE);
#endif
	g_mouse_aquired = 0;
	return 0;
}

typedef struct DIDEVICEOBJECTDATA {
	uint32_t dwOfs;
	uint32_t dwData;
	uint32_t dwTimeStamp;
	uint32_t dwSequence;
	uintptr_t uAppData;
} DIDEVICEOBJECTDATA, *LPDIDEVICEOBJECTDATA;

// get mouse data
bool nox_client_nextMouseEvent_47DB20(nox_mouse_state_t* e) {
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
		OnLibraryNotice_265(&e, 2, me->wheel); // mix event hanlder is triggered only for wheel events
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

void input_events_tick() { controller_tick(); }

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
		printf("SDL event: SDL_CONTROLLERAXISMOTION (%x): joy=%d, axis=%d, val=%d\n", event->type,
			   (int)event->caxis.which, (int)event->caxis.axis, (int)event->caxis.value);
		process_gpad_axis_event(&event->caxis);
		break;
	case SDL_CONTROLLERBUTTONDOWN:
	case SDL_CONTROLLERBUTTONUP:
		printf("SDL event: SDL_CONTROLLERBUTTON (%x): joy=%d, btn=%d, state=%d\n", event->type,
			   (int)event->cbutton.which, (int)event->cbutton.button, (int)event->cbutton.state);
		process_gpad_button_event(&event->cbutton);
		break;
	case SDL_CONTROLLERDEVICEADDED:
		printf("SDL event: SDL_CONTROLLERDEVICEADDED (%x): joy=%d\n", event->type, (int)event->cdevice.which);
		process_gpad_device_event(&event->cdevice);
		break;
	case SDL_CONTROLLERDEVICEREMOVED:
		printf("SDL event: SDL_CONTROLLERDEVICEREMOVED (%x): joy=%d\n", event->type, (int)event->cdevice.which);
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

void input_cleanup() { cleanupControllers(); }

//----- (004453A0) --------------------------------------------------------
int nox_input_pollEvents_4453A0() {
	input_events_tick();
	SDL_Event event;
	while (SDL_PollEvent(&event))
		process_event(&event);
	return 0;
}

int process_movie_event(const SDL_Event* event) {
	switch (event->type) {
	case SDL_KEYUP:
	case SDL_MOUSEBUTTONUP:
		return -1;
		break;
#ifdef __EMSCRIPTEN__
	case SDL_FINGERMOTION:
	case SDL_FINGERDOWN:
	case SDL_FINGERUP:
		return -1;
		break;
#endif
	case SDL_WINDOWEVENT:
		// process_window_event(&event->window);
		break;
	default:
		break;
	}
	return 0;
}

int nox_input_pollEventsMovie() {
	int result = 0;
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		int processed = process_movie_event(&event);
		result = processed;
	}
	return result;
}

int g_textinput;
wchar_t g_ime_buf[512];
// static unsigned int g_ime_idx;

#ifdef __EMSCRIPTEN__
static char g_ime_raw[512];

static void update_ime(int finished) {
	char tmp[512], complete[512];
	const char* src;
	wchar_t wtmp[3], *dst;

	complete[0] = 0;
	tmp[0] = 0;
	EM_ASM_(
		{
			var raw = Array.from(UTF8ToString($0));
			var assembled = Hangul.assemble(raw);
			if (assembled.length > 1) {
				stringToUTF8(assembled.slice(0, 1), $1, 512);
				raw = Hangul.disassemble(assembled.slice(1));
				stringToUTF8(raw.join(), $0, 512);
				assembled = Hangul.assemble(raw);
			}
			stringToUTF8(assembled, $2, 512);
		},
		g_ime_raw, complete, tmp);

	dst = g_ime_buf;
	src = tmp;
	if (ConvertUTF8toUTF16(&src, src + strlen(src), &dst, g_ime_buf + 512, strictConversion) == conversionOK) {
		*dst = 0;
	} else {
		g_ime_buf[0] = UNI_REPLACEMENT_CHAR;
		g_ime_buf[1] = 0;
	}

	if (complete[0]) {
		dst = wtmp;
		src = complete;
		if (ConvertUTF8toUTF16(&src, src + strlen(src), &dst, wtmp + 3, strictConversion) == conversionOK) {
			unsigned int i;
			for (i = 0; &wtmp[i] != dst; i++)
				nox_xxx_onChar_488BD0(wtmp[i]);
		} else {
			nox_xxx_onChar_488BD0(UNI_REPLACEMENT_CHAR);
		}
	}

	if (finished) {
		unsigned int i;
		wchar_t wc = g_ime_buf[0];
		if (wc) {
			g_ime_buf[0] = 0;
			nox_xxx_onChar_488BD0(wc);
			for (i = 1; g_ime_buf[i]; i++)
				nox_xxx_onChar_488BD0(g_ime_buf[i]);
		}
		g_ime_raw[0] = 0;
	}
}
#endif // __EMSCRIPTEN__

void process_textediting_event(const SDL_TextEditingEvent* event) {
	const char* src = event->text;
	wchar_t* dst = g_ime_buf;

	if (ConvertUTF8toUTF16(&src, event->text + strlen(event->text), &dst, g_ime_buf + 512, strictConversion) ==
		conversionOK) {
		*dst = 0;
	} else {
		g_ime_buf[0] = UNI_REPLACEMENT_CHAR;
		g_ime_buf[1] = 0;
	}
}

void process_textinput_event(const SDL_TextInputEvent* event) {
#ifdef __EMSCRIPTEN__
	// Javascript / emscripten is terrible and we need to handle composition ourselves :(
	// Thankfully we only want to handle English and Korean, and we can use JS libraries.
	int hangul;

	hangul = EM_ASM_INT(
		{
			var raw = Array.from(UTF8ToString($0));
			return Hangul.isCho(raw[0]) || Hangul.isJong(raw[0]) || Hangul.isVowel(raw[0]);
		},
		event->text);
	strcat(g_ime_raw, event->text);
	update_ime(!hangul);
#else  // !__EMSCRIPTEN__
	const char* src = event->text;
	wchar_t tmp[3], *dst = tmp;

	// g_ime_buf[g_ime_idx++] = event->text[0];
	// g_ime_buf[g_ime_idx] = 0;
	g_ime_buf[0] = 0;

	if (ConvertUTF8toUTF16(&src, event->text + strlen(event->text), &dst, tmp + 3, strictConversion) == conversionOK) {
		unsigned int i;
		for (i = 0; &tmp[i] != dst; i++)
			nox_xxx_onChar_488BD0(tmp[i]);
	} else {
		nox_xxx_onChar_488BD0(UNI_REPLACEMENT_CHAR);
	}
#endif // __EMSCRIPTEN__
}

void process_keyboard_event(const SDL_KeyboardEvent* event);
void process_textinput_keyboard_event(const SDL_KeyboardEvent* event) {
#ifdef __EMSCRIPTEN__
	// intercept keyboard events, such as backspace and enter
	switch (event->keysym.sym) {
	case SDLK_BACKSPACE:
		if (g_ime_raw[0]) {
			char* tmp;
			unsigned int i;

			// only process key down
			if (event->state == SDL_PRESSED) {
				tmp = NULL;
				for (i = 0; g_ime_raw[i]; i++) {
					if ((g_ime_raw[i] & 0xc0) != 0x80)
						tmp = &g_ime_raw[i];
				}
				if (tmp) {
					_dprintf("BACKSPACE %d", tmp - g_ime_raw);
					*tmp = 0;
					update_ime(0);
				}
			}
		}
		break;
	case SDLK_RETURN:
		if (g_ime_raw[0] && event->state == SDL_PRESSED) {
			update_ime(1);
		}
		break;
	default:
		break;
	}
#endif // __EMSCRIPTEN__
	process_keyboard_event(event);
}

//----- (005700CA) --------------------------------------------------------
void nox_input_enableTextEdit_5700CA() {
	SDL_StartTextInput();
	g_textinput = 1;
}

//----- (005700F6) --------------------------------------------------------
void nox_input_disableTextEdit_5700F6() {
	SDL_StopTextInput();
	g_textinput = 0;
}

//----- (0057011C) --------------------------------------------------------
wchar_t* nox_input_getStringBuffer_57011C() { return g_ime_buf; }
void nox_input_freeStringBuffer_57011C(wchar_t* p) {}
