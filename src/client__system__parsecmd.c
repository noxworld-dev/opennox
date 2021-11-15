#include "client__system__parsecmd.h"

#include "client__gui__guicon.h"
#include "client__gui__guimsg.h"
#include "client__gui__servopts__general.h"
#include "client__gui__servopts__guiserv.h"
#include "common__log.h"
#include "common__strman.h"
#include "common__system__settings.h"
#include "common__telnet__telnetd.h"
#include "server__script__script.h"

#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME2_2.h"
#include "GAME2_3.h"
#include "GAME3.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4.h"
#include "GAME5_2.h"
#include "client__video__draw_common.h"
#include "common__magic__speltree.h"
#include "static.h"

extern uint32_t dword_5d4594_823696;
extern uint32_t dword_5d4594_1563664;
extern uint32_t nox_xxx_xxxRenderGUI_587000_80832;
extern uint32_t nox_server_connectionType_3596;
extern uint32_t dword_5d4594_805836;
extern uint32_t nox_client_renderGUI_80828;
extern uint32_t dword_5d4594_2650652;
extern uint32_t nox_player_netCode_85319C;

void* nox_client_consoleCurCmd_823700 = 0;

nox_playerInfo* nox_console_playerWhoSent_823692 = 0;

int nox_xxx_consoleTokenPairs_823708 = 0;
unsigned int nox_client_consoleIsServer_823684 = 0;

#ifndef NOX_CGO
enum {
	NOX_CONSOLE_SECRET = 0x40,
};

typedef struct nox_cmd_t nox_cmd_t;
typedef struct nox_cmd_t {
	const wchar_t* token;
	unsigned int token2;
	const char* help_id;
	unsigned int flags;
	nox_cmd_t* sub;
	int (*fnc)(int tokInd, int tokCnt, wchar_t** tokens);
} nox_cmd_t;

#ifdef NOX_DEBUG
int nox_cheats_disabled = 0;
#else
int nox_cheats_disabled = 1;
#endif
int nox_cmd_racoiaws(int, int, wchar_t**);
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
int nox_cmd_help(int, int, wchar_t**);
int nox_cmd_bind(int, int, wchar_t**);
int nox_cmd_reenter(int, int, wchar_t**);
int nox_cmd_startSoloQuest(int, int, wchar_t**);

nox_cmd_t nox_commands_quality[] = {
	{L"modem", 0, "setqualmodemhelp", 0x3, 0, &nox_cmd_set_qual_modem},
	{L"isdn", 0, "setqualisdnhelp", 0x3, 0, &nox_cmd_set_qual_isdn},
	{L"cable", 0, "setqualcablehelp", 0x3, 0, &nox_cmd_set_qual_cable},
	{L"T1", 0, "setqualT1help", 0x3, 0, &nox_cmd_set_qual_t1},
	{L"LAN", 0, "setqualLANhelp", 0x3, 0, &nox_cmd_set_qual_lan},
	{0},
};

nox_cmd_t nox_commands_allow[] = {
	{L"user", 0, "allowuserhelp", 0x1, 0, &nox_cmd_allow_user},
	{L"IP", 0, "allowiphelp", 0x1, 0, &nox_cmd_allow_ip},
	{0},
};

nox_cmd_t nox_commands_cheat[] = {
	{L"ability", 0, "cheatabilityhelp", 0x1, 0, &nox_cmd_cheat_ability},
	{L"goto", 0, "cheatgotohelp", 0x1, 0, &nox_cmd_cheat_goto},
	{L"health", 0, "cheathealthhelp", 0x1, 0, &nox_cmd_cheat_health},
	{L"mana", 0, "cheatmanahelp", 0x1, 0, &nox_cmd_cheat_mana},
	{L"level", 0, "cheatlevelhelp", 0x1, 0, &nox_cmd_cheat_level},
	{L"spells", 0, "cheatspellshelp", 0x1, 0, &nox_cmd_cheat_spells},
	{L"gold", 0, "cheatgoldhelp", 0x1, 0, &nox_cmd_cheat_gold},
	{L"re-enter", 0, "", 0x1, 0, &nox_cmd_reenter},
	{0},
};

nox_cmd_t nox_commands_list[] = {
	{L"armor", 0, "listarmorhelp", 0x3, 0, &nox_cmd_list_armor},
	{L"maps", 0, "listmapshelp", 0x3, 0, &nox_cmd_list_maps},
	{L"spells", 0, "listspellshelp", 0x3, 0, &nox_cmd_list_spells},
	{L"staffs", 0, "liststaffshelp", 0x3, 0, &nox_cmd_list_staffs},
	{L"weapons", 0, "listweaponshelp", 0x3, 0, &nox_cmd_list_weapons},
	{L"users", 0, "listusershelp", 0x3, 0, &nox_cmd_list_users},
	{0},
};

nox_cmd_t nox_commands_log[] = {
	{L"console", 0, "logconsolehelp", 0x3, 0, &nox_cmd_log_console},
	{L"file", 0, "logfilehelp", 0x3, 0, &nox_cmd_log_file},
	{L"stop", 0, "logstophelp", 0x3, 0, &nox_cmd_log_stop},
	{0},
};

nox_cmd_t nox_commands_macros[] = {
	{L"on", 0, "macrosonhelp", 0x1, 0, &nox_cmd_macros_on},
	{L"off", 0, "macrosoffhelp", 0x1, 0, &nox_cmd_macros_off},
	{0},
};

nox_cmd_t nox_commands_menu[] = {
	{L"vidopt", 0, "menuvidopthelp", 0x3, 0, &nox_cmd_menu_vidopt},
	{L"options", 0, "menuoptionshelp", 0x3, 0, &nox_cmd_menu_options},
	{0},
};

nox_cmd_t nox_commands_set[] = {
	{L"armor", 0, "setarmorhelp", 0x1, 0, &nox_cmd_set_armor},
	{L"cycle", 0, "setcyclehelp", 0x1, 0, &nox_cmd_set_cycle},
	{L"frameratelimiter", 0, "setfrhelp", 0x11, 0, &nox_cmd_set_fr},
	{L"god", 0, "setgodhelp", 0x11, 0, &nox_cmd_set_god},
	{L"lessons", 0, "setlessonshelp", 0x1, 0, &nox_cmd_set_lessons},
	{L"monsters", 0, "setmnstrshelp", 0x11, 0, &nox_cmd_set_mnstrs},
	{L"name", 0, "setnamehelp", 0x1, 0, &nox_cmd_set_name},
	{L"netdebug", 0, "setnetdebughelp", 0x13, 0, &nox_cmd_set_net_debug},
	{L"ob", 0, "setobshelp", 0x13, 0, &nox_cmd_set_obs},
	{L"players", 0, "setplayershelp", 0x1, 0, &nox_cmd_set_players},
	{L"quality", 0, "setqualityhelp", 0x3, nox_commands_quality, 0},
	{L"sage", 0, "setsagehelp", 0x11, 0, &nox_cmd_set_sage},
	{L"savedebugcmd", 0, "setsavedebughelp", 0x1, 0, &nox_cmd_set_save_debug},
	{L"spell", 0, "setspellhelp", 0x1, 0, &nox_cmd_set_spell},
	{L"spellpoints", 0, "setspellptshelp", 0x11, 0, &nox_cmd_set_spellpts},
	{L"staff", 0, "setstaffhelp", 0x11, 0, &nox_cmd_set_staff},
	{L"staffs", 0, "setstaffshelp", 0x11, 0, &nox_cmd_set_staffs},
	{L"sysop", 0, "setsysophelp", 0x1, 0, &nox_cmd_set_sysop},
	{L"time", 0, "settimehelp", 0x1, 0, &nox_cmd_set_time},
	{L"weapon", 0, "setweaponhelp", 0x1, 0, &nox_cmd_set_weapon},
	{L"weapons", 0, "setweaponshelp", 0x11, 0, &nox_cmd_set_weapons},
	{L"team", 0, "officialonly", 0x31, 0, &nox_cmd_offonly1},
	{L"mode", 0, "officialonly", 0x31, 0, &nox_cmd_offonly2},
	{0},
};

nox_cmd_t nox_commands_show[] = {
	{L"bindings", 0, "showbindingshelp", 0x3, 0, &nox_cmd_show_bindings},
	{L"game", 0, "showgamehelp", 0x3, 0, &nox_cmd_show_game},
	{L"motd", 0, "showmotdhelp", 0x3, 0, &nox_cmd_show_motd},
	{L"rank", 0, "showrankhelp", 0x3, 0, &nox_cmd_show_rank},
	{L"perfmon", 0, "showperfmonhelp", 0x3, 0, &nox_cmd_show_perfmon},
	{L"extents", 0, "showextentshelp", 0x13, 0, &nox_cmd_show_extents},
	{L"gui", 0, "showguihelp", 0x3, 0, &nox_cmd_show_gui},
	{L"ai", 0, "showaihelp", 0x11, 0, &nox_cmd_show_ai},
	{L"info", 0, "showinfohelp", 0x7, 0, &nox_cmd_show_info},
	{L"mem", 0, "showmemhelp", 0x13, 0, &nox_cmd_show_mem},
	{L"netstat", 0, "shownetstathelp", 0x3, 0, &nox_cmd_show_netstat},
	{L"mmx", 0, "showmmxhelp", 0x3, 0, &nox_cmd_show_mmx},
	{L"seq", 0, "showseqhelp", 0x13, 0, &nox_cmd_show_seq},
	{0},
};

nox_cmd_t nox_commands_telnet[] = {
	{L"on", 0, "telnetonhelp", 0x1, 0, &nox_cmd_telnet_on},
	{L"off", 0, "telnetoffhelp", 0x1, 0, &nox_cmd_telnet_off},
	{0},
};

nox_cmd_t nox_commands_unset[] = {
	{L"god", 0, "unsetgodhelp", 0x1, 0, &nox_cmd_unset_god},
	{L"frameratelimiter", 0, "unsetfrhelp", 0x1, 0, &nox_cmd_unset_fr},
	{L"netdebug", 0, "unsetnetdebug", 0x3, 0, &nox_cmd_unset_net_debug},
	{L"sage", 0, "unsetsagehelp", 0x1, 0, &nox_cmd_unset_sage},
	{0},
};

nox_cmd_t nox_commands[] = {
	{L"0YAKikQs", 0, "noHelp", NOX_CONSOLE_SECRET | 0x7, 0, &nox_cmd_racoiaws},
	{L"allow", 0, "allowhelp", 0x1, nox_commands_allow, 0},
	{L"audtest", 0, "sethelp", 0x3, 0, &nox_cmd_set},
	{L"ban", 0, "banhelp", 0x1, 0, &nox_cmd_ban},
	{L"bind", 0, "bindHelp", 0x3, 0, &nox_cmd_bind},
	{L"broadcast", 0, "broadcasthelp", 0x1, 0, &nox_cmd_broadcast},
	{L"cheat", 0, "cheathelp", 0x11, nox_commands_cheat, 0},
	{L"clear", 0, "clearhelp", 0x3, 0, &nox_cmd_clear},
	{L"exec", 0, "exechelp", 0x1, 0, &nox_cmd_exec},
	{L"execrul", 0, "execrulhelp", 0x3, 0, &nox_cmd_exec_rul},
	{L"exit", 0, "exithelp", 0x3, 0, &nox_cmd_exit},
	{L"gamma", 0, "gammahelp", 0x3, 0, &nox_cmd_gamma},
	{L"help", 0, "helphelp", 0x3, 0, &nox_cmd_help},
	{L"image", 0, "imagehelp", 0x3, 0, &nox_cmd_image},
	{L"kick", 0, "kickhelp", 0x1, 0, &nox_cmd_kick},
	{L"list", 0, "listhelp", 0x3, nox_commands_list, 0},
	{L"lock", 0, "lockhelp", 0x3, 0, &nox_cmd_lock},
	{L"load", 0, "loadhelp", 0x11, 0, &nox_cmd_load},
	{L"log", 0, "loghelp", 0x13, nox_commands_log, 0},
	{L"macros", 0, "macroshelp", 0x3, nox_commands_macros, 0},
	{L"menu", 0, "menuhelp", 0x3, nox_commands_menu, 0},
	{L"mute", 0, "mutehelp", 0x3, 0, &nox_cmd_mute},
	{L"quit", 0, "quithelp", 0x3, 0, &nox_cmd_quit},
	{L"say", 0, "sayhelp", 0x3, 0, &nox_cmd_say},
	{L"set", 0, "sethelp", 0x3, nox_commands_set, 0},
	{L"show", 0, "showhelp", 0x3, nox_commands_show, 0},
	{L"sysop", 0, "nohelp", 0x7, 0, &nox_cmd_sysop},
	{L"telnet", 0, "telnethelp", 0x1, nox_commands_telnet, 0},
	{L"unset", 0, "unsethelp", 0x3, nox_commands_unset, 0},
	{L"unmute", 0, "unmutehelp", 0x3, 0, &nox_cmd_unmute},
	{L"unbind", 0, "unbindHelp", 0x3, 0, &nox_cmd_unbind},
	{L"unlock", 0, "unlockhelp", 0x3, 0, &nox_cmd_unlock},
	{L"watch", 0, "watchhelp", 0x3, 0, &nox_cmd_watch},
	{L"window", 0, "windowhelp", 0x3, 0, &nox_cmd_window},
	{L"startSoloQuest", 0, "nohelp", 0x5, 0, &nox_cmd_startSoloQuest},
	{L"ques", 0, "helphelp", 0x3, 0, &nox_cmd_help},
	{0},
};

