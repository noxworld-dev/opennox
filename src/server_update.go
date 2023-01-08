package opennox

/*
#include "defs.h"
void nox_xxx_updateFallLogic_51B870(nox_object_t* a1);
char nox_xxx_unitHasCollideOrUpdateFn_537610(nox_object_t* a1p);
void nox_xxx_unitNeedSync_4E44F0(nox_object_t* a1);
void sub_51B810(nox_object_t* a1);
void sub_537770(nox_object_t* a1);
nox_object_t* nox_xxx_findObjectAtCursor_54AF40(nox_object_t* a1);
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/internal/ccall"
)

func (s *Server) itemsApplyUpdateEffect(a1 *Object) {
	for it := asObjectS(a1.InvFirstItem); it != nil; it = asObjectS(it.InvNextItem) {
		const maskItems = object.ClassFlag | object.ClassWeapon | object.ClassArmor | object.ClassWand
		if it.Flags().Has(object.FlagEquipped) && it.Class().HasAny(maskItems) {
			idata := unsafe.Slice((*unsafe.Pointer)(it.InitData), 4)
			for _, mod := range idata {
				if mod != nil {
					if fnc := *(*unsafe.Pointer)(unsafe.Add(mod, 100)); fnc != nil {
						ccall.CallVoidPtr3(fnc, mod, unsafe.Pointer(it.CObj()), nil)
					}
				}
			}
		}
	}
}

func (s *Server) updateUnitsAAA() { // nox_xxx_updateUnits_51B100_A
	for _, u := range s.getPlayerUnits() {
		s.itemsApplyUpdateEffect(u.AsObject())
		ud := u.UpdateDataPlayer()
		ud.CursorObj = asObjectC(C.nox_xxx_findObjectAtCursor_54AF40(u.CObj())).SObj()
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
				s.Players.Control.Player(obj.AsUnit().ControllingPlayer().Index()).Reset()
			}
		}
		if obj.Class().Has(object.ClassMonster) {
			obj.NeedSync()
		}
		C.nox_xxx_updateFallLogic_51B870(obj.CObj())
		if h := obj.HealthData; h != nil {
			h.Field2 = h.Cur
		}
		obj.ObjFlags &^= uint32(object.FlagOnObject)
		dxr := sub_419A10(obj.NewPos.X - obj.PosVec.X)
		dyr := sub_419A10(obj.NewPos.Y - obj.PosVec.Y)
		const dpos = 0.01
		if obj.ForceVec.X <= -dpos || obj.ForceVec.X >= dpos || obj.ForceVec.Y <= -dpos || obj.ForceVec.Y >= dpos ||
			obj.VelVec.X <= -dpos || obj.VelVec.X >= dpos || obj.VelVec.Y <= -dpos || obj.VelVec.Y >= dpos ||
			dxr <= -dpos || dxr >= dpos || dyr <= -dpos || dyr >= dpos ||
			obj.ZVal <= -dpos || obj.ZVal >= dpos || obj.Field27 <= -dpos || obj.Field27 >= dpos {
			C.nox_xxx_unitHasCollideOrUpdateFn_537610(obj.CObj())
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
	for obj := asObjectS(s.Objs.UpdatableList2); obj != nil; obj = obj.Next() {
		if obj.Flags().HasAny(object.FlagNoUpdateMask) {
			continue
		}
		obj.CallUpdate()
		C.nox_xxx_updateFallLogic_51B870(obj.CObj())
		C.sub_51B810(obj.CObj())
		C.sub_537770(obj.CObj())
		prev := obj.Pos()
		obj.Direction1 = obj.Direction2
		npos := obj.NewPos
		obj.PrevPos = prev
		obj.PosVec = npos
		obj.ForceVec = types.Pointf{}
		nox_xxx_moveUpdateSpecial_517970(obj.CObj())
	}
}
