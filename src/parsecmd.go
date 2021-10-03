package nox

/*
#include <stddef.h>
extern unsigned int nox_client_consoleIsServer_823684;
extern int nox_cheat_allowall;
extern int nox_cheat_charmall;

void nox_xxx_consoleTokenAddPair_4444C0(wchar_t* tok, wchar_t* tok2);
int nox_gui_console_Print_450B90(unsigned char typ, wchar_t* str);
int nox_client_quit_4460C0();
int  sub_4D6B10(int a1);

int nox_cmd_lock(int, int, wchar_t**);
int nox_cmd_unlock(int, int, wchar_t**);
int nox_cmd_set_sysop(int, int, wchar_t**);
int nox_cmd_macros_on(int, int, wchar_t**);
int nox_cmd_macros_off(int, int, wchar_t**);
int nox_cmd_list_weapons(int, int, wchar_t**);
int nox_cmd_list_armor(int, int, wchar_t**);
int nox_cmd_list_staffs(int, int, wchar_t**);
int nox_cmd_show_bindings(int, int, wchar_t**);
int nox_cmd_show_game(int, int, wchar_t**);
int nox_cmd_show_mmx(int, int, wchar_t**);
int nox_cmd_load(int, int, wchar_t**);
int nox_cmd_set_obs(int, int, wchar_t**);
int nox_cmd_set_save_debug(int, int, wchar_t**);
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
int nox_cmd_exec(int, int, wchar_t**);
int nox_cmd_exec_rul(int, int, wchar_t**);
int nox_cmd_sysop(int, int, wchar_t**);
int nox_cmd_unbind(int, int, wchar_t**);
int nox_cmd_broadcast(int, int, wchar_t**);
int nox_cmd_say(int, int, wchar_t**);
int nox_cmd_offonly1(int, int, wchar_t**);
int nox_cmd_offonly2(int, int, wchar_t**);
int nox_cmd_set_fr(int, int, wchar_t**);
int nox_cmd_unset_fr(int, int, wchar_t**);
int nox_cmd_set_net_debug(int, int, wchar_t**);
int nox_cmd_unset_net_debug(int, int, wchar_t**);
int nox_cmd_show_ai(int, int, wchar_t**);
int nox_cmd_show_gui(int, int, wchar_t**);
int nox_cmd_show_extents(int, int, wchar_t**);
int nox_cmd_show_perfmon(int, int, wchar_t**);
int nox_cmd_show_netstat(int, int, wchar_t**);
int nox_cmd_show_info(int, int, wchar_t**);
int nox_cmd_show_mem(int, int, wchar_t**);
int nox_cmd_show_rank(int, int, wchar_t**);
int nox_cmd_show_motd(int, int, wchar_t**);
int nox_cmd_show_seq(int, int, wchar_t**);
int nox_cmd_list_maps(int, int, wchar_t**);
int nox_cmd_log_file(int, int, wchar_t**);
int nox_cmd_log_console(int, int, wchar_t**);
int nox_cmd_log_stop(int, int, wchar_t**);
int nox_cmd_set(int, int, wchar_t**);
int nox_cmd_cheat_ability(int, int, wchar_t**);
int nox_cmd_cheat_goto(int, int, wchar_t**);
int nox_cmd_cheat_level(int, int, wchar_t**);
int nox_cmd_cheat_spells(int, int, wchar_t**);
int nox_cmd_cheat_gold(int, int, wchar_t**);
int nox_cmd_watch(int, int, wchar_t**);
int nox_cmd_gamma(int, int, wchar_t**);
int nox_cmd_window(int, int, wchar_t**);
int nox_cmd_set_qual_modem(int, int, wchar_t**);
int nox_cmd_set_qual_isdn(int, int, wchar_t**);
int nox_cmd_set_qual_cable(int, int, wchar_t**);
int nox_cmd_set_qual_t1(int, int, wchar_t**);
int nox_cmd_set_qual_lan(int, int, wchar_t**);
int nox_cmd_set_time(int, int, wchar_t**);
int nox_cmd_set_lessons(int, int, wchar_t**);
int nox_cmd_clear(int, int, wchar_t**);
int nox_cmd_menu_options(int, int, wchar_t**);
int nox_cmd_menu_vidopt(int, int, wchar_t**);
int nox_cmd_bind(int, int, wchar_t**);
int nox_cmd_reenter(int, int, wchar_t**);
int nox_cmd_startSoloQuest(int, int, wchar_t**);
*/
import "C"
import (
	"fmt"

	"nox/v1/client/system/parsecmd"
	noxflags "nox/v1/common/flags"
	"nox/v1/common/strman"
)

