package legacy

import (
	"image"
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
	v26 := int32(dr.NetCode32)
	pl := nox_common_playerInfoGetByID_417040(v26)
	if pl == nil {
		return 1
	}
	v30 := false
	if *memmap.PtrUint32(0x8531A0, 2576) != 0 && (int32(*(*uint8)(unsafe.Add(*memmap.PtrPtr(0x8531A0, 2576), 3680)))&1) != 0 {
		v30 = true
	}
	var (
		v31 = false
		tm  *server.Team
	)
	if nox_player_netCode_85319C == dr.NetCode32 {
		if v4 := nox_xxx_objGetTeamByNetCode_418C80(nox_player_netCode_85319C); v4 != nil {
			tm = nox_xxx_getTeamByID_418AB0(int32(v4.ID))
		}
	} else {
		if pl.Field3680&0x1 != 0 {
			return 1
		}
		if v6 := nox_xxx_objGetTeamByNetCode_418C80(nox_player_netCode_85319C); v6 != nil {
			if v7 := nox_xxx_objGetTeamByNetCode_418C80(dr.NetCode32); v7 != nil {
				if nox_xxx_servCompareTeams_419150(v6, v7) != 0 {
					v31 = true
				}
				tm = nox_xxx_getTeamByID_418AB0(int32(v7.ID))
			}
		}
	}
	teamsEnabled := nox_xxx_getTeamCounter_417DD0() != 0
	if pl.WeaponEquip&0x1 != 0 {
		var vp2 noxrender.Viewport
		vp2.Screen.Max = image.Point{X: int(nox_win_width), Y: int(nox_win_height)}
		vp2.Size = image.Point{X: int(nox_win_width), Y: int(nox_win_height)}
		flag := dword_5d4594_1313792
		if dword_5d4594_1313792 == nil {
			v13 := nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("Flag"))
			flag = nox_new_drawable_for_thing(v13)
			dword_5d4594_1313792 = flag
		}
		if dword_5d4594_1313792 != nil {
			for i := range pl.Weapon {
				v15 := &pl.Weapon[i]
				if v15.Field0 == 1 {
					*(*[5]uint32)(unsafe.Add(unsafe.Pointer(flag), 4*108)) = *(*[5]uint32)(unsafe.Pointer(&v15.Field4))
					flag = dword_5d4594_1313792
					break
				}
			}
			flag.PosVec.X = dr.PosVec.X - vp.World.Min.X + vp.Screen.Min.X + 15
			dword_5d4594_1313792.PosVec.Y = vp.Screen.Min.Y - vp.World.Min.Y + dr.PosVec.Y - 25
			dword_5d4594_1313792.DrawFunc.Get()(&vp2, dword_5d4594_1313792)
		}
	}
	var colors [6]uint32
	if nox_client_drawable_testBuff_4356C0(dr, 23) {
		cl := nox_color_blue_2650684
		if gameFrame()%2 != 0 {
			cl = nox_color_white_2523948
		}
		for i := 0; i < 6; i++ {
			colors[i] = cl
		}
	} else if nox_client_drawable_testBuff_4356C0(dr, 25) {
		for i := 0; i < 6; i++ {
			colors[i] = nox_color_blue_2650684
		}
	} else {
		pl.Info()
		colors[0] = pl.Color0
		colors[1] = pl.Color1
		colors[2] = pl.Color2
		colors[3] = pl.Color3
		colors[4] = pl.Color4
		colors[5] = pl.Color5
		if pl.Field3680&0x400 != 0 {
			for i := 0; i < 6; i++ {
				var r, g, b byte
				nox_draw_splitColor_435280(int16(uint16(colors[i])), &r, &g, &b)
				if int(g)+100 >= 255 {
					g = math.MaxUint8
				} else {
					g += 100
				}
				colors[i] = nox_color_rgb_4344A0(int32(r), int32(g), int32(b))
			}
		}
	}
	for i := 0; i < 6; i++ {
		nox_draw_setMaterial_4341D0(int32(i+1), int32(colors[i]))
	}
	var (
		panim *client.PlayerAnimation
		fi    int32
	)
	img := sub_4B8FA0(dr, &panim, &fi)
	if img == nil {
		return 0
	}
	nox_xxx_drawObject_4C4770_draw(vp, dr, img)

	// A player in Nox has a 32-bit integer field that contains bits for each
	// type of armor / weapon. sub_4B8D40 is responsible for iterating over
	// each type and drawing it to the screen.
	//
	// To add support for drawing the quiver, we must modify sub_4B8D40 to
	// iterate from 1 instead of 2 (i.e. bit 1 indicates quiver equipped). We
	// must also modify how sub_4B8D40 is called because of Z ordering.
	//
	// The Z ordering is simple to understand. Usually Nox will draw the player
	// body, and then the armor / weapon on top (or vice versa depending on
	// rotation). The quiver is unique because it is on the player's back, e.g.
	// it must be drawn first, then the body, then the rest of the armor.
	if dr.AnimDir != 1 && dr.AnimDir != 0 && dr.AnimDir != 2 && dr.AnimDir != 3 && dr.AnimDir != 6 || dr.AnimInd == 37 {
		sub_4B8D40(vp, dr, pl.WeaponEquip&2, &pl.Weapon, panim, fi)
		sub_4B8960(vp, dr, pl.ArmorEquip, &pl.Armor, panim, fi)
		sub_4B8D40(vp, dr, pl.WeaponEquip&^2, &pl.Weapon, panim, fi)
	} else {
		sub_4B8D40(vp, dr, pl.WeaponEquip&^2, &pl.Weapon, panim, fi)
		sub_4B8960(vp, dr, pl.ArmorEquip, &pl.Armor, panim, fi)
		sub_4B8D40(vp, dr, pl.WeaponEquip&2, &pl.Weapon, panim, fi)
	}
	if !(v30 || !nox_client_drawable_testBuff_4356C0(dr, 0) || dr.NetCode32 == nox_player_netCode_85319C || *memmap.PtrT[*client.Drawable](0x852978, 8) != nil && (nox_client_drawable_testBuff_4356C0(*memmap.PtrT[*client.Drawable](0x852978, 8), 21) || v31)) {
		return 1
	}
	a1 := nox_color_rgb_4344A0(155, 155, 155)
	if sub_48D830(dr) == 0 && !noxflags.HasGame(2048) {
		name := &pl.NameFinal[0] // pl.Name()
		var v34 int32
		nox_xxx_drawGetStringSize_43F840(nil, name, &v34, nil, 0)
		x := int32(vp.Screen.Min.X) + int32(dr.PosVec.X) + v34/(-2) - int32(vp.World.Min.X)
		y := int32(vp.Screen.Min.Y - vp.World.Min.Y + dr.PosVec.Y - 64)
		nox_xxx_drawSetTextColor_434390(*memmap.PtrInt32(0x852978, 4))
		nox_xxx_drawString_43F6E0(nil, name, x+1, y+1)
		nox_xxx_drawSetTextColor_434390(int32(a1))
		if teamsEnabled && tm != nil {
			cl := int32(nox_xxx_materialGetTeamColor_418D50(tm))
			nox_xxx_drawSetTextColor_434390(cl)
		}
		nox_xxx_drawString_43F6E0(nil, name, x, y)
	}
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
	if nox_client_drawable_testBuff_4356C0(dr, 30) {
		var vp2 noxrender.Viewport
		vp2.Screen.Max = image.Point{X: int(nox_win_width), Y: int(nox_win_height)}
		vp2.Size = image.Point{X: int(nox_win_width), Y: int(nox_win_height)}
		if dword_5d4594_1313800 == nil {
			dword_5d4594_1313800 = nox_new_drawable_for_thing(nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("SpinningCrown")))
			dword_5d4594_1313800.ObjFlags |= 0x1000000
		}
		dword_5d4594_1313800.PosVec.X = dr.PosVec.X + vp.Screen.Min.X - vp.World.Min.X
		dword_5d4594_1313800.PosVec.Y = dr.PosVec.Y + vp.Screen.Min.Y - vp.World.Min.Y - 50
		dword_5d4594_1313800.DrawFunc.Get()(&vp2, dword_5d4594_1313800)
	}
	for i := 0; i < 6; i++ {
		// TODO: shouldn't it be i+1 ?
		nox_draw_setMaterial_4341D0(int32(i), int32(nox_color_white_2523948))
	}
	if !(dr != *memmap.PtrT[*client.Drawable](0x852978, 8) && nox_xxx_playerGet_470A90() != 0) {
		return 1
	}
	if noxflags.HasGame(4096) {
		nox_xxx_drawOtherPlayerHP_4B8EB0(vp, dr, pl.Field2282&0xff, int8(uint8((pl.Field3680>>10)&1)))
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
func nox_things_player_draw_parse(obj *client.ObjectType, f *binfile.MemFile, attr *byte) bool {
	dd, _ := alloc.New(client.PlayerDrawData{})
	dd.Size = uint32(unsafe.Sizeof(client.PlayerDrawData{}))
	tok := nox_memfile_read_u32(f)
	if tok == 0x454E4420 {
		return false
	}
loop:
	for {
		v22 := nox_memfile_read_u8(f)
		nox_memfile_read(unsafe.Pointer(attr), 1, int32(v22), f)
		*((*uint8)(unsafe.Add(unsafe.Pointer(attr), v22))) = 0
		aind := sub_44BB20(attr)
		if aind < 0 {
			return false
		}
		panim := &dd.Anim[aind]
		if !nox_xxx_loadVectorAnimated_44B8B0(&panim.Base, f) {
			return false
		}
		for {
			tok = nox_memfile_read_u32(f)
			if tok == 0x454E4420 {
				obj.DrawFunc.Set(nox_thing_player_draw)
				obj.DrawData = unsafe.Pointer(dd)
				return true
			}
			if tok == 0x53544154 {
				continue loop
			}
			n := nox_memfile_read_u8(f)
			nox_memfile_read(unsafe.Pointer(attr), 1, int32(n), f)
			*((*uint8)(unsafe.Add(unsafe.Pointer(attr), n))) = 0
			var res int32
			if libc.StrCmp(internCStr("NAKED"), attr) == 0 {
				p, _ := alloc.New(client.PlayerEquipAnimation{})
				panim.Naked = p
				res = sub_44B940(p, int32(panim.Base.Cnt40), f)
			} else {
				if ind := nox_xxx_parse_Armor_44BA60(attr); ind >= 0 {
					p, _ := alloc.New(client.PlayerEquipAnimation{})
					panim.Armor[ind] = p
					res = sub_44B940(p, int32(panim.Base.Cnt40), f)
				} else if ind = sub_44BAC0(attr); ind >= 0 {
					p, _ := alloc.New(client.PlayerEquipAnimation{})
					panim.Weapon[ind] = p
					res = sub_44B940(p, int32(panim.Base.Cnt40), f)
				} else {
					return false
				}
			}
			if res == 0 {
				return false
			}
		}
	}
}
