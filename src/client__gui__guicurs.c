//+build none

#include "client__gui__guicurs.h"

#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME2_2.h"
#include "GAME2_3.h"
#include "GAME3_1.h"
#include "GAME4_1.h"
#include "input_common.h"

extern int dword_5d4594_1097212;
extern int dword_5d4594_1097216;
extern _DWORD nox_xxx_cursorTypePrev_587000_151528;
extern _DWORD dword_5d4594_1097208;
extern _DWORD dword_5d4594_3798728;
extern int nox_win_width;
extern int nox_win_height;
extern unsigned int nox_frame_xxx_2598000;
extern int nox_client_mouseCursorType;

//----- (00477A30) --------------------------------------------------------
void nox_video_cursorDrawImpl_477A30(int a1, int a2, int a3) {
	int v3;       // edi
	int v4;       // ebp
	int v5;       // esi
	int v6;       // eax
	__int16* v7;  // eax
	__int16* v8;  // eax
	__int16* v9;  // eax
	__int16* v10; // eax
	__int16* v11; // eax
	__int16* v12; // eax
	__int16* v13; // eax
	int v15;      // esi
	int v16;      // ebx
	int v18;      // [esp+10h] [ebp-Ch]
	float2 v19;   // [esp+14h] [ebp-8h]

	v18 = *getMemU32Ptr(0x973F18, 68);
	v3 = a2 - 64;
	v4 = a3 - 64;
	*getMemU32Ptr(0x973F18, 68) = 0;
	dword_5d4594_3798728 = 1;
	dword_5d4594_1097212 = a2 - 64;
	dword_5d4594_1097216 = a3 - 64;
	if ((unsigned char)nox_frame_xxx_2598000 & 1)
		++*getMemU32Ptr(0x5D4594, 1097288);
	nox_xxx_drawSetTextColor_434390(*getMemIntPtr(0x5D4594, 2589772));
	v5 = nox_xxx_guiFontHeightMB_43F320(0);
	if (nox_xxx_guiSpell_460650() || sub_4611A0()) {
		LOWORD(result) = nox_video_drawAnimatedImageOrCursorAt_4BE6D0(*getMemIntPtr(0x5D4594, 1097240), v3, v4);
		dword_5d4594_3798728 = 0;
		nox_xxx_cursorTypePrev_587000_151528 = 5;
		*getMemU32Ptr(0x973F18, 68) = v18;
	} else {
		v6 = nox_client_mouseCursorType;
		if (nox_client_mouseCursorType != nox_xxx_cursorTypePrev_587000_151528 && nox_client_mouseCursorType != 14) {
			sub_48B680(0);
			v6 = nox_client_mouseCursorType;
		}
		switch (v6) {
		case 1:
			v10 = (__int16*)nox_strman_loadString_40F1D0("GRAB", 0,
												  "C:\\NoxPost\\src\\Client\\Gui\\guicurs.c", 199);
			nox_xxx_drawString_43F6E0(0, v10, v3 + 54, a3 - v5);
			nox_video_drawAnimatedImageOrCursorAt_4BE6D0(*getMemIntPtr(0x5D4594, 1097224), v3, v4);
			break;
		case 2:
			v7 = (__int16*)nox_strman_loadString_40F1D0("PICKUP", 0,
												 "C:\\NoxPost\\src\\Client\\Gui\\guicurs.c", 176);
			nox_xxx_drawString_43F6E0(0, v7, v3 + 49, v5 + a3);
			nox_video_drawAnimatedImageOrCursorAt_4BE6D0(*getMemIntPtr(0x5D4594, 1097228), v3, v4);
			goto LABEL_16;
		case 3:
			v8 = (__int16*)nox_strman_loadString_40F1D0("SHOPKEEPER", 0,
												 "C:\\NoxPost\\src\\Client\\Gui\\guicurs.c", 185);
			nox_xxx_drawString_43F6E0(0, v8, v3 + 39, a3 - v5);
			nox_video_drawAnimatedImageOrCursorAt_4BE6D0(*getMemIntPtr(0x5D4594, 1097232), v3, v4);
			break;
		case 4:
			v9 = (__int16*)nox_strman_loadString_40F1D0("TALK", 0,
												 "C:\\NoxPost\\src\\Client\\Gui\\guicurs.c", 192);
			nox_xxx_drawString_43F6E0(0, v9, v3 + 49, a3 - v5);
			nox_video_drawAnimatedImageOrCursorAt_4BE6D0(*getMemIntPtr(0x5D4594, 1097236), v3, v4);
			break;
		case 6:
		case 7:
			v11 = (__int16*)nox_strman_loadString_40F1D0("IDENTIFY", 0,
												  "C:\\NoxPost\\src\\Client\\Gui\\guicurs.c", 207);
			nox_xxx_drawString_43F6E0(0, v11, v3 + 49, v4 + 88);
			nox_video_drawAnimatedImageOrCursorAt_4BE6D0(
				*getMemU32Ptr(0x5D4594, 1097220 + 4 * nox_client_mouseCursorType), v3, v4);
			break;
		case 8:
			v12 = (__int16*)nox_strman_loadString_40F1D0("REPAIR", 0,
												  "C:\\NoxPost\\src\\Client\\Gui\\guicurs.c", 214);
			nox_xxx_drawString_43F6E0(0, v12, v3 + 49, a3 - v5);
			nox_video_drawAnimatedImageOrCursorAt_4BE6D0(*getMemIntPtr(0x5D4594, 1097252), v3, v4);
			dword_5d4594_1097208 = 2 * v5 + 4;
			break;
		case 9:
		case 10:
		case 11:
		case 12:
			nox_video_drawAnimatedImageOrCursorAt_4BE6D0(*getMemU32Ptr(0x5D4594, 1097220 + 4 * v6), v3, v4);
			break;
		case 13:
			v13 = (__int16*)nox_strman_loadString_40F1D0("USE", 0,
												  "C:\\NoxPost\\src\\Client\\Gui\\guicurs.c", 223);
			nox_xxx_drawString_43F6E0(0, v13, v3 + 54, v5 + a3);
			nox_video_drawAnimatedImageOrCursorAt_4BE6D0(*getMemIntPtr(0x5D4594, 1097272), v3, v4);
		LABEL_16:
			dword_5d4594_1097208 = -2 * v5;
			break;
		case 14:;
			nox_point mpos = nox_client_getMousePos_4309F0();
			v19.field_0 = (double)(mpos.x - nox_win_width / 2);
			v19.field_4 = (double)(mpos.y - nox_win_height / 2);
			// _dprintf("cur %f %f %d", v19.field_0, v19.field_4, nox_xxx_math_509ED0(&v19));
			v15 = nox_xxx_math_509ED0(&v19) / 8;
			if (v19.field_4 * v19.field_4 + v19.field_0 * v19.field_0 > 10000.0 ||
				*getMemU32Ptr(0x852978, 8) && *(_DWORD*)(*getMemU32Ptr(0x852978, 8) + 276) == 6) {
				v15 += 32;
			}
			v16 = nox_xxx_spriteGetMB_476F80();
			if (v16) {
				sub_48B680(1);
				if (!(*(_BYTE*)(v16 + 112) & 6) || sub_495A80(*(_DWORD*)(v16 + 128)))
					sub_48B800(*getMemIntPtr(0x85B3FC, 980));
				else
					sub_48B800(*getMemIntPtr(0x85B3FC, 940));
			} else {
				sub_48B680(0);
			}
			sub_4BE710(*getMemIntPtr(0x5D4594, 1097276), v3, v4, v15);
			sub_4345F0(0);
			break;
		case 15:
			nox_video_drawAnimatedImageOrCursorAt_4BE6D0(*getMemU32Ptr(0x5D4594, 1097220 + 4 * v6), v3, v4);
			dword_5d4594_1097208 = -2 * v5;
			break;
		case 16:
			nox_video_drawAnimatedImageOrCursorAt_4BE6D0(*getMemU32Ptr(0x5D4594, 1097220 + 4 * v6), v3, v4);
			dword_5d4594_1097208 = -v5;
			break;
		default:
			nox_video_drawAnimatedImageOrCursorAt_4BE6D0(*getMemIntPtr(0x5D4594, 1097220), v3, v4);
			break;
		}
		dword_5d4594_3798728 = 0;
		nox_xxx_cursorTypePrev_587000_151528 = nox_client_mouseCursorType;
		*getMemU32Ptr(0x973F18, 68) = v18;
	}
}
