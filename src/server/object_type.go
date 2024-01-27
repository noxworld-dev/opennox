package server

import (
	"encoding/json"
	"errors"
	"fmt"
	"math"
	"strconv"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/player"
	"github.com/noxworld-dev/opennox-lib/things"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

var (
	createFuncs    = make(map[string]unsafe.Pointer)
	initFuncs      = make(map[string]objectDefFunc)
	initParseFuncs = map[string]ObjectParseFunc{
		"SkullInit":     objectDirectionInitParse,
		"DirectionInit": objectDirectionInitParse,
		"BreakInit": func(objt *ObjectType, _ []string) error {
			objt.Field9 = 2
			return nil
		},
	}
	updateFuncs       = make(map[string]objectDefFunc)
	updateParseFuncs  = make(map[string]ObjectParseFunc)
	collideFuncs      = make(map[string]objectDefFunc)
	collideParseFuncs = make(map[string]ObjectParseFunc)
	useFuncs          = make(map[string]objectDefFunc)
	useParseFuncs     = make(map[string]ObjectParseFunc)
	damageFuncs       = make(map[string]unsafe.Pointer)
	damageSoundFuncs  = make(map[string]unsafe.Pointer)
	deathFuncs        = make(map[string]objectDefFunc)
	deathParseFuncs   = make(map[string]ObjectParseFunc)
	dropFuncs         = make(map[string]unsafe.Pointer)
	dropParseFuncs    = map[string]ObjectParseFunc{
		"AudEventDrop": func(t *ObjectType, args []string) error {
			if len(args) != 0 {
				if snd := sound.ByName(args[0]); snd != 0 {
					t.s.dropSoundTable[t.ind] = snd
				}
			}
			return nil
		},
	}
	pickupFuncs      = make(map[string]unsafe.Pointer)
	pickupParseFuncs = map[string]ObjectParseFunc{
		"AudEventPickup": func(t *ObjectType, args []string) error {
			if len(args) != 0 {
				if snd := sound.ByName(args[0]); snd != 0 {
					t.s.pickupSoundTable[t.ind] = snd
				}
			}
			return nil
		},
	}
	xferFuncs = make(map[string]unsafe.Pointer)
)

type ObjectParseFunc func(objt *ObjectType, args []string) error

type objectDefFunc struct {
	Func     unsafe.Pointer
	DataSize uintptr
}

var (
	DefaultDamage      unsafe.Pointer
	DefaultDamageSound unsafe.Pointer
	DefaultXfer        unsafe.Pointer
)

func init() {
	RegisterObjectCreate("NoCreate", nil)
	RegisterObjectCreate("PlayerCreate", nil)

	RegisterObjectInit("NoInit", nil, 0)
	RegisterObjectInit("ProjectileInit", nil, 0)
	RegisterObjectInit("GruntInit", nil, 0)
	RegisterObjectInit("SkeletonInit", nil, 0)
	RegisterObjectInit("TowerInit", nil, 0)
	RegisterObjectInit("RewardMarkerInit", nil, 220)
	RegisterObjectInit("AnkhInit", nil, 5124)

	RegisterObjectUpdate("NoUpdate", nil, 0)
	RegisterObjectUpdate("HomingProjectileUpdate", nil, 4)
	RegisterObjectUpdate("SpikeBlockUpdate", nil, 2200)
	RegisterObjectUpdate("TowerUpdate", nil, 8)
	RegisterObjectUpdate("WeaponArmorUpdate", nil, 8)

	RegisterObjectCollide("NoCollide", nil, 0)

	RegisterObjectUse("AmmoUse", nil, 3)
	RegisterObjectUse("BowUse", nil, 1)
}

func RegisterObjectCreate(name string, fnc unsafe.Pointer) {
	if _, ok := createFuncs[name]; ok {
		panic("already registered")
	}
	createFuncs[name] = fnc
}

func RegisterObjectInit(name string, fnc unsafe.Pointer, sz uintptr) {
	if _, ok := initFuncs[name]; ok {
		panic("already registered")
	}
	initFuncs[name] = objectDefFunc{Func: fnc, DataSize: sz}
}

func RegisterObjectUpdate(name string, fnc unsafe.Pointer, sz uintptr) {
	if _, ok := updateFuncs[name]; ok {
		panic("already registered")
	}
	updateFuncs[name] = objectDefFunc{Func: fnc, DataSize: sz}
}

func RegisterObjectUpdateParse(name string, fnc ObjectParseFunc) {
	if _, ok := updateParseFuncs[name]; ok {
		panic("already registered")
	}
	updateParseFuncs[name] = fnc
}

func RegisterObjectCollide(name string, fnc unsafe.Pointer, sz uintptr) {
	if _, ok := collideFuncs[name]; ok {
		panic("already registered")
	}
	collideFuncs[name] = objectDefFunc{Func: fnc, DataSize: sz}
}

func RegisterObjectCollideParse(name string, fnc ObjectParseFunc) {
	if _, ok := collideParseFuncs[name]; ok {
		panic("already registered")
	}
	collideParseFuncs[name] = fnc
}

func RegisterObjectUse(name string, fnc unsafe.Pointer, sz uintptr) {
	if _, ok := useFuncs[name]; ok {
		panic("already registered")
	}
	useFuncs[name] = objectDefFunc{Func: fnc, DataSize: sz}
}

func RegisterObjectUseParse(name string, fnc ObjectParseFunc) {
	if _, ok := useParseFuncs[name]; ok {
		panic("already registered")
	}
	useParseFuncs[name] = fnc
}

func RegisterObjectDamage(name string, fnc unsafe.Pointer) {
	if _, ok := damageFuncs[name]; ok {
		panic("already registered")
	}
	damageFuncs[name] = fnc
}

func RegisterObjectDamageSound(name string, fnc unsafe.Pointer) {
	if _, ok := damageSoundFuncs[name]; ok {
		panic("already registered")
	}
	damageSoundFuncs[name] = fnc
}

func RegisterObjectDeath(name string, fnc unsafe.Pointer, sz uintptr) {
	if _, ok := deathFuncs[name]; ok {
		panic("already registered")
	}
	deathFuncs[name] = objectDefFunc{Func: fnc, DataSize: sz}
}

func RegisterObjectDeathParse(name string, fnc ObjectParseFunc) {
	if _, ok := deathParseFuncs[name]; ok {
		panic("already registered")
	}
	deathParseFuncs[name] = fnc
}

func RegisterObjectDrop(name string, fnc unsafe.Pointer) {
	if _, ok := dropFuncs[name]; ok {
		panic("already registered")
	}
	dropFuncs[name] = fnc
}

func RegisterObjectPickup(name string, fnc unsafe.Pointer) {
	if _, ok := pickupFuncs[name]; ok {
		panic("already registered")
	}
	pickupFuncs[name] = fnc
}

func RegisterObjectXfer(name string, fnc unsafe.Pointer) {
	if _, ok := xferFuncs[name]; ok {
		panic("already registered")
	}
	xferFuncs[name] = fnc
}

type serverObjTypes struct {
	first *ObjectType
	byInd []*ObjectType
	byID  map[string]*ObjectType
	crc   uint32

	playerAnimFrames [][2]int
	dropSoundTable   map[uint16]sound.ID
	pickupSoundTable map[uint16]sound.ID

	fast struct {
		frog       int
		rat        int
		fishSmall  int
		fishBig    int
		plant      int
		polyp      int
		wisp       int
		mimic      int
		ball       int
		crown      int
		npc        int
		bomber     int
		glyph      int
		silverKey  int
		gold       int
		goldPile   int
		goldChest  int
		pixie      int
		hecubah    int
		necrom     int
		zombie     int
		zombieVile int
		magic      int
		deathBall  int
		flag       int
	}

	ClientTypeByID func(id string) int
}

func (s *serverObjTypes) init() {
	s.dropSoundTable = make(map[uint16]sound.ID)
	s.pickupSoundTable = make(map[uint16]sound.ID)
	s.playerAnimFrames = make([][2]int, len(playerAnimTypes))
}

func (s *serverObjTypes) cacheObjectTypeID(vr *int, id string) int {
	if *vr == 0 {
		*vr = s.IndByID(id)
	}
	return *vr
}

func (s *serverObjTypes) NPCID() int {
	return s.cacheObjectTypeID(&s.fast.npc, "NPC")
}

func (s *serverObjTypes) MimicID() int {
	return s.cacheObjectTypeID(&s.fast.mimic, "Mimic")
}

func (s *serverObjTypes) CarnivorousPlantID() int {
	return s.cacheObjectTypeID(&s.fast.plant, "CarnivorousPlant")
}

func (s *serverObjTypes) PolypID() int {
	return s.cacheObjectTypeID(&s.fast.polyp, "Polyp")
}

func (s *serverObjTypes) WillOWispID() int {
	return s.cacheObjectTypeID(&s.fast.wisp, "WillOWisp")
}

func (s *serverObjTypes) FishSmallID() int {
	return s.cacheObjectTypeID(&s.fast.fishSmall, "FishSmall")
}

func (s *serverObjTypes) FishBigID() int {
	return s.cacheObjectTypeID(&s.fast.fishBig, "FishBig")
}

func (s *serverObjTypes) RatID() int {
	return s.cacheObjectTypeID(&s.fast.rat, "Rat")
}

func (s *serverObjTypes) GreenFrogID() int {
	return s.cacheObjectTypeID(&s.fast.frog, "GreenFrog")
}

func (s *serverObjTypes) GameBallID() int {
	return s.cacheObjectTypeID(&s.fast.ball, "GameBall")
}

func (s *serverObjTypes) CrownID() int {
	return s.cacheObjectTypeID(&s.fast.crown, "Crown")
}

func (s *serverObjTypes) BomberID() int {
	return s.cacheObjectTypeID(&s.fast.bomber, "Bomber")
}

func (s *serverObjTypes) GlyphID() int {
	return s.cacheObjectTypeID(&s.fast.glyph, "Glyph")
}

func (s *serverObjTypes) SilverKeyID() int {
	return s.cacheObjectTypeID(&s.fast.silverKey, "SilverKey")
}

func (s *serverObjTypes) GoldID() int {
	return s.cacheObjectTypeID(&s.fast.gold, "Gold")
}

func (s *serverObjTypes) GoldPileID() int {
	return s.cacheObjectTypeID(&s.fast.goldPile, "QuestGoldPile")
}

func (s *serverObjTypes) GoldChestID() int {
	return s.cacheObjectTypeID(&s.fast.goldChest, "QuestGoldChest")
}

func (s *serverObjTypes) PixieID() int {
	return s.cacheObjectTypeID(&s.fast.pixie, "Pixie")
}

func (s *serverObjTypes) HecubahID() int {
	return s.cacheObjectTypeID(&s.fast.hecubah, "Hecubah")
}

func (s *serverObjTypes) NecromancerID() int {
	return s.cacheObjectTypeID(&s.fast.necrom, "Necromancer")
}

func (s *serverObjTypes) ZombieID() int {
	return s.cacheObjectTypeID(&s.fast.zombie, "Zombie")
}

func (s *serverObjTypes) VileZombieID() int {
	return s.cacheObjectTypeID(&s.fast.zombieVile, "VileZombie")
}

func (s *serverObjTypes) DeathBallID() int {
	return s.cacheObjectTypeID(&s.fast.deathBall, "DeathBall")
}

func (s *serverObjTypes) MagicID() int {
	return s.cacheObjectTypeID(&s.fast.magic, "Magic")
}

func (s *serverObjTypes) FlagID() int {
	return s.cacheObjectTypeID(&s.fast.flag, "Flag")
}

func (s *serverObjTypes) ReadObjectType(thg *things.Thing) error {
	typ := &ObjectType{
		s:        s,
		id:       thg.Name,
		Icon:     -1,
		material: object.MaterialNone,
		Mass:     1,
		ZSize1:   0, ZSize2: 30,
		Damage:      DefaultDamage,
		DamageSound: DefaultDamageSound,
		Xfer:        DefaultXfer,
		Weight:      255,
		CarryCap:    thg.CarryCap,
	}
	typ.ind = uint16(len(s.byInd))
	s.byInd = append(s.byInd, typ)

	if thg.Mass != 0 {
		typ.Mass = float32(thg.Mass)
	}
	if thg.Weight != 0 {
		typ.Weight = byte(thg.Weight)
	}
	if thg.Price != nil {
		typ.Worth = *thg.Price
	}
	if thg.Experience != 0 {
		typ.Experience = float32(thg.Experience)
	}
	if thg.ZSize != nil {
		v1, v2 := thg.ZSize.Bottom, thg.ZSize.Top
		if v2 < v1 {
			v2 = v1
		}
		typ.ZSize1 = float32(v1)
		typ.ZSize2 = float32(v2)
	}
	if thg.Speed != nil {
		fv := float32(float64(*thg.Speed) / 32)
		typ.SpeedBonus = 0
		typ.Speed = fv
		typ.SpeedBase = fv
	}
	for _, s := range thg.Class {
		v, err := object.ParseClass(string(s))
		if err != nil {
			Log.Printf("%q (%d): %v", typ.ID(), typ.Ind(), err)
		}
		typ.class |= v
	}
	for _, s := range thg.SubClass {
		v, err := object.ParseSubClass(string(s))
		if err != nil {
			Log.Printf("%q (%d): %v", typ.ID(), typ.Ind(), err)
		}
		typ.subclass |= v
	}
	for _, s := range thg.Flags {
		v, err := object.ParseFlag(string(s))
		if err != nil {
			Log.Printf("%q (%d): %v", typ.ID(), typ.Ind(), err)
		}
		typ.flags |= v
	}
	if len(thg.Material) != 0 {
		typ.material = 0
		for _, s := range thg.Material {
			v, err := object.ParseMaterial(string(s))
			if err != nil {
				Log.Printf("%q (%d): %v", typ.ID(), typ.Ind(), err)
			}
			typ.material |= v
		}
	}
	if thg.Health != nil {
		if typ.health != nil {
			alloc.Free(typ.health)
		}
		data, _ := alloc.New(HealthData{})
		typ.health = data
		data.Cur = uint16(*thg.Health)
		data.Max = uint16(*thg.Health)
	}
	if thg.Menu != nil {
		typ.Icon = thg.Menu.Ind
	}
	switch v := thg.Extent.(type) {
	case nil:
		typ.Shape.Kind = ShapeKindNone
	case things.Center:
		typ.Shape.Kind = ShapeKindCenter
	case things.Circle:
		typ.Shape.Kind = ShapeKindCircle
		typ.Shape.Circle.R = v.R
		typ.Shape.Circle.R2 = v.R * v.R
	case things.Box:
		typ.Shape.Kind = ShapeKindBox
		typ.Shape.Box.W = v.W
		typ.Shape.Box.H = v.H
		typ.Shape.Box.Calc()
	default:
		return fmt.Errorf("unsupported shape type: %T", v)
	}
	if err := typ.parseCreate(thg.OnCreate); err != nil {
		return err
	}
	if err := typ.parseInit(thg.OnInit); err != nil {
		return err
	}
	if err := typ.parseUpdate(thg.OnUpdate); err != nil {
		return err
	}
	if err := typ.parseCollide(thg.OnCollide); err != nil {
		return err
	}
	if err := typ.parseUse(thg.OnUse); err != nil {
		return err
	}
	if err := typ.parseDamage(thg.OnDamage); err != nil {
		return err
	}
	if err := typ.parseDamageSound(thg.DamageSound); err != nil {
		return err
	}
	if err := typ.parseDeath(thg.OnDie); err != nil {
		return err
	}
	if err := typ.parseDrop(thg.OnDrop); err != nil {
		return err
	}
	if err := typ.parsePickup(thg.OnPickup); err != nil {
		return err
	}
	if err := typ.parseXfer(thg.OnXfer); err != nil {
		return err
	}
	if err := typ.parseDraw(thg.Draw); err != nil {
		return err
	}
	if typ.Collide == nil {
		typ.flags |= object.FlagNoCollide
	}
	typ.ind2 = typ.ind
	typ.flags |= object.FlagEnabled
	if typ.Class().Has(object.ClassImmobile) {
		typ.Mass = 1e10
	}
	if typ.Class().Has(object.ClassMissile) {
		typ.Field13 = 1.0
		typ.Speed *= 2
		typ.SpeedBase *= 2
	} else {
		typ.Field13 = 0.5
	}
	switch thg.Name {
	case "Boulder", "RollingBoulder", "BoulderIndestructible":
		typ.Field13 = 0.01
		typ.Mass = 100.0
	case "Rock7":
		typ.Mass = 0.25
	}
	if typ.Class().Has(object.ClassMonster) {
		ud := typ.UpdateDataMonster()
		ud.ScriptEnemySighted.Func = -1
		ud.ScriptLookingForEnemy.Func = -1
		ud.ScriptDeath.Func = -1
	} else if typ.Class().Has(object.ClassTrigger) {
		ud := unsafe.Slice((*int32)(typ.UpdateData), 9)
		ud[4] = -1
		ud[6] = -1
		ud[8] = -1
	} else if typ.Class().Has(object.ClassHole) {
		*(*int32)(unsafe.Add(typ.CollideData, 4)) = -1
	}
	if typ.Class().HasAny(object.ClassWeapon | object.ClassArmor | object.ClassPlayer | object.ClassMonster) {
		if typ.health == nil {
			typ.health, _ = alloc.New(HealthData{})
		}
	}
	typ.allowed = true
	typ.Mass *= 10.0
	s.crc ^= s.protectType(typ)
	typ.next = s.first
	s.first = typ
	s.byID[strings.ToLower(thg.Name)] = typ
	return nil
}

func (s *Server) FreeObjectTypes() {
	s.Types.Free()
}

func (s *serverObjTypes) Free() {
	if s.first == nil && s.byID != nil {
		return
	}
	var next *ObjectType
	for typ := s.first; typ != nil; typ = next {
		next = typ.next
		typ.id = ""
		if typ.health != nil {
			alloc.Free(typ.health)
			typ.health = nil
		}
		if typ.CollideData != nil {
			alloc.FreePtr(typ.CollideData)
			typ.CollideData = nil
		}
		if typ.DeathData != nil {
			alloc.FreePtr(typ.DeathData)
			typ.DeathData = nil
		}
		if typ.InitData != nil {
			alloc.FreePtr(typ.InitData)
			typ.InitData = nil
		}
		if typ.UpdateData != nil {
			if typ.Class().Has(object.ClassMonster) {
				ud := typ.UpdateDataMonster()
				if ud.Field119 != nil {
					alloc.Free(ud.Field119)
				}
			}
			alloc.FreePtr(typ.UpdateData)
			typ.UpdateData = nil
		}
		if typ.UseData != nil {
			alloc.FreePtr(typ.UseData)
			typ.UseData = nil
		}
		*typ = ObjectType{}
	}
	s.first = nil
	s.byInd = []*ObjectType{nil}
	s.byID = make(map[string]*ObjectType)
	s.crc = 0
}

func (s *serverObjTypes) ByInd(ind int) *ObjectType {
	if ind == math.MaxUint16 {
		return nil
	}
	if ind < 0 || ind >= len(s.byInd) {
		return nil
	}
	return s.byInd[ind]
}

func (s *serverObjTypes) ByID(id string) *ObjectType {
	id = strings.ToLower(id)
	return s.byID[id]
}

func (s *serverObjTypes) IndByID(id string) int {
	typ := s.ByID(id)
	if typ == nil {
		return 0
	}
	return typ.Ind()
}

func (s *serverObjTypes) List() (out []*ObjectType) {
	for _, typ := range s.byInd {
		if typ == nil {
			continue
		}
		out = append(out, typ)
	}
	return
}

func (s *serverObjTypes) Count() int {
	return len(s.byInd)
}

func (s *serverObjTypes) disableObject(typ *ObjectType) {
	if typ.allowed {
		s.crc ^= 1
	} else {
		s.crc ^= 0
	}
	typ.allowed = false
}

func (s *serverObjTypes) enableObject(typ *ObjectType) {
	if typ.allowed {
		s.crc ^= 1
	} else {
		s.crc ^= 0
	}
	typ.allowed = true
	s.crc ^= 1
}

func (s *serverObjTypes) protectTypeFields(typ *ObjectType) uint32 {
	val := uint32(typ.ind2) ^
		uint32(typ.flags) ^
		typ.Field9 ^
		math.Float32bits(typ.Mass)
	if h := typ.health; h != nil {
		val ^= uint32(h.Cur ^ h.Max)
	}
	return val
}

func (s *serverObjTypes) protectType(typ *ObjectType) uint32 {
	if typ == nil {
		return 0
	}
	val := uint32(typ.ind)
	if typ.allowed {
		val ^= 1
	} else {
		val ^= 0
	}
	val ^= s.protectTypeFields(typ)
	val ^= protectBytes([]byte(typ.ID()))
	return val
}

func (s *Server) ProtectTypeCheck() {
	s.Types.protectTypeCheck()
}

func (s *serverObjTypes) protectTypeCheck() {
	val := uint32(0)
	for typ := s.first; typ != nil; typ = typ.next {
		val ^= s.protectType(typ)
	}
	if val != s.crc {
		// TODO: there was a nop function here; what was it for?
	}
}

func (s *serverObjTypes) checkObjSizes() error {
	const maxSize = 85
	for typ := s.first; typ != nil; typ = typ.next {
		if typ.Flags().Has(object.FlagNoCollide) {
			continue
		}
		shape := &typ.Shape
		if shape.Kind == ShapeKindCircle {
			if sz := 2 * shape.Circle.R; sz >= maxSize {
				return fmt.Errorf("object %q is too large: %v >= %v", typ.ID(), sz, maxSize)
			}
		} else if shape.Kind == ShapeKindBox {
			shape.Box.Calc()
			if sz := shape.Box.RightTop - shape.Box.LeftBottom2; sz >= 85.0 {
				return fmt.Errorf("object %q is too large: %v >= %v", typ.ID(), sz, maxSize)
			} else if sz = shape.Box.RightTop2 - shape.Box.LeftBottom; sz >= 85.0 {
				return fmt.Errorf("object %q is too large: %v >= %v", typ.ID(), sz, maxSize)
			}
		}
	}
	return nil
}

func (s *serverObjTypes) checkTypes() error {
	if err := s.checkObjSizes(); err != nil {
		return err
	}
	s.protectTypeCheck()
	return nil
}

func (s *Server) CheckTypes() error {
	return s.Types.checkTypes()
}

func (s *Server) Sub_4F40A0(obj *Object) int8 {
	if obj == nil {
		return 0
	}
	if obj.ID() != "" {
		return -1
	}
	if obj.InvFirstItem != nil {
		return -1
	}
	if obj.Field129 != nil {
		return -1
	}
	if obj.TeamVal.ID != 0 {
		return -1
	}
	typ := s.Types.ByInd(int(obj.TypeInd))
	if (obj.Flags()^typ.Flags())&0x11408162 != 0 {
		return -1
	}
	if (byte(obj.Field5)^byte(typ.Field9))&0x5E != 0 {
		return -1
	}
	if noxflags.HasGame(noxflags.GameFlag22 | noxflags.GameFlag23) {
		v3 := alloc.GoString((*byte)(obj.Field189))
		if v3 != "" {
			return -1
		}
	} else if noxflags.HasGame(noxflags.GameHost) && obj.Field192 != -1 {
		return -1
	}
	return 0
}

type ShapeKind uint32

const (
	ShapeKindNone   = ShapeKind(0)
	ShapeKindCenter = ShapeKind(1)
	ShapeKindCircle = ShapeKind(2)
	ShapeKindBox    = ShapeKind(3)
)

var _ = ([1]struct{}{})[52-unsafe.Sizeof(Shape{})]

type Shape struct {
	Kind   ShapeKind // 0, 0x0, (43, 172)
	Circle struct {
		R  float32 // 1, 0x4, (44, 176)
		R2 float32 // 2, 0x8, (45, 180)
	}
	Box ShapeBox
}

type ShapeBox struct {
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

func (s *ShapeBox) Calc() {
	const mul = 0.35354999 // cos(Pi/4) / 2
	px := s.W * mul
	py := s.H * mul

	v := float32(0.0)

	v = -px + py
	s.LeftTop = v
	s.LeftTop2 = v

	v = -px - py
	s.LeftBottom = v
	s.LeftBottom2 = v

	v = +px + py
	s.RightTop = v
	s.RightTop2 = v

	v = +px - py
	s.RightBottom = v
	s.RightBottom2 = v
}

type HealthData struct {
	Cur     uint16 // 0, 0
	Field2  uint16 // 0, 2
	Max     uint16 // 1, 4
	field6  uint16 // 1, 6
	field8  uint32 // 2, 8
	field12 uint32 // 3, 12
	Field16 uint32 // 4, 16
}

func (h *HealthData) C() unsafe.Pointer {
	return unsafe.Pointer(h)
}

type ObjectType struct {
	s               *serverObjTypes
	ind             uint16
	id              string
	Icon            int
	allowed         bool
	ind2            uint16
	class           object.Class
	subclass        object.SubClass
	flags           object.Flags
	Field9          uint32
	material        object.Material
	Experience      float32
	Worth           int
	Field13         float32
	Mass            float32
	Shape           Shape
	ZSize1          float32
	ZSize2          float32
	Weight          byte
	CarryCap        int
	Speed           float32
	SpeedBase       float32
	SpeedBonus      float32
	health          *HealthData
	Collide         unsafe.Pointer
	CollideData     unsafe.Pointer
	CollideDataSize uintptr
	Damage          unsafe.Pointer
	DamageSound     unsafe.Pointer
	Death           unsafe.Pointer
	DeathData       unsafe.Pointer
	Drop            unsafe.Pointer
	Init            unsafe.Pointer
	InitData        unsafe.Pointer
	InitDataSize    uintptr
	Pickup          unsafe.Pointer
	Update          unsafe.Pointer
	UpdateData      unsafe.Pointer
	UpdateDataSize  uintptr
	Use             unsafe.Pointer
	UseData         unsafe.Pointer
	UseDataSize     uintptr
	Xfer            unsafe.Pointer
	Create          unsafe.Pointer
	next            *ObjectType
}

func (t *ObjectType) ID() string {
	return t.id
}

func (t *ObjectType) Ind() int {
	if t == nil {
		return 0
	}
	return int(t.ind)
}

func (t *ObjectType) Ind2() int {
	return int(t.ind2)
}

func (t *ObjectType) Class() object.Class {
	return t.class
}

func (t *ObjectType) SubClass() object.SubClass {
	return t.subclass
}

func (t *ObjectType) MonsterClass() object.MonsterClass {
	if !t.Class().Has(object.ClassMonster) {
		return 0
	}
	return t.SubClass().AsMonster()
}

func (t *ObjectType) ArmorClass() object.ArmorClass {
	if !t.Class().Has(object.ClassArmor) {
		return 0
	}
	return t.SubClass().AsArmor()
}

func (t *ObjectType) WeaponClass() object.WeaponClass {
	if !t.Class().Has(object.ClassWeapon) {
		return 0
	}
	return t.SubClass().AsWeapon()
}

func (t *ObjectType) OtherClass() object.OtherClass {
	if !t.Class().HasAny(object.ClassMonster | object.ClassArmor | object.ClassWeapon) {
		return 0
	}
	return t.SubClass().AsOther()
}

func (t *ObjectType) Flags() object.Flags {
	return t.flags
}

func (t *ObjectType) Material() object.Material {
	return t.material
}

func (t *ObjectType) Allowed() bool {
	return t.allowed
}

func (t *ObjectType) SetAllowed(allow bool) {
	if allow {
		t.s.enableObject(t)
	} else {
		t.s.disableObject(t)
	}
}

func (t *ObjectType) String() string {
	return fmt.Sprintf("ObjectType(%d,%q)", t.Ind(), t.ID())
}

func (t *ObjectType) Health() *HealthData {
	return t.health
}

func (t *ObjectType) UpdateDataMonster() *MonsterUpdateData {
	if !t.Class().Has(object.ClassMonster) {
		panic(t.Class().String())
	}
	return (*MonsterUpdateData)(t.UpdateData)
}

func (t *ObjectType) parseCreate(d *things.ProcFunc) error {
	if d == nil {
		return nil
	}
	fnc, ok := createFuncs[d.Name]
	if !ok {
		return fmt.Errorf("unsupported create func: %q", d.Name)
	}
	t.Create = fnc
	return nil
}

func (t *ObjectType) parseInit(d *things.ProcFunc) error {
	if d == nil {
		return nil
	}
	def, ok := initFuncs[d.Name]
	if !ok {
		// TODO: add "unknown" init as a nop init types (similar to NoInit)
		return nil
	}
	t.Init = def.Func
	t.InitData = nil
	t.InitDataSize = def.DataSize
	if def.DataSize == 0 {
		return nil
	}
	data, _ := alloc.Malloc(def.DataSize)
	t.InitData = data
	if parse, ok := initParseFuncs[d.Name]; ok {
		if err := parse(t, d.Args); err != nil {
			return err
		}
	}
	return nil
}

func objectDirectionInitParse(objt *ObjectType, args []string) error {
	p := unsafe.Slice((*int32)(objt.InitData), 2)
	if len(args) != 2 {
		return errors.New("expected two values")
	}
	v1, err := strconv.Atoi(args[0])
	if err != nil {
		return err
	}
	v2, err := strconv.Atoi(args[1])
	if err != nil {
		return err
	}
	p[0] = int32(v1)
	p[1] = int32(v2)
	return nil
}

func (t *ObjectType) parseUpdate(d *things.ProcFunc) error {
	if d == nil {
		return nil
	}
	def, ok := updateFuncs[d.Name]
	if !ok {
		// TODO: add "unknown" updates as a nop update types (similar to NoUpdate)
		return nil
	}
	t.Update = def.Func
	t.UpdateData = nil
	t.UpdateDataSize = def.DataSize
	if def.DataSize == 0 {
		return nil
	}
	data, _ := alloc.Malloc(def.DataSize)
	t.UpdateData = data
	if parse, ok := updateParseFuncs[d.Name]; ok {
		if err := parse(t, d.Args); err != nil {
			return err
		}
	}
	return nil
}

func (t *ObjectType) parseCollide(d *things.ProcFunc) error {
	if d == nil {
		return nil
	}
	def, ok := collideFuncs[d.Name]
	if !ok {
		// TODO: add "unknown" collide as a nop types (similar to NoCollide)
		return nil
	}
	t.Collide = def.Func
	t.CollideData = nil
	t.CollideDataSize = def.DataSize
	if def.DataSize == 0 {
		return nil
	}
	data, _ := alloc.Malloc(def.DataSize)
	t.CollideData = data
	if parse, ok := collideParseFuncs[d.Name]; ok {
		if err := parse(t, d.Args); err != nil {
			return err
		}
	}
	return nil
}

func (t *ObjectType) parseUse(d *things.ProcFunc) error {
	if d == nil {
		return nil
	}
	def, ok := useFuncs[d.Name]
	if !ok {
		// TODO: add "unknown" use as a nop types
		return nil
	}
	t.Use = def.Func
	t.UseData = nil
	t.UseDataSize = def.DataSize
	if def.DataSize == 0 {
		return nil
	}
	data, _ := alloc.Malloc(def.DataSize)
	t.UseData = data
	if parse, ok := useParseFuncs[d.Name]; ok {
		if err := parse(t, d.Args); err != nil {
			return err
		}
	}
	return nil
}

func (t *ObjectType) parseDamage(d *things.ProcFunc) error {
	if d == nil {
		return nil
	}
	t.Damage = damageFuncs[d.Name]
	return nil
}

func (t *ObjectType) parseDamageSound(name string) error {
	if name == "" {
		return nil
	}
	t.DamageSound = damageSoundFuncs[name]
	return nil
}

func (t *ObjectType) parseDeath(d *things.ProcFunc) error {
	if d == nil {
		return nil
	}
	def, ok := deathFuncs[d.Name]
	if !ok {
		// TODO: add "unknown" death as a nop types
		return nil
	}
	t.Death = def.Func
	t.DeathData = nil
	if def.DataSize == 0 {
		return nil
	}
	data, _ := alloc.Malloc(def.DataSize)
	t.DeathData = data
	if parse, ok := deathParseFuncs[d.Name]; ok {
		if err := parse(t, d.Args); err != nil {
			return err
		}
	}
	return nil
}

func (t *ObjectType) parseDrop(d *things.ProcFunc) error {
	if d == nil {
		return nil
	}
	fnc, ok := dropFuncs[d.Name]
	if !ok {
		// TODO: add "unknown" drop as a nop types
		return nil
	}
	t.Drop = fnc
	if parse, ok := dropParseFuncs[d.Name]; ok {
		if err := parse(t, d.Args); err != nil {
			return err
		}
	}
	return nil
}

func (s *Server) DropSound(ind uint16) sound.ID {
	return s.Types.dropSoundTable[ind]
}

func (t *ObjectType) parsePickup(d *things.ProcFunc) error {
	if d == nil {
		return nil
	}
	fnc, ok := pickupFuncs[d.Name]
	if !ok {
		// TODO: add "unknown" pickup as a nop types
		return nil
	}
	t.Pickup = fnc
	if parse, ok := pickupParseFuncs[d.Name]; ok {
		if err := parse(t, d.Args); err != nil {
			return err
		}
	}
	return nil
}

func (s *Server) PickupSound(ind uint16) sound.ID {
	return s.Types.pickupSoundTable[ind]
}

func (t *ObjectType) parseXfer(d *things.ProcFunc) error {
	if d == nil {
		return nil
	}
	xfer := xferFuncs[d.Name]
	if xfer == nil {
		return fmt.Errorf("unsupported xfer: %q", d.Name)
	}
	t.Xfer = xfer
	return nil
}

type MonsterAnim struct {
	sound   uint32  // 0, 0
	data4   [4]byte // 1, 4
	field8  byte    // 2, 8
	frames  byte    // 2, 9
	field10 byte    // 2, 10
	field11 byte    // 2, 11
	loop    uint32  // 3, 12
}

func (t *ObjectType) parseDraw(d things.Draw) error {
	switch d := d.(type) {
	case things.MonsterDraw:
		ud := t.UpdateDataMonster()
		if ud == nil {
			return errors.New("no monster update data")
		}
		anims, _ := alloc.Make([]MonsterAnim{}, 16)
		ud.Field119 = (*[16]MonsterAnim)(anims)
		for _, st := range d.Anims {
			if int(st.Type) >= len(anims) {
				return errors.New("unexpected animation index")
			}
			ani := MonsterAnim{
				sound:   uint32(sound.ByName(st.Sound)),
				frames:  st.FramesPerDir,
				field10: st.Field10,
			}
			switch st.Kind {
			case things.AnimationLoop, things.AnimationLoopAndFade:
				ani.loop = 1
			}
			anims[st.Type] = ani
		}
	case things.PlayerDraw:
		for name, st := range d.Anims {
			ind := -1
			for i, s := range playerAnimTypes {
				if name == s {
					ind = i
					break
				}
			}
			if ind >= 0 {
				t.s.playerAnimFrames[ind] = [2]int{
					int(st.FramesPerDir),
					int(st.Field8),
				}
			}
		}
	}
	return nil
}

func (s *Server) PlayerAnimFrames(i int) (_, _ int) {
	if i < 0 || i >= len(s.Types.playerAnimFrames) {
		return 0, 0
	}
	v := s.Types.playerAnimFrames[i]
	return v[0], v[1]
}

var playerAnimTypes = []player.AnimType{
	player.AnimIdle,
	player.AnimDie,
	player.AnimDead,
	player.AnimJump,
	player.AnimWalk,
	player.AnimWalkAndDrag,
	player.AnimRun,
	player.AnimRunningJump,
	player.AnimPickup,
	player.AnimDodgeLeft,
	player.AnimDodgeRight,
	player.AnimElectrocuted,
	player.AnimFall,
	player.AnimTrip,
	player.AnimGetUp,
	player.AnimLaugh,
	player.AnimPoint,
	player.AnimSit,
	player.AnimSleep,
	player.AnimTalk,
	player.AnimTaunt,
	player.AnimCastSpell,
	player.AnimConcentrate,
	player.AnimPunchLeft,
	player.AnimPunchRight,
	player.AnimPunchRightHook,
	player.AnimMaceStrike,
	player.AnimSwordStrike,
	player.AnimLongSwordStrike,
	player.AnimStaffStrike,
	player.AnimStaffBlock,
	player.AnimStaffSpellBlast,
	player.AnimStaffThrust,
	player.AnimShootBow,
	player.AnimShootCrossbow,
	player.AnimAxeStrike,
	player.AnimGreatSwordParry,
	player.AnimGreatSwordStrike,
	player.AnimGreatSwordIdle,
	player.AnimHammerStrike,
	player.AnimRaiseShield,
	player.AnimRecoilForward,
	player.AnimRecoilBackward,
	player.AnimRecoilShield,
	player.AnimChakramStrike,
	player.AnimBerserkerCharge,
	player.AnimWarcry,
	player.AnimGreatSwordBlockLeft,
	player.AnimGreatSwordBlockRight,
	player.AnimGreatSwordBlockDown,
	player.AnimElectricZap,
	player.AnimDust,
	player.AnimRecoil,
	player.AnimSneak,
	player.AnimHarpoonThrow,
}

type debugObjectType struct {
	Ind          int                 `json:"ind"`
	ID           string              `json:"id"`
	Class        object.Class        `json:"class"`
	MonsterClass object.MonsterClass `json:"monster_class,omitempty"`
	ArmorClass   object.ArmorClass   `json:"armor_class,omitempty"`
	WeaponClass  object.WeaponClass  `json:"weapon_class,omitempty"`
	OtherClass   object.OtherClass   `json:"other_class,omitempty"`
}

func (t *ObjectType) dump() *debugObjectType {
	if t == nil {
		return nil
	}
	return &debugObjectType{
		Ind:          t.Ind(),
		ID:           t.ID(),
		Class:        t.Class(),
		MonsterClass: t.MonsterClass(),
		ArmorClass:   t.ArmorClass(),
		WeaponClass:  t.WeaponClass(),
		OtherClass:   t.OtherClass(),
	}
}

func (t *ObjectType) MarshalJSON() ([]byte, error) {
	return json.Marshal(t.dump())
}
