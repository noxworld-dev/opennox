package opennox

/*
#include "defs.h"
#include "server__script__script.h"
*/
import "C"
import (
	"fmt"
	"unsafe"
)

type noxEventType int

const (
	noxEventCollide            = noxEventType(1)  // 1+2
	noxEventGeneratorSpawn     = noxEventType(2)  // 1+2
	noxEventGeneratorDead      = noxEventType(3)  // 1+2
	noxEventMonsterMoveXXX     = noxEventType(4)  // 2
	noxEventMonsterIdle        = noxEventType(5)  // 2
	noxEventMonsterDone        = noxEventType(6)  // 2
	noxEventMonsterDead        = noxEventType(7)  // 2
	noxEventTriggerActivated   = noxEventType(8)  // 1+2
	noxEventTriggerDeactivated = noxEventType(9)  // 2
	noxEventToggleXXX          = noxEventType(10) // 1+2
	noxEventToggleYYY          = noxEventType(11) // 2
	noxEventMonsterYYY         = noxEventType(12) // 1+2
	noxEventMonsterFightStart  = noxEventType(13) // 1+2
	noxEventMonsterSeeEnemy    = noxEventType(14) // 1+2
	noxEventMonsterLostEnemy   = noxEventType(15) // 1+2
	noxEventMonsterHearEnemy   = noxEventType(16) // 1+2 -- unit, heardMonster, raycastDistance
	noxEventMonsterZZZ         = noxEventType(17) // 1+2
	noxEventInventoryPlace     = noxEventType(18) // 1+2
	noxEventGeneratorCollide   = noxEventType(19) // 1+2
	noxEventTrapdoorCollide    = noxEventType(20) // 1+2
	noxEventBombCollide        = noxEventType(21) // 1+2
	noxEventMonsterCollide     = noxEventType(22) // 1+2
	noxEventGeneratorDamage    = noxEventType(23) // 1+2
	noxEventPolygonEnterXXX    = noxEventType(24) // 1
	noxEventPolygonEnterYYY    = noxEventType(25) // 1
	noxEventPolygonEnterZZZ    = noxEventType(26) // 1
	noxEventPolygonPlayerXXX   = noxEventType(27) // 1
	noxEventPolygonPlayerEnter = noxEventType(28) // 1
	noxEventPolygonPlayerZZZ   = noxEventType(29) // 1
	noxEventPlayerJoin         = noxEventType(30) // 1
	noxEventPlayerLeave        = noxEventType(31) // 1
)

func (ev noxEventType) String() string {
	switch ev {
	case 0:
		return "UnknownEvent"
	case noxEventCollide:
		return "Collide"
	case noxEventGeneratorSpawn:
		return "GeneratorSpawn"
	case noxEventGeneratorDead:
		return "GeneratorDead"
	case noxEventMonsterMoveXXX:
		return "MonsterMoveXXX"
	case noxEventMonsterIdle:
		return "MonsterIdle"
	case noxEventMonsterDone:
		return "MonsterDone"
	case noxEventMonsterDead:
		return "MonsterDead"
	case noxEventTriggerActivated:
		return "TriggerActivated"
	case noxEventTriggerDeactivated:
		return "TriggerDeactivated"
	case noxEventToggleXXX:
		return "ToggleXXX"
	case noxEventToggleYYY:
		return "ToggleYYY"
	case noxEventMonsterYYY:
		return "MonsterYYY"
	case noxEventMonsterFightStart:
		return "MonsterFightStart"
	case noxEventMonsterSeeEnemy:
		return "MonsterSeeEnemy"
	case noxEventMonsterLostEnemy:
		return "MonsterLostEnemy"
	case noxEventMonsterHearEnemy:
		return "MonsterHearEnemy"
	case noxEventMonsterZZZ:
		return "MonsterZZZ"
	case noxEventInventoryPlace:
		return "InventoryPlace"
	case noxEventGeneratorCollide:
		return "GeneratorCollide"
	case noxEventTrapdoorCollide:
		return "TrapdoorCollide"
	case noxEventBombCollide:
		return "BombCollide"
	case noxEventMonsterCollide:
		return "MonsterCollide"
	case noxEventGeneratorDamage:
		return "GeneratorDamage"
	case noxEventPolygonEnterXXX:
		return "PolygonEnterXXX"
	case noxEventPolygonEnterYYY:
		return "PolygonEnterYYY"
	case noxEventPolygonEnterZZZ:
		return "PolygonEnterZZZ"
	case noxEventPolygonPlayerXXX:
		return "PolygonPlayerXXX"
	case noxEventPolygonPlayerEnter:
		return "PolygonPlayerEnter"
	case noxEventPolygonPlayerZZZ:
		return "PolygonPlayerZZZ"
	default:
		return fmt.Sprintf("noxEventType(%d)", int(ev))
	}
}

func nox_xxx_scriptCallByEventBlock_502490(ptr *uint32, obj1 noxObject, obj2 noxObject, ev noxEventType) {
	C.nox_xxx_scriptCallByEventBlock_502490((*C.int)(unsafe.Pointer(ptr)), C.int(uintptr(unsafe.Pointer(toCObj(obj1)))), C.int(uintptr(unsafe.Pointer(toCObj(obj2)))), C.int(ev))
}

//export nox_script_callByEvent_cgo
func nox_script_callByEvent_cgo(event C.int, a1, a2 unsafe.Pointer) {
	noxServer.nox_script_callByEventcgo(int(event), a1, a2)
}

func (s *Server) nox_script_callByEventcgo(event int, a1, a2 unsafe.Pointer) {
	ev := noxEventType(event)
	switch ev {
	case noxEventCollide, noxEventMonsterCollide, noxEventMonsterHearEnemy:
		// too frequent, don't log for now
	case noxEventTriggerActivated:
		obj := asObject(a1)
		trig := asObject(a2)
		callOnTriggerActivated(trig, obj)
	case noxEventTriggerDeactivated:
		trig := asObject(a2)
		callOnTriggerDeactivated(trig)
	case noxEventMonsterDone:
		obj := asUnit(a2)
		callOnMonsterDone(obj)
	case noxEventMonsterFightStart:
		targ := asUnit(a1)
		obj := asUnit(a2)
		callOnMonsterAttack(obj, targ)
	case noxEventMonsterSeeEnemy:
		targ := asUnit(a1)
		obj := asUnit(a2)
		// TODO: inverse order?
		callOnMonsterSeeEnemy(obj, targ)
	case noxEventMonsterLostEnemy:
		targ := asUnit(a1)
		obj := asUnit(a2)
		// TODO: inverse order?
		callOnMonsterLostEnemy(obj, targ)
	case noxEventPolygonPlayerEnter:
		obj := asUnit(a1)
		scriptLog.Printf("secret YYY: %s", obj)
		callOnPolygonPlayerEnter(obj)
	case noxEventPolygonEnterYYY:
		v1 := asUnit(a1)
		scriptLog.Printf("polygon YYY: %s", v1)
	case noxEventMonsterIdle:
		obj := asUnit(a2)
		callOnMonsterIdle(obj)
	case noxEventMonsterDead:
		obj := asUnit(a2)
		callOnMonsterDead(obj)
	case noxEventPlayerJoin:
		p := asPlayer((*C.nox_playerInfo)(a1))
		s.callOnPlayerJoin(p)
	case noxEventPlayerLeave:
		p := asPlayer((*C.nox_playerInfo)(a1))
		s.callOnPlayerLeave(p)
	default:
		scriptLog.Printf("event: %s (%x, %x)", ev, uintptr(a1), uintptr(a2))
	}
}
