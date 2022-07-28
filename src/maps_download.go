package opennox

/*
 */
import "C"
import (
	"context"
	"errors"
	"fmt"
	"image"
	"path/filepath"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/client/keybind"
	"github.com/noxworld-dev/opennox-lib/datapath"
	"github.com/noxworld-dev/opennox-lib/log"
	"github.com/noxworld-dev/opennox-lib/maps"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/common/sound"
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

func nox_xxx_mapSetDownloadInProgress(v bool) {
	mapsend.inProgress = v
}

func nox_xxx_mapSetDownloadOK(v bool) {
	mapsend.downloadOK = v
}

func nox_xxx_mapDeleteFile_4AB720() {
	mapsendLog.Println("delete downloaded map")
	mapsendNative.CancelAndDelete()
	nox_xxx_mapSetDownloadInProgress(false)
	nox_xxx_mapSetDownloadOK(true)
}

func nox_xxx_cliCancelMapDownload_native_4ABA90() {
	if mapsendNative.DownloadOK() {
		nox_xxx_cliSendCancelMap_43CAB0()
		mapsendNative.CancelAndCleanup()
	}
}

func nox_xxx_mapDownloadStart_native_4ABAD0(name string, sz uint) error {
	if name == "" {
		return errors.New("empty name")
	} else if sz <= 0 {
		return errors.New("invalid size")
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
			return fmt.Errorf("unexpected map name: %q", name)
		}
		mname := name[i+1 : j]
		mdir = datapath.Maps(mname)
		fpath = filepath.Join(mdir, mname+".nxz")
		noxServer.nox_xxx_gameSetMapPath_409D70(name[i+1:])
	} else {
		noxServer.nox_xxx_gameSetMapPath_409D70(name)
		mname := strings.TrimSuffix(name, filepath.Ext(name))
		mdir = datapath.Maps(mname)
		fpath = filepath.Join(mdir, mname+".nxz")
	}
	mapsendLog.Println("downloading map to:", fpath)
	if err := mapsendNative.Start(fpath, sz); err != nil {
		return err
	}
	return nil
}

//export nox_client_onMapDownloadStart
func nox_client_onMapDownloadStart(a1 *C.char, a2 C.uint) {
	name := strings.TrimSuffix(strings.ToLower(GoString(a1)), maps.Ext)
	mapsendLog.Printf("download start (native): %q, %d", name, int(a2))
	mapsend.native = true
	if err := nox_xxx_mapDownloadStart_native_4ABAD0(name, uint(a2)); err != nil {
		mapsendLog.Println("download start failed:", err)
		nox_xxx_cliSendCancelMap_43CAB0()
		nox_xxx_mapSetDownloadInProgress(false)
		nox_xxx_mapSetDownloadOK(false)
	}
}

//export nox_client_onMapDownloadPart
func nox_client_onMapDownloadPart(a1 C.ushort, a2p unsafe.Pointer, a3 C.uint) {
	if a2p == nil || a3 == 0 {
		return
	}
	ind := uint(a1)
	data := unsafe.Slice((*byte)(a2p), int(a3))
	mapsendNative.WritePart(ind, data)

	if mapsendNative.Complete() {
		mapsendNative.Reset() // closes the map file
		nox_xxx_mapSetDownloadInProgress(false)
		nox_xxx_mapSetDownloadOK(true)
		nox_xxx_guiDownloadSetPercent_4CC900(100)
		nox_xxx_netMapReceived_43CA80()
	} else {
		nox_xxx_guiDownloadSetPercent_4CC900(int(mapsendNative.Progress() * 100.0))
	}
}

//export nox_client_onMapDownloadAbort
func nox_client_onMapDownloadAbort() {
	mapsendLog.Printf("download aborted by the server")
	nox_xxx_mapDeleteFile_4AB720()
	nox_xxx_mapSetDownloadInProgress(false)
	nox_xxx_mapSetDownloadOK(false)
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

func nox_xxx_gameDownloadShowDialog_4CC770() {
	winDownload = newWindowFromFile("mapdnld.wnd", nox_xxx_guiDownloadProc_4CC890)
	winDownload.SetAllFuncs(nox_xxx_guiDownloadAbort_4CC830, nil, nil)
	mode := videoGetGameMode()
	v3, v4 := mode.X, mode.Y
	max := videoGetMaxSize()
	v5, v6 := max.X, max.Y
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
	winDownload.SetPos(image.Point{X: (v0 - 1024) / 2, Y: (v1 - 768) / 2})
	nox_xxx_wndShowModalMB(winDownload)
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
		clientPlaySoundSpecial(sound.SoundPermanentFizzle, 100)
		nox_xxx_guiDownloadClose_4CC930()
		noxServer.nox_xxx_gameSetMapPath_409D70(GoString((*C.char)(memmap.PtrOff(0x5D4594, 1522936))))
		nox_xxx_cliCancelMapDownload_4ABA90()
		nox_xxx_mapSetDownloadInProgress(false)
		nox_xxx_mapSetDownloadOK(false)
		noxflags.UnsetGame(noxflags.GameFlag21 | noxflags.GameFlag24)
	}
	return RawEventResp(1)
}

func nox_xxx_guiDownloadProc_4CC890(a1 *Window, ev WindowEvent) WindowEventResp {
	switch ev := ev.(type) {
	case *WindowEvent0x4007:
		v3 := ev.Win.ID()
		clientPlaySoundSpecial(sound.SoundButtonPress, 100)
		if v3 != 1601 {
			return nil
		}
		nox_xxx_guiDownloadClose_4CC930()
		nox_xxx_cliCancelMapDownload_4ABA90()
		noxServer.nox_xxx_gameSetMapPath_409D70(GoString((*C.char)(memmap.PtrOff(0x5D4594, 1522940))))
		nox_xxx_mapSetDownloadInProgress(false)
		nox_xxx_mapSetDownloadOK(false)
		noxflags.UnsetGame(noxflags.GameFlag21 | noxflags.GameFlag24)
		return RawEventResp(1)
	}
	return nil
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
