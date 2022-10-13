package cnxz

/*
#include <stdint.h>
#include <stdlib.h>

void* nxz_decompress_new();
void nxz_decompress_free(void* p);
int nxz_decompress(void* p, uint8_t* a2, int* a3, uint8_t* a4, int* a5);

void* nxz_compress_new();
void nxz_compress_free(void* p);
int nxz_compress(void* a1p, uint8_t* a2p, uint8_t* a3p, int a4p);
*/
import "C"
import (
	"encoding/binary"
	"errors"
	"io"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/ifs"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
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
	if _, err = io.ReadFull(r, buf[:4]); err != nil {
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
	if _, err = w.Write(dbuf); err != nil {
		return err
	}
	return w.Close()
}

func compBufferSize(sz int) int {
	return sz + sz/2 + 32
}

func CompressFile(src, dst string) error {
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

	srcSz := int(fi.Size())
	sbuf, sfree := alloc.Make([]byte{}, srcSz)
	defer sfree()
	if _, err = io.ReadFull(r, sbuf); err != nil {
		return err
	}

	dbuf, dfree := alloc.Make([]byte{}, compBufferSize(srcSz))
	defer dfree()

	ptr := C.nxz_compress_new()
	cnt := 0
	for i := 0; i < srcSz; i += 500000 {
		v := srcSz - i
		if v > 500000 {
			v = 500000
		}
		cnt += int(C.nxz_compress(ptr,
			(*C.uchar)(unsafe.Pointer(&dbuf[cnt])),
			(*C.uchar)(unsafe.Pointer(&sbuf[i])),
			C.int(v),
		))
	}
	C.nxz_compress_free(ptr)

	w, err := ifs.Create(dst)
	if err != nil {
		return err
	}
	defer w.Close()

	var buf [4]byte
	binary.LittleEndian.PutUint32(buf[:4], uint32(srcSz))
	if _, err := w.Write(buf[:4]); err != nil {
		return err
	}
	if _, err := w.Write(dbuf[:cnt]); err != nil {
		return err
	}
	return w.Close()
}
