package server

import (
	"bytes"
	"fmt"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/script"
	"github.com/noxworld-dev/opennox-lib/types"
)

var (
	_ Obj                 = &Object{}
	_ script.Identifiable = &Object{}
)

type Obj interface {
	SObj() *Object
}

type serverObjects struct {
	List           *Object
	Pending        *Object
	UpdatableList  *Object
	UpdatableList2 *Object
	DeletedList    *Object
}

func (s *Server) FirstServerObject() *Object { // nox_server_getFirstObject_4DA790
	return s.Objs.List
}

func (s *Server) GetObjects() []*Object {
	var out []*Object
	for p := s.FirstServerObject(); p != nil; p = p.ObjNext {
		out = append(out, p)
	}
	return out
}

func (s *Server) GetObjectsUpdatable2() []*Object {
	var out []*Object
	for p := s.Objs.UpdatableList2; p != nil; p = p.ObjNext {
		out = append(out, p)
	}
	return out
}

func (s *serverObjects) AddToUpdatable(obj *Object) {
	if obj.IsUpdatable == 0 && !obj.Class().Has(object.ClassMissile) {
		obj.UpdatablePrev = nil
		obj.UpdatableNext = s.UpdatableList
		if s.UpdatableList != nil {
			s.UpdatableList.UpdatablePrev = obj
		}
		s.UpdatableList = obj
		obj.IsUpdatable = 1
		obj.Obj130 = nil
	}
}

func (s *serverObjects) RemoveFromUpdatable(obj *Object) {
	if obj.IsUpdatable == 0 {
		return
	}
	prev := obj.UpdatablePrev
	if prev != nil {
		prev.UpdatableNext = obj.UpdatableNext
	} else {
		s.UpdatableList = obj.UpdatableNext
	}
	if next := obj.UpdatableNext; next != nil {
		next.UpdatablePrev = prev
	}
	obj.IsUpdatable = 0
	obj.Obj130 = nil
}

func (s *Server) getObjectsUninited() []*Object {
	var out []*Object
	for p := s.Objs.Pending; p != nil; p = p.ObjNext {
		out = append(out, p)
	}
	return out
}

func (s *Server) GetObjectByInd(ind int) *Object { // aka nox_xxx_netGetUnitByExtent_4ED020
	for p := s.FirstServerObject(); p != nil; p = p.ObjNext {
		if !p.Flags().Has(object.FlagDestroyed) && p.Ind() == ind {
			return p
		}
	}
	return nil
}

func (s *Server) GetObjectByID(id string) *Object {
	for obj := s.Objs.List; obj != nil; obj = obj.ObjNext {
		if p := obj.FindByID(id); p != nil {
			return p
		}
	}
	for obj := s.Objs.Pending; obj != nil; obj = obj.ObjNext {
		if p := obj.FindByID(id); p != nil {
			return p
		}
	}
	return nil
}

func (s *Server) ObjectsClearPending() {
	var next *Object
	for it := s.Objs.Pending; it != nil; it = next {
		next = it.ObjNext
		it.ObjFlags &^= uint32(object.FlagPending)
		if s.Objs.List != nil {
			s.Objs.List.ObjPrev = it
		}
		it.ObjNext = s.Objs.List
		it.ObjPrev = nil
		s.Objs.List = it
	}
	s.Objs.Pending = nil
}

type Dir16 uint16

func (v Dir16) Vec() types.Pointf {
	x, y := sincosDir(byte(v))
	return types.Pointf{X: x, Y: y}
}

type ObjectIndex struct {
	X     uint16
	Y     uint16
	Next4 *ObjectIndex
	Prev8 *ObjectIndex
	Obj12 *Object
}

