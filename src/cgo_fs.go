package nox

/*
#include <stdbool.h>
#include <stdio.h>
*/
import "C"
import (
	"bufio"
	"io"
	"os"
	"sync"
	"unicode"
	"unsafe"

	"nox/v1/common/alloc/handles"
	"nox/v1/common/datapath"
	"nox/v1/common/fs"
)

var files struct {
	sync.RWMutex
	byHandle map[unsafe.Pointer]*File
}

type File struct {
	*os.File
	onRead  func(n int)
	onWrite func(p []byte)
	onSeek  func(off int64, whence int)
	buf     *bufio.Reader
	err     error
	text    bool
}

func (f *File) enableBuffer() {
	if f.buf != nil {
		return
	}
	f.buf = bufio.NewReader(f.File)
}

func (f *File) ScanString() (string, error) {
	f.enableBuffer()
	var out []byte
	for {
		b, err := f.buf.ReadByte()
		if err == io.EOF {
			return string(out), nil
		} else if err != nil {
			return string(out), err
		}
		if unicode.IsSpace(rune(b)) {
			return string(out), nil
		}
		out = append(out, b)
	}
}

func (f *File) Seek(off int64, whence int) (int64, error) {
	if f.buf != nil {
		if whence == io.SeekCurrent {
			off -= int64(f.buf.Buffered())
		}
		f.buf = nil
	}
	n, err := f.File.Seek(off, whence)
	if f.onSeek != nil {
		f.onSeek(off, whence)
	}
	f.err = err
	return n, err
}

func (f *File) Read(p []byte) (int, error) {
	if f.buf != nil {
		n, err := f.buf.Read(p)
		f.err = err
		return n, err
	}
	n, err := f.File.Read(p)
	f.err = err
	if f.onRead != nil {
		f.onRead(len(p))
	}
	return n, err
}

func (f *File) Write(p []byte) (int, error) {
	if f.buf != nil {
		panic("TODO: write on a buffered file")
	}
	n, err := f.File.Write(p)
	f.err = err
	if f.onWrite != nil {
		f.onWrite(p)
	}
	return n, err
}

func (f *File) WriteString(p string) (int, error) {
	if f.buf != nil {
		panic("TODO: write on a buffered file")
	}
	n, err := f.File.WriteString(p)
	f.err = err
	if f.onWrite != nil {
		f.onWrite([]byte(p))
	}
	return n, err
}

func (f *File) Sync() error {
	err := f.File.Sync()
	f.err = err
	return err
}

func (f *File) Close() error {
	if f.buf != nil {
		f.buf = nil
	}
	return f.File.Close()
}

