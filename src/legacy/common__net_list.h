#ifndef NOX_COMMON_NET_LIST_H
#define NOX_COMMON_NET_LIST_H

#include <stdbool.h>

int nox_netlist_addToMsgListCli_40EBC0(int ind1, int ind2, unsigned char* buf, int sz);
int nox_netlist_clientSendWrap_40ECA0(int ind1, int ind2, unsigned char* buf, int sz);
bool nox_netlist_addToMsgListSrv_40EF40(int ind, unsigned char* buf, int sz);

#endif // NOX_COMMON_NET_LIST_H
