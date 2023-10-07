package opennox

import (
	"encoding/binary"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/common"
	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/types"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/server"
)

func nox_xxx_harpoonBreakForPlr_537520(u *server.Object) {
	noxServer.abilities.harpoon.breakForOwner(asObjectS(u), true)
}

func nox_xxx_collideHarpoon_4EB6A0(a1c *server.Object, a2c *server.Object) {
	noxServer.abilities.harpoon.Collide(asObjectS(a1c), asObjectS(a2c))
}

func nox_xxx_updateHarpoon_54F380(a1c *server.Object) {
	noxServer.abilities.harpoon.Update(asObjectS(a1c))
}

type harpoonData struct {
	*harpoonPtr
	getAim func() types.Pointf
}

var _ = [1]struct{}{}[24-unsafe.Sizeof(harpoonPtr{})]

type harpoonPtr struct {
	target  *server.Object // 33, 132
	bolt    *server.Object // 34, 136
	frame35 uint32         // 35, 140
	targPos types.Pointf   // 36, 144
	frame38 uint32         // 38, 152
}

type abilityHarpoon struct {
	s         *Server
	damage    int
	maxDist   float32
	minDist   float32
	maxFlight float32
	lifetime  float32
}

func (a *abilityHarpoon) Init(s *Server) {
	a.s = s
}

func (a *abilityHarpoon) Free() {
}

func (a *abilityHarpoon) getHarpoonData(u *Object) *harpoonData {
	if u == nil {
		return nil
	}
	switch {
	case u.Class().Has(object.ClassPlayer):
		ud := u.UpdateDataPlayer()
		pl := asPlayerS(ud.Player)
		p := (*harpoonPtr)(unsafe.Pointer(&ud.HarpoonTarg))
		return &harpoonData{harpoonPtr: p, getAim: func() types.Pointf {
			return pl.CursorPos()
		}}
	default:
		panic(u.Class().String())
	}
}

func (a *abilityHarpoon) Do(u *Object) {
	nox_xxx_playerSetState_4FA020(u, 32)
	if u == nil {
		return
	}
	d := a.getHarpoonData(u)
	if d == nil {
		return
	}
	a.createBolt(u)
	d.frame35 = 0
}

func (a *abilityHarpoon) createBolt(u *Object) {
	if u == nil {
		return
	}
	d := a.getHarpoonData(u)
	if d == nil {
		return
	}
	bolt := a.s.NewObjectByTypeID("HarpoonBolt")
	if bolt == nil {
		return
	}
	r := u.Shape.Circle.R + 1.0
	*(**server.Object)(unsafe.Add(bolt.CollideData, 4)) = u.SObj()
	dv := u.Direction1.Vec()
	hpos := u.Pos().Add(dv.Mul(r))
	a.s.CreateObjectAt(bolt, u, hpos)
	bolt.VelVec = dv.Mul(bolt.SpeedCur)
	dir := u.Direction1
	bolt.Direction1 = dir
	bolt.Direction2 = dir
	d.bolt = bolt.SObj()
	d.frame35 = 0
}

func (a *abilityHarpoon) netHarpoonAttach(u1, u2 *Object) {
	if u1 != nil && u2 != nil {
		var buf [7]byte
		buf[0] = byte(noxnet.MSG_FX_DURATION_SPELL)
		buf[1] = 7
		buf[2] = 0
		binary.LittleEndian.PutUint16(buf[3:], uint16(a.s.GetUnitNetCode(u1)))
		binary.LittleEndian.PutUint16(buf[5:], uint16(a.s.GetUnitNetCode(u2)))
		a.s.NetSendPacketXxx1(255, buf[:7], 0, 1)
	}
}

func (a *abilityHarpoon) netHarpoonBreak(u1 *Object, u2 *Object) {
	if u1 != nil && u2 != nil {
		var buf [7]byte
		buf[0] = byte(noxnet.MSG_FX_DURATION_SPELL)
		buf[1] = 14
		buf[2] = 0
		binary.LittleEndian.PutUint16(buf[3:], uint16(a.s.GetUnitNetCode(u1)))
		binary.LittleEndian.PutUint16(buf[5:], uint16(a.s.GetUnitNetCode(u2)))
		a.s.NetSendPacketXxx1(255, buf[:7], 0, 1)
	}
}

func (a *abilityHarpoon) UpdatePlayer(u *Object) {
	d := a.getHarpoonData(u)
	if d == nil {
		return
	}
	if targ := d.target; targ != nil {
		if targ.Flags().Has(object.FlagDestroyed) {
			a.breakForOwner(u, true)
		} else {
			force := a.s.Balance.Float("HarpoonForce")
			sub_4E7540(u, targ)
			asObjectS(targ).applyForce(u.Pos(), -force)
		}
	}
}

func (a *abilityHarpoon) breakForOwner(u *Object, emitSound bool) {
	if u == nil {
		return
	}
	d := a.getHarpoonData(u)
	if d == nil {
		return
	}
	if d.bolt != nil {
		d.target = nil
		a.s.abilities.DisableAbility(u.SObj(), server.AbilityHarpoon)
		asObjectS(d.bolt).Delete()
		d.bolt = nil
	}
	if emitSound {
		a.s.Audio.EventObj(sound.SoundHarpoonBroken, u, 0, 0)
	}
}

