#ifndef NOX_COMMON_ALLOC_CLASS_H
#define NOX_COMMON_ALLOC_CLASS_H

#include <stdint.h>

typedef struct nox_alloc_hdr nox_alloc_hdr;
typedef struct nox_alloc_hdr {
	int field_0;
	int field_1;
	nox_alloc_hdr* field_2;
	int field_3;
} nox_alloc_hdr;

typedef struct nox_alloc_class {
	char name[88];           // 0, 0, 0
	int size;                // 22, 0x58, 88
	int cnt1;                // 23
	nox_alloc_hdr* field_24; // 24
	nox_alloc_hdr* field_25; // 25
	unsigned int field_26;         // 26
	unsigned int field_27;         // 27
	unsigned int field_28;         // 28
	void* items;             // 29
	unsigned int field_30;         // 30
	unsigned int field_31;         // 31
	uint64_t ticks;  // 32
	unsigned int field_34;         // 34
	unsigned int field_35;         // 35
	int cnt2;                // 36
	unsigned int field_37;         // 37
} nox_alloc_class;
_Static_assert(sizeof(nox_alloc_class) == 152, "wrong size of nox_alloc_class structure!");

#ifndef NOX_CGO
nox_alloc_class*  nox_new_alloc_class(const char* name, int size, int cnt);
nox_alloc_class*  nox_new_alloc_class_f30(const char* name, int size, int cnt);
#else // NOX_CGO
nox_alloc_class*  nox_new_alloc_class(char* name, int size, int cnt);
nox_alloc_class*  nox_new_alloc_class_f30(char* name, int size, int cnt);
#endif // NOX_CGO
void  nox_free_alloc_class(nox_alloc_class* p); // idb
void  nox_free_alloc_class_f30(nox_alloc_class* p);
void*  nox_alloc_class_new_obj(nox_alloc_class* a1);
void*  nox_alloc_class_new_obj_zero(nox_alloc_class* a1);
void  nox_xxx_class_4144D0(unsigned int* a1);
void  nox_alloc_class_free_obj_414330(unsigned int* a1, uint64_t* a2);
void  sub_414400(unsigned int* a1, uint64_t* a2);

#endif // NOX_COMMON_ALLOC_CLASS_H