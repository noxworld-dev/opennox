package nox

import (
	"strconv"

	"nox/v1/client/system/parsecmd"
	noxflags "nox/v1/common/flags"
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
		&parsecmd.Command{
			Token:  "god",
			HelpID: "setgodhelp",
			Flags:  parsecmd.Server | parsecmd.Cheat,
			Func: func(c *parsecmd.Console, tokens []string) bool {
				return noxCmdSetBool(c, tokens, func(enable bool) {
					serverCheatInvincible(enable)
					if enable {
						str := strMan.GetStringInFile("godset", "parsecmd.c")
						c.Printf(parsecmd.ColorLightYellow, str)
					} else {
						str := strMan.GetStringInFile("godunset", "parsecmd.c")
						c.Printf(parsecmd.ColorLightYellow, str)
					}
				})
			},
		},
		&parsecmd.Command{
			Token:  "sage",
			HelpID: "setsagehelp",
			Flags:  parsecmd.Server | parsecmd.Cheat,
			Func: func(c *parsecmd.Console, tokens []string) bool {
				return noxCmdSetBool(c, tokens, func(enable bool) {
					serverCheatSage(enable)
					if enable {
						str := strMan.GetStringInFile("sageset", "parsecmd.c")
						c.Printf(parsecmd.ColorLightYellow, str)
					} else {
						str := strMan.GetStringInFile("sageunset", "parsecmd.c")
						c.Printf(parsecmd.ColorLightYellow, str)
					}
				})
			},
		},
		&parsecmd.Command{
			Token:  "spells",
			HelpID: "setsagehelp",
			Flags:  parsecmd.Server | parsecmd.Cheat,
			Func: func(c *parsecmd.Console, tokens []string) bool {
				return noxCmdSetBool(c, tokens, func(enable bool) {
					serverCheatSpells(enable)
					if enable {
						str := strMan.GetStringInFile("sageset", "parsecmd.c")
						c.Printf(parsecmd.ColorLightYellow, str)
					} else {
						str := strMan.GetStringInFile("sageunset", "parsecmd.c")
						c.Printf(parsecmd.ColorLightYellow, str)
					}
				})
			},
		},
		&parsecmd.Command{
			Token:  "scrolls",
			HelpID: "setsagehelp",
			Flags:  parsecmd.Server | parsecmd.Cheat,
			Func: func(c *parsecmd.Console, tokens []string) bool {
				return noxCmdSetBool(c, tokens, func(enable bool) {
					serverCheatScrolls(enable)
					if enable {
						str := strMan.GetStringInFile("sageset", "parsecmd.c")
						c.Printf(parsecmd.ColorLightYellow, str)
					} else {
						str := strMan.GetStringInFile("sageunset", "parsecmd.c")
						c.Printf(parsecmd.ColorLightYellow, str)
					}
				})
			},
		},
	)
	// legacy cheats from set and unset categories
	noxCmdSet.Sub = append(noxCmdSet.Sub,
		&parsecmd.Command{
			Token:  "god",
			HelpID: "setgodhelp",
			Flags:  parsecmd.Server | parsecmd.Cheat,
			Func:   noxCheatSetGod,
		},
	)
	noxCmdUnSet.Sub = append(noxCmdUnSet.Sub,
		&parsecmd.Command{
			Token:  "god",
			HelpID: "unsetgodhelp",
			Flags:  parsecmd.Server,
			Func:   noxCheatUnsetGod,
		},
	)
}

func noxCheatGold(c *parsecmd.Console, tokens []string) bool {
	if len(tokens) != 1 {
		return false
	}
	v, err := strconv.Atoi(tokens[0])
	if _, err2 := strconv.ParseUint(tokens[0], 10, 64); err2 == nil {
		err = nil
		v = 999999999 // a lot, but still some space before overflowing int32
	}
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

func serverCheatInvincible(enable bool) {
	if noxflags.HasGame(noxflags.GameModeSolo12) {
		if enable {
			setEngineFlag(NOX_ENGINE_FLAG_ADMIN | NOX_ENGINE_FLAG_GODMODE)
		} else {
			resetEngineFlag(NOX_ENGINE_FLAG_ADMIN | NOX_ENGINE_FLAG_GODMODE)
		}
	}
}

func serverCheatSage(enable bool) {
	if noxflags.HasGame(noxflags.GameModeSolo12) {
		for _, p := range getPlayers() {
			serverSetAllBeastScrolls(p, enable)
			serverSetAllSpells(p, enable)
			serverSetAllWarriorAbilities(p, enable)
		}
	}
}

func serverCheatScrolls(enable bool) {
	if noxflags.HasGame(noxflags.GameModeSolo12) {
		for _, p := range getPlayers() {
			serverSetAllBeastScrolls(p, enable)
		}
	}
}

func serverCheatSpells(enable bool) {
	if noxflags.HasGame(noxflags.GameModeSolo12) {
		for _, p := range getPlayers() {
			serverSetAllSpells(p, enable)
			serverSetAllWarriorAbilities(p, enable)
		}
	}
}

func noxCheatSetGod(c *parsecmd.Console, tokens []string) bool {
	if !noxflags.HasGame(noxflags.GameModeQuest) {
		serverCheatGod(true)
		str := strMan.GetStringInFile("godset", "parsecmd.c")
		c.Printf(parsecmd.ColorRed, str)
	}
	return true
}

func noxCheatUnsetGod(c *parsecmd.Console, tokens []string) bool {
	serverCheatGod(false)
	str := strMan.GetStringInFile("godunset", "parsecmd.c")
	c.Printf(parsecmd.ColorRed, str)
	return true
}

func serverCheatGod(enable bool) {
	if noxflags.HasGame(noxflags.GameModeSolo12) {
		serverCheatInvincible(enable)
		serverCheatSage(enable)
	}
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
