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
	harpoonDamage int
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
	C.sub_5374D0(u.CObj())
	nox_xxx_aud_501960(998, u, 0, 0)
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
		ud.harpoon_targ = nil
		sub4FC300(owner, AbilityHarpoon)
		bolt.Delete()
		ud.harpoon_bolt = nil
		return
	}
	if targ.Flags().HasAny(object.FlagDestroyed|object.FlagDead) || targ == owner {
		return
	}
	u5 := bolt.findOwnerChainPlayer()
	if targ.callDamage(u5, bolt, harpoonDamage, 11) == 0 || !(owner.isEnemyTo(targ) || checkGameplayFlags(1) && targ.Class().HasAny(object.MaskUnits)) {
		C.nox_xxx_soundDefaultDamageSound_532E20(targ.CObj(), bolt.CObj())
		ud.harpoon_targ = nil
		sub4FC300(owner, AbilityHarpoon)
		bolt.Delete()
		ud.harpoon_bolt = nil
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