//export nox_fs_root
func nox_fs_root() *C.char {
	return internCStr(datapath.Path())
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

//export nox_fs_remove
func nox_fs_remove(path *C.char) C.bool {
	return fs.Remove(C.GoString(path)) == nil
}

//export nox_fs_mkdir
func nox_fs_mkdir(path *C.char) C.bool {
	return fs.Mkdir(C.GoString(path)) == nil
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

func convWhence(mode C.int) int {
	var whence int
	switch mode {
	case C.SEEK_SET:
		whence = io.SeekStart
	case C.SEEK_CUR:
		whence = io.SeekCurrent
	case C.SEEK_END:
		whence = io.SeekEnd
	default:
		panic("unsupported seek mode")
	}
	return whence
}

//export nox_fs_fseek
func nox_fs_fseek(f *C.FILE, off C.long, mode C.int) C.int {
	fp := fileByHandle(f)
	_, err := fp.Seek(int64(off), convWhence(mode))
	if err != nil {
		return -1
	}
	return 0
}

//export nox_fs_ftell
func nox_fs_ftell(f *C.FILE) C.long {
	fp := fileByHandle(f)
	off, err := fp.Seek(0, io.SeekCurrent)
	if err != nil {
		e := int64(-1)
		return C.long(e)
	}
	return C.long(off)
}

//export nox_fs_fsize
func nox_fs_fsize(f *C.FILE) C.long {
	fp := fileByHandle(f)
	cur, err := fp.Seek(0, io.SeekCurrent)
	if err != nil {
		e := int64(-1)
		return C.long(e)
	}
	size, err := fp.Seek(0, io.SeekEnd)
	if err != nil {
		e := int64(-1)
		return C.long(e)
	}
	_, err = fp.Seek(cur, io.SeekStart)
	if err != nil {
		e := int64(-1)
		return C.long(e)
	}
	return C.long(size)
}

//export nox_fs_fread
func nox_fs_fread(f *C.FILE, dst unsafe.Pointer, sz C.int) C.int {
	fp := fileByHandle(f)
	n, _ := fp.Read(unsafe.Slice((*byte)(dst), int(sz)))
	return C.int(n)
}

//export nox_fs_fwrite
func nox_fs_fwrite(f *C.FILE, dst unsafe.Pointer, sz C.int) C.int {
	fp := fileByHandle(f)
	n, _ := fp.Write(unsafe.Slice((*byte)(dst), int(sz)))
	return C.int(n)
}

//export nox_fs_fgets
func nox_fs_fgets(f *C.FILE, dst *C.char, sz C.int) C.bool {
	fp := fileByHandle(f)
	fp.enableBuffer()
	var (
		out []byte
		end bool
	)
	for {
		b, err := fp.buf.ReadByte()
		fp.err = err
		if err == io.EOF {
			end = true
			break
		} else if err != nil {
			return false
		}
		out = append(out, b)
		if b == '\n' {
			break
		}
	}
	if n := len(out); n >= 2 && out[n-2] == '\r' && out[n-1] == '\n' {
		out[n-2] = '\n'
		out = out[:n-1]
	}
	StrCopy(dst, int(sz), string(out))
	return C.bool(!end)
}

//export nox_fs_fgetc
func nox_fs_fgetc(f *C.FILE) C.int {
	fp := fileByHandle(f)
	fp.enableBuffer()
	b, err := fp.buf.ReadByte()
	fp.err = err
	if err != nil {
		return -1
	}
	return C.int(b)
}

//export nox_fs_fputs
func nox_fs_fputs(f *C.FILE, str *C.char) C.int {
	fp := fileByHandle(f)
	n, err := fp.WriteString(C.GoString(str))
	if err != nil {
		return -1
	}
	return C.int(n)
}

//export nox_fs_fputs_sync
func nox_fs_fputs_sync(f *C.FILE, str *C.char) C.int {
	fp := fileByHandle(f)
	n, err := fp.WriteString(C.GoString(str))
	if err != nil {
		return -1
	}
	err = fp.Sync()
	if err != nil {
		return -1
	}
	return C.int(n)
}

//export nox_fs_fscan_str
func nox_fs_fscan_str(f *C.FILE, str *C.char) C.int {
	fp := fileByHandle(f)
	s, err := fp.ScanString()
	if err != nil {
		return -1
	}
	StrCopy(str, len(s)+1, s)
	return 1
}

//export nox_fs_fscan_skip
func nox_fs_fscan_skip(f *C.FILE) C.int {
	fp := fileByHandle(f)
	_, err := fp.ScanString()
	if err != nil {
		return -1
	}
	return 1
}

//export nox_fs_fscan_char
func nox_fs_fscan_char(f *C.FILE, p *C.char) C.int {
	fp := fileByHandle(f)
	s, err := fp.ScanString()
	if err != nil {
		return -1
	}
	*p = C.char(s[0])
	return 1
}

//export nox_fs_fscan_char2
func nox_fs_fscan_char2(f *C.FILE, p *C.char) C.int {
	fp := fileByHandle(f)
	s, err := fp.ScanString()
	if err != nil {
		return -1
	}
	b := unsafe.Slice((*byte)(unsafe.Pointer(p)), 2)
	b[0] = s[0]
	if len(s) > 1 {
		b[1] = s[1]
	} else {
		b[1] = 0
	}
	return 1
}

//export nox_fs_feof
func nox_fs_feof(f *C.FILE) C.bool {
	fp := fileByHandle(f)
	return fp.err == io.EOF
}

func fileByHandle(f *C.FILE) *File {
	h := unsafe.Pointer(f)
	handles.AssertValidPtr(h)
	files.RLock()
	fp := files.byHandle[h]
	files.RUnlock()
	return fp
}

//export nox_fs_close
func nox_fs_close(f *C.FILE) {
	if f == nil {
		return
	}
	h := unsafe.Pointer(f)
	handles.AssertValidPtr(h)
	files.Lock()
	defer files.Unlock()
	fp := files.byHandle[h]
	if fp != nil {
		_ = fp.Close()
		delete(files.byHandle, h)
	}
}

//export nox_fs_flush
func nox_fs_flush(f *C.FILE) {
	fp := fileByHandle(f)
	_ = fp.Sync()
}

func newFileHandle(f *File) *C.FILE {
	h := handles.NewPtr()
	files.Lock()
	defer files.Unlock()
	if files.byHandle == nil {
		files.byHandle = make(map[unsafe.Pointer]*File)
	}
	files.byHandle[h] = f
	return (*C.FILE)(h)
}

//export nox_fs_open
func nox_fs_open(path *C.char) *C.FILE {
	f, err := fs.Open(C.GoString(path))
	if err != nil {
		return nil
	}
	return newFileHandle(&File{File: f})
}

//export nox_fs_open_text
func nox_fs_open_text(path *C.char) *C.FILE {
	f, err := fs.Open(C.GoString(path))
	if err != nil {
		return nil
	}
	return newFileHandle(&File{File: f, text: true})
}

//export nox_fs_create
func nox_fs_create(path *C.char) *C.FILE {
	f, err := fs.Create(C.GoString(path))
	if err != nil {
		return nil
	}
	return newFileHandle(&File{File: f})
}

//export nox_fs_create_text
func nox_fs_create_text(path *C.char) *C.FILE {
	f, err := fs.Create(C.GoString(path))
	if err != nil {
		return nil
	}
	return newFileHandle(&File{File: f, text: true})
}

//export nox_fs_open_rw
func nox_fs_open_rw(path *C.char) *C.FILE {
	f, err := fs.OpenFile(C.GoString(path), os.O_RDWR)
	if err != nil {
		return nil
	}
	return newFileHandle(&File{File: f})
}

//export nox_fs_create_rw
func nox_fs_create_rw(path *C.char) *C.FILE {
	return nox_fs_create(path)
}

//export nox_fs_append_text
func nox_fs_append_text(path *C.char) *C.FILE {
	f, err := fs.OpenFile(C.GoString(path), os.O_WRONLY|os.O_APPEND)
	if err != nil {
		return nil
	}
	return newFileHandle(&File{File: f, text: true})
}

//export nox_readHiddenCode_4145F0
func nox_readHiddenCode_4145F0(dst *C.char) C.int {
	// this usually reads some hidden code that is then displayed in the legal screen
	return 0
}
