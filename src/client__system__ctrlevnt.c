//+build none

#ifdef _WIN32
#define _USE_MATH_DEFINES
#endif // _WIN32
#include <math.h>
#include "client__system__ctrlevnt.h"

#include "common__strman.h"
#include "GAME1.h"
#include "GAME1_2.h"
#include "GAME1_1.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME2_2.h"
#include "GAME2_3.h"
#include "GAME3.h"
#include "GAME3_1.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4.h"
#include "GAME4_1.h"
#include "GAME4_2.h"
#include "GAME4_3.h"
#include "GAME5.h"
#include "GAME5_2.h"
#include "GAME_data.h"
#include "GAME_data_init.h"
#include "cdrom.h"
#include "client__drawable__drawdb.h"
#include "client__draw__fx.h"
#include "client__draw__image.h"
#include "client__gui__guiinv.h"
#include "client__gui__guimeter.h"
#include "client__gui__guishop.h"
#include "client__gui__guispell.h"
#include "client__gui__servopts__guiserv.h"
#include "client__gui__window.h"
#include "client__io__win95__focus.h"
#include "client__network__netclint.h"
#include "client__shell__optsback.h"
#include "client__system__ctrlevnt.h"
#include "client__video__draw_common.h"
#include "client__video__sdl__draw_nogl.h"
#include "common__config.h"
#include "common__magic__speltree.h"
#include "defs.h"
#include "GAME1_1.h"
#include "GAME1_3.h"
#include "GAME1.h"
#include "GAME2_2.h"
#include "GAME2_3.h"
#include "GAME2.h"
#include "GAME3_3.h"
#include "GAME3.h"
#include "GAME4_1.h"
#include "GAME4.h"
#include "GAME5_2.h"
#include "input_common.h"
#include "input.h"
#include "movie.h"
#include "server__network__mapsend.h"
#include "server__script__builtin.h"
#include "server__script__script.h"
#include "server__xfer__savegame__savegame.h"
#include "thing.h"
#include "win.h"

#include "input.h"
#include "common/fs/nox_fs.h"
#include "client__gui__guicon.h"
#include "client__gui__guisave.h"
#include "client__gui__guispell.h"
#include "client__gui__servopts__guiserv.h"

nox_ctrlevent_key_t* dword_5d4594_754056 = 0;
uint32_t nox_ctrlevent_player_orientation = 0;
extern uint32_t nox_xxx_xxxRenderGUI_587000_80832;
uint32_t dword_5d4594_754036 = 0;
uint32_t dword_5d4594_754040 = 0;
uint32_t dword_5d4594_754044 = 0;
uint32_t dword_5d4594_754048 = 0;
extern uint32_t nox_client_renderGUI_80828;
extern int nox_win_width;
extern int nox_win_height;
extern unsigned int nox_gameFPS;
extern nox_ctrlevent_key_t* dword_5d4594_754056;

long long nox_ctrlevent_ticks = 0;

