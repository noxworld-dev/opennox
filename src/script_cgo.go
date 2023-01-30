package opennox

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/server"
)

func (s *Server) Nox_script_callByEventcgo(ev server.ScriptEventType, a1, a2 unsafe.Pointer) {
	switch ev {
	case server.NoxEventCollide, server.NoxEventMonsterCollide, server.NoxEventMonsterHearEnemy, server.NoxEventMonsterIsHit:
		// too frequent, don't log for now
	case server.NoxEventTriggerActivated:
		obj := asObject(a1)
		trig := asObject(a2)
		callOnTriggerActivated(trig, obj)
	case server.NoxEventTriggerDeactivated:
		trig := asObject(a2)
		callOnTriggerDeactivated(trig)
	case server.NoxEventMonsterDone:
		obj := asUnit(a2)
		callOnMonsterDone(obj)
	case server.NoxEventMonsterFightStart:
		targ := asUnit(a1)
		obj := asUnit(a2)
		callOnMonsterAttack(obj, targ)
	case server.NoxEventMonsterSeeEnemy:
		targ := asUnit(a1)
		obj := asUnit(a2)
		// TODO: inverse order?
		callOnMonsterSeeEnemy(obj, targ)
	case server.NoxEventMonsterLostEnemy:
		targ := asUnit(a1)
		obj := asUnit(a2)
		// TODO: inverse order?
		callOnMonsterLostEnemy(obj, targ)
	case server.NoxEventPolygonPlayerEnter:
		obj := asUnit(a1)
		scriptLog.Printf("secret YYY: %s", obj)
		callOnPolygonPlayerEnter(obj)
	case server.NoxEventPolygonEnterYYY:
		v1 := asUnit(a1)
		scriptLog.Printf("polygon YYY: %s", v1)
	case server.NoxEventMonsterIdle:
		obj := asUnit(a2)
		callOnMonsterIdle(obj)
	case server.NoxEventMonsterDead:
		obj := asUnit(a2)
		callOnMonsterDead(obj)
	case server.NoxEventPlayerJoin:
		p := legacy.AsPlayerP(a1)
		s.callOnPlayerJoin(asPlayerS(p))
	case server.NoxEventPlayerLeave:
		p := legacy.AsPlayerP(a1)
		s.callOnPlayerLeave(asPlayerS(p))
	default:
		scriptLog.Printf("event: %s (%x, %x)", ev, uintptr(a1), uintptr(a2))
	}
}
