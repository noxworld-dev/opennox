package opennox

import (
	"context"

	"github.com/noxworld-dev/opennox-lib/log"
	"github.com/noxworld-dev/opennox-lib/strman"

	"github.com/noxworld-dev/opennox-lib/console"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/legacy"
)

var (
	consoleMux = console.NewMultiPrinter(
		console.LogPrinter(log.New("console")),
	)
	noxConsole = console.New(consoleMux)
)

func initConsole(sm *strman.StringManager) {
	noxConsole.Localize(sm, "on", "off", "force", "ctf", "coop", "team", "respawn", "all")
}

func init() {
	noxConsole.SetExec(execConsoleCmd)
	for _, c := range noxCommands {
		noxConsole.Register(c)
	}
}

var (
	noxCmdList = &console.Command{Token: "list", HelpID: "listhelp", Flags: console.ClientServer, Sub: []*console.Command{
		{Token: "maps", HelpID: "listmapshelp", Flags: console.ClientServer, LegacyFunc: legacy.WrapCommandC(legacy.Nox_cmd_list_maps)},
		{Token: "users", HelpID: "listusershelp", Flags: console.ClientServer, LegacyFunc: legacy.WrapCommandC(legacy.Nox_cmd_list_users)},
	}}
	noxCmdSet = &console.Command{Token: "set", HelpID: "sethelp", Flags: console.ClientServer, Sub: []*console.Command{
		{Token: "cycle", HelpID: "setcyclehelp", Flags: console.Server, LegacyFunc: legacy.WrapCommandC(legacy.Nox_cmd_set_cycle)},
		{Token: "frameratelimiter", HelpID: "setfrhelp", Flags: console.Server | console.Cheat, Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			if len(tokens) != 0 {
				return false
			}
			setEnableFrameLimit(true)
			return true
		}},
		{Token: "lessons", HelpID: "setlessonshelp", Flags: console.Server, LegacyFunc: legacy.WrapCommandC(legacy.Nox_cmd_set_lessons)},
		{Token: "monsters", HelpID: "setmnstrshelp", Flags: console.Server | console.Cheat, LegacyFunc: legacy.WrapCommandC(legacy.Nox_cmd_set_mnstrs)},
		{Token: "name", HelpID: "setnamehelp", Flags: console.Server, LegacyFunc: legacy.WrapCommandC(legacy.Nox_cmd_set_name)},
		{Token: "netdebug", HelpID: "setnetdebughelp", Flags: console.ClientServer | console.Cheat, LegacyFunc: legacy.WrapCommandC(legacy.Nox_cmd_set_net_debug)},
		{Token: "ob", HelpID: "setobshelp", Flags: console.ClientServer | console.Cheat, Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			cur := console.CurCommand(ctx)
			s := c.Strings().GetStringInFile("processingobs", "parsecmd.c")
			c.Print(console.ColorRed, s)
			if noxflags.HasGame(noxflags.GameHost) {
				nox_xxx_serverHandleClientConsole_443E90(clientPlayer(), 0, cur)
			} else {
				nox_xxx_netServerCmd_440950(0, cur)
			}
			return true
		}},
		{Token: "players", HelpID: "setplayershelp", Flags: console.Server, LegacyFunc: legacy.WrapCommandC(legacy.Nox_cmd_set_players)},
		{Token: "quality", HelpID: "setqualityhelp", Flags: console.ClientServer, Sub: []*console.Command{
			{Token: "modem", HelpID: "setqualmodemhelp", Flags: console.ClientServer, LegacyFunc: legacy.WrapCommandC(legacy.Nox_cmd_set_qual_modem)},
			{Token: "isdn", HelpID: "setqualisdnhelp", Flags: console.ClientServer, LegacyFunc: legacy.WrapCommandC(legacy.Nox_cmd_set_qual_isdn)},
			{Token: "cable", HelpID: "setqualcablehelp", Flags: console.ClientServer, LegacyFunc: legacy.WrapCommandC(legacy.Nox_cmd_set_qual_cable)},
			{Token: "T1", HelpID: "setqualT1help", Flags: console.ClientServer, LegacyFunc: legacy.WrapCommandC(legacy.Nox_cmd_set_qual_t1)},
			{Token: "LAN", HelpID: "setqualLANhelp", Flags: console.ClientServer, LegacyFunc: legacy.WrapCommandC(legacy.Nox_cmd_set_qual_lan)},
		}},
		{Token: "savedebugcmd", HelpID: "setsavedebughelp", Flags: console.Server, Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			noxflags.SetEngine(noxflags.EngineSaveDebug)
			s := c.Strings().GetStringInFile("savedebugset", "parsecmd.c")
			c.Print(console.ColorRed, s)
			return true
		}},
		{Token: "spell", HelpID: "setspellhelp", Flags: console.Server, LegacyFunc: legacy.WrapCommandC(legacy.Nox_cmd_set_spell)},
		{Token: "spellpoints", HelpID: "setspellptshelp", Flags: console.Server | console.Cheat, LegacyFunc: legacy.WrapCommandC(legacy.Nox_cmd_set_spellpts)},
		{Token: "staffs", HelpID: "setstaffshelp", Flags: console.Server | console.Cheat, LegacyFunc: legacy.WrapCommandC(legacy.Nox_cmd_set_staffs)},
		{Token: "sysop", HelpID: "setsysophelp", Flags: console.Server, LegacyFunc: legacy.WrapCommandC(legacy.Nox_cmd_set_sysop)},
		{Token: "time", HelpID: "settimehelp", Flags: console.Server, LegacyFunc: legacy.WrapCommandC(legacy.Nox_cmd_set_time)},
		{Token: "weapons", HelpID: "setweaponshelp", Flags: console.Server | console.Cheat, LegacyFunc: legacy.WrapCommandC(legacy.Nox_cmd_set_weapons)},
		{Token: "team", HelpID: "officialonly", Flags: console.Server | console.Cheat | console.FlagDedicated, LegacyFunc: legacy.WrapCommandC(legacy.Nox_cmd_offonly1)},
		{Token: "mode", HelpID: "officialonly", Flags: console.Server | console.Cheat | console.FlagDedicated, LegacyFunc: legacy.WrapCommandC(legacy.Nox_cmd_offonly2)},
	}}
	noxCmdUnSet = &console.Command{Token: "unset", HelpID: "unsethelp", Flags: console.ClientServer, Sub: []*console.Command{
		{Token: "frameratelimiter", HelpID: "unsetfrhelp", Flags: console.Server, Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			if len(tokens) != 0 {
				return false
			}
			setEnableFrameLimit(false)
			return true
		}},
		{Token: "netdebug", HelpID: "unsetnetdebug", Flags: console.ClientServer, LegacyFunc: legacy.WrapCommandC(legacy.Nox_cmd_unset_net_debug)},
	}}
	noxCmdShow = &console.Command{Token: "show", HelpID: "showhelp", Flags: console.ClientServer, Sub: []*console.Command{
		{
			Token:  "bindings",
			HelpID: "showbindingshelp",
			Flags:  console.ClientServer,
			Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
				if len(tokens) != 0 {
					return false
				}
				return c.Exec(ctx, "bindings")
			},
		},
		{Token: "motd", HelpID: "showmotdhelp", Flags: console.ClientServer, LegacyFunc: legacy.WrapCommandC(legacy.Nox_cmd_show_motd)},
		{Token: "rank", HelpID: "showrankhelp", Flags: console.ClientServer, LegacyFunc: legacy.WrapCommandC(legacy.Nox_cmd_show_rank)},
		{Token: "extents", HelpID: "showextentshelp", Flags: console.ClientServer | console.Cheat, Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			clientPlaySoundSpecial(sound.SoundShellClick, 100)
			noxflags.ToggleEngine(noxflags.EngineShowExtents)
			return true
		}},
		{Token: "ai", HelpID: "showaihelp", Flags: console.Server | console.Cheat, Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			noxflags.ToggleEngine(noxflags.EngineShowAI)
			return true
		}},
		{Token: "info", HelpID: "showinfohelp", Flags: console.ClientServer | console.NoHelp, LegacyFunc: legacy.WrapCommandC(legacy.Nox_cmd_show_info)},
		{Token: "mem", HelpID: "showmemhelp", Flags: console.ClientServer | console.Cheat, LegacyFunc: legacy.WrapCommandC(legacy.Nox_cmd_show_mem)},
		{Token: "netstat", HelpID: "shownetstathelp", Flags: console.ClientServer, Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			sub_470A60()
			return true
		}},
		{Token: "seq", HelpID: "showseqhelp", Flags: console.ClientServer | console.Cheat, LegacyFunc: legacy.WrapCommandC(legacy.Nox_cmd_show_seq)},
	}}
	noxCmdCheat = &console.Command{Token: "cheat", HelpID: "cheathelp", Flags: console.Server | console.Cheat, Sub: []*console.Command{
		{Token: "ability", HelpID: "cheatabilityhelp", Flags: console.Server, LegacyFunc: legacy.WrapCommandC(legacy.Nox_cmd_cheat_ability)},
		{Token: "level", HelpID: "cheatlevelhelp", Flags: console.Server, LegacyFunc: legacy.WrapCommandC(legacy.Nox_cmd_cheat_level)},
		{Token: "re-enter", HelpID: "", Flags: console.Server, LegacyFunc: legacy.WrapCommandC(legacy.Nox_cmd_reenter)},
	}}
	noxCommands = []*console.Command{
		noxCmdList,
		noxCmdSet,
		noxCmdUnSet,
		noxCmdShow,
		noxCmdCheat,
		{Token: "allow", HelpID: "allowhelp", Flags: console.Server, Sub: []*console.Command{
			{Token: "user", HelpID: "allowuserhelp", Flags: console.Server, LegacyFunc: legacy.WrapCommandC(legacy.Nox_cmd_allow_user)},
			{Token: "IP", HelpID: "allowiphelp", Flags: console.Server, LegacyFunc: legacy.WrapCommandC(legacy.Nox_cmd_allow_ip)},
		}},
		{Token: "audtest", HelpID: "sethelp", Flags: console.ClientServer, Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			return true
		}},
		{Token: "ban", HelpID: "banhelp", Flags: console.Server, LegacyFunc: legacy.WrapCommandC(legacy.Nox_cmd_ban)},
		{Token: "execrul", HelpID: "execrulhelp", Flags: console.ClientServer, LegacyFunc: legacy.WrapCommandC(legacy.Nox_cmd_exec_rul)},
		{Token: "exit", HelpID: "exithelp", Flags: console.ClientServer, Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			if noxflags.HasGame(noxflags.GameModeQuest) && noxflags.HasGame(noxflags.GameHost) {
				sub_4D6B10(false)
			}
			if noxflags.HasGame(noxflags.GameFlag26) {
				nox_client_quit_4460C0()
			}
			nox_game_exit_xxx2()
			return true
		}},
		{Token: "kick", HelpID: "kickhelp", Flags: console.Server, LegacyFunc: legacy.WrapCommandC(legacy.Nox_cmd_kick)},
		{Token: "log", HelpID: "loghelp", Flags: console.ClientServer | console.Cheat, Sub: []*console.Command{
			{Token: "console", HelpID: "logconsolehelp", Flags: console.ClientServer, Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
				if len(tokens) != 0 {
					return false
				}
				noxflags.SetEngine(noxflags.EngineLogToConsole)
				return true
			}},
			{Token: "file", HelpID: "logfilehelp", Flags: console.ClientServer, Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
				return true
			}},
			{Token: "stop", HelpID: "logstophelp", Flags: console.ClientServer, Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
				return true
			}},
		}},
		{Token: "menu", HelpID: "menuhelp", Flags: console.ClientServer, Sub: []*console.Command{
			{Token: "vidopt", HelpID: "menuvidopthelp", Flags: console.ClientServer, LegacyFunc: legacy.WrapCommandC(legacy.Nox_cmd_menu_vidopt)},
			{Token: "options", HelpID: "menuoptionshelp", Flags: console.ClientServer, LegacyFunc: legacy.WrapCommandC(legacy.Nox_cmd_menu_options)},
		}},
		{Token: "mute", HelpID: "mutehelp", Flags: console.ClientServer, LegacyFunc: legacy.WrapCommandC(legacy.Nox_cmd_mute)},
		{Token: "quit", HelpID: "quithelp", Flags: console.ClientServer, Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			nox_client_quit_4460C0()
			return true
		}},
		{Token: "unmute", HelpID: "unmutehelp", Flags: console.ClientServer, LegacyFunc: legacy.WrapCommandC(legacy.Nox_cmd_unmute)},
		{Token: "window", HelpID: "windowhelp", Flags: console.ClientServer, LegacyFunc: legacy.WrapCommandC(legacy.Nox_cmd_window)},
	}
)