nox_keybind_t nox_keybind_arr[NOX_KEYEVENT_MAX] = {
	{"KP0", 0x52, "keybind:Kp0", 0},
	{"KP1", 0x4f, "keybind:Kp1", 0},
	{"KP2", 0x50, "keybind:Kp2", 0},
	{"KP3", 0x51, "keybind:Kp3", 0},
	{"KP4", 0x4b, "keybind:Kp4", 0},
	{"KP5", 0x4c, "keybind:Kp5", 0},
	{"KP6", 0x4d, "keybind:Kp6", 0},
	{"KP7", 0x47, "keybind:Kp7", 0},
	{"KP8", 0x48, "keybind:Kp8", 0},
	{"KP9", 0x49, "keybind:Kp9", 0},
	{"KPDEL", 0x53, "keybind:KpPeriod", 0},
	{"KPSTAR", 0x37, "keybind:KpStar", 0},
	{"KPMINUS", 0x4a, "keybind:KpMinus", 0},
	{"KPPLUS", 0x4e, "keybind:KpPlus", 0},
	{"KPENTER", 0x9c, "keybind:KpEnter", 0},
	{"KPSLASH", 0xb5, "keybind:KpSlash", 0},
	{"ESC", 0x1, "keybind:Esc", 0},
	{"BACKSPACE", 0xe, "keybind:Back", 0},
	{"ENTER", 0x1c, "keybind:Enter", 0},
	{"SPACE", 0x39, "keybind:Space", 0},
	{"TAB", 0xf, "keybind:Tab", 0},
	{"F1", 0x3b, "keybind:F1", 0},
	{"F2", 0x3c, "keybind:F2", 0},
	{"F3", 0x3d, "keybind:F3", 0},
	{"F4", 0x3e, "keybind:F4", 0},
	{"F5", 0x3f, "keybind:F5", 0},
	{"F6", 0x40, "keybind:F6", 0},
	{"F7", 0x41, "keybind:F7", 0},
	{"F8", 0x42, "keybind:F8", 0},
	{"F9", 0x43, "keybind:F9", 0},
	{"F10", 0x44, "keybind:F10", 0},
	{"F11", 0x57, "keybind:F11", 0},
	{"F12", 0x58, "keybind:F12", 0},
	{"A", 0x1e, "keybind:A", 0},
	{"B", 0x30, "keybind:B", 0},
	{"C", 0x2e, "keybind:C", 0},
	{"D", 0x20, "keybind:D", 0},
	{"E", 0x12, "keybind:E", 0},
	{"F", 0x21, "keybind:F", 0},
	{"G", 0x22, "keybind:G", 0},
	{"H", 0x23, "keybind:H", 0},
	{"I", 0x17, "keybind:I", 0},
	{"J", 0x24, "keybind:J", 0},
	{"K", 0x25, "keybind:K", 0},
	{"L", 0x26, "keybind:L", 0},
	{"M", 0x32, "keybind:M", 0},
	{"N", 0x31, "keybind:N", 0},
	{"O", 0x18, "keybind:O", 0},
	{"P", 0x19, "keybind:P", 0},
	{"Q", 0x10, "keybind:Q", 0},
	{"R", 0x13, "keybind:R", 0},
	{"S", 0x1f, "keybind:S", 0},
	{"T", 0x14, "keybind:T", 0},
	{"U", 0x16, "keybind:U", 0},
	{"V", 0x2f, "keybind:V", 0},
	{"W", 0x11, "keybind:W", 0},
	{"X", 0x2d, "keybind:X", 0},
	{"Y", 0x15, "keybind:Y", 0},
	{"Z", 0x2c, "keybind:Z", 0},
	{"1", 0x2, "keybind:1", 0},
	{"2", 0x3, "keybind:2", 0},
	{"3", 0x4, "keybind:3", 0},
	{"4", 0x5, "keybind:4", 0},
	{"5", 0x6, "keybind:5", 0},
	{"6", 0x7, "keybind:6", 0},
	{"7", 0x8, "keybind:7", 0},
	{"8", 0x9, "keybind:8", 0},
	{"9", 0xa, "keybind:9", 0},
	{"0", 0xb, "keybind:0", 0},
	{"MINUS", 0xc, "keybind:Minus", 0},
	{"EQUALS", 0xd, "keybind:Equal", 0},
	{"LEFT_BRACKET", 0x1a, "keybind:[", 0},
	{"RIGHT_BRACKET", 0x1b, "keybind:]", 0},
	{"SEMICOLON", 0x27, "keybind:SemiColon", 0},
	{"APOSTROPHE", 0x28, "keybind:Squote", 0},
	{"TICK", 0x29, "keybind:Apos", 0},
	{"BACKSLASH", 0x2b, "keybind:Bslash", 0},
	{"COMMA", 0x33, "keybind:Comma", 0},
	{"PERIOD", 0x34, "keybind:Period", 0},
	{"SLASH", 0x35, "keybind:Slash", 0},
	{"SYSREQ", 0xb7, "keybind:SysReq", 0},
	{"CAPS_LOCK", 0x3a, "keybind:Caps", 0},
	{"NUM", 0x45, "keybind:NumLck", 0},
	{"SCROLL", 0x46, "keybind:Scroll", 0},
	{"LEFT_CTRL", 0x1d, "keybind:LCtrl", 0},
	{"LEFT_ALT", 0x38, "keybind:LAlt", 0},
	{"LEFT_SHIFT", 0x2a, "keybind:LShift", 0},
	{"RIGHT_SHIFT", 0x36, "keybind:RShift", 0},
	{"RIGHT_ALT", 0xb8, "keybind:RAlt", 0},
	{"RIGHT_CTRL", 0x9d, "keybind:RCtrl", 0},
	{"UP_ARROW", 0xc8, "keybind:Up", 0},
	{"DOWN_ARROW", 0xd0, "keybind:Down", 0},
	{"LEFT_ARROW", 0xcb, "keybind:Left", 0},
	{"RIGHT_ARROW", 0xcd, "keybind:Right", 0},
	{"HOME", 0xc7, "keybind:Home", 0},
	{"END", 0xcf, "keybind:End", 0},
	{"PAGEUP", 0xc9, "keybind:PgUp", 0},
	{"PAGEDOWN", 0xd1, "keybind:PgDn", 0},
	{"INS", 0xd2, "keybind:Ins", 0},
	{"DEL", 0xd3, "keybind:Del", 0},
	{"MOUSE_BUTTON_LEFT", 0x10000, "keybind:LeftMouse", 0},
	{"MOUSE_BUTTON_MID", 0x10001, "keybind:MiddleMouse", 0},
	{"MOUSE_BUTTON_RIGHT", 0x10002, "keybind:RightMouse", 0},
	{"MOUSE_WHEEL_UP", 0x10003, "keybind:MouseWheelUp", 0},
	{"MOUSE_WHEEL_DOWN", 0x10004, "keybind:MouseWheelDown", 0},
	{"JOYSTICK_BUTTON_1", 0x20000, "keybind:NA", 0},
	{"JOYSTICK_BUTTON_2", 0x20001, "keybind:NA", 0},
	{"JOYSTICK_BUTTON_3", 0x20002, "keybind:NA", 0},
	{"JOYSTICK_BUTTON_4", 0x20003, "keybind:NA", 0},
	{"JOYSTICK_BUTTON_5", 0x20004, "keybind:NA", 0},
	{"JOYSTICK_BUTTON_6", 0x20005, "keybind:NA", 0},
	{"JOYSTICK_BUTTON_7", 0x20006, "keybind:NA", 0},
	{"JOYSTICK_BUTTON_8", 0x20007, "keybind:NA", 0},
	{"JOYSTICK_BUTTON_9", 0x20008, "keybind:NA", 0},
	{"JOYSTICK_BUTTON_10", 0x20009, "keybind:NA", 0},
	{"JOYSTICK_BUTTON_11", 0x2000a, "keybind:NA", 0},
	{"JOYSTICK_BUTTON_12", 0x2000b, "keybind:NA", 0},
	{"JOYSTICK_BUTTON_13", 0x2000c, "keybind:NA", 0},
	{"JOYSTICK_BUTTON_14", 0x2000d, "keybind:NA", 0},
	{"JOYSTICK_BUTTON_15", 0x2000e, "keybind:NA", 0},
	{"JOYSTICK_BUTTON_16", 0x2000f, "keybind:NA", 0},
	{"JOYSTICK_BUTTON_17", 0x20010, "keybind:NA", 0},
	{"JOYSTICK_BUTTON_18", 0x20011, "keybind:NA", 0},
	{"JOYSTICK_BUTTON_19", 0x20012, "keybind:NA", 0},
	{"JOYSTICK_BUTTON_20", 0x20013, "keybind:NA", 0},
	{"JOYSTICK_BUTTON_21", 0x20014, "keybind:NA", 0},
	{"JOYSTICK_BUTTON_22", 0x20015, "keybind:NA", 0},
	{"JOYSTICK_BUTTON_23", 0x20016, "keybind:NA", 0},
	{"JOYSTICK_BUTTON_24", 0x20017, "keybind:NA", 0},
	{"JOYSTICK_BUTTON_25", 0x20018, "keybind:NA", 0},
	{"JOYSTICK_BUTTON_26", 0x20019, "keybind:NA", 0},
	{"JOYSTICK_BUTTON_27", 0x2001a, "keybind:NA", 0},
	{"JOYSTICK_BUTTON_28", 0x2001b, "keybind:NA", 0},
	{"JOYSTICK_BUTTON_29", 0x2001c, "keybind:NA", 0},
	{"JOYSTICK_BUTTON_30", 0x2001d, "keybind:NA", 0},
	{"JOYSTICK_BUTTON_31", 0x2001e, "keybind:NA", 0},
	{"JOYSTICK_BUTTON_32", 0x2001f, "keybind:NA", 0},
};

nox_bindevent_t nox_bindevent_arr[NOX_BINDEVENT_MAX] = {
	{"", 0, 0}, // represents no binding
	{"MoveForward", 0x2, 0},
	{"Action", 0x1, 0},
	{"Jump", 0x6, 0},
	{"ToggleInventory", 0x7, 0},
	{"ToggleBook", 0xa, 0},
	{"ToggleMap", 0x10, 0},
	{"MapZoomOut", 0x22, 0},
	{"MapZoomIn", 0x21, 0},
	{"InvokeSlot1", 0x1c, 0},
	{"InvokeSlot2", 0x1d, 0},
	{"InvokeSlot3", 0x1e, 0},
	{"InvokeSlot4", 0x1f, 0},
	{"InvokeSlot5", 0x20, 0},
	{"PreviousSpellSet", 0x28, 0},
	{"NextSpellSet", 0x27, 0},
	{"SelectSpellSet", 0x29, 0},
	{"InvertSpellTarget", 0x31, 0},
	{"PlaceTrapBomber", 0x2a, 0},
	{"SwapWeapons", 0x23, 0},
	{"QuickHealth", 0x24, 0},
	{"QuickMana", 0x25, 0},
	{"QuickCurePoison", 0x26, 0},
	{"Chat", 0x8, 0},
	{"TeamChat", 0x9, 0},
	{"ToggleConsole", 0xb, 0},
	{"ToggleQuitMenu", 0x2c, 0},
	{"ToggleServerMenu", 0x2d, 0},
	{"ToggleRank", 0x32, 0},
	{"ToggleNetstat", 0x33, 0},
	{"ToggleGUI", 0x34, 0},
	{"AutoSave", 0x35, 0},
	{"AutoLoad", 0x36, 0},
	{"Taunt", 0x2e, 0},
	{"Point", 0x30, 0},
	{"Laugh", 0x2f, 0},
	{"IncreaseWindowSize", 0xc, 0},
	{"DecreaseWindowSize", 0xd, 0},
	{"IncreaseGamma", 0xe, 0},
	{"DecreaseGamma", 0xf, 0},
	{"ScreenShot", 0x37, 0},
};

nox_ctrlevent_xxx_t nox_ctrlevent_buf_747884[NOX_CTRLEVENT_XXX_MAX] = {0};
nox_ctrlevent_xxx_t nox_ctrlevent_buf_750964[NOX_CTRLEVENT_XXX_MAX] = {0}; // TODO: size a guess

