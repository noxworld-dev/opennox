#ifndef NOX_SERVER_SCRIPT_BUILTIN_H
#define NOX_SERVER_SCRIPT_BUILTIN_H

#include "defs.h"

int nox_script_builtinGetF40();
int nox_script_builtinGetF44();
int nox_script_callBuiltin_508B70(int i, int fi);
bool nox_script_shouldReadMoreXxx(int fi);
bool nox_script_shouldReadEvenMoreXxx(int fi);

void sub_511E60();
int* nox_server_scriptMoveTo_5123C0(int a1, int a2);
int nox_xxx_moverGoTo_5124C0(uint32_t* a1, uint32_t* a2);
void nox_xxx_scriptMonsterRoam_512930(nox_object_t* obj);
void sub_5165D0();

#endif // NOX_SERVER_SCRIPT_BUILTIN_H
