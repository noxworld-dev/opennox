package main

/*
#include "proto.h"
#include "client__system__client.h"
#include "client__gui__guiquit.h"
#include "client__gui__guiggovr.h"
#include "client__video__draw_common.h"
#include "client__draw__selectdw.h"
extern nox_draw_viewport_t nox_draw_viewport;
extern unsigned int dword_5d4594_811896;
extern unsigned int dword_5d4594_811904;
extern unsigned int nox_client_gui_flag_815132;
extern unsigned int dword_5d4594_1096432;
extern unsigned int dword_5d4594_1096516;
extern unsigned int dword_5d4594_3799452;
extern unsigned int dword_5d4594_3799468;
extern unsigned int dword_5d4594_3799484;
extern unsigned int dword_5d4594_3799476;
extern unsigned int dword_5d4594_3799508;
extern void* nox_draw_sprite_dstPtr_3799540;
extern unsigned int dword_5d4594_3799552;
extern unsigned char* nox_video_cur_pixdata_3799444;
extern int dword_5d4594_3799524;
extern unsigned int nox_client_gui_flag_1556112;
extern unsigned int nox_gameDisableMapDraw_5d4594_2650672;
extern nox_video_bag_section_t* nox_video_bag_sections_arr;
void  nox_client_xxxDraw16_4C7440(nox_video_bag_image_t* img, int x, int y);
void nox_client_drawXxx_4C7C80(int x, int y, int width, int4* a4);
void  nox_client_drawImg_bbb_4C7860(int a1, int a2, int a3);
void sub_4C8130();
void sub_4C8410();
void sub_4C86B0();
void sub_4C8850();
void sub_4C8D60();
void sub_4C8DF0();
void sub_4C8EC0();
void sub_4C9050();
void sub_4C91C0();
void sub_4C92F0();
void sub_4C94D0();
void sub_4C96A0();
void sub_4C97F0();
void sub_4C9970();
void sub_4C9B20();
void nox_xxx_clientDrawAll_436100_draw_A();
void nox_xxx_clientDrawAll_436100_draw_B();
void nox_xxx_drawAllMB_475810_draw_A(nox_draw_viewport_t* vp);
int nox_xxx_drawAllMB_475810_draw_B(nox_draw_viewport_t* vp);
void nox_xxx_drawAllMB_475810_draw_C(nox_draw_viewport_t* vp, int v36, int v7);
void nox_xxx_drawAllMB_475810_draw_D(nox_draw_viewport_t* vp);
void nox_xxx_drawAllMB_475810_draw_E(nox_draw_viewport_t* vp);
void nox_xxx_drawAllMB_475810_draw_F(nox_draw_viewport_t* vp);
*/
import "C"
import (
	"encoding/binary"
	"unsafe"

	"nox/v1/client/input"
	"nox/v1/common/alloc"
	noxcolor "nox/v1/common/color"
	noxflags "nox/v1/common/flags"
	"nox/v1/common/memmap"
	"nox/v1/common/types"
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

func nox_xxx_guiFontHeightMB_43F320(a1 int) int {
	return int(C.nox_xxx_guiFontHeightMB_43F320(C.int(a1)))
}

var noxrend = NewNoxRender()

type drawOpFunc func(dst, src []byte, op byte, val int) (outDst, outSrc []byte)

type NoxRender struct {
	p *C.nox_render_data_t

	colors struct {
		mode noxcolor.Mode
		R    [256]uint16
		G    [256]uint16
		B    [256]uint16
	}

	draw27 drawOpFunc
	draw4  drawOpFunc
	draw5  drawOpFunc
	draw6  drawOpFunc
}

func NewNoxRender() *NoxRender {
	r := &NoxRender{}
	r.SetColorMode(noxcolor.ModeRGBA5551)
	return r
}

func (r *NoxRender) SetData(p *C.nox_render_data_t) {
	r.p = p
}

func (r *NoxRender) Rect() types.Rect {
	return types.Rect{
		Left:   int(r.p.clip.left),
		Top:    int(r.p.clip.top),
		Right:  int(r.p.clip.right),
		Bottom: int(r.p.clip.bottom),
	}
}

func (r *NoxRender) IsAlphaEnabled() bool {
	return r.p.field_13 != 0
}

func (r *NoxRender) SelectColor(a1 uint32) { // nox_xxx_drawSelectColor_434350
	r.p.field_58 = C.uint(a1)
}

func (r *NoxRender) SetTextColor(a1 uint32) { // nox_xxx_drawSetTextColor_434390
	r.p.field_59 = C.uint(a1)
}

func (r *NoxRender) SetColor(a1 uint32) { // nox_xxx_drawSetColor_4343E0
	r.p.field_60 = C.uint(a1)
}

func (r *NoxRender) SetColor2(a1 uint32) { // nox_client_drawSetColor_434460
	r.p.field_61 = C.uint(a1)
}

func (r *NoxRender) DrawRectFilledOpaque(x, y, w, h int) { // nox_client_drawRectFilledOpaque_49CE30
	C.nox_client_drawRectFilledOpaque_49CE30(C.int(x), C.int(y), C.int(w), C.int(h))
}

func (r *NoxRender) DrawRectFilledAlpha(x, y, w, h int) { // nox_client_drawRectFilledAlpha_49CF10
	C.nox_client_drawRectFilledAlpha_49CF10(C.int(x), C.int(y), C.int(w), C.int(h))
}

func (r *NoxRender) DrawString(a1 int, a2 string, a3 int, a4 int) { // nox_xxx_drawString_43F6E0
	sp := CWString(a2)
	defer WStrFree(sp)
	C.nox_xxx_drawString_43F6E0(C.int(a1), sp, C.int(a3), C.int(a4))
}

func (r *NoxRender) DrawString2(a1 int, a2 string, a3, a4, a5, a6 int) { // nox_xxx_drawString_43FAF0
	sp := CWString(a2)
	defer WStrFree(sp)
	C.nox_xxx_drawString_43FAF0(C.int(a1), sp, C.int(a3), C.int(a4), C.int(a5), C.int(a6))
}

func (r *NoxRender) GetStringSize(a1 int, a2 string, a5 int) types.Size { // nox_xxx_drawGetStringSize_43F840
	sp := CWString(a2)
	defer WStrFree(sp)
	p := (*C.nox_point)(alloc.Malloc(unsafe.Sizeof(C.nox_point{})))
	defer alloc.Free(unsafe.Pointer(p))
	C.nox_xxx_drawGetStringSize_43F840(C.int(a1), sp, &p.x, &p.y, C.int(a5))
	return types.Size{W: int(p.x), H: int(p.y)}
}

func (r *NoxRender) DrawCircle(a1, a2, a3 int) {
	if r.IsAlphaEnabled() {
		C.nox_video_drawCircle16Alpha_4B2480(C.int(a1), C.int(a2), C.int(a3))
	} else {
		C.nox_video_drawCircle16Opaque_4B1380(C.int(a1), C.int(a2), C.int(a3))
	}
}

func (r *NoxRender) DrawCircleColored(a1, a2, a3 int, a4 uint32) {
	r.SetColor2(a4)
	r.DrawCircle(a1, a2, a3)
}

func nox_xxx_gLoadImg_42F970(name string) unsafe.Pointer {
	return unsafe.Pointer(C.nox_xxx_gLoadImg_42F970(internCStr(name)))
}

func nox_video_drawAnimatedImageOrCursorAt_4BE6D0(a1 uint32, a2, a3 int) {
	C.nox_video_drawAnimatedImageOrCursorAt_4BE6D0(C.int(a1), C.int(a2), C.int(a3))
}

func nox_xxx_client_435F80_draw(inp *input.Handler) bool {
	mpos := inp.GetMousePos()
	if C.nox_xxx_serverIsClosing_446180() != 0 {
		C.sub_446190()
	}
	if sub_437060(inp) == 0 && !noxflags.HasGame(8) {
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
	if !noxflags.HasGame(1) {
		C.sub_40B970()
		C.sub_40B790()
	}
	if noxflags.HasGame(1) {
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
	if C.nox_client_isConnected_43C700() != 0 {
		C.nox_xxx_cliToggleObsWindow_4357A0()
	}
	nox_xxx_clientDrawAll_436100_draw()
	C.sub_49BB40()
	C.sub_49BA70()
	if C.sub_409F40(4096) != 0 {
		C.nox_xxx_screenshot_46D830()
	}
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
		nox_ticks_xxx_416D40()
	}
	if !(memmap.Uint32(0x587000, 85724) == 0 || isTick || !noxflags.HasGame(1) || sub_416D70() ||
		C.nox_client_gui_flag_815132 != 0 || nox_xxx_checkGameFlagPause_413A50() || getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
		setEngineFlag(NOX_ENGINE_FLAG_PAUSE)
		return
	}
	resetEngineFlag(NOX_ENGINE_FLAG_PAUSE)
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
	if id := memmap.Uint32(0x85319C, 0); id != 0 {
		*memmap.PtrPtr(0x852978, 8) = unsafe.Pointer(C.nox_xxx_netSpriteByCodeDynamic_45A6F0(C.int(id)))
	}
	if getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) {
		C.nox_xxx_clientDrawAll_436100_draw_A()
	} else if memmap.Uint32(0x852978, 8) != 0 && C.nox_client_isConnected_43C700() != 0 {
		nox_xxx_drawAllMB_475810_draw(vp)
		C.nox_xxx_drawMinimapAndLines_4738E0()
	} else {
		noxrend.SelectColor(memmap.Uint32(0x85B3FC, 952))
		sub_440900()
	}
	if C.dword_5d4594_811896 != 0 {
		C.sub_4365C0()
	}
	if C.dword_5d4594_811904 != 0 {
		C.sub_436F50()
	}
	if nox_common_gameFlags_check_40A5C0(8) {
		v13 := platformTicks() - memmap.Uint64(0x5D4594, 811908)
		if v13 > 10000 && !nox_common_gameFlags_check_40A5C0(1) {
			nox_common_gameFlags_unset_40A540(8)
		}
	}
	if nox_common_gameFlags_check_40A5C0(8) {
		C.nox_xxx_clientDrawAll_436100_draw_B()
	}
	if memmap.Uint32(0x587000, 85744) != 0 {
		C.sub_430B50(0, 0, C.int(nox_win_width-1), C.int(nox_win_height-1))
		sub_440900()
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
	v36 := vp.field_4 / 23
	v7 := vp.field_5 / 23
	C.dword_5d4594_1096516 = 0
	C.nox_xxx_drawBlack_496150(vp.C())
	v8 := false
	if !nox_common_gameFlags_check_40A5C0(2048) && C.nox_xxx_testCD_413830() == 0 ||
		nox_common_gameFlags_check_40A5C0(2048) && C.nox_xxx_testCDAndSolo_413840() == 0 ||
		C.nox_xxx_spriteTestBuf_4356C0((*C.nox_drawable)(*memmap.PtrPtr(0x852978, 8)), 2) != 0 ||
		C.nox_gameDisableMapDraw_5d4594_2650672 != 0 {
		v8 = true
	}
	if C.nox_client_gui_flag_1556112 != 0 || v8 {
		noxrend.SelectColor(memmap.Uint32(0x85B3FC, 952))
		sub_440900()
		C.sub_437290()
		C.dword_5d4594_3799524 = 1
		return
	}
	if memmap.Uint32(0x5D4594, 1096520) != 0 {
		noxrend.SelectColor(memmap.Uint32(0x5D4594, 2523948))
		sub_440900()
		noxrend.SelectColor(memmap.Uint32(0x85B3FC, 952))
		*memmap.PtrUint32(0x5D4594, 1096520) = 0
		C.sub_437290()
		C.dword_5d4594_3799524 = 1
		return
	}
	v10 := C.nox_xxx_drawAllMB_475810_draw_B(vp.C()) != 0
	C.sub_4765F0(vp.C())
	C.sub_4754F0(vp.C())
	if v10 {
		C.nox_xxx_tileDrawMB_481C20(vp.C())
		C.sub_4C5500(vp.C())
	} else {
		sub_440900()
	}
	C.sub_475F10(vp.C())
	C.nox_xxx_drawAllMB_475810_draw_C(vp.C(), C.int(v36), C.int(v7))
	C.nox_xxx_drawAllMB_475810_draw_D(vp.C())
	C.sub_475FE0(vp.C())
	C.nox_video_drawCursorSelectCircle_4773C0(vp.C())
	C.nox_xxx_drawAllMB_475810_draw_E(vp.C())
	C.sub_4AFD40()
	C.sub_4C5060(vp.C())
	C.nox_xxx_drawAllMB_475810_draw_F(vp.C())
	C.sub_44D9F0(0)
	if getEngineFlag(NOX_ENGINE_FLAG_ENABLE_SHOW_AI) {
		C.sub_476270(vp.C())
	}
	C.sub_45AB40()
	C.sub_437290()
	*memmap.PtrUint32(0x973F18, 68) = 1
	C.sub_476680()
}

//export nox_video_drawCircleColored_4C3270
func nox_video_drawCircleColored_4C3270(a1, a2, a3, a4 C.int) {
	noxrend.DrawCircleColored(int(a1), int(a2), int(a3), uint32(a4))
}

//export nox_video_drawCircle_4B0B90
func nox_video_drawCircle_4B0B90(a1, a2, a3 C.int) {
	noxrend.DrawCircle(int(a1), int(a2), int(a3))
}

func (r *NoxRender) DrawImageAt(img *C.nox_video_bag_image_t, pos types.Point) {
	r.DrawImageAtPix(img, pos, nil)
}

type getPixdataFunc func(img *C.nox_video_bag_image_t) []byte

func (r *NoxRender) DrawImageAtPix(img *C.nox_video_bag_image_t, pos types.Point, pixels getPixdataFunc) {
	if C.dword_5d4594_3799452 != 0 {
		C.nox_xxx_wndDraw_49F7F0()
		C.sub_49F780(C.int(memmap.Int32(0x973F18, 52)), C.int(memmap.Int32(0x973F18, 12)))
		C.sub_49F6D0(1)
	}
	r.drawImage16(img, pos, pixels)
	if C.dword_5d4594_3799452 != 0 {
		C.sub_49F860()
		C.dword_5d4594_3799452 = 0
	}
	C.dword_5d4594_3799484 = 0
	*memmap.PtrUint32(0x973F18, 120) = 0
	if memmap.Uint32(0x973F18, 68) != 0 && img != nil {
		if memmap.Uint32(0x973F18, 92) != uint32(img.field_1_0) || memmap.Uint32(0x973F18, 84) != uint32(img.field_1_1) {
			C.dword_5d4594_3799524 = 1
		}
		img.field_1_0 = C.ushort(memmap.Uint32(0x973F18, 92))
		img.field_1_1 = C.ushort(memmap.Uint32(0x973F18, 84))
	}
}

//export nox_client_drawImageAt_47D2C0
func nox_client_drawImageAt_47D2C0(img *C.nox_video_bag_image_t, x, y C.int) {
	noxrend.DrawImageAt(img, types.Point{X: int(x), Y: int(y)})
}

func sub_47D200() {
	if C.dword_5d4594_3801780 == 0 {
		panic("TODO")
		//nox_client_drawAtFunc_3799500 = sub_4C5EB0
	}
	C.dword_5d4594_3799484 = 0
	*memmap.PtrUint32(0x973F18, 52) = 0
	*memmap.PtrUint32(0x973F18, 12) = 0
	C.dword_5d4594_3799476 = 0
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
	C.dword_5d4594_3799552 = 0
	C.dword_5d4594_3799508 = 0
	//nox_video_getImagePixdata_func = nox_video_getImagePixdata_42FB30
}

func (r *NoxRender) drawImage16(img *C.nox_video_bag_image_t, pos types.Point, pixels getPixdataFunc) { // nox_client_xxxDraw16_4C7440
	if img == nil {
		return
	}
	switch img.typ & 0x3F {
	case 2, 7:
		r.draw27 = pixCopyN
		r.nox_client_drawImg_bbb_4C7860(img, pos, pixels)
	case 3, 4, 5, 6:
		r.draw5 = drawOpC(func() { C.sub_4C96A0() })
		r.draw6 = func(dst, src []byte, op byte, val int) (_, _ []byte) { return dst, src }
		if C.ptr_5D4594_3799572.field_13 == 0 {
			if C.ptr_5D4594_3799572.field_14 != 0 {
				r.draw5 = drawOpC(func() { C.sub_4C9970() })
				r.draw27 = r.sub_4C86B0
				r.draw4 = drawOpC(func() { C.sub_4C91C0() })
			} else {
				r.draw27 = drawOpC(func() { C.sub_4C8D60() })
				if C.ptr_5D4594_3799572.field_17 == 0 {
					r.draw27 = pixCopyN
				}
				r.draw4 = drawOpC(func() { C.sub_4C8DF0() })
			}
		} else {
			r.draw5 = drawOpC(func() { C.sub_4C97F0() })
			if C.ptr_5D4594_3799572.field_14 != 0 {
				v3 := C.ptr_5D4594_3799572.field_259
				if v3 == 255 {
					if C.ptr_5D4594_3799572.field_16 == 0 {
						r.draw27 = r.sub_4C86B0
						r.draw4 = drawOpC(func() { C.sub_4C91C0() })
					} else {
						r.draw27 = pixCopyN
						r.draw4 = drawOpC(func() { C.sub_4C8DF0() })
					}
				} else if v3 == 128 {
					r.draw27 = r.pixBlend
					r.draw4 = drawOpC(func() { C.sub_4C94D0() })
				} else {
					r.draw27 = drawOpC(func() { C.sub_4C8850() })
					r.draw4 = drawOpC(func() { C.sub_4C92F0() })
				}
			} else {
				v4 := C.ptr_5D4594_3799572.field_259
				if v4 == 255 {
					r.draw27 = pixCopyN
					r.draw4 = drawOpC(func() { C.sub_4C8DF0() })
				} else if v4 == 128 {
					r.draw27 = drawOpC(func() { C.sub_4C8410() })
					r.draw4 = drawOpC(func() { C.sub_4C9050() })
				} else {
					r.draw27 = drawOpC(func() { C.sub_4C8130() })
					r.draw4 = drawOpC(func() { C.sub_4C8EC0() })
				}
			}
		}
		r.nox_client_drawImg_aaa_4C79F0(img, pos, pixels)
	case 8:
		r.draw27 = drawOpC(func() { C.sub_4C9B20() })
		r.nox_client_drawImg_aaa_4C79F0(img, pos, pixels)
	}
}

func pixCopyN(dst, src []byte, _ byte, n int) (_, _ []byte) { // sub_4C80E0
	sz := n * 2
	copy(dst[:sz], src[:sz])
	return dst[sz:], src[sz:]
}

func drawOpC(fnc func()) drawOpFunc {
	return func(dst, src []byte, op byte, val int) (_, _ []byte) {
		var pdst, psrc uintptr
		if len(dst) == 0 {
			C.nox_draw_sprite_dstPtr_3799540 = nil
		} else {
			C.nox_draw_sprite_dstPtr_3799540 = unsafe.Pointer(&dst[0])
			pdst = uintptr(unsafe.Pointer(&dst[0]))
		}
		if len(src) == 0 {
			C.nox_video_cur_pixdata_3799444 = nil
		} else {
			C.nox_video_cur_pixdata_3799444 = (*C.uchar)(unsafe.Pointer(&src[0]))
			psrc = uintptr(unsafe.Pointer(&src[0]))
		}

		*memmap.PtrUint32(0x973F18, 0) = uint32(op)
		*memmap.PtrInt32(0x973F18, 28) = int32(val)
		fnc()

		if p := uintptr(unsafe.Pointer(C.nox_draw_sprite_dstPtr_3799540)); p > pdst {
			dst = dst[p-pdst:]
		}
		if p := uintptr(unsafe.Pointer(C.nox_video_cur_pixdata_3799444)); p > psrc {
			src = src[p-psrc:]
		}
		return dst, src
	}
}

func nox_bag_section(i int) *C.nox_video_bag_section_t {
	return (*C.nox_video_bag_section_t)(unsafe.Pointer(
		uintptr(unsafe.Pointer(C.nox_video_bag_sections_arr)) +
			uintptr(i)*unsafe.Sizeof(C.nox_video_bag_section_t{})))
}

//export nox_video_getImagePixdata_func
func nox_video_getImagePixdata_func(img *C.nox_video_bag_image_t) unsafe.Pointer {
	data := nox_video_getImagePixdata(img)
	if len(data) == 0 {
		return nil
	}
	return unsafe.Pointer(&data[0])
}

func nox_video_getImagePixdata(img *C.nox_video_bag_image_t) []byte {
	if img == nil {
		return nil
	}
	if data := nox_video_getImagePixdata_new(img); len(data) != 0 {
		// TODO: remove interning when we get rid of C renderer
		data = asByteSlice(internCBytes(data), len(data))
		return data
	}
	// FIXME
	sz := 999999
	if img.typ&0x80 == 0 && img.typ&0x3F != 7 {
		if ent := nox_bag_section(int(img.sect_ind)); ent.size > 0 {
			// TODO: this is still incorrect (size of the section vs size of the image)
			sz = int(ent.size)
		}
	}
	ptr := C.nox_video_getImagePixdata_42FB30(img)
	return asByteSlice(ptr, sz)
}

func skipPixdata(pix []byte, width int, skip int) []byte {
	for i := 0; i < skip; i++ {
		val := 0
		for j := 0; j < width; j += val {
			op := pix[0]
			val = int(pix[1])
			pix = pix[2:]
			switch op & 0xF {
			case 2, 5, 6, 7:
				pix = pix[2*val:]
				break
			case 4:
				pix = pix[val:]
			}
		}
	}
	return pix
}

func (r *NoxRender) nox_client_drawImg_aaa_4C79F0(img *C.nox_video_bag_image_t, pos types.Point, pixels getPixdataFunc) { // nox_client_drawImg_aaa_4C79F0
	if pixels == nil {
		pixels = nox_video_getImagePixdata
	}
	src := pixels(img)
	if len(src) == 0 {
		return
	}

	width := binary.LittleEndian.Uint32(src[0:])
	height := binary.LittleEndian.Uint32(src[4:])
	src = src[8:]

	offX := int32(binary.LittleEndian.Uint32(src[0:]))
	offY := int32(binary.LittleEndian.Uint32(src[4:]))
	src = src[8:]
	pos.X += int(offX)
	pos.Y += int(offY)

	src = src[1:] // unused

	if C.dword_5d4594_3799484 != 0 {
		height -= uint32(C.dword_5d4594_3799484)
		if height <= 0 {
			return
		}
		C.dword_5d4594_3799476 = C.uint(int(height) + pos.Y)
	}
	*memmap.PtrInt32(0x973F18, 92) = int32(pos.X)
	*memmap.PtrInt32(0x973F18, 84) = int32(pos.Y)
	*memmap.PtrUint32(0x973F18, 88) = width
	*memmap.PtrUint32(0x973F18, 76) = height
	if C.ptr_5D4594_3799572.flag_0 != 0 {
		rc := types.Rect{Left: pos.X, Top: pos.Y, Right: pos.X + int(width), Bottom: pos.Y + int(height)}
		a1a, ok := nox_xxx_utilRect_49F930(rc, r.Rect())
		if !ok {
			return
		}
		if rc != a1a {
			r.nox_client_drawXxx_4C7C80(src, pos, int(width), a1a)
			return
		}
	}
	C.dword_5d4594_3799508 ^= C.uint(pos.Y & 1)
	pitch := 2 * nox_pixbuffer_size.W
	for i := 0; i < int(height); i++ {
		dst := nox_pixbuffer_main[pitch*(pos.Y+i)+2*pos.X:]
		if C.dword_5d4594_3799552 != 0 {
			C.dword_5d4594_3799508 ^= 1
			if C.dword_5d4594_3799508 != 0 {
				if i != 0 {
					copy(dst[:2*width], nox_pixbuffer_main[pitch*(pos.Y+i-1)+2*pos.X:])
				}
				src = skipPixdata(src, int(width), 1)
				continue
			}
		}
		var val int
		for j := 0; j < int(width); j += val {
			op := src[0]
			val = int(src[1])
			src = src[2:]

			if op&0xF == 1 {
				dst = dst[2*val:]
				continue
			}
			switch op & 0xF {
			case 2, 7:
				dst, src = r.draw27(dst, src, op, val)
			case 4:
				dst, src = r.draw4(dst, src, op, val)
			case 5:
				dst, src = r.draw5(dst, src, op, val)
			case 6:
				dst, src = r.draw6(dst, src, op, val)
			default:
				panic(op)
			}
		}
	}
}

func (r *NoxRender) nox_client_drawXxx_4C7C80(pix []byte, pos types.Point, width int, clip types.Rect) { // nox_client_drawXxx_4C7C80
	left := clip.Left
	right := clip.Right
	dy := clip.Top - pos.Y
	height := clip.Bottom - clip.Top
	if C.dword_5d4594_3799484 != 0 {
		height -= int(C.dword_5d4594_3799484)
		if height <= 0 {
			return
		}
		C.dword_5d4594_3799476 = C.uint(height + pos.Y)
	}
	if height == 0 {
		return
	}
	ys := pos.Y
	if dy != 0 {
		ys += dy
		pix = skipPixdata(pix, width, dy)
	}
	C.dword_5d4594_3799508 ^= C.uint(ys & 1)
	pitch := 2 * nox_pixbuffer_size.W
	for i := 0; i < height; i++ {
		yi := ys + i
		if C.dword_5d4594_3799552 != 0 {
			C.dword_5d4594_3799508 ^= 1
			if C.dword_5d4594_3799508 != 0 {
				if i != 0 {
					src := nox_pixbuffer_main[pitch*(yi-1)+2*left:]
					dst := nox_pixbuffer_main[pitch*(yi+0)+2*left:]
					w := right - left
					if w > width {
						w = width
					}
					copy(dst[:2*w], src[:2*w])
				}
				pix = skipPixdata(pix, width, 1)
				continue
			}
		}
		if width <= 0 {
			continue
		}
		row := nox_pixbuffer_main[pitch*yi : pitch*(yi+1)]
		var n int
		for j := 0; j < width; j += n {
			op := pix[0]
			n = int(pix[1]) // TODO: custom bag images fail here
			pix = pix[2:]

			if op&0xF == 1 {
				continue
			}

			var (
				fnc  drawOpFunc
				pmul int
			)
			switch op & 0xF {
			case 2, 7:
				fnc = r.draw27
				pmul = 2
			case 4:
				fnc = r.draw4
				pmul = 1
			case 5:
				fnc = r.draw5
				pmul = 2
			case 6:
				fnc = r.draw6
				pmul = 2
			default:
				panic(op)
			}
			xs := pos.X + j
			xe := xs + n
			xw := n
			if xe <= 0 || xs >= right {
				pix = pix[pmul*n:]
				continue
			}

			pix2 := pix
			if xs < left {
				d := left - xs
				xw -= d
				xs = left
				pix2 = pix2[pmul*d:]
			}
			row2 := row[2*xs:]
			if xe > right {
				d := xe - right
				xw -= d
			}
			_, _ = fnc(row2, pix2, op, xw)
			pix = pix[pmul*n:]
		}
	}
}

//export nox_video_drawImageAt2_4B0820
func nox_video_drawImageAt2_4B0820(a1 unsafe.Pointer, x, y C.int) {
	var v C.nox_video_bag_image_t
	v.typ = 8
	ptr := *(*unsafe.Pointer)(unsafe.Pointer(uintptr(a1) + 64))
	pix := asByteSlice(ptr, 999999) // FIXME
	noxrend.DrawImageAtPix(&v, types.Point{X: int(x), Y: int(y)}, func(img *C.nox_video_bag_image_t) []byte {
		if img != &v {
			panic("unexpected argument")
		}
		return pix
	})
}

func (r *NoxRender) nox_client_drawImg_bbb_4C7860(img *C.nox_video_bag_image_t, pos types.Point, pixels getPixdataFunc) {
	if pixels == nil {
		pixels = nox_video_getImagePixdata
	}
	data := pixels(img)
	if len(data) == 0 {
		return
	}
	width := binary.LittleEndian.Uint32(data[0:])
	height := binary.LittleEndian.Uint32(data[4:])
	data = data[8:]

	offX := int32(binary.LittleEndian.Uint32(data[0:]))
	offY := int32(binary.LittleEndian.Uint32(data[4:]))
	data = data[8:]
	pos.X += int(offX)
	pos.Y += int(offY)

	data = data[1:] // unused

	if C.dword_5d4594_3799484 != 0 {
		height -= uint32(C.dword_5d4594_3799484)
		if height <= 0 {
			return
		}
		C.dword_5d4594_3799476 = C.uint(pos.Y + int(height))
	}

	wsz := int(width)
	if r.p.flag_0 != 0 {
		rc := types.Rect{
			Left:   pos.X,
			Top:    pos.Y,
			Right:  pos.X + int(width),
			Bottom: pos.Y + int(height),
		}
		a1a, ok := nox_xxx_utilRect_49F930(rc, r.Rect())
		if !ok {
			return
		}
		v11 := a1a.Left - rc.Left
		v12 := a1a.Top - rc.Top
		wsz = a1a.Right - a1a.Left
		height = uint32(a1a.Bottom - a1a.Top)
		if a1a.Left != rc.Left || v12 != 0 {
			pos.X += v11
			data = data[int(width)*v12+2*v11:]
			pos.Y += v12
		}
	}
	xoff := 2 * pos.X
	ipitch := 2 * int(width)
	pitch := 2 * nox_pixbuffer_size.W
	for i := 0; i < int(height); i++ {
		dst := nox_pixbuffer_main[pitch*(pos.Y+1)+xoff:]
		src := data[ipitch*i:]
		copy(dst[:wsz*2], src[:wsz*2])
	}
}

func (r *NoxRender) pixBlend(dst, src []byte, _ byte, sz int) (_, _ []byte) { // sub_4C8A30
	par := asU32Slice(unsafe.Pointer(&C.byte_5D4594_3804364[0]), 40)

	rshift := par[5]
	gshift := par[4]
	bshift := par[3]

	rmask := uint16(par[2])
	gmask := uint16(par[1])
	bmask := uint16(par[0])

	rmul := uint16(byte(C.ptr_5D4594_3799572.field_26))
	gmul := uint16(byte(C.ptr_5D4594_3799572.field_25))
	bmul := uint16(byte(C.ptr_5D4594_3799572.field_24))

	for i := 0; i < sz; i++ {
		c1 := binary.LittleEndian.Uint16(dst) // old color
		c2 := binary.LittleEndian.Uint16(src) // color to draw

		rc := byte((rmul * ((rmask & c2) << rshift)) >> 8)
		gc := byte((gmul * ((gmask & c2) >> gshift)) >> 8)
		bc := byte((bmul * ((bmask & c2) >> bshift)) >> 8)

		c3 := r.colors.R[byte(int16(bc)+(int16((bmask&c1)>>bshift)-int16(bc))/2)] |
			r.colors.G[byte(int16(gc)+(int16((gmask&c1)>>gshift)-int16(gc))/2)] |
			r.colors.B[byte(int16(rc)+(int16((rmask&c1)<<rshift)-int16(rc))/2)]

		binary.LittleEndian.PutUint16(dst, c3)
		dst = dst[2:]
		src = src[2:]
	}
	return dst, src
}

func (r *NoxRender) sub_4C86B0(dst, src []byte, _ byte, sz int) (_, _ []byte) { // sub_4C86B0
	par := asU32Slice(unsafe.Pointer(&C.byte_5D4594_3804364[0]), 40)

	rshift := par[5]
	gshift := par[4]
	bshift := par[3]

	rmask := uint16(par[2])
	gmask := uint16(par[1])
	bmask := uint16(par[0])

	rmul := uint32(C.obj_5D4594_3800716.field_26)
	gmul := uint32(C.obj_5D4594_3800716.field_25)
	bmul := uint32(C.obj_5D4594_3800716.field_24)

	for i := 0; i < sz; i++ {
		v2 := binary.LittleEndian.Uint16(src[2*i:])
		cr := r.colors.R[byte((bmul*(uint32(bmask&v2)>>bshift))>>8)]
		cg := r.colors.G[byte((gmul*(uint32(gmask&v2)>>gshift))>>8)]
		cb := r.colors.B[byte((rmul*(uint32(rmask&v2)<<rshift))>>8)]
		c := cr | cg | cb
		binary.LittleEndian.PutUint16(dst[2*i:], c)
	}
	return dst[2*sz:], src[2*sz:]
}

//export nox_draw_initColorTables_434CC0
func nox_draw_initColorTables_434CC0() C.int {
	mode := noxcolor.GetMode()
	if C.dword_5d4594_3801780 == 0 {
		mode = noxcolor.ModeRGBA5551
	}
	noxrend.SetColorMode(mode)
	arrR := alloc.Uints16(257)[:256]
	arrG := alloc.Uints16(257)[:256]
	arrB := alloc.Uints16(257)[:256]
	copy(arrR, noxrend.colors.R[:])
	copy(arrG, noxrend.colors.G[:])
	copy(arrB, noxrend.colors.B[:])
	C.nox_draw_colors_r_3804672 = (*C.uchar)(unsafe.Pointer(&arrR[0]))
	C.nox_draw_colors_g_3804656 = (*C.uchar)(unsafe.Pointer(&arrG[0]))
	C.nox_draw_colors_b_3804664 = (*C.uchar)(unsafe.Pointer(&arrB[0]))
	return 1
}

//export sub_433C20_freeColorTables
func sub_433C20_freeColorTables() {
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