nox_ctrlevent_code_info_t nox_ctrlevent_code_infos[] = {
		{"CC_Null", 0, 0},
		{"CC_Orientation", 0x1, 0x1},
		{"CC_MoveForward", 0x1, 0x1},
		{"CC_MoveBackward", 0x1, 0x1},
		{"CC_MoveLeft", 0x1, 0x1},
		{"CC_MoveRight", 0x1, 0x1},
		{"CC_Action", 0, 0},
		{"CC_Jump", 0, 0},
		{"CC_Chat", 0, 0},
		{"CC_TeamChat", 0, 0},
		{"CC_ReadSpellbook", 0, 0},
		{"CC_ToggleConsole", 0, 0},
		// TODO: somewhere around here the names for indexes are off by +2 (e.g. CC_QuitMenu = 17)
		{"CC_IncreaseWindowSize", 0, 0},
		{"CC_DecreaseWindowSize", 0, 0},
		{"CC_Quit", 0, 0},
		{"CC_QuitMenu", 0, 0},
		{"CC_ReadMap", 0, 0},
		{"CC_Inventory", 0, 0},
		{"CC_SpellGestureUp", 0, 0},
		{"CC_SpellGestureDown", 0, 0},
		{"CC_SpellGestureLeft", 0, 0},
		{"CC_SpellGestureRight", 0, 0},
		{"CC_SpellGestureUpperRight", 0, 0},
		{"CC_SpellGestureUpperLeft", 0, 0},
		{"CC_SpellGestureLowerRight", 0, 0},
		{"CC_SpellGestureLowerLeft", 0, 0},
		{"CC_SpellPatternEnd", 0x1, 0x1},
		{"CC_CastQueuedSpell", 0x1, 0x4},
		{"CC_CastMostRecentSpell", 0x1, 0x4},
		{"CC_CastSpell1", 0, 0},
		{"CC_CastSpell2", 0, 0},
		{"CC_CastSpell3", 0, 0},
		{"CC_CastSpell4", 0, 0},
		{"CC_CastSpell5", 0, 0},
		{"CC_MapZoomIn", 0, 0},
		{"CC_MapZoomOut", 0, 0},
		{"CC_NextWeapon", 0, 0},
		{"CC_QuickHealthPotion", 0, 0},
		{"CC_QuickManaPotion", 0, 0},
		{"CC_QuickCurePoisonPotion", 0, 0},
		{"CC_NextSpellSet", 0, 0},
		{"CC_PreviousSpellSet", 0, 0},
		{"CC_SelectSpellSet", 0, 0},
		{"CC_BuildTrap", 0, 0},
		{"CC_ServerOptions", 0, 0},
		{"CC_Taunt", 0, 0},
		{"CC_Laugh", 0, 0},
		{"CC_Point", 0, 0},
		{"CC_InvertSpellTarget", 0, 0},
		{"CC_ToggleRank", 0, 0},
		{"CC_ToggleNetstat", 0, 0},
		{"CC_ToggleGUI", 0, 0},
		{"CC_AutoSave", 0, 0},
		{"CC_AutoLoad", 0, 0},
		{"CC_ScreenShot", 0, 0},
		{"CC_Unknown55", 0, 0},
		{"CC_Unknown56", 0, 0},
};
int nox_ctrlevent_code_infos_cnt = sizeof(nox_ctrlevent_code_infos) / sizeof(nox_ctrlevent_code_info_t);

//----- (0042D440) --------------------------------------------------------
int nox_ctrlevent_has_data_42D440(nox_ctrlevent_code code) {
	return nox_ctrlevent_code_infos[code].has_data;
}

//----- (0042D450) --------------------------------------------------------
unsigned char nox_ctrlevent_data_size_42D450(nox_ctrlevent_code code) {
	return nox_ctrlevent_code_infos[code].data_size;
}

//----- (0042E630) --------------------------------------------------------
int nox_ctrlevent_add_ticks_42E630() {
	char* v0 = (char*)sub_416640();
	switch (*(uint32_t*)(v0 + 66)) {
	case 1:
		return sub_554290();
	case 2:
		return sub_554300();
	case 3:
		return *(uint32_t*)(v0 + 70);
	default:
		return 0;
	}
}
// 42E644: control flows out of bounds to 554290
// 42E649: control flows out of bounds to 554300

char*  nox_xxx_keybind_nameByKey(unsigned int key) {
	for (int i = 0; i < NOX_KEYEVENT_MAX; i++) {
		nox_keybind_t* ev = &nox_keybind_arr[i];
		if (ev->key == key) {
			return ev->name;
		}
	}
	return 0;
}

unsigned int nox_xxx_keybind_keyByName(char* name) {
	for (int i = 0; i < NOX_KEYEVENT_MAX; i++) {
		nox_keybind_t* ev = &nox_keybind_arr[i];
		if (strcmp(ev->name, name) == 0) {
			return ev->key;
		}
	}
	return 0;
}

//----- (0042E960) --------------------------------------------------------
char*  nox_xxx_keybind_nameByTitle_42E960(wchar_t* title) {
	for (int i = 0; i < NOX_KEYEVENT_MAX; i++) {
		nox_keybind_t* ev = &nox_keybind_arr[i];
		if (_nox_wcsicmp(ev->title, title) == 0) {
			return ev->name;
		}
	}
	return 0;
}

//----- (0042EA00) --------------------------------------------------------
wchar_t* nox_xxx_keybind_titleByKey_42EA00(unsigned int a1) {
	for (int i = 0; i < NOX_KEYEVENT_MAX; i++) {
		nox_keybind_t* ev = &nox_keybind_arr[i];
		if (ev->key == a1) {
			return ev->title;
		}
	}
	return L"";
}

//----- (0042EA00) --------------------------------------------------------
wchar_t* nox_xxx_keybind_titleByKeyZero_42EA00(unsigned int a1) {
	for (int i = 0; i < NOX_KEYEVENT_MAX; i++) {
		nox_keybind_t* ev = &nox_keybind_arr[i];
		if (ev->key == a1) {
			return ev->title;
		}
	}
	return 0;
}

char* nox_xxx_bindevent_bindNameByKey(unsigned int key) {
	for (int i = 0; i < NOX_BINDEVENT_MAX; i++) {
		nox_bindevent_t* ev = &nox_bindevent_arr[i];
		if (ev->key == key) {
			return ev->name;
		}
	}
	return 0;
}

unsigned int nox_xxx_bindevent_bindKeyByName(char* name) {
	for (int i = 0; i < NOX_BINDEVENT_MAX; i++) {
		nox_bindevent_t* ev = &nox_bindevent_arr[i];
		if (strcmp(ev->name, name) == 0) {
			return ev->key;
		}
	}
	return 0;
}

//----- (0042EA40) --------------------------------------------------------
char* nox_xxx_bindevent_bindNameByTitle_42EA40(wchar_t* title) {
	for (int i = 0; i < NOX_BINDEVENT_MAX; i++) {
		nox_bindevent_t* ev = &nox_bindevent_arr[i];
		if (_nox_wcsicmp(ev->title, title) == 0) {
			return ev->name;
		}
	}
	return 0;
}

//----- (0042EAE0) --------------------------------------------------------
void nox_xxx_bindevent_initStrings_42EAE0() {
	for (int i = 0; i < NOX_KEYEVENT_MAX; i++) {
		nox_keybind_t* ev = &nox_keybind_arr[i];
		ev->title = nox_strman_loadString_40F1D0(ev->title_id, 0, "C:\\NoxPost\\src\\Client\\System\\Ctrlevnt.c", 2092);
	}
	char buf[256];
	nox_bindevent_arr[0].title = nox_strman_loadString_40F1D0("bindevent:NullEvent", 0, "C:\\NoxPost\\src\\Client\\System\\Ctrlevnt.c", 2095);
	for (int i = 1; i < NOX_BINDEVENT_MAX; i++) {
		nox_bindevent_t* ev = &nox_bindevent_arr[i];
		nox_sprintf(buf, "bindevent:%s", ev->name);
		ev->title = nox_strman_loadString_40F1D0(buf, 0, "C:\\NoxPost\\src\\Client\\System\\Ctrlevnt.c", 2100);
	}
}

