#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "alloc_class.h"
#include "../../platform/platform.h"

unsigned int dword_5d4594_252276 = 0;
unsigned int dword_5d4594_338300 = 0;

//----- (00414130) --------------------------------------------------------
void  nox_free_alloc_class_f30(nox_alloc_class* p) {
	if (!p)
		return;

	if (p->field_26) {
		unsigned int* ptr = (unsigned int*)p->field_26;
		while (ptr) {
			unsigned int* next = (unsigned int*)ptr[2];
			free(ptr);
			ptr = next;
		}
	}

	if (p->field_28) {
		unsigned int* ptr = (unsigned int*)p->field_28;
		while (ptr) {
			unsigned int* next = (unsigned int*)ptr[2];
			if (*(uint64_t*)ptr)
				free(ptr);
			ptr = next;
		}
	}

	p->field_26 = 0;
	p->field_27 = 0;
}

#ifndef NOX_CGO
//----- (00413FE0) --------------------------------------------------------
nox_alloc_class*  nox_new_alloc_class(const char* name, int size, int cnt) {
	nox_alloc_class* p = (nox_alloc_class*)calloc(1, sizeof(nox_alloc_class));
	if (!p)
		return 0;
	if (!name)
		return 0;
	if (size <= 0)
		return 0;
	if (cnt <= 0)
		return 0;
	strcpy(&p->name[0], name);

	char sbuf[80];
	sprintf(sbuf, "%s (Allocation Class)", name);

	int isize = size + sizeof(nox_alloc_hdr);
	void* items = calloc(cnt, isize);
	p->items = items;

	if (!items)
		return 0;

	for (int i = 0; i < cnt; i++) {
		nox_alloc_hdr* h = (nox_alloc_hdr*)((char*)p->items + isize * i);

		h->field_0 = 0;
		h->field_1 = 0;
		h->field_2 = p->field_24;
		p->field_24 = h;
		if (i != 0)
			p->field_25 = h;
	}
	p->size = size;
	p->cnt1 = cnt;
	p->cnt2 = cnt;
	p->ticks = 0;
	p->field_26 = 0;
	p->field_27 = 0;
	p->field_31 = 0;
	return p;
}

//----- (004140D0) --------------------------------------------------------
nox_alloc_class*  nox_new_alloc_class_f30(const char* name, int size, int cnt) {
	nox_alloc_class* p = nox_new_alloc_class(name, size, cnt);
	if (!p)
		return 0;
	p->field_30 = 1;
	return p;
}

//----- (00414100) --------------------------------------------------------
void  nox_free_alloc_class(nox_alloc_class* p) {
	if (!p)
		return;
	if (p->field_30)
		nox_free_alloc_class_f30(p);
	free(p->items);
	free(p);
}
#endif // NOX_CGO

//----- (00414190) --------------------------------------------------------
void* nox_alloc_class_new_obj(nox_alloc_class* al) {
	if (!al)
		return 0;
	int v2 = al->field_24;
	unsigned int* v4;
	if (v2) {
		int v3 = *(unsigned int*)(v2 + 8);
		v4 = (unsigned int*)(v2 + 8);
		al->field_24 = v3;
		if (!v3)
			al->field_25 = 0;
	} else {
		if (!al->field_26) {
			if (!al->field_30)
				return 0;
			unsigned int* v5 = malloc(al->size + 16); // TODO: sizeof(nox_alloc_hdr) ?
			al->field_26 = v5;
			al->field_31++;
			if (!v5)
				return 0;
			al->cnt2++;
			v5[2] = 0;
			*(unsigned int*)(al->field_26 + 12) = 0;
			unsigned int* v7 = (unsigned int*)al->field_26;
			v7[0] = 1;
			v7[1] = 0;
			al->field_27 = al->field_26;
		}
		v2 = al->field_26;
		int v8 = *(unsigned int*)(v2 + 8);
		v4 = (unsigned int*)(v2 + 8);
		al->field_26 = v8;
		if (!v8)
			al->field_27 = 0;
		if (!v2)
			return 0;
	}
	int v9 = al->field_28;
	*(unsigned int*)(v2 + 12) = 0;
	*v4 = v9;
	int v10 = al->field_28;
	if (v10) {
		*(unsigned int*)(v10 + 12) = v2;
	}
	al->field_28 = v2;
	int v20 = v2 + 16;
	uint64_t ticks = nox_platform_get_ticks();
	if (ticks != al->ticks) {
		unsigned int* v12 = (unsigned int*)al->field_26;
		if (v12) {
			unsigned int* v14;
			do {
				int v13 = v12[2];
				v14 = (unsigned int*)v12[2];
				if (ticks > *(uint64_t*)v12) {
					int v15 = v12[3];
					if (v15)
						*(unsigned int*)(v15 + 8) = v13;
					else
						al->field_26 = v13;
					int v16 = v12[2];
					if (v16)
						*(unsigned int*)(v16 + 12) = v12[3];
					else
						al->field_27 = v12[3];
					--al->field_31;
					free(v12);
				}
				v12 = v14;
			} while (v14);
		}
		al->ticks = ticks;
	}
	al->field_35++;
	if (al->field_35 > al->field_34) {
		al->field_34 = al->field_35;
	}
	return v20;
}

