#ifndef NOX_PORT_CLIENT_DRAWABLE_DRAWDB
#define NOX_PORT_CLIENT_DRAWABLE_DRAWDB

#include "defs.h"

typedef struct nox_parse_thing_funcs_t {
	const char* name;
	bool (*parse_func)(nox_thing*, nox_memfile*, char*);
} nox_parse_thing_funcs_t;

extern nox_parse_thing_funcs_t nox_parse_thing_funcs[];

int nox_parse_thing(nox_memfile* thing_file, char* scratch_buffer, nox_thing* thing);

#endif // NOX_PORT_CLIENT_DRAWABLE_DRAWDB
