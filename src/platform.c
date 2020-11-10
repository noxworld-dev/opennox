#include "proto.h"
#include <time.h>

#include "platform.h"

#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif

int nox_platform_rand() { return rand(); }

void nox_platform_srand(unsigned int seed) { srand(seed); }

#ifndef NOX_PREDICTABLE // ------------------------------------------------

void nox_platform_srand_time() { srand(time(0)); }

unsigned int nox_platform_get_ticks() { return SDL_GetTicks(); }

void nox_platform_sleep(unsigned int ms) {
#ifdef __EMSCRIPTEN__
	emscripten_sleep(ms);
#else
	SDL_Delay(ms);
#endif
}

int nox_SDL_PollEvent(SDL_Event* event) { return SDL_PollEvent(event); }

Uint8 nox_SDL_GetEventState(Uint32 type) { return SDL_GetEventState(type); }

#else // NOX_PREDICTABLE --------------------------------------------------

volatile unsigned int ticks = 0;
volatile unsigned int loop_ticks = 0;

void nox_platform_srand_time() { srand(loop_ticks); }

#ifdef NOX_E2E_TEST
void nox_platform_time_hook();
#endif

void nox_platform_sleep(unsigned int ms) {
	ticks += ms;
	sleep(0);
}

unsigned int nox_platform_get_ticks() { return ticks; }

unsigned int nox_get_loop_ticks() { return loop_ticks; }

#ifdef NOX_E2E_TEST
unsigned int event_cur = 0;
unsigned int event_cnt = 0;
unsigned int next_event = 50;

const unsigned int wait_unit = 5;
const unsigned int time_scale = 10;

SDL_Event script_events[512] = {0};

void script_add_event(SDL_Event e) {
	script_events[event_cnt] = e;
	event_cnt++;
}

void script_exit() {
	SDL_Event e;
	e.type = 0xdead;
	e.common.timestamp = 100;
	script_add_event(e);
}

void script_wait(unsigned int dt) {
	if (dt == 0) {
		dt = wait_unit;
	}
	SDL_Event e;
	e.type = 0xbeaf;
	e.common.timestamp = dt * time_scale;
	script_add_event(e);
}

void script_move(int dx, int dy) {
	SDL_Event e;
	e.type = SDL_MOUSEMOTION;
	e.motion.xrel = dx;
	e.motion.yrel = dy;
	script_add_event(e);
	script_wait(5 * wait_unit);
}

void script_move_to(int x, int y) {
	SDL_Event e;
	e.type = SDL_MOUSEMOTION;
	e.motion.x = x;
	e.motion.y = y;
	script_add_event(e);
	script_wait(5 * wait_unit);
}

void script_hold(int btn) {
	SDL_Event e;
	e.type = SDL_MOUSEBUTTONDOWN;
	e.button.button = btn;
	e.button.state = SDL_PRESSED;
	script_add_event(e);
	script_wait(0);
}

void script_release(int btn) {
	SDL_Event e;
	e.type = SDL_MOUSEBUTTONUP;
	e.button.button = btn;
	e.button.state = SDL_RELEASED;
	script_add_event(e);
}

void script_click(int btn) {
	script_hold(btn);
	script_release(btn);
}

void nox_platform_time_hook() {
	// fprintf(stderr, "loop %d\n", loop_ticks);
	if (event_cnt == 0) {
		init_script_events();
	}
	if (next_event && loop_ticks >= next_event) {
		next_event = 0;
		event_cur++;
		fprintf(stderr, "%d: script trigger: %d\n", loop_ticks, event_cur);
	}
	loop_ticks++;
}
#endif

void log_event(SDL_Event* event) {
	switch (event->type) {
	case SDL_TEXTEDITING:
		fprintf(stderr, "%d: sdl: edit\n", loop_ticks);
		break;
	case SDL_TEXTINPUT:
		fprintf(stderr, "%d: sdl: text\n", loop_ticks);
		break;
	case SDL_KEYDOWN:
		fprintf(stderr, "%d: sdl: key down\n", loop_ticks);
		break;
	case SDL_KEYUP:
		fprintf(stderr, "%d: sdl: key up\n", loop_ticks);
		break;
	case SDL_MOUSEBUTTONDOWN:
		fprintf(stderr, "%d: sdl: mouse down: %d %d\n", loop_ticks, event->button.button, event->button.state);
		break;
	case SDL_MOUSEBUTTONUP:
		fprintf(stderr, "%d: sdl: mouse up: %d %d\n", loop_ticks, event->button.button, event->button.state);
		break;
	case SDL_MOUSEMOTION:
		fprintf(stderr, "%d: sdl: mouse motion: %d %d\n", loop_ticks, event->motion.xrel, event->motion.yrel);
		break;
	case SDL_MOUSEWHEEL:
		fprintf(stderr, "%d: sdl: mouse wheel\n", loop_ticks);
		break;
	case SDL_WINDOWEVENT:
		fprintf(stderr, "%d: sdl: window\n", loop_ticks);
		break;
	default:
		fprintf(stderr, "%d: sdl: unknown: %d\n", loop_ticks, event->type);
		break;
	}
}

#ifdef NOX_E2E_TEST
int script_mouse_x = 0;
int script_mouse_y = 0;
#endif

int nox_SDL_PollEvent(SDL_Event* event) {
#ifdef NOX_E2E_TEST
	if (event_cur) {
		if (event_cur - 1 >= event_cnt) {
			// no more recorded events - allow player to control again
			return SDL_PollEvent(event);
		}
		// consume and discard all SDL events
		while (SDL_PollEvent(event)) {
			// log_event(event);
			if (event->type == SDL_QUIT) {
				exit(1);
			}
		}
		// we started the script, ignore all events
		// generate them in this function
		memset(event, 0, sizeof(SDL_Event));
		if (next_event) {
			return 0; // wait, do nothing
		}
		SDL_Event* e2 = &script_events[event_cur - 1];
		if (e2->type == 0xdead) {
			// special: exit
			exit(1);
			return 0;
		} else if (e2->type == 0xbeaf) {
			// special: timer, wait some time before generating a new event
			unsigned int dt = e2->common.timestamp / time_scale;
			fprintf(stderr, "%d: script wait: %d\n", loop_ticks, dt);
			next_event = loop_ticks + dt;
			return 0;
		}
		*event = *e2;
		if (event->type == SDL_MOUSEMOTION) {
			if (event->motion.x != 0 || event->motion.y != 0) {
				event->motion.xrel = event->motion.x - script_mouse_x;
				event->motion.yrel = event->motion.y - script_mouse_y;
				script_mouse_x = event->motion.x;
				script_mouse_y = event->motion.y;
			} else {
				script_mouse_x += event->motion.xrel;
				script_mouse_y += event->motion.yrel;
			}
		}
		event_cur++;
		log_event(event);
		return 1;
	}
#endif
	int ret = SDL_PollEvent(event);
	if (!ret) {
		return 0;
	}
#ifdef NOX_E2E_TEST
	if (event->type != SDL_WINDOWEVENT) {
		return 0;
	}
	log_event(event);
#endif
	return ret;
}

Uint8 nox_SDL_GetEventState(Uint32 type) { return 1; }

#endif // NOX_PREDICTABLE -------------------------------------------------
