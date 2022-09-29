package opennox

/*
#include "defs.h"
int nox_xxx_netOnPacketRecvCli_48EA70(int a1, unsigned char* data, int sz);
int nox_xxx_netSendReadPacket_5528B0(unsigned int a1, char a2);
int sub_48D660();
*/
import "C"
import (
	"encoding/binary"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

var (
	nox_net_lists_buf     []byte
	nox_net_lists_buf_arr [3][]netBuf
	nox_net_lists         [3][noxMaxPlayers]*MsgList
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

//export nox_netlist_findAndFreeBuf_40F000
func nox_netlist_findAndFreeBuf_40F000(ind C.int, buf *C.uchar) {
	netList(int(ind), 2).findAndFreeBuf((*byte)(unsafe.Pointer(buf)))
}

const (
	netListsBufSize    = 2048
	netListsMaxPackets = 512
)

func netList(ind1, ind2 int) *MsgList {
	return nox_net_lists[ind2][ind1]
}

type netListItem struct {
	buf  []byte
	prev *netListItem
	next *netListItem
}

type MsgList struct {
	first *netListItem
	last  *netListItem
	count int
	size  int
}

func (l *MsgList) freeItem(item *netListItem) {
	*item = netListItem{}
}

func (l *MsgList) get() []byte { // nox_netlist_get_420A90
	if l.first == nil {
		return nil
	}
	item := l.first

	l.count--
	l.size -= len(item.buf)

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

	buf := item.buf
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
	return l.count
}

func (l *MsgList) Size() int { // nox_netlist_size_420BD0
	if l == nil {
		return 0
	}
	return l.size
}

func nox_netlist_countByInd_40E9D0(ind1, ind2 int) int {
	return netList(ind1, ind2).Count()
}

func nox_netlist_sizeByInd_40E9F0(ind1, ind2 int) int {
	return netList(ind1, ind2).Size()
}

//export nox_netlist_countByInd2_40F0B0
func nox_netlist_countByInd2_40F0B0(ind int) int {
	return nox_netlist_countByInd_40E9D0(ind, 2)
}

func nox_netlist_sizeByInd2_40F0D0(ind int) int {
	return nox_netlist_sizeByInd_40E9F0(ind, 2)
}

func newMsgList(cnt int) *MsgList {
	return &MsgList{}
}

func nox_netlist_init_40EA10() {
	for i := 0; i < noxMaxPlayers; i++ {
		nox_net_lists[0][i] = nil
		nox_net_lists[1][i] = newMsgList(netListsMaxPackets)
		nox_net_lists[2][i] = newMsgList(netListsMaxPackets)
	}
	nox_net_lists[0][noxMaxPlayers-1] = newMsgList(netListsMaxPackets)
}

func (l *MsgList) Free() {
	*l = MsgList{}
}

func nox_netlist_free_40EA70() {
	for i := 0; i < noxMaxPlayers; i++ {
		for j := 0; j < 3; j++ {
			if l := nox_net_lists[j][i]; l != nil {
				l.Free()
				nox_net_lists[j][i] = nil
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
	*l = MsgList{}
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
	l.add(out, len(buf), true)
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
	l.add(out, len(buf), true)
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
		len1 := len(l.first.buf)
		len2 := len(l.first.next.buf)

		// Flush old data to network.
		if ind == noxMaxPlayers-1 {
			nox_netlist_receiveCli_494E90(ind)
		} else {
			C.nox_xxx_netSendReadPacket_5528B0(C.uint(s.getPlayerByInd(ind).Index())+1, 0)
		}

		// Set buffer length and re-queue updates.
		p.cur = len1 + len2
		l.add(&p.buf[0], len1, true)
		l.add(&p.buf[len1], len2, true)

		// Retry original allocation.
		out = nox_xxx_netlistAdd_40EFA0(ind, buf)
	}
	if out == nil {
		return false
	}
	l.add(out, len(buf), true)
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
			l.add(&src[0], len(src), false)
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

func (l *MsgList) add(buf *byte, sz int, appnd bool) bool {
	it := &netListItem{buf: unsafe.Slice(buf, sz)}
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
	l.size += sz
	return true
}

func (l *MsgList) findAndFreeBuf(buf *byte) {
	if l.first == nil {
		return
	}
	var item *netListItem
	for p := l.first; p != nil; p = p.next {
		if &p.buf[0] == buf {
			item = p
			break
		}
	}
	if item == nil {
		return
	}
	l.count--
	l.size -= len(item.buf)

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
	*item = netListItem{}
}

func (l *MsgList) each(fnc func(b []byte) bool) {
	if fnc == nil {
		return
	}
	for p := l.first; p != nil; p = p.next {
		if fnc(p.buf) {
			break
		}
	}
}

//export sub_4DF5E0
func sub_4DF5E0(ind, max C.int) unsafe.Pointer {
	a1 := memmap.Int32(0x5D4594, 1563292)
	a2 := memmap.Int32(0x5D4594, 1563296)
	var found *byte
	netList(int(ind), 2).each(func(b []byte) bool {
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
