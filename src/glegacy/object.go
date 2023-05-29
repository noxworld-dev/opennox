package legacy

import (
	"image"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/spell"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	Sub_47A1F0                                 func()
	Nox_xxx_unitMonsterInit_4F0040             func(obj *server.Object)
	Nox_xxx_setNPCColor_4E4A90                 func(obj *server.Object, a2 byte, a3 *server.Color3)
	Nox_xxx_checkSummonedCreaturesLimit_500D70 func(u *server.Object, ind int) bool
	Nox_xxx_unitDoSummonAt_5016C0              func(typID int, pos types.Pointf, owner *server.Object, dir server.Dir16) *server.Object
	Sub_57AEE0                                 func(sp spell.ID, u *server.Object) bool
	Sub_4E71F0                                 func(obj *server.Object)
	Nox_bomberDead_54A150                      func(obj *server.Object) int
	Nox_xxx_dieGlyph_54DF30                    func(obj *server.Object)
	Nox_xxx_collideGlyph_4E9A00                func(obj, obj2 *server.Object)
)

var _ = [1]struct{}{}[28-unsafe.Sizeof(Nox_object_Missile_data_t{})]

type Nox_object_Missile_data_t struct {
	Owner    *server.Object // 0, 0
	Target   *server.Object // 1, 4
	Field_8  uint32         // 2, 8
	SpellID  int32          // 3, 12
	Field_16 uint32         // 4, 16
	Field_20 uint32         // 5, 20
	Field_24 uint32         // 6, 24
}

var _ = [1]struct{}{}[20-unsafe.Sizeof(Nox_object_Elevator_data_t{})]

type Nox_object_Elevator_data_t struct {
	Field_0 uint32  // 0, 0
	Field_1 uint32  // 1, 4
	Field_2 uint32  // 2, 8
	Field_3 byte    // 3, 12
	_       [3]byte // 3, 13
	Field_4 uint32  // 4, 16
}

var _ = [1]struct{}{}[36-unsafe.Sizeof(Nox_object_Mover_data_t{})]

type Nox_object_Mover_data_t struct {
	Field_0 uint8          // 0, 0
	_       [3]byte        // 0, 1
	Field_1 float32        // 1, 4
	Field_2 int32          // 2, 8
	Field_3 uint32         // 3, 12
	Field_4 uint32         // 4, 16
	Field_5 uint32         // 5, 20
	Field_6 uint32         // 6, 24
	Field_7 *server.Object // 7, 28
	Field_8 uint32         // 8, 32
}

type nox_object_t = server.Object

func asObjectC(p *server.Object) *nox_object_t {
	return (*nox_object_t)(p.CObj())
}

func AsObjectP(p unsafe.Pointer) *server.Object {
	return (*server.Object)(p)
}

func asObjectS(p *nox_object_t) *server.Object {
	return (*server.Object)(unsafe.Pointer(p))
}

func ToObjS(p *nox_object_t) server.Obj {
	if p == nil {
		return nil
	}
	return asObjectS(p)
}

// nox_server_getFirstObject_4DA790
func nox_server_getFirstObject_4DA790() *nox_object_t {
	return asObjectC(GetServer().FirstServerObject())
}

// nox_server_getFirstObjectUninited_4DA870
func nox_server_getFirstObjectUninited_4DA870() *nox_object_t {
	return asObjectC(GetServer().S().Objs.Pending)
}

// nox_server_getNextObject_4DA7A0
func nox_server_getNextObject_4DA7A0(cobj *nox_object_t) *nox_object_t {
	return asObjectC(asObjectS(cobj).Next())
}

// nox_server_getNextObjectUninited_4DA880
func nox_server_getNextObjectUninited_4DA880(cobj *nox_object_t) *nox_object_t {
	return asObjectC(asObjectS(cobj).Next())
}

// nox_xxx_getNextUpdatable2Object_4DA850
func nox_xxx_getNextUpdatable2Object_4DA850(cobj *nox_object_t) *nox_object_t {
	return asObjectC(asObjectS(cobj).Next())
}

// nox_xxx_unitAddToUpdatable_4DA8D0
func nox_xxx_unitAddToUpdatable_4DA8D0(cobj *nox_object_t) {
	GetServer().S().Objs.AddToUpdatable(asObjectS(cobj))
}

