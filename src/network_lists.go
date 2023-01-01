package opennox

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
	"encoding/binary"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/common"
	"github.com/noxworld-dev/opennox-lib/noxnet"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/internal/netlist"
	"github.com/noxworld-dev/opennox/v1/internal/netstr"
)

//export nox_netlist_addToMsgListCli_40EBC0
func nox_netlist_addToMsgListCli_40EBC0(ind1, ind2 C.int, buf *C.uchar, sz C.int) C.int {
	return C.int(bool2int(netlist.AddToMsgListCli(int(ind1), netlist.Kind(ind2), unsafe.Slice((*byte)(unsafe.Pointer(buf)), int(sz)))))
}

//export nox_netlist_clientSendWrap_40ECA0
func nox_netlist_clientSendWrap_40ECA0(ind1, ind2 C.int, buf *C.uchar, sz C.int) C.int {
	return C.int(bool2int(netlist.ClientSend0(int(ind1), netlist.Kind(ind2), unsafe.Slice((*byte)(unsafe.Pointer(buf)), int(sz)), netPlayerBufSize)))
}

//export nox_netlist_addToMsgListSrv_40EF40
func nox_netlist_addToMsgListSrv_40EF40(ind C.int, buf *C.uchar, sz C.int) C.bool {
	return C.bool(nox_netlist_addToMsgListSrv(int(ind), unsafe.Slice((*byte)(unsafe.Pointer(buf)), int(sz))))
}

//export nox_netlist_initPlayerBufs_40F020
func nox_netlist_initPlayerBufs_40F020(ind int) {
	netlist.InitByInd(ind)
}

func nox_xxx_rateGet_40A6C0() int {
	return int(memmap.Uint32(0x587000, 4728))
}

func nox_netlist_addToMsgListSrv(ind int, buf []byte) bool {
	s := noxServer
	return netlist.AddToMsgListSrv(ind, buf, func(ind int) {
		// Flush old data to network.
		if ind == common.MaxPlayers-1 {
			noxClient.nox_netlist_receiveCli_494E90(ind)
		} else {
			netstr.SendReadPacket(s.getPlayerByInd(ind).Index()+1, 0)
		}
	})
}

func (c *Client) nox_netlist_receiveCli_494E90(ind int) int {
	res := 0

	if buf1 := netlist.CopyPacketsB(ind); len(buf1) != 0 {
		res = c.nox_xxx_netOnPacketRecvCli48EA70(ind, buf1)
	}

	if buf2 := netlist.CopyPacketsA(ind, netlist.Kind1); len(buf2) != 0 {
		res = c.nox_xxx_netOnPacketRecvCli48EA70(ind, buf2)
		if res != 0 {
			C.sub_48D660()
		}
	}
	return res
}

func sub_4DF8F0(ind int, p1 []byte) int {
	if netlist.ByInd(ind, netlist.Kind2).Count() == 0 {
		return 0
	}
	v4 := 127
	v6 := sub_4DF5E0(ind, 127)
	flag := false
	off := 0
	if v6 == nil {
		for {
			v4 += 127
			if v4 > 4064 {
				return 0
			}
			v6 = sub_4DF5E0(ind, v4)
			if v6 != nil {
				if v4 <= 127 {
					break
				}
				p1[0] = 0
				flag = true
				off++
				break
			}
		}
	}
	v8 := sub_4DF9B0(p1[off:], v6, flag)
	if v8 == -1 {
		return off
	}
	netlist.ByInd(ind, netlist.Kind2).FindAndFreeBuf(v6)
	return off + v8
}

func sub_4DF5E0(ind, max int) []byte {
	k1a := netPlayerK1
	k2a := netPlayerK2
	var found []byte
	netlist.ByInd(ind, netlist.Kind2).Each(func(b []byte) bool {
		if len(b) < 9 {
			return false
		}
		var dk1 int
		if k1b := int(binary.LittleEndian.Uint16(b[5:])); k1b-int(k1a) >= 0 {
			dk1 = k1b - int(k1a)
		} else {
			dk1 = int(k1a) - k1b
		}
		if dk1 >= max {
			return false
		}
		var dk2 int
		if k2b := int(binary.LittleEndian.Uint16(b[7:])); k2b-int(k2a) >= 0 {
			dk2 = k2b - int(k2a)
		} else {
			dk2 = int(k2a) - k2b
		}
		if dk2 >= max {
			return false
		}
		found = b
		return true
	})
	return found
}

var _ = [1]struct{}{}[8-unsafe.Sizeof(playerNetData{})]

type playerNetData struct {
	field0 uint16
	field2 uint16
	frame4 uint32
}

