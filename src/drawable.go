package opennox

import (
	"image"
	"math"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

const (
	nox_drawable_2d_index_cap = 47
	nox_drawable_2d_div       = 128
)

var (
	nox_drawable_2d_index          [][]*client.Drawable
	nox_drawable_2d_index_size     int
	nox_drawable_head_unk3         *client.Drawable
	nox_drawable_head_unk4         *client.Drawable
	dword_5d4594_1303536           *client.Drawable
	nox_xxx_drawablePlayer_1046600 *client.Drawable
	dword_5d4594_1046596           *client.Drawable
	dword_5d4594_1303472           *client.Drawable
	dword_5d4594_1303468           *client.Drawable
	dword_5d4594_1046576           *client.Drawable
	nox_drawable_count             int
	nox_alloc_drawable             alloc.ClassT[client.Drawable]
)

func nox_alloc_drawable_init(cnt int) bool {
	nox_alloc_drawable = alloc.NewClassT("drawableClass", client.Drawable{}, cnt)
	return nox_alloc_drawable.Class != nil
}

func nox_new_drawable_for_thing(i int) *client.Drawable {
	c := noxClient
	dr := nox_alloc_drawable.NewObject()
	if dr == nil {
		dr = nox_xxx_spriteFromCache_45A330_drawable()
	}
	if dr == nil {
		return nil
	}
	if nox_drawable_link_thing(dr, i) == 0 {
		return nil
	}
	draw := dr.DrawFuncPtr
	if draw == legacy.Get_nox_thing_static_random_draw() {
		v4 := randomIntMinMax(0, int(*(*uint8)(unsafe.Add(dr.Field_76, 8)))-1)
		nox_xxx_spriteSetFrameMB_45AB80(dr, v4)
	} else if draw == legacy.Get_nox_thing_red_spark_draw() || draw == legacy.Get_nox_thing_blue_spark_draw() ||
		draw == legacy.Get_nox_thing_yellow_spark_draw() || draw == legacy.Get_nox_thing_green_spark_draw() ||
		draw == legacy.Get_nox_thing_cyan_spark_draw() {
		dr.Field_26_1 = 35
		dr.VelZ = 2
	} else {
		nox_xxx_spriteSetFrameMB_45AB80(dr, 0)
	}
	dr.Field_79 = c.srv.Frame()
	dr.Field_85 = c.srv.Frame()
	nox_drawable_count++
	dr.Field_120 = 0
	dr.Field_121 = 0
	return dr
}

func nox_xxx_spriteSetFrameMB_45AB80(dr *client.Drawable, a2 int) {
	if dr.Flags28()&0x2 == 0 || dr.Flags29()&0x40000 == 0 || dr.Field_69 != 8 {
		dr.Field_78 = dr.Field_77
		dr.Field_77 = uint32(a2)
	}
}

func nox_xxx_getSomeSprite_49BD40() *client.Drawable {
	return dword_5d4594_1303536
}

func nox_xxx_spriteToList_49BC80_drawable(dr *client.Drawable) {
	if dr.Field_96 == 0 {
		dr.Field_95 = nil
		dr.Field_94 = dword_5d4594_1303536
		if dword_5d4594_1303536 != nil {
			dword_5d4594_1303536.Field_95 = dr
		}
		dword_5d4594_1303536 = dr
		dr.Field_96 = 1
	}
}

func sub_49BCD0(dr *client.Drawable) {
	if dr.Field_96 != 0 {
		v2 := dr.Field_95
		if v2 != nil {
			v2.Field_94 = dr.Field_94
			if v3 := dr.Field_94; v3 != nil {
				v3.Field_95 = dr.Field_95
				dr.Field_96 = 0
				return
			}
		} else {
			dword_5d4594_1303536 = dr.Field_94
			if v4 := dr.Field_94; v4 != nil {
				v4.Field_95 = nil
			}
		}
		dr.Field_96 = 0
	}
}

func nox_xxx_cliGetSpritePlayer_45A000() *client.Drawable {
	return nox_xxx_drawablePlayer_1046600
}

func sub_459ED0_drawable(dr *client.Drawable) {
	dr.Field_104 = nox_xxx_drawablePlayer_1046600
	dr.Field_105 = nil
	if nox_xxx_drawablePlayer_1046600 != nil {
		nox_xxx_drawablePlayer_1046600.Field_105 = dr
	}
	nox_xxx_drawablePlayer_1046600 = dr
}

func sub_459F00(dr *client.Drawable) {
	if v2 := dr.Field_104; v2 != nil {
		v2.Field_105 = dr.Field_105
	}
	if v3 := dr.Field_105; v3 != nil {
		v3.Field_104 = dr.Field_104
	} else {
		nox_xxx_drawablePlayer_1046600 = dr.Field_104
	}
}

func nox_xxx_netSpriteByCodeStatic_45A720(id int) *client.Drawable {
	for dr := legacy.Sub_45A060(); dr != nil; dr = dr.NextPtr {
		if dr.Flags28()&0x20400000 != 0 && dr.Field_32 == uint32(id) {
			return dr
		}
	}
	return nil
}

func nox_xxx_netSpriteByCodeDynamic_45A6F0(id int) *client.Drawable {
	for dr := legacy.Sub_45A060(); dr != nil; dr = dr.NextPtr {
		if dr.Flags28()&0x20400000 == 0 && dr.Field_32 == uint32(id) {
			return dr
		}
	}
	return nil
}

func nox_xxx_spriteFromCache_45A330_drawable() *client.Drawable {
	if nox_drawable_head_unk4 == nil {
		return nil
	}
	legacy.Nox_xxx_spriteDeleteStatic_45A4E0_drawable(nox_drawable_head_unk4)
	return nox_alloc_drawable.NewObject()
}

func sub_459F40_drawable(dr *client.Drawable) {
	dr.Field_106 = dword_5d4594_1046576
	dr.Field_107 = nil
	if dword_5d4594_1046576 != nil {
		dword_5d4594_1046576.Field_107 = dr
	}
	dword_5d4594_1046576 = dr
}

func sub_45A090() *client.Drawable {
	return dword_5d4594_1046576
}

func sub_459F70(dr *client.Drawable) {
	if v2 := dr.Field_106; v2 != nil {
		v2.Field_107 = dr.Field_107
	} else if dr.Field_107 == nil && dword_5d4594_1046576 != dr {
		return
	}
	if v3 := dr.Field_107; v3 != nil {
		v3.Field_106 = dr.Field_106
	} else {
		dword_5d4594_1046576 = dr.Field_106
	}
	dr.Field_106 = nil
	dr.Field_107 = nil
	if p := legacy.Sub_452EB0(&dr.Field_124); p != nil {
		legacy.Sub_4523D0(p)
	}
}

func nox_xxx_cliRemoveHealthbar_459E30(dr *client.Drawable, a2 uint8) {
	if dr.Flags30()&0x80000000 != 0 {
		set := (^a2 & dr.Field_71_0) == 0
		dr.Field_71_0 &= ^a2
		if set {
			if v4 := dr.Field_102; v4 != nil {
				v4.Field_103 = dr.Field_103
			}
			if v5 := dr.Field_103; v5 != nil {
				v5.Field_102 = dr.Field_102
			} else {
				dword_5d4594_1046596 = dr.Field_102
			}
			dr.Flags30Val &^= 0x80000000
		}
	}
}

func nox_xxx_cliFirstMinimapObj_459EB0() *client.Drawable {
	return dword_5d4594_1046596
}

func sub_459DD0(dr *client.Drawable, a2 uint8) {
	if dr == nil {
		return
	}
	dr.Field_71_0 |= a2
	if dr.Flags30()&0x80000000 != 0 {
		return
	}
	for it := nox_xxx_cliFirstMinimapObj_459EB0(); it != nil; it = nox_xxx_cliNextMinimapObj_459EC0(it) {
		// TODO: this happens when hosting a Solo map in Arena game mode and leads to an infinite loop, so we prevent it
		if dr == it {
			return
		}
	}
	v4 := dword_5d4594_1046596
	dr.Field_103 = nil
	dr.Field_102 = v4
	if dword_5d4594_1046596 != nil {
		dword_5d4594_1046596.Field_103 = dr
	}
	dword_5d4594_1046596 = dr
	dr.Flags30Val |= 0x80000000
}

func nox_xxx_cliNextMinimapObj_459EC0(dr *client.Drawable) *client.Drawable {
	next := dr.Field_102
	if dr != nil && dr == next {
		panic("infinite loop!")
	}
	return next
}

func nox_xxx_sprite_49BA10(dr *client.Drawable) {
	if dr.Deadline != 0 {
		if v2 := dr.Field_88; v2 != nil {
			v2.Field_87 = dr.Field_87
		} else {
			dword_5d4594_1303468 = dr.Field_87
		}
		if v3 := dr.Field_87; v3 != nil {
			v3.Field_88 = dr.Field_88
		}
		dr.Deadline = 0
	}
}

func sub_49BA70() {
	c := noxClient
	var next *client.Drawable
	for dr := dword_5d4594_1303468; dr != nil; dr = next {
		next = dr.Field_87
		if dr.Deadline > c.srv.Frame() {
			break
		}
		legacy.Nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr)
	}
}

