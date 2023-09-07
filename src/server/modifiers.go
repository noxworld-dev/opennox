package server

import (
	"fmt"
	"math"
	"strconv"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/datapath"
	"github.com/noxworld-dev/opennox-lib/modifiers"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/strman"

	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
)

type ModifierInitData struct {
	Modifiers [4]*ModifierEff // 0, 0
	Field16   uint32          // 4, 16
}

var (
	modDamageEffects = make(map[string]modFuncs[ccall.Func[ModifierDamageFunc]])
	modDefendEffects = make(map[string]modFuncs[ccall.Func[ModifierDefendFunc]])
	modUpdateEffects = make(map[string]modFuncs[ccall.Func[ModifierUpdateFunc]])
	modEngageEffects = make(map[string]modFuncs[ccall.Func[ModifierEngageFunc]])
)

func registerModifVoid[T any](m map[string]modFuncs[T], name string, fnc T) {
	if _, ok := m[name]; ok {
		panic("already registered")
	}
	m[name] = modFuncs[T]{Func: fnc}
}

func registerModifInt[T any](m map[string]modFuncs[T], name string, fnc T) {
	if _, ok := m[name]; ok {
		panic("already registered")
	}
	m[name] = modFuncs[T]{Func: fnc, ParseInt: modEffectParseInt}
}

func registerModifFloat[T any](m map[string]modFuncs[T], name string, fnc T) {
	if _, ok := m[name]; ok {
		panic("already registered")
	}
	m[name] = modFuncs[T]{Func: fnc, ParseFloat: ModEffectParseFloat}
}

type ModifierDamageFunc func(m *ModifierEff, a2p, a3p, a4p *Object, a5, a6 unsafe.Pointer)
type ModifierDefendFunc func(m *ModifierEff, a2p, a3p, a4p *Object, a5, a6 unsafe.Pointer)
type ModifierUpdateFunc func(a1 unsafe.Pointer, a2 *Object)
type ModifierEngageFunc func(m *ModifierEff, a2 *Object, a3 *Object)

func RegisterModifDamageEffectInt(name string, fnc ModifierDamageFunc) {
	registerModifInt(modDamageEffects, name, ccall.FuncPtr(fnc))
}

func RegisterModifDamageEffectFloat(name string, fnc ModifierDamageFunc) {
	registerModifFloat(modDamageEffects, name, ccall.FuncPtr(fnc))
}

func RegisterModifDefendEffectInt(name string, fnc ModifierDefendFunc) {
	registerModifInt(modDefendEffects, name, ccall.FuncPtr(fnc))
}

func RegisterModifDefendEffectFloat(name string, fnc ModifierDefendFunc) {
	registerModifFloat(modDefendEffects, name, ccall.FuncPtr(fnc))
}

func RegisterModifUpdateEffectInt(name string, fnc ModifierUpdateFunc) {
	registerModifInt(modUpdateEffects, name, ccall.FuncPtr(fnc))
}

func RegisterModifUpdateEffectFloat(name string, fnc ModifierUpdateFunc) {
	registerModifFloat(modUpdateEffects, name, ccall.FuncPtr(fnc))
}

func RegisterModifEngageEffectInt(name string, fnc ModifierEngageFunc) {
	registerModifInt(modEngageEffects, name, ccall.FuncPtr(fnc))
}

func RegisterModifEngageEffectFloat(name string, fnc ModifierEngageFunc) {
	registerModifFloat(modEngageEffects, name, ccall.FuncPtr(fnc))
}

func RegisterModifEngageEffectVoid(name string, fnc ModifierEngageFunc) {
	registerModifVoid(modEngageEffects, name, ccall.FuncPtr(fnc))
}

type serverModifiers struct {
	sm                  *strman.StringManager
	byte_5D4594_251584  [3]*ModifierEff // EFFECTIVENESS, MATERIAL, ENCHANTMENT
	byte_5D4594_251596  uint32
	Dword_5d4594_251600 *Modifier
	Dword_5d4594_251608 *Modifier
}

func (s *serverModifiers) init(sm *strman.StringManager) {
	s.sm = sm
}

type ModColor struct {
	R, G, B byte
}

