package nox

/*
#include "defs.h"
#include "server__magic__plyrspel.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4.h"
#include "GAME4_2.h"
#include "GAME4_3.h"
#include "GAME5_2.h"
#include "server__magic__spell__execdur.h"
extern nox_spell_t nox_spells_arr_588124[NOX_SPELLS_MAX+1];
void nox_xxx_spellCastByBook_4FCB80();
void nox_xxx_spellCastByPlayer_4FEEF0();

static int nox_spells_call_intint6_go(int (*f)(int, void*, nox_object_t*, nox_object_t*, void*, int), int a1, nox_object_t* a2, nox_object_t* a3, nox_object_t* a4, void* a5, int a6) { return f(a1, a2, a3, a4, a5, a6); }
*/
import "C"
import (
	"bufio"
	"fmt"
	"io"
	"unsafe"

	"nox/v1/common/alloc"
	noxflags "nox/v1/common/flags"
	"nox/v1/common/memmap"
	"nox/v1/common/object"
	"nox/v1/common/player"
	"nox/v1/common/things"
	"nox/v1/common/types"
)

var (
	spellPhonemeTree   *phonemeLeaf
	noxSpellMissileTyp int // 0x5D4594, 2489136
)

var _ = [1]struct{}{}[40-unsafe.Sizeof(phonemeLeaf{})]

type phonemeLeaf struct {
	Ind int32
	Pho [things.PhonMax]*phonemeLeaf
}

//export nox_xxx_spellGetDefArrayPtr_424820
func nox_xxx_spellGetDefArrayPtr_424820() unsafe.Pointer {
	return unsafe.Pointer(getPhonemeTree())
}

func getPhonemeTree() *phonemeLeaf {
	if spellPhonemeTree == nil {
		p, _ := alloc.Malloc(unsafe.Sizeof(phonemeLeaf{}))
		spellPhonemeTree = (*phonemeLeaf)(p)
	}
	return spellPhonemeTree
}

const noxSpellsMax = int(C.NOX_SPELLS_MAX)

//export nox_xxx_spellNameByN_424870
func nox_xxx_spellNameByN_424870(ind C.int) *C.char {
	s := things.SpellIDByIndex(int(ind))
	if s == "" {
		return nil
	}
	return internCStr(s)
}

//export nox_xxx_spellNameToN_4243F0
func nox_xxx_spellNameToN_4243F0(cid *C.char) C.int {
	id := GoString(cid)
	ind := things.SpellIndex(id)
	if ind <= 0 {
		return 0
	}
	return C.int(ind)
}

//export nox_xxx_spellAwardAll1_4EFD80
func nox_xxx_spellAwardAll1_4EFD80(p *C.nox_playerInfo) {
	serverSetAllBeastScrolls(asPlayer(p), noxflags.HasEngine(noxflags.EngineAdmin))
}

//export nox_xxx_spellAwardAll2_4EFC80
func nox_xxx_spellAwardAll2_4EFC80(p *C.nox_playerInfo) {
	serverSetAllSpells(asPlayer(p), noxflags.HasEngine(noxflags.EngineAdmin))
}

//export nox_xxx_spellAwardAll3_4EFE10
func nox_xxx_spellAwardAll3_4EFE10(p *C.nox_playerInfo) {
	serverSetAllWarriorAbilities(asPlayer(p), noxflags.HasEngine(noxflags.EngineAdmin))
}

//export nox_xxx_spellFlySearchTarget_540610
func nox_xxx_spellFlySearchTarget_540610(cpos *C.float2, msl *nox_object_t, mask C.int, dist C.float, a5 C.int, self *nox_object_t) *nox_object_t {
	var pos *types.Pointf
	if cpos != nil {
		pos = &types.Pointf{X: float32(cpos.field_0), Y: float32(cpos.field_4)}
	}
	return nox_xxx_spellFlySearchTarget(pos, asObjectC(msl), uint32(mask), float32(dist), int(a5), asUnitC(self)).CObj()
}

func nox_thing_read_SPEL_4156B0(f *MemFile) error {
	br := bufio.NewReader(f)
	spells, err := things.ReadSpellsSection(br)
	if n := br.Buffered(); n != 0 {
		f.Seek(-int64(n), io.SeekCurrent)
	}
	if err != nil {
		return err
	}
	isClient := noxflags.HasGame(noxflags.GameClient)
	for _, s := range spells {
		if err := createSpellFrom(&s, isClient); err != nil {
			return err
		}
	}
	return nil
}

