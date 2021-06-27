package main

/*
#include "proto.h"
#include "client__gui__gadgets__listbox.h"
#include "client__gui__gamewin__psscript.h"

extern nox_window* nox_win_xxx1_first;
extern unsigned int nox_client_gui_flag_815132;
extern nox_window* dword_5d4594_1064896;
extern nox_alloc_class* nox_alloc_window;
extern nox_window_ref* nox_win_1064912;

void  sub_4AA030(nox_window* win, nox_window_data* data);
void nox_window_call_draw_func(nox_window* win, nox_window_data* data);
int nox_gui_console_Enter_450FD0();
void nox_gui_console_F1_451350();
void  nox_window_set_ptrs_97(nox_window* win, nox_window* a2); // TODO: move to Go
void  nox_client_wndListXxxAdd_46A920(nox_window* win); // TODO: move to Go
void  nox_client_wndListXxxRemove_46A960(nox_window* win); // TODO: move to Go
void  sub_46AC60(nox_window* a1);
static void nox_window_call_tooltip_func(nox_window* win, nox_window_data* data, int a3) {
	if (!win || !win->tooltip_func)
		return;
	win->tooltip_func(win, data, a3);
}
*/
import "C"
import (
	"bufio"
	"fmt"
	"image"
	"io"
	"path/filepath"
	"strconv"
	"strings"
	"unsafe"

	"nox/v1/client/gui"
	"nox/v1/client/input/keybind"
	"nox/v1/client/system/parsecmd"
	"nox/v1/common/alloc"
	noxcolor "nox/v1/common/color"
	"nox/v1/common/fs"
	"nox/v1/common/log"
	"nox/v1/common/memmap"
	"nox/v1/common/strman"
	"nox/v1/common/types"
)

var (
	guiLog              = log.New("gui")
	nox_win_unk3        *Window
	nox_win_cur_focused *Window
	nox_win_1064900     *Window
	nox_win_1064916     *Window
)

//export nox_xxx_wndGetFocus_46B4F0
func nox_xxx_wndGetFocus_46B4F0() *C.nox_window {
	return nox_win_cur_focused.C()
}

//export nox_xxx_windowFocus_46B500
func nox_xxx_windowFocus_46B500(win *C.nox_window) C.int {
	guiFocus(asWindow(win))
	return 0
}

//export nox_client_getWin1064916_46C720
func nox_client_getWin1064916_46C720() *C.nox_window {
	return nox_win_1064916.C()
}

//export nox_xxx_wndSetCaptureMain_46ADC0
func nox_xxx_wndSetCaptureMain_46ADC0(win *C.nox_window) C.int {
	if nox_win_unk3 != nil {
		return -4
	}
	nox_win_unk3 = asWindow(win)
	return 0
}

//export nox_xxx_wndClearCaptureMain_46ADE0
func nox_xxx_wndClearCaptureMain_46ADE0(win *C.nox_window) C.int {
	if win == nox_win_unk3.C() {
		nox_win_unk3 = nil
	}
	return 0
}

//export nox_xxx_wndGetCaptureMain_46AE00
func nox_xxx_wndGetCaptureMain_46AE00() *C.nox_window {
	return nox_win_unk3.C()
}

func asWindowData(data *C.nox_window_data) *WindowData {
	return (*WindowData)(unsafe.Pointer(data))
}

type WindowData C.nox_window_data

func (d *WindowData) C() *C.nox_window_data {
	return (*C.nox_window_data)(unsafe.Pointer(d))
}

func (d *WindowData) Group() int {
	return int(d.group)
}

func (d *WindowData) StyleFlags() gui.StyleFlags {
	return gui.StyleFlags(d.style)
}

func (d *WindowData) Status() int {
	return int(d.status)
}

func (d *WindowData) Window() *Window {
	return asWindow(d.win)
}

func (d *WindowData) Text() string {
	return GoWString(&d.text[0])
}

func (d *WindowData) SetText(s string) {
	n := len(d.text)
	CWStringCopyTo(&d.text[0], n, s)
	d.text[n-1] = 0
}

func (d *WindowData) BackgroundImage() unsafe.Pointer {
	return d.bg_image
}

func (d *WindowData) BackgroundColor() noxcolor.Color16 {
	return noxcolor.IntToColor(uint32(d.bg_color))
}

func (d *WindowData) SetBackgroundColor(cl noxcolor.Color16) {
	d.bg_color = C.uint32_t(noxcolor.ExtendColor16(cl))
}

func (d *WindowData) EnabledImage() unsafe.Pointer {
	return d.en_image
}

func (d *WindowData) EnabledColor() noxcolor.Color16 {
	return noxcolor.IntToColor(uint32(d.en_color))
}

func (d *WindowData) SetEnabledColor(cl noxcolor.Color16) {
	d.en_color = C.uint32_t(noxcolor.ExtendColor16(cl))
}

func (d *WindowData) DisabledImage() unsafe.Pointer {
	return d.dis_image
}

func (d *WindowData) DisabledColor() noxcolor.Color16 {
	return noxcolor.IntToColor(uint32(d.dis_color))
}

func (d *WindowData) SetDisabledColor(cl noxcolor.Color16) {
	d.dis_color = C.uint32_t(noxcolor.ExtendColor16(cl))
}

