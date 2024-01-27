package opennox

import (
	"encoding/binary"

	"github.com/noxworld-dev/opennox-lib/noxnet"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/ntype"
	"github.com/noxworld-dev/opennox/v1/internal/netstr"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	xferDataArr       []xferData
	xferDataCnt       int
	xferDataActive    int
	dword_5d4594_3620 []xferDataTwo
	dword_5d4594_3624 int
	dword_5d4594_3628 int
)

type xferData struct {
	NetInd0   netstr.Handle // 0, 0
	Stream4   byte          // 1, 4
	Kind6     uint16        // 1, 6
	Size8     int           // 2, 8
	Cnt12     uint32        // 3, 12
	Blocks16  int           // 4, 16
	BlockSz20 uint16        // 5, 20
	Field22   byte          // 5, 22
	Type23    string        // 5, 23
	First152  *xferBlock    // 38, 152
	Last156   *xferBlock    // 39, 156
}

type xferDataTwo struct {
	NetInd0  netstr.Handle // 0, 0
	Act4     byte          // 1, 4
	Stream5  byte          // 1, 5
	Cnt8     uint32        // 2, 8
	Cur12    int           // 3, 12
	Data20   []byte        // 5, 20
	Type24   string        // 6, 24
	Perc152  float32       // 38, 152
	Frame156 uint32        // 39, 156
	Field160 *xferBlock    // 40, 160
	Field164 *xferBlock    // 41, 164
}

type xferBlock struct {
	Ind0    uint16     // 0, 0
	Data4   []byte     // 1, 4
	Frame12 uint32     // 3, 12
	Cnt16   uint16     // 4, 16
	Next20  *xferBlock // 5, 20
	Prev24  *xferBlock // 6, 24
}

func xferCodeFive40B720(a1 byte, a2 byte) {
	sub_40B4E0(a2)
	sub_40B1F0(a2)
}

func sub_40B740() {
	for i := 0; i < dword_5d4594_3624; i++ {
		sub_40B4E0(byte(i))
	}
	dword_5d4594_3620 = nil
}

func sub_40B4E0(a1 uint8) {
	p := &dword_5d4594_3620[a1]
	for it := p.Field160; it != nil; it = it.Next20 {
		*it = xferBlock{}
	}
}

func sub_40B1F0(i byte) {
	p := &dword_5d4594_3620[i]
	p.Act4 = 0
	p.Stream5 = i
	p.Cnt8 = 1
	p.Cur12 = 0
	p.Data20 = nil
	p.Type24 = ""
	p.Perc152 = 0
	p.Frame156 = 0
	p.Field160 = nil
	p.Field164 = nil
}

func sub_40B170(cnt int) {
	n := cnt
	if cnt >= 0 {
		if cnt > 256 {
			n = 256
		}
	} else {
		n = 16
	}
	dword_5d4594_3624 = n
	dword_5d4594_3620 = make([]xferDataTwo, n)
	for i := 0; i < dword_5d4594_3624; i++ {
		sub_40B1F0(byte(i))
	}
}

func sub_40B790() {
	s := noxServer
	for i := 0; i < dword_5d4594_3624; i++ {
		it := &dword_5d4594_3620[i]
		if len(it.Data20) != 0 && s.Frame() > it.Frame156+900 {
			sub_40B530(byte(i), 3)
		}
	}
}

func sub_40B530(i byte, a2 byte) {
	p := &dword_5d4594_3620[i]
	if len(p.Data20) != 0 {
		nox_xxx_neXfer_40B590(p.NetInd0, p.Stream5, a2)
		if dword_5d4594_3628 != 0 {
			dword_5d4594_3628--
		}
		sub_40B4E0(i)
		sub_40B1F0(i)
	}
}

func sub_40B6D0() (*xferDataTwo, byte) {
	if dword_5d4594_3624 <= 0 {
		return nil, 0
	}
	for i := 0; i < dword_5d4594_3624; i++ {
		it := &dword_5d4594_3620[i]
		if len(it.Data20) == 0 {
			return it, byte(i)
		}
	}
	return nil, 0
}

