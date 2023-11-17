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

	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

var (
	modDamageEffects = make(map[string]modFuncs)
	modDefendEffects = make(map[string]modFuncs)
	modUpdateEffects = make(map[string]modFuncs)
	modEngageEffects = make(map[string]modFuncs)
)

func registerModif(m map[string]modFuncs, name string, fnc unsafe.Pointer, parse ModifierParseFunc) {
	if _, ok := m[name]; ok {
		panic("already registered")
	}
	m[name] = modFuncs{Func: fnc, Parse: parse}
}

func RegisterModifDamageEffect(name string, fnc unsafe.Pointer, parse ModifierParseFunc) {
	registerModif(modDamageEffects, name, fnc, parse)
}

func RegisterModifDefendEffect(name string, fnc unsafe.Pointer, parse ModifierParseFunc) {
	registerModif(modDefendEffects, name, fnc, parse)
}

func RegisterModifUpdateEffect(name string, fnc unsafe.Pointer, parse ModifierParseFunc) {
	registerModif(modUpdateEffects, name, fnc, parse)
}

func RegisterModifEngageEffect(name string, fnc unsafe.Pointer, parse ModifierParseFunc) {
	registerModif(modEngageEffects, name, fnc, parse)
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
	name0                *byte       // 0, 0
	Ind4                 uint32      // 1, 4
	desc8                *uint16     // 2, 8
	colors12             [8]ModColor // 3, 12
	effectiveness36      int32       // 9, 36
	material40           int32       // 10, 40
	prienchant44         int32       // 11, 44
	secenchant48         int32       // 12, 48
	durability52         uint32      // 13, 52
	field56              uint32      // 14, 56
	reqstrength60        uint16      // 15, 60
	Classes62            byte        // 15, 62
	field63              byte        // 15, 63
	damageCoeffOrArmor64 float32     // 16, 64
	range68              float32     // 17, 68
	damageMin72          uint16      // 18, 72
	field74              uint16      // 18, 74
	damageType76         uint32      // 19, 76
	Next80               *Modifier   // 20, 80
	Prev84               *Modifier   // 21, 84
}

func (p *Modifier) C() unsafe.Pointer {
	return unsafe.Pointer(p)
}

func (p *Modifier) Name() string {
	return alloc.GoString(p.name0)
}

func (p *Modifier) Index() int {
	return int(p.Ind4)
}

func (p *Modifier) Desc() string {
	return alloc.GoString16(p.desc8)
}

type ModifierEffFnc struct {
	fnc  unsafe.Pointer
	valf float32
	val  int32
}

type ModifierEff struct { // obj_412ae0_t
	name0             *byte          // 0, 0
	ind4              uint32         // 1, 4
	desc8             *uint16        // 2, 8
	secdesc12         *uint16        // 3, 12
	identdesc16       *uint16        // 4, 16
	price20           int32          // 5, 20
	color24           ModColor       // 6, 24
	_                 byte           // 6, 27
	allowWeapons28    uint32         // 7, 28
	allowArmor32      uint32         // 8, 32
	allowPos36        uint32         // 9, 36
	attack40          ModifierEffFnc // 10, 40
	attackPreHit52    ModifierEffFnc // 13, 52
	attackPreDmg64    ModifierEffFnc // 16, 64
	defend76          ModifierEffFnc // 19, 76
	defendCollide88   ModifierEffFnc // 22, 88
	update100         ModifierEffFnc // 25, 100
	engage112         unsafe.Pointer // 28, 112
	disengage116      unsafe.Pointer // 29, 116
	engageFloat120    float32        // 30, 120
	engageInt124      int32          // 31, 124
	disengageFloat128 float32        // 32, 128
	disengageInt132   int32          // 33, 132
	next136           *ModifierEff   // 34, 136
	prev140           *ModifierEff   // 35, 140
}

func (p *ModifierEff) C() unsafe.Pointer {
	return unsafe.Pointer(p)
}

func (p *ModifierEff) Name() string {
	return alloc.GoString(p.name0)
}

func (p *ModifierEff) Index() int {
	return int(p.ind4)
}

