package opennox

import (
	"encoding/binary"
	"image/color"
	"math"
	"time"
	"unsafe"

	ns4 "github.com/noxworld-dev/noxscript/ns/v4"
	"github.com/noxworld-dev/opennox-lib/noxnet"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/player"
	"github.com/noxworld-dev/opennox-lib/script"
	"github.com/noxworld-dev/opennox-lib/spell"
	"github.com/noxworld-dev/opennox-lib/strman"
	"github.com/noxworld-dev/opennox-lib/types"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/common/unit/ai"
	"github.com/noxworld-dev/opennox/v1/internal/cryptfile"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
	"github.com/noxworld-dev/opennox/v1/server"
)

func asObject(p unsafe.Pointer) *Object {
	return (*Object)(p)
}
func asObjectS(p *server.Object) *Object {
	return (*Object)(unsafe.Pointer(p))
}

func (s *Server) getObjectGroupByID(id string) *script.ObjectGroup {
	g := s.MapGroups.GroupByID(id, server.MapGroupObjects)
	if g == nil {
		return nil
	}
	// may contain map name, so we load it again
	id = g.ID()
	var list []script.Object
	for it := g.First(); it != nil; it = it.Next() {
		if wl := s.Objs.GetObjectByInd(it.Data1()); wl != nil {
			list = append(list, scrObject{asObjectS(wl)})
		}
	}
	return script.NewObjectGroup(id, list...)
}

func (s *Server) getObjectFromNetCode(code int) *server.Object { // nox_server_getObjectFromNetCode_4ECCB0
	return legacy.Nox_server_getObjectFromNetCode_4ECCB0(code)
}

func (s *Server) DelayedDelete(obj *server.Object) {
	if obj == nil || obj.Flags().Has(object.FlagDestroyed) {
		return
	}
	if owner := obj.Owner(); owner != nil && owner.Class().Has(object.ClassPlayer) {
		if obj.Class().Has(object.ClassMonster) && !server.Nox_xxx_creatureIsMonitored_500CC0(owner, obj) && (obj.SubClass()&0x80 != 0) {
			legacy.Nox_xxx_monsterRemoveMonitors_4E7B60(owner, obj)
		}
	}

	if v := obj.InvHolder; v != nil {
		legacy.Sub_4ED0C0(v, obj)
	}
	legacy.Nox_xxx_playerCancelSpells_4FEAE0(obj)
	if noxflags.HasGame(noxflags.GameModeQuest) && obj.Class().Has(object.ClassMonster) {
		legacy.Sub_50E210(obj)
	}
	if obj.Class().Has(object.ClassPlayer) {
		legacy.Sub_506740(obj)
	}
	obj.ObjFlags |= uint32(object.FlagDestroyed)
	obj.DeletedNext = s.Objs.DeletedList
	s.Objs.DeletedList = obj
	obj.DeletedAt = s.Frame()
	if obj.HasTeam() {
		legacy.Nox_xxx_netChangeTeamMb_419570(obj.TeamPtr(), obj.NetCode)
	}
}

func (s *Server) DeleteAfter(obj *server.Object, frames uint32) {
	legacy.Nox_xxx_unitSetDecayTime_511660(obj, int(frames))
}

func (s *Server) FinalizeDeletingObjects() {
	var next *server.Object
	for it := s.Objs.DeletedList; it != nil; it = next {
		next = it.DeletedNext
		s.objectDeleteFinish(it)
	}
	s.Objs.DeletedList = nil
}

func (s *Server) objectDeleteFinish(obj *server.Object) {
	legacy.Nox_xxx_unitTransferSlaves_4EC4B0(obj)
	obj.SetOwner(nil)
	s.Activators.ClearOnObject(obj)
	legacy.Nox_xxx_decay_5116F0(obj)
	asObjectS(obj).dropAllItems()
	s.ObjectDeleteLast(obj)
	s.Objs.FreeObject(obj)
}

func (s *Server) ObjectDeleteLast(obj *server.Object) {
	if !obj.Flags().Has(object.FlagActive) {
		return
	}
	obj.ObjFlags &^= uint32(object.FlagActive)
	s.nox_xxx_playerLeaveObsByObserved_4E60A0(obj)
	if !noxflags.HasGame(noxflags.GameFlag20) {
		legacy.Nox_xxx_netReportDestroyObject_5289D0(obj)
	}
	legacy.Nox_xxx_unit_511810(obj)
	asObjectS(obj).SetOwner(nil)
	legacy.Nox_xxx_unitRemoveChild_4EC470(obj)
	s.sub_517870(obj)
	s.sub_4DAE50(obj)
	legacy.Sub_4ECFA0(obj)
	legacy.Sub_511DE0(obj)
	if obj.Class().HasAny(object.MaskUnits) {
		legacy.Sub_528990(obj)
	}
}

func (s *Server) deletedObjectsUpdate() {
	var (
		list *server.Object
		next *server.Object
	)
	for it := s.Objs.DeletedList; it != nil; it = next {
		next = it.DeletedNext
		if it.DeletedAt == s.Frame() {
			it.DeletedNext = list
			list = it
			s.Objs.RemoveFromUpdatable(it)
		} else {
			s.objectDeleteFinish(it)
		}
	}
	s.Objs.DeletedList = list
}

