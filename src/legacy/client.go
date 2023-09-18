package legacy

/*
void sub_4519C0();
int sub_495430();
void sub_44D3A0();
void sub_43D440();
*/
import "C"
import (
	"image"
	"image/color"

	"github.com/noxworld-dev/opennox-lib/strman"
	"golang.org/x/image/font"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
)

type Client interface {
	Strings() *strman.StringManager
	Cli() *client.Client
	Viewport() *noxrender.Viewport
	R2() Render2
	SetDrawFunc(fnc func() bool)
	SetUpdateFunc2(fnc func() bool)
	Nox_client_setCursorType(c gui.Cursor)
	DrawGeneral(v bool) error
	Sub4C42A0(a1, a2 image.Point, a3 *int, a4 *int) int32
	Sub4C5630(a1 int, a2 int, a3 int) int
	Nox_video_drawAnimatedImageOrCursorAt(ref *ImageRef, pos image.Point)
	Sub469920(p image.Point) []uint32
	Nox_video_stopAllFades44E040()
	GameAddStateCode(code gui.StateID)
	GameGetStateCode() gui.StateID
	GamePopState()
	GameStateSwitch() bool
	GetMousePos() image.Point
	GetInputSeq() uint
	ChangeMousePos(pos image.Point, abs bool)
	SetMouseBounds(rect image.Rectangle)
	SetSensitivity(v float32)
	SetTextInput(enable bool)
	GetTextEditBuf() string
	NewGUIAdvOptsOn(par *gui.Window)
	GUIAdvVideoOptsLoad()
	Nox_drawable_find(pt image.Point, r int) *client.Drawable
	Nox_xxx_spriteLoadAdd_45A360_drawable(thingInd int, pos image.Point) *client.Drawable
	Sub_45A670(a1 uint32)
	Nox_xxx_spriteDelete_45A4B0(dr *client.Drawable) int
	Nox_new_drawable_for_thing(i int) *client.Drawable
	Nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr *client.Drawable)
	Nox_xxx_spriteDeleteAll_45A5E0(a1 int)
}

type Render2 interface {
	Data() *noxrender.RenderData
	SetRectFullScreen()
	SetInterlacing(enable bool, y int)
	SetTextSmooting(enabled bool)
	SetColorMultAndIntensityRGB(cr, cg, cb byte) byte
	ClearPoints()
	AddPoint(pos image.Point)
	AddPointRel(pos image.Point)
	DrawLineFromPoints(cl color.Color, arr ...image.Point) bool
	DrawParticles49ED80(mul2 int) bool
	DrawRectFilledOpaque(x, y, w, h int, cl color.Color)
	DrawRectFilledAlpha(x, y, w, h int)
	DrawBorder(x, y, w, h int, cl color.Color)
	DrawPixel(pos image.Point, cl color.Color)
	DrawPointRad(p image.Point, rad int, cl color.Color)
	DrawPoint(pos image.Point, rad int, cl color.Color)
	DrawCircle(x, y, rad int, cl color.Color)
	DrawCircleSegment(cx, cy, rad, ang int, cl color.Color)
	DrawImageAt(img *noxrender.Image, pos image.Point)
	DrawGlow(pos image.Point, cl color.Color, a3 int, a4 int)
	FontHeight(fnt font.Face) int
	GetFonts() *noxrender.RenderFonts
	TabWidth() int
	SetTabWidth(w int)
	GetStringSizeWrapped(fnt font.Face, s string, maxW int) image.Point
	GetStringSizeWrappedStyle(fnt font.Face, s string, maxW int) image.Point
	DrawString(font font.Face, str string, pos image.Point) int
	DrawStringHL(font font.Face, str string, pos image.Point) int
	DrawStringStyle(font font.Face, str string, pos image.Point) int
	DrawStringWrapped(font font.Face, s string, rect image.Rectangle) int
	DrawStringWrappedHL(font font.Face, s string, rect image.Rectangle) int
	DrawStringWrappedStyle(font font.Face, s string, rect image.Rectangle) int
	FadeInScreen(t int, menu bool, done func()) bool
	FadeOutScreen(t int, menu bool, done func()) int
	GetBag() *noxrender.RenderSprites
	Set_dword_5d4594_3799484(v int)
	Sub_49F7C0_def_go()
}

var (
	GetClient func() Client
)

func Sub_4519C0() {
	C.sub_4519C0()
}

func Sub_495430() {
	C.sub_495430()
}

func Sub_44D3A0() {
	C.sub_44D3A0()
}

func Sub_43D440() {
	C.sub_43D440()
}
