//go:build !server

package opennox

/*
#include "GAME1.h"
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME2_3.h"
#include "GAME3.h"
#include "GAME3_1.h"
#include "GAME3_3.h"
#include "GAME5.h"
#include "GAME5_2.h"

extern unsigned int nox_client_gui_flag_1556112;
extern unsigned int dword_5d4594_2650652;
*/
import "C"
import (
	"context"
	"encoding/binary"
	"errors"
	"fmt"
	"image"
	"math"
	"strings"

	"github.com/noxworld-dev/opennox-lib/client/seat"
	"github.com/noxworld-dev/opennox-lib/common"
	"github.com/noxworld-dev/opennox-lib/datapath"
	"github.com/noxworld-dev/opennox-lib/maps"
	"github.com/noxworld-dev/opennox-lib/noxnet"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/internal/netlist"
	"github.com/noxworld-dev/opennox/v1/internal/netstr"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	ticks815724 uint64
)

func (c *Client) drawAndPresent() {
	if nox_client_gui_flag_815132 != 0 {
		guiAnimationStep()
		noxflags.UnsetEngine(noxflags.EnginePause)
		c.generateMouseSparks()
	}
	if !noxflags.HasEngine(noxflags.EnginePause) {
		c.mainloopDrawAndPresent()
	}
}

func (c *Client) map_download_start() {
	C.nox_xxx_gameClearAll_467DF0(1)
	c.ShowMapDownload()
	c.mapsend.setDownloading(true)
	c.mapsend.setDownloadOK(true)
	if _, err := c.mapDownloadLoop(true); err != nil {
		c.mapsend.log.Println(err)
	}
}

func (c *Client) mapDownloadLoop(first bool) (bool, error) {
	if !c.mapsend.Downloading() {
		if c.map_download_finish() == 0 {
			return true, errors.New("map download failed")
		}
		return true, nil
	}

	c.srv.SetRateLimit(30)
	c.processInput()
	sub_43CCA0()

	if first {
		ctx, cancel := context.WithCancel(context.Background())

		hport := server.InferHTTPPort(clientGetServerPort())
		srv := fmt.Sprintf("%s:%d", clientGetServerHost(), hport)
		c.mapsend.log.Printf("checking map download API on server %q", srv)
		cli, err := maps.NewClient(ctx, srv)
		if err != nil {
			if err == maps.ErrAPIUnsupported {
				c.mapsend.log.Println("map API check:", err)
			} else {
				c.mapsend.log.Println("cannot check map API:", err)
			}
			cancel()
			c.mapsend.native = true
		} else {
			c.mapsend.log.Println("map API supported")
			errc := make(chan error, 1)
			c.mapsend.cancel = cancel
			c.mapsend.done = errc
			c.mapsend.native = false

			name := strings.TrimSuffix(strings.ToLower(clientGetServerMap()), maps.Ext)
			c.mapsend.log.Printf("download start (http): %q", name)
			go func() {
				defer cli.Close()
				defer close(errc)

				err := cli.DownloadMap(ctx, datapath.Data(maps.Dir), name)
				if err != nil {
					c.mapsend.log.Println("download failed:", err)
					errc <- err
				} else {
					c.mapsend.log.Println("download complete")
				}
			}()
		}
	}

	if c.mapsend.native {
		if first {
			nox_xxx_netRequestMap_43CA50()
		}
		if c.srv.Frame()%30 != 0 { // TODO: shouldn't it be == 0?
			nox_xxx_netKeepAliveSocket_43CA20()
		}
	} else {
		select {
		case err := <-c.mapsend.done:
			c.mapsend.setDownloading(false)
			if err != nil {
				c.mapsend.setDownloadOK(false)
				return true, err
			}
			c.mapsend.setDownloadOK(true)
			c.mapsend.setProgress(100)
			if c.map_download_finish() == 0 {
				return true, errors.New("map download failed")
			}
			return true, nil
		default:
		}
	}
	if !c.mapsend.Downloading() {
		if c.map_download_finish() == 0 {
			return true, errors.New("map download failed")
		}
		return true, nil
	}

	c.GUI.Draw()
	c.nox_client_drawCursorAndTooltips_477830()
	c.copyPixBuffer()

	if !c.mapsend.Downloading() {
		if c.map_download_finish() == 0 {
			return true, errors.New("map download failed")
		}
		return true, nil
	}
	// continue
	return false, nil
}

func (c *Client) mainloopDrawAndPresent() {
	sub_437180()
	if C.nox_client_gui_flag_1556112 == 0 {
		c.GUI.Draw() // Draw game windows
	}
	c.DrawSparks()
	if !noxflags.HasEngine(noxflags.EngineNoRendering) || noxflags.HasEngine(noxflags.EngineFlag9) || nox_client_gui_flag_815132 != 0 {
		c.nox_client_drawCursorAndTooltips_477830() // Draw cursor
	}
	c.r.DrawFade(true)
	c.maybeScreenshot()
	if !noxflags.HasEngine(noxflags.EngineNoRendering) || noxflags.HasEngine(noxflags.EngineFlag9) || nox_client_gui_flag_815132 != 0 {
		c.copyPixBuffer()
	}
}

