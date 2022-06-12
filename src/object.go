package opennox

/*
#include "defs.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4.h"
#include "GAME4_1.h"
#include "GAME4_3.h"
extern nox_object_t* nox_server_objects_1556844;
extern nox_object_t* nox_server_objects_uninited_1556860;
extern nox_object_t* nox_server_objects_updatable2_1556848;
static void nox_call_obj_update_go(void (*fnc)(nox_object_t*), nox_object_t* obj) { fnc(obj); }
static int nox_call_object_xfer(int (*fnc)(nox_object_t*, void*), nox_object_t* a1, void* a2) { return fnc(a1, a2); }
static void nox_call_object_damage(int (*fnc)(nox_object_t*, nox_object_t*, int, int, int), nox_object_t* a1, nox_object_t* a2, int a3, int a4, int a5) { fnc(a1, a2, a3, a4, a5); }
*/
import "C"
import (
	"fmt"
	"image"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/script"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
)

type serverObjects struct {
	types struct {
		frog      int
		rat       int
		fishSmall int
		fishBig   int
		plant     int
		polyp     int
		wisp      int
	}
}

//export nox_xxx_findParentChainPlayer_4EC580
func nox_xxx_findParentChainPlayer_4EC580(obj *nox_object_t) *nox_object_t {
	return asObjectC(obj).findOwnerChainPlayer().CObj()
}

//export nox_xxx_unitIsEnemyTo_5330C0
func nox_xxx_unitIsEnemyTo_5330C0(a, b *nox_object_t) C.int {
	if asObjectC(a).isEnemyTo(asObjectC(b)) {
		return 1
	}
	return 0
}

//export nox_xxx_unitIsAFish_534B10
func nox_xxx_unitIsAFish_534B10(obj *nox_object_t) C.int {
	if asObjectC(obj).isFish() {
		return 1
	}
	return 0
}

//export nox_xxx_unitIsARat_534B60
func nox_xxx_unitIsARat_534B60(obj *nox_object_t) C.int {
	if asObjectC(obj).isRat() {
		return 1
	}
	return 0
}

//export nox_xxx_unitIsAFrog_534B90
func nox_xxx_unitIsAFrog_534B90(obj *nox_object_t) C.int {
	if asObjectC(obj).isFrog() {
		return 1
	}
	return 0
}

type shapeKind uint32

const (
	shapeKindNone   = shapeKind(0)
	shapeKindCenter = shapeKind(1)
	shapeKindCircle = shapeKind(2)
	shapeKindBox    = shapeKind(3)
)

var _ = ([1]struct{}{})[52-unsafe.Sizeof(noxShape{})]

type noxShape struct {
	kind   shapeKind // 0, 0x0, (43)
	circle struct {
		R  float32 // 1, 0x4, (44)
		R2 float32 // 2, 0x8, (45)
	}
	box noxShapeBox
}

type noxShapeBox struct {
	W            float32 // 3, 0xC, (46)
	H            float32 // 4, 0x10, (47)
	LeftTop      float32 // 5, 0x14, (48)
	LeftBottom   float32 // 6, 0x18, (49)
	LeftBottom2  float32 // 7, 0x1C, (50)
	LeftTop2     float32 // 8, 0x20, (51)
	RightTop     float32 // 9, 0x24, (52)
	RightBottom  float32 // 10, 0x28, (53)
	RightBottom2 float32 // 11, 0x2C, (54)
	RightTop2    float32 // 12, 0x30, (55)
}

func asPointf(p unsafe.Pointer) types.Pointf {
	cp := (*C.float2)(p)
	return types.Pointf{
		X: float32(cp.field_0),
		Y: float32(cp.field_4),
	}
}
func asPoint(p unsafe.Pointer) image.Point {
	cp := (*C.nox_point)(p)
	return image.Point{
		X: int(cp.x),
		Y: int(cp.y),
	}
}
func asObject(p unsafe.Pointer) *Object {
	return (*Object)(p)
}
func asObjectC(p *C.nox_object_t) *Object {
	return asObject(unsafe.Pointer(p))
}

