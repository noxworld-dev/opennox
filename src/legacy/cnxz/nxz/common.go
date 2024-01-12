package nxz

import (
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

const (
	bufferSize = 64 * 1024
	tableSize  = 274
)

type Common struct {
	field0 *[tableSize]int16 // 0, 0 (8)
}

func initCommon(c *Common) {
	c.field0, _ = alloc.New([tableSize]int16{})
}

func freeCommon(c *Common) {
	alloc.Free(c.field0)
	c.field0 = nil
}
