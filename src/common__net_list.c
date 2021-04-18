#include <stdbool.h>
#include <stdlib.h>

#include "common__net_list.h"
#include "common/alloc/classes/alloc_class.h"
#include "defs.h" // for nox_playerInfo and NOX_PLAYERINFO_MAX

// TODO: link to those properly
nox_playerInfo* nox_common_playerInfoFromNum_417090(int i);
int  nox_xxx_netSendReadPacket_5528B0(unsigned int a1, char a2);
int  nox_xxx_netlist_494E90(int a1);
int sub_4DFB20();

typedef struct {
	unsigned char buf[2048];
	unsigned int cur;
} nox_net_lists_buf_t;

void(*nox_netlist_func_534816)(unsigned int) = 0;
void* nox_net_lists[3][NOX_PLAYERINFO_MAX] = {0};
char nox_net_lists_buf[2048] = {0};
nox_net_lists_buf_t nox_net_lists_buf_arr[3][NOX_PLAYERINFO_MAX] = {0};


//----- (00420BC0) --------------------------------------------------------
int  nox_xxx_netSend_420BC0(int a1) {
	return *(unsigned int*)(a1 + 16); //_fileno(a1);
}

//----- (00420BD0) --------------------------------------------------------
int  nox_xxx_net_420BD0(int a1) {
	return *(unsigned int*)(a1 + 20);
}

//----- (0040E9D0) --------------------------------------------------------
int  sub_40E9D0(int ind1, int ind2) {
	return nox_xxx_netSend_420BC0(nox_net_lists[ind2][ind1]);
}

//----- (0040E9F0) --------------------------------------------------------
int  nox_netlist_xxx_40E9F0(int ind1, int ind2) {
	return nox_xxx_net_420BD0(nox_net_lists[ind2][ind1]);
}

//----- (00420890) --------------------------------------------------------
unsigned int*  nox_xxx_net_CreateMsgList_420890(int a1, int a2) {
	unsigned int* v2 = malloc(32);
	if (!v2)
		return 0;
	char* v4 = nox_new_alloc_class("CreateMsgList", 16, a1);
	v2[3] = v4;
	if (!v4)
		return 0;
	v2[0] = 0;
	v2[1] = 0;
	v2[2] = 0;
	v2[4] = 0;
	v2[5] = 0;
	nox_netlist_func_534816 = a2;
	return v2;
}

//----- (004208F0) --------------------------------------------------------
void  nox_xxx_net_DeleteMsgList_4208F0(void* lpMem) {
	unsigned int* v1; // esi

	if (nox_netlist_func_534816) {
		v1 = *(unsigned int**)lpMem;
		if (*(unsigned int*)lpMem) {
			do {
				if (*v1)
					nox_netlist_func_534816(*v1);
				v1 = (unsigned int*)v1[3];
			} while (v1);
		}
	}
	nox_free_alloc_class(*((void**)lpMem + 3));
	free(lpMem);
}

//----- (0040EA10) --------------------------------------------------------
void nox_netlist_initMsgBufs_40EA10() {
	for (int i = 0; i < NOX_PLAYERINFO_MAX; i++) {
		nox_net_lists[1][i] = nox_xxx_net_CreateMsgList_420890(512, 0);
		nox_net_lists[0][i] = 0;
		nox_net_lists[2][i] = nox_xxx_net_CreateMsgList_420890(512, 0);
	}
	nox_net_lists[0][NOX_PLAYERINFO_MAX-1] = nox_xxx_net_CreateMsgList_420890(512, 0);
}

//----- (0040EA70) --------------------------------------------------------
void nox_netlist_freeMsgBufs_40EA70() {
	for (int i = 0; i < NOX_PLAYERINFO_MAX; i++) {
		if (nox_net_lists[1][i]) {
			nox_xxx_net_DeleteMsgList_4208F0(nox_net_lists[1][i]);
		}
		if (nox_net_lists[0][i]) {
			nox_xxx_net_DeleteMsgList_4208F0(nox_net_lists[0][i]);
		}
		if (nox_net_lists[2][i]) {
			nox_xxx_net_DeleteMsgList_4208F0(nox_net_lists[2][i]);
		}
	}
}

