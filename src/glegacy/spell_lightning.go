package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	Nox_xxx_lightningSpellDuration_52FFD0 func(a1 unsafe.Pointer, from, to *server.Object)
)

// nox_xxx_lightningSpellDuration_52FFD0
func nox_xxx_lightningSpellDuration_52FFD0(a1 int32, from, to int32) {
	Nox_xxx_lightningSpellDuration_52FFD0(unsafe.Pointer(uintptr(a1)), asObjectS((*nox_object_t)(unsafe.Pointer(uintptr(from)))), asObjectS((*nox_object_t)(unsafe.Pointer(uintptr(to)))))
}
