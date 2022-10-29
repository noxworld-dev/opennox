package opennox

/*
#include "defs.h"
#include "GAME1_1.h"
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
}

func (a *aiData) Init(s *Server) {
	a.s = s
}

//export nox_ai_debug_print
func nox_ai_debug_print(str *C.char) {
	ai.Log.Printf("%s", GoString(str))
}

//export nox_ai_debug_printStack_509F60
func nox_ai_debug_printStack_509F60(cu *C.nox_object_t, event *C.char) {
	asUnitC(cu).maybePrintAIStack(GoString(event))
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
		u.updateDataMonster().PrintAIStack(u.getServer().Frame(), event)
	}
}

//export nox_xxx_mobActionDependency_546A70
func nox_xxx_mobActionDependency_546A70(uc *C.nox_object_t) {
	noxServer.ai.nox_xxx_mobActionDependency(asUnitC(uc))
}

func (a *aiData) nox_xxx_mobActionDependency(u *Unit) {
	ud := u.updateDataMonster()
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
			h := obj.healthData()
			if obj == nil || !obj.Class().HasAny(object.MaskUnits) || (h.Cur == 0) && h.Max != 0 {
				ok = false
				ud.Field97 = 0
				ud.Field101 = a.s.Frame() + a.s.TickRate()
			}
		case ai.DEPENDENCY_UNDER_ATTACK:
			if C.sub_5347A0(u.CObj()) != 0 {
				if u.obj_130 != nil {
					v26 := getOwnerUnit(asObjectC(u.obj_130))
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
			if u.obj_130 == nil {
				break
			}
			attacker := getOwnerUnit(asObjectC(u.obj_130))
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
			ok = u.HasEnchant(EnchantID(st.Args[0]))
		case ai.DEPENDENCY_ENEMY_CLOSER_THAN:
			enemy := asUnitS(ud.CurrentEnemy)
			ok = enemy != nil && nox_xxx_calcDistance_4E6C00(u, enemy) <= st.ArgF32(0)
		case ai.DEPENDENCY_NOT_HEALTHY:
			h := u.healthData()
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
			ok = u.Pos() == u.prevPos()
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
			nox_xxx_monsterPopAction_50A160(u)
			if !(int(ud.AIStackInd) >= i && C.sub_5341F0(u.CObj()) == 0) {
				break
			}
		}
		stack = ud.GetAIStack()
		i = len(stack) - 1
		nox_xxx_monsterActionReset_50A110(u)
		u.maybePrintAIStack("procDep")
	}
}

func nox_xxx_monsterActionReset_50A110(u *Unit) {
	C.nox_xxx_monsterActionReset_50A110(u.CObj())
}

func nox_xxx_monsterPopAction_50A160(u *Unit) {
	C.nox_xxx_monsterPopAction_50A160(u.CObj())
}

func nox_xxx_checkMobAction_50A0D0(u *Unit, act ai.ActionType) bool {
	return C.nox_xxx_checkMobAction_50A0D0(u.CObj(), C.int(act)) != 0
}

//export sub_545E60
func sub_545E60(a1c *nox_object_t) C.int {
	u := asUnitC(a1c)
	s := u.getServer()

	ud := u.updateDataMonster()
	ts := uint32(u.field_134)
	if ud.Field129 >= ts || s.Frame()-ts >= 10*s.TickRate() {
		return 0
	}
	ud.Field129 = ts
	if u.obj_130 != nil {
		if obj4 := getOwnerUnit(asObjectC(u.obj_130)); obj4 != nil {
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

//export nox_xxx_unitListenRoutine_50CDD0
func nox_xxx_unitListenRoutine_50CDD0(unit *nox_object_t) {
	noxServer.ai.aiListenToSounds(asUnitC(unit))
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
	ud := u.updateDataMonster()
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
	ud := u.updateDataMonster()
	punit := lis.obj.findOwnerChainPlayer()
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
	ud := u.updateDataMonster()
	ud.Field97 = uint32(lis.snd)
	ud.Field101 = a.s.Frame()
	ud.Field102 = uint32(dist)
	if lis.obj != nil {
		ud.Field98 = uint32(lis.obj.net_code)
	} else {
		ud.Field98 = 0
	}
	ud.Field99X = lis.pos.X
	ud.Field99Y = lis.pos.Y
	a.lastHeard = lis.pos
	obj5 := lis.obj.findOwnerChainPlayer()
	// EventID 16 is MonsterHearsEnemy
	C.nox_xxx_scriptCallByEventBlock_502490((*C.int)(unsafe.Pointer(&ud.Field320)), C.int(uintptr(unsafe.Pointer(obj5.CObj()))), C.int(uintptr(unsafe.Pointer(u.CObj()))), 16)
}

func (a *aiData) lastHeardEvent() types.Pointf {
	return a.lastHeard
}
