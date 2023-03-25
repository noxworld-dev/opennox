package opennox

import (
	"fmt"
	"image"
	"image/color"
	"time"

	"github.com/noxworld-dev/opennox-lib/common"
	"github.com/noxworld-dev/opennox-lib/platform"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/internal/netstr"
)

const perfmonSz = 30

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
		m.fps = int(10000 / uint64(dt))
		m.prevTicks = ticks
	}

	c.drawFPS(m)
	c.drawProfile(m)
	c.drawPing(m)
	y += 10

	frame := c.srv.Frame()
	format := c.Strings().GetStringInFile("Frame", "client.c")
	c.r.Data().SetTextColor(color.White)
	c.r.DrawString(nil, fmt.Sprintf(format, frame), image.Pt(x, y))
	y += 10

	format = c.Strings().GetStringInFile("PacketSize", "client.c")
	c.r.Data().SetTextColor(color.White)
	c.r.DrawString(nil, fmt.Sprintf(format, m.packetSize()), image.Pt(x, y))
	c.drawBandwidth(m)
	y += 10

	format = c.Strings().GetStringInFile("DrawCount", "client.c")
	c.r.Data().SetTextColor(color.White)
	c.r.DrawString(nil, fmt.Sprintf(format, c.Objs.Count), image.Pt(x, y))
	y += 10

	tsOps := *memmap.PtrUint32(0x85B3FC, 120)
	lp := m.latePackets
	format = c.Strings().GetStringInFile("LatePackets", "client.c")
	c.r.DrawString(nil, fmt.Sprintf(format, lp, tsOps), image.Pt(x, y))
	y += 10

	format = c.Strings().GetStringInFile("Latency", "client.c")
	c.r.DrawRectFilledOpaque(x+80, y, 16, 8, color.Black)
	c.r.DrawString(nil, fmt.Sprintf(format, m.ping.Milliseconds(), m.fps), image.Pt(x, y))

	y = 200
	for _, pl := range c.srv.GetPlayers() {
		var str string
		if pl.Field3680&8 != 0 {
			format = c.Strings().GetStringInFile("Muted", "client.c")
			str = fmt.Sprintf(format, pl.Name())
		} else {
			str = pl.Name()
		}
		c.r.DrawString(nil, str, image.Pt(10, y))
		d := m.bandData(pl.Index())
		var bps uint32
		if pl.Index() == common.MaxPlayers-1 {
			bps = m.TransferStats(netstr.Global.First())
			format = c.Strings().GetStringInFile("TransferStats", "client.c")
		} else {
			bps = m.TransferStats(netstr.Global.Player(pl))
			format = c.Strings().GetStringInFile("TransferStats", "client.c")
		}
		c.r.DrawString(nil, fmt.Sprintf(format, bps, d.th, d.ri, d.rpu), image.Pt(70, y))
		y += 10
	}
	m.cnt++
}

