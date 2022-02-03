package nox

/*
#include "GAME1_2.h"
#include "GAME2_3.h"
#include "GAME3_1.h"
#include "defs.h"
#include "GAME2_1.h"
#include "common__system__team.h"
#include "client__system__client.h"
#include "client__gui__guiquit.h"
#include "client__gui__guiggovr.h"
#include "client__video__draw_common.h"
#include "client__draw__selectdw.h"
#include "client__draw__drawwin.h"
#include "client__draw__debugdraw.h"
extern nox_draw_viewport_t nox_draw_viewport;
extern nox_drawable* nox_xxx_drawablePlayer_1046600;
extern unsigned int nox_client_drawFrontWalls_80812;
extern unsigned int nox_client_translucentFrontWalls_805844;
extern unsigned int nox_client_highResFrontWalls_80820;
extern unsigned int nox_client_highResFloors_154952;
extern unsigned int nox_client_lockHighResFloors_1193152;
extern unsigned int nox_client_texturedFloors_154956;
extern unsigned int nox_gui_console_translucent;
extern unsigned int nox_client_renderGlow_805852;
extern unsigned int nox_client_fadeObjects_80836;
extern unsigned int nox_client_renderBubbles_80844;
extern unsigned int nox_client_renderGUI_80828;
extern unsigned int nox_client_showTooltips_80840;
extern unsigned int nox_xxx_xxxRenderGUI_587000_80832;
extern unsigned int nox_profiled_805856;
extern unsigned int nox_xxx_waypointCounterMB_587000_154948;
extern unsigned char nox_arr_84EB20[280*57*4];
extern void* nox_draw_defaultFont_816492;
extern unsigned int dword_5d4594_2523804;
extern unsigned int dword_5d4594_2650676;
extern unsigned int dword_5d4594_2650680;
extern unsigned int dword_5d4594_811896;
extern unsigned int dword_5d4594_811904;
extern unsigned int nox_client_gui_flag_815132;
extern unsigned int dword_5d4594_1096432;
extern unsigned int dword_5d4594_3799452;
extern unsigned int dword_5d4594_3799468;
extern unsigned int nox_client_texturedFloors2_154960;
extern unsigned int dword_5d4594_1193156;
extern unsigned int dword_5d4594_1193188;
extern int dword_5d4594_3799524;
extern unsigned int nox_client_gui_flag_1556112;
extern unsigned int nox_gameDisableMapDraw_5d4594_2650672;
extern void* dword_5d4594_810640;
extern void* nox_draw_colorTablesRev_3804668;
void nox_xxx_tileDrawMB_481C20_A(nox_draw_viewport_t* vp, int v3);
void nox_xxx_tileDrawMB_481C20_B(nox_draw_viewport_t* vp, int v78);
void nox_xxx_tileDrawMB_481C20_C_textured(nox_draw_viewport_t* vp, int v72, int v78);
void nox_xxx_tileDrawMB_481C20_C_solid(nox_draw_viewport_t* vp, int v72, int v78);
void sub_4C86B0();
void  nox_xxx_cliLight16_469140(nox_drawable* dr, nox_draw_viewport_t* vp);
void nox_xxx_clientDrawAll_436100_draw_A();
void nox_xxx_clientDrawAll_436100_draw_B();
void nox_xxx_drawAllMB_475810_draw_A(nox_draw_viewport_t* vp);
int nox_xxx_drawAllMB_475810_draw_B(nox_draw_viewport_t* vp);
void nox_xxx_drawAllMB_475810_draw_C(nox_draw_viewport_t* vp, int v36, int v7);
void nox_xxx_drawAllMB_475810_draw_D(nox_draw_viewport_t* vp);
extern uint32_t nox_color_white_2523948;
extern uint32_t nox_color_black_2650656;
extern uint32_t nox_color_red_2589776;
extern uint32_t nox_color_blue_2650684;
extern uint32_t nox_color_green_2614268;
*/
import "C"
import (
	"fmt"
	"image"
	"sort"
	"unsafe"

	"golang.org/x/image/font"

	"nox/v1/client/input"
	"nox/v1/client/noxrender"
	"nox/v1/common"
	"nox/v1/common/alloc"
	noxcolor "nox/v1/common/color"
	noxflags "nox/v1/common/flags"
	"nox/v1/common/memmap"
	"nox/v1/common/noximage"
	"nox/v1/common/types"
)

var (
	noxrend                         *NoxRender
	nox_draw_colorTablesRev_3804668 []byte // map[Color16]byte
)

func getViewport() *Viewport {
	return asViewport(&C.nox_draw_viewport)
}

func asViewport(p *C.nox_draw_viewport_t) *Viewport {
	return (*Viewport)(unsafe.Pointer(p))
}

type Viewport C.nox_draw_viewport_t

func (vp *Viewport) C() *C.nox_draw_viewport_t {
	return (*C.nox_draw_viewport_t)(unsafe.Pointer(vp))
}

func (vp *Viewport) toScreenPos(pos types.Point) types.Point { // sub_4739E0
	return pos.Add(types.Point{
		X: int(vp.x1) - int(vp.field_4),
		Y: int(vp.y1) - int(vp.field_5),
	})
}

func detectBestVideoSettings() { // nox_setProfiledMode_4445C0
	const cfg = 450
	cut := 0
	*memmap.PtrUint32(0x587000, 80808) = 1
	*memmap.PtrUint32(0x587000, 80816) = 1
	C.nox_client_showTooltips_80840 = 1
	C.nox_client_renderGUI_80828 = 1
	C.nox_xxx_xxxRenderGUI_587000_80832 = 1
	if cfg == 0 {
		//v4 = 8
		cut = 75
		C.nox_client_drawFrontWalls_80812 = 0
		C.nox_client_translucentFrontWalls_805844 = 0
		C.nox_client_highResFrontWalls_80820 = 0
		C.nox_client_highResFloors_154952 = 0
		C.nox_client_lockHighResFloors_1193152 = 0
		C.nox_client_texturedFloors_154956 = 1
		C.nox_gui_console_translucent = 0
		C.nox_client_renderGlow_805852 = 0
		C.nox_client_fadeObjects_80836 = 0
		noxflags.UnsetEngine(noxflags.EngineSoftShadowEdge)
		C.nox_client_renderBubbles_80844 = 0
	} else if cfg == 200 {
		//v4 = 8
		cut = 85
		C.nox_client_drawFrontWalls_80812 = 1
		C.nox_client_translucentFrontWalls_805844 = 0
		C.nox_client_highResFrontWalls_80820 = 0
		C.nox_client_highResFloors_154952 = 0
		C.nox_client_lockHighResFloors_1193152 = 0
		C.nox_client_texturedFloors_154956 = 1
		C.nox_gui_console_translucent = 0
		C.nox_client_renderGlow_805852 = 0
		C.nox_client_fadeObjects_80836 = 0
		noxflags.UnsetEngine(noxflags.EngineSoftShadowEdge)
		C.nox_client_renderBubbles_80844 = 0
	} else if cfg == 266 {
		//v4 = 8
		cut = 100
		C.nox_client_drawFrontWalls_80812 = 1
		C.nox_client_translucentFrontWalls_805844 = 1
		C.nox_client_highResFrontWalls_80820 = 1
		C.nox_client_highResFloors_154952 = 1
		C.nox_client_lockHighResFloors_1193152 = 0
		C.nox_client_texturedFloors_154956 = 1
		C.nox_gui_console_translucent = 0
		C.nox_client_renderGlow_805852 = 1
		C.nox_client_fadeObjects_80836 = 1
		noxflags.SetEngine(noxflags.EngineSoftShadowEdge)
		C.nox_client_renderBubbles_80844 = 1
	} else if cfg == 300 {
		//v4 = 16
		cut = 100
		C.nox_client_drawFrontWalls_80812 = 1
		C.nox_client_translucentFrontWalls_805844 = 1
		C.nox_client_highResFrontWalls_80820 = 1
		C.nox_client_highResFloors_154952 = 1
		C.nox_client_lockHighResFloors_1193152 = 0
		C.nox_client_texturedFloors_154956 = 1
		C.nox_gui_console_translucent = 0
		C.nox_client_renderGlow_805852 = 1
		C.nox_client_fadeObjects_80836 = 1
		noxflags.SetEngine(noxflags.EngineSoftShadowEdge)
		C.nox_client_renderBubbles_80844 = 1
	} else if cfg == 450 {
		//v4 = 16
		cut = 100
		C.nox_client_drawFrontWalls_80812 = 1
		C.nox_client_translucentFrontWalls_805844 = 1
		C.nox_client_highResFrontWalls_80820 = 1
		C.nox_client_highResFloors_154952 = 1
		C.nox_client_lockHighResFloors_1193152 = 1
		C.nox_client_texturedFloors_154956 = 1
		C.nox_gui_console_translucent = 1
		C.nox_client_renderGlow_805852 = 1
		C.nox_client_fadeObjects_80836 = 1
		noxflags.SetEngine(noxflags.EngineSoftShadowEdge)
		C.nox_client_renderBubbles_80844 = 1
	}
	C.nox_xxx_tileSetDrawFn_481420()
	if !noxflags.HasEngine(noxflags.EngineWindowed) {
		videoUpdateGameMode(types.Size{
			W: noxDefaultWidth,
			H: noxDefaultHeight,
		})
	}
	C.nox_video_setCutSize_4766A0(C.int(cut))
	if noxflags.HasGame(noxflags.GameFlag29) {
		nox_draw_setCutSize_476700(C.int(cut), 0)
	}
	C.nox_profiled_805856 = 1
}

