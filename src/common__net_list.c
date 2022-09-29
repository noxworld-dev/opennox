#include <stdbool.h>
#include <stdlib.h>

#include "common__net_list.h"
#include "defs.h" // for nox_playerInfo and NOX_PLAYERINFO_MAX

// TODO: link to those properly
nox_playerInfo* nox_common_playerInfoFromNum_417090(int i);
int nox_xxx_netSendReadPacket_5528B0(unsigned int a1, char a2);
int nox_netlist_receiveCli_494E90(int a1);

typedef struct {
	unsigned char buf[2048];
	unsigned int cur;
} nox_net_lists_buf_t;

nox_net_list_t* nox_net_lists[3][NOX_PLAYERINFO_MAX] = {0};
unsigned char nox_net_lists_buf[2048] = {0};
nox_net_lists_buf_t nox_net_lists_buf_arr[3][NOX_PLAYERINFO_MAX] = {0};

//----- (00420BC0) --------------------------------------------------------
int nox_netlist_count_420BC0(nox_net_list_t* p) {
	if (!p) {
		return 0;
	}
	return p->count; //_fileno(p);
}

//----- (00420BD0) --------------------------------------------------------
int nox_netlist_size_420BD0(nox_net_list_t* p) {
	if (!p) {
		return 0;
	}
	return p->size;
}

//----- (0040E9D0) --------------------------------------------------------
int nox_netlist_countByInd_40E9D0(int ind1, int ind2) { return nox_netlist_count_420BC0(nox_net_lists[ind2][ind1]); }

//----- (0040E9F0) --------------------------------------------------------
int nox_netlist_sizeByInd_40E9F0(int ind1, int ind2) { return nox_netlist_size_420BD0(nox_net_lists[ind2][ind1]); }

//----- (0040F0B0) --------------------------------------------------------
int nox_netlist_countByInd2_40F0B0(int ind) { return nox_netlist_countByInd_40E9D0(ind, 2); }

//----- (0040F0D0) --------------------------------------------------------
int nox_netlist_sizeByInd2_40F0D0(int ind) { return nox_netlist_sizeByInd_40E9F0(ind, 2); }

//----- (004208F0) --------------------------------------------------------
void nox_netlist_freeMsgList_4208F0(nox_net_list_t* p) {
	nox_free_alloc_class(p->alloc);
	free(p);
}

//----- (0040EA70) --------------------------------------------------------
void nox_netlist_free_40EA70() {
	for (int i = 0; i < NOX_PLAYERINFO_MAX; i++) {
		if (nox_net_lists[1][i]) {
			nox_netlist_freeMsgList_4208F0(nox_net_lists[1][i]);
		}
		if (nox_net_lists[0][i]) {
			nox_netlist_freeMsgList_4208F0(nox_net_lists[0][i]);
		}
		if (nox_net_lists[2][i]) {
			nox_netlist_freeMsgList_4208F0(nox_net_lists[2][i]);
		}
	}
}

//----- (0040EAC0) --------------------------------------------------------
bool nox_netlist_checkSizes_40EAC0(int ind1, int ind2, int sz) {
	if (ind2 == 1) {
		int psz = nox_netlist_sizeByInd_40E9F0(ind1, 1);
		if (psz + sz + nox_netlist_sizeByInd_40E9F0(ind1, 2) > NOX_NETBUF_MAX_SIZE) {
			return 0;
		}
	} else {
		if (sz + nox_netlist_sizeByInd_40E9F0(ind1, ind2) > NOX_NETBUF_MAX_SIZE) {
			return 0;
		}
	}
	return nox_netlist_count_420BC0(nox_net_lists[ind2][ind1]) < NOX_NETBUF_MAX_PACKETS;
}

//----- (0040EB60) --------------------------------------------------------
bool nox_netlist_checkSizesExt_40EB60(int ind1, int ind2, int sz, int sz2) {
	nox_net_list_t* p = nox_net_lists[ind2][ind1];
	int psz = nox_netlist_size_420BD0(p);
	if (sz + psz + sz2 > NOX_NETBUF_MAX_SIZE) {
		return 0;
	}
	return nox_netlist_count_420BC0(p) < NOX_NETBUF_MAX_PACKETS;
}

//----- (0040EC30) --------------------------------------------------------
unsigned char* nox_netlist_sendByInd_40EC30(int ind1, int ind2, unsigned char* buf, int sz) {
	if (!buf || sz <= 0) {
		return 0;
	}
	nox_net_lists_buf_t* p = &nox_net_lists_buf_arr[ind2 + 1][ind1];
	int i = p->cur;
	if (i + sz > 2048) {
		return 0;
	}
	memcpy(&p->buf[i], buf, sz);
	p->cur += sz;
	return &p->buf[i];
}

