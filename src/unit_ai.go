package opennox

/*
#include "defs.h"
#include "GAME1_1.h"
#include "GAME3_3.h"
#include "GAME4.h"
#include "GAME4_1.h"
#include "GAME4_2.h"
#include "GAME4_3.h"
#include "GAME5.h"
#include "server__script__script.h"
extern unsigned int dword_5d4594_2489460;
*/
import "C"

import (
	"fmt"
	"math"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/spell"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/common/unit/ai"
	"github.com/noxworld-dev/opennox/v1/server"
)

func init() {
	server.RegisterAIAction(AIActionIdle{})
	server.RegisterAIAction(AIActionWait{})
	server.RegisterAIAction(AIActionWaitRel{})
	server.RegisterAIAction(AIActionCastOnObj{})
	server.RegisterAIAction(AIActionCastOnPos{})
	server.RegisterAIAction(AIActionCastDuration{})
	server.RegisterAIAction(AIActionDropObj{})
	server.RegisterAIAction(AIActionFindObj{})
	server.RegisterAIAction(AIActionMorphIntoChest{})
	server.RegisterAIAction(AIActionMorphBackToSelf{})
	for typ, a := range map[ai.ActionType]struct {
		Start, Update, End, Cancel unsafe.Pointer
	}{
		ai.ACTION_ESCORT:            {Update: C.nox_xxx_mobActionEscort_546430, End: C.sub_546410, Cancel: C.sub_546420},
		ai.ACTION_GUARD:             {Update: C.nox_xxx_mobActionGuard_546010},
		ai.ACTION_HUNT:              {Update: C.nox_xxx_mobActionHunt_5449D0},
		ai.ACTION_RETREAT:           {Update: C.nox_xxx_mobActionRetreat_545440},
		ai.ACTION_MOVE_TO:           {Update: C.nox_xxx_mobActionMoveTo_5443F0},
		ai.ACTION_FAR_MOVE_TO:       {Update: C.nox_xxx_mobActionMoveToFar_5445C0},
		ai.ACTION_DODGE:             {Update: C.nox_xxx_mobActionDodge_544640},
		ai.ACTION_ROAM:              {Start: C.sub_545790, Update: C.nox_xxx_mobActionRoam_5457E0, Cancel: C.sub_5457C0},
		ai.ACTION_PICKUP_OBJECT:     {Update: C.nox_xxx_mobActionPickupObject_544B90},
		ai.ACTION_RETREAT_TO_MASTER: {Start: C.sub_5456B0, Update: C.sub_5456D0, End: C.sub_5456C0},
		ai.ACTION_FIGHT:             {Start: C.nox_xxx_mobActionFightStart_531E20, Update: C.nox_xxx_mobActionFight_531EC0, End: C.sub_531E90},
		ai.ACTION_MELEE_ATTACK:      {Start: C.nox_xxx_mobActionMelee1_532130, Update: C.nox_xxx_mobActionMeleeAtt_532440, Cancel: C.nox_ai_action_pop_532100},
		ai.ACTION_MISSILE_ATTACK:    {Start: C.sub_532540, Update: C.nox_xxx_mobActionMissileAtt_532610, Cancel: C.nox_ai_action_pop_532100},
		ai.ACTION_BLOCK_ATTACK:      {Update: C.nox_xxx_monsterShieldBlockStart_532070, Cancel: C.nox_ai_action_pop_532100},
		ai.ACTION_BLOCK_FINISH:      {Update: C.nox_xxx_monsterShieldBlockStop_5320E0, Cancel: C.nox_ai_action_pop_532100},
		ai.ACTION_WEAPON_BLOCK:      {Update: C.sub_532110, Cancel: C.nox_ai_action_pop_532100},
		ai.ACTION_FLEE:              {Start: C.sub_544740, Update: C.nox_xxx_mobActionFlee_544760, End: C.sub_544750},
		ai.ACTION_FACE_LOCATION:     {Update: C.sub_545210, Cancel: C.nox_ai_action_pop_532100},
		ai.ACTION_FACE_OBJECT:       {Update: C.sub_545300, Cancel: C.nox_ai_action_pop_532100},
		ai.ACTION_FACE_ANGLE:        {Update: C.sub_545340, Cancel: C.nox_ai_action_pop_532100},
		ai.ACTION_SET_ANGLE:         {Update: C.sub_5453E0, Cancel: C.nox_ai_action_pop_532100},
		ai.ACTION_RANDOM_WALK:       {Update: C.nox_xxx_mobActionRandomWalk_545020},
		ai.ACTION_DYING:             {Start: C.nox_xxx_mobGenericDeath_544C40, Update: C.sub_544D60, End: C.nox_xxx_zombieBurnDeleteCheck_544CA0},
		ai.ACTION_DEAD:              {Start: C.nox_xxx_mobActionDead1_544D80, Update: C.nox_xxx_mobActionDead2_544EC0},
		ai.ACTION_REPORT:            {Update: C.nox_xxx_mobActionReportComplete_544FF0},
		ai.ACTION_GET_UP:            {Update: C.nox_xxx_mobActionGetUp_534A90},
		ai.ACTION_CONFUSED:          {Update: C.nox_xxx_mobActionConfuse_545140},
		ai.ACTION_MOVE_TO_HOME:      {Start: C.nox_xxx_mobActionReturnToHome_544920, Update: C.sub_544950, End: C.sub_544930, Cancel: C.sub_544940},
	} {
		server.RegisterAIAction(cgoAIAction{typ: typ, start: a.Start, update: a.Update, end: a.End, cancel: a.Cancel})
	}
}

