package opennox

import (
	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/spell"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/server"
)

type spellBuffConf struct {
	Dur            int    // static duration for the spell
	DurOpt         string // load duration from this gamedata value
	DurOptMulQuest string // use this multiplier in Quest mode
	DurInSec       bool   // base duration is in seconds, not frames
	DurLevelMul    bool   // multiply base duration by spell level
	Once           bool   // only allow this buff to be cast once per target
	Defensive      bool
	Orig           *server.Object
	Offensive      bool
	PointFX        noxnet.Op // play this point effect at the target
}

func castBuffSpell(spellID spell.ID, enc server.EnchantID, lvl int, targ *server.Object, opts spellBuffConf) int {
	s := noxServer
	if targ == nil {
		return 0
	}
	if opts.Once && targ.HasEnchant(enc) {
		return 0
	}
	dur := opts.Dur
	if opts.DurOpt != "" {
		dur = int(s.Balance.Float(opts.DurOpt))
	}
	if opts.DurOptMulQuest != "" && noxflags.HasGame(noxflags.GameModeQuest) {
		dur = int(float64(dur) * s.Balance.Float(opts.DurOptMulQuest))
	}
	if opts.DurInSec {
		dur *= int(s.TickRate())
	}
	if opts.DurLevelMul {
		dur *= lvl
	}
	if opts.Defensive {
		s.spells.duration.CancelOffensiveFor(targ)
	}
	asObjectS(targ).ApplyEnchant(enc, dur, lvl)
	if opts.Orig != nil && opts.Offensive {
		sub_4E7540(opts.Orig, targ)
	}
	if opts.PointFX != 0 {
		nox_xxx_netSendPointFx_522FF0(opts.PointFX, targ.Pos())
	}
	return 1
}
