package legacy

/*
#include "defs.h"
#include "GAME1_1.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4.h"
#include "GAME4_1.h"
#include "GAME4_2.h"
#include "GAME4_3.h"
void nox_xxx_updateHarpoon_54F380(nox_object_t* a1);
int nox_objectDropAudEvent_4EE2F0(nox_object_t* a1, nox_object_t* a2, float2* a3);
void nox_xxx_script_forcedialog_548CD0(nox_object_t* a1, nox_object_t* a2);
wchar2_t* sub_4E39F0_obj_db(nox_object_t* a1);
void nox_xxx_scriptDialog_548D30(nox_object_t* a1, char a2);
void nox_server_scriptFleeFrom_515F70(nox_object_t* a1, void* a2);
void nox_xxx_monsterActionMelee_515A30(nox_object_t* a1, float2* a2);
void nox_xxx_monsterMissileAttack_515B80(nox_object_t* a1p, float2* a2);
*/
import "C"
import (
	"image"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/spell"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/common/ntype"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	Nox_xxx_unitMonsterInit_4F0040             func(obj *server.Object)
	Nox_xxx_checkSummonedCreaturesLimit_500D70 func(u *server.Object, ind int) bool
	Nox_xxx_unitDoSummonAt_5016C0              func(typID int, pos types.Pointf, owner *server.Object, dir server.Dir16) *server.Object
	Sub_4E71F0                                 func(obj *server.Object)
	Nox_bomberDead_54A150                      func(obj *server.Object) int
	Nox_xxx_dieGlyph_54DF30                    func(obj *server.Object)
	Nox_xxx_collideGlyph_4E9A00                func(obj, obj2 *server.Object)
	Nox_xxx_playerSetState_4FA020              func(a1 *server.Object, a2 byte) bool
)

var _ = [1]struct{}{}[28-unsafe.Sizeof(server.MissileUpdateData{})]

var _ = [1]struct{}{}[20-unsafe.Sizeof(server.ElevatorUpdateData{})]

var _ = [1]struct{}{}[36-unsafe.Sizeof(server.MoverUpdateData{})]

type nox_object_t = C.nox_object_t

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

//export nox_server_getFirstObject_4DA790
func nox_server_getFirstObject_4DA790() *nox_object_t {
	return asObjectC(GetServer().S().Objs.First())
}

//export nox_server_getFirstObjectUninited_4DA870
func nox_server_getFirstObjectUninited_4DA870() *nox_object_t {
	return asObjectC(GetServer().S().Objs.Pending)
}

//export nox_server_getNextObject_4DA7A0
func nox_server_getNextObject_4DA7A0(cobj *nox_object_t) *nox_object_t {
	return asObjectC(asObjectS(cobj).Next())
}

//export nox_server_getNextObjectUninited_4DA880
func nox_server_getNextObjectUninited_4DA880(cobj *nox_object_t) *nox_object_t {
	return asObjectC(asObjectS(cobj).Next())
}

//export nox_xxx_getNextUpdatable2Object_4DA850
func nox_xxx_getNextUpdatable2Object_4DA850(cobj *nox_object_t) *nox_object_t {
	return asObjectC(asObjectS(cobj).Next())
}

//export nox_xxx_unitAddToUpdatable_4DA8D0
func nox_xxx_unitAddToUpdatable_4DA8D0(cobj *nox_object_t) {
	GetServer().S().Objs.AddToUpdatable(asObjectS(cobj))
}

//export nox_xxx_unitRemoveFromUpdatable_4DA920
func nox_xxx_unitRemoveFromUpdatable_4DA920(cobj *nox_object_t) {
	GetServer().S().Objs.RemoveFromUpdatable(asObjectS(cobj))
}

//export nox_xxx_servFinalizeDelObject_4DADE0
func nox_xxx_servFinalizeDelObject_4DADE0(cobj *nox_object_t) {
	GetServer().ObjectDeleteLast(asObjectS(cobj))
}

//export nox_xxx_getFirstUpdatable2Object_4DA840
func nox_xxx_getFirstUpdatable2Object_4DA840() *nox_object_t {
	return asObjectC(GetServer().S().Objs.UpdatableList2)
}

//export nox_xxx_unitsNewAddToList_4DAC00
func nox_xxx_unitsNewAddToList_4DAC00() {
	GetServer().ObjectsAddPending()
}

//export nox_xxx_unitClearPendingMB_4DB030
func nox_xxx_unitClearPendingMB_4DB030() {
	GetServer().S().Objs.ObjectsClearPending()
}

