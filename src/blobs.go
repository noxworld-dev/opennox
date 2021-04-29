package main

/*
extern unsigned char byte_581450[23472];
extern unsigned char byte_587000[316820];
extern unsigned char byte_5D4594[3844309];
extern unsigned int mix_dword_980858[3];
typedef unsigned int uintptr_t;
*/
import "C"
import (
	"fmt"
	"unsafe"
)

func Ptr(base, off uintptr) unsafe.Pointer {
	switch base {
	case 0x581450:
		return unsafe.Pointer(&C.byte_581450[off])
	case 0x587000:
		return unsafe.Pointer(&C.byte_587000[off])
	case 0x5D4594:
		return unsafe.Pointer(&C.byte_5D4594[off])
	case 0x980858:
		return unsafe.Pointer(uintptr(unsafe.Pointer(&C.mix_dword_980858[0])) + off)
	}
	panic(fmt.Errorf("Invalid memory access! Requested = %x+%x[???]\n", base, off))
}

func PtrSize(base, off, size uintptr) unsafe.Pointer {
	switch base {
	case 0x581450:
		return unsafe.Pointer(&C.byte_581450[off])
	case 0x587000:
		return unsafe.Pointer(&C.byte_587000[off])
	case 0x5D4594:
		return unsafe.Pointer(&C.byte_5D4594[off])
	case 0x980858:
		return unsafe.Pointer(uintptr(unsafe.Pointer(&C.mix_dword_980858[0])) + off)
	}
	panic(fmt.Errorf("Invalid memory access! Requested = %x+%x[%d]\n", base, off, size))
}

func PtrUint8(base, off uintptr) *byte {
	return (*byte)(PtrSize(base, off, 1))
}

func PtrInt8(base, off uintptr) *int8 {
	return (*int8)(PtrSize(base, off, 1))
}

func PtrUint16(base, off uintptr) *uint16 {
	return (*uint16)(PtrSize(base, off, 2))
}

func PtrInt16(base, off uintptr) *int16 {
	return (*int16)(PtrSize(base, off, 2))
}

func PtrUint32(base, off uintptr) *uint32 {
	return (*uint32)(PtrSize(base, off, 4))
}

func PtrInt32(base, off uintptr) *int32 {
	return (*int32)(PtrSize(base, off, 4))
}

func PtrUint64(base, off uintptr) *uint64 {
	return (*uint64)(PtrSize(base, off, 8))
}

func PtrInt64(base, off uintptr) *int64 {
	return (*int64)(PtrSize(base, off, 8))
}

func PtrFloat32(base, off uintptr) *float32 {
	return (*float32)(PtrSize(base, off, 4))
}

func PtrFloat64(base, off uintptr) *float64 {
	return (*float64)(PtrSize(base, off, 8))
}

func Uint8(base, off uintptr) byte {
	return *(*byte)(PtrSize(base, off, 1))
}

func Int8(base, off uintptr) int8 {
	return *(*int8)(PtrSize(base, off, 1))
}

func Uint16(base, off uintptr) uint16 {
	return *(*uint16)(PtrSize(base, off, 2))
}

func Int16(base, off uintptr) int16 {
	return *(*int16)(PtrSize(base, off, 2))
}

func Uint32(base, off uintptr) uint32 {
	return *(*uint32)(PtrSize(base, off, 4))
}

func Int32(base, off uintptr) int32 {
	return *(*int32)(PtrSize(base, off, 4))
}

func Uint64(base, off uintptr) uint64 {
	return *(*uint64)(PtrSize(base, off, 8))
}

func Int64(base, off uintptr) int64 {
	return *(*int64)(PtrSize(base, off, 8))
}

func Float32(base, off uintptr) float32 {
	return *(*float32)(PtrSize(base, off, 4))
}

func Float64(base, off uintptr) float64 {
	return *(*float64)(PtrSize(base, off, 8))
}