type aiData struct {
	s                  *Server
	allocListen        alloc.ClassT[MonsterListen]
	listenHead         *MonsterListen
	soundMuteThreshold int
	lastHeard          types.Pointf
	stackChanged       bool
}

func (a *aiData) Init(s *Server) {
	a.s = s
}

//export nox_ai_debug_print
func nox_ai_debug_print(str *C.char) {
	ai.Log.Printf("%s", GoString(str))
}

func aiStackSetArgs(s *server.AIStackItem, args ...any) {
	if s == nil {
		return
	}
	off := 0
	for _, v := range args {
		switch v := v.(type) {
		case int:
			s.Args[off] = uintptr(uint32(int32(v)))
		case uint32:
			s.Args[off] = uintptr(v)
		case unsafe.Pointer:
			s.Args[off] = uintptr(v)
		case float32:
			s.Args[off] = uintptr(math.Float32bits(v))
		case noxObject:
			s.Args[off] = uintptr(unsafe.Pointer(toCObj(v)))
		case types.Pointf:
			s.Args[off+0] = uintptr(math.Float32bits(v.X))
			off++
			s.Args[off+1] = uintptr(math.Float32bits(v.Y))
		default:
			panic(fmt.Errorf("unsupported arg: %T", v))
		}
		off++
	}
}

func aiStackArgObj(s *server.AIStackItem, i int) *Object {
	return asObject(unsafe.Pointer(s.Args[i]))
}

func aiStackArgUnit(s *server.AIStackItem, i int) *Unit {
	return asUnit(unsafe.Pointer(s.Args[i]))
}

func (u *Unit) maybePrintAIStack(event string) {
	if noxflags.HasEngine(noxflags.EngineShowAI) {
		u.UpdateDataMonster().PrintAIStack(u.getServer().Frame(), event)
	}
}