func (d *WindowData) HighlightImage() unsafe.Pointer {
	return d.hl_image
}

func (d *WindowData) HighlightColor() noxcolor.Color16 {
	return noxcolor.IntToColor(uint32(d.hl_color))
}

func (d *WindowData) SetHighlightColor(cl noxcolor.Color16) {
	d.hl_color = C.uint32_t(noxcolor.ExtendColor16(cl))
}

func (d *WindowData) SelectedImage() unsafe.Pointer {
	return d.sel_image
}

func (d *WindowData) SelectedColor() noxcolor.Color16 {
	return noxcolor.IntToColor(uint32(d.sel_color))
}

func (d *WindowData) SetSelectedColor(cl noxcolor.Color16) {
	d.sel_color = C.uint32_t(noxcolor.ExtendColor16(cl))
}

func (d *WindowData) TextColor() noxcolor.Color16 {
	return noxcolor.IntToColor(uint32(d.text_color))
}

func (d *WindowData) SetTextColor(cl noxcolor.Color16) {
	d.text_color = C.uint32_t(noxcolor.ExtendColor16(cl))
}

func (d *WindowData) ImagePoint() image.Point {
	return image.Point{
		X: int(d.img_px),
		Y: int(d.img_py),
	}
}

func (d *WindowData) Tooltip() string {
	return GoWString(&d.tooltip[0])
}

func (d *WindowData) SetTooltip(sm *strman.StringManager, s string) {
	n := len(d.tooltip)
	if CWLen(s) > n && sm != nil {
		s = sm.GetStringInFile("TooltipTooLong", "C:\\NoxPost\\src\\Client\\Gui\\GameWin\\gamewin.c")
	}
	CWStringCopyTo(&d.tooltip[0], n, s)
	d.tooltip[n-1] = 0
}

func (d *WindowData) SetDefaults(def gui.StyleDefaults) {
	d.SetEnabledColor(def.EnabledColor)
	d.SetHighlightColor(def.HighlightColor)
	d.SetDisabledColor(def.DisabledColor)
	d.SetBackgroundColor(def.BackgroundColor)
	d.SetSelectedColor(def.SelectedColor)
	d.SetTextColor(def.TextColor)
}

func asWindow(win *C.nox_window) *Window {
	return (*Window)(unsafe.Pointer(win))
}

type WindowFlag int

func (f WindowFlag) Has(f2 WindowFlag) bool {
	return f&f2 != 0
}
func (f WindowFlag) HasNone(f2 WindowFlag) bool {
	return f&f2 == 0
}

const (
	NOX_WIN_HIDDEN      = WindowFlag(0x10)
	NOX_WIN_LAYER_FRONT = WindowFlag(0x20)
	NOX_WIN_LAYER_BACK  = WindowFlag(0x40)
)

type Window C.nox_window

func (win *Window) C() *C.nox_window {
	return (*C.nox_window)(unsafe.Pointer(win))
}

func (win *Window) ID() uint {
	return uint(win.id)
}

func (win *Window) SetID(id uint) int {
	if win == nil {
		return -2
	}
	win.id = C.int(id)
	return 0
}

func (win *Window) Flags() WindowFlag {
	if win == nil {
		return 0
	}
	return WindowFlag(win.flags)
}

func (win *Window) Offs() types.Point {
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
	C.nox_window_set_hidden(win.C(), 1)
}

func (win *Window) Show() {
	C.nox_window_set_hidden(win.C(), 0)
}

func (win *Window) Func93(ev int, a1, a2 uintptr) int {
	if win == nil {
		return 0
	}
	return int(C.nox_window_call_field_93(win.C(), C.int(ev), C.int(a1), C.int(a2)))
}

func (win *Window) Func94(ev int, a1, a2 uintptr) int {
	if win == nil {
		return 0
	}
	return int(C.nox_window_call_field_94(win.C(), C.int(ev), C.int(a1), C.int(a2)))
}

