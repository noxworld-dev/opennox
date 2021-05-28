package main

/*
#include "proto.h"
void nox_server_gotoHome(int v2);
*/
import "C"
import (
	"unsafe"

	"nox/v1/common/alloc"
	"nox/v1/common/object"
	"nox/v1/common/types"
	"nox/v1/server/script"
)

func asUnit(p unsafe.Pointer) *Unit {
	if p == nil {
		return nil
	}
	return (*Unit)(p)
}

type Unit [0]byte

func (u *Unit) C() unsafe.Pointer {
	return unsafe.Pointer(u)
}

func (u *Unit) AsObject() *Object {
	return asObject(u.C())
}

func (u *Unit) field(dp uintptr) unsafe.Pointer {
	return unsafe.Pointer(uintptr(u.C()) + dp)
}

func (u *Unit) ID() string {
	p := *(**C.char)(u.field(0))
	return GoString(p)
}

func (u *Unit) Class() object.Class {
	v := *(*uint32)(u.field(8))
	return object.Class(v)
}

func (u *Unit) ObjectType() script.ObjectType {
	panic("implement me")
}

func (u *Unit) Pos() types.Pointf {
	if u == nil {
		return types.Pointf{}
	}
	return types.Pointf{
		X: float32(*(*C.float)(u.field(56))),
		Y: float32(*(*C.float)(u.field(60))),
	}
}

func (u *Unit) MoveTo(p types.Pointf) {
	cp := (*C.float2)(alloc.Malloc(unsafe.Sizeof(C.float2{})))
	defer alloc.Free(unsafe.Pointer(cp))
	cp.field_0 = C.float(p.X)
	cp.field_4 = C.float(p.Y)
	C.nox_xxx_unitMove_4E7010(C.int(uintptr(u.C())), cp)
}

func (u *Unit) Z() float32 {
	return float32(*(*C.int)(u.field(104)))
}

func (u *Unit) SetZ(z float32) {
	panic("implement me")
}

func (u *Unit) Push(vec types.Pointf, force float32) {
	panic("implement me")
}

func (u *Unit) PushTo(p types.Pointf) {
	panic("implement me")
}

func (u *Unit) IsEnabled() bool {
	if u == nil {
		return false
	}
	return *(*uint32)(u.field(16))&0x1000000 != 0
}

func (u *Unit) Enable(enable bool) {
	if u == nil {
		return
	}
	if enable {
		C.nox_xxx_objectSetOn_4E75B0(C.int(uintptr(u.C())))
	} else {
		C.nox_xxx_objectSetOff_4E7600(C.int(uintptr(u.C())))
	}
}

func (u *Unit) Delete() {
	C.nox_xxx_delayedDeleteObject_4E5CC0(C.int(uintptr(u.C())))
}

func (u *Unit) CanSee(obj script.Object) bool {
	panic("implement me")
}

func (u *Unit) Health() (cur, max int) {
	panic("implement me")
}

func (u *Unit) SetHealth(v int) {
	panic("implement me")
}

func (u *Unit) SetMaxHealth(v int) {
	panic("implement me")
}

func (u *Unit) Destroy() {
	panic("implement me")
}

func (u *Unit) Mana() (cur, max int) {
	panic("implement me")
}

func (u *Unit) SetMana(v int) {
	panic("implement me")
}

func (u *Unit) SetMaxMana(v int) {
	panic("implement me")
}

func (u *Unit) WalkTo(p types.Pointf) {
	C.nox_xxx_monsterWalkTo_514110(C.int(uintptr(u.C())), C.int(p.X), C.int(p.Y))
}

func (u *Unit) LookAt(p types.Pointf) {
	p1, p2 := u.Pos(), p
	p.X = p2.X - p1.X
	p.Y = p2.Y - p1.Y
	v := nox_xxx_math_509ED0(p)
	*(*int16)(u.field(124)) = int16(v)
	*(*int16)(u.field(126)) = int16(v)
}

func (u *Unit) LookAtDir(dir int) {
	panic("implement me")
}

func (u *Unit) LookAngle(ang int) {
	panic("implement me")
}

func (u *Unit) Freeze(freeze bool) {
	if freeze {
		C.nox_xxx_unitFreeze_4E79C0(C.int(uintptr(u.C())), 1)
	} else {
		C.nox_xxx_unitUnFreeze_4E7A60(C.int(uintptr(u.C())), 1)
	}
}

func (u *Unit) Wander() {
	C.nox_xxx_scriptMonsterRoam_512930(C.int(uintptr(u.C())))
}

func (u *Unit) Return() {
	C.nox_server_gotoHome(C.int(uintptr(u.C())))
}

func (u *Unit) Follow(obj script.Positioner) {
	panic("implement me")
}

func (u *Unit) Flee(obj script.Positioner, dur script.Duration) {
	panic("implement me")
}

func (u *Unit) Aggression() float32 {
	panic("implement me")
}

func (u *Unit) SetAggression(v float32) {
	panic("implement me")
}

func (u *Unit) RetreatLevel() float32 {
	panic("implement me")
}

func (u *Unit) SetRetreatLevel(v float32) {
	panic("implement me")
}

func (u *Unit) RegroupLevel() float32 {
	panic("implement me")
}

func (u *Unit) SetRegroupLevel(v float32) {
	panic("implement me")
}

func (u *Unit) Attack(obj script.Positioner) {
	panic("implement me")
}

func (u *Unit) HitMelee(p types.Pointf) {
	panic("implement me")
}

func (u *Unit) HitRanged(p types.Pointf) {
	panic("implement me")
}

func (u *Unit) Say(text string, dur script.Duration) {
	panic("implement me")
}

func (u *Unit) Mute() {
	panic("implement me")
}