func nox_draw_initColorTablesRev_434DA0() {
	const max = 0x7FFF
	const (
		rshift = 7 // -10+3
		gshift = 2 // -5+3
		bshift = 3 // -0+3

		rmask = 0x7c00
		gmask = 0x03e0
		bmask = 0x001f
	)
	nox_draw_colorTablesRev_3804668 = make([]byte, max+3)
	for i := 0; i <= max; i++ {
		cr := uint32((i & rmask) >> rshift)
		cg := uint32((i & gmask) >> gshift)
		cb := uint32((i & bmask) << bshift)
		nox_draw_colorTablesRev_3804668[i] = byte((28*(cb|7) + 150*(cg|7) + 76*(cr|7)) >> 8)
	}
	ptr, _ := alloc.Bytes(uintptr(len(nox_draw_colorTablesRev_3804668)))
	copy(ptr, nox_draw_colorTablesRev_3804668)
	C.nox_draw_colorTablesRev_3804668 = unsafe.Pointer(&ptr[0])
}

func nox_draw_freeColorTables_433C20() {
	if C.dword_5d4594_810640 != nil {
		alloc.Free(C.dword_5d4594_810640)
		C.dword_5d4594_810640 = nil
	}
	if C.nox_draw_colorTablesRev_3804668 != nil {
		alloc.Free(C.nox_draw_colorTablesRev_3804668)
		C.nox_draw_colorTablesRev_3804668 = nil
	}
	if p := C.nox_draw_colors_r_3804672; p != nil {
		alloc.Free(unsafe.Pointer(p))
		C.nox_draw_colors_r_3804672 = nil
	}
	if p := C.nox_draw_colors_g_3804656; p != nil {
		alloc.Free(unsafe.Pointer(p))
		C.nox_draw_colors_g_3804656 = nil
	}
	if p := C.nox_draw_colors_b_3804664; p != nil {
		alloc.Free(unsafe.Pointer(p))
		C.nox_draw_colors_b_3804664 = nil
	}
	*memmap.PtrUint32(0x973F18, 5232) = 0
}

func sub_4338D0() int {
	noxcolor.SetMode(noxcolor.ModeRGBA5551)
	C.dword_975240 = (*[0]byte)(C.sub_435280)
	C.dword_975380 = (*[0]byte)(C.sub_434E80)
	copy(byte_5D4594_3804364[:], byte_581450_9176[:])
	copy(unsafe.Slice((*uint32)(unsafe.Pointer(&C.byte_5D4594_3804364[0])), 40), byte_581450_9176[:])
	ptr := noxrend.Data()
	ptr.Reset()
	nox_draw_initColorTables_434CC0()
	nox_draw_initColorTablesRev_434DA0()
	if C.dword_5d4594_823772 == 0 {
		C.sub_4353C0()
	}
	*memmap.PtrUint32(0x5D4594, 809596) = 0
	C.dword_5d4594_808568 = 0
	C.dword_5d4594_810628 = 0
	if C.dword_5d4594_823772 != 0 {
		v2, freeV2 := alloc.Malloc(256 * 3)
		defer freeV2()
		C.sub_435150((*C.uchar)(v2), (*C.char)(memmap.PtrOff(0x973F18, 3880)))
		C.sub_4347F0((*C.char)(v2), 256)
	} else {
		C.sub_4347F0((*C.char)(memmap.PtrOff(0x581450, 8404)), 256)
	}
	if C.sub_434FB0() == 0 {
		return 0
	}
	C.sub_4340A0(0, 0, 0, 255)
	C.sub_4340A0(1, 0, 255, 0)
	C.sub_4340A0(2, 0, 255, 255)
	C.sub_4340A0(3, 255, 0, 0)
	C.sub_4340A0(4, 255, 0, 255)
	C.sub_4340A0(5, 255, 255, 0)
	C.sub_4340A0(6, 255, 255, 255)
	C.sub_4340A0(7, 0, 0, 0)
	C.sub_4340A0(8, 0, 0, 128)
	C.sub_4340A0(9, 0, 128, 0)
	C.sub_4340A0(10, 0, 128, 128)
	C.sub_4340A0(11, 128, 0, 0)
	C.sub_4340A0(12, 128, 0, 128)
	C.sub_4340A0(13, 128, 128, 0)
	C.sub_4340A0(14, 128, 128, 128)
	C.sub_4340A0(15, 0, 0, 0)
	// TODO gamma control
	C.dword_5d4594_808564 = 0
	C.sub_4348C0()
	C.sub_4352E0()
	*memmap.PtrUint32(0x973F18, 5232) = 0
	return 1
}

//export sub_433E80
func sub_433E80(r, g, b C.uchar) {
	noxrend.Data().setColorInt44(ColorInt{
		R: int(r),
		G: int(g),
		B: int(b),
	})
}

//export nox_xxx_drawMakeRGB_433F10
func nox_xxx_drawMakeRGB_433F10(r, g, b C.uchar) {
	noxrend.Data().setColorInt54(ColorInt{
		R: int(r),
		G: int(g),
		B: int(b),
	})
}

//export sub_434080
func sub_434080(a1 C.int) {
	noxrend.Data().setField262(int(a1))
}

//export nox_xxx_drawSelectColor_434350
func nox_xxx_drawSelectColor_434350(a1 C.int) {
	noxrend.Data().SetSelectColor(uint32(a1))
}

//export nox_xxx_drawSetTextColor_434390
func nox_xxx_drawSetTextColor_434390(a1 C.int) {
	noxrend.Data().SetTextColor(uint32(a1))
}

//export nox_xxx_drawSetColor_4343E0
func nox_xxx_drawSetColor_4343E0(a1 C.int) {
	noxrend.Data().SetColor(uint32(a1))
}

//export nox_client_drawSetColor_434460
func nox_client_drawSetColor_434460(a1 C.int) {
	noxrend.Data().SetColor2(uint32(a1))
}

//export nox_client_drawEnableAlpha_434560
func nox_client_drawEnableAlpha_434560(a1 C.int) {
	noxrend.Data().SetAlphaEnabled(a1 != 0)
}

//export sub_4345F0
func sub_4345F0(a1 C.int) {
	noxrend.Data().setField14(int(a1))
}

//export nox_xxx_draw_434600
func nox_xxx_draw_434600(a1 C.int) {
	noxrend.Data().setField17(int(a1))
}

//export sub_434990
func sub_434990(r, g, b C.int) {
	noxrend.Data().SetLightColor(ColorInt{
		R: int(r),
		G: int(g),
		B: int(b),
	})
}

//export sub_4349C0
func sub_4349C0(a1 *C.uint) {
	arr := unsafe.Slice(a1, 3)
	noxrend.Data().SetLightColor(ColorInt{
		R: int(arr[0]),
		G: int(arr[1]),
		B: int(arr[2]),
	})
}

//export sub_434A10
func sub_434A10(a1, a2, a3 *C.uint) {
	p := noxrend.Data()
	if a1 != nil {
		*a1 = p.field_62
	}
	if a2 != nil {
		*a2 = p.field_63
	}
	if a3 != nil {
		*a3 = p.field_64
	}
}

//export sub_47D370
func sub_47D370(a1 C.int) {
	noxrend.Set_dword_5d4594_3799484(int(a1))
}

//export sub_47D400
func sub_47D400(a1 C.int, a2 C.char) {
	noxrend.Set_dword_5d4594_37995xx(uint32(a1), byte(a2))
}

//export sub_49F7C0_def
func sub_49F7C0_def() {
	noxrend.sub_49F7C0_def_go()
}

func (r *NoxRender) sub_49F7C0_def_go() {
	v1 := r.Get_dword_5d4594_3799476()
	cr := r.Data().ClipRect()
	if v1 > cr.Bottom {
		v1 = cr.Bottom
	}
	r.nox_client_copyRect_49F6F0(cr.Left, cr.Top, cr.Right-cr.Left, v1-cr.Top)
}

func (r *NoxRender) nox_client_copyRect_49F6F0(x, y, w, h int) {
	rc := types.Rect{
		Left:   x,
		Top:    y,
		Right:  x + w,
		Bottom: y + h,
	}
	d := r.Data()
	if rect, ok := types.UtilRectXxx(rc, d.Rect3()); ok {
		d.SetClipRect(rect)
		rect.Right--
		rect.Bottom--
		d.SetRect2(rect)
	}
}

