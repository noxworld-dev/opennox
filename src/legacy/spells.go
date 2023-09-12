package legacy

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
void nox_xxx_spellCastByBook_4FCB80();
void nox_xxx_spellCastByPlayer_4FEEF0();

extern void* nox_alloc_magicEnt_1569668;
extern uint32_t dword_5d4594_1569672;

int nox_xxx_spellCastCleansingFlame_52D5C0(int a1, nox_object_t* a2p, nox_object_t* a3p, nox_object_t* a4p, void* a5p, int a6);
int nox_xxx_spellWallCreate_4FFA90(void* a1);
int nox_xxx_spellWallUpdate_500070(void* a1);
void nox_xxx_spellWallDestroy_500080(void* a1);

static int nox_spells_call_intint6_go(int (*f)(int, void*, nox_object_t*, nox_object_t*, void*, int), int a1, nox_object_t* a2, nox_object_t* a3, nox_object_t* a4, void* a5, int a6) { return f(a1, a2, a3, a4, a5, a6); }
*/
import "C"
import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/spell"
	"github.com/noxworld-dev/opennox-lib/things"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	GetPhonemeTree                    func() unsafe.Pointer
	Nox_xxx_spellAwardAll1_4EFD80     func(p *server.Player)
	Nox_xxx_spellAwardAll2_4EFC80     func(p *server.Player)
	Nox_xxx_spellAwardAll3_4EFE10     func(p *server.Player)
	Nox_xxx_spellGetAud44_424800      func(ind, a2 int) int
	Nox_xxx_spellTitle_424930         func(ind int) (string, bool)
	Nox_xxx_spellDescription_424A30   func(ind int) (string, bool)
	Nox_xxx_spellByTitle_424960       func(ctitle string) int
	Nox_xxx_spellManaCost_4249A0      func(ind, a2 int) int
	Nox_xxx_spellPhonemes_424A20      func(ind, ind2 int) spell.Phoneme
	Nox_xxx_spellIcon_424A90          func(ind int) unsafe.Pointer
	Nox_xxx_spellIconHighlight_424AB0 func(ind int) unsafe.Pointer
	Nox_xxx_spellFirstValid_424AD0    func() int
	Nox_xxx_spellNextValid_424AF0     func(ind int) int
	Nox_xxx_spellIsValid_424B50       func(ind int) bool
	Nox_xxx_spellIsEnabled_424B70     func(ind int) bool
	Nox_xxx_spellEnable_424B90        func(ind int) bool
	Nox_xxx_spellDisable_424BB0       func(ind int) bool
	Nox_xxx_spellCanUseInTrap_424BF0  func(ind int) bool
	Nox_xxx_spellPrice_424C40         func(ind int) int
	Nox_xxx_spellEnableAll_424BD0     func()
	Nox_xxx_castSpellByUser_4FDD20    func(a1 int, a2 *server.Object, a3 unsafe.Pointer) int
	Nox_xxx_spellWallCreate_4FFA90    func(sp *server.DurSpell) int
	Nox_xxx_spellWallUpdate_500070    func(sp *server.DurSpell) int
	Nox_xxx_spellWallDestroy_500080   func(sp *server.DurSpell)
)

//export nox_xxx_spellGetDefArrayPtr_424820
func nox_xxx_spellGetDefArrayPtr_424820() unsafe.Pointer {
	return unsafe.Pointer(GetPhonemeTree())
}

//export nox_xxx_getEnchantSpell_424920
func nox_xxx_getEnchantSpell_424920(enc int) int {
	return int(server.EnchantID(enc).Spell())
}

//export nox_xxx_getEnchantName_4248F0
func nox_xxx_getEnchantName_4248F0(enc int) *C.char {
	return internCStr(server.EnchantID(enc).String())
}

//export nox_xxx_enchantByName_424880
func nox_xxx_enchantByName_424880(cname *C.char) int {
	id, ok := server.ParseEnchant(GoString(cname))
	if !ok {
		return -1
	}
	return int(id)
}

//export nox_xxx_spellNameByN_424870
func nox_xxx_spellNameByN_424870(ind int) *C.char {
	s := spell.ID(ind).String()
	if s == "" {
		return nil
	}
	return internCStr(s)
}

