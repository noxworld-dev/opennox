package opennox

import (
	"math"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/common/ntype"
	"github.com/noxworld-dev/opennox/v1/common/sound"
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

func nox_xxx_collideDeathBall_4E9E90(ball *server.Object, targ *server.Object, pos *types.Pointf) {
	s := asObjectS(ball).getServer()
	if targ != nil {
		if targ.Class().Has(object.ClassDoor) {
			ud := targ.UpdateData
			ball.NewPos.X = ball.PrevPos.X
			ball.NewPos.Y = ball.PrevPos.Y
			dx := float64(targ.PosVec.X - ball.PrevPos.X)
			dy := float64(targ.PosVec.Y - ball.PrevPos.Y)
			ind := *(*uint32)(unsafe.Add(ud, 12))
			xx := -float64(memmap.Int32(0x587000, uintptr(ind)*8+196188))
			yy := +float64(memmap.Int32(0x587000, uintptr(ind)*8+196184))
			var vv types.Pointf
			vv.X = float32(xx)
			vv.Y = float32(yy)
			if yy*dy+xx*dx > 0.0 {
				vv.X = -vv.X
				vv.Y = -vv.Y
			}
			sub_57B770(&ball.VelVec, vv)
			s.Audio.EventObj(sound.SoundFireExtinguish, ball, 0, 0)
		} else {
			v14 := int(s.Balance.Float("DeathBallCollideDamage"))
			owner := ball.FindOwnerChainPlayer()
			targ.CallDamage(owner, ball, v14, object.DamageCrush)
		}
	} else {
		if pos != nil {
			nox_xxx_collideReflect_57B810(pos, &ball.VelVec)
			s.Audio.EventObj(sound.SoundForceOfNatureReflect, ball, 0, 0)
			if res := traceHitResult(); res != nil {
				dmg := int(s.Balance.Float("DeathBallCollideDamage"))
				s.Nox_xxx_damageToMap_534BC0(int(res.X), int(res.Y), dmg, object.DamageCrush, ball)
			}
		}
	}
}

func sub_57B770(a1 *types.Pointf, a2 types.Pointf) {
	v9 := a2.X
	v3 := math.Sqrt(float64(a2.X*a2.X + a2.Y*a2.Y))
	v4 := v3 + 0.1
	v5 := float64(-a2.Y)
	v6 := float64(a1.X*a2.X+a1.Y*a2.Y) / (v3 + 0.1)
	v11 := float32((float64(a2.X*a1.Y) + v5*float64(a1.X)) / v4)
	v7 := float32(v6 * float64(a2.X) / v4)
	v8 := float32(v6 * float64(a2.Y) / v4)
	v10 := float32(float64(v11) * v5 / v4)
	a1.X = v10 - v7
	a1.Y = float32(float64(v11*v9)/v4 - float64(v8))
}

func nox_xxx_collideReflect_57B810(a1 *types.Pointf, a2 *types.Pointf) {
	if a1.Y*a1.X <= 0.0 {
		a2.X, a2.Y = a2.Y, a2.X
	} else {
		a2.X, a2.Y = -a2.Y, -a2.X
	}
}

func traceHitResult() *ntype.Point32 {
	if legacy.Get_dword_5d4594_2488620() != 0 {
		return memmap.PtrT[ntype.Point32](0x5D4594, 2488612)
	}
	return nil
}
