package gui

import (
	"image"
	"unsafe"

	noxcolor "github.com/noxworld-dev/opennox-lib/color"

	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
)

const deadWord = 0xacacacac

type WindowFunc func(win *Window, ev WindowEvent) WindowEventResp
type WindowDrawFunc func(win *Window, draw *WindowData) int
type WindowTooltipFunc func(win *Window, draw *WindowData, a3 uintptr) int

type WindowFuncLegacy = func(*Window, uintptr, uintptr, uintptr) uintptr

func WrapFunc(fnc WindowFuncLegacy) WindowFunc {
	if fnc == nil {
		return nil
	}
	return func(win *Window, e WindowEvent) WindowEventResp {
		ev := e.EventCode()
		a1, a2 := e.EventArgsC()
		r := fnc(win, uintptr(ev), a1, a2)
		if r == 0 {
			return nil
		}
		return RawEventResp(r)
	}
}

type windowExt struct {
	GUI    *GUI
	Func93 WindowFunc
	Func94 WindowFunc
	Draw   WindowDrawFunc
}

type WidgetData interface {
	CWidgetData() unsafe.Pointer
}

type Window struct {
	id             int32                         // 0, 0
	Flags          StatusFlags                   // 1, 4
	size           image.Point                   // 2, 8
	Off            image.Point                   // 4, 16
	EndPos         image.Point                   // 6, 24
	WidgetData     unsafe.Pointer                // 8, 32; different types
	drawData       WindowData                    // 9, 36
	field92        uint32                        // 92, 368
	field93        ccall.Func[WindowFuncLegacy]  // 93
	field94        ccall.Func[WindowFuncLegacy]  // 94, 376
	drawFunc       ccall.Func[WindowDrawFunc]    // 95, 380, second arg is &field_9
	TooltipFuncPtr ccall.Func[WindowTooltipFunc] // 96, 384
	prev           *Window                       // 97, 388
	next           *Window                       // 98, 392
	parent         *Window                       // 99, 396
	field100       *Window                       // 100, 400
}

func (win *Window) C() unsafe.Pointer {
	return unsafe.Pointer(win)
}

func (win *Window) ID() uint {
	if win.isNilOrDead() {
		return 0
	}
	return uint(win.id)
}

func (win *Window) SetID(id uint) int {
	if win.isNilOrDead() {
		return -2
	}
	win.id = int32(id)
	return 0
}

func (win *Window) GetFlags() StatusFlags {
	if win.isNilOrDead() {
		return 0
	}
	return win.Flags
}

func (win *Window) Offs() image.Point { // nox_gui_getWindowOffs_46AA20
	if win.isNilOrDead() {
		return image.Point{}
	}
	return win.Off
}

func (win *Window) SetOffs(p image.Point) {
	win.Off = p
}

func (win *Window) End() image.Point {
	if win.isNilOrDead() {
		return image.Point{}
	}
	return win.EndPos
}

func (win *Window) SetEnd(p image.Point) {
	win.EndPos = p
}

func (win *Window) Size() image.Point {
	if win.isNilOrDead() {
		return image.Point{}
	}
	return win.size
}

func (win *Window) DrawData() *WindowData {
	return &win.drawData
}

func (win *Window) CopyDrawData(p *WindowData) int {
	if win == nil {
		return -2
	}
	if p == nil {
		return -3
	}
	win.drawData = *p
	return 0
}

func (win *Window) PointIn(p image.Point) bool {
	off, end := win.Offs(), win.End()
	return p.X >= off.X && p.X <= end.X && p.Y >= off.Y && p.Y <= end.Y
}

func (win *Window) Next() *Window {
	if win == nil {
		return nil
	}
	return win.next
}

func (win *Window) Prev() *Window {
	if win == nil {
		return nil
	}
	return win.prev
}

func (win *Window) Parent() *Window {
	if win == nil {
		return nil
	}
	return win.parent
}

func (win *Window) setParent(par *Window) {
	if par == nil {
		return
	}
	win.next = nil
	v2 := par.field100
	win.prev = v2
	if v2 != nil {
		v2.next = win
	}
	par.field100 = win
	win.parent = par
}

func (win *Window) SetParent(par *Window) int {
	if win == nil {
		return -2
	}
	return win.GUI().setParent(win, par)
}

func (win *Window) Field100() *Window {
	if win == nil {
		return nil
	}
	return win.field100
}

func (win *Window) Show() {
	if win.isNilOrDead() {
		return
	}
	win.Flags &^= StatusHidden
}