func (win *Window) TooltipFunc(a1 uintptr) {
	if win == nil {
		return
	}
	C.nox_window_call_tooltip_func(win.C(), win.DrawData().C(), C.int(a1))
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
	if win.Flags().Has(NOX_WIN_HIDDEN) {
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

func (win *Window) Draw() {
	if win.draw_func != nil {
		C.nox_window_call_draw_func(win.C(), win.DrawData().C())
	}
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

func DrawGUI() {
	// back layer (background and some UI parts)
	for win := asWindow(C.nox_win_xxx1_first); win != nil; win = win.Next() {
		if win.Flags().Has(NOX_WIN_LAYER_BACK) {
			win.drawRecursive()
		}
	}
	// middle layer
	for win := asWindow(C.nox_win_xxx1_first); win != nil; win = win.Next() {
		if win.Flags().HasNone(NOX_WIN_LAYER_BACK | NOX_WIN_LAYER_FRONT) {
			win.drawRecursive()
		}
	}
	// front layer
	for win := asWindow(C.nox_win_xxx1_first); win != nil; win = win.Next() {
		if win.Flags().Has(NOX_WIN_LAYER_FRONT) {
			win.drawRecursive()
		}
	}
}

//export nox_gui_draw
func nox_gui_draw() {
	DrawGUI()
}

//export nox_new_window_from_file
func nox_new_window_from_file(name *C.char, fnc unsafe.Pointer) *C.nox_window {
	return newWindowFromFile(C.GoString(name), fnc).C()
}

func newWindowFromFile(name string, fnc unsafe.Pointer) *Window {
	guiLog.Printf("load: %q", name)
	path := filepath.Join("window", name)

	f, err := fs.Open(path)
	if err != nil {
		guiLog.Printf("cannot load file %q: %v", path, err)
		return nil
	}
	defer f.Close()

	return newWindowFromReader(f, fnc)
}

func newWindowFromString(src string, fnc unsafe.Pointer) *Window {
	return newWindowFromReader(strings.NewReader(src), fnc)
}

func newWindowFromReader(r io.Reader, fnc unsafe.Pointer) *Window {
	return newGUIParser(strMan, r).ParseRoot(fnc)
}

func newGUIParser(sm *strman.StringManager, r io.Reader) *guiParser {
	br := bufio.NewReader(r)
	p := &guiParser{
		sm: sm,
		br: br,
	}
	p.resetDefaults()
	return p
}

type guiParser struct {
	sm       *strman.StringManager
	br       *bufio.Reader
	parents  []*Window
	defaults struct {
		font uintptr
		gui.StyleDefaults
	}
	widgets struct {
		radioButton *radioButtonData
		slider      *sliderData
		scrollBox   *scrollListBoxData
		entryField  *entryFieldData
		staticText  *staticTextData
	}
}

func (p *guiParser) parentsTop() *Window {
	n := len(p.parents)
	if n == 0 {
		return nil
	}
	return p.parents[n-1]
}

func (p *guiParser) parentsPop() *Window {
	n := len(p.parents)
	if n == 0 {
		return nil
	}
	cur := p.parents[n-1]
	p.parents = p.parents[:n-1]
	return cur
}

func (p *guiParser) parentsPush(win *Window) {
	p.parents = append(p.parents, win)
}

func (p *guiParser) resetDefaults() {
	val := noxcolor.IntToColor(memmap.Uint32(0x5D4594, 2650656))
	p.defaults.font = 0
	p.defaults.SetColors(val)
}

func (p *guiParser) ParseRoot(fnc unsafe.Pointer) *Window {
	for {
		tok := p.nextWord()
		if tok == "" {
			break
		}
		ok := true
		switch tok {
		case "ENABLEDCOLOR":
			p.defaults.EnabledColor, ok = p.parseColorField()
		case "DISABLEDCOLOR":
			p.defaults.DisabledColor, ok = p.parseColorField()
		case "BACKGROUNDCOLOR":
			p.defaults.BackgroundColor, ok = p.parseColorField()
		case "HILITECOLOR":
			p.defaults.HighlightColor, ok = p.parseColorField()
		case "SELECTEDCOLOR":
			p.defaults.SelectedColor, ok = p.parseColorField()
		case "TEXTCOLOR":
			p.defaults.TextColor, ok = p.parseColorField()
		case "FONT":
			p.defaults.font, ok = p.parseFontField()
		case "WINDOW":
			return p.parseWindowRoot(fnc)
		}
		if !ok {
			break
		}
	}
	return nil
}

func (p *guiParser) parseFontField() (uintptr, bool) {
	p.skipToken() // skip '='
	tok, _ := p.nextToken()
	fnt := nox_xxx_guiFontPtrByName_43F360(tok)
	return fnt, fnt != 0
}

func nox_xxx_guiFontPtrByName_43F360(name string) uintptr {
	cstr := C.CString(name)
	defer StrFree(cstr)
	return uintptr(C.nox_xxx_guiFontPtrByName_43F360(cstr))
}

//export nox_gui_parseColor_4A0570
func nox_gui_parseColor_4A0570(out *C.uint, buf *C.char) C.int {
	r, g, b := gui.ParseColor(C.GoString(buf))
	cl := noxcolor.RGBColor(byte(r), byte(g), byte(b))
	*out = C.uint(noxcolor.ExtendColor16(cl))
	return 1
}

func (p *guiParser) skipToken() {
	var s string
	fmt.Fscan(p.br, &s)
}

func (p *guiParser) nextWord() string {
	var v string
	fmt.Fscan(p.br, &v)
	return v
}

func (p *guiParser) nextToken() (string, error) {
	return gui.ReadNextToken(p.br)
}

func (p *guiParser) parseColorField() (noxcolor.Color16, bool) {
	p.skipToken() // skip '='
	tok, err := p.nextToken()
	if err != nil {
		return noxcolor.RGBA5551(0), false
	}
	return gui.ParseColorTransp(tok)
}

//export nox_color_rgb_4344A0
func nox_color_rgb_4344A0(r, g, b C.int) C.uint32_t {
	cl := noxcolor.RGBColor(byte(r), byte(g), byte(b))
	return C.uint32_t(noxcolor.ExtendColor16(cl))
}

//export nox_color_rgb_func
func nox_color_rgb_func(r, g, b C.uint8_t, p *C.uint32_t) {
	cl := noxcolor.RGBColor(byte(r), byte(g), byte(b))
	*p = C.uint32_t(noxcolor.ExtendColor16(cl))
}

//export nox_color_rgb_func_get
func nox_color_rgb_func_get() C.int {
	return C.int(noxcolor.GetMode())
}

//export nox_color_rgb_func_set
func nox_color_rgb_func_set(mode C.int) {
	noxcolor.SetMode(noxcolor.Mode(mode))
}

var guiWinStatuses = []string{
	"ACTIVE", "TOGGLE", "DRAGABLE", "ENABLED", "HIDDEN", "ABOVE", "BELOW", "IMAGE",
	"TABSTOP", "NOINPUT", "NOFOCUS", "DESTROYED", "BORDER", "SMOOTH_TEXT", "ONE_LINE", "NO_FLUSH",
}

var guiWinStyles = []string{
	"PUSHBUTTON", "RADIOBUTTON", "CHECKBOX", "VERTSLIDER", "HORZSLIDER", "SCROLLLISTBOX", "FADELISTBOX",
	"ENTRYFIELD", "MOUSETRACK", "ANIMATED", "TABSTOP", "STATICTEXT", "PROGRESSBAR",
}

type guiWindowParseFunc func(*guiParser, *WindowData, string) bool

var parseWindowFuncs = []struct {
	name string
	fnc  guiWindowParseFunc
}{
	{"STATUS", func(_ *guiParser, draw *WindowData, buf string) bool {
		draw.status = C.int(guiFlagsFromNames(buf, guiWinStatuses))
		return true
	}},
	{"STYLE", func(_ *guiParser, draw *WindowData, buf string) bool {
		draw.style = C.int(guiFlagsFromNames(buf, guiWinStyles))
		return true
	}},
	{"GROUP", func(_ *guiParser, draw *WindowData, buf string) bool {
		v, _ := gui.ParseNextIntField(buf)
		draw.group = C.int(v)
		return true
	}},
	{"BACKGROUNDCOLOR", makeColorParseFunc(func(data *WindowData) *C.uint {
		return &data.bg_color
	})},
	{"BACKGROUNDIMAGE", makeImageParseFunc(func(data *WindowData) *unsafe.Pointer {
		return &data.bg_image
	})},
	{"ENABLEDCOLOR", makeColorParseFunc(func(data *WindowData) *C.uint {
		return &data.en_color
	})},
	{"ENABLEDIMAGE", makeImageParseFunc(func(data *WindowData) *unsafe.Pointer {
		return &data.en_image
	})},
	{"DISABLEDCOLOR", makeColorParseFunc(func(data *WindowData) *C.uint {
		return &data.dis_color
	})},
	{"DISABLEDIMAGE", makeImageParseFunc(func(data *WindowData) *unsafe.Pointer {
		return &data.dis_image
	})},
	{"HILITECOLOR", makeColorParseFunc(func(data *WindowData) *C.uint {
		return &data.hl_color
	})},
	{"HILITEIMAGE", makeImageParseFunc(func(data *WindowData) *unsafe.Pointer {
		return &data.hl_image
	})},
	{"SELECTEDCOLOR", makeColorParseFunc(func(data *WindowData) *C.uint {
		return &data.sel_color
	})},
	{"SELECTEDIMAGE", makeImageParseFunc(func(data *WindowData) *unsafe.Pointer {
		return &data.sel_image
	})},
	{"IMAGEOFFSET", func(_ *guiParser, draw *WindowData, buf string) bool {
		var px, py int
		px, buf = gui.ParseNextIntField(buf)
		py, buf = gui.ParseNextIntField(buf)
		draw.img_px = C.int(px)
		draw.img_py = C.int(py)
		return true
	}},
	{"TEXTCOLOR", makeColorParseFunc(func(data *WindowData) *C.uint {
		return &data.text_color
	})},
	{"TEXT", func(p *guiParser, draw *WindowData, buf string) bool {
		var str string
		// TODO: this is a hack to replace 8-16bit switch with Window-FullScreen switch
		//       we can probably do better than this and insert additional controls based
		//       on the window identifier later
		switch buf {
		case "Options.wnd:8BitColor":
			str = "\tWindowed"
		case "Options.wnd:16BitColor":
			str = "\tFullscreen"
		default:
			str = p.sm.GetStringInFile(strman.ID(buf), "C:\\NoxPost\\src\\Client\\Gui\\GameWin\\psscript.c")
		}
		draw.SetText(str)
		return true
	}},
	{"FONT", func(_ *guiParser, draw *WindowData, buf string) bool {
		fnt := nox_xxx_guiFontPtrByName_43F360(buf)
		if fnt == 0 {
			return false
		}
		draw.font = C.uint(fnt)
		return true
	}},
	{"TOOLTIP", func(p *guiParser, draw *WindowData, buf string) bool {
		s := p.sm.GetStringInFile(strman.ID(buf), "C:\\NoxPost\\src\\Client\\Gui\\GameWin\\psscript.c")
		draw.SetTooltip(p.sm, s)
		return true
	}},
}

func unsafePtrToInt(p unsafe.Pointer) C.int {
	return C.int(uintptr(p))
}

func dataPtrToInt(p *WindowData) C.int {
	return C.int(uintptr(unsafe.Pointer(p)))
}

func guiFlagsFromNames(str string, values []string) int {
	str = strings.TrimSpace(str)
	if str == "NULL" {
		return 0
	}
	out := 0
	for _, v := range strings.Split(str, "+") {
		v = strings.TrimSpace(v)
		for j, v2 := range values {
			if v == v2 {
				out |= 1 << j
				break
			}
		}
	}
	return out
}

func makeColorParseFunc(field func(*WindowData) *C.uint) guiWindowParseFunc {
	return func(_ *guiParser, draw *WindowData, buf string) bool {
		cl, _ := gui.ParseColorTransp(buf)
		out := field(draw)
		*out = C.uint(noxcolor.ExtendColor16(cl))
		return true
	}
}

func makeImageParseFunc(field func(*WindowData) *unsafe.Pointer) guiWindowParseFunc {
	return func(_ *guiParser, draw *WindowData, buf string) bool {
		s, _ := gui.ParseNextField(buf)
		out := field(draw)
		if s == "NULL" {
			*out = nil
		} else {
			cstr := C.CString(s)
			defer StrFree(cstr)
			*out = unsafe.Pointer(C.nox_xxx_gLoadImg_42F970(cstr))
		}
		return true
	}
}

//export nox_xxx_wndWddSetTooltip_46B000
func nox_xxx_wndWddSetTooltip_46B000(draw *C.nox_window_data, str *C.wchar_t) {
	d := asWindowData(draw)
	if str == nil {
		d.SetTooltip(strMan, "")
		return
	}
	d.SetTooltip(strMan, GoWString(str))
}

func (p *guiParser) parseWindowRoot(fnc unsafe.Pointer) *Window {
	drawDataP := alloc.Calloc(1, unsafe.Sizeof(WindowData{}))
	defer alloc.Free(drawDataP)
	draw := (*WindowData)(drawDataP)

	draw.field_0 = 0
	draw.SetDefaults(p.defaults.StyleDefaults)
	font := p.defaults.font
	if font == 0 {
		if C.nox_client_gui_flag_815132 != 0 {
			font = nox_xxx_guiFontPtrByName_43F360("large")
		} else {
			font = nox_xxx_guiFontPtrByName_43F360("default")
		}
	}
	draw.font = C.uint(font)

	tok, _ := p.nextToken()

	var id uint
	id, tok = gui.ParseNextUintField(tok)

	var px, py int
	px, tok = gui.ParseNextIntField(tok)
	py, tok = gui.ParseNextIntField(tok)

	var w, h int
	w, tok = gui.ParseNextIntField(tok)
	h, tok = gui.ParseNextIntField(tok)

	var typ string
	typ, tok = gui.ParseNextField(tok)

	var win *Window
	var data guiWidgetData
	for {
		field := p.nextWord()
		// hooks for different custom fields
		found := false
		for _, pfnc := range parseWindowFuncs {
			if field == pfnc.name {
				p.skipToken() // skip '='
				sdata, _ := p.nextToken()
				if !pfnc.fnc(p, draw, sdata) {
					return nil
				}
				found = true
				break
			}
		}
		if found {
			continue
		}
		// check the builtin fields
		if field == "DATA" {
			p.skipToken() // skip '='
			sdata, _ := p.nextToken()
			d, ok := p.parseDataField(typ, sdata)
			if !ok {
				return nil
			}
			data = d
		} else if field == "END" || field == "" {
			if win != nil {
				return win
			}
			return p.parseWindowOrWidget(typ, id, int(draw.status), px, py, w, h, draw, data, fnc)
		} else if field == "CHILD" {
			win = p.parseWindowOrWidget(typ, id, int(draw.status), px, py, w, h, draw, data, fnc)
			if win == nil {
				return nil
			}
			if !p.parseWinFields(win) {
				return nil
			}
		} else {
			// skip?
			if _, err := p.nextToken(); err != nil {
				return nil
			}
		}
	}
}

func (p *guiParser) parseWinFields(win *Window) bool {
	p.parentsPush(win)
	for {
		tok := p.nextWord()
		if tok == "" || tok == "END" {
			break
		}
		ok := true
		switch tok {
		case "ENABLEDCOLOR":
			p.defaults.EnabledColor, ok = p.parseColorField()
		case "DISABLEDCOLOR":
			p.defaults.DisabledColor, ok = p.parseColorField()
		case "HILITECOLOR":
			p.defaults.HighlightColor, ok = p.parseColorField()
		case "SELECTEDCOLOR":
			p.defaults.SelectedColor, ok = p.parseColorField()
		case "TEXTCOLOR":
			p.defaults.TextColor, ok = p.parseColorField()
		case "WINDOW":
			if p.parseWindowRoot(nil) == nil {
				return false
			}
		}
		if !ok {
			return false
		}
	}
	return p.parentsPop() == win
}

func (p *guiParser) parseDataField(typ string, buf string) (guiWidgetData, bool) {
	var (
		s string
		v uint
	)
	switch typ {
	case "VERTSLIDER", "HORZSLIDER":
		if p.widgets.slider == nil {
			p.widgets.slider = (*sliderData)(alloc.Calloc(1, unsafe.Sizeof(sliderData{})))
		}
		d := p.widgets.slider
		*d = sliderData{}
		v, buf = gui.ParseNextUintField(buf)
		d.field_0 = C.uint(v)
		v, buf = gui.ParseNextUintField(buf)
		d.field_1 = C.uint(v)
		d.field_2 = 0
		d.field_3 = 0
		return d, true
	case "SCROLLLISTBOX":
		if p.widgets.scrollBox == nil {
			p.widgets.scrollBox = (*scrollListBoxData)(alloc.Calloc(1, unsafe.Sizeof(scrollListBoxData{})))
		}
		d := p.widgets.scrollBox
		*d = scrollListBoxData{}
		v, buf = gui.ParseNextUintField(buf)
		d.field_0_0 = C.ushort(v)
		v, buf = gui.ParseNextUintField(buf)
		d.field_0_1 = C.ushort(v)
		v, buf = gui.ParseNextUintField(buf)
		d.field_1 = C.uint(v)
		v, buf = gui.ParseNextUintField(buf)
		d.field_2 = C.uint(v)
		v, buf = gui.ParseNextUintField(buf)
		d.field_3 = C.uint(v)
		v, buf = gui.ParseNextUintField(buf)
		d.field_4 = C.uint(v)
		v, buf = gui.ParseNextUintField(buf)
		d.field_5 = C.uint(v)
		return d, true
	case "ENTRYFIELD":
		if p.widgets.entryField == nil {
			p.widgets.entryField = (*entryFieldData)(alloc.Calloc(1, unsafe.Sizeof(entryFieldData{})))
		}
		d := p.widgets.entryField
		*d = entryFieldData{}
		v, buf = gui.ParseNextUintField(buf)
		d.field_1040 = C.ushort(v)
		s, buf = gui.ParseNextField(buf)
		if s != "" {
			v, _ := strconv.Atoi(s)
			d.field_1042 = C.short(v)
		} else {
			d.field_1042 = -1
		}
		s, buf = gui.ParseNextField(buf)
		if s != "" {
			v, _ := strconv.Atoi(s)
			d.field_1024 = C.uint(bool2int(v != 0))
		} else {
			d.field_1024 = 0
		}
		s, buf = gui.ParseNextField(buf)
		if s != "" {
			v, _ := strconv.Atoi(s)
			d.field_1028 = C.uint(bool2int(v == 1))
			d.field_1032 = C.uint(bool2int(v == 2))
			d.field_1036 = C.uint(bool2int(v == 3))
		} else {
			d.field_1028 = 0
			d.field_1032 = 0
			d.field_1036 = 0
		}
		return d, true
	case "STATICTEXT":
		if p.widgets.staticText == nil {
			p.widgets.staticText = (*staticTextData)(alloc.Calloc(1, unsafe.Sizeof(staticTextData{})))
		}
		d := p.widgets.staticText
		*d = staticTextData{}
		v, buf = gui.ParseNextUintField(buf)
		d.field_1 = C.uint(bool2int(v != 0))
		v, buf = gui.ParseNextUintField(buf)
		d.field_2 = C.uint(bool2int(v != 0))
		s, buf = gui.ParseNextField(buf)
		text := p.sm.GetStringInFile(strman.ID(s), "C:\\NoxPost\\src\\Client\\Gui\\GameWin\\psscript.c")
		d.text = internWStr(text)
		return d, true
	case "RADIOBUTTON":
		if p.widgets.radioButton == nil {
			p.widgets.radioButton = (*radioButtonData)(alloc.Calloc(1, unsafe.Sizeof(radioButtonData{})))
		}
		d := p.widgets.radioButton
		*d = radioButtonData{}
		v, buf = gui.ParseNextUintField(buf)
		d.field_0 = C.uint(v)
		// TODO: is this correct?
		if p.widgets.staticText == nil {
			p.widgets.staticText = (*staticTextData)(alloc.Calloc(1, unsafe.Sizeof(staticTextData{})))
		}
		d2 := p.widgets.staticText
		d2.field_1 = C.uint(bool2int(p.widgets.staticText.field_1 != 0))
		return d, true
	}
	return nil, true
}

func (p *guiParser) parseWindowOrWidget(typ string, id uint, status int, px, py, w, h int, drawData *WindowData, data guiWidgetData, fnc unsafe.Pointer) *Window {
	parent := p.parentsTop()
	var win *Window
	if typ == "USER" {
		win = newWindow(parent, status, px, py, w, h, fnc)
		drawData.style |= C.int(gui.StyleUserWindow)
		win.CopyDrawData(drawData)
	} else {
		win = guiNewWidget(typ, parent, status, px, py, w, h, drawData, data)
	}
	win.SetID(id)
	if parent != nil {
		parent.Func94(22, uintptr(id), 0)
	}
	return win
}

type guiWidgetData interface {
	cWidgetData() unsafe.Pointer
}

type rawWidgetData struct {
	Ptr unsafe.Pointer
}

func (d rawWidgetData) cWidgetData() unsafe.Pointer {
	return unsafe.Pointer(d.Ptr)
}

type radioButtonData C.nox_radioButton_data

func (d *radioButtonData) cWidgetData() unsafe.Pointer {
	return unsafe.Pointer(d)
}

type sliderData C.nox_slider_data

func (d *sliderData) cWidgetData() unsafe.Pointer {
	return unsafe.Pointer(d)
}

type scrollListBoxData C.nox_scrollListBox_data

func (d *scrollListBoxData) cWidgetData() unsafe.Pointer {
	return unsafe.Pointer(d)
}

type entryFieldData C.nox_entryField_data

func (d *entryFieldData) cWidgetData() unsafe.Pointer {
	return unsafe.Pointer(d)
}

type staticTextData C.nox_staticText_data

func (d *staticTextData) cWidgetData() unsafe.Pointer {
	return unsafe.Pointer(d)
}

func guiNewWidget(typ string, parent *Window, status int, px, py, w, h int, draw *WindowData, data guiWidgetData) *Window {
	draw.win = parent.C()
	iparent := unsafePtrToInt(unsafe.Pointer(parent.C()))
	udraw := unsafe.Pointer(draw.C())
	switch typ {
	case "PUSHBUTTON":
		draw.style |= C.int(gui.StylePushButton)
		return newButtonOrCheckbox(parent, status, px, py, w, h, draw)
	case "RADIOBUTTON":
		tdata, _ := data.(*radioButtonData)
		draw.style |= C.int(gui.StyleRadioButton)
		return newRadioButton(parent, status, px, py, w, h, draw, tdata)
	case "CHECKBOX":
		draw.style |= C.int(gui.StyleCheckBox)
		return newButtonOrCheckbox(parent, status, px, py, w, h, draw)
	case "VERTSLIDER":
		tdata, _ := data.(*sliderData)
		draw.style |= C.int(gui.StyleVertSlider)
		return asWindow(C.nox_gui_newSlider_4B4EE0(iparent, C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), (*C.uint)(udraw), (*C.float)(unsafe.Pointer(tdata))))
	case "HORZSLIDER":
		tdata, _ := data.(*sliderData)
		draw.style |= C.int(gui.StyleHorizSlider)
		return asWindow(C.nox_gui_newSlider_4B4EE0(iparent, C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), (*C.uint)(udraw), (*C.float)(unsafe.Pointer(tdata))))
	case "SCROLLLISTBOX":
		tdata, _ := data.(*scrollListBoxData)
		draw.style |= C.int(gui.StyleScrollListBox)
		return asWindow(C.nox_gui_newScrollListBox_4A4310(iparent, C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), dataPtrToInt(draw), (*C.short)(unsafe.Pointer(tdata))))
	case "ENTRYFIELD":
		tdata, _ := data.(*entryFieldData)
		draw.style |= C.int(gui.StyleEntryField)
		return asWindow(C.nox_gui_newEntryField_488500(iparent, C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), dataPtrToInt(draw), (*C.ushort)(unsafe.Pointer(tdata))))
	case "STATICTEXT":
		tdata, _ := data.(*staticTextData)
		draw.style |= C.int(gui.StyleStaticText)
		return asWindow(C.nox_gui_newStaticText_489300(iparent, C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), (*C.uint)(udraw), (*C.uint)(unsafe.Pointer(tdata))))
	case "PROGRESSBAR":
		draw.style |= C.int(gui.StyleProgressBar)
		return asWindow(C.nox_gui_newProgressBar_4CAF10(iparent, C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), (*C.uint)(udraw)))
	}
	return nil
}

