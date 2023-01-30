package legacy

/*
#include <stddef.h>
extern unsigned int nox_client_consoleIsServer_823684;
extern int nox_cheat_allowall;
extern int nox_cheat_charmall;
extern int nox_cheat_summon_nolimit;

int nox_cmd_set_sysop(int, int, wchar_t**);
int nox_cmd_set_cycle(int, int, wchar_t**);
int nox_cmd_set_weapons(int, int, wchar_t**);
int nox_cmd_set_staffs(int, int, wchar_t**);
int nox_cmd_set_name(int, int, wchar_t**);
int nox_cmd_set_mnstrs(int, int, wchar_t**);
int nox_cmd_set_spell(int, int, wchar_t**);
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
int nox_cmd_set_net_debug(int, int, wchar_t**);
int nox_cmd_unset_net_debug(int, int, wchar_t**);
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

	"github.com/noxworld-dev/opennox-lib/console"
)

func CheatEquipAll(v bool) {
	C.nox_cheat_allowall = C.int(bool2int(v))
}

func CheatCharmAll(v bool) {
	C.nox_cheat_charmall = C.int(bool2int(v))
}

func CheatSummonNoLimit(v bool) {
	C.nox_cheat_summon_nolimit = C.int(bool2int(v))
}

func WrapCommandC(cfnc func(C.int, C.int, **C.wchar_t) C.int) console.CommandLegacyFunc {
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

func Nox_cmd_set_sysop(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_set_sysop(i, n, arr)
}
func Nox_cmd_set_cycle(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_set_cycle(i, n, arr)
}
func Nox_cmd_set_weapons(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_set_weapons(i, n, arr)
}
func Nox_cmd_set_staffs(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_set_staffs(i, n, arr)
}
func Nox_cmd_set_name(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_set_name(i, n, arr)
}
func Nox_cmd_set_mnstrs(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_set_mnstrs(i, n, arr)
}
func Nox_cmd_set_spell(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_set_spell(i, n, arr)
}
func Nox_cmd_ban(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_ban(i, n, arr)
}
func Nox_cmd_allow_user(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_allow_user(i, n, arr)
}
func Nox_cmd_allow_ip(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_allow_ip(i, n, arr)
}
func Nox_cmd_kick(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_kick(i, n, arr)
}
func Nox_cmd_set_players(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_set_players(i, n, arr)
}
func Nox_cmd_set_spellpts(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_set_spellpts(i, n, arr)
}
func Nox_cmd_list_users(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_list_users(i, n, arr)
}
func Nox_cmd_unmute(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_unmute(i, n, arr)
}
func Nox_cmd_mute(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_mute(i, n, arr)
}
func Nox_cmd_exec_rul(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_exec_rul(i, n, arr)
}
func Nox_cmd_offonly1(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_offonly1(i, n, arr)
}
func Nox_cmd_offonly2(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_offonly2(i, n, arr)
}
func Nox_cmd_set_net_debug(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_set_net_debug(i, n, arr)
}
func Nox_cmd_unset_net_debug(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_unset_net_debug(i, n, arr)
}
func Nox_cmd_show_info(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_show_info(i, n, arr)
}
func Nox_cmd_show_mem(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_show_mem(i, n, arr)
}
func Nox_cmd_show_rank(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_show_rank(i, n, arr)
}
func Nox_cmd_show_motd(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_show_motd(i, n, arr)
}
func Nox_cmd_show_seq(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_show_seq(i, n, arr)
}
func Nox_cmd_list_maps(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_list_maps(i, n, arr)
}
func Nox_cmd_cheat_ability(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_cheat_ability(i, n, arr)
}
func Nox_cmd_cheat_level(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_cheat_level(i, n, arr)
}
func Nox_cmd_window(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_window(i, n, arr)
}
func Nox_cmd_set_qual_modem(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_set_qual_modem(i, n, arr)
}
func Nox_cmd_set_qual_isdn(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_set_qual_isdn(i, n, arr)
}
func Nox_cmd_set_qual_cable(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_set_qual_cable(i, n, arr)
}
func Nox_cmd_set_qual_t1(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_set_qual_t1(i, n, arr)
}
func Nox_cmd_set_qual_lan(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_set_qual_lan(i, n, arr)
}
func Nox_cmd_set_time(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_set_time(i, n, arr)
}
func Nox_cmd_set_lessons(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_set_lessons(i, n, arr)
}
func Nox_cmd_menu_options(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_menu_options(i, n, arr)
}
func Nox_cmd_menu_vidopt(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_menu_vidopt(i, n, arr)
}
func Nox_cmd_reenter(i C.int, n C.int, arr **C.wchar_t) C.int {
	return C.nox_cmd_reenter(i, n, arr)
}
