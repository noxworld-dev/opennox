package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func nox_thing_summon_effect_draw(a1 *int32, dr *nox_drawable) int32 {
	var (
		v2     *uint32
		v3     int32
		v4     int32
		v5     int32
		v6     int32
		v7     int32
		v8     int32
		result int32
		v10    uint32
		v11    *uint8
		v12    uint32
		v13    int32
		v14    int32
		v15    int32
		v16    int64
		v17    int32
		v18    int32
		a2     *uint32 = &dr.field_0
	)
	v2 = a2
	v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*3)))
	v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*4)))
	v5 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*76)))
	v18 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*77)))
	v6 = int32(dword_5d4594_1313740)
	v15 = v3
	v17 = v4
	if dword_5d4594_1313740 == 0 {
		v6 = nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("BlueSpark"))
		dword_5d4594_1313740 = uint32(v6)
	}
	v7 = int32(gameFrame() - *(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*79)))
	v8 = int32(*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v2))), unsafe.Sizeof(uint16(0))*218))))
	if uint32(v7) < uint32(uint16(int16(v8))) {
		if v7 >= v8-1 {
			nox_xxx_makePointFxCli_499610(v6, 50, 1000, 30, int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*3))), int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*4))))
		}
		nox_thing_animate_draw((*uint32)(unsafe.Pointer(a1)), dr)
		v10 = 0
		v11 = (*uint8)(memmap.PtrOff(0x587000, 192092))
		for {
			if v10 >= uint32(*(*uint8)(unsafe.Pointer(uintptr(v5 + 8)))) {
				v10 = 0
			}
			v12 = (v10 + gameFrame() + *(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*32))) / (uint32(*(*uint8)(unsafe.Pointer(uintptr(v5 + 9)))) + 1)
			*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*77)) = v12
			if v12 >= uint32(*(*uint8)(unsafe.Pointer(uintptr(v5 + 8)))) {
				*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*77)) = v12 % uint32(*(*uint8)(unsafe.Pointer(uintptr(v5 + 8))))
			}
			*(*uint32)(unsafe.Pointer(uintptr(v5 + 12))) = 5
			v13 = int32(uint32(v15) + *((*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(v11))), -int(4*1))))*2)
			*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*3)) = uint32(v13)
			v14 = int32(uint32(v17) + *(*uint32)(unsafe.Pointer(v11))*2)
			*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*4)) = uint32(v14)
			if v13 >= 0 && v13 < 5888 && v14 >= 0 && v14 < 5888 {
				nox_thing_animate_draw((*uint32)(unsafe.Pointer(a1)), dr)
			}
			v11 = (*uint8)(unsafe.Add(unsafe.Pointer(v11), 80))
			v10++
			if int32(uintptr(unsafe.Pointer(v11))) >= int32(uintptr(memmap.PtrOff(0x587000, 194140))) {
				break
			}
		}
		*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*3)) = uint32(v15)
		*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*4)) = uint32(v17)
		*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*77)) = uint32(v18)
		*(*uint32)(unsafe.Pointer(uintptr(v5 + 12))) = 2
		nox_client_drawEnableAlpha_434560(1)
		v16 = int64(gameFrame())
		*(*uint32)(unsafe.Add(unsafe.Pointer((*uint32)(unsafe.Pointer(&v16))), 4*0)) = *(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*79))
		nox_client_drawSetAlpha_434580(uint8(int8(int64((float64(gameFrame()) - float64(v16)) / float64(*((*uint16)(unsafe.Add(unsafe.Pointer((*uint16)(unsafe.Pointer(v2))), unsafe.Sizeof(uint16(0))*218)))) * 255.0))))
		asFuncT[func(*int32, uint32)](unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*108))+300)))(a1, *(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*108)))
		nox_client_drawEnableAlpha_434560(0)
		result = 1
	} else {
		nox_xxx_spriteDelete_45A4B0((*nox_drawable)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*108))))))
		nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr)
		result = 0
	}
	return result
}