//----- (0042D6B0) --------------------------------------------------------
void nox_xxx_clientControl_42D6B0_orientation(nox_mouse_state_t* mouse) {
	if (getMemByte(0x5D4594, 747848) != 2 && *getMemU32Ptr(0x5D4594, 747868) == 4) {
		// calculates player orientation
		void* v15 = nox_xxx_spriteGetMB_476F80();
		int x = mouse->pos.x;
		int y = mouse->pos.y;
		if (v15) {
			y = sub_4739D0(*(uint32_t *) ((uint32_t)v15 + 16));
		}
		int cx = x - nox_win_width / 2;
		int cy = y - nox_win_height / 2;
		double rad = atan2(cy, cx);
		if (controller_relative()) {
			nox_pointf p = controller_relative_pos();
			rad = atan2(p.y, p.x);
		}
		// represent as integer
		int ang = (int)((rad + 2 * M_PI) * 128.0/M_PI + 0.5);
		if (ang < 0) {
			ang += ((unsigned int)(255 - ang) >> 8) << 8;
		}
		if (ang >= 256) {
			ang -= ((unsigned int)ang >> 8) << 8;
		}
		nox_ctrlevent_player_orientation = ang;
	}
	nox_ctrlevent_action_42E670(CC_Orientation, nox_ctrlevent_player_orientation);
}
void nox_xxx_clientControl_42D6B0_A(int a4) {
	int v2 = *getMemU32Ptr(0x8531A0, 2576);
	for (int i = a4; i; i = *(uint32_t*)(i + 84)) {
		for (int j = 0; j < *(int*)(i + 68); ++j) {
			switch (*(uint32_t*)(i + 4 * j + 36)) {
				case 1:;
					int v9 = nox_client_getCursorType_477620();
					switch (v9) {
						case 3:;
							int v10 = nox_xxx_clientGetSpriteAtCursor_476F90();
							nox_xxx_clientTrade_42E850(v10);
							break;
						case 4:;
							int v11 = nox_xxx_clientGetSpriteAtCursor_476F90();
							if (*(uint8_t*)(v11 + 280) & 0x10) {
								nox_xxx_clientTalk_42E7B0(v11);
							}
							break;
						case 13:;
							int v12 = nox_xxx_clientGetSpriteAtCursor_476F90();
							nox_xxx_clientCollideOrUse_42E810(v12);
							break;
						default:
							nox_ctrlevent_action_42E670(CC_Action, 0);
							break;
					}
					break;
				case 2:
					if (nox_input_isMouseDown()) {
						int v5 = 1;
						if (getMemByte(0x5D4594, 754064) & 8) {
							v5 = 3;
						}
						nox_ctrlevent_action_42E670(CC_MoveForward, v5);
					}
					break;
				case 3:;
					int v6 = (getMemByte(0x5D4594, 754064) & 1) != 0;
					if (getMemByte(0x5D4594, 754064) & 8) {
						v6 |= 2;
					}
					nox_ctrlevent_action_42E670(CC_MoveBackward, v6);
					break;
				case 4:;
					int v7 = (getMemByte(0x5D4594, 754064) & 1) != 0;
					if (getMemByte(0x5D4594, 754064) & 8) {
						v7 |= 2;
					}
					nox_ctrlevent_action_42E670(CC_MoveLeft, v7);
					break;
				case 5:;
					int v8 = (getMemByte(0x5D4594, 754064) & 1) != 0;
					if (getMemByte(0x5D4594, 754064) & 8) {
						v8 |= 2;
					}
					nox_ctrlevent_action_42E670(CC_MoveRight, v8);
					break;
				case 6:
					nox_ctrlevent_action_42E670(CC_Jump, 0);
					break;
				case 7:
					nox_ctrlevent_action_42E670(CC_SpellGestureDown, 0);
					break;
				case 8:
					nox_ctrlevent_action_42E670(CC_Chat, 0);
					break;
				case 9:
					if (!(*(uint8_t*)(v2 + 3680) & 1)) {
						nox_ctrlevent_action_42E670(CC_TeamChat, 0);
					}
					break;
				case 0xA:
					nox_ctrlevent_action_42E670(CC_ReadSpellbook, 0);
					break;
				case 0xB:
					nox_ctrlevent_action_42E670(CC_ToggleConsole, 0);
					break;
				case 0xC:
					if (!nox_xxx_checkGameFlagPause_413A50()) {
						nox_ctrlevent_action_42E670(CC_IncreaseWindowSize, 0);
					}
					break;
				case 0xD:
					if (!nox_xxx_checkGameFlagPause_413A50()) {
						nox_ctrlevent_action_42E670(CC_DecreaseWindowSize, 0);
					}
					break;
				case 0xE:
					nox_ctrlevent_action_42E670(CC_Quit, 0);
					break;
				case 0xF:
					nox_ctrlevent_action_42E670(CC_QuitMenu, 0);
					break;
				case 0x10:
					nox_ctrlevent_action_42E670(CC_SpellGestureUp, 0);
					break;
				case 0x11:
					if (!nox_xxx_guiSpellTest_45D9C0()) {
						int v13 = nox_xxx_packetGetMarshall_476F40();
						nox_ctrlevent_action_42E780(CC_CastSpell1, v13);
					}
					break;
				case 0x12:
					if (!nox_xxx_guiSpellTest_45D9C0()) {
						nox_ctrlevent_action_42E780(CC_SpellGestureLeft, 0);
					}
					break;
				case 0x13:
					if (!nox_xxx_guiSpellTest_45D9C0()) {
						nox_ctrlevent_action_42E780(CC_SpellGestureRight, 0);
					}
					break;
				case 0x14:
					if (!nox_xxx_guiSpellTest_45D9C0()) {
						nox_ctrlevent_action_42E780(CC_SpellGestureUpperRight, 0);
					}
					break;
				case 0x15:
					if (!nox_xxx_guiSpellTest_45D9C0()) {
						nox_ctrlevent_action_42E780(CC_SpellGestureUpperLeft, 0);
					}
					break;
				case 0x16:
					if (!nox_xxx_guiSpellTest_45D9C0()) {
						nox_ctrlevent_action_42E780(CC_SpellGestureLowerRight, 0);
					}
					break;
				case 0x17:
					if (!nox_xxx_guiSpellTest_45D9C0()) {
						nox_ctrlevent_action_42E780(CC_SpellGestureLowerLeft, 0);
					}
					break;
				case 0x18:
					if (!nox_xxx_guiSpellTest_45D9C0()) {
						nox_ctrlevent_action_42E780(CC_SpellPatternEnd, 0);
					}
					break;
				case 0x19:
					if (!nox_xxx_guiSpellTest_45D9C0()) {
						nox_ctrlevent_action_42E780(CC_CastQueuedSpell, 0);
					}
					break;
				case 0x1A:
					if (!nox_xxx_guiSpellTest_45D9C0()) {
						nox_ctrlevent_action_42E780(CC_CastMostRecentSpell, 0);
					}
					break;
				case 0x1B:
					if (!nox_xxx_guiSpellTest_45D9C0()) {
						int v14 = nox_xxx_packetGetMarshall_476F40();
						nox_ctrlevent_action_42E780(CC_CastSpell2, v14);
					}
					break;
				case 0x1C:
					nox_ctrlevent_action_42E780(CC_CastSpell3, 0);
					break;
				case 0x1D:
					nox_ctrlevent_action_42E780(CC_CastSpell4, 0);
					break;
				case 0x1E:
					nox_ctrlevent_action_42E780(CC_CastSpell5, 0);
					break;
				case 0x1F:
					nox_ctrlevent_action_42E780(CC_MapZoomIn, 0);
					break;
				case 0x20:
					nox_ctrlevent_action_42E780(CC_MapZoomOut, 0);
					break;
				case 0x21:
					nox_ctrlevent_action_42E670(CC_NextWeapon, 0);
					break;
				case 0x22:
					nox_ctrlevent_action_42E670(CC_QuickHealthPotion, 0);
					break;
				case 0x23:
					nox_ctrlevent_action_42E780(CC_QuickManaPotion, 0);
					break;
				case 0x24:
					nox_ctrlevent_action_42E780(CC_QuickCurePoisonPotion, 0);
					break;
				case 0x25:
					nox_ctrlevent_action_42E780(CC_NextSpellSet, 0);
					break;
				case 0x26:
					nox_ctrlevent_action_42E780(CC_PreviousSpellSet, 0);
					break;
				case 0x27:
					nox_ctrlevent_action_42E780(CC_SelectSpellSet, 0);
					break;
				case 0x28:
					nox_ctrlevent_action_42E780(CC_BuildTrap, 0);
					break;
				case 0x29:
					nox_ctrlevent_action_42E780(CC_ServerOptions, 0);
					break;
				case 0x2A:
					nox_ctrlevent_action_42E780(CC_Taunt, 0);
					break;
				case 0x2B:
					nox_ctrlevent_action_42E670(CC_ReadMap, 0);
					break;
				case 0x2C:
					nox_ctrlevent_action_42E670(CC_Inventory, 0);
					break;
				case 0x2D:
					nox_ctrlevent_action_42E670(CC_Laugh, 0);
					break;
				case 0x2E:
					if (nox_common_gameFlags_check_40A5C0(0x2000) &&
						nox_xxx_checkKeybTimeout_4160F0(0x15u, nox_gameFPS)) {
						nox_xxx_setKeybTimeout_4160D0(21);
						nox_ctrlevent_action_42E670(CC_Point, 0);
					}
					break;
				case 0x2F:
					if (nox_common_gameFlags_check_40A5C0(0x2000) &&
						nox_xxx_checkKeybTimeout_4160F0(0x14u, 2 * nox_gameFPS)) {
						nox_xxx_setKeybTimeout_4160D0(20);
						nox_ctrlevent_action_42E670(CC_InvertSpellTarget, 0);
					}
					break;
				case 0x30:
					if (nox_common_gameFlags_check_40A5C0(0x2000) &&
						nox_xxx_checkKeybTimeout_4160F0(0x16u, nox_gameFPS)) {
						nox_xxx_setKeybTimeout_4160D0(22);
						nox_ctrlevent_action_42E670(CC_ToggleRank, 0);
					}
					break;
				case 0x31:
					nox_ctrlevent_action_42E670(CC_ToggleNetstat, 0);
					break;
				case 0x32:
					if (nox_common_gameFlags_check_40A5C0(0x2000)) {
						nox_ctrlevent_action_42E670(CC_ToggleGUI, 0);
					}
					break;
				case 0x33:
					if (!nox_xxx_checkGameFlagPause_413A50()) {
						nox_ctrlevent_action_42E670(CC_AutoSave, 0);
					}
					break;
				case 0x34:
					nox_ctrlevent_action_42E670(CC_AutoLoad, 0);
					break;
				case 0x35:
					if (nox_common_gameFlags_check_40A5C0(2048) && !nox_xxx_guiCursor_477600()) {
						nox_ctrlevent_action_42E670(CC_ScreenShot, 0);
					}
					break;
				case 0x36:
					if (nox_common_gameFlags_check_40A5C0(2048) && !nox_xxx_guiCursor_477600()) {
						nox_ctrlevent_action_42E670(CC_Unknown55, 0);
					}
					break;
				case 0x37:
					nox_ctrlevent_action_42E670(CC_Unknown56, 0);
					break;
				default:
					break;
			}
		}
	}
}
void nox_xxx_clientControl_42D6B0_B() {
	int l0 = 0;
	int v34 = 0;
	if (nox_common_gameFlags_check_40A5C0(1)) {
		l0 = dword_5d4594_754040;
		v34 = dword_5d4594_754036;
		if (dword_5d4594_754036 < *(int*)&dword_5d4594_754040) {
			v34 = dword_5d4594_754036 + NOX_CTRLEVENT_XXX_MAX;
		}
	} else {
		v34 = dword_5d4594_754036;
	}
	int v43 = v34;
	for (int l = l0; l < v43; ++l) {
		int li = l % NOX_CTRLEVENT_XXX_MAX;
		if (!(nox_ctrlevent_buf_747884[li].active)) {
			continue;
		}
		switch (nox_ctrlevent_buf_747884[li].code) {
			case 0x14:
				if (!nox_common_gameFlags_check_40A5C0(128)) {
					nox_xxx_clientPlaySoundSpecial_452D80(186, 100);
					nox_client_setPhonemeFrame_476E00(1);
				}
				break;
			case 0x15:
				if (!nox_common_gameFlags_check_40A5C0(128)) {
					nox_xxx_clientPlaySoundSpecial_452D80(190, 100);
					nox_client_setPhonemeFrame_476E00(6);
				}
				break;
			case 0x16:
				if (!nox_common_gameFlags_check_40A5C0(128)) {
					nox_xxx_clientPlaySoundSpecial_452D80(192, 100);
					nox_client_setPhonemeFrame_476E00(3);
				}
				break;
			case 0x17:
				if (!nox_common_gameFlags_check_40A5C0(128)) {
					nox_xxx_clientPlaySoundSpecial_452D80(188, 100);
					nox_client_setPhonemeFrame_476E00(4);
				}
				break;
			case 0x18:
				if (!nox_common_gameFlags_check_40A5C0(128)) {
					nox_xxx_clientPlaySoundSpecial_452D80(187, 100);
					nox_client_setPhonemeFrame_476E00(2);
				}
				break;
			case 0x19:
				if (!nox_common_gameFlags_check_40A5C0(128)) {
					nox_xxx_clientPlaySoundSpecial_452D80(193, 100);
					nox_client_setPhonemeFrame_476E00(0);
				}
				break;
			case 0x1A:
				if (!nox_common_gameFlags_check_40A5C0(128)) {
					nox_xxx_clientPlaySoundSpecial_452D80(189, 100);
					nox_client_setPhonemeFrame_476E00(7);
				}
				break;
			case 0x1B:
				if (!nox_common_gameFlags_check_40A5C0(128)) {
					nox_xxx_clientPlaySoundSpecial_452D80(191, 100);
					nox_client_setPhonemeFrame_476E00(5);
				}
				break;
			default:
				break;
		}
		int v37 = nox_ctrlevent_buf_747884[li].code;
		int tmp = 0;
		switch (v37) {
			case 8:
				nox_client_chatStart_46A430(0);
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 9:
				nox_client_chatStart_46A430(1);
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 10:
				nox_client_toggleSpellbook_45AC70();
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 11:
				nox_client_toggleConsole_451350();
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 12:
				nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
				nox_client_increaseViewport_4766E0();
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 13:
				nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
				nox_client_decreaseViewport_4766F0();
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 14:
				nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
				int v38 = nox_video_getGammaSetting_434B00();
				nox_video_setGammaSetting_434B30(v38 + 1);
				updateGamma(1);
				sub_434B60();
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 15:
				nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
				int v39 = nox_video_getGammaSetting_434B00();
				nox_video_setGammaSetting_434B30(v39 - 1);
				updateGamma(-1);
				sub_434B60();
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 16:
				nox_client_quit_4460C0();
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 17:
				if (sub_450560()) {
					nox_savegame_sub_46D580();
				} else {
					sub_42EB90(1);
				}
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 18:
				nox_client_toggleMap_473610();
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 19:
				nox_client_toggleInventory_467C60();
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 31:
			case 32:
			case 33:
			case 34:
			case 35:
				nox_client_invokeSpellSlot_45DA50(v37 - 31);
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 36:
				nox_client_mapZoomIn_4724E0();
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 37:
				nox_client_mapZoomOut_472500();
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 38:
				nox_client_invAlterWeapon_4672C0();
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 39:
				nox_client_quickHealthPotion_472220();
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 40:
				nox_client_quickManaPotion_472240();
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 41:
				nox_client_quickCurePoisonPotion_472260();
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 42:
				nox_client_spellSetNext_4604F0();
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 43:
				nox_client_spellSetPrev_460540();
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 44:
				nox_client_spellSetSelect_460590();
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 45:
				nox_client_buildTrap_45E040();
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 46:
				if (!(nox_common_gameFlags_check_40A5C0(8) || !nox_common_gameFlags_check_40A5C0(0x2000))) {
					nox_xxx_guiServerOptsLoad_457500();
				}
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 47:
				tmp = 739;
				nox_xxx_netClientSend2_4E53C0(31, &tmp, 2, 0, 1);
				break;
			case 48:
				tmp = 483;
				nox_xxx_netClientSend2_4E53C0(31, &tmp, 2, 0, 1);
				break;
			case 49:;
				char v42[2];
				v42[0] = -29;
				v42[1] = 4;
				nox_xxx_netClientSend2_4E53C0(31, v42, 2, 0, 1);
				break;
			case 50:
				sub_460630();
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 51:
				nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
				sub_4703F0();
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 52:
				sub_470A60();
				nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 53:
				if (!nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
					nox_client_renderGUI_80828 ^= 1u;
					nox_xxx_xxxRenderGUI_587000_80832 = nox_client_renderGUI_80828;
					nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
				}
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 54:
				if (nox_common_gameFlags_check_40A5C0(2048)) {
					if (nox_xxx_game_4DCCB0()) {
						nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
						sub_4DB130("AUTOSAVE");
						sub_4DB170(1, 0, 0);
					} else {
						nox_xxx_clientPlaySoundSpecial_452D80(231, 100);
					}
				}
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 55:
				if (nox_common_gameFlags_check_40A5C0(2048)) {
					if (nox_xxx_game_4DCCB0()) {
						nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
						sub_413A00(1);
						wchar_t* v41 = nox_strman_loadString_40F1D0("GUIQuit.c:ReallyLoadMessage", 0,
																 "C:\\NoxPost\\src\\Client\\System\\Ctrlevnt.c", 1867);
						wchar_t* v40 = nox_strman_loadString_40F1D0("SelChar.c:LoadLabel", 0,
																 "C:\\NoxPost\\src\\Client\\System\\Ctrlevnt.c", 1866);
						nox_xxx_dialogMsgBoxCreate_449A10(0, (int)v40, (int)v41, 56, sub_42E600, sub_42E620);
					} else {
						nox_xxx_clientPlaySoundSpecial_452D80(231, 100);
					}
				}
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 56:
				nox_xxx_saveScreenshot_46DB00();
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			default:
				break;
		}
	}
}
void nox_xxx_clientControl_42D6B0_C() {
	if (nox_common_gameFlags_check_40A5C0(1)) {
		int v20 = dword_5d4594_754040;
		if (dword_5d4594_754048 != dword_5d4594_754040) {
			int cnt = 0;
			for (int i = dword_5d4594_754048; i != v20; i = (i + 1) % NOX_CTRLEVENT_XXX_MAX) {
				memcpy(&nox_ctrlevent_buf_750964[cnt], &nox_ctrlevent_buf_747884[i], sizeof(nox_ctrlevent_xxx_t));
				cnt++;
			}
			if (cnt > 0) {
				dword_5d4594_754048 = v20;
				dword_5d4594_754044 = cnt;
			}
		}
		int v23 = dword_5d4594_754044;
		for (int i = v20; i != dword_5d4594_754036; i = (i + 1) % NOX_CTRLEVENT_XXX_MAX) {
			if (v23 <= 0) {
				continue;
			}
			nox_ctrlevent_xxx_t* p1 = &nox_ctrlevent_buf_747884[i];
			for (int j = 0; j < v23; j++) {
				nox_ctrlevent_xxx_t* p2 = &nox_ctrlevent_buf_750964[j];
				if (p1->code == p2->code) {
					if (nox_xxx_keyCanPauseMode_42D4B0(p1->code)) {
						p1->active = 0;
					}
					v23 = dword_5d4594_754044;
					break;
				}
			}
		}
	} else {
		if (dword_5d4594_754036 > 0) {
			for (int i = 0; i < dword_5d4594_754036; i++) {
				nox_ctrlevent_xxx_t* p1 = &nox_ctrlevent_buf_747884[i];
				p1->active = 1;
				if (dword_5d4594_754044 > 0) {
					for (int j = 0; j < dword_5d4594_754044; j++) {
						nox_ctrlevent_xxx_t* p2 = &nox_ctrlevent_buf_750964[j];
						if (p1->code == p2->code) {
							if (nox_xxx_keyCanPauseMode_42D4B0(p1->code)) {
								p1->active = 0;
							}
							break;
						}
					}
				}
			}
			memcpy(nox_ctrlevent_buf_750964, nox_ctrlevent_buf_747884, sizeof(nox_ctrlevent_xxx_t) * dword_5d4594_754036);
		}
		dword_5d4594_754044 = dword_5d4594_754036;
	}
}
void nox_xxx_clientControl_42D6B0(nox_mouse_state_t* mouse, int a4) {
	nox_ctrlevent_ticks = nox_platform_get_ticks();
	if (nox_common_gameFlags_check_40A5C0(1) && nox_common_gameFlags_check_40A5C0(0x2000)) {
		nox_ctrlevent_ticks += nox_ctrlevent_add_ticks_42E630();
	}
	if (!nox_common_gameFlags_check_40A5C0(1)) {
		dword_5d4594_754036 = 0;
	}
	nox_xxx_clientControl_42D6B0_A(a4);
#ifdef __EMSCRIPTEN__
	if (!nox_input_isMouseDown()) {
		nox_xxx_clientControl_42D6B0_em_not_mouse_down();
	} else
#endif
	{
		nox_xxx_clientControl_42D6B0_orientation(mouse);
	}
	if (getMemByte(0x85B3FC, 12254) != 0) {
		nox_xxx_guiSpellTargetClickCheckSend_45DBB0();
	}
	if (getMemByte(0x5D4594, 754064) & 4) {
		nox_ctrlevent_action_42E670(CC_CastMostRecentSpell, 0);
	}
	nox_xxx_clientControl_42D6B0_C();
	*getMemU32Ptr(0x5D4594, 754064) = 0;
	nox_xxx_clientControl_42D6B0_B();
}

