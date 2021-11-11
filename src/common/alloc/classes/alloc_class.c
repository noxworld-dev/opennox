//+build none

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../platform/platform.h"
#include "alloc_class.h"

#define ALLOC_DEAD_CHAR 0xAC

//----- (00414130) --------------------------------------------------------
void nox_free_alloc_class_dynamic(nox_alloc_class* p) {
	if (!p)
		return;

	if (p->first_free_add) {
		nox_alloc_hdr* ptr = p->first_free_add;
		while (ptr) {
			nox_alloc_hdr* next = ptr->next;
			free(ptr);
			ptr = next;
		}
	}

	if (p->field_28) {
		nox_alloc_hdr* ptr = p->field_28;
		while (ptr) {
			nox_alloc_hdr* next = ptr->next;
			if (ptr->expires)
				free(ptr);
			ptr = next;
		}
	}

	p->first_free_add = 0;
	p->last_free_add = 0;
}

//----- (00413FE0) --------------------------------------------------------
nox_alloc_class* nox_new_alloc_class(const char* name, int size, int cnt) {
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

		h->expires = 0;
		h->next = p->first_free;
		p->first_free = h;
		if (i != 0)
			p->last_free = h;
	}
	p->size = size;
	p->cnt1 = cnt;
	p->cnt2 = cnt;
	p->ticks = 0;
	p->first_free_add = 0;
	p->last_free_add = 0;
	p->field_31 = 0;
	return p;
}

//----- (004140D0) --------------------------------------------------------
nox_alloc_class* nox_new_alloc_class_dynamic(const char* name, int size, int cnt) {
	nox_alloc_class* p = nox_new_alloc_class(name, size, cnt);
	if (!p)
		return 0;
	p->can_grow = 1;
	return p;
}

//----- (00414100) --------------------------------------------------------
void nox_free_alloc_class(nox_alloc_class* p) {
	if (!p)
		return;
	if (p->can_grow)
		nox_free_alloc_class_dynamic(p);
	free(p->items);
	free(p);
}

//----- (00414190) --------------------------------------------------------
void nox_alloc_maybe_free_dynamic(nox_alloc_class* al) {
	uint64_t ticks = nox_platform_get_ticks();
	if (ticks == al->ticks) {
		return;
	}
	for (nox_alloc_hdr* i = al->first_free_add; i; i = i->next) {
		if (ticks <= i->expires) {
			continue;
		}
		nox_alloc_hdr* v13 = i->next;
		nox_alloc_hdr* v15 = i->field_3;
		if (v15)
			v15->next = v13;
		else
			al->first_free_add = v13;

		nox_alloc_hdr* v16 = i->next;
		if (v16)
			v16->field_3 = i->field_3;
		else
			al->last_free_add = i->field_3;
		al->field_31--;
		free(i);
	}
	al->ticks = ticks;
}
void* nox_alloc_class_new_obj(nox_alloc_class* al) {
	if (!al)
		return 0;
	nox_alloc_hdr* h = al->first_free;
	nox_alloc_hdr** dst;
	if (h) {
		// still have free items in the linear memory segment
		dst = &h->next;
		al->first_free = h->next;
		if (!h->next)
			al->last_free = 0;
	} else {
		// no more free items
		if (!al->first_free_add) {
			// allocate new items as needed, if we are allowed to
			if (!al->can_grow)
				return 0;
			nox_alloc_hdr* item = calloc(1, al->size + sizeof(nox_alloc_hdr));
			al->first_free_add = item;
			al->field_31++;
			if (!item)
				return 0;
			al->cnt2++;
			item->expires = 1;
			item->next = 0;
			item->field_3 = 0;
			al->last_free_add = item;
		}
		// pick existing free dynamic item
		h = al->first_free_add;
		dst = &h->next;
		al->first_free_add = h->next;
		if (!h->next)
			al->last_free_add = 0;
		if (!h)
			return 0;
	}
	h->field_3 = 0;
	nox_alloc_hdr* v10 = al->field_28;
	*dst = v10;
	if (v10) {
		v10->field_3 = h;
	}
	al->field_28 = h;
	nox_alloc_maybe_free_dynamic(al);
	al->field_35++;
	if (al->field_35 > al->field_34) {
		al->field_34 = al->field_35;
	}
	return (void*)(h + 1);
}