//----- (00440D70) --------------------------------------------------------
int nox_cmd_racoiaws(int tokInd, int tokCnt, wchar_t** tokens) {
	nox_cheats_disabled = 0;
	return 1;
}
#endif // NOX_CGO

//----- (00440D80) --------------------------------------------------------
int nox_cmd_lock(int tokInd, int tokCnt, wchar_t** tokens) {
	if (tokCnt != 2) {
		return 0;
	}
	nox_gui_console_Lock_450B20(tokens[1]);
	nox_gui_console_Clear_450B70();
	wchar_t* s = nox_strman_loadString_40F1D0("consolelocked", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1329);
	nox_gui_console_Printf_450C00(NOX_CONSOLE_WHITE, s);
	return 1;
}

//----- (00440DD0) --------------------------------------------------------
int nox_cmd_unlock(int tokInd, int tokCnt, wchar_t** tokens) {
	if (tokCnt != 1) {
		return 0;
	}
	nox_gui_console_Unlock_450B50();
	wchar_t* s =
		nox_strman_loadString_40F1D0("consoleunlocked", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1340);
	nox_gui_console_Printf_450C00(NOX_CONSOLE_WHITE, s);
	return 1;
}

//----- (00440E10) --------------------------------------------------------
int nox_cmd_set_sysop(int tokInd, int tokCnt, wchar_t** tokens) {
	if (tokCnt != 3) {
		return 0;
	}
	nox_xxx_sysopSetPass_40A610(tokens[tokInd]);
	wchar_t* s =
		nox_strman_loadString_40F1D0("sysoppasswordset", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1352);
	nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, s);
	return 1;
}

#ifndef NOX_CGO
//----- (00440E60) --------------------------------------------------------
int nox_cmd_telnet_off(int tokInd, int tokCnt, wchar_t** tokens) {
	if (tokCnt != 2) {
		return 0;
	}
	if (!nox_common_gameFlags_check_40A5C0(2048)) {
		nox_telnet_stop_579830();
		wchar_t* s = nox_strman_loadString_40F1D0("telnetoff", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1368);
		nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, s);
	}
	return 1;
}

//----- (00440EB0) --------------------------------------------------------
int nox_cmd_telnet_on(int tokInd, int tokCnt, wchar_t** tokens) {
	if (tokCnt < 2 || tokCnt > 3) {
		return 0;
	}
	if (nox_common_gameFlags_check_40A5C0(2048)) {
		return 1;
	}
	if (tokCnt == 2) {
		nox_telnet_start_5797F0(0);
	} else {
		unsigned short v = nox_wcstol(tokens[tokCnt - 1], 0, 10);
		nox_telnet_start_5797F0(v);
	}
	int port = nox_telnet_getPort_579850();
	wchar_t* s = nox_strman_loadString_40F1D0("telneton", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1388);
	nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, s, port);
	return 1;
}
#endif // NOX_CGO

//----- (00440F50) --------------------------------------------------------
int nox_cmd_macros_on(int tokInd, int tokCnt, wchar_t** tokens) {
	if (tokCnt != 2) {
		return 0;
	}
	*getMemU32Ptr(0x587000, 95416) = 1;
	wchar_t* s = nox_strman_loadString_40F1D0("macroson", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1400);
	nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, s);
	return 1;
}

//----- (00440F90) --------------------------------------------------------
int nox_cmd_macros_off(int tokInd, int tokCnt, wchar_t** tokens) {
	if (tokCnt != 2) {
		return 0;
	}
	*getMemU32Ptr(0x587000, 95416) = 0;
	wchar_t* s = nox_strman_loadString_40F1D0("macrosoff", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1411);
	nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, s);
	return 1;
}

//----- (00441050) --------------------------------------------------------
int nox_cmd_list_weapons(int tokInd, int tokCnt, wchar_t** tokens) {
	wchar_t* allow = nox_strman_loadString_40F1D0("allowed", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1460);
	wchar_t* disallow =
		nox_strman_loadString_40F1D0("disallowed", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1461);
	for (nox_objectType_t* typ = nox_xxx_getFirstObjectType_4E3B30(); typ; typ = nox_xxx_objectType_next_4E3B40(typ)) {
		if ((typ->obj_class & 0x1000000) == 0) {
			continue;
		}
		int v3 = sub_415910(typ->id);
		int v4 = sub_4159F0(v3);
		if (!v4) {
			continue;
		}
		wchar_t* v5;
		wchar_t* v8;
		if (nox_xxx_getUnitDefDd10_4E3BA0(typ->ind)) {
			v8 = allow;
			v5 = nox_strman_loadString_40F1D0("itemdisplay", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1475);
		} else {
			v8 = disallow;
			v5 = nox_strman_loadString_40F1D0("itemdisplay", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1477);
		}
		nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v5, v4, v8);
	}
	return 1;
}

//----- (00441130) --------------------------------------------------------
int nox_cmd_list_armor(int tokInd, int tokCnt, wchar_t** tokens) {
	wchar_t* v0; // ebx
	wchar_t* v1; // ebp
	char** v2;   // edi
	int v3;      // eax
	int v4;      // esi
	wchar_t* v5; // eax
	int v7;      // [esp-Ch] [ebp-18h]
	wchar_t* v8; // [esp-8h] [ebp-14h]

	v0 = nox_strman_loadString_40F1D0("allowed", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1492);
	v1 = nox_strman_loadString_40F1D0("disallowed", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1493);
	v2 = (char**)nox_xxx_getFirstObjectType_4E3B30();
	while (v2) {
		if ((unsigned int)v2[6] & 0x2000000) {
			v3 = sub_415DF0(v2[1]);
			v4 = sub_415E80(v3);
			if (v4) {
				if (nox_xxx_getUnitDefDd10_4E3BA0(*(unsigned short*)v2)) {
					v8 = v0;
					v7 = v4;
					v5 = nox_strman_loadString_40F1D0("itemdisplay", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
													  1508);
				} else {
					v8 = v1;
					v7 = v4;
					v5 = nox_strman_loadString_40F1D0("itemdisplay", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
													  1510);
				}
				nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v5, v7, v8);
			}
		}
		v2 = (char**)nox_xxx_objectType_next_4E3B40((int)v2);
	}
	return 1;
}

//----- (00441210) --------------------------------------------------------
#ifndef NOX_CGO
int nox_cmd_list_spells(int tokInd, int tokCnt, wchar_t** tokens) {
	wchar_t* v0; // edi
	wchar_t* v1; // ebx
	wchar_t* v3; // eax
	int v5;      // [esp-Ch] [ebp-18h]
	int v6;      // [esp-8h] [ebp-14h]
	wchar_t* v7; // [esp-4h] [ebp-10h]

	v0 = nox_strman_loadString_40F1D0("allowed", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1524);
	v1 = nox_strman_loadString_40F1D0("disallowed", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1525);
	for (int i = 1; i < NOX_SPELLS_MAX; i++) {
		if (!nox_xxx_spellIsValid_424B50(i)) {
			continue;
		}
		if (nox_xxx_spellIsEnabled_424B70(i)) {
			v7 = v0;
		} else {
			v7 = v1;
		}
		v6 = nox_xxx_spellManaCost_4249A0(i, 1);
		v5 = nox_xxx_spellTitle_424930(i);
		v3 = nox_strman_loadString_40F1D0("SpellFmt", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1531);
		nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3, v5, v6, v7);
	}
	return 1;
}
#endif // NOX_CGO

//----- (004412E0) --------------------------------------------------------
int nox_cmd_list_staffs(int tokInd, int tokCnt, wchar_t** tokens) {
	wchar_t* v0;        // ebx
	wchar_t* v1;        // ebp
	unsigned short* v2; // edi
	int v3;             // eax
	int v4;             // eax
	int v5;             // esi
	wchar_t* v6;        // eax
	int v8;             // [esp-Ch] [ebp-18h]
	wchar_t* v9;        // [esp-8h] [ebp-14h]

	v0 = nox_strman_loadString_40F1D0("allowed", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1588);
	v1 = nox_strman_loadString_40F1D0("disallowed", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1589);
	v2 = (unsigned short*)nox_xxx_getFirstObjectType_4E3B30();
	while (v2) {
		v3 = *((uint32_t*)v2 + 6);
		if (v3 & 0x1000) {
			v4 = sub_415910(*((char**)v2 + 1));
			v5 = sub_4159F0(v4);
			if (v5) {
				if (nox_xxx_getUnitDefDd10_4E3BA0(*v2)) {
					v9 = v0;
					v8 = v5;
					v6 = nox_strman_loadString_40F1D0("itemdisplay", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
													  1604);
				} else {
					v9 = v1;
					v8 = v5;
					v6 = nox_strman_loadString_40F1D0("itemdisplay", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
													  1606);
				}
				nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v6, v8, v9);
			}
		}
		v2 = (unsigned short*)nox_xxx_objectType_next_4E3B40((int)v2);
	}
	return 1;
}

//----- (004413C0) --------------------------------------------------------
int nox_cmd_show_bindings(int tokInd, int tokCnt, wchar_t** tokens) {
	unsigned char* v3; // esi
	wchar_t* v4;       // eax

	if (tokCnt != 2) {
		return 0;
	}
	v3 = getMemAt(0x587000, 94516);
	do {
		if (*(uint16_t*)v3) {
			nox_gui_console_Printf_450C00(NOX_CONSOLE_WHITE, (wchar_t*)getMemAt(0x587000, 102824), *((uint32_t*)v3 - 2),
										  v3);
		}
		v3 += 76;
	} while ((int)v3 - (int)getMemAt(0x587000, 94516) < 912);
	if (*getMemU32Ptr(0x587000, 95416)) {
		v4 = nox_strman_loadString_40F1D0("macrosOn", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1630);
	} else {
		v4 = nox_strman_loadString_40F1D0("macrosOff", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1632);
	}
	nox_gui_console_Printf_450C00(NOX_CONSOLE_WHITE, v4);
	return 1;
}

//----- (00441550) --------------------------------------------------------
int nox_cmd_show_game(int tokInd, int tokCnt, wchar_t** tokens) {
	char* v2;        // esi
	int v4;          // edi
	int v5;          // eax
	wchar_t* v6;     // eax
	short v7;        // ax
	wchar_t* v8;     // eax
	wchar_t* v9;     // eax
	char* v11;       // eax
	char* v12;       // [esp-18h] [ebp-5Ch]
	int v13;         // [esp-10h] [ebp-54h]
	int v14;         // [esp-Ch] [ebp-50h]
	char* v15;       // [esp-8h] [ebp-4Ch]
	int v16;         // [esp-8h] [ebp-4Ch]
	int v17;         // [esp-8h] [ebp-4Ch]
	wchar_t v18[32]; // [esp+4h] [ebp-40h]

	v2 = sub_4165B0();
	if (tokCnt != 2) {
		return 0;
	}
	v4 = nox_common_playerInfoCount_416F40();
	if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
		--v4;
	}
	v5 = nox_client_getVersionBuild_409AC0();
	nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, (wchar_t*)getMemAt(0x587000, 102952), nox_version_string_102944, v5);
	if (nox_common_gameFlags_check_40A5C0(0x2000)) {
		v15 = nox_xxx_serverOptionsGetServername_40A4C0();
		v6 = nox_strman_loadString_40F1D0("Name", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1801);
		nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, (wchar_t*)getMemAt(0x587000, 103028), v6, v15);
		v7 = nox_common_gameFlags_getVal_40A5B0();
		v16 = nox_xxx_guiServerOptionsGetGametypeName_4573C0(v7);
		v8 = nox_strman_loadString_40F1D0("Type", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1802);
		nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, (wchar_t*)getMemAt(0x587000, 103088), v8, v16);
		v17 = sub_40A180(*((uint16_t*)v2 + 26));
		v14 = (unsigned short)nox_xxx_servGamedataGet_40A020(*((uint16_t*)v2 + 26));
		v13 = nox_xxx_servGetPlrLimit_409FA0();
		v12 = nox_server_currentMapGetFilename_409B30();
		v9 = nox_strman_loadString_40F1D0("GameInfo", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1803);
		nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v9, v12, v4, v13, v14, v17);
		v11 = nox_net_ip2str(nox_xxx_net_getIP_554200(0));
		nox_swprintf(v18, L"%S", v11);
		nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, (wchar_t*)getMemAt(0x587000, 103160), v18);
	}
	return 1;
}

//----- (004416F0) --------------------------------------------------------
int nox_cmd_show_mmx(int tokInd, int tokCnt, wchar_t** tokens) {
	wchar_t* s;

	if (dword_5d4594_805836) {
		s = nox_strman_loadString_40F1D0("MMXEnabled", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1869);
	} else {
		s = nox_strman_loadString_40F1D0("MMXNotEnabled", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 1871);
	}
	nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, s);
	return 1;
}

