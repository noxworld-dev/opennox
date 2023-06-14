package legacy

import (
	"math"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/internal/binfile"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
	"github.com/noxworld-dev/opennox/v1/server"
)

func sub_4BC490(a1 int32) int8 {
	var (
		v1 int32
		v2 uint32
		v3 int32
		v4 int32
		v5 int32
		v6 int32
		v7 int32
		v8 int32
	)
	*((*uint8)(unsafe.Pointer(&v1))) = uint8(gameFrame())
	if (int32(uint8(gameFrame()))&3) == 0 && *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 276)) == 8 && *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 116))&0x40000 != 0 {
		v2 = *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 308))
		v3 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 308)))
		if v3 != 0 {
			v4 = v3 - 2
			if v4 != 0 {
				if v4 == 2 {
					v1 = nox_common_randomIntMinMax_415FF0(0, 100, internCStr("C:\\NoxPost\\src\\Client\\Draw\\mondraw.c"), 74)
					if v1 < 15 {
						v5 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 308)))
						*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 299)) = 0
						v1 = v5 - 1
						*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 308)) = uint32(v1)
					}
				} else {
					*((*uint8)(unsafe.Pointer(&v1))) = *(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 299))
					switch uint8(int8(v1)) {
					case 0:
						if v2 < 2 {
							*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 308)) = v2 + 1
							return int8(v1)
						}
						*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 308)) = v2 - 1
						return int8(v1)
					case 1:
						*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 308)) = v2 - 1
						return int8(v1)
					case 2:
						*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 308)) = v2 + 1
					default:
						*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 308)) = 2
						*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 299)) = 0
					}
				}
			} else {
				v1 = nox_common_randomIntMinMax_415FF0(0, 100, internCStr("C:\\NoxPost\\src\\Client\\Draw\\mondraw.c"), 52)
				if v1 >= 5 {
					if v1 < 10 {
						v7 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 308)))
						*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 299)) = 2
						v1 = v7 + 1
						*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 308)) = uint32(v1)
					}
				} else {
					v6 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 308)))
					*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 299)) = 1
					v1 = v6 - 1
					*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 308)) = uint32(v1)
				}
			}
		} else {
			v1 = nox_common_randomIntMinMax_415FF0(0, 100, internCStr("C:\\NoxPost\\src\\Client\\Draw\\mondraw.c"), 66)
			if v1 < 15 {
				v8 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 308)))
				*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 299)) = 0
				v1 = v8 + 1
				*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(a1)), 308)) = uint32(v1)
			}
		}
	}
	return int8(v1)
}
func nox_thing_monster_draw(vp *noxrender.Viewport, dr *client.Drawable) int {
	a1 := (*int32)(vp.C())
	var (
		v2  int32
		v3  int32
		v4  int8
		v5  int32
		v6  int32
		v7  int32
		v8  int32
		v10 int32
		v11 int32
		v12 *int32
		v13 *byte
		v14 int32
		v15 int32
		v16 int32
		v17 *byte
		v18 int32
		v19 int32
		v20 int32
		v21 int32
		v22 int32
		v23 int32
		a2  int32 = int32(uintptr(unsafe.Pointer(dr)))
	)
	v2 = int32(uintptr(unsafe.Pointer(dr)))
	v23 = 1
	v3 = int32(*(*uint32)(unsafe.Pointer(&dr.Field_76)))
	if !noxflags.HasGame(0x200000) {
		v4 = int8(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v2)), 432)))
		if int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v2)), 297))) != int32(v4) {
			v5 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v2)), 276)))
			if v5 != 1 && v5 != 3 && v5 != 5 {
				if (gameFrame() - *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v2)), 436))) >= uint32(int32(gameFPS())>>2) {
					*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v2)), 436)) = gameFrame()
					*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v2)), 432)) = *(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v2)), 297))
				} else {
					*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v2)), 297)) = uint8(v4)
				}
			}
		}
	}
	v6 = int32(*memmap.PtrUint32(0x5D4594, 1316536))
	if *memmap.PtrUint32(0x5D4594, 1316536) == 0 {
		v6 = nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("Ghost"))
		*memmap.PtrUint32(0x5D4594, 1316536) = uint32(v6)
	}
	v7 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v2)), 276)) * 48)
	v8 = v7 + v3 + 4
	if int32(*(*uint16)(unsafe.Add(unsafe.Pointer(uintptr(v7+v3)), 44))) == 0 {
		return 1
	}
	if *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v2)), 108)) != uint32(v6) {
		goto LABEL_22
	}
	if noxflags.HasGame(0x200000) {
		v10 = 0
		v11 = 0
	} else {
		v10 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v2)), 12)) - *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*memmap.PtrUint32(0x852978, 8))), 12)))
		v11 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v2)), 16)) - *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(*memmap.PtrUint32(0x852978, 8))), 16)))
	}
	if *memmap.PtrUint32(0x852978, 8) != 0 && nox_client_drawable_testBuff_4356C0((*client.Drawable)(unsafe.Pointer(uintptr(*memmap.PtrInt32(0x852978, 8)))), 21) {
		nox_xxx_draw_434600(1)
		nox_draw_setColorMultAndIntensity_433E40(*memmap.PtrInt32(0x8531A0, 2572))
		*((*uint8)(unsafe.Pointer(&a2))) = math.MaxUint8
	} else {
		if v10*v10+v11*v11 < 40000 {
			goto LABEL_21
		}
		v12 = a1
		goto LABEL_24
	}
LABEL_21:
	nox_client_drawEnableAlpha_434560(1)
	nox_client_drawSetAlpha_434580(uint8(int8(a2)))
LABEL_22:
	sub_4BC490(v2)
	v12 = a1
	v23 = int32(sub_4BC6B0(a1, (*client.Drawable)(unsafe.Pointer(uintptr(v2))), v8))
	nox_xxx_draw_434600(0)