//export nox_client_drawSetAlpha_434580
func nox_client_drawSetAlpha_434580(a C.uchar) {
	noxrend.Data().SetAlpha(byte(a))
}

//export nox_draw_enableTextSmoothing_43F670
func nox_draw_enableTextSmoothing_43F670(v C.int) {
	noxrend.SetTextSmooting(v != 0)
}

func toRect(cr *C.nox_rect) image.Rectangle {
	return image.Rect(int(cr.left), int(cr.top), int(cr.right), int(cr.bottom))
}

type NoxRender struct {
	p   *RenderData
	rnd *noxrender.NoxRender

	colors struct {
		mode noxcolor.Mode
		R    [256]uint16
		G    [256]uint16
		B    [256]uint16
	}

	particles struct {
		byOpts   map[particleOpt]*Particle
		byHandle map[unsafe.Pointer]*Particle
	}
}

func (r *NoxRender) Set_dword_5d4594_3799484(v int) {
	r.rnd.Set_dword_5d4594_3799484(v)
}

func (r *NoxRender) Set_dword_5d4594_37995xx(v uint32, a2 byte) {
	r.rnd.Set_dword_5d4594_37995xx(v, a2)
}

func (r *NoxRender) Reset_dword_5d4594_3799476() {
	r.rnd.Reset_dword_5d4594_3799476()
}

func (r *NoxRender) Get_dword_5d4594_3799476() int {
	return r.rnd.Get_dword_5d4594_3799476()
}

func (r *NoxRender) PixBuffer() *noximage.Image16 {
	return r.rnd.PixBuffer()
}

func (r *NoxRender) SetPixBuffer(pix *noximage.Image16) {
	r.rnd.SetPixBuffer(pix)
}

func newNoxRenderData() (*RenderData, func()) {
	p, free := alloc.Malloc(unsafe.Sizeof(C.nox_render_data_t{}))
	d := (*RenderData)(p)
	d.Reset()
	return d, free
}

func NewNoxRender() *NoxRender {
	r := &NoxRender{rnd: noxrender.NewRender()}
	r.rnd.SetData(renderDataAdapter{r})
	r.SetColorMode(noxcolor.ModeRGBA5551)
	return r
}

func (r *NoxRender) CopyPixBuffer() *image.NRGBA {
	return r.rnd.CopyPixBuffer()
}

func (r *NoxRender) ClearScreen() {
	r.rnd.ClearScreen()
}

func (r *NoxRender) shouldDrawGlow() bool {
	return C.nox_client_renderGlow_805852 != 0
}

func (r *NoxRender) Frame() uint32 {
	return gameFrame()
}

func (r *NoxRender) Data() *RenderData {
	return r.p
}

type renderDataAdapter struct {
	r *NoxRender
}

func (d renderDataAdapter) Frame() uint32 {
	return d.r.Frame()
}

func (d renderDataAdapter) ClipRect() image.Rectangle {
	return d.r.ClipRectImg()
}

func (d renderDataAdapter) ClipRectNox() types.Rect {
	return d.r.Rect()
}

func (d renderDataAdapter) Flag0() bool {
	return d.r.p.flag_0 != 0
}

func (d renderDataAdapter) Multiply14() bool {
	return d.r.p.field_14 != 0
}

func (d renderDataAdapter) Flag16() bool {
	return d.r.p.field_16 != 0
}

func (d renderDataAdapter) Colorize17() bool {
	return d.r.p.field_17 != 0
}

func (d renderDataAdapter) ColorMultA() (r, g, b uint32) {
	p := d.r.p
	return uint32(p.field_24), uint32(p.field_25), uint32(p.field_26)
}

func (d renderDataAdapter) ColorMultOp(op int) (r, g, b uint32) {
	arr := d.r.p.field66(op)

	return arr[6], arr[7], arr[8]
}

func (d renderDataAdapter) IsAlphaEnabled() bool {
	return d.r.p.IsAlphaEnabled()
}

func (d renderDataAdapter) Alpha() byte {
	return d.r.p.Alpha()
}

func (d renderDataAdapter) Color() uint32 {
	return d.r.Color()
}

func (d renderDataAdapter) BgColor() uint32 {
	return uint32(d.r.p.field_58)
}

func (d renderDataAdapter) ShouldDrawText() bool {
	return !noxflags.HasEngine(noxflags.EngineNoTextRendering)
}

func (d renderDataAdapter) TextColor() uint32 {
	return d.r.TextColor()
}

func (d renderDataAdapter) SetTextColor(a1 uint32) {
	d.r.SetTextColor(a1)
}

func (d renderDataAdapter) DefaultFont() font.Face {
	return noxFontDefault
}

func (r *NoxRender) SetData(p *RenderData) {
	r.p = p
}

func (r *NoxRender) Rect() types.Rect {
	return r.p.ClipRect()
}

func (r *NoxRender) SetAlphaEnabled(enabled bool) { // nox_client_drawEnableAlpha_434560
	r.p.SetAlphaEnabled(enabled)
}

func (r *NoxRender) SetAlpha(v byte) { // nox_client_drawSetAlpha_434580
	r.p.SetAlpha(v)
}

func (r *NoxRender) SelectColor(a1 uint32) { // nox_xxx_drawSelectColor_434350
	r.p.SetSelectColor(a1)
}

func (r *NoxRender) TextColor() uint32 {
	return uint32(r.p.field_59)
}

func (r *NoxRender) SetTextColor(a1 uint32) { // nox_xxx_drawSetTextColor_434390
	r.p.SetTextColor(a1)
}

func (r *NoxRender) SetTextSmooting(enabled bool) {
	r.rnd.SetTextSmooting(enabled)
}

func (r *NoxRender) Color() uint32 {
	return uint32(r.p.field_60)
}

func (r *NoxRender) SetColor(a1 uint32) { // nox_xxx_drawSetColor_4343E0
	r.p.SetColor(a1)
}

func (r *NoxRender) SetColor2(a1 uint32) { // nox_client_drawSetColor_434460
	r.p.SetColor2(a1)
}

func (r *NoxRender) sub49EFA0(pos types.Point) { // sub_49EFA0
	C.sub_49EFA0(C.int(pos.X), C.int(pos.Y))
}

func (r *NoxRender) SetBold(enable bool) {
	r.rnd.SetBold(enable)
}

func (r *NoxRender) TabWidth() int {
	return r.rnd.TabWidth()
}

func (r *NoxRender) SetTabWidth(w int) {
	r.rnd.SetTabWidth(w)
}

func (r *NoxRender) DrawPoint(pos types.Point, rad int) { // nox_xxx_drawPointMB_499B70
	switch rad {
	case 0, 1:
		r.sub49EFA0(pos)
	case 2:
		r.DrawRectFilledOpaque(pos.X, pos.Y, 2, 2)
	case 3:
		r.sub49EFA0(pos.Add(types.Point{Y: -1}))
		r.DrawRectFilledOpaque(pos.X-1, pos.Y, 3, 1)
		r.sub49EFA0(pos.Add(types.Point{Y: +1}))
	case 4:
		r.DrawRectFilledOpaque(pos.X, pos.Y-1, 2, 1)
		r.DrawRectFilledOpaque(pos.X-1, pos.Y, 4, 2)
		r.DrawRectFilledOpaque(pos.X, pos.Y+2, 2, 1)
	case 5:
		r.DrawRectFilledOpaque(pos.X-1, pos.Y-2, 3, 1)
		r.DrawRectFilledOpaque(pos.X-2, pos.Y-1, 5, 3)
		r.DrawRectFilledOpaque(pos.X-1, pos.Y+2, 3, 1)
	case 6:
		r.DrawRectFilledOpaque(pos.X, pos.Y-2, 2, 1)
		r.DrawRectFilledOpaque(pos.X-1, pos.Y-1, 4, 1)
		r.DrawRectFilledOpaque(pos.X-2, pos.Y, 6, 2)
		r.DrawRectFilledOpaque(pos.X-1, pos.Y+2, 4, 1)
		r.DrawRectFilledOpaque(pos.X, pos.Y+3, 2, 1)
	default:
		C.sub_4B0BC0(C.int(pos.X), C.int(pos.Y), C.int(rad/2))
	}
}

func (r *NoxRender) nox_client_drawAddPoint_49F500(pos types.Point) {
	C.nox_client_drawAddPoint_49F500(C.int(pos.X), C.int(pos.Y))
}

func (r *NoxRender) DrawLineFromPoints(arr ...types.Point) { // nox_client_drawLineFromPoints_49E4B0
	for _, p := range arr {
		r.nox_client_drawAddPoint_49F500(p)
	}
	C.nox_client_drawLineFromPoints_49E4B0()
}

func (r *NoxRender) DrawRectFilledOpaque(x, y, w, h int) { // nox_client_drawRectFilledOpaque_49CE30
	C.nox_client_drawRectFilledOpaque_49CE30(C.int(x), C.int(y), C.int(w), C.int(h))
}

