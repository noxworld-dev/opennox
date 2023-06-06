package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/server"
)

func nullsub_22(a1 unsafe.Pointer, a2p, a3p, a4p *server.Object, a5, a6 unsafe.Pointer) {
}
func nullsub_36(a1 unsafe.Pointer, a2p, a3p, a4p *server.Object, a5, a6 unsafe.Pointer) {
}
func nullsub_38(a1 unsafe.Pointer, a2p, a3p, a4p *server.Object, a5, a6 unsafe.Pointer) {
}
func nullsub_39(a1 unsafe.Pointer, a2p, a3p, a4p *server.Object, a5, a6 unsafe.Pointer) {
}
func nullsub_40(m *server.ModifierEff, a2p, a3p, a4p *server.Object, a5, a6 unsafe.Pointer) {
}
func nullsub_41(m *server.ModifierEff, a2p, a3p, a4p *server.Object, a5, a6 unsafe.Pointer) {
}
func nullsub_42(m *server.ModifierEff, a2p, a3p, a4p *server.Object, a5, a6 unsafe.Pointer) {
}
func nullsub_43(a1 unsafe.Pointer, a2 *server.Object) {
}
func nullsub_44(a1 unsafe.Pointer, a2 *server.Object) {
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
	return nox_strman_loadString_40F1D0(*(**byte)(memmap.PtrOff(0x587000, uintptr(v1*20+27344))), nil, internCStr("C:\\NoxPost\\src\\common\\Object\\Modifier.c"), 2087)
}
