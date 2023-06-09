package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	Nox_xxx_spellCastedFirst_4FE930    func() unsafe.Pointer
	Nox_xxx_spellCastedNext_4FE940     func(a1 unsafe.Pointer) unsafe.Pointer
	Sub_4FE8A0                         func(a1 int)
	Sub_4FE900                         func(a1 unsafe.Pointer)
	Nox_xxx_spellCastByPlayer_4FEEF0   func()
	Nox_xxx_spellCancelDurSpell_4FEB10 func(a1 int, a2 *server.Object)
	Sub_4FE980                         func(a1 unsafe.Pointer)
	Sub_4FF310                         func(a1 *server.Object)
)

// nox_xxx_spellCastedFirst_4FE930
func nox_xxx_spellCastedFirst_4FE930() unsafe.Pointer { return Nox_xxx_spellCastedFirst_4FE930() }

// nox_xxx_spellCastedNext_4FE940
func nox_xxx_spellCastedNext_4FE940(a1 unsafe.Pointer) unsafe.Pointer {
	return Nox_xxx_spellCastedNext_4FE940(a1)
}

// sub_4FE8A0
func sub_4FE8A0(a1 int32) { Sub_4FE8A0(int(a1)) }

// sub_4FE900
func sub_4FE900(a1 unsafe.Pointer) { Sub_4FE900(a1) }

// nox_xxx_spellCastByPlayer_4FEEF0
func nox_xxx_spellCastByPlayer_4FEEF0() { Nox_xxx_spellCastByPlayer_4FEEF0() }

// nox_xxx_spellCancelDurSpell_4FEB10
func nox_xxx_spellCancelDurSpell_4FEB10(a1 int, a2 *server.Object) {
	Nox_xxx_spellCancelDurSpell_4FEB10(a1, asObjectS(a2))
}

// sub_4FE980
func sub_4FE980(a1 unsafe.Pointer) { Sub_4FE980(a1) }

// sub_4FF310
func sub_4FF310(a1 *server.Object) { Sub_4FF310(asObjectS(a1)) }
func Nox_xxx_spellCancelSpellDo_4FE9D0(a1 unsafe.Pointer) {
	nox_xxx_spellCancelSpellDo_4FE9D0(a1)
}
