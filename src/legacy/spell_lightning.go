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
	Nox_xxx_lightningSpellDuration_52FFD0(a1, asObjectS((*server.Object)(from)), asObjectS((*server.Object)(to)))
}
