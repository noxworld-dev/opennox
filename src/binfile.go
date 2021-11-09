package nox

/*
#include <stdbool.h>
#include <stdio.h>
*/
import "C"
import (
	"bytes"
	"encoding/binary"
	"encoding/hex"
	"errors"
	"fmt"
	"io"
	"os"
	"path/filepath"
	"runtime/debug"
	"strings"
	"unsafe"

	"nox/v1/common/crypt"
	"nox/v1/common/fs"
	"nox/v1/common/log"
)

var (
	binFileLog     = log.New("binfile")
	binFileTmp     string
	binFileByCFile = make(map[*File]*Binfile)
	binFileDebug   = os.Getenv("NOX_DEBUG_BINFILE") == "true"
	binFileGo      = os.Getenv("NOX_BINFILE_GO") == "true"
)

type BinFileMode int

const (
	BinFileRO = BinFileMode(0)
	BinFileWO = BinFileMode(1)
	BinFileRW = BinFileMode(2)
)

type binfileSkip struct {
	fseek   bool
	seek    bool
	fread   bool
	fwrite  bool
	tell    bool
	read    bool
	readRaw bool
	write   bool
	lasterr bool
}

type Binfile struct {
	file  *File
	mode  BinFileMode
	key   int
	write *crypt.Writer
	read  *crypt.Reader
	full  *crypt.File

	orig      *File
	noRaw     binfileSkip
	noRawFrom string
}

func (f *Binfile) assertSkip() {
	if f.noRaw != (binfileSkip{}) {
		panic(fmt.Errorf("skip flags not empty: %+v (from %s)", f.noRaw, f.noRawFrom))
	}
}

