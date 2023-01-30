#ifndef NOX_PORT_CLIENT_DRAW_DOORDRAW
#define NOX_PORT_CLIENT_DRAW_DOORDRAW

#include "defs.h"

int nox_thing_door_draw(uint32_t* a1, nox_drawable* dr);
bool nox_things_door_draw_parse(nox_thing* obj, nox_memfile* f, char* attr_value);

#endif // NOX_PORT_CLIENT_DRAW_DOORDRAW