//----- (00440A20) --------------------------------------------------------
void sub_440A20(wchar_t* a1, ...) {
	va_list va; // [esp+8h] [ebp+8h]

	va_start(va, a1);
	nox_vswprintf((wchar_t*)getMemAt(0x5D4594, 822660), a1, va);
	nox_xxx_printCentered_445490((wchar_t*)getMemAt(0x5D4594, 822660));
}

//----- (00441910) --------------------------------------------------------
int nox_cmd_load(int tokInd, int tokCnt, wchar_t** tokens) {
	int v4;             // eax
	int v5;             // ebx
	wchar_t* v6;        // eax
	unsigned int v7;    // kr04_4
	char* v8;           // ebx
	wchar_t* v9;        // eax
	char* v10;          // [esp-4h] [ebp-234h]
	char v11[260];      // [esp+8h] [ebp-228h]
	struct _stat v12;   // [esp+10Ch] [ebp-124h]
	char FileName[256]; // [esp+130h] [ebp-100h]

	if (nox_common_gameFlags_check_40A5C0(4096)) {
		return 1;
	}
	if (tokCnt != 2) {
		return 0;
	}
	nox_sprintf(&v11[4], "%S", tokens[1]);
	if (v11[4] != 35 && !nox_common_checkMapFile_4CFE10(&v11[4])) {
		return 1;
	}
	v4 = nox_xxx_mapGetTypeMB_4CFFA0((int)getMemAt(0x973F18, 2408));
	v5 = v4;
	if (nox_common_gameFlags_check_40A5C0(0x2000)) {
		if (!(v5 && !(v5 & 0x200))) {
			return 1;
		}
		if (nox_common_gameFlags_check_40A5C0(128)) {
			if (v5 & 0x60 && nox_xxx_getTeamCounter_417DD0() != 2) {
				nox_xxx_wndGuiTeamCreate_4185B0();
			}
		} else if (!(nox_common_gameFlags_getVal_40A5B0() & v5)) {
			v6 = nox_strman_loadString_40F1D0("NoMapLoadNewMode", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
											  2005);
			sub_440A20(v6);
			return 1;
		}
	} else if (!(v5 & 0x200)) {
		return 1;
	}
	v7 = strlen(&v11[4]) + 1;
	if ((int)(v7 - 1) <= 4 || _strcmpi(&v11[v7 - 1], ".map")) {
		strcpy((char*)getMemAt(0x5D4594, 822324), &v11[4]);
		v8 = (char*)getMemAt(0x5D4594, 822324);
		strcat((char*)getMemAt(0x5D4594, 822324), ".map");
	} else {
		v8 = &v11[4];
	}
	if (!v8 ||
		*v8 != 35 && (strcpy(FileName, "maps\\"), strncat(FileName, v8, (strlen(v8) - 4 < 256 ? strlen(v8) - 4 : 256)),
					  *(uint16_t*)&FileName[strlen(FileName)] = *getMemU16Ptr(0x587000, 103416), strcat(FileName, v8),
					  _stat(FileName, (int)&v12))) {
		v10 = v8;
		v9 = nox_strman_loadString_40F1D0("CannotAccessMap", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2076);
	} else {
		nox_xxx_mapLoadOrSaveMB_4DCC70(1);
		nox_xxx_mapLoad_4D2450(v8);
		sub_41D650();
		v10 = v8;
		v9 = nox_strman_loadString_40F1D0("maploaded", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2072);
	}
	sub_440A20(v9, v10);
	return 1;
}

// 44198D: variable 'v4' is possibly undefined

#ifndef NOX_CGO
//----- (00441B90) --------------------------------------------------------
void nox_cmd_help_2_441B90(nox_cmd_t cmds[]) {
	if (!cmds || !cmds[0].token) {
		return;
	}
	for (nox_cmd_t* cmd = &cmds[0]; cmd->token; cmd++) {
		if (!(cmd->flags & 4) && (!nox_cheats_disabled || !(cmd->flags & 0x10))) {
			wchar_t* help =
				nox_strman_loadString_40F1D0(cmd->help_id, 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2097);
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, L"\t%s -\t%s", cmd->token2, help);
		}
	}
}

//----- (00441BF0) --------------------------------------------------------
int nox_cmd_help_1_441BF0(int tokInd, int tokCnt, wchar_t** tokens, nox_cmd_t* cmds) {
	if (!tokens[tokInd] || !cmds || !cmds[0].token) {
		return 0;
	}
	int v5 = 0;
	const wchar_t** v6 = cmds;
	const wchar_t** v7 = cmds;
	while (1) {
		if (!_nox_wcsicmp(tokens[tokInd], *v6)) {
			char v8 = *((uint8_t*)v7 + 12);
			if (!(v8 & 4) && (!nox_cheats_disabled || !(v8 & 0x10))) {
				break;
			}
		}
		const wchar_t* v9 = v7[6];
		v7 += 6;
		++v5;
		v6 = v7;
		if (!v9) {
			return 0;
		}
	}
	nox_cmd_t* cmd = &cmds[v5];
	if (cmd->sub) {
		if (tokCnt <= tokInd + 1) {
			nox_cmd_help_2_441B90(cmd->sub);
			return 1;
		}
		int res = nox_cmd_help_1_441BF0(tokInd + 1, tokCnt, tokens, cmd->sub);
		if (res == 0) {
			nox_cmd_help_2_441B90(cmd->sub);
			return 1;
		}
		return res;
	} else {
		wchar_t* help =
			nox_strman_loadString_40F1D0(cmd->help_id, 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2135);
		nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, help);
		return 1;
	}
	return 0;
}

//----- (00441CE0) --------------------------------------------------------
int nox_cmd_help(int tokInd, int tokCnt, wchar_t** tokens) {
	if (tokCnt != 1) {
		return nox_cmd_help_1_441BF0(1, tokCnt, tokens, nox_commands);
	}
	nox_cmd_help_2_441B90(nox_commands);
	return 1;
}
#endif // NOX_CGO

//----- (004421A0) --------------------------------------------------------
int nox_cmd_set_obs(int tokInd, int tokCnt, wchar_t** tokens) {
	wchar_t* s = nox_strman_loadString_40F1D0("processingobs", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2440);
	nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, s);
	if (nox_common_gameFlags_check_40A5C0(1)) {
		char* v2 = nox_common_playerInfoGetByID_417040(nox_player_netCode_85319C);
		nox_xxx_serverHandleClientConsole_443E90((int)v2, 0, *(wchar_t**)&nox_client_consoleCurCmd_823700);
	} else {
		nox_xxx_netServerCmd_440950(0, *(wchar_t**)&nox_client_consoleCurCmd_823700);
	}
	return 1;
}

//----- (004423D0) --------------------------------------------------------
int nox_cmd_set_save_debug(int tokInd, int tokCnt, wchar_t** tokens) {
	nox_common_setEngineFlag(NOX_ENGINE_FLAG_SAVE_DEBUG);
	wchar_t* s = nox_strman_loadString_40F1D0("savedebugset", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2541);
	nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, s);
	return 1;
}

#ifndef NOX_CGO
//----- (00442410) --------------------------------------------------------
int nox_cmd_set_god(int tokInd, int tokCnt, wchar_t** tokens) {
	if (!nox_common_gameFlags_check_40A5C0(4096)) {
		nox_xxx_set_god_4EF500(1);
		wchar_t* s = nox_strman_loadString_40F1D0("godset", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2557);
		nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, s);
	}
	return 1;
}

//----- (00442450) --------------------------------------------------------
int nox_cmd_unset_god(int tokInd, int tokCnt, wchar_t** tokens) {
	nox_xxx_set_god_4EF500(0);
	wchar_t* s = nox_strman_loadString_40F1D0("godunset", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2568);
	nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, s);
	return 1;
}
//----- (00442480) --------------------------------------------------------
int nox_cmd_set_sage(int tokInd, int tokCnt, wchar_t** tokens) {
	if (!nox_common_gameFlags_check_40A5C0(4096)) {
		nox_xxx_set_sage(1);
		wchar_t* s = nox_strman_loadString_40F1D0("sageset", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2585);
		nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, s);
	}
	return 1;
}

//----- (004424C0) --------------------------------------------------------
int nox_cmd_unset_sage(int tokInd, int tokCnt, wchar_t** tokens) {
	nox_xxx_set_sage(0);
	wchar_t* s = nox_strman_loadString_40F1D0("sageunset", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2597);
	nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, s);
	return 1;
}
#endif // NOX_CGO

//----- (004424F0) --------------------------------------------------------
int nox_cmd_set_cycle(int tokInd, int tokCnt, wchar_t** tokens) {
	wchar_t* v3;
	if (tokCnt == 3) {
		if (!_nox_wcsicmp(tokens[tokInd], L"on")) {
			sub_4D0D90(1);
			v3 = nox_strman_loadString_40F1D0("MapCycleOn", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2614);
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3);
			sub_4AD840();
			return 1;
		}
		if (!_nox_wcsicmp(tokens[tokInd], L"off")) {
			sub_4D0D90(0);
			v3 = nox_strman_loadString_40F1D0("MapCycleOff", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2621);
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3);
			sub_4AD840();
			return 1;
		}
	}
	return 0;
}

//----- (00442590) --------------------------------------------------------
int nox_cmd_set_weapons(int tokInd, int tokCnt, wchar_t** tokens) {
	wchar_t* v3;
	wchar_t* v5;
	if (tokCnt == 3) {
		if (!_nox_wcsicmp(tokens[tokInd], L"on")) {
			sub_409E70(1);
			nox_server_gameSettingsUpdated_40A670();
			v5 = nox_strman_loadString_40F1D0("cmd_token:on", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2644);
			v3 = nox_strman_loadString_40F1D0("weapons", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2645);
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3, v5);
			return 1;
		}
		if (!_nox_wcsicmp(tokens[tokInd], L"off")) {
			sub_409EC0(1);
			nox_server_gameSettingsUpdated_40A670();
			v5 = nox_strman_loadString_40F1D0("cmd_token:off", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2652);
			v3 = nox_strman_loadString_40F1D0("weapons", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2653);
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3, v5);
			return 1;
		}
	}
	return 0;
}

//----- (00442670) --------------------------------------------------------
int nox_cmd_set_staffs(int tokInd, int tokCnt, wchar_t** tokens) {
	wchar_t* v3;
	wchar_t* v5;
	if (tokCnt == 3) {
		if (!_nox_wcsicmp(tokens[tokInd], L"on")) {
			sub_409E70(16);
			nox_server_gameSettingsUpdated_40A670();
			v5 = nox_strman_loadString_40F1D0("cmd_token:on", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2674);
			v3 = nox_strman_loadString_40F1D0("staffs", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2675);
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3, v5);
			return 1;
		}
		if (!_nox_wcsicmp(tokens[tokInd], L"off")) {
			sub_409EC0(16);
			nox_server_gameSettingsUpdated_40A670();
			v5 = nox_strman_loadString_40F1D0("cmd_token:off", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2682);
			v3 = nox_strman_loadString_40F1D0("staffs", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2683);
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3, v5);
			return 1;
		}
	}
	return 0;
}
//----- (00442840) --------------------------------------------------------
int nox_cmd_set_name(int tokInd, int tokCnt, wchar_t** tokens) {
	int v3;          // ebx
	unsigned int v5; // edx
	char* v6;        // edi
	char* v7;        // edi
	char* v8;        // esi
	char v9;         // cl
	int v10;         // edx
	wchar_t* v11;    // eax
	uint32_t* v12;   // [esp+4h] [ebp-104h]
	char v13[128];   // [esp+8h] [ebp-100h]
	char v14[128];   // [esp+88h] [ebp-80h]

	v3 = tokInd;
	if (tokCnt < 3) {
		return 0;
	}
	v13[0] = 0;
	if (tokInd < tokCnt) {
		v12 = &tokens[tokInd];
		do {
			nox_sprintf(v14, "%S", *v12);
			v5 = strlen(v14) + 1;
			v6 = &v13[strlen(v13)];
			memcpy(v6, v14, 4 * (v5 >> 2));
			v8 = &v14[4 * (v5 >> 2)];
			v7 = &v6[4 * (v5 >> 2)];
			v9 = v5;
			v10 = v3 + 1;
			memcpy(v7, v8, v9 & 3);
			if (v3 + 1 < tokCnt) {
				*(uint16_t*)&v13[strlen(v13)] = *getMemU16Ptr(0x587000, 104484);
			}
			++v3;
			++v12;
		} while (v10 < tokCnt);
		if (v13[0]) {
			nox_xxx_gameSetServername_40A440(v13);
			v11 = nox_strman_loadString_40F1D0("setgamename", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2766);
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v11, v13);
		}
	}
	return 1;
}
// 442840: using guessed type char var_100[128];
// 442840: using guessed type char var_80[128];