//----- (0042E670) --------------------------------------------------------
void nox_ctrlevent_action_42E670(nox_ctrlevent_code code, uint32_t data) {
	if (!nox_common_gameFlags_check_40A5C0(1)) {
		if (dword_5d4594_754036 >= NOX_CTRLEVENT_XXX_MAX) {
			return;
		}
	} else {
		if (dword_5d4594_754036 + 1 == dword_5d4594_754040) {
			return;
		}
	}
	if (getMemByte(0x85B3FC, 12254) != 0 || (nox_xxx_keyCheckWarrorKeys_42D460(code) == 0)) {
		int j = dword_5d4594_754036;
		if (nox_common_gameFlags_check_40A5C0(1) && nox_xxx_keyCanPauseMode_42D4B0(code)) {
			for (int i = dword_5d4594_754040; i != dword_5d4594_754036; i = (i + 1) % NOX_CTRLEVENT_XXX_MAX) {
				if (nox_ctrlevent_buf_747884[i].code == code) {
					return;
				}
			}
		}
		nox_ctrlevent_buf_747884[j].tick = nox_ctrlevent_ticks;
		nox_ctrlevent_buf_747884[j].code = code;
		nox_ctrlevent_buf_747884[j].data = data;
		nox_ctrlevent_buf_747884[j].active = 1;
		dword_5d4594_754036 = j + 1;
		if (nox_common_gameFlags_check_40A5C0(1)) {
			dword_5d4594_754036 %= NOX_CTRLEVENT_XXX_MAX;
		}
	}
}

