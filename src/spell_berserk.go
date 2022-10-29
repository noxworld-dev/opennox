package opennox

/*
#include "defs.h"
void nox_xxx_cancelAllSpells_4FEE90(nox_object_t* a1);
*/
import "C"
import (
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/spell"
)

func nox_xxx_warriorBerserker_53FEB0(u *Unit) {
	if u == nil {
		return
	}
	s := noxServer
	C.nox_xxx_cancelAllSpells_4FEE90(u.CObj())
	if u.HasEnchant(ENCHANT_CONFUSED) {
		u.direction2 = C.ushort(int16(int(u.direction1) + 4*noxRndCounter1.IntClamp(-8, 8)))
	}
	if u.Class().Has(object.ClassPlayer) {
		if ud := u.updateDataPlayer(); ud != nil {
			ud.Field59_0 = 0
		}
	}
	nox_xxx_playerSetState_4FA020(u, 1)
	u.DisableEnchant(ENCHANT_INVISIBLE)
	u.DisableEnchant(ENCHANT_INVULNERABLE)
	nox_xxx_spellCancelDurSpell_4FEB10(spell.SPELL_OVAL_SHIELD, u)
	s.abilities.netAbilReportActive(u, AbilityBerserk, true)
}
