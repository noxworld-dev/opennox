package cnxz

/*
#include <stdint.h>
#include <stdlib.h>

void* nxz_decompress_new();
void nxz_decompress_free(void* p);
int nxz_decompress(void* p, uint8_t* a2, int* a3, uint8_t* a4, int* a5);
*/
import "C"
import (
	"encoding/binary"
	"errors"
	"io"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/ifs"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

// only works on 32bit
var _ = [1]struct{}{}[unsafe.Sizeof(int(0))-4]

//export nxz_getMemAt
func nxz_getMemAt(base, off uint) unsafe.Pointer {
	return memmap.PtrOff(uintptr(base), uintptr(off))
}

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
