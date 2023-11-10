package opennox

import (
	"image"
	"math"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
)

func (c *Client) Nox_new_drawable_for_thing(i int) *client.Drawable {
	dr := c.Objs.Alloc.NewObject()
	if dr == nil {
		dr = c.nox_xxx_spriteFromCache_45A330_drawable()
	}
	if dr == nil {
		return nil
	}
	if c.DrawableLinkThing(dr, i) == 0 {
		return nil
	}
	draw := dr.DrawFuncPtr
	if draw == legacy.Get_nox_thing_static_random_draw() {
		v4 := c.srv.Rand.Other.Int(0, int(*(*uint8)(unsafe.Add(dr.Field_76, 8)))-1)
		dr.SetFrameMB(v4)
	} else if draw == legacy.Get_nox_thing_red_spark_draw() || draw == legacy.Get_nox_thing_blue_spark_draw() ||
		draw == legacy.Get_nox_thing_yellow_spark_draw() || draw == legacy.Get_nox_thing_green_spark_draw() ||
		draw == legacy.Get_nox_thing_cyan_spark_draw() {
		dr.ZVal2 = 35
		dr.VelZ = 2
	} else {
		dr.SetFrameMB(0)
	}
	dr.Field_79 = c.srv.Frame()
	dr.Field_85 = c.srv.Frame()
	c.Objs.Count++
	dr.Field_120 = 0
	dr.Field_121 = 0
	return dr
}

func (c *Client) Nox_xxx_spriteLoadAdd_45A360_drawable(thingInd int, pos image.Point) *client.Drawable {
	dr := c.Nox_new_drawable_for_thing(thingInd)
	if dr == nil {
		return nil
	}
	dr.Buffs = 0
	dr.Field_32 = 0
	if dr.ClientUpdateFuncPtr != nil {
		c.Objs.List5Add(dr)
	}
	if dr.Flags()&0x200000 != 0 {
		c.Objs.List6Add(dr)
	}
	if dr.AudioLoop != 0 {
		c.Objs.List8Add(dr)
	}
	dr.PosVec.X = pos.X
	dr.Field_8 = uint32(pos.X)
	dr.PosVec.Y = pos.Y
	dr.Field_9 = uint32(pos.Y)
	dr.Field_80 = c.srv.Frame()
	dr.NextPtr = c.Objs.List1
	dr.Field_93 = nil
	if c.Objs.List1 != nil {
		c.Objs.List1.Field_93 = dr
	}
	c.Objs.List1 = dr
	c.Objs.AddIndex2D(dr)
	if dr.Flags()&0x10000 != 0 {
		v6 := c.Objs.List2
		dr.Field_91 = nil
		dr.Field_90 = v6
		if v6 != nil {
			v6.Field_91 = dr
		}
		c.Objs.List2 = dr
	}
	if dr.Class()&0x4 != 0 {
		c.Objs.PlayerListAdd(dr)
	}
	dr.ObjFlags |= 0x1000000
	dr.SetActive()
	dr.Field_120 = 0
	dr.Field_121 = 0
	nox_xxx_sprite_45A480_drawable(dr)
	return dr
}

func nox_xxx_sprite_45A480_drawable(dr *client.Drawable) {
	if dr.Class()&0x1000000 != 0 && dr.SubClass()&0xC0 != 0 {
		if dr.Flags()&0x4000 != 0 {
			sub_495F70(dr)
		}
	}
}

var _ = [1]struct{}{}[80-unsafe.Sizeof(client.DrawableFX{})]

func nox_xxx_allocArrayDrawableFX_495AB0() int32 {
	cl := alloc.NewClassT("DrawableFX", client.DrawableFX{}, 128)
	*memmap.PtrPtr(0x5D4594, 1203868) = cl.UPtr()
	if cl.Class == nil {
		return 0
	}
	*memmap.PtrUint32(0x5D4594, 1203872) = 0
	return 1
}

func sub_495AE0() {
	aclass := alloc.AsClassT[client.DrawableFX](*memmap.PtrPtr(0x5D4594, 1203868))
	aclass.Free()
	*memmap.PtrPtr(0x5D4594, 1203868) = nil
	*memmap.PtrUint32(0x5D4594, 1203872) = 0
}

func sub_495F70(dr *client.Drawable) {
	aclass := alloc.AsClassT[client.DrawableFX](*memmap.PtrPtr(0x5D4594, 1203868))
	if dr != nil && !dr.HasFX(1) {
		p := aclass.NewObject()
		if p != nil {
			p.Field0 = 1
			p.Field4 = 0
			legacy.Sub_495FC0(p, dr)
		}
	}
}

func (c *Client) Nox_xxx_spriteDeleteAll_45A5E0(a1 bool) {
	var next *client.Drawable
	for dr := c.Objs.List1; dr != nil; dr = next {
		next = dr.NextPtr
		if dr.Class()&0x4 == 0 || !a1 || !c.Objs.IsPlayer(dr) {
			c.Nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr)
		}
	}
}

func (c *Client) nox_xxx_spriteFromCache_45A330_drawable() *client.Drawable {
	if c.Objs.List4 == nil {
		return nil
	}
	c.Nox_xxx_spriteDeleteStatic_45A4E0_drawable(c.Objs.List4)
	return c.Objs.Alloc.NewObject()
}

