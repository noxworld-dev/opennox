#ifdef _WIN32
#define _USE_MATH_DEFINES
#endif // _WIN32
#include <math.h>
#include "client__system__ctrlevnt.h"

#include "proto.h"
#include "input.h"
#include "client__gui__guicon.h"
#include "client__gui__guisave.h"
#include "client__gui__guispell.h"
#include "client__gui__servopts__guiserv.h"

_DWORD nox_ctrlevent_player_orientation = 0;
extern _DWORD dword_5d4594_754048;
extern _DWORD dword_5d4594_754044;
extern _DWORD nox_xxx_useAudio_587000_80832;
extern _DWORD dword_5d4594_754040;
extern _DWORD dword_5d4594_754036;
extern _DWORD nox_client_renderGUI_80828;
extern int nox_win_width;
extern int nox_win_height;
extern unsigned int nox_gameFPS;

__int64 nox_ctrlevent_ticks = 0;

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
unsigned __int8 nox_ctrlevent_data_size_42D450(nox_ctrlevent_code code) {
	return nox_ctrlevent_code_infos[code].data_size;
}

//----- (0042E630) --------------------------------------------------------
int nox_ctrlevent_add_ticks_42E630() {
	char* v0 = (char*)sub_416640();
	switch (*(_DWORD*)(v0 + 66)) {
	case 1:
		return sub_554290();
	case 2:
		return sub_554300();
	case 3:
		return *(_DWORD*)(v0 + 70);
	default:
		return 0;
	}
}
// 42E644: control flows out of bounds to 554290
// 42E649: control flows out of bounds to 554300

//----- (0042EAE0) --------------------------------------------------------
char* nox_xxx_bindevent_42EAE0() {
	unsigned __int8* v0; // esi
	int v1;              // eax
	char* result;        // eax
	unsigned __int8* v3; // esi
	char v4[256];        // [esp+4h] [ebp-100h]

	if (*getMemU32Ptr(0x587000, 73672)) {
		v0 = getMemAt(0x587000, 73684);
		do {
			*(_DWORD*)v0 =
				nox_strman_loadString_40F1D0(*((char**)v0 - 1), 0, "C:\\NoxPost\\src\\Client\\System\\Ctrlevnt.c", 2092);
			v1 = *((_DWORD*)v0 + 1);
			v0 += 16;
		} while (v1);
	}
	*getMemU32Ptr(0x587000, 75888) =
		nox_strman_loadString_40F1D0("bindevent:NullEvent", 0, "C:\\NoxPost\\src\\Client\\System\\Ctrlevnt.c", 2095);
	result = *(char**)getMemAt(0x587000, 75892);
	if (*getMemU32Ptr(0x587000, 75892)) {
		v3 = getMemAt(0x587000, 75892);
		do {
			nox_sprintf(v4, "bindevent:%s", result);
			*((_DWORD*)v3 + 2) = nox_strman_loadString_40F1D0(v4, 0, "C:\\NoxPost\\src\\Client\\System\\Ctrlevnt.c", 2100);
			result = (char*)*((_DWORD*)v3 + 3);
			v3 += 12;
		} while (result);
	}
	return result;
}