func (a *aiData) nox_xxx_mobActionDependency(u *Unit) {
	ud := u.UpdateDataMonster()
	stack := ud.GetAIStack()
	if len(stack) == 0 {
		return
	}
	isOR := false
	okPrev := false
	for i := len(stack) - 1; i >= 0; i-- {
		ok := true
		st := &stack[i]
		typ := st.Type()
		if !typ.IsCondition() {
			isOR = false
			continue
		}
		switch typ {
		case ai.DEPENDENCY_OR:
			isOR = true
			okPrev = false
			continue
		case ai.DEPENDENCY_TIME:
			ok = st.ArgU32(0) > a.s.Frame()
		case ai.DEPENDENCY_ALIVE:
			obj := aiStackArgObj(st, 0)
			h := obj.HealthData
			if obj == nil || !obj.Class().HasAny(object.MaskUnits) || (h.Cur == 0) && h.Max != 0 {
				ok = false
				ud.Field97 = 0
				ud.Field101 = a.s.Frame() + a.s.TickRate()
			}
		case ai.DEPENDENCY_UNDER_ATTACK:
			if sub_5347A0(u) {
				if u.Obj130 != nil {
					v26 := getOwnerUnit(asObjectS(u.Obj130))
					if v26 != nil && v26.Class().HasAny(object.MaskUnits) {
						st.Args[0] = uintptr(a.s.Frame())
					}
				}
			}
			ok = a.s.Frame()-st.ArgU32(0) <= 10*a.s.TickRate()
		case ai.DEPENDENCY_NOT_UNDER_ATTACK:
			if !sub_5347A0(u) {
				break
			}
			if u.Obj130 == nil {
				break
			}
			attacker := getOwnerUnit(asObjectS(u.Obj130))
			if attacker == nil {
				break
			}
			if attacker.Class().HasAny(object.MaskUnits) {
				ok = false
			}
		case ai.DEPENDENCY_CAN_SEE:
			obj := aiStackArgObj(st, 0)
			if obj == nil || !nox_xxx_unitCanInteractWith_5370E0(u, obj, 0) {
				ok = false
			}
		case ai.DEPENDENCY_CANNOT_SEE:
			obj := aiStackArgObj(st, 0)
			if obj == nil || C.sub_533360(u.CObj(), obj.CObj()) != 0 {
				ok = false
			}
		case ai.DEPENDENCY_BLOCKED_LINE_OF_FIRE:
			obj := aiStackArgObj(st, 0)
			if obj == nil {
				ok = false
				break
			}
			pos, pos2 := u.Pos(), obj.Pos()
			ok = !nox_xxx_mapTraceObstacles(u, pos, pos2)
		case ai.DEPENDENCY_OBJECT_AT_VISIBLE_LOCATION:
			v28 := aiStackArgObj(st, 2)
			v29 := false
			if v28 != nil && nox_xxx_unitCanInteractWith_5370E0(u, v28, 0) {
				v29 = true
				pos := v28.Pos()
				st.Args[0] = uintptr(math.Float32bits(pos.X))
				st.Args[1] = uintptr(math.Float32bits(pos.Y))
			}
			if a.s.MapTraceRay(u.Pos(), st.ArgPos(0), MapTraceFlag1); !v29 {
				ok = false
			}
		case ai.DEPENDENCY_OBJECT_FARTHER_THAN:
			obj, r := aiStackArgObj(st, 2), st.ArgF32(0)
			ok = obj != nil && nox_xxx_calcDistance_4E6C00(u, obj) > r
		case ai.DEPENDENCY_OBJECT_CLOSER_THAN:
			obj, r := aiStackArgObj(st, 2), st.ArgF32(0)
			ok = obj != nil && nox_xxx_calcDistance_4E6C00(u, obj) <= r
		case ai.DEPENDENCY_LOCATION_FARTHER_THAN:
			pos := u.Pos()
			pos2 := st.ArgPos(2)
			dx := pos2.X - pos.X
			dy := pos2.Y - pos.Y
			ok = float32(math.Sqrt(float64(dy*dy+dx*dx))) >= st.ArgF32(0)
		case ai.DEPENDENCY_LOCATION_CLOSER_THAN:
			pos := u.Pos()
			pos2 := st.ArgPos(2)
			dx := pos2.X - pos.X
			dy := pos2.Y - pos.Y
			ok = float32(math.Sqrt(float64(dy*dy+dx*dx))) <= st.ArgF32(0)
		case ai.DEPENDENCY_VISIBLE_ENEMY:
			ok = ud.CurrentEnemy != nil
		case ai.DEPENDENCY_NO_VISIBLE_ENEMY:
			ok = ud.CurrentEnemy == nil
		case ai.DEPENDENCY_NO_VISIBLE_FOOD:
			r := 250.0
			if noxflags.HasGame(noxflags.GameModeQuest) {
				r = 640.0
			}
			ok = C.nox_xxx_mobSearchEdible_544A00(u.CObj(), C.float(r)) == 0
		case ai.DEPENDENCY_NO_INTERESTING_SOUND:
			if ud.Field97 != 0 && a.s.Frame()-ud.Field101 < 3*a.s.TickRate() {
				ok = false
			}
		case ai.DEPENDENCY_NO_NEW_ENEMY:
			old := aiStackArgUnit(st, 0)
			if old == nil {
				ok = false
				break
			}
			enemy := asUnitS(ud.CurrentEnemy)
			if enemy == nil {
				break
			}
			pos := u.Pos()

			pos2 := old.Pos()
			dx1 := pos2.X - pos.X
			dy1 := pos2.Y - pos.Y
			rOld := dx1*dx1 + dy1*dy1

			pos3 := enemy.Pos()
			dx2 := pos3.X - pos.X
			dy2 := pos3.Y - pos.Y
			rNew := dx2*dx2 + dy2*dy2

			ok = rNew >= rOld
		case ai.DEPENDENCY_UNINTERRUPTABLE:
			return
		case ai.DEPENDENCY_IS_ENCHANTED:
			ok = u.HasEnchant(server.EnchantID(st.Args[0]))
		case ai.DEPENDENCY_ENEMY_CLOSER_THAN:
			enemy := asUnitS(ud.CurrentEnemy)
			ok = enemy != nil && nox_xxx_calcDistance_4E6C00(u, enemy) <= st.ArgF32(0)
		case ai.DEPENDENCY_NOT_HEALTHY:
			h := u.HealthData
			perc := float32(1.0)
			if h.Max != 0 {
				perc = float32(h.Cur) / float32(h.Max)
			}
			if perc >= ud.Field336 {
				ok = false
			}
		case ai.DEPENDENCY_WAIT_FOR_STAMINA:
			if C.int(ud.Field282_0) >= C.nox_xxx_weaponGetStaminaByType_4F7E80(C.int(ud.Field514)) {
				ok = false
			}
		case ai.DEPENDENCY_ENEMY_FARTHER_THAN:
			enemy := asUnitS(ud.CurrentEnemy)
			if enemy != nil && nox_xxx_calcDistance_4E6C00(u, enemy) < st.ArgF32(0) {
				ok = false
			}
		case ai.DEPENDENCY_UNDER_CURSOR:
			hu := HostPlayerUnit()
			if hu == nil || C.nox_xxx_findObjectAtCursor_54AF40(hu.CObj()) != u.CObj() {
				ok = false
			}
		case ai.DEPENDENCY_NOT_CORNERED:
			ok = C.nox_xxx_mobGetMoveAttemptTime_534810(u.CObj()) == 0
		case ai.DEPENDENCY_LOCATION_IS_SAFE:
			C.dword_5d4594_2489460 = 1
			a.s.Map.EachObjInCircle(st.ArgPos(0), 50.0, func(it *server.Object) {
				C.nox_xxx_unitIsDangerous_547120(asUnitS(it).CObj(), u.CObj())
			})
			if C.dword_5d4594_2489460 == 0 {
				ok = false
			}
		case ai.DEPENDENCY_NOT_FRUSTRATED:
			if ud.Field360&0x200000 != 0 {
				ok = false
				ud.Field360 &= 0xFFDFFFFF
			}
		case ai.DEPENDENCY_NOT_MOVED:
			ok = u.Pos() == u.PrevPos
		}
		if !isOR {
			if ok {
				continue
			}
			// failed, pop actions
		} else {
			if ok {
				okPrev = true
			}
			if i > 0 {
				if stack[i-1].Type().IsCondition() {
					continue
				}
			}
			if okPrev {
				continue
			}
		}
		if noxflags.HasEngine(noxflags.EngineShowAI) {
			ai.Log.Printf("%d: %s DEPENDENCY '%s'@%d failed, popping:\n", a.s.Frame(), u.String(), typ.String(), i)
		}
		for {
			u.monsterPopAction()
			if !(int(ud.AIStackInd) >= i && C.sub_5341F0(u.CObj()) == 0) {
				break
			}
		}
		stack = ud.GetAIStack()
		i = len(stack) - 1
		u.monsterActionReset()
		u.maybePrintAIStack("procDep")
	}
}

