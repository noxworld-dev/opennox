//go:build 386

package nxz

import (
	"encoding/binary"
	"errors"
	"io"
	"math"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/ifs"

	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

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

	enc := NewEncoder()
	cnt := 0
	for i := 0; i < srcSz; i += 500000 {
		v := srcSz - i
		if v > 500000 {
			v = 500000
		}
		cnt += enc.Encode(dbuf[cnt:], sbuf[i:], v)
	}
	enc.Free()

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

var _ = [1]struct{}{}[24-unsafe.Sizeof(Encoder{})]

func memcpy(dst, src unsafe.Pointer, size int) {
	alloc.Memcpy(dst, src, uintptr(size))
}

func abs[T ~int | ~int32 | ~int64](v T) T {
	if v < 0 {
		return -v
	}
	return v
}

func __ROL4__(value uint32, shift int32) uint32 {
	var c uint32 = uint32(shift & 31)
	if c == 0 {
		return value
	}
	return (value << c) | value>>(32-c)
}

type Encoder struct {
	field0  *[bufferSize]byte // 0, 0
	field4  uint32            // 1, 4
	data    encoderData       // 2, 8
	field20 *[bufferSize]byte // 5, 20
}

type encoderData struct {
	tableData                    // 0, 0
	field4    uint32             // 1, 4
	field8    *[tableSize]uint32 // 2, 8
}

func (d *encoderData) init() {
	d.tableData.init()
	d.field4 = 4096
	d.field8, _ = alloc.New([tableSize]uint32{})
	*d.field8 = nxzTable6
}

func (d *encoderData) free() {
	alloc.Free(d.field8)
	d.field8 = nil
	d.tableData.free()
}

func NewEncoder() *Encoder {
	enc, _ := alloc.New(Encoder{})
	enc.field0, _ = alloc.New([bufferSize]byte{})
	enc.field4 = 0
	enc.data.init()
	enc.field20, _ = alloc.New([bufferSize]byte{})
	for i := 0; i < len(enc.field20); i += 2 {
		binary.LittleEndian.PutUint16(enc.field20[i:], math.MaxUint16)
	}
	return enc
}

func (enc *Encoder) Free() {
	if enc == nil {
		return
	}
	alloc.Free(enc.field20)
	enc.field20 = nil
	enc.data.free()
	alloc.Free(enc.field0)
	enc.field0 = nil
	alloc.Free(enc)
}

func (enc *Encoder) Encode(dst, src []byte, sz int) int {
	return int(nxz_compress(unsafe.Pointer(enc), &dst[0], &src[0], int32(sz)))
}
