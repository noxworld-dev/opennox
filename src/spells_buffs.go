package opennox

import (
	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/things"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
)

type spellBuffConf struct {
	Dur            int    // static duration for the spell
	DurOpt         string // load duration from this gamedata value
	DurOptMulQuest string // use this multiplier in Quest mode
	DurFPSMul      bool   // multiply base duration value by server FPS
	DurLevelMul    bool   // multiply base duration by spell level
	Once           bool   // only allow this buff to be cast once per target
	Defensive      bool
	Orig           *Unit
	Offensive      bool
	PointFX        noxnet.Op // play this point effect at the target
}

func castBuffSpell(spellID things.SpellID, enc EnchantID, lvl int, targ *Unit, opts spellBuffConf) int {
	if targ == nil {
		return 0
	}
	if opts.Once && targ.HasEnchant(enc) {
		return 0
	}
	dur := opts.Dur
	if opts.DurOpt != "" {
		dur = int(gamedataFloat(opts.DurOpt))
	}
	if opts.DurOptMulQuest != "" && noxflags.HasGame(noxflags.GameModeQuest) {
		dur = int(float64(dur) * gamedataFloat(opts.DurOptMulQuest))
	}
	if opts.DurFPSMul {
		dur *= int(gameFPS())
	}
	if opts.DurLevelMul {
		dur *= lvl
	}
	if opts.Defensive {
		sub_4FF310(targ)
	}
	targ.ApplyEnchant(enc, dur, lvl)
	if opts.Orig != nil && opts.Offensive {
		sub_4E7540(opts.Orig, targ)
	}
	if opts.PointFX != 0 {
		nox_xxx_netSendPointFx_522FF0(opts.PointFX, targ.Pos())
	}
	return 1
}
