package opennox

import (
	"encoding/binary"
	"errors"
	"fmt"
	"io"
	"time"

	"github.com/noxworld-dev/opennox-lib/common"
	"github.com/noxworld-dev/opennox-lib/console"
	"github.com/noxworld-dev/opennox-lib/datapath"
	"github.com/noxworld-dev/opennox-lib/ifs"
	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/platform"

	"github.com/noxworld-dev/opennox/v1/common/ntype"
	"github.com/noxworld-dev/opennox/v1/internal/netstr"
	"github.com/noxworld-dev/opennox/v1/legacy"
)

const (
	mapSendPacketSize = 512
	mapSendMaxQueue   = 2
)

type serverMapSend struct {
	s           *Server
	players     [common.MaxPlayers - 1]playerMapSend
	mapName     string
	currentData []byte // shared
	activeCnt   int
}

func (s *serverMapSend) init(srv *Server) {
	s.s = srv
}

type playerMapSend struct {
	PlayerInd ntype.PlayerInd // 0, 0
	Active    bool            // 0, 2
	OwnBuffer bool            // 1, 4
	Data      []byte          // 2, 8
	DataSize  int             // 3, 12
	Sequence  uint32          // 4, 16
	SentSize  int             // 6, 24
	Field32   uint32          // 8, 32
	Start     time.Duration   // 10, 40
}

func (p *playerMapSend) Clear(pli ntype.PlayerInd) {
	if p == nil {
		return
	}
	*p = playerMapSend{
		PlayerInd: pli,
		Sequence:  1,
	}
}

func (s *serverMapSend) CountQueued(pli ntype.PlayerInd) int {
	nind := s.players[pli].PlayerInd
	if nind == 0 || pli >= 32 {
		return 0
	}
	return netstr.Global.PlayerInd(nind).CountInQueue(noxnet.MSG_MAP_SEND_START, noxnet.MSG_MAP_SEND_PACKET)
}

func (s *serverMapSend) Reset() {
	s.currentData = nil
	s.activeCnt = 0
	for i := range s.players {
		s.players[i].Clear(ntype.PlayerInd(i))
	}
}

func (s *serverMapSend) sub_51A100() {
	if s.activeCnt != 0 {
		s.AbortAll(0)
	}
	s.currentData = nil
}

func (s *serverMapSend) abort(p *playerMapSend, errCode byte) {
	if p == nil {
		return
	}
	var buf [2]byte
	buf[0] = byte(noxnet.MSG_MAP_SEND_ABORT)
	buf[1] = byte(errCode)
	netstr.Global.Send(netstr.Global.PlayerInd(p.PlayerInd), buf[:2], netstr.SendNoLock|netstr.SendFlagFlush)
	if s.activeCnt != 0 {
		s.activeCnt--
	}
	format := strMan.GetStringInFile("downloadaborted", "mapsend.c")
	noxConsole.Print(console.ColorRed, fmt.Sprintf(format, int(p.PlayerInd), errCode))
}

func (s *serverMapSend) SendMore(p *playerMapSend) {
	if p == nil {
		return
	}
	if p.SentSize == 0 {
		if pl := s.s.Players.ByInd(p.PlayerInd); pl != nil {
			format := strMan.GetStringInFile("Downloadingmap", "mapsend.c")
			noxConsole.Print(console.ColorRed, fmt.Sprintf(format, s.mapName, pl.Name()))
		}
		var buf [88]byte
		buf[0] = byte(noxnet.MSG_MAP_SEND_START)
		binary.LittleEndian.PutUint32(buf[4:], uint32(p.DataSize))
		copy(buf[8:], s.mapName)
		netstr.Global.Send(netstr.Global.PlayerInd(p.PlayerInd), buf[:88], netstr.SendNoLock|netstr.SendFlagFlush)
	}
	psz := mapSendPacketSize
	packet := make([]byte, 6+psz)
	if dsz := p.DataSize - p.SentSize; psz >= dsz {
		psz = dsz
	}
	packet[0] = byte(noxnet.MSG_MAP_SEND_PACKET)
	binary.LittleEndian.PutUint16(packet[2:], uint16(p.Sequence))
	binary.LittleEndian.PutUint16(packet[4:], uint16(psz))
	var src []byte
	if p.OwnBuffer {
		src = p.Data[p.SentSize:]
	} else {
		src = s.currentData[p.SentSize:]
	}
	copy(packet[6:], src[:psz])
	netstr.Global.Send(netstr.Global.PlayerInd(p.PlayerInd), packet[:6+psz], netstr.SendNoLock|netstr.SendFlagFlush)
	p.Sequence++
	p.SentSize += psz
	if p.SentSize < p.DataSize {
		p.Active = true
		return
	}
	var speed int
	sec := (platform.Ticks() - p.Start).Seconds()
	if sec != 0 {
		speed = int(float64(p.DataSize) / sec)
	} else {
		speed = p.DataSize
	}
	if pl := s.s.Players.ByInd(p.PlayerInd); pl != nil {
		format := strMan.GetStringInFile("downloaddone", "mapsend.c")
		noxConsole.Print(console.ColorRed, fmt.Sprintf(format, p.SentSize, p.Sequence-1, speed, sec, pl.Name()))
	}
	if s.activeCnt != 0 {
		s.activeCnt--
	}
	format := strMan.GetStringInFile("InProgress", "mapsend.c")
	noxConsole.Print(console.ColorRed, fmt.Sprintf(format, s.activeCnt))
	p.Clear(p.PlayerInd)
}

