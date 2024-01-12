package nxz

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

var _ = [1]struct{}{}[152-unsafe.Sizeof(Decompressor{})]

type Decompressor struct {
	buf0     unsafe.Pointer // 0, 0
	field4   uint32         // 1, 4
	field8   Common         // 2, 8
	field144 uint32         // 36, 144
	field148 uint32         // 37, 148
}

func NewDecompressor() *Decompressor {
	dec, _ := alloc.New(Decompressor{})
	if dec == nil {
		return nil
	}
	dec.buf0 = calloc(1, 64*1024)
	dec.field4 = 0
	sub57E8A0(&dec.field8)
	dec.field144 = 0
	dec.field148 = 0
	return dec
}

func sub57E8A0(c *Common) {
	initCommon(c)
	c.field132, _ = alloc.New([548]byte{})
	*c.field132 = nxz_table_3
	c.field4 = nxz_table_4
}

func (dec *Decompressor) Free() {
	if dec == nil {
		return
	}
	freeCommonDec(&dec.field8)
	alloc.FreePtr(dec.buf0)
	dec.buf0 = nil
	alloc.Free(dec)
}

func freeCommonDec(c *Common) {
	alloc.Free(c.field132)
	c.field132 = nil
	freeCommon(c)
}

func (dec *Decompressor) Decompress(a2, a3 []byte, a4, a5 *int32) bool {
	return nxz_decompress(
		unsafe.Pointer(dec),
		(*byte)(unsafe.Pointer(&a2[0])), a4,
		(*byte)(unsafe.Pointer(&a3[0])), a5,
	) != 0
}
