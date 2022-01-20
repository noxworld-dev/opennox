package nox

/*
int nox_xxx_guiDownloadAbort_4CC830(int a1, int a2, int a3, int a4);
int nox_xxx_guiDownloadProc_4CC890(int a1, int a2, int* a3, int a4);
*/
import "C"
import (
	"context"
	"path/filepath"
	"strings"
	"unsafe"

	"nox/v1/common/datapath"
	noxflags "nox/v1/common/flags"
	"nox/v1/common/keybind"
	"nox/v1/common/log"
	"nox/v1/common/maps"
	"nox/v1/common/memmap"
	"nox/v1/common/types"
)

var (
	winDownload *Window
	mapsendLog  = log.New("mapsend")
	mapsend     struct {
		inProgress bool // 	nox_xxx_gameDownloadInProgress_587000_173328
		downloadOK bool // nox_xxx_mapDownloadOK_587000_173332
		cancel     func()
		done       <-chan error
		native     bool
		srv        *maps.Server
	}
	mapsendNative *maps.NativeDownloader
)

func init() {
	registerOnDataPathSet(func() {
		mapsend.srv = maps.NewServer(datapath.Maps())
		mapsend.srv.RegisterOnMux(noxServer.http.mux)
		mapsendNative = maps.NewNativeDownloader(datapath.Maps())
	})
}

func mapDownloading() bool {
	return mapsend.inProgress
}

func nox_xxx_mapSetDownloadInProgress(v bool) { // nox_xxx_mapSetDownloadInProgress_4AB560
	mapsend.inProgress = v
}

func nox_xxx_mapSetDownloadOK(v bool) {
	mapsend.downloadOK = v
}

//export nox_xxx_mapSetDownloadInProgress_4AB560
func nox_xxx_mapSetDownloadInProgress_4AB560(v C.int) {
	nox_xxx_mapSetDownloadInProgress(v != 0)
}

//export nox_xxx_mapSetDownloadOK_4AB570
func nox_xxx_mapSetDownloadOK_4AB570(v C.int) {
	nox_xxx_mapSetDownloadOK(v != 0)
}

//export nox_xxx_mapDeleteFile_4AB720
func nox_xxx_mapDeleteFile_4AB720() {
	mapsendNative.CancelAndDelete()
	nox_xxx_mapSetDownloadInProgress_4AB560(0)
	nox_xxx_mapSetDownloadOK(true)
}

func nox_xxx_cliCancelMapDownload_native_4ABA90() {
	if mapsendNative.DownloadOK() {
		nox_xxx_cliSendCancelMap_43CAB0()
		mapsendNative.CancelAndCleanup()
	}
}

func nox_xxx_mapDownloadStart_native_4ABAD0(name string, sz uint) int {
	if name == "" || sz <= 0 {
		return 0
	}
	mapsendNative.Reset()
	var (
		fpath string
		mdir  string
	)
	if strings.ContainsAny(name, "\\/") {
		name = strings.ReplaceAll(name, "\\", string(filepath.Separator))
		i := strings.IndexByte(name, '/')
		j := strings.IndexByte(name, '.')
		if i <= 0 || j <= 0 {
			return 0
		}
		mname := name[i+1 : j]
		mdir = datapath.Maps(mname)
		fpath = filepath.Join(mdir, mname+".nxz")
		noxServer.nox_xxx_gameSetMapPath_409D70(name[i+1:])
	} else {
		noxServer.nox_xxx_gameSetMapPath_409D70(name)
		mname := noxServer.getServerMap()
		mdir = datapath.Maps(mname)
		fpath = filepath.Join(mdir, mname+".nxz")
	}
	if err := mapsendNative.Start(fpath, sz); err != nil {
		mapsendLog.Println(err)
		return 0
	}
	return 1
}

//export nox_xxx_mapDownloadStart_4ABAD0
func nox_xxx_mapDownloadStart_4ABAD0(a1 *C.char, a2 C.uint) C.int {
	name := strings.TrimSuffix(strings.ToLower(GoString(a1)), maps.Ext)
	mapsendLog.Printf("download start: %q, %d", name, int(a2))
	mapsend.native = true
	return C.int(nox_xxx_mapDownloadStart_native_4ABAD0(name, uint(a2)))
}