//----- (004142F0) --------------------------------------------------------
void* nox_alloc_class_new_obj_zero(nox_alloc_class* al) {
	void* data = (void*)nox_alloc_class_new_obj(al);
	if (!data)
		return 0;
	memset(data, 0, al->size);
	return data;
}

//----- (004144D0) --------------------------------------------------------
void nox_alloc_class_free_all(nox_alloc_class* al) {
	if (!al)
		return;

	if (al->can_grow)
		nox_free_alloc_class_dynamic(al);

	if (al->field_28) {
		nox_alloc_hdr* g1 = al->field_28;
		nox_alloc_hdr* v1 = g1;
		nox_alloc_hdr* g2 = 0;
		do {
			g2 = v1->next;
			memset((void*)(v1 + 1), ALLOC_DEAD_CHAR, al->size);
			int v2 = al->first_free;
			if (!v2)
				al->last_free = g1;
			g1->next = v2;
			al->first_free = g1;
			v1 = g2;
			g1 = g2;
		} while (g2);
	}
	al->first_free_add = 0;
	al->last_free_add = 0;
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
		v3->next = hdr->next;
	else
		al->field_28 = hdr->next;

	nox_alloc_hdr* v4 = hdr->next;
	if (v4) {
		v4->field_3 = hdr->field_3;
	}
}

//----- (00414330) --------------------------------------------------------
void nox_alloc_class_free_obj_first(nox_alloc_class* al, void* obj) {
	if (!obj)
		return;

	nox_alloc_hdr* hdr = (nox_alloc_hdr*)obj - 1;
	nox_alloc_class_zzz_4143D0(al, obj);
	al->field_35--;
	if (hdr->expires) {
		if (!al->last_free_add)
			al->last_free_add = hdr;

		hdr->next = al->first_free_add;
		hdr->field_3 = 0;
		al->first_free_add = hdr;

		hdr->expires = nox_platform_get_ticks() + 10000;
	} else {
		if (!al->last_free)
			al->last_free = hdr;

		hdr->next = al->first_free;
		hdr->field_3 = 0;
		al->first_free = hdr;
	}
	memset(obj, ALLOC_DEAD_CHAR, al->size);
}

//----- (00414400) --------------------------------------------------------
void nox_alloc_class_free_obj_last(nox_alloc_class* al, void* obj) {
	if (!obj)
		return;

	nox_alloc_hdr* hdr = (nox_alloc_hdr*)obj - 1;
	nox_alloc_class_zzz_4143D0(al, obj);
	al->field_35--;
	if (hdr->expires) {
		if (!al->first_free_add)
			al->first_free_add = hdr;
		hdr->next = 0;
		hdr->field_3 = al->last_free_add;
		nox_alloc_hdr* v4 = al->last_free_add;
		if (v4)
			v4->next = hdr;
		al->last_free_add = hdr;
		hdr->expires = nox_platform_get_ticks() + 10000;
	} else {
		if (!al->first_free)
			al->first_free = hdr;
		hdr->next = 0;
		hdr->field_3 = al->last_free;
		nox_alloc_hdr* v3 = al->last_free;
		if (v3)
			v3->next = hdr;
		al->last_free = hdr;
	}
	memset(obj, ALLOC_DEAD_CHAR, al->size);
}

//----- (004144B0) --------------------------------------------------------
void nox_alloc_class_reset_stats(nox_alloc_class* p) {
	p->field_34 = p->field_35;
}

void nox_alloc_class_obj_keep(nox_alloc_class* p, int off) {
	// do nothing, since we don't clean an object
}
