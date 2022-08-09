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

	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/common/sound"
)

//export nox_xxx_harpoonBreakForPlr_537520
func nox_xxx_harpoonBreakForPlr_537520(u *nox_object_t) {
	noxServer.abilities.harpoon.breakForPlayer(asUnitC(u))
}

//export nox_xxx_collideHarpoon_4EB6A0
func nox_xxx_collideHarpoon_4EB6A0(a1c *nox_object_t, a2c *nox_object_t) {
	noxServer.abilities.harpoon.Collide(asUnitC(a1c), asUnitC(a2c))
}

//export nox_xxx_updateHarpoon_54F380
func nox_xxx_updateHarpoon_54F380(a1c *nox_object_t) {
	noxServer.abilities.harpoon.Update(asUnitC(a1c))
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

func (a *abilityHarpoon) Do(u *Unit) {
	nox_xxx_playerSetState_4FA020(u, 32)
	if u == nil {
		return
	}
	if !u.Class().Has(object.ClassPlayer) {
		return
	}
	a.createBolt(u)
	if ud := u.updateDataPlayer(); ud != nil {
		ud.harpoon_35 = 0
	}
}

func (a *abilityHarpoon) createBolt(u *Unit) {
	if u == nil {
		return
	}
	if !u.Class().Has(object.ClassPlayer) {
		return
	}
	bolt := a.s.newObjectByTypeID("HarpoonBolt")
	if bolt == nil {
		return
	}
	ud := u.updateDataPlayer()
	r := u.getShape().circle.R + 1.0
	*(**nox_object_t)(unsafe.Add(bolt.collide_data, 4)) = u.CObj()
	cos := memmap.Float32(0x587000, 194136+8*uintptr(u.direction1))
	sin := memmap.Float32(0x587000, 194140+8*uintptr(u.direction1))
	hpos := u.Pos().Add(types.Pointf{
		X: r * cos, Y: r * sin,
	})
	nox_xxx_createAt_4DAA50(bolt, u, hpos)
	bolt.vel_x = C.float(cos * float32(bolt.speed_cur))
	bolt.vel_y = C.float(sin * float32(bolt.speed_cur))
	dir := u.direction1
	bolt.direction1 = dir
	bolt.direction2 = dir
	ud.harpoon_bolt = bolt.CObj()
	ud.harpoon_35 = 0
}

func (a *abilityHarpoon) netHarpoonAttach(u1, u2 *Unit) {
	if u1 != nil && u2 != nil {
		var buf [7]byte
		buf[0] = byte(noxnet.MSG_FX_DURATION_SPELL)
		buf[1] = 7
		buf[2] = 0
		binary.LittleEndian.PutUint16(buf[3:], uint16(a.s.nox_xxx_netGetUnitCodeServ(u1)))
		binary.LittleEndian.PutUint16(buf[5:], uint16(a.s.nox_xxx_netGetUnitCodeServ(u2)))
		a.s.nox_xxx_netSendPacket1_4E5390(255, buf[:7], 0, 1)
	}
}

func (a *abilityHarpoon) netHarpoonBreak(u1 *Unit, u2 *Unit) {
	if u1 != nil && u2 != nil {
		var buf [7]byte
		buf[0] = byte(noxnet.MSG_FX_DURATION_SPELL)
		buf[1] = 14
		buf[2] = 0
		binary.LittleEndian.PutUint16(buf[3:], uint16(a.s.nox_xxx_netGetUnitCodeServ(u1)))
		binary.LittleEndian.PutUint16(buf[5:], uint16(a.s.nox_xxx_netGetUnitCodeServ(u2)))
		a.s.nox_xxx_netSendPacket1_4E5390(255, buf[:7], 0, 1)
	}
}

func (a *abilityHarpoon) UpdatePlayer(u *Unit) {
	ud := u.updateDataPlayer()
	if targ := asObjectC(ud.harpoon_targ); targ != nil {
		if targ.Flags().Has(object.FlagDestroyed) {
			a.breakForPlayer(u)
		} else {
			force := gamedataFloat("HarpoonForce")
			sub_4E7540(u, targ)
			targ.applyForce(u.Pos(), -force)
		}
	}
}

func (a *abilityHarpoon) breakForPlayer(u *Unit) {
	a.breakSilent(u)
	nox_xxx_aud_501960(sound.SoundHarpoonBroken, u, 0, 0)
}

func (a *abilityHarpoon) breakSilent(u *Unit) {
	if u == nil {
		return
	}
	ud := u.updateDataPlayer()
	if ud == nil {
		return
	}
	if ud.harpoon_bolt != nil {
		ud.harpoon_targ = nil
		a.s.abilities.DisableAbility(u, AbilityHarpoon)
		asUnitC(ud.harpoon_bolt).Delete()
		ud.harpoon_bolt = nil
	}
}

func (a *abilityHarpoon) Collide(bolt *Unit, targ *Unit) {
	owner := bolt.OwnerC().AsUnit()
	if a.damage == 0 {
		a.damage = int(gamedataFloat("HarpoonDamage"))
	}
	ud := owner.updateDataPlayer()
	if targ == nil {
		npos := bolt.newPos()
		C.nox_xxx_damageToMap_534BC0(C.int(npos.X/common.GridStep), C.int(npos.Y/common.GridStep), C.int(a.damage), 11, bolt.CObj())
		a.breakSilent(owner)
		return
	}
	if targ.Flags().HasAny(object.FlagDestroyed|object.FlagDead) || targ == owner {
		return
	}
	u5 := bolt.findOwnerChainPlayer()
	if targ.callDamage(u5, bolt, a.damage, 11) == 0 || !(owner.isEnemyTo(targ) || checkGameplayFlags(1) && targ.Class().HasAny(object.MaskUnits)) {
		C.nox_xxx_soundDefaultDamageSound_532E20(targ.CObj(), bolt.CObj())
		a.breakSilent(owner)
		return
	}
	ud.harpoon_targ = targ.CObj()
	tpos := targ.Pos()
	ud.harpoon_targ_x = C.float(tpos.X)
	ud.harpoon_targ_y = C.float(tpos.Y)
	ud.harpoon_frame = C.uint(gameFrame())
	bolt.SetFlags(bolt.Flags() | object.FlagNoCollide)
	sub_4E7540(bolt.OwnerC(), targ)
	nox_xxx_aud_501960(sound.SoundHarpoonReel, owner, 0, 0)
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
		a.breakForPlayer(owner)
		return
	}
	bud := bolt.updateDataPtr()
	pud := owner.updateDataPlayer()
	obj4 := asUnitC(*(**nox_object_t)(bud))
	if obj4 != nil && obj4.Flags().HasAny(object.FlagDestroyed|object.FlagDead) {
		a.breakForPlayer(owner)
		return
	}
	if obj4 == nil {
		if pud.harpoon_targ == nil {
			pl := pud.Player()
			v13 := types.Pointf{
				X: float32(pl.field_2284),
				Y: float32(pl.field_2288),
			}
			obj6 := nox_xxx_spellFlySearchTarget(&v13, bolt, 32, a.maxDist, 0, owner)
			*(**nox_object_t)(bud) = obj6.CObj()
			if obj6 != nil {
				if nox_server_testTwoPointsAndDirection_4E6E50(bolt.Pos(), int16(bolt.direction1), obj6.Pos())&0x1 == 0 {
					*(**nox_object_t)(bud) = nil
				}
			}
		}
	}
	if obj4 != nil && pud.harpoon_targ == nil {
		vel := obj4.Pos().Sub(bolt.Pos())
		bolt.setVel(vel.Normalize().Mul(float32(bolt.speed_cur)))
	}
	dist := nox_xxx_calcDistance_4E6C00(bolt, owner)
	if targ := asUnitC(pud.harpoon_targ); targ != nil {
		if dist > a.maxDist {
			a.breakForPlayer(owner)
			return
		}
		if dist < a.minDist {
			a.breakSilent(owner)
			return
		}

		if df := gameFrame() - uint32(pud.harpoon_35); float32(df) > a.lifetime {
			a.breakForPlayer(owner)
			return
		}
		tpos := targ.Pos()
		if gameFrame()-uint32(pud.harpoon_frame) > 30 {
			pud.harpoon_frame = C.uint(gameFrame())
			dx := float32(pud.harpoon_targ_x) - tpos.X
			dy := float32(pud.harpoon_targ_y) - tpos.Y
			if dx*dx+dy*dy < 1.0 {
				a.breakForPlayer(owner)
				return
			}
			pud.harpoon_targ_x = C.float(tpos.X)
			pud.harpoon_targ_y = C.float(tpos.Y)
		}
		if !MapTraceRayAt(owner.Pos(), tpos, nil, nil, 9) {
			a.breakForPlayer(owner)
			return
		}
		if targ.Flags().HasAny(object.FlagDestroyed | object.FlagDead) {
			a.breakForPlayer(owner)
			return
		}
		bolt.setNewPos(tpos)
		bolt.setPos(tpos)
		bolt.setPrevPos(tpos)
		bolt.setVel(types.Pointf{})
		bolt.setForce(types.Pointf{})
		bolt.direction1 = targ.direction1
		nox_xxx_moveUpdateSpecial_517970(bolt.CObj())
	} else if dist > a.maxFlight {
		a.breakForPlayer(owner)
		return
	}
	if pud.harpoon_35 == 0 {
		a.netHarpoonAttach(owner, bolt)
		pud.harpoon_35 = C.uint(gameFrame())
	}
}
