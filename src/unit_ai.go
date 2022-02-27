package nox

/*
#include "defs.h"
#include "GAME4.h"
#include "GAME4_1.h"
#include "GAME4_3.h"
#include "GAME5.h"
extern unsigned int dword_5d4594_2489460;
*/
import "C"

import (
	"fmt"
	"math"
	"unsafe"

	noxflags "nox/v1/common/flags"
	"nox/v1/common/object"
	"nox/v1/common/types"
	"nox/v1/common/unit/ai"
)

//export nox_ai_debug_print
func nox_ai_debug_print(str *C.char) {
	ai.Log.Printf("%s", GoString(str))
}

//export nox_ai_debug_printStack_509F60
func nox_ai_debug_printStack_509F60(cu *C.nox_object_t, event *C.char) {
	asUnitC(cu).maybePrintAIStack(GoString(event))
}

var _ = ([1]struct{}{})[24-unsafe.Sizeof(aiStack{})]

type aiStack struct {
	action  uint32 // 0, 0
	arg_1   uint32 // 1, 4
	arg_2   uint32 // 2, 8
	arg_3   uint32 // 3, 12
	arg_4   uint32 // 4, 16
	field_5 uint32 // 5, 20
}

func (s *aiStack) Type() ai.ActionType {
	return ai.ActionType(s.action)
}

func (s *aiStack) SetArgs(args ...interface{}) {
	for i, v := range args {
		p := s.ptr(i)
		switch v := v.(type) {
		case int:
			*(*int32)(p) = int32(v)
		case uint32:
			*(*uint32)(p) = v
		case unsafe.Pointer:
			*(*unsafe.Pointer)(p) = v
		case float32:
			*(*float32)(p) = v
		case noxObject:
			*(*unsafe.Pointer)(p) = unsafe.Pointer(toCObj(v))
		default:
			panic(fmt.Errorf("unsupported arg: %T", v))
		}
	}
}

func (s *aiStack) ArgU32(i int) uint32 {
	switch i {
	case 0:
		return s.arg_1
	case 1:
		return s.arg_2
	case 2:
		return s.arg_3
	case 3:
		return s.arg_4
	default:
		panic(i)
	}
}

func (s *aiStack) ArgF32(i int) float32 {
	switch i {
	case 0:
		return *(*float32)(unsafe.Pointer(&s.arg_1))
	case 1:
		return *(*float32)(unsafe.Pointer(&s.arg_2))
	case 2:
		return *(*float32)(unsafe.Pointer(&s.arg_3))
	case 3:
		return *(*float32)(unsafe.Pointer(&s.arg_4))
	default:
		panic(i)
	}
}

func (s *aiStack) argPtr(i int) unsafe.Pointer {
	switch i {
	case 0:
		return *(*unsafe.Pointer)(unsafe.Pointer(&s.arg_1))
	case 1:
		return *(*unsafe.Pointer)(unsafe.Pointer(&s.arg_2))
	case 2:
		return *(*unsafe.Pointer)(unsafe.Pointer(&s.arg_3))
	case 3:
		return *(*unsafe.Pointer)(unsafe.Pointer(&s.arg_4))
	default:
		panic(i)
	}
}

func (s *aiStack) ptr(i int) unsafe.Pointer {
	switch i {
	case 0:
		return unsafe.Pointer(&s.arg_1)
	case 1:
		return unsafe.Pointer(&s.arg_2)
	case 2:
		return unsafe.Pointer(&s.arg_3)
	case 3:
		return unsafe.Pointer(&s.arg_4)
	default:
		panic(i)
	}
}

func (s *aiStack) ArgPos(i int) types.Pointf {
	switch i {
	case 0:
		p := *(*[2]float32)(unsafe.Pointer(&s.arg_1))
		return types.Pointf{X: p[0], Y: p[1]}
	case 1:
		p := *(*[2]float32)(unsafe.Pointer(&s.arg_2))
		return types.Pointf{X: p[0], Y: p[1]}
	case 2:
		p := *(*[2]float32)(unsafe.Pointer(&s.arg_3))
		return types.Pointf{X: p[0], Y: p[1]}
	default:
		panic(i)
	}
}

func (s *aiStack) ArgObj(i int) *Object {
	return asObject(s.argPtr(i))
}

func (s *aiStack) ArgUnit(i int) *Unit {
	return asUnit(s.argPtr(i))
}

func (u *Unit) maybePrintAIStack(event string) {
	if noxflags.HasEngine(noxflags.EngineShowAI) {
		u.updateDataMonster().printAIStack(event)
	}
}

