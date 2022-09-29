package opennox

/*
#include "defs.h"
#include "common__net_list.h"
extern nox_net_list_t* nox_net_lists[3][NOX_PLAYERINFO_MAX];
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
)

const (
	netListsBufSize        = 2048
	NOX_NETBUF_MAX_PACKETS = 512
)

func asNetList(p *C.nox_net_list_t) *MsgList {
	return (*MsgList)(unsafe.Pointer(p))
}

func netList(ind1, ind2 int) *MsgList {
	return asNetList(C.nox_net_lists[ind2][ind1])
}

var _ = [1]struct{}{}[16-unsafe.Sizeof(netListItem{})]

type netListItem struct {
	buf  unsafe.Pointer // 0, 0
	size uint32         // 1, 4
	prev *netListItem   // 2, 8
	next *netListItem   // 3, 12
}

var _ = [1]struct{}{}[32-unsafe.Sizeof(MsgList{})]

type MsgList struct {
	first   *netListItem       // 0, 0
	last    *netListItem       // 1, 4
	field_2 uint32             // 2, 8
	alloc   *C.nox_alloc_class // 3, 12
	count   uint32             // 4, 16
	size    uint32             // 5, 20
	field_6 uint32             // 6, 24
	field_7 uint32             // 7, 28
}

func (l *MsgList) C() *C.nox_net_list_t {
	return (*C.nox_net_list_t)(unsafe.Pointer(l))
}

func (l *MsgList) freeItem(item *netListItem) {
	alloc.AsClass(unsafe.Pointer(l.alloc)).FreeObjectFirst(unsafe.Pointer(item))
}

func (l *MsgList) get() []byte { // nox_netlist_get_420A90
	if l.first == nil {
		return nil
	}
	item := l.first
	sz := int(item.size)

	l.count--
	l.size -= item.size

	if next := item.next; next != nil {
		next.prev = item.prev
	} else {
		l.last = item.prev
	}
	if prev := item.prev; prev != nil {
		prev.next = item.next
	} else {
		l.first = item.next
	}

	buf := unsafe.Slice((*byte)(item.buf), sz)
	l.freeItem(item)
	return buf
}

func nox_netlist_copyPacketList_40ED60(ind1, ind2 int) []byte {
	list := netList(ind1, ind2)
	out := make([]byte, 0, netListsBufSize)
	for {
		buf := list.get()
		if len(buf) == 0 {
			return out
		} else if len(out)+len(buf) > cap(out) {
			// TODO: is it okay that it discards data?
			return out
		}
		out = append(out, buf...)
	}
}

func (l *MsgList) Count() int { // nox_netlist_count_420BC0
	if l == nil {
		return 0
	}
	return int(l.count)
}

func (l *MsgList) Size() int { // nox_netlist_size_420BD0
	if l == nil {
		return 0
	}
	return int(l.size)
}

func nox_netlist_countByInd_40E9D0(ind1, ind2 int) int {
	return netList(ind1, ind2).Count()
}

func nox_netlist_sizeByInd_40E9F0(ind1, ind2 int) int {
	return netList(ind1, ind2).Size()
}

func nox_netlist_countByInd2_40F0B0(ind int) int {
	return nox_netlist_countByInd_40E9D0(ind, 2)
}

func nox_netlist_sizeByInd2_40F0D0(ind int) int {
	return nox_netlist_sizeByInd_40E9F0(ind, 2)
}

func newMsgList(cnt int) *MsgList {
	p, _ := alloc.New(MsgList{})
	aclass := alloc.NewClass("CreateMsgList", unsafe.Sizeof(netListItem{}), cnt)
	p.first = nil
	p.last = nil
	p.field_2 = 0
	p.alloc = (*C.nox_alloc_class)(aclass.UPtr())
	p.count = 0
	p.size = 0
	p.field_6 = 0
	p.field_7 = 0
	return p
}

func nox_netlist_init_40EA10() {
	for i := 0; i < noxMaxPlayers; i++ {
		C.nox_net_lists[0][i] = nil
		C.nox_net_lists[1][i] = newMsgList(NOX_NETBUF_MAX_PACKETS).C()
		C.nox_net_lists[2][i] = newMsgList(NOX_NETBUF_MAX_PACKETS).C()
	}
	C.nox_net_lists[0][noxMaxPlayers-1] = newMsgList(NOX_NETBUF_MAX_PACKETS).C()
}

func (l *MsgList) Free() {
	alloc.AsClass(unsafe.Pointer(l.alloc)).Free()
	l.alloc = nil
	alloc.Free(unsafe.Pointer(l.C()))
}

func nox_netlist_free_40EA70() {
	for i := 0; i < noxMaxPlayers; i++ {
		for j := 0; j < 3; j++ {
			if l := asNetList(C.nox_net_lists[j][i]); l != nil {
				l.Free()
				C.nox_net_lists[j][i] = nil
			}
		}
	}
}
