package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func nullsub_22() {
}
func nullsub_36() {
}
func nullsub_38() {
}
func nullsub_39() {
}
func nullsub_40() {
}
func nullsub_41() {
}
func nullsub_42() {
}
func nullsub_43() {
}
func nullsub_44() {
}
func sub_413480(a1 int8) *wchar2_t {
	var (
		v1 int32
		v2 *uint8
	)
	v1 = 0
	v2 = (*uint8)(memmap.PtrOff(0x587000, 27332))
	for int32(a1) != int32(*v2) {
		v2 = (*uint8)(unsafe.Add(unsafe.Pointer(v2), 20))
		v1++
		if int32(uintptr(unsafe.Pointer(v2))) >= int32(uintptr(memmap.PtrOff(0x587000, 27452))) {
			return nil
		}
	}
	return nox_strman_loadString_40F1D0(*(**byte)(memmap.PtrOff(0x587000, uint32(v1*20+27344))), nil, internCStr("C:\\NoxPost\\src\\common\\Object\\Modifier.c"), 2087)
}
