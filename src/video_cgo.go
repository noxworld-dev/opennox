package main

/*
#include "client__video__draw_common.h"
#include "proto.h"
extern int g_fullscreen_cfg;
extern unsigned int dword_5d4594_805860;
extern int nox_video_dxFullScreen;
extern int nox_enable_threads;
extern int nox_video_dxFullScreen;
extern int nox_video_dxUnlockSurface;
extern unsigned int nox_video_16bit;
extern int nox_win_width_game;
extern int nox_win_height_game;
extern int nox_win_depth_game;
extern char* dword_5d4594_3798632;
extern unsigned int dword_5d4594_3798728;
extern int dword_5d4594_1097212;
extern int dword_5d4594_1097216;
extern unsigned int dword_5d4594_1193188;
extern unsigned int dword_5d4594_1305748;
extern unsigned int dword_5d4594_3798636;
extern unsigned int dword_5d4594_3798640;
extern char* dword_5d4594_3798644;
extern char* dword_5d4594_3798648;
extern unsigned int dword_5d4594_3799468;
extern unsigned int nox_xxx_useAudio_587000_80840;
extern int dword_5d4594_3799524;
extern int nox_client_mouseCursorType;
extern int nox_xxx_cursorTypePrev_587000_151528;
extern int nox_video_cutSize;
extern int nox_win_width;
extern int nox_win_height;
extern unsigned char** nox_pixbuffer_rows_3798776;
extern unsigned char* nox_pixbuffer_3798788;
int nox_video_initFloorBuffer_430BA0();
BOOL nox_xxx___cfltcvt_init_430CC0();
int sub_430D60();
*/
import "C"
import (
	"errors"
	"unsafe"

	"nox/v1/client/input"
	"nox/v1/client/render"
	"nox/v1/common/alloc"
	noxcolor "nox/v1/common/color"
	"nox/v1/common/memmap"
	"nox/v1/common/player"
	"nox/v1/common/types"
)

var (
	g_scaled                               int
	nox_win_width                          int
	nox_win_height                         int
	noxBackBufCopyFunc                     func()
	nox_video_cursorDrawIsThreaded         bool
	dword_6F7C10                           func(a1 unsafe.Pointer, a2, a3 uint32)
	nox_backbuffer_width32                 int
	nox_pixbuffer_main_rows                []unsafe.Pointer
	nox_pixbuffer_rows_3798776_arr         []unsafe.Pointer
	nox_pixbuffer_main                     []byte
	nox_pixbuffer_3798788_arr              []byte
	dword_5d4594_3798632_arr               []unsafe.Pointer
	dword_5d4594_3798644_arr               []byte
	dword_5d4594_3798648_arr               []byte
	dword_5d4594_1193704_arr               []unsafe.Pointer
	nox_client_spellDragnDrop_1097192      uint32
	nox_client_spellDragnDrop_type_1097196 int
	nox_client_itemDragnDrop_1097188       *Drawable
	dword_5d4594_1097204                   int
	dword_5d4594_1097208                   int
	nox_video_gammaValue                   int
	draw_gamma                             float32
)

func videoGetWindowSize() types.Size {
	return types.Size{
		W: nox_win_width,
		H: nox_win_height,
	}
}

func videoSetWindowSize(sz types.Size) {
	C.nox_win_width = C.int(sz.W)
	C.nox_win_height = C.int(sz.H)
	nox_win_width = sz.W
	nox_win_height = sz.H
}

func cfgUpdateFullScreen() {
	C.g_fullscreen_cfg = C.int(getWindowMode())
}

//export nox_video_getScaled
func nox_video_getScaled() C.int {
	return C.int(g_scaled)
}

//export nox_video_setScaled
func nox_video_setScaled(v C.int) {
	g_scaled = int(v)
	setScaled(v != 0)
}

//export nox_video_getGammaSetting_434B00
func nox_video_getGammaSetting_434B00() C.int {
	v := nox_video_gammaValue
	if v < 1 {
		nox_video_gammaValue = 1
	} else if v > 10 {
		nox_video_gammaValue = 10
	}
	return C.int(nox_video_gammaValue)
}

//export updateGamma
func updateGamma(value C.int) {
	var dv float32
	if value > 0 {
		dv = 0.1
	} else if value < 0 {
		dv = -0.1
	}
	setGamma(draw_gamma + dv)
}

//export nox_video_getGamma
func nox_video_getGamma() C.float {
	return C.float(draw_gamma)
}

//export nox_video_setGamma
func nox_video_setGamma(v C.float) {
	setGamma(float32(v))
}

func setGamma(v float32) {
	if v < 0.1 {
		v = 0.1
	} else if v > 3.0 {
		v = 3.0
	}
	if draw_gamma != v {
		videoLog.Printf("gamma2: %v", draw_gamma)
	}
	draw_gamma = v
	if noxSeat != nil {
		noxSeat.SetGamma(v)
	}
}

//export nox_video_setGammaSetting_434B30
func nox_video_setGammaSetting_434B30(a1 C.int) C.int {
	v := int(a1)
	if v < 1 {
		v = 1
	} else if v > 10 {
		v = 10
	}
	if nox_video_gammaValue != v {
		videoLog.Printf("gamma: %v", nox_video_gammaValue)
	}
	nox_video_gammaValue = v
	return C.int(v)
}

//export nox_getBackbufWidth
func nox_getBackbufWidth() C.int {
	return C.int(getBackbufWidth())
}

