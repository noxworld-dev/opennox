package opennox

import (
	"time"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/log"
	"github.com/noxworld-dev/opennox-lib/platform"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/internal/netstr"
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
	transfer      [noxMaxPlayers]uint32
	transferTick  [noxMaxPlayers]time.Duration
	packetSizeCli int

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

func (m *Perfmon) LogBandwidth() {
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
	for _, pl := range noxServer.getPlayers() {
		d := m.bandData(pl.Index())
		v4 := gameFrame()
		var bps uint32
		if pl.Index() == noxMaxPlayers-1 {
			bps = noxPerfmon.TransferStats(0)
		} else {
			bps = noxPerfmon.TransferStats(pl.Index() + 1)
		}
		m.logger.Printf("%s, %d, %d, %d, %d, %d\n", pl.Name(), bps, v4, d.th, d.ri, d.rpu)
	}
}

type playerBandData struct {
	rpu, ri, th uint32
}

func (m *Perfmon) bandData(ind int) playerBandData {
	arr := unsafe.Slice((*uint32)(memmap.PtrOff(0x5D4594, 1565124)), 3*noxMaxPlayers)
	arr = arr[3*ind : 3*(ind+1)]
	return playerBandData{
		rpu: arr[0] & 0xff,
		ri:  (arr[0] >> 8) & 0xff,
		th:  arr[1],
	}
}

func (m *Perfmon) TransferStats(ind int) uint32 {
	ticks := platform.Ticks()
	prev := m.transferTick[ind]
	if ticks < prev+time.Second {
		return m.transfer[ind]
	}
	m.transferTick[ind] = ticks
	stat := netstr.TransferStats(ind)
	m.transfer[ind] = stat
	return stat
}

func (m *Perfmon) packetSize() int {
	if !noxflags.HasGame(noxflags.GameHost) {
		return m.packetSizeCli
	}
	return netList(noxMaxPlayers-1, 1).Size() + netList(noxMaxPlayers-1, 2).Size()
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
