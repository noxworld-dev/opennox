package opennox

import (
	"github.com/noxworld-dev/opennox/v1/server"
)

func (s *Server) Nox_script_event_playerLeave(pl *server.Player) {
	s.CallOnPlayerLeave(scrPlayer{pl})
}

func (s *noxScript) scriptCallByEvent(ev server.ScriptEventType, a1, a2 *server.Object) {
	switch ev {
	case server.NoxEventCollide, server.NoxEventMonsterCollide, server.NoxEventMonsterHearEnemy, server.NoxEventMonsterIsHit:
		// too frequent, don't log for now
	case server.NoxEventTriggerActivated:
		obj := a1
		trig := a2
		trig.CallOnTriggerActivated(scrObject{asObjectS(obj)})
	case server.NoxEventTriggerDeactivated:
		trig := a2
		trig.CallOnTriggerDeactivated()
	case server.NoxEventMonsterDone:
		obj := a2
		obj.CallOnMonsterDone()
	case server.NoxEventMonsterFightStart:
		targ := a1
		obj := a2
		obj.CallOnMonsterAttack(scrObject{asObjectS(targ)})
	case server.NoxEventMonsterSeeEnemy:
		targ := a1
		obj := a2
		// TODO: inverse order?
		obj.CallOnMonsterSeeEnemy(scrObject{asObjectS(targ)})
	case server.NoxEventMonsterLostEnemy:
		targ := a1
		obj := a2
		// TODO: inverse order?
		obj.CallOnMonsterLostEnemy(scrObject{asObjectS(targ)})
	case server.NoxEventPolygonPlayerEnter:
		obj := a1
		ScriptLog.Printf("secret YYY: %s", obj)
		obj.CallOnPolygonPlayerEnter()
	case server.NoxEventPolygonEnterYYY:
		v1 := a1
		ScriptLog.Printf("polygon YYY: %s", v1)
	case server.NoxEventMonsterIdle:
		obj := a2
		obj.CallOnMonsterIdle()
	case server.NoxEventMonsterDead:
		obj := a2
		obj.CallOnMonsterDead()
	}
}
