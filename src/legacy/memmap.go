package legacy

/*
extern unsigned char byte_581450[23472];
extern unsigned char byte_587000[316820];
extern unsigned char byte_5D4594[2598284];
extern unsigned char byte_973CE0[568];
extern unsigned char byte_973F18[44881];
extern unsigned char byte_85B3FC[1029636];
extern unsigned char byte_852978[40];
extern unsigned char byte_973A20[704];
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func init() {
	memmap.RegisterBlobData(0x581450, "byte_581450", unsafe.Slice((*byte)(unsafe.Pointer(&C.byte_581450[0])), int(unsafe.Sizeof(C.byte_581450))))
	memmap.RegisterBlobData(0x587000, "byte_587000", unsafe.Slice((*byte)(unsafe.Pointer(&C.byte_587000[0])), int(unsafe.Sizeof(C.byte_587000))))
	memmap.RegisterBlobData(0x5D4594, "byte_5D4594", unsafe.Slice((*byte)(unsafe.Pointer(&C.byte_5D4594[0])), int(unsafe.Sizeof(C.byte_5D4594))))
	memmap.RegisterBlobData(0x973CE0, "byte_973CE0", unsafe.Slice((*byte)(unsafe.Pointer(&C.byte_973CE0[0])), int(unsafe.Sizeof(C.byte_973CE0))))
	memmap.RegisterBlobData(0x973F18, "byte_973F18", unsafe.Slice((*byte)(unsafe.Pointer(&C.byte_973F18[0])), int(unsafe.Sizeof(C.byte_973F18))))
	memmap.RegisterBlobData(0x85B3FC, "byte_85B3FC", unsafe.Slice((*byte)(unsafe.Pointer(&C.byte_85B3FC[0])), int(unsafe.Sizeof(C.byte_85B3FC))))
	memmap.RegisterBlobData(0x852978, "byte_852978", unsafe.Slice((*byte)(unsafe.Pointer(&C.byte_852978[0])), int(unsafe.Sizeof(C.byte_852978))))
	memmap.RegisterBlobData(0x973A20, "byte_973A20", unsafe.Slice((*byte)(unsafe.Pointer(&C.byte_973A20[0])), int(unsafe.Sizeof(C.byte_973A20))))
}