func createSpellFrom(s *things.Spell, isClient bool) error {
	ind := things.SpellIndex(s.ID)
	sp := SpellDefByInd(ind)
	if sp == nil {
		return fmt.Errorf("unsupported spell: %q", s.ID)
	}
	sp.mana_cost = C.uchar(s.ManaCost)
	sp.price = C.ushort(s.Price)

	if len(s.Phonemes) != 0 {
		leaf := getPhonemeTree()
		for _, ph := range s.Phonemes {
			next := leaf.Pho[ph]
			if next == nil {
				p, _ := alloc.Malloc(unsafe.Sizeof(phonemeLeaf{}))
				next = (*phonemeLeaf)(p)
				leaf.Pho[ph] = next
			}
			leaf = next
		}
		leaf.Ind = int32(ind)

		s.Phonemes = append(s.Phonemes, things.PhonEnd)
	}
	sp.setPhonemes(s.Phonemes)

	sp.icon = nil
	if isClient {
		sp.icon = unsafe.Pointer(thingsImageRef(s.Icon).C())
	}
	sp.icon_enabled = nil
	if isClient {
		sp.icon_enabled = unsafe.Pointer(thingsImageRef(s.IconEnabled).C())
	}

	sp.flags = C.uint(s.Flags)
	sp.title = internWStr(strMan.GetStringInFile(s.Title, "C:\\NoxPost\\src\\Common\\Magic\\Speltree.c"))
	sp.desc = internWStr(strMan.GetStringInFile(s.Desc, "C:\\NoxPost\\src\\Common\\Magic\\Speltree.c"))

	sp.cast_sound = nox_xxx_utilFindSound_40AF50(s.CastSound)
	sp.on_sound = nox_xxx_utilFindSound_40AF50(s.OnSound)
	sp.off_sound = nox_xxx_utilFindSound_40AF50(s.OffSound)
	sp.enabled = 1
	sp.valid = 1
	return nil
}

func nox_xxx_spellHasFlags_424A50(ind int, flag things.SpellFlags) bool {
	sp := SpellDefByInd(ind)
	if sp == nil {
		return false
	}
	return sp.Flags().Has(flag)
}

func serverSetAllBeastScrolls(p *Player, enable bool) {
	lvl := 0
	if enable {
		lvl = 1
	}
	C.nox_xxx_playerUpdateNetBuffs_56F7D0(C.int(*(*uintptr)(p.field(4640))), 0)
	for i := 1; i < len(p.beast_scroll_lvl); i++ {
		p.beast_scroll_lvl[i] = C.uint(lvl)
		C.nox_xxx_playerAwardSpellProtection_56FCE0(C.int(*(*uintptr)(p.field(4640))), C.int(i), C.int(lvl))
	}
	C.sub_56FD50(C.int(*(*uintptr)(p.field(4640))), unsafe.Pointer(&p.beast_scroll_lvl[0]), C.int(len(p.beast_scroll_lvl)))
}

func serverSetAllSpells(p *Player, enable bool) {
	lvl := 0
	if enable {
		lvl = 3
	}
	C.nox_xxx_playerUpdateNetBuffs_56F7D0(C.int(*(*uintptr)(p.field(4636))), 0)
	for i := 1; i < len(p.spell_lvl); i++ {
		p.spell_lvl[i] = C.uint(lvl)
		C.nox_xxx_playerAwardSpellProtection_56FCE0(C.int(*(*uintptr)(p.field(4636))), C.int(i), C.int(lvl))
	}
	if !enable && noxflags.HasGame(noxflags.GameModeQuest) {
		u := p.UnitC()
		switch p.PlayerClass() {
		case player.Wizard:
			C.nox_xxx_spellGrantToPlayer_4FB550_magic_plyrspel(u.CObj(), 27, 1, 1, 1)
		case player.Conjurer:
			C.nox_xxx_spellGrantToPlayer_4FB550_magic_plyrspel(u.CObj(), 9, 1, 1, 1)
			C.nox_xxx_spellGrantToPlayer_4FB550_magic_plyrspel(u.CObj(), 41, 1, 1, 1) // spawn spells?
		}
	}
	C.sub_56FD50(C.int(*(*uintptr)(p.field(4636))), unsafe.Pointer(&p.spell_lvl[0]), C.int(len(p.spell_lvl)))
}

