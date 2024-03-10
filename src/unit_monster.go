package opennox

import (
	"math"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/spell"
	"github.com/noxworld-dev/opennox-lib/things"

	"github.com/noxworld-dev/opennox/v1/common/unit/ai"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/server"
)

func init() {
	server.RegisterObjectUpdate("MonsterUpdate", nox_xxx_unitUpdateMonster_50A5C0, unsafe.Sizeof(server.MonsterUpdateData{}))
}

var _ = [1]struct{}{}[248-unsafe.Sizeof(server.MonsterDef{})]

func objectMonsterInit(sobj *server.Object) {
	obj := asObjectS(sobj)
	s := obj.getServer()
	ud := obj.UpdateDataMonster()
	if !obj.Flags().HasAny(object.FlagDead | object.FlagDestroyed) {
		switch int(obj.TypeInd) {
		case s.Types.CarnivorousPlantID():
			obj.clearActionStack()
			ud.Field328 = float32(float64(ud.MonsterDef.MeleeAttackRange112+obj.Shape.Circle.R) + 10.0)
			ud.AIAction340 = uint32(ai.ACTION_GUARD)
		case s.Types.RatID():
			obj.clearActionStack()
			obj.monsterPushAction(ai.ACTION_RANDOM_WALK)
			ud.Aggression = 0.16
			ud.AIAction340 = uint32(ai.ACTION_INVALID)
		case s.Types.FishSmallID(), s.Types.FishBigID():
			obj.clearActionStack()
			obj.monsterPushAction(ai.ACTION_ROAM, 0, 0, 0xff)
			ud.Aggression = 0.16
			ud.AIAction340 = uint32(ai.ACTION_INVALID)
		case s.Types.GreenFrogID():
			obj.clearActionStack()
			obj.monsterPushAction(ai.ACTION_IDLE)
			ud.Aggression = 0.16
			ud.AIAction340 = uint32(ai.ACTION_INVALID)
			ud.StatusFlags |= object.MonStatusAlert
		case s.Types.NPCID():
			for i := 0; i < 6; i++ {
				if ud.Color[i] == (server.Color3{}) {
					cl := s.Rand.RandomColor3()
					nox_xxx_setNPCColor_4E4A90(obj.SObj(), byte(i), &cl)
				}
			}
		}
	}
	switch ai.ActionType(ud.AIAction340) {
	case ai.ACTION_ESCORT:
		obj.monsterPushAction(ai.ACTION_ESCORT, obj.Pos())
	case ai.ACTION_GUARD:
		obj.monsterPushAction(ai.ACTION_GUARD, obj.Pos(), int(obj.Direction1))
	case ai.ACTION_ROAM:
		if nox_xxx_monsterCanAttackAtWill_534390(obj) {
			obj.monsterPushAction(ai.ACTION_HUNT)
		} else {
			obj.monsterPushAction(ai.ACTION_ROAM, 0, 0, uint32(uint8(ud.Field333)))
		}
	case ai.ACTION_FIGHT:
		obj.monsterPushAction(ai.ACTION_FIGHT, obj.Pos(), uint32(s.Frame()))
	case ai.ACTION_INVALID:
		// nop
	default:
		if ud.AIStackInd < 0 {
			obj.monsterPushAction(ai.ACTION_IDLE)
		}
	}
	ud.AIAction340 = uint32(ai.ACTION_INVALID)
	ud.Direction94 = uint32(obj.Direction1)
	ud.Pos95 = obj.Pos()
	h := obj.HealthData
	if h.Cur == h.Max {
		legacy.Nox_xxx_unitSetHP_4E4560(obj.SObj(), uint16(float64(h.Max)*float64(ud.Field338)))
	}
	h.Field2 = h.Cur
	for i := range ud.HealthGraph103 {
		ud.HealthGraph103[i] = h.Cur
	}
	if obj.SubClass().AsMonster().HasAny(object.MonsterNPC | object.MonsterFemaleNPC) {
		obj.SpeedBase = float32(1.7 + float64(ud.Field332)*0.5)
	} else {
		obj.SpeedBase = float32(float64(obj.SpeedBase) * s.Rand.Logic.FloatClamp(0.94999999, 1.05))
	}
	if legacy.Nox_xxx_monsterCanCast_534300(obj.SObj()) {
		ud.FleeRange = 100
	}
	if ud.StatusFlags.Has(object.MonStatusHoldYourGround) {
		ud.FleeRange = 0
	}
	if ud.StatusFlags.Has(object.MonStatusAlwaysRun) {
		ud.StatusFlags |= object.MonStatusRunning
	}
}

