#ifndef NOX_SERVER_SCRIPT_INTERNAL_H
#define NOX_SERVER_SCRIPT_INTERNAL_H

void nox_script_push(int val);
int nox_script_pop();
unsigned int nox_script_stack_at(int i);
int  nox_script_addString_512E40(char* a1);
const char* nox_script_getString_512E40(int i);
int  nox_server_scriptValToObjectPtr_511B60(int a1);
const char* nox_script_getField36(int i);
unsigned int nox_script_getField40(int i);
unsigned int nox_script_getField44(int i);

#endif // NOX_SERVER_SCRIPT_INTERNAL_H
