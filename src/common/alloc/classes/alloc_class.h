#ifndef NOX_COMMON_ALLOC_CLASS_H
#define NOX_COMMON_ALLOC_CLASS_H

#include <stdint.h>

#define ALLOC_CLASS_NAME_MAX 88

typedef struct nox_alloc_hdr nox_alloc_hdr;
typedef struct nox_alloc_hdr {
	uint64_t ticks; // 0
	nox_alloc_hdr* field_2; // 8
	nox_alloc_hdr* field_3; // 12
} nox_alloc_hdr;

typedef struct nox_alloc_class {
	char name[ALLOC_CLASS_NAME_MAX];           // 0, 0, 0
	int size;                // 22, 0x58, 88
	int cnt1;                // 23
	nox_alloc_hdr* field_24; // 24
	nox_alloc_hdr* field_25; // 25
	nox_alloc_hdr* field_26; // 26
	nox_alloc_hdr* field_27; // 27
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

#ifdef NOX_CGO_ALLOC
#define nox_alloc_class_new_obj nox_alloc_class_new_obj_go
#define nox_alloc_class_free_obj nox_alloc_class_free_obj_go
#define nox_alloc_class_yyy_4144D0 nox_alloc_class_yyy_4144D0_go
#define nox_alloc_class_xxx_414400 nox_alloc_class_xxx_414400_go
#define nox_platform_get_ticks alloc_nox_platform_get_ticks
#endif // NOX_CGO_ALLOC

#ifndef NOX_CGO
nox_alloc_class*  nox_new_alloc_class(const char* name, int size, int cnt);
nox_alloc_class*  nox_new_alloc_class_f30(const char* name, int size, int cnt);
#else // NOX_CGO
nox_alloc_class*  nox_new_alloc_class(char* name, int size, int cnt);
nox_alloc_class*  nox_new_alloc_class_f30(char* name, int size, int cnt);
#endif // NOX_CGO
void  nox_free_alloc_class(nox_alloc_class* p); // idb
void*  nox_alloc_class_new_obj(nox_alloc_class* p);
void*  nox_alloc_class_new_obj_zero(nox_alloc_class* p);
void  nox_alloc_class_yyy_4144D0(nox_alloc_class* p);
void  nox_alloc_class_free_obj(nox_alloc_class* p, void* obj);
void  nox_alloc_class_xxx_414400(nox_alloc_class* p, void* obj);

#endif // NOX_COMMON_ALLOC_CLASS_H
