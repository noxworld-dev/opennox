#ifndef NOX_PLATFORM_H
#define NOX_PLATFORM_H

//#define NOX_PREDICTABLE
//#define NOX_E2E_TEST

#include <SDL2/SDL.h>

int nox_rand();
void nox_srand(unsigned int seed);
void nox_srand_time();

unsigned int nox_get_ticks();
void nox_sleep(unsigned int ms);

int nox_SDL_PollEvent(SDL_Event* event);
Uint8 nox_SDL_GetEventState(Uint32 type);

#endif // NOX_PLATFORM_H
