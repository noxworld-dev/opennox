package opennox

import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/spell"

	"github.com/noxworld-dev/opennox/v1/server"
)

func nox_xxx_lightningSpellDuration_52FFD0(a1 unsafe.Pointer, from, to *server.Object) {
	p := noxServer.spells.duration.newDur()
	if p == nil {
		return
	}
	src := (*server.DurSpell)(a1)
	p.Target48 = to
	p.Caster16 = from
	p.Spell = uint32(spell.SPELL_CHAIN_LIGHTNING_BOLT)
	p.Sub108 = nil
	p.Sub104 = nil
	p.Prev = nil
	p.Next = src.Sub108
	if sub := src.Sub108; sub != nil {
		sub.Prev = p
	}
	src.Sub108 = p
}