func (a *abilityHarpoon) Collide(bolt *Object, targ *Object) {
	owner := bolt.OwnerC()
	if a.damage == 0 {
		a.damage = int(a.s.Balance.Float("HarpoonDamage"))
	}
	if targ == nil {
		npos := bolt.NewPos
		legacy.Nox_xxx_damageToMap_534BC0(int(npos.X/common.GridStep), int(npos.Y/common.GridStep), a.damage, 11, bolt.SObj())
		a.breakForOwner(owner, false)
		return
	}
	if targ.Flags().HasAny(object.FlagDestroyed|object.FlagDead) || targ == owner {
		return
	}
	u5 := bolt.FindOwnerChainPlayer()
	if targ.CallDamage(u5, bolt, a.damage, object.DamageImpact) == 0 || !(a.s.IsEnemyTo(owner.SObj(), targ.SObj()) || noxflags.HasGamePlay(1) && targ.Class().HasAny(object.MaskUnits)) {
		legacy.Nox_xxx_soundDefaultDamageSound_532E20(targ.SObj(), bolt.SObj())
		a.breakForOwner(owner, false)
		return
	}
	d := a.getHarpoonData(owner)
	if d == nil {
		return
	}
	d.target = targ.SObj()
	tpos := targ.Pos()
	d.targPos = tpos
	d.frame38 = a.s.Frame()
	bolt.ObjFlags |= uint32(object.FlagNoCollide)
	sub_4E7540(bolt.OwnerC(), targ)
	a.s.Audio.EventObj(sound.SoundHarpoonReel, owner, 0, 0)
}

func (a *abilityHarpoon) disable(u *Object) {
	ud := u.UpdateDataPlayer()
	a.netHarpoonBreak(u, asObjectS(ud.HarpoonBolt))
}

func (a *abilityHarpoon) Update(bolt *Object) {
	if bolt == nil || bolt.OwnerC() == nil {
		return
	}

	if a.maxDist == 0 {
		a.maxDist = float32(a.s.Balance.Float("MaxHarpoonDistance"))
		a.minDist = float32(a.s.Balance.Float("MinHarpoonDistance"))
		a.maxFlight = float32(a.s.Balance.Float("MaxHarpoonFlightDistance"))
		a.lifetime = float32(a.s.Balance.Float("MaxHarpoonExistence"))
	}
	owner := bolt.OwnerC()
	if owner.Flags().HasAny(object.FlagDestroyed | object.FlagDead) {
		a.breakForOwner(owner, true)
		return
	}
	bud := bolt.UpdateData
	obj4 := asObjectS(*(**server.Object)(bud))
	if obj4 != nil && obj4.Flags().HasAny(object.FlagDestroyed|object.FlagDead) {
		a.breakForOwner(owner, true)
		return
	}
	d := a.getHarpoonData(owner)
	if d == nil {
		return
	}
	if d.target == nil {
		if obj4 == nil {
			aim := d.getAim()
			obj6 := a.s.Nox_xxx_spellFlySearchTarget(&aim, bolt, 32, a.maxDist, 0, owner.SObj())
			*(**server.Object)(bud) = obj6.SObj()
			if obj6 != nil {
				if legacy.Nox_server_testTwoPointsAndDirection_4E6E50(bolt.Pos(), int16(bolt.Direction1), obj6.Pos())&0x1 == 0 {
					*(**server.Object)(bud) = nil
				}
			}
		} else {
			vel := obj4.Pos().Sub(bolt.Pos())
			bolt.VelVec = vel.Normalize().Mul(bolt.SpeedCur)
		}
	}
	dist := nox_xxx_calcDistance_4E6C00(bolt, owner)
	if targ := asObjectS(d.target); targ != nil {
		if dist > a.maxDist {
			a.breakForOwner(owner, true)
			return
		}
		if dist < a.minDist {
			a.breakForOwner(owner, false)
			return
		}

		if df := a.s.Frame() - d.frame35; float32(df) > a.lifetime {
			a.breakForOwner(owner, true)
			return
		}
		tpos := targ.Pos()
		if a.s.Frame()-d.frame38 > 30 {
			d.frame38 = a.s.Frame()
			dx := d.targPos.X - tpos.X
			dy := d.targPos.Y - tpos.Y
			if dx*dx+dy*dy < 1.0 {
				a.breakForOwner(owner, true)
				return
			}
			d.targPos = tpos
		}
		if !a.s.MapTraceRayAt(owner.Pos(), tpos, nil, nil, 9) {
			a.breakForOwner(owner, true)
			return
		}
		if targ.Flags().HasAny(object.FlagDestroyed | object.FlagDead) {
			a.breakForOwner(owner, true)
			return
		}
		bolt.NewPos = tpos
		bolt.PosVec = tpos
		bolt.PrevPos = tpos
		bolt.VelVec = types.Pointf{}
		bolt.ForceVec = types.Pointf{}
		bolt.Direction1 = targ.Direction1
		nox_xxx_moveUpdateSpecial_517970(bolt.SObj())
	} else if dist > a.maxFlight {
		a.breakForOwner(owner, true)
		return
	}
	if d.frame35 == 0 {
		a.netHarpoonAttach(owner, bolt)
		d.frame35 = a.s.Frame()
	}
}
