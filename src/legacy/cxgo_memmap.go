package legacy

import (
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func mem_getU8Ptr(base uintptr, off uint32) *uint8 {
	return (*uint8)(memmap.PtrSizeOff(base, uintptr(off), 1))
}
func mem_getI8Ptr(base uintptr, off uint32) *int8 {
	return (*int8)(memmap.PtrSizeOff(base, uintptr(off), 1))
}
func mem_getU16Ptr(base uintptr, off uint32) *uint16 {
	return (*uint16)(memmap.PtrSizeOff(base, uintptr(off), 2))
}
func mem_getI16Ptr(base uintptr, off uint32) *int16 {
	return (*int16)(memmap.PtrSizeOff(base, uintptr(off), 2))
}
func mem_getU32Ptr(base uintptr, off uint32) *uint32 {
	return (*uint32)(memmap.PtrSizeOff(base, uintptr(off), 4))
}
func mem_getI32Ptr(base uintptr, off uint32) *int32 {
	return (*int32)(memmap.PtrSizeOff(base, uintptr(off), 4))
}
func mem_getU64Ptr(base uintptr, off uint32) *uint64 {
	return (*uint64)(memmap.PtrSizeOff(base, uintptr(off), 8))
}
func mem_getI64Ptr(base uintptr, off uint32) *int64 {
	return (*int64)(memmap.PtrSizeOff(base, uintptr(off), 8))
}
func mem_getFloatPtr(base uintptr, off uint32) *float32 {
	return (*float32)(memmap.PtrSizeOff(base, uintptr(off), 4))
}
func mem_getDoublePtr(base uintptr, off uint32) *float64 {
	return (*float64)(memmap.PtrSizeOff(base, uintptr(off), 8))
}
