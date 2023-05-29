package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/ntype"
	"github.com/noxworld-dev/opennox/v1/internal/netlist"
)

var (
	GetNetPlayerBufSize         func() int
	Nox_netlist_addToMsgListSrv func(ind ntype.PlayerInd, buf []byte) bool
)

// nox_netlist_addToMsgListCli_40EBC0
func nox_netlist_addToMsgListCli_40EBC0(ind1, ind2 int, buf *byte, sz int) int {
	return bool2int(netlist.AddToMsgListCli(ntype.PlayerInd(ind1), netlist.Kind(ind2), unsafe.Slice((*byte)(unsafe.Pointer(buf)), sz)))
}

// nox_netlist_clientSendWrap_40ECA0
func nox_netlist_clientSendWrap_40ECA0(ind1, ind2 int, buf *byte, sz int) int {
	return bool2int(netlist.ClientSend0(ntype.PlayerInd(ind1), netlist.Kind(ind2), unsafe.Slice((*byte)(unsafe.Pointer(buf)), sz), GetNetPlayerBufSize()))
}

// nox_netlist_addToMsgListSrv_40EF40
func nox_netlist_addToMsgListSrv_40EF40(ind int, buf *byte, sz int) bool {
	return bool(Nox_netlist_addToMsgListSrv(ntype.PlayerInd(ind), unsafe.Slice((*byte)(unsafe.Pointer(buf)), sz)))
}

func Nox_xxx_netImportant_4E5770(a1 byte, a2 int) {
	nox_xxx_netImportant_4E5770(byte(a1), int(a2))
}
