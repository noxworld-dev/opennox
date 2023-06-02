package gui

import (
	"image"

	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
)

var (
	AnimSpeed = 1

	animList        *Anim
	animGlobalState AnimState
)

func SetAnimGlobalState(st AnimState) {
	animGlobalState = st
}

func AnimGlobalState() AnimState {
	return animGlobalState
}

type AnimState int

const (
	AnimInDone  = AnimState(0)
	AnimOutDone = AnimState(1)
	AnimOut     = AnimState(2)
	AnimIn      = AnimState(3)
)

func AnimTick() {
	var next *Anim
	for a := animList; a != nil; a = next {
		next = a.next
		if a.State() == AnimOut {
			a.doOut()
		} else if a.State() == AnimIn {
			a.doIn()
		}
	}
}

func FindAnimForStateID(dest StateID) *Anim {
	for p := animList; p != nil; p = p.next {
		if p.StateID == dest {
			return p
		}
	}
	return nil
}

func NewAnim(win *Window, p1, p2, dpIn, dpOut image.Point) *Anim {
	a := newAnim(win)
	win.SetPos(p2)
	a.p1 = p1
	a.p2 = p2
	a.dpIn = dpIn
	a.dpOut = dpOut
	a.Func12Ptr.Set(nil)
	a.FncDoneOutPtr.Set(nil)
	a.FncDoneInPtr.Set(nil)
	a.SetState(AnimIn)
	SetAnimGlobalState(AnimIn)
	return a
}

func newAnim(win *Window) *Anim {
	a, _ := alloc.New(Anim{})
	a.win = win
	a.next = animList
	if animList != nil {
		animList.prev = a
	}
	animList = a
	return a
}

type Anim struct {
	StateID       StateID                // 0, 0
	win           *Window                // 1, 4
	p2            image.Point            // 2, 8
	p1            image.Point            // 4, 16
	dpOut         image.Point            // 6, 24
	dpIn          image.Point            // 8, 32
	next          *Anim                  // 10, 40
	prev          *Anim                  // 11, 44
	Func12Ptr     ccall.Func[func() int] // // 12, 48; func() int
	Func13Ptr     ccall.Func[func() int] // 13, 52; func() int
	FncDoneOutPtr ccall.Func[func() int] // 14, 56; func() int
	FncDoneInPtr  ccall.Func[func()]     // 15, 60; func()
	state         AnimState              // 16, 64
}

func (a *Anim) Free() {
	if a == nil {
		return
	}
	if next := a.next; next != nil {
		next.prev = a.prev
	}
	if prev := a.prev; prev != nil {
		prev.next = a.next
	} else {
		animList = a.next
	}
	alloc.Free(a)
}

func (a *Anim) State() AnimState {
	if a == nil {
		return -1
	}
	return a.state
}

func (a *Anim) SetState(s AnimState) {
	a.state = s
}

func (a *Anim) Window() *Window {
	if a == nil {
		return nil
	}
	return a.win
}

func (a *Anim) Func12() int {
	return a.Func12Ptr.Get()()
}

func (a *Anim) Func13() int {
	return a.Func13Ptr.Get()()
}

func (a *Anim) doOut() {
	p := a.Window().Offs()
	p = p.Add(a.dpOut.Mul(AnimSpeed))

	maxed := 0

	if mx := a.p2.X; a.dpOut.X >= 0 {
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
	if my := a.p2.Y; a.dpOut.Y >= 0 {
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
		a.SetState(AnimOutDone)
		SetAnimGlobalState(AnimOutDone)
		if fnc := a.FncDoneOutPtr.Get(); fnc != nil {
			fnc()
		}
	}
}

func (a *Anim) doIn() {
	p := a.Window().Offs()
	p = p.Add(a.dpIn.Mul(AnimSpeed))

	maxed := 0

	if mx := a.p1.X; a.dpIn.X >= 0 {
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
	if my := a.p1.Y; a.dpIn.Y >= 0 {
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
		a.SetState(AnimInDone)
		SetAnimGlobalState(AnimInDone)
		if fnc := a.FncDoneInPtr.Get(); fnc != nil {
			fnc()
		}
		FocusMainBg()
	}
}