func (r *NoxRender) DrawRectFilledAlpha(x, y, w, h int) { // nox_client_drawRectFilledAlpha_49CF10
	C.nox_client_drawRectFilledAlpha_49CF10(C.int(x), C.int(y), C.int(w), C.int(h))
}

func (r *NoxRender) DrawBorder(x, y, w, h int) { // nox_client_drawBorderLines_49CC70
	C.nox_client_drawBorderLines_49CC70(C.int(x), C.int(y), C.int(w), C.int(h))
}

func (r *NoxRender) ClipRectImg() image.Rectangle {
	return toRect(&r.p.clip)
}

func (r *NoxRender) FontHeight(fnt font.Face) int {
	return r.rnd.FontHeight(fnt)
}

func (r *NoxRender) DrawString(font font.Face, str string, pos types.Point) int { // nox_xxx_drawString_43F6E0
	return r.rnd.DrawString(font, str, pos)
}

func (r *NoxRender) DrawStringStyle(font font.Face, str string, pos types.Point) int { // nox_xxx_drawStringStyle_43F7B0
	return r.rnd.DrawStringStyle(font, str, pos)
}

func (r *NoxRender) DrawStringHL(font font.Face, str string, pos types.Point) int { // nox_draw_drawStringHL_43F730
	return r.rnd.DrawStringHL(font, str, pos)
}

func (r *NoxRender) DrawStringWrapped(font font.Face, s string, rect image.Rectangle) int { // nox_xxx_drawStringWrap_43FAF0
	return r.rnd.DrawStringWrapped(font, s, rect)
}

func (r *NoxRender) DrawStringWrappedHL(font font.Face, s string, rect image.Rectangle) int { // nox_xxx_drawStringWrapHL_43FD00
	return r.rnd.DrawStringWrappedHL(font, s, rect)
}

func (r *NoxRender) DrawStringWrappedStyle(font font.Face, s string, rect image.Rectangle) int { // nox_xxx_bookDrawString_43FA80_43FD80
	return r.rnd.DrawStringWrappedStyle(font, s, rect)
}

func (r *NoxRender) SplitStringWrapped(fnt font.Face, s string, maxW int) []string {
	return r.rnd.SplitStringWrapped(fnt, s, maxW)
}

func (r *NoxRender) GetStringSizeWrapped(fnt font.Face, s string, maxW int) types.Size { // nox_xxx_drawGetStringSize_43F840
	return r.rnd.GetStringSizeWrapped(fnt, s, maxW)
}

func (r *NoxRender) GetStringSizeWrappedStyle(fnt font.Face, s string, maxW int) types.Size { // nox_xxx_bookGetStringSize_43FA80
	return r.rnd.GetStringSizeWrappedStyle(fnt, s, maxW)
}

func (r *NoxRender) DrawCircle(a1, a2, a3 int) {
	if r.p.IsAlphaEnabled() {
		C.nox_video_drawCircle16Alpha_4B2480(C.int(a1), C.int(a2), C.int(a3))
	} else {
		C.nox_video_drawCircle16Opaque_4B1380(C.int(a1), C.int(a2), C.int(a3))
	}
}

func (r *NoxRender) DrawCircleColored(a1, a2, a3 int, a4 uint32) {
	r.SetColor2(a4)
	r.DrawCircle(a1, a2, a3)
}

//export nox_xxx_guiFontHeightMB_43F320
func nox_xxx_guiFontHeightMB_43F320(fnt unsafe.Pointer) C.int {
	return C.int(noxrend.FontHeight(asFont(fnt)))
}

//export nox_draw_setTabWidth_43FE20
func nox_draw_setTabWidth_43FE20(v C.int) C.int {
	old := noxrend.TabWidth()
	noxrend.SetTabWidth(int(v))
	return C.int(old)
}

//export nox_draw_getFontAdvance_43F9E0
func nox_draw_getFontAdvance_43F9E0(fnt unsafe.Pointer, sp *C.wchar_t, maxW C.int) C.int {
	// TODO: this may be incorrect
	return C.int(noxrend.GetStringSizeWrapped(asFont(fnt), GoWString(sp), int(maxW)).W)
}

//export nox_xxx_drawGetStringSize_43F840
func nox_xxx_drawGetStringSize_43F840(font unsafe.Pointer, sp *C.wchar_t, outW, outH *C.int, maxW C.int) C.int {
	sz := noxrend.GetStringSizeWrapped(asFont(font), GoWString(sp), int(maxW))
	if outW != nil {
		*outW = C.int(sz.W)
	}
	if outH != nil {
		*outH = C.int(sz.H)
	}
	return C.int(bool2int(sz != (types.Size{})))
}

//export nox_xxx_bookGetStringSize_43FA80
func nox_xxx_bookGetStringSize_43FA80(font unsafe.Pointer, sp *C.wchar_t, outW, outH *C.int, maxW C.int) C.int {
	sz := noxrend.GetStringSizeWrappedStyle(asFont(font), GoWString(sp), int(maxW))
	if outW != nil {
		*outW = C.int(sz.W)
	}
	if outH != nil {
		*outH = C.int(sz.H)
	}
	return C.int(bool2int(sz != (types.Size{})))
}

//export nox_xxx_drawString_43F6E0
func nox_xxx_drawString_43F6E0(font unsafe.Pointer, sp *C.wchar_t, x, y C.int) C.int {
	return C.int(noxrend.DrawString(asFont(font), GoWString(sp), types.Point{X: int(x), Y: int(y)}))
}

//export nox_draw_drawStringHL_43F730
func nox_draw_drawStringHL_43F730(font unsafe.Pointer, sp *C.wchar_t, x, y C.int) C.int {
	return C.int(noxrend.DrawStringHL(asFont(font), GoWString(sp), types.Point{X: int(x), Y: int(y)}))
}

//export nox_xxx_drawStringWrap_43FAF0
func nox_xxx_drawStringWrap_43FAF0(font unsafe.Pointer, sp *C.wchar_t, x, y, maxW, maxH C.int) C.int {
	return C.int(noxrend.DrawStringWrapped(asFont(font), GoWString(sp), image.Rect(int(x), int(y), int(x+maxW), int(y+maxH))))
}

//export nox_xxx_drawStringWrapHL_43FD00
func nox_xxx_drawStringWrapHL_43FD00(font unsafe.Pointer, sp *C.wchar_t, x, y, maxW, maxH C.int) C.int {
	return C.int(noxrend.DrawStringWrappedHL(asFont(font), GoWString(sp), image.Rect(int(x), int(y), int(x+maxW), int(y+maxH))))
}

//export nox_xxx_bookDrawString_43FA80_43FD80
func nox_xxx_bookDrawString_43FA80_43FD80(font unsafe.Pointer, s *C.wchar_t, x, y, maxW, maxH C.int) C.int {
	return C.int(noxrend.DrawStringWrappedStyle(asFont(font), GoWString(s), image.Rect(int(x), int(y), int(x+maxW), int(y+maxH))))
}

//export nox_xxx_drawStringStyle_43F7B0
func nox_xxx_drawStringStyle_43F7B0(font unsafe.Pointer, sp *C.wchar_t, x, y C.int) C.int {
	return C.int(noxrend.DrawStringStyle(asFont(font), GoWString(sp), types.Point{X: int(x), Y: int(y)}))
}

//export nox_video_drawAnimatedImageOrCursorAt_4BE6D0
func nox_video_drawAnimatedImageOrCursorAt_4BE6D0(a1, a2, a3 C.int) {
	noxrend.nox_video_drawAnimatedImageOrCursorAt(asImageRefP(unsafe.Pointer(uintptr(a1))), types.Point{X: int(a2), Y: int(a3)})
}

func (r *NoxRender) nox_video_drawAnimatedImageOrCursorAt(ref *noxImageRef, pos types.Point) {
	if v3 := asImageP(unsafe.Pointer(uintptr(C.sub_4BE640(C.int(uintptr(unsafe.Pointer(ref.C()))), 0)))); v3 != nil {
		if C.dword_5d4594_3798728 != 0 {
			r.noxDrawCursor(v3, pos)
		} else {
			r.DrawImageAt(v3, pos)
		}
	}
}

