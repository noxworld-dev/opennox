package legacy

import (
	"image"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/internal/binfile"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
)

func sub_4BC490(dr *client.Drawable) int8 {
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
	if !((int32(uint8(gameFrame()))&3) == 0 && dr.AnimInd == 8 && dr.ObjSubClass&0x40000 != 0) {
		return int8(v1)
	}
	v2 = dr.AnimFrameSlave
	v3 = int32(dr.AnimFrameSlave)
	if v3 != 0 {
		v4 = v3 - 2
		if v4 != 0 {
			if v4 == 2 {
				v1 = nox_common_randomIntMinMax_415FF0(0, 100, internCStr("C:\\NoxPost\\src\\Client\\Draw\\mondraw.c"), 74)
				if v1 < 15 {
					v5 = int32(dr.AnimFrameSlave)
					dr.Field_74_4 = 0
					v1 = v5 - 1
					dr.AnimFrameSlave = uint32(v1)
				}
			} else {
				*((*uint8)(unsafe.Pointer(&v1))) = dr.Field_74_4
				switch uint8(int8(v1)) {
				case 0:
					if v2 < 2 {
						dr.AnimFrameSlave = v2 + 1
						return int8(v1)
					}
					dr.AnimFrameSlave = v2 - 1
					return int8(v1)
				case 1:
					dr.AnimFrameSlave = v2 - 1
					return int8(v1)
				case 2:
					dr.AnimFrameSlave = v2 + 1
				default:
					dr.AnimFrameSlave = 2
					dr.Field_74_4 = 0
				}
			}
		} else {
			v1 = nox_common_randomIntMinMax_415FF0(0, 100, internCStr("C:\\NoxPost\\src\\Client\\Draw\\mondraw.c"), 52)
			if v1 >= 5 {
				if v1 < 10 {
					v7 = int32(dr.AnimFrameSlave)
					dr.Field_74_4 = 2
					v1 = v7 + 1
					dr.AnimFrameSlave = uint32(v1)
				}
			} else {
				v6 = int32(dr.AnimFrameSlave)
				dr.Field_74_4 = 1
				v1 = v6 - 1
				dr.AnimFrameSlave = uint32(v1)
			}
		}
	} else {
		v1 = nox_common_randomIntMinMax_415FF0(0, 100, internCStr("C:\\NoxPost\\src\\Client\\Draw\\mondraw.c"), 66)
		if v1 < 15 {
			v8 = int32(dr.AnimFrameSlave)
			dr.Field_74_4 = 0
			v1 = v8 + 1
			dr.AnimFrameSlave = uint32(v1)
		}
	}
	return int8(v1)
}
func nox_thing_monster_draw(vp *noxrender.Viewport, dr *client.Drawable) int {
	res := 1
	dd := (*client.MonsterDrawData)(dr.DrawData)
	if !noxflags.HasGame(0x200000) {
		v4 := int8(dr.Field_108_0)
		if int32(dr.AnimDir) != int32(v4) {
			v5 := int32(dr.AnimInd)
			if v5 != 1 && v5 != 3 && v5 != 5 {
				if (gameFrame() - uint32(dr.Field_109)) >= uint32(int32(gameFPS())>>2) {
					dr.Field_109 = uintptr(gameFrame())
					dr.Field_108_0 = dr.AnimDir
				} else {
					dr.AnimDir = uint8(v4)
				}
			}
		}
	}
	v6 := int32(*memmap.PtrUint32(0x5D4594, 1316536))
	if *memmap.PtrUint32(0x5D4594, 1316536) == 0 {
		v6 = nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("Ghost"))
		*memmap.PtrUint32(0x5D4594, 1316536) = uint32(v6)
	}
	ani := &dd.Anim[dr.AnimInd]
	if int32(ani.Cnt40) == 0 {
		return 1
	}
	if dr.Field_27 == uint32(v6) {
		var v10, v11 int32
		if noxflags.HasGame(0x200000) {
			v10 = 0
			v11 = 0
		} else {
			v10 = int32(dr.PosVec.X - int((*memmap.PtrT[*client.Drawable](0x852978, 8)).PosVec.X))
			v11 = int32(dr.PosVec.Y - int((*memmap.PtrT[*client.Drawable](0x852978, 8)).PosVec.Y))
		}
		if *memmap.PtrT[*client.Drawable](0x852978, 8) != nil && nox_client_drawable_testBuff_4356C0(*memmap.PtrT[*client.Drawable](0x852978, 8), 21) {
			nox_xxx_draw_434600(1)
			nox_draw_setColorMultAndIntensity_433E40(*memmap.PtrInt32(0x8531A0, 2572))
			nox_client_drawEnableAlpha_434560(1)
			nox_client_drawSetAlpha_434580(0xff)
		} else {
			if v10*v10+v11*v11 >= 40000 {
				goto LABEL_24
			}
			nox_client_drawEnableAlpha_434560(1)
			nox_client_drawSetAlpha_434580(0)
		}
	}
	sub_4BC490(dr)
	res = sub_4BC6B0(vp, dr, ani)
	nox_xxx_draw_434600(0)