func xferStart40B5D0(a1 netstr.Handle, act byte, typ string, sz uint32, tok byte) {
	s := noxServer
	if sz == 0 {
		return
	}
	p, ind := sub_40B6D0()
	if p == nil {
		return
	}
	p.NetInd0 = a1
	p.Act4 = act
	if typ != "" {
		p.Type24 = typ
	}
	p.Stream5 = ind
	p.Data20 = make([]byte, sz)
	p.Frame156 = s.Frame()
	dword_5d4594_3628++
	xferSendAccept(a1, ind, tok)
}

func xferDataChunk40B250(ind netstr.Handle, a2 byte, a3 uint16, data []byte) {
	s := noxServer
	if len(data) == 0 {
		return
	}
	if int(a2) >= dword_5d4594_3624 {
		return
	}
	p := &dword_5d4594_3620[a2]
	if len(p.Data20) == 0 {
		return
	}
	p.Frame156 = s.Frame()
	if uint32(a3) == p.Cnt8 {
		copy(p.Data20[p.Cur12:p.Cur12+len(data)], data)
		p.Cur12 += len(data)
		p.Cnt8++
	} else {
		b := &xferBlock{
			Ind0:  a3,
			Data4: make([]byte, len(data)),
		}
		copy(b.Data4, data)
		b.Next20 = nil
		b.Prev24 = p.Field164
		if v9 := p.Field164; v9 != nil {
			v9.Next20 = b
		}
		p.Field164 = b
		if v10 := p.Field160; v10 == nil {
			p.Field160 = b
		}
	}

	for it := p.Field160; it != nil; it = it.Next20 {
		if p.Cnt8 == uint32(it.Ind0) {
			copy(p.Data20[p.Cur12:p.Cur12+len(it.Data4)], it.Data4)
			p.Cur12 += len(it.Data4)
			p.Cnt8++
			if v14 := it.Prev24; v14 != nil {
				v14.Next20 = it.Next20
			} else {
				p.Field160 = it.Next20
			}
			if v15 := it.Next20; v15 != nil {
				v15.Prev24 = it.Prev24
			} else {
				p.Field164 = it.Prev24
			}
			*it = xferBlock{}
		}
	}
	p.Perc152 = float32(float64(p.Cur12) / float64(len(p.Data20)) * 100.0)
	if p.Cur12 == len(p.Data20) {
		nox_xxx_netXfer_40B4B0(p.NetInd0, p.Stream5)
		xferDataCallback40AF90(ind.Player(), p.Stream5, p.Act4, p.Type24, p.Data20)
		if dword_5d4594_3628 != 0 {
			dword_5d4594_3628--
		}
		p.Data20 = nil
		sub_40B4E0(a2)
		sub_40B1F0(a2)
	}
}

func xferAck40BF60(ind netstr.Handle, a2 byte, a3 uint16) {
	p := sub_40BC10(ind, a2)
	if p == nil {
		return
	}
	for it := p.First152; it != nil; it = it.Next20 {
		if it.Ind0 == a3 {
			if next := it.Next20; next != nil {
				next.Prev24 = it.Prev24
			} else {
				p.Last156 = it.Prev24
			}
			if prev := it.Prev24; prev != nil {
				prev.Next20 = it.Next20
			} else {
				p.First152 = it.Next20
			}
			*it = xferBlock{}
			return
		}
	}
}

func xferClose40C030(ind netstr.Handle, a2 byte) {
	p := sub_40BC10(ind, a2)
	if p == nil {
		return
	}
	sub_40B850(ind, p.Field22)
	xferDataActive--
	sub_40B930(p)
}

func xferCodeSix40C070(ind netstr.Handle, a2 byte, a3 byte) {
	p := sub_40BC10(ind, a3)
	if p == nil {
		return
	}
	sub_40BBC0(p.NetInd0, p.Field22)
	for it := p.First152; it != nil; it = it.Next20 {
		*it = xferBlock{}
	}
	sub_40B930(p)
}