func (s *Server) firstServerObject() *Object { // nox_server_getFirstObject_4DA790
	return asObjectC(C.nox_server_objects_1556844)
}

func firstServerObjectUpdatable2() *Object { // nox_xxx_getFirstUpdatable2Object_4DA840
	return asObjectC(C.nox_server_objects_updatable2_1556848)
}

func (s *Server) firstServerObjectUninited() *Object { // nox_server_getFirstObjectUninited_4DA870
	return asObjectC(C.nox_server_objects_uninited_1556860)
}

func (s *Server) getObjects() []*Object {
	var out []*Object
	for p := s.firstServerObject(); p != nil; p = p.Next() {
		out = append(out, p)
	}
	return out
}

func getObjectsUpdatable2() []*Object {
	var out []*Object
	for p := firstServerObjectUpdatable2(); p != nil; p = p.Next() {
		out = append(out, p)
	}
	return out
}

func (s *Server) getObjectsUninited() []*Object {
	var out []*Object
	for p := s.firstServerObjectUninited(); p != nil; p = p.Next() {
		out = append(out, p)
	}
	return out
}

func (s *Server) getObjectByID(id string) *Object {
	for obj := s.firstServerObject(); obj != nil; obj = obj.Next() {
		if p := obj.findByID(id); p != nil {
			return p
		}
	}
	for obj := s.firstServerObjectUninited(); obj != nil; obj = obj.Next() {
		if p := obj.findByID(id); p != nil {
			return p
		}
	}
	return nil
}

func (s *Server) getObjectByInd(ind int) *Object { // aka nox_xxx_netGetUnitByExtent_4ED020
	for p := s.firstServerObject(); p != nil; p = p.Next() {
		if !p.Flags().Has(object.FlagDestroyed) && p.Ind() == ind {
			return p
		}
	}
	return nil
}

func (s *Server) getObjectGroupByID(id string) *script.ObjectGroup {
	g := getMapGroupByID(id, 0)
	if g == nil {
		return nil
	}
	// may contain map name, so we load it again
	id = g.ID()
	var list []script.Object
	for wp := g.FirstItem(); wp != nil; wp = wp.Next() {
		ind := int(*(*int32)(wp.Payload()))
		if wl := s.getObjectByInd(ind); wl != nil {
			list = append(list, wl)
		}
	}
	return script.NewObjectGroup(id, list...)
}

func nox_xxx_createAt_4DAA50(obj noxObject, owner noxObject, pos types.Pointf) {
	C.nox_xxx_createAt_4DAA50(obj.CObj(), toCObj(owner), C.float(pos.X), C.float(pos.Y))
}

type nox_object_t = C.nox_object_t

func toCObj(obj noxObject) *nox_object_t {
	if obj == nil {
		return nil
	}
	return obj.CObj()
}

type noxObject interface {
	CObj() *nox_object_t
}

type Object nox_object_t

func (obj *Object) getServer() *Server {
	return noxServer // TODO: attach to object
}

func (obj *Object) UniqueKey() uintptr {
	return uintptr(unsafe.Pointer(obj))
}

func (obj *Object) CObj() *nox_object_t {
	return (*nox_object_t)(unsafe.Pointer(obj))
}

func (obj *Object) field(dp uintptr) unsafe.Pointer {
	return unsafe.Add(unsafe.Pointer(obj), dp)
}

func (obj *Object) ID() string {
	return GoString(obj.id)
}

func (obj *Object) Ind() int { // aka "extent"
	return int(obj.extent)
}

func (obj *Object) ScriptID() int {
	return int(obj.script_id)
}

func (obj *Object) objTypeInd() int {
	return int(obj.typ_ind)
}

