#ifndef NOX_PORT_CLIENT_DRAW_PLAYERDRAW
#define NOX_PORT_CLIENT_DRAW_PLAYERDRAW

#include "../../defs.h"

int __cdecl nox_thing_player_draw(_DWORD* a1, nox_drawable* dr);
int __cdecl nox_thing_player_waypoint_draw(int a1, nox_drawable* dr);
bool __cdecl nox_things_player_draw_parse(nox_thing* obj, nox_memfile* f, _BYTE* a3);

#endif // NOX_PORT_CLIENT_DRAW_PLAYERDRAW
