#include "proto.h"
#include <time.h>

#include "platform.h"

#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif

#ifndef NOX_CGO
int nox_platform_rand() { return rand(); }

void nox_platform_srand(unsigned int seed) { srand(seed); }
#endif // NOX_CGO

#ifndef NOX_PREDICTABLE // ------------------------------------------------

#ifndef NOX_CGO
void nox_platform_srand_time() { srand(time(0)); }

unsigned int nox_platform_time_seed() { return time(0); }

unsigned int nox_platform_get_ticks() { return SDL_GetTicks(); }

void nox_platform_sleep(unsigned int ms) {
#ifdef __EMSCRIPTEN__
	emscripten_sleep(ms);
#else
	SDL_Delay(ms);
#endif
}
#endif // NOX_CGO

int nox_SDL_PollEvent(SDL_Event* event) { return SDL_PollEvent(event); }

Uint8 nox_SDL_GetEventState(Uint32 type) { return SDL_GetEventState(type); }

#else // NOX_PREDICTABLE --------------------------------------------------

volatile unsigned int ticks = 0;
volatile unsigned int loop_ticks = 0;

unsigned int nox_platform_time_seed() { return loop_ticks; }

void nox_platform_srand_time() { srand(loop_ticks); }

void nox_platform_sleep(unsigned int ms) {
	ticks += ms;
	sleep(0);
}

unsigned int nox_platform_get_ticks() { return ticks; }

unsigned int nox_get_loop_ticks() { return loop_ticks; }

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

int nox_SDL_PollEvent(SDL_Event* event) {
	int ret = SDL_PollEvent(event);
	if (!ret) {
		return 0;
	}
	return ret;
}

Uint8 nox_SDL_GetEventState(Uint32 type) { return 1; }

#endif // NOX_PREDICTABLE -------------------------------------------------
