#ifndef NOX_SERVER_SCRIPT_SCRIPT_H
#define NOX_SERVER_SCRIPT_SCRIPT_H

#include "defs.h"

int nox_script_ncobj_parse_505360();
void nox_script_callByIndex_507310(int index, void* a1, void* a2);
#ifdef NOX_CGO
void nox_script_callOnEvent(char* event, void* a1, void* a2);
#else  // NOX_CGO
void nox_script_callOnEvent(const char* event, void* a1, void* a2);
#endif // NOX_CGO
int nox_script_indexByEvent(const char* a1);
void nox_xxx_scriptLeverReact_51ADF0();
void sub_51B0C0();

int nox_xxx_xferReadScriptHandler_4F5580(int a1, char* a2);
unsigned char* nox_xxx_scriptCallByEventBlock_502490(int* a1, int a2, int a3, int eventCode);
int nox_server_mapRWScriptData_504F90();
void nox_script_freeEverything_5058F0();
void nox_xxx_scriptRunFirst_507290();
int sub_508CB0(unsigned int* a1, int a2);

#endif // NOX_SERVER_SCRIPT_SCRIPT_H
