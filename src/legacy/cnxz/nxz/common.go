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

type commonData struct {
	field0 *[tableSize]int16 // 0, 0 (8)
}

func initCommon(c *commonData) {
	c.field0, _ = alloc.New([tableSize]int16{})
}

func freeCommon(c *commonData) {
	alloc.Free(c.field0)
	c.field0 = nil
}
