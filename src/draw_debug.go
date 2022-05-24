package opennox

/*
#include "defs.h"
extern uint32_t nox_color_white_2523948;
extern uint32_t nox_color_yellow_2589772;
*/
import "C"
import (
	"fmt"
	"image"
	"strconv"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

//export nox_thing_debug_draw
func nox_thing_debug_draw(cvp *C.nox_draw_viewport_t, cdr *C.nox_drawable) C.int {
	r := noxrend
	vp := asViewport(cvp)
	dr := asDrawable(cdr)

	cl := noxrender.Color(memmap.Uint32(0x8531A0, 2572))
	if uint32(dr.field_72) >= gameFrame() {
		cl = noxrender.Color(C.nox_color_yellow_2589772)
	}
	r.Data().SetColor2(cl)
	r.Data().SetTextColor(noxrender.Color(C.nox_color_white_2523948))
	p := dr.Pos().Add(image.Point{
		X: int(vp.x1) - int(vp.field_4),
		Y: int(vp.y1) - int(vp.field_5),
	})
	if dr.Flags28()&0x80 != 0 {
		y1 := p.Y - int(dr.field_24)
		y2 := p.Y - int(dr.field_25)
		v11 := int(memmap.Int32(0x587000, 196184+8*uintptr(dr.field_74_4)))
		v18 := int(memmap.Int32(0x587000, 196188+8*uintptr(dr.field_74_4)))
		r.DrawVector(
			image.Pt(p.X, y1),
			image.Pt(v11, v18),
			cl,
		)
		r.DrawVector(
			image.Pt(p.X, y2),
			image.Pt(v11, v18),
			cl,
		)
		r.DrawLine(
			image.Pt(p.X, y1),
			image.Pt(p.X, y2),
			cl,
		)
		r.DrawLine(
			image.Pt(p.X+v11, y1+v18),
			image.Pt(p.X+v11, y2+v18),
			cl,
		)
	} else if dr.Flags28()&0x2 != 0 {
		debugDrawShape(r, dr, p, cl)
		r.DrawVector(
			p,
			image.Point{
				X: int(memmap.Int32(0x587000, 179880+8*uintptr(dr.field_74_2))),
				Y: int(memmap.Int32(0x587000, 179884+8*uintptr(dr.field_74_2))),
			},
			cl,
		)
		r.DrawString(nil, strconv.Itoa(int(dr.Field32())), image.Pt(p.X, p.Y-10))
		r.DrawString(nil, nox_get_thing_name(int(dr.Field27())), p)
		r.DrawString(nil, debugStateStr2(int(dr.field_69)), image.Pt(p.X, p.Y+10))
	} else if dr.Flags28()&0x4 != 0 {
		debugDrawShape(r, dr, p, cl)
		r.DrawVector(
			p,
			image.Point{
				X: int(memmap.Int32(0x587000, 179880+8*uintptr(dr.field_74_2))),
				Y: int(memmap.Int32(0x587000, 179884+8*uintptr(dr.field_74_2))),
			},
			cl,
		)
		r.DrawString(nil, strconv.Itoa(int(dr.Field32())), image.Pt(p.X, p.Y-10))
		r.DrawString(nil, nox_get_thing_name(int(dr.Field27())), p)
		r.DrawString(nil, debugStateStr(int(dr.field_69)), image.Pt(p.X, p.Y+10))
	} else {
		debugDrawShape(r, dr, p, cl)
	}
	r.DrawString(nil, strconv.Itoa(int(dr.Field32())), image.Pt(p.X, p.Y-10))
	r.DrawString(nil, nox_get_thing_name(int(dr.Field27())), p)
	return 1
}

func debugDrawShape(r *NoxRender, dr *Drawable, p image.Point, cl noxrender.Color) {
	sh := dr.getShape()
	switch sh.kind {
	case shapeKindCircle:
		rad := int(sh.circle.R)
		z := *(*int16)(unsafe.Pointer(&dr.field_26))
		y1 := p.Y - int(float32(dr.field_24)-float32(z))
		y2 := p.Y - int(float32(dr.field_25)-float32(z))
		if y1 > 0 {
			cl := noxrender.Color(memmap.Uint32(0x85B3FC, 940))
			r.DrawCircleColored(p.X, p.Y, rad, cl)
		}
		r.DrawCircleColored(p.X, y1, rad, cl)
		r.DrawCircleColored(p.X, y2, rad, cl)
		r.Data().SetColor2(cl)
		r.DrawLine(
			image.Pt(p.X-rad, y1),
			image.Pt(p.X-rad, y2),
			cl,
		)
		r.DrawLine(
			image.Pt(p.X+rad, y1),
			image.Pt(p.X+rad, y2),
			cl,
		)
	case shapeKindBox:
		box := &sh.box
		z := *(*int16)(unsafe.Pointer(&dr.field_26))
		p1 := image.Point{
			X: p.X,
			Y: p.Y - int(float32(dr.field_24)-float32(z)),
		}
		p2 := image.Point{
			X: p.X,
			Y: p.Y - int(float32(dr.field_25)-float32(z)),
		}
		if p1.Y > 0 {
			cl := noxrender.Color(memmap.Uint32(0x85B3FC, 940))
			drawDebugBox(r, box, p, cl)
		}
		drawDebugBox(r, box, p1, cl)
		drawDebugBox(r, box, p2, cl)
		r.Data().SetColor2(cl)
		r.DrawLine(
			p1.Add(image.Pt(int(box.LeftBottom2), int(box.LeftTop2))),
			p2.Add(image.Pt(int(box.LeftBottom2), int(box.LeftTop2))),
			cl,
		)
		r.DrawLine(
			p1.Add(image.Pt(int(box.RightTop), int(box.RightBottom))),
			p2.Add(image.Pt(int(box.RightTop), int(box.RightBottom))),
			cl,
		)
		r.DrawLine(
			p1.Add(image.Pt(int(box.RightBottom2), int(box.RightTop2))),
			p2.Add(image.Pt(int(box.RightBottom2), int(box.RightTop2))),
			cl,
		)
	}
}

func drawDebugBox(r *NoxRender, b *noxShapeBox, p image.Point, cl noxrender.Color) {
	p1 := p.Add(image.Point{
		X: int(b.LeftTop),
		Y: int(b.LeftBottom),
	})
	p2 := p.Add(image.Point{
		X: int(b.LeftBottom2),
		Y: int(b.LeftTop2),
	})
	p3 := p.Add(image.Point{
		X: int(b.RightTop),
		Y: int(b.RightBottom),
	})
	p4 := p.Add(image.Point{
		X: int(b.RightBottom2),
		Y: int(b.RightTop2),
	})
	r.DrawLine(p1, p3, cl)
	r.DrawLine(p4, p3, cl)
	r.DrawLine(p1, p2, cl)
	r.DrawLine(p4, p2, cl)
}

func debugStateStr2(v int) string {
	if v < 0 || v >= len(debugStates2) {
		return fmt.Sprintf("UNK(%d)", v)
	}
	return debugStates2[v]
}

var debugStates2 = []string{
	"SPECIAL_3",
	"ATTACK",
	"ATTACK_FINISH",
	"ATTACK_FAR",
	"ATTACK_FAR_FINISH",
	"DEFEND",
	"DEFEND_FINISH",
	"CAST_SPELL",
	"IDLE",
	"DIE",
	"DEAD",
	"HURT",
	"MOVE",
	"MOVE_2",
	"SPECIAL_1",
	"SPECIAL_2",
}

func debugStateStr(v int) string {
	if v < 0 || v >= len(debugStates) {
		return fmt.Sprintf("UNK(%d)", v)
	}
	return debugStates[v]
}

var debugStates = []string{
	"IDLE",
	"DIE",
	"DEAD",
	"JUMP",
	"WALK",
	"WALK_AND_DRAG",
	"RUN",
	"RUNNING_JUMP",
	"PICKUP",
	"DODGE_LEFT",
	"DODGE_RIGHT",
	"ELECTROCUTED",
	"FALL",
	"TRIP",
	"GET_UP",
	"LAUGH",
	"POINT",
	"SIT",
	"SLEEP",
	"TALK",
	"TAUNT",
	"CAST_SPELL",
	"CONCENTRATE",
	"PUNCH_LEFT",
	"PUNCH_RIGHT",
	"PUNCH_RIGHT_HOOK",
	"MACE_STRIKE",
	"SWORD_STRIKE",
	"LONG_SWORD_STRIKE",
	"STAFF_STRIKE",
	"STAFF_BLOCK",
	"STAFF_SPELL_BLAST",
	"STAFF_THRUST",
	"SHOOT_BOW",
	"SHOOT_CROSSBOW",
	"AXE_STRIKE",
	"GREAT_SWORD_PARRY",
	"GREAT_SWORD_STRIKE",
	"GREAT_SWORD_IDLE",
	"HAMMER_STRIKE",
	"RAISE_SHIELD",
	"RECOIL_FORWARD",
	"RECOIL_BACKWARD",
	"RECOIL_SHIELD",
	"CHAKRAM_STRIKE",
	"BERSERKER_CHARGE",
	"WARCRY",
	"GREAT_SWORD_BLOCK_LEFT",
	"GREAT_SWORD_BLOCK_RIGHT",
	"GREAT_SWORD_BLOCK_DOWN",
	"ELECTRIC_ZAP",
	"DUST",
	"RECOIL",
	"SNEAK",
	"HARPOONTHROW",
}
