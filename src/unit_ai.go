package opennox

import (
	"math"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/spell"
	"github.com/noxworld-dev/opennox-lib/types"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/common/unit/ai"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
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
	server.RegisterAIAction(AIActionReport{})
}

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

func (obj *Object) MaybePrintAIStack(event string) {
	obj.SObj().MaybePrintAIStack(event)
}

func (a *aiData) nox_xxx_mobActionDependency(u *Object) {
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
			obj := st.ArgObj(0)
			h := obj.HealthData
			if obj == nil || !obj.Class().HasAny(object.MaskUnits) || (h.Cur == 0) && h.Max != 0 {
				ok = false
				ud.Field97 = 0
				ud.Field101 = a.s.Frame() + a.s.SecToFrames(1)
			}
		case ai.DEPENDENCY_UNDER_ATTACK:
			if u.MonsterIsInjured() {
				if u.Obj130 != nil {
					v26 := u.Obj130.GetOwnerUnit()
					if v26 != nil && v26.Class().HasAny(object.MaskUnits) {
						st.Args[0] = uintptr(a.s.Frame())
					}
				}
			}
			ok = a.s.Frame()-st.ArgU32(0) <= a.s.SecToFrames(10)
		case ai.DEPENDENCY_NOT_UNDER_ATTACK:
			if !u.MonsterIsInjured() {
				break
			}
			if u.Obj130 == nil {
				break
			}
			attacker := u.Obj130.GetOwnerUnit()
			if attacker == nil {
				break
			}
			if attacker.Class().HasAny(object.MaskUnits) {
				ok = false
			}
		case ai.DEPENDENCY_CAN_SEE:
			obj := st.ArgObj(0)
			if obj == nil || !a.s.CanInteract(u.SObj(), obj, 0) {
				ok = false
			}
		case ai.DEPENDENCY_CANNOT_SEE:
			obj := st.ArgObj(0)
			if obj == nil || a.s.CanSeeDir(u.SObj(), obj) {
				ok = false
			}
		case ai.DEPENDENCY_BLOCKED_LINE_OF_FIRE:
			obj := st.ArgObj(0)
			if obj == nil {
				ok = false
				break
			}
			pos, pos2 := u.Pos(), obj.Pos()
			ok = !a.s.MapTraceObstacles(u.SObj(), pos, pos2)
		case ai.DEPENDENCY_OBJECT_AT_VISIBLE_LOCATION:
			v28 := st.ArgObj(2)
			v29 := false
			if v28 != nil && a.s.CanInteract(u.SObj(), v28.SObj(), 0) {
				v29 = true
				pos := v28.Pos()
				st.Args[0] = uintptr(math.Float32bits(pos.X))
				st.Args[1] = uintptr(math.Float32bits(pos.Y))
			}
			if a.s.MapTraceRay(u.Pos(), st.ArgPos(0), server.MapTraceFlag1); !v29 {
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
			ok = ud.CurrentEnemy != nil
		case ai.DEPENDENCY_NO_VISIBLE_ENEMY:
			ok = ud.CurrentEnemy == nil
		case ai.DEPENDENCY_NO_VISIBLE_FOOD:
			r := 250.0
			if noxflags.HasGame(noxflags.GameModeQuest) {
				r = 640.0
			}
			ok = legacy.Nox_xxx_mobSearchEdible_544A00(u.SObj(), float32(r)) == 0
		case ai.DEPENDENCY_NO_INTERESTING_SOUND:
			if ud.Field97 != 0 && a.s.Frame()-ud.Field101 < a.s.SecToFrames(3) {
				ok = false
			}
		case ai.DEPENDENCY_NO_NEW_ENEMY:
			old := st.ArgObj(0)
			if old == nil {
				ok = false
				break
			}
			enemy := asObjectS(ud.CurrentEnemy)
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
			enemy := asObjectS(ud.CurrentEnemy)
			ok = enemy != nil && nox_xxx_calcDistance_4E6C00(u, enemy) <= st.ArgF32(0)
		case ai.DEPENDENCY_NOT_HEALTHY:
			h := u.HealthData
			perc := float32(1.0)
			if h.Max != 0 {
				perc = float32(h.Cur) / float32(h.Max)
			}
			if perc >= ud.ResumeLevel {
				ok = false
			}
		case ai.DEPENDENCY_WAIT_FOR_STAMINA:
			if int(ud.Field282_0) >= legacy.Nox_xxx_weaponGetStaminaByType_4F7E80(int(ud.Field514)) {
				ok = false
			}
		case ai.DEPENDENCY_ENEMY_FARTHER_THAN:
			enemy := asObjectS(ud.CurrentEnemy)
			if enemy != nil && nox_xxx_calcDistance_4E6C00(u, enemy) < st.ArgF32(0) {
				ok = false
			}
		case ai.DEPENDENCY_UNDER_CURSOR:
			if hu := a.s.Players.HostUnit; hu == nil || legacy.Nox_xxx_findObjectAtCursor_54AF40(hu) != u.SObj() {
				ok = false
			}
		case ai.DEPENDENCY_NOT_CORNERED:
			ok = legacy.Nox_xxx_mobGetMoveAttemptTime_534810(u.SObj()) == 0
		case ai.DEPENDENCY_LOCATION_IS_SAFE:
			legacy.Set_dword_5d4594_2489460(1)
			a.s.Map.EachObjInCircle(st.ArgPos(0), 50.0, func(it *server.Object) bool {
				legacy.Nox_xxx_unitIsDangerous_547120(asObjectS(it).SObj(), u.SObj())
				return true
			})
			if legacy.Get_dword_5d4594_2489460() == 0 {
				ok = false
			}
		case ai.DEPENDENCY_NOT_FRUSTRATED:
			if ud.StatusFlags.Has(object.MonStatusFrustrated) {
				ok = false
				ud.StatusFlags &^= object.MonStatusFrustrated
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
			u.MonsterPopAction()
			if int(ud.AIStackInd) < i || u.SObj().AIStackEmptyAndIdle() {
				break
			}
		}
		stack = ud.GetAIStack()
		i = len(stack) - 1
		u.MonsterActionReset()
		u.MaybePrintAIStack("procDep")
	}
}