type Object struct {
	IDPtr         unsafe.Pointer // 0, 0
	TypeInd       uint16         // 1, 4
	Field1_2      uint16         // 1, 6
	ObjClass      uint32         // 2, 8
	ObjSubClass   uint32         // 3, 12
	ObjFlags      uint32         // 4, 16
	Field5        uint32         // 5, 20
	Material      uint16         // 6, 24
	Field6_2      uint16         // 6, 26
	Experience    float32        // 7, 28
	Worth         uint32         // 8, 32
	NetCode       uint32         // 9, 36
	Extent        uint32         // 10, 40
	ScriptID      int            // 11, 44
	Field12       uint32         // 12, 48
	Field13       uint32         // 13, 52, // TODO: first byte is team?
	PosVec        types.Pointf   // 14, 56
	NewPos        types.Pointf   // 16, 64
	PrevPos       types.Pointf   // 18, 72
	VelVec        types.Pointf   // 20, 80
	ForceVec      types.Pointf   // 22, 88
	Pos24         types.Pointf   // 24, 96, // TODO: something related to acceleration/direction
	ZVal          float32        // 26, 104
	Field27       uint32         // 27, 108
	Float28       float32        // 28, 112, // TODO: damping/drag?
	Field29       uint32         // 29, 116
	Mass          float32        // 30, 120
	Direction1    Dir16          // 31, 124
	Direction2    Dir16          // 31, 126
	Field32       uint32         // 32, 128, TODO: some frame/timestamp
	Field33       uint32         // 33, 132
	Field34       uint32         // 34, 136, TODO: some frame/timestamp
	Field35       uint32         // 35, 140
	Field36       uint32         // 36, 144
	Field37       int            // 37, 148
	Field38       int            // 38, 152
	Pos39         types.Pointf   // 39, 156
	Field41       uint32         // 41, 164
	Field42       uint32         // 42, 168
	Shape         Shape          // 43, 172
	ZSize1        float32        // 56, 224
	ZSize2        float32        // 57, 228
	CollideP1     types.Pointf   // 58, 232
	CollideP2     types.Pointf   // 60, 240
	Field62       uint32         // 62, 248
	Field63       uint32         // 63, 252
	ObjIndexBase  ObjectIndex    // 64, 256
	ObjIndex      [4]ObjectIndex // 68, 272
	ObjIndexCur   uint32         // 84, 336
	Buffs         uint32         // 85, 340
	BuffsDur      [32]uint16     // 86, 344
	BuffsPower    [32]uint8      // 102, 408
	Field110      uint32         // 110, 440
	ObjNext       *Object        // 111, 444
	ObjPrev       *Object        // 112, 448
	DeletedNext   *Object        // 113, 452
	DeletedAt     uint32         // 114, 456
	Field115      uint32         // 115, 460
	Field116      uint32         // 116, 464
	Field117      uint32         // 117, 468
	Field118      uint32         // 118, 472
	UpdatableNext *Object        // 119, 476
	UpdatablePrev *Object        // 120, 480
	IsUpdatable   uint32         // 121, 484
	Weight        uint8          // 122, 488
	Field122_1    uint8          // 122, 489
	CarryCapacity uint16         // 122, 490
	InvHolder     *Object        // 123, 492 // Also health data, possibly same as 556, see 4E4560
	InvNextItem   *Object        // 124, 496, TODO: next item
	Field125      *Object        // 125, 500, TODO: a nox_object_t*? see 4ED0C0
	InvFirstItem  *Object        // 126, 504, TODO: first item
	ObjOwner      *Object        // 127, 508
	Field128      *Object        // 128, 512
	Field129      *Object        // 129, 516
	Obj130        *Object        // 130, 520
	Field131      uint32         // 131, 524
	Pos132        types.Pointf   // 132, 528
	Field134      uint32         // 134, 536, TODO: some timestamp
	Field135      uint32         // 135, 540, TODO: 541 accessed as byte
	SpeedCur      float32        // 136, 544
	Speed2        float32        // 137, 548
	Float138      float32        // 138, 552
	HealthData    *HealthData    // 139, 556
	Field140      uint32         // 140, 560
	Field141      uint32         // 141, 564
	Field142      uint32         // 142, 568
	Field143      uint32         // 143, 572
	Field144      uint32         // 144, 576
	Field145      uint32         // 145, 580
	Field146      uint32         // 146, 584
	Field147      uint32         // 147, 588
	Field148      uint32         // 148, 592
	Field149      uint32         // 149, 596
	Field150      uint32         // 150, 600
	Field151      uint32         // 151, 604
	Field152      uint32         // 152, 608
	Field153      uint32         // 153, 612
	Field154      uint32         // 154, 616
	Field155      uint32         // 155, 620
	Field156      uint32         // 156, 624
	Field157      uint32         // 157, 628
	Field158      uint32         // 158, 632
	Field159      uint32         // 159, 636
	Field160      uint32         // 160, 640
	Field161      uint32         // 161, 644
	Field162      uint32         // 162, 648
	Field163      uint32         // 163, 652
	Field164      uint32         // 164, 656
	Field165      uint32         // 165, 660
	Field166      uint32         // 166, 664
	Field167      uint32         // 167, 668
	Field168      uint32         // 168, 672
	Field169      uint32         // 169, 676
	Field170      uint32         // 170, 680
	Field171      uint32         // 171, 684
	Init          unsafe.Pointer // 172, 688
	InitData      unsafe.Pointer // 173, 692, // TODO: struct pointer; struct at least 8 bytes wide. see 4F3030.
	Collide       unsafe.Pointer // 174, 696
	CollideData   unsafe.Pointer // 175, 700
	Xfer          unsafe.Pointer // 176, 704; func(*Object, int) int
	Pickup        unsafe.Pointer // 177, 708
	Drop          unsafe.Pointer // 178, 712
	Damage        unsafe.Pointer // 179, 716; func(*Object, *Object, int, int, int) int
	DamageSound   unsafe.Pointer // 180, 720
	Death         unsafe.Pointer // 181, 724
	DeathData     unsafe.Pointer // 182, 728
	Use           unsafe.Pointer // 183, 732
	UseData       unsafe.Pointer // 184, 736
	Field185      uint32         // 185, 740
	Update        unsafe.Pointer // 186, 744; func(*Object)
	UpdateData    unsafe.Pointer // 187, 748
	Field188      uint32         // 188, 752
	Field189      unsafe.Pointer // 189, 756
	Field190      uint32         // 190, 760
	Field191      uint32         // 191, 764
	Field192      int            // 192, 768
}