//----- (0042E780) --------------------------------------------------------
void nox_ctrlevent_action_42E780(nox_ctrlevent_code code, uint32_t data) {
	if (*getMemU32Ptr(0x852978, 8) && !(*(uint8_t*)(*getMemU32Ptr(0x852978, 8) + 120) & 2)) {
		if (!nox_xxx_checkGameFlagPause_413A50()) {
			nox_ctrlevent_action_42E670(code, data);
		}
	}
}

//----- (0042CD70) --------------------------------------------------------
nox_ctrlevent_key_t* nox_xxx_getBindKeysBuf_42CD70() { return dword_5d4594_754056; }


//----- (0042E8C0) --------------------------------------------------------
void  sub_42E8C0(int a1) {
	nullsub_33(a1, nox_ctrlevent_buf_747884, dword_5d4594_754036);
}
// 42E8B0: using guessed type void  nullsub_33(uint32_t, uint32_t, uint32_t);

//----- (0042E8E0) --------------------------------------------------------
wchar_t* sub_42E8E0(int a1, int a2) {
	for (nox_ctrlevent_key_t* v2 = dword_5d4594_754056; v2; v2 = v2->field_19) {
		int v3 = v2->field_9_cnt;
		if (v3 <= 0) {
			continue;
		}
		for (int v4 = 0; v4 < v3 && v4 < NOX_CTRLEVENT_KEYS_NUM; v4++) {
			if (v2->field_9[v4] == a1 && --a2 <= 0) {
				const wchar_t* title = nox_xxx_keybind_titleByKeyZero_42EA00(v2->keys[0]);
				if (title) {
					return title;
				}
			}
		}
	}
	return L"";
}

