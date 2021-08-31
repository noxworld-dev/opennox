#ifndef NOX_PORT_THING
#define NOX_PORT_THING

#include "defs.h"

nox_memfile* nox_open_thing_bin(void);
void nox_free_thing_bin(void);
bool nox_ensure_thing_bin(void);

#endif // NOX_PORT_THING