// nox_xxx_unitRemoveFromUpdatable_4DA920
func nox_xxx_unitRemoveFromUpdatable_4DA920(cobj *nox_object_t) {
	GetServer().S().Objs.RemoveFromUpdatable(asObjectS(cobj))
}

// nox_xxx_servFinalizeDelObject_4DADE0
func nox_xxx_servFinalizeDelObject_4DADE0(cobj *nox_object_t) {
	GetServer().ObjectDeleteLast(asObjectS(cobj))
}

// nox_xxx_getFirstUpdatable2Object_4DA840
func nox_xxx_getFirstUpdatable2Object_4DA840() *nox_object_t {
	return asObjectC(GetServer().S().Objs.UpdatableList2)
}

// nox_xxx_unitsNewAddToList_4DAC00
func nox_xxx_unitsNewAddToList_4DAC00() {
	GetServer().ObjectsAddPending()
}

// nox_xxx_unitClearPendingMB_4DB030
func nox_xxx_unitClearPendingMB_4DB030() {
	GetServer().ObjectsClearPending()
}

// nox_xxx_finalizeDeletingUnits_4E5EC0
func nox_xxx_finalizeDeletingUnits_4E5EC0() {
	GetServer().FinalizeDeletingObjects()
}

// nox_xxx_getFirstUpdatableObject_4DA8A0
func nox_xxx_getFirstUpdatableObject_4DA8A0() *nox_object_t {
	return asObjectC(GetServer().S().Objs.UpdatableList)
}

// nox_xxx_getNextUpdatableObject_4DA8B0
func nox_xxx_getNextUpdatableObject_4DA8B0(obj *nox_object_t) *nox_object_t {
	if obj == nil {
		return nil
	}
	return obj.UpdatableNext
}

// sub_548600
func sub_548600(a1 *nox_object_t, a2, a3 float32) {
	asObjectS(a1).Sub548600(types.Pointf{X: float32(a2), Y: float32(a3)})
}

// nox_xxx_delayedDeleteObject_4E5CC0
func nox_xxx_delayedDeleteObject_4E5CC0(obj *nox_object_t) {
	GetServer().DelayedDelete(asObjectS(obj))
}

func AsPointf(p unsafe.Pointer) types.Pointf {
	cp := (*float2)(p)
	return types.Pointf{
		X: float32(cp.field_0),
		Y: float32(cp.field_4),
	}
}
func AsPoint(p unsafe.Pointer) image.Point {
	cp := (*nox_point)(p)
	return image.Point{
		X: int(cp.x),
		Y: int(cp.y),
	}
}

// nox_xxx_createAt_4DAA50
func nox_xxx_createAt_4DAA50(cobj *nox_object_t, cowner *nox_object_t, x float32, y float32) {
	var owner server.Obj
	if cowner != nil {
		owner = asObjectS(cowner)
	}
	GetServer().CreateObjectAt(ToObjS(cobj), owner, types.Pointf{X: float32(x), Y: float32(y)})
}

// nox_xxx_objectFreeMem_4E38A0
func nox_xxx_objectFreeMem_4E38A0(a1p *nox_object_t) int {
	return GetServer().S().Objs.FreeObject(asObjectS(a1p))
}

// nox_xxx_findParentChainPlayer_4EC580
func nox_xxx_findParentChainPlayer_4EC580(obj *nox_object_t) *nox_object_t {
	return asObjectC(asObjectS(obj).FindOwnerChainPlayer())
}

// nox_xxx_unitHasThatParent_4EC4F0
func nox_xxx_unitHasThatParent_4EC4F0(obj, owner *nox_object_t) int {
	return bool2int(asObjectS(obj).HasOwner(asObjectS(owner)))
}

// nox_xxx_unitIsEnemyTo_5330C0
func nox_xxx_unitIsEnemyTo_5330C0(a, b *nox_object_t) int {
	return bool2int(GetServer().IsEnemyTo(asObjectS(a), asObjectS(b)))
}

// nox_get_and_zero_server_objects_4DA3C0
func nox_get_and_zero_server_objects_4DA3C0() *nox_object_t {
	return asObjectC(GetServer().S().Objs.GetAndZeroObjects())
}