func (f *Binfile) setSkip() {
	f.noRawFrom = caller(1)
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

func (f *Binfile) rawSeek(off int64, whence int) {
	if f.noRaw.fseek {
		//if binFileDebug {
		//	log.Printf("binfile: SKIP seek(%s,raw): %q (%d, %d)", f.flags(), f.orig.Name(), off, whence)
		//}
		return
	}
	if binFileDebug {
		log.Printf("binfile: seek(%s,raw): %q (%d, %d)", f.flags(), f.orig.Name(), off, whence)
	}
	f.file.Seek(off, whence)
	if whence != io.SeekCurrent {
		checkEqualContent(fmt.Sprintf("seek(%s)", f.flags()), f.orig.File, f.file.File)
	} else {
		filesCheckOffsets(f.orig.File, f.file.File)
	}
}

func (f *Binfile) rawWrite(p []byte) {
	if f.noRaw.fwrite {
		//if binFileDebug {
		//	log.Printf("binfile: SKIP write(%s,raw): %q [:%d]", f.flags(), f.orig.Name(), len(p))
		//}
		return
	}
	if binFileDebug {
		log.Printf("binfile: write(%s,raw): %q [:%d]", f.flags(), f.orig.Name(), len(p))
	}
	f.file.Write(p)
	filesCheckOffsets(f.orig.File, f.file.File)
}

func (f *Binfile) rawRead(n int) {
	if f.noRaw.fread {
		//if binFileDebug {
		//	log.Printf("binfile: SKIP read(%s,raw): %q [:%d]", f.flags(), f.orig.Name(), n)
		//}
		return
	}
	if binFileDebug {
		log.Printf("binfile: read(%s,raw): %q [:%d]", f.flags(), f.orig.Name(), n)
	}
	buf := make([]byte, n)
	f.file.Read(buf)
	filesCheckOffsets(f.orig.File, f.file.File)
}

func filesCheckOffsets(f1, f2 *os.File) {
	off1, err := f1.Seek(0, io.SeekCurrent)
	if err != nil {
		panic(err)
	}
	off2, err := f2.Seek(0, io.SeekCurrent)
	if err != nil {
		panic(err)
	}
	if off1 != off2 {
		panic(fmt.Errorf("different offsets: %d vs %d", off1, off2))
	}
}

func hexDataBlock(data []byte, block int) string {
	block *= 2
	str := hex.EncodeToString(data)
	var parts []string
	for len(str) > 0 {
		if len(str) < block {
			parts = append(parts, str)
			str = ""
		} else {
			parts = append(parts, str[:block])
			str = str[block:]
		}
	}
	return strings.Join(parts, " ")
}

func checkEqualBytes(pref string, name1, name2 string, buf1, buf2 []byte) {
	if bytes.Equal(buf1, buf2) {
		return
	}
	off := 0
	sz1, sz2 := len(buf1), len(buf2)
	for i := range buf1 {
		if i >= len(buf2) || buf1[i] != buf2[i] {
			off = i
			off -= off % crypt.Block
			if off >= crypt.Block {
				off -= crypt.Block
			}
			buf1 = buf1[off:]
			buf2 = buf2[off:]
			break
		}
	}
	const max = 64
	end1 := buf1
	if len(end1) > max {
		end1 = end1[len(end1)-max:]
	}
	end2 := buf2
	if len(end2) > max {
		end2 = end2[len(end2)-max:]
	}
	if len(buf1) > max {
		buf1 = buf1[:max]
	}
	if len(buf2) > max {
		buf2 = buf2[:max]
	}
	if pref != "" {
		pref += " "
	}
	panic(fmt.Errorf("%sdifferent content (+%d):\n%s (%d):\n%s ... %s\n%s (%d):\n%s ... %s",
		pref, off, name1, sz1, hexDataBlock(buf1, crypt.Block), hexDataBlock(end1, crypt.Block), name2, sz2, hexDataBlock(buf2, crypt.Block), hexDataBlock(end2, crypt.Block)))
}

func checkEqualContent(pref string, f1, f2 *os.File) {
	off1, err := f1.Seek(0, io.SeekCurrent)
	if err != nil {
		panic(err)
	}
	off2, err := f2.Seek(0, io.SeekCurrent)
	if err != nil {
		panic(err)
	}
	if off1 != off2 {
		panic(fmt.Errorf("different offsets: %d vs %d", off1, off2))
	}
	_, err = f1.Seek(0, io.SeekStart)
	if err != nil {
		panic(err)
	}
	_, err = f2.Seek(0, io.SeekStart)
	if err != nil {
		panic(err)
	}
	buf1, err := io.ReadAll(f1)
	if err != nil {
		panic(err)
	}
	buf2, err := io.ReadAll(f2)
	if err != nil {
		panic(err)
	}
	_, err = f1.Seek(off1, io.SeekStart)
	if err != nil {
		panic(err)
	}
	_, err = f2.Seek(off2, io.SeekStart)
	if err != nil {
		panic(err)
	}
	checkEqualBytes(pref, f1.Name(), f2.Name(), buf1, buf2)
}

func nox_binfile_open_408CC0_test(cpath *C.char, cmode C.int) *Binfile {
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
	return bin
}

//export nox_binfile_open_408CC0_hook
func nox_binfile_open_408CC0_hook(cpath *C.char, cmode C.int, cfile *C.FILE) {
	if !binFileGo {
		return
	}
	if binFileTmp == "" {
		dir, err := os.MkdirTemp("", "nox-binfile-")
		if err != nil {
			panic(err)
		}
		binFileTmp = dir
	}
	file := fileByHandle(cfile)
	tpath := filepath.Join(binFileTmp, file.Name())
	if err := os.MkdirAll(filepath.Dir(tpath), 0755); err != nil {
		panic(err)
	}
	switch cmode {
	case 0:
		err := fs.Copy(file.Name(), tpath)
		if err != nil {
			panic(err)
		}
	case 1:
		// create
	case 2:
		err := fs.Copy(file.Name(), tpath)
		if !os.IsNotExist(err) && err != nil {
			panic(err)
		}
	default:
		panic(cmode)
	}
	bin := nox_binfile_open_408CC0_test(internCStr(tpath), cmode)
	if bin == nil {
		panic("no file")
	}
	bin.orig = file
	file.hooks.onSeek = bin.rawSeek
	file.hooks.onRead = bin.rawRead
	file.hooks.onWrite = bin.rawWrite
	binFileByCFile[file] = bin
}

func nox_binfile_close_408D90_test(cfile *C.FILE) C.int {
	file := fileByHandle(cfile)
	file.Close()
	return 1
}

//export nox_binfile_close_408D90_hookStart
func nox_binfile_close_408D90_hookStart(cfile *C.FILE) {
	if !binFileGo {
		return
	}
	file := fileByHandle(cfile)
	bin := binFileByCFile[file]
	bin.assertSkip()
	bin.noRaw.fwrite = true
	bin.setSkip()
	filesCheckOffsets(file.File, bin.file.File)
}

//export nox_binfile_close_408D90_hook
func nox_binfile_close_408D90_hook(cfile *C.FILE, res C.int) {
	if !binFileGo {
		return
	}
	file := fileByHandle(cfile)
	bin := binFileByCFile[file]
	delete(binFileByCFile, file)
	defer func() {
		bin.noRaw.fwrite = false
		bin.assertSkip()
	}()
	got := nox_binfile_close_408D90_test(newFileHandle(bin.file))
	if res != got {
		panic(fmt.Errorf("invalid response: %d vs %d", int(res), int(got)))
	}
	if bin.mode != BinFileRO {
		f, err := fs.Open(file.Name())
		if err != nil {
			panic(err)
		}
		defer f.Close()
		buf, err := io.ReadAll(f)
		if err != nil {
			panic(err)
		}
		f2, err := fs.Open(bin.file.Name())
		if err != nil {
			panic(err)
		}
		defer f2.Close()
		buf2, err := io.ReadAll(f2)
		if err != nil {
			panic(err)
		}
		checkEqualBytes(fmt.Sprintf("close(%s)", bin.flags()), f.Name(), bin.file.Name(), buf, buf2)
	}
}

//export nox_binfile_ftell_426A50_hook
func nox_binfile_ftell_426A50_hook(cfile *C.FILE, res C.int) {
	if !binFileGo {
		return
	}
	file := fileByHandle(cfile)
	bin := binFileByCFile[file]
	if bin.noRaw.tell {
		return
	}
	got := nox_binfile_ftell_426A50_test(newFileHandle(bin.file))
	if res != got {
		panic(fmt.Errorf("invalid response: %d vs %d", int(res), int(got)))
	}
}

func nox_binfile_ftell_426A50_test(cfile *C.FILE) C.int {
	file := fileByHandle(cfile)
	off := file.bin.Written()
	return C.int(off)
}

//export nox_binfile_lastErr_409370_hook
func nox_binfile_lastErr_409370_hook(cfile *C.FILE, res C.int) C.bool {
	if !binFileGo {
		return true
	}
	file := fileByHandle(cfile)
	bin := binFileByCFile[file]
	if bin.noRaw.tell {
		return true
	}
	got := nox_binfile_lastErr_409370_test(newFileHandle(bin.file))
	if res != got {
		binFileLog.Println(fmt.Errorf("invalid response: %d vs %d", int(res), int(got)))
		return false
	}
	return true
}

func nox_binfile_lastErr_409370_test(cfile *C.FILE) C.int {
	file := fileByHandle(cfile)
	if file.err != nil {
		return -1
	}
	return 0
}

func nox_binfile_cryptSet_408D40_test(cfile *C.FILE, ckey C.int) C.int {
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

//export nox_binfile_cryptSet_408D40_hook
func nox_binfile_cryptSet_408D40_hook(cfile *C.FILE, ckey, res C.int) {
	if !binFileGo {
		return
	}
	file := fileByHandle(cfile)
	bin := binFileByCFile[file]
	got := nox_binfile_cryptSet_408D40_test(newFileHandle(bin.file), ckey)
	if res != got {
		panic(fmt.Errorf("invalid response: %d vs %d", int(res), int(got)))
	}
}

func nox_binfile_fread_408E40_test(cbuf *C.char, sz, cnt C.int, cfile *C.FILE) C.int {
	if sz == 0 || cnt == 0 {
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

//export nox_binfile_fread_408E40_hookStart
func nox_binfile_fread_408E40_hookStart(cfile *C.FILE) {
	if !binFileGo {
		return
	}
	file := fileByHandle(cfile)
	bin := binFileByCFile[file]
	if bin == nil || bin.noRaw.read {
		return
	}
	bin.assertSkip()
	bin.noRaw.fread = true
	bin.noRaw.readRaw = true
	bin.noRaw.fseek = true
	bin.noRaw.seek = true
	bin.setSkip()
	if bin.read != nil {
		filesCheckOffsets(file.File, bin.file.File)
	} else if bin.write != nil {
		panic("read on writer")
	} else if bin.full != nil {
		filesCheckOffsets(file.File, bin.file.File)
	}
}

//export nox_binfile_fread_408E40_hook
func nox_binfile_fread_408E40_hook(cbuf *C.char, a2, a3 C.int, cfile *C.FILE, res C.int) C.bool {
	if !binFileGo {
		return true
	}
	file := fileByHandle(cfile)
	bin := binFileByCFile[file]
	if bin.noRaw.read {
		return true
	}
	defer func() {
		bin.noRaw.fread = false
		bin.noRaw.readRaw = false
		bin.noRaw.fseek = false
		bin.noRaw.seek = false
		bin.assertSkip()
	}()

	buf := unsafe.Slice((*byte)(unsafe.Pointer(cbuf)), int(a2*a3))
	buf = buf[:int(a2*res)]
	if binFileDebug {
		if len(buf) != cap(buf) {
			log.Printf("binfile: read(%s): %s [:%d:%d]", bin.flags(), file.Name(), len(buf), cap(buf))
		} else {
			log.Printf("binfile: read(%s): %s [:%d]", bin.flags(), file.Name(), len(buf))
		}
	}
	buf2 := make([]byte, int(a2*a3))
	got := nox_binfile_fread_408E40_test((*C.char)(unsafe.Pointer(&buf2[0])), a2, a3, newFileHandle(bin.file))
	if res != got {
		panic(fmt.Errorf("invalid response: %d vs %d", int(res), int(got)))
	}
	buf2 = buf2[:a2*got]
	checkEqualBytes(fmt.Sprintf("read(%s)", bin.flags()), file.Name(), bin.file.Name(), buf, buf2)
	return true
}

func nox_binfile_fread_raw_40ADD0_test(cbuf *C.char, sz, cnt C.size_t, cfile *C.FILE) C.int {
	n := nox_fs_fread(cfile, unsafe.Pointer(cbuf), C.int(sz*cnt))
	if n >= 0 {
		n /= C.int(sz)
	}
	return n
}

//export nox_binfile_fread_raw_40ADD0_hookStart
func nox_binfile_fread_raw_40ADD0_hookStart(cfile *C.FILE) {
	if !binFileGo {
		return
	}
	file := fileByHandle(cfile)
	bin := binFileByCFile[file]
	if bin == nil || bin.noRaw.readRaw {
		return
	}
	bin.assertSkip()
	bin.noRaw.fread = true
	bin.setSkip()
}

//export nox_binfile_fread_raw_40ADD0_hook
func nox_binfile_fread_raw_40ADD0_hook(cbuf *C.char, a2, a3 C.int, cfile *C.FILE, res C.int) C.bool {
	if !binFileGo {
		return true
	}
	file := fileByHandle(cfile)
	bin := binFileByCFile[file]
	if bin == nil || bin.noRaw.readRaw {
		return true
	}
	defer func() {
		bin.noRaw.fread = false
		bin.assertSkip()
	}()
	buf := unsafe.Slice((*byte)(unsafe.Pointer(cbuf)), int(a2*a3))
	buf = buf[:int(a2*res)]

	buf2 := make([]byte, int(a2*a3))
	got := nox_binfile_fread_raw_40ADD0_test((*C.char)(unsafe.Pointer(&buf2[0])), C.uint(a2), C.uint(a3), newFileHandle(bin.file))
	if res != got {
		panic(fmt.Errorf("invalid response: %d vs %d", int(res), int(got)))
	}
	buf2 = buf2[:a2*got]
	checkEqualBytes(fmt.Sprintf("read(%s)", bin.flags()), file.Name(), bin.file.Name(), buf, buf2)
	return true
}

//export nox_binfile_fread_align_408FE0_hookStart
func nox_binfile_fread_align_408FE0_hookStart(cfile *C.FILE) {
	if !binFileGo {
		return
	}
	file := fileByHandle(cfile)
	bin := binFileByCFile[file]
	bin.assertSkip()
	bin.noRaw.fread = true
	bin.noRaw.read = true
	bin.noRaw.readRaw = true
	bin.setSkip()
	filesCheckOffsets(file.File, bin.file.File)
}

//export nox_binfile_fread_align_408FE0_hook
func nox_binfile_fread_align_408FE0_hook(cbuf *C.char, a2, a3 C.int, cfile *C.FILE, res C.int) C.bool {
	if !binFileGo {
		return true
	}
	file := fileByHandle(cfile)
	bin := binFileByCFile[file]
	defer func() {
		bin.noRaw.fread = false
		bin.noRaw.read = false
		bin.noRaw.readRaw = false
		bin.assertSkip()
	}()

	buf := unsafe.Slice((*byte)(unsafe.Pointer(cbuf)), int(a2*a3))
	buf = buf[:int(a2*res)]
	if binFileDebug {
		if len(buf) != cap(buf) {
			log.Printf("binfile: read-align(%s): %s [:%d:%d]", bin.flags(), file.Name(), len(buf), cap(buf))
		} else {
			log.Printf("binfile: read-align(%s): %s [:%d]", bin.flags(), file.Name(), len(buf))
		}
	}
	buf2 := make([]byte, int(a2*a3))
	got := nox_binfile_fread_align_408FE0_test((*C.char)(unsafe.Pointer(&buf2[0])), a2, a3, newFileHandle(bin.file))
	if res != got {
		panic(fmt.Errorf("invalid response: %d vs %d", int(res), int(got)))
	}
	buf2 = buf2[:a2*got]
	checkEqualBytes(fmt.Sprintf("read-align(%s)", bin.flags()), file.Name(), bin.file.Name(), buf, buf2)
	return true
}

func nox_binfile_fread_align_408FE0_test(cbuf *C.char, sz, cnt C.int, cfile *C.FILE) C.int {
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

//export nox_binfile_skipLine_409520_hookStart
func nox_binfile_skipLine_409520_hookStart(cfile *C.FILE) {
	if !binFileGo {
		return
	}
	file := fileByHandle(cfile)
	bin := binFileByCFile[file]
	bin.assertSkip()
	bin.noRaw.fread = true
	bin.noRaw.read = true
	bin.noRaw.readRaw = true
	bin.noRaw.lasterr = true
	bin.setSkip()
	filesCheckOffsets(file.File, bin.file.File)
}

//export nox_binfile_skipLine_409520_hook
func nox_binfile_skipLine_409520_hook(cfile *C.FILE, res C.int) {
	if !binFileGo {
		return
	}
	file := fileByHandle(cfile)
	bin := binFileByCFile[file]
	defer func() {
		bin.noRaw.fread = false
		bin.noRaw.read = false
		bin.noRaw.readRaw = false
		bin.noRaw.lasterr = false
		bin.assertSkip()
	}()
	got := nox_binfile_skipLine_409520_test(newFileHandle(bin.file))
	if res != got {
		panic(fmt.Errorf("invalid response: %d vs %d", int(res), int(got)))
	}
	filesCheckOffsets(file.File, bin.file.File)
}

func nox_binfile_skipLine_409520_test(cfile *C.FILE) C.int {
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

func nox_binfile_fseek_409050_test(cfile *C.FILE, coff, cwhence C.int) C.int {
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

//export nox_binfile_fseek_409050_hookStart
func nox_binfile_fseek_409050_hookStart(cfile *C.FILE) {
	if !binFileGo {
		return
	}
	file := fileByHandle(cfile)
	bin := binFileByCFile[file]
	if bin.noRaw.seek {
		return
	}
	bin.assertSkip()
	bin.noRaw.fread = true
	bin.noRaw.readRaw = true
	bin.noRaw.fseek = true
	bin.setSkip()
	if bin.read != nil {
		filesCheckOffsets(file.File, bin.file.File)
	} else if bin.write != nil {
		panic("seek on writer")
	} else if bin.full != nil {
		filesCheckOffsets(file.File, bin.file.File)
	}
}

//export nox_binfile_fseek_409050_hook
func nox_binfile_fseek_409050_hook(cfile *C.FILE, coff, cwhence C.int) C.bool {
	if !binFileGo {
		return true
	}
	file := fileByHandle(cfile)
	bin := binFileByCFile[file]
	if bin.noRaw.seek {
		return true
	}
	defer func() {
		bin.noRaw.fread = false
		bin.noRaw.readRaw = false
		bin.noRaw.fseek = false
		bin.assertSkip()
	}()
	got := nox_binfile_fseek_409050_test(newFileHandle(bin.file), coff, cwhence)
	if 0 != got {
		panic(fmt.Errorf("invalid response: %d vs %d", 0, int(got)))
	}
	filesCheckOffsets(file.File, bin.file.File)
	return true
}

func nox_binfile_fflush_409110_test(cfile *C.FILE) C.int {
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

//export nox_binfile_fflush_409110_hookStart
func nox_binfile_fflush_409110_hookStart(cfile *C.FILE, binoff C.int) {
	if !binFileGo {
		return
	}
	file := fileByHandle(cfile)
	bin := binFileByCFile[file]
	bin.assertSkip()
	bin.noRaw.fwrite = true
	bin.setSkip()
	filesCheckOffsets(file.File, bin.file.File)
	if boff := bin.Written(); boff != int64(binoff) {
		panic(fmt.Errorf("bin offset is different: %d vs %d", boff, int64(binoff)))
	}
}

//export nox_binfile_fflush_409110_hook
func nox_binfile_fflush_409110_hook(cfile *C.FILE, binoff C.int, res C.int) (out C.bool) {
	if !binFileGo {
		return true
	}
	file := fileByHandle(cfile)
	bin := binFileByCFile[file]
	defer func() {
		if r := recover(); r != nil {
			log.Printf("binfile: flush(%s): %v", bin.flags(), r)
			debug.PrintStack()
			out = false
		}
		bin.noRaw.fwrite = false
		bin.assertSkip()
	}()
	if binFileDebug {
		off, _ := bin.file.Seek(0, io.SeekCurrent)
		log.Printf("binfile: flush(%s): %s, +%d (+%d)", bin.flags(), file.Name(), off, bin.Written())
	}
	got := nox_binfile_fflush_409110_test(newFileHandle(bin.file))
	if res != got {
		panic(fmt.Errorf("invalid response: %d vs %d", int(res), int(got)))
	}
	checkEqualContent(fmt.Sprintf("flush(%s)", bin.flags()), file.File, bin.file.File)
	if boff := bin.Written(); boff != int64(binoff) {
		panic(fmt.Errorf("bin offset is different: %d vs %d", boff, int64(binoff)))
	}
	return true
}

func nox_binfile_fwrite_409200_test(cbuf *C.char, sz, cnt C.int, cfile *C.FILE) C.size_t {
	file := fileByHandle(cfile)
	bin := file.bin
	buf := unsafe.Slice((*byte)(unsafe.Pointer(cbuf)), int(sz*cnt))
	n, err := bin.Write(buf)
	if err != nil {
		file.err = err
	}
	return C.size_t(n / int(sz))
}

//export nox_binfile_fwrite_409200_hookStart
func nox_binfile_fwrite_409200_hookStart(cfile *C.FILE, binoff C.int) {
	if !binFileGo {
		return
	}
	file := fileByHandle(cfile)
	bin := binFileByCFile[file]
	if bin.noRaw.write {
		return
	}
	bin.assertSkip()
	bin.noRaw.fwrite = true
	bin.setSkip()
	if bin.read != nil {
		panic("write on reader")
	} else if bin.write != nil {
		filesCheckOffsets(file.File, bin.file.File)
	} else if bin.full != nil {
		filesCheckOffsets(file.File, bin.file.File)
	}
	if boff := bin.Written(); boff != int64(binoff) {
		panic(fmt.Errorf("bin offset is different: %d vs %d", boff, int64(binoff)))
	}
}

//export nox_binfile_fwrite_409200_hook
func nox_binfile_fwrite_409200_hook(cbuf *C.char, a2, a3 C.int, cfile *C.FILE, binoff, res C.int) {
	if !binFileGo {
		return
	}
	file := fileByHandle(cfile)
	bin := binFileByCFile[file]
	if bin.noRaw.write {
		return
	}
	defer func() {
		bin.noRaw.fwrite = false
		bin.assertSkip()
	}()
	buf := unsafe.Slice((*byte)(unsafe.Pointer(cbuf)), int(a2*a3))
	if binFileDebug {
		off, _ := bin.file.Seek(0, io.SeekCurrent)
		wbuf := buf
		if len(wbuf) > 16 {
			wbuf = wbuf[len(wbuf)-16:]
		}
		log.Printf("binfile: write(%s): %s [:%d] (%d * %d) +%d (+%d) %x", bin.flags(), file.Name(), len(buf), int(a2), int(a3), off, bin.Written(), wbuf)
	}
	got := nox_binfile_fwrite_409200_test((*C.char)(unsafe.Pointer(&buf[0])), a2, a3, newFileHandle(bin.file))
	//if res != C.int(got) {
	//	panic(fmt.Errorf("invalid response: %d vs %d (%v)", int(res), int(got), file.err))
	//}
	_ = got
	filesCheckOffsets(file.File, bin.file.File)
	if boff := bin.Written(); boff != int64(binoff) {
		panic(fmt.Errorf("bin offset is different: %d vs %d", boff, int64(binoff)))
	}
}

//export nox_binfile_writeIntAt_409190_hookStart
func nox_binfile_writeIntAt_409190_hookStart(cfile *C.FILE) {
	if !binFileGo {
		return
	}
	file := fileByHandle(cfile)
	bin := binFileByCFile[file]
	bin.assertSkip()
	bin.noRaw.fseek = true
	bin.noRaw.fwrite = true
	bin.setSkip()
}

//export nox_binfile_writeIntAt_409190_hook
func nox_binfile_writeIntAt_409190_hook(cfile *C.FILE, cval, coff C.int) {
	if !binFileGo {
		return
	}
	file := fileByHandle(cfile)
	bin := binFileByCFile[file]
	defer func() {
		bin.noRaw.fseek = false
		bin.noRaw.fwrite = false
		bin.assertSkip()
	}()
	nox_binfile_writeIntAt_409190_test(newFileHandle(bin.file), cval, coff)
	checkEqualContent(fmt.Sprintf("writeIntAt(%s)", bin.flags()), file.File, bin.file.File)
}

func nox_binfile_writeIntAt_409190_test(cfile *C.FILE, cval, coff C.int) {
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
