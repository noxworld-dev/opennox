#ifndef NOX_PORT_CLIENT_DRAW_SLAVEDRAW
#define NOX_PORT_CLIENT_DRAW_SLAVEDRAW

#include "defs.h"

int nox_thing_slave_draw(int* a1, nox_drawable* dr);
bool nox_things_slave_draw_parse(nox_thing* obj, nox_memfile* f, char* attr_value);

#endif // NOX_PORT_CLIENT_DRAW_SLAVEDRAW