LABEL_24:
	if nox_client_drawable_testBuff_4356C0(dr, 16) {
		var v36 [13]int32 = [13]int32{}
		v36[0] = 0
		v36[1] = 0
		v36[2] = nox_win_width
		v36[3] = nox_win_height
		v36[4] = 0
		v36[5] = 0
		v36[8] = nox_win_width
		v36[9] = nox_win_height
		if dword_5d4594_1313796 == nil {
			dword_5d4594_1313796 = unsafe.Pointer(nox_new_drawable_for_thing(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("SpinningSkull"))))
			*(*uint32)(unsafe.Add(dword_5d4594_1313796, 120)) |= 0x1000000
		}
		*(*uint32)(unsafe.Add(dword_5d4594_1313796, 12)) = uint32(int32(dr.PosVec.X) + *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*0)) - *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*4)))
		*(*uint32)(unsafe.Add(dword_5d4594_1313796, 16)) = uint32(int32(dr.PosVec.Y) + *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*1)) - *(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*5)) - 50)
		ccall.AsFunc[func(*int32, unsafe.Pointer)](*(*unsafe.Pointer)(unsafe.Add(dword_5d4594_1313796, 300)))(&v36[0], dword_5d4594_1313796)
	}
	if nox_xxx_unitSpriteCheckAlly_4951F0(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v2)), 128)))) != 0 {
		v22 = 0
		v21 = 0
		*((*uint8)(unsafe.Pointer(&a2))) = 0
		sub_495180(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v2)), 128))), (*uint16)(unsafe.Pointer(&v22)), (*uint16)(unsafe.Pointer(&v21)), (*uint8)(unsafe.Pointer(&a2)))
		nox_xxx_spriteDrawMonsterHP_4BC080((*uint32)(unsafe.Pointer(v12)), v2, uint16(int16(v22)), uint16(int16(v21)), int8(a2))
	}
	if !nox_xxx_CheckGameplayFlags_417DA0(4) && (*memmap.PtrUint32(0x852978, 8) == 0 || nox_xxx_servObjectHasTeam_419130(unsafe.Add(*memmap.PtrPtr(0x852978, 8), 24)) == 0) {
		nox_client_drawEnableAlpha_434560(0)
		return int(v23)
	}
	if !noxflags.HasGame(1) {
		v15 = int32(*memmap.PtrUint32(0x852978, 8) + 24)
	} else {
		v13 = (*byte)(unsafe.Pointer(nox_common_playerInfoFromNum_417090(31)))
		if v13 == nil {
			nox_client_drawEnableAlpha_434560(0)
			return int(v23)
		}
		v14 = int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v13), 4*514))))
		if v14 == 0 {
			nox_client_drawEnableAlpha_434560(0)
			return int(v23)
		}
		v15 = v14 + 48
	}
	if v15 == 0 {
		nox_client_drawEnableAlpha_434560(0)
		return int(v23)
	}
	v16 = 0
	v17 = (*byte)(unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v15)), 4))))))
	if v17 != nil && sub_495A80(int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v2)), 128)))) != 0 {
		v16 = 1
	}
	if (!noxflags.HasGame(4096) || (int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v2)), 112)))&2) == 0 || (int32(*(*uint8)(unsafe.Add(unsafe.Pointer(uintptr(v2)), 116)))&8) == 0) && v16 != 0 {
		v18 = int32(nox_xxx_materialGetTeamColor_418D50((*server.Team)(unsafe.Pointer(v17))))
		nox_client_drawSetColor_434460(v18)
		v19 = int32(uint32(*v12) + *(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v2)), 12)) - uint32(*(*int32)(unsafe.Add(unsafe.Pointer(v12), 4*4))))
		v20 = int32(*(*uint32)(unsafe.Add(unsafe.Pointer(uintptr(v2)), 16)) + uint32(*(*int32)(unsafe.Add(unsafe.Pointer(v12), 4*1))) - uint32(*(*int16)(unsafe.Add(unsafe.Pointer(uintptr(v2)), 104))) - uint32(*(*int32)(unsafe.Add(unsafe.Pointer(a1), 4*5))) - uint32(int32(*(*float32)(unsafe.Add(unsafe.Pointer(uintptr(v2)), 100)))*2))
		nox_client_drawPoint_4B0BC0(v19, v20, 3)
	}
	nox_client_drawEnableAlpha_434560(0)
	return int(v23)
}
func nox_things_monster_draw_parse(obj *client.ObjectType, f *binfile.MemFile, attr_value *byte) bool {
	var (
		v2 *uint32
		v4 int32
		v6 uint8
		v9 int32
	)
	v2 = (*uint32)(alloc.Calloc1(1, 0x304))
	*v2 = 772
	for {
		v4 = int32(nox_memfile_read_u32(f))
		if uint32(v4) == 0x454E4420 {
			break
		}
		v6 = nox_memfile_read_u8(f)
		if int32(v6) < 0x10 {
			var n uint8
			n = nox_memfile_read_u8(f)
			nox_memfile_skip(f, int32(n))
			n = nox_memfile_read_u8(f)
			nox_memfile_skip(f, int32(n))
			v9 = int32(uintptr(unsafe.Pointer((*uint32)(unsafe.Add(unsafe.Pointer(v2), 4*uintptr(int32(v6)*12+1))))))
			if nox_xxx_loadVectorAnimated_44B8B0(v9, f) != 0 {
				if nox_xxx_loadVectorAnimated_44BC50(v9, f) != 0 {
					continue
				}
			}
		}
		return false
	}
	obj.DrawFunc.Set(nox_thing_monster_draw)
	obj.Field_5c = unsafe.Pointer(v2)
	return true
}