//----- (0042CF50) --------------------------------------------------------
int  nox_client_parseConfigHotkeysLine_42CF50(char* a1) {
	int result;           // eax
	const char* v2;       // ebp
	uint32_t* v3;           // ebx
	char* v4;             // ebp
	int v5;               // edi
	const char** v6;      // esi
	int v10;              // eax
	char* v11;            // eax
	int v15;              // eax
	char* v16;            // [esp+10h] [ebp-408h]
	int v17;              // [esp+14h] [ebp-404h]
	char v18[1024];       // [esp+18h] [ebp-400h]

	*getMemU32Ptr(0x5D4594, 747868) = 4;
	*getMemU8Ptr(0x5D4594, 747848) = 0;
	strcpy(v18, a1);
	result = (int)strtok(v18, " \r\t\n");
	v2 = (const char*)result;
	v16 = (char*)result;
	if (!result) {
		return 0;
	}
	result = (int)calloc(1, 96);
	v3 = (uint32_t*)result;
	v17 = result;
	if (!result) {
		return 0;
	}
	if (!strcmp(v2, "MousePickup")) {
		strtok(0, " \r\t\n");
		v4 = strtok(0, " \r\t\n");
		v5 = 0;
		v6 = (const char**)getMemAt(0x587000, 73652);
		while (_strcmpi(v4, *v6)) {
			++v6;
			++v5;
			if ((int)v6 >= (int)getMemAt(0x587000, 73668))
				goto LABEL_9;
		}
		if (v5 < 4)
			goto LABEL_10;
	LABEL_9:
		v5 = 0;
	LABEL_10:
		sub_430AA0(v5);
		free(v3);
		return 1;
	}
	while (*v2 != 61) {
		if (*v2 != 43) {
			unsigned int k = nox_xxx_keybind_keyByName(v16);
			if (k) {
				v10 = v3[8];
				if (v10 == 8) {
					free(v3);
					return 0;
				}
				v3[v10] = k;
				++v3[8];
			}
		}
		v16 = strtok(0, " \r\t\n");
		if (!v16)
			break;
		v2 = v16;
	}
	v3[17] = 0;
	v11 = strtok(0, " \r\t\n");
	if (v11) {
		while (*v11 != 61) {
			if (*v11 != 43) {
				unsigned int k = nox_xxx_bindevent_bindKeyByName(v11);
				if (k) {
					v3 = (uint32_t*)v17;
					v15 = *(uint32_t*)(v17 + 68);
					if (v15 == 8) {
						free(v3);
						return 0;
					}
					*(uint32_t*)(v17 + 4 * v15 + 36) = k;
					++*(uint32_t*)(v17 + 68);
				} else {
					v3 = (uint32_t*)v17;
				}
			}
			v11 = strtok(0, " \r\t\n");
			if (!v11)
				break;
		}
	}
	v3[18] = 0;
	v3[19] = dword_5d4594_754056;
	if (dword_5d4594_754056)
		dword_5d4594_754056->field_18 = v3;
	dword_5d4594_754056 = v3;
	return 1;
}

//----- (0042CDF0) --------------------------------------------------------
void nox_client_writeConfigHotkeys_42CDF0(FILE* a1) {
	int v1;              // eax
	FILE* v2;            // edi
	uint32_t* result;      // eax
	uint32_t* v4;          // ebx
	int v5;              // ebp
	int v8;              // ebp
	uint32_t* v11;         // [esp+Ch] [ebp+4h]
	uint32_t* v12;         // [esp+Ch] [ebp+4h]

	v1 = nox_client_mousePriKey_430AF0();
	v2 = a1;
	nox_fs_fprintf(a1, "MousePickup = %s\n", *getMemU32Ptr(0x587000, 73652 + 4 * v1));
	result = dword_5d4594_754056;
	v4 = dword_5d4594_754056;
	if (dword_5d4594_754056) {
		for (result = dword_5d4594_754056->field_19; result; result = (uint32_t*)result[19])
			v4 = result;
		for (; v4; v4 = (uint32_t*)v4[18]) {
			v5 = 0;
			if (v4[8] > 0) {
				v11 = v4;
				do {
					const char* name = nox_xxx_keybind_nameByKey(*v11);
					if (name) {
						nox_fs_fprintf(v2, "%s ", name);
					}
					if (v5 != v4[8] - 1)
						nox_fs_fprintf(v2, "+ ");
					++v5;
					v11++;
				} while (v5 < v4[8]);
			}
			nox_fs_fprintf(v2, "= ");
			v8 = 0;
			if (v4[17] > 0) {
				v12 = v4 + 9;
				do {
					const char* name = nox_xxx_bindevent_bindNameByKey(*v12);
					if (name) {
						nox_fs_fprintf(v2, "%s ", name);
					}
					if (v8 != v4[17] - 1)
						nox_fs_fprintf(v2, "+ ");
					++v8;
					v12++;
				} while (v8 < v4[17]);
			}
			result = (uint32_t*)nox_fs_fprintf(v2, "\n");
		}
	}
}

//----- (0042CD90) --------------------------------------------------------
void sub_42CD90() {
	uint32_t* result; // eax
	uint32_t* v1;     // esi

	result = dword_5d4594_754056;
	if (result) {
		do {
			v1 = (uint32_t*)result[19];
			free(result);
			result = v1;
		} while (v1);
	}
	dword_5d4594_754056 = 0;
	*getMemU8Ptr(0x5D4594, 747848) = 0;
	*getMemU8Ptr(0x5D4594, 750956) = 0;
	dword_5d4594_754036 = 0;
	dword_5d4594_754040 = 0;
	dword_5d4594_754044 = 0;
	dword_5d4594_754048 = 0;
	*getMemU32Ptr(0x5D4594, 747856) = 100;
	*getMemU32Ptr(0x5D4594, 747868) = 4;
}

