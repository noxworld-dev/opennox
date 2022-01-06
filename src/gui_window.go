package nox

/*
#include <stdlib.h>
#include "client__gui__window.h"
extern unsigned int dword_5d4594_3799468;
extern int dword_5d4594_3799524;
extern nox_window* dword_5d4594_1064896;
extern nox_window_ref* nox_win_1064912;

int  nox_xxx_wndDrawFnDefault_46B370(int a1, int* a2);
void  sub_4AA030(nox_window* win, nox_window_data* data);

int nox_xxx_wndDefaultProc_0_46B330(int a1, int a2, int a3, int a4);
int nox_xxx_wndDefaultProc_46B2F0(int a1, int a2, int a3, int a4);

static void nox_window_call_draw_func_go(nox_window* win, nox_window_data* data) {
	win->draw_func(win, data);
}
static int nox_window_call_field_93_go(nox_window* win, int a2, int a3, int a4) {
	return win->field_93(win, a2, a3, a4);
}
static int nox_window_call_field_94_go(nox_window* win, int a2, int a3, int a4) {
	return win->field_94(win, a2, a3, a4);
}
static void nox_window_call_tooltip_func(nox_window* win, nox_window_data* data, int a3) {
	if (!win || !win->tooltip_func)
		return;
	win->tooltip_func(win, data, a3);
}
*/
import "C"
import (
	"runtime/debug"
	"unsafe"

	"nox/v1/client/gui"
	"nox/v1/common/alloc"
	noxcolor "nox/v1/common/color"
	"nox/v1/common/log"
	"nox/v1/common/types"
)

var (
	nox_alloc_window    *alloc.Class
	nox_win_cur_focused *Window
	nox_win_xxx1_first  *Window
	nox_win_xxx1_last   *Window
)

//export nox_window_new_go
func nox_window_new_go(par *C.nox_window, flags, a3, a4, w, h C.int, fnc unsafe.Pointer) *C.nox_window {
	return newWindowRaw(asWindow(par), gui.StatusFlags(flags), int(a3), int(a4), int(w), int(h), fnc).C()
}

//export nox_xxx_wndGetID_46B0A0
func nox_xxx_wndGetID_46B0A0(win *C.nox_window) C.int {
	if win == nil {
		return -2
	}
	return C.int(asWindow(win).ID())
}

//export nox_xxx_wndSetID_46B080
func nox_xxx_wndSetID_46B080(win *C.nox_window, id C.int) C.int {
	if win == nil {
		return -2
	}
	win.id = C.int(id)
	return 0
}

//export nox_window_set_all_funcs_go
func nox_window_set_all_funcs_go(p *C.nox_window, a2 unsafe.Pointer, draw unsafe.Pointer, tooltip unsafe.Pointer) C.int {
	if p == nil {
		return -2
	}
	win := asWindow(p)
	win.setFunc93(a2)
	win.setDraw(draw)
	win.setTooltipFunc(tooltip)
	return 0
}

func (win *Window) SetAllFuncs(a2 unsafe.Pointer, draw unsafe.Pointer, tooltip unsafe.Pointer) {
	if win == nil {
		return
	}
	win.setFunc93(a2)
	win.setDraw(draw)
	win.setTooltipFunc(tooltip)
}

//export nox_xxx_wndSetWindowProc_46B300_go
func nox_xxx_wndSetWindowProc_46B300_go(win *C.nox_window, fnc unsafe.Pointer) C.int {
	if win == nil {
		return -2
	}
	asWindow(win).setFunc93(fnc)
	return 0
}

//export nox_xxx_wndSetProc_46B2C0_go
func nox_xxx_wndSetProc_46B2C0_go(win *C.nox_window, fnc unsafe.Pointer) C.int {
	if win == nil {
		return -2
	}
	asWindow(win).setFunc94(fnc)
	return 0
}

