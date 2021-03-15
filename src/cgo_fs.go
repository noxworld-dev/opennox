package main

/*
#include <stdbool.h>
#include <stdio.h>
*/
import "C"
import (
	"os"
	"path/filepath"
	"strings"
	"unsafe"

	"nox/common/fs"
)

var noxDataPath string

func setDataPath(path string) {
	noxDataPath = path
}

func getDataPath() string {
	return noxDataPath
}

//export nox_fs_root
func nox_fs_root() *C.char {
	return internCStr(getDataPath())
}

//export nox_fs_normalize
func nox_fs_normalize(path *C.char) *C.char {
	out := fs.Normalize(C.GoString(path))
	return C.CString(out)
}

//export nox_fs_workdir
func nox_fs_workdir(dst *C.char, max C.int) C.bool {
	dir, err := os.Getwd()
	if err != nil {
		return false
	}
	dir = strings.ReplaceAll(dir, string(filepath.Separator), "\\")
	out := asByteSlice(unsafe.Pointer(dst), int(max))
	n := copy(out[:len(out)-1], dir)
	out[n] = 0
	return len(dir) <= n
}

//export nox_fs_set_workdir
func nox_fs_set_workdir(path *C.char) C.bool {
	spath := C.GoString(path)
	spath = fs.Normalize(spath)
	err := os.Chdir(spath)
	return err == nil
}

func noxFSOpen(path *C.char, mode string) *C.FILE {
	spath := C.GoString(path)
	spath = fs.Normalize(spath)

	cmode := C.CString(mode)
	cpath := C.CString(spath)
	defer func() {
		StrFree(cpath)
		StrFree(cmode)
	}()
	return C.fopen(cpath, cmode)
}

//export nox_fs_open
func nox_fs_open(path *C.char) *C.FILE {
	return noxFSOpen(path, "rb")
}

//export nox_fs_open_text
func nox_fs_open_text(path *C.char) *C.FILE {
	return noxFSOpen(path, "r")
}

//export nox_fs_create
func nox_fs_create(path *C.char) *C.FILE {
	return noxFSOpen(path, "wb")
}

//export nox_fs_create_text
func nox_fs_create_text(path *C.char) *C.FILE {
	return noxFSOpen(path, "w")
}

//export nox_fs_open_rw
func nox_fs_open_rw(path *C.char) *C.FILE {
	return noxFSOpen(path, "r+b")
}

//export nox_fs_create_rw
func nox_fs_create_rw(path *C.char) *C.FILE {
	return noxFSOpen(path, "w+b")
}

//export nox_fs_append_text
func nox_fs_append_text(path *C.char) *C.FILE {
	return noxFSOpen(path, "w")
}
