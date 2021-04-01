package main

/*
#include "proto.h"
#include "client__gui__gadgets__listbox.h"
#include "client__gui__gamewin__psscript.h"

extern nox_window* nox_win_xxx1_first;
extern unsigned int nox_client_gui_flag_815132;

void  sub_4AA030(nox_window* win, nox_window_data* data);
void nox_window_call_draw_func(nox_window* win, nox_window_data* data);
*/
import "C"
import (
	"bufio"
	"fmt"
	"io"
	"log"
	"path/filepath"
	"strconv"
	"strings"
	"unsafe"

	"nox/client/gui"
	"nox/common/alloc"
	"nox/common/fs"
	"nox/common/memmap"
	"nox/common/strman"
)

func asWindowData(data *C.nox_window_data) *WindowData {
	return (*WindowData)(unsafe.Pointer(data))
}

type WindowData C.nox_window_data

func (d *WindowData) C() *C.nox_window_data {
	return (*C.nox_window_data)(unsafe.Pointer(d))
}

func (d *WindowData) SetText(s string) {
	n := len(d.text)
	CWStringCopyTo(&d.text[0], n, s)
	d.text[n-1] = 0
}

func (d *WindowData) SetTooltip(sm *strman.StringManager, s string) {
	n := len(d.tooltip)
	if CWLen(s) > n && sm != nil {
		s = sm.GetStringInFile("TooltipTooLong", "C:\\NoxPost\\src\\Client\\Gui\\GameWin\\gamewin.c")
	}
	CWStringCopyTo(&d.tooltip[0], n, s)
	d.tooltip[n-1] = 0
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

func (win *Window) Func93(ev int, a1, a2 int) int {
	if win == nil {
		return 0
	}
	return int(C.nox_window_call_field_93(win.C(), C.int(ev), C.int(a1), C.int(a2)))
}

func (win *Window) Func94(ev int, a1, a2 int) int {
	if win == nil {
		return 0
	}
	return int(C.nox_window_call_field_94(win.C(), C.int(ev), C.int(a1), C.int(a2)))
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
	path := filepath.Join("window", name)

	f, err := fs.Open(path)
	if err != nil {
		log.Printf("cannot load gui file %q: %v", path, err)
		return nil
	}
	defer f.Close()

	return newGUIParser(strMan, f).ParseRoot(fnc)
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
		font      uintptr
		enColor   uint
		disColor  uint
		bgColor   uint
		hlColor   uint
		selColor  uint
		textColor uint
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
	val := uint(memmap.Uint32(0x5D4594, 2650656))
	p.defaults.font = 0
	p.defaults.enColor = val
	p.defaults.disColor = val
	p.defaults.bgColor = val
	p.defaults.hlColor = val
	p.defaults.selColor = val
	p.defaults.textColor = val
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
			p.defaults.enColor, ok = p.parseColorField()
		case "DISABLEDCOLOR":
			p.defaults.disColor, ok = p.parseColorField()
		case "BACKGROUNDCOLOR":
			p.defaults.bgColor, ok = p.parseColorField()
		case "HILITECOLOR":
			p.defaults.hlColor, ok = p.parseColorField()
		case "SELECTEDCOLOR":
			p.defaults.selColor, ok = p.parseColorField()
		case "TEXTCOLOR":
			p.defaults.textColor, ok = p.parseColorField()
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
	*out = C.uint(nox_color_rgb_4344A0(r, g, b))
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

func (p *guiParser) parseColorField() (uint, bool) {
	p.skipToken() // skip '='
	tok, err := p.nextToken()
	if err != nil {
		return 0, false
	}
	return guiParseColorTransp(tok)
}

func guiParseColorTransp(str string) (uint, bool) {
	if str == "TRANSPARENT" {
		return 0x80000000, true
	}
	r, g, b := gui.ParseColor(str)
	cl := nox_color_rgb_4344A0(r, g, b)
	return cl, true
}

func nox_color_rgb_4344A0(r, g, b int) uint {
	return uint(C.nox_color_rgb_4344A0(C.int(r), C.int(g), C.int(b)))
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
		cl, _ := guiParseColorTransp(buf)
		out := field(draw)
		*out = C.uint(cl)
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
	draw.en_color = C.uint(p.defaults.enColor)
	draw.hl_color = C.uint(p.defaults.hlColor)
	draw.dis_color = C.uint(p.defaults.disColor)
	draw.bg_color = C.uint(p.defaults.bgColor)
	draw.sel_color = C.uint(p.defaults.selColor)
	draw.text_color = C.uint(p.defaults.textColor)
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
		} else if field == "END" {
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
			p.defaults.enColor, ok = p.parseColorField()
		case "DISABLEDCOLOR":
			p.defaults.disColor, ok = p.parseColorField()
		case "HILITECOLOR":
			p.defaults.hlColor, ok = p.parseColorField()
		case "SELECTEDCOLOR":
			p.defaults.selColor, ok = p.parseColorField()
		case "TEXTCOLOR":
			p.defaults.textColor, ok = p.parseColorField()
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
		drawData.style |= styleUserWindow
		win.CopyDrawData(drawData)
	} else {
		win = guiNewWidget(typ, parent, status, px, py, w, h, drawData, data)
	}
	win.SetID(id)
	if parent != nil {
		parent.Func94(22, int(id), 0)
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
		draw.style |= stylePushButton
		return newButtonOrCheckbox(parent, status, px, py, w, h, draw)
	case "RADIOBUTTON":
		tdata, _ := data.(*radioButtonData)
		draw.style |= styleRadioButton
		return newRadioButton(parent, status, px, py, w, h, draw, tdata)
	case "CHECKBOX":
		draw.style |= styleCheckBox
		return newButtonOrCheckbox(parent, status, px, py, w, h, draw)
	case "VERTSLIDER":
		tdata, _ := data.(*sliderData)
		draw.style |= styleVertSlider
		return asWindow(C.nox_gui_newSlider_4B4EE0(iparent, C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), (*C.uint)(udraw), (*C.float)(unsafe.Pointer(tdata))))
	case "HORZSLIDER":
		tdata, _ := data.(*sliderData)
		draw.style |= styleHorizSlider
		return asWindow(C.nox_gui_newSlider_4B4EE0(iparent, C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), (*C.uint)(udraw), (*C.float)(unsafe.Pointer(tdata))))
	case "SCROLLLISTBOX":
		tdata, _ := data.(*scrollListBoxData)
		draw.style |= styleScrollListBox
		return asWindow(C.nox_gui_newScrollListBox_4A4310(iparent, C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), dataPtrToInt(draw), (*C.short)(unsafe.Pointer(tdata))))
	case "ENTRYFIELD":
		tdata, _ := data.(*entryFieldData)
		draw.style |= styleEntryField
		return asWindow(C.nox_gui_newEntryField_488500(iparent, C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), dataPtrToInt(draw), (*C.ushort)(unsafe.Pointer(tdata))))
	case "STATICTEXT":
		tdata, _ := data.(*staticTextData)
		draw.style |= styleStaticText
		return asWindow(C.nox_gui_newStaticText_489300(iparent, C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), (*C.uint)(udraw), (*C.uint)(unsafe.Pointer(tdata))))
	case "PROGRESSBAR":
		draw.style |= styleProgressBar
		return asWindow(C.nox_gui_newProgressBar_4CAF10(iparent, C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), (*C.uint)(udraw)))
	}
	return nil
}

func newWindow(parent *Window, status int, px, py, w, h int, fnc94 unsafe.Pointer) *Window {
	return asWindow(C.nox_window_new(parent.C(), C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), (*[0]byte)(fnc94)))
}

const (
	stylePushButton    = 0x1
	styleRadioButton   = 0x2
	styleCheckBox      = 0x4
	styleVertSlider    = 0x8
	styleHorizSlider   = 0x10
	styleScrollListBox = 0x20
	styleEntryField    = 0x80
	styleStaticText    = 0x800
	styleProgressBar   = 0x1000
	styleUserWindow    = 0x2000
)

func newButtonOrCheckbox(parent *Window, status int, px, py, w, h int, draw *WindowData) *Window {
	if draw.style&stylePushButton != 0 {
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
	}
	if draw.style&styleCheckBox != 0 {
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
	if draw.style&styleRadioButton == 0 {
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
