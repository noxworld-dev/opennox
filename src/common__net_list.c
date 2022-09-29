#include <stdbool.h>
#include <stdlib.h>

#include "common__net_list.h"
#include "defs.h" // for nox_playerInfo and NOX_PLAYERINFO_MAX

nox_net_list_t* nox_net_lists[3][NOX_PLAYERINFO_MAX] = {0};

//----- (00420BC0) --------------------------------------------------------
int nox_netlist_count_420BC0(nox_net_list_t* p) {
	if (!p) {
		return 0;
	}
	return p->count; //_fileno(p);
}

//----- (0040E9D0) --------------------------------------------------------
int nox_netlist_countByInd_40E9D0(int ind1, int ind2) { return nox_netlist_count_420BC0(nox_net_lists[ind2][ind1]); }

//----- (0040F0B0) --------------------------------------------------------
int nox_netlist_countByInd2_40F0B0(int ind) { return nox_netlist_countByInd_40E9D0(ind, 2); }

//----- (004209C0) --------------------------------------------------------
void nox_netlist_free_item_4209C0(nox_net_list_t* list, nox_net_list_item_t* item) {
	nox_alloc_class_free_obj_first(list->alloc, item);
}

//----- (004209E0) --------------------------------------------------------
void nox_netlist_findAndFreeBuf_4209E0(nox_net_list_t* list, unsigned char* buf) {
	if (!list->first) {
		return;
	}

	nox_net_list_item_t* item = 0;
	for (nox_net_list_item_t* p = list->first; p; p = p->next) {
		if (p->buf == buf) {
			item = p;
			break;
		}
	}
	if (!item) {
		return;
	}
	list->count--;
	list->size -= item->size;

	nox_net_list_item_t* next = item->next;
	if (next) {
		next->prev = item->prev;
	} else {
		list->last = item->prev;
	}

	nox_net_list_item_t* prev = item->prev;
	if (prev) {
		prev->next = item->next;
	} else {
		list->first = item->next;
	}

	nox_netlist_free_item_4209C0(list, item);
}

//----- (0040F000) --------------------------------------------------------
void nox_netlist_findAndFreeBuf_40F000(int ind, unsigned char* buf) {
	nox_netlist_findAndFreeBuf_4209E0(nox_net_lists[2][ind], buf);
}

//----- (00420A60) --------------------------------------------------------
void sub_420A60(nox_net_list_t* list, int (*fnc)(unsigned int, int), int a3) {
	if (!list->first) {
		return;
	}
	for (nox_net_list_item_t* p = list->first; p; p = p->next) {
		if (fnc(p->buf, a3)) {
			break;
		}
	}
}

//----- (0040F0F0) --------------------------------------------------------
void nox_netlist_forEach2_40F0F0(int ind, int (*fnc)(unsigned int, int), int a3) {
	if (fnc && a3) {
		sub_420A60(nox_net_lists[2][ind], fnc, a3);
	}
}
