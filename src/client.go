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

	"github.com/noxworld-dev/opennox-lib/console"
	"github.com/spf13/viper"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/audio/ail"
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
	cl := client.NewClient(pr, srv.Server)
	c := &Client{
		Client: cl,
		srv:    srv,
		r:      NewNoxRender(cl.Render()),
	}
	c.guiAdv.Init(c)
	c.screenshots.Init(c)
	c.mapsend.Init(c)
	return c, nil
}

type Client struct {
	*client.Client
	srv                *Server
	r                  *NoxRender
	mapsend            clientMapDownload
	guiAdv             guiAdvOptions
	guiFPS             guiFPS
	screenshots        screenshots
	netPrevMouse       image.Point
	inSub4312C0        bool
	ticks805996        uint64
	inDraw1            bool
	dragndrapSpell     uint32
	dragndropSpellType int
	dragndropItem      *client.Drawable
	pos1097204         image.Point
	pos1097212         image.Point
	flag3798728        bool
}

func (c *Client) Close() error {
	c.freeSeat()
	return nil
}

func (c *Client) SetStretch(v bool) {
	if c == nil {
		return
	}
	c.Client.SetStretch(v)
	viper.Set(configVideoStretch, v)
}

func (c *Client) setStretchIfNotSet(v bool) {
	if !viper.IsSet(configVideoStretch) {
		c.SetStretch(v)
	}
}

func (c *Client) ToggleStretch() {
	c.SetStretch(!c.GetStretch())
}

func (c *Client) ToggleFiltering() {
	if c == nil {
		return
	}
	val := !c.Client.ToggleFiltering()
	viper.Set(configVideoFiltering, val)
	writeConfigLater()
}

func (c *Client) processInput() {
	if c == nil || c.Inp == nil {
		return
	}
	c.Inp.Tick()
	c.nox_client_processInput_4308A0()
	c.nox_xxx_cursorUpdate_46B740()
	c.GUI.ProcessKeys(c.Inp)
}

func (c *Client) Update() bool {
	defer noxPerfmon.startProfileClient()()
	if !isDedicatedServer {
		c.inDraw1 = true
		if c.DrawFunc != nil && !c.DrawFunc() {
			if debugMainloop {
				gameLog.Println("call_nox_draw_unk1 exit")
			}
			return false
		}
		c.inDraw1 = false
	}
	if c.UpdateFunc2 != nil && !c.UpdateFunc2() {
		if debugMainloop {
			gameLog.Println("call_func_5D4594_816392 exit")
		}
		return false
	}
	C.sub_4519C0()
	c.sub4312C0()
	if !isDedicatedServer {
		C.sub_495430()
	}
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