//export nox_xxx_mobActionDependency_546A70
func nox_xxx_mobActionDependency_546A70(uc *C.nox_object_t) {
	u := asUnitC(uc)
	ud := u.updateDataMonster()
	stack := ud.getAIStack()
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
			ok = st.ArgU32(0) > gameFrame()
		case ai.DEPENDENCY_ALIVE:
			obj := st.ArgObj(0)
			v13 := unsafe.Slice((*uint16)(obj.field_139), 3)
			if obj == nil || !obj.Class().HasAny(object.MaskUnits) || (v13[0] == 0) && v13[2] != 0 {
				ok = false
				ud.field_97 = 0
				ud.field_101 = C.uint(gameFrame() + gameFPS())
			}
		case ai.DEPENDENCY_UNDER_ATTACK:
			if C.sub_5347A0(u.CObj()) != 0 {
				if u.field_130 != 0 {
					v26 := asObjectC(C.sub_534160(C.int(u.field_130)))
					if v26 != nil && v26.Class().HasAny(object.MaskUnits) {
						st.arg_1 = gameFrame()
					}
				}
			}
			ok = gameFrame()-st.ArgU32(0) <= 10*gameFPS()
		case ai.DEPENDENCY_NOT_UNDER_ATTACK:
			if C.sub_5347A0(u.CObj()) == 0 {
				break
			}
			if u.field_130 == 0 {
				break
			}
			v27 := asObjectC(C.sub_534160(C.int(u.field_130)))
			if v27 == nil {
				break
			}
			if v27.Class().HasAny(object.MaskUnits) {
				ok = false
			}
		case ai.DEPENDENCY_CAN_SEE:
			v14 := st.ArgObj(0)
			if v14 == nil || !nox_xxx_unitCanInteractWith_5370E0(u, v14, 0) {
				ok = false
			}
		case ai.DEPENDENCY_CANNOT_SEE:
			obj := st.ArgObj(0)
			if obj == nil || C.sub_533360(u.CObj(), obj.CObj()) != 0 {
				ok = false
			}
		case ai.DEPENDENCY_BLOCKED_LINE_OF_FIRE:
			obj := st.ArgObj(0)
			if obj == nil {
				ok = false
				break
			}
			pos, pos2 := u.Pos(), obj.Pos()
			ok = !nox_xxx_mapTraceObstacles(u, pos, pos2)
		case ai.DEPENDENCY_OBJECT_AT_VISIBLE_LOCATION:
			v28 := st.ArgObj(2)
			v29 := false
			if v28 != nil && nox_xxx_unitCanInteractWith_5370E0(u, v28, 0) {
				v29 = true
				pos := v28.Pos()
				*(*float32)(unsafe.Pointer(&st.arg_1)) = pos.X
				*(*float32)(unsafe.Pointer(&st.arg_2)) = pos.Y
			}
			pos2 := st.ArgPos(0)
			if _, trok := nox_xxx_mapTraceRay_535250_00(u.Pos(), pos2, 1); trok && !v29 {
				ok = false
			}
		case ai.DEPENDENCY_OBJECT_FARTHER_THAN:
			obj, r := st.ArgObj(2), st.ArgF32(0)
			ok = obj != nil && nox_xxx_calcDistance_4E6C00(u, obj) > r
		case ai.DEPENDENCY_OBJECT_CLOSER_THAN:
			obj, r := st.ArgObj(2), st.ArgF32(0)
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
			ok = ud.current_enemy != nil
		case ai.DEPENDENCY_NO_VISIBLE_ENEMY:
			ok = ud.current_enemy == nil
		case ai.DEPENDENCY_NO_VISIBLE_FOOD:
			r := 250.0
			if noxflags.HasGame(noxflags.GameModeQuest) {
				r = 640.0
			}
			ok = C.nox_xxx_mobSearchEdible_544A00(u.CObj(), C.float(r)) == 0
		case ai.DEPENDENCY_NO_INTERESTING_SOUND:
			if ud.field_97 != 0 && gameFrame()-uint32(ud.field_101) < 3*gameFPS() {
				ok = false
			}
		case ai.DEPENDENCY_NO_NEW_ENEMY:
			old := st.ArgUnit(0)
			if old == nil {
				ok = false
				break
			}
			enemy := asUnitC(ud.current_enemy)
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
			ok = u.testBuff(byte(st.arg_1))
		case ai.DEPENDENCY_ENEMY_CLOSER_THAN:
			enemy := asUnitC(ud.current_enemy)
			ok = enemy != nil && nox_xxx_calcDistance_4E6C00(u, enemy) <= st.ArgF32(0)
		case ai.DEPENDENCY_NOT_HEALTHY:
			v34 := unsafe.Slice((*uint16)(u.field_139), 3)
			v35 := float32(1.0)
			if v34[2] != 0 {
				v35 = float32(v34[0]) / float32(v34[2])
			}
			if v35 >= float32(ud.field_336) {
				ok = false
			}
		case ai.DEPENDENCY_WAIT_FOR_STAMINA:
			if C.int(ud.field_282_0) >= C.nox_xxx_weaponGetStaminaByType_4F7E80(C.int(ud.field_514)) {
				ok = false
			}
		case ai.DEPENDENCY_ENEMY_FARTHER_THAN:
			enemy := asUnitC(ud.current_enemy)
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
			C.nox_xxx_unitsGetInCircle_517F90((*C.float2)(unsafe.Pointer(&st.arg_1)), 50.0, C.nox_xxx_unitIsDangerous_547120, u.CObj())
			if C.dword_5d4594_2489460 == 0 {
				ok = false
			}
		case ai.DEPENDENCY_NOT_FRUSTRATED:
			if ud.field_360&0x200000 != 0 {
				ok = false
				ud.field_360 &= 0xFFDFFFFF
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
			ai.Log.Printf("%d: %s DEPENDENCY '%s'@%d failed, popping:\n", gameFrame(), u.String(), typ.String(), i)
		}
		for {
			nox_xxx_monsterPopAction_50A160(u)
			if !(ud.getAIStackInd() >= i && C.sub_5341F0(u.CObj()) == 0) {
				break
			}
		}
		stack = ud.getAIStack()
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
