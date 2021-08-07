package main

/*
extern unsigned char byte_581450[23472];
extern unsigned char byte_587000[316820];
extern unsigned char byte_5D4594[2614284];
extern unsigned char byte_8529A0[2048];
extern unsigned char byte_8531A0[1182528];
extern unsigned char byte_973CE0[568];
extern unsigned char byte_973F18[44881];
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
	memmap.RegisterBlobData(0x8531A0, "byte_8531A0", asByteSlice(unsafe.Pointer(&C.byte_8531A0[0]), int(unsafe.Sizeof(C.byte_8531A0))))
	memmap.RegisterBlobData(0x973CE0, "byte_973CE0", asByteSlice(unsafe.Pointer(&C.byte_973CE0[0]), int(unsafe.Sizeof(C.byte_973CE0))))
	memmap.RegisterBlobData(0x973F18, "byte_973F18", asByteSlice(unsafe.Pointer(&C.byte_973F18[0]), int(unsafe.Sizeof(C.byte_973F18))))
}
