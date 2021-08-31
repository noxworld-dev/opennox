package main

/*
#include "cdrom.h"
#include "client__drawable__drawdb.h"
#include "client__draw__fx.h"
#include "client__draw__image.h"
#include "client__gui__guiinv.h"
#include "client__gui__guimeter.h"
#include "client__gui__guishop.h"
#include "client__gui__guispell.h"
#include "client__gui__servopts__guiserv.h"
#include "client__gui__window.h"
#include "client__io__win95__focus.h"
#include "client__network__netclint.h"
#include "client__shell__optsback.h"
#include "client__system__ctrlevnt.h"
#include "client__video__draw_common.h"
#include "client__video__sdl__draw_nogl.h"
#include "common__config.h"
#include "common__magic__speltree.h"
#include "defs.h"
#include "GAME1_1.h"
#include "GAME1_3.h"
#include "GAME1.h"
#include "GAME2_2.h"
#include "GAME2_3.h"
#include "GAME2.h"
#include "GAME3_3.h"
#include "GAME3.h"
#include "GAME4_1.h"
#include "GAME4.h"
#include "GAME5_2.h"
#include "input_common.h"
#include "input.h"
#include "movie.h"
#include "server__network__mapsend.h"
#include "server__script__builtin.h"
#include "server__script__script.h"
#include "server__xfer__savegame__savegame.h"
#include "thing.h"
#include "win.h"
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
	"os"
	"path/filepath"
	"strings"

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