type Modifier struct {
	Name0                *byte       // 0, 0
	Ind4                 uint32      // 1, 4
	Desc8                *uint16     // 2, 8
	colors12             [8]ModColor // 3, 12
	Effectiveness36      int32       // 9, 36
	Material40           int32       // 10, 40
	PriEnchant44         int32       // 11, 44
	SecEnchant48         int32       // 12, 48
	Durability52         uint32      // 13, 52
	Field56              uint32      // 14, 56
	ReqStrength60        uint16      // 15, 60
	Classes62            byte        // 15, 62
	Field63              byte        // 15, 63
	DamageCoeffOrArmor64 float32     // 16, 64
	Range68              float32     // 17, 68
	DamageMin72          uint16      // 18, 72
	Field74              uint16      // 18, 74
	DamageType76         uint32      // 19, 76
	Next80               *Modifier   // 20, 80
	Prev84               *Modifier   // 21, 84
}

func (p *Modifier) C() unsafe.Pointer {
	return unsafe.Pointer(p)
}

func (p *Modifier) Name() string {
	return alloc.GoString(p.Name0)
}

func (p *Modifier) Index() int {
	return int(p.Ind4)
}

func (p *Modifier) Desc() string {
	return alloc.GoString16(p.Desc8)
}

type ModifierEffFnc[T any] struct {
	Fnc  T       // 0, 0
	Valf float32 // 1, 4
	Val  int32   // 2, 8
}

type ModifierEff struct { // obj_412ae0_t
	Name0             *byte                                          // 0, 0
	Ind4              uint32                                         // 1, 4
	Desc8             *uint16                                        // 2, 8
	SecDesc12         *uint16                                        // 3, 12
	IdentDesc16       *uint16                                        // 4, 16
	Price20           int32                                          // 5, 20
	color24           ModColor                                       // 6, 24
	_                 byte                                           // 6, 27
	AllowWeapons28    uint32                                         // 7, 28
	AllowArmor32      uint32                                         // 8, 32
	AllowPos36        uint32                                         // 9, 36
	Attack40          ModifierEffFnc[ccall.Func[ModifierDamageFunc]] // 10, 40-44-48
	AttackPreHit52    ModifierEffFnc[ccall.Func[ModifierDamageFunc]] // 13, 52-56-60
	AttackPreDmg64    ModifierEffFnc[ccall.Func[ModifierDamageFunc]] // 16, 64-68-72
	Defend76          ModifierEffFnc[ccall.Func[ModifierDefendFunc]] // 19, 76-80-84
	DefendCollide88   ModifierEffFnc[ccall.Func[ModifierDefendFunc]] // 22, 88-92-96
	Update100         ModifierEffFnc[ccall.Func[ModifierUpdateFunc]] // 25, 100-104-108
	Engage112         ccall.Func[ModifierEngageFunc]                 // 28, 112
	Disengage116      ccall.Func[ModifierEngageFunc]                 // 29, 116
	EngageFloat120    float32                                        // 30, 120
	EngageInt124      int32                                          // 31, 124
	DisengageFloat128 float32                                        // 32, 128
	DisengageInt132   int32                                          // 33, 132
	Next136           *ModifierEff                                   // 34, 136
	Prev140           *ModifierEff                                   // 35, 140
}

func (p *ModifierEff) C() unsafe.Pointer {
	return unsafe.Pointer(p)
}

func (p *ModifierEff) Name() string {
	return alloc.GoString(p.Name0)
}

func (p *ModifierEff) Index() int {
	return int(p.Ind4)
}

func (p *ModifierEff) Desc() string {
	return alloc.GoString16(p.Desc8)
}

func modParseBitList(table []string, arr []string) (uint32, error) {
	val := uint32(0)
	for _, s := range arr {
		ind := -1
		s = strings.ToUpper(s)
		for i, t := range table {
			if strings.ToUpper(t) == s {
				ind = i
				break
			}
		}
		if ind < 0 {
			return val, fmt.Errorf("unsupported list item: %q", s)
		}
		val |= 1 << ind
	}
	return val, nil
}

