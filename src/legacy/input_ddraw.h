#ifndef NOX_PORT_INPUT_DDRAW
#define NOX_PORT_INPUT_DDRAW

#include "../tainted/defs.h"

int nox_input_pollEvents_4453A0();
DWORD* sub_47D7A0(DWORD* a1, UINT uJoyID);
int sub_47D890();
int unacquireMouse_sub_47D8B0();
int acquireMouse_sub_47D8C0();
void nox_xxx_getKeyFromKeyboardImpl_47FA80(nox_keyboard_btn_t* ev);
void nox_xxx_initKeyboard_47FB10();
int nox_xxx_freeKeyboard_47FCC0();

#endif // NOX_PORT_INPUT_DDRAW
