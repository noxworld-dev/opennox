#ifndef NOX_PORT_CLIENT_DRAW_STATICDRAW
#define NOX_PORT_CLIENT_DRAW_STATICDRAW

#include "defs.h"

int __cdecl nox_thing_static_draw(_DWORD* a1, nox_drawable* dr);
int __cdecl nox_thing_static_random_draw(_DWORD* a1, nox_drawable* dr);
bool __cdecl nox_things_static_draw_parse(nox_thing* obj, nox_memfile* f, char* attr_value);
bool __cdecl nox_things_static_random_draw_parse(nox_thing* obj, nox_memfile* f, char* attr_value);

#endif // NOX_PORT_CLIENT_DRAW_STATICDRAW
