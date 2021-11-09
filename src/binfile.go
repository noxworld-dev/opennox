package nox

/*
#include <stdbool.h>
#include <stdio.h>
*/
import "C"
import (
	"encoding/binary"
	"errors"
	"io"
	"os"
	"unsafe"

	"nox/v1/common/crypt"
	"nox/v1/common/fs"
	"nox/v1/common/log"
)

var (
	binFileLog = log.New("binfile")
)

type BinFileMode int

const (
	BinFileRO = BinFileMode(0)
	BinFileWO = BinFileMode(1)
	BinFileRW = BinFileMode(2)
)

type Binfile struct {
	file  *File
	mode  BinFileMode
	key   int
	write *crypt.Writer
	read  *crypt.Reader
	full  *crypt.File
}

func (f *Binfile) close() error {
	if f.read != nil {
		f.read = nil
	}
	var last error
	if f.write != nil {
		if err := f.write.Close(); err != nil {
			last = err
		}
		f.write = nil
	}
	if f.full != nil {
		if err := f.full.Close(); err != nil {
			last = err
		}
		f.full = nil
	}
	return last
}

func (f *Binfile) Written() int64 {
	if f.write != nil {
		return f.write.Written()
	} else if f.full != nil {
		return f.full.Written()
	}
	off, _ := f.Seek(0, io.SeekCurrent)
	return off
}

func (f *Binfile) Read(p []byte) (int, error) {
	if f.read != nil {
		return f.read.Read(p)
	} else if f.full != nil {
		return f.full.Read(p)
	}
	return f.file.Read(p)
}

func (f *Binfile) Write(p []byte) (int, error) {
	if f.write != nil {
		return f.write.Write(p)
	} else if f.full != nil {
		return f.full.Write(p)
	}
	return f.file.Write(p)
}

func (f *Binfile) Seek(off int64, whence int) (int64, error) {
	if f.read != nil {
		return f.read.Seek(off, whence)
	} else if f.write != nil {
		return 0, errors.New("seek on binfile writer")
	} else if f.full != nil {
		return f.full.Seek(off, whence)
	}
	return f.file.Seek(off, whence)
}

func (f *Binfile) flags() string {
	if f.read != nil {
		return "R"
	} else if f.write != nil {
		return "W"
	} else if f.full != nil {
		return "RW"
	}
	return ""
}

//export nox_binfile_open_408CC0
func nox_binfile_open_408CC0(cpath *C.char, cmode C.int) *C.FILE {
	path := GoString(cpath)
	mode := BinFileMode(cmode)
	var (
		f   *os.File
		err error
	)
	switch mode {
	case BinFileRO:
		f, err = fs.Open(path)
	case BinFileWO:
		f, err = fs.Create(path)
	case BinFileRW:
		f, err = fs.OpenFile(path, os.O_RDWR)
	default:
		binFileLog.Println("invalid mode:", int(cmode))
		return nil
	}
	if os.IsNotExist(err) {
		return nil
	} else if err != nil {
		binFileLog.Println(err)
		return nil
	}
	file := &File{File: f}
	bin := &Binfile{file: file, mode: mode}
	file.bin = bin
	return newFileHandle(file)
}

//export nox_binfile_close_408D90
func nox_binfile_close_408D90(cfile *C.FILE) C.int {
	file := fileByHandle(cfile)
	file.Close()
	return 1
}

//export nox_binfile_ftell_426A50
func nox_binfile_ftell_426A50(cfile *C.FILE) C.int {
	file := fileByHandle(cfile)
	off := file.bin.Written()
	return C.int(off)
}

//export nox_binfile_lastErr_409370
func nox_binfile_lastErr_409370(cfile *C.FILE) C.int {
	file := fileByHandle(cfile)
	if file.err != nil {
		return -1
	}
	return 0
}

//export nox_binfile_cryptSet_408D40
func nox_binfile_cryptSet_408D40(cfile *C.FILE, ckey C.int) C.int {
	file := fileByHandle(cfile)
	bin := file.bin
	if bin == nil {
		binFileLog.Println("crypt not enabled on this file")
		return 0
	}
	bin.key = int(ckey)
	if bin.key < 0 {
		bin.close()
		return 1
	}
	switch bin.mode {
	case BinFileRO:
		cr, err := crypt.NewReader(bin.file, bin.key)
		if err != nil {
			binFileLog.Println(err)
			return 0
		}
		bin.read = cr
	case BinFileWO:
		cw, err := crypt.NewWriter(bin.file, bin.key)
		if err != nil {
			binFileLog.Println(err)
			return 0
		}
		cw.NoZero = true
		bin.write = cw
	case BinFileRW:
		cf, err := crypt.NewFile(bin.file, bin.key)
		if err != nil {
			panic(err)
		}
		bin.full = cf
	default:
		binFileLog.Println("unsupported file mode:", bin.mode)
		return 0
	}
	return 1
}