func (p *ModifierEff) Desc() string {
	return alloc.GoString16(p.desc8)
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
		p.name0, _ = alloc.CString(w.Name)
		if w.Desc != "" {
			p.desc8, _ = alloc.CString16(s.sm.GetStringInFile(strman.ID(w.Desc), "Modifier.c"))
		}
		for i := range p.colors12 {
			p.colors12[i] = ModColor{R: 0xff, G: 0xff, B: 0xff}
		}
		for i, c := range w.Colors {
			cl := c.Color
			p.colors12[i+1] = ModColor{R: byte(cl.R), G: byte(cl.G), B: byte(cl.B)}
		}
		if w.Effectiveness >= 0 {
			p.effectiveness36 = int32(w.Effectiveness) + 1
		} else {
			p.effectiveness36 = -1
		}
		if w.Material >= 0 {
			p.material40 = int32(w.Material) + 1
		} else {
			p.material40 = -1
		}
		if w.PriEnchant >= 0 {
			p.prienchant44 = int32(w.PriEnchant) + 1
		} else {
			p.prienchant44 = -1
		}
		if w.SecondEnchant >= 0 {
			p.secenchant48 = int32(w.SecondEnchant) + 1
		} else {
			p.secenchant48 = -1
		}
		var err error
		cl, err := modParseBitList([]string{"Warrior", "Wizard", "Conjurer"}, w.Class)
		if err != nil {
			return err
		}
		p.Classes62 = byte(cl)
		p.durability52 = uint32(w.Durability)
		p.reqstrength60 = uint16(w.ReqStrength)
		p.damageMin72 = uint16(w.DamageMin)
		d, _ := object.ParseDamageType(w.DamageType)
		p.damageType76 = uint32(d)
		p.range68 = float32(w.Range)
		if w.DamageCoeff != 0 {
			p.damageCoeffOrArmor64 = float32(w.DamageCoeff)
		} else {
			p.damageCoeffOrArmor64 = float32(w.Armor)
		}
	}
	return nil
}