func (s *Server) ObjectsAddPending() {
	var next *server.Object
	for it := s.Objs.Pending; it != nil; it = next {
		next = it.Next()
		for it2 := it.Owner(); it2 != nil; it2 = it.Owner() {
			if !it.Flags().Has(object.FlagDestroyed) {
				break
			}
			it.SetOwner(it2.Owner())
		}
		if it.Class().Has(object.ClassMissile) {
			it.ObjNext = s.Objs.MissileList
			it.ObjPrev = nil
			if s.Objs.MissileList != nil {
				s.Objs.MissileList.ObjPrev = it
			}
			s.Objs.MissileList = it
		} else {
			if it.Flags().Has(object.FlagShadow) {
				it.ObjFlags &^= uint32(object.FlagShadow)
				legacy.Nox_xxx_unitNewAddShadow_4DA9A0(it)
			}
			if it.Flags().Has(object.FlagRespawn) && !noxflags.HasGame(noxflags.GameModeQuest) {
				legacy.Nox_xxx_respawnAdd_4EC5E0(it)
			}
			if it.Update != nil || it.Vel() != (types.Pointf{}) { // TODO: had a weird check: ... && *(*uint8)(&it.obj_class) >= 0
				s.Objs.AddToUpdatable(it)
			}
			it.ObjNext = s.Objs.List
			it.ObjPrev = nil
			if s.Objs.List != nil {
				s.Objs.List.ObjPrev = it
			}
			s.Objs.List = it
		}
		s.Map.AddObjectToIndex(it)
		if it.Collide != nil {
			legacy.Sub_5117F0(it)
		}
		if it.Init != nil {
			ccall.CallVoidPtr2(it.Init, it.CObj(), nil)
		}
		var v6 bool
		if it.Class().Has(object.ClassImmobile) {
			if it.SubClass()&0x18 != 0 {
				v6 = false
			} else {
				v6 = (^it.SubClass() >> 7) != 0
			}
		} else {
			v6 = ((uint32(it.Class()) >> 29) & 1) != 0
		}
		if it.Class().Has(object.ClassVisibleEnable) || !v6 {
			it.NeedSync()
			if !it.Class().HasAny(object.ClassClientPersist | object.ClassImmobile) {
				it.Field37 = 0
			}
		} else {
			it.MakeUnseen()
			legacy.Sub_527E00(it)
			it.Field37 = math.MaxUint32
		}
		it.ObjFlags &^= uint32(object.FlagPending)
	}
	s.Objs.Pending = nil
	for _, fnc := range s.Objs.PendingActions {
		fnc()
	}
	s.Objs.PendingActions = nil
}

func (s *Server) sub_4DAE50(obj *server.Object) {
	legacy.Nox_xxx_action_4DA9F0(obj)
	if obj.Class().Has(object.ClassMissile) {
		prev := obj.ObjPrev
		if prev != nil {
			prev.ObjNext = obj.ObjNext
		} else {
			s.Objs.MissileList = obj.ObjNext
		}
		if next := obj.ObjNext; next != nil {
			next.ObjPrev = prev
		}
	} else {
		s.Objs.RemoveFromUpdatable(obj)
		prev := obj.ObjPrev
		if prev != nil {
			prev.ObjNext = obj.ObjNext
		} else {
			s.Objs.List = obj.ObjNext
		}
		if next := obj.ObjNext; next != nil {
			next.ObjPrev = prev
		}
	}
}

func (s *Server) CreateObjectAt(a11 server.Obj, owner server.Obj, pos types.Pointf) {
	obj := server.ToObject(a11)
	if obj.Flags().HasAny(object.FlagActive | object.FlagDestroyed) {
		return
	}
	obj.ObjFlags &= 0x35E9FEDB
	obj.PrevPos = pos
	obj.PosVec = pos
	obj.NewPos = pos
	obj.Pos39 = pos
	obj.Nox_xxx_objectUnkUpdateCoords_4E7290()
	if obj.Class().HasAny(object.MaskUnits) {
		legacy.Nox_xxx_unitPostCreateNotify_4E7F10(obj)
	}
	if owner != nil {
		obj.SetOwner(server.ToObject(owner))
	}
	obj.VelVec = types.Pointf{}
	obj.ForceVec = types.Pointf{}
	obj.ObjFlags |= uint32(object.FlagActive)
	obj.Field32 = s.Frame()
	obj.Field34 = s.Frame()
	if noxflags.HasGame(noxflags.GameOnline) && !noxflags.HasGame(noxflags.GameModeQuest) && !obj.Class().Has(object.ClassMissile) &&
		(int(obj.TypeInd) == s.Types.GoldID() ||
			obj.Class().HasAny(object.ClassFood|object.ClassInfoBook|object.ClassWand|object.ClassWeapon|object.ClassArmor)) {
		obj.ObjFlags |= uint32(object.FlagNoCollide)
	}
	obj.ObjNext = s.Objs.Pending
	obj.ObjPrev = nil
	if s.Objs.Pending != nil {
		s.Objs.Pending.ObjPrev = obj
	}
	s.Objs.Pending = obj
	obj.ObjFlags |= uint32(object.FlagPending)
	if obj.TeamVal.ID != 0 && (!obj.Class().Has(object.ClassFlag) || memmap.Int32(0x973F18, 3800) >= 0) {
		if noxflags.HasGame(noxflags.GameModeCoop) || noxflags.HasGamePlay(4) {
			legacy.Nox_xxx_createAtImpl_4191D0(obj.TeamVal.ID, obj.TeamPtr(), 0, obj.NetCode, 0)
		}
	}
}

func (s *Server) deleteAllObjectsOfType(t *server.ObjectType) {
	var next *server.Object
	for it := s.Objs.First(); it != nil; it = next {
		next = it.Next()
		var next2 *server.Object
		for it2 := it.FirstItem(); it2 != nil; it2 = next2 {
			next2 = it2.NextItem()
			if int(it2.TypeInd) == t.Ind() {
				asObjectS(it2).Delete()
			}
		}
		if int(it.TypeInd) == t.Ind() {
			asObjectS(it).Delete()
		}
	}
}

var _ = [1]struct{}{}[780-unsafe.Sizeof(Object{})]

type Object server.Object

func (obj *Object) getServer() *Server {
	s := obj.Server()
	if s == nil {
		return nil
	}
	return (*Server)(s.ExtServer)
}

func (obj *Object) Server() *server.Server {
	return obj.SObj().Server()
}

func (obj *Object) UniqueKey() uintptr {
	return uintptr(unsafe.Pointer(obj))
}

func (obj *Object) SObj() *server.Object {
	return (*server.Object)(obj)
}

func (obj *Object) field(dp uintptr) unsafe.Pointer {
	return unsafe.Add(unsafe.Pointer(obj), dp)
}

func (obj *Object) ID() string {
	return alloc.GoString((*byte)(obj.IDPtr))
}

func (obj *Object) Ind() int { // aka "extent"
	return int(obj.Extent)
}

func (obj *Object) ScriptID() int {
	return obj.SObj().ScriptID()
}

func (obj *Object) ObjScriptID() int {
	return obj.SObj().ObjScriptID()
}

func (obj *Object) String() string {
	return obj.SObj().String()
}

func (obj *Object) Class() object.Class {
	return obj.SObj().Class()
}

func (obj *Object) SubClass() object.SubClass {
	return obj.SObj().SubClass()
}