//----- (0040EAC0) --------------------------------------------------------
bool  nox_xxx_netSend_40EAC0(int a1, int a2, int a3) {
	int v3; // edi
	int v4; // ebx

	if (a2 == 1) {
		v3 = a1;
		v4 = nox_xxx_net_420BD0(nox_net_lists[1][a1]);
		if ((unsigned int)(v4 + a3 + nox_xxx_net_420BD0(nox_net_lists[2][a1])) > 0x7F0)
			return 0;
	} else {
		v3 = a1;
		if ((unsigned int)(a3 + nox_xxx_net_420BD0(nox_net_lists[a2][a1])) > 0x7F0)
			return 0;
	}
	return nox_xxx_netSend_420BC0(nox_net_lists[a2][v3]) < 512;
}

//----- (0040EB60) --------------------------------------------------------
bool  nox_xxx_net_40EB60(int a1, int a2, int a3) {
	int* v3 = &nox_net_lists[a2][a1];
	int v4 = nox_xxx_net_420BD0(*v3);
	if ((unsigned int)(a3 + v4 + sub_4DFB20()) > 0x7F0)
		return 0;
	return nox_xxx_netSend_420BC0((FILE*)*v3) < 512;
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
int  nox_netlist_put_xxx_420940(int a1, int a2, int a3, int a4) {
	unsigned int* v4; // eax
	int v6;     // ecx
	int v7;     // ecx
	int v8;     // eax

	// dprintf("len %d: %08X %08X", a3, ((unsigned int*)a2)[0], ((unsigned int*)a2)[1]);

	v4 = nox_alloc_class_new_obj_zero(*(unsigned int**)(a1 + 12));
	if (!v4)
		return 0;
	*v4 = a2;
	v4[1] = a3;
	if (a4) {
		v6 = *(unsigned int*)(a1 + 4);
		v4[3] = 0;
		v4[2] = v6;
		v7 = *(unsigned int*)(a1 + 4);
		if (v7)
			*(unsigned int*)(v7 + 12) = v4;
		else
			*(unsigned int*)a1 = v4;
		*(unsigned int*)(a1 + 4) = v4;
	} else {
		v4[2] = 0;
		v4[3] = *(unsigned int*)a1;
		if (*(unsigned int*)a1)
			*(unsigned int*)(*(unsigned int*)a1 + 8) = v4;
		else
			*(unsigned int*)(a1 + 4) = v4;
		*(unsigned int*)a1 = v4;
	}
	v8 = *(unsigned int*)(a1 + 20);
	++*(unsigned int*)(a1 + 16);
	*(unsigned int*)(a1 + 20) = a3 + v8;
	return 1;
}

//----- (0040EBC0) --------------------------------------------------------
int  nox_netlist_addToMsgListCli_40EBC0(int ind, int ind2, const void* buf, int sz) {
	int p = nox_net_lists[ind2][ind];
	if (sz <= 0)
		return 1;
	if (!nox_xxx_netSend_40EAC0(ind, ind2, sz))
		return 0;
	void* v6 = nox_xxx_netSend_40EC30(ind, ind2, buf, sz);
	if (!v6)
		return 0;
	nox_netlist_put_xxx_420940(p, v6, sz, 1);
	return 1;
}

//----- (0040ECA0) --------------------------------------------------------
int  nox_netlist_clientSend_0_40ECA0(int a1, int a2, const void* a3, int a4) {
	void* v4 = nox_net_lists[a2][a1];
	if (a4 <= 0)
		return 1;
	if (!nox_xxx_net_40EB60(a1, a2, a4))
		return 0;
	void* v6 = nox_xxx_netSend_40EC30(a1, a2, a3, a4);
	if (!v6)
		return 0;
	nox_netlist_put_xxx_420940(v4, v6, a4, 1);
	return 1;
}

//----- (0040ED40) --------------------------------------------------------
void nox_xxx_netBufsSetZero_40ED40(int a1, int a2) {
	nox_net_lists_buf_arr[a2+1][a1].cur = 0;
}

//----- (0040F040) --------------------------------------------------------
void  sub_40F040(int a1) {
	nox_net_lists_buf_arr[0][a1].cur = 0;
}

//----- (00420830) --------------------------------------------------------
void  nox_xxx_net_420830(unsigned int* a1) {
	unsigned int* v1; // esi
	unsigned int* v2; // eax

	if (nox_netlist_func_534816) {
		v1 = (unsigned int*)*a1;
		if (*a1) {
			do {
				if (*v1)
					nox_netlist_func_534816(*v1);
				*v1 = 0;
				v1[1] = 0;
				v1 = (unsigned int*)v1[3];
			} while (v1);
		}
	}
	v2 = (unsigned int*)a1[3];
	*a1 = 0;
	a1[1] = 0;
	a1[2] = 0;
	a1[4] = 0;
	a1[5] = 0;
	nox_alloc_class_yyy_4144D0(v2);
}

//----- (0040ED10) --------------------------------------------------------
void nox_netlist_xxx_40ED10(int a1, int a2) {
	int p = nox_net_lists[a2][a1];
	if (p) {
		nox_xxx_net_420830(p);
		nox_xxx_netBufsSetZero_40ED40(a1, a2);
	}
}

//----- (0040F020) --------------------------------------------------------
void nox_netlist_initPlayerBufs_40F020(int a1) {
	nox_xxx_net_420830(nox_net_lists[2][a1]);
	sub_40F040(a1);
}

//----- (0040EE90) --------------------------------------------------------
void nox_netlist_xxx_40EE90(int a1) {
	for (int i = 0; i < NOX_PLAYERINFO_MAX; ++i) {
		nox_netlist_xxx_40ED10(i, a1);
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
void  nox_xxx_net_4209C0(int a1, void* a2) {
	nox_alloc_class_free_obj(*(unsigned int**)(a1 + 12), a2);
}

//----- (00420A90) --------------------------------------------------------
unsigned int*  nox_xxx_netlistGetList_420A90(int a1, unsigned int* ListSizePtr) {
	unsigned int* result; // eax
	int v3;         // esi
	int v4;         // edx
	int v5;         // edx
	unsigned int* v6;     // esi

	result = *(unsigned int**)a1;
	if (*(unsigned int*)a1) {
		*ListSizePtr = result[1];
		v3 = *(unsigned int*)(a1 + 20);
		--*(unsigned int*)(a1 + 16);
		*(unsigned int*)(a1 + 20) = v3 - result[1];
		v4 = result[3];
		if (v4)
			*(unsigned int*)(v4 + 8) = result[2];
		else
			*(unsigned int*)(a1 + 4) = result[2];
		v5 = result[2];
		if (v5)
			*(unsigned int*)(v5 + 12) = result[3];
		else
			*(unsigned int*)a1 = result[3];
		v6 = (unsigned int*)*result;
		nox_xxx_net_4209C0(a1, (int)result);
		result = v6;
	}
	return result;
}

//----- (0040ED60) --------------------------------------------------------
unsigned char* nox_netlist_copyPacketList_40ED60(int ind1, int ind2, unsigned int* outSz) {
	void* list = nox_net_lists[ind2][ind1];
	unsigned int cnt = 0;
	memset(nox_net_lists_buf, 0, sizeof(nox_net_lists_buf));
	while (1) {
		unsigned int sz = 0;
		unsigned char* src = nox_xxx_netlistGetList_420A90(list, &sz);
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
unsigned char*  nox_netlist_xxx_40EEB0(int a1, int a2, unsigned int* a3) {
	int n = 0;
	unsigned char* p = nox_xxx_netlistGetList_420A90(nox_net_lists[a2][a1], &n);
	if (!p)
		return 0;
	*a3 = n;
	return p;
}

//----- (0040EEF0) --------------------------------------------------------
bool sub_40EEF0(int a1, int a2) {
	if ((unsigned int)(a2 + nox_xxx_net_420BD0(nox_net_lists[2][a1])) > 2032)
		return 0;
	return nox_xxx_netSend_420BC0(nox_net_lists[2][a1]) < 512;
}

//----- (0040F080) --------------------------------------------------------
unsigned char*  nox_netlist_getData_40F080(int a1, unsigned int* a2) {
	int n = 0;
	unsigned char* p = nox_xxx_netlistGetList_420A90(nox_net_lists[2][a1], &n);
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
			nox_xxx_net_4209C0((int)a1, (_QWORD*)v2);
		}
	}
}

//----- (0040F000) --------------------------------------------------------
void  nox_netlist_xxx_40F000(int a1, int a2) {
	sub_4209E0(nox_net_lists[2][a1], a2);
}

//----- (0040EFA0) --------------------------------------------------------
char*  nox_xxx_netlistAdd_40EFA0(int a1, unsigned char* buf, int sz) {
	if (!buf || sz <= 0) {
		return 0;
	}
	nox_net_lists_buf_t* p = &nox_net_lists_buf_arr[0][a1];
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
int  nox_netlist_xxx_40F0B0(int a1) {
	return nox_xxx_netSend_420BC0(nox_net_lists[2][a1]);
}

//----- (0040F0D0) --------------------------------------------------------
int  nox_netlist_xxx_40F0D0(int a1) {
	return nox_xxx_net_420BD0(nox_net_lists[2][a1]);
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
void  nox_netlist_xxx_40F0F0(int a1, int(* a2)(unsigned int, int), int a3) {
	if (a2) {
		if (a3) {
			sub_420A60(nox_net_lists[2][a1], a2, a3);
		}
	}
}

//----- (0040EF40) --------------------------------------------------------
int  nox_netlist_addToMsgListSrv_40EF40(int a1, const void* a2, int a3) {
	int v3;   // ebx
	char* v5; // eax

	v3 = nox_net_lists[2][a1];
	if (a3 <= 0)
		return 1;
	// If there are too many updates, then we may run out of space in a single
	// packet. Instead of fragmenting, we can instead send additional packets.
	if (!sub_40EEF0(a1, a3) || !(v5 = nox_xxx_netlistAdd_40EFA0(a1, a2, a3))) {
		nox_net_lists_buf_t* p = &nox_net_lists_buf_arr[0][a1];
		unsigned int len1, len2;

		// The new update packet needs to have correct bytes at the
		// beginning. Save the length of the first two queued datas so we
		// can replay them.
		len1 = *((DWORD*)((DWORD*)(*((DWORD*)v3)) + 1));                  // head->len
		len2 = *((DWORD*)(*((DWORD*)((DWORD*)(*((DWORD*)v3)) + 3)) + 4)); // head->next->len

		// Flush old data to network.
		if (a1 == 31)
			nox_xxx_netlist_494E90(a1);
		else
			nox_xxx_netSendReadPacket_5528B0(*((DWORD*)nox_common_playerInfoFromNum_417090(a1) + 516) + 1, 0);

		// Set buffer length and re-queue updates.
		p->cur = len1 + len2;
		nox_netlist_put_xxx_420940(v3, &p->buf[0], len1, 1);
		nox_netlist_put_xxx_420940(v3, &p->buf[len1], len2, 1);

		// Retry original allocation.
		v5 = nox_xxx_netlistAdd_40EFA0(a1, a2, a3);
	}
	if (!v5)
		return 0;
	nox_netlist_put_xxx_420940(v3, (int)v5, a3, 1);
	return 1;
}

//----- (0040F120) --------------------------------------------------------
unsigned char* nox_netlist_copyPacketList2_40F120(int ind, unsigned int* outSz) {
	void* list = nox_net_lists[2][ind];
	unsigned int cnt = 0;
	memset(nox_net_lists_buf, 0, sizeof(nox_net_lists_buf));
	while (1) {
		unsigned int sz = 0;
		unsigned char* src = nox_xxx_netlistGetList_420A90(list, &sz);
		if (!src) {
			break; // no more data
		}
		if (cnt + sz > sizeof(nox_net_lists_buf)) {
			// we cannot store it, so put it back
			nox_netlist_put_xxx_420940(list, src, sz, 0);
			break;
		}
		memcpy(&nox_net_lists_buf[cnt], src, sz);
		cnt += sz;
	}
	*outSz = cnt;
	return nox_net_lists_buf;
}
