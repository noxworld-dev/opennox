package legacy

import (
	"image"
	"unsafe"

	noxcolor "github.com/noxworld-dev/opennox-lib/color"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	Nox_xxx_cliUpdateCameraPos_435600     func(x, y int)
	Sub_437260                            func()
	Get_nox_client_texturedFloors_154956  func() bool
	Sub_480860                            func(dst, src []uint16, w int, a4p, a5p []uint32)
	Nox_xxx_drawList1096512_Append_4754C0 func(p *server.Wall)
	Sub_473970                            func(a1 image.Point) image.Point
	Nox_client_isConnected                func() bool
)

type nox_draw_viewport_t = noxrender.Viewport

func asViewportP(p unsafe.Pointer) *noxrender.Viewport {
	return (*noxrender.Viewport)(p)
}

func asViewport(p *nox_draw_viewport_t) *noxrender.Viewport {
	return asViewportP(unsafe.Pointer(p))
}

// get_nox_client_texturedFloors_154956
func get_nox_client_texturedFloors_154956() bool {
	return Get_nox_client_texturedFloors_154956()
}

// sub_4C42A0
func sub_4C42A0(a1 *int2, a2 *int2, a3 *int32, a4 *int32) int32 {
	return GetClient().Sub4C42A0(AsPoint(unsafe.Pointer(a1)), AsPoint(unsafe.Pointer(a2)), a3, a4)
}

// sub_4C5630
func sub_4C5630(a1 int32, a2 int32, a3 int32) int32 {
	return int32(GetClient().Sub4C5630(int(a1), int(a2), int(a3)))
}

// nox_draw_getViewport_437250
func nox_draw_getViewport_437250() *nox_draw_viewport_t {
	return (*nox_draw_viewport_t)(GetClient().Viewport().C())
}

// sub_4355B0
func sub_4355B0(a1 int32) {
	GetClient().Viewport().Field12 = int(a1)
}

// nox_xxx_getSomeCoods_435670
func nox_xxx_getSomeCoods_435670(a1 *int2) {
	p := GetClient().Viewport().World.Max
	a1.field_0 = int32(p.X)
	a1.field_4 = int32(p.Y)
}

// nox_xxx_cliUpdateCameraPos_435600
func nox_xxx_cliUpdateCameraPos_435600(x, y int32) {
	Nox_xxx_cliUpdateCameraPos_435600(int(x), int(y))
}

// sub_437260
func sub_437260() {
	Sub_437260()
}

// nox_draw_splitColor_435280
func nox_draw_splitColor_435280(cl int16, pr, pg, pb *byte) {
	c := noxrender.SplitColor(noxcolor.RGBA5551(cl))
	*pr = byte(c.R)
	*pg = byte(c.G)
	*pb = byte(c.B)
}

// nox_draw_setMaterial_4340A0
func nox_draw_setMaterial_4340A0(ind, r, g, b int32) {
	GetClient().R2().Data().SetMaterialRGB(int(ind), int(r), int(g), int(b))
}

// nox_draw_setMaterial_4341D0
func nox_draw_setMaterial_4341D0(ind, cl int32) {
	GetClient().R2().Data().SetMaterial(int(ind), noxcolor.RGBA5551(cl))
}

// sub_434080
func sub_434080(a1 int32) {
	GetClient().R2().Data().SetField262(int(a1))
}

// nox_xxx_drawSetTextColor_434390
func nox_xxx_drawSetTextColor_434390(a1 int32) {
	GetClient().R2().Data().SetTextColor(noxcolor.RGBA5551(a1))
}

// nox_xxx_drawSetColor_4343E0
func nox_xxx_drawSetColor_4343E0(a1 int32) {
	GetClient().R2().Data().SetColor(noxcolor.RGBA5551(a1))
}

// nox_client_drawSetColor_434460
func nox_client_drawSetColor_434460(a1 int32) {
	GetClient().R2().Data().SetColor2(noxcolor.RGBA5551(a1))
}