// nox_set_server_objects_4DA3E0
func nox_set_server_objects_4DA3E0(list *nox_object_t) {
	GetServer().S().Objs.SetObjects(asObjectS(list))
}

// sub_47A1F0
func sub_47A1F0() {
	Sub_47A1F0()
}

// nox_xxx_unitMonsterInit_4F0040
func nox_xxx_unitMonsterInit_4F0040(obj *nox_object_t) {
	Nox_xxx_unitMonsterInit_4F0040(asObjectS(obj))
}

// nox_xxx_setNPCColor_4E4A90
func nox_xxx_setNPCColor_4E4A90(obj *nox_object_t, a2 byte, p unsafe.Pointer) {
	Nox_xxx_setNPCColor_4E4A90(asObjectS(obj), a2, (*server.Color3)(p))
}

// nox_xxx_checkSummonedCreaturesLimit_500D70
func nox_xxx_checkSummonedCreaturesLimit_500D70(obj *nox_object_t, ind int) bool {
	return bool(Nox_xxx_checkSummonedCreaturesLimit_500D70(asObjectS(obj), ind))
}

// nox_xxx_unitDoSummonAt_5016C0
func nox_xxx_unitDoSummonAt_5016C0(typID int, cpos *float32, owner *nox_object_t, dir byte) *nox_object_t {
	pos := unsafe.Slice(cpos, 2)
	return asObjectC(Nox_xxx_unitDoSummonAt_5016C0(typID, types.Ptf(pos[0], pos[1]), asObjectS(owner), server.Dir16(dir)))
}

// sub_57AEE0
func sub_57AEE0(sp int, u *nox_object_t) int {
	return bool2int(Sub_57AEE0(spell.ID(sp), asObjectS(u)))
}

// sub_4E71F0
func sub_4E71F0(a1 *nox_object_t) {
	Sub_4E71F0(asObjectS(a1))
}

// nox_bomberDead_54A150
func nox_bomberDead_54A150(a1 *nox_object_t) int {
	return Nox_bomberDead_54A150(asObjectS(a1))
}

// nox_xxx_dieGlyph_54DF30
func nox_xxx_dieGlyph_54DF30(a1 *nox_object_t) {
	Nox_xxx_dieGlyph_54DF30(asObjectS(a1))
}

// nox_xxx_collideGlyph_4E9A00
func nox_xxx_collideGlyph_4E9A00(a1, a2 *nox_object_t) {
	Nox_xxx_collideGlyph_4E9A00(asObjectS(a1), asObjectS(a2))
}

// sub_57B4D0
func sub_57B4D0(obj *nox_object_t) {
	GetServer().S().Doors.SetKeyHolder(asObjectS(obj))
}

// nox_xxx_doorGetSomeKey_4E8910
func nox_xxx_doorGetSomeKey_4E8910(u, door *nox_object_t) *nox_object_t {
	return asObjectC(GetServer().S().DoorCheckKey(asObjectS(u), asObjectS(door)))
}

