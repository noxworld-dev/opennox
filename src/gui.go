package main

/*
#include "proto.h"
*/
import "C"
import (
	"strings"
	"unsafe"

	"nox/client/gui"
	"nox/common/alloc"
	"nox/common/memmap"
)

var noxWinParents []*C.nox_window

//export nox_gui_winParentsReset_4A0CF0
func nox_gui_winParentsReset_4A0CF0() {
	noxWinParents = nil
}

//export nox_gui_winParentsTop_4A14F0
func nox_gui_winParentsTop_4A14F0() *C.nox_window {
	n := len(noxWinParents)
	if n == 0 {
		return nil
	}
	return noxWinParents[n-1]
}

//export nox_gui_winParentsPop_4A18A0
func nox_gui_winParentsPop_4A18A0() *C.nox_window {
	n := len(noxWinParents)
	if n == 0 {
		return nil
	}
	cur := noxWinParents[n-1]
	noxWinParents = noxWinParents[:n-1]
	return cur
}

//export nox_gui_winParentsPush_4A18C0
func nox_gui_winParentsPush_4A18C0(win *C.nox_window) {
	noxWinParents = append(noxWinParents, win)
}

//export nox_xxx_getToken_57BBC0
func nox_xxx_getToken_57BBC0(f *C.FILE, buf *C.char, sz C.int) C.int {
	out := asByteSlice(unsafe.Pointer(buf), int(sz))
	tok, _ := gui.ParseNextToken(newCFile(f))
	n := copy(out, tok)
	out[n] = 0
	return C.int(n)
}

//export nox_new_window_from_file
func nox_new_window_from_file(name *C.char, fnc unsafe.Pointer) *C.nox_window {
	nox_gui_winParentsReset_4A0CF0()
	C.sub_4A0D10()
	path := strings.Join([]string{"window", C.GoString(name)}, "\\")

	f := fopen(path, "r")
	if f == nil {
		return nil
	}
	defer C.fclose(f)

	sbuf := (*C.char)(alloc.Malloc(256))
	defer alloc.Free(unsafe.Pointer(sbuf))

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
			return C.nox_gui_parseWindowRoot_4A0D80(f, sbuf, (*[0]byte)(fnc))
		}
	}
	return nil
}

//export nox_gui_parseColorTo_4A05E0
func nox_gui_parseColorTo_4A05E0(out *C.uint, f *C.FILE, _ *C.char) C.int {
	fi := newCFile(f)
	fscanf(f, "%*s") // skip '='
	tok, err := gui.ParseNextToken(fi)
	if err != nil {
		return 0
	}
	if tok == "TRANSPARENT" {
		*out = 0x80000000
		return 1
	}
	r, g, b := gui.ParseColor(tok)
	v := nox_color_rgb_4344A0(r, g, b)
	*out = C.uint(v)
	return 1
}

func guiParseFont(f *C.FILE) (uintptr, bool) {
	fi := newCFile(f)
	fscanf(f, "%*s") // skip '='
	tok, _ := gui.ParseNextToken(fi)
	cstr := C.CString(tok)
	defer StrFree(cstr)
	fnt := C.nox_xxx_guiFontPtrByName_43F360(cstr)
	return uintptr(fnt), fnt != 0
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
	tok, err := gui.ParseNextToken(fi)
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
