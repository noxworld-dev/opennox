package opennox

/*
#include <stdint.h>

int sub_436AA0(int a1);
int nox_xxx_drawTimingMB_436C40();
int nox_xxx_drawPing_436DF0(int a1);

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
	c.drawBandwidth(m, packSz)
	y += 10

	format = c.Strings().GetStringInFile("DrawCount", "client.c")
	c.r.Data().SetTextColor(color.White)
	c.r.DrawString(nil, fmt.Sprintf(format, drawableCount()), image.Pt(x, y))
	y += 10

	tsOps := *memmap.PtrUint32(0x85B3FC, 120)
	lp := int(C.nox_perfmon_latePackets_2618900)
	format = c.Strings().GetStringInFile("LatePackets", "client.c")
	c.r.DrawString(nil, fmt.Sprintf(format, lp, tsOps), image.Pt(x, y))
	y += 10

	format = c.Strings().GetStringInFile("Latency", "client.c")
	c.r.DrawRectFilledOpaque(x+80, y, 16, 8, color.Black)
	c.r.DrawString(nil, fmt.Sprintf(format, m.ping, m.fps), image.Pt(x, y))

	y = 200
	for _, pl := range c.srv.getPlayers() {
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

func (c *Client) drawBandwidth(m *Perfmon, psz int) {
	wsz := videoGetWindowSize()
	str := c.Strings().GetStringInFile("Bandwidth", "C:\\NoxPost\\src\\client\\System\\client.c")
	th := wsz.Y - 31 - c.r.FontHeight(nil)
	c.r.Data().SetTextColor(nox_color_white_2523948)
	c.r.DrawString(nil, str, image.Pt(0, th))
	c.r.DrawBorder(0, wsz.Y-31, wsz.X, 31, nox_color_gray2)
	si := m.bandInd
	m.bandHistory[si] = psz / 4
	if psz/4 > 30 {
		m.bandHistory[si] = 30
	}
	n := len(m.bandHistory)
	m.bandInd = (si + 1) % n

	dx := wsz.X / n
	for i := 0; i < n; i++ {
		j := si + i + 1
		p1 := image.Pt((i+0)*dx, wsz.Y-1-m.bandHistory[(j+0)%n])
		p2 := image.Pt((i+1)*dx, wsz.Y-1-m.bandHistory[(j+1)%n])
		c.r.DrawLine(p1, p2, nox_color_yellow_2589772)
	}
}
