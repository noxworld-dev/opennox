#ifndef NOX_INPUT_H
#define NOX_INPUT_H

#include "defs.h" // for nox_point

void nox_input_setSensitivity(float v);

int nox_input_pollEvents_4453A0();

void nox_input_enableTextEdit_5700CA();
void nox_input_disableTextEdit_5700F6();
wchar2_t* nox_input_getStringBuffer_57011C();
void nox_input_freeStringBuffer_57011C(wchar2_t* p);

unsigned short nox_input_scanCodeToAlpha_47F950(unsigned short a1);

#endif // NOX_INPUT_H
