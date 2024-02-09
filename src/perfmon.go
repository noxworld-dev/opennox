package opennox

import (
	"time"

	"github.com/noxworld-dev/opennox-lib/common"
	"github.com/noxworld-dev/opennox-lib/log"
	"github.com/noxworld-dev/opennox-lib/platform"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/internal/netlist"
	"github.com/noxworld-dev/opennox/v1/server"
	"github.com/noxworld-dev/opennox/v1/server/netlib"
)

var (
	noxPerfmon = newPerfmon()
	bandLog    = log.New("bandwidth")
)

func newPerfmon() *Perfmon {
	return &Perfmon{nextCnt: 10, logger: bandLog}
}

type Perfmon struct {
	enabled       bool
	nextCnt       uint
	cnt           uint
	prevTicks     time.Duration
	transfer      [common.MaxPlayers]uint32
	transferTick  [common.MaxPlayers]time.Duration
	packetSizeCli int
	latePackets   int

	logger      *log.Logger
	loggerHdr   bool
	logBandLast time.Duration

	bandInd     int
	bandHistory [128]int

	ping        time.Duration
	pingInd     int
	pingHistory [128]int

	profInd int

	profClient     time.Duration
	profClientHist [128]int

	profServer     time.Duration
	profServerHist [128]int

	fps        int
	fpsInd     int
	fpsHistory [128]int
}

func (m *Perfmon) Toggle() {
	m.enabled = !m.enabled
}

func (m *Perfmon) LogBandwidth(s *server.Server, nets netlib.Streams) {
	ticks := platform.Ticks()
	if ticks-m.logBandLast <= time.Second {
		return
	}
	m.logBandLast = ticks

	if !m.loggerHdr {
		m.loggerHdr = true
		m.logger.Print("Player,\tBPS, Frame, Threshold, Resend Interval, Resends Per Update, Sleep Interval\n\n")
	}
	m.logger.Print("\n")
	for _, pl := range s.Players.List() {
		d := m.bandData(pl.Index())
		v4 := s.Frame()
		var bps uint32
		if pl.Index() == server.HostPlayerIndex {
			bps = m.TransferStats(nets.HostStream())
		} else {
			bps = m.TransferStats(nets.StreamByPlayerInd(pl.PlayerIndex()))
		}
		m.logger.Printf("%s, %d, %d, %d, %d, %d\n", pl.Name(), bps, v4, d.th, d.ri, d.rpu)
	}
}

type playerBandData struct {
	rpu, ri, th uint32
}

func (m *Perfmon) bandData(ind int) playerBandData {
	arr := memmap.PtrT[[3 * common.MaxPlayers]uint32](0x5D4594, 1565124)[:]
	arr = arr[3*ind : 3*(ind+1)]
	return playerBandData{
		rpu: arr[0] & 0xff,
		ri:  (arr[0] >> 8) & 0xff,
		th:  arr[1],
	}
}

func (m *Perfmon) TransferStats(conn netlib.StreamStats) uint32 {
	ticks := platform.Ticks()
	ri := conn.Raw()
	prev := m.transferTick[ri]
	if ticks < prev+time.Second {
		return m.transfer[ri]
	}
	m.transferTick[ri] = ticks
	stat := conn.TransferStats()
	m.transfer[ri] = stat
	return stat
}

func (m *Perfmon) packetSize(l *netlist.List) int {
	if !noxflags.HasGame(noxflags.GameHost) {
		return m.packetSizeCli
	}
	return l.ByInd(server.HostPlayerIndex, netlist.Kind1).Size() + l.ByInd(server.HostPlayerIndex, netlist.Kind2).Size()
}

func (m *Perfmon) startProfileClient() func() {
	start := platform.Ticks()
	return func() {
		m.profClient = platform.Ticks() - start
	}
}

func (m *Perfmon) startProfileServer() func() {
	start := platform.Ticks()
	return func() {
		m.profServer = platform.Ticks() - start
	}
}
