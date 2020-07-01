#ifndef NOX_PORT_CLIENT_DRAWABLE_DRAWDB
#define NOX_PORT_CLIENT_DRAWABLE_DRAWDB

#include "../../defs.h"

typedef struct nox_parse_thing_funcs_t {
	const char* name;
	bool(__cdecl* parse_func)(nox_thing*, nox_memfile*, char*);
} nox_parse_thing_funcs_t;

extern nox_parse_thing_funcs_t nox_parse_thing_funcs[];
extern int nox_parse_thing_funcs_cnt;

void* __cdecl sub_44C840_read_things(void);
void nox_things_free_44C580();

int sub_4E2A20();

#endif // NOX_PORT_CLIENT_DRAWABLE_DRAWDB