func sub_40BC60(pli ntype.PlayerInd, a2 byte, typ string, data []byte, flag bool) bool {
	p, pi := sub_40BF10()
	if p == nil {
		return false
	}
	if len(data) == 0 {
		return false
	}
	var nind netstr.Handle
	if !noxflags.HasGame(noxflags.GameHost) {
		nind = netstrClientConn
	} else {
		if !noxflags.HasGame(noxflags.GameClient) {
			return false
		}
		if !flag {
			sub_40B810(a2, data)
			return true
		}
		if pli == server.HostPlayerIndex {
			sub_40B810(a2, data)
			return true
		}
		nind = netstr.Global.ByPlayerInd(pli)
	}
	xferDataActive++
	left := data
	const blockSz = 512
	blocks := (len(data)-1)/blockSz + 1
	for i := 0; i < blocks; i++ {
		b := &xferBlock{
			Ind0: uint16(i + 1),
		}
		n := blockSz
		if len(left) <= n {
			n = len(left)
		}
		buf := make([]byte, n)
		copy(buf, left[:n])
		b.Data4 = buf
		b.Frame12 = 0
		b.Cnt16 = 0
		b.Next20 = nil
		b.Prev24 = p.Last156
		left = left[n:]
		if prev := p.Last156; prev != nil {
			prev.Next20 = b
		} else {
			p.First152 = b
		}
		p.Last156 = b
	}
	p.NetInd0 = nind
	p.Stream4 = 0
	p.Kind6 = 1
	p.Size8 = len(data)
	p.Cnt12 = 1
	p.Blocks16 = blocks
	p.BlockSz20 = blockSz
	if typ != "" {
		p.Type23 = typ
	}
	p.Field22 = a2
	nox_xxx_netXferMsg_40BE80(nind, a2, typ, len(data), byte(pi))
	return true
}

func sub_40C0E0(ind netstr.Handle) {
	for i := 0; i < xferDataCnt; i++ {
		it := &xferDataArr[i]
		if it.Blocks16 == 2 && it.NetInd0 == ind {
			sub_40BB20(it.NetInd0, it.Stream4, 1)
		}
	}
}

func sub_40BF10() (*xferData, int) {
	for i := 0; i < xferDataCnt; i++ {
		it2 := &xferDataArr[i]
		if it2.Kind6 == 0 && it2.Size8 == 0 {
			return it2, i
		}
	}
	return nil, -1
}

func sub_40BC10(ind netstr.Handle, a2 byte) *xferData {
	for i := 0; i < xferDataCnt; i++ {
		it := &xferDataArr[i]
		if it.NetInd0 == ind && it.Stream4 == a2 {
			return it
		}
	}
	return nil
}

func xferAccept40BFF0(a1 netstr.Handle, stream byte, tok byte) {
	if int(tok) >= xferDataCnt {
		return
	}
	p := &xferDataArr[tok]
	p.Stream4 = stream
	p.Kind6 = 2
}

func sub_40C0D0() {
	alloc.FreeSlice(xferDataArr)
}

func sub_40B970() {
	s := noxServer
	if xferDataActive == 0 {
		return
	}
	if int32(xferDataCnt) <= 0 {
		return
	}
	for i := 0; i < xferDataCnt; i++ {
		it := &xferDataArr[i]
		if it.Kind6 != 2 {
			continue
		}
		for j, it2 := 0, it.First152; j < 2 && it2 != nil; j, it2 = j+1, it2.Next20 {
			if t := it2.Frame12; t != 0 {
				if s.Frame() > t+90 {
					if it2.Cnt16 >= 20 {
						if it.Kind6 == 2 {
							sub_40BB20(it.NetInd0, it.Stream4, 2)
							break
						}
					} else {
						sub_40BA90(it.NetInd0, it.Stream4, it2.Ind0, it2.Data4)
						it2.Frame12 = s.Frame()
						it2.Cnt16++
					}
				}
			} else {
				sub_40BA90(it.NetInd0, it.Stream4, it2.Ind0, it2.Data4)
				it.Cnt12++
				it2.Frame12 = s.Frame()
			}
		}
	}
}

