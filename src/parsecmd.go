package opennox

/*
#include <stddef.h>
extern unsigned int nox_client_consoleIsServer_823684;
extern int nox_cheat_allowall;
extern int nox_cheat_charmall;
extern int nox_cheat_summon_nolimit;

void nox_xxx_consoleTokenAddPair_4444C0(wchar_t* tok, wchar_t* tok2);
int nox_gui_console_Print_450B90(unsigned char typ, wchar_t* str);
int  sub_4D6B10(int a1);

int nox_cmd_set_sysop(int, int, wchar_t**);
int nox_cmd_show_game(int, int, wchar_t**);
int nox_cmd_set_cycle(int, int, wchar_t**);
int nox_cmd_set_weapons(int, int, wchar_t**);
int nox_cmd_set_staffs(int, int, wchar_t**);
int nox_cmd_set_name(int, int, wchar_t**);
int nox_cmd_set_mnstrs(int, int, wchar_t**);
int nox_cmd_set_spell(int, int, wchar_t**);
int nox_cmd_set_weapon(int, int, wchar_t**);
int nox_cmd_set_armor(int, int, wchar_t**);
int nox_cmd_set_staff(int, int, wchar_t**);
int nox_cmd_ban(int, int, wchar_t**);
int nox_cmd_allow_user(int, int, wchar_t**);
int nox_cmd_allow_ip(int, int, wchar_t**);
int nox_cmd_kick(int, int, wchar_t**);
int nox_cmd_set_players(int, int, wchar_t**);
int nox_cmd_set_spellpts(int, int, wchar_t**);
int nox_cmd_list_users(int, int, wchar_t**);
int nox_cmd_unmute(int, int, wchar_t**);
int nox_cmd_mute(int, int, wchar_t**);
int nox_cmd_exec_rul(int, int, wchar_t**);
int nox_cmd_offonly1(int, int, wchar_t**);
int nox_cmd_offonly2(int, int, wchar_t**);
int nox_cmd_set_fr(int, int, wchar_t**);
int nox_cmd_unset_fr(int, int, wchar_t**);
int nox_cmd_set_net_debug(int, int, wchar_t**);
int nox_cmd_unset_net_debug(int, int, wchar_t**);
int nox_cmd_show_gui(int, int, wchar_t**);
int nox_cmd_show_netstat(int, int, wchar_t**);
int nox_cmd_show_info(int, int, wchar_t**);
int nox_cmd_show_mem(int, int, wchar_t**);
int nox_cmd_show_rank(int, int, wchar_t**);
int nox_cmd_show_motd(int, int, wchar_t**);
int nox_cmd_show_seq(int, int, wchar_t**);
int nox_cmd_list_maps(int, int, wchar_t**);
int nox_cmd_cheat_ability(int, int, wchar_t**);
int nox_cmd_cheat_level(int, int, wchar_t**);
int nox_cmd_cheat_gold(int, int, wchar_t**);
int nox_cmd_window(int, int, wchar_t**);
int nox_cmd_set_qual_modem(int, int, wchar_t**);
int nox_cmd_set_qual_isdn(int, int, wchar_t**);
int nox_cmd_set_qual_cable(int, int, wchar_t**);
int nox_cmd_set_qual_t1(int, int, wchar_t**);
int nox_cmd_set_qual_lan(int, int, wchar_t**);
int nox_cmd_set_time(int, int, wchar_t**);
int nox_cmd_set_lessons(int, int, wchar_t**);
int nox_cmd_menu_options(int, int, wchar_t**);
int nox_cmd_menu_vidopt(int, int, wchar_t**);
int nox_cmd_reenter(int, int, wchar_t**);
*/
import "C"
import (
	"context"

	"github.com/noxworld-dev/opennox-lib/log"
	"github.com/noxworld-dev/opennox-lib/strman"

	"github.com/noxworld-dev/opennox-lib/console"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/sound"
)

var (
	consoleMux = console.NewMultiPrinter(
		console.LogPrinter(log.New("console")),
	)
	noxConsole = console.New(consoleMux)
)

func cheatEquipAll(v bool) {
	C.nox_cheat_allowall = C.int(bool2int(v))
}

func cheatCharmAll(v bool) {
	C.nox_cheat_charmall = C.int(bool2int(v))
}

func cheatSummonNoLimit(v bool) {
	C.nox_cheat_summon_nolimit = C.int(bool2int(v))
}

func initConsole(sm *strman.StringManager) {
	noxConsole.Localize(sm, "on", "off", "force", "ctf", "coop", "team", "respawn", "all")
}