func sub_57B930(arr *[255]playerNetData, f1, f2 uint16, frame uint32) byte {
	si := int(byte(f1))
	if si == 255 || si == 0 {
		si = 1
	}
	i := si
	for {
		v := &arr[i]
		if v.field0 == f1 && v.field2 == f2 {
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
	return 255
}

func nox_xxx_chkIsMsgTimestamp_4DF7F0(b []byte) bool {
	return len(b) != 0 && (b[0] == byte(noxnet.MSG_TIMESTAMP) || b[0] == byte(noxnet.MSG_FULL_TIMESTAMP))
}

func copyFull(dst []byte, src []byte) int {
	if len(dst) < len(src) {
		return 0
	}
	copy(dst, src)
	return len(src)
}

func zero3full(b []byte) int {
	if len(b) < 3 {
		return 0
	}
	b[0] = 0
	b[1] = 0
	b[2] = 0
	return 3
}

var (
	netPlayerPlus16  *[255]playerNetData
	netPlayerBufSize int
	netPlayerK1      uint16
	netPlayerK2      uint16
)

func nox_xxx_netFn_UpdateStream_4DF630(ind int, b1 []byte, _ unsafe.Pointer) int {
	pl := noxServer.getPlayerByInd(ind - 1)
	*memmap.PtrUint32(0x5D4594, 1563308) = 0
	netPlayerBufSize = 0
	netPlayerPlus16 = pl.net16()
	v7 := netlist.ByInd(ind-1, netlist.Kind2).Get()
	var off int
	if nox_xxx_chkIsMsgTimestamp_4DF7F0(v7) {
		off += copy(b1[off:off+len(v7)], v7)
		if v9 := netlist.ByInd(ind-1, netlist.Kind2).Get(); len(v9) != 0 {
			b1[off] = byte(noxnet.MSG_UPDATE_STREAM)
			off++
			n := sub_4DF810(b1[off:], v9)
			if n == 0 {
				off--
				return off
			}
			off += n
			for {
				n := sub_4DF8F0(ind-1, b1[off:])
				off += n
				if n == 0 {
					break
				}
			}
			off += zero3full(b1[off:])
		}
	}
	for b := netlist.ByInd(ind-1, netlist.Kind1).Get(); len(b) != 0; b = netlist.ByInd(ind-1, netlist.Kind1).Get() {
		if b[0] != byte(noxnet.MSG_FX_SENTRY_RAY) || C.dword_5d4594_2650652 != 1 || (noxServer.Frame()%uint32(nox_xxx_rateGet_40A6C0()) == 0) {
			n := copyFull(b1[off:], b)
			if n == 0 {
				return off
			}
			off += n
		}
	}
	netPlayerBufSize = off
	if C.dword_5d4594_2650652 == 0 || (noxServer.Frame()%uint32(nox_xxx_rateGet_40A6C0()) == 0) || noxflags.HasGame(noxflags.GameFlag4) {
		C.nox_xxx_netImportant_4E5770(C.uchar(ind-1), 1)
		for b := netlist.ByInd(ind-1, netlist.Kind1).Get(); len(b) != 0; b = netlist.ByInd(ind-1, netlist.Kind1).Get() {
			n := copyFull(b1[off:], b)
			if n == 0 {
				break
			}
			off += n
		}
	}
	return off
}

func sub_4DF810(b1 []byte, b2 []byte) int {
	if len(b1) < 16 || b2[0] != byte(noxnet.MSG_PLAYER_OBJ) {
		return 0
	}
	f1 := binary.LittleEndian.Uint16(b2[1:])
	f3 := binary.LittleEndian.Uint16(b2[3:])
	f5 := binary.LittleEndian.Uint16(b2[5:])
	f7 := binary.LittleEndian.Uint16(b2[7:])
	f5 &= 0xFFFE
	f7 &= 0xFFFE
	binary.LittleEndian.PutUint16(b2[5:], f5)
	binary.LittleEndian.PutUint16(b2[7:], f7)
	v4 := sub_57B930(netPlayerPlus16, f1, f3, noxServer.Frame())
	b1[0] = v4
	off := 1
	if v4 == 255 {
		off += copy(b1[off:off+4], b2[1:5])
	}
	off += copy(b1[off:off+4], b2[5:9])
	b1[off] = b2[9]
	if b2[10] != 255 {
		b1[off] |= 0x80
		off++
		b1[off] = b2[10]
	}
	off++
	b1[off] = b2[11]
	off++
	netPlayerK1 = f5
	netPlayerK2 = f7
	return off
}

func sub_4DF9B0(b1, b2 []byte, full bool) int {
	if len(b1) < 8 || full && len(b1) < 10 {
		return -1
	}
	f1 := binary.LittleEndian.Uint16(b2[1:])
	f3 := binary.LittleEndian.Uint16(b2[3:])
	f5 := binary.LittleEndian.Uint16(b2[5:])
	f7 := binary.LittleEndian.Uint16(b2[7:])
	v4 := sub_57B930(netPlayerPlus16, f1, f3, noxServer.Frame())
	b1[0] = v4
	off := 1
	if v4 == 255 {
		off += copy(b1[off:off+4], b2[1:5])
	}
	if full {
		if f5 > 6000 || f7 > 6000 {
			return 0
		}
		binary.LittleEndian.PutUint16(b1[off+0:], f5)
		binary.LittleEndian.PutUint16(b1[off+2:], f7)
		off += 4
	} else {
		b1[off+0] = byte(int(f5) - int(netPlayerK1))
		b1[off+1] = byte(int(f7) - int(netPlayerK2))
		off += 2
	}
	netPlayerK1 = f5
	netPlayerK2 = f7
	if b2[0] == byte(noxnet.MSG_COMPLEX_OBJ) || b2[0] == byte(noxnet.MSG_PLAYER_OBJ) {
		b1[off] = b2[9]
		if b2[10] != 255 {
			b1[off] |= 0x80
			off++
			b1[off] = b2[10]
		}
		if b2[0] == byte(noxnet.MSG_PLAYER_OBJ) {
			off++
			b1[off] = b2[11]
		}
		off++
	}
	return off
}