//export nox_xxx_wndSetDrawFn_46B340_go
func nox_xxx_wndSetDrawFn_46B340_go(win *C.nox_window, fnc unsafe.Pointer) C.int {
	if win == nil {
		return -2
	}
	asWindow(win).setDraw(fnc)
	return 0
}

//export nox_gui_winSetFunc96_46B070
func nox_gui_winSetFunc96_46B070(win *C.nox_window, fnc unsafe.Pointer) {
	asWindow(win).setTooltipFunc(fnc)
}

//export nox_xxx_wndSetRectColor2MB_46AFE0
func nox_xxx_wndSetRectColor2MB_46AFE0(win *C.nox_window, a2 C.int) C.int {
	if win == nil {
		return -2
	}
	// TODO: not sure if the color format is correct
	asWindow(win).DrawData().SetBackgroundColor(noxcolor.RGBA5551(a2))
	return 0
}

//export nox_window_call_field_94_fnc
func nox_window_call_field_94_fnc(p *C.nox_window, a2, a3, a4 C.int, file *C.char, line C.int) C.int {
	if p == nil {
		return 0
	}
	if guiDebug {
		guiLog.Printf("nox_window_call_field_94(%p, %x, %x, %x): %s:%d", p, a2, a3, a4, GoString(file), line)
	}
	return C.int(asWindow(p).Func94(int(a2), uintptr(a3), uintptr(a4)))
}

//export nox_window_call_field_93
func nox_window_call_field_93(p *C.nox_window, a2, a3, a4 C.int) C.int {
	if p == nil {
		return 0
	}
	return C.int(asWindow(p).Func93(int(a2), uintptr(a3), uintptr(a4)))
}

//export nox_xxx_wndGetChildByID_46B0C0
func nox_xxx_wndGetChildByID_46B0C0(root *C.nox_window, id C.int) *C.nox_window {
	return asWindow(root).ChildByID(uint(id)).C()
}

//export nox_xxx_windowDestroyMB_46C4E0
func nox_xxx_windowDestroyMB_46C4E0(a1 *C.nox_window) C.int {
	win := asWindow(a1)
	if win == nil {
		return -2
	}
	win.Destroy()
	return 0
}

//export nox_window_set_hidden
func nox_window_set_hidden(p *C.nox_window, hidden C.int) C.int {
	if p == nil {
		return -2
	}
	win := asWindow(p)
	if hidden != 0 {
		win.Hide()
	} else {
		win.Show()
	}
	return 0
}

func nox_client_wndListXxxAdd_46A920(win *Window) {
	win.next = nil
	win.prev = nox_win_xxx1_last.C()
	if nox_win_xxx1_last != nil {
		nox_win_xxx1_last.next = win.C()
	} else {
		nox_win_xxx1_first = win
	}
	nox_win_xxx1_last = win
}

func nox_client_wndListXxxRemove_46A960(win *Window) {
	prev := win.Prev()
	next := win.Next()
	if prev != nil {
		prev.next = next.C()
	} else {
		nox_win_xxx1_first = next
	}
	if next != nil {
		next.prev = prev.C()
	} else {
		nox_win_xxx1_last = prev
	}
}

func newUserWindow(parent *Window, id uint, status gui.StatusFlags, px, py, w, h int, drawData *WindowData, fnc unsafe.Pointer) *Window {
	win := newWindowRaw(parent, status, px, py, w, h, fnc)
	drawData.style |= C.int(gui.StyleUserWindow)
	win.SetID(id)
	win.CopyDrawData(drawData)
	if parent != nil {
		parent.Func94(22, uintptr(id), 0)
	}
	return win
}