//----- (00442950) --------------------------------------------------------
int nox_cmd_set_mnstrs(int tokInd, int tokCnt, wchar_t** tokens) {
	wchar_t* v3; // eax
	wchar_t* v5; // [esp-4h] [ebp-10h]

	if (tokCnt == 3 || tokCnt == 4) {
		if (_nox_wcsicmp(tokens[2], *(const wchar_t**)getMemAt(0x587000, 94492))) {
			if (!_nox_wcsicmp(tokens[tokInd], L"on")) {
				sub_409E70(4);
				nox_server_gameSettingsUpdated_40A670();
				v5 = nox_strman_loadString_40F1D0("cmd_token:on", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
												  2810);
				v3 = nox_strman_loadString_40F1D0("monsters", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2811);
				nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3, v5);
				return 1;
			}
			if (!_nox_wcsicmp(tokens[tokInd], L"off")) {
				sub_409EC0(4);
				nox_server_gameSettingsUpdated_40A670();
				v5 = nox_strman_loadString_40F1D0("cmd_token:off", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
												  2818);
				v3 = nox_strman_loadString_40F1D0("monsters", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 2819);
				nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3, v5);
				return 1;
			}
		} else if (tokCnt != 3) {
			if (!_nox_wcsicmp(tokens[3], L"on")) {
				sub_409E70(8);
				nox_server_gameSettingsUpdated_40A670();
				v5 = nox_strman_loadString_40F1D0("cmd_token:on", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
												  2788);
				v3 = nox_strman_loadString_40F1D0("monsterrespawn", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
												  2789);
				nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3, v5);
				return 1;
			}
			if (!_nox_wcsicmp(tokens[3], L"off")) {
				sub_409E70(8);
				nox_server_gameSettingsUpdated_40A670();
				v5 = nox_strman_loadString_40F1D0("cmd_token:off", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
												  2796);
				v3 = nox_strman_loadString_40F1D0("monsterrespawn", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
												  2797);
				nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3, v5);
				return 1;
			}
		}
	}
	return 0;
}

//----- (00442B00) --------------------------------------------------------
int nox_cmd_set_spell(int tokInd, int tokCnt, wchar_t** tokens) {
	wchar_t* v3;   // eax
	int v4;        // esi
	char* v5;      // ebx
	wchar_t* v7;   // eax
	int v8;        // [esp-4h] [ebp-74h]
	int v9;        // [esp-4h] [ebp-74h]
	char v10[100]; // [esp+Ch] [ebp-64h]

	if (tokCnt == 4) {
		if (nox_common_gameFlags_check_40A5C0(128)) {
			v8 = tokens[2];
			v3 = nox_strman_loadString_40F1D0("NotInChat", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3293);
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3, v8);
			return 1;
		}
		v4 = nox_xxx_spellByTitle_424960(tokens[2]);
		if (v4 || (nox_sprintf(v10, "%S", tokens[2]), (v4 = nox_xxx_spellNameToN_4243F0(v10)) != 0)) {
			if (!_nox_wcsicmp(tokens[3], L"on")) {
				v5 = sub_4165B0();
				if ((nox_common_gameFlags_check_40A5C0(64) || v5[52] & 0x40) && v4 == 132) {
					return 1;
				}
				if (nox_xxx_spellIsEnabled_424B70(v4)) {
					return 1;
				}
				nox_xxx_spellEnable_424B90(v4);
				nox_server_gameSettingsUpdated_40A670();
				v8 = tokens[2];
				v3 = nox_strman_loadString_40F1D0("spellenabled", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
												  3324);
				nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3, v8);
				return 1;
			}
			if (!_nox_wcsicmp(tokens[3], L"off")) {
				if (!nox_xxx_spellIsEnabled_424B70(v4)) {
					return 1;
				}
				nox_xxx_spellDisable_424BB0(v4);
				nox_server_gameSettingsUpdated_40A670();
				v8 = tokens[2];
				v3 = nox_strman_loadString_40F1D0("spelldisabled", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
												  3333);
				nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3, v8);
				return 1;
			}
		} else {
			v9 = tokens[2];
			v7 = nox_strman_loadString_40F1D0("invalidspell", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3342);
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v7, v9);
		}
	}
	return 0;
}

//----- (004E5DB0) --------------------------------------------------------
void nox_xxx_deleteAllObjectsOfType_4E5DB0(int a1) {
	const nox_object_t* v1 = nox_server_getFirstObject_4DA790();
	if (v1) {
		nox_object_t* v2;
		do {
			v2 = nox_server_getNextObject_4DA7A0(v1);
			int v3 = *(uint32_t*)&v1->field_126;
			if (v3) {
				int v4;
				do {
					v4 = *(uint32_t*)(v3 + 496);
					if (*(unsigned short*)(v3 + 4) == a1) {
						nox_xxx_delayedDeleteObject_4E5CC0(v3);
					}
					v3 = v4;
				} while (v4);
			}
			if (v1->typ_ind == a1) {
				nox_xxx_delayedDeleteObject_4E5CC0(v1);
			}
			v1 = v2;
		} while (v2);
	}
}

//----- (004E3BC0) --------------------------------------------------------
void sub_4E3BC0(int a1) {
	dword_5d4594_1563664 ^= *(uint32_t*)(a1 + 16);
	*(uint32_t*)(a1 + 16) = 0;
}

//----- (00415A60) --------------------------------------------------------
int sub_415A60(wchar_t* a1) {
	char* v1; // eax
	int v2;   // eax

	v1 = (char*)sub_415960(a1);
	if (v1 && (v2 = sub_415840(v1)) != 0) {
		return nox_xxx_objectTypeByInd_4E3B70(v2);
	}
	return 0;
}

//----- (00442C90) --------------------------------------------------------
int nox_cmd_set_weapon(int tokInd, int tokCnt, wchar_t** tokens) {
	wchar_t* v3;        // eax
	wchar_t* v4;        // eax
	unsigned short* v6; // esi
	wchar_t* v7;        // eax
	int v8;             // [esp-4h] [ebp-70h]
	int v9;             // [esp-4h] [ebp-70h]
	int v10;            // [esp-4h] [ebp-70h]
	char v11[100];      // [esp+8h] [ebp-64h]

	if (tokCnt == 4) {
		if (nox_common_gameFlags_check_40A5C0(128)) {
			v8 = tokens[2];
			v3 = nox_strman_loadString_40F1D0("NotInChat", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3361);
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3, v8);
			return 1;
		}
		if (_nox_wcsicmp(tokens[2], *(const wchar_t**)getMemAt(0x587000, 94492))) {
			v6 = (unsigned short*)sub_415A60(tokens[2]);
			if (v6 || (nox_sprintf(v11, "%S", tokens[2]), (v6 = (unsigned short*)sub_415A30(v11)) != 0)) {
				if (!_nox_wcsicmp(tokens[3], L"on")) {
					if (nox_xxx_getUnitDefDd10_4E3BA0(*v6)) {
						return 1;
					}
					sub_4E3BF0((int)v6);
					nox_server_gameSettingsUpdated_40A670();
					v8 = tokens[2];
					v3 = nox_strman_loadString_40F1D0("weaponEnabled", 0,
													  "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3401);
					nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3, v8);
					return 1;
				}
				if (!_nox_wcsicmp(tokens[3], L"off")) {
					if (!nox_xxx_getUnitDefDd10_4E3BA0(*v6) || nox_xxx_ammoCheck_415880((char*)*v6) == 1) {
						return 1;
					}
					sub_4E3BC0((int)v6);
					nox_xxx_deleteAllObjectsOfType_4E5DB0(*v6);
					nox_server_gameSettingsUpdated_40A670();
					v8 = tokens[2];
					v3 = nox_strman_loadString_40F1D0("weaponDisabled", 0,
													  "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3414);
					nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3, v8);
					return 1;
				}
			} else {
				v10 = tokens[2];
				v7 = nox_strman_loadString_40F1D0("invalidweapon", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
												  3423);
				nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v7, v10);
			}
		} else {
			if (!_nox_wcsicmp(tokens[3], L"on")) {
				sub_409E70(2);
				v9 = tokens[3];
				v4 = nox_strman_loadString_40F1D0("weaponsrespawn", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
												  3370);
				nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v4, v9);
				sub_4AD840();
				return 1;
			}
			if (!_nox_wcsicmp(tokens[3], L"off")) {
				sub_409E70(2);
				v9 = tokens[3];
				v4 = nox_strman_loadString_40F1D0("weaponsrespawn", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
												  3377);
				nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v4, v9);
				sub_4AD840();
				return 1;
			}
		}
	}
	return 0;
}

//----- (00415EF0) --------------------------------------------------------
int sub_415EF0(wchar_t* a1) {
	char* v1; // eax
	int v2;   // eax

	v1 = (char*)sub_415DA0(a1);
	if (v1 && (v2 = sub_415CD0(v1)) != 0) {
		return nox_xxx_objectTypeByInd_4E3B70(v2);
	}
	return 0;
}

//----- (00442ED0) --------------------------------------------------------
int nox_cmd_set_armor(int tokInd, int tokCnt, wchar_t** tokens) {
	wchar_t* v3;        // eax
	unsigned short* v4; // esi
	wchar_t* v6;        // eax
	int v7;             // [esp-4h] [ebp-70h]
	int v8;             // [esp-4h] [ebp-70h]
	char v9[100];       // [esp+8h] [ebp-64h]

	if (tokCnt == 4) {
		if (nox_common_gameFlags_check_40A5C0(128)) {
			v7 = tokens[2];
			v3 = nox_strman_loadString_40F1D0("NotInChat", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3442);
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3, v7);
			return 1;
		}
		v4 = (unsigned short*)sub_415EF0(tokens[2]);
		if (v4 || (nox_sprintf(v9, "%S", tokens[2]), (v4 = (unsigned short*)sub_415EC0(v9)) != 0)) {
			if (!_nox_wcsicmp(tokens[3], L"on")) {
				if (!nox_xxx_getUnitDefDd10_4E3BA0(*v4)) {
					sub_4E3BF0((int)v4);
					nox_server_gameSettingsUpdated_40A670();
					v7 = tokens[2];
					v3 = nox_strman_loadString_40F1D0("armorEnabled", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
													  3462);
					nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3, v7);
					return 1;
				}
				return 1;
			}
			if (!_nox_wcsicmp(tokens[3], L"off")) {
				if (nox_xxx_getUnitDefDd10_4E3BA0(*v4)) {
					sub_4E3BC0((int)v4);
					nox_xxx_deleteAllObjectsOfType_4E5DB0(*v4);
					nox_server_gameSettingsUpdated_40A670();
					v7 = tokens[2];
					v3 = nox_strman_loadString_40F1D0("armorDisabled", 0,
													  "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3473);
					nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v3, v7);
					return 1;
				}
				return 1;
			}
		} else {
			v8 = tokens[2];
			v6 = nox_strman_loadString_40F1D0("invalidarmor", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3481);
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v6, v8);
		}
	}
	return 0;
}

//----- (00443050) --------------------------------------------------------
int nox_cmd_set_staff(int tokInd, int tokCnt, wchar_t** tokens) {
	int v3;       // edi
	wchar_t* v4;  // eax
	wchar_t* v6;  // eax
	int v7;       // [esp-4h] [ebp-8Ch]
	int v8;       // [esp-4h] [ebp-8Ch]
	char v9[128]; // [esp+8h] [ebp-80h]

	if (tokCnt == 4) {
		nox_sprintf(v9, "%S", tokens[2]);
		v3 = nox_xxx_objectTypeByID_4E3B60(v9);
		if (v3) {
			if (!_nox_wcsicmp(tokens[3], L"on")) {
				sub_4E3BF0(v3);
				v7 = tokens[2];
				v4 = nox_strman_loadString_40F1D0("staffEnabled", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
												  3535);
				nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v4, v7);
				return 1;
			}
			if (!_nox_wcsicmp(tokens[3], L"off")) {
				sub_4E3BC0(v3);
				v7 = tokens[2];
				v4 = nox_strman_loadString_40F1D0("staffDisabled", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
												  3541);
				nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v4, v7);
				return 1;
			}
		} else {
			v8 = tokens[2];
			v6 = nox_strman_loadString_40F1D0("invalidstaff", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3548);
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v6, v8);
		}
	}
	return 0;
}

//----- (00443160) --------------------------------------------------------
int nox_cmd_ban(int tokInd, int tokCnt, wchar_t** tokens) {
	wchar_t* v4; // edi
	char* v5;    // eax
	char* v6;    // esi
	wchar_t* v7; // eax
	wchar_t* v8; // eax
	int v9;      // [esp-Ch] [ebp-Ch]

	if (tokCnt != 2) {
		return 0;
	}
	v4 = tokens[tokInd];
	v5 = nox_xxx_playerByName_4170D0(tokens[tokInd]);
	v6 = v5;
	if (v5) {
		if (v5[2064] == 31) {
			v8 = nox_strman_loadString_40F1D0("cantbanyourself", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
											  3580);
			sub_440A20(v8);
			return 1;
		}
		if (nox_common_gameFlags_check_40A5C0(4096)) {
			sub_4DCFB0(*((uint32_t*)v6 + 514));
		} else {
			nox_xxx_playerDisconnByPlrID_4DEB00((unsigned char)v6[2064]);
		}
		sub_416770(0, v4, v6 + 2112);
		v9 = (int)(v6 + 4704);
		v7 = nox_strman_loadString_40F1D0("banned", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3577);
	} else {
		sub_416770(0, v4, 0);
		v9 = (int)v4;
		v7 = nox_strman_loadString_40F1D0("banDisallow", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3585);
	}
	sub_440A20(v7, v9);
	return 1;
}

