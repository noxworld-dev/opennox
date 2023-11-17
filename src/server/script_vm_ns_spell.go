package server

import (
	"strings"

	ns4 "github.com/noxworld-dev/noxscript/ns/v4"
	"github.com/noxworld-dev/noxscript/ns/v4/effect"
	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/types"
)

var nsFxNames = make(map[string]noxnet.Op)

func init() {
	for fx := noxnet.MSG_FX_PARTICLEFX; fx <= noxnet.MSG_FX_MANA_BOMB_CANCEL; fx++ {
		nsFxNames[fx.String()] = fx
	}
}

func (s NoxScriptNS) Effect(effect effect.Effect, p1, p2 ns4.Positioner) {
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
		s.s.Nox_xxx_netSendPointFx_522FF0(fx, pos)
	case noxnet.MSG_FX_LIGHTNING,
		noxnet.MSG_FX_ENERGY_BOLT,
		noxnet.MSG_FX_PLASMA,
		noxnet.MSG_FX_DRAIN_MANA,
		noxnet.MSG_FX_CHARM,
		noxnet.MSG_FX_GREATER_HEAL,
		noxnet.MSG_FX_DEATH_RAY,
		noxnet.MSG_FX_SENTRY_RAY:
		s.s.Nox_xxx_netSendRayFx_5232F0(fx, pos.Point(), pos2.Point())
	case noxnet.MSG_FX_SPARK_EXPLOSION:
		s.s.Nox_xxx_netSparkExplosionFx_5231B0(pos, byte(pos2.X))
	case noxnet.MSG_FX_JIGGLE:
		s.s.Nox_xxx_earthquakeSend_4D9110(pos, int(pos2.X))
	case noxnet.MSG_FX_GREEN_BOLT:
		s.s.Nox_xxx_netSendFxGreenBolt_523790(pos.Point(), pos2.Point(), 30)
	case noxnet.MSG_FX_VAMPIRISM:
		s.s.Nox_xxx_netSendVampFx_523270(fx, pos.Point(), pos2.Point(), 100)
	}
}
