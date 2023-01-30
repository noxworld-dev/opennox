package server

import "strconv"

type Ability int32

func (a Ability) String() string {
	if a >= 0 && int(a) < len(AbilityNames) {
		return AbilityNames[a]
	}
	return "Ability(" + strconv.Itoa(int(a)) + ")"
}

func (a Ability) Valid() bool {
	return a > AbilityInvalid && a < AbilityMax
}

const (
	AbilityInvalid = Ability(iota)
	AbilityBerserk
	AbilityWarcry
	AbilityHarpoon
	AbilityTreadLightly
	AbilityInfravis
	AbilityMax
)

var AbilityNames = []string{
	"ABILITY_INVALID", "ABILITY_BERSERKER_CHARGE", "ABILITY_WARCRY",
	"ABILITY_HARPOON", "ABILITY_TREAD_LIGHTLY", "ABILITY_EYE_OF_THE_WOLF",
}
