package opennox

import (
	"fmt"

	"github.com/noxworld-dev/opennox-lib/spell"
)

type EnchantID byte

func (id EnchantID) String() string {
	name, ok := enchantNames[id]
	if ok {
		return name
	}
	return fmt.Sprintf("EnchantID(%d)", int(id))
}

var enchantByName = make(map[string]EnchantID)

func init() {
	for id, name := range enchantNames {
		enchantByName[name] = id
	}
}

const (
	ENCHANT_INVISIBLE                = EnchantID(0)
	ENCHANT_MOONGLOW                 = EnchantID(1)
	ENCHANT_BLINDED                  = EnchantID(2)
	ENCHANT_CONFUSED                 = EnchantID(3)
	ENCHANT_SLOWED                   = EnchantID(4)
	ENCHANT_HELD                     = EnchantID(5)
	ENCHANT_DETECTING                = EnchantID(6)
	ENCHANT_ETHEREAL                 = EnchantID(7)
	ENCHANT_RUN                      = EnchantID(8)
	ENCHANT_HASTED                   = EnchantID(9)
	ENCHANT_VILLAIN                  = EnchantID(10)
	ENCHANT_AFRAID                   = EnchantID(11)
	ENCHANT_BURNING                  = EnchantID(12)
	ENCHANT_VAMPIRISM                = EnchantID(13)
	ENCHANT_ANCHORED                 = EnchantID(14)
	ENCHANT_LIGHT                    = EnchantID(15)
	ENCHANT_DEATH                    = EnchantID(16)
	ENCHANT_PROTECT_FROM_FIRE        = EnchantID(17)
	ENCHANT_PROTECT_FROM_POISON      = EnchantID(18)
	ENCHANT_PROTECT_FROM_MAGIC       = EnchantID(19)
	ENCHANT_PROTECT_FROM_ELECTRICITY = EnchantID(20)
	ENCHANT_INFRAVISION              = EnchantID(21)
	ENCHANT_SHOCK                    = EnchantID(22)
	ENCHANT_INVULNERABLE             = EnchantID(23)
	ENCHANT_TELEKINESIS              = EnchantID(24)
	ENCHANT_FREEZE                   = EnchantID(25)
	ENCHANT_SHIELD                   = EnchantID(26)
	ENCHANT_REFLECTIVE_SHIELD        = EnchantID(27)
	ENCHANT_CHARMING                 = EnchantID(28)
	ENCHANT_ANTI_MAGIC               = EnchantID(29)
	ENCHANT_CROWN                    = EnchantID(30)
	ENCHANT_SNEAK                    = EnchantID(31)
)

var enchantSpells = map[EnchantID]spell.ID{
	ENCHANT_INVISIBLE:                spell.SPELL_INVISIBILITY,
	ENCHANT_MOONGLOW:                 spell.SPELL_MOONGLOW,
	ENCHANT_BLINDED:                  spell.SPELL_BLIND,
	ENCHANT_CONFUSED:                 spell.SPELL_CONFUSE,
	ENCHANT_SLOWED:                   spell.SPELL_SLOW,
	ENCHANT_HELD:                     spell.SPELL_STUN,
	ENCHANT_DETECTING:                0,
	ENCHANT_ETHEREAL:                 0,
	ENCHANT_RUN:                      spell.SPELL_RUN,
	ENCHANT_HASTED:                   spell.SPELL_HASTE,
	ENCHANT_VILLAIN:                  spell.SPELL_VILLAIN,
	ENCHANT_AFRAID:                   spell.SPELL_FEAR,
	ENCHANT_BURNING:                  0,
	ENCHANT_VAMPIRISM:                spell.SPELL_VAMPIRISM,
	ENCHANT_ANCHORED:                 spell.SPELL_ANCHOR,
	ENCHANT_LIGHT:                    spell.SPELL_LIGHT,
	ENCHANT_DEATH:                    spell.SPELL_DEATH,
	ENCHANT_PROTECT_FROM_FIRE:        spell.SPELL_PROTECTION_FROM_FIRE,
	ENCHANT_PROTECT_FROM_POISON:      spell.SPELL_PROTECTION_FROM_POISON,
	ENCHANT_PROTECT_FROM_MAGIC:       spell.SPELL_PROTECTION_FROM_MAGIC,
	ENCHANT_PROTECT_FROM_ELECTRICITY: spell.SPELL_PROTECTION_FROM_ELECTRICITY,
	ENCHANT_INFRAVISION:              spell.SPELL_INFRAVISION,
	ENCHANT_SHOCK:                    spell.SPELL_SHOCK,
	ENCHANT_INVULNERABLE:             spell.SPELL_INVULNERABILITY,
	ENCHANT_TELEKINESIS:              spell.SPELL_TELEKINESIS,
	ENCHANT_FREEZE:                   spell.SPELL_FREEZE,
	ENCHANT_SHIELD:                   spell.SPELL_SHIELD,
	ENCHANT_REFLECTIVE_SHIELD:        spell.SPELL_OVAL_SHIELD,
	ENCHANT_CHARMING:                 spell.SPELL_CHARM,
	ENCHANT_ANTI_MAGIC:               spell.SPELL_NULLIFY,
	ENCHANT_CROWN:                    0,
	ENCHANT_SNEAK:                    0,
}

