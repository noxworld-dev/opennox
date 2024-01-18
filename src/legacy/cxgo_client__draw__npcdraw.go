package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func nox_thing_npc_draw(vp *noxrender.Viewport, dr *client.Drawable) int {
	if noxflags.HasGame(0x200000) {
		typ := sub_44D330(internCStr("NewPlayer"))
		dd := typ.DrawData
		dd2 := unsafe.Add(dd, 4)
		if *(*uint16)(unsafe.Add(dd2, 40)) == 0 {
			return 1
		}
		p2 := *(*unsafe.Pointer)(unsafe.Add(dd2, 48))
		p3 := *(*unsafe.Pointer)(unsafe.Add(p2, uintptr(dr.AnimDir)*4+4))
		nox_xxx_drawObject_4C4770_draw(vp, dr, *(*noxrender.ImageHandle)(unsafe.Add(p3, 0)))
		return 1
	}
	npcID := int32(dr.NetCode32)
	dd2 := (*memmap.PtrT[*client.Drawable](0x852978, 8)).DrawData
	npc := nox_npc_by_id(npcID)
	if dd2 == nil || npc == nil {
		return 1
	}
	if nox_client_drawable_testBuff_4356C0(dr, 23) {
		cl := nox_color_blue_2650684
		if gameFrame()%2 != 0 {
			cl = nox_color_white_2523948
		}
		for i := 0; i < 6; i++ {
			nox_draw_setMaterial_4341D0(int32(i+1), int32(cl))
		}
	} else if nox_client_drawable_testBuff_4356C0(dr, 25) {
		for i := 0; i < 6; i++ {
			nox_draw_setMaterial_4341D0(int32(i+1), int32(nox_color_blue_2650684))
		}
	} else if npc.Field1312 == 1 {
		for i := 0; i < 6; i++ {
			var v35, a2, v34 byte
			nox_draw_splitColor_435280(int16(npc.Color8[i]), &v35, &a2, &v34)
			if int(a2)+100 >= 0xff {
				a2 = 0xff
			} else {
				a2 += 100
			}
			v14 := int32(nox_color_rgb_4344A0(int32(v35), int32(a2), int32(v34)))
			nox_draw_setMaterial_4341D0(int32(i+1), v14)
		}
	} else {
		for i := 0; i < 6; i++ {
			nox_draw_setMaterial_4341D0(int32(i+1), int32(npc.Color8[i]))
		}
	}
	v18 := nox_xxx_spriteNPCInfo_49A4B0(dr, int32(npc.WeaponEquip), int32(npc.ArmorEquip))
	tp := unsafe.Add(dd2, v18*264)
	panim := (*client.PlayerAnimation)(unsafe.Add(tp, 4))
	if int32(*(*uint16)(unsafe.Add(tp, 44))) == 0 {
		return 1
	}
	fi := sub_4BC5D0(dr, &panim.Base)
	if fi < 0 {
		return 0
	}
	frames := panim.FramesSlice(panim.Naked.Frames[dr.AnimDir])
	nox_xxx_drawObject_4C4770_draw(vp, dr, frames[fi])
	if dr.AnimDir != 1 && dr.AnimDir != 0 && dr.AnimDir != 2 && dr.AnimDir != 3 && dr.AnimDir != 6 || dr.AnimInd == 37 {
		sub_4B8960(vp, dr, npc.ArmorEquip, &npc.Armor, panim, fi)
		sub_4B8D40(vp, dr, npc.WeaponEquip, &npc.Weapon, panim, fi)
	} else {
		sub_4B8D40(vp, dr, npc.WeaponEquip, &npc.Weapon, panim, fi)
		sub_4B8960(vp, dr, npc.ArmorEquip, &npc.Armor, panim, fi)
	}
	if nox_client_drawable_testBuff_4356C0(dr, 16) {
		if dword_5d4594_1313796 == nil {
			typ := nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("SpinningSkull"))
			dword_5d4594_1313796 = nox_new_drawable_for_thing(typ)
			dword_5d4594_1313796.ObjFlags |= 0x1000000
		}
		dword_5d4594_1313796.PosVec.X = vp.Screen.Min.X + dr.PosVec.X - vp.World.Min.X
		dword_5d4594_1313796.PosVec.Y = vp.Screen.Min.Y - vp.World.Min.Y + dr.PosVec.Y - 50
		dword_5d4594_1313796.CallDraw(nox_draw_getViewport_437250())
	}
	if nox_client_drawable_testBuff_4356C0(dr, 30) {
		if dword_5d4594_1313800 == nil {
			typ := nox_xxx_getTTByNameSpriteMB_44CFC0(internCStr("SpinningCrown"))
			dword_5d4594_1313800 = nox_new_drawable_for_thing(typ)
			dword_5d4594_1313800.ObjFlags |= 0x1000000
		}
		dword_5d4594_1313800.PosVec.X = vp.Screen.Min.X + dr.PosVec.X - vp.World.Min.X
		dword_5d4594_1313800.PosVec.Y = vp.Screen.Min.Y - vp.World.Min.Y + dr.PosVec.Y - 50
		dword_5d4594_1313800.CallDraw(nox_draw_getViewport_437250())
	}
	if nox_xxx_unitSpriteCheckAlly_4951F0(int32(dr.NetCode32)) != 0 {
		var (
			a1   uint16
			v33b uint16
			a2   byte
		)
		sub_495180(int32(dr.NetCode32), &v33b, &a1, &a2)
		nox_xxx_spriteDrawMonsterHP_4BC080(vp, dr, v33b, a1, int8(a2))
	}
	for i := 0; i < 6; i++ {
		nox_draw_setMaterial_4341D0(int32(i), int32(nox_color_white_2523948))
	}
	return 1
}
