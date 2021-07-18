package main

import (
	"strconv"

	"nox/v1/client/system/parsecmd"
)

func init() {
	noxCmdCheat.Sub = append(noxCmdCheat.Sub,
		&parsecmd.Command{
			Token:  "health",
			HelpID: "cheathealth",
			Help:   "sets health for the player",
			Flags:  parsecmd.Server | parsecmd.Cheat,
			Func: func(c *parsecmd.Console, tokens []string) bool {
				return noxCmdSetPlayerUnitParam(c, tokens, "health", (*Unit).SetMaxHealth)
			},
		},
		&parsecmd.Command{
			Token:  "mana",
			HelpID: "cheatmana",
			Help:   "sets mana for the player",
			Flags:  parsecmd.Server | parsecmd.Cheat,
			Func: func(c *parsecmd.Console, tokens []string) bool {
				return noxCmdSetPlayerUnitParam(c, tokens, "mana", (*Unit).SetMaxMana)
			},
		},
		&parsecmd.Command{
			Token:  "equip.all",
			HelpID: "cheatequipall",
			Help:   "allows to equip all items by all classes",
			Flags:  parsecmd.Server | parsecmd.Cheat,
			Func: func(c *parsecmd.Console, tokens []string) bool {
				return noxCmdSetBool(c, tokens, func(allow bool) {
					cheatEquipAll(allow)
					if allow {
						c.Printf(parsecmd.ColorLightYellow, "all players are allowed to equip all items")
					} else {
						c.Printf(parsecmd.ColorLightYellow, "equip restrictions with work as usual")
					}
				})
			},
		},
		&parsecmd.Command{
			Token:  "charm.all",
			HelpID: "cheatcharmall",
			Help:   "allows to charm all creatures",
			Flags:  parsecmd.Server | parsecmd.Cheat,
			Func: func(c *parsecmd.Console, tokens []string) bool {
				return noxCmdSetBool(c, tokens, func(allow bool) {
					cheatCharmAll(allow)
					if allow {
						c.Printf(parsecmd.ColorLightYellow, "players can charm any creature")
					} else {
						c.Printf(parsecmd.ColorLightYellow, "charming will work as it should")
					}
				})
			},
		},
		&parsecmd.Command{
			Token:  "gold",
			HelpID: "cheatgoldhelp",
			Flags:  parsecmd.Server | parsecmd.Cheat,
			Func:   noxCheatGold,
		},
	)
}

func noxCheatGold(c *parsecmd.Console, tokens []string) bool {
	if len(tokens) != 1 {
		return false
	}
	v, err := strconv.Atoi(tokens[0])
	if err != nil {
		c.Printf(parsecmd.ColorLightRed, "failed to parse the value")
		return true
	}
	for _, u := range getPlayerUnits() {
		u.AddGold(v)
	}
	c.Printf(parsecmd.ColorLightYellow, "added %d gold to all players", v)
	return true
}

func noxCmdSetBool(c *parsecmd.Console, tokens []string, fnc func(v bool)) bool {
	if len(tokens) > 1 {
		return false
	}
	allow := true
	if len(tokens) == 1 {
		v, err := strconv.ParseBool(tokens[0])
		if err != nil {
			c.Printf(parsecmd.ColorLightRed, "failed to parse the value")
			return true
		}
		allow = v
	}
	fnc(allow)
	return true
}

func noxCmdSetPlayerUnitParam(c *parsecmd.Console, tokens []string, param string, fnc func(u *Unit, v int)) bool {
	if len(tokens) == 0 || len(tokens) > 2 {
		return false
	}
	var p *Player
	if len(tokens) == 1 {
		p = HostPlayer()
	} else {
		p = noxCmdPlayerByIndex(c, tokens[0])
		if p == nil {
			return true
		}
		tokens = tokens[1:]
	}
	u := p.UnitC()
	if u == nil {
		c.Printf(parsecmd.ColorLightRed, "player %q doesn't have a unit", p.Name())
		return true
	}
	v, err := strconv.Atoi(tokens[0])
	if err != nil {
		c.Printf(parsecmd.ColorLightRed, "%s must be an integer", param)
		return true
	}
	fnc(u, v)
	c.Printf(parsecmd.ColorLightYellow, "set %q player %s to %d", p.Name(), param, v)
	return true
}

func noxCmdPlayerByIndex(c *parsecmd.Console, sind string) *Player {
	ind, err := strconv.Atoi(sind)
	if err != nil {
		c.Printf(parsecmd.ColorLightRed, "player index must be an integer")
		return nil
	}
	list := getPlayers()
	if ind < 0 || ind >= len(list) {
		c.Printf(parsecmd.ColorLightRed, "player index out of range [0-%d]", len(list)-1)
		return nil
	}
	return list[ind]
}