func nox_xxx_client_435F80_draw(inp *input.Handler) bool {
	mpos := inp.GetMousePos()
	if C.nox_xxx_serverIsClosing_446180() != 0 {
		C.sub_446190()
	}
	if keyBindingsCheckActive(inp) == 0 && !noxflags.HasGame(noxflags.GameFlag4) {
		nox_xxx_setContinueMenuOrHost_43DDD0(0)
		return false
	}
	C.sub_437100()
	if C.sub_478030() == 0 && !nox_xxx_guiCursor_477600() {
		C.sub_470DE0()
	}
	ctrlEvent.nox_xxx_input_42D220(inp)
	if C.nox_xxx_get_430890() == 1 {
		C.sub_430880(0)
	}
	C.nox_xxx_clientEnumHover_476FA0()
	vp := noxGetViewport()
	ipx := int(vp.field_4) + mpos.X - int(vp.x1)
	ipy := int(vp.field_5) + mpos.Y - int(vp.y1)
	if !clientSendInput(31, uint16(ipx), uint16(ipy)) {
		return true
	}
	if !noxflags.HasGame(noxflags.GameHost) {
		C.sub_40B970()
		C.sub_40B790()
	}
	if noxflags.HasGame(noxflags.GameHost) {
		C.nox_xxx_spriteDeleteSomeList_49C4B0()
		if C.nox_netlist_receiveCli_494E90(31) == 0 {
			return true
		}
	} else {
		C.sub_43CCA0()
	}
	C.sub_49BD70(vp)
	C.sub_49BBC0()
	C.nox_xxx_polygonDrawColor_421B80()
	if nox_client_isConnected() {
		C.nox_xxx_cliToggleObsWindow_4357A0()
	}
	nox_xxx_clientDrawAll_436100_draw()
	C.sub_49BB40()
	C.sub_49BA70()
	maybeScreenshot()
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

func nox_xxx_clientDrawAll_436100_draw() {
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
	vp := getViewport()
	v6 := int(vp.x1)
	v7 := int(vp.y1)
	if memmap.Uint32(0x587000, 85744) != 0 {
		vp.height = vp.width * C.int(nox_win_height) / C.int(nox_win_width)
		v6 = (nox_win_width - int(vp.width)) / 2
		v7 = (nox_win_height - int(vp.height)) / 2
		vp.x1 = C.int(v6)
		vp.y1 = C.int(v7)
		vp.x2 = C.int(v6) + vp.width - 1
		vp.y2 = C.int(v7) + vp.height - 1
	}
	C.sub_430B50(C.int(v6), C.int(v7), vp.x2, vp.y2)
	if id := clientPlayerNetCode(); id != 0 {
		*memmap.PtrPtr(0x852978, 8) = unsafe.Pointer(C.nox_xxx_netSpriteByCodeDynamic_45A6F0(C.int(id)))
	}
	if noxflags.HasEngine(noxflags.EngineNoRendering) {
		C.nox_xxx_clientDrawAll_436100_draw_A()
	} else if memmap.Uint32(0x852978, 8) != 0 && nox_client_isConnected() {
		nox_xxx_drawAllMB_475810_draw(vp)
		C.nox_xxx_drawMinimapAndLines_4738E0()
	} else {
		noxrend.SelectColor(uint32(C.nox_color_black_2650656))
		noxrend.ClearScreen()
	}
	if C.dword_5d4594_811896 != 0 {
		C.sub_4365C0()
	}
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
		noxrend.ClearScreen()
		*memmap.PtrUint32(0x587000, 85744) = 0
	}
}

func nox_xxx_drawAllMB_475810_draw(vp *Viewport) {
	C.nox_xxx_drawAllMB_475810_draw_A(vp.C())
	if int32(vp.field_12) < 0 {
		vp.field_12 = C.int(-1 - int32(vp.field_12))
	} else if int32(vp.field_12) > 0 {
		vp.field_12 = C.int(1 - int32(vp.field_12))
	}
	*memmap.PtrInt32(0x5D4594, 1096428) = int32(C.int(vp.field_4) - vp.x1)
	C.dword_5d4594_1096432 = C.uint(C.int(vp.field_5) - vp.y1)
	xmin := int(vp.field_4) / common.GridStep
	ymin := int(vp.field_5) / common.GridStep
	nox_wallsYyy = nox_wallsYyy[:0]
	C.nox_xxx_drawBlack_496150(vp.C())
	disableDraw := false
	if asDrawable((*C.nox_drawable)(*memmap.PtrPtr(0x852978, 8))).CheckFlag31(2) || C.nox_gameDisableMapDraw_5d4594_2650672 != 0 {
		disableDraw = true
	}
	if C.nox_client_gui_flag_1556112 != 0 || disableDraw {
		noxrend.SelectColor(uint32(C.nox_color_black_2650656))
		noxrend.ClearScreen()
		C.sub_437290()
		C.dword_5d4594_3799524 = 1
		return
	}
	if memmap.Uint32(0x5D4594, 1096520) != 0 {
		noxrend.SelectColor(uint32(C.nox_color_white_2523948))
		noxrend.ClearScreen()
		noxrend.SelectColor(uint32(C.nox_color_black_2650656))
		*memmap.PtrUint32(0x5D4594, 1096520) = 0
		C.sub_437290()
		C.dword_5d4594_3799524 = 1
		return
	}
	sub_468F80(vp)
	v10 := C.nox_xxx_drawAllMB_475810_draw_B(vp.C()) != 0
	C.sub_4765F0(vp.C())
	sub_4754F0(vp)
	if v10 {
		nox_xxx_tileDrawMB_481C20(vp)
		C.sub_4C5500(vp.C())
	} else {
		noxrend.ClearScreen()
	}
	sub_475F10(vp)
	nox_client_queueWallsDraw(vp, xmin, ymin)
	nox_client_drawBackWalls(vp)
	sub_475FE0(vp)
	C.nox_video_drawCursorSelectCircle_4773C0(vp.C())
	nox_xxx_drawAllMB_475810_draw_E(vp)
	C.sub_4AFD40()
	C.sub_4C5060(vp.C())
	nox_client_maybeDrawFrontWalls(vp)
	C.nox_client_procFade_44D9F0(0)
	if noxflags.HasEngine(noxflags.EngineShowAI) {
		C.sub_476270(vp.C())
	}
	C.sub_45AB40()
	C.sub_437290()
	*memmap.PtrUint32(0x973F18, 68) = 1
	C.sub_476680()
}

type ColorInt struct {
	R, G, B int
}

const (
	// TODO: the 4x factor is for high-res; figure out what those values are
	lightGridW = 57 * 4
	lightGridH = 45 * 4
	lightGrid  = common.GridStep
)

var (
	nox_arr2_853BC0 [lightGridW][lightGridH]ColorInt
	lightsOutBuf    []uint32
)

func nox_xxx_get_57AF20() int {
	return int(C.dword_5d4594_2523804)
}

func sub_468F80(vp *Viewport) {
	// TODO: values here are similar to lightGridW and lightGridH
	C.dword_5d4594_2650676 = C.uint(46*((int(vp.field_4)+11)/46-1) - 11)
	C.dword_5d4594_2650680 = C.uint(46*((int(vp.field_5)+11)/46) - 57)
	if noxflags.HasEngine(noxflags.EngineNoSoftLights) {
		for i := 0; i < lightGridW; i++ {
			for j := 0; j < lightGridH; j++ {
				nox_arr2_853BC0[i][j].R = 255 << 16
				nox_arr2_853BC0[i][j].G = 255 << 16
				nox_arr2_853BC0[i][j].B = 255 << 16
			}
		}
	} else {
		cl := noxrend.Data().GetLightColor()
		if nox_xxx_get_57AF20() != 0 {
			cl = ColorInt{R: 50, G: 50, B: 50}
		}
		for i := 0; i < lightGridW; i++ {
			for j := 0; j < lightGridH; j++ {
				nox_arr2_853BC0[i][j].R = cl.R << 16
				nox_arr2_853BC0[i][j].G = cl.G << 16
				nox_arr2_853BC0[i][j].B = cl.B << 16
			}
		}
		const add = 100
		rect := image.Rect(
			int(vp.field_4)-add,
			int(vp.field_5)-add,
			int(vp.width)+int(vp.field_4)+add,
			int(vp.height)+int(vp.field_5)+add,
		)
		nox_xxx_forEachSprite(rect, func(dr *Drawable) {
			C.nox_xxx_cliLight16_469140(dr.C(), vp.C())
		})
	}
}

//export sub_469920
func sub_469920(p *C.nox_point) *C.char {
	if noxflags.HasEngine(noxflags.EngineNoSoftLights) {
		return (*C.char)(unsafe.Pointer(&lightsOutBuf[0]))
	}

	x := int(int32(p.x) - int32(uint32(C.dword_5d4594_2650676)))
	y := int(int32(p.y) - int32(uint32(C.dword_5d4594_2650680)))

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

	var cr1 ColorInt
	cr1.R = c00.R + xr*(c10.R-c00.R)/lightGrid
	cr1.G = c00.G + xr*(c10.G-c00.G)/lightGrid
	cr1.B = c00.B + xr*(c10.B-c00.B)/lightGrid

	var cr2 ColorInt
	cr2.R = c01.R + xr*(c11.R-c01.R)/lightGrid
	cr2.G = c01.G + xr*(c11.G-c01.G)/lightGrid
	cr2.B = c01.B + xr*(c11.B-c01.B)/lightGrid

	var res ColorInt
	res.R = cr1.R + yr*(cr2.R-cr1.R)/lightGrid
	res.G = cr1.G + yr*(cr2.G-cr1.G)/lightGrid
	res.B = cr1.B + yr*(cr2.B-cr1.B)/lightGrid

	dst := lightsOutBuf[3:]
	dst[0] = uint32(res.R >> 16)
	dst[1] = uint32(res.G >> 16)
	dst[2] = uint32(res.B >> 16)
	return (*C.char)(unsafe.Pointer(&dst[0]))
}