func newWindowRaw(parent *Window, status gui.StatusFlags, px, py, w, h int, fnc94 unsafe.Pointer) *Window {
	if nox_alloc_window == nil {
		nox_alloc_window = alloc.NewClass("Window", unsafe.Sizeof(C.nox_window{}), 576)
	}
	win := asWindow((*C.nox_window)(nox_alloc_window.NewObject()))
	if parent != nil {
		win.setParent(parent)
	} else {
		nox_client_wndListXxxAdd_46A920(win)
	}
	win.SetID(0)
	win.SetFlags(status)
	win.width = C.int(w)
	win.height = C.int(h)
	win.SetPos(types.Point{X: px, Y: py})
	win.draw_data.tooltip[0] = 0
	win.setDraw(nil)
	win.setFunc93(nil)
	win.setFunc94(fnc94)
	if fnc94 != nil {
		win.Func94(1, 0, 0)
	}
	win.field_92 = 0
	return win
}

func asWindow(win *C.nox_window) *Window {
	return asWindowP(unsafe.Pointer(win))
}

func asWindowP(win unsafe.Pointer) *Window {
	w := (*Window)(win)
	if false && cgoSafe && w.ID() == DeadWord {
		log.Println("memory corruption detected")
		debug.PrintStack()
		C.abort()
	}
	return w
}

type Window C.nox_window

func (win *Window) C() *C.nox_window {
	return (*C.nox_window)(unsafe.Pointer(win))
}

func (win *Window) ID() uint {
	if win == nil {
		return 0
	}
	return uint(win.id)
}

func (win *Window) SetID(id uint) int {
	if win == nil {
		return -2
	}
	win.id = C.int(id)
	return 0
}

func (win *Window) Flags() gui.StatusFlags {
	if win == nil {
		return 0
	}
	return gui.StatusFlags(win.flags)
}

func (win *Window) SetFlags(v gui.StatusFlags) {
	win.flags = C.nox_window_flags(v)
}

func (win *Window) Offs() types.Point { // nox_gui_getWindowOffs_46AA20
	if win == nil {
		return types.Point{}
	}
	return types.Point{
		X: int(win.off_x),
		Y: int(win.off_y),
	}
}

func (win *Window) SetOffs(p types.Point) {
	win.off_x = C.int(p.X)
	win.off_y = C.int(p.Y)
}

func (win *Window) End() types.Point {
	if win == nil {
		return types.Point{}
	}
	return types.Point{
		X: int(win.end_x),
		Y: int(win.end_y),
	}
}

func (win *Window) SetEnd(p types.Point) {
	win.end_x = C.int(p.X)
	win.end_y = C.int(p.Y)
}

func (win *Window) Size() types.Size {
	if win == nil {
		return types.Size{}
	}
	return types.Size{
		W: int(win.width),
		H: int(win.height),
	}
}

func (win *Window) pointIn(p types.Point) bool {
	off, end := win.Offs(), win.End()
	return p.X >= off.X && p.X <= end.X && p.Y >= off.Y && p.Y <= end.Y
}

func (win *Window) GlobalPos() types.Point { // nox_client_wndGetPosition_46AA60
	if win == nil {
		return types.Point{}
	}
	pos := win.Offs()
	for it := win.Parent(); it != nil; it = it.Parent() {
		pos = pos.Add(it.Offs())
	}
	return pos
}

func (win *Window) IsChild(win2 *Window) bool {
	if win == nil || win2 == nil {
		return false
	}
	for cur := win2.Parent(); cur != nil; cur = cur.Parent() {
		if win == cur {
			return true
		}
	}
	return false
}

func GUIChildByID(id uint) *Window {
	return nox_win_xxx1_last.ChildByID(id)
}

func (win *Window) ChildByID(id uint) *Window {
	for cur := win; cur != nil; cur = cur.Prev() {
		if cur.ID() == id {
			return cur
		}
		if sub := asWindow(cur.field_100); sub != nil {
			if res := sub.ChildByID(id); res != nil {
				return res
			}
		}
	}
	return nil
}

func (win *Window) ChildByPos(p types.Point) *Window {
	if win == nil {
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
		if p.X >= off.X && p.X <= off.X+sz.W && p.Y >= off.Y && p.Y <= off.Y+sz.H {
			if f := it1.Flags(); f.Has(8) && !f.Has(0x10) {
				cur = it1
				goto loop
			}
		}
	}
	return cur
}