func nox_xxx_spriteTransparentDecay_49B950(dr *client.Drawable, lifetime int) {
	c := noxClient
	if dr.Deadline != 0 {
		nox_xxx_sprite_49BA10(dr)
	}
	v2 := c.srv.Frame() + uint32(lifetime)
	dr.Deadline = v2
	if dword_5d4594_1303468 == nil {
		dr.Field_87 = nil
		dr.Field_88 = nil
		dword_5d4594_1303468 = dr
		return
	}

	var last *client.Drawable
	for it := dword_5d4594_1303468; it != nil; it = it.Field_87 {
		if it.Deadline >= v2 {
			dr.Field_87 = it
			dr.Field_88 = it.Field_88
			if v5 := it.Field_88; v5 != nil {
				v5.Field_87 = dr
			} else {
				dword_5d4594_1303468 = dr
			}
			it.Field_88 = dr
			return
		}
		last = it
	}
	last.Field_87 = dr
	dr.Field_87 = nil
	dr.Field_88 = last
}

func sub_49BAF0(dr *client.Drawable) {
	if dr.Flags30()&0x200000 != 0 {
		if v2 := dr.Field_84; v2 != nil {
			v2.Field_83 = dr.Field_83
		} else {
			dword_5d4594_1303472 = dr.Field_83
		}
		if v3 := dr.Field_83; v3 != nil {
			v3.Field_84 = dr.Field_84
		}
		dr.Flags30Val &= 0xFFDFFFFF
	}
}

