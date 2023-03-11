#ifndef NOX_SERVER_SCRIPT_INTERNAL_H
#define NOX_SERVER_SCRIPT_INTERNAL_H

#include "defs.h"

void nox_script_push(int val);
void nox_script_pushf(float val);
int nox_script_pop();
float nox_script_popf();
void* nox_script_get_caller();
void* nox_script_get_trigger();
char* nox_script_getString_512E40(int i);
nox_object_t* nox_server_scriptValToObjectPtr_511B60(int a1);

#endif // NOX_SERVER_SCRIPT_INTERNAL_H
