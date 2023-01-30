package opennox

import (
	"fmt"
	"image"
	"image/color"
	"unsafe"

	noxcolor "github.com/noxworld-dev/opennox-lib/color"
	"github.com/noxworld-dev/opennox-lib/common"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
)

const (
	// TODO: the 4x factor is for high-res; figure out what those values are
	lightGridW = 57 * 4
	lightGridH = 45 * 4
	lightGrid  = common.GridStep
)

var _ = [1]struct{}{}[1056-unsafe.Sizeof(noxrender.RenderData{})]
var _ = [1]struct{}{}[48-unsafe.Sizeof(noxrender.RenderMat{})]

var (
	nox_video_renderTargetFlags          = 0
	nox_client_texturedFloors_154956     = true
	nox_client_texturedFloors2_154960    = true
	nox_client_lockHighResFloors_1193152 = false
	nox_client_showTooltips_80840        = true
	nox_client_drawFrontWalls_80812      = true
	partViewportOff                      image.Point
)

type tileMapXxx struct {
	arr [32]int
}

type nox_arr_84EB20_t struct {
	Y  int
	Cl [common.GridStep]noxrender.RGB
}

type clientTileData struct {
	noxTilesGpx    int
	noxTilesGpy    int
	noxTileBuf     []uint16
	noxTileBufFree func()
	nox_arr_956A00 [noxMaxHeight + 150]int
	nox_arr_957820 [noxMaxHeight + 150]tileMapXxx

	dword_5d4594_3679320 int
	dword_5d4594_3798156 int
	dword_5d4594_3798812 int
	dword_5d4594_3798800 int
	dword_5d4594_3798816 int
	dword_5d4594_3798808 int
	dword_5d4594_3798804 int

	nox_arr2_853BC0  [lightGridW][lightGridH]noxrender.RGB
	nox_arr_84EB20   [lightGridW]nox_arr_84EB20_t
	lightsOutBuf     []uint32
	nox_light_8529A0 [512]int
}

func sub_473970(a1 image.Point) image.Point {
	return partViewportOff.Add(a1)
}

func partOffsetPos(p image.Point) image.Point {
	return p.Sub(partViewportOff)
}

func sub_4739D0(a1 int) int { return a1 - partViewportOff.Y }

func get_nox_client_texturedFloors_154956() bool {
	return nox_client_texturedFloors_154956
}

func sub_437260() {
	vp := noxClient.Viewport()
	noxClient.r.setClipRects(vp.Screen.Min, vp.Size)
}

func sub_437180() {
	legacy.Sub_437180()
}

func nox_xxx_cliUpdateCameraPos_435600(x, y int) {
	vp := noxClient.Viewport()
	*memmap.PtrInt32(0x5D4594, 811364) = int32(vp.World.Max.X)
	*memmap.PtrInt32(0x5D4594, 811368) = int32(vp.World.Max.Y)
	vp.World.Min.X = x - vp.Size.X/2
	vp.World.Min.Y = y + vp.Field12 - vp.Size.Y/2
	vp.World.Max.X = x
	vp.World.Max.Y = y + vp.Field12
}

var _ = [1]struct{}{}[52-unsafe.Sizeof(noxrender.Viewport{})]
var _ = [1]struct{}{}[4-unsafe.Sizeof(int(0))]

