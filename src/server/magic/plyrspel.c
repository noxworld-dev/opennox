#include "../../client/gui/guimsg.h"

#include "../../proto.h"
extern void* dword_587000_66120;

//----- (00424850) --------------------------------------------------------
BOOL __cdecl nox_xxx_isArgB8EqSome_424850(void* a1) { return a1 == *(void**)&dword_587000_66120; }

//----- (004D7F90) --------------------------------------------------------
int __cdecl nox_xxx_netSendSpellAward_4D7F90(int a1, int a2, char a3, int a4) {
	int result; // eax
	int v5;     // eax

	result = a1;
	if (*(_BYTE*)(a1 + 8) & 4) {
		v5 = *(_DWORD*)(a1 + 748);
		LOBYTE(a1) = 111;
		BYTE1(a1) = a2;
		BYTE2(a1) = *(_BYTE*)(*(_DWORD*)(v5 + 276) + 4 * a2 + 3696);
		HIBYTE(a1) = a3;
		if (a4)
			HIBYTE(a1) = a3 | 0x80;
		result = nox_xxx_netSendPacket1_4E5390(*(unsigned __int8*)(*(_DWORD*)(v5 + 276) + 2064), (int)&a1, 4, 0, 1);
	}
	return result;
}

//----- (004FB0B0) --------------------------------------------------------
void __cdecl nox_xxx_abilGetError_4FB0B0_magic_plyrspel(int a1) {
	wchar_t* v1; // eax

	v1 = nox_xxx_loadString_40F1D0(*(char**)getMemAt(0x587000, 4 * a1 + 216380), 0, "C:\\NoxPost\\src\\Server\\Magic\\plyrspel.c",
							   86);
	nox_xxx_printCentered_445490(v1);
}

//----- (004FB2A0) --------------------------------------------------------
int __cdecl nox_xxx_playerSpell_4FB2A0_magic_plyrspel(int a1) {
	_DWORD* v1;   // edi
	int v2;       // ebp
	int v3;       // esi
	_DWORD* v4;   // eax
	int v5;       // ebx
	int result;   // eax
	int v7;       // eax
	int v8;       // ebx
	int v9;       // ecx
	int v10;      // eax
	double v11;   // st7
	int* v12;     // eax
	wchar_t* v13; // eax
	int v14[3];   // [esp+10h] [ebp-Ch]

	v1 = (_DWORD*)a1;
	v2 = 1;
	v3 = *(_DWORD*)(a1 + 748);
	if (nox_xxx_isArgB8EqSome_424850(*(void**)(v3 + 184))) {
		v2 = 0;
	} else {
		v4 = *(_DWORD**)(v3 + 184);
		if (v4 && *v4) {
			if (!nox_common_gameFlags_check_40A5C0(4096)) {
				v5 = *(_DWORD*)(v3 + 288);
				if (nox_xxx_spellDefHasFlags_424A50(**(_DWORD**)(v3 + 184), 32)) {
					if (v5) {
						result = nox_xxx_unitIsEnemyTo_5330C0((int)v1, v5);
						if (!result)
							return result;
					}
				}
			}
			v7 = **(_DWORD**)(v3 + 184);
			if (*(_DWORD*)(*(_DWORD*)(v3 + 276) + 4 * v7 + 3696) || v7 == 34) {
				v2 = 0;
				a1 = sub_4FD0E0((int)v1, v7);
				if (a1 || (a1 = nox_xxx_checkPlrCantCastSpell_4FD150((int)v1, **(_DWORD**)(v3 + 184), 0)) != 0) {
					nox_xxx_netInformTextMsg_4DA0F0(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), 0, &a1);
					nox_xxx_aud_501960(231, (int)v1, 0, 0);
				} else {
					v8 = sub_4FCF90((int)v1, **(_DWORD**)(v3 + 184), 1);
					if (v8 < 0) {
						a1 = 11;
						nox_xxx_netInformTextMsg_4DA0F0(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), 0, &a1);
						nox_xxx_aud_501960(232, (int)v1, 0, 0);
					} else {
						v14[0] = *(_DWORD*)(*(_DWORD*)(v3 + 276) + 3640);
						if (nox_common_gameFlags_check_40A5C0(4096)) {
							if (nox_xxx_spellDefHasFlags_424A50(**(_DWORD**)(v3 + 184), 32)) {
								v9 = *(_DWORD*)(v3 + 276);
								if (*(_DWORD*)(v9 + 3640)) {
									if (!nox_xxx_unitIsEnemyTo_5330C0((int)v1, *(_DWORD*)(v9 + 3640)))
										v14[0] = 0;
								}
							}
						}
						v10 = *(_DWORD*)(v3 + 276);
						*(float*)&v14[1] = (double)*(int*)(v10 + 2284);
						v11 = (double)*(int*)(v10 + 2288);
						v12 = *(int**)(v3 + 184);
						*(float*)&v14[2] = v11;
						if (nox_xxx_castSpellByUser_4FDD20(*v12, v1, v14)) {
							nox_xxx_netInformTextMsg_4DA0F0(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), 1, *(int**)(v3 + 184));
						} else {
							sub_4FD030((int)v1, v8);
							a1 = 8;
						}
					}
				}
			}
		}
	}
	if (*(_BYTE*)(v3 + 88) == 2)
		nox_xxx_playerSetState_4FA020(v1, 13);
	if (v2) {
		v13 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 216908), 0, "C:\\NoxPost\\src\\Server\\Magic\\plyrspel.c", 301);
		result = nox_xxx_netSendLineMessage_4D9EB0((int)v1, v13);
	} else if (a1) {
		result = nox_xxx_netReportSpellStat_4D9630(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), **(_DWORD**)(v3 + 184), 0);
	} else {
		result = nox_xxx_spellDefHasFlags_424A50(**(_DWORD**)(v3 + 184), 0x100000);
		if (!result)
			result = nox_xxx_netReportSpellStat_4D9630(*(unsigned __int8*)(*(_DWORD*)(v3 + 276) + 2064), **(_DWORD**)(v3 + 184), 15);
	}
	return result;
}

