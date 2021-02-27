//+build none

#include "proto.h"
#include <time.h>

#include "platform.h"

#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif

int nox_platform_rand() { return rand(); }

void nox_platform_srand(unsigned int seed) { srand(seed); }

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
