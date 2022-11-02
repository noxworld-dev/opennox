package opennox

/*
#include "GAME4_3.h"
#include "GAME5_2.h"
*/
import "C"
import (
	"encoding/binary"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/common"
	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/common/sound"
)

//export nox_xxx_harpoonBreakForPlr_537520
func nox_xxx_harpoonBreakForPlr_537520(u *nox_object_t) {
	noxServer.abilities.harpoon.breakForOwner(asUnitC(u), true)
}

//export nox_xxx_collideHarpoon_4EB6A0
func nox_xxx_collideHarpoon_4EB6A0(a1c *nox_object_t, a2c *nox_object_t) {
	noxServer.abilities.harpoon.Collide(asUnitC(a1c), asUnitC(a2c))
}

//export nox_xxx_updateHarpoon_54F380
func nox_xxx_updateHarpoon_54F380(a1c *nox_object_t) {
	noxServer.abilities.harpoon.Update(asUnitC(a1c))
}

type harpoonData struct {
	*harpoonPtr
	getAim func() types.Pointf
}

var _ = [1]struct{}{}[24-unsafe.Sizeof(harpoonPtr{})]

type harpoonPtr struct {
	target  *nox_object_t // 33, 132
	bolt    *nox_object_t // 34, 136
	frame35 uint32        // 35, 140
	targPos types.Pointf  // 36, 144
	frame38 uint32        // 38, 152
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

func (a *abilityHarpoon) getHarpoonData(u *Unit) *harpoonData {
	if u == nil {
		return nil
	}
	switch {
	case u.Class().Has(object.ClassPlayer):
		ud := u.UpdateDataPlayer()
		pl := asPlayerS(ud.Player)
		p := (*harpoonPtr)(unsafe.Pointer(&ud.HarpoonTarg))
		return &harpoonData{harpoonPtr: p, getAim: func() types.Pointf {
			return types.Pointf{
				X: float32(pl.field_2284),
				Y: float32(pl.field_2288),
			}
		}}
	default:
		panic(u.Class().String())
	}
}

func (a *abilityHarpoon) Do(u *Unit) {
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

func (a *abilityHarpoon) createBolt(u *Unit) {
	if u == nil {
		return
	}
	d := a.getHarpoonData(u)
	if d == nil {
		return
	}
	bolt := a.s.newObjectByTypeID("HarpoonBolt")
	if bolt == nil {
		return
	}
	r := u.getShape().Circle.R + 1.0
	*(**nox_object_t)(unsafe.Add(bolt.CollideData, 4)) = u.CObj()
	cos, sin := sincosDir(byte(u.Direction1))
	hpos := u.Pos().Add(types.Pointf{
		X: r * cos, Y: r * sin,
	})
	a.s.createObjectAt(bolt, u, hpos)
	bolt.VelVecX = cos * bolt.SpeedCur
	bolt.VelVecY = sin * bolt.SpeedCur
	dir := u.Direction1
	bolt.Direction1 = dir
	bolt.Direction2 = dir
	d.bolt = bolt.CObj()
	d.frame35 = 0
}

func (a *abilityHarpoon) netHarpoonAttach(u1, u2 *Unit) {
	if u1 != nil && u2 != nil {
		var buf [7]byte
		buf[0] = byte(noxnet.MSG_FX_DURATION_SPELL)
		buf[1] = 7
		buf[2] = 0
		binary.LittleEndian.PutUint16(buf[3:], uint16(a.s.getUnitNetCode(u1)))
		binary.LittleEndian.PutUint16(buf[5:], uint16(a.s.getUnitNetCode(u2)))
		a.s.nox_xxx_netSendPacket1_4E5390(255, buf[:7], 0, 1)
	}
}

func (a *abilityHarpoon) netHarpoonBreak(u1 *Unit, u2 *Unit) {
	if u1 != nil && u2 != nil {
		var buf [7]byte
		buf[0] = byte(noxnet.MSG_FX_DURATION_SPELL)
		buf[1] = 14
		buf[2] = 0
		binary.LittleEndian.PutUint16(buf[3:], uint16(a.s.getUnitNetCode(u1)))
		binary.LittleEndian.PutUint16(buf[5:], uint16(a.s.getUnitNetCode(u2)))
		a.s.nox_xxx_netSendPacket1_4E5390(255, buf[:7], 0, 1)
	}
}

func (a *abilityHarpoon) UpdatePlayer(u *Unit) {
	d := a.getHarpoonData(u)
	if d == nil {
		return
	}
	if targ := asObjectC(d.target); targ != nil {
		if targ.Flags().Has(object.FlagDestroyed) {
			a.breakForOwner(u, true)
		} else {
			force := gamedataFloat("HarpoonForce")
			sub_4E7540(u, targ)
			targ.applyForce(u.Pos(), -force)
		}
	}
}

func (a *abilityHarpoon) breakForOwner(u *Unit, emitSound bool) {
	if u == nil {
		return
	}
	d := a.getHarpoonData(u)
	if d == nil {
		return
	}
	if d.bolt != nil {
		d.target = nil
		a.s.abilities.DisableAbility(u, AbilityHarpoon)
		asUnitC(d.bolt).Delete()
		d.bolt = nil
	}
	if emitSound {
		nox_xxx_aud_501960(sound.SoundHarpoonBroken, u, 0, 0)
	}
}

func (a *abilityHarpoon) Collide(bolt *Unit, targ *Unit) {
	owner := bolt.OwnerC().AsUnit()
	if a.damage == 0 {
		a.damage = int(gamedataFloat("HarpoonDamage"))
	}
	if targ == nil {
		npos := bolt.newPos()
		C.nox_xxx_damageToMap_534BC0(C.int(npos.X/common.GridStep), C.int(npos.Y/common.GridStep), C.int(a.damage), 11, bolt.CObj())
		a.breakForOwner(owner, false)
		return
	}
	if targ.Flags().HasAny(object.FlagDestroyed|object.FlagDead) || targ == owner {
		return
	}
	u5 := bolt.findOwnerChainPlayer()
	if targ.callDamage(u5, bolt, a.damage, 11) == 0 || !(owner.isEnemyTo(targ) || checkGameplayFlags(1) && targ.Class().HasAny(object.MaskUnits)) {
		C.nox_xxx_soundDefaultDamageSound_532E20(targ.CObj(), bolt.CObj())
		a.breakForOwner(owner, false)
		return
	}
	d := a.getHarpoonData(owner)
	if d == nil {
		return
	}
	d.target = targ.CObj()
	tpos := targ.Pos()
	d.targPos = tpos
	d.frame38 = a.s.Frame()
	bolt.SetFlags(bolt.Flags() | object.FlagNoCollide)
	sub_4E7540(bolt.OwnerC(), targ)
	nox_xxx_aud_501960(sound.SoundHarpoonReel, owner, 0, 0)
}

func (a *abilityHarpoon) disable(u *Unit) {
	ud := u.UpdateDataPlayer()
	a.netHarpoonBreak(u, asUnitS(ud.HarpoonBolt))
}

func (a *abilityHarpoon) Update(bolt *Unit) {
	if bolt == nil || bolt.OwnerC() == nil {
		return
	}

	if a.maxDist == 0 {
		a.maxDist = float32(gamedataFloat("MaxHarpoonDistance"))
		a.minDist = float32(gamedataFloat("MinHarpoonDistance"))
		a.maxFlight = float32(gamedataFloat("MaxHarpoonFlightDistance"))
		a.lifetime = float32(gamedataFloat("MaxHarpoonExistence"))
	}
	owner := bolt.OwnerC().AsUnit()
	if owner.Flags().HasAny(object.FlagDestroyed | object.FlagDead) {
		a.breakForOwner(owner, true)
		return
	}
	bud := bolt.UpdateData
	obj4 := asUnitC(*(**nox_object_t)(bud))
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
			obj6 := nox_xxx_spellFlySearchTarget(&aim, bolt, 32, a.maxDist, 0, owner)
			*(**nox_object_t)(bud) = obj6.CObj()
			if obj6 != nil {
				if nox_server_testTwoPointsAndDirection_4E6E50(bolt.Pos(), int16(bolt.Direction1), obj6.Pos())&0x1 == 0 {
					*(**nox_object_t)(bud) = nil
				}
			}
		} else {
			vel := obj4.Pos().Sub(bolt.Pos())
			bolt.setVel(vel.Normalize().Mul(float32(bolt.SpeedCur)))
		}
	}
	dist := nox_xxx_calcDistance_4E6C00(bolt, owner)
	if targ := asUnitC(d.target); targ != nil {
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
		if !MapTraceRayAt(owner.Pos(), tpos, nil, nil, 9) {
			a.breakForOwner(owner, true)
			return
		}
		if targ.Flags().HasAny(object.FlagDestroyed | object.FlagDead) {
			a.breakForOwner(owner, true)
			return
		}
		bolt.setNewPos(tpos)
		bolt.setPos(tpos)
		bolt.setPrevPos(tpos)
		bolt.setVel(types.Pointf{})
		bolt.setForce(types.Pointf{})
		bolt.Direction1 = targ.Direction1
		nox_xxx_moveUpdateSpecial_517970(bolt.CObj())
	} else if dist > a.maxFlight {
		a.breakForOwner(owner, true)
		return
	}
	if d.frame35 == 0 {
		a.netHarpoonAttach(owner, bolt)
		d.frame35 = a.s.Frame()
	}
}