func nox_xxx_checkMobAction_50A0D0(u *Unit, act ai.ActionType) bool {
	return C.nox_xxx_checkMobAction_50A0D0(u.CObj(), C.int(act)) != 0
}

//export sub_545E60
func sub_545E60(a1c *nox_object_t) C.int {
	u := asUnitC(a1c)
	s := u.getServer()

	ud := u.UpdateDataMonster()
	ts := u.Field134
	if ud.Field129 >= ts || s.Frame()-ts >= 10*s.TickRate() {
		return 0
	}
	ud.Field129 = ts
	if u.Obj130 != nil {
		if obj4 := getOwnerUnit(asObjectS(u.Obj130)); obj4 != nil {
			if !u.isEnemyTo(obj4) {
				return 0
			}
			canInteract := nox_xxx_unitCanInteractWith_5370E0(u, obj4, 0)
			if u.isPlant() {
				if !canInteract {
					return 0
				}
				u.monsterPushAction(ai.DEPENDENCY_ENEMY_CLOSER_THAN, float32(ud.Field328)*1.05)
			} else {
				u.monsterPushAction(ai.DEPENDENCY_UNDER_ATTACK, s.Frame())
			}
			u.monsterPushAction(ai.ACTION_FIGHT, obj4.Pos(), s.Frame())
			if !canInteract {
				u.monsterPushAction(ai.DEPENDENCY_NO_VISIBLE_ENEMY)
				if nox_xxx_monsterCanAttackAtWill_534390(u) {
					u.monsterPushAction(ai.DEPENDENCY_NO_INTERESTING_SOUND)
				}
				u.monsterPushAction(ai.ACTION_MOVE_TO, obj4.Pos(), 0)
			}
			return 1
		}
	}
	if !nox_xxx_checkMobAction_50A0D0(u, ai.ACTION_ROAM) {
		u.monsterPushAction(ai.DEPENDENCY_TIME, 5*s.TickRate())
		u.monsterPushAction(ai.DEPENDENCY_NO_VISIBLE_ENEMY)
		if nox_xxx_monsterCanAttackAtWill_534390(u) {
			u.monsterPushAction(ai.DEPENDENCY_NO_INTERESTING_SOUND)
		}
		u.monsterPushAction(ai.ACTION_ROAM, 0, 0, -128)
	}
	return 0
}

var _ = [1]struct{}{}[24-unsafe.Sizeof(MonsterListen{})]

type MonsterListen struct {
	snd   sound.ID       // 0, 0
	obj   *Object        // 1, 4
	pos   types.Pointf   // 2, 8
	frame uint32         // 4, 16
	next  *MonsterListen // 5, 20
}

//export sub_50D1C0
func sub_50D1C0() {
	noxServer.ai.Reset()
}

func (a *aiData) Reset() {
	a.allocListen.FreeAllObjects()
	//allocMonsterListen.Class = nil
	a.listenHead = nil
}

func (a *aiData) Free() {
	if a.allocListen.Class != nil {
		a.allocListen.Free()
	}
	a.listenHead = nil
}

func (a *aiData) NewSound(snd sound.ID, obj *Object, pos types.Pointf) {
	if a.s.Audio.Flags(snd) == 0 {
		return
	}
	if a.allocListen.Class == nil {
		a.allocListen = alloc.NewClassT("MonsterListen", MonsterListen{}, 128)
	}
	if getOwnerUnit(obj) == nil {
		return
	}

	p := a.allocListen.NewObject()
	if p == nil {
		return
	}
	*p = MonsterListen{
		snd:   snd,
		obj:   obj,
		pos:   pos,
		frame: a.s.Frame(),
	}
	p.next = a.listenHead
	a.listenHead = p
}

func getOwnerUnit(obj *Object) *Object {
	for it := obj; it != nil; it = it.OwnerC() {
		if it.Class().HasAny(object.MaskUnits) {
			return it
		}
	}
	return nil
}

func (a *aiData) aiListenToSounds(u *Unit) {
	// Not sure about this check. If unit is invulnerable, don't listen for anything?
	// Is present in vanilla though, so this might be some kind of weird fix for strange behaviour
	if C.nox_xxx_checkIsKillable_528190(u.CObj()) == 0 {
		return
	}

	// Do not listen to anything if you are a fish, frog or rat
	if u.isFish() || u.isFrog() || u.isRat() {
		return
	}

	var (
		prev     *MonsterListen
		next     *MonsterListen
		maxHeard *MonsterListen
		maxDist  int
	)
	ud := u.UpdateDataMonster()
	for it := a.listenHead; it != nil; it = next {
		next = it.next
		if a.s.Frame() < it.frame || a.s.Frame()-it.frame > 2 {
			if prev != nil {
				prev.next = next
			} else {
				a.listenHead = it.next
			}
			a.allocListen.FreeObjectFirst(it)
		} else {
			if it.obj != nil && it.obj.Flags().Has(object.FlagDestroyed) {
				it.obj = nil
			}
			if ud.Field101 <= it.frame && a.shouldUnitListen(u, it) {
				dist := a.traceSound(u, it)
				// This finds the farthest?
				if dist > 0 && dist > maxDist {
					maxDist = dist
					maxHeard = it
				}
			}
			prev = it
		}
	}
	if maxHeard != nil && (maxHeard.frame > ud.Field101 || maxDist > int(ud.Field102)) {
		a.nox_xxx_unitEmitHearEvent_50D110(u, maxHeard, maxDist)
	}
}

