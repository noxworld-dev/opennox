package main

/*
#include "client__video__draw_common.h"
#include "proto.h"
extern unsigned int dword_5d4594_805860;
extern unsigned int nox_game_loop_xxx_805872;
extern int nox_video_dxFullScreen;
extern int nox_enable_threads;
extern int nox_video_dxFullScreen;
extern int nox_video_dxUnlockSurface;
extern unsigned int nox_video_16bit;
extern int nox_win_width_game;
extern int nox_win_height_game;
extern int nox_win_depth_game;
int nox_video_initFloorBuffer_430BA0();
*/
import "C"
import (
	"errors"
	"log"

	"nox/common/memmap"
	"nox/common/types"
)

const (
	noxDefaultWidth  = C.NOX_DEFAULT_WIDTH
	noxDefaultHeight = C.NOX_DEFAULT_HEIGHT
)

var (
	noxBackBufCopyFunc func()
	noxVideoModeMenu   = renderMode{
		Width:  noxDefaultWidth,
		Height: noxDefaultHeight,
		Depth:  16,
	}
)

type renderMode struct {
	Width  int
	Height int
	Depth  int
}

//export sub_48A290_call_present
func sub_48A290_call_present() {
	callPresent()
}

//export nox_video_getFullScreen
func nox_video_getFullScreen() C.int {
	return C.int(noxFullScreen)
}

//export nox_video_setFullScreen
func nox_video_setFullScreen(v C.int) {
	noxFullScreen = int(v)
}

//export nox_video_sync_depths
func nox_video_sync_depths() C.bool {
	if int(C.nox_win_depth_game) == noxVideoModeMenu.Depth {
		return true
	}
	noxVideoModeMenu.Depth = int(C.nox_win_depth_game)
	return false
}

//export nox_common_parsecfg_videomode_apply
func nox_common_parsecfg_videomode_apply(w, h, d C.int) {
	d = 16 // 8 bit not supported
	if !getEngineFlag(NOX_ENGINE_FLAG_ENABLE_WINDOWED_MODE) {
		C.nox_win_width_game = w
		C.nox_win_height_game = h
		C.nox_win_depth_game = d
		noxVideoModeMenu.Depth = int(d)

		// FIXME: this will cause the game to change its window size to whatever set in nox.cfg right at the
		// start! this is different from original game where window is only resized after joining the game
		changeWindowedOrFullscreen()
	}
}

func nox_video_setBackBufferCopyFunc_4AD100() error {
	if C.nox_video_renderTargetFlags&0x40 != 0 {
		noxBackBufCopyFunc = nox_video_copyBackBuffer2_4AD180
		return errors.New("nox_video_setBackBufferCopyFunc_4AD100: flag not implemented")
	} else {
		nox_video_setBackBufferCopyFunc2_4AD150()
	}
	*memmap.PtrUint32(0x5D4594, 3798652) = 0
	return nil
}

//export nox_video_setBackBufferCopyFunc2_4AD150
func nox_video_setBackBufferCopyFunc2_4AD150() {
	if C.nox_video_renderTargetFlags&0x40 != 0 {
		noxBackBufCopyFunc = nox_video_copyBackBuffer_4AD2A0
	} else {
		noxBackBufCopyFunc = nox_video_copyBackBuffer3_4AD1E0
	}
}

//export nox_video_callCopyBackBuffer_4AD170
func nox_video_callCopyBackBuffer_4AD170() {
	noxBackBufCopyFunc()
}

func nox_xxx_utilRect_49F930(out, a2, a3 *types.Rect) bool {
	left := a3.Left
	if a2.Left >= a3.Left {
		left = a2.Left
	}
	right := a3.Right
	if a2.Right <= right {
		right = a2.Right
	}
	if left >= right {
		return false
	}
	top := a3.Top
	if a2.Top >= top {
		top = a2.Top
	}
	bottom := a3.Bottom
	if a2.Bottom <= bottom {
		bottom = a2.Bottom
	}
	if top >= bottom {
		return false
	}
	out.Left = left
	out.Top = top
	out.Right = right
	out.Bottom = bottom
	return true
}