func (c *Client) Nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr *client.Drawable) {
	if dr.Field_93 != nil {
		dr.Field_93.NextPtr = dr.NextPtr
	} else {
		c.Objs.List1 = dr.NextPtr
	}
	if dr.NextPtr != nil {
		dr.NextPtr.Field_93 = dr.Field_93
	}
	c.Objs.Index2DRemove(dr, dr.Ext())
	c.nox_xxx_clientDeleteSprite_476F10_drawable(dr)
	if dr.Flags()&0x10000 != 0 {
		if dr.Field_91 != nil {
			dr.Field_91.Field_90 = dr.Field_90
		} else {
			c.Objs.List2 = dr.Field_90
		}
		if dr.Field_90 != nil {
			dr.Field_90.Field_91 = dr.Field_91
		}
	}
	c.Objs.List34Delete(dr)
	c.Objs.List5Delete(dr)
	c.Objs.List6Delete(dr)
	c.Objs.DeadlineRemove(dr)
	c.Objs.RemoveHealthBar(dr, 3)
	c.sub_459F70(dr)
	if dr.Class()&0x4 != 0 {
		c.Objs.PlayerListDelete(dr)
	}
	if dr.HasTeam() {
		legacy.Nox_xxx_netChangeTeamMb_419570(dr.TeamPtr(), dr.Field_32)
	}
	c.Nox_xxx_spriteDelete_45A4B0(dr)
}

func (c *Client) sub_459F70(dr *client.Drawable) {
	if v2 := dr.Field_106; v2 != nil {
		v2.Field_107 = dr.Field_107
	} else if dr.Field_107 == nil && c.Objs.List8 != dr {
		return
	}
	if v3 := dr.Field_107; v3 != nil {
		v3.Field_106 = dr.Field_106
	} else {
		c.Objs.List8 = dr.Field_106
	}
	dr.Field_106 = nil
	dr.Field_107 = nil
	if p := sub_452EB0(&dr.Field_124, &dr.Field_125, &dr.Field_126); p != nil {
		legacy.Sub_4523D0(p)
	}
}

func sub_452EB0(a0 *unsafe.Pointer, a1, a2 *uint32) unsafe.Pointer {
	p := *a0
	if *a0 != nil && (*a2 != *(*uint32)(unsafe.Add(p, 36)) || *a1 != *(*uint32)(unsafe.Add(p, 280))) {
		p = nil
		*a0 = nil
	}
	return p
}

func (c *Client) sub_49BA70() {
	var next *client.Drawable
	for dr := c.Objs.DeadlineList; dr != nil; dr = next {
		next = dr.Field_87
		if dr.Deadline > c.srv.Frame() {
			break
		}
		c.Nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr)
	}
}

func sub_435590() uint32 {
	return memmap.Uint32(0x5D4594, 811916)
}

func (c *Client) sub_49BB40() {
	var next *client.Drawable
	for dr := c.Objs.List6; dr != nil; dr = next {
		next = dr.Field_83
		if dr.Field_85 < sub_435590() {
			c.Nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr)
		}
	}
}

func (c *Client) nox_xxx_clientDeleteSprite_476F10_drawable(dr *client.Drawable) {
	if legacy.Get_dword_5d4594_1096640() == dr {
		legacy.Set_dword_5d4594_1096640(nil)
	}
	if legacy.Get_nox_client_spriteUnderCursorXxx_1096644() == dr {
		legacy.Set_nox_client_spriteUnderCursorXxx_1096644(nil)
	}
}

func (c *Client) Nox_xxx_spriteDelete_45A4B0(dr *client.Drawable) int {
	c.sub_495B00(dr)
	c.Objs.Alloc.FreeObjectFirst(dr)
	c.Objs.Count--
	return c.Objs.Count
}

func (c *Client) sub_495B00(dr *client.Drawable) {
	var next *client.DrawableFX
	aclass := alloc.AsClassT[client.DrawableFX](*memmap.PtrPtr(0x5D4594, 1203868))
	for p := dr.Field_114; p != nil; p = next {
		next = p.Next
		if uintptr(next.C()) < math.MaxUint16 {
			// FIXME: Sometimes this pointer contains garbage.
			//        Equip throwable like shuriken or chakram and fire it. Once it hits, this will eventually trigger.
			next = nil
		}
		legacy.Sub_495B50(p)
		aclass.FreeObjectFirst(p)
	}
	dr.Field_114 = nil
}

func (c *Client) Sub_45A670(a1 uint32) {
	if c.dword_5d4594_1046604 == 0 {
		c.dword_5d4594_1046604 = c.Things.TypeByID("SummonEffect").Index()
	}
	var next *client.Drawable
	for dr := c.Objs.List1; dr != nil; dr = next {
		next = dr.NextPtr
		if dr.Class()&0x20400006 == 0 {
			if legacy.Sub_49C520(dr) == 0 {
				if int(dr.Field_27) != c.dword_5d4594_1046604 && dr.Field_80 < a1 {
					c.Nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr)
				}
			}
		}
	}
}

func (c *Client) sub_45AB40() {
	for it := c.Objs.FirstList8(); it != nil; it = it.Field_106 {
		if it.AudioLoop != 0 {
			legacy.Sub_45A9B0(it, c.ClientPlayerUnit())
		}
	}
}

func (c *Client) sub_49BD70(vp *noxrender.Viewport) {
	if nox_xxx_checkGameFlagPause_413A50() {
		return
	}
	var next *client.Drawable
	for it := c.Objs.FirstList5(); it != nil; it = next {
		next = it.Field_94
		if fnc1 := it.ClientUpdateFuncPtr; fnc1 == nil || ccall.CallIntPtr2(fnc1, vp.C(), it.C()) != 0 {
			if fnc2 := it.Field_115; fnc2 != nil {
				ccall.CallVoidPtr2(fnc2, vp.C(), it.C())
			}
		}
	}
}
