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

const netListsBufSize = 2048

func asNetList(p *C.nox_net_list_t) *NetList {
	return (*NetList)(unsafe.Pointer(p))
}

var _ = [1]struct{}{}[16-unsafe.Sizeof(netListItem{})]

type netListItem struct {
	buf  unsafe.Pointer // 0, 0
	size uint32         // 1, 4
	prev *netListItem   // 2, 8
	next *netListItem   // 3, 12
}

var _ = [1]struct{}{}[32-unsafe.Sizeof(NetList{})]

type NetList struct {
	first   *netListItem       // 0, 0
	last    *netListItem       // 1, 4
	field_2 uint32             // 2, 8
	alloc   *C.nox_alloc_class // 3, 12
	count   uint32             // 4, 16
	size    uint32             // 5, 20
	field_6 uint32             // 6, 24
	field_7 uint32             // 7, 28
}

func (l *NetList) C() *C.nox_net_list_t {
	return (*C.nox_net_list_t)(unsafe.Pointer(l))
}

func (l *NetList) freeItem(item *netListItem) {
	alloc.AsClass(unsafe.Pointer(l.alloc)).FreeObjectFirst(unsafe.Pointer(item))
}

func (l *NetList) get() []byte { // nox_netlist_get_420A90
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
	list := asNetList(C.nox_net_lists[ind2][ind1])
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