func (a *aiData) traceSound(u *Unit, p *MonsterListen) int {
	flags := a.s.Audio.Flags(p.snd)
	perc := a.soundFadePerc(p.snd, p.pos, u.Pos())
	if !a.checkSoundThreshold(flags, perc) {
		return -1
	}
	if !a.s.MapTraceRayAt(u.Pos(), p.pos, nil, nil, 5) {
		perc = int(float64(perc) * 0.5)
	}
	if !a.checkSoundThreshold(flags, perc) {
		return -1
	}
	return perc
}

//export nox_xxx_gameSetAudioFadeoutMb_501AC0
func nox_xxx_gameSetAudioFadeoutMb_501AC0(v C.int) {
	noxServer.ai.nox_xxx_gameSetAudioFadeoutMb(int(v))
}

func (a *aiData) nox_xxx_gameSetAudioFadeoutMb(v int) {
	v = clamp(v, 0, 100)
	a.soundMuteThreshold = v
}

func (a *aiData) soundFadePerc(snd sound.ID, p1, p2 types.Pointf) int {
	max := a.s.Audio.MaxDist(snd)
	if max <= 0 {
		return 0
	}
	dx := float64(p1.X - p2.X)
	dy := float64(p1.Y - p2.Y)
	if abs(dx) >= float64(max) || abs(dy) >= float64(max) {
		return 0
	}
	dist := int(math.Sqrt(dy*dy + dx*dx + 0.1))
	if dist >= max {
		return 0
	}
	v := 100 * (max - dist) / max
	v = clamp(v, 0, 100)
	if v <= a.soundMuteThreshold {
		return 0
	}
	return v
}

func (a *aiData) checkSoundThreshold(flags, perc int) bool {
	threshold := 50
	if flags&0x20 != 0 { // walk?
		threshold = 89
	} else if flags&0x40 != 0 { // run?
		threshold = 20
	}
	return perc >= threshold
}

func (a *aiData) shouldUnitListen(u *Unit, lis *MonsterListen) bool {
	ud := u.UpdateDataMonster()
	punit := lis.obj.FindOwnerChainPlayer()
	flags := a.s.Audio.Flags(lis.snd)
	if ud.Field101 > a.s.Frame() {
		return false
	}
	if punit == nil {
		if flags == 0 {
			return false
		}
	} else {
		if u.isEnemyTo(punit) {
			if flags == 0 {
				return false
			}
		} else if flags&0x10 == 0 {
			return false
		}
	}
	cp, free := alloc.New(types.Pointf{})
	defer free()
	*cp = lis.pos
	if v12 := C.sub_501C00((*C.float)(unsafe.Pointer(cp)), lis.obj.CObj()); v12 != 0 {
		pos := u.Pos()
		cpi, free := alloc.Make([]int32{}, 2)
		defer free()
		cpi[0] = int32(pos.X)
		cpi[1] = int32(pos.Y)
		resp := C.nox_xxx_polygonIsPlayerInPolygon_4217B0((*C.int2)(unsafe.Pointer(&cpi[0])), 0)
		if resp != nil && byte(v12) != *(*byte)(unsafe.Add(unsafe.Pointer(&resp.field_0[32]), 2)) {
			return false
		}
	}
	return true
}

func (a *aiData) nox_xxx_unitEmitHearEvent_50D110(u *Unit, lis *MonsterListen, dist int) {
	ud := u.UpdateDataMonster()
	ud.Field97 = uint32(lis.snd)
	ud.Field101 = a.s.Frame()
	ud.Field102 = uint32(dist)
	if lis.obj != nil {
		ud.Field98 = lis.obj.NetCode
	} else {
		ud.Field98 = 0
	}
	ud.Field99X = lis.pos.X
	ud.Field99Y = lis.pos.Y
	a.lastHeard = lis.pos
	obj5 := lis.obj.FindOwnerChainPlayer()
	// EventID 16 is MonsterHearsEnemy
	a.s.scriptCallback(&ud.ScriptHearEnemy, obj5, u.AsObject(), noxEventMonsterHearEnemy)
}

func (a *aiData) lastHeardEvent() types.Pointf {
	return a.lastHeard
}

//export nox_xxx_monsterPopAction_50A160
func nox_xxx_monsterPopAction_50A160(a1 *nox_object_t) int {
	return asUnitC(a1).monsterPopAction()
}

func (u *Unit) monsterPopAction() int {
	s := u.getServer()
	ud := u.UpdateDataMonster()
	if noxflags.HasEngine(noxflags.EngineShowAI) {
		typ := ud.AIStackHead().Type()
		ai.Log.Printf("%d: PopActionStack( %s(#%d) ) = %s@%d:\n", s.Frame(), u, u.NetCode, typ, ud.AIStackInd)
	}
	if cur := ud.AIStackHead(); cur != nil {
		if act := cur.Type(); !act.IsCondition() && cur.Field5 != 0 {
			if a := server.GetAIAction(act); a != nil {
				a.End(u.SObj())
			}
		}
	}
	s.ai.stackChanged = true
	// pop action
	ud.AIStackInd--
	// pop related conditions (if any)
	for ; ud.AIStackInd >= 0; ud.AIStackInd-- {
		cur := &ud.AIStack[ud.AIStackInd]
		if !cur.Type().IsCondition() {
			break
		}
	}
	u.monsterActionReset()
	si := ud.AIStackInd
	if si < 0 {
		ud.AIStackInd = 0
		ud.AIStack[0].Action = 0
	}
	return int(si)
}

