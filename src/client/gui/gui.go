package gui

import (
	"github.com/noxworld-dev/opennox-lib/client/keybind"

	"github.com/noxworld-dev/opennox/v1/client/input"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
)

var (
	DrawImplFunc func(win *Window)
	Renderer     *noxrender.NoxRender

	Nox_win_cur_input            *Window
	Nox_win_1064912              *WindowRef
	nox_win_xxx1_first           *Window
	nox_win_xxx1_last            *Window
	nox_win_cur_focused          *Window
	nox_win_freeList             *Window
	Nox_win_activeWindow_1064900 *Window
	Nox_win_1064916              *Window
)

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