func (c *Client) drawBandwidth(m *Perfmon) {
	wsz := videoGetWindowSize()
	str := c.Strings().GetStringInFile("Bandwidth", "client.c")
	th := wsz.Y - (perfmonSz + 1) - c.r.FontHeight(nil)
	c.r.Data().SetTextColor(nox_color_white_2523948)
	c.r.DrawString(nil, str, image.Pt(0, th))
	c.r.DrawBorder(0, wsz.Y-(perfmonSz+1), wsz.X, perfmonSz+1, nox_color_gray2)
	si := m.bandInd

	cur := perfmonSz * m.packetSize() / 120
	if cur > perfmonSz {
		cur = perfmonSz
	}
	m.bandHistory[si] = cur

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

func (c *Client) drawPing(m *Perfmon) {
	wsz := videoGetWindowSize()

	th := wsz.Y - 80 - c.r.FontHeight(nil)
	str := c.Strings().GetStringInFile("Ping", "client.c")
	c.r.Data().SetTextColor(nox_color_white_2523948)
	c.r.DrawString(nil, str, image.Pt(0, th))
	c.r.DrawBorder(0, wsz.Y-80, wsz.X, perfmonSz+1, nox_color_gray2)

	si := m.pingInd
	cur := int(perfmonSz * m.ping / (500 * time.Millisecond))
	if cur > perfmonSz {
		cur = perfmonSz
	}
	m.pingHistory[si] = cur

	n := len(m.pingHistory)
	m.pingInd = (si + 1) % n
	dx := wsz.X / n
	for i := 0; i < n; i++ {
		j := si + i + 1
		v := m.pingHistory[(j+0)%n]
		var cl color.Color
		if v < 100 {
			cl = nox_color_green
		} else if v < 350 {
			cl = nox_color_yellow_2589772
		} else {
			cl = nox_color_red
		}
		p1 := image.Pt((i+0)*dx, wsz.Y-80+perfmonSz-m.pingHistory[(j+0)%n])
		p2 := image.Pt((i+1)*dx, wsz.Y-80+perfmonSz-m.pingHistory[(j+1)%n])
		c.r.DrawLine(p1, p2, cl)
	}
}

func (c *Client) drawProfile(m *Perfmon) {
	wsz := videoGetWindowSize()

	th := 2*perfmonSz - c.r.FontHeight(nil)
	str := c.Strings().GetStringInFile("CSTiming", "client.c")
	c.r.Data().SetTextColor(nox_color_white_2523948)
	c.r.DrawString(nil, fmt.Sprintf("%s: %3d / %3d",
		str, m.profClient.Milliseconds(), m.profServer.Milliseconds()), image.Pt(0, th))

	c.r.DrawBorder(0, 2*perfmonSz, wsz.X, perfmonSz+1, nox_color_gray2)
	si := m.profInd

	pcli := int(perfmonSz * m.profClient / (100 * time.Millisecond))
	if pcli > perfmonSz {
		pcli = perfmonSz
	}
	m.profClientHist[si] = pcli

	psrv := int(perfmonSz * m.profServer / (100 * time.Millisecond))
	if psrv > perfmonSz {
		psrv = perfmonSz
	}
	m.profServerHist[si] = psrv

	n := len(m.profClientHist)
	m.profInd = (si + 1) % n
	dx := wsz.X / n
	for i := 0; i < n; i++ {
		j := si + i + 1

		p1 := image.Pt((i+0)*dx, 3*perfmonSz-m.profClientHist[(j+0)%n])
		p2 := image.Pt((i+1)*dx, 3*perfmonSz-m.profClientHist[(j+1)%n])
		c.r.DrawLine(p1, p2, nox_color_blue_2650684)

		p1 = image.Pt((i+0)*dx, 3*perfmonSz-m.profServerHist[(j+0)%n])
		p2 = image.Pt((i+1)*dx, 3*perfmonSz-m.profServerHist[(j+1)%n])
		c.r.DrawLine(p1, p2, nox_color_red)
	}
}

func (c *Client) drawFPS(m *Perfmon) {
	wsz := videoGetWindowSize()

	c.r.Data().SetTextColor(nox_color_white_2523948)
	str := c.Strings().GetStringInFile("FPS", "client.c")
	c.r.DrawString(nil, fmt.Sprintf("%s: %d", str, m.fps), image.Pt(0, 0))

	th := c.r.FontHeight(nil)
	for i := 0; i < 4; i++ {
		y := th + 10*i
		p1 := image.Pt(0, y)
		p2 := image.Pt(wsz.X, y)
		c.r.DrawLine(p1, p2, nox_color_gray2)
	}
	p1 := image.Pt(0, th)
	p2 := image.Pt(0, th+perfmonSz)
	c.r.DrawLine(p1, p2, nox_color_gray2)

	p1 = image.Pt(wsz.X-1, th)
	p2 = image.Pt(wsz.X-1, th+perfmonSz)
	c.r.DrawLine(p1, p2, nox_color_gray2)

	si := m.fpsInd
	m.fpsHistory[si] = perfmonSz * m.fps / 30

	n := len(m.fpsHistory)
	m.fpsInd = (si + 1) % n
	dx := wsz.X / n
	for i := 0; i < n; i++ {
		j := si + i + 1

		var cl color.Color
		if v := m.fpsHistory[(j+0)%n]; v < 10 {
			cl = nox_color_red
		} else if v < 20 {
			cl = nox_color_yellow_2589772
		} else {
			cl = nox_color_green
		}
		p1 := image.Pt((i+0)*dx, th+perfmonSz-m.fpsHistory[(j+0)%n])
		p2 := image.Pt((i+1)*dx, th+perfmonSz-m.fpsHistory[(j+1)%n])
		c.r.DrawLine(p1, p2, cl)
	}
}
