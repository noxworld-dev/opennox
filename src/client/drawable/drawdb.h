#ifndef NOX_PORT_CLIENT_DRAWABLE_DRAWDB
#define NOX_PORT_CLIENT_DRAWABLE_DRAWDB

#include "../../defs.h"

bool __cdecl nox_parse_thing_pretty_name(nox_thing* obj, nox_memfile* f, char* a3);
bool __cdecl nox_parse_thing_desc(nox_thing* obj, nox_memfile* f, char* a3);
void* __cdecl sub_44C840_read_things(void);

#endif // NOX_PORT_CLIENT_DRAWABLE_DRAWDB