func (obj *Object) stringAs(typ string) string {
	if obj == nil {
		return fmt.Sprintf("%s(<nil>)", typ)
	}
	var oid string
	if id := obj.ID(); id != "" {
		oid = fmt.Sprintf("%q", id)
	} else if ind := obj.Ind(); ind != 0 {
		oid = fmt.Sprintf("#%d", ind)
	}
	if obj.Class().Has(object.ClassPlayer) {
		// TODO: better way
		for _, p := range obj.getServer().getPlayers() {
			if u := p.UnitC(); u != nil && u.CObj() == obj.CObj() {
				oid += fmt.Sprintf(",P:%q", p.Name())
			}
		}
	}
	if t := obj.ObjectTypeC(); t != nil {
		return fmt.Sprintf("%s(%s,T:%q)", typ, oid, t.ID())
	}
	return fmt.Sprintf("%s(%s)", typ, oid)
}

func (obj *Object) String() string {
	return obj.stringAs("Object")
}

func (obj *Object) GetObject() script.Object {
	if obj == nil {
		return nil
	}
	return obj
}

func (obj *Object) Class() object.Class {
	return object.Class(obj.obj_class)
}

func (obj *Object) SubClass() uint32 {
	return uint32(obj.obj_subclass)
}

func (obj *Object) ArmorClass() object.ArmorClass {
	if !obj.Class().Has(object.ClassArmor) {
		return 0
	}
	return object.ArmorClass(obj.SubClass())
}

func (obj *Object) Flags() object.Flags {
	return object.Flags(obj.obj_flags)
}

func (obj *Object) SetFlags(v object.Flags) {
	obj.obj_flags = C.uint(v)
}

func (obj *Object) Mass() float32 {
	return float32(obj.mass)
}

func (obj *Object) getShape() *noxShape {
	return (*noxShape)(unsafe.Pointer(&obj.shape))
}

func (obj *Object) ptrXxx() unsafe.Pointer {
	return unsafe.Pointer(obj.data_139)
}

func (obj *Object) IsMovable() bool {
	if obj.Flags().HasAny(object.FlagNotMovableMask) {
		return false
	}
	return !obj.Class().Has(object.ClassImmobile)
}

func (obj *Object) team() byte {
	return obj.teamPtr().field1
}

func (obj *Object) Team() *Team {
	if obj == nil {
		return nil
	}
	return obj.getServer().teamByYyy(obj.team())
}

func (obj *Object) findByID(id string) *Object {
	if obj.equalID(id) {
		return obj
	}
	for p := obj.FirstItem(); p != nil; p = p.NextItem() {
		if p.equalID(id) {
			return p
		}
	}
	return nil
}

func (obj *Object) equalID(id2 string) bool {
	id := obj.ID()
	if id == "" {
		return false
	}
	return id == id2 || strings.HasSuffix(id, ":"+id2)
}

func (obj *Object) Next() *Object { // nox_server_getNextObject_4DA7A0, nox_xxx_getNextUpdatable2Object_4DA850
	return asObject(unsafe.Pointer(obj.field_111))
}

func (obj *Object) FirstItem() *Object { // nox_xxx_inventoryGetFirst_4E7980
	return asObject(unsafe.Pointer(obj.field_126))
}

func (obj *Object) NextItem() *Object {
	return asObject(unsafe.Pointer(obj.field_124))
}

func (obj *Object) updateDataPtr() unsafe.Pointer {
	return unsafe.Pointer(obj.data_update)
}

func (obj *Object) updateDataMissile() *C.nox_object_Missile_data_t {
	return (*C.nox_object_Missile_data_t)(unsafe.Pointer(obj.data_update))
}

func (obj *Object) Inventory() []*Object {
	var out []*Object
	for p := obj.FirstItem(); p != nil; p = p.NextItem() {
		out = append(out, p)
	}
	return out
}

func (obj *Object) NextOwned512() *Object {
	return asObject(unsafe.Pointer(obj.field_128))
}

func (obj *Object) FirstOwned516() *Object {
	return asObject(unsafe.Pointer(obj.field_129))
}

func (obj *Object) GetOwned516() []*Object {
	var out []*Object
	for p := obj.FirstOwned516(); p != nil; p = p.NextOwned512() {
		out = append(out, p)
	}
	return out
}