func Nox_server_getObjectFromNetCode_4ECCB0(a1 int) *server.Object {
	return asObjectS(nox_server_getObjectFromNetCode_4ECCB0(int32(a1)))
}
func Nox_xxx_creatureIsMonitored_500CC0(a1 *server.Object, a2 *server.Object) int {
	return int(nox_xxx_creatureIsMonitored_500CC0(asObjectC(a1), asObjectC(a2)))
}
func Nox_xxx_monsterRemoveMonitors_4E7B60(a1 *server.Object, a2 *server.Object) {
	nox_xxx_monsterRemoveMonitors_4E7B60(asObjectC(a1), asObjectC(a2))
}
func Sub_4ED0C0(a1 *server.Object, a2 *server.Object) {
	sub_4ED0C0(asObjectC(a1), asObjectC(a2))
}
func Nox_xxx_playerCancelSpells_4FEAE0(a1 *server.Object) {
	nox_xxx_playerCancelSpells_4FEAE0(asObjectC(a1))
}
func Sub_50E210(a1 *server.Object) {
	sub_50E210(asObjectC(a1))
}
func Sub_506740(a1 *server.Object) {
	sub_506740(asObjectC(a1))
}
func Nox_xxx_unitTransferSlaves_4EC4B0(a1 *server.Object) {
	nox_xxx_unitTransferSlaves_4EC4B0(asObjectC(a1))
}
func Nox_xxx_decay_5116F0(a1 *server.Object) {
	nox_xxx_decay_5116F0(asObjectC(a1))
}
func Nox_xxx_netReportDestroyObject_5289D0(a1 *server.Object) {
	nox_xxx_netReportDestroyObject_5289D0(asObjectC(a1))
}
func Nox_xxx_unit_511810(a1 *server.Object) {
	nox_xxx_unit_511810(asObjectC(a1))
}
func Nox_xxx_unitRemoveChild_4EC470(a1 *server.Object) {
	nox_xxx_unitRemoveChild_4EC470(asObjectC(a1))
}
func Sub_517870(a1 *server.Object) {
	sub_517870(asObjectC(a1))
}
func Sub_4ECFA0(a1 *server.Object) {
	sub_4ECFA0(asObjectC(a1))
}
func Sub_511DE0(a1 *server.Object) {
	sub_511DE0(asObjectC(a1))
}
func Sub_528990(a1 *server.Object) {
	sub_528990(asObjectC(a1))
}
func Nox_xxx_unitNewAddShadow_4DA9A0(a1 *server.Object) {
	nox_xxx_unitNewAddShadow_4DA9A0(asObjectC(a1))
}
func Nox_xxx_respawnAdd_4EC5E0(a1 *server.Object) {
	nox_xxx_respawnAdd_4EC5E0(asObjectC(a1))
}
func Sub_5117F0(a1 *server.Object) {
	sub_5117F0(asObjectC(a1))
}
func Sub_527E00(a1 *server.Object) {
	sub_527E00(asObjectC(a1))
}
func Nox_xxx_action_4DA9F0(a1 *server.Object) {
	nox_xxx_action_4DA9F0(asObjectC(a1))
}
func Nox_xxx_unitPostCreateNotify_4E7F10(a1 *server.Object) {
	nox_xxx_unitPostCreateNotify_4E7F10(asObjectC(a1))
}
func Nox_xxx_buffApplyTo_4FF380(a1 *server.Object, a2 server.EnchantID, a3 int, a4 int) {
	nox_xxx_buffApplyTo_4FF380(asObjectC(a1), int32(a2), int16(a3), char(a4))
}
func Nox_xxx_spellBuffOff_4FF5B0(a1 *server.Object, a2 server.EnchantID) {
	nox_xxx_spellBuffOff_4FF5B0(asObjectC(a1), int32(a2))
}
func Nox_xxx_unitClearOwner_4EC300(a1 *server.Object) {
	nox_xxx_unitClearOwner_4EC300(asObjectC(a1))
}
func Nox_xxx_unitSetOwner_4EC290(a1 *server.Object, a2 *server.Object) {
	nox_xxx_unitSetOwner_4EC290(asObjectC(a1), asObjectC(a2))
}
func Nox_xxx_unitRaise_4E46F0(a1 *server.Object, a2 float32) {
	nox_xxx_unitRaise_4E46F0(asObjectC(a1), float32(a2))
}
func Nox_xxx_objectSetOff_4E7600(a1 *server.Object) {
	nox_xxx_objectSetOff_4E7600(asObjectC(a1))
}
func Nox_xxx_objectSetOn_4E75B0(a1 *server.Object) {
	nox_xxx_objectSetOn_4E75B0(asObjectC(a1))
}
func Nox_xxx_drop_4ED790(a1 *server.Object, a2 *server.Object, pos types.Pointf) int {
	cpos, free := alloc.New(types.Pointf{})
	defer free()
	*cpos = pos
	return int(nox_xxx_drop_4ED790(asObjectC(a1), asObjectC(a2), (*float2)(unsafe.Pointer(cpos))))
}
func Nox_xxx_dropAllItems_4EDA40(a1 *server.Object) {
	nox_xxx_dropAllItems_4EDA40((*uint32)(a1.CObj()))
}