//export nox_xxx_spellNameToN_4243F0
func nox_xxx_spellNameToN_4243F0(cid *C.char) int {
	id := GoString(cid)
	ind := spell.ParseID(id)
	if ind <= 0 {
		return 0
	}
	return int(ind)
}

//export nox_xxx_spellAwardAll1_4EFD80
func nox_xxx_spellAwardAll1_4EFD80(p *C.nox_playerInfo) { Nox_xxx_spellAwardAll1_4EFD80(asPlayerS(p)) }

//export nox_xxx_spellAwardAll2_4EFC80
func nox_xxx_spellAwardAll2_4EFC80(p *C.nox_playerInfo) { Nox_xxx_spellAwardAll2_4EFC80(asPlayerS(p)) }

//export nox_xxx_spellAwardAll3_4EFE10
func nox_xxx_spellAwardAll3_4EFE10(p *C.nox_playerInfo) { Nox_xxx_spellAwardAll3_4EFE10(asPlayerS(p)) }

//export nox_xxx_spellFlySearchTarget_540610
func nox_xxx_spellFlySearchTarget_540610(cpos *C.float2, msl *nox_object_t, sflags C.int, dist C.float, a5 C.int, self *nox_object_t) *nox_object_t {
	var pos *types.Pointf
	if cpos != nil {
		pos = &types.Pointf{X: float32(cpos.field_0), Y: float32(cpos.field_4)}
	}
	return asObjectC(GetServer().Nox_xxx_spellFlySearchTarget(pos, ToObjS(msl), things.SpellFlags(sflags), float32(dist), int(a5), asObjectS(self)))
}

//export nox_xxx_spellGetAud44_424800
func nox_xxx_spellGetAud44_424800(ind, a2 int) int { return Nox_xxx_spellGetAud44_424800(ind, a2) }

//export nox_xxx_spellTitle_424930
func nox_xxx_spellTitle_424930(ind int) *wchar2_t {
	s, ok := Nox_xxx_spellTitle_424930(ind)
	if !ok {
		return nil
	}
	return internWStr(s)
}

//export nox_xxx_spellDescription_424A30
func nox_xxx_spellDescription_424A30(ind int) *wchar2_t {
	s, ok := Nox_xxx_spellDescription_424A30(ind)
	if !ok {
		return nil
	}
	return internWStr(s)
}

//export nox_xxx_spellByTitle_424960
func nox_xxx_spellByTitle_424960(ctitle *wchar2_t) int {
	return Nox_xxx_spellByTitle_424960(GoWString(ctitle))
}

//export nox_xxx_spellManaCost_4249A0
func nox_xxx_spellManaCost_4249A0(ind, a2 int) int { return Nox_xxx_spellManaCost_4249A0(ind, a2) }

//export nox_xxx_spellPhonemes_424A20
func nox_xxx_spellPhonemes_424A20(ind, ind2 int) C.char {
	return C.char(Nox_xxx_spellPhonemes_424A20(ind, ind2))
}

//export nox_xxx_spellHasFlags_424A50
func nox_xxx_spellHasFlags_424A50(ind, flags int) C.bool {
	return C.bool(GetServer().SpellHasFlags(spell.ID(ind), things.SpellFlags(flags)))
}

//export nox_xxx_spellFlags_424A70
func nox_xxx_spellFlags_424A70(ind int) C.uint { return C.uint(GetServer().SpellFlags(spell.ID(ind))) }

//export nox_xxx_spellIcon_424A90
func nox_xxx_spellIcon_424A90(ind int) unsafe.Pointer { return Nox_xxx_spellIcon_424A90(ind) }

//export nox_xxx_spellIconHighlight_424AB0
func nox_xxx_spellIconHighlight_424AB0(ind int) unsafe.Pointer {
	return Nox_xxx_spellIconHighlight_424AB0(ind)
}

//export nox_xxx_spellFirstValid_424AD0
func nox_xxx_spellFirstValid_424AD0() int { return Nox_xxx_spellFirstValid_424AD0() }

//export nox_xxx_spellNextValid_424AF0
func nox_xxx_spellNextValid_424AF0(ind int) int { return Nox_xxx_spellNextValid_424AF0(ind) }

//export nox_xxx_spellIsValid_424B50
func nox_xxx_spellIsValid_424B50(ind int) C.bool { return C.bool(Nox_xxx_spellIsValid_424B50(ind)) }

