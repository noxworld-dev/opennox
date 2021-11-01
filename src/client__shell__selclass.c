#include "client__shell__selclass.h"

#include "common__strman.h"
#include "common__random.h"
#include "GAME1.h"
#include "GAME2.h"
#include "GAME3.h"
#include "GAME3_2.h"
#include "client__shell__selcolor.h"
extern uint32_t dword_5d4594_1307724;
extern nox_gui_animation* nox_wnd_xxx_1307732;
extern uint32_t dword_5d4594_1307736;

//----- (004A4A20) --------------------------------------------------------
int  sub_4A4A20(int a1, int a2, int* a3, int a4) {
	int v4;      // eax
	int v5;      // eax
	int v6;      // eax
	int v7;      // ebx
	uint32_t* v8;  // esi
	wchar_t* v9; // eax

	if (a2 != 16389) {
		if (a2 != 16391)
			return 0;
		v4 = nox_xxx_wndGetID_46B0A0(a3);
		if (v4 >= 601) {
			if (v4 <= 603)
				return 1;
			if (v4 == 610) {
				if (nox_common_gameFlags_check_40A5C0(0x2000) && !nox_common_gameFlags_check_40A5C0(4096)) {
					if (nox_xxx_isQuest_4D6F50() || (v5 = sub_4D6F70()) != 0)
						v5 = 1;
					sub_4A4B70(v5);
				}
				sub_4A4970();
				nox_wnd_xxx_1307732->field_13 = nox_game_showSelColor_4A5D00;
			}
		}
		nox_xxx_clientPlaySoundSpecial_452D80(921, 100);
		return 1;
	}
	v6 = nox_xxx_wndGetID_46B0A0(a3);
	v7 = v6;
	if (v6 >= 601 && v6 <= 603) {
		nox_xxx_wnd_46ABB0(*getMemIntPtr(0x5D4594, 1307728), 1);
		v8 = nox_xxx_wndGetChildByID_46B0C0(*(uint32_t**)&dword_5d4594_1307736, 605);
		*(uint8_t*)(dword_5d4594_1307724 + 66) = v7 - 89;
		v9 = nox_strman_loadString_40F1D0(*(char**)getMemAt(0x587000, 170208 + 4 * (unsigned char)(v7 - 89)), 0,
								   "C:\\NoxPost\\src\\client\\shell\\SelClass.c", 279);
		nox_window_call_field_94((int)v8, 16385, (int)v9, 0);
		*getMemU32Ptr(0x5D4594, 1307740) = v7;
	}
	nox_xxx_clientPlaySoundSpecial_452D80(920, 100);
	return 1;
}

//----- (004A4B70) --------------------------------------------------------
void*  sub_4A4B70(int a1) {
	unsigned char v1; // dl
	void* result;       // eax
	uint8_t* v3;          // edi
	int v4;             // esi
	int v5;             // ebp
	int v6;             // esi
	int v7;             // ebp
	bool v8;            // zf
	unsigned char v9; // [esp+10h] [ebp-Ch]
	int v10;            // [esp+14h] [ebp-8h]
	int v11;            // [esp+18h] [ebp-4h]

	v1 = 0;
	result = (void*)*(unsigned char*)(dword_5d4594_1307724 + 66);
	v3 = *(uint8_t**)getMemAt(0x587000, 170156 + 4 * (uint32_t)result);
	if (*v3) {
		do
			result = (void*)++v1;
		while (v3[4 * v1 + v1]);
		if (v1) {
			v4 = 0;
			v9 = nox_common_randomIntMinMax_415FF0(0, v1 - 1, "C:\\NoxPost\\src\\client\\shell\\SelClass.c", 195);
			if (*(uint8_t*)(dword_5d4594_1307724 + 66)) {
				v10 = 0;
				v11 = 5;
				do {
					nox_xxx_clientUpdateButtonRow_45E110(v10);
					v6 = 0;
					v7 = 5;
					do {
						if (a1 == 1)
							nox_xxx_book_45DBE0((void*)2, 0, v6);
						else
							nox_xxx_book_45DBE0((void*)2, (unsigned char)v3[4 * v9 + v6 + v9], v6);
						++v6;
						--v7;
					} while (v7);
					v8 = v11 == 1;
					++v10;
					--v11;
				} while (!v8);
				result = (void*)nox_xxx_clientUpdateButtonRow_45E110(0);
			} else {
				nox_xxx_clientUpdateButtonRow_45E110(0);
				v5 = 5;
				do {
					if (a1 == 1)
						result = nox_xxx_book_45DBE0((void*)3, 0, v4);
					else
						result = nox_xxx_book_45DBE0((void*)3, (unsigned char)v3[4 * v9 + v4 + v9], v4);
					++v4;
					--v5;
				} while (v5);
			}
		}
	}
	return result;
}