func (win *Window) ToggleHidden() {
	if win.isNilOrDead() {
		return
	}
	win.SetHidden(!win.GetFlags().IsHidden())
}

func (win *Window) SetHidden(hidden bool) {
	if win.isNilOrDead() {
		return
	}
	if hidden {
		win.Hide()
	} else {
		win.Show()
	}
}

func (win *Window) Hide() {
	if win.isNilOrDead() {
		return
	}
	g := win.GUI()
	if g.ValXXX != 0 {
		if !win.Flags.IsHidden() {
			g.ValXXX = 1
		}
	}
	win.Flags |= StatusHidden
}

func (win *Window) GlobalPos() image.Point { // nox_client_wndGetPosition_46AA60
	if win.isNilOrDead() {
		return image.Point{}
	}
	pos := win.Offs()
	for it := win.Parent(); it != nil; it = it.Parent() {
		pos = pos.Add(it.Offs())
	}
	return pos
}

func (win *Window) IsChild(win2 *Window) bool {
	if win.isNilOrDead() || win2.isNilOrDead() {
		return false
	}
	for cur := win2.Parent(); cur != nil; cur = cur.Parent() {
		if win == cur {
			return true
		}
	}
	return false
}

func (win *Window) ChildByID(id uint) *Window {
	if win.isNilOrDead() {
		return nil
	}
	for cur := win; cur != nil; cur = cur.Prev() {
		if cur.ID() == id {
			return cur
		}
		if sub := cur.field100; sub != nil {
			if res := sub.ChildByID(id); res != nil {
				return res
			}
		}
	}
	return nil
}

func (win *Window) ChildByPos(p image.Point) *Window {
	if win.isNilOrDead() {
		return nil
	}
	cur := win
loop:
	for it1 := cur.Field100(); it1 != nil; it1 = it1.Prev() {
		sz := it1.Size()
		off := it1.Offs()
		for it2 := it1.Parent(); it2 != nil; it2 = it2.Parent() {
			off = off.Add(it2.Offs())
		}
		if p.X >= off.X && p.X <= off.X+sz.X && p.Y >= off.Y && p.Y <= off.Y+sz.Y {
			if f := it1.GetFlags(); f.Has(8) && !f.Has(0x10) {
				cur = it1
				goto loop
			}
		}
	}
	return cur
}

func (win *Window) SetFunc93(fnc WindowFunc) { // nox_xxx_wndSetWindowProc_46B300
	if win.isNilOrDead() {
		return
	}
	if fnc == nil {
		fnc = func(win *Window, ev WindowEvent) WindowEventResp { return nil }
	}
	win.ext().Func93 = fnc
}

func (win *Window) SetFunc94(fnc WindowFunc) { // nox_xxx_wndSetProc_46B2C0
	if win.isNilOrDead() {
		return
	}
	if fnc == nil {
		fnc = func(win *Window, ev WindowEvent) WindowEventResp { return nil }
	}
	win.ext().Func94 = fnc
}

func (win *Window) SetDraw(fnc WindowDrawFunc) { // nox_xxx_wndSetDrawFn_46B340
	if win.isNilOrDead() {
		return
	}
	if fnc == nil {
		fnc = drawDefault
	}
	win.ext().Draw = fnc
}

func (win *Window) SetTooltipFunc(fnc WindowTooltipFunc) {
	if win.isNilOrDead() {
		return
	}
	win.TooltipFuncPtr.Set(fnc)
}

func (win *Window) SetAllFuncs(a2 WindowFunc, draw WindowDrawFunc, tooltip WindowTooltipFunc) {
	if win.isNilOrDead() {
		return
	}
	win.SetFunc93(a2)
	win.SetDraw(draw)
	win.SetTooltipFunc(tooltip)
}

func (win *Window) SetPos(pos image.Point) {
	if win.isNilOrDead() {
		return
	}
	sz := win.Size()
	win.SetOffs(pos)
	win.SetEnd(pos.Add(sz))
	win.fixCoords()
}

func (win *Window) fixCoords() {
	off := win.Offs()
	end := win.End()
	change := false
	if off.X > end.X {
		off.X, end.X = end.X, off.X
		change = true
	}
	if off.Y > end.Y {
		off.Y, end.Y = end.Y, off.Y
		change = true
	}
	if change {
		win.SetOffs(off)
		win.SetEnd(end)
	}
}

