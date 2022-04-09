#ifndef NOX_COMMON_ALLOC_CLASS_H
#define NOX_COMMON_ALLOC_CLASS_H

typedef struct nox_alloc_class nox_alloc_class;

nox_alloc_class* nox_new_alloc_class(char* name, int size, int cnt);
nox_alloc_class* nox_new_alloc_class_dynamic(char* name, int size, int cnt);
void nox_free_alloc_class(nox_alloc_class* p); // idb
void* nox_alloc_class_new_obj(nox_alloc_class* p);
void* nox_alloc_class_new_obj_zero(nox_alloc_class* p);
void nox_alloc_class_free_all(nox_alloc_class* p);
void nox_alloc_class_free_obj_first(nox_alloc_class* p, void* obj);
void nox_alloc_class_free_obj_last(nox_alloc_class* p, void* obj);
void nox_alloc_class_reset_stats(nox_alloc_class* p);
void nox_alloc_class_obj_keep(nox_alloc_class* p, int off);

#endif // NOX_COMMON_ALLOC_CLASS_H
