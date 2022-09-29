package opennox

/*
#include "defs.h"
#include "common__net_list.h"
typedef struct {
	unsigned char buf[2048];
	unsigned int cur;
} nox_net_lists_buf_t;
extern nox_net_list_t* nox_net_lists[3][NOX_PLAYERINFO_MAX];
extern nox_net_lists_buf_t nox_net_lists_buf_arr[3][NOX_PLAYERINFO_MAX];
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
)

//export nox_netlist_addToMsgListCli_40EBC0
func nox_netlist_addToMsgListCli_40EBC0(ind1, ind2 C.int, buf *C.uchar, sz C.int) C.int {
	return C.int(bool2int(nox_netlist_addToMsgListCli(int(ind1), int(ind2), unsafe.Slice((*byte)(unsafe.Pointer(buf)), int(sz)))))
}

//export nox_netlist_clientSend_0_40ECA0
func nox_netlist_clientSend_0_40ECA0(ind1, ind2 C.int, buf *C.uchar, sz, sz2 C.int) C.int {
	return C.int(bool2int(nox_netlist_clientSend_0(int(ind1), int(ind2), unsafe.Slice((*byte)(unsafe.Pointer(buf)), int(sz)), int(sz2))))
}

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

func (l *MsgList) Alloc() alloc.ClassT[netListItem] {
	return alloc.AsClassT[netListItem](unsafe.Pointer(l.alloc))
}

func (l *MsgList) freeItem(item *netListItem) {
	l.Alloc().FreeObjectFirst(item)
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
	l.Alloc().Free()
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

func nox_netlist_checkSizes_40EAC0(ind1, ind2 int, sz int) bool {
	if ind2 == 1 {
		psz := nox_netlist_sizeByInd_40E9F0(ind1, 1)
		if psz+sz+nox_netlist_sizeByInd_40E9F0(ind1, 2) > netListsBufSize {
			return false
		}
	} else {
		if sz+nox_netlist_sizeByInd_40E9F0(ind1, ind2) > netListsBufSize {
			return false
		}
	}
	return netList(ind1, ind2).Count() < NOX_NETBUF_MAX_PACKETS
}

func nox_netlist_checkSizesExt_40EB60(ind1, ind2 int, sz, sz2 int) bool {
	l := netList(ind1, ind2)
	psz := l.Size()
	if sz+psz+sz2 > netListsBufSize {
		return false
	}
	return l.Count() < NOX_NETBUF_MAX_PACKETS
}

func nox_xxx_netBufsSetZero_40ED40(ind, ind2 int) {
	C.nox_net_lists_buf_arr[ind2+1][ind].cur = 0
}

func (l *MsgList) Reset() { // nox_netlist_resetList_420830
	l.first = nil
	l.last = nil
	l.field_2 = 0
	l.count = 0
	l.size = 0
	l.Alloc().FreeAllObjects()
}

//export nox_netlist_resetByInd_40ED10
func nox_netlist_resetByInd_40ED10(ind1, ind2 int) {
	l := netList(ind1, ind2)
	if l == nil {
		return
	}
	l.Reset()
	nox_xxx_netBufsSetZero_40ED40(ind1, ind2)
}

//export nox_netlist_initPlayerBufs_40F020
func nox_netlist_initPlayerBufs_40F020(ind int) {
	l := netList(ind, 2)
	l.Reset()
	sub_40F040(ind)
}

func nox_netlist_resetAllInList_40EE90(ind int) {
	for i := 0; i < noxMaxPlayers; i++ {
		nox_netlist_resetByInd_40ED10(i, ind)
	}
}

func nox_netlist_resetAll_40EE60() {
	for i := 0; i < noxMaxPlayers; i++ {
		nox_netlist_resetByInd_40ED10(i, 1)
		nox_netlist_resetByInd_40ED10(i, 0)
		nox_netlist_initPlayerBufs_40F020(i)
	}
}

func sub_40F040(ind int) {
	C.nox_net_lists_buf_arr[0][ind].cur = 0
}

func nox_netlist_sendByInd_40EC30(ind1, ind2 int, buf []byte) *byte {
	if len(buf) == 0 {
		return nil
	}
	p := &C.nox_net_lists_buf_arr[ind2+1][ind1]
	i := int(p.cur)
	if i+len(buf) > netListsBufSize {
		return nil
	}
	ptr := (*byte)(unsafe.Pointer(&p.buf[i]))
	dst := unsafe.Slice(ptr, len(buf))
	copy(dst, buf)
	p.cur += C.uint(len(buf))
	return ptr
}

func nox_netlist_addToMsgListCli(ind1, ind2 int, buf []byte) bool {
	l := netList(ind1, ind2)
	if len(buf) == 0 {
		return true
	}
	if !nox_netlist_checkSizes_40EAC0(ind1, ind2, len(buf)) {
		return false
	}
	out := nox_netlist_sendByInd_40EC30(ind1, ind2, buf)
	if out == nil {
		return false
	}
	nox_netlist_add_420940(l, out, len(buf), true)
	return true
}

func nox_netlist_clientSend_0(ind1, ind2 int, buf []byte, sz2 int) bool {
	l := netList(ind1, ind2)
	if len(buf) == 0 {
		return true
	}
	if !nox_netlist_checkSizesExt_40EB60(ind1, ind2, len(buf), sz2) {
		return false
	}
	out := nox_netlist_sendByInd_40EC30(ind1, ind2, buf)
	if out == nil {
		return false
	}
	nox_netlist_add_420940(l, out, len(buf), true)
	return true
}

func nox_netlist_add_420940(l *MsgList, buf *byte, sz int, appnd bool) bool {
	it := l.Alloc().NewObject()
	if it == nil {
		return false
	}
	it.buf = unsafe.Pointer(buf)
	it.size = uint32(sz)
	if appnd {
		it.prev = l.last
		it.next = nil
		if l.last != nil {
			l.last.next = it
		} else {
			l.first = it
		}
		l.last = it
	} else {
		it.prev = nil
		it.next = l.first
		if l.first != nil {
			l.first.prev = it
		} else {
			l.last = it
		}
		l.first = it
	}
	l.count++
	l.size += uint32(sz)
	return true
}
