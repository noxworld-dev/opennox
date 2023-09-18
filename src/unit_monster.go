package opennox

import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/spell"
	"github.com/noxworld-dev/opennox-lib/things"

	"github.com/noxworld-dev/opennox/v1/common/unit/ai"
	"github.com/noxworld-dev/opennox/v1/server"
)

func (u *Unit) monsterCast(spellInd spell.ID, target *server.Object) {
	s := u.getServer()
	ud := u.UpdateDataMonster()
	u.monsterPushAction(ai.DEPENDENCY_UNINTERRUPTABLE)
	sp := s.SpellDefByInd(spellInd)
	if sp.Def.Flags.Has(things.SpellDuration) {
		ts := s.Frame() + uint32(noxRndCounter1.IntClamp(int(s.TickRate()/2), int(2*s.TickRate())))
		u.monsterPushAction(ai.DEPENDENCY_TIME, ts)
		u.monsterPushAction(ai.ACTION_CAST_DURATION_SPELL, uint32(spellInd), 0, target)
	} else {
		u.monsterPushAction(ai.ACTION_CAST_SPELL_ON_OBJECT, uint32(spellInd), 0, target)
	}
	if target.SObj() != u.SObj() && !u.monsterActionIsScheduled(ai.ACTION_FLEE) {
		if !sp.Def.Flags.Has(things.SpellTargeted) { // TODO: looks like the flag name is incorrect
			u.monsterPushAction(ai.ACTION_FACE_OBJECT, target)
			u.monsterPushAction(ai.DEPENDENCY_BLOCKED_LINE_OF_FIRE, target)
		}

		v9 := *(*uint32)(unsafe.Add(ud.Field121, 212))
		u.monsterPushAction(ai.DEPENDENCY_OBJECT_FARTHER_THAN, v9, 0, target)
		u.monsterPushAction(ai.DEPENDENCY_OR)
		pos2 := target.Pos()
		u.monsterPushAction(ai.ACTION_MOVE_TO, pos2.X, pos2.Y, target)
	}
}

func nox_xxx_monsterCast_540A30(cu *server.Object, spellInd int, a3p *server.Object) {
	asUnitS(cu).monsterCast(spell.ID(spellInd), a3p)
}
