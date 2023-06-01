package legacy

import (
	"context"

	"github.com/noxworld-dev/opennox-lib/console"
)

func CheatEquipAll(v bool) {
	nox_cheat_allowall = bool2int32(v)
}

func CheatCharmAll(v bool) {
	nox_cheat_charmall = bool2int32(v)
}

func WrapCommandC(cfnc func(int, int, **wchar2_t) int) console.CommandLegacyFunc {
	return func(ctx context.Context, c *console.Console, tokInd int, tokens []string) bool {
		nox_client_consoleIsServer_823684 = uint32(bool2int(!console.IsClient(ctx)))
		ctokens, free := CWStrSlice(tokens)
		defer free()
		var ptr **wchar2_t
		if len(ctokens) > 0 {
			ptr = &ctokens[0]
		}
		return cfnc(int(tokInd), int(len(tokens)), ptr) != 0
	}
}

func Nox_cmd_set_sysop(i int, n int, arr **wchar2_t) int {
	return int(nox_cmd_set_sysop(int32(i), int32(n), arr))
}
func Nox_cmd_set_cycle(i int, n int, arr **wchar2_t) int {
	return int(nox_cmd_set_cycle(int32(i), int32(n), arr))
}
func Nox_cmd_set_weapons(i int, n int, arr **wchar2_t) int {
	return int(nox_cmd_set_weapons(int32(i), int32(n), arr))
}
func Nox_cmd_set_staffs(i int, n int, arr **wchar2_t) int {
	return int(nox_cmd_set_staffs(int32(i), int32(n), arr))
}
func Nox_cmd_set_name(i int, n int, arr **wchar2_t) int {
	return int(nox_cmd_set_name(int32(i), int32(n), arr))
}
func Nox_cmd_set_mnstrs(i int, n int, arr **wchar2_t) int {
	return int(nox_cmd_set_mnstrs(int32(i), int32(n), arr))
}
func Nox_cmd_set_spell(i int, n int, arr **wchar2_t) int {
	return int(nox_cmd_set_spell(int32(i), int32(n), arr))
}
func Nox_cmd_ban(i int, n int, arr **wchar2_t) int {
	return int(nox_cmd_ban(int32(i), int32(n), arr))
}
func Nox_cmd_allow_user(i int, n int, arr **wchar2_t) int {
	return int(nox_cmd_allow_user(int32(i), int32(n), arr))
}
func Nox_cmd_allow_ip(i int, n int, arr **wchar2_t) int {
	return int(nox_cmd_allow_ip(int32(i), int32(n), arr))
}
func Nox_cmd_kick(i int, n int, arr **wchar2_t) int {
	return int(nox_cmd_kick(int32(i), int32(n), arr))
}
func Nox_cmd_set_players(i int, n int, arr **wchar2_t) int {
	return int(nox_cmd_set_players(int32(i), int32(n), arr))
}
func Nox_cmd_set_spellpts(i int, n int, arr **wchar2_t) int {
	return int(nox_cmd_set_spellpts(int32(i), int32(n), arr))
}
func Nox_cmd_list_users(i int, n int, arr **wchar2_t) int {
	return int(nox_cmd_list_users(int32(i), int32(n), arr))
}
func Nox_cmd_unmute(i int, n int, arr **wchar2_t) int {
	return int(nox_cmd_unmute(int32(i), int32(n), arr))
}
func Nox_cmd_mute(i int, n int, arr **wchar2_t) int {
	return int(nox_cmd_mute(int32(i), int32(n), arr))
}
func Nox_cmd_exec_rul(i int, n int, arr **wchar2_t) int {
	return int(nox_cmd_exec_rul(int32(i), int32(n), arr))
}
func Nox_cmd_offonly1(i int, n int, arr **wchar2_t) int {
	return int(nox_cmd_offonly1(int32(i), int32(n), arr))
}
func Nox_cmd_offonly2(i int, n int, arr **wchar2_t) int {
	return int(nox_cmd_offonly2(int32(i), int32(n), arr))
}
func Nox_cmd_set_net_debug(i int, n int, arr **wchar2_t) int {
	return int(nox_cmd_set_net_debug(int32(i), int32(n), arr))
}
func Nox_cmd_unset_net_debug(i int, n int, arr **wchar2_t) int {
	return int(nox_cmd_unset_net_debug(int32(i), int32(n), arr))
}
func Nox_cmd_show_info(i int, n int, arr **wchar2_t) int {
	return int(nox_cmd_show_info(int32(i), int32(n), arr))
}
func Nox_cmd_show_mem(i int, n int, arr **wchar2_t) int {
	return int(nox_cmd_show_mem(int32(i), int32(n), arr))
}
func Nox_cmd_show_rank(i int, n int, arr **wchar2_t) int {
	return int(nox_cmd_show_rank(int32(i), int32(n), arr))
}
func Nox_cmd_show_motd(i int, n int, arr **wchar2_t) int {
	return int(nox_cmd_show_motd(int32(i), int32(n), arr))
}
func Nox_cmd_show_seq(i int, n int, arr **wchar2_t) int {
	return int(nox_cmd_show_seq(int32(i), int32(n), arr))
}
func Nox_cmd_list_maps(i int, n int, arr **wchar2_t) int {
	return int(nox_cmd_list_maps(int32(i), int32(n), arr))
}
func Nox_cmd_cheat_ability(i int, n int, arr **wchar2_t) int {
	return int(nox_cmd_cheat_ability(int32(i), int32(n), arr))
}
func Nox_cmd_cheat_level(i int, n int, arr **wchar2_t) int {
	return int(nox_cmd_cheat_level(int32(i), int32(n), arr))
}
func Nox_cmd_window(i int, n int, arr **wchar2_t) int {
	return int(nox_cmd_window(int32(i), int32(n), arr))
}
func Nox_cmd_set_qual_modem(i int, n int, arr **wchar2_t) int {
	return int(nox_cmd_set_qual_modem(int32(i), int32(n), arr))
}
func Nox_cmd_set_qual_isdn(i int, n int, arr **wchar2_t) int {
	return int(nox_cmd_set_qual_isdn(int32(i), int32(n), arr))
}
func Nox_cmd_set_qual_cable(i int, n int, arr **wchar2_t) int {
	return int(nox_cmd_set_qual_cable(int32(i), int32(n), arr))
}
func Nox_cmd_set_qual_t1(i int, n int, arr **wchar2_t) int {
	return int(nox_cmd_set_qual_t1(int32(i), int32(n), arr))
}
func Nox_cmd_set_qual_lan(i int, n int, arr **wchar2_t) int {
	return int(nox_cmd_set_qual_lan(int32(i), int32(n), arr))
}
func Nox_cmd_set_time(i int, n int, arr **wchar2_t) int {
	return int(nox_cmd_set_time(int32(i), int32(n), arr))
}
func Nox_cmd_set_lessons(i int, n int, arr **wchar2_t) int {
	return int(nox_cmd_set_lessons(int32(i), int32(n), arr))
}
func Nox_cmd_menu_options(i int, n int, arr **wchar2_t) int {
	return int(nox_cmd_menu_options(int32(i), int32(n), arr))
}
func Nox_cmd_menu_vidopt(i int, n int, arr **wchar2_t) int {
	return int(nox_cmd_menu_vidopt(int32(i), int32(n), arr))
}
func Nox_cmd_reenter(i int, n int, arr **wchar2_t) int {
	return int(nox_cmd_reenter(int32(i), int32(n), arr))
}