func (obj *Object) MonsterClass() object.MonsterClass {
	return obj.SObj().MonsterClass()
}

func (obj *Object) ArmorClass() object.ArmorClass {
	return obj.SObj().ArmorClass()
}

func (obj *Object) WeaponClass() object.WeaponClass {
	return obj.SObj().WeaponClass()
}

func (obj *Object) OtherClass() object.OtherClass {
	return obj.SObj().OtherClass()
}

func (obj *Object) SetExt() *server.ObjectExt {
	return obj.SObj().SetExt()
}

func (obj *Object) GetExt() *server.ObjectExt {
	return obj.SObj().GetExt()
}

func (obj *Object) Flags() object.Flags {
	return obj.SObj().Flags()
}

func (obj *Object) SetFlags(v object.Flags) {
	obj.SObj().SetFlags(v)
}

func (obj *Object) FlagsEnable(v object.Flags) {
	obj.SObj().FlagsEnable(v)
}

func (obj *Object) FlagsDisable(v object.Flags) {
	obj.SObj().FlagsDisable(v)
}

func (obj *Object) Health() (cur, max int) {
	return obj.SObj().Health()
}

func (obj *Object) SetHealth(v int) {
	if obj == nil {
		return
	}
	if noxflags.HasGame(noxflags.GameSuddenDeath) {
		return
	}
	if v < 0 {
		v = 0
	}
	if _, max := obj.Health(); v > max {
		v = max
	}
	// TODO: if 0, trigger death
	legacy.Nox_xxx_unitSetHP_4E4560(obj.SObj(), uint16(v))
	if obj.Class().Has(object.ClassMonster) {
		legacy.Nox_xxx_mobInformOwnerHP_4EE4C0(obj.SObj())
	}
}

func (obj *Object) SetMaxHealth(v int) {
	if obj == nil {
		return
	}
	if noxflags.HasGame(noxflags.GameSuddenDeath) {
		return
	}
	if v < 0 {
		v = 0
	}
	h := obj.HealthData
	if h == nil {
		return
	}
	// TODO: verify it works in MP
	// TODO: if it's the player, we need to adjust GUI health bars
	h.Max = uint16(v)
	obj.SetHealth(v)
}

func (obj *Object) Mana() (cur, max int) {
	return obj.SObj().Mana()
}

func (obj *Object) SetMana(v int) {
	if obj == nil {
		return
	}
	if v < 0 {
		v = 0
	}
	if _, max := obj.Mana(); v > max {
		v = max
	}
	if obj.Class().Has(object.ClassPlayer) {
		p := obj.UpdateDataPlayer()
		if p == nil {
			return
		}
		cur := int(p.ManaCur)
		p.ManaPrev = uint16(cur)
		p.ManaCur = uint16(v)
		pt := p.Player
		legacy.Nox_xxx_protectMana_56F9E0(int(pt.ProtUnitManaCur), int16(v-cur))
	} else if obj.Class().Has(object.ClassImmobile) && obj.SubClass().AsOther().HasAny(object.OtherVisibleObelisk|object.OtherInvisibleObelisk) {
		ud := obj.UpdateDataObelisk()
		if ud == nil {
			return
		}
		ud.Mana = int32(v)
		obj.NeedSync()
	}
}

func (obj *Object) SetMaxMana(v int) {
	if obj == nil {
		return
	}
	if v < 0 {
		v = 0
	}
	if obj.Class().Has(object.ClassPlayer) {
		p := obj.UpdateDataPlayer()
		if p == nil {
			return
		}
		p.ManaMax = uint16(v)
	} else if obj.Class().Has(object.ClassImmobile) && obj.SubClass().AsOther().HasAny(object.OtherVisibleObelisk|object.OtherInvisibleObelisk) {
		// TODO: looks like max mana for obelisks is hardcoded; set regular mana instead
		ud := obj.UpdateDataObelisk()
		if ud == nil {
			return
		}
		ud.Mana = int32(v)
		obj.NeedSync()
	}
	obj.SetMana(v)
}

func (obj *Object) CurrentSpeed() float32 {
	return obj.SObj().CurrentSpeed()
}

func (obj *Object) BaseSpeed() float32 {
	return obj.SObj().BaseSpeed()
}

func (obj *Object) SetBaseSpeed(v float32) {
	obj.SObj().SetBaseSpeed(v)
}

func (obj *Object) Strength() int {
	return obj.SObj().Strength()
}

func (obj *Object) SetStrength(v int) {
	obj.SObj().SetStrength(v)
}

func (obj *Object) IsMovable() bool {
	return obj.SObj().IsMovable()
}

func (obj *Object) FindByID(id string) *server.Object {
	return obj.SObj().FindByID(id)
}

func (obj *Object) NeedSync() { // nox_xxx_unitNeedSync_4E44F0
	obj.SObj().NeedSync()
}

func (obj *Object) MakeUnseen() { // nox_xxx_objectMakeUnseenByNoone_4E44E0
	obj.SObj().MakeUnseen()
}

func (obj *Object) Next() *server.Object { // nox_server_getNextObject_4DA7A0, nox_xxx_getNextUpdatable2Object_4DA850, nox_server_getNextObjectUninited_4DA880
	if obj == nil {
		return nil
	}
	return obj.SObj().Next()
}

func (obj *Object) FirstItem() *server.Object { // nox_xxx_inventoryGetFirst_4E7980
	return obj.InvFirstItem
}

func (obj *Object) NextItem() *server.Object {
	return obj.InvNextItem
}

func (obj *Object) InventoryHolder() *server.Object {
	return obj.InvHolder
}

func (obj *Object) HasItem(item *server.Object) bool {
	return obj.SObj().HasItem(item)
}

func (obj *Object) Inventory() []*server.Object {
	var out []*server.Object
	for p := obj.FirstItem(); p != nil; p = p.NextItem() {
		out = append(out, p)
	}
	return out
}

func (obj *Object) Equipment() []*server.Object {
	var out []*server.Object
	for p := obj.FirstItem(); p != nil; p = p.NextItem() {
		if p.Flags().Has(object.FlagEquipped) {
			out = append(out, p)
		}
	}
	return out
}

func (obj *Object) NextOwned512() *server.Object {
	return obj.SObj().NextOwned512()
}

