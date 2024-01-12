package nxz

import (
	"unsafe"
)

func sub57DD90(this *uint32) *uint32 {
	v1 := this
	v2 := calloc(1, 0x224)
	*v1 = uint32(uintptr(v2))
	memset(v2, 0, 0x224)
	return v1
}
func sub57DDC0(this *unsafe.Pointer) {
	free(*this)
}
