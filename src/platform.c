#include "proto.h"
#include <time.h>

#include <SDL2/SDL.h>

#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif

// #define NOX_PREDICTABLE

int nox_rand() {
    return rand();
}

void nox_srand(unsigned int seed) {
    srand(seed);
}

#ifndef NOX_PREDICTABLE // ------------------------------------------------

void nox_srand_time() {
    srand(time(0));
}

unsigned int nox_get_ticks() {
    return SDL_GetTicks();
}

void nox_sleep(unsigned int ms) {
#ifdef __EMSCRIPTEN__
    emscripten_sleep(ms);
#else
    SDL_Delay(ms);
#endif
}

#else // NOX_PREDICTABLE --------------------------------------------------

volatile unsigned int ticks = 0;

void nox_srand_time() {
    srand(ticks);
}

void nox_sleep(unsigned int ms) {
    ticks += ms;
    sleep(0);
}

unsigned int nox_get_ticks() {
    ticks++;
    return ticks;
}

#endif // NOX_PREDICTABLE -------------------------------------------------
