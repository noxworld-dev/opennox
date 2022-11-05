package opennox

/*
#include "GAME3_2.h"
*/
import "C"
import (
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/spell"
	"github.com/noxworld-dev/opennox-lib/things"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/server"
)

type spellMissiles struct {
	s    *Server
	proj map[spell.ID]int // map[spellID]typeID, 0x5D4594, 2489136
}

func (sp *spellMissiles) Init(s *Server) {
	sp.s = s
	sp.proj = make(map[spell.ID]int)
}

func (sp *spellMissiles) Free() {
	sp.proj = nil
}

func (sp *spellMissiles) Cast(spellID spell.ID, a2, owner, caster *Unit, a5 *spellAcceptArg, lvl int) int {
	spl := sp.s.SpellDefByInd(spellID)
	opts := spl.Def.Missiles.Level(lvl)
	typ, ok := sp.proj[spellID]
	if !ok {
		typ = sp.s.ObjectTypeID(opts.Projectile)
		sp.proj[spellID] = typ
	}
	curCnt := owner.countSubOfType(typ)
	var cnt, maxCnt int
	if opts.Count <= 0 {
		// it's intentionally loading this variable twice
		// looks previously there were two separate config values for it
		cnt = int(gamedataFloatInd("MagicMissileCount", lvl-1))
		maxCnt = int(gamedataFloatInd("MagicMissileCount", lvl-1))
	} else {
		cnt, maxCnt = opts.Count, opts.Count
	}
	if curCnt+cnt > maxCnt {
		cnt = maxCnt - curCnt
	}
	if cnt <= 0 {
		nox_xxx_netPriMsgToPlayer_4DA2C0(owner, "mmissile.c:TooManyMissiles", 0)
		return 0
	}
	opts.Count = cnt
	sp.CastCustom(spellID, owner, caster, opts)
	return 1
}

func (sp *spellMissiles) CastCustom(spellID spell.ID, owner, caster *Unit, opts things.MissilesSpell) {
	cpos := caster.Pos()
	cvel := caster.Vel()
	rdist := caster.Shape.Circle.R + opts.Offset
	for i := 0; i < opts.Count; i++ {
		doff := int16(opts.Spread * uint16((i+1)/2))
		if i%2 == 1 {
			doff = -doff
		}
		dir := server.Dir16(nox_xxx_math_roundDirI16(int16(caster.Direction1) + doff))
		dv := dir.Vec()
		p2 := types.Pointf{
			X: cpos.X + cvel.X + rdist*dv.X,
			Y: cpos.Y + cvel.Y + rdist*dv.Y,
		}
		if !MapTraceRay(cpos, p2, MapTraceFlag1|MapTraceFlag3) {
			continue
		}
		msl := sp.s.newObjectByTypeID(opts.Projectile)
		mud := msl.updateDataMissile()
		sp.s.createObjectAt(msl, owner, p2)
		mspeed := float32(noxRndCounter1.FloatClamp(opts.SpeedRndMin, opts.SpeedRndMax) * float64(msl.curSpeed()))
		msl.SpeedCur = mspeed
		msl.setAllDirs(dir)
		msl.VelVec = types.Pointf{
			X: cvel.X + mspeed*dv.X*opts.VelMult,
			Y: cvel.Y + mspeed*dv.Y*opts.VelMult,
		}
		var ppos *types.Pointf
		if caster.Class().Has(object.ClassPlayer) {
			pl := caster.ControllingPlayer()
			ppos = &types.Pointf{
				X: float32(pl.field_2284),
				Y: float32(pl.field_2288),
			}
		}
		targ := nox_xxx_spellFlySearchTarget(ppos, msl, 0x20, opts.SearchDist, 0, owner)
		mud.owner = owner.CObj()
		mud.target = targ.CObj()
		mud.spellID = C.int(spellID)
	}
	aud := sp.s.SpellDefByInd(spellID).GetAudio(0)
	nox_xxx_aud_501960(aud, caster, 0, 0)
}