//export nox_xxx_monsterPushAction_50A260_impl
func nox_xxx_monsterPushAction_50A260_impl(u *nox_object_t, act int, file *C.char, line int) unsafe.Pointer {
	return unsafe.Pointer(asUnitC(u).monsterPushActionImpl(ai.ActionType(act), GoString(file), line))
}

func (u *Unit) monsterPushActionImpl(act ai.ActionType, file string, line int) *server.AIStackItem {
	if !u.Class().Has(object.ClassMonster) {
		return nil
	}
	s := u.getServer()
	ud := u.UpdateDataMonster()
	if int(ud.AIStackInd) >= len(ud.AIStack)-1 {
		return nil
	}
	if cur := ud.AIStackHead(); cur == nil {
		ud.AIStackInd = -1
	} else {
		if ud.AIStackHead().Type() == ai.ACTION_DEAD && act != ai.ACTION_DYING {
			return nil
		}
		if curAct := cur.Type(); curAct == ai.ACTION_IDLE && ud.AIStackInd == 0 {
			ud.AIStackInd = -1
		} else if !curAct.IsCondition() && cur.Field5 != 0 {
			if a := server.GetAIAction(curAct); a != nil {
				a.Cancel(u.SObj())
			}
		}
	}
	ud.AIStackInd++
	ud.AIStack[ud.AIStackInd] = server.AIStackItem{
		Action: uint32(act), Field5: 0,
	}
	u.monsterActionReset()
	if noxflags.HasEngine(noxflags.EngineShowAI) {
		ai.Log.Printf("%d: PushActionStack( %s(#%d), %s ), result: (%s:%d)\n", s.Frame(), u, u.NetCode, act, file, line)
	}
	s.ai.stackChanged = true
	return ud.AIStackHead()
}

func (u *Unit) monsterActionReset() {
	ud := u.UpdateDataMonster()
	ud.Field2 = 0
	ud.Field67 = 0
	ud.Field74 = 0
	ud.Field91 = 0
	ud.Field120_1 = 0
	ud.Field120_2 = 0
	ud.Field120_3 = 0
	ud.Field124 = noxServer.Frame()
	ud.Field137 = noxServer.Frame()
}

//export nox_xxx_unitUpdateMonster_50A5C0
func nox_xxx_unitUpdateMonster_50A5C0(a1 *nox_object_t) {
	u := asUnitC(a1)
	s := u.getServer()
	ud := u.UpdateDataMonster()

	if ud.Field523_2 != 0 {
		ud.Field523_2--
	}

	if obj4 := ud.Field548; obj4 != nil && obj4.Flags().HasAny(object.FlagDead|object.FlagDestroyed) {
		ud.Field548 = nil
	}
	C.nox_xxx_mobAction_50A910(u.CObj())
	s.ai.aiListenToSounds(u)
	if !u.Flags().Has(object.FlagEnabled) {
		return
	}
	s.ai.stackChanged = false
	if ud.Field121 == nil {
		return
	}
	if !u.Flags().HasAny(object.FlagDead | object.FlagDestroyed) {
		if ud.Field360&0x200 != 0 {
			if v7 := C.nox_xxx_monsterGetSoundSet_424300(u.CObj()); v7 != nil {
				s.AudioEventObj(sound.ID(*(*uint32)(unsafe.Add(v7, 64))), u, 0, 0)
			}
			s.scriptCallback(&ud.ScriptIsHit, asObjectS(u.Obj130), u.AsObject(), noxEventMonsterIsHit)
			if noxflags.HasEngine(noxflags.EngineShowAI) {
				cur, max := u.Health()
				ai.Log.Printf("%d: HP = %d/%d\n", s.Frame(), cur, max)
			}
		}
		if v8 := ud.Field130; v8 != 0 && int(s.Frame()-v8) >= int(s.TickRate()) {
			C.nox_xxx_monsterPlayHurtSound_532800(u.CObj())
			ud.Field130 = 0
		}
		C.nox_xxx_mobAction_5469B0(u.CObj())
	}

	if h := u.HealthData; h != nil {
		if !u.Flags().Has(object.FlagDead) && int(s.Frame()-u.Field134) > int(s.TickRate()) {
			if h.Cur < h.Max && h.Max != 0 && s.Frame()%(180*s.TickRate()/uint32(h.Max)) == 0 {
				C.nox_xxx_unitAdjustHP_4EE460(u.CObj(), 1)
			}
		}
	}
	C.nox_xxx_unitUpdateSightMB_5281F0(u.CObj())
	C.nox_xxx_monsterMainAIFn_547210(u.CObj())
	s.ai.nox_xxx_mobActionDependency(u)
	C.nox_xxx_updateNPCAnimData_50A850(u.CObj())
	changedPrev := s.ai.stackChanged
	curAct := ai.ACTION_IDLE
	for {
		cur := ud.AIStackHead()
		act := cur.Type()
		curAct = act
		if cur.Field5 != 0 {
			if !s.ai.stackChanged {
				s.ai.stackChanged = changedPrev
			}
			break
		}
		cur.Field5 = 1
		s.ai.stackChanged = false
		if a := server.GetAIAction(act); a != nil {
			a.Start(u.SObj())
		}
		if !s.ai.stackChanged {
			s.ai.stackChanged = changedPrev
			break
		}
	}
	if a := server.GetAIAction(curAct); a != nil {
		a.Update(u.SObj())
	}
	if s.ai.stackChanged {
		u.maybePrintAIStack("stack changed")
	}
	ud.Field360 &= 0xFFFFFDFF
	C.nox_xxx_monsterPolygonEnter_421FF0(u.CObj())

	if v := ud.Field282_0; v < 100 {
		ud.Field282_0 = v + uint8(100/s.TickRate())
	}
	if u.isMimic() {
		C.nox_xxx_monsterMimicCheckMorph_534950(u.CObj())
	}
	if s.Frame()-u.Field134 > 3*s.TickRate() {
		ud.Field360 &= 0xFFF7FFFF
	}
}