var _ = [1]struct{}{}[24-unsafe.Sizeof(MonsterListen{})]

type MonsterListen struct {
	snd   sound.ID       // 0, 0
	obj   *server.Object // 1, 4
	pos   types.Pointf   // 2, 8
	frame uint32         // 4, 16
	next  *MonsterListen // 5, 20
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

func (a *aiData) NewSound(snd sound.ID, obj *server.Object, pos types.Pointf) {
	if a.s.Audio.Flags(snd) == 0 {
		return
	}
	if a.allocListen.Class == nil {
		a.allocListen = alloc.NewClassT("MonsterListen", MonsterListen{}, 128)
	}
	if obj.GetOwnerUnit() == nil {
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

func (a *aiData) aiListenToSounds(u *Object) {
	// Not sure about this check. If unit is invulnerable, don't listen for anything?
	// Is present in vanilla though, so this might be some kind of weird fix for strange behaviour
	if legacy.Nox_xxx_checkIsKillable_528190(u.SObj()) == 0 {
		return
	}

	// Do not listen to anything if you are a fish, frog or rat
	if a.s.IsFish(u.SObj()) || a.s.IsFrog(u.SObj()) || a.s.IsRat(u.SObj()) {
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

func (a *aiData) traceSound(u *Object, p *MonsterListen) int {
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

func nox_xxx_gameSetAudioFadeoutMb_501AC0(v int) {
	noxServer.ai.nox_xxx_gameSetAudioFadeoutMb(v)
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

func (a *aiData) shouldUnitListen(u *Object, lis *MonsterListen) bool {
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
		if a.s.IsEnemyTo(u.SObj(), punit) {
			if flags == 0 {
				return false
			}
		} else if flags&0x10 == 0 {
			return false
		}
	}
	if v12 := legacy.Sub_501C00(lis.pos, lis.obj); v12 != 0 {
		pos := u.Pos()
		cpi, free := alloc.Make([]int32{}, 2)
		defer free()
		cpi[0] = int32(pos.X)
		cpi[1] = int32(pos.Y)
		resp := legacy.Nox_xxx_polygonIsPlayerInPolygon_4217B0(unsafe.Pointer(&cpi[0]), 0)
		if resp != nil && byte(v12) != *(*byte)(unsafe.Add(unsafe.Pointer(&resp.Field_0[32]), 2)) {
			return false
		}
	}
	return true
}

func (a *aiData) nox_xxx_unitEmitHearEvent_50D110(u *Object, lis *MonsterListen, dist int) {
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
	a.s.noxScript.ScriptCallback(&ud.ScriptHearEnemy, obj5, u.SObj(), server.NoxEventMonsterHearEnemy)
}

func (a *aiData) lastHeardEvent() types.Pointf {
	return a.lastHeard
}

func (obj *Object) MonsterPopAction() int { // nox_xxx_monsterPopAction_50A160
	return obj.SObj().MonsterPopAction()
}

func (obj *Object) MonsterPushActionImpl(act ai.ActionType, file string, line int) *server.AIStackItem { // nox_xxx_monsterPushAction_50A260_impl
	return obj.SObj().MonsterPushActionImpl(act, file, line)
}

func (obj *Object) MonsterActionReset() {
	obj.SObj().MonsterActionReset()
}

func nox_xxx_unitUpdateMonster_50A5C0(a1 *server.Object) {
	u := asObjectS(a1)
	s := u.getServer()
	ud := u.UpdateDataMonster()

	if ud.Field523_2 != 0 {
		ud.Field523_2--
	}

	if obj4 := ud.Field548; obj4 != nil && obj4.Flags().HasAny(object.FlagDead|object.FlagDestroyed) {
		ud.Field548 = nil
	}
	legacy.Nox_xxx_mobAction_50A910(u.SObj())
	s.ai.aiListenToSounds(u)
	if !u.Flags().Has(object.FlagEnabled) {
		return
	}
	s.AI.StackChanged = false
	if ud.MonsterDef == nil {
		return
	}
	if !u.Flags().HasAny(object.FlagDead | object.FlagDestroyed) {
		if ud.StatusFlags.Has(object.MonStatusInjured) {
			if v7 := legacy.Nox_xxx_monsterGetSoundSet_424300(u.SObj()); v7 != nil {
				s.Audio.EventObj(sound.ID(*(*uint32)(unsafe.Add(v7, 64))), u, 0, 0)
			}
			s.noxScript.ScriptCallback(&ud.ScriptIsHit, u.Obj130, u.SObj(), server.NoxEventMonsterIsHit)
			if noxflags.HasEngine(noxflags.EngineShowAI) {
				cur, max := u.Health()
				ai.Log.Printf("%d: HP = %d/%d\n", s.Frame(), cur, max)
			}
		}
		if v8 := ud.Field130; v8 != 0 && int(s.Frame()-v8) >= int(s.SecToFrames(1)) {
			legacy.Nox_xxx_monsterPlayHurtSound_532800(u.SObj())
			ud.Field130 = 0
		}
		legacy.Nox_xxx_mobAction_5469B0(u.SObj())
	}

	if h := u.HealthData; h != nil {
		if !u.Flags().Has(object.FlagDead) && int(s.Frame()-u.Frame134) > int(s.SecToFrames(1)) {
			if h.Cur < h.Max && h.Max != 0 && s.Frame()%(180*s.TickRate()/uint32(h.Max)) == 0 {
				legacy.Nox_xxx_unitAdjustHP_4EE460(u.SObj(), 1)
			}
		}
	}
	legacy.Nox_xxx_unitUpdateSightMB_5281F0(u.SObj())
	legacy.Nox_xxx_monsterMainAIFn_547210(u.SObj())
	s.ai.nox_xxx_mobActionDependency(u)
	legacy.Nox_xxx_updateNPCAnimData_50A850(u.SObj())
	changedPrev := s.AI.StackChanged
	curAct := ai.ACTION_IDLE
	for {
		cur := ud.AIStackHead()
		act := cur.Type()
		curAct = act
		if cur.Field5 != 0 {
			if !s.AI.StackChanged {
				s.AI.StackChanged = changedPrev
			}
			break
		}
		cur.Field5 = 1
		s.AI.StackChanged = false
		if a := server.GetAIAction(act); a != nil {
			a.Start(u.SObj())
		}
		if !s.AI.StackChanged {
			s.AI.StackChanged = changedPrev
			break
		}
	}
	if a := server.GetAIAction(curAct); a != nil {
		a.Update(u.SObj())
	}
	if s.AI.StackChanged {
		u.MaybePrintAIStack("stack changed")
	}
	ud.StatusFlags &^= object.MonStatusInjured
	legacy.Nox_xxx_monsterPolygonEnter_421FF0(u.SObj())

	if v := ud.Field282_0; v < 100 {
		ud.Field282_0 = v + uint8(100/s.TickRate())
	}
	if s.IsMimic(u.SObj()) {
		legacy.Nox_xxx_monsterMimicCheckMorph_534950(u.SObj())
	}
	if s.Frame()-u.Frame134 > s.SecToFrames(3) {
		ud.StatusFlags &^= object.MonStatusOnFire
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
	u := asObjectS(obj)
	s := u.Server()
	ud := u.UpdateDataMonster()
	cur := ud.AIStackHead()
	cur.Args[0] = uintptr(s.Frame())
}
func (AIActionIdle) End(_ *server.Object)    {}
func (AIActionIdle) Cancel(_ *server.Object) {}

func (AIActionIdle) Update(obj *server.Object) {
	u := asObjectS(obj)
	s := u.getServer()
	ud := obj.UpdateDataMonster()
	if uint16(s.Frame()-ud.AIStackHead().ArgU32(0)) == uint16(ud.Field305) {
		s.noxScript.ScriptCallback(&ud.ScriptLookingForEnemy, nil, obj, server.NoxEventMonsterIdle)
	}
	if obj.Flags().Has(object.FlagEnabled) && (obj.Sub_5343C0() || obj.Nox_xxx_monsterCanAttackAtWill_534390()) {
		if enemy := asObjectS(ud.CurrentEnemy); enemy != nil {
			u.MonsterPushAction(ai.ACTION_FIGHT, enemy.Pos(), s.Frame())
			return
		}
		if legacy.Sub_5466F0(u.SObj()) != 0 {
			return
		}
	}
	if !u.Flags().Has(object.FlagEnabled) || obj.Sub_534440() || obj.Sub_545E60() == 0 {
		if s.IsMimic(u.SObj()) {
			if !u.HasEnchant(server.ENCHANT_ANTI_MAGIC) {
				legacy.Nox_xxx_mobHealSomeone_5411A0(u.SObj())
			}
		} else {
			if u.MonsterLookAtDamager() {
				return
			}
			if s.Frame()-ud.Field137 <= s.TickRate()/2 || u.PosVec == u.PrevPos {
				if !u.HasEnchant(server.ENCHANT_ANTI_MAGIC) {
					legacy.Nox_xxx_mobHealSomeone_5411A0(u.SObj())
				}
			} else {
				u.MonsterPushAction(ai.ACTION_FACE_LOCATION, u.PrevPos)
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
	u := asObjectS(obj)
	s := u.Server()
	ud := u.UpdateDataMonster()
	if s.Frame() >= ud.AIStackHead().ArgU32(0) {
		u.MonsterPopAction()
	}
}

func (AIActionWait) Cancel(obj *server.Object) {
	u := asObjectS(obj)
	u.MonsterPopAction()
}

type AIActionWaitRel struct{}

func (AIActionWaitRel) Type() ai.ActionType {
	return ai.ACTION_WAIT_RELATIVE
}
func (AIActionWaitRel) Start(_ *server.Object) {}
func (AIActionWaitRel) End(_ *server.Object)   {}

func (AIActionWaitRel) Update(obj *server.Object) {
	u := asObjectS(obj)
	s := u.Server()
	ud := u.UpdateDataMonster()
	if s.Frame() > ud.Field137+ud.AIStackHead().ArgU32(0) {
		u.MonsterPopAction()
	}
}

func (AIActionWaitRel) Cancel(obj *server.Object) {
	u := asObjectS(obj)
	u.MonsterPopAction()
}

type AIActionCastOnObj struct{}

func (AIActionCastOnObj) Type() ai.ActionType {
	return ai.ACTION_CAST_SPELL_ON_OBJECT
}
func (AIActionCastOnObj) Start(_ *server.Object)  {}
func (AIActionCastOnObj) End(_ *server.Object)    {}
func (AIActionCastOnObj) Cancel(_ *server.Object) {}

func (AIActionCastOnObj) Update(obj *server.Object) {
	u := asObjectS(obj)
	ud := u.UpdateDataMonster()
	if ud.AIStackHead().ArgU32(2) == 0 {
		u.MonsterPopAction()
		return
	}
	legacy.Nox_xxx_mobActionCast_5413B0(u.SObj(), 0)
	if ud.Field120_3 != 0 {
		u.MonsterPopAction()
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
	u := asObjectS(obj)
	ud := u.UpdateDataMonster()
	legacy.Nox_xxx_mobActionCast_5413B0(u.SObj(), 1)
	if ud.Field120_3 != 0 {
		u.MonsterPopAction()
	}
}

type AIActionCastDuration struct{}

func (AIActionCastDuration) Type() ai.ActionType {
	return ai.ACTION_CAST_DURATION_SPELL
}

func (AIActionCastDuration) Start(_ *server.Object) {}

func (AIActionCastDuration) Update(obj *server.Object) {
	u := asObjectS(obj)
	ud := u.UpdateDataMonster()
	if ud.AIStackHead().ArgU32(2) != 0 {
		legacy.Nox_xxx_mobActionCast_5413B0(u.SObj(), 0)
	} else {
		u.MonsterPopAction()
	}
}

func (AIActionCastDuration) End(obj *server.Object) {
	u := asObjectS(obj)
	s := u.getServer()
	ud := u.UpdateDataMonster()
	s.spells.duration.CancelFor(spell.ID(ud.AIStackHead().ArgU32(0)), u)
}

func (AIActionCastDuration) Cancel(obj *server.Object) {
	u := asObjectS(obj)
	s := u.getServer()
	ud := u.UpdateDataMonster()
	s.spells.duration.CancelFor(spell.ID(ud.AIStackHead().ArgU32(0)), u)
	u.MonsterPopAction()
}

func monsterCancelDurSpell(u *server.Object, exp spell.ID) {
	if act := u.UpdateDataMonster().AIStackHead(); act.Type() == ai.ACTION_CAST_DURATION_SPELL {
		if spell.ID(act.ArgU32(0)) == exp {
			asObjectS(u).MonsterPopAction()
		}
	}
}

type AIActionMorphIntoChest struct{}

func (AIActionMorphIntoChest) Type() ai.ActionType {
	return ai.ACTION_MORPH_INTO_CHEST
}

func (AIActionMorphIntoChest) Start(_ *server.Object)  {}
func (AIActionMorphIntoChest) End(_ *server.Object)    {}
func (AIActionMorphIntoChest) Cancel(_ *server.Object) {}

func (AIActionMorphIntoChest) Update(obj *server.Object) {
	u := obj
	ud := u.UpdateDataMonster()
	if ud.Field120_3 != 0 {
		u.MonsterPopAction()
		ud.StatusFlags |= object.MonStatusMorphed
		u.Nox_xxx_monsterMarkUpdate_4E8020()
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
	u := obj
	ud := u.UpdateDataMonster()
	if ud.Field120_3 != 0 {
		u.MonsterPopAction()
		ud.StatusFlags &^= object.MonStatusMorphed
		u.Nox_xxx_monsterMarkUpdate_4E8020()
	}
}

type AIActionReport struct{}

func (AIActionReport) Type() ai.ActionType {
	return ai.ACTION_REPORT
}

func (AIActionReport) Start(_ *server.Object)  {}
func (AIActionReport) End(_ *server.Object)    {}
func (AIActionReport) Cancel(_ *server.Object) {}

func (AIActionReport) Update(obj *server.Object) {
	u := asObjectS(obj)
	s := u.getServer()
	ud := u.UpdateDataMonster()
	u.MonsterPopAction()
	s.noxScript.ScriptCallback(&ud.ScriptEndOfWaypoint, nil, u.SObj(), server.NoxEventMonsterDone)
}