func (obj *Object) SObj() *Object {
	if obj == nil {
		return nil
	}
	return obj
}

func (obj *Object) Ind() int { // aka "extent"
	return int(obj.Extent)
}

func (obj *Object) ID() string {
	if obj == nil {
		return ""
	}
	arr := unsafe.Slice((*byte)(obj.IDPtr), 512)
	i := bytes.IndexByte(arr, 0)
	if i < 0 {
		return string(arr)
	}
	return string(arr[:i])
}

func (obj *Object) EqualID(id2 string) bool {
	id := obj.ID()
	if id == "" {
		return false
	}
	return id == id2 || strings.HasSuffix(id, ":"+id2)
}

func (obj *Object) FindByID(id string) *Object {
	if obj.EqualID(id) {
		return obj
	}
	for p := obj.InvFirstItem; p != nil; p = p.InvNextItem {
		if p.EqualID(id) {
			return p
		}
	}
	return nil
}

func (obj *Object) HasItem(item *Object) bool {
	if item == nil || item.InvHolder != obj {
		return false
	}
	for p := obj.InvFirstItem; p != nil; p = p.InvNextItem {
		if p == item {
			return true
		}
	}
	return false
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
	if t := obj.TypeInd; t != 0 {
		return fmt.Sprintf("%s(%s,T:%q)", typ, oid, t)
	}
	return fmt.Sprintf("%s(%s)", typ, oid)
}

func (obj *Object) String() string {
	return obj.stringAs("Object")
}

func (obj *Object) Pos() types.Pointf {
	if obj == nil {
		return types.Pointf{}
	}
	return obj.PosVec
}

func (obj *Object) Vel() types.Pointf {
	if obj == nil {
		return types.Pointf{}
	}
	return obj.VelVec
}

func (obj *Object) Force() types.Pointf {
	if obj == nil {
		return types.Pointf{}
	}
	return obj.ForceVec
}

func (obj *Object) Class() object.Class {
	return object.Class(obj.ObjClass)
}

func (obj *Object) SubClass() object.SubClass {
	return object.SubClass(obj.ObjSubClass)
}

func (obj *Object) ArmorClass() object.ArmorClass {
	if !obj.Class().Has(object.ClassArmor) {
		return 0
	}
	return object.ArmorClass(obj.SubClass())
}

func (obj *Object) Flags() object.Flags {
	return object.Flags(obj.ObjFlags)
}

func (obj *Object) IsEnabled() bool {
	if obj == nil {
		return false
	}
	return obj.Flags().Has(object.FlagEnabled)
}

func (obj *Object) IsMovable() bool {
	if obj.Flags().HasAny(object.FlagNotMovableMask) {
		return false
	}
	return !obj.Class().Has(object.ClassImmobile)
}