func Get_nox_objectDropAudEvent_4EE2F0() unsafe.Pointer {
	return nox_objectDropAudEvent_4EE2F0
}
func Get_nox_xxx_XFerDefault_4F49A0() unsafe.Pointer {
	return nox_xxx_XFerDefault_4F49A0
}
func Get_nox_xxx_updateHarpoon_54F380() unsafe.Pointer {
	return nox_xxx_updateHarpoon_54F380
}
func Get_nox_xxx_updatePixie_53CD20() unsafe.Pointer {
	return nox_xxx_updatePixie_53CD20
}
func Nox_object_getGold_4FA6D0(obj *server.Object) int {
	return int(nox_object_getGold_4FA6D0(asObjectC(obj)))
}
func Nox_object_setGold_4FA620(obj *server.Object, v int) {
	nox_object_setGold_4FA620(asObjectC(obj), int32(v))
}
func Nox_xxx_unitSetXStatus_4E4800(obj *server.Object, a2 int) {
	nox_xxx_unitSetXStatus_4E4800(asObjectC(obj), int32(a2))
}
func Nox_xxx_unitUnsetXStatus_4E4780(obj *server.Object, a2 int) {
	nox_xxx_unitUnsetXStatus_4E4780(asObjectC(obj), int32(a2))
}
func Nox_xxx_script_forcedialog_548CD0(obj, obj2 *server.Object) {
	nox_xxx_script_forcedialog_548CD0(asObjectC(obj), asObjectC(obj2))
}
func Sub_4E39F0_obj_db(obj *server.Object) string {
	return GoWString(sub_4E39F0_obj_db(asObjectC(obj)))
}
func Nox_xxx_scriptDialog_548D30(obj *server.Object, a2 byte) {
	nox_xxx_scriptDialog_548D30(asObjectC(obj), char(a2))
}
func Nox_xxx_mobSetFightTarg_515D30(obj, targ *server.Object) {
	nox_xxx_mobSetFightTarg_515D30(asObjectC(obj), asObjectC(targ))
}
func Nox_server_scriptFleeFrom_515F70(obj, targ *server.Object, df int) {
	p, free := alloc.New(struct {
		Targ *nox_object_t
		Dt   int32
	}{})
	defer free()
	p.Targ = asObjectC(targ)
	p.Dt = int32(df)
	nox_server_scriptFleeFrom_515F70(asObjectC(obj), unsafe.Pointer(p))
}
func Nox_xxx_monsterGoPatrol_515680(obj *server.Object, p1, p2 types.Pointf, dist float32) {
	p, free := alloc.New(struct {
		P1   types.Pointf
		P2   types.Pointf
		Dist float32
	}{})
	defer free()
	p.P1 = p1
	p.P2 = p2
	p.Dist = dist
	nox_xxx_monsterGoPatrol_515680(asObjectC(obj), unsafe.Pointer(p))
}

func Sub_516090(obj *server.Object, df int) {
	sub_516090(asObjectC(obj), uint32(df))
}

func Nox_xxx_monsterCanCast_534300(obj *server.Object) bool {
	return nox_xxx_monsterCanCast_534300(asObjectC(obj)) != 0
}

func Nox_xxx_playerTryEquip_4F2F70(obj, item *server.Object) bool {
	return nox_xxx_playerTryEquip_4F2F70(asObjectC(obj), asObjectC(item)) != 0
}

func Nox_xxx_inventoryPutImpl_4F3070(obj, item *server.Object, a3 int) {
	nox_xxx_inventoryPutImpl_4F3070(asObjectC(obj), asObjectC(item), int32(a3))
}

func Nox_xxx_orderUnit_533900(owner, obj *server.Object, order uint32) {
	nox_xxx_orderUnit_533900(asObjectC(owner), asObjectC(obj), int32(order))
}

func Sub_4E9A30(a1, a2 *server.Object) bool {
	return sub_4E9A30(asObjectC(a1), asObjectC(a2)) != 0
}

func Nox_xxx_unitsHaveSameTeam_4EC520(a1, a2 *server.Object) bool {
	return nox_xxx_unitsHaveSameTeam_4EC520(asObjectC(a1), asObjectC(a2)) != 0
}

func Nox_xxx_mapPushUnitsAround_52E040(pos types.Pointf, a2 float32, a3 float32, a4 float32, a5 *server.Object, a6 int, a7 int) {
	cpos, free := alloc.New(types.Pointf{})
	defer free()
	*cpos = pos
	nox_xxx_mapPushUnitsAround_52E040(unsafe.Pointer(cpos), float32(a2), float32(a3), float32(a4), asObjectC(a5), int32(a6), int32(a7))
}