// nox_client_drawEnableAlpha_434560
func nox_client_drawEnableAlpha_434560(a1 int32) {
	GetClient().R2().Data().SetAlphaEnabled(a1 != 0)
}

// sub_4345F0
func sub_4345F0(a1 int32) {
	GetClient().R2().Data().SetMultiply14(int(a1))
}

// nox_xxx_draw_434600
func nox_xxx_draw_434600(a1 int32) {
	GetClient().R2().Data().SetColorize17(int(a1))
}

// sub_434990
func sub_434990(r, g, b int32) {
	GetClient().R2().Data().SetLightColor(noxrender.RGB{
		R: int(r),
		G: int(g),
		B: int(b),
	})
}

// sub_4349C0
func sub_4349C0(a1 *uint32) {
	arr := unsafe.Slice(a1, 3)
	GetClient().R2().Data().SetLightColor(noxrender.RGB{
		R: int(arr[0]),
		G: int(arr[1]),
		B: int(arr[2]),
	})
}

// sub_47D370
func sub_47D370(a1 int32) {
	GetClient().R2().Set_dword_5d4594_3799484(int(a1))
}

// sub_47D400
func sub_47D400(a1 int32, a2 int8) {
	GetClient().R2().SetInterlacing(a1 != 0, int(a2))
}

// sub_49F7C0_def
func sub_49F7C0_def() {
	GetClient().R2().Sub_49F7C0_def_go()
}

// nox_client_drawSetAlpha_434580
func nox_client_drawSetAlpha_434580(a byte) {
	GetClient().R2().Data().SetAlpha(a)
}

// nox_draw_enableTextSmoothing_43F670
func nox_draw_enableTextSmoothing_43F670(v int32) {
	GetClient().R2().SetTextSmooting(v != 0)
}

// nox_client_drawResetPoints_49F5A0
func nox_client_drawResetPoints_49F5A0() {
	GetClient().R2().ClearPoints()
}

// nox_client_drawAddPoint_49F500
func nox_client_drawAddPoint_49F500(x, y int32) {
	GetClient().R2().AddPoint(image.Pt(int(x), int(y)))
}

// nox_xxx_rasterPointRel_49F570
func nox_xxx_rasterPointRel_49F570(x, y int32) {
	GetClient().R2().AddPointRel(image.Pt(int(x), int(y)))
}

// nox_client_drawLineFromPoints_49E4B0
func nox_client_drawLineFromPoints_49E4B0() int32 {
	r := GetClient().R2()
	return bool2int32(r.DrawLineFromPoints(r.Data().Color2()))
}

// sub_49E4F0
func sub_49E4F0(a1 int32) int32 {
	return bool2int32(GetClient().R2().DrawParticles49ED80(int(a1)))
}

// sub_480860
func sub_480860(a1, a2 *uint16, w int32, a4, a5 *int32) {
	dst := unsafe.Slice((*uint16)(unsafe.Pointer(a1)), w)
	src := unsafe.Slice((*uint16)(unsafe.Pointer(a2)), w)
	a4p := unsafe.Slice((*uint32)(unsafe.Pointer(a4)), 3)
	a5p := unsafe.Slice((*uint32)(unsafe.Pointer(a5)), 3)
	Sub_480860(dst, src, int(w), a4p, a5p)
}

// nox_draw_setColorMultAndIntensityRGB_433CD0
func nox_draw_setColorMultAndIntensityRGB_433CD0(r, g, b byte) int {
	return int(GetClient().R2().SetColorMultAndIntensityRGB(r, g, b))
}

// nox_draw_set54RGB32_434040
func nox_draw_set54RGB32_434040(cl int32) {
	c := noxrender.SplitColor(noxcolor.RGBA5551(cl))
	GetClient().R2().Data().SetColorInt54(noxrender.RGB{
		R: int(c.R),
		G: int(c.G),
		B: int(c.B),
	})
}

