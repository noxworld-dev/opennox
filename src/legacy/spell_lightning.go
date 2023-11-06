package legacy

import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/server"
)

//export nox_xxx_lightningSpellDuration_52FFD0
func nox_xxx_lightningSpellDuration_52FFD0(a1 unsafe.Pointer, from, to *nox_object_t) {
	GetServer().S().Spells.Dur.NewLightningSub((*server.DurSpell)(a1), asObjectS(from), asObjectS(to))
}