//----- (00443250) --------------------------------------------------------
int nox_cmd_allow_user(int tokInd, int tokCnt, wchar_t** tokens) {
	wchar_t* s =
		nox_strman_loadString_40F1D0("notyetimplemented", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3698);
	nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, s);
	return 1;
}

//----- (00443280) --------------------------------------------------------
int nox_cmd_allow_ip(int tokInd, int tokCnt, wchar_t** tokens) {
	wchar_t* s =
		nox_strman_loadString_40F1D0("notyetimplemented", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3704);
	nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, s);
	return 1;
}

//----- (004432B0) --------------------------------------------------------
int nox_cmd_kick(int tokInd, int tokCnt, wchar_t** tokens) {
	char* v4;    // eax
	char* v5;    // esi
	wchar_t* v6; // eax
	wchar_t* v7; // eax

	if (tokCnt != 2) {
		return 0;
	}
	v4 = nox_xxx_playerByName_4170D0(tokens[tokInd]);
	v5 = v4;
	if (!v4) {
		return 1;
	}
	if (v4[2064] == 31) {
		v7 = nox_strman_loadString_40F1D0("cantkickyourself", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3745);
		sub_440A20(v7);
		return 1;
	}
	if (nox_common_gameFlags_check_40A5C0(4096)) {
		sub_4DCFB0(*((uint32_t*)v5 + 514));
	} else {
		nox_xxx_playerCallDisconnect_4DEAB0((unsigned char)v5[2064], 4);
		v6 = nox_strman_loadString_40F1D0("kicked", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3739);
		sub_440A20(v6, v5 + 4704);
	}
	return 1;
}

//----- (00443380) --------------------------------------------------------
int nox_cmd_set_players(int tokInd, int tokCnt, wchar_t** tokens) {
	int v3;            // esi
	const wchar_t* v5; // eax
	int v6;            // eax
	wchar_t* v7;       // eax

	v3 = 0;
	if (tokCnt != 3) {
		return 0;
	}
	v5 = tokens[2];
	if (v5) {
		v6 = nox_wcstol(v5, 0, 10);
		v3 = v6;
		if (v6 >= 0) {
			if (v6 > 999) {
				v3 = 999;
			}
		} else {
			v3 = 0;
		}
		if (nox_xxx_servGetPlrLimit_409FA0() == v3) {
			return 1;
		}
		nox_xxx_servSetPlrLimit_409F80(v3);
		sub_455800();
	}
	v7 = nox_strman_loadString_40F1D0("playersset", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3779);
	sub_440A20(v7, v3);
	return 1;
}

//----- (00443480) --------------------------------------------------------
int nox_cmd_set_spellpts(int tokInd, int tokCnt, wchar_t** tokens) {
	wchar_t* s =
		nox_strman_loadString_40F1D0("notyetimplemented", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3830);
	nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, s);
	return 1;
}

//----- (004434B0) --------------------------------------------------------
int nox_cmd_list_users(int tokInd, int tokCnt, wchar_t** tokens) {
	wchar_t* v0;     // eax
	char* i;         // esi
	wchar_t* v2;     // eax
	wchar_t* v3;     // eax
	wchar_t v5[128]; // [esp+4h] [ebp-100h]

	v0 = nox_strman_loadString_40F1D0("userslist", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3839);
	nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v0);
	for (i = nox_common_playerInfoGetFirst_416EA0(); i; i = nox_common_playerInfoGetNext_416EE0((int)i)) {
		v5[0] = 0;
		nox_wcscat(v5, (const wchar_t*)i + 2352);
		if (nox_client_consoleIsServer_823684 && i[3680] & 4) {
			nox_wcscat(v5, L", ");
			v2 = nox_strman_loadString_40F1D0("SysMuted", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3851);
			nox_wcscat(v5, v2);
		}
		if (i[3680] & 8) {
			nox_wcscat(v5, L", ");
			v3 = nox_strman_loadString_40F1D0("ClientMuted", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3857);
			nox_wcscat(v5, v3);
		}
		nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, (wchar_t*)getMemAt(0x587000, 106604), v5);
	}
	return 1;
}

//----- (0057A0F0) --------------------------------------------------------
int sub_57A0F0(wchar_t* a1) {
	if (!nox_common_gameFlags_check_40A5C0(2)) {
		return 0;
	}
	if (!a1) {
		return 0;
	}
	char* v1 = nox_xxx_playerByName_4170D0(a1);
	if (!v1) {
		return 0;
	}
	nox_xxx_playerUnsetStatus_417530((int)v1, 8);
	return 1;
}

//----- (0057A130) --------------------------------------------------------
int sub_57A130(wchar_t* a1) {
	if (!a1) {
		return 0;
	}
	char* v1 = nox_xxx_playerByName_4170D0(a1);
	if (!v1) {
		return 0;
	}
	nox_xxx_playerUnsetStatus_417530((int)v1, 4);
	return 1;
}

//----- (00443610) --------------------------------------------------------
int nox_cmd_unmute(int tokInd, int tokCnt, wchar_t** tokens) {
	wchar_t** v3; // esi
	int v4;       // eax
	int v5;       // eax
	wchar_t* v6;  // eax
	wchar_t* v8;  // [esp-4h] [ebp-14h]

	if (tokCnt < 2 || tokCnt > 3) {
		return 0;
	}
	v3 = &tokens[tokInd];
	if (!nox_client_consoleIsServer_823684) {
		v5 = sub_57A0F0(*v3);
	} else {
		if (_nox_wcsicmp(tokens[tokInd], *(const wchar_t**)getMemAt(0x587000, 94496))) {
			v5 = sub_57A0F0(*v3);
		} else {
			v4 = tokInd + 1;
			if (tokInd + 1 != tokCnt - 1) {
				return 0;
			}
			v3 = &tokens[v4];
			v5 = sub_57A130(*v3);
		}
	}
	v8 = *v3;
	if (v5) {
		v6 = nox_strman_loadString_40F1D0("UnMuted", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3923);
	} else {
		v6 = nox_strman_loadString_40F1D0("UserNotFound", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3921);
	}
	nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v6, v8);
	return 1;
}

//----- (0057A080) --------------------------------------------------------
int sub_57A080(wchar_t* a1) {
	if (!nox_common_gameFlags_check_40A5C0(2)) {
		return 0;
	}
	if (!a1) {
		return 0;
	}
	char* v1 = nox_xxx_playerByName_4170D0(a1);
	if (!v1 || v1[2064] == 31) {
		return 0;
	}
	nox_xxx_netNeedTimestampStatus_4174F0((int)v1, 8);
	return 1;
}

//----- (0057A0C0) --------------------------------------------------------
int sub_57A0C0(wchar_t* a1) {
	if (!a1) {
		return 0;
	}
	char* v1 = nox_xxx_playerByName_4170D0(a1);
	if (!v1) {
		return 0;
	}
	nox_xxx_netNeedTimestampStatus_4174F0((int)v1, 4);
	return 1;
}

//----- (004436E0) --------------------------------------------------------
int nox_cmd_mute(int tokInd, int tokCnt, wchar_t** tokens) {
	wchar_t** v3; // esi
	int v4;       // eax
	int v5;       // eax
	wchar_t* v6;  // eax
	wchar_t* v8;  // [esp-4h] [ebp-14h]

	if (tokCnt < 2 || tokCnt > 3) {
		return 0;
	}
	v3 = &tokens[tokInd];
	if (!nox_client_consoleIsServer_823684) {
		v5 = sub_57A080(*v3);
	} else {
		if (_nox_wcsicmp(tokens[tokInd], *(const wchar_t**)getMemAt(0x587000, 94496))) {
			v5 = sub_57A080(*v3);
		} else {
			v4 = tokInd + 1;
			if (tokInd + 1 != tokCnt - 1) {
				return 0;
			}
			v3 = &tokens[v4];
			v5 = sub_57A0C0(*v3);
		}
	}
	v8 = *v3;
	if (v5) {
		v6 = nox_strman_loadString_40F1D0("Muted", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3961);
	} else {
		v6 = nox_strman_loadString_40F1D0("UserNotFound", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3959);
	}
	nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v6, v8);
	return 1;
}

//----- (004437B0) --------------------------------------------------------
int nox_cmd_exec(int tokInd, int tokCnt, wchar_t** tokens) {
	if (tokCnt != 2) {
		return 0;
	}
	if (!nox_common_gameFlags_check_40A5C0(1)) {
		int v4 = nox_client_consoleCurCmd_823700;
		wchar_t* s =
			nox_strman_loadString_40F1D0("RemoteExec", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 3979);
		nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, s, v4);
	}
	nox_xxx_netServerCmd_440950(1, *(wchar_t**)&nox_client_consoleCurCmd_823700);
	return 1;
}

//----- (00443810) --------------------------------------------------------
int nox_cmd_exec_rul(int tokInd, int tokCnt, wchar_t** tokens) {
	if (tokCnt != 2) {
		return 0;
	}
	wchar_t buf[128];
	nox_wcscpy(buf, tokens[1]);
	if (!nox_wcschr(buf, 0x2Eu)) {
		nox_wcscat(buf, L".rul");
	}
	wchar_t* s = nox_strman_loadString_40F1D0("ExecutingRul", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4002);
	nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, s, buf);
	nox_xxx_doExecrul_4438A0(buf);
	return 1;
}

//----- (004439B0) --------------------------------------------------------
int nox_cmd_sysop(int tokInd, int tokCnt, wchar_t** tokens) {
	wchar_t* v2; // eax
	wchar_t* v4; // eax
	if (tokCnt == 1) {
		dword_5d4594_823696 = 1;
		v2 = nox_strman_loadString_40F1D0("enterSysopPW", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4014);
		nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v2);
	} else {
		if (tokCnt > 1 && *getMemU32Ptr(0x5D4594, 823688)) {
			v4 = nox_wcsstr(*(const wchar_t**)&nox_client_consoleCurCmd_823700, L" ");
			if (v4) {
				nox_xxx_netServerCmd_440950(2, v4);
			}
		}
	}
	return 1;
}

//----- (00443BF0) --------------------------------------------------------
void nox_console_encodeSecretToken_443BF0(unsigned short* a1, char* a2) {
	int v2;             // esi
	signed int v3;      // ebp
	unsigned short v4;  // ax
	unsigned short* v5; // ecx
	int v6;             // edx

	v2 = 0;
	if (a1) {
		if (a2 && (v3 = nox_wcslen(*(const wchar_t**)getMemAt(0x587000, 98256)), (v4 = *a1) != 0)) {
			v5 = a1;
			do {
				++v5;
				v6 = (unsigned char)(v2++ * (v4 - 1) % v3);
				*(unsigned short*)((char*)v5 - (char*)a1 + a2 - 2) =
					*(uint16_t*)(*getMemU32Ptr(0x587000, 98256) + 2 * v6);
				v4 = *v5;
			} while (*v5);
			*(uint16_t*)&a2[2 * v2] = 0;
		} else {
			*(uint16_t*)a2 = 0;
		}
	} else {
		*(uint16_t*)a2 = 0;
	}
}

//----- (00443A20) --------------------------------------------------------
#ifndef NOX_CGO
int nox_xxx_consoleParseToken_443A20(int tokInd, int tokCnt, wchar_t** tokens, nox_cmd_t cmds[], int a5) {
	if (!tokens[tokInd] || !cmds || !cmds[0].token) {
		return 0;
	}

	wchar_t buf[256];
	int ind = 0;
	for (ind = 0; cmds[ind].token; ind++) {
		nox_cmd_t* cur = &cmds[ind];
		if (cur->flags & NOX_CONSOLE_SECRET) {
			nox_console_encodeSecretToken_443BF0(tokens[tokInd], buf);
		} else {
			nox_wcscpy(buf, tokens[tokInd]);
		}
		if (!_nox_wcsicmp(buf, cur->token)) {
			break;
		}
	}
	nox_cmd_t* cmd = &cmds[ind];
	if (!nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) && nox_cheats_disabled &&
		(cmd->flags & 0x10)) {
		return 0;
	}
	if (nox_client_consoleIsServer_823684) {
		if (!(cmd->flags & 0x1)) {
			wchar_t* s =
				nox_strman_loadString_40F1D0("clientonly", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4091);
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, s);
			return 1;
		}
	} else {
		if (!(cmd->flags & 0x2)) {
			wchar_t* s =
				nox_strman_loadString_40F1D0("serveronly", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4097);
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, s);
			return 1;
		}
	}
	if ((cmd->flags & 0x20) && !nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
		return 1;
	}
	int res;
	if (cmd->sub) { // have sub-commands
		if (tokInd + 1 >= tokCnt) {
			// not enough tokens - print help
			wchar_t* help =
				nox_strman_loadString_40F1D0(cmd->help_id, 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4125);
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, help);
			return 1;
		}
		// continue parsing the sub command
		res = nox_xxx_consoleParseToken_443A20(tokInd + 1, tokCnt, tokens, cmd->sub, a5);
	} else {
		// call console command handler, let it parse the rest
		res = cmd->fnc(tokInd + 1, tokCnt, tokens);
	}
	if (!res) {
		// command failed - print help
		wchar_t* help =
			nox_strman_loadString_40F1D0(cmd->help_id, 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4125);
		nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, help);
		return 1;
	}
	return res;
}
#else  // NOX_CGO
int nox_xxx_consoleParseToken_443A20(int tokInd, int tokCnt, wchar_t** tokens, int a5);
#endif // NOX_CGO

