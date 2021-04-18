#include <stdbool.h>
#include <stdlib.h>

#include "common__net_list.h"
#include "common/alloc/classes/alloc_class.h"
#include "defs.h" // for nox_playerInfo and NOX_PLAYERINFO_MAX

#define NOX_NETBUF_MAX_PACKETS 512
#define NOX_NETBUF_MAX_SIZE 2032

// TODO: link to those properly
nox_playerInfo* nox_common_playerInfoFromNum_417090(int i);
int  nox_xxx_netSendReadPacket_5528B0(unsigned int a1, char a2);
int  nox_xxx_netlist_494E90(int a1);
int sub_4DFB20();

typedef struct {
	unsigned char buf[2048];
	unsigned int cur;
} nox_net_lists_buf_t;

typedef struct nox_net_list_item_t nox_net_list_item_t;
typedef struct nox_net_list_item_t {
	unsigned char* buf; // 0, 0
	unsigned int size; // 1, 4
	nox_net_list_item_t* prev; // 2, 8
	nox_net_list_item_t* next; // 3, 12
} nox_net_list_item_t;

typedef struct {
	nox_net_list_item_t* first; // 0, 0
	nox_net_list_item_t* last; // 1, 4
	unsigned int field_2; // 2, 8
	nox_alloc_class* alloc; // 3, 12
	unsigned int count; // 4, 16
	unsigned int size; // 5, 20
	unsigned int field_6; // 6, 24
	unsigned int field_7; // 7, 28
} nox_net_list_t;

nox_net_list_t* nox_net_lists[3][NOX_PLAYERINFO_MAX] = {0};
char nox_net_lists_buf[2048] = {0};
nox_net_lists_buf_t nox_net_lists_buf_arr[3][NOX_PLAYERINFO_MAX] = {0};


//----- (00420BC0) --------------------------------------------------------
int nox_netlist_count_420BC0(nox_net_list_t* p) {
	if (!p)
		return 0;
	return p->count; //_fileno(p);
}

//----- (00420BD0) --------------------------------------------------------
int nox_netlist_size_420BD0(nox_net_list_t* p) {
	if (!p)
		return 0;
	return p->size;
}

//----- (0040E9D0) --------------------------------------------------------
int nox_netlist_countByInd_40E9D0(int ind1, int ind2) {
	return nox_netlist_count_420BC0(nox_net_lists[ind2][ind1]);
}

//----- (0040E9F0) --------------------------------------------------------
int  nox_netlist_sizeByInd_40E9F0(int ind1, int ind2) {
	return nox_netlist_size_420BD0(nox_net_lists[ind2][ind1]);
}

//----- (00420890) --------------------------------------------------------
nox_net_list_t*  nox_netlist_newMsgList_420890(int cnt) {
	nox_net_list_t* p = malloc(sizeof(nox_net_list_t));
	if (!p)
		return 0;
	nox_alloc_class* aclass = nox_new_alloc_class("CreateMsgList", sizeof(nox_net_list_item_t), cnt);
	if (!aclass)
		return 0;
	p->first = 0;
	p->last = 0;
	p->field_2 = 0;
	p->alloc = aclass;
	p->count = 0;
	p->size = 0;
	p->field_6 = 0;
	p->field_7 = 0;
	return p;
}

//----- (004208F0) --------------------------------------------------------
void  nox_netlist_freeMsgList_4208F0(nox_net_list_t* p) {
	nox_free_alloc_class(p->alloc);
	free(p);
}

