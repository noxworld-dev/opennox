#ifndef NOX_INPUT_H
#define NOX_INPUT_H

#include "defs.h" // for nox_point

void input_cleanup();
void input_events_tick();

int unacquireMouse_sub_47D8B0();
int acquireMouse_sub_47D8C0();
int nox_xxx_freeKeyboard_47FCC0();
void nox_xxx_getKeyFromKeyboardImpl_47FA80(nox_keyboard_btn_t* ev);

float nox_input_getSensitivity();
void nox_input_setSensitivity(float v);

void nox_input_resetBuffers();
bool nox_input_shiftState();
bool nox_input_scrollLockState();
int nox_input_pollEvents_4453A0();
int nox_input_pollEventsMovie();
bool nox_input_isMouseDown();

bool controller_relative();
nox_pointf controller_relative_pos();

void nox_input_enableTextEdit_5700CA();
void nox_input_disableTextEdit_5700F6();
wchar_t* nox_input_getStringBuffer_57011C();
void nox_input_freeStringBuffer_57011C(wchar_t* p);

unsigned short nox_input_scanCodeToAlpha_47F950(unsigned short a1);
void nox_xxx_getKeyFromKeyboard_430710();

int nox_xxx_initMouse_47D8D0();
bool nox_client_nextMouseEvent_47DB20(nox_mouse_state_t* e);
void nox_xxx_clientControl_42D6B0_em_not_mouse_down();

#endif // NOX_INPUT_H