//----- (00420940) --------------------------------------------------------
int nox_netlist_add_420940(nox_net_list_t* list, int buf, int sz, bool append) {
	// _dprintf("len %d: %08X %08X", sz, ((unsigned int*)buf)[0], ((unsigned int*)buf)[1]);

	nox_net_list_item_t* item = nox_alloc_class_new_obj_zero(list->alloc);
	if (!item) {
		return 0;
	}
	item->buf = buf;
	item->size = sz;
	if (append) {
		item->prev = list->last;
		item->next = 0;
		if (list->last) {
			list->last->next = item;
		} else {
			list->first = item;
		}
		list->last = item;
	} else {
		item->prev = 0;
		item->next = list->first;
		if (list->first) {
			list->first->prev = item;
		} else {
			list->last = item;
		}
		list->first = item;
	}
	list->count++;
	list->size += sz;
	return 1;
}

//----- (0040EBC0) --------------------------------------------------------
int nox_netlist_addToMsgListCli_40EBC0(int ind1, int ind2, unsigned char* buf, int sz) {
	nox_net_list_t* p = nox_net_lists[ind2][ind1];
	if (sz <= 0) {
		return 1;
	}
	if (!nox_netlist_checkSizes_40EAC0(ind1, ind2, sz)) {
		return 0;
	}
	unsigned char* out = nox_netlist_sendByInd_40EC30(ind1, ind2, buf, sz);
	if (!out) {
		return 0;
	}
	nox_netlist_add_420940(p, out, sz, 1);
	return 1;
}

//----- (0040ECA0) --------------------------------------------------------
int nox_netlist_clientSend_0_40ECA0(int ind1, int ind2, unsigned char* buf, int sz, int sz2) {
	nox_net_list_t* p = nox_net_lists[ind2][ind1];
	if (sz <= 0) {
		return 1;
	}
	if (!nox_netlist_checkSizesExt_40EB60(ind1, ind2, sz, sz2)) {
		return 0;
	}
	unsigned char* out = nox_netlist_sendByInd_40EC30(ind1, ind2, buf, sz);
	if (!out) {
		return 0;
	}
	nox_netlist_add_420940(p, out, sz, 1);
	return 1;
}

//----- (0040ED40) --------------------------------------------------------
void nox_xxx_netBufsSetZero_40ED40(int ind, int ind2) { nox_net_lists_buf_arr[ind2 + 1][ind].cur = 0; }

//----- (0040F040) --------------------------------------------------------
void sub_40F040(int ind) { nox_net_lists_buf_arr[0][ind].cur = 0; }

//----- (00420830) --------------------------------------------------------
void nox_netlist_resetList_420830(nox_net_list_t* p) {
	p->first = 0;
	p->last = 0;
	p->field_2 = 0;
	p->count = 0;
	p->size = 0;
	nox_alloc_class_free_all(p->alloc);
}

//----- (0040ED10) --------------------------------------------------------
void nox_netlist_resetByInd_40ED10(int ind1, int ind2) {
	nox_net_list_t* p = nox_net_lists[ind2][ind1];
	if (p) {
		nox_netlist_resetList_420830(p);
		nox_xxx_netBufsSetZero_40ED40(ind1, ind2);
	}
}

//----- (0040F020) --------------------------------------------------------
void nox_netlist_initPlayerBufs_40F020(int ind) {
	nox_netlist_resetList_420830(nox_net_lists[2][ind]);
	sub_40F040(ind);
}

//----- (0040EE90) --------------------------------------------------------
void nox_netlist_resetAllInList_40EE90(int ind) {
	for (int i = 0; i < NOX_PLAYERINFO_MAX; ++i) {
		nox_netlist_resetByInd_40ED10(i, ind);
	}
}

//----- (0040EE60) --------------------------------------------------------
void nox_netlist_resetAll_40EE60() {
	for (int i = 0; i < NOX_PLAYERINFO_MAX; ++i) {
		nox_netlist_resetByInd_40ED10(i, 1);
		nox_netlist_resetByInd_40ED10(i, 0);
		nox_netlist_initPlayerBufs_40F020(i);
	}
}

//----- (004209C0) --------------------------------------------------------
void nox_netlist_free_item_4209C0(nox_net_list_t* list, nox_net_list_item_t* item) {
	nox_alloc_class_free_obj_first(list->alloc, item);
}

//----- (00420A90) --------------------------------------------------------
unsigned int* nox_netlist_get_420A90(nox_net_list_t* list, unsigned int* outSz) {
	if (!list->first) {
		return 0;
	}
	nox_net_list_item_t* item = list->first;

	*outSz = item->size;

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

	unsigned char* buf = item->buf;
	nox_netlist_free_item_4209C0(list, item);
	return buf;
}

