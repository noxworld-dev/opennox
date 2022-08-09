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
)

var (
	harpoonDamage    int
	harpoonMaxDist   float32
	harpoonMinDist   float32
	harpoonMaxFlight float32
	harpoonLifetime  float32
)

func nox_xxx_warriorHarpoon_540070(u *Unit) {
	nox_xxx_playerSetState_4FA020(u, 32)
	if u == nil {
		return
	}
	if !u.Class().Has(object.ClassPlayer) {
		return
	}
	nox_xxx_createHarpoonBolt_538890(u)
	if ud := u.updateDataPlayer(); ud != nil {
		ud.harpoon_35 = 0
	}
}

func nox_xxx_createHarpoonBolt_538890(u *Unit) {
	s := noxServer
	if u == nil {
		return
	}
	if !u.Class().Has(object.ClassPlayer) {
		return
	}
	bolt := s.newObjectByTypeID("HarpoonBolt")
	if bolt == nil {
		return
	}
	ud := u.updateDataPlayer()
	r := u.getShape().circle.R + 1.0
	*(**nox_object_t)(unsafe.Add(bolt.collide_data, 4)) = u.CObj()
	cos := memmap.Float32(0x587000, 194136+8*uintptr(u.field_31_0))
	sin := memmap.Float32(0x587000, 194140+8*uintptr(u.field_31_0))
	hpos := u.Pos().Add(types.Pointf{
		X: r * cos, Y: r * sin,
	})
	nox_xxx_createAt_4DAA50(bolt, u, hpos)
	bolt.vel_x = C.float(cos * float32(bolt.speed_cur))
	bolt.vel_y = C.float(sin * float32(bolt.speed_cur))
	dir := u.field_31_0
	bolt.field_31_0 = dir
	bolt.direction = dir
	ud.harpoon_bolt = bolt.CObj()
	ud.harpoon_35 = 0
}

func (s *Server) nox_xxx_netHarpoonAttach_4D9840(u1, u2 *Unit) {
	if u1 != nil && u2 != nil {
		var buf [7]byte
		buf[0] = byte(noxnet.MSG_FX_DURATION_SPELL)
		buf[1] = 7
		buf[2] = 0
		binary.LittleEndian.PutUint16(buf[3:], uint16(C.nox_xxx_netGetUnitCodeServ_578AC0(u1.CObj())))
		binary.LittleEndian.PutUint16(buf[5:], uint16(C.nox_xxx_netGetUnitCodeServ_578AC0(u2.CObj())))
		s.nox_xxx_netSendPacket1_4E5390(255, buf[:7], 0, 1)
	}
}

func (s *Server) nox_xxx_netHarpoonBreak_4D98A0(u1 *Unit, u2 *Unit) {
	if u1 != nil && u2 != nil {
		var buf [7]byte
		buf[0] = byte(noxnet.MSG_FX_DURATION_SPELL)
		buf[1] = 14
		buf[2] = 0
		binary.LittleEndian.PutUint16(buf[3:], uint16(C.nox_xxx_netGetUnitCodeServ_578AC0(u1.CObj())))
		binary.LittleEndian.PutUint16(buf[5:], uint16(C.nox_xxx_netGetUnitCodeServ_578AC0(u2.CObj())))
		s.nox_xxx_netSendPacket1_4E5390(255, buf[:7], 0, 1)
	}
}

func harpoonUpdatePlayer(u *Unit) {
	ud := u.updateDataPlayer()
	if targ := asObjectC(ud.harpoon_targ); targ != nil {
		if targ.Flags().Has(object.FlagDestroyed) {
			nox_xxx_harpoonBreakForPlr(u)
		} else {
			force := gamedataFloat("HarpoonForce")
			sub_4E7540(u, targ)
			targ.applyForce(u.Pos(), -force)
		}
	}
}

//export nox_xxx_harpoonBreakForPlr_537520
func nox_xxx_harpoonBreakForPlr_537520(u *nox_object_t) {
	nox_xxx_harpoonBreakForPlr(asUnitC(u))
}

func nox_xxx_harpoonBreakForPlr(u *Unit) {
	harpoonBreakSilent(u)
	nox_xxx_aud_501960(998, u, 0, 0)
}

func harpoonBreakSilent(u *Unit) {
	if u == nil {
		return
	}
	ud := u.updateDataPlayer()
	if ud == nil {
		return
	}
	if ud.harpoon_bolt != nil {
		ud.harpoon_targ = nil
		abilityDisable(u, AbilityHarpoon)
		asUnitC(ud.harpoon_bolt).Delete()
		ud.harpoon_bolt = nil
	}
}

