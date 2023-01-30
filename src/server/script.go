package server

import "fmt"

type ScriptEventType int

const (
	NoxEventCollide            = ScriptEventType(1)  // 1+2
	NoxEventGeneratorSpawn     = ScriptEventType(2)  // 1+2
	NoxEventGeneratorDead      = ScriptEventType(3)  // 1+2
	NoxEventMonsterMoveXXX     = ScriptEventType(4)  // 2
	NoxEventMonsterIdle        = ScriptEventType(5)  // 2
	NoxEventMonsterDone        = ScriptEventType(6)  // 2
	NoxEventMonsterDead        = ScriptEventType(7)  // 2
	NoxEventTriggerActivated   = ScriptEventType(8)  // 1+2
	NoxEventTriggerDeactivated = ScriptEventType(9)  // 2
	NoxEventToggleXXX          = ScriptEventType(10) // 1+2
	NoxEventToggleYYY          = ScriptEventType(11) // 2
	NoxEventMonsterYYY         = ScriptEventType(12) // 1+2
	NoxEventMonsterFightStart  = ScriptEventType(13) // 1+2
	NoxEventMonsterSeeEnemy    = ScriptEventType(14) // 1+2
	NoxEventMonsterLostEnemy   = ScriptEventType(15) // 1+2
	NoxEventMonsterHearEnemy   = ScriptEventType(16) // 1+2 -- unit, heardMonster, raycastDistance
	NoxEventMonsterIsHit       = ScriptEventType(17) // 1+2
	NoxEventInventoryPlace     = ScriptEventType(18) // 1+2
	NoxEventGeneratorCollide   = ScriptEventType(19) // 1+2
	NoxEventTrapdoorCollide    = ScriptEventType(20) // 1+2
	NoxEventBombCollide        = ScriptEventType(21) // 1+2
	NoxEventMonsterCollide     = ScriptEventType(22) // 1+2
	NoxEventGeneratorDamage    = ScriptEventType(23) // 1+2
	NoxEventPolygonEnterXXX    = ScriptEventType(24) // 1
	NoxEventPolygonEnterYYY    = ScriptEventType(25) // 1
	NoxEventPolygonEnterZZZ    = ScriptEventType(26) // 1
	NoxEventPolygonPlayerXXX   = ScriptEventType(27) // 1
	NoxEventPolygonPlayerEnter = ScriptEventType(28) // 1
	NoxEventPolygonPlayerZZZ   = ScriptEventType(29) // 1
	NoxEventPlayerJoin         = ScriptEventType(30) // 1
	NoxEventPlayerLeave        = ScriptEventType(31) // 1
)

func (ev ScriptEventType) String() string {
	switch ev {
	case 0:
		return "UnknownEvent"
	case NoxEventCollide:
		return "Collide"
	case NoxEventGeneratorSpawn:
		return "GeneratorSpawn"
	case NoxEventGeneratorDead:
		return "GeneratorDead"
	case NoxEventMonsterMoveXXX:
		return "MonsterMoveXXX"
	case NoxEventMonsterIdle:
		return "MonsterIdle"
	case NoxEventMonsterDone:
		return "MonsterDone"
	case NoxEventMonsterDead:
		return "MonsterDead"
	case NoxEventTriggerActivated:
		return "TriggerActivated"
	case NoxEventTriggerDeactivated:
		return "TriggerDeactivated"
	case NoxEventToggleXXX:
		return "ToggleXXX"
	case NoxEventToggleYYY:
		return "ToggleYYY"
	case NoxEventMonsterYYY:
		return "MonsterYYY"
	case NoxEventMonsterFightStart:
		return "MonsterFightStart"
	case NoxEventMonsterSeeEnemy:
		return "MonsterSeeEnemy"
	case NoxEventMonsterLostEnemy:
		return "MonsterLostEnemy"
	case NoxEventMonsterHearEnemy:
		return "MonsterHearEnemy"
	case NoxEventMonsterIsHit:
		return "MonsterZZZ"
	case NoxEventInventoryPlace:
		return "InventoryPlace"
	case NoxEventGeneratorCollide:
		return "GeneratorCollide"
	case NoxEventTrapdoorCollide:
		return "TrapdoorCollide"
	case NoxEventBombCollide:
		return "BombCollide"
	case NoxEventMonsterCollide:
		return "MonsterCollide"
	case NoxEventGeneratorDamage:
		return "GeneratorDamage"
	case NoxEventPolygonEnterXXX:
		return "PolygonEnterXXX"
	case NoxEventPolygonEnterYYY:
		return "PolygonEnterYYY"
	case NoxEventPolygonEnterZZZ:
		return "PolygonEnterZZZ"
	case NoxEventPolygonPlayerXXX:
		return "PolygonPlayerXXX"
	case NoxEventPolygonPlayerEnter:
		return "PolygonPlayerEnter"
	case NoxEventPolygonPlayerZZZ:
		return "PolygonPlayerZZZ"
	default:
		return fmt.Sprintf("server.ScriptEventType(%d)", int(ev))
	}
}
