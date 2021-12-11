package nox

/*
#include "defs.h"
void nox_xxx_updateFallLogic_51B870(nox_object_t* a1);
void sub_51B810(nox_object_t* a1);
void sub_537770(nox_object_t* a1);
void nox_xxx_itemApplyUpdateEffect_4FA490(nox_object_t* a1);
void* nox_xxx_findObjectAtCursor_54AF40(nox_object_t* a1);
*/
import "C"
import (
	"nox/v1/common/types"
)

func serverUpdateUnitsAAA() { // nox_xxx_updateUnits_51B100_A
	for _, u := range getPlayerUnits() {
		ud := u.updateDataPlayer()
		C.nox_xxx_itemApplyUpdateEffect_4FA490(u.CObj())
		ud.cursor_obj = C.nox_xxx_findObjectAtCursor_54AF40(u.CObj())
	}
}

func serverUpdateUnitsCallUpdate() { // nox_xxx_updateUnits_51B100_callUpdate
	for obj := firstServerObjectUpdatable2(); obj != nil; obj = obj.Next() {
		if obj.Flags16()&0x22 == 0 {
			obj.callUpdate()
			C.nox_xxx_updateFallLogic_51B870(obj.CObj())
			C.sub_51B810(obj.CObj())
			C.sub_537770(obj.CObj())
			prev := obj.Pos()
			obj.field_31_0 = obj.field_31_1
			npos := obj.newPos()
			obj.setPrevPos(prev)
			obj.setPos(npos)
			obj.setForce(types.Pointf{})
			nox_xxx_moveUpdateSpecial_517970(obj.CObj())
		}
	}
}
