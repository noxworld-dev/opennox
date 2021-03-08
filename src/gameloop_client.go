//+build !server

package main

/*
#include <fenv.h>

#include "proto.h"
#include "common__system__team.h"
#include "common__system__gamedisk.h"
#include "client__system__gameloop.h"

extern unsigned int dword_5d4594_1556112;
extern unsigned int dword_5d4594_815132;
extern int nox_win_width;
extern int nox_win_height;
*/
import "C"
import (
	"math"
	"unsafe"

	"nox/common/alloc"
	"nox/common/memmap"
)

func mainloopDrawAndPresent() {
	C.sub_437180()
	if C.dword_5d4594_1556112 == 0 {
		C.nox_gui_draw() // Draw game windows
	}
	mainloopDrawSparks()
	if !getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) || getEngineFlag(NOX_ENGINE_FLAG_9) || C.dword_5d4594_815132 != 0 {
		C.nox_client_drawCursorAndTooltips_477830() // Draw cursor
	}
	C.sub_44D9F0(1)
	if C.sub_409F40(4096) == 0 { // CheckRuleFlags and smth
		C.nox_xxx_screenshot_46D830()
	}
	if !getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) || getEngineFlag(NOX_ENGINE_FLAG_9) || C.dword_5d4594_815132 != 0 {
		// C.nox_xxx_directDrawBlitMB_48A220() // does nothing
		nox_video_callCopyBackBuffer_4AD170()
		callPresent()
	}
}

func mainloopDrawSparks() {
	if C.dword_5d4594_815132 != 0 {
		v28 := alloc.Calloc(10, 4)
		v28s := asU32Slice(v28, 10)
		v28s[0] = 0
		v28s[1] = 0
		v28s[2] = uint32(C.nox_win_width)
		v28s[3] = uint32(C.nox_win_height)
		v28s[8] = uint32(C.nox_win_width)
		v28s[9] = uint32(C.nox_win_height)
		C.nox_client_screenParticlesDraw_431720((*C.int)(v28))
		alloc.Free(v28)
	} else {
		v25 := C.sub_437250()
		C.nox_client_screenParticlesDraw_431720((*C.int)(unsafe.Pointer(v25)))
	}
}

func generateMouseSparks() {
	if memmap.Uint32(0x5D4594, 816408) != 0 {
		return
	}

	mouse := C.nox_client_getMouseState_4309F0()
	// emit sparks when passing a certain distance
	const distanceSparks = 0.25
	dx := int(mouse.pos.x) - int(memmap.Uint32(0x5D4594, 816420))
	dy := int(mouse.pos.y) - int(memmap.Uint32(0x5D4594, 816424))
	r2 := dx*dx + dy*dy
	if memmap.Uint32(0x5D4594, 816428) != 0 {
		cnt := (int)(math.Sqrt(float64(r2)) * distanceSparks)
		for i := cnt; i > 0; i-- {
			v6 := randomIntMinMax(0, 100)
			v7 := int(memmap.Uint32(0x5D4594, 816420)) + dx*v6/100
			v9 := int(memmap.Uint32(0x5D4594, 816424)) + dy*v6/100
			v23 := randomIntMinMax(2, 5)
			v22 := randomIntMinMax(2, 5)
			v21 := randomIntMinMax(-7, 2)
			v10 := randomIntMinMax(-5, 5)
			C.nox_client_newScreenParticle_431540(4, C.int(v7), C.int(v9), C.int(v10), C.int(v21), 1, C.char(v22), C.char(v23), 2, 1)
		}
		if r2 < 10 {
			*memmap.PtrUint32(0x5D4594, 816428) = 0
		}
		*memmap.PtrUint32(0x5D4594, 816420) = uint32(mouse.pos.x)
		*memmap.PtrUint32(0x5D4594, 816424) = uint32(mouse.pos.y)
	} else if r2 > 64 {
		*memmap.PtrUint32(0x5D4594, 816428) = 1
	}
	// explode with sparks when clicking
	const explosionSparks = 75
	if mouse.btn[C.NOX_MOUSE_LEFT].pressed == 1 {
		randomIntMinMax(0, 2)
		if memmap.Uint32(0x5D4594, 816416) == 0 {
			*memmap.PtrUint32(0x5D4594, 816416) = 1
			C.nox_xxx_clientPlaySoundSpecial_452D80(924, 100)
			for i := explosionSparks; i > 0; i-- {
				v12 := randomIntMinMax(0, 255)
				v13 := randomIntMinMax(6, 12)
				v14 := v13 * int(memmap.Int32(0x587000, 8*uintptr(v12)+192088))
				v15 := v13*int(memmap.Int32(0x587000, 8*uintptr(v12)+192092))/16 - 6
				v24 := randomIntMinMax(2, 5)
				v16 := randomIntMinMax(2, 5)
				C.nox_client_newScreenParticle_431540(4, C.int(v14/16+int(mouse.pos.x)), C.int(int(mouse.pos.y)+v15), C.int(v14/16), C.int(v15), 1, C.char(v16), C.char(v24), 2, 1)
			}
		}
	} else {
		*memmap.PtrUint32(0x5D4594, 816416) = 0
	}
}