func newWindow(parent *Window, status int, px, py, w, h int, fnc94 unsafe.Pointer) *Window {
	return asWindow(C.nox_window_new(parent.C(), C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), (*[0]byte)(fnc94)))
}

func newButtonOrCheckbox(parent *Window, status int, px, py, w, h int, draw *WindowData) *Window {
	st := draw.StyleFlags()
	if st.IsPushButton() {
		btn := newWindow(parent, status, px, py, w, h, C.nox_xxx_wndButtonProcPre_4A9250)
		if btn == nil {
			return nil
		}
		C.nox_xxx_wndButtonInit_4A8340(unsafePtrToInt(unsafe.Pointer(btn.C())))
		if draw.win == nil {
			draw.win = btn.C()
		}
		btn.CopyDrawData(draw)
		return btn
	} else if st.IsCheckBox() {
		btn := newWindow(parent, status, px, py, w, h, C.nox_xxx_wndCheckboxProcMB_4A92C0)
		if btn == nil {
			return nil
		}
		C.nox_xxx_wndCheckBoxInit_4A8E60(unsafePtrToInt(unsafe.Pointer(btn.C())))
		if draw.win == nil {
			draw.win = btn.C()
		}
		btn.CopyDrawData(draw)
		return btn
	}
	return nil
}

