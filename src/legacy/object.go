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
*/
import "C"
import (
	"image"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
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
	return asObjectC(GetServer().FirstServerObject())
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
	GetServer().ObjectsNewAdd()
}

//export nox_xxx_unitClearPendingMB_4DB030
func nox_xxx_unitClearPendingMB_4DB030() {
	GetServer().ObjectsClearPending()
}

//export nox_xxx_finalizeDeletingUnits_4E5EC0
func nox_xxx_finalizeDeletingUnits_4E5EC0() {
	GetServer().FinalizeDeletingObjects()
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
	return bool2int(GetServer().IsEnemyTo(asObjectS(a), asObjectS(b)))
}

//export nox_xxx_unitIsAFish_534B10
func nox_xxx_unitIsAFish_534B10(obj *nox_object_t) int {
	return bool2int(GetServer().IsFish(asObjectS(obj)))
}

//export nox_xxx_unitIsARat_534B60
func nox_xxx_unitIsARat_534B60(obj *nox_object_t) int {
	return bool2int(GetServer().IsRat(asObjectS(obj)))
}

//export nox_xxx_unitIsAFrog_534B90
func nox_xxx_unitIsAFrog_534B90(obj *nox_object_t) int {
	return bool2int(GetServer().IsFrog(asObjectS(obj)))
}

//export nox_get_and_zero_server_objects_4DA3C0
func nox_get_and_zero_server_objects_4DA3C0() *nox_object_t {
	return asObjectC(GetServer().S().Objs.GetAndZeroObjects())
}

//export nox_set_server_objects_4DA3E0
func nox_set_server_objects_4DA3E0(list *nox_object_t) {
	GetServer().S().Objs.SetObjects(asObjectS(list))
}
func Nox_server_getObjectFromNetCode_4ECCB0(a1 int) *server.Object {
	return asObjectS(C.nox_server_getObjectFromNetCode_4ECCB0(C.int(a1)))
}
func Nox_xxx_creatureIsMonitored_500CC0(a1 *server.Object, a2 *server.Object) int {
	return int(C.nox_xxx_creatureIsMonitored_500CC0(asObjectC(a1), asObjectC(a2)))
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
func Nox_xxx_buffApplyTo_4FF380(a1 *server.Object, a2 server.EnchantID, a3 int, a4 int) {
	C.nox_xxx_buffApplyTo_4FF380(asObjectC(a1), C.int(a2), C.short(a3), C.char(a4))
}
func Nox_xxx_spellBuffOff_4FF5B0(a1 *server.Object, a2 server.EnchantID) {
	C.nox_xxx_spellBuffOff_4FF5B0(asObjectC(a1), C.int(a2))
}
func Nox_xxx_unitClearOwner_4EC300(a1 *server.Object) {
	C.nox_xxx_unitClearOwner_4EC300(asObjectC(a1))
}
func Nox_xxx_unitSetOwner_4EC290(a1 *server.Object, a2 *server.Object) {
	C.nox_xxx_unitSetOwner_4EC290(asObjectC(a1), asObjectC(a2))
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
