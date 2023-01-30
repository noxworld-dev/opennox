#ifndef NOX_PORT_CLIENT_DRAW_MAGICDRW
#define NOX_PORT_CLIENT_DRAW_MAGICDRW

#include "defs.h"

int nox_thing_magic_draw(int* a1, nox_drawable* dr);
int nox_thing_magic_missle_draw(int* a1, nox_drawable* dr);
int nox_thing_magic_missle_tail_link_draw(uint32_t* a1, nox_drawable* dr);
int nox_thing_magic_tail_link_draw(uint32_t* a1, nox_drawable* dr);
int nox_thing_drain_mana_draw();

#endif // NOX_PORT_CLIENT_DRAW_MAGICDRW