func (obj *Object) monsterCast(spellInd spell.ID, target *server.Object) {
	s := obj.getServer()
	ud := obj.UpdateDataMonster()
	obj.monsterPushAction(ai.DEPENDENCY_UNINTERRUPTABLE)
	sp := s.SpellDefByInd(spellInd)
	if sp.Def.Flags.Has(things.SpellDuration) {
		ts := s.Frame() + uint32(s.Rand.Logic.IntClamp(int(s.TickRate()/2), int(2*s.TickRate())))
		obj.monsterPushAction(ai.DEPENDENCY_TIME, ts)
		obj.monsterPushAction(ai.ACTION_CAST_DURATION_SPELL, uint32(spellInd), 0, target)
	} else {
		obj.monsterPushAction(ai.ACTION_CAST_SPELL_ON_OBJECT, uint32(spellInd), 0, target)
	}
	if target.SObj() != obj.SObj() && !obj.monsterActionIsScheduled(ai.ACTION_FLEE) {
		if !sp.Def.Flags.Has(things.SpellTargeted) { // TODO: looks like the flag name is incorrect on our side
			obj.monsterPushAction(ai.ACTION_FACE_OBJECT, target)
			obj.monsterPushAction(ai.DEPENDENCY_BLOCKED_LINE_OF_FIRE, target)
		}
		obj.monsterPushAction(ai.DEPENDENCY_OBJECT_FARTHER_THAN, ud.MonsterDef.MissileAttackRange212, 0, target)
		obj.monsterPushAction(ai.DEPENDENCY_OR)
		obj.monsterPushAction(ai.ACTION_MOVE_TO, target.Pos(), target)
	}
}

func nox_xxx_monsterCast_540A30(cu *server.Object, spellInd int, a3p *server.Object) {
	asObjectS(cu).monsterCast(spell.ID(spellInd), a3p)
}

func nox_xxx_setNPCColor_4E4A90(obj *server.Object, ind byte, cl *server.Color3) {
	ud := obj.UpdateDataMonster()
	obj.NeedSync()
	ud.Color[ind] = *cl
	if obj.Class().HasAny(object.ClassClientPersist | object.ClassImmobile | object.ClassPlayer) {
		for i, v := range obj.Field140 {
			obj.Field140[i] = v&0xFFFFF000 | 0x4000000
		}
	} else {
		val := sub_4E4C90(obj, 0x400)
		sub_4E4500(obj, 0x4000000, 1024, val)
	}
}

func nox_xxx_monsterCreateFn_54C480(u *server.Object) {
	s := noxServer
	ud := u.UpdateDataMonster()
	name := s.Types.ByInd(int(u.TypeInd)).ID()
	ud.SoundSet122 = legacy.Nox_xxx_getDefaultSoundSet_424350(name)
	def := legacy.Nox_xxx_monsterDefByTT_517560(int(u.TypeInd))
	ud.MonsterDef = def
	if def != nil {
		h := u.HealthData
		u.Experience = float32(def.Experience64)
		h.Cur = uint16(def.Health68)
		h.Field2 = uint16(def.Health68)
		h.Max = uint16(def.Health68)
		speed := float64(def.Speed76) / 32
		u.SpeedBase = float32(speed)
		u.SpeedCur = float32(speed)
		ud.RetreatLevel = def.RetreatRatio80
		ud.Field335 = 1
		ud.ResumeLevel = def.ResumeRatio84
		ud.Field337 = 1
		ud.StatusFlags = def.StatusFlags92
		ud.Field361 = 1
		ud.FleeRange = def.FleeRange88
	}
	ud.AIStackInd = 0
	ud.AIStack[0].Action = ai.ACTION_IDLE
	ud.AIAction340 = 0
	ud.Aggression = 0.5
	ud.Aggression2 = 0.5
	ud.Field330 = 0.5
	ud.Field332 = 0.5
	ud.Field328 = 150.0
	ud.Field329 = 30.0
	ud.Field333 = math.MaxUint8
	ud.Field331 = 30
	ud.Field338 = 1.0

	ud.ScriptLookingForEnemy = server.ScriptCallback{Func: -1}
	ud.ScriptEnemySighted = server.ScriptCallback{Func: -1}
	ud.ScriptChangeFocus = server.ScriptCallback{Func: -1}
	ud.ScriptIsHit = server.ScriptCallback{Func: -1}
	ud.ScriptRetreat = server.ScriptCallback{Func: -1}
	ud.ScriptDeath = server.ScriptCallback{Func: -1}
	ud.ScriptCollision = server.ScriptCallback{Func: -1}
	ud.ScriptHearEnemy = server.ScriptCallback{Func: -1}
	ud.ScriptEndOfWaypoint = server.ScriptCallback{Func: -1}
	ud.ScriptLostEnemy = server.ScriptCallback{Func: -1}

	fps := s.TickRate()
	ud.SpellLvl510 = 1
	ud.Field362_0 = 0
	ud.Field362_2 = uint16(fps / 2)
	ud.Field364_0 = uint16(fps * 3)
	ud.Field364_2 = uint16(fps * 10)
	ud.Field366_0 = uint16(fps * 3)
	ud.Field366_2 = uint16(fps * 6)
	ud.Field368_0 = 0
	ud.Field368_2 = uint16(fps * 3)
	ud.Field370_0 = 0
	ud.Field370_2 = uint16(fps * 6)
	ud.DialogStartFunc = -1
	ud.DialogEndFunc = -1
	ud.Field0 = 0xDEADFACE
	legacy.Nox_xxx_monsterAutoSpells_54C0C0(u)
	if u.SubClass().AsMonster().Has(object.MonsterShopkeeper) {
		idata := u.InitDataShopkeeper()
		idata.Field1716 = 1.0
		idata.Field1720 = 0.33333
	}
	if u.SubClass().AsMonster().Has(object.MonsterFemaleNPC) {
		for i := range ud.Color {
			ud.Color[i] = server.Color3{R: 210, G: 174, B: 121}
		}
	}
	ud.Field1 = 0
	ud.Field72 = 0
	ud.Field73 = 0
}
