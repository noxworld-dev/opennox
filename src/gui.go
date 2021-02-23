package main

/*
#include "proto.h"
#include "client__gui__gadgets__listbox.h"
#include "client__gui__gamewin__psscript.h"

extern unsigned int dword_5d4594_815132;
*/
import "C"
import (
	"strconv"
	"strings"
	"unsafe"

	"nox/client/gui"
	"nox/common/alloc"
	"nox/common/memmap"
)

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

func (win *Window) CopyDrawData(p *C.nox_window_data) int {
	if win == nil {
		return -2
	}
	if p == nil {
		return -3
	}
	win.draw_data = *p
	return 0
}

var noxWinParents []*Window

func guiWinParentsReset() {
	noxWinParents = nil
}

func guiWinParentsTop() *Window {
	n := len(noxWinParents)
	if n == 0 {
		return nil
	}
	return noxWinParents[n-1]
}

func guiWinParentsPop() *Window {
	n := len(noxWinParents)
	if n == 0 {
		return nil
	}
	cur := noxWinParents[n-1]
	noxWinParents = noxWinParents[:n-1]
	return cur
}

func guiWinParentsPush(win *Window) {
	noxWinParents = append(noxWinParents, win)
}

//export nox_new_window_from_file
func nox_new_window_from_file(name *C.char, fnc unsafe.Pointer) *C.nox_window {
	return newWindowFromFile(C.GoString(name), fnc).C()
}

func newWindowFromFile(name string, fnc unsafe.Pointer) *Window {
	guiWinParentsReset()
	guiResetWidgetData()
	path := strings.Join([]string{"window", name}, "\\")

	f := fopen(path, "r")
	if f == nil {
		return nil
	}
	defer C.fclose(f)

	var tok string
loop:
	for fscanf(f, "%s", &tok) != -1 {
		switch tok {
		case "ENABLEDCOLOR":
			cl, ok := guiParseColorTo(f)
			if !ok {
				break loop
			}
			*memmap.PtrUint32(0x5D4594, 1307264) = uint32(cl)
		case "DISABLEDCOLOR":
			cl, ok := guiParseColorTo(f)
			if !ok {
				break loop
			}
			*memmap.PtrUint32(0x5D4594, 1307268) = uint32(cl)
		case "BACKGROUNDCOLOR":
			cl, ok := guiParseColorTo(f)
			if !ok {
				break loop
			}
			*memmap.PtrUint32(0x5D4594, 1307272) = uint32(cl)
		case "HILITECOLOR":
			cl, ok := guiParseColorTo(f)
			if !ok {
				break loop
			}
			*memmap.PtrUint32(0x5D4594, 1307276) = uint32(cl)
		case "SELECTEDCOLOR":
			cl, ok := guiParseColorTo(f)
			if !ok {
				break loop
			}
			*memmap.PtrUint32(0x5D4594, 1307280) = uint32(cl)
		case "TEXTCOLOR":
			cl, ok := guiParseColorTo(f)
			if !ok {
				break loop
			}
			*memmap.PtrUint32(0x5D4594, 1307284) = uint32(cl)
		case "FONT":
			fnt, ok := guiParseFont(f)
			if !ok {
				break loop
			}
			*memmap.PtrUint32(0x5D4594, 1307288) = uint32(fnt)
		case "WINDOW":
			return guiParseWindowRoot(f, fnc)
		}
	}
	return nil
}

