#ifndef NOX_COMMON_ALLOC_CLASS_H
#define NOX_COMMON_ALLOC_CLASS_H

#include <stdint.h>

#include "../../../static_assert.h"

#define ALLOC_CLASS_NAME_MAX 88

typedef struct nox_alloc_hdr nox_alloc_hdr;
typedef struct nox_alloc_hdr {
	uint64_t expires;       // 0, set to 1 if item is dynamic and in use; set to a deadline if dynamic and unused
	nox_alloc_hdr* next;    // 8
	nox_alloc_hdr* field_3; // 12
} nox_alloc_hdr;

typedef struct nox_alloc_class {
	char name[ALLOC_CLASS_NAME_MAX]; // 0, 0, 0
	int size;                        // 22, 0x58, 88
	int cnt1;                        // 23
	nox_alloc_hdr* first_free;       // 24, points to items
	nox_alloc_hdr* last_free;        // 25, points to items
	nox_alloc_hdr* first_free_add;   // 26, allocated separately
	nox_alloc_hdr* last_free_add;    // 27, allocated separately
	nox_alloc_hdr* field_28;         // 28
	void* items;                     // 29, preallocated linear array
	int can_grow;                    // 30
	int field_31;                    // 31
	uint64_t ticks;                  // 32
	int field_34;                    // 34
	int field_35;                    // 35
	int cnt2;                        // 36
	unsigned int field_37;           // 37
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
nox_alloc_class* nox_new_alloc_class(const char* name, int size, int cnt);
nox_alloc_class* nox_new_alloc_class_dynamic(const char* name, int size, int cnt);
#else                                          // NOX_CGO
nox_alloc_class* nox_new_alloc_class(char* name, int size, int cnt);
nox_alloc_class* nox_new_alloc_class_dynamic(char* name, int size, int cnt);
#endif                                         // NOX_CGO
void nox_free_alloc_class(nox_alloc_class* p); // idb
void* nox_alloc_class_new_obj(nox_alloc_class* p);
void* nox_alloc_class_new_obj_zero(nox_alloc_class* p);
void nox_alloc_class_yyy_4144D0(nox_alloc_class* p);
void nox_alloc_class_free_obj(nox_alloc_class* p, void* obj);
void nox_alloc_class_xxx_414400(nox_alloc_class* p, void* obj);

#endif // NOX_COMMON_ALLOC_CLASS_H
