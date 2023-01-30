package legacy

/*
#include <stdbool.h>
#include <stdio.h>
*/
import "C"
import (
	"errors"
	"io"
	"os"
	"sync"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/datapath"
	"github.com/noxworld-dev/opennox-lib/ifs"

	"github.com/noxworld-dev/opennox/v1/internal/binfile"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc/handles"
)

var files struct {
	sync.RWMutex
	byHandle map[unsafe.Pointer]*binfile.File
}

type FILE = C.FILE

//export nox_fs_root
func nox_fs_root() *C.char {
	return internCStr(datapath.Data())
}

//export nox_fs_normalize
func nox_fs_normalize(path *C.char) *C.char {
	out := ifs.Normalize(GoString(path))
	return CString(out)
}

//export nox_fs_remove
func nox_fs_remove(path *C.char) C.bool {
	return ifs.Remove(GoString(path)) == nil
}

//export nox_fs_mkdir
func nox_fs_mkdir(path *C.char) C.bool {
	return ifs.Mkdir(GoString(path)) == nil
}

//export nox_fs_set_workdir
func nox_fs_set_workdir(path *C.char) C.bool {
	return ifs.Chdir(GoString(path)) == nil
}

//export nox_fs_copy
func nox_fs_copy(src, dst *C.char) C.bool {
	return ifs.Copy(GoString(src), GoString(dst)) == nil
}

//export nox_fs_move
func nox_fs_move(src, dst *C.char) C.bool {
	return ifs.Rename(GoString(src), GoString(dst)) == nil
}

func convWhence(mode int) int {
	var whence int
	switch C.int(mode) {
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
func nox_fs_fseek(f *FILE, off C.long, mode int) int {
	fp := fileByHandle(f)
	_, err := fp.Seek(int64(off), convWhence(mode))
	if err != nil {
		return -1
	}
	return 0
}

//export nox_fs_ftell
func nox_fs_ftell(f *FILE) C.long {
	fp := fileByHandle(f)
	off, err := fp.Seek(0, io.SeekCurrent)
	if err != nil {
		e := int64(-1)
		return C.long(e)
	}
	return C.long(off)
}

//export nox_fs_fsize
func nox_fs_fsize(f *FILE) C.long {
	fp := fileByHandle(f)
	size, err := fp.Size()
	if err != nil {
		e := int64(-1)
		return C.long(e)
	}
	return C.long(size)
}

//export nox_fs_fread
func nox_fs_fread(f *FILE, dst unsafe.Pointer, sz int) int {
	fp := fileByHandle(f)
	n, _ := fp.Read(unsafe.Slice((*byte)(dst), sz))
	return n
}

//export nox_fs_fwrite
func nox_fs_fwrite(f *FILE, dst unsafe.Pointer, sz int) int {
	fp := fileByHandle(f)
	n, _ := fp.Write(unsafe.Slice((*byte)(dst), sz))
	return n
}

//export nox_fs_fgets
func nox_fs_fgets(f *FILE, dst *C.char, sz int) C.bool {
	fp := fileByHandle(f)
	out, err := fp.ReadString()
	if err != nil && !errors.Is(err, io.EOF) {
		return false
	}
	StrCopy(dst, sz, string(out))
	return C.bool(!errors.Is(err, io.EOF))
}

//export nox_fs_fputs
func nox_fs_fputs(f *FILE, str *C.char) int {
	fp := fileByHandle(f)
	n, err := fp.WriteString(GoString(str))
	if err != nil {
		return -1
	}
	return n
}

//export nox_fs_feof
func nox_fs_feof(f *FILE) C.bool {
	fp := fileByHandle(f)
	return fp.Err == io.EOF
}

func fileByHandle(f *FILE) *binfile.File {
	h := unsafe.Pointer(f)
	handles.AssertValidPtr(h)
	files.RLock()
	fp := files.byHandle[h]
	files.RUnlock()
	return fp
}

//export nox_fs_close
func nox_fs_close(f *FILE) {
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

func Nox_fs_close(f *FILE) {
	nox_fs_close(f)
}

func NewFileHandle(f *binfile.File) *FILE {
	if f.Handle != nil {
		return (*FILE)(f.Handle)
	}
	f.Handle = handles.NewPtr()
	files.Lock()
	defer files.Unlock()
	if files.byHandle == nil {
		files.byHandle = make(map[unsafe.Pointer]*binfile.File)
	}
	files.byHandle[f.Handle] = f
	return (*FILE)(f.Handle)
}

//export nox_fs_access
func nox_fs_access(path *C.char, mode int) int {
	_, err := ifs.Stat(GoString(path))
	if os.IsNotExist(err) {
		return -1
	} else if err != nil {
		return -2
	}
	return 0
}

//export nox_fs_open
func nox_fs_open(path *C.char) *FILE {
	f, err := ifs.Open(GoString(path))
	if err != nil {
		return nil
	}
	return NewFileHandle(binfile.NewFile(f))
}

//export nox_fs_open_text
func nox_fs_open_text(path *C.char) *FILE {
	f, err := ifs.Open(GoString(path))
	if err != nil {
		return nil
	}
	return NewFileHandle(binfile.NewTextFile(f))
}

//export nox_fs_create
func nox_fs_create(path *C.char) *FILE {
	f, err := ifs.Create(GoString(path))
	if err != nil {
		return nil
	}
	return NewFileHandle(binfile.NewFile(f))
}

//export nox_fs_create_text
func nox_fs_create_text(path *C.char) *FILE {
	f, err := ifs.Create(GoString(path))
	if err != nil {
		return nil
	}
	return NewFileHandle(binfile.NewTextFile(f))
}

//export nox_fs_open_rw
func nox_fs_open_rw(path *C.char) *FILE {
	f, err := ifs.OpenFile(GoString(path), os.O_RDWR)
	if err != nil {
		return nil
	}
	return NewFileHandle(binfile.NewFile(f))
}