//----- (004409D0) --------------------------------------------------------
void sub_4409D0(wchar_t* a1) {
	char v2[21]; // [esp+0h] [ebp-18h]

	v2[0] = -68;
	nox_wcsncpy((wchar_t*)&v2[1], a1, 8u);
	*(uint16_t*)&v2[17] = 0;
	*(uint16_t*)&v2[19] = nox_player_netCode_85319C;
	nox_xxx_netClientSend2_4E53C0(31, v2, 21, 0, 1);
}

//----- (00443E40) --------------------------------------------------------
wchar_t* nox_xxx_consoleTokenFindByAlias_443E40(wchar_t* s) {
	if (nox_xxx_consoleTokenPairs_823708 <= 0) {
		return 0;
	}
	int ind = 0;
	const wchar_t** i;
	for (i = (const wchar_t**)getMemAt(0x5D4594, 816504 + 8 * 0); _nox_wcsicmp(s, *i); i += 2) {
		if (++ind >= nox_xxx_consoleTokenPairs_823708) {
			return 0;
		}
	}
	return *getMemU32Ptr(0x5D4594, 816500 + 8 * ind);
}

#ifndef NOX_CGO
//----- (00443C80) --------------------------------------------------------
int nox_server_parseCmdText_443C80(wchar_t* cmdText, int a2) {
	// !!! If the command is bigger than 31 symbol (w/0 \0), game will crash because of stack corruption (bug
	// persists in original image)

	if (!cmdText) {
		nox_client_consoleCurCmd_823700 = 0;
		return 0;
	}
	nox_client_consoleCurCmd_823700 = cmdText;
	memset(getMemAt(0x5D4594, 820276), 0, 0x800u);
	if (nox_common_gameFlags_check_40A5C0(1)) {
		nox_client_consoleIsServer_823684 = 1;
		*getMemU32Ptr(0x5D4594, 823688) = 0;
	} else {
		nox_client_consoleIsServer_823684 = 0;
		*getMemU32Ptr(0x5D4594, 823688) = 1;
	}
	if (dword_5d4594_823696) {
		sub_4409D0(cmdText);
		dword_5d4594_823696 = 0;
		return 1;
	}
	nox_wcscpy((wchar_t*)getMemAt(0x5D4594, 820276), cmdText);
	wchar_t* str;
	int v2;
	if (*getMemU16Ptr(0x5D4594, 820276) == 34) {
		str = nox_wcstok((wchar_t*)getMemAt(0x5D4594, 820278), L"\"\n\r");
		v2 = 1;
	} else {
		str = nox_wcstok((wchar_t*)getMemAt(0x5D4594, 820276), L" ");
		v2 = 0;
	}
	wchar_t* tokens[32];
	int tokCnt = 0;
	while (str) {
		wchar_t* tok = str;
		if (!v2) {
			tok = nox_xxx_consoleTokenFindByAlias_443E40(str);
			if (!tok) {
				tok = str;
			}
		}
		tokens[tokCnt] = tok;
		tokCnt++;
		wchar_t* v8 = &str[nox_wcslen(str) + 1];
		if (v2) {
			++v8;
		}
		if (*v8 == 34) {
			str = nox_wcstok(v8 + 1, L"\"\n\r");
			v2 = 1;
		} else {
			str = nox_wcstok(0, L" ");
			v2 = 0;
		}
	}
	int res = 0;
	if (tokCnt > 0) {
#ifndef NOX_CGO
		res = nox_xxx_consoleParseToken_443A20(0, tokCnt, tokens, nox_commands, a2);
#else  // NOX_CGO
		res = nox_xxx_consoleParseToken_443A20(0, tokCnt, tokens, a2);
#endif // NOX_CGO
		if (!res) {
			wchar_t* help =
				nox_strman_loadString_40F1D0("typehelp", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4226);
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, help);
		}
	}
	nox_client_consoleCurCmd_823700 = 0;
	return res;
}
#endif // NOX_CGO

//----- (00443E90) --------------------------------------------------------
int nox_xxx_serverHandleClientConsole_443E90(nox_playerInfo* pl, char a2, wchar_t* a3) {
	int v3;        // ecx
	int result;    // eax
	int v5;        // edi
	wchar_t* v6;   // ebx
	int v7;        // eax
	int v8;        // eax
	wchar_t* v9;   // eax
	wchar_t* v10;  // esi
	int v11;       // edi
	wchar_t* v12;  // eax
	wchar_t* v13;  // eax
	char* v14;     // esi
	int v15;       // eax
	wchar_t* v16;  // eax
	char* v17;     // esi
	wchar_t* v18;  // eax
	int v19;       // [esp-8h] [ebp-94h]
	int v20;       // [esp-8h] [ebp-94h]
	wchar_t* v21;  // [esp-4h] [ebp-90h]
	char v22[128]; // [esp+Ch] [ebp-80h]

	if (!pl || !pl->playerUnit) {
		return 0;
	}
	if (a3) {
		nox_wcscpy((wchar_t*)getMemAt(0x5D4594, 818228), a3);
	} else {
		*getMemU16Ptr(0x5D4594, 818228) = 0;
	}
	v3 = pl;
	nox_console_playerWhoSent_823692 = pl;
	if (a2 != 4 && a2 != 5 && a2) {
		if (nox_common_gameFlags_check_40A5C0(49152)) {
			return 1;
		}
	}
	switch (a2) {
	case 0:
		if (nox_common_gameFlags_check_40A5C0(8) || nox_common_gameFlags_check_40A5C0(4096) ||
			*(uint8_t*)((int)pl + 3680) & 1) {
			nox_console_playerWhoSent_823692 = 0;
			return 1;
		}
		v5 = *getMemI16Ptr(0x5D4594, 818228) == -4083 && *getMemI16Ptr(0x5D4594, 818230) == -3923 &&
			 !*getMemU16Ptr(0x5D4594, 818232);
		if (nox_xxx_playerGoObserver_4E6860(pl, v5, 0) != 1) {
			nox_console_playerWhoSent_823692 = 0;
			return 1;
		}
		v6 = nox_strman_loadString_40F1D0("set", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4287);
		v7 = nox_xxx_gamePlayIsAnyPlayers_40A8A0();
		if (v7) {
			if (!v5) {
				nox_xxx_netNeedTimestampStatus_4174F0(pl, 256);
			}
			if (nox_common_gameFlags_check_40A5C0(1024) && sub_40A770() == 1) {
				sub_5095E0();
			}
		}
		v8 = pl->playerUnit;
		if (v8) {
			nox_xxx_netChangeTeamMb_419570(v8 + 48, pl->netCode);
		}
		v21 = v6;
		v9 = nox_strman_loadString_40F1D0("observermode", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4308);
		nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v9, v21);
		nox_console_playerWhoSent_823692 = 0;
		return 1;
	case 1:
		if (!sub_4D12A0(pl->playerInd) && pl->playerInd != nox_player_netCode_85319C &&
			!nox_common_gameFlags_check_40A5C0(2048)) {
			nox_console_playerWhoSent_823692 = 0;
			return 1;
		}
		nox_wcstok((wchar_t*)getMemAt(0x5D4594, 818228), L" ");
		v10 = nox_wcstok(0, L" ");
		nox_sprintf(v22, "%S", v10);
		v11 = nox_script_indexByEvent(v22);
		if (v11 != -1 && nox_console_playerWhoSent_823692) {
			v12 = nox_strman_loadString_40F1D0("ExecutingFunction", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
											   4332);
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v12, v10);
			nox_script_callByIndex_507310(v11, nox_console_playerWhoSent_823692->playerUnit,
										  nox_console_playerWhoSent_823692->playerUnit);
			nox_console_playerWhoSent_823692 = 0;
		} else {
			v21 = v10;
			v9 = nox_strman_loadString_40F1D0("InvalidFunction", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
											  4329);
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v9, v21);
			nox_console_playerWhoSent_823692 = 0;
		}
		return 1;
	case 2:
		if (!sub_4D12A0(pl->playerInd) && pl->playerInd != nox_player_netCode_85319C &&
			!nox_common_gameFlags_check_40A5C0(2048)) {
			nox_console_playerWhoSent_823692 = 0;
			return 1;
		}
		v19 = (char*)nox_console_playerWhoSent_823692 + 4704;
		v13 = nox_strman_loadString_40F1D0("RemoteSysop", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4345);
		nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v13, v19, a3);
		nox_server_parseCmdText_443C80(a3, 0);
		nox_console_playerWhoSent_823692 = 0;
		return 1;
	case 3:
		nox_xxx_printToAll_4D9FD0(0, a3);
		nox_console_playerWhoSent_823692 = 0;
		return 1;
	case 4:
		if (!(*(uint8_t*)(v3 + 3680) & 1) && !(nox_common_getEngineFlag(NOX_ENGINE_FLAG_REPLAY_READ))) {
			if (nox_common_gameFlags_check_40A5C0(1)) {
				v16 = nox_strman_loadString_40F1D0("notinobserver", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c",
												   4392);
				nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v16);
				nox_console_playerWhoSent_823692 = 0;
				return 1;
			}
			nox_console_playerWhoSent_823692 = 0;
			return 1;
		}
		if (!*a3) {
			nox_xxx_playerCameraUnlock_4E6040(*(uint32_t*)(v3 + 2056));
			nox_console_playerWhoSent_823692 = 0;
			return 1;
		}
		v17 = nox_common_playerInfoGetFirst_416EA0();
		if (!v17) {
			nox_console_playerWhoSent_823692 = 0;
			return 1;
		}
		do {
			if (!_nox_wcsicmp(a3, (const wchar_t*)v17 + 2352)) {
				nox_xxx_playerCameraFollow_4E6060(nox_console_playerWhoSent_823692->playerUnit,
												  *((uint32_t*)v17 + 514));
			}
			v17 = nox_common_playerInfoGetNext_416EE0((int)v17);
		} while (v17);
		nox_console_playerWhoSent_823692 = 0;
		return 1;
	case 5:
		nox_xxx_printToAll_4D9FD0(16, a3);
		v14 = nox_common_playerInfoGetFirst_416EA0();
		if (!v14) {
			nox_console_playerWhoSent_823692 = 0;
			return 1;
		}
		do {
			v15 = *((uint32_t*)v14 + 514);
			if (v15) {
				nox_xxx_aud_501960(902, v15, 0, 0);
			}
			v14 = nox_common_playerInfoGetNext_416EE0((int)v14);
		} while (v14);
		nox_console_playerWhoSent_823692 = 0;
		return 1;
	default:
		v20 = v3 + 4704;
		v18 = nox_strman_loadString_40F1D0("invalidattempt", 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4400);
		nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, v18, v20, a3);
		nox_console_playerWhoSent_823692 = 0;
		return 1;
	}
	return result;
}
// 443FC8: variable 'v7' is possibly undefined

//----- (004444C0) --------------------------------------------------------
void nox_xxx_consoleTokenAddPair_4444C0(wchar_t* tok, wchar_t* tok2) {
	int n = nox_xxx_consoleTokenPairs_823708;
	*getMemU32Ptr(0x5D4594, 816500 + 8 * n) = tok;
	*getMemU32Ptr(0x5D4594, 816504 + 8 * n) = tok2;
	nox_xxx_consoleTokenPairs_823708++;
}

//----- (00444440) --------------------------------------------------------
#ifndef NOX_CGO
void nox_xxx_consoleLoadTokens_444440(nox_cmd_t cmds[]) {
	if (!cmds || !cmds[0].token) {
		return;
	}
	char buf[64];
	for (nox_cmd_t* cmd = &cmds[0]; cmd->token; cmd++) {
		nox_sprintf(buf, "cmd_token:%S", cmd->token);
		wchar_t* tok = nox_strman_loadString_40F1D0(buf, 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4441);
		cmd->token2 = tok;
		nox_xxx_consoleTokenAddPair_4444C0(cmd->token, tok);
		if (nox_wcslen(tok) < 32 && cmd->sub) {
			nox_xxx_consoleLoadTokens_444440(cmd->sub);
		}
	}
}
#else  // NOX_CGO
void nox_xxx_consoleLoadTokens_444440();
#endif // NOX_CGO

//----- (00444570) --------------------------------------------------------
void sub_444570() {
	int* v0;     // esi
	wchar_t* v1; // eax
	char v3[80]; // [esp+4h] [ebp-50h]

	v0 = getMemIntPtr(0x587000, 94504);
	do {
		nox_sprintf(v3, "keybind:%S", *v0);
		v1 = nox_strman_loadString_40F1D0(v3, 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 874);
		v0[1] = (int)v1;
		nox_xxx_consoleTokenAddPair_4444C0(*v0, (int)v1);
		v0 += 19;
	} while ((int)v0 < (int)getMemAt(0x587000, 95416));
}

//----- (00444560) --------------------------------------------------------
void nox_xxx_consoleInitTokenPairs_444560() { nox_xxx_consoleTokenPairs_823708 = 0; }