// nox_draw_setColorMultAndIntensity_433E40
func nox_draw_setColorMultAndIntensity_433E40(cl int32) int32 {
	c := noxcolor.RGBA5551(cl).ColorNRGBA()
	return int32(GetClient().R2().SetColorMultAndIntensityRGB(c.R, c.G, c.B))
}

// sub_437290
func sub_437290() {
	GetClient().R2().SetRectFullScreen()
}

// nox_client_drawRectFilledOpaque_49CE30
func nox_client_drawRectFilledOpaque_49CE30(a1, a2, a3, a4 int32) {
	r := GetClient().R2()
	r.DrawRectFilledOpaque(int(a1), int(a2), int(a3), int(a4), r.Data().Color2())
}

// nox_client_drawRectFilledAlpha_49CF10
func nox_client_drawRectFilledAlpha_49CF10(a1, a2, a3, a4 int32) {
	GetClient().R2().DrawRectFilledAlpha(int(a1), int(a2), int(a3), int(a4))
}

// nox_client_drawBorderLines_49CC70
func nox_client_drawBorderLines_49CC70(a1, a2, a3, a4 int32) {
	r := GetClient().R2()
	r.DrawBorder(int(a1), int(a2), int(a3), int(a4), r.Data().Color2())
}

// nox_client_drawPixel_49EFA0
func nox_client_drawPixel_49EFA0(a1, a2 int32) {
	r := GetClient().R2()
	r.DrawPixel(image.Pt(int(a1), int(a2)), r.Data().Color2())
}

// nox_client_drawPoint_4B0BC0
func nox_client_drawPoint_4B0BC0(a1, a2, a3 int32) {
	r := GetClient().R2()
	r.DrawPointRad(image.Pt(int(a1), int(a2)), int(a3), r.Data().Color2())
}

// nox_xxx_drawPointMB_499B70
func nox_xxx_drawPointMB_499B70(a1, a2, a3 int32) {
	r := GetClient().R2()
	r.DrawPoint(image.Pt(int(a1), int(a2)), int(a3), r.Data().Color2())
}

// nox_xxx_guiFontHeightMB_43F320
func nox_xxx_guiFontHeightMB_43F320(fnt unsafe.Pointer) int32 {
	r := GetClient().R2()
	return int32(r.FontHeight(r.GetFonts().AsFont(fnt)))
}

// nox_draw_setTabWidth_43FE20
func nox_draw_setTabWidth_43FE20(v int32) int32 {
	old := GetClient().R2().TabWidth()
	GetClient().R2().SetTabWidth(int(v))
	return int32(old)
}

// nox_xxx_drawGetStringSize_43F840
func nox_xxx_drawGetStringSize_43F840(font unsafe.Pointer, sp *wchar2_t, outW, outH *int32, maxW int32) int32 {
	r := GetClient().R2()
	sz := r.GetStringSizeWrapped(r.GetFonts().AsFont(font), GoWString(sp), int(maxW))
	if outW != nil {
		*outW = int32(sz.X)
	}
	if outH != nil {
		*outH = int32(sz.Y)
	}
	return bool2int32(sz != (image.Point{}))
}

// nox_xxx_bookGetStringSize_43FA80
func nox_xxx_bookGetStringSize_43FA80(font unsafe.Pointer, sp *wchar2_t, outW, outH *int32, maxW int32) int32 {
	r := GetClient().R2()
	sz := r.GetStringSizeWrappedStyle(r.GetFonts().AsFont(font), GoWString(sp), int(maxW))
	if outW != nil {
		*outW = int32(sz.X)
	}
	if outH != nil {
		*outH = int32(sz.Y)
	}
	return bool2int32(sz != (image.Point{}))
}

// nox_xxx_drawString_43F6E0
func nox_xxx_drawString_43F6E0(font unsafe.Pointer, sp *wchar2_t, x, y int32) int32 {
	r := GetClient().R2()
	return int32(r.DrawString(r.GetFonts().AsFont(font), GoWString(sp), image.Point{X: int(x), Y: int(y)}))
}