func modParseAllowed(table map[string]uint32, l modifiers.AllowList) (uint32, error) {
	if l.Base == "" && len(l.Terms) == 0 {
		return 0, nil
	}
	val, ok := table[strings.ToUpper(l.Base)]
	if !ok {
		return 0, fmt.Errorf("unsupported allow list: %q", l.Base)
	}
	for _, t := range l.Terms {
		v, ok := table[strings.ToUpper(t.Val)]
		if !ok {
			return val, fmt.Errorf("unsupported allow list: %q", t.Val)
		}
		if t.Add {
			val |= v
		} else {
			val &^= v
		}
	}
	return val, nil
}

func (s *serverModifiers) nox_xxx_parseWeaponOrArmorDef412D40(head **Modifier, arr []modifiers.WeaponOrArmor) error {
	for _, w := range arr {
		p, _ := alloc.New(Modifier{})
		p.Prev84 = nil
		p.Next80 = *head
		if *head != nil {
			(*head).Prev84 = p
		}
		*head = p
		p.Name0, _ = alloc.CString(w.Name)
		if w.Desc != "" {
			p.Desc8, _ = alloc.CString16(s.sm.GetStringInFile(strman.ID(w.Desc), "Modifier.c"))
		}
		for i := range p.colors12 {
			p.colors12[i] = ModColor{R: 0xff, G: 0xff, B: 0xff}
		}
		for i, c := range w.Colors {
			cl := c.Color
			p.colors12[i+1] = ModColor{R: byte(cl.R), G: byte(cl.G), B: byte(cl.B)}
		}
		if w.Effectiveness >= 0 {
			p.Effectiveness36 = int32(w.Effectiveness) + 1
		} else {
			p.Effectiveness36 = -1
		}
		if w.Material >= 0 {
			p.Material40 = int32(w.Material) + 1
		} else {
			p.Material40 = -1
		}
		if w.PriEnchant >= 0 {
			p.PriEnchant44 = int32(w.PriEnchant) + 1
		} else {
			p.PriEnchant44 = -1
		}
		if w.SecondEnchant >= 0 {
			p.SecEnchant48 = int32(w.SecondEnchant) + 1
		} else {
			p.SecEnchant48 = -1
		}
		var err error
		cl, err := modParseBitList([]string{"Warrior", "Wizard", "Conjurer"}, w.Class)
		if err != nil {
			return err
		}
		p.Classes62 = byte(cl)
		p.Durability52 = uint32(w.Durability)
		p.ReqStrength60 = uint16(w.ReqStrength)
		p.DamageMin72 = uint16(w.DamageMin)
		d, _ := object.ParseDamageType(w.DamageType)
		p.DamageType76 = uint32(d)
		p.Range68 = float32(w.Range)
		if w.DamageCoeff != 0 {
			p.DamageCoeffOrArmor64 = float32(w.DamageCoeff)
		} else {
			p.DamageCoeffOrArmor64 = float32(w.Armor)
		}
	}
	return nil
}

