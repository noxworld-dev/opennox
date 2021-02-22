package main

/*
#include "defs.h"
*/
import "C"
import (
	"io"
	"unsafe"

	"nox/client/gui"
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
	tok, _ := gui.ParseNextToken(fileByteReader{f})
	n := copy(out, tok)
	out[n] = 0
	return C.int(n)
}

type fileByteReader struct {
	f *C.FILE
}

func (f fileByteReader) ReadByte() (byte, error) {
	c := C.fgetc(f.f)
	if c < 0 {
		// it's not always true, but that's what original code does
		return 0, io.EOF
	}
	return byte(c), nil
}
