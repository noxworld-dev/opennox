package gui

import (
	"fmt"
	"image"
	"sync"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/client/keybind"

	"github.com/noxworld-dev/opennox/v1/client/input"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

var (
	emu     sync.RWMutex
	exts    = make(map[*Window]*windowExt)
	extData = make(map[*WindowData]*windowExt)

	MainBg *Window
)

func FocusMainBg() {
	MainBg.Focus()
}

func setExt(win *Window, ext *windowExt) {
	emu.Lock()
	if ext == nil {
		delete(exts, win)
		delete(extData, win.DrawData())
	} else {
		exts[win] = ext
		extData[win.DrawData()] = ext
	}
	emu.Unlock()
}

func (win *Window) ext() *windowExt {
	if win == nil {
		return nil
	}
	emu.RLock()
	ext := exts[win]
	emu.RUnlock()
	return ext
}

func (win *Window) isNilOrDead() bool {
	return win == nil ||
		uint32(win.id) == alloc.DeadWord ||
		uint32(win.Flags) == alloc.DeadWord ||
		win.Flags.Has(StatusDestroyed)
}

func (win *Window) GUI() *GUI {
	if win == nil {
		return nil
	}
	ext := win.ext()
	if ext == nil {
		if win.isNilOrDead() {
			panic(fmt.Errorf("no GUI for deallocated Window(%p), id: 0x%x, flags: 0x%x", win, win.id, uint32(win.Flags)))
		}
		panic(fmt.Errorf("no GUI associated with Window(%p), id: %d, flags: %v", win, win.id, win.Flags))
	}
	return ext.GUI
}

func (d *WindowData) gui() *GUI {
	if d == nil {
		return nil
	}
	if d.Window != nil {
		return d.Window.GUI()
	}
	emu.RLock()
	ext := extData[d]
	emu.RUnlock()
	if ext == nil {
		return nil
	}
	return ext.GUI
}

func New(r *noxrender.NoxRender) *GUI {
	return &GUI{r: r}
}

type windowRef struct {
	Win  *Window
	Next *windowRef
}

type GUI struct {
	r       *noxrender.NoxRender
	borders Borders
	alloc   alloc.ClassT[Window]

	captured *Window
	stack    *windowRef
	head     *Window
	last     *Window
	focused  *Window
	free     *Window

	ActiveXXX *Window
	WinYYY    *Window
	ValXXX    int
	ValYYY    int
}

func (g *GUI) SetBorders(b Borders) {
	g.borders = b
}

func (g *GUI) Render() *noxrender.NoxRender {
	return g.r
}

func (g *GUI) NewWindowRaw(parent *Window, status StatusFlags, px, py, w, h int, fnc94 WindowFunc) *Window {
	if g.alloc.Class == nil {
		g.alloc = alloc.NewClassT("Window", Window{}, 576)
	}
	win := g.alloc.NewObject()
	setExt(win, &windowExt{GUI: g})
	if parent != nil {
		win.setParent(parent)
	} else {
		g.add(win)
	}
	win.SetID(0)
	win.Flags = status
	win.SizeVal.X = w
	win.SizeVal.Y = h
	win.SetPos(image.Point{X: px, Y: py})
	win.drawData.tooltip[0] = 0
	win.SetDraw(nil)
	win.SetFunc93(nil)
	win.SetFunc94(fnc94)
	if fnc94 != nil {
		fnc94(win, WindowInit{})
	}
	win.Field92Val = 0
	return win
}

func (g *GUI) NewUserWindow(parent *Window, id uint, status StatusFlags, px, py, w, h int, drawData *WindowData, fnc WindowFunc) *Window {
	win := g.NewWindowRaw(parent, status, px, py, w, h, fnc)
	drawData.Style |= StyleUserWindow
	win.SetID(id)
	win.CopyDrawData(drawData)
	if parent != nil {
		parent.Func94(WindowNewChild{ID: id})
	}
	return win
}

func (g *GUI) GameexCheck() bool {
	return g.free == nil && g.ActiveXXX == nil
}

func (g *GUI) Draw() {
	// back layer (background and some UI parts)
	for win := g.head; win != nil; win = win.Next() {
		if win.GetFlags().Has(StatusBelow) {
			win.drawRecursive()
		}
	}
	// middle layer
	for win := g.head; win != nil; win = win.Next() {
		if win.GetFlags().HasNone(StatusBelow | StatusAbove) {
			win.drawRecursive()
		}
	}
	// front layer
	for win := g.head; win != nil; win = win.Next() {
		if win.GetFlags().Has(StatusAbove) {
			win.drawRecursive()
		}
	}
}

func (g *GUI) Last() *Window {
	return g.last
}

func (g *GUI) ChildByID(id uint) *Window {
	return g.last.ChildByID(id)
}

func (g *GUI) Focus(win *Window) {
	if g == nil {
		return
	}
	if win != nil && win.GetFlags().Has(0x400) {
		return
	}
	if g.focused != nil && g.focused != win {
		g.focused.Func94(WindowFocus(false))
	}
	g.focused = win
	for cur := win; cur != nil; cur = cur.Parent() {
		if EventRespBool(cur.Func94(WindowFocus(true))) {
			return
		}
	}
	g.focused = nil
}

func (g *GUI) Focused() *Window {
	return g.focused
}

func (g *GUI) add(win *Window) {
	win.NextPtr = nil
	win.PrevPtr = g.last
	if g.last != nil {
		g.last.NextPtr = win
	} else {
		g.head = win
	}
	g.last = win
}

func (g *GUI) remove(win *Window) {
	prev := win.Prev()
	next := win.Next()
	if prev != nil {
		prev.NextPtr = next
	} else {
		g.head = next
	}
	if next != nil {
		next.PrevPtr = prev
	} else {
		g.last = prev
	}
}

func (g *GUI) capture(win *Window) bool {
	if g.captured != nil || win == nil {
		return false
	}
	g.captured = win
	return true
}

func (g *GUI) uncapture(win *Window) {
	if g.captured == win {
		g.captured = nil
	}
}

func (g *GUI) Captured() *Window {
	return g.captured
}

func (g *GUI) ProcessKeys(inp *input.Handler) {
	for _, key := range inp.KeyboardKeys() {
		g.processKey(inp, key)
	}
}

func (g *GUI) processKey(inp *input.Handler, key keybind.Key) {
	if g.focused == nil {
		return
	}
	if key == 0 {
		return
	}
	if inp.GetKeyFlag(key) {
		return
	}
	ok := false
	for win := g.focused; win != nil; win = win.Parent() {
		if EventRespBool(win.Func93(WindowKeyPress{Key: key, Pressed: inp.IsPressed(key)})) {
			ok = true
			break
		}
	}
	inp.SetKeyFlag(key, ok)
}

func (g *GUI) StackHead() *Window {
	if g.stack == nil {
		return nil
	}
	return g.stack.Win
}

func (g *GUI) stackPush(win *Window) int {
	if win == nil {
		return -2
	}
	if win.Parent() != nil {
		return -3
	}
	g.stack = &windowRef{Next: g.stack, Win: win}
	return 0
}

func (g *GUI) stackPop(win *Window) int {
	if win == nil {
		return -2
	}
	if g.stack == nil || g.stack.Win != win {
		return -1
	}
	g.stack = g.stack.Next
	return 0
}

func (g *GUI) FreeDestroyed() {
	win := g.free
	g.free = nil
	for win != nil {
		prev := win.Prev()
		win.PrevPtr = nil
		if g.captured == win {
			g.captured = nil
		}
		if g.focused == win {
			g.Focus(nil)
		}
		if g.stack != nil && win == g.stack.Win {
			g.stackPop(g.stack.Win)
		}
		if g.ActiveXXX == win {
			g.ActiveXXX = nil
		}
		if g.WinYYY == win {
			g.WinYYY = nil
		}
		win.Func94(WindowDestroy{})
		setExt(win, nil)
		g.alloc.FreeObjectFirst(win)
		win = prev
	}
}

func (g *GUI) destroyWindow(win *Window) {
	if win == nil {
		return
	}
	if win.GetFlags().Has(StatusDestroyed) {
		return
	}
	win.Flags |= StatusDestroyed

	if g.captured == win {
		g.captured = nil
	}
	if g.focused == win {
		g.Focus(nil)
	}
	if g.stack != nil && win == g.stack.Win {
		g.stackPop(g.stack.Win)
	}
	if g.ActiveXXX == win {
		g.ActiveXXX = nil
	}
	if g.WinYYY == win {
		g.WinYYY = nil
	}
	v3 := win.Field100()
	for v3 != nil {
		v4 := v3.Prev()
		g.destroyWindow(v3)
		v3 = v4
	}
	if win.Parent() != nil {
		win.unlink()
	} else {
		g.remove(win)
	}
	win.NextPtr = nil
	win.PrevPtr = g.free
	g.free = win

	ext := win.ext()
	// clear everything except GUI reference
	*ext = windowExt{GUI: ext.GUI}
}

func (g *GUI) showModal(win *Window) int {
	if win == nil {
		return -2
	}
	for it := g.last; it != nil; it = it.Prev() {
		if it == win {
			g.remove(win)
			g.add(win)
			win.Flags |= StatusActive
			win.Show()
			return 0
		}
	}
	return -3
}

func (g *GUI) DestroyAll() {
	var prev *Window
	for it := g.last; it != nil; it = prev {
		prev = it.Prev()
		it.Destroy()
	}
	g.FreeDestroyed()
	g.alloc.FreeAllObjects()
}

func (g *GUI) setParent(win, par *Window) int {
	if win == nil {
		return -2
	}
	if win.Parent() != nil {
		win.unlink()
	} else {
		g.remove(win)
	}
	if par != nil {
		win.setParent(par)
	} else {
		g.add(win)
		win.ParentPtr = nil
	}
	return 0
}

func (g *GUI) drawWindowBorder(win *Window) {
	data := win.DrawData()
	gpos := win.GlobalPos()
	sz := win.Size()

	for i := 0; i < 32; i++ {
		flag := data.Style & (1 << i)
		if flag == 0 {
			continue
		}
		switch flag {
		case StylePushButton, StyleRadioButton, StyleStaticText, StyleProgressBar, StyleUserWindow:
			g.borders.Draw(g.r, gpos.X, gpos.Y, sz.X, sz.Y)
			return
		case StyleCheckBox, StyleVertSlider, StyleHorizSlider:
			return
		case StyleScrollListBox:
			ptr := win.WidgetData
			dsx := 0
			dy := 0
			if *(*uint32)(unsafe.Add(ptr, 12)) != 0 {
				p1 := *(**Window)(unsafe.Add(ptr, 36))
				p2 := p1.Field100()
				dsx = p2.Size().Y
			}
			if data.Text() != "" {
				dy = 4
			}
			g.borders.Draw(g.r, gpos.X-3, gpos.Y-dy-3, sz.X-dsx+3, sz.Y+6)
			return
		case StyleEntryField:
			v9 := gpos.X
			ptr := win.WidgetData

			sx := sz.X
			x := gpos.X
			dy := 0
			if text := data.Text(); text != "" {
				tsz := g.r.GetStringSizeWrapped(data.Font(), text, 0)
				x += tsz.X + 6
				sx -= tsz.X + 6
			}
			v14 := int(int16(*(*uint16)(unsafe.Add(ptr, 1042))))
			if int32(v14) > 0 && sx > v14 {
				sx = v14
				x = v9 + sz.X - v14
			}
			g.borders.Draw(g.r, x, gpos.Y+dy, sx, sz.Y)
			return
		}
	}
}

func (b *Borders) Draw(r *noxrender.NoxRender, x, y, w, h int) {
	x1 := x + 10
	x2 := x + w - 30
	x3 := x + w
	x4 := x + w

	y1 := y - 10
	y2 := y - 10
	y3 := y + h - 10
	if x1 <= x2 {
		for {
			r.DrawImage16(b.Horizontal, image.Pt(x1, y1))
			r.DrawImage16(b.Horizontal, image.Pt(x1, y3))
			x1 += 20
			if x1 > x2 {
				break
			}
		}
		x4 = x3
	}
	x5 := x4 - 10
	if x5-x1 >= 10 {
		r.DrawImage16(b.HorizontalShort, image.Pt(x1, y1))
		r.DrawImage16(b.HorizontalShort, image.Pt(x1, y3))
		x1 += 10
	}
	if x1 < x5 {
		v10 := int(uint32(x1) + (uint32(x5-x1+1) & 0xFFFFFFFE) - 10)
		r.DrawImage16(b.HorizontalShort, image.Pt(v10, y1))
		r.DrawImage16(b.HorizontalShort, image.Pt(v10, y3))
	}
	y4 := y + 10
	x6 := x - 10
	y5 := y + h - 30
	for y4 <= y5 {
		r.DrawImage16(b.Vertical, image.Pt(x6, y4))
		r.DrawImage16(b.Vertical, image.Pt(x5, y4))
		y4 += 20
	}
	if y3-y4 >= 10 {
		r.DrawImage16(b.VerticalShort, image.Pt(x6, y4))
		r.DrawImage16(b.VerticalShort, image.Pt(x5, y4))
		y4 += 10
	}
	if y4 < y3 {
		v16 := int(uint32(y4) + (uint32(y3-y4+1) & 0xFFFFFFFE) - 10)
		r.DrawImage16(b.VerticalShort, image.Pt(x6, v16))
		r.DrawImage16(b.VerticalShort, image.Pt(x5, v16))
	}
	r.DrawImage16(b.CornerUL, image.Pt(x6, y2))
	r.DrawImage16(b.CornerUR, image.Pt(x5, y2))
	r.DrawImage16(b.CornerLL, image.Pt(x6, y3))
	r.DrawImage16(b.CornerLR, image.Pt(x5, y3))
}
