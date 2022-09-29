#include <stdbool.h>
#include <stdlib.h>

#include "common__net_list.h"
#include "defs.h" // for nox_playerInfo and NOX_PLAYERINFO_MAX

nox_net_list_t* nox_net_lists[3][NOX_PLAYERINFO_MAX] = {0};

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