func (s *serverModifiers) nox_xxx_parseModifDesc_412AE0(typ int, arr []modifiers.Effect) error {
	for _, v := range arr {
		p, _ := alloc.New(ModifierEff{})
		p.Ind4 = s.byte_5D4594_251596
		s.byte_5D4594_251596++

		p.Prev140 = nil
		p.Next136 = s.byte_5D4594_251584[typ]
		if s.byte_5D4594_251584[typ] != nil {
			s.byte_5D4594_251584[typ].Prev140 = p
		}
		s.byte_5D4594_251584[typ] = p

		p.Name0, _ = alloc.CString(v.Name)
		if v.Desc != "" {
			p.Desc8, _ = alloc.CString16(s.sm.GetStringInFile(strman.ID(v.Desc), "Modifier.c"))
		} else if v.PriDesc != "" {
			p.Desc8, _ = alloc.CString16(s.sm.GetStringInFile(strman.ID(v.PriDesc), "Modifier.c"))
		}
		if v.SecondDesc != "" {
			p.SecDesc12, _ = alloc.CString16(s.sm.GetStringInFile(strman.ID(v.SecondDesc), "Modifier.c"))
		}
		if v.IdentifyDesc != "" {
			p.IdentDesc16, _ = alloc.CString16(s.sm.GetStringInFile(strman.ID(v.IdentifyDesc), "Modifier.c"))
		}
		p.Price20 = int32(v.Price)
		p.color24 = ModColor{R: byte(v.Color.R), G: byte(v.Color.G), B: byte(v.Color.B)}
		for _, d := range []struct {
			dst *ModifierEffFnc[ccall.Func[ModifierDamageFunc]]
			src string
		}{
			{&p.Attack40, v.Attack},
			{&p.AttackPreHit52, v.AttackPreHit},
			{&p.AttackPreDmg64, v.AttackPreDamage},
		} {
			if err := modParseEffect("damage", modDamageEffects, p, &d.dst.Fnc, &d.dst.Val, &d.dst.Valf, d.src); err != nil {
				return err
			}
		}
		for _, d := range []struct {
			dst *ModifierEffFnc[ccall.Func[ModifierDefendFunc]]
			src string
		}{
			{&p.Defend76, v.Defend},
			{&p.DefendCollide88, v.DefendCollide},
		} {
			if err := modParseEffect("defend", modDefendEffects, p, &d.dst.Fnc, &d.dst.Val, &d.dst.Valf, d.src); err != nil {
				return err
			}
		}
		if err := modParseEffect("update", modUpdateEffects, p, &p.Update100.Fnc, &p.Update100.Val, &p.Update100.Valf, v.Update); err != nil {
			return err
		}
		for _, d := range []struct {
			fnc  *ccall.Func[ModifierEngageFunc]
			fval *float32
			ival *int32
			src  string
		}{
			{&p.Engage112, &p.EngageFloat120, &p.EngageInt124, v.Engage},
			{&p.Disengage116, &p.DisengageFloat128, &p.DisengageInt132, v.Disengage},
		} {
			if err := modParseEffect("engage", modEngageEffects, p, d.fnc, d.ival, d.fval, d.src); err != nil {
				return err
			}
		}
		var err error
		p.AllowWeapons28, err = modParseAllowed(modAllowList, v.AllowWeapons)
		if err != nil {
			return err
		}
		p.AllowArmor32, err = modParseAllowed(modAllowList, v.AllowArmor)
		if err != nil {
			return err
		}
		p.AllowPos36, err = modParseBitList([]string{"PRIMARY", "SECONDARY"}, v.AllowPos)
		if err != nil {
			return err
		}
	}
	return nil
}

func (s *serverModifiers) Nox_xxx_parseModifierBin_412930(fname string) error {
	s.byte_5D4594_251584[0] = nil
	s.byte_5D4594_251584[1] = nil
	s.byte_5D4594_251584[2] = nil
	s.byte_5D4594_251596 = 0
	s.Dword_5d4594_251600 = nil
	s.Dword_5d4594_251608 = nil
	f, err := modifiers.ReadFile(datapath.Data(fname))
	if err != nil {
		return err
	}
	if err := s.nox_xxx_parseWeaponOrArmorDef412D40(&s.Dword_5d4594_251600, f.Weapons); err != nil {
		return err
	}
	if err := s.nox_xxx_parseWeaponOrArmorDef412D40(&s.Dword_5d4594_251608, f.Armor); err != nil {
		return err
	}
	if err := s.nox_xxx_parseModifDesc_412AE0(0, f.Effectiveness); err != nil {
		return err
	}
	if err := s.nox_xxx_parseModifDesc_412AE0(1, f.Materials); err != nil {
		return err
	}
	if err := s.nox_xxx_parseModifDesc_412AE0(2, f.Enchants); err != nil {
		return err
	}
	cnt := 0
	for k := 0; k < 3; k++ {
		for l := s.byte_5D4594_251584[k]; l != nil; l = l.Next136 {
			cnt++
		}
	}
	return nil
}

func (s *serverModifiers) Nox_xxx_modifGetModifListByType_4133B0(a1 int) unsafe.Pointer {
	return s.byte_5D4594_251584[a1].C()
}

