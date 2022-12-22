package opennox

/*
#include <stdint.h>

extern void* dword_5d4594_1308156;
extern void* dword_5d4594_1308160;
extern void* dword_5d4594_1308164;

void nullsub_22();
void nullsub_36();
void nullsub_38();
void nullsub_39();
void nullsub_40();
void nullsub_41();
void nullsub_42();
void nullsub_43();
void nullsub_44();

void sub_4DFE10(int a1, int a2);
float* sub_4E0370(int a1, int a2, int a3, int a4, int a5, float* a6);
float* sub_4E0380(int a1, int a2, int a3, int a4, int a5, float* a6);
float* nox_xxx_effectDamageMultiplier_4E04C0(int a1, int a2, int a3, int a4, float* a5);
void nox_xxx_attribContinualReplen_4E02C0(int a1, uint32_t* a2);
void nox_xxx_confuseEffect_4E0670(int a1, int a2, int a3, int a4);
int nox_xxx_blueFREffect_4E05F0(int a1, int a2, int a3);
void nox_xxx_drainMEffect_4E0740(int a1, int a2, int a3, int a4, int* a5);
void nox_xxx_sympathyEffect_4E08E0(int a1, int a2, int a3, int a4, int* a5);
int nox_xxx_effectProjectileSpeed_4E09B0(int a1, int a2, int a3, int a4, int a5);
void nox_xxx_buff_4DFD80(int a1, int a2);
void nox_xxx_checkPoisonProtectEnch_4DFDE0(int a1, int a2);
int nox_xxx_gripEffect_4E0480(int a1, int a2, int a3, int a4, int a5, int* a6);
void nox_xxx_effectRegeneration_4E01D0(int a1, int a2);
void nox_xxx_stunEffect_4E04D0(int a1, int a2, int a3, int a4);
void nox_xxx_fireEffect_4E0550(int a1, int a2, int a3, int a4);
int nox_xxx_fireRingEffect_4E05B0(int a1, int a2, int a3);
void nox_xxx_recoilEffect_4E0640(int a1, int a2, int a3, int a4);
void nox_xxx_lightngEffect_4E06F0(int a1, int a2, int a3, int a4);
void nox_xxx_vampirismEffect_4E07C0(int a1, int a2, int a3, int a4, int* a5);
void nox_xxx_poisonEffect_4E0850(int a1, int a2, int a3, int a4);
int nox_xxx_inversionEffect_4E03D0(int a1, int a2, int a3, int a4, int a5, int* a6);
void sub_4DFB50(int a1, int a2);
void sub_4DFB80(int a1, int a2);
void nox_xxx_effectSpeedEngage_4DFC30(int a1, int a2);
void nox_xxx_effectSpeedDisengage_4DFCA0(int a1, int a2);
void sub_4DFD10(int a1, int a2);
void nox_xxx_modifFireProtection_4DFD40(int a1, int a2, int a3);
void sub_4DFDB0(int a1, int a2);
void sub_4E0140(int a1, int a2);
void sub_4E0170(int a1, int a2);
*/
import "C"
import (
	"fmt"
	"math"
	"strconv"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/datapath"
	"github.com/noxworld-dev/opennox-lib/log"
	"github.com/noxworld-dev/opennox-lib/modifiers"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/strman"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

var (
	modLog              = log.New("modifiers")
	byte_5D4594_251584  [3]*noxModifierEff // EFFECTIVENESS, MATERIAL, ENCHANTMENT
	dword_5d4594_251600 *noxModifier
	dword_5d4594_251608 *noxModifier
	byte_5D4594_251596  uint32
)

func nox_xxx_parseModifierBin_412930(fname string) error {
	byte_5D4594_251584[0] = nil
	byte_5D4594_251584[1] = nil
	byte_5D4594_251584[2] = nil
	byte_5D4594_251596 = 0
	dword_5d4594_251600 = nil
	dword_5d4594_251608 = nil
	f, err := modifiers.ReadFile(datapath.Data(fname))
	if err != nil {
		return err
	}
	if err := nox_xxx_parseWeaponOrArmorDef412D40(&dword_5d4594_251600, f.Weapons); err != nil {
		return err
	}
	if err := nox_xxx_parseWeaponOrArmorDef412D40(&dword_5d4594_251608, f.Armor); err != nil {
		return err
	}
	if err := nox_xxx_parseModifDesc_412AE0(0, f.Effectiveness); err != nil {
		return err
	}
	if err := nox_xxx_parseModifDesc_412AE0(1, f.Materials); err != nil {
		return err
	}
	if err := nox_xxx_parseModifDesc_412AE0(2, f.Enchants); err != nil {
		return err
	}
	cnt := 0
	for k := 0; k < 3; k++ {
		for l := byte_5D4594_251584[k]; l != nil; l = l.next136 {
			cnt++
		}
	}
	return nil
}

func nox_xxx_freeWeaponArmorDefAndModifs_413060() {
	sub_4130C0(dword_5d4594_251600)
	dword_5d4594_251600 = nil
	sub_413100(dword_5d4594_251608)
	dword_5d4594_251608 = nil
	for i := int32(0); i < 3; i++ {
		nox_xxx_modifFreeOne_413140(byte_5D4594_251584[i])
		byte_5D4594_251584[i] = nil
	}
	byte_5D4594_251596 = 0
}

func sub_4130C0(head *noxModifier) {
	var next *noxModifier
	for it := head; it != nil; it = next {
		next = it.next80
		if it.name0 != nil {
			StrFree(it.name0)
			it.name0 = nil
		}
		if it.desc8 != nil {
			StrFree(it.desc8)
			it.desc8 = nil
		}
		alloc.Free(unsafe.Pointer(it))
	}
}

func sub_413100(head *noxModifier) {
	var next *noxModifier
	for it := head; it != nil; it = next {
		next = it.next80
		if it.name0 != nil {
			StrFree(it.name0)
			it.name0 = nil
		}
		if it.desc8 != nil {
			StrFree(it.desc8)
			it.desc8 = nil
		}
		alloc.Free(unsafe.Pointer(it))
	}
}

func nox_xxx_modifFreeOne_413140(head *noxModifierEff) {
	var next *noxModifierEff
	for it := head; it != nil; it = next {
		next = it.next136
		if it.name0 != nil {
			StrFree(it.name0)
			it.name0 = nil
		}
		if it.desc8 != nil {
			StrFree(it.desc8)
			it.desc8 = nil
		}
		if it.secdesc12 != nil {
			StrFree(it.secdesc12)
			it.secdesc12 = nil
		}
		alloc.Free(unsafe.Pointer(it))
	}
}

//export nox_xxx_modifGetModifListByType_4133B0
func nox_xxx_modifGetModifListByType_4133B0(a1 int) unsafe.Pointer {
	return byte_5D4594_251584[a1].C()
}

//export nox_xxx_modifGetDescById_413330
func nox_xxx_modifGetDescById_413330(a1 int32) unsafe.Pointer {
	return nox_xxx_modifGetDescById413330(a1).C()
}

func nox_xxx_modifGetDescById413330(a1 int32) *noxModifierEff {
	if a1 == math.MaxUint8 {
		return nil
	}
	for _, head := range byte_5D4594_251584 {
		for it := head; it != nil; it = it.next136 {
			if it.ind4 == uint32(a1) {
				return it
			}
		}
	}
	return nil
}

//export nox_xxx_modifGetIdByName_413290
func nox_xxx_modifGetIdByName_413290(name *C.char) int32 {
	return nox_xxx_modifGetIdByName413290(GoString(name))
}

func nox_xxx_modifGetIdByName413290(name string) int32 {
	if name == "" {
		return math.MaxUint8
	}
	for _, head := range byte_5D4594_251584 {
		for it := head; it != nil; it = it.next136 {
			if GoString(it.name0) == name {
				return int32(it.ind4)
			}
		}
	}
	return math.MaxUint8
}

//export nox_xxx_getProjectileClassById_413250
func nox_xxx_getProjectileClassById_413250(a1 int32) unsafe.Pointer {
	return nox_xxx_getProjectileClassById413250(a1).C()
}

func nox_xxx_getProjectileClassById413250(a1 int32) *noxModifier {
	for it := dword_5d4594_251600; it != nil; it = it.next80 {
		if it.ind4 == uint32(a1) {
			return it
		}
	}
	return nil
}

//export nox_xxx_equipClothFindDefByTT_413270
func nox_xxx_equipClothFindDefByTT_413270(a1 int32) unsafe.Pointer {
	return nox_xxx_equipClothFindDefByTT413270(a1).C()
}

func nox_xxx_equipClothFindDefByTT413270(a1 int32) *noxModifier {
	for it := dword_5d4594_251608; it != nil; it = it.next80 {
		if it.ind4 == uint32(a1) {
			return it
		}
	}
	return nil
}

//export sub_4A5E90_A
func sub_4A5E90_A() {
	for it := dword_5d4594_251608; it != nil; it = it.next80 {
		switch GoString(it.name0) {
		case "StreetPants":
			C.dword_5d4594_1308156 = it.C()
		case "StreetShirt":
			C.dword_5d4594_1308160 = it.C()
		case "StreetSneakers":
			C.dword_5d4594_1308164 = it.C()
		}
	}
}

func nox_xxx_equipWeapon_4131A0() {
	if *memmap.PtrUint32(0x5D4594, 251616) != 1 {
		for it := dword_5d4594_251600; it != nil; it = it.next80 {
			var ind int
			if noxflags.HasGame(noxflags.GameHost | noxflags.GameFlag22) {
				ind = int(nox_xxx_getNameId_4E3AA0(it.name0))
			} else {
				if !noxflags.HasGame(noxflags.GameClient) {
					return
				}
				ind = nox_things.IndByID(GoString(it.name0))
			}
			it.ind4 = uint32(ind)
		}
		for j := dword_5d4594_251608; j != nil; j = j.next80 {
			var ind int
			if noxflags.HasGame(noxflags.GameHost | noxflags.GameFlag22) {
				ind = int(nox_xxx_getNameId_4E3AA0(j.name0))
			} else {
				if !noxflags.HasGame(noxflags.GameClient) {
					return
				}
				ind = nox_things.IndByID(GoString(j.name0))
			}
			j.ind4 = uint32(ind)
		}
		*memmap.PtrUint32(0x5D4594, 251616) = 1
	}
}

var _ = [1]struct{}{}[88-unsafe.Sizeof(noxModifier{})]

type modColor struct {
	R, G, B byte
}

type noxModifier struct {
	name0                *C.char      // 0, 0
	ind4                 uint32       // 1, 4
	desc8                *wchar_t     // 2, 8
	colors12             [8]modColor  // 3, 12
	effectiveness36      int32        // 9, 36
	material40           int32        // 10, 40
	prienchant44         int32        // 11, 44
	secenchant48         int32        // 12, 48
	durability52         uint32       // 13, 52
	field56              uint32       // 14, 56
	reqstrength60        uint16       // 15, 60
	classes62            byte         // 15, 62
	field63              byte         // 15, 63
	damageCoeffOrArmor64 float32      // 16, 64
	range68              float32      // 17, 68
	damageMin72          uint16       // 18, 72
	field74              uint16       // 18, 74
	damageType76         uint32       // 19, 76
	next80               *noxModifier // 20, 80
	prev84               *noxModifier // 21, 84
}

func (p *noxModifier) C() unsafe.Pointer {
	return unsafe.Pointer(p)
}

func (p *noxModifier) Name() string {
	return GoString(p.name0)
}

func (p *noxModifier) Index() int {
	return int(p.ind4)
}

func (p *noxModifier) Desc() string {
	return GoWString(p.desc8)
}

func nox_xxx_parseWeaponOrArmorDef412D40(head **noxModifier, arr []modifiers.WeaponOrArmor) error {
	for _, w := range arr {
		p, _ := alloc.New(noxModifier{})
		p.prev84 = nil
		p.next80 = *head
		if *head != nil {
			(*head).prev84 = p
		}
		*head = p
		p.name0 = CString(w.Name)
		if w.Desc != "" {
			p.desc8, _ = CWString(strMan.GetStringInFile(strman.ID(w.Desc), "Modifier.c"))
		}
		for i := range p.colors12 {
			p.colors12[i] = modColor{0xff, 0xff, 0xff}
		}
		for i, c := range w.Colors {
			cl := c.Color
			p.colors12[i+1] = modColor{R: byte(cl.R), G: byte(cl.G), B: byte(cl.B)}
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
		p.classes62 = byte(cl)
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

var _ = [1]struct{}{}[144-unsafe.Sizeof(noxModifierEff{})]

type noxModifierEffFnc struct {
	fnc  unsafe.Pointer
	valf float32
	val  int32
}

type noxModifierEff struct { // obj_412ae0_t
	name0             *C.char           // 0, 0
	ind4              uint32            // 1, 4
	desc8             *wchar_t          // 2, 8
	secdesc12         *wchar_t          // 3, 12
	identdesc16       *wchar_t          // 4, 16
	price20           int32             // 5, 20
	color24           modColor          // 6, 24
	_                 byte              // 6, 27
	allowWeapons28    uint32            // 7, 28
	allowArmor32      uint32            // 8, 32
	allowPos36        uint32            // 9, 36
	attack40          noxModifierEffFnc // 10, 40
	attackPreHit52    noxModifierEffFnc // 13, 52
	attackPreDmg64    noxModifierEffFnc // 16, 64
	defend76          noxModifierEffFnc // 19, 76
	defendCollide88   noxModifierEffFnc // 22, 88
	update100         noxModifierEffFnc // 25, 100
	engage112         unsafe.Pointer    // 28, 112
	disengage116      unsafe.Pointer    // 29, 116
	engageFloat120    float32           // 30, 120
	engageInt124      int32             // 31, 124
	disengageFloat128 float32           // 32, 128
	disengageInt132   int32             // 33, 132
	next136           *noxModifierEff   // 34, 136
	prev140           *noxModifierEff   // 35, 140
}

func (p *noxModifierEff) C() unsafe.Pointer {
	return unsafe.Pointer(p)
}

func (p *noxModifierEff) Name() string {
	return GoString(p.name0)
}

func (p *noxModifierEff) Index() int {
	return int(p.ind4)
}

func (p *noxModifierEff) Desc() string {
	return GoWString(p.desc8)
}

func nox_xxx_parseModifDesc_412AE0(typ int, arr []modifiers.Effect) error {
	for _, v := range arr {
		p, _ := alloc.New(noxModifierEff{})
		p.ind4 = byte_5D4594_251596
		byte_5D4594_251596++

		p.prev140 = nil
		p.next136 = byte_5D4594_251584[typ]
		if byte_5D4594_251584[typ] != nil {
			byte_5D4594_251584[typ].prev140 = p
		}
		byte_5D4594_251584[typ] = p

		p.name0 = CString(v.Name)
		if v.Desc != "" {
			p.desc8, _ = CWString(strMan.GetStringInFile(strman.ID(v.Desc), "Modifier.c"))
		} else if v.PriDesc != "" {
			p.desc8, _ = CWString(strMan.GetStringInFile(strman.ID(v.PriDesc), "Modifier.c"))
		}
		if v.SecondDesc != "" {
			p.secdesc12, _ = CWString(strMan.GetStringInFile(strman.ID(v.SecondDesc), "Modifier.c"))
		}
		if v.IdentifyDesc != "" {
			p.identdesc16, _ = CWString(strMan.GetStringInFile(strman.ID(v.IdentifyDesc), "Modifier.c"))
		}
		p.price20 = int32(v.Price)
		p.color24 = modColor{R: byte(v.Color.R), G: byte(v.Color.G), B: byte(v.Color.B)}
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
			if err := modParseEffect(d.text, d.table, p, modParseTarg{d.fnc, d.fval, d.ival}, d.src); err != nil {
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

type modParseTarg struct {
	Func  *unsafe.Pointer
	Float *float32
	Int   *int32
}

func modParseEffect(text string, table map[string]modFuncs, mod *noxModifierEff, p modParseTarg, v string) error {
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
	Parse func(mod *noxModifierEff, p modParseTarg, v string) bool
}

func modEffectParseInt(_ *noxModifierEff, p modParseTarg, s string) bool {
	v, err := strconv.ParseInt(firstWord(s), 10, 32)
	if err != nil {
		*p.Int = -1
	} else {
		*p.Int = int32(v)
	}
	return true
}

func modEffectParseFloat(_ *noxModifierEff, p modParseTarg, s string) bool {
	v, err := strconv.ParseFloat(firstWord(s), 32)
	if err != nil {
		*p.Float = -1
	} else {
		*p.Float = float32(v)
	}
	return true
}

var modDamageEffects = map[string]modFuncs{
	"DamageMultiplierEffect": {C.nox_xxx_effectDamageMultiplier_4E04C0, modEffectParseFloat},
	"StunEffect":             {C.nox_xxx_stunEffect_4E04D0, modEffectParseInt},
	"FireEffect":             {C.nox_xxx_fireEffect_4E0550, modEffectParseFloat},
	"FireRingEffect":         {C.nox_xxx_fireRingEffect_4E05B0, modEffectParseInt},
	"BlueFireRingEffect":     {C.nox_xxx_blueFREffect_4E05F0, modEffectParseInt},
	"FrostEffect":            {C.nullsub_38, modEffectParseInt},
	"RecoilEffect":           {C.nox_xxx_recoilEffect_4E0640, modEffectParseFloat},
	"ConfuseEffect":          {C.nox_xxx_confuseEffect_4E0670, modEffectParseInt},
	"LightningEffect":        {C.nox_xxx_lightngEffect_4E06F0, modEffectParseFloat},
	"DrainManaEffect":        {C.nox_xxx_drainMEffect_4E0740, modEffectParseFloat},
	"VampirismEffect":        {C.nox_xxx_vampirismEffect_4E07C0, modEffectParseFloat},
	"PoisonEffect":           {C.nox_xxx_poisonEffect_4E0850, modEffectParseInt},
	"PanicEffect":            {C.nullsub_39, modEffectParseInt},
	"SympathyEffect":         {C.nox_xxx_sympathyEffect_4E08E0, modEffectParseFloat},
	"ReadinessEffect":        {C.nullsub_22, modEffectParseInt},
	"ProjectileSpeedEffect":  {C.nox_xxx_effectProjectileSpeed_4E09B0, modEffectParseFloat},
	"ReplenishmentEffect":    {C.nullsub_36, modEffectParseInt},
}

var modDefendEffects = map[string]modFuncs{
	"ArmorMultiplierEffect":      {C.sub_4E0370, modEffectParseFloat},
	"DurabilityMultiplierEffect": {C.sub_4E0380, modEffectParseFloat},
	"ResilienceEffect":           {C.nullsub_40, modEffectParseFloat},
	"InversionEffect":            {C.nox_xxx_inversionEffect_4E03D0, modEffectParseInt},
	"GripEffect":                 {C.nox_xxx_gripEffect_4E0480, modEffectParseInt},
	"BreakingEffect":             {C.nullsub_41, modEffectParseFloat},
	"PunctureProneEffect":        {C.nullsub_42, modEffectParseFloat},
}

var modUpdateEffects = map[string]modFuncs{
	"RegenerationUpdate":           {C.nox_xxx_effectRegeneration_4E01D0, modEffectParseInt},
	"ParasiteUpdate":               {C.nullsub_43, modEffectParseInt},
	"AttractionUpdate":             {C.nullsub_44, modEffectParseInt},
	"ContinualReplenishmentUpdate": {C.nox_xxx_attribContinualReplen_4E02C0, modEffectParseInt},
}

var modEngageEffects = map[string]modFuncs{
	"BrillianceEngage":          {C.sub_4DFB50, modEffectParseInt},
	"BrillianceDisengage":       {C.sub_4DFB80, modEffectParseInt},
	"SpeedEngage":               {C.nox_xxx_effectSpeedEngage_4DFC30, modEffectParseFloat},
	"SpeedDisengage":            {C.nox_xxx_effectSpeedDisengage_4DFCA0, modEffectParseFloat},
	"FireProtectEngage":         {C.sub_4DFD10, modEffectParseFloat},
	"FireProtectDisengage":      {C.nox_xxx_modifFireProtection_4DFD40, modEffectParseFloat},
	"LightningProtectEngage":    {C.nox_xxx_buff_4DFD80, modEffectParseFloat},
	"LightningProtectDisengage": {C.sub_4DFDB0, modEffectParseFloat},
	"PoisonProtectEngage":       {C.nox_xxx_checkPoisonProtectEnch_4DFDE0, modEffectParseFloat},
	"PoisonProtectDisengage":    {C.sub_4DFE10, modEffectParseFloat},
	"RegenerationEngage":        {C.sub_4E0140, nil},
	"RegenerationDisengage":     {C.sub_4E0170, nil},
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