type consolePrinter struct{}

func (consolePrinter) Printf(cl parsecmd.Color, format string, args ...interface{}) {
	consolePrintf(cl, format, args...)
}

func cheatEquipAll(v bool) {
	C.nox_cheat_allowall = C.int(bool2int(v))
}

func cheatCharmAll(v bool) {
	C.nox_cheat_charmall = C.int(bool2int(v))
}

var parseCmd = parsecmd.NewConsole(consolePrinter{}, strMan)

func consolePrintf(typ parsecmd.Color, format string, args ...interface{}) int {
	str := fmt.Sprintf(format, args...)
	cstr, free := CWString(str)
	defer free()
	res := C.nox_gui_console_Print_450B90(C.uchar(typ), cstr)
	return int(res)
}

//export nox_xxx_consoleLoadTokens_444440
func nox_xxx_consoleLoadTokens_444440() {
	consoleLoadTokens(parseCmd, parseCmd.Commands())
}

func consoleLoadTokens(c *parsecmd.Console, cmds []*parsecmd.Command) {
	for i := range cmds {
		cmd := cmds[i]
		if v, ok := c.Strings().GetVariant(strman.ID("cmd_token:" + cmd.Token)); ok {
			cmd.Token2 = v.Str
		} else {
			cmd.Token2 = cmd.Token
		}
		C.nox_xxx_consoleTokenAddPair_4444C0(internWStr(cmd.Token), internWStr(cmd.Token2))
		if len(cmd.Token2) < 32 && len(cmd.Sub) != 0 {
			consoleLoadTokens(c, cmd.Sub)
		}
	}
}