// nox_draw_drawStringHL_43F730
func nox_draw_drawStringHL_43F730(font unsafe.Pointer, sp *wchar2_t, x, y int32) int32 {
	r := GetClient().R2()
	return int32(r.DrawStringHL(r.GetFonts().AsFont(font), GoWString(sp), image.Point{X: int(x), Y: int(y)}))
}

// nox_xxx_drawStringWrap_43FAF0
func nox_xxx_drawStringWrap_43FAF0(font unsafe.Pointer, sp *wchar2_t, x, y, maxW, maxH int32) int32 {
	r := GetClient().R2()
	return int32(r.DrawStringWrapped(r.GetFonts().AsFont(font), GoWString(sp), image.Rect(int(x), int(y), int(x+maxW), int(y+maxH))))
}

// nox_xxx_drawStringWrapHL_43FD00
func nox_xxx_drawStringWrapHL_43FD00(font unsafe.Pointer, sp *wchar2_t, x, y, maxW, maxH int32) int32 {
	r := GetClient().R2()
	return int32(r.DrawStringWrappedHL(r.GetFonts().AsFont(font), GoWString(sp), image.Rect(int(x), int(y), int(x+maxW), int(y+maxH))))
}

// nox_xxx_bookDrawString_43FA80_43FD80
func nox_xxx_bookDrawString_43FA80_43FD80(font unsafe.Pointer, s *wchar2_t, x, y, maxW, maxH int32) int32 {
	r := GetClient().R2()
	return int32(r.DrawStringWrappedStyle(r.GetFonts().AsFont(font), GoWString(s), image.Rect(int(x), int(y), int(x+maxW), int(y+maxH))))
}

// nox_xxx_drawStringStyle_43F7B0
func nox_xxx_drawStringStyle_43F7B0(font unsafe.Pointer, sp *wchar2_t, x, y int32) int32 {
	r := GetClient().R2()
	return int32(r.DrawStringStyle(r.GetFonts().AsFont(font), GoWString(sp), image.Point{X: int(x), Y: int(y)}))
}

// nox_video_drawAnimatedImageOrCursorAt_4BE6D0
func nox_video_drawAnimatedImageOrCursorAt_4BE6D0(a1, a2, a3 int32) {
	GetClient().Nox_video_drawAnimatedImageOrCursorAt(AsImageRefP(unsafe.Pointer(uintptr(a1))), image.Point{X: int(a2), Y: int(a3)})
}

// sub_484C60
func sub_484C60(a1 float32) int32 {
	return int32(client.LightRadius(float32(a1)))
}

// sub_469920
func sub_469920(p *nox_point) *byte {
	dst := GetClient().Sub469920(AsPoint(unsafe.Pointer(p)))
	return (*byte)(unsafe.Pointer(&dst[0]))
}

// nox_xxx_drawList1096512_Append_4754C0
func nox_xxx_drawList1096512_Append_4754C0(p unsafe.Pointer) {
	Nox_xxx_drawList1096512_Append_4754C0(asWallP(p))
}

// nox_video_drawCircleColored_4C3270
func nox_video_drawCircleColored_4C3270(a1, a2, a3, a4 int32) {
	GetClient().R2().DrawCircle(int(a1), int(a2), int(a3), noxcolor.RGBA5551(a4))
}

// nox_video_drawCircle_4B0B90
func nox_video_drawCircle_4B0B90(a1, a2, a3 int32) {
	GetClient().R2().DrawCircle(int(a1), int(a2), int(a3), GetClient().R2().Data().Color2())
}

// nox_client_drawImageAt_47D2C0
func nox_client_drawImageAt_47D2C0(img *nox_video_bag_image_t, x, y int32) {
	GetClient().R2().DrawImageAt(asImage(img), image.Point{X: int(x), Y: int(y)})
}