//----- (0042D6B0) --------------------------------------------------------
void nox_xxx_clientControl_42D6B0_orientation(nox_mouse_state_t* mouse) {
	if (getMemByte(0x5D4594, 747848) != 2 && *getMemU32Ptr(0x5D4594, 747868) == 4) {
		// calculates player orientation
		void* v15 = nox_xxx_spriteGetMB_476F80();
		int x = mouse->pos.x;
		int y = mouse->pos.y;
		if (v15) {
			y = sub_4739D0(*(_DWORD *) ((_DWORD)v15 + 16));
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
	int v2 = *getMemU32Ptr(0x5D4594, 2618908);
	for (int i = a4; i; i = *(_DWORD*)(i + 84)) {
		for (int j = 0; j < *(int*)(i + 68); ++j) {
			switch (*(_DWORD*)(i + 4 * j + 36)) {
				case 1:;
					int v9 = nox_client_getCursorType_477620();
					switch (v9) {
						case 3:;
							int v10 = nox_xxx_clientGetSpriteAtCursor_476F90();
							nox_xxx_clientTrade_42E850(v10);
							break;
						case 4:;
							int v11 = nox_xxx_clientGetSpriteAtCursor_476F90();
							if (*(_BYTE*)(v11 + 280) & 0x10) {
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
					if (!(*(_BYTE*)(v2 + 3680) & 1)) {
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
					if (!nox_xxx_checkGFlagNoParticles_413A50()) {
						nox_ctrlevent_action_42E670(CC_IncreaseWindowSize, 0);
					}
					break;
				case 0xD:
					if (!nox_xxx_checkGFlagNoParticles_413A50()) {
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
					if (!nox_xxx_checkGFlagNoParticles_413A50()) {
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
					sub_476E00(1);
				}
				break;
			case 0x15:
				if (!nox_common_gameFlags_check_40A5C0(128)) {
					nox_xxx_clientPlaySoundSpecial_452D80(190, 100);
					sub_476E00(6);
				}
				break;
			case 0x16:
				if (!nox_common_gameFlags_check_40A5C0(128)) {
					nox_xxx_clientPlaySoundSpecial_452D80(192, 100);
					sub_476E00(3);
				}
				break;
			case 0x17:
				if (!nox_common_gameFlags_check_40A5C0(128)) {
					nox_xxx_clientPlaySoundSpecial_452D80(188, 100);
					sub_476E00(4);
				}
				break;
			case 0x18:
				if (!nox_common_gameFlags_check_40A5C0(128)) {
					nox_xxx_clientPlaySoundSpecial_452D80(187, 100);
					sub_476E00(2);
				}
				break;
			case 0x19:
				if (!nox_common_gameFlags_check_40A5C0(128)) {
					nox_xxx_clientPlaySoundSpecial_452D80(193, 100);
					sub_476E00(0);
				}
				break;
			case 0x1A:
				if (!nox_common_gameFlags_check_40A5C0(128)) {
					nox_xxx_clientPlaySoundSpecial_452D80(189, 100);
					sub_476E00(7);
				}
				break;
			case 0x1B:
				if (!nox_common_gameFlags_check_40A5C0(128)) {
					nox_xxx_clientPlaySoundSpecial_452D80(191, 100);
					sub_476E00(5);
				}
				break;
			default:
				break;
		}
		int v37 = nox_ctrlevent_buf_747884[li].code;
		int tmp = 0;
		switch (v37) {
			case 8:
				sub_46A430(0);
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 9:
				sub_46A430(1);
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 10:
				sub_45AC70();
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 11:
				nox_xxx_consoleF1_451350();
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 12:
				nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
				sub_4766E0();
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 13:
				nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
				sub_4766F0();
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
				nox_xxx_quit_4460C0();
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
				sub_473610();
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 19:
				sub_467C60();
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 31:
			case 32:
			case 33:
			case 34:
			case 35:
				nox_xxx_clientUseQWEButton_45DA50(v37 - 31);
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 36:
				sub_4724E0();
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 37:
				sub_472500();
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 38:
				nox_client_invAlterWeapon_4672C0();
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 39:
				sub_472220();
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 40:
				sub_472240();
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 41:
				sub_472260();
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 42:
				nox_xxx_spellNext_4604F0();
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 43:
				nox_xxx_spellPrev_460540();
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 44:
				nox_xxx_spellReset_460590();
				nox_ctrlevent_buf_747884[li].active = 0;
				break;
			case 45:
				nox_xxx_clientUseTrap_45E040();
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
					nox_xxx_useAudio_587000_80832 = nox_client_renderGUI_80828;
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
	if (getMemByte(0x5D4594, 2661958)) {
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
void nox_ctrlevent_action_42E670(nox_ctrlevent_code code, _DWORD data) {
	if (!nox_common_gameFlags_check_40A5C0(1)) {
		if (dword_5d4594_754036 >= NOX_CTRLEVENT_XXX_MAX) {
			return;
		}
	} else {
		if (dword_5d4594_754036 + 1 == dword_5d4594_754040) {
			return;
		}
	}
	if (getMemByte(0x5D4594, 2661958) || (nox_xxx_keyCheckWarrorKeys_42D460(code) == 0)) {
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
void nox_ctrlevent_action_42E780(nox_ctrlevent_code code, _DWORD data) {
	if (*getMemU32Ptr(0x5D4594, 2614252) && !(*(_BYTE*)(*getMemU32Ptr(0x5D4594, 2614252) + 120) & 2)) {
		if (!nox_xxx_checkGFlagNoParticles_413A50()) {
			nox_ctrlevent_action_42E670(code, data);
		}
	}
}