func wrapCommandC(cfnc func(C.int, C.int, **C.wchar_t) C.int) parsecmd.CommandLegacyFunc {
	return func(c *parsecmd.Console, tokInd int, tokens []string) bool {
		C.nox_client_consoleIsServer_823684 = C.uint(bool2int(!c.IsClient()))
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
	for _, c := range noxCommands {
		parseCmd.Register(c)
	}
}

var (
	noxCmdList = &parsecmd.Command{Token: "list", HelpID: "listhelp", Flags: parsecmd.ClientServer, Sub: []*parsecmd.Command{
		{Token: "armor", HelpID: "listarmorhelp", Flags: parsecmd.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_list_armor)},
		{Token: "maps", HelpID: "listmapshelp", Flags: parsecmd.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_list_maps)},
		{Token: "staffs", HelpID: "liststaffshelp", Flags: parsecmd.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_list_staffs)},
		{Token: "weapons", HelpID: "listweaponshelp", Flags: parsecmd.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_list_weapons)},
		{Token: "users", HelpID: "listusershelp", Flags: parsecmd.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_list_users)},
	}}
	noxCmdSet = &parsecmd.Command{Token: "set", HelpID: "sethelp", Flags: parsecmd.ClientServer, Sub: []*parsecmd.Command{
		{Token: "armor", HelpID: "setarmorhelp", Flags: parsecmd.Server, LegacyFunc: wrapCommandC(nox_cmd_set_armor)},
		{Token: "cycle", HelpID: "setcyclehelp", Flags: parsecmd.Server, LegacyFunc: wrapCommandC(nox_cmd_set_cycle)},
		{Token: "frameratelimiter", HelpID: "setfrhelp", Flags: parsecmd.Server | parsecmd.Cheat, LegacyFunc: wrapCommandC(nox_cmd_set_fr)},
		{Token: "lessons", HelpID: "setlessonshelp", Flags: parsecmd.Server, LegacyFunc: wrapCommandC(nox_cmd_set_lessons)},
		{Token: "monsters", HelpID: "setmnstrshelp", Flags: parsecmd.Server | parsecmd.Cheat, LegacyFunc: wrapCommandC(nox_cmd_set_mnstrs)},
		{Token: "name", HelpID: "setnamehelp", Flags: parsecmd.Server, LegacyFunc: wrapCommandC(nox_cmd_set_name)},
		{Token: "netdebug", HelpID: "setnetdebughelp", Flags: parsecmd.ClientServer | parsecmd.Cheat, LegacyFunc: wrapCommandC(nox_cmd_set_net_debug)},
		{Token: "ob", HelpID: "setobshelp", Flags: parsecmd.ClientServer | parsecmd.Cheat, LegacyFunc: wrapCommandC(nox_cmd_set_obs)},
		{Token: "players", HelpID: "setplayershelp", Flags: parsecmd.Server, LegacyFunc: wrapCommandC(nox_cmd_set_players)},
		{Token: "quality", HelpID: "setqualityhelp", Flags: parsecmd.ClientServer, Sub: []*parsecmd.Command{
			{Token: "modem", HelpID: "setqualmodemhelp", Flags: parsecmd.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_set_qual_modem)},
			{Token: "isdn", HelpID: "setqualisdnhelp", Flags: parsecmd.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_set_qual_isdn)},
			{Token: "cable", HelpID: "setqualcablehelp", Flags: parsecmd.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_set_qual_cable)},
			{Token: "T1", HelpID: "setqualT1help", Flags: parsecmd.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_set_qual_t1)},
			{Token: "LAN", HelpID: "setqualLANhelp", Flags: parsecmd.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_set_qual_lan)},
		}},
		{Token: "savedebugcmd", HelpID: "setsavedebughelp", Flags: parsecmd.Server, LegacyFunc: wrapCommandC(nox_cmd_set_save_debug)},
		{Token: "spell", HelpID: "setspellhelp", Flags: parsecmd.Server, LegacyFunc: wrapCommandC(nox_cmd_set_spell)},
		{Token: "spellpoints", HelpID: "setspellptshelp", Flags: parsecmd.Server | parsecmd.Cheat, LegacyFunc: wrapCommandC(nox_cmd_set_spellpts)},
		{Token: "staff", HelpID: "setstaffhelp", Flags: parsecmd.Server | parsecmd.Cheat, LegacyFunc: wrapCommandC(nox_cmd_set_staff)},
		{Token: "staffs", HelpID: "setstaffshelp", Flags: parsecmd.Server | parsecmd.Cheat, LegacyFunc: wrapCommandC(nox_cmd_set_staffs)},
		{Token: "sysop", HelpID: "setsysophelp", Flags: parsecmd.Server, LegacyFunc: wrapCommandC(nox_cmd_set_sysop)},
		{Token: "time", HelpID: "settimehelp", Flags: parsecmd.Server, LegacyFunc: wrapCommandC(nox_cmd_set_time)},
		{Token: "weapon", HelpID: "setweaponhelp", Flags: parsecmd.Server, LegacyFunc: wrapCommandC(nox_cmd_set_weapon)},
		{Token: "weapons", HelpID: "setweaponshelp", Flags: parsecmd.Server | parsecmd.Cheat, LegacyFunc: wrapCommandC(nox_cmd_set_weapons)},
		{Token: "team", HelpID: "officialonly", Flags: parsecmd.Server | parsecmd.Cheat | parsecmd.FlagDedicated, LegacyFunc: wrapCommandC(nox_cmd_offonly1)},
		{Token: "mode", HelpID: "officialonly", Flags: parsecmd.Server | parsecmd.Cheat | parsecmd.FlagDedicated, LegacyFunc: wrapCommandC(nox_cmd_offonly2)},
	}}
	noxCmdUnSet = &parsecmd.Command{Token: "unset", HelpID: "unsethelp", Flags: parsecmd.ClientServer, Sub: []*parsecmd.Command{
		{Token: "frameratelimiter", HelpID: "unsetfrhelp", Flags: parsecmd.Server, LegacyFunc: wrapCommandC(nox_cmd_unset_fr)},
		{Token: "netdebug", HelpID: "unsetnetdebug", Flags: parsecmd.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_unset_net_debug)},
	}}
	noxCmdShow = &parsecmd.Command{Token: "show", HelpID: "showhelp", Flags: parsecmd.ClientServer, Sub: []*parsecmd.Command{
		{Token: "bindings", HelpID: "showbindingshelp", Flags: parsecmd.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_show_bindings)},
		{Token: "game", HelpID: "showgamehelp", Flags: parsecmd.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_show_game)},
		{Token: "motd", HelpID: "showmotdhelp", Flags: parsecmd.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_show_motd)},
		{Token: "rank", HelpID: "showrankhelp", Flags: parsecmd.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_show_rank)},
		{Token: "perfmon", HelpID: "showperfmonhelp", Flags: parsecmd.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_show_perfmon)},
		{Token: "extents", HelpID: "showextentshelp", Flags: parsecmd.ClientServer | parsecmd.Cheat, LegacyFunc: wrapCommandC(nox_cmd_show_extents)},
		{Token: "gui", HelpID: "showguihelp", Flags: parsecmd.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_show_gui)},
		{Token: "ai", HelpID: "showaihelp", Flags: parsecmd.Server | parsecmd.Cheat, LegacyFunc: wrapCommandC(nox_cmd_show_ai)},
		{Token: "info", HelpID: "showinfohelp", Flags: parsecmd.ClientServer | parsecmd.NoHelp, LegacyFunc: wrapCommandC(nox_cmd_show_info)},
		{Token: "mem", HelpID: "showmemhelp", Flags: parsecmd.ClientServer | parsecmd.Cheat, LegacyFunc: wrapCommandC(nox_cmd_show_mem)},
		{Token: "netstat", HelpID: "shownetstathelp", Flags: parsecmd.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_show_netstat)},
		{Token: "mmx", HelpID: "showmmxhelp", Flags: parsecmd.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_show_mmx)},
		{Token: "seq", HelpID: "showseqhelp", Flags: parsecmd.ClientServer | parsecmd.Cheat, LegacyFunc: wrapCommandC(nox_cmd_show_seq)},
	}}
	noxCmdCheat = &parsecmd.Command{Token: "cheat", HelpID: "cheathelp", Flags: parsecmd.Server | parsecmd.Cheat, Sub: []*parsecmd.Command{
		{Token: "ability", HelpID: "cheatabilityhelp", Flags: parsecmd.Server, LegacyFunc: wrapCommandC(nox_cmd_cheat_ability)},
		{Token: "goto", HelpID: "cheatgotohelp", Flags: parsecmd.Server, LegacyFunc: wrapCommandC(nox_cmd_cheat_goto)},
		{Token: "level", HelpID: "cheatlevelhelp", Flags: parsecmd.Server, LegacyFunc: wrapCommandC(nox_cmd_cheat_level)},
		{Token: "spells", HelpID: "cheatspellshelp", Flags: parsecmd.Server, LegacyFunc: wrapCommandC(nox_cmd_cheat_spells)},
		{Token: "re-enter", HelpID: "", Flags: parsecmd.Server, LegacyFunc: wrapCommandC(nox_cmd_reenter)},
	}}
	noxCommands = []*parsecmd.Command{
		noxCmdList,
		noxCmdSet,
		noxCmdUnSet,
		noxCmdShow,
		noxCmdCheat,
		{Token: "allow", HelpID: "allowhelp", Flags: parsecmd.Server, Sub: []*parsecmd.Command{
			{Token: "user", HelpID: "allowuserhelp", Flags: parsecmd.Server, LegacyFunc: wrapCommandC(nox_cmd_allow_user)},
			{Token: "IP", HelpID: "allowiphelp", Flags: parsecmd.Server, LegacyFunc: wrapCommandC(nox_cmd_allow_ip)},
		}},
		{Token: "audtest", HelpID: "sethelp", Flags: parsecmd.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_set)},
		{Token: "ban", HelpID: "banhelp", Flags: parsecmd.Server, LegacyFunc: wrapCommandC(nox_cmd_ban)},
		{Token: "bind", HelpID: "bindHelp", Flags: parsecmd.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_bind)},
		{Token: "broadcast", HelpID: "broadcasthelp", Flags: parsecmd.Server, LegacyFunc: wrapCommandC(nox_cmd_broadcast)},
		{Token: "clear", HelpID: "clearhelp", Flags: parsecmd.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_clear)},
		{Token: "exec", HelpID: "exechelp", Flags: parsecmd.Server, LegacyFunc: wrapCommandC(nox_cmd_exec)},
		{Token: "execrul", HelpID: "execrulhelp", Flags: parsecmd.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_exec_rul)},
		{Token: "exit", HelpID: "exithelp", Flags: parsecmd.ClientServer, Func: func(c *parsecmd.Console, tokens []string) bool {
			if noxflags.HasGame(noxflags.GameModeQuest) && noxflags.HasGame(1) {
				C.sub_4D6B10(0)
			}
			if noxflags.HasGame(0x2000000) {
				C.nox_client_quit_4460C0()
			}
			nox_xxx_setContinueMenuOrHost_43DDD0(0)
			nox_game_exit_xxx_43DE60()
			return true
		}},
		{Token: "gamma", HelpID: "gammahelp", Flags: parsecmd.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_gamma)},
		{Token: "kick", HelpID: "kickhelp", Flags: parsecmd.Server, LegacyFunc: wrapCommandC(nox_cmd_kick)},
		{Token: "lock", HelpID: "lockhelp", Flags: parsecmd.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_lock)},
		{Token: "load", HelpID: "loadhelp", Flags: parsecmd.Server | parsecmd.Cheat, LegacyFunc: wrapCommandC(nox_cmd_load)},
		{Token: "log", HelpID: "loghelp", Flags: parsecmd.ClientServer | parsecmd.Cheat, Sub: []*parsecmd.Command{
			{Token: "console", HelpID: "logconsolehelp", Flags: parsecmd.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_log_console)},
			{Token: "file", HelpID: "logfilehelp", Flags: parsecmd.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_log_file)},
			{Token: "stop", HelpID: "logstophelp", Flags: parsecmd.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_log_stop)},
		}},
		{Token: "macros", HelpID: "macroshelp", Flags: parsecmd.ClientServer, Sub: []*parsecmd.Command{
			{Token: "on", HelpID: "macrosonhelp", Flags: parsecmd.Server, LegacyFunc: wrapCommandC(nox_cmd_macros_on)},
			{Token: "off", HelpID: "macrosoffhelp", Flags: parsecmd.Server, LegacyFunc: wrapCommandC(nox_cmd_macros_off)},
		}},
		{Token: "menu", HelpID: "menuhelp", Flags: parsecmd.ClientServer, Sub: []*parsecmd.Command{
			{Token: "vidopt", HelpID: "menuvidopthelp", Flags: parsecmd.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_menu_vidopt)},
			{Token: "options", HelpID: "menuoptionshelp", Flags: parsecmd.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_menu_options)},
		}},
		{Token: "mute", HelpID: "mutehelp", Flags: parsecmd.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_mute)},
		{Token: "quit", HelpID: "quithelp", Flags: parsecmd.ClientServer, Func: func(c *parsecmd.Console, tokens []string) bool {
			C.nox_client_quit_4460C0()
			return true
		}},
		{Token: "say", HelpID: "sayhelp", Flags: parsecmd.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_say)},
		{Token: "sysop", HelpID: "nohelp", Flags: parsecmd.ClientServer | parsecmd.NoHelp, LegacyFunc: wrapCommandC(nox_cmd_sysop)},
		{Token: "unmute", HelpID: "unmutehelp", Flags: parsecmd.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_unmute)},
		{Token: "unbind", HelpID: "unbindHelp", Flags: parsecmd.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_unbind)},
		{Token: "unlock", HelpID: "unlockhelp", Flags: parsecmd.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_unlock)},
		{Token: "watch", HelpID: "watchhelp", Flags: parsecmd.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_watch)},
		{Token: "window", HelpID: "windowhelp", Flags: parsecmd.ClientServer, LegacyFunc: wrapCommandC(nox_cmd_window)},
		{Token: "startSoloQuest", HelpID: "nohelp", Flags: parsecmd.Server | parsecmd.NoHelp, LegacyFunc: wrapCommandC(nox_cmd_startSoloQuest)},
	}
)

