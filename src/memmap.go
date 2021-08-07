package main

/*
extern unsigned char byte_581450[23472];
extern unsigned char byte_587000[316820];
extern unsigned char byte_5D4594[2614284];
extern unsigned char byte_8529A0[1230025];
*/
import "C"
import (
	"unsafe"

	"nox/v1/common/memmap"
	_ "nox/v1/common/memmap/nox"
)

func init() {
	memmap.RegisterBlobData(0x581450, "byte_581450", asByteSlice(unsafe.Pointer(&C.byte_581450[0]), int(unsafe.Sizeof(C.byte_581450))))
	memmap.RegisterBlobData(0x587000, "byte_587000", asByteSlice(unsafe.Pointer(&C.byte_587000[0]), int(unsafe.Sizeof(C.byte_587000))))
	memmap.RegisterBlobData(0x5D4594, "byte_5D4594", asByteSlice(unsafe.Pointer(&C.byte_5D4594[0]), int(unsafe.Sizeof(C.byte_5D4594))))
	memmap.RegisterBlobData(0x8529A0, "byte_8529A0", asByteSlice(unsafe.Pointer(&C.byte_8529A0[0]), int(unsafe.Sizeof(C.byte_8529A0))))
}
