package cnxz

/*
#include <stdint.h>
#include <stdlib.h>

void* nxz_decompress_new();
void nxz_decompress_free(void* p);
int nxz_decompress(void* p, uint8_t* a2, int* a3, uint8_t* a4, int* a5);

int nxz_compress_file(char* src, char* dst);
*/
import "C"
import (
	"encoding/binary"
	"errors"
	"io"
	"os"
	"runtime/cgo"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/ifs"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

// only works on 32bit
var _ = [1]struct{}{}[unsafe.Sizeof(int(0))-4]

func DecompressFile(src, dst string) error {
	if src == "" {
		return errors.New("empty source path")
	}
	if dst == "" {
		return errors.New("empty destination path")
	}
	r, err := ifs.Open(src)
	if err != nil {
		return err
	}
	defer r.Close()
	fi, err := r.Stat()
	if err != nil {
		return err
	}
	srcSz := int(fi.Size() - 4)
	var buf [4]byte
	_, err = io.ReadFull(r, buf[:4])
	if err != nil {
		return err
	}
	dstSz := int(binary.LittleEndian.Uint32(buf[:]))

	sbuf, sfree := alloc.Make([]byte{}, srcSz)
	defer sfree()
	_, err = io.ReadFull(r, sbuf)
	if err != nil {
		return err
	}

	dbuf, dfree := alloc.Make([]byte{}, dstSz)
	defer dfree()

	sleft := srcSz
	dleft := dstSz

	ptr := C.nxz_decompress_new()
	for sleft > 0 && dleft > 0 {
		if C.nxz_decompress(ptr,
			(*C.uchar)(unsafe.Pointer(&dbuf[dstSz-dleft])), (*C.int)(unsafe.Pointer(&dleft)),
			(*C.uchar)(unsafe.Pointer(&sbuf[srcSz-sleft])), (*C.int)(unsafe.Pointer(&sleft)),
		) == 0 {
			break
		}
	}
	C.nxz_decompress_free(ptr)

	w, err := ifs.Create(dst)
	if err != nil {
		return err
	}
	defer w.Close()
	_, err = w.Write(dbuf)
	return err
}

var (
	testOpen   string
	testCreate string
)

//export nxz_fs_open
func nxz_fs_open(cpath *C.char) unsafe.Pointer {
	path := C.GoString(cpath)
	if path != testOpen {
		panic(path)
	}
	f, err := ifs.Open(path)
	if err != nil {
		return nil
	}
	return unsafe.Pointer(cgo.NewHandle(f))
}

//export nxz_fs_create
func nxz_fs_create(cpath *C.char) unsafe.Pointer {
	path := C.GoString(cpath)
	if path != testCreate {
		panic(path)
	}
	f, err := ifs.Create(path)
	if err != nil {
		return nil
	}
	return unsafe.Pointer(cgo.NewHandle(f))
}

//export nxz_fs_fsize
func nxz_fs_fsize(fd unsafe.Pointer) int {
	f, ok := cgo.Handle(fd).Value().(*os.File)
	if !ok {
		return 0
	}
	fi, err := f.Stat()
	if err != nil {
		return 0
	}
	return int(fi.Size())
}

//export nxz_fs_fwrite
func nxz_fs_fwrite(fd unsafe.Pointer, src unsafe.Pointer, sz int) int {
	f, ok := cgo.Handle(fd).Value().(*os.File)
	if !ok {
		return 0
	}
	buf := unsafe.Slice((*byte)(src), sz)
	n, _ := f.Write(buf)
	return n
}

//export nxz_fs_close
func nxz_fs_close(fd unsafe.Pointer) {
	h := cgo.Handle(fd)
	f, ok := h.Value().(*os.File)
	if !ok {
		return
	}
	f.Close()
	h.Delete()
}

//export nxz_binfile_fread_raw_40ADD0
func nxz_binfile_fread_raw_40ADD0(dst *C.char, sz, cnt uint, fd unsafe.Pointer) int {
	if sz*cnt == 0 {
		return 0
	}
	f, ok := cgo.Handle(fd).Value().(*os.File)
	if !ok {
		return 0
	}
	buf := unsafe.Slice((*byte)(unsafe.Pointer(dst)), sz*cnt)
	n, _ := f.Read(buf)
	if n >= 0 {
		n /= int(sz)
		return n
	}
	return -1
}

//export nxz_getMemAt
func nxz_getMemAt(base, off uint) unsafe.Pointer {
	return memmap.PtrOff(uintptr(base), uintptr(off))
}

//export nxz_getMemU16Ptr
func nxz_getMemU16Ptr(base, off uint) *uint16 {
	return memmap.PtrUint16(uintptr(base), uintptr(off))
}

//export nxz_getMemU32Ptr
func nxz_getMemU32Ptr(base, off uint) *uint32 {
	return memmap.PtrUint32(uintptr(base), uintptr(off))
}

func CompressFile(src, dst string) error {
	c1, c2 := C.CString(src), C.CString(dst)
	defer func() {
		C.free(unsafe.Pointer(c1))
		C.free(unsafe.Pointer(c2))
	}()
	if C.nxz_compress_file(c1, c2) == 0 {
		return errors.New("compression failed")
	}
	return nil
}
