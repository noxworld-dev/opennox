package nxz

import (
	"unsafe"
)

const bufferSize = 64 * 1024

type Common struct {
	field0 unsafe.Pointer // 0, 0 (8)
}

func initCommon(c *Common) {
	c.field0 = calloc(1, 0x224)
	memset(c.field0, 0, 0x224)
}

func freeCommon(c *Common) {
	free(c.field0)
	c.field0 = nil
}