func serverSetAllWarriorAbilities(p *Player, enable bool) {
	if p.PlayerClass() != player.Warrior {
		return
	}
	lvl := 0
	if enable {
		lvl = 5
	}
	for i := 1; i < 6; i++ {
		p.spell_lvl[i] = C.uint(lvl)
		C.nox_xxx_playerAwardSpellProtection_56FCE0(C.int(*(*uintptr)(p.field(4636))), C.int(i), C.int(lvl))
	}
}

func nox_xxx_spellBookReact_4FCB70() {
	C.nox_xxx_spellCastByBook_4FCB80()
	C.nox_xxx_spellCastByPlayer_4FEEF0()
}

func SpellDefs() []*SpellDef {
	out := make([]*SpellDef, 0, noxSpellsMax)
	for i := 1; i < noxSpellsMax; i++ {
		out = append(out, (*SpellDef)(unsafe.Pointer(&C.nox_spells_arr_588124[i])))
	}
	return out
}

func SpellDefByInd(i int) *SpellDef {
	if i <= 0 || i >= noxSpellsMax {
		return nil
	}
	return (*SpellDef)(unsafe.Pointer(&C.nox_spells_arr_588124[i]))
}

func SpellIDs() []string {
	out := make([]string, 0, noxSpellsMax)
	for i := 1; i < noxSpellsMax; i++ {
		out = append(out, things.SpellIDByIndex(i))
	}
	return out
}

type SpellDef C.nox_spell_t

func (s *SpellDef) Title() string {
	return GoWString(s.title)
}

func (s *SpellDef) Description() string {
	return GoWString(s.desc)
}

func (s *SpellDef) Flags() things.SpellFlags {
	return things.SpellFlags(s.flags)
}

func (s *SpellDef) Allowed() bool {
	return s.enabled == 1
}

func (s *SpellDef) Valid() bool {
	return s.valid == 1
}

func (s *SpellDef) ManaCost() int {
	return int(s.mana_cost)
}

func (s *SpellDef) BasePrice() int {
	return int(s.price)
}

func (s *SpellDef) setPhonemes(ph []things.Phoneme) {
	s.phonemes_cnt = C.uchar(len(ph))
	for i, p := range ph {
		s.phonemes[i] = C.char(p)
	}
}

func (s *SpellDef) Phonemes() (out []things.Phoneme) {
	for i := 0; i < int(s.phonemes_cnt); i++ {
		out = append(out, things.Phoneme(s.phonemes[i]))
	}
	return out
}

func (s *SpellDef) GetAudio(snd int) int { // nox_xxx_spellGetAud44_424800
	if s == nil {
		return 0
	}
	switch snd {
	case 0:
		return int(s.cast_sound)
	case 1:
		return int(s.on_sound)
	case 2:
		return int(s.off_sound)
	}
	return 0
}

type spellAcceptArg struct {
	Obj  *nox_object_t
	Arg1 float32
	Arg2 float32
}

//export nox_xxx_spellAccept_4FD400
func nox_xxx_spellAccept_4FD400(ispellID C.int, a2, a3p, a4p, a5p unsafe.Pointer, lvli C.int) C.int {
	if nox_xxx_spellAccept4FD400(int(ispellID), asUnit(a2), asUnit(a3p), asUnit(a4p), (*spellAcceptArg)(a5p), int(lvli)) {
		return 1
	}
	return 0
}

