//go:build !server
// +build !server

package nox

/*
#include "GAME1.h"
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME3_1.h"
#include "client__system__gameloop.h"

extern unsigned int nox_client_gui_flag_1556112;
extern unsigned int nox_client_gui_flag_815132;
extern int nox_win_width;
extern int nox_win_height;
*/
import "C"
import (
	"context"
	"errors"
	"fmt"
	"image"
	"image/draw"
	"math"
	"strings"
	"unsafe"

	"nox/v1/client/input"
	"nox/v1/client/seat"
	"nox/v1/common/alloc"
	"nox/v1/common/datapath"
	"nox/v1/common/maps"
	"nox/v1/common/memmap"
	"nox/v1/common/types"
)

func drawAndPresent() {
	if C.nox_client_gui_flag_815132 != 0 {
		guiAnimationStep()
		resetEngineFlag(NOX_ENGINE_FLAG_PAUSE)
		generateMouseSparks(inpHandlerS)
	}
	if !getEngineFlag(NOX_ENGINE_FLAG_PAUSE) {
		mainloopDrawAndPresent(inpHandlerS)
	}
}

func map_download_start() {
	C.nox_xxx_gameClearAll_467DF0(1)
	C.nox_xxx_gameDownloadShowDialog_4CC770()
	nox_xxx_mapSetDownloadInProgress(true)
	nox_xxx_mapSetDownloadOK(true)
	if _, err := mapDownloadLoop(true); err != nil {
		mapsendLog.Println(err)
	}
}

func mapDownloadLoop(first bool) (bool, error) {
	if !mapDownloading() {
		if map_download_finish() == 0 {
			return true, errors.New("map download failed")
		}
		return true, nil
	}

	if C.nox_xxx_check_flag_aaa_43AF70() == 1 {
		C.sub_40D250()
		C.sub_40DF90()
	}
	nox_framerate_limit_416C70(30)
	inp := processInput()
	C.sub_43CCA0()

	if first {
		ctx, cancel := context.WithCancel(context.Background())

		hport := inferHTTPPort(clientGetServerPort())
		srv := fmt.Sprintf("%s:%d", clientGetServerHost(), hport)
		mapsendLog.Printf("checking map download API on server %q", srv)
		cli, err := maps.NewClient(ctx, srv)
		if err != nil {
			if err == maps.ErrAPIUnsupported {
				mapsendLog.Println("map API check:", err)
			} else {
				mapsendLog.Println("cannot check map API:", err)
			}
			cancel()
			mapsend.native = true
		} else {
			mapsendLog.Println("map API supported")
			errc := make(chan error, 1)
			mapsend.cancel = cancel
			mapsend.done = errc
			mapsend.native = false

			name := strings.TrimSuffix(strings.ToLower(clientGetServerMap()), maps.Ext)
			mapsendLog.Printf("download start: %q", name)
			go func() {
				defer cli.Close()
				defer close(errc)

				err := cli.DownloadMap(ctx, datapath.Path(maps.Dir), name)
				if err != nil {
					mapsendLog.Println("download failed:", err)
					errc <- err
				} else {
					mapsendLog.Println("download complete")
				}
			}()
		}
	}

	if mapsend.native {
		if first {
			nox_xxx_netRequestMap_43CA50()
		}
		if gameFrame()%30 != 0 { // TODO: shouldn't it be == 0?
			nox_xxx_netKeepAliveSocket_43CA20()
		}
	} else {
		select {
		case err := <-mapsend.done:
			nox_xxx_mapSetDownloadInProgress(false)
			if err != nil {
				nox_xxx_mapSetDownloadOK(false)
				return true, err
			}
			nox_xxx_mapSetDownloadOK(true)
			nox_xxx_guiDownloadSetPercent_4CC900(100)
			if map_download_finish() == 0 {
				return true, errors.New("map download failed")
			}
			return true, nil
		default:
		}
	}
	if !mapDownloading() {
		if map_download_finish() == 0 {
			return true, errors.New("map download failed")
		}
		return true, nil
	}

	DrawGUI()
	nox_client_drawCursorAndTooltips_477830(noxrend, inp)
	// C.nox_xxx_directDrawBlitMB_48A220() // does nothing
	nox_video_callCopyBackBuffer_4AD170()

	if !mapDownloading() {
		if map_download_finish() == 0 {
			return true, errors.New("map download failed")
		}
		return true, nil
	}
	// continue
	return false, nil
}