func (s *serverModifiers) nox_xxx_parseModifDesc_412AE0(typ int, arr []modifiers.Effect) error {
	for _, v := range arr {
		p, _ := alloc.New(ModifierEff{})
		p.ind4 = s.byte_5D4594_251596
		s.byte_5D4594_251596++

		p.prev140 = nil
		p.next136 = s.byte_5D4594_251584[typ]
		if s.byte_5D4594_251584[typ] != nil {
			s.byte_5D4594_251584[typ].prev140 = p
		}
		s.byte_5D4594_251584[typ] = p

		p.name0, _ = alloc.CString(v.Name)
		if v.Desc != "" {
			p.desc8, _ = alloc.CString16(s.sm.GetStringInFile(strman.ID(v.Desc), "Modifier.c"))
		} else if v.PriDesc != "" {
			p.desc8, _ = alloc.CString16(s.sm.GetStringInFile(strman.ID(v.PriDesc), "Modifier.c"))
		}
		if v.SecondDesc != "" {
			p.secdesc12, _ = alloc.CString16(s.sm.GetStringInFile(strman.ID(v.SecondDesc), "Modifier.c"))
		}
		if v.IdentifyDesc != "" {
			p.identdesc16, _ = alloc.CString16(s.sm.GetStringInFile(strman.ID(v.IdentifyDesc), "Modifier.c"))
		}
		p.price20 = int32(v.Price)
		p.color24 = ModColor{R: byte(v.Color.R), G: byte(v.Color.G), B: byte(v.Color.B)}
		for _, d := range []struct {
			text  string
			table map[string]modFuncs
			fnc   *unsafe.Pointer
			fval  *float32
			ival  *int32
			src   string
		}{
			{"damage", modDamageEffects, &p.attack40.fnc, &p.attack40.valf, &p.attack40.val, v.Attack},
			{"damage", modDamageEffects, &p.attackPreHit52.fnc, &p.attackPreHit52.valf, &p.attackPreHit52.val, v.AttackPreHit},
			{"damage", modDamageEffects, &p.attackPreDmg64.fnc, &p.attackPreDmg64.valf, &p.attackPreDmg64.val, v.AttackPreDamage},
			{"defend", modDefendEffects, &p.defend76.fnc, &p.defend76.valf, &p.defend76.val, v.Defend},
			{"defend", modDefendEffects, &p.defendCollide88.fnc, &p.defendCollide88.valf, &p.defendCollide88.val, v.DefendCollide},
			{"update", modUpdateEffects, &p.update100.fnc, &p.update100.valf, &p.update100.val, v.Update},
			{"engage", modEngageEffects, &p.engage112, &p.engageFloat120, &p.engageInt124, v.Engage},
			{"engage", modEngageEffects, &p.disengage116, &p.disengageFloat128, &p.disengageInt132, v.Disengage},
		} {
			if err := modParseEffect(d.text, d.table, p, ModParseTarg{d.fnc, d.fval, d.ival}, d.src); err != nil {
				return err
			}
		}
		var err error
		p.allowWeapons28, err = modParseAllowed(modAllowList, v.AllowWeapons)
		if err != nil {
			return err
		}
		p.allowArmor32, err = modParseAllowed(modAllowList, v.AllowArmor)
		if err != nil {
			return err
		}
		p.allowPos36, err = modParseBitList([]string{"PRIMARY", "SECONDARY"}, v.AllowPos)
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
		for l := s.byte_5D4594_251584[k]; l != nil; l = l.next136 {
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
		for it := head; it != nil; it = it.next136 {
			if it.ind4 == uint32(a1) {
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
		for it := head; it != nil; it = it.next136 {
			if alloc.GoString(it.name0) == name {
				return int32(it.ind4)
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
		if it.name0 != nil {
			alloc.Free(it.name0)
			it.name0 = nil
		}
		if it.desc8 != nil {
			alloc.Free(it.desc8)
			it.desc8 = nil
		}
		alloc.Free(it)
	}
}

func sub_413100(head *Modifier) {
	var next *Modifier
	for it := head; it != nil; it = next {
		next = it.Next80
		if it.name0 != nil {
			alloc.Free(it.name0)
			it.name0 = nil
		}
		if it.desc8 != nil {
			alloc.Free(it.desc8)
			it.desc8 = nil
		}
		alloc.Free(it)
	}
}

func nox_xxx_modifFreeOne_413140(head *ModifierEff) {
	var next *ModifierEff
	for it := head; it != nil; it = next {
		next = it.next136
		if it.name0 != nil {
			alloc.Free(it.name0)
			it.name0 = nil
		}
		if it.desc8 != nil {
			alloc.Free(it.desc8)
			it.desc8 = nil
		}
		if it.secdesc12 != nil {
			alloc.Free(it.secdesc12)
			it.secdesc12 = nil
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

type ModParseTarg struct {
	Func  *unsafe.Pointer
	Float *float32
	Int   *int32
}

func modParseEffect(text string, table map[string]modFuncs, mod *ModifierEff, p ModParseTarg, v string) error {
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
	*p.Func = e.Func
	if e.Parse != nil && !e.Parse(mod, p, args) {
		return fmt.Errorf("cannot parse %s effect: %q", text, v)
	}
	return nil
}

type modFuncs struct {
	Func  unsafe.Pointer
	Parse func(mod *ModifierEff, p ModParseTarg, v string) bool
}

type ModifierParseFunc func(mod *ModifierEff, p ModParseTarg, v string) bool

func ModEffectParseInt(_ *ModifierEff, p ModParseTarg, s string) bool {
	v, err := strconv.ParseInt(firstWord(s), 10, 32)
	if err != nil {
		*p.Int = -1
	} else {
		*p.Int = int32(v)
	}
	return true
}

func ModEffectParseFloat(_ *ModifierEff, p ModParseTarg, s string) bool {
	v, err := strconv.ParseFloat(firstWord(s), 32)
	if err != nil {
		*p.Float = -1
	} else {
		*p.Float = float32(v)
	}
	return true
}

func (s *Server) Nox_xxx_fireEffect_4E0550(a1 unsafe.Pointer, a2, src, targ *Object) {
	v5 := *(*float32)(unsafe.Add(a1, 56))
	if targ != nil {
		targ.CallDamage(src, a2, int(v5), object.DamageExplosion)
		s.Nox_xxx_netSparkExplosionFx_5231B0(targ.PosVec, byte(int8(int64(float64(v5)*10.0))))
		s.Audio.EventObj(sound.SoundWeaponEffectFire, targ, 0, 0)
	}
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