func videoInit(w, h, depth, flags int) error {
	C.dword_5d4594_823776 = 0
	C.ptr_5D4594_3799572 = &C.obj_5D4594_3799660
	if err := drawInitAll(w, h, depth, flags); err != nil {
		log.Println("videoInit:", err)
		return err
	}
	C.ptr_5D4594_3799572 = &C.obj_5D4594_3800716
	C.obj_5D4594_3800716 = C.obj_5D4594_3799660
	if C.nox_video_renderTargetFlags&0x200 != 0 {
		windowMinimize()
	}
	C.dword_5d4594_823776 = 1
	C.dword_5d4594_823772++
	return nil
}

func drawInitAll(w, h, depth, flags int) error {
	if res := C.nox_client_drawXxx_444AC0(C.int(w), C.int(h), C.int(depth), C.int(flags)); res == 0 {
		return errors.New("nox_client_drawXxx_444AC0 failed")
	}
	if res := C.sub_47D200(); res == 0 {
		return errors.New("sub_47D200 failed")
	}
	if res := C.sub_486090(); res == 0 {
		return errors.New("sub_47D200 failed")
	}
	if res := C.nox_video_assignCircleDrawFuncs_4B0B30(); res == 0 {
		return errors.New("nox_video_assignCircleDrawFuncs_4B0B30 failed")
	}
	if res := C.sub_4408E0(); res == 0 {
		return errors.New("sub_4408E0 failed")
	}
	if res := C.sub_49F610(); res == 0 {
		return errors.New("sub_49F610 failed")
	}
	if res := C.sub_4338D0(); res == 0 {
		return errors.New("sub_4338D0 failed")
	}
	if err := nox_video_setBackBufferCopyFunc_4AD100(); err != nil {
		return err
	}
	if res := C.nox_video_initCursorDrawVars_48B1F0(); res == 0 {
		return errors.New("subnox_video_initCursorDrawVars_48B1F0_49F610 failed")
	}
	if res := C.sub_44D9A0(); res == 0 {
		return errors.New("sub_44D9A0 failed")
	}
	if res := C.sub_4B0650(); res == 0 {
		return errors.New("sub_4B0650 failed")
	}
	if res := C.nox_video_initLineDrawingFuncs_49E3F0(); res == 0 {
		return errors.New("nox_video_initLineDrawingFuncs_49E3F0 failed")
	}
	if res := C.sub_48C560(); res == 0 {
		return errors.New("sub_48C560 failed")
	}
	if res := C.sub_4B02D0(); res == 0 {
		return errors.New("sub_4B02D0 failed")
	}
	if res := C.sub_4AF8D0(); res == 0 {
		return errors.New("sub_4AF8D0 failed")
	}
	if res := C.sub_4AEE80(); res == 0 {
		return errors.New("sub_4AEE80 failed")
	}
	if res := C.sub_4AE520(); res == 0 {
		return errors.New("sub_4AE520 failed")
	}
	if res := C.nox_video_initRectDrawingFuncs_49CB50(); res == 0 {
		return errors.New("nox_video_initRectDrawingFuncs_49CB50 failed")
	}
	if res := C.nox_xxx_fontLoadMB_43F1C0(); res == 0 {
		return errors.New("nox_xxx_fontLoadMB_43F1C0 failed")
	}
	if res := C.sub_4AE400(); res == 0 {
		return errors.New("sub_4AE400 failed")
	}
	if res := C.sub_49F4A0(); res == 0 {
		return errors.New("sub_49F4A0 failed")
	}
	return nil
}

func nox_video_copyBackBuffer2_4AD180() {
	panic("not implemented")
}

func getBackBufferMode() renderMode {
	return renderMode{
		Width:  int(C.nox_backbuffer_width),
		Height: int(C.nox_backbuffer_height),
		Depth:  int(C.nox_backbuffer_depth),
	}
}