#ifndef NOX_CGO
//----- (004142F0) --------------------------------------------------------
void*  nox_alloc_class_new_obj_zero(nox_alloc_class* al) {
	void* v1 = (void*)nox_alloc_class_new_obj(al);
	if (!v1)
		return 0;
	memset(v1, 0, al->size);
	return v1;
}
#endif // NOX_CGO

//----- (004144D0) --------------------------------------------------------
void  nox_alloc_class_yyy_4144D0(nox_alloc_class* al) {
	unsigned int* a1 = al;
	int v1; // edx
	int v2; // eax

	if (a1) {
		if (a1[30])
			nox_free_alloc_class_f30(a1);
		dword_5d4594_252276 = a1[28];
		v1 = dword_5d4594_252276;
		if (dword_5d4594_252276) {
			do {
				dword_5d4594_338300 = *(unsigned int*)(v1 + 8);
				memset((void*)(v1 + 16), 0xACu, a1[22]);
				v2 = a1[24];
				if (!v2)
					a1[25] = dword_5d4594_252276;
				*(unsigned int*)(dword_5d4594_252276 + 8) = v2;
				a1[24] = dword_5d4594_252276;
				v1 = dword_5d4594_338300;
				dword_5d4594_252276 = dword_5d4594_338300;
			} while (dword_5d4594_338300);
		}
		a1[28] = 0;
		a1[26] = 0;
		a1[27] = 0;
		a1[35] = 0;
	}
}

//----- (004143D0) --------------------------------------------------------
int  sub_4143D0(int a1, int a2) {
	int result; // eax
	int v3;     // ecx
	int v4;     // ecx

	result = a2;
	if (a2) {
		v3 = *(unsigned int*)(a2 - 4);
		if (v3)
			*(unsigned int*)(v3 + 8) = *(unsigned int*)(a2 - 8);
		else
			*(unsigned int*)(a1 + 112) = *(unsigned int*)(a2 - 8);
		v4 = *(unsigned int*)(a2 - 8);
		if (v4) {
			result = *(unsigned int*)(a2 - 4);
			*(unsigned int*)(v4 + 12) = result;
		}
	}
	return result;
}

//----- (00414330) --------------------------------------------------------
void  nox_alloc_class_free_obj(nox_alloc_class* al, void* obj) {
	unsigned int* a1 = al;
	uint64_t* a2 = obj;
	uint64_t* v2;      // esi
	unsigned int v3; // ecx
	unsigned int v4; // edx

	if (a2) {
		v2 = a2 - 2;
		sub_4143D0((int)a1, a2);
		--a1[35];
		if (*(a2 - 2)) {
			if (!a1[27])
				a1[27] = (unsigned int)v2;
			v4 = a1[26];
			*((unsigned int*)v2 + 3) = 0;
			*((unsigned int*)v2 + 2) = v4;
			a1[26] = (unsigned int)v2;
			*v2 = nox_platform_get_ticks() + 10000;
		} else {
			if (!a1[25])
				a1[25] = (unsigned int)v2;
			v3 = a1[24];
			*((unsigned int*)v2 + 3) = 0;
			*((unsigned int*)v2 + 2) = v3;
			a1[24] = (unsigned int)v2;
		}
		memset(a2, 0xACu, a1[22]);
	}
}

//----- (00414400) --------------------------------------------------------
void  nox_alloc_class_xxx_414400(nox_alloc_class* al, void* obj) {
	unsigned int* a1 = al;
	uint64_t* a2 = obj;
	uint64_t* v2;      // esi
	unsigned int v3; // eax
	unsigned int v4; // eax

	if (a2) {
		v2 = a2 - 2;
		sub_4143D0((int)a1, (int)a2);
		--a1[35];
		if (*(a2 - 2)) {
			if (!a1[26])
				a1[26] = (unsigned int)v2;
			*((unsigned int*)v2 + 2) = 0;
			*((unsigned int*)v2 + 3) = a1[27];
			v4 = a1[27];
			if (v4)
				*(unsigned int*)(v4 + 8) = v2;
			a1[27] = (unsigned int)v2;
			*v2 = nox_platform_get_ticks() + 10000;
		} else {
			if (!a1[24])
				a1[24] = (unsigned int)v2;
			*((unsigned int*)v2 + 2) = 0;
			*((unsigned int*)v2 + 3) = a1[25];
			v3 = a1[25];
			if (v3)
				*(unsigned int*)(v3 + 8) = v2;
			a1[25] = (unsigned int)v2;
		}
		memset(a2, 0xACu, a1[22]);
	}
}
