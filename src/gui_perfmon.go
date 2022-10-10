package opennox

/*
#include <stdint.h>
#include <GAME1_3.h>
#include <GAME2.h>
#include <GAME3_3.h>
#include <GAME5_2.h>
#include <client__system__client.h>
#include <common__net_list.h>

extern uint32_t nox_perfmon_latePackets_2618900;
*/
import "C"
import (
	"fmt"
	"image"
	"image/color"
	"time"

	"github.com/noxworld-dev/opennox-lib/platform"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func (c *Client) DrawPerfmon(m *Perfmon) {
	if !m.enabled {
		return
	}
	wsz := videoGetWindowSize()
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
	C.nox_xxx_drawPing_436DF0(C.int(m.ping))
	y += 10

	frame := gameFrame()
	format := c.Strings().GetStringInFile("Frame", "client.c")
	c.r.Data().SetTextColor(color.White)
	c.r.DrawString(nil, fmt.Sprintf(format, frame), image.Pt(x, y))
	y += 10

	packSz := m.packetSize()
	format = c.Strings().GetStringInFile("PacketSize", "client.c")
	c.r.Data().SetTextColor(color.White)
	c.r.DrawString(nil, fmt.Sprintf(format, packSz), image.Pt(x, y))
	C.nox_xxx_drawBandwith_436970(C.int(packSz))
	y += 10

	dcnt := C.nox_get_drawable_count()
	format = c.Strings().GetStringInFile("DrawCount", "client.c")
	c.r.Data().SetTextColor(color.White)
	c.r.DrawString(nil, fmt.Sprintf(format, dcnt), image.Pt(x, y))
	y += 10

	oop := *memmap.PtrUint32(0x85B3FC, 120)
	lp := C.nox_perfmon_latePackets_2618900
	format = c.Strings().GetStringInFile("LatePackets", "client.c")
	c.r.DrawString(nil, fmt.Sprintf(format, lp, oop), image.Pt(x, y))
	y += 10

	format = c.Strings().GetStringInFile("Latency", "client.c")
	c.r.DrawRectFilledOpaque(x+80, y, 16, 8, color.Black)
	c.r.DrawString(nil, fmt.Sprintf(format, m.ping, m.fps), image.Pt(x, y))

	y = 200
	for _, pl := range noxServer.getPlayers() {
		var str string
		if pl.field_3680&8 != 0 {
			format = c.Strings().GetStringInFile("Muted", "client.c")
			str = fmt.Sprintf(format, pl.Name())
		} else {
			str = pl.Name()
		}
		c.r.DrawString(nil, str, image.Pt(10, y))
		d := m.bandData(pl.Index())
		var bps uint32
		if pl.Index() == noxMaxPlayers-1 {
			bps = m.TransferStats(0)
			format = c.Strings().GetStringInFile("TransferStats", "client.c")
		} else {
			bps = m.TransferStats(pl.Index() + 1)
			format = c.Strings().GetStringInFile("TransferStats", "client.c")
		}
		c.r.DrawString(nil, fmt.Sprintf(format, bps, d.th, d.ri, d.rpu), image.Pt(70, y))
		y += 10
	}
	m.cnt++
}
