#ifndef NOX_COMMON_NET_LIST_H
#define NOX_COMMON_NET_LIST_H

int  nox_netlist_xxx_40E9F0(int a1, int a2);
void nox_netlist_initMsgBufs_40EA10();
void nox_netlist_freeMsgBufs_40EA70();
int  nox_netlist_addToMsgListCli_40EBC0(int a1, int a2, const void* a3, int a4);
int  nox_netlist_clientSend_0_40ECA0(int a1, int a2, const void* a3, int a4);
void nox_netlist_xxx_40ED10(int a1, int a2);
void nox_netlist_xxx_40EE90(int a1);
void nox_netlist_xxx_40EE60();
unsigned char* nox_netlist_copyPacketList_40ED60(int ind1, int ind2, unsigned int* outSz);
unsigned char* nox_netlist_xxx_40EEB0(int a1, int a2, unsigned int* a3);
unsigned char* nox_netlist_getData_40F080(int a1, unsigned int* a2);
void  nox_netlist_xxx_40F000(int a1, int a2);
void nox_netlist_initPlayerBufs_40F020(int a1);
int  nox_netlist_xxx_40F0B0(int a1);
int  nox_netlist_xxx_40F0D0(int a1);
void  nox_netlist_xxx_40F0F0(int a1, int(* a2)(unsigned int, int), int a3);
int  nox_netlist_addToMsgListSrv_40EF40(int a1, const void* a2, int a3);
unsigned char*  nox_netlist_copyPacketList2_40F120(int a1, unsigned int* a2);

#endif // NOX_COMMON_NET_LIST_H
