package opennox

/*
#include "client__gui__window.h"
*/
import "C"
import (
	"bufio"
	"fmt"
	"image"
	"image/color"
	"io"
	"path/filepath"
	"strconv"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/ifs"
	"github.com/noxworld-dev/opennox-lib/noxfont"
	"github.com/noxworld-dev/opennox-lib/strman"

	"github.com/noxworld-dev/opennox/v1/client/gui"
	"github.com/noxworld-dev/opennox/v1/client/noxrender"
	"github.com/noxworld-dev/opennox/v1/common/alloc"
)

//export nox_new_window_from_file
func nox_new_window_from_file(cname *C.char, fnc unsafe.Pointer) *C.nox_window {
	if isDedicatedServer {
		panic("server should not load GUI")
	}
	name := GoString(cname)
	win := newWindowFromFile(noxClient.GUI, name, gui.WrapFuncC(fnc))
	if win != nil {
		guiParseHook(name, win)
	}
	return (*C.nox_window)(win.C())
}

func newWindowFromFile(g *gui.GUI, name string, fnc gui.WindowFunc) *gui.Window {
	guiLog.Printf("load: %q", name)
	path := filepath.Join("window", name)

	f, err := ifs.Open(path)
	if err != nil {
		guiLog.Printf("cannot load file %q: %v", path, err)
		return nil
	}
	defer f.Close()

	return newWindowFromReader(g, f, fnc)
}

func newWindowFromString(g *gui.GUI, src string, fnc gui.WindowFunc) *gui.Window {
	return newWindowFromReader(g, strings.NewReader(src), fnc)
}

func newWindowFromReader(g *gui.GUI, r io.Reader, fnc gui.WindowFunc) *gui.Window {
	return newGUIParser(g, strMan, r).ParseRoot(fnc)
}

func newGUIParser(g *gui.GUI, sm *strman.StringManager, r io.Reader) *guiParser {
	br := bufio.NewReader(r)
	p := &guiParser{
		g:  g,
		sm: sm,
		br: br,
	}
	p.resetDefaults()
	return p
}

type guiParser struct {
	g        *gui.GUI
	sm       *strman.StringManager
	br       *bufio.Reader
	parents  []*gui.Window
	defaults struct {
		font unsafe.Pointer
		gui.StyleDefaults
	}
	widgets struct {
		radioButton *radioButtonData
		slider      *sliderData
		scrollBox   *scrollListBoxData
		entryField  *entryFieldData
		staticText  *gui.StaticTextData
	}
}

func (p *guiParser) parentsTop() *gui.Window {
	n := len(p.parents)
	if n == 0 {
		return nil
	}
	return p.parents[n-1]
}

func (p *guiParser) parentsPop() *gui.Window {
	n := len(p.parents)
	if n == 0 {
		return nil
	}
	cur := p.parents[n-1]
	p.parents = p.parents[:n-1]
	return cur
}

func (p *guiParser) parentsPush(win *gui.Window) {
	p.parents = append(p.parents, win)
}

func (p *guiParser) resetDefaults() {
	p.defaults.font = nil
	p.defaults.SetColors(color.Black)
}

