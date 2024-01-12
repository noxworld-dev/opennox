package nxz

import (
	"unsafe"
)

type Common struct {
	field0   unsafe.Pointer // 0, 0 (8)
	field4   [32]uint32     // 1, 4
	field132 *[548]byte     // 33, 132
}

func initCommon(c *Common) {
	c.field0 = calloc(1, 0x224)
	memset(c.field0, 0, 0x224)
}

func freeCommon(c *Common) {
	free(c.field0)
	c.field0 = nil
}
