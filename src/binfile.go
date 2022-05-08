package opennox

/*
#include <stdbool.h>
#include <stdio.h>
*/
import "C"
import (
	"encoding/binary"
	"errors"
	"fmt"
	"io"
	"os"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/ifs"
	"golang.org/x/crypto/blowfish"

	"github.com/noxworld-dev/noxcrypt"
	"github.com/noxworld-dev/opennox-lib/log"
)

var (
	binFileLog     = log.New("binfile")
	binFileCiphers = make(map[int]*blowfish.Cipher)
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

func (f *Binfile) Mode() BinFileMode {
	return f.mode
}

func (f *Binfile) Close() error {
	// it will call Binfile.close
	return f.file.Close()
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

func (f *Binfile) SetKey(key int) error {
	if f == nil {
		return errors.New("nil file")
	}
	f.key = key
	if f.key < 0 {
		f.close()
		return nil
	}
	switch f.mode {
	case BinFileRO:
		cr, err := crypt.NewReader(f.file, f.key)
		if err != nil {
			return err
		}
		f.read = cr
	case BinFileWO:
		cw, err := crypt.NewWriter(f.file, f.key)
		if err != nil {
			return err
		}
		cw.NoZero = true
		f.write = cw
	case BinFileRW:
		cf, err := crypt.NewFile(f.file, f.key)
		if err != nil {
			return err
		}
		f.full = cf
	default:
		return fmt.Errorf("unsupported file mode: %d", f.mode)
	}
	return nil
}

func (f *Binfile) FileSeek(off int64, whence int) error {
	if f.mode != BinFileRO {
		// this is what nox_binfile_fseek_409050 does for some reason
		if off != 0 {
			return nil
		}
		// same, for some reason it resets the writer to the end
		whence = io.SeekEnd
	}
	_, err := f.Seek(off, whence)
	if err == io.EOF {
		err = nil
	}
	return err
}

func (f *Binfile) ReadAligned(buf []byte) (int, error) {
	if f.read != nil {
		return f.read.ReadAligned(buf)
	} else if f.full != nil {
		return f.full.ReadAligned(buf)
	}
	return 0, errors.New("cannot read on writer")
}
func (f *Binfile) FileFlush() (int64, error) {
	var flusher interface {
		WriteEmpty() error
		Flush() error
	}
	if f.write != nil {
		flusher = f.write
	} else if f.full != nil {
		flusher = f.full
	}
	err := flusher.Flush()
	res := f.Written()
	if err != nil {
		f.file.err = err
		return res, err
	}
	err = flusher.WriteEmpty()
	if err != nil {
		f.file.err = err
	}
	return res, err
}

func (f *Binfile) WriteUint32At(v int32, off int64) error {
	if off < 0 {
		return nil
	}
	var buf [crypt.Block]byte
	binary.LittleEndian.PutUint32(buf[0:], uint32(v))
	c := binFileCiphers[f.key]
	if c == nil {
		var err error
		c, err = crypt.NewCipher(f.key)
		if err != nil {
			return err
		}
		binFileCiphers[f.key] = c
	}
	crypt.EncodeWith(c, buf[:])
	_, err := f.file.WriteAt(buf[:], off)
	f.file.Seek(0, io.SeekEnd)
	return err
}

//export nox_binfile_open_408CC0
func nox_binfile_open_408CC0(cpath *C.char, cmode C.int) *C.FILE {
	file, err := BinfileOpen(GoString(cpath), BinFileMode(cmode))
	if os.IsNotExist(err) {
		return nil
	} else if err != nil {
		binFileLog.Println(err)
		return nil
	}
	return newFileHandle(file.file)
}

func BinfileOpen(path string, mode BinFileMode) (*Binfile, error) {
	var (
		f   *os.File
		err error
	)
	switch mode {
	case BinFileRO:
		f, err = ifs.Open(path)
	case BinFileWO:
		f, err = ifs.Create(path)
	case BinFileRW:
		f, err = ifs.OpenFile(path, os.O_RDWR)
	default:
		return nil, fmt.Errorf("invalid mode: %d", mode)
	}
	if err != nil {
		return nil, err
	}
	file := &File{File: f}
	bin := &Binfile{file: file, mode: mode}
	file.bin = bin
	return bin, nil
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
	err := bin.SetKey(int(ckey))
	if err != nil {
		binFileLog.Println(err)
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
	err := bin.FileSeek(int64(coff), convWhence(cwhence))
	if err != nil {
		binFileLog.Println(err)
	}
	return 0
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
