#include "guivote.h"

#include "../../proto.h"
extern _DWORD dword_5d4594_1197308;
extern _DWORD dword_5d4594_1197332;
extern _DWORD dword_5d4594_1197316;
extern _DWORD dword_5d4594_1197320;
extern _DWORD dword_5d4594_1197324;
extern _DWORD dword_5d4594_1197312;

//----- (0048CB10) --------------------------------------------------------
_DWORD* __cdecl sub_48CB10(int a1) {
	_DWORD* result;     // eax
	wchar_t* v2;        // eax
	_DWORD* v3;         // esi
	wchar_t* v4;        // eax
	wchar_t* v5;        // eax
	wchar_t* v6;        // eax
	wchar_t* v7;        // eax
	wchar_t* v8;        // eax
	_DWORD* v9;         // esi
	wchar_t* v10;       // eax
	wchar_t* v11;       // eax
	wchar_t* v12;       // eax
	_DWORD* v13;        // esi
	wchar_t* v14;       // eax
	_DWORD* v15;        // eax
	char* v16;          // ebx
	char* i;            // ebp
	_DWORD* v18;        // eax
	int v19;            // esi
	const wchar_t* v20; // ebx
	char* j;            // ebp
	int v22;            // esi
	const wchar_t* v23; // edi
	wchar_t* v24;       // [esp-10h] [ebp-228h]
	int v25;            // [esp+10h] [ebp-208h]
	char* v26;          // [esp+14h] [ebp-204h]
	wchar_t v27[256];   // [esp+18h] [ebp-200h]

	v25 = 0;
	nox_window_call_field_94(*(int*)&dword_5d4594_1197316, 16399, 0, 0);
	nox_window_call_field_94(*(int*)&dword_5d4594_1197320, 16399, 0, 0);
	result = (_DWORD*)a1;
	dword_5d4594_1197308 = a1;
	switch (a1) {
	case 4:
		if (*getMemU32Ptr(0x5D4594, 2618908) && !*(_DWORD*)(*getMemU32Ptr(0x5D4594, 2618908) + 4792)) {
			v24 =
				nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 156516), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIVote.c", 452);
			v2 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 156580), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIVote.c", 451);
			return nox_xxx_dialogMsgBoxCreate_449A10(0, (int)v2, (int)v24, 33, 0, 0);
		}
		nox_window_set_hidden(*(int*)&dword_5d4594_1197316, 1);
		nox_window_set_hidden(*(int*)&dword_5d4594_1197320, 0);
		v3 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1197312, 4301);
		v4 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 156632), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIVote.c", 465);
		sub_46AEE0((int)v3, (int)v4);
		v5 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 156684), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIVote.c", 468);
		nox_wcscpy(v27, v5);
		nox_wcscat(v27, L" ");
		v6 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 156740), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIVote.c", 470);
		nox_wcscat(v27, v6);
		nox_window_call_field_94(*(int*)&dword_5d4594_1197320, 16397, (int)v27, 4);
		v7 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 156792), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIVote.c", 474);
		nox_wcscpy(v27, v7);
		nox_wcscat(v27, L" ");
		v8 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 156848), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIVote.c", 476);
		nox_wcscat(v27, v8);
		nox_window_call_field_94(*(int*)&dword_5d4594_1197320, 16397, (int)v27, 4);
		return (_DWORD*)nox_xxx_wndShowModalMB_46A8C0(*(int*)&dword_5d4594_1197312);
	case 2:
		nox_window_set_hidden(*(int*)&dword_5d4594_1197316, 1);
		nox_window_set_hidden(*(int*)&dword_5d4594_1197320, 0);
		v9 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1197312, 4301);
		v10 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 156900), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIVote.c", 491);
		sub_46AEE0((int)v9, (int)v10);
		v11 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 156952), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIVote.c", 495);
		nox_window_call_field_94(*(int*)&dword_5d4594_1197320, 16397, (int)v11, 4);
		v12 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 157004), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIVote.c", 498);
		nox_window_call_field_94(*(int*)&dword_5d4594_1197320, 16397, (int)v12, 4);
		if (dword_5d4594_1197332 == 1)
			nox_window_call_field_94(*(int*)&dword_5d4594_1197320, 16403, 0, 0);
		else
			nox_window_call_field_94(*(int*)&dword_5d4594_1197320, 16403, 1, 0);
		return (_DWORD*)nox_xxx_wndShowModalMB_46A8C0(*(int*)&dword_5d4594_1197312);
	case 0:
	case 1:
	case 3:
		nox_window_set_hidden(*(int*)&dword_5d4594_1197316, 0);
		nox_window_set_hidden(*(int*)&dword_5d4594_1197320, 1);
		v13 = nox_xxx_wndGetChildByID_46B0C0(*(_DWORD**)&dword_5d4594_1197312, 4301);
		v14 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 157056), 0, "C:\\NoxPost\\src\\client\\Gui\\GUIVote.c", 520);
		sub_46AEE0((int)v13, (int)v14);
		if (nox_xxx_getTeamCounter_417DD0()) {
			v15 = nox_xxx_objGetTeamByNetCode_418C80(*getMemIntPtr(0x5D4594, 2616328));
			v16 = nox_xxx_clientGetTeamColor_418AB0(*((unsigned __int8*)v15 + 4));
			v26 = v16;
			if (v16) {
				for (i = nox_common_playerInfoGetFirst_416EA0(); i; i = nox_common_playerInfoGetNext_416EE0((int)i)) {
					if (i != *(char**)getMemAt(0x5D4594, 2618908)) {
						v18 = nox_xxx_objGetTeamByNetCode_418C80(*((_DWORD*)i + 515));
						if (v18) {
							if (nox_xxx_teamCompare2_419180((int)v18, v16[57])) {
								nox_window_call_field_94(
									*(int*)&dword_5d4594_1197316, 16397, (int)(i + 4704),
									*getMemU32Ptr(0x587000, 8 * ((unsigned __int8)v16[57] % 10) + 156400));
								v19 = 0;
								if (dword_5d4594_1197324 > 0) {
									v20 = (const wchar_t*)getMemAt(0x5D4594, 1193720);
									do {
										if (!nox_wcscmp(v20, (const wchar_t*)i + 2352))
											nox_window_call_field_94(*(int*)&dword_5d4594_1197316, 16405, v25, 0);
										++v19;
										v20 += 28;
									} while (v19 < *(int*)&dword_5d4594_1197324);
									v16 = v26;
								}
								++v25;
							}
						}
					}
				}
			}
		} else {
			for (j = nox_common_playerInfoGetFirst_416EA0(); j; j = nox_common_playerInfoGetNext_416EE0((int)j)) {
				if (j != *(char**)getMemAt(0x5D4594, 2618908)) {
					nox_window_call_field_94(*(int*)&dword_5d4594_1197316, 16397, (int)(j + 4704), 4);
					v22 = 0;
					if (dword_5d4594_1197324 > 0) {
						v23 = (const wchar_t*)getMemAt(0x5D4594, 1193720);
						do {
							if (!nox_wcscmp(v23, (const wchar_t*)j + 2352))
								nox_window_call_field_94(*(int*)&dword_5d4594_1197316, 16405, v25, 0);
							++v22;
							v23 += 28;
						} while (v22 < *(int*)&dword_5d4594_1197324);
					}
					++v25;
				}
			}
		}
		return (_DWORD*)nox_xxx_wndShowModalMB_46A8C0(*(int*)&dword_5d4594_1197312);
	}
	return result;
}
