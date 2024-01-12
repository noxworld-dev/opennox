package nxz

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

var _ = [1]struct{}{}[152-unsafe.Sizeof(Decoder{})]

type Decoder struct {
	buf0     *[bufferSize]byte // 0, 0
	field4   uint32            // 1, 4
	data8    decoderData       // 2, 8
	field144 uint32            // 36, 144
	field148 uint32            // 37, 148
}

type decoderData struct {
	field0   Common             // 0, 0 (2, 8)
	field4   [32]uint32         // 1, 4 (3, 12)
	field132 *[tableSize3]int16 // 33, 132 (35, 140)
}

type decoderRec struct {
	ind0 int16
	val2 int16
}

func NewDecoder() *Decoder {
	dec, _ := alloc.New(Decoder{})
	if dec == nil {
		return nil
	}
	dec.buf0, _ = alloc.New([bufferSize]byte{})
	dec.field4 = 0
	initDecData(&dec.data8)
	dec.field144 = 0
	dec.field148 = 0
	return dec
}

func initDecData(d *decoderData) {
	initCommon(&d.field0)
	d.field132, _ = alloc.New([tableSize3]int16{})
	*d.field132 = nxz_table_3
	d.field4 = nxz_table_4
}

func (dec *Decoder) Free() {
	if dec == nil {
		return
	}
	freeDecData(&dec.data8)
	alloc.Free(dec.buf0)
	dec.buf0 = nil
	alloc.Free(dec)
}

func freeDecData(d *decoderData) {
	alloc.Free(d.field132)
	d.field132 = nil
	freeCommon(&d.field0)
}