func (obj *Object) FirstOwned516() *server.Object {
	return obj.SObj().FirstOwned516()
}

func (obj *Object) GetOwned516() []*server.Object {
	var out []*server.Object
	for p := obj.FirstOwned516(); p != nil; p = p.NextOwned512() {
		out = append(out, p)
	}
	return out
}

func (obj *Object) HasEnchant(v server.EnchantID) bool { // nox_xxx_testUnitBuffs_4FF350
	return obj.SObj().HasEnchant(v)
}

func (obj *Object) EnchantDur(v server.EnchantID) int { // nox_xxx_unitGetBuffTimer_4FF550
	return obj.SObj().EnchantDur(v)
}

func (obj *Object) EnchantPower(v server.EnchantID) int { // nox_xxx_buffGetPower_4FF570
	return obj.SObj().EnchantPower(v)
}

func (obj *Object) ApplyEnchant(v server.EnchantID, dur, power int) { // nox_xxx_buffApplyTo_4FF380
	if obj == nil || v >= 32 {
		return
	}
	legacy.Nox_xxx_buffApplyTo_4FF380(obj.SObj(), v, dur, power)
}

func (obj *Object) DisableEnchant(v server.EnchantID) { // nox_xxx_spellBuffOff_4FF5B0
	if obj == nil || v >= 32 {
		return
	}
	legacy.Nox_xxx_spellBuffOff_4FF5B0(obj.SObj(), v)
}

func (obj *Object) ObjectTypeC() *server.ObjectType {
	return obj.SObj().ObjectTypeC()
}

func (obj *Object) ObjectType() script.ObjectType {
	t := obj.ObjectTypeC()
	if t == nil {
		return nil
	}
	return noxScriptObjType{t}
}

func (obj *Object) TeamPtr() *server.ObjectTeam {
	if obj == nil {
		return nil
	}
	return obj.SObj().TeamPtr()
}

func (obj *Object) HasTeam() bool {
	if obj == nil {
		return false
	}
	return obj.SObj().HasTeam()
}

func (obj *Object) Team() *server.Team {
	if obj == nil {
		return nil
	}
	return obj.SObj().Team()
}

func (obj *Object) Owner() *server.Object {
	return obj.SObj().Owner()
}

func (obj *Object) SetOwner(owner *server.Object) {
	obj.SObj().SetOwner(owner)
}

func (obj *Object) SetMonsterStatus(v object.MonsterStatus) {
	obj.SObj().SetMonsterStatus(v)
}

func (obj *Object) MonsterStatusEnable(v object.MonsterStatus) {
	obj.SObj().MonsterStatusEnable(v)
}

func (obj *Object) MonsterStatusDisable(v object.MonsterStatus) {
	obj.SObj().MonsterStatusDisable(v)
}

func (obj *Object) Pos() types.Pointf {
	return obj.SObj().Pos()
}

func (obj *Object) Vel() types.Pointf {
	return obj.SObj().Vel()
}

func (obj *Object) Force() types.Pointf {
	return obj.SObj().Force()
}

func (obj *Object) Dir1() server.Dir16 {
	return obj.SObj().Dir1()
}

func (obj *Object) Dir2() server.Dir16 {
	return obj.SObj().Dir2()
}

func (obj *Object) Z() float32 {
	return obj.ZVal
}

func (obj *Object) curSpeed() float32 {
	if obj == nil {
		return 0
	}
	return obj.SpeedCur
}

func (obj *Object) setAllDirs(dir server.Dir16) {
	obj.Direction1 = dir
	obj.Direction2 = dir
}

func (obj *Object) SetPos(pos types.Pointf) {
	if obj == nil {
		return
	}
	if obj.Class().Has(object.ClassImmobile) {
		return
	}
	s := obj.Server()
	ss := obj.getServer()
	if int(obj.PosVec.X) != int(pos.X) || int(obj.PosVec.Y) != int(pos.Y) {
		obj.NeedSync()
	}
	obj.NewPos = pos
	obj.PosVec = pos
	obj.PrevPos = pos
	ss.nox_xxx_moveUpdateSpecial_517970(obj.SObj())
	if obj.Collide != nil {
		legacy.Nox_xxx_unitHasCollideOrUpdateFn_537610(obj.SObj())
	}
	if obj.ObjClass&6 != 0 {
		obj.sub_537540()
	}
	if obj.Class().Has(object.ClassMonster) {
		obj.sub_5346D0()
	}
	ss.nox_xxx_teleportAllPixies_4FD090(obj.SObj())
	if obj.ObjClass&6 != 0 {
		legacy.Nox_xxx_frameCounterSetCopyToNextFrame_5281D0()
	}
	if obj.Class().Has(object.ClassPlayer) && noxflags.HasGame(noxflags.GameOnline) {
		ud := obj.UpdateDataPlayer()
		pl := ud.Player
		ud.Field68 = s.Frame()
		s.Sub4DE4D0(int(pl.PlayerInd))
		var buf [5]byte
		buf[0] = byte(noxnet.MSG_FORGET_DRAWABLES)
		binary.LittleEndian.PutUint32(buf[1:], s.Frame())
		s.NetSendPacketXxx1(pl.Index(), buf[:5], 0, 0)
	}
	if obj.Class().Has(object.ClassPlayer) {
		pl := obj.UpdateDataPlayer().Player
		if pl.CameraFollowObj == nil && pl.Field3680&0x3 == 0 {
			pl.Pos3632Vec = obj.PosVec
		}
	}
}

func (obj *Object) sub_537540() {
	if obj == nil {
		return
	}
	s := obj.getServer()
	for it := s.Players.FirstUnit(); it != nil; it = s.Players.NextUnit(it) {
		if it.UpdateDataPlayer().HarpoonTarg == obj.SObj() {
			s.abilities.harpoon.breakForOwner(it, true)
		}
	}
}

func (obj *Object) sub_5346D0() {
	ud := obj.UpdateDataMonster()
	ud.Field2 = 0
	ud.Field74 = 0
}

// ApplyForce adds a new force vector to the object. If another force in effect, it will adds up.
func (obj *Object) ApplyForce(p types.Pointf) {
	obj.SObj().ApplyForce(p)
}

func (obj *Object) SetZ(z float32) {
	legacy.Nox_xxx_unitRaise_4E46F0(obj.SObj(), z)
}