func wrapCommandC(cfnc func(C.int, C.int, **C.wchar_t) C.int) console.CommandLegacyFunc {
	return func(ctx context.Context, c *console.Console, tokInd int, tokens []string) bool {
		C.nox_client_consoleIsServer_823684 = C.uint(bool2int(!console.IsClient(ctx)))
		ctokens, free := CWStrSlice(tokens)
		defer free()
		var ptr **C.wchar_t
		if len(ctokens) > 0 {
			ptr = &ctokens[0]
		}
		return cfnc(C.int(tokInd), C.int(len(tokens)), ptr) != 0
	}
}

func init() {
	noxConsole.SetExec(execConsoleCmd)
	for _, c := range noxCommands {
		noxConsole.Register(c)
	}
}

var (
	noxCmdList = &console.Command{Token: "list", HelpID: "listhelp", Flags: console.ClientServer, Sub: []*console.Command{
		{Token: "maps", HelpID: "listmapshelp", Flags: console.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_list_maps)},
		{Token: "users", HelpID: "listusershelp", Flags: console.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_list_users)},
	}}
	noxCmdSet = &console.Command{Token: "set", HelpID: "sethelp", Flags: console.ClientServer, Sub: []*console.Command{
		{Token: "armor", HelpID: "setarmorhelp", Flags: console.Server, LegacyFunc: wrapCommandC(nox_cmd_set_armor)},
		{Token: "cycle", HelpID: "setcyclehelp", Flags: console.Server, LegacyFunc: wrapCommandC(nox_cmd_set_cycle)},
		{Token: "frameratelimiter", HelpID: "setfrhelp", Flags: console.Server | console.Cheat, LegacyFunc: wrapCommandC(nox_cmd_set_fr)},
		{Token: "lessons", HelpID: "setlessonshelp", Flags: console.Server, LegacyFunc: wrapCommandC(nox_cmd_set_lessons)},
		{Token: "monsters", HelpID: "setmnstrshelp", Flags: console.Server | console.Cheat, LegacyFunc: wrapCommandC(nox_cmd_set_mnstrs)},
		{Token: "name", HelpID: "setnamehelp", Flags: console.Server, LegacyFunc: wrapCommandC(nox_cmd_set_name)},
		{Token: "netdebug", HelpID: "setnetdebughelp", Flags: console.ClientServer | console.Cheat, LegacyFunc: wrapCommandC(nox_cmd_set_net_debug)},
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
		{Token: "players", HelpID: "setplayershelp", Flags: console.Server, LegacyFunc: wrapCommandC(nox_cmd_set_players)},
		{Token: "quality", HelpID: "setqualityhelp", Flags: console.ClientServer, Sub: []*console.Command{
			{Token: "modem", HelpID: "setqualmodemhelp", Flags: console.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_set_qual_modem)},
			{Token: "isdn", HelpID: "setqualisdnhelp", Flags: console.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_set_qual_isdn)},
			{Token: "cable", HelpID: "setqualcablehelp", Flags: console.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_set_qual_cable)},
			{Token: "T1", HelpID: "setqualT1help", Flags: console.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_set_qual_t1)},
			{Token: "LAN", HelpID: "setqualLANhelp", Flags: console.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_set_qual_lan)},
		}},
		{Token: "savedebugcmd", HelpID: "setsavedebughelp", Flags: console.Server, Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			noxflags.SetEngine(noxflags.EngineSaveDebug)
			s := c.Strings().GetStringInFile("savedebugset", "parsecmd.c")
			c.Print(console.ColorRed, s)
			return true
		}},
		{Token: "spell", HelpID: "setspellhelp", Flags: console.Server, LegacyFunc: wrapCommandC(nox_cmd_set_spell)},
		{Token: "spellpoints", HelpID: "setspellptshelp", Flags: console.Server | console.Cheat, LegacyFunc: wrapCommandC(nox_cmd_set_spellpts)},
		{Token: "staff", HelpID: "setstaffhelp", Flags: console.Server | console.Cheat, LegacyFunc: wrapCommandC(nox_cmd_set_staff)},
		{Token: "staffs", HelpID: "setstaffshelp", Flags: console.Server | console.Cheat, LegacyFunc: wrapCommandC(nox_cmd_set_staffs)},
		{Token: "sysop", HelpID: "setsysophelp", Flags: console.Server, LegacyFunc: wrapCommandC(nox_cmd_set_sysop)},
		{Token: "time", HelpID: "settimehelp", Flags: console.Server, LegacyFunc: wrapCommandC(nox_cmd_set_time)},
		{Token: "weapon", HelpID: "setweaponhelp", Flags: console.Server, LegacyFunc: wrapCommandC(nox_cmd_set_weapon)},
		{Token: "weapons", HelpID: "setweaponshelp", Flags: console.Server | console.Cheat, LegacyFunc: wrapCommandC(nox_cmd_set_weapons)},
		{Token: "team", HelpID: "officialonly", Flags: console.Server | console.Cheat | console.FlagDedicated, LegacyFunc: wrapCommandC(nox_cmd_offonly1)},
		{Token: "mode", HelpID: "officialonly", Flags: console.Server | console.Cheat | console.FlagDedicated, LegacyFunc: wrapCommandC(nox_cmd_offonly2)},
	}}
	noxCmdUnSet = &console.Command{Token: "unset", HelpID: "unsethelp", Flags: console.ClientServer, Sub: []*console.Command{
		{Token: "frameratelimiter", HelpID: "unsetfrhelp", Flags: console.Server, LegacyFunc: wrapCommandC(nox_cmd_unset_fr)},
		{Token: "netdebug", HelpID: "unsetnetdebug", Flags: console.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_unset_net_debug)},
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
		{Token: "game", HelpID: "showgamehelp", Flags: console.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_show_game)},
		{Token: "motd", HelpID: "showmotdhelp", Flags: console.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_show_motd)},
		{Token: "rank", HelpID: "showrankhelp", Flags: console.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_show_rank)},
		{Token: "extents", HelpID: "showextentshelp", Flags: console.ClientServer | console.Cheat, Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			clientPlaySoundSpecial(sound.SoundShellClick, 100)
			noxflags.ToggleEngine(noxflags.EngineShowExtents)
			return true
		}},
		{Token: "gui", HelpID: "showguihelp", Flags: console.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_show_gui)},
		{Token: "ai", HelpID: "showaihelp", Flags: console.Server | console.Cheat, Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			noxflags.ToggleEngine(noxflags.EngineShowAI)
			return true
		}},
		{Token: "info", HelpID: "showinfohelp", Flags: console.ClientServer | console.NoHelp, LegacyFunc: wrapCommandC(nox_cmd_show_info)},
		{Token: "mem", HelpID: "showmemhelp", Flags: console.ClientServer | console.Cheat, LegacyFunc: wrapCommandC(nox_cmd_show_mem)},
		{Token: "netstat", HelpID: "shownetstathelp", Flags: console.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_show_netstat)},
		{Token: "seq", HelpID: "showseqhelp", Flags: console.ClientServer | console.Cheat, LegacyFunc: wrapCommandC(nox_cmd_show_seq)},
	}}
	noxCmdCheat = &console.Command{Token: "cheat", HelpID: "cheathelp", Flags: console.Server | console.Cheat, Sub: []*console.Command{
		{Token: "ability", HelpID: "cheatabilityhelp", Flags: console.Server, LegacyFunc: wrapCommandC(nox_cmd_cheat_ability)},
		{Token: "level", HelpID: "cheatlevelhelp", Flags: console.Server, LegacyFunc: wrapCommandC(nox_cmd_cheat_level)},
		{Token: "re-enter", HelpID: "", Flags: console.Server, LegacyFunc: wrapCommandC(nox_cmd_reenter)},
	}}
	noxCommands = []*console.Command{
		noxCmdList,
		noxCmdSet,
		noxCmdUnSet,
		noxCmdShow,
		noxCmdCheat,
		{Token: "allow", HelpID: "allowhelp", Flags: console.Server, Sub: []*console.Command{
			{Token: "user", HelpID: "allowuserhelp", Flags: console.Server, LegacyFunc: wrapCommandC(nox_cmd_allow_user)},
			{Token: "IP", HelpID: "allowiphelp", Flags: console.Server, LegacyFunc: wrapCommandC(nox_cmd_allow_ip)},
		}},
		{Token: "audtest", HelpID: "sethelp", Flags: console.ClientServer, Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			return true
		}},
		{Token: "ban", HelpID: "banhelp", Flags: console.Server, LegacyFunc: wrapCommandC(nox_cmd_ban)},
		{Token: "execrul", HelpID: "execrulhelp", Flags: console.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_exec_rul)},
		{Token: "exit", HelpID: "exithelp", Flags: console.ClientServer, Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			if noxflags.HasGame(noxflags.GameModeQuest) && noxflags.HasGame(noxflags.GameHost) {
				C.sub_4D6B10(0)
			}
			if noxflags.HasGame(noxflags.GameFlag26) {
				nox_client_quit_4460C0()
			}
			nox_xxx_setContinueMenuOrHost_43DDD0(0)
			nox_game_exit_xxx_43DE60()
			return true
		}},
		{Token: "kick", HelpID: "kickhelp", Flags: console.Server, LegacyFunc: wrapCommandC(nox_cmd_kick)},
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
			{Token: "vidopt", HelpID: "menuvidopthelp", Flags: console.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_menu_vidopt)},
			{Token: "options", HelpID: "menuoptionshelp", Flags: console.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_menu_options)},
		}},
		{Token: "mute", HelpID: "mutehelp", Flags: console.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_mute)},
		{Token: "quit", HelpID: "quithelp", Flags: console.ClientServer, Func: func(ctx context.Context, c *console.Console, tokens []string) bool {
			nox_client_quit_4460C0()
			return true
		}},
		{Token: "unmute", HelpID: "unmutehelp", Flags: console.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_unmute)},
		{Token: "window", HelpID: "windowhelp", Flags: console.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_window)},
	}
)

