package opennox

import (
	"github.com/noxworld-dev/opennox-lib/object"

	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/server"
)

func nox_xxx_updateDeathBall_53D080(obj *server.Object) {
	sobj := asObjectS(obj)
	s := sobj.getServer()
	df := s.Frame() - obj.Field32
	if s.Frame()%(s.TickRate()/3) != 0 {
		found := false
		r := float32(s.Balance.Float("DeathBallCancelRange"))
		s.Map.EachMissilesInCircle(obj.PosVec, r, func(it *server.Object) bool {
			if it == obj {
				return true
			}
			if int(it.TypeInd) != s.Types.DeathBallID() {
				return true
			}
			if !s.MapTraceVision(obj, it) {
				return true
			}
			found = true
			if !it.Flags().Has(object.FlagDestroyed) {
				s.Nox_xxx_netSendFxGreenBolt_523790(obj.PosVec.Point(), it.PosVec.Point(), 10)
				legacy.Nox_xxx_sMakeScorch_537AF0(it.PosVec, 1)
				asObjectS(it).Delete()
			}
			return true
		})
		if found {
			legacy.Nox_xxx_sMakeScorch_537AF0(obj.PosVec, 1)
			sobj.Delete()
		}
	}
	if df > 10 {
		r1 := float32(s.Balance.Float("DeathBallOutRadius"))
		r2 := float32(s.Balance.Float("DeathBallInRadius"))
		dmg := int(s.Balance.Float("DeathBallNearbyDamage"))
		s.Nox_xxx_mapDamageUnitsAround(obj.PosVec, r1, r2, dmg, object.DamageCrush, obj, nil, doDamageWalls)
	}
	if df > s.SecToFrames(4) {
		sobj.Delete()
	}
}
