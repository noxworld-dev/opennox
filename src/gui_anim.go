package opennox

/*
#include "defs.h"
#include "client__gui__window.h"
*/
import "C"
import (
	"image"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/env"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/common/alloc"
	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/internal/ccall"
)

func init() {
	if env.IsDevMode() || env.IsE2E() {
		gui.AnimSpeed = 5
	}
}

var guiAnimationsHead *guiAnim

func asGUIAnim(p *C.nox_gui_animation) *guiAnim {
	return (*guiAnim)(unsafe.Pointer(p))
}

var _ = [1]struct{}{}[68-unsafe.Sizeof(guiAnim{})]

type guiAnim struct {
	field0     uint32         // 0, 0
	win        *gui.Window    // 1, 4
	p2         image.Point    // 2, 8
	p1         image.Point    // 4, 16
	outDp      image.Point    // 6, 24
	inDp       image.Point    // 8, 32
	next       *guiAnim       // 10, 40
	prev       *guiAnim       // 11, 44
	func12     unsafe.Pointer // // 12, 48; func() int
	func13     unsafe.Pointer // 13, 52; func() int
	fncDoneOut unsafe.Pointer // 14, 56; func() int
	fncDoneIn  unsafe.Pointer // 15, 60; func()
	state      gui.AnimState  // 16, 64
}

func (a *guiAnim) C() *C.nox_gui_animation {
	return (*C.nox_gui_animation)(unsafe.Pointer(a))
}

func (a *guiAnim) State() gui.AnimState {
	if a == nil {
		return -1
	}
	return a.state
}

func (a *guiAnim) SetState(s gui.AnimState) {
	a.state = s
}

func (a *guiAnim) Window() *gui.Window {
	if a == nil {
		return nil
	}
	return a.win
}

func (a *guiAnim) Next() *guiAnim {
	if a == nil {
		return nil
	}
	return a.next
}

func (a *guiAnim) Prev() *guiAnim {
	if a == nil {
		return nil
	}
	return a.prev
}

func (a *guiAnim) Func12() int {
	return ccall.CallIntVoid(a.func12)
}

func (a *guiAnim) Func13() int {
	return ccall.CallIntVoid(a.func13)
}

func (a *guiAnim) doOut() {
	p := a.Window().Offs()
	p = p.Add(a.outDp.Mul(gui.AnimSpeed))

	maxed := 0

	if mx := a.p2.X; a.outDp.X >= 0 {
		if p.X >= mx {
			p.X = mx
			maxed++
		}
	} else {
		if p.X <= mx {
			p.X = mx
			maxed++
		}
	}
	if my := a.p2.Y; a.outDp.Y >= 0 {
		if p.Y >= my {
			p.Y = my
			maxed++
		}
	} else {
		if p.Y <= my {
			p.Y = my
			maxed++
		}
	}

	a.Window().SetPos(p)
	if maxed == 2 {
		a.SetState(gui.AnimOutDone)
		sub_43BE40(1)
		if a.fncDoneOut != nil {
			ccall.CallIntVoid(a.fncDoneOut)
		}
	}
}

func (a *guiAnim) doIn() {
	p := a.Window().Offs()
	p = p.Add(a.inDp.Mul(gui.AnimSpeed))

	maxed := 0

	if mx := a.p1.X; a.inDp.X >= 0 {
		if p.X >= mx {
			p.X = mx
			maxed++
		}
	} else {
		if p.X <= mx {
			p.X = mx
			maxed++
		}
	}
	if my := a.p1.Y; a.inDp.Y >= 0 {
		if p.Y >= my {
			p.Y = my
			maxed++
		}
	} else {
		if p.Y <= my {
			p.Y = my
			maxed++
		}
	}

	a.Window().SetPos(p)
	if maxed == 2 {
		a.SetState(gui.AnimInDone)
		sub_43BE40(0)
		if a.fncDoneIn != nil {
			ccall.CallVoidVoid(a.fncDoneIn)
		}
		guiFocusMainBg()
	}
}

func guiAnimationStep() {
	var next *guiAnim
	for a := guiAnimationsHead; a != nil; a = next {
		next = a.Next()
		if a.State() == gui.AnimOut {
			a.doOut()
		} else if a.State() == gui.AnimIn {
			a.doIn()
		}
	}
}

func nox_gui_findAnimationForDest_43C520(dest gui.StateID) *guiAnim {
	for p := guiAnimationsHead; p != nil; p = p.Next() {
		if gui.StateID(p.field0) == dest {
			return p
		}
	}
	return nil
}

func newGUIAnimation(win *gui.Window) *guiAnim {
	p, _ := alloc.New(guiAnim{})
	p.win = win
	p.next = guiAnimationsHead
	if guiAnimationsHead != nil {
		guiAnimationsHead.prev = p
	}
	guiAnimationsHead = p
	return p
}

//export nox_gui_freeAnimation_43C570
func nox_gui_freeAnimation_43C570(a *C.nox_gui_animation) {
	asGUIAnim(a).Free()
}

func (a *guiAnim) Free() {
	if a == nil {
		return
	}
	if next := a.Next(); next != nil {
		next.prev = a.Prev()
	}
	if prev := a.Prev(); prev != nil {
		prev.next = a.Next()
	} else {
		guiAnimationsHead = a.Next()
	}
	alloc.Free(unsafe.Pointer(a))
}

//export nox_gui_makeAnimation_43C5B0
func nox_gui_makeAnimation_43C5B0(win *C.nox_window, x1, y1, x2, y2, in_dx, in_dy, out_dx, out_dy C.int) *C.nox_gui_animation {
	return nox_gui_makeAnimation(asWindow(win), int(x1), int(y1), int(x2), int(y2), int(in_dx), int(in_dy), int(out_dx), int(out_dy)).C()
}
func nox_gui_makeAnimation(win *gui.Window, x1, y1, x2, y2, inDx, inDy, outDx, outDy int) *guiAnim {
	a := newGUIAnimation(win)
	win.SetPos(image.Point{X: x2, Y: y2})
	a.p1 = image.Pt(x1, y1)
	a.p2 = image.Pt(x2, y2)
	a.inDp = image.Pt(inDx, inDy)
	a.outDp = image.Pt(outDx, outDy)
	a.SetState(gui.AnimIn)
	sub_43BE40(3)
	clientPlaySoundSpecial(sound.SoundShellSlideIn, 100)
	a.func12 = nil
	a.fncDoneOut = nil
	a.fncDoneIn = nil
	return a
}