// nox_draw_imageMeta_47D5C0
func nox_draw_imageMeta_47D5C0(img *nox_video_bag_image_t, px, py, pw, ph *uint32) int32 {
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
		*px += uint32(off.X)
	}
	if py != nil {
		*py += uint32(off.Y)
	}
	if pw != nil {
		*pw = uint32(sz.X)
	}
	if ph != nil {
		*ph = uint32(sz.Y)
	}
	return 1
}

// nox_video_getImagePixdata_42FB30
func nox_video_getImagePixdata_42FB30(img *nox_video_bag_image_t) unsafe.Pointer {
	data := asImage(img).Pixdata()
	if len(data) == 0 {
		return nil
	}
	return unsafe.Pointer(&data[0])
}

// sub_4AE6F0
func sub_4AE6F0(cx, cy, rad, ang, ccl int32) {
	GetClient().R2().DrawCircleSegment(int(cx), int(cy), int(rad), int(ang), noxcolor.RGBA5551(ccl))
}

// sub_473970
func sub_473970(a1, a2p *int2) {
	a2 := Sub_473970(image.Pt(int(a1.field_0), int(a1.field_4)))
	a2p.field_0 = int32(a2.X)
	a2p.field_4 = int32(a2.Y)
}

// nox_client_isConnected_43C700
func nox_client_isConnected_43C700() int32 {
	return bool2int32(Nox_client_isConnected())
}

func Sub_437180() {
	sub_48D990((*nox_draw_viewport_t)(GetClient().Viewport().C()))
}

func Sub_476AE0(vp *noxrender.Viewport, dr *client.Drawable) {
	sub_476AE0((*nox_draw_viewport_t)(vp.C()), (*client.Drawable)(dr.C()))
}

func Nox_xxx_drawShinySpot_4C4F40(vp *noxrender.Viewport, dr *client.Drawable) {
	nox_xxx_drawShinySpot_4C4F40((*nox_draw_viewport_t)(vp.C()), (*client.Drawable)(dr.C()))
}

func Sub_499F60(p int, pos image.Point, a4 int, a5, a6, a7, a8, a9 int, a10 int) {
	sub_499F60(int32(p), int32(pos.X), int32(pos.Y), int16(a4), int8(a5), int8(a6), int8(a7), int8(a8), int8(a9), int32(a10))
}

func Get_sub_480250() unsafe.Pointer {
	return ccall.FuncAddr(sub_480250)
}
func Get_sub_480220() unsafe.Pointer {
	return ccall.FuncAddr(sub_480220)
}
func Sub_435120(a1 unsafe.Pointer, a2 unsafe.Pointer) {
	sub_435120(a1, a2)
}
func Sub_435040() {
	sub_435040()
}
func Sub_435150(a1 unsafe.Pointer, a2 unsafe.Pointer) {
	sub_435150((*byte)(a1), (*byte)(a2))
}
func Nox_xxx_wndDraw_49F7F0() {
	nox_xxx_wndDraw_49F7F0()
}
func Sub_49F780(a1 int, a2 int) {
	sub_49F780(int32(a1), int32(a2))
}
func Sub_49F860() {
	sub_49F860()
}
func Nox_xxx_drawEnergyBolt_499710(a1 int, a2 int, a3 int, a4 int) {
	nox_xxx_drawEnergyBolt_499710(int32(a1), int32(a2), int16(a3), int32(a4))
}
func Nox_xxx_drawShield_499810(vp *noxrender.Viewport, dr *client.Drawable) {
	nox_xxx_drawShield_499810((*nox_draw_viewport_t)(vp.C()), (*client.Drawable)(dr.C()))
}
func Sub_474B40(dr *client.Drawable) int {
	return int(sub_474B40((*client.Drawable)(dr.C())))
}
func Sub_495BB0(dr *client.Drawable, vp *noxrender.Viewport) {
	sub_495BB0((*client.Drawable)(dr.C()), (*nox_draw_viewport_t)(vp.C()))
}