func nox_cmd_lock(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_lock(i, n, arr)
}
func nox_cmd_unlock(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_unlock(i, n, arr)
}
func nox_cmd_set_sysop(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_set_sysop(i, n, arr)
}
func nox_cmd_macros_on(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_macros_on(i, n, arr)
}
func nox_cmd_macros_off(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_macros_off(i, n, arr)
}
func nox_cmd_list_weapons(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_list_weapons(i, n, arr)
}
func nox_cmd_list_armor(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_list_armor(i, n, arr)
}
func nox_cmd_list_staffs(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_list_staffs(i, n, arr)
}
func nox_cmd_show_bindings(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_show_bindings(i, n, arr)
}
func nox_cmd_show_game(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_show_game(i, n, arr)
}
func nox_cmd_show_mmx(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_show_mmx(i, n, arr)
}
func nox_cmd_load(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_load(i, n, arr)
}
func nox_cmd_set_obs(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_set_obs(i, n, arr)
}
func nox_cmd_set_save_debug(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_set_save_debug(i, n, arr)
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
func nox_cmd_exec(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_exec(i, n, arr)
}
func nox_cmd_exec_rul(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_exec_rul(i, n, arr)
}
func nox_cmd_sysop(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_sysop(i, n, arr)
}
func nox_cmd_unbind(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_unbind(i, n, arr)
}
func nox_cmd_broadcast(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_broadcast(i, n, arr)
}
func nox_cmd_say(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_say(i, n, arr)
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
func nox_cmd_show_ai(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_show_ai(i, n, arr)
}
func nox_cmd_show_gui(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_show_gui(i, n, arr)
}
func nox_cmd_show_extents(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_show_extents(i, n, arr)
}
func nox_cmd_show_perfmon(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_show_perfmon(i, n, arr)
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
func nox_cmd_log_file(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_log_file(i, n, arr)
}
func nox_cmd_log_console(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_log_console(i, n, arr)
}
func nox_cmd_log_stop(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_log_stop(i, n, arr)
}
func nox_cmd_set(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_set(i, n, arr)
}
func nox_cmd_cheat_ability(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_cheat_ability(i, n, arr)
}
func nox_cmd_cheat_goto(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_cheat_goto(i, n, arr)
}
func nox_cmd_cheat_level(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_cheat_level(i, n, arr)
}
func nox_cmd_cheat_spells(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_cheat_spells(i, n, arr)
}
func nox_cmd_watch(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_watch(i, n, arr)
}
func nox_cmd_gamma(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_gamma(i, n, arr)
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
func nox_cmd_clear(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_clear(i, n, arr)
}
func nox_cmd_menu_options(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_menu_options(i, n, arr)
}
func nox_cmd_menu_vidopt(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_menu_vidopt(i, n, arr)
}
func nox_cmd_bind(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_bind(i, n, arr)
}
func nox_cmd_reenter(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_reenter(i, n, arr)
}
func nox_cmd_startSoloQuest(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_startSoloQuest(i, n, arr)
}
