#ifndef NOX_PORT_CLIENT_DRAW_DOORDRAW
#define NOX_PORT_CLIENT_DRAW_DOORDRAW

#include "../../defs.h"

int __cdecl nox_thing_door_draw(_DWORD* a1, nox_drawable* dr);
bool __cdecl nox_things_door_draw_parse(nox_thing* obj, nox_memfile* f, char* attr_value);

#endif // NOX_PORT_CLIENT_DRAW_DOORDRAW