LABEL_24:
	if nox_client_drawable_testBuff_4356C0(dr, 16) {
		var vp2 noxrender.Viewport
		vp2.Screen.Max = image.Point{X: int(nox_win_width), Y: int(nox_win_height)}
		vp2.Size = image.Point{X: int(nox_win_width), Y: int(nox_win_height)}
		if dword_5d4594_1313796 == nil {
			dword_5d4594_1313796 = nox_new_drawable_for_thing(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("SpinningSkull")))
			dword_5d4594_1313796.ObjFlags |= 0x1000000
		}
		dword_5d4594_1313796.PosVec.X = dr.PosVec.X + vp.Screen.Min.X - vp.World.Min.X
		dword_5d4594_1313796.PosVec.Y = dr.PosVec.Y + vp.Screen.Min.Y - vp.World.Min.Y - 50
		dword_5d4594_1313796.DrawFunc.Get()(&vp2, dword_5d4594_1313796)
	}
	if nox_xxx_unitSpriteCheckAlly_4951F0(int32(dr.NetCode32)) != 0 {
		var (
			v21b, v22b uint16
			a2         byte
		)
		sub_495180(int32(dr.NetCode32), &v22b, &v21b, &a2)
		nox_xxx_spriteDrawMonsterHP_4BC080(vp, dr, v22b, v21b, int8(a2))
	}
	if !nox_xxx_CheckGameplayFlags_417DA0(4) && (*memmap.PtrT[*client.Drawable](0x852978, 8) == nil || nox_xxx_servObjectHasTeam_419130((*server.ObjectTeam)(unsafe.Add(unsafe.Pointer(*memmap.PtrT[*client.Drawable](0x852978, 8)), 24))) == 0) {
		nox_client_drawEnableAlpha_434560(0)
		return int(res)
	}
	var tm *server.ObjectTeam
	if !noxflags.HasGame(1) {
		tm = (*memmap.PtrT[*client.Drawable](0x852978, 8)).TeamPtr()
	} else {
		pl := nox_common_playerInfoFromNum_417090(31)
		if pl == nil {
			nox_client_drawEnableAlpha_434560(0)
			return int(res)
		}
		u := pl.PlayerUnit
		if u == nil {
			nox_client_drawEnableAlpha_434560(0)
			return int(res)
		}
		tm = u.TeamPtr()
	}
	if tm != nil {
		v16 := false
		v17 := nox_xxx_getTeamByID_418AB0(int32(tm.ID))
		if v17 != nil && sub_495A80(int32(dr.NetCode32)) != 0 {
			v16 = true
		}
		if (!noxflags.HasGame(4096) || (int32(*(*uint8)(unsafe.Add(unsafe.Pointer(dr), 112)))&2) == 0 || (int32(*(*uint8)(unsafe.Add(unsafe.Pointer(dr), 116)))&8) == 0) && v16 {
			v18 := int32(nox_xxx_materialGetTeamColor_418D50(v17))
			nox_client_drawSetColor_434460(v18)
			v19 := int32(vp.Screen.Min.X + dr.PosVec.X - vp.World.Min.X)
			v20 := int32(dr.PosVec.Y + vp.Screen.Min.Y - int(dr.ZVal) - vp.World.Min.Y - int(dr.ZSizeMax)*2)
			nox_client_drawPoint_4B0BC0(v19, v20, 3)
		}
	}
	nox_client_drawEnableAlpha_434560(0)
	return int(res)
}
func nox_things_monster_draw_parse(obj *client.ObjectType, f *binfile.MemFile, attr_value *byte) bool {
	dd, _ := alloc.New(client.MonsterDrawData{})
	dd.Size = uint32(unsafe.Sizeof(client.MonsterDrawData{}))
	for {
		tok := nox_memfile_read_u32(f)
		if tok == 0x454E4420 {
			break
		}
		ind := nox_memfile_read_u8(f)
		if int(ind) >= len(dd.Anim) {
			return false
		}
		var n uint8
		n = nox_memfile_read_u8(f)
		nox_memfile_skip(f, int32(n))
		n = nox_memfile_read_u8(f)
		nox_memfile_skip(f, int32(n))
		ani := &dd.Anim[ind]
		if !nox_xxx_loadVectorAnimated_44B8B0(ani, f) {
			return false
		}
		if !nox_xxx_loadVectorAnimated_44BC50(ani, f) {
			return false
		}
	}
	obj.DrawFunc.Set(nox_thing_monster_draw)
	obj.DrawData = unsafe.Pointer(dd)
	return true
}