//export nox_xxx_spellIsEnabled_424B70
func nox_xxx_spellIsEnabled_424B70(ind int) C.bool { return C.bool(Nox_xxx_spellIsEnabled_424B70(ind)) }

//export nox_xxx_spellEnable_424B90
func nox_xxx_spellEnable_424B90(ind int) C.bool { return C.bool(Nox_xxx_spellEnable_424B90(ind)) }

//export nox_xxx_spellDisable_424BB0
func nox_xxx_spellDisable_424BB0(ind int) C.bool { return C.bool(Nox_xxx_spellDisable_424BB0(ind)) }

//export nox_xxx_spellCanUseInTrap_424BF0
func nox_xxx_spellCanUseInTrap_424BF0(ind int) C.bool {
	return C.bool(Nox_xxx_spellCanUseInTrap_424BF0(ind))
}

//export nox_xxx_spellPrice_424C40
func nox_xxx_spellPrice_424C40(ind int) int { return Nox_xxx_spellPrice_424C40(ind) }

//export nox_xxx_spellEnableAll_424BD0
func nox_xxx_spellEnableAll_424BD0() { Nox_xxx_spellEnableAll_424BD0() }

//export nox_xxx_spellAccept_4FD400
func nox_xxx_spellAccept_4FD400(ispellID int, a2, a3p, a4p *nox_object_t, a5p unsafe.Pointer, lvli int) int {
	if GetServer().Nox_xxx_spellAccept4FD400(spell.ID(ispellID), asObjectS(a2), asObjectS(a3p), asObjectS(a4p), (*server.SpellAcceptArg)(a5p), lvli) {
		return 1
	}
	return 0
}

//export nox_xxx_castSpellByUser_4FDD20
func nox_xxx_castSpellByUser_4FDD20(a1 int, a2 *nox_object_t, a3 unsafe.Pointer) int {
	return Nox_xxx_castSpellByUser_4FDD20(a1, asObjectS(a2), a3)
}

//export nox_xxx_spellWallCreate_4FFA90
func nox_xxx_spellWallCreate_4FFA90(p unsafe.Pointer) int {
	return Nox_xxx_spellWallCreate_4FFA90((*server.DurSpell)(p))
}

//export nox_xxx_spellWallUpdate_500070
func nox_xxx_spellWallUpdate_500070(p unsafe.Pointer) int {
	return Nox_xxx_spellWallUpdate_500070((*server.DurSpell)(p))
}

//export nox_xxx_spellWallDestroy_500080
func nox_xxx_spellWallDestroy_500080(p unsafe.Pointer) {
	Nox_xxx_spellWallDestroy_500080((*server.DurSpell)(p))
}
func Nox_xxx_spellCastByBook_4FCB80() {
	C.nox_xxx_spellCastByBook_4FCB80()
}
func Nox_xxx_playerResetProtectionCRC_56F7D0(a1 uintptr, a2 int) {
	C.nox_xxx_playerResetProtectionCRC_56F7D0(C.int(a1), C.int(a2))
}
func Nox_xxx_playerAwardSpellProtectionCRC_56FCE0(a1 uintptr, a2 int, a3 int) {
	C.nox_xxx_playerAwardSpellProtectionCRC_56FCE0(C.int(a1), C.int(a2), C.int(a3))
}
func Nox_xxx_playerApplyProtectionCRC_56FD50(a1 uintptr, a2 unsafe.Pointer, a3 int) {
	C.nox_xxx_playerApplyProtectionCRC_56FD50(C.int(a1), a2, C.int(a3))
}
func Nox_xxx_spellGrantToPlayer_4FB550(a1 *server.Object, a2 spell.ID, a3 int, a4 int, a5 int) int {
	return int(C.nox_xxx_spellGrantToPlayer_4FB550(asObjectC(a1), C.int(a2), C.int(a3), C.int(a4), C.int(a5)))
}
func Nox_xxx_gameCaptureMagic_4FDC10(a1 spell.ID, a2 *server.Object) int {
	return int(C.nox_xxx_gameCaptureMagic_4FDC10(C.int(a1), asObjectC(a2)))
}
func Nox_spells_call_intint6_go(a1 unsafe.Pointer, a2 spell.ID, a3 *server.Object, a4 *server.Object, a5 *server.Object, a6 *server.SpellAcceptArg, a7 int) int {
	return int(C.nox_spells_call_intint6_go((*[0]byte)(a1), C.int(a2), asObjectC(a3), asObjectC(a4), asObjectC(a5), unsafe.Pointer(a6), C.int(a7)))
}
func Nox_xxx_createSpellFly_4FDDA0(a1 *server.Object, a2 *server.Object, a3 spell.ID) {
	C.nox_xxx_createSpellFly_4FDDA0(asObjectC(a1), asObjectC(a2), C.int(a3))
}
func Nox_xxx_spellGetPower_4FE7B0(a1 spell.ID, a2 *server.Object) int {
	return int(C.nox_xxx_spellGetPower_4FE7B0(C.int(a1), asObjectC(a2)))
}