var enchantNames = map[EnchantID]string{
	ENCHANT_INVISIBLE:                "ENCHANT_INVISIBLE",
	ENCHANT_MOONGLOW:                 "ENCHANT_MOONGLOW",
	ENCHANT_BLINDED:                  "ENCHANT_BLINDED",
	ENCHANT_CONFUSED:                 "ENCHANT_CONFUSED",
	ENCHANT_SLOWED:                   "ENCHANT_SLOWED",
	ENCHANT_HELD:                     "ENCHANT_HELD",
	ENCHANT_DETECTING:                "ENCHANT_DETECTING",
	ENCHANT_ETHEREAL:                 "ENCHANT_ETHEREAL",
	ENCHANT_RUN:                      "ENCHANT_RUN",
	ENCHANT_HASTED:                   "ENCHANT_HASTED",
	ENCHANT_VILLAIN:                  "ENCHANT_VILLAIN",
	ENCHANT_AFRAID:                   "ENCHANT_AFRAID",
	ENCHANT_BURNING:                  "ENCHANT_BURNING",
	ENCHANT_VAMPIRISM:                "ENCHANT_VAMPIRISM",
	ENCHANT_ANCHORED:                 "ENCHANT_ANCHORED",
	ENCHANT_LIGHT:                    "ENCHANT_LIGHT",
	ENCHANT_DEATH:                    "ENCHANT_DEATH",
	ENCHANT_PROTECT_FROM_FIRE:        "ENCHANT_PROTECT_FROM_FIRE",
	ENCHANT_PROTECT_FROM_POISON:      "ENCHANT_PROTECT_FROM_POISON",
	ENCHANT_PROTECT_FROM_MAGIC:       "ENCHANT_PROTECT_FROM_MAGIC",
	ENCHANT_PROTECT_FROM_ELECTRICITY: "ENCHANT_PROTECT_FROM_ELECTRICITY",
	ENCHANT_INFRAVISION:              "ENCHANT_INFRAVISION",
	ENCHANT_SHOCK:                    "ENCHANT_SHOCK",
	ENCHANT_INVULNERABLE:             "ENCHANT_INVULNERABLE",
	ENCHANT_TELEKINESIS:              "ENCHANT_TELEKINESIS",
	ENCHANT_FREEZE:                   "ENCHANT_FREEZE",
	ENCHANT_SHIELD:                   "ENCHANT_SHIELD",
	ENCHANT_REFLECTIVE_SHIELD:        "ENCHANT_REFLECTIVE_SHIELD",
	ENCHANT_CHARMING:                 "ENCHANT_CHARMING",
	ENCHANT_ANTI_MAGIC:               "ENCHANT_ANTI_MAGIC",
	ENCHANT_CROWN:                    "ENCHANT_CROWN",
	ENCHANT_SNEAK:                    "ENCHANT_SNEAK",
}