func (s *serverModifiers) Nox_xxx_modifGetDescById413330(a1 int32) *ModifierEff {
	if a1 == math.MaxUint8 {
		return nil
	}
	for _, head := range s.byte_5D4594_251584 {
		for it := head; it != nil; it = it.Next136 {
			if it.Ind4 == uint32(a1) {
				return it
			}
		}
	}
	return nil
}

func (s *serverModifiers) Nox_xxx_modifGetIdByName413290(name string) int32 {
	if name == "" {
		return math.MaxUint8
	}
	for _, head := range s.byte_5D4594_251584 {
		for it := head; it != nil; it = it.Next136 {
			if alloc.GoString(it.Name0) == name {
				return int32(it.Ind4)
			}
		}
	}
	return math.MaxUint8
}

func (s *serverModifiers) Nox_xxx_getProjectileClassById413250(a1 int32) *Modifier {
	for it := s.Dword_5d4594_251600; it != nil; it = it.Next80 {
		if it.Ind4 == uint32(a1) {
			return it
		}
	}
	return nil
}

func (s *serverModifiers) Nox_xxx_equipClothFindDefByTT413270(a1 int32) *Modifier {
	for it := s.Dword_5d4594_251608; it != nil; it = it.Next80 {
		if it.Ind4 == uint32(a1) {
			return it
		}
	}
	return nil
}

func sub_4130C0(head *Modifier) {
	var next *Modifier
	for it := head; it != nil; it = next {
		next = it.Next80
		if it.Name0 != nil {
			alloc.Free(it.Name0)
			it.Name0 = nil
		}
		if it.Desc8 != nil {
			alloc.Free(it.Desc8)
			it.Desc8 = nil
		}
		alloc.Free(it)
	}
}

func sub_413100(head *Modifier) {
	var next *Modifier
	for it := head; it != nil; it = next {
		next = it.Next80
		if it.Name0 != nil {
			alloc.Free(it.Name0)
			it.Name0 = nil
		}
		if it.Desc8 != nil {
			alloc.Free(it.Desc8)
			it.Desc8 = nil
		}
		alloc.Free(it)
	}
}

func nox_xxx_modifFreeOne_413140(head *ModifierEff) {
	var next *ModifierEff
	for it := head; it != nil; it = next {
		next = it.Next136
		if it.Name0 != nil {
			alloc.Free(it.Name0)
			it.Name0 = nil
		}
		if it.Desc8 != nil {
			alloc.Free(it.Desc8)
			it.Desc8 = nil
		}
		if it.SecDesc12 != nil {
			alloc.Free(it.SecDesc12)
			it.SecDesc12 = nil
		}
		alloc.Free(it)
	}
}

func (s *serverModifiers) Nox_xxx_freeWeaponArmorDefAndModifs_413060() {
	sub_4130C0(s.Dword_5d4594_251600)
	s.Dword_5d4594_251600 = nil
	sub_413100(s.Dword_5d4594_251608)
	s.Dword_5d4594_251608 = nil
	for i := int32(0); i < 3; i++ {
		nox_xxx_modifFreeOne_413140(s.byte_5D4594_251584[i])
		s.byte_5D4594_251584[i] = nil
	}
	s.byte_5D4594_251596 = 0
}

func modParseEffect[T any](text string, table map[string]modFuncs[T], mod *ModifierEff, pfnc *T, pint *int32, pflt *float32, v string) error {
	if v == "" {
		return nil
	}
	name, args := v, ""
	if i := strings.IndexByte(v, ' '); i >= 0 {
		name = v[:i]
		args = strings.TrimSpace(v[i+1:])
	}
	e, ok := table[name]
	if !ok {
		return fmt.Errorf("unsupported %s effect: %q", text, v)
	}
	*pfnc = e.Func
	if e.ParseInt != nil {
		if !e.ParseInt(mod, pint, args) {
			return fmt.Errorf("cannot parse %s effect: %q", text, v)
		}
	} else if e.ParseFloat != nil {
		if !e.ParseFloat(mod, pflt, args) {
			return fmt.Errorf("cannot parse %s effect: %q", text, v)
		}
	}
	return nil
}

type modFuncs[T any] struct {
	Func       T
	ParseInt   func(mod *ModifierEff, p *int32, v string) bool
	ParseFloat func(mod *ModifierEff, p *float32, v string) bool
}

