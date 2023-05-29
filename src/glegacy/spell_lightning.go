package legacy

import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	Nox_xxx_lightningSpellDuration_52FFD0 func(a1 unsafe.Pointer, from, to *server.Object)
)

//export nox_xxx_lightningSpellDuration_52FFD0
func nox_xxx_lightningSpellDuration_52FFD0(a1 unsafe.Pointer, from, to *nox_object_t) {
	Nox_xxx_lightningSpellDuration_52FFD0(a1, asObjectS(from), asObjectS(to))
}
