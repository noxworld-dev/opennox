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

void nullsub_66();
void nullsub_67();
*/
import "C"

import (
	"fmt"
	"math"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/common/unit/ai"
	"github.com/noxworld-dev/opennox/v1/server"
)

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
	for i, v := range args {
		switch v := v.(type) {
		case int:
			s.Args[i] = uintptr(uint32(int32(v)))
		case uint32:
			s.Args[i] = uintptr(v)
		case unsafe.Pointer:
			s.Args[i] = uintptr(v)
		case float32:
			s.Args[i] = uintptr(math.Float32bits(v))
		case noxObject:
			s.Args[i] = uintptr(unsafe.Pointer(toCObj(v)))
		case types.Pointf:
			s.Args[i+0] = uintptr(math.Float32bits(v.X))
			s.Args[i+1] = uintptr(math.Float32bits(v.Y))
		default:
			panic(fmt.Errorf("unsupported arg: %T", v))
		}
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
			if C.sub_5347A0(u.CObj()) != 0 {
				if u.Obj130 != nil {
					v26 := getOwnerUnit(asObjectS(u.Obj130))
					if v26 != nil && v26.Class().HasAny(object.MaskUnits) {
						st.Args[0] = uintptr(a.s.Frame())
					}
				}
			}
			ok = a.s.Frame()-st.ArgU32(0) <= 10*a.s.TickRate()
		case ai.DEPENDENCY_NOT_UNDER_ATTACK:
			if C.sub_5347A0(u.CObj()) == 0 {
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
			if MapTraceRay(u.Pos(), st.ArgPos(0), MapTraceFlag1); !v29 {
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
			C.nox_xxx_unitsGetInCircle_517F90((*C.float2)(unsafe.Pointer(&st.Args[0])), 50.0, C.nox_xxx_unitIsDangerous_547120, u.CObj())
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
				if C.nox_xxx_monsterCanAttackAtWill_534390(u.CObj()) != 0 {
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
		if C.nox_xxx_monsterCanAttackAtWill_534390(u.CObj()) != 0 {
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

//export nox_xxx_audioAddAIInteresting_50CD40
func nox_xxx_audioAddAIInteresting_50CD40(snd C.int, obj *nox_object_t, cp *C.float2) {
	noxServer.ai.NewSound(sound.ID(snd), asObjectC(obj), asPointf(unsafe.Pointer(cp)))
}

func (a *aiData) NewSound(snd sound.ID, obj *Object, pos types.Pointf) {
	if getSoundFlags(snd) == 0 {
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

func getSoundFlags(ind sound.ID) int {
	return int(memmap.Uint32(0x5D4594, 1570284+28*uintptr(ind)+4))
}

func (a *aiData) traceSound(u *Unit, p *MonsterListen) int {
	flags := getSoundFlags(p.snd)
	perc := a.soundFadePerc(p.snd, p.pos, u.Pos())
	if !a.checkSoundThreshold(flags, perc) {
		return -1
	}
	if !MapTraceRayAt(u.Pos(), p.pos, nil, nil, 5) {
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

//export sub_501AF0
func sub_501AF0(snd C.int, p1, p2 *C.float2) C.int {
	return C.int(noxServer.ai.soundFadePerc(sound.ID(snd), asPointf(unsafe.Pointer(p1)), asPointf(unsafe.Pointer(p2))))
}

func (a *aiData) soundFadePerc(snd sound.ID, p1, p2 types.Pointf) int {
	max := int(memmap.Uint32(0x5D4594, 1570284+28*uintptr(snd)+0))
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
	flags := getSoundFlags(lis.snd)
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
	C.nox_xxx_scriptCallByEventBlock_502490((*C.int)(unsafe.Pointer(&ud.Field320)), C.int(uintptr(unsafe.Pointer(obj5.CObj()))), C.int(uintptr(unsafe.Pointer(u.CObj()))), 16)
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
			if fnc := aiActions[act].End; fnc != nil {
				fnc(u)
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
			if fnc := aiActions[curAct].Cancel; fnc != nil {
				fnc(u)
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
				nox_xxx_aud_501960(sound.ID(*(*uint32)(unsafe.Add(v7, 64))), u, 0, 0)
			}
			C.nox_xxx_scriptCallByEventBlock_502490((*C.int)(unsafe.Pointer(&ud.Field312)),
				C.int(uintptr(unsafe.Pointer(asObjectS(u.Obj130).CObj()))),
				C.int(uintptr(unsafe.Pointer(u.CObj()))), 17)
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
		if fnc := aiActions[act].Start; fnc != nil {
			fnc(u)
		}
		if !s.ai.stackChanged {
			s.ai.stackChanged = changedPrev
			break
		}
	}
	if fnc := aiActions[curAct].Update; fnc != nil {
		fnc(u)
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

type AIFunc func(u *Unit)

func wrapAIFuncC(ptr unsafe.Pointer) AIFunc {
	if ptr == nil {
		return nil
	}
	return func(u *Unit) {
		cgoCallVoidPtrFunc(ptr, unsafe.Pointer(u.CObj()))
	}
}

var aiActions = map[ai.ActionType]struct {
	Start  AIFunc
	Update AIFunc
	End    AIFunc
	Cancel AIFunc
}{
	ai.ACTION_IDLE:                   {Start: wrapAIFuncC(C.nox_xxx_monsterIdleStarted_546820), Update: wrapAIFuncC(C.nox_xxx_monsterUpdateIdleLogic_546850)},
	ai.ACTION_WAIT:                   {Update: wrapAIFuncC(C.nox_xxx_mobActionWait_544960), Cancel: wrapAIFuncC(C.sub_532100)},
	ai.ACTION_WAIT_RELATIVE:          {Update: wrapAIFuncC(C.nox_xxx_mobActionWaitRelative_544990), Cancel: wrapAIFuncC(C.sub_532100)},
	ai.ACTION_ESCORT:                 {Update: wrapAIFuncC(C.nox_xxx_mobActionEscort_546430), End: wrapAIFuncC(C.sub_546410), Cancel: wrapAIFuncC(C.sub_546420)},
	ai.ACTION_GUARD:                  {Update: wrapAIFuncC(C.nox_xxx_mobActionGuard_546010)},
	ai.ACTION_HUNT:                   {Update: wrapAIFuncC(C.nox_xxx_mobActionHunt_5449D0)},
	ai.ACTION_RETREAT:                {Update: wrapAIFuncC(C.nox_xxx_mobActionRetreat_545440)},
	ai.ACTION_MOVE_TO:                {Update: wrapAIFuncC(C.nox_xxx_mobActionMoveTo_5443F0)},
	ai.ACTION_FAR_MOVE_TO:            {Update: wrapAIFuncC(C.nox_xxx_mobActionMoveToFar_5445C0)},
	ai.ACTION_DODGE:                  {Update: wrapAIFuncC(C.nox_xxx_mobActionDodge_544640)},
	ai.ACTION_ROAM:                   {Start: wrapAIFuncC(C.sub_545790), Update: wrapAIFuncC(C.nox_xxx_mobActionRoam_5457E0), Cancel: wrapAIFuncC(C.sub_5457C0)},
	ai.ACTION_PICKUP_OBJECT:          {Update: wrapAIFuncC(C.nox_xxx_mobActionPickupObject_544B90)},
	ai.ACTION_DROP_OBJECT:            {Update: wrapAIFuncC(C.nullsub_66)},
	ai.ACTION_FIND_OBJECT:            {Update: wrapAIFuncC(C.nullsub_67)},
	ai.ACTION_RETREAT_TO_MASTER:      {Start: wrapAIFuncC(C.sub_5456B0), Update: wrapAIFuncC(C.sub_5456D0), End: wrapAIFuncC(C.sub_5456C0)},
	ai.ACTION_FIGHT:                  {Start: wrapAIFuncC(C.nox_xxx_mobActionFightStart_531E20), Update: wrapAIFuncC(C.nox_xxx_mobActionFight_531EC0), End: wrapAIFuncC(C.sub_531E90)},
	ai.ACTION_MELEE_ATTACK:           {Start: wrapAIFuncC(C.nox_xxx_mobActionMelee1_532130), Update: wrapAIFuncC(C.nox_xxx_mobActionMeleeAtt_532440), Cancel: wrapAIFuncC(C.sub_532100)},
	ai.ACTION_MISSILE_ATTACK:         {Start: wrapAIFuncC(C.sub_532540), Update: wrapAIFuncC(C.nox_xxx_mobActionMissileAtt_532610), Cancel: wrapAIFuncC(C.sub_532100)},
	ai.ACTION_CAST_SPELL_ON_OBJECT:   {Update: wrapAIFuncC(C.nox_xxx_mobActionCastOnObj_541360)},
	ai.ACTION_CAST_SPELL_ON_LOCATION: {Update: wrapAIFuncC(C.nox_xxx_mobActionCastOnPoint_541560)},
	ai.ACTION_CAST_DURATION_SPELL:    {Update: wrapAIFuncC(C.nox_xxx_mobActionCastStart_5415F0), End: wrapAIFuncC(C.nox_xxx_mobActionCastStopMB_541590), Cancel: wrapAIFuncC(C.nox_xxx_mobActionCastFinishMB_5415C0)},
	ai.ACTION_BLOCK_ATTACK:           {Update: wrapAIFuncC(C.nox_xxx_monsterShieldBlockStart_532070), Cancel: wrapAIFuncC(C.sub_532100)},
	ai.ACTION_BLOCK_FINISH:           {Update: wrapAIFuncC(C.nox_xxx_monsterShieldBlockStop_5320E0), Cancel: wrapAIFuncC(C.sub_532100)},
	ai.ACTION_WEAPON_BLOCK:           {Update: wrapAIFuncC(C.sub_532110), Cancel: wrapAIFuncC(C.sub_532100)},
	ai.ACTION_FLEE:                   {Start: wrapAIFuncC(C.sub_544740), Update: wrapAIFuncC(C.nox_xxx_mobActionFlee_544760), End: wrapAIFuncC(C.sub_544750)},
	ai.ACTION_FACE_LOCATION:          {Update: wrapAIFuncC(C.sub_545210), Cancel: wrapAIFuncC(C.sub_532100)},
	ai.ACTION_FACE_OBJECT:            {Update: wrapAIFuncC(C.sub_545300), Cancel: wrapAIFuncC(C.sub_532100)},
	ai.ACTION_FACE_ANGLE:             {Update: wrapAIFuncC(C.sub_545340), Cancel: wrapAIFuncC(C.sub_532100)},
	ai.ACTION_SET_ANGLE:              {Update: wrapAIFuncC(C.sub_5453E0), Cancel: wrapAIFuncC(C.sub_532100)},
	ai.ACTION_RANDOM_WALK:            {Update: wrapAIFuncC(C.nox_xxx_mobActionRandomWalk_545020)},
	ai.ACTION_DYING:                  {Start: wrapAIFuncC(C.nox_xxx_mobGenericDeath_544C40), Update: wrapAIFuncC(C.sub_544D60), End: wrapAIFuncC(C.nox_xxx_zombieBurnDeleteCheck_544CA0)},
	ai.ACTION_DEAD:                   {Start: wrapAIFuncC(C.nox_xxx_mobActionDead1_544D80), Update: wrapAIFuncC(C.nox_xxx_mobActionDead2_544EC0)},
	ai.ACTION_REPORT:                 {Update: wrapAIFuncC(C.nox_xxx_mobActionReportComplete_544FF0)},
	ai.ACTION_MORPH_INTO_CHEST:       {Update: wrapAIFuncC(C.nox_xxx_mobActionMorphToChest_5348D0)},
	ai.ACTION_MORPH_BACK_TO_SELF:     {Update: wrapAIFuncC(C.nox_xxx_mobActionMorphBackToSelf_534910)},
	ai.ACTION_GET_UP:                 {Update: wrapAIFuncC(C.nox_xxx_mobActionGetUp_534A90)},
	ai.ACTION_CONFUSED:               {Update: wrapAIFuncC(C.nox_xxx_mobActionConfuse_545140)},
	ai.ACTION_MOVE_TO_HOME:           {Start: wrapAIFuncC(C.nox_xxx_mobActionReturnToHome_544920), Update: wrapAIFuncC(C.sub_544950), End: wrapAIFuncC(C.sub_544930), Cancel: wrapAIFuncC(C.sub_544940)},
}
