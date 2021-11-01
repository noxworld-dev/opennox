#ifndef NOX_PORT_CLIENT_DRAW_PLAYERDRAW
#define NOX_PORT_CLIENT_DRAW_PLAYERDRAW

#include "defs.h"

int  nox_thing_player_draw(uint32_t* a1, nox_drawable* dr);
int  nox_thing_player_waypoint_draw(int a1, nox_drawable* dr);
bool  nox_things_player_draw_parse(nox_thing* obj, nox_memfile* f, char* attr_value);

#endif // NOX_PORT_CLIENT_DRAW_PLAYERDRAW