func modEffectParseInt(_ *ModifierEff, p *int32, s string) bool {
	v, err := strconv.ParseInt(firstWord(s), 10, 32)
	if err != nil {
		*p = -1
	} else {
		*p = int32(v)
	}
	return true
}

func ModEffectParseFloat(_ *ModifierEff, p *float32, s string) bool {
	v, err := strconv.ParseFloat(firstWord(s), 32)
	if err != nil {
		*p = -1
	} else {
		*p = float32(v)
	}
	return true
}

var modAllowList = map[string]uint32{
	"NO_ARMOR":                 0,
	"ALL_ARMOR":                0x3ffffff,
	"ALL_CLOTH_ARMOR":          0x4c0f,
	"ALL_LEATHER_ARMOR":        0x2090d0,
	"ALL_TORSO_ARMOR":          0x3cc02,
	"ALL_HELM_ARMOR":           0xfc0000,
	"ALL_ARM_ARMOR":            0x3000,
	"ALL_FEET_ARMOR":           0x1c1,
	"ALL_LEG_ARMOR":            0x23c,
	"ALL_HAND_ARMOR":           0x3000000,
	"STREET_PANTS":             0x4,
	"MEDIEVAL_PANTS":           0x8,
	"STREET_SNEAKERS":          0x1,
	"LEATHER_BOOTS":            0x40,
	"LEATHER_ARMORED_BOOTS":    0x80,
	"PLATE_BOOTS":              0x100,
	"LEATHER_LEGGINGS":         0x10,
	"CHAIN_LEGGINGS":           0x20,
	"PLATE_LEGGINGS":           0x200,
	"STREET_SHIRT":             0x400,
	"MEDIEVAL_SHIRT":           0x800,
	"WIZARD_ROBE":              0x4000,
	"LEATHER_TUNIC":            0x8000,
	"CHAIN_TUNIC":              0x10000,
	"PLATE_BREAST":             0x20000,
	"LEATHER_ARMBANDS":         0x1000,
	"PLATE_ARMS":               0x2000,
	"MEDIEVAL_CLOAK":           0x2,
	"ROUND_SHIELD":             0x1000000,
	"KITE_SHIELD":              0x2000000,
	"CHAIN_COIF":               0x40000,
	"WIZARD_HELM":              0x80000,
	"CONJURER_HELM":            0x100000,
	"LEATHER_HELM":             0x200000,
	"PLATE_HELM":               0x400000,
	"ORNATE_HELM":              0x800000,
	"NO_WEAPONS":               0,
	"ALL_WEAPONS":              0x7fffffe,
	"ALL_MAGICAL_STAVES":       0x47f0000,
	"ALL_STAVES":               0x7ff8000,
	"ALL_RANGED_WEAPONS":       0x47f00fe,
	"FLAG":                     0x1,
	"QUIVER":                   0x2,
	"BOW":                      0x4,
	"CROSSBOW":                 0x8,
	"ARROW":                    0x10,
	"BOLT":                     0x20,
	"CHAKRAM":                  0x40,
	"SHURIKEN":                 0x80,
	"SWORD":                    0x100,
	"LONG_SWORD":               0x200,
	"GREAT_SWORD":              0x400,
	"MACE":                     0x800,
	"AXE":                      0x1000,
	"OGRE_AXE":                 0x2000,
	"HAMMER":                   0x4000,
	"STAFF":                    0x8000,
	"STAFF_SULPHOROUS_FLARE":   0x10000,
	"STAFF_SULPHOROUS_SHOWER":  0x20000,
	"STAFF_LIGHTNING":          0x40000,
	"STAFF_FIREBALL":           0x80000,
	"STAFF_TRIPLE_FIREBALL":    0x100000,
	"STAFF_FORCE_OF_NATURE":    0x200000,
	"STAFF_DEATH_RAY":          0x400000,
	"STAFF_OBLIVION_HALBERD":   0x800000,
	"STAFF_OBLIVION_HEART":     0x1000000,
	"STAFF_OBLIVION_WIERDLING": 0x2000000,
	"STAFF_OBLIVION_ORB":       0x4000000,
}