type cgoAIAction struct {
	typ                        ai.ActionType
	start, update, end, cancel unsafe.Pointer
}

func (a cgoAIAction) Type() ai.ActionType {
	return a.typ
}

func (a cgoAIAction) Start(u *server.Object) {
	if a.start != nil {
		cgoCallVoidPtrFunc(a.start, unsafe.Pointer(asUnitS(u).CObj()))
	}
}

func (a cgoAIAction) Update(u *server.Object) {
	if a.update != nil {
		cgoCallVoidPtrFunc(a.update, unsafe.Pointer(asUnitS(u).CObj()))
	}
}

func (a cgoAIAction) End(u *server.Object) {
	if a.end != nil {
		cgoCallVoidPtrFunc(a.end, unsafe.Pointer(asUnitS(u).CObj()))
	}
}

func (a cgoAIAction) Cancel(u *server.Object) {
	if a.cancel != nil {
		cgoCallVoidPtrFunc(a.cancel, unsafe.Pointer(asUnitS(u).CObj()))
	}
}

type AIActionDropObj struct{}

func (AIActionDropObj) Type() ai.ActionType {
	return ai.ACTION_DROP_OBJECT
}
func (AIActionDropObj) Start(_ *server.Object)  {}
func (AIActionDropObj) Update(_ *server.Object) {}
func (AIActionDropObj) End(_ *server.Object)    {}
func (AIActionDropObj) Cancel(_ *server.Object) {}

type AIActionFindObj struct{}

func (AIActionFindObj) Type() ai.ActionType {
	return ai.ACTION_FIND_OBJECT
}
func (AIActionFindObj) Start(_ *server.Object)  {}
func (AIActionFindObj) Update(_ *server.Object) {}
func (AIActionFindObj) End(_ *server.Object)    {}
func (AIActionFindObj) Cancel(_ *server.Object) {}

type AIActionIdle struct{}

func (AIActionIdle) Type() ai.ActionType {
	return ai.ACTION_IDLE
}
func (AIActionIdle) Start(obj *server.Object) {
	u := asUnitS(obj)
	ud := u.UpdateDataMonster()
	cur := ud.AIStackHead()
	cur.Args[0] = uintptr(noxServer.Frame())
}
func (AIActionIdle) End(_ *server.Object)    {}
func (AIActionIdle) Cancel(_ *server.Object) {}

func sub_5343C0(u *Unit) bool {
	ud := u.UpdateDataMonster()
	return ud.Field326 < 0.66000003 && ud.Field326 > 0.33000001
}

func nox_xxx_monsterCanAttackAtWill_534390(u *Unit) bool {
	return u.UpdateDataMonster().Field326 > 0.66000003
}

func sub_534440(u *Unit) bool {
	return u.UpdateDataMonster().Field326 < 0.079999998
}

func sub_5347A0(u *Unit) bool {
	return (u.UpdateDataMonster().Field360>>9)&1 != 0
}

func nox_xxx_monsterLookAtDamager_5466B0(u *Unit) bool {
	if !sub_5347A0(u) {
		return false
	}
	u.monsterPushAction(ai.ACTION_FACE_LOCATION, u.Pos132)
	return true
}

func (AIActionIdle) Update(obj *server.Object) {
	u := asUnitS(obj)
	s := u.getServer()
	ud := u.UpdateDataMonster()
	if uint16(s.Frame()-ud.AIStackHead().ArgU32(0)) == uint16(ud.Field305) {
		s.scriptCallback(&ud.ScriptLookingForEnemy, nil, u.AsObject(), noxEventMonsterIdle)
	}
	if u.Flags().Has(object.FlagEnabled) && (sub_5343C0(u) || nox_xxx_monsterCanAttackAtWill_534390(u)) {
		if enemy := asObjectS(ud.CurrentEnemy); enemy != nil {
			u.monsterPushAction(ai.ACTION_FIGHT, enemy.Pos(), s.Frame())
			return
		}
		if C.sub_5466F0(u.CObj()) != 0 {
			return
		}
	}
	if !u.Flags().Has(object.FlagEnabled) || sub_534440(u) || sub_545E60(u.CObj()) == 0 {
		if u.isMimic() {
			if !u.HasEnchant(server.ENCHANT_ANTI_MAGIC) {
				C.nox_xxx_mobHealSomeone_5411A0(u.CObj())
			}
		} else {
			if nox_xxx_monsterLookAtDamager_5466B0(u) {
				return
			}
			if s.Frame()-ud.Field137 <= s.TickRate()/2 || u.PosVec == u.PrevPos {
				if !u.HasEnchant(server.ENCHANT_ANTI_MAGIC) {
					C.nox_xxx_mobHealSomeone_5411A0(u.CObj())
				}
			} else {
				u.monsterPushAction(ai.ACTION_FACE_LOCATION, u.PrevPos)
			}
		}
	}
}

type AIActionWait struct{}