func (p *guiParser) ParseRoot(fnc gui.WindowFunc) *gui.Window {
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

func (p *guiParser) parseFontField() (unsafe.Pointer, bool) {
	p.skipToken() // skip '='
	tok, _ := p.nextToken()
	fnt := noxClient.r.Fonts.FontPtrByName(tok)
	return fnt, fnt != nil
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

func (p *guiParser) parseColorField() (color.Color, bool) {
	p.skipToken() // skip '='
	tok, err := p.nextToken()
	if err != nil {
		return color.Black, false
	}
	return gui.ParseColorTransp(tok)
}

func (p *guiParser) parseWindowRoot(fnc gui.WindowFunc) *gui.Window {
	draw, drawFree := gui.NewWindowData()
	defer drawFree()

	draw.Field0 = 0
	draw.SetDefaults(p.defaults.StyleDefaults)
	font := p.defaults.font
	if font == nil {
		if nox_client_gui_flag_815132 != 0 {
			font = noxClient.r.Fonts.FontPtrByName(noxfont.LargeName)
		} else {
			font = noxClient.r.Fonts.FontPtrByName(noxfont.DefaultName)
		}
	}
	draw.SetFont(font)

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

	var win *gui.Window
	var data gui.WidgetData
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
			return p.parseWindowOrWidget(typ, id, draw.Status, px, py, w, h, draw, data, fnc)
		} else if field == "CHILD" {
			win = p.parseWindowOrWidget(typ, id, draw.Status, px, py, w, h, draw, data, fnc)
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

func (p *guiParser) parseWinFields(win *gui.Window) bool {
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
		case "BACKGROUNDCOLOR":
			p.defaults.BackgroundColor, ok = p.parseColorField()
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

func (p *guiParser) parseDataField(typ string, buf string) (gui.WidgetData, bool) {
	var (
		s string
		v uint
	)
	switch typ {
	case "VERTSLIDER", "HORZSLIDER":
		if p.widgets.slider == nil {
			p.widgets.slider, _ = alloc.New(sliderData{})
		}
		d := p.widgets.slider
		*d = sliderData{}
		v, buf = gui.ParseNextUintField(buf)
		d.min = uint32(v)
		v, buf = gui.ParseNextUintField(buf)
		d.max = uint32(v)
		d.field2 = 0
		d.field3 = 0
		return d, true
	case "SCROLLLISTBOX":
		if p.widgets.scrollBox == nil {
			p.widgets.scrollBox, _ = alloc.New(scrollListBoxData{})
		}
		d := p.widgets.scrollBox
		*d = scrollListBoxData{}
		v, buf = gui.ParseNextUintField(buf)
		d.count = C.ushort(v)
		v, buf = gui.ParseNextUintField(buf)
		d.line_height = C.ushort(v)
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
			p.widgets.entryField, _ = alloc.New(entryFieldData{})
		}
		d := p.widgets.entryField
		*d = entryFieldData{}
		v, buf = gui.ParseNextUintField(buf)
		d.field_1040 = uint16(v)
		s, buf = gui.ParseNextField(buf)
		if s != "" {
			v, _ := strconv.Atoi(s)
			d.field_1042 = int16(v)
		} else {
			d.field_1042 = -1
		}
		s, buf = gui.ParseNextField(buf)
		if s != "" {
			v, _ := strconv.Atoi(s)
			d.field_1024 = uint32(bool2int(v != 0))
		} else {
			d.field_1024 = 0
		}
		s, buf = gui.ParseNextField(buf)
		if s != "" {
			v, _ := strconv.Atoi(s)
			d.field_1028 = uint32(bool2int(v == 1))
			d.field_1032 = uint32(bool2int(v == 2))
			d.field_1036 = uint32(bool2int(v == 3))
		} else {
			d.field_1028 = 0
			d.field_1032 = 0
			d.field_1036 = 0
		}
		return d, true
	case "STATICTEXT":
		if p.widgets.staticText == nil {
			p.widgets.staticText, _ = alloc.New(gui.StaticTextData{})
		}
		d := p.widgets.staticText
		*d = gui.StaticTextData{}
		v, buf = gui.ParseNextUintField(buf)
		d.Center = uint32(bool2int(v != 0))
		v, buf = gui.ParseNextUintField(buf)
		d.Glow = uint32(bool2int(v != 0))
		s, buf = gui.ParseNextField(buf)
		text := p.sm.GetStringInFile(strman.ID(s), "C:\\NoxPost\\src\\Client\\Gui\\GameWin\\psscript.c")
		d.Text = alloc.InternCString16(text)
		return d, true
	case "RADIOBUTTON":
		if p.widgets.radioButton == nil {
			p.widgets.radioButton, _ = alloc.New(radioButtonData{})
		}
		d := p.widgets.radioButton
		*d = radioButtonData{}
		v, buf = gui.ParseNextUintField(buf)
		d.field0 = uint32(v)
		// TODO: is this correct?
		if p.widgets.staticText == nil {
			p.widgets.staticText, _ = alloc.New(gui.StaticTextData{})
		}
		d2 := p.widgets.staticText
		d2.Center = uint32(bool2int(p.widgets.staticText.Center != 0))
		return d, true
	}
	return nil, true
}

func (p *guiParser) parseWindowOrWidget(typ string, id uint, status gui.StatusFlags, px, py, w, h int, drawData *gui.WindowData, data gui.WidgetData, fnc gui.WindowFunc) *gui.Window {
	parent := p.parentsTop()
	if typ == "USER" {
		return p.g.NewUserWindow(parent, id, status, px, py, w, h, drawData, fnc)
	}
	win := guiNewWidget(p.g, typ, parent, status, px, py, w, h, drawData, data)
	win.SetID(id)
	if parent != nil {
		parent.Func94(gui.WindowNewChild{ID: id})
	}
	return win
}

var guiWinStatuses = []string{
	"ACTIVE", "TOGGLE", "DRAGABLE", "ENABLED", "HIDDEN", "ABOVE", "BELOW", "IMAGE",
	"TABSTOP", "NOINPUT", "NOFOCUS", "DESTROYED", "BORDER", "SMOOTH_TEXT", "ONE_LINE", "NO_FLUSH",
}

var guiWinStyles = []string{
	"PUSHBUTTON", "RADIOBUTTON", "CHECKBOX", "VERTSLIDER", "HORZSLIDER", "SCROLLLISTBOX", "FADELISTBOX",
	"ENTRYFIELD", "MOUSETRACK", "ANIMATED", "TABSTOP", "STATICTEXT", "PROGRESSBAR",
}

type guiWindowParseFunc func(*guiParser, *gui.WindowData, string) bool

var parseWindowFuncs = []struct {
	name string
	fnc  guiWindowParseFunc
}{
	{"STATUS", func(_ *guiParser, draw *gui.WindowData, buf string) bool {
		draw.Status = gui.StatusFlags(guiFlagsFromNames(buf, guiWinStatuses))
		return true
	}},
	{"STYLE", func(_ *guiParser, draw *gui.WindowData, buf string) bool {
		draw.Style = gui.StyleFlags(guiFlagsFromNames(buf, guiWinStyles))
		return true
	}},
	{"GROUP", func(_ *guiParser, draw *gui.WindowData, buf string) bool {
		v, _ := gui.ParseNextIntField(buf)
		draw.SetGroup(v)
		return true
	}},
	{"BACKGROUNDCOLOR", makeColorParseFunc((*gui.WindowData).SetBackgroundColor)},
	{"BACKGROUNDIMAGE", makeImageParseFunc((*gui.WindowData).SetBackgroundImage)},
	{"ENABLEDCOLOR", makeColorParseFunc((*gui.WindowData).SetEnabledColor)},
	{"ENABLEDIMAGE", makeImageParseFunc((*gui.WindowData).SetEnabledImage)},
	{"DISABLEDCOLOR", makeColorParseFunc((*gui.WindowData).SetDisabledColor)},
	{"DISABLEDIMAGE", makeImageParseFunc((*gui.WindowData).SetDisabledImage)},
	{"HILITECOLOR", makeColorParseFunc((*gui.WindowData).SetHighlightColor)},
	{"HILITEIMAGE", makeImageParseFunc((*gui.WindowData).SetHighlightImage)},
	{"SELECTEDCOLOR", makeColorParseFunc((*gui.WindowData).SetSelectedColor)},
	{"SELECTEDIMAGE", makeImageParseFunc((*gui.WindowData).SetSelectedImage)},
	{"IMAGEOFFSET", func(_ *guiParser, draw *gui.WindowData, buf string) bool {
		var px, py int
		px, buf = gui.ParseNextIntField(buf)
		py, buf = gui.ParseNextIntField(buf)
		draw.SetImagePoint(image.Point{X: px, Y: py})
		return true
	}},
	{"TEXTCOLOR", makeColorParseFunc((*gui.WindowData).SetTextColor)},
	{"TEXT", func(p *guiParser, draw *gui.WindowData, buf string) bool {
		str := p.sm.GetStringInFile(strman.ID(buf), "psscript.c")
		draw.SetText(str)
		return true
	}},
	{"FONT", func(_ *guiParser, draw *gui.WindowData, buf string) bool {
		fnt := noxClient.r.Fonts.FontPtrByName(buf)
		if fnt == nil {
			return false
		}
		draw.SetFont(fnt)
		return true
	}},
	{"TOOLTIP", func(p *guiParser, draw *gui.WindowData, buf string) bool {
		s := p.sm.GetStringInFile(strman.ID(buf), "psscript.c")
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

func makeColorParseFunc(field func(*gui.WindowData, color.Color)) guiWindowParseFunc {
	return func(_ *guiParser, draw *gui.WindowData, buf string) bool {
		cl, _ := gui.ParseColorTransp(buf)
		field(draw, cl)
		return true
	}
}

func makeImageParseFunc(field func(*gui.WindowData, *noxrender.Image)) guiWindowParseFunc {
	return func(_ *guiParser, draw *gui.WindowData, buf string) bool {
		s, _ := gui.ParseNextField(buf)
		var val *noxrender.Image
		if s != "NULL" {
			val = nox_xxx_gLoadImg(s)
		}
		field(draw, val)
		return true
	}
}
