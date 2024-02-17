package client

import (
	"image"

	"github.com/noxworld-dev/opennox-lib/client/seat"
	"github.com/noxworld-dev/opennox-lib/console"
	"github.com/noxworld-dev/opennox-lib/log"
	"github.com/noxworld-dev/opennox-lib/strman"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/client/input"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/client/render"
	"github.com/noxworld-dev/opennox/v1/internal/netstr"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	Log = log.New("client")
)

func NewClient(pr console.Printer, s *server.Server) *Client {
	c := &Client{
		Printer: pr, Server: s,
		r:          noxrender.NewRender(s),
		Cursor:     gui.CursorSelect,
		CursorPrev: gui.Cursor17,
	}
	s.Types.ClientTypeByID = c.Things.IndByID
	c.Things.init(s.Strings())
	c.Objs.init(c)
	c.GUI = gui.New(c.r)
	c.vp, _ = alloc.New(noxrender.Viewport{})
	return c
}

type Client struct {
	console.Printer
	Server     *server.Server
	Things     clientObjTypes
	Objs       clientDrawables
	Sight      clientSight
	r          *noxrender.NoxRender
	Seat       seat.Seat
	Inp        *input.Handler
	Win        *render.Renderer
	GUI        *gui.GUI
	vp         *noxrender.Viewport
	DrawFunc   func() bool
	Cursor     gui.Cursor
	CursorPrev gui.Cursor
	state      gui.State

	Conn *netstr.Client

	DrawableQueue []*Drawable
	DrawableList3 []*Drawable
	DrawableList2 []*Drawable
	DrawableList4 []*Drawable

	BackWalls  []*server.Wall
	FrontWalls []*server.Wall
	WallsYyy   []*server.Wall

	Debug struct {
		ShowSight     bool
		showSightData [][]image.Point
	}
}

func (c *Client) Render() *noxrender.NoxRender {
	return c.r
}

func (c *Client) GameAddStateCode(code gui.StateID) {
	if !c.state.Push(code) {
		return
	}
	Log.Println("state code:", code)
}

func (c *Client) GameGetStateCode() gui.StateID {
	return c.state.Current()
}

func (c *Client) GamePopState() {
	c.state.Pop()
	Log.Println("state code:", c.state.Current())
}

func (c *Client) GamePopStateUntil(code gui.StateID) {
	c.state.PopUntil(code)
}

func (c *Client) GameStateSwitch() bool {
	return c.state.Switch()
}

func (c *Client) SetScreenSize(sz image.Point) {
	if c == nil || c.Seat == nil {
		return
	}
	c.Seat.ResizeScreen(sz)
}

func (c *Client) SetScreenGamma(v float32) {
	if c == nil || c.Seat == nil {
		return
	}
	c.Seat.SetGamma(v)
}

func (c *Client) UpdateFullScreen(mode int) {
	if c == nil || c.Win == nil {
		return
	}
	c.Win.SetWindowMode(mode)
}

func (c *Client) SetStretch(v bool) {
	if c == nil || c.Win == nil {
		return
	}
	c.Win.SetStretched(v)
}

func (c *Client) GetStretch() bool {
	if c == nil || c.Win == nil {
		return false
	}
	return c.Win.GetStretched()
}

func (c *Client) ToggleStretch() {
	c.SetStretch(!c.GetStretch())
}

func (c *Client) GetFiltering() bool {
	if c == nil || c.Win == nil {
		return false
	}
	return c.Win.GetFiltering()
}

func (c *Client) ToggleFiltering() bool {
	if c == nil || c.Win == nil {
		return false
	}
	val := !c.Win.GetFiltering()
	c.Win.SetFiltering(val)
	return val
}

func (c *Client) GetWindowMode() int {
	if c == nil || c.Win == nil {
		return 0
	}
	return c.Win.WindowMode()
}

func (c *Client) ResetInput() {
	if c == nil || c.Inp == nil {
		return
	}
	c.Inp.Reset()
}

func (c *Client) GetInputSeq() uint {
	if c == nil || c.Inp == nil {
		return 1
	}
	return c.Inp.CurrentSeq()
}

func (c *Client) GetTextEditBuf() string {
	if c == nil || c.Inp == nil {
		return ""
	}
	return c.Inp.GetTextEditBuf()
}

func (c *Client) SetTextInput(enable bool) {
	if c == nil || c.Inp == nil {
		return
	}
	c.Inp.SetTextInput(enable)
}

func (c *Client) GetSensitivity() float32 {
	if c == nil || c.Inp == nil {
		return 1
	}
	return c.Inp.GetSensitivity()
}

func (c *Client) SetSensitivity(v float32) {
	if c == nil || c.Inp == nil {
		return
	}
	c.Inp.SetSensitivity(v)
}

func (c *Client) GetMousePos() image.Point {
	if c == nil || c.Inp == nil {
		return image.Point{}
	}
	return c.Inp.GetMousePos()
}

func (c *Client) ChangeMousePos(pos image.Point, abs bool) {
	if c == nil || c.Inp == nil {
		return
	}
	c.Inp.ChangeMousePos(pos, abs)
}

func (c *Client) SetMouseBounds(rect image.Rectangle) {
	if c == nil || c.Inp == nil {
		return
	}
	c.Inp.SetMouseBounds(rect)
}

func (c *Client) SetDrawFunc(fnc func() bool) {
	c.DrawFunc = fnc
}

func (c *Client) Strings() *strman.StringManager {
	return c.Server.Strings()
}

func (c *Client) Viewport() *noxrender.Viewport {
	return c.vp
}

func (c *Client) Nox_client_setCursorType(v gui.Cursor) {
	c.Cursor = v
}

func (c *Client) Nox_client_getCursorType() gui.Cursor {
	return c.Cursor
}