func Nox_xxx_spellArachna_52DC80(spellID spell.ID, a2, a3, a4 *server.Object, sa *server.SpellAcceptArg, lvl int) int {
	return Nox_spells_call_intint6_go(C.nox_xxx_spellArachna_52DC80, spellID, a2.SObj(), a3.SObj(), a4.SObj(), sa, lvl)
}

func Nox_xxx_castBurn_52C3E0(spellID spell.ID, a2, a3, a4 *server.Object, sa *server.SpellAcceptArg, lvl int) int {
	return Nox_spells_call_intint6_go(C.nox_xxx_castBurn_52C3E0, spellID, a2.SObj(), a3.SObj(), a4.SObj(), sa, lvl)
}

func Nox_xxx_spellCastCleansingFlame_52D5C0(spellID spell.ID, a2, a3, a4 *server.Object, sa *server.SpellAcceptArg, lvl int) int {
	return Nox_spells_call_intint6_go(C.nox_xxx_spellCastCleansingFlame_52D5C0, spellID, a2.SObj(), a3.SObj(), a4.SObj(), sa, lvl)
}

func Nox_xxx_castConfuse_52C1E0(spellID spell.ID, a2, a3, a4 *server.Object, sa *server.SpellAcceptArg, lvl int) int {
	return Nox_spells_call_intint6_go(C.nox_xxx_castConfuse_52C1E0, spellID, a2.SObj(), a3.SObj(), a4.SObj(), sa, lvl)
}

func Nox_xxx_castCounterSpell_52BBB0(spellID spell.ID, a2, a3, a4 *server.Object, sa *server.SpellAcceptArg, lvl int) int {
	return Nox_spells_call_intint6_go(C.nox_xxx_castCounterSpell_52BBB0, spellID, a2.SObj(), a3.SObj(), a4.SObj(), sa, lvl)
}

func Nox_xxx_castCurePoison_52CDB0(spellID spell.ID, a2, a3, a4 *server.Object, sa *server.SpellAcceptArg, lvl int) int {
	return Nox_spells_call_intint6_go(C.nox_xxx_castCurePoison_52CDB0, spellID, a2.SObj(), a3.SObj(), a4.SObj(), sa, lvl)
}

func Nox_xxx_castEquake_52DE40(spellID spell.ID, a2, a3, a4 *server.Object, sa *server.SpellAcceptArg, lvl int) int {
	return Nox_spells_call_intint6_go(C.nox_xxx_castEquake_52DE40, spellID, a2.SObj(), a3.SObj(), a4.SObj(), sa, lvl)
}

func Nox_xxx_castFireball_52C790(spellID spell.ID, a2, a3, a4 *server.Object, sa *server.SpellAcceptArg, lvl int) int {
	return Nox_spells_call_intint6_go(C.nox_xxx_castFireball_52C790, spellID, a2.SObj(), a3.SObj(), a4.SObj(), sa, lvl)
}

func Nox_xxx_castFist_52D3C0(spellID spell.ID, a2, a3, a4 *server.Object, sa *server.SpellAcceptArg, lvl int) int {
	return Nox_spells_call_intint6_go(C.nox_xxx_castFist_52D3C0, spellID, a2.SObj(), a3.SObj(), a4.SObj(), sa, lvl)
}

func Nox_xxx_castFumble_52C060(spellID spell.ID, a2, a3, a4 *server.Object, sa *server.SpellAcceptArg, lvl int) int {
	return Nox_spells_call_intint6_go(C.nox_xxx_castFumble_52C060, spellID, a2.SObj(), a3.SObj(), a4.SObj(), sa, lvl)
}

