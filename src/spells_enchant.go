package opennox

import (
	"fmt"

	"github.com/noxworld-dev/opennox-lib/things"
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

var enchantSpells = map[EnchantID]things.SpellID{
	ENCHANT_INVISIBLE:                things.SPELL_INVISIBILITY,
	ENCHANT_MOONGLOW:                 things.SPELL_MOONGLOW,
	ENCHANT_BLINDED:                  things.SPELL_BLIND,
	ENCHANT_CONFUSED:                 things.SPELL_CONFUSE,
	ENCHANT_SLOWED:                   things.SPELL_SLOW,
	ENCHANT_HELD:                     things.SPELL_STUN,
	ENCHANT_DETECTING:                0,
	ENCHANT_ETHEREAL:                 0,
	ENCHANT_RUN:                      things.SPELL_RUN,
	ENCHANT_HASTED:                   things.SPELL_HASTE,
	ENCHANT_VILLAIN:                  things.SPELL_VILLAIN,
	ENCHANT_AFRAID:                   things.SPELL_FEAR,
	ENCHANT_BURNING:                  0,
	ENCHANT_VAMPIRISM:                things.SPELL_VAMPIRISM,
	ENCHANT_ANCHORED:                 things.SPELL_ANCHOR,
	ENCHANT_LIGHT:                    things.SPELL_LIGHT,
	ENCHANT_DEATH:                    things.SPELL_DEATH,
	ENCHANT_PROTECT_FROM_FIRE:        things.SPELL_PROTECTION_FROM_FIRE,
	ENCHANT_PROTECT_FROM_POISON:      things.SPELL_PROTECTION_FROM_POISON,
	ENCHANT_PROTECT_FROM_MAGIC:       things.SPELL_PROTECTION_FROM_MAGIC,
	ENCHANT_PROTECT_FROM_ELECTRICITY: things.SPELL_PROTECTION_FROM_ELECTRICITY,
	ENCHANT_INFRAVISION:              things.SPELL_INFRAVISION,
	ENCHANT_SHOCK:                    things.SPELL_SHOCK,
	ENCHANT_INVULNERABLE:             things.SPELL_INVULNERABILITY,
	ENCHANT_TELEKINESIS:              things.SPELL_TELEKINESIS,
	ENCHANT_FREEZE:                   things.SPELL_FREEZE,
	ENCHANT_SHIELD:                   things.SPELL_SHIELD,
	ENCHANT_REFLECTIVE_SHIELD:        things.SPELL_OVAL_SHIELD,
	ENCHANT_CHARMING:                 things.SPELL_CHARM,
	ENCHANT_ANTI_MAGIC:               things.SPELL_NULLIFY,
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
