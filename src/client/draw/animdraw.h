#ifndef NOX_PORT_CLIENT_DRAW_ANIMDRAW
#define NOX_PORT_CLIENT_DRAW_ANIMDRAW

#include "../../defs.h"

int __cdecl nox_thing_animate_draw(_DWORD* a1, nox_drawable* dr);
int __cdecl nox_thing_animate_state_draw(_DWORD* a1, nox_drawable* dr);
bool __cdecl nox_things_animate_draw_parse(nox_thing* obj, nox_memfile* f, char* attr_value);
bool __cdecl nox_things_animate_state_draw_parse(nox_thing* obj, nox_memfile* f, char* attr_value);

#endif // NOX_PORT_CLIENT_DRAW_ANIMDRAW