func Sub_52BEB0(spellID spell.ID, a2, a3, a4 *server.Object, sa *server.SpellAcceptArg, lvl int) int {
	return Nox_spells_call_intint6_go(C.sub_52BEB0, spellID, a2.SObj(), a3.SObj(), a4.SObj(), sa, lvl)
}

func Sub_52DD50(spellID spell.ID, a2, a3, a4 *server.Object, sa *server.SpellAcceptArg, lvl int) int {
	return Nox_spells_call_intint6_go(C.sub_52DD50, spellID, a2.SObj(), a3.SObj(), a4.SObj(), sa, lvl)
}

func Nox_xxx_castLock_52CE90(spellID spell.ID, a2, a3, a4 *server.Object, sa *server.SpellAcceptArg, lvl int) int {
	return Nox_spells_call_intint6_go(C.nox_xxx_castLock_52CE90, spellID, a2.SObj(), a3.SObj(), a4.SObj(), sa, lvl)
}

func Sub_52CA80(spellID spell.ID, a2, a3, a4 *server.Object, sa *server.SpellAcceptArg, lvl int) int {
	return Nox_spells_call_intint6_go(C.sub_52CA80, spellID, a2.SObj(), a3.SObj(), a4.SObj(), sa, lvl)
}

func Sub_52CBD0(spellID spell.ID, a2, a3, a4 *server.Object, sa *server.SpellAcceptArg, lvl int) int {
	return Nox_spells_call_intint6_go(C.sub_52CBD0, spellID, a2.SObj(), a3.SObj(), a4.SObj(), sa, lvl)
}

func Nox_xxx_castMeteor_52D9D0(spellID spell.ID, a2, a3, a4 *server.Object, sa *server.SpellAcceptArg, lvl int) int {
	return Nox_spells_call_intint6_go(C.nox_xxx_castMeteor_52D9D0, spellID, a2.SObj(), a3.SObj(), a4.SObj(), sa, lvl)
}

func Nox_xxx_castMeteorShower_52D8A0(spellID spell.ID, a2, a3, a4 *server.Object, sa *server.SpellAcceptArg, lvl int) int {
	return Nox_spells_call_intint6_go(C.nox_xxx_castMeteorShower_52D8A0, spellID, a2.SObj(), a3.SObj(), a4.SObj(), sa, lvl)
}

func Nox_xxx_castPixies_540440(spellID spell.ID, a2, a3, a4 *server.Object, sa *server.SpellAcceptArg, lvl int) int {
	return Nox_spells_call_intint6_go(C.nox_xxx_castPixies_540440, spellID, a2.SObj(), a3.SObj(), a4.SObj(), sa, lvl)
}

func Nox_xxx_castPoison_52C720(spellID spell.ID, a2, a3, a4 *server.Object, sa *server.SpellAcceptArg, lvl int) int {
	return Nox_spells_call_intint6_go(C.nox_xxx_castPoison_52C720, spellID, a2.SObj(), a3.SObj(), a4.SObj(), sa, lvl)
}

func Nox_xxx_castPull_52BFA0(spellID spell.ID, a2, a3, a4 *server.Object, sa *server.SpellAcceptArg, lvl int) int {
	return Nox_spells_call_intint6_go(C.nox_xxx_castPull_52BFA0, spellID, a2.SObj(), a3.SObj(), a4.SObj(), sa, lvl)
}

func Nox_xxx_castPush_52C000(spellID spell.ID, a2, a3, a4 *server.Object, sa *server.SpellAcceptArg, lvl int) int {
	return Nox_spells_call_intint6_go(C.nox_xxx_castPush_52C000, spellID, a2.SObj(), a3.SObj(), a4.SObj(), sa, lvl)
}

func Nox_xxx_castSpellWinkORrestoreHealth_52BF20(spellID spell.ID, a2, a3, a4 *server.Object, sa *server.SpellAcceptArg, lvl int) int {
	return Nox_spells_call_intint6_go(C.nox_xxx_castSpellWinkORrestoreHealth_52BF20, spellID, a2.SObj(), a3.SObj(), a4.SObj(), sa, lvl)
}

