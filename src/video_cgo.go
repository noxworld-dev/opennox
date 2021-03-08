package main

/*
#include "client__video__draw_common.h"
*/
import "C"
import (
	"fmt"

	"nox/common/memmap"
	"nox/common/types"
)

var (
	noxBackBufCopyFunc func()
)

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

//export nox_video_setBackBufferCopyFunc_4AD100
func nox_video_setBackBufferCopyFunc_4AD100() C.int {
	if C.nox_video_renderTargetFlags&0x40 != 0 {
		noxBackBufCopyFunc = nox_video_copyBackBuffer2_4AD180
		panic("not implemented")
	} else {
		nox_video_setBackBufferCopyFunc2_4AD150()
	}
	*memmap.PtrUint32(0x5D4594, 3798652) = 0
	return 1
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

//export nox_xxx_GfxInit_444930
func nox_xxx_GfxInit_444930(w, h, depth, flags C.int) C.int {
	C.dword_5d4594_823776 = 0
	C.ptr_5D4594_3799572 = &C.obj_5D4594_3799660
	result := C.nox_client_drawInitAll_4449D0(w, h, depth, flags)
	fmt.Printf("nox_client_drawInitAll_4449D0: %d\n", int(result))
	if result == 0 {
		return 0
	}
	C.ptr_5D4594_3799572 = &C.obj_5D4594_3800716
	C.obj_5D4594_3800716 = C.obj_5D4594_3799660
	if C.nox_video_renderTargetFlags&0x200 != 0 {
		windowMinimize()
	}
	C.dword_5d4594_823776 = 1
	C.dword_5d4594_823772++
	return 1
}

func nox_video_copyBackBuffer2_4AD180() {
	panic("not implemented")
}
