#ifndef NOX_SERVER_SCRIPT_INTERNAL_H
#define NOX_SERVER_SCRIPT_INTERNAL_H

#include "defs.h"

typedef struct nox_script_xxx_t {
	char* field_0;           // 0, 0
	unsigned int stack_size; // 1, 4
	unsigned int size_28;    // 2, 8
	unsigned int field_12;   // 3, 12; len field_20 and field_24
	unsigned int field_16;   // 4, 16
	unsigned int* field_20;  // 5, 20
	unsigned int* field_24;  // 6, 24
	unsigned int* field_28;  // 7, 28
	void* data;              // 8, 32
	char* field_36;          // 9, 36
	unsigned int field_40;   // 10, 40
	unsigned int field_44;   // 11, 44
} nox_script_xxx_t;

void nox_script_push(int val);
void nox_script_pushf(float val);
int nox_script_pop();
float nox_script_popf();
unsigned int nox_script_stack_at(int i);
int nox_script_addString_512E40(char* a1);
void* nox_script_get_caller();
void* nox_script_get_trigger();
const char* nox_script_getString_512E40(int i);
nox_object_t* nox_server_scriptValToObjectPtr_511B60(int a1);
const char* nox_script_getField36(int i);
unsigned int nox_script_getField40(int i);
unsigned int nox_script_getField44(int i);

#endif // NOX_SERVER_SCRIPT_INTERNAL_H