func (s *serverMapSend) AbortAll(errCode byte) {
	for i := range s.players {
		it := &s.players[i]
		if !it.Active {
			continue
		}
		it.Active = false
		s.abort(it, errCode)
		it.Clear(ntype.PlayerInd(i))
	}
}

func (s *serverMapSend) EndReceive(pli ntype.PlayerInd) {
	legacy.Sub_4DE410(s.players[pli].PlayerInd)
}

func (s *serverMapSend) StartSendShared(pli ntype.PlayerInd) {
	s.activeCnt++
	p := &s.players[pli]
	if p.Active {
		str := strMan.GetStringInFile("Sending", "mapsend.c")
		noxConsole.Print(console.ColorRed, str)
	} else {
		p.Active = true
		p.DataSize = len(s.currentData)
		p.Sequence = 1
		p.SentSize = 0
		p.Start = platform.Ticks()
	}
}

func (s *serverMapSend) ForceCopy() {
	for i := range s.players {
		it := &s.players[i]
		if !it.Active {
			s.abort(it, 1)
			continue
		}
		data := make([]byte, len(s.currentData))
		copy(data, s.currentData)
		it.Data = data
		it.OwnBuffer = true
		it.DataSize = len(data)
		str := strMan.GetStringInFile("ForceCopy", "mapsend.c")
		noxConsole.Print(console.ColorRed, str)
	}
}

func (s *serverMapSend) ReadMapFile() error {
	mname := s.s.nox_server_currentMapGetFilename_409B30()
	if s.activeCnt != 0 {
		s.ForceCopy()
	}
	if mname == "" {
		str := strMan.GetStringInFile("CompressFail", "mapsend.c")
		noxConsole.Print(console.ColorRed, str)
		return errors.New("compress fail: empty map name")
	}
	mname2 := legacy.Nox_xxx_mapGetMapName_409B40()
	fname := datapath.Maps(mname2, mname2+".nxz")
	f, err := ifs.Open(fname)
	if err != nil {
		str := strMan.GetStringInFile("CompressFail", "mapsend.c")
		noxConsole.Print(console.ColorRed, str)
		return fmt.Errorf("compress fail: %w", err)
	}
	defer f.Close()

	s.mapName = mname
	data, err := io.ReadAll(f)
	if err != nil {
		s.currentData = nil
		str := strMan.GetStringInFile("CompressFail", "mapsend.c")
		noxConsole.Print(console.ColorRed, str)
		return fmt.Errorf("compress fail: %w", err)
	}
	s.currentData = data
	return nil
}

func (s *serverMapSend) Update() {
	if s.activeCnt == 0 {
		return
	}
	if len(s.currentData) == 0 {
		s.ReadMapFile()
	}
	for i := range s.players {
		it := &s.players[i]
		if !it.Active {
			continue
		}
		if s.CountQueued(ntype.PlayerInd(i)) <= mapSendMaxQueue {
			s.SendMore(it)
		}
	}
}

func (s *serverMapSend) mapSendCancel(pli ntype.PlayerInd) {
	p := &s.players[pli]
	p.Active = false
	p.Clear(pli)
	if s.activeCnt != 0 {
		s.activeCnt--
	}
	if pl := s.s.Players.ByInd(pli); pl != nil {
		format := strMan.GetStringInFile("downloadcancelled", "mapsend.c")
		noxConsole.Print(console.ColorRed, fmt.Sprintf(format, pl.Name()))
	}
}