//export nox_xxx_getFirstUpdatableObject_4DA8A0
func nox_xxx_getFirstUpdatableObject_4DA8A0() *nox_object_t {
	return asObjectC(GetServer().S().Objs.UpdatableList)
}

//export nox_xxx_getNextUpdatableObject_4DA8B0
func nox_xxx_getNextUpdatableObject_4DA8B0(obj *nox_object_t) *nox_object_t {
	if obj == nil {
		return nil
	}
	return obj.updatable_next
}

//export sub_548600
func sub_548600(a1 *nox_object_t, a2, a3 C.float) {
	asObjectS(a1).Sub548600(types.Pointf{X: float32(a2), Y: float32(a3)})
}

//export nox_xxx_delayedDeleteObject_4E5CC0
func nox_xxx_delayedDeleteObject_4E5CC0(obj *nox_object_t) {
	GetServer().DelayedDelete(asObjectS(obj))
}

//export nox_xxx_unitSetOwner_4EC290
func nox_xxx_unitSetOwner_4EC290(obj1, obj2 *nox_object_t) {
	GetServer().S().ObjSetOwner(asObjectS(obj1), asObjectS(obj2))
}

//export nox_xxx_unitClearOwner_4EC300
func nox_xxx_unitClearOwner_4EC300(obj *nox_object_t) {
	GetServer().S().ObjClearOwner(asObjectS(obj))
}

//export nox_xxx_creatureIsMonitored_500CC0
func nox_xxx_creatureIsMonitored_500CC0(obj1, obj2 *nox_object_t) int {
	return bool2int(server.Nox_xxx_creatureIsMonitored_500CC0(asObjectS(obj1), asObjectS(obj2)))
}

//export nox_xxx_netMarkMinimapObject_417190
func nox_xxx_netMarkMinimapObject_417190(a1 int, obj *nox_object_t, a3 uint32) {
	GetServer().S().Players.Nox_xxx_netMarkMinimapObject_417190(ntype.PlayerInd(a1), asObjectS(obj), a3)
}

//export nox_xxx_netUnmarkMinimapObj_417300
func nox_xxx_netUnmarkMinimapObj_417300(a1 int, obj *nox_object_t, a3 uint32) {
	GetServer().S().Players.Nox_xxx_netUnmarkMinimapObj_417300(ntype.PlayerInd(a1), asObjectS(obj), a3)
}

//export nox_xxx_monsterMarkUpdate_4E8020
func nox_xxx_monsterMarkUpdate_4E8020(obj *nox_object_t) {
	asObjectS(obj).Nox_xxx_monsterMarkUpdate_4E8020()
}

//export nox_xxx_unitIsHostileMimic_4E7F90
func nox_xxx_unitIsHostileMimic_4E7F90(obj1, obj2 *nox_object_t) int {
	return bool2int(GetServer().S().IsHostileMimicXxx(asObjectS(obj1), asObjectS(obj2)))
}

func AsPointf(p unsafe.Pointer) types.Pointf {
	cp := (*C.float2)(p)
	return types.Pointf{
		X: float32(cp.field_0),
		Y: float32(cp.field_4),
	}
}
func AsPoint(p unsafe.Pointer) image.Point {
	cp := (*C.nox_point)(p)
	return image.Point{
		X: int(cp.x),
		Y: int(cp.y),
	}
}

//export nox_xxx_createAt_4DAA50
func nox_xxx_createAt_4DAA50(cobj *nox_object_t, cowner *nox_object_t, x C.float, y C.float) {
	var owner server.Obj
	if cowner != nil {
		owner = asObjectS(cowner)
	}
	GetServer().CreateObjectAt(ToObjS(cobj), owner, types.Pointf{X: float32(x), Y: float32(y)})
}

//export nox_xxx_objectFreeMem_4E38A0
func nox_xxx_objectFreeMem_4E38A0(a1p *nox_object_t) int {
	return GetServer().S().Objs.FreeObject(asObjectS(a1p))
}

//export nox_xxx_findParentChainPlayer_4EC580
func nox_xxx_findParentChainPlayer_4EC580(obj *nox_object_t) *nox_object_t {
	return asObjectC(asObjectS(obj).FindOwnerChainPlayer())
}

//export nox_xxx_unitHasThatParent_4EC4F0
func nox_xxx_unitHasThatParent_4EC4F0(obj, owner *nox_object_t) int {
	return bool2int(asObjectS(obj).HasOwner(asObjectS(owner)))
}