func (c *Client) DrawSparks() {
	if nox_client_gui_flag_815132 != 0 {
		sz := videoGetWindowSize()
		rdr, rdrFree := alloc.New(nox_draw_viewport_t{})
		defer rdrFree()
		rdr.x1 = 0
		rdr.y1 = 0
		rdr.x2 = C.int(sz.X)
		rdr.y2 = C.int(sz.Y)
		rdr.width = C.int(sz.X)
		rdr.height = C.int(sz.Y)
		C.nox_client_screenParticlesDraw_431720(rdr)
	} else {
		vp := c.Viewport()
		C.nox_client_screenParticlesDraw_431720((*nox_draw_viewport_t)(vp.C()))
	}
}

func (c *Client) generateMouseSparks() {
	if memmap.Uint32(0x5D4594, 816408) != 0 {
		return
	}

	mpos := c.Inp.GetMousePos()
	// emit sparks when passing a certain distance
	const distanceSparks = 0.25
	dx := mpos.X - int(memmap.Uint32(0x5D4594, 816420))
	dy := mpos.Y - int(memmap.Uint32(0x5D4594, 816424))
	r2 := dx*dx + dy*dy
	if memmap.Uint32(0x5D4594, 816428) != 0 {
		cnt := int(math.Sqrt(float64(r2)) * distanceSparks)
		for i := cnt; i > 0; i-- {
			v6 := randomIntMinMax(0, 100)
			v7 := int(memmap.Uint32(0x5D4594, 816420)) + dx*v6/100
			v9 := int(memmap.Uint32(0x5D4594, 816424)) + dy*v6/100
			v23 := randomIntMinMax(2, 5)
			v22 := randomIntMinMax(2, 5)
			v21 := randomIntMinMax(-7, 2)
			v10 := randomIntMinMax(-5, 5)
			C.nox_client_newScreenParticle_431540(4, C.int(v7), C.int(v9), C.int(v10), C.int(v21), 1, C.char(v22), C.char(v23), 2, 1)
		}
		if r2 < 10 {
			*memmap.PtrUint32(0x5D4594, 816428) = 0
		}
		*memmap.PtrUint32(0x5D4594, 816420) = uint32(mpos.X)
		*memmap.PtrUint32(0x5D4594, 816424) = uint32(mpos.Y)
	} else if r2 > 64 {
		*memmap.PtrUint32(0x5D4594, 816428) = 1
	}
	// explode with sparks when clicking
	const explosionSparks = 75
	if c.Inp.IsMousePressed(seat.MouseButtonLeft) {
		randomIntMinMax(0, 2)
		if memmap.Uint32(0x5D4594, 816416) == 0 {
			*memmap.PtrUint32(0x5D4594, 816416) = 1
			clientPlaySoundSpecial(sound.SoundShellMouseBoom, 100)
			for i := explosionSparks; i > 0; i-- {
				v12 := randomIntMinMax(0, 255)
				v13 := randomIntMinMax(6, 12)
				pos := sincosTable16[v12].Mul(v13).Div(16).Add(image.Point{Y: -6})
				v24 := randomIntMinMax(2, 5)
				v16 := randomIntMinMax(2, 5)
				C.nox_client_newScreenParticle_431540(4, C.int(pos.X+mpos.X), C.int(pos.Y+mpos.Y), C.int(pos.X), C.int(pos.Y), 1, C.char(v16), C.char(v24), 2, 1)
			}
		}
	} else {
		*memmap.PtrUint32(0x5D4594, 816416) = 0
	}
}

func sub_43CCA0() {
	C.nox_xxx_spriteDeleteSomeList_49C4B0()
	start := noxServer.Frame()
	nox_xxx_servNetInitialPackets_552A80(int(nox_xxx_netGet_43C750()), 1)
	if start != noxServer.Frame() && C.dword_5d4594_2650652 == 1 && !noxflags.HasGame(noxflags.GameHost) {
		if v1 := C.sub_40A710(1); C.sub_43C790() > v1 {
			C.sub_43CEB0()
			v2 := memmap.Uint64(0x5D4594, 815740) + memmap.Uint64(0x587000, 91880)/uint64(C.sub_43C790())
			if platformTicks() >= v2 {
				buf, free := alloc.Make([]byte{}, 8) // TODO: check if we need extra space
				defer free()
				buf[0] = byte(noxnet.MSG_FULL_TIMESTAMP)
				binary.LittleEndian.PutUint32(buf[1:], noxServer.Frame()+1)
				noxClient.nox_xxx_netOnPacketRecvCli48EA70(common.MaxPlayers-1, buf[:5])
			}
		}
	}

	if dt := platformTicks() - ticks815724; dt >= 2000 {
		ticks815724 = platformTicks()
		netstr.Sub552E70(int(nox_xxx_netGet_43C750()))
	}
	if !noxflags.HasGame(noxflags.GameHost) {
		C.nox_xxx_netImportant_4E5770(0x1F, 0)
	}
	nox_xxx_netSendBySock_40EE10(int(nox_xxx_netGet_43C750()), common.MaxPlayers-1, netlist.Kind0)
	netstr.MaybeSendAll()
	if lastCliHandlePackets == 0 {
		return
	}

	if dt := platformTicks() - lastCliHandlePackets; dt > 2000 && !dword_5d4594_815704 {
		dword_5d4594_815704 = true
		C.sub_4AB4A0(1)
		ticks815732 = platformTicks()
	}
	if lastCliHandlePackets == 0 {
		return
	}

	if dt := platformTicks() - lastCliHandlePackets; dt <= 20000 || dword_5d4594_815708 {
		return
	}

	if dt := platformTicks() - ticks815732; dt > 20000 {
		sub_43CF70()
	}
}