func (obj *Object) Dir1() Dir16 {
	if obj == nil {
		return 0
	}
	return obj.Direction1
}

func (obj *Object) Dir2() Dir16 {
	if obj == nil {
		return 0
	}
	return obj.Direction2
}

func (obj *Object) UpdateDataPlayer() *PlayerUpdateData {
	if !obj.Class().Has(object.ClassPlayer) {
		panic(obj.Class().String())
	}
	// TODO: verify this conversion by checking ObjectType
	return (*PlayerUpdateData)(obj.UpdateData)
}

func (obj *Object) UpdateDataMonster() *MonsterUpdateData {
	if !obj.Class().Has(object.ClassMonster) {
		panic(obj.Class().String())
	}
	// TODO: verify this conversion by checking ObjectType
	return (*MonsterUpdateData)(obj.UpdateData)
}

func (obj *Object) Push(vec types.Pointf, force float32) {
	p := obj.Pos().Sub(vec)
	l := float32(p.Len())
	p.X = force * p.X / l
	p.Y = force * p.Y / l
	obj.PushTo(p)
}

// ApplyForce adds a new force vector to the object. If another force in effect, it will adds up.
func (obj *Object) ApplyForce(p types.Pointf) {
	obj.ForceVec = obj.ForceVec.Add(p)
}

func (obj *Object) PushTo(p types.Pointf) {
	obj.ForceVec = obj.ForceVec.Add(p)
}

func (obj *Object) SetDir(v Dir16) {
	obj.Direction1 = v
	obj.Direction2 = v
}

func (obj *Object) LookAt(p types.Pointf) {
	p = p.Sub(obj.Pos())
	v := DirFromVec(p)
	obj.SetDir(v)
}

func (obj *Object) Health() (cur, max int) {
	if obj == nil {
		return
	}
	h := obj.HealthData
	if h == nil {
		return
	}
	cur = int(h.Cur)
	max = int(h.Max)
	return
}

func (obj *Object) Mana() (cur, max int) {
	if obj == nil {
		return
	}
	p := obj.UpdateDataPlayer()
	if p == nil {
		return
	}
	cur = int(p.ManaCur)
	max = int(p.ManaMax)
	return
}

func (obj *Object) HasEnchant(v EnchantID) bool { // nox_xxx_testUnitBuffs_4FF350
	if obj == nil || v >= 32 {
		return false
	}
	return obj.Buffs&(uint32(1)<<v) != 0
}

func (obj *Object) EnchantDur(v EnchantID) int { // nox_xxx_unitGetBuffTimer_4FF550
	if obj == nil || v >= 32 {
		return 0
	}
	return int(obj.BuffsDur[v])
}

func (obj *Object) EnchantPower(v EnchantID) int { // nox_xxx_buffGetPower_4FF570
	if obj == nil || v >= 32 {
		return 0
	}
	return int(obj.BuffsDur[v])
}

func (obj *Object) HasOwner(owner *Object) bool {
	if obj == nil {
		return false
	}
	for it := obj; it != nil; it = it.ObjOwner {
		if it == owner {
			return true
		}
	}
	return false
}

func (obj *Object) FindOwnerChainPlayer() *Object {
	if obj == nil {
		return nil
	}
	res := obj
	for it := obj.ObjOwner; it != nil; it = it.ObjOwner {
		if it.Class().Has(object.ClassPlayer) {
			res = it
			break
		}
		res = it
	}
	return res
}

func (obj *Object) UpdateCollider() {
	sh := &obj.Shape
	switch sh.Kind {
	case ShapeKindCenter:
		obj.CollideP1 = obj.NewPos
		obj.CollideP2 = obj.NewPos
	case ShapeKindCircle:
		r := types.Ptf(sh.Circle.R, sh.Circle.R)
		obj.CollideP1 = obj.NewPos.Sub(r)
		obj.CollideP2 = obj.NewPos.Add(r)
	case ShapeKindBox:
		obj.CollideP1 = obj.NewPos.Add(types.Ptf(sh.Box.LeftBottom2, sh.Box.LeftBottom))
		obj.CollideP2 = obj.NewPos.Add(types.Ptf(sh.Box.RightTop, sh.Box.RightTop2))
	}
}