//export nox_xxx_unitIsEnemyTo_5330C0
func nox_xxx_unitIsEnemyTo_5330C0(a, b *nox_object_t) int {
	return bool2int(GetServer().S().IsEnemyTo(asObjectS(a), asObjectS(b)))
}

//export nox_get_and_zero_server_objects_4DA3C0
func nox_get_and_zero_server_objects_4DA3C0() *nox_object_t {
	return asObjectC(GetServer().S().Objs.GetAndZeroObjects())
}

//export nox_set_server_objects_4DA3E0
func nox_set_server_objects_4DA3E0(list *nox_object_t) {
	GetServer().S().Objs.SetObjects(asObjectS(list))
}

//export nox_xxx_unitMonsterInit_4F0040
func nox_xxx_unitMonsterInit_4F0040(obj *nox_object_t) {
	Nox_xxx_unitMonsterInit_4F0040(asObjectS(obj))
}

//export nox_xxx_setNPCColor_4E4A90
func nox_xxx_setNPCColor_4E4A90(obj *nox_object_t, a2 byte, p unsafe.Pointer) {
	asObjectS(obj).Nox_xxx_setNPCColor_4E4A90(a2, (*server.Color3)(p))
}

//export nox_xxx_checkSummonedCreaturesLimit_500D70
func nox_xxx_checkSummonedCreaturesLimit_500D70(obj *nox_object_t, ind int) C.bool {
	return C.bool(Nox_xxx_checkSummonedCreaturesLimit_500D70(asObjectS(obj), ind))
}

//export nox_xxx_unitDoSummonAt_5016C0
func nox_xxx_unitDoSummonAt_5016C0(typID int, cpos *float32, owner *nox_object_t, dir C.uchar) *nox_object_t {
	pos := unsafe.Slice(cpos, 2)
	return asObjectC(Nox_xxx_unitDoSummonAt_5016C0(typID, types.Ptf(pos[0], pos[1]), asObjectS(owner), server.Dir16(dir)))
}

//export sub_57AEE0
func sub_57AEE0(sp int, u *nox_object_t) int {
	return bool2int(server.Sub_57AEE0(spell.ID(sp), asObjectS(u)))
}

//export sub_4E71F0
func sub_4E71F0(a1 *nox_object_t) {
	Sub_4E71F0(asObjectS(a1))
}

//export nox_bomberDead_54A150
func nox_bomberDead_54A150(a1 *nox_object_t) int {
	return Nox_bomberDead_54A150(asObjectS(a1))
}

//export nox_xxx_dieGlyph_54DF30
func nox_xxx_dieGlyph_54DF30(a1 *nox_object_t) {
	Nox_xxx_dieGlyph_54DF30(asObjectS(a1))
}

//export nox_xxx_collideGlyph_4E9A00
func nox_xxx_collideGlyph_4E9A00(a1, a2 *nox_object_t) {
	Nox_xxx_collideGlyph_4E9A00(asObjectS(a1), asObjectS(a2))
}

//export nox_xxx_doorGetSomeKey_4E8910
func nox_xxx_doorGetSomeKey_4E8910(u, door *nox_object_t) *nox_object_t {
	return asObjectC(GetServer().S().DoorCheckKey(asObjectS(u), asObjectS(door)))
}

//export nox_xxx_unitSetXStatus_4E4800
func nox_xxx_unitSetXStatus_4E4800(a1 *nox_object_t, a2 uint32) {
	asObjectS(a1).SetXStatus(a2)
}

//export nox_xxx_unitUnsetXStatus_4E4780
func nox_xxx_unitUnsetXStatus_4E4780(a1 *nox_object_t, a2 uint32) {
	asObjectS(a1).UnsetXStatus(a2)
}

//export nox_xxx_playerSetState_4FA020
func nox_xxx_playerSetState_4FA020(a1 *nox_object_t, a2 int) int {
	return bool2int(Nox_xxx_playerSetState_4FA020(asObjectS(a1), byte(a2)))
}

