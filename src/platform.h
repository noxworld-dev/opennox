#ifndef NOX_PLATFORM_H
#define NOX_PLATFORM_H

#include <SDL.h>

int nox_rand();
void nox_srand(unsigned int seed);
void nox_srand_time();

unsigned int nox_get_ticks();
void nox_sleep(unsigned int ms);

int nox_SDL_PollEvent(SDL_Event* event);
Uint8 nox_SDL_GetEventState(Uint32 type);

#ifdef NOX_E2E_TEST
void script_add_event(SDL_Event e);
void script_exit();
void script_wait(unsigned int dt);
void script_move(int dx, int dy);
void script_move_to(int x, int y);
void script_hold(int btn);
void script_release(int btn);
void script_click(int btn);
void time_hook();
void init_script_events();
#endif

#endif // NOX_PLATFORM_H