func (win *Window) DrawData() *WindowData {
	return asWindowData(&win.draw_data)
}

func (win *Window) CopyDrawData(p *WindowData) int {
	if win == nil {
		return -2
	}
	if p == nil {
		return -3
	}
	win.draw_data = *p.C()
	return 0
}

func (win *Window) Hide() {
	if win == nil {
		return
	}
	if C.dword_5d4594_3799468 != 0 {
		if !win.Flags().IsHidden() {
			C.dword_5d4594_3799524 = 1
		}
	}
	win.flags |= C.nox_window_flags(gui.StatusHidden)
}

func (win *Window) Show() {
	if win == nil {
		return
	}
	win.flags &^= C.nox_window_flags(gui.StatusHidden)
}

func (win *Window) Func93(ev int, a1, a2 uintptr) int {
	if win == nil || win.field_93 == nil || uintptr(unsafe.Pointer(win.field_93)) == DeadWord {
		return 0
	}
	return int(C.nox_window_call_field_93_go(win.C(), C.int(ev), C.int(a1), C.int(a2)))
}

func (win *Window) setFunc93(fnc unsafe.Pointer) {
	if fnc == nil {
		fnc = C.nox_xxx_wndDefaultProc_0_46B330
	}
	win.field_93 = (*[0]byte)(fnc)
}

func (win *Window) Func94(ev int, a1, a2 uintptr) int {
	if win == nil || win.field_94 == nil || uintptr(unsafe.Pointer(win.field_94)) == DeadWord {
		return 0
	}
	return int(C.nox_window_call_field_94_go(win.C(), C.int(ev), C.int(a1), C.int(a2)))
}

func (win *Window) setFunc94(fnc unsafe.Pointer) {
	if fnc == nil {
		fnc = C.nox_xxx_wndDefaultProc_46B2F0
	}
	win.field_94 = (*[0]byte)(fnc)
}

func (win *Window) Draw() {
	if win == nil || win.draw_func == nil || uintptr(unsafe.Pointer(win.draw_func)) == DeadWord {
		return
	}
	C.nox_window_call_draw_func_go(win.C(), win.DrawData().C())
}

func (win *Window) setDraw(fnc unsafe.Pointer) {
	if fnc == nil {
		fnc = C.nox_xxx_wndDrawFnDefault_46B370
	}
	win.draw_func = (*[0]byte)(fnc)
}

func (win *Window) TooltipFunc(a1 uintptr) {
	if win == nil {
		return
	}
	C.nox_window_call_tooltip_func(win.C(), win.DrawData().C(), C.int(a1))
}

func (win *Window) setTooltipFunc(fnc unsafe.Pointer) {
	win.tooltip_func = (*[0]byte)(fnc)
}

func (win *Window) Next() *Window {
	if win == nil {
		return nil
	}
	return asWindow(win.next)
}

func (win *Window) Prev() *Window {
	if win == nil {
		return nil
	}
	return asWindow(win.prev)
}

func (win *Window) Parent() *Window {
	if win == nil {
		return nil
	}
	return asWindow(win.parent)
}

func (win *Window) Field100() *Window {
	if win == nil {
		return nil
	}
	return asWindow(win.field_100)
}

