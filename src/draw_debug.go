package opennox

/*
#include "defs.h"
#include "GAME4_1.h"
#include "GAME5_2.h"
extern void* dword_5d4594_2386176;
extern uint32_t dword_5d4594_2386180;
*/
import "C"
import (
	"fmt"
	"image"
	"image/color"
	"strconv"
	"unsafe"

	noxcolor "github.com/noxworld-dev/opennox-lib/color"
	"github.com/noxworld-dev/opennox-lib/common"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/client"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/server"
)

//export nox_thing_debug_draw
func nox_thing_debug_draw(cvp *nox_draw_viewport_t, cdr *nox_drawable) C.int {
	c := noxClient
	r := c.r
	vp := asViewport(cvp)
	dr := asDrawable(cdr)

	cl := nox_color_green
	if uint32(dr.field_72) >= c.srv.Frame() {
		cl = nox_color_yellow_2589772
	}
	r.Data().SetColor2(cl)
	r.Data().SetTextColor(color.White)
	p := vp.ToScreenPos(dr.Pos())
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
		r.DrawString(nil, getThingName(int(dr.Field27())), p)
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
		r.DrawString(nil, getThingName(int(dr.Field27())), p)
		r.DrawString(nil, debugStateStr(int(dr.field_69)), image.Pt(p.X, p.Y+10))
	} else {
		debugDrawShape(r, dr, p, cl)
	}
	r.DrawString(nil, strconv.Itoa(int(dr.Field32())), image.Pt(p.X, p.Y-10))
	r.DrawString(nil, getThingName(int(dr.Field27())), p)
	return 1
}

func debugDrawShape(r *NoxRender, dr *Drawable, p image.Point, cl color.Color) {
	sh := dr.getShape()
	switch sh.Kind {
	case server.ShapeKindCircle:
		rad := int(sh.Circle.R)
		z := int16(dr.z)
		y1 := p.Y - int(float32(dr.field_24)-float32(z))
		y2 := p.Y - int(float32(dr.field_25)-float32(z))
		if y1 > 0 {
			r.DrawCircle(p.X, p.Y, rad, nox_color_red)
		}
		r.DrawCircle(p.X, y1, rad, cl)
		r.DrawCircle(p.X, y2, rad, cl)
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
	case server.ShapeKindBox:
		box := &sh.Box
		z := int16(dr.z)
		p1 := image.Point{
			X: p.X,
			Y: p.Y - int(float32(dr.field_24)-float32(z)),
		}
		p2 := image.Point{
			X: p.X,
			Y: p.Y - int(float32(dr.field_25)-float32(z)),
		}
		if p1.Y > 0 {
			drawDebugBox(r, box, p, nox_color_red)
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

func drawDebugBox(r *NoxRender, b *server.ShapeBox, p image.Point, cl color.Color) {
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

func sub_50CB00() int {
	return int(C.dword_5d4594_2386180)
}

func sub_50D210() int {
	return int(memmap.Int32(0x5D4594, 2386204))
}

func sub_50CB10() []types.Pointf {
	sz := sub_50CB00()
	return unsafe.Slice((*types.Pointf)(C.dword_5d4594_2386176), sz)
}

func drawDebugAI(vp *client.Viewport) {
	r := noxClient.r

	if arr := sub_50CB10(); len(arr) >= 2 {
		cur := sub_50D210()
		var lp image.Point
		for i := 0; i < len(arr)-1; i++ {
			var cl color.Color
			if i == cur {
				cl = nox_color_red
			} else if arr[i].X < 0.0 || arr[i].Y < 0.0 {
				cl = nox_color_blue_2650684
			} else {
				cl = nox_color_yellow_2589772
			}
			p1 := vp.ToScreenPos(arr[i].Point())
			p2 := vp.ToScreenPos(arr[i+1].Point())
			r.DrawBorder(p1.X-1, p1.Y-1, 3, 3, cl)
			r.DrawLine(p1, p2, nox_color_green)
			lp = p2
		}
		r.DrawBorder(lp.X-1, lp.Y-1, 3, 3, nox_color_yellow_2589772)
	}

	last := noxServer.ai.lastHeardEvent()
	lp := vp.ToScreenPos(last.Point())
	r.DrawBorder(lp.X-2, lp.Y-2, 5, 5, nox_color_white_2523948)

	vsz := videoGetWindowSize()
	xmin := int(float32(vp.World.Min.X/common.GridStep) + 0.5)
	ymin := int(float32(vp.World.Min.Y/common.GridStep) + 0.5)
	xmax := int(float32((vp.World.Min.X+vsz.X)/common.GridStep) + 0.5)
	ymax := int(float32((vp.World.Min.Y+vsz.Y)/common.GridStep) + 0.5)
	for y := ymin; y <= ymax; y++ {
		yi := common.GridStep * y
		for x := xmin; x <= xmax; x++ {
			xi := common.GridStep * x
			if C.sub_57B500(C.int(x), C.int(y), 64) != -1 {
				r.Data().SetColor2(noxcolor.RGB5551Color(0, 0, 255))
				r.DrawBorder(xi-vp.World.Min.X, yi-vp.World.Min.Y, common.GridStep, common.GridStep, r.Data().Color2())
				continue
			}
			flags := C.sub_50AB50(C.int(x), C.int(y))
			var cl color.Color
			if flags&0x40 != 0 {
				cl = noxcolor.RGB5551Color(0, 255, 0)
			} else if flags&2 != 0 {
				cl = noxcolor.RGB5551Color(0, 255, 255)
			} else if flags&1 != 0 {
				cl = noxcolor.RGB5551Color(0, 100, 100)
			} else if flags&0x3C != 0 {
				cl = noxcolor.RGB5551Color(255, 0, 255)
			} else if flags&0x400 != 0 {
				cl = noxcolor.RGB5551Color(255, 0, 0)
			} else if flags&0x200 != 0 {
				cl = noxcolor.RGB5551Color(255, 255, 0)
			} else if flags&0x100 != 0 {
				cl = noxcolor.RGB5551Color(100, 100, 0)
			}
			if cl != nil {
				r.DrawBorder(xi-vp.World.Min.X, yi-vp.World.Min.Y, common.GridStep, common.GridStep, cl)
			}
		}
	}
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
