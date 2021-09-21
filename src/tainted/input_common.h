#ifndef NOX_PORT_INPUT_COMMON
#define NOX_PORT_INPUT_COMMON

#include "defs.h"

void nox_xxx_input_42D220();
void nox_input_reset_430140(int a1);
int nox_xxx_initInput_430190();
void nox_xxx_freeKeyboard_430210();
void nox_client_mouseBtnState_430230();
void nox_client_processMouseEvents_4302A0(int evNum, int a2);
void nox_client_readMouseBuffer_4306A0(int a1);
int sub_4307D0();
int nox_client_processMouseInput_4308A0(int a1);
char* nox_xxx_wndKeyGet_430940();
unsigned char sub_430950(unsigned char i);
unsigned char nox_input_keyboardGetKeyState_430970(unsigned char i);
int nox_input_keyboardGetKeySeq_430990(unsigned char i);
nox_point nox_client_getMousePos_4309F0();
nox_mouse_state_t* nox_client_getMouseState_4309F0();
void nox_client_changeMousePos_430A00(int x, int y, bool isAbs);
void nox_xxx_setMouseBounds_430A70(int x_min, int x_max, int y_min, int y_max);
int nox_xxx_bookGet_430B40_get_mouse_prev_seq();

#endif // NOX_PORT_INPUT_COMMON
