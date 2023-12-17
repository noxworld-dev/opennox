package opennox

import (
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/legacy"
)

func (s *Server) updateUnitsAAA() { // nox_xxx_updateUnits_51B100_A
	for _, u := range s.getPlayerUnits() {
		s.ItemsApplyUpdateEffect(u.SObj())
		ud := u.UpdateDataPlayer()
		ud.CursorObj = legacy.Nox_xxx_findObjectAtCursor_54AF40(u.SObj())
	}
}

func (s *Server) updateUnitsBBB() { // nox_xxx_updateUnits_51B100_B
	var next *Object
	for obj := asObjectS(s.Objs.UpdatableList); obj != nil; obj = next {
		next = asObjectS(obj.UpdatableNext)
		if obj.Flags().Has(object.FlagDestroyed) {
			continue
		}
		if obj4 := asObjectS(obj.Obj130); obj4 != nil && obj4.Flags().Has(object.FlagDestroyed) {
			if obj5 := asObjectS(obj4.ObjOwner); obj5 == nil || obj5.Flags().Has(object.FlagDestroyed) {
				obj.Obj130 = nil
			} else {
				obj.Obj130 = obj5.SObj()
			}
		}
		if obj.Update != nil {
			if !obj.Flags().Has(object.FlagNoUpdate) {
				obj.CallUpdate()
			}
			if obj.Class().Has(object.ClassPlayer) {
				s.Players.Control.Player(obj.ControllingPlayer().Index()).Reset()
			}
		}
		if obj.Class().Has(object.ClassMonster) {
			obj.NeedSync()
		}
		legacy.Nox_xxx_updateFallLogic_51B870(obj.SObj())
		if h := obj.HealthData; h != nil {
			h.Field2 = h.Cur
		}
		obj.ObjFlags &^= uint32(object.FlagOnObject)
		dxr := fabs(obj.NewPos.X - obj.PosVec.X)
		dyr := fabs(obj.NewPos.Y - obj.PosVec.Y)
		const dpos = 0.01
		if obj.ForceVec.X <= -dpos || obj.ForceVec.X >= dpos || obj.ForceVec.Y <= -dpos || obj.ForceVec.Y >= dpos ||
			obj.VelVec.X <= -dpos || obj.VelVec.X >= dpos || obj.VelVec.Y <= -dpos || obj.VelVec.Y >= dpos ||
			dxr <= -dpos || dxr >= dpos || dyr <= -dpos || dyr >= dpos ||
			obj.ZVal <= -dpos || obj.ZVal >= dpos || obj.Field27 <= -dpos || obj.Field27 >= dpos {
			legacy.Nox_xxx_unitHasCollideOrUpdateFn_537610(obj.SObj())
			obj.ObjFlags &^= uint32(object.FlagStill)
		} else {
			obj.ForceVec = types.Pointf{}
			obj.VelVec = types.Pointf{}
			obj.SetZ(0.0)
			obj.NewPos = obj.PosVec
			obj.Field27 = 0
			obj.ObjFlags |= uint32(object.FlagStill)
			if obj.Update == nil {
				s.Objs.RemoveFromUpdatable(obj.SObj())
			}
		}
	}
}

func (s *Server) updateUnitsCallUpdate() { // nox_xxx_updateUnits_51B100_callUpdate
	for obj := s.Objs.UpdatableList2; obj != nil; obj = obj.Next() {
		if obj.Flags().HasAny(object.FlagNoUpdateMask) {
			continue
		}
		asObjectS(obj).CallUpdate()
		legacy.Nox_xxx_updateFallLogic_51B870(obj)
		legacy.Sub_51B810(obj)
		legacy.Sub_537770(obj)
		prev := obj.Pos()
		obj.Direction1 = obj.Direction2
		npos := obj.NewPos
		obj.PrevPos = prev
		obj.PosVec = npos
		obj.ForceVec = types.Pointf{}
		s.nox_xxx_moveUpdateSpecial_517970(obj)
	}
}
