package legacy

/*
#include <stdbool.h>
#include <stdio.h>
*/
import "C"
import (
	"os"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/internal/binfile"
)

//export nox_binfile_open_408CC0
func nox_binfile_open_408CC0(cpath *C.char, cmode int) *C.FILE {
	file, err := binfile.BinfileOpen(GoString(cpath), binfile.Mode(cmode))
	if os.IsNotExist(err) {
		return nil
	} else if err != nil {
		binfile.Log.Println(err)
		return nil
	}
	return NewFileHandle(file.File)
}

//export nox_binfile_close_408D90
func nox_binfile_close_408D90(cfile *C.FILE) int {
	file := fileByHandle(cfile)
	file.Close()
	return 1
}

//export nox_binfile_ftell_426A50
func nox_binfile_ftell_426A50(cfile *C.FILE) int {
	file := fileByHandle(cfile)
	off := file.Bin.Written()
	return int(off)
}

//export nox_binfile_lastErr_409370
func nox_binfile_lastErr_409370(cfile *C.FILE) int {
	file := fileByHandle(cfile)
	if file.Err != nil {
		return -1
	}
	return 0
}

//export nox_binfile_cryptSet_408D40
func nox_binfile_cryptSet_408D40(cfile *C.FILE, ckey int) int {
	file := fileByHandle(cfile)
	bin := file.Bin
	err := bin.SetKey(ckey)
	if err != nil {
		binfile.Log.Println(err)
		return 0
	}
	return 1
}

//export nox_binfile_fread_408E40
func nox_binfile_fread_408E40(cbuf *C.char, sz, cnt int, cfile *C.FILE) int {
	if sz*cnt == 0 {
		return 0
	}
	file := fileByHandle(cfile)
	bin := file.Bin
	buf := unsafe.Slice((*byte)(unsafe.Pointer(cbuf)), sz*cnt)
	n, err := bin.Read(buf)
	if err != nil {
		file.Err = err
	}
	return n / sz
}

//export nox_binfile_fread_raw_40ADD0
func nox_binfile_fread_raw_40ADD0(cbuf *C.char, sz, cnt C.size_t, cfile *C.FILE) int {
	if sz*cnt == 0 {
		return 0
	}
	n := nox_fs_fread(cfile, unsafe.Pointer(cbuf), int(sz*cnt))
	if n >= 0 {
		n /= int(sz)
	}
	return n
}

//export nox_binfile_fread_align_408FE0
func nox_binfile_fread_align_408FE0(cbuf *C.char, sz, cnt int, cfile *C.FILE) int {
	if sz*cnt == 0 {
		return 0
	}
	file := fileByHandle(cfile)
	bin := file.Bin
	buf := unsafe.Slice((*byte)(unsafe.Pointer(cbuf)), sz*cnt)
	n, err := bin.ReadAligned(buf)
	if err != nil {
		n = -1
	}
	if err != nil {
		file.Err = err
	}
	return n / sz
}

//export nox_binfile_skipLine_409520
func nox_binfile_skipLine_409520(cfile *C.FILE) int {
	file := fileByHandle(cfile)
	if err := file.Bin.SkipLine(); err != nil {
		binfile.Log.Println(err)
		return -1
	}
	return 0
}

//export nox_binfile_fseek_409050
func nox_binfile_fseek_409050(cfile *C.FILE, coff, cwhence int) int {
	file := fileByHandle(cfile)
	err := file.Bin.FileSeek(int64(coff), convWhence(cwhence))
	if err != nil {
		binfile.Log.Println(err)
	}
	return 0
}