func nox_xxx_spellAccept4FD400(spellID int, a2, obj3, obj4 *Unit, arg5 *spellAcceptArg, lvl int) bool {
	if spellID == 0 {
		return false
	}
	if obj3 == nil {
		return false
	}
	if a2 == nil {
		return false
	}
	if arg5 == nil {
		return false
	}
	obj5 := asUnitC(arg5.Obj)
	if nox_xxx_spellHasFlags_424A50(spellID, things.SpellFlagUnk8) && obj5 != nil && !obj5.Class().Has(object.MaskUnits) {
		return false
	}
	if !(obj5 == nil || C.nox_xxx_gameCaptureMagic_4FDC10(C.int(spellID), obj5.CObj()) != 0) {
		nox_xxx_aud_501960(231, obj5, 0, 0)
		return false
	}
	var (
		fnc  func(spellID int, a2, a3, a4 *Unit, a5 *spellAcceptArg, lvl int) int
		cfnc unsafe.Pointer
	)
	switch spellID {
	case 1:
		cfnc = C.nox_xxx_castAnchor_52C390
	case 2:
		cfnc = C.nox_xxx_spellArachna_52DC80
	case 3:
		cfnc = C.sub_52C750
	case 4:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, arg5, lvl, C.nox_xxx_spellBlink2_530310, C.nox_xxx_spellBlink1_530380, nil, 0)
	case 5:
		cfnc = C.nox_xxx_castBurn_52C3E0
	case 6:
		cfnc = C.sub_52BBA0
	case 8:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, arg5, lvl, nil, C.sub_52F460, nil, 0)
	case 9:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, arg5, lvl, C.nox_xxx_charmCreature1_5011F0, C.nox_xxx_charmCreatureFinish_5013E0, C.nox_xxx_charmCreature2_501690, 0)
	case 10, 11:
		cfnc = C.nox_xxx_spellCastCleansingFlame_52D5C0
	case 12:
		cfnc = C.nox_xxx_castConfuse_52C1E0
	case 13:
		cfnc = C.nox_xxx_castCounterSpell_52BBB0
	case 14:
		cfnc = C.nox_xxx_castCurePoison_52CDB0
	case 15:
		cfnc = C.nox_xxx_castDeath_52C920
	case 16:
		cfnc = C.nox_xxx_castDeathRay_52D1E0
	case 17:
		cfnc = C.sub_52C8D0
	case 18:
		cfnc = C.sub_52BF00
	case 19:
		cfnc = C.sub_537E60
	case 21:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, arg5, lvl, C.nox_xxx_spellTurnUndeadCreate_531310, C.nox_xxx_spellTurnUndeadUpdate_531410, C.nox_xxx_spellTurnUndeadDelete_531420, 70)
	case 22:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, arg5, lvl, nil, C.nox_xxx_spellDrainMana_52E210, nil, 0)
	case 23:
		cfnc = C.nox_xxx_castEquake_52DE40
	case 24:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, arg5, lvl, C.nox_xxx_spellEnergyBoltStop_52E820, C.nox_xxx_spellEnergyBoltTick_52E850, C.nullsub_29, 30)
	case 26:
		cfnc = C.nox_xxx_castFear_52DF40
	case 27:
		cfnc = C.nox_xxx_castFireball_52C790
	case 28:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, arg5, lvl, nil, C.nox_xxx_firewalkTick_52ED40, nil, 3*gameFPS())
	case 29:
		cfnc = C.nox_xxx_castFist_52D3C0
	case 31:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, arg5, lvl, C.sub_52EF30, C.sub_52EFD0, C.sub_52F1D0, 2*gameFPS()/3)
	case 32:
		cfnc = C.nox_xxx_castFreeze_52C350
	case 33:
		cfnc = C.nox_xxx_castFumble_52C060
	case 34:
		cfnc = C.nox_xxx_castGlyph_537FA0
	case 35:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, arg5, lvl, C.sub_52F220, C.sub_52F2E0, nil, 0)
	case 36:
		cfnc = C.nox_xxx_castHaste_52C640
	case 37:
		cfnc = C.nox_xxx_castInfra_52CA30
	case 38:
		cfnc = C.sub_52BEB0
	case 39:
		cfnc = C.nox_xxx_castInvis_52C980
	case 40:
		cfnc = C.nox_xxx_castInvul_52C9E0
	case 41:
		cfnc = C.sub_52DD50
	case 42:
		cfnc = C.nox_xxx_castLight_52C6D0
	case 43:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, arg5, lvl, C.nox_xxx_onStartLightning_52F820, C.nox_xxx_onFrameLightning_52F8A0, C.sub_530100, 30)
	case 44:
		cfnc = C.nox_xxx_castLock_52CE90
	case 45:
		cfnc = C.sub_52CA80
	case 46, 47, 48, 49:
		cfnc = C.sub_52CBD0
	case 50:
		fnc = nox_xxx_castMissilesOM_540160
	case 51:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj5, obj4, arg5, lvl, C.nox_xxx_castShield1_52F5A0, C.sub_52F650, C.sub_52F670, 0)
	case 52:
		cfnc = C.nox_xxx_castMeteor_52D9D0
	case 53:
		cfnc = C.nox_xxx_castMeteorShower_52D8A0
	case 54:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj5, obj4, arg5, lvl, C.nox_xxx_spellCreateMoonglow_531A00, nil, C.sub_531AF0, 0)
	case 55:
		cfnc = C.sub_52C230
	case 56:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, arg5, lvl, C.nox_xxx_manaBomb_530F90, C.nox_xxx_manaBombBoom_5310C0, C.sub_531290, 0)
	case 57:
		cfnc = C.nox_xxx_spellPhantom_52CA70
	case 58:
		cfnc = C.nox_xxx_castPixies_540440
	case 59:
		v8 := gamedataFloat("PlasmaSearchTime")
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, arg5, lvl, C.nox_xxx_plasmaSmth_531580, C.nox_xxx_plasmaShot_531600, C.sub_5319E0, uint32(v8))
	case 60:
		cfnc = C.nox_xxx_castPoison_52C720
	case 61:
		cfnc = C.nox_xxx_castProtectElect_52D150
	case 62:
		cfnc = C.nox_xxx_castProtectFire_52D110
	case 63:
		cfnc = C.sub_52D190
	case 64:
		cfnc = C.nox_xxx_castProtectPosion_52D1A0
	case 65:
		cfnc = C.nox_xxx_castPull_52BFA0
	case 66:
		cfnc = C.nox_xxx_castPush_52C000
	case 67:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj5, obj4, arg5, lvl, C.sub_531490, C.sub_5314F0, C.sub_531560, 0)
	case 68, 133:
		cfnc = C.nox_xxx_castSpellWinkORrestoreHealth_52BF20
	case 69:
		cfnc = C.sub_52BF50
	case 70:
		cfnc = C.nox_xxx_castRun_52C680
	case 71:
		cfnc = C.nox_xxx_useShock_52C5A0
	case 72:
		cfnc = C.nox_xxx_castSlow_52C190
	case 74:
		cfnc = C.nox_xxx_castStun_52C2C0
	case 75, 76, 77, 78, 80, 81, 82, 83, 84, 85,
		86, 87, 88, 89, 90, 91, 92, 93, 94, 95,
		96, 97, 98, 99, 100, 101, 102, 103, 104, 105,
		106, 107, 108, 109, 110, 111, 112, 113, 114:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, arg5, lvl, C.nox_xxx_summonStart_500DA0, C.nox_xxx_summonFinish_5010D0, C.nox_xxx_summonCancel_5011C0, 0)
	case 115:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, arg5, lvl, C.sub_530CA0, C.sub_530D30, nil, 0)
	case 116:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, arg5, lvl, C.nox_xxx_spellTagCreature_530160, C.sub_530250, C.sub_530270, 0)
	case 117, 118, 119, 120, 122, 123, 124, 125:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, arg5, lvl, C.sub_5305D0, C.sub_530650, nil, 0)
	case 121:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, arg5, lvl, C.nox_xxx_castTele_530820, C.sub_530880, nil, 0)
	case 126:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, arg5, lvl, C.sub_530A30_spell_execdur, C.nox_xxx_castTTT_530B70, nil, 0)
	case 127:
		cfnc = C.nox_xxx_castTelekinesis_52D330
	case 128:
		cfnc = C.nox_xxx_castToxicCloud_52DB60
	case 129:
		cfnc = C.sub_52CCD0
	case 130:
		cfnc = C.nox_xxx_castVamp_52C530
	case 131:
		cfnc = C.sub_52C270
	case 132:
		return nox_xxx_spellDurationBased_4FEBA0(spellID, a2, obj3, obj4, arg5, lvl, C.nox_xxx_spellWallCreate_4FFA90, C.nox_xxx_spellWallUpdate_500070, C.nox_xxx_spellWallDestroy_500080, 0)
	default:
		return true
	}
	if cfnc != nil {
		fnc = func(spellID int, a2, a3, a4 *Unit, a5 *spellAcceptArg, lvl int) int {
			return int(C.nox_spells_call_intint6_go((*[0]byte)(cfnc), C.int(spellID), a2.CObj(), a3.CObj(), a4.CObj(), unsafe.Pointer(arg5), C.int(lvl)))
		}
	}
	v9 := fnc(spellID, a2, obj3, obj4, arg5, lvl)
	if v9 == 0 {
		nox_xxx_aud_501960(231, obj4, 0, 0)
	}
	return v9 != 0
}

