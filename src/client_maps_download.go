package opennox

import (
	"context"
	"errors"
	"fmt"
	"image"
	"path/filepath"
	"strings"

	"github.com/noxworld-dev/opennox-lib/client/keybind"
	"github.com/noxworld-dev/opennox-lib/datapath"
	"github.com/noxworld-dev/opennox-lib/log"
	"github.com/noxworld-dev/opennox-lib/maps"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/common/sound"
)

type clientMapDownload struct {
	log        *log.Logger
	inProgress bool
	downloadOK bool
	cancel     func()
	done       <-chan error
	native     bool
	ndl        *maps.NativeDownloader
	win        *gui.Window
	iface      struct {
		setMapPath      func(path string)
		sendCancelMap   func() int
		sendReceivedMap func() int
	}
}

func (c *clientMapDownload) Init(cl *Client) {
	c.log = log.New("mapsend")
	c.ndl = maps.NewNativeDownloader(datapath.Maps())
	c.iface.setMapPath = cl.srv.nox_xxx_gameSetMapPath_409D70
	c.iface.sendCancelMap = nox_xxx_cliSendCancelMap_43CAB0
	c.iface.sendReceivedMap = nox_xxx_netMapReceived_43CA80
}

func (c *clientMapDownload) Downloading() bool {
	return c.inProgress
}

func (c *clientMapDownload) setDownloading(v bool) {
	c.inProgress = v
}

func (c *clientMapDownload) setDownloadOK(v bool) {
	c.downloadOK = v
}

func (c *clientMapDownload) deleteFile() {
	c.log.Println("delete downloaded map")
	c.ndl.CancelAndDelete()
	c.setDownloading(false)
	c.setDownloadOK(true)
}

func (c *clientMapDownload) cancelNative() {
	if c.ndl.DownloadOK() {
		c.iface.sendCancelMap()
		c.ndl.CancelAndCleanup()
	}
}

func (c *clientMapDownload) startNative(name string, sz uint) error {
	if name == "" {
		return errors.New("empty name")
	} else if sz <= 0 {
		return errors.New("invalid size")
	}
	c.ndl.Reset()
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
		c.iface.setMapPath(name[i+1:])
	} else {
		c.iface.setMapPath(name)
		mname := strings.TrimSuffix(name, filepath.Ext(name))
		mdir = datapath.Maps(mname)
		fpath = filepath.Join(mdir, mname+".nxz")
	}
	c.log.Println("downloading map to:", fpath)
	if err := c.ndl.Start(fpath, sz); err != nil {
		return err
	}
	return nil
}

func (c *clientMapDownload) onMapDownloadStart(name string, a2 uint) {
	name = strings.TrimSuffix(strings.ToLower(name), maps.Ext)
	c.log.Printf("download start (native): %q, %d", name, int(a2))
	c.native = true
	if err := c.startNative(name, a2); err != nil {
		c.log.Println("download start failed:", err)
		c.iface.sendCancelMap()
		c.setDownloading(false)
		c.setDownloadOK(false)
	}
}

func (c *clientMapDownload) onMapDownloadPart(ind uint, data []byte) {
	if len(data) == 0 {
		return
	}
	c.ndl.WritePart(ind, data)
	if c.ndl.Complete() {
		c.ndl.Reset() // closes the map file
		c.setDownloading(false)
		c.setDownloadOK(true)
		c.setProgress(100)
		c.iface.sendReceivedMap()
	} else {
		c.setProgress(int(c.ndl.Progress() * 100.0))
	}
}

func (c *clientMapDownload) setProgress(val int) int {
	win2 := c.win.ChildByID(1603)
	return gui.EventRespInt(win2.Func94(gui.AsWindowEvent(0x4020, uintptr(val), 0)))
}

func (c *clientMapDownload) onMapDownloadAbort() {
	c.log.Printf("download aborted by the server")
	c.deleteFile()
	c.setDownloading(false)
	c.setDownloadOK(false)
}

func (c *clientMapDownload) Cancel() {
	c.log.Printf("map download cancelled")
	if c.native {
		c.cancelNative()
		return
	}
	c.setDownloading(false)
	if c.cancel != nil {
		c.cancel()
		c.cancel = nil
		if err := <-c.done; err != nil && err != context.Canceled {
			c.log.Println(err)
		}
		c.done = nil
	}
}

func (c *clientMapDownload) abortAndClose(path string) {
	c.CloseDialog()
	c.Cancel()
	c.iface.setMapPath(path)
	c.setDownloading(false)
	c.setDownloadOK(false)
}

func (c *clientMapDownload) CloseDialog() {
	if c.win != nil {
		c.win.Destroy()
	}
	c.win = nil
}

func (c *Client) ShowMapDownload() {
	c.mapsend.win = newWindowFromFile("mapdnld.wnd", c.dialogProc)
	c.mapsend.win.SetAllFuncs(c.dialogEvents, nil, nil)
	mode := c.videoGetGameMode()
	x, y := mode.X, mode.Y
	max := videoGetMaxSize()
	if x > max.X {
		x = max.X
	}
	if y > max.Y {
		y = max.Y
	}
	c.mapsend.win.SetPos(image.Point{X: (x - 1024) / 2, Y: (y - 768) / 2})
	gui.Nox_xxx_wndShowModalMB(c.mapsend.win)
}

func (c *Client) dialogEvents(a1 *gui.Window, ev gui.WindowEvent) gui.WindowEventResp {
	ekey, ok := ev.(gui.WindowKeyPress)
	if !ok {
		return nil
	}
	if ekey.Key != keybind.KeyEsc {
		return nil
	}
	if ekey.Pressed {
		clientPlaySoundSpecial(sound.SoundPermanentFizzle, 100)
		c.mapsend.abortAndClose(memmap.String(0x5D4594, 1522936))
		noxflags.UnsetGame(noxflags.GameFlag21 | noxflags.GameFlag24)
	}
	return gui.RawEventResp(1)
}

func (c *Client) dialogProc(a1 *gui.Window, ev gui.WindowEvent) gui.WindowEventResp {
	switch ev := ev.(type) {
	case *WindowEvent0x4007:
		id := ev.Win.ID()
		clientPlaySoundSpecial(sound.SoundButtonPress, 100)
		if id != 1601 {
			return nil
		}
		c.mapsend.abortAndClose(memmap.String(0x5D4594, 1522940))
		noxflags.UnsetGame(noxflags.GameFlag21 | noxflags.GameFlag24)
		return gui.RawEventResp(1)
	}
	return nil
}
