package main

/*
#include "proto.h"
#include "client__gui__gadgets__listbox.h"
#include "client__gui__gamewin__psscript.h"

extern unsigned int dword_5d4594_815132;
*/
import "C"
import (
	"bufio"
	"fmt"
	"io"
	"log"
	"os"
	"strconv"
	"strings"
	"unsafe"

	"nox/client/gui"
	"nox/common/alloc"
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
	if len(s) > n && sm != nil {
		s = sm.GetStringInFile("TooltipTooLong", "C:\\NoxPost\\src\\Client\\Gui\\GameWin\\gamewin.c")
	}
	CWStringCopyTo(&d.tooltip[0], n, s)
	d.tooltip[n-1] = 0
}

func asWindow(win *C.nox_window) *Window {
	return (*Window)(unsafe.Pointer(win))
}

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

//export nox_new_window_from_file
func nox_new_window_from_file(name *C.char, fnc unsafe.Pointer) *C.nox_window {
	return newWindowFromFile(C.GoString(name), fnc).C()
}

func newWindowFromFile(name string, fnc unsafe.Pointer) *Window {
	path := strings.Join([]string{"window", name}, "\\")
	path = resolveGamePath(path)

	f, err := os.Open(path)
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
			str = p.sm.GetStringInFile(buf, "C:\\NoxPost\\src\\Client\\Gui\\GameWin\\psscript.c")
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
		s := p.sm.GetStringInFile(buf, "C:\\NoxPost\\src\\Client\\Gui\\GameWin\\psscript.c")
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
		if C.dword_5d4594_815132 != 0 {
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
	var data unsafe.Pointer
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

func (p *guiParser) parseDataField(typ string, buf string) (unsafe.Pointer, bool) {
	var (
		s string
		v uint
	)
	switch typ {
	case "VERTSLIDER", "HORZSLIDER":
		*memmap.PtrUint32(0x5D4594, 1305820) = 0
		*memmap.PtrUint32(0x5D4594, 1305824) = 0
		*memmap.PtrUint32(0x5D4594, 1305828) = 0
		*memmap.PtrUint32(0x5D4594, 1305832) = 0
		v, buf = gui.ParseNextUintField(buf)
		*memmap.PtrUint32(0x5D4594, 1305820) = uint32(v)
		v, buf = gui.ParseNextUintField(buf)
		*memmap.PtrUint32(0x5D4594, 1305824) = uint32(v)
		return memmap.PtrOff(0x5D4594, 1305820), true
	case "SCROLLLISTBOX":
		alloc.Memset(memmap.PtrOff(0x5D4594, 1306892), 0, 0x38)
		v, buf = gui.ParseNextUintField(buf)
		*memmap.PtrUint16(0x5D4594, 1306892) = uint16(v)
		v, buf = gui.ParseNextUintField(buf)
		*memmap.PtrUint16(0x5D4594, 1306892+2) = uint16(v)
		v, buf = gui.ParseNextUintField(buf)
		*memmap.PtrUint32(0x5D4594, 1306892+4) = uint32(v)
		v, buf = gui.ParseNextUintField(buf)
		*memmap.PtrUint32(0x5D4594, 1306892+8) = uint32(v)
		v, buf = gui.ParseNextUintField(buf)
		*memmap.PtrUint32(0x5D4594, 1306892+12) = uint32(v)
		v, buf = gui.ParseNextUintField(buf)
		*memmap.PtrUint32(0x5D4594, 1306892+16) = uint32(v)
		v, buf = gui.ParseNextUintField(buf)
		*memmap.PtrUint32(0x5D4594, 1306892+20) = uint32(v)
		return memmap.PtrOff(0x5D4594, 1306892), true
	case "ENTRYFIELD":
		alloc.Memset(memmap.PtrOff(0x5D4594, 1305836), 0, 0x420)
		v, buf = gui.ParseNextUintField(buf)
		*memmap.PtrUint16(0x5D4594, 1305836+1040) = uint16(v)
		s, buf = gui.ParseNextField(buf)
		if s != "" {
			v, _ := strconv.Atoi(s)
			*memmap.PtrUint16(0x5D4594, 1305836+1042) = uint16(v)
		} else {
			*memmap.PtrInt16(0x5D4594, 1305836+1042) = -1
		}
		s, buf = gui.ParseNextField(buf)
		if s != "" {
			v, _ := strconv.Atoi(s)
			*memmap.PtrUint32(0x5D4594, 1305836+1024) = uint32(bool2int(v != 0))
		} else {
			*memmap.PtrUint32(0x5D4594, 1305836+1024) = 0
		}
		s, buf = gui.ParseNextField(buf)
		if s != "" {
			v, _ := strconv.Atoi(s)
			*memmap.PtrUint32(0x5D4594, 1305836+1028) = uint32(bool2int(v == 1))
			*memmap.PtrUint32(0x5D4594, 1305836+1032) = uint32(bool2int(v == 2))
			*memmap.PtrUint32(0x5D4594, 1305836+1036) = uint32(bool2int(v == 3))
		} else {
			*memmap.PtrUint32(0x5D4594, 1305836+1028) = 0
			*memmap.PtrUint32(0x5D4594, 1305836+1032) = 0
			*memmap.PtrUint32(0x5D4594, 1305836+1036) = 0
		}
		return memmap.PtrOff(0x5D4594, 1305836), true
	case "STATICTEXT":
		v, buf = gui.ParseNextUintField(buf)
		*memmap.PtrUint32(0x5D4594, 1307256) = uint32(bool2int(v != 0))
		v, buf = gui.ParseNextUintField(buf)
		*memmap.PtrUint32(0x5D4594, 1307260) = uint32(bool2int(v != 0))
		s, buf = gui.ParseNextField(buf)
		text := p.sm.GetStringInFile(s, "C:\\NoxPost\\src\\Client\\Gui\\GameWin\\psscript.c")
		*memmap.PtrPtr(0x5D4594, 1307252) = unsafe.Pointer(internWStr(text))
		return memmap.PtrOff(0x5D4594, 1307252), true
	case "RADIOBUTTON":
		v, buf = gui.ParseNextUintField(buf)
		*memmap.PtrUint32(0x5D4594, 1305812) = uint32(v)
		// TODO: is this correct?
		*memmap.PtrUint32(0x5D4594, 1307256) = uint32(bool2int(memmap.Uint32(0x5D4594, 1307256) != 0))
		return memmap.PtrOff(0x5D4594, 1305812), true
	}
	return nil, true
}

func (p *guiParser) parseWindowOrWidget(typ string, id uint, status int, px, py, w, h int, drawData *WindowData, data unsafe.Pointer, fnc unsafe.Pointer) *Window {
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

func guiNewWidget(typ string, parent *Window, status int, px, py, w, h int, draw *WindowData, data unsafe.Pointer) *Window {
	draw.win = parent.C()
	iparent := unsafePtrToInt(unsafe.Pointer(parent.C()))
	udraw := unsafe.Pointer(draw.C())
	switch typ {
	case "PUSHBUTTON":
		draw.style |= stylePushButton
		return newButtonOrCheckbox(parent, status, px, py, w, h, draw)
	case "RADIOBUTTON":
		draw.style |= styleRadioButton
		return asWindow(C.nox_gui_newRadioButton_4A9330(iparent, C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), dataPtrToInt(draw), (*C.uint)(data)))
	case "CHECKBOX":
		draw.style |= styleCheckBox
		return newButtonOrCheckbox(parent, status, px, py, w, h, draw)
	case "VERTSLIDER":
		draw.style |= styleVertSlider
		return asWindow(C.nox_gui_newSlider_4B4EE0(iparent, C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), (*C.uint)(udraw), (*C.float)(data)))
	case "HORZSLIDER":
		draw.style |= styleHorizSlider
		return asWindow(C.nox_gui_newSlider_4B4EE0(iparent, C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), (*C.uint)(udraw), (*C.float)(data)))
	case "SCROLLLISTBOX":
		draw.style |= styleScrollListBox
		return asWindow(C.nox_gui_newScrollListBox_4A4310(iparent, C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), dataPtrToInt(draw), (*C.short)(data)))
	case "ENTRYFIELD":
		draw.style |= styleEntryField
		return asWindow(C.nox_gui_newEntryField_488500(iparent, C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), dataPtrToInt(draw), (*C.ushort)(data)))
	case "STATICTEXT":
		draw.style |= styleStaticText
		return asWindow(C.nox_gui_newStaticText_489300(iparent, C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), (*C.uint)(udraw), (*C.uint)(data)))
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