//----- (0040EA10) --------------------------------------------------------
void nox_netlist_init_40EA10() {
	for (int i = 0; i < NOX_PLAYERINFO_MAX; i++) {
		nox_net_lists[1][i] = nox_netlist_newMsgList_420890(NOX_NETBUF_MAX_PACKETS);
		nox_net_lists[0][i] = 0;
		nox_net_lists[2][i] = nox_netlist_newMsgList_420890(NOX_NETBUF_MAX_PACKETS);
	}
	nox_net_lists[0][NOX_PLAYERINFO_MAX-1] = nox_netlist_newMsgList_420890(NOX_NETBUF_MAX_PACKETS);
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
bool  nox_xxx_netSend_40EAC0(int a1, int a2, int a3) {
	int v3; // edi

	if (a2 == 1) {
		v3 = a1;
		int psz = nox_netlist_sizeByInd_40E9F0(a1, 1);
		if ((unsigned int)(psz + a3 + nox_netlist_sizeByInd_40E9F0(a1, 2)) > NOX_NETBUF_MAX_SIZE)
			return 0;
	} else {
		v3 = a1;
		if ((unsigned int)(a3 + nox_netlist_sizeByInd_40E9F0(a1, a2)) > NOX_NETBUF_MAX_SIZE)
			return 0;
	}
	return nox_netlist_count_420BC0(nox_net_lists[a2][v3]) < NOX_NETBUF_MAX_PACKETS;
}

//----- (0040EB60) --------------------------------------------------------
bool  nox_xxx_net_40EB60(int ind1, int ind2, int a3) {
	nox_net_list_t* p = nox_net_lists[ind2][ind1];
	int psz = nox_netlist_size_420BD0(p);
	if ((unsigned int)(a3 + psz + sub_4DFB20()) > NOX_NETBUF_MAX_SIZE)
		return 0;
	return nox_netlist_count_420BC0(p) < NOX_NETBUF_MAX_PACKETS;
}

//----- (0040EC30) --------------------------------------------------------
unsigned char* nox_xxx_netSend_40EC30(int a1, int a2, unsigned char* buf, int sz) {
	if (!buf || sz <= 0) {
		return 0;
	}
	nox_net_lists_buf_t* p = &nox_net_lists_buf_arr[a2+1][a1];
	int i = p->cur;
	if (i + sz > 2048) {
		return 0;
	}
	memcpy(&p->buf[i], buf, sz);
	p->cur += sz;
	return &p->buf[i];
}

//----- (00420940) --------------------------------------------------------
int  nox_netlist_add_420940(nox_net_list_t* list, int buf, int sz, bool append) {
	// dprintf("len %d: %08X %08X", sz, ((unsigned int*)buf)[0], ((unsigned int*)buf)[1]);

	nox_net_list_item_t* item = nox_alloc_class_new_obj_zero(list->alloc);
	if (!item)
		return 0;
	item->buf = buf;
	item->size = sz;
	if (append) {
		item->prev = list->last;
		item->next = 0;
		if (list->last)
			list->last->next = item;
		else
			list->first = item;
		list->last = item;
	} else {
		item->prev = 0;
		item->next = list->first;
		if (list->first)
			list->first->prev = item;
		else
			list->last = item;
		list->first = item;
	}
	list->count++;
	list->size += sz;
	return 1;
}

//----- (0040EBC0) --------------------------------------------------------
int  nox_netlist_addToMsgListCli_40EBC0(int ind, int ind2, const void* buf, int sz) {
	nox_net_list_t* p = nox_net_lists[ind2][ind];
	if (sz <= 0)
		return 1;
	if (!nox_xxx_netSend_40EAC0(ind, ind2, sz))
		return 0;
	void* v6 = nox_xxx_netSend_40EC30(ind, ind2, buf, sz);
	if (!v6)
		return 0;
	nox_netlist_add_420940(p, v6, sz, 1);
	return 1;
}

//----- (0040ECA0) --------------------------------------------------------
int  nox_netlist_clientSend_0_40ECA0(int ind1, int ind2, const void* a3, int a4) {
	nox_net_list_t* p = nox_net_lists[ind2][ind1];
	if (a4 <= 0)
		return 1;
	if (!nox_xxx_net_40EB60(ind1, ind2, a4))
		return 0;
	void* v6 = nox_xxx_netSend_40EC30(ind1, ind2, a3, a4);
	if (!v6)
		return 0;
	nox_netlist_add_420940(p, v6, a4, 1);
	return 1;
}

//----- (0040ED40) --------------------------------------------------------
void nox_xxx_netBufsSetZero_40ED40(int ind, int ind2) {
	nox_net_lists_buf_arr[ind2+1][ind].cur = 0;
}

//----- (0040F040) --------------------------------------------------------
void  sub_40F040(int ind) {
	nox_net_lists_buf_arr[0][ind].cur = 0;
}

//----- (00420830) --------------------------------------------------------
void  nox_netlist_resetList_420830(nox_net_list_t* p) {
	p->first = 0;
	p->last = 0;
	p->field_2 = 0;
	p->count = 0;
	p->size = 0;
	nox_alloc_class_yyy_4144D0(p->alloc);
}

//----- (0040ED10) --------------------------------------------------------
void nox_netlist_xxx_40ED10(int ind1, int ind2) {
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
void nox_netlist_xxx_40EE90(int ind) {
	for (int i = 0; i < NOX_PLAYERINFO_MAX; ++i) {
		nox_netlist_xxx_40ED10(i, ind);
	}
}

//----- (0040EE60) --------------------------------------------------------
void nox_netlist_xxx_40EE60() {
	for (int i = 0; i < NOX_PLAYERINFO_MAX; ++i) {
		nox_netlist_xxx_40ED10(i, 1);
		nox_netlist_xxx_40ED10(i, 0);
		nox_netlist_initPlayerBufs_40F020(i);
	}
}

//----- (004209C0) --------------------------------------------------------
void  nox_netlist_free_item_4209C0(nox_net_list_t* list, nox_net_list_item_t* item) {
	nox_alloc_class_free_obj(list->alloc, item);
}

//----- (00420A90) --------------------------------------------------------
unsigned int*  nox_netlist_get_420A90(nox_net_list_t* list, unsigned int* outSz) {
	if (!list->first) {
		return 0;
	}
	nox_net_list_item_t* item = list->first;

	*outSz = item->size;

	list->count--;
	list->size -= item->size;

	nox_net_list_item_t* next = item->next;
	if (next)
		next->prev = item->prev;
	else
		list->last = item->prev;

	nox_net_list_item_t* prev = item->prev;
	if (prev)
		prev->next = item->next;
	else
		list->first = item->next;

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
unsigned char*  nox_netlist_xxx_40EEB0(int ind1, int ind2, unsigned int* a3) {
	int n = 0;
	unsigned char* p = nox_netlist_get_420A90(nox_net_lists[ind2][ind1], &n);
	if (!p)
		return 0;
	*a3 = n;
	return p;
}

//----- (0040EEF0) --------------------------------------------------------
bool sub_40EEF0(int ind, int a2) {
	if ((unsigned int)(a2 + nox_netlist_size_420BD0(nox_net_lists[2][ind])) > NOX_NETBUF_MAX_SIZE)
		return 0;
	return nox_netlist_count_420BC0(nox_net_lists[2][ind]) < NOX_NETBUF_MAX_PACKETS;
}

//----- (0040F080) --------------------------------------------------------
unsigned char*  nox_netlist_getData_40F080(int ind, unsigned int* a2) {
	int n = 0;
	unsigned char* p = nox_netlist_get_420A90(nox_net_lists[2][ind], &n);
	if (!p)
		return 0;
	*a2 = n;
	return p;
}

//----- (004209E0) --------------------------------------------------------
void  sub_4209E0(int* a1, int a2) {
	int v2; // eax
	int v3; // esi
	int v4; // edx
	int v5; // edx

	v2 = *a1;
	if (*a1) {
		while (*(unsigned int*)v2 != a2) {
			v2 = *(unsigned int*)(v2 + 12);
			if (!v2)
				return;
		}
		if (v2) {
			v3 = a1[5];
			--a1[4];
			a1[5] = v3 - *(unsigned int*)(v2 + 4);
			v4 = *(unsigned int*)(v2 + 12);
			if (v4)
				*(unsigned int*)(v4 + 8) = *(unsigned int*)(v2 + 8);
			else
				a1[1] = *(unsigned int*)(v2 + 8);
			v5 = *(unsigned int*)(v2 + 8);
			if (v5)
				*(unsigned int*)(v5 + 12) = *(unsigned int*)(v2 + 12);
			else
				*a1 = *(unsigned int*)(v2 + 12);
			nox_netlist_free_item_4209C0((int)a1, (_QWORD*)v2);
		}
	}
}

//----- (0040F000) --------------------------------------------------------
void  nox_netlist_xxx_40F000(int ind, int a2) {
	sub_4209E0(nox_net_lists[2][ind], a2);
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

//----- (0040F060) --------------------------------------------------------
void sub_40F060() {
	for (int i = 0; i < NOX_PLAYERINFO_MAX; ++i) {
		nox_netlist_initPlayerBufs_40F020(i);
	}
}

//----- (0040F0B0) --------------------------------------------------------
int  nox_netlist_xxx_40F0B0(int ind) {
	return nox_netlist_countByInd_40E9D0(ind, 2);
}

//----- (0040F0D0) --------------------------------------------------------
int  nox_netlist_xxx_40F0D0(int ind) {
	return nox_netlist_sizeByInd_40E9F0(ind, 2);
}

//----- (00420A60) --------------------------------------------------------
unsigned int*  sub_420A60(unsigned int* a1, int(* a2)(unsigned int, int), int a3) {
	unsigned int* result; // eax
	unsigned int* v4;     // esi

	result = (unsigned int*)*a1;
	if (*a1) {
		do {
			v4 = (unsigned int*)result[3];
			result = (unsigned int*)a2(*result, a3);
			if (result)
				break;
			result = v4;
		} while (v4);
	}
	return result;
}

//----- (0040F0F0) --------------------------------------------------------
void  nox_netlist_xxx_40F0F0(int ind, int(* a2)(unsigned int, int), int a3) {
	if (a2) {
		if (a3) {
			sub_420A60(nox_net_lists[2][ind], a2, a3);
		}
	}
}

//----- (0040EF40) --------------------------------------------------------
bool nox_netlist_addToMsgListSrv_40EF40(int ind, unsigned char* buf, int sz) {
	if (sz <= 0)
		return 1;
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
		if (ind == 31)
			nox_xxx_netlist_494E90(ind);
		else
			nox_xxx_netSendReadPacket_5528B0(*((DWORD*)nox_common_playerInfoFromNum_417090(ind) + 516) + 1, 0);

		// Set buffer length and re-queue updates.
		p->cur = len1 + len2;
		nox_netlist_add_420940(list, &p->buf[0], len1, 1);
		nox_netlist_add_420940(list, &p->buf[len1], len2, 1);

		// Retry original allocation.
		out = nox_xxx_netlistAdd_40EFA0(ind, buf, sz);
	}
	if (!out)
		return 0;
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