//----- (004FB550) --------------------------------------------------------
int __cdecl nox_xxx_spellGrantToPlayer_4FB550_magic_plyrspel(int a1, int a2, int a3, int a4, int a5) {
	int v5;      // ebp
	int v6;      // esi
	int v7;      // ebx
	wchar_t* v8; // eax
	_DWORD* v9;  // eax
	int v10;     // edx
	int v11;     // ebp
	int v12;     // edi
	_DWORD* v13; // eax
	int v14;     // edx
	int v15;     // edi
	char* i;     // edi
	int v17;     // eax
	_DWORD* v18; // ebx

	v5 = a1;
	if (!(*(_BYTE*)(a1 + 8) & 4))
		return 0;
	v6 = a2;
	if (a2 <= 0 || a2 >= 137) {
		v8 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 216964), 0, "C:\\NoxPost\\src\\Server\\Magic\\plyrspel.c", 339);
		nox_xxx_netSendLineMessage_4D9EB0(a1, v8);
		return 0;
	}
	v7 = *(_DWORD*)(a1 + 748);
	if (nox_common_gameFlags_check_40A5C0(6144) && *(_DWORD*)(*(_DWORD*)(v7 + 276) + 4 * a2 + 3696) == 3 ||
		*(_DWORD*)(*(_DWORD*)(v7 + 276) + 4 * a2 + 3696) == 5) {
		v8 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 217020), 0, "C:\\NoxPost\\src\\Server\\Magic\\plyrspel.c", 351);
		nox_xxx_netSendLineMessage_4D9EB0(a1, v8);
		return 0;
	}
	if (nox_common_gameFlags_check_40A5C0(4096) &&
		(a2 == 34 || a2 == 134 || a2 == 45 || a2 == 46 || a2 == 47 || a2 == 48 || a2 == 49 || a2 == 117 || a2 == 118 ||
		 a2 == 119 || a2 == 120 || a2 == 121 || a2 == 122 || a2 == 123 || a2 == 124 || a2 == 125 || a2 == 19) &&
		*(_DWORD*)(*(_DWORD*)(v7 + 276) + 4 * a2 + 3696)) {
		v8 = nox_xxx_loadString_40F1D0((char*)getMemAt(0x587000, 217076), 0, "C:\\NoxPost\\src\\Server\\Magic\\plyrspel.c", 386);
		nox_xxx_netSendLineMessage_4D9EB0(a1, v8);
		return 0;
	}
	++*(_DWORD*)(*(_DWORD*)(v7 + 276) + 4 * a2 + 3696);
	v9 = (_DWORD*)(*(_DWORD*)(v7 + 276) + 4 * a2 + 3696);
	if (*v9 > 5)
		*v9 = 5;
	if (nox_common_gameFlags_check_40A5C0(4096)) {
		v10 = *(_DWORD*)(v7 + 276);
		if (*(_DWORD*)(v10 + 4 * a2 + 3696) > 3)
			*(_DWORD*)(v10 + 4 * a2 + 3696) = 3;
	}
	if (a5)
		*(_DWORD*)(*(_DWORD*)(v7 + 276) + 4 * a2 + 3696) = a5;
	nox_xxx_playerAwardSpellProtection_56FCE0(*(_DWORD*)(*(_DWORD*)(v7 + 276) + 4636), a2, *(_DWORD*)(*(_DWORD*)(v7 + 276) + 4 * a2 + 3696));
	int v20 = 0;
	if (nox_xxx_spellDefHasFlags_424A50(a2, 4096)) {
		v20 = 0x2000;
	} else if (nox_xxx_spellDefHasFlags_424A50(a2, 0x4000)) {
		v20 = 0x8000;
	} else if (nox_xxx_spellDefHasFlags_424A50(a2, 0x10000)) {
		v20 = 0x20000;
	}
	if (v20) {
		v11 = 1;
		v12 = 3700;
		while (v12 < 4244) {
			if (nox_xxx_spellDefHasFlags_424A50(v11, v20) && nox_xxx_spellGetValidMB_424B50(v11)) {
				if (a5)
					*(_DWORD*)(v12 + *(_DWORD*)(v7 + 276)) = a5;
				else
					++*(_DWORD*)(v12 + *(_DWORD*)(v7 + 276));
				v13 = (_DWORD*)(v12 + *(_DWORD*)(v7 + 276));
				if (*v13 > 5)
					*v13 = 5;
				if (nox_common_gameFlags_check_40A5C0(4096)) {
					v14 = *(_DWORD*)(v7 + 276);
					if (*(_DWORD*)(v14 + 4 * v6 + 3696) > 3)
						*(_DWORD*)(v14 + 4 * v6 + 3696) = 3;
				}
				nox_xxx_playerAwardSpellProtection_56FCE0(*(_DWORD*)(*(_DWORD*)(v7 + 276) + 4636), v6, *(_DWORD*)(v12 + *(_DWORD*)(v7 + 276)));
			}
			v12 += 4;
			++v11;
		}
		v5 = a1;
	}
	if (a3) {
		v15 = 1;
		nox_xxx_aud_501960(226, v5, 0, 0);
		if (nox_common_gameFlags_check_40A5C0(2048) && (v6 == 34 || nox_xxx_spellDefHasFlags_424A50(v6, 86016)))
			v15 = 0;
		if (!nox_common_gameFlags_check_40A5C0(4096) || *(_DWORD*)(*(_DWORD*)(v7 + 276) + 4792)) {
			if (v15) {
				nox_xxx_netSendRewardNotify_4FAD50(v5, 0, v5, v6);
				if (!sub_419E60(v5)) {
					for (i = nox_common_playerInfoGetFirst_416EA0(); i; i = nox_common_playerInfoGetNext_416EE0((int)i)) {
						v17 = *((_DWORD*)i + 514);
						if (v17 != v5 && v17)
							nox_xxx_netSendRewardNotify_4FAD50(v17, 0, v5, v6);
					}
				}
			}
		}
	}
	if (nox_common_gameFlags_check_40A5C0(2048) && a3 == 1 && a4 == 1) {
		v18 = *(_DWORD**)(v7 + 280);
		if (v18)
			sub_50F4C0(v18);
	}
	nox_xxx_netSendSpellAward_4D7F90(v5, v6, a3, a4);
	return 1;
}