//export nox_xxx_collideHarpoon_4EB6A0
func nox_xxx_collideHarpoon_4EB6A0(a1c *nox_object_t, a2c *nox_object_t) {
	bolt := asUnitC(a1c)
	targ := asUnitC(a2c)

	owner := bolt.OwnerC().AsUnit()
	if harpoonDamage == 0 {
		harpoonDamage = int(gamedataFloat("HarpoonDamage"))
	}
	ud := owner.updateDataPlayer()
	if targ == nil {
		npos := bolt.newPos()
		C.nox_xxx_damageToMap_534BC0(C.int(npos.X/common.GridStep), C.int(npos.Y/common.GridStep), C.int(harpoonDamage), 11, bolt.CObj())
		harpoonBreakSilent(owner)
		return
	}
	if targ.Flags().HasAny(object.FlagDestroyed|object.FlagDead) || targ == owner {
		return
	}
	u5 := bolt.findOwnerChainPlayer()
	if targ.callDamage(u5, bolt, harpoonDamage, 11) == 0 || !(owner.isEnemyTo(targ) || checkGameplayFlags(1) && targ.Class().HasAny(object.MaskUnits)) {
		C.nox_xxx_soundDefaultDamageSound_532E20(targ.CObj(), bolt.CObj())
		harpoonBreakSilent(owner)
		return
	}
	ud.harpoon_targ = targ.CObj()
	tpos := targ.Pos()
	ud.harpoon_targ_x = C.float(tpos.X)
	ud.harpoon_targ_y = C.float(tpos.Y)
	ud.harpoon_frame = C.uint(gameFrame())
	bolt.SetFlags(bolt.Flags() | object.FlagNoCollide)
	sub_4E7540(bolt.OwnerC(), targ)
	nox_xxx_aud_501960(999, owner, 0, 0)
}

//export nox_xxx_updateHarpoon_54F380
func nox_xxx_updateHarpoon_54F380(a1c *nox_object_t) {
	s := noxServer
	bolt := asUnitC(a1c)
	if bolt == nil || bolt.OwnerC() == nil {
		return
	}
	//int v1;         // ebx
	//float2** v2;    // ebp
	//int v3;         // edi
	//float2* v4;     // eax
	//int v5;         // eax
	//float2* v6;     // eax
	//long double v7; // st7
	//int v8;         // ecx
	//double v9;      // st7
	//double v10;     // st6
	//float v11;      // eax
	//int v12;        // ecx
	//float4 v13;     // [esp+10h] [ebp-10h]

	if harpoonMaxDist == 0 {
		harpoonMaxDist = float32(gamedataFloat("MaxHarpoonDistance"))
		harpoonMinDist = float32(gamedataFloat("MinHarpoonDistance"))
		harpoonMaxFlight = float32(gamedataFloat("MaxHarpoonFlightDistance"))
		harpoonLifetime = float32(gamedataFloat("MaxHarpoonExistence"))
	}
	owner := bolt.OwnerC().AsUnit()
	if owner.Flags().HasAny(object.FlagDestroyed | object.FlagDead) {
		nox_xxx_harpoonBreakForPlr(owner)
		return
	}
	bud := bolt.updateDataPtr()
	pud := owner.updateDataPlayer()
	obj4 := asUnitC(*(**nox_object_t)(bud))
	if obj4 != nil && obj4.Flags().HasAny(object.FlagDestroyed|object.FlagDead) {
		nox_xxx_harpoonBreakForPlr(owner)
		return
	}
	if obj4 == nil {
		if pud.harpoon_targ == nil {
			pl := pud.Player()
			v13 := types.Pointf{
				X: float32(pl.field_2284),
				Y: float32(pl.field_2288),
			}
			obj6 := nox_xxx_spellFlySearchTarget(&v13, bolt, 32, harpoonMaxDist, 0, owner)
			*(**nox_object_t)(bud) = obj6.CObj()
			if obj6 != nil {
				if nox_server_testTwoPointsAndDirection_4E6E50(bolt.Pos(), int16(bolt.field_31_0), obj6.Pos())&0x1 == 0 {
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
		if dist > harpoonMaxDist {
			nox_xxx_harpoonBreakForPlr(owner)
			return
		}
		if dist < harpoonMinDist {
			harpoonBreakSilent(owner)
			return
		}

		if df := gameFrame() - uint32(pud.harpoon_35); float32(df) > harpoonLifetime {
			nox_xxx_harpoonBreakForPlr(owner)
			return
		}
		tpos := targ.Pos()
		if gameFrame()-uint32(pud.harpoon_frame) > 30 {
			pud.harpoon_frame = C.uint(gameFrame())
			dx := float32(pud.harpoon_targ_x) - tpos.X
			dy := float32(pud.harpoon_targ_y) - tpos.Y
			if dx*dx+dy*dy < 1.0 {
				nox_xxx_harpoonBreakForPlr(owner)
				return
			}
			pud.harpoon_targ_x = C.float(tpos.X)
			pud.harpoon_targ_y = C.float(tpos.Y)
		}
		if !MapTraceRayAt(owner.Pos(), tpos, nil, nil, 9) {
			nox_xxx_harpoonBreakForPlr(owner)
			return
		}
		if targ.Flags().HasAny(object.FlagDestroyed | object.FlagDead) {
			nox_xxx_harpoonBreakForPlr(owner)
			return
		}
		bolt.setNewPos(tpos)
		bolt.setPos(tpos)
		bolt.setPrevPos(tpos)
		bolt.setVel(types.Pointf{})
		bolt.setForce(types.Pointf{})
		bolt.field_31_0 = targ.field_31_0
		nox_xxx_moveUpdateSpecial_517970(bolt.CObj())
	} else if dist > harpoonMaxFlight {
		nox_xxx_harpoonBreakForPlr(owner)
		return
	}
	if pud.harpoon_35 == 0 {
		s.nox_xxx_netHarpoonAttach_4D9840(owner, bolt)
		pud.harpoon_35 = C.uint(gameFrame())
	}
}
