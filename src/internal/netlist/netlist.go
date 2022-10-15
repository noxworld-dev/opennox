package netlist

import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/common"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
)

const (
	bufSize    = 2048
	maxPackets = 512
)

var (
	Buffer      []byte
	buffersList [3][]buffer
	messageList [3][common.MaxPlayers]*MsgList
)

type buffer struct {
	buf [bufSize]byte
	cur int
}

func init() {
	Buffer, _ = alloc.Make([]byte{}, bufSize)
	buffersList[0], _ = alloc.Make([]buffer{}, common.MaxPlayers)
	buffersList[1], _ = alloc.Make([]buffer{}, common.MaxPlayers)
	buffersList[2], _ = alloc.Make([]buffer{}, common.MaxPlayers)
}

func Init() {
	for i := 0; i < common.MaxPlayers; i++ {
		messageList[0][i] = nil
		messageList[1][i] = newMsgList()
		messageList[2][i] = newMsgList()
	}
	messageList[0][common.MaxPlayers-1] = newMsgList()
}

func Free() {
	for i := 0; i < common.MaxPlayers; i++ {
		for j := 0; j < 3; j++ {
			if l := messageList[j][i]; l != nil {
				l.Free()
				messageList[j][i] = nil
			}
		}
	}
}

func checkSizesA(ind1, ind2 int, sz int) bool {
	if ind2 == 1 {
		psz := ByInd(ind1, 1).Size()
		if psz+sz+ByInd(ind1, 2).Size() > bufSize {
			return false
		}
	} else {
		if sz+ByInd(ind1, ind2).Size() > bufSize {
			return false
		}
	}
	return ByInd(ind1, ind2).Count() < maxPackets
}

func checkSizesB(ind1, ind2 int, sz, sz2 int) bool {
	l := ByInd(ind1, ind2)
	psz := l.Size()
	if sz+psz+sz2 > bufSize {
		return false
	}
	return l.Count() < maxPackets
}

func checkSizesC(ind, a2 int) bool {
	l := ByInd(ind, 2)
	if (a2 + l.Size()) > bufSize {
		return false
	}
	return l.Count() < maxPackets
}

func ResetByInd(ind1, ind2 int) {
	l := ByInd(ind1, ind2)
	if l == nil {
		return
	}
	l.Reset()
	buffersList[ind2+1][ind1].cur = 0
}

func InitByInd(ind int) {
	l := ByInd(ind, 2)
	l.Reset()
	buffersList[0][ind].cur = 0
}

func ResetAllInd(ind int) {
	for i := 0; i < common.MaxPlayers; i++ {
		ResetByInd(i, ind)
	}
}

func ResetAll() {
	for i := 0; i < common.MaxPlayers; i++ {
		ResetByInd(i, 1)
		ResetByInd(i, 0)
		InitByInd(i)
	}
}

func sendByInd(ind1, ind2 int, buf []byte) *byte {
	if len(buf) == 0 {
		return nil
	}
	p := &buffersList[ind2+1][ind1]
	i := p.cur
	if i+len(buf) > bufSize {
		return nil
	}
	copy(p.buf[i:], buf)
	p.cur += len(buf)
	return &p.buf[i]
}

func addToInd(ind int, buf []byte) *byte {
	if len(buf) == 0 {
		return nil
	}
	p := &buffersList[0][ind]
	i := p.cur
	if i+len(buf) > bufSize {
		return nil
	}
	copy(p.buf[i:], buf)
	p.cur += len(buf)
	return &p.buf[i]
}

func AddToMsgListCli(ind1, ind2 int, buf []byte) bool {
	l := ByInd(ind1, ind2)
	if len(buf) == 0 {
		return true
	}
	if !checkSizesA(ind1, ind2, len(buf)) {
		return false
	}
	out := sendByInd(ind1, ind2, buf)
	if out == nil {
		return false
	}
	l.add(out, len(buf), true)
	return true
}

func CopyPacketsA(ind1, ind2 int) []byte {
	list := ByInd(ind1, ind2)
	out := make([]byte, 0, bufSize)
	for {
		buf := list.Get()
		if len(buf) == 0 {
			return out
		} else if len(out)+len(buf) > cap(out) {
			// TODO: is it okay that it discards data?
			return out
		}
		out = append(out, buf...)
	}
}

func CopyPacketsB(ind int) []byte {
	l := ByInd(ind, 2)
	cnt := 0
	sbuf := Buffer
	copy(sbuf, make([]byte, len(sbuf)))
	for {
		src := l.Get()
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

func ClientSend0(ind1, ind2 int, buf []byte, sz2 int) bool {
	l := ByInd(ind1, ind2)
	if len(buf) == 0 {
		return true
	}
	if !checkSizesB(ind1, ind2, len(buf), sz2) {
		return false
	}
	out := sendByInd(ind1, ind2, buf)
	if out == nil {
		return false
	}
	l.add(out, len(buf), true)
	return true
}

func AddToMsgListSrv(ind int, buf []byte, flush func(ind int)) bool {
	if len(buf) == 0 {
		return true
	}
	// If there are too many updates, then we may run out of space in a single
	// packet. Instead of fragmenting, we can instead send additional packets.
	var out *byte
	l := ByInd(ind, 2)
	if !checkSizesC(ind, len(buf)) || !(func() bool { out = addToInd(ind, buf); return out != nil }()) {
		p := &buffersList[0][ind]

		// The new update packet needs to have correct bytes at the
		// beginning. Save the length of the first two queued datas so we
		// can replay them.
		len1 := len(l.first.buf)
		len2 := len(l.first.next.buf)

		// Flush old data to network.
		flush(ind)

		// Set buffer length and re-queue updates.
		p.cur = len1 + len2
		l.add(&p.buf[0], len1, true)
		l.add(&p.buf[len1], len2, true)

		// Retry original allocation.
		out = addToInd(ind, buf)
	}
	if out == nil {
		return false
	}
	l.add(out, len(buf), true)
	return true
}

func ByInd(ind1, ind2 int) *MsgList {
	return messageList[ind2][ind1]
}

func newMsgList() *MsgList {
	return &MsgList{}
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

func (l *MsgList) Free() {
	*l = MsgList{}
}

func (l *MsgList) Reset() {
	*l = MsgList{}
}

func (l *MsgList) freeItem(item *netListItem) {
	*item = netListItem{}
}

func (l *MsgList) Count() int {
	if l == nil {
		return 0
	}
	return l.count
}

func (l *MsgList) Size() int {
	if l == nil {
		return 0
	}
	return l.size
}

func (l *MsgList) Get() []byte {
	if l == nil || l.first == nil {
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

func (l *MsgList) FindAndFreeBuf(buf *byte) {
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

func (l *MsgList) Each(fnc func(b []byte) bool) {
	if fnc == nil {
		return
	}
	for p := l.first; p != nil; p = p.next {
		if fnc(p.buf) {
			break
		}
	}
}
