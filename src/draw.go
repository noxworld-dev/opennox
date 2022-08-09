package opennox

/*
#include "defs.h"
#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME2_2.h"
#include "GAME2_3.h"
#include "GAME3_1.h"
#include "GAME5_2.h"
#include "common__system__team.h"
#include "client__system__client.h"
#include "client__gui__guiquit.h"
#include "client__gui__guiggovr.h"
#include "client__draw__selectdw.h"
#include "client__draw__debugdraw.h"
#include "client__draw__glowdraw.h"
#include "client__draw__fx.h"
extern nox_drawable* nox_xxx_drawablePlayer_1046600;
extern unsigned int nox_client_translucentFrontWalls_805844;
extern unsigned int nox_client_highResFrontWalls_80820;
extern unsigned int nox_client_highResFloors_154952;
extern unsigned int nox_client_lockHighResFloors_1193152;
extern unsigned int nox_client_fadeObjects_80836;
extern unsigned int nox_client_renderBubbles_80844;
extern unsigned int nox_client_renderGUI_80828;
extern unsigned int nox_xxx_xxxRenderGUI_587000_80832;
extern unsigned int nox_xxx_waypointCounterMB_587000_154948;
extern unsigned int dword_5d4594_2523804;
extern unsigned int dword_5d4594_2650676;
extern unsigned int dword_5d4594_2650680;
extern unsigned int dword_5d4594_811904;
extern unsigned int nox_client_gui_flag_815132;
extern unsigned int dword_5d4594_3799452;
extern unsigned int dword_5d4594_3799468;
extern unsigned int dword_5d4594_1193156;
extern unsigned int dword_5d4594_1193188;
extern int dword_5d4594_3799524;
extern unsigned int nox_client_gui_flag_1556112;
extern unsigned int nox_gameDisableMapDraw_5d4594_2650672;
void nox_xxx_tileDrawMB_481C20_A(nox_draw_viewport_t* vp, int v3);
void nox_xxx_tileDrawMB_481C20_B(nox_draw_viewport_t* vp, int v78);
void nox_xxx_tileDrawMB_481C20_C_textured(nox_draw_viewport_t* vp, int v72, int v78);
void nox_xxx_tileDrawMB_481C20_C_solid(nox_draw_viewport_t* vp, int v72, int v78);
void  nox_xxx_cliLight16_469140(nox_drawable* dr, nox_draw_viewport_t* vp);
void nox_xxx_clientDrawAll_436100_draw_A();
void nox_xxx_clientDrawAll_436100_draw_B();
void nox_xxx_drawAllMB_475810_draw_A(nox_draw_viewport_t* vp);
int nox_xxx_drawAllMB_475810_draw_B(nox_draw_viewport_t* vp);
void nox_xxx_drawAllMB_475810_draw_C(nox_draw_viewport_t* vp, int v36, int v7);
void nox_xxx_drawAllMB_475810_draw_D(nox_draw_viewport_t* vp);
extern uint32_t dword_5d4594_3679320;
extern uint32_t dword_5d4594_3798156;
extern uint32_t dword_5d4594_3798800;
extern uint32_t dword_5d4594_3798804;
extern uint32_t dword_5d4594_3798808;
extern uint32_t dword_5d4594_3798812;
extern uint32_t dword_5d4594_3798816;
extern uint32_t dword_5d4594_3798820;
extern uint32_t dword_5d4594_3798824;
extern uint32_t dword_5d4594_3798828;
extern uint32_t dword_5d4594_3798832;
extern uint32_t dword_5d4594_3798836;
extern uint32_t dword_5d4594_3798840;
extern uint32_t nox_arr_956A00[NOX_MAX_HEIGHT + 150];
extern unsigned char nox_arr_957820[128 * (NOX_MAX_HEIGHT + 150)];
extern void (*func_587000_154940)(int2*, uint32_t, uint32_t);
extern int (*func_587000_154944)(int, int);
extern void* nox_video_tileBuf_ptr_3798796;
extern void* nox_video_tileBuf_end_3798844;
*/
import "C"
import (
	"encoding/binary"
	"fmt"
	"image"
	"image/color"
	"math"
	"sort"
	"unsafe"

	"golang.org/x/image/font"

	noxcolor "github.com/noxworld-dev/opennox-lib/color"
	"github.com/noxworld-dev/opennox-lib/common"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/common/alloc"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

const (
	// TODO: the 4x factor is for high-res; figure out what those values are
	lightGridW = 57 * 4
	lightGridH = 45 * 4
	lightGrid  = common.GridStep
)

var (
	nox_video_renderTargetFlags       = 0
	nox_client_texturedFloors_154956  = true
	nox_client_texturedFloors2_154960 = true
	nox_client_showTooltips_80840     = true
	nox_client_drawFrontWalls_80812   = true
	partViewportOff                   image.Point

	nox_arr2_853BC0  [lightGridW][lightGridH]RGB
	nox_arr_84EB20   [lightGridW]nox_arr_84EB20_t
	lightsOutBuf     []uint32
	nox_light_8529A0 [512]int
)

type nox_arr_84EB20_t struct {
	Y  int
	Cl [common.GridStep]RGB
}

//export sub_473970
func sub_473970(a1, a2 *C.int2) {
	a2.field_0 = C.int(partViewportOff.X) + a1.field_0
	a2.field_4 = C.int(partViewportOff.Y) + a1.field_4
}

func partOffsetPos(p image.Point) image.Point {
	return p.Sub(partViewportOff)
}

//export sub_4739D0
func sub_4739D0(a1 C.int) C.int { return a1 - C.int(partViewportOff.Y) }

//export get_nox_client_texturedFloors_154956
func get_nox_client_texturedFloors_154956() C.bool {
	return C.bool(nox_client_texturedFloors_154956)
}

func asViewport(p *nox_draw_viewport_t) *Viewport {
	return asViewportP(unsafe.Pointer(p))
}

func asViewportP(p unsafe.Pointer) *Viewport {
	return (*Viewport)(p)
}

//export nox_draw_getViewport_437250
func nox_draw_getViewport_437250() *nox_draw_viewport_t {
	return noxClient.Viewport().C()
}

//export sub_437260
func sub_437260() {
	vp := noxClient.Viewport()
	noxClient.r.setClipRects(vp.Screen.Min, vp.Size)
}

func sub_437180() {
	C.sub_48D990(noxClient.Viewport().C())
}

//export sub_4355B0
func sub_4355B0(a1 C.int) {
	noxClient.Viewport().field_12 = int(a1)
}

//export nox_xxx_getSomeCoods_435670
func nox_xxx_getSomeCoods_435670(a1 *C.int2) {
	p := noxClient.Viewport().World.Max
	a1.field_0 = C.int(p.X)
	a1.field_4 = C.int(p.Y)
}

//export nox_xxx_cliUpdateCameraPos_435600
func nox_xxx_cliUpdateCameraPos_435600(x, y C.int) {
	vp := noxClient.Viewport()
	*memmap.PtrInt32(0x5D4594, 811364) = int32(vp.World.Max.X)
	*memmap.PtrInt32(0x5D4594, 811368) = int32(vp.World.Max.Y)
	vp.World.Min.X = int(x) - vp.Size.X/2
	vp.World.Min.Y = int(y) + vp.field_12 - vp.Size.Y/2
	vp.World.Max.X = int(x)
	vp.World.Max.Y = int(y) + vp.field_12
}

//export sub_437290
func sub_437290() {
	noxClient.r.setRectFullScreen()
}

//export nox_client_drawRectFilledOpaque_49CE30
func nox_client_drawRectFilledOpaque_49CE30(a1, a2, a3, a4 C.int) {
	r := noxClient.r
	r.DrawRectFilledOpaque(int(a1), int(a2), int(a3), int(a4), r.Data().Color2())
}

//export nox_client_drawRectFilledAlpha_49CF10
func nox_client_drawRectFilledAlpha_49CF10(a1, a2, a3, a4 C.int) {
	noxClient.r.DrawRectFilledAlpha(int(a1), int(a2), int(a3), int(a4))
}

//export nox_client_drawBorderLines_49CC70
func nox_client_drawBorderLines_49CC70(a1, a2, a3, a4 C.int) {
	r := noxClient.r
	r.DrawBorder(int(a1), int(a2), int(a3), int(a4), r.Data().Color2())
}

//export nox_client_drawLineHorizontal_49F180
func nox_client_drawLineHorizontal_49F180(a1, a2, a3 C.int) {
	r := noxClient.r
	r.DrawLineHorizontal(int(a1), int(a2), int(a3), r.Data().Color2())
}

//export nox_client_drawPixel_49EFA0
func nox_client_drawPixel_49EFA0(a1, a2 C.int) {
	r := noxClient.r
	r.DrawPixel(image.Pt(int(a1), int(a2)), r.Data().Color2())
}

//export nox_client_drawPoint_4B0BC0
func nox_client_drawPoint_4B0BC0(a1, a2, a3 C.int) {
	r := noxClient.r
	r.DrawPointRad(image.Pt(int(a1), int(a2)), int(a3), r.Data().Color2())
}

//export nox_xxx_drawPointMB_499B70
func nox_xxx_drawPointMB_499B70(a1, a2, a3 C.int) {
	r := noxClient.r
	r.DrawPoint(image.Pt(int(a1), int(a2)), int(a3), r.Data().Color2())
}

var _ = [1]struct{}{}[52-unsafe.Sizeof(Viewport{})]
var _ = [1]struct{}{}[4-unsafe.Sizeof(int(0))]

type nox_draw_viewport_t = C.nox_draw_viewport_t

type Viewport struct {
	Screen   image.Rectangle // 0, 0
	World    image.Rectangle // 4, 16
	Size     image.Point     // 8, 32
	field_10 uint            // 10, 40
	field_11 uint            // 11, 44
	field_12 int             // 12, 48
}

func (vp *Viewport) C() *nox_draw_viewport_t {
	return (*nox_draw_viewport_t)(unsafe.Pointer(vp))
}

func (vp *Viewport) ToScreenPos(pos image.Point) image.Point { // sub_4739E0
	return pos.Sub(vp.World.Min).Add(vp.Screen.Min)
}

func (vp *Viewport) ToWorldPos(pos image.Point) image.Point {
	return pos.Sub(vp.Screen.Min).Add(vp.World.Min)
}

func detectBestVideoSettings() {
	const cfg = 450
	cut := 0
	*memmap.PtrUint32(0x587000, 80808) = 1
	*memmap.PtrUint32(0x587000, 80816) = 1
	nox_client_showTooltips_80840 = true
	C.nox_client_renderGUI_80828 = 1
	C.nox_xxx_xxxRenderGUI_587000_80832 = 1
	if cfg == 0 {
		//v4 = 8
		cut = 75
		nox_client_drawFrontWalls_80812 = false
		C.nox_client_translucentFrontWalls_805844 = 0
		C.nox_client_highResFrontWalls_80820 = 0
		C.nox_client_highResFloors_154952 = 0
		C.nox_client_lockHighResFloors_1193152 = 0
		nox_client_texturedFloors_154956 = true
		guiCon.translucent = false
		noxClient.r.renderGlow = false
		C.nox_client_fadeObjects_80836 = 0
		noxflags.UnsetEngine(noxflags.EngineSoftShadowEdge)
		C.nox_client_renderBubbles_80844 = 0
	} else if cfg == 200 {
		//v4 = 8
		cut = 85
		nox_client_drawFrontWalls_80812 = true
		C.nox_client_translucentFrontWalls_805844 = 0
		C.nox_client_highResFrontWalls_80820 = 0
		C.nox_client_highResFloors_154952 = 0
		C.nox_client_lockHighResFloors_1193152 = 0
		nox_client_texturedFloors_154956 = true
		guiCon.translucent = false
		noxClient.r.renderGlow = false
		C.nox_client_fadeObjects_80836 = 0
		noxflags.UnsetEngine(noxflags.EngineSoftShadowEdge)
		C.nox_client_renderBubbles_80844 = 0
	} else if cfg == 266 {
		//v4 = 8
		cut = 100
		nox_client_drawFrontWalls_80812 = true
		C.nox_client_translucentFrontWalls_805844 = 1
		C.nox_client_highResFrontWalls_80820 = 1
		C.nox_client_highResFloors_154952 = 1
		C.nox_client_lockHighResFloors_1193152 = 0
		nox_client_texturedFloors_154956 = true
		guiCon.translucent = false
		noxClient.r.renderGlow = true
		C.nox_client_fadeObjects_80836 = 1
		noxflags.SetEngine(noxflags.EngineSoftShadowEdge)
		C.nox_client_renderBubbles_80844 = 1
	} else if cfg == 300 {
		//v4 = 16
		cut = 100
		nox_client_drawFrontWalls_80812 = true
		C.nox_client_translucentFrontWalls_805844 = 1
		C.nox_client_highResFrontWalls_80820 = 1
		C.nox_client_highResFloors_154952 = 1
		C.nox_client_lockHighResFloors_1193152 = 0
		nox_client_texturedFloors_154956 = true
		guiCon.translucent = false
		noxClient.r.renderGlow = true
		C.nox_client_fadeObjects_80836 = 1
		noxflags.SetEngine(noxflags.EngineSoftShadowEdge)
		C.nox_client_renderBubbles_80844 = 1
	} else if cfg == 450 {
		//v4 = 16
		cut = 100
		nox_client_drawFrontWalls_80812 = true
		C.nox_client_translucentFrontWalls_805844 = 1
		C.nox_client_highResFrontWalls_80820 = 1
		C.nox_client_highResFloors_154952 = 1
		C.nox_client_lockHighResFloors_1193152 = 1
		nox_client_texturedFloors_154956 = true
		guiCon.translucent = true
		noxClient.r.renderGlow = true
		C.nox_client_fadeObjects_80836 = 1
		noxflags.SetEngine(noxflags.EngineSoftShadowEdge)
		C.nox_client_renderBubbles_80844 = 1
	}
	nox_xxx_tileSetDrawFn_481420()
	if !noxflags.HasEngine(noxflags.EngineWindowed) {
		videoUpdateGameMode(image.Point{
			X: noxDefaultWidth,
			Y: noxDefaultHeight,
		})
	}
	nox_video_setCutSize(cut)
	if noxflags.HasGame(noxflags.GameFlag29) {
		noxClient.nox_draw_setCutSize(cut, 0)
	}
	legacyProfiled = 1
}

func nox_draw_freeColorTables_433C20() {
	*memmap.PtrUint32(0x973F18, 5232) = 0
}

//export nox_draw_splitColor_435280
func nox_draw_splitColor_435280(cl C.short, pr, pg, pb *C.uchar) {
	c := noxrender.SplitColor(noxcolor.RGBA5551(cl))
	*pr = C.uchar(c.R)
	*pg = C.uchar(c.G)
	*pb = C.uchar(c.B)
}

//export nox_draw_setMaterial_4340A0
func nox_draw_setMaterial_4340A0(ind, r, g, b C.int) {
	noxClient.r.Data().SetMaterialRGB(int(ind), int(r), int(g), int(b))
}

//export nox_draw_setMaterial_4341D0
func nox_draw_setMaterial_4341D0(ind, cl C.int) {
	noxClient.r.Data().SetMaterial(int(ind), noxcolor.RGBA5551(cl))
}

func sub_4347F0(a1 unsafe.Pointer, a2 int) {
	if a2 <= 256 {
		C.sub_435120(memmap.PtrOff(0x973F18, 3880), a1)
		C.sub_435040()
	}
	nox_xxx_makeFillerColor_48BDE0()
}

func sub_4338D0() int {
	d := noxClient.r.Data()
	d.Reset()
	*memmap.PtrUint32(0x5D4594, 809596) = 0
	if videoInitDone {
		v2, freeV2 := alloc.Malloc(256 * 3)
		defer freeV2()
		C.sub_435150((*C.uchar)(v2), (*C.char)(memmap.PtrOff(0x973F18, 3880)))
		sub_4347F0(v2, 256)
	} else {
		sub_4347F0(memmap.PtrOff(0x581450, 8404), 256)
	}
	d.SetMaterialRGB(0, 0, 0, 255)
	d.SetMaterialRGB(1, 0, 255, 0)
	d.SetMaterialRGB(2, 0, 255, 255)
	d.SetMaterialRGB(3, 255, 0, 0)
	d.SetMaterialRGB(4, 255, 0, 255)
	d.SetMaterialRGB(5, 255, 255, 0)
	d.SetMaterialRGB(6, 255, 255, 255)
	d.SetMaterialRGB(7, 0, 0, 0)
	d.SetMaterialRGB(8, 0, 0, 128)
	d.SetMaterialRGB(9, 0, 128, 0)
	d.SetMaterialRGB(10, 0, 128, 128)
	d.SetMaterialRGB(11, 128, 0, 0)
	d.SetMaterialRGB(12, 128, 0, 128)
	d.SetMaterialRGB(13, 128, 128, 0)
	d.SetMaterialRGB(14, 128, 128, 128)
	d.SetMaterialRGB(15, 0, 0, 0)
	*memmap.PtrUint32(0x973F18, 5232) = 0
	return 1
}

//export nox_draw_set54RGB32_434040
func nox_draw_set54RGB32_434040(cl C.int) {
	c := noxrender.SplitColor(noxcolor.RGBA5551(cl))
	noxClient.r.Data().setColorInt54(RGB{
		R: int(c.R),
		G: int(c.G),
		B: int(c.B),
	})
}

//export nox_draw_setColorMultAndIntensity_433E40
func nox_draw_setColorMultAndIntensity_433E40(cl C.int) C.int {
	c := noxcolor.RGBA5551(cl).ColorNRGBA()
	return C.int(noxClient.r.setColorMultAndIntensityRGB(c.R, c.G, c.B))
}

func sub433E40(cl noxcolor.Color) C.int {
	c := cl.ColorNRGBA()
	return C.int(noxClient.r.setColorMultAndIntensityRGB(c.R, c.G, c.B))
}

//export nox_draw_setColorMultAndIntensityRGB_433CD0
func nox_draw_setColorMultAndIntensityRGB_433CD0(r, g, b C.uchar) C.int {
	return C.int(noxClient.r.setColorMultAndIntensityRGB(byte(r), byte(g), byte(b)))
}

func (r *NoxRender) setColorMultAndIntensity(cl color.Color) {
	c := noxcolor.ToRGBA5551Color(cl).ColorNRGBA()
	r.setColorMultAndIntensityRGB(c.R, c.G, c.B)
}

func (r *NoxRender) setColorMultAndIntensityRGB(cr, cg, cb byte) byte {
	d := r.Data()
	d.flag16 = uint32(bool2int(cr == 0xFF && cg == 0xFF && cb == 0xFF))
	d.SetColorMultA(noxrender.Color16{R: uint16(cr), G: uint16(cg), B: uint16(cb)})
	v := r.ColorIntensity(cr, cg, cb)
	d.intensity258 = uint16(v)
	return v
}

//export sub_434080
func sub_434080(a1 C.int) {
	noxClient.r.Data().setField262(int(a1))
}

//export nox_xxx_drawSetTextColor_434390
func nox_xxx_drawSetTextColor_434390(a1 C.int) {
	noxClient.r.Data().SetTextColor(noxcolor.RGBA5551(a1))
}

//export nox_xxx_drawSetColor_4343E0
func nox_xxx_drawSetColor_4343E0(a1 C.int) {
	noxClient.r.Data().SetColor(noxcolor.RGBA5551(a1))
}

//export nox_client_drawSetColor_434460
func nox_client_drawSetColor_434460(a1 C.int) {
	noxClient.r.Data().SetColor2(noxcolor.RGBA5551(a1))
}

//export nox_client_drawEnableAlpha_434560
func nox_client_drawEnableAlpha_434560(a1 C.int) {
	noxClient.r.Data().SetAlphaEnabled(a1 != 0)
}

//export sub_4345F0
func sub_4345F0(a1 C.int) {
	noxClient.r.Data().setMultiply14(int(a1))
}

//export nox_xxx_draw_434600
func nox_xxx_draw_434600(a1 C.int) {
	noxClient.r.Data().setColorize17(int(a1))
}

//export sub_434990
func sub_434990(r, g, b C.int) {
	noxClient.r.Data().SetLightColor(RGB{
		R: int(r),
		G: int(g),
		B: int(b),
	})
}

//export sub_4349C0
func sub_4349C0(a1 *C.uint) {
	arr := unsafe.Slice(a1, 3)
	noxClient.r.Data().SetLightColor(RGB{
		R: int(arr[0]),
		G: int(arr[1]),
		B: int(arr[2]),
	})
}

//export sub_47D370
func sub_47D370(a1 C.int) {
	noxClient.r.Set_dword_5d4594_3799484(int(a1))
}

//export sub_47D400
func sub_47D400(a1 C.int, a2 C.char) {
	noxClient.r.SetInterlacing(a1 != 0, int(a2))
}

//export sub_49F7C0_def
func sub_49F7C0_def() {
	noxClient.r.sub_49F7C0_def_go()
}

func (r *NoxRender) sub_49F7C0_def_go() {
	ymax := r.Get_dword_5d4594_3799476()
	cr := r.Data().ClipRect()
	if ymax > cr.Max.Y {
		ymax = cr.Max.Y
	}
	r.setClipRects(cr.Min, image.Pt(cr.Dx(), ymax-cr.Min.Y))
}

func (r *NoxRender) setClipRects(p, sz image.Point) { // nox_client_copyRect_49F6F0
	rc := image.Rectangle{Min: p, Max: p.Add(sz)}
	d := r.Data()
	rect := rc.Intersect(d.Rect3())
	if !rect.Empty() {
		d.SetClipRect(rect)
		rect.Max.X--
		rect.Max.Y--
		d.SetClipRect2(rect)
	}
}

func (r *NoxRender) setRectFullScreen() { // sub_437290
	sz := r.PixBufferRect().Size()
	r.setClipRects(image.Pt(0, 0), sz)
}

//export nox_client_drawSetAlpha_434580
func nox_client_drawSetAlpha_434580(a C.uchar) {
	noxClient.r.Data().SetAlpha(byte(a))
}

//export nox_draw_enableTextSmoothing_43F670
func nox_draw_enableTextSmoothing_43F670(v C.int) {
	noxClient.r.SetTextSmooting(v != 0)
}

//export nox_client_drawResetPoints_49F5A0
func nox_client_drawResetPoints_49F5A0() {
	noxClient.r.ClearPoints()
}

//export nox_client_drawAddPoint_49F500
func nox_client_drawAddPoint_49F500(x, y C.int) {
	noxClient.r.AddPoint(image.Pt(int(x), int(y)))
}

//export nox_xxx_rasterPointRel_49F570
func nox_xxx_rasterPointRel_49F570(x, y C.int) {
	noxClient.r.AddPointRel(image.Pt(int(x), int(y)))
}

func nox_client_drawLastPoint_49F5B0(px, py *uint, keep int) int {
	pos, ok := noxClient.r.LastPoint(keep != 0)
	if !ok {
		return 0
	}
	if px != nil {
		*px = uint(pos.X)
	}
	if py != nil {
		*py = uint(pos.Y)
	}
	return 1
}

//export nox_client_drawLineFromPoints_49E4B0
func nox_client_drawLineFromPoints_49E4B0() C.int {
	r := noxClient.r
	return C.int(bool2int(r.DrawLineFromPoints(r.Data().Color2())))
}

//export sub_49E4F0
func sub_49E4F0(a1 C.int) C.int {
	return C.int(bool2int(noxClient.r.drawParticles49ED80(int(a1))))
}

//export sub_480860
func sub_480860(a1, a2 *C.ushort, w C.int, a4, a5 *C.int) {
	dst := unsafe.Slice((*uint16)(unsafe.Pointer(a1)), int(w))
	src := unsafe.Slice((*uint16)(unsafe.Pointer(a2)), int(w))
	a4p := unsafe.Slice((*uint32)(unsafe.Pointer(a4)), 3)
	a5p := unsafe.Slice((*uint32)(unsafe.Pointer(a5)), 3)
	for i := 0; i < int(w); i++ {
		c := noxrender.SplitColor16(src[i])
		c.R = uint16((a4p[0] * uint32(c.R)) >> 16)
		c.G = uint16((a4p[1] * uint32(c.G)) >> 16)
		c.B = uint16((a4p[2] * uint32(c.B)) >> 16)
		dst[i] = c.Make16()

		a4p[0] += a5p[0]
		a4p[1] += a5p[1]
		a4p[2] += a5p[2]
	}
}

func toRect(cr *C.nox_rect) image.Rectangle {
	return image.Rect(int(cr.min_x), int(cr.min_y), int(cr.max_x), int(cr.max_y))
}

func setRect(cr *C.nox_rect, r image.Rectangle) {
	cr.min_x = C.int(r.Min.X)
	cr.min_y = C.int(r.Min.Y)
	cr.max_x = C.int(r.Max.X)
	cr.max_y = C.int(r.Max.Y)
}

type NoxRender struct {
	*noxrender.NoxRender
	p *RenderData

	colors struct {
		R [256]uint16
		G [256]uint16
		B [256]uint16
	}

	renderGlow bool
	circleSeg  circleSegments
	particles  struct {
		byOpts map[particleOpt]*Particle
	}
	partfx partFXes
}

func newNoxRenderData() (*RenderData, func()) {
	d, free := alloc.New(RenderData{})
	d.Reset()
	return d, free
}

func NewNoxRender() *NoxRender {
	r := &NoxRender{
		NoxRender:  noxrender.NewRender(),
		renderGlow: true,
	}
	r.NoxRender.SetData(renderDataAdapter{r: r, RenderData: r.p})
	r.initColorTables()
	return r
}

func (r *NoxRender) Frame() uint32 {
	return gameFrame()
}

func (r *NoxRender) Data() *RenderData {
	return r.p
}

type renderDataAdapter struct {
	r *NoxRender
	*RenderData
}

func (d renderDataAdapter) Frame() uint32 {
	return d.r.Frame()
}

func (d renderDataAdapter) ShouldDrawText() bool {
	return !noxflags.HasEngine(noxflags.EngineNoTextRendering)
}

func (d renderDataAdapter) DefaultFont() font.Face {
	return noxFontDefault
}

func (r *NoxRender) SetData(p *RenderData) {
	r.p = p
	r.NoxRender.SetData(renderDataAdapter{r: r, RenderData: r.p})
}

//export nox_xxx_guiFontHeightMB_43F320
func nox_xxx_guiFontHeightMB_43F320(fnt unsafe.Pointer) C.int {
	return C.int(noxClient.r.FontHeight(asFont(fnt)))
}

//export nox_draw_setTabWidth_43FE20
func nox_draw_setTabWidth_43FE20(v C.int) C.int {
	old := noxClient.r.TabWidth()
	noxClient.r.SetTabWidth(int(v))
	return C.int(old)
}

//export nox_draw_getFontAdvance_43F9E0
func nox_draw_getFontAdvance_43F9E0(fnt unsafe.Pointer, sp *C.wchar_t, maxW C.int) C.int {
	// TODO: this may be incorrect
	return C.int(noxClient.r.GetStringSizeWrapped(asFont(fnt), GoWString(sp), int(maxW)).X)
}

//export nox_xxx_drawGetStringSize_43F840
func nox_xxx_drawGetStringSize_43F840(font unsafe.Pointer, sp *C.wchar_t, outW, outH *C.int, maxW C.int) C.int {
	sz := noxClient.r.GetStringSizeWrapped(asFont(font), GoWString(sp), int(maxW))
	if outW != nil {
		*outW = C.int(sz.X)
	}
	if outH != nil {
		*outH = C.int(sz.Y)
	}
	return C.int(bool2int(sz != (image.Point{})))
}

//export nox_xxx_bookGetStringSize_43FA80
func nox_xxx_bookGetStringSize_43FA80(font unsafe.Pointer, sp *C.wchar_t, outW, outH *C.int, maxW C.int) C.int {
	sz := noxClient.r.GetStringSizeWrappedStyle(asFont(font), GoWString(sp), int(maxW))
	if outW != nil {
		*outW = C.int(sz.X)
	}
	if outH != nil {
		*outH = C.int(sz.Y)
	}
	return C.int(bool2int(sz != (image.Point{})))
}

//export nox_xxx_drawString_43F6E0
func nox_xxx_drawString_43F6E0(font unsafe.Pointer, sp *C.wchar_t, x, y C.int) C.int {
	return C.int(noxClient.r.DrawString(asFont(font), GoWString(sp), image.Point{X: int(x), Y: int(y)}))
}

//export nox_draw_drawStringHL_43F730
func nox_draw_drawStringHL_43F730(font unsafe.Pointer, sp *C.wchar_t, x, y C.int) C.int {
	return C.int(noxClient.r.DrawStringHL(asFont(font), GoWString(sp), image.Point{X: int(x), Y: int(y)}))
}

//export nox_xxx_drawStringWrap_43FAF0
func nox_xxx_drawStringWrap_43FAF0(font unsafe.Pointer, sp *C.wchar_t, x, y, maxW, maxH C.int) C.int {
	return C.int(noxClient.r.DrawStringWrapped(asFont(font), GoWString(sp), image.Rect(int(x), int(y), int(x+maxW), int(y+maxH))))
}

//export nox_xxx_drawStringWrapHL_43FD00
func nox_xxx_drawStringWrapHL_43FD00(font unsafe.Pointer, sp *C.wchar_t, x, y, maxW, maxH C.int) C.int {
	return C.int(noxClient.r.DrawStringWrappedHL(asFont(font), GoWString(sp), image.Rect(int(x), int(y), int(x+maxW), int(y+maxH))))
}

//export nox_xxx_bookDrawString_43FA80_43FD80
func nox_xxx_bookDrawString_43FA80_43FD80(font unsafe.Pointer, s *C.wchar_t, x, y, maxW, maxH C.int) C.int {
	return C.int(noxClient.r.DrawStringWrappedStyle(asFont(font), GoWString(s), image.Rect(int(x), int(y), int(x+maxW), int(y+maxH))))
}

//export nox_xxx_drawStringStyle_43F7B0
func nox_xxx_drawStringStyle_43F7B0(font unsafe.Pointer, sp *C.wchar_t, x, y C.int) C.int {
	return C.int(noxClient.r.DrawStringStyle(asFont(font), GoWString(sp), image.Point{X: int(x), Y: int(y)}))
}

//export nox_video_drawAnimatedImageOrCursorAt_4BE6D0
func nox_video_drawAnimatedImageOrCursorAt_4BE6D0(a1, a2, a3 C.int) {
	noxClient.nox_video_drawAnimatedImageOrCursorAt(asImageRefP(unsafe.Pointer(uintptr(a1))), image.Point{X: int(a2), Y: int(a3)})
}

func (c *Client) nox_video_drawAnimatedImageOrCursorAt(ref *noxImageRef, pos image.Point) {
	if v3 := c.getCursorAnimFrame(ref, 0); v3 != nil {
		if dword_5d4594_3798728 {
			c.r.noxDrawCursor(v3, pos)
		} else {
			c.r.DrawImageAt(v3, pos)
		}
	}
}

func (c *Client) nox_xxx_client_435F80_draw() bool {
	mpos := c.inp.GetMousePos()
	if C.nox_xxx_serverIsClosing_446180() != 0 {
		C.sub_446190()
	}
	if c.keyBindingsCheckActive() == 0 && !noxflags.HasGame(noxflags.GameFlag4) {
		nox_xxx_setContinueMenuOrHost_43DDD0(0)
		return false
	}
	C.sub_437100()
	if C.sub_478030() == 0 && nox_xxx_guiCursor_477600() == 0 {
		C.sub_470DE0()
	}
	ctrlEvent.nox_xxx_input_42D220(c.inp)
	if C.nox_xxx_get_430890() == 1 {
		C.sub_430880(0)
	}
	C.nox_xxx_clientEnumHover_476FA0()
	vp := c.Viewport()
	ipos := vp.ToWorldPos(mpos)
	if !clientSendInput(noxMaxPlayers-1, uint16(ipos.X), uint16(ipos.Y)) {
		return true
	}
	if !noxflags.HasGame(noxflags.GameHost) {
		C.sub_40B970()
		C.sub_40B790()
	}
	if noxflags.HasGame(noxflags.GameHost) {
		C.nox_xxx_spriteDeleteSomeList_49C4B0()
		if C.nox_netlist_receiveCli_494E90(noxMaxPlayers-1) == 0 {
			return true
		}
	} else {
		C.sub_43CCA0()
	}
	C.sub_49BD70(vp.C())
	C.sub_49BBC0()
	C.nox_xxx_polygonDrawColor_421B80()
	if nox_client_isConnected() {
		C.nox_xxx_cliToggleObsWindow_4357A0()
	}
	c.nox_xxx_clientDrawAll_436100_draw()
	C.sub_49BB40()
	C.sub_49BA70()
	c.maybeScreenshot()
	if memmap.Uint32(0x5D4594, 826068) != 0 {
		C.nox_xxx_motd_4467F0()
	}
	if C.sub_42EBA0() == 1 {
		C.sub_42EB90(0)
		C.nox_xxx_consoleEsc_49B7A0()
	}
	C.sub_49B6E0()
	return C.int(memmap.Uint32(0x587000, 85720)) != 0
}

func (c *Client) nox_xxx_clientDrawAll_436100_draw() {
	v0 := platformTicks()
	isTick := false
	if int(v0-memmap.Uint64(0x5D4594, 814532)) >= int(memmap.Int32(0x587000, 85748)) {
		isTick = true
		nox_ticks_reset_416D40()
	}
	if !(memmap.Uint32(0x587000, 85724) == 0 || isTick || !noxflags.HasGame(noxflags.GameHost) || nox_ticks_getNext() >= 0 ||
		C.nox_client_gui_flag_815132 != 0 || nox_xxx_checkGameFlagPause_413A50() || noxflags.HasEngine(noxflags.EngineNoRendering)) {
		noxflags.SetEngine(noxflags.EnginePause)
		return
	}
	noxflags.UnsetEngine(noxflags.EnginePause)
	*memmap.PtrUint64(0x5D4594, 814532) = v0
	*memmap.PtrUint32(0x5D4594, 811916) = gameFrame()
	vp := c.Viewport()
	if memmap.Uint32(0x587000, 85744) != 0 {
		vp.Size.Y = vp.Size.X * nox_win_height / nox_win_width
		sx := (nox_win_width - vp.Size.X) / 2
		sy := (nox_win_height - vp.Size.Y) / 2
		vp.Screen.Min.X = sx
		vp.Screen.Min.Y = sy
		vp.Screen.Max.X = sx + vp.Size.X - 1
		vp.Screen.Max.Y = sy + vp.Size.Y - 1
	}
	C.sub_430B50(C.int(vp.Screen.Min.X), C.int(vp.Screen.Min.Y), C.int(vp.Screen.Max.X), C.int(vp.Screen.Max.Y))
	if id := clientPlayerNetCode(); id != 0 {
		*memmap.PtrPtr(0x852978, 8) = unsafe.Pointer(C.nox_xxx_netSpriteByCodeDynamic_45A6F0(C.int(id)))
	}
	if noxflags.HasEngine(noxflags.EngineNoRendering) {
		C.nox_xxx_clientDrawAll_436100_draw_A()
	} else if memmap.Uint32(0x852978, 8) != 0 && nox_client_isConnected() {
		c.nox_xxx_drawAllMB_475810_draw(vp)
		C.nox_xxx_drawMinimapAndLines_4738E0()
	} else {
		c.r.ClearScreen(color.Black)
	}
	noxPerfmon.Draw(c.r)
	if C.dword_5d4594_811904 != 0 {
		C.sub_436F50()
	}
	if noxflags.HasGame(noxflags.GameFlag4) {
		v13 := platformTicks() - memmap.Uint64(0x5D4594, 811908)
		if v13 > 10000 && !noxflags.HasGame(noxflags.GameHost) {
			noxflags.UnsetGame(noxflags.GameFlag4)
		}
	}
	if noxflags.HasGame(noxflags.GameFlag4) {
		C.nox_xxx_clientDrawAll_436100_draw_B()
	}
	if memmap.Uint32(0x587000, 85744) != 0 {
		C.sub_430B50(0, 0, C.int(nox_win_width-1), C.int(nox_win_height-1))
		c.r.ClearScreen(color.Black)
		*memmap.PtrUint32(0x587000, 85744) = 0
	}
}

func (c *Client) nox_xxx_drawAllMB_475810_draw_A(vp *Viewport) {
	if *memmap.PtrUint32(0x5D4594, 1096448) == 0 {
		*memmap.PtrUint32(0x5D4594, 1096448) = uint32(nox_things.IndByID("Crown"))
	}
	c.sub_477F80()
	*memmap.PtrUint32(0x973F18, 68) = 0
	r := c.r
	if vp.Screen.Min.X != 0 {
		C.dword_5d4594_3799468 = 1
		x := vp.Screen.Max.X + 1
		y := vp.Screen.Max.Y
		r.setRectFullScreen()
		if C.dword_5d4594_3799524 != 0 {
			rect := r.PixBufferRect()
			cl := color.Black
			r.DrawRectFilledOpaque(0, 0, rect.Dx(), vp.Screen.Min.Y, cl)
			r.DrawRectFilledOpaque(0, y, rect.Dx(), rect.Dy()-y, cl)
			r.DrawRectFilledOpaque(0, vp.Screen.Min.Y, vp.Screen.Min.X, y-vp.Screen.Min.Y, cl)
			r.DrawRectFilledOpaque(x, vp.Screen.Min.Y, rect.Dx()-x, y-vp.Screen.Min.Y, cl)
			C.dword_5d4594_3799524 = 0
		}
		r.DrawBorder(vp.Screen.Min.X-2, vp.Screen.Min.Y-2, x-vp.Screen.Min.X+4, y-vp.Screen.Min.Y+4, nox_color_gray2)
	} else {
		C.dword_5d4594_3799468 = 0
	}
	r.setClipRects(vp.Screen.Min, vp.Size)
}

func (c *Client) nox_xxx_drawAllMB_475810_draw(vp *Viewport) {
	r := c.r
	c.nox_xxx_drawAllMB_475810_draw_A(vp)
	if vp.field_12 < 0 {
		vp.field_12 = -1 - vp.field_12
	} else if vp.field_12 > 0 {
		vp.field_12 = 1 - vp.field_12
	}
	partViewportOff = vp.ToWorldPos(image.Pt(0, 0))
	xmin := int(vp.World.Min.X) / common.GridStep
	ymin := int(vp.World.Min.Y) / common.GridStep
	nox_wallsYyy = nox_wallsYyy[:0]
	C.nox_xxx_drawBlack_496150(vp.C())
	disableDraw := false
	if asDrawable((*nox_drawable)(*memmap.PtrPtr(0x852978, 8))).HasEnchant(ENCHANT_BLINDED) || C.nox_gameDisableMapDraw_5d4594_2650672 != 0 {
		disableDraw = true
	}
	if C.nox_client_gui_flag_1556112 != 0 || disableDraw {
		r.ClearScreen(color.Black)
		r.setRectFullScreen()
		C.dword_5d4594_3799524 = 1
		return
	}
	if memmap.Uint32(0x5D4594, 1096520) != 0 {
		r.ClearScreen(color.White)
		*memmap.PtrUint32(0x5D4594, 1096520) = 0
		r.setRectFullScreen()
		C.dword_5d4594_3799524 = 1
		return
	}
	sub_468F80(vp)
	v10 := C.nox_xxx_drawAllMB_475810_draw_B(vp.C()) != 0
	C.sub_4765F0(vp.C())
	sub_4754F0(vp)
	if v10 {
		c.nox_xxx_tileDrawMB_481C20(vp)
		C.sub_4C5500(vp.C())
	} else {
		r.ClearScreen(color.Black)
	}
	c.sub_475F10(vp)
	nox_client_queueWallsDraw(vp, xmin, ymin)
	nox_client_drawBackWalls(vp)
	c.sub_475FE0(vp)
	C.nox_video_drawCursorSelectCircle_4773C0(vp.C())
	c.nox_xxx_drawAllMB_475810_draw_E(vp)
	r.partfx.Draw()
	C.sub_4C5060(vp.C())
	nox_client_maybeDrawFrontWalls(vp)
	r.DrawFade(false)
	if noxflags.HasEngine(noxflags.EngineShowAI) {
		drawDebugAI(vp)
	}
	C.sub_45AB40()
	r.setRectFullScreen()
	*memmap.PtrUint32(0x973F18, 68) = 1
	C.sub_476680()
}

type RGB struct {
	R, G, B int
}

func nox_xxx_get_57AF20() int {
	return int(C.dword_5d4594_2523804)
}

func sub_468F80(vp *Viewport) {
	// TODO: values here are similar to lightGridW and lightGridH
	noxTilesGpx = (2*common.GridStep)*((int(vp.World.Min.X)+11)/(2*common.GridStep)-1) - 11
	noxTilesGpy = (2*common.GridStep)*((int(vp.World.Min.Y)+11)/(2*common.GridStep)) - 57
	C.dword_5d4594_2650676 = C.uint(noxTilesGpx)
	C.dword_5d4594_2650680 = C.uint(noxTilesGpy)
	if noxflags.HasEngine(noxflags.EngineNoSoftLights) {
		for i := 0; i < lightGridW; i++ {
			for j := 0; j < lightGridH; j++ {
				nox_arr2_853BC0[i][j].R = 255 << 16
				nox_arr2_853BC0[i][j].G = 255 << 16
				nox_arr2_853BC0[i][j].B = 255 << 16
			}
		}
	} else {
		cl := noxClient.r.Data().GetLightColor()
		if nox_xxx_get_57AF20() != 0 {
			cl = RGB{R: 50, G: 50, B: 50}
		}
		for i := 0; i < lightGridW; i++ {
			for j := 0; j < lightGridH; j++ {
				nox_arr2_853BC0[i][j].R = cl.R << 16
				nox_arr2_853BC0[i][j].G = cl.G << 16
				nox_arr2_853BC0[i][j].B = cl.B << 16
			}
		}
		const add = 100
		padd := image.Pt(add, add)
		rect := image.Rectangle{
			Min: vp.World.Min.Sub(padd),
			Max: vp.World.Min.Add(vp.Size).Add(padd),
		}
		nox_xxx_forEachSprite(rect, nox_xxx_cliLight16_469140)
	}
}

func sub_484BD0() float32 {
	return lightMinIntensity
}

const (
	dword_587000_142328 = 0x40000
	dword_587000_142316 = 0x40000
	lightMinIntensity   = 1.0
	qword_581450_9552   = 0x10000
	qword_581450_9544   = 0.5
)

func nox_xxx_cliLight16_469140(dr *Drawable) {
	if !(drawableUpdateLight(dr) || dr.Flags28()&0x80000 != 0 && dr.Flags30()&0x1000000 != 0 && dr.light_intensity_rad > 0 && dr.Flags30()&0x4 != 0) {
		return
	}
	if !(nox_xxx_get_57AF20() == 0 || unsafe.Pointer(dr.C()) == *memmap.PtrPtr(0x852978, 8) || unsafe.Pointer(dr.draw_func) == C.nox_thing_glow_orb_draw) {
		return
	}
	intens := int(dr.light_intensity_u16)
	rad := int(dr.light_intensity_rad)
	if dr.Flags30()&0x20000000 != 0 {
		intens += randomIntMinMax(0, int(dr.light_intensity_u16)>>18) << 16
		rad = lightRadius(float32(intens) / 0x10000)
	}
	if intens <= int(sub_484BD0()*0x10000) {
		return
	}
	intens2 := intens
	if max := int(memmap.Int32(0x587000, 142320)); intens2 > max {
		intens2 = max
	}
	pos := dr.Pos()
	xx := pos.X - noxTilesGpx
	yy := pos.Y - noxTilesGpy
	a4 := image.Pt(xx, yy)
	if dr.field_42 == 0xFFFF {
		dlimit := rad * rad

		xmin := (xx - rad) / common.GridStep
		if xmin < 0 {
			xmin = 0
		}

		xmax := (xx + rad) / common.GridStep
		if xmax > lightGridW-1 {
			xmax = lightGridW - 1
		}

		ymin := (yy - rad) / common.GridStep
		if ymin < 0 {
			ymin = 0
		}

		ymax := (yy + rad) / common.GridStep
		if ymax > lightGridH-1 {
			ymax = lightGridH - 1
		}

		v36 := (intens >> 16) * (intens >> 16)
		for y := ymin; y <= ymax; y++ {
			dy := yy - common.GridStep*y
			dy2 := dy * dy
			for x := xmin; x <= xmax; x++ {
				dx := xx - common.GridStep*x
				dx2 := dx * dx
				if dist := dx2 + dy2; dist <= dlimit {
					intens3 := sub_4C1C70(intens2+dword_587000_142328, 66*dist*int(memmap.Uint32(0x587000, 142324))/v36+0x10000)
					if intens3 > dword_587000_142328 {
						sub_4695E0(x, y, (*int32)(unsafe.Pointer(&dr.light_color_r)), 8*(intens3-dword_587000_142328), dr.field_43 != 0)
					}
					xx = a4.X
					yy = a4.Y
				}
			}
		}
	} else {
		a1 := image.Pt(
			(xx<<16)/common.GridStep,
			(yy<<16)/common.GridStep,
		)
		v19 := (rad << 16) / common.GridStep
		v22 := sub_4C1C60(v19, 16*int(memmap.Uint32(0x85B3FC, 12260+4*uintptr(uint16(dr.field_41_0+0x4000)>>4))))
		v23 := sub_4C1C60(v19, 16*int(memmap.Uint32(0x85B3FC, 12260+4*uintptr(uint16(dr.field_41_0)>>4))))

		v22b := uint16(dr.field_41_0) + uint16(dr.field_41_1)
		a3 := a1.Add(image.Pt(v22, v23))
		v44 := sub_4C1C60(v19, 16*int(memmap.Uint32(0x85B3FC, 12260+4*uintptr((v22b+0x4000)>>4))))
		v24 := sub_4C1C60(v19, 16*int(memmap.Uint32(0x85B3FC, 12260+4*uintptr(v22b>>4))))

		v22b = uint16(dr.field_41_0) + uint16(dr.field_41_1)
		a2 := a1.Add(image.Pt(v44, v24))
		v45 := sub_4C1C60(v19, 16*int(memmap.Uint32(0x85B3FC, 12260+4*uintptr((v22b+0x4000)>>4))))
		v25 := sub_4C1C60(v19, 16*int(memmap.Uint32(0x85B3FC, 12260+4*uintptr(v22b>>4))))

		v42 := a1.Add(image.Pt(v45, v25))
		sub_4696B0(a1, a2, a3, a4, intens, (*int32)(unsafe.Pointer(&dr.light_color_r)))
		sub_4696B0(a1, a3, v42, a4, intens, (*int32)(unsafe.Pointer(&dr.light_color_r)))
	}
}

func sub_467430() byte {
	return memmap.Uint8(0x5D4594, 1062536)
}

func drawableUpdateLight(dr *Drawable) bool {
	if dr.HasEnchant(ENCHANT_INVULNERABLE) {
		dr.SetLightColor(128, 128, 255)
		dr.SetLightIntensity(300.0)
		return true
	} else if dr.HasEnchant(ENCHANT_LIGHT) || unsafe.Pointer(dr.C()) == *memmap.PtrPtr(0x852978, 8) && sub_467430()&8 != 0 {
		dr.SetLightColor(255, 255, 255)
		dr.SetLightIntensity(200.0)
		return true
	} else if dr.Flags28()&0x2 == 0 || dr.Flags28()&0x80000 != 0 {
		return false
	} else if dr.field_69 == 10 {
		dr.SetLightIntensity(0.0)
		return true
	}
	dr.SetLightColor(255, 255, 255)
	if dr.Flags29()&0x1 != 0 {
		dr.SetLightIntensity(25.0)
	} else if dr.Flags29()&0x2 != 0 {
		dr.SetLightIntensity(35.0)
	} else if dr.Flags29()&0x4 != 0 {
		dr.SetLightIntensity(45.0)
	}
	return true
}

//export sub_484C60
func sub_484C60(a1 C.float) C.int {
	return C.int(lightRadius(float32(a1)))
}

func lightRadius(intens float32) int {
	if intens <= lightMinIntensity {
		return 0
	}
	intens2 := intens
	if intens2 > 31.0 {
		intens2 = 31.0
	}
	return int(math.Sqrt(float64(((memmap.Float32(0x587000, 154980)+intens2)/
		(memmap.Float32(0x587000, 154980)+lightMinIntensity) + 1.0) *
		(intens * intens / (memmap.Float32(0x587000, 154976) * memmap.Float32(0x587000, 154972))))))
}

func sub_4C1C70(a1, a2 int) int {
	return int((uint64(a1) << 16) / uint64(a2))
}

func sub_4696B0(a1, a2, a3, a4 image.Point, a5 int, pcl *int32) {
	var v8, v9, v10 image.Point
	if a1.Y > a2.Y {
		if a2.Y <= a3.Y {
			v9 = a2
			v10 = a3
			v8 = a1
		} else {
			v9 = a3
			v10 = a1
			v8 = a2
		}
	} else {
		if a1.Y <= a3.Y {
			v9 = a1
			v10 = a2
			v8 = a3
		} else {
			v9 = a3
			v10 = a1
			v8 = a2
		}
	}
	var v13, v14, v15 [2 * common.GridStep]int
	sub_484DC0(v9, v10, v15[:])
	sub_484DC0(v9, v8, v14[:])
	sub_4697C0(v15[:], v14[:], a4, a5, pcl)
	if v10.Y < v8.Y {
		sub_484DC0(v10, v8, v13[:])
		sub_4697C0(v13[:], v14[:], a4, a5, pcl)
	} else if v10.Y > v8.Y {
		sub_484DC0(v8, v10, v13[:])
		sub_4697C0(v15[:], v13[:], a4, a5, pcl)
	}
}

func sub_4697C0(a1, a2 []int, a3 image.Point, a4 int, a5 *int32) {
	v0 := a1[0]
	v7 := a1[0] + a1[1]
	if a1[0] < a2[0] {
		v0 = a2[0]
	}
	if v7 > a2[1]+a2[0] {
		v7 = a2[1] + a2[0]
	}
	if v7-v0 <= 1 {
		return
	}
	v23 := a4
	if max := int(memmap.Int32(0x587000, 142308)); v23 > max {
		v23 = max
	}
	if v0 >= v7 {
		return
	}
	v21 := (a4 >> 16) * (a4 >> 16)
	v8 := common.GridStep*v0 - a3.Y
	v12 := dword_587000_142316
	for ii := v0; ii < v7; ii++ {
		v10 := &a2[ii+2]
		v13 := a1[ii+2]
		v14 := common.GridStep*v13 - a3.X
		if v13 < *v10 {
			v16 := v8 * v8
			for jj := v13; jj < *v10; jj++ {
				v17 := sub_4C1C70(v12+v23, 66*int(memmap.Uint32(0x587000, 142312))*(v16+v14*v14)/v21+0x10000)
				v12 = dword_587000_142316
				if v17 > dword_587000_142316 {
					sub_4695E0(jj, ii, a5, 8*(v17-dword_587000_142316), false)
					v12 = dword_587000_142316
				}
				v14 += common.GridStep
			}
		}
		v0 = v7
		v8 += common.GridStep
	}
}

func sub_484DC0(a1, a2 image.Point, a3 []int) {
	a3[0] = (a1.Y + 0x8000) >> 16
	a3[1] = ((a2.Y + 0x8000) >> 16) - a3[0] + 1
	if a3[1] <= 0 {
		return
	}
	dn := (a2.X - a1.X) / a3[1]
	v6 := a3[0] + a3[1]
	if int(a3[0]) < 0 {
		a3[0] = 0
		a3[1] = v6
	}
	if v6 > 44 {
		a3[1] += 44 - v6
		v6 = 44
	}
	v7 := a3[0]
	if v7 >= v6 {
		return
	}
	v8 := a1.X + 0x8000
	v9 := a3[v7+2:]
	for v10 := v6 - v7; v10 != 0; v10-- {
		v9[0] = v8 >> 16
		if v8>>16 < 0 {
			v9[0] = 0
		}
		if v9[0] >= 56 {
			v9[0] = 55
		}
		v8 += dn
		v9 = v9[1:]
	}
}

//export sub_469920
func sub_469920(p *C.nox_point) *C.char {
	if noxflags.HasEngine(noxflags.EngineNoSoftLights) {
		return (*C.char)(unsafe.Pointer(&lightsOutBuf[0]))
	}

	x := int(int32(p.x) - int32(noxTilesGpx))
	y := int(int32(p.y) - int32(noxTilesGpy))

	xd := x / lightGrid
	yd := y / lightGrid
	if xd < 0 || yd < 0 || xd+1 >= lightGridW || yd+1 >= lightGridH {
		return (*C.char)(unsafe.Pointer(&lightsOutBuf[0]))
	}

	xr := x % lightGrid
	yr := y % lightGrid

	c00 := nox_arr2_853BC0[xd+0][yd+0]
	c10 := nox_arr2_853BC0[xd+1][yd+0]
	c01 := nox_arr2_853BC0[xd+0][yd+1]
	c11 := nox_arr2_853BC0[xd+1][yd+1]

	var cr1 RGB
	cr1.R = c00.R + xr*(c10.R-c00.R)/lightGrid
	cr1.G = c00.G + xr*(c10.G-c00.G)/lightGrid
	cr1.B = c00.B + xr*(c10.B-c00.B)/lightGrid

	var cr2 RGB
	cr2.R = c01.R + xr*(c11.R-c01.R)/lightGrid
	cr2.G = c01.G + xr*(c11.G-c01.G)/lightGrid
	cr2.B = c01.B + xr*(c11.B-c01.B)/lightGrid

	var res RGB
	res.R = cr1.R + yr*(cr2.R-cr1.R)/lightGrid
	res.G = cr1.G + yr*(cr2.G-cr1.G)/lightGrid
	res.B = cr1.B + yr*(cr2.B-cr1.B)/lightGrid

	dst := lightsOutBuf[3:]
	dst[0] = uint32(res.R >> 16)
	dst[1] = uint32(res.G >> 16)
	dst[2] = uint32(res.B >> 16)
	return (*C.char)(unsafe.Pointer(&dst[0]))
}

func noxTileUpdateLightXxx(p image.Point) {
	c1 := nox_arr2_853BC0[p.X][p.Y+0]
	c1r := c1.R >> 8
	c1g := c1.G >> 8
	c1b := c1.B >> 8

	c2 := nox_arr2_853BC0[p.X][p.Y+1]
	c2r := c2.R >> 8
	c2g := c2.G >> 8
	c2b := c2.B >> 8

	dcr := nox_light_8529A0[255+(c2r-c1r)>>8]
	dcg := nox_light_8529A0[255+(c2g-c1g)>>8]
	dcb := nox_light_8529A0[255+(c2b-c1b)>>8]

	for i := 0; i < lightGrid; i++ {
		nox_arr_84EB20[p.X].Cl[i] = RGB{R: c1r, G: c1g, B: c1b}
		c1r += dcr
		c1g += dcg
		c1b += dcb
	}
	nox_arr_84EB20[p.X].Y = p.Y
}

func sub_4C1C60(a1, a2 int) int {
	return int((int64(a1) * int64(a2)) >> 16)
}

func sub_4695E0(a1, a2 int, pcl *int32, a4 int, flip bool) {
	v5 := a4
	if flip {
		v5 = -a4
	}
	a3 := unsafe.Slice(pcl, 3)
	v6 := sub_4C1C60(v5, int(a3[0])) << 8
	v7 := sub_4C1C60(v5, int(a3[1])) << 8
	v8 := sub_4C1C60(v5, int(a3[2])) << 8

	ptr := &nox_arr2_853BC0[a1][a2]

	var res RGB
	res.R = v6 + ptr.R
	res.G = v7 + ptr.G
	res.B = v8 + ptr.B

	if res.R <= 0xFF0000 {
		if res.R < 0 {
			res.R = 0
		}
	} else {
		res.R = 0xFF0000
	}
	if res.G <= 0xFF0000 {
		if res.G < 0 {
			res.G = 0
		}
	} else {
		res.G = 0xFF0000
	}
	if res.B <= 0xFF0000 {
		if res.B < 0 {
			res.B = 0
		}
	} else {
		res.B = 0xFF0000
	}
	*ptr = res
}

func (c *Client) nox_xxx_tileDrawMB_481C20(vp *Viewport) {
	C.nox_xxx_waypointCounterMB_587000_154948++
	dp := vp.ToWorldPos(image.Pt(0, 0))
	if !nox_client_texturedFloors_154956 && C.dword_5d4594_1193156 == 1 {
		nox_client_texturedFloors2_154960 = false
		nox_client_texturedFloors_154956 = true
		nox_xxx_tileSetDrawFn_481420()
	}
	if C.dword_5d4594_1193156 == 1 && !nox_client_texturedFloors2_154960 && gameFrame()%30 == 0 && C.nox_xxx_tileCheckRedrawMB_482570(vp.C()) == 0 {
		C.dword_5d4594_1193156 = 0
		nox_client_texturedFloors_154956 = nox_client_texturedFloors2_154960
		nox_xxx_tileSetDrawFn_481420()
	}
	if C.dword_5d4594_1193188 != 0 {
		C.nox_xxx_tileDrawImpl_4826A0(vp.C())
		C.dword_5d4594_1193188 = 0
	} else {
		C.nox_xxx_tileDrawMB_481C20_A(vp.C(), C.int(dp.X))
		C.nox_xxx_tileDrawMB_481C20_B(vp.C(), C.int(dp.Y))
	}
	if nox_client_texturedFloors_154956 {
		c.nox_xxx_tileDrawMB_481C20_C_textured(vp, dp)
	} else {
		C.nox_xxx_tileDrawMB_481C20_C_solid(vp.C(), C.int(dp.X), C.int(dp.Y))
	}
}

func nox_xxx_setupSomeVideo_47FEF0() {
	*memmap.PtrPtr(0x973F18, 7716) = C.sub_480250
	*memmap.PtrPtr(0x973F18, 5248) = C.sub_480220
	*memmap.PtrUint32(0x5D4594, 2598128) = 0
	*memmap.PtrUint32(0x5D4594, 2598160) = 0
	*memmap.PtrUint32(0x5D4594, 2598132) = 0
	*memmap.PtrUint32(0x5D4594, 2598136) = 0
	*memmap.PtrUint32(0x5D4594, 2598168) = 0
	*memmap.PtrUint32(0x5D4594, 2598144) = 0
	*memmap.PtrUint32(0x5D4594, 2598176) = 0
	*memmap.PtrUint32(0x5D4594, 2598152) = 0
	*memmap.PtrUint32(0x5D4594, 2598184) = 0
	*memmap.PtrUint32(0x5D4594, 2598124) = 7
	*memmap.PtrUint32(0x5D4594, 2598156) = 2
	*memmap.PtrUint32(0x5D4594, 2598164) = 5
	*memmap.PtrUint32(0x5D4594, 2598140) = 8
	*memmap.PtrUint32(0x5D4594, 2598172) = 3
	*memmap.PtrUint32(0x5D4594, 2598148) = 8
	*memmap.PtrUint32(0x5D4594, 2598180) = 3
}

func nox_xxx_initSight_485F80() {
	v0 := 0
	v1 := 0
	v2 := 1
	for i := common.GridStep; i > 0; i-- {
		*memmap.PtrUint32(0x973CE0, 0+4*uintptr(v1)) = uint32(v0)
		*memmap.PtrUint32(0x973CE0, 192+4*uintptr(v1)) = uint32(i)
		*memmap.PtrUint32(0x973CE0, 384+4*uintptr(v1)) = uint32(v2)
		v0 += v2
		v1++
		v2 += 2
	}
	if v1 < 2*common.GridStep {
		v4 := 91 - 2*v1
		v5 := v1 - 22
		v6 := 4 * v1
		for v7 := 2*common.GridStep - v1; v7 != 0; v7-- {
			*memmap.PtrUint32(0x973CE0, 0+uintptr(v6)) = uint32(v0)
			*memmap.PtrUint32(0x973CE0, 192+uintptr(v6)) = uint32(v5)
			*memmap.PtrUint32(0x973CE0, 384+uintptr(v6)) = uint32(v4)
			v0 += v4
			v5++
			v4 -= 2
			v6 += 4
		}
	}

	for i := 0; i < 253; i++ {
		nox_light_8529A0[i] = ((i - 253) * 256) / 22
	}
	nox_light_8529A0[256] = 0
	for i := 0; i < 256; i++ {
		nox_light_8529A0[255+i] = (i * 256) / 22
	}
}

var (
	dword_5d4594_3798812 int
	dword_5d4594_3798800 int
	dword_5d4594_3798816 int
	dword_5d4594_3798808 int
	dword_5d4594_3798804 int
	noxTilesGpx          int
	noxTilesGpy          int
	noxTileBuf           []uint16
	noxTileBufFree       func()
)

func nox_xxx_tileInitBuf_430DB0(width, height int) {
	dword_5d4594_3798812 = width/(2*common.GridStep) + 4
	dword_5d4594_3798800 = (2 * common.GridStep) * dword_5d4594_3798812
	dword_5d4594_3798816 = height/(2*common.GridStep) + 3
	dword_5d4594_3798808 = (2 * common.GridStep) * dword_5d4594_3798816
	dword_5d4594_3798804 = ((2 * common.GridStep) * dword_5d4594_3798812) * 2

	C.dword_5d4594_3798812 = C.uint(dword_5d4594_3798812)
	C.dword_5d4594_3798800 = C.uint(dword_5d4594_3798800)
	C.dword_5d4594_3798816 = C.uint(dword_5d4594_3798816)
	C.dword_5d4594_3798808 = C.uint(dword_5d4594_3798808)
	C.dword_5d4594_3798804 = C.uint(dword_5d4594_3798804)

	C.dword_5d4594_3798820 = 0
	C.dword_5d4594_3798824 = 0
	C.dword_5d4594_3798828 = 0
	C.dword_5d4594_3798832 = 0
	C.dword_5d4594_3798836 = 0
	C.dword_5d4594_3798840 = 0

	sz := dword_5d4594_3798804 * (2 * common.GridStep) * dword_5d4594_3798816
	noxTileBuf, noxTileBufFree = alloc.Make([]uint16{}, sz/2)
	C.nox_video_tileBuf_ptr_3798796 = unsafe.Pointer(&noxTileBuf[0])
	C.nox_video_tileBuf_end_3798844 = unsafe.Add(unsafe.Pointer(&noxTileBuf[0]), sz)
}

//export nox_video_freeFloorBuffer_430EC0
func nox_video_freeFloorBuffer_430EC0() {
	if noxTileBuf != nil {
		noxTileBufFree()
		noxTileBuf = nil
		noxTileBufFree = nil
	}
	noxClient.sub_444C50()
}

func (c *Client) nox_xxx_tileDrawMB_481C20_C_textured(vp *Viewport, dp image.Point) {
	r := c.r

	sy := int(C.dword_5d4594_3679320)
	ymax := int(C.dword_5d4594_3798156)
	gpx := noxTilesGpx
	gpy := noxTilesGpy
	var v67 image.Point
	v67.Y = dp.Y + sy
	c.sub4745F0(vp)
	nox_arr_957820 := unsafe.Slice((*byte)(unsafe.Pointer(&C.nox_arr_957820[0])), len(C.nox_arr_957820))
	nox_arr_956A00 := unsafe.Slice((*uint32)(unsafe.Pointer(&C.nox_arr_956A00[0])), len(C.nox_arr_956A00))
	for i := range nox_arr_84EB20 {
		nox_arr_84EB20[i].Y = -1
	}
	var v66 image.Point
	v66.Y = (v67.Y - gpy) / common.GridStep
	v78 := v67.Y - common.GridStep*v66.Y - gpy
	pix := r.PixBuffer()
	for yy := sy; yy < ymax; yy++ {
		src := nox_arr_957820[128*yy:]
		if v78 == common.GridStep {
			v78 = 0
			v66.Y++
		}
		vv := int(nox_arr_956A00[yy])
		if C.nox_client_highResFloors_154952 != 0 || v67.Y&1 == 0 || yy == 0 {
			// high-res or each second row on low-res
			if vv > 0 {
				for jj := (vv + 1) / 2; jj != 0; jj-- {
					v1 := int(binary.LittleEndian.Uint32(src[0:]))
					v2 := int(binary.LittleEndian.Uint32(src[4:]))
					src = src[8:]

					v67.X = v1 + dp.X
					v66.X = (v1 + dp.X - gpx) / common.GridStep
					for kk := gpx + common.GridStep*v66.X; kk < v2+dp.X+common.GridStep; kk += common.GridStep {
						if nox_arr_84EB20[v66.X].Y != v66.Y {
							noxTileUpdateLightXxx(v66)
						}
						v66.X++
					}
					v66.X = (v1 + dp.X - gpx) / common.GridStep
					ind := pix.PixOffset(v1, yy)
					v66.X = c.noxTileDrawTextured(v67, v66.X, v78, v2-v1, pix.Pix[ind:])
				}
			}
		} else {
			// low-res floors basically skip each second row (interlacing) and then duplicate result from the first row
			if vv > 0 {
				for jj := (vv + 1) / 2; jj != 0; jj-- {
					v1 := int(binary.LittleEndian.Uint32(src[0:]))
					v2 := int(binary.LittleEndian.Uint32(src[4:]))
					src = src[8:]

					ind := pix.PixOffset(v1, yy)
					ind2 := pix.PixOffset(v1, yy-1)
					copy(pix.Pix[ind:], pix.Pix[ind2:ind2+(v2-v1)])
				}
			}
		}
		v78++
		v67.Y++
	}
}

func (c *Client) noxTileDrawTextured(a1 image.Point, a2 int, a3, sz int, dst []uint16) int {
	buf := noxTileBuf

	bi := (dword_5d4594_3798804/2)*(int(C.dword_5d4594_3798840)+a1.Y-int(C.dword_5d4594_3798824)) + (int(C.dword_5d4594_3798836) + a1.X - int(C.dword_5d4594_3798820))
	if bi >= len(buf) {
		bi -= len(buf)
	}
	if noxflags.HasEngine(noxflags.EngineNoSoftLights) {
		if bi+sz < len(buf) {
			copy(dst[:sz], buf[bi:bi+sz])
		} else {
			sz1 := len(buf) - bi
			sz2 := sz - sz1
			copy(dst[:sz1], buf[bi:bi+sz1])
			copy(dst[sz1:sz1+sz2], buf[:sz2])
		}
		return a2
	}
	mul := a1.X - common.GridStep*a2 - noxTilesGpx
	c1 := nox_arr_84EB20[a2].Cl[a3]
	c2 := nox_arr_84EB20[a2+1].Cl[a3]
	lr := nox_light_8529A0[255+(c2.R-c1.R)>>8]
	lg := nox_light_8529A0[255+(c2.G-c1.G)>>8]
	lb := nox_light_8529A0[255+(c2.B-c1.B)>>8]
	var csz int
	if mul <= 0 {
		csz = common.GridStep
	} else {
		c1.R += mul * lr
		c1.G += mul * lg
		c1.B += mul * lb
		csz = common.GridStep - mul
	}
	if csz > sz {
		csz = sz
	}
	for {
		bi = bi % len(buf)
		_ = dst[csz:]
		_ = buf[bi:]
		for i := 0; i < csz; i++ {
			cl := buf[bi%len(buf)]
			r := uint16((uint32(c1.R)*uint32((cl>>7)&0xF8))>>16) & 0xF8
			g := uint16((uint32(c1.G)*uint32((cl>>2)&0xF8))>>16) & 0xF8
			b := uint16((uint32(c1.B)*uint32((cl>>0)&0x1F))>>13) & 0xF8
			dst[i] = (r << 7) | (g << 2) | (b >> 3)

			bi++
			c1.R += lr
			c1.G += lg
			c1.B += lb
		}
		dst = dst[csz:]
		sz -= csz
		if sz <= 0 {
			break
		}
		csz = common.GridStep
		if sz < common.GridStep {
			csz = sz
		}
		a2++
		c1 = nox_arr_84EB20[a2].Cl[a3]
		c2 = nox_arr_84EB20[a2+1].Cl[a3]
		lr = nox_light_8529A0[255+(c2.R-c1.R)>>8]
		lg = nox_light_8529A0[255+(c2.G-c1.G)>>8]
		lb = nox_light_8529A0[255+(c2.B-c1.B)>>8]
	}
	return a2
}

func nox_xxx_tileSetDrawFn_481420() {
	if nox_client_texturedFloors_154956 {
		C.func_587000_154940 = (*[0]byte)(C.nox_xxx_tileDraw_4815E0)
		C.func_587000_154944 = (*[0]byte)(C.nox_xxx_drawTexEdgesProbably_481900)
	} else {
		C.func_587000_154940 = (*[0]byte)(C.sub_481770)
		C.func_587000_154944 = (*[0]byte)(C.nullsub_8)
	}
	C.dword_5d4594_1193188 = 1
}

func sub_4754F0(vp *Viewport) {
	rect := image.Rectangle{
		Min: vp.World.Min,
		Max: vp.World.Min.Add(vp.Size).Add(image.Pt(0, 128)),
	}
	nox_drawable_objects_queue = nox_drawable_objects_queue[:0]
	nox_drawable_list_3 = nox_drawable_list_3[:0]
	nox_drawable_list_2 = nox_drawable_list_2[:0]
	nox_drawable_list_4 = nox_drawable_list_4[:0]
	nox_backWalls = nox_backWalls[:0]
	nox_frontWalls = nox_frontWalls[:0]
	nox_xxx_forEachSprite(rect, nox_xxx_spriteAddQueue_475560_draw)
}

func nox_xxx_spriteAddQueue_475560_draw(dr *Drawable) {
	if C.nox_xxx_sprite_4756E0_drawable(dr.C()) != 0 {
		nox_drawable_list_2 = append(nox_drawable_list_2, dr)
		return
	}
	if C.nox_xxx_sprite_475740_drawable(dr.C()) != 0 {
		nox_drawable_list_3 = append(nox_drawable_list_3, dr)
		return
	}
	if C.nox_xxx_sprite_4757A0_drawable(dr.C()) != 0 {
		nox_drawable_list_4 = append(nox_drawable_list_4, dr)
		return
	}
	if C.sub_4757D0_drawable(dr.C()) != 0 {
		if C.nox_client_fadeObjects_80836 != 0 || unsafe.Pointer(dr.C()) == *memmap.PtrPtr(0x852978, 8) || C.nox_xxx_client_4984B0_drawable(dr.C()) != 0 {
			if dr.field_122 == 0 {
				if C.nox_xxx_client_4984B0_drawable(dr.C()) != 0 {
					dr.field_121 = 1
					dr.field_120 = 0
				} else {
					if dr.field_121 == 0 || (dr.flags28&0x6 != 0) {
						return
					}
					dr.field_120 = 1
				}
			}
			if (dr.field_120 != 0 || dr.field_122 != 0) && (gameFrame()-uint32(dr.field_85)) > gameFPS() {
				dr.field_120 = 0
			} else {
				nox_drawable_objects_queue = append(nox_drawable_objects_queue, dr)
			}
		}
	}
}

const (
	nox_drawable_list_1_cap = 8192
	nox_drawable_lists_cap  = 512

	noxDrawableWallsCap = 256
)

var (
	nox_drawable_objects_queue []*Drawable
	nox_drawable_list_3        []*Drawable
	nox_drawable_list_2        []*Drawable
	nox_drawable_list_4        []*Drawable

	nox_backWalls  []*Wall
	nox_frontWalls []*Wall
	nox_wallsYyy   []*Wall
)

func initDrawableLists() {
	nox_drawable_objects_queue = make([]*Drawable, 0, nox_drawable_list_1_cap)
	nox_drawable_list_3 = make([]*Drawable, 0, nox_drawable_lists_cap)
	nox_drawable_list_2 = make([]*Drawable, 0, nox_drawable_lists_cap)
	nox_drawable_list_4 = make([]*Drawable, 0, nox_drawable_lists_cap)

	nox_backWalls = make([]*Wall, 0, noxDrawableWallsCap)
	nox_frontWalls = make([]*Wall, 0, noxDrawableWallsCap)
	nox_wallsYyy = make([]*Wall, 0, noxDrawableWallsCap)
}

func sub_473B30_free() {
	nox_drawable_objects_queue = nil
	nox_drawable_list_3 = nil
	nox_drawable_list_2 = nil
	nox_drawable_list_4 = nil

	nox_backWalls = nil
	nox_frontWalls = nil
	nox_wallsYyy = nil
}

//export nox_xxx_drawList1096512_Append_4754C0
func nox_xxx_drawList1096512_Append_4754C0(p unsafe.Pointer) {
	nox_wallsYyy = append(nox_wallsYyy, asWall(p))
}

func nox_xxx_cliGetSpritePlayer_45A000() *Drawable {
	return asDrawable(C.nox_xxx_drawablePlayer_1046600)
}

func nox_client_queueWallsDraw(vp *Viewport, xmin, ymin int) { // nox_xxx_drawAllMB_475810_draw_C
	xmax := xmin + int(vp.Size.X)/common.GridStep + 2
	ymax := ymin + int(vp.Size.Y)/common.GridStep + 4
	for y := ymin; y <= ymax; y++ {
		for x := xmin; x <= xmax; x++ {
			wl := noxServer.getWallAtGrid(image.Point{X: x, Y: y})
			if wl == nil {
				continue
			}
			if memmap.Uint8(0x85B3FC, 43076+12332*uintptr(wl.tile()))&4 == 0 {
				if wl.field4()&2 != 0 {
					nox_frontWalls = append(nox_frontWalls, wl)
				} else {
					nox_backWalls = append(nox_backWalls, wl)
				}
			}
		}
	}
}

func nox_client_drawBackWalls(vp *Viewport) {
	for _, v20 := range nox_backWalls {
		nox_xxx_drawWalls_473C10(vp, v20)
	}
	nox_backWalls = nox_backWalls[:0]
}

func sub_476160(a1, a2 *Drawable) bool {
	var v1 int
	if *(*int8)(a1.field(112)) >= 0 {
		v1 = a1.Pos().Y + int(*(*int16)(a1.field(104)))
	} else {
		v1 = int(C.sub_4761B0(a1.C()))
	}
	var v2 int
	if *(*int8)(a2.field(112)) >= 0 {
		v2 = a2.Pos().Y + int(*(*int16)(a2.field(104)))
	} else {
		v2 = int(C.sub_4761B0(a2.C()))
	}
	return v1-v2 < 0
}

func (c *Client) nox_xxx_drawAllMB_475810_draw_E(vp *Viewport) {
	sort.Slice(nox_drawable_objects_queue, func(i, j int) bool {
		a, b := nox_drawable_objects_queue[i], nox_drawable_objects_queue[j]
		return sub_476160(a, b)
	})
	sort.Slice(nox_wallsYyy, func(i, j int) bool {
		a, b := nox_wallsYyy[i], nox_wallsYyy[j]
		return C.sub_476080((*C.uchar)(a.C())) < C.sub_476080((*C.uchar)(b.C()))
	})
	objects := nox_drawable_objects_queue
	walls := nox_wallsYyy
	sy := math.MaxInt32
	if len(objects) > 0 {
		sy = objects[0].Pos().Y
	}
	wy := math.MaxInt32
	if len(walls) > 0 {
		wy = int(C.sub_476080((*C.uchar)(walls[0].C())))
	}
LOOP:
	for len(objects) > 0 || len(walls) > 0 {
		if sy >= wy {
			if len(walls) != 0 {
				nox_xxx_drawWalls_473C10(vp, walls[0])
				walls = walls[1:]
				if len(walls) != 0 {
					wy = int(C.sub_476080((*C.uchar)(walls[0].C())))
					continue
				}
			}
			wy = math.MaxInt32
			continue
		}
		if len(objects) == 0 {
			sy = math.MaxInt32
			continue
		}
		dr := objects[0]
		objects = objects[1:]
		if len(objects) > 0 {
			sy = objects[0].Pos().Y
		} else {
			sy = math.MaxInt32
		}
		if uint32(dr.field_27) == memmap.Uint32(0x5D4594, 1096448) && nox_server_teamFirst_418B10() != nil {
			for v25 := nox_xxx_cliGetSpritePlayer_45A000(); v25 != nil; v25 = v25.Field104() {
				if v25.HasEnchant(ENCHANT_CROWN) {
					continue LOOP
				}
			}
		}
		v26 := dr.Flags28()
		if !((v26&6 == 0) || gameFrame()-uint32(dr.field_72) <= 5) {
			if v26&2 != 0 {
				v27 := dr.field_69
				if !(v27 == 9 || v27 == 10) {
					continue
				}
			} else if *memmap.PtrPtr(0x852978, 8) != unsafe.Pointer(dr.C()) {
				continue
			}
		}
		c.drawCreatureBackEffects(vp, dr)
		if dr.DrawFunc(vp) == 0 {
			continue
		}
		if noxflags.HasEngine(noxflags.EngineShowExtents) {
			nox_thing_debug_draw(vp.C(), dr.C())
		}
		dr.field_33 = 0
		if dr.Flags70()&0x40 != 0 {
			C.nox_xxx_drawShinySpot_4C4F40(vp.C(), dr.C())
		}
		c.drawCreatureFrontEffects(vp, dr)
		C.sub_495BB0(dr.C(), vp.C())
		if dr.field_120 == 0 && dr.field_122 == 0 {
			dr.field_85 = C.uint(gameFrame())
		}
		if C.sub_459DB0(dr.C()) != 0 {
			C.sub_459DD0(dr.C(), 1)
		}
		if dr.Flags28()&0x20006 != 0 {
			C.sub_49A6A0(vp.C(), dr.C())
		}
	}
	nox_drawable_objects_queue = nox_drawable_objects_queue[:0]
}

func (c *Client) sub_475FE0(vp *Viewport) {
	for _, dr := range nox_drawable_list_4 {
		if C.nox_xxx_client_4984B0_drawable(dr.C()) != 0 {
			dr.field_121 = 1
			dr.DrawFunc(vp)
			if noxflags.HasEngine(noxflags.EngineShowExtents) {
				nox_thing_debug_draw(vp.C(), dr.C())
			}
			dr.field_33 = 0
			if dr.field_120 == 0 && dr.field_122 == 0 {
				dr.field_85 = C.uint(gameFrame())
			}
		}
	}
	nox_drawable_list_4 = nox_drawable_list_4[:0]
}

func (c *Client) sub_475F10(vp *Viewport) {
	for _, dr := range nox_drawable_list_3 {
		c.drawCreatureBackEffects(vp, dr)
		if C.nox_xxx_client_4984B0_drawable(dr.C()) == 0 {
			continue
		}
		dr.field_121 = 1
		dr.DrawFunc(vp)
		if dr.Flags70()&0x40 != 0 {
			C.nox_xxx_drawShinySpot_4C4F40(vp.C(), dr.C())
		}
		c.drawCreatureFrontEffects(vp, dr)
		C.sub_495BB0(dr.C(), vp.C())
		if noxflags.HasEngine(noxflags.EngineShowExtents) {
			nox_thing_debug_draw(vp.C(), dr.C())
		}
		dr.field_33 = 0
		if dr.field_120 == 0 && dr.field_122 == 0 {
			dr.field_85 = C.uint(gameFrame())
		}
	}
	nox_drawable_list_3 = nox_drawable_list_3[:0]
}

func nox_xxx_drawWalls_473C10(vp *Viewport, p *Wall) {
	C.nox_xxx_drawWalls_473C10(vp.C(), p.C())
}

func nox_client_maybeDrawFrontWalls(vp *Viewport) { // nox_client_maybeDrawFrontWalls_475810_F
	if nox_client_drawFrontWalls_80812 {
		for _, wl := range nox_frontWalls {
			nox_xxx_drawWalls_473C10(vp, wl)
		}
	} else {
		for _, wl := range nox_frontWalls {
			*(*byte)(wl.field(3)) = 0
			*(*byte)(wl.field(4)) &= 0xFC
		}
	}
	nox_frontWalls = nox_frontWalls[:0]
}

//export sub_4745F0
func sub_4745F0(cvp *nox_draw_viewport_t) {
	noxClient.sub4745F0(asViewport(cvp))
}
func (c *Client) sub4745F0(vp *Viewport) {
	for _, dr := range nox_drawable_list_2 {
		c.drawCreatureBackEffects(vp, dr)
		if C.nox_xxx_client_4984B0_drawable(dr.C()) == 0 {
			continue
		}
		dr.field_121 = 1
		C.sub_476AE0(vp.C(), dr.C())
		if dr.Flags70()&0x40 != 0 {
			C.nox_xxx_drawShinySpot_4C4F40(vp.C(), dr.C())
		}
		c.drawCreatureFrontEffects(vp, dr)
		C.sub_495BB0(dr.C(), vp.C())
		if noxflags.HasEngine(noxflags.EngineShowExtents) {
			nox_thing_debug_draw(vp.C(), dr.C())
		}
		dr.field_33 = 0
		if dr.field_120 == 0 && dr.field_122 == 0 {
			dr.field_85 = C.uint(gameFrame())
		}
	}
	nox_drawable_list_2 = nox_drawable_list_2[:0]
}

//export nox_video_drawCircleColored_4C3270
func nox_video_drawCircleColored_4C3270(a1, a2, a3, a4 C.int) {
	noxClient.r.DrawCircle(int(a1), int(a2), int(a3), noxcolor.RGBA5551(a4))
}

//export nox_video_drawCircle_4B0B90
func nox_video_drawCircle_4B0B90(a1, a2, a3 C.int) {
	noxClient.r.DrawCircle(int(a1), int(a2), int(a3), noxClient.r.Data().Color2())
}

func (r *NoxRender) DrawImageAt(img *Image, pos image.Point) {
	defer func() {
		if r := recover(); r != nil {
			panic(fmt.Errorf("panic drawing image %v: %v", img, r))
		}
	}()
	if C.dword_5d4594_3799452 != 0 {
		C.nox_xxx_wndDraw_49F7F0()
		C.sub_49F780(C.int(memmap.Int32(0x973F18, 52)), C.int(memmap.Int32(0x973F18, 12)))
		r.p.useClip = 1
	}
	r.HookImageDrawXxx = func(pos image.Point, sz image.Point) {
		*memmap.PtrInt32(0x973F18, 92) = int32(pos.X)
		*memmap.PtrInt32(0x973F18, 84) = int32(pos.Y)
		*memmap.PtrUint32(0x973F18, 88) = uint32(sz.X)
		*memmap.PtrUint32(0x973F18, 76) = uint32(sz.Y)
	}
	if img != nil {
		r.DrawImage16(img, pos)
	}
	if C.dword_5d4594_3799452 != 0 {
		C.sub_49F860()
		C.dword_5d4594_3799452 = 0
	}
	r.Set_dword_5d4594_3799484(0)
	*memmap.PtrUint32(0x973F18, 120) = 0
	if memmap.Uint32(0x973F18, 68) != 0 && img != nil {
		if memmap.Uint32(0x973F18, 92) != uint32(img.field_1_0) || memmap.Uint32(0x973F18, 84) != uint32(img.field_1_1) {
			C.dword_5d4594_3799524 = 1
		}
		img.field_1_0 = uint16(memmap.Uint32(0x973F18, 92))
		img.field_1_1 = uint16(memmap.Uint32(0x973F18, 84))
	}
}

//export nox_client_drawImageAt_47D2C0
func nox_client_drawImageAt_47D2C0(img *nox_video_bag_image_t, x, y C.int) {
	noxClient.r.DrawImageAt(asImage(img), image.Point{X: int(x), Y: int(y)})
}

func sub_47D200() {
	noxClient.r.Set_dword_5d4594_3799484(0)
	*memmap.PtrUint32(0x973F18, 52) = 0
	*memmap.PtrUint32(0x973F18, 12) = 0
	noxClient.r.Reset_dword_5d4594_3799476()
	C.dword_5d4594_3799452 = 0
	*memmap.PtrUint32(0x973F18, 44) = 0
	*memmap.PtrUint32(0x973F18, 104) = 0
	*memmap.PtrUint32(0x973F18, 8) = 0
	*memmap.PtrUint32(0x973F18, 36) = 0
	*memmap.PtrUint32(0x973F18, 32) = 0
	*memmap.PtrUint32(0x973F18, 100) = 0
	*memmap.PtrUint32(0x973F18, 20) = 0
	*memmap.PtrUint32(0x973F18, 120) = 0
	*memmap.PtrUint32(0x973F18, 68) = 0
	C.dword_5d4594_3799524 = 0
	C.dword_5d4594_3799468 = 0
	noxClient.r.SetInterlacing(false, 0)
}

//export nox_draw_imageMeta_47D5C0
func nox_draw_imageMeta_47D5C0(img *nox_video_bag_image_t, px, py, pw, ph *C.uint) C.int {
	if img == nil {
		return 0
	}
	if pw != nil {
		*pw = 0
	}
	if ph != nil {
		*ph = 0
	}
	off, sz, ok := asImage(img).Meta()
	if !ok {
		return 0
	}
	if px != nil {
		*px += C.uint(off.X)
	}
	if py != nil {
		*py += C.uint(off.Y)
	}
	if pw != nil {
		*pw = C.uint(sz.X)
	}
	if ph != nil {
		*ph = C.uint(sz.Y)
	}
	return 1
}

//export nox_video_getImagePixdata_42FB30
func nox_video_getImagePixdata_42FB30(img *nox_video_bag_image_t) unsafe.Pointer {
	data := asImage(img).Pixdata()
	if len(data) == 0 {
		return nil
	}
	return unsafe.Pointer(&data[0])
}

func (r *NoxRender) initColorTables() {
	for i := 0; i < 256; i++ {
		r.colors.R[i] = noxcolor.RGB5551Color(byte(i), 0, 0).Color16()
		r.colors.G[i] = noxcolor.RGB5551Color(0, byte(i), 0).Color16()
		r.colors.B[i] = noxcolor.RGB5551Color(0, 0, byte(i)).Color16()
	}
}

func clipFlags(p image.Point, r image.Rectangle) int {
	flags := 0
	if p.X >= r.Min.X {
		if p.X > r.Max.X {
			flags |= 0x2
		}
	} else {
		flags |= 0x1
	}
	if p.Y >= r.Min.Y {
		if p.Y > r.Max.Y {
			flags |= 0x4
		}
	} else {
		flags |= 0x8
	}
	return flags
}

func clipToRect(r image.Rectangle, p1 *image.Point, p2 image.Point, side bool) bool {
	ds := +1
	if side {
		ds = -1
	}
	if p1.Y < r.Min.Y {
		if p1.Y == p2.Y {
			return false
		}
		dx := (r.Min.Y - p1.Y) * (ds * (p2.X - p1.X)) / (ds * (p2.Y - p1.Y))
		p1.Y = r.Min.Y
		p1.X += dx
	} else if p1.Y > r.Max.Y {
		if p1.Y == p2.Y {
			return false
		}
		dx := (r.Max.Y - p1.Y) * (ds * (p2.X - p1.X)) / (ds * (p2.Y - p1.Y))
		p1.Y = r.Max.Y
		p1.X += dx
	}
	if p1.X > r.Max.X {
		if p1.X == p2.X {
			return false
		}
		dy := (r.Max.X - p1.X) * (ds * (p2.Y - p1.Y)) / (ds * (p2.X - p1.X))
		p1.X = r.Max.X
		p1.Y += dy
	} else if p1.X < r.Min.X {
		if p1.X == p2.X {
			return false
		}
		dy := (r.Min.X - p1.X) * (ds * (p2.Y - p1.Y)) / (ds * (p2.X - p1.X))
		p1.X = r.Min.X
		p1.Y += dy
	}
	return true
}

func (r *NoxRender) clipToRect2(p1, p2 *image.Point) bool {
	d := r.Data()
	rect := d.ClipRect2()
	flag1 := clipFlags(*p1, rect)
	flag2 := clipFlags(*p2, rect)
	if flag1|flag2 == 0 {
		return true
	}
	if flag1&flag2 != 0 {
		return false
	}
	if flag1 != 0 {
		if !clipToRect(rect, p1, *p2, false) {
			return false
		}
	}
	if flag2 != 0 {
		if !clipToRect(rect, p2, *p1, true) {
			return false
		}
	}
	return p1.X >= rect.Min.X && p1.X <= rect.Max.X && p1.Y >= rect.Min.Y && p1.Y <= rect.Max.Y &&
		p2.X >= rect.Min.X && p2.X <= rect.Max.X && p2.Y >= rect.Min.Y && p2.Y <= rect.Max.Y
}

func (r *NoxRender) drawParticles49ED80(mul2 int) bool {
	d := r.Data()
	pos2, ok := r.LastPoint(false)
	if !ok {
		return false
	}
	pos1, ok := r.LastPoint(false)
	if !ok {
		return false
	}
	if d.IsAlphaEnabled() {
		r.DrawLineAlpha(pos1, pos2, r.Data().Color2())
		return true
	}
	if d.useClip != 0 && !r.clipToRect2(&pos1, &pos2) {
		return true
	}
	dx := pos2.X - pos1.X
	dy := pos2.Y - pos1.Y

	sx := 0
	if dx > 0 {
		sx = +1
	} else if dx < 0 {
		sx = -1
		dx = -dx
	}

	sy := 0
	if dy > 0 {
		sy = +1
	} else if dy < 0 {
		sy = -1
		dy = -dy
	}

	p := r.newParticle(0, mul2)
	each := p.opt.rad / 4
	if dx <= dy {
		v := 2*dx - dy
		p.DrawAt(pos1)
		step := 0
		for i := dy; i > 0; i-- {
			pos1.Y += sy
			if v >= 0 {
				v += 2 * (dx - dy)
				pos1.X += sx
			} else {
				v += 2 * dx
			}
			step++
			if step >= each {
				p.DrawAt(pos1)
				step = 0
			}
		}
	} else {
		v := 2*dy - dx
		p.DrawAt(pos1)
		step := 0
		for i := dx; i > 0; i-- {
			pos1.X += sx
			if v >= 0 {
				v += 2 * (dy - dx)
				pos1.Y += sy
			} else {
				v += 2 * dy
			}
			step++
			if step >= each {
				p.DrawAt(pos1)
				step = 0
			}
		}
	}
	return true
}

var (
	drawWhiteBubbleParticle     int
	drawLightBlueBubbleParticle int
	drawRedBubbleParticle       int
	drawOrangeBubbleParticle    int
	drawYellowBubbleParticle    int
	drawGreenBubbleParticle     int
	drawWhiteSpark              int
)

func sub_499F60(p int, pos image.Point, a4 int, a5, a6, a7, a8, a9 int, a10 int) {
	C.sub_499F60(C.int(p), C.int(pos.X), C.int(pos.Y), C.short(a4), C.char(a5), C.char(a6), C.char(a7), C.char(a8), C.char(a9), C.int(a10))
}

func (c *Client) drawCreatureBackEffects(vp *Viewport, dr *Drawable) {
	if dr.HasEnchant(ENCHANT_INVISIBLE) && C.sub_474B40(dr.C()) == 0 {
		return
	}
	if dr.HasEnchant(ENCHANT_ANCHORED) {
		pos := vp.ToScreenPos(dr.Pos())
		c.r.DrawGlow(pos, nox_color_blue_2650684, 30, 31)
	}
	if dr.HasEnchant(ENCHANT_HASTED) && !nox_xxx_checkGameFlagPause_413A50() {
		if drawWhiteBubbleParticle == 0 {
			drawWhiteBubbleParticle = nox_things.IndByID("WhiteBubbleParticle")
			drawLightBlueBubbleParticle = nox_things.IndByID("LightBlueBubbleParticle")
		}
		pos := dr.Pos()
		v2 := 0
		if dr.Pos() != dr.Point8() {
			v2 = 2
		}
		for ; v2 > 0; v2-- {
			v22 := randomIntMinMax(3, 5)
			v18 := randomIntMinMax(3, 6)
			v14 := randomIntMinMax(2, 4)
			pos2 := image.Point{
				X: randomIntMinMax(-10, 10),
				Y: randomIntMinMax(-10, 10) + int(*(*int16)(dr.field(104))),
			}
			sub_499F60(drawWhiteBubbleParticle, pos.Add(pos2), 1, v14, v18, 0, 0, 0, v22)

			v23 := randomIntMinMax(3, 5)
			v19 := randomIntMinMax(3, 6)
			v15 := randomIntMinMax(2, 4)
			pos3 := image.Point{
				X: randomIntMinMax(-10, 10),
				Y: randomIntMinMax(-10, 10) + int(*(*int16)(dr.field(104))),
			}
			sub_499F60(drawLightBlueBubbleParticle, pos.Add(pos3), 1, v15, v19, 0, 0, 0, v23)
		}
	}
	if dr.HasEnchant(ENCHANT_RUN) && !nox_xxx_checkGameFlagPause_413A50() {
		if drawRedBubbleParticle == 0 {
			drawRedBubbleParticle = nox_things.IndByID("RedBubbleParticle")
			drawOrangeBubbleParticle = nox_things.IndByID("OrangeBubbleParticle")
		}
		pos := dr.Pos()
		v5 := 1
		if dr.Pos() != dr.Point8() {
			v5 = 2
		}
		for ; v5 > 0; v5-- {
			v24 := randomIntMinMax(3, 5)
			v20 := randomIntMinMax(3, 6)
			v16 := randomIntMinMax(2, 4)
			pos2 := image.Point{
				X: randomIntMinMax(-10, 10),
				Y: randomIntMinMax(-10, 10) + int(*(*int16)(dr.field(104))),
			}
			sub_499F60(drawRedBubbleParticle, pos.Add(pos2), 1, v16, v20, 0, 0, 0, v24)

			v25 := randomIntMinMax(3, 5)
			v21 := randomIntMinMax(3, 6)
			v17 := randomIntMinMax(2, 4)
			pos3 := image.Point{
				X: randomIntMinMax(-10, 10),
				Y: randomIntMinMax(-10, 10) + int(*(*int16)(dr.field(104))),
			}
			sub_499F60(drawOrangeBubbleParticle, pos.Add(pos3), 1, v17, v21, 0, 0, 0, v25)
		}
	}
	// Protection effects
	if dr.HasEnchant(ENCHANT_PROTECT_FROM_FIRE) {
		c.r.drawProtectEffectDefault(vp, dr.Pos(), dr, 0, 0, nox_color_red, nox_color_red_2589776, true)
	}
	if dr.HasEnchant(ENCHANT_PROTECT_FROM_POISON) {
		c.r.drawProtectEffectDefault(vp, dr.Pos(), dr, 85, 1, nox_color_green, nox_color_green_2614268, true)
	}
	if dr.HasEnchant(ENCHANT_PROTECT_FROM_ELECTRICITY) {
		c.r.drawProtectEffectDefault(vp, dr.Pos(), dr, 170, 2, nox_color_blue_2650684, nox_color_white_2523948, true)
	}
	if dr.HasEnchant(ENCHANT_REFLECTIVE_SHIELD) { // Shield effects
		switch *(*byte)(dr.field(297)) {
		case 0, 1, 2:
			C.nox_xxx_drawShield_499810(vp.C(), dr.C())
		}
	}
}

func (c *Client) drawCreatureFrontEffects(vp *Viewport, dr *Drawable) {
	if dr.HasEnchant(ENCHANT_INVISIBLE) && C.sub_474B40(dr.C()) == 0 {
		return
	}
	if dr.HasEnchant(ENCHANT_SHOCK) {
		if drawWhiteSpark == 0 {
			drawWhiteSpark = nox_things.IndByID("WhiteSpark")
		}
		pos := dr.Pos()
		C.nox_xxx_drawEnergyBolt_499710(C.int(pos.X), C.int(pos.Y), C.short(*(*int16)(dr.field(104))), C.int(drawWhiteSpark))
	}
	if dr.HasEnchant(ENCHANT_CONFUSED) || dr.HasEnchant(ENCHANT_HELD) || dr.HasEnchant(ENCHANT_ANTI_MAGIC) || dr.HasEnchant(ENCHANT_CHARMING) {
		pos := vp.ToScreenPos(dr.Pos())
		v5 := 5 - int(*(*int16)(dr.field(106))) - int(*(*int16)(dr.field(104))) - int(dr.Field25())
		v6 := *(*byte)(dr.field(112))
		pos.Y += v5
		if v6&0x4 != 0 && *(*uint32)(dr.field(276)) == 6 {
			v8 := 8 * uintptr(*(*byte)(dr.field(297)))
			pos.X += int(memmap.Int32(0x587000, 149432+v8))
			pos.Y += int(memmap.Int32(0x587000, 149436+v8))
		}
		if dr.HasEnchant(ENCHANT_ANTI_MAGIC) {
			c.r.Data().setColorize17(1)
			sub433E40(nox_color_blue_2650684)
		}
		c.nox_video_drawAnimatedImageOrCursorAt(asImageRefP(*memmap.PtrPtr(0x5D4594, 1096456)), pos.Add(image.Point{X: -64, Y: -64}))
		c.r.Data().setColorize17(0)
	}
	if dr.HasEnchant(ENCHANT_SLOWED) && !nox_xxx_checkGameFlagPause_413A50() {
		v11 := int(*(*float32)(dr.field(48)))
		v44 := int(dr.Field25() * 0.5)
		if drawYellowBubbleParticle == 0 {
			drawYellowBubbleParticle = nox_things.IndByID("YellowBubbleParticle")
		}
		pos := dr.Pos()
		for v12 := 0; v12 < 2; v12++ {
			v40 := randomIntMinMax(3, 5)
			v36 := randomIntMinMax(3, 6)
			v34 := randomIntMinMax(1, 2)
			v32 := randomIntMinMax(0, v44)
			pos2 := image.Point{
				X: randomIntMinMax(-v11, v11),
				Y: randomIntMinMax(-v11, v11),
			}
			sub_499F60(drawYellowBubbleParticle, pos.Add(pos2), v32, v34, v36, -5, 0, 0, v40)
		}
	}
	if dr.HasEnchant(ENCHANT_INFRAVISION) && !nox_xxx_checkGameFlagPause_413A50() {
		if drawGreenBubbleParticle == 0 {
			drawGreenBubbleParticle = nox_things.IndByID("GreenBubbleParticle")
		}
		pos := dr.Pos()
		v41 := randomIntMinMax(2, 3)
		v37 := randomIntMinMax(3, 6)
		v35 := randomIntMinMax(2, 4)
		v29 := int(dr.Field25()) + 12
		v14 := int(dr.Field25())
		v33 := randomIntMinMax(v14+8, v29)
		pos2 := image.Point{
			X: randomIntMinMax(-6, 6),
			Y: randomIntMinMax(-10, 10),
		}
		sub_499F60(drawGreenBubbleParticle, pos.Add(pos2), v33, v35, v37, 1, 0, 0, v41)
	}
	if dr.HasEnchant(ENCHANT_VAMPIRISM) && !nox_xxx_checkGameFlagPause_413A50() {
		pos := vp.ToScreenPos(dr.Pos())

		for v16 := 0; v16 < 10; v16++ {
			v17 := randomIntMinMax(1, 2)
			v38 := int(*(*float32)(dr.field(48)))
			v18 := int(*(*float32)(dr.field(48)))
			v20 := int(dr.Field25())
			pos2 := pos.Add(image.Point{
				X: randomIntMinMax(-v18, v38),
				Y: randomIntMinMax(-10-v20, 0) + int(*(*int16)(dr.field(104))),
			})
			v22 := randomIntMinMax(3, 4)
			c.r.DrawGlow(pos2, drawColorPurple, v17+v22, v17+2)
			c.r.DrawPoint(pos2, v17, drawColorDarkPurple)
		}
	}
	if dr.HasEnchant(ENCHANT_PROTECT_FROM_FIRE) {
		c.r.drawProtectEffectDefault(vp, dr.Pos(), dr, 0, 0, nox_color_red, nox_color_red_2589776, false)
	}
	if dr.HasEnchant(ENCHANT_PROTECT_FROM_POISON) {
		c.r.drawProtectEffectDefault(vp, dr.Pos(), dr, 85, 1, nox_color_green, nox_color_green_2614268, false)
	}
	if dr.HasEnchant(ENCHANT_PROTECT_FROM_ELECTRICITY) {
		c.r.drawProtectEffectDefault(vp, dr.Pos(), dr, 170, 2, nox_color_blue_2650684, nox_color_white_2523948, false)
	}
	if dr.HasEnchant(ENCHANT_SHIELD) {
		pos := vp.ToScreenPos(dr.Pos())
		v23 := *(*uint32)(dr.field(276))
		v24 := -90 - int(*(*int16)(dr.field(104)))
		pos.X -= 64
		pos.Y += v24
		if v23 == 6 {
			v26 := 8 * uintptr(*(*byte)(dr.field(297)))
			pos.X += int(memmap.Int32(0x587000, 149504+v26))
			pos.Y += int(memmap.Int32(0x587000, 149508+v26))
		}
		c.r.Data().SetAlphaEnabled(true)
		c.r.Data().SetAlpha(0x80)
		c.nox_video_drawAnimatedImageOrCursorAt(asImageRefP(*memmap.PtrPtr(0x5D4594, 1096460)), pos)
		c.r.Data().SetAlphaEnabled(false)
	}
	if dr.HasEnchant(ENCHANT_REFLECTIVE_SHIELD) {
		switch *(*byte)(dr.field(297)) {
		default:
			C.nox_xxx_drawShield_499810(vp.C(), dr.C())
		case 0, 1, 2:
		}
	}
}

type circleSeg struct {
	val int
	ptr *circleSeg
}

type circleSegments struct {
	byY  []*circleSeg
	ymin int
	ymax int
	arr  []circleSeg
	cur  []circleSeg
}

func (c *circleSegments) Init(r *NoxRender) {
	height := r.PixBufferRect().Dy()
	c.byY = make([]*circleSeg, height)
	c.arr = make([]circleSeg, height*8)
}

func (c *circleSegments) Free() {
	if c.byY != nil {
		c.byY = nil
	}
	if c.arr != nil {
		c.arr = nil
		c.cur = nil
	}
}

func (c *circleSegments) Reset() {
	c.cur = c.arr
	c.ymax = 0
	c.ymin = len(c.byY) - 1
	for i := range c.byY {
		c.byY[i] = nil
	}
}

func (r *NoxRender) circleSegClip(p1, p2 *image.Point) bool {
	var ys, ye int
	if p := r.Data(); p.useClip != 0 {
		rect2 := p.ClipRect2()
		ys = rect2.Min.Y
		ye = rect2.Max.Y
	} else {
		ys = 0
		ye = r.PixBufferRect().Dy() - 1
	}
	v16 := 0
	v6 := p1.X
	v7 := p2.X
	v8 := p1.Y
	v9 := p2.Y
	if v8 >= ys {
		if v8 > ye {
			v16 = 4
		}
	} else {
		v16 = 8
	}
	v17 := 0
	if v9 >= ys {
		if v9 > ye {
			v17 = 4
		}
	} else {
		v17 = 8
	}
	if v17&v16 != 0 {
		return false
	}
	if v16 != 0 {
		if v16&8 != 0 {
			if v9 == v8 {
				return false
			}
			v11 := (ys - v8) * (v7 - v6) / (v9 - v8)
			v8 = ys
			v6 += v11
		} else if v16&4 != 0 {
			if v9 == v8 {
				return false
			}
			v12 := (ye - v8) * (v7 - v6) / (v9 - v8)
			v8 = ye
			v6 += v12
		}
	}
	if v17 != 0 {
		if v17&8 != 0 {
			if v9 == v8 {
				return false
			}
			v13 := (v7 - v6) * (ys - v9) / (v9 - v8)
			v9 = ys
			v7 += v13
		} else if v17&4 != 0 {
			if v9 == v8 {
				return false
			}
			v14 := (v7 - v6) * (ye - v9) / (v9 - v8)
			v9 = ye
			v7 += v14
		}
	}
	p1.X = v6
	p1.Y = v8
	p2.X = v7
	p2.Y = v9
	return true
}

func (r *NoxRender) circleSegAdd(p1, p2 image.Point, a2 bool) {
	if !r.circleSegClip(&p1, &p2) {
		return
	}
	v3 := p2.X - p1.X
	p1.X <<= 16
	yi := p1.Y
	v5 := v3 << 16
	var v6, v7 int
	if p1.Y > p2.Y {
		v6 = -1
		v7 = p1.Y - p2.Y
		v5 /= p1.Y - p2.Y
		if p2.Y < r.circleSeg.ymin {
			r.circleSeg.ymin = p2.Y
		}
		if p1.Y > r.circleSeg.ymax {
			r.circleSeg.ymax = p1.Y
		}
	} else {
		v6 = 1
		v7 = p2.Y - p1.Y
		if p2.Y != p1.Y {
			v5 /= v7
		}
		if p1.Y < r.circleSeg.ymin {
			r.circleSeg.ymin = p1.Y
		}
		if p2.Y > r.circleSeg.ymax {
			r.circleSeg.ymax = p2.Y
		}
	}
	for ; v7 > 0; v7-- {
		v8 := r.circleSeg.byY[yi]
		p := &r.circleSeg.cur[0]
		r.circleSeg.byY[yi] = p
		p.val = p1.X >> 16
		p.ptr = v8
		r.circleSeg.cur = r.circleSeg.cur[1:]
		yi = v6 + p1.Y
		p1.X += v5
		p1.Y += v6
	}
	if a2 {
		v9 := r.circleSeg.byY[yi]
		p := &r.circleSeg.cur[0]
		r.circleSeg.byY[yi] = p
		p.val = int(uint16(p2.X))
		p.ptr = v9
		r.circleSeg.cur = r.circleSeg.cur[1:]
	}
}

//export sub_4AE6F0
func sub_4AE6F0(cx, cy, rad, ang, ccl C.int) {
	noxClient.r.drawCircleSegment(int(cx), int(cy), int(rad), int(ang), noxcolor.RGBA5551(ccl))
}

func (r *NoxRender) drawCircleSegment(cx, cy, rad, ang int, cl color.Color) {
	r.Data().SetColor2(cl)
	if ang < 0 {
		ang = 0
	}
	if ang >= 256 {
		return
	}
	dx := rad * int(memmap.Int32(0x5D4594, 1310096+4*uintptr(256-ang))) >> 16
	dy := rad * int(memmap.Int32(0x5D4594, 1309840+4*uintptr(256-ang))) >> 16
	r.circleSeg.Reset()
	r.circleSegAdd(image.Pt(cx, cy-rad), image.Pt(cx, cy), false)
	r.circleSegAdd(image.Pt(cx, cy), image.Pt(cx+dx, cy+dy), true)
	drawPart := func(x1, y1, x2, ly, yi, dn int) {
		if y1 < r.circleSeg.ymin || y1 > r.circleSeg.ymax+dn {
			if dx <= 0 {
				r.DrawLineHorizontal(x1, y1, x2, cl)
			}
		} else {
			p := r.circleSeg.byY[yi]
			if p2 := p.ptr; p2 != nil {
				if p.val > p2.val {
					p.val, p2.val = p2.val, p.val
				}
				if dx > 0 {
					r.DrawLineHorizontal(p.val, ly, p2.val, cl)
				} else {
					r.DrawLineHorizontal(x1, ly, p.val, cl)
					r.DrawLineHorizontal(p2.val, ly, x2, cl)
				}
			} else {
				r.DrawLineHorizontal(p.val, y1, x2, cl)
			}
		}
	}
	dval := 5 - 2*rad
	flag1 := false
	j := 0
	val := 1 - rad
	for i := 0; i <= rad-j; i++ {
		if flag1 {
			drawPart(cx-i, cy-rad+j, cx+i, cy-rad+j, cy-rad+j, 0)
		}
		if i != 0 {
			drawPart(cx-rad+j, cy-i, cx+rad-j, cy-i, cy-i, -1)
		}
		drawPart(cx-rad+j, cy+i, cx+rad-j, cy+i, cy+i, -1)
		if flag1 {
			drawPart(cx-i, cy+rad-j, cx+i, cy+rad-j, cy+rad-j, 0)
		}
		if int(val) >= 0 {
			flag1 = true
			j++
			val += dval
			dval += 4
		} else {
			flag1 = false
			val += 3 + 2*i
			dval += 2
		}
	}
}

//export nox_client_isConnected_43C700
func nox_client_isConnected_43C700() C.int {
	return C.int(bool2int(nox_client_isConnected()))
}

//export nox_xxx_gameSetCliConnected_43C720
func nox_xxx_gameSetCliConnected_43C720(a1 C.int) {
	nox_xxx_gameSetCliConnected(a1 != 0)
}

func nox_client_isConnected() bool {
	return memmap.Uint32(0x5D4594, 815764) != 0
}

func nox_xxx_gameSetCliConnected(v bool) {
	same := nox_client_isConnected() == v
	cl := caller(1)
	if v {
		gameLog.Printf("client connected: %s", cl)
	} else {
		gameLog.Printf("client not connected: %s", cl)
	}
	*memmap.PtrUint32(0x5D4594, 815764) = uint32(bool2int(v))
	if !same && !v {
		C.nox_xxx_guiServerOptionsHide_4597E0(0)
		C.nox_xxx_cliSetSettingsAcquired_4169D0(0)
	}
}
