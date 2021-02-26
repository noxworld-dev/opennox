#ifndef NOX_INPUT_H
#define NOX_INPUT_H

#define USE_SDL 1

#ifdef USE_SDL
#include <SDL2/SDL.h>
#include "defs.h" // for nox_point

void input_cleanup();
void input_events_tick();
bool nox_input_isMouseDown();
void process_event(const SDL_Event* event);

bool controller_relative();
nox_pointf controller_relative_pos();
#endif // USE_SDL

#endif // NOX_INPUT_H
