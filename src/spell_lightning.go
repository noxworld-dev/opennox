package opennox

import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/spell"
)

//export nox_xxx_lightningSpellDuration_52FFD0
func nox_xxx_lightningSpellDuration_52FFD0(a1 unsafe.Pointer, from, to *nox_object_t) {
	p := noxServer.spells.duration.newDur()
	if p == nil {
		return
	}
	src := (*noxDurSpell)(a1)
	p.obj48 = to
	p.obj16 = from
	p.spell = uint32(spell.SPELL_CHAIN_LIGHTNING_BOLT)
	p.sub108 = nil
	p.sub104 = nil
	p.prev = nil
	p.next = src.sub108
	if sub := src.sub108; sub != nil {
		sub.prev = p
	}
	src.sub108 = p
}
