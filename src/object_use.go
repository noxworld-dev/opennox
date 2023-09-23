package opennox

import (
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/player"
	"github.com/noxworld-dev/opennox-lib/spell"

	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/server"
)

func nox_xxx_usePotion_53EF70(obj, potion *server.Object) int {
	s := noxServer
	if obj.Class().Has(object.ClassPlayer) && obj.Flags().Has(object.FlagDead) {
		return 0
	}
	consumed := false
	if potion.UseData != nil && potion.SubClass().AsFood().Has(object.FoodHealthPotion) && obj.HealthData != nil && obj.HealthData.Cur < obj.HealthData.Max {
		dhp := int(*(*int32)(potion.UseData))
		if obj.Class().Has(object.ClassPlayer) {
			ud := obj.UpdateDataPlayer()
			switch ud.Player.PlayerClass() {
			case player.Warrior:
				dhp = int(float64(dhp) * float64(legacy.Get_nox_xxx_warriorMaxHealth_587000_312784()))
			case player.Wizard:
				dhp = int(float64(dhp) * float64(legacy.Get_nox_xxx_wizardMaxHealth_587000_312816()))
			case player.Conjurer:
				dhp = int(float64(dhp) * float64(legacy.Get_nox_xxx_conjurerMaxHealth_587000_312800()))
			}
		}
		legacy.Nox_xxx_unitAdjustHP_4EE460(obj, dhp)
		s.AudioEventObj(sound.SoundRestoreHealth, obj, 0, 0)
		consumed = true
	}
	if potion.UseData != nil && potion.SubClass().AsFood().Has(object.FoodManaPotion) && obj.Class().Has(object.ClassPlayer) {
		ud := obj.UpdateDataPlayer()
		if ud.ManaCur < ud.ManaMax {
			dmp := int(*(*int32)(potion.UseData))
			switch ud.Player.PlayerClass() {
			case player.Warrior:
				dmp = int(float64(dmp) * float64(legacy.Get_nox_xxx_warriorMaxMana_587000_312788()))
			case player.Wizard:
				dmp = int(float64(dmp) * float64(legacy.Get_nox_xxx_wizardMaximumMana_587000_312820()))
			case player.Conjurer:
				dmp = int(float64(dmp) * float64(legacy.Get_nox_xxx_conjurerMaxMana_587000_312804()))
			}
			legacy.Nox_xxx_playerManaAdd_4EEB80(obj, dmp)
			s.AudioEventObj(sound.SoundRestoreMana, obj, 0, 0)
			consumed = true
		}
	}
	if potion.SubClass().AsFood().Has(object.FoodCurePoisonPotion) && obj.Class().Has(object.ClassPlayer) && int32(obj.Field540) != 0 {
		legacy.Nox_xxx_removePoison_4EE9D0(obj)
		aud := s.Spells.DefByInd(spell.SPELL_CURE_POISON).GetOnSound()
		s.AudioEventObj(aud, obj, 0, 0)
		consumed = true
	}
	for _, t := range []struct {
		SubClass object.FoodClass
		Enchant  server.EnchantID
	}{
		{object.FoodHastePotion, server.ENCHANT_HASTED},
		{object.FoodInvisibilityPotion, server.ENCHANT_INVISIBLE},
		{object.FoodFireProtectPotion, server.ENCHANT_PROTECT_FROM_FIRE},
		{object.FoodShockProtectPotion, server.ENCHANT_PROTECT_FROM_ELECTRICITY},
		{object.FoodPoisonProtectPotion, server.ENCHANT_PROTECT_FROM_POISON},
		{object.FoodInvulnerabilityPotion, server.ENCHANT_INVULNERABLE},
		{object.FoodInfravisionPotion, server.ENCHANT_INFRAVISION},
		{object.FoodVampirismPotion, server.ENCHANT_VAMPIRISM},
	} {
		if potion.SubClass().AsFood().Has(t.SubClass) {
			legacy.Nox_xxx_buffApplyTo_4FF380(obj, t.Enchant, int(s.SecToFrames(120)), 3)
			consumed = true
		}
	}
	if potion.UseData != nil && potion.SubClass().AsFood().Has(object.FoodShieldPotion) {
		lvl := int(*(*int32)(potion.UseData))
		s.Nox_xxx_spellAccept4FD400(spell.SPELL_SHIELD, obj, obj, obj, &server.SpellAcceptArg{
			Obj: obj,
			Pos: obj.PosVec,
		}, lvl)
		consumed = true
	}
	if consumed {
		s.DelayedDelete(potion)
	}
	return 1
}