func (obj *Object) Push(vec types.Pointf, force float32) {
	obj.SObj().Push(vec, force)
}

func (obj *Object) PushTo(p types.Pointf) {
	obj.SObj().PushTo(p)
}

func (obj *Object) IsEnabled() bool {
	return obj.SObj().IsEnabled()
}

// Toggle the object's enable state.
// The returning boolean represents the enabled state of the object before toggled.
func (obj *Object) Toggle() bool {
	if obj.IsEnabled() {
		legacy.Nox_xxx_objectSetOff_4E7600(obj.SObj())
		return true
	} else {
		legacy.Nox_xxx_objectSetOn_4E75B0(obj.SObj())
		return false
	}
}

func (obj *Object) Enable(enable bool) {
	if obj == nil {
		return
	}
	if enable {
		legacy.Nox_xxx_objectSetOn_4E75B0(obj.SObj())
	} else {
		legacy.Nox_xxx_objectSetOff_4E7600(obj.SObj())
	}
}

func (obj *Object) Delete() {
	obj.getServer().DelayedDelete(obj.SObj())
}

func (obj *Object) DeleteAfter(frames uint32) {
	obj.getServer().DeleteAfter(obj.SObj(), frames)
}

func (obj *Object) UpdateDataPlayer() *server.PlayerUpdateData {
	return obj.SObj().UpdateDataPlayer()
}

func (obj *Object) UpdateDataMonster() *server.MonsterUpdateData {
	return obj.SObj().UpdateDataMonster()
}

func (obj *Object) UpdateDataMonsterGen() *server.MonsterGenUpdateData {
	return obj.SObj().UpdateDataMonsterGen()
}

func (obj *Object) UpdateDataObelisk() *server.ObeliskUpdateData {
	return obj.SObj().UpdateDataObelisk()
}

func (obj *Object) UpdateDataMissile() *server.MissileUpdateData {
	return obj.SObj().UpdateDataMissile()
}

func (obj *Object) UpdateDataElevator() *server.ElevatorUpdateData {
	return obj.SObj().UpdateDataElevator()
}

func (obj *Object) UpdateDataMover() *server.MoverUpdateData {
	return obj.SObj().UpdateDataMover()
}

func (obj *Object) ControllingPlayer() *Player {
	return obj.SObj().ControllingPlayer()
}

func (obj *Object) CallUpdate() {
	if obj.Update == nil {
		return
	}
	switch obj.Update {
	case unsafe.Pointer(legacy.Get_nox_xxx_updatePlayer_4F8100()):
		nox_xxx_updatePlayer_4F8100(obj.SObj())
	case unsafe.Pointer(legacy.Get_nox_xxx_updatePlayerObserver_4E62F0()):
		nox_xxx_updatePlayerObserver_4E62F0(obj.SObj())
	case unsafe.Pointer(legacy.Get_nox_xxx_updateHarpoon_54F380()):
		nox_xxx_updateHarpoon_54F380(obj.SObj())
	case unsafe.Pointer(legacy.Get_nox_xxx_updatePixie_53CD20()):
		nox_xxx_updatePixie_53CD20(obj.SObj())
	default:
		obj.SObj().CallUpdate()
	}
}

func (obj *Object) CallXfer(a2 unsafe.Pointer) error {
	switch obj.Xfer {
	case unsafe.Pointer(legacy.Get_nox_xxx_XFerDefault_4F49A0()):
		return nox_xxx_XFerDefault4F49A0(cryptfile.Global(), obj.SObj(), a2)
	}
	return obj.SObj().CallXfer(a2)
}

func (obj *Object) CallDamage(who, a3 server.Obj, dmg int, typ object.DamageType) bool {
	return obj.SObj().CallDamage(who, a3, dmg, typ)
}

func (obj *Object) CallCollide(a2, a3 int) {
	obj.SObj().CallCollide(a2, a3)
}

func (obj *Object) CallDrop(it server.Obj, pos types.Pointf) int {
	if obj.Drop == nil {
		return 0
	}
	switch obj.Drop {
	case unsafe.Pointer(legacy.Get_nox_objectDropAudEvent_4EE2F0()):
		cpos, free := alloc.New(types.Pointf{})
		defer free()
		*cpos = pos
		return int(nox_objectDropAudEvent_4EE2F0(obj.SObj(), server.ToObject(it), cpos))
	default:
		return obj.SObj().CallDrop(it, pos)
	}
}

func (obj *Object) forceDrop(item *server.Object) int { // nox_xxx_invForceDropItem_4ED930
	s := obj.Server()
	pos := s.RandomReachablePointAround(50.0, obj.Pos())
	return obj.forceDropAt(item, pos)
}

func (obj *Object) forceDropAt(item *server.Object, pos types.Pointf) int { // nox_xxx_drop_4ED790
	return legacy.Nox_xxx_drop_4ED790(obj.SObj(), item, pos)
}

func (obj *Object) CanSee(obj2 *server.Object) bool {
	return obj.SObj().CanSee(obj2)
}

func (obj *Object) FindOwnerChainPlayer() *server.Object { // nox_xxx_findParentChainPlayer_4EC580
	return obj.SObj().FindOwnerChainPlayer()
}

func (obj *Object) HasOwner(owner *server.Object) bool {
	return obj.SObj().HasOwner(owner)
}

func (obj *Object) dropAllItems() {
	legacy.Nox_xxx_dropAllItems_4EDA40(obj.SObj())
}

func (obj *Object) MoveTo(p types.Pointf) {
	// TODO: originally, this method required Waypoint as an argument
	//       but now we actually have WalkTo and friends which accept both position or a waypoint (in LUA)
	//       so we will call WalkTo here for now, but that Waypoint requirement was probably done for a reason
	obj.WalkTo(p)
}

func (obj *Object) WalkTo(p types.Pointf) {
	legacy.Nox_xxx_monsterWalkTo_514110(obj.SObj(), p.X, p.Y)
}

func (obj *Object) SetDir(v server.Dir16) {
	obj.SObj().SetDir(v)
}

func (obj *Object) LookAt(p types.Pointf) {
	obj.SObj().LookAt(p)
}

func (obj *Object) LookAtDir(dir int) {
	legacy.Nox_xxx_monsterLookAt_5125A0(obj.SObj(), dir)
}

