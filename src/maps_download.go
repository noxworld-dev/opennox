package nox

/*
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
	registerOnConfigRead(func() {
		mapsend.srv = maps.NewServer(datapath.Path(maps.Dir))
		mapsend.srv.RegisterOnMux(gameMux)
	})
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
