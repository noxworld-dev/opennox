package main

/*
#include <stdbool.h>
#include <stdio.h>
*/
import "C"
import (
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
	dir, err := fs.Workdir()
	if err != nil {
		return false
	}
	n := StrCopy(dst, int(max), dir)
	return len(dir) <= n
}

//export nox_fs_progname
func nox_fs_progname(dst *C.char, max C.int) {
	StrCopy(dst, int(max), fs.ProgName())
}

//export nox_fs_remove
func nox_fs_remove(path *C.char) C.bool {
	return fs.Remove(C.GoString(path)) == nil
}

//export nox_fs_remove_dir
func nox_fs_remove_dir(path *C.char) C.bool {
	return fs.Remove(C.GoString(path)) == nil
}

//export nox_fs_set_workdir
func nox_fs_set_workdir(path *C.char) C.bool {
	return fs.Chdir(C.GoString(path)) == nil
}

//export nox_fs_copy
func nox_fs_copy(src, dst *C.char) C.bool {
	return fs.Copy(C.GoString(src), C.GoString(dst)) == nil
}

//export nox_fs_move
func nox_fs_move(src, dst *C.char) C.bool {
	return fs.Rename(C.GoString(src), C.GoString(dst)) == nil
}

//export nox_fs_fseek_start
func nox_fs_fseek_start(f *C.FILE, off C.uint) C.int {
	return C.fseek(f, C.long(off), C.SEEK_SET)
}

//export nox_fs_fread
func nox_fs_fread(f *C.FILE, dst unsafe.Pointer, sz C.int) C.int {
	return C.int(C.fread(dst, 1, C.uint(sz), f))
}

//export nox_fs_close
func nox_fs_close(f *C.FILE) {
	C.fclose(f)
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
