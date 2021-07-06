package main

/*
#include "proto.h"
int map_download_finish();
void nox_xxx_cliCancelMapDownload_native_4ABA90();
int  nox_xxx_mapDownloadStart_native_4ABAD0(char* a1, unsigned int a2);
extern unsigned int nox_xxx_gameDownloadInProgress_587000_173328;
extern unsigned int nox_xxx_mapDownloadOK_587000_173332;
extern unsigned int dword_5d4594_2618912;
*/
import "C"
import (
	"context"
	"errors"
	"os"
	"path/filepath"
	"strings"

	"nox/v1/common/datapath"
	"nox/v1/common/log"
	"nox/v1/common/maps"
)

var (
	mapsendLog = log.New("mapsend")
	mapsend    struct {
		cancel func()
		done   <-chan error
		native bool
		srv    *maps.Server
	}
)

func init() {
	wd, _ := os.Getwd()
	mapsend.srv = maps.NewServer(filepath.Join(wd, maps.Dir))
	mapsend.srv.RegisterOnMux(gameMux)
}

func mapDownloading() bool {
	return C.nox_xxx_gameDownloadInProgress_587000_173328 != 0
}

func nox_xxx_mapSetDownloadInProgress_4AB560(v bool) {
	C.nox_xxx_gameDownloadInProgress_587000_173328 = C.uint(bool2int(v))
}

func nox_xxx_mapSetDownloadOK_4AB570(v bool) {
	C.nox_xxx_mapDownloadOK_587000_173332 = C.uint(bool2int(v))
}

//export nox_xxx_mapDownloadStart_4ABAD0
func nox_xxx_mapDownloadStart_4ABAD0(a1 *C.char, a2 C.uint) C.int {
	name := strings.TrimSuffix(strings.ToLower(GoString(a1)), maps.Ext)
	mapsendLog.Printf("download start: %q, %d", name, int(a2))
	mapsend.native = true
	return C.nox_xxx_mapDownloadStart_native_4ABAD0(a1, a2)
}

//export nox_xxx_cliCancelMapDownload_4ABA90
func nox_xxx_cliCancelMapDownload_4ABA90() {
	mapsendLog.Printf("map download cancelled")
	if mapsend.native {
		C.nox_xxx_cliCancelMapDownload_native_4ABA90()
		return
	}
	nox_xxx_mapSetDownloadInProgress_4AB560(false)
	if mapsend.cancel != nil {
		mapsend.cancel()
		mapsend.cancel = nil
		if err := <-mapsend.done; err != nil && err != context.Canceled {
			mapsendLog.Println(err)
		}
		mapsend.done = nil
	}
}

func clientGetServerMap() string {
	if nox_xxx_gameIsNotMultiplayer_4DB250() {
		return nox_xxx_mapFilenameGetSolo_4DB260()
	}
	return nox_server_currentMapGetFilename_409B30()
}

func map_download_start() {
	C.nox_xxx_gameClearAll_467DF0(1)
	C.nox_xxx_gameDownloadShowDialog_4CC770()
	nox_xxx_mapSetDownloadInProgress_4AB560(true)
	nox_xxx_mapSetDownloadOK_4AB570(true)
	if _, err := mapDownloadLoop(true); err != nil {
		mapsendLog.Println(err)
	}
}

func mapDownloadLoop(first bool) (bool, error) {
	if !mapDownloading() {
		if C.map_download_finish() == 0 {
			return true, errors.New("map download failed")
		}
		return true, nil
	}

	nox_framerate_limit_416C70(30)
	inpHandler.Tick()
	nox_client_processMouseInput_4308A0(noxInp, true)
	nox_xxx_cursorUpdate_46B740(noxInp)
	if C.nox_xxx_check_flag_aaa_43AF70() == 1 {
		C.sub_40D250()
		C.sub_40DF90()
	}
	mainloopKeysUpdate()
	C.sub_43CCA0()

	if first {
		ctx, cancel := context.WithCancel(context.Background())

		srv := clientGetServerHost()
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
			C.nox_xxx_netRequestMap_43CA50()
		}
		if gameFrame()%30 != 0 { // TODO: shouldn't it be == 0?
			C.nox_xxx_netKeepAliveSocket_43CA20()
		}
	} else {
		select {
		case err := <-mapsend.done:
			nox_xxx_mapSetDownloadInProgress_4AB560(false)
			if err != nil {
				nox_xxx_mapSetDownloadOK_4AB570(false)
				return true, err
			}
			nox_xxx_mapSetDownloadOK_4AB570(true)
			C.nox_xxx_guiDownloadSetPercent_4CC900(100)
			if C.map_download_finish() == 0 {
				return true, errors.New("map download failed")
			}
			return true, nil
		default:
		}
	}
	if !mapDownloading() {
		if C.map_download_finish() == 0 {
			return true, errors.New("map download failed")
		}
		return true, nil
	}

	DrawGUI()
	nox_client_drawCursorAndTooltips_477830()
	// C.nox_xxx_directDrawBlitMB_48A220() // does nothing
	nox_video_callCopyBackBuffer_4AD170()

	if !mapDownloading() {
		if C.map_download_finish() == 0 {
			return true, errors.New("map download failed")
		}
		return true, nil
	}
	// continue
	return false, nil
}
