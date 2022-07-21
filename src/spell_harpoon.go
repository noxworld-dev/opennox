package opennox

/*
#include "GAME5_2.h"
*/
import "C"
import (
	"encoding/binary"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
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