//----- (004444F0) --------------------------------------------------------
void nox_xxx_cmdTokensLoad_4444F0() {
	int* v0;     // esi
	wchar_t* v1; // eax
	char v3[80]; // [esp+4h] [ebp-50h]

	nox_xxx_consoleInitTokenPairs_444560();
	v0 = getMemIntPtr(0x587000, 94468);
	do {
		nox_sprintf(v3, "cmd_token:%S", *v0);
		v1 = nox_strman_loadString_40F1D0(v3, 0, "C:\\NoxPost\\src\\Client\\System\\parsecmd.c", 4476);
		nox_xxx_consoleTokenAddPair_4444C0(*v0, (int)v1);
		++v0;
	} while ((int)v0 < (int)getMemAt(0x587000, 94500));
	dword_5d4594_823696 = 0;
#ifndef NOX_CGO
	nox_xxx_consoleLoadTokens_444440(nox_commands);
#else  // NOX_CGO
	nox_xxx_consoleLoadTokens_444440();
#endif // NOX_CGO
	sub_444570();
}

//----- (00440B00) --------------------------------------------------------
int nox_cmd_unbind(int tokInd, int tokCnt, wchar_t** tokens) {
	if (tokCnt != 2) {
		return 0;
	}
	if (nox_wcslen(tokens[1]) >= 0x20) {
		return 0;
	}
	int v3 = sub_440AC0(tokens[1]);
	if (v3 == -1) {
		return 0;
	}
	*getMemU16Ptr(0x587000, 94516 + 76 * v3) = 0;
	return 1;
}

//----- (00440BC0) --------------------------------------------------------
char* sub_cmd_broadcast_xxx_440BC0(int tokInd, int tokCnt, wchar_t** tokens) {
	int v3;            // ebx
	unsigned int v5;   // edx
	unsigned char* v6; // edi
	unsigned char* v7; // edi
	char* v8;          // esi
	char v9;           // cl
	int v10;           // edx
	uint32_t* v11;     // [esp+8h] [ebp-84h]
	char v12[128];     // [esp+Ch] [ebp-80h]

	v3 = tokInd;
	if (tokInd == tokCnt) {
		return 0;
	}
	*getMemU8Ptr(0x5D4594, 818100) = 0;
	if (tokInd < tokCnt) {
		v11 = &tokens[tokInd];
		do {
			nox_sprintf(v12, "%S", *v11);
			v5 = strlen(v12) + 1;
			v6 = getMemAt(0x5D4594, 818100 + strlen((const char*)getMemAt(0x5D4594, 818100)));
			memcpy(v6, v12, 4 * (v5 >> 2));
			v8 = &v12[4 * (v5 >> 2)];
			v7 = &v6[4 * (v5 >> 2)];
			v9 = v5;
			v10 = v3 + 1;
			memcpy(v7, v8, v9 & 3);
			if (v3 + 1 < tokCnt) {
				*getMemU16Ptr(0x5D4594, 818100 + strlen((const char*)getMemAt(0x5D4594, 818100))) =
					*getMemU16Ptr(0x587000, 101624);
			}
			++v3;
			++v11;
		} while (v10 < tokCnt);
	}
	return (char*)getMemAt(0x5D4594, 818100);
}
// 440BC0: using guessed type char var_80[128];

//----- (00440B50) --------------------------------------------------------
int nox_cmd_broadcast(int tokInd, int tokCnt, wchar_t** tokens) {
	int result;      // eax
	wchar_t v4[128]; // [esp+0h] [ebp-100h]

	if (tokCnt == 1) {
		return 0;
	}
	result = sub_cmd_broadcast_xxx_440BC0(tokInd, tokCnt, tokens);
	if (result) {
		nox_swprintf(v4, L"%S", result);
		nox_xxx_netServerCmd_440950(5, v4);
		result = 1;
	}
	return result;
}

//----- (00440C90) --------------------------------------------------------
int nox_cmd_say(int tokInd, int tokCnt, wchar_t** tokens) {
	if (tokCnt == 1) {
		return 0;
	}
	nox_xxx_cmdSayDo_46A4B0((wchar_t*)((int)nox_client_consoleCurCmd_823700 + 8), 0);
	return 1;
}

//----- (00440CC0) --------------------------------------------------------
int nox_cmd_offonly1(int tokInd, int tokCnt, wchar_t** tokens) {
	if (tokCnt != 2) {
		return 0;
	}
	nox_xxx_wndGuiTeamCreate_4185B0();
	return 1;
}

//----- (00440CE0) --------------------------------------------------------
int nox_cmd_offonly2(int tokInd, int tokCnt, wchar_t** tokens) {
	int result;        // eax
	char* v4;          // ebx
	const wchar_t* v5; // eax
	int v6;            // edi
	unsigned char* v7; // esi

	if (tokCnt != 3) {
		return 0;
	}
	result = (int)getMemAt(0x5D4594, 822660);
	if (true) // TODO: byte_5D4594 != (unsigned char*)-822660
	{
		v4 = nox_xxx_cliGamedataGet_416590(1);
		v5 = *(const wchar_t**)getMemAt(0x587000, 94400);
		v6 = 0;
		if (*getMemU32Ptr(0x587000, 94400)) {
			v7 = getMemAt(0x587000, 94400);
			while (_nox_wcsicmp(v5, tokens[tokInd])) {
				v5 = (const wchar_t*)*((uint32_t*)v7 + 2);
				v7 += 8;
				++v6;
				if (!v5) {
					return 1;
				}
			}
			*((uint16_t*)v4 + 26) &= 0xE80Fu;
			*((uint16_t*)v4 + 26) |= *getMemU16Ptr(0x587000, 94404 + 8 * v6);
		}
		result = 1;
	}
	return result;
}

//----- (00440FD0) --------------------------------------------------------
int nox_cmd_set_fr(int tokInd, int tokCnt, wchar_t** tokens) {
	if (tokCnt != 2) {
		return 0;
	}
	nox_xxx_setFrameLimit_43DDE0(1);
	return 1;
}

//----- (00440FF0) --------------------------------------------------------
int nox_cmd_unset_fr(int tokInd, int tokCnt, wchar_t** tokens) {
	if (tokCnt != 2) {
		return 0;
	}
	nox_xxx_setFrameLimit_43DDE0(0);
	return 1;
}

//----- (00441010) --------------------------------------------------------
int nox_cmd_set_net_debug(int tokInd, int tokCnt, wchar_t** tokens) {
	if (tokCnt != 2) {
		return 0;
	}
	nox_common_setEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG);
	return 1;
}

//----- (00441030) --------------------------------------------------------
int nox_cmd_unset_net_debug(int tokInd, int tokCnt, wchar_t** tokens) {
	if (tokCnt != 2) {
		return 0;
	}
	nox_common_resetEngineFlag(NOX_ENGINE_FLAG_ENABLE_NET_DEBUG);
	return 1;
}

//----- (00441440) --------------------------------------------------------
int nox_cmd_show_ai(int tokInd, int tokCnt, wchar_t** tokens) {
	nox_common_toggleEngineFlag(NOX_ENGINE_FLAG_ENABLE_SHOW_AI);
	return 1;
}

//----- (00441460) --------------------------------------------------------
int nox_cmd_show_gui(int tokInd, int tokCnt, wchar_t** tokens) {
	int v0 = nox_client_renderGUI_80828 ^ 1;
	nox_client_renderGUI_80828 = v0;
	nox_xxx_xxxRenderGUI_587000_80832 = v0;
	return 1;
}

//----- (00441480) --------------------------------------------------------
int nox_cmd_show_extents(int tokInd, int tokCnt, wchar_t** tokens) {
	nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
	nox_common_toggleEngineFlag(NOX_ENGINE_FLAG_ENABLE_SHOW_EXTENTS);
	return 1;
}

//----- (004414B0) --------------------------------------------------------
int nox_cmd_show_perfmon(int tokInd, int tokCnt, wchar_t** tokens) {
	nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
	sub_435F40();
	return 1;
}

//----- (004414D0) --------------------------------------------------------
int nox_cmd_show_netstat(int tokInd, int tokCnt, wchar_t** tokens) {
	sub_470A60();
	return 1;
}

//----- (004414E0) --------------------------------------------------------
int nox_cmd_show_info(int tokInd, int tokCnt, wchar_t** tokens) {
	nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
	sub_435F60();
	return 1;
}

//----- (00441500) --------------------------------------------------------
int nox_cmd_show_mem(int tokInd, int tokCnt, wchar_t** tokens) {
	nox_server_currentMapGetFilename_409B30();
	nox_xxx_gameLoopMemDump_413E30();
	return 1;
}

//----- (00441530) --------------------------------------------------------
int nox_cmd_show_rank(int tokInd, int tokCnt, wchar_t** tokens) {
	if (nox_common_gameFlags_check_40A5C0(0x2000)) {
		sub_4703F0();
	}
	return 1;
}

//----- (004416B0) --------------------------------------------------------
int nox_cmd_show_motd(int tokInd, int tokCnt, wchar_t** tokens) {
	if (tokCnt != 2) {
		return 0;
	}
	nox_xxx_motd_4467F0();
	return 1;
}

//----- (004416D0) --------------------------------------------------------
int nox_cmd_show_seq(int tokInd, int tokCnt, wchar_t** tokens) {
	if (tokCnt != 2) {
		return 0;
	}
	sub_48D7B0();
	return 1;
}

//----- (00441740) --------------------------------------------------------
int nox_cmd_list_maps(int tokInd, int tokCnt, wchar_t** tokens) {
	int* v0;       // esi
	int i;         // edi
	bool v2;       // zf
	signed int v3; // edi

	memset(getMemAt(0x5D4594, 822404), 0, 0x100u);
	v0 = nox_common_maplist_first_4D09B0();
	for (i = 1; v0; ++i) {
		sub_4417E0((wchar_t*)getMemAt(0x5D4594, 822404), (const char*)v0 + 12);
		if (!(i % 4)) {
			nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, (wchar_t*)getMemAt(0x587000, 103276),
										  getMemAt(0x5D4594, 822404));
			*getMemU16Ptr(0x5D4594, 822404) = 0;
		}
		v0 = nox_common_maplist_next_4D09C0(v0);
	}
	v3 = (i - 1) & 0x80000003;
	v2 = v3 == 0;
	if (v3 < 0) {
		v2 = (((uint8_t)v3 - 1) | 0xFFFFFFFC) == (unsigned int)-1;
	}
	if (!v2) {
		nox_gui_console_Printf_450C00(NOX_CONSOLE_RED, (wchar_t*)getMemAt(0x587000, 103284),
									  getMemAt(0x5D4594, 822404));
	}
	return 1;
}

//----- (00441870) --------------------------------------------------------
int nox_cmd_log_file(int tokInd, int tokCnt, wchar_t** tokens) {
	if (tokCnt == 3) {
		if (tokens[2]) {
			nox_common_setEngineFlag(NOX_ENGINE_FLAG_LOG_TO_FILE);
			char v4[256];
			nox_sprintf(v4, "%S", tokens[2]);
			return nox_xxx_log_4_reopen_413A80(v4);
		}
	}
	return 0;
}

//----- (004418D0) --------------------------------------------------------
int nox_cmd_log_console(int tokInd, int tokCnt, wchar_t** tokens) {
	if (tokCnt != 2) {
		return 0;
	}
	nox_common_setEngineFlag(NOX_ENGINE_FLAG_LOG_TO_CONSOLE);
	return 1;
}

//----- (004418F0) --------------------------------------------------------
int nox_cmd_log_stop(int tokInd, int tokCnt, wchar_t** tokens) {
	if (tokCnt != 2) {
		return 0;
	}
	nox_xxx_log_4_close_413C00();
	return 1;
}

//----- (00441D20) --------------------------------------------------------
int nox_cmd_set(int tokInd, int tokCnt, wchar_t** tokens) { return 1; }

//----- (00441D30) --------------------------------------------------------
int nox_cmd_cheat_ability(int tokInd, int tokCnt, wchar_t** tokens) {
	char* i; // esi

	if (!nox_common_gameFlags_check_40A5C0(0x2000)) {
		for (i = nox_common_playerInfoGetFirst_416EA0(); i; i = nox_common_playerInfoGetNext_416EE0((int)i)) {
			if (*((uint32_t*)i + 514)) {
				nox_xxx_playerCancelAbils_4FC180(*((uint32_t*)i + 514));
			}
		}
	}
	return 1;
}

//----- (00441D80) --------------------------------------------------------
int nox_cmd_cheat_goto(int tokInd, int tokCnt, wchar_t** tokens) {
	const char* v4; // edi
	char* v5;       // esi
	int v6;         // eax
	char* v7;       // eax
	char* v8;       // esi
	char buf[76];

	if (nox_common_gameFlags_check_40A5C0(0x2000)) {
		return 1;
	}
	if (tokCnt >= 4) {
		v7 = nox_common_playerInfoGetByID_417040(nox_player_netCode_85319C);
		v8 = v7;
		if (!v7 || !*((uint32_t*)v7 + 514)) {
			return 0;
		}
		float2 pos;
		nox_sprintf(buf, "%S", tokens[2]);
		pos.field_0 = atof(buf);
		nox_sprintf(buf, "%S", tokens[3]);
		pos.field_4 = atof(buf);
		nox_xxx_unitMove_4E7010(*((uint32_t*)v8 + 514), &pos);
		return 1;
	}
	if (tokCnt < 3) {
		return 0;
	}
	nox_sprintf(buf, "%S", tokens[2]);
	v4 = nox_xxx_waypointByName_579E30(buf);
	if (!v4) {
		return 1;
	}
	v5 = nox_common_playerInfoGetFirst_416EA0();
	if (!v5) {
		return 1;
	}
	do {
		v6 = *((uint32_t*)v5 + 514);
		if (v6) {
			nox_xxx_unitMove_4E7010(v6, (float2*)v4 + 1);
		}
		v5 = nox_common_playerInfoGetNext_416EE0((int)v5);
	} while (v5);
	return 1;
}

