package nox

/*
#include "client__video__draw_common.h"
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME2_2.h"
#include "GAME2_3.h"
#include "GAME3.h"
#include "GAME3_1.h"
#include "common__magic__speltree.h"
extern int g_fullscreen_cfg;
extern unsigned int dword_5d4594_805860;
extern int nox_video_dxFullScreen;
extern int nox_enable_threads;
extern int nox_video_dxFullScreen;
extern unsigned int nox_video_dxUnlockSurface;
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
extern unsigned int nox_client_showTooltips_80840;
extern int dword_5d4594_3799524;
extern int nox_client_mouseCursorType;
extern int nox_xxx_cursorTypePrev_587000_151528;
extern int nox_video_cutSize;
extern int nox_win_width;
extern int nox_win_height;
extern unsigned char** nox_pixbuffer_rows_3798776;
extern unsigned char* nox_pixbuffer_3798788;
int nox_video_initFloorBuffer_430BA0();
int nox_xxx___cfltcvt_init_430CC0();
*/
import "C"
import (
	"errors"
	"fmt"
	"image"
	"unsafe"

	"nox/v1/client/input"
	"nox/v1/common/alloc"
	noxcolor "nox/v1/common/color"
	"nox/v1/common/memmap"
	"nox/v1/common/noximage"
	"nox/v1/common/player"
	"nox/v1/common/types"
)

var (
	g_scaled                               int
	nox_win_width                          int
	nox_win_height                         int
	dword_6F7C10                           func(a1 *Image, a2, a3 uint32)
	nox_pixbuffer_rows_3798776_arr         []unsafe.Pointer
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
	noxPixBuffer                           struct {
		img      *noximage.Image16
		free     func()
		rows     []*uint16
		freeRows func()
		onResize []func(sz types.Size)
	}
)

func OnPixBufferResize(fnc func(sz types.Size)) {
	noxPixBuffer.onResize = append(noxPixBuffer.onResize, fnc)
}

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

