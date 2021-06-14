package main

import (
	"strconv"

	"nox/v1/client/system/parsecmd"
)

func init() {
	noxCmdSet.Sub = append(noxCmdSet.Sub,
		&parsecmd.Command{
			Token:  "health",
			HelpID: "sethealth",
			Help:   "sets health for the player",
			Flags:  parsecmd.Server | parsecmd.Cheat,
			Func: func(c *parsecmd.Console, tokens []string) bool {
				return noxCmdSetPlayerUnitParam(c, tokens, "health", (*Unit).SetMaxHealth)
			},
		},
		&parsecmd.Command{
			Token:  "mana",
			HelpID: "setmana",
			Help:   "sets mana for the player",
			Flags:  parsecmd.Server | parsecmd.Cheat,
			Func: func(c *parsecmd.Console, tokens []string) bool {
				return noxCmdSetPlayerUnitParam(c, tokens, "mana", (*Unit).SetMaxMana)
			},
		},
	)
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
