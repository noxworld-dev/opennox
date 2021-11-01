#ifndef NOX_PORT_CLIENT_DRAW_STATICDRAW
#define NOX_PORT_CLIENT_DRAW_STATICDRAW

#include "defs.h"

int nox_thing_static_draw(uint32_t* a1, nox_drawable* dr);
int nox_thing_static_random_draw(uint32_t* a1, nox_drawable* dr);
bool nox_things_static_draw_parse(nox_thing* obj, nox_memfile* f, char* attr_value);
bool nox_things_static_random_draw_parse(nox_thing* obj, nox_memfile* f, char* attr_value);

#endif // NOX_PORT_CLIENT_DRAW_STATICDRAW