//export nox_binfile_fread_408E40
func nox_binfile_fread_408E40(cbuf *C.char, sz, cnt C.int, cfile *C.FILE) C.int {
	if sz*cnt == 0 {
		return 0
	}
	file := fileByHandle(cfile)
	bin := file.bin
	buf := unsafe.Slice((*byte)(unsafe.Pointer(cbuf)), int(sz*cnt))
	n, err := bin.Read(buf)
	if err != nil {
		file.err = err
	}
	return C.int(n) / sz
}

//export nox_binfile_fread_raw_40ADD0
func nox_binfile_fread_raw_40ADD0(cbuf *C.char, sz, cnt C.size_t, cfile *C.FILE) C.int {
	if sz*cnt == 0 {
		return 0
	}
	n := nox_fs_fread(cfile, unsafe.Pointer(cbuf), C.int(sz*cnt))
	if n >= 0 {
		n /= C.int(sz)
	}
	return n
}

//export nox_binfile_fread_align_408FE0
func nox_binfile_fread_align_408FE0(cbuf *C.char, sz, cnt C.int, cfile *C.FILE) C.int {
	if sz*cnt == 0 {
		return 0
	}
	file := fileByHandle(cfile)
	bin := file.bin
	buf := unsafe.Slice((*byte)(unsafe.Pointer(cbuf)), int(sz*cnt))
	var (
		n   int
		err error
	)
	if bin.read != nil {
		n, err = bin.read.ReadAligned(buf)
	} else if bin.full != nil {
		n, err = bin.full.ReadAligned(buf)
	} else {
		return -1
	}
	if err != nil {
		file.err = err
	}
	return C.int(n) / sz
}

//export nox_binfile_skipLine_409520
func nox_binfile_skipLine_409520(cfile *C.FILE) C.int {
	file := fileByHandle(cfile)
	bin := file.bin
	var buf [1]byte
	for {
		_, err := bin.Read(buf[:])
		if err == io.EOF {
			break
		} else if err != nil {
			return -1
		}
		if buf[0] != '\n' {
			break
		}
	}
	return 0
}

//export nox_binfile_fseek_409050
func nox_binfile_fseek_409050(cfile *C.FILE, coff, cwhence C.int) C.int {
	file := fileByHandle(cfile)
	bin := file.bin
	off1, whence := int64(coff), convWhence(cwhence)
	if bin.mode != BinFileRO {
		// this is what nox_binfile_fseek_409050 does for some reason
		if off1 != 0 {
			return 0
		}
		// same, for some reason it resets the writer to the end
		whence = io.SeekEnd
	}
	_, err := bin.Seek(off1, whence)
	if err == io.EOF {
		err = nil
	}
	if err != nil {
		binFileLog.Println(err)
	}
	return 0
}

//export nox_binfile_disable_409560
func nox_binfile_disable_409560() {}

//export nox_binfile_reset_4093A0
func nox_binfile_reset_4093A0() {}

//export nox_binfile_fflush_409110
func nox_binfile_fflush_409110(cfile *C.FILE) C.int {
	file := fileByHandle(cfile)
	bin := file.bin
	var flusher interface {
		WriteEmpty() error
		Flush() error
	}
	if bin.write != nil {
		flusher = bin.write
	} else if bin.full != nil {
		flusher = bin.full
	}
	err := flusher.Flush()
	if err != nil {
		binFileLog.Println(err)
		file.err = err
	}
	res := bin.Written()
	err = flusher.WriteEmpty()
	if err != nil {
		binFileLog.Println(err)
		file.err = err
	}
	return C.int(res)
}

//export nox_binfile_fwrite_409200
func nox_binfile_fwrite_409200(cbuf *C.char, sz, cnt C.int, cfile *C.FILE) C.size_t {
	if sz*cnt == 0 {
		return 0
	}
	file := fileByHandle(cfile)
	bin := file.bin
	buf := unsafe.Slice((*byte)(unsafe.Pointer(cbuf)), int(sz*cnt))
	n, err := bin.Write(buf)
	if err != nil {
		file.err = err
	}
	return C.size_t(n / int(sz))
}

//export nox_binfile_writeIntAt_409190
func nox_binfile_writeIntAt_409190(cfile *C.FILE, cval, coff C.int) {
	if coff < 0 {
		return
	}
	file := fileByHandle(cfile)
	var buf [crypt.Block]byte
	binary.LittleEndian.PutUint32(buf[0:], uint32(cval))
	crypt.Encode(buf[:], file.bin.key)
	file.WriteAt(buf[:], int64(coff))
	file.Seek(0, io.SeekEnd)
}
