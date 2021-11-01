#ifndef NOX_PORT_CLIENT_DRAWABLE_DRAWABLE
#define NOX_PORT_CLIENT_DRAWABLE_DRAWABLE

// FIXME: Move the drawable struct defs here instead.
#include "defs.h"

extern nox_parse_thing_draw_funcs_t nox_parse_thing_draw_funcs[];
extern int nox_parse_thing_draw_funcs_cnt;

nox_drawable* nox_new_drawable_for_thing(int i);

#endif // NOX_PORT_CLIENT_DRAWABLE_DRAWABLE