func nox_xxx_spellDurationBased_4FEBA0(spellID int, a2, a3, a4 *Unit, a5 *spellAcceptArg, a6 int, a7, a8, a9 unsafe.Pointer, a10 uint32) bool {
	return C.nox_xxx_spellDurationBased_4FEBA0(C.int(spellID), a2.CObj(), a3.CObj(), a4.CObj(), unsafe.Pointer(a5), C.int(a6), a7, a8, a9, C.int(a10)) != 0
}

type MissilesSpellOpts struct {
	Count       int
	Spread      uint16
	Type        string
	VelMult     float32
	Offset      float32
	SpeedRndMin float64
	SpeedRndMax float64
	SearchDist  float32
}

func (s *Server) castSpellMissilesCustom(spellID int, owner, caster *Unit, opts MissilesSpellOpts) {
	cpos := caster.Pos()
	cvel := caster.Vel()
	rdist := float32(caster.shape.circle_r) + opts.Offset
	for i := 0; i < opts.Count; i++ {
		doff := int16(opts.Spread * uint16((i+1)/2))
		if i%2 == 1 {
			doff = -doff
		}
		dir := nox_xxx_math_roundDirI16(int16(caster.field_31_0) + doff)
		dirX := memmap.Float32(0x587000, 194136+8*uintptr(dir))
		dirY := memmap.Float32(0x587000, 194140+8*uintptr(dir))
		p2 := types.Pointf{
			X: cpos.X + cvel.X + rdist*dirX,
			Y: cpos.Y + cvel.Y + rdist*dirY,
		}
		tpos, ok := nox_xxx_mapTraceRay_535250_00(cpos, p2, 5)
		if !ok {
			continue
		}
		msl := noxServer.newObjectByTypeID(opts.Type)
		mud := msl.updateDataMissile()
		nox_xxx_createAt_4DAA50(msl, owner, tpos)
		mspeed := float32(noxRndCounter1.FloatClamp(opts.SpeedRndMin, opts.SpeedRndMax) * float64(msl.speed_cur))
		msl.speed_cur = C.float(mspeed)
		msl.setDir(dir)
		msl.setVel(types.Pointf{
			X: cvel.X + mspeed*dirX*opts.VelMult,
			Y: cvel.Y + mspeed*dirY*opts.VelMult,
		})
		var ppos *types.Pointf
		if caster.Class().Has(object.ClassPlayer) {
			pl := caster.ControllingPlayer()
			ppos = &types.Pointf{
				X: float32(pl.field_2284),
				Y: float32(pl.field_2288),
			}
		}
		targ := nox_xxx_spellFlySearchTarget(ppos, msl, 0x20, opts.SearchDist, 0, owner)
		mud.owner = owner.CObj()
		mud.target = targ.CObj()
		mud.spellID = C.int(spellID)
	}
	aud := SpellDefByInd(spellID).GetAudio(0)
	nox_xxx_aud_501960(aud, caster, 0, 0)
}

