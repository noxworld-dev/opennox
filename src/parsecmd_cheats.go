package nox

import (
	"context"
	"strconv"

	"nox/v1/common/console"
	noxflags "nox/v1/common/flags"
	"nox/v1/common/types"
)

func init() {
	noxCmdCheat.Register(&console.Command{
		Token:  "health",
		HelpID: "cheathealthhelp",
		Help:   "sets health for the player",
		Flags:  console.Server | console.Cheat,
		Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			return noxCmdSetPlayerUnitParam(c, tokens, "health", (*Unit).SetMaxHealth, func(u *Unit) {
				_, max := u.Health()
				u.SetHealth(max)
			})
		},
	})
	noxCmdCheat.Register(&console.Command{
		Token:  "mana",
		HelpID: "cheatmanahelp",
		Help:   "sets mana for the player",
		Flags:  console.Server | console.Cheat,
		Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			return noxCmdSetPlayerUnitParam(c, tokens, "mana", (*Unit).SetMaxMana, func(u *Unit) {
				_, max := u.Mana()
				u.SetMana(max)
			})
		},
	})
	noxCmdCheat.Register(&console.Command{
		Token:  "equip.all",
		HelpID: "cheatequipall",
		Help:   "allows to equip all items by all classes",
		Flags:  console.Server | console.Cheat,
		Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			return noxCmdSetBool(c, tokens, func(allow bool) {
				cheatEquipAll(allow)
				if allow {
					c.Printf(console.ColorLightYellow, "all players are allowed to equip all items")
				} else {
					c.Printf(console.ColorLightYellow, "equip restrictions with work as usual")
				}
			})
		},
	})
	noxCmdCheat.Register(&console.Command{
		Token:  "charm.all",
		HelpID: "cheatcharmall",
		Help:   "allows to charm all creatures",
		Flags:  console.Server | console.Cheat,
		Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			return noxCmdSetBool(c, tokens, func(allow bool) {
				cheatCharmAll(allow)
				if allow {
					c.Printf(console.ColorLightYellow, "players can charm any creature")
				} else {
					c.Printf(console.ColorLightYellow, "charming will work as it should")
				}
			})
		},
	})
	noxCmdCheat.Register(&console.Command{
		Token:  "gold",
		HelpID: "cheatgoldhelp",
		Flags:  console.Server | console.Cheat,
		Func:   noxCheatGold,
	})
	noxCmdCheat.Register(&console.Command{
		Token:  "god",
		HelpID: "setgodhelp",
		Flags:  console.Server | console.Cheat,
		Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			return noxCmdSetBool(c, tokens, func(enable bool) {
				serverCheatInvincible(enable)
				if enable {
					str := strMan.GetStringInFile("godset", "parsecmd.c")
					c.Printf(console.ColorLightYellow, str)
				} else {
					str := strMan.GetStringInFile("godunset", "parsecmd.c")
					c.Printf(console.ColorLightYellow, str)
				}
			})
		},
	})
	noxCmdCheat.Register(&console.Command{
		Token:  "sage",
		HelpID: "setsagehelp",
		Flags:  console.Server | console.Cheat,
		Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			return noxCmdSetBool(c, tokens, func(enable bool) {
				serverCheatSage(enable)
				if enable {
					str := strMan.GetStringInFile("sageset", "parsecmd.c")
					c.Printf(console.ColorLightYellow, str)
				} else {
					str := strMan.GetStringInFile("sageunset", "parsecmd.c")
					c.Printf(console.ColorLightYellow, str)
				}
			})
		},
	})
	noxCmdCheat.Register(&console.Command{
		Token:  "spells",
		HelpID: "setsagehelp",
		Flags:  console.Server | console.Cheat,
		Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			return noxCmdSetBool(c, tokens, func(enable bool) {
				serverCheatSpells(enable)
				if enable {
					str := strMan.GetStringInFile("sageset", "parsecmd.c")
					c.Printf(console.ColorLightYellow, str)
				} else {
					str := strMan.GetStringInFile("sageunset", "parsecmd.c")
					c.Printf(console.ColorLightYellow, str)
				}
			})
		},
	})
	noxCmdCheat.Register(&console.Command{
		Token:  "scrolls",
		HelpID: "setsagehelp",
		Flags:  console.Server | console.Cheat,
		Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			return noxCmdSetBool(c, tokens, func(enable bool) {
				serverCheatScrolls(enable)
				if enable {
					str := strMan.GetStringInFile("sageset", "parsecmd.c")
					c.Printf(console.ColorLightYellow, str)
				} else {
					str := strMan.GetStringInFile("sageunset", "parsecmd.c")
					c.Printf(console.ColorLightYellow, str)
				}
			})
		},
	})
	noxCmdCheat.Register(&console.Command{
		Token:  "goto",
		HelpID: "gotohelp",
		Help:   "teleports player to a given location",
		Flags:  console.Server | console.Cheat,
		Func:   noxCheatGoto,
	})
	noxCmdCheat.Register(&console.Command{
		Token:  "spawn",
		HelpID: "spawnhelp",
		Help:   "spawns an item or creature with a given name",
		Flags:  console.Server | console.Cheat,
		Func:   noxCheatSpawn,
	})

	// legacy cheats from set and unset categories
	noxCmdSet.Register(&console.Command{
		Token:  "god",
		HelpID: "setgodhelp",
		Flags:  console.Server | console.Cheat,
		Func:   noxCheatSetGod,
	})
	noxCmdUnSet.Register(&console.Command{
		Token:  "god",
		HelpID: "unsetgodhelp",
		Flags:  console.Server,
		Func:   noxCheatUnsetGod,
	})
}