func gameUpdateVideoMode(inMenu bool) error {
	var mode renderMode
	if inMenu {
		if debugMainloop {
			log.Printf("gameUpdateVideoMode: menu (%s)", caller(1))
		}
		mode = noxVideoModeMenu
	} else {
		if debugMainloop {
			log.Printf("gameUpdateVideoMode: game (%s)", caller(1))
		}
		mode = renderMode{
			Width:  int(C.nox_win_width_game),
			Height: int(C.nox_win_height_game),
			Depth:  int(C.nox_win_depth_game),
		}
	}
	C.nox_video_resizewnd(C.int(mode.Width), C.int(mode.Height), C.int(mode.Depth))
	C.nox_game_loop_xxx_805872 = 0
	cur := getBackBufferMode()
	if mode == cur {
		return nil
	}
	C.nox_video_mouseThreadXxx_48BE50(1)
	if mode.Depth != cur.Depth {
		if C.nox_video_bagMaybeReload(C.int(C.nox_video_16bit)) == 0 {
			return errors.New("nox_video_bagMaybeReload failed")
		}
	}
	if err := recreateBuffersAndTarget(); err != nil {
		return err
	}
	C.nox_xxx_loadPal_4A96C0_video_read_palette(internCStr("default.pal"))
	C.sub_461520()
	C.nox_xxx_setMouseBounds_430A70(0, C.int(cur.Width-1), 0, C.int(cur.Height-1))
	C.nox_video_mouseThreadXxx_48BE50(0)
	return nil
}

func recreateBuffersAndTarget() error {
	C.nox_video_freeFloorBuffer_430EC0()
	if err := recreateRenderTarget(); err != nil {
		log.Println("recreateRenderTarget:", err)
		return err
	}
	log.Println("recreateRenderTarget: ok")
	if C.nox_video_initFloorBuffer_430BA0() == 0 {
		return errors.New("nox_video_initFloorBuffer_430BA0 failed")
	}
	return nil
}

func recreateRenderTarget() error {
	flags := uint(0)
	if C.nox_video_dxFullScreen != 0 {
		if C.nox_video_dxUnlockSurface != 0 {
			flags = 0x20
		}
	} else {
		flags = 0x10
	}
	if C.dword_5d4594_805860 != 0 {
		flags |= 0x18
	}
	if getEngineFlag(NOX_ENGINE_FLAG_26) && C.nox_video_dxFullScreen != 0 {
		flags &= 0xFFFFFFDF
	}
	if C.nox_enable_threads == 0 {
		flags |= 0x100
	}
	if memmap.Uint32(0x5D4594, 805864) != 0 {
		flags |= 0x200
	}
	C.nox_xxx_setSomeFunc_48A210(C.int(uintptr(C.sub_47FCE0))) // TODO: another callback
	v1 := C.nox_client_getCursorType_477620()
	C.nox_client_setCursorType_477610(0)
	v2 := C.sub_48B3E0(0)
	depth := 16
	if C.nox_video_16bit == 0 {
		depth = 8
	}
	if err := videoInit(int(C.nox_win_width), int(C.nox_win_height), depth, int(flags)); err != nil {
		v9 := strMan.GetStringInFile("result:ERROR", "C:\\NoxPost\\src\\Client\\Io\\Win95\\dxvideo.c")
		v4 := strMan.GetStringInFile("gfxDdraw.c:DXWarning", "C:\\NoxPost\\src\\Client\\Io\\Win95\\dxvideo.c")
		// TODO: show OS modal message
		_, _ = v4, v9
		return err
	}
	C.nox_xxx_cursorLoadAll_477710()
	C.nox_client_setCursorType_477610(v1)
	C.sub_48B3E0(v2)
	C.sub_440900()
	C.nox_xxx_setupSomeVideo_47FEF0()
	C.sub_49F6D0(1)
	C.sub_437290()
	C.nox_video_16bit = C.dword_5d4594_3801780
	*memmap.PtrUint32(0x5D4594, 3805488) = uint32(C.nox_backbuffer_pitch_3801808 * C.nox_backbuffer_height)
	*memmap.PtrUint32(0x5D4594, 3807124) = uint32(bool2int(C.dword_5d4594_3801780 == 1))
	C.sub_430B50(0, 0, noxDefaultWidth-1, noxDefaultHeight-1)
	inpHandler.Tick()
	return nil
}
