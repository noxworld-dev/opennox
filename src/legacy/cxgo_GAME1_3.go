package legacy

import (
	"math"
	"unsafe"

	"github.com/gotranspile/cxgo/runtime/libc"
	noxcolor "github.com/noxworld-dev/opennox-lib/color"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/internal/binfile"
	"github.com/noxworld-dev/opennox/v1/legacy/client/audio/ail"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
)

var dword_5d4594_830236 unsafe.Pointer
var dword_5d4594_830232 unsafe.Pointer
var audioStream1 ail.Stream
var audioDriver ail.Driver
var dword_5d4594_816092 uint32

func nox_client_xxx_switchChatMap_43B510() {
	var (
		v0     int16
		result *byte
		v2     *byte
		v5     int16
		v6     int32
		v7     [80]byte
	)
	nox_client_gui_set_flag_815132(0)
	nox_xxx_setGameFlags_40A4D0(5)
	nox_xxx_setMouseBounds_430A70(0, nox_win_width-1, 0, nox_win_height-1)
	v6 = int32(*memmap.PtrUint32(0x5D4594, 814916))
	if false {
		v0 = int16(int32(*memmap.PtrUint16(0x5D4594, 814916)) - int32(*memmap.PtrUint16(0x587000, uintptr(dword_587000_87412)*8+87528)))
		*(*uint16)(unsafe.Add(unsafe.Pointer(&v6), unsafe.Sizeof(uint16(0))*1)) -= *memmap.PtrUint16(0x587000, uintptr(dword_587000_87412)*8+87530)
		*(*uint16)(unsafe.Add(unsafe.Pointer(&v6), unsafe.Sizeof(uint16(0))*0)) = uint16(v0)
	}
	libc.StrCpy(&v7[0], nox_client_getChatMap_49FF40((*int16)(unsafe.Pointer(&v6))))
	if libc.StrChr(&v7[0], '.') == nil {
		sub_409B50(&v7[0])
		v2 = &v7[libc.StrLen(&v7[0])+1]
		*(*uint32)(unsafe.Pointer(func() *byte {
			p := &v2
			*p = (*byte)(unsafe.Add(unsafe.Pointer(*p), -1))
			return *p
		}())) = *memmap.PtrUint32(0x587000, 90856)
		*(*byte)(unsafe.Add(unsafe.Pointer(v2), 4)) = 0
		if !nox_common_getEngineFlag(NOX_ENGINE_FLAG_REPLAY_READ) {
			nox_xxx_gameSetMapPath_409D70(&v7[0])
		}
		nox_common_gameFlags_unset_40A540(55280)
		nox_xxx_setGameFlags_40A4D0(128)
		result = sub_4165D0(0)
		v5 = int16(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(result), unsafe.Sizeof(uint16(0))*26))) & 0x280F)
		*(*uint8)(unsafe.Pointer(&v5)) = *(*byte)(unsafe.Add(unsafe.Pointer(result), 52))&0xF | 0x80
		*(*uint16)(unsafe.Add(unsafe.Pointer(result), unsafe.Sizeof(uint16(0))*26)) = uint16(v5)
	}
}
func sub_43B6D0() int32 {
	return int32(dword_5d4594_815044)
}
func sub_43BC10(a1 *wchar2_t, a2 uint8) *uint16 {
	var (
		a1_len       uint32    = nox_wcslen(a1)
		a1_last_char *wchar2_t = (*wchar2_t)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(wchar2_t(0))*uintptr(a1_len)))
		a1v          int32     = 0
	)
	for {
		nox_xxx_drawGetStringSize_43F840(nil, a1, &a1v, nil, 0)
		*a1_last_char = 0
		a1_last_char = (*wchar2_t)(unsafe.Add(unsafe.Pointer(a1_last_char), -int(unsafe.Sizeof(wchar2_t(0))*1)))
		if a1v+5 <= int32(a2) {
			break
		}
	}
	return a1
}
func nox_sprintAddrPort_43BC80(addr *byte, port uint16, dst *byte) int32 {
	return nox_sprintf(dst, internCStr("%s:%d"), addr, port)
}
func sub_43BDB0() int32 {
	return int32(*memmap.PtrUint32(0x5D4594, 815092))
}
func sub_43C650() int32 {
	var (
		v0     int64
		v1     uint32
		v2     int32
		result int32
	)
	v0 = int64(nox_platform_get_ticks())
	v1 = *memmap.PtrUint32(0x5D4594, 815756)
	if *memmap.PtrUint64(0x5D4594, 815740) != 0 {
		v2 = int32(uint32(bool2int32(uint32(int32(v0)) < uint32(*memmap.PtrInt32(0x5D4594, 815740)))) + *memmap.PtrUint32(0x5D4594, 815744))
		*memmap.PtrUint32(0x5D4594, uintptr(*memmap.PtrUint32(0x5D4594, 815756))*8+815220) = uint32(int32(v0 - int64(*memmap.PtrUint32(0x5D4594, 815740))))
		*memmap.PtrUint32(0x5D4594, uintptr(v1)*8+815224) = (*(*uint32)(unsafe.Add(unsafe.Pointer(&v0), 4*1))) - uint32(v2)
	} else {
		*memmap.PtrUint32(0x5D4594, uintptr(*memmap.PtrUint32(0x5D4594, 815756))*8+815220) = uint32(int32(v0))
		*memmap.PtrUint32(0x5D4594, uintptr(v1)*8+815224) = *(*uint32)(unsafe.Add(unsafe.Pointer(&v0), 4*1))
	}
	*memmap.PtrUint64(0x5D4594, 815756) = ((((uint64(*memmap.PtrUint32(0x5D4594, 815760))) << 32) | uint64(v1)) + 1) % 0x3C
	result = int32(dword_5d4594_815748 + 1)
	*memmap.PtrUint64(0x5D4594, 815740) = uint64(v0)
	dword_5d4594_815748++
	return result
}
func sub_43C7A0(a1 int32) int32 {
	var result int32
	result = a1
	*memmap.PtrUint32(0x587000, 91876) = uint32(a1)
	return result
}
func sub_43CEB0() {
	var (
		v1 uint32
		v2 uint32
		v3 uint32
		v4 uint64 = 0
		v5 uint32
		v6 int32
		v7 uint32
		v9 uint32
		v0 int32 = int32(dword_5d4594_815748)
	)
	if dword_5d4594_815748 >= 60 {
		v0 = 60
	}
	v1 = 0
	v2 = 0
	v3 = 0
	if v0 == 0 || v0 <= 10 {
		*memmap.PtrUint32(0x587000, 91884) = 0
		*memmap.PtrUint32(0x587000, 91880) = 33
		return
	}
	v5 = 0
	v9 = uint32(v0)
	for {
		for {
			v6 = int32(*memmap.PtrUint32(0x5D4594, uintptr(v5)*8+815220) + v2)
			v3 = uint32(((((uint64(*memmap.PtrUint32(0x5D4594, uintptr(v5)*8+815224))) << 32) | uint64(*memmap.PtrUint32(0x5D4594, uintptr(v5)*8+815220))) + (((uint64(v3)) << 32) | uint64(v2))) >> 32)
			v2 += *memmap.PtrUint32(0x5D4594, uintptr(v5)*8+815220)
			v7 = v5 + 1
			v1 = uint32(((((uint64(v1)) << 32) | uint64(func() uint32 {
				p := &v5
				x := *p
				*p++
				return x
			}())) + 1) >> 32)
			if v1 >= (*(*uint32)(unsafe.Add(unsafe.Pointer(&v4), 4*1))) {
				break
			}
		}
		*(*uint32)(unsafe.Add(unsafe.Pointer(&v4), 4*0)) = v9
		if v1 > (*(*uint32)(unsafe.Add(unsafe.Pointer(&v4), 4*1))) || v7 >= v9 {
			break
		}
	}
	var v0a int64 = int64((((uint64(v3)) << 32) | uint64(uint32(v6))) / v4)
	*memmap.PtrUint64(0x587000, 91880) = uint64(v0a)
}
func sub_43D2D0() {
	var v1 int32
	if dword_5d4594_816340 != 0 {
		if audioStream1 != 0 {
			sub_486520(memmap.PtrOff(0x5D4594, 816244))
			sub_486520(memmap.PtrOff(0x5D4594, 816148))
			v1 = int32(*(*uint32)(unsafe.Add(dword_587000_81128, 4)) >> 16)
			if uint32(v1) == *memmap.PtrUint32(0x587000, 93168) {
				if (uint64(nox_platform_get_ticks()) - *memmap.PtrUint64(0x5D4594, 816380)) > 0x32 {
					*(*uint32)(dword_587000_81128) &= 0xFFFFFFFD
					*(*uint32)(unsafe.Add(dword_587000_81128, 32)) &= 0xFFFFFFFD
					*(*uint32)(unsafe.Add(dword_587000_81128, 64)) &= 0xFFFFFFFD
				}
			} else {
				*memmap.PtrUint64(0x5D4594, 816380) = uint64(nox_platform_get_ticks())
				*memmap.PtrUint32(0x587000, 93168) = uint32(v1)
			}
			if audioStream1 != 0 {
				if int32(*(*uint8)(dword_587000_81128))&2 != 0 || int32(*memmap.PtrUint8(0x5D4594, 816148))&2 != 0 || int32(*memmap.PtrUint8(0x5D4594, 816244))&2 != 0 {
					sub_43D3C0(audioStream1, *memmap.PtrInt32(0x5D4594, 816096))
				}
			}
		}
	}
}
func sub_43D3C0(a1 ail.Stream, a2 int32) {
	var v2 uint32
	if a1 != 0 {
		v2 = (*(*uint32)(unsafe.Add(dword_587000_81128, 4)) >> 16) * ((uint32(*memmap.PtrUint16(0x5D4594, 816154)) * ((uint32(a2) * uint32(*memmap.PtrUint16(0x5D4594, 816250))) >> 14)) >> 14)
		*memmap.PtrUint32(0x5D4594, 816148) &= 0xFFFFFFFD
		*memmap.PtrUint32(0x5D4594, 816244) &= 0xFFFFFFFD
		AIL_set_stream_volume(a1, int32((v2>>14)*math.MaxInt8)/100)
	}
}
func Sub_43D440() {
	v0 := mem_getI32Ptr(0x5D4594, *memmap.PtrUint32(0x5D4594, 816352)*20+816108)
	if dword_5d4594_816340 == 0 {
		return
	}
	switch dword_5d4594_816348 {
	case 0:
		if dword_5d4594_816356 != 0 && dword_587000_93156 != 0 {
			dword_5d4594_816348 = 3
		} else {
			if *v0 != 0 {
				if dword_587000_93156 != 0 {
					sub_486320(memmap.PtrOff(0x5D4594, 816148), 0x4000)
					if nox_xxx_musicStartPlay_43D6C0(v0) != 0 {
						dword_5d4594_816348 = 1
						*(*int32)(unsafe.Add(unsafe.Pointer(v0), 4*4)) = 1
					} else {
						*v0 = 0
					}
				}
			}
		}
	case 1:
		if dword_587000_93156 != 0 && uint32(*v0) == dword_5d4594_816092 && audioStream1 != 0 && AIL_stream_status(audioStream1) != 2 {
			if dword_5d4594_816356 != 0 {
				dword_5d4594_816348 = 4
				sub_486350(memmap.PtrOff(0x5D4594, 816148), 0)
			}
		} else {
			dword_5d4594_816348 = 2
			sub_486350(memmap.PtrOff(0x5D4594, 816148), 0)
		}
	case 2:
		if audioStream1 == 0 {
			sub_43D650()
			dword_5d4594_816348 = 0
		} else {
			if AIL_stream_status(audioStream1) == 2 || (*memmap.PtrUint32(0x5D4594, 816152)&0xFFFF0000) == 0 {
				sub_43D650()
				dword_5d4594_816348 = 0
			}
		}
	case 3:
		if dword_5d4594_816356 == 0 || dword_587000_93156 == 0 {
			if dword_587000_93156 == 0 || uint32(*v0) != dword_5d4594_816092 || audioStream1 == 0 || AIL_stream_status(audioStream1) == 2 {
				sub_43D650()
				dword_5d4594_816348 = 0
			} else {
				sub_486350(memmap.PtrOff(0x5D4594, 816148), 0x4000)
				sub_43D6A0()
				dword_5d4594_816348 = 1
			}
		}
	case 4:
		if audioStream1 != 0 && AIL_stream_status(audioStream1) != 2 {
			if (*memmap.PtrUint32(0x5D4594, 816152) & 0xFFFF0000) == 0 {
				sub_43D680()
				dword_5d4594_816348 = 3
			}
		} else {
			sub_43D650()
			dword_5d4594_816348 = 0
		}
	default:
	}
}
func sub_43D8E0() int32 {
	if dword_5d4594_816340 != 0 {
		return 1
	}
	v1 := sub_43F130()
	audioDriver = v1
	dword_587000_93156 = uint32(bool2int32(v1 != 0))
	sub_4864A0((*uint32)(memmap.PtrOff(0x5D4594, 816148)))
	sub_486380((*uint32)(memmap.PtrOff(0x5D4594, 816148)), 0x3E8, 0, 0x4000)
	dword_5d4594_816348 = 0
	dword_5d4594_816092 = 0
	*memmap.PtrUint32(0x5D4594, 816352) = 0
	*memmap.PtrUint32(0x5D4594, 816108) = 0
	dword_5d4594_816356 = 0
	dword_5d4594_816372 = 0
	dword_5d4594_816368 = 0
	audioStream1 = 0
	dword_5d4594_816340 = 1
	return 1
}
func sub_43D990() {
	var v1 int4
	v1.field_0 = 0
	sub_43D9E0(&v1)
}
func sub_43D9B0(a1 int32, a2 int32) {
	var v3 int4
	v3.field_0 = a1
	v3.field_C = 0
	v3.field_8 = 0
	v3.field_4 = a2
	sub_43D9E0(&v3)
}
func sub_43D9E0(a1 *int4) {
	var (
		v1 *int4
		v2 int32
	)
	v1 = (*int4)(memmap.PtrOff(0x5D4594, uintptr((*memmap.PtrUint32(0x5D4594, 816352)^1))*20+816108))
	v2 = a1.field_4
	if v2 <= 100 {
		if v2 < 0 {
			a1.field_4 = 0
		}
	} else {
		a1.field_4 = 100
	}
	if *memmap.PtrUint32(0x5D4594, 816344) != 0 {
		*(*int4)(memmap.PtrOff(0x5D4594, 816060)) = *a1
	} else {
		*v1 = *a1
		(*(*int4)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(int4{})*1))).field_0 = 0
		*memmap.PtrUint32(0x5D4594, 816352) ^= 1
	}
}
func sub_43DA80() int32 {
	var result int32
	if dword_5d4594_816368 < 6 {
		sub_43DD10(mem_getI32Ptr(0x5D4594, (dword_5d4594_816368+dword_5d4594_816372*6)*16+815772))
		dword_5d4594_816368++
		result = 1
	} else {
		dword_5d4594_816368 = 6
		result = 0
	}
	return result
}
func sub_43DAD0() {
	if dword_5d4594_816368 > 0 {
		sub_43D9E0((*int4)(memmap.PtrOff(0x5D4594, uintptr((func() uint32 {
			p := &dword_5d4594_816368
			*p--
			return *p
		}()+dword_5d4594_816372*6))*16+815772)))
	}
	dword_5d4594_816368 = 0
}
func sub_43DB20() int32 {
	return int32(dword_5d4594_816368)
}
func sub_43DB30(a1 int32) int32 {
	var result int32
	result = a1
	dword_5d4594_816368 = uint32(a1)
	return result
}
func sub_43DB40(a1 int32) *byte {
	return (*byte)(memmap.PtrOff(0x5D4594, uintptr((uint32(a1)+dword_5d4594_816372*6))*16+815772))
}
func sub_43DB60() int32 {
	var (
		result int32
		v1     int32
		v2     int32
	)
	result = 3
	if dword_5d4594_816372 < 3 {
		sub_43DA80()
		v1 = int32(dword_5d4594_816372)
		v2 = int32(dword_5d4594_816368)
		dword_5d4594_816368 = 0
		*memmap.PtrUint32(0x5D4594, uintptr(dword_5d4594_816372)*4+816076) = uint32(v2)
		result = v1 + 1
		dword_5d4594_816372 = uint32(result)
	} else {
		dword_5d4594_816372 = 3
	}
	return result
}
func sub_43DBA0() {
	var v1 int32
	if dword_5d4594_816372 > 0 {
		v1 = int32(dword_5d4594_816372 - 1)
		dword_5d4594_816372 = uint32(v1)
		dword_5d4594_816368 = *memmap.PtrUint32(0x5D4594, uintptr(v1*4)+816076)
		sub_43DAD0()
	} else {
		dword_5d4594_816372 = 0
	}
}
func sub_43DBD0() int32 {
	dword_5d4594_816356++
	Sub_43D440()
	return 0
}
func sub_43DBE0() int32 {
	if func() int32 {
		p := (*int32)(unsafe.Pointer(&dword_5d4594_816356))
		*p--
		return *p
	}() < 0 {
		dword_5d4594_816356 = 0
	}
	Sub_43D440()
	return 0
}
func sub_43DC00() {
	dword_587000_93156 = 0
}
func sub_43DC10() int32 {
	var result int32
	result = int32(audioDriver)
	if audioDriver != 0 {
		dword_587000_93156 = 1
	}
	return result
}
func sub_43DC30() int32 {
	return int32(dword_587000_93156)
}
func sub_43DC40() int32 {
	var result int32
	if dword_5d4594_816340 == 0 || (func() bool {
		result = 1
		return dword_5d4594_816348 != 1
	}()) && dword_5d4594_816348 != 4 && dword_5d4594_816348 != 2 {
		result = 0
	}
	return result
}
func sub_43DD10(a1 *int32) int32 {
	var (
		v1     *uint8
		result int32
	)
	v1 = (*uint8)(memmap.PtrOff(0x5D4594, uintptr(*memmap.PtrUint32(0x5D4594, 816352))*20+816108))
	*a1 = int32(*memmap.PtrUint32(0x5D4594, uintptr(*memmap.PtrUint32(0x5D4594, 816352))*20+816108))
	*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1)) = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*1)))
	*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*2)) = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*2)))
	*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*3)) = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*3)))
	result = int32(audioStream1)
	if audioStream1 == 0 {
		return result
	}
	result = *a1
	if dword_5d4594_816092 == uint32(*a1) {
		result = AIL_stream_position(audioStream1)
		*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*2)) = result
	}
	return result
}
func sub_43DD70(a1 int32, a2 int32) {
	sub_43DD10(mem_getI32Ptr(0x5D4594, 816060))
	sub_43D9B0(a1, a2)
	*memmap.PtrUint32(0x5D4594, 816344) = 1
}
func nox_xxx_gui_43E1A0(a1 int32) {
	if a1 != 0 {
		result := nox_window_new(nil, 552, 0, 0, int(nox_win_width), int(nox_win_height), nil)
		dword_5d4594_816412 = result
		result.DrawData().BgColorVal = nox_color_black_2650656
	} else {
		if dword_5d4594_816412 != nil {
			nox_xxx_windowDestroyMB_46C4E0(dword_5d4594_816412)
			dword_5d4594_816412 = nil
		}
	}
}
func sub_43E8C0(a1 int32) {
	*memmap.PtrUint32(0x5D4594, 816408) = uint32(a1)
}
func sub_43EDB0(a1 ail.Sample) {
	v1 := AIL_sample_user_data(a1)
	v2 := v1
	result := int32(*(*uint32)(unsafe.Add(v1, 28)))
	if result == 0 {
		result = ccall.AsFunc[func(unsafe.Pointer) int32](*(*unsafe.Pointer)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v2, 4)), 284)))(*(*unsafe.Pointer)(unsafe.Add(v2, 4)))
		*(*uint32)(unsafe.Add(v2, 28)) = 1
	}
}
func sub_43EE00(a1 unsafe.Pointer) int32 {
	var (
		v4  int32
		v5  *byte
		v6  uint32
		v7  int32
		v8  int32
		v9  *byte
		v10 int8
		v11 uint32
		v12 *byte
		v13 *byte
		v14 int32
		v15 int32
		v16 int32
		v17 *byte
		v18 int32
		v19 *byte
		v20 int32
		v21 int32
		v22 *byte
	)
	v1 := a1
	v20 = AIL_sample_buffer_ready((ail.Sample)(*(*uint32)(unsafe.Add(a1, 8))))
	if v20 == -1 {
		return -1
	}
	for {
		v3 := *(*unsafe.Pointer)(unsafe.Add(v1, 4))
		v4 = 0
		v5 = nil
		v17 = *(**byte)(unsafe.Add(v1, v20*4+20))
		v6 = 0
		v7 = 0
		v21 = 0
		v19 = nil
		v18 = 0
		if *(*uint32)(unsafe.Add(a1, 12)) == 0 {
			for {
				if v4 >= 0x4000 {
					break
				}
				v8 = int32(*(*uint32)(unsafe.Add(v3, 300)))
				if v8 == 0 {
					ccall.AsFunc[func(unsafe.Pointer)](*(*unsafe.Pointer)(unsafe.Add(v3, 276)))(v3)
					v8 = int32(*(*uint32)(unsafe.Add(v3, 300)))
					if v8 == 0 {
						ccall.AsFunc[func(unsafe.Pointer)](*(*unsafe.Pointer)(unsafe.Add(v3, 280)))(v3)
						v8 = int32(*(*uint32)(unsafe.Add(v3, 300)))
						if v8 == 0 {
							*(*uint32)(unsafe.Add(a1, 12)) = 1
							break
						}
					}
					v6 = uint32(v18)
				}
				if v4 != 0 {
					goto LABEL_A
				}
				v19 = *(**byte)(unsafe.Add(v3, 296))
				if v8 < 0x4000 || v5 != nil {
					goto LABEL_A
				} else {
					v7 = v8
					goto LABEL_B
				}
			LABEL_A:
				if v8+v4 > 0x4000 {
					v8 = 0x4000 - v4
				}
				if v8 != 0 {
					if v5 != nil {
						if v6 != 0 {
							v9 = v5
							v10 = int8(uint8(v6))
							v11 = v6 >> 2
							alloc.Memcpy(unsafe.Pointer(v22), unsafe.Pointer(v9), uintptr(v11*4))
							v13 = (*byte)(unsafe.Add(unsafe.Pointer(v9), v11*4))
							v12 = (*byte)(unsafe.Add(unsafe.Pointer(v22), v11*4))
							v19 = v22
							v14 = int32(v10) & 3
							v5 = nil
							alloc.Memcpy(unsafe.Pointer(v12), unsafe.Pointer(v13), uintptr(v14))
						}
						alloc.Memcpy(unsafe.Pointer(v17), *(*unsafe.Pointer)(unsafe.Add(v3, 296)), uintptr(v8))
						v4 = v21
					} else if v6 == 0 {
						v5 = *(**byte)(unsafe.Add(v3, 296))
						v22 = v17
						v18 = v8
					} else {
						alloc.Memcpy(unsafe.Pointer(v17), *(*unsafe.Pointer)(unsafe.Add(v3, 296)), uintptr(v8))
						v4 = v21
					}
					v7 = v8
					v17 = (*byte)(unsafe.Add(unsafe.Pointer(v17), v8))
					v6 = uint32(v18)
				}
			LABEL_B:
				v15 = int32(*(*uint32)(unsafe.Add(v3, 304)) - uint32(v7))
				*(*uint32)(unsafe.Add(v3, 300)) -= uint32(v7)
				v16 = int32(uint32(v7) + *(*uint32)(unsafe.Add(v3, 296)))
				*(*uint32)(unsafe.Add(v3, 304)) = uint32(v15)
				*(*uint32)(unsafe.Add(v3, 296)) = uint32(v16)
				v4 += v7
				v21 = v4
				if *(*uint32)(unsafe.Add(a1, 12)) != 0 {
					break
				}
			}
		}
		AIL_load_sample_buffer((ail.Sample)(*(*uint32)(unsafe.Add(a1, 8))), uint32(v20), unsafe.Pointer(v19), uint32(v4))
		v20 = AIL_sample_buffer_ready((ail.Sample)(*(*uint32)(unsafe.Add(a1, 8))))
		if v20 == -1 {
			return -1
		}
		v1 = a1
	}
}
func sub_43F0E0(a1 *uint32) int32 {
	var (
		v1     int32
		result int32
		v3     int32
	)
	v1 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)))
	if v1 != 0 {
		if v1 == 2 {
			v3 = -bool2int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*3)) != 2)
			*(*uint8)(unsafe.Pointer(&v3)) = uint8(int8(v3 & 0xFE))
			result = v3 + 7
		} else {
			result = 0
		}
	} else if *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*3)) == 2 {
		result = bool2int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)) == 2) + 2
	} else {
		result = bool2int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4)) == 2)
	}
	return result
}
func sub_4417E0(a1 *wchar2_t, a2 *byte) {
	var (
		v2 uint8
		v3 *byte
	)
	_ = v3
	var v4 [64]byte
	var v5 [64]wchar2_t
	if a2 != nil {
		libc.StrCpy(&v4[0], a2)
		v2 = *memmap.PtrUint8(0x587000, 103296)
		v3 = &v4[libc.StrLen(&v4[0])]
		*(*uint32)(unsafe.Pointer(v3)) = *memmap.PtrUint32(0x587000, 103292)
		*(*byte)(unsafe.Add(unsafe.Pointer(v3), 4)) = v2
		nox_swprintf(&v5[0], internWStr("%-20.20S\t\t"), &v4[0])
		nox_wcscat(a1, &v5[0])
	}
}
func nox_xxx_doExecrul_4438A0(a1 unsafe.Pointer) int32 {
	var (
		v1 *FILE
		v2 *FILE
		v3 *byte
		v5 [256]byte
		v6 [256]byte
		v7 [128]wchar2_t
	)
	if a1 == nil {
		return 0
	}
	v6[0] = 0
	nox_sprintf(&v6[0], internCStr("%S"), a1)
	v1 = nox_fs_open_text(&v6[0])
	v2 = v1
	if v1 == nil {
		return 0
	}
	if !nox_fs_feof(v1) {
		for {
			libc.MemSet(unsafe.Pointer(&v5[0]), 0, 0xFC)
			*(*uint16)(unsafe.Pointer(&v5[252])) = 0
			v5[254] = 0
			nox_fs_fgets(v2, &v5[0], math.MaxUint8)
			v3 = libc.StrChr(&v5[0], 10)
			if v3 != nil {
				*v3 = 0
			}
			if v5[0] != 0 {
				nox_swprintf(&v7[0], internWStr("%S"), &v5[0])
				nox_gui_console_Printf_450C00(NOX_CONSOLE_WHITE, (*wchar2_t)(memmap.PtrOff(0x587000, 106956)), &v7[0])
				nox_server_parseCmdText_443C80(&v7[0], 1)
			}
			if nox_fs_feof(v2) {
				break
			}
		}
	}
	nox_fs_close(v2)
	return 1
}
func sub_445450() *wchar2_t {
	var (
		v0     *uint8
		result *wchar2_t
	)
	v0 = (*uint8)(memmap.PtrOff(0x5D4594, 824440))
	for {
		result = nox_wcscpy((*wchar2_t)(unsafe.Add(unsafe.Pointer(v0), -int(unsafe.Sizeof(wchar2_t(0))*318))), (*wchar2_t)(memmap.PtrOff(0x5D4594, 825740)))
		*(*uint32)(unsafe.Pointer(v0)) = 0
		*(*uint8)(unsafe.Add(unsafe.Pointer(v0), 4)) = 0
		v0 = (*uint8)(unsafe.Add(unsafe.Pointer(v0), 644))
		if int32(uintptr(unsafe.Pointer(v0))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 826372))) {
			break
		}
	}
	dword_5d4594_825736 = 0
	return result
}
func nox_xxx_drawMessageLines_445530() int32 {
	var (
		v1     int32
		v2     int32
		v3     int32
		result int32
		v5     int32
		v6     *uint16
		v7     int32
		v8     *uint8
		v9     int32
		v10    int32
		v11    int32
		i      int32
		v13    int32
		v14    int32
	)
	v13 = 0
	var rdr = nox_draw_getViewport_437250()
	v1 = int32(rdr.Size.Y*3/4 + rdr.Screen.Min.Y - 15)
	v2 = int32(dword_5d4594_825736)
	for i = int32(dword_5d4594_825736); ; v2 = i {
		v3 = v2 * 161
		result = int32(gameFrame())
		v5 = v3 * 4
		if *memmap.PtrUint32(0x5D4594, uintptr(v5)+824440) < gameFrame() {
			break
		}
		nox_xxx_drawSetTextColor_434390(int32(nox_color_black_2650656))
		v6 = mem_getU16Ptr(0x5D4594, uint32(v5)+823804)
		nox_xxx_drawGetStringSize_43F840(nil, v6, &v14, nil, 0)
		v7 = nox_win_width - v14
		v8 = (*uint8)(memmap.PtrOff(0x587000, 107848))
		v9 = (nox_win_width - v14) / 2
		for {
			nox_xxx_drawString_43F6E0(nil, v6, int32(uint32(v9)+*(*uint32)(unsafe.Pointer(v8))), int32(uint32(v1)+*(*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*1))))
			v8 = (*uint8)(unsafe.Add(unsafe.Pointer(v8), 8))
			if int32(uintptr(unsafe.Pointer(v8))) >= int32(uintptr(memmap.PtrOff(0x587000, 107880))) {
				break
			}
		}
		v10 = v13
		if v13 != 0 {
			nox_xxx_drawSetTextColor_434390(*memmap.PtrInt32(0x5D4594, 2597996))
		} else {
			nox_xxx_drawSetTextColor_434390(int32(nox_color_white_2523948))
		}
		nox_xxx_drawString_43F6E0(nil, v6, v7/2, v1)
		v11 = -4 - nox_xxx_guiFontHeightMB_43F320(nil)
		result = i
		v1 += v11
		if i != 0 {
			i--
		} else {
			i = 2
		}
		v13++
		if v10+1 >= 3 {
			break
		}
	}
	return result
}
func nox_xxx_guiChatMode_4456E0(win *gui.Window, draw *gui.WindowData) int {
	var (
		a1p = win.C()
		v2  int32
		v4  int32
	)
	v1 := a1p
	var a1a int32
	nox_client_wndGetPosition_46AA60(win, &a1a, &v4)
	v2 = *(*int32)(unsafe.Add(v1, 4*25))
	a1 := a1a + *(*int32)(unsafe.Add(v1, 4*24))
	nox_client_drawImageAt_47D2C0((noxrender.ImageHandle)(*(*unsafe.Pointer)(unsafe.Add(v1, 4*15))), a1, v2+v4)
	return 1
}
func nox_xxx_guiChatShowHide_445730(a1 int32) int32 {
	return nox_window_set_hidden(dword_5d4594_825744, a1)
}
func sub_445770() {
	nox_xxx_windowDestroyMB_46C4E0(dword_5d4594_825744)
	dword_5d4594_825744 = nil
}
func nox_xxx_quitDialogYes_445B20() {
	nox_client_quit_4460C0()
	sub_445C40()
}
func nox_xxx_quitDialogNo_445B30() int32 {
	return nox_xxx_wndSetCaptureMain_46ADC0(nox_wnd_quitMenu_825760)
}
func sub_445BA0() {
	sub_413A00(0)
}
func sub_445C20() {
	v := nox_xxx_wndGetFlags_46ADA0(nox_wnd_quitMenu_825760)
	if (v & 0x10) == 0 {
		sub_445C40()
	}
}
func sub_445FF0() {
	if nox_wnd_quitMenu_825760 != nil {
		nox_wnd_quitMenu_825760.DrawData().SetBackgroundColor(noxcolor.RGBA5551(nox_color_black_2650656))
	}
	for i := 9001; i <= 9006; i++ {
		result := nox_xxx_wndGetChildByID_46B0C0(nox_wnd_quitMenu_825760, int32(i))
		if result != nil {
			result.DrawData().TextColorVal = nox_color_orange_2614256
		}
	}
}
func nox_gui_xxx_check_446360() uint32 {
	if nox_wnd_quitMenu_825760 == nil {
		return 0
	}
	return (uint32(^nox_xxx_wndGetFlags_46ADA0(nox_wnd_quitMenu_825760)) >> 4) & 1
}
func nox_motd_4463E0(a1 int32) {
	dword_5d4594_826036 = nil
	*memmap.PtrUint32(0x5D4594, uintptr(a1*4)+826040) = 0
	v2 := nox_fs_open(internCStr("motd.txt"))
	if v2 != nil {
		*memmap.PtrUint32(0x5D4594, uintptr(a1*4)+826040) = uint32(nox_fs_fsize(v2))
		v3 := alloc.Calloc1(int(*memmap.PtrUint32(0x5D4594, uintptr(a1*4)+826040)+1), 1)
		dword_5d4594_826036 = v3
		if v3 != nil {
			nox_binfile_fread_raw_40ADD0((*byte)(v3), *memmap.PtrUint32(0x5D4594, uintptr(a1*4)+826040), 1, v2)
			v3 = dword_5d4594_826036
		}
		*(*byte)(unsafe.Add(v3, func() uint32 {
			p := mem_getU32Ptr(0x5D4594, uint32(a1*4)+826040)
			x := *p
			*p++
			return x
		}())) = 0
		nox_fs_close(v2)
	}
}
func sub_446490(a1 int32) {
	if dword_5d4594_826036 != nil {
		alloc.FreePtr(dword_5d4594_826036)
	}
	dword_5d4594_826036 = nil
	*memmap.PtrUint32(0x5D4594, uintptr(a1)*4+826040) = 0
}
func nox_xxx_guiMotdLoad_4465C0() *gui.Window {
	v0 := nox_new_window_from_file(internCStr("motd.wnd"), sub_4466C0)
	dword_5d4594_826028 = v0
	v1 := nox_xxx_wndGetChildByID_46B0C0(v0, 4203)
	dword_5d4594_826032 = v1
	v2 := v1.WidgetData
	v7 := nox_xxx_gLoadImg_42F970(internCStr("UISlider"))
	v3 := nox_xxx_gLoadImg_42F970(internCStr("UISliderLit"))
	v4 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_826028, 4204)
	v5 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_826028, 4205)
	v8 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_826028, 4206)
	v4.Field100Ptr.SizeVal.X = 16
	v4.Field100Ptr.SizeVal.Y = 10
	sub_4B5700(v4, nil, nil, v7, v3, v3)
	nox_xxx_wnd_46B280(v4, dword_5d4594_826032)
	nox_xxx_wnd_46B280(v5, dword_5d4594_826032)
	nox_xxx_wnd_46B280(v8, dword_5d4594_826032)
	*(*uint32)(unsafe.Add(v2, 4*9)) = uint32(uintptr(unsafe.Pointer(v4)))
	*(*uint32)(unsafe.Add(v2, 4*7)) = uint32(uintptr(unsafe.Pointer(v5)))
	*(*uint32)(unsafe.Add(v2, 4*8)) = uint32(uintptr(unsafe.Pointer(v8)))
	return dword_5d4594_826028
}
func sub_4466C0(win *gui.Window, a2, a3, a4 uintptr) uintptr {
	if a2 == 16391 {
		nox_xxx_clientPlaySoundSpecial_452D80(766, 100)
		sub_446780()
	}
	return 0
}
func sub_4466F0(a1 *byte, a2 *uint8) *byte {
	var (
		v2     *byte
		v3     *byte
		v4     int8
		result *byte
	)
	v2 = a2
	v3 = a1
	*a2 = 0
	if *a1 == 0 {
		return nil
	}
	for {
		v4 = int8(*v3)
		if *v3 == 0 {
			*v2 = 0
			return nil
		}
		if int32(v4) == 10 {
			*v2 = 0
			return (*byte)(unsafe.Add(unsafe.Pointer(v3), 1))
		}
		if int32(v4) == 13 {
			break
		}
		*func() *byte {
			p := &v2
			x := *p
			*p = (*byte)(unsafe.Add(unsafe.Pointer(*p), 1))
			return x
		}() = byte(v4)
		v3 = (*byte)(unsafe.Add(unsafe.Pointer(v3), 1))
	}
	result = (*byte)(unsafe.Add(unsafe.Pointer(v3), 1))
	*v2 = 0
	if *result == 10 {
		result = (*byte)(unsafe.Add(unsafe.Pointer(result), 1))
	}
	return result
}
func nox_xxx_motdAddSomeTextMB_446730(a1 *uint8) *uint8 {
	var (
		result *uint8
	)
	v2, free := alloc.Make([]wchar2_t{}, 256)
	defer free()
	result = a1
	if int32(*a1) != 0 {
		nox_swprintf(&v2[0], internWStr("%S"), a1)
		result = (*uint8)(unsafe.Pointer(nox_window_call_field_94_fnc(dword_5d4594_826032, 16397, uintptr(unsafe.Pointer(&v2[0])), math.MaxUint32)))
	}
	return result
}
func sub_446780() int32 {
	if wndIsShown_nox_xxx_wndIsShown_46ACC0(dword_5d4594_826028) != 0 {
		return 0
	}
	nox_xxx_windowFocus_46B500(nil)
	nox_window_set_hidden(dword_5d4594_826028, 1)
	dword_5d4594_826028.Flags &= 0xFFFFFFF7
	dword_5d4594_826032.Flags &= 0xFFFFFFF7
	nox_window_call_field_94_fnc(dword_5d4594_826032, 16399, 0, 0)
	return 1
}
func nox_xxx_motd_4467F0() {
	var (
		result uint32
		v2     *byte
		v4     [256]byte
	)
	result = nox_gui_xxx_check_446360()
	if result == 0 {
		result = uint32(nox_xxx_isQuest_4D6F50())
		if result == 0 || (func() uint32 {
			result = uint32(bool2int32(noxflags.HasGame(128)))
			return result
		}()) == 0 {
			if !nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) {
				result = uint32(nox_xxx_wndGetFlags_46ADA0(dword_5d4594_826028))
				if result&0x10 != 0 {
					result = uint32(sub_44A4A0())
					if result == 0 {
						result = uint32(sub_49C810())
						if result == 0 {
							result = uint32(sub_49CB40())
							if result == 0 {
								nox_xxx_wndShowModalMB_46A8C0(dword_5d4594_826028)
								v1 := nox_xxx_wndGetChildByID_46B0C0(nil, 4100)
								if v1 != nil {
									nox_xxx_wndShowModalMB_46A8C0(v1)
								}
								dword_5d4594_826028.Flags |= 8
								dword_5d4594_826032.Flags |= 8
								v2 = *(**byte)(memmap.PtrOff(0x5D4594, 826060))
								if *memmap.PtrUint32(0x5D4594, 826060) != 0 {
									for {
										v2 = sub_4466F0(v2, &v4[0])
										if v2 == nil {
											break
										}
										if v4[0] == 0 {
											libc.StrCpy(&v4[0], internCStr(" "))
										}
										nox_xxx_motdAddSomeTextMB_446730(&v4[0])
									}
									if v4[0] != 0 {
										nox_xxx_motdAddSomeTextMB_446730(&v4[0])
									}
								}
								v3 := nox_xxx_wndGetChildByID_46B0C0(dword_5d4594_826028, 4202)
								nox_xxx_windowFocus_46B500(v3)
							}
						}
					}
				}
			}
			*memmap.PtrUint32(0x5D4594, 826068) = 0
		}
	}
}
func sub_446950() int32 {
	return bool2int32(dword_5d4594_826028 != nil && (nox_xxx_wndGetFlags_46ADA0(dword_5d4594_826028)&0x10) == 0)
}
func sub_44B940(a1 *uint32, a2 int32, f *binfile.MemFile) int32 {
	var (
		v3  int32
		v4  int32
		v5  unsafe.Pointer
		v6  int32
		v8  int32
		v10 int8
		v13 int32
		v14 int32
		v15 uint8
		v16 *byte
		v17 [128]byte
	)
	v3 = a2
	v4 = 0
	*a1 = 40
	v14 = 0
	for {
		if v4 >= 16 {
			v13 = v4 + 4
		} else {
			v13 = v4
		}
		v5 = alloc.Calloc1(int(v3), 4)
		*(*uint32)(unsafe.Add(unsafe.Add(unsafe.Pointer(a1), v13), 4)) = uint32(uintptr(v5))
		if v5 == nil {
			break
		}
		v6 = 0
		if v3 > 0 {
			for {
				v8 = nox_memfile_read_i32(f)
				v17[0] = *memmap.PtrUint8(0x5D4594, 830840)
				if v8 == -1 {
					v10 = nox_memfile_read_i8(f)
					v15 = nox_memfile_read_u8(f)
					*(*uint8)(unsafe.Pointer(&v16)) = uint8(v10)
					nox_memfile_read(unsafe.Pointer(&v17[0]), 1, int32(v15), f)
					v17[v15] = 0
					v3 = a2
				}
				*(*uint32)(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Add(unsafe.Add(unsafe.Pointer(a1), v13), 4)) + uint32(func() int32 {
					p := &v6
					*p++
					return *p
				}()*4) - 4))) = uint32(uintptr(unsafe.Pointer(nox_xxx_readImgMB_42FAA0(v8, int8(uintptr(unsafe.Pointer(v16))), &v17[0]))))
				if v6 >= v3 {
					break
				}
			}
			v4 = v14
		}
		v4 += 4
		v14 = v4
		if v4 >= 32 {
			return 1
		}
	}
	return 0
}
func nox_xxx_parse_Armor_44BA60(a1 *byte) int32 {
	var (
		v1 int32
		v2 **byte
	)
	v1 = 0
	v2 = (**byte)(memmap.PtrOff(0x587000, 113856))
	for libc.StrCmp(*v2, a1) != 0 {
		v2 = (**byte)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof((*byte)(nil))*1))
		v1++
		if int32(uintptr(unsafe.Pointer(v2))) >= int32(uintptr(memmap.PtrOff(0x587000, 113960))) {
			return -1
		}
	}
	return v1
}
func sub_44BAC0(a1 *byte) int32 {
	var (
		v1 int32
		v2 **byte
	)
	v1 = 0
	v2 = (**byte)(memmap.PtrOff(0x587000, 113964))
	for libc.StrCmp(*v2, a1) != 0 {
		v2 = (**byte)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof((*byte)(nil))*1))
		v1++
		if int32(uintptr(unsafe.Pointer(v2))) >= int32(uintptr(memmap.PtrOff(0x587000, 114072))) {
			return -1
		}
	}
	return v1
}
func sub_44BB20(a1 *byte) int32 {
	var (
		v1 int32
		v2 **byte
	)
	v1 = 0
	v2 = (**byte)(memmap.PtrOff(0x587000, 115688))
	for libc.StrCmp(a1, *v2) != 0 {
		v2 = (**byte)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof((*byte)(nil))*1))
		v1++
		if int32(uintptr(unsafe.Pointer(v2))) >= int32(uintptr(memmap.PtrOff(0x587000, 115908))) {
			return -1
		}
	}
	return v1
}
