#ifndef NOX_PORT_CLIENT_DRAW_ANIMDRAW
#define NOX_PORT_CLIENT_DRAW_ANIMDRAW

#include "defs.h"

int nox_thing_animate_draw(uint32_t* a1, nox_drawable* dr);
int nox_thing_animate_state_draw(nox_draw_viewport_t* a1, nox_drawable* dr);
bool nox_things_animate_draw_parse(nox_thing* obj, nox_memfile* f, char* attr_value);
bool nox_things_animate_state_draw_parse(nox_thing* obj, nox_memfile* f, char* attr_value);

#endif // NOX_PORT_CLIENT_DRAW_ANIMDRAW