func (obj *Object) HasEnchant(v EnchantID) bool { // nox_xxx_testUnitBuffs_4FF350
	if obj == nil || v >= 32 {
		return false
	}
	return uint32(obj.buffs)&(uint32(1)<<v) != 0
}

func (obj *Object) EnchantDur(v EnchantID) int { // nox_xxx_unitGetBuffTimer_4FF550
	if obj == nil || v >= 32 {
		return 0
	}
	return int(obj.buffs_dur[v])
}

func (obj *Object) EnchantPower(v EnchantID) int { // nox_xxx_buffGetPower_4FF570
	if obj == nil || v >= 32 {
		return 0
	}
	return int(obj.buffs_dur[v])
}

func (obj *Object) ApplyEnchant(v EnchantID, dur, power int) { // nox_xxx_buffApplyTo_4FF380
	if obj == nil || v >= 32 {
		return
	}
	C.nox_xxx_buffApplyTo_4FF380(obj.CObj(), C.int(v), C.short(dur), C.char(power))
}

func (obj *Object) AsUnit() *Unit {
	// TODO: check somehow
	return asUnit(unsafe.Pointer(obj))
}

func (obj *Object) ObjectTypeC() *ObjectType {
	if obj == nil {
		return nil
	}
	ind := obj.objTypeInd()
	return obj.getServer().getObjectTypeByInd(ind)
}

func (obj *Object) ObjectType() script.ObjectType {
	t := obj.ObjectTypeC()
	if t == nil {
		return nil
	}
	return t
}

func (obj *Object) teamPtr() *objectTeam {
	if obj == nil {
		return nil
	}
	return (*objectTeam)(unsafe.Pointer(&obj.field_12))
}

func (obj *Object) OwnerC() *Object {
	return asObjectC(obj.owner)
}

func (obj *Object) Owner() script.Object {
	p := obj.OwnerC()
	if p == nil {
		return nil
	}
	return p
}

func (obj *Object) SetOwner(owner script.ObjectWrapper) {
	if owner == nil {
		C.nox_xxx_unitClearOwner_4EC300(obj.CObj())
		return
	}
	own := owner.GetObject().(noxObject)
	C.nox_xxx_unitSetOwner_4EC290(own.CObj(), obj.CObj())
}

func (obj *Object) Pos() types.Pointf {
	if obj == nil {
		return types.Pointf{}
	}
	return types.Pointf{
		X: float32(obj.x),
		Y: float32(obj.y),
	}
}

func (obj *Object) Vel() types.Pointf {
	if obj == nil {
		return types.Pointf{}
	}
	return types.Pointf{
		X: float32(obj.vel_x),
		Y: float32(obj.vel_y),
	}
}

func (obj *Object) Force() types.Pointf {
	if obj == nil {
		return types.Pointf{}
	}
	return types.Pointf{
		X: float32(obj.force_x),
		Y: float32(obj.force_y),
	}
}

func (obj *Object) Dir() uint16 {
	if obj == nil {
		return 0
	}
	return uint16(obj.direction)
}

func (obj *Object) curSpeed() float32 {
	if obj == nil {
		return 0
	}
	return float32(obj.speed_cur)
}

func (obj *Object) setDir(dir uint16) {
	obj.field_31_0 = C.uint16_t(dir)
	obj.direction = C.uint16_t(dir)
}

func (obj *Object) prevPos() types.Pointf {
	return types.Pointf{
		X: float32(obj.prev_x),
		Y: float32(obj.prev_y),
	}
}

func (obj *Object) newPos() types.Pointf {
	return types.Pointf{
		X: float32(obj.new_x),
		Y: float32(obj.new_y),
	}
}

func (obj *Object) SetPos(p types.Pointf) {
	cp, free := alloc.New(C.float2{})
	defer free()
	cp.field_0 = C.float(p.X)
	cp.field_4 = C.float(p.Y)
	C.nox_xxx_unitMove_4E7010(obj.CObj(), cp)
}

func (obj *Object) setPos(p types.Pointf) {
	obj.x = C.float(p.X)
	obj.y = C.float(p.Y)
}

