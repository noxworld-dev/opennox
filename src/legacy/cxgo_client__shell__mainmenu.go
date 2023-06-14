package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func Sub_4A22A0(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1    = int32(uintptr(win.C()))
		a2    = (*int32)(draw.C())
		v2    int32
		v3    int32
		v4    *uint8
		v5    int32
		v6    int32
		v7    bool
		v8    int32
		v9    int32
		v10   *uint8
		v11   int32
		xLeft int32
		yTop  int32
	)
	nox_xxx_bookGet_430B40_get_mouse_prev_seq()
	nox_client_wndGetPosition_46AA60((*gui.Window)(unsafe.Pointer(uintptr(a1))), (*uint32)(unsafe.Pointer(&xLeft)), (*uint32)(unsafe.Pointer(&yTop)))
	if int32(int8(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 4)))) >= 0 {
		if uint32(*(*int32)(unsafe.Add(unsafe.Pointer(a2), 4*5))) != 0x80000000 {
			nox_client_drawSetColor_434460(*(*int32)(unsafe.Add(unsafe.Pointer(a2), 4*5)))
			nox_client_drawRectFilledOpaque_49CE30(xLeft, yTop, int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 8))), int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 12))))
		}
	} else {
		v2 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 100)))
		xLeft += int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 96)))
		v3 = v2 + yTop
		*((*uint8)(unsafe.Pointer(&v2))) = *(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 36))
		yTop = v3
		if v2&2 != 0 {
			nox_client_drawImageAt_47D2C0((*nox_video_bag_image_t)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a2), 4*10))), xLeft, v3)
		} else {
			nox_client_drawImageAt_47D2C0((*nox_video_bag_image_t)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a2), 4*6))), xLeft, v3)
		}
	}
	if *memmap.PtrUint32(0x587000, 168836) != 0 {
		v4 = (*uint8)(memmap.PtrOff(0x587000, 168868))
		for {
			v5 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*2))))
			if v5 != 0 {
				*((*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*2))) = uint32(v5 - 1)
			}
			v6 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*1))))
			if v6 != 0 {
				*((*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*1))) = uint32(v6 - 1)
				*((*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*2))) = uint32(nox_common_randomIntMinMax_415FF0(60, 120, internCStr("C:\\NoxPost\\src\\Client\\shell\\mainmenu.c"), 180))
			}
			v7 = func() uint32 {
				p := (*uint32)(unsafe.Pointer(v4))
				x := *p
				*p--
				return x
			}() == 1
			v8 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v4), -int(4*5)))))
			if v7 {
				if v8 != 0 {
					*((*uint32)(unsafe.Add(unsafe.Pointer(v4), -int(4*5)))) = 0
					*(*uint32)(unsafe.Pointer(v4)) = uint32(nox_common_randomIntMinMax_415FF0(int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v4), -int(4*4))))), int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v4), -int(4*3))))), internCStr("C:\\NoxPost\\src\\Client\\shell\\mainmenu.c"), 211))
					*((*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*2))) = uint32(nox_common_randomIntMinMax_415FF0(60, 90, internCStr("C:\\NoxPost\\src\\Client\\shell\\mainmenu.c"), 214))
				} else {
					*((*uint32)(unsafe.Add(unsafe.Pointer(v4), -int(4*5)))) = 1
					*(*uint32)(unsafe.Pointer(v4)) = uint32(nox_common_randomIntMinMax_415FF0(int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v4), -int(4*2))))), int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v4), -int(4*1))))), internCStr("C:\\NoxPost\\src\\Client\\shell\\mainmenu.c"), 199))
				}
			} else if v8 == 0 && *((*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*2))) == 0 && *((*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*1))) == 0 && nox_common_randomIntMinMax_415FF0(0, 100, internCStr("C:\\NoxPost\\src\\Client\\shell\\mainmenu.c"), 228) > 75 {
				*((*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*1))) = uint32(nox_common_randomIntMinMax_415FF0(4, 8, internCStr("C:\\NoxPost\\src\\Client\\shell\\mainmenu.c"), 229))
			}
			v9 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*4))))
			v4 = (*uint8)(unsafe.Add(unsafe.Pointer(v4), 48))
			if v9 == 0 {
				break
			}
		}
	}
	if *memmap.PtrUint32(0x587000, 168832) != 0 {
		v10 = (*uint8)(memmap.PtrOff(0x587000, 168872))
		for {
			if *((*uint32)(unsafe.Add(unsafe.Pointer(v10), -int(4*6)))) == 0 && *(*uint32)(unsafe.Pointer(v10)) == 0 {
				nox_client_drawImageAt_47D2C0((*nox_video_bag_image_t)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer(v10), -int(4*9))))))), int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v10), -int(4*8))))), int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v10), -int(4*7))))))
			}
			v11 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v10), 4*2))))
			v10 = (*uint8)(unsafe.Add(unsafe.Pointer(v10), 48))
			if v11 == 0 {
				break
			}
		}
	}
	return 1
}
