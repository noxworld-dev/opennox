#ifdef _WIN32
#define _USE_MATH_DEFINES
#endif // _WIN32
#include <math.h>
#include "ctrlevnt.h"

#include "../../proto.h"
#include "../gui/guicon.h"
#include "../gui/guisave.h"
#include "../gui/guispell.h"
#include "../gui/servopts/guiserv.h"

_DWORD dword_5d4594_754060 = 0;
extern _DWORD dword_5d4594_754048;
extern _DWORD dword_5d4594_754044;
extern _DWORD nox_xxx_useAudio_587000_80832;
extern _DWORD dword_5d4594_754040;
extern _DWORD dword_5d4594_754036;
extern _DWORD nox_client_renderGUI_80828;
extern int nox_win_width;
extern int nox_win_height;
extern unsigned int nox_gameFPS;

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
				nox_xxx_loadString_40F1D0(*((char**)v0 - 1), 0, "C:\\NoxPost\\src\\Client\\System\\Ctrlevnt.c", 2092);
			v1 = *((_DWORD*)v0 + 1);
			v0 += 16;
		} while (v1);
	}
	*getMemU32Ptr(0x587000, 75888) =
		nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 80484), 0, "C:\\NoxPost\\src\\Client\\System\\Ctrlevnt.c", 2095);
	result = *(char**)getMemAt(0x587000, 75892);
	if (*getMemU32Ptr(0x587000, 75892)) {
		v3 = getMemAt(0x587000, 75892);
		do {
			nox_sprintf(v4, "bindevent:%s", result);
			*((_DWORD*)v3 + 2) = nox_xxx_loadString_40F1D0(v4, 0, "C:\\NoxPost\\src\\Client\\System\\Ctrlevnt.c", 2100);
			result = (char*)*((_DWORD*)v3 + 3);
			v3 += 12;
		} while (result);
	}
	return result;
}