//export nox_getBackbufHeight
func nox_getBackbufHeight() C.int {
	return C.int(getBackbufHeight())
}

//export sub_48A290_call_present
func sub_48A290_call_present() {
}

//export nox_video_getFullScreen
func nox_video_getFullScreen() C.int {
	return C.int(getWindowMode())
}

//export nox_video_setFullScreen
func nox_video_setFullScreen(v C.int) {
	updateFullScreen(int(v))
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
	videoResizeView(render.Mode{
		Width:  int(w),
		Height: int(h),
		Depth:  int(d),
	})
}

func videoGetGameMode() render.Mode {
	return render.Mode{
		Width:  int(C.nox_win_width_game),
		Height: int(C.nox_win_height_game),
		Depth:  int(C.nox_win_depth_game),
	}
}

func videoSetGameMode(mode render.Mode) {
	C.nox_win_width_game = C.int(mode.Width)
	C.nox_win_height_game = C.int(mode.Height)
	C.nox_win_depth_game = C.int(mode.Depth)
	setScreenSize(mode.Size())
}

//export nox_common_parsecfg_videomode_apply
func nox_common_parsecfg_videomode_apply(w, h, d C.int) {
	videoApplyConfigVideoMode(render.Mode{
		Width:  int(w),
		Height: int(h),
		Depth:  int(d),
	})
}

func nox_video_setBackBufferCopyFunc_4AD100() error {
	if C.nox_video_renderTargetFlags&0x40 != 0 {
		return errors.New("nox_video_setBackBufferCopyFunc_4AD100: flag not implemented")
	} else {
		nox_video_setBackBufferCopyFunc2_4AD150()
	}
	*memmap.PtrUint32(0x973A20, 496) = 0
	return nil
}

