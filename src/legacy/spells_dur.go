package legacy

/*
#include <stdint.h>
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/spell"

	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	Nox_xxx_spellCastedFirst_4FE930  func() *server.DurSpell
	Nox_xxx_spellCastedNext_4FE940   func(a1 *server.DurSpell) *server.DurSpell
	Nox_xxx_spellCastByPlayer_4FEEF0 func()
)

//export nox_xxx_spellCastedFirst_4FE930
func nox_xxx_spellCastedFirst_4FE930() unsafe.Pointer { return Nox_xxx_spellCastedFirst_4FE930().C() }

//export nox_xxx_spellCastedNext_4FE940
func nox_xxx_spellCastedNext_4FE940(a1 unsafe.Pointer) unsafe.Pointer {
	return Nox_xxx_spellCastedNext_4FE940((*server.DurSpell)(a1)).C()
}

//export sub_4FE8A0
func sub_4FE8A0(a1 int) { GetServer().S().Spells.Dur.Sub4FE8A0(a1) }

//export nox_xxx_spellCastByPlayer_4FEEF0
func nox_xxx_spellCastByPlayer_4FEEF0() { Nox_xxx_spellCastByPlayer_4FEEF0() }

//export nox_xxx_spellCancelDurSpell_4FEB10
func nox_xxx_spellCancelDurSpell_4FEB10(a1 int, a2 *nox_object_t) {
	GetServer().S().Spells.Dur.CancelFor(spell.ID(a1), asObjectS(a2))
}

//export sub_4FE980
func sub_4FE980(a1 unsafe.Pointer) { GetServer().S().Spells.Dur.FreeRecursive((*server.DurSpell)(a1)) }

//export sub_4FF310
func sub_4FF310(a1 *nox_object_t) {
	GetServer().S().Spells.Dur.CancelOffensiveFor(asObjectS(a1))
}