func (obj *Object) LookAngle(ang int) {
	v := nox_xxx_math_roundDir(int32(ang))
	obj.SetDir(server.Dir16(v))
}

func (obj *Object) Freeze(freeze bool) {
	if freeze {
		legacy.Nox_xxx_unitFreeze_4E79C0(obj.SObj(), 1)
	} else {
		legacy.Nox_xxx_unitUnFreeze_4E7A60(obj.SObj(), 1)
	}
}

func (obj *Object) Wander() {
	legacy.Nox_xxx_scriptMonsterRoam_512930(obj.SObj())
}

func (obj *Object) Return() {
	legacy.Nox_server_gotoHome(obj.SObj())
}

func (obj *Object) Idle() {
	legacy.Nox_xxx_unitIdle_515820(obj.SObj())
}

func (obj *Object) IsAttackedBy(obj2 *server.Object) bool {
	if obj2 == nil {
		return false
	}
	return obj.getServer().IsEnemyTo(obj.SObj(), obj2)
}

func (obj *Object) Follow(targ ns4.Positioner) {
	if targ == nil {
		return
	}
	if v, ok := targ.(script.ObjectWrapper); ok {
		targ = v.GetObject()
	}
	cobj := server.ToObject(targ.(server.Obj))
	legacy.Nox_xxx_unitSetFollow_5158C0(obj.SObj(), cobj)
}

func (obj *Object) Flee(target ns4.Positioner, dt ns4.Duration) {
	var targ *server.Object
	if t, ok := target.(server.Obj); ok {
		targ = server.ToObject(t)
	}
	nox_server_scriptFleeFrom_515F70(obj.SObj(), targ, obj.Server().AsFrames(dt))
}

func (obj *Object) Aggression() float32 {
	return obj.SObj().Aggression()
}

func (obj *Object) SetAggression(v float32) {
	obj.SObj().SetAggression(v)
}

func (obj *Object) RetreatLevel() float32 {
	return obj.SObj().RetreatLevel()
}

func (obj *Object) SetRetreatLevel(v float32) {
	obj.SObj().SetRetreatLevel(v)
}

func (obj *Object) RegroupLevel() float32 {
	return obj.SObj().RegroupLevel()
}

func (obj *Object) SetRegroupLevel(v float32) {
	obj.SObj().SetRegroupLevel(v)
}

func (obj *Object) Attack(targ ns4.Positioner) {
	if wr, ok := targ.(script.ObjectWrapper); ok {
		targ = wr.GetObject()
	}
	var tobj *server.Object
	switch targ := targ.(type) {
	case nil:
		tobj = nil
	case nsObj:
		tobj = targ.SObj()
	case server.Obj:
		tobj = server.ToObject(targ)
	default:
		// Fallback to hitting position (ground).
		// TODO: pick melee/ranged automatically
		obj.HitMelee(targ.Pos())
		return
	}
	nox_xxx_mobSetFightTarg_515D30(obj.SObj(), tobj)
}

func (obj *Object) HitMelee(pos types.Pointf) {
	nox_xxx_monsterActionMelee_515A30(obj.SObj(), pos)
}

func (obj *Object) HitRanged(pos types.Pointf) {
	nox_xxx_monsterMissileAttack_515B80(obj.SObj(), pos)
}

func (obj *Object) Guard(p1, p2 types.Pointf, distance float32) {
	nox_xxx_monsterGoPatrol_515680(obj.SObj(), p1, p2, distance)
}

func (obj *Object) Hunt() {
	legacy.Nox_xxx_unitHunt_5157A0(obj.SObj())
}

func (obj *Object) AddGold(v int) {
	if v < 0 {
		legacy.Nox_xxx_playerSubGold_4FA5D0(obj.SObj(), v)
	} else {
		legacy.Nox_xxx_playerAddGold_4FA590(obj.SObj(), v)
	}
}

func (obj *Object) LookAtDirection(dir ns4.Direction) {
	if obj.Class().Has(object.ClassMonster) && !obj.Flags().Has(object.FlagDead) {
		obj.LookAtDir(int(dir))
	}
}

func (obj *Object) LookWithAngle(angle int) {
	dir := server.Dir16(nox_xxx_math_roundDir(int32(angle)))
	obj.setAllDirs(dir)
}

func (obj *Object) LookAtObject(targ ns4.Positioner) {
	if targ == nil {
		return
	}
	dir := server.DirFromVec(targ.Pos().Sub(obj.Pos()))
	obj.setAllDirs(dir)
}

func (obj *Object) Move(w ns4.WaypointObj) {
	if w == nil {
		return
	}
	if obj.Flags().Has(object.FlagDead) {
		return
	}
	wp := w.(*server.Waypoint)
	legacy.Nox_server_scriptMoveTo_5123C0(obj.SObj(), wp)
}

func (obj *Object) Pause(dt ns4.Duration) {
	sub_516090(obj.SObj(), obj.Server().AsFrames(dt))
}

func (obj *Object) DoDamage(source *server.Object, amount int, typ object.DamageType) bool {
	if obj == nil || amount <= 0 {
		return false
	}
	if typ == object.DamageTrue {
		legacy.Nox_xxx_unitDamageClear_4EE5E0(obj.SObj(), amount)
		return true
	}
	owner := source.FindOwnerChainPlayer()
	return obj.CallDamage(owner, source, amount, typ)
}

func (obj *Object) Chat(message ns4.StringID) {
	obj.ChatTimer(message, ns4.Frames(0))
}

func (obj *Object) ChatTimer(message ns4.StringID, dt ns4.Duration) {
	s := obj.Server()
	v, _ := s.Strings().GetVariantInFile(strman.ID(message), "CScrFunc.c")
	legacy.Nox_xxx_netSendChat_528AC0(obj.SObj(), v.Str, uint16(s.AsFrames(dt)))
	if noxflags.HasGame(noxflags.GameModeCoop) {
		legacy.Nox_xxx_playDialogFile_44D900(v.Str2, 100)
	}
}

func (obj *Object) ChatStr(message string) {
	obj.ChatStrTimer(message, ns4.Frames(0))
}

func (obj *Object) ChatStrTimer(message string, dt ns4.Duration) {
	legacy.Nox_xxx_netSendChat_528AC0(obj.SObj(), message, uint16(obj.Server().AsFrames(dt)))
}

func (obj *Object) DestroyChat() {
	obj.SObj().DestroyChat()
}