#ifndef NOX_CGO
//----- (00441EB0) --------------------------------------------------------
int nox_cmd_cheat_health(int tokInd, int tokCnt, wchar_t** tokens) {
	char* i; // esi

	if (!nox_common_gameFlags_check_40A5C0(0x2000)) {
		for (i = nox_common_playerInfoGetFirst_416EA0(); i; i = nox_common_playerInfoGetNext_416EE0((int)i)) {
			if (*((uint32_t*)i + 514)) {
				nox_xxx_unitHPsetOnMax_4EE6F0(*((uint32_t*)i + 514));
			}
		}
	}
	return 1;
}

//----- (00441F00) --------------------------------------------------------
int nox_cmd_cheat_mana(int tokInd, int tokCnt, wchar_t** tokens) {
	char* i; // esi
	int v1;  // eax

	if (!nox_common_gameFlags_check_40A5C0(0x2000)) {
		for (i = nox_common_playerInfoGetFirst_416EA0(); i; i = nox_common_playerInfoGetNext_416EE0((int)i)) {
			v1 = *((uint32_t*)i + 514);
			if (v1) {
				nox_xxx_playerManaAdd_4EEB80(v1, 2000);
			}
		}
	}
	return 1;
}
#endif // NOX_CGO

//----- (00441F50) --------------------------------------------------------
int nox_cmd_cheat_level(int tokInd, int tokCnt, wchar_t** tokens) {
	char* i;          // esi
	unsigned char v5; // al

	if (!nox_common_gameFlags_check_40A5C0(0x2000)) {
		if (tokCnt < 3) {
			return 0;
		}
		for (i = nox_common_playerInfoGetFirst_416EA0(); i; i = nox_common_playerInfoGetNext_416EE0((int)i)) {
			if (*((uint32_t*)i + 514)) {
				v5 = nox_wcstol(tokens[2], 0, 10);
				sub_4EF410(*((uint32_t*)i + 514), v5);
			}
		}
	}
	return 1;
}

//----- (00441FC0) --------------------------------------------------------
int nox_cmd_cheat_spells(int tokInd, int tokCnt, wchar_t** tokens) {
	int v4;  // eax
	int v5;  // edi
	char* i; // ebp
	int v7;  // esi
	int* v8; // ebx

	if (!nox_common_gameFlags_check_40A5C0(0x2000)) {
		if (tokCnt < 3) {
			return 0;
		}
		v4 = nox_wcstol(tokens[2], 0, 10);
		v5 = v4;
		if (v4 > 0) {
			if (v4 > 5) {
				v5 = 5;
			}
		} else {
			v5 = 1;
		}
		for (i = nox_common_playerInfoGetFirst_416EA0(); i; i = nox_common_playerInfoGetNext_416EE0((int)i)) {
			v7 = 0;
			v8 = (int*)(i + 3696);
			do {
				*v8 = v5;
				nox_xxx_playerAwardSpellProtection_56FCE0(*((uint32_t*)i + 1159), v7, v5);
				*v8 = v5;
				nox_xxx_playerAwardSpellProtection_56FCE0(*((uint32_t*)i + 1159), v7++, v5);
				++v8;
			} while (v7 < 137);
		}
	}
	return 1;
}

//----- (00442070) --------------------------------------------------------
#ifndef NOX_CGO
int nox_cmd_cheat_gold(int tokInd, int tokCnt, wchar_t** tokens) {
	int v4;  // edi
	char* i; // esi
	int v6;  // eax

	if (!nox_common_gameFlags_check_40A5C0(0x2000)) {
		if (tokCnt < 3) {
			return 0;
		}
		v4 = nox_wcstol(tokens[2], 0, 10);
		for (i = nox_common_playerInfoGetFirst_416EA0(); i; i = nox_common_playerInfoGetNext_416EE0((int)i)) {
			v6 = *((uint32_t*)i + 514);
			if (v6) {
				if (v4 < 0) {
					nox_xxx_playerSubGold_4FA5D0(v6, v4);
				} else {
					nox_xxx_playerAddGold_4FA590(v6, v4);
				}
			}
		}
	}
	return 1;
}

//----- (00442120) --------------------------------------------------------
int nox_cmd_image(int tokInd, int tokCnt, wchar_t** tokens) {
	nox_xxx_saveScreenshot_46DB00();
	return 1;
}

//----- (00442130) --------------------------------------------------------
int nox_cmd_quit(int tokInd, int tokCnt, wchar_t** tokens) {
	nox_client_quit_4460C0();
	return 1;
}

//----- (00442140) --------------------------------------------------------
int nox_cmd_exit(int tokInd, int tokCnt, wchar_t** tokens) {
	if (nox_common_gameFlags_check_40A5C0(4096) && nox_common_gameFlags_check_40A5C0(1)) {
		sub_4D6B10(0);
	}
	if (nox_common_gameFlags_check_40A5C0(0x2000000)) {
		nox_client_quit_4460C0();
	}
	nox_xxx_setContinueMenuOrHost_43DDD0(0);
	nox_game_exit_xxx_43DE60();
	return 1;
}
#endif // NOX_CGO

//----- (00442210) --------------------------------------------------------
int nox_cmd_watch(int tokInd, int tokCnt, wchar_t** tokens) {
	char* v4;        // eax
	wchar_t v5[128]; // [esp+4h] [ebp-100h]

	int result = sub_cmd_broadcast_xxx_440BC0(tokInd, tokCnt, tokens);
	if (result) {
		nox_swprintf(v5, L"%S", result);
		if (nox_common_gameFlags_check_40A5C0(1)) {
			v4 = nox_common_playerInfoGetByID_417040(nox_player_netCode_85319C);
			if (tokCnt <= 1) {
				nox_xxx_serverHandleClientConsole_443E90((int)v4, 4, (wchar_t*)getMemAt(0x5D4594, 823768));
			} else {
				nox_xxx_serverHandleClientConsole_443E90((int)v4, 4, v5);
			}
			result = 1;
		} else {
			if (tokCnt <= 1) {
				nox_xxx_netServerCmd_440950(4, (wchar_t*)getMemAt(0x5D4594, 823764));
			} else {
				nox_xxx_netServerCmd_440950(4, v5);
			}
			result = 1;
		}
	}
	return result;
}

//----- (004422D0) --------------------------------------------------------
int nox_cmd_gamma(int tokInd, int tokCnt, wchar_t** tokens) {
	const wchar_t* v3; // eax
	int v4;            // esi
	int v5;            // esi
	int v6;            // eax
	int v8;            // [esp-14h] [ebp-14h]

	if (tokCnt <= 1) {
		return 1;
	}
	v3 = tokens[tokInd];
	if (*v3 == 43) {
		v4 = nox_wcstol(v3, 0, 10);
		v8 = nox_video_getGammaSetting_434B00() + v4;
		nox_video_setGammaSetting_434B30(v8);
	} else {
		if (*v3 == 45) {
			v5 = nox_wcstol(v3, 0, 10);
			v6 = nox_video_getGammaSetting_434B00() - v5;
		} else {
			v6 = nox_wcstol(v3, 0, 10);
		}
		nox_video_setGammaSetting_434B30(v6);
	}
	sub_434B60();
	return 1;
}

//----- (00442340) --------------------------------------------------------
int nox_cmd_window(int tokInd, int tokCnt, wchar_t** tokens) {
	const wchar_t* v3; // eax
	int v4;            // eax
	int v6;            // eax

	if (tokCnt > 1) {
		v3 = tokens[tokInd];
		if (*v3 != 43 && *v3 != 45) {
			v4 = nox_wcstol(v3, 0, 10);
			nox_draw_setCutSize_476700(v4, 0);
			return 1;
		}
		v6 = nox_wcstol(v3, 0, 10);
		nox_draw_setCutSize_476700(0, v6);
	}
	return 1;
}

//----- (00442750) --------------------------------------------------------
int nox_cmd_set_qual_modem(int tokInd, int tokCnt, wchar_t** tokens) {
	dword_5d4594_2650652 = 1;
	int v0 = sub_40A710(4);
	nox_xxx_rateUpdate_40A6D0(v0);
	nox_server_connectionType_3596 = 4;
	sub_4AD840();
	return 1;
}

//----- (00442780) --------------------------------------------------------
int nox_cmd_set_qual_isdn(int tokInd, int tokCnt, wchar_t** tokens) {
	dword_5d4594_2650652 = 1;
	int v0 = sub_40A710(3);
	nox_xxx_rateUpdate_40A6D0(v0);
	nox_server_connectionType_3596 = 3;
	sub_4AD840();
	return 1;
}

//----- (004427B0) --------------------------------------------------------
int nox_cmd_set_qual_cable(int tokInd, int tokCnt, wchar_t** tokens) {
	dword_5d4594_2650652 = 1;
	int v0 = sub_40A710(2);
	nox_xxx_rateUpdate_40A6D0(v0);
	nox_server_connectionType_3596 = 2;
	sub_4AD840();
	return 1;
}

//----- (004427E0) --------------------------------------------------------
int nox_cmd_set_qual_t1(int tokInd, int tokCnt, wchar_t** tokens) {
	dword_5d4594_2650652 = 1;
	int v0 = sub_40A710(1);
	nox_xxx_rateUpdate_40A6D0(v0);
	nox_server_connectionType_3596 = 1;
	sub_4AD840();
	return 1;
}

//----- (00442810) --------------------------------------------------------
int nox_cmd_set_qual_lan(int tokInd, int tokCnt, wchar_t** tokens) {
	dword_5d4594_2650652 = 0;
	int v0 = sub_40A710(1);
	nox_xxx_rateUpdate_40A6D0(v0);
	nox_server_connectionType_3596 = 1;
	sub_4AD840();
	return 1;
}

//----- (00443400) --------------------------------------------------------
int nox_cmd_set_time(int tokInd, int tokCnt, wchar_t** tokens) {
	char* v4;          // esi
	const wchar_t* v5; // eax
	unsigned char v6;  // al

	if (tokCnt != 3) {
		return 0;
	}
	v4 = sub_4165B0();
	v5 = tokens[2];
	if (v5) {
		v6 = nox_wcstol(v5, 0, 10);
		sub_40A040_settings(*((uint16_t*)v4 + 26), v6);
	}
	return 1;
}

//----- (00443440) --------------------------------------------------------
int nox_cmd_set_lessons(int tokInd, int tokCnt, wchar_t** tokens) {
	const wchar_t* v4; // esi
	char* v5;          // edi
	unsigned short v6; // ax

	if (tokCnt != 3) {
		return 0;
	}
	v4 = tokens[2];
	v5 = sub_4165B0();
	if (v4) {
		v6 = nox_wcstol(v4, 0, 10);
		sub_409FB0_settings(*((uint16_t*)v5 + 26), v6);
	}
	return 1;
}

//----- (004435C0) --------------------------------------------------------
int nox_cmd_clear(int tokInd, int tokCnt, wchar_t** tokens) {
	nox_gui_console_Clear_450B70();
	return 1;
}

//----- (004435D0) --------------------------------------------------------
int nox_cmd_menu_options(int tokInd, int tokCnt, wchar_t** tokens) {
	if (!nox_common_gameFlags_check_40A5C0(8) && nox_common_gameFlags_check_40A5C0(0x2000)) {
		nox_xxx_guiServerOptsLoad_457500();
	}
	return 1;
}

//----- (00443600) --------------------------------------------------------
int nox_cmd_menu_vidopt(int tokInd, int tokCnt, wchar_t** tokens) {
	sub_4ADA40();
	return 1;
}

//----- (00440A50) --------------------------------------------------------
int nox_cmd_bind(int tokInd, int tokCnt, wchar_t** tokens) {
	if (tokCnt != 3) {
		return 0;
	}
	if (nox_wcslen(tokens[1]) >= 0x20) {
		return 0;
	}
	int v3 = sub_440AC0(tokens[1]);
	if (v3 == -1 || nox_wcslen(tokens[2]) >= 0x80) {
		return 0;
	}
	nox_wcscpy((wchar_t*)getMemAt(0x587000, 94516 + 76 * v3), tokens[2]);
	return 1;
}

//----- (004420F0) --------------------------------------------------------
int nox_cmd_reenter(int tokInd, int tokCnt, wchar_t** tokens) {
	if (!nox_common_gameFlags_check_40A5C0(0x2000)) {
		sub_40AA60(1);
	}
	return 1;
}

//----- (004423A0) --------------------------------------------------------
int nox_cmd_startSoloQuest(int tokInd, int tokCnt, wchar_t** tokens) {
	if (nox_xxx_isQuest_4D6F50() && !nox_common_gameFlags_check_40A5C0(4096)) {
		nox_server_conCmdHandler_startSoloQuest_4D7080();
	}
	return 1;
}