func (win *Window) Func93(e WindowEvent) WindowEventResp {
	if win.isNilOrDead() {
		return nil
	}
	if ext := win.ext(); ext != nil && ext.Func93 != nil {
		return ext.Func93(win, e)
	}
	if ptr := win.field93.Ptr(); ptr == nil || uintptr(ptr) == deadWord {
		return nil
	}
	ev := e.EventCode()
	a1, a2 := e.EventArgsC()
	r := win.field93.Get()(win, uintptr(ev), a1, a2)
	if r == 0 {
		return nil
	}
	return RawEventResp(r)
}

func (win *Window) GetFunc94() WindowFuncLegacy {
	return win.field94.Get()
}

func (win *Window) Func94(e WindowEvent) WindowEventResp {
	if win.isNilOrDead() {
		return nil
	}
	if ext := win.ext(); ext != nil && ext.Func94 != nil {
		return ext.Func94(win, e)
	}
	if ptr := win.field94.Ptr(); ptr == nil || uintptr(ptr) == deadWord {
		return nil
	}
	ev := e.EventCode()
	a1, a2 := e.EventArgsC()
	r := win.field94.Get()(win, uintptr(ev), a1, a2)
	if r == 0 {
		return nil
	}
	return RawEventResp(r)
}

func (win *Window) Draw() {
	if win.isNilOrDead() {
		return
	}
	if ext := win.ext(); ext != nil && ext.Draw != nil {
		ext.Draw(win, win.DrawData())
		return
	}
	if ptr := win.drawFunc.Ptr(); ptr == nil || uintptr(ptr) == deadWord {
		return
	}
	win.drawFunc.Get()(win, win.DrawData())
}

func (win *Window) TooltipFunc(a1 uintptr) {
	if win.isNilOrDead() {
		return
	}
	if ptr := win.TooltipFuncPtr.Ptr(); ptr == nil || uintptr(ptr) == deadWord {
		return
	}
	win.TooltipFuncPtr.Get()(win, win.DrawData(), a1)
}

func (win *Window) Focus() {
	if win.isNilOrDead() {
		return
	}
	win.GUI().Focus(win)
}

func (win *Window) Capture(enable bool) bool {
	if win.isNilOrDead() {
		return false
	}
	g := win.GUI()
	if !enable {
		g.uncapture(win)
		return true
	}
	return g.capture(win)
}

func (win *Window) ShowModal() int {
	if win.isNilOrDead() {
		return -2
	}
	return win.GUI().showModal(win)
}

func (win *Window) StackPush() int {
	if win.isNilOrDead() {
		return -2
	}
	return win.GUI().stackPush(win)
}

func (win *Window) StackPop() int { // nox_xxx_wnd_46C6E0
	if win.isNilOrDead() {
		return -2
	}
	return win.GUI().stackPop(win)
}

func (win *Window) Destroy() {
	if win.isNilOrDead() {
		return
	}
	win.GUI().destroyWindow(win)
}

func (win *Window) drawRecursive() bool {
	if win.isNilOrDead() {
		return false
	}
	if win.GetFlags().IsHidden() {
		return true
	}
	win.Draw()
	if win.Flags.Has(StatusBorder) {
		win.GUI().drawWindowBorder(win)
	}

	for sub := win.field100; sub != nil; sub = sub.Prev() {
		sub.drawRecursive()
	}
	return true
}

func (win *Window) unlink() {
	next := win.Next()
	prev := win.Prev()
	if next != nil {
		next.prev = prev
		if prev != nil {
			prev.next = win.Next()
		}
	} else if prev != nil {
		win.Parent().field100 = prev
		win.Prev().next = win.Next()
		win.prev = nil
	} else {
		win.Parent().field100 = nil
	}
}

func drawDefault(win *Window, draw *WindowData) int {
	g := win.GUI()
	gpos := win.GlobalPos()
	if !win.Flags.Has(StatusImage) {
		if draw.BackgroundColor().Color32() != noxcolor.TransparentRGBA5551.Color32() {
			g.r.DrawRectFilledOpaque(gpos.X, gpos.Y, win.Size().X, win.Size().Y, draw.BackgroundColor())
		}
		return 1
	}
	ipt := win.DrawData().ImagePoint()
	gpos = gpos.Add(ipt)
	// TODO: was DrawImageAt
	if win.DrawData().Field0&2 != 0 {
		if img := draw.HighlightImage(); img != nil {
			g.r.DrawImage16(img, gpos)
		}
	} else {
		if img := draw.BackgroundImage(); img != nil {
			g.r.DrawImage16(img, gpos)
		}
	}
	return 1
}
