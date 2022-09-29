#ifndef NOX_COMMON_NET_LIST_H
#define NOX_COMMON_NET_LIST_H

#include "common/alloc/classes/alloc_class.h"
#include <stdbool.h>

#define NOX_NETBUF_MAX_PACKETS 512
#define NOX_NETBUF_MAX_SIZE 2032

typedef struct nox_net_list_item_t nox_net_list_item_t;
typedef struct nox_net_list_item_t {
	unsigned char* buf;        // 0, 0
	unsigned int size;         // 1, 4
	nox_net_list_item_t* prev; // 2, 8
	nox_net_list_item_t* next; // 3, 12
} nox_net_list_item_t;

typedef struct {
	nox_net_list_item_t* first; // 0, 0
	nox_net_list_item_t* last;  // 1, 4
	unsigned int field_2;       // 2, 8
	nox_alloc_class* alloc;     // 3, 12
	unsigned int count;         // 4, 16
	unsigned int size;          // 5, 20
	unsigned int field_6;       // 6, 24
	unsigned int field_7;       // 7, 28
} nox_net_list_t;

void nox_netlist_free_40EA70();

int nox_netlist_countByInd_40E9D0(int ind1, int ind2);
int nox_netlist_sizeByInd_40E9F0(int ind1, int ind2);
int nox_netlist_countByInd2_40F0B0(int ind);
int nox_netlist_sizeByInd2_40F0D0(int ind);

int nox_netlist_addToMsgListCli_40EBC0(int ind1, int ind2, unsigned char* buf, int sz);
int nox_netlist_clientSend_0_40ECA0(int ind1, int ind2, unsigned char* buf, int sz, int sz2);
void nox_netlist_resetByInd_40ED10(int ind1, int ind2);
void nox_netlist_resetAllInList_40EE90(int a1);
void nox_netlist_resetAll_40EE60();
unsigned char* nox_netlist_copyPacketList_40ED60(int ind1, int ind2, unsigned int* outSz);
unsigned char* nox_netlist_getInd_40EEB0(int ind1, int ind2, unsigned int* outSz);
unsigned char* nox_netlist_getByInd2_40F080(int ind, unsigned int* outSz);
void nox_netlist_findAndFreeBuf_40F000(int ind, unsigned char* buf);
void nox_netlist_initPlayerBufs_40F020(int a1);
void nox_netlist_forEach2_40F0F0(int a1, int (*a2)(unsigned int, int), int a3);
bool nox_netlist_addToMsgListSrv_40EF40(int ind, unsigned char* buf, int sz);
unsigned char* nox_netlist_copyPacketList2_40F120(int a1, unsigned int* a2);

#endif // NOX_COMMON_NET_LIST_H