func updateGamma(value int) {
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

//export sub_43BE50_get_video_mode_id
func sub_43BE50_get_video_mode_id() C.int {
	return C.int(videoModeID())
}

//export get_video_mode_string
func get_video_mode_string(cid C.int) *C.wchar_t {
	id := int(cid)
	if id < 0 || id >= len(noxVideoModes) {
		return internWStr("custom")
	}
	mode := noxVideoModes[id]
	return internWStr(fmt.Sprintf("%dx%d", mode.W, mode.H))
}

//export nox_getBackbufWidth
func nox_getBackbufWidth() C.int {
	return C.int(noxPixBuffer.img.Rect.Dx())
}

//export nox_getBackbufHeight
func nox_getBackbufHeight() C.int {
	return C.int(noxPixBuffer.img.Rect.Dy())
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
	return true
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

//export nox_video_resizewnd
func nox_video_resizewnd(w, h, d C.int) {
	videoResizeView(types.Size{
		W: int(w),
		H: int(h),
	})
}

func videoGetGameMode() types.Size {
	return types.Size{
		W: int(C.nox_win_width_game),
		H: int(C.nox_win_height_game),
	}
}

func videoSetGameMode(mode types.Size) {
	C.nox_win_width_game = C.int(mode.W)
	C.nox_win_height_game = C.int(mode.H)
	C.nox_win_depth_game = 16
	setScreenSize(mode)
}

//export nox_common_parsecfg_videomode_apply
func nox_common_parsecfg_videomode_apply(w, h, d C.int) {
	videoApplyConfigVideoMode()
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
	}
}

//export nox_video_callCopyBackBuffer_4AD170
func nox_video_callCopyBackBuffer_4AD170() {
	copyPixBuffer()
}

func videoInit(sz types.Size, flags int) error {
	C.dword_5d4594_823776 = 0
	noxrend.SetData(asRenderData(&C.obj_5D4594_3799660))
	C.nox_draw_curDrawData_3799572 = noxrend.Data().C()
	if err := drawInitAll(sz, flags); err != nil {
		videoLog.Println("init:", err)
		return err
	}
	noxrend.SetData(asRenderData(&C.obj_5D4594_3800716))
	C.nox_draw_curDrawData_3799572 = noxrend.Data().C()
	C.obj_5D4594_3800716 = C.obj_5D4594_3799660
	C.dword_5d4594_823776 = 1
	C.dword_5d4594_823772++
	return nil
}

func videoInitStub() {
	noxrend.SetData(asRenderData(&C.obj_5D4594_3800716))
	C.nox_draw_curDrawData_3799572 = noxrend.Data().C()
	C.dword_5d4594_823776 = 1
	C.nox_win_width = noxDefaultWidth
	C.nox_win_height = noxDefaultHeight
}

func drawInitAll(sz types.Size, flags int) error {
	if err := nox_client_drawXxx_444AC0(sz.W, sz.H, flags); err != nil {
		return err
	}
	sub_47D200()
	nox_video_initPixbuffer_486090(sz)
	sub_49F610(sz)
	if res := sub_4338D0(); res == 0 {
		return errors.New("sub_4338D0 failed")
	}
	if err := nox_video_setBackBufferCopyFunc_4AD100(); err != nil {
		return err
	}
	if res := C.nox_client_initFade2_44D9A0(); res == 0 {
		return errors.New("nox_client_initFade2_44D9A0 failed")
	}
	noxrend.initParticles()
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
	if err := loadGameFonts(); err != nil {
		return err
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

func recreateBuffersAndTarget(sz types.Size) error {
	C.nox_video_freeFloorBuffer_430EC0()
	if err := recreateRenderTarget(sz); err != nil {
		videoLog.Println("recreate render target:", err)
		return err
	}
	videoLog.Println("recreate render target: ok")
	if err := nox_video_initFloorBuffer_430BA0(sz); err != nil {
		return err
	}
	return nil
}

func recreateRenderTarget(sz types.Size) error {
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
	if err := videoInit(videoGetWindowSize(), int(flags)); err != nil {
		v9 := strMan.GetStringInFile("result:ERROR", "C:\\NoxPost\\src\\Client\\Io\\Win95\\dxvideo.c")
		v4 := strMan.GetStringInFile("gfxDdraw.c:DXWarning", "C:\\NoxPost\\src\\Client\\Io\\Win95\\dxvideo.c")
		// TODO: show OS modal message
		_, _ = v4, v9
		return err
	}
	nox_xxx_cursorLoadAll_477710()
	nox_client_setCursorType_477610(int(v1))
	C.sub_48B3E0(v2)
	nox_client_clearScreen_440900()
	C.nox_xxx_setupSomeVideo_47FEF0()
	C.sub_49F6D0(1)
	C.sub_437290()
	//videoSet16Bit(C.dword_5d4594_3801780 != 0)
	*memmap.PtrUint32(0x973F18, 6060) = uint32(2 * sz.W * sz.H)
	*memmap.PtrUint32(0x973F18, 7696) = uint32(bool2int(C.dword_5d4594_3801780 == 1))
	C.sub_430B50(0, 0, noxDefaultWidth-1, noxDefaultHeight-1)
	return nil
}

//export nox_getBackbufferPitch
func nox_getBackbufferPitch() C.int {
	return C.int(2 * noxPixBuffer.img.Stride)
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
	for C.sub_43DC40() != 0 || sub_44D930() {
		sub_4312C0()
		//#ifdef __EMSCRIPTEN__
		//nox_platform_sleep(0x32u);
		//#endif
	}
	sub_43E8E0(0)
	v12 := C.sub_48B3E0(0)
	//inpHandler.UnacquireMouse()
	//sub_48A7F0()
	v2 := C.dword_5d4594_3801780
	var (
		v4     int
		prevSz types.Size
		vpos   types.Point
		v11    *Image
	)
	if v2 != 0 {
		v4 = a1
	} else {
		v11, vpos = sub_48B590()
		v2 = C.dword_5d4594_3801780
		v4 = int(C.nox_video_renderTargetFlags)
		prevSz = noxPixBuffer.img.Size()
		nox_video_stopCursorDrawThread_48B350()
		nox_draw_freeColorTables_433C20()
		nox_free_pixbuffers_486110()
		C.nox_video_renderTargetFlags = C.int(v4)
		sz := types.Size{W: noxDefaultWidth, H: noxDefaultHeight}
		if err := resetRenderer(sz, false); err != nil {
			return err
		}
		nox_video_initPixbuffer_486090(sz)
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
		if err := resetRenderer(prevSz, false); err != nil {
			return err
		}
		nox_video_initPixbuffer_486090(prevSz)
		if sub_4338D0() == 0 {
			return errors.New("sub_4338D0 failed")
		}
		noxrend.noxDrawCursor(v11, vpos)
	}
	sub_43E910(0)
	C.sub_43DBE0()
	//inpHandler.AcquireMouse()
	C.sub_48B3E0(v12)
	C.sub_4B05D0()
	return nil
}

func nox_video_initFloorBuffer_430BA0(sz types.Size) error {
	C.nox_xxx___cfltcvt_init_430CC0()
	if C.nox_xxx_tileInitBuf_430DB0(C.int(sz.W), C.int(sz.H)) == 0 {
		return errors.New("VideoInit: error initializing floor buffer")
	}
	if lightsOutBuf == nil {
		lightsOutBuf, _ = alloc.Uints32(6)
		lightsOutBuf[0] = 255
		lightsOutBuf[1] = 255
		lightsOutBuf[2] = 255
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
	height := noxPixBuffer.img.Rect.Dy()
	dword_5d4594_3798632_arr, _ = alloc.Pointers(height)
	C.dword_5d4594_3798632 = (*C.char)(unsafe.Pointer(&dword_5d4594_3798632_arr[0]))

	dword_5d4594_3798644_arr, _ = alloc.Bytes(uintptr(height) << 6)
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
	C.dword_5d4594_3798648, dword_5d4594_3798648_arr = C.dword_5d4594_3798644, dword_5d4594_3798644_arr
	v0 := 0
	C.dword_5d4594_3798640 = 0
	for C.dword_5d4594_3798636 = 0; int(C.dword_5d4594_3798636) < noxPixBuffer.img.Rect.Dy(); C.dword_5d4594_3798636++ {
		dword_5d4594_3798632_arr[v0] = nil
		v0 = int(C.dword_5d4594_3798636 + 1)
	}
	C.dword_5d4594_3798636 = C.uint(v0 - 1)
}

func sub_49F610(sz types.Size) {
	p := noxrend.Data()
	p.flag_0 = 0
	p.clip = C.nox_rect{right: C.int(sz.W), bottom: C.int(sz.H)}
	p.rect2 = C.nox_rect{right: C.int(sz.W - 1), bottom: C.int(sz.H - 1)}
	p.field_9 = 0
	p.field_10 = 0
	p.field_11 = C.uint(sz.W)
	p.field_12 = C.uint(sz.H)
	C.dword_5d4594_1305748 = 0
}

//export sub_49FC20
func sub_49FC20(a1, a2, a3, a4 *C.int) int {
	var ys, ye int
	if p := noxrend.Data(); p.flag_0 != 0 {
		ys = int(p.rect2.top)
		ye = int(p.rect2.bottom)
	} else {
		ys = 0
		ye = noxPixBuffer.img.Rect.Dy() - 1
	}
	v16 := 0
	v6 := int(*a1)
	v7 := int(*a3)
	v8 := int(*a2)
	v9 := int(*a4)
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
		return 0
	}
	if v16 != 0 {
		if v16&8 != 0 {
			if v9 == v8 {
				return 0
			}
			v11 := (ys - v8) * (v7 - v6) / (v9 - v8)
			v8 = ys
			v6 += v11
		} else if v16&4 != 0 {
			if v9 == v8 {
				return 0
			}
			v12 := (ye - v8) * (v7 - v6) / (v9 - v8)
			v8 = ye
			v6 += v12
		}
	}
	if v17 != 0 {
		if v17&8 != 0 {
			if v9 == v8 {
				return 0
			}
			v13 := (v7 - v6) * (ys - v9) / (v9 - v8)
			v9 = ys
			v7 += v13
		} else if v17&4 != 0 {
			if v9 == v8 {
				return 0
			}
			v14 := (v7 - v6) * (ye - v9) / (v9 - v8)
			v9 = ye
			v7 += v14
		}
	}
	*a1 = C.int(v6)
	*a2 = C.int(v8)
	*a3 = C.int(v7)
	*a4 = C.int(v9)
	return 1
}

//export nox_client_clearScreen_440900
func nox_client_clearScreen_440900() {
	noxrend.ClearScreen()
}

func (r *NoxRender) ClearScreen() {
	cl := uint32(r.p.field_58)
	for i := range r.pix.Pix {
		r.pix.Pix[i] = uint16(cl)
	}
}

func nox_free_pixbuffers_486110() {
	if memmap.Uint32(0x5D4594, 1193200) == 0 {
		noxPixBuffer.img = nil
		if noxPixBuffer.free != nil {
			noxPixBuffer.free()
			noxPixBuffer.free = nil
		}

		if nox_pixbuffer_3798788_arr != nil {
			alloc.FreeBytes(nox_pixbuffer_3798788_arr)
			nox_pixbuffer_3798788_arr = nil
			C.nox_pixbuffer_3798788 = nil
		}
	}
	noxPixBuffer.rows = nil
	if noxPixBuffer.freeRows != nil {
		noxPixBuffer.freeRows()
		noxPixBuffer.freeRows = nil
		C.nox_pixbuffer_rows_3798784 = nil
	}
	if nox_pixbuffer_rows_3798776_arr != nil {
		alloc.FreePointers(nox_pixbuffer_rows_3798776_arr)
		nox_pixbuffer_rows_3798776_arr = nil
		C.nox_pixbuffer_rows_3798776 = nil
	}
}

func nox_video_initPixbuffer_486090(sz types.Size) {
	videoLog.Printf("initializing pixbuffer: %v", sz)
	nox_video_initPixbufferData_4861D0(sz)
	nox_video_initPixbufferRows_486230()
	for _, fnc := range noxPixBuffer.onResize {
		fnc(sz)
	}
}

func nox_video_initPixbufferData_4861D0(sz types.Size) {
	if memmap.Uint32(0x5D4594, 1193200) != 0 {
		return
	}
	data, free := alloc.Uints16(uintptr(sz.W * sz.H))
	noxPixBuffer.free = free
	noxPixBuffer.img = noximage.NewImage16WithData(data, sz)
	noxrend.SetPixBuffer(noxPixBuffer.img)
	if C.nox_video_renderTargetFlags&0x40 == 0 {
		return
	}

	nox_pixbuffer_3798788_arr, _ = alloc.Bytes(uintptr(len(data)))
	C.nox_pixbuffer_3798788 = (*C.uchar)(unsafe.Pointer(&nox_pixbuffer_3798788_arr[0]))
}

func nox_video_initPixbufferRows_486230() {
	sz := noxPixBuffer.img.Size()
	ptrs, freeRows := alloc.Pointers(sz.H)
	noxPixBuffer.rows = unsafe.Slice((**uint16)(unsafe.Pointer(&ptrs[0])), len(ptrs))
	noxPixBuffer.freeRows = freeRows
	C.nox_pixbuffer_rows_3798784 = (**C.uchar)(unsafe.Pointer(&noxPixBuffer.rows[0]))
	for y := 0; y < sz.H; y++ {
		noxPixBuffer.rows[y] = &noxPixBuffer.img.Row(y)[0]
	}

	if C.nox_video_renderTargetFlags&0x40 == 0 {
		return
	}

	nox_pixbuffer_rows_3798776_arr, _ = alloc.Pointers(sz.H)
	C.nox_pixbuffer_rows_3798776 = (**C.uchar)(unsafe.Pointer(&nox_pixbuffer_rows_3798776_arr[0]))
	for y := 0; y < sz.H; y++ {
		nox_pixbuffer_rows_3798776_arr[y] = unsafe.Pointer(&nox_pixbuffer_3798788_arr[y*2*sz.W])
	}
}

//export sub_48B3F0
func sub_48B3F0(a1 unsafe.Pointer, a2, a3 C.int) C.int {
	return C.int(noxrend.noxDrawCursor(asImageP(a1), types.Point{X: int(a2), Y: int(a3)}))
}

func (r *NoxRender) noxDrawCursor(a1 *Image, pos types.Point) int {
	if C.dword_5d4594_1193672 != 0 && a1 != nil {
		r.DrawImageAt(a1, pos)
	}
	return 1
}

//export nox_draw_setCutSize_476700
func nox_draw_setCutSize_476700(cutPerc C.int, a2 C.int) {
	vp := getViewport()
	bsz := noxPixBuffer.img.Size()
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

func nox_client_drawXxx_444AC0(w, h int, flags int) error {
	//int v5;             // eax
	//bool v6;            // zf
	//unsigned char v7 = 0; // al
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
	if v7&4 != 0 {
		panic("unreachable")
	}
	if err := resetRenderer(types.Size{W: v8, H: h}, true); err != nil {
		return err
	}
	return nil
}

func sub_48B800(a1 uint32) {
	p, pfree := alloc.Uints32(3)
	defer pfree()
	C.sub_434480(C.int(a1), (*C.int)(unsafe.Pointer(&p[0])), (*C.int)(unsafe.Pointer(&p[1])), (*C.int)(unsafe.Pointer(&p[2])))
	sub_48B6B0(byte(p[0]), byte(p[1]), byte(p[2]))
}

func sub_48B6B0(a1, a2, a3 byte) {
	C.sub_433CD0(C.uchar(a1), C.uchar(a2), C.uchar(a3))
}

func sub_48B590() (a1 *Image, pos types.Point) {
	return asImageP(C.dword_5d4594_1193624), types.Point{X: int(C.dword_5d4594_1193648), Y: int(C.dword_5d4594_1193524)}
}

func sub_48B680(a1 int) {
	p := noxrend.Data()
	if a1 != int(p.field_15) {
		p.field_14 = C.uint(a1)
		C.sub_48BD90(1)
	}
}

func nox_video_cursorDrawImpl_477A30(r *NoxRender, inp *input.Handler, pos types.Point) {
	v18 := memmap.Uint32(0x973F18, 68)
	pos = pos.Sub(types.Point{X: 64, Y: 64})
	*memmap.PtrUint32(0x973F18, 68) = 0
	C.dword_5d4594_3798728 = 1
	C.dword_5d4594_1097212 = C.int(pos.X)
	C.dword_5d4594_1097216 = C.int(pos.Y)
	if gameFrame()&1 != 0 {
		*memmap.PtrUint32(0x5D4594, 1097288)++
	}
	r.SetTextColor(memmap.Uint32(0x5D4594, 2589772))
	fh := noxrend.FontHeight(nil)
	if C.nox_xxx_guiSpell_460650() != 0 || C.sub_4611A0() != 0 {
		r.nox_video_drawAnimatedImageOrCursorAt(noxCursors.Target, pos)
		C.dword_5d4594_3798728 = 0
		C.nox_xxx_cursorTypePrev_587000_151528 = 5
		*memmap.PtrUint32(0x973F18, 68) = v18
		return
	}

	if C.nox_client_mouseCursorType != C.nox_xxx_cursorTypePrev_587000_151528 && C.nox_client_mouseCursorType != 14 {
		sub_48B680(0)
	}
	switch typ := int(C.nox_client_mouseCursorType); typ {
	case 1:
		str := strMan.GetStringInFile("GRAB", "C:\\NoxPost\\src\\Client\\Gui\\guicurs.c")
		r.DrawString(nil, str, pos.Add(types.Point{X: 54, Y: 64 - fh}))
		r.nox_video_drawAnimatedImageOrCursorAt(noxCursors.Grab, pos)
	case 2:
		str := strMan.GetStringInFile("PICKUP", "C:\\NoxPost\\src\\Client\\Gui\\guicurs.c")
		r.DrawString(nil, str, pos.Add(types.Point{X: 49, Y: 64 + fh}))
		r.nox_video_drawAnimatedImageOrCursorAt(noxCursors.Pickup, pos)
		dword_5d4594_1097208 = -2 * fh
	case 3:
		str := strMan.GetStringInFile("SHOPKEEPER", "C:\\NoxPost\\src\\Client\\Gui\\guicurs.c")
		r.DrawString(nil, str, pos.Add(types.Point{X: 39, Y: 64 - fh}))
		r.nox_video_drawAnimatedImageOrCursorAt(noxCursors.Trade, pos)
	case 4:
		str := strMan.GetStringInFile("TALK", "C:\\NoxPost\\src\\Client\\Gui\\guicurs.c")
		r.DrawString(nil, str, pos.Add(types.Point{X: 49, Y: 64 - fh}))
		r.nox_video_drawAnimatedImageOrCursorAt(noxCursors.Talk, pos)
	case 6, 7:
		str := strMan.GetStringInFile("IDENTIFY", "C:\\NoxPost\\src\\Client\\Gui\\guicurs.c")
		r.DrawString(nil, str, pos.Add(types.Point{X: 49, Y: +88}))
		if typ == 6 {
			r.nox_video_drawAnimatedImageOrCursorAt(noxCursors.Identify, pos)
		} else {
			r.nox_video_drawAnimatedImageOrCursorAt(noxCursors.IdentifyNo, pos)
		}
	case 8:
		str := strMan.GetStringInFile("REPAIR", "C:\\NoxPost\\src\\Client\\Gui\\guicurs.c")
		r.DrawString(nil, str, pos.Add(types.Point{X: 49, Y: 64 - fh}))
		r.nox_video_drawAnimatedImageOrCursorAt(noxCursors.Repair, pos)
		dword_5d4594_1097208 = 2*fh + 4
	case 9:
		r.nox_video_drawAnimatedImageOrCursorAt(noxCursors.CreateGame, pos)
	case 10:
		r.nox_video_drawAnimatedImageOrCursorAt(noxCursors.Busy, pos)
	case 11:
		r.nox_video_drawAnimatedImageOrCursorAt(noxCursors.Buy, pos)
	case 12:
		r.nox_video_drawAnimatedImageOrCursorAt(noxCursors.Sell, pos)
	case 13:
		str := strMan.GetStringInFile("USE", "C:\\NoxPost\\src\\Client\\Gui\\guicurs.c")
		r.DrawString(nil, str, pos.Add(types.Point{X: 54, Y: 64 + fh}))
		r.nox_video_drawAnimatedImageOrCursorAt(noxCursors.Use, pos)
		dword_5d4594_1097208 = -2 * fh
	case 14:
		mpos := inp.GetMousePos()
		v19 := types.Pointf{
			X: float32(mpos.X - nox_win_width/2),
			Y: float32(mpos.Y - nox_win_height/2),
		}
		v15 := nox_xxx_math_509ED0(v19) / 8
		if v19.X*v19.X+v19.Y*v19.Y > 100*100 || memmap.Uint32(0x852978, 8) != 0 && *(*uint32)(unsafe.Add(*memmap.PtrPtr(0x852978, 8), 276)) == 6 {
			v15 += 32
		}
		if v16 := nox_xxx_spriteGetMB_476F80(); v16 != nil {
			sub_48B680(1)
			if v16.Flags28()&6 == 0 || C.sub_495A80(C.int(v16.Field32())) != 0 {
				sub_48B800(memmap.Uint32(0x85B3FC, 980))
			} else {
				sub_48B800(memmap.Uint32(0x85B3FC, 940))
			}
		} else {
			sub_48B680(0)
		}
		C.sub_4BE710(C.int(uintptr(unsafe.Pointer(noxCursors.Move.C()))), C.int(pos.X), C.int(pos.Y), C.int(v15))
		sub_4345F0(0)
	case 15:
		r.nox_video_drawAnimatedImageOrCursorAt(noxCursors.PickupFar, pos)
		dword_5d4594_1097208 = -2 * fh
	case 16:
		r.nox_video_drawAnimatedImageOrCursorAt(noxCursors.Caution, pos)
		dword_5d4594_1097208 = -fh
	default:
		r.nox_video_drawAnimatedImageOrCursorAt(noxCursors.Select, pos)
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

func nox_client_drawCursorAndTooltips_477830(r *NoxRender, inp *input.Handler) {
	if noxCursors.Select == nil {
		nox_xxx_cursorLoadAll_477710()
	}
	mpos := inp.GetMousePos()
	vpp, freeVp := alloc.Malloc(unsafe.Sizeof(C.nox_draw_viewport_t{}))
	defer freeVp()
	vp := asViewport((*C.nox_draw_viewport_t)(vpp))
	vp.x1 = 0
	vp.y1 = 0
	vp.x2 = C.int(nox_win_width)
	vp.y2 = C.int(nox_win_height)
	vp.field_4 = 0
	vp.field_5 = 0
	vp.width = C.int(nox_win_width)
	vp.height = C.int(nox_win_height)
	dword_5d4594_1097204 = 0
	dword_5d4594_1097208 = noxrend.FontHeight(nil) + 4
	if nox_client_itemDragnDrop_1097188 != nil { // Dragging item
		nox_client_itemDragnDrop_1097188.SetPos(mpos)
		nox_client_itemDragnDrop_1097188.DrawFunc(vp)
	}
	if nox_client_spellDragnDrop_1097192 != 0 { // Player is dragging spell or ability
		pl := getPlayerByID(clientPlayerNetCode())
		if pl == nil || pl.PlayerClass() != player.Warrior {
			v2 := C.nox_xxx_spellIcon_424A90(C.int(nox_client_spellDragnDrop_1097192)) // Spell icon
			if v2 != nil {
				r.DrawImageAt(asImageP(unsafe.Pointer(v2)), mpos.Sub(types.Point{X: 15, Y: 15}))
			}
		} else {
			v2 := C.nox_xxx_spellGetAbilityIcon_425310(C.int(nox_client_spellDragnDrop_1097192), 0) // Ability icon
			if v2 != nil {
				r.DrawImageAt(asImageP(unsafe.Pointer(v2)), mpos.Sub(types.Point{X: 15, Y: 15}))
			}
		}
	}
	nox_video_cursorDrawImpl_477A30(r, inp, mpos)
	if str := GoWStringP(memmap.PtrOff(0x5D4594, 1096676)); str != "" && C.nox_client_showTooltips_80840 == 1 {
		sz := r.GetStringSizeWrapped(nil, str, 0)
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
		r.DrawRectFilledAlpha(px, py, sz.W, sz.H)
		r.SetTextColor(memmap.Uint32(0x5D4594, 2589772))
		r.DrawStringWrapped(nil, str, image.Rect(px+2, py+2, px+2, py+2))
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
	if C.dword_5d4594_3799468 != 0 {
		vp := getViewport()
		if C.dword_5d4594_1097212 < vp.x1 || C.dword_5d4594_1097212+64 >= vp.x2 || C.dword_5d4594_1097216 < vp.y1 || C.dword_5d4594_1097216+64 >= vp.y2 {
			noxrend.SetColor2(memmap.Uint32(0x85B3FC, 952))
			noxrend.DrawRectFilledOpaque(int(C.dword_5d4594_1097212)+32, int(C.dword_5d4594_1097216)+32, 64, 64)
		}
	}
}

//export sub_444C50
func sub_444C50() {
	if C.dword_5d4594_823776 != 0 {
		nox_video_stopCursorDrawThread_48B350()
		nox_free_pixbuffers_486110()
		nox_draw_freeColorTables_433C20()
		C.nox_client_initFade_44D9D0()
		noxrend.freeParticles()
		C.sub_4AF950()
		sub_4AE540()
		nox_xxx_FontDestroy_43F2E0()
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
