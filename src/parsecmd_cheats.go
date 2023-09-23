package opennox

import (
	"context"
	"strconv"

	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox-lib/console"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/legacy"
)

func init() {
	noxCmdCheat.Register(&console.Command{
		Token:  "health",
		HelpID: "cheathealthhelp",
		Help:   "sets health for the player",
		Flags:  console.Server | console.Cheat,
		Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			return noxCmdSetPlayerUnitParam(c, tokens, "health", (*Object).SetMaxHealth, func(u *Object) {
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
			return noxCmdSetPlayerUnitParam(c, tokens, "mana", (*Object).SetMaxMana, func(u *Object) {
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
				legacy.CheatEquipAll(allow)
				cheatAllowAll = allow
				if allow {
					c.Print(console.ColorLightYellow, "all players are allowed to equip all items")
				} else {
					c.Print(console.ColorLightYellow, "equip restrictions with work as usual")
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
				legacy.CheatCharmAll(allow)
				if allow {
					c.Print(console.ColorLightYellow, "players can charm any creature")
				} else {
					c.Print(console.ColorLightYellow, "charming will work as it should")
				}
			})
		},
	})
	noxCmdCheat.Register(&console.Command{
		Token:  "summon.nolimit",
		HelpID: "cheatsummonnolimit",
		Help:   "allows to summon any number of creatures (UNSTABLE)",
		Flags:  console.Server | console.Cheat,
		Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			return noxCmdSetBool(c, tokens, func(allow bool) {
				cheatSummonNoLimit = allow
				if allow {
					c.Print(console.ColorLightYellow, "players can summon any number of creatures")
					c.Print(console.ColorLightRed, "the game may be unstable with this enabled")
				} else {
					c.Print(console.ColorLightYellow, "summoning will work as it should")
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
					c.Print(console.ColorLightYellow, str)
				} else {
					str := strMan.GetStringInFile("godunset", "parsecmd.c")
					c.Print(console.ColorLightYellow, str)
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
				serverCheatSage(enable, 0)
				if enable {
					str := strMan.GetStringInFile("sageset", "parsecmd.c")
					c.Print(console.ColorLightYellow, str)
				} else {
					str := strMan.GetStringInFile("sageunset", "parsecmd.c")
					c.Print(console.ColorLightYellow, str)
				}
			})
		},
	})
	noxCmdCheat.Register(&console.Command{
		Token:  "spells",
		HelpID: "cheatspellshelp",
		Flags:  console.Server | console.Cheat,
		Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			all := false
			max := 0
			if len(tokens) == 0 {
				max = 1 // compatibility
			}
			if len(tokens) > 0 && tokens[0] == "all" {
				all = true
				tokens = tokens[1:]
			}
			if len(tokens) > 0 {
				if v, err := strconv.Atoi(tokens[0]); err == nil && v > 0 {
					max = v
					tokens = tokens[1:]
				}
			}
			return noxCmdSetBool(c, tokens, func(enable bool) {
				if all {
					serverCheatAllSpells(enable, max)
				} else {
					serverCheatSpells(enable, max)
				}
				if enable {
					str := strMan.GetStringInFile("sageset", "parsecmd.c")
					c.Print(console.ColorLightYellow, str)
				} else {
					str := strMan.GetStringInFile("sageunset", "parsecmd.c")
					c.Print(console.ColorLightYellow, str)
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
					c.Print(console.ColorLightYellow, str)
				} else {
					str := strMan.GetStringInFile("sageunset", "parsecmd.c")
					c.Print(console.ColorLightYellow, str)
				}
			})
		},
	})
	noxCmdCheat.Register(&console.Command{
		Token:  "goto",
		HelpID: "cheatgotohelp",
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
	if err != nil {
		if _, err2 := strconv.ParseUint(tokens[0], 10, 64); err2 == nil {
			err = nil
			v = 999999999 // a lot, but still some space before overflowing int32
		}
	}
	if err != nil {
		c.Print(console.ColorLightRed, "failed to parse the value")
		return true
	}
	for _, u := range noxServer.getPlayerUnits() {
		u.AddGold(v)
	}
	c.Printf(console.ColorLightYellow, "added %d gold to all players", v)
	return true
}

func serverCheatInvincible(enable bool) {
	if noxflags.HasGame(noxflags.GameModeCoop | noxflags.GameModeQuest) {
		if enable {
			noxflags.SetEngine(noxflags.EngineAdmin | noxflags.EngineGodMode)
		} else {
			noxflags.UnsetEngine(noxflags.EngineAdmin | noxflags.EngineGodMode)
		}
	}
}

func serverCheatSage(enable bool, max int) {
	if noxflags.HasGame(noxflags.GameModeCoop | noxflags.GameModeQuest) {
		for _, p := range noxServer.GetPlayers() {
			serverSetAllBeastScrolls(p, enable)
			serverSetAllSpells(p, enable, max)
			serverSetAllWarriorAbilities(p, enable, max)
		}
	}
}

func serverCheatScrolls(enable bool) {
	if noxflags.HasGame(noxflags.GameModeCoop | noxflags.GameModeQuest) {
		for _, p := range noxServer.GetPlayers() {
			serverSetAllBeastScrolls(p, enable)
		}
	}
}

func serverCheatSpells(enable bool, max int) {
	if noxflags.HasGame(noxflags.GameModeCoop | noxflags.GameModeQuest) {
		for _, p := range noxServer.GetPlayers() {
			serverSetAllSpells(p, enable, max)
			serverSetAllWarriorAbilities(p, enable, max)
		}
	}
}

func serverCheatAllSpells(enable bool, max int) {
	serverCheatSage(enable, max)
	if noxflags.HasGame(noxflags.GameModeCoop | noxflags.GameModeQuest) {
		noxServer.Spells.AllowAll = enable
	}
}

func noxCheatSetGod(ctx context.Context, c *console.Console, tokens []string) bool {
	if noxflags.HasGame(noxflags.GameModeCoop | noxflags.GameModeQuest) {
		serverCheatGod(true)
		str := strMan.GetStringInFile("godset", "parsecmd.c")
		c.Print(console.ColorRed, str)
	}
	return true
}

func noxCheatUnsetGod(ctx context.Context, c *console.Console, tokens []string) bool {
	serverCheatGod(false)
	str := strMan.GetStringInFile("godunset", "parsecmd.c")
	c.Print(console.ColorRed, str)
	return true
}

func serverCheatGod(enable bool) {
	if noxflags.HasGame(noxflags.GameModeCoop | noxflags.GameModeQuest) {
		serverCheatInvincible(enable)
		serverCheatSage(enable, 0)
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
			c.Print(console.ColorLightRed, "failed to parse the value")
			return true
		}
		allow = v
	}
	fnc(allow)
	return true
}

func noxCmdSetPlayerUnitParam(c *console.Console, tokens []string, param string, fnc func(u *Object, v int), def func(u *Object)) bool {
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
		c.Print(console.ColorLightRed, "player index must be an integer")
		return nil
	}
	list := noxServer.GetPlayers()
	if ind < 0 || ind >= len(list) {
		c.Printf(console.ColorLightRed, "player index out of range [0-%d]", len(list)-1)
		return nil
	}
	return list[ind]
}

func noxCheatGoto(ctx context.Context, c *console.Console, tokens []string) bool {
	var pos types.Pointf
	switch len(tokens) {
	case 1: // waypoint name
		wp := noxServer.getWaypointByID(tokens[0])
		if wp == nil {
			c.Printf(console.ColorLightRed, "cannot find waypoint %q", tokens[0])
			return true
		}
		pos = wp.Pos()
	case 2: // coordinates
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
		pos = types.Pointf{X: float32(x), Y: float32(y)}
	default:
		c.Print(console.ColorLightRed, "expected two coordinates or a waypoint name")
		return false
	}
	for _, p := range noxServer.GetPlayers() {
		u := p.UnitC()
		if u == nil {
			c.Printf(console.ColorLightRed, "player %q doesn't have a unit", p.Name())
			continue
		}
		u.SetPos(pos)
		c.Printf(console.ColorLightYellow, "teleported player %q to (%v, %v)", p.Name(), pos.X, pos.Y)
	}
	return true
}

func noxCheatSpawn(ctx context.Context, c *console.Console, tokens []string) bool {
	s := noxServer
	cnt := 1
	switch len(tokens) {
	default:
		c.Print(console.ColorLightRed, "expected an object name")
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
	typ := s.Types.ByID(tokens[0])
	if typ == nil {
		c.Printf(console.ColorLightRed, "unknown object: %q", tokens[0])
		return true
	}
	pos := HostPlayer().Pos()
	for i := 0; i < cnt; i++ {
		s.createObject(typ, pos)
	}
	c.Printf(console.ColorLightYellow, "created %q at (%d, %d)", typ.ID(), int(pos.X), int(pos.Y))
	return true
}
