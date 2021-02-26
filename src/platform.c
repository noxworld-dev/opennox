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
