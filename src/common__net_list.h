#ifndef NOX_COMMON_NET_LIST_H
#define NOX_COMMON_NET_LIST_H

#include <stdbool.h>

int nox_netlist_addToMsgListCli_40EBC0(int ind1, int ind2, unsigned char* buf, int sz);
int nox_netlist_clientSendWrap_40ECA0(int ind1, int ind2, unsigned char* buf, int sz);
unsigned char* nox_netlist_copyPacketList_40ED60(int ind1, int ind2, unsigned int* outSz);
unsigned char* nox_netlist_getInd_40EEB0(int ind1, int ind2, unsigned int* outSz);
unsigned char* nox_netlist_getByInd2_40F080(int ind, unsigned int* outSz);
void nox_netlist_initPlayerBufs_40F020(int a1);
bool nox_netlist_addToMsgListSrv_40EF40(int ind, unsigned char* buf, int sz);

#endif // NOX_COMMON_NET_LIST_H
