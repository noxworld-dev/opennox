package main

/*
extern unsigned char byte_581450[23472];
extern unsigned char byte_587000[316820];
extern unsigned char byte_5D4594[3844309];
extern unsigned int mix_dword_980858[3];
*/
import "C"
import (
	"nox/common/memmap"
	_ "nox/common/memmap/nox"
	"unsafe"
)

func init() {
	memmap.RegisterBlobData(0x581450, "byte_581450", asByteSlice(unsafe.Pointer(&C.byte_581450[0]), int(unsafe.Sizeof(C.byte_581450))))
	memmap.RegisterBlobData(0x587000, "byte_587000", asByteSlice(unsafe.Pointer(&C.byte_587000[0]), int(unsafe.Sizeof(C.byte_587000))))
	memmap.RegisterBlobData(0x5D4594, "byte_5D4594", asByteSlice(unsafe.Pointer(&C.byte_5D4594[0]), int(unsafe.Sizeof(C.byte_5D4594))))
	memmap.RegisterBlobData(0x980858, "mix_dword_980858", asByteSlice(unsafe.Pointer(&C.mix_dword_980858[0]), int(unsafe.Sizeof(C.mix_dword_980858))))
}
