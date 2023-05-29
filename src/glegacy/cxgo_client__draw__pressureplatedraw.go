package legacy

import "unsafe"

func nox_thing_pressure_plate_draw(a1 *uint32, dr *nox_drawable) int32 {
	var (
		v2  int32
		v4  int32
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v10 int32
		v11 int32
		v12 int32
		v13 float32
		v14 int32
		v15 int32
		v16 int32
		v17 int32
		v18 int32
		v19 int32
		v20 int32
	)
	v2 = int32(uintptr(unsafe.Pointer(dr)))
	if int32(*(*uint8)(unsafe.Pointer(uintptr(v2 + 432)))) == 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(v2 + 433)))) == 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(v2 + 434)))) == 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(v2 + 435)))) == 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(v2 + 436)))) == 0 && int32(*(*uint8)(unsafe.Pointer(uintptr(v2 + 437)))) == 0 {
		return 1
	}
	v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)) - *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*5)))
	v13 = *(*float32)(unsafe.Pointer(uintptr(v2 + 64)))
	v5 = int32(*a1 - *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)))
	v20 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)) - *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*5)))
	v18 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 12))) + uint32(v5) + uint32(nox_float2int(v13)))
	v6 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 16))) + uint32(v4) + uint32(nox_float2int(*(*float32)(unsafe.Pointer(uintptr(v2 + 68))))))
	v19 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 12))) + uint32(v5) + uint32(nox_float2int(*(*float32)(unsafe.Pointer(uintptr(v2 + 88))))))
	v7 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 16))) + uint32(v20) + uint32(nox_float2int(*(*float32)(unsafe.Pointer(uintptr(v2 + 92))))))
	v16 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 12))) + uint32(v5) + uint32(nox_float2int(*(*float32)(unsafe.Pointer(uintptr(v2 + 72))))))
	v17 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 16))) + uint32(v20) + uint32(nox_float2int(*(*float32)(unsafe.Pointer(uintptr(v2 + 76))))))
	v14 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 12))) + uint32(v5) + uint32(nox_float2int(*(*float32)(unsafe.Pointer(uintptr(v2 + 80))))))
	v8 = nox_float2int(*(*float32)(unsafe.Pointer(uintptr(v2 + 84))))
	v9 = v20
	v10 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + 16))))
	v11 = v10 + v20 + v8
	v12 = 0
	v15 = v11
	for {
		if v12 != 0 {
			*((*uint8)(unsafe.Pointer(&v9))) = *(*uint8)(unsafe.Pointer(uintptr(v2 + 437)))
			*((*uint8)(unsafe.Pointer(&v11))) = *(*uint8)(unsafe.Pointer(uintptr(v2 + 436)))
			*((*uint8)(unsafe.Pointer(&v10))) = *(*uint8)(unsafe.Pointer(uintptr(v2 + 435)))
		} else {
			*((*uint8)(unsafe.Pointer(&v9))) = *(*uint8)(unsafe.Pointer(uintptr(v2 + 434)))
			*((*uint8)(unsafe.Pointer(&v11))) = *(*uint8)(unsafe.Pointer(uintptr(v2 + 433)))
			*((*uint8)(unsafe.Pointer(&v10))) = *(*uint8)(unsafe.Pointer(uintptr(v2 + 432)))
		}
		nox_set_color_rgb_434430(v10, v11, v9)
		nox_client_drawAddPoint_49F500(v12+v18, v6)
		nox_client_drawAddPoint_49F500(v12+v14, v15)
		nox_client_drawLineFromPoints_49E4B0()
		nox_client_drawAddPoint_49F500(v12+v19, v7)
		nox_client_drawAddPoint_49F500(v12+v14, v15)
		nox_client_drawLineFromPoints_49E4B0()
		nox_client_drawAddPoint_49F500(v12+v18, v6)
		nox_client_drawAddPoint_49F500(v12+v16, v17)
		nox_client_drawLineFromPoints_49E4B0()
		nox_client_drawAddPoint_49F500(v12+v19, v7)
		nox_client_drawAddPoint_49F500(v12+v16, v17)
		v11 = nox_client_drawLineFromPoints_49E4B0()
		v12++
		if v12 >= 2 {
			break
		}
	}
	return 1
}