//----- (0040ED60) --------------------------------------------------------
unsigned char* nox_netlist_copyPacketList_40ED60(int ind1, int ind2, unsigned int* outSz) {
	nox_net_list_t* list = nox_net_lists[ind2][ind1];
	unsigned int cnt = 0;
	memset(nox_net_lists_buf, 0, sizeof(nox_net_lists_buf));
	while (1) {
		unsigned int sz = 0;
		unsigned char* src = nox_netlist_get_420A90(list, &sz);
		if (!src) {
			break; // no more data
		}
		if (cnt + sz > sizeof(nox_net_lists_buf)) {
			// TODO: is it okay that it discards data?
			break;
		}
		memcpy(&nox_net_lists_buf[cnt], src, sz);
		cnt += sz;
	}
	*outSz = cnt;
	return nox_net_lists_buf;
}

//----- (0040EEB0) --------------------------------------------------------
unsigned char* nox_netlist_getInd_40EEB0(int ind1, int ind2, unsigned int* outSz) {
	return nox_netlist_get_420A90(nox_net_lists[ind2][ind1], outSz);
}

//----- (0040EEF0) --------------------------------------------------------
bool sub_40EEF0(int ind, int a2) {
	if ((unsigned int)(a2 + nox_netlist_size_420BD0(nox_net_lists[2][ind])) > NOX_NETBUF_MAX_SIZE) {
		return 0;
	}
	return nox_netlist_count_420BC0(nox_net_lists[2][ind]) < NOX_NETBUF_MAX_PACKETS;
}

//----- (0040F080) --------------------------------------------------------
unsigned char* nox_netlist_getByInd2_40F080(int ind, unsigned int* outSz) {
	return nox_netlist_get_420A90(nox_net_lists[2][ind], outSz);
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

//----- (0040EFA0) --------------------------------------------------------
char* nox_xxx_netlistAdd_40EFA0(int ind, unsigned char* buf, int sz) {
	if (!buf || sz <= 0) {
		return 0;
	}
	nox_net_lists_buf_t* p = &nox_net_lists_buf_arr[0][ind];
	int i = p->cur;
	if (i + sz > 2048) {
		return 0;
	}
	memcpy(&p->buf[i], buf, sz);
	p->cur += sz;
	return &p->buf[i];
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

//----- (0040EF40) --------------------------------------------------------
bool nox_netlist_addToMsgListSrv_40EF40(int ind, unsigned char* buf, int sz) {
	if (sz <= 0) {
		return 1;
	}
	// If there are too many updates, then we may run out of space in a single
	// packet. Instead of fragmenting, we can instead send additional packets.
	unsigned char* out;
	nox_net_list_t* list = nox_net_lists[2][ind];
	if (!sub_40EEF0(ind, sz) || !(out = nox_xxx_netlistAdd_40EFA0(ind, buf, sz))) {
		nox_net_lists_buf_t* p = &nox_net_lists_buf_arr[0][ind];
		unsigned int len1, len2;

		// The new update packet needs to have correct bytes at the
		// beginning. Save the length of the first two queued datas so we
		// can replay them.
		len1 = list->first->size;
		len2 = list->first->next->size;

		// Flush old data to network.
		if (ind == 31) {
			nox_netlist_receiveCli_494E90(ind);
		} else {
			nox_xxx_netSendReadPacket_5528B0(*((uint32_t*)nox_common_playerInfoFromNum_417090(ind) + 516) + 1, 0);
		}

		// Set buffer length and re-queue updates.
		p->cur = len1 + len2;
		nox_netlist_add_420940(list, &p->buf[0], len1, 1);
		nox_netlist_add_420940(list, &p->buf[len1], len2, 1);

		// Retry original allocation.
		out = nox_xxx_netlistAdd_40EFA0(ind, buf, sz);
	}
	if (!out) {
		return 0;
	}
	nox_netlist_add_420940(list, out, sz, 1);
	return 1;
}

//----- (0040F120) --------------------------------------------------------
unsigned char* nox_netlist_copyPacketList2_40F120(int ind, unsigned int* outSz) {
	nox_net_list_t* list = nox_net_lists[2][ind];
	unsigned int cnt = 0;
	memset(nox_net_lists_buf, 0, sizeof(nox_net_lists_buf));
	while (1) {
		unsigned int sz = 0;
		unsigned char* src = nox_netlist_get_420A90(list, &sz);
		if (!src) {
			break; // no more data
		}
		if (cnt + sz > sizeof(nox_net_lists_buf)) {
			// we cannot store it, so put it back
			nox_netlist_add_420940(list, src, sz, 0);
			break;
		}
		memcpy(&nox_net_lists_buf[cnt], src, sz);
		cnt += sz;
	}
	*outSz = cnt;
	return nox_net_lists_buf;
}