func mainloopDrawAndPresent(inp *input.Handler) {
	C.sub_437180()
	if C.nox_client_gui_flag_1556112 == 0 {
		DrawGUI() // Draw game windows
	}
	DrawSparks()
	if !getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) || getEngineFlag(NOX_ENGINE_FLAG_9) || C.nox_client_gui_flag_815132 != 0 {
		nox_client_drawCursorAndTooltips_477830(noxrend, inp) // Draw cursor
	}
	C.nox_client_procFade_44D9F0(1)
	maybeScreenshot()
	if !getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) || getEngineFlag(NOX_ENGINE_FLAG_9) || C.nox_client_gui_flag_815132 != 0 {
		// C.nox_xxx_directDrawBlitMB_48A220() // does nothing
		nox_video_callCopyBackBuffer_4AD170()
	}
}

func copyGamePixBuffer() *image.NRGBA {
	img := image.NewNRGBA(noxPixBuffer.img.Rect)
	draw.Draw(img, img.Rect, noxrend.pix, noxrend.pix.Rect.Min, draw.Src)
	return img
}

func DrawSparks() {
	if C.nox_client_gui_flag_815132 != 0 {
		sz := videoGetWindowSize()
		rdrP, rdrFree := alloc.Malloc(unsafe.Sizeof(C.nox_draw_viewport_t{}))
		defer rdrFree()
		rdr := (*C.nox_draw_viewport_t)(rdrP)
		rdr.x1 = 0
		rdr.y1 = 0
		rdr.x2 = C.int(sz.W)
		rdr.y2 = C.int(sz.H)
		rdr.width = C.int(sz.W)
		rdr.height = C.int(sz.H)
		C.nox_client_screenParticlesDraw_431720(rdr)
	} else {
		vp := getViewport()
		C.nox_client_screenParticlesDraw_431720(vp.C())
	}
}

func generateMouseSparks(inp *input.Handler) {
	if memmap.Uint32(0x5D4594, 816408) != 0 {
		return
	}

	mpos := inp.GetMousePos()
	// emit sparks when passing a certain distance
	const distanceSparks = 0.25
	dx := mpos.X - int(memmap.Uint32(0x5D4594, 816420))
	dy := mpos.Y - int(memmap.Uint32(0x5D4594, 816424))
	r2 := dx*dx + dy*dy
	if memmap.Uint32(0x5D4594, 816428) != 0 {
		cnt := (int)(math.Sqrt(float64(r2)) * distanceSparks)
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
	if inp.IsMousePressed(seat.MouseButtonLeft) {
		randomIntMinMax(0, 2)
		if memmap.Uint32(0x5D4594, 816416) == 0 {
			*memmap.PtrUint32(0x5D4594, 816416) = 1
			clientPlaySoundSpecial(924, 100)
			for i := explosionSparks; i > 0; i-- {
				v12 := randomIntMinMax(0, 255)
				v13 := randomIntMinMax(6, 12)
				pos := sincosTable16[v12].Mul(v13).Div(16).Add(types.Point{Y: -6})
				v24 := randomIntMinMax(2, 5)
				v16 := randomIntMinMax(2, 5)
				C.nox_client_newScreenParticle_431540(4, C.int(pos.X+mpos.X), C.int(pos.Y+mpos.Y), C.int(pos.X), C.int(pos.Y), 1, C.char(v16), C.char(v24), 2, 1)
			}
		}
	} else {
		*memmap.PtrUint32(0x5D4594, 816416) = 0
	}
}