func Sub_52BF50(spellID spell.ID, a2, a3, a4 *server.Object, sa *server.SpellAcceptArg, lvl int) int {
	return Nox_spells_call_intint6_go(C.sub_52BF50, spellID, a2.SObj(), a3.SObj(), a4.SObj(), sa, lvl)
}

func Nox_xxx_useShock_52C5A0(spellID spell.ID, a2, a3, a4 *server.Object, sa *server.SpellAcceptArg, lvl int) int {
	return Nox_spells_call_intint6_go(C.nox_xxx_useShock_52C5A0, spellID, a2.SObj(), a3.SObj(), a4.SObj(), sa, lvl)
}

func Nox_xxx_castStun_52C2C0(spellID spell.ID, a2, a3, a4 *server.Object, sa *server.SpellAcceptArg, lvl int) int {
	return Nox_spells_call_intint6_go(C.nox_xxx_castStun_52C2C0, spellID, a2.SObj(), a3.SObj(), a4.SObj(), sa, lvl)
}

func Nox_xxx_castTelekinesis_52D330(spellID spell.ID, a2, a3, a4 *server.Object, sa *server.SpellAcceptArg, lvl int) int {
	return Nox_spells_call_intint6_go(C.nox_xxx_castTelekinesis_52D330, spellID, a2.SObj(), a3.SObj(), a4.SObj(), sa, lvl)
}

func Nox_xxx_castToxicCloud_52DB60(spellID spell.ID, a2, a3, a4 *server.Object, sa *server.SpellAcceptArg, lvl int) int {
	return Nox_spells_call_intint6_go(C.nox_xxx_castToxicCloud_52DB60, spellID, a2.SObj(), a3.SObj(), a4.SObj(), sa, lvl)
}

func Sub_52CCD0(spellID spell.ID, a2, a3, a4 *server.Object, sa *server.SpellAcceptArg, lvl int) int {
	return Nox_spells_call_intint6_go(C.sub_52CCD0, spellID, a2.SObj(), a3.SObj(), a4.SObj(), sa, lvl)
}

func Get_nox_xxx_spellBlink2_530310() unsafe.Pointer {
	return C.nox_xxx_spellBlink2_530310
}

func Get_nox_xxx_spellBlink1_530380() unsafe.Pointer {
	return C.nox_xxx_spellBlink1_530380
}

func Get_sub_52F460() unsafe.Pointer {
	return C.sub_52F460
}

func Get_nox_xxx_charmCreature1_5011F0() unsafe.Pointer {
	return C.nox_xxx_charmCreature1_5011F0
}

func Get_nox_xxx_charmCreatureFinish_5013E0() unsafe.Pointer {
	return C.nox_xxx_charmCreatureFinish_5013E0
}

func Get_nox_xxx_charmCreature2_501690() unsafe.Pointer {
	return C.nox_xxx_charmCreature2_501690
}

func Get_nox_xxx_spellTurnUndeadCreate_531310() unsafe.Pointer {
	return C.nox_xxx_spellTurnUndeadCreate_531310
}

func Get_nox_xxx_spellTurnUndeadUpdate_531410() unsafe.Pointer {
	return C.nox_xxx_spellTurnUndeadUpdate_531410
}

func Get_nox_xxx_spellTurnUndeadDelete_531420() unsafe.Pointer {
	return C.nox_xxx_spellTurnUndeadDelete_531420
}

func Get_nox_xxx_spellDrainMana_52E210() unsafe.Pointer {
	return C.nox_xxx_spellDrainMana_52E210
}

func Get_nox_xxx_spellEnergyBoltStop_52E820() unsafe.Pointer {
	return C.nox_xxx_spellEnergyBoltStop_52E820
}

func Get_nox_xxx_spellEnergyBoltTick_52E850() unsafe.Pointer {
	return C.nox_xxx_spellEnergyBoltTick_52E850
}

func Get_nullsub_29() unsafe.Pointer {
	return C.nullsub_29
}

func Get_nox_xxx_firewalkTick_52ED40() unsafe.Pointer {
	return C.nox_xxx_firewalkTick_52ED40
}

func Get_sub_52EF30() unsafe.Pointer {
	return C.sub_52EF30
}

func Get_sub_52EFD0() unsafe.Pointer {
	return C.sub_52EFD0
}