func (obj *Object) CreateMover(wp ns4.WaypointObj, speed float32) *server.Object {
	s := obj.getServer()
	mv := s.NewObjectByTypeID("Mover")
	if mv == nil {
		return nil
	}
	s.CreateObjectAt(mv, nil, obj.Pos())
	mv.VelVec = types.Pointf{}

	ud := mv.UpdateDataMover()
	ud.Field_7 = obj.SObj()
	ud.Field_2 = int32(wp.WaypointScriptID())
	ud.Field_1 = speed
	ud.Field_0 = 0

	asObjectS(mv).Enable(true)
	s.Objs.AddToUpdatable(mv)
	return mv
}

func (obj *Object) ZombieStayDown() {
	obj.SObj().ZombieStayDown()
}

func (obj *Object) RaiseZombie() {
	legacy.Sub_516D00(obj.SObj())
}

func (obj *Object) DoPickup(item *server.Object) bool {
	if item == nil {
		return false
	}
	s := obj.Server()
	it := item
	gold := s.Types.GoldID()
	goldPile := s.Types.GoldPileID()
	goldChest := s.Types.GoldChestID()
	isPlayerInCoop := noxflags.HasGame(noxflags.GameModeCoop) && obj.Class().Has(object.ClassPlayer)
	if isPlayerInCoop {
		if f := s.Frame(); *memmap.PtrUint32(0x5D4594, 2386844) != f {
			*memmap.PtrUint32(0x5D4594, 2386844) = f
			legacy.Set_dword_5d4594_2386848(0)
			legacy.Set_dword_5d4594_2386852(0)
		}
		if typ := int(it.TypeInd); typ != gold && typ != goldPile && typ != goldChest {
			legacy.Nox_xxx_playerCanCarryItem_513B00(obj.SObj(), it)
		}
	}
	if legacy.Nox_xxx_inventoryServPlace_4F36F0(obj.SObj(), it, 1, 1) == 0 {
		return false
	}
	if isPlayerInCoop && int(it.TypeInd) != gold {
		legacy.Inc_dword_5d4594_2386848()
	}
	return true
}

func (obj *Object) DoDrop(item *server.Object) bool {
	if item == nil {
		return false
	}
	return obj.forceDrop(item) != 0
}

func (obj *Object) Equip(item *server.Object) bool {
	if item == nil {
		return false
	}
	it := item
	if obj.Flags().Has(object.FlagPending) || it.Flags().Has(object.FlagPending) {
		// TODO: figure out a way to equip pending items directly
		obj.Server().Objs.QueueAction(func() {
			obj.Equip(item)
		})
		return true
	}
	if !obj.HasItem(item) {
		if !obj.DoPickup(item) {
			return false
		}
	}
	return legacy.Nox_xxx_playerTryEquip_4F2F70(obj.SObj(), it)
}

func (obj *Object) HasEquipment(item *server.Object) bool {
	if !obj.HasItem(item) {
		return false
	}
	return item.Flags().Has(object.FlagEquipped)
}

func (obj *Object) Unequip(item *server.Object) bool {
	if item == nil {
		return false
	}
	if !obj.HasEquipment(item) {
		return false
	}
	it := item
	return legacy.Nox_xxx_playerTryDequip_4F2FB0(obj.SObj(), it)
}

func (obj *Object) TeamEqual(tm *server.Team) bool {
	if tm == nil {
		return !obj.HasTeam()
	}
	return legacy.Nox_xxx_teamCompare2_419180(obj.TeamPtr(), tm.ID()) != 0
}

func (obj *Object) SetTeam(tm *server.Team) {
	if tm == nil {
		return // TODO: support clearing the team
	}
	// TODO: check arg3 and arg5
	legacy.Nox_xxx_createAtImpl_4191D0(tm.ID(), obj.TeamPtr(), 1, obj.NetCode, 0)
}

func (obj *Object) IsLocked() bool {
	return obj.SObj().IsLocked()
}

func (obj *Object) Lock(lock bool) {
	obj.SObj().Lock(lock)
}

func (obj *Object) RestoreHealth(amount int) {
	if amount <= 0 {
		return
	}
	legacy.Nox_xxx_unitAdjustHP_4EE460(obj.SObj(), amount)
}

func (obj *Object) SetHealthRegenToMaxDur(t time.Duration) {
	obj.SetExt().HealthRegenToMax = t
}

func (obj *Object) SetHealthRegenPerFrame(v float32) {
	obj.SetExt().HealthRegenPerFrame = v
}

func (obj *Object) GetGold() int {
	if obj == nil {
		return 0
	}
	return legacy.Nox_object_getGold_4FA6D0(obj.SObj())
}

func (obj *Object) ChangeGold(delta int) {
	if obj == nil {
		return
	}
	legacy.Nox_object_setGold_4FA620(obj.SObj(), delta)
}

func (obj *Object) Cast(sp spell.ID, lvl int, targ script.Positioner) bool {
	if !sp.Valid() || lvl <= 0 {
		return false
	}
	var s *Server = obj.getServer()
	sa, freeArg := alloc.New(server.SpellAcceptArg{})
	defer freeArg()
	if targ == nil {
		targ = obj
	}
	if o, ok := targ.(server.Obj); ok {
		sa.Obj = server.ToObject(o)
	}
	sa.Pos = targ.Pos()
	return s.castSpell(sp, lvl, obj.SObj(), sa)
}

func (obj *Object) ClearActionStack() { // aka nox_xxx_monsterClearActionStack_50A3A0
	obj.SObj().ClearActionStack()
}

func (obj *Object) MonsterPushAction(act ai.ActionType, args ...any) *server.AIStackItem { // aka nox_xxx_monsterPushAction_50A260
	return obj.SObj().MonsterPushAction(act, args...)
}

func (obj *Object) MonsterActionIsScheduled(act ai.ActionType) bool { // nox_xxx_monsterIsActionScheduled_50A090
	return obj.SObj().MonsterActionIsScheduled(act)
}

func (obj *Object) CountSubOfType(typ int) int { // nox_xxx_unitIsUnitTT_4E7C80
	return obj.SObj().CountSubOfType(typ)
}

func (obj *Object) SetTrapSpells(spells ...spell.ID) {
	setBomberSpells(obj.SObj(), spells...)
}

