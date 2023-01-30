#ifndef NOX_PORT_CLIENT_DRAW_CANIDRAW_H
#define NOX_PORT_CLIENT_DRAW_CANIDRAW_H

#include "defs.h"

int nox_thing_cond_animate_draw(uint32_t* a1, nox_drawable* dr);
bool nox_things_cond_animate_draw_parse(nox_thing* obj, nox_memfile* f, char* attr_value);

#endif // NOX_PORT_CLIENT_DRAW_CANIDRAW_H
