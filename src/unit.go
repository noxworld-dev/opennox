package main

/*
#include "proto.h"
void nox_server_gotoHome(nox_object_t* obj);
*/
import "C"
import (
	"unsafe"

	"nox/v1/common/alloc"
	noxflags "nox/v1/common/flags"
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

type Unit struct {
	Object
}

func (u *Unit) AsObject() *Object {
	return asObjectC(u.CObj())
}

func (u *Unit) String() string {
	return u.stringAs("Unit")
}

func (u *Unit) SetPos(p types.Pointf) {
	cp := (*C.float2)(alloc.Malloc(unsafe.Sizeof(C.float2{})))
	defer alloc.Free(unsafe.Pointer(cp))
	cp.field_0 = C.float(p.X)
	cp.field_4 = C.float(p.Y)
	C.nox_xxx_unitMove_4E7010(u.CObj(), cp)
}

func (u *Unit) Push(vec types.Pointf, force float32) {
	p := u.Pos().Sub(vec)
	l := float32(p.Len())
	p.X = force * p.X / l
	p.Y = force * p.Y / l
	u.PushTo(p)
}

func (u *Unit) PushTo(p types.Pointf) {
	u.force_x += C.float(p.X)
	u.force_y += C.float(p.Y)
}

func (u *Unit) Destroy() {
	panic("implement me")
}

func (u *Unit) CanSee(obj script.Object) bool {
	panic("implement me")
}

func (u *Unit) ptrXxx() unsafe.Pointer {
	return unsafe.Pointer(u.field_139)
}

func (u *Unit) ptrYyy() unsafe.Pointer {
	return unsafe.Pointer(u.field_187)
}

func (u *Unit) Health() (cur, max int) {
	if u == nil {
		return
	}
	p := u.ptrXxx()
	if p == nil {
		return
	}
	cur = int(*(*uint16)(unsafe.Pointer(uintptr(p) + 0)))
	max = int(*(*uint16)(unsafe.Pointer(uintptr(p) + 4)))
	return
}

func (u *Unit) SetHealth(v int) {
	if u == nil {
		return
	}
	if noxflags.HasGame(noxflags.GameSuddenDeath) {
		return
	}
	if v < 0 {
		v = 0
	}
	if _, max := u.Health(); v > max {
		v = max
	}
	// TODO: if 0, trigger death
	C.nox_xxx_unitSetHP_4E4560(u.CObj(), C.ushort(v))
	if u.Class().Has(object.ClassMonster) {
		C.nox_xxx_mobInformOwnerHP_4EE4C0(u.CObj())
	}
}

func (u *Unit) SetMaxHealth(v int) {
	if u == nil {
		return
	}
	if noxflags.HasGame(noxflags.GameSuddenDeath) {
		return
	}
	if v < 0 {
		v = 0
	}
	p := u.ptrXxx()
	if p == nil {
		return
	}
	// TODO: verify it works in MP
	// TODO: if it's the player, we need to adjust GUI health bars
	*(*uint16)(unsafe.Pointer(uintptr(p) + 4)) = uint16(v)
	u.SetHealth(v)
}

func (u *Unit) Mana() (cur, max int) {
	if u == nil {
		return
	}
	p := u.ptrYyy()
	if p == nil {
		return
	}
	// TODO: +6 is similar, what's the difference?
	cur = int(*(*uint16)(unsafe.Pointer(uintptr(p) + 4)))
	max = int(*(*uint16)(unsafe.Pointer(uintptr(p) + 8)))
	return
}

func (u *Unit) SetMana(v int) {
	panic("implement me")
}

func (u *Unit) SetMaxMana(v int) {
	panic("implement me")
}

func (u *Unit) MoveTo(p types.Pointf) {
	// TODO: originally, this method required Waypoint as an argument
	//       but now we actually have WalkTo and friends which accept both position or a waypoint (in LUA)
	//       so we will call WalkTo here for now, but that Waypoint requirement was probably done for a reason
	u.WalkTo(p)
}

func (u *Unit) WalkTo(p types.Pointf) {
	C.nox_xxx_monsterWalkTo_514110(u.CObj(), C.float(p.X), C.float(p.Y))
}

func (u *Unit) look(v int16) {
	*(*int16)(u.field(124)) = v
	*(*int16)(u.field(126)) = v
}

func (u *Unit) LookAt(p types.Pointf) {
	p = p.Sub(u.Pos())
	v := nox_xxx_math_509ED0(p)
	u.look(int16(v))
}

func (u *Unit) LookAtDir(dir int) {
	C.nox_xxx_monsterLookAt_5125A0(u.CObj(), C.int(dir))
}

func (u *Unit) LookAngle(ang int) {
	v := nox_xxx_math_roundDir(int32(ang))
	u.look(int16(v))
}

func (u *Unit) Freeze(freeze bool) {
	if freeze {
		C.nox_xxx_unitFreeze_4E79C0(u.CObj(), 1)
	} else {
		C.nox_xxx_unitUnFreeze_4E7A60(u.CObj(), 1)
	}
}

func (u *Unit) Wander() {
	C.nox_xxx_scriptMonsterRoam_512930(u.CObj())
}

func (u *Unit) Return() {
	C.nox_server_gotoHome(u.CObj())
}

func (u *Unit) Idle() {
	C.nox_xxx_unitIdle_515820(u.CObj())
}

func (u *Unit) Follow(obj script.Positioner) {
	if v, ok := obj.(script.ObjectWrapper); ok {
		obj = v.GetObject()
	}
	cobj := obj.(noxObject)
	C.nox_xxx_unitSetFollow_5158C0(u.CObj(), cobj.CObj())
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

func (u *Unit) Guard() {
	panic("implement me")
}

func (u *Unit) Hunt() {
	C.nox_xxx_unitHunt_5157A0(u.CObj())
}

func (u *Unit) Say(text string, dur script.Duration) {
	panic("implement me")
}

func (u *Unit) Mute() {
	panic("implement me")
}
