package gui

import (
	"image"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/client/keybind"

	"github.com/noxworld-dev/opennox/v1/client/input"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
)

var (
	Renderer *noxrender.NoxRender

	borders Borders

	Nox_win_cur_input            *Window
	Nox_win_1064912              *WindowRef
	nox_win_xxx1_first           *Window
	nox_win_xxx1_last            *Window
	nox_win_cur_focused          *Window
	nox_win_freeList             *Window
	Nox_win_activeWindow_1064900 *Window
	Nox_win_1064916              *Window
)

func SetBorders(b Borders) {
	borders = b
}

func GameexCheck() bool {
	return nox_win_freeList == nil && Nox_win_activeWindow_1064900 == nil
}

func DrawGUI() {
	// back layer (background and some UI parts)
	for win := nox_win_xxx1_first; win != nil; win = win.Next() {
		if win.GetFlags().Has(StatusBelow) {
			win.drawRecursive()
		}
	}
	// middle layer
	for win := nox_win_xxx1_first; win != nil; win = win.Next() {
		if win.GetFlags().HasNone(StatusBelow | StatusAbove) {
			win.drawRecursive()
		}
	}
	// front layer
	for win := nox_win_xxx1_first; win != nil; win = win.Next() {
		if win.GetFlags().Has(StatusAbove) {
			win.drawRecursive()
		}
	}
}

func Last() *Window {
	return nox_win_xxx1_last
}

type WindowRef struct {
	Win  *Window
	Next *WindowRef
}

func GUIChildByID(id uint) *Window {
	return nox_win_xxx1_last.ChildByID(id)
}

func Focus(win *Window) {
	if win != nil && win.GetFlags().Has(0x400) {
		return
	}
	if nox_win_cur_focused != nil && nox_win_cur_focused != win {
		nox_win_cur_focused.Func94(WindowFocus(false))
	}
	nox_win_cur_focused = win
	for cur := win; cur != nil; cur = cur.Parent() {
		if EventRespBool(cur.Func94(WindowFocus(true))) {
			return
		}
	}
	nox_win_cur_focused = nil
}

func Focused() *Window {
	return nox_win_cur_focused
}

func nox_client_wndListXxxAdd_46A920(win *Window) {
	win.next = nil
	win.prev = nox_win_xxx1_last
	if nox_win_xxx1_last != nil {
		nox_win_xxx1_last.next = win
	} else {
		nox_win_xxx1_first = win
	}
	nox_win_xxx1_last = win
}

func nox_client_wndListXxxRemove_46A960(win *Window) {
	prev := win.Prev()
	next := win.Next()
	if prev != nil {
		prev.next = next
	} else {
		nox_win_xxx1_first = next
	}
	if next != nil {
		next.prev = prev
	} else {
		nox_win_xxx1_last = prev
	}
}

