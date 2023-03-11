package opennox

import (
	"github.com/noxworld-dev/opennox/v1/server"
)

func (s *Server) Nox_script_event_playerLeave(pl *server.Player) {
	s.callOnPlayerLeave(asPlayerS(pl))
}

func (s *noxScript) scriptCallByEvent(ev server.ScriptEventType, a1, a2 *Object) {
	switch ev {
	case server.NoxEventCollide, server.NoxEventMonsterCollide, server.NoxEventMonsterHearEnemy, server.NoxEventMonsterIsHit:
		// too frequent, don't log for now
	case server.NoxEventTriggerActivated:
		obj := a1
		trig := a2
		callOnTriggerActivated(trig, obj)
	case server.NoxEventTriggerDeactivated:
		trig := a2
		callOnTriggerDeactivated(trig)
	case server.NoxEventMonsterDone:
		obj := a2
		callOnMonsterDone(obj)
	case server.NoxEventMonsterFightStart:
		targ := a1
		obj := a2
		callOnMonsterAttack(obj, targ)
	case server.NoxEventMonsterSeeEnemy:
		targ := a1
		obj := a2
		// TODO: inverse order?
		callOnMonsterSeeEnemy(obj, targ)
	case server.NoxEventMonsterLostEnemy:
		targ := a1
		obj := a2
		// TODO: inverse order?
		callOnMonsterLostEnemy(obj, targ)
	case server.NoxEventPolygonPlayerEnter:
		obj := a1
		scriptLog.Printf("secret YYY: %s", obj)
		callOnPolygonPlayerEnter(obj)
	case server.NoxEventPolygonEnterYYY:
		v1 := a1
		scriptLog.Printf("polygon YYY: %s", v1)
	case server.NoxEventMonsterIdle:
		obj := a2
		callOnMonsterIdle(obj)
	case server.NoxEventMonsterDead:
		obj := a2
		callOnMonsterDead(obj)
	}
}