func newRadioButton(parent *Window, status int, px, py, w, h int, draw *WindowData, data *radioButtonData) *Window {
	if !draw.StyleFlags().IsRadioButton() {
		return nil
	}
	win := newWindow(parent, status, px, py, w, h, C.nox_xxx_wndRadioButtonProcPre_4A93C0)
	if win == nil {
		return nil
	}
	C.nox_xxx_wndRadioButtonSetAllFn_4A87E0(unsafePtrToInt(unsafe.Pointer(win.C())))
	if draw.win == nil {
		draw.win = win.C()
	}
	d := (*C.nox_radioButton_data)(alloc.Calloc(1, unsafe.Sizeof(C.nox_radioButton_data{})))
	if data != nil {
		d.field_0 = data.field_0
	}
	win.field_8 = C.uint(unsafePtrToInt(unsafe.Pointer(d)))
	win.CopyDrawData(draw)
	return win
}

func nox_xxx_windowUpdateKeysMB_46B6B0(a1 *noxKeyEventInt) {
	root := nox_win_cur_focused
	if root == nil {
		return
	}
	if a1.code == 0 {
		return
	}
	if a1.field_2 == 1 {
		return
	}
	v3 := byte(1)
	ok := false
	for win := root; win != nil; win = win.Parent() {
		if win.Func93(21, uintptr(a1.code), uintptr(a1.state)) != 0 {
			ok = true
			break
		}
	}
	if !ok {
		v3 = 0
	}
	v6 := a1.code
	a1.field_2 = v3
	sub_4309B0_go(v6, v3)
}

