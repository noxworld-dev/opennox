package main

/*
#include "proto.h"
#include "client__system__client.h"
#include "client__gui__guiquit.h"
#include "client__gui__guiggovr.h"
#include "client__video__draw_common.h"
extern nox_draw_viewport_t nox_draw_viewport;
extern unsigned int dword_5d4594_811896;
extern unsigned int dword_5d4594_811904;
extern unsigned int nox_client_gui_flag_815132;
void nox_xxx_clientDrawAll_436100_draw_A();
void nox_xxx_clientDrawAll_436100_draw_B();
*/
import "C"
import (
	"unsafe"

	"nox/v1/client/input"
	"nox/v1/common/alloc"
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

func nox_xxx_drawSelectColor_434350(a1 uint32) {
	C.ptr_5D4594_3799572.data[58] = C.uint(a1)
}

func nox_xxx_drawSetTextColor_434390(a1 uint32) {
	C.ptr_5D4594_3799572.data[59] = C.uint(a1)
}

func nox_xxx_drawSetColor_4343E0(a1 uint32) {
	C.ptr_5D4594_3799572.data[60] = C.uint(a1)
}

func nox_client_drawSetColor_434460(a1 uint32) {
	C.ptr_5D4594_3799572.data[61] = C.uint(a1)
}

func nox_client_drawRectFilledOpaque_49CE30(x, y, w, h int) {
	C.nox_client_drawRectFilledOpaque_49CE30(C.int(x), C.int(y), C.int(w), C.int(h))
}

func nox_client_drawRectFilledAlpha_49CF10(x, y, w, h int) {
	C.nox_client_drawRectFilledAlpha_49CF10(C.int(x), C.int(y), C.int(w), C.int(h))
}

func nox_xxx_drawString_43F6E0(a1 int, a2 string, a3 int, a4 int) {
	sp := CWString(a2)
	defer WStrFree(sp)
	C.nox_xxx_drawString_43F6E0(C.int(a1), sp, C.int(a3), C.int(a4))
}

func nox_xxx_drawString_43FAF0(a1 int, a2 string, a3, a4, a5, a6 int) {
	sp := CWString(a2)
	defer WStrFree(sp)
	C.nox_xxx_drawString_43FAF0(C.int(a1), sp, C.int(a3), C.int(a4), C.int(a5), C.int(a6))
}

func nox_xxx_drawGetStringSize_43F840(a1 int, a2 string, a5 int) types.Size {
	sp := CWString(a2)
	defer WStrFree(sp)
	p := (*C.nox_point)(alloc.Malloc(unsafe.Sizeof(C.nox_point{})))
	defer alloc.Free(unsafe.Pointer(p))
	C.nox_xxx_drawGetStringSize_43F840(C.int(a1), sp, &p.x, &p.y, C.int(a5))
	return types.Size{W: int(p.x), H: int(p.y)}
}

func nox_xxx_gLoadImg_42F970(name string) unsafe.Pointer {
	return unsafe.Pointer(C.nox_xxx_gLoadImg_42F970(internCStr(name)))
}

func nox_video_drawAnimatedImageOrCursorAt_4BE6D0(a1 uint32, a2, a3 int) {
	C.nox_video_drawAnimatedImageOrCursorAt_4BE6D0(C.int(a1), C.int(a2), C.int(a3))
}

func nox_client_drawImageAt_47D2C0(img *C.nox_video_bag_image_t, x, y int) {
	C.nox_client_drawImageAt_47D2C0(img, C.int(x), C.int(y))
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
	viewport := &C.nox_draw_viewport
	v6 := int(viewport.x1)
	v7 := int(viewport.y1)
	if memmap.Uint32(0x587000, 85744) != 0 {
		viewport.height = viewport.width * C.int(nox_win_height) / C.int(nox_win_width)
		v6 = (nox_win_width - int(viewport.width)) / 2
		v7 = (nox_win_height - int(viewport.height)) / 2
		viewport.x1 = C.int(v6)
		viewport.y1 = C.int(v7)
		viewport.x2 = C.int(v6) + viewport.width - 1
		viewport.y2 = C.int(v7) + viewport.height - 1
	}
	C.sub_430B50(C.int(v6), C.int(v7), viewport.x2, viewport.y2)
	if id := memmap.Uint32(0x85319C, 0); id != 0 {
		*memmap.PtrPtr(0x852978, 8) = unsafe.Pointer(C.nox_xxx_netSpriteByCodeDynamic_45A6F0(C.int(id)))
	}
	if getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) {
		C.nox_xxx_clientDrawAll_436100_draw_A()
	} else if memmap.Uint32(0x852978, 8) != 0 && C.nox_client_isConnected_43C700() != 0 {
		C.nox_xxx_drawAllMB_475810_draw(viewport)
		C.nox_xxx_drawMinimapAndLines_4738E0()
	} else {
		nox_xxx_drawSelectColor_434350(memmap.Uint32(0x85B3FC, 952))
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