func nox_xxx_castMissilesOM_540160(spellID int, a2, owner, caster *Unit, a5 *spellAcceptArg, lvl int) int {
	const typ = "MagicMissile"
	if noxSpellMissileTyp == 0 {
		noxSpellMissileTyp = noxServer.getObjectTypeID(typ)
	}
	// it's intentionally loading this variable twice
	// looks previously there were two separate config values for it
	cnt := int(gamedataFloatInd("MagicMissileCount", lvl-1))
	curCnt := owner.countSubOfType(noxSpellMissileTyp)
	maxCnt := int(gamedataFloatInd("MagicMissileCount", lvl-1))
	if curCnt+cnt > maxCnt {
		cnt = maxCnt - curCnt
	}
	if cnt <= 0 {
		C.nox_xxx_netPriMsgToPlayer_4DA2C0(owner.CObj(), internCStr("mmissile.c:TooManyMissiles"), 0)
		return 0
	}
	noxServer.castSpellMissilesCustom(spellID, owner, caster, MissilesSpellOpts{
		Count:       cnt,
		Spread:      16,
		Type:        typ,
		Offset:      4.0,
		VelMult:     0.1,
		SpeedRndMin: 0.80000001,
		SpeedRndMax: 1.2,
		SearchDist:  600.0,
	})
	return 1
}

