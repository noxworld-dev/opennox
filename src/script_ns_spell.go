package opennox

/*
#include "defs.h"

int nox_xxx_spellGrantToPlayer_4FB550(nox_object_t* a1, int a2, int a3, int a4, int a5);
*/
import "C"
import (
	"strings"

	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/script"
	"github.com/noxworld-dev/opennox-lib/script/noxscript/ns"
	"github.com/noxworld-dev/opennox-lib/script/noxscript/ns/effect"
	"github.com/noxworld-dev/opennox-lib/script/noxscript/ns/enchant"
	nsp "github.com/noxworld-dev/opennox-lib/script/noxscript/ns/spell"
	"github.com/noxworld-dev/opennox-lib/spell"
	"github.com/noxworld-dev/opennox-lib/types"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/server"
)

var nsFxNames = make(map[string]noxnet.Op)

func init() {
	for fx := noxnet.MSG_FX_PARTICLEFX; fx <= noxnet.MSG_FX_MANA_BOMB_CANCEL; fx++ {
		nsFxNames[fx.String()] = fx
	}
}

func (s noxScriptNS) Effect(effect effect.Effect, p1, p2 script.Positioner) {
	var pos, pos2 types.Pointf
	if p1 != nil {
		pos = p1.Pos()
	}
	if p2 != nil {
		pos2 = p2.Pos()
	}
	name := "MSG_FX_" + strings.ToUpper(string(effect))
	switch fx := nsFxNames[name]; fx {
	case noxnet.MSG_FX_BLUE_SPARKS,
		noxnet.MSG_FX_YELLOW_SPARKS,
		noxnet.MSG_FX_CYAN_SPARKS,
		noxnet.MSG_FX_VIOLET_SPARKS,
		noxnet.MSG_FX_EXPLOSION,
		noxnet.MSG_FX_LESSER_EXPLOSION,
		noxnet.MSG_FX_COUNTERSPELL_EXPLOSION,
		noxnet.MSG_FX_THIN_EXPLOSION,
		noxnet.MSG_FX_TELEPORT,
		noxnet.MSG_FX_SMOKE_BLAST,
		noxnet.MSG_FX_DAMAGE_POOF,
		noxnet.MSG_FX_RICOCHET,
		noxnet.MSG_FX_WHITE_FLASH,
		noxnet.MSG_FX_TURN_UNDEAD,
		noxnet.MSG_FX_MANA_BOMB_CANCEL:
		nox_xxx_netSendPointFx_522FF0(fx, pos)
	case noxnet.MSG_FX_LIGHTNING,
		noxnet.MSG_FX_ENERGY_BOLT,
		noxnet.MSG_FX_PLASMA,
		noxnet.MSG_FX_DRAIN_MANA,
		noxnet.MSG_FX_CHARM,
		noxnet.MSG_FX_GREATER_HEAL,
		noxnet.MSG_FX_DEATH_RAY,
		noxnet.MSG_FX_SENTRY_RAY:
		nox_xxx_netSendRayFx_5232F0(fx, pos.Point(), pos2.Point())
	case noxnet.MSG_FX_SPARK_EXPLOSION:
		nox_xxx_netSparkExplosionFx_5231B0(pos, byte(pos2.X))
	case noxnet.MSG_FX_JIGGLE:
		nox_xxx_earthquakeSend_4D9110(pos, int(pos2.X))
	case noxnet.MSG_FX_GREEN_BOLT:
		nox_xxx_netSendFxGreenBolt_523790(pos.Point(), pos2.Point(), 30)
	case noxnet.MSG_FX_VAMPIRISM:
		nox_xxx_netSendVampFx_523270(fx, pos.Point(), pos2.Point(), 100)
	}
}

func (s noxScriptNS) CastSpell(name nsp.Spell, source, target script.Positioner) {
	sp := spell.ParseID(string(name))
	if !sp.Valid() {
		return
	}
	if source == nil || target == nil {
		return
	}
	srcH, _ := source.(noxObject)
	targH, _ := target.(noxObject)
	src := toObject(srcH).AsUnit()
	if src != nil && src.Flags().HasAny(object.FlagDestroyed|object.FlagDead) {
		return
	}
	targPos := target.Pos()
	if src == nil {
		nox_xxx_imagCasterUnit_1569664.SetPos(source.Pos())
		src = nox_xxx_imagCasterUnit_1569664
	}
	src.Direction1 = server.DirFromVec(targPos.Sub(src.Pos()))
	s.s.castSpellBy(sp, src, targH, targPos)
}

func (obj nsObj) AwardSpell(name nsp.Spell) bool {
	sp := spell.ParseID(string(name))
	if !sp.Valid() {
		return false
	}
	return C.nox_xxx_spellGrantToPlayer_4FB550(obj.CObj(), C.int(sp), 1, 0, 0) != 0
}

func (obj nsObj) Enchant(enc enchant.Enchant, dt script.Duration) {
	id, ok := server.ParseEnchant(string(enc))
	if !ok {
		return
	}
	s := obj.getServer()
	obj.ApplyEnchant(id, s.AsFrames(dt), 5)
}

func (obj nsObj) EnchantOff(enc enchant.Enchant) {
	e, ok := server.ParseEnchant(string(enc))
	if !ok {
		return
	}
	obj.DisableEnchant(e)
}

func (obj nsObj) TrapSpells(spell1 nsp.Spell, spell2 nsp.Spell, spell3 nsp.Spell) {
	//TODO implement me
	panic("implement me")
}

func (g nsObjGroup) AwardSpell(sp nsp.Spell) {
	spl := spell.ParseID(string(sp))
	if !spl.Valid() {
		return
	}
	g.EachObject(true, func(it ns.Obj) bool {
		// TODO: why it.AwardSpell is different?
		val := 0
		obj := it.(noxObject)
		if noxflags.HasGame(noxflags.GameModeCoop) && it.Class().Has(object.ClassPlayer) && asPlayerS(obj.SObj().UpdateDataPlayer().Player).SpellLvl[spl] == 0 {
			val = 1
		}
		C.nox_xxx_spellGrantToPlayer_4FB550(obj.CObj(), C.int(spl), 1, C.int(val), 0)
		return true
	})
}
