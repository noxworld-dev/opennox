package opennox

import (
	"unsafe"

	noxcolor "github.com/noxworld-dev/opennox-lib/color"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/server"
)

func init() {
	client.RegisterDraw("NPCDraw", legacy.Get_nox_thing_npc_draw(), 0, nil)
}

func (c *Client) DrawNPC(vp *noxrender.Viewport, dr *client.Drawable) int {
	if noxflags.HasGame(noxflags.GameFlag22) {
		typ := c.Things.TypeByID("NewPlayer")
		dd := (*client.PlayerDrawData)(typ.DrawData)
		panim := &dd.Anim[0]
		if panim.Base.Cnt40 == 0 {
			return 1
		}
		// TODO: This looks very suspicious. It's just drawing a static frame.
		//       It would only makes sense if the engine is drawing a map preview of some sort.
		//       So maybe GameFlag22 means "preview" or even "editor"?
		frames := panim.FramesSlice(dd.Anim[0].Naked.Frames[dr.AnimDir])
		legacy.Nox_xxx_drawObject_4C4770_draw(vp, dr, frames[0])
		return 1
	}
	npcID := int(dr.NetCode32)
	dd2 := (*client.PlayerDrawData)(c.ClientPlayerUnit().DrawData)
	npc := c.Server.NPCs.ByID(npcID)
	if dd2 == nil || npc == nil {
		return 1
	}
	// TODO: call DrawFlagOn to support bots taking the flag
	var colors [6]noxcolor.RGBA5551
	for i, cl := range npc.Color8 {
		colors[i] = noxcolor.RGBA5551(cl)
	}
	c.EnchantColorize(dr, npc.Field1312 == 1, colors[:])
	for i, cl := range colors {
		c.r.Data().SetMaterial(i+1, cl)
	}
	ind := c.nox_xxx_spriteNPCInfo_49A4B0(dr, npc.WeaponEquip, npc.ArmorEquip)
	panim := &dd2.Anim[ind]
	if panim.Base.Cnt40 == 0 {
		return 1
	}
	fi := c.getAnimFrameInd(dr, &panim.Base)
	if fi < 0 {
		return 0
	}
	frames := panim.FramesSlice(panim.Naked.Frames[dr.AnimDir])
	legacy.Nox_xxx_drawObject_4C4770_draw(vp, dr, frames[fi])
	c.DrawArmorAndWeapon(vp, dr, npc, panim, fi)
	for i := range colors {
		c.r.Data().SetMaterial(i+1, nox_color_white_2523948)
	}
	// TODO: call DrawPlayerName to support bot names
	c.DrawEnchantsTop(vp, dr)
	c.DrawMonsterHP(vp, dr)
	return 1
}
func (c *Client) nox_xxx_spriteNPCInfo_49A4B0(dr *client.Drawable, weapons, armor uint32) int {
	ptr := (*uint32)(unsafe.Add(unsafe.Pointer(&dr.Union), 0))
	res := int(*ptr)
	*ptr = 0
	switch dr.AnimInd - 1 {
	case 0, 1, 2, 3:
		if weapons&0xFFFFFFFC == 0 {
			if res == 0 || dr.AnimFrameSlave == 0 {
				res = c.Server.Rand.Other.Int(23, 24)
			}
			*ptr = uint32(res)
			return res
		}
		return sub_4FA280(weapons & 0xFFFFFFFC)
	case 4, 5:
		if weapons&0x400 != 0 {
			if res != 0 && dr.AnimFrameSlave != 0 {
				*ptr = uint32(res)
			} else {
				res = c.Server.Rand.Other.Int(47, 49)
				*ptr = uint32(res)
			}
			return res
		} else if weapons&0x7FF8000 != 0 {
			return 30
		} else if armor&0x3000000 == 0 {
			if (weapons & 0x400) != 0 {
				return 0x26
			}
			return 0
		}
		return 40
	case 6:
		return 21
	case 7:
		if (weapons & 0x400) != 0 {
			return 0x26
		}
		return 0
	case 8:
		return 1
	case 9:
		return 2
	case 11:
		return 4
	case 12:
		return 6
	case 13:
		return 50
	default:
		return 0
	}
}
func sub_4FA280(bit uint32) int {
	for i := 2; i < server.PlayerWeaponCnt; i++ {
		if ((1 << i) & bit) != 0 {
			return int(memmap.Uint32(0x587000, uintptr(i*4)+215824))
		}
	}
	return 0
}
