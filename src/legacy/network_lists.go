package legacy

/*
#include "defs.h"
extern unsigned int dword_5d4594_2650652;
int nox_xxx_netOnPacketRecvCli_48EA70(int a1, unsigned char* data, int sz);
int sub_48D660();
int sub_4DF9B0(void* a1, void* a2, void* a3, int a4);
void nox_xxx_netImportant_4E5770(unsigned char a1, int a2);
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/internal/netlist"
)

var (
	GetNetPlayerBufSize         func() int
	Nox_netlist_addToMsgListSrv func(ind int, buf []byte) bool
)

//export nox_netlist_addToMsgListCli_40EBC0
func nox_netlist_addToMsgListCli_40EBC0(ind1, ind2 int, buf *C.uchar, sz int) int {
	return bool2int(netlist.AddToMsgListCli(ind1, netlist.Kind(ind2), unsafe.Slice((*byte)(unsafe.Pointer(buf)), sz)))
}

//export nox_netlist_clientSendWrap_40ECA0
func nox_netlist_clientSendWrap_40ECA0(ind1, ind2 int, buf *C.uchar, sz int) int {
	return bool2int(netlist.ClientSend0(ind1, netlist.Kind(ind2), unsafe.Slice((*byte)(unsafe.Pointer(buf)), sz), GetNetPlayerBufSize()))
}

//export nox_netlist_addToMsgListSrv_40EF40
func nox_netlist_addToMsgListSrv_40EF40(ind int, buf *C.uchar, sz int) C.bool {
	return C.bool(Nox_netlist_addToMsgListSrv(ind, unsafe.Slice((*byte)(unsafe.Pointer(buf)), sz)))
}

func Nox_xxx_netImportant_4E5770(a1 byte, a2 int) {
	C.nox_xxx_netImportant_4E5770(C.uchar(a1), C.int(a2))
}