func noxCheatGold(ctx context.Context, c *console.Console, tokens []string) bool {
	if len(tokens) != 1 {
		return false
	}
	v, err := strconv.Atoi(tokens[0])
	if _, err2 := strconv.ParseUint(tokens[0], 10, 64); err2 == nil {
		err = nil
		v = 999999999 // a lot, but still some space before overflowing int32
	}
	if err != nil {
		c.Printf(console.ColorLightRed, "failed to parse the value")
		return true
	}
	for _, u := range getPlayerUnits() {
		u.AddGold(v)
	}
	c.Printf(console.ColorLightYellow, "added %d gold to all players", v)
	return true
}

func serverCheatInvincible(enable bool) {
	if noxflags.HasGame(noxflags.GameModeCoop) {
		if enable {
			setEngineFlag(NOX_ENGINE_FLAG_ADMIN | NOX_ENGINE_FLAG_GODMODE)
		} else {
			resetEngineFlag(NOX_ENGINE_FLAG_ADMIN | NOX_ENGINE_FLAG_GODMODE)
		}
	}
}

func serverCheatSage(enable bool) {
	if noxflags.HasGame(noxflags.GameModeCoop) {
		for _, p := range getPlayers() {
			serverSetAllBeastScrolls(p, enable)
			serverSetAllSpells(p, enable)
			serverSetAllWarriorAbilities(p, enable)
		}
	}
}

func serverCheatScrolls(enable bool) {
	if noxflags.HasGame(noxflags.GameModeCoop) {
		for _, p := range getPlayers() {
			serverSetAllBeastScrolls(p, enable)
		}
	}
}

func serverCheatSpells(enable bool) {
	if noxflags.HasGame(noxflags.GameModeCoop) {
		for _, p := range getPlayers() {
			serverSetAllSpells(p, enable)
			serverSetAllWarriorAbilities(p, enable)
		}
	}
}

func noxCheatSetGod(ctx context.Context, c *console.Console, tokens []string) bool {
	if !noxflags.HasGame(noxflags.GameModeQuest) {
		serverCheatGod(true)
		str := strMan.GetStringInFile("godset", "parsecmd.c")
		c.Printf(console.ColorRed, str)
	}
	return true
}

func noxCheatUnsetGod(ctx context.Context, c *console.Console, tokens []string) bool {
	serverCheatGod(false)
	str := strMan.GetStringInFile("godunset", "parsecmd.c")
	c.Printf(console.ColorRed, str)
	return true
}