func sub_40B930(p *xferData) {
	p.NetInd0 = netstr.Handle{}
	p.Stream4 = 0
	p.Kind6 = 0
	p.Size8 = 0
	p.Cnt12 = 1
	p.Blocks16 = 0
	p.BlockSz20 = 0
	p.Field22 = 0
	p.Type23 = ""
	p.First152 = nil
	p.Last156 = nil
}

func sub_40B890(n int) {
	if n < 0 {
		xferDataCnt = 16
	} else {
		xferDataCnt = 256
		if n <= 256 {
			xferDataCnt = n
		}
	}
	xferDataArr, _ = alloc.Make([]xferData{}, xferDataCnt)
	for i := 0; i < xferDataCnt; i++ {
		sub_40B930(&xferDataArr[i])
	}
	xferDataActive = 0
}

func nox_xxx_netXferMsg_40BE80(conn netstr.Handle, act byte, typ string, sz int, tok byte) {
	var buf [140]byte
	buf[0] = byte(noxnet.MSG_XFER_MSG)
	buf[1] = 0 // XFER_START
	buf[2] = act
	binary.LittleEndian.PutUint32(buf[4:], uint32(sz))
	n := copy(buf[8:136], typ)
	buf[8+n] = 0
	buf[136] = tok
	conn.Send(buf[:140], netstr.SendQueue|netstr.SendFlush)
}

func xferSendAccept(conn netstr.Handle, stream byte, tok byte) {
	var buf [4]byte
	buf[0] = byte(noxnet.MSG_XFER_MSG)
	buf[1] = 1 // XFER_ACCEPT
	buf[2] = stream
	buf[3] = tok
	conn.Send(buf[:4], netstr.SendQueue|netstr.SendFlush)
}

func sub_40BA90(conn netstr.Handle, a2 byte, block uint16, data []byte) int {
	buf := make([]byte, 8+len(data))
	buf[0] = byte(noxnet.MSG_XFER_MSG)
	buf[1] = 2 // XFER_DATA
	buf[2] = a2
	buf[3] = 0
	binary.LittleEndian.PutUint16(buf[4:], block)
	binary.LittleEndian.PutUint16(buf[6:], uint16(len(data)))
	copy(buf[8:], data)
	conn.Send(buf, 0)
	return conn.SendReadPacket(true)
}

func nox_xxx_netXfer_40B4B0(conn netstr.Handle, a2 byte) {
	var buf [3]byte
	buf[0] = byte(noxnet.MSG_XFER_MSG)
	buf[1] = 4 // XFER_CLOSE
	buf[2] = a2
	conn.Send(buf[:3], netstr.SendQueue|netstr.SendFlush)
}

func sub_40BB20(conn netstr.Handle, a2 byte, a3 byte) *xferData {
	p := sub_40BC10(conn, a2)
	if p == nil {
		return nil
	}
	var buf [4]byte
	buf[0] = byte(noxnet.MSG_XFER_MSG)
	buf[1] = 5 // XFER_CODE5
	buf[2] = a2
	buf[3] = a3
	conn.Send(buf[:4], netstr.SendQueue|netstr.SendFlush)
	sub_40BBC0(p.NetInd0, p.Field22)
	if xferDataActive != 0 {
		xferDataActive--
	}
	for it := p.First152; it != nil; it = it.Next20 {
		*it = xferBlock{}
	}
	sub_40B930(p)
	return p
}

func nox_xxx_neXfer_40B590(conn netstr.Handle, a2 byte, a3 byte) {
	var buf [4]byte
	buf[0] = byte(noxnet.MSG_XFER_MSG)
	buf[1] = 6 // XFER_CODE6
	buf[2] = a2
	buf[3] = a3
	conn.Send(buf[:4], netstr.SendQueue|netstr.SendFlush)
}