//export nox_xxx_consoleEditProc_450F40
func nox_xxx_consoleEditProc_450F40(a1 unsafe.Pointer, a2, a3, a4 C.int) C.int {
	if a2 != 21 {
		return C.nox_xxx_wndEditProc_487D70((*C.uint)(a1), a2, a3, a4)
	}
	for it := nox_ctrlevent_key_head; it != nil; it = it.field_19 {
		if it.binds[0] == 11 && keybind.Key(a3) == it.keys[0] {
			if a4 == 2 {
				C.nox_gui_console_F1_451350()
			}
			return 1
		}
	}
	if a3 == 1 {
		if a4 == 2 {
			C.nox_xxx_consoleEsc_49B7A0()
		}
	} else {
		if a3 != 28 {
			return C.nox_xxx_wndEditProc_487D70((*C.uint)(a1), a2, a3, a4)
		}
		if a4 == 2 {
			C.nox_gui_console_Enter_450FD0()
			return 1
		}
	}
	return 1
}

//var dword_5d4594_2618912 *noxKeyEventInt

//export sub_437060
func sub_437060() C.int {
	if C.sub_46A4A0() != 0 {
		return 1
	}
	for j := range nox_input_arr_787228 {
		p := &nox_input_arr_787228[j]
		if p.code == 0 {
			break
		}
		//dword_5d4594_2618912 = p
		if p.field_2 != 1 && p.state != 2 {
			switch p.code {
			case 0x3B, 0x3C, 0x3D, 0x3E, 0x3F,
				0x40, 0x41, 0x42, 0x43, 0x44, 0x57, 0x58:
				v2 := !nox_xxx_guiCursor_477600()
				if v2 {
					sub_4443B0(p.code)
				}
			}
		}
	}
	return 1
}