//export sub_4814F0
func sub_4814F0(a1 *C.nox_point) C.int {
	c1 := nox_arr2_853BC0[a1.x][a1.y+0]
	v2 := c1.R >> 8
	v3 := c1.G >> 8
	v4 := c1.B >> 8

	c2 := nox_arr2_853BC0[a1.x][a1.y+1]
	v2b := c2.R >> 8
	v3b := c2.G >> 8
	v4b := c2.B >> 8

	v8 := int(memmap.Int32(0x8529A0, uintptr(1020+4*((v2b-v2)>>8))))
	v9 := int(memmap.Int32(0x8529A0, uintptr(1020+4*((v3b-v3)>>8))))
	v10 := int(memmap.Int32(0x8529A0, uintptr(1020+4*((v4b-v4)>>8))))

	for i := 0; i < lightGrid; i++ {
		v6 := unsafe.Slice((*uint32)(unsafe.Pointer(&C.nox_arr_84EB20[280*int(a1.x)+12*i+4])), 3)
		v6[0] = uint32(int32(v2))
		v6[1] = uint32(int32(v3))
		v6[2] = uint32(int32(v4))
		v2 += v8
		v3 += v9
		v4 += v10
	}

	v6p := (*int32)(unsafe.Pointer(&C.nox_arr_84EB20[280*a1.x]))
	*v6p = int32(a1.y)
	return 7 * a1.x
}

func sub_4C1C60(a1, a2 int) int {
	return int((int64(a1) * int64(a2)) >> 16)
}

