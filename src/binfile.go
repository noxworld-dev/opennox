package nox

/*
#include <stdbool.h>
#include <stdio.h>
*/
import "C"
import (
	"bytes"
	"encoding/hex"
	"fmt"
	"io"
	"os"
	"runtime/debug"
	"strings"
	"unsafe"

	"nox/v1/common/crypt"
	"nox/v1/common/fs"
	"nox/v1/common/log"
)

var (
	binFileData  = make(map[*File]*Binfile)
	binFileTmp   = make(map[string]string)
	binFileDebug = os.Getenv("NOX_DEBUG_BINFILE") == "true"
	binFileGo    = os.Getenv("NOX_BINFILE_GO") == "true"
)

type Binfile struct {
	Path      string
	File      *File
	Key       int
	noRaw     bool
	noRawFrom string
	write     struct {
		File   *os.File
		Writer *crypt.Writer
	}
	read struct {
		File   *os.File
		Reader *crypt.Reader
	}
	full struct {
		File *os.File
		Full *crypt.File
	}
}

func (f *Binfile) flags() string {
	if f.read.File != nil {
		return "R"
	} else if f.write.File != nil {
		return "W"
	} else if f.full.File != nil {
		return "RW"
	}
	return ""
}

func (f *Binfile) IgnoreRaw(ignore bool) {
	f.noRaw = ignore
	if ignore {
		f.noRawFrom = caller(1)
	} else {
		f.noRawFrom = ""
	}
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

//export nox_binfile_open_408CC0_hook
func nox_binfile_open_408CC0_hook(cpath *C.char, cmode C.int, cfile *C.FILE) {
	if !binFileGo {
		return
	}
	path := GoString(cpath)
	file := fileByHandle(cfile)
	bin := &Binfile{
		Path: path, File: file,
	}
	binFileData[file] = bin
	switch cmode {
	case 0:
		f, err := fs.Open(file.Name())
		if err != nil {
			panic(err)
		}
		bin.read.File = f
		if binFileDebug {
			log.Printf("binfile: open(R): %q", path)
		}
	case 1:
		file.onWrite = func(p []byte) {
			if bin.noRaw {
				if binFileDebug {
					log.Printf("binfile: SKIP write(W,raw): %q [:%d]", path, len(p))
				}
				return
			}
			if binFileDebug {
				log.Printf("binfile: write(W,raw): %q [:%d]", path, len(p))
			}
			bin.write.File.Write(p)
			filesCheckOffsets(file.File, bin.write.File)
		}
		file.onSeek = func(off int64, whence int) {
			if bin.noRaw {
				if binFileDebug {
					log.Printf("binfile: SKIP seek(W,raw): %q (%d, %d)", path, off, whence)
				}
				return
			}
			if binFileDebug {
				log.Printf("binfile: seek(W,raw): %q (%d, %d)", path, off, whence)
			}
			bin.write.File.Seek(off, whence)
			if whence != io.SeekCurrent {
				checkEqualContent(fmt.Sprintf("seek(%s)", bin.flags()), bin.File.File, bin.write.File)
			} else {
				filesCheckOffsets(file.File, bin.write.File)
			}
		}
		f, err := os.CreateTemp("", "opennox-binfile-")
		if err != nil {
			panic(err)
		}
		bin.write.File = f
		binFileTmp[file.Name()] = f.Name()
		if binFileDebug {
			log.Printf("binfile: open(W): %q", path)
		}
	case 2:
		file.onRead = func(n int) {
			if bin.noRaw {
				if binFileDebug {
					log.Printf("binfile: SKIP read(RW,raw): %q [:%d]", path, n)
				}
				return
			}
			if binFileDebug {
				log.Printf("binfile: read(RW,raw): %q [:%d]", path, n)
			}
			buf := make([]byte, n)
			bin.full.File.Read(buf)
			filesCheckOffsets(file.File, bin.full.File)
		}
		file.onWrite = func(p []byte) {
			if bin.noRaw {
				if binFileDebug {
					log.Printf("binfile: SKIP write(W,raw): %q [:%d]", path, len(p))
				}
				return
			}
			if binFileDebug {
				log.Printf("binfile: write(RW,raw): %q [:%d]", path, len(p))
			}
			bin.full.File.Write(p)
			filesCheckOffsets(file.File, bin.full.File)
		}
		file.onSeek = func(off int64, whence int) {
			if bin.noRaw {
				if binFileDebug {
					log.Printf("binfile: SKIP seek(W,raw): %q (%d, %d)", path, off, whence)
				}
				return
			}
			if binFileDebug {
				log.Printf("binfile: seek(RW,raw): %q (%d, %d)", path, off, whence)
			}
			bin.full.File.Seek(off, whence)
			if whence != io.SeekCurrent {
				checkEqualContent(fmt.Sprintf("seek(%s)", bin.flags()), bin.File.File, bin.full.File)
			} else {
				filesCheckOffsets(file.File, bin.full.File)
			}
		}
		var (
			f   *os.File
			err error
		)
		if name, ok := binFileTmp[file.Name()]; ok {
			f, err = os.OpenFile(name, os.O_RDWR, 0644)
			if binFileDebug {
				fi, _ := f.Stat()
				log.Printf("binfile: open(RW): %q, %d", path, fi.Size())
			}
		} else {
			f, err = os.CreateTemp("", "opennox-binfile-")
			binFileTmp[file.Name()] = f.Name()
			if binFileDebug {
				log.Printf("binfile: open(RW, new): %q", path)
			}
		}
		if err != nil {
			panic(err)
		}
		bin.full.File = f
		filesCheckOffsets(file.File, bin.full.File)
	default:
		panic(cmode)
	}
}

//export nox_binfile_close_408D90_hookStart
func nox_binfile_close_408D90_hookStart(cfile *C.FILE) {
	if !binFileGo {
		return
	}
	file := fileByHandle(cfile)
	bin := binFileData[file]
	bin.IgnoreRaw(true)
	if bin.read.File != nil {
		filesCheckOffsets(file.File, bin.read.File)
	} else if bin.write.File != nil {
		filesCheckOffsets(file.File, bin.write.File)
	} else if bin.full.File != nil {
		filesCheckOffsets(file.File, bin.full.File)
	}
}

//export nox_binfile_close_408D90_hook
func nox_binfile_close_408D90_hook(cfile *C.FILE) {
	if !binFileGo {
		return
	}
	file := fileByHandle(cfile)
	bin := binFileData[file]
	delete(binFileData, file)
	if bin.read.File != nil {
		if binFileDebug {
			log.Printf("binfile: close(R): %q", bin.Path)
		}
		bin.read.File.Close()
		bin.read.Reader = nil
	}
	if bin.write.File != nil {
		if binFileDebug {
			log.Printf("binfile: close(W): %q", bin.Path)
		}
		if bin.write.Writer != nil {
			bin.write.Writer.Close()
			bin.write.Writer = nil
		}
		f, err := fs.Open(bin.File.Name())
		if err != nil {
			panic(err)
		}
		defer f.Close()
		buf, err := io.ReadAll(f)
		if err != nil {
			panic(err)
		}
		_, err = bin.write.File.Seek(0, io.SeekStart)
		if err != nil {
			panic(err)
		}
		buf2, err := io.ReadAll(bin.write.File)
		if err != nil {
			panic(err)
		}
		checkEqualBytes(fmt.Sprintf("close(%s)", bin.flags()), f.Name(), bin.write.File.Name(), buf, buf2)
		bin.write.File.Close()
	}
	if bin.full.File != nil {
		if binFileDebug {
			log.Printf("binfile: close(RW): %q", bin.Path)
		}
		if bin.full.Full != nil {
			bin.full.Full.Close()
			bin.full.Full = nil
		}
		f, err := fs.Open(bin.File.Name())
		if err != nil {
			panic(err)
		}
		defer f.Close()
		buf, err := io.ReadAll(f)
		if err != nil {
			panic(err)
		}
		_, err = bin.full.File.Seek(0, io.SeekStart)
		if err != nil {
			panic(err)
		}
		buf2, err := io.ReadAll(bin.full.File)
		if err != nil {
			panic(err)
		}
		checkEqualBytes(fmt.Sprintf("close(%s)", bin.flags()), f.Name(), bin.full.File.Name(), buf, buf2)
		bin.full.File.Close()
	}
}

//export nox_binfile_fread_408E40_hookStart
func nox_binfile_fread_408E40_hookStart(cfile *C.FILE) {
	if !binFileGo {
		return
	}
	file := fileByHandle(cfile)
	bin := binFileData[file]
	if bin != nil {
		bin.IgnoreRaw(true)
		if bin.read.File != nil {
			filesCheckOffsets(file.File, bin.read.File)
		} else if bin.write.File != nil {
			panic("read on writer")
		} else if bin.full.File != nil {
			filesCheckOffsets(file.File, bin.full.File)
		}
	}
}

//export nox_binfile_cryptSet_408D40_hook
func nox_binfile_cryptSet_408D40_hook(cfile *C.FILE, ckey C.int) {
	if !binFileGo {
		return
	}
	file := fileByHandle(cfile)
	bin := binFileData[file]
	bin.Key = int(ckey)
	if binFileDebug {
		log.Printf("binfile: key(%s): %s, %d", bin.flags(), bin.Path, bin.Key)
	}
	if bin.read.File != nil {
		if bin.Key < 0 {
			bin.read.Reader = nil
		} else {
			cr, err := crypt.NewReader(bin.read.File, bin.Key)
			if err != nil {
				panic(err)
			}
			bin.read.Reader = cr
		}
	}
	if bin.write.File != nil {
		if bin.Key < 0 {
			bin.write.Writer = nil
		} else {
			cw, err := crypt.NewWriter(bin.write.File, bin.Key)
			if err != nil {
				panic(err)
			}
			bin.write.Writer = cw
		}
	}
	if bin.full.File != nil {
		if bin.Key < 0 {
			bin.full.Full = nil
		} else {
			cf, err := crypt.NewFile(bin.full.File, bin.Key)
			if err != nil {
				panic(err)
			}
			bin.full.Full = cf
		}
	}
}

//export nox_binfile_fread_408E40_hook
func nox_binfile_fread_408E40_hook(cbuf *C.char, a2, a3 C.int, cfile *C.FILE, res C.int) C.bool {
	if !binFileGo {
		return true
	}
	file := fileByHandle(cfile)
	bin := binFileData[file]
	bin.IgnoreRaw(false)
	buf := unsafe.Slice((*byte)(unsafe.Pointer(cbuf)), int(a2*a3))
	buf = buf[:int(a2*res)]
	if binFileDebug {
		if len(buf) != cap(buf) {
			log.Printf("binfile: read(%s): %s [:%d:%d]", bin.flags(), bin.Path, len(buf), cap(buf))
		} else {
			log.Printf("binfile: read(%s): %s [:%d]", bin.flags(), bin.Path, len(buf))
		}
	}
	var (
		rd    io.Reader
		name2 string
	)
	if bin.read.Reader != nil {
		rd = bin.read.Reader
		name2 = bin.read.File.Name()
	} else if bin.read.File != nil {
		rd = bin.read.File
		name2 = bin.read.File.Name()
	} else if bin.full.Full != nil {
		rd = bin.full.Full
		name2 = bin.full.File.Name()
	} else if bin.full.File != nil {
		rd = bin.full.File
		name2 = bin.full.File.Name()
	}
	if rd != nil {
		buf2 := make([]byte, cap(buf))
		n, err := rd.Read(buf2)
		if err == io.EOF {
			err = nil
		}
		if err != nil {
			panic(err)
		}
		buf2 = buf2[:n]
		checkEqualBytes(fmt.Sprintf("read(%s)", bin.flags()), file.Name(), name2, buf, buf2)
	}
	return true
}

//export nox_binfile_fread_raw_40ADD0_hook
func nox_binfile_fread_raw_40ADD0_hook(a2, a3 C.int, cfile *C.FILE) C.bool {
	if !binFileGo {
		return true
	}
	file := fileByHandle(cfile)
	bin := binFileData[file]
	if bin == nil || bin.noRaw {
		return true
	}
	size := int(a2 * a3)
	off, _ := file.File.Seek(0, io.SeekCurrent)
	if binFileDebug {
		if bin == nil {
			log.Printf("binfile: read(raw, no init): %s [:%d], +%d", file.Name(), size, off)
		} else {
			log.Printf("binfile: read(%s,raw): %s [:%d], +%d", bin.flags(), bin.Path, size, off)
		}
	}
	if bin == nil {
		return true
	}
	var rs *os.File
	if bin.read.File != nil {
		rs = bin.read.File
	} else if bin.full.File != nil {
		rs = bin.full.File
	}
	if rs != nil {
		off2, err := rs.Seek(0, io.SeekCurrent)
		if err != nil {
			panic(err)
		} else if off != off2 {
			panic(fmt.Errorf("different offsets: %d vs %d", off, off2))
		}
		buf := make([]byte, size)
		_, err = io.ReadFull(file.File, buf)
		if err != nil {
			panic(err)
		}
		_, err = file.File.Seek(off, io.SeekStart)
		if err != nil {
			panic(err)
		}

		buf2 := make([]byte, size)
		_, err = io.ReadFull(rs, buf2)
		if err != nil {
			panic(err)
		}
		checkEqualBytes(fmt.Sprintf("read(%s,raw)", bin.flags()), file.Name(), rs.Name(), buf, buf2)
		_, err = rs.Seek(off2, io.SeekStart)
		if err != nil {
			panic(err)
		}
	}
	return true
}

//export nox_binfile_fseek_409050_hookStart
func nox_binfile_fseek_409050_hookStart(cfile *C.FILE) {
	if !binFileGo {
		return
	}
	file := fileByHandle(cfile)
	bin := binFileData[file]
	bin.IgnoreRaw(true)
	if bin.read.File != nil {
		filesCheckOffsets(file.File, bin.read.File)
	} else if bin.write.File != nil {
		panic("seek on writer")
	} else if bin.full.File != nil {
		filesCheckOffsets(file.File, bin.full.File)
	}
}

//export nox_binfile_fseek_409050_hook
func nox_binfile_fseek_409050_hook(cfile *C.FILE, coff, cwhence C.int) C.bool {
	if !binFileGo {
		return true
	}
	file := fileByHandle(cfile)
	bin := binFileData[file]
	bin.IgnoreRaw(false)
	off, _ := file.File.Seek(0, io.SeekCurrent)
	if binFileDebug {
		log.Printf("binfile: seek(%s): %s, +%d = (%d, %d)", bin.flags(), bin.Path, off, coff, cwhence)
	}
	var (
		sk    io.Seeker
		file2 *os.File
	)
	if bin.read.Reader != nil {
		sk = bin.read.Reader
		file2 = bin.read.File
	} else if bin.write.Writer != nil {
		panic("seek on writer")
	} else if bin.full.Full != nil {
		sk = bin.full.Full
		file2 = bin.full.File
	}
	if sk != nil {
		off1, whence := int64(coff), convWhence(cwhence)
		if bin.read.Reader == nil {
			// this is what nox_binfile_fseek_409050 does for some reason
			if off1 != 0 {
				return true
			}
			// same, for some reason it resets the writer to the end
			whence = io.SeekEnd
		}
		_, err := sk.Seek(off1, whence)
		if err == io.EOF {
			err = nil
		}
		if err != nil {
			panic(err)
		}
		off2, err := file2.Seek(0, io.SeekCurrent)
		if err != nil {
			panic(err)
		}
		if off != off2 {
			panic(fmt.Errorf("different offsets: %d vs %d", off, off2))
		}
	}
	return true
}

//export nox_binfile_fflush_409110_hookStart
func nox_binfile_fflush_409110_hookStart(cfile *C.FILE) {
	if !binFileGo {
		return
	}
	file := fileByHandle(cfile)
	bin := binFileData[file]
	bin.IgnoreRaw(true)
	if bin.read.File != nil {
		filesCheckOffsets(file.File, bin.read.File)
	} else if bin.write.File != nil {
		filesCheckOffsets(file.File, bin.write.File)
	} else if bin.full.File != nil {
		filesCheckOffsets(file.File, bin.full.File)
	}
}

//export nox_binfile_fflush_409110_hook
func nox_binfile_fflush_409110_hook(cfile *C.FILE) (out C.bool) {
	if !binFileGo {
		return true
	}
	file := fileByHandle(cfile)
	bin := binFileData[file]
	bin.IgnoreRaw(false)
	defer func() {
		if r := recover(); r != nil {
			log.Printf("binfile: flush(%s): %v", bin.flags(), r)
			debug.PrintStack()
			out = false
		}
	}()
	off, err := file.File.Seek(0, io.SeekCurrent)
	if err != nil {
		panic(err)
	}
	if binFileDebug {
		log.Printf("binfile: flush(%s): %s, +%d", bin.flags(), bin.Path, off)
	}
	var file2 *os.File
	if bin.write.Writer != nil {
		file2 = bin.write.File
		err = bin.write.Writer.Flush()
	} else if bin.full.Full != nil {
		file2 = bin.full.File
		err = bin.full.Full.Flush()
	}
	if err != nil {
		panic(err)
	}
	if file2 == nil {
		return true
	}
	_, err = file2.Write(make([]byte, 8))
	if err != nil {
		panic(err)
	}
	off2, err := file2.Seek(0, io.SeekCurrent)
	if err != nil {
		panic(err)
	}
	if off != off2 {
		panic(fmt.Errorf("different offsets (%s): %d vs %d", bin.flags(), off, off2))
	}
	f, err := fs.Open(bin.File.Name())
	if err != nil {
		panic(err)
	}
	defer f.Close()
	buf, err := io.ReadAll(f)
	if err != nil {
		panic(err)
	}
	_, err = file2.Seek(0, io.SeekStart)
	if err != nil {
		panic(err)
	}
	buf2, err := io.ReadAll(file2)
	if err != nil {
		panic(err)
	}
	_, err = file2.Seek(off2, io.SeekStart)
	if err != nil {
		panic(err)
	}
	checkEqualBytes(fmt.Sprintf("flush(%s)", bin.flags()), f.Name(), file2.Name(), buf, buf2)
	return true
}

//export nox_binfile_fwrite_409200_hookStart
func nox_binfile_fwrite_409200_hookStart(cfile *C.FILE) {
	if !binFileGo {
		return
	}
	file := fileByHandle(cfile)
	bin := binFileData[file]
	bin.IgnoreRaw(true)
	if bin.read.File != nil {
		panic("write on reader")
	} else if bin.write.File != nil {
		filesCheckOffsets(file.File, bin.write.File)
	} else if bin.full.File != nil {
		filesCheckOffsets(file.File, bin.full.File)
	}
}

//export nox_binfile_fwrite_409200_hook
func nox_binfile_fwrite_409200_hook(cbuf *C.char, a2, a3 C.int, cfile *C.FILE, res C.int) {
	if !binFileGo {
		return
	}
	file := fileByHandle(cfile)
	bin := binFileData[file]
	bin.IgnoreRaw(false)
	buf := unsafe.Slice((*byte)(unsafe.Pointer(cbuf)), int(a2*a3))
	if binFileDebug {
		off, _ := file.File.Seek(0, io.SeekCurrent)
		log.Printf("binfile: write(%s): %s [:%d] +%d", bin.flags(), bin.Path, len(buf), off)
	}
	var w io.Writer
	if bin.write.Writer != nil {
		w = bin.write.Writer
	} else if bin.write.File != nil {
		w = bin.write.File
	} else if bin.full.Full != nil {
		w = bin.full.Full
	} else if bin.full.File != nil {
		w = bin.full.File
	}
	if w != nil {
		_, err := w.Write(buf)
		if err != nil {
			panic(err)
		}
	}
}
