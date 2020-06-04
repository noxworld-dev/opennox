#include "inputcfg.h"

#include "../../../proto.h"
extern _DWORD dword_5d4594_1522632;
extern _DWORD dword_5d4594_1522612;
extern _DWORD dword_5d4594_1522604;
extern _DWORD dword_5d4594_1522628;
extern _DWORD dword_5d4594_1522624;

//----- (004CBD30) --------------------------------------------------------
char* sub_4CBD30() {
	int v0;        // ebp
	int i;         // esi
	wchar_t* v2;   // eax
	int v3;        // edi
	wchar_t* v4;   // eax
	char* v5;      // ebx
	wchar_t* v6;   // eax
	char* v7;      // eax
	wchar_t* v8;   // eax
	int v9;        // esi
	wchar_t* v10;  // eax
	char* result;  // eax
	char v12[256]; // [esp+8h] [ebp-100h]

	v0 = *(_DWORD*)(*(_DWORD*)&byte_5D4594[1522620] + 32);
	sub_42CD90();
	for (i = 0; i < *(__int16*)(v0 + 44); ++i) {
		v2 = (wchar_t*)nox_window_call_field_94(*(int*)&byte_5D4594[1522620], 16406, i, 0);
		v3 = sub_42EA40(v2);
		v4 = (wchar_t*)nox_window_call_field_94(*(int*)&dword_5d4594_1522624, 16406, i, 0);
		v5 = sub_42E960(v4);
		v6 = (wchar_t*)nox_window_call_field_94(*(int*)&dword_5d4594_1522628, 16406, i, 0);
		v7 = sub_42E960(v6);
		if (v7) {
			nox_sprintf(v12, "%s = %s", v7, v3);
			sub_42CF50(v12);
		}
		if (v5) {
			nox_sprintf(v12, "%s = %s", v5, v3);
			sub_42CF50(v12);
		}
	}
	v8 = loadString_sub_40F1D0((char*)&byte_587000[187620], 0,
				   "C:\\NoxPost\\src\\Client\\shell\\InputCfg\\inputcfg.c", 192);
	v9 = sub_42EA40(v8);
	v10 = loadString_sub_40F1D0((char*)&byte_587000[187696], 0,
				    "C:\\NoxPost\\src\\Client\\shell\\InputCfg\\inputcfg.c", 193);
	result = sub_42E960(v10);
	if (result) {
		nox_sprintf(v12, "%s = %s", result, v9);
		result = (char*)sub_42CF50(v12);
	}
	return result;
}

//----- (004CBF60) --------------------------------------------------------
int __cdecl sub_4CBF60(int a1, unsigned int a2, int a3, int a4) {
	int v5;      // eax
	wchar_t* v6; // eax
	int v7;      // esi
	int v8;      // esi
	int v9;      // [esp-4h] [ebp-10h]

	if (a2 > 0x4007) {
		if (a2 == 16393) {
			v7 = *(_DWORD*)(a1 + 32);
			sub_4A30D0(a1, 0x4009u, (wchar_t*)a3, a4);
			v8 = sub_4A4800(v7);
			nox_window_call_field_94(*(int*)&byte_5D4594[1522620], 16412, v8, 0);
			nox_window_call_field_94(*(int*)&dword_5d4594_1522624, 16412, v8, 0);
			nox_window_call_field_94(*(int*)&dword_5d4594_1522628, 16412, v8, 0);
		} else if (a2 == 16400) {
			v5 = *(_DWORD*)(a3 + 32);
			if ((int)*(_DWORD*)(v5 + 48) >= 0) {
				dword_5d4594_1522632 = a3;
				v9 = nox_window_call_field_94(*(int*)&byte_5D4594[1522620], 16406, *(_DWORD*)(v5 + 48),
							      0);
				v6 =
				    loadString_sub_40F1D0((char*)&byte_587000[187784], 0,
							  "C:\\NoxPost\\src\\Client\\shell\\InputCfg\\inputcfg.c", 424);
				nox_swprintf((wchar_t*)&byte_5D4594[1522636], L"%s\n'%s'", v6, v9);
				sub_46A8C0(*(int*)&dword_5d4594_1522612);
				sub_46B500(*(int*)&dword_5d4594_1522612);
				sub_46C690(*(int*)&dword_5d4594_1522612);
				return sub_4A30D0(a1, 0x4010u, (wchar_t*)a3, a4);
			}
		}
	} else {
		if (a2 != 16391) {
			if (a2 == 23)
				return 1;
			if (a2 != 0x4000)
				return sub_4A30D0(a1, a2, (wchar_t*)a3, a4);
		}
		if ((_DWORD*)a3 == sub_46B0C0(*(_DWORD**)&dword_5d4594_1522604, 921) ||
		    (_DWORD*)a3 == sub_46B0C0(*(_DWORD**)&dword_5d4594_1522604, 922)) {
			nox_window_call_field_94(*(int*)&byte_5D4594[1522620], a2, a3, 0);
			nox_window_call_field_94(*(int*)&dword_5d4594_1522624, a2, a3, 0);
			nox_window_call_field_94(*(int*)&dword_5d4594_1522628, a2, a3, 0);
			return sub_4A30D0(a1, a2, (wchar_t*)a3, a4);
		}
	}
	return sub_4A30D0(a1, a2, (wchar_t*)a3, a4);
}