func detectBestVideoSettings() {
	const cfg = 450
	cut := 0
	*memmap.PtrUint32(0x587000, 80808) = 1
	*memmap.PtrUint32(0x587000, 80816) = 1
	nox_client_showTooltips_80840 = true
	nox_client_renderGUI_80828 = true
	nox_xxx_xxxRenderGUI_587000_80832 = true
	if cfg == 0 {
		//v4 = 8
		cut = 75
		nox_client_drawFrontWalls_80812 = false
		legacy.Set_nox_client_translucentFrontWalls_805844(0)
		legacy.Set_nox_client_highResFrontWalls_80820(0)
		legacy.Set_nox_client_highResFloors_154952(0)
		nox_client_lockHighResFloors_1193152 = false
		nox_client_texturedFloors_154956 = true
		guiCon.translucent = false
		noxClient.r.Part.RenderGlow = false
		legacy.Set_nox_client_fadeObjects_80836(0)
		noxflags.UnsetEngine(noxflags.EngineSoftShadowEdge)
		legacy.Set_nox_client_renderBubbles_80844(0)
	} else if cfg == 200 {
		//v4 = 8
		cut = 85
		nox_client_drawFrontWalls_80812 = true
		legacy.Set_nox_client_translucentFrontWalls_805844(0)
		legacy.Set_nox_client_highResFrontWalls_80820(0)
		legacy.Set_nox_client_highResFloors_154952(0)
		nox_client_lockHighResFloors_1193152 = false
		nox_client_texturedFloors_154956 = true
		guiCon.translucent = false
		noxClient.r.Part.RenderGlow = false
		legacy.Set_nox_client_fadeObjects_80836(0)
		noxflags.UnsetEngine(noxflags.EngineSoftShadowEdge)
		legacy.Set_nox_client_renderBubbles_80844(0)
	} else if cfg == 266 {
		//v4 = 8
		cut = 100
		nox_client_drawFrontWalls_80812 = true
		legacy.Set_nox_client_translucentFrontWalls_805844(1)
		legacy.Set_nox_client_highResFrontWalls_80820(1)
		legacy.Set_nox_client_highResFloors_154952(1)
		nox_client_lockHighResFloors_1193152 = false
		nox_client_texturedFloors_154956 = true
		guiCon.translucent = false
		noxClient.r.Part.RenderGlow = true
		legacy.Set_nox_client_fadeObjects_80836(1)
		noxflags.SetEngine(noxflags.EngineSoftShadowEdge)
		legacy.Set_nox_client_renderBubbles_80844(1)
	} else if cfg == 300 {
		//v4 = 16
		cut = 100
		nox_client_drawFrontWalls_80812 = true
		legacy.Set_nox_client_translucentFrontWalls_805844(1)
		legacy.Set_nox_client_highResFrontWalls_80820(1)
		legacy.Set_nox_client_highResFloors_154952(1)
		nox_client_lockHighResFloors_1193152 = false
		nox_client_texturedFloors_154956 = true
		guiCon.translucent = false
		noxClient.r.Part.RenderGlow = true
		legacy.Set_nox_client_fadeObjects_80836(1)
		noxflags.SetEngine(noxflags.EngineSoftShadowEdge)
		legacy.Set_nox_client_renderBubbles_80844(1)
	} else if cfg == 450 {
		//v4 = 16
		cut = 100
		nox_client_drawFrontWalls_80812 = true
		legacy.Set_nox_client_translucentFrontWalls_805844(1)
		legacy.Set_nox_client_highResFrontWalls_80820(1)
		legacy.Set_nox_client_highResFloors_154952(1)
		nox_client_lockHighResFloors_1193152 = true
		nox_client_texturedFloors_154956 = true
		guiCon.translucent = true
		noxClient.r.Part.RenderGlow = true
		legacy.Set_nox_client_fadeObjects_80836(1)
		noxflags.SetEngine(noxflags.EngineSoftShadowEdge)
		legacy.Set_nox_client_renderBubbles_80844(1)
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

func sub_4347F0(a1 unsafe.Pointer, a2 int) {
	if a2 <= 256 {
		legacy.Sub_435120(memmap.PtrOff(0x973F18, 3880), a1)
		legacy.Sub_435040()
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
		legacy.Sub_435150(v2, memmap.PtrOff(0x973F18, 3880))
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

func sub433E40(cl noxcolor.Color) int {
	c := cl.ColorNRGBA()
	return int(noxClient.r.SetColorMultAndIntensityRGB(c.R, c.G, c.B))
}

func (r *NoxRender) setColorMultAndIntensity(cl color.Color) {
	c := noxcolor.ToRGBA5551Color(cl).ColorNRGBA()
	r.SetColorMultAndIntensityRGB(c.R, c.G, c.B)
}

func (r *NoxRender) SetColorMultAndIntensityRGB(cr, cg, cb byte) byte {
	d := r.Data()
	d.SetFlag16(cr == 0xFF && cg == 0xFF && cb == 0xFF)
	d.SetColorMultA(noxrender.Color16{R: uint16(cr), G: uint16(cg), B: uint16(cb)})
	v := r.ColorIntensity(cr, cg, cb)
	d.Intensity258 = uint16(v)
	return v
}

func (r *NoxRender) Sub_49F7C0_def_go() {
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

func (r *NoxRender) SetRectFullScreen() { // sub_437290
	sz := r.PixBufferRect().Size()
	r.setClipRects(image.Pt(0, 0), sz)
}

func sub_480860(dst, src []uint16, w int, a4p, a5p []uint32) {
	for i := 0; i < w; i++ {
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

type NoxRender struct {
	*noxrender.NoxRender

	colors struct {
		R [256]uint16
		G [256]uint16
		B [256]uint16
	}

	circleSeg circleSegments
	partfx    partFXes
}

func NewNoxRender(cr *noxrender.NoxRender) *NoxRender {
	r := &NoxRender{
		NoxRender: cr,
	}
	r.initColorTables()
	return r
}

func (c *Client) Nox_video_drawAnimatedImageOrCursorAt(ref *legacy.ImageRef, pos image.Point) {
	if fr := c.getCursorAnimFrame(ref, 0); fr != nil {
		if c.flag3798728 {
			c.r.noxDrawCursor(fr, pos)
		} else {
			c.r.DrawImageAt(fr, pos)
		}
	}
}

const (
	lightMinIntensity = 1.0
)

func (c *Client) Sub469920(p image.Point) []uint32 {
	if noxflags.HasEngine(noxflags.EngineNoSoftLights) {
		return c.tiles.lightsOutBuf
	}

	x := int(int32(p.X) - int32(c.tiles.noxTilesGpx))
	y := int(int32(p.Y) - int32(c.tiles.noxTilesGpy))

	xd := x / lightGrid
	yd := y / lightGrid
	if xd < 0 || yd < 0 || xd+1 >= lightGridW || yd+1 >= lightGridH {
		return c.tiles.lightsOutBuf
	}

	xr := x % lightGrid
	yr := y % lightGrid

	c00 := c.tiles.nox_arr2_853BC0[xd+0][yd+0]
	c10 := c.tiles.nox_arr2_853BC0[xd+1][yd+0]
	c01 := c.tiles.nox_arr2_853BC0[xd+0][yd+1]
	c11 := c.tiles.nox_arr2_853BC0[xd+1][yd+1]

	var cr1 noxrender.RGB
	cr1.R = c00.R + xr*(c10.R-c00.R)/lightGrid
	cr1.G = c00.G + xr*(c10.G-c00.G)/lightGrid
	cr1.B = c00.B + xr*(c10.B-c00.B)/lightGrid

	var cr2 noxrender.RGB
	cr2.R = c01.R + xr*(c11.R-c01.R)/lightGrid
	cr2.G = c01.G + xr*(c11.G-c01.G)/lightGrid
	cr2.B = c01.B + xr*(c11.B-c01.B)/lightGrid

	var res noxrender.RGB
	res.R = cr1.R + yr*(cr2.R-cr1.R)/lightGrid
	res.G = cr1.G + yr*(cr2.G-cr1.G)/lightGrid
	res.B = cr1.B + yr*(cr2.B-cr1.B)/lightGrid

	dst := c.tiles.lightsOutBuf[3:]
	dst[0] = uint32(res.R >> 16)
	dst[1] = uint32(res.G >> 16)
	dst[2] = uint32(res.B >> 16)
	return dst
}

func (c *Client) noxTileUpdateLightXxx(p image.Point) {
	c1 := c.tiles.nox_arr2_853BC0[p.X][p.Y+0]
	c1r := c1.R >> 8
	c1g := c1.G >> 8
	c1b := c1.B >> 8

	c2 := c.tiles.nox_arr2_853BC0[p.X][p.Y+1]
	c2r := c2.R >> 8
	c2g := c2.G >> 8
	c2b := c2.B >> 8

	dcr := c.tiles.nox_light_8529A0[255+(c2r-c1r)>>8]
	dcg := c.tiles.nox_light_8529A0[255+(c2g-c1g)>>8]
	dcb := c.tiles.nox_light_8529A0[255+(c2b-c1b)>>8]

	for i := 0; i < lightGrid; i++ {
		c.tiles.nox_arr_84EB20[p.X].Cl[i] = noxrender.RGB{R: c1r, G: c1g, B: c1b}
		c1r += dcr
		c1g += dcg
		c1b += dcb
	}
	c.tiles.nox_arr_84EB20[p.X].Y = p.Y
}

func nox_xxx_setupSomeVideo_47FEF0() {
	*memmap.PtrPtr(0x973F18, 7716) = legacy.Get_sub_480250()
	*memmap.PtrPtr(0x973F18, 5248) = legacy.Get_sub_480220()
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

func (c *Client) nox_xxx_initSight_485F80() {
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
		c.tiles.nox_light_8529A0[i] = ((i - 253) * 256) / 22
	}
	c.tiles.nox_light_8529A0[256] = 0
	for i := 0; i < 256; i++ {
		c.tiles.nox_light_8529A0[255+i] = (i * 256) / 22
	}
}

func (c *Client) nox_xxx_tileInitBuf_430DB0(width, height int) {
	c.tiles.dword_5d4594_3798812 = width/(2*common.GridStep) + 4
	c.tiles.dword_5d4594_3798800 = (2 * common.GridStep) * c.tiles.dword_5d4594_3798812
	c.tiles.dword_5d4594_3798816 = height/(2*common.GridStep) + 3
	c.tiles.dword_5d4594_3798808 = (2 * common.GridStep) * c.tiles.dword_5d4594_3798816
	c.tiles.dword_5d4594_3798804 = ((2 * common.GridStep) * c.tiles.dword_5d4594_3798812) * 2
	legacy.Set_dword_5d4594_3798812(c.tiles.dword_5d4594_3798812)
	legacy.Set_dword_5d4594_3798800(c.tiles.dword_5d4594_3798800)
	legacy.Set_dword_5d4594_3798816(c.tiles.dword_5d4594_3798816)
	legacy.Set_dword_5d4594_3798808(c.tiles.dword_5d4594_3798808)
	legacy.Set_dword_5d4594_3798804(c.tiles.dword_5d4594_3798804)
	legacy.Set_dword_5d4594_3798820(0)
	legacy.Set_dword_5d4594_3798824(0)
	legacy.Set_dword_5d4594_3798828(0)
	legacy.Set_dword_5d4594_3798832(0)
	legacy.Set_dword_5d4594_3798836(0)
	legacy.Set_dword_5d4594_3798840(0)

	sz := c.tiles.dword_5d4594_3798804 * (2 * common.GridStep) * c.tiles.dword_5d4594_3798816
	c.tiles.noxTileBuf, c.tiles.noxTileBufFree = alloc.Make([]uint16{}, sz/2)
	legacy.Set_nox_video_tileBuf_ptr_3798796(unsafe.Pointer(&c.tiles.noxTileBuf[0]))
	legacy.Set_nox_video_tileBuf_end_3798844(unsafe.Add(unsafe.Pointer(&c.tiles.noxTileBuf[0]), sz))

	if c.tiles.lightsOutBuf == nil {
		c.tiles.lightsOutBuf, _ = alloc.Make([]uint32{}, 6)
		c.tiles.lightsOutBuf[0] = 255
		c.tiles.lightsOutBuf[1] = 255
		c.tiles.lightsOutBuf[2] = 255
	}
}

func (c *Client) nox_video_freeFloorBuffer_430EC0() {
	if c.tiles.noxTileBuf != nil {
		c.tiles.noxTileBufFree()
		c.tiles.noxTileBuf = nil
		c.tiles.noxTileBufFree = nil
	}
	c.sub_444C50()
}

func nox_xxx_tileSetDrawFn_481420() {
	if nox_client_texturedFloors_154956 {
		legacy.Set_func_587000_154940(legacy.Get_nox_xxx_tileDraw_4815E0())
		legacy.Set_func_587000_154944(legacy.Get_nox_xxx_drawTexEdgesProbably_481900())
	} else {
		legacy.Set_func_587000_154940(legacy.Get_sub_481770())
		legacy.Set_func_587000_154944(legacy.Get_nullsub_8())
	}
	legacy.Set_dword_5d4594_1193188(1)
}

const (
	nox_drawable_list_1_cap = 8192
	nox_drawable_lists_cap  = 512

	noxDrawableWallsCap = 256
)

var (
	nox_drawable_objects_queue []*client.Drawable
	nox_drawable_list_3        []*client.Drawable
	nox_drawable_list_2        []*client.Drawable
	nox_drawable_list_4        []*client.Drawable

	nox_backWalls  []*Wall
	nox_frontWalls []*Wall
	nox_wallsYyy   []*Wall
)

func initDrawableLists() {
	nox_drawable_objects_queue = make([]*client.Drawable, 0, nox_drawable_list_1_cap)
	nox_drawable_list_3 = make([]*client.Drawable, 0, nox_drawable_lists_cap)
	nox_drawable_list_2 = make([]*client.Drawable, 0, nox_drawable_lists_cap)
	nox_drawable_list_4 = make([]*client.Drawable, 0, nox_drawable_lists_cap)

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

func nox_xxx_drawList1096512_Append_4754C0(p unsafe.Pointer) {
	nox_wallsYyy = append(nox_wallsYyy, asWall(p))
}

func (c *Client) sub4745F0(vp *noxrender.Viewport) {
	for _, dr := range nox_drawable_list_2 {
		c.drawCreatureBackEffects(vp, dr)
		if legacy.Nox_xxx_client_4984B0_drawable(dr) == 0 {
			continue
		}
		dr.Field_121 = 1
		legacy.Sub_476AE0(vp, dr)
		if dr.Flags70()&0x40 != 0 {
			legacy.Nox_xxx_drawShinySpot_4C4F40(vp, dr)
		}
		c.drawCreatureFrontEffects(vp, dr)
		legacy.Sub_495BB0(dr, vp)
		if noxflags.HasEngine(noxflags.EngineShowExtents) {
			nox_thing_debug_draw(vp, dr)
		}
		dr.Field_33 = 0
		if dr.Field_120 == 0 && dr.Field_122 == 0 {
			dr.Field_85 = c.srv.Frame()
		}
	}
	nox_drawable_list_2 = nox_drawable_list_2[:0]
}

func (r *NoxRender) DrawImageAt(img *noxrender.Image, pos image.Point) {
	defer func() {
		if r := recover(); r != nil {
			panic(fmt.Errorf("panic drawing image %v: %v", img, r))
		}
	}()
	if legacy.Get_dword_5d4594_3799452() != 0 {
		legacy.Nox_xxx_wndDraw_49F7F0()
		legacy.Sub_49F780(int(memmap.Int32(0x973F18, 52)), int(memmap.Int32(0x973F18, 12)))
		r.Data().SetClip(true)
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
	if legacy.Get_dword_5d4594_3799452() != 0 {
		legacy.Sub_49F860()
		legacy.Set_dword_5d4594_3799452(0)
	}
	r.Set_dword_5d4594_3799484(0)
	*memmap.PtrUint32(0x973F18, 120) = 0
	if memmap.Uint32(0x973F18, 68) != 0 && img != nil {
		if memmap.Uint32(0x973F18, 92) != uint32(img.Field_1_0) || memmap.Uint32(0x973F18, 84) != uint32(img.Field_1_1) {
			noxClient.GUI.ValYYY = 1
		}
		img.Field_1_0 = uint16(memmap.Uint32(0x973F18, 92))
		img.Field_1_1 = uint16(memmap.Uint32(0x973F18, 84))
	}
}

func sub_47D200() {
	noxClient.r.Set_dword_5d4594_3799484(0)
	*memmap.PtrUint32(0x973F18, 52) = 0
	*memmap.PtrUint32(0x973F18, 12) = 0
	noxClient.r.Reset_dword_5d4594_3799476()
	legacy.Set_dword_5d4594_3799452(0)
	*memmap.PtrUint32(0x973F18, 44) = 0
	*memmap.PtrUint32(0x973F18, 104) = 0
	*memmap.PtrUint32(0x973F18, 8) = 0
	*memmap.PtrUint32(0x973F18, 36) = 0
	*memmap.PtrUint32(0x973F18, 32) = 0
	*memmap.PtrUint32(0x973F18, 100) = 0
	*memmap.PtrUint32(0x973F18, 20) = 0
	*memmap.PtrUint32(0x973F18, 120) = 0
	*memmap.PtrUint32(0x973F18, 68) = 0
	noxClient.GUI.ValYYY = 0
	noxClient.GUI.ValXXX = 0
	noxClient.r.SetInterlacing(false, 0)
}

func (r *NoxRender) initColorTables() {
	for i := 0; i < 256; i++ {
		r.colors.R[i] = noxcolor.RGB5551Color(byte(i), 0, 0).Color16()
		r.colors.G[i] = noxcolor.RGB5551Color(0, byte(i), 0).Color16()
		r.colors.B[i] = noxcolor.RGB5551Color(0, 0, byte(i)).Color16()
	}
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

func (c *Client) drawCreatureBackEffects(vp *noxrender.Viewport, dr *client.Drawable) {
	if dr.HasEnchant(server.ENCHANT_INVISIBLE) && legacy.Sub_474B40(dr) == 0 {
		return
	}
	if dr.HasEnchant(server.ENCHANT_ANCHORED) {
		pos := vp.ToScreenPos(dr.Pos())
		c.r.DrawGlow(pos, nox_color_blue_2650684, 30, 31)
	}
	if dr.HasEnchant(server.ENCHANT_HASTED) && !nox_xxx_checkGameFlagPause_413A50() {
		if drawWhiteBubbleParticle == 0 {
			drawWhiteBubbleParticle = c.Things.IndByID("WhiteBubbleParticle")
			drawLightBlueBubbleParticle = c.Things.IndByID("LightBlueBubbleParticle")
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
				Y: randomIntMinMax(-10, 10) + dr.Z(),
			}
			legacy.Sub_499F60(drawWhiteBubbleParticle, pos.Add(pos2), 1, v14, v18, 0, 0, 0, v22)

			v23 := randomIntMinMax(3, 5)
			v19 := randomIntMinMax(3, 6)
			v15 := randomIntMinMax(2, 4)
			pos3 := image.Point{
				X: randomIntMinMax(-10, 10),
				Y: randomIntMinMax(-10, 10) + dr.Z(),
			}
			legacy.Sub_499F60(drawLightBlueBubbleParticle, pos.Add(pos3), 1, v15, v19, 0, 0, 0, v23)
		}
	}
	if dr.HasEnchant(server.ENCHANT_RUN) && !nox_xxx_checkGameFlagPause_413A50() {
		if drawRedBubbleParticle == 0 {
			drawRedBubbleParticle = c.Things.IndByID("RedBubbleParticle")
			drawOrangeBubbleParticle = c.Things.IndByID("OrangeBubbleParticle")
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
				Y: randomIntMinMax(-10, 10) + dr.Z(),
			}
			legacy.Sub_499F60(drawRedBubbleParticle, pos.Add(pos2), 1, v16, v20, 0, 0, 0, v24)

			v25 := randomIntMinMax(3, 5)
			v21 := randomIntMinMax(3, 6)
			v17 := randomIntMinMax(2, 4)
			pos3 := image.Point{
				X: randomIntMinMax(-10, 10),
				Y: randomIntMinMax(-10, 10) + dr.Z(),
			}
			legacy.Sub_499F60(drawOrangeBubbleParticle, pos.Add(pos3), 1, v17, v21, 0, 0, 0, v25)
		}
	}
	// Protection effects
	if dr.HasEnchant(server.ENCHANT_PROTECT_FROM_FIRE) {
		c.DrawProtectEffectDefault(vp, dr.Pos(), dr, 0, 0, nox_color_red, nox_color_red_2589776, true)
	}
	if dr.HasEnchant(server.ENCHANT_PROTECT_FROM_POISON) {
		c.DrawProtectEffectDefault(vp, dr.Pos(), dr, 85, 1, nox_color_green, nox_color_green_2614268, true)
	}
	if dr.HasEnchant(server.ENCHANT_PROTECT_FROM_ELECTRICITY) {
		c.DrawProtectEffectDefault(vp, dr.Pos(), dr, 170, 2, nox_color_blue_2650684, nox_color_white_2523948, true)
	}
	if dr.HasEnchant(server.ENCHANT_REFLECTIVE_SHIELD) { // Shield effects
		switch dr.Field_74_2 {
		case 0, 1, 2:
			legacy.Nox_xxx_drawShield_499810(vp, dr)
		}
	}
}

func (c *Client) drawCreatureFrontEffects(vp *noxrender.Viewport, dr *client.Drawable) {
	if dr.HasEnchant(server.ENCHANT_INVISIBLE) && legacy.Sub_474B40(dr) == 0 {
		return
	}
	if dr.HasEnchant(server.ENCHANT_SHOCK) {
		if drawWhiteSpark == 0 {
			drawWhiteSpark = c.Things.IndByID("WhiteSpark")
		}
		pos := dr.Pos()
		legacy.Nox_xxx_drawEnergyBolt_499710(pos.X, pos.Y, dr.Z(), drawWhiteSpark)
	}
	if dr.HasEnchant(server.ENCHANT_CONFUSED) || dr.HasEnchant(server.ENCHANT_HELD) || dr.HasEnchant(server.ENCHANT_ANTI_MAGIC) || dr.HasEnchant(server.ENCHANT_CHARMING) {
		pos := vp.ToScreenPos(dr.Pos())
		v5 := 5 - int(int16(dr.Field_26_1)) - dr.Z() - int(dr.Field25())
		pos.Y += v5
		if dr.Flags28Val&0x4 != 0 && dr.Field_69 == 6 {
			v8 := 8 * uintptr(dr.Field_74_2)
			pos.X += int(memmap.Int32(0x587000, 149432+v8))
			pos.Y += int(memmap.Int32(0x587000, 149436+v8))
		}
		if dr.HasEnchant(server.ENCHANT_ANTI_MAGIC) {
			c.r.Data().SetColorize17(1)
			sub433E40(nox_color_blue_2650684)
		}
		c.Nox_video_drawAnimatedImageOrCursorAt(legacy.AsImageRefP(*memmap.PtrPtr(0x5D4594, 1096456)), pos.Add(image.Point{X: -64, Y: -64}))
		c.r.Data().SetColorize17(0)
	}
	if dr.HasEnchant(server.ENCHANT_SLOWED) && !nox_xxx_checkGameFlagPause_413A50() {
		v11 := int(dr.Shape.Circle.R)
		v44 := int(dr.Field25() * 0.5)
		if drawYellowBubbleParticle == 0 {
			drawYellowBubbleParticle = c.Things.IndByID("YellowBubbleParticle")
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
			legacy.Sub_499F60(drawYellowBubbleParticle, pos.Add(pos2), v32, v34, v36, -5, 0, 0, v40)
		}
	}
	if dr.HasEnchant(server.ENCHANT_INFRAVISION) && !nox_xxx_checkGameFlagPause_413A50() {
		if drawGreenBubbleParticle == 0 {
			drawGreenBubbleParticle = c.Things.IndByID("GreenBubbleParticle")
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
		legacy.Sub_499F60(drawGreenBubbleParticle, pos.Add(pos2), v33, v35, v37, 1, 0, 0, v41)
	}
	if dr.HasEnchant(server.ENCHANT_VAMPIRISM) && !nox_xxx_checkGameFlagPause_413A50() {
		pos := vp.ToScreenPos(dr.Pos())

		for v16 := 0; v16 < 10; v16++ {
			v17 := randomIntMinMax(1, 2)
			r := int(dr.Shape.Circle.R)
			v20 := int(dr.Field25())
			pos2 := pos.Add(image.Point{
				X: randomIntMinMax(-r, r),
				Y: randomIntMinMax(-10-v20, 0) + dr.Z(),
			})
			v22 := randomIntMinMax(3, 4)
			c.r.DrawGlow(pos2, drawColorPurple, v17+v22, v17+2)
			c.r.DrawPoint(pos2, v17, drawColorDarkPurple)
		}
	}
	if dr.HasEnchant(server.ENCHANT_PROTECT_FROM_FIRE) {
		c.DrawProtectEffectDefault(vp, dr.Pos(), dr, 0, 0, nox_color_red, nox_color_red_2589776, false)
	}
	if dr.HasEnchant(server.ENCHANT_PROTECT_FROM_POISON) {
		c.DrawProtectEffectDefault(vp, dr.Pos(), dr, 85, 1, nox_color_green, nox_color_green_2614268, false)
	}
	if dr.HasEnchant(server.ENCHANT_PROTECT_FROM_ELECTRICITY) {
		c.DrawProtectEffectDefault(vp, dr.Pos(), dr, 170, 2, nox_color_blue_2650684, nox_color_white_2523948, false)
	}
	if dr.HasEnchant(server.ENCHANT_SHIELD) {
		pos := vp.ToScreenPos(dr.Pos())
		v24 := -90 - dr.Z()
		pos.X -= 64
		pos.Y += v24
		if dr.Field_69 == 6 {
			v26 := 8 * uintptr(dr.Field_74_2)
			pos.X += int(memmap.Int32(0x587000, 149504+v26))
			pos.Y += int(memmap.Int32(0x587000, 149508+v26))
		}
		c.r.Data().SetAlphaEnabled(true)
		c.r.Data().SetAlpha(0x80)
		c.Nox_video_drawAnimatedImageOrCursorAt(legacy.AsImageRefP(*memmap.PtrPtr(0x5D4594, 1096460)), pos)
		c.r.Data().SetAlphaEnabled(false)
	}
	if dr.HasEnchant(server.ENCHANT_REFLECTIVE_SHIELD) {
		switch dr.Field_74_2 {
		default:
			legacy.Nox_xxx_drawShield_499810(vp, dr)
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
	if p := r.Data(); p.Clip() {
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

func (r *NoxRender) DrawCircleSegment(cx, cy, rad, ang int, cl color.Color) {
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

func nox_client_isConnected_43C700() int {
	return bool2int(nox_client_isConnected())
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
		legacy.Nox_xxx_guiServerOptionsHide_4597E0(0)
		legacy.Nox_xxx_cliSetSettingsAcquired_4169D0(0)
	}
}