func (obj *Object) setPrevPos(p types.Pointf) {
	obj.prev_x = C.float(p.X)
	obj.prev_y = C.float(p.Y)
}

func (obj *Object) setNewPos(p types.Pointf) {
	obj.new_x = C.float(p.X)
	obj.new_y = C.float(p.Y)
}

func (obj *Object) setVel(p types.Pointf) {
	obj.vel_x = C.float(p.X)
	obj.vel_y = C.float(p.Y)
}

func (obj *Object) setForce(p types.Pointf) {
	obj.force_x = C.float(p.X)
	obj.force_y = C.float(p.Y)
}

func (obj *Object) Z() float32 {
	return float32(*(*C.int)(obj.field(104)))
}

func (obj *Object) SetZ(z float32) {
	C.nox_xxx_unitRaise_4E46F0(obj.CObj(), C.float(z))
}

func (obj *Object) Push(vec types.Pointf, force float32) {
	panic("implement me")
}

func (obj *Object) PushTo(p types.Pointf) {
	panic("implement me")
}

func (obj *Object) IsEnabled() bool {
	if obj == nil {
		return false
	}
	return *(*uint32)(obj.field(16))&0x1000000 != 0
}

func (obj *Object) Enable(enable bool) {
	if obj == nil {
		return
	}
	if enable {
		C.nox_xxx_objectSetOn_4E75B0(obj.CObj())
	} else {
		C.nox_xxx_objectSetOff_4E7600(obj.CObj())
	}
}

func (obj *Object) Delete() {
	C.nox_xxx_delayedDeleteObject_4E5CC0(obj.CObj())
}

func (obj *Object) Destroy() {
	panic("implement me")
}

func (obj *Object) callUpdate() {
	if obj.func_update != nil {
		C.nox_call_obj_update_go((*[0]byte)(obj.func_update), obj.CObj())
	}
}

func (obj *Object) callXfer(a2 unsafe.Pointer) int {
	switch unsafe.Pointer(obj.func_xfer) {
	case unsafe.Pointer(C.nox_xxx_XFerDefault_4F49A0):
		return nox_xxx_XFerDefault4F49A0(obj, a2)
	}
	return int(C.nox_call_object_xfer((*[0]byte)(obj.func_xfer), obj.CObj(), a2))
}

func (obj *Object) callDamage(who noxObject, a3, a4, a5 int) {
	if obj.func_damage != nil {
		C.nox_call_object_damage((*[0]byte)(obj.func_damage), obj.CObj(), toCObj(who), C.int(a3), C.int(a4), C.int(a5))
	}
}

func (obj *Object) forceDrop(item *Object) { // nox_xxx_invForceDropItem_4ED930
	pos := randomReachablePointAround(50.0, obj.Pos())
	ptr, free := alloc.Malloc(8)
	defer free()
	cpos := (*C.float2)(ptr)
	cpos.field_0 = C.float(pos.X)
	cpos.field_4 = C.float(pos.Y)
	C.nox_xxx_drop_4ED790(obj.CObj(), item.CObj(), cpos)
}

