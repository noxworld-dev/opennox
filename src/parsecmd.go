package main

/*
#include <stddef.h>
extern unsigned int dword_5d4594_823684;

void nox_xxx_consoleTokenAddPair_4444C0(wchar_t* tok, wchar_t* tok2);
int nox_xxx_consolePrint_450B90(unsigned char typ, wchar_t* str);

int nox_cmd_lock(int, int, wchar_t**);
int nox_cmd_unlock(int, int, wchar_t**);
int nox_cmd_set_sysop(int, int, wchar_t**);
int nox_cmd_telnet_off(int, int, wchar_t**);
int nox_cmd_telnet_on(int, int, wchar_t**);
int nox_cmd_macros_on(int, int, wchar_t**);
int nox_cmd_macros_off(int, int, wchar_t**);
int nox_cmd_list_weapons(int, int, wchar_t**);
int nox_cmd_list_armor(int, int, wchar_t**);
int nox_cmd_list_spells(int, int, wchar_t**);
int nox_cmd_list_staffs(int, int, wchar_t**);
int nox_cmd_show_bindings(int, int, wchar_t**);
int nox_cmd_show_game(int, int, wchar_t**);
int nox_cmd_show_mmx(int, int, wchar_t**);
int nox_cmd_load(int, int, wchar_t**);
int nox_cmd_set_obs(int, int, wchar_t**);
int nox_cmd_set_save_debug(int, int, wchar_t**);
int nox_cmd_set_god(int, int, wchar_t**);
int nox_cmd_unset_god(int, int, wchar_t**);
int nox_cmd_set_sage(int, int, wchar_t**);
int nox_cmd_unset_sage(int, int, wchar_t**);
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
int nox_cmd_cheat_health(int, int, wchar_t**);
int nox_cmd_cheat_mana(int, int, wchar_t**);
int nox_cmd_cheat_level(int, int, wchar_t**);
int nox_cmd_cheat_spells(int, int, wchar_t**);
int nox_cmd_cheat_gold(int, int, wchar_t**);
int nox_cmd_image(int, int, wchar_t**);
int nox_cmd_quit(int, int, wchar_t**);
int nox_cmd_exit(int, int, wchar_t**);
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
	"log"

	"nox/client/system/parsecmd"
)

type consolePrinter struct{}

func (consolePrinter) Printf(cl parsecmd.Color, format string, args ...interface{}) {
	consolePrintf(cl, format, args...)
}

var parseCmd = parsecmd.NewConsole(consolePrinter{}, strMan)

//export nox_xxx_consoleParseToken_443A20
func nox_xxx_consoleParseToken_443A20(tokInd C.int, tokCnt C.int, tokens **C.wchar_t, a5 C.int) C.int {
	toks := GoWStrSliceN(tokens, int(tokCnt))
	ok := consoleParseToken(int(tokInd), toks, parseCmd.Commands(), int(a5))
	if ok {
		return 1
	}
	return 0
}

func consolePrintf(typ parsecmd.Color, format string, args ...interface{}) int {
	str := fmt.Sprintf(format, args...)
	log.Print(str)
	cstr := CWString(str)
	res := C.nox_xxx_consolePrint_450B90(C.uchar(typ), cstr)
	WStrFree(cstr)
	return int(res)
}

func consoleParseToken(tokInd int, tokens []string, cmds []parsecmd.Command, a5 int) bool {
	if tokInd >= len(tokens) || len(cmds) == 0 {
		return false
	}

	var cmd *parsecmd.Command
	for i, cur := range cmds {
		tok := tokens[tokInd]
		if cur.Flags.Has(parsecmd.Secret) {
			tok = parsecmd.EncodeSecret(tok)
		}
		if tok == cur.Token {
			cmd = &cmds[i]
			break
		}
	}
	if cmd == nil {
		return false
	}
	if !getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) && !parseCmd.Cheats() && cmd.Flags.Has(parsecmd.Cheat) {
		return false
	}
	if C.dword_5d4594_823684 != 0 {
		if !cmd.Flags.Has(parsecmd.Server) {
			s := strMan.GetStringInFile("clientonly", "C:\\NoxPost\\src\\Client\\System\\parsecmd.c")
			consolePrintf(parsecmd.ColorRed, s)
			return true
		}
	} else {
		if !cmd.Flags.Has(parsecmd.Client) {
			s := strMan.GetStringInFile("serveronly", "C:\\NoxPost\\src\\Client\\System\\parsecmd.c")
			consolePrintf(parsecmd.ColorRed, s)
			return true
		}
	}
	if cmd.Flags.Has(parsecmd.Flag0x20) && !getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) {
		return true
	}
	var res bool
	if len(cmd.Sub) != 0 { // have sub-commands
		if tokInd+1 >= len(tokens) {
			// not enough tokens - print help
			help := strMan.GetStringInFile(cmd.HelpID, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c")
			consolePrintf(parsecmd.ColorRed, help)
			return true
		}
		// continue parsing the sub command
		res = consoleParseToken(tokInd+1, tokens, cmd.Sub, a5)
	} else {
		// call console command handler, let it parse the rest
		res = cmd.Func(tokInd+1, tokens)
	}
	if !res {
		// command failed - print help
		help := strMan.GetStringInFile(cmd.HelpID, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c")
		consolePrintf(parsecmd.ColorRed, help)
		return true
	}
	return res
}

//export nox_xxx_consoleLoadTokens_444440
func nox_xxx_consoleLoadTokens_444440() {
	consoleLoadTokens(parseCmd.Commands())
}

func consoleLoadTokens(cmds []parsecmd.Command) {
	for i := range cmds {
		cmd := &cmds[i]
		cmd.Token2 = strMan.GetStringInFile("cmd_token:"+cmd.Token, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c")
		C.nox_xxx_consoleTokenAddPair_4444C0(internWStr(cmd.Token), internWStr(cmd.Token2))
		if len(cmd.Token2) < 32 && len(cmd.Sub) != 0 {
			consoleLoadTokens(cmd.Sub)
		}
	}
}

func wrapCommandC(cfnc func(C.int, C.int, **C.wchar_t) C.int) parsecmd.CommandFunc {
	return func(tokInd int, tokens []string) bool {
		ctokens := CWStrSlice(tokens)
		defer WStrSliceFree(ctokens)
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

var noxCommands = []parsecmd.Command{
	{Token: "allow", HelpID: "allowhelp", Flags: parsecmd.Server, Sub: []parsecmd.Command{
		{Token: "user", HelpID: "allowuserhelp", Flags: parsecmd.Server, Func: wrapCommandC(nox_cmd_allow_user)},
		{Token: "IP", HelpID: "allowiphelp", Flags: parsecmd.Server, Func: wrapCommandC(nox_cmd_allow_ip)},
	}},
	{Token: "audtest", HelpID: "sethelp", Flags: parsecmd.ClientServer, Func: wrapCommandC(nox_cmd_set)},
	{Token: "ban", HelpID: "banhelp", Flags: parsecmd.Server, Func: wrapCommandC(nox_cmd_ban)},
	{Token: "bind", HelpID: "bindHelp", Flags: parsecmd.ClientServer, Func: wrapCommandC(nox_cmd_bind)},
	{Token: "broadcast", HelpID: "broadcasthelp", Flags: parsecmd.Server, Func: wrapCommandC(nox_cmd_broadcast)},
	{Token: "cheat", HelpID: "cheathelp", Flags: parsecmd.Server | parsecmd.Cheat, Sub: []parsecmd.Command{
		{Token: "ability", HelpID: "cheatabilityhelp", Flags: parsecmd.Server, Func: wrapCommandC(nox_cmd_cheat_ability)},
		{Token: "goto", HelpID: "cheatgotohelp", Flags: parsecmd.Server, Func: wrapCommandC(nox_cmd_cheat_goto)},
		{Token: "health", HelpID: "cheathealthhelp", Flags: parsecmd.Server, Func: wrapCommandC(nox_cmd_cheat_health)},
		{Token: "mana", HelpID: "cheatmanahelp", Flags: parsecmd.Server, Func: wrapCommandC(nox_cmd_cheat_mana)},
		{Token: "level", HelpID: "cheatlevelhelp", Flags: parsecmd.Server, Func: wrapCommandC(nox_cmd_cheat_level)},
		{Token: "spells", HelpID: "cheatspellshelp", Flags: parsecmd.Server, Func: wrapCommandC(nox_cmd_cheat_spells)},
		{Token: "gold", HelpID: "cheatgoldhelp", Flags: parsecmd.Server, Func: wrapCommandC(nox_cmd_cheat_gold)},
		{Token: "re-enter", HelpID: "", Flags: parsecmd.Server, Func: wrapCommandC(nox_cmd_reenter)},
	}},
	{Token: "clear", HelpID: "clearhelp", Flags: parsecmd.ClientServer, Func: wrapCommandC(nox_cmd_clear)},
	{Token: "exec", HelpID: "exechelp", Flags: parsecmd.Server, Func: wrapCommandC(nox_cmd_exec)},
	{Token: "execrul", HelpID: "execrulhelp", Flags: parsecmd.ClientServer, Func: wrapCommandC(nox_cmd_exec_rul)},
	{Token: "exit", HelpID: "exithelp", Flags: parsecmd.ClientServer, Func: wrapCommandC(nox_cmd_exit)},
	{Token: "gamma", HelpID: "gammahelp", Flags: parsecmd.ClientServer, Func: wrapCommandC(nox_cmd_gamma)},
	{Token: "image", HelpID: "imagehelp", Flags: parsecmd.ClientServer, Func: wrapCommandC(nox_cmd_image)},
	{Token: "kick", HelpID: "kickhelp", Flags: parsecmd.Server, Func: wrapCommandC(nox_cmd_kick)},
	{Token: "list", HelpID: "listhelp", Flags: parsecmd.ClientServer, Sub: []parsecmd.Command{
		{Token: "armor", HelpID: "listarmorhelp", Flags: parsecmd.ClientServer, Func: wrapCommandC(nox_cmd_list_armor)},
		{Token: "maps", HelpID: "listmapshelp", Flags: parsecmd.ClientServer, Func: wrapCommandC(nox_cmd_list_maps)},
		{Token: "spells", HelpID: "listspellshelp", Flags: parsecmd.ClientServer, Func: wrapCommandC(nox_cmd_list_spells)},
		{Token: "staffs", HelpID: "liststaffshelp", Flags: parsecmd.ClientServer, Func: wrapCommandC(nox_cmd_list_staffs)},
		{Token: "weapons", HelpID: "listweaponshelp", Flags: parsecmd.ClientServer, Func: wrapCommandC(nox_cmd_list_weapons)},
		{Token: "users", HelpID: "listusershelp", Flags: parsecmd.ClientServer, Func: wrapCommandC(nox_cmd_list_users)},
	}},
	{Token: "lock", HelpID: "lockhelp", Flags: parsecmd.ClientServer, Func: wrapCommandC(nox_cmd_lock)},
	{Token: "load", HelpID: "loadhelp", Flags: parsecmd.Server | parsecmd.Cheat, Func: wrapCommandC(nox_cmd_load)},
	{Token: "log", HelpID: "loghelp", Flags: parsecmd.ClientServer | parsecmd.Cheat, Sub: []parsecmd.Command{
		{Token: "console", HelpID: "logconsolehelp", Flags: parsecmd.ClientServer, Func: wrapCommandC(nox_cmd_log_console)},
		{Token: "file", HelpID: "logfilehelp", Flags: parsecmd.ClientServer, Func: wrapCommandC(nox_cmd_log_file)},
		{Token: "stop", HelpID: "logstophelp", Flags: parsecmd.ClientServer, Func: wrapCommandC(nox_cmd_log_stop)},
	}},
	{Token: "macros", HelpID: "macroshelp", Flags: parsecmd.ClientServer, Sub: []parsecmd.Command{
		{Token: "on", HelpID: "macrosonhelp", Flags: parsecmd.Server, Func: wrapCommandC(nox_cmd_macros_on)},
		{Token: "off", HelpID: "macrosoffhelp", Flags: parsecmd.Server, Func: wrapCommandC(nox_cmd_macros_off)},
	}},
	{Token: "menu", HelpID: "menuhelp", Flags: parsecmd.ClientServer, Sub: []parsecmd.Command{
		{Token: "vidopt", HelpID: "menuvidopthelp", Flags: parsecmd.ClientServer, Func: wrapCommandC(nox_cmd_menu_vidopt)},
		{Token: "options", HelpID: "menuoptionshelp", Flags: parsecmd.ClientServer, Func: wrapCommandC(nox_cmd_menu_options)},
	}},
	{Token: "mute", HelpID: "mutehelp", Flags: parsecmd.ClientServer, Func: wrapCommandC(nox_cmd_mute)},
	{Token: "quit", HelpID: "quithelp", Flags: parsecmd.ClientServer, Func: wrapCommandC(nox_cmd_quit)},
	{Token: "say", HelpID: "sayhelp", Flags: parsecmd.ClientServer, Func: wrapCommandC(nox_cmd_say)},
	{Token: "set", HelpID: "sethelp", Flags: parsecmd.ClientServer, Sub: []parsecmd.Command{
		{Token: "armor", HelpID: "setarmorhelp", Flags: parsecmd.Server, Func: wrapCommandC(nox_cmd_set_armor)},
		{Token: "cycle", HelpID: "setcyclehelp", Flags: parsecmd.Server, Func: wrapCommandC(nox_cmd_set_cycle)},
		{Token: "frameratelimiter", HelpID: "setfrhelp", Flags: parsecmd.Server | parsecmd.Cheat, Func: wrapCommandC(nox_cmd_set_fr)},
		{Token: "god", HelpID: "setgodhelp", Flags: parsecmd.Server | parsecmd.Cheat, Func: wrapCommandC(nox_cmd_set_god)},
		{Token: "lessons", HelpID: "setlessonshelp", Flags: parsecmd.Server, Func: wrapCommandC(nox_cmd_set_lessons)},
		{Token: "monsters", HelpID: "setmnstrshelp", Flags: parsecmd.Server | parsecmd.Cheat, Func: wrapCommandC(nox_cmd_set_mnstrs)},
		{Token: "name", HelpID: "setnamehelp", Flags: parsecmd.Server, Func: wrapCommandC(nox_cmd_set_name)},
		{Token: "netdebug", HelpID: "setnetdebughelp", Flags: parsecmd.ClientServer | parsecmd.Cheat, Func: wrapCommandC(nox_cmd_set_net_debug)},
		{Token: "ob", HelpID: "setobshelp", Flags: parsecmd.ClientServer | parsecmd.Cheat, Func: wrapCommandC(nox_cmd_set_obs)},
		{Token: "players", HelpID: "setplayershelp", Flags: parsecmd.Server, Func: wrapCommandC(nox_cmd_set_players)},
		{Token: "quality", HelpID: "setqualityhelp", Flags: parsecmd.ClientServer, Sub: []parsecmd.Command{
			{Token: "modem", HelpID: "setqualmodemhelp", Flags: parsecmd.ClientServer, Func: wrapCommandC(nox_cmd_set_qual_modem)},
			{Token: "isdn", HelpID: "setqualisdnhelp", Flags: parsecmd.ClientServer, Func: wrapCommandC(nox_cmd_set_qual_isdn)},
			{Token: "cable", HelpID: "setqualcablehelp", Flags: parsecmd.ClientServer, Func: wrapCommandC(nox_cmd_set_qual_cable)},
			{Token: "T1", HelpID: "setqualT1help", Flags: parsecmd.ClientServer, Func: wrapCommandC(nox_cmd_set_qual_t1)},
			{Token: "LAN", HelpID: "setqualLANhelp", Flags: parsecmd.ClientServer, Func: wrapCommandC(nox_cmd_set_qual_lan)},
		}},
		{Token: "sage", HelpID: "setsagehelp", Flags: parsecmd.Server | parsecmd.Cheat, Func: wrapCommandC(nox_cmd_set_sage)},
		{Token: "savedebugcmd", HelpID: "setsavedebughelp", Flags: parsecmd.Server, Func: wrapCommandC(nox_cmd_set_save_debug)},
		{Token: "spell", HelpID: "setspellhelp", Flags: parsecmd.Server, Func: wrapCommandC(nox_cmd_set_spell)},
		{Token: "spellpoints", HelpID: "setspellptshelp", Flags: parsecmd.Server | parsecmd.Cheat, Func: wrapCommandC(nox_cmd_set_spellpts)},
		{Token: "staff", HelpID: "setstaffhelp", Flags: parsecmd.Server | parsecmd.Cheat, Func: wrapCommandC(nox_cmd_set_staff)},
		{Token: "staffs", HelpID: "setstaffshelp", Flags: parsecmd.Server | parsecmd.Cheat, Func: wrapCommandC(nox_cmd_set_staffs)},
		{Token: "sysop", HelpID: "setsysophelp", Flags: parsecmd.Server, Func: wrapCommandC(nox_cmd_set_sysop)},
		{Token: "time", HelpID: "settimehelp", Flags: parsecmd.Server, Func: wrapCommandC(nox_cmd_set_time)},
		{Token: "weapon", HelpID: "setweaponhelp", Flags: parsecmd.Server, Func: wrapCommandC(nox_cmd_set_weapon)},
		{Token: "weapons", HelpID: "setweaponshelp", Flags: parsecmd.Server | parsecmd.Cheat, Func: wrapCommandC(nox_cmd_set_weapons)},
		{Token: "team", HelpID: "officialonly", Flags: parsecmd.Server | parsecmd.Cheat | parsecmd.Flag0x20, Func: wrapCommandC(nox_cmd_offonly1)},
		{Token: "mode", HelpID: "officialonly", Flags: parsecmd.Server | parsecmd.Cheat | parsecmd.Flag0x20, Func: wrapCommandC(nox_cmd_offonly2)},
	}},
	{Token: "show", HelpID: "showhelp", Flags: parsecmd.ClientServer, Sub: []parsecmd.Command{
		{Token: "bindings", HelpID: "showbindingshelp", Flags: parsecmd.ClientServer, Func: wrapCommandC(nox_cmd_show_bindings)},
		{Token: "game", HelpID: "showgamehelp", Flags: parsecmd.ClientServer, Func: wrapCommandC(nox_cmd_show_game)},
		{Token: "motd", HelpID: "showmotdhelp", Flags: parsecmd.ClientServer, Func: wrapCommandC(nox_cmd_show_motd)},
		{Token: "rank", HelpID: "showrankhelp", Flags: parsecmd.ClientServer, Func: wrapCommandC(nox_cmd_show_rank)},
		{Token: "perfmon", HelpID: "showperfmonhelp", Flags: parsecmd.ClientServer, Func: wrapCommandC(nox_cmd_show_perfmon)},
		{Token: "extents", HelpID: "showextentshelp", Flags: parsecmd.ClientServer | parsecmd.Cheat, Func: wrapCommandC(nox_cmd_show_extents)},
		{Token: "gui", HelpID: "showguihelp", Flags: parsecmd.ClientServer, Func: wrapCommandC(nox_cmd_show_gui)},
		{Token: "ai", HelpID: "showaihelp", Flags: parsecmd.Server | parsecmd.Cheat, Func: wrapCommandC(nox_cmd_show_ai)},
		{Token: "info", HelpID: "showinfohelp", Flags: parsecmd.ClientServer | parsecmd.Flag0x4, Func: wrapCommandC(nox_cmd_show_info)},
		{Token: "mem", HelpID: "showmemhelp", Flags: parsecmd.ClientServer | parsecmd.Cheat, Func: wrapCommandC(nox_cmd_show_mem)},
		{Token: "netstat", HelpID: "shownetstathelp", Flags: parsecmd.ClientServer, Func: wrapCommandC(nox_cmd_show_netstat)},
		{Token: "mmx", HelpID: "showmmxhelp", Flags: parsecmd.ClientServer, Func: wrapCommandC(nox_cmd_show_mmx)},
		{Token: "seq", HelpID: "showseqhelp", Flags: parsecmd.ClientServer | parsecmd.Cheat, Func: wrapCommandC(nox_cmd_show_seq)},
	}},
	{Token: "sysop", HelpID: "nohelp", Flags: parsecmd.ClientServer | parsecmd.Flag0x4, Func: wrapCommandC(nox_cmd_sysop)},
	{Token: "telnet", HelpID: "telnethelp", Flags: parsecmd.Server, Sub: []parsecmd.Command{
		{Token: "god", HelpID: "unsetgodhelp", Flags: parsecmd.Server, Func: wrapCommandC(nox_cmd_unset_god)},
		{Token: "frameratelimiter", HelpID: "unsetfrhelp", Flags: parsecmd.Server, Func: wrapCommandC(nox_cmd_unset_fr)},
		{Token: "netdebug", HelpID: "unsetnetdebug", Flags: parsecmd.ClientServer, Func: wrapCommandC(nox_cmd_unset_net_debug)},
		{Token: "sage", HelpID: "unsetsagehelp", Flags: parsecmd.Server, Func: wrapCommandC(nox_cmd_unset_sage)},
	}},
	{Token: "unset", HelpID: "unsethelp", Flags: parsecmd.ClientServer, Sub: []parsecmd.Command{
		{Token: "god", HelpID: "unsetgodhelp", Flags: parsecmd.Server, Func: wrapCommandC(nox_cmd_unset_god)},
		{Token: "frameratelimiter", HelpID: "unsetfrhelp", Flags: parsecmd.Server, Func: wrapCommandC(nox_cmd_unset_fr)},
		{Token: "netdebug", HelpID: "unsetnetdebug", Flags: parsecmd.ClientServer, Func: wrapCommandC(nox_cmd_unset_net_debug)},
		{Token: "sage", HelpID: "unsetsagehelp", Flags: parsecmd.Server, Func: wrapCommandC(nox_cmd_unset_sage)},
	}},
	{Token: "unmute", HelpID: "unmutehelp", Flags: parsecmd.ClientServer, Func: wrapCommandC(nox_cmd_unmute)},
	{Token: "unbind", HelpID: "unbindHelp", Flags: parsecmd.ClientServer, Func: wrapCommandC(nox_cmd_unbind)},
	{Token: "unlock", HelpID: "unlockhelp", Flags: parsecmd.ClientServer, Func: wrapCommandC(nox_cmd_unlock)},
	{Token: "watch", HelpID: "watchhelp", Flags: parsecmd.ClientServer, Func: wrapCommandC(nox_cmd_watch)},
	{Token: "window", HelpID: "windowhelp", Flags: parsecmd.ClientServer, Func: wrapCommandC(nox_cmd_window)},
	{Token: "startSoloQuest", HelpID: "nohelp", Flags: parsecmd.Server | parsecmd.Flag0x4, Func: wrapCommandC(nox_cmd_startSoloQuest)},
}

func nox_cmd_lock(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_lock(i, n, arr)
}
func nox_cmd_unlock(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_unlock(i, n, arr)
}
func nox_cmd_set_sysop(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_set_sysop(i, n, arr)
}
func nox_cmd_telnet_off(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_telnet_off(i, n, arr)
}
func nox_cmd_telnet_on(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_telnet_on(i, n, arr)
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
func nox_cmd_list_spells(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_list_spells(i, n, arr)
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
func nox_cmd_set_god(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_set_god(i, n, arr)
}
func nox_cmd_unset_god(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_unset_god(i, n, arr)
}
func nox_cmd_set_sage(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_set_sage(i, n, arr)
}
func nox_cmd_unset_sage(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_unset_sage(i, n, arr)
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
func nox_cmd_cheat_health(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_cheat_health(i, n, arr)
}
func nox_cmd_cheat_mana(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_cheat_mana(i, n, arr)
}
func nox_cmd_cheat_level(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_cheat_level(i, n, arr)
}
func nox_cmd_cheat_spells(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_cheat_spells(i, n, arr)
}
func nox_cmd_cheat_gold(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_cheat_gold(i, n, arr)
}
func nox_cmd_image(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_image(i, n, arr)
}
func nox_cmd_quit(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_quit(i, n, arr)
}
func nox_cmd_exit(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_exit(i, n, arr)
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