//----- (0042D6B0) --------------------------------------------------------
void nox_xxx_clientControl_42D6B0(nox_mouse_state_t* mouse, int a4) {
	int v2;               // ebp
	int i;                // edi
	int j;                // esi
	int v5;               // eax
	int v6;               // eax
	int v7;               // eax
	int v8;               // eax
	int v9;               // eax
	int v10;              // eax
	int v11;              // eax
	int v12;              // eax
	int v13;              // eax
	int v14;              // eax
	int v19;              // eax
	int v20;              // ebp
	int v21;              // ebx
	unsigned __int8* v22; // edx
	int v23;              // edx
	int k;                // edi
	int v25;              // ecx
	unsigned __int8* v26; // eax
	int v27;              // ebp
	int v28;              // ebx
	int v29;              // edx
	unsigned __int8* v30; // esi
	int v31;              // eax
	unsigned __int8* v32; // ecx
	int v34;              // ecx
	int l;                // ebp
	int v36;              // esi
	int v37;              // eax
	int v38;              // eax
	int v39;              // eax
	wchar_t* v40;         // eax
	wchar_t* v41;         // [esp-20h] [ebp-28h]
	char v42[2];          // [esp+2h] [ebp-6h]
	int v43;              // [esp+4h] [ebp-4h]

	*getMemU64Ptr(0x5D4594, 747876) = nox_call_get_ticks();
	if (nox_common_gameFlags_check_40A5C0(1) && nox_common_gameFlags_check_40A5C0(0x2000)) {
		*getMemU64Ptr(0x5D4594, 747876) += sub_42E630();
	}
	v2 = *getMemU32Ptr(0x5D4594, 2618908);
	if (!nox_common_gameFlags_check_40A5C0(1)) {
		dword_5d4594_754036 = 0;
	}
	for (i = a4; i; i = *(_DWORD*)(i + 84)) {
		for (j = 0; j < *(int*)(i + 68); ++j) {
			switch (*(_DWORD*)(i + 4 * j + 36)) {
			case 1:
				v9 = nox_client_getCursorType_477620();
				switch (v9) {
				case 3:
					v10 = nox_xxx_clientGetSpriteAtCursor_476F90();
					nox_xxx_clientTrade_42E850(v10);
					break;
				case 4:
					v11 = nox_xxx_clientGetSpriteAtCursor_476F90();
					if (*(_BYTE*)(v11 + 280) & 0x10) {
						nox_xxx_clientTalk_42E7B0(v11);
					}
					break;
				case 13:
					v12 = nox_xxx_clientGetSpriteAtCursor_476F90();
					nox_xxx_clientCollideOrUse_42E810(v12);
					break;
				default:
					nox_xxx_keys_42E670(6, 0);
					break;
				}
				break;
			case 2:
				if (nox_SDL_GetEventState(SDL_MOUSEBUTTONDOWN)) {
					v5 = 1;
					if (getMemByte(0x5D4594, 754064) & 8) {
						v5 = 3;
					}
					nox_xxx_keys_42E670(2, v5);
				}
				break;
			case 3:
				v6 = (getMemByte(0x5D4594, 754064) & 1) != 0;
				if (getMemByte(0x5D4594, 754064) & 8) {
					LOBYTE(v6) = v6 | 2;
				}
				nox_xxx_keys_42E670(3, v6);
				break;
			case 4:
				v7 = (getMemByte(0x5D4594, 754064) & 1) != 0;
				if (getMemByte(0x5D4594, 754064) & 8) {
					LOBYTE(v7) = v7 | 2;
				}
				nox_xxx_keys_42E670(4, v7);
				break;
			case 5:
				v8 = (getMemByte(0x5D4594, 754064) & 1) != 0;
				if (getMemByte(0x5D4594, 754064) & 8) {
					LOBYTE(v8) = v8 | 2;
				}
				nox_xxx_keys_42E670(5, v8);
				break;
			case 6:
				nox_xxx_keys_42E670(7, 0);
				break;
			case 7:
				nox_xxx_keys_42E670(19, 0);
				break;
			case 8:
				nox_xxx_keys_42E670(8, 0);
				break;
			case 9:
				if (!(*(_BYTE*)(v2 + 3680) & 1)) {
					nox_xxx_keys_42E670(9, 0);
				}
				break;
			case 0xA:
				nox_xxx_keys_42E670(10, 0);
				break;
			case 0xB:
				nox_xxx_keys_42E670(11, 0);
				break;
			case 0xC:
				if (!nox_xxx_checkGFlagNoParticles_413A50()) {
					nox_xxx_keys_42E670(12, 0);
				}
				break;
			case 0xD:
				if (!nox_xxx_checkGFlagNoParticles_413A50()) {
					nox_xxx_keys_42E670(13, 0);
				}
				break;
			case 0xE:
				nox_xxx_keys_42E670(14, 0);
				break;
			case 0xF:
				nox_xxx_keys_42E670(15, 0);
				break;
			case 0x10:
				nox_xxx_keys_42E670(18, 0);
				break;
			case 0x11:
				if (!nox_xxx_guiSpellTest_45D9C0()) {
					v13 = nox_xxx_packetGetMarshall_476F40();
					nox_xxx_keys_42E780(29, v13);
				}
				break;
			case 0x12:
				if (!nox_xxx_guiSpellTest_45D9C0()) {
					nox_xxx_keys_42E780(20, 0);
				}
				break;
			case 0x13:
				if (!nox_xxx_guiSpellTest_45D9C0()) {
					nox_xxx_keys_42E780(21, 0);
				}
				break;
			case 0x14:
				if (!nox_xxx_guiSpellTest_45D9C0()) {
					nox_xxx_keys_42E780(22, 0);
				}
				break;
			case 0x15:
				if (!nox_xxx_guiSpellTest_45D9C0()) {
					nox_xxx_keys_42E780(23, 0);
				}
				break;
			case 0x16:
				if (!nox_xxx_guiSpellTest_45D9C0()) {
					nox_xxx_keys_42E780(24, 0);
				}
				break;
			case 0x17:
				if (!nox_xxx_guiSpellTest_45D9C0()) {
					nox_xxx_keys_42E780(25, 0);
				}
				break;
			case 0x18:
				if (!nox_xxx_guiSpellTest_45D9C0()) {
					nox_xxx_keys_42E780(26, 0);
				}
				break;
			case 0x19:
				if (!nox_xxx_guiSpellTest_45D9C0()) {
					nox_xxx_keys_42E780(27, 0);
				}
				break;
			case 0x1A:
				if (!nox_xxx_guiSpellTest_45D9C0()) {
					nox_xxx_keys_42E780(28, 0);
				}
				break;
			case 0x1B:
				if (!nox_xxx_guiSpellTest_45D9C0()) {
					v14 = nox_xxx_packetGetMarshall_476F40();
					nox_xxx_keys_42E780(30, v14);
				}
				break;
			case 0x1C:
				nox_xxx_keys_42E780(31, 0);
				break;
			case 0x1D:
				nox_xxx_keys_42E780(32, 0);
				break;
			case 0x1E:
				nox_xxx_keys_42E780(33, 0);
				break;
			case 0x1F:
				nox_xxx_keys_42E780(34, 0);
				break;
			case 0x20:
				nox_xxx_keys_42E780(35, 0);
				break;
			case 0x21:
				nox_xxx_keys_42E670(36, 0);
				break;
			case 0x22:
				nox_xxx_keys_42E670(37, 0);
				break;
			case 0x23:
				nox_xxx_keys_42E780(38, 0);
				break;
			case 0x24:
				nox_xxx_keys_42E780(39, 0);
				break;
			case 0x25:
				nox_xxx_keys_42E780(40, 0);
				break;
			case 0x26:
				nox_xxx_keys_42E780(41, 0);
				break;
			case 0x27:
				nox_xxx_keys_42E780(42, 0);
				break;
			case 0x28:
				nox_xxx_keys_42E780(43, 0);
				break;
			case 0x29:
				nox_xxx_keys_42E780(44, 0);
				break;
			case 0x2A:
				nox_xxx_keys_42E780(45, 0);
				break;
			case 0x2B:
				nox_xxx_keys_42E670(16, 0);
				break;
			case 0x2C:
				nox_xxx_keys_42E670(17, 0);
				break;
			case 0x2D:
				nox_xxx_keys_42E670(46, 0);
				break;
			case 0x2E:
				if (nox_common_gameFlags_check_40A5C0(0x2000) &&
					nox_xxx_checkKeybTimeout_4160F0(0x15u, nox_gameFPS)) {
					nox_xxx_setKeybTimeout_4160D0(21);
					nox_xxx_keys_42E670(47, 0);
				}
				break;
			case 0x2F:
				if (nox_common_gameFlags_check_40A5C0(0x2000) &&
					nox_xxx_checkKeybTimeout_4160F0(0x14u, 2 * nox_gameFPS)) {
					nox_xxx_setKeybTimeout_4160D0(20);
					nox_xxx_keys_42E670(48, 0);
				}
				break;
			case 0x30:
				if (nox_common_gameFlags_check_40A5C0(0x2000) &&
					nox_xxx_checkKeybTimeout_4160F0(0x16u, nox_gameFPS)) {
					nox_xxx_setKeybTimeout_4160D0(22);
					nox_xxx_keys_42E670(49, 0);
				}
				break;
			case 0x31:
				nox_xxx_keys_42E670(50, 0);
				break;
			case 0x32:
				if (nox_common_gameFlags_check_40A5C0(0x2000)) {
					nox_xxx_keys_42E670(51, 0);
				}
				break;
			case 0x33:
				if (!nox_xxx_checkGFlagNoParticles_413A50()) {
					nox_xxx_keys_42E670(52, 0);
				}
				break;
			case 0x34:
				nox_xxx_keys_42E670(53, 0);
				break;
			case 0x35:
				if (nox_common_gameFlags_check_40A5C0(2048) && !nox_xxx_guiCursor_477600()) {
					nox_xxx_keys_42E670(54, 0);
				}
				break;
			case 0x36:
				if (nox_common_gameFlags_check_40A5C0(2048) && !nox_xxx_guiCursor_477600()) {
					nox_xxx_keys_42E670(55, 0);
				}
				break;
			case 0x37:
				nox_xxx_keys_42E670(56, 0);
				break;
			default:
				break;
			}
		}
	}
#ifdef __EMSCRIPTEN__
	if (!nox_SDL_GetEventState(SDL_MOUSEBUTTONDOWN)) {
		nox_xxx_clientControl_42D6B0_em_not_mouse_down();
	} else
#endif
	{
		if (getMemByte(0x5D4594, 747848) != 2 && *getMemU32Ptr(0x5D4594, 747868) == 4) {
			// calculates player view direction?
			void* v15 = nox_xxx_spriteGetMB_476F80();
			int x = mouse->pos.x;
			int y = mouse->pos.y;
			if (v15) {
				y = sub_4739D0(*(_DWORD *) ((_DWORD)v15 + 16));
			}
			int cx = x - nox_win_width / 2;
			int cy = y - nox_win_height / 2;
			double rad = atan2(cy, cx);
			// represent as integer
			int ang = (int)((rad + 2 * M_PI) * 128.0/M_PI + 0.5);
			if (ang < 0) {
				ang += ((unsigned int)(255 - ang) >> 8) << 8;
			}
			if (ang >= 256) {
				ang -= ((unsigned int)ang >> 8) << 8;
			}
			dword_5d4594_754060 = ang;
			nox_xxx_keys_42E670(1, ang);
		}
		nox_xxx_keys_42E670(1, dword_5d4594_754060);
	}
	if (getMemByte(0x5D4594, 2661958)) {
		nox_xxx_guiSpellTargetClickCheckSend_45DBB0();
	}
	if (getMemByte(0x5D4594, 754064) & 4) {
		nox_xxx_keys_42E670(28, 0);
	}
	if (nox_common_gameFlags_check_40A5C0(1)) {
		v19 = dword_5d4594_754048;
		v20 = dword_5d4594_754040;
		v21 = 0;
		if (dword_5d4594_754048 == dword_5d4594_754040) {
			v23 = dword_5d4594_754044;
		} else {
			v22 = getMemAt(0x5D4594, 750964);
			do {
				memcpy(v22, getMemAt(0x5D4594, 747884 + 24*v19), sizeof(nox_ctrlevent_xxx_t));
				v19 = (v19 + 1) % NOX_CTRLEVENT_XXX_MAX;
				++v21;
				v22 += sizeof(nox_ctrlevent_xxx_t);
			} while (v19 != v20);
			if (v21 <= 0) {
				v23 = dword_5d4594_754044;
			} else {
				v23 = v21;
				dword_5d4594_754048 = v20;
				dword_5d4594_754044 = v21;
			}
		}
		for (k = v20; k != dword_5d4594_754036; k = (k + 1) % 128) {
			v25 = 0;
			if (v23 <= 0) {
				continue;
			}
			v26 = getMemAt(0x5D4594, 750972);
			while (*getMemU32Ptr(0x5D4594, 747884 + 24*k + 8) != *(_DWORD*)v26) {
				++v25;
				v26 += sizeof(nox_ctrlevent_xxx_t);
				if (v25 >= v23) {
					goto LABEL_137;
				}
			}
			if (nox_xxx_keyCanPauseMode_42D4B0(*getMemU32Ptr(0x5D4594, 747884 + 24*k + 8))) {
				*getMemU32Ptr(0x5D4594, 747884 + 24*k + 16) = 0;
			}
			v23 = dword_5d4594_754044;
		LABEL_137:;
		}
	} else {
		v27 = dword_5d4594_754036;
		v28 = 0;
		if (dword_5d4594_754036 > 0) {
			v29 = dword_5d4594_754044;
			v30 = getMemAt(0x5D4594, 747884 + 16);
			do {
				v31 = 0;
				*(_DWORD*)v30 = 1;
				if (v29 > 0) {
					v32 = getMemAt(0x5D4594, 750972);
					while (*((_DWORD*)v30 - 2) != *(_DWORD*)v32) {
						++v31;
						v32 += 24;
						if (v31 >= v29)
							goto LABEL_149;
					}
					if (nox_xxx_keyCanPauseMode_42D4B0(*((_DWORD*)v30 - 2)))
						*(_DWORD*)v30 = 0;
					v27 = dword_5d4594_754036;
					v29 = dword_5d4594_754044;
				}
			LABEL_149:
				++v28;
				v30 += sizeof(nox_ctrlevent_xxx_t);
			} while (v28 < v27);
			if (v27 > 0) {
				memcpy(getMemAt(0x5D4594, 750964), getMemAt(0x5D4594, 747884), 4 * ((unsigned int) (24 * v27) >> 2));
			}
		}
		dword_5d4594_754044 = v27;
	}
	*getMemU32Ptr(0x5D4594, 754064) = 0;
	int l0 = 0;
	if (nox_common_gameFlags_check_40A5C0(1)) {
		l0 = dword_5d4594_754040;
		v34 = dword_5d4594_754036;
		if (dword_5d4594_754036 < *(int*)&dword_5d4594_754040) {
			v34 = dword_5d4594_754036 + 128;
		}
	} else {
		v34 = dword_5d4594_754036;
	}
	v43 = v34;
	for (l = l0; l < v43; ++l) {
		v36 = 24 * (l % NOX_CTRLEVENT_XXX_MAX);
		if (!(*getMemU32Ptr(0x5D4594, 747884 + v36 + 16))) {
			continue;
		}
		switch (*getMemU32Ptr(0x5D4594, 747884 + v36 + 8)) {
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
		v37 = *getMemU32Ptr(0x5D4594, 747884 + 8 + v36);
		int tmp = 0;
		switch (v37) {
			case 8:
				sub_46A430(0);
				*getMemU32Ptr(0x5D4594, 747884 + 16 + v36) = 0;
				break;
			case 9:
				sub_46A430(1);
				*getMemU32Ptr(0x5D4594, 747884 + 16 + v36) = 0;
				break;
			case 10:
				sub_45AC70();
				*getMemU32Ptr(0x5D4594, 747884 + 16 + v36) = 0;
				break;
			case 11:
				nox_xxx_consoleF1_451350();
				*getMemU32Ptr(0x5D4594, 747884 + 16 + v36) = 0;
				break;
			case 12:
				nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
				sub_4766E0();
				*getMemU32Ptr(0x5D4594, 747884 + 16 + v36) = 0;
				break;
			case 13:
				nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
				sub_4766F0();
				*getMemU32Ptr(0x5D4594, 747884 + 16 + v36) = 0;
				break;
			case 14:
				nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
				v38 = nox_video_getGammaSetting_434B00();
				nox_video_setGammaSetting_434B30(v38 + 1);
				updateGamma(1);
				sub_434B60();
				*getMemU32Ptr(0x5D4594, 747884 + 16 + v36) = 0;
				break;
			case 15:
				nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
				v39 = nox_video_getGammaSetting_434B00();
				nox_video_setGammaSetting_434B30(v39 - 1);
				updateGamma(-1);
				sub_434B60();
				*getMemU32Ptr(0x5D4594, 747884 + 16 + v36) = 0;
				break;
			case 16:
				sub_4460C0();
				*getMemU32Ptr(0x5D4594, 747884 + 16 + v36) = 0;
				break;
			case 17:
				if (sub_450560()) {
					nox_savegame_sub_46D580();
				} else {
					sub_42EB90(1);
				}
				*getMemU32Ptr(0x5D4594, 747884 + 16 + v36) = 0;
				break;
			case 18:
				sub_473610();
				*getMemU32Ptr(0x5D4594, 747884 + 16 + v36) = 0;
				break;
			case 19:
				sub_467C60();
				*getMemU32Ptr(0x5D4594, 747884 + 16 + v36) = 0;
				break;
			case 31:
			case 32:
			case 33:
			case 34:
			case 35:
				nox_xxx_clientUseQWEButton_45DA50(v37 - 31);
				*getMemU32Ptr(0x5D4594, 747884 + 16 + v36) = 0;
				break;
			case 36:
				sub_4724E0();
				*getMemU32Ptr(0x5D4594, 747884 + 16 + v36) = 0;
				break;
			case 37:
				sub_472500();
				*getMemU32Ptr(0x5D4594, 747884 + 16 + v36) = 0;
				break;
			case 38:
				nox_client_invAlterWeapon_4672C0();
				*getMemU32Ptr(0x5D4594, 747884 + 16 + v36) = 0;
				break;
			case 39:
				sub_472220();
				*getMemU32Ptr(0x5D4594, 747884 + 16 + v36) = 0;
				break;
			case 40:
				sub_472240();
				*getMemU32Ptr(0x5D4594, 747884 + 16 + v36) = 0;
				break;
			case 41:
				sub_472260();
				*getMemU32Ptr(0x5D4594, 747884 + 16 + v36) = 0;
				break;
			case 42:
				nox_xxx_spellNext_4604F0();
				*getMemU32Ptr(0x5D4594, 747884 + 16 + v36) = 0;
				break;
			case 43:
				nox_xxx_spellPrev_460540();
				*getMemU32Ptr(0x5D4594, 747884 + 16 + v36) = 0;
				break;
			case 44:
				nox_xxx_spellReset_460590();
				*getMemU32Ptr(0x5D4594, 747884 + 16 + v36) = 0;
				break;
			case 45:
				nox_xxx_clientUseTrap_45E040();
				*getMemU32Ptr(0x5D4594, 747884 + 16 + v36) = 0;
				break;
			case 46:
				if (!(nox_common_gameFlags_check_40A5C0(8) || !nox_common_gameFlags_check_40A5C0(0x2000))) {
					nox_xxx_guiServerOptsLoad_457500();
				}
				*getMemU32Ptr(0x5D4594, 747884 + 16 + v36) = 0;
				break;
			case 47:
				tmp = 739;
				nox_xxx_netClientSend2_4E53C0(31, &tmp, 2, 0, 1);
				break;
			case 48:
				tmp = 483;
				nox_xxx_netClientSend2_4E53C0(31, &tmp, 2, 0, 1);
				break;
			case 49:
				v42[0] = -29;
				v42[1] = 4;
				nox_xxx_netClientSend2_4E53C0(31, v42, 2, 0, 1);
				break;
			case 50:
				sub_460630();
				*getMemU32Ptr(0x5D4594, 747884 + 16 + v36) = 0;
				break;
			case 51:
				nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
				sub_4703F0();
				*getMemU32Ptr(0x5D4594, 747884 + 16 + v36) = 0;
				break;
			case 52:
				sub_470A60();
				nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
				*getMemU32Ptr(0x5D4594, 747884 + 16 + v36) = 0;
				break;
			case 53:
				if (!nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING)) {
					nox_client_renderGUI_80828 ^= 1u;
					nox_xxx_useAudio_587000_80832 = nox_client_renderGUI_80828;
					nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
				}
				*getMemU32Ptr(0x5D4594, 747884 + 16 + v36) = 0;
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
				*getMemU32Ptr(0x5D4594, 747884 + 16 + v36) = 0;
				break;
			case 55:
				if (nox_common_gameFlags_check_40A5C0(2048)) {
					if (nox_xxx_game_4DCCB0()) {
						nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
						sub_413A00(1);
						v41 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 80304), 0,
													"C:\\NoxPost\\src\\Client\\System\\Ctrlevnt.c", 1867);
						v40 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 80372), 0,
													"C:\\NoxPost\\src\\Client\\System\\Ctrlevnt.c", 1866);
						nox_xxx_dialogMsgBoxCreate_449A10(0, (int)v40, (int)v41, 56, sub_42E600, sub_42E620);
					} else {
						nox_xxx_clientPlaySoundSpecial_452D80(231, 100);
					}
				}
				*getMemU32Ptr(0x5D4594, 747884 + 16 + v36) = 0;
				break;
			case 56:
				sub_46DB00();
				*getMemU32Ptr(0x5D4594, 747884 + 16 + v36) = 0;
				break;
			default:
				break;
		}
	}
}