func nox_xxx_unitIsUnitTT_4E7C80(a1 *server.Object, a2 int) int {
	return asObjectS(a1).CountSubOfType(a2)
}

func nox_xxx_script_forcedialog_548CD0(obj, obj2 *server.Object) {
	legacy.Nox_xxx_script_forcedialog_548CD0(obj, obj2)
}

func nox_xxx_startShopDialog_548DE0(player, npc *server.Object, snd sound.ID, str strman.ID) {
	if str == "" {
		return
	}
	if player == nil || !player.Class().Has(object.ClassPlayer) {
		return
	}
	if npc == nil || !npc.Class().Has(object.ClassMonster) {
		return
	}
	s := noxServer
	tud := npc.UpdateDataMonster()
	pud := player.UpdateDataPlayer()
	pud.DialogWith = npc

	buf, free := alloc.Make([]byte{}, 135)
	defer free()
	buf[0] = byte(noxnet.MSG_DIALOG)
	buf[1] = 3
	copy(buf[2:34], str)
	v7 := legacy.Sub_4E39F0_obj_db(npc)
	alloc.StrCopy16B(buf[34:96], v7)
	buf[96] = 0
	buf[97] = 0
	binary.LittleEndian.PutUint32(buf[98:], uint32(snd))
	if pname := tud.DialogPortrait(); pname != "" {
		copy(buf[102:134], pname)
	} else {
		copy(buf[102:134], "ShopKeeperPic")
	}
	buf[134] = tud.DialogFlags
	pl := player.ControllingPlayer()
	s.NetSendPacketXxx0(pl.Index(), buf[:135], 0, 1)
	legacy.Nox_xxx_unitFreeze_4E79C0(player, 0)
}

func nox_xxx_mobSetFightTarg_515D30(obj, targ *server.Object) {
	legacy.Nox_xxx_mobSetFightTarg_515D30(obj, targ)
}

func nox_server_scriptFleeFrom_515F70(obj, targ *server.Object, df int) {
	legacy.Nox_server_scriptFleeFrom_515F70(obj, targ, df)
}

func nox_xxx_monsterGoPatrol_515680(obj *server.Object, p1, p2 types.Pointf, dist float32) {
	legacy.Nox_xxx_monsterGoPatrol_515680(obj, p1, p2, dist)
}

func nox_xxx_monsterActionMelee_515A30(obj *server.Object, pos types.Pointf) {
	legacy.Nox_xxx_monsterActionMelee_515A30(obj, pos)
}

func nox_xxx_monsterMissileAttack_515B80(obj *server.Object, pos types.Pointf) {
	legacy.Nox_xxx_monsterMissileAttack_515B80(obj, pos)
}

func sub_516090(obj *server.Object, df int) {
	legacy.Sub_516090(obj, df)
}

func (obj *Object) MonsterIsInjured() bool {
	return obj.SObj().MonsterIsInjured()
}

func (obj *Object) MonsterLookAtDamager() bool {
	return obj.SObj().MonsterLookAtDamager()
}

func (obj *Object) SetColor(ind int, cl color.Color) {
	obj.SObj().SetColor(ind, cl)
}

func sub_534020(a1 *server.Object) int32 {
	return int32((a1.ObjSubClass >> 10) & 1)
}

func nox_xxx_playerSetState_4FA020(u *server.Object, st server.PlayerState) bool {
	s := noxServer
	res := true
	ud := u.UpdateDataPlayer()
	if u.Flags().Has(object.FlagDead) && st != server.PlayerState3 && st != server.PlayerState4 {
		return false
	}
	if !noxflags.HasGame(2048) {
		if u.Flags().Has(object.FlagAirborne) {
			if st == server.PlayerState30 {
				return false
			}
		}
	}
	switch st {
	case server.PlayerState24, server.PlayerStateShakeFist, server.PlayerStateLaugh, server.PlayerState27, server.PlayerStatePoint, server.PlayerState29:
		if s.Abils.IsActive(u, server.AbilityBerserk) {
			return false
		}
		if ud.State == server.PlayerState12 {
			return false
		}
	}
	if ud.State == server.PlayerState1 {
		if st == server.PlayerState1 {
			goto LABEL_26
		}
		if s.Abils.IsActiveVal(u, server.AbilityWarcry) && st != server.PlayerState4 && st != server.PlayerState3 {
			return false
		}
	}
	if st != 1 {
		*(*uint8)(unsafe.Pointer(&ud.Player.Field8)) = 0
		switch st {
		case server.PlayerState3, server.PlayerState4:
			ud.Field40_0 = 0
			ud.Field41 = 0
		case server.PlayerStateShakeFist:
			if ud.State != st {
				s.Audio.EventObj(sound.SoundTauntShakeFist, u, 0, 0)
			}
		case server.PlayerStateLaugh:
			if ud.State != st {
				s.Audio.EventObj(sound.SoundTauntLaugh, u, 0, 0)
			}
		case server.PlayerStatePoint:
			if ud.State != st {
				s.Audio.EventObj(sound.SoundTauntPoint, u, 0, 0)
			}
		}
		goto LABEL_42
	}
LABEL_26:
	if ud.Field0 <= s.Frame() {
		pl := ud.Player
		ud.Field0 = 0
		if pl.Field4 != 0 {
			*(*uint8)(unsafe.Pointer(&pl.Field8)) = 0
		} else {
			*(*uint8)(unsafe.Pointer(&pl.Field8)) = uint8(int8(s.Rand.Logic.IntClamp(23, 24)))
			if ud.Player.PlayerClass() == player.Warrior && s.Rand.Logic.IntClamp(0, 100) > 75 {
				*(*uint8)(unsafe.Pointer(&pl.Field8)) = 25
			}
			asObjectS(u).DisableEnchant(server.ENCHANT_INVISIBLE)
			asObjectS(u).DisableEnchant(server.ENCHANT_INVULNERABLE)
			s.Spells.Dur.CancelFor(spell.SPELL_OVAL_SHIELD, u)
		}
	} else {
		res = false
		st = ud.State
	}
LABEL_42:
	if ud.State != st {
		ud.State2 = ud.State
		ud.State = st
		u.Field34 = s.Frame()
		ud.Field59_0 = 0
	}
	if st == server.PlayerState30 {
		ud.Field41 = s.Frame()
	}
	return res
}
