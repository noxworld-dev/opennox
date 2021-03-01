#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "alloc_class.h"
#include "../../platform/platform.h"

#define ALLOC_DEAD_CHAR 0xAC

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

		h->ticks = 0;
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
	nox_alloc_hdr* h = al->field_24;
	nox_alloc_hdr** dst;
	if (h) {
		dst = &h->field_2;
		al->field_24 = h->field_2;
		if (!h->field_2)
			al->field_25 = 0;
	} else {
		if (!al->field_26) {
			if (!al->field_30)
				return 0;
			nox_alloc_hdr* item = malloc(al->size + sizeof(nox_alloc_hdr));
			al->field_26 = item;
			al->field_31++;
			if (!item)
				return 0;
			al->cnt2++;
			item->ticks = 1;
			item->field_2 = 0;
			item->field_3 = 0;
			al->field_27 = item;
		}
		h = al->field_26;
		dst = &h->field_2;
		al->field_26 = h->field_2;
		if (!h->field_2)
			al->field_27 = 0;
		if (!h)
			return 0;
	}
	h->field_3 = 0;
	*dst = al->field_28;
	nox_alloc_hdr* v10 = al->field_28;
	if (v10) {
		v10->field_3 = h;
	}
	al->field_28 = h;
	void* data = (void*)(h + 1);
	uint64_t ticks = nox_platform_get_ticks();
	if (ticks != al->ticks) {
		for (nox_alloc_hdr* i = al->field_26; i; i = i->field_2) {
			if (ticks > i->ticks) {
				nox_alloc_hdr* v13 = i->field_2;
				nox_alloc_hdr* v15 = i->field_3;
				if (v15)
					v15->field_2 = v13;
				else
					al->field_26 = v13;
				nox_alloc_hdr* v16 = i->field_2;
				if (v16)
					v16->field_3 = i->field_3;
				else
					al->field_27 = i->field_3;
				al->field_31--;
				free(i);
			}
		}
		al->ticks = ticks;
	}
	al->field_35++;
	if (al->field_35 > al->field_34) {
		al->field_34 = al->field_35;
	}
	return data;
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
	if (!al)
		return;

	if (al->field_30)
		nox_free_alloc_class_f30(al);

	if (al->field_28) {
		int g1 = al->field_28;
		int v1 = g1;
		int g2 = 0;
		do {
			g2 = *(unsigned int*)(v1 + 8);
			memset((void*)(v1 + 16), ALLOC_DEAD_CHAR, al->size);
			int v2 = al->field_24;
			if (!v2)
				al->field_25 = g1;
			*(unsigned int*)(g1 + 8) = v2;
			al->field_24 = g1;
			v1 = g2;
			g1 = g2;
		} while (g2);
	}
	al->field_26 = 0;
	al->field_27 = 0;
	al->field_28 = 0;
	al->field_35 = 0;
}

//----- (004143D0) --------------------------------------------------------
void nox_alloc_class_zzz_4143D0(nox_alloc_class* al, void* obj) {
	if (!obj)
		return;

	nox_alloc_hdr* hdr = (nox_alloc_hdr*)obj - 1;

	nox_alloc_hdr* v3 = hdr->field_3;
	if (v3)
		v3->field_2 = hdr->field_2;
	else
		al->field_28 = hdr->field_2;

	nox_alloc_hdr* v4 = hdr->field_2;
	if (v4) {
		v4->field_3 = hdr->field_3;
	}
}

//----- (00414330) --------------------------------------------------------
void  nox_alloc_class_free_obj(nox_alloc_class* al, void* obj) {
	if (!obj)
		return;

	nox_alloc_hdr* hdr = (nox_alloc_hdr*)obj - 1;
	nox_alloc_class_zzz_4143D0(al, obj);
	al->field_35--;
	if (hdr->ticks) {
		if (!al->field_27)
			al->field_27 = hdr;

		hdr->field_2 = al->field_26;
		hdr->field_3 = 0;
		al->field_26 = hdr;

		hdr->ticks = nox_platform_get_ticks() + 10000;
	} else {
		if (!al->field_25)
			al->field_25 = hdr;

		hdr->field_2 = al->field_24;
		hdr->field_3 = 0;
		al->field_24 = hdr;
	}
	memset(obj, ALLOC_DEAD_CHAR, al->size);
}

//----- (00414400) --------------------------------------------------------
void  nox_alloc_class_xxx_414400(nox_alloc_class* al, void* obj) {
	if (!obj)
		return;

	nox_alloc_hdr* hdr = (nox_alloc_hdr*)obj - 1;
	nox_alloc_class_zzz_4143D0(al, obj);
	al->field_35--;
	if (hdr->ticks) {
		if (!al->field_26)
			al->field_26 = hdr;
		hdr->field_2 = 0;
		hdr->field_3 = al->field_27;
		nox_alloc_hdr* v4 = al->field_27;
		if (v4)
			v4->field_2 = hdr;
		al->field_27 = hdr;
		hdr->ticks = nox_platform_get_ticks() + 10000;
	} else {
		if (!al->field_24)
			al->field_24 = hdr;
		hdr->field_2 = 0;
		hdr->field_3 = al->field_25;
		nox_alloc_hdr* v3 = al->field_25;
		if (v3)
			v3->field_2 = hdr;
		al->field_25 = hdr;
	}
	memset(obj, ALLOC_DEAD_CHAR, al->size);
}
