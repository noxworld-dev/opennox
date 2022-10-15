package opennox

/*
#include "defs.h"
int nox_xxx_netOnPacketRecvCli_48EA70(int a1, unsigned char* data, int sz);
int sub_48D660();
*/
import "C"
import (
	"encoding/binary"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/common"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/internal/netlist"
	"github.com/noxworld-dev/opennox/v1/internal/netstr"
)

//export nox_netlist_addToMsgListCli_40EBC0
func nox_netlist_addToMsgListCli_40EBC0(ind1, ind2 C.int, buf *C.uchar, sz C.int) C.int {
	return C.int(bool2int(netlist.AddToMsgListCli(int(ind1), int(ind2), unsafe.Slice((*byte)(unsafe.Pointer(buf)), int(sz)))))
}

//export nox_netlist_clientSend_0_40ECA0
func nox_netlist_clientSend_0_40ECA0(ind1, ind2 C.int, buf *C.uchar, sz, sz2 C.int) C.int {
	return C.int(bool2int(netlist.ClientSend0(int(ind1), int(ind2), unsafe.Slice((*byte)(unsafe.Pointer(buf)), int(sz)), int(sz2))))
}

//export nox_netlist_addToMsgListSrv_40EF40
func nox_netlist_addToMsgListSrv_40EF40(ind C.int, buf *C.uchar, sz C.int) C.bool {
	return C.bool(nox_netlist_addToMsgListSrv(int(ind), unsafe.Slice((*byte)(unsafe.Pointer(buf)), int(sz))))
}

//export nox_netlist_getInd_40EEB0
func nox_netlist_getInd_40EEB0(ind1, ind2 C.int, outSz *C.uint) *C.uchar {
	buf := netlist.ByInd(int(ind1), int(ind2)).Get()
	*outSz = C.uint(len(buf))
	if len(buf) == 0 {
		return nil
	}
	return (*C.uchar)(unsafe.Pointer(&buf[0]))
}

//export nox_netlist_getByInd2_40F080
func nox_netlist_getByInd2_40F080(ind C.int, outSz *C.uint) *C.uchar {
	buf := netlist.ByInd(int(ind), 2).Get()
	*outSz = C.uint(len(buf))
	if len(buf) == 0 {
		return nil
	}
	return (*C.uchar)(unsafe.Pointer(&buf[0]))
}

//export nox_netlist_copyPacketList_40ED60
func nox_netlist_copyPacketList_40ED60(ind1, ind2 C.int, outSz *C.uint) *C.uchar {
	buf := netlist.CopyPacketsA(int(ind1), int(ind2))
	sbuf := netlist.Buffer
	copy(sbuf, make([]byte, len(sbuf)))
	*outSz = C.uint(len(buf))
	copy(sbuf, buf)
	return (*C.uchar)(unsafe.Pointer(&sbuf[0]))
}

//export nox_netlist_findAndFreeBuf_40F000
func nox_netlist_findAndFreeBuf_40F000(ind C.int, buf *C.uchar) {
	netlist.ByInd(int(ind), 2).FindAndFreeBuf((*byte)(unsafe.Pointer(buf)))
}

//export nox_netlist_countByInd2_40F0B0
func nox_netlist_countByInd2_40F0B0(ind int) int {
	return netlist.ByInd(ind, 2).Count()
}

//export nox_netlist_initPlayerBufs_40F020
func nox_netlist_initPlayerBufs_40F020(ind int) {
	netlist.InitByInd(ind)
}

func nox_netlist_addToMsgListSrv(ind int, buf []byte) bool {
	s := noxServer
	return netlist.AddToMsgListSrv(ind, buf, func(ind int) {
		// Flush old data to network.
		if ind == common.MaxPlayers-1 {
			nox_netlist_receiveCli_494E90(ind)
		} else {
			netstr.SendReadPacket(s.getPlayerByInd(ind).Index()+1, 0)
		}
	})
}

func nox_netlist_receiveCli_494E90(ind int) int {
	res := 0

	if buf1 := netlist.CopyPacketsB(ind); len(buf1) != 0 {
		res = nox_xxx_netOnPacketRecvCli_48EA70(ind, buf1)
	}

	if buf2 := netlist.CopyPacketsA(ind, 1); len(buf2) != 0 {
		res = nox_xxx_netOnPacketRecvCli_48EA70(ind, buf2)
		if res != 0 {
			C.sub_48D660()
		}
	}
	return res
}

//export sub_4DF5E0
func sub_4DF5E0(ind, max C.int) unsafe.Pointer {
	a1 := memmap.Int32(0x5D4594, 1563292)
	a2 := memmap.Int32(0x5D4594, 1563296)
	var found *byte
	netlist.ByInd(int(ind), 2).Each(func(b []byte) bool {
		if len(b) < 9 {
			return false
		}
		var v1 int32
		if v := int32(binary.LittleEndian.Uint16(b[5:])); v-a1 >= 0 {
			v1 = v - a1
		} else {
			v1 = a1 - v
		}
		if v1 >= int32(max) {
			return false
		}
		var v2 int32
		if v := int32(binary.LittleEndian.Uint16(b[7:])); v-a2 >= 0 {
			v2 = v - a2
		} else {
			v2 = a2 - v
		}
		if v2 >= int32(max) {
			return false
		}
		found = &b[0]
		return true
	})
	return unsafe.Pointer(found)
}

var _ = [1]struct{}{}[8-unsafe.Sizeof(item57B930{})]

type item57B930 struct {
	field0 uint16
	field2 uint16
	frame4 uint32
}

//export sub_57B930
func sub_57B930(ptr unsafe.Pointer, a2, a3 int, frame uint32) byte {
	si := int(byte(a2))
	if si == 255 || si == 0 {
		si = 1
	}
	arr := unsafe.Slice((*item57B930)(ptr), 256)
	i := si
	for {
		v := &arr[i]
		if int(v.field0) == a2 && int(v.field2) == a3 {
			if v.frame4 >= frame {
				return byte(i)
			}
			break
		}
		i++
		if i == 255 {
			i = 1
		}
		if i == si {
			break
		}
	}
	return 0xff
}