func nox_cmd_set_sysop(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_set_sysop(i, n, arr)
}
func nox_cmd_show_game(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_show_game(i, n, arr)
}
func nox_cmd_set_cycle(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_set_cycle(i, n, arr)
}
func nox_cmd_set_weapons(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_set_weapons(i, n, arr)
}
func nox_cmd_set_staffs(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_set_staffs(i, n, arr)
}
func nox_cmd_set_name(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_set_name(i, n, arr)
}
func nox_cmd_set_mnstrs(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_set_mnstrs(i, n, arr)
}
func nox_cmd_set_spell(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_set_spell(i, n, arr)
}
func nox_cmd_set_weapon(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_set_weapon(i, n, arr)
}
func nox_cmd_set_armor(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_set_armor(i, n, arr)
}
func nox_cmd_set_staff(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_set_staff(i, n, arr)
}
func nox_cmd_ban(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_ban(i, n, arr)
}
func nox_cmd_allow_user(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_allow_user(i, n, arr)
}
func nox_cmd_allow_ip(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_allow_ip(i, n, arr)
}
func nox_cmd_kick(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_kick(i, n, arr)
}
func nox_cmd_set_players(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_set_players(i, n, arr)
}
func nox_cmd_set_spellpts(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_set_spellpts(i, n, arr)
}
func nox_cmd_list_users(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_list_users(i, n, arr)
}
func nox_cmd_unmute(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_unmute(i, n, arr)
}
func nox_cmd_mute(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_mute(i, n, arr)
}
func nox_cmd_exec_rul(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_exec_rul(i, n, arr)
}
func nox_cmd_offonly1(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_offonly1(i, n, arr)
}
func nox_cmd_offonly2(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_offonly2(i, n, arr)
}
func nox_cmd_set_fr(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_set_fr(i, n, arr)
}
func nox_cmd_unset_fr(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_unset_fr(i, n, arr)
}
func nox_cmd_set_net_debug(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_set_net_debug(i, n, arr)
}
func nox_cmd_unset_net_debug(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_unset_net_debug(i, n, arr)
}
func nox_cmd_show_gui(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_show_gui(i, n, arr)
}
func nox_cmd_show_netstat(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_show_netstat(i, n, arr)
}
func nox_cmd_show_info(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_show_info(i, n, arr)
}
func nox_cmd_show_mem(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_show_mem(i, n, arr)
}
func nox_cmd_show_rank(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_show_rank(i, n, arr)
}
func nox_cmd_show_motd(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_show_motd(i, n, arr)
}
func nox_cmd_show_seq(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_show_seq(i, n, arr)
}
func nox_cmd_list_maps(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_list_maps(i, n, arr)
}
func nox_cmd_cheat_ability(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_cheat_ability(i, n, arr)
}
func nox_cmd_cheat_level(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_cheat_level(i, n, arr)
}
func nox_cmd_window(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_window(i, n, arr)
}
func nox_cmd_set_qual_modem(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_set_qual_modem(i, n, arr)
}
func nox_cmd_set_qual_isdn(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_set_qual_isdn(i, n, arr)
}
func nox_cmd_set_qual_cable(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_set_qual_cable(i, n, arr)
}
func nox_cmd_set_qual_t1(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_set_qual_t1(i, n, arr)
}
func nox_cmd_set_qual_lan(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_set_qual_lan(i, n, arr)
}
func nox_cmd_set_time(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_set_time(i, n, arr)
}
func nox_cmd_set_lessons(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_set_lessons(i, n, arr)
}
func nox_cmd_menu_options(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_menu_options(i, n, arr)
}
func nox_cmd_menu_vidopt(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_menu_vidopt(i, n, arr)
}
func nox_cmd_reenter(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_reenter(i, n, arr)
}