func nox_xxx_spellFlySearchTarget(pos *types.Pointf, msl *Object, mask uint32, dist float32, a5 int, self *Unit) *Object {
	if self != nil && self.Class().Has(object.ClassPlayer) && mask&0x20 != 0 {
		if curTarg := self.updateDataPlayer().CursorObj(); curTarg != nil {
			if self.isEnemyTo(curTarg) && ((a5 == 1) || (a5 == 0) && msl != curTarg) {
				return curTarg
			}
		}
	}
	var center types.Pointf
	if pos == nil {
		if msl == nil {
			return nil
		}
		center = msl.Pos()
	} else if msl != nil {
		if _, ok := nox_xxx_mapTraceRay_535250_00(msl.Pos(), *pos, 5); ok {
			center = *pos // TODO: it ignores tay tracing result; intentional?
		} else {
			center = msl.Pos()
		}
	} else {
		center = *pos
	}
	dist2 := dist * dist
	owner := msl.findOwnerChainPlayer()
	rect := types.Rectf{
		Left:   center.X - dist,
		Top:    center.Y - dist,
		Right:  center.X + dist,
		Bottom: center.Y + dist,
	}
	var (
		minDist float32 = 1e+08
		found   *Object
	)
	getUnitsInRect(rect, func(it *Object) {
		if !(a5 != 0 || msl != it) {
			return
		}
		if !it.Class().HasAny(object.MaskTargets) {
			return
		}
		if it.Class().Has(object.ClassMonster) && (it.field_3&0x8000 != 0) {
			return
		}
		if it.Class().Has(object.ClassPlayer) && it.AsUnit().ControllingPlayer().field_3680&0x1 != 0 {
			return
		}
		if it.Flags().HasAny(object.FlagDestroyed | object.FlagDead) {
			return
		}
		if it.Class().Has(object.ClassMonster) && (it.field_3&0x4000 != 0) {
			return
		}
		it.findOwnerChainPlayer() // FIXME: result unused!
		if (mask&0x20 != 0) && !msl.isEnemyTo(it) {
			return
		}
		opos := it.Pos()
		dx := center.X - opos.X
		dy := center.Y - opos.Y
		odist := dy*dy + dx*dx
		if odist > dist2 {
			return
		}
		if msl != nil && !nox_xxx_unitCanInteractWith_5370E0(msl, it, 0) {
			return
		}
		if owner != nil && !nox_xxx_unitCanInteractWith_5370E0(owner, it, 0) {
			return
		}
		if odist < minDist {
			found = it
			minDist = odist
		}
	})
	return found
}

//export nox_xxx_castSpellByUser_4FDD20
func nox_xxx_castSpellByUser_4FDD20(a1 C.int, a2 *nox_object_t, a3 unsafe.Pointer) C.int {
	if nox_xxx_castSpellByUser4FDD20(int(a1), asUnitC(a2), (*spellAcceptArg)(a3)) {
		return 1
	}
	return 0
}

func nox_xxx_castSpellByUser4FDD20(spellInd int, u *Unit, a3 *spellAcceptArg) bool {
	lvl := int(C.nox_xxx_spellGetPower_4FE7B0(C.int(spellInd), u.CObj()))
	if nox_xxx_spellHasFlags_424A50(spellInd, things.SpellCancelsProtect) {
		C.nox_xxx_spellBuffOff_4FF5B0(u.CObj(), 0)
		C.nox_xxx_spellBuffOff_4FF5B0(u.CObj(), 23)
		C.nox_xxx_spellCancelDurSpell_4FEB10(67, u.CObj())
	}
	if !nox_xxx_spellHasFlags_424A50(spellInd, things.SpellTargetFoe) || u.CObj() == a3.Obj {
		return nox_xxx_spellAccept4FD400(spellInd, u, u, u, a3, lvl)
	}
	C.nox_xxx_createSpellFly_4FDDA0(u.CObj(), a3.Obj, C.int(spellInd))
	return true
}