func sub_46B180(win *Window) {
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

func Nox_xxx_wndSetCaptureMain(win *Window) int {
	if Nox_win_cur_input != nil {
		return -4
	}
	Nox_win_cur_input = win
	return 0
}

func Nox_xxx_wndClearCaptureMain(win *Window) int {
	if win == Nox_win_cur_input {
		Nox_win_cur_input = nil
	}
	return 0
}

func Nox_xxx_wndGetCaptureMain() *Window {
	return Nox_win_cur_input
}

func Nox_client_getWin1064916_46C720() *Window {
	return Nox_win_1064916
}

func Nox_xxx_windowUpdateKeysMB_46B6B0(inp *input.Handler, key keybind.Key) {
	root := nox_win_cur_focused
	if root == nil {
		return
	}
	if key == 0 {
		return
	}
	if inp.GetKeyFlag(key) {
		return
	}
	ok := false
	for win := root; win != nil; win = win.Parent() {
		if EventRespBool(win.Func93(WindowKeyPress{Key: key, Pressed: inp.IsPressed(key)})) {
			ok = true
			break
		}
	}
	inp.SetKeyFlag(key, ok)
}

func Nox_xxx_wnd46C6E0(win *Window) int { // nox_xxx_wnd_46C6E0
	if win == nil {
		return -2
	}
	if Nox_win_1064912 == nil || Nox_win_1064912.Win != win {
		return -1
	}
	Nox_win_1064912 = Nox_win_1064912.Next
	return 0
}

func FreeAllWindowsInList() {
	win := nox_win_freeList
	nox_win_freeList = nil
	for win != nil {
		prev := win.Prev()
		win.prev = nil
		if Nox_win_cur_input == win {
			Nox_win_cur_input = nil
		}
		if nox_win_cur_focused == win {
			Focus(nil)
		}
		if Nox_win_1064912 != nil && win == Nox_win_1064912.Win {
			Nox_xxx_wnd46C6E0(Nox_win_1064912.Win)
		}
		if Nox_win_activeWindow_1064900 == win {
			Nox_win_activeWindow_1064900 = nil
		}
		if Nox_win_1064916 == win {
			Nox_win_1064916 = nil
		}
		win.Func94(WindowDestroy{})
		nox_alloc_window.FreeObjectFirst(win)
		win = prev
	}
}

func destroyWindow(win *Window) {
	if win == nil {
		return
	}
	if win.GetFlags().Has(StatusDestroyed) {
		return
	}
	win.Flags |= StatusDestroyed
	delete(winExts, win)

	if Nox_win_cur_input == win {
		Nox_win_cur_input = nil
	}
	if nox_win_cur_focused == win {
		Focus(nil)
	}
	if Nox_win_1064912 != nil && win == Nox_win_1064912.Win {
		Nox_xxx_wnd46C6E0(Nox_win_1064912.Win)
	}
	if Nox_win_activeWindow_1064900 == win {
		Nox_win_activeWindow_1064900 = nil
	}
	if Nox_win_1064916 == win {
		Nox_win_1064916 = nil
	}
	v3 := win.Field100()
	for v3 != nil {
		v4 := v3.Prev()
		destroyWindow(v3)
		v3 = v4
	}
	if win.Parent() != nil {
		sub_46B180(win)
	} else {
		nox_client_wndListXxxRemove_46A960(win)
	}
	win.next = nil
	win.prev = nox_win_freeList
	nox_win_freeList = win
}

func Nox_xxx_wndShowModalMB(win *Window) int {
	if win == nil {
		return -2
	}
	for it := nox_win_xxx1_last; it != nil; it = it.Prev() {
		if it == win {
			nox_client_wndListXxxRemove_46A960(win)
			nox_client_wndListXxxAdd_46A920(win)
			win.Flags |= StatusActive
			win.Show()
			return 0
		}
	}
	return -3
}

func Sub_46C5D0() {
	for it := nox_win_xxx1_last; it != nil; {
		prev := it.Prev()
		it.Destroy()
		it = prev
	}
	FreeAllWindowsInList()
	nox_alloc_window.FreeAllObjects()
}

func Sub46C690(a1 *Window) int {
	if a1 == nil {
		return -2
	}
	if a1.Parent() != nil {
		return -3
	}
	Nox_win_1064912 = &WindowRef{Next: Nox_win_1064912, Win: a1}
	return 0
}

func Sub46B120(win, par *Window) int {
	if win == nil {
		return -2
	}
	if win.Parent() != nil {
		sub_46B180(win)
	} else {
		nox_client_wndListXxxRemove_46A960(win)
	}
	if par != nil {
		win.setParent(par)
	} else {
		nox_client_wndListXxxAdd_46A920(win)
		win.parent = nil
	}
	return 0
}

func drawWindowBorder(win *Window) {
	r := Renderer
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
			borders.Draw(gpos.X, gpos.Y, sz.X, sz.Y)
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
			borders.Draw(gpos.X-3, gpos.Y-dy-3, sz.X-dsx+3, sz.Y+6)
			return
		case StyleEntryField:
			v9 := gpos.X
			ptr := win.WidgetData

			sx := sz.X
			x := gpos.X
			dy := 0
			if text := data.Text(); text != "" {
				tsz := r.GetStringSizeWrapped(data.Font(), text, 0)
				x += tsz.X + 6
				sx -= tsz.X + 6
			}
			v14 := int(int16(*(*uint16)(unsafe.Add(ptr, 1042))))
			if int32(v14) > 0 && sx > v14 {
				sx = v14
				x = v9 + sz.X - v14
			}
			borders.Draw(x, gpos.Y+dy, sx, sz.Y)
			return
		}
	}
}

func (b *Borders) Draw(x, y, w, h int) {
	r := Renderer
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