//----- (0042CD50) --------------------------------------------------------
char*  nox_xxx_netGetBuffSize_42CD50(uint8_t* a1) {
	*a1 = getMemByte(0x5D4594, 747864);
	return (char*)getMemAt(0x5D4594, 741692);
}

//----- (0042D510) --------------------------------------------------------
void nox_xxx_netBuf_42D510() {
	long long ticks = nox_platform_get_ticks();
	*getMemU32Ptr(0x5D4594, 747864) = 0;
	if (nox_common_gameFlags_check_40A5C0(1)) {
		if (dword_5d4594_754040 != dword_5d4594_754036) {
			for (int i = dword_5d4594_754040; i != dword_5d4594_754036; i = (i + 1) % NOX_CTRLEVENT_XXX_MAX) {
				nox_ctrlevent_xxx_t* p = &nox_ctrlevent_buf_747884[i];
				if (p->tick > ticks + 50) {
					break;
				}
				if (p->active != 1) {
					continue;
				}
				int v5 = *getMemU32Ptr(0x5D4594, 747864);
				*getMemU8Ptr(0x5D4594, 741692 + *getMemU32Ptr(0x5D4594, 747864)) = p->code & 0xff;
				*getMemU32Ptr(0x5D4594, 747864) = v5 + 4;
				if (nox_ctrlevent_has_data_42D440(p->code)) {
					int sz = nox_ctrlevent_data_size_42D450(p->code);
					memcpy(getMemAt(0x5D4594, 741692 + *getMemU32Ptr(0x5D4594, 747864)), &p->data, sz);
					*getMemU32Ptr(0x5D4594, 747864) += sz;
				}
			}
			dword_5d4594_754040 = dword_5d4594_754036;
		}
	} else if (dword_5d4594_754036 > 0) {
		for (int i = 0; i < dword_5d4594_754036; i++) {
			nox_ctrlevent_xxx_t* p = &nox_ctrlevent_buf_747884[i];
			if (p->active != 1) {
				continue;
			}
			int v8 = *getMemU32Ptr(0x5D4594, 747864);
			*getMemU8Ptr(0x5D4594, 741692 + *getMemU32Ptr(0x5D4594, 747864)) = p->code & 0xff;
			*getMemU32Ptr(0x5D4594, 747864) = v8 + 4;
			if (nox_ctrlevent_has_data_42D440(p->code)) {
				int sz = nox_ctrlevent_data_size_42D450(p->code);
				memcpy(getMemAt(0x5D4594, 741692 + *getMemU32Ptr(0x5D4594, 747864)), &p->data, sz);
				*getMemU32Ptr(0x5D4594, 747864) += sz;
			}
		}
	}
}

//----- (0051AAA0) --------------------------------------------------------
int  sub_51AAA0(int a1, int a2, int a3) {
	int v3;             // edi
	int v4;             // ebp
	uint32_t* v5;         // ebx
	int v6;             // ecx
	unsigned char v7; // al
	int v9;             // [esp+8h] [ebp-4h]

	v3 = 0;
	v4 = 0;
	v9 = 0;
	if (a2 <= 0)
		return 0;
	v5 = (uint32_t*)(a3 + 12);
	do {
		v6 = *(unsigned char*)(a1 + v4);
		v4 += 4;
		*(v5 - 1) = v6;
		if (nox_ctrlevent_has_data_42D440(v6)) {
			v7 = nox_ctrlevent_data_size_42D450(*(v5 - 1));
			*v5 = 0;
			memcpy(v5, (const void*)(v4 + a1), v7);
			v4 += v7;
			v3 = v9;
		} else {
			*v5 = 0;
		}
		v5[1] = 1;
		++v3;
		v5 += 6;
		v9 = v3;
	} while (v4 < a2);
	return v3;
}

//----- (0051A960) --------------------------------------------------------
int  nox_xxx_playerSaveInput_51A960(int a1, unsigned char* a2) {
	char* v2;      // eax
	int v3;        // esi
	int v5;        // eax
	int v6;        // edx
	int v7;        // [esp+Ch] [ebp-C04h]
	char v8[3072]; // [esp+10h] [ebp-C00h]

	v2 = nox_common_playerInfoFromNum_417090(a1);
	v3 = *a2;
	v7 = *a2;
	if (v2 && !(v2[3680] & 0x10))
		return v3 + 1;
	v5 = sub_51AAA0((int)(a2 + 1), v3, (int)v8);
	v6 = *getMemU32Ptr(0x5D4594, 2388804 + 4 * a1);
	if (v6 + v5 < 128) {
		*getMemU32Ptr(0x5D4594, 2388804 + 4 * a1) = v6 + v5;
		memcpy(getMemAt(0x5D4594, 2388932 + 24 * (v6 + (a1 << 7))), v8, 24 * v5);
		v3 = v7;
	}
	sub_51AA20(a1);
	return v3 + 1;
}

//----- (0042D460) --------------------------------------------------------
int nox_xxx_keyCheckWarrorKeys_42D460(nox_ctrlevent_code code) {
	switch (code) {
	case CC_SpellGestureLeft:
	case CC_SpellGestureRight:
	case CC_SpellGestureUpperRight:
	case CC_SpellGestureUpperLeft:
	case CC_SpellGestureLowerRight:
	case CC_SpellGestureLowerLeft:
	case CC_SpellPatternEnd:
	case CC_CastQueuedSpell:
	case CC_CastMostRecentSpell:
	case CC_CastSpell1:
	case CC_CastSpell2:
	case CC_SelectSpellSet:
	case CC_BuildTrap:
	case CC_ServerOptions:
	case CC_Taunt:
		return 1;
	default:
		return 0;
	}
}

//----- (0042D4B0) --------------------------------------------------------
int nox_xxx_keyCanPauseMode_42D4B0(nox_ctrlevent_code code) {
	switch (code) {
	case CC_Action:
	case CC_Jump:
	case CC_Chat:
	case CC_TeamChat:
	case CC_ReadSpellbook:
	case CC_ToggleConsole:
	case CC_IncreaseWindowSize:
	case CC_DecreaseWindowSize:
	case CC_Quit:
	case CC_QuitMenu:
	case CC_ReadMap:
	case CC_Inventory:
	case CC_SpellGestureUp:
	case CC_SpellGestureDown:
	case CC_SpellGestureLeft:
	case CC_SpellGestureRight:
	case CC_SpellGestureUpperRight:
	case CC_SpellGestureUpperLeft:
	case CC_SpellGestureLowerRight:
	case CC_SpellGestureLowerLeft:
	case CC_SpellPatternEnd:
	case CC_CastQueuedSpell:
	case CC_CastMostRecentSpell:
	case CC_CastSpell1:
	case CC_CastSpell2:
	case CC_CastSpell3:
	case CC_CastSpell4:
	case CC_CastSpell5:
	case CC_MapZoomIn:
	case CC_MapZoomOut:
	case CC_QuickManaPotion:
	case CC_QuickCurePoisonPotion:
	case CC_NextSpellSet:
	case CC_PreviousSpellSet:
	case CC_SelectSpellSet:
	case CC_BuildTrap:
	case CC_ServerOptions:
	case CC_Taunt:
	case CC_Laugh:
	case CC_Point:
	case CC_InvertSpellTarget:
	case CC_ToggleRank:
	case CC_ToggleGUI:
	case CC_AutoSave:
	case CC_AutoLoad:
	case CC_ScreenShot:
	case CC_Unknown55:
	case CC_Unknown56:
		return 1;
	default:
		return 0;
	}
}
