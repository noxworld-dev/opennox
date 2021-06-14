package main

/*
#include "client__video__draw_common.h"
#include "proto.h"
extern int g_fullscreen_cfg;
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
	"image"

	"nox/v1/common/memmap"
	"nox/v1/common/types"
)

var (
	noxBackBufCopyFunc func()
)

func videoGetWindowSize() types.Size {
	return types.Size{
		W: int(C.nox_win_width),
		H: int(C.nox_win_height),
	}
}

func videoSetWindowSize(sz types.Size) {
	C.nox_win_width = C.int(sz.W)
	C.nox_win_height = C.int(sz.H)
}

func getBackBufferMode() renderMode {
	return renderMode{
		Width:  int(C.nox_backbuffer_width),
		Height: int(C.nox_backbuffer_height),
		Depth:  int(C.nox_backbuffer_depth),
	}
}

func cfgUpdateFullScreen() {
	C.g_fullscreen_cfg = C.int(noxFullScreen)
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
	return C.bool(videoSyncMenuDepth())
}

//export sub_430C30_set_video_max
func sub_430C30_set_video_max(w, h C.int) {
	videoSetMaxSize(types.Size{W: int(w), H: int(h)})
}

//export nox_xxx_screenGetSize_430C50_get_video_max
func nox_xxx_screenGetSize_430C50_get_video_max(pw, ph *C.int) {
	sz := videoGetMaxSize()
	*pw = C.int(sz.W)
	*ph = C.int(sz.H)
}

func videoIs16Bit() bool {
	return C.nox_video_16bit != 0
}

func videoSet16Bit(v bool) {
	C.nox_video_16bit = C.uint(bool2int(v))
}

//export nox_video_resizewnd
func nox_video_resizewnd(w, h, d C.int) {
	videoResizeView(renderMode{
		Width:  int(w),
		Height: int(h),
		Depth:  int(d),
	})
}

func videoGetGameMode() renderMode {
	return renderMode{
		Width:  int(C.nox_win_width_game),
		Height: int(C.nox_win_height_game),
		Depth:  int(C.nox_win_depth_game),
	}
}

func videoSetGameMode(mode renderMode) {
	C.nox_win_width_game = C.int(mode.Width)
	C.nox_win_height_game = C.int(mode.Height)
	C.nox_win_depth_game = C.int(mode.Depth)
}

//export nox_common_parsecfg_videomode_apply
func nox_common_parsecfg_videomode_apply(w, h, d C.int) {
	videoApplyConfigVideoMode(renderMode{
		Width:  int(w),
		Height: int(h),
		Depth:  int(d),
	})
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

func videoInit(sz types.Size, depth, flags int) error {
	C.dword_5d4594_823776 = 0
	C.ptr_5D4594_3799572 = &C.obj_5D4594_3799660
	if err := drawInitAll(sz, depth, flags); err != nil {
		videoLog.Println("init:", err)
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

func drawInitAll(sz types.Size, depth, flags int) error {
	if res := C.nox_client_drawXxx_444AC0(C.int(sz.W), C.int(sz.H), C.int(depth), C.int(flags)); res == 0 {
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

func gameUpdateVideoMode(inMenu bool) error {
	var mode renderMode
	if inMenu {
		if debugMainloop {
			videoLog.Printf("gameUpdateVideoMode: menu (%s)", caller(1))
		}
		mode = videoGetMenuMode()
	} else {
		if debugMainloop {
			videoLog.Printf("gameUpdateVideoMode: game (%s)", caller(1))
		}
		mode = videoGetGameMode()
	}
	videoLog.Printf("mode switch: %+v (menu: %v)", mode, inMenu)
	videoResizeView(mode)
	C.nox_game_loop_xxx_805872 = 0
	cur := getBackBufferMode()
	if mode == cur {
		return nil
	}
	C.nox_video_mouseThreadXxx_48BE50(1)
	if mode.Depth != cur.Depth {
		if C.nox_video_bagMaybeReload(C.int(bool2int(videoIs16Bit()))) == 0 {
			return errors.New("nox_video_bagMaybeReload failed")
		}
	}
	if err := recreateBuffersAndTarget(); err != nil {
		return err
	}
	C.nox_xxx_loadPal_4A96C0_video_read_palette(internCStr("default.pal"))
	C.sub_461520()
	setMouseBounds(image.Rect(0, 0, mode.Width-1, mode.Height-1))
	C.nox_video_mouseThreadXxx_48BE50(0)
	return nil
}

func recreateBuffersAndTarget() error {
	C.nox_video_freeFloorBuffer_430EC0()
	if err := recreateRenderTarget(); err != nil {
		videoLog.Println("recreate render target:", err)
		return err
	}
	videoLog.Println("recreate render target: ok")
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
	if !videoIs16Bit() {
		depth = 8
	}
	if err := videoInit(videoGetWindowSize(), depth, int(flags)); err != nil {
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
	videoSet16Bit(C.dword_5d4594_3801780 != 0)
	*memmap.PtrUint32(0x5D4594, 3805488) = uint32(C.nox_backbuffer_pitch_3801808 * C.nox_backbuffer_height)
	*memmap.PtrUint32(0x5D4594, 3807124) = uint32(bool2int(C.dword_5d4594_3801780 == 1))
	C.sub_430B50(0, 0, noxDefaultWidth-1, noxDefaultHeight-1)
	inpHandler.Tick()
	return nil
}
