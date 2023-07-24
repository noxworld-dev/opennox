package legacy

import (
	"math"
	"unsafe"

	"github.com/gotranspile/cxgo/runtime/libc"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/internal/binfile"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
)

func nox_thing_player_draw(vp *noxrender.Viewport, dr *client.Drawable) int {
	a1p := vp
	var (
		v3  *byte
		v4  *server.ObjectTeam
		v5  *byte
		v6  *server.ObjectTeam
		v7  *server.ObjectTeam
		v8  *server.ObjectTeam
		v9  uint8
		v11 *client.Drawable
		v13 int32
		v14 int32
		v15 *uint32
	)
	var v18 int32
	var v20 int8
	var v21 *int16
	var v22 int32
	var v23 int32
	var v26 int32
	var v27 int32
	var v28 unsafe.Pointer
	var v29 *byte
	var v30 int32
	var v31 int32
	var v32 *byte
	var v34 int32
	var v35 int32
	var v36 [unsafe.Sizeof(noxrender.Viewport{})]int32
	v26 = int32(dr.Field_32)
	v31 = 0
	v30 = 0
	v29 = nil
	v3 = (*byte)(unsafe.Pointer(nox_common_playerInfoGetByID_417040(v26)))
	v32 = v3
	if v3 == nil {
		return 1
	}
	if *memmap.PtrUint32(0x8531A0, 2576) != 0 && (int32(*(*uint8)(unsafe.Add(*memmap.PtrPtr(0x8531A0, 2576), 3680)))&1) != 0 {
		v30 = 1
	}
	if nox_player_netCode_85319C == dr.Field_32 {
		v4 = nox_xxx_objGetTeamByNetCode_418C80(nox_player_netCode_85319C)
		if v4 != nil {
			v5 = (*byte)(unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(v4.ID))))
			v29 = v5
		}
	} else {
		if *(*byte)(unsafe.Add(unsafe.Pointer(v3), 3680))&1 != 0 {
			return 1
		}
		v6 = nox_xxx_objGetTeamByNetCode_418C80(nox_player_netCode_85319C)
		if v6 != nil {
			v7 = nox_xxx_objGetTeamByNetCode_418C80(dr.Field_32)
			v8 = v7
			if v7 != nil {
				if nox_xxx_servCompareTeams_419150(v6, v7) != 0 {
					v31 = 1
				}
				v5 = (*byte)(unsafe.Pointer(nox_xxx_getTeamByID_418AB0(int32(v8.ID))))
				v29 = v5
			}
		}
	}
	v9 = nox_xxx_getTeamCounter_417DD0()
	v10 := a1p
	v35 = bool2int32(int32(v9) != 0)
	if (*(*byte)(unsafe.Add(unsafe.Pointer(v3), 4)) & 1) != 0 {
		v36[2] = nox_win_width
		v36[8] = nox_win_width
		v11 = dword_5d4594_1313792
		v36[0] = 0
		v36[1] = 0
		v36[3] = nox_win_height
		v36[9] = nox_win_height
		v36[4] = 0
		v36[5] = 0
		if dword_5d4594_1313792 != nil || (func() bool {
			v13 = nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("Flag"))
			v11 = nox_new_drawable_for_thing(v13)
			return (func() *client.Drawable {
				dword_5d4594_1313792 = v11
				return dword_5d4594_1313792
			}()) != nil
		}()) {
			v15 = (*uint32)(unsafe.Add(unsafe.Pointer(v3), 2324))
			for v14 = 0; v14 < 27; v14++ {
				if *v15 == 1 {
					alloc.Memcpy(unsafe.Add(unsafe.Pointer(v11), 4*108), unsafe.Add(unsafe.Pointer(v3), v14*24+2328), 0x14)
					v11 = dword_5d4594_1313792
					v3 = v32
					break
				}
				v15 = (*uint32)(unsafe.Add(unsafe.Pointer(v15), 4*6))
			}
			v11.PosVec.X = dr.PosVec.X - v10.World.Min.X + v10.Screen.Min.X + 15
			dword_5d4594_1313792.PosVec.Y = v10.Screen.Min.Y - v10.World.Min.Y + dr.PosVec.Y - 25
			dword_5d4594_1313792.DrawFunc.Get()((*noxrender.Viewport)(unsafe.Pointer(&v36[0])), dword_5d4594_1313792)
		}
	}
	var colors [6]uint32
	colors[0] = 0
	colors[1] = 0
	colors[2] = 0
	colors[3] = 0
	colors[4] = 0
	colors[5] = 0
	if nox_client_drawable_testBuff_4356C0(dr, 23) {
		if (int32(uint8(gameFrame())) & 1) == 0 {
			for i := int32(0); i < 6; i++ {
				colors[i] = nox_color_blue_2650684
			}
		} else {
			for i := int32(0); i < 6; i++ {
				colors[i] = nox_color_white_2523948
			}
		}
	} else if nox_client_drawable_testBuff_4356C0(dr, 25) {
		for i := int32(0); i < 6; i++ {
			colors[i] = nox_color_blue_2650684
		}
	} else {
		colors[0] = *((*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*574)))
		colors[1] = *((*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*576)))
		colors[2] = *((*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*578)))
		colors[3] = *((*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*577)))
		colors[4] = *((*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*575)))
		colors[5] = *((*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*573)))
		if *((*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*920)))&0x400 != 0 {
			for i := int32(0); i < 6; i++ {
				var (
					r int32 = 0
					g int32 = 0
					b int32 = 0
				)
				nox_draw_splitColor_435280(int16(uint16(colors[i])), (*uint8)(unsafe.Pointer(&r)), (*uint8)(unsafe.Pointer(&g)), (*uint8)(unsafe.Pointer(&b)))
				if g >= 155 {
					g = math.MaxUint8
				} else {
					g += 100
				}
				colors[i] = nox_color_rgb_4344A0(r, g, b)
			}
		}
	}
	nox_draw_setMaterial_4341D0(1, int32(colors[0]))
	nox_draw_setMaterial_4341D0(2, int32(colors[1]))
	nox_draw_setMaterial_4341D0(3, int32(colors[2]))
	nox_draw_setMaterial_4341D0(4, int32(colors[3]))
	nox_draw_setMaterial_4341D0(5, int32(colors[4]))
	nox_draw_setMaterial_4341D0(6, int32(colors[5]))
	v18 = sub_4B8FA0(dr, &v28, &v27)
	if v18 == 0 {
		return 0
	}
	nox_xxx_drawObject_4C4770_draw(v10, dr, v18)
	v20 = int8(dr.Field_74_2)
	if int32(v20) != 1 && int32(v20) != 0 && int32(v20) != 2 && int32(v20) != 3 && int32(v20) != 6 || dr.Field_69 == 37 {
		sub_4B8D40(v10, dr, int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*1)))&2), (*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*581)), v28, v27)
		sub_4B8960(v10, dr, int32(*(*uint32)(unsafe.Pointer(v3))), (*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*743)), v28, v27)
		sub_4B8D40(v10, dr, int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*1)))&^uint32(2)), (*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*581)), v28, v27)
	} else {
		sub_4B8D40(v10, dr, int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*1)))&^uint32(2)), (*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*581)), v28, v27)
		sub_4B8960(v10, dr, int32(*(*uint32)(unsafe.Pointer(v3))), (*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*743)), v28, v27)
		sub_4B8D40(v10, dr, int32(*((*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*1)))&2), (*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*581)), v28, v27)
	}
	if !(v30 != 0 || !nox_client_drawable_testBuff_4356C0(dr, 0) || dr.Field_32 == nox_player_netCode_85319C || *memmap.PtrUint32(0x852978, 8) != 0 && (nox_client_drawable_testBuff_4356C0((*client.Drawable)(*memmap.PtrPtr(0x852978, 8)), 21) || v31 != 0)) {
		return 1
	}
	a1 := nox_color_rgb_4344A0(155, 155, 155)
	if sub_48D830(dr) == 0 && !noxflags.HasGame(2048) {
		v21 = (*int16)(unsafe.Add(unsafe.Pointer(v3), 4704))
		nox_xxx_drawGetStringSize_43F840(nil, (*uint16)(unsafe.Add(unsafe.Pointer(v3), unsafe.Sizeof(uint16(0))*2352)), &v34, nil, 0)
		v22 = int32(v10.Screen.Min.X) + int32(dr.PosVec.X) + v34/(-2) - int32(v10.World.Min.X)
		var a2 int32 = int32(v10.Screen.Min.Y - v10.World.Min.Y + dr.PosVec.Y - 64)
		nox_xxx_drawSetTextColor_434390(*memmap.PtrInt32(0x852978, 4))
		nox_xxx_drawString_43F6E0(nil, (*wchar2_t)(unsafe.Pointer(v21)), v22+1, a2+1)
		nox_xxx_drawSetTextColor_434390(int32(a1))
		if v35 != 0 {
			if v29 != nil {
				v23 = int32(nox_xxx_materialGetTeamColor_418D50((*server.Team)(unsafe.Pointer(v29))))
				nox_xxx_drawSetTextColor_434390(v23)
			}
		}
		nox_xxx_drawString_43F6E0(nil, (*wchar2_t)(unsafe.Pointer(v21)), v22, a2)
		v3 = v32
	}
	if nox_client_drawable_testBuff_4356C0(dr, 16) {
		v36[0] = 0
		v36[1] = 0
		v36[2] = nox_win_width
		v36[3] = nox_win_height
		v36[4] = 0
		v36[5] = 0
		v36[8] = nox_win_width
		v36[9] = nox_win_height
		if dword_5d4594_1313796 == nil {
			dword_5d4594_1313796 = nox_new_drawable_for_thing(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("SpinningSkull")))
			dword_5d4594_1313796.Flags30Val |= 0x1000000
		}
		dword_5d4594_1313796.PosVec.X = dr.PosVec.X + v10.Screen.Min.X - v10.World.Min.X
		dword_5d4594_1313796.PosVec.Y = dr.PosVec.Y + v10.Screen.Min.Y - v10.World.Min.Y - 50
		dword_5d4594_1313796.DrawFunc.Get()((*noxrender.Viewport)(unsafe.Pointer(&v36[0])), dword_5d4594_1313796)
	}
	if nox_client_drawable_testBuff_4356C0(dr, 30) {
		v36[0] = 0
		v36[1] = 0
		v36[2] = nox_win_width
		v36[3] = nox_win_height
		v36[4] = 0
		v36[5] = 0
		v36[8] = nox_win_width
		v36[9] = nox_win_height
		if dword_5d4594_1313800 == nil {
			dword_5d4594_1313800 = nox_new_drawable_for_thing(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("SpinningCrown")))
			dword_5d4594_1313800.Flags30Val |= 0x1000000
		}
		dword_5d4594_1313800.PosVec.X = dr.PosVec.X + v10.Screen.Min.X - v10.World.Min.X
		dword_5d4594_1313800.PosVec.Y = dr.PosVec.Y + v10.Screen.Min.Y - v10.World.Min.Y - 50
		dword_5d4594_1313800.DrawFunc.Get()((*noxrender.Viewport)(unsafe.Pointer(&v36[0])), dword_5d4594_1313800)
	}
	for i := int32(0); i < 6; i++ {
		nox_draw_setMaterial_4341D0(i, int32(nox_color_white_2523948))
	}
	if !(unsafe.Pointer(dr) != *memmap.PtrPtr(0x852978, 8) && nox_xxx_playerGet_470A90() != 0) {
		return 1
	}
	if noxflags.HasGame(4096) {
		nox_xxx_drawOtherPlayerHP_4B8EB0(v10, dr, uint16(*(*byte)(unsafe.Add(unsafe.Pointer(v3), 2282))), int8(uint8((*((*uint32)(unsafe.Add(unsafe.Pointer(v3), 4*920)))>>10)&1)))
	}
	return 1
}
func nox_thing_player_waypoint_draw(vp *noxrender.Viewport, dr *client.Drawable) int {
	a1 := vp
	var (
		v2 int32
		v3 int32
		v4 int32
		v5 int32
		v7 int32
		a2 = dr
	)
	v2 = int32(*memmap.PtrUint32(0x85B3FC, 940))
	nox_xxx_spriteDrawCircleMB_4C32A0(int32(a2.PosVec.X-a1.World.Min.X), int32(a2.PosVec.Y-a1.World.Min.Y), 10, *memmap.PtrInt32(0x85B3FC, 940))
	v3 = int32(a2.PosVec.Y - a1.World.Min.Y)
	v4 = int32(a2.PosVec.X - a1.World.Min.X)
	v5 = int32(uint8(int8(int32(uint8(gameFrame())) * 2)))
	nox_client_drawEnableAlpha_434560(1)
	nox_client_drawSetColor_434460(v2)
	v7 = 5
	for {
		nox_client_drawAddPoint_49F500(v4+*memmap.PtrInt32(0x587000, uintptr(v5*8)+192088)*10/16, v3+*memmap.PtrInt32(0x587000, uintptr(v5*8)+192092)*10/16)
		nox_client_drawAddPoint_49F500(v4+*memmap.PtrInt32(0x587000, uintptr(((v5+102)%256)*8)+192088)*10/16, v3+*memmap.PtrInt32(0x587000, uintptr(((v5+102)%256)*8)+192092)*10/16)
		nox_client_drawLineFromPoints_49E4B0()
		v5 = (v5 + 102) % 256
		v7--
		if v7 == 0 {
			break
		}
	}
	nox_client_drawEnableAlpha_434560(0)
	return 1
}
func nox_things_player_draw_parse(obj *client.ObjectType, f *binfile.MemFile, attr_value *byte) bool {
	var (
		a3  = attr_value
		v3  *uint32
		v5  *uint32
		v7  int32
		v10 int32
		v13 int32
		v14 *uint32
		v15 int32
		v16 int32
		v17 int32
		v18 *uint32
		v19 int32
		v20 *uint32
		v21 *uint32
		v22 uint8
		v23 uint8
	)
	v3 = (*uint32)(alloc.Calloc1(1, 14524))
	v5 = v3
	v21 = v3
	*v3 = 14524
	v7 = int32(nox_memfile_read_u32(f))
	if uint32(v7) == 0x454E4420 {
		return false
	}
LABEL_3:
	v22 = nox_memfile_read_u8(f)
	nox_memfile_read(unsafe.Pointer(a3), 1, int32(v22), f)
	*((*uint8)(unsafe.Add(unsafe.Pointer(a3), v22))) = 0
	v10 = sub_44BB20(a3)
	if v10 < 0 {
		return false
	}
	v11 := unsafe.Add(unsafe.Pointer(v5), 4*uintptr(v10*66+1))
	if nox_xxx_loadVectorAnimated_44B8B0(v11, f) == 0 {
		return false
	}
	for {
		v13 = int32(nox_memfile_read_u32(f))
		if uint32(v13) == 0x454E4420 {
			break
		}
		if uint32(v13) == 0x53544154 {
			v5 = v21
			goto LABEL_3
		}
		v23 = nox_memfile_read_u8(f)
		nox_memfile_read(unsafe.Pointer(a3), 1, int32(v23), f)
		*((*uint8)(unsafe.Add(unsafe.Pointer(a3), v23))) = 0
		if libc.StrCmp(internCStr("NAKED"), a3) == 0 {
			v14 = (*uint32)(alloc.Calloc1(1, 0x28))
			v15 = int32(*(*int16)(unsafe.Add(v11, 40)))
			*(*uint32)(unsafe.Add(v11, 48)) = uint32(uintptr(unsafe.Pointer(v14)))
			v16 = sub_44B940(v14, v15, f)
		} else {
			v17 = nox_xxx_parse_Armor_44BA60(a3)
			if v17 < 0 {
				v19 = sub_44BAC0(a3)
				if v19 < 0 {
					return false
				}
				v20 = (*uint32)(alloc.Calloc1(1, 0x28))
				*(*uint32)(unsafe.Add(v11, v19*4+156)) = uint32(uintptr(unsafe.Pointer(v20)))
				v16 = sub_44B940(v20, int32(*(*int16)(unsafe.Add(v11, 40))), f)
			} else {
				v18 = (*uint32)(alloc.Calloc1(1, 0x28))
				*(*uint32)(unsafe.Add(v11, v17*4+52)) = uint32(uintptr(unsafe.Pointer(v18)))
				v16 = sub_44B940(v18, int32(*(*int16)(unsafe.Add(v11, 40))), f)
			}
		}
		if v16 == 0 {
			return false
		}
	}
	obj.DrawFunc.Set(nox_thing_player_draw)
	obj.Field_5c = unsafe.Pointer(v21)
	return true
}