func sub_435590() uint32 {
	return memmap.Uint32(0x5D4594, 811916)
}

func sub_49BB40() {
	var next *client.Drawable
	for dr := dword_5d4594_1303472; dr != nil; dr = next {
		next = dr.Field_83
		if dr.Field_85 < sub_435590() {
			legacy.Nox_xxx_spriteDeleteStatic_45A4E0_drawable(dr)
		}
	}
}

func nox_xxx_spriteToSightDestroyList_49BAB0_drawable(dr *client.Drawable) {
	dr.Field_84 = nil
	dr.Field_83 = dword_5d4594_1303472
	if dword_5d4594_1303472 != nil {
		dword_5d4594_1303472.Field_84 = dr
	}
	dword_5d4594_1303472 = dr
	dr.Flags30Val |= 0x200000
}

func nox_xxx_spriteDelete_45A4B0(dr *client.Drawable) int {
	sub_495B00(dr)
	nox_alloc_drawable.FreeObjectFirst(dr)
	nox_drawable_count--
	return nox_drawable_count
}

func sub_495B00(dr *client.Drawable) {
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

func nox_drawable_free() {
	nox_alloc_drawable.Free()
	legacy.Nox_drawable_free_lists()
	nox_drawable_head_unk3 = nil
	nox_drawable_head_unk4 = nil
	nox_drawable_count = 0
}

func nox_xxx_sprite_45A110_drawable(dr *client.Drawable) {
	dr.Field_98 = nil
	dr.Field_97 = nox_drawable_head_unk3
	if nox_drawable_head_unk3 != nil {
		nox_drawable_head_unk3.Field_98 = dr
	} else {
		nox_drawable_head_unk4 = dr
	}
	nox_drawable_head_unk3 = dr
	dr.Flags30Val |= 0x400000
}

func sub_45A160_drawable(dr *client.Drawable) {
	if (dr.Flags30() & 0x400000) == 0 {
		return
	}
	if dr2 := dr.Field_98; dr2 != nil {
		dr2.Field_97 = dr.Field_97
	} else {
		nox_drawable_head_unk3 = dr.Field_97
	}
	if dr2 := dr.Field_97; dr2 != nil {
		dr2.Field_98 = dr.Field_98
	} else {
		nox_drawable_head_unk4 = dr.Field_98
	}
	dr.Flags30Val &= 0xFFBFFFFF
}

func sub_49A8E0_init() {
	nox_drawable_2d_index_size = nox_drawable_2d_index_cap
	nox_drawable_2d_index = make([][]*client.Drawable, nox_drawable_2d_index_size)
	for i := 0; i < nox_drawable_2d_index_size; i++ {
		nox_drawable_2d_index[i] = make([]*client.Drawable, nox_drawable_2d_index_size)
	}
}

func sub_49A950_free() {
	nox_drawable_2d_index = nil
	nox_drawable_2d_index_size = 0
}

func nox_xxx_sprite_49AA00_drawable(dr *client.Drawable) {
	pos := dr.Pos()
	xi := pos.X / nox_drawable_2d_div
	yi := pos.Y / nox_drawable_2d_div

	ext := dr.Ext()
	if ext.Field99 != nil {
		client.Nox_xxx_sprite_2d_remove(dr, ext)
	}

	dr.Field_101 = nil

	if xi < 0 || xi >= len(nox_drawable_2d_index) {
		return
	}
	index := nox_drawable_2d_index[xi]
	if yi < 0 || yi >= len(index) {
		return
	}
	v4 := index[yi]
	dr.Field_100 = v4
	if v4 != nil {
		v4.Field_101 = dr
	}
	nox_drawable_2d_index[xi][yi] = dr

	ext.Field99 = &nox_drawable_2d_index[xi][yi]
}

func nox_xxx_forEachSprite(rect image.Rectangle, fnc func(dr *client.Drawable)) {
	if fnc == nil {
		return
	}
	xs := rect.Min.X / nox_drawable_2d_div
	if xs < 0 {
		xs = 0
	}
	ys := rect.Min.Y / nox_drawable_2d_div
	if ys < 0 {
		ys = 0
	}
	xe := rect.Max.X / nox_drawable_2d_div
	if xe >= nox_drawable_2d_index_size {
		xe = nox_drawable_2d_index_size - 1
	}
	ye := rect.Max.Y / nox_drawable_2d_div
	if ye >= nox_drawable_2d_index_size {
		ye = nox_drawable_2d_index_size - 1
	}
	for y := ys; y <= ye; y++ {
		for x := xs; x <= xe; x++ {
			for cur := nox_drawable_2d_index[x][y]; cur != nil; cur = cur.Field100() {
				fnc(cur)
			}
		}
	}
}

func nox_drawable_find(pt image.Point, r int) *client.Drawable {
	xs := (pt.X - r) / nox_drawable_2d_div
	if xs < 0 {
		xs = 0
	}
	ys := (pt.Y - r) / nox_drawable_2d_div
	if ys < 0 {
		ys = 0
	}
	xe := (pt.X + r) / nox_drawable_2d_div
	if xe >= nox_drawable_2d_index_size {
		xe = nox_drawable_2d_index_size - 1
	}
	ye := (pt.Y + r) / nox_drawable_2d_div
	if ye >= nox_drawable_2d_index_size {
		ye = nox_drawable_2d_index_size - 1
	}
	var (
		out *client.Drawable
		min = -1
		r2  = r * r
	)
	for y := ys; y <= ye; y++ {
		for x := xs; x <= xe; x++ {
			for dr := nox_drawable_2d_index[x][y]; dr != nil; dr = dr.Field100() {
				if legacy.Nox_xxx_client_4984B0_drawable(dr) == 0 {
					continue
				}
				dp := pt.Sub(dr.Pos())
				d2 := dp.X*dp.X + dp.Y*dp.Y
				if d2 >= r2 {
					continue
				}
				if min < 0 || d2 < min {
					min = d2
					out = dr
				}
			}
		}
	}
	return out
}
