package nxz

import (
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
