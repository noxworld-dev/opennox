#ifndef NOX_PORT_INPUT_COMMON
#define NOX_PORT_INPUT_COMMON

#include "defs.h"

void nox_input_reset_430140(int a1);
nox_point nox_client_getMousePos_4309F0();
void nox_client_changeMousePos_430A00(int x, int y, bool isAbs);
void nox_xxx_setMouseBounds_430A70(int x_min, int x_max, int y_min, int y_max);
int nox_xxx_bookGet_430B40_get_mouse_prev_seq();

#endif // NOX_PORT_INPUT_COMMON
