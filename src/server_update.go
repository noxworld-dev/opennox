package opennox

/*
#include "defs.h"
void nox_xxx_updateFallLogic_51B870(nox_object_t* a1);
void sub_51B810(nox_object_t* a1);
void sub_537770(nox_object_t* a1);
nox_object_t* nox_xxx_findObjectAtCursor_54AF40(nox_object_t* a1);
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/types"
)

func (s *Server) itemsApplyUpdateEffect(a1 *Object) {
	for it := asObjectS(a1.InvFirstItem); it != nil; it = asObjectS(it.InvNextItem) {
		const maskItems = object.ClassFlag | object.ClassWeapon | object.ClassArmor | object.ClassWand
		if it.Flags().Has(object.FlagEquipped) && it.Class().HasAny(maskItems) {
			idata := unsafe.Slice((*unsafe.Pointer)(it.InitData), 4)
			for _, mod := range idata {
				if mod != nil {
					if fnc := *(*unsafe.Pointer)(unsafe.Add(mod, 100)); fnc != nil {
						cgoCallVoidPtr3Func(fnc, mod, unsafe.Pointer(it.CObj()), nil)
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

func (s *Server) updateUnitsCallUpdate() { // nox_xxx_updateUnits_51B100_callUpdate
	for obj := asObjectS(s.Objs.UpdatableList2); obj != nil; obj = obj.Next() {
		if obj.Flags().HasAny(object.FlagNoUpdateMask) {
			continue
		}
		obj.callUpdate()
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
