package opennox

/*
#include "defs.h"
#include "common__net_list.h"
extern nox_net_list_t* nox_net_lists[3][NOX_PLAYERINFO_MAX];

int nox_xxx_netOnPacketRecvCli_48EA70(int a1, unsigned char* data, int sz);
int nox_xxx_netSendReadPacket_5528B0(unsigned int a1, char a2);
int sub_48D660();
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
)

var (
	nox_net_lists_buf     []byte
	nox_net_lists_buf_arr [3][]netBuf
)

type netBuf struct {
	buf [netListsBufSize]byte
	cur int
}

func init() {
	nox_net_lists_buf, _ = alloc.Make([]byte{}, netListsBufSize)
	nox_net_lists_buf_arr[0], _ = alloc.Make([]netBuf{}, noxMaxPlayers)
	nox_net_lists_buf_arr[1], _ = alloc.Make([]netBuf{}, noxMaxPlayers)
	nox_net_lists_buf_arr[2], _ = alloc.Make([]netBuf{}, noxMaxPlayers)
}

//export nox_netlist_addToMsgListCli_40EBC0
func nox_netlist_addToMsgListCli_40EBC0(ind1, ind2 C.int, buf *C.uchar, sz C.int) C.int {
	return C.int(bool2int(nox_netlist_addToMsgListCli(int(ind1), int(ind2), unsafe.Slice((*byte)(unsafe.Pointer(buf)), int(sz)))))
}

//export nox_netlist_clientSend_0_40ECA0
func nox_netlist_clientSend_0_40ECA0(ind1, ind2 C.int, buf *C.uchar, sz, sz2 C.int) C.int {
	return C.int(bool2int(nox_netlist_clientSend_0(int(ind1), int(ind2), unsafe.Slice((*byte)(unsafe.Pointer(buf)), int(sz)), int(sz2))))
}

//export nox_netlist_addToMsgListSrv_40EF40
func nox_netlist_addToMsgListSrv_40EF40(ind C.int, buf *C.uchar, sz C.int) C.bool {
	return C.bool(nox_netlist_addToMsgListSrv(int(ind), unsafe.Slice((*byte)(unsafe.Pointer(buf)), int(sz))))
}

//export nox_netlist_getInd_40EEB0
func nox_netlist_getInd_40EEB0(ind1, ind2 C.int, outSz *C.uint) *C.uchar {
	buf := netList(int(ind1), int(ind2)).get()
	*outSz = C.uint(len(buf))
	if len(buf) == 0 {
		return nil
	}
	return (*C.uchar)(unsafe.Pointer(&buf[0]))
}

//export nox_netlist_getByInd2_40F080
func nox_netlist_getByInd2_40F080(ind C.int, outSz *C.uint) *C.uchar {
	buf := netList(int(ind), 2).get()
	*outSz = C.uint(len(buf))
	if len(buf) == 0 {
		return nil
	}
	return (*C.uchar)(unsafe.Pointer(&buf[0]))
}

//export nox_netlist_copyPacketList_40ED60
func nox_netlist_copyPacketList_40ED60(ind1, ind2 C.int, outSz *C.uint) *C.uchar {
	buf := nox_netlist_copyPacketList(int(ind1), int(ind2))
	sbuf := nox_net_lists_buf
	copy(sbuf, make([]byte, len(sbuf)))
	*outSz = C.uint(len(buf))
	copy(sbuf, buf)
	return (*C.uchar)(unsafe.Pointer(&sbuf[0]))
}

const (
	netListsBufSize    = 2048
	netListsMaxPackets = 512
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

func nox_netlist_copyPacketList(ind1, ind2 int) []byte {
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
		C.nox_net_lists[1][i] = newMsgList(netListsMaxPackets).C()
		C.nox_net_lists[2][i] = newMsgList(netListsMaxPackets).C()
	}
	C.nox_net_lists[0][noxMaxPlayers-1] = newMsgList(netListsMaxPackets).C()
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
	return netList(ind1, ind2).Count() < netListsMaxPackets
}

func nox_netlist_checkSizesExt_40EB60(ind1, ind2 int, sz, sz2 int) bool {
	l := netList(ind1, ind2)
	psz := l.Size()
	if sz+psz+sz2 > netListsBufSize {
		return false
	}
	return l.Count() < netListsMaxPackets
}

func nox_xxx_netBufsSetZero_40ED40(ind, ind2 int) {
	nox_net_lists_buf_arr[ind2+1][ind].cur = 0
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
	nox_net_lists_buf_arr[0][ind].cur = 0
}

func nox_netlist_sendByInd_40EC30(ind1, ind2 int, buf []byte) *byte {
	if len(buf) == 0 {
		return nil
	}
	p := &nox_net_lists_buf_arr[ind2+1][ind1]
	i := p.cur
	if i+len(buf) > netListsBufSize {
		return nil
	}
	copy(p.buf[i:], buf)
	p.cur += len(buf)
	return &p.buf[i]
}

func nox_xxx_netlistAdd_40EFA0(ind int, buf []byte) *byte {
	if len(buf) == 0 {
		return nil
	}
	p := &nox_net_lists_buf_arr[0][ind]
	i := p.cur
	if i+len(buf) > netListsBufSize {
		return nil
	}
	copy(p.buf[i:], buf)
	p.cur += len(buf)
	return &p.buf[i]
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

func sub_40EEF0(ind, a2 int) bool {
	l := netList(ind, 2)
	if (a2 + l.Size()) > netListsBufSize {
		return false
	}
	return l.Count() < netListsMaxPackets
}

func nox_netlist_addToMsgListSrv(ind int, buf []byte) bool {
	if len(buf) == 0 {
		return true
	}
	s := noxServer
	// If there are too many updates, then we may run out of space in a single
	// packet. Instead of fragmenting, we can instead send additional packets.
	var out *byte
	l := netList(ind, 2)
	if !sub_40EEF0(ind, len(buf)) || !(func() bool { out = nox_xxx_netlistAdd_40EFA0(ind, buf); return out != nil }()) {
		p := &nox_net_lists_buf_arr[0][ind]

		// The new update packet needs to have correct bytes at the
		// beginning. Save the length of the first two queued datas so we
		// can replay them.
		len1 := int(l.first.size)
		len2 := int(l.first.next.size)

		// Flush old data to network.
		if ind == noxMaxPlayers-1 {
			nox_netlist_receiveCli_494E90(ind)
		} else {
			C.nox_xxx_netSendReadPacket_5528B0(C.uint(s.getPlayerByInd(ind).Index())+1, 0)
		}

		// Set buffer length and re-queue updates.
		p.cur = len1 + len2
		nox_netlist_add_420940(l, &p.buf[0], len1, true)
		nox_netlist_add_420940(l, &p.buf[len1], len2, true)

		// Retry original allocation.
		out = nox_xxx_netlistAdd_40EFA0(ind, buf)
	}
	if out == nil {
		return false
	}
	nox_netlist_add_420940(l, out, len(buf), true)
	return true
}

func nox_netlist_copyPacketList2_40F120(ind int) []byte {
	l := netList(ind, 2)
	cnt := 0
	sbuf := nox_net_lists_buf
	copy(sbuf, make([]byte, len(sbuf)))
	for {
		src := l.get()
		if len(src) == 0 {
			break // no more data
		}
		if cnt+len(src) > len(sbuf) {
			// we cannot store it, so put it back
			nox_netlist_add_420940(l, &src[0], len(src), false)
			break
		}
		copy(sbuf[cnt:], src)
		cnt += len(src)
	}
	return sbuf[:cnt]
}

func nox_netlist_receiveCli_494E90(ind int) int {
	res := 0

	if buf1 := nox_netlist_copyPacketList2_40F120(ind); len(buf1) != 0 {
		res = int(C.nox_xxx_netOnPacketRecvCli_48EA70(C.int(ind), (*C.uchar)(unsafe.Pointer(&buf1[0])), C.int(len(buf1))))
	}

	if buf2 := nox_netlist_copyPacketList(ind, 1); len(buf2) != 0 {
		res = int(C.nox_xxx_netOnPacketRecvCli_48EA70(C.int(ind), (*C.uchar)(unsafe.Pointer(&buf2[0])), C.int(len(buf2))))
		if res != 0 {
			C.sub_48D660()
		}
	}
	return res
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