func Get_sub_52F1D0() unsafe.Pointer {
	return C.sub_52F1D0
}

func Get_sub_52F220() unsafe.Pointer {
	return C.sub_52F220
}

func Get_sub_52F2E0() unsafe.Pointer {
	return C.sub_52F2E0
}

func Get_nox_xxx_onStartLightning_52F820() unsafe.Pointer {
	return C.nox_xxx_onStartLightning_52F820
}

func Get_nox_xxx_onFrameLightning_52F8A0() unsafe.Pointer {
	return C.nox_xxx_onFrameLightning_52F8A0
}

func Get_sub_530100() unsafe.Pointer {
	return C.sub_530100
}

func Get_nox_xxx_castShield1_52F5A0() unsafe.Pointer {
	return C.nox_xxx_castShield1_52F5A0
}

func Get_sub_52F650() unsafe.Pointer {
	return C.sub_52F650
}

func Get_sub_52F670() unsafe.Pointer {
	return C.sub_52F670
}

func Get_nox_xxx_spellCreateMoonglow_531A00() unsafe.Pointer {
	return C.nox_xxx_spellCreateMoonglow_531A00
}

func Get_sub_531AF0() unsafe.Pointer {
	return C.sub_531AF0
}

func Get_nox_xxx_manaBomb_530F90() unsafe.Pointer {
	return C.nox_xxx_manaBomb_530F90
}

func Get_nox_xxx_manaBombBoom_5310C0() unsafe.Pointer {
	return C.nox_xxx_manaBombBoom_5310C0
}

func Get_sub_531290() unsafe.Pointer {
	return C.sub_531290
}

func Get_nox_xxx_plasmaSmth_531580() unsafe.Pointer {
	return C.nox_xxx_plasmaSmth_531580
}

func Get_nox_xxx_plasmaShot_531600() unsafe.Pointer {
	return C.nox_xxx_plasmaShot_531600
}

func Get_sub_5319E0() unsafe.Pointer {
	return C.sub_5319E0
}

func Get_sub_531490() unsafe.Pointer {
	return C.sub_531490
}

func Get_sub_5314F0() unsafe.Pointer {
	return C.sub_5314F0
}

func Get_sub_531560() unsafe.Pointer {
	return C.sub_531560
}

func Get_nox_xxx_summonStart_500DA0() unsafe.Pointer {
	return C.nox_xxx_summonStart_500DA0
}

func Get_nox_xxx_summonFinish_5010D0() unsafe.Pointer {
	return C.nox_xxx_summonFinish_5010D0
}

func Get_nox_xxx_summonCancel_5011C0() unsafe.Pointer {
	return C.nox_xxx_summonCancel_5011C0
}

func Get_sub_530CA0() unsafe.Pointer {
	return C.sub_530CA0
}

func Get_sub_530D30() unsafe.Pointer {
	return C.sub_530D30
}

func Get_nox_xxx_spellTagCreature_530160() unsafe.Pointer {
	return C.nox_xxx_spellTagCreature_530160
}

func Get_sub_530250() unsafe.Pointer {
	return C.sub_530250
}

func Get_sub_530270() unsafe.Pointer {
	return C.sub_530270
}

func Get_sub_5305D0() unsafe.Pointer {
	return C.sub_5305D0
}

func Get_sub_530650() unsafe.Pointer {
	return C.sub_530650
}

func Get_nox_xxx_castTele_530820() unsafe.Pointer {
	return C.nox_xxx_castTele_530820
}

func Get_sub_530880() unsafe.Pointer {
	return C.sub_530880
}

func Get_sub_530A30_spell_execdur() unsafe.Pointer {
	return C.sub_530A30_spell_execdur
}

func Get_nox_xxx_castTTT_530B70() unsafe.Pointer {
	return C.nox_xxx_castTTT_530B70
}

func Get_nox_xxx_spellWallCreate_4FFA90() unsafe.Pointer {
	return C.nox_xxx_spellWallCreate_4FFA90
}

func Get_nox_xxx_spellWallUpdate_500070() unsafe.Pointer {
	return C.nox_xxx_spellWallUpdate_500070
}

func Get_nox_xxx_spellWallDestroy_500080() unsafe.Pointer {
	return C.nox_xxx_spellWallDestroy_500080
}