func Nox_server_getObjectFromNetCode_4ECCB0(a1 int) *server.Object {
	return asObjectS(C.nox_server_getObjectFromNetCode_4ECCB0(C.int(a1)))
}
func Nox_xxx_monsterRemoveMonitors_4E7B60(a1 *server.Object, a2 *server.Object) {
	C.nox_xxx_monsterRemoveMonitors_4E7B60(asObjectC(a1), asObjectC(a2))
}
func Sub_4ED0C0(a1 *server.Object, a2 *server.Object) {
	C.sub_4ED0C0(asObjectC(a1), asObjectC(a2))
}
func Nox_xxx_playerCancelSpells_4FEAE0(a1 *server.Object) {
	C.nox_xxx_playerCancelSpells_4FEAE0(asObjectC(a1))
}
func Sub_50E210(a1 *server.Object) {
	C.sub_50E210(asObjectC(a1))
}
func Sub_506740(a1 *server.Object) {
	C.sub_506740(asObjectC(a1))
}
func Nox_xxx_unitTransferSlaves_4EC4B0(a1 *server.Object) {
	C.nox_xxx_unitTransferSlaves_4EC4B0(asObjectC(a1))
}
func Nox_xxx_decay_5116F0(a1 *server.Object) {
	C.nox_xxx_decay_5116F0(asObjectC(a1))
}
func Nox_xxx_netReportDestroyObject_5289D0(a1 *server.Object) {
	C.nox_xxx_netReportDestroyObject_5289D0(asObjectC(a1))
}
func Nox_xxx_unit_511810(a1 *server.Object) {
	C.nox_xxx_unit_511810(asObjectC(a1))
}
func Nox_xxx_unitRemoveChild_4EC470(a1 *server.Object) {
	C.nox_xxx_unitRemoveChild_4EC470(asObjectC(a1))
}
func Sub_517870(a1 *server.Object) {
	C.sub_517870(asObjectC(a1))
}
func Sub_4ECFA0(a1 *server.Object) {
	C.sub_4ECFA0(asObjectC(a1))
}
func Sub_511DE0(a1 *server.Object) {
	C.sub_511DE0(asObjectC(a1))
}
func Sub_528990(a1 *server.Object) {
	C.sub_528990(asObjectC(a1))
}
func Nox_xxx_unitNewAddShadow_4DA9A0(a1 *server.Object) {
	C.nox_xxx_unitNewAddShadow_4DA9A0(asObjectC(a1))
}
func Nox_xxx_respawnAdd_4EC5E0(a1 *server.Object) {
	C.nox_xxx_respawnAdd_4EC5E0(asObjectC(a1))
}
func Sub_5117F0(a1 *server.Object) {
	C.sub_5117F0(asObjectC(a1))
}
func Sub_527E00(a1 *server.Object) {
	C.sub_527E00(asObjectC(a1))
}
func Nox_xxx_action_4DA9F0(a1 *server.Object) {
	C.nox_xxx_action_4DA9F0(asObjectC(a1))
}
func Nox_xxx_unitPostCreateNotify_4E7F10(a1 *server.Object) {
	C.nox_xxx_unitPostCreateNotify_4E7F10(asObjectC(a1))
}
func Nox_xxx_buffApplyTo_4FF380(a1 *server.Object, a2 server.EnchantID, dur int, power int) {
	C.nox_xxx_buffApplyTo_4FF380(asObjectC(a1), C.int(a2), C.short(dur), C.char(power))
}
func Nox_xxx_spellBuffOff_4FF5B0(a1 *server.Object, a2 server.EnchantID) {
	C.nox_xxx_spellBuffOff_4FF5B0(asObjectC(a1), C.int(a2))
}
func Nox_xxx_unitRaise_4E46F0(a1 *server.Object, a2 float32) {
	C.nox_xxx_unitRaise_4E46F0(asObjectC(a1), C.float(a2))
}
func Nox_xxx_objectSetOff_4E7600(a1 *server.Object) {
	C.nox_xxx_objectSetOff_4E7600(asObjectC(a1))
}
func Nox_xxx_objectSetOn_4E75B0(a1 *server.Object) {
	C.nox_xxx_objectSetOn_4E75B0(asObjectC(a1))
}
func Nox_xxx_drop_4ED790(a1 *server.Object, a2 *server.Object, pos types.Pointf) int {
	cpos, free := alloc.New(types.Pointf{})
	defer free()
	*cpos = pos
	return int(C.nox_xxx_drop_4ED790(asObjectC(a1), asObjectC(a2), (*C.float2)(unsafe.Pointer(cpos))))
}
func Nox_xxx_dropAllItems_4EDA40(a1 *server.Object) {
	C.nox_xxx_dropAllItems_4EDA40((*C.uint)(a1.CObj()))
}