func (obj *Object) isEnemyTo(objp noxObject) bool { // nox_xxx_unitIsEnemyTo_5330C0
	obj2 := asObjectC(toCObj(objp))
	if obj == nil || obj2 == nil {
		return false
	}
	if obj.CObj() == obj2.CObj() {
		return false
	}
	srv := obj.getServer()
	if srv.objs.types.plant == 0 {
		srv.objs.types.plant = srv.getObjectTypeID("CarnivorousPlant")
		srv.objs.types.polyp = srv.getObjectTypeID("Polyp")
		srv.objs.types.wisp = srv.getObjectTypeID("WillOWisp")
	}
	if obj2.Class().HasAny(object.ClassMonster) {
		if ud := obj2.AsUnit().updateDataMonster(); ud.field_360&0x40000 != 0 {
			return false
		}
	}
	if obj.Class().HasAny(object.ClassPlayer) && obj2.objTypeInd() == srv.objs.types.polyp {
		return true
	}
	if obj.Class().HasAny(object.ClassPlayer) && obj2.Class().HasAny(object.ClassMonsterGenerator) {
		return true
	}
	if obj.Class().HasAny(object.ClassMonster) && obj2.Class().HasAny(object.ClassMonsterGenerator) {
		return false
	}
	if obj.Class().HasAny(object.ClassPlayer) && obj2.Class().HasAny(object.ClassMonster) && (obj2.SubClass()&0x20 != 0) {
		return false
	}
	if obj.Class().HasAny(object.ClassMonster) && obj2.Class().HasAny(object.ClassPlayer) && (obj.SubClass()&0x20 != 0) {
		return false
	}
	if obj.isFish() || obj.isFrog() {
		return !obj2.isFish() && !obj2.isFrog()
	}
	if obj.isRat() {
		return !obj2.isRat()
	}
	if obj2.isFish() {
		return false
	}
	if obj2.Class().HasAny(2) && (obj2.SubClass()&0x8 != 0) {
		return false
	}
	if obj.Class().HasAny(2) && (obj.SubClass()&0x8 != 0) {
		return false
	}
	if obj.HasEnchant(ENCHANT_CHARMING) || obj2.HasEnchant(ENCHANT_CHARMING) {
		return false
	}
	if obj2.Class().HasAny(object.ClassPlayer) {
		if pl := obj2.AsUnit().ControllingPlayer(); pl.field_3680&0x1 != 0 {
			return false
		}
	}
	own1 := obj.findOwnerChainPlayer()
	own2 := obj2.findOwnerChainPlayer()
	if own1 == own2 {
		return false
	}
	if nox_xxx_servCompareTeams_419150(own1.teamPtr(), own2.teamPtr()) {
		return false
	}
	if own1.Class().HasAny(object.ClassPlayer) && own2.Class().HasAny(object.ClassMonsterGenerator) {
		return true
	}
	if own1.Class().HasAny(object.ClassMonster) && own2.Class().HasAny(object.ClassMonsterGenerator) {
		return false
	}
	if !noxflags.HasGame(noxflags.GameModeQuest) && obj.Class().HasAny(object.ClassMonster) && obj2.objTypeInd() == srv.objs.types.wisp {
		return C.nox_xxx_checkMobAction_50A0D0(obj2.CObj(), 15) != 0
	}
	if nox_xxx_servObjectHasTeam_419130(own1.teamPtr()) || nox_xxx_servObjectHasTeam_419130(own2.teamPtr()) {
		return true
	}
	if own1.Class().HasAny(object.ClassMonster) && own2.Class().HasAny(object.ClassMonster) {
		return false
	}
	return true
}

func (obj *Object) isFish() bool {
	if obj == nil {
		return false
	}
	srv := obj.getServer()
	if srv.objs.types.fishSmall == 0 {
		srv.objs.types.fishSmall = srv.getObjectTypeID("FishSmall")
		srv.objs.types.fishBig = srv.getObjectTypeID("FishBig")
	}
	return obj.objTypeInd() == srv.objs.types.fishSmall || obj.objTypeInd() == srv.objs.types.fishBig
}

func (obj *Object) isRat() bool {
	if obj == nil {
		return false
	}
	srv := obj.getServer()
	if srv.objs.types.rat == 0 {
		srv.objs.types.rat = srv.getObjectTypeID("Rat")
	}
	return obj.objTypeInd() == srv.objs.types.rat
}

func (obj *Object) isFrog() bool {
	if obj == nil {
		return false
	}
	srv := obj.getServer()
	if srv.objs.types.frog == 0 {
		srv.objs.types.frog = srv.getObjectTypeID("GreenFrog")
	}
	return obj.objTypeInd() == srv.objs.types.frog
}

func (obj *Object) findOwnerChainPlayer() *Object { // nox_xxx_findParentChainPlayer_4EC580
	if obj == nil {
		return nil
	}
	res := obj
	for it := obj.OwnerC(); it != nil; it = it.OwnerC() {
		if it.Class().Has(object.ClassPlayer) {
			res = it
			break
		}
		res = it
	}
	return res
}
