package opennox

/*
int sub_4519C0();
int sub_495430();
void sub_44D3A0();
void sub_43D440();
*/
import "C"
import (
	"image"

	"github.com/noxworld-dev/opennox-lib/client/seat"
	"github.com/noxworld-dev/opennox-lib/console"
	"github.com/noxworld-dev/opennox-lib/strman"
	"github.com/spf13/viper"

	"github.com/noxworld-dev/opennox/v1/client/audio/ail"
	"github.com/noxworld-dev/opennox/v1/client/input"
	"github.com/noxworld-dev/opennox/v1/client/render"
	"github.com/noxworld-dev/opennox/v1/common/alloc"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
)

var (
	noxClient *Client
)

const (
	configVideoFiltering = "video.filtering"
	configVideoStretch   = "video.stretch"
)

func NewClient(pr console.Printer, srv *Server) (*Client, error) {
	c := &Client{
		pr:  pr,
		srv: srv,
		r:   NewNoxRender(srv),
	}
	c.vp, _ = alloc.New(Viewport{})
	c.guiAdv.Init(c)
	c.screenshots.Init(c)
	c.mapsend.Init(c)
	return c, nil
}

type Client struct {
	pr           console.Printer
	srv          *Server
	seat         seat.Seat
	win          *render.Renderer
	r            *NoxRender
	vp           *Viewport
	inp          *input.Handler
	drawFunc     func() bool
	updateFunc2  func() bool
	mapsend      clientMapDownload
	guiAdv       guiAdvOptions
	guiFPS       guiFPS
	screenshots  screenshots
	netPrevMouse image.Point
	inSub4312C0  bool
	ticks805996  uint64
	inDraw1      bool
}

func (c *Client) Close() error {
	c.freeSeat()
	return nil
}

func (c *Client) Strings() *strman.StringManager {
	return c.srv.Strings()
}

func (c *Client) Viewport() *Viewport {
	return c.vp
}

func (c *Client) setScreenSize(sz image.Point) {
	if c == nil || c.seat == nil {
		return
	}
	c.seat.ResizeScreen(sz)
}

func (c *Client) setScreenGamma(v float32) {
	if c == nil || c.seat == nil {
		return
	}
	c.seat.SetGamma(v)
}

func (c *Client) updateFullScreen(mode int) {
	if c == nil || c.win == nil {
		return
	}
	c.win.SetWindowMode(mode)
}

func (c *Client) setStretch(v bool) {
	if c == nil || c.win == nil {
		return
	}
	c.win.SetStretched(v)
	viper.Set(configVideoStretch, v)
}

func (c *Client) setStretchIfNotSet(v bool) {
	if !viper.IsSet(configVideoStretch) {
		c.setStretch(v)
	}
}

func (c *Client) getStretch() bool {
	if c == nil || c.win == nil {
		return false
	}
	return c.win.GetStretched()
}

func (c *Client) toggleStretch() {
	c.setStretch(!c.getStretch())
}

func (c *Client) getFiltering() bool {
	if c == nil || c.win == nil {
		return false
	}
	return c.win.GetFiltering()
}

func (c *Client) toggleFiltering() {
	if c == nil || c.win == nil {
		return
	}
	val := !c.win.GetFiltering()
	viper.Set(configVideoFiltering, val)
	writeConfigLater()
	c.win.SetFiltering(val)
}

func (c *Client) getWindowMode() int {
	if c == nil || c.win == nil {
		return 0
	}
	return c.win.WindowMode()
}

func (c *Client) processInput() {
	if c == nil || c.inp == nil {
		return
	}
	c.inp.Tick()
	nox_client_processInput_4308A0(c.inp)
	nox_xxx_cursorUpdate_46B740(c.inp)
	c.mainloopKeysUpdate()
}

func (c *Client) resetInput() {
	if c == nil || c.inp == nil {
		return
	}
	c.inp.Reset()
}

func (c *Client) getInputSeq() uint {
	if c == nil || c.inp == nil {
		return 1
	}
	return c.inp.CurrentSeq()
}

func (c *Client) getTextEditBuf() string {
	if c == nil || c.inp == nil {
		return ""
	}
	return c.inp.GetTextEditBuf()
}

func (c *Client) setTextInput(enable bool) {
	if c == nil || c.inp == nil {
		return
	}
	c.inp.SetTextInput(enable)
}

func (c *Client) getSensitivity() float32 {
	if c == nil || c.inp == nil {
		return 1
	}
	return c.inp.GetSensitivity()
}

func (c *Client) setSensitivity(v float32) {
	if c == nil || c.inp == nil {
		return
	}
	c.inp.SetSensitivity(v)
}

func (c *Client) getMousePos() image.Point {
	if c == nil || c.inp == nil {
		return image.Point{}
	}
	return c.inp.GetMousePos()
}

func (c *Client) changeMousePos(pos image.Point, abs bool) {
	if c == nil || c.inp == nil {
		return
	}
	c.inp.ChangeMousePos(pos, abs)
}

func (c *Client) setMouseBounds(rect image.Rectangle) {
	if c == nil || c.inp == nil {
		return
	}
	c.inp.SetMouseBounds(rect)
}

func (c *Client) mainloopKeysUpdate() {
	if c == nil || c.inp == nil {
		return
	}
	for _, key := range c.inp.KeyboardKeys() {
		nox_xxx_windowUpdateKeysMB_46B6B0(c.inp, key)
	}
}

func (c *Client) setDrawFunc(fnc func() bool) {
	c.drawFunc = fnc
}

func (c *Client) setUpdateFunc2(fnc func() bool) {
	c.updateFunc2 = fnc
}

func (c *Client) Update() bool {
	defer noxPerfmon.startProfileClient()()
	if !isDedicatedServer {
		c.inDraw1 = true
		if c.drawFunc != nil && !c.drawFunc() {
			if debugMainloop {
				gameLog.Println("call_nox_draw_unk1 exit")
			}
			return false
		}
		c.inDraw1 = false
	}
	if c.updateFunc2 != nil && !c.updateFunc2() {
		if debugMainloop {
			gameLog.Println("call_func_5D4594_816392 exit")
		}
		return false
	}
	C.sub_4519C0()
	c.sub4312C0()
	C.sub_495430()
	if noxflags.HasGame(noxflags.GameHost) && continueMenuOrHost && !mainloopStopError {
		mainloopMaybeSwitchMapXXX()
	}
	c.drawAndPresent()
	return true
}

func (c *Client) sub4312C0() {
	ail.Serve()
	if c.inSub4312C0 {
		return
	}
	c.inSub4312C0 = true
	defer func() {
		c.inSub4312C0 = false
	}()
	ticks := platformTicks()

	if ticks-c.ticks805996 > 33 {
		C.sub_44D3A0()
		C.sub_43D440()
		c.ticks805996 = ticks
	}
}