func (AIActionWait) Type() ai.ActionType {
	return ai.ACTION_WAIT
}
func (AIActionWait) Start(_ *server.Object) {}
func (AIActionWait) End(_ *server.Object)   {}

func (AIActionWait) Update(obj *server.Object) {
	u := asUnitS(obj)
	s := u.getServer()
	ud := u.UpdateDataMonster()
	if s.Frame() >= ud.AIStackHead().ArgU32(0) {
		u.monsterPopAction()
	}
}

func (AIActionWait) Cancel(obj *server.Object) {
	u := asUnitS(obj)
	u.monsterPopAction()
}

type AIActionWaitRel struct{}

func (AIActionWaitRel) Type() ai.ActionType {
	return ai.ACTION_WAIT_RELATIVE
}
func (AIActionWaitRel) Start(_ *server.Object) {}
func (AIActionWaitRel) End(_ *server.Object)   {}

func (AIActionWaitRel) Update(obj *server.Object) {
	u := asUnitS(obj)
	s := u.getServer()
	ud := u.UpdateDataMonster()
	if s.Frame() > ud.Field137+ud.AIStackHead().ArgU32(0) {
		u.monsterPopAction()
	}
}

func (AIActionWaitRel) Cancel(obj *server.Object) {
	u := asUnitS(obj)
	u.monsterPopAction()
}

type AIActionCastOnObj struct{}

func (AIActionCastOnObj) Type() ai.ActionType {
	return ai.ACTION_CAST_SPELL_ON_OBJECT
}
func (AIActionCastOnObj) Start(_ *server.Object)  {}
func (AIActionCastOnObj) End(_ *server.Object)    {}
func (AIActionCastOnObj) Cancel(_ *server.Object) {}

func (AIActionCastOnObj) Update(obj *server.Object) {
	u := asUnitS(obj)
	ud := u.UpdateDataMonster()
	if ud.AIStackHead().ArgU32(2) == 0 {
		u.monsterPopAction()
		return
	}
	C.nox_xxx_mobActionCast_5413B0(u.CObj(), 0)
	if ud.Field120_3 != 0 {
		u.monsterPopAction()
	}
}

type AIActionCastOnPos struct{}

func (AIActionCastOnPos) Type() ai.ActionType {
	return ai.ACTION_CAST_SPELL_ON_LOCATION
}
func (AIActionCastOnPos) Start(_ *server.Object)  {}
func (AIActionCastOnPos) End(_ *server.Object)    {}
func (AIActionCastOnPos) Cancel(_ *server.Object) {}

func (AIActionCastOnPos) Update(obj *server.Object) {
	u := asUnitS(obj)
	ud := u.UpdateDataMonster()
	C.nox_xxx_mobActionCast_5413B0(u.CObj(), 1)
	if ud.Field120_3 != 0 {
		u.monsterPopAction()
	}
}

type AIActionCastDuration struct{}

func (AIActionCastDuration) Type() ai.ActionType {
	return ai.ACTION_CAST_DURATION_SPELL
}

func (AIActionCastDuration) Start(_ *server.Object) {}

func (AIActionCastDuration) Update(obj *server.Object) {
	u := asUnitS(obj)
	ud := u.UpdateDataMonster()
	if ud.AIStackHead().ArgU32(2) != 0 {
		C.nox_xxx_mobActionCast_5413B0(u.CObj(), 0)
	} else {
		u.monsterPopAction()
	}
}

func (AIActionCastDuration) End(obj *server.Object) {
	u := asUnitS(obj)
	s := u.getServer()
	ud := u.UpdateDataMonster()
	s.spells.duration.CancelFor(spell.ID(ud.AIStackHead().ArgU32(0)), u)
}

func (AIActionCastDuration) Cancel(obj *server.Object) {
	u := asUnitS(obj)
	s := u.getServer()
	ud := u.UpdateDataMonster()
	s.spells.duration.CancelFor(spell.ID(ud.AIStackHead().ArgU32(0)), u)
	u.monsterPopAction()
}

type AIActionMorphIntoChest struct{}

func (AIActionMorphIntoChest) Type() ai.ActionType {
	return ai.ACTION_MORPH_INTO_CHEST
}

func (AIActionMorphIntoChest) Start(_ *server.Object)  {}
func (AIActionMorphIntoChest) End(_ *server.Object)    {}
func (AIActionMorphIntoChest) Cancel(_ *server.Object) {}

func (AIActionMorphIntoChest) Update(obj *server.Object) {
	u := asUnitS(obj)
	ud := u.UpdateDataMonster()
	if ud.Field120_3 != 0 {
		u.monsterPopAction()
		ud.Field360 |= 0x40000
		C.nox_xxx_monsterMarkUpdate_4E8020(u.CObj())
	}
}

type AIActionMorphBackToSelf struct{}

func (AIActionMorphBackToSelf) Type() ai.ActionType {
	return ai.ACTION_MORPH_BACK_TO_SELF
}

func (AIActionMorphBackToSelf) Start(_ *server.Object)  {}
func (AIActionMorphBackToSelf) End(_ *server.Object)    {}
func (AIActionMorphBackToSelf) Cancel(_ *server.Object) {}

func (AIActionMorphBackToSelf) Update(obj *server.Object) {
	u := asUnitS(obj)
	ud := u.UpdateDataMonster()
	if ud.Field120_3 != 0 {
		u.monsterPopAction()
		ud.Field360 &^= 0x40000
		C.nox_xxx_monsterMarkUpdate_4E8020(u.CObj())
	}
}