func nox_xxx_cliCancelMapDownload_4ABA90() {
	mapsendLog.Printf("map download cancelled")
	if mapsend.native {
		nox_xxx_cliCancelMapDownload_native_4ABA90()
		return
	}
	nox_xxx_mapSetDownloadInProgress(false)
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
	return noxServer.nox_server_currentMapGetFilename_409B30()
}

//export nox_xxx_netMapDownloadPart_4AB7C0
func nox_xxx_netMapDownloadPart_4AB7C0(a1 C.ushort, a2p unsafe.Pointer, a3 C.uint) {
	if a2p == nil || a3 == 0 {
		return
	}
	ind := uint(a1)
	data := unsafe.Slice((*byte)(a2p), int(a3))
	mapsendNative.WritePart(ind, data)

	if mapsendNative.Complete() {
		mapsendNative.Reset()
		nox_xxx_mapSetDownloadInProgress_4AB560(0)
		nox_xxx_mapSetDownloadOK(true)
		nox_xxx_guiDownloadSetPercent_4CC900(100)
		nox_xxx_netMapReceived_43CA80()
	} else {
		nox_xxx_guiDownloadSetPercent_4CC900(int(mapsendNative.Progress() * 100.0))
	}
}

//export nox_xxx_gameDownloadShowDialog_4CC770
func nox_xxx_gameDownloadShowDialog_4CC770() C.int {
	winDownload = newWindowFromFile("mapdnld.wnd", nox_xxx_guiDownloadProc_4CC890)
	winDownload.SetAllFuncs(nox_xxx_guiDownloadAbort_4CC830, nil, nil)
	mode := videoGetGameMode()
	v3, v4 := mode.W, mode.H
	max := videoGetMaxSize()
	v5, v6 := max.W, max.H
	v0 := v3
	if v3 > v5 {
		v0 = v5
		v3 = v5
	}
	v1 := v4
	if v4 > v6 {
		v1 = v6
		v4 = v6
	}
	winDownload.SetPos(types.Point{X: (v0 - 1024) / 2, Y: (v1 - 768) / 2})
	nox_xxx_wndShowModalMB(winDownload)
	return 1
}

func nox_xxx_guiDownloadAbort_4CC830(a1 *Window, ev WindowEvent) WindowEventResp {
	ekey, ok := ev.(WindowKeyPress)
	if !ok {
		return nil
	}
	if ekey.Key != keybind.KeyEsc {
		return nil
	}
	if ekey.Pressed {
		clientPlaySoundSpecial(231, 100)
		nox_xxx_guiDownloadClose_4CC930()
		noxServer.nox_xxx_gameSetMapPath_409D70(GoString((*C.char)(memmap.PtrOff(0x5D4594, 1522936))))
		nox_xxx_cliCancelMapDownload_4ABA90()
		nox_xxx_mapSetDownloadInProgress_4AB560(0)
		nox_xxx_mapSetDownloadOK_4AB570(0)
		noxflags.UnsetGame(noxflags.GameFlag21 | noxflags.GameFlag24)
	}
	return RawEventResp(1)
}

func nox_xxx_guiDownloadProc_4CC890(a1 *Window, ev WindowEvent) WindowEventResp {
	a2, a3, _ := ev.EventArgsC()
	if a2 != 0x4007 {
		return nil
	}
	v3 := asWindowP(unsafe.Pointer(a3)).ID()
	clientPlaySoundSpecial(766, 100)
	if v3 != 1601 {
		return nil
	}
	nox_xxx_guiDownloadClose_4CC930()
	nox_xxx_cliCancelMapDownload_4ABA90()
	noxServer.nox_xxx_gameSetMapPath_409D70(GoString((*C.char)(memmap.PtrOff(0x5D4594, 1522940))))
	nox_xxx_mapSetDownloadInProgress_4AB560(0)
	nox_xxx_mapSetDownloadOK_4AB570(0)
	noxflags.UnsetGame(noxflags.GameFlag21 | noxflags.GameFlag24)
	return RawEventResp(1)
}

func nox_xxx_guiDownloadSetPercent_4CC900(a1 int) int {
	v1 := winDownload.ChildByID(1603)
	return eventRespInt(v1.Func94(asWindowEvent(0x4020, uintptr(a1), 0)))
}

func nox_xxx_guiDownloadClose_4CC930() {
	if winDownload != nil {
		winDownload.Destroy()
	}
	winDownload = nil
}
