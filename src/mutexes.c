//+build none

#include "mutexes.h"
#include <SDL2/SDL.h>

void nox_mutex_init(nox_mutex_t* m) { m->p = SDL_CreateMutex(); }
void nox_mutex_free(nox_mutex_t* m) {
	SDL_DestroyMutex(m->p);
	m->p = 0;
}
void nox_mutex_lock(nox_mutex_t* m) { SDL_LockMutex(m->p); }
void nox_mutex_unlock(nox_mutex_t* m) { SDL_UnlockMutex(m->p); }
