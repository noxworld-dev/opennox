package main

/*
#include "client__gui__window.h"
extern unsigned int nox_client_gui_flag_815132;
*/
import "C"
import (
	"bufio"
	"fmt"
	"io"
	"path/filepath"
	"strconv"
	"strings"
	"unsafe"

	"nox/v1/client/gui"
	"nox/v1/common/alloc"
	noxcolor "nox/v1/common/color"
	"nox/v1/common/fs"
	"nox/v1/common/memmap"
	"nox/v1/common/strman"
)

//export nox_new_window_from_file
func nox_new_window_from_file(cname *C.char, fnc unsafe.Pointer) *C.nox_window {
	if isDedicatedServer {
		panic("server should not load GUI")
	}
	name := C.GoString(cname)
	win := newWindowFromFile(name, fnc)
	if win != nil {
		guiParseHook(name, win)
	}
	return win.C()
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
	val := noxcolor.IntToColor(memmap.Uint32(0x85B3FC, 952))
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

const (
	winStatusActive = 1 << iota
	winStatusToggle
	winStatusDraggable
	winStatusEnabled
	winStatusHidden
	winStatusAbove
	winStatusBelow
	winStatusImage
	winStatusTabStop
	winStatusNoInput
	winStatusNoFocus
	winStatusDestroyed
	winStatusBorder
	winStatusSmoothText
	winStatusOneLine
	winStatusNoFlush
)

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
		str := p.sm.GetStringInFile(strman.ID(buf), "C:\\NoxPost\\src\\Client\\Gui\\GameWin\\psscript.c")
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
			*out = nox_xxx_gLoadImg_42F970(s)
		}
		return true
	}
}