//export sub_4695E0
func sub_4695E0(a1, a2 C.int, a3p *C.int, a4, a5 C.int) {
	v5 := int(a4)
	if a5 != 0 {
		v5 = -int(a4)
	}
	a3 := unsafe.Slice((*int32)(unsafe.Pointer(a3p)), 3)
	v6 := sub_4C1C60(v5, int(a3[0])) << 8
	v7 := sub_4C1C60(v5, int(a3[1])) << 8
	v8 := sub_4C1C60(v5, int(a3[2])) << 8

	ptr := &nox_arr2_853BC0[a1][a2]

	var res ColorInt
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

func nox_xxx_tileDrawMB_481C20(vp *Viewport) {
	C.nox_xxx_waypointCounterMB_587000_154948++
	dx := int(vp.field_4) - int(vp.x1)
	dy := int(vp.field_5) - int(vp.y1)
	if C.nox_client_texturedFloors_154956 == 0 && C.dword_5d4594_1193156 == 1 {
		C.nox_client_texturedFloors2_154960 = 0
		C.nox_client_texturedFloors_154956 = 1
		C.nox_xxx_tileSetDrawFn_481420()
	}
	if C.dword_5d4594_1193156 == 1 && C.nox_client_texturedFloors2_154960 == 0 && gameFrame()%30 == 0 && C.nox_xxx_tileCheckRedrawMB_482570(vp.C()) == 0 {
		C.dword_5d4594_1193156 = 0
		C.nox_client_texturedFloors_154956 = C.nox_client_texturedFloors2_154960
		C.nox_xxx_tileSetDrawFn_481420()
	}
	if C.dword_5d4594_1193188 != 0 {
		C.nox_xxx_tileDrawImpl_4826A0(vp.C())
		C.dword_5d4594_1193188 = 0
	} else {
		C.nox_xxx_tileDrawMB_481C20_A(vp.C(), C.int(dx))
		C.nox_xxx_tileDrawMB_481C20_B(vp.C(), C.int(dy))
	}
	if C.nox_client_texturedFloors_154956 != 0 {
		C.nox_xxx_tileDrawMB_481C20_C_textured(vp.C(), C.int(dx), C.int(dy))
	} else {
		C.nox_xxx_tileDrawMB_481C20_C_solid(vp.C(), C.int(dx), C.int(dy))
	}
}

func sub_4754F0(vp *Viewport) {
	rect := image.Rect(
		int(vp.field_4), int(vp.field_5),
		int(vp.field_4+vp.width), int(vp.field_5+vp.height)+128,
	)
	nox_drawable_list_1 = nox_drawable_list_1[:0]
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
				nox_drawable_list_1 = append(nox_drawable_list_1, dr)
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
	nox_drawable_list_1 []*Drawable
	nox_drawable_list_3 []*Drawable
	nox_drawable_list_2 []*Drawable
	nox_drawable_list_4 []*Drawable

	nox_backWalls  []*Wall
	nox_frontWalls []*Wall
	nox_wallsYyy   []*Wall
)

func initDrawableLists() {
	nox_drawable_list_1 = make([]*Drawable, 0, nox_drawable_list_1_cap)
	nox_drawable_list_3 = make([]*Drawable, 0, nox_drawable_lists_cap)
	nox_drawable_list_2 = make([]*Drawable, 0, nox_drawable_lists_cap)
	nox_drawable_list_4 = make([]*Drawable, 0, nox_drawable_lists_cap)

	nox_backWalls = make([]*Wall, 0, noxDrawableWallsCap)
	nox_frontWalls = make([]*Wall, 0, noxDrawableWallsCap)
	nox_wallsYyy = make([]*Wall, 0, noxDrawableWallsCap)
}

func sub_473B30_free() {
	nox_drawable_list_1 = nil
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
	xmax := xmin + int(vp.width)/common.GridStep + 2
	ymax := ymin + int(vp.height)/common.GridStep + 4
	for y := ymin; y <= ymax; y++ {
		for x := xmin; x <= xmax; x++ {
			wl := noxServer.getWallAtGrid(types.Point{X: x, Y: y})
			if wl == nil {
				continue
			}
			if memmap.Uint8(0x85B3FC, 43076+12332*uintptr(wl.field1()))&4 == 0 {
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

func nox_xxx_drawAllMB_475810_draw_E(vp *Viewport) {
	sort.Slice(nox_drawable_list_1, func(i, j int) bool {
		a, b := nox_drawable_list_1[i], nox_drawable_list_1[j]
		return sub_476160(a, b)
	})
	sort.Slice(nox_wallsYyy, func(i, j int) bool {
		a, b := nox_wallsYyy[i], nox_wallsYyy[j]
		return C.sub_476080((*C.uchar)(a.C())) < C.sub_476080((*C.uchar)(b.C()))
	})
	arr1 := nox_drawable_list_1
	arr2 := nox_wallsYyy
	v41 := 0x7FFFFFFF
	if len(arr1) > 0 {
		v41 = arr1[0].Pos().Y
	}
	v21 := 0x7FFFFFFF
	if len(arr2) > 0 {
		v21 = int(C.sub_476080((*C.uchar)(arr2[0].C())))
	}
LOOP:
	for len(arr1) > 0 || len(arr2) > 0 {
		if v41 >= v21 {
			if len(arr2) != 0 {
				nox_xxx_drawWalls_473C10(vp, arr2[0])
				arr2 = arr2[1:]
				if len(arr2) != 0 {
					v21 = int(C.sub_476080((*C.uchar)(arr2[0].C())))
					continue
				}
			}
			v21 = 0x7FFFFFFF
			continue
		}
		if len(arr1) == 0 {
			v41 = 0x7FFFFFFF
			continue
		}
		dr := arr1[0]
		arr1 = arr1[1:]
		//nox_drawable_list_1_size--
		if len(arr1) > 0 {
			v41 = arr1[0].Pos().Y
		} else {
			v41 = 0x7FFFFFFF
		}
		if uint32(dr.field_27) == memmap.Uint32(0x5D4594, 1096448) && nox_server_teamFirst_418B10() != nil {
			for v25 := nox_xxx_cliGetSpritePlayer_45A000(); v25 != nil; v25 = v25.Field104() {
				if v25.CheckFlag31(30) {
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
		drawCreatureBackEffects(noxrend, vp, dr)
		if dr.DrawFunc(vp) == 0 {
			continue
		}
		if noxflags.HasEngine(noxflags.EngineShowExtents) {
			C.nox_thing_debug_draw(vp.C(), dr.C())
		}
		dr.field_33 = 0
		if dr.Flags70()&0x40 != 0 {
			C.nox_xxx_drawShinySpot_4C4F40(vp.C(), dr.C())
		}
		drawCreatureFrontEffects(noxrend, vp, dr)
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
	nox_drawable_list_1 = nox_drawable_list_1[:0]
}

func sub_475FE0(vp *Viewport) {
	for _, dr := range nox_drawable_list_4 {
		if C.nox_xxx_client_4984B0_drawable(dr.C()) != 0 {
			dr.field_121 = 1
			dr.DrawFunc(vp)
			if noxflags.HasEngine(noxflags.EngineShowExtents) {
				C.nox_thing_debug_draw(vp.C(), dr.C())
			}
			dr.field_33 = 0
			if dr.field_120 == 0 && dr.field_122 == 0 {
				dr.field_85 = C.uint(gameFrame())
			}
		}
	}
	nox_drawable_list_4 = nox_drawable_list_4[:0]
}

func sub_475F10(vp *Viewport) {
	for _, dr := range nox_drawable_list_3 {
		drawCreatureBackEffects(noxrend, vp, dr)
		if C.nox_xxx_client_4984B0_drawable(dr.C()) != 0 {
			dr.field_121 = 1
			dr.DrawFunc(vp)
			if dr.Flags70()&0x40 != 0 {
				C.nox_xxx_drawShinySpot_4C4F40(vp.C(), dr.C())
			}
			drawCreatureFrontEffects(noxrend, vp, dr)
			C.sub_495BB0(dr.C(), vp.C())
			if noxflags.HasEngine(noxflags.EngineShowExtents) {
				C.nox_thing_debug_draw(vp.C(), dr.C())
			}
			dr.field_33 = 0
			if dr.field_120 == 0 && dr.field_122 == 0 {
				dr.field_85 = C.uint(gameFrame())
			}
		}
	}
	nox_drawable_list_3 = nox_drawable_list_3[:0]
}

func nox_xxx_drawWalls_473C10(vp *Viewport, p *Wall) {
	C.nox_xxx_drawWalls_473C10(vp.C(), p.C())
}

func nox_client_maybeDrawFrontWalls(vp *Viewport) { // nox_client_maybeDrawFrontWalls_475810_F
	if C.nox_client_drawFrontWalls_80812 != 0 {
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
func sub_4745F0(cvp *C.nox_draw_viewport_t) {
	vp := asViewport(cvp)
	for _, dr := range nox_drawable_list_2 {
		drawCreatureBackEffects(noxrend, vp, dr)
		if C.nox_xxx_client_4984B0_drawable(dr.C()) == 0 {
			continue
		}
		dr.field_121 = 1
		C.sub_476AE0(vp.C(), dr.C())
		if dr.Flags70()&0x40 != 0 {
			C.nox_xxx_drawShinySpot_4C4F40(vp.C(), dr.C())
		}
		drawCreatureFrontEffects(noxrend, vp, dr)
		C.sub_495BB0(dr.C(), vp.C())
		if noxflags.HasEngine(noxflags.EngineShowExtents) {
			C.nox_thing_debug_draw(vp.C(), dr.C())
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
	noxrend.DrawCircleColored(int(a1), int(a2), int(a3), uint32(a4))
}

//export nox_video_drawCircle_4B0B90
func nox_video_drawCircle_4B0B90(a1, a2, a3 C.int) {
	noxrend.DrawCircle(int(a1), int(a2), int(a3))
}

func (r *NoxRender) DrawImageAt(img *Image, pos types.Point) {
	defer func() {
		if r := recover(); r != nil {
			panic(fmt.Errorf("panic drawing image %v: %v", img, r))
		}
	}()
	if C.dword_5d4594_3799452 != 0 {
		C.nox_xxx_wndDraw_49F7F0()
		C.sub_49F780(C.int(memmap.Int32(0x973F18, 52)), C.int(memmap.Int32(0x973F18, 12)))
		r.p.flag_0 = 1
	}
	r.rnd.HookImageDrawXxx = func(pos types.Point, sz types.Size) {
		*memmap.PtrInt32(0x973F18, 92) = int32(pos.X)
		*memmap.PtrInt32(0x973F18, 84) = int32(pos.Y)
		*memmap.PtrUint32(0x973F18, 88) = uint32(sz.W)
		*memmap.PtrUint32(0x973F18, 76) = uint32(sz.H)
	}
	if img != nil {
		r.rnd.DrawImage16(img, pos)
	}
	if C.dword_5d4594_3799452 != 0 {
		C.sub_49F860()
		C.dword_5d4594_3799452 = 0
	}
	r.rnd.Set_dword_5d4594_3799484(0)
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
func nox_client_drawImageAt_47D2C0(img *C.nox_video_bag_image_t, x, y C.int) {
	noxrend.DrawImageAt(asImage(img), types.Point{X: int(x), Y: int(y)})
}

func sub_47D200() {
	noxrend.Set_dword_5d4594_3799484(0)
	*memmap.PtrUint32(0x973F18, 52) = 0
	*memmap.PtrUint32(0x973F18, 12) = 0
	noxrend.Reset_dword_5d4594_3799476()
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
	noxrend.Set_dword_5d4594_37995xx(0, 0)
}

//export nox_video_getImagePixdata_func
func nox_video_getImagePixdata_func(img *C.nox_video_bag_image_t) unsafe.Pointer {
	data := asImage(img).Pixdata()
	if len(data) == 0 {
		return nil
	}
	return unsafe.Pointer(&data[0])
}

//export nox_video_getImagePixdata_42FB30
func nox_video_getImagePixdata_42FB30(img *C.nox_video_bag_image_t) unsafe.Pointer {
	data := asImage(img).Pixdata()
	if len(data) == 0 {
		return nil
	}
	return unsafe.Pointer(&data[0])
}

//export nox_video_drawImageAt2_4B0820
func nox_video_drawImageAt2_4B0820(a1 unsafe.Pointer, x, y C.int) {
	p := noxrend.asParticle(a1)
	p.DrawAt(types.Point{X: int(x), Y: int(y)})
}

func nox_draw_initColorTables_434CC0() {
	mode := noxcolor.GetMode()
	if C.nox_video_modeXxx_3801780 == 0 {
		mode = noxcolor.ModeRGBA5551
	}
	noxrend.SetColorMode(mode)
	arrR, _ := alloc.Uints16(257)
	arrG, _ := alloc.Uints16(257)
	arrB, _ := alloc.Uints16(257)
	arrR = arrR[:256]
	arrG = arrG[:256]
	arrB = arrB[:256]
	copy(arrR, noxrend.colors.R[:])
	copy(arrG, noxrend.colors.G[:])
	copy(arrB, noxrend.colors.B[:])
	C.nox_draw_colors_r_3804672 = (*C.uchar)(unsafe.Pointer(&arrR[0]))
	C.nox_draw_colors_g_3804656 = (*C.uchar)(unsafe.Pointer(&arrG[0]))
	C.nox_draw_colors_b_3804664 = (*C.uchar)(unsafe.Pointer(&arrB[0]))
}

func (r *NoxRender) SetColorMode(mode noxcolor.Mode) {
	if r.colors.mode == mode {
		return
	}
	for i := 0; i < 256; i++ {
		r.colors.R[i] = mode.RGB(byte(i), 0, 0).Color16()
		r.colors.G[i] = mode.RGB(0, byte(i), 0).Color16()
		r.colors.B[i] = mode.RGB(0, 0, byte(i)).Color16()
	}
	r.colors.mode = mode
}

var (
	drawWhiteBubbleParticle     uint32
	drawLightBlueBubbleParticle uint32
	drawRedBubbleParticle       uint32
	drawOrangeBubbleParticle    uint32
	drawYellowBubbleParticle    uint32
	drawGreenBubbleParticle     uint32
	drawWhiteSpark              uint32
	drawColorXxxLoaded1096552   bool
	drawColorXxx1096452         uint32
	drawColorXxx1096436         uint32
)

func sub_499F60(p uint32, pos types.Point, a4 int, a5, a6, a7, a8, a9 int, a10 int) {
	C.sub_499F60(C.int(p), C.int(pos.X), C.int(pos.Y), C.short(a4), C.char(a5), C.char(a6), C.char(a7), C.char(a8), C.char(a9), C.int(a10))
}

func drawCreatureBackEffects(r *NoxRender, vp *Viewport, dr *Drawable) { // nox_xxx_drawHasteAndRunParticles_4746C0
	if dr.CheckFlag31(0) && C.sub_474B40(dr.C()) == 0 {
		return
	}
	if dr.CheckFlag31(14) {
		pos := vp.toScreenPos(dr.Pos())
		r.DrawGlow(pos, uint32(C.nox_color_blue_2650684), 30, 31)
	}
	if dr.CheckFlag31(9) && !nox_xxx_checkGameFlagPause_413A50() { // Haste effect
		if drawWhiteBubbleParticle == 0 {
			drawWhiteBubbleParticle = nox_xxx_getTTByNameSpriteMB_44CFC0("WhiteBubbleParticle")
			drawLightBlueBubbleParticle = nox_xxx_getTTByNameSpriteMB_44CFC0("LightBlueBubbleParticle")
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
			pos2 := types.Point{
				X: randomIntMinMax(-10, 10),
				Y: randomIntMinMax(-10, 10) + int(*(*int16)(dr.field(104))),
			}
			sub_499F60(drawWhiteBubbleParticle, pos.Add(pos2), 1, v14, v18, 0, 0, 0, v22)

			v23 := randomIntMinMax(3, 5)
			v19 := randomIntMinMax(3, 6)
			v15 := randomIntMinMax(2, 4)
			pos3 := types.Point{
				X: randomIntMinMax(-10, 10),
				Y: randomIntMinMax(-10, 10) + int(*(*int16)(dr.field(104))),
			}
			sub_499F60(drawLightBlueBubbleParticle, pos.Add(pos3), 1, v15, v19, 0, 0, 0, v23)
		}
	}
	if dr.CheckFlag31(8) && !nox_xxx_checkGameFlagPause_413A50() { // Run effect
		if drawRedBubbleParticle == 0 {
			drawRedBubbleParticle = nox_xxx_getTTByNameSpriteMB_44CFC0("RedBubbleParticle")
			drawOrangeBubbleParticle = nox_xxx_getTTByNameSpriteMB_44CFC0("OrangeBubbleParticle")
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
			pos2 := types.Point{
				X: randomIntMinMax(-10, 10),
				Y: randomIntMinMax(-10, 10) + int(*(*int16)(dr.field(104))),
			}
			sub_499F60(drawRedBubbleParticle, pos.Add(pos2), 1, v16, v20, 0, 0, 0, v24)

			v25 := randomIntMinMax(3, 5)
			v21 := randomIntMinMax(3, 6)
			v17 := randomIntMinMax(2, 4)
			pos3 := types.Point{
				X: randomIntMinMax(-10, 10),
				Y: randomIntMinMax(-10, 10) + int(*(*int16)(dr.field(104))),
			}
			sub_499F60(drawOrangeBubbleParticle, pos.Add(pos3), 1, v17, v21, 0, 0, 0, v25)
		}
	}
	// Protection effects
	if dr.CheckFlag31(17) {
		r.drawProtectEffectDefault(vp, dr.Pos(), dr, 0, 0, memmap.Uint32(0x85B3FC, 940), uint32(C.nox_color_red_2589776), true)
	}
	if dr.CheckFlag31(18) {
		r.drawProtectEffectDefault(vp, dr.Pos(), dr, 85, 1, memmap.Uint32(0x8531A0, 2572), uint32(C.nox_color_green_2614268), true)
	}
	if dr.CheckFlag31(20) {
		r.drawProtectEffectDefault(vp, dr.Pos(), dr, 170, 2, uint32(C.nox_color_blue_2650684), uint32(C.nox_color_white_2523948), true)
	}
	if dr.CheckFlag31(27) { // Shield effects
		switch *(*byte)(dr.field(297)) {
		case 0, 1, 2:
			C.nox_xxx_drawShield_499810(vp.C(), dr.C())
		}
	}
}

func drawCreatureFrontEffects(r *NoxRender, vp *Viewport, dr *Drawable) { // nox_xxx_drawEffectsMB_474E60
	if dr.CheckFlag31(0) && C.sub_474B40(dr.C()) == 0 {
		return
	}
	if dr.CheckFlag31(22) {
		if drawWhiteSpark == 0 {
			drawWhiteSpark = nox_xxx_getTTByNameSpriteMB_44CFC0("WhiteSpark")
		}
		pos := dr.Pos()
		C.nox_xxx_drawEnergyBolt_499710(C.int(pos.X), C.int(pos.Y), C.short(*(*int16)(dr.field(104))), C.int(drawWhiteSpark))
	}
	if dr.CheckFlag31(3) || dr.CheckFlag31(5) || dr.CheckFlag31(29) || dr.CheckFlag31(28) {
		pos := vp.toScreenPos(dr.Pos())
		v5 := 5 - int(*(*int16)(dr.field(106))) - int(*(*int16)(dr.field(104))) - int(dr.Field25())
		v6 := *(*byte)(dr.field(112))
		pos.Y += v5
		if v6&0x4 != 0 && *(*uint32)(dr.field(276)) == 6 {
			v8 := 8 * uintptr(*(*byte)(dr.field(297)))
			pos.X += int(memmap.Int32(0x587000, 149432+v8))
			pos.Y += int(memmap.Int32(0x587000, 149436+v8))
		}
		if dr.CheckFlag31(29) {
			r.Data().setField17(1)
			C.sub_433E40(C.int(C.nox_color_blue_2650684))
		}
		r.nox_video_drawAnimatedImageOrCursorAt(asImageRefP(*memmap.PtrPtr(0x5D4594, 1096456)), pos.Add(types.Point{X: -64, Y: -64}))
		r.Data().setField17(0)
	}
	if dr.CheckFlag31(4) && !nox_xxx_checkGameFlagPause_413A50() {
		v11 := int(*(*float32)(dr.field(48)))
		v44 := int(dr.Field25() * 0.5)
		if drawYellowBubbleParticle == 0 {
			drawYellowBubbleParticle = nox_xxx_getTTByNameSpriteMB_44CFC0("YellowBubbleParticle")
		}
		pos := dr.Pos()
		for v12 := 0; v12 < 2; v12++ {
			v40 := randomIntMinMax(3, 5)
			v36 := randomIntMinMax(3, 6)
			v34 := randomIntMinMax(1, 2)
			v32 := randomIntMinMax(0, v44)
			pos2 := types.Point{
				X: randomIntMinMax(-v11, v11),
				Y: randomIntMinMax(-v11, v11),
			}
			sub_499F60(drawYellowBubbleParticle, pos.Add(pos2), v32, v34, v36, -5, 0, 0, v40)
		}
	}
	if dr.CheckFlag31(21) && !nox_xxx_checkGameFlagPause_413A50() {
		if drawGreenBubbleParticle == 0 {
			drawGreenBubbleParticle = nox_xxx_getTTByNameSpriteMB_44CFC0("GreenBubbleParticle")
		}
		pos := dr.Pos()
		v41 := randomIntMinMax(2, 3)
		v37 := randomIntMinMax(3, 6)
		v35 := randomIntMinMax(2, 4)
		v29 := int(dr.Field25()) + 12
		v14 := int(dr.Field25())
		v33 := randomIntMinMax(v14+8, v29)
		pos2 := types.Point{
			X: randomIntMinMax(-6, 6),
			Y: randomIntMinMax(-10, 10),
		}
		sub_499F60(drawGreenBubbleParticle, pos.Add(pos2), v33, v35, v37, 1, 0, 0, v41)
	}
	if dr.CheckFlag31(13) && !nox_xxx_checkGameFlagPause_413A50() {
		if !drawColorXxxLoaded1096552 {
			drawColorXxx1096452 = noxcolor.ExtendColor16(noxcolor.RGBColor(255, 0, 255))
			drawColorXxx1096436 = noxcolor.ExtendColor16(noxcolor.RGBColor(255, 180, 255))
			drawColorXxxLoaded1096552 = true
		}
		pos := vp.toScreenPos(dr.Pos())

		for v16 := 0; v16 < 10; v16++ {
			v17 := randomIntMinMax(1, 2)
			v38 := int(*(*float32)(dr.field(48)))
			v18 := int(*(*float32)(dr.field(48)))
			v20 := int(dr.Field25())
			pos2 := pos.Add(types.Point{
				X: randomIntMinMax(-v18, v38),
				Y: randomIntMinMax(-10-v20, 0) + int(*(*int16)(dr.field(104))),
			})
			v22 := randomIntMinMax(3, 4)
			r.DrawGlow(pos2, drawColorXxx1096452, v17+v22, v17+2)
			r.SetColor2(drawColorXxx1096436)
			r.DrawPoint(pos2, v17)
		}
	}
	if dr.CheckFlag31(17) {
		r.drawProtectEffectDefault(vp, dr.Pos(), dr, 0, 0, memmap.Uint32(0x85B3FC, 940), uint32(C.nox_color_red_2589776), false)
	}
	if dr.CheckFlag31(18) {
		r.drawProtectEffectDefault(vp, dr.Pos(), dr, 85, 1, memmap.Uint32(0x8531A0, 2572), uint32(C.nox_color_green_2614268), false)
	}
	if dr.CheckFlag31(20) {
		r.drawProtectEffectDefault(vp, dr.Pos(), dr, 170, 2, uint32(C.nox_color_blue_2650684), uint32(C.nox_color_white_2523948), false)
	}
	if dr.CheckFlag31(26) {
		pos := vp.toScreenPos(dr.Pos())
		v23 := *(*uint32)(dr.field(276))
		v24 := -90 - int(*(*int16)(dr.field(104)))
		pos.X -= 64
		pos.Y += v24
		if v23 == 6 {
			v26 := 8 * uintptr(*(*byte)(dr.field(297)))
			pos.X += int(memmap.Int32(0x587000, 149504+v26))
			pos.Y += int(memmap.Int32(0x587000, 149508+v26))
		}
		r.SetAlphaEnabled(true)
		r.SetAlpha(0x80)
		r.nox_video_drawAnimatedImageOrCursorAt(asImageRefP(*memmap.PtrPtr(0x5D4594, 1096460)), pos)
		r.SetAlphaEnabled(false)
	}
	if dr.CheckFlag31(27) {
		switch *(*byte)(dr.field(297)) {
		default:
			C.nox_xxx_drawShield_499810(vp.C(), dr.C())
		case 0, 1, 2:
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