func Get_nox_objectDropAudEvent_4EE2F0() unsafe.Pointer {
	return C.nox_objectDropAudEvent_4EE2F0
}
func Get_nox_xxx_XFerDefault_4F49A0() unsafe.Pointer {
	return C.nox_xxx_XFerDefault_4F49A0
}
func Get_nox_xxx_updateHarpoon_54F380() unsafe.Pointer {
	return C.nox_xxx_updateHarpoon_54F380
}
func Get_nox_xxx_updatePixie_53CD20() unsafe.Pointer {
	return C.nox_xxx_updatePixie_53CD20
}
func Nox_object_getGold_4FA6D0(obj *server.Object) int {
	return int(C.nox_object_getGold_4FA6D0(asObjectC(obj)))
}
func Nox_object_setGold_4FA620(obj *server.Object, v int) {
	C.nox_object_setGold_4FA620(asObjectC(obj), C.int(v))
}
func Nox_xxx_script_forcedialog_548CD0(obj, obj2 *server.Object) {
	C.nox_xxx_script_forcedialog_548CD0(asObjectC(obj), asObjectC(obj2))
}
func Sub_4E39F0_obj_db(obj *server.Object) string {
	return GoWString(C.sub_4E39F0_obj_db(asObjectC(obj)))
}
func Nox_xxx_scriptDialog_548D30(obj *server.Object, a2 byte) {
	C.nox_xxx_scriptDialog_548D30(asObjectC(obj), C.char(a2))
}
func Nox_xxx_mobSetFightTarg_515D30(obj, targ *server.Object) {
	C.nox_xxx_mobSetFightTarg_515D30(asObjectC(obj), asObjectC(targ))
}
func Nox_server_scriptFleeFrom_515F70(obj, targ *server.Object, df int) {
	p, free := alloc.New(struct {
		Targ *nox_object_t
		Dt   int32
	}{})
	defer free()
	p.Targ = asObjectC(targ)
	p.Dt = int32(df)
	C.nox_server_scriptFleeFrom_515F70(asObjectC(obj), unsafe.Pointer(p))
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
	C.nox_xxx_monsterGoPatrol_515680(asObjectC(obj), unsafe.Pointer(p))
}
func Nox_xxx_monsterActionMelee_515A30(obj *server.Object, pos types.Pointf) {
	cp, free := alloc.New(types.Pointf{})
	defer free()
	*cp = pos
	C.nox_xxx_monsterActionMelee_515A30(asObjectC(obj), (*C.float2)(unsafe.Pointer(cp)))
}
func Nox_xxx_monsterMissileAttack_515B80(obj *server.Object, pos types.Pointf) {
	cp, free := alloc.New(types.Pointf{})
	defer free()
	*cp = pos
	C.nox_xxx_monsterMissileAttack_515B80(asObjectC(obj), (*C.float2)(unsafe.Pointer(cp)))
}

func Sub_516090(obj *server.Object, df int) {
	C.sub_516090(asObjectC(obj), C.uint(df))
}

func Nox_xxx_monsterCanCast_534300(obj *server.Object) bool {
	return C.nox_xxx_monsterCanCast_534300(asObjectC(obj)) != 0
}

func Nox_xxx_playerTryEquip_4F2F70(obj, item *server.Object) bool {
	return C.nox_xxx_playerTryEquip_4F2F70(asObjectC(obj), asObjectC(item)) != 0
}

func Nox_xxx_playerTryDequip_4F2FB0(obj, item *server.Object) bool {
	return C.nox_xxx_playerTryDequip_4F2FB0(asObjectC(obj), asObjectC(item)) != 0
}

func Nox_xxx_inventoryPutImpl_4F3070(obj, item *server.Object, a3 int) {
	C.nox_xxx_inventoryPutImpl_4F3070(asObjectC(obj), asObjectC(item), C.int(a3))
}

func Nox_xxx_orderUnit_533900(owner, obj *server.Object, order uint32) {
	C.nox_xxx_orderUnit_533900(asObjectC(owner), asObjectC(obj), C.int(order))
}

func Sub_4E9A30(a1, a2 *server.Object) bool {
	return C.sub_4E9A30(asObjectC(a1), asObjectC(a2)) != 0
}

func Nox_xxx_unitsHaveSameTeam_4EC520(a1, a2 *server.Object) bool {
	return C.nox_xxx_unitsHaveSameTeam_4EC520(asObjectC(a1), asObjectC(a2)) != 0
}

func Nox_xxx_mapPushUnitsAround_52E040(pos types.Pointf, a2 float32, a3 float32, a4 float32, a5 *server.Object, a6 int, a7 int) {
	cpos, free := alloc.New(types.Pointf{})
	defer free()
	*cpos = pos
	C.nox_xxx_mapPushUnitsAround_52E040(unsafe.Pointer(cpos), C.float(a2), C.float(a3), C.float(a4), asObjectC(a5), C.int(a6), C.int(a7))
}