//export nox_video_setBackBufferCopyFunc2_4AD150
func nox_video_setBackBufferCopyFunc2_4AD150() {
	if C.nox_video_renderTargetFlags&0x40 != 0 {
		panic("not implemented")
	} else {
		noxBackBufCopyFunc = copyPixBuffer
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
	C.dword_5d4594_823776 = 1
	C.dword_5d4594_823772++
	return nil
}

func videoInitStub() {
	C.ptr_5D4594_3799572 = &C.obj_5D4594_3800716
	C.dword_5d4594_823776 = 1
	C.nox_win_width = noxDefaultWidth
	C.nox_win_height = noxDefaultHeight
}

func drawInitAll(sz types.Size, depth, flags int) error {
	if err := nox_client_drawXxx_444AC0(sz.W, sz.H, depth, flags); err != nil {
		return err
	}
	if res := C.sub_47D200(); res == 0 {
		return errors.New("sub_47D200 failed")
	}
	if err := sub_486090(); err != nil {
		return err
	}
	if res := C.nox_video_assignCircleDrawFuncs_4B0B30(); res == 0 {
		return errors.New("nox_video_assignCircleDrawFuncs_4B0B30 failed")
	}
	sub_49F610()
	if res := C.sub_4338D0(); res == 0 {
		return errors.New("sub_4338D0 failed")
	}
	if err := nox_video_setBackBufferCopyFunc_4AD100(); err != nil {
		return err
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
	sub_4AE520()
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

func gameUpdateVideoMode(inMenu bool) error {
	return gameResetVideoMode(inMenu, false)
}

func recreateBuffersAndTarget() error {
	C.nox_video_freeFloorBuffer_430EC0()
	if err := recreateRenderTarget(); err != nil {
		videoLog.Println("recreate render target:", err)
		return err
	}
	videoLog.Println("recreate render target: ok")
	if err := nox_video_initFloorBuffer_430BA0(); err != nil {
		return err
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
	if getEngineFlag(NOX_ENGINE_FLAG_LOCK_VIDEO_RESOLUTION) && C.nox_video_dxFullScreen != 0 {
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
	nox_client_setCursorType_477610(0)
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
	nox_client_setCursorType_477610(int(v1))
	C.sub_48B3E0(v2)
	sub_440900()
	C.nox_xxx_setupSomeVideo_47FEF0()
	C.sub_49F6D0(1)
	C.sub_437290()
	videoSet16Bit(C.dword_5d4594_3801780 != 0)
	*memmap.PtrUint32(0x973F18, 6060) = uint32(2 * getBackbufWidth() * getBackbufHeight())
	*memmap.PtrUint32(0x973F18, 7696) = uint32(bool2int(C.dword_5d4594_3801780 == 1))
	C.sub_430B50(0, 0, noxDefaultWidth-1, noxDefaultHeight-1)
	return nil
}

//export nox_getBackbufferPitch
func nox_getBackbufferPitch() C.int {
	return C.int(2 * getBackbufWidth())
}

//export nox_video_getSurfaceData_48A720
func nox_video_getSurfaceData_48A720(s unsafe.Pointer, outPitch *C.int, outPixels *unsafe.Pointer) C.int {
	panic("TODO")
}

//export nox_xxx_makeFillerColor_48BDE0
func nox_xxx_makeFillerColor_48BDE0() C.bool {
	v0 := noxcolor.ExtendColor16(noxcolor.RGBColor(255, 0, 255))
	*memmap.PtrUint32(0x5D4594, 1193592) = v0
	return true
}

//export nox_client_drawGeneral_4B0340
func nox_client_drawGeneral_4B0340(a1 C.int) C.int {
	if err := drawGeneral_4B0340(int(a1)); err != nil {
		videoLog.Println(err)
		return 0
	}
	return 1
}

func drawGeneral_4B0340(a1 int) error {
	C.dword_5d4594_1311936 = 1
	*memmap.PtrUint32(0x5D4594, 1311932) = uint32(a1)
	// FIXME
	v1 := false
	if getEngineFlag(NOX_ENGINE_FLAG_ENABLE_WINDOWED_MODE) || v1 || C.nox_video_renderTargetFlags&0x10 != 0 {
		C.sub_4B05D0()
		return nil
	}
	C.sub_431290()
	C.sub_43DBD0()
	C.sub_44D8F0()
	for C.sub_43DC40() != 0 || C.sub_44D930() != 0 {
		sub_4312C0()
		//#ifdef __EMSCRIPTEN__
		//nox_platform_sleep(0x32u);
		//#endif
	}
	C.sub_43E8E0(0)
	v12 := C.sub_48B3E0(0)
	//inpHandler.UnacquireMouse()
	//sub_48A7F0()
	v2 := C.dword_5d4594_3801780
	var (
		v4      int
		v7, v8  int
		v9, v10 int
		v11     unsafe.Pointer
	)
	if v2 != 0 {
		v4 = a1
	} else {
		v11, v10, v9 = sub_48B590()
		v2 = C.dword_5d4594_3801780
		v4 = int(C.nox_video_renderTargetFlags)
		bsz := getBackbufSize()
		v8 = bsz.W
		v7 = bsz.H
		nox_video_stopCursorDrawThread_48B350()
		C.sub_433C20()
		nox_free_pixbuffers_486110()
		C.nox_video_renderTargetFlags = C.int(v4)
		if err := resetRenderer(types.Size{W: noxDefaultWidth, H: noxDefaultHeight}); err != nil {
			return err
		}
		if err := sub_486090(); err != nil {
			return err
		}
	}

	// FIXME: play movies
	//#if 0
	//#ifdef __linux__
	//;
	//if (nox_enable_audio) { // TODO: disable audio in movies instead
	//char* path = nox_fs_normalize(&byte_5D4594[1311940]);
	//PlayMovie(path);
	//free(path);
	//}
	//#else
	////PlayMovie(&byte_5D4594[1311940]);
	//#endif
	//#endif

	if v2 == 0 {
		nox_free_pixbuffers_486110()
		C.nox_video_renderTargetFlags = C.int(v4)
		if err := resetRenderer(types.Size{W: v8, H: v7}); err != nil {
			return err
		}
		if err := sub_486090(); err != nil {
			return err
		}
		if C.sub_4338D0() == 0 {
			return errors.New("sub_4338D0 failed")
		}
		sub_48B3F0(v11, C.int(v10), C.int(v9))
	}
	C.sub_43E910(0)
	C.sub_43DBE0()
	//inpHandler.AcquireMouse()
	C.sub_48B3E0(v12)
	C.sub_4B05D0()
	return nil
}

func nox_video_initFloorBuffer_430BA0() error {
	if C.dword_5d4594_3801780 == 1 {
		C.nox_xxx___cfltcvt_init_430CC0()
	} else {
		C.sub_430D60()
	}
	bsz := getBackbufSize()
	if C.nox_xxx_tileInitBuf_430DB0(C.int(bsz.W), C.int(bsz.H)) == 0 {
		return errors.New("VideoInit: error initializing floor buffer")
	}
	return nil
}

func nox_video_stopCursorDrawThread_48B350() {
	if dword_5d4594_1193704_arr != nil {
		alloc.FreePointers(dword_5d4594_1193704_arr)
		dword_5d4594_1193704_arr = nil
		C.dword_5d4594_1193704 = nil
	}
	C.dword_5d4594_1193624 = nil
}

func sub_4AEDF0() {
	height := getBackbufSize().H
	dword_5d4594_3798632_arr = alloc.Pointers(height)
	C.dword_5d4594_3798632 = (*C.char)(unsafe.Pointer(&dword_5d4594_3798632_arr[0]))

	dword_5d4594_3798644_arr = alloc.Bytes(uintptr(height) << 6)
	C.dword_5d4594_3798644 = (*C.char)(unsafe.Pointer(&dword_5d4594_3798644_arr[0]))
}

func sub_4AE540() {
	if dword_5d4594_3798632_arr != nil {
		alloc.FreePointers(dword_5d4594_3798632_arr)
		dword_5d4594_3798632_arr = nil
		C.dword_5d4594_3798632 = nil
	}
	if dword_5d4594_3798644_arr != nil {
		alloc.FreeBytes(dword_5d4594_3798644_arr)
		dword_5d4594_3798644_arr = nil
		C.dword_5d4594_3798644 = nil
	}
}

func sub_4AE520() {
	sub_4AEDF0()
	C.sub_4AEE30()
}

//export sub_4AEBD0
func sub_4AEBD0() {
	height := getBackbufSize().H
	C.dword_5d4594_3798648, dword_5d4594_3798648_arr = C.dword_5d4594_3798644, dword_5d4594_3798644_arr
	v0 := 0
	C.dword_5d4594_3798640 = 0
	for C.dword_5d4594_3798636 = 0; int(C.dword_5d4594_3798636) < height; C.dword_5d4594_3798636++ {
		dword_5d4594_3798632_arr[v0] = nil
		v0 = int(C.dword_5d4594_3798636 + 1)
	}
	C.dword_5d4594_3798636 = C.uint(v0 - 1)
}

func sub_49F610() {
	bsz := getBackbufSize()
	C.ptr_5D4594_3799572.data[0] = 0
	C.ptr_5D4594_3799572.data[1] = 0
	C.ptr_5D4594_3799572.data[2] = 0
	C.ptr_5D4594_3799572.data[3] = C.uint(bsz.W)
	C.ptr_5D4594_3799572.data[4] = C.uint(bsz.H)
	C.ptr_5D4594_3799572.data[5] = 0
	C.ptr_5D4594_3799572.data[6] = 0
	C.ptr_5D4594_3799572.data[7] = C.uint(bsz.W - 1)
	C.ptr_5D4594_3799572.data[8] = C.uint(bsz.H - 1)
	C.ptr_5D4594_3799572.data[9] = 0
	C.ptr_5D4594_3799572.data[10] = 0
	C.ptr_5D4594_3799572.data[11] = C.uint(bsz.W)
	C.ptr_5D4594_3799572.data[12] = C.uint(bsz.H)
	C.dword_5d4594_1305748 = 0
}

//export sub_49FC20
func sub_49FC20(a1, a2, a3, a4 *C.int) int {
	var v4, v5 int
	if C.ptr_5D4594_3799572.data[0] != 0 {
		v4 = int(C.ptr_5D4594_3799572.data[6])
		v5 = int(C.ptr_5D4594_3799572.data[8])
	} else {
		v4 = 0
		v5 = getBackbufSize().H - 1
	}
	v16 := 0
	v6 := int(*a1)
	v7 := int(*a3)
	v8 := int(*a2)
	v9 := int(*a4)
	if v8 >= v4 {
		if v8 > v5 {
			v16 = 4
		}
	} else {
		v16 = 8
	}
	v17 := 0
	if v9 >= v4 {
		if v9 > v5 {
			v17 = 4
		}
	} else {
		v17 = 8
	}
	if v17&v16 != 0 {
		return 0
	}
	if v16 != 0 {
		if v16&8 != 0 {
			if v9 == v8 {
				return 0
			}
			v11 := (v4 - v8) * (v7 - v6) / (v9 - v8)
			v8 = v4
			v6 += v11
		} else if v16&4 != 0 {
			if v9 == v8 {
				return 0
			}
			v12 := (v5 - v8) * (v7 - v6) / (v9 - v8)
			v8 = v5
			v6 += v12
		}
	}
	if v17 != 0 {
		if v17&8 != 0 {
			if v9 == v8 {
				return 0
			}
			v13 := (v7 - v6) * (v4 - v9) / (v9 - v8)
			v9 = v4
			v7 += v13
		} else if v17&4 != 0 {
			if v9 == v8 {
				return 0
			}
			v14 := (v7 - v6) * (v5 - v9) / (v9 - v8)
			v9 = v5
			v7 += v14
		}
	}
	*a1 = C.int(v6)
	*a2 = C.int(v8)
	*a3 = C.int(v7)
	*a4 = C.int(v9)
	return 1
}

//export sub_440900
func sub_440900() {
	height := getBackbufSize().H
	val := uint32(C.ptr_5D4594_3799572.data[58])
	for y := 0; y < height; y++ {
		row := asU32Slice(nox_pixbuffer_main_rows[y], nox_backbuffer_width32*8)
		for x := 0; x < nox_backbuffer_width32*8; x++ {
			row[x] = val
		}
	}
}

func nox_free_pixbuffers_486110() {
	if memmap.Uint32(0x5D4594, 1193200) == 0 {
		if nox_pixbuffer_main != nil {
			alloc.FreeBytes(nox_pixbuffer_main)
			nox_pixbuffer_main = nil
		}
		if nox_pixbuffer_3798788_arr != nil {
			alloc.FreeBytes(nox_pixbuffer_3798788_arr)
			nox_pixbuffer_3798788_arr = nil
			C.nox_pixbuffer_3798788 = nil
		}
	}
	if nox_pixbuffer_main_rows != nil {
		alloc.FreePointers(nox_pixbuffer_main_rows)
		nox_pixbuffer_main_rows = nil
		C.nox_pixbuffer_rows_3798784 = nil
	}
	if nox_pixbuffer_rows_3798776_arr != nil {
		alloc.FreePointers(nox_pixbuffer_rows_3798776_arr)
		nox_pixbuffer_rows_3798776_arr = nil
		C.nox_pixbuffer_rows_3798776 = nil
	}
}

func sub_486090() error {
	sub_4861D0()
	sub_486230()
	return nil
}

func sub_4861D0() {
	if memmap.Uint32(0x5D4594, 1193200) != 0 {
		return
	}
	sz := getBackbufSize()

	nox_pixbuffer_main = alloc.Bytes(uintptr(2 * sz.W * sz.H))
	if C.nox_video_renderTargetFlags&0x40 == 0 {
		return
	}

	nox_pixbuffer_3798788_arr = alloc.Bytes(uintptr(len(nox_pixbuffer_main)))
	C.nox_pixbuffer_3798788 = (*C.uchar)(unsafe.Pointer(&nox_pixbuffer_3798788_arr[0]))
}

func sub_486230() {
	sz := getBackbufSize()
	nox_pixbuffer_main_rows = alloc.Pointers(sz.H)
	C.nox_pixbuffer_rows_3798784 = (**C.uchar)(unsafe.Pointer(&nox_pixbuffer_main_rows[0]))
	for y := 0; y < sz.H; y++ {
		nox_pixbuffer_main_rows[y] = unsafe.Pointer(&nox_pixbuffer_main[y*2*sz.W])
	}

	if C.nox_video_renderTargetFlags&0x40 == 0 {
		return
	}

	nox_pixbuffer_rows_3798776_arr = alloc.Pointers(sz.H)
	C.nox_pixbuffer_rows_3798776 = (**C.uchar)(unsafe.Pointer(&nox_pixbuffer_rows_3798776_arr[0]))
	for y := 0; y < sz.H; y++ {
		nox_pixbuffer_rows_3798776_arr[y] = unsafe.Pointer(&nox_pixbuffer_3798788_arr[y*2*sz.W])
	}
}

//export sub_48B3F0
func sub_48B3F0(a1 unsafe.Pointer, a2, a3 C.int) C.int {
	if nox_video_cursorDrawIsThreaded {
		mu := asMutex(memmap.PtrOff(0x973F18, 168))
		mu.Lock()
		*memmap.PtrUint32(0x5D4594, 1193640) = uint32(C.dword_5d4594_1193648)
		*memmap.PtrUint32(0x5D4594, 1193628) = uint32(C.dword_5d4594_1193524)
		C.dword_5d4594_1193648 = C.uint(a2)
		C.dword_5d4594_1193524 = C.uint(a3)
		if a1 != nil && a1 != C.dword_5d4594_1193624 {
			C.dword_5d4594_1193624 = a1
			for i := range dword_5d4594_1193704_arr {
				C.sub_49D1C0(dword_5d4594_1193704_arr[i], C.int(memmap.Uint32(0x5D4594, 1193592)), 128)
			}
			pp := (*[2]C.uint)(alloc.Malloc(8))
			defer alloc.Free(unsafe.Pointer(pp))
			if C.sub_48C0C0(a1, &pp[0], &pp[1]) != 0 {
				dword_6F7C10(a1, uint32(pp[0]), uint32(pp[1]))
				*memmap.PtrUint32(0x5D4594, 1193580) = uint32(pp[0])
				*memmap.PtrUint32(0x5D4594, 1193600) = uint32(C.dword_5d4594_1193568)
				*memmap.PtrUint32(0x5D4594, 1193620) = uint32(C.dword_5d4594_1193576)
				*memmap.PtrUint32(0x5D4594, 1193636) = uint32(pp[1])
				*memmap.PtrUint32(0x5D4594, 1193604) = 0
				*memmap.PtrUint32(0x5D4594, 1193608) = 0
				*memmap.PtrUint32(0x5D4594, 1193612) = uint32(C.dword_5d4594_1193568)
				*memmap.PtrUint32(0x5D4594, 1193616) = uint32(C.dword_5d4594_1193576)
				C.dword_5d4594_1193664 = 1
			}
		}
		if uint32(C.dword_5d4594_1193648) != memmap.Uint32(0x5D4594, 1193640) ||
			uint32(C.dword_5d4594_1193524) != memmap.Uint32(0x5D4594, 1193628) {
			C.dword_5d4594_1193668 = 1
		}
		mu.Unlock()
	} else if C.dword_5d4594_1193672 != 0 && a1 != nil {
		C.nox_client_drawImageAt_47D2C0((*C.nox_video_bag_image_t)(a1), a2, a3)
		return 1
	}
	return 1
}

//export nox_draw_setCutSize_476700
func nox_draw_setCutSize_476700(cutPerc C.int, a2 C.int) {
	vp := getViewport()
	bsz := getBackbufSize()
	v2 := int(a2)
	v4 := int(vp.width)
	perc := int(cutPerc)
	if a2 != 0 {
		v7 := 0
		for v7 < 4 {
			perc = v2 + 100*(bsz.W-2*int(vp.x1))/bsz.W
			v6 := perc * bsz.W / 100
			if v2 >= 0 {
				v2++
			} else {
				v2--
			}
			if v6-v4 < 0 {
				v7 = v4 - v6
			} else {
				v7 = v6 - v4
			}
		}
	}
	if perc >= 40 {
		if perc > 100 {
			perc = 100
		}
	} else {
		perc = 40
	}
	C.nox_video_cutSize = C.int(perc)

	vp.x1 = C.int(uint32((bsz.W-perc*bsz.W/100)/2) & 0xFFFFFFFC)
	if vp.x1 < 0 {
		vp.x1 = 0
	}

	vp.y1 = C.int((bsz.H - perc*bsz.H/100) / 2)
	if vp.y1 < 0 {
		vp.y1 = 0
	}

	vp.x2 = C.int(uint32(bsz.W-int(vp.x1)+2) & 0xFFFFFFFC)
	if int(vp.x2) >= bsz.W {
		vp.x2 = C.int(bsz.W - 1)
	}

	vp.y2 = C.int(bsz.H - int(vp.y1) - 1)
	if int(vp.y2) >= bsz.H {
		vp.y2 = C.int(bsz.H - 1)
	}

	vp.width = C.int(vp.x2 - vp.x1 + 1)
	vp.height = C.int(vp.y2 - vp.y1 + 1)
	C.dword_5d4594_1193188 = 1
	C.dword_5d4594_3799524 = 1
}

func nox_client_drawXxx_444AC0(w, h, depth int, flags int) error {
	//int v5;             // eax
	//bool v6;            // zf
	//unsigned __int8 v7 = 0; // al
	//int v8;             // esi
	//int v9;             // eax
	//int v10;            // eax

	nox_mutex_initP(memmap.PtrOff(0x973F18, 168))
	*memmap.PtrUint32(0x5D4594, 823780) = 1

	C.nox_video_renderTargetFlags = C.int(flags)

	// Force always WINNT, forces always using unlocked DX surfaces
	C.nox_video_windowsPlatformVersion = 5

	var v7 byte
	if C.nox_video_windowsPlatformVersion == 5 { // if Windows NT platform
		v7 = byte(C.nox_video_renderTargetFlags | 0x20)
		C.nox_video_renderTargetFlags |= 0x120
	}
	v8 := int(uint32(w) & 0xFFFFFFE0)
	if v7&4 == 0 {
		if err := resetRenderer(types.Size{W: v8, H: h}); err != nil {
			return err
		}
		return nil
	}
	panic("TODO")
	v9 := (v7 & 0x17) - 20
	*memmap.PtrUint32(0x973F18, 2368) = 0
	//nox_backbuffer_width = v8
	//nox_backbuffer_height = h
	//nox_backbuffer_pitchDiff = 0
	//dword_973C64 = 0
	if v9 == 0 {
		C.dword_5d4594_3799624 = 0
		//nox_backbuffer_pitch_3801808 = v8
		C.dword_5d4594_3801780 = 0
		*memmap.PtrUint32(0x973F18, 2348) = uint32(v8) >> 2
		nox_backbuffer_width32 = v8 >> 5
		return nil
	}
	v10 := v9 - 1
	if v10 != 0 {
		if v10 != 1 {
			return errors.New("nox_client_drawXxx_444AC0 failed")
		}
		C.dword_5d4594_3799624 = 2
	} else {
		C.dword_5d4594_3799624 = 1
	}
	C.dword_5d4594_3801780 = 1
	//nox_backbuffer_pitch_3801808 = 2 * v8
	*memmap.PtrUint32(0x973F18, 2348) = uint32(v8) >> 1
	nox_backbuffer_width32 = v8 >> 4
	return nil
}

func sub_48B800(a1 uint32) {
	p := (*[3]C.int)(alloc.Malloc(12))
	defer alloc.Free(unsafe.Pointer(p))
	C.sub_434480(C.int(a1), &p[0], &p[1], &p[2])
	sub_48B6B0(byte(p[0]), byte(p[1]), byte(p[2]))
}

func sub_48B6B0(a1, a2, a3 byte) {
	if !nox_video_cursorDrawIsThreaded {
		C.sub_433CD0(C.uchar(a1), C.uchar(a2), C.uchar(a3))
	} else {
		C.ptr_5D4594_3799572.data[34] = C.uint(a1)
		C.ptr_5D4594_3799572.data[35] = C.uint(a2)
		C.ptr_5D4594_3799572.data[36] = C.uint(a3)
	}
}

func sub_48B590() (a1 unsafe.Pointer, a2, a3 int) {
	return C.dword_5d4594_1193624, int(C.dword_5d4594_1193648), int(C.dword_5d4594_1193524)
}

func sub_48B680(a1 int) {
	if a1 != int(C.ptr_5D4594_3799572.data[15]) {
		if nox_video_cursorDrawIsThreaded {
			C.ptr_5D4594_3799572.data[15] = C.uint(a1)
		} else {
			C.ptr_5D4594_3799572.data[14] = C.uint(a1)
		}
		C.sub_48BD90(1)
	}
}

func nox_video_cursorDrawImpl_477A30(inp *input.Handler, a2, a3 int) {
	v18 := memmap.Uint32(0x973F18, 68)
	v3 := a2 - 64
	v4 := a3 - 64
	*memmap.PtrUint32(0x973F18, 68) = 0
	C.dword_5d4594_3798728 = 1
	C.dword_5d4594_1097212 = C.int(a2 - 64)
	C.dword_5d4594_1097216 = C.int(a3 - 64)
	if gameFrame()&1 != 0 {
		*memmap.PtrUint32(0x5D4594, 1097288)++
	}
	nox_xxx_drawSetTextColor_434390(memmap.Uint32(0x5D4594, 2589772))
	v5 := nox_xxx_guiFontHeightMB_43F320(0)
	if C.nox_xxx_guiSpell_460650() != 0 || C.sub_4611A0() != 0 {
		nox_video_drawAnimatedImageOrCursorAt_4BE6D0(memmap.Uint32(0x5D4594, 1097240), v3, v4)
		C.dword_5d4594_3798728 = 0
		C.nox_xxx_cursorTypePrev_587000_151528 = 5
		*memmap.PtrUint32(0x973F18, 68) = v18
		return
	}
	v6 := C.nox_client_mouseCursorType
	if C.nox_client_mouseCursorType != C.nox_xxx_cursorTypePrev_587000_151528 && C.nox_client_mouseCursorType != 14 {
		sub_48B680(0)
		v6 = C.nox_client_mouseCursorType
	}
	switch v6 {
	case 1:
		v10 := strMan.GetStringInFile("GRAB", "C:\\NoxPost\\src\\Client\\Gui\\guicurs.c")
		nox_xxx_drawString_43F6E0(0, v10, v3+54, a3-v5)
		nox_video_drawAnimatedImageOrCursorAt_4BE6D0(memmap.Uint32(0x5D4594, 1097224), v3, v4)
	case 2:
		v7 := strMan.GetStringInFile("PICKUP", "C:\\NoxPost\\src\\Client\\Gui\\guicurs.c")
		nox_xxx_drawString_43F6E0(0, v7, v3+49, v5+a3)
		nox_video_drawAnimatedImageOrCursorAt_4BE6D0(memmap.Uint32(0x5D4594, 1097228), v3, v4)
		dword_5d4594_1097208 = -2 * v5
	case 3:
		v8 := strMan.GetStringInFile("SHOPKEEPER", "C:\\NoxPost\\src\\Client\\Gui\\guicurs.c")
		nox_xxx_drawString_43F6E0(0, v8, v3+39, a3-v5)
		nox_video_drawAnimatedImageOrCursorAt_4BE6D0(memmap.Uint32(0x5D4594, 1097232), v3, v4)
	case 4:
		v9 := strMan.GetStringInFile("TALK", "C:\\NoxPost\\src\\Client\\Gui\\guicurs.c")
		nox_xxx_drawString_43F6E0(0, v9, v3+49, a3-v5)
		nox_video_drawAnimatedImageOrCursorAt_4BE6D0(memmap.Uint32(0x5D4594, 1097236), v3, v4)
	case 6, 7:
		v11 := strMan.GetStringInFile("IDENTIFY", "C:\\NoxPost\\src\\Client\\Gui\\guicurs.c")
		nox_xxx_drawString_43F6E0(0, v11, v3+49, v4+88)
		nox_video_drawAnimatedImageOrCursorAt_4BE6D0(memmap.Uint32(0x5D4594, 1097220+4*uintptr(C.nox_client_mouseCursorType)), v3, v4)
	case 8:
		v12 := strMan.GetStringInFile("REPAIR", "C:\\NoxPost\\src\\Client\\Gui\\guicurs.c")
		nox_xxx_drawString_43F6E0(0, v12, v3+49, a3-v5)
		nox_video_drawAnimatedImageOrCursorAt_4BE6D0(memmap.Uint32(0x5D4594, 1097252), v3, v4)
		dword_5d4594_1097208 = 2*v5 + 4
	case 9, 10, 11, 12:
		nox_video_drawAnimatedImageOrCursorAt_4BE6D0(memmap.Uint32(0x5D4594, 1097220+4*uintptr(v6)), v3, v4)
	case 13:
		v13 := strMan.GetStringInFile("USE", "C:\\NoxPost\\src\\Client\\Gui\\guicurs.c")
		nox_xxx_drawString_43F6E0(0, v13, v3+54, v5+a3)
		nox_video_drawAnimatedImageOrCursorAt_4BE6D0(memmap.Uint32(0x5D4594, 1097272), v3, v4)
		dword_5d4594_1097208 = -2 * v5
	case 14:
		mpos := inp.GetMousePos()
		v19 := types.Pointf{
			X: float32(mpos.X - nox_win_width/2),
			Y: float32(mpos.Y - nox_win_height/2),
		}
		v15 := nox_xxx_math_509ED0(v19) / 8
		if v19.X*v19.X+v19.Y*v19.Y > 100*100 || memmap.Uint32(0x852978, 8) != 0 && *(*uint32)(unsafe.Pointer(uintptr(*memmap.PtrPtr(0x852978, 8)) + 276)) == 6 {
			v15 += 32
		}
		v16 := nox_xxx_spriteGetMB_476F80()
		if v16 != nil {
			sub_48B680(1)
			if v16.Flags28()&6 == 0 || C.sub_495A80(C.int(v16.Field32())) != 0 {
				sub_48B800(memmap.Uint32(0x85B3FC, 980))
			} else {
				sub_48B800(memmap.Uint32(0x85B3FC, 940))
			}
		} else {
			sub_48B680(0)
		}
		C.sub_4BE710(C.int(memmap.Uint32(0x5D4594, 1097276)), C.int(v3), C.int(v4), C.int(v15))
		C.sub_4345F0(0)
	case 15:
		nox_video_drawAnimatedImageOrCursorAt_4BE6D0(memmap.Uint32(0x5D4594, 1097220+4*uintptr(v6)), v3, v4)
		dword_5d4594_1097208 = -2 * v5
	case 16:
		nox_video_drawAnimatedImageOrCursorAt_4BE6D0(memmap.Uint32(0x5D4594, 1097220+4*uintptr(v6)), v3, v4)
		dword_5d4594_1097208 = -v5
	default:
		nox_video_drawAnimatedImageOrCursorAt_4BE6D0(memmap.Uint32(0x5D4594, 1097220), v3, v4)
	}
	C.dword_5d4594_3798728 = 0
	C.nox_xxx_cursorTypePrev_587000_151528 = C.nox_client_mouseCursorType
	*memmap.PtrUint32(0x973F18, 68) = v18
}

//export nox_xxx_bookSaveSpellForDragDrop_477640
func nox_xxx_bookSaveSpellForDragDrop_477640(a1, a2 C.int) {
	nox_client_spellDragnDrop_1097192 = uint32(a1)
	nox_client_spellDragnDrop_type_1097196 = int(a2)
}

//export nox_xxx_bookSpellDnDclear_477660
func nox_xxx_bookSpellDnDclear_477660() {
	nox_client_spellDragnDrop_1097192 = 0
	nox_client_spellDragnDrop_type_1097196 = 0
}

//export nox_xxx_bookGetSpellDnDType_477670
func nox_xxx_bookGetSpellDnDType_477670() C.int {
	return C.int(nox_client_spellDragnDrop_type_1097196)
}

//export nox_xxx_cursorGetDraggedItem_477680
func nox_xxx_cursorGetDraggedItem_477680() *C.nox_drawable {
	return nox_client_itemDragnDrop_1097188.C()
}

//export nox_xxx_cursorSetDraggedItem_477690
func nox_xxx_cursorSetDraggedItem_477690(a1 *C.nox_drawable) {
	nox_client_itemDragnDrop_1097188 = asDrawable(a1)
}

//export nox_xxx_cursorResetDraggedItem_4776A0
func nox_xxx_cursorResetDraggedItem_4776A0() {
	nox_client_itemDragnDrop_1097188 = nil
}

func nox_client_drawCursorAndTooltips_477830(inp *input.Handler) {
	if memmap.Uint32(0x5D4594, 1097220) == 0 {
		C.nox_xxx_cursorLoadAll_477710()
	}
	mpos := inp.GetMousePos()
	vp := asViewport((*C.nox_draw_viewport_t)(alloc.Malloc(unsafe.Sizeof(C.nox_draw_viewport_t{}))))
	defer alloc.Free(unsafe.Pointer(vp.C()))
	vp.x1 = 0
	vp.y1 = 0
	vp.x2 = C.int(nox_win_width)
	vp.y2 = C.int(nox_win_height)
	vp.field_4 = 0
	vp.field_5 = 0
	vp.width = C.int(nox_win_width)
	vp.height = C.int(nox_win_height)
	dword_5d4594_1097204 = 0
	dword_5d4594_1097208 = nox_xxx_guiFontHeightMB_43F320(0) + 4
	if nox_client_itemDragnDrop_1097188 != nil { // Dragging item
		nox_client_itemDragnDrop_1097188.SetPos(mpos)
		nox_client_itemDragnDrop_1097188.DrawFunc(vp)
	}
	if nox_client_spellDragnDrop_1097192 != 0 { // Player is dragging spell or ability
		pl := getPlayerByID(int(memmap.Int32(0x85319C, 0)))
		if pl == nil || pl.PlayerClass() != player.Warrior {
			v2 := C.nox_xxx_spellIcon_424A90(C.int(nox_client_spellDragnDrop_1097192)) // Spell icon
			if v2 != nil {
				nox_client_drawImageAt_47D2C0((*C.nox_video_bag_image_t)(v2), mpos.X-15, mpos.Y-15)
			}
		} else {
			v2 := C.nox_xxx_spellGetAbilityIcon_425310(C.int(nox_client_spellDragnDrop_1097192), 0) // Ability icon
			if v2 != nil {
				nox_client_drawImageAt_47D2C0((*C.nox_video_bag_image_t)(v2), mpos.X-15, mpos.Y-15)
			}
		}
	}
	nox_video_cursorDrawImpl_477A30(inp, mpos.X, mpos.Y)
	if str := GoWStringP(memmap.PtrOff(0x5D4594, 1096676)); str != "" && C.nox_xxx_useAudio_587000_80840 == 1 {
		sz := nox_xxx_drawGetStringSize_43F840(0, str, 0)
		px := mpos.X - dword_5d4594_1097204
		py := mpos.Y - dword_5d4594_1097208
		sz.W += 4
		sz.H += 4
		if px+sz.W >= nox_win_width {
			px -= sz.W
		}
		if px < 0 {
			px = 0
		}
		if py+sz.H >= nox_win_height {
			py = nox_win_height - sz.H
		}
		if py < 0 {
			py = 0
		}
		nox_client_drawRectFilledAlpha_49CF10(px, py, sz.W, sz.H)
		nox_xxx_drawSetTextColor_434390(memmap.Uint32(0x5D4594, 2589772))
		nox_xxx_drawString_43FAF0(0, str, px+2, py+2, 0, 0)
		if C.dword_5d4594_3799468 != 0 {
			vp := getViewport()
			if px < int(vp.x1) || px+sz.W > int(vp.x2) || py < int(vp.y1) || py+sz.H > int(vp.y2) {
				C.dword_5d4594_3799524 = 1
			}
		}
	}
}

//export sub_477F80
func sub_477F80() {
	if !nox_video_cursorDrawIsThreaded {
		if C.dword_5d4594_3799468 != 0 {
			vp := getViewport()
			if C.dword_5d4594_1097212 < vp.x1 || C.dword_5d4594_1097212+64 >= vp.x2 || C.dword_5d4594_1097216 < vp.y1 || C.dword_5d4594_1097216+64 >= vp.y2 {
				nox_client_drawSetColor_434460(memmap.Uint32(0x85B3FC, 952))
				nox_client_drawRectFilledOpaque_49CE30(int(C.dword_5d4594_1097212)+32, int(C.dword_5d4594_1097216)+32, 64, 64)
			}
		}
	}
}

//export sub_444C50
func sub_444C50() {
	if C.dword_5d4594_823776 != 0 {
		nox_video_stopCursorDrawThread_48B350()
		nox_free_pixbuffers_486110()
		C.sub_433C20()
		C.sub_44D9D0()
		C.sub_4B0660()
		C.sub_4AF950()
		sub_4AE540()
		C.nox_xxx_FontDestroy_43F2E0()
		C.sub_49F4D0()
		C.dword_5d4594_823776 = 0
		if memmap.Uint32(0x5D4594, 823780) != 0 {
			nox_mutex_freeP(memmap.PtrOff(0x973F18, 168))
			*memmap.PtrUint32(0x5D4594, 823780) = 0
		}
	}
}

//export sub_478000
func sub_478000() C.int {
	C.sub_467CD0()
	if nox_client_spellDragnDrop_type_1097196 != 0 {
		v1 := nox_xxx_wndGetCaptureMain_46AE00()
		nox_xxx_wndClearCaptureMain_46ADE0(v1)
		nox_xxx_bookSpellDnDclear_477660()
	}
	return 0
}
