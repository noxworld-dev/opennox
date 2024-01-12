package nxz

import (
	"encoding/binary"
	"math"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

var _ = [1]struct{}{}[24-unsafe.Sizeof(Encoder{})]

type Encoder struct {
	field0  *[bufferSize]byte // 0, 0
	field4  uint32            // 1, 4
	field8  encoderData       // 2, 8
	field20 *[bufferSize]byte // 5, 20
}

type encoderData struct {
	field0 Common             // 0, 0
	field4 uint32             // 1, 4
	field8 *[tableSize]uint32 // 2, 8
}

func NewEncoder() *Encoder {
	enc, _ := alloc.New(Encoder{})
	enc.field0, _ = alloc.New([bufferSize]byte{})
	enc.field4 = 0
	initEncData(&enc.field8)
	enc.field20, _ = alloc.New([bufferSize]byte{})
	for i := 0; i < len(enc.field20); i += 2 {
		binary.LittleEndian.PutUint16(enc.field20[i:], math.MaxUint16)
	}
	return enc
}

func initEncData(d *encoderData) {
	initCommon(&d.field0)
	d.field4 = 4096
	d.field8, _ = alloc.New([tableSize]uint32{})
	*d.field8 = nxz_table_6
}

func freeEncData(d *encoderData) {
	alloc.Free(d.field8)
	d.field8 = nil
	freeCommon(&d.field0)
}

func (enc *Encoder) Free() {
	if enc == nil {
		return
	}
	alloc.Free(enc.field20)
	enc.field20 = nil
	freeEncData(&enc.field8)
	alloc.Free(enc.field0)
	enc.field0 = nil
	alloc.Free(enc)
}

func (enc *Encoder) Encode(dst, src []byte, sz int) int {
	return int(nxz_compress(unsafe.Pointer(enc), &dst[0], &src[0], int32(sz)))
}