func sub_4443B0(a1 byte) {
	if a1 < 0x3B || a1 > 0x58 {
		return
	}
	if *memmap.PtrUint32(0x587000, 95416) == 0 {
		return
	}
	if str := GoWString(C.sub_444410(C.int(a1))); str != "" {
		consolePrintf(parsecmd.ColorWhite, "> %s\n", str)
		nox_server_parseCmdText_443C80(str, 0)
		sub_4309B0(C.uchar(a1), 1)
	}
}
func sub_4281F0(a1 types.Point, a2 types.Rect) bool {
	return a1.X >= a2.Left && a1.X <= a2.Right && a1.Y >= a2.Top && a1.Y <= a2.Bottom
}

//export sub_46C200
func sub_46C200() {
	v0 := asWindow(C.dword_5d4594_1064896)
	C.dword_5d4594_1064896 = nil
	for v0 != nil {
		prev := v0.Prev()
		if nox_win_unk3 == v0 {
			nox_win_unk3 = nil
		}
		if nox_win_cur_focused == v0 {
			guiFocus(nil)
		}
		if C.nox_win_1064912 != nil && v0.C() == C.nox_win_1064912.win {
			C.nox_xxx_wnd_46C6E0(C.nox_win_1064912.win)
		}
		if nox_win_1064900 == v0 {
			nox_win_1064900 = nil
		}
		if nox_win_1064916 == v0 {
			nox_win_1064916 = nil
		}
		v0.Func94(2, 0, 0)
		nox_alloc_class_free_obj(C.nox_alloc_window, unsafe.Pointer(v0.C()))
		v0 = prev
	}
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

func (win *Window) Destroy() {
	if win == nil {
		return
	}
	if win.Flags().Has(0x800) {
		return
	}
	win.flags |= 0x800
	C.sub_46AC60(win.C())
	if nox_win_unk3 == win {
		nox_win_unk3 = nil
	}
	if nox_win_cur_focused == win {
		guiFocus(nil)
	}
	if C.nox_win_1064912 != nil && win.C() == C.nox_win_1064912.win {
		C.nox_xxx_wnd_46C6E0(C.nox_win_1064912.win)
	}
	if nox_win_1064900 == win {
		nox_win_1064900 = nil
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
		C.nox_client_wndListXxxRemove_46A960(win.C())
	}
	win.next = nil
	win.prev = C.dword_5d4594_1064896
	C.dword_5d4594_1064896 = win.C() // TODO: this doesn't look right; or is it a list of free items?
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

//export sub_46B120
func sub_46B120(a1, a2 *C.nox_window) C.int {
	win := asWindow(a1)
	if win == nil {
		return -2
	}
	if win.Parent() != nil {
		sub_46B180(win)
	} else {
		C.nox_client_wndListXxxRemove_46A960(win.C())
	}
	if a2 != nil {
		C.nox_window_set_ptrs_97(win.C(), a2)
	} else {
		C.nox_client_wndListXxxAdd_46A920(win.C())
		win.parent = nil
	}
	return 0
}
