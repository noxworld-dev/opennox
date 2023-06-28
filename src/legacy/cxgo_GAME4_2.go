package legacy

import (
	"math"
	"unicode"
	"unsafe"

	"github.com/gotranspile/cxgo/runtime/cmath"
	"github.com/gotranspile/cxgo/runtime/libc"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/spell"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/client"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
	"github.com/noxworld-dev/opennox/v1/server"
)

func sub_51DA70(a1 int32, a2 int32, a3 unsafe.Pointer, a4 int32, a5 int32) int32 {
	var (
		v5  int32
		v6  int32
		v7  *int32
		v8  int32
		v9  int32
		v10 int32
		v11 int32
		v12 int32
		v13 int32
		v15 int32
		v16 int32
		v17 int32
		v18 int32
		v19 int32
		v20 int32
		v22 int32
		v23 int32
		v24 int32
		v25 int32
		v26 int32
		v27 int32
		v28 int32
		v29 int32
		v30 int32
	)
	v5 = a4
	v6 = a2
	v7 = (*int32)(a3)
	v8 = a1
	if a3 == nil {
		v9 = math.MaxUint8
		v10 = 0
		goto LABEL_19
	}
	if *(*uint32)(unsafe.Add(a3, 8)) == 0 {
		v11 = a1
		v12 = a2
		v28 = a1
		v13 = bool2int32(a4 != 1)
		v30 = v13
		goto LABEL_11
	}
	if int32(*(*uint8)(unsafe.Add(a3, 20))) == 0 {
		v9 = int32(*(*uint32)(a3))
		v10 = 0
		*(*uint32)(unsafe.Add(a3, 12)) = uint32(a1)
		*(*uint32)(unsafe.Add(a3, 16)) = uint32(a2)
		*(*uint8)(unsafe.Add(a3, 20)) = uint8(int8(a4))
		goto LABEL_19
	}
	v11 = int32(uint32(a1) - *(*uint32)(unsafe.Add(a3, 12)))
	v12 = int32(uint32(a2) - *(*uint32)(unsafe.Add(a3, 16)))
	v28 = int32(uint32(a1) - *(*uint32)(unsafe.Add(a3, 12)))
	a2 -= int32(*(*uint32)(unsafe.Add(a3, 16)))
	if int32(*(*uint8)(unsafe.Add(a3, 20))) != a4 {
		if int32(*(*uint8)(unsafe.Add(a3, 20))) != 1 {
			v13 = -1
		} else {
			v13 = 1
		}
		v30 = v13
		goto LABEL_11
	}
	v30 = 0
LABEL_11:
	v9 = *v7
	v15 = int32(nox_tile_defs_arr[v9].field_52)
	v29 = (v12 + v11) % v15
	v16 = int32(nox_tile_defs_arr[v9].field_53)
	v17 = (v30 + a2 - v28) % v16
	v18 = v29
	if v29 < 0 {
		v18 = v15 + v29
	}
	if v17 < 0 {
		v17 += v16
	}
	if *memmap.PtrUint32(0x973F18, 35916) == 1 {
		v10 = int32(dword_5d4594_3835348)
	} else {
		v10 = v18 + v17*v15
	}
	v8 = a1
	v5 = a4
LABEL_19:
	if v5 == 2 {
		if dword_5d4594_3835352 == 1 {
			if v7 != nil {
				v19 = *(*int32)(unsafe.Add(unsafe.Pointer(v7), 4*6))
				v20 = *(*int32)(unsafe.Add(unsafe.Pointer(v7), 4*7))
			} else {
				v19 = math.MaxUint8
				v20 = 0
			}
			return nox_xxx_tile_543C50((*uint32)(unsafe.Add(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(*(**obj_5D4594_2650668_t)(unsafe.Add(unsafe.Pointer(ptr_5D4594_2650668), unsafe.Sizeof((*obj_5D4594_2650668_t)(nil))*uintptr(v8))))))+uint32(v6*44))), 24)), v9, v10, v19, v20, a5)
		}
		v22 = v6 * 44
		v23 = int32(uint32(v22) + uint32(uintptr(unsafe.Pointer(*(**obj_5D4594_2650668_t)(unsafe.Add(unsafe.Pointer(ptr_5D4594_2650668), unsafe.Sizeof((*obj_5D4594_2650668_t)(nil))*uintptr(v8)))))))
		if *(*uint32)(unsafe.Add(v23, 24)) != uint32(v9) || *(*uint32)(unsafe.Add(v23, 28)) != uint32(v10) {
			*(*uint32)(unsafe.Add(v23, 24)) = uint32(v9)
			*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(*(**obj_5D4594_2650668_t)(unsafe.Add(unsafe.Pointer(ptr_5D4594_2650668), unsafe.Sizeof((*obj_5D4594_2650668_t)(nil))*uintptr(v8))))))+uint32(v22))), 28)) = uint32(v10)
			if v9 == math.MaxUint8 {
				nox_xxx_tileFreeTile_422200(int32(uint32(uintptr(unsafe.Pointer(*(**obj_5D4594_2650668_t)(unsafe.Add(unsafe.Pointer(ptr_5D4594_2650668), unsafe.Sizeof((*obj_5D4594_2650668_t)(nil))*uintptr(v8)))))) + uint32(v22) + 24))
			}
			if v7 != nil {
				*(*uint8)(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(*(**obj_5D4594_2650668_t)(unsafe.Add(unsafe.Pointer(ptr_5D4594_2650668), unsafe.Sizeof((*obj_5D4594_2650668_t)(nil))*uintptr(v8)))))) + uint32(v22)))) |= 2
			} else {
				*(*uint8)(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(*(**obj_5D4594_2650668_t)(unsafe.Add(unsafe.Pointer(ptr_5D4594_2650668), unsafe.Sizeof((*obj_5D4594_2650668_t)(nil))*uintptr(v8)))))) + uint32(v22)))) = uint8(int8(int32(*(*uint8)(unsafe.Pointer(uintptr(uint32(v22) + uint32(uintptr(unsafe.Pointer(*(**obj_5D4594_2650668_t)(unsafe.Add(unsafe.Pointer(ptr_5D4594_2650668), unsafe.Sizeof((*obj_5D4594_2650668_t)(nil))*uintptr(v8)))))))))) & 0xFD))
			}
			return 1
		}
		return 0
	}
	if v5 != 1 {
		return 0
	}
	if dword_5d4594_3835352 == 1 {
		if v7 != nil {
			v24 = *(*int32)(unsafe.Add(unsafe.Pointer(v7), 4*6))
			v25 = *(*int32)(unsafe.Add(unsafe.Pointer(v7), 4*7))
		} else {
			v24 = math.MaxUint8
			v25 = 0
		}
		return nox_xxx_tile_543C50((*uint32)(unsafe.Add(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(*(**obj_5D4594_2650668_t)(unsafe.Add(unsafe.Pointer(ptr_5D4594_2650668), unsafe.Sizeof((*obj_5D4594_2650668_t)(nil))*uintptr(v8))))))+uint32(v6*44))), 4)), v9, v10, v24, v25, a5)
	}
	v26 = v6 * 44
	v27 = int32(uint32(v26) + uint32(uintptr(unsafe.Pointer(*(**obj_5D4594_2650668_t)(unsafe.Add(unsafe.Pointer(ptr_5D4594_2650668), unsafe.Sizeof((*obj_5D4594_2650668_t)(nil))*uintptr(v8)))))))
	if *(*uint32)(unsafe.Add(v27, 4)) == uint32(v9) && *(*uint32)(unsafe.Add(v27, 8)) == uint32(v10) {
		return 0
	}
	*(*uint32)(unsafe.Add(v27, 4)) = uint32(v9)
	*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(*(**obj_5D4594_2650668_t)(unsafe.Add(unsafe.Pointer(ptr_5D4594_2650668), unsafe.Sizeof((*obj_5D4594_2650668_t)(nil))*uintptr(v8))))))+uint32(v26))), 8)) = uint32(v10)
	if v9 == math.MaxUint8 {
		nox_xxx_tileFreeTile_422200(int32(uint32(uintptr(unsafe.Pointer(*(**obj_5D4594_2650668_t)(unsafe.Add(unsafe.Pointer(ptr_5D4594_2650668), unsafe.Sizeof((*obj_5D4594_2650668_t)(nil))*uintptr(v8)))))) + uint32(v26) + 4))
	}
	if v7 != nil {
		*(*uint8)(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(*(**obj_5D4594_2650668_t)(unsafe.Add(unsafe.Pointer(ptr_5D4594_2650668), unsafe.Sizeof((*obj_5D4594_2650668_t)(nil))*uintptr(v8)))))) + uint32(v26)))) |= 1
	} else {
		*(*uint8)(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(*(**obj_5D4594_2650668_t)(unsafe.Add(unsafe.Pointer(ptr_5D4594_2650668), unsafe.Sizeof((*obj_5D4594_2650668_t)(nil))*uintptr(v8)))))) + uint32(v26)))) = uint8(int8(int32(*(*uint8)(unsafe.Pointer(uintptr(uint32(v26) + uint32(uintptr(unsafe.Pointer(*(**obj_5D4594_2650668_t)(unsafe.Add(unsafe.Pointer(ptr_5D4594_2650668), unsafe.Sizeof((*obj_5D4594_2650668_t)(nil))*uintptr(v8)))))))))) & 0xFE))
	}
	return 1
}
func sub_51DD50(a1 int32, a2 int32, a3 int32, a4 int32) {
	var (
		v4 int32
		v5 int32
		v6 *uint8
		v7 int32
	)
	if a1 > 0 && a1 < math.MaxInt8 && a2 > 0 && a2 < math.MaxInt8 {
		if (func() int32 {
			v4 = a3
			return a3 & 2
		}()) != 0 && (func() bool {
			v4 = a3
			return uint32(a4) == *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(*(**obj_5D4594_2650668_t)(unsafe.Add(unsafe.Pointer(ptr_5D4594_2650668), unsafe.Sizeof((*obj_5D4594_2650668_t)(nil))*uintptr(a1))))))+uint32(a2*44))), 24))
		}()) || v4&1 != 0 && uint32(a4) == *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(*(**obj_5D4594_2650668_t)(unsafe.Add(unsafe.Pointer(ptr_5D4594_2650668), unsafe.Sizeof((*obj_5D4594_2650668_t)(nil))*uintptr(a1))))))+uint32(a2*44))), 4)) {
			if ((v4&1) == 0 || a2 != 1) && ((a3&2) == 0 || a1 != 1) {
				v5 = 0
				if dword_5d4594_2487248 > 0 {
					v6 = (*uint8)(memmap.PtrOff(0x973F18, 16204))
					for {
						if *((*uint32)(unsafe.Add(unsafe.Pointer(v6), -int(4*1)))) == uint32(a1) && *(*uint32)(unsafe.Pointer(v6)) == uint32(a2) && *((*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*1))) == uint32(v4) {
							return
						}
						v5++
						v6 = (*uint8)(unsafe.Add(unsafe.Pointer(v6), 12))
						if v5 >= dword_5d4594_2487248 {
							break
						}
					}
				}
				if dword_5d4594_2487248 >= 500 {
					*memmap.PtrUint32(0x973F18, 22200) = 1
				} else {
					v7 = int32(func() uint32 {
						p := &dword_5d4594_2487248
						x := *p
						*p++
						return x
					}() * 12)
					*memmap.PtrUint32(0x973F18, uintptr(v7+16200)) = uint32(a1)
					*memmap.PtrUint32(0x973F18, uintptr(v7+16204)) = uint32(a2)
					*memmap.PtrUint32(0x973F18, uintptr(v7+16208)) = uint32(v4)
				}
			}
		}
	}
}
func sub_51DE30(a1 *uint32, a2 *uint32, a3 *uint32) int32 {
	var (
		v3     int32
		result int32
	)
	if dword_5d4594_2487248 <= 0 {
		return 0
	}
	v3 = int32(dword_5d4594_2487248 - 1)
	dword_5d4594_2487248 = uint32(v3)
	*a1 = *memmap.PtrUint32(0x973F18, uintptr(v3*12+16200))
	*a2 = *memmap.PtrUint32(0x973F18, uintptr(dword_5d4594_2487248)*12+16204)
	result = 1
	*a3 = *memmap.PtrUint32(0x973F18, uintptr(dword_5d4594_2487248)*12+16208)
	return result
}
func nox_xxx_mapCountWallsMB_51DEA0(it *server.Wall, data unsafe.Pointer) {
	a1 := int32(uintptr(it.C()))
	var result int32
	if int32(*(*uint8)(unsafe.Add(a1, 5))) < *memmap.PtrInt32(0x5D4594, 2487252) {
		*memmap.PtrUint32(0x5D4594, 2487252) = uint32(*(*uint8)(unsafe.Add(a1, 5)))
	}
	result = int32(*(*uint8)(unsafe.Add(a1, 6)))
	if result < *memmap.PtrInt32(0x5D4594, 2487256) {
		*memmap.PtrUint32(0x5D4594, 2487256) = uint32(*(*uint8)(unsafe.Add(a1, 6)))
	}
}
func sub_51DED0() int32 {
	var (
		v0 *int32
		v1 *byte
		v3 *float32
		v4 int32
		v5 int32
	)
	v0 = (*int32)(unsafe.Pointer(sub_45A060()))
	if v0 == nil {
		return 1
	}
	for {
		if sub_4E3AD0(*(*int32)(unsafe.Add(unsafe.Pointer(v0), 4*27))) == 0 && sub_4E3B80(*(*int32)(unsafe.Add(unsafe.Pointer(v0), 4*27))) != 0 {
			v1 = nox_get_thing_name(*(*int32)(unsafe.Add(unsafe.Pointer(v0), 4*27)))
			v3 = (*float32)(unsafe.Pointer(nox_xxx_newObjectByTypeID_4E3810(v1)))
			v4 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*9))))
			*(*float32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float32(0))*14)) = float32(float64(*(*int32)(unsafe.Add(unsafe.Pointer(v0), 4*3))) + 0.5)
			*(*float32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float32(0))*15)) = float32(float64(*(*int32)(unsafe.Add(unsafe.Pointer(v0), 4*4))) + 0.5)
			v5 = *(*int32)(unsafe.Add(unsafe.Pointer(v0), 4*32))
			*((*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*10))) = uint32(v5)
			*((*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*11))) = uint32(v5)
			*((*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*9))) = uint32(v5)
			*((*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*4))) = uint32(*(*int32)(unsafe.Add(unsafe.Pointer(v0), 4*30)))
			*((*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*5))) = uint32(*(*int32)(unsafe.Add(unsafe.Pointer(v0), 4*70)))
			nox_xxx_xfer_saveObj_51DF90((*server.Object)(unsafe.Pointer(v3)))
			*((*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*9))) = uint32(v4)
			nox_xxx_objectFreeMem_4E38A0((*server.Object)(unsafe.Pointer(v3)))
		}
		v0 = (*int32)(unsafe.Pointer(nox_drawable_next_45A070((*client.Drawable)(unsafe.Pointer(v0)))))
		if v0 == nil {
			break
		}
	}
	return 1
}
func nox_xxx_mapSaveMap_51E010(a1 *byte, a2 int32) int32 {
	var (
		v2     *byte
		v3     uint8
		result int32
		v5     int32
		v7     int32
		v8     [1024]byte
		Mem    [1024]byte
	)
	v7 = -86050098
	libc.StrCpy(&Mem[0], a1)
	v8[0] = 0
	libc.StrNCat(&v8[0], a1, 1024-1)
	v8[libc.StrLen(&v8[0])-4] = 0
	v2 = &v8[libc.StrLen(&v8[0])+1]
	v3 = *memmap.PtrUint8(0x587000, 253116)
	*(*uint32)(unsafe.Pointer(func() *byte {
		p := &v2
		*p = (*byte)(unsafe.Add(unsafe.Pointer(*p), -1))
		return *p
	}())) = *memmap.PtrUint32(0x587000, 253112)
	*(*byte)(unsafe.Add(unsafe.Pointer(v2), 4)) = v3
	result = nox_xxx_cryptOpen_426910(&Mem[0], 0, 19)
	if result != 0 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v7)), 4)
		v5 = nox_xxx_cryptFlush_4268E0()
		if nox_xxx_map_51E140() != 0 {
			sub_4268F0(v5)
			nox_xxx_cryptClose_4269F0()
			if a2 == 0 || (func() int32 {
				result = nox_xxx_nxzCompressFile_57BDD0(&Mem[0], &v8[0])
				return result
			}()) != 0 {
				result = 1
			}
		} else {
			nox_xxx_cryptClose_4269F0()
			result = 0
		}
	}
	return result
}
func nox_xxx_map_51E140() int32 {
	var (
		result int32
		v2     int8
	)
	*memmap.PtrUint32(0x5D4594, 2487252) = 256
	*memmap.PtrUint32(0x5D4594, 2487256) = 256
	nox_xxx_wallForeachFn_410640(nox_xxx_mapCountWallsMB_51DEA0, nil)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x5D4594, 2487252)), 4)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(memmap.PtrOff(0x5D4594, 2487256)), 4)
	nox_xxx_mapWall_426A80(mem_getI32Ptr(0x5D4594, 2487252))
	nox_xxx_mapSetWallInGlobalDir0pr1_5004D0()
	if nox_xxx_mapWriteSectionsMB_426E20(nil) != 0 {
		nox_xxx_map_5004F0()
		v2 = 0
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v2)), 1)
		result = 1
	} else {
		nox_xxx_cryptClose_4269F0()
		result = 0
	}
	return result
}
func nox_xxx_mapGenSpellIdByName_51E1D0(a1 *byte) int32 {
	var (
		i  uint32
		v3 [60]byte
		v4 int8
	)
	libc.StrCpy(&v3[0], a1)
	for i = 0; i < uint32(libc.StrLen(&v3[0])); i++ {
		v3[i] = byte(int8(unicode.ToUpper(rune(v3[i]))))
	}
	nox_sprintf((*byte)(unsafe.Pointer(&v4)), internCStr("SPELL_%s"), &v3[0])
	return nox_xxx_spellNameToN_4243F0((*byte)(unsafe.Pointer(&v4)))
}
func nox_xxx_mapGenReadTheme_51E260(a1 *int32, a2 int32) int32 {
	var (
		v2 *FILE
		v3 *FILE
		v4 int32
		v5 int32
		v7 [256]byte
	)
	libc.MemSet(unsafe.Pointer(a1), 0, 0x45C)
	nox_sprintf(&v7[0], internCStr("mapgen/%s.thm"), a2)
	*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*3)) = 3
	*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*5)) = 3
	*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1)) = 5
	*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*2)) = 2
	*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*4)) = 1
	*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*6)) = 40
	*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*7)) = 20
	*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*8)) = 10
	*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*9)) = 5
	*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*10)) = 20
	*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*16)) = 1157234688
	*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*18)) = 100
	*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*19)) = int32(libc.GetTime(nil))
	*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*14)) = 1
	*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*22)) = 0
	*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*11)) = 0
	*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*12)) = 100
	*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*13)) = 100
	*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*30)) = 0
	*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*38)) = 0
	*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*46)) = 0
	*memmap.PtrUint32(0x5D4594, 2487520) = 0
	v2 = nox_binfile_open_408CC0(&v7[0], 0)
	v3 = v2
	if v2 == nil || nox_binfile_cryptSet_408D40(v2, 1) == 0 {
		return 0
	}
	for nox_xxx_mapGenReadLine_51E540(v3, (*uint8)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
		if nox_strcmpi(internCStr("ALGORITHM_DATA"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
			v4 = nox_xxx_genReadAlgData_51EBB0(int32(uintptr(unsafe.Pointer(a1))), v3)
			goto LABEL_23
		}
		if nox_strcmpi(internCStr("EXIT"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
			v4 = nox_xxx_genReadExit_51F800(int32(uintptr(unsafe.Pointer(a1))), v3)
			goto LABEL_23
		}
		if nox_strcmpi(internCStr("PREFAB"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
			v4 = nox_xxx_genReadPrefab_520BF0(int32(uintptr(unsafe.Pointer(a1))), v3)
			goto LABEL_23
		}
		if nox_strcmpi(internCStr("AMBIENT_LIGHT"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
			if nox_xxx_mapGenReadLine_51E540(v3, (*uint8)(memmap.PtrOff(0x5D4594, 2487264))) == 0 || (func() bool {
				*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*134)) = int32(libc.Atoi(libc.GoString((*byte)(memmap.PtrOff(0x5D4594, 2487264)))))
				return nox_xxx_mapGenReadLine_51E540(v3, (*uint8)(memmap.PtrOff(0x5D4594, 2487264))) == 0
			}()) || (func() bool {
				*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*135)) = int32(libc.Atoi(libc.GoString((*byte)(memmap.PtrOff(0x5D4594, 2487264)))))
				return nox_xxx_mapGenReadLine_51E540(v3, (*uint8)(memmap.PtrOff(0x5D4594, 2487264))) == 0
			}()) {
				v5 = 0
				goto LABEL_27
			}
			*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*136)) = int32(libc.Atoi(libc.GoString((*byte)(memmap.PtrOff(0x5D4594, 2487264)))))
			continue
		}
		if nox_strcmpi(internCStr("SPELL_SET"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
			if nox_strcmpi(internCStr("ARMOR_SET"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
				if nox_strcmpi(internCStr("WEAPON_SET"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
					if nox_strcmpi(internCStr("DECOR"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
						v5 = 0
						goto LABEL_27
					}
					v4 = nox_xxx_genReadDecor_51F9F0((*uint32)(unsafe.Pointer(a1)), v3)
				} else {
					v4 = nox_xxx_genReadWeaponSet_51F030(int32(uintptr(unsafe.Pointer(a1))), v3)
				}
			} else {
				v4 = nox_xxx_genReadArmorSet_51F640(int32(uintptr(unsafe.Pointer(a1))), v3)
			}
		} else {
			v4 = nox_xxx_genReadSpellSet_51EFB0(int32(uintptr(unsafe.Pointer(a1))), v3)
		}
	LABEL_23:
		v5 = v4
		if v4 == 0 {
			goto LABEL_27
		}
	}
	v5 = 1
LABEL_27:
	nox_binfile_close_408D90(v3)
	if v5 != 1 || nox_xxx_mapgenCheckSettings_520AD0((*int32)(unsafe.Add(unsafe.Pointer(a1), 4*22))) != 0 && nox_xxx_mapgenCheckSettings_520AD0((*int32)(unsafe.Add(unsafe.Pointer(a1), 4*30))) != 0 && (*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*46)) == 0 || nox_xxx_mapgenCheckSettings_520AD0((*int32)(unsafe.Add(unsafe.Pointer(a1), 4*46))) != 0) {
		return v5
	}
	return 0
}
func nox_xxx_mapGenReadLine_51E540(a1 *FILE, a2 *uint8) int32 {
	var result int32
	result = sub_51E570(a1, a2)
	if result != 0 {
		result = bool2int32(sub_51E670(a1) != 0)
	}
	return result
}
func sub_51E570(a1 *FILE, a2 *uint8) int32 {
	var (
		v2       *uint8
		v3       int32
		v4       int32
		v5       int32
		v6       int32
		CharType [2]uint16
	)
	v2 = a2
	v3 = 0
	*(*uint32)(unsafe.Pointer(&CharType[0])) = 0
	v4 = 1
	for {
		for {
			v5 = v3
			nox_binfile_fread_408E40((*byte)(unsafe.Pointer(&CharType[0])), 1, 1, a1)
			if nox_binfile_lastErr_409370(a1) == -1 {
				return 0
			}
			v3 = int32(*(*uint32)(unsafe.Pointer(&CharType[0])))
			if *(*uint32)(unsafe.Pointer(&CharType[0])) == 10 {
				*memmap.PtrUint32(0x5D4594, 2487520)++
			}
			v6 = bool2int32(unicode.IsSpace(rune(CharType[0])))
			if v6 != 0 {
				break
			}
			v4 = 0
			if v3 != 47 || v5 != 47 {
				*func() *uint8 {
					p := &v2
					x := *p
					*p = (*uint8)(unsafe.Add(unsafe.Pointer(*p), 1))
					return x
				}() = uint8(int8(v3))
			} else {
				sub_51E630(a1)
				v2 = a2
				v3 = int32(*(*uint32)(unsafe.Pointer(&CharType[0])))
				v4 = 1
			}
		}
		if v4 == 0 {
			break
		}
	}
	*v2 = 0
	return 1
}
func sub_51E630(a1 *FILE) int32 {
	var (
		v1     *FILE
		result int32
	)
	v1 = a1
	for {
		*((*uint8)(unsafe.Pointer(&a1))) = 0
		nox_binfile_fread_408E40((*byte)(unsafe.Pointer(&a1)), 1, 1, v1)
		result = nox_binfile_lastErr_409370(v1)
		if result == -1 {
			break
		}
		if int32(uint8(uintptr(unsafe.Pointer(a1)))) == 10 {
			*memmap.PtrUint32(0x5D4594, 2487520)++
			return result
		}
	}
	return result
}
func sub_51E670(a1 *FILE) int32 {
	var (
		result int32
		v2     int32
	)
	if nox_strcmpi(internCStr("IF"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
		if nox_strcmpi(internCStr("ELSE"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
			if nox_strcmpi(internCStr("ENDIF"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
				return 1
			}
		} else {
			result = sub_51E720(a1)
			if result == 0 {
				return result
			}
		}
		return bool2int32(nox_xxx_mapGenReadLine_51E540(a1, (*uint8)(memmap.PtrOff(0x5D4594, 2487264))) != 0)
	}
	result = sub_51E800(int32(uintptr(unsafe.Pointer(a1))), (*uint32)(unsafe.Pointer(&v2)))
	if result != 0 {
		if v2 != 0 {
			return bool2int32(nox_xxx_mapGenReadLine_51E540(a1, (*uint8)(memmap.PtrOff(0x5D4594, 2487264))) != 0)
		}
		result = sub_51E780(a1)
		if result != 0 {
			return bool2int32(nox_xxx_mapGenReadLine_51E540(a1, (*uint8)(memmap.PtrOff(0x5D4594, 2487264))) != 0)
		}
	}
	return result
}
func sub_51E720(a1 *FILE) int32 {
	for {
		for {
			if sub_51E570(a1, (*uint8)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
				return 0
			}
			if nox_strcmpi(internCStr("IF"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
				break
			}
			if sub_51E720(a1) == 0 {
				return 0
			}
		}
		if nox_strcmpi(internCStr("ENDIF"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
			break
		}
	}
	return 1
}
func sub_51E780(a1 *FILE) int32 {
	for {
		for {
			if sub_51E570(a1, (*uint8)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
				return 0
			}
			if nox_strcmpi(internCStr("IF"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
				break
			}
			if sub_51E720(a1) == 0 {
				return 0
			}
		}
		if nox_strcmpi(internCStr("ENDIF"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) == 0 || nox_strcmpi(internCStr("ELSE"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
			break
		}
	}
	return 1
}
func sub_51E800(a1 int32, a2 *uint32) int32 {
	var (
		v2 *FILE
		v3 *uint32
	)
	_ = v3
	var v4 *byte
	var result int32
	var v6 *byte
	var v7 *byte
	var v8 int32
	var v9 int32
	var v10 int32
	var v11 int32
	v2 = (*FILE)(a1)
	if nox_xxx_mapGenReadLine_51E540((*FILE)(a1), (*uint8)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
		return 0
	}
	if nox_strcmpi(internCStr("WIZARD"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
		v3 = a2
		*a2 = 0
		v4 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetFirst_416EA0()))
		if v4 != nil {
			for *(*byte)(unsafe.Add(unsafe.Pointer(v4), 2251)) != 1 {
				v4 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetNext_416EE0((*server.Player)(unsafe.Pointer(v4)))))
				if v4 == nil {
					return 1
				}
			}
			*v3 = 1
			return 1
		}
		return 1
	}
	if nox_strcmpi(internCStr("CONJURER"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
		v3 = a2
		*a2 = 0
		v6 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetFirst_416EA0()))
		if v6 != nil {
			for *(*byte)(unsafe.Add(unsafe.Pointer(v6), 2251)) != 2 {
				v6 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetNext_416EE0((*server.Player)(unsafe.Pointer(v6)))))
				if v6 == nil {
					return 1
				}
			}
			*v3 = 1
			return 1
		}
		return 1
	}
	if nox_strcmpi(internCStr("WARRIOR"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
		v3 = a2
		*a2 = 0
		v7 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetFirst_416EA0()))
		if v7 != nil {
			for *(*byte)(unsafe.Add(unsafe.Pointer(v7), 2251)) != 0 {
				v7 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetNext_416EE0((*server.Player)(unsafe.Pointer(v7)))))
				if v7 == nil {
					return 1
				}
			}
			*v3 = 1
			return 1
		}
		return 1
	}
	if nox_strcmpi(internCStr("EXPERIENCE_LEVEL"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
		if sub_51EAF0(int32(uintptr(unsafe.Pointer(v2))), (*uint32)(unsafe.Pointer(&a1))) != 0 && nox_xxx_mapGenReadLine_51E540(v2, (*uint8)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
			v8 = int32(libc.Atoi(libc.GoString((*byte)(memmap.PtrOff(0x5D4594, 2487264)))))
			switch a1 {
			case 0:
				*a2 = uint32(bool2int32(v8 > 3))
				result = 1
			case 1:
				*a2 = uint32(bool2int32(v8 < 3))
				result = 1
			case 2:
				*a2 = uint32(bool2int32(v8 == 3))
				result = 1
			case 3:
				*a2 = uint32(bool2int32(v8 != 3))
				result = 1
			default:
				return 1
			}
			return result
		}
		return 0
	}
	if nox_strcmpi(internCStr("NUMPLAYERS"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
		if libc.StrChr((*byte)(memmap.PtrOff(0x5D4594, 2487264)), 37) != nil {
			v11 = int32(libc.Atoi(libc.GoString((*byte)(memmap.PtrOff(0x5D4594, 2487264)))))
			*a2 = uint32(bool2int32(nox_xxx_mapGenRandFunc_526AC0(1, 100) <= v11))
			return 1
		}
		return 0
	}
	v9 = nox_common_playerInfoCount_416F40()
	if sub_51EAF0(int32(uintptr(unsafe.Pointer(v2))), (*uint32)(unsafe.Pointer(&a1))) == 0 || nox_xxx_mapGenReadLine_51E540(v2, (*uint8)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
		return 0
	}
	v10 = int32(libc.Atoi(libc.GoString((*byte)(memmap.PtrOff(0x5D4594, 2487264)))))
	switch a1 {
	case 0:
		*a2 = uint32(bool2int32(v9 < v10))
		result = 1
	case 1:
		*a2 = uint32(bool2int32(v9 > v10))
		result = 1
	case 2:
		*a2 = uint32(bool2int32(v9 == v10))
		result = 1
	case 3:
		*a2 = uint32(bool2int32(v9 != v10))
		result = 1
	default:
		return 1
	}
	return result
}
func sub_51EAF0(a1 int32, a2 *uint32) int32 {
	var result int32
	if nox_xxx_mapGenReadLine_51E540((*FILE)(a1), (*uint8)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
		return 0
	}
	if nox_strcmpi(internCStr("<"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
		*a2 = 0
		return 1
	}
	if nox_strcmpi(internCStr(">"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
		result = 1
		*a2 = 1
		return result
	}
	if nox_strcmpi(internCStr("=="), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
		*a2 = 2
		return 1
	}
	if nox_strcmpi(internCStr("!="), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
		return 0
	}
	result = 1
	*a2 = 3
	return result
}
func nox_xxx_genReadAlgData_51EBB0(a1 int32, a2 *FILE) int32 {
	var (
		v2 int32
		v3 **byte
		v4 *uint8
		v5 int32
		v7 int8
	)
	for nox_xxx_mapGenReadLine_51E540(a2, (*uint8)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
		if nox_strcmpi(internCStr("END"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
			return 1
		}
		if nox_xxx_mapGenReadLine_51E540(a2, (*uint8)(unsafe.Pointer(&v7))) == 0 {
			break
		}
		if nox_strcmpi(internCStr("midHallLength"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
			if nox_strcmpi(internCStr("hallLengthVariance"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
				if nox_strcmpi(internCStr("midHallWidth"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
					if nox_strcmpi(internCStr("hallWidthVariance"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
						if nox_strcmpi(internCStr("hallLimit"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
							if nox_strcmpi(internCStr("hallBranchRate"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
								if nox_strcmpi(internCStr("hallRoomRate"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
									if nox_strcmpi(internCStr("midRoomSize"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
										if nox_strcmpi(internCStr("roomVariance"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
											if nox_strcmpi(internCStr("irregularRoomRate"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
												if nox_strcmpi(internCStr("mapSize"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
													if nox_strcmpi(internCStr("recursionLimit"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
														if nox_strcmpi(internCStr("seed"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
															if nox_strcmpi(internCStr("emptyRoomRate"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
																if nox_strcmpi(internCStr("mergeRate"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
																	if nox_strcmpi(internCStr("useDoors"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
																		if nox_strcmpi(internCStr("debug"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
																			if nox_strcmpi(internCStr("adjacentPortalRate"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
																				if nox_strcmpi(internCStr("skeleton"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
																					v2 = 0
																					if *memmap.PtrUint32(0x587000, 253244) != 0 {
																						v3 = (**byte)(memmap.PtrOff(0x587000, 253244))
																						v4 = (*uint8)(memmap.PtrOff(0x587000, 253244))
																						for {
																							if nox_strcmpi(*v3, (*byte)(unsafe.Pointer(&v7))) == 0 {
																								break
																							}
																							v5 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*1))))
																							v4 = (*uint8)(unsafe.Add(unsafe.Pointer(v4), 4))
																							v2++
																							v3 = (**byte)(unsafe.Pointer(v4))
																							if v5 == 0 {
																								break
																							}
																						}
																					}
																					if *memmap.PtrUint32(0x587000, uintptr(v2*4)+253244) != 0 {
																						*(*uint32)(a1) = uint32(v2)
																					} else {
																						*(*uint32)(a1) = 0
																					}
																				}
																			} else {
																				*(*uint32)(unsafe.Add(a1, 52)) = uint32(atoi((*byte)(unsafe.Pointer(&v7))))
																			}
																		} else if nox_strcmpi((*byte)(unsafe.Pointer(&v7)), internCStr("true")) != 0 {
																			*(*uint32)(unsafe.Add(a1, 60)) = 0
																		} else {
																			*(*uint32)(unsafe.Add(a1, 60)) = 1
																		}
																	} else if nox_strcmpi((*byte)(unsafe.Pointer(&v7)), internCStr("true")) != 0 {
																		*(*uint32)(unsafe.Add(a1, 56)) = 0
																	} else {
																		*(*uint32)(unsafe.Add(a1, 56)) = 1
																	}
																} else {
																	*(*uint32)(unsafe.Add(a1, 48)) = uint32(atoi((*byte)(unsafe.Pointer(&v7))))
																}
															} else {
																*(*uint32)(unsafe.Add(a1, 44)) = uint32(atoi((*byte)(unsafe.Pointer(&v7))))
															}
														} else {
															*(*uint32)(unsafe.Add(a1, 76)) = uint32(atoi((*byte)(unsafe.Pointer(&v7))))
														}
													} else {
														*(*uint32)(unsafe.Add(a1, 72)) = uint32(atoi((*byte)(unsafe.Pointer(&v7))))
													}
												} else {
													*(*float32)(unsafe.Add(a1, 64)) = float32(atof((*byte)(unsafe.Pointer(&v7))))
												}
											} else {
												*(*uint32)(unsafe.Add(a1, 40)) = uint32(atoi((*byte)(unsafe.Pointer(&v7))))
											}
										} else {
											*(*uint32)(unsafe.Add(a1, 36)) = uint32(atoi((*byte)(unsafe.Pointer(&v7))))
										}
									} else {
										*(*uint32)(unsafe.Add(a1, 32)) = uint32(atoi((*byte)(unsafe.Pointer(&v7))))
									}
								} else {
									*(*uint32)(unsafe.Add(a1, 28)) = uint32(atoi((*byte)(unsafe.Pointer(&v7))))
								}
							} else {
								*(*uint32)(unsafe.Add(a1, 24)) = uint32(atoi((*byte)(unsafe.Pointer(&v7))))
							}
						} else {
							*(*uint32)(unsafe.Add(a1, 20)) = uint32(atoi((*byte)(unsafe.Pointer(&v7))))
						}
					} else {
						*(*uint32)(unsafe.Add(a1, 16)) = uint32(atoi((*byte)(unsafe.Pointer(&v7))))
					}
				} else {
					*(*uint32)(unsafe.Add(a1, 12)) = uint32(atoi((*byte)(unsafe.Pointer(&v7))))
				}
			} else {
				*(*uint32)(unsafe.Add(a1, 8)) = uint32(atoi((*byte)(unsafe.Pointer(&v7))))
			}
		} else {
			*(*uint32)(unsafe.Add(a1, 4)) = uint32(atoi((*byte)(unsafe.Pointer(&v7))))
		}
	}
	return 0
}
func nox_xxx_genReadSpellSet_51EFB0(a1 int32, a2 *FILE) int32 {
	var v2 int32
	for {
		if nox_xxx_mapGenReadLine_51E540(a2, (*uint8)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
			return 0
		}
		if nox_strcmpi(internCStr("END"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) == 0 || *(*uint32)(unsafe.Add(a1, 1096)) >= 137 {
			break
		}
		v2 = nox_xxx_mapGenSpellIdByName_51E1D0((*byte)(memmap.PtrOff(0x5D4594, 2487264)))
		if v2 != 0 {
			*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(uint32(a1)+func() uint32 {
				p := (*uint32)(unsafe.Add(a1, 1096))
				x := *p
				*p++
				return x
			}()*4)), 548)) = uint32(v2)
		}
	}
	return 1
}
func nox_xxx_genReadWeaponSet_51F030(a1 int32, a2 *FILE) int32 {
	var (
		v2 *byte
		v3 int32
		v4 int32
		i  int32
	)
	dword_5d4594_2487524 = 0
	for {
		if nox_xxx_mapGenReadLine_51E540(a2, (*uint8)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
			return 0
		}
		if nox_strcmpi(internCStr("END"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
			break
		}
		if nox_strcmpi(internCStr("WEAPON"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
			v2 = (*byte)(alloc.Calloc1(1, 0x9C))
			if v2 == nil || nox_xxx_mapGenReadLine_51E540(a2, (*uint8)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
				return 0
			}
			libc.StrCpy((*byte)(unsafe.Add(unsafe.Pointer(v2), 60)), (*byte)(memmap.PtrOff(0x5D4594, 2487264)))
			if nox_strcmpi(internCStr("TEMPLATE"), (*byte)(unsafe.Add(unsafe.Pointer(v2), 60))) != 0 {
				if nox_xxx_mapGenReadLine_51E540(a2, (*uint8)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
					return 0
				}
				libc.StrCpy(v2, (*byte)(memmap.PtrOff(0x5D4594, 2487264)))
			}
			if sub_51F230(int32(uintptr(unsafe.Pointer(v2))), a2) == 0 {
				return 0
			}
			if nox_strcmpi(internCStr("TEMPLATE"), (*byte)(unsafe.Add(unsafe.Pointer(v2), 60))) != 0 {
				*((*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*38))) = 0
				v3 = int32(*(*uint32)(unsafe.Add(a1, 1100)))
				if v3 != 0 {
					for i = int32(*(*uint32)(unsafe.Add(v3, 152))); i != 0; i = int32(*(*uint32)(unsafe.Add(i, 152))) {
						v3 = i
					}
					*(*uint32)(unsafe.Add(v3, 152)) = uint32(uintptr(unsafe.Pointer(v2)))
					*(*uint32)(unsafe.Add(a1, 1104))++
				} else {
					v4 = int32(*(*uint32)(unsafe.Add(a1, 1104)))
					*(*uint32)(unsafe.Add(a1, 1100)) = uint32(uintptr(unsafe.Pointer(v2)))
					*(*uint32)(unsafe.Add(a1, 1104)) = uint32(v4 + 1)
				}
			} else {
				dword_5d4594_2487524 = uint32(uintptr(unsafe.Pointer(v2)))
			}
		}
	}
	if dword_5d4594_2487524 != 0 {
		nox_xxx_mapGenFreeStr_51F1F0(dword_5d4594_2487524)
	}
	dword_5d4594_2487524 = 0
	return 1
}
func nox_xxx_mapGenFreeStr_51F1F0(lpMem unsafe.Pointer) {
	var (
		v1 *byte
		v2 int32
	)
	v1 = (*byte)(unsafe.Add(lpMem, 120))
	v2 = 4
	for {
		if *((*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*4))) != 0 {
			alloc.FreePtr(*(*unsafe.Pointer)(unsafe.Pointer(v1)))
		}
		v1 = (*byte)(unsafe.Add(unsafe.Pointer(v1), 4))
		v2--
		if v2 == 0 {
			break
		}
	}
	alloc.FreePtr(lpMem)
}
func sub_51F230(a1 int32, a2 *FILE) int32 {
	if true {
		panic("FIXME: v55 local var size in invalid, it's unsafe to execute this code!")
	}
	var (
		v2  int32
		v3  int32
		v4  *uint32
		v5  int32
		v6  *int32
		v8  int32
		v9  int32
		v10 int32
		v11 *uint32
		v12 int32
		v13 *byte
		v14 *uint32
		v15 *byte
		v16 int32
		v17 *byte
		v18 int32
		v19 int32
		v20 *byte
		v21 *byte
		v22 int32
		v23 *byte
		v24 bool
		v25 *byte
		v26 *byte
		v27 *byte
		v28 uint32
		v29 int8
		v30 *byte
		v31 *byte
		v32 *byte
		v33 *byte
		v34 int32
		v35 *uint32
		v36 unsafe.Pointer
		v37 int32
		v38 int32
		v39 *byte
		v40 *byte
		v41 *uint32
		v42 *byte
		v43 int32
		v44 *byte
		v46 *uint32
		v47 *byte
		v48 *byte
		v49 *uint32
		v50 *byte
		v51 *byte
		v52 *int32
		v53 *byte
		v54 int32
		v55 int32 // nosemgrep: taking-var-address
		v56 int32
	)
	_ = v56
	var v57 int32
	_ = v57
	var v58 int32
	_ = v58
	var v60 [15360]byte
	var v61 [61440]byte
	v55 = 0
	v56 = 0
	v57 = 0
	v58 = 0
	for {
		if nox_xxx_mapGenReadLine_51E540(a2, (*uint8)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
			return 0
		}
		if nox_strcmpi(internCStr("END"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
			v50 = &v61[0]
			v4 = (*uint32)(unsafe.Add(a1, 120))
			v5 = 16 - a1
			v6 = &v55
			// FIXME: this is definitely invalid! v55 is likely a large array
			v7 := int32(120 - uint32(uintptr(unsafe.Pointer(&v55))))
			v47 = nil
			v52 = &v55
			v49 = (*uint32)(unsafe.Add(a1, 120))
			v54 = 16 - a1
			for i := int32(120 - uint32(uintptr(unsafe.Pointer(&v55)))); ; v7 = i {
				if dword_5d4594_2487524 != 0 {
					v8 = int32(uintptr(unsafe.Pointer(v4))) + v5
					v9 = int32(*(*uint32)(unsafe.Pointer(uintptr(uint32(v8) + dword_5d4594_2487524))))
					if v9 > 0 {
						v10 = int32(*(*uint32)(unsafe.Pointer(uintptr(uint32(v8) + dword_5d4594_2487524))))
						v11 = (*uint32)(unsafe.Add(unsafe.Add(unsafe.Pointer(v6), v7), dword_5d4594_2487524))
						v12 = 0
						v46 = v11
						for {
							v13 = (*byte)(unsafe.Pointer(uintptr(uint32(v12) + *v46)))
							v48 = &v60[v12]
							v12 += 60
							libc.StrCpy(v48, v13)
							v10--
							if v10 == 0 {
								break
							}
						}
					}
					v14 = (*uint32)(unsafe.Pointer(uintptr(*v52)))
					if *v52 > 0 {
						v15 = v50
						v48 = v50
						v46 = v14
						v51 = &v60[v9*60]
						for {
							if *v15 == 45 {
								v16 = 0
								if v9 <= 0 {
									goto LABEL_43
								}
								v17 = &v60[0]
								for nox_strcmpi(v17, (*byte)(unsafe.Add(unsafe.Pointer(v15), 1))) != 0 {
									v16++
									v17 = (*byte)(unsafe.Add(unsafe.Pointer(v17), 60))
									if v16 >= v9 {
										goto LABEL_43
									}
								}
								if v16 >= v9 {
									goto LABEL_43
								}
								v18 = v16 + 1
								if v18 < v9 {
									v19 = v9 - v18
									v20 = &v60[v18*60]
									for {
										v53 = (*byte)(unsafe.Add(unsafe.Pointer(v20), -60))
										v20 = (*byte)(unsafe.Add(unsafe.Pointer(v20), 60))
										libc.StrCpy(v53, v20)
										v19--
										if v19 == 0 {
											break
										}
									}
									v15 = v48
								}
								v9--
								v21 = (*byte)(unsafe.Add(unsafe.Pointer(v51), -60))
							} else {
								v22 = 0
								if v9 > 0 {
									v23 = &v60[0]
									for {
										if nox_strcmpi(v23, v15) == 0 {
											break
										}
										v22++
										v23 = (*byte)(unsafe.Add(unsafe.Pointer(v23), 60))
										if v22 >= v9 {
											break
										}
									}
								}
								if v22 != v9 {
									goto LABEL_43
								}
								v9++
								v21 = (*byte)(unsafe.Add(unsafe.Pointer(libc.StrCpy(v51, v15)), 60))
							}
							v51 = v21
						LABEL_43:
							v15 = (*byte)(unsafe.Add(unsafe.Pointer(v15), 60))
							v24 = uintptr(unsafe.Pointer(v46)) == uintptr(1)
							v48 = v15
							v46 = (*uint32)(unsafe.Add(unsafe.Pointer(v46), -1))
							if v24 {
								break
							}
						}
					}
				} else {
					v9 = *v6
					v24 = *v6 == 0
					if *v6 <= 0 {
						goto LABEL_49
					}
					v25 = v50
					v26 = &v60[0]
					v46 = (*uint32)(v9)
					for {
						v27 = v25
						v25 = (*byte)(unsafe.Add(unsafe.Pointer(v25), 60))
						v28 = uint32(libc.StrLen(v27) + 1)
						v29 = int8(uint8(v28))
						v30 = v27
						v31 = v26
						v26 = (*byte)(unsafe.Add(unsafe.Pointer(v26), 60))
						v28 >>= 2
						alloc.Memcpy(unsafe.Pointer(v31), unsafe.Pointer(v30), uintptr(v28*4))
						v33 = (*byte)(unsafe.Add(unsafe.Pointer(v30), v28*4))
						v32 = (*byte)(unsafe.Add(unsafe.Pointer(v31), v28*4))
						v34 = int32(v29) & 3
						v35 = (*uint32)(unsafe.Add(unsafe.Pointer(v46), -1))
						v24 = uintptr(unsafe.Pointer(v46)) == uintptr(1)
						alloc.Memcpy(unsafe.Pointer(v32), unsafe.Pointer(v33), uintptr(v34))
						v46 = v35
						if v24 {
							break
						}
					}
				}
				v24 = v9 == 0
			LABEL_49:
				if !v24 {
					v36 = alloc.Calloc1(int(v9), 0x3C)
					*v49 = uint32(uintptr(v36))
					if v36 == nil {
						return 0
					}
					if v9 > 0 {
						v37 = 0
						v38 = v9
						for {
							v39 = &v60[v37]
							v40 = (*byte)(unsafe.Pointer(uintptr(uint32(v37) + *v49)))
							v37 += 60
							v53 = libc.StrCpy(v40, v39)
							v38--
							if v38 == 0 {
								break
							}
						}
					}
				}
				v41 = v49
				v42 = v47
				v43 = int32(uintptr(unsafe.Pointer(v52)))
				v44 = v50
				*(*uint32)(unsafe.Add(unsafe.Pointer(v49), 4*4)) = uint32(v9)
				v6 = (*int32)(unsafe.Add(v43, 4))
				v4 = (*uint32)(unsafe.Add(unsafe.Pointer(v41), 4*1))
				v47 = (*byte)(unsafe.Add(unsafe.Pointer(v42), 1))
				v52 = v6
				v49 = v4
				v50 = (*byte)(unsafe.Add(unsafe.Pointer(v44), 15360))
				if int32(uintptr(unsafe.Add(unsafe.Pointer(v42), 1))) >= 4 {
					return 1
				}
				v5 = v54
			}
		}
		if nox_strcmpi(internCStr("EFFECTIVENESS"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 && nox_strcmpi(internCStr("QUALITY"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
			if nox_strcmpi(internCStr("MATERIAL"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
				v2 = 1
				goto LABEL_13
			}
			if nox_strcmpi(internCStr("PRIMARY_ENCHANTMENT"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
				v2 = 2
				goto LABEL_13
			}
			if nox_strcmpi(internCStr("SECONDARY_ENCHANTMENT"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
				v2 = 3
				goto LABEL_13
			}
			return 0
		}
		v2 = 0
	LABEL_13:
		for {
			if nox_xxx_mapGenReadLine_51E540(a2, (*uint8)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
				return 0
			}
			if nox_strcmpi(internCStr("END"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
				break
			}
			v3 = *((*int32)(unsafe.Add(unsafe.Pointer(&v55), 4*uintptr(v2))))
			v47 = &v61[(v3+(v2<<8))*60]
			libc.StrCpy(v47, (*byte)(memmap.PtrOff(0x5D4594, 2487264)))
			*((*int32)(unsafe.Add(unsafe.Pointer(&v55), 4*uintptr(v2)))) = v3 + 1
		}
	}
}
func nox_xxx_genReadArmorSet_51F640(a1 int32, a2 *FILE) int32 {
	var (
		v2 *byte
		v3 int32
		v4 int32
		i  int32
	)
	dword_5d4594_2487524 = 0
	for {
		if nox_xxx_mapGenReadLine_51E540(a2, (*uint8)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
			return 0
		}
		if nox_strcmpi(internCStr("END"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
			break
		}
		if nox_strcmpi(internCStr("ARMOR"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
			v2 = (*byte)(alloc.Calloc1(1, 0x9C))
			if v2 == nil || nox_xxx_mapGenReadLine_51E540(a2, (*uint8)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
				return 0
			}
			libc.StrCpy((*byte)(unsafe.Add(unsafe.Pointer(v2), 60)), (*byte)(memmap.PtrOff(0x5D4594, 2487264)))
			if nox_strcmpi(internCStr("TEMPLATE"), (*byte)(unsafe.Add(unsafe.Pointer(v2), 60))) != 0 {
				if nox_xxx_mapGenReadLine_51E540(a2, (*uint8)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
					return 0
				}
				libc.StrCpy(v2, (*byte)(memmap.PtrOff(0x5D4594, 2487264)))
			}
			if sub_51F230(int32(uintptr(unsafe.Pointer(v2))), a2) == 0 {
				return 0
			}
			if nox_strcmpi(internCStr("TEMPLATE"), (*byte)(unsafe.Add(unsafe.Pointer(v2), 60))) != 0 {
				*((*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*38))) = 0
				v3 = int32(*(*uint32)(unsafe.Add(a1, 1108)))
				if v3 != 0 {
					for i = int32(*(*uint32)(unsafe.Add(v3, 152))); i != 0; i = int32(*(*uint32)(unsafe.Add(i, 152))) {
						v3 = i
					}
					*(*uint32)(unsafe.Add(v3, 152)) = uint32(uintptr(unsafe.Pointer(v2)))
					*(*uint32)(unsafe.Add(a1, 1112))++
				} else {
					v4 = int32(*(*uint32)(unsafe.Add(a1, 1112)))
					*(*uint32)(unsafe.Add(a1, 1108)) = uint32(uintptr(unsafe.Pointer(v2)))
					*(*uint32)(unsafe.Add(a1, 1112)) = uint32(v4 + 1)
				}
			} else {
				dword_5d4594_2487524 = uint32(uintptr(unsafe.Pointer(v2)))
			}
		}
	}
	if dword_5d4594_2487524 != 0 {
		nox_xxx_mapGenFreeStr_51F1F0(dword_5d4594_2487524)
	}
	dword_5d4594_2487524 = 0
	return 1
}
func nox_xxx_genReadExit_51F800(a1 int32, a2 *FILE) int32 {
	for {
		if nox_xxx_mapGenReadLine_51E540(a2, (*uint8)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
			return 0
		}
		if nox_strcmpi(internCStr("END"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
			break
		}
		if nox_strcmpi(internCStr("OBJECT"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
			if nox_strcmpi(internCStr("LINKDATA"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 || nox_xxx_mapGenReadLine_51E540(a2, (*uint8)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
				return 0
			}
			libc.StrCpy((*byte)(unsafe.Add(a1, 476)), (*byte)(memmap.PtrOff(0x5D4594, 2487264)))
		} else {
			if nox_xxx_mapGenReadLine_51E540(a2, (*uint8)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
				return 0
			}
			libc.StrCpy((*byte)(unsafe.Pointer(uintptr(uint32(a1+216)+(*(*uint32)(unsafe.Add(a1, 472))<<6)))), (*byte)(memmap.PtrOff(0x5D4594, 2487264)))
			if nox_xxx_mapGenReadLine_51E540(a2, (*uint8)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
				return 0
			}
			if nox_strcmpi(internCStr("NORTH"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
				if nox_strcmpi(internCStr("SOUTH"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
					if nox_strcmpi(internCStr("EAST"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
						if nox_strcmpi(internCStr("WEST"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
							*(*uint32)(unsafe.Add(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(a1, 472))<<6)+uint32(a1))), 216), 60)) = 3
						}
						*(*uint32)(unsafe.Add(a1, 472))++
					} else {
						*(*uint32)(unsafe.Add(unsafe.Add(unsafe.Pointer(uintptr((func() uint32 {
							p := (*uint32)(unsafe.Add(a1, 472))
							x := *p
							*p++
							return x
						}()<<6)+uint32(a1))), 216), 60)) = 2
					}
				} else {
					*(*uint32)(unsafe.Add(unsafe.Add(unsafe.Pointer(uintptr((func() uint32 {
						p := (*uint32)(unsafe.Add(a1, 472))
						x := *p
						*p++
						return x
					}()<<6)+uint32(a1))), 216), 60)) = 1
				}
			} else {
				*(*uint32)(unsafe.Add(unsafe.Add(unsafe.Pointer(uintptr((func() uint32 {
					p := (*uint32)(unsafe.Add(a1, 472))
					x := *p
					*p++
					return x
				}()<<6)+uint32(a1))), 216), 60)) = 0
			}
		}
	}
	return 1
}
func nox_xxx_genReadDecor_51F9F0(a1 *uint32, a2 *FILE) int32 {
	var (
		v2     *uint8
		v3     int32
		v4     *FILE
		v5     int32
		v6     int32
		v7     **byte
		v8     *uint8
		v9     int32
		v10    int32
		result int32
		v12    int32
		v13    int32
		v14    int32
		v15    *byte
	)
	v15 = nil
	v2 = (*uint8)(alloc.Calloc1(1, 0xE0))
	v3 = int32(uintptr(unsafe.Pointer(v2)))
	if v2 == nil {
		return 0
	}
	v4 = a2
	*(*uint8)(unsafe.Add(unsafe.Pointer(v2), 64)) = 0
	*((*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*18))) = 1000
	*((*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*19))) = 0
	*((*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*20))) = 999999
	if nox_xxx_mapGenReadLine_51E540(a2, (*uint8)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
		return 0
	}
	if nox_xxx_mapGenReadLine_51E540(a2, (*uint8)(v3)) == 0 {
		return 0
	}
	if nox_strcmpi(internCStr("ROOM"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
		*(*uint32)(unsafe.Add(v3, 60)) = 0
	} else if nox_strcmpi(internCStr("HALL"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
		*(*uint32)(unsafe.Add(v3, 60)) = 1
	} else if nox_strcmpi(internCStr("TEMPLATE"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
		*(*uint32)(unsafe.Add(v3, 60)) = 2
	} else if nox_strcmpi(internCStr("BACKDROP"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
		*(*uint32)(unsafe.Add(v3, 60)) = 3
	} else {
		return 0
	}
	for {
		if nox_xxx_mapGenReadLine_51E540(v4, (*uint8)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
			return 0
		}
		if nox_strcmpi(internCStr("END"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
			switch *(*uint32)(unsafe.Add(v3, 60)) {
			case 0:
				*(*uint32)(unsafe.Add(v3, 220)) = *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*22))
				v10 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*23)))
				*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*22)) = uint32(v3)
				*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*23)) = uint32(v10 + 1)
				result = 1
			case 1:
				*(*uint32)(unsafe.Add(v3, 220)) = *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*30))
				v12 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*31)))
				*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*30)) = uint32(v3)
				*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*31)) = uint32(v12 + 1)
				result = 1
			case 2:
				*(*uint32)(unsafe.Add(v3, 220)) = *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*38))
				v13 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*39)))
				*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*38)) = uint32(v3)
				*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*39)) = uint32(v13 + 1)
				result = 1
			case 3:
				*(*uint32)(unsafe.Add(v3, 220)) = *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*46))
				v14 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*47)) + 1)
				*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*46)) = uint32(v3)
				*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*47)) = uint32(v14)
				result = 1
			default:
				result = 1
			}
			return result
		}
		if nox_strcmpi(internCStr("WALL_FLOOR"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
			if nox_strcmpi(internCStr("OCCUR_CONSTRAINT"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
				if nox_strcmpi(internCStr("OCCUR_LIMIT"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
					if nox_strcmpi(internCStr("MUST_OCCUR"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
						if nox_strcmpi(internCStr("FREQUENCY"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
							if nox_strcmpi(internCStr("DOOR"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
								if nox_strcmpi(internCStr("DOUBLE_DOOR"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
									if nox_strcmpi(internCStr("ROOM_SIZE_CONSTRAINT"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
										if nox_strcmpi(internCStr("COPY"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
											if nox_strcmpi(internCStr("DECOR_SET"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
												v5 = 0
												v6 = 0
												if *memmap.PtrUint32(0x587000, 253200) == 0 {
													return 0
												}
												v7 = (**byte)(memmap.PtrOff(0x587000, 253200))
												v8 = (*uint8)(memmap.PtrOff(0x587000, 253200))
												for {
													if nox_strcmpi(*v7, (*byte)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
														if v15 == nil || sub_51FEC0(int32(uintptr(unsafe.Pointer(v15))), v6, a2) == 0 {
															return 0
														}
														v5 = 1
													}
													v9 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*1))))
													v8 = (*uint8)(unsafe.Add(unsafe.Pointer(v8), 4))
													v6++
													v7 = (**byte)(unsafe.Pointer(v8))
													if v9 == 0 {
														break
													}
												}
												if v5 == 0 {
													return 0
												}
												v4 = a2
											} else if nox_xxx_genDecorReadDecorSet_51FFA0(v3, v4) == 0 {
												return 0
											}
										} else if nox_xxx_genDecorReadCopy_520660(a1, (*byte)(v3), v4) == 0 {
											return 0
										}
									} else if nox_xxx_genDecorReadRoomSizeCon_5209F0(v3, v4) == 0 {
										return 0
									}
								} else if nox_xxx_genDecorReadDoubleDoor_520AB0(v3, v4) == 0 {
									return 0
								}
							} else if nox_xxx_genDecorReadDoor_520A90(v3, v4) == 0 {
								return 0
							}
						} else if nox_xxx_genDecorReadFrequency_520910(v3, v4) == 0 {
							return 0
						}
					} else {
						*(*uint8)(unsafe.Add(v3, 67)) = 1
					}
				} else if nox_xxx_genDecorReadOccurLimit_5208D0(v3, v4) == 0 {
					return 0
				}
			} else if nox_xxx_genDecorReadOccurConstraint_520810(v3, v4) == 0 {
				return 0
			}
		} else {
			v15 = nox_xxx_genDecorReadWallFloor_51FE00(v3, v4)
			if v15 == nil {
				return 0
			}
		}
	}
	return 0
}
func nox_xxx_genDecorReadWallFloor_51FE00(a1 int32, a2 *FILE) *byte {
	var (
		result *byte
		v3     *byte
		v4     int32
	)
	result = (*byte)(alloc.Calloc1(1, 0x80))
	v3 = result
	if result != nil {
		result = (*byte)(unsafe.Pointer(uintptr(nox_xxx_mapGenReadLine_51E540(a2, (*uint8)(memmap.PtrOff(0x5D4594, 2487264))))))
		if result != nil {
			libc.StrCpy(v3, (*byte)(memmap.PtrOff(0x5D4594, 2487264)))
			result = (*byte)(unsafe.Pointer(uintptr(nox_xxx_mapGenReadLine_51E540(a2, (*uint8)(memmap.PtrOff(0x5D4594, 2487264))))))
			if result != nil {
				libc.StrCpy((*byte)(unsafe.Add(unsafe.Pointer(v3), 60)), (*byte)(memmap.PtrOff(0x5D4594, 2487264)))
				*((*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*31))) = *(*uint32)(unsafe.Add(a1, 84))
				v4 = int32(*(*uint32)(unsafe.Add(a1, 88)) + 1)
				*(*uint32)(unsafe.Add(a1, 84)) = uint32(uintptr(unsafe.Pointer(v3)))
				*(*uint32)(unsafe.Add(a1, 88)) = uint32(v4)
				result = v3
			}
		}
	}
	return result
}
func sub_51FEC0(a1 int32, a2 int32, a3 *FILE) int32 {
	var (
		result int32
		v4     int32
		v5     int32
		i      int32
	)
	result = int32(uintptr(alloc.Calloc1(1, 0x80)))
	v4 = result
	if result != 0 {
		*(*uint32)(result) = uint32(a2)
		result = nox_xxx_mapGenReadLine_51E540(a3, (*uint8)(memmap.PtrOff(0x5D4594, 2487264)))
		if result != 0 {
			libc.StrCpy((*byte)(unsafe.Add(v4, 4)), (*byte)(memmap.PtrOff(0x5D4594, 2487264)))
			result = nox_xxx_mapGenReadLine_51E540(a3, (*uint8)(memmap.PtrOff(0x5D4594, 2487264)))
			if result != 0 {
				libc.StrCpy((*byte)(unsafe.Add(v4, 64)), (*byte)(memmap.PtrOff(0x5D4594, 2487264)))
				v5 = int32(*(*uint32)(unsafe.Add(a1, 120)))
				if v5 != 0 {
					for i = int32(*(*uint32)(unsafe.Add(v5, 124))); i != 0; i = int32(*(*uint32)(unsafe.Add(i, 124))) {
						v5 = i
					}
					*(*uint32)(unsafe.Add(v5, 124)) = uint32(v4)
					result = 1
				} else {
					*(*uint32)(unsafe.Add(a1, 120)) = uint32(v4)
					result = 1
				}
			}
		}
	}
	return result
}
func nox_xxx_genDecorReadDecorSet_51FFA0(a1 int32, a2 *FILE) int32 {
	var (
		v2     int32
		result int32
		v4     *int32
		v5     *uint32
		v6     *uint32
		v7     *uint32
		v8     int32
		v9     int32
		v10    int32
		i      int32
		v12    int32
	)
	v2 = 0
	result = int32(uintptr(alloc.Calloc1(1, 0x18)))
	v4 = (*int32)(result)
	v12 = result
	if result == 0 {
		return 0
	}
	result = nox_xxx_mapGenReadLine_51E540(a2, (*uint8)(memmap.PtrOff(0x5D4594, 2487264)))
	if result == 0 {
		return 0
	}
	*v4 = int32(libc.Atoi(libc.GoString((*byte)(memmap.PtrOff(0x5D4594, 2487264)))))
	result = nox_xxx_mapGenReadLine_51E540(a2, (*uint8)(memmap.PtrOff(0x5D4594, 2487264)))
	if result == 0 {
		return 0
	}
	*(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*1)) = int32(libc.Atoi(libc.GoString((*byte)(memmap.PtrOff(0x5D4594, 2487264)))))
	for {
		for {
			if nox_xxx_mapGenReadLine_51E540(a2, (*uint8)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
				return 0
			}
			if nox_strcmpi(internCStr("END"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
				v10 = int32(*(*uint32)(unsafe.Add(a1, 92)))
				if v10 != 0 {
					for i = int32(*(*uint32)(unsafe.Add(v10, 20))); i != 0; i = int32(*(*uint32)(unsafe.Add(i, 20))) {
						v10 = i
					}
					*(*uint32)(unsafe.Add(v10, 20)) = uint32(uintptr(unsafe.Pointer(v4)))
				} else {
					*(*uint32)(unsafe.Add(a1, 92)) = uint32(uintptr(unsafe.Pointer(v4)))
				}
				*(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*5)) = 0
				*(*uint32)(unsafe.Add(a1, 96))++
				return 1
			}
			if nox_strcmpi(internCStr("FOREACH"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
				break
			}
			if v2 == 0 {
				return 0
			}
			if *(*uint32)(v2) != 1 {
				return 0
			}
			v5 = nox_xxx_gen_5205B0(a2)
			if v5 == nil {
				return 0
			}
			*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*2)) = *(*uint32)(unsafe.Add(v2, 84))
			*(*uint32)(unsafe.Add(v2, 84)) = uint32(uintptr(unsafe.Pointer(v5)))
		}
		if nox_strcmpi(internCStr("CONTAINS"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
			if v2 != 0 {
				if *(*uint32)(v2) == 0 {
					v6 = nox_xxx_gen_520380(a2)
					*(*uint32)(unsafe.Add(v2, 80)) = uint32(uintptr(unsafe.Pointer(v6)))
					if v6 != nil {
						continue
					}
				}
			}
			return 0
		}
		v7 = (*uint32)(alloc.Calloc1(1, 0x64))
		v2 = int32(uintptr(unsafe.Pointer(v7)))
		if v7 == nil {
			return 0
		}
		*v7 = 0
		if *memmap.PtrUint32(0x587000, 253216) != 0 {
			for {
				if nox_strcmpi(*(**byte)(memmap.PtrOff(0x587000, uintptr(*(*uint32)(v2))*4+253216)), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
					break
				}
				v8 = int32(*(*uint32)(v2) + 1)
				*(*uint32)(v2) = uint32(v8)
				if *memmap.PtrUint32(0x587000, uintptr(v8*4)+253216) == 0 {
					break
				}
			}
		}
		if *memmap.PtrUint32(0x587000, uintptr(*(*uint32)(v2))*4+253216) == 0 {
			alloc.FreePtr(v2)
			return 0
		}
		switch *(*uint32)(v2) {
		case 0, 1:
			if nox_xxx_mapGenReadLine_51E540(a2, (*uint8)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
				alloc.FreePtr(v2)
				return 0
			}
			libc.StrCpy((*byte)(unsafe.Add(v2, 4)), (*byte)(memmap.PtrOff(0x5D4594, 2487264)))
			if nox_xxx_mapGenReadLine_51E540(a2, (*uint8)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
				alloc.FreePtr(v2)
				return 0
			}
			if nox_strcmpi(internCStr("DENSITY"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
				*(*uint32)(unsafe.Add(v2, 64)) = 0
				*(*uint32)(unsafe.Add(v2, 68)) = uint32(libc.Atoi(libc.GoString((*byte)(memmap.PtrOff(0x5D4594, 2487264)))))
				if nox_xxx_mapGenReadLine_51E540(a2, (*uint8)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
					alloc.FreePtr(v2)
					return 0
				}
				*(*uint32)(unsafe.Add(v2, 72)) = uint32(libc.Atoi(libc.GoString((*byte)(memmap.PtrOff(0x5D4594, 2487264)))))
				v4 = (*int32)(v12)
				goto LABEL_39
			}
			*(*uint32)(unsafe.Add(v2, 64)) = 1
			if nox_xxx_mapGenReadLine_51E540(a2, (*uint8)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
				*(*float32)(unsafe.Add(v2, 76)) = float32(libc.Atof(libc.GoString((*byte)(memmap.PtrOff(0x5D4594, 2487264)))))
				if nox_xxx_mapGenReadLine_51E540(a2, (*uint8)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
					if libc.StrCmp(internCStr("*"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
						*(*uint32)(unsafe.Add(v2, 68)) = 0
					} else {
						*(*uint32)(unsafe.Add(v2, 68)) = uint32(libc.Atoi(libc.GoString((*byte)(memmap.PtrOff(0x5D4594, 2487264)))))
					}
					if nox_xxx_mapGenReadLine_51E540(a2, (*uint8)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
						if libc.StrCmp(internCStr("*"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
							*(*uint32)(unsafe.Add(v2, 72)) = 999999
						} else {
							*(*uint32)(unsafe.Add(v2, 72)) = uint32(libc.Atoi(libc.GoString((*byte)(memmap.PtrOff(0x5D4594, 2487264)))))
						}
						v4 = (*int32)(v12)
						goto LABEL_39
					}
				}
			}
			alloc.FreePtr(v2)
			return 0
		case 3, 4, 5:
			if nox_xxx_mapGenReadLine_51E540(a2, (*uint8)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
				alloc.FreePtr(v2)
				return 0
			}
			libc.StrCpy((*byte)(unsafe.Add(v2, 4)), (*byte)(memmap.PtrOff(0x5D4594, 2487264)))
			v4 = (*int32)(v12)
		default:
		}
	LABEL_39:
		*(*uint32)(unsafe.Add(v2, 88)) = uint32(*(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*2)))
		v9 = *(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*3)) + 1
		*(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*2)) = v2
		*(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*3)) = v9
	}
}
func nox_xxx_gen_520380(a1 *FILE) *uint32 {
	var (
		v1  *uint32
		v2  *uint32
		v3  int32
		v4  int32
		v5  **byte
		v6  *uint8
		v7  int32
		v8  int32
		v9  *uint32
		i   *uint32
		v11 *uint32
		v13 *uint32
		v14 *uint32
		v15 int32
		v16 int32
		v17 int32
	)
	v1 = nil
	v17 = 0
	v15 = 0
	v16 = 100
LABEL_2:
	v2 = (*uint32)(alloc.Calloc1(1, 0x80C))
	if v2 != nil && nox_xxx_mapGenReadLine_51E540(a1, (*uint8)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
		if libc.StrCmp(internCStr("*"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
			*v2 = math.MaxUint32
			v15++
		} else {
			v3 = int32(libc.Atoi(libc.GoString((*byte)(memmap.PtrOff(0x5D4594, 2487264)))))
			*v2 = uint32(v3)
			v16 -= v3
		}
		for nox_xxx_mapGenReadLine_51E540(a1, (*uint8)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
			if nox_strcmpi(internCStr("END"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
				v17 = 1
			} else if nox_strcmpi(internCStr("OR"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
			} else {
				goto LABEL_A
			}
			if v1 != nil {
				v9 = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v1), 4*514)))
				for i = v1; v9 != nil; v9 = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v9), 4*514))) {
					i = v9
				}
				*(*uint32)(unsafe.Add(unsafe.Pointer(i), 4*514)) = uint32(uintptr(unsafe.Pointer(v2)))
			} else {
				v1 = v2
			}
			if v17 != 0 {
				if v15 != 0 {
					v11 = v1
					for {
						if int32(*v11) < 0 {
							*v11 = uint32(v16/v15 + 1)
						}
						v11 = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v11), 4*514)))
						if v11 == nil {
							break
						}
					}
				}
				return v1
			}
			goto LABEL_2
		LABEL_A:
			v4 = 0
			if *memmap.PtrUint32(0x587000, 253216) != 0 {
				v5 = (**byte)(memmap.PtrOff(0x587000, 253216))
				v6 = (*uint8)(memmap.PtrOff(0x587000, 253216))
				for {
					if nox_strcmpi(*v5, (*byte)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
						break
					}
					v7 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*1))))
					v6 = (*uint8)(unsafe.Add(unsafe.Pointer(v6), 4))
					v4++
					v5 = (**byte)(unsafe.Pointer(v6))
					if v7 == 0 {
						break
					}
				}
			}
			if *memmap.PtrUint32(0x587000, uintptr(v4*4)+253216) == 0 {
				alloc.Free(v2)
				break
			}
			*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*513))*16+1))) = uint32(v4)
			if nox_xxx_mapGenReadLine_51E540(a1, (*uint8)(unsafe.Add(unsafe.Pointer(v2), 4*uintptr(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*513))*16+2)))) == 0 {
				break
			}
			v8 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*513)) + 1)
			*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*513)) = uint32(v8)
			if v8 >= 32 {
				*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*513)) = 31
			}
		}
	}
	v13 = v1
	if v1 != nil {
		for {
			v14 = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v13), 4*514)))
			alloc.Free(v13)
			v13 = v14
			if v14 == nil {
				break
			}
		}
	}
	return nil
}
func nox_xxx_gen_5205B0(a1 *FILE) *uint32 {
	var (
		result *uint32
		v2     *uint32
		v3     *uint32
	)
	result = (*uint32)(unsafe.Pointer(uintptr(nox_xxx_mapGenReadLine_51E540(a1, (*uint8)(memmap.PtrOff(0x5D4594, 2487264))))))
	if result != nil {
		result = (*uint32)(alloc.Calloc1(1, 0xC))
		v2 = result
		if result != nil {
			*result = uint32(nox_xxx_getNameId_4E3AA0((*byte)(memmap.PtrOff(0x5D4594, 2487264))))
			if nox_xxx_mapGenReadLine_51E540(a1, (*uint8)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
				if nox_strcmpi(internCStr("CONTAINS"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
					alloc.Free(v2)
					result = nil
				} else {
					v3 = nox_xxx_gen_520380(a1)
					*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*1)) = uint32(uintptr(unsafe.Pointer(v3)))
					if v3 != nil {
						result = v2
					} else {
						alloc.Free(v2)
						result = nil
					}
				}
			} else {
				alloc.Free(v2)
				result = nil
			}
		}
	}
	return result
}
func nox_xxx_genDecorReadCopy_520660(a1 *uint32, a2 *byte, a3 *FILE) int32 {
	var (
		result int32
		v4     int32
		v5     int32
		v6     *byte
		v7     *byte
		i      *uint32
		v9     *uint32
		v10    int32
		v11    *uint32
		j      *uint32
		k      *uint32
		v14    *uint32
		v15    int32
	)
	result = nox_xxx_mapGenReadLine_51E540(a3, (*uint8)(memmap.PtrOff(0x5D4594, 2487264)))
	if result == 0 {
		return 0
	}
	v4 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*15))))
	if v4 != 0 {
		v5 = v4 - 1
		if v5 != 0 {
			if v5 == 1 {
				v6 = (*byte)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*38)))
			} else {
				v6 = a2
			}
		} else {
			v6 = (*byte)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*30)))
		}
	} else {
		v6 = (*byte)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*22)))
	}
	v7 = v6
	if v6 != nil {
		for libc.StrCmp(v7, (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
			v7 = (*byte)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*55))))))
			if v7 == nil {
				break
			}
		}
	}
	if v7 == nil {
		v7 = (*byte)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*38)))
		if v7 == nil {
			return 0
		}
		for libc.StrCmp(v7, (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
			v7 = (*byte)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*55))))))
			if v7 == nil {
				return 0
			}
		}
	}
	for i = (*uint32)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*21)))))); i != nil; i = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(i), 4*31))) {
		v9 = (*uint32)(alloc.Calloc1(1, 0x80))
		if v9 == nil {
			return 0
		}
		alloc.Memcpy(unsafe.Pointer(v9), unsafe.Pointer(i), 0x80)
		*(*uint32)(unsafe.Add(unsafe.Pointer(v9), 4*31)) = *((*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*21)))
		v10 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*22))) + 1)
		*((*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*21))) = uint32(uintptr(unsafe.Pointer(v9)))
		*((*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*22))) = uint32(v10)
	}
	v11 = (*uint32)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*23))))))
	if v11 != nil {
		for j = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v11), 4*5))); j != nil; j = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(j), 4*5))) {
			v11 = j
		}
	}
	for k = (*uint32)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*23)))))); k != nil; v11 = v14 {
		v14 = (*uint32)(alloc.Calloc1(1, 0x18))
		if v14 == nil {
			return 0
		}
		v15 = 1
		alloc.Memcpy(unsafe.Pointer(v14), unsafe.Pointer(k), 0x18)
		*(*uint32)(unsafe.Add(unsafe.Pointer(v14), 4*4)) = 1
		*(*uint32)(unsafe.Add(unsafe.Pointer(v14), 4*5)) = 0
		if v11 != nil {
			*(*uint32)(unsafe.Add(unsafe.Pointer(v11), 4*5)) = uint32(uintptr(unsafe.Pointer(v14)))
			v15 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*24))) + 1)
		} else {
			*((*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*23))) = uint32(uintptr(unsafe.Pointer(v14)))
		}
		*((*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*24))) = uint32(v15)
		k = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(k), 4*5)))
	}
	return 1
}
func nox_xxx_genDecorReadOccurConstraint_520810(a1 int32, a2 *FILE) int32 {
	var (
		v3 *byte
		v4 int32
		v5 **byte
		v6 *uint8
		v7 int32
	)
	*(*uint8)(unsafe.Add(a1, 64)) = 0
	if nox_xxx_mapGenReadLine_51E540(a2, (*uint8)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
		return 0
	}
	if nox_strcmpi(internCStr("NONE"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
		v3 = libc.StrTok((*byte)(memmap.PtrOff(0x5D4594, 2487264)), internCStr("+"))
		if v3 != nil {
			for {
				v4 = 0
				if *memmap.PtrUint32(0x587000, 253144) != 0 {
					v5 = (**byte)(memmap.PtrOff(0x587000, 253144))
					v6 = (*uint8)(memmap.PtrOff(0x587000, 253144))
					for {
						if nox_strcmpi(*v5, v3) == 0 {
							break
						}
						v7 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*1))))
						v6 = (*uint8)(unsafe.Add(unsafe.Pointer(v6), 4))
						v4++
						v5 = (**byte)(unsafe.Pointer(v6))
						if v7 == 0 {
							break
						}
					}
				}
				if *memmap.PtrUint32(0x587000, uintptr(v4*4)+253144) == 0 {
					break
				}
				*(*uint8)(unsafe.Add(a1, 64)) |= uint8(int8(1 << v4))
				v3 = libc.StrTok(nil, internCStr("+"))
				if v3 == nil {
					return 1
				}
			}
			return 0
		}
	}
	return 1
}
func nox_xxx_genDecorReadOccurLimit_5208D0(a1 int32, a2 *FILE) int32 {
	var result int32
	result = nox_xxx_mapGenReadLine_51E540(a2, (*uint8)(memmap.PtrOff(0x5D4594, 2487264)))
	if result != 0 {
		*(*uint8)(unsafe.Add(a1, 65)) = uint8(int8(libc.Atoi(libc.GoString((*byte)(memmap.PtrOff(0x5D4594, 2487264))))))
		result = 1
	}
	return result
}
func nox_xxx_genDecorReadFrequency_520910(a1 int32, a2 *FILE) int32 {
	var result int32
	result = nox_xxx_mapGenReadLine_51E540(a2, (*uint8)(memmap.PtrOff(0x5D4594, 2487264)))
	if result != 0 {
		if nox_strcmpi(internCStr("COMMON"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
			if nox_strcmpi(internCStr("UNCOMMON"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
				if nox_strcmpi(internCStr("RARE"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
					if nox_strcmpi(internCStr("VERY_RARE"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
						if nox_strcmpi(internCStr("HARDLY_EVER"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
							*(*uint32)(unsafe.Add(a1, 72)) = 1
						}
						result = 1
					} else {
						result = 1
						*(*uint32)(unsafe.Add(a1, 72)) = 10
					}
				} else {
					*(*uint32)(unsafe.Add(a1, 72)) = 100
					result = 1
				}
			} else {
				result = 1
				*(*uint32)(unsafe.Add(a1, 72)) = 500
			}
		} else {
			result = 1
			*(*uint32)(unsafe.Add(a1, 72)) = 1000
		}
	}
	return result
}
func nox_xxx_genDecorReadRoomSizeCon_5209F0(a1 int32, a2 *FILE) int32 {
	var result int32
	result = nox_xxx_mapGenReadLine_51E540(a2, (*uint8)(memmap.PtrOff(0x5D4594, 2487264)))
	if result != 0 {
		if nox_strcmpi(internCStr("*"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
			*(*uint32)(unsafe.Add(a1, 76)) = uint32(libc.Atoi(libc.GoString((*byte)(memmap.PtrOff(0x5D4594, 2487264)))))
		} else {
			*(*uint32)(unsafe.Add(a1, 76)) = 0
		}
		result = nox_xxx_mapGenReadLine_51E540(a2, (*uint8)(memmap.PtrOff(0x5D4594, 2487264)))
		if result != 0 {
			if nox_strcmpi(internCStr("*"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
				*(*uint32)(unsafe.Add(a1, 80)) = uint32(libc.Atoi(libc.GoString((*byte)(memmap.PtrOff(0x5D4594, 2487264)))))
			} else {
				*(*uint32)(unsafe.Add(a1, 80)) = 999999
			}
			result = 1
		}
	}
	return result
}
func nox_xxx_genDecorReadDoor_520A90(a1 int32, a2 *FILE) int32 {
	return bool2int32(nox_xxx_mapGenReadLine_51E540(a2, (*uint8)(unsafe.Add(a1, 100))) != 0)
}
func nox_xxx_genDecorReadDoubleDoor_520AB0(a1 int32, a2 *FILE) int32 {
	return bool2int32(nox_xxx_mapGenReadLine_51E540(a2, (*uint8)(unsafe.Add(a1, 160))) != 0)
}
func nox_xxx_mapgenCheckSettings_520AD0(a1 *int32) int32 {
	var v1 int32
	v1 = *a1
	*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*2)) = 0
	*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*3)) = 0
	*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*4)) = 0
	*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*5)) = 0
	*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*6)) = 0
	for *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*7)) = 0; v1 != 0; v1 = int32(*(*uint32)(unsafe.Add(v1, 220))) {
		if int32(*(*uint8)(unsafe.Add(v1, 64))) == 0 {
			*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*2)) += int32(*(*uint32)(unsafe.Add(v1, 72)))
			*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*3)) += int32(*(*uint32)(unsafe.Add(v1, 72)))
			*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*4)) += int32(*(*uint32)(unsafe.Add(v1, 72)))
			*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*5)) += int32(*(*uint32)(unsafe.Add(v1, 72)))
			*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*6)) += int32(*(*uint32)(unsafe.Add(v1, 72)))
			*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*7)) += int32(*(*uint32)(unsafe.Add(v1, 72)))
		}
		if int32(*(*uint8)(unsafe.Add(v1, 64)))&1 != 0 {
			*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*2)) += int32(*(*uint32)(unsafe.Add(v1, 72)))
		}
		if int32(*(*uint8)(unsafe.Add(v1, 64)))&2 != 0 {
			*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*3)) += int32(*(*uint32)(unsafe.Add(v1, 72)))
		}
		if int32(*(*uint8)(unsafe.Add(v1, 64)))&4 != 0 {
			*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*4)) += int32(*(*uint32)(unsafe.Add(v1, 72)))
		}
		if int32(*(*uint8)(unsafe.Add(v1, 64)))&8 != 0 {
			*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*5)) += int32(*(*uint32)(unsafe.Add(v1, 72)))
		}
		if int32(*(*uint8)(unsafe.Add(v1, 64)))&0x10 != 0 {
			*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*6)) += int32(*(*uint32)(unsafe.Add(v1, 72)))
		}
		if int32(*(*uint8)(unsafe.Add(v1, 64)))&0x20 != 0 {
			*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*7)) += int32(*(*uint32)(unsafe.Add(v1, 72)))
		}
	}
	if *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*2)) == 0 {
		return 0
	}
	if *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*3)) == 0 {
		return 0
	}
	if *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*4)) == 0 {
		return 0
	}
	if *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*5)) == 0 {
		return 0
	}
	if *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*6)) != 0 {
		return bool2int32(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*7)) != 0)
	}
	return 0
}
func nox_xxx_genReadPrefab_520BF0(a1 int32, a2 *FILE) int32 {
	var (
		v2 *byte
		v3 int32
		v4 *byte
		v5 *uint32
	)
	v2 = nil
	v3 = 0
	for nox_xxx_mapGenReadLine_51E540(a2, (*uint8)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
		if nox_strcmpi(internCStr("END"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
			return 1
		}
		if nox_strcmpi(internCStr("AREAMAP"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
			if nox_strcmpi(internCStr("MUST_OCCUR"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) != 0 {
				if nox_strcmpi(internCStr("FOREACH"), (*byte)(memmap.PtrOff(0x5D4594, 2487264))) == 0 {
					if v2 == nil {
						return 0
					}
					v5 = nox_xxx_gen_5205B0(a2)
					if v5 == nil {
						return 0
					}
					*(*uint32)(unsafe.Add(unsafe.Pointer(v5), 4*2)) = *((*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*38)))
					*((*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*38))) = uint32(uintptr(unsafe.Pointer(v5)))
				}
			} else {
				v3 = 1
			}
		} else {
			v4 = sub_520CE0(a1, a2)
			v2 = v4
			if v4 == nil {
				return 0
			}
			if v3 != 0 {
				*((*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*18))) = 1
				v3 = 0
			}
		}
	}
	return 0
}
func sub_520CE0(a1 int32, a2 *FILE) *byte {
	var (
		result *byte
		v3     int32
	)
	result = (*byte)(unsafe.Pointer(uintptr(nox_xxx_mapGenReadLine_51E540(a2, (*uint8)(memmap.PtrOff(0x5D4594, 2487264))))))
	if result != nil {
		result = (*byte)(alloc.Calloc1(1, 0xA0))
		if result != nil {
			libc.StrCpy(result, (*byte)(memmap.PtrOff(0x5D4594, 2487264)))
			*((*uint32)(unsafe.Add(unsafe.Pointer(result), 4*39))) = *(*uint32)(unsafe.Add(a1, 80))
			v3 = int32(*(*uint32)(unsafe.Add(a1, 84)) + 1)
			*(*uint32)(unsafe.Add(a1, 80)) = uint32(uintptr(unsafe.Pointer(result)))
			*(*uint32)(unsafe.Add(a1, 84)) = uint32(v3)
		}
	}
	return result
}
func sub_520D50(a1 *uint32) *uint32 {
	var (
		v1     *uint32
		v2     *uint32
		v3     *uint32
		v4     *uint32
		v5     *uint32
		v6     *uint32
		v7     *uint32
		v8     *uint32
		result *uint32
		v10    *uint32
	)
	v1 = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*22)))
	if v1 != nil {
		for {
			v2 = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v1), 4*55)))
			alloc.Free(v1)
			v1 = v2
			if v2 == nil {
				break
			}
		}
	}
	v3 = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*30)))
	if v3 != nil {
		for {
			v4 = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v3), 4*55)))
			alloc.Free(v3)
			v3 = v4
			if v4 == nil {
				break
			}
		}
	}
	v5 = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*275)))
	if v5 != nil {
		for {
			v6 = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v5), 4*38)))
			nox_xxx_mapGenFreeStr_51F1F0(unsafe.Pointer(v5))
			v5 = v6
			if v6 == nil {
				break
			}
		}
	}
	v7 = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*277)))
	if v7 != nil {
		for {
			v8 = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v7), 4*38)))
			nox_xxx_mapGenFreeStr_51F1F0(unsafe.Pointer(v7))
			v7 = v8
			if v8 == nil {
				break
			}
		}
	}
	result = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*20)))
	if result != nil {
		for {
			v10 = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(result), 4*39)))
			alloc.Free(result)
			result = v10
			if v10 == nil {
				break
			}
		}
	}
	return result
}
func nox_xxx_mapGenRoundFloatToPtr_520DF0(a1 *types.Pointf, a2 *uint32) int64 {
	var (
		v2     float64
		v3     float64
		result int64
	)
	if float64(a1.X) >= 0.0 {
		v2 = 0.5
	} else {
		v2 = -0.5
	}
	*a2 = uint32(int32(int64(float64(a1.X)*0.030743772 + v2)))
	if float64(a1.Y) >= 0.0 {
		v3 = 0.5
	} else {
		v3 = -0.5
	}
	result = int64(float64(a1.Y)*0.030743772 + v3)
	*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*1)) = uint32(int32(result))
	return result
}
func sub_520E60(a1 *int2) int32 {
	var (
		v1     int32
		v2     int32
		result int32
	)
	v1 = int32(dword_5d4594_2487536 + uint32(a1.field_0))
	v2 = int32(dword_5d4594_2487536 + uint32(a1.field_4))
	if v1 < 0 || v1 >= dword_5d4594_2487540 || v2 < 0 || v2 >= dword_5d4594_2487540 {
		result = 0
	} else {
		result = int32(*(*uint32)(unsafe.Pointer(uintptr(dword_5d4594_2487532 + uint32(v1*4)))) + uint32(v2*20))
	}
	return result
}
func sub_520EA0(a1 int32) int32 {
	var (
		v2 int32
		v3 int32
		v4 int32
		v5 int32
		v6 int32
		v7 int32
	)
	dword_5d4594_2487540 = *(*uint32)(unsafe.Add(a1, 68))*2 + 1
	dword_5d4594_2487536 = *(*uint32)(unsafe.Add(a1, 68))
	dword_5d4594_2487532 = uint32(uintptr(alloc.Calloc1(int(dword_5d4594_2487540), 4)))
	if dword_5d4594_2487532 == 0 {
		return 0
	}
	v2 = int32(dword_5d4594_2487540)
	v3 = 0
	if dword_5d4594_2487540 > 0 {
		for {
			*(*uint32)(unsafe.Pointer(uintptr(dword_5d4594_2487532 + uint32(v3*4)))) = uint32(uintptr(alloc.Calloc1(int(v2), 20)))
			if *(*uint32)(unsafe.Pointer(uintptr(dword_5d4594_2487532 + uint32(v3*4)))) == 0 {
				return 0
			}
			v2 = int32(dword_5d4594_2487540)
			if func() int32 {
				p := &v3
				*p++
				return *p
			}() >= dword_5d4594_2487540 {
				break
			}
		}
	}
	v4 = 0
	if v2 > 0 {
		v5 = 0
		for {
			v6 = 0
			if v2 > 0 {
				for {
					*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(dword_5d4594_2487532 + uint32(v6*4))))+uint32(v5))), 4)) = uint32(v6) - dword_5d4594_2487536
					v7 = int32(*(*uint32)(unsafe.Pointer(uintptr(dword_5d4594_2487532 + uint32(func() int32 {
						p := &v6
						x := *p
						*p++
						return x
					}()*4)))))
					*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v7+v5)), 8)) = uint32(v4) - dword_5d4594_2487536
					*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*(*uint32)(unsafe.Pointer(uintptr(dword_5d4594_2487532 + uint32(v6*4) - 4)))+uint32(v5))), 16)) = 0
					v2 = int32(dword_5d4594_2487540)
					if v6 >= dword_5d4594_2487540 {
						break
					}
				}
			}
			v4++
			v5 += 20
			if v4 >= v2 {
				break
			}
		}
	}
	return 1
}
func sub_520F80() {
	var i int32
	for i = 0; i < dword_5d4594_2487540; i++ {
		alloc.FreePtr(*(*unsafe.Pointer)(unsafe.Pointer(uintptr(dword_5d4594_2487532 + uint32(i*4)))))
	}
	alloc.FreePtr(dword_5d4594_2487532)
}
func sub_521100(a1 int32) int32 {
	var (
		result int32
		v2     int32
		v3     int32
		v4     int32
		v5     int32
		a1a    int2
		a2     int2
	)
	nox_xxx_mapGenRoundFloatToPtr_520DF0((*types.Pointf)(unsafe.Add(a1, 20)), (*uint32)(unsafe.Pointer(&a2)))
	result = int32(*(*uint32)(unsafe.Add(a1, 16)))
	v2 = 0
	for a1a.field_4 = a2.field_4; v2 < result; a1a.field_4++ {
		v3 = 0
		a1a.field_0 = a2.field_0
		if *(*uint32)(unsafe.Add(a1, 12)) > 0 {
			for {
				v4 = sub_520E60(&a1a)
				if v4 != 0 {
					*(*uint32)(unsafe.Add(v4, 16)) = uint32(a1)
				}
				v5 = int32(*(*uint32)(unsafe.Add(a1, 12)))
				v3++
				a1a.field_0++
				if v3 >= v5 {
					break
				}
			}
		}
		result = int32(*(*uint32)(unsafe.Add(a1, 16)))
		v2++
	}
	return result
}
func sub_521180(a1 int32) int32 {
	var (
		result int32
		v2     int32
		v3     int32
		v4     int32
		v5     int32
		a1a    int2
		a2     int2
	)
	nox_xxx_mapGenRoundFloatToPtr_520DF0((*types.Pointf)(unsafe.Add(a1, 20)), (*uint32)(unsafe.Pointer(&a2)))
	result = int32(*(*uint32)(unsafe.Add(a1, 16)))
	v2 = 0
	for a1a.field_4 = a2.field_4; v2 < result; a1a.field_4++ {
		v3 = 0
		a1a.field_0 = a2.field_0
		if *(*uint32)(unsafe.Add(a1, 12)) > 0 {
			for {
				v4 = sub_520E60(&a1a)
				if v4 != 0 {
					*(*uint32)(unsafe.Add(v4, 16)) = 0
				}
				v5 = int32(*(*uint32)(unsafe.Add(a1, 12)))
				v3++
				a1a.field_0++
				if v3 >= v5 {
					break
				}
			}
		}
		result = int32(*(*uint32)(unsafe.Add(a1, 16)))
		v2++
	}
	return result
}
func sub_521200(a1 int32) int32 {
	var (
		v1  int32
		v2  int32
		v3  int32
		v4  int32
		v5  int32
		v6  int32
		a1a int2
		a2  int2
	)
	nox_xxx_mapGenRoundFloatToPtr_520DF0((*types.Pointf)(unsafe.Add(a1, 20)), (*uint32)(unsafe.Pointer(&a2)))
	v1 = int32(*(*uint32)(unsafe.Add(a1, 16)))
	v2 = 0
	a1a.field_4 = a2.field_4
	if v1 <= 0 {
		return 0
	}
	for {
		v3 = 0
		a1a.field_0 = a2.field_0
		if *(*uint32)(unsafe.Add(a1, 12)) > 0 {
			for {
				v4 = sub_520E60(&a1a)
				if v4 != 0 {
					if *(*uint32)(unsafe.Add(v4, 16)) != 0 {
						return int32(*(*uint32)(unsafe.Add(v4, 16)))
					}
				}
				v5 = int32(*(*uint32)(unsafe.Add(a1, 12)))
				v3++
				a1a.field_0++
				if v3 >= v5 {
					goto LABEL_6
				}
			}
		}
	LABEL_6:
		v6 = int32(*(*uint32)(unsafe.Add(a1, 16)))
		v2++
		a1a.field_4++
		if v2 >= v6 {
			return 0
		}
	}
}
func sub_521290(a1 *int2) int32 {
	var (
		v1     int32
		result int32
	)
	v1 = sub_520E60(a1)
	if v1 != 0 {
		result = int32(*(*uint32)(unsafe.Add(v1, 16)))
	} else {
		result = 0
	}
	return result
}
func sub_5212B0(a1 int32, a2 *uint32) int32 {
	var (
		v2  *uint32
		v3  int32
		v4  int32
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v10 int32
		v11 int32
		v12 int32
		v13 int32
		v14 int32
		v15 int32
		v16 *int32
		a2a types.Pointf
		v19 [4]int32
	)
	v2 = a2
	v3 = 0
	for {
		v4 = int32(*(*uint32)(unsafe.Add(a1, 4)))
		v5 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*1)))
		v6 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*3)) - uint32(v4))
		v7 = int32(*(*uint32)(unsafe.Add(a1, 12)) + uint32(v4) - uint32(v5))
		v8 = v5 + v6
		v9 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*2)))
		v10 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*4)))
		v19[3] = v7
		v11 = int32(*(*uint32)(unsafe.Add(a1, 8)))
		v12 = -1
		v19[0] = v9 + v10 - v11
		v13 = int32(*(*uint32)(unsafe.Add(a1, 16)) + uint32(v11) - uint32(v9))
		v19[2] = v8
		v19[1] = v13
		v14 = 99999
		v15 = 0
		v16 = &v19[0]
		for {
			if *v16 < v14 {
				v14 = *v16
				v12 = v15
			}
			v15++
			v16 = (*int32)(unsafe.Add(unsafe.Pointer(v16), 4*1))
			if v15 >= 4 {
				break
			}
		}
		switch v12 {
		case 0:
			a2a.X = *(*float32)(unsafe.Add(a1, 20))
			a2a.Y = float32(float64(v19[0])*32.526913 + float64(*(*float32)(unsafe.Add(a1, 24))))
		case 1:
			a2a.X = *(*float32)(unsafe.Add(a1, 20))
			a2a.Y = float32(float64(*(*float32)(unsafe.Add(a1, 24))) - float64(v19[1])*32.526913)
		case 2:
			a2a.Y = *(*float32)(unsafe.Add(a1, 24))
			a2a.X = float32(float64(v19[2])*32.526913 + float64(*(*float32)(unsafe.Add(a1, 20))))
		case 3:
			a2a.Y = *(*float32)(unsafe.Add(a1, 24))
			a2a.X = float32(float64(*(*float32)(unsafe.Add(a1, 20))) - float64(v19[3])*32.526913)
		default:
		}
		nox_xxx_mapGenSetRoomPos_521880((*uint32)(a1), &a2a)
		v2 = (*uint32)(unsafe.Pointer(uintptr(sub_521200(a1))))
		if v2 == nil {
			return 1
		}
		if func() int32 {
			p := &v3
			*p++
			return *p
		}() >= 25 {
			return 0
		}
	}
}
func nox_xxx_mapgenAllocBuffer_5213E0() int32 {
	dword_5d4594_2487556 = uint32(uintptr(alloc.Calloc1(1, 0x2000)))
	return bool2int32(dword_5d4594_2487556 != 0)
}
func nox_xxx_mapgenFreeBuffer_521400() {
	alloc.FreePtr(dword_5d4594_2487556)
}
func nox_xxx_mapGenGetTopRoom_521710() unsafe.Pointer { return dword_5d4594_2487560 }
func sub_521720(a1 int32) int32 {
	var result int32
	if a1 != 0 {
		result = int32(*(*uint32)(unsafe.Add(a1, 56)))
	} else {
		result = 0
	}
	return result
}
func nox_xxx_mapGenAddNewRoom_521730(a1 *uint32) int32 {
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*15)) = 0
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*14)) = dword_5d4594_2487560
	if dword_5d4594_2487560 != 0 {
		*(*uint32)(unsafe.Add(dword_5d4594_2487560, 60)) = uint32(uintptr(unsafe.Pointer(a1)))
	}
	dword_5d4594_2487560 = uint32(uintptr(unsafe.Pointer(a1)))
	return sub_521100(int32(uintptr(unsafe.Pointer(a1))))
}
func sub_521760(a1 int32) int32 {
	var (
		v1 int32
		v2 int32
	)
	v1 = int32(*(*uint32)(unsafe.Add(a1, 60)))
	if v1 != 0 {
		*(*uint32)(unsafe.Add(v1, 56)) = *(*uint32)(unsafe.Add(a1, 56))
	} else {
		dword_5d4594_2487560 = *(*uint32)(unsafe.Add(a1, 56))
	}
	v2 = int32(*(*uint32)(unsafe.Add(a1, 56)))
	if v2 != 0 {
		*(*uint32)(unsafe.Add(v2, 60)) = *(*uint32)(unsafe.Add(a1, 60))
	}
	return sub_521180(a1)
}
func sub_5217A0(a1 int32, a2 int32) int32 {
	var (
		v2 int32
		v3 int32
		v4 float64
		v5 int32
		v6 float64
		v7 int32
	)
	v2 = 0
	v3 = int32(*(*uint32)(unsafe.Add(a2, 16)))
	v4 = float64(*(*float32)(unsafe.Add(a2, 24)))
	if v3 <= 0 {
		return 1
	}
	v5 = int32(*(*uint32)(unsafe.Add(a2, 12)))
	for {
		v6 = float64(*(*float32)(unsafe.Add(a2, 20)))
		v7 = 0
		if v5 > 0 {
			for float64(*(*float32)(unsafe.Add(a1, 64))) >= math.Abs(v6) && float64(*(*float32)(unsafe.Add(a1, 64))) >= math.Abs(v4) {
				v6 = v6 + 32.526913
				if func() int32 {
					p := &v7
					*p++
					return *p
				}() >= v5 {
					goto LABEL_7
				}
			}
			return 0
		}
	LABEL_7:
		v2++
		v4 = v4 + 32.526913
		if v2 >= v3 {
			return 1
		}
	}
}
func sub_521820(a1 int32, a2 int32) int32 {
	var result int32
	result = sub_5217A0(a1, a2)
	if result != 0 {
		result = bool2int32(sub_521200(a2) == 0)
	}
	return result
}
func nox_xxx_mapGenUpdateRoomRect_521850(a1 int32) int32 {
	var (
		result int32
		v2     float64
		v3     int32
	)
	result = a1
	v2 = float64(*(*float32)(unsafe.Add(a1, 28)) + *(*float32)(unsafe.Add(a1, 20)))
	v3 = int32(*(*uint32)(unsafe.Add(a1, 24)))
	*(*uint32)(unsafe.Add(a1, 36)) = *(*uint32)(unsafe.Add(a1, 20))
	*(*uint32)(unsafe.Add(a1, 40)) = uint32(v3)
	*(*float32)(unsafe.Add(a1, 44)) = float32(v2)
	*(*float32)(unsafe.Add(a1, 48)) = *(*float32)(unsafe.Add(a1, 32)) + *(*float32)(unsafe.Add(a1, 24))
	return result
}
func nox_xxx_mapGenSetRoomPos_521880(a1 *uint32, a2 *types.Pointf) int32 {
	*(*types.Pointf)(unsafe.Add(unsafe.Pointer(a1), 4*5)) = *a2
	nox_xxx_mapGenRoundFloatToPtr_520DF0(a2, (*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)))
	return nox_xxx_mapGenUpdateRoomRect_521850(int32(uintptr(unsafe.Pointer(a1))))
}
func sub_5218B0(a1 int32, a2 int32) int32 {
	var (
		v2 int32
		v3 int32
		i  *uint32
	)
	v2 = 0
	v3 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a1+a2)), 216)))
	if v3 <= 0 {
		return 0
	}
	for i = (*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a2*32+a1)), 88)); *i == 0 || *(*uint32)(unsafe.Pointer(uintptr(*i))) != 1; i = (*uint32)(unsafe.Add(unsafe.Pointer(i), 4*1)) {
		if func() int32 {
			p := &v2
			*p++
			return *p
		}() >= v3 {
			return 0
		}
	}
	return 1
}
func sub_521900(a1 int32, a2 int32, a3 int32) int32 {
	if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a1+a3)), 216))) >= 8 {
		return 0
	}
	*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1+(int32(func() uint8 {
		p := (*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a1+a3)), 216))
		x := *p
		*p++
		return x
	}())+a3*8)*4)), 88)) = uint32(a2)
	return 1
}
func nox_xxx_mapGenMakeRoomStruct_521940(a1 int32, a2 int32) *float32 {
	var result *float32
	result = (*float32)(alloc.Calloc1(1, 0x178))
	if result != nil {
		*(*uint32)(unsafe.Pointer(result)) = 1
		*((*uint32)(unsafe.Add(unsafe.Pointer(result), 4*3))) = uint32(a1)
		*((*uint32)(unsafe.Add(unsafe.Pointer(result), 4*4))) = uint32(a2)
		*(*float32)(unsafe.Add(unsafe.Pointer(result), unsafe.Sizeof(float32(0))*7)) = float32(float64(a1) * 32.526913)
		*(*float32)(unsafe.Add(unsafe.Pointer(result), unsafe.Sizeof(float32(0))*8)) = float32(float64(a2) * 32.526913)
	}
	return result
}
func nox_xxx_mapGenPrepareRoom_521990(a1 int32) *float32 {
	var (
		v1 int32
		v2 int32
		v3 int32
		v4 int32
		v5 int32
		v7 int32
		v8 int32
	)
	v1 = a1
	v2 = int32(*(*uint32)(unsafe.Add(a1, 32)))
	v7 = int32(*(*uint32)(unsafe.Add(a1, 36)))
	v3 = v2 - v7
	v4 = nox_xxx_mapGenRandFunc2_526B00(v2, v7)
	v8 = v4
	if v4 < 5 {
		v4 = 5
		v8 = 5
	}
	v5 = nox_xxx_mapGenRandFunc2_526B00(v4, int32(int64(float64(v8)*0.30000001)))
	if v5 < 5 {
		v5 = 5
	}
	if v5 < v3 {
		v5 = v3
	}
	if *(*uint32)(unsafe.Add(v1, 56)) != 0 {
		nox_xxx_mapGenRandFunc_526AC0(0, 2)
	}
	return nox_xxx_mapGenMakeRoomStruct_521940(v4, v5)
}
func sub_521A10(lpMem unsafe.Pointer) {
	var (
		v1 *uint32
		v2 *uint32
	)
	v1 = (*uint32)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(lpMem, 4*92))))))
	if v1 != nil {
		for {
			v2 = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v1), 4*6)))
			alloc.Free(v1)
			v1 = v2
			if v2 == nil {
				break
			}
		}
	}
	alloc.FreePtr(lpMem)
}
func nox_xxx_mapGenFreeTopRoom_521A40() *uint32 {
	var (
		result *uint32
		v1     *uint32
	)
	result = dword_5d4594_2487560
	if dword_5d4594_2487560 != 0 {
		for {
			v1 = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(result), 4*14)))
			sub_521A10(unsafe.Pointer(result))
			result = v1
			if v1 == nil {
				break
			}
		}
		dword_5d4594_2487560 = 0
	} else {
		dword_5d4594_2487560 = 0
	}
	return result
}
func sub_521A70(a1 int32, a2 int32, a3 int32) int32 {
	var v3 int32
	sub_521900(a1, a2, a3)
	v3 = sub_523960(a3)
	return sub_521900(a2, a1, v3)
}
func sub_521AA0(a1 *uint32, a2 int32) int32 {
	var v2 int32
	if *a1 == 1 {
		return 0
	}
	switch *a1 {
	case 2:
		v2 = 1
	case 3:
		v2 = 0
	case 4:
		v2 = 3
	case 5:
		v2 = 2
	default:
		v2 = int32(uintptr(unsafe.Pointer(a1)))
	}
	if a2 != v2 {
		return 0
	} else {
		return 1
	}
}
func sub_521B00(a1 int32, a2 int32) float64 {
	return float64(nox_xxx_mapGenRandFunc_526AC0(0, int32(*(*uint32)(unsafe.Add(a1, 12))-*(*uint32)(unsafe.Add(a2, 12)))))*32.526913 + float64(*(*float32)(unsafe.Add(a1, 20)))
}
func sub_521B30(a1 int32, a2 int32) float64 {
	return float64(nox_xxx_mapGenRandFunc_526AC0(0, int32(*(*uint32)(unsafe.Add(a1, 16))-*(*uint32)(unsafe.Add(a2, 16)))))*32.526913 + float64(*(*float32)(unsafe.Add(a1, 24)))
}
func sub_521B60(a1 int32, a2 int32) float64 {
	return float64(*(*float32)(unsafe.Add(a2, 20))) - float64(nox_xxx_mapGenRandFunc_526AC0(0, int32(*(*uint32)(unsafe.Add(a1, 12))-*(*uint32)(unsafe.Add(a2, 12)))))*32.526913
}
func sub_521B90(a1 int32, a2 int32) float64 {
	return float64(*(*float32)(unsafe.Add(a2, 24))) - float64(nox_xxx_mapGenRandFunc_526AC0(0, int32(*(*uint32)(unsafe.Add(a1, 16))-*(*uint32)(unsafe.Add(a2, 16)))))*32.526913
}
func sub_521BC0(a1 int32, a2 *types.Pointf, a3 float32, a4 float32) *float32 {
	var result *float32
	result = (*float32)(alloc.Calloc1(1, 0x1C))
	if result != nil {
		*result = 0.0
		*(*types.Pointf)(unsafe.Add(unsafe.Pointer(result), unsafe.Sizeof(float32(0))*1)) = *a2
		*(*float32)(unsafe.Add(unsafe.Pointer(result), unsafe.Sizeof(float32(0))*3)) = a3 + a2.X
		*(*float32)(unsafe.Add(unsafe.Pointer(result), unsafe.Sizeof(float32(0))*4)) = a4 + a2.Y
		*(*float32)(unsafe.Add(unsafe.Pointer(result), unsafe.Sizeof(float32(0))*6)) = *(*float32)(unsafe.Add(a1, 368))
		*(*uint32)(unsafe.Add(a1, 368)) = uint32(uintptr(unsafe.Pointer(result)))
	}
	return result
}
func sub_521C10(a1 int32) *uint32 {
	var (
		v1     *uint32
		result *uint32
		v3     *uint32
	)
	v1 = nil
	result = *(**uint32)(unsafe.Add(a1, 368))
	if result != nil {
		for {
			v3 = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(result), 4*6)))
			if *result == 1 {
				if v1 != nil {
					*(*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*6)) = uint32(uintptr(unsafe.Pointer(v3)))
				} else {
					*(*uint32)(unsafe.Add(a1, 368)) = uint32(uintptr(unsafe.Pointer(v3)))
				}
				alloc.Free(result)
			} else {
				v1 = result
			}
			result = v3
			if v3 == nil {
				break
			}
		}
	}
	return result
}
func nox_xxx_mapgen_521C60(a1 int32, a2 int32) int32 {
	var (
		result int32
		i      int32
		v4     int32
	)
	result = sub_504980()
	for i = result; result != 0; i = result {
		v4 = a2
		if a2 != 0 {
			for {
				if uint32(*(*uint16)(unsafe.Add(i, 4))) == *(*uint32)(v4) {
					nox_xxx_mapgen_521FE0(a1, i, *(**uint32)(unsafe.Add(v4, 4)))
					break
				}
				v4 = int32(*(*uint32)(unsafe.Add(v4, 8)))
				if v4 == 0 {
					break
				}
			}
		}
		result = sub_5049C0(i)
	}
	return result
}
func sub_521CB0(a1 int32, a2 int32, a3 int32, a4 int32) int32 {
	var (
		v4  *float32
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v10 int32
		v11 float64
		v12 int32
		v14 *float32
		v15 float32
		v16 float32
		v17 *byte
		v18 int32
		v19 int32
		v20 types.Pointf
		v22 int32
	)
	v4 = (*float32)(alloc.Calloc1(1, 0x1C))
	if v4 == nil {
		return 0
	}
	v15 = float32(sub_502E70(a4))
	v16 = float32(sub_502EA0(a4))
	v5 = int32(int64(float64(v15) * 0.030743772))
	v18 = v5
	v6 = a2
	v19 = int32(int64(float64(v16) * 0.030743772))
	v7 = int32(*(*uint32)(unsafe.Add(a2, 12)) - uint32(v5))
	v8 = int32(*(*uint32)(unsafe.Add(a2, 16)) - uint32(v19))
	if v7 >= 0 && v8 >= 0 {
		v17 = sub_526AA0(a4)
		v20.X = float32(float64(nox_xxx_mapGenRandFunc_526AC0(0, v7))*32.526913 + float64(*(*float32)(unsafe.Add(a2, 36))))
		v20.Y = float32(float64(nox_xxx_mapGenRandFunc_526AC0(0, v8))*32.526913 + float64(*(*float32)(unsafe.Add(a2, 40))))
		v9 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v17), 4*15))))
		if v9&1 != 0 {
			v20.Y = *(*float32)(unsafe.Add(a2, 40))
		} else if v9&2 != 0 {
			v20.Y = *(*float32)(unsafe.Add(a2, 48)) - v16
		}
		v10 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v17), 4*15))))
		if v10&4 != 0 {
			v20.X = *(*float32)(unsafe.Add(a2, 44)) - v15
		} else if v10&8 != 0 {
			v20.X = *(*float32)(unsafe.Add(a2, 36))
		}
		if *(*byte)(unsafe.Add(unsafe.Pointer(v17), 60))&0x10 != 0 {
			v22 = int32((*(*uint32)(unsafe.Add(a2, 16)) - uint32(v19)) / 2)
			v20.X = float32(float64(int32((*(*uint32)(unsafe.Add(v6, 12))-uint32(v18))/2))*32.526913 + float64(*(*float32)(unsafe.Add(v6, 36))))
			v20.Y = float32(float64(v22)*32.526913 + float64(*(*float32)(unsafe.Add(v6, 40))))
		}
		*(*uint32)(unsafe.Pointer(v4)) = 1
		*(*float32)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(float32(0))*1)) = v20.X
		*(*float32)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(float32(0))*2)) = v20.Y
		*(*float32)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(float32(0))*3)) = v20.X + v15
		v11 = float64(v20.Y + v16)
		*((*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*5))) = uint32(a4)
		*(*float32)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(float32(0))*4)) = float32(v11)
		v12 = sub_521EB0((*float32)(v6), v4)
		v14 = v4
		if v12 == 0 {
			goto LABEL_18
		}
		if sub_521F10(v6, v4) == 0 {
			sub_502D70(a4)
			nox_xxx_mapgen_521C60(a1, int32(*(*uint32)(unsafe.Add(a3, 84))))
			sub_503B30(&v20)
			*(*float32)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(float32(0))*6)) = *(*float32)(unsafe.Add(v6, 368))
			*(*uint32)(unsafe.Add(v6, 368)) = uint32(uintptr(unsafe.Pointer(v4)))
			return 1
		}
	}
	v14 = v4
LABEL_18:
	alloc.Free(v14)
	return 0
}
func sub_521EB0(a1 *float32, a2 *float32) int32 {
	return bool2int32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*1)))+0.5 >= float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*9))) && float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*3)))-0.5 <= float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*11))) && float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*2)))+0.5 >= float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*10))) && float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*4)))-0.5 <= float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*12))))
}
func sub_521F10(a1 int32, a2 *float32) int32 {
	var (
		v2 int32
		v4 float32
		v5 float32
		v6 float32
		v7 float32
		v8 float32
		v9 float32
	)
	v2 = int32(*(*uint32)(unsafe.Add(a1, 368)))
	if v2 == 0 {
		return 0
	}
	for {
		if (*float32)(v2) != a2 {
			v4 = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*1))) + 0.5)
			if float64(v4) < float64(*(*float32)(unsafe.Add(v2, 12)))-0.5 {
				v6 = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*3))) - 0.5)
				if float64(v6) > float64(*(*float32)(unsafe.Add(v2, 4)))+0.5 {
					v9 = float32(float64(*(*float32)(unsafe.Add(v2, 16))) - 0.5)
					v5 = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*2))) + 0.5)
					if float64(v5) < float64(v9) {
						v8 = float32(float64(*(*float32)(unsafe.Add(v2, 8))) + 0.5)
						v7 = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*4))) - 0.5)
						if float64(v7) > float64(v8) {
							break
						}
					}
				}
			}
		}
		v2 = int32(*(*uint32)(unsafe.Add(v2, 24)))
		if v2 == 0 {
			return 0
		}
	}
	return v2
}
func nox_xxx_mapgen_521FE0(a1 int32, a2 int32, a3 *uint32) {
	var (
		v3 *uint32
		v4 int32
		v5 *uint32
		v6 *byte
		v7 *uint32
		v8 int32
	)
	v3 = a3
	if a3 != nil {
		v4 = nox_xxx_mapGenRandFunc_526AC0(1, 100)
		for {
			v4 -= int32(*v3)
			if v4 <= 0 {
				break
			}
			v3 = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v3), 4*514)))
			if v3 == nil {
				return
			}
		}
		if v3 != nil {
			v8 = 0
			if *(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*513)) > 0 {
				v5 = nil
				v6 = (*byte)(unsafe.Add(unsafe.Pointer(v3), 4*2))
				for {
					switch *((*uint32)(unsafe.Add(unsafe.Pointer(v6), -int(4*1)))) {
					case 0:
						v7 = (*uint32)(unsafe.Pointer(nox_xxx_newObjectByTypeID_4E3810(v6)))
						v5 = v7
					case 3:
						v7 = nox_xxx_mapGenMakeEnchantedItem_5221A0(v6, *(**byte)(unsafe.Add(a1, 1100)), int32(*(*uint32)(unsafe.Add(a1, 1104))))
						v5 = v7
					case 4:
						v7 = nox_xxx_mapGenMakeEnchantedItem_5221A0(v6, *(**byte)(unsafe.Add(a1, 1108)), int32(*(*uint32)(unsafe.Add(a1, 1112))))
						v5 = v7
					case 5:
						v7 = nox_xxx_mapGenMakeSpellbook_5220E0(a1, v6)
						v5 = v7
					default:
					}
					if v5 != nil {
						sub_522300(a2, v5)
					}
					v6 = (*byte)(unsafe.Add(unsafe.Pointer(v6), 64))
					v8++
					if uint32(v8) >= *(*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*513)) {
						break
					}
				}
			}
		}
	}
}
func nox_xxx_mapGenMakeSpellbook_5220E0(a1 int32, a2 *byte) *uint32 {
	var (
		v3 *uint32
		v4 int8
	)
	if *(*uint32)(unsafe.Add(a1, 1096)) == 0 {
		return nil
	}
	v3 = (*uint32)(unsafe.Pointer(nox_xxx_newObjectByTypeID_4E3810(internCStr("SpellBook"))))
	if v3 == nil {
		return v3
	}
	if libc.StrCmp(internCStr("*"), a2) == 0 {
		v4 = int8(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a1+nox_xxx_mapGenRandFunc_526AC0(0, int32(*(*uint32)(unsafe.Add(a1, 1096))-1))*4)), 548)))
		nox_xxx_mapGenFinishSpellbook_527DB0(int32(uintptr(unsafe.Pointer(v3))), v4)
		return v3
	}
	v4 = int8(nox_xxx_mapGenSpellIdByName_51E1D0(a2))
	if int32(v4) != 0 {
		nox_xxx_mapGenFinishSpellbook_527DB0(int32(uintptr(unsafe.Pointer(v3))), v4)
		return v3
	}
	alloc.Free(v3)
	return nil
}
func nox_xxx_mapGenMakeEnchantedItem_5221A0(a1 *byte, a2 *byte, a3 int32) *uint32 {
	var (
		v3  int32
		v4  *byte
		i   int32
		v6  *byte
		v7  *uint32
		v8  *uint32
		v9  int32
		v10 *byte
		v11 int32
		v13 [20]byte
	)
	if libc.StrCmp(internCStr("*"), a1) == 0 {
		v3 = nox_xxx_mapGenRandFunc_526AC0(0, a3-1)
		v4 = a2
		for i = 0; v4 != nil; i++ {
			if i == v3 {
				break
			}
			v4 = (*byte)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*38))))))
		}
		v6 = (*byte)(unsafe.Add(unsafe.Pointer(v4), 60))
	} else {
		v4 = a2
		if a2 != nil {
			for {
				if nox_strcmpi(v4, a1) == 0 {
					v6 = (*byte)(unsafe.Add(unsafe.Pointer(v4), 60))
					break
				}
				v4 = (*byte)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*38))))))
				if v4 == nil {
					break
				}
			}
		}
		if v4 == nil {
			v6 = a1
		}
	}
	v7 = (*uint32)(unsafe.Pointer(nox_xxx_newObjectByTypeID_4E3810(v6)))
	if v7 != nil && v4 != nil {
		v8 = (*uint32)(unsafe.Add(unsafe.Pointer(v4), 136))
		*(*uint32)(unsafe.Pointer(&v13[0])) = 0
		v9 = 0
		*(*uint32)(unsafe.Pointer(&v13[4])) = 0
		*(*uint32)(unsafe.Pointer(&v13[8])) = 0
		*(*uint32)(unsafe.Pointer(&v13[12])) = 0
		for {
			if *v8 != 0 {
				if uint32(nox_xxx_mapGenRandFunc_526AC0(1, 100)) <= *memmap.PtrUint32(0x587000, uintptr(v9)+254688) {
					v10 = (*byte)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer(v8), -int(4*4)))) + uint32(nox_xxx_mapGenRandFunc_526AC0(0, int32(*v8-1))*60))))
					if nox_strcmpi(internCStr("none"), v10) != 0 {
						v11 = nox_xxx_modifGetIdByName_413290(v10)
						*(*uint32)(unsafe.Pointer(&v13[v9])) = uint32(uintptr(nox_xxx_modifGetDescById_413330(v11)))
					}
				}
			}
			v9 += 4
			v8 = (*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*1))
			if v9 >= 16 {
				break
			}
		}
		if *(*uint32)(unsafe.Pointer(&v13[8])) == 0 {
			*(*uint32)(unsafe.Pointer(&v13[12])) = 0
		}
		nox_xxx_modifSetItemAttrs_4E4990((*server.Object)(unsafe.Pointer(v7)), (*int32)(unsafe.Pointer(&v13[0])))
	}
	return v7
}
func sub_522300(a1 int32, a2 *uint32) *uint32 {
	var (
		result *uint32
		v3     int32
	)
	result = a2
	*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*125)) = 0
	*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*124)) = *(*uint32)(unsafe.Add(a1, 504))
	v3 = int32(*(*uint32)(unsafe.Add(a1, 504)))
	if v3 != 0 {
		*(*uint32)(unsafe.Add(v3, 500)) = uint32(uintptr(unsafe.Pointer(a2)))
	}
	*(*uint32)(unsafe.Add(a1, 504)) = uint32(uintptr(unsafe.Pointer(a2)))
	*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*123)) = uint32(a1)
	return result
}
func nox_xxx_mapgen_522340(a1 int32, a2 int32) {
	var i *int32
	for i = *(**int32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a2, 372)), 92)); i != nil; i = (*int32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(i), 4*5))) {
		nox_xxx_mapgen_522370(a1, a2, i)
	}
}
func nox_xxx_mapgen_522370(a1 int32, a2 int32, a3 *int32) {
	var (
		v3  *int32
		v4  int32
		v5  int32
		v6  int32
		v7  *uint32
		v8  *uint32
		v9  int32
		v10 int32
		v11 int32
		v12 int32
		v13 int32
	)
	v3 = a3
	if *(*int32)(unsafe.Add(unsafe.Pointer(a3), 4*2)) != 0 {
		v4 = nox_xxx_mapGenRandFunc_526AC0(*a3, *(*int32)(unsafe.Add(unsafe.Pointer(a3), 4*1)))
		v5 = *(*int32)(unsafe.Add(unsafe.Pointer(a3), 4*3))
		v13 = v4
		if v4 > v5 {
			v13 = v5
			v4 = v5
		}
		v6 = *(*int32)(unsafe.Add(unsafe.Pointer(v3), 4*2))
		v7 = (*uint32)(v6)
		v12 = 1
		*(*uint32)(unsafe.Add(v6, 92)) = 0
		*(*uint32)(unsafe.Add(v6, 96)) = 0
		v8 = *(**uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v3), 4*2)), 88))
		if *(*int32)(unsafe.Add(unsafe.Pointer(v3), 4*3)) > 1 {
			for {
				if nox_xxx_mapGenRandFunc_526AC0(1, 100) >= 50 {
					if nox_xxx_mapGenRandFunc_526AC0(1, 100) >= 50 {
						*(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*23)) = uint32(uintptr(unsafe.Pointer(v8)))
						*(*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*24)) = uint32(uintptr(unsafe.Pointer(v7)))
						*(*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*23)) = 0
						v7 = v8
					} else {
						*(*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*23)) = uint32(uintptr(unsafe.Pointer(v7)))
						*(*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*24)) = *(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*24))
						v10 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*24)))
						if v10 != 0 {
							*(*uint32)(unsafe.Add(v10, 92)) = uint32(uintptr(unsafe.Pointer(v8)))
						} else {
							v6 = int32(uintptr(unsafe.Pointer(v8)))
						}
						*(*uint32)(unsafe.Add(unsafe.Pointer(v7), 4*24)) = uint32(uintptr(unsafe.Pointer(v8)))
					}
				} else if nox_xxx_mapGenRandFunc_526AC0(1, 100) >= 50 {
					v9 = int32(*(*uint32)(unsafe.Add(v6, 92)))
					if v9 != 0 {
						*(*uint32)(unsafe.Add(v9, 96)) = uint32(uintptr(unsafe.Pointer(v8)))
						*(*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*24)) = uint32(v6)
						*(*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*23)) = *(*uint32)(unsafe.Add(v6, 92))
					} else {
						*(*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*24)) = uint32(v6)
						*(*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*23)) = *(*uint32)(unsafe.Add(v6, 92))
						v7 = v8
					}
					*(*uint32)(unsafe.Add(v6, 92)) = uint32(uintptr(unsafe.Pointer(v8)))
				} else {
					*(*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*23)) = uint32(v6)
					*(*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*24)) = 0
					*(*uint32)(unsafe.Add(v6, 96)) = uint32(uintptr(unsafe.Pointer(v8)))
					v6 = int32(uintptr(unsafe.Pointer(v8)))
				}
				v8 = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v8), 4*22)))
				v12++
				if v12 >= *(*int32)(unsafe.Add(unsafe.Pointer(v3), 4*3)) {
					break
				}
			}
			v4 = v13
		}
		if v4 != 0 {
			v11 = v4
			for {
				nox_xxx_mapgen_5224B0(a1, a2, v6)
				v6 = int32(*(*uint32)(unsafe.Add(v6, 92)))
				v11--
				if v11 == 0 {
					break
				}
			}
		}
	}
}
func nox_xxx_mapgen_5224B0(a1 int32, a2 int32, a3 int32) *float32 {
	var (
		v3     int32
		v4     *float32
		v5     int32
		v6     int32
		result *float32
		v8     int32
		v9     *float32
		v10    int32
		v11    int32
		v12    int32
		v13    int32
	)
	v3 = a3
	if *(*uint32)(unsafe.Add(a3, 64)) != 0 {
		v4 = (*float32)(a2)
		v5 = int32(int64(float64(int32(*(*uint32)(unsafe.Add(a2, 12))**(*uint32)(unsafe.Add(a2, 16)))) * float64(*(*float32)(unsafe.Add(a3, 76)))))
		v6 = int32(*(*uint32)(unsafe.Add(a3, 68)))
		if v5 < v6 || (func() bool {
			v6 = int32(*(*uint32)(unsafe.Add(a3, 72)))
			return v5 > v6
		}()) {
			v5 = v6
		}
	} else {
		v4 = (*float32)(a2)
		v5 = nox_xxx_mapGenRandFunc_526AC0(int32(*(*uint32)(unsafe.Add(a3, 68))), int32(*(*uint32)(unsafe.Add(a3, 72))))
	}
	result = *(**float32)(a3)
	switch *(*uint32)(a3) {
	case 0:
		if v5 > 0 {
			v12 = v5
			for {
				v8 = nox_xxx_mapGenMakeMonsterInRoom_522810(v4, (*byte)(unsafe.Add(a3, 4)))
				if v8 != 0 {
					nox_xxx_mapgen_521FE0(a1, v8, *(**uint32)(unsafe.Add(a3, 80)))
				}
				result = (*float32)(unsafe.Pointer(uintptr(func() int32 {
					p := &v12
					*p--
					return *p
				}())))
				if v12 == 0 {
					break
				}
			}
		}
	case 1:
		result = (*float32)(unsafe.Pointer(uintptr(sub_5268F0((*byte)(unsafe.Add(a3, 4))))))
		v9 = result
		if int32(uintptr(unsafe.Pointer(result))) >= 0 && v5 > 0 {
			v13 = v5
			for {
				v10 = 0
				for {
					if sub_521CB0(a1, a2, v3, int32(uintptr(unsafe.Pointer(v9)))) != 0 {
						break
					}
					v10++
					if v10 >= 3 {
						break
					}
				}
				result = (*float32)(unsafe.Pointer(uintptr(func() int32 {
					p := &v13
					*p--
					return *p
				}())))
				if v13 == 0 {
					break
				}
			}
		}
	case 2:
		result = (*float32)(unsafe.Pointer(sub_521C10(int32(uintptr(unsafe.Pointer(v4))))))
	case 3:
		result = (*float32)(unsafe.Pointer(uintptr(sub_5226D0(unsafe.Pointer(v4), 0.89999998, unsafe.Pointer(&v11)))))
		if result != nil {
			result = (*float32)(unsafe.Pointer(nox_xxx_mapGenMakeEnchantedItem_5221A0((*byte)(unsafe.Add(a3, 4)), *(**byte)(unsafe.Add(a1, 1100)), int32(*(*uint32)(unsafe.Add(a1, 1104))))))
			if result != nil {
				result = nox_xxx_mapGenMoveObject_527A10(result, (*types.Pointf)(unsafe.Pointer(&v11)))
			}
		}
	case 4:
		result = (*float32)(unsafe.Pointer(uintptr(sub_5226D0(unsafe.Pointer(v4), 0.89999998, unsafe.Pointer(&v11)))))
		if result != nil {
			result = (*float32)(unsafe.Pointer(nox_xxx_mapGenMakeEnchantedItem_5221A0((*byte)(unsafe.Add(a3, 4)), *(**byte)(unsafe.Add(a1, 1108)), int32(*(*uint32)(unsafe.Add(a1, 1112))))))
			if result != nil {
				result = nox_xxx_mapGenMoveObject_527A10(result, (*types.Pointf)(unsafe.Pointer(&v11)))
			}
		}
	case 5:
		result = (*float32)(unsafe.Pointer(uintptr(sub_5226D0(unsafe.Pointer(v4), 0.89999998, unsafe.Pointer(&v11)))))
		if result != nil {
			result = (*float32)(unsafe.Pointer(nox_xxx_mapGenMakeSpellbook_5220E0(a1, (*byte)(unsafe.Add(a3, 4)))))
			if result != nil {
				result = nox_xxx_mapGenMoveObject_527A10(result, (*types.Pointf)(unsafe.Pointer(&v11)))
			}
		}
	default:
		return result
	}
	return result
}
func sub_5226D0(a1 unsafe.Pointer, a2 float32, a3 unsafe.Pointer) int32 {
	var (
		v3  *float32
		v4  float64
		v6  float32
		v7  float32
		v8  float32
		v9  float32
		v10 float32
		v11 float32
		v12 int32
	)
	v3 = (*float32)(a1)
	v4 = float64(*(*float32)(unsafe.Add(a1, 36)) + *(*float32)(unsafe.Add(a1, 44)))
	v12 = 0
	v10 = float32(v4 * 0.5)
	v11 = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float32(0))*10))+*(*float32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float32(0))*12))) * 0.5)
	v8 = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float32(0))*11))-*(*float32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float32(0))*9))) * 0.5)
	v9 = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float32(0))*12))-*(*float32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float32(0))*10))) * 0.5)
	for {
		v6 = -v8
		*(*float32)(a3) = float32(sub_526BC0(v6, v8)*float64(a2) + float64(v10))
		v7 = -v9
		*(*float32)(unsafe.Add(a3, 4)) = float32(sub_526BC0(v7, v9)*float64(a2) + float64(v11))
		if sub_5227B0(int32(uintptr(unsafe.Pointer(v3))), (*float32)(a3)) == 0 {
			break
		}
		if func() int32 {
			p := &v12
			*p++
			return *p
		}() >= 10 {
			return 0
		}
	}
	return 1
}
func sub_5227B0(a1 int32, a2 *float32) int32 {
	var v2 int32
	v2 = int32(*(*uint32)(unsafe.Add(a1, 368)))
	if v2 == 0 {
		return 0
	}
	for float64(*a2) < float64(*(*float32)(unsafe.Add(v2, 4))) || float64(*a2) > float64(*(*float32)(unsafe.Add(v2, 12))) || float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*1))) < float64(*(*float32)(unsafe.Add(v2, 8))) || float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*1))) > float64(*(*float32)(unsafe.Add(v2, 16))) {
		v2 = int32(*(*uint32)(unsafe.Add(v2, 24)))
		if v2 == 0 {
			return 0
		}
	}
	return 1
}
func nox_xxx_mapGenMakeMonsterInRoom_522810(a1 *float32, a2 *byte) int32 {
	var (
		result int32
		v3     *float32
		v4     int32
		v5     int32
		v6     int32
		v7     float32
		v8     float32
		v9     types.Pointf
		v11    types.Pointf
	)
	v7 = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*11))+*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*9))) * 0.5)
	v8 = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*12))+*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*10))) * 0.5)
	result = sub_5226D0(unsafe.Pointer(a1), 0.94999999, unsafe.Pointer(&v9))
	if result != 0 {
		nox_xxx_mapGenGetObjID_527940(a2)
		v3 = nox_xxx_mapGenPlaceObj_5279B0(&v9)
		v4 = int32(uintptr(unsafe.Pointer(v3)))
		if v3 != nil {
			if int32(uint8(*(*float32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float32(0))*2))))&2 != 0 {
				v11.X = v7 - v9.X
				v11.Y = v8 - v9.Y
				v5 = nox_xxx_math_509ED0(&v11)
				v6 = nox_xxx_math_509EA0(v5)
				nox_xxx_mapGenOrientObj_527C60(v4, v6)
			}
		}
		result = v4
	}
	return result
}
func sub_522C80(a1 *float32) *float32 {
	var result *float32
	result = sub_51D1A0((*types.Pointf)(unsafe.Pointer(a1)))
	if result == nil {
		result = (*float32)(unsafe.Pointer(sub_51D120(a1)))
	}
	return result
}
func sub_522CA0(a1 int32, a2 *float32) int8 {
	var (
		v2 int32
		v3 int32
		v4 *float32
		v5 int32
	)
	*((*uint8)(unsafe.Pointer(&v2))) = *(*uint8)(unsafe.Add(a1, 352))
	if int32(uint8(int8(v2))) < 0x10 {
		v3 = 0
		if int32(uint8(int8(v2))) != 0 {
			v4 = (*float32)(unsafe.Add(a1, 228))
			for {
				if sub_524660(*((*float32)(unsafe.Add(unsafe.Pointer(v4), -int(unsafe.Sizeof(float32(0))*1)))), *a2) != 0 {
					v2 = sub_524660(*v4, *(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*1)))
					if v2 != 0 {
						return int8(v2)
					}
				}
				v3++
				v4 = (*float32)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(float32(0))*2))
				if v3 >= int32(*(*uint8)(unsafe.Add(a1, 352))) {
					break
				}
			}
		}
		v5 = int32(*(*uint8)(unsafe.Add(a1, 352)))
		*(*float32)(unsafe.Add(unsafe.Pointer(uintptr(a1+v5*8)), 224)) = *a2
		*(*float32)(unsafe.Add(unsafe.Pointer(uintptr(a1+v5*8)), 228)) = *(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*1))
		*((*uint8)(unsafe.Pointer(&v2))) = uint8(int8(int32(*(*uint8)(unsafe.Add(a1, 352))) + 1))
		*(*uint8)(unsafe.Add(a1, 352)) = uint8(int8(v2))
	}
	return int8(v2)
}
func sub_522D30(a1 int32) *float32 {
	var (
		result *float32
		i      *float32
		v3     *int32
		v4     int32
		v5     int32
		v6     **float32
		v7     int32
		v8     int32
		v9     int32
		v10    int32
		v11    types.Pointf
		v12    types.Pointf
	)
	sub_51D0F0(math.MinInt8)
	result = (*float32)(nox_xxx_mapGenGetTopRoom_521710())
	for i = result; result != nil; i = result {
		nox_xxx_mapGenSetFlags_5235F0(-100)
		if *(*uint32)(unsafe.Pointer(i)) == 1 {
			v3 = (*int32)(unsafe.Add(unsafe.Pointer(i), unsafe.Sizeof(float32(0))*22))
			v4 = 0
			v9 = int32(uintptr(unsafe.Add(unsafe.Pointer(i), unsafe.Sizeof(float32(0))*22)))
			for {
				v5 = 0
				if int32(*((*uint8)(unsafe.Add(unsafe.Add(unsafe.Pointer(i), v4), 216)))) != 0 {
					for {
						if nox_xxx_mapGenCheckRoomType_5238F0((*int32)(unsafe.Pointer(uintptr(*v3)))) != 0 && sub_523920(int32(*(*uint32)(unsafe.Pointer(uintptr(*v3))))) == v4 {
							sub_523CB0(*v3, unsafe.Pointer(&v12))
							sub_522CA0(int32(uintptr(unsafe.Pointer(i))), &v12.X)
							sub_523D30((*float32)(unsafe.Pointer(uintptr(*v3))), &v11.X)
							sub_522C80(&v12.X)
							sub_522C80(&v11.X)
							sub_51D3F0(&v12, &v11)
							if *(*uint32)(unsafe.Add(a1, 60)) == 0 {
								sub_51D3F0(&v11, &v12)
							}
						}
						v5++
						v3 = (*int32)(unsafe.Add(unsafe.Pointer(v3), 4*1))
						if v5 >= int32(*((*uint8)(unsafe.Add(unsafe.Add(unsafe.Pointer(i), v4), 216)))) {
							break
						}
					}
				}
				v4++
				v3 = (*int32)(unsafe.Add(v9, 32))
				v9 += 32
				if v4 >= 4 {
					break
				}
			}
		} else {
			sub_523D30(i, &v12.X)
			v6 = (**float32)(unsafe.Add(unsafe.Pointer(i), unsafe.Sizeof(float32(0))*22))
			v7 = 0
			v10 = int32(uintptr(unsafe.Add(unsafe.Pointer(i), unsafe.Sizeof(float32(0))*22)))
			for {
				if sub_521AA0((*uint32)(unsafe.Pointer(i)), v7) == 0 {
					v8 = 0
					if int32(*((*uint8)(unsafe.Add(unsafe.Add(unsafe.Pointer(i), v7), 216)))) != 0 {
						for {
							if nox_xxx_mapGenCheckRoomType_5238F0((*int32)(unsafe.Pointer(*v6))) != 0 {
								sub_523D30(*v6, &v11.X)
							} else {
								sub_523C30(int32(uintptr(unsafe.Pointer(i))), unsafe.Pointer(&v11))
								sub_522CA0(int32(uintptr(unsafe.Pointer(*v6))), &v11.X)
							}
							sub_522C80(&v12.X)
							sub_522C80(&v11.X)
							sub_51D3F0(&v12, &v11)
							if *(*uint32)(unsafe.Add(a1, 60)) == 0 {
								sub_51D3F0(&v11, &v12)
							}
							v8++
							v6 = (**float32)(unsafe.Add(unsafe.Pointer(v6), unsafe.Sizeof((*float32)(nil))*1))
							if v8 >= int32(*((*uint8)(unsafe.Add(unsafe.Add(unsafe.Pointer(i), v7), 216)))) {
								break
							}
						}
					}
				}
				v7++
				v6 = (**float32)(unsafe.Add(v10, 32))
				v10 += 32
				if v7 >= 4 {
					break
				}
			}
		}
		result = (*float32)(unsafe.Pointer(uintptr(sub_521720(int32(uintptr(unsafe.Pointer(i)))))))
	}
	return result
}
func nox_xxx_mapGenTryNextRoom_522F40(a1 *uint32) *uint8 {
	var (
		result *uint8
		i      *uint8
		v3     int32
		v4     int32
		v5     int32
		v6     *types.Pointf
		v7     *types.Pointf
	)
	result = (*uint8)(unsafe.Pointer(a1))
	if *(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*15)) == 0 {
		result = (*uint8)(nox_xxx_mapGenGetTopRoom_521710())
		for i = result; result != nil; i = result {
			if *(*uint32)(unsafe.Pointer(i)) == 1 {
				nox_xxx_mapGenSetFlags_5235F0(-100)
				v3 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(i), 352)))
				v4 = 0
				if v3 > 0 {
					v7 = (*types.Pointf)(unsafe.Add(unsafe.Pointer(i), 224))
					for {
						v5 = 0
						if v3 > 0 {
							v6 = (*types.Pointf)(unsafe.Add(unsafe.Pointer(i), 224))
							for {
								if v4 != v5 {
									sub_51D3F0(v7, v6)
								}
								v5++
								v6 = (*types.Pointf)(unsafe.Add(unsafe.Pointer(v6), unsafe.Sizeof(types.Pointf{})*1))
								if v5 >= int32(*(*uint8)(unsafe.Add(unsafe.Pointer(i), 352))) {
									break
								}
							}
						}
						v3 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(i), 352)))
						v4++
						v7 = (*types.Pointf)(unsafe.Add(unsafe.Pointer(v7), unsafe.Sizeof(types.Pointf{})*1))
						if v4 >= v3 {
							break
						}
					}
				}
			}
			result = (*uint8)(unsafe.Pointer(uintptr(sub_521720(int32(uintptr(unsafe.Pointer(i)))))))
		}
	}
	return result
}
func nox_xxx_netSendPointFx_522FF0(a1 int8, a2 *types.Pointf) int32 {
	var buf [5]byte
	buf[0] = byte(a1)
	*(*uint16)(unsafe.Pointer(&buf[1])) = uint16(int16(int32(a2.X)))
	*(*uint16)(unsafe.Pointer(&buf[3])) = uint16(int16(int32(a2.Y)))
	return nox_xxx_netSendFxAllCli_523030(a2, unsafe.Pointer(&buf[0]), 5)
}
func nox_xxx_netSendFxAllCli_523030(a1 *types.Pointf, a2 unsafe.Pointer, a3 int32) int32 {
	var (
		result int32
		i      int32
		v5     int32
		v6     int32
		v7     float32
		v8     float32
		v9     float64
		v10    float64
		v11    float64
		v12    float32
		v13    float32
		v14    float32
		v15    float32
	)
	result = int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0())))
	for i = result; result != 0; i = result {
		v5 = int32(*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(i, 748)), 276)))
		if int32(*(*uint8)(unsafe.Add(v5, 3680)))&3 != 0 && (func() int32 {
			v6 = int32(*(*uint32)(unsafe.Add(v5, 3628)))
			return v6
		}()) != 0 {
			v7 = *(*float32)(unsafe.Add(v6, 56))
			v8 = *(*float32)(unsafe.Add(v6, 60))
			v12 = v7
		} else {
			v8 = *(*float32)(unsafe.Add(i, 60))
			v12 = *(*float32)(unsafe.Add(i, 56))
		}
		v9 = float64(*(*uint16)(unsafe.Add(v5, 10)))
		v13 = float32(float64(v12) - v9 - 50.0)
		v10 = v9 + float64(v12) + 50.0
		v11 = float64(*(*uint16)(unsafe.Add(v5, 12)))
		if float64(a1.X) > float64(v13) && v10 > float64(a1.X) {
			v14 = float32(float64(v8) - v11 - 50.0)
			if float64(a1.Y) > float64(v14) {
				v15 = float32(v11 + float64(v8) + 50.0)
				if float64(a1.Y) < float64(v15) {
					nox_netlist_addToMsgListCli_40EBC0(int32(*(*uint8)(unsafe.Add(v5, 2064))), 1, (*uint8)(a2), a3)
				}
			}
		}
		result = int32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(i)))))
	}
	return result
}
func sub_523150(a1 int8, a2 int8, a3 *float32) int32 {
	var v4 [6]byte
	v4[0] = byte(a1)
	v4[1] = byte(a2)
	*(*uint16)(unsafe.Pointer(&v4[2])) = uint16(int16(int32(*a3)))
	*(*uint16)(unsafe.Pointer(&v4[4])) = uint16(int16(int32(*(*float32)(unsafe.Add(unsafe.Pointer(a3), unsafe.Sizeof(float32(0))*1)))))
	return nox_xxx_netSendFxAllCli_523030((*types.Pointf)(unsafe.Pointer(a3)), unsafe.Pointer(&v4[0]), 6)
}
func nox_xxx_netSparkExplosionFx_5231B0(a1 *float32, a2 int8) int32 {
	var (
		v2 int16
		v3 float32
		v5 [6]byte
	)
	v5[0] = 147
	v2 = int16(int32(*a1))
	v3 = *(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*1))
	*(*uint16)(unsafe.Pointer(&v5[1])) = uint16(v2)
	*(*uint16)(unsafe.Pointer(&v5[3])) = uint16(int16(int32(v3)))
	v5[5] = byte(a2)
	return nox_xxx_netSendFxAllCli_523030((*types.Pointf)(unsafe.Pointer(a1)), unsafe.Pointer(&v5[0]), 6)
}
func nox_xxx_sendGeneratorBreakFX_523200(a1 *float32, a2 int8) {
	var (
		v2 int16
		v3 float32
		v5 [7]byte
	)
	v5[0] = 240
	v5[1] = 25
	v2 = int16(int32(*a1))
	v3 = *(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*1))
	*(*uint16)(unsafe.Pointer(&v5[2])) = uint16(v2)
	*(*uint16)(unsafe.Pointer(&v5[4])) = uint16(int16(int32(v3)))
	v5[6] = byte(a2)
	nox_xxx_netSendFxAllCli_523030((*types.Pointf)(unsafe.Pointer(a1)), unsafe.Pointer(&v5[0]), 7)
}
func nox_xxx_netSendVampFx_523270(a1 int8, a2 *int16, a3 int16) int32 {
	var (
		v3  int16
		v4  uint16
		v5  uint16
		a1a types.Pointf
		a2a [11]byte
	)
	a2a[0] = byte(a1)
	v3 = *(*int16)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(int16(0))*2))
	*(*uint16)(unsafe.Pointer(&a2a[1])) = uint16(*a2)
	v4 = uint16(*(*int16)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(int16(0))*4)))
	v5 = uint16(*(*int16)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(int16(0))*6)))
	*(*uint16)(unsafe.Pointer(&a2a[3])) = uint16(v3)
	*(*uint16)(unsafe.Pointer(&a2a[5])) = v4
	*(*uint16)(unsafe.Pointer(&a2a[7])) = v5
	a1a.X = float32(float64(v4))
	*(*uint16)(unsafe.Pointer(&a2a[9])) = uint16(a3)
	a1a.Y = float32(float64(v5))
	return nox_xxx_netSendFxAllCli_523030(&a1a, unsafe.Pointer(&a2a[0]), 11)
}
func nox_xxx_servCode_523340(a1 *int32, a2 unsafe.Pointer, a3 int32) int32 {
	var (
		result int32
		i      int32
		v5     int32
		v6     int32
		v7     float32
		v8     float32
		v9     float64
		v10    int8
		v11    float64
		v12    float64
		v13    float64
		v14    float64
		v15    float64
		v16    int8
		v17    float64
		v18    float32
		v19    int32
		v20    int32
		v21    int32
		v22    int32
		v23    float32
		v24    float32
		v25    float32
	)
	if *a1 >= *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*2)) {
		v19 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*2))
		v21 = *a1
	} else {
		v19 = *a1
		v21 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*2))
	}
	if *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1)) >= *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*3)) {
		v20 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*3))
		v22 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1))
	} else {
		v20 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1))
		v22 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*3))
	}
	result = int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0())))
	for i = result; result != 0; i = result {
		v5 = int32(*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(i, 748)), 276)))
		if int32(*(*uint8)(unsafe.Add(v5, 3680)))&3 != 0 && (func() int32 {
			v6 = int32(*(*uint32)(unsafe.Add(v5, 3628)))
			return v6
		}()) != 0 {
			v7 = *(*float32)(unsafe.Add(v6, 56))
			v8 = *(*float32)(unsafe.Add(v6, 60))
			v18 = v7
		} else {
			v8 = *(*float32)(unsafe.Add(i, 60))
			v18 = *(*float32)(unsafe.Add(i, 56))
		}
		v9 = float64(*(*uint16)(unsafe.Add(v5, 10)))
		v10 = 0
		v23 = float32(float64(v18) - v9 - 50.0)
		v11 = v9 + float64(v18) + 50.0
		v12 = float64(*(*uint16)(unsafe.Add(v5, 12)))
		v24 = float32(float64(v8) - v12 - 50.0)
		v25 = float32(v12 + float64(v8) + 50.0)
		v13 = float64(*a1)
		if v13 >= float64(v23) {
			if v13 > v11 {
				v10 = 8
			}
		} else {
			v10 = 4
		}
		v14 = float64(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1)))
		if v14 >= float64(v24) {
			if v14 > float64(v25) {
				v10 |= 2
			}
		} else {
			v10 |= 1
		}
		v15 = float64(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*2)))
		v16 = 0
		if v15 >= float64(v23) {
			if v15 > v11 {
				v16 = 8
			}
		} else {
			v16 = 4
		}
		v17 = float64(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*3)))
		if v17 >= float64(v24) {
			if v17 > float64(v25) {
				v16 |= 2
			}
		} else {
			v16 |= 1
		}
		if (int32(uint8(v16))&int32(uint8(v10))) == 0 && float64(v19) <= v11 && float64(v21) >= float64(v23) && float64(v20) <= float64(v25) && float64(v22) >= float64(v24) {
			nox_netlist_addToMsgListCli_40EBC0(int32(*(*uint8)(unsafe.Add(v5, 2064))), 1, (*uint8)(a2), a3)
		}
		result = int32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(i)))))
	}
	return result
}
func nox_xxx_netClientPredictLinear_523530(a1 int32) int32 {
	var (
		v1     int16
		v2     float64
		v3     int64
		v4     float64
		v5     int64
		v6     float64
		v7     int16
		v8     int64
		v9     float64
		v10    int64
		v11    float64
		result int32
		i      int32
		v14    [14]byte
	)
	v14[0] = 181
	v1 = int16(uint16(nox_xxx_netGetUnitCodeServ_578AC0((*server.Object)(a1))))
	v2 = float64(*(*float32)(unsafe.Add(a1, 56)))
	*(*uint16)(unsafe.Pointer(&v14[1])) = uint16(v1)
	*(*uint16)(unsafe.Pointer(&v14[3])) = *(*uint16)(unsafe.Add(a1, 4))
	v3 = int64(v2)
	v4 = float64(*(*float32)(unsafe.Add(a1, 60)))
	*(*uint16)(unsafe.Pointer(&v14[5])) = uint16(int16(v3))
	v5 = int64(v4)
	v6 = float64(*(*float32)(unsafe.Add(a1, 112))) * 16.0
	v7 = int16(*(*uint16)(unsafe.Add(a1, 124)))
	*(*uint16)(unsafe.Pointer(&v14[7])) = uint16(int16(v5))
	*(*uint16)(unsafe.Pointer(&v14[9])) = uint16(v7)
	v8 = int64(v6)
	v9 = float64(*(*float32)(unsafe.Add(a1, 80))) * 16.0
	v14[11] = byte(int8(v8))
	v10 = int64(v9)
	v11 = float64(*(*float32)(unsafe.Add(a1, 84))) * 16.0
	v14[12] = byte(int8(v10))
	v14[13] = byte(int8(int64(v11)))
	result = int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0())))
	for i = result; result != 0; i = result {
		nox_netlist_addToMsgListCli_40EBC0(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(i, 748)), 276)), 2064))), 1, &v14[0], 14)
		result = int32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(i)))))
	}
	return result
}
func nox_xxx_mapGenSetFlags_5235F0(a1 int8) {
	var v3 int32
	if !noxflags.HasGame(0x200000) {
		dword_5d4594_2487564 = nox_platform_get_ticks()
		if dword_5d4594_2487568 > dword_5d4594_2487564 {
			dword_5d4594_2487568 = 0
		}
		nox_input_pollEvents_4453A0()
		if dword_5d4594_2487564-dword_5d4594_2487568 > uint32(*memmap.PtrInt32(0x587000, 254948)) {
			*(*uint16)(unsafe.Add(unsafe.Pointer(&v3), 1)) = *memmap.PtrUint16(0x5D4594, 2487572)
			*((*uint8)(unsafe.Pointer(&v3))) = uint8(a1)
			*memmap.PtrUint32(0x5D4594, 2487572)++
			nox_xxx_mapGenClientText_4A9D00((*uint8)(unsafe.Pointer(&v3)))
			dword_5d4594_2487568 = dword_5d4594_2487564
		}
	}
}
func nox_xxx_netSendShieldFx_523670(a1 unsafe.Pointer, a2 *float32) int32 {
	var (
		v2 int8
		v3 int32
		v5 [4]byte
		v6 types.Pointf
	)
	v5[0] = 128
	*(*uint16)(unsafe.Pointer(&v5[1])) = uint16(nox_xxx_netGetUnitCodeServ_578AC0((*server.Object)(a1)))
	if a2 != nil {
		v6.X = *(*float32)(unsafe.Add(a1, 56)) - *a2
		v6.Y = *(*float32)(unsafe.Add(a1, 60)) - *(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*1))
		v3 = nox_xxx_math_509ED0(&v6)
		v2 = int8(nox_xxx_math_509EA0(v3))
	} else {
		v2 = int8(nox_xxx_math_509EA0(int32(*(*int16)(unsafe.Add(a1, 124)))))
	}
	v5[3] = byte(v2)
	return nox_xxx_netSendFxAllCli_523030((*types.Pointf)(unsafe.Add(a1, 56)), unsafe.Pointer(&v5[0]), 4)
}
func nox_xxx_sendSummonStartFX_5236F0(a1 int16, a2 *float32, a3 int8, a4 int16, a5 int16) int32 {
	var (
		v5 float64
		v6 int64
		v7 float64
		v9 [12]byte
	)
	v9[0] = 126
	*(*uint16)(unsafe.Pointer(&v9[5])) = uint16(a1)
	*(*uint16)(unsafe.Pointer(&v9[7])) = uint16(a4)
	v5 = float64(*a2)
	v9[9] = byte(a3)
	v6 = int64(v5)
	v7 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*1)))
	*(*uint16)(unsafe.Pointer(&v9[1])) = uint16(int16(v6))
	*(*uint16)(unsafe.Pointer(&v9[3])) = uint16(int16(int64(v7)))
	*(*uint16)(unsafe.Pointer(&v9[10])) = uint16(a5)
	return nox_xxx_netSendPacket0_4E5420(math.MaxUint8, unsafe.Pointer(&v9[0]), 12, nil, 1)
}
func nox_xxx_sendSummonCancelFX_523760(a1 int16) int32 {
	var v3 [3]byte
	v3[0] = math.MaxInt8
	*(*uint16)(unsafe.Pointer(&v3[1])) = uint16(a1)
	return nox_xxx_netSendPacket0_4E5420(math.MaxUint8, unsafe.Pointer(&v3[0]), 3, nil, 1)
}
func nox_xxx_netSendFxGreenBolt_523790(a1 *int4, a2 int16) int32 {
	var (
		v2  *int4
		v3  int32
		v4  float64
		v5  int16
		v7  int32
		a1a types.Pointf
		a2a [11]byte
		v10 *int4
	)
	v2 = a1
	a2a[0] = 152
	v7 = a1.field_0
	v3 = a1.field_4
	v4 = float64(a1.field_8 - a1.field_0)
	v10 = (*int4)(unsafe.Pointer(uintptr(a1.field_C - v3)))
	*(*uint16)(unsafe.Pointer(&a2a[3])) = uint16(int16(v2.field_4))
	v5 = int16(v2.field_C)
	*(*uint16)(unsafe.Pointer(&a2a[1])) = uint16(int16(v2.field_0))
	*(*uint16)(unsafe.Pointer(&a2a[5])) = uint16(int16(v2.field_8))
	*(*uint16)(unsafe.Pointer(&a2a[7])) = uint16(v5)
	*(*uint16)(unsafe.Pointer(&a2a[9])) = uint16(a2)
	a1a.X = float32(v4*0.5 + float64(v7))
	a1a.Y = float32(float64(int32(uintptr(unsafe.Pointer(v10))))*0.5 + float64(v3))
	return nox_xxx_netSendFxAllCli_523030(&a1a, unsafe.Pointer(&a2a[0]), 11)
}
func nox_xxx_sendGeneratorSpawnFX_523830(a1 *int4, a2 int16) {
	var (
		v2  float64
		v3  int16
		v4  int16
		v5  float64
		v6  int16
		a1a types.Pointf
		a2a [12]byte
	)
	a2a[0] = 240
	a2a[1] = 16
	v2 = float64(a1.field_8)
	v3 = int16(a1.field_0)
	*(*uint16)(unsafe.Pointer(&a2a[4])) = uint16(int16(a1.field_4))
	v4 = int16(a1.field_C)
	a1a.X = float32(v2)
	v5 = float64(a1.field_C)
	*(*uint16)(unsafe.Pointer(&a2a[2])) = uint16(v3)
	v6 = int16(a1.field_8)
	*(*uint16)(unsafe.Pointer(&a2a[8])) = uint16(v4)
	*(*uint16)(unsafe.Pointer(&a2a[6])) = uint16(v6)
	a1a.Y = float32(v5)
	*(*uint16)(unsafe.Pointer(&a2a[10])) = uint16(a2)
	nox_xxx_netSendFxAllCli_523030(&a1a, unsafe.Pointer(&a2a[0]), 12)
}
func nox_xxx_sendArrowTrapFX_5238A0(a1 *float32, a2 int8) {
	var (
		v2 int16
		v3 float32
		v5 [6]byte
	)
	v5[0] = 161
	v2 = nox_float2int16(*a1)
	v3 = *(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*1))
	*(*uint16)(unsafe.Pointer(&v5[1])) = uint16(v2)
	*(*uint16)(unsafe.Pointer(&v5[3])) = uint16(nox_float2int16(v3))
	v5[5] = byte(a2)
	nox_xxx_netSendFxAllCli_523030((*types.Pointf)(unsafe.Pointer(a1)), unsafe.Pointer(&v5[0]), 6)
}
func nox_xxx_mapGenCheckRoomType_5238F0(a1 *int32) int32 {
	var v1 int32
	v1 = *a1
	return bool2int32(*a1 == 2 || v1 == 3 || v1 == 4 || v1 == 5)
}
func sub_523920(a1 int32) int32 {
	switch a1 {
	case 2:
		return 0
	case 3:
		return 1
	case 4:
		return 2
	}
	if a1 != 5 {
		return 0
	}
	return 3
}
func sub_523960(a1 int32) int32 {
	return int32(*memmap.PtrUint32(0x587000, uintptr(a1*4)+254952))
}
func sub_523970(a1 int32) int32 {
	var result int32
	switch a1 {
	case 2:
		result = 3
	case 3:
		result = 2
	case 5:
		result = 1
	default:
		result = 0
	}
	return result
}
func sub_5239B0(a1 int32) int32 {
	var v1 int32
	v1 = sub_523970(a1)
	return sub_523960(v1)
}
func sub_523A10(a1 int32, a2 *float32) int32 {
	var (
		v2  float64
		v3  int32
		v4  float64
		v5  int32
		v7  float32
		v8  int32
		v9  float64
		v10 int32
		v11 float32
		v12 int32
		v13 float64
		v14 int32
		v15 float64
		v16 int32
		v17 float64
		v18 int32
		v19 types.Pointf
	)
	switch *(*uint32)(a1) {
	case 2:
		if float64(*(*float32)(unsafe.Add(a1, 36))) < float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*9))) || float64(*(*float32)(unsafe.Add(a1, 44))) > float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*11))) {
			return 0
		}
		v2 = float64(*(*float32)(unsafe.Add(a1, 24)))
		v19.X = *(*float32)(unsafe.Add(a1, 20))
		v3 = int32(*(*uint32)(unsafe.Add(a1, 16)))
		v19.Y = float32(v2)
		if v3 > 1 {
			for {
				v2 = v2 + 32.526913
				v4 = float64(*(*float32)(unsafe.Add(a1, 32))) - 32.526913
				v5 = int32(*(*uint32)(unsafe.Add(a1, 16)) - 1)
				*(*uint32)(unsafe.Add(a1, 16)) = uint32(v5)
				*(*float32)(unsafe.Add(a1, 32)) = float32(v4)
				if v2+0.1 > float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*12))) || v5 <= 1 {
					break
				}
			}
			v19.Y = float32(v2)
		}
		nox_xxx_mapGenSetRoomPos_521880((*uint32)(a1), &v19)
		return bool2int32(sub_521200(a1) == 0)
	case 3:
		if float64(*(*float32)(unsafe.Add(a1, 36))) < float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*9))) || float64(*(*float32)(unsafe.Add(a1, 44))) > float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*11))) {
			return 0
		}
		v7 = *(*float32)(unsafe.Add(a1, 24))
		v19.X = *(*float32)(unsafe.Add(a1, 20))
		v8 = int32(*(*uint32)(unsafe.Add(a1, 16)))
		v19.Y = v7
		if v8 <= 1 {
			nox_xxx_mapGenSetRoomPos_521880((*uint32)(a1), &v19)
			return bool2int32(sub_521200(a1) == 0)
		}
	case 4:
		if float64(*(*float32)(unsafe.Add(a1, 40))) < float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*10))) || float64(*(*float32)(unsafe.Add(a1, 48))) > float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*12))) {
			return 0
		}
		v11 = *(*float32)(unsafe.Add(a1, 24))
		v19.X = *(*float32)(unsafe.Add(a1, 20))
		v12 = int32(*(*uint32)(unsafe.Add(a1, 12)))
		v19.Y = v11
		if v12 > 1 {
			for {
				v13 = float64(*(*float32)(unsafe.Add(a1, 28))) - 32.526913
				v14 = int32(*(*uint32)(unsafe.Add(a1, 12)) - 1)
				*(*uint32)(unsafe.Add(a1, 12)) = uint32(v14)
				*(*float32)(unsafe.Add(a1, 28)) = float32(v13)
				if v13+float64(v19.X)-0.1 < float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*9))) || v14 <= 1 {
					break
				}
			}
		}
		nox_xxx_mapGenSetRoomPos_521880((*uint32)(a1), &v19)
		return bool2int32(sub_521200(a1) == 0)
	case 5:
		if float64(*(*float32)(unsafe.Add(a1, 40))) < float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*10))) || float64(*(*float32)(unsafe.Add(a1, 48))) > float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*12))) {
			return 0
		}
		v15 = float64(*(*float32)(unsafe.Add(a1, 20)))
		v19.Y = *(*float32)(unsafe.Add(a1, 24))
		v16 = int32(*(*uint32)(unsafe.Add(a1, 12)))
		v19.X = float32(v15)
		if v16 > 1 {
			for {
				v15 = v15 + 32.526913
				v17 = float64(*(*float32)(unsafe.Add(a1, 28))) - 32.526913
				v18 = int32(*(*uint32)(unsafe.Add(a1, 12)) - 1)
				*(*uint32)(unsafe.Add(a1, 12)) = uint32(v18)
				*(*float32)(unsafe.Add(a1, 28)) = float32(v17)
				if v15+0.1 > float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*11))) || v18 <= 1 {
					break
				}
			}
			v19.X = float32(v15)
		}
		nox_xxx_mapGenSetRoomPos_521880((*uint32)(a1), &v19)
		return bool2int32(sub_521200(a1) == 0)
	default:
		return bool2int32(sub_521200(a1) == 0)
	}
	for {
		v9 = float64(*(*float32)(unsafe.Add(a1, 32))) - 32.526913
		v10 = int32(*(*uint32)(unsafe.Add(a1, 16)) - 1)
		*(*uint32)(unsafe.Add(a1, 16)) = uint32(v10)
		*(*float32)(unsafe.Add(a1, 32)) = float32(v9)
		if v9+float64(v19.Y)-0.1 < float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*10))) {
			break
		}
		if v10 <= 1 {
			nox_xxx_mapGenSetRoomPos_521880((*uint32)(a1), &v19)
			return bool2int32(sub_521200(a1) == 0)
		}
	}
	nox_xxx_mapGenSetRoomPos_521880((*uint32)(a1), &v19)
	return bool2int32(sub_521200(a1) == 0)
}
func sub_523C30(a1 int32, a2 unsafe.Pointer) int32 {
	var (
		result int32
		v3     int32
	)
	result = a1
	switch *(*uint32)(a1) {
	case 2:
		*(*float32)(a2) = float32(float64(*(*float32)(unsafe.Add(a1, 44))+*(*float32)(unsafe.Add(a1, 36))) * 0.5)
		result = int32(*(*uint32)(unsafe.Add(a1, 40)))
		*(*uint32)(unsafe.Add(a2, 4)) = uint32(result)
	case 3:
		*(*float32)(a2) = float32(float64(*(*float32)(unsafe.Add(a1, 44))+*(*float32)(unsafe.Add(a1, 36))) * 0.5)
		*(*uint32)(unsafe.Add(a2, 4)) = *(*uint32)(unsafe.Add(a1, 48))
	case 4:
		v3 = int32(*(*uint32)(unsafe.Add(a1, 44)))
		*(*uint32)(a2) = uint32(v3)
		*(*float32)(unsafe.Add(a2, 4)) = float32(float64(*(*float32)(unsafe.Add(a1, 48))+*(*float32)(unsafe.Add(a1, 40))) * 0.5)
	case 5:
		v3 = int32(*(*uint32)(unsafe.Add(a1, 36)))
		*(*uint32)(a2) = uint32(v3)
		*(*float32)(unsafe.Add(a2, 4)) = float32(float64(*(*float32)(unsafe.Add(a1, 48))+*(*float32)(unsafe.Add(a1, 40))) * 0.5)
	default:
		return result
	}
	return result
}
func sub_523CB0(a1 int32, a2 unsafe.Pointer) int32 {
	var (
		result int32
		v3     int32
	)
	result = a1
	switch *(*uint32)(a1) {
	case 2:
		*(*float32)(a2) = float32(float64(*(*float32)(unsafe.Add(a1, 44))+*(*float32)(unsafe.Add(a1, 36))) * 0.5)
		result = int32(*(*uint32)(unsafe.Add(a1, 48)))
		*(*uint32)(unsafe.Add(a2, 4)) = uint32(result)
	case 3:
		*(*float32)(a2) = float32(float64(*(*float32)(unsafe.Add(a1, 44))+*(*float32)(unsafe.Add(a1, 36))) * 0.5)
		*(*uint32)(unsafe.Add(a2, 4)) = *(*uint32)(unsafe.Add(a1, 40))
	case 4:
		v3 = int32(*(*uint32)(unsafe.Add(a1, 36)))
		*(*uint32)(a2) = uint32(v3)
		*(*float32)(unsafe.Add(a2, 4)) = float32(float64(*(*float32)(unsafe.Add(a1, 48))+*(*float32)(unsafe.Add(a1, 40))) * 0.5)
	case 5:
		v3 = int32(*(*uint32)(unsafe.Add(a1, 44)))
		*(*uint32)(a2) = uint32(v3)
		*(*float32)(unsafe.Add(a2, 4)) = float32(float64(*(*float32)(unsafe.Add(a1, 48))+*(*float32)(unsafe.Add(a1, 40))) * 0.5)
	default:
		return result
	}
	return result
}
func sub_523D30(a1 *float32, a2 *float32) *float32 {
	var (
		result *float32
		v3     int32
		v4     *uint32
		v5     *uint32
		v6     float64
		v7     *uint32
		v8     *uint32
	)
	result = a1
	v3 = int32(*(*uint32)(unsafe.Pointer(a1)))
	if *(*uint32)(unsafe.Pointer(a1)) == 2 || v3 == 3 {
		v7 = (*uint32)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*22))))))
		if v7 != nil {
			v8 = (*uint32)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*30))))))
			if v8 != nil {
				if *v7 == 1 && *v8 == 1 {
					v6 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*11))+*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*9))) * 0.5
					*a2 = float32(v6)
					*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*1)) = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*12))+*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*10))) * 0.5)
					return result
				}
			}
		}
	} else {
		v4 = (*uint32)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*38))))))
		if v4 != nil {
			v5 = (*uint32)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*46))))))
			if v5 != nil {
				if *v4 == 1 && *v5 == 1 {
					v6 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*11))+*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*9))) * 0.5
					*a2 = float32(v6)
					*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*1)) = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*12))+*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*10))) * 0.5)
					return result
				}
			}
		}
	}
	switch v3 {
	case 2:
		*a2 = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*11))+*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*9))) * 0.5)
		*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*1)) = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*7)))*0.5 + float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*10))))
	case 3:
		*a2 = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*11))+*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*9))) * 0.5)
		*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*1)) = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*12))) - float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*7)))*0.5)
	case 4:
		v6 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*11))) - float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*8)))*0.5
		*a2 = float32(v6)
		*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*1)) = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*12))+*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*10))) * 0.5)
		return result
	case 5:
		v6 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*8)))*0.5 + float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*9)))
		*a2 = float32(v6)
		*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*1)) = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*12))+*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*10))) * 0.5)
		return result
	default:
		return result
	}
	return result
}
func sub_523E30(a1 int32, a2 int32, a3 int32) *float32 {
	var result *float32
	result = (*float32)(alloc.Calloc1(1, 0x178))
	if result != nil {
		*(*uint32)(unsafe.Pointer(result)) = uint32(a1)
		switch a1 {
		case 2, 3:
			*((*uint32)(unsafe.Add(unsafe.Pointer(result), 4*3))) = uint32(a2)
			if a2 < 1 {
				*((*uint32)(unsafe.Add(unsafe.Pointer(result), 4*3))) = 1
			}
			*((*uint32)(unsafe.Add(unsafe.Pointer(result), 4*4))) = uint32(a3)
		case 4, 5:
			*((*uint32)(unsafe.Add(unsafe.Pointer(result), 4*3))) = uint32(a3)
			*((*uint32)(unsafe.Add(unsafe.Pointer(result), 4*4))) = uint32(a2)
			if a2 < 1 {
				*((*uint32)(unsafe.Add(unsafe.Pointer(result), 4*4))) = 1
			}
		default:
		}
		*(*float32)(unsafe.Add(unsafe.Pointer(result), unsafe.Sizeof(float32(0))*7)) = float32(float64(*((*int32)(unsafe.Add(unsafe.Pointer(result), 4*3)))) * 32.526913)
		*(*float32)(unsafe.Add(unsafe.Pointer(result), unsafe.Sizeof(float32(0))*8)) = float32(float64(*((*int32)(unsafe.Add(unsafe.Pointer(result), 4*4)))) * 32.526913)
	}
	return result
}
func nox_xxx_mapGenMakeHall_523EC0(a1 int32, a2 int32, a3 int32) *float32 {
	var v3 int32
	v3 = nox_xxx_mapGenRandFunc2_526B00(int32(*(*uint32)(unsafe.Add(a1, 4))), int32(*(*uint32)(unsafe.Add(a1, 8))))
	return sub_523E30(a2, a3, v3)
}
func sub_524070(a1 int32, a2 int32) int32 {
	var result int32
	result = sub_524090(a2, (*int32)(unsafe.Add(a1, 184)))
	*(*uint32)(unsafe.Add(a2, 372)) = uint32(result)
	return result
}
func sub_524090(a1 int32, a2 *int32) int32 {
	var (
		v2 int32
		v3 int32
		v4 int32
		v5 int32
		i  int32
	)
	v2 = a1
	for i = 0; ; i++ {
	LABEL_2:
		switch *(*uint32)(unsafe.Add(a1, 364)) {
		case 1:
			v2 = *(*int32)(unsafe.Add(unsafe.Pointer(a2), 4*2))
		case 2:
			v2 = *(*int32)(unsafe.Add(unsafe.Pointer(a2), 4*3))
		case 4:
			v2 = *(*int32)(unsafe.Add(unsafe.Pointer(a2), 4*4))
		case 8:
			v2 = *(*int32)(unsafe.Add(unsafe.Pointer(a2), 4*5))
		case 0x10:
			v2 = *(*int32)(unsafe.Add(unsafe.Pointer(a2), 4*6))
		case 0x20:
			v2 = *(*int32)(unsafe.Add(unsafe.Pointer(a2), 4*7))
		default:
		}
		if v2 <= 0 {
			nullsub_28(uint32(a1))
			return 0
		}
		v3 = nox_xxx_mapGenRandFunc_526AC0(0, v2)
		v4 = *a2
		v5 = v3
		if *a2 != 0 {
			for {
				if nox_xxx_mapGenDecorChkConstaint_5241C0(v4, a1) != 0 {
					v5 -= int32(*(*uint32)(unsafe.Add(v4, 72)))
					if v5 <= 0 {
						break
					}
				}
				v4 = int32(*(*uint32)(unsafe.Add(v4, 220)))
				if v4 == 0 {
					i++
					goto LABEL_2
				}
			}
			if nox_xxx_mapGenChkDecorFillsRoom_5241F0(v4, a1) != 0 && int32(*(*uint8)(unsafe.Add(v4, 66))) == 0 {
				nox_xxx_mapGenDecorChkLimit_524220(a2, v4)
				return v4
			}
			if i >= 100 {
				break
			}
		}
	}
	nullsub_28(uint32(a1))
	return 0
}
func nox_xxx_mapGenDecorChkConstaint_5241C0(a1 int32, a2 int32) int32 {
	var v2 uint8
	v2 = *(*uint8)(unsafe.Add(a1, 64))
	return bool2int32(int32(*(*uint8)(unsafe.Add(a2, 364)))&int32(v2) != 0 || int32(v2) == 0)
}
func nox_xxx_mapGenChkDecorFillsRoom_5241F0(a1 int32, a2 int32) int32 {
	var v2 int32
	v2 = int32(*(*uint32)(unsafe.Add(a2, 12)))
	if v2 <= *(*int32)(unsafe.Add(a2, 16)) {
		v2 = int32(*(*uint32)(unsafe.Add(a2, 16)))
	}
	return bool2int32(v2 >= *(*int32)(unsafe.Add(a1, 76)) && v2 <= *(*int32)(unsafe.Add(a1, 80)))
}
func nox_xxx_mapGenDecorChkLimit_524220(a1 *int32, a2 int32) int8 {
	var (
		i  int32
		v3 int32
		v4 int32
	)
	*((*uint8)(unsafe.Pointer(&i))) = *(*uint8)(unsafe.Add(a2, 65))
	if int32(uint8(int8(i))) != 0 {
		*((*uint8)(unsafe.Pointer(&i))) = uint8(int8(i - 1))
		*(*uint8)(unsafe.Add(a2, 65)) = uint8(int8(i))
		if int32(uint8(int8(i))) == 0 {
			if int32(*(*uint8)(unsafe.Add(a2, 64)))&2 != 0 {
				*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*3)) -= int32(*(*uint32)(unsafe.Add(a2, 72)))
			}
			if int32(*(*uint8)(unsafe.Add(a2, 64)))&4 != 0 {
				*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*4)) -= int32(*(*uint32)(unsafe.Add(a2, 72)))
			}
			if int32(*(*uint8)(unsafe.Add(a2, 64)))&8 != 0 {
				*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*5)) -= int32(*(*uint32)(unsafe.Add(a2, 72)))
			}
			if int32(*(*uint8)(unsafe.Add(a2, 64)))&0x10 != 0 {
				*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*6)) -= int32(*(*uint32)(unsafe.Add(a2, 72)))
			}
			i = *a1
			v3 = 0
			if *a1 != 0 {
				for {
					if i == a2 {
						break
					}
					v3 = i
					i = int32(*(*uint32)(unsafe.Add(i, 220)))
					if i == 0 {
						break
					}
				}
			}
			if v3 != 0 {
				i = int32(*(*uint32)(unsafe.Add(a2, 220)))
				*(*uint32)(unsafe.Add(v3, 220)) = uint32(i)
			} else {
				*a1 = int32(*(*uint32)(unsafe.Add(a2, 220)))
			}
			v4 = *a1
			if *a1 != 0 {
				for i = int32(*(*uint32)(unsafe.Add(v4, 220))); i != 0; i = int32(*(*uint32)(unsafe.Add(i, 220))) {
					v4 = i
				}
				*(*uint32)(unsafe.Add(v4, 220)) = uint32(a2)
				*(*uint32)(unsafe.Add(a2, 220)) = 0
				*(*uint8)(unsafe.Add(a2, 66)) = 1
			} else {
				*a1 = a2
				*(*uint32)(unsafe.Add(a2, 220)) = 0
				*(*uint8)(unsafe.Add(a2, 66)) = 1
			}
		}
	}
	return int8(i)
}
func nox_xxx_mapGenMakeRooms_524310(a1 int32) int32 {
	var (
		v1  int32
		v2  int32
		v3  int32
		v4  *int32
		v5  int32
		v6  *int32
		v7  int32
		v8  *int32
		v9  *int32
		v10 int32
		v12 *int32
	)
	v1 = a1
	v12 = (*int32)(unsafe.Add(a1, 88))
	v2 = *v12
	if *v12 != 0 {
		for {
			v3 = int32(*(*uint32)(unsafe.Add(v2, 220)))
			if int32(*(*uint8)(unsafe.Add(v2, 67))) != 0 && int32(*(*uint8)(unsafe.Add(v2, 68))) == 0 {
				v4 = (*int32)(nox_xxx_mapGenGetTopRoom_521710())
				if v4 == nil {
					break
				}
				for *(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*93)) != 0 || nox_xxx_mapGenCheckRoomType_5238F0(v4) != 0 || nox_xxx_mapGenDecorChkConstaint_5241C0(v2, int32(uintptr(unsafe.Pointer(v4)))) == 0 || nox_xxx_mapGenChkDecorFillsRoom_5241F0(v2, int32(uintptr(unsafe.Pointer(v4)))) == 0 || int32(*(*uint8)(unsafe.Add(v2, 66))) != 0 {
					v4 = (*int32)(unsafe.Pointer(uintptr(sub_521720(int32(uintptr(unsafe.Pointer(v4)))))))
					if v4 == nil {
						return 0
					}
				}
				nox_xxx_mapGenDecorChkLimit_524220(v12, v2)
				*(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*93)) = v2
				*(*uint8)(unsafe.Add(v2, 68)) = 1
				if v4 == nil {
					break
				}
			}
			v2 = v3
			if v3 == 0 {
				goto LABEL_14
			}
		}
		return 0
	}
LABEL_14:
	v5 = int32(*(*uint32)(unsafe.Add(v1, 120)))
	v6 = (*int32)(unsafe.Add(v1, 120))
	if v5 != 0 {
		for {
			v7 = int32(*(*uint32)(unsafe.Add(v5, 220)))
			if int32(*(*uint8)(unsafe.Add(v5, 67))) != 0 && int32(*(*uint8)(unsafe.Add(v5, 68))) == 0 {
				v8 = (*int32)(nox_xxx_mapGenGetTopRoom_521710())
				if v8 == nil {
					break
				}
				for *(*int32)(unsafe.Add(unsafe.Pointer(v8), 4*93)) != 0 || nox_xxx_mapGenCheckRoomType_5238F0(v8) == 0 || nox_xxx_mapGenDecorChkConstaint_5241C0(v5, int32(uintptr(unsafe.Pointer(v8)))) == 0 || nox_xxx_mapGenChkDecorFillsRoom_5241F0(v5, int32(uintptr(unsafe.Pointer(v8)))) == 0 || int32(*(*uint8)(unsafe.Add(v5, 66))) != 0 {
					v8 = (*int32)(unsafe.Pointer(uintptr(sub_521720(int32(uintptr(unsafe.Pointer(v8)))))))
					if v8 == nil {
						return 0
					}
				}
				nox_xxx_mapGenDecorChkLimit_524220(v6, v5)
				*(*int32)(unsafe.Add(unsafe.Pointer(v8), 4*93)) = v5
				*(*uint8)(unsafe.Add(v5, 68)) = 1
				if v8 == nil {
					break
				}
			}
			v5 = v7
			if v7 == 0 {
				goto LABEL_27
			}
		}
		return 0
	}
LABEL_27:
	v9 = (*int32)(nox_xxx_mapGenGetTopRoom_521710())
	if v9 == nil {
		return 1
	}
	for {
		if *(*int32)(unsafe.Add(unsafe.Pointer(v9), 4*93)) == 0 {
			if nox_xxx_mapGenCheckRoomType_5238F0(v9) != 0 {
				v10 = sub_524090(int32(uintptr(unsafe.Pointer(v9))), v6)
			} else {
				v10 = sub_524090(int32(uintptr(unsafe.Pointer(v9))), v12)
			}
			*(*int32)(unsafe.Add(unsafe.Pointer(v9), 4*93)) = v10
			if v10 == 0 {
				break
			}
		}
		v9 = (*int32)(unsafe.Pointer(uintptr(sub_521720(int32(uintptr(unsafe.Pointer(v9)))))))
		if v9 == nil {
			return 1
		}
	}
	return 0
}
func sub_5244D0(a1 int32) int32 {
	var (
		v1     int32
		result int32
	)
	v1 = nox_xxx_mapGenRandFunc_526AC0(0, int32(*(*uint32)(unsafe.Add(a1, 88))-1))
	for result = int32(*(*uint32)(unsafe.Add(a1, 84))); v1 != 0; v1-- {
		result = int32(*(*uint32)(unsafe.Add(result, 124)))
	}
	return result
}
func sub_524500(a1 *types.Pointf, a2 int32) int32 {
	var (
		v2     float32
		result int32
		v4     int32
		v5     types.Pointf
	)
	v2 = a1.Y
	v5.X = a1.X
	v5.Y = v2
	sub_526D50(0)
	result = a2
	if a2 > 0 {
		v4 = a2
		for {
			result = sub_526E60(&v5.X)
			v4--
			v5.X = float32(float64(v5.X) + 32.526913)
			if v4 == 0 {
				break
			}
		}
	}
	return result
}
func sub_524550(a1 *int32, a2 int32) int32 {
	var (
		v2     int32
		result int32
		v4     int32
		v5     int32
		v6     float32
	)
	v2 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1))
	v5 = *a1
	v6 = v2
	result = sub_526D50(1)
	v4 = a2
	if a2 > 0 {
		for {
			result = sub_526E60((*float32)(unsafe.Pointer(&v5)))
			v4--
			v6 = float32(float64(v6) + 32.526913)
			if v4 == 0 {
				break
			}
		}
	}
	return result
}
func sub_5245A0(a1 int32, a2 *float32, a3 int32, a4 int32) *float32 {
	var (
		result *float32
		v5     int32
		v6     int32
		v7     float32
		v8     float32
	)
	result = (*float32)(a4)
	v8 = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*1))) + 16.263456)
	if a4 > 0 {
		v5 = a4
		for {
			v7 = float32(float64(*a2) + 16.263456)
			if a3 > 0 {
				v6 = a3
				for {
					result = sub_51D5E0(&v7)
					v6--
					v7 = float32(float64(v7) + 32.526913)
					if v6 == 0 {
						break
					}
				}
			}
			v5--
			v8 = float32(float64(v8) + 32.526913)
			if v5 == 0 {
				break
			}
		}
	}
	return result
}
func sub_524610(a1 int32, a2 *float32, a3 int32) *float32 {
	var (
		result *float32
		v4     int32
		v5     float32
		v6     float32
	)
	result = a2
	v4 = a3
	v5 = float32(float64(*a2) + 16.263456)
	v6 = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*1))) + 16.263456)
	if a3 > 0 {
		for {
			result = sub_51D5E0(&v5)
			v4--
			v6 = float32(float64(v6) + 32.526913)
			if v4 == 0 {
				break
			}
		}
	}
	return result
}
func sub_524660(a1 float32, a2 float32) int32 {
	return bool2int32(math.Abs(float64(a1-a2)) < *mem_getDoublePtr(0x581450, 10432))
}
func nox_xxx_gen_524680(a1 int32, a2 int32, a3 int32) int32 {
	var (
		v3     *float32
		v4     float64
		result int32
		v6     int32
		v7     *uint32
		v8     *uint32
		v9     *uint32
		v10    float32
		v11    *uint32
		v12    float64
		v13    int32
		v14    float64
		v15    *uint32
		v16    *uint32
		v17    float64
		v18    *uint32
		v19    *uint32
		i      *uint32
		v21    int32 = 0
		v22    int32 = 0
		v23    float32
		v24    float32
	)
	nox_xxx_tileGetDefByName_51D4D0((*byte)(unsafe.Add(a3, 60)))
	v3 = (*float32)(unsafe.Add(a2, 20))
	sub_5245A0(a1, (*float32)(unsafe.Add(a2, 20)), int32(*(*uint32)(unsafe.Add(a2, 12))), int32(*(*uint32)(unsafe.Add(a2, 16))))
	switch *(*uint32)(a2) {
	case 1:
		v4 = float64(*v3) + 32.526913
		result = int32(*(*uint32)(unsafe.Add(a2, 12)) - 2)
		v6 = int32(*(*uint32)(unsafe.Add(a2, 16)) - 2)
		v21 = int32(*(*uint32)(unsafe.Add(a2, 12)) - 2)
		v22 = v6
		v23 = float32(v4)
		v24 = float32(float64(*(*float32)(unsafe.Add(a2, 24))) + 32.526913)
	case 2:
		v7 = *(**uint32)(unsafe.Add(a2, 88))
		result = int32(*(*uint32)(unsafe.Add(a2, 12)) - 2)
		v23 = float32(float64(*v3) + 32.526913)
		v21 = result
		if v7 != nil && *v7 != 1 {
			v24 = *(*float32)(unsafe.Add(a2, 24))
			v6 = int32(*(*uint32)(unsafe.Add(a2, 16)))
		} else {
			v6 = int32(*(*uint32)(unsafe.Add(a2, 16)) - 1)
			v24 = float32(float64(*(*float32)(unsafe.Add(a2, 24))) + 32.526913)
		}
		v8 = *(**uint32)(unsafe.Add(a2, 120))
		v22 = v6
		if v8 != nil {
			if *v8 != 1 {
				v22 = func() int32 {
					p := &v6
					*p++
					return *p
				}()
				break
			}
			v22 = func() int32 {
				p := &v6
				*p--
				return *p
			}()
		}
	case 3:
		v9 = *(**uint32)(unsafe.Add(a2, 120))
		v10 = *(*float32)(unsafe.Add(a2, 24))
		result = int32(*(*uint32)(unsafe.Add(a2, 12)) - 2)
		v23 = float32(float64(*v3) + 32.526913)
		v24 = v10
		v21 = result
		if v9 != nil && *v9 != 1 {
			v6 = int32(*(*uint32)(unsafe.Add(a2, 16)))
		} else {
			v6 = int32(*(*uint32)(unsafe.Add(a2, 16)) - 1)
		}
		v11 = *(**uint32)(unsafe.Add(a2, 88))
		v22 = v6
		if v11 != nil {
			v12 = float64(v24)
			if *v11 == 1 {
				v22 = func() int32 {
					p := &v6
					*p--
					return *p
				}()
				v24 = float32(v12 + 32.526913)
			} else {
				v24 = float32(v12 - 32.526913)
				v22 = func() int32 {
					p := &v6
					*p++
					return *p
				}()
			}
		}
	case 4:
		v13 = int32(*(*uint32)(unsafe.Add(a2, 16)))
		v14 = float64(*(*float32)(unsafe.Add(a2, 24))) + 32.526913
		v23 = *v3
		v15 = *(**uint32)(unsafe.Add(a2, 152))
		v6 = v13 - 2
		v24 = float32(v14)
		v22 = v6
		if v15 != nil && *v15 != 1 {
			result = int32(*(*uint32)(unsafe.Add(a2, 12)))
		} else {
			result = int32(*(*uint32)(unsafe.Add(a2, 12)) - 1)
		}
		v16 = *(**uint32)(unsafe.Add(a2, 184))
		v21 = result
		if v16 != nil {
			v17 = float64(v23)
			if *v16 != 1 {
				v23 = float32(v17 - 32.526913)
				v21 = func() int32 {
					p := &result
					*p++
					return *p
				}()
				break
			}
			v21 = func() int32 {
				p := &result
				*p--
				return *p
			}()
			v23 = float32(v17 + 32.526913)
		}
	case 5:
		v18 = *(**uint32)(unsafe.Add(a2, 184))
		v6 = int32(*(*uint32)(unsafe.Add(a2, 16)) - 2)
		v24 = float32(float64(*(*float32)(unsafe.Add(a2, 24))) + 32.526913)
		v22 = v6
		if v18 != nil && *v18 != 1 {
			result = int32(*(*uint32)(unsafe.Add(a2, 12)))
			v23 = *v3
		} else {
			result = int32(*(*uint32)(unsafe.Add(a2, 12)) - 1)
			v23 = float32(float64(*v3) + 32.526913)
		}
		v19 = *(**uint32)(unsafe.Add(a2, 152))
		v21 = result
		if v19 != nil {
			if *v19 == 1 {
				v21 = func() int32 {
					p := &result
					*p--
					return *p
				}()
			} else {
				v21 = func() int32 {
					p := &result
					*p++
					return *p
				}()
			}
		}
	default:
		v6 = v22
		result = v21
	}
	for i = *(**uint32)(unsafe.Add(a3, 120)); i != nil; i = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(i), 4*31))) {
		if result <= 0 || v6 <= 0 {
			break
		}
		if *i == 1 {
			sub_5249C0(a1, int32(uintptr(unsafe.Pointer(i))), &v23, &v21)
		} else if *i == 2 {
			sub_524B50(a1, int32(uintptr(unsafe.Pointer(i))), &v23, &v21)
		} else {
			sub_524950(a1, int32(uintptr(unsafe.Pointer(i))), &v23, &v21)
		}
		result = v21 - 2
		v6 = v22 - 2
		v21 -= 2
		v22 -= 2
		v23 = float32(float64(v23) + 32.526913)
		v24 = float32(float64(v24) + 32.526913)
	}
	return result
}
func sub_524950(a1 int32, a2 int32, a3 *float32, a4 *int32) int32 {
	var (
		v5 float32
		v6 float32
	)
	_ = v6
	nox_xxx_tileGetDefByName_51D4D0((*byte)(unsafe.Add(a2, 64)))
	sub_5245A0(a1, a3, *a4, *(*int32)(unsafe.Add(unsafe.Pointer(a4), 4*1)))
	sub_544020((*byte)(unsafe.Add(a2, 4)))
	v5 = float32(float64(*a4)*16.263456 + float64(*a3))
	v6 = float32(float64(*(*int32)(unsafe.Add(unsafe.Pointer(a4), 4*1)))*16.263456 + float64(*(*float32)(unsafe.Add(unsafe.Pointer(a3), unsafe.Sizeof(float32(0))*1))))
	return sub_543680(&v5)
}
func sub_5249C0(a1 int32, a2 int32, a3 *float32, a4 *int32) int32 {
	var (
		v4  *int32
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v9  float64
		v10 int32
		v11 float64
		v12 int32
		v13 bool
		v14 int32
		v15 int32
		v16 int32
		v17 int32
		v19 float32
		v20 float32
		v21 float32
		v22 float32
		v23 float32
	)
	_ = v23
	var v24 int32
	nox_xxx_tileGetDefByName_51D4D0((*byte)(unsafe.Add(a2, 64)))
	v4 = a4
	v5 = *a4
	v6 = *a4 / 3
	v7 = *(*int32)(unsafe.Add(unsafe.Pointer(a4), 4*1))
	v8 = v6 * 2
	v24 = 0
	v9 = float64(v6) * 32.526913
	v10 = v5 - v6*2
	v19 = float32(v9)
	v11 = v9 + float64(*a3)
	v21 = *(*float32)(unsafe.Add(unsafe.Pointer(a3), unsafe.Sizeof(float32(0))*1))
	v20 = float32(v11)
	if v7/2 >= 0 {
		for {
			sub_5245A0(a1, &v20, v10, 1)
			v12 = *v4
			v10 += 2
			v13 = v10 < *v4
			v20 = float32(float64(v20) - 32.526913)
			v21 = float32(float64(v21) + 32.526913)
			if !v13 {
				v10 = v12
				v20 = *a3
			}
			v24++
			if v24 > *(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*1))/2 {
				break
			}
		}
	}
	v14 = *(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*1))
	v15 = *v4 - v8
	v16 = 0
	v20 = v19 + *a3
	v21 = float32(float64(v14-1)*32.526913 + float64(*(*float32)(unsafe.Add(unsafe.Pointer(a3), unsafe.Sizeof(float32(0))*1))))
	if v14/2 > 0 {
		for {
			sub_5245A0(a1, &v20, v15, 1)
			v17 = *v4
			v15 += 2
			v13 = v15 < *v4
			v20 = float32(float64(v20) - 32.526913)
			v21 = float32(float64(v21) - 32.526913)
			if !v13 {
				v15 = v17
				v20 = *a3
			}
			v16++
			if v16 >= *(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*1))/2 {
				break
			}
		}
	}
	sub_544020((*byte)(unsafe.Add(a2, 4)))
	v22 = float32(float64(*v4)*16.263456 + float64(*a3))
	v23 = float32(float64(*(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*1)))*16.263456 + float64(*(*float32)(unsafe.Add(unsafe.Pointer(a3), unsafe.Sizeof(float32(0))*1))))
	return sub_543680(&v22)
}
func sub_524B50(a1 int32, a2 int32, a3 *float32, a4 *int32) {
	var (
		v4  *int32
		v5  int32
		v7  int32
		v8  int32
		v9  int32
		v10 int32
		v11 int32
		v12 int32
		v13 int32
		v14 int32
		v15 float32
		v16 int32
		v17 int32
		v18 int32
		v19 int32
		v20 int32
		v21 float32
		v22 float32
		v23 float32
		v24 float32
		v25 float32
	)
	_ = v25
	var v26 int32
	var v27 int32
	v4 = a4
	if *a4 >= 3 && *(*int32)(unsafe.Add(unsafe.Pointer(a4), 4*1)) >= 3 {
		nox_xxx_tileGetDefByName_51D4D0((*byte)(unsafe.Add(a2, 64)))
		v5 = *a4 - 2
		v22 = float32(float64(*a3) + 32.526913)
		v23 = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(a3), unsafe.Sizeof(float32(0))*1))) + 32.526913)
		if v5 < 1 {
			v5 = 1
		}
		v7 = *(*int32)(unsafe.Add(unsafe.Pointer(a4), 4*1)) - 2
		if v7 < 1 {
			v7 = 1
		}
		sub_5245A0(a1, &v22, v5, v7)
		v8 = *a4
		if *a4 < 4 {
			if v8 == 3 {
				v15 = *(*float32)(unsafe.Add(unsafe.Pointer(a3), unsafe.Sizeof(float32(0))*1))
				v22 = float32(float64(*a3) + 32.526913)
				v23 = v15
				sub_5245A0(a1, &v22, 1, 1)
				v23 = float32(float64(v23) + 65.053825)
				sub_5245A0(a1, &v22, 1, 1)
			}
		} else {
			v9 = nox_xxx_mapGenRandFunc_526AC0(1, v8-3)
			v10 = v9
			v11 = nox_xxx_mapGenRandFunc_526AC0(1, *a4-v9-2)
			v23 = *(*float32)(unsafe.Add(unsafe.Pointer(a3), unsafe.Sizeof(float32(0))*1))
			v22 = float32(float64(v11)*32.526913 + float64(*a3))
			sub_5245A0(a1, &v22, v10, 1)
			v12 = nox_xxx_mapGenRandFunc_526AC0(1, *a4-3)
			v13 = v12
			v14 = nox_xxx_mapGenRandFunc_526AC0(1, *a4-v12-2)
			v26 = *(*int32)(unsafe.Add(unsafe.Pointer(a4), 4*1)) - 1
			v22 = float32(float64(v14)*32.526913 + float64(*a3))
			v23 = float32(float64(v26)*32.526913 + float64(*(*float32)(unsafe.Add(unsafe.Pointer(a3), unsafe.Sizeof(float32(0))*1))))
			sub_5245A0(a1, &v22, v13, 1)
		}
		v16 = *(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*1))
		if v16 < 4 {
			if v16 == 3 {
				v21 = *a3
				v23 = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(a3), unsafe.Sizeof(float32(0))*1))) + 32.526913)
				v22 = v21
				sub_5245A0(a1, &v22, 1, 1)
				v22 = float32(float64(v22) + 65.053825)
				sub_5245A0(a1, &v22, 1, 1)
			}
		} else {
			v17 = nox_xxx_mapGenRandFunc_526AC0(1, v16-3)
			v18 = v17
			v19 = nox_xxx_mapGenRandFunc_526AC0(1, *(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*1))-v17-2)
			v22 = *a3
			v23 = float32(float64(v19)*32.526913 + float64(*(*float32)(unsafe.Add(unsafe.Pointer(a3), unsafe.Sizeof(float32(0))*1))))
			sub_524610(a1, &v22, v18)
			v20 = nox_xxx_mapGenRandFunc_526AC0(1, *(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*1))-3)
			v27 = nox_xxx_mapGenRandFunc_526AC0(1, *(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*1))-v20-2)
			v22 = float32(float64(*v4-1)*32.526913 + float64(*a3))
			v23 = float32(float64(v27)*32.526913 + float64(*(*float32)(unsafe.Add(unsafe.Pointer(a3), unsafe.Sizeof(float32(0))*1))))
			sub_524610(a1, &v22, v20)
		}
		sub_544020((*byte)(unsafe.Add(a2, 4)))
		v24 = float32(float64(*v4)*16.263456 + float64(*a3))
		v25 = float32(float64(*(*int32)(unsafe.Add(unsafe.Pointer(v4), 4*1)))*16.263456 + float64(*(*float32)(unsafe.Add(unsafe.Pointer(a3), unsafe.Sizeof(float32(0))*1))))
		sub_543680(&v24)
	}
}
func nox_xxx_gen_524E00(a1 int32, a2 int32) {
	var (
		v2  int32
		v3  *byte
		v4  float32
		v5  float32
		v6  float32
		v7  float32
		v8  float64
		v9  float64
		v10 int32
		v11 *int32
		v12 int32
		v13 int32
		v14 int32
		v15 int32
		v16 int32
		v17 types.Pointf
		v18 int32
	)
	v2 = a2
	if (int32(*(*uint8)(unsafe.Add(a2, 52))) & 2) == 0 {
		v3 = (*byte)(unsafe.Pointer(uintptr(sub_5244D0(int32(*(*uint32)(unsafe.Add(a2, 372)))))))
		nox_xxx_gen_524680(a1, a2, int32(uintptr(unsafe.Pointer(v3))))
		sub_526CA0(v3)
		v4 = *(*float32)(unsafe.Add(a2, 40))
		v17.X = *(*float32)(unsafe.Add(a2, 36))
		v17.Y = v4
		sub_526D50(8)
		sub_526E60(&v17.X)
		v15 = int32(*(*uint32)(unsafe.Add(a2, 12)) - 1)
		v17.X = float32(float64(v17.X) + 32.526913)
		sub_524500(&v17, v15)
		v5 = *(*float32)(unsafe.Add(a2, 40))
		v17.X = *(*float32)(unsafe.Add(a2, 44))
		v17.Y = v5
		sub_526D50(9)
		sub_526E60(&v17.X)
		v6 = *(*float32)(unsafe.Add(a2, 48))
		v17.X = *(*float32)(unsafe.Add(a2, 36))
		v17.Y = v6
		sub_526D50(7)
		sub_526E60(&v17.X)
		v14 = int32(*(*uint32)(unsafe.Add(a2, 12)) - 1)
		v17.X = float32(float64(v17.X) + 32.526913)
		sub_524500(&v17, v14)
		v7 = *(*float32)(unsafe.Add(a2, 48))
		v17.X = *(*float32)(unsafe.Add(a2, 44))
		v17.Y = v7
		sub_526D50(10)
		sub_526E60(&v17.X)
		v8 = float64(*(*float32)(unsafe.Add(a2, 40))) + 32.526913
		v16 = int32(*(*uint32)(unsafe.Add(a2, 16)) - 1)
		v17.X = *(*float32)(unsafe.Add(a2, 36))
		v17.Y = float32(v8)
		sub_524550((*int32)(unsafe.Pointer(&v17)), v16)
		v9 = float64(*(*float32)(unsafe.Add(a2, 40))) + 32.526913
		v10 = int32(*(*uint32)(unsafe.Add(a2, 16)) - 1)
		v17.X = *(*float32)(unsafe.Add(a2, 44))
		v17.Y = float32(v9)
		sub_524550((*int32)(unsafe.Pointer(&v17)), v10)
		sub_526C80(0)
		v11 = (*int32)(unsafe.Add(a2, 88))
		v12 = 0
		v18 = a2 + 88
		for {
			v13 = 0
			if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v2+v12)), 216))) != 0 {
				for {
					sub_524FB0(v2, *v11, v12)
					v13++
					v11 = (*int32)(unsafe.Add(unsafe.Pointer(v11), 4*1))
					if v13 >= int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v2+v12)), 216))) {
						break
					}
				}
			}
			v12++
			v11 = (*int32)(unsafe.Add(v18, 32))
			v18 += 32
			if v12 >= 4 {
				break
			}
		}
		sub_526C80(1)
		nox_xxx_mapgen_525510(a1, v2)
	}
}
func sub_524FB0(a1 int32, a2 int32, a3 int32) int32 {
	var (
		result int32
		v4     float64
		v5     int32
		v6     int32
		v7     int32
		v8     float32
		v9     float64
		v10    float32
		v11    int32
		v12    int32
		v13    int32
		v14    float64
		v15    float32
		v16    float64
		v17    float64
		v18    float64
		v19    int32
		v20    int32
		v21    int32
		v22    float64
		v23    float64
		v24    float64
		v25    float64
		v26    float64
		v27    int32
		v28    int32
		v29    int32
		v30    float64
		v31    float64
		v32    float64
		a2a    types.Pointf
		v34    types.Pointf
	)
	result = a3
	switch a3 {
	case 0:
		if float64(*(*float32)(unsafe.Add(a2, 36))) >= float64(*(*float32)(unsafe.Add(a1, 36))) {
			v4 = float64(*(*float32)(unsafe.Add(a2, 36)))
		} else {
			v4 = float64(*(*float32)(unsafe.Add(a1, 36)))
		}
		v5 = int32(*(*uint32)(unsafe.Add(a1, 12)))
		a2a.Y = *(*float32)(unsafe.Add(a1, 40))
		v6 = int32(*(*uint32)(unsafe.Add(a2, 12)))
		a2a.X = float32(v4)
		if v5 >= v6 {
			v7 = v6
			sub_521BC0(a1, &a2a, *(*float32)(unsafe.Add(a2, 28)), 32.526913)
		} else {
			v7 = v5
			sub_521BC0(a1, &a2a, *(*float32)(unsafe.Add(a1, 28)), 32.526913)
		}
		v34.X = float32(float64(a2a.X) + 32.526913)
		v34.Y = a2a.Y
		sub_525330(&v34, v7-1)
		sub_5253B0(&a2a.X)
		v8 = *(*float32)(unsafe.Add(a1, 40))
		if float64(*(*float32)(unsafe.Add(a2, 44))) <= float64(*(*float32)(unsafe.Add(a1, 44))) {
			a2a.X = *(*float32)(unsafe.Add(a2, 44))
		} else {
			a2a.X = *(*float32)(unsafe.Add(a1, 44))
		}
		a2a.Y = v8
		result = sub_5253B0(&a2a.X)
	case 1:
		if float64(*(*float32)(unsafe.Add(a2, 36))) >= float64(*(*float32)(unsafe.Add(a1, 36))) {
			v9 = float64(*(*float32)(unsafe.Add(a2, 36)))
		} else {
			v9 = float64(*(*float32)(unsafe.Add(a1, 36)))
		}
		a2a.X = float32(v9)
		v10 = *(*float32)(unsafe.Add(a1, 48))
		v11 = int32(*(*uint32)(unsafe.Add(a2, 12)))
		v34.X = float32(v9)
		a2a.Y = v10
		v12 = int32(*(*uint32)(unsafe.Add(a1, 12)))
		v34.Y = float32(float64(a2a.Y) - 32.526913)
		if v12 >= v11 {
			v13 = v11
			sub_521BC0(a1, &v34, *(*float32)(unsafe.Add(a2, 28)), 32.526913)
		} else {
			v13 = v12
			sub_521BC0(a1, &v34, *(*float32)(unsafe.Add(a1, 28)), 32.526913)
		}
		v34.X = float32(float64(a2a.X) + 32.526913)
		v34.Y = a2a.Y
		sub_525330(&v34, v13-1)
		sub_5253B0(&a2a.X)
		if float64(*(*float32)(unsafe.Add(a2, 44))) <= float64(*(*float32)(unsafe.Add(a1, 44))) {
			v14 = float64(*(*float32)(unsafe.Add(a2, 44)))
		} else {
			v14 = float64(*(*float32)(unsafe.Add(a1, 44)))
		}
		v15 = *(*float32)(unsafe.Add(a1, 48))
		a2a.X = float32(v14)
		a2a.Y = v15
		result = sub_5253B0(&a2a.X)
	case 2:
		v16 = float64(*(*float32)(unsafe.Add(a1, 40)))
		v17 = float64(*(*float32)(unsafe.Add(a2, 40)))
		a2a.X = *(*float32)(unsafe.Add(a1, 44))
		if v17 >= v16 {
			v18 = float64(*(*float32)(unsafe.Add(a2, 40)))
		} else {
			v18 = float64(*(*float32)(unsafe.Add(a1, 40)))
		}
		a2a.Y = float32(v18)
		v19 = int32(*(*uint32)(unsafe.Add(a1, 16)))
		v20 = int32(*(*uint32)(unsafe.Add(a2, 16)))
		v34.X = float32(float64(a2a.X) - 32.526913)
		v34.Y = float32(v18)
		if v19 >= v20 {
			v21 = v20
			sub_521BC0(a1, &v34, 32.526913, *(*float32)(unsafe.Add(a2, 32)))
		} else {
			v21 = v19
			sub_521BC0(a1, &v34, 32.526913, *(*float32)(unsafe.Add(a1, 32)))
		}
		v34.Y = float32(float64(a2a.Y) + 32.526913)
		v34.X = a2a.X
		sub_525370(&v34, v21-1)
		sub_5253B0(&a2a.X)
		v22 = float64(*(*float32)(unsafe.Add(a1, 48)))
		v23 = float64(*(*float32)(unsafe.Add(a2, 48)))
		a2a.X = *(*float32)(unsafe.Add(a1, 44))
		if v23 <= v22 {
			a2a.Y = *(*float32)(unsafe.Add(a2, 48))
		} else {
			a2a.Y = *(*float32)(unsafe.Add(a1, 48))
		}
		result = sub_5253B0(&a2a.X)
	case 3:
		v24 = float64(*(*float32)(unsafe.Add(a1, 40)))
		v25 = float64(*(*float32)(unsafe.Add(a2, 40)))
		a2a.X = *(*float32)(unsafe.Add(a1, 36))
		if v25 >= v24 {
			v26 = float64(*(*float32)(unsafe.Add(a2, 40)))
		} else {
			v26 = float64(*(*float32)(unsafe.Add(a1, 40)))
		}
		v27 = int32(*(*uint32)(unsafe.Add(a1, 16)))
		v28 = int32(*(*uint32)(unsafe.Add(a2, 16)))
		a2a.Y = float32(v26)
		if v27 >= v28 {
			v29 = v28
			sub_521BC0(a1, &a2a, 32.526913, *(*float32)(unsafe.Add(a2, 32)))
		} else {
			v29 = v27
			sub_521BC0(a1, &a2a, 32.526913, *(*float32)(unsafe.Add(a1, 32)))
		}
		v34.Y = float32(float64(a2a.Y) + 32.526913)
		v34.X = a2a.X
		sub_525370(&v34, v29-1)
		sub_5253B0(&a2a.X)
		v30 = float64(*(*float32)(unsafe.Add(a1, 48)))
		v31 = float64(*(*float32)(unsafe.Add(a2, 48)))
		a2a.X = *(*float32)(unsafe.Add(a1, 36))
		if v31 <= v30 {
			v32 = float64(*(*float32)(unsafe.Add(a2, 48)))
		} else {
			v32 = float64(*(*float32)(unsafe.Add(a1, 48)))
		}
		a2a.Y = float32(v32)
		result = sub_5253B0(&a2a.X)
	default:
		return result
	}
	return result
}
func sub_525330(a1 *types.Pointf, a2 int32) {
	var (
		v3  int32
		v4  float32
		a1a types.Pointf
	)
	v3 = a2
	v4 = a1.Y
	a1a.X = a1.X
	a1a.Y = v4
	if a2 > 0 {
		for {
			sub_527030(&a1a)
			v3--
			a1a.X = float32(float64(a1a.X) + 32.526913)
			if v3 == 0 {
				break
			}
		}
	}
}
func sub_525370(a1 *types.Pointf, a2 int32) {
	var (
		v3  int32
		v4  float32
		a1a types.Pointf
	)
	v3 = a2
	v4 = a1.Y
	a1a.X = a1.X
	a1a.Y = v4
	if a2 > 0 {
		for {
			sub_527030(&a1a)
			v3--
			a1a.Y = float32(float64(a1a.Y) + 32.526913)
			if v3 == 0 {
				break
			}
		}
	}
}
func sub_5253B0(a1 *float32) int32 {
	var (
		v1     float64
		v2     float64
		v3     float64
		v4     float64
		result int32
		v6     uint8
		v7     float32
		v8     float32
	)
	_ = v8
	var v9 int32
	v1 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*1))) - 32.526913
	v6 = 0
	v7 = *a1
	v8 = float32(v1)
	if sub_526DD0((*types.Pointf)(unsafe.Pointer(&v7)), &v9) != 0 {
		v6 = 1
	}
	v2 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*1))) + 32.526913
	v7 = *a1
	v8 = float32(v2)
	if sub_526DD0((*types.Pointf)(unsafe.Pointer(&v7)), &v9) != 0 {
		v6 |= 2
	}
	v3 = float64(*a1) - 32.526913
	v8 = *(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*1))
	v7 = float32(v3)
	if sub_526DD0((*types.Pointf)(unsafe.Pointer(&v7)), &v9) != 0 {
		v6 |= 4
	}
	v4 = float64(*a1) + 32.526913
	v8 = *(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*1))
	v7 = float32(v4)
	if sub_526DD0((*types.Pointf)(unsafe.Pointer(&v7)), &v9) != 0 {
		v6 |= 8
	}
	result = int32(v6) - 3
	switch v6 {
	case 3:
		sub_526D50(1)
		return sub_526E60(a1)
	case 5:
		sub_526D50(10)
		return sub_526E60(a1)
	case 6:
		sub_526D50(9)
		return sub_526E60(a1)
	case 7:
		sub_526D50(6)
		return sub_526E60(a1)
	case 9:
		sub_526D50(7)
		return sub_526E60(a1)
	case 0xA:
		sub_526D50(8)
		return sub_526E60(a1)
	case 0xB:
		sub_526D50(4)
		return sub_526E60(a1)
	case 0xC:
		sub_526D50(0)
		return sub_526E60(a1)
	case 0xD:
		sub_526D50(3)
		return sub_526E60(a1)
	case 0xE:
		sub_526D50(5)
		return sub_526E60(a1)
	case 0xF:
		sub_526D50(2)
		return sub_526E60(a1)
	default:
		return result
	}
}
func nox_xxx_mapgen_525510(a1 int32, a2 int32) {
	var (
		v2 int32
		v3 *int32
		v4 int32
		v5 int32
		v6 int32
	)
	v2 = a2
	v3 = (*int32)(unsafe.Add(a2, 88))
	v4 = 0
	v6 = a2 + 88
	for {
		v5 = 0
		if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v2+v4)), 216))) != 0 {
			for {
				nox_xxx_mapgen_525570(a1, v2, *v3, v4)
				v5++
				v3 = (*int32)(unsafe.Add(unsafe.Pointer(v3), 4*1))
				if v5 >= int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v2+v4)), 216))) {
					break
				}
			}
		}
		v4++
		v3 = (*int32)(unsafe.Add(v6, 32))
		v6 += 32
		if v4 >= 4 {
			break
		}
	}
}
func nox_xxx_mapgen_525570(a1 int32, a2 int32, a3 int32, a4 int32) {
	var (
		v4 float64
		v5 int32
		v6 float64
		v7 int32
		v8 int32
		v9 types.Pointf
	)
	switch a4 {
	case 0, 1:
		if float64(*(*float32)(unsafe.Add(a3, 36))) >= float64(*(*float32)(unsafe.Add(a2, 36))) {
			v4 = float64(*(*float32)(unsafe.Add(a3, 36)))
		} else {
			v4 = float64(*(*float32)(unsafe.Add(a2, 36)))
		}
		v9.X = float32(v4)
		if a4 != 0 {
			v9.Y = *(*float32)(unsafe.Add(a2, 48))
		} else {
			v9.Y = *(*float32)(unsafe.Add(a2, 40))
		}
		v5 = int32(*(*uint32)(unsafe.Add(a3, 12)))
		if *(*uint32)(unsafe.Add(a2, 12)) < uint32(v5) {
			v5 = int32(*(*uint32)(unsafe.Add(a2, 12)))
		}
		if v5 >= 2 && (v5 == 2 || nox_xxx_mapgen_525740(a2, &v9, v5) == 0) {
			nox_xxx_mapgen_525690(a2, &v9, v5)
		}
	case 2, 3:
		if a4 == 3 {
			v9.X = *(*float32)(unsafe.Add(a2, 36))
		} else {
			v9.X = *(*float32)(unsafe.Add(a2, 44))
		}
		if float64(*(*float32)(unsafe.Add(a3, 40))) >= float64(*(*float32)(unsafe.Add(a2, 40))) {
			v6 = float64(*(*float32)(unsafe.Add(a3, 40)))
		} else {
			v6 = float64(*(*float32)(unsafe.Add(a2, 40)))
		}
		v7 = int32(*(*uint32)(unsafe.Add(a2, 16)))
		v8 = int32(*(*uint32)(unsafe.Add(a3, 16)))
		v9.Y = float32(v6)
		if v7 < v8 {
			v8 = v7
		}
		if v8 >= 2 && (v8 == 2 || nox_xxx_mapgen_5258E0(a2, &v9, v8) == 0) {
			nox_xxx_mapgen_525830(a2, &v9, v8)
		}
	default:
		return
	}
}
func nox_xxx_mapgen_525690(a1 int32, a2 *types.Pointf, a3 int32) int32 {
	var (
		v4  *float32
		v5  *byte
		a1a types.Pointf
	)
	if int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 372)), 100))) == 0 {
		return 0
	}
	sub_524500(a2, a3+1)
	a1a.Y = a2.Y
	a1a.X = float32(float64(a3/2)*32.526913 + float64(a2.X))
	sub_527030(&a1a)
	v5 = (*byte)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 372)), 100))
	a1a.X = float32(float64(a1a.X) - 16.263456)
	nox_xxx_mapGenGetObjID_527940(v5)
	v4 = nox_xxx_mapGenPlaceObj_5279B0(&a1a)
	if v4 != nil {
		nox_xxx_mapGenOrientObj_527C60(int32(uintptr(unsafe.Pointer(v4))), 5)
	}
	return 1
}
func nox_xxx_mapgen_525740(a1 int32, a2 *types.Pointf, a3 int32) int32 {
	var (
		v4 *float32
		v5 *float32
		v6 *byte
		v7 types.Pointf
	)
	if int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 372)), 160))) == 0 {
		return 0
	}
	sub_524500(a2, a3+1)
	v7.Y = a2.Y
	v7.X = float32(float64(a3/2)*32.526913 + float64(a2.X))
	sub_527030(&v7)
	v7.X = float32(float64(v7.X) + 32.526913)
	sub_527030(&v7)
	v6 = (*byte)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 372)), 160))
	v7.X = float32(float64(v7.X) - 48.790367)
	nox_xxx_mapGenGetObjID_527940(v6)
	v4 = nox_xxx_mapGenPlaceObj_5279B0(&v7)
	if v4 != nil {
		nox_xxx_mapGenOrientObj_527C60(int32(uintptr(unsafe.Pointer(v4))), 5)
	}
	v7.X = float32(float64(v7.X) + 65.053825)
	v5 = nox_xxx_mapGenPlaceObj_5279B0(&v7)
	if v5 != nil {
		nox_xxx_mapGenOrientObj_527C60(int32(uintptr(unsafe.Pointer(v5))), 3)
	}
	return 1
}
func nox_xxx_mapgen_525830(a1 int32, a2 *types.Pointf, a3 int32) int32 {
	var (
		v4  *float32
		v5  *byte
		a1a types.Pointf
	)
	if int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 372)), 100))) == 0 {
		return 0
	}
	sub_524550((*int32)(unsafe.Pointer(a2)), a3+1)
	a1a.X = a2.X
	a1a.Y = float32(float64(a3/2)*32.526913 + float64(a2.Y))
	sub_527030(&a1a)
	v5 = (*byte)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 372)), 100))
	a1a.Y = float32(float64(a1a.Y) - 16.263456)
	nox_xxx_mapGenGetObjID_527940(v5)
	v4 = nox_xxx_mapGenPlaceObj_5279B0(&a1a)
	if v4 != nil {
		nox_xxx_mapGenOrientObj_527C60(int32(uintptr(unsafe.Pointer(v4))), 7)
	}
	return 1
}
func nox_xxx_mapgen_5258E0(a1 int32, a2 *types.Pointf, a3 int32) int32 {
	var (
		v4  *float32
		v5  *float32
		v6  *byte
		a1a types.Pointf
	)
	if int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 372)), 160))) == 0 {
		return 0
	}
	sub_524550((*int32)(unsafe.Pointer(a2)), a3+1)
	a1a.X = a2.X
	a1a.Y = float32(float64(a3/2)*32.526913 + float64(a2.Y))
	sub_527030(&a1a)
	a1a.Y = float32(float64(a1a.Y) + 32.526913)
	sub_527030(&a1a)
	v6 = (*byte)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 372)), 160))
	a1a.Y = float32(float64(a1a.Y) - 48.790367)
	nox_xxx_mapGenGetObjID_527940(v6)
	v4 = nox_xxx_mapGenPlaceObj_5279B0(&a1a)
	if v4 != nil {
		nox_xxx_mapGenOrientObj_527C60(int32(uintptr(unsafe.Pointer(v4))), 7)
	}
	a1a.Y = float32(float64(a1a.Y) + 65.053825)
	v5 = nox_xxx_mapGenPlaceObj_5279B0(&a1a)
	if v5 != nil {
		nox_xxx_mapGenOrientObj_527C60(int32(uintptr(unsafe.Pointer(v5))), 1)
	}
	return 1
}
func sub_5259F0(a1 int32, a2 int32, a3 float32) {
	var (
		v3  float64
		v4  int32
		v5  *int32
		v6  int32
		v7  *uint8
		v8  int32
		v9  int32
		v10 int32
		v11 float32
	)
	nox_xxx_mapGenSetFlags_5235F0(-100)
	if a2 != 0 {
		switch *(*uint32)(a2) {
		case 1:
			v3 = math.Sqrt(float64(*(*float32)(unsafe.Add(a2, 28))**(*float32)(unsafe.Add(a2, 28)) + *(*float32)(unsafe.Add(a2, 32))**(*float32)(unsafe.Add(a2, 32))))
		case 2, 3:
			v3 = float64(*(*float32)(unsafe.Add(a2, 32)))
		case 4, 5:
			v3 = float64(*(*float32)(unsafe.Add(a2, 28)))
		default:
			v3 = float64(a3)
		}
	} else {
		v3 = 0.0
	}
	v4 = a1
	v11 = float32(v3 + float64(a3))
	if int32(*(*uint8)(unsafe.Add(a1, 220))) != 1 || float64(v11) < float64(*(*float32)(unsafe.Add(a1, 356))) {
		*(*float32)(unsafe.Add(a1, 356)) = v11
		v5 = (*int32)(unsafe.Add(a1, 88))
		v6 = -216 - a1
		*(*uint8)(unsafe.Add(a1, 220)) = 1
		v7 = (*uint8)(unsafe.Add(a1, 216))
		v10 = a1 + 88
		v9 = -216 - a1
		for {
			v8 = 0
			if int32(*v7) != 0 {
				for {
					if *v5 != 0 {
						sub_5259F0(*v5, v4, v11)
					}
					v8++
					v5 = (*int32)(unsafe.Add(unsafe.Pointer(v5), 4*1))
					if v8 >= int32(*v7) {
						break
					}
				}
				v6 = v9
			}
			v7 = (*uint8)(unsafe.Add(unsafe.Pointer(v7), 1))
			v5 = (*int32)(unsafe.Add(v10, 32))
			v10 += 32
			if int32(uintptr(unsafe.Add(unsafe.Pointer(v7), v6))) >= 4 {
				break
			}
		}
	}
}
func sub_525AF0(a1 int32) *float32 {
	var (
		v1     int32
		v2     int32
		i      *float32
		result *float32
		v5     int32
		v6     int32
	)
	v1 = 0
	v2 = 0
	dword_5d4594_2487580 = 0
	dword_5d4594_2487576 = uint32(a1)
	sub_525BF0(a1)
	*(*uint32)(unsafe.Add(dword_5d4594_2487576, 52)) |= 1
	for i = (*float32)(nox_xxx_mapGenGetTopRoom_521710()); i != nil; i = (*float32)(unsafe.Pointer(uintptr(sub_521720(int32(uintptr(unsafe.Pointer(i))))))) {
		v1++
		*(*float32)(unsafe.Add(unsafe.Pointer(i), unsafe.Sizeof(float32(0))*90)) = *(*float32)(unsafe.Add(unsafe.Pointer(i), unsafe.Sizeof(float32(0))*89)) / dword_5d4594_2487580
	}
	dword_5d4594_2487584 = 0
	result = sub_525C90()
	v5 = a1
	if a1 != 0 {
		for {
			if v1 > 1 {
				v6 = v2 / (v1 - 1)
			} else {
				v6 = 100
			}
			if v5 == a1 {
				*(*uint32)(unsafe.Add(v5, 364)) = 1
			} else if v6 >= 30 {
				if v6 >= 60 {
					if v6 >= 90 {
						*(*uint32)(unsafe.Add(v5, 364)) = 16
					} else {
						*(*uint32)(unsafe.Add(v5, 364)) = 8
					}
				} else {
					*(*uint32)(unsafe.Add(v5, 364)) = 4
				}
			} else {
				*(*uint32)(unsafe.Add(v5, 364)) = 2
			}
			v5 = int32(*(*uint32)(unsafe.Add(v5, 64)))
			v2 += 100
			if v5 == 0 {
				break
			}
		}
		result = dword_5d4594_2487576
		*(*uint32)(unsafe.Add(dword_5d4594_2487576, 364)) = 32
	} else {
		*(*uint32)(unsafe.Add(dword_5d4594_2487576, 364)) = 32
	}
	return result
}
func sub_525BF0(a1 int32) {
	var (
		v1 int32
		v2 int32
		v3 *uint8
		v4 int32
		v5 int32
		v6 *int32
		v7 int32
	)
	if int32(*(*uint8)(unsafe.Add(a1, 220))) != 2 {
		if float64(dword_5d4594_2487580) < float64(*(*float32)(unsafe.Add(a1, 356))) && *(*uint32)(a1) == 1 {
			v1 = int32(*(*uint32)(unsafe.Add(a1, 356)))
			dword_5d4594_2487576 = uint32(a1)
			dword_5d4594_2487580 = uint32(v1)
		}
		v2 = -216 - a1
		*(*uint8)(unsafe.Add(a1, 220)) = 2
		v3 = (*uint8)(unsafe.Add(a1, 216))
		v4 = a1 + 88
		v7 = -216 - a1
		for {
			v5 = 0
			if int32(*v3) != 0 {
				v6 = (*int32)(v4)
				for {
					if *v6 != 0 {
						sub_525BF0(*v6)
					}
					v5++
					v6 = (*int32)(unsafe.Add(unsafe.Pointer(v6), 4*1))
					if v5 >= int32(*v3) {
						break
					}
				}
				v2 = v7
			}
			v3 = (*uint8)(unsafe.Add(unsafe.Pointer(v3), 1))
			v4 += 32
			if int32(uintptr(unsafe.Add(unsafe.Pointer(v3), v2))) >= 4 {
				break
			}
		}
	}
}
func sub_525C90() *float32 {
	var (
		result *float32
		i      *float32
		v2     int32
		v3     int32
		v4     int32
		v5     int32
	)
	dword_5d4594_2487584 = 0
	result = (*float32)(nox_xxx_mapGenGetTopRoom_521710())
	for i = result; result != nil; i = result {
		v2 = int32(dword_5d4594_2487584)
		if dword_5d4594_2487584 != 0 {
			v3 = 0
			for {
				if float64(*(*float32)(unsafe.Add(unsafe.Pointer(i), unsafe.Sizeof(float32(0))*89))) < float64(*(*float32)(unsafe.Add(v2, 356))) {
					v4 = int32(*(*uint32)(unsafe.Add(v2, 68)))
					if v4 != 0 {
						*(*uint32)(unsafe.Add(v4, 64)) = uint32(uintptr(unsafe.Pointer(i)))
					} else {
						dword_5d4594_2487584 = uint32(uintptr(unsafe.Pointer(i)))
					}
					v5 = int32(*(*uint32)(unsafe.Add(v2, 68)))
					*((*uint32)(unsafe.Add(unsafe.Pointer(i), 4*16))) = uint32(v2)
					*((*uint32)(unsafe.Add(unsafe.Pointer(i), 4*17))) = uint32(v5)
					*(*uint32)(unsafe.Add(v2, 68)) = uint32(uintptr(unsafe.Pointer(i)))
					break
				}
				v3 = v2
				v2 = int32(*(*uint32)(unsafe.Add(v2, 64)))
				if v2 == 0 {
					break
				}
			}
			if v2 == 0 {
				*((*uint32)(unsafe.Add(unsafe.Pointer(i), 4*17))) = uint32(v3)
				*(*float32)(unsafe.Add(unsafe.Pointer(i), unsafe.Sizeof(float32(0))*16)) = 0.0
				*(*uint32)(unsafe.Add(v3, 64)) = uint32(uintptr(unsafe.Pointer(i)))
				goto LABEL_13
			}
		} else {
			dword_5d4594_2487584 = uint32(uintptr(unsafe.Pointer(i)))
			*(*float32)(unsafe.Add(unsafe.Pointer(i), unsafe.Sizeof(float32(0))*16)) = 0.0
			*(*float32)(unsafe.Add(unsafe.Pointer(i), unsafe.Sizeof(float32(0))*17)) = 0.0
		}
	LABEL_13:
		result = (*float32)(unsafe.Pointer(uintptr(sub_521720(int32(uintptr(unsafe.Pointer(i)))))))
	}
	return result
}
func nox_xxx_mapGen_InPrefab1_525D20(a1 int32) int32 {
	var (
		v1 int32
		i  *uint32
		j  *uint32
	)
	v1 = 0
	if dword_5d4594_2487656 == 0 {
		dword_5d4594_2487656 = uint32(nox_xxx_getNameId_4E3AA0(internCStr("ExitNorthMarker")))
		*memmap.PtrUint32(0x5D4594, 2487660) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("ExitSouthMarker")))
		*memmap.PtrUint32(0x5D4594, 2487664) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("ExitEastMarker")))
		*memmap.PtrUint32(0x5D4594, 2487668) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("ExitWestMarker")))
	}
	sub_525DF0(a1)
	for i = *(**uint32)(unsafe.Add(a1, 80)); i != nil; i = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(i), 4*39))) {
		if *(*uint32)(unsafe.Add(unsafe.Pointer(i), 4*18)) != 0 {
			if v1 == 5 || nox_xxx_mapGenPrefabMkRoom_526100(a1, int32(uintptr(unsafe.Pointer(i)))) == 0 {
				return 0
			}
			*(*uint32)(unsafe.Add(unsafe.Pointer(i), 4*19)) = 1
			v1++
		}
	}
	for j = *(**uint32)(unsafe.Add(a1, 80)); j != nil; j = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(j), 4*39))) {
		if *(*uint32)(unsafe.Add(unsafe.Pointer(j), 4*18)) == 0 {
			if v1 == 5 {
				return 1
			}
			if nox_xxx_mapGenPrefabMkRoom_526100(a1, int32(uintptr(unsafe.Pointer(j)))) == 0 {
				return 0
			}
			*(*uint32)(unsafe.Add(unsafe.Pointer(j), 4*19)) = 1
			v1++
		}
	}
	return 1
}
func sub_525DF0(a1 float32) {
	var (
		v1  float64
		v2  int32
		v3  int32
		v4  *uint8
		v5  int32
		v6  int32
		v7  int32
		v8  float64
		v9  int32
		v10 float64
		v11 float64
		v12 float64
		v13 float64
		v14 float32
		v15 float32
		v16 float32
	)
	v1 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0))))), 64))) * 0.5
	*memmap.PtrUint32(0x5D4594, 2487608) = 0
	v2 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0))))), 84)))
	v16 = float32(v1)
	if v2 >= 5 {
		v2 = 5
		dword_5d4594_2487652 = 5
	} else {
		dword_5d4594_2487652 = uint32(v2)
		if v2 == 1 {
			*memmap.PtrUint32(0x5D4594, 2487588) = 0
			goto LABEL_10
		}
		if v2 == 2 {
			if nox_xxx_mapGenRandFunc_526AC0(0, 100) >= 50 {
				v2 = int32(dword_5d4594_2487652)
				*memmap.PtrUint32(0x5D4594, 2487588) = 1
				*memmap.PtrUint32(0x5D4594, 2487592) = 0
			} else {
				v2 = int32(dword_5d4594_2487652)
				*memmap.PtrUint32(0x5D4594, 2487588) = 0
				*memmap.PtrUint32(0x5D4594, 2487592) = 1
			}
			goto LABEL_10
		}
	}
	v3 = 0
	if v2 > 0 {
		v4 = (*uint8)(memmap.PtrOff(0x5D4594, 2487588))
		for {
			*(*uint32)(unsafe.Pointer(v4)) = uint32(func() int32 {
				p := &v3
				x := *p
				*p++
				return x
			}())
			v4 = (*uint8)(unsafe.Add(unsafe.Pointer(v4), 4))
			if v3 >= v2 {
				break
			}
		}
	}
	v5 = 0
	if v2 > 0 {
		for {
			v6 = nox_xxx_mapGenRandFunc_526AC0(0, v2-2)
			v7 = int32(*memmap.PtrUint32(0x5D4594, uintptr(v6*4)+2487588))
			*memmap.PtrUint32(0x5D4594, uintptr(v6*4)+2487588) = *memmap.PtrUint32(0x5D4594, uintptr(v6*4)+2487592)
			*memmap.PtrUint32(0x5D4594, uintptr(v6*4)+2487592) = uint32(v7)
			v2 = int32(dword_5d4594_2487652)
			v5++
			if v5 >= dword_5d4594_2487652 {
				break
			}
		}
	}
LABEL_10:
	switch v2 {
	case 1:
		v14 = -v16
		*mem_getFloatPtr(0x5D4594, 2487612) = float32(sub_526BC0(v14, v16))
		*mem_getFloatPtr(0x5D4594, 2487616) = float32(sub_526BC0(v14, v16))
	case 2:
		v8 = float64(-v16)
		v15 = float32(v8)
		if nox_xxx_mapGenRandFunc_526AC0(0, 100) >= 50 {
			*mem_getFloatPtr(0x5D4594, 2487612) = float32(v8)
			*mem_getFloatPtr(0x5D4594, 2487616) = float32(sub_526BC0(v15, v16))
			dword_5d4594_2487620 = v16
			dword_5d4594_2487624 = float32(sub_526BC0(v15, v16))
		} else {
			*mem_getFloatPtr(0x5D4594, 2487612) = float32(sub_526BC0(v15, v16))
			*mem_getFloatPtr(0x5D4594, 2487616) = v15
			dword_5d4594_2487620 = float32(sub_526BC0(v15, v16))
			dword_5d4594_2487624 = v16
		}
	case 3:
		v9 = nox_xxx_mapGenRandFunc_526AC0(0, 100)
		if v9 >= 25 {
			if v9 >= 50 {
				v12 = float64(-v16)
				if v9 >= 75 {
					*mem_getFloatPtr(0x5D4594, 2487612) = float32(v12)
					*mem_getFloatPtr(0x5D4594, 2487616) = float32(v12)
					dword_5d4594_2487620 = float32(v12)
					dword_5d4594_2487624 = v16
					dword_5d4594_2487628 = v16
				} else {
					*mem_getFloatPtr(0x5D4594, 2487616) = float32(v12)
					dword_5d4594_2487628 = float32(v12)
					*mem_getFloatPtr(0x5D4594, 2487612) = v16
					dword_5d4594_2487620 = v16
					dword_5d4594_2487624 = v16
				}
				dword_5d4594_2487632 = 0
			} else {
				v11 = float64(-v16)
				*mem_getFloatPtr(0x5D4594, 2487612) = float32(v11)
				dword_5d4594_2487632 = float32(v11)
				*mem_getFloatPtr(0x5D4594, 2487616) = v16
				dword_5d4594_2487620 = v16
				dword_5d4594_2487624 = v16
				dword_5d4594_2487628 = 0
			}
		} else {
			v10 = float64(-v16)
			*mem_getFloatPtr(0x5D4594, 2487612) = float32(v10)
			*mem_getFloatPtr(0x5D4594, 2487616) = float32(v10)
			dword_5d4594_2487624 = float32(v10)
			dword_5d4594_2487620 = v16
			dword_5d4594_2487628 = 0
			dword_5d4594_2487632 = v16
		}
	case 4, 5:
		*memmap.PtrUint32(0x5D4594, 2487644) = 0
		v13 = float64(-v16)
		*mem_getFloatPtr(0x5D4594, 2487612) = float32(v13)
		*mem_getFloatPtr(0x5D4594, 2487616) = float32(v13)
		dword_5d4594_2487624 = float32(v13)
		dword_5d4594_2487628 = float32(v13)
		dword_5d4594_2487620 = v16
		dword_5d4594_2487632 = v16
		*mem_getFloatPtr(0x5D4594, 2487636) = v16
		*mem_getFloatPtr(0x5D4594, 2487640) = v16
		*memmap.PtrUint32(0x5D4594, 2487648) = 0
	default:
		return
	}
}
func nox_xxx_mapGenPrefabMkRoom_526100(a1 int32, a2 int32) int32 {
	var (
		result int32
		v3     *float32
		v4     int32
		v5     *uint32
		v6     int32
		v7     int32
		v8     *uint32
		v9     types.Pointf
	)
	result = sub_5262F0(a1, a2)
	if result != 0 {
		v3 = nox_xxx_mapGenMakeRoomStruct_521940(int32(uint32(uint64(*(*uint32)(unsafe.Add(a2, 144))*4)+uint64(int64(float64(*(*float32)(unsafe.Add(a2, 60)))*0.030743772+0.5)))), int32(uint32(uint64(*(*uint32)(unsafe.Add(a2, 144))*4)+uint64(int64(float64(*(*float32)(unsafe.Add(a2, 64)))*0.030743772+0.5)))))
		*(*uint32)(unsafe.Add(a2, 148)) = uint32(uintptr(unsafe.Pointer(v3)))
		sub_526260(int32(uintptr(unsafe.Pointer(v3))), &v9.X)
		nox_xxx_mapGenSetRoomPos_521880(*(**uint32)(unsafe.Add(a2, 148)), &v9)
		v4 = 1
		v5 = (*uint32)(unsafe.Pointer(uintptr(sub_521200(int32(*(*uint32)(unsafe.Add(a2, 148)))))))
		if v5 != nil && sub_5212B0(int32(*(*uint32)(unsafe.Add(a2, 148))), v5) == 0 {
			v4 = 0
		}
		if sub_5217A0(a1, int32(*(*uint32)(unsafe.Add(a2, 148)))) != 0 && v4 != 0 {
			nox_xxx_mapGenAddNewRoom_521730(*(**uint32)(unsafe.Add(a2, 148)))
			v6 = 4
			*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a2, 148)), 52)) |= 2
			v7 = int32(*(*uint32)(unsafe.Add(a2, 144)) * 2)
			v8 = (*uint32)(unsafe.Add(a2, 80))
			for {
				if *(*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*3)) != 0 {
					*v8 += uint32(v7) + *(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a2, 148)), 4))
					*(*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*1)) += uint32(v7) + *(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a2, 148)), 8))
				}
				v8 = (*uint32)(unsafe.Add(unsafe.Pointer(v8), 4*4))
				v6--
				if v6 == 0 {
					break
				}
			}
			result = 1
		} else {
			sub_521A10(*(*unsafe.Pointer)(unsafe.Add(a2, 148)))
			*(*uint32)(unsafe.Add(a2, 148)) = 0
			result = 0
		}
	}
	return result
}
func sub_526260(a1 int32, a2 *float32) int64 {
	var (
		v2     int32
		result int64
	)
	v2 = int32(*memmap.PtrUint32(0x5D4594, uintptr(*memmap.PtrUint32(0x5D4594, 2487608))*4+2487588))
	*a2 = *mem_getFloatPtr(0x5D4594, uint32(v2*8)+2487612)
	*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*1)) = *mem_getFloatPtr(0x5D4594, uint32(v2*8)+2487616)
	*memmap.PtrUint32(0x5D4594, 2487608)++
	*a2 = float32(float64(*a2) - float64(*(*float32)(unsafe.Add(a1, 28)))*0.5)
	*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*1)) = float32(float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*1))) - float64(*(*float32)(unsafe.Add(a1, 32)))*0.5)
	*a2 = float32(float64(int32(int64(float64(*a2)*0.030743772))) * 32.526913)
	result = int64(float64(*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*1))) * 0.030743772)
	*(*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*1)) = float32(float64(int32(result)) * 32.526913)
	return result
}
func sub_5262F0(a1 int32, a2 int32) int32 {
	var (
		v2     int32
		v3     float64
		v4     int32
		i      int32
		v6     int32
		v7     int32
		v8     int32
		v9     int32
		v10    int32
		v11    int32
		v12    int32
		v13    int32
		v14    int32
		v15    int32
		v16    int32
		v17    int32
		v18    int32
		v19    int32
		v20    int32
		v21    int32
		v22    *uint32
		result int32
	)
	_ = result
	var v24 int2
	var v26 types.Pointf
	var v28 types.Pointf
	v2 = sub_5029A0((*byte)(a2))
	*(*uint32)(unsafe.Add(a2, 68)) = uint32(v2)
	if v2 == -1 {
		return 0
	}
	sub_502D70(v2)
	v3 = sub_502E70(int32(*(*uint32)(unsafe.Add(a2, 68))))
	v4 = int32(*(*uint32)(unsafe.Add(a2, 68)))
	*(*float32)(unsafe.Add(a2, 60)) = float32(v3)
	*(*float32)(unsafe.Add(a2, 64)) = float32(sub_502EA0(v4))
	for i = sub_504980(); i != 0; i = sub_5049C0(i) {
		sub_503EC0(i, &v26.X)
		v28.X = float32(float64(v26.X) - 1.0)
		v28.Y = float32(float64(v26.Y) - 1.0)
		nox_xxx_mapGenRoundFloatToPtr_520DF0(&v28, (*uint32)(unsafe.Pointer(&v24)))
		v6 = int32(*(*uint16)(unsafe.Add(i, 4)))
		if uint32(uint16(int16(v6))) == dword_5d4594_2487656 {
			if *(*uint32)(unsafe.Add(a2, 92)) != 0 {
				if v24.field_0 < *(*int32)(unsafe.Add(a2, 80)) {
					*(*uint32)(unsafe.Add(a2, 80)) = uint32(v24.field_0)
				}
				v7 = int32(*(*uint32)(unsafe.Add(a2, 88)) + 1)
				*(*uint32)(unsafe.Add(a2, 84)) = uint32(v24.field_4)
				*(*uint32)(unsafe.Add(a2, 88)) = uint32(v7)
			} else {
				v8 = v24.field_0
				v9 = v24.field_4
				*(*uint32)(unsafe.Add(a2, 92)) = 1
				*(*uint32)(unsafe.Add(a2, 80)) = uint32(v8)
				*(*uint32)(unsafe.Add(a2, 84)) = uint32(v9)
				*(*uint32)(unsafe.Add(a2, 88)) = 1
			}
		} else if uint32(v6) == *memmap.PtrUint32(0x5D4594, 2487660) {
			if *(*uint32)(unsafe.Add(a2, 108)) != 0 {
				if v24.field_0 < *(*int32)(unsafe.Add(a2, 96)) {
					*(*uint32)(unsafe.Add(a2, 96)) = uint32(v24.field_0)
				}
				v10 = int32(*(*uint32)(unsafe.Add(a2, 104)) + 1)
				*(*uint32)(unsafe.Add(a2, 100)) = uint32(v24.field_4)
				*(*uint32)(unsafe.Add(a2, 104)) = uint32(v10)
			} else {
				v11 = v24.field_0
				v12 = v24.field_4
				*(*uint32)(unsafe.Add(a2, 108)) = 1
				*(*uint32)(unsafe.Add(a2, 96)) = uint32(v11)
				*(*uint32)(unsafe.Add(a2, 100)) = uint32(v12)
				*(*uint32)(unsafe.Add(a2, 104)) = 1
			}
		} else if uint32(v6) == *memmap.PtrUint32(0x5D4594, 2487668) {
			if *(*uint32)(unsafe.Add(a2, 140)) != 0 {
				if v24.field_4 < *(*int32)(unsafe.Add(a2, 132)) {
					*(*uint32)(unsafe.Add(a2, 132)) = uint32(v24.field_4)
				}
				v13 = int32(*(*uint32)(unsafe.Add(a2, 136)) + 1)
				*(*uint32)(unsafe.Add(a2, 128)) = uint32(v24.field_0)
				*(*uint32)(unsafe.Add(a2, 136)) = uint32(v13)
			} else {
				v14 = v24.field_0
				v15 = v24.field_4
				*(*uint32)(unsafe.Add(a2, 140)) = 1
				*(*uint32)(unsafe.Add(a2, 128)) = uint32(v14)
				*(*uint32)(unsafe.Add(a2, 132)) = uint32(v15)
				*(*uint32)(unsafe.Add(a2, 136)) = 1
			}
		} else if uint32(v6) == *memmap.PtrUint32(0x5D4594, 2487664) {
			if *(*uint32)(unsafe.Add(a2, 124)) != 0 {
				if v24.field_4 < *(*int32)(unsafe.Add(a2, 116)) {
					*(*uint32)(unsafe.Add(a2, 116)) = uint32(v24.field_4)
				}
				v16 = int32(*(*uint32)(unsafe.Add(a2, 120)) + 1)
				*(*uint32)(unsafe.Add(a2, 112)) = uint32(v24.field_0)
				*(*uint32)(unsafe.Add(a2, 120)) = uint32(v16)
			} else {
				v17 = v24.field_0
				v18 = v24.field_4
				*(*uint32)(unsafe.Add(a2, 124)) = 1
				*(*uint32)(unsafe.Add(a2, 112)) = uint32(v17)
				*(*uint32)(unsafe.Add(a2, 116)) = uint32(v18)
				*(*uint32)(unsafe.Add(a2, 120)) = 1
			}
		}
	}
	v19 = 4
	v20 = int32(*(*uint32)(unsafe.Add(a1, 12)) + *(*uint32)(unsafe.Add(a1, 16)))
	v21 = 0
	v22 = (*uint32)(unsafe.Add(a2, 88))
	for {
		if *(*uint32)(unsafe.Add(unsafe.Pointer(v22), 4*1)) != 0 {
			if *v22 > uint32(*(*int32)(unsafe.Add(a2, 144))) {
				*(*uint32)(unsafe.Add(a2, 144)) = *v22
			}
			v21++
		}
		v22 = (*uint32)(unsafe.Add(unsafe.Pointer(v22), 4*4))
		v19--
		if v19 == 0 {
			break
		}
	}
	if *(*uint32)(unsafe.Add(a2, 144)) > uint32(v20) || v21 > 2 || (*(*uint32)(unsafe.Add(a2, 92)) != 0 || *(*uint32)(unsafe.Add(a2, 108)) != 0) && (*(*uint32)(unsafe.Add(a2, 124)) != 0 || *(*uint32)(unsafe.Add(a2, 140)) != 0) {
		return 0
	} else {
		return 1
	}
}
func sub_526550(a1 int32, a2 int32) int32 {
	var (
		v2  int32
		v3  int32
		v4  int32
		v5  int32
		v6  int32
		v7  *int32
		v8  int32
		v9  int32
		v10 int32
		v11 int32
		v12 int32
		v13 *int32
		v14 int32
		v15 int32
		v16 int32
		v17 int32
		v18 int32
		v19 int64
		v20 *int32
		v21 int32
		v23 int32
		v24 int32
		v25 int32
		v26 [5]int32 = [5]int32{}
		v27 int32
		v28 [5]int32
		v29 int32
	)
	v2 = (a2 + 5) * 16
	v3 = 0
	v4 = 0
	v5 = 0
	v23 = int32(*(*uint32)(unsafe.Pointer(uintptr(v2 + a1))))
	v6 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v2+a1)), 4)))
	v27 = 0
	v24 = v6
	v29 = 0
	v7 = (*int32)(nox_xxx_mapGenGetTopRoom_521710())
	if v7 != nil {
		for {
			if nox_xxx_mapGenCheckRoomType_5238F0(v7) == 0 {
				v8 = *(*int32)(unsafe.Add(unsafe.Pointer(v7), 4*1)) + *(*int32)(unsafe.Add(unsafe.Pointer(v7), 4*3))/2 - v23
				v9 = *(*int32)(unsafe.Add(unsafe.Pointer(v7), 4*2)) + *(*int32)(unsafe.Add(unsafe.Pointer(v7), 4*4))/2 - v24
				switch a2 {
				case 0:
					if v9 < 0 {
						break
					}
					goto LABEL_A
				case 1:
					if v9 > 0 {
						break
					}
					goto LABEL_A
				case 2:
					if v8 > 0 {
						break
					}
					goto LABEL_A
				case 3:
					if v8 < 0 {
						break
					}
					goto LABEL_A
				default:
				}
				v10 = v8*v8 + v9*v9
				if v3 >= 24 {
					if *((*int32)(unsafe.Add(unsafe.Pointer(&v25), 4*uintptr(v5)))) > v10 {
						*((*int32)(unsafe.Add(unsafe.Pointer(&v27), 4*uintptr(v5)))) = int32(uintptr(unsafe.Pointer(v7)))
						*((*int32)(unsafe.Add(unsafe.Pointer(&v25), 4*uintptr(v5)))) = v10
					}
				} else {
					v4++
					*(*int32)(unsafe.Add(unsafe.Pointer(&v27), v3)) = int32(uintptr(unsafe.Pointer(v7)))
					*(*int32)(unsafe.Add(unsafe.Pointer(&v25), v3)) = v10
					v29 = v4
					v3 += 4
				}
				v11 = v25
				v5 = 0
				v12 = 1
				if v3 > 4 {
					v13 = &v26[0]
					for {
						if *v13 > v11 {
							v5 = v12
							v11 = *v13
						}
						v12++
						v13 = (*int32)(unsafe.Add(unsafe.Pointer(v13), 4*1))
						if v12 >= v29 {
							break
						}
					}
					v4 = v29
				}
			}
		LABEL_A:
			v14 = sub_521720(int32(uintptr(unsafe.Pointer(v7))))
			v7 = (*int32)(v14)
			if v14 == 0 {
				break
			}
		}
		if v4 > 1 {
			v15 = v4 - 1
			if v4-1 > 0 {
				for {
					v16 = *((*int32)(unsafe.Add(unsafe.Pointer(&v25), 4*uintptr(v14))))
					v17 = v26[v14]
					if v16 > v17 {
						v18 = *((*int32)(unsafe.Add(unsafe.Pointer(&v27), 4*uintptr(v14))))
						*((*int32)(unsafe.Add(unsafe.Pointer(&v25), 4*uintptr(v14)))) = v17
						*((*int32)(unsafe.Add(unsafe.Pointer(&v27), 4*uintptr(v14)))) = v28[v14]
						v26[v14] = v16
						v28[v14] = v18
						v14 = -1
					}
					v14++
					if v14 >= v15 {
						break
					}
				}
				v4 = v29
			}
		}
	}
	v19 = 0
	if v4 > 0 {
		v20 = &v27
		for {
			v21 = *v20
			*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*v20)), 72)) = 0
			if (*(*uint32)(unsafe.Add(unsafe.Pointer(&v19), 4*1))) != 0 {
				*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&v19), 4*1))))), 72)) = uint32(v21)
			} else {
				*(*uint32)(unsafe.Add(unsafe.Pointer(&v19), 4*0)) = uint32(v21)
			}
			v20 = (*int32)(unsafe.Add(unsafe.Pointer(v20), 4*1))
			v4--
			*(*uint32)(unsafe.Add(unsafe.Pointer(&v19), 4*1)) = uint32(v21)
			if v4 == 0 {
				break
			}
		}
	}
	return int32(v19)
}
func nox_xxx_mapGen_InPrefab2_5266F0(a1 int32) int32 {
	var (
		v1 int32
		v2 int32
		v3 *float32
		v4 *uint32
		v5 int32
		v6 *uint32
		v8 types.Pointf
	)
	v1 = int32(*(*uint32)(unsafe.Add(a1, 80)))
	if v1 == 0 {
		return 1
	}
	for {
		if *(*uint32)(unsafe.Add(v1, 76)) != 0 {
			v2 = int32(*(*uint32)(unsafe.Add(v1, 148)))
			v8.X = *(*float32)(unsafe.Add(v2, 20))
			v8.Y = *(*float32)(unsafe.Add(v2, 24))
			v8.X = float32(float64(*(*int32)(unsafe.Add(v1, 144)))*65.053825 + float64(v8.X))
			v8.Y = float32(float64(*(*int32)(unsafe.Add(v1, 144)))*65.053825 + float64(v8.Y))
			sub_521760(int32(*(*uint32)(unsafe.Add(v1, 148))))
			sub_521A10(*(*unsafe.Pointer)(unsafe.Add(v1, 148)))
			v3 = nox_xxx_mapGenMakeRoomStruct_521940(int32(int64(float64(*(*float32)(unsafe.Add(v1, 60)))*0.030743772+0.5)), int32(int64(float64(*(*float32)(unsafe.Add(v1, 64)))*0.030743772+0.5)))
			*(*uint32)(unsafe.Add(v1, 148)) = uint32(uintptr(unsafe.Pointer(v3)))
			nox_xxx_mapGenSetRoomPos_521880((*uint32)(unsafe.Pointer(v3)), &v8)
			nox_xxx_mapGenAddNewRoom_521730(*(**uint32)(unsafe.Add(v1, 148)))
			v4 = (*uint32)(unsafe.Add(v1, 92))
			v5 = 0
			*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v1, 148)), 52)) |= 2
			for {
				if *v4 != 0 {
					v6 = (*uint32)(unsafe.Pointer(uintptr(sub_526550(v1, v5))))
					if v6 == nil {
						return 0
					}
					for sub_54B2D0((*int32)(v1), v5, v6) == 0 {
						v6 = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v6), 4*18)))
						if v6 == nil {
							return 0
						}
					}
					if v6 == nil {
						return 0
					}
				}
				v5++
				v4 = (*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*4))
				if v5 >= 4 {
					goto LABEL_11
				}
			}
		}
	LABEL_11:
		v1 = int32(*(*uint32)(unsafe.Add(v1, 156)))
		if v1 == 0 {
			return 1
		}
	}
}
func nox_xxx_mapGenPlacePrefabs_526830(a1 int32) int32 {
	var (
		v1 *int32
		v2 int32
		v3 int32
		v4 int32
	)
	v1 = *(**int32)(unsafe.Add(a1, 80))
	if v1 == nil {
		return 1
	}
	for {
		if *(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*19)) != 0 {
			sub_502D70(*(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*17)))
			v2 = sub_504980()
			if v2 != 0 {
				for {
					v3 = sub_5049C0(v2)
					v4 = int32(*(*uint16)(unsafe.Add(v2, 4)))
					if uint32(uint16(int16(v4))) == dword_5d4594_2487656 || uint32(v4) == *memmap.PtrUint32(0x5D4594, 2487660) || uint32(v4) == *memmap.PtrUint32(0x5D4594, 2487664) || uint32(v4) == *memmap.PtrUint32(0x5D4594, 2487668) {
						sub_504A10(v2)
					}
					v2 = v3
					if v3 == 0 {
						break
					}
				}
			}
			nox_xxx_mapgen_521C60(a1, *(*int32)(unsafe.Add(unsafe.Pointer(v1), 4*38)))
			sub_503B30((*types.Pointf)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v1), 4*37)), 20)))
		}
		v1 = (*int32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v1), 4*39)))
		if v1 == nil {
			break
		}
	}
	return 1
}
func sub_5268F0(a1 *byte) int32 {
	var (
		v1 int32
		i  *byte
	)
	v1 = 0
	if dword_5d4594_2487676 <= 0 {
		return -1
	}
	for i = dword_5d4594_2487672; libc.StrCmp(i, a1) != 0; i = (*byte)(unsafe.Add(unsafe.Pointer(i), 64)) {
		if func() int32 {
			p := &v1
			*p++
			return *p
		}() >= dword_5d4594_2487676 {
			return -1
		}
	}
	return v1
}
func sub_526950() *byte {
	var (
		v0     int32
		result *byte
		v2     int32
		v3     *byte
		v4     *byte
		v5     int32
		v6     uint8
		v7     int32
		v8     [256]byte
	)
	v0 = sub_502A20()
	dword_5d4594_2487676 = uint32(v0)
	result = (*byte)(alloc.Calloc1(int(v0), 0x40))
	v2 = 0
	dword_5d4594_2487672 = uint32(uintptr(unsafe.Pointer(result)))
	if result != nil {
		v7 = 0
		if dword_5d4594_2487676 > 0 {
			for {
				v3 = (*byte)(unsafe.Add(unsafe.Pointer(result), v2))
				libc.StrCpy(&v8[0], (*byte)(unsafe.Pointer(uintptr(sub_5029F0(v7)))))
				libc.StrCpy((*byte)(unsafe.Pointer(uintptr(dword_5d4594_2487672+uint32(v2)))), &v8[0])
				libc.StrTok(&v8[0], internCStr("-"))
				libc.StrTok(nil, internCStr("-"))
				v4 = libc.StrTok(nil, internCStr("-"))
				if v4 != nil {
					v5 = 0
					if int32(*memmap.PtrUint8(0x587000, 255032)) != 0 {
						for {
							if libc.StrChr(v4, *memmap.PtrUint8(0x587000, uintptr(v5)+255032)) != nil {
								*((*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*15))) |= 1 << v5
							}
							v6 = *memmap.PtrUint8(0x587000, uintptr(func() int32 {
								p := &v5
								x := *p
								*p++
								return x
							}())+255033)
							if int32(v6) == 0 {
								break
							}
						}
					}
				}
				result = (*byte)(unsafe.Add(v7, 1))
				v2 += 64
				if func() int32 {
					p := &v7
					*p++
					return *p
				}() >= dword_5d4594_2487676 {
					break
				}
				result = dword_5d4594_2487672
			}
		}
	} else {
		dword_5d4594_2487676 = 0
	}
	return result
}
func sub_526AA0(a1 int32) *byte {
	return (*byte)(unsafe.Pointer(uintptr(dword_5d4594_2487672 + uint32(a1<<6))))
}
func nox_xxx_mapGenSetRngSeed_526AB0(a1 uint32) {
	nox_platform_srand(a1)
}
func nox_xxx_mapGenRandFunc_526AC0(a1 int32, a2 int32) int32 {
	var result int32
	result = a1 + (a2-a1+1)*nox_platform_rand()/math.MaxInt16
	if result > a2 {
		result = a2
	}
	return result
}
func nox_xxx_mapGenRandFunc2_526B00(a1 int32, a2 int32) int32 {
	var (
		v3 int32
		v4 int32
		v5 int32
	)
	if a2 == 0 {
		return a1
	}
	v3 = 10000 / a2
	for {
		for {
			v4 = nox_xxx_mapGenRandFunc_526AC0(-a2, a2)
			v5 = nox_xxx_mapGenRandFunc_526AC0(0, 10000/a2)
			if v5 < v3*(a2-v4)/a2 {
				break
			}
		}
		if v5 < v3*(v4+a2)/a2 {
			break
		}
	}
	return v4 + a1
}
func sub_526BC0(a1 float32, a2 float32) float64 {
	return float64(uint32(nox_platform_rand()))*float64(a2-a1)*3.0518509e-05 + float64(a1)
}
func sub_526C40(a1 int32) int32 {
	if a1 != 1 && a1 != 0 {
		return 0
	}
	dword_5d4594_3835364 = uint32(a1)
	return 1
}
func sub_526C80(a1 int32) int32 {
	if a1 != 1 && a1 != 0 {
		return 0
	}
	dword_5d4594_3835368 = uint32(a1)
	return 1
}
func sub_526D50(a1 int32) int32 {
	var result int32
	if a1 < 0 || a1 >= 15 {
		*memmap.PtrUint32(0x973F18, 35952) = 0
		result = 0
	} else {
		*memmap.PtrUint32(0x973F18, 35952) = uint32(a1)
		result = 1
	}
	return result
}
func sub_526DD0(a1 *types.Pointf, a2 *int32) int32 {
	var (
		v2  int32
		v3  int64
		v4  int32
		a2a types.Pointf
	)
	if nox_xxx_mapGenFixCoords_4D3D90(a1, &a2a) == 0 {
		return 0
	}
	if a2 == nil {
		return 0
	}
	v2 = int32(int64(float64(a2a.X) * 0.043478262))
	v3 = int64(float64(a2a.Y) * 0.043478262)
	if (int32(uint8(int8(v3)))+int32(uint8(int8(v2))))&1 != 0 {
		return 0
	}
	if v2 < 0 {
		return 0
	}
	if v2 >= 256 {
		return 0
	}
	if int32(v3) < 0 {
		return 0
	}
	if int32(v3) >= 256 {
		return 0
	}
	v4 = int32(uintptr(nox_server_getWallAtGrid_410580(v2, int32(v3))))
	if v4 == 0 {
		return 0
	}
	*a2 = v4
	return 1
}
func sub_526E60(a1 *float32) int32 {
	var (
		v2  int32
		v3  int64
		v4  int32
		v5  *uint8
		v6  *uint8
		v7  *uint8
		v8  *uint8
		v9  int32
		v10 uint8
		v11 int16
		v12 int32
		v13 int32
		v14 int32
		v15 int32
		v16 types.Pointf
	)
	if *memmap.PtrUint32(0x973F18, 35948) == math.MaxUint8 {
		return 1
	}
	if nox_xxx_mapGenFixCoords_4D3D90((*types.Pointf)(unsafe.Pointer(a1)), &v16) != 0 {
		v2 = int32(int64(float64(v16.X) * 0.043478262))
		v3 = int64(float64(v16.Y) * 0.043478262)
		v4 = int32(v3)
		if ((int32(uint8(int8(v2)))+int32(uint8(int8(v3))))&1) == 0 && v2 >= 0 && v2 < 256 && int32(v3) >= 0 && int32(v3) < 256 {
			v5 = (*uint8)(nox_server_getWallAtGrid_410580(v2, int32(v3)))
			v6 = v5
			if v5 != nil {
				*(*uint8)(unsafe.Add(unsafe.Pointer(v5), 1)) = *memmap.PtrUint8(0x973F18, 35948)
				if dword_5d4594_3835368 == 1 {
					v10 = nox_xxx_wall_42A6C0(*memmap.PtrUint8(0x973F18, 35952), *v5)
				} else {
					v10 = *memmap.PtrUint8(0x973F18, 35952)
				}
				*v6 = v10
				if dword_5d4594_3835372 != 0 {
					v11 = int16(int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v6), 5))) % int32(int16(nox_xxx_map_410E00(int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v6), 1)))))))
				} else {
					*((*uint8)(unsafe.Pointer(&v11))) = *memmap.PtrUint8(0x973F18, 35956)
				}
				v15 = int32(*v6)
				v13 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v6), 1)))
				*(*uint8)(unsafe.Add(unsafe.Pointer(v6), 2)) = uint8(int8(v11))
				if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v6), 2))) >= int32(nox_xxx_mapWallMaxVariation_410DD0(v13, v15, 0)) {
					*(*uint8)(unsafe.Add(unsafe.Pointer(v6), 2)) = 0
				}
				*(*uint8)(unsafe.Add(unsafe.Pointer(v6), 4)) = 128
				return 1
			}
			v7 = (*uint8)(nox_xxx_wallCreateAt_410250(v2, v4))
			v8 = v7
			if v7 != nil {
				*(*uint8)(unsafe.Add(unsafe.Pointer(v7), 1)) = *memmap.PtrUint8(0x973F18, 35948)
				*v7 = *memmap.PtrUint8(0x973F18, 35952)
				if dword_5d4594_3835372 != 0 {
					v9 = v2 % int32(nox_xxx_map_410E00(int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v7), 1)))))
				} else {
					*((*uint8)(unsafe.Pointer(&v9))) = *memmap.PtrUint8(0x973F18, 35956)
				}
				v14 = int32(*v8)
				v12 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v8), 1)))
				*(*uint8)(unsafe.Add(unsafe.Pointer(v8), 2)) = uint8(int8(v9))
				*(*uint8)(unsafe.Add(unsafe.Pointer(v8), 4)) = 128
				if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v8), 2))) >= int32(nox_xxx_mapWallMaxVariation_410DD0(v12, v14, 0)) {
					*(*uint8)(unsafe.Add(unsafe.Pointer(v8), 2)) = 0
					return 1
				}
				return 1
			}
		}
	}
	return 0
}
func sub_527030(a1 *types.Pointf) int32 {
	var (
		v1 int32
		v2 int64
		v3 int32
		v4 int32
		v5 int32
		a2 types.Pointf
	)
	if nox_xxx_mapGenFixCoords_4D3D90(a1, &a2) == 0 {
		return 0
	}
	v1 = int32(int64(float64(a2.X) * 0.043478262))
	v2 = int64(float64(a2.Y) * 0.043478262)
	v3 = int32(v2)
	if (int32(uint8(int8(v2)))+int32(uint8(int8(v1))))&1 != 0 {
		return 0
	}
	if v1 < 0 {
		return 0
	}
	if v1 >= 256 {
		return 0
	}
	if int32(v2) < 0 {
		return 0
	}
	if int32(v2) >= 256 {
		return 0
	}
	v4 = int32(uintptr(nox_server_getWallAtGrid_410580(v1, int32(v2))))
	v5 = v4
	if v4 == 0 {
		return 0
	}
	if *(*uint32)(unsafe.Add(v4, 28)) != 0 {
		sub_4107A0(*(*unsafe.Pointer)(unsafe.Add(v4, 28)))
		*(*uint32)(unsafe.Add(v5, 28)) = 0
	}
	nox_xxx_mapDelWallAtPt_410430(v1, v3)
	return 1
}
func sub_527380(a1 *float32) int32 {
	var (
		v1 float64
		v2 int32
		v3 int64
		v4 int32
		v5 int32
		v6 int32
		v8 int32
		v9 int32
	)
	v1 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*1))) * 0.043478262
	v2 = int32(int64(float64(*a1) * 0.043478262))
	v8 = int32(int64(float64(*a1) * 0.043478262))
	v3 = int64(v1)
	v9 = int32(int64(v1))
	if v2 > 0 && v2 < math.MaxUint8 && int32(v3) > 0 && int32(v3) < math.MaxUint8 {
		sub_527450((*uint32)(unsafe.Pointer(&v8)))
		*(*uint32)(unsafe.Add(unsafe.Pointer(&v3), 4*0)) = uint32(v9)
		v2 = v8
	}
	v4 = v2 - 1
	v8 = v4
	if v4 > 0 && v4 < math.MaxUint8 && int32(v3) > 0 && int32(v3) < math.MaxUint8 {
		sub_527450((*uint32)(unsafe.Pointer(&v8)))
		*(*uint32)(unsafe.Add(unsafe.Pointer(&v3), 4*0)) = uint32(v9)
		v4 = v8
	}
	v5 = v4 + 1
	v6 = int32(v3 - 1)
	v8 = v5
	v9 = v6
	if v5 > 0 && v5 < math.MaxUint8 && v6 > 0 && v6 < math.MaxUint8 {
		sub_527450((*uint32)(unsafe.Pointer(&v8)))
	}
	return 1
}
func sub_527450(a1 *uint32) int32 {
	var (
		v1     int32
		v2     int32
		v3     int32
		result int32
		v5     int32
		v6     int32
		v7     int32
		v8     int32
		v9     int32
		v10    int32
		v11    int32
		v12    int64
		v13    int32
		v14    int32
		v15    int32
		v16    int32
		v17    int32
		v18    *uint8
		v19    *uint8
		v20    int32
		v21    uint8
		v22    uint8
		v23    *uint8
		v24    uint8
		v25    int32
		v26    int32
		v27    int32
		v28    *uint8
		v29    *uint8
		v30    int32
		v31    uint8
		v32    uint8
		v33    uint8
		v34    int32
		v35    int32
		v36    int32
		v37    int32
		v38    int32
		v39    int32
	)
	v1 = int32(*a1 - 1)
	if v1 > 0 {
		v2 = v1 & 0xFFFE
		v36 = v2
	} else {
		v36 = 0
		v2 = 0
	}
	v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*1)) - 1)
	if v3 > 0 {
		result = v3 & 0xFFFE
		v38 = result
	} else {
		v38 = 0
		result = 0
	}
	v5 = result + 4
	v6 = result
	v37 = result + 4
	for v6 <= v5 {
		v7 = v2
		for v7 <= v2+4 {
			v8 = int32(uintptr(nox_server_getWallAtGrid_410580(v7, v6)))
			v9 = v8
			if v8 != 0 && (int32(*(*uint8)(unsafe.Add(v8, 4)))&0x8C) == 0 {
				if *(*uint32)(unsafe.Add(v8, 28)) != 0 {
					sub_4107A0(*(*unsafe.Pointer)(unsafe.Add(v8, 28)))
					*(*uint32)(unsafe.Add(v9, 28)) = 0
				}
				nox_xxx_mapDelWallAtPt_410430(int32(*(*uint8)(unsafe.Add(v9, 5))), int32(*(*uint8)(unsafe.Add(v9, 6))))
			}
			v7++
		}
		v5 = v37
		result = v38
		v6++
	}
	v10 = result
	v35 = result
	if result > v5 {
		return result
	}
	v11 = v2 + 4
	for {
		v34 = v2
		v12 = int64(v10)
		v13 = int32(v12)
		result = int32(v12 - int64(*(*uint32)(unsafe.Add(unsafe.Pointer(&v12), 4*1))))
		v14 = v13 / 2
		if v2 > v11 {
			goto LABEL_72
		}
		for {
			v15 = 0
			v16 = v34 / 2
			if v34/2 >= 128 {
				goto LABEL_70
			}
			if v14 < 128 {
				v17 = int32(uint32(v14*44) + uint32(uintptr(unsafe.Pointer(*(**obj_5D4594_2650668_t)(unsafe.Add(unsafe.Pointer(ptr_5D4594_2650668), unsafe.Sizeof((*obj_5D4594_2650668_t)(nil))*uintptr(v16)))))))
				if *(*uint32)(unsafe.Add(v17, 24)) != math.MaxUint8 {
					v15 = 8
				}
				if *(*uint32)(unsafe.Add(v17, 4)) != math.MaxUint8 {
					v15 |= 2
				}
				if v14 > 0 && *(*uint32)(unsafe.Pointer(uintptr(v17 - 20))) != math.MaxUint8 {
					v15 |= 4
				}
				if v16 > 0 && *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(*(**obj_5D4594_2650668_t)(unsafe.Add(unsafe.Pointer(ptr_5D4594_2650668), unsafe.Sizeof((*obj_5D4594_2650668_t)(nil))*uintptr(v16-1))))))+uint32(v14*44))), 4)) != math.MaxUint8 {
					v15 |= 1
				}
				if *memmap.PtrUint32(0x587000, uintptr(v15*4)+255052) != math.MaxUint8 {
					v18 = (*uint8)(nox_server_getWallAtGrid_410580(v34, v35))
					v19 = v18
					if v18 != nil {
						if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v18), 4)))&0x8C != 0 {
							goto LABEL_45
						}
						if uint32(*v18) == *memmap.PtrUint32(0x587000, uintptr(v15*4)+255052) {
							goto LABEL_45
						}
						v20 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v18), 1)))
						if uint32(v20) == *memmap.PtrUint32(0x973F18, 35948) {
							goto LABEL_45
						}
						v21 = *memmap.PtrUint8(0x587000, uintptr(v15*4)+255052)
						*(*uint8)(unsafe.Add(unsafe.Pointer(v18), 2)) = 0
						*v18 = v21
						if int32(v21) != 0 {
							if int32(v21) != 1 {
								goto LABEL_45
							}
						}
						v22 = nox_xxx_map_410E00(v20)
					} else {
						v23 = (*uint8)(nox_xxx_wallCreateAt_410250(v34, v35))
						v19 = v23
						if v23 == nil {
							goto LABEL_45
						}
						v24 = *memmap.PtrUint8(0x587000, uintptr(v15*4)+255052)
						*(*uint8)(unsafe.Add(unsafe.Pointer(v23), 2)) = 0
						*v23 = v24
						*(*uint8)(unsafe.Add(unsafe.Pointer(v23), 1)) = *memmap.PtrUint8(0x973F18, 35948)
						if int32(v24) != 0 {
							if int32(v24) != 1 {
								goto LABEL_45
							}
						}
						v22 = nox_xxx_map_410E00(int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v23), 1))))
					}
					*(*uint8)(unsafe.Add(unsafe.Pointer(v19), 2)) = uint8(int8(int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v19), 5))) % int32(int16(v22))))
				}
			}
		LABEL_45:
			if v14 < 128 {
				v39 = 0
				if v14 > 0 && *(*uint32)(unsafe.Pointer(uintptr(uint32(uintptr(unsafe.Pointer(*(**obj_5D4594_2650668_t)(unsafe.Add(unsafe.Pointer(ptr_5D4594_2650668), unsafe.Sizeof((*obj_5D4594_2650668_t)(nil))*uintptr(v16)))))) + uint32(v14*44) - 20))) != math.MaxUint8 {
					v39 = 2
				}
				if v16 > 0 {
					v25 = v14 * 44
					v26 = int32(uintptr(unsafe.Pointer(*(**obj_5D4594_2650668_t)(unsafe.Add(unsafe.Pointer(ptr_5D4594_2650668), unsafe.Sizeof((*obj_5D4594_2650668_t)(nil))*uintptr(v16-1))))))
					if *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v26+v14*44)), 4)) != math.MaxUint8 {
						v39 |= 8
					}
					if v14 > 0 {
						if *(*uint32)(unsafe.Pointer(uintptr(v26 + v25 - 40))) != math.MaxUint8 {
							v39 |= 4
						}
						if *(*uint32)(unsafe.Pointer(uintptr(v26 + v25 - 20))) != math.MaxUint8 {
							v27 = v39
							*((*uint8)(unsafe.Pointer(&v27))) = uint8(int8(v39 | 1))
							v39 = v27
						}
					}
				}
				if *memmap.PtrUint32(0x587000, uintptr(v39*4)+255052) != math.MaxUint8 {
					v28 = (*uint8)(nox_server_getWallAtGrid_410580(v34-1, v35-1))
					v29 = v28
					if v28 != nil {
						if (int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v28), 4)))&0x8C) == 0 && uint32(*v28) != *memmap.PtrUint32(0x587000, uintptr(v39*4)+255052) {
							v30 = int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v28), 1)))
							if uint32(v30) != *memmap.PtrUint32(0x973F18, 35948) {
								v31 = *memmap.PtrUint8(0x587000, uintptr(v39*4)+255052)
								*(*uint8)(unsafe.Add(unsafe.Pointer(v28), 2)) = 0
								*v28 = v31
								if int32(v31) == 0 || int32(v31) == 1 {
									v32 = nox_xxx_map_410E00(v30)
									*(*uint8)(unsafe.Add(unsafe.Pointer(v29), 2)) = uint8(int8(int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v29), 5))) % int32(int16(v32))))
									goto LABEL_70
								}
							}
						}
					} else {
						v29 = (*uint8)(nox_xxx_wallCreateAt_410250(v34-1, v35-1))
						if v29 != nil {
							v33 = *memmap.PtrUint8(0x587000, uintptr(v39*4)+255052)
							*(*uint8)(unsafe.Add(unsafe.Pointer(v29), 2)) = 0
							*v29 = v33
							*(*uint8)(unsafe.Add(unsafe.Pointer(v29), 1)) = *memmap.PtrUint8(0x973F18, 35948)
							if int32(v33) == 0 || int32(v33) == 1 {
								v32 = nox_xxx_map_410E00(int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v29), 1))))
								*(*uint8)(unsafe.Add(unsafe.Pointer(v29), 2)) = uint8(int8(int32(*(*uint8)(unsafe.Add(unsafe.Pointer(v29), 5))) % int32(int16(v32))))
								goto LABEL_70
							}
						}
					}
				}
			}
		LABEL_70:
			result = v34 + 2
			v11 = v36 + 4
			v34 = result
			if result > v36+4 {
				break
			}
		}
		v5 = v37
		v10 = v35
		v2 = v36
	LABEL_72:
		v10 += 2
		v35 = v10
		if v10 > v5 {
			break
		}
	}
	return result
}
func nox_xxx_mapGenGetObjID_527940(a1 *byte) int32 {
	var result int32
	if nox_strcmpi(a1, internCStr("NONE")) != 0 {
		if a1 != nil {
			dword_5d4594_3835388 = uint32(nox_xxx_getNameId_4E3AA0(a1))
			result = 1
		} else {
			result = 0
		}
	} else {
		dword_5d4594_3835388 = 0
		result = 1
	}
	return result
}
func nox_xxx_mapGenPlaceObj_5279B0(a1 *types.Pointf) *float32 {
	var (
		result *float32
		a2     types.Pointf
	)
	if dword_5d4594_3835388 == 0 {
		return nil
	}
	result = (*float32)(unsafe.Pointer(uintptr(nox_xxx_mapGenFixCoords_4D3D90(a1, &a2))))
	if result != nil {
		result = (*float32)(unsafe.Pointer(nox_xxx_newObjectWithTypeInd_4E3450(dword_5d4594_3835388)))
		if result != nil {
			result = nox_xxx_mapGenMoveObject_527A10(result, (*types.Pointf)(unsafe.Pointer(&a1.X)))
		}
	}
	return result
}
func nox_xxx_mapGenMoveObject_527A10(a1 *float32, a2 *types.Pointf) *float32 {
	var (
		v3 float32
		v4 float32
		v5 int32
		v6 *byte
		v7 types.Pointf
	)
	if nox_xxx_mapGenFixCoords_4D3D90(a2, &v7) == 0 {
		return a1
	}
	if a1 == nil {
		return nil
	}
	v3 = v7.Y
	*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*10)) = dword_5d4594_3835392
	v4 = v7.X
	dword_5d4594_3835392++
	*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*15)) = v3
	v5 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4))) | 0x1000000)
	*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*14)) = v4
	*((*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*4))) = uint32(v5)
	v6 = nox_xxx_getUnitName_4E39D0((*server.Object)(unsafe.Pointer(a1)))
	if nox_objectTypeGetXfer(v6) == ccall.FuncAddr(nox_xxx_XFerDoor_4F4CB0) {
		*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*14)) = float32(float64(int32(uint32(uint64(int64(float64(v7.X)*0.043478262+0.5)) * 23))))
		*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*15)) = float32(float64(int32(uint32(uint64(int64(float64(v7.Y)*0.043478262+0.5)) * 23))))
	}
	nox_xxx_createAt_4DAA50((*server.Object)(unsafe.Pointer(a1)), nil, *(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*14)), *(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*15)))
	nox_xxx_unitClearPendingMB_4DB030()
	return a1
}
func nox_xxx_mapGenOrientObj_527C60(a1 int32, a2 int32) int32 {
	var (
		v2     int32
		v3     int32
		v4     int32
		result int32
		v6     *uint32
		v7     int32
		v8     int32
		v9     int32
		v10    int32
	)
	if a1 == 0 {
		return 0
	}
	if (int32(*(*uint8)(unsafe.Add(a1, 8))) & 2) == 2 {
		v2 = int32(*(*uint32)(unsafe.Add(a1, 748)))
		v3 = sub_4D3FF0(a2)
		v4 = nox_xxx_mathDirection4ToAngle_509E90(v3)
		*(*uint32)(unsafe.Add(v2, 376)) = uint32(v4)
		*(*uint16)(unsafe.Add(a1, 124)) = uint16(int16(v4))
		return 1
	}
	if (*(*uint32)(unsafe.Add(a1, 8)) & 0x80) == 0 {
		return 0
	}
	v6 = *(**uint32)(unsafe.Add(a1, 748))
	switch a2 {
	case 1:
		*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*3)) = 0
		v7 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*3)))
		*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*1)) = uint32(v7)
		*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*2)) = uint32(v7)
		result = 1
	case 3:
		*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*3)) = 24
		v10 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*3)))
		*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*1)) = uint32(v10)
		*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*2)) = uint32(v10)
		result = 1
	case 5:
		*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*3)) = 8
		v8 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*3)))
		*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*1)) = uint32(v8)
		*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*2)) = uint32(v8)
		result = 1
	case 7:
		*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*3)) = 16
		v9 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*3)))
		*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*1)) = uint32(v9)
		*(*uint32)(unsafe.Add(unsafe.Pointer(v6), 4*2)) = uint32(v9)
		result = 1
	default:
		return 0
	}
	return result
}
func nox_xxx_mapGenFinishSpellbook_527DB0(a1 int32, a2 int8) int32 {
	var v3 *byte
	if a1 == 0 {
		return 0
	}
	v3 = nox_xxx_getUnitName_4E39D0((*server.Object)(a1))
	if nox_objectTypeGetXfer(v3) != ccall.FuncAddr(nox_xxx_XFerSpellReward_4F5F30) {
		return 0
	}
	**(**uint8)(unsafe.Add(a1, 736)) = uint8(a2)
	return 1
}
func sub_527E00(a1 *server.Object) *int32 {
	var (
		v1     int32
		result *int32
		v3     int32
	)
	v1 = 32
	result = (*int32)(unsafe.Add(unsafe.Pointer(a1), 560))
	for {
		v3 = *result
		result = (*int32)(unsafe.Add(unsafe.Pointer(result), 4*1))
		v1--
		*((*int32)(unsafe.Add(unsafe.Pointer(result), -int(4*1)))) = v3 & 0xFFF
		if v1 == 0 {
			break
		}
	}
	return result
}
func nox_xxx_netUpdateObjectSpecial_527E50(a1p *server.Object, a2p *server.Object) int32 {
	var (
		a1 int32   = int32(uintptr(unsafe.Pointer(a1p)))
		a2 *uint32 = (*uint32)(unsafe.Pointer(a2p))
		v2 uint32
		v3 int32
	)
	v2 = uint32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 748)), 276)), 2064)))
	if a2 != nil && v2 < 0x20 {
		v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*uintptr(v2+140))))
		if (uint32(v3) & 0xFFF0000) == 0 {
			return 0
		}
		if (uint32(v3) & 0x10000) == 0x10000 {
			nox_xxx_netReportAnimFrame_4D81F0(int32(v2), a2)
			*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*uintptr(v2+140))) &= 0xFFFEFFFF
		}
		if (*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*uintptr(v2+140))) & 0x20000) == 0x20000 {
			if nox_xxx_unitIsEnemyTo_5330C0((*server.Object)(a1), (*server.Object)(unsafe.Pointer(a2))) == 0 {
				nox_xxx_netReportUnitCurrentHP_4D8620(int32(v2), a2)
			}
			*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*uintptr(v2+140))) &= 0xFFFDFFFF
		}
		if (*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*uintptr(v2+140))) & 0x40000) == 0x40000 {
			nox_xxx_netReportObjHidden_4D8FD0(int32(v2), a2)
			*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*uintptr(v2+140))) &= 0xFFFBFFFF
		}
		if (*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*uintptr(v2+140))) & 0x80000) == 0x80000 {
			nox_xxx_netReportXStatus_4D8230(int32(v2), a2)
			*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*uintptr(v2+140))) &= 0xFFF7FFFF
		}
		if (*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*uintptr(v2+140))) & 0x400000) == 0x400000 {
			nox_xxx_netReportUnitHeight_4D9020(int32(v2), (*server.Object)(unsafe.Pointer(a2)))
			*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*uintptr(v2+140))) &= 0xFFBFFFFF
		}
		if (*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*uintptr(v2+140))) & 0x800000) == 0x800000 {
			nox_xxx_netReportEnchant_4D8F90(int32(v2), a2)
			*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*uintptr(v2+140))) &= 0xFF7FFFFF
		}
		if (*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*uintptr(v2+140))) & 0x2000000) == 0x2000000 {
			nox_xxx_netReportTeamBase_4D92D0(int32(v2), int32(uintptr(unsafe.Pointer(a2))))
			*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*uintptr(v2+140))) &= 0xFDFFFFFF
		}
		if (*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*uintptr(v2+140))) & 0x4000000) == 0x4000000 {
			nox_xxx_netSendReportNPC_4D93A0(int32(v2), int32(uintptr(unsafe.Pointer(a2))))
			*(*uint32)(unsafe.Add(unsafe.Pointer(a2), 4*uintptr(v2+140))) &= 0xFBFFFFFF
		}
	}
	return 1
}
func sub_528030(a1 unsafe.Pointer) int16 {
	var (
		v2     int32
		v3     *uint16
		v4     int32
		v5     int32
		v6     int32
		v7     uint32
		v8     int32
		result int16
		v10    int32
		v11    int32
	)
	v1 := a1
	v2 = int32(*(*uint32)(unsafe.Add(a1, 748)))
	v3 = *(**uint16)(unsafe.Add(a1, 556))
	v4 = int32(*(*uint32)(unsafe.Add(v2, 276)))
	v11 = int32(*(*uint8)(unsafe.Add(v4, 2064)))
	if int32(*(*uint16)(unsafe.Add(v2, 10))) == int32(*v3) {
		v5 = int32(gameFrame())
		v7 = gameFPS()
	} else if cmath.Abs(int64(int32(*v3)-int32(*(*uint16)(unsafe.Add(v2, 10))))) >= int64(int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(uint16(0))*2)))/10) || (func() bool {
		v5 = int32(gameFrame())
		v6 = int32(*(*uint32)(unsafe.Add(v4, 2176)))
		v7 = gameFPS()
		return (gameFrame() - uint32(v6)) > uint32(int32(gameFPS())>>2)
	}()) {
		nox_xxx_netSendPlrHealthToTeam_4D86E0(v11)
		v8 = int32(*(*uint32)(unsafe.Add(v2, 276)))
		*(*uint16)(unsafe.Add(v2, 10)) = **(**uint16)(unsafe.Add(v1, 556))
		*(*uint32)(unsafe.Add(v8, 2176)) = gameFrame()
		v5 = int32(gameFrame())
		v7 = gameFPS()
	}
	result = int16(*(*uint16)(unsafe.Add(v2, 4)))
	if int32(*(*uint16)(unsafe.Add(v2, 6))) != int32(result) {
		result = 0
		if cmath.Abs(int64(int32(*(*uint16)(unsafe.Add(v2, 4)))-int32(*(*uint16)(unsafe.Add(v2, 6))))) >= int64(int32(*(*uint16)(unsafe.Add(v2, 8)))/10) || uint32(v5)-*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v2, 276)), 2180)) > v7>>2 {
			nox_xxx_netReportMana_4D8930(v11, v1)
			v10 = int32(*(*uint32)(unsafe.Add(v2, 276)))
			*(*uint16)(unsafe.Add(v2, 6)) = *(*uint16)(unsafe.Add(v2, 4))
			result = int16(uint16(gameFrame()))
			*(*uint32)(unsafe.Add(v10, 2180)) = gameFrame()
		}
	}
	return result
}
func nox_xxx_checkIsKillable_528190(a1p *server.Object) int32 {
	var (
		a1 int32 = int32(uintptr(unsafe.Pointer(a1p)))
		v1 *uint16
		v2 bool
	)
	v1 = *(**uint16)(unsafe.Add(a1, 556))
	if v1 == nil {
		return 0
	}
	if int32(*v1) != 0 {
		v2 = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(uint16(0))*2))) == 0
		if int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(uint16(0))*2))) != 0 {
			return 1
		}
	} else {
		v2 = int32(*(*uint16)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(uint16(0))*2))) == 0
	}
	if v2 {
		return 1
	} else {
		return 0
	}
}
func nox_xxx_frameCounterSetCopyToNextFrame_5281D0() int32 {
	var result int32
	result = int32(gameFrame() + 1)
	*memmap.PtrUint32(0x5D4594, 2487684) = gameFrame() + 1
	return result
}
func nox_xxx_frameCounterSetCopy_5281E0() int32 {
	var result int32
	result = int32(gameFrame())
	*memmap.PtrUint32(0x5D4594, 2487684) = gameFrame()
	return result
}
func nox_xxx_unitUpdateSightMB_5281F0(a1p *server.Object) {
	var (
		a1  = unsafe.Pointer(a1p)
		v2  int32
		v3  int32
		v4  float64
		v5  int32
		v6  *int32
		v7  float64
		v8  float64
		v9  float64
		v10 float64
		v11 int32
		v12 int32
		v13 int32
		v14 int32
		v15 int32
		v16 int32
		v17 int32
		v18 float32
		v19 int32
		v20 float32
		v21 float32
	)
	v1 := a1
	v17 = 0
	v2 = int32(*(*uint32)(unsafe.Add(a1, 16)))
	v3 = int32(*(*uint32)(unsafe.Add(a1, 748)))
	if (v2&0x8000) != 0 && nox_xxx_unitIsZombie_534A40(a1) == 0 {
		return
	}
	if noxflags.HasGame(4096) {
		v4 = 640.0
	} else {
		v4 = 250.0
	}
	if v4 >= float64(*(*float32)(unsafe.Add(v3, 1312))) {
		v21 = float32(v4)
	} else {
		v21 = *(*float32)(unsafe.Add(v3, 1312))
	}
	if gameFrame()-*(*uint32)(unsafe.Add(v3, 1212)) <= (gameFPS() * 2) {
		v19 = 0
	} else {
		v19 = 1
		*(*uint32)(unsafe.Add(v3, 1212)) = gameFrame()
	}
	v5 = 0
	if int32(*(*uint8)(unsafe.Add(v3, 1129))) != 0 {
		v6 = (*int32)(unsafe.Add(v3, 1132))
		for {
			if *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*v6)), 16))&0x8020 != 0 || nox_xxx_unitCanSee_536FB0((*server.Object)(v1), (*server.Object)(unsafe.Pointer(uintptr(*v6))), 0) == 0 || (func() bool {
				v7 = float64(*(*float32)(unsafe.Add(v1, 56)) - *(*float32)(unsafe.Add(unsafe.Pointer(uintptr(*v6)), 56)))
				v8 = float64(*(*float32)(unsafe.Add(v1, 60)) - *(*float32)(unsafe.Add(unsafe.Pointer(uintptr(*v6)), 60)))
				v20 = float32((float64(v21) + 30.0) * (float64(v21) + 30.0))
				return v8*v8+v7*v7 > float64(v20)
			}()) || (func() bool {
				v9 = float64(*(*float32)(unsafe.Add(v1, 56)) - *(*float32)(unsafe.Add(v1, 72)))
				v10 = float64(*(*float32)(unsafe.Add(v1, 60)) - *(*float32)(unsafe.Add(v1, 76)))
				return v10*v10+v9*v9 > 1000.0
			}()) || v19 != 0 && nox_xxx_unitCanInteractWith_5370E0((*server.Object)(v1), (*server.Object)(unsafe.Pointer(uintptr(*v6))), 0) == 0 {
				nox_xxx_aiLostSight_528560(v1, func() int32 {
					p := &v5
					x := *p
					*p--
					return x
				}())
				v17 = 1
				v6 = (*int32)(unsafe.Add(unsafe.Pointer(v6), -int(4*1)))
			}
			v5++
			v6 = (*int32)(unsafe.Add(unsafe.Pointer(v6), 4*1))
			if v5 >= int32(*(*uint8)(unsafe.Add(v3, 1129))) {
				break
			}
		}
	}
	v11 = int32(*(*uint32)(unsafe.Add(v3, 1196)))
	if v11 != 0 && nox_xxx_testUnitBuffs_4FF350((*server.Object)(v11), 28) != 0 {
		v17 = 1
	}
	if (*(*uint32)(unsafe.Add(v3, 1196)) == 0 || gameFrame()-*(*uint32)(unsafe.Add(v3, 1204)) > (gameFPS()*2)) && (*(*uint32)(unsafe.Add(v3, 1208)) <= gameFrame() || gameFrame() == *memmap.PtrUint32(0x5D4594, 2487684)) {
		nox_xxx_unitsGetInCircle_517F90((*types.Pointf)(unsafe.Add(v1, 56)), v21, nox_xxx_monsterUpdateSeenEnemies_5286D0, v1)
		*(*uint32)(unsafe.Add(v3, 1204)) = gameFrame()
		*(*uint32)(unsafe.Add(v3, 1212)) = gameFrame()
		v17 = 1
	}
	if v17 != 0 {
		v12 = int32(*(*uint32)(unsafe.Add(v3, 1196)))
		if v12 != 0 {
			v13 = int32(*(*uint32)(unsafe.Add(v12, 36)))
		} else {
			v13 = 0
		}
		sub_528610(v1)
		v14 = int32(*(*uint32)(unsafe.Add(v3, 1196)))
		if v14 != 0 && v13 != 0 && uint32(v13) != *(*uint32)(unsafe.Add(v14, 36)) {
			*(*uint32)(unsafe.Add(v3, 1200)) = uint32(v13)
		}
	}
	if *(*uint32)(unsafe.Add(v3, 1204)) == gameFrame() {
		v15 = int32(*(*uint32)(unsafe.Add(v3, 1440)))
		if v15&0x400 != 0 || noxflags.HasGame(0x2000) || *(*uint32)(unsafe.Add(v3, 1196)) != 0 {
			*(*uint32)(unsafe.Add(v3, 1208)) = gameFrame() + uint32(nox_common_randomInt_415FA0(5, 10))
		} else {
			v16 = int32(gameFPS() * 5)
			v18 = float32(sub_5336D0((*server.Object)(v1)))
			*(*float32)(unsafe.Add(v3, 524)) = v18
			if float64(v18) < 0.0 {
				*(*uint32)(unsafe.Add(v3, 1208)) = uint32(v16) + gameFrame()
			} else if float64(v18) > float64(v21) {
				*(*uint32)(unsafe.Add(v3, 1208)) = uint32(uint64(int64(float64(v18-v21)*float64(v16)/(1000.0-float64(v21)))) + 10 + uint64(gameFrame()))
			} else {
				*(*uint32)(unsafe.Add(v3, 1208)) = uint32(nox_common_randomInt_415FA0(5, 10)) + gameFrame()
			}
		}
	}
}
func nox_xxx_aiLostSight_528560(a1 unsafe.Pointer, a2 int32) int32 {
	var (
		v2     int32
		v3     int32
		v4     *int32
		v5     int32
		v6     int32
		v7     int32
		v8     int32
		result int32
		v10    int32
	)
	v2 = int32(*(*uint32)(unsafe.Add(a1, 748)))
	v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v2+a2*4)), 1132)))
	v4 = (*int32)(unsafe.Add(unsafe.Pointer(uintptr(v2+a2*4)), 1132))
	v10 = int32(*(*uint32)(unsafe.Add(v3, 36)))
	v5 = int32(uintptr(unsafe.Pointer(nox_xxx_getUnitName_4E39D0((*server.Object)(v3)))))
	nox_ai_debug_printf_5341A0(internCStr("%d: Lost sight of %s(#%d)\n"), gameFrame(), v5, v10)
	nox_xxx_scriptCallByEventBlock_502490(unsafe.Add(v2, 1296), unsafe.Pointer(uintptr(*v4)), a1, 15)
	v6 = int32(*(*uint32)(unsafe.Add(v2, 1196)))
	if *v4 == v6 {
		v7 = int32(*(*uint32)(unsafe.Add(v6, 36)))
		*(*uint32)(unsafe.Add(v2, 1196)) = 0
		*(*uint32)(unsafe.Add(v2, 1200)) = uint32(v7)
	}
	v8 = a2
	*((*uint8)(unsafe.Pointer(&result))) = uint8(int8(int32(*(*uint8)(unsafe.Add(v2, 1129))) - 1))
	*(*uint8)(unsafe.Add(v2, 1129)) = uint8(int8(result))
	result = int32(uint8(int8(result)))
	if a2 < int32(uint8(int8(result))) {
		result = v2 + a2*4 + 1132
		for {
			v8++
			*(*uint32)(result) = *(*uint32)(unsafe.Add(result, 4))
			result += 4
			if v8 >= int32(*(*uint8)(unsafe.Add(v2, 1129))) {
				break
			}
		}
	}
	return result
}
func sub_528610(a1 unsafe.Pointer) {
	var (
		v2 int32
		v3 int32
		v4 int8
		i  *int32
		v6 float64
		v7 float64
		v8 float64
		v9 float32
	)
	v1 := a1
	v2 = int32(*(*uint32)(unsafe.Add(a1, 748)))
	v3 = 0
	v9 = 1e+08
	v4 = int8(*(*uint8)(unsafe.Add(v2, 1129)))
	*(*uint32)(unsafe.Add(v2, 1196)) = 0
	if int32(v4) != 0 {
		for i = (*int32)(unsafe.Add(v2, 1132)); uint32(*i) != *(*uint32)(unsafe.Add(v2, 1216)); i = (*int32)(unsafe.Add(unsafe.Pointer(i), 4*1)) {
			if nox_xxx_unitIsEnemyTo_5330C0((*server.Object)(v1), (*server.Object)(unsafe.Pointer(uintptr(*i)))) != 0 && nox_xxx_checkIsKillable_528190((*server.Object)(unsafe.Pointer(uintptr(*i)))) != 0 {
				v6 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(uintptr(*i)), 56)) - *(*float32)(unsafe.Add(v1, 56)))
				v7 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(uintptr(*i)), 60)) - *(*float32)(unsafe.Add(v1, 60)))
				v8 = v7*v7 + v6*v6
				if v8 < float64(v9) {
					v9 = float32(v8)
					*(*uint32)(unsafe.Add(v2, 1196)) = uint32(*i)
				}
			}
			if func() int32 {
				p := &v3
				*p++
				return *p
			}() >= int32(*(*uint8)(unsafe.Add(v2, 1129))) {
				return
			}
		}
		*(*uint32)(unsafe.Add(v2, 1196)) = *(*uint32)(unsafe.Add(v2, 1216))
	}
}
func nox_xxx_monsterUpdateSeenEnemies_5286D0(it *server.Object, data unsafe.Pointer) {
	a1 := it.CObj()
	a2 := data
	var (
		v3  int32
		v4  int32
		v5  int32
		v6  float64
		v7  float64
		v8  *float32
		v9  float32
		v10 float32
	)
	v2 := a2
	v3 = int32(*(*uint32)(unsafe.Add(a2, 748)))
	if a2 != a1 {
		if int32(*(*uint8)(unsafe.Add(a1, 8)))&6 != 0 {
			if (*(*uint32)(unsafe.Add(a1, 16)) & 0x8020) == 0 {
				v4 = int32(*(*uint32)(unsafe.Add(v3, 1440)))
				if (v4&0x400 != 0 || nox_xxx_unitIsEnemyTo_5330C0((*server.Object)(a2), (*server.Object)(a1)) != 0) && sub_528950(a2, a1) == 0 {
					v5 = int32(*(*uint32)(unsafe.Add(v3, 1440)))
					if v5&0x100 != 0 || (func() bool {
						v6 = float64(*(*float32)(unsafe.Add(a1, 56)) - *(*float32)(unsafe.Add(a2, 56)))
						v7 = float64(*(*float32)(unsafe.Add(a1, 60)) - *(*float32)(unsafe.Add(a2, 60)))
						v9 = float32(v7)
						v8 = mem_getFloatPtr(0x587000, uint32(int32(*(*int16)(unsafe.Add(a2, 124)))*8)+194136)
						v10 = float32(math.Sqrt(v7*float64(v9)+v6*v6) + 0.001)
						return float64(v9/v10**(*float32)(unsafe.Add(unsafe.Pointer(v8), unsafe.Sizeof(float32(0))*1)))+v6/float64(v10)*float64(*v8) >= 0.5
					}()) {
						if nox_xxx_unitCanInteractWith_5370E0((*server.Object)(v2), (*server.Object)(a1), 0) != 0 {
							nox_xxx_monsterVisionSeeEnemy_5287B0(v2, a1)
						}
					}
				}
			}
		}
	}
}
func nox_xxx_monsterVisionSeeEnemy_5287B0(a1 unsafe.Pointer, a2 unsafe.Pointer) {
	var (
		v3  float64
		v4  int32
		v5  int32
		v6  int32
		v7  int32
		v8  float64
		v9  float64
		v10 float64
		v11 unsafe.Pointer
		v12 float64
		v13 float64
		v15 uint32
		v16 int32
		v17 int32
		v18 float32
	)
	v2 := a1
	v3 = 0.0
	v4 = int32(*(*uint32)(unsafe.Add(a1, 748)))
	v5 = 16
	v6 = 0
	if int32(*(*uint8)(unsafe.Add(v4, 1129))) == 16 {
		v7 = v4 + 1132
		for {
			v8 = float64(*(*float32)(unsafe.Add(*(*unsafe.Pointer)(v7), 56)) - *(*float32)(unsafe.Add(v2, 56)))
			v9 = float64(*(*float32)(unsafe.Add(*(*unsafe.Pointer)(v7), 60)) - *(*float32)(unsafe.Add(v2, 60)))
			v10 = v9*v9 + v8*v8
			if v10 > v3 {
				v18 = float32(v10)
				v3 = float64(v18)
				v6 = int32(*(*uint32)(v7))
			}
			v7 += 4
			v5--
			if v5 == 0 {
				break
			}
		}
		v11 = a2
		v12 = float64(*(*float32)(unsafe.Add(a2, 56)) - *(*float32)(unsafe.Add(v2, 56)))
		v13 = float64(*(*float32)(unsafe.Add(a2, 60)) - *(*float32)(unsafe.Add(v2, 60)))
		if v3 <= v13*v13+v12*v12 {
			return
		}
		sub_528910(v2, v6)
	} else {
		v11 = a2
	}
	*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(uintptr(v4+int32(*(*uint8)(unsafe.Add(v4, 1129)))*4)), 1132)) = v11
	v15 = *(*uint32)(unsafe.Add(v4, 536))
	*(*uint8)(unsafe.Add(v4, 1129))++
	if gameFrame() > v15 {
		if nox_xxx_unitIsEnemyTo_5330C0((*server.Object)(v2), (*server.Object)(v11)) != 0 {
			if nox_xxx_unitIsZombie_534A40(v2) == 0 || (func() bool {
				v16 = int32(*(*uint32)(unsafe.Add(v2, 16)))
				return (v16 & 0x8000) == 0
			}()) {
				v17 = int32(uintptr(nox_xxx_monsterGetSoundSet_424300((*server.Object)(v2))))
				if v17 != 0 {
					nox_xxx_aud_501960(int32(*(*uint32)(unsafe.Add(v17, 68))), (*server.Object)(v2), 0, 0)
				}
				*(*uint32)(unsafe.Add(v4, 536)) = gameFrame() + uint32(nox_common_randomInt_415FA0(int32(gameFPS()*2), int32(gameFPS()*4)))
			}
		}
	}
	nox_xxx_scriptCallByEventBlock_502490(unsafe.Add(v4, 1232), v11, v2, 14)
}
func sub_528910(a1 unsafe.Pointer, a2 int32) int32 {
	var (
		result int32
		v3     int32
		v4     int32
		i      *uint32
	)
	result = 0
	v3 = int32(*(*uint32)(unsafe.Add(a1, 748)))
	v4 = int32(*(*uint8)(unsafe.Add(v3, 1129)))
	if v4 > 0 {
		for i = (*uint32)(unsafe.Add(v3, 1132)); *i != uint32(a2); i = (*uint32)(unsafe.Add(unsafe.Pointer(i), 4*1)) {
			if func() int32 {
				p := &result
				*p++
				return *p
			}() >= v4 {
				return result
			}
		}
		result = nox_xxx_aiLostSight_528560(a1, result)
	}
	return result
}
func sub_528950(a1 unsafe.Pointer, a2 unsafe.Pointer) int32 {
	var (
		v2 int32
		v3 int32
		v4 int32
		i  *uint32
	)
	v2 = int32(*(*uint32)(unsafe.Add(a1, 748)))
	v3 = 0
	v4 = int32(*(*uint8)(unsafe.Add(v2, 1129)))
	if v4 <= 0 {
		return 0
	}
	for i = (*uint32)(unsafe.Add(v2, 1132)); *(*unsafe.Pointer)(unsafe.Pointer(i)) != a2; i = (*uint32)(unsafe.Add(unsafe.Pointer(i), 4*1)) {
		if func() int32 {
			p := &v3
			*p++
			return *p
		}() >= v4 {
			return 0
		}
	}
	return 1
}
func sub_528990(a1 *server.Object) {
	result := unsafe.Pointer(nox_xxx_getFirstUpdatableObject_4DA8A0())
	for i := result; result != nil; i = result {
		if int32(*(*uint8)(unsafe.Add(i, 8)))&2 != 0 {
			if (int32(*(*uint8)(unsafe.Add(i, 16))) & 0x20) == 0 {
				sub_528910(i, int32(uintptr(unsafe.Pointer(a1))))
				sub_528610(i)
			}
		}
		result = unsafe.Pointer(nox_xxx_getNextUpdatableObject_4DA8B0((*server.Object)(i)))
	}
}
func nox_xxx_netReportDestroyObject_5289D0(a1p *server.Object) {
	var (
		a1     int32 = int32(uintptr(unsafe.Pointer(a1p)))
		result *byte
		i      int32
		v4     int32
	)
	result = (*byte)(unsafe.Pointer(nox_common_playerInfoGetFirst_416EA0()))
	for i = int32(uintptr(unsafe.Pointer(result))); result != nil; i = int32(uintptr(unsafe.Pointer(result))) {
		if uint32(1<<int32(*(*uint8)(unsafe.Add(i, 2064))))&*(*uint32)(unsafe.Add(a1, 148)) != 0 {
			*((*uint8)(unsafe.Pointer(&v4))) = uint8(int8((int32(uint8(*(*uint32)(unsafe.Add(a1, 20)))) >> 6) | 0x31))
			*(*uint16)(unsafe.Add(unsafe.Pointer(&v4), 1)) = uint16(nox_xxx_netGetUnitCodeServ_578AC0((*server.Object)(a1)))
			nox_xxx_netSendPacket0_4E5420(int32(*(*uint8)(unsafe.Add(i, 2064))), unsafe.Pointer(&v4), 3, nil, 1)
		}
		if int32(*(*uint8)(unsafe.Add(a1, 8)))&6 != 0 {
			nox_xxx_netFriendAddRemove_4D97A0(int32(*(*uint8)(unsafe.Add(i, 2064))), (*uint32)(a1), 0)
		}
		result = (*byte)(unsafe.Pointer(nox_common_playerInfoGetNext_416EE0((*server.Player)(i))))
	}
}
func nox_xxx_netObjectOutOfSight_528A60(a1 int32, a2 *uint32) int32 {
	var v4 [3]byte
	v4[0] = 50
	*(*uint16)(unsafe.Pointer(&v4[1])) = uint16(nox_xxx_netGetUnitCodeServ_578AC0((*server.Object)(unsafe.Pointer(a2))))
	return nox_xxx_netSendPacket0_4E5420(a1, unsafe.Pointer(&v4[0]), 3, nil, 1)
}
func nox_xxx_netObjectInShadows_528A90(a1 int32, a2 *uint32) int32 {
	var v4 [3]byte
	v4[0] = 51
	*(*uint16)(unsafe.Pointer(&v4[1])) = uint16(nox_xxx_netGetUnitCodeServ_578AC0((*server.Object)(unsafe.Pointer(a2))))
	return nox_xxx_netSendPacket0_4E5420(a1, unsafe.Pointer(&v4[0]), 3, nil, 1)
}
func nox_xxx_monsterCmdSend_528BD0(unit unsafe.Pointer, source unsafe.Pointer, command *byte, a4 int16) {
	var (
		v4  int16
		v5  float64
		v6  int64
		v7  float64
		v10 [520]byte
	)
	v10[0] = 168
	v10[3] = 8
	v4 = int16(uint16(nox_xxx_netGetUnitCodeServ_578AC0((*server.Object)(unit))))
	v5 = float64(*(*float32)(unsafe.Add(unit, 56)))
	*(*uint16)(unsafe.Pointer(&v10[1])) = uint16(v4)
	v6 = int64(v5)
	v7 = float64(*(*float32)(unsafe.Add(unit, 60)))
	*(*uint16)(unsafe.Pointer(&v10[4])) = uint16(int16(v6))
	*(*uint16)(unsafe.Pointer(&v10[6])) = uint16(int16(int64(v7)))
	*(*uint16)(unsafe.Pointer(&v10[9])) = uint16(a4)
	v10[8] = byte(int8(libc.StrLen(command) + 1))
	libc.StrCpy(&v10[11], command)
	if source != nil {
		if int32(*(*uint8)(unsafe.Add(source, 8)))&4 != 0 {
			nox_netlist_addToMsgListCli_40EBC0(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(source, 748)), 276)), 2064))), 1, &v10[0], int32(v10[8])+11)
		}
	} else {
		result := unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0())
		for i := result; result != nil; i = result {
			nox_netlist_addToMsgListCli_40EBC0(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(i, 748)), 276)), 2064))), 1, &v10[0], int32(v10[8])+11)
			result = unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(i)))
		}
	}
}
func nox_xxx_destroyEveryChatMB_528D60() int32 {
	var (
		result int32
		i      int32
		v2     [3]byte
	)
	v2[0] = 202
	*(*uint16)(unsafe.Pointer(&v2[1])) = 57005
	result = int32(uintptr(unsafe.Pointer(nox_xxx_getFirstPlayerUnit_4DA7C0())))
	for i = result; result != 0; i = result {
		nox_netlist_addToMsgListCli_40EBC0(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(i, 748)), 276)), 2064))), 1, &v2[0], 3)
		result = int32(uintptr(unsafe.Pointer(nox_xxx_getNextPlayerUnit_4DA7F0((*server.Object)(i)))))
	}
	return result
}
func nox_xxx_XFerMonster_528DB0(a1p *server.Object, data unsafe.Pointer) int {
	a1 := a1p.CObj()
	var (
		v1     int32
		result int32
		v3     *byte
		v4     *byte
		v5     *byte
		v6     *byte
		v7     *byte
		v8     *byte
		v9     *byte
		v10    *byte
		v11    *byte
		v12    *byte
		v13    *byte
		v14    int32
		v15    int16
		v16    int32
		v17    *uint32
		v18    *uint32
		v19    int32
		v20    int32
		v21    *byte
		i      int32
		v23    int32
		v24    *int32
		v25    *byte
		v26    *byte
		v27    int32
		v28    uint8
		v29    *uint8
		v30    int32
		v31    int32
		v32    int32
		v33    int32
		j      unsafe.Pointer
		v35    int32
		v36    int32
		v37    *uint32
		v38    *uint32
		v39    int32
		v40    *int32
		v41    *uint32
		v42    int32
		v43    int32
		v44    int32
		v45    int32
		v46    int32
		v47    *uint8
		v48    int32
		v49    int32
		v50    int32
		v51    int32
		v52    [2]uint32
		v53    [256]byte
	)
	v1 = int32(*(*uint32)(unsafe.Add(a1, 748)))
	v51 = int32(*(*uint32)(unsafe.Add(a1, 136)))
	if *memmap.PtrUint32(0x5D4594, 2487692) == 0 {
		*memmap.PtrUint32(0x5D4594, 2487692) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("Glyph")))
	}
	v45 = 64
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v45)), 2)
	if int32(int16(v45)) > 64 {
		return 0
	}
	result = nox_xxx_mapReadWriteObjData_4F4530((*server.Object)(a1), int32(int16(v45)))
	if result == 0 {
		return 0
	}
	if nox_crypt_IsReadOnly() == 0 {
		nox_xxx_xferIndexedDirection_509E20(int32(*(*int16)(unsafe.Add(a1, 124))), (*int2)(unsafe.Pointer(&v52[0])))
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v52[0])), 8)
	if int32(int16(v45)) >= 3 {
		v3 = *(**byte)(unsafe.Add(a1, 756))
		if v3 != nil {
			v4 = (*byte)(unsafe.Add(unsafe.Pointer(v3), 640))
		} else {
			v4 = nil
		}
		nox_xxx_xferReadScriptHandler_4F5580(v1+1232, v4)
		if v3 != nil {
			v5 = (*byte)(unsafe.Add(unsafe.Pointer(v3), 896))
		} else {
			v5 = nil
		}
		nox_xxx_xferReadScriptHandler_4F5580(v1+1264, v5)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1220)), 2)
		if v3 != nil {
			v6 = (*byte)(unsafe.Add(unsafe.Pointer(v3), 768))
		} else {
			v6 = nil
		}
		nox_xxx_xferReadScriptHandler_4F5580(v1+1224, v6)
		if int32(int16(v45)) >= 31 {
			if v3 != nil {
				v7 = (*byte)(unsafe.Add(unsafe.Pointer(v3), 1024))
			} else {
				v7 = nil
			}
			nox_xxx_xferReadScriptHandler_4F5580(v1+1240, v7)
			if v3 != nil {
				v8 = (*byte)(unsafe.Add(unsafe.Pointer(v3), 1152))
			} else {
				v8 = nil
			}
			nox_xxx_xferReadScriptHandler_4F5580(v1+1248, v8)
			if v3 != nil {
				v9 = (*byte)(unsafe.Add(unsafe.Pointer(v3), 1280))
			} else {
				v9 = nil
			}
			nox_xxx_xferReadScriptHandler_4F5580(v1+1256, v9)
			if v3 != nil {
				v10 = (*byte)(unsafe.Add(unsafe.Pointer(v3), 1408))
			} else {
				v10 = nil
			}
			nox_xxx_xferReadScriptHandler_4F5580(v1+1272, v10)
			if v3 != nil {
				v11 = (*byte)(unsafe.Add(unsafe.Pointer(v3), 1536))
			} else {
				v11 = nil
			}
			nox_xxx_xferReadScriptHandler_4F5580(v1+1280, v11)
			if v3 != nil {
				v12 = (*byte)(unsafe.Add(unsafe.Pointer(v3), 1664))
			} else {
				v12 = nil
			}
			nox_xxx_xferReadScriptHandler_4F5580(v1+1288, v12)
			if int32(int16(v45)) >= 52 {
				if v3 != nil {
					v13 = (*byte)(unsafe.Add(unsafe.Pointer(v3), 1792))
				} else {
					v13 = nil
				}
				nox_xxx_xferReadScriptHandler_4F5580(v1+1296, v13)
			}
		}
	} else {
		sub_4F5540(v1 + 1232)
		sub_4F5540(v1 + 1264)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1220)), 2)
		sub_4F5540(v1 + 1224)
	}
	v14 = nox_crypt_IsReadOnly()
	if nox_crypt_IsReadOnly() != 1 || (func() bool {
		v15 = int16(nox_xxx_xferDirectionToAngle_509E00(&v52[0]))
		*(*uint16)(unsafe.Add(a1, 126)) = uint16(v15)
		*(*uint16)(unsafe.Add(a1, 124)) = uint16(v15)
		v14 = nox_crypt_IsReadOnly()
		return nox_crypt_IsReadOnly() != 1
	}()) {
		if v14 == 0 {
			v46 = 0
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v46)), 4)
		}
	} else if int32(int16(v45)) >= 11 {
		v46 = 0
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v46)), 4)
	}
	if int32(int16(v45)) >= 31 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1332)), 1)
		if int32(int16(v45)) < 51 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v46)), 2)
			*(*uint32)(unsafe.Add(v1, 1440)) = uint32(uint16(int16(v46)))
		} else {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1440)), 4)
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1352)), 4)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1336)), 4)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1344)), 4)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1312)), 4)
		if int32(int16(v45)) < 33 {
			nox_xxx_cryptSeekCur_40E0A0(2)
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1304)), 4)
		*(*uint32)(unsafe.Add(v1, 1308)) = *(*uint32)(unsafe.Add(v1, 1304))
		if int32(int16(v45)) < 34 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1360)), 4)
		}
		*((*uint8)(unsafe.Pointer(&v48))) = uint8(int8(libc.StrLen((*byte)(unsafe.Add(v1, 1364)))))
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v48)), 1)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1364)), uint32(uint8(int8(v48))))
		*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(int32(uint8(int8(v48)))+v1)), 1364)) = 0
		if int32(int16(v45)) >= 34 {
			if nox_crypt_IsReadOnly() != 0 {
				libc.MemSet(unsafe.Add(v1, 1488), 0, 0x224)
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v44)), 4)
				for i = 0; i < v44; i++ {
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v48)), 1)
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v53[0], uint32(uint8(int8(v48))))
					v53[uint8(int8(v48))] = 0
					v23 = nox_xxx_spellNameToN_4243F0(&v53[0])
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v1+v23*4)), 1488)), 4)
				}
			} else {
				v16 = 0
				v17 = (*uint32)(unsafe.Add(v1, 1488))
				v44 = 0
				v18 = (*uint32)(unsafe.Add(v1, 1488))
				v19 = 137
				for {
					if *v18 != 0 {
						v16++
					}
					v18 = (*uint32)(unsafe.Add(unsafe.Pointer(v18), 4*1))
					v19--
					if v19 == 0 {
						break
					}
				}
				v44 = v16
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v44)), 4)
				v20 = 0
				v47 = (*uint8)(unsafe.Add(v1, 1488))
				for {
					if *v17 != 0 {
						v21 = nox_xxx_spellNameByN_424870(v20)
						*((*uint8)(unsafe.Pointer(&v46))) = uint8(int8(libc.StrLen(v21)))
						nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v46)), 1)
						nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v21, uint32(uint8(int8(v46))))
						nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v47, 4)
					}
					v20++
					v17 = (*uint32)(unsafe.Add(unsafe.Pointer(v47), 4))
					v47 = (*uint8)(unsafe.Add(unsafe.Pointer(v47), 4))
					if v20 >= 137 {
						break
					}
				}
			}
		} else {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1488)), 0x224)
		}
		if int32(int16(v45)) < 46 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v44)), 1)
			*(*uint16)(unsafe.Add(v1, 1448)) = uint16(uint8(int8(v44)))
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v44)), 1)
			*(*uint16)(unsafe.Add(v1, 1450)) = uint16(uint8(int8(v44)))
		} else {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1448)), 2)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1450)), 2)
		}
		if int32(int16(v45)) <= 32 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v49)), 4)
		}
		if int32(int16(v45)) < 46 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v44)), 1)
			*(*uint16)(unsafe.Add(v1, 1456)) = uint16(uint8(int8(v44)))
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v44)), 1)
			*(*uint16)(unsafe.Add(v1, 1458)) = uint16(uint8(int8(v44)))
		} else {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1456)), 2)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1458)), 2)
		}
		if int32(int16(v45)) <= 32 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v49)), 4)
		}
		if int32(int16(v45)) < 46 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v44)), 1)
			*(*uint16)(unsafe.Add(v1, 1464)) = uint16(uint8(int8(v44)))
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v44)), 1)
			*(*uint16)(unsafe.Add(v1, 1466)) = uint16(uint8(int8(v44)))
		} else {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1464)), 2)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1466)), 2)
		}
		if int32(int16(v45)) <= 32 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v49)), 4)
		}
		if int32(int16(v45)) < 46 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v44)), 1)
			*(*uint16)(unsafe.Add(v1, 1472)) = uint16(uint8(int8(v44)))
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v44)), 1)
			*(*uint16)(unsafe.Add(v1, 1474)) = uint16(uint8(int8(v44)))
		} else {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1472)), 2)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1474)), 2)
		}
		if int32(int16(v45)) <= 32 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v49)), 4)
		}
		if int32(int16(v45)) < 46 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v44)), 1)
			*(*uint16)(unsafe.Add(v1, 1480)) = uint16(uint8(int8(v44)))
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v44)), 1)
			*(*uint16)(unsafe.Add(v1, 1482)) = uint16(uint8(int8(v44)))
		} else {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1480)), 2)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1482)), 2)
		}
		if int32(int16(v45)) > 32 || (func() bool {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v49)), 4)
			return int32(int16(v45)) >= 32
		}()) {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1316)), 4)
		}
		if int32(int16(v45)) >= 33 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 2040)), 4)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1320)), 4)
			if int32(int16(v45)) < 42 {
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v44)), 2)
				if int32(uint16(int16(v44))) == 0 {
					*(*uint8)(unsafe.Add(v1, 1445)) = 1
				}
			}
			if int32(int16(v45)) < 53 {
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 2044)), 4)
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 2048)), 4)
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 2052)), 4)
			} else {
				v24 = (*int32)(unsafe.Add(v1, 2044))
				v46 = 3
				for {
					if nox_crypt_IsReadOnly() == 1 {
						nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v44)), 1)
						nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v53[0], uint32(uint8(int8(v44))))
						v53[uint8(int8(v44))] = 0
						*v24 = nox_xxx_spellNameToN_4243F0(&v53[0])
					} else {
						v25 = nox_xxx_spellNameByN_424870(*v24)
						*((*uint8)(unsafe.Pointer(&v44))) = uint8(int8(libc.StrLen(v25)))
						nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v44)), 1)
						nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v25, uint32(uint8(int8(v44))))
					}
					v24 = (*int32)(unsafe.Add(unsafe.Pointer(v24), 4*1))
					v46--
					if v46 == 0 {
						break
					}
				}
			}
		}
		if int32(int16(v45)) >= 34 {
			if nox_crypt_IsReadOnly() != 0 {
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v44)), 1)
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v53[0], uint32(uint8(int8(v44))))
				v53[uint8(int8(v44))] = 0
				*(*uint32)(unsafe.Add(v1, 1360)) = uint32(nox_xxx_actionNByNameMB_5345F0(&v53[0]))
			} else {
				v26 = sub_5345B0(int32(*(*uint32)(unsafe.Add(v1, 1360))))
				*((*uint8)(unsafe.Pointer(&v44))) = uint8(int8(libc.StrLen(v26)))
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v44)), 1)
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v26, uint32(uint8(int8(v44))))
			}
		}
	}
	if int32(int16(v45)) >= 41 {
		result = nox_xxx_XFer_ActionData_529CE0(a1)
		if result == 0 {
			return 0
		}
	}
	if int32(int16(v45)) >= 42 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1445)), 1)
	}
	if int32(int16(v45)) >= 43 && int32(*(*uint8)(unsafe.Add(a1, 12)))&8 != 0 {
		*((*uint8)(unsafe.Pointer(&v44))) = 0
		v27 = int32(*(*uint32)(unsafe.Add(a1, 692)))
		if int32(int16(v45)) >= 50 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v27, 1716)), 4)
		}
		if int32(int16(v45)) >= 61 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v27, 1720)), 4)
		}
		if int32(int16(v45)) >= 48 {
			*((*uint8)(unsafe.Pointer(&v47))) = uint8(int8(libc.StrLen((*byte)(unsafe.Add(v27, 1684)))))
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v47)), 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v27, 1684)), uint32(uint8(uintptr(unsafe.Pointer(v47)))))
			*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(int32(uint8(uintptr(unsafe.Pointer(v47))))+v27)), 1684)) = 0
		}
		if nox_crypt_IsReadOnly() == 1 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v44)), 1)
			if v27 == 0 {
				goto LABEL_137
			}
			*(*uint8)(v27) = uint8(int8(v44))
		} else {
			if v27 != 0 {
				*((*uint8)(unsafe.Pointer(&v44))) = *(*uint8)(v27)
			}
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v44)), 1)
		}
		if v27 != 0 {
			*((*uint8)(unsafe.Pointer(&v44))) = 0
			if int32(*(*uint8)(v27)) != 0 {
				for {
					if nox_crypt_IsReadOnly() == 1 {
						nox_xxx_XFer_ReadShopItem_52A840(unsafe.Add(unsafe.Pointer(uintptr(v27+int32(uint8(int8(v44)))*28)), 4), int32(int16(v45)))
					} else {
						nox_xxx_XFer_WriteShopItem_52A5F0(unsafe.Add(unsafe.Pointer(uintptr(v27+int32(uint8(int8(v44)))*28)), 4))
					}
					*((*uint8)(unsafe.Pointer(&v44))) = uint8(int8(v44 + 1))
					if int32(uint8(int8(v44))) >= int32(*(*uint8)(v27)) {
						break
					}
				}
			}
		}
	}
LABEL_137:
	if int32(int16(v45)) >= 44 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(v1), 4)
	}
	if int32(int16(v45)) >= 45 {
		v50 = int32(*(*uint32)(unsafe.Add(a1, 12)) & 0x180)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v50)), 4)
		*(*uint32)(unsafe.Add(a1, 12)) |= uint32(v50)
	}
	if int32(int16(v45)) >= 49 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl(*(**uint8)(unsafe.Add(a1, 556)), 2)
	}
	if int32(int16(v45)) >= 51 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1348)), 1)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1340)), 1)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1444)), 1)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 2036)), 1)
	}
	if int32(*(*uint8)(unsafe.Add(a1, 12)))&0x20 != 0 && int32(int16(v45)) >= 54 {
		v28 = 0
		v29 = (*uint8)(unsafe.Add(v1, 2076))
		*((*uint8)(unsafe.Pointer(&v46))) = 0
		for {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v29, 3)
			if nox_crypt_IsReadOnly() == 1 {
				nox_xxx_setNPCColor_4E4A90((*server.Object)(a1), uint8(int8(v46)), unsafe.Pointer(v29))
			}
			v28++
			v29 = (*uint8)(unsafe.Add(unsafe.Pointer(v29), 3))
			*((*uint8)(unsafe.Pointer(&v46))) = v28
			if int32(v28) >= 6 {
				break
			}
		}
	}
	if int32(int16(v45)) >= 55 && int32(*(*uint8)(unsafe.Add(a1, 12)))&0x20 != 0 {
		nox_xxx_readNPCVoiceSet_52AD10(a1)
	}
	if int32(int16(v45)) >= 62 && (func() int32 {
		result = nox_xxx_XFer_ReadMonsterBuffs_52AAB0((*uint32)(a1))
		return result
	}()) == 0 {
		return 0
	}
	if int32(int16(v45)) >= 63 && *(*uint32)(unsafe.Add(a1, 12))&0x80000 != 0 {
		nox_xxx_readNPCVoiceSet_52AD10(a1)
	}
	if int32(int16(v45)) >= 64 {
		*((*uint8)(unsafe.Pointer(&v47))) = *(*uint8)(unsafe.Add(a1, 540))
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v47)), 1)
		if nox_crypt_IsReadOnly() != 1 {
			goto LABEL_171
		}
		if int32(uint8(uintptr(unsafe.Pointer(v47)))) == 0 {
			goto LABEL_164
		}
		nox_xxx_setSomePoisonData_4EEA90(a1, int32(uint8(uintptr(unsafe.Pointer(v47)))))
	}
	if nox_crypt_IsReadOnly() != 1 {
		goto LABEL_171
	}
LABEL_164:
	if int32(*(*uint8)(unsafe.Add(v1, 1445))) == 0 {
		v30 = int32(*(*uint32)(unsafe.Add(a1, 16)))
		if (v30&0x8000) != 0 && nox_xxx_unitIsZombie_534A40(a1) == 0 {
			*(*uint32)(unsafe.Add(a1, 16)) |= 0x40
		}
		goto LABEL_171
	}
	if noxflags.HasGame(1) {
		*(*uint16)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 556)), 4)) = 0
		**(**uint16)(unsafe.Add(a1, 556)) = 0
	}
	if nox_crypt_IsReadOnly() == 1 {
		v30 = int32(*(*uint32)(unsafe.Add(a1, 16)))
		if (v30&0x8000) != 0 && nox_xxx_unitIsZombie_534A40(a1) == 0 {
			*(*uint32)(unsafe.Add(a1, 16)) |= 0x40
		}
	}
LABEL_171:
	if *(*uint32)(unsafe.Add(a1, 136)) != 0 {
		if nox_crypt_IsReadOnly() != 1 {
			*(*uint32)(unsafe.Add(a1, 136)) = uint32(v51)
			return 1
		}
		result = nox_xxx_xfer_4F3E30(uint16(int16(v45)), (*server.Object)(a1), int32(*(*uint32)(unsafe.Add(a1, 136))))
		if result == 0 {
			return 0
		}
	}
	if nox_crypt_IsReadOnly() == 1 {
		if noxflags.HasGame(0x200000) || nox_xxx_gameIsSwitchToSolo_4DB240() == 0 {
			nox_xxx_monsterOnSpawnSpellcaster_529BC0(a1)
		}
		if nox_crypt_IsReadOnly() == 1 {
			if int32(*(*uint8)(unsafe.Add(a1, 8)))&2 != 0 {
				v31 = int32(*(*uint32)(unsafe.Add(a1, 12)))
				if v31&0x2000 != 0 {
					v32 = 0
					v33 = 0
					for j = nox_xxx_inventoryGetFirst_4E7980(a1); j != nil; j = nox_xxx_inventoryGetNext_4E7990(j) {
						if uint32(*(*uint16)(unsafe.Add(j, 4))) == *memmap.PtrUint32(0x5D4594, 2487692) {
							v32 = 1
						}
					}
					v35 = v1 + 2044
					v36 = 3
					v37 = (*uint32)(v35)
					for {
						if *v37 != 0 {
							v33++
						}
						v37 = (*uint32)(unsafe.Add(unsafe.Pointer(v37), 4*1))
						v36--
						if v36 == 0 {
							break
						}
					}
					if v32 == 0 && v33 != 0 {
						v38 = (*uint32)(unsafe.Pointer(nox_xxx_newObjectByTypeID_4E3810(internCStr("Glyph"))))
						v46 = int32(uintptr(unsafe.Pointer(v38)))
						if v38 != nil {
							v39 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v38), 4*173)))
							if v33 > 0 {
								v40 = (*int32)(v35)
								v41 = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v38), 4*173)))
								v42 = v33
								for {
									v43 = *v40
									v40 = (*int32)(unsafe.Add(unsafe.Pointer(v40), 4*1))
									*v41 = uint32(v43)
									v41 = (*uint32)(unsafe.Add(unsafe.Pointer(v41), 4*1))
									v42--
									if v42 == 0 {
										break
									}
								}
								v38 = (*uint32)(v46)
							}
							*(*uint8)(unsafe.Add(v39, 20)) = uint8(int8(v33))
							*(*uint32)(unsafe.Add(v39, 24)) = 0
							*(*uint32)(unsafe.Add(v39, 28)) = *(*uint32)(unsafe.Add(a1, 56))
							*(*uint32)(unsafe.Add(v39, 32)) = *(*uint32)(unsafe.Add(a1, 60))
						}
						nox_xxx_inventoryPutImpl_4F3070((*server.Object)(a1), (*server.Object)(unsafe.Pointer(v38)), 1)
					}
				}
			}
		}
	}
	*(*uint32)(unsafe.Add(a1, 136)) = uint32(v51)
	return 1
}
func nox_xxx_monsterOnSpawnSpellcaster_529BC0(a1 unsafe.Pointer) {
	var (
		v1 int32
		v2 *uint32
		i  int32
		v4 int32
		v5 int32
		v6 int32
		v7 int32
	)
	if a1 != nil {
		v1 = int32(*(*uint32)(unsafe.Add(a1, 748)))
		v2 = (*uint32)(unsafe.Pointer(Nox_xxx_monsterDefByTT_517560(int(*(*uint16)(unsafe.Add(a1, 4))))))
		if v2 != nil {
			if int32(*(*uint8)(unsafe.Add(v1, 1445))) == 0 {
				**(**uint16)(unsafe.Add(a1, 556)) = *((*uint16)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(uint16(0))*34)))
				*(*uint16)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 556)), 4)) = *((*uint16)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(uint16(0))*34)))
				*(*uint16)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 556)), 2)) = *((*uint16)(unsafe.Add(unsafe.Pointer(v2), unsafe.Sizeof(uint16(0))*34)))
			}
			if int32(*(*uint8)(unsafe.Add(v1, 1444))) == 1 {
				*(*uint32)(unsafe.Add(v1, 1440)) = *(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*23))
			} else {
				for i = 0; i < 22; i++ {
					v4 = 1 << i
					if (uint32(1<<i) & 0x19C40) == 0 {
						v5 = int32(*(*uint32)(unsafe.Add(v1, 1440)))
						if v5&v4 != 0 && (uint32(v4)&*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*23))) == 0 {
							*(*uint32)(unsafe.Add(v1, 1440)) = uint32(v5 & ^v4)
						}
						v6 = int32(*(*uint32)(unsafe.Add(v1, 1440)))
						if (v6&v4) == 0 && uint32(v4)&*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*23)) != 0 {
							*(*uint32)(unsafe.Add(v1, 1440)) = uint32(v4 | v6)
						}
					}
				}
			}
			v7 = int32(*(*uint32)(unsafe.Add(v1, 1440)))
			if (v7 & 0x20) == 0 {
				*(*uint8)(unsafe.Add(unsafe.Pointer(&v7), 1)) &= 0xE7
				*(*uint32)(unsafe.Add(v1, 1440)) = uint32(v7)
			}
			if int32(*(*uint8)(unsafe.Add(v1, 1340))) == 1 {
				*(*uint32)(unsafe.Add(v1, 1336)) = *(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*20))
			}
			if int32(*(*uint8)(unsafe.Add(v1, 1348))) == 1 {
				*(*uint32)(unsafe.Add(v1, 1344)) = *(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*21))
			}
			if int32(*(*uint8)(unsafe.Add(v1, 2036))) == 1 {
				nox_xxx_monsterAutoSpells_54C0C0((*server.Object)(a1))
			}
		}
	}
}
func nox_xxx_XFer_ActionData_529CE0(a1 unsafe.Pointer) int32 {
	var (
		v1  int32
		v3  int32
		v4  bool
		v5  **uint8
		v6  int32
		v7  bool
		v8  *uint8
		v9  int32
		v10 int32
		v11 int32
		v12 int32
		v13 int32
		v14 int32
		v15 *uint8
		v16 *int32
		v17 int32
		v18 int32
		v19 int8
		v20 int32
		v21 int32
		v22 int32
		v23 int32
		v24 [256]byte
	)
	v1 = int32(*(*uint32)(unsafe.Add(a1, 748)))
	v21 = 4
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v21)), 2)
	if int32(int16(v21)) > 4 {
		return 0
	}
	v19 = 1
	if int32(int16(v21)) < 2 {
		goto LABEL_67
	}
	v19 = 0
	if noxflags.HasGame(1) && !noxflags.HasGame(0x400000) {
		v19 = 1
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v19)), 1)
	if int32(v19) == 0 && int32(uint16(int16(v21))) != 1 {
		return 1
	}
LABEL_67:
	v23 = int32(gameFrame())
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v23)), 4)
	v3 = int32(gameFrame() - uint32(v23))
	v18 = 0
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v18)), 4)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 8)), 4)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 12)), *(*uint32)(unsafe.Add(v1, 8))*8)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 268)), 4)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 272)), 8)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 280)), 4)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 284)), 1)
	if nox_crypt_IsReadOnly() == 1 {
		nox_xxx_AssignIfGreater_52A420((*int32)(unsafe.Add(v1, 280)), v3)
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 296)), 4)
	v4 = *(*int32)(unsafe.Add(v1, 296)) <= 0
	v18 = 0
	if !v4 {
		v5 = (**uint8)(unsafe.Add(v1, 300))
		for {
			if nox_crypt_IsReadOnly() != 0 {
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v22)), 4)
				*v5 = (*uint8)(unsafe.Pointer(sub_579C80(v22)))
			} else {
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl(*v5, 4)
			}
			v5 = (**uint8)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof((*uint8)(nil))*1))
			v4 = func() int32 {
				p := &v18
				*p++
				return *p
			}() < *(*int32)(unsafe.Add(v1, 296))
			if !v4 {
				break
			}
		}
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 364)), 4)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 368)), 8)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 376)), 4)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 380)), 8)
	libc.StrCpy(&v24[0], nox_xxx_getSndName_40AF80(int32(*(*uint32)(unsafe.Add(v1, 388)))))
	*((*uint8)(unsafe.Pointer(&v20))) = uint8(int8(libc.StrLen(&v24[0])))
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v20)), 1)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v24[0], uint32(uint8(int8(v20))))
	v24[uint8(int8(v20))] = 0
	*(*uint32)(unsafe.Add(v1, 388)) = uint32(nox_xxx_utilFindSound_40AF50(&v24[0]))
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 396)), 8)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 404)), 4)
	if nox_crypt_IsReadOnly() == 1 {
		nox_xxx_AssignIfGreater_52A420((*int32)(unsafe.Add(v1, 404)), v3)
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 481)), 1)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 482)), 1)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 483)), 1)
	if int32(int16(v21)) < 3 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v18)), 4)
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 496)), 4)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 500)), 8)
	if nox_crypt_IsReadOnly() == 1 {
		nox_xxx_AssignIfGreater_52A420((*int32)(unsafe.Add(v1, 496)), v3)
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v18)), 4)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 536)), 4)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 540)), 4)
	nox_xxx_AssignIfGreater_52A420((*int32)(unsafe.Add(v1, 536)), v3)
	nox_xxx_AssignIfGreater_52A420((*int32)(unsafe.Add(v1, 540)), v3)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 544)), 1)
	v6 = 0
	if int32(int8(*(*uint8)(unsafe.Add(v1, 544)))) >= 0 {
		v18 = v1 + 552
		for {
			sub_52A440(a1, v18, v3)
			v6++
			v18 += 24
			if v6 > int32(*(*byte)(unsafe.Add(v1, 544))) {
				break
			}
		}
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1129)), 1)
	v7 = int32(*(*uint8)(unsafe.Add(v1, 1129))) == 0
	v18 = 0
	if !v7 {
		v8 = (*uint8)(unsafe.Add(v1, 1132))
		for {
			if nox_crypt_IsReadOnly() != 0 {
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v8, 4)
			} else {
				if *memmap.PtrUint32(0x5D4594, 2487688) == 0 {
					*memmap.PtrUint32(0x5D4594, 2487688) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("NewPlayer")))
				}
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Pointer(v8)), 44)), 4)
			}
			v9 = int32(*(*uint8)(unsafe.Add(v1, 1129)))
			v8 = (*uint8)(unsafe.Add(unsafe.Pointer(v8), 4))
			v18++
			if v18 >= v9 {
				break
			}
		}
	}
	if nox_crypt_IsReadOnly() != 0 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1196)), 4)
	} else {
		v10 = int32(*(*uint32)(unsafe.Add(v1, 1196)))
		if v10 != 0 {
			v22 = int32(*(*uint32)(unsafe.Add(v10, 44)))
		} else {
			v22 = 0
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v22)), 4)
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1204)), 4)
	nox_xxx_AssignIfGreater_52A420((*int32)(unsafe.Add(v1, 1204)), v3)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 2096)), 4)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 2100)), 4)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 2104)), 1)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 2105)), 1)
	*((*uint8)(unsafe.Pointer(&v20))) = uint8(int8(libc.StrLen((*byte)(unsafe.Add(v1, 2106)))))
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v20)), 1)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 2106)), uint32(uint8(int8(v20))))
	*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(int32(uint8(int8(v20)))+v1)), 2106)) = 0
	if int32(int16(v21)) < 4 {
		return 1
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 4)), 4)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 288)), 4)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 292)), 4)
	v11 = int32(uintptr(unsafe.Pointer(nox_server_getObjectFromNetCode_4ECCB0(int32(*(*uint32)(unsafe.Add(v1, 392)))))))
	if v11 != 0 {
		v18 = int32(*(*uint32)(unsafe.Add(v11, 44)))
	} else {
		v18 = 0
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v18)), 4)
	if nox_crypt_IsReadOnly() == 1 {
		*(*uint32)(unsafe.Add(v1, 392)) = uint32(v18)
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 492)), 4)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 508)), 4)
	nox_xxx_AssignIfGreater_52A420((*int32)(unsafe.Add(v1, 508)), v3)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 512)), 4)
	nox_xxx_AssignIfGreater_52A420((*int32)(unsafe.Add(v1, 512)), v3)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 516)), 4)
	nox_xxx_AssignIfGreater_52A420((*int32)(unsafe.Add(v1, 516)), v3)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 520)), 4)
	nox_xxx_AssignIfGreater_52A420((*int32)(unsafe.Add(v1, 520)), v3)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 528)), 4)
	nox_xxx_AssignIfGreater_52A420((*int32)(unsafe.Add(v1, 528)), v3)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 532)), 4)
	nox_xxx_AssignIfGreater_52A420((*int32)(unsafe.Add(v1, 532)), v3)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 524)), 4)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 548)), 4)
	nox_xxx_AssignIfGreater_52A420((*int32)(unsafe.Add(v1, 548)), v3)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1128)), 1)
	v12 = int32(uintptr(unsafe.Pointer(nox_server_getObjectFromNetCode_4ECCB0(int32(*(*uint32)(unsafe.Add(v1, 1200)))))))
	if v12 != 0 {
		v18 = int32(*(*uint32)(unsafe.Add(v12, 44)))
	} else {
		v18 = 0
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v18)), 4)
	if nox_crypt_IsReadOnly() == 1 {
		*(*uint32)(unsafe.Add(v1, 1200)) = uint32(v18)
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1208)), 4)
	nox_xxx_AssignIfGreater_52A420((*int32)(unsafe.Add(v1, 1208)), v3)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1212)), 4)
	nox_xxx_AssignIfGreater_52A420((*int32)(unsafe.Add(v1, 1212)), v3)
	v13 = int32(*(*uint32)(unsafe.Add(v1, 1216)))
	v14 = 0
	if v13 != 0 {
		v18 = int32(*(*uint32)(unsafe.Add(v13, 44)))
	} else {
		v18 = 0
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v18)), 4)
	if nox_crypt_IsReadOnly() == 1 {
		*(*uint32)(unsafe.Add(v1, 1216)) = uint32(v18)
	}
	v15 = (*uint8)(unsafe.Add(v1, 2172))
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 2172)), 1)
	if int32(*(*uint8)(unsafe.Add(v1, 2172))) != 0 {
		v16 = (*int32)(unsafe.Add(v1, 2140))
		for {
			v17 = int32(uintptr(unsafe.Pointer(nox_server_getObjectFromNetCode_4ECCB0(*v16))))
			if v17 != 0 {
				v18 = int32(*(*uint32)(unsafe.Add(v17, 44)))
			} else {
				v18 = 0
			}
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v18)), 4)
			if nox_crypt_IsReadOnly() == 1 {
				*v16 = v18
			}
			v14++
			v16 = (*int32)(unsafe.Add(unsafe.Pointer(v16), 4*1))
			if v14 >= int32(*v15) {
				break
			}
		}
	}
	return 1
}
func nox_xxx_AssignIfGreater_52A420(a1 *int32, a2 int32) int32 {
	var result int32
	result = a2 + *a1
	if result >= 1 {
		*a1 = result
	} else {
		*a1 = 1
	}
	return result
}
func sub_52A440(a1 unsafe.Pointer, a2 int32, a3 int32) int32 {
	var (
		v3     int32
		v4     int32
		v5     *int32
		result int32
		v7     uint32
		v8     int32
		v9     int32
		v10    int32
		v11    [256]byte
	)
	libc.StrCpy(&v11[0], sub_534650(int32(*(*uint32)(a2))))
	*((*uint8)(unsafe.Pointer(&v10))) = uint8(int8(libc.StrLen(&v11[0])))
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v10)), 1)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v11[0], uint32(uint8(int8(v10))))
	v11[uint8(int8(v10))] = 0
	v3 = nox_xxx_actionByName_534670(&v11[0])
	*(*uint32)(a2) = uint32(v3)
	*((*uint8)(unsafe.Pointer(&v8))) = *memmap.PtrUint8(0x587000, uintptr(v3*16)+255604)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v8)), 1)
	v4 = 0
	if int32(uint8(int8(v8))) > 0 {
		v5 = (*int32)(unsafe.Add(a2, 4))
		for {
			result = int32(*memmap.PtrUint32(0x587000, uintptr((uint32(v4)+*(*uint32)(a2)*4))*4+255608))
			switch result {
			case 0:
				v7 = 8
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(v5)), v7)
			case 1:
				if nox_crypt_IsReadOnly() != 0 {
					v7 = 4
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(v5)), v7)
					break
				}
				if *v5 != 0 {
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(uintptr(*v5)), 44)), 4)
				} else {
					v9 = 0
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v9)), 4)
				}
			case 2:
				if nox_crypt_IsReadOnly() != 0 {
					v7 = 4
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(v5)), v7)
					break
				}
				if *v5 != 0 {
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(uintptr(*v5))), 4)
				} else {
					v9 = 0
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v9)), 4)
				}
			case 3, 4, 6:
				v7 = 4
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(v5)), v7)
			case 5:
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(v5)), 4)
				if nox_crypt_IsReadOnly() == 1 {
					nox_xxx_AssignIfGreater_52A420(v5, a3)
				}
			case 7:
				v7 = 1
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(v5)), v7)
			default:
				return result
			}
			v4++
			v5 = (*int32)(unsafe.Add(unsafe.Pointer(v5), 4*2))
			if v4 >= int32(uint8(int8(v8))) {
				return int32(nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(a2, 20)), 4))
			}
		}
	}
	return int32(nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(a2, 20)), 4))
}
func nox_xxx_XFer_ReadMonsterBuffs_52AAB0(a1 *uint32) int32 {
	var (
		v1  int32
		v2  *byte
		v3  int32
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v9  int32
		v10 int32
		v11 int32
		v12 int32
		v13 int32
		v14 int32
		v15 int32
		v16 int32
		v17 [3]int32
		v20 [256]byte
	)
	v13 = 2
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v13)), 2)
	if int32(int16(v13)) > 2 || int32(int16(v13)) <= 0 {
		return 0
	}
	*((*uint8)(unsafe.Pointer(&v16))) = uint8(sub_424CB0(unsafe.Pointer(a1)))
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v16)), 1)
	if nox_crypt_IsReadOnly() != 0 {
		v5 = 0
		if int32(uint8(int8(v16))) == 0 {
			return 1
		}
		for {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v11)), 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v20[0], uint32(uint8(int8(v11))))
			v20[uint8(int8(v11))] = 0
			v6 = nox_xxx_enchantByName_424880(&v20[0])
			if v6 == -1 {
				break
			}
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v15)), 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v14)), 4)
			v7 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*15)))
			v17[1] = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*14)))
			v10 = int32(uint8(int8(v15)))
			v17[0] = int32(uintptr(unsafe.Pointer(a1)))
			v17[2] = v7
			v8 = nox_xxx_getEnchantSpell_424920(v6)
			nox_xxx_spellAccept_4FD400(v8, (*server.Object)(unsafe.Pointer(a1)), (*server.Object)(unsafe.Pointer(a1)), (*server.Object)(unsafe.Pointer(a1)), unsafe.Pointer(&v17[0]), v10)
			*((*uint16)(unsafe.Add(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(uint16(0))*uintptr(v6)), unsafe.Sizeof(uint16(0))*172))) = uint16(int16(v14))
			if v6 == 26 && int32(int16(v13)) >= 2 {
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v12)), 4)
				v9 = sub_4FF2D0(51, unsafe.Pointer(a1))
				if v9 != 0 {
					*(*uint32)(unsafe.Add(v9, 72)) = uint32(v12)
				}
			}
			if func() int32 {
				p := &v5
				*p++
				return *p
			}() >= int32(uint8(int8(v16))) {
				return 1
			}
		}
		return 0
	}
	v1 = sub_424D00()
	if v1 == -1 {
		return 1
	}
	for {
		if nox_xxx_testUnitBuffs_4FF350((*server.Object)(unsafe.Pointer(a1)), server.EnchantID(v1)) != 0 {
			v2 = nox_xxx_getEnchantName_4248F0(v1)
			*((*uint8)(unsafe.Pointer(&v11))) = uint8(int8(libc.StrLen(v2)))
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v11)), 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v2, uint32(uint8(int8(v11))))
			*((*uint8)(unsafe.Pointer(&v15))) = uint8(nox_xxx_buffGetPower_4FF570((*server.Object)(unsafe.Pointer(a1)), server.EnchantID(v1)))
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v15)), 1)
			v14 = nox_xxx_unitGetBuffTimer_4FF550((*server.Object)(unsafe.Pointer(a1)), server.EnchantID(v1))
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v14)), 4)
			if v1 == 26 {
				v3 = sub_4FF2D0(51, unsafe.Pointer(a1))
				if v3 != 0 {
					v12 = int32(*(*uint32)(unsafe.Add(v3, 72)))
				} else {
					v12 = 100
				}
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v12)), 4)
			}
		}
		v1 = sub_424D20(v1)
		if v1 == -1 {
			break
		}
	}
	return 1
}
func nox_xxx_readNPCVoiceSet_52AD10(a1 unsafe.Pointer) {
	var (
		v1 **byte
		v2 **byte
		v4 **byte
		v5 int32
		v6 [256]byte
	)
	if nox_crypt_IsReadOnly() != 0 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v5)), 1)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v6[0], uint32(uint8(int8(v5))))
		v6[uint8(int8(v5))] = 0
		v4 = nox_xxx_getDefaultSoundSet_424350(&v6[0])
		nox_xxx_setNPCVoiceSet_424320(a1, int32(uintptr(unsafe.Pointer(v4))))
	} else {
		v1 = (**byte)(nox_xxx_monsterGetSoundSet_424300((*server.Object)(a1)))
		v2 = v1
		if v1 != nil {
			*((*uint8)(unsafe.Pointer(&v5))) = uint8(int8(libc.StrLen(*v1)))
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v5)), 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(*v2, uint32(uint8(int8(v5))))
		} else {
			*((*uint8)(unsafe.Pointer(&v5))) = 0
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v5)), 1)
		}
	}
}
func nox_xxx_XFerNPC_52ADE0(a1p *server.Object, data unsafe.Pointer) int {
	a1 := a1p.CObj()
	var (
		v1     int32
		v2     *byte
		result int32
		v4     *uint32
		v5     *byte
		v6     *byte
		v7     *byte
		v8     *byte
		v9     *byte
		v10    *byte
		v11    *byte
		v12    *byte
		v13    *byte
		v14    *byte
		v15    int32
		v16    int16
		v17    uint8
		v18    *uint8
		v19    int32
		i      uint8
		v21    int32
		v22    *uint16
		v23    *uint16
		v24    int32
		v25    *uint8
		v26    *uint32
		v27    int32
		v28    *byte
		v29    bool
		j      uint8
		v31    int32
		v32    *int32
		v33    *byte
		v34    *byte
		v35    unsafe.Pointer
		v36    int32
		v37    int32
		v38    int32
		v39    int32
		k      *uint32
		v41    int32
		v42    int32
		v43    int32
		v44    int32
		v45    int32
		v46    uint8
		v47    int32
		v48    int32
		v49    int32
		v50    int32
		v51    int32
		v52    int32
		v53    [3]byte
		v54    int32
		v55    [2]uint32
		v56    [256]byte
		v57    [256]byte
	)
	v1 = int32(*(*uint32)(unsafe.Add(a1, 748)))
	v2 = *(**byte)(unsafe.Add(a1, 756))
	v54 = int32(*(*uint32)(unsafe.Add(a1, 136)))
	v44 = 62
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v44)), 2)
	if int32(int16(v44)) > 62 {
		return 0
	}
	if nox_crypt_IsReadOnly() == 1 {
		v4 = (*uint32)(unsafe.Pointer(Nox_xxx_monsterDefByTT_517560(int(*(*uint16)(unsafe.Add(a1, 4))))))
		*(*uint32)(unsafe.Add(v1, 484)) = uint32(uintptr(unsafe.Pointer(v4)))
		if v4 != nil {
			*(*uint32)(unsafe.Add(v1, 1440)) = *(*uint32)(unsafe.Add(unsafe.Pointer(v4), 4*23))
		}
	}
	result = nox_xxx_mapReadWriteObjData_4F4530((*server.Object)(a1), int32(int16(v44)))
	if result == 0 {
		return 0
	}
	if nox_crypt_IsReadOnly() == 0 {
		nox_xxx_xferIndexedDirection_509E20(int32(*(*int16)(unsafe.Add(a1, 124))), (*int2)(unsafe.Pointer(&v55[0])))
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v55[0])), 8)
	if v2 != nil {
		v5 = (*byte)(unsafe.Add(unsafe.Pointer(v2), 640))
	} else {
		v5 = nil
	}
	nox_xxx_xferReadScriptHandler_4F5580(v1+1232, v5)
	if v2 != nil {
		v6 = (*byte)(unsafe.Add(unsafe.Pointer(v2), 896))
	} else {
		v6 = nil
	}
	nox_xxx_xferReadScriptHandler_4F5580(v1+1264, v6)
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1220)), 2)
	if v2 != nil {
		v7 = (*byte)(unsafe.Add(unsafe.Pointer(v2), 768))
	} else {
		v7 = nil
	}
	nox_xxx_xferReadScriptHandler_4F5580(v1+1224, v7)
	if int32(int16(v44)) >= 32 {
		if v2 != nil {
			v8 = (*byte)(unsafe.Add(unsafe.Pointer(v2), 1024))
		} else {
			v8 = nil
		}
		nox_xxx_xferReadScriptHandler_4F5580(v1+1240, v8)
		if v2 != nil {
			v9 = (*byte)(unsafe.Add(unsafe.Pointer(v2), 1152))
		} else {
			v9 = nil
		}
		nox_xxx_xferReadScriptHandler_4F5580(v1+1248, v9)
		if v2 != nil {
			v10 = (*byte)(unsafe.Add(unsafe.Pointer(v2), 1280))
		} else {
			v10 = nil
		}
		nox_xxx_xferReadScriptHandler_4F5580(v1+1256, v10)
		if v2 != nil {
			v11 = (*byte)(unsafe.Add(unsafe.Pointer(v2), 1408))
		} else {
			v11 = nil
		}
		nox_xxx_xferReadScriptHandler_4F5580(v1+1272, v11)
		if v2 != nil {
			v12 = (*byte)(unsafe.Add(unsafe.Pointer(v2), 1536))
		} else {
			v12 = nil
		}
		nox_xxx_xferReadScriptHandler_4F5580(v1+1280, v12)
		if v2 != nil {
			v13 = (*byte)(unsafe.Add(unsafe.Pointer(v2), 1664))
		} else {
			v13 = nil
		}
		nox_xxx_xferReadScriptHandler_4F5580(v1+1288, v13)
		if int32(int16(v44)) >= 50 {
			if v2 != nil {
				v14 = (*byte)(unsafe.Add(unsafe.Pointer(v2), 1792))
			} else {
				v14 = nil
			}
			nox_xxx_xferReadScriptHandler_4F5580(v1+1296, v14)
		}
	}
	v47 = 0
	v15 = nox_crypt_IsReadOnly()
	if nox_crypt_IsReadOnly() != 1 || (func() bool {
		v16 = int16(nox_xxx_xferDirectionToAngle_509E00(&v55[0]))
		*(*uint16)(unsafe.Add(a1, 126)) = uint16(v16)
		*(*uint16)(unsafe.Add(a1, 124)) = uint16(v16)
		v15 = nox_crypt_IsReadOnly()
		return nox_crypt_IsReadOnly() != 1
	}()) {
		if v15 == 0 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v47)), 4)
		}
	} else {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v47)), 4)
	}
	if nox_crypt_IsReadOnly() == 1 {
		v17 = 0
		*((*uint8)(unsafe.Pointer(&v48))) = 0
		for {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v53[0], 3)
			nox_xxx_setNPCColor_4E4A90((*server.Object)(a1), uint8(int8(v48)), unsafe.Pointer(&v53[0]))
			*((*uint8)(unsafe.Pointer(&v48))) = func() uint8 {
				p := &v17
				*p++
				return *p
			}()
			if int32(v17) >= 6 {
				break
			}
		}
	} else {
		v18 = (*uint8)(unsafe.Add(v1, 2076))
		v19 = 6
		for {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v18, 3)
			v18 = (*uint8)(unsafe.Add(unsafe.Pointer(v18), 3))
			v19--
			if v19 == 0 {
				break
			}
		}
	}
	if nox_crypt_IsReadOnly() == 1 && int32(uint16(int16(v44))) == 31 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v49)), 2)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v46, 1)
		for i = 0; int32(i) < int32(v46); i++ {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v50)), 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v56[0], uint32(uint8(int8(v50))))
			v56[uint8(int8(v50))] = 0
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v43)), 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v43)), 1)
		}
	}
	if int32(int16(v44)) >= 32 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1332)), 1)
		if int32(int16(v44)) < 49 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v47)), 2)
			*(*uint32)(unsafe.Add(v1, 1440)) = uint32(uint16(int16(v47)))
		} else {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1440)), 4)
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1352)), 4)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1336)), 4)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1344)), 4)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1312)), 4)
		v43 = 0
		v22 = *(**uint16)(unsafe.Add(a1, 556))
		if v22 != nil {
			*(*uint16)(unsafe.Add(unsafe.Pointer(&v21), unsafe.Sizeof(uint16(0))*0)) = *v22
			v43 = v21
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v43)), 2)
		v23 = *(**uint16)(unsafe.Add(a1, 556))
		if v23 != nil {
			*v23 = uint16(int16(v43))
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1304)), 4)
		*(*uint32)(unsafe.Add(v1, 1308)) = *(*uint32)(unsafe.Add(v1, 1304))
		if int32(int16(v44)) < 35 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1360)), 4)
		}
		*((*uint8)(unsafe.Pointer(&v49))) = uint8(int8(libc.StrLen((*byte)(unsafe.Add(v1, 1364)))))
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v49)), 1)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1364)), uint32(uint8(int8(v49))))
		*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(int32(uint8(int8(v49)))+v1)), 1364)) = 0
		if int32(int16(v44)) >= 34 {
			if nox_crypt_IsReadOnly() != 0 {
				libc.MemSet(unsafe.Add(v1, 1488), 0, 0x224)
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v43)), 4)
				for j = 0; int32(j) < v43; *((*uint8)(unsafe.Pointer(&v48))) = j {
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v49)), 1)
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v56[0], uint32(uint8(int8(v49))))
					v56[uint8(int8(v49))] = 0
					v31 = nox_xxx_spellNameToN_4243F0(&v56[0])
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v1+v31*4)), 1488)), 4)
					j++
				}
			} else {
				v24 = 0
				v25 = (*uint8)(unsafe.Add(v1, 1488))
				v43 = 0
				v26 = (*uint32)(unsafe.Add(v1, 1488))
				v27 = 137
				for {
					if *v26 != 0 {
						v24++
					}
					v26 = (*uint32)(unsafe.Add(unsafe.Pointer(v26), 4*1))
					v27--
					if v27 == 0 {
						break
					}
				}
				v43 = v24
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v43)), 4)
				v48 = 0
				v47 = 137
				for {
					if *(*uint32)(unsafe.Pointer(v25)) != 0 {
						v28 = nox_xxx_spellNameByN_424870(v48)
						*((*uint8)(unsafe.Pointer(&v52))) = uint8(int8(libc.StrLen(v28)))
						nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v52)), 1)
						nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v28, uint32(uint8(int8(v52))))
						nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v25, 4)
					}
					v25 = (*uint8)(unsafe.Add(unsafe.Pointer(v25), 4))
					v29 = v47 == 1
					v48++
					v47--
					if v29 {
						break
					}
				}
			}
		} else {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1488)), 0x224)
		}
		if int32(int16(v44)) < 47 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v43)), 1)
			*(*uint16)(unsafe.Add(v1, 1448)) = uint16(uint8(int8(v43)))
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v43)), 1)
			*(*uint16)(unsafe.Add(v1, 1450)) = uint16(uint8(int8(v43)))
		} else {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1448)), 2)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1450)), 2)
		}
		if int32(int16(v44)) < 34 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v45)), 4)
		}
		if int32(int16(v44)) < 47 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v43)), 1)
			*(*uint16)(unsafe.Add(v1, 1456)) = uint16(uint8(int8(v43)))
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v43)), 1)
			*(*uint16)(unsafe.Add(v1, 1458)) = uint16(uint8(int8(v43)))
		} else {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1456)), 2)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1458)), 2)
		}
		if int32(int16(v44)) < 34 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v45)), 4)
		}
		if int32(int16(v44)) < 47 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v43)), 1)
			*(*uint16)(unsafe.Add(v1, 1464)) = uint16(uint8(int8(v43)))
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v43)), 1)
			*(*uint16)(unsafe.Add(v1, 1466)) = uint16(uint8(int8(v43)))
		} else {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1464)), 2)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1466)), 2)
		}
		if int32(int16(v44)) < 34 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v45)), 4)
		}
		if int32(int16(v44)) < 47 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v43)), 1)
			*(*uint16)(unsafe.Add(v1, 1472)) = uint16(uint8(int8(v43)))
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v43)), 1)
			*(*uint16)(unsafe.Add(v1, 1474)) = uint16(uint8(int8(v43)))
		} else {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1472)), 2)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1474)), 2)
		}
		if int32(int16(v44)) < 34 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v45)), 4)
		}
		if int32(int16(v44)) < 47 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v43)), 1)
			*(*uint16)(unsafe.Add(v1, 1480)) = uint16(uint8(int8(v43)))
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v43)), 1)
			*(*uint16)(unsafe.Add(v1, 1482)) = uint16(uint8(int8(v43)))
		} else {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1480)), 2)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1482)), 2)
		}
		if int32(int16(v44)) < 34 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v45)), 4)
		}
		if int32(int16(v44)) >= 33 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1316)), 4)
		}
		if int32(int16(v44)) >= 34 {
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 2040)), 4)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1324)), 1)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1328)), 4)
			nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1320)), 4)
			if int32(int16(v44)) < 42 {
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v43)), 2)
				if int32(uint16(int16(v43))) == 0 {
					*(*uint8)(unsafe.Add(v1, 1445)) = 1
				}
			}
			v32 = (*int32)(unsafe.Add(v1, 2044))
			v47 = 3
			for {
				if nox_crypt_IsReadOnly() == 1 {
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v43)), 1)
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v56[0], uint32(uint8(int8(v43))))
					v56[uint8(int8(v43))] = 0
					*v32 = nox_xxx_spellNameToN_4243F0(&v56[0])
				} else {
					v33 = nox_xxx_spellNameByN_424870(*v32)
					*((*uint8)(unsafe.Pointer(&v43))) = uint8(int8(libc.StrLen(v33)))
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v43)), 1)
					nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v33, uint32(uint8(int8(v43))))
				}
				v32 = (*int32)(unsafe.Add(unsafe.Pointer(v32), 4*1))
				v47--
				if v47 == 0 {
					break
				}
			}
		}
		if int32(int16(v44)) >= 35 {
			if nox_crypt_IsReadOnly() != 0 {
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v43)), 1)
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl(&v57[0], uint32(uint8(int8(v43))))
				v57[uint8(int8(v43))] = 0
				*(*uint32)(unsafe.Add(v1, 1360)) = uint32(nox_xxx_actionNByNameMB_5345F0(&v57[0]))
			} else {
				v34 = sub_5345B0(int32(*(*uint32)(unsafe.Add(v1, 1360))))
				*((*uint8)(unsafe.Pointer(&v43))) = uint8(int8(libc.StrLen(v34)))
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v43)), 1)
				nox_xxx_fileReadWrite_426AC0_file3_fread_impl(v34, uint32(uint8(int8(v43))))
			}
		}
	}
	if int32(int16(v44)) < 41 {
		v35 = a1
	} else {
		v35 = a1
		result = nox_xxx_XFer_ActionData_529CE0(a1)
		if result == 0 {
			return 0
		}
	}
	if int32(int16(v44)) >= 42 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v1, 1445)), 1)
	}
	if int32(int16(v44)) >= 44 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(v1), 4)
	}
	if int32(int16(v44)) >= 45 {
		v36 = int32(*(*uint32)(unsafe.Add(v35, 556)))
		v45 = 0
		if v36 != 0 {
			v45 = int32(*(*uint16)(unsafe.Add(v36, 4)))
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v45)), 4)
		v37 = int32(*(*uint32)(unsafe.Add(v35, 556)))
		if v37 != 0 {
			*(*uint16)(unsafe.Add(v37, 4)) = uint16(int16(v45))
		}
	}
	if int32(int16(v44)) >= 46 {
		v51 = int32(*(*uint32)(unsafe.Add(v35, 12)) & 0x180)
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v51)), 4)
		*(*uint32)(unsafe.Add(v35, 12)) |= uint32(v51)
	}
	if int32(int16(v44)) >= 48 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl(*(**uint8)(unsafe.Add(v35, 556)), 2)
	}
	if int32(int16(v44)) >= 51 {
		nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Add(v35, 28)), 4)
	}
	if int32(int16(v44)) >= 52 {
		nox_xxx_readNPCVoiceSet_52AD10(v35)
	}
	if int32(int16(v44)) >= 61 && (func() int32 {
		result = nox_xxx_XFer_ReadMonsterBuffs_52AAB0((*uint32)(v35))
		return result
	}()) == 0 {
		return int(result)
	}
	if int32(int16(v44)) < 62 {
		if nox_crypt_IsReadOnly() == 1 {
			goto LABEL_149
		}
		goto LABEL_156
	}
	*((*uint8)(unsafe.Pointer(&v45))) = *(*uint8)(unsafe.Add(v35, 540))
	nox_xxx_fileReadWrite_426AC0_file3_fread_impl((*uint8)(unsafe.Pointer(&v45)), 1)
	if nox_crypt_IsReadOnly() != 1 {
		goto LABEL_156
	}
	if int32(uint8(int8(v45))) != 0 {
		nox_xxx_setSomePoisonData_4EEA90(v35, int32(uint8(int8(v45))))
		if nox_crypt_IsReadOnly() == 1 {
			goto LABEL_149
		}
		goto LABEL_156
	}
LABEL_149:
	if int32(*(*uint8)(unsafe.Add(v1, 1445))) == 0 {
		goto LABEL_170
	}
	if noxflags.HasGame(1) {
		v38 = int32(*(*uint32)(unsafe.Add(v35, 556)))
		if v38 != 0 {
			*(*uint16)(unsafe.Add(v38, 4)) = 0
			**(**uint16)(unsafe.Add(v35, 556)) = 0
		}
	}
	if nox_crypt_IsReadOnly() != 1 {
		goto LABEL_156
	}
LABEL_170:
	v39 = int32(*(*uint32)(unsafe.Add(v35, 16)))
	if (v39 & 0x8000) != 0 {
		*((*uint8)(unsafe.Pointer(&v39))) = uint8(int8(v39 | 0x40))
		*(*uint32)(unsafe.Add(v35, 16)) = uint32(v39)
	}
LABEL_156:
	if *(*uint32)(unsafe.Add(v35, 136)) == 0 || nox_crypt_IsReadOnly() != 1 || (func() int32 {
		result = nox_xxx_xfer_4F3E30(uint16(int16(v44)), (*server.Object)(v35), int32(*(*uint32)(unsafe.Add(v35, 136))))
		return result
	}()) != 0 {
		sub_52BA70(v35)
		if nox_crypt_IsReadOnly() == 1 {
			if noxflags.HasGame(1) {
				for k = *(**uint32)(unsafe.Add(v35, 504)); k != nil; k = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(k), 4*124))) {
					v41 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(k), 4*4)))
					if v41&0x100 != 0 {
						v42 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(k), 4*2)))
						*(*uint32)(unsafe.Add(unsafe.Pointer(k), 4*4)) &= 0xFFFFFEFF
						if uint32(v42)&0x1001000 != 0 {
							nox_xxx_NPCEquipWeapon_53A2C0(v35, (*server.Object)(unsafe.Pointer(k)))
						} else {
							nox_xxx_NPCEquipArmor_53E520(v35, k)
						}
					}
				}
			}
		}
		*(*uint32)(unsafe.Add(v35, 136)) = uint32(v54)
		return 1
	}
	return int(result)
}
func sub_52BA70(a1 unsafe.Pointer) {
	var (
		v2 int32
		v3 int32
		v4 int32
		v5 int32
	)
	result := a1
	v2 = 0
	v3 = 0
	if a1 != nil {
		for result = *(*unsafe.Pointer)(unsafe.Add(a1, 504)); result != nil; result = *(*unsafe.Pointer)(unsafe.Add(result, 496)) {
			v4 = int32(*(*uint32)(unsafe.Add(result, 16)))
			if v4&0x100 != 0 {
				v5 = int32(*(*uint32)(unsafe.Add(result, 8)))
				if uint32(v5)&0x1001000 != 0 && *(*uint32)(unsafe.Add(result, 12))&0x7FFE40C != 0 {
					if v3 == 1 {
						*(*uint8)(unsafe.Add(unsafe.Pointer(&v4), 1)) &= 0xFE
						*(*uint32)(unsafe.Add(result, 16)) = uint32(v4)
					} else {
						v2 = 1
					}
				} else if uint32(v5)&0x2000000 != 0 && int32(*(*uint8)(unsafe.Add(result, 12)))&2 != 0 {
					if v2 == 1 {
						*(*uint8)(unsafe.Add(unsafe.Pointer(&v4), 1)) &= 0xFE
						*(*uint32)(unsafe.Add(result, 16)) = uint32(v4)
					} else {
						v3 = 1
					}
				}
			}
		}
	}
}
func sub_52BAF0(a1 int32) int32 {
	var (
		v1     int32
		result int32
		v3     *uint32
		v4     int32
		v5     int32
		v6     *int32
		v7     int32
		v8     int32
	)
	v1 = a1
	v8 = 0
	result = int32(*(*uint32)(unsafe.Add(v1, 748)))
	v7 = result
	if int32(*(*uint8)(unsafe.Add(result, 544)))&0x80 != 0 {
		return result
	}
	v3 = (*uint32)(unsafe.Add(result, 552))
	for {
		v4 = 0
		v5 = int32(*memmap.PtrUint32(0x587000, uintptr(*v3)*16+255604))
		if v5 <= 0 {
			goto LABEL_14
		}
		v6 = (*int32)(unsafe.Add(unsafe.Pointer(v3), 4*1))
		for {
			if *memmap.PtrUint32(0x587000, uintptr((uint32(v4)+*v3*4))*4+255608) == 1 {
				if *v6 != 0 {
					*v6 = sub_4ECF10(*v6)
					goto LABEL_12
				}
			} else {
				if *memmap.PtrUint32(0x587000, uintptr((uint32(v4)+*v3*4))*4+255608) != 2 {
					goto LABEL_12
				}
				if *v6 != 0 {
					*v6 = int32(uintptr(unsafe.Pointer(nox_server_getWaypointById_579C40(*v6))))
					goto LABEL_12
				}
			}
			*v6 = 0
		LABEL_12:
			v4++
			v6 = (*int32)(unsafe.Add(unsafe.Pointer(v6), 4*2))
			if v4 >= v5 {
				break
			}
		}
		result = v7
	LABEL_14:
		v3 = (*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*6))
		v8++
		if v8 > int32(*(*byte)(unsafe.Add(result, 544))) {
			break
		}
	}
	return result
}
func nox_xxx_castCounterSpell_52BBB0(a1 int32, a2, a3, a4 unsafe.Pointer) int32 {
	var (
		v4  *types.Pointf
		i   int32
		v6  float64
		v7  float64
		v8  int32
		v10 float32
	)
	v10 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("CounterspellRange")))
	v4 = (*types.Pointf)(unsafe.Add(a4, 56))
	nox_xxx_getMissilesInCircle_518170((*types.Pointf)(unsafe.Add(a4, 56)), v10, func(it *server.Object, data unsafe.Pointer) {
		nox_xxx_cspellRemoveSpell_52BC90(it)
	}, nil)
	for i = int32(uintptr(nox_xxx_spellCastedFirst_4FE930())); i != 0; i = int32(uintptr(nox_xxx_spellCastedNext_4FE940(i))) {
		if nox_xxx_spellHasFlags_424A50(int32(*(*uint32)(unsafe.Add(i, 4))), 0x40000) && ((int32(*(*uint8)(unsafe.Add(i, 88)))&2) == 0 || *(*uint32)(unsafe.Add(i, 4)) == 43) {
			v6 = float64(*(*float32)(unsafe.Add(i, 28)) - v4.X)
			v7 = float64(*(*float32)(unsafe.Add(i, 32)) - *(*float32)(unsafe.Add(a4, 60)))
			if float64(v10*v10) >= v7*v7+v6*v6 {
				nox_xxx_spellCancelSpellDo_4FE9D0(i)
			}
		}
	}
	nox_xxx_unitsGetInCircle_517F90(v4, v10, sub_52BDB0, a4)
	v8 = nox_xxx_spellGetAud44_424800(a1, 0)
	nox_xxx_aud_501960(v8, (*server.Object)(a4), 0, 0)
	return 1
}
func nox_xxx_cspellRemoveSpell_52BC90(it *server.Object) {
	a1 := int32(uintptr(it.CObj()))
	var v1 int32
	if *memmap.PtrUint32(0x5D4594, 2487720) == 0 {
		*memmap.PtrUint32(0x5D4594, 2487720) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("Magic")))
		*memmap.PtrUint32(0x5D4594, 2487724) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("DeathBall")))
	}
	if int32(*(*uint8)(unsafe.Add(a1, 12)))&1 != 0 && (int32(*(*uint8)(unsafe.Add(a1, 16)))&0x20) == 0 {
		nox_xxx_netSendPointFx_522FF0(-121, (*types.Pointf)(unsafe.Add(a1, 56)))
		v1 = int32(*(*uint16)(unsafe.Add(a1, 4)))
		if uint32(uint16(int16(v1))) == *memmap.PtrUint32(0x5D4594, 2487720) {
			nox_xxx_delayedDeleteObject_4E5CC0((*server.Object)(a1))
			return
		}
		if uint32(v1) == *memmap.PtrUint32(0x5D4594, 2487724) {
			nox_xxx_deathBallCreateFragments_52BD30((*int32)(a1))
			nox_xxx_delayedDeleteObject_4E5CC0((*server.Object)(a1))
			return
		}
		ccall.AsFunc[func(int32, uint32, uint32)](*(*unsafe.Pointer)(unsafe.Add(a1, 696)))(a1, 0, 0)
		if (int32(*(*uint8)(unsafe.Add(a1, 16))) & 0x20) == 0 {
			nox_xxx_delayedDeleteObject_4E5CC0((*server.Object)(a1))
			return
		}
	}
}
func nox_xxx_deathBallCreateFragments_52BD30(a1 *int32) int32 {
	var (
		v1     int32
		result int32
		v3     *float32
		v4     int16
	)
	v1 = 3
	for {
		result = int32(uintptr(unsafe.Pointer(nox_xxx_newObjectByTypeID_4E3810(internCStr("DeathBallFragment")))))
		v3 = (*float32)(result)
		if result != 0 {
			nox_xxx_createAt_4DAA50((*server.Object)(result), (*server.Object)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*math.MaxInt8))), *((*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*14))), *((*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*15))))
			v4 = int16(nox_common_randomInt_415FA0(0, math.MaxUint8))
			*((*uint16)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(uint16(0))*62))) = uint16(v4)
			result = int32(v4) * 8
			*(*float32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float32(0))*20)) = *mem_getFloatPtr(0x587000, uint32(result)+194136) * *(*float32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float32(0))*136))
			*(*float32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float32(0))*21)) = *mem_getFloatPtr(0x587000, uint32(result)+194140) * *(*float32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(float32(0))*136))
		}
		v1--
		if v1 == 0 {
			break
		}
	}
	return result
}
func sub_52BDB0(it *server.Object, data unsafe.Pointer) {
	a1 := int32(uintptr(it.CObj()))
	a2 := int32(uintptr(data))
	var (
		result int32
		v3     int32
		i      int32
	)
	result = a2
	v3 = 0
	if a1 != a2 && (*(*uint32)(unsafe.Add(a1, 16))&0x8020) == 0 {
		for i = 0; i < 32; i++ {
			result = nox_xxx_testUnitBuffs_4FF350((*server.Object)(a1), server.EnchantID(i))
			if result != 0 {
				result = nox_xxx_unitGetBuffTimer_4FF550((*server.Object)(a1), server.EnchantID(i))
				if result != 0 {
					result = nox_xxx_getEnchantSpell_424920(i)
					if result != 0 {
						result = bool2int32(nox_xxx_spellHasFlags_424A50(result, 0x40000))
						if result != 0 {
							if v3 == 0 {
								nox_xxx_netSendPointFx_522FF0(-121, (*types.Pointf)(unsafe.Add(a1, 56)))
								v3 = 1
							}
							result = nox_xxx_spellBuffOff_4FF5B0((*server.Object)(a1), i)
						}
					}
				}
			}
		}
	}
}
func nox_xxx_changeOwner_52BE40(a1, a2 unsafe.Pointer) {
	if int32(*(*uint8)(unsafe.Add(a1, 8)))&1 != 0 && int32(*(*uint8)(unsafe.Add(a1, 12)))&2 != 0 {
		v2 := *(**int32)(unsafe.Add(a1, 748))
		if *(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*3)) == 115 {
			nox_xxx_cspellRemoveSpell_52BC90(AsObjectP(a1))
		} else if *(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v2), 4*1)) == a2 {
			*(*int32)(unsafe.Add(unsafe.Pointer(v2), 4*1)) = *v2
			*(*unsafe.Pointer)(unsafe.Pointer(v2)) = a2
			nox_xxx_unitClearOwner_4EC300((*server.Object)(a1))
			nox_xxx_unitSetOwner_4EC290((*server.Object)(a2), (*server.Object)(a1))
			*(*uint32)(unsafe.Add(a1, 128)) = gameFrame()
			nox_xxx_aud_501960(64, (*server.Object)(a2), 0, 0)
		}
	}
}
func sub_52BEB0(a1 int32, a2 int32, a3 unsafe.Pointer, a4 unsafe.Pointer, a5 *server.SpellAcceptArg, a6 int) int32 {
	var (
		v4 int32
		v6 float32
	)
	v6 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("InversionRange")))
	nox_xxx_getMissilesInCircle_518170((*types.Pointf)(unsafe.Add(a4, 56)), v6, func(it *server.Object, data unsafe.Pointer) {
		nox_xxx_changeOwner_52BE40(it.CObj(), data)
	}, (*server.Object)(a3))
	v4 = nox_xxx_spellGetAud44_424800(a1, 0)
	nox_xxx_aud_501960(v4, (*server.Object)(a4), 0, 0)
	return 1
}
func nox_xxx_castSpellWinkORrestoreHealth_52BF20(a1 int32, a2 int32, a3 int32, a4 int32, a5 *int32, a6 int) int32 {
	if p := *(*unsafe.Pointer)(unsafe.Pointer(a5)); p != nil {
		nox_xxx_unitHPsetOnMax_4EE6F0(p)
		nox_xxx_aud_501960(754, (*server.Object)(p), 0, 0)
		return 1
	}
	return 0
}
func sub_52BF50(a1 int32, a2 int32, a3 int32, a4 int32, a5 *int32, a6 int) int32 {
	var result int32
	result = *a5
	if *a5 != 0 {
		if int32(*(*uint8)(unsafe.Add(result, 8)))&4 != 0 {
			nox_xxx_playerManaAdd_4EEB80((*server.Object)(result), int16(*(*uint16)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(result, 748)), 8))))
			nox_xxx_aud_501960(755, (*server.Object)(unsafe.Pointer(uintptr(*a5))), 0, 0)
		}
		result = 1
	}
	return result
}
func nox_xxx_castPull_52BFA0(a1 int32, a2 int32, a3 int32, a4 int32, a5 int32, a6 int32) int32 {
	var (
		v6 int32
		v8 float32
	)
	v8 = float32(-(nox_xxx_gamedataGetFloat_419D40(internCStr("PullPowerCoeff")) * float64(a6)))
	nox_xxx_mapPushUnitsAround_52E040(unsafe.Add(a4, 56), 600.0, 10.0, v8, nil, 0, 0)
	v6 = nox_xxx_spellGetAud44_424800(a1, 0)
	nox_xxx_aud_501960(v6, (*server.Object)(a3), 0, 0)
	return 1
}
func nox_xxx_castPush_52C000(a1 int32, a2 int32, a3 int32, a4 int32, a5 int32, a6 int32) int32 {
	var (
		v6 int32
		v8 float32
	)
	v8 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("PushPowerCoeff")) * float64(a6))
	nox_xxx_mapPushUnitsAround_52E040(unsafe.Add(a4, 56), 600.0, 10.0, v8, nil, 0, 0)
	v6 = nox_xxx_spellGetAud44_424800(a1, 0)
	nox_xxx_aud_501960(v6, (*server.Object)(a3), 0, 0)
	return 1
}
func nox_xxx_castFumble_52C060(a1 int32, a2 int32, a3 int32, a4 int32, a5 *int32, a6 int) int32 {
	var (
		result int32
		v6     int32
		v7     int32
		v8     int32
		v9     int32
		v10    int32
		v11    int32
		v12    int32
		v13    int32
		v14    int32
		v15    int32
	)
	result = *a5
	if *a5 != 0 {
		if *(*uint32)(unsafe.Add(result, 8))&4 != 0 || (func() int32 {
			v6 = int32(*(*uint32)(unsafe.Add(result, 8)) & 2)
			return v6
		}()) != 0 && int32(*(*uint8)(unsafe.Add(result, 12)))&0x10 != 0 {
			v8 = int32(*(*uint32)(unsafe.Add(result, 504)))
			if v8 != 0 {
				for {
					v9 = int32(*(*uint32)(unsafe.Add(v8, 16)))
					v10 = int32(*(*uint32)(unsafe.Add(v8, 496)))
					if v9&0x100 != 0 {
						v11 = int32(*(*uint32)(unsafe.Add(v8, 8)))
						if uint32(v11)&0x1001000 != 0 || uint32(v11)&0x2000000 != 0 && int32(*(*uint8)(unsafe.Add(v8, 12)))&2 != 0 {
							nox_xxx_invForceDropItem_4ED930(*(*unsafe.Pointer)(unsafe.Pointer(a5)), (*uint32)(v8))
						}
					}
					v8 = v10
					if v10 == 0 {
						break
					}
				}
			}
			v12 = int32(*memmap.PtrUint32(0x5D4594, 2487728))
			if *memmap.PtrUint32(0x5D4594, 2487728) == 0 {
				v12 = nox_xxx_getNameId_4E3AA0(internCStr("GameBall"))
				*memmap.PtrUint32(0x5D4594, 2487728) = uint32(v12)
			}
			v13 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*a5)), 516)))
			if v13 != 0 {
				for int32(*(*uint16)(unsafe.Add(v13, 4))) != v12 {
					v13 = int32(*(*uint32)(unsafe.Add(v13, 512)))
					if v13 == 0 {
						goto LABEL_22
					}
				}
				nox_xxx_objectApplyForce_52DF80((*float32)(unsafe.Add(unsafe.Pointer(uintptr(*a5)), 56)), (*server.Object)(v13), 100.0)
				nox_xxx_unitClearOwner_4EC300((*server.Object)(v13))
				nox_xxx_aud_501960(926, (*server.Object)(unsafe.Pointer(uintptr(*a5))), 0, 0)
			}
		} else if v6 == 0 || (func() bool {
			v7 = int32(*(*uint32)(unsafe.Add(result, 12)))
			return (v7 & 0x2000) == 0
		}()) {
			nox_xxx_dropAllItems_4EDA40((*uint32)(result))
			nox_xxx_objectApplyForce_52DF80((*float32)(unsafe.Add(a4, 56)), (*server.Object)(unsafe.Pointer(uintptr(*a5))), 50.0)
		}
	LABEL_22:
		v15 = *a5
		v14 = nox_xxx_spellGetAud44_424800(a1, 1)
		nox_xxx_aud_501960(v14, (*server.Object)(v15), 0, 0)
		result = 1
	}
	return result
}
func nox_xxx_castConfuse_52C1E0(a1 int32, a2 int32, a3 int32, a4 int32, a5 *int32, a6 int8) int32 {
	var (
		v7 int16
		v8 float32
	)
	if *a5 == 0 {
		return 0
	}
	v8 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("ConfuseEnchantDuration")))
	v7 = int16(int32(v8))
	nox_xxx_buffApplyTo_4FF380((*server.Object)(unsafe.Pointer(uintptr(*a5))), 3, v7, a6)
	sub_4E7540((*server.Object)(a3), (*server.Object)(unsafe.Pointer(uintptr(*a5))))
	return 1
}
func nox_xxx_castStun_52C2C0(a1 int32, a2 int32, a3 int32, a4 int32, a5 *int32, a6 int8) int32 {
	var (
		v7  int16
		v8  int32
		v9  int16
		v10 int32
		v11 float32
	)
	if *a5 == 0 {
		return 0
	}
	v11 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("StunEnchantDuration")))
	v7 = int16(int32(v11))
	v8 = *a5
	v9 = v7
	v10 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*a5)), 8)))
	if (v10 & 4) == 0 {
		if v10&2 != 0 && float64(*(*float32)(unsafe.Add(v8, 120))) > 15.0 {
			nox_xxx_buffApplyTo_4FF380((*server.Object)(v8), 4, v9, a6)
			sub_4E7540((*server.Object)(a3), (*server.Object)(unsafe.Pointer(uintptr(*a5))))
			return 1
		}
		nox_xxx_buffApplyTo_4FF380((*server.Object)(v8), 5, v9, a6)
		sub_4E7540((*server.Object)(a3), (*server.Object)(unsafe.Pointer(uintptr(*a5))))
		return 1
	}
	if int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v8, 748)), 276)), 2251))) != 0 {
		nox_xxx_buffApplyTo_4FF380((*server.Object)(v8), 5, v9, a6)
		sub_4E7540((*server.Object)(a3), (*server.Object)(unsafe.Pointer(uintptr(*a5))))
		return 1
	}
	nox_xxx_buffApplyTo_4FF380((*server.Object)(v8), 4, v9, a6)
	sub_4E7540((*server.Object)(a3), (*server.Object)(unsafe.Pointer(uintptr(*a5))))
	return 1
}
func nox_xxx_castBurn_52C3E0(a1 int32, a2 int32, a3 int32, a4 int32, a5 int32, a6 int) int32 {
	var (
		v5  int32
		v6  int32
		v7  *float32
		v8  float32
		v9  float32
		v10 float32
		v11 int32
		v13 int32
		v14 *float32
		v15 int32
		v16 int32
		v17 float32
		v18 float4
	)
	v5 = int32(dword_5d4594_2487712)
	if dword_5d4594_2487712 == 0 {
		v5 = nox_xxx_getNameId_4E3AA0(internCStr("Glyph"))
		dword_5d4594_2487712 = uint32(v5)
	}
	v6 = a5
	if a5 == 0 || a4 == 0 {
		return 0
	}
	if int32(*(*uint16)(unsafe.Add(a4, 4))) != v5 {
		v8 = *(*float32)(unsafe.Add(a4, 56))
		v9 = *(*float32)(unsafe.Add(a5, 4))
		v18.field_4 = *(*float32)(unsafe.Add(a4, 60))
		v18.field_0 = v8
		v10 = *(*float32)(unsafe.Add(a5, 8))
		v18.field_8 = v9
		v18.field_C = v10
		if int32(uint8(int8(nox_xxx_traceRay_5374B0(&v18)))) != 0 {
			v7 = (*float32)(unsafe.Add(v6, 4))
			goto LABEL_12
		}
		if int32(*(*uint8)(unsafe.Add(a4, 8)))&4 != 0 {
			v11 = int32(*(*uint32)(unsafe.Add(a4, 748)))
			a5 = 2
			nox_xxx_netInformTextMsg_4DA0F0(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v11, 276)), 2064))), 0, &a5)
		}
		return 0
	}
	v7 = (*float32)(unsafe.Add(a4, 56))
LABEL_12:
	v13 = int32(*memmap.PtrUint32(0x5D4594, 2487732))
	if *memmap.PtrUint32(0x5D4594, 2487732) == 0 {
		v13 = nox_xxx_getNameId_4E3AA0(internCStr("MediumFlame"))
		*memmap.PtrUint32(0x5D4594, 2487732) = uint32(v13)
	}
	v14 = (*float32)(unsafe.Pointer(nox_xxx_newObjectWithTypeInd_4E3450(v13)))
	if v14 != nil {
		nox_xxx_createAt_4DAA50((*server.Object)(unsafe.Pointer(v14)), (*server.Object)(a4), *v7, *(*float32)(unsafe.Add(unsafe.Pointer(v7), unsafe.Sizeof(float32(0))*1)))
		v17 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("BurnDuration")))
		v15 = int32(v17)
		nox_xxx_unitSetDecayTime_511660((*server.Object)(unsafe.Pointer(v14)), v15)
		nox_xxx_netSparkExplosionFx_5231B0((*float32)(unsafe.Add(unsafe.Pointer(v14), unsafe.Sizeof(float32(0))*14)), 64)
	}
	v16 = nox_xxx_spellGetAud44_424800(a1, 0)
	nox_xxx_audCreate_501A30(v16, (*types.Pointf)(unsafe.Add(v6, 4)), 0, 0)
	return 1
}
func nox_xxx_useShock_52C5A0(a1 int32, a2 int32, a3 int32, a4 int32, a5 *int32, a6 int32) int32 {
	var (
		result int32
		v7     int32
		v8     int32
		v9     int16
		v10    float32
		v11    float32
	)
	if *a5 == 0 {
		return 0
	}
	v7 = int32(dword_5d4594_2487712)
	if dword_5d4594_2487712 == 0 {
		v7 = nox_xxx_getNameId_4E3AA0(internCStr("Glyph"))
		dword_5d4594_2487712 = uint32(v7)
	}
	if a4 != 0 && int32(*(*uint16)(unsafe.Add(a4, 4))) == v7 {
		v10 = float32(nox_xxx_gamedataGetFloatTable_419D70(internCStr("ShockTrapDamage"), a6-1))
		v8 = int32(v10)
		ccall.AsFunc[func(int32, int32, int32, int32, int32)](*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(uintptr(*a5)), 716)))(*a5, a3, a3, v8, 9)
		result = 1
	} else {
		v11 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("ShockEnchantDuration")))
		v9 = int16(int32(v11))
		nox_xxx_buffApplyTo_4FF380((*server.Object)(unsafe.Pointer(uintptr(*a5))), 22, v9, int8(a6))
		result = 1
	}
	return result
}
func nox_xxx_castPoison_52C720(a1 int32, a2 int32, a3 int32, a4 int32, a5 *int32, a6 int32) int32 {
	result := *(*unsafe.Pointer)(unsafe.Pointer(a5))
	if result != nil {
		nox_xxx_activatePoison_4EE7E0(result, a6, a6)
		sub_4E7540((*server.Object)(a3), (*server.Object)(unsafe.Pointer(uintptr(*a5))))
		return 1
	}
	return 0
}
func nox_xxx_castFireball_52C790(a1 int32, a2 int32, a3 int32, a4 int32, a5 int32, a6 int32) int32 {
	var (
		v6  int32
		v7  *float32
		v8  int32
		v9  float64
		v10 int32
		v11 float32
		v12 float64
		v13 float64
		v14 float64
		v15 float64
		v16 int16
		v17 int32
		v19 float4
		v20 float32
		v21 float32
		v22 float32
	)
	v6 = a6
	v7 = (*float32)(unsafe.Pointer(nox_xxx_newObjectByTypeID_4E3810(*(**byte)(memmap.PtrOff(0x587000, uintptr(a6*4)+258864)))))
	if v7 == nil {
		return 1
	}
	v8 = a4
	v9 = float64(*(*float32)(unsafe.Add(a4, 176)) + *(*float32)(unsafe.Add(a4, 176)))
	v10 = int32(*(*int16)(unsafe.Add(a4, 124))) * 8
	v21 = *mem_getFloatPtr(0x587000, uint32(v10)+194136)
	v20 = *mem_getFloatPtr(0x587000, uint32(v10)+194140)
	v11 = *(*float32)(unsafe.Add(v8, 60))
	v19.field_0 = *(*float32)(unsafe.Add(v8, 56))
	v12 = v9*float64(v21) + float64(*(*float32)(unsafe.Add(v8, 56)))
	v19.field_4 = v11
	v19.field_8 = float32(v12)
	v13 = v9*float64(v20) + float64(*(*float32)(unsafe.Add(v8, 60)))
	v19.field_8 = v19.field_8 + *(*float32)(unsafe.Add(v8, 80))
	v19.field_C = float32(v13 + float64(*(*float32)(unsafe.Add(v8, 84))))
	if nox_xxx_mapTraceRay_535250(&v19, nil, nil, 5) == 0 {
		v19.field_8 = v19.field_0
		v19.field_C = v19.field_4
	}
	nox_xxx_createAt_4DAA50((*server.Object)(unsafe.Pointer(v7)), (*server.Object)(v8), v19.field_8, v19.field_C)
	v14 = nox_xxx_gamedataGetFloatTable_419D70(internCStr("FireballSpeedCoeff"), v6-1) * float64(*(*float32)(unsafe.Add(unsafe.Pointer(v7), unsafe.Sizeof(float32(0))*136)))
	*(*float32)(unsafe.Add(unsafe.Pointer(v7), unsafe.Sizeof(float32(0))*136)) = float32(v14)
	v22 = float32(v14 * float64(v21))
	*(*float32)(unsafe.Add(unsafe.Pointer(v7), unsafe.Sizeof(float32(0))*20)) = v22
	v15 = v14 * float64(v20)
	*(*float32)(unsafe.Add(unsafe.Pointer(v7), unsafe.Sizeof(float32(0))*21)) = float32(v15)
	*(*float32)(unsafe.Add(unsafe.Pointer(v7), unsafe.Sizeof(float32(0))*20)) = v22 + *(*float32)(unsafe.Add(v8, 80))
	*(*float32)(unsafe.Add(unsafe.Pointer(v7), unsafe.Sizeof(float32(0))*21)) = float32(v15 + float64(*(*float32)(unsafe.Add(v8, 84))))
	v16 = int16(*(*uint16)(unsafe.Add(v8, 124)))
	*((*uint16)(unsafe.Add(unsafe.Pointer(v7), unsafe.Sizeof(uint16(0))*62))) = *(*uint16)(unsafe.Add(v8, 124))
	*((*uint16)(unsafe.Add(unsafe.Pointer(v7), unsafe.Sizeof(uint16(0))*63))) = uint16(v16)
	v17 = nox_xxx_spellGetAud44_424800(a1, 0)
	nox_xxx_aud_501960(v17, (*server.Object)(v8), 0, 0)
	return 1
}
func sub_52CA80(a1 int32, a2 int32, a3 int32, a4 int32, a5 *server.SpellAcceptArg, a6 int) int32 {
	var (
		v4  int32
		v5  int32
		v6  *types.Pointf
		v7  int32
		v8  int32
		v9  int32
		v10 *uint32
		v11 uint32
		i   int32
		v13 int32
		v14 *uint32
		v15 int32
		v17 [4]*byte
	)
	v4 = int32(dword_5d4594_2487712)
	if dword_5d4594_2487712 == 0 {
		v4 = nox_xxx_getNameId_4E3AA0(internCStr("Glyph"))
		dword_5d4594_2487712 = uint32(v4)
	}
	if a4 != 0 && int32(*(*uint16)(unsafe.Add(a4, 4))) == v4 {
		v5 = a3
		v6 = (*types.Pointf)(unsafe.Add(a4, 56))
	} else {
		v5 = a3
		v6 = (*types.Pointf)(unsafe.Add(a3, 56))
	}
	if int32(*(*uint8)(unsafe.Add(v5, 8)))&4 != 0 {
		v7 = int32(*(*uint32)(unsafe.Add(v5, 748)))
		v8 = 0
		v9 = v7 + 116
		v10 = (*uint32)(unsafe.Add(v7, 116))
		for {
			if *v10 == 0 {
				break
			}
			v8++
			v10 = (*uint32)(unsafe.Add(unsafe.Pointer(v10), 4*1))
			if v8 >= 4 {
				break
			}
		}
		if v8 == 4 {
			v11 = gameFrame()
			v8 = a3
			for i = 0; i < 4; i++ {
				if *(*uint32)(unsafe.Add(*(*unsafe.Pointer)(v9), 136)) < v11 {
					v11 = *(*uint32)(unsafe.Add(*(*unsafe.Pointer)(v9), 136))
					v8 = i
				}
				v9 += 4
			}
		}
		v13 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v7+v8*4)), 116)))
		if v13 != 0 {
			nox_xxx_unitMove_4E7010((*server.Object)(v13), v6)
			*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(uintptr(v7+v8*4)), 116)), 136)) = gameFrame()
		} else {
			v17[0] = internCStr("TeleportGlyph1")
			v17[1] = internCStr("TeleportGlyph2")
			v17[2] = internCStr("TeleportGlyph3")
			v17[3] = internCStr("TeleportGlyph4")
			v14 = (*uint32)(unsafe.Pointer(nox_xxx_newObjectByTypeID_4E3810(v17[v8])))
			*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v7+v8*4)), 116)) = uint32(uintptr(unsafe.Pointer(v14)))
			if v14 == nil {
				v15 = nox_xxx_spellGetAud44_424800(a1, 0)
				nox_xxx_aud_501960(v15, (*server.Object)(a3), 0, 0)
				return 1
			}
			nox_xxx_createAt_4DAA50((*server.Object)(unsafe.Pointer(v14)), (*server.Object)(a3), v6.X, v6.Y)
		}
		*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v8+v7)), 156)) = 3
		v15 = nox_xxx_spellGetAud44_424800(a1, 0)
		nox_xxx_aud_501960(v15, (*server.Object)(a3), 0, 0)
		return 1
	}
	return 1
}
func sub_52CBD0(a1 int32, a2 int32, a3 int32, a4 int32, a5 *server.SpellAcceptArg, a6 int) int32 {
	var (
		v4  int32
		v5  int32
		v6  int32
		v7  int32
		v8  *uint32
		v9  float32
		v10 float32
		v11 int32
		v14 int32
		v15 int32
		v16 int32
		v17 [4]*byte
	)
	v4 = int32(dword_5d4594_2487712)
	if dword_5d4594_2487712 == 0 {
		v4 = nox_xxx_getNameId_4E3AA0(internCStr("Glyph"))
		dword_5d4594_2487712 = uint32(v4)
	}
	if a4 == 0 || (func() bool {
		v5 = a4 + 56
		return int32(*(*uint16)(unsafe.Add(a4, 4))) != v4
	}()) {
		v5 = a3 + 56
	}
	if int32(*(*uint8)(unsafe.Add(a3, 8)))&4 != 0 {
		v6 = int32(*(*uint32)(unsafe.Add(a3, 748)))
		v7 = int32(*(*uint32)(unsafe.Pointer(uintptr(v6 + a1*4 - 68))))
		if v7 != 0 {
			nox_xxx_unitMove_4E7010((*server.Object)(v7), (*types.Pointf)(v5))
			*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Pointer(uintptr(v6 + a1*4 - 68))), 136)) = gameFrame()
		} else {
			v17[0] = internCStr("TeleportGlyph1")
			v17[1] = internCStr("TeleportGlyph2")
			v17[2] = internCStr("TeleportGlyph3")
			v17[3] = internCStr("TeleportGlyph4")
			v8 = (*uint32)(unsafe.Pointer(nox_xxx_newObjectByTypeID_4E3810(v17[a1-46])))
			*(*uint32)(unsafe.Pointer(uintptr(v6 + a1*4 - 68))) = uint32(uintptr(unsafe.Pointer(v8)))
			if v8 == nil {
				v16 = 0
				v15 = 0
				v14 = a3
				v11 = nox_xxx_spellGetAud44_424800(a1, 0)
				nox_xxx_aud_501960(v11, (*server.Object)(v14), v15, v16)
				return 1
			}
			v9 = *(*float32)(unsafe.Add(v5, 4))
			v10 = *(*float32)(v5)
			v16 = 0
			nox_xxx_createAt_4DAA50((*server.Object)(unsafe.Pointer(v8)), (*server.Object)(a3), v10, v9)
		}
		*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a1+v6)), 110)) = 3
		v16 = 0
		v15 = 0
		v14 = a3
		v11 = nox_xxx_spellGetAud44_424800(a1, 0)
		nox_xxx_aud_501960(v11, (*server.Object)(v14), v15, v16)
		return 1
	}
	return 1
}
func sub_52CCD0(a1 int32, a2 int32, a3 int32, a4 *server.Object, a5 *server.SpellAcceptArg, a6 int) int32 {
	var (
		v3 int32
		v4 float64
		v5 float64
		v6 float64
		v7 int32
		v9 float32
		Tm *libc.TimeInfo
	)
	Tm = nil
	v9 = 1e+08
	v3 = int32(uintptr(unsafe.Pointer(nox_server_getFirstObject_4DA790())))
	if v3 == 0 {
		return 0
	}
	for {
		if nox_xxx_unitHasThatParent_4EC4F0((*server.Object)(v3), (*server.Object)(a3)) != 0 && libc.StrCmp(nox_xxx_getUnitName_4E39D0((*server.Object)(v3)), internCStr("Glyph")) == 0 {
			v4 = float64(*(*float32)(unsafe.Add(a3, 56)) - *(*float32)(unsafe.Add(v3, 56)))
			v5 = float64(*(*float32)(unsafe.Add(a3, 60)) - *(*float32)(unsafe.Add(v3, 60)))
			v6 = v5*v5 + v4*v4
			if v6 < float64(v9) {
				v9 = float32(v6)
				Tm = (*libc.TimeInfo)(v3)
			}
		}
		v3 = int32(uintptr(unsafe.Pointer(nox_server_getNextObject_4DA7A0((*server.Object)(v3)))))
		if v3 == 0 {
			break
		}
	}
	if Tm == nil {
		return 0
	}
	v7 = nox_xxx_spellGetAud44_424800(a1, 0)
	nox_xxx_aud_501960(v7, (*server.Object)(a3), 0, 0)
	nox_xxx_dieGlyph_54DF30((*server.Object)(unsafe.Pointer(Tm)))
	return 1
}
func nox_xxx_castCurePoison_52CDB0(a1 int32, a2 int32, a3 int32, a4 int32, a5 *int32, a6 int32) int32 {
	var (
		result int32
		v7     int32
		v8     int16
		v9     int32
	)
	result = *a5
	if *a5 != 0 {
		if int32(*(*uint8)(unsafe.Add(result, 540))) != 0 {
			if int32(*(*uint8)(unsafe.Add(result, 540))) > a6 {
				nox_xxx_updatePoison_4EE8F0((*server.Object)(result), a6)
				nox_xxx_netPriMsgToPlayer_4DA2C0((*server.Object)(unsafe.Pointer(uintptr(*a5))), internCStr("ExecSpel.c:PoisonCure"), 0)
			} else {
				nox_xxx_removePoison_4EE9D0(*(*unsafe.Pointer)(unsafe.Pointer(a5)))
				nox_xxx_netPriMsgToPlayer_4DA2C0((*server.Object)(unsafe.Pointer(uintptr(*a5))), internCStr("ExecSpel.c:PoisonClean"), 0)
			}
			v9 = *a5
			v7 = nox_xxx_spellGetAud44_424800(a1, 1)
			nox_xxx_aud_501960(v7, (*server.Object)(v9), 0, 0)
			return 1
		}
		if result != a2 {
			v9 = *a5
			v7 = nox_xxx_spellGetAud44_424800(a1, 1)
			nox_xxx_aud_501960(v7, (*server.Object)(v9), 0, 0)
			return 1
		}
		v8 = int16(nox_xxx_spellManaCost_4249A0(a1, 1))
		sub_4FD030(*a5, v8)
		result = 1
	}
	return result
}
func sub_52CE60(it *server.Object, data unsafe.Pointer) {
	a1 := int32(uintptr(it.CObj()))
	if int32(*(*uint8)(unsafe.Add(a1, 8)))&0x80 != 0 {
		*(*uint32)(unsafe.Add(a1, 508)) = *memmap.PtrUint32(0x5D4594, 2487716)
		*(*uint32)(unsafe.Add(a1, 136)) = gameFrame() + gameFPS()*60
	}
}
func nox_xxx_castLock_52CE90(a1 int32, a2 int32, a3 int32, a4 int32, a5 *server.SpellAcceptArg, a6 int) int32 {
	var (
		v5 int32
		v7 int32
		v8 int32
		v9 float4
	)
	v9.field_0 = float32(float64(*(*float32)(unsafe.Add(a3, 56))) - 150.0)
	v9.field_4 = float32(float64(*(*float32)(unsafe.Add(a3, 60))) - 150.0)
	v9.field_8 = float32(float64(*(*float32)(unsafe.Add(a3, 56))) + 150.0)
	v9.field_C = float32(float64(*(*float32)(unsafe.Add(a3, 60))) + 150.0)
	dword_5d4594_2487708 = 0
	*memmap.PtrUint32(0x5D4594, 2487704) = 1287568416
	nox_xxx_getUnitsInRect_517C10(&v9, sub_52CF90, a4)
	if dword_5d4594_2487708 == 0 {
		return 0
	}
	v5 = int32(*(*uint32)(unsafe.Add(dword_5d4594_2487708, 508)))
	if v5 != 0 && v5 != a3 {
		nox_xxx_netPriMsgToPlayer_4DA2C0((*server.Object)(a3), internCStr("ExecSpel.c:DoorAlreadyLocked"), 0)
		return 0
	}
	*(*uint32)(unsafe.Add(dword_5d4594_2487708, 508)) = uint32(a3)
	*(*uint32)(unsafe.Add(dword_5d4594_2487708, 136)) = gameFrame() + gameFPS()*60
	sub_52D060(dword_5d4594_2487708, a3)
	v8 = int32(dword_5d4594_2487708)
	v7 = nox_xxx_spellGetAud44_424800(a1, 0)
	nox_xxx_aud_501960(v7, (*server.Object)(v8), 0, 0)
	return 1
}
func sub_52CF90(it *server.Object, data unsafe.Pointer) {
	a1 := int32(uintptr(it.CObj()))
	a2 := int32(uintptr(data))
	var (
		v2 int32
		v3 float64
		v4 float64
		v5 int32
		v6 float32
		v7 float4
		v8 float32
	)
	v2 = a1
	if int32(*(*uint8)(unsafe.Add(a1, 8)))&0x80 != 0 {
		v3 = float64(*(*float32)(unsafe.Add(a2, 56)) - *(*float32)(unsafe.Add(a1, 56)))
		v4 = float64(*(*float32)(unsafe.Add(a2, 60)) - *(*float32)(unsafe.Add(a1, 60)))
		v8 = float32(v4*v4 + v3*v3)
		if float64(v8) <= 22500.0 && float64(v8) < float64(*mem_getFloatPtr(0x5D4594, 2487704)) {
			v5 = int32(*(*uint32)(unsafe.Add(v2, 748)))
			v6 = *(*float32)(unsafe.Add(a2, 60))
			v7.field_0 = *(*float32)(unsafe.Add(a2, 56))
			v7.field_4 = v6
			v7.field_8 = float32(float64(*memmap.PtrInt32(0x587000, uintptr(*(*uint32)(unsafe.Add(v5, 12)))*8+196184))*0.5 + float64(*(*float32)(unsafe.Add(v2, 56))))
			v7.field_C = float32(float64(*memmap.PtrInt32(0x587000, uintptr(*(*uint32)(unsafe.Add(v5, 12)))*8+196188))*0.5 + float64(*(*float32)(unsafe.Add(v2, 60))))
			if nox_xxx_mapTraceRay_535250(&v7, nil, nil, 0) != 0 {
				dword_5d4594_2487708 = uint32(v2)
				*mem_getFloatPtr(0x5D4594, 2487704) = float32(v4*v4 + v3*v3)
			}
		}
	}
}
func sub_52D060(a1 int32, a2 int32) {
	var (
		v2 int32
		v3 int32
		v5 float4
	)
	v2 = int32(*(*uint32)(unsafe.Add(a1, 748)))
	v5.field_0 = float32(float64(int32(*(*uint32)(unsafe.Add(v2, 16))*23)) - 34.0)
	v5.field_4 = float32(float64(int32(*(*uint32)(unsafe.Add(v2, 20))*23)) - 34.0)
	v5.field_8 = float32(float64(int32(*(*uint32)(unsafe.Add(v2, 16))*23)) + 34.0)
	v3 = int32(*(*uint32)(unsafe.Add(v2, 20)))
	*memmap.PtrUint32(0x5D4594, 2487716) = uint32(a2)
	v5.field_C = float32(float64(v3*23) + 34.0)
	nox_xxx_getUnitsInRect_517C10(&v5, sub_52CE60, nil)
	*memmap.PtrUint32(0x5D4594, 2487716) = 0
}
func nox_xxx_castTelekinesis_52D330(a1 int32, a2 int32, a3 int32, a4 int32, a5 *int32, a6 int8) int32 {
	var (
		result int32
		v7     *uint32
		v8     int32
		v9     int32
	)
	result = *a5
	if *a5 != 0 {
		if int32(*(*uint8)(unsafe.Add(result, 8)))&4 != 0 {
			v7 = (*uint32)(unsafe.Pointer(nox_xxx_newObjectByTypeID_4E3810(internCStr("TelekinesisHand"))))
			if v7 != nil {
				nox_xxx_createAt_4DAA50((*server.Object)(unsafe.Pointer(v7)), (*server.Object)(unsafe.Pointer(uintptr(*a5))), *(*float32)(unsafe.Add(unsafe.Pointer(uintptr(*a5)), 56)), *(*float32)(unsafe.Add(unsafe.Pointer(uintptr(*a5)), 60)))
				nox_xxx_buffApplyTo_4FF380((*server.Object)(unsafe.Pointer(uintptr(*a5))), 24, int16(int32(uint16(gameFPS()))*20), a6)
				nox_xxx_spellCancelDurSpell_4FEB10(24, (*server.Object)(unsafe.Pointer(uintptr(*a5))))
				nox_xxx_spellCancelDurSpell_4FEB10(43, (*server.Object)(unsafe.Pointer(uintptr(*a5))))
				v9 = *a5
				v8 = nox_xxx_spellGetAud44_424800(a1, 1)
				nox_xxx_aud_501960(v8, (*server.Object)(v9), 0, 0)
			}
		}
		result = 1
	}
	return result
}
func nox_xxx_castFist_52D3C0(a1 int32, a2 int32, a3 int32, a4 int32, a5 int32, a6 int32) int32 {
	var (
		v6     int32
		v7     *uint8
		v8     float32
		v9     float32
		v10    float32
		v11    int32
		v12    int32
		result int32
		v14    *uint32
		v15    int32
		v16    *uint32
	)
	_ = v16
	var v17 float64
	var v18 uint32
	var v19 int32
	var v20 float32
	var v21 float4
	if *memmap.PtrUint32(0x5D4594, 2487736) == 0 {
		*memmap.PtrUint32(0x5D4594, 2487740) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("SmallFist")))
		*memmap.PtrUint32(0x5D4594, 2487744) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("MediumFist")))
		*memmap.PtrUint32(0x5D4594, 2487748) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("LargeFist")))
		*memmap.PtrUint32(0x5D4594, 2487752) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("LargeFist")))
		*memmap.PtrUint32(0x5D4594, 2487756) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("LargeFist")))
		*memmap.PtrUint32(0x5D4594, 2487736) = 1
	}
	v6 = int32(*(*uint32)(unsafe.Add(a3, 516)))
	if v6 != 0 {
		for {
			v7 = (*uint8)(memmap.PtrOff(0x5D4594, 2487740))
			for {
				if uint32(*(*uint16)(unsafe.Add(v6, 4))) == *(*uint32)(unsafe.Pointer(v7)) {
					nox_xxx_netPriMsgToPlayer_4DA2C0((*server.Object)(a3), internCStr("ExecSpel.c:TooManyFists"), 0)
					return 0
				}
				v7 = (*uint8)(unsafe.Add(unsafe.Pointer(v7), 4))
				if int32(uintptr(unsafe.Pointer(v7))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 2487760))) {
					break
				}
			}
			v6 = int32(*(*uint32)(unsafe.Add(v6, 512)))
			if v6 != 0 {
				continue
			}
			break
		}
	}
	v8 = *(*float32)(unsafe.Add(a4, 60))
	v9 = *(*float32)(unsafe.Add(a5, 4))
	v21.field_0 = *(*float32)(unsafe.Add(a4, 56))
	v10 = *(*float32)(unsafe.Add(a5, 8))
	v21.field_4 = v8
	v21.field_8 = v9
	v21.field_C = v10
	v11 = bool2int32(noxflags.HasGame(2048))
	if nox_xxx_mapTraceRay_535250(&v21, nil, nil, int8(func() int32 {
		if v11 == 0 {
			return 73
		}
		return 9
	}())) != 0 {
		v14 = (*uint32)(unsafe.Pointer(nox_xxx_newObjectWithTypeInd_4E3450(int32(*memmap.PtrUint32(0x5D4594, uintptr(a6*4)+2487736)))))
		v15 = int32(uintptr(unsafe.Pointer(v14)))
		if v14 != nil {
			v16 = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v14), 4*187)))
			v20 = float32(nox_xxx_gamedataGetFloatTable_419D70(internCStr("FistOfVengeanceDamage"), a6-1))
			*v16 = uint32(int32(v20))
			nox_xxx_createAt_4DAA50((*server.Object)(v15), (*server.Object)(a4), *(*float32)(unsafe.Add(a5, 4)), *(*float32)(unsafe.Add(a5, 8)))
			*(*uint32)(unsafe.Add(v15, 20)) |= 0x20
			nox_xxx_unitRaise_4E46F0((*server.Object)(v15), 255.0)
			v17 = nox_xxx_gamedataGetFloat_419D40(internCStr("FistSpeed"))
			v18 = *(*uint32)(unsafe.Add(v15, 16)) | 0x800000
			*(*float32)(unsafe.Add(v15, 108)) = float32(-v17)
			*(*uint32)(unsafe.Add(v15, 16)) = v18
			*(*uint32)(unsafe.Add(v15, 116)) = 1091567616
			v19 = nox_xxx_spellGetAud44_424800(a1, 0)
			nox_xxx_aud_501960(v19, (*server.Object)(a4), 0, 0)
		}
		result = 1
	} else {
		if int32(*(*uint8)(unsafe.Add(a4, 8)))&4 != 0 {
			v12 = int32(*(*uint32)(unsafe.Add(a4, 748)))
			a6 = 2
			nox_xxx_netInformTextMsg_4DA0F0(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v12, 276)), 2064))), 0, &a6)
		}
		result = 0
	}
	return result
}
func nox_xxx_spellCastCleansingFlame_52D5C0(a1 int32, a2p *server.Object, a3p *server.Object, a4p *server.Object, a5p unsafe.Pointer, a6 int32) int32 {
	var (
		a2 int32 = int32(uintptr(unsafe.Pointer(a2p)))
		a3 int32 = int32(uintptr(unsafe.Pointer(a3p)))
		a4 int32 = int32(uintptr(unsafe.Pointer(a4p)))
		a5 int32 = int32(uintptr(a5p))
	)
	_ = a5
	var v6 int32
	var v7 *uint8
	var v8 int32
	var v9 *float32
	var v10 int16
	var v11 float64
	var v12 float64
	var v13 int32
	var v14 float32
	var v15 float64
	var v17 int32
	var v18 int32
	var v19 int32
	var v20 float4
	var v21 float32
	var v22 float32
	if *memmap.PtrUint32(0x5D4594, 2487760) == 0 {
		*memmap.PtrUint32(0x5D4594, 2487760) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("SmallFlameCleanse")))
		*memmap.PtrUint32(0x5D4594, 2487764) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("SmallFlameCleanse")))
		*memmap.PtrUint32(0x5D4594, 2487768) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("MediumFlameCleanse")))
		*memmap.PtrUint32(0x5D4594, 2487772) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("FlameCleanse")))
		*memmap.PtrUint32(0x5D4594, 2487776) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("LargeFlameCleanse")))
		*memmap.PtrUint32(0x5D4594, 2487780) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("SmallBlueFlameCleanse")))
		*memmap.PtrUint32(0x5D4594, 2487784) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("SmallBlueFlameCleanse")))
		*memmap.PtrUint32(0x5D4594, 2487788) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("MediumBlueFlameCleanse")))
		*memmap.PtrUint32(0x5D4594, 2487792) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("BlueFlameCleanse")))
		*memmap.PtrUint32(0x5D4594, 2487796) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("LargeBlueFlameCleanse")))
	}
	if a2 != 0 {
		v6 = int32(*(*uint32)(unsafe.Add(a2, 516)))
		if v6 != 0 {
			for {
				v7 = (*uint8)(memmap.PtrOff(0x5D4594, 2487760))
				for {
					if uint32(*(*uint16)(unsafe.Add(v6, 4))) == *(*uint32)(unsafe.Pointer(v7)) {
						nox_xxx_netPriMsgToPlayer_4DA2C0((*server.Object)(a3), internCStr("plyrspel.c:TooManySpells"), 0)
						return 0
					}
					v7 = (*uint8)(unsafe.Add(unsafe.Pointer(v7), 4))
					if int32(uintptr(unsafe.Pointer(v7))) >= int32(uintptr(memmap.PtrOff(0x5D4594, 2487800))) {
						break
					}
				}
				v6 = int32(*(*uint32)(unsafe.Add(v6, 512)))
				if v6 != 0 {
					continue
				}
				break
			}
		}
	}
	if !noxflags.HasGame(2048) {
		a6 = 4
	}
	v19 = 48
	for {
		v8 = a6 - nox_common_randomInt_415FA0(0, 1)
		if v8 >= 1 {
			v9 = (*float32)(unsafe.Pointer(nox_xxx_newObjectWithTypeInd_4E3450(int32(*memmap.PtrUint32(0x5D4594, uintptr(((func() int32 {
				if a1 != 10 {
					return 5
				}
				return 0
			}())+v8)*4)+2487756)))))
			if v9 != nil {
				v10 = int16(nox_common_randomInt_415FA0(0, math.MaxUint8))
				v11 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(v9), unsafe.Sizeof(float32(0))*44)))
				*((*uint16)(unsafe.Add(unsafe.Pointer(v9), unsafe.Sizeof(uint16(0))*62))) = uint16(v10)
				v12 = v11 + float64(*(*float32)(unsafe.Add(a4, 176))) + 4.0
				v13 = int32(v10) * 8
				v21 = *mem_getFloatPtr(0x587000, uint32(v13)+194136)
				v22 = *mem_getFloatPtr(0x587000, uint32(v13)+194140)
				v14 = *(*float32)(unsafe.Add(a4, 60))
				v15 = v12*float64(v21) + float64(*(*float32)(unsafe.Add(a4, 56)))
				v20.field_0 = *(*float32)(unsafe.Add(a4, 56))
				v20.field_4 = v14
				v20.field_8 = float32(v15)
				v20.field_C = float32(v12*float64(v22) + float64(*(*float32)(unsafe.Add(a4, 60))))
				if nox_xxx_mapTraceRay_535250(&v20, nil, nil, 65) != 0 {
					nox_xxx_createAt_4DAA50((*server.Object)(unsafe.Pointer(v9)), (*server.Object)(a4), v20.field_8, v20.field_C)
					*((*uint16)(unsafe.Add(unsafe.Pointer(v9), unsafe.Sizeof(uint16(0))*63))) = *((*uint16)(unsafe.Add(unsafe.Pointer(v9), unsafe.Sizeof(uint16(0))*62)))
					*(*float32)(unsafe.Add(unsafe.Pointer(v9), unsafe.Sizeof(float32(0))*20)) = float32(float64(v21) * 4.0)
					*(*float32)(unsafe.Add(unsafe.Pointer(v9), unsafe.Sizeof(float32(0))*21)) = float32(float64(v22) * 4.0)
					*((*uint32)(unsafe.Add(unsafe.Pointer(v9), 4*34))) = gameFrame() + uint32(nox_common_randomInt_415FA0(int32(gameFPS()*3), int32(gameFPS()*6)))
					*(*float32)(unsafe.Add(unsafe.Pointer(v9), unsafe.Sizeof(float32(0))*39)) = *(*float32)(unsafe.Add(a4, 56))
					*(*float32)(unsafe.Add(unsafe.Pointer(v9), unsafe.Sizeof(float32(0))*40)) = *(*float32)(unsafe.Add(a4, 60))
					*((*uint32)(unsafe.Add(unsafe.Pointer(v9), 4*186))) = uint32(uintptr(ccall.FuncAddr(nox_xxx_updateFlameCleanse_53D510)))
					nox_xxx_unitAddToUpdatable_4DA8D0((*server.Object)(unsafe.Pointer(v9)))
					v17 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v9), 4*2))) | 0x40000000)
					*(*float32)(unsafe.Add(unsafe.Pointer(v9), unsafe.Sizeof(float32(0))*28)) = 0.0
					*((*uint32)(unsafe.Add(unsafe.Pointer(v9), 4*2))) = uint32(v17)
					nox_xxx_netClientPredictLinear_523530(int32(uintptr(unsafe.Pointer(v9))))
				} else {
					nox_xxx_delayedDeleteObject_4E5CC0((*server.Object)(unsafe.Pointer(v9)))
				}
			}
		}
		v19--
		if v19 == 0 {
			break
		}
	}
	v18 = nox_xxx_spellGetAud44_424800(a1, 0)
	nox_xxx_aud_501960(v18, (*server.Object)(a4), 0, 0)
	return 1
}
func nox_xxx_castMeteorShower_52D8A0(a1 int32, a2 int32, a3 int32, a4 int32, a5 int32, a6 int32) int32 {
	var (
		v6     int32
		v7     int32
		v8     float32
		v9     float32
		v10    float32
		v11    int32
		v12    int32
		result int32
		v14    *uint32
		v15    int32
		v16    *uint32
	)
	_ = v16
	var v17 int32
	var v18 float32
	var v19 float4
	if *memmap.PtrUint32(0x5D4594, 2487800) == 0 {
		*memmap.PtrUint32(0x5D4594, 2487800) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("MeteorShower")))
	}
	v6 = a5
	v7 = a4
	v8 = *(*float32)(unsafe.Add(a5, 4))
	v9 = *(*float32)(unsafe.Add(a4, 60))
	v19.field_0 = *(*float32)(unsafe.Add(a4, 56))
	v10 = *(*float32)(unsafe.Add(a5, 8))
	v19.field_4 = v9
	v19.field_8 = v8
	v19.field_C = v10
	v11 = bool2int32(noxflags.HasGame(2048))
	if nox_xxx_mapTraceRay_535250(&v19, nil, nil, int8(func() int32 {
		if v11 == 0 {
			return 73
		}
		return 9
	}())) != 0 {
		v14 = (*uint32)(unsafe.Pointer(nox_xxx_newObjectWithTypeInd_4E3450(*memmap.PtrInt32(0x5D4594, 2487800))))
		v15 = int32(uintptr(unsafe.Pointer(v14)))
		if v14 != nil {
			v16 = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v14), 4*187)))
			v18 = float32(nox_xxx_gamedataGetFloatTable_419D70(internCStr("MeteorDamage"), a6-1))
			*v16 = uint32(int32(v18))
			nox_xxx_createAt_4DAA50((*server.Object)(v15), (*server.Object)(a3), *(*float32)(unsafe.Add(v6, 4)), *(*float32)(unsafe.Add(v6, 8)))
			v17 = nox_xxx_spellGetAud44_424800(a1, 0)
			nox_xxx_aud_501960(v17, (*server.Object)(a3), 0, 0)
		}
		result = 1
	} else {
		if int32(*(*uint8)(unsafe.Add(v7, 8)))&4 != 0 {
			v12 = int32(*(*uint32)(unsafe.Add(v7, 748)))
			a4 = 2
			nox_xxx_netInformTextMsg_4DA0F0(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v12, 276)), 2064))), 0, &a4)
		}
		result = 0
	}
	return result
}

var dword_5d4594_2487804 int32

func Nox_xxx_castMeteor_52D9D0(sp spell.ID, a2p, a3p, a4p *server.Object, sa *server.SpellAcceptArg, lvl int) int {
	typ := dword_5d4594_2487804
	if dword_5d4594_2487804 == 0 {
		typ = nox_xxx_getNameId_4E3AA0(internCStr("Meteor"))
		dword_5d4594_2487804 = typ
	}
	for it := a3p.Field129; it != nil; it = it.Field128 {
		if int32(it.TypeInd) == typ {
			nox_xxx_netPriMsgToPlayer_4DA2C0(a3p, internCStr("ExecSpel.c:TooManyMeteors"), 0)
			return 0
		}
	}
	v14v := int8(9)
	if !noxflags.HasGame(2048) {
		v14v = 73
	}
	var line float4
	line.field_0 = a4p.PosVec.X
	line.field_4 = a4p.PosVec.Y
	line.field_8 = sa.Pos.X
	line.field_C = sa.Pos.Y
	if nox_xxx_mapTraceRay_535250(&line, nil, nil, v14v) != 0 {
		if p := nox_xxx_newObjectWithTypeInd_4E3450(dword_5d4594_2487804); p != nil {
			dmg := float32(nox_xxx_gamedataGetFloatTable_419D70(internCStr("MeteorDamage"), int32(lvl-1)))
			*(*int32)(p.UpdateData) = int32(dmg)
			nox_xxx_createAt_4DAA50(p, a3p, sa.Pos.X, sa.Pos.Y)
			p.Field5 |= 0x20
			nox_xxx_unitRaise_4E46F0(p, 255.0)
			p.Field27 = -float32(nox_xxx_gamedataGetFloat_419D40(internCStr("MeteorSpeed")))
			snd := nox_xxx_spellGetAud44_424800(int32(sp), 0)
			nox_xxx_audCreate_501A30(snd, &sa.Pos, 0, 0)
		}
		return 1
	}
	if a4p.Class().Has(object.ClassPlayer) {
		ud := a4p.UpdateDataPlayer()
		a3 := int32(2)
		nox_xxx_netInformTextMsg_4DA0F0(int32(ud.Player.Index()), 0, &a3)
	}
	return 0
}
func nox_xxx_castToxicCloud_52DB60(a1 int32, a2 int32, a3 int32, a4 int32, a5 int32, a6 int) int32 {
	var (
		v5     int32
		v6     int32
		v7     float32
		v8     float32
		v9     float32
		v10    int32
		result int32
		v12    *uint32
		v13    *uint32
	)
	_ = v13
	var v14 int32
	var v15 float32
	var v16 float4
	if *memmap.PtrUint32(0x5D4594, 2487808) == 0 {
		*memmap.PtrUint32(0x5D4594, 2487808) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("ToxicCloud")))
	}
	v5 = a4
	v6 = a5
	v7 = *(*float32)(unsafe.Add(a4, 56))
	v8 = *(*float32)(unsafe.Add(a5, 4))
	v16.field_4 = *(*float32)(unsafe.Add(a4, 60))
	v16.field_0 = v7
	v9 = *(*float32)(unsafe.Add(a5, 8))
	v16.field_8 = v8
	v16.field_C = v9
	if int32(uint8(int8(nox_xxx_traceRay_5374B0(&v16)))) != 0 {
		v12 = (*uint32)(unsafe.Pointer(nox_xxx_newObjectWithTypeInd_4E3450(*memmap.PtrInt32(0x5D4594, 2487808))))
		if v12 != nil {
			v13 = (*uint32)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v12), 4*187)))
			nox_xxx_createAt_4DAA50((*server.Object)(unsafe.Pointer(v12)), (*server.Object)(a3), *(*float32)(unsafe.Add(v6, 4)), *(*float32)(unsafe.Add(v6, 8)))
			v15 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("ToxicCloudLifetime")) * float64(int32(gameFPS())))
			*v13 = uint32(int32(v15))
		}
		v14 = nox_xxx_spellGetAud44_424800(a1, 0)
		nox_xxx_aud_501960(v14, (*server.Object)(unsafe.Pointer(v12)), 0, 0)
		result = 1
	} else {
		if int32(*(*uint8)(unsafe.Add(v5, 8)))&4 != 0 {
			v10 = int32(*(*uint32)(unsafe.Add(v5, 748)))
			a4 = 2
			nox_xxx_netInformTextMsg_4DA0F0(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v10, 276)), 2064))), 0, &a4)
		}
		result = 0
	}
	return result
}
func nox_xxx_spellArachna_52DC80(a1 int32, a2 int32, a3 int32, a4 int32, a5 int32, a6 int) int32 {
	var (
		v5     int32
		v6     int32
		v7     float32
		v8     float32
		v9     float32
		v10    int32
		result int32
		v12    *uint32
		v13    float4
	)
	if *memmap.PtrUint32(0x5D4594, 2487812) == 0 {
		*memmap.PtrUint32(0x5D4594, 2487812) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("ArachnaphobiaFocus")))
	}
	v5 = a4
	v6 = a5
	v7 = *(*float32)(unsafe.Add(a4, 56))
	v8 = *(*float32)(unsafe.Add(a5, 4))
	v13.field_4 = *(*float32)(unsafe.Add(a4, 60))
	v13.field_0 = v7
	v9 = *(*float32)(unsafe.Add(a5, 8))
	v13.field_8 = v8
	v13.field_C = v9
	if int32(uint8(int8(nox_xxx_traceRay_5374B0(&v13)))) != 0 {
		v12 = (*uint32)(unsafe.Pointer(nox_xxx_newObjectWithTypeInd_4E3450(*memmap.PtrInt32(0x5D4594, 2487812))))
		if v12 != nil {
			nox_xxx_createAt_4DAA50((*server.Object)(unsafe.Pointer(v12)), (*server.Object)(a3), *(*float32)(unsafe.Add(v6, 4)), *(*float32)(unsafe.Add(v6, 8)))
		}
		result = 1
	} else {
		if int32(*(*uint8)(unsafe.Add(v5, 8)))&4 != 0 {
			v10 = int32(*(*uint32)(unsafe.Add(v5, 748)))
			a4 = 2
			nox_xxx_netInformTextMsg_4DA0F0(int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v10, 276)), 2064))), 0, &a4)
		}
		result = 0
	}
	return result
}
func sub_52DD50(a1 int32, a2 int32, a3 int32, a4 int32, a5 unsafe.Pointer, a6 int) int32 {
	var (
		v5  unsafe.Pointer
		v8  int16
		v9  int16
		v10 int8
		v11 float64
		v12 int32
		v13 int32
		v14 int32
		v15 float32
	)
	v5 = a5
	v6 := *(*unsafe.Pointer)(a5)
	if *(*uint32)(a5) == 0 {
		return 0
	}
	v8 = nox_xxx_unitGetHP_4EE780((*server.Object)(*(*unsafe.Pointer)(a5)))
	if int32(v8) == int32(nox_xxx_unitGetMaxHP_4EE7A0(v6)) && uint32(a2) == *(*uint32)(a5) {
		v9 = int16(nox_xxx_spellManaCost_4249A0(a1, 1))
		sub_4FD030(a3, v9)
		return 1
	}
	v15 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("LesserHealAmount")))
	if a3 != 0 && int32(*(*uint8)(unsafe.Add(a3, 8)))&4 != 0 {
		v10 = int8(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a3, 748)), 276)), 2251)))
		switch v10 {
		case 0:
			v11 = float64(nox_xxx_warriorMaxHealth_587000_312784)
			v15 = float32(v11 * float64(v15))
		case 2:
			v11 = float64(nox_xxx_conjurerMaxHealth_587000_312800)
			v15 = float32(v11 * float64(v15))
		case 1:
			v11 = float64(nox_xxx_wizardMaxHealth_587000_312816)
			v15 = float32(v11 * float64(v15))
		}
	}
	v12 = int32(v15)
	nox_xxx_unitAdjustHP_4EE460((*server.Object)(*(*unsafe.Pointer)(v5)), v12)
	v14 = int32(*(*uint32)(v5))
	v13 = nox_xxx_spellGetAud44_424800(a1, 1)
	nox_xxx_aud_501960(v13, (*server.Object)(v14), 0, 0)
	return 1
}
func nox_xxx_castEquake_52DE40(a1 int32, a2 int32, a3 int32, a4 int32, a5 int32, a6 int32) int32 {
	var (
		v6  int32
		v7  int32
		v9  float32
		v10 float32
	)
	*memmap.PtrUint32(0x5D4594, 2487700) = uint32(a6)
	v9 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("EarthquakeRange")))
	nox_xxx_unitsGetInCircle_517F90((*types.Pointf)(unsafe.Add(a4, 56)), v9, nox_xxx_equakeDamage_52DEC0, a4)
	v6 = nox_xxx_spellGetAud44_424800(a1, 0)
	nox_xxx_aud_501960(v6, (*server.Object)(a4), 0, 0)
	v10 = float32(nox_xxx_gamedataGetFloatTable_419D70(internCStr("EarthquakeJiggle"), a6-1))
	v7 = int32(v10)
	nox_xxx_earthquakeSend_4D9110((*types.Pointf)(unsafe.Add(a4, 56)), v7)
	return 1
}
func nox_xxx_equakeDamage_52DEC0(it *server.Object, data unsafe.Pointer) {
	a1 := int32(uintptr(it.CObj()))
	a2 := int32(uintptr(data))
	var (
		v2 int32
		v3 int32
		v4 int32
		v5 float64
		v7 float32
		v8 float32
	)
	v2 = a2
	v3 = int32(uintptr(unsafe.Pointer(nox_xxx_findParentChainPlayer_4EC580((*server.Object)(a2)))))
	v4 = v3
	if a1 != a2 {
		v3 = int32(*(*uint32)(unsafe.Add(a1, 16)))
		if (v3 & 0x4000) == 0 {
			*(*uint16)(unsafe.Add(unsafe.Pointer(&v3), unsafe.Sizeof(uint16(0))*0)) = uint16(nox_xxx_unitGetHP_4EE780((*server.Object)(a1)))
			if int32(uint16(int16(v3))) != 0 {
				v7 = float32(nox_xxx_calcDistance_4E6C00((*server.Object)(a1), (*server.Object)(a2)))
				v8 = float32(1.0 - float64(v7)/nox_xxx_gamedataGetFloat_419D40(internCStr("EarthquakeRange")))
				v5 = nox_xxx_gamedataGetFloatTable_419D70(internCStr("EarthquakeDamage"), int32(*memmap.PtrUint32(0x5D4594, 2487700)-1)) * float64(v8)
				*(*uint16)(unsafe.Add(unsafe.Pointer(&v3), unsafe.Sizeof(uint16(0))*0)) = uint16(int16(ccall.AsFunc[func(int32, int32, int32, uint32, int32) int32](*(*unsafe.Pointer)(unsafe.Add(a1, 716)))(a1, v4, v2, uint32(int32(int64(v5))), 11)))
			}
		}
	}
}
func nox_xxx_isObjectMovable_52E020(a1 unsafe.Pointer) uint32 {
	var result uint32
	if *(*uint32)(unsafe.Add(a1, 16))&0x8068 != 0 {
		result = 0
	} else {
		result = (^*(*uint32)(unsafe.Add(a1, 8)) >> 22) & 1
	}
	return result
}
func nox_xxx_mapPushUnitsAround_52E040(a1p unsafe.Pointer, a2 float32, a3p float32, a4 float32, a5p *server.Object, a6 int32, a7 int32) {
	var (
		a1  int32 = int32(uintptr(a1p))
		a3  int32 = a3p
		a5  int32 = int32(uintptr(unsafe.Pointer(a5p)))
		v7  float64
		v8  float64
		a1a float4
		a3a [7]int32
	)
	a3a[0] = a1
	v7 = float64(*(*float32)(a1) - a2)
	a3a[5] = a6
	a3a[6] = a7
	a1a.field_0 = float32(v7)
	a1a.field_4 = *(*float32)(unsafe.Add(a1, 4)) - a2
	a1a.field_8 = a2 + *(*float32)(a1)
	v8 = float64(a2 + *(*float32)(unsafe.Add(a1, 4)))
	a3a[4] = a5
	a3a[2] = a3
	a1a.field_C = float32(v8)
	*(*float32)(unsafe.Pointer(&a3a[3])) = float32(float64(a4) * 10.0)
	if float64(a2) >= float64(a3p) {
		*(*float32)(unsafe.Pointer(&a3a[1])) = a2
	} else {
		a3a[1] = a3
	}
	nox_xxx_getUnitsInRectAdv_517ED0(&a1a, nox_xxx_unitPushAroundFn_52E0E0, unsafe.Pointer(&a3a[0]))
}
func nox_xxx_unitPushAroundFn_52E0E0(it *server.Object, data unsafe.Pointer) {
	a1 := it.CObj()
	a2 := (**int32)(data)
	var (
		v3  **int32
		v4  *int32
		v5  float32
		v6  float32
		v7  float32
		v8  float64
		v9  float64
		v10 float64
		v12 bool
		v13 float32
		v14 float32
		v15 float4
		v16 float32
		v17 float32
		v18 float32
	)
	v2 := a1
	if nox_xxx_isObjectMovable_52E020(a1) != 0 {
		v3 = a2
		v4 = *a2
		*(*uint32)(unsafe.Add(unsafe.Pointer(&v15.field_0), 4*0)) = uint32(**a2)
		v5 = *((*float32)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(float32(0))*1)))
		v6 = *(*float32)(unsafe.Add(a1, 56))
		v7 = *(*float32)(unsafe.Add(a1, 60))
		v15.field_4 = v5
		v15.field_8 = v6
		v15.field_C = v7
		if nox_xxx_mapTraceRay_535250(&v15, nil, nil, 0) != 0 {
			v13 = *(*float32)(unsafe.Add(a1, 56)) - *(*float32)(unsafe.Pointer(*a2))
			v8 = float64(*(*float32)(unsafe.Add(a1, 60)) - *((*float32)(unsafe.Add(unsafe.Pointer(*a2), unsafe.Sizeof(float32(0))*1))))
			v14 = float32(v8)
			v9 = math.Sqrt(v8*float64(v14)+float64(v13*v13)) + 0.1
			v16 = float32(v9)
			if v9 <= float64(*((*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*1)))) {
				if float64(v16) > float64(*((*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*2)))) {
					v17 = float32((1.0 - float64((v16-*((*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*2))))/(*((*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*1)))-*((*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*2)))))) * float64(*((*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*3)))))
				} else {
					v17 = *((*float32)(unsafe.Add(unsafe.Pointer(a2), unsafe.Sizeof(float32(0))*3)))
				}
				v10 = nox_xxx_objectGetMass_4E4A70(v2)
				v11 := *(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof((*int32)(nil))*5))
				v18 = float32(float64(v17) / v10)
				if v11 != nil {
					(ccall.AsFunc[func(unsafe.Pointer, uint32, *int32)](v11))(v2, *(*uint32)(unsafe.Add(unsafe.Pointer(&v16), 4*0)), *(**int32)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof((*int32)(nil))*6)))
				}
				v12 = (int32(*(*uint8)(unsafe.Add(v2, 8))) & 1) == 0
				*(*float32)(unsafe.Add(v2, 88)) = v18*v13/v16 + *(*float32)(unsafe.Add(v2, 88))
				*(*float32)(unsafe.Add(v2, 92)) = v18*v14/v16 + *(*float32)(unsafe.Add(v2, 92))
				if v12 {
					nox_xxx_unitHasCollideOrUpdateFn_537610((*server.Object)(v2))
				}
			}
		}
	}
}
func Nox_xxx_spellDrainMana_52E210(sp *server.DurSpell) int32 {
	a1 := int32(uintptr(sp.C()))
	var (
		v1  int32
		v2  int32
		v3  int32
		v4  float32
		v8  uint16
		v9  int32
		v10 int32
		v11 float64
		v12 float64
		v14 int32
		v15 *uint32
		v16 float64
		v17 *uint32
		v18 int32
		v19 types.Pointf
		v21 float32
		v22 float32
	)
	v1 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0)))
	v2 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0))))), 16)))
	if v2 != 0 {
		if nox_xxx_testUnitBuffs_4FF350((*server.Object)(v2), 8) != 0 {
			return 1
		}
	} else if *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0))))), 20)) == 0 {
		return 1
	}
	if *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0))))), 20)) != 0 {
		v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0))))), 16)))
		if v3 != 0 {
			v19.X = *(*float32)(unsafe.Add(v3, 56))
			v4 = *(*float32)(unsafe.Add(v3, 60))
		} else {
			v4 = *(*float32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0))))), 32))
			v19.X = *(*float32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0))))), 28))
		}
		v19.Y = v4
		v5 := sub_52E610((*int32)(unsafe.Pointer(&v19)), v3)
		if v5 != nil {
			nox_xxx_playerManaSub_4EEBF0(v5, 50)
			return 1
		}
		return 1
	}
	v7 := *(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0))))), 16))
	if int32(*(*uint8)(unsafe.Add(v7, 8)))&4 != 0 {
		v8 = uint16(nox_xxx_unitGetOldMana_4EEC80(v7))
		if int32(v8) >= int32(uint16(nox_xxx_playerGetMaxMana_4EECB0(v7))) {
			return 1
		}
	}
	v9 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0))))), 16)))
	if int32(*(*uint8)(unsafe.Add(v9, 8)))&2 != 0 {
		if sub_4FEA70(v9, (*types.Pointf)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0))))), 28))) != 0 {
			return 1
		}
	}
	v10 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0))))), 16)))
	v11 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0))))), 28)) - *(*float32)(unsafe.Add(v10, 56)))
	if v11 < 0.0 {
		v11 = -v11
	}
	v19.X = float32(v11)
	v12 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0))))), 32)) - *(*float32)(unsafe.Add(v10, 60)))
	if v12 < 0.0 {
		v12 = -v12
	}
	v19.Y = float32(v12)
	if sub_4E6BD0(v10) != 0 || float64(v19.X) >= 5.0 || float64(v19.Y) >= 5.0 {
		return 1
	}
	v13 := sub_52E610((*int32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0))))), 16)), 56)), int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0))))), 16))))
	*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0))))), 48)) = v13
	if v13 == nil {
		if *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0))))), 36)) != 0 {
			nox_xxx_netStopRaySpell_4FEF90(*(*int32)(unsafe.Add(unsafe.Pointer(&a1), 4*0)), *(**uint32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0))))), 36)))
		}
		return 1
	}
	v21 = *(*float32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0))))), 72))
	v22 = float32(nox_xxx_gamedataGetFloatTable_419D70(internCStr("ManaDrainCoeff"), int32(*(*uint32)(unsafe.Add(v1, 8))-1)) + float64(v21))
	v14 = COERCE_FLOAT(uint32(int32(v22)))
	v15 = *(**uint32)(unsafe.Add(v1, 48))
	v19.X = v14
	v16 = float64(v14)
	v17 = *(**uint32)(unsafe.Add(v1, 36))
	*(*float32)(unsafe.Add(v1, 72)) = float32(float64(v22) - v16)
	if v15 != v17 {
		if v17 != nil {
			nox_xxx_netStopRaySpell_4FEF90(v1, v17)
		}
		nox_xxx_netStartDurationRaySpell_4FF130(v1)
	}
	v18 = int32(v22)
	if sub_52E450(*(*unsafe.Pointer)(unsafe.Add(v1, 16)), *(*unsafe.Pointer)(unsafe.Add(v1, 48)), v18) != 0 && (gameFrame()%(gameFPS()>>1)) == 0 {
		nox_xxx_aud_501960(230, (*server.Object)(*(*unsafe.Pointer)(unsafe.Add(v1, 16))), 0, 0)
		nox_xxx_aud_501960(229, (*server.Object)(*(*unsafe.Pointer)(unsafe.Add(v1, 48))), 0, 0)
	}
	*(*uint32)(unsafe.Add(v1, 36)) = *(*uint32)(unsafe.Add(v1, 48))
	return 0
}
func sub_52E450(a1 unsafe.Pointer, a2 unsafe.Pointer, a3 int32) int32 {
	var (
		v3  int32
		v4  int32
		v5  *int32
		v6  int32
		v7  int32
		v8  int8
		v9  float64
		v11 float32
	)
	if int32(*(*uint8)(unsafe.Add(a1, 8)))&4 != 0 {
		v3 = int32(*(*uint32)(unsafe.Add(a1, 748)))
		if int32(uint16(nox_xxx_unitGetOldMana_4EEC80(a1))) >= int32(*(*uint16)(unsafe.Add(v3, 8))) {
			return 0
		}
	}
	v4 = int32(*(*uint32)(unsafe.Add(a2, 8)))
	if uint32(v4)&0x400000 != 0 && int32(*(*uint8)(unsafe.Add(a2, 12)))&0x18 != 0 {
		v5 = *(**int32)(unsafe.Add(a2, 748))
		if nox_xxx_servObjectHasTeam_419130(unsafe.Add(a2, 48)) != 0 && nox_xxx_servCompareTeams_419150(unsafe.Add(a2, 48), unsafe.Add(a1, 48)) == 0 {
			return 0
		}
		v6 = a3
		if *v5 <= a3 {
			v6 = *v5
			a3 = *v5
			if !noxflags.HasGame(4096) {
				*v5 = 0
			}
		} else if !noxflags.HasGame(4096) {
			*v5 -= a3
		}
		if v6 == 0 {
			return 0
		}
		if !noxflags.HasGame(4096) {
			nox_xxx_unitNeedSync_4E44F0((*server.Object)(a2))
		}
		if v6 > 0 {
			goto LABEL_24
		}
		return 0
	}
	if v4&2 != 0 {
		if int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a2, 748)), 1440)))&0x20 != 0 {
			*(*uint16)(unsafe.Add(unsafe.Pointer(&v6), unsafe.Sizeof(uint16(0))*0)) = 1
			a3 = 1
			goto LABEL_24
		}
		v6 = a3
		if v6 > 0 {
			goto LABEL_24
		}
		return 0
	}
	if (v4 & 4) == 0 {
		v6 = a3
		if v6 > 0 {
			goto LABEL_24
		}
		return 0
	}
	v6 = a3
	v7 = int32(*(*uint16)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a2, 748)), 4)))
	if int32(uint16(int16(v7))) <= a3 {
		v6 = int32(*(*uint16)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a2, 748)), 4)))
		a3 = int32(*(*uint16)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a2, 748)), 4)))
		nox_xxx_playerManaSub_4EEBF0(a2, v7)
	} else {
		nox_xxx_playerManaSub_4EEBF0(a2, a3)
	}
	if v6 <= 0 {
		return 0
	}
LABEL_24:
	if !noxflags.HasGame(4096) || (int32(*(*uint8)(unsafe.Add(a1, 8)))&4) == 0 {
		nox_xxx_playerManaAdd_4EEB80((*server.Object)(a1), int16(v6))
		return 1
	}
	v8 = int8(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 748)), 276)), 2251)))
	if int32(v8) != 0 {
		if int32(v8) == 1 {
			v9 = float64(a3) * float64(nox_xxx_wizardMaximumMana_587000_312820)
		} else {
			if int32(v8) != 2 {
				nox_xxx_playerManaAdd_4EEB80((*server.Object)(a1), int16(v6))
				return 1
			}
			v9 = float64(a3) * float64(nox_xxx_conjurerMaxMana_587000_312804)
		}
	} else {
		v9 = float64(a3) * float64(nox_xxx_warriorMaxMana_587000_312788)
	}
	v11 = float32(v9)
	*(*uint16)(unsafe.Add(unsafe.Pointer(&v6), unsafe.Sizeof(uint16(0))*0)) = uint16(int16(int32(v11)))
	nox_xxx_playerManaAdd_4EEB80((*server.Object)(a1), int16(v6))
	return 1
}
func sub_52E610(a1 *int32, a2 int32) unsafe.Pointer {
	*memmap.PtrUint32(0x5D4594, 2487828) = 0
	*memmap.PtrUint32(0x5D4594, 2487876) = 1287568416
	*memmap.PtrUint32(0x5D4594, 2487836) = uint32(*a1)
	*memmap.PtrUint32(0x5D4594, 2487840) = uint32(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1)))
	v3 := float32(nox_xxx_gamedataGetFloat_419D40(internCStr("ManaDrainRange")))
	nox_xxx_unitsGetInCircle_517F90((*types.Pointf)(unsafe.Pointer(a1)), v3, sub_52E660, a2)
	return *memmap.PtrPtr(0x5D4594, 2487828)
}
func sub_52E660(it *server.Object, data unsafe.Pointer) {
	a1 := it.CObj()
	a2 := data
	var (
		v2  int32
		v3  int32
		v4  float64
		v5  int32
		v6  float64
		v7  float64
		v8  float64
		v9  float32
		v10 float32
		v11 float4
		v12 float32
	)
	if a1 == a2 || sub_52E7C0(a1) == 0 || *(*uint32)(unsafe.Add(a1, 16))&0x8020 != 0 {
		return
	}
	v2 = int32(*(*uint32)(unsafe.Add(a1, 8)))
	if (v2 & 2) == 0 {
		if uint32(v2)&0x400000 != 0 && int32(*(*uint8)(unsafe.Add(a1, 12)))&0x18 != 0 {
			v4 = 1.0
		} else {
			if (v2 & 4) == 0 {
				return
			}
			v5 = int32(*(*uint32)(unsafe.Add(a1, 748)))
			if a2 != nil {
				if nox_xxx_unitIsEnemyTo_5330C0((*server.Object)(a2), (*server.Object)(a1)) == 0 {
					return
				}
			}
			if nox_xxx_unitsHaveSameTeam_4EC520((*server.Object)(a1), (*server.Object)(a2)) != 0 || int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v5, 276)), 3680)))&1 != 0 {
				return
			}
			v4 = 0.5
		}
		goto LABEL_18
	}
	v3 = int32(*(*uint32)(unsafe.Add(a1, 748)))
	if a2 != nil && nox_xxx_unitIsEnemyTo_5330C0((*server.Object)(a2), (*server.Object)(a1)) == 0 || int32(*(*uint8)(unsafe.Add(v3, 1440)))&0x20 == 0 {
		return
	}
	v4 = 1.0
LABEL_18:
	v6 = float64(*mem_getFloatPtr(0x5D4594, 2487836) - *(*float32)(unsafe.Add(a1, 56)))
	v7 = float64(*mem_getFloatPtr(0x5D4594, 2487840) - *(*float32)(unsafe.Add(a1, 60)))
	v8 = v4 * (v7*v7 + v6*v6)
	if v8 < float64(*mem_getFloatPtr(0x5D4594, 2487876)) {
		v9 = *(*float32)(unsafe.Add(a1, 56))
		v11.field_4 = *mem_getFloatPtr(0x5D4594, 2487840)
		v11.field_0 = *mem_getFloatPtr(0x5D4594, 2487836)
		v10 = *(*float32)(unsafe.Add(a1, 60))
		v11.field_8 = v9
		v11.field_C = v10
		if nox_xxx_mapTraceRay_535250(&v11, nil, nil, 5) != 0 {
			*memmap.PtrPtr(0x5D4594, 2487828) = a1
			v12 = float32(v8)
			*mem_getFloatPtr(0x5D4594, 2487876) = v12
		}
	}
}
func sub_52E7C0(a1 unsafe.Pointer) int32 {
	var v1 int32
	v1 = int32(*(*uint32)(unsafe.Add(a1, 8)))
	if uint32(v1)&0x400000 != 0 && int32(*(*uint8)(unsafe.Add(a1, 12)))&0x18 != 0 {
		if **(**uint32)(unsafe.Add(a1, 748)) > 0 {
			return 1
		}
	} else if v1&2 != 0 {
		if int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 748)), 1440)))&0x20 != 0 {
			return 1
		}
	} else if v1&4 != 0 && int32(nox_xxx_unitGetOldMana_4EEC80(a1)) != 0 {
		return 1
	}
	return 0
}
func Nox_xxx_spellEnergyBoltStop_52E820(sp *server.DurSpell) int32 {
	a1 := int32(uintptr(sp.C()))
	if *(*uint32)(unsafe.Add(a1, 16)) != 0 {
		nox_xxx_spellCancelDurSpell_4FEB10(43, (*server.Object)(*(*unsafe.Pointer)(unsafe.Add(a1, 16))))
	}
	nox_xxx_netSendPointFx_522FF0(-126, (*types.Pointf)(unsafe.Add(a1, 28)))
	return 0
}
func Nox_xxx_spellEnergyBoltTick_52E850(sp *server.DurSpell) int32 {
	a1 := int32(uintptr(sp.C()))
	var (
		v1     int32
		v2     int32
		result int32
		v5     int32
		v7     int32
		v8     int32
		v9     int32
		v10    int32
		v11    int32
		v12    int32
		v13    int32
		v14    int32
		v16    float32
		v17    int32
		v18    *uint32
		v19    float64
		v20    *uint32
		v21    int32
		v22    int32
		v23    int32
		v24    int32
		v25    int32
		v26    int32
		v27    float32
		v28    float32
		v31    float32
		v32    float32
		v33    float32
		v34    int32
	)
	v1 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0)))
	v2 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0))))), 16)))
	if v2 != 0 {
		if nox_xxx_testUnitBuffs_4FF350((*server.Object)(v2), 8) != 0 {
			return 1
		}
	} else if *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0))))), 20)) == 0 {
		return 1
	}
	v31 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("LightningRange")))
	if *(*uint32)(unsafe.Add(v1, 20)) == 0 {
		v9 = int32(*(*uint32)(unsafe.Add(v1, 16)))
		if v9 != 0 && int32(*(*uint8)(unsafe.Add(v9, 8)))&2 != 0 && sub_4FEA70(v9, (*types.Pointf)(unsafe.Add(v1, 28))) != 0 {
			return 1
		}
		if (gameFrame()-*(*uint32)(unsafe.Add(v1, 60))) > 2 && sub_4E6BD0(int32(*(*uint32)(unsafe.Add(v1, 16)))) != 0 {
			return 1
		}
		v10 = int32(*(*uint32)(unsafe.Add(v1, 48)))
		if v10 != 0 {
			if (*(*uint32)(unsafe.Add(v10, 16))&0x8020) == 0 && nox_server_testTwoPointsAndDirection_4E6E50((*types.Pointf)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v1, 16)), 56)), int32(*(*int16)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v1, 16)), 124))), (*types.Pointf)(unsafe.Add(v10, 56)))&1 != 0 && nox_xxx_calcDistance_4E6C00((*server.Object)(*(*unsafe.Pointer)(unsafe.Add(v1, 48))), (*server.Object)(*(*unsafe.Pointer)(unsafe.Add(v1, 16)))) <= float64(v31) && nox_xxx_unitCanInteractWith_5370E0((*server.Object)(*(*unsafe.Pointer)(unsafe.Add(v1, 16))), (*server.Object)(*(*unsafe.Pointer)(unsafe.Add(v1, 48))), 0) != 0 {
				goto LABEL_31
			}
			*(*uint32)(unsafe.Add(v1, 48)) = 0
		}
		v11 = int32(*(*uint32)(unsafe.Add(v1, 16)))
		if int32(*(*uint8)(unsafe.Add(v11, 8)))&4 != 0 {
			v12 = int32(*(*uint32)(unsafe.Add(v11, 748)))
			v13 = int32(*(*uint32)(unsafe.Add(v12, 288)))
			if v13 != 0 {
				if nox_xxx_unitIsEnemyTo_5330C0((*server.Object)(v11), (*server.Object)(*(*unsafe.Pointer)(unsafe.Add(v12, 288)))) != 0 && nox_xxx_calcDistance_4E6C00((*server.Object)(*(*unsafe.Pointer)(unsafe.Add(v1, 16))), (*server.Object)(v13)) <= float64(v31) {
					*(*uint32)(unsafe.Add(v1, 48)) = uint32(v13)
				}
			}
		}
		if *(*uint32)(unsafe.Add(v1, 48)) != 0 {
			goto LABEL_32
		}
		*memmap.PtrUint32(0x5D4594, 2487832) = 0
		nox_xxx_energyBoltTarget_5d4594_2487880 = 0
		v14 = int32(*(*uint32)(unsafe.Add(v1, 16)))
		*mem_getFloatPtr(0x5D4594, 2487868) = *(*float32)(unsafe.Add(v14, 56))
		*mem_getFloatPtr(0x5D4594, 2487872) = *(*float32)(unsafe.Add(v14, 60))
		dword_5d4594_2487884 = v31 * v31
		nox_xxx_unitsGetInCircle_517F90((*types.Pointf)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v1, 16)), 56)), v31, nox_xxx_spellEnergyBoltSetTarget_52EC60, *(*unsafe.Pointer)(unsafe.Add(v1, 16)))
		*(*uint32)(unsafe.Add(v1, 48)) = nox_xxx_energyBoltTarget_5d4594_2487880
	LABEL_31:
		if *(*uint32)(unsafe.Add(v1, 48)) == 0 {
			if *(*uint32)(unsafe.Add(v1, 36)) != 0 {
				nox_xxx_netStopRaySpell_4FEF90(v1, *(**uint32)(unsafe.Add(v1, 36)))
				*(*uint32)(unsafe.Add(v1, 36)) = 0
			}
			return 0
		}
	LABEL_32:
		v32 = *(*float32)(unsafe.Add(v1, 72))
		v33 = float32(nox_xxx_gamedataGetFloatTable_419D70(internCStr("EnergyBoltDamage"), int32(*(*uint32)(unsafe.Add(v1, 8))-1)) + float64(v32))
		v16 = v33
		v17 = int32(v33)
		v18 = *(**uint32)(unsafe.Add(v1, 48))
		v19 = float64(v17)
		v20 = *(**uint32)(unsafe.Add(v1, 36))
		*(*float32)(unsafe.Add(v1, 72)) = float32(float64(v33) - v19)
		if v18 != v20 {
			if v20 != nil {
				nox_xxx_netStopRaySpell_4FEF90(v1, v20)
			}
			nox_xxx_netStartDurationRaySpell_4FF130(v1)
		}
		v34 = int32(*(*uint32)(unsafe.Add(v1, 48)))
		v21 = int32(v16)
		ccall.AsFunc[func(uint32, uint32, uint32, int32, int32)](*(*unsafe.Pointer)(unsafe.Add(v34, 716)))(*(*uint32)(unsafe.Add(v1, 48)), *(*uint32)(unsafe.Add(v1, 16)), 0, v21, 17)
		v22 = int32(*(*uint32)(unsafe.Add(v1, 48)))
		if *(*uint32)(unsafe.Add(v22, 16))&0x8020 != 0 {
			nox_xxx_netSendPointFx_522FF0(-126, (*types.Pointf)(unsafe.Add(v22, 56)))
		}
		v23 = int32(*(*uint32)(unsafe.Add(v1, 16)))
		*(*uint32)(unsafe.Add(v1, 36)) = *(*uint32)(unsafe.Add(v1, 48))
		if int32(*(*uint8)(unsafe.Add(v23, 8)))&4 != 0 {
			nox_xxx_playerSetState_4FA020((*server.Object)(v23), 10)
		}
		if (gameFrame() % (gameFPS() / 3)) == 0 {
			nox_xxx_aud_501960(32, (*server.Object)(*(*unsafe.Pointer)(unsafe.Add(v1, 16))), 0, 0)
			nox_xxx_aud_501960(32, (*server.Object)(*(*unsafe.Pointer)(unsafe.Add(v1, 48))), 0, 0)
		}
		v28 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("LightningSearchTime")))
		*(*uint32)(unsafe.Add(v1, 68)) = gameFrame() + uint32(int32(v28))
		v24 = int32(*(*uint32)(unsafe.Add(v1, 16)))
		if int32(*(*uint8)(unsafe.Add(v24, 8)))&4 != 0 {
			nox_xxx_playerSetState_4FA020((*server.Object)(v24), 10)
			nox_xxx_playerManaSub_4EEBF0(*(*unsafe.Pointer)(unsafe.Add(v1, 16)), 1)
			if int32(nox_xxx_unitGetOldMana_4EEC80(*(*unsafe.Pointer)(unsafe.Add(v1, 16)))) == 0 {
				return 1
			}
		}
		v25 = int32(*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v1, 48)), 16)))
		if (v25 & 0x8000) != 0 {
			result = 0
			*(*uint32)(unsafe.Add(v1, 68)) = gameFrame() + 1
			return result
		}
		return 0
	}
	var v29 types.Pointf
	v29.X = *(*float32)(unsafe.Add(v1, 28))
	v29.Y = *(*float32)(unsafe.Add(v1, 32))
	*mem_getFloatPtr(0x5D4594, 2487868) = v29.X
	*mem_getFloatPtr(0x5D4594, 2487872) = v29.Y
	nox_xxx_energyBoltTarget_5d4594_2487880 = 0
	dword_5d4594_2487884 = v31 * v31
	*memmap.PtrUint32(0x5D4594, 2487832) = 1
	v5 = int32(*(*uint32)(unsafe.Add(v1, 16)))
	nox_xxx_unitsGetInCircle_517F90(&v29, v31, nox_xxx_spellEnergyBoltSetTarget_52EC60, v5)
	if nox_xxx_energyBoltTarget_5d4594_2487880 != 0 {
		v6 := ccall.AsFunc[func(uint32, uint32, uint32, int32, int32)](*(*unsafe.Pointer)(unsafe.Add(nox_xxx_energyBoltTarget_5d4594_2487880, 716)))
		v27 = float32(nox_xxx_gamedataGetFloat_419D40(internCStr("EnergyBoltGlyphDamage")))
		v7 = int32(v27)
		v6(nox_xxx_energyBoltTarget_5d4594_2487880, *(*uint32)(unsafe.Add(v1, 12)), 0, v7, 17)
		v26 = int32(nox_xxx_energyBoltTarget_5d4594_2487880)
		v8 = nox_xxx_spellGetAud44_424800(24, 0)
		nox_xxx_aud_501960(v8, (*server.Object)(v26), 0, 0)
		nox_xxx_netSendPointFx_522FF0(-126, (*types.Pointf)(unsafe.Add(nox_xxx_energyBoltTarget_5d4594_2487880, 56)))
	}
	return 1
}
func nox_xxx_spellEnergyBoltSetTarget_52EC60(it *server.Object, data unsafe.Pointer) {
	target := int32(uintptr(it.CObj()))
	source := int32(uintptr(data))
	var (
		v2 int32
		v3 int32
		v4 float64
		v5 float64
		v6 float64
	)
	v2 = int32(*(*uint32)(unsafe.Add(target, 8)))
	if uint32(v2)&0x20006 != 0 {
		if (*(*uint32)(unsafe.Add(target, 16))&0x8020) == 0 && target != source {
			if (v2&2) == 0 || (func() bool {
				v3 = int32(*(*uint32)(unsafe.Add(target, 12)))
				return (v3 & 0x8000) == 0
			}()) {
				if source == 0 || nox_xxx_unitIsEnemyTo_5330C0((*server.Object)(source), (*server.Object)(target)) != 0 && (*memmap.PtrUint32(0x5D4594, 2487832) != 0 || nox_server_testTwoPointsAndDirection_4E6E50((*types.Pointf)(unsafe.Add(source, 56)), int32(*(*int16)(unsafe.Add(source, 124))), (*types.Pointf)(unsafe.Add(target, 56)))&1 != 0 && nox_xxx_unitCanInteractWith_5370E0((*server.Object)(source), (*server.Object)(target), 0) != 0) {
					v4 = float64(*(*float32)(unsafe.Add(target, 56)) - *mem_getFloatPtr(0x5D4594, 2487868))
					v5 = float64(*(*float32)(unsafe.Add(target, 60)) - *mem_getFloatPtr(0x5D4594, 2487872))
					v6 = v5*v5 + v4*v4
					if v6 < float64(dword_5d4594_2487884) {
						dword_5d4594_2487884 = float32(v6)
						nox_xxx_energyBoltTarget_5d4594_2487880 = uint32(target)
					}
				}
			}
		}
	}
}
func Nox_xxx_firewalkTick_52ED40(sp *server.DurSpell) int32 {
	a1 := (*float32)(sp.C())
	var (
		v1     *float32
		v2     int32
		result int32
		v4     int32
		v5     *float32
		v6     int32
		v7     float64
		v8     float64
		v9     float64
		v10    int32
		v11    float32
		v12    int32
		v13    int32
		v14    *uint32
		v15    *uint32
		v16    int32
		v17    float32
		v18    types.Pointf
		v19    float32
	)
	v1 = a1
	v2 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*12))))
	if v2 == 0 {
		return 1
	}
	if *(*uint32)(unsafe.Add(v2, 16))&0x8020 != 0 {
		return 1
	}
	if *memmap.PtrUint32(0x5D4594, 2487888) == 0 {
		*memmap.PtrUint32(0x5D4594, 2487888) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("SmallFlame")))
		*memmap.PtrUint32(0x5D4594, 2487892) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("MediumFlame")))
		*memmap.PtrUint32(0x5D4594, 2487896) = uint32(nox_xxx_getNameId_4E3AA0(internCStr("Flame")))
	}
	if *((*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*15))) == *((*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*16))) {
		v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*12))))), 56)))
		*((*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*18))) = uint32(v4)
		*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*19)) = *(*float32)(unsafe.Add(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*12))))), 60))
		*((*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*20))) = uint32(v4)
		*(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*21)) = *(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*19))
		*((*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*16)))++
		result = 0
	} else {
		v5 = (*float32)(unsafe.Pointer(uintptr(*((*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*12))))))
		v6 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*2))))
		v7 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(float32(0))*14)) - *(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*18)))
		v8 = float64(*(*float32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(float32(0))*15)) - *(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*19)))
		v9 = math.Sqrt(v8*v8 + v7*v7)
		if v6 >= 2 {
			v10 = bool2int32(v6 >= 4) + 1
		} else {
			v10 = 0
		}
		if v9-float64(*(*float32)(unsafe.Add(unsafe.Pointer(v5), unsafe.Sizeof(float32(0))*44))) > 15.0 {
			v11 = *(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*19))
			v18.X = *(*float32)(unsafe.Add(unsafe.Pointer(a1), unsafe.Sizeof(float32(0))*18))
			v18.Y = v11
			v12 = 2
			for {
				v13 = nox_common_randomInt_415FA0(0, v10)
				v14 = (*uint32)(unsafe.Pointer(nox_xxx_newObjectWithTypeInd_4E3450(int32(*memmap.PtrUint32(0x5D4594, uintptr(v13*4)+2487888)))))
				v15 = v14
				if v14 != nil {
					nox_xxx_createAt_4DAA50((*server.Object)(unsafe.Pointer(v14)), nil, v18.X, v18.Y)
					nox_xxx_audCreate_501A30(46, &v18, 0, 0)
					nox_xxx_unitSetDecayTime_511660((*server.Object)(unsafe.Pointer(v15)), int32(gameFPS()*25))
				}
				v19 = v18.X - *(*float32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float32(0))*20))
				v17 = v18.Y - *(*float32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float32(0))*21))
				if float64(v19) != 0.0 && float64(v17) != 0.0 {
					v18.X = float32(float64(v18.X) - float64(v19)*0.5)
					v18.Y = float32(float64(v18.Y) - float64(v17)*0.5)
				}
				v12--
				if v12 == 0 {
					break
				}
			}
			*(*float32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float32(0))*20)) = *(*float32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float32(0))*18))
			*(*float32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float32(0))*21)) = *(*float32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float32(0))*19))
			v16 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v1), 4*12))))
			*(*float32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float32(0))*18)) = *(*float32)(unsafe.Add(v16, 56))
			*(*float32)(unsafe.Add(unsafe.Pointer(v1), unsafe.Sizeof(float32(0))*19)) = *(*float32)(unsafe.Add(v16, 60))
		}
		result = 0
	}
	return result
}
func Sub_52EF30(sp *server.DurSpell) int32 {
	a1 := int32(uintptr(sp.C()))
	var (
		v1 int32
		v2 int32
		v3 int32
		v4 float32
		v5 float32
		v6 int32
		v7 *uint32
		v8 *uint32
	)
	if *(*uint32)(unsafe.Add(a1, 20)) != 0 {
		*(*uint16)(unsafe.Add(a1, 72)) = *(*uint16)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(a1, 24)), 124))
		v3 = int32(*(*uint32)(unsafe.Add(a1, 24)))
		v4 = *(*float32)(unsafe.Add(v3, 56))
		v5 = *(*float32)(unsafe.Add(v3, 60))
	} else {
		v1 = int32(*(*uint32)(unsafe.Add(a1, 16)))
		if int32(*(*uint8)(unsafe.Add(v1, 8)))&4 != 0 {
			v2 = int32(*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v1, 748)), 104)))
			if v2 != 0 {
				if *(*uint32)(unsafe.Add(v2, 12))&0x200000 != 0 && int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v2, 736)), 96)))&4 != 0 {
					*(*uint8)(unsafe.Add(a1, 88)) |= 2
				}
			}
		}
		v6 = int32(*(*uint32)(unsafe.Add(a1, 16)))
		v4 = *(*float32)(unsafe.Add(v6, 56))
		v5 = *(*float32)(unsafe.Add(v6, 60))
		*(*uint16)(unsafe.Add(a1, 72)) = *(*uint16)(unsafe.Add(v6, 124))
	}
	v7 = (*uint32)(unsafe.Pointer(nox_xxx_newObjectByTypeID_4E3810(internCStr("ForceOfNatureCharge"))))
	v8 = v7
	if v7 != nil {
		nox_xxx_createAt_4DAA50((*server.Object)(unsafe.Pointer(v7)), nil, v4, v5)
		*(*uint32)(unsafe.Add(a1, 76)) = uint32(uintptr(unsafe.Pointer(v8)))
	}
	return 0
}
func Sub_52EFD0(sp *server.DurSpell) int32 {
	a1 := int32(uintptr(sp.C()))
	var (
		v1     int32
		v2     int32
		result int32
		v4     *float32
		v5     float32
		v6     float32
		v7     int16
		v8     float64
		v9     int32
		v10    int32
		v11    int32
		v12    float32
		v13    float32
		v14    float32
		v15    float4
		v16    float32
	)
	v1 = a1
	v2 = int32(*(*uint32)(unsafe.Add(a1, 16)))
	if v2 != 0 && nox_xxx_testUnitBuffs_4FF350((*server.Object)(v2), 8) != 0 {
		return 1
	}
	if *(*uint32)(unsafe.Add(a1, 68))-7 == gameFrame() && *(*uint32)(unsafe.Add(a1, 76)) != 0 {
		nox_xxx_delayedDeleteObject_4E5CC0((*server.Object)(*(*unsafe.Pointer)(unsafe.Add(a1, 76))))
		*(*uint32)(unsafe.Add(a1, 76)) = 0
	}
	if *(*uint32)(unsafe.Add(a1, 68))-1 == gameFrame() {
		v4 = (*float32)(unsafe.Pointer(nox_xxx_newObjectByTypeID_4E3810(internCStr("DeathBall"))))
		if v4 != nil {
			if *(*uint32)(unsafe.Add(a1, 20)) != 0 {
				v5 = *(*float32)(unsafe.Add(a1, 28))
				v6 = *(*float32)(unsafe.Add(a1, 32))
				v7 = int16(*(*uint16)(unsafe.Add(a1, 72)))
				v13 = *(*float32)(unsafe.Add(a1, 28))
				v8 = 0.0
				v14 = *(*float32)(unsafe.Add(a1, 32))
			} else {
				v9 = int32(*(*uint32)(unsafe.Add(a1, 16)))
				v5 = *(*float32)(unsafe.Add(v9, 56))
				v6 = *(*float32)(unsafe.Add(v9, 60))
				v7 = int16(*(*uint16)(unsafe.Add(v9, 124)))
				v13 = *(*float32)(unsafe.Add(v9, 56))
				v14 = *(*float32)(unsafe.Add(v9, 60))
				switch *(*uint32)(unsafe.Add(v9, 172)) {
				case 1:
					v8 = 4.0
				case 2:
					v8 = float64(*(*float32)(unsafe.Add(v9, 176))) + 4.0
				case 3:
					if float64(*(*float32)(unsafe.Add(v9, 184))) <= float64(*(*float32)(unsafe.Add(v9, 188))) {
						v8 = float64(*(*float32)(unsafe.Add(v9, 188))) + 4.0
					} else {
						v8 = float64(*(*float32)(unsafe.Add(v9, 184))) + 4.0
					}
				default:
					v8 = 24.0
				}
			}
			v10 = int32(v7) * 8
			v15.field_4 = v6
			v16 = *mem_getFloatPtr(0x587000, uint32(v10)+194136)
			v12 = *mem_getFloatPtr(0x587000, uint32(v10)+194140)
			v15.field_0 = v5
			v15.field_8 = float32(float64(v16)*v8 + float64(v13))
			v15.field_C = float32(float64(v12)*v8 + float64(v14))
			if nox_xxx_mapTraceRay_535250(&v15, nil, nil, 5) == 0 {
				v15.field_8 = v15.field_0
				v15.field_C = v15.field_4
			}
			nox_xxx_createAt_4DAA50((*server.Object)(unsafe.Pointer(v4)), (*server.Object)(*(*unsafe.Pointer)(unsafe.Add(v1, 16))), v15.field_8, v15.field_C)
			if *(*uint32)(unsafe.Add(v1, 20)) == 1 {
				*(*float32)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(float32(0))*20)) = 0.0
				*(*float32)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(float32(0))*21)) = 0.0
			} else {
				*(*float32)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(float32(0))*20)) = v16 * *(*float32)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(float32(0))*136))
				*(*float32)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(float32(0))*21)) = v12 * *(*float32)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(float32(0))*136))
			}
			*((*uint16)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(uint16(0))*62))) = uint16(v7)
			*((*uint16)(unsafe.Add(unsafe.Pointer(v4), unsafe.Sizeof(uint16(0))*63))) = uint16(v7)
			nox_xxx_aud_501960(38, (*server.Object)(*(*unsafe.Pointer)(unsafe.Add(v1, 16))), 0, 0)
		}
		result = 1
	} else {
		if *(*uint32)(unsafe.Add(a1, 20)) == 0 {
			v11 = int32(*(*uint32)(unsafe.Add(a1, 16)))
			if v11 != 0 {
				if int32(*(*uint8)(unsafe.Add(v11, 8)))&4 != 0 {
					nox_xxx_playerSetState_4FA020((*server.Object)(v11), 10)
				}
			}
		}
		result = 0
	}
	return result
}
func Sub_52F1D0(sp *server.DurSpell) int32 {
	a1 := int32(uintptr(sp.C()))
	var result int32
	if *(*uint32)(unsafe.Add(a1, 76)) != 0 {
		nox_xxx_delayedDeleteObject_4E5CC0((*server.Object)(*(*unsafe.Pointer)(unsafe.Add(a1, 76))))
	}
	result = int32(*(*uint32)(unsafe.Add(a1, 16)))
	if result != 0 {
		if int32(*(*uint8)(unsafe.Add(result, 8)))&4 != 0 {
			result = int32(*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(result, 748)), 104)))
			if result != 0 {
				if *(*uint32)(unsafe.Add(result, 12))&0x200000 != 0 {
					result = int32(*(*uint32)(unsafe.Add(result, 736)))
					*(*uint32)(unsafe.Add(result, 96)) &= 0xFFFFFFFB
				}
			}
		}
	}
	return result
}
func Sub_52F220(sp *server.DurSpell) int32 {
	a1 := (*int32)(sp.C())
	var (
		v1     int32
		result int32
		v3     int32
		v4     int32
		v5     int32
		v6     int32
		v7     int32
	)
	v1 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*5))
	if *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*4)) == 0 {
		if v1 == 0 {
			return 1
		}
		v3 = int32(nox_xxx_spellFlags_424A70(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1))))
		v4 = int32(uintptr(unsafe.Pointer(nox_xxx_spellFlySearchTarget_540610((*types.Pointf)(unsafe.Add(unsafe.Pointer(a1), 4*13)), nil, v3, 400.0, 1, nil))))
		if v4 != 0 {
			nox_xxx_unitAdjustHP_4EE460((*server.Object)(v4), 20)
		}
		return 1
	}
	if v1 != 0 {
		v3 = int32(nox_xxx_spellFlags_424A70(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1))))
		v4 = int32(uintptr(unsafe.Pointer(nox_xxx_spellFlySearchTarget_540610((*types.Pointf)(unsafe.Add(unsafe.Pointer(a1), 4*13)), nil, v3, 400.0, 1, nil))))
		if v4 != 0 {
			nox_xxx_unitAdjustHP_4EE460((*server.Object)(v4), 20)
		}
		return 1
	}
	v7 = *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*4))
	v5 = int32(nox_xxx_spellFlags_424A70(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1))))
	v6 = int32(uintptr(unsafe.Pointer(nox_xxx_spellFlySearchTarget_540610((*types.Pointf)(unsafe.Add(unsafe.Pointer(a1), 4*13)), (*server.Object)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*4))), v5, 400.0, 1, (*server.Object)(v7)))))
	*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*12)) = v6
	if v6 != 0 {
		result = nox_xxx_unitIsEnemyTo_5330C0((*server.Object)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*4))), (*server.Object)(v6))
		if result == 0 {
			nox_xxx_netStartDurationRaySpell_4FF130(unsafe.Pointer(a1))
			result = 0
		}
	} else {
		nox_xxx_netPriMsgToPlayer_4DA2C0((*server.Object)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*4))), internCStr("ExecDur.c:GreaterHealNoTarget"), 0)
		result = 1
	}
	return result
}
func Sub_52F2E0(sp *server.DurSpell) int32 {
	a1 := int32(uintptr(sp.C()))
	var (
		v1  int32
		v2  int32
		v4  int32
		v5  int32
		v6  int16
		v7  int32
		v8  int8
		v9  float64
		v10 int32
		v11 float32
	)
	v1 = a1
	v2 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0))))), 48)))
	if v2 == 0 {
		return 1
	}
	if *(*uint32)(unsafe.Add(v2, 16))&0x8020 != 0 {
		return 1
	}
	v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0))))), 16)))
	if v4 != 0 && nox_xxx_testUnitBuffs_4FF350((*server.Object)(v4), 8) != 0 {
		return 1
	}
	if nox_xxx_unitCanInteractWith_5370E0((*server.Object)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0))))), 16))), (*server.Object)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0))))), 48))), 0) == 0 {
		return 1
	}
	if int32(nox_xxx_unitGetOldMana_4EEC80(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0))))), 16)))) == 0 {
		return 1
	}
	v5 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0))))), 16)))
	if int32(*(*uint8)(unsafe.Add(v5, 8)))&2 != 0 && sub_4FEA70(v5, (*types.Pointf)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0))))), 28))) != 0 {
		return 1
	}
	if sub_4E6BD0(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0))))), 16)))) != 0 {
		return 1
	}
	v6 = nox_xxx_unitGetMaxHP_4EE7A0(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0))))), 48)))
	if int32(v6) == int32(nox_xxx_unitGetHP_4EE780((*server.Object)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0))))), 48))))) {
		return 1
	}
	v7 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0))))), 16)))
	v11 = *(*float32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0))))), 72)) + *mem_getFloatPtr(0x587000, *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0))))), 8))*4+260360)
	if v7 != 0 && int32(*(*uint8)(unsafe.Add(v7, 8)))&4 != 0 {
		v8 = int8(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v7, 748)), 276)), 2251)))
		switch v8 {
		case 0:
			v9 = float64(nox_xxx_warriorMaxHealth_587000_312784)
			v11 = float32(v9 * float64(v11))
		case 2:
			v9 = float64(nox_xxx_conjurerMaxHealth_587000_312800)
			v11 = float32(v9 * float64(v11))
		case 1:
			v9 = float64(nox_xxx_wizardMaxHealth_587000_312816)
			v11 = float32(v9 * float64(v11))
		}
	}
	*(*float32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&v1), 4*0))))), 72)) = float32(float64(v11) - float64(int32(v11)))
	v10 = int32(v11)
	nox_xxx_unitAdjustHP_4EE460((*server.Object)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&v1), 4*0))))), 48))), v10)
	nox_xxx_playerManaSub_4EEBF0(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&v1), 4*0))))), 16)), 1)
	return 0
}
func Sub_52F460(sp *server.DurSpell) int32 {
	a1 := int32(uintptr(sp.C()))
	var (
		v1     int32
		v2     int32
		result int32
		v4     int32
		v5     int32
		v6     int16
		v7     int16
		v8     float32
		v9     float32
	)
	v1 = a1
	v2 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0))))), 48)))
	if v2 == 0 {
		return 1
	}
	if *(*uint32)(unsafe.Add(v2, 16))&0x8020 != 0 {
		return 1
	}
	if *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0))))), 20)) != 0 {
		nox_xxx_playerManaAdd_4EEB80((*server.Object)(v2), 20)
		nox_xxx_unitDamageClear_4EE5E0((*server.Object)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0))))), 48))), 20)
		result = 1
	} else {
		v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0))))), 16)))
		if v4 != 0 && nox_xxx_testUnitBuffs_4FF350((*server.Object)(v4), 8) != 0 {
			result = 1
		} else {
			v5 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0))))), 48)))
			if int32(*(*uint8)(unsafe.Add(v5, 8)))&2 != 0 && sub_4FEA70(v5, (*types.Pointf)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0))))), 28))) != 0 {
				result = 1
			} else {
				v6 = nox_xxx_playerGetMaxMana_4EECB0(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0))))), 48)))
				if int32(v6) == int32(nox_xxx_unitGetOldMana_4EEC80(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0))))), 48)))) {
					result = 1
				} else if int32(uint16(nox_xxx_unitGetHP_4EE780((*server.Object)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0))))), 16)))))) > 1 {
					if int32(nox_xxx_unitGetHP_4EE780((*server.Object)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0))))), 16))))) != 0 {
						v8 = *(*float32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&a1), 4*0))))), 72))
						v9 = float32(nox_xxx_gamedataGetFloatTable_419D70(internCStr("ChannelLifeCoeff"), int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&v1), 4*0))))), 8))-1)) + float64(v8))
						*(*float32)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&v1), 4*0))))), 72)) = float32(float64(v9) - float64(int32(v9)))
						v7 = int16(int32(v9))
						nox_xxx_playerManaAdd_4EEB80((*server.Object)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&v1), 4*0))))), 48))), v7)
						nox_xxx_unitDamageClear_4EE5E0((*server.Object)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(uintptr((*(*uint32)(unsafe.Add(unsafe.Pointer(&v1), 4*0))))), 16))), 1)
					}
					result = 0
				} else {
					result = 1
				}
			}
		}
	}
	return result
}
func Nox_xxx_castShield1_52F5A0(sp *server.DurSpell) int32 {
	a1 := (*uint32)(sp.C())
	var (
		v1 int32
		v3 int32
		v4 int32
		v5 float32
		v6 float32
	)
	v1 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*12)))
	if v1 == 0 {
		return 1
	}
	if *(*uint32)(unsafe.Add(v1, 16))&0x8020 != 0 {
		return 1
	}
	if *(*uint32)(unsafe.Add(v1, 8))&2 != 0 && int32(*(*uint8)(unsafe.Add(v1, 12)))&4 != 0 {
		return 1
	}
	if (*(*uint32)(unsafe.Add(v1, 8))&4) == 0 && (*(*uint32)(unsafe.Add(v1, 8))&2) == 0 {
		return 1
	}
	v5 = float32(nox_xxx_gamedataGetFloatTable_419D70(internCStr("ShieldDuration"), int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*2))-1)))
	v3 = int32(v5)
	nox_xxx_buffApplyTo_4FF380((*server.Object)(*(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(a1), 4*12))), 26, int16(v3), int8(uint8(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*2)))))
	v4 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*2)) - 1)
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*17)) = uint32(v3) + gameFrame()
	v6 = float32(nox_xxx_gamedataGetFloatTable_419D70(internCStr("ShieldHealth"), v4))
	*(*uint32)(unsafe.Add(unsafe.Pointer(a1), 4*18)) = uint32(int32(v6))
	return 0
}
func Sub_52F650(sp *server.DurSpell) int32 {
	a1 := int32(uintptr(sp.C()))
	var (
		v1     int32
		result int32
	)
	v1 = int32(*(*uint32)(unsafe.Add(a1, 48)))
	if v1 != 0 {
		result = bool2int32((*(*uint32)(unsafe.Add(v1, 16)) & 0x8020) != 0)
	} else {
		result = 1
	}
	return result
}
func Sub_52F670(sp *server.DurSpell) int32 {
	a1 := int32(uintptr(sp.C()))
	var result int32
	result = int32(*(*uint32)(unsafe.Add(a1, 48)))
	if result != 0 {
		result = nox_xxx_spellBuffOff_4FF5B0((*server.Object)(result), 26)
	}
	return result
}
func nox_xxx_unitShield_52F690(a1 unsafe.Pointer, a2 int32) {
	v2 := (*uint32)(nox_xxx_spellCastedFirst_4FE930())
	if v2 != nil {
		for *(*unsafe.Pointer)(unsafe.Add(unsafe.Pointer(v2), 4*12)) != a1 || *(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*1)) != 51 {
			v2 = (*uint32)(nox_xxx_spellCastedNext_4FE940(unsafe.Pointer(v2)))
			if v2 == nil {
				nox_xxx_spellBuffOff_4FF5B0((*server.Object)(a1), 26)
				return
			}
		}
		v3 := int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*12)))
		if v3 != 0 {
			if *(*uint32)(unsafe.Add(v3, 16))&0x8020 != 0 {
				*((*uint8)(unsafe.Pointer(&v2))) = uint8(nox_xxx_spellCancelSpellDo_4FE9D0(unsafe.Pointer(v2)))
			} else if int32(*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*18)))-a2 > 0 {
				*(*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*18)) -= uint32(a2)
			} else {
				nox_xxx_spellCancelSpellDo_4FE9D0(unsafe.Pointer(v2))
			}
		} else {
			nox_xxx_spellCancelSpellDo_4FE9D0(unsafe.Pointer(v2))
		}
	} else {
		nox_xxx_spellBuffOff_4FF5B0((*server.Object)(a1), 26)
	}
}
func nox_xxx_unitShieldReduceDamage_52F710(a1 unsafe.Pointer, a2 *int32, a3 int32, a4 unsafe.Pointer) {
	var (
		v4 int32
		v5 int32
	)
	if a1 != nil && a2 != nil {
		nox_xxx_aud_501960(131, (*server.Object)(a1), 0, 0)
		if a4 != nil {
			nox_xxx_netSendShieldFx_523670(a1, (*float32)(unsafe.Add(a4, 56)))
		} else {
			nox_xxx_netSendShieldFx_523670(a1, nil)
		}
		v4 = *a2
		if int32(uint16(nox_xxx_unitGetHP_4EE780((*server.Object)(a1)))) > v4 {
			*a2 = v4 / 2
			if (v4 / 2) == 0 {
				*a2 = 1
			}
			nox_xxx_unitShield_52F690(a1, *a2)
		} else {
			if int32(*(*uint8)(unsafe.Add(a1, 8)))&4 != 0 && (func() bool {
				v5 = int32(*(*uint32)(unsafe.Add(a1, 748)))
				return int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v5, 276)), 2251))) == 0
			}()) && int32(*(*uint8)(unsafe.Add(v5, 88))) == 16 && a4 != nil && nox_server_testTwoPointsAndDirection_4E6E50((*types.Pointf)(unsafe.Add(a1, 56)), int32(*(*int16)(unsafe.Add(a1, 124))), (*types.Pointf)(unsafe.Add(a4, 72)))&1 != 0 {
				*a2 = 1
			} else {
				nox_xxx_unitSetHP_4E4560((*server.Object)(a1), 2)
				*a2 = 0
			}
			nox_xxx_unitShield_52F690(a1, 999999)
			*(*unsafe.Pointer)(unsafe.Add(a1, 520)) = a4
			*(*uint32)(unsafe.Add(a1, 524)) = uint32(a3)
			*(*uint32)(unsafe.Add(a1, 536)) = gameFrame()
		}
	}
}
func Nox_xxx_onStartLightning_52F820(sp *server.DurSpell) int32 {
	a1 := int32(uintptr(sp.C()))
	var (
		v1 int32
		v2 int32
	)
	*(*uint32)(unsafe.Add(a1, 72)) = 0
	*(*uint32)(unsafe.Add(a1, 76)) = 0
	if *(*uint32)(unsafe.Add(a1, 16)) != 0 {
		nox_xxx_spellCancelDurSpell_4FEB10(24, (*server.Object)(*(*unsafe.Pointer)(unsafe.Add(a1, 16))))
	}
	if *(*uint32)(unsafe.Add(a1, 20)) == 0 {
		v1 = int32(*(*uint32)(unsafe.Add(a1, 16)))
		if int32(*(*uint8)(unsafe.Add(v1, 8)))&4 != 0 {
			v2 = int32(*(*uint32)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v1, 748)), 104)))
			if v2 != 0 {
				if *(*uint32)(unsafe.Add(v2, 12))&0x40000 != 0 && int32(*(*uint8)(unsafe.Add(*(*unsafe.Pointer)(unsafe.Add(v2, 736)), 96)))&4 != 0 {
					*(*uint32)(unsafe.Add(a1, 72)) = uint32(v2)
				}
			}
		}
	}
	if *(*uint32)(unsafe.Add(a1, 72)) != 0 {
		*(*uint8)(unsafe.Add(a1, 88)) |= 2
	}
	nox_xxx_netSendPointFx_522FF0(-127, (*types.Pointf)(unsafe.Add(a1, 28)))
	return 0
}
