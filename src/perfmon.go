package opennox

/*
#include <stdint.h>
#include <GAME1_3.h>
#include <GAME2.h>
#include <GAME3_3.h>
#include <GAME5_2.h>
#include <client__system__client.h>
#include <common__net_list.h>

extern uint32_t nox_perfmon_ping_2614264;
extern uint32_t nox_perfmon_latePackets_2618900;
*/
import "C"
import (
	"fmt"
	"image"
	"image/color"
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
	fps           uint64
	prevTicks     time.Duration
	transfer      [noxMaxPlayers]uint32
	transferTick  [noxMaxPlayers]time.Duration
	packetSizeCli int

	logger      *log.Logger
	loggerHdr   bool
	logBandLast time.Duration
}

func (m *Perfmon) Toggle() {
	m.enabled = !m.enabled
}

func (m *Perfmon) Draw(r *NoxRender, wsz image.Point) {
	if !m.enabled {
		return
	}
	x := wsz.X - 177
	y := wsz.Y - 80
	if m.cnt >= m.nextCnt {
		m.nextCnt = m.cnt + 10
		ticks := platform.Ticks()
		dt := (ticks - m.prevTicks) / time.Millisecond
		m.fps = 10000 / uint64(dt)
		m.prevTicks = ticks
	}

	C.sub_436AA0(C.int(m.fps))
	C.nox_xxx_drawTimingMB_436C40()
	C.nox_xxx_drawPing_436DF0(C.int(C.nox_perfmon_ping_2614264))
	y += 10

	frame := gameFrame()
	format := strMan.GetStringInFile("Frame", "client.c")
	r.Data().SetTextColor(color.White)
	r.DrawString(nil, fmt.Sprintf(format, frame), image.Pt(x, y))
	y += 10

	packSz := m.packetSize()
	format = strMan.GetStringInFile("PacketSize", "client.c")
	r.Data().SetTextColor(color.White)
	r.DrawString(nil, fmt.Sprintf(format, packSz), image.Pt(x, y))
	C.nox_xxx_drawBandwith_436970(C.int(packSz))
	y += 10

	dcnt := C.nox_get_drawable_count()
	format = strMan.GetStringInFile("DrawCount", "client.c")
	r.Data().SetTextColor(color.White)
	r.DrawString(nil, fmt.Sprintf(format, dcnt), image.Pt(x, y))
	y += 10

	oop := *memmap.PtrUint32(0x85B3FC, 120)
	lp := C.nox_perfmon_latePackets_2618900
	format = strMan.GetStringInFile("LatePackets", "client.c")
	r.DrawString(nil, fmt.Sprintf(format, lp, oop), image.Pt(x, y))
	y += 10

	latency := C.nox_perfmon_ping_2614264
	format = strMan.GetStringInFile("Latency", "client.c")
	r.DrawRectFilledOpaque(x+80, y, 16, 8, color.Black)
	r.DrawString(nil, fmt.Sprintf(format, latency, m.fps), image.Pt(x, y))

	y = 200
	for _, pl := range noxServer.getPlayers() {
		var str string
		if pl.field_3680&8 != 0 {
			format = strMan.GetStringInFile("Muted", "client.c")
			str = fmt.Sprintf(format, pl.Name())
		} else {
			str = pl.Name()
		}
		r.DrawString(nil, str, image.Pt(10, y))
		d := m.bandData(pl.Index())
		var bps uint32
		if pl.Index() == noxMaxPlayers-1 {
			bps = m.TransferStats(0)
			format = strMan.GetStringInFile("TransferStats", "client.c")
		} else {
			bps = m.TransferStats(pl.Index() + 1)
			format = strMan.GetStringInFile("TransferStats", "client.c")
		}
		r.DrawString(nil, fmt.Sprintf(format, bps, d.th, d.ri, d.rpu), image.Pt(70, y))
		y += 10
	}
	m.cnt++
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