func guiParseFont(f *C.FILE) (uintptr, bool) {
	fi := newCFile(f)
	fscanf(f, "%*s") // skip '='
	tok, _ := gui.ReadNextToken(fi)
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

func guiParseColorTo(f *C.FILE) (uint, bool) {
	fi := newCFile(f)
	fscanf(f, "%*s") // skip '='
	tok, err := gui.ReadNextToken(fi)
	if err != nil {
		return 0, false
	}
	if tok == "TRANSPARENT" {
		return 0x80000000, true
	}
	r, g, b := gui.ParseColor(tok)
	cl := nox_color_rgb_4344A0(r, g, b)
	return cl, true
}

func nox_color_rgb_4344A0(r, g, b int) uint {
	return uint(C.nox_color_rgb_4344A0(C.int(r), C.int(g), C.int(b)))
}

var parseWindowFuncs = []struct {
	name string
	fnc  func(*C.nox_window_data, *C.char) C.int
}{
	{"STATUS", nox_gui_parseWindowStatus_4A0A00},
	{"STYLE", nox_gui_parseWindowStyle_4A0A30},
	{"GROUP", nox_gui_parseWindowGroup_4A0A60},
	{"BACKGROUNDCOLOR", nox_gui_parseWindowBgColor_4A0650},
	{"BACKGROUNDIMAGE", nox_gui_parseWindowBgImage_4A0870},
	{"ENABLEDCOLOR", nox_gui_parseWindowEnColor_4A0690},
	{"ENABLEDIMAGE", nox_gui_parseWindowEnImage_4A08C0},
	{"DISABLEDCOLOR", nox_gui_parseWindowDisColor_4A06D0},
	{"DISABLEDIMAGE", nox_gui_parseWindowDisImage_4A0910},
	{"HILITECOLOR", nox_gui_parseWindowHlColor_4A0710},
	{"HILITEIMAGE", nox_gui_parseWindowHlImage_4A09B0},
	{"SELECTEDCOLOR", nox_gui_parseWindowSelColor_4A0750},
	{"SELECTEDIMAGE", nox_gui_parseWindowSelImage_4A0960},
	{"IMAGEOFFSET", nox_gui_parseWindowImgOffs_4A0830},
	{"TEXTCOLOR", nox_gui_parseWindowTextColor_4A0790},
	{"TEXT", nox_gui_parseWindowText_4A0A90},
	{"FONT", nox_gui_parseWindowFont_4A07D0},
	{"TOOLTIP", nox_gui_parseWindowTooltip_4A0800},
}

func unsafePtrToInt(p unsafe.Pointer) C.int {
	return C.int(uintptr(p))
}

func dataPtrToInt(p *C.nox_window_data) C.int {
	return C.int(uintptr(unsafe.Pointer(p)))
}

func nox_gui_parseWindowStatus_4A0A00(draw *C.nox_window_data, buf *C.char) C.int {
	return C.nox_gui_parseWindowStatus_4A0A00(draw, buf)
}
func nox_gui_parseWindowStyle_4A0A30(draw *C.nox_window_data, buf *C.char) C.int {
	return C.nox_gui_parseWindowStyle_4A0A30(draw, buf)
}
func nox_gui_parseWindowGroup_4A0A60(draw *C.nox_window_data, buf *C.char) C.int {
	return C.nox_gui_parseWindowGroup_4A0A60(draw, buf)
}
func nox_gui_parseWindowBgColor_4A0650(draw *C.nox_window_data, buf *C.char) C.int {
	return C.nox_gui_parseWindowBgColor_4A0650(draw, buf)
}
func nox_gui_parseWindowBgImage_4A0870(draw *C.nox_window_data, buf *C.char) C.int {
	return C.nox_gui_parseWindowBgImage_4A0870(draw, buf)
}
func nox_gui_parseWindowEnColor_4A0690(draw *C.nox_window_data, buf *C.char) C.int {
	return C.nox_gui_parseWindowEnColor_4A0690(draw, buf)
}
func nox_gui_parseWindowEnImage_4A08C0(draw *C.nox_window_data, buf *C.char) C.int {
	return C.nox_gui_parseWindowEnImage_4A08C0(draw, buf)
}
func nox_gui_parseWindowDisColor_4A06D0(draw *C.nox_window_data, buf *C.char) C.int {
	return C.nox_gui_parseWindowDisColor_4A06D0(draw, buf)
}
func nox_gui_parseWindowDisImage_4A0910(draw *C.nox_window_data, buf *C.char) C.int {
	return C.nox_gui_parseWindowDisImage_4A0910(draw, buf)
}
func nox_gui_parseWindowHlColor_4A0710(draw *C.nox_window_data, buf *C.char) C.int {
	return C.nox_gui_parseWindowHlColor_4A0710(draw, buf)
}
func nox_gui_parseWindowHlImage_4A09B0(draw *C.nox_window_data, buf *C.char) C.int {
	return C.nox_gui_parseWindowHlImage_4A09B0(draw, buf)
}
func nox_gui_parseWindowSelColor_4A0750(draw *C.nox_window_data, buf *C.char) C.int {
	return C.nox_gui_parseWindowSelColor_4A0750(draw, buf)
}
func nox_gui_parseWindowSelImage_4A0960(draw *C.nox_window_data, buf *C.char) C.int {
	return C.nox_gui_parseWindowSelImage_4A0960(draw, buf)
}
func nox_gui_parseWindowImgOffs_4A0830(draw *C.nox_window_data, buf *C.char) C.int {
	return C.nox_gui_parseWindowImgOffs_4A0830(draw, buf)
}
func nox_gui_parseWindowTextColor_4A0790(draw *C.nox_window_data, buf *C.char) C.int {
	return C.nox_gui_parseWindowTextColor_4A0790(draw, buf)
}
func nox_gui_parseWindowText_4A0A90(draw *C.nox_window_data, buf *C.char) C.int {
	return C.nox_gui_parseWindowText_4A0A90(draw, buf)
}
func nox_gui_parseWindowFont_4A07D0(draw *C.nox_window_data, buf *C.char) C.int {
	return C.nox_gui_parseWindowFont_4A07D0(draw, buf)
}
func nox_gui_parseWindowTooltip_4A0800(draw *C.nox_window_data, buf *C.char) C.int {
	return C.nox_gui_parseWindowTooltip_4A0800(draw, buf)
}

func guiParseWindowRoot(f *C.FILE, fnc unsafe.Pointer) *Window {
	drawDataP := alloc.Calloc(1, unsafe.Sizeof(C.nox_window_data{}))
	defer alloc.Free(drawDataP)
	draw := (*C.nox_window_data)(drawDataP)

	draw.field_0 = 0
	draw.en_color = C.uint(memmap.Uint32(0x5D4594, 1307264))
	draw.hl_color = C.uint(memmap.Uint32(0x5D4594, 1307276))
	font := uintptr(memmap.Uint32(0x5D4594, 1307288))
	draw.dis_color = C.uint(memmap.Uint32(0x5D4594, 1307268))
	draw.bg_color = C.uint(memmap.Uint32(0x5D4594, 1307272))
	draw.sel_color = C.uint(memmap.Uint32(0x5D4594, 1307280))
	draw.text_color = C.uint(memmap.Uint32(0x5D4594, 1307284))
	if font == 0 {
		if C.dword_5d4594_815132 != 0 {
			font = nox_xxx_guiFontPtrByName_43F360("large")
		} else {
			font = nox_xxx_guiFontPtrByName_43F360("default")
		}
	}
	draw.font = C.uint(font)

	fi := newCFile(f)
	tok, _ := gui.ReadNextToken(fi)

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
		var field string
		fscanf(f, "%s", &field)
		// hooks for different custom fields
		found := false
		for _, pfnc := range parseWindowFuncs {
			if field == pfnc.name {
				fscanf(f, "%*s") // skip '='
				sdata, _ := gui.ReadNextToken(fi)
				cdata := C.CString(sdata)
				ok := pfnc.fnc(draw, cdata) != 0
				StrFree(cdata)
				if !ok {
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
			fscanf(f, "%*s")
			sdata, _ := gui.ReadNextToken(fi)
			d, ok := guiParseDataField(typ, sdata)
			if !ok {
				return nil
			}
			data = d
		} else if field == "END" {
			if win != nil {
				return win
			}
			return guiParseWindowOrWidget(typ, id, int(draw.status), px, py, w, h, draw, data, fnc)
		} else if field == "CHILD" {
			win = guiParseWindowOrWidget(typ, id, int(draw.status), px, py, w, h, draw, data, fnc)
			if win == nil {
				return nil
			}
			if !guiParseWinFields(win, f) {
				return nil
			}
		} else {
			// skip?
			if _, err := gui.ReadNextToken(fi); err != nil {
				return nil
			}
		}
	}
}

func guiParseWinFields(win *Window, f *C.FILE) bool {
	guiWinParentsPush(win)
	var tok string
loop:
	for fscanf(f, "%s", &tok) != -1 {
		switch tok {
		case "END":
			break loop
		case "ENABLEDCOLOR":
			cl, ok := guiParseColorTo(f)
			if !ok {
				return false
			}
			*memmap.PtrUint32(0x5D4594, 1307264) = uint32(cl)
		case "DISABLEDCOLOR":
			cl, ok := guiParseColorTo(f)
			if !ok {
				return false
			}
			*memmap.PtrUint32(0x5D4594, 1307268) = uint32(cl)
		case "HILITECOLOR":
			cl, ok := guiParseColorTo(f)
			if !ok {
				return false
			}
			*memmap.PtrUint32(0x5D4594, 1307276) = uint32(cl)
		case "SELECTEDCOLOR":
			cl, ok := guiParseColorTo(f)
			if !ok {
				return false
			}
			*memmap.PtrUint32(0x5D4594, 1307280) = uint32(cl)
		case "TEXTCOLOR":
			cl, ok := guiParseColorTo(f)
			if !ok {
				return false
			}
			*memmap.PtrUint32(0x5D4594, 1307284) = uint32(cl)
		case "WINDOW":
			if guiParseWindowRoot(f, nil) == nil {
				return false
			}
		}
	}
	return guiWinParentsPop() == win
}

func guiParseDataField(typ string, buf string) (unsafe.Pointer, bool) {
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
		text := strMan.GetStringInFile(s, "C:\\NoxPost\\src\\Client\\Gui\\GameWin\\psscript.c")
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

func guiParseWindowOrWidget(typ string, id uint, status int, px, py, w, h int, drawData *C.nox_window_data, data unsafe.Pointer, fnc unsafe.Pointer) *Window {
	parent := guiWinParentsTop()
	var win *Window
	if typ == "USER" {
		win = asWindow(C.nox_window_new(parent.C(), C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), (*[0]byte)(fnc)))
		drawData.style |= 0x2000
		win.CopyDrawData(drawData)
	} else {
		win = guiParseWidget(typ, parent, status, px, py, w, h, drawData, data)
	}
	win.SetID(id)
	if parent != nil {
		C.nox_window_call_field_94(parent.C(), 22, C.int(id), 0)
	}
	return win
}

func guiParseWidget(typ string, parent *Window, status int, px, py, w, h int, draw *C.nox_window_data, data unsafe.Pointer) *Window {
	draw.win = parent.C()
	iparent := unsafePtrToInt(unsafe.Pointer(parent.C()))
	udraw := unsafe.Pointer(draw)
	switch typ {
	case "PUSHBUTTON":
		draw.style |= 0x1
		return asWindow(C.nox_gui_newButtonOrCheckbox_4A91A0(iparent, C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), (*C.uint)(udraw)))
	case "RADIOBUTTON":
		draw.style |= 0x2
		return asWindow(C.nox_gui_newRadioButton_4A9330(iparent, C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), dataPtrToInt(draw), (*C.uint)(data)))
	case "CHECKBOX":
		draw.style |= 0x4
		return asWindow(C.nox_gui_newButtonOrCheckbox_4A91A0(iparent, C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), (*C.uint)(udraw)))
	case "VERTSLIDER":
		draw.style |= 0x8
		return asWindow(C.nox_gui_newSlider_4B4EE0(iparent, C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), (*C.uint)(udraw), (*C.float)(data)))
	case "HORZSLIDER":
		draw.style |= 0x10
		return asWindow(C.nox_gui_newSlider_4B4EE0(iparent, C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), (*C.uint)(udraw), (*C.float)(data)))
	case "SCROLLLISTBOX":
		draw.style |= 0x20
		return asWindow(C.nox_gui_newScrollListBox_4A4310(iparent, C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), dataPtrToInt(draw), (*C.short)(data)))
	case "ENTRYFIELD":
		draw.style |= 0x80
		return asWindow(C.nox_gui_newEntryField_488500(iparent, C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), dataPtrToInt(draw), (*C.ushort)(data)))
	case "STATICTEXT":
		draw.style |= 0x800
		return asWindow(C.nox_gui_newStaticText_489300(iparent, C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), (*C.uint)(udraw), (*C.uint)(data)))
	case "PROGRESSBAR":
		draw.style |= 0x1000
		return asWindow(C.nox_gui_newProgressBar_4CAF10(iparent, C.int(status), C.int(px), C.int(py), C.int(w), C.int(h), (*C.uint)(udraw)))
	}
	return nil
}

func guiResetWidgetData() {
	val := memmap.Uint32(0x5D4594, 2650656)
	*memmap.PtrUint32(0x5D4594, 1307288) = 0
	*memmap.PtrUint32(0x5D4594, 1307264) = val
	*memmap.PtrUint32(0x5D4594, 1307268) = val
	*memmap.PtrUint32(0x5D4594, 1307272) = val
	*memmap.PtrUint32(0x5D4594, 1307276) = val
	*memmap.PtrUint32(0x5D4594, 1307280) = val
	*memmap.PtrUint32(0x5D4594, 1307284) = val
}
