package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func init() {
	memmap.RegisterBlobData(0x581450, "byte_581450", unsafe.Slice((*byte)(unsafe.Pointer(&byte_581450[0])), int(unsafe.Sizeof(byte_581450))))
	memmap.RegisterBlobData(0x587000, "byte_587000", unsafe.Slice((*byte)(unsafe.Pointer(&byte_587000[0])), int(unsafe.Sizeof(byte_587000))))
	memmap.RegisterBlobData(0x5D4594, "byte_5D4594", unsafe.Slice((*byte)(unsafe.Pointer(&byte_5D4594[0])), int(unsafe.Sizeof(byte_5D4594))))
	memmap.RegisterBlobData(0x8531A0, "byte_8531A0", unsafe.Slice((*byte)(unsafe.Pointer(&byte_8531A0[0])), int(unsafe.Sizeof(byte_8531A0))))
	memmap.RegisterBlobData(0x973CE0, "byte_973CE0", unsafe.Slice((*byte)(unsafe.Pointer(&byte_973CE0[0])), int(unsafe.Sizeof(byte_973CE0))))
	memmap.RegisterBlobData(0x973F18, "byte_973F18", unsafe.Slice((*byte)(unsafe.Pointer(&byte_973F18[0])), int(unsafe.Sizeof(byte_973F18))))
	memmap.RegisterBlobData(0x85B3FC, "byte_85B3FC", unsafe.Slice((*byte)(unsafe.Pointer(&byte_85B3FC[0])), int(unsafe.Sizeof(byte_85B3FC))))
	memmap.RegisterBlobData(0x852978, "byte_852978", unsafe.Slice((*byte)(unsafe.Pointer(&byte_852978[0])), int(unsafe.Sizeof(byte_852978))))
	memmap.RegisterBlobData(0x973A20, "byte_973A20", unsafe.Slice((*byte)(unsafe.Pointer(&byte_973A20[0])), int(unsafe.Sizeof(byte_973A20))))
}