func serverCheatGod(enable bool) {
	if noxflags.HasGame(noxflags.GameModeCoop) {
		serverCheatInvincible(enable)
		serverCheatSage(enable)
	}
}

func noxCmdSetBool(c *console.Console, tokens []string, fnc func(v bool)) bool {
	if len(tokens) > 1 {
		return false
	}
	allow := true
	if len(tokens) == 1 {
		v, err := strconv.ParseBool(tokens[0])
		if err != nil {
			c.Printf(console.ColorLightRed, "failed to parse the value")
			return true
		}
		allow = v
	}
	fnc(allow)
	return true
}

func noxCmdSetPlayerUnitParam(c *console.Console, tokens []string, param string, fnc func(u *Unit, v int), def func(u *Unit)) bool {
	if len(tokens) > 2 {
		return false
	}
	if len(tokens) == 0 {
		p := HostPlayer()
		u := p.UnitC()
		if u == nil {
			c.Printf(console.ColorLightRed, "player %q doesn't have a unit", p.Name())
			return true
		}
		def(u)
		c.Printf(console.ColorLightYellow, "set %q player %s to max", p.Name(), param)
		return true
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
		c.Printf(console.ColorLightRed, "player %q doesn't have a unit", p.Name())
		return true
	}
	v, err := strconv.Atoi(tokens[0])
	if err != nil {
		c.Printf(console.ColorLightRed, "%s must be an integer", param)
		return true
	}
	fnc(u, v)
	c.Printf(console.ColorLightYellow, "set %q player %s to %d", p.Name(), param, v)
	return true
}

func noxCmdPlayerByIndex(c *console.Console, sind string) *Player {
	ind, err := strconv.Atoi(sind)
	if err != nil {
		c.Printf(console.ColorLightRed, "player index must be an integer")
		return nil
	}
	list := getPlayers()
	if ind < 0 || ind >= len(list) {
		c.Printf(console.ColorLightRed, "player index out of range [0-%d]", len(list)-1)
		return nil
	}
	return list[ind]
}

func noxCheatGoto(ctx context.Context, c *console.Console, tokens []string) bool {
	if len(tokens) != 2 {
		c.Printf(console.ColorLightRed, "expected two coordinates")
		return false
	}
	x, err := strconv.Atoi(tokens[0])
	if err != nil {
		c.Printf(console.ColorLightRed, "%s must be an integer", tokens[0])
		return true
	}
	y, err := strconv.Atoi(tokens[1])
	if err != nil {
		c.Printf(console.ColorLightRed, "%s must be an integer", tokens[1])
		return true
	}
	p := HostPlayer()
	u := p.UnitC()
	if u == nil {
		c.Printf(console.ColorLightRed, "player %q doesn't have a unit", p.Name())
		return true
	}
	u.SetPos(types.Pointf{X: float32(x), Y: float32(y)})
	c.Printf(console.ColorLightYellow, "teleported player %q to (%d, %d)", p.Name(), x, y)
	return true
}

func noxCheatSpawn(ctx context.Context, c *console.Console, tokens []string) bool {
	cnt := 1
	switch len(tokens) {
	default:
		c.Printf(console.ColorLightRed, "expected an object name")
		return false
	case 2:
		var err error
		cnt, err = strconv.Atoi(tokens[1])
		if err != nil {
			c.Printf(console.ColorLightRed, "%s must be an integer", tokens[1])
			return true
		}
	case 1:
	}
	typ := getObjectTypeByID(tokens[0])
	if typ == nil {
		c.Printf(console.ColorLightRed, "unknown object: %q", tokens[0])
		return true
	}
	pos := HostPlayer().Pos()
	for i := 0; i < cnt; i++ {
		typ.CreateObject(pos)
	}
	c.Printf(console.ColorLightYellow, "created %q at (%d, %d)", typ.ID(), int(pos.X), int(pos.Y))
	return true
}