func (win *Window) drawRecursive() bool {
	if win == nil {
		return false
	}
	if win.Flags().IsHidden() {
		return true
	}
	win.Draw()
	if (win.flags & 0x1000) != 0 {
		C.sub_4AA030(win.C(), win.DrawData().C())
	}

	for sub := asWindow(win.field_100); sub != nil; sub = sub.Prev() {
		sub.drawRecursive()
	}
	return true
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

func (win *Window) setParent(par *Window) {
	if par == nil {
		return
	}
	win.next = nil
	v2 := par.field_100
	win.prev = v2
	if v2 != nil {
		v2.next = win.C()
	}
	par.field_100 = win.C()
	win.parent = par.C()
}

func guiFocus(win *Window) {
	win.Focus()
}

func (win *Window) Focus() {
	if win != nil && win.Flags().Has(0x400) {
		return
	}
	if nox_win_cur_focused != nil && nox_win_cur_focused != win {
		nox_win_cur_focused.Func94(23, 0, 0)
	}
	nox_win_cur_focused = win
	for cur := win; cur != nil; cur = cur.Parent() {
		if cur.Func94(23, 1, 0) != 0 {
			return
		}
	}
	nox_win_cur_focused = nil
}

func (win *Window) Destroy() {
	if win == nil {
		return
	}
	if win.Flags().Has(gui.StatusDestroyed) {
		return
	}
	win.flags |= C.nox_window_flags(gui.StatusDestroyed)

	if nox_win_unk3 == win {
		nox_win_unk3 = nil
	}
	if nox_win_cur_focused == win {
		guiFocus(nil)
	}
	if C.nox_win_1064912 != nil && win.C() == C.nox_win_1064912.win {
		C.nox_xxx_wnd_46C6E0(C.nox_win_1064912.win)
	}
	if nox_win_activeWindow_1064900 == win {
		nox_win_activeWindow_1064900 = nil
	}
	if nox_win_1064916 == win {
		nox_win_1064916 = nil
	}
	v3 := win.Field100()
	for v3 != nil {
		v4 := v3.Prev()
		v3.Destroy()
		v3 = v4
	}
	if win.Parent() != nil {
		sub_46B180(win)
	} else {
		nox_client_wndListXxxRemove_46A960(win)
	}
	win.next = nil
	win.prev = nox_win_freeList.C()
	nox_win_freeList = win
}

//export nox_xxx_wndShowModalMB_46A8C0
func nox_xxx_wndShowModalMB_46A8C0(p *C.nox_window) C.int {
	return C.int(nox_xxx_wndShowModalMB(asWindow(p)))
}

func nox_xxx_wndShowModalMB(win *Window) int {
	if win == nil {
		return -2
	}
	for it := nox_win_xxx1_last; it != nil; it = it.Prev() {
		if it == win {
			nox_client_wndListXxxRemove_46A960(win)
			nox_client_wndListXxxAdd_46A920(win)
			win.flags |= C.nox_window_flags(gui.StatusActive)
			win.Show()
			return 0
		}
	}
	return -3
}

func sub_46C5D0() {
	for it := nox_win_xxx1_last; it != nil; {
		prev := it.Prev()
		it.Destroy()
		it = prev
	}
	freeAllWindowsInList()
	nox_alloc_window.FreeAllObjects()
}

//export nox_window_setPos_46A9B0
func nox_window_setPos_46A9B0(p *C.nox_window, x, y C.int) C.int {
	win := asWindow(p)
	if win == nil {
		return -2
	}
	win.SetPos(types.Point{X: int(x), Y: int(y)})
	return 0
}

//export wndIsShown_nox_xxx_wndIsShown_46ACC0
func wndIsShown_nox_xxx_wndIsShown_46ACC0(p *C.nox_window) C.int {
	if p == nil {
		return 1
	}
	win := asWindow(p)
	is := win.Flags().IsHidden()
	return C.int(bool2int(is))
}

func (win *Window) SetPos(pos types.Point) {
	sz := win.Size()
	win.SetOffs(pos)
	win.SetEnd(pos.Add(sz.Point()))
	win.fixCoords()
}

func sub_46B180(win *Window) {
	next := win.Next()
	prev := win.Prev()
	if next != nil {
		next.prev = prev.C()
		if prev != nil {
			prev.next = win.Next().C()
		}
	} else if prev != nil {
		win.Parent().field_100 = prev.C()
		win.Prev().next = win.Next().C()
		win.prev = nil
	} else {
		win.Parent().field_100 = nil
	}
}

func nox_xxx_wnd_46ABB0(win *Window, v int) int {
	return int(C.nox_xxx_wnd_46ABB0(win.C(), C.int(v)))
}
