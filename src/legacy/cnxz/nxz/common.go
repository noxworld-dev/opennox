package nxz

import (
	"math"
	"math/bits"

	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

const (
	bufferSize = 64 * 1024
	tableSize  = 274
	uintSize   = bits.UintSize
)

type tableData struct {
	table *[tableSize]int16 // 0, 0 (8)
}

func (d *tableData) init() {
	d.table, _ = alloc.New([tableSize]int16{})
}

func (d *tableData) free() {
	alloc.Free(d.table)
	d.table = nil
}

func newBitReader(r func() (byte, bool)) *bitReader {
	return &bitReader{readByte: r}
}

type bitReader struct {
	readByte func() (byte, bool)
	buf      uint
	cnt      int
}

func (r *bitReader) Reset() {
	r.cnt = 0
}

func (r *bitReader) ReadBits(n int) uint {
	for r.cnt < n {
		b, ok := r.readByte()
		if !ok {
			r.cnt = 0
			return math.MaxUint
		}
		r.buf |= uint(b) << (uintSize - 8 - r.cnt)
		r.cnt += 8
	}
	val := r.buf >> (uintSize - n)
	r.buf <<= n
	r.cnt -= n
	return val
}
