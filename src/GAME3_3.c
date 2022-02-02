#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif
#include <math.h>

#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME1_2.h"
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
#include "common__net_list.h"
#include "common__random.h"
#include "common__system__team.h"
#include "operators.h"
#include "server__ability__ability.h"
#include "server__magic__plyrspel.h"
#include "server__object__health.h"
#include "server__system__server.h"

#include "common__gamemech__pausefx.h"

#include "client__gui__window.h"
#include "client__video__draw_common.h"
#include "common/fs/nox_fs.h"
#include "common__crypt.h"
#include "common__magic__speltree.h"
#include "server__script__script.h"
#include "server__script__activator.h"

extern uint32_t nox_xxx_respawnAllow_587000_205200;
extern uint32_t dword_5d4594_1567960;
extern uint32_t dword_5d4594_1567956;
extern uint32_t dword_5d4594_1568280;
extern uint32_t dword_5d4594_1568288;
extern uint32_t dword_5d4594_1563320;
extern uint32_t dword_5d4594_1568308;
extern uint32_t dword_5d4594_1567988;
extern uint32_t dword_5d4594_1565628;
extern uint32_t dword_5d4594_1565632;
extern uint32_t dword_5d4594_1565612;
extern uint32_t dword_5d4594_1565520;
extern uint32_t nox_server_needInitNetCodeCache;
extern uint32_t dword_5d4594_1568260;
extern uint32_t dword_5d4594_1565516;
extern uint32_t dword_5d4594_1563664;
extern uint32_t dword_5d4594_1567928;
extern void* nox_alloc_respawn_1568020;
extern uint32_t dword_5d4594_1565616;
extern uint32_t dword_587000_202404;
extern uint32_t nox_xxx_warriorMaxMana_587000_312788;
extern nox_objectType_t* nox_xxx_objectTypes_head_1563660;
extern uint32_t nox_xxx_warriorMaxHealth_587000_312784;
extern uint32_t nox_xxx_conjurerMaxHealth_587000_312800;
extern uint32_t nox_xxx_wizardMaxHealth_587000_312816;
extern uint32_t nox_xxx_conjurerMaxMana_587000_312804;
extern uint32_t nox_xxx_wizardMaximumMana_587000_312820;
extern uint32_t dword_5d4594_2649712;
extern uint64_t qword_581450_10176;
extern uint64_t qword_581450_10256;
extern uint64_t qword_5d4594_1567940;
extern uint64_t qword_581450_9544;
extern nox_object_t* nox_xxx_host_player_unit_3843628;
extern uint32_t dword_5d4594_1568024;
extern uint32_t dword_5d4594_1565512;
extern uint32_t dword_5d4594_2650652;
extern nox_memfile* nox_loaded_thing_bin;
extern unsigned int nox_gameFPS;
extern unsigned int nox_frame_xxx_2598000;
extern unsigned int gameex_flags;

nox_alloc_class* nox_alloc_gameObject_1563344 = 0;

//----- (004E17B0) --------------------------------------------------------
int nox_server_handler_PlayerDamage_4E17B0(int a1, int a2, int a3, int a4, int a5) {
	int v5;           // esi
	int v6;           // eax
	int v8;           // eax
	int v9;           // ebx
	int v10;          // edx
	int v11;          // ecx
	int v12;          // edi
	int* v13;         // eax
	int weaponFlags;  // ebp
	float v15;        // eax
	float2* v16;      // ebp
	int v17;          // ecx
	int v18;          // eax
	int v19;          // edx
	int v20;          // eax
	int v21;          // ecx
	int v22;          // eax
	int v23;          // eax
	int v24;          // eax
	int v25;          // ebp
	double v26;       // st7
	int v27;          // ebp
	char v28;         // al
	int v29;          // eax
	double v30;       // st7
	char v31;         // al
	double v32;       // st7
	int v33;          // ebp
	int v34;          // eax
	double v35;       // st7
	float v36;        // edx
	float v37;        // eax
	int v38;          // eax
	float v39;        // ecx
	float v40;        // edx
	int v41;          // eax
	float v42;        // ebx
	int v43;          // eax
	int v44;          // edi
	int v45;          // eax
	float v46;        // [esp+0h] [ebp-2Ch]
	float v47;        // [esp+0h] [ebp-2Ch]
	float v48;        // [esp+0h] [ebp-2Ch]
	float v49;        // [esp+4h] [ebp-28h]
	float v50;        // [esp+4h] [ebp-28h]
	float v51;        // [esp+4h] [ebp-28h]
	float v52;        // [esp+4h] [ebp-28h]
	float v53;        // [esp+18h] [ebp-14h]
	int armorrFlags;  // [esp+1Ch] [ebp-10h]
	int weaponFlags2; // [esp+20h] [ebp-Ch]
	float2 a3a;       // [esp+24h] [ebp-8h]

	v5 = a1;
	v6 = *(uint32_t*)(a1 + 16);
	if (v6 & 2 || (v6 & 0x8000) != 0) {
		return 0;
	}
	if (nox_xxx_testUnitBuffs_4FF350(a1, 23)) {
		if (!((unsigned char)nox_frame_xxx_2598000 & 3)) {
			nox_xxx_aud_501960(71, v5, 0, 0);
		}
		return 1;
	}
	v8 = nox_common_gameFlags_check_40A5C0(2048);
	v9 = a2;
	if (v8) {
		if (nox_xxx_findParentChainPlayer_4EC580(a2) == v5 && *(uint8_t*)(v5 + 8) & 4 && LODWORD(a5) != 15) {
			return 0;
		}
	}
	if (a3) {
		v9 = a3;
	}
	v10 = *(uint32_t*)(v5 + 8);
	v11 = *(uint32_t*)(v5 + 8) & 4;
	if (v11) {                        // Is player
		v12 = *(uint32_t*)(v5 + 748); // UC
		v13 = *(int**)(v12 + 276);    // PlayerInfo
		weaponFlags = v13[1];
		armorrFlags = *v13;
		v15 = *(float*)(v12 + 228);
		weaponFlags2 = weaponFlags;
	} else {
		if (!(v10 & 2) || !(*(uint8_t*)(v5 + 12) & 0x10)) {
			return 0;
		}
		v12 = *(uint32_t*)(v5 + 748);
		weaponFlags2 = *(uint32_t*)(v12 + 2056);
		armorrFlags = *(uint32_t*)(v12 + 2060);
		v15 = *(float*)(v12 + 2072);
	}
	v53 = v15;
	if (v11) {
		if (*(uint8_t*)(*(uint32_t*)(v12 + 276) + 3680) & 1) {
			return 0;
		}
	}
	if (v11) {
		*(uint32_t*)(v12 + 304) = 0;
	} else if (v10 & 2) {
		*(uint32_t*)(v12 + 2188) = 0;
	}
	if (*(uint8_t*)(v5 + 8) & 4 && nox_xxx_playerGetPossess_4DDF30(v5)) {
		nox_xxx_playerObserveClear_4DDEF0(v5);
	}
	if (nox_xxx_testUnitBuffs_4FF350(v5, 27) && v9) {
		if (*(uint8_t*)(v9 + 8) & 1) {
			v16 = (float2*)(v5 + 56);
			if (nox_server_testTwoPointsAndDirection_4E6E50((float2*)(v5 + 56), *(short*)(v5 + 124),
															(float2*)(v9 + 56)) &
				1) {
				nox_xxx_projectileReflect_4E0A70(v9, v5);
				if (!(*(uint8_t*)(v9 + 12) & 0x40)) {
					nox_xxx_unitClearOwner_4EC300(v9);
					nox_xxx_unitSetOwner_4EC290(v5, v9);
				}
				if (*(uint8_t*)(v9 + 8) & 1 && *(uint8_t*)(v9 + 12) & 2) {
					nox_xxx_changeOwner_52BE40(v9, v5);
				}
				if (LODWORD(a5) == 16) {
					nox_xxx_netSendPointFx_522FF0(132, v16);
				}
				nox_xxx_aud_501960(122, v5, 0, 0);
				return 0;
			}
		} else if (LODWORD(a5) == 16 || LODWORD(a5) == 17) {
			v16 = (float2*)(v5 + 56);
			if (nox_server_testTwoPointsAndDirection_4E6E50((float2*)(v5 + 56), *(short*)(v5 + 124),
															(float2*)(v9 + 56)) &
				1) {
				if (LODWORD(a5) == 16) {
					nox_xxx_netSendPointFx_522FF0(132, v16);
				}
				nox_xxx_aud_501960(122, v5, 0, 0);
				return 0;
			}
		}
	}
	if (a2) {
		v17 = dword_5d4594_1563320;
		if (!dword_5d4594_1563320) {
			dword_5d4594_1563320 = nox_xxx_getNameId_4E3AA0("SmallFist");
			*getMemU32Ptr(0x5D4594, 1563324) = nox_xxx_getNameId_4E3AA0("MediumFist");
			*getMemU32Ptr(0x5D4594, 1563328) = nox_xxx_getNameId_4E3AA0("LargeFist");
			*getMemU32Ptr(0x5D4594, 1563332) = nox_xxx_getNameId_4E3AA0("Meteor");
			*getMemU32Ptr(0x5D4594, 1563336) = nox_xxx_getNameId_4E3AA0("ToxicCloud");
			v18 = nox_xxx_getNameId_4E3AA0("SmallToxicCloud");
			v17 = dword_5d4594_1563320;
			*getMemU32Ptr(0x5D4594, 1563340) = v18;
		}
		v19 = a3;
		if (a3) {
			a3a = *(float2*)(a3 + 72);
			v20 = *(unsigned short*)(a3 + 4);
			v21 = (unsigned short)v20 != v17 && v20 != *getMemU32Ptr(0x5D4594, 1563324) &&
				  v20 != *getMemU32Ptr(0x5D4594, 1563328) && v20 != *getMemU32Ptr(0x5D4594, 1563332) &&
				  v20 != *getMemU32Ptr(0x5D4594, 1563336) && v20 != *getMemU32Ptr(0x5D4594, 1563340);
			if (a2 != a3) {
				v22 = *(uint32_t*)(v5 + 8);
				if (v22 & 4) {
					*(uint32_t*)(v12 + 304) = 1;
					*(uint32_t*)(v12 + 300) = *(unsigned short*)(v19 + 4);
				} else if (v22 & 2) {
					*(uint32_t*)(v12 + 2188) = 1;
					*(uint32_t*)(v12 + 2184) = *(unsigned short*)(v19 + 4);
				}
			}
		} else {
			v19 = a2;
			a3a = *(float2*)(a2 + 72);
			v23 = *(unsigned short*)(a2 + 4);
			v21 = (unsigned short)v23 != v17 && v23 != *getMemU32Ptr(0x5D4594, 1563324) &&
				  v23 != *getMemU32Ptr(0x5D4594, 1563328) && v23 != *getMemU32Ptr(0x5D4594, 1563332);
			if (LODWORD(a5) == 10 || LODWORD(a5) == 2) {
				v24 = *(uint32_t*)(v5 + 8);
				if (v24 & 4) {
					*(uint32_t*)(v12 + 304) = 1;
					*(uint32_t*)(v12 + 300) = *(unsigned short*)(v19 + 4);
				} else if (v24 & 2) {
					*(uint32_t*)(v12 + 2188) = 1;
					*(uint32_t*)(v12 + 2184) = *(unsigned short*)(v19 + 4);
				}
			}
		}
		if (!(LODWORD(a5) == 15 || !v21 ||
			  !(nox_server_testTwoPointsAndDirection_4E6E50((float2*)(v5 + 56), *(short*)(v5 + 124), &a3a) & 1))) {
			int c1 = *(uint8_t*)(v5 + 8) & 4;
			if (((c1 && *(uint8_t*)(v12 + 88) != 16) || (!c1 && nox_xxx_mobActionGet_50A020(v5) != 21)) ||
				!(armorrFlags & 0x3000000)) {
				v27 = LODWORD(a5);
				if (weaponFlags2 & 0x400) {
					v27 = LODWORD(a5);
					if (*(uint8_t*)(v9 + 8) & 1 || a5 == 0.0 || LODWORD(a5) == 11) {
						if (*(uint8_t*)(v5 + 8) & 4) {
							v28 = *(uint8_t*)(v12 + 88);
							if (v28 != 13 && v28 != 18 && v28 != 19 && v28 != 20) {
								goto LABEL_120;
							}
						} else if (!sub_534340(v5)) {
							goto LABEL_120;
						}
						if (*(uint8_t*)(v9 + 8) & 1) {
							nox_xxx_projectileReflect_4E0A70(v9, v5);
							if (*(uint8_t*)(v9 + 8) & 1) {
								if (!(*(uint8_t*)(v9 + 12) & 2)) {
									nox_xxx_unitClearOwner_4EC300(v9);
									nox_xxx_unitSetOwner_4EC290(v5, v9);
								}
							}
						}
						nox_xxx_aud_501960(890, v5, 0, 0);
						if (*(uint8_t*)(v5 + 8) & 4) {
							v29 = nox_common_randomInt_415FA0(18, 20);
							nox_xxx_playerSetState_4FA020((uint32_t*)v5, v29);
						} else {
							nox_xxx_monsterAction_50A360(v5, 23);
						}
						v30 = nox_xxx_gamedataGetFloat_419D40("ItemDamageFromBlockPercentage");
						v47 = v30 * (double)a4;
						sub_4E22A0(v5, a2, a3, 1024, v47, v27);
						return 0;
					}
				} else {
					// actionId (+88) = 1 corresposponds either to attacking OR using berserker charge
					// armorrFlags & 0x3000000 tests if either Steel or Wooden shields are equipped (see 58F820 -- table
					// that references armor types and corresponding flags)
					if (*(uint8_t*)(v12 + 88) == 1 && nox_common_mapPlrActionToStateId_4FA2B0(v5) == 45 &&
						armorrFlags & 0x3000000) {
						if (gameex_flags & 0x10) { // BERSERKER_SHIED_BLOCK
							goto M_LABEL_78;
						}
					}
				}
				if (!(weaponFlags2 & 0x7FF8000) || v27 && v27 != 11 || *(uint8_t*)(v9 + 8) & 1) {
					goto LABEL_120;
				}
				if (*(uint8_t*)(v5 + 8) & 4) {
					v31 = *(uint8_t*)(v12 + 88);
					if (v31 != 13 && v31 != 18 && v31 != 19 && v31 != 20 &&
						(v31 || !(gameex_flags & 0x4))) { // GREAT_SWORD_BLOKING_WALK
						goto LABEL_120;
					}
				} else if (!sub_534340(v5)) {
					goto LABEL_120;
				}
				nox_xxx_aud_501960(894, v5, 0, 0);
				if (*(uint8_t*)(v5 + 8) & 4) {
					nox_xxx_playerSetState_4FA020((uint32_t*)v5, 21);
				} else {
					nox_xxx_monsterAction_50A360(v5, 23);
				}
				v32 = nox_xxx_gamedataGetFloat_419D40("ItemDamageFromBlockPercentage");
				v48 = v32 * (double)a4;
				sub_4E22A0(v5, a2, a3, 134184960, v48, v27);
				return 0;
			}
		M_LABEL_78:
			v25 = LODWORD(a5);
			if (LODWORD(a5) != 9 && LODWORD(a5) != 17) { // Blocking
				nox_xxx_aud_501960(878, v5, 0, 0);
				if ((*(uint8_t*)(v9 + 8) & 1) && (!(*(uint8_t*)(v9 + 12) & 0x70))) {
					nox_xxx_projectileReflect_4E0A70(v9, v5);
					if ((*(uint8_t*)(v9 + 8) & 1) && (!(*(uint8_t*)(v9 + 12) & 2))) {
						nox_xxx_unitClearOwner_4EC300(v9);
						nox_xxx_unitSetOwner_4EC290(v5, v9);
					}
				}
				v26 = nox_xxx_gamedataGetFloat_419D40("ItemDamageFromBlockPercentage");
				v46 = v26 * (double)a4;
				sub_4E2330(v5, a2, a3, 2, v46, v25);
				return 0;
			}
		}
	}
LABEL_120:
	switch (LODWORD(a5)) {
	case 0:
	case 3:
	case 7:
	case 8:
	case 0xA:
	case 0xB:
		v51 = (1.0 - v53) * (double)a4;
		nox_xxx_playerDecrementHPMana_4E20F0(v5, (int)&a1, v51);
		v33 = a4;
		v42 = a5;
		nox_xxx_playerDamageItems_4E2180(v5, a2, a3, a4 - a1, a5);
		v43 = *(uint32_t*)(v5 + 8);
		if (v43 & 4) {
			if (!*(uint32_t*)(v12 + 304)) {
				*(uint32_t*)(v12 + 304) = 2;
				*(float*)(v12 + 300) = v42;
			}
		} else if (v43 & 2 && !*(uint32_t*)(v12 + 2188)) {
			*(uint32_t*)(v12 + 2188) = 2;
			*(float*)(v12 + 2184) = v42;
		}
		break;
	case 1:
	case 0xC:
		v33 = a4;
		a1 = a4;
		nox_xxx_playerDamageItems_4E2180(v5, a2, a3, a4, a5);
		v34 = *(uint32_t*)(v5 + 8);
		if (v34 & 4) {
			if (!*(uint32_t*)(v12 + 304)) {
				v36 = a5;
				*(uint32_t*)(v12 + 304) = 2;
				*(float*)(v12 + 300) = v36;
			}
		} else if (v34 & 2 && !*(uint32_t*)(v12 + 2188)) {
			v37 = a5;
			*(uint32_t*)(v12 + 2188) = 2;
			*(float*)(v12 + 2184) = v37;
		}
		break;
	case 2:
		v50 = (1.0 - v53 * 0.5) * (double)a4;
		nox_xxx_playerDecrementHPMana_4E20F0(v5, (int)&a1, v50);
		v33 = a4;
		nox_xxx_playerDamageItems_4E2180(v5, a2, a3, a4 - a1, COERCE_FLOAT(2));
		v41 = *(uint32_t*)(v5 + 8);
		if (v41 & 4) {
			if (!*(uint32_t*)(v12 + 304)) {
				*(uint32_t*)(v12 + 304) = 2;
				*(uint32_t*)(v12 + 300) = 2;
			}
		} else if (v41 & 2 && !*(uint32_t*)(v12 + 2188)) {
			*(uint32_t*)(v12 + 2188) = 2;
			*(uint32_t*)(v12 + 2184) = 2;
		}
		break;
	case 4:
	case 5:
	case 6:
	case 0xE:
	case 0xF:
	case 0x10:
		v38 = *(uint32_t*)(v5 + 8);
		v33 = a4;
		a1 = a4;
		if (v38 & 4) {
			if (!*(uint32_t*)(v12 + 304)) {
				v39 = a5;
				*(uint32_t*)(v12 + 304) = 2;
				*(float*)(v12 + 300) = v39;
			}
		} else if (v38 & 2 && !*(uint32_t*)(v12 + 2188)) {
			v40 = a5;
			*(uint32_t*)(v12 + 2188) = 2;
			*(float*)(v12 + 2184) = v40;
		}
		break;
	case 9:
	case 0x11:
		v35 = sub_4E2220(v5);
		v49 = v35 * (double)a4;
		nox_xxx_playerDecrementHPMana_4E20F0(v5, (int)&a1, v49);
		v33 = a4;
		nox_xxx_playerDamageItems_4E2180(v5, a2, a3, a4, a5);
		v34 = *(uint32_t*)(v5 + 8);
		if (v34 & 4) {
			if (!*(uint32_t*)(v12 + 304)) {
				v36 = a5;
				*(uint32_t*)(v12 + 304) = 2;
				*(float*)(v12 + 300) = v36;
			}
		} else if (v34 & 2 && !*(uint32_t*)(v12 + 2188)) {
			v37 = a5;
			*(uint32_t*)(v12 + 2188) = 2;
			*(float*)(v12 + 2184) = v37;
		}
		break;
	default:
		v33 = a4;
		a1 = a4;
		break;
	}
	if (v33 > 0 && !a1) {
		a1 = 1;
	}
	if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_GODMODE) && *(uint8_t*)(v5 + 8) & 4) {
		return 1;
	}
	if (nox_common_gameFlags_check_40A5C0(4096)) {
		v44 = a1;
		v52 = sub_4E40B0() * (double)a1;
		v45 = nox_float2int(v52);
		a1 = v45;
		if (v44 > 0 && v45 < 1) {
			v45 = 1;
			a1 = 1;
		}
	} else {
		v45 = a1;
	}
	return nox_xxx_damageDefaultProc_4E0B30(v5, a2, a3, v45, SLODWORD(a5));
}

//----- (004E20F0) --------------------------------------------------------
void nox_xxx_playerDecrementHPMana_4E20F0(int a1, int a2, float a3) {
	int v3;    // esi
	int v4;    // eax
	double v5; // st7
	int v6;    // eax
	int v7;    // eax
	int v8;    // [esp+Ch] [ebp+4h]

	v3 = a1;
	if (a1 && a2) {
		v4 = *(uint32_t*)(a1 + 8);
		if (v4 & 4) {
			v5 = a3 + *(float*)(*(uint32_t*)(a1 + 748) + 84);
		} else {
			if (!(v4 & 2)) {
				goto LABEL_8;
			}
			v5 = a3 + *(float*)(*(uint32_t*)(a1 + 748) + 4);
		}
		a3 = v5;
	LABEL_8:
		v6 = nox_float2int(a3);
		v8 = v6;
		*(uint32_t*)a2 = v6;
		v7 = *(uint32_t*)(v3 + 8);
		if (v7 & 4) {
			*(float*)(*(uint32_t*)(v3 + 748) + 84) = a3 - (double)v8;
		} else if (v7 & 2) {
			*(float*)(*(uint32_t*)(v3 + 748) + 4) = a3 - (double)v8;
		}
	}
}

//----- (004E2180) --------------------------------------------------------
void nox_xxx_playerDamageItems_4E2180(int a1, int a2, int a3, int a4, float a5) {
	int v5;       // edi
	int v6;       // eax
	uint32_t* v7; // esi
	int v8;       // ebx
	int v9;       // eax
	int v10;      // [esp+Ch] [ebp+4h]
	float v11;    // [esp+1Ch] [ebp+14h]

	v5 = a1;
	v6 = *(uint32_t*)(a1 + 8);
	if (v6 & 4) {
		v10 = *(int*)(*(uint32_t*)(a1 + 748) + 228);
	} else {
		if (!(v6 & 2) || !(*(uint8_t*)(a1 + 12) & 0x10)) {
			return;
		}
		v10 = *(int*)(*(uint32_t*)(a1 + 748) + 2072);
	}
	v7 = *(uint32_t**)(v5 + 504);
	if (v7) {
		v8 = LODWORD(a5);
		do {
			if (v7[2] & 0x2000000) {
				v9 = v7[4];
				if (v9 & 0x100) {
					v11 = nox_xxx_itemApplyDefendEffect_415C00((int)v7) / *(float*)&v10 * (double)a4;
					nox_xxx_equipDamage_4E16D0((int)v7, v5, a2, a3, v11, v8);
				}
			}
			v7 = (uint32_t*)v7[124];
		} while (v7);
	}
}

//----- (004E2220) --------------------------------------------------------
double sub_4E2220(int a1) {
	int v1;    // esi
	int v2;    // eax
	double v3; // st7
	float v5;  // [esp+4h] [ebp-4h]

	v5 = 1.0;
	v1 = *(uint32_t*)(a1 + 504);
	if (!v1) {
		return 1.0;
	}
	do {
		if (*(uint32_t*)(v1 + 8) & 0x2000000) {
			if (*(uint8_t*)(v1 + 24) & 0x10) {
				v2 = *(uint32_t*)(v1 + 16);
				if (v2 & 0x100) {
					if (!sub_4133D0(v1)) {
						if (*(uint32_t*)(v1 + 12) & 0x2000000) {
							v3 = *getMemFloatPtr(0x587000, 201108);
						} else {
							v3 = sub_415BD0(v1);
						}
						v5 = v3 + v5;
					}
				}
			}
		}
		v1 = *(uint32_t*)(v1 + 496);
	} while (v1);
	return v5;
}

//----- (004E22A0) --------------------------------------------------------
int sub_4E22A0(int a1, int a2, int a3, int a4, float a5, int a6) {
	uint32_t* i; // esi
	int v7;      // eax

	for (i = *(uint32_t**)(a1 + 504); i; i = (uint32_t*)i[124]) {
		if (i[4] & 0x100 && a4 & i[3]) {
			break;
		}
	}
	v7 = a3;
	if (!a3) {
		v7 = a2;
	}
	nox_xxx_playerDamageWeapon_4E1560((int)i, a1, a2, v7, a5, a6);
	if (!(i[4] & 0x20)) {
		return 0;
	}
	if (*(uint8_t*)(a1 + 8) & 4) {
		nox_xxx_playerSetState_4FA020((uint32_t*)a1, 13);
	} else {
		nox_xxx_monsterPopAction_50A160(a1);
	}
	return 1;
}

//----- (004E2330) --------------------------------------------------------
int sub_4E2330(int a1, int a2, int a3, int a4, float a5, int a6) {
	uint32_t* i; // esi
	int v7;      // eax

	for (i = *(uint32_t**)(a1 + 504); i; i = (uint32_t*)i[124]) {
		if (i[4] & 0x100 && a4 & i[3]) {
			break;
		}
	}
	v7 = a3;
	if (!a3) {
		v7 = a2;
	}
	nox_xxx_equipDamage_4E16D0((int)i, a1, a2, v7, a5, a6);
	if (i == 0) {
		return 0;
	}
	if (!(i[4] & 0x20)) {
		return 0;
	}
	if (*(uint8_t*)(a1 + 8) & 4) {
		nox_xxx_playerSetState_4FA020((uint32_t*)a1, 13);
	} else {
		nox_xxx_monsterPopAction_50A160(a1);
	}
	return 1;
}

//----- (004E23C0) --------------------------------------------------------
int sub_4E23C0(int a1, int a2, int a3, int a4, int a5) {
	int result; // eax
	float v6;   // ecx
	float v7;   // eax
	int v8;     // edi
	float2 a3a; // [esp+10h] [ebp-8h]

	if (nox_xxx_testUnitBuffs_4FF350(a1, 23)) {
		if (!((unsigned char)nox_frame_xxx_2598000 & 3)) {
			nox_xxx_aud_501960(71, a1, 0, 0);
		}
		result = 1;
	} else if (a2 && (!a3 ? (v7 = *(float*)(a2 + 76), a3a.field_0 = *(float*)(a2 + 72), a3a.field_4 = v7)
						  : (v6 = *(float*)(a3 + 76), a3a.field_0 = *(float*)(a3 + 72), a3a.field_4 = v6),
					  nox_server_testTwoPointsAndDirection_4E6E50((float2*)(a1 + 56), *(short*)(a1 + 124), &a3a) & 1 &&
						  (v8 = *(uint32_t*)(a1 + 748), nox_xxx_mobActionGet_50A020(a1) == 21) &&
						  *(uint8_t*)(v8 + 481) > (unsigned int)(*(uint8_t*)(v8 + 480) >> 1))) {
		nox_xxx_aud_501960(878, a1, 0, 0);
		result = 1;
	} else {
		result = nox_xxx_damageDefaultProc_4E0B30(a1, a2, a3, a4, a5);
	}
	return result;
}

//----- (004E24B0) --------------------------------------------------------
int sub_4E24B0(int a1, int a2, int a3, int a4, int a5) { return nox_xxx_damageDefaultProc_4E0B30(a1, a2, a3, a4, a5); }

//----- (004E24E0) --------------------------------------------------------
int sub_4E24E0(int a1, int a2, int a3, int a4, int a5) {
	int v5; // eax

	if (a5 != 9 && a5 != 17) {
		v5 = a4;
	} else {
		v5 = 2 * a4;
	}
	return nox_xxx_damageDefaultProc_4E0B30(a1, a2, a3, v5, a5);
}

//----- (004E2520) --------------------------------------------------------
int nox_xxx_damageFlammable_4E2520(int a1, int a2, int a3, int a4, int a5) {
	int v5; // eax

	if (a5 == 1 || a5 == 12 || (v5 = a4, a5 == 7)) {
		v5 = 9999999;
	}
	return nox_xxx_damageDefaultProc_4E0B30(a1, a2, a3, v5, a5);
}

//----- (004E2560) --------------------------------------------------------
int nox_xxx_damageBlackPowder_4E2560(int a1, int a2, int a3, int a4, int a5) {
	int result; // eax

	if (a5 != 1 && a5 != 12 && a5 != 2 && a5) {
		result = 0;
	} else {
		result = nox_xxx_damageDefaultProc_4E0B30(a1, a2, a3, 999999, a5);
	}
	return result;
}

//----- (004E25A0) --------------------------------------------------------
int nox_xxx_gameSetWallsDamage_4E25A0(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x587000, 201112) = a1;
	return result;
}

//----- (004E25B0) --------------------------------------------------------
bool nox_xxx_mapDamageUnitsAround_4E25B0(int a1, float a2, float a3, int a4, int a5, int a6, int a7) {
	bool result; // al
	float4 a1a;  // [esp+0h] [ebp-3Ch]
	int4 v11;    // [esp+10h] [ebp-2Ch]
	int a3a[7];  // [esp+20h] [ebp-1Ch]

	a3a[6] = a7;
	a3a[3] = a4;
	a3a[5] = a6;
	a3a[4] = a5;
	a3a[0] = a1;
	*(float*)&a3a[2] = a3;
	if (a2 >= (double)a3) {
		*(float*)&a3a[1] = a2;
	} else {
		*(float*)&a3a[1] = a3;
	}
	a1a.field_0 = *(float*)a1 - *(float*)&a3a[1];
	a1a.field_4 = *(float*)(a1 + 4) - *(float*)&a3a[1];
	a1a.field_8 = *(float*)&a3a[1] + *(float*)a1;
	a1a.field_C = *(float*)&a3a[1] + *(float*)(a1 + 4);
	nox_xxx_getUnitsInRect_517C10(&a1a, nox_xxx_damageFn_4E2700, (int)a3a);
	v11.field_0 = nox_float2int(a1a.field_0) / 23;
	v11.field_4 = nox_float2int(a1a.field_4) / 23;
	v11.field_8 = nox_float2int(a1a.field_8) / 23;
	v11.field_C = nox_float2int(a1a.field_C) / 23;
	result = nox_xxx_mapDamageToWalls_534FC0(&v11, a1, a2, a4, a5, a6);
	*getMemU32Ptr(0x587000, 201112) = 1;
	return result;
}

//----- (004E2700) --------------------------------------------------------
void nox_xxx_damageFn_4E2700(float* a1, int a2) {
	int v2;         // esi
	float* v3;      // ecx
	double v4;      // st7
	double v5;      // st6
	long double v6; // st5
	float v7;       // edx
	float v8;       // eax
	long long v9;   // rax
	float4 v10;     // [esp+8h] [ebp-10h]
	float v11;      // [esp+20h] [ebp+8h]

	v2 = a2;
	if ((a1 != *(float**)(a2 + 20) || *getMemU32Ptr(0x587000, 201112)) && *(float**)(a2 + 24) != a1) {
		v3 = *(float**)a2;
		v4 = a1[14] - **(float**)a2;
		v5 = a1[15] - *(float*)(*(uint32_t*)a2 + 4);
		v6 = sqrt(v5 * v5 + v4 * v4);
		v11 = v6;
		if (v6 <= *(float*)(v2 + 4)) {
			v7 = a1[14];
			v10.field_0 = *v3;
			v8 = a1[15];
			v10.field_4 = v3[1];
			v10.field_8 = v7;
			v10.field_C = v8;
			if (nox_xxx_mapTraceRay_535250(&v10, 0, 0, 1)) {
				if (v11 >= (double)*(float*)(v2 + 8)) {
					v9 = (long long)((1.0 - (v11 - *(float*)(v2 + 8)) / (*(float*)(v2 + 4) - *(float*)(v2 + 8))) *
									 (double)*(int*)(v2 + 12));
				} else {
					LODWORD(v9) = *(uint32_t*)(v2 + 12);
				}
				(*((void (**)(float*, uint32_t, uint32_t, uint32_t, uint32_t))a1 + 179))(a1, *(uint32_t*)(v2 + 20), 0,
																						 v9, *(uint32_t*)(v2 + 16));
			}
		}
	}
}

//----- (004E27D0) --------------------------------------------------------
int nox_xxx_damageMonsterGen_4E27D0(int a1, int a2, int a3, int a4, int a5) {
	int v5;             // ebp
	int v7;             // edi
	int v8;             // eax
	unsigned short* v9; // eax
	int v10;            // edi
	int v11;            // eax
	int v12;            // eax
	int v13;            // eax
	float v14;          // [esp+0h] [ebp-1Ch]
	float v15;          // [esp+0h] [ebp-1Ch]
	float2 a1a;         // [esp+14h] [ebp-8h]
	int v17;            // [esp+28h] [ebp+Ch]

	v5 = *(uint32_t*)(a1 + 748);
	if (*(uint32_t*)(a1 + 16) & 0x8020) {
		return 0;
	}
	if ((unsigned int)(nox_frame_xxx_2598000 - *(uint32_t*)(a1 + 536)) > 0x14 || !(nox_frame_xxx_2598000 % 0x1Eu)) {
		if (a3) {
			a1a.field_0 = *(float*)(a3 + 56) - *(float*)(a1 + 56) + 0.0099999998;
			a1a.field_4 = *(float*)(a3 + 60) - *(float*)(a1 + 60) + 0.0099999998;
			nox_xxx_utilNormalizeVector_509F20(&a1a);
			a1a.field_0 = a1a.field_0 * 22.0 + *(float*)(a1 + 56);
			a1a.field_4 = a1a.field_4 * 22.0 + *(float*)(a1 + 60);
			sub_523150(240, 26, &a1a.field_0);
		} else {
			sub_523150(240, 26, (float*)(a1 + 56));
		}
		nox_xxx_aud_501960(1001, a1, 0, 0);
	}
	v7 = (unsigned short)nox_xxx_unitGetHP_4EE780(a1);
	v17 = nox_xxx_damageDefaultProc_4E0B30(a1, a2, a3, a4, a5);
	if ((unsigned short)nox_xxx_unitGetHP_4EE780(a1) < v7) {
		nox_xxx_scriptCallByEventBlock_502490((int*)(v5 + 48), a2, a1, 23);
	}
	v8 = *(uint32_t*)(a1 + 16);
	if ((v8 & 0x8000) == 0 && !(v8 & 0x20)) {
		v9 = *(unsigned short**)(a1 + 556);
		v10 = *v9;
		v14 = (double)v9[2] * 0.333;
		if (v10 > nox_float2int(v14)) {
			v15 = (double)*(unsigned short*)(*(uint32_t*)(a1 + 556) + 4) * 0.66600001;
			if (v10 <= nox_float2int(v15)) {
				v13 = *(uint32_t*)(a1 + 20);
				if (!(v13 & 0x100)) {
					nox_xxx_unitSetXStatus_4E4800(a1, (int*)0x100);
				}
			}
		} else {
			v11 = *(uint32_t*)(a1 + 20);
			if (v11 & 0x100) {
				nox_xxx_unitUnsetXStatus_4E4780(a1, 256);
			}
			v12 = *(uint32_t*)(a1 + 20);
			if (!(v12 & 0x200)) {
				nox_xxx_unitSetXStatus_4E4800(a1, (int*)0x200);
			}
		}
	}
	return v17;
}

//----- (004E30A0) --------------------------------------------------------
int nox_xxx_keyFirstLetterNumber_4E30A0(char* a1) {
	int result; // eax
	int v2;     // eax

	if (!a1) {
		return -1;
	}
	v2 = toupper(*a1);
	if (v2 < 65 || v2 > 90) {
		result = 26;
	} else {
		result = v2 - 65;
	}
	return result;
}

//----- (004E31A0) --------------------------------------------------------
int nox_xxx_unitDefProtectMB_4E31A0(int a1) {
	int result; // eax
	int v2;     // esi
	int v3;     // esi

	result = 0;
	if (a1) {
		LOWORD(result) = *(uint16_t*)a1;
		v2 = result ^ *(uint32_t*)(a1 + 16);
		v3 = sub_4E31E0((uint32_t*)(a1 + 20)) ^ v2;
		result = nox_xxx_protectionStringCRCLen_56FAE0(*(int**)(a1 + 4), strlen(*(const char**)(a1 + 4))) ^ v3;
	}
	return result;
}

//----- (004E31E0) --------------------------------------------------------
int sub_4E31E0(uint32_t* a1) {
	unsigned short* v1; // ecx
	int result;         // eax

	v1 = (unsigned short*)a1[29];
	result = *(unsigned short*)a1 ^ a1[3] ^ a1[4] ^ a1[9];
	if (v1) {
		result ^= *v1 ^ v1[2];
	}
	return result;
}

#ifndef NOX_CGO
//----- (004E3220) --------------------------------------------------------
int nox_thing_read_xxx_4E3220(nox_memfile* a1p, char* a2, nox_objectType_t* a3p) {
	int a1 = a1p;
	int a3 = a3p;
	char* v3;          // ebx
	unsigned char* v4; // eax
	char* v5;          // edi
	unsigned char* v6; // ebp
	int v7;            // eax
	char* v8;          // eax
	unsigned char v10; // [esp+18h] [ebp+8h]

	v3 = a2;
	while (1) {
	LABEL_2:
		v4 = *(unsigned char**)(a1 + 8);
		v10 = *v4;
		*(uint32_t*)(a1 + 8) = v4 + 1;
		if (!v10) {
			return 1;
		}
		nox_memfile_read(v3, 1u, v10, a1);
		v3[v10] = 0;
		v5 = strtok(v3, " \t\n\r");
		v6 = getMemAt(0x587000, 201392);
		if (*getMemU32Ptr(0x587000, 201396)) {
			while (strcmp(v5, *(const char**)v6)) {
				v7 = *((uint32_t*)v6 + 3);
				v6 += 8;
				if (!v7) {
					goto LABEL_2;
				}
			}
			v8 = strtok(0, "=");
			if (v8) {
				memmove(v3, v8 + 1, strlen(v8 + 1) + 1);
			}
			if (!(*((int (**)(int, int, char*))v6 + 1))(a3, a1, v3)) {
				return 0;
			}
		}
	}
}
#endif // NOX_CGO

//----- (004E3320) --------------------------------------------------------
void nox_xxx_unitDefFindMaxDataSize_4E3320() {
	int max = 0;
	for (nox_objectType_t* typ = nox_xxx_objectTypes_head_1563660; typ; typ = typ->next) {
		if (max < typ->field_36_size + typ->field_44_size + typ->data_update_size + typ->field_51_size) {
			max = typ->field_36_size + typ->field_44_size + typ->data_update_size + typ->field_51_size;
		}
	}
	// TODO: result is unused :/
}

//----- (004E3360) --------------------------------------------------------
int nox_xxx_allocClassArrayObjects_4E3360(unsigned int a1) {
	uint32_t* v1; // esi
	int v2;       // edi
	uint32_t* v4; // eax
	uint32_t* v5; // edi
	int v6;       // ebx
	uint64_t* v7; // eax

	v1 = 0;
	v2 = 1;
	nox_alloc_gameObject_1563344 = nox_new_alloc_class("objectMemClass", sizeof(nox_object_t), a1);
	if (!nox_alloc_gameObject_1563344) {
		return 0;
	}
	nox_alloc_class_obj_keep(nox_alloc_gameObject_1563344, 36); // keep unit ID assigned in the loop below
	if (!a1) {
		nox_alloc_class_reset_stats(nox_alloc_gameObject_1563344);
		return 1;
	}
	while (1) {
		v4 = nox_alloc_class_new_obj_zero(nox_alloc_gameObject_1563344);
		if (!v4) {
			break;
		}
		v4[9] = v2++;
		v4[111] = v1;
		v1 = v4;
		if (v2 - 1 >= a1) {
			do {
				v5 = v1;
				v1 = (uint32_t*)v1[111];
				v6 = v5[9];
				nox_alloc_class_free_obj_first(nox_alloc_gameObject_1563344, v5);
				v5[9] = v6;
			} while (v1);
			nox_alloc_class_reset_stats(nox_alloc_gameObject_1563344);
			return 1;
		}
	}
	while (v1) {
		v7 = v1;
		v1 = (uint32_t*)v1[111];
		nox_alloc_class_free_obj_first(nox_alloc_gameObject_1563344, v7);
	}
	return 0;
}

//----- (004E3420) --------------------------------------------------------
int nox_xxx_freeGameObjectClass_4E3420() {
	nox_free_alloc_class(nox_alloc_gameObject_1563344);
	return 1;
}

//----- (004E3450) --------------------------------------------------------
nox_object_t* nox_xxx_newObjectWithTypeInd_4E3450(int ind) {
	return nox_xxx_newObjectWithType_4E3470(*(uint32_t*)(*getMemU32Ptr(0x5D4594, 1563456) + 4 * ind));
}

//----- (004E3470) --------------------------------------------------------
nox_object_t* nox_xxx_newObjectWithType_4E3470(nox_objectType_t* typ) {
	void* v5; // eax
	int v8;   // eax
	int v9;   // [esp+10h] [ebp-4h]

	nox_object_t* ob = nox_alloc_class_new_obj(nox_alloc_gameObject_1563344);
	if (!ob) {
		return 0;
	}
	v9 = ob->field_9; // TODO: is it a really weird way to get random data?
	memset(ob, 0, sizeof(nox_object_t));
	ob->typ_ind = typ->field_5_0; // TODO: why is it setting it and then overwriting again?
	ob->obj_class = typ->obj_class;
	ob->field_3 = typ->field_7;
	ob->flags = typ->field_8;
	ob->field_5 = typ->field_9;
	ob->field_6_0 = typ->field_10;
	ob->field_7 = typ->field_11;
	ob->field_8 = typ->field_12;
	ob->float_28 = typ->field_13;
	ob->mass = typ->mass;
	memcpy(&ob->shape, &typ->shape, 0x3Cu); // TODO: this is larger than nox_shape
	if (!(ob->flags & 0x40)) {
		nox_xxx_objectUnkUpdateCoords_4E7290(ob);
	}
	ob->field_122_0 = typ->field_30_0;
	ob->field_122_2 = typ->field_30_2;
	ob->speed_cur = typ->speed;
	ob->float_137 = typ->field_32;
	ob->float_138 = typ->field_33;
	ob->field_139 = typ->field_34;
	ob->field_38 = -1;
	ob->typ_ind = typ->ind;
	if (typ->field_34) {
		ob->field_139 = calloc(1, 20);
		if (!ob->field_139) {
			return 0;
		}
		memcpy(ob->field_139, typ->field_34, 20);
	}
	ob->field_172 = typ->field_43;
	if (typ->field_44_size) {
		ob->field_173 = calloc(1, typ->field_44_size);
		if (!ob->field_173) {
			return 0;
		}
		memcpy(ob->field_173, typ->field_44, typ->field_44_size);
	}
	ob->field_174 = typ->field_35;
	if (typ->field_36_size) {
		ob->field_175 = calloc(1, typ->field_36_size);
		if (!ob->field_175) {
			return 0;
		}
		memcpy(ob->field_175, typ->field_36, typ->field_36_size);
	}
	ob->func_xfer = typ->func_xfer;
	ob->field_183 = typ->field_50;
	if (typ->field_51_size) {
		ob->field_184 = calloc(1, typ->field_51_size);
		if (!ob->field_184) {
			return 0;
		}
		memcpy(ob->field_184, typ->field_51, typ->field_51_size);
	}
	ob->func_update = typ->func_update;
	if (typ->data_update_size) {
		ob->data_update = calloc(1, typ->data_update_size);
		if (!ob->data_update) {
			return 0;
		}
		memcpy(ob->data_update, typ->data_update, typ->data_update_size);
	}
	ob->field_177 = typ->field_46;
	ob->field_178 = typ->field_42;
	ob->func_damage = typ->func_damage;
	ob->func_damage_sound = typ->func_damage_sound;
	ob->deleteOverride = typ->field_40;
	ob->field_190 = 0;
	ob->field_182 = typ->field_41;
	ob->field_192 = -1;
	ob->field_9 = v9;
	if (nox_common_gameFlags_check_40A5C0(6291456) &&
		(ob->obj_class & 0x20A02 || ob->func_xfer == nox_xxx_XFerInvLight_4F5AA0 || ob->field_122_0 != 0xff) &&
		(v5 = calloc(1u, 0xA0Cu), (ob->field_189 = v5) == 0)) {
		nox_xxx_objectFreeMem_4E38A0(ob);
		return 0;
	}
	if (typ->func_new) {
		typ->func_new(ob);
	}
	if (!nox_common_gameFlags_check_40A5C0(0x200000)) {
		ob->script_id = nox_server_NextObjectScriptID();
	}
	if (ob->obj_class & 0x100000) {
		++*getMemU32Ptr(0x5D4594, 1563888);
	} else if (ob->obj_class & 0x400000) {
		++*getMemU32Ptr(0x5D4594, 1563892);
	}
	v8 = *getMemU32Ptr(0x5D4594, 1563900) + 1;
	++*getMemU32Ptr(0x5D4594, 1563884);
	if (++*getMemU32Ptr(0x5D4594, 1563900) > *getMemIntPtr(0x5D4594, 1563896)) {
		*getMemU32Ptr(0x5D4594, 1563896) = v8;
	}
	return ob;
}

//----- (004E3810) --------------------------------------------------------
nox_object_t* nox_xxx_newObjectByTypeID_4E3810(const char* id) {
	nox_objectType_t* typ = nox_xxx_objectTypeByID_4E3830(id);
	if (!typ) {
		return 0;
	}
	return nox_xxx_newObjectWithType_4E3470(typ);
}

//----- (004E3830) --------------------------------------------------------
nox_objectType_t* nox_xxx_objectTypeByID_4E3830(const char* id) {
	if (!id) {
		return 0;
	}

	int v1 = nox_xxx_keyFirstLetterNumber_4E30A0(id);
	if (v1 < 0) {
		return 0;
	}

	int bucketSz = *getMemU32Ptr(0x5D4594, 1563668 + 4 * v1);
	if (bucketSz < 0) {
		return 0;
	}

	void* bucket = *(void**)getMemAt(0x5D4594, 1563348 + 4 * v1);
	if (!bucket) {
		return 0;
	}

	nox_objectType_t** v4 = bsearch(id, bucket, bucketSz, 4, nox_xxx_objBsearchFn_4E3880);
	if (!v4) {
		return 0;
	}

	return *v4;
}

//----- (004E3880) --------------------------------------------------------
int nox_xxx_objBsearchFn_4E3880(const void* a1, const void* a2) {
	return _strcmpi((const char*)a1, *(const char**)(*(uint32_t*)a2 + 4));
}

//----- (004E38A0) --------------------------------------------------------
int nox_xxx_objectFreeMem_4E38A0(int a1) {
	int* v1; // esi
	int v2;  // ebp
	int v3;  // edi
	int v4;  // eax
	int v5;  // esi
	int v6;  // esi

	if (*(uint32_t*)(a1 + 8) & 0x20000) {
		v1 = *(int**)(a1 + 748);
		v2 = 3;
		do {
			v3 = 4;
			do {
				if (*v1) {
					nox_xxx_objectFreeMem_4E38A0(*v1);
				}
				++v1;
				--v3;
			} while (v3);
			--v2;
		} while (v2);
	}
	if (!nox_common_gameFlags_check_40A5C0(0x200000)) {
		v4 = *(uint32_t*)(a1 + 504);
		if (v4) {
			do {
				v5 = *(uint32_t*)(v4 + 496);
				nox_xxx_objectFreeMem_4E38A0(v4);
				v4 = v5;
			} while (v5);
		}
	}
	if (*(uint32_t*)a1) {
		free(*(void**)a1);
	}
	if (*(uint32_t*)(a1 + 556)) {
		free(*(void**)(a1 + 556));
	}
	if (*(uint32_t*)(a1 + 760)) {
		free(*(void**)(a1 + 760));
	}
	if (*(uint32_t*)(a1 + 756)) {
		free(*(void**)(a1 + 756));
	}
	if (*(uint32_t*)(a1 + 692)) {
		free(*(void**)(a1 + 692));
	}
	if (*(uint32_t*)(a1 + 700)) {
		free(*(void**)(a1 + 700));
	}
	if (*(uint32_t*)(a1 + 736)) {
		free(*(void**)(a1 + 736));
	}
	if (*(uint32_t*)(a1 + 748)) {
		free(*(void**)(a1 + 748));
	}
	v6 = *(uint32_t*)(a1 + 36);
	nox_alloc_class_free_obj_last(nox_alloc_gameObject_1563344, a1);
	*(uint32_t*)(a1 + 36) = v6;
	return --*getMemU32Ptr(0x5D4594, 1563900);
}

//----- (004E39D0) --------------------------------------------------------
int nox_xxx_getUnitName_4E39D0(int a1) {
	return *(uint32_t*)(*(uint32_t*)(*getMemU32Ptr(0x5D4594, 1563456) + 4 * *(unsigned short*)(a1 + 4)) + 4);
}

//----- (004E3A80) --------------------------------------------------------
int nox_xxx_getUnitNameByThingType_4E3A80(int a1) {
	int result; // eax

	result = a1;
	if (a1) {
		result = *(uint32_t*)(*(uint32_t*)(*getMemU32Ptr(0x5D4594, 1563456) + 4 * a1) + 4);
	}
	return result;
}

//----- (004E3AA0) --------------------------------------------------------
int nox_xxx_getNameId_4E3AA0(char* a1) {
	unsigned short* v1; // eax
	int result;         // eax

	v1 = (unsigned short*)nox_xxx_objectTypeByID_4E3830(a1);
	if (v1) {
		result = *v1;
	} else {
		result = 0;
	}
	return result;
}

//----- (004E3AC0) --------------------------------------------------------
int nox_xxx_unitDefGetCount_4E3AC0() { return *getMemU32Ptr(0x587000, 201384); }

//----- (004E3AD0) --------------------------------------------------------
int sub_4E3AD0(int a1) {
	int v1;     // ecx
	int v2;     // eax
	int v3;     // ecx
	int result; // eax

	if (!*getMemU32Ptr(0x5D4594, 1563904)) {
		*getMemU32Ptr(0x5D4594, 1563904) = nox_xxx_getNameId_4E3AA0("Pixie");
	}
	v1 = *(uint32_t*)(*getMemU32Ptr(0x5D4594, 1563456) + 4 * a1);
	v2 = *(uint32_t*)(v1 + 24);
	result = 1;
	if (!(v2 & 1)) {
		if (v2 & 0x400000) {
			if (!(0x800000 & v2)) {
				v3 = *(uint32_t*)(v1 + 32);
				if (v3 & 0x40) {
					if (!(v3 & 0x10000)) {
						result = 0;
					}
				}
			}
		}
	}
	return result;
}

//----- (004E3B30) --------------------------------------------------------
nox_objectType_t* nox_xxx_getFirstObjectType_4E3B30() { return nox_xxx_objectTypes_head_1563660; }

//----- (004E3B40) --------------------------------------------------------
nox_objectType_t* nox_xxx_objectType_next_4E3B40(nox_objectType_t* typ) {
	if (!typ) {
		return 0;
	}
	return typ->next;
}

//----- (004E3B60) --------------------------------------------------------
nox_objectType_t* nox_xxx_objectTypeByID_4E3B60(char* id) { return nox_xxx_objectTypeByID_4E3830(id); }

//----- (004E3B70) --------------------------------------------------------
nox_objectType_t* nox_xxx_objectTypeByInd_4E3B70(int ind) {
	return *(uint32_t*)(*getMemU32Ptr(0x5D4594, 1563456) + 4 * ind);
}

//----- (004E3B80) --------------------------------------------------------
int sub_4E3B80(int a1) { return *(int*)(*(uint32_t*)(*getMemU32Ptr(0x5D4594, 1563456) + 4 * a1) + 12) != -1; }

//----- (004E3BA0) --------------------------------------------------------
int nox_xxx_getUnitDefDd10_4E3BA0(int a1) {
	return *(uint32_t*)(*(uint32_t*)(*getMemU32Ptr(0x5D4594, 1563456) + 4 * a1) + 16);
}

//----- (004E3BF0) --------------------------------------------------------
int sub_4E3BF0(int a1) {
	int result; // eax

	result = a1;
	dword_5d4594_1563664 ^= *(uint32_t*)(a1 + 16);
	*(uint32_t*)(a1 + 16) = 1;
	dword_5d4594_1563664 ^= 1u;
	return result;
}

//----- (004E3C20) --------------------------------------------------------
int nox_xxx_protectUnitDefUpdateMB_4E3C20() {
	int v0;     // edi
	void* i;    // esi
	int result; // eax

	v0 = 0;
	for (i = nox_xxx_getFirstObjectType_4E3B30(); i; i = (void*)nox_xxx_objectType_next_4E3B40((int)i)) {
		v0 ^= nox_xxx_unitDefProtectMB_4E31A0((int)i);
	}
	result = dword_5d4594_1563664;
	if (v0 != dword_5d4594_1563664) {
		nullsub_31(1);
	}
	return result;
}
// 560840: using guessed type void  nullsub_31(uint32_t);

//----- (004E3CA0) --------------------------------------------------------
double sub_4E3CA0() { return *getMemFloatPtr(0x587000, 202024); }

//----- (004E3CB0) --------------------------------------------------------
int sub_4E3CB0(float a1) {
	int result; // eax

	result = LODWORD(a1);
	*getMemFloatPtr(0x587000, 202024) = a1;
	return result;
}

//----- (004E3CC0) --------------------------------------------------------
int nox_game_getQuestStage_4E3CC0() { return *getMemU32Ptr(0x587000, 202028); }

//----- (004E3CD0) --------------------------------------------------------
void nox_game_setQuestStage_4E3CD0(int a1) { *getMemU32Ptr(0x587000, 202028) = a1; }

//----- (004E3CE0) --------------------------------------------------------
int nox_xxx_player_4E3CE0() {
	int v0; // ebp
	int v1; // esi
	int v2; // edi

	v0 = 0;
	v1 = nox_xxx_getFirstPlayerUnit_4DA7C0();
	if (!v1) {
		return 0;
	}
	do {
		v2 = *(uint32_t*)(v1 + 748);
		if ((!nox_common_gameFlags_check_40A5C0(1) ||
			 !nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) ||
			 *(uint8_t*)(*(uint32_t*)(v2 + 276) + 2064) != 31) &&
			*(uint32_t*)(*(uint32_t*)(v2 + 276) + 4792) == 1) {
			++v0;
		}
		v1 = nox_xxx_getNextPlayerUnit_4DA7F0(v1);
	} while (v1);
	return v0;
}

//----- (004E3D50) --------------------------------------------------------
int sub_4E3D50() {
	int v0;   // esi
	float v2; // [esp+0h] [ebp-8h]

	if (!*getMemU32Ptr(0x5D4594, 1563928)) {
		*getMemFloatPtr(0x5D4594, 1563912) = nox_xxx_gamedataGetFloat_419D40("PlayerDifficultyDelta");
		*getMemU32Ptr(0x5D4594, 1563928) = 1;
	}
	v0 = nox_xxx_player_4E3CE0();
	v2 = (double)(unsigned int)nox_game_getQuestStage_4E3CC0() *
		 ((double)(v0 - 1) * *getMemFloatPtr(0x5D4594, 1563912) + 1.0);
	return sub_4E3CB0(v2);
}

//----- (004E3DD0) --------------------------------------------------------
short sub_4E3DD0() {
	int v0;             // eax
	int v1;             // esi
	int v2;             // ebx
	int v3;             // ecx
	short v4;           // cx
	int v5;             // edi
	unsigned short v6;  // bp
	unsigned short v7;  // ax
	short v8;           // cx
	int v9;             // ebp
	int v10;            // ecx
	short v11;          // di
	short v12;          // ax
	int v13;            // ecx
	float v15;          // [esp+0h] [ebp-1Ch]
	float v16;          // [esp+0h] [ebp-1Ch]
	float v17;          // [esp+0h] [ebp-1Ch]
	float v18;          // [esp+0h] [ebp-1Ch]
	float v19;          // [esp+Ch] [ebp-10h]
	float v20;          // [esp+Ch] [ebp-10h]
	float v21;          // [esp+10h] [ebp-Ch]
	float v22;          // [esp+14h] [ebp-8h]
	unsigned short v23; // [esp+18h] [ebp-4h]

	v21 = nox_xxx_gamedataGetFloat_419D40("GeneratorMaxHealth");
	v23 = nox_float2int(v21);
	if (!*getMemU32Ptr(0x5D4594, 1563932)) {
		*getMemFloatPtr(0x5D4594, 1563908) = nox_xxx_gamedataGetFloat_419D40("PlayerDamageDiffInit");
		*getMemFloatPtr(0x5D4594, 1563916) = nox_xxx_gamedataGetFloat_419D40("SystemHealthDiffInit");
		*getMemFloatPtr(0x5D4594, 1563920) = nox_xxx_gamedataGetFloat_419D40("PlayerDamageDiffCoeff");
		*getMemFloatPtr(0x5D4594, 1563924) = nox_xxx_gamedataGetFloat_419D40("SystemHealthDiffCoeff");
		*getMemU32Ptr(0x5D4594, 1563932) = 1;
	}
	v19 = (sub_4E3CA0() - 1.0) * *getMemFloatPtr(0x5D4594, 1563920) + *getMemFloatPtr(0x5D4594, 1563908);
	sub_4E4080(v19);
	v20 = (sub_4E3CA0() - 1.0) * *getMemFloatPtr(0x5D4594, 1563924) + *getMemFloatPtr(0x5D4594, 1563916);
	sub_4E40C0(v20);
	v0 = nox_server_getFirstObject_4DA790();
	v1 = v0;
	if (v0) {
		do {
			v2 = nox_server_getNextObject_4DA7A0(v1);
			v0 = *(uint32_t*)(v1 + 8);
			if (v0 & 0x20000 && (v3 = *(uint32_t*)(v1 + 16), (v3 & 0x8000) == 0)) {
				v0 = *(uint32_t*)(v1 + 556);
				v4 = *(uint16_t*)(v0 + 4);
				if (v4) {
					LOWORD(v0) = *(uint16_t*)v0;
					if ((uint16_t)v0) {
						if ((uint16_t)v0 == v4) {
							v5 = nox_xxx_objectTypeByInd_4E3B70(*(unsigned short*)(v1 + 4));
							v15 = sub_4E40F0() * (double)*(unsigned short*)(*(uint32_t*)(v5 + 136) + 4);
							v6 = nox_float2int16_abs(v15);
							v16 = sub_4E40F0() * (double)**(unsigned short**)(v5 + 136);
							v7 = nox_float2int16_abs(v16);
							if (!v7) {
								v7 = 1;
							}
							if (!v6) {
								v6 = 1;
							}
							if (v7 > v23) {
								v7 = v23;
							}
							if (v6 > v23) {
								v6 = v23;
							}
							LOWORD(v0) = nox_xxx_unitSetHP_4E4560(v1, v7);
							*(uint16_t*)(*(uint32_t*)(v1 + 556) + 4) = v6;
						}
					}
				}
			} else if (v0 & 2) {
				v0 = *(uint32_t*)(v1 + 16);
				if ((v0 & 0x8000) == 0) {
					v0 = *(uint32_t*)(v1 + 556);
					v8 = *(uint16_t*)(v0 + 4);
					if (v8) {
						LOWORD(v0) = *(uint16_t*)v0;
						if ((uint16_t)v0) {
							if ((uint16_t)v0 == v8) {
								v0 = nox_xxx_objectTypeByInd_4E3B70(*(unsigned short*)(v1 + 4));
								v9 = *(uint32_t*)(v1 + 748);
								v10 = *(uint32_t*)(v9 + 484);
								LOWORD(v0) = v10 ? *(uint16_t*)(v10 + 72) : *(uint16_t*)(*(uint32_t*)(v0 + 136) + 4);
								if ((signed char)*(uint8_t*)(v9 + 1440) >= 0) {
									v22 = (double)(unsigned short)v0;
									v17 = sub_4E40F0() * v22;
									v11 = nox_float2int16_abs(v17);
									v18 = sub_4E40F0() * v22;
									v12 = nox_float2int16_abs(v18);
									if (!v12) {
										v12 = 1;
									}
									if (!v11) {
										v11 = 1;
									}
									nox_xxx_unitSetHP_4E4560(v1, v12);
									v0 = v9 + 412;
									v13 = 32;
									*(uint16_t*)(*(uint32_t*)(v1 + 556) + 4) = v11;
									do {
										v0 += 2;
										--v13;
										*(uint16_t*)(v0 - 2) = **(uint16_t**)(v1 + 556);
									} while (v13);
								}
							}
						}
					}
				}
			}
			v1 = v2;
		} while (v2);
	}
	return v0;
}

//----- (004E4080) --------------------------------------------------------
void sub_4E4080(float a1) {
	double v1; // st7

	v1 = nox_xxx_gamedataGetFloat_419D40("PlayerDamageCap");
	if (a1 <= v1) {
		*getMemFloatPtr(0x587000, 202032) = a1;
	} else {
		*getMemFloatPtr(0x587000, 202032) = v1;
	}
}

//----- (004E40B0) --------------------------------------------------------
double sub_4E40B0() { return *getMemFloatPtr(0x587000, 202032); }

//----- (004E40C0) --------------------------------------------------------
void sub_4E40C0(float a1) {
	double v1; // st7

	v1 = nox_xxx_gamedataGetFloat_419D40("SystemHealthCap");
	if (a1 <= v1) {
		*getMemFloatPtr(0x587000, 202036) = a1;
	} else {
		*getMemFloatPtr(0x587000, 202036) = v1;
	}
}

//----- (004E40F0) --------------------------------------------------------
double sub_4E40F0() { return *getMemFloatPtr(0x587000, 202036); }

//----- (004E4100) --------------------------------------------------------
int sub_4E4100() {
	unsigned int v0; // ebp
	int v1;          // esi
	int v2;          // edi
	int result;      // eax

	v0 = 0;
	v1 = nox_xxx_getFirstPlayerUnit_4DA7C0();
	if (!v1) {
		return 1;
	}
	do {
		v2 = *(uint32_t*)(v1 + 748);
		if (!nox_common_gameFlags_check_40A5C0(1) ||
			!nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) ||
			*(uint8_t*)(*(uint32_t*)(v2 + 276) + 2064) != 31) {
			if (*(uint32_t*)(*(uint32_t*)(v2 + 276) + 4792)) {
				++v0;
			}
		}
		result = nox_xxx_getNextPlayerUnit_4DA7F0(v1);
		v1 = result;
	} while (result);
	if (v0 < 6) {
		return 1;
	}
	return result;
}

//----- (004E41B0) --------------------------------------------------------
int sub_4E41B0(char* a1) {
	FILE* v1; // edi

	v1 = nox_fs_open_text(a1);
	if (v1) {
		do {
			while (1) {
				do {
					if (!nox_fs_fgets(v1, (char*)getMemAt(0x5D4594, 1563936), 1024)) {
						nox_fs_close(v1);
						return 1;
					}
				} while (!strtok((char*)getMemAt(0x5D4594, 1563936), "\r\t\n"));
				if (strcmp((const char*)getMemAt(0x5D4594, 1563936), "[Banned Users]")) {
					break;
				}
				if (!sub_4E42C0(v1)) {
					goto LABEL_11;
				}
			}
		} while (strcmp((const char*)getMemAt(0x5D4594, 1563936), "[Allowed Users]") || sub_4E4390(v1));
	LABEL_11:
		nox_fs_close(v1);
	}
	return 0;
}

//----- (004E42C0) --------------------------------------------------------
int sub_4E42C0(FILE* a1) {
	char* v1;       // eax
	char* v2;       // eax
	wchar_t v4[26]; // [esp+Ch] [ebp-34h]

	while (1) {
		if (!nox_fs_fgets(a1, (char*)getMemAt(0x5D4594, 1563936), 1024)) {
			return 1;
		}
		v1 = strtok((char*)getMemAt(0x5D4594, 1563936), "\r\t\n");
		if (!v1) {
			return 1;
		}
		nox_swprintf(v4, L"%S", v1);
		if (!nox_fs_fgets(a1, (char*)getMemAt(0x5D4594, 1563936), 1024)) {
			return 1;
		}
		v2 = strtok((char*)getMemAt(0x5D4594, 1563936), "\r\t\n");
		if (!v2) {
			break;
		}
		if (!strcmp(v2, "0")) {
			sub_416770(0, v4, 0);
		} else {
			sub_416770(0, v4, v2);
		}
	}
	return 0;
}

//----- (004E4390) --------------------------------------------------------
int sub_4E4390(FILE* a1) {
	char* v1;       // eax
	wchar_t v3[26]; // [esp+4h] [ebp-34h]

	while (nox_fs_fgets(a1, (char*)getMemAt(0x5D4594, 1563936), 1024)) {
		v1 = strtok((char*)getMemAt(0x5D4594, 1563936), "\r\t\n");
		if (!v1) {
			break;
		}
		nox_swprintf(v3, L"%S", v1);
		sub_4168A0(v3);
	}
	return 1;
}

//----- (004E43F0) --------------------------------------------------------
FILE* sub_4E43F0(char* a1) {
	FILE* result; // eax
	FILE* v2;     // edi
	int* i;       // esi
	int* j;       // esi

	result = nox_fs_create_text(a1);
	v2 = result;
	if (result) {
		nox_fs_fprintf(result, "%s\n", getMemAt(0x587000, 202212));
		for (i = sub_416900(); i; i = sub_416910(i)) {
			if (!*((uint64_t*)i + 8)) {
				nox_fs_fprintf(v2, "%S\n", i + 3);
				if (*((uint8_t*)i + 72)) {
					nox_fs_fprintf(v2, "%s\n", i + 18);
				} else {
					nox_fs_fprintf(v2, "0\n");
				}
			}
		}
		nox_fs_fprintf(v2, "\n%s\n", getMemAt(0x587000, 202228));
		for (j = sub_4168E0(); j; j = sub_4168F0(j)) {
			nox_fs_fprintf(v2, "%S\n", j + 3);
		}
		nox_fs_close(v2);
		result = (FILE*)1;
	}
	return result;
}

//----- (004E44E0) --------------------------------------------------------
int nox_xxx_objectMakeUnseenByNoone_4E44E0(int a1) {
	int result; // eax

	result = a1;
	*(uint32_t*)(a1 + 152) = 0;
	return result;
}

//----- (004E44F0) --------------------------------------------------------
int nox_xxx_unitNeedSync_4E44F0(int a1) {
	int result; // eax

	result = a1;
	*(uint32_t*)(a1 + 152) = -1;
	return result;
}

//----- (004E4500) --------------------------------------------------------
int* sub_4E4500(int a1, int a2, int a3, int a4) {
	int v4;      // ecx
	int* result; // eax
	int v6;      // edx

	v4 = 0;
	result = (int*)(a1 + 560);
	do {
		if (a4) {
			*result |= a3;
		} else {
			*result &= ~a3;
		}
		v6 = *result;
		if ((1 << v4) & *(uint32_t*)(a1 + 148)) {
			*result = a2 | v6;
		} else if (!(v6 & a3)) {
			*result = v6 & ~a2;
		}
		++v4;
		++result;
	} while (v4 < 32);
	return result;
}

//----- (004E4560) --------------------------------------------------------
int nox_xxx_unitSetHP_4E4560(nox_object_t* obj, unsigned short amount) {
	int unit = obj;
	int healthData;      // eax
	int otherHealthData; // eax
	int unitFlags;       // eax
	int* v5;             // eax
	int counter;         // ecx
	int v7;              // edx
	int v8;              // eax

	healthData = *(uint32_t*)(unit + 556);
	if (healthData) {
		nox_xxx_unitNeedSync_4E44F0(unit);
		otherHealthData = *(uint32_t*)(unit + 492);
		if (otherHealthData && *(uint8_t*)(otherHealthData + 8) & 4) {
			nox_xxx_protect_56FC50(*(uint32_t*)(*(uint32_t*)(*(uint32_t*)(otherHealthData + 748) + 276) + 4632),
								   (int*)unit);
		}

		**(uint16_t**)(unit + 556) = amount;

		if (*(uint8_t*)(unit + 8) & 4) { // Is player and is local?
			nox_xxx_protectPlayerHPMana_56F870(*(uint32_t*)(*(uint32_t*)(*(uint32_t*)(unit + 748) + 276) + 4584),
											   amount);
		}

		unitFlags = *(uint32_t*)(unit + 8);                     // flags
		if (unitFlags & 2 && (*(uint8_t*)(unit + 12) & 0x80)) { // is owned monster ?
			if (unitFlags & 0x20400004) {
				v5 = (int*)(unit + 560);
				counter = 32;
				do {
					v7 = *v5;
					++v5;
					--counter;
					*(v5 - 1) = v7 & 0xFFFFF000 | 0x20000;
				} while (counter);
			} else {
				nox_xxx_objectTypeByInd_4E3B70(*(unsigned short*)(unit + 4));
				v8 = sub_4E4C90(unit, 2u);
				sub_4E4500(unit, 0x20000, 2, v8);
			}
		}

		healthData = *(uint32_t*)(unit + 492);
		if (healthData) {
			if (*(uint8_t*)(healthData + 8) & 4) {
				healthData = nox_xxx_protect_56FBF0(
					*(uint32_t*)(*(uint32_t*)(*(uint32_t*)(healthData + 748) + 276) + 4632), (int*)unit);
			}
		}
	}
	return healthData;
}

//----- (004E4670) --------------------------------------------------------
int* nox_xxx_unitSetOnOff_4E4670(int a1, int a2) {
	int v2;          // eax
	unsigned int v3; // eax
	int* result;     // eax
	int v5;          // ecx
	int v6;          // edx
	int v7;          // eax

	nox_xxx_unitNeedSync_4E44F0(a1);
	v2 = *(uint32_t*)(a1 + 16);
	if (a2) {
		v3 = v2 | 0x1000000;
	} else {
		v3 = v2 & 0xFEFFFFFF;
	}
	*(uint32_t*)(a1 + 16) = v3;
	if (*(uint32_t*)(a1 + 8) & 0x20400004) {
		result = (int*)(a1 + 560);
		v5 = 32;
		do {
			v6 = *result;
			++result;
			--v5;
			*(result - 1) = v6 & 0xFFFFF000 | 0x40000;
		} while (v5);
	} else {
		nox_xxx_objectTypeByInd_4E3B70(*(unsigned short*)(a1 + 4));
		v7 = sub_4E4C90(a1, 4u);
		result = sub_4E4500(a1, 0x40000, 4, v7);
	}
	return result;
}

//----- (004E46F0) --------------------------------------------------------
void nox_xxx_unitRaise_4E46F0(nox_object_t* obj, float a2) {
	int a1 = obj;
	int* v2; // eax
	int v3;  // ecx
	int v4;  // edx
	int v5;  // eax

	if (*(float*)(a1 + 104) != a2) {
		nox_xxx_unitNeedSync_4E44F0(a1);
		*(float*)(a1 + 104) = a2;
		if (*(uint32_t*)(a1 + 8) & 0x20400004) {
			v2 = (int*)(a1 + 560);
			v3 = 32;
			do {
				v4 = *v2;
				++v2;
				--v3;
				*(v2 - 1) = v4 & 0xFFFFF000 | 0x400000;
			} while (v3);
		} else {
			nox_xxx_objectTypeByInd_4E3B70(*(unsigned short*)(a1 + 4));
			v5 = sub_4E4C90(a1, 0x40u);
			sub_4E4500(a1, 0x400000, 64, v5);
		}
	}
}

//----- (004E4780) --------------------------------------------------------
int* nox_xxx_unitUnsetXStatus_4E4780(int a1, int a2) {
	int* result; // eax
	int v3;      // ecx
	int v4;      // edx
	int v5;      // eax

	result = *(int**)(a1 + 20);
	if ((unsigned int)result & a2) {
		*(uint32_t*)(a1 + 20) = (unsigned int)result & ~a2;
		if (a2 != 1) {
			nox_xxx_unitNeedSync_4E44F0(a1);
			if (*(uint32_t*)(a1 + 8) & 0x20400004) {
				result = (int*)(a1 + 560);
				v3 = 32;
				do {
					v4 = *result;
					++result;
					--v3;
					*(result - 1) = v4 & 0xFFFFF000 | 0x80000;
				} while (v3);
			} else {
				nox_xxx_objectTypeByInd_4E3B70(*(unsigned short*)(a1 + 4));
				v5 = sub_4E4C90(a1, 8u);
				result = sub_4E4500(a1, 0x80000, 8, v5);
			}
		}
	}
	return result;
}

//----- (004E4800) --------------------------------------------------------
int* nox_xxx_unitSetXStatus_4E4800(int a1, int* a2) {
	int* result; // eax
	int v3;      // ecx
	int v4;      // edx
	int v5;      // eax

	result = a2;
	*(uint32_t*)(a1 + 20) |= (unsigned int)a2;
	if (a2 != (int*)1) {
		nox_xxx_unitNeedSync_4E44F0(a1);
		if (*(uint32_t*)(a1 + 8) & 0x20400004) {
			result = (int*)(a1 + 560);
			v3 = 32;
			do {
				v4 = *result;
				++result;
				--v3;
				*(result - 1) = v4 & 0xFFFFF000 | 0x80000;
			} while (v3);
		} else {
			nox_xxx_objectTypeByInd_4E3B70(*(unsigned short*)(a1 + 4));
			v5 = sub_4E4C90(a1, 8u);
			result = sub_4E4500(a1, 0x80000, 8, v5);
		}
	}
	return result;
}

//----- (004E4880) --------------------------------------------------------
int* nox_xxx_servMarkObjAnimFrame_4E4880(int a1, int a2) {
	int* result; // eax
	int v3;      // ecx
	int v4;      // edx
	int v5;      // eax

	nox_xxx_unitNeedSync_4E44F0(a1);
	*(uint32_t*)(a1 + 132) = a2;
	if (*(uint32_t*)(a1 + 8) & 0x20400004) {
		result = (int*)(a1 + 560);
		v3 = 32;
		do {
			v4 = *result;
			++result;
			--v3;
			*(result - 1) = v4 & 0xFFFFF000 | 0x10000;
		} while (v3);
	} else {
		nox_xxx_objectTypeByInd_4E3B70(*(unsigned short*)(a1 + 4));
		v5 = sub_4E4C90(a1, 1u);
		result = sub_4E4500(a1, 0x10000, 1, v5);
	}
	return result;
}

//----- (004E48F0) --------------------------------------------------------
int* nox_xxx_setUnitBuffFlags_4E48F0(int a1, int a2) {
	char v2;     // cl
	int* result; // eax
	int v4;      // ecx
	int v5;      // edx
	int v6;      // eax

	nox_xxx_unitNeedSync_4E44F0(a1);
	v2 = *(uint8_t*)(a1 + 8);
	*(uint32_t*)(a1 + 340) = a2;
	if (v2 & 4) {
		nox_xxx_playerUpdateNetBuffs_56F7D0(*(uint32_t*)(*(uint32_t*)(*(uint32_t*)(a1 + 748) + 276) + 4612), a2);
	}
	if (*(uint32_t*)(a1 + 8) & 0x20400004) {
		result = (int*)(a1 + 560);
		v4 = 32;
		do {
			v5 = *result;
			++result;
			--v4;
			*(result - 1) = 0x800000 | v5 & 0xFFFFF000;
		} while (v4);
	} else {
		nox_xxx_objectTypeByInd_4E3B70(*(unsigned short*)(a1 + 4));
		v6 = sub_4E4C90(a1, 0x80u);
		result = sub_4E4500(a1, 0x800000, 128, v6);
	}
	return result;
}

//----- (004E4990) --------------------------------------------------------
int* nox_xxx_modifSetItemAttrs_4E4990(int a1, int* a2) {
	int v2;      // eax
	int v3;      // edx
	int* result; // eax
	int v5;      // ecx
	int v6;      // ecx
	int v7;      // edx
	int v8;      // eax

	v2 = *(uint32_t*)(a1 + 8);
	if (v2 & 0x1000 && *(uint32_t*)(a1 + 12) & 0x47F0000) {
		goto LABEL_19;
	}
	v3 = 0;
	result = a2;
	v5 = 4;
	do {
		if (*result) {
			v3 = 1;
		}
		++result;
		--v5;
	} while (v5);
	if (v3) {
	LABEL_19:
		result = *(int**)getMemAt(0x5D4594, 1564960);
		if (!*getMemU32Ptr(0x5D4594, 1564960)) {
			result = (int*)nox_xxx_getNameId_4E3AA0("TeamBase");
			*getMemU32Ptr(0x5D4594, 1564960) = result;
		}
		if (*(uint32_t*)(a1 + 8) & 0x13001000 || (int*)*(unsigned short*)(a1 + 4) == result) {
			nox_xxx_unitNeedSync_4E44F0(a1);
			memcpy(*(void**)(a1 + 692), a2, 0x14u);
			if (*(uint32_t*)(a1 + 8) & 0x20400004) {
				result = (int*)(a1 + 560);
				v6 = 32;
				do {
					v7 = *result;
					++result;
					--v6;
					*(result - 1) = v7 & 0xFFFFF000 | 0x2000000;
				} while (v6);
			} else {
				v8 = sub_4E4C90(a1, 0x200u);
				result = sub_4E4500(a1, 0x2000000, 512, v8);
			}
		}
	}
	return result;
}

//----- (004E4A70) --------------------------------------------------------
double nox_xxx_objectGetMass_4E4A70(int a1) { return *(float*)(a1 + 120); }

//----- (004E4A80) --------------------------------------------------------
int sub_4E4A80(int a1) { return *(uint32_t*)(a1 + 340); }

//----- (004E4A90) --------------------------------------------------------
int* nox_xxx_setNPCColor_4E4A90(nox_object_t* a1p, unsigned char a2, int a3) {
	int a1 = a1p;
	int v3;      // edi
	int v4;      // eax
	int* result; // eax
	int v6;      // ecx
	int v7;      // edx
	int v8;      // eax

	v3 = *(uint32_t*)(a1 + 748);
	nox_xxx_unitNeedSync_4E44F0(a1);
	v4 = v3 + 2 * (a2 + 692) + a2 + 692;
	*(uint16_t*)v4 = *(uint16_t*)a3;
	*(uint8_t*)(v4 + 2) = *(uint8_t*)(a3 + 2);
	if (*(uint32_t*)(a1 + 8) & 0x20400004) {
		result = (int*)(a1 + 560);
		v6 = 32;
		do {
			v7 = *result;
			++result;
			--v6;
			*(result - 1) = v7 & 0xFFFFF000 | 0x4000000;
		} while (v6);
	} else {
		v8 = sub_4E4C90(a1, 0x400u);
		result = sub_4E4500(a1, 0x4000000, 1024, v8);
	}
	return result;
}

//----- (004E4B20) --------------------------------------------------------
int* nox_xxx_npcSetItemEquipFlags_4E4B20(int a1, nox_object_t* item, int a3) {
	int v3;      // esi
	int v4;      // ecx
	int v5;      // ecx
	int* result; // eax
	int v7;      // ecx
	int v8;      // edx

	v3 = *(uint32_t*)(a1 + 748);
	nox_xxx_unitNeedSync_4E44F0(a1);
	v4 = *(uint32_t*)&item->obj_class;
	if (a3 == 1) {
		if (v4 & 0x1001000) {
			*(uint32_t*)(v3 + 2056) |= nox_xxx_weaponInventoryEquipFlags_415820(item);
			goto LABEL_9;
		}
		v5 = nox_xxx_unitArmorInventoryEquipFlags_415C70(item) | *(uint32_t*)(v3 + 2060);
	} else {
		if (v4 & 0x1001000) {
			*(uint32_t*)(v3 + 2056) &= ~nox_xxx_weaponInventoryEquipFlags_415820(item);
			goto LABEL_9;
		}
		v5 = ~nox_xxx_unitArmorInventoryEquipFlags_415C70(item) & *(uint32_t*)(v3 + 2060);
	}
	*(uint32_t*)(v3 + 2060) = v5;
LABEL_9:
	if (!(*(uint32_t*)(a1 + 8) & 0x20400004)) {
		return sub_4E4500(a1, 0x4000000, 1024, 1);
	}
	result = (int*)(a1 + 560);
	v7 = 32;
	do {
		v8 = *result;
		++result;
		--v7;
		*(result - 1) = v8 & 0xFFFFF000 | 0x4000000;
	} while (v7);
	return result;
}

//----- (004E4C00) --------------------------------------------------------
int sub_4E4C00(nox_object_t* item) {
	int result; // eax

	if (item) {
		result = *(uint32_t*)&item->field_9;
	} else {
		result = 0;
	}
	return result;
}

//----- (004E4C10) --------------------------------------------------------
int sub_4E4C10(nox_object_t* item) {
	int result; // eax

	if (item) {
		result = *(unsigned short*)&item->typ_ind;
	} else {
		result = 0;
	}
	return result;
}

//----- (004E4C30) --------------------------------------------------------
int sub_4E4C30(nox_object_t* item) {
	int result; // eax

	if (item) {
		result = *(uint32_t*)&item->field_173;
	} else {
		result = 0;
	}
	return result;
}

//----- (004E4C50) --------------------------------------------------------
int sub_4E4C50(nox_object_t* item) {
	int v1;     // eax
	int result; // eax

	if (item && (v1 = nox_xxx_objectTypeByInd_4E3B70(*(unsigned short*)&item->typ_ind)) != 0) {
		result = *(uint32_t*)(v1 + 180);
	} else {
		result = 0;
	}
	return result;
}

//----- (004E4C80) --------------------------------------------------------
int sub_4E4C80(nox_object_t* item) {
	const int* a1 = (int*)item;
	int result; // eax

	if (item) {
		result = *a1; // item->id?
	} else {
		result = 0;
	}
	return result;
}

//----- (004E4C90) --------------------------------------------------------
int sub_4E4C90(int a1, unsigned int a2) {
	uint32_t* v2; // eax
	int result;   // eax
	uint16_t* v4; // esi
	uint16_t* v5; // eax

	v2 = (uint32_t*)nox_xxx_objectTypeByInd_4E3B70(*(unsigned short*)(a1 + 4));
	if (a2 > 0x20) {
		if (a2 > 0x200) {
			if (a2 == 1024 && *(uint8_t*)(a1 + 8) & 2 && *(uint8_t*)(a1 + 12) & 0x30) {
				return 1;
			}
		} else {
			switch (a2) {
			case 0x200u:
				return (*(uint32_t*)(a1 + 8) & 0x13001000) != 0;
			case 0x40u:
				if (*(float*)(a1 + 104) != 0.0) {
					return 1;
				}
				break;
			case 0x80u:
				return *(uint32_t*)(a1 + 340) != 0;
			}
		}
		return 0;
	}
	if (a2 == 32) {
		return 0;
	}
	switch (a2) {
	case 1u:
		result = *(uint32_t*)(a1 + 132) != 0;
		break;
	case 2u:
		v4 = *(uint16_t**)(a1 + 556);
		if (!v4) {
			return 0;
		}
		v5 = (uint16_t*)v2[34];
		if (!v5) {
			return 0;
		}
		result = *v5 != *v4;
		break;
	case 4u:
		result = ((unsigned int)(*(uint32_t*)(a1 + 16) ^ v2[8]) >> 24) & 1;
		break;
	case 8u:
		result = v2[9] != *(uint32_t*)(a1 + 20);
		break;
	default:
		return 0;
	}
	return result;
}

//----- (004E4DE0) --------------------------------------------------------
int sub_4E4DE0() {
	int v0;            // edi
	unsigned char* v1; // esi
	int result;        // eax

	if (*getMemU32Ptr(0x5D4594, 1565508)) {
		nox_free_alloc_class(*(void**)getMemAt(0x5D4594, 1565508));
	}
	*getMemU32Ptr(0x5D4594, 1565508) = 0;
	memset(getMemAt(0x5D4594, 1565524), 0, 0x40u);
	memset(getMemAt(0x5D4594, 1565124), 0, 0x180u);
	dword_5d4594_1565512 = 0;
	dword_5d4594_1565516 = 0;
	v0 = 0;
	v1 = getMemAt(0x5D4594, 1565124);
	do {
		v1[1] = 2;
		*v1 = 1;
		v1[2] = nox_xxx_rateGet_40A6C0();
		result = sub_4E4E50(v0);
		v1 += 12;
		++v0;
	} while ((int)v1 < (int)getMemAt(0x5D4594, 1565508));
	return result;
}

//----- (004E4E50) --------------------------------------------------------
int sub_4E4E50(int a1) {
	unsigned int v1;   // esi
	unsigned char v2;  // bl
	unsigned char* v3; // ecx
	int result;        // eax

	v1 = 1;
	if (dword_5d4594_2650652 == 1) {
		v1 = nox_xxx_rateGet_40A6C0();
	}
	v2 = getMemByte(0x5D4594, 1565125 + 12 * a1);
	v3 = getMemAt(0x5D4594, 1565124 + 12 * a1);
	if (v2 > 2u) {
		*((uint32_t*)v3 + 2) = *v3 * (v2 - 1) * (nox_gameFPS / v1);
	} else {
		*((uint32_t*)v3 + 2) = 0;
	}
	result = v2 * *v3 * (nox_gameFPS / v1);
	*((uint32_t*)v3 + 1) = result;
	return result;
}

//----- (004E4ED0) --------------------------------------------------------
int sub_4E4ED0() {
	int result; // eax

	result = 0;
	memset(getMemAt(0x5D4594, 1565524), 0, 0x40u);
	return result;
}

//----- (004E4EF0) --------------------------------------------------------
int sub_4E4EF0() {
	unsigned char* v0; // esi
	int v1;            // edi
	int result;        // eax

	v0 = getMemAt(0x5D4594, 1565124);
	memset(getMemAt(0x5D4594, 1565124), 0, 0x180u);
	v1 = 0;
	do {
		v0[1] = 2;
		*v0 = 1;
		v0[2] = nox_xxx_rateGet_40A6C0();
		result = sub_4E4E50(v1);
		v0 += 12;
		++v1;
	} while ((int)v0 < (int)getMemAt(0x5D4594, 1565508));
	return result;
}

//----- (004E4F30) --------------------------------------------------------
int sub_4E4F30(int a1) {
	int result; // eax

	result = a1;
	*getMemU16Ptr(0x5D4594, 1565524 + 2 * a1) = 0;
	return result;
}

//----- (004E4F40) --------------------------------------------------------
int nox_xxx_playerResetImportantCtr_4E4F40(int a1) {
	int v1; // esi

	v1 = 12 * a1;
	*getMemU8Ptr(0x5D4594, 1565125 + v1) = 2;
	*getMemU8Ptr(0x5D4594, 1565124 + v1) = 1;
	*getMemU8Ptr(0x5D4594, 1565126 + v1) = nox_xxx_rateGet_40A6C0();
	return sub_4E4E50(a1);
}

//----- (004E4F80) --------------------------------------------------------
int sub_4E4F80() {
	int result;       // eax
	unsigned char v1; // cl
	int v2;           // esi

	result = dword_5d4594_1565512;
	if (dword_5d4594_1565512) {
		do {
			v1 = *(uint8_t*)(result + 251);
			v2 = *(uint32_t*)(result + 408);
			if (v1 >= 0x31u && v1 <= 0x33u) {
				sub_4E4FC0(result);
			}
			result = v2;
		} while (v2);
	}
	return result;
}

//----- (004E4FC0) --------------------------------------------------------
void sub_4E4FC0(int a1) {
	int v1; // ecx
	int v2; // ecx

	v1 = *(uint32_t*)(a1 + 412);
	if (v1) {
		*(uint32_t*)(v1 + 408) = *(uint32_t*)(a1 + 408);
	} else {
		dword_5d4594_1565512 = *(uint32_t*)(a1 + 408);
	}
	v2 = *(uint32_t*)(a1 + 408);
	if (v2) {
		*(uint32_t*)(v2 + 412) = *(uint32_t*)(a1 + 412);
	} else {
		dword_5d4594_1565516 = *(uint32_t*)(a1 + 412);
	}
	nox_alloc_class_free_obj_first(*(unsigned int**)getMemAt(0x5D4594, 1565508), (uint64_t*)a1);
}

//----- (004E5030) --------------------------------------------------------
int nox_xxx_netSendPacket_4E5030(int a1, const void* a2, signed int a3, int a4, int a5, char a6) {
	char* v7;           // eax
	char* v8;           // edx
	uint16_t* v9;       // esi
	char v10;           // cl
	unsigned char* v11; // eax
	unsigned char* v12; // eax
	int v13;            // edi
	int v14;            // ecx

	if (a1 == 255 || (a1 & 0x80u) == 0 || dword_5d4594_2649712 & ~(1 << (a1 & 0x7F))) {
		if (a3 > 150) {
			return 0;
		}
		v7 = *(char**)getMemAt(0x5D4594, 1565508);
		if (!*getMemU32Ptr(0x5D4594, 1565508)) {
			if (nox_common_gameFlags_check_40A5C0(2048)) {
				dword_5d4594_1565520 = 512;
			} else {
				dword_5d4594_1565520 = nox_common_gameFlags_check_40A5C0(1) ? 3072 : 256;
			}
			if (nox_common_gameFlags_check_40A5C0(2048)) {
				v7 = nox_new_alloc_class_dynamic("importantClass", 416, *(int*)&dword_5d4594_1565520);
			} else {
				v7 = nox_new_alloc_class("importantClass", 416, *(int*)&dword_5d4594_1565520);
			}
			*getMemU32Ptr(0x5D4594, 1565508) = v7;
		}
		v8 = (char*)nox_alloc_class_new_obj_zero(v7);
		if (!v8) {
			if (nox_xxx_importantCheckRate_4E52B0() != 1) {
				return 0;
			}
			v8 = (char*)nox_alloc_class_new_obj_zero(*(uint32_t**)getMemAt(0x5D4594, 1565508));
			if (!v8) {
				return 0;
			}
		}
		memcpy(v8 + 251, a2, a3);
		v8[401] = a3;
		*((uint32_t*)v8 + 101) = a4;
		v8[250] = a1;
		*((uint32_t*)v8 + 45) = a5;
		v8[184] = a6;
		*((uint32_t*)v8 + 43) = 0;
		*((uint32_t*)v8 + 42) = 0;
		v8[164] = 0;
		*((uint32_t*)v8 + 44) = dword_5d4594_2649712;
		memset(v8 + 4, 0, 0x80u);
		v9 = v8 + 186;
		*(uint32_t*)v8 = nox_frame_xxx_2598000;
		memset(v8 + 186, 0, 0x40u);
		if (v8[184]) {
			if (a1 == 255) {
				v10 = 0;
				v11 = getMemAt(0x5D4594, 1565524);
				do {
					if ((1 << v10) & *((uint32_t*)v8 + 44)) {
						*v9 = (*(uint16_t*)v11)++;
					}
					v11 += 2;
					++v10;
					++v9;
				} while ((int)v11 < (int)getMemAt(0x5D4594, 1565588));
			} else if ((a1 & 0x80u) == 0) {
				*(uint16_t*)&v8[2 * a1 + 186] = (*getMemU16Ptr(0x5D4594, 1565524 + 2 * a1))++;
			} else {
				v12 = getMemAt(0x5D4594, 1565524);
				v13 = v8[250] & 0x7F;
				v14 = 0;
				do {
					if (v14 != v13 && (1 << v14) & *((uint32_t*)v8 + 44)) {
						*v9 = (*(uint16_t*)v12)++;
					}
					v12 += 2;
					++v14;
					++v9;
				} while ((int)v12 < (int)getMemAt(0x5D4594, 1565588));
			}
		}
		*((uint32_t*)v8 + 103) = 0;
		*((uint32_t*)v8 + 102) = dword_5d4594_1565512;
		if (dword_5d4594_1565512) {
			*(uint32_t*)(dword_5d4594_1565512 + 412) = v8;
			dword_5d4594_1565512 = v8;
			return 1;
		}
		dword_5d4594_1565516 = v8;
		dword_5d4594_1565512 = v8;
	}
	return 1;
}

//----- (004E52B0) --------------------------------------------------------
int nox_xxx_importantCheckRate_4E52B0() {
	int v0;            // ebp
	int v1;            // edx
	int v2;            // ebx
	unsigned short v3; // si
	unsigned int v4;   // edi
	char v5;           // al
	int v6;            // eax
	short v8[32];      // [esp+10h] [ebp-40h]

	v0 = 0;
	v1 = dword_5d4594_1565512;
	v8[0] = 0;
	memset(&v8[1], 0, 0x3Cu);
	v2 = -1;
	v3 = 0;
	v8[31] = 0;
	v4 = 999999999;
	if (!dword_5d4594_1565512) {
		return 0;
	}
	do {
		v5 = *(uint8_t*)(v1 + 250);
		if (v5 != -1 && v5 >= 0 && v5 != 31) {
			v6 = *(unsigned char*)(v1 + 250);
			if ((unsigned short)++v8[v6] > v3) {
				v2 = v6;
				v3 = v8[v6];
			}
		}
		if (*(uint32_t*)v1 < v4) {
			v4 = *(uint32_t*)v1;
			v0 = v1;
		}
		v1 = *(uint32_t*)(v1 + 408);
	} while (v1);
	if (v2 != -1) {
		nullsub_24(getMemAt(0x587000, 202360));
		nox_xxx_playerKickDueToRate_4E5360(v2);
	}
	if (!v0) {
		return 0;
	}
	sub_4E4FC0(v0);
	return 1;
}
// 4E5AB0: using guessed type void  nullsub_24(uint32_t);

//----- (004E5360) --------------------------------------------------------
char* nox_xxx_playerKickDueToRate_4E5360(int a1) {
	char* result; // eax
	char* v2;     // esi

	result = nox_common_playerInfoFromNum_417090(a1);
	v2 = result;
	if (result) {
		sub_4E55F0(a1);
		result = (char*)nox_xxx_netNeedTimestampStatus_4174F0((int)v2, 128);
	}
	return result;
}

//----- (004E5390) --------------------------------------------------------
int nox_xxx_netSendPacket1_4E5390(int a1, int a2, int a3, int a4, int a5) {
	return nox_xxx_netSendPacket_4E5030(a1, (const void*)a2, a3, a4, a5, 1);
}

//----- (004E53C0) --------------------------------------------------------
int nox_xxx_netClientSend2_4E53C0(int a1, const void* a2, int a3, int a4, int a5) {
	int result; // eax

	if (nox_common_gameFlags_check_40A5C0(1)) {
		nox_netlist_addToMsgListCli_40EBC0(a1, 0, a2, a3);
		result = 1;
	} else if (a1 == 255 || (a1 & 0x80u) != 0) {
		result = 0;
	} else {
		result = nox_xxx_netSendPacket0_4E5420(a1, a2, a3, a4, a5);
	}
	return result;
}

//----- (004E5420) --------------------------------------------------------
int nox_xxx_netSendPacket0_4E5420(int a1, const void* a2, signed int a3, int a4, int a5) {
	return nox_xxx_netSendPacket_4E5030(a1, a2, a3, a4, a5, 0);
}

//----- (004E5450) --------------------------------------------------------
int sub_4E5450(int a1, char* a2, signed int a3, int a4, int a5) {
	char* v5; // edi
	int v6;   // eax
	int v7;   // esi
	char v9;  // [esp+10h] [ebp+8h]

	v5 = a2;
	v9 = *a2;
	v6 = dword_5d4594_1565512;
	if (dword_5d4594_1565512) {
		do {
			v7 = *(uint32_t*)(v6 + 408);
			if (v9 == *(uint8_t*)(v6 + 251)) {
				if (a1 == 255 || (a1 & 0x80u) != 0) {
					sub_4E4FC0(v6);
				} else {
					sub_4E54D0(1 << a1, v6, a1);
				}
			}
			v6 = v7;
		} while (v7);
	}
	return nox_xxx_netSendPacket0_4E5420(a1, v5, a3, a4, a5);
}

//----- (004E54D0) --------------------------------------------------------
void sub_4E54D0(int a1, int a2, int a3) {
	int v3;  // ecx
	char v4; // dl
	int v5;  // esi
	char v6; // cl
	int v7;  // ecx
	int v8;  // edx
	int v9;  // ecx

	v3 = *(uint32_t*)(a2 + 404);
	if (v3) {
		v4 = *(uint8_t*)(a2 + 251);
		if (v4 == 49 || v4 == 50 || v4 == 51) {
			*(uint32_t*)(v3 + 148) &= ~a1;
		}
	}
	v5 = dword_5d4594_2649712 & *(uint32_t*)(a2 + 176);
	v6 = *(uint8_t*)(a2 + 250);
	if (v6 == -1) {
		v7 = a1 | *(uint32_t*)(a2 + 168);
		*(uint32_t*)(a2 + 168) = v7;
		if ((v5 & v7) == v5) {
			sub_4E4FC0(a2);
		}
	} else if (v6 >= 0) {
		if (*(unsigned char*)(a2 + 250) == a3) {
			sub_4E4FC0(a2);
		}
	} else {
		v8 = 1 << (v6 & 0x7F);
		v9 = a1 | *(uint32_t*)(a2 + 168);
		*(uint32_t*)(a2 + 168) = v9;
		if ((v5 & ~v8 & v9) == (v5 & ~v8)) {
			sub_4E4FC0(a2);
		}
	}
}

//----- (004E55A0) --------------------------------------------------------
int sub_4E55A0(unsigned char a1, int a2) {
	int result; // eax
	int v3;     // edi

	result = dword_5d4594_1565512;
	if (dword_5d4594_1565512) {
		do {
			v3 = *(uint32_t*)(result + 408);
			if (*(uint32_t*)(result + 4 * a1 + 4) == a2) {
				sub_4E54D0(1 << a1, result, a1);
			}
			result = v3;
		} while (v3);
	}
	return result;
}

//----- (004E55F0) --------------------------------------------------------
int sub_4E55F0(unsigned char a1) {
	int result; // eax
	int v2;     // esi

	result = dword_5d4594_1565512;
	if (dword_5d4594_1565512) {
		do {
			v2 = *(uint32_t*)(result + 408);
			sub_4E54D0(1 << a1, result, a1);
			result = v2;
		} while (v2);
	}
	return result;
}

//----- (004E5630) --------------------------------------------------------
int sub_4E5630(unsigned char a1, uint32_t* a2, uint32_t* a3, uint32_t* a4) {
	int result; // eax

	result = 12 * a1;
	*a2 = *getMemU32Ptr(0x5D4594, 1565128 + result);
	*a3 = getMemByte(0x5D4594, 1565125 + result);
	*a4 = getMemByte(0x5D4594, 1565124 + result);
	return result;
}

//----- (004E5670) --------------------------------------------------------
unsigned int nox_xxx_importantCheckRate2_4E5670(unsigned char a1) {
	int v1;              // ebp
	int v2;              // eax
	int v3;              // ecx
	char v4;             // al
	unsigned char* v5;   // esi
	unsigned char v6;    // al
	unsigned int result; // eax
	int v8;              // eax
	unsigned char v9;    // al

	v1 = 0;
	nox_common_playerInfoFromNum_417090(a1);
	v2 = dword_5d4594_1565516;
	if (dword_5d4594_1565516) {
		do {
			v3 = *(uint32_t*)(v2 + 412);
			if (!(*(uint32_t*)(v2 + 168) & (1 << a1))) {
				v4 = *(uint8_t*)(v2 + 250);
				if (v4 == -1) {
					goto LABEL_8;
				}
				if (v4 >= 0) {
					if (v4 == a1) {
					LABEL_8:
						++v1;
						goto LABEL_9;
					}
				} else if (a1 != (v4 & 0x7F)) {
					goto LABEL_8;
				}
			}
		LABEL_9:
			v2 = v3;
		} while (v3);
	}
	v5 = getMemAt(0x5D4594, 1565124 + 12 * a1);
	if (nox_xxx_rateGet_40A6C0() != v5[2]) {
		v5[2] = nox_xxx_rateGet_40A6C0();
	}
	if (v1 <= *((uint32_t*)v5 + 1)) {
		v8 = *((uint32_t*)v5 + 2);
		if (v8 > 0 && v1 < v8) {
			if (*v5 == 2) {
				*v5 = 1;
				return sub_4E4E50(a1);
			}
			v9 = v5[1] - 1;
			v5[1] = v9;
			if (v9 < 2u) {
				v5[1] = 2;
			}
		}
		result = sub_4E4E50(a1);
	} else {
		v6 = v5[1] + 1;
		v5[1] = v6;
		if (v6 > 5u) {
			if (*v5 == 2) {
				nox_xxx_playerKickDueToRate_4E5360(a1);
			}
			v5[1] = 5;
			*v5 = 2;
		}
		v5[2] = nox_xxx_rateGet_40A6C0();
		result = sub_4E4E50(a1);
	}
	return result;
}

//----- (004DFB20) --------------------------------------------------------
int sub_4DFB20() { return *getMemU32Ptr(0x5D4594, 1563312); }

int nox_netlist_clientSendWrap_40ECA0(int ind1, int ind2, unsigned char* buf, int sz) {
	return nox_netlist_clientSend_0_40ECA0(ind1, ind2, buf, sz, sub_4DFB20());
}

//----- (004E5770) --------------------------------------------------------
void nox_xxx_netImportant_4E5770(unsigned char a1, int a2) {
	int v2;                                    // edi
	char* v3;                                  // esi
	int v4;                                    // ebp
	int v5;                                    // eax
	char v6;                                   // al
	int v7;                                    // eax
	char v8;                                   // al
	char v9;                                   // cl
	int v10;                                   // eax
	int v11;                                   // eax
	char v12[1];                               // [esp+13h] [ebp-1Dh]
	int (*v13)(int, int, unsigned char*, int); // [esp+14h] [ebp-1Ch]
	int v14;                                   // [esp+18h] [ebp-18h]
	int v15;                                   // [esp+1Ch] [ebp-14h]
	int v16;                                   // [esp+20h] [ebp-10h]
	int v17;                                   // [esp+24h] [ebp-Ch]
	char v18[5];                               // [esp+28h] [ebp-8h]

	v2 = 1 << a1;
	v15 = 1;
	v14 = 0;
	v16 = 1 << a1;
	v3 = nox_common_playerInfoFromNum_417090(a1);
	v13 = nox_netlist_addToMsgListCli_40EBC0;
	if (a1 != 31) {
		v13 = nox_netlist_clientSendWrap_40ECA0;
	}
	if (!v3 || !nox_common_gameFlags_check_40A5C0(1) || v3[3680] & 0x10) {
		v4 = dword_5d4594_1565516;
		if (dword_5d4594_1565516) {
			while (1) {
				v17 = *(uint32_t*)(v4 + 412);
				v5 = *(uint32_t*)(v4 + 404);
				if (v5 && *(uint8_t*)(v5 + 16) & 0x20) {
					*(uint32_t*)(v4 + 404) = 0;
				}
				if (v2 & *(uint32_t*)(v4 + 168)) {
					goto LABEL_39;
				}
				v6 = *(uint8_t*)(v4 + 250);
				if (v6 != -1) {
					if (v6 >= 0) {
						if (v6 != a1) {
							goto LABEL_39;
						}
					} else if (a1 == (v6 & 0x7F)) {
						goto LABEL_39;
					}
				}
				v7 = *(uint32_t*)(v4 + 404);
				if (v7 && !(v2 & *(uint32_t*)(v7 + 148)) || *(uint32_t*)(v4 + 180) && !(v2 & dword_5d4594_2649712)) {
					sub_4E54D0(v2, v4, a1);
					return;
				}
				if (!(v2 & *(uint32_t*)(v4 + 172))) {
					goto LABEL_24;
				}
				v8 = *(uint8_t*)(a1 + v4 + 132);
				if (v8) {
					*(uint8_t*)(a1 + v4 + 132) = v8 - 1;
					goto LABEL_39;
				}
				if (v14 < getMemByte(0x5D4594, 1565124 + 12 * a1)) {
					break;
				}
			LABEL_39:
				v4 = v17;
				if (!v17) {
					goto LABEL_40;
				}
			}
			v9 = *(uint8_t*)(v4 + 164) + 1;
			v10 = v14 + 1;
			*(uint32_t*)(v4 + 172) &= ~v2;
			*(uint8_t*)(v4 + 164) = v9;
			v14 = v10;
		LABEL_24:
			if (v15) {
				if (a2 && a1 != 31) {
					v12[0] = -86;
					if (!v13(a1, a2, v12, 1)) {
						return;
					}
				} else {
					v18[0] = -86;
					*(uint32_t*)&v18[1] = nox_frame_xxx_2598000;
					if (!v13(a1, a2, v18, 5)) {
						return;
					}
				}
				v15 = 0;
			}
			if (!*(uint8_t*)(v4 + 184)) {
				v11 = v13(a1, a2, (const void*)(v4 + 251), *(unsigned char*)(v4 + 401));
				goto LABEL_36;
			}
			if (true) { // TODO: byte_5D4594 != (unsigned char*)-1564964
				*getMemU8Ptr(0x5D4594, 1564964) = -52;
				*getMemU16Ptr(0x5D4594, 1564965) = *(uint16_t*)(v4 + 2 * a1 + 186);
				*getMemU8Ptr(0x5D4594, 1564967) = *(uint8_t*)(v4 + 401);
				memcpy(getMemAt(0x5D4594, 1564968), (const void*)(v4 + 251), *(unsigned char*)(v4 + 401));
				v11 = v13(a1, a2, getMemAt(0x5D4594, 1564964), *(unsigned char*)(v4 + 401) + 4);
				v2 = v16;
			LABEL_36:
				if (v11) {
					*(uint32_t*)(v4 + 172) |= v2;
					*(uint8_t*)(a1 + v4 + 132) =
						nox_gameFPS * (unsigned int)getMemByte(0x5D4594, 1565125 + 12 * a1) / nox_xxx_rateGet_40A6C0();
					*(uint32_t*)(v4 + 4 * a1 + 4) = nox_frame_xxx_2598000;
					if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_REPLAY_READ)) {
						sub_4E54D0(v2, v4, a1);
					}
				}
				goto LABEL_39;
			}
			goto LABEL_39;
		}
	LABEL_40:
		if (nox_common_gameFlags_check_40A5C0(1) &&
			!(nox_frame_xxx_2598000 % (nox_gameFPS * (unsigned int)getMemByte(0x5D4594, 1565125 + 12 * a1)))) {
			nox_xxx_importantCheckRate2_4E5670(a1);
		}
	}
}

//----- (004E5A90) --------------------------------------------------------
int nox_xxx_unused_4E5A90() {
	int v0; // eax
	int i;  // ecx

	v0 = dword_5d4594_1565512;
	for (i = 0; v0; ++i) {
		v0 = *(uint32_t*)(v0 + 408);
	}
	return dword_5d4594_1565520 - i;
}

//----- (004E5AD0) --------------------------------------------------------
void nox_xxx_playerRemoveSpawnedStuff_4E5AD0(int a1) {
	char v1; // al
	int v2;  // esi
	int v3;  // edi

	if (*(uint8_t*)(a1 + 8) & 4) {
		v1 = *(uint8_t*)(*(uint32_t*)(*(uint32_t*)(a1 + 748) + 276) + 2251);
		if (v1 == 1) {
			sub_4E5F40(a1);
		} else if (v1 == 2) {
			sub_4E5FC0(a1);
		}
	}
	v2 = *(uint32_t*)(a1 + 516);
	if (v2) {
		do {
			v3 = *(uint32_t*)(v2 + 512);
			if (*(uint8_t*)(v2 + 8) & 1 || !sub_4E3B80(*(unsigned short*)(v2 + 4))) {
				nox_xxx_delayedDeleteObject_4E5CC0(v2);
			}
			v2 = v3;
		} while (v3);
	}
}

//----- (004E5B50) --------------------------------------------------------
int nox_xxx_isUnit_4E5B50(nox_object_t* a1p) {
	int a1 = a1p;
	int v1;     // ecx
	int result; // eax

	result = 0;
	if (!nox_common_gameFlags_check_40A5C0(0x2000)) {
		if (*(uint8_t*)(a1 + 8) & 2) {
			v1 = *(uint32_t*)(a1 + 12);
			if (v1 & 0x100) {
				result = 1;
			}
		}
	}
	return result;
}

//----- (004E5B80) --------------------------------------------------------
int sub_4E5B80(nox_object_t* a1p) {
	int a1 = a1p;
	int v1;     // eax
	int result; // eax

	if (!*getMemU32Ptr(0x5D4594, 1565592)) {
		*getMemU32Ptr(0x5D4594, 1565592) = nox_xxx_getNameId_4E3AA0("Pixie");
	}
	result = 0;
	if (a1) {
		if (*(uint8_t*)(a1 + 8) & 1) {
			if (nox_common_gameFlags_check_40A5C0(2048)) {
				if (*(unsigned short*)(a1 + 4) == *getMemU32Ptr(0x5D4594, 1565592)) {
					v1 = nox_xxx_findParentChainPlayer_4EC580(a1);
					if (v1) {
						if (*(uint8_t*)(v1 + 8) & 4) {
							result = 1;
						}
					}
				}
			}
		}
	}
	return result;
}

//----- (004E5BF0) --------------------------------------------------------
void sub_4E5BF0(int a1) {
	int v1; // esi
	int v2; // edi
	int v3; // eax
	int v4; // eax

	if (!*getMemU32Ptr(0x5D4594, 1565596)) {
		*getMemU32Ptr(0x5D4594, 1565596) = nox_xxx_getNameId_4E3AA0("Moonglow");
	}
	v1 = nox_server_getFirstObject_4DA790();
	if (v1) {
		do {
			v2 = nox_server_getNextObject_4DA7A0(v1);
			if (!a1 || !(*(uint8_t*)(v1 + 8) & 4) &&
						   ((v3 = *(uint32_t*)(v1 + 492)) == 0 || !(*(uint8_t*)(v3 + 8) & 4)) &&
						   (*(unsigned short*)(v1 + 4) != *getMemU32Ptr(0x5D4594, 1565596) ||
							(v4 = *(uint32_t*)(v1 + 508)) == 0 || !(*(uint8_t*)(v4 + 8) & 4)) &&
						   !nox_xxx_isUnit_4E5B50(v1)) {
				nox_xxx_delayedDeleteObject_4E5CC0(v1);
			}
			v1 = v2;
		} while (v2);
	}
	nox_object_t* obj = nox_xxx_getFirstUpdatable2Object_4DA840();
	if (obj) {
		do {
			nox_object_t* v6 = nox_xxx_getNextUpdatable2Object_4DA850(obj);
			if (a1 != 1 || !sub_4E5B80(obj)) {
				nox_xxx_delayedDeleteObject_4E5CC0(obj);
			}
			obj = v6;
		} while (obj);
	}
}

//----- (004E5CC0) --------------------------------------------------------
void nox_xxx_delayedDeleteObject_4E5CC0(nox_object_t* obj) {
	int object = obj;
	int v1; // eax
	int v2; // eax

	if (object && !(*(uint8_t*)(object + 16) & 0x20)) {
		v1 = *(uint32_t*)(object + 508);
		if (v1 && *(uint8_t*)(v1 + 8) & 4 && *(uint8_t*)(object + 8) & 2 &&
			!nox_xxx_creatureIsMonitored_500CC0(v1, object) && (*(uint8_t*)(object + 12) & 0x80)) {
			nox_xxx_monsterRemoveMonitors_4E7B60(*(uint32_t*)(object + 508), (uint32_t*)object);
		}
		v2 = *(uint32_t*)(object + 492);
		if (v2) {
			sub_4ED0C0(v2, (int*)object);
		}
		nox_xxx_playerCancelSpells_4FEAE0(object);
		if (nox_common_gameFlags_check_40A5C0(4096) && *(uint8_t*)(object + 8) & 2) {
			sub_50E210(object);
		}
		if (*(uint8_t*)(object + 8) & 4) {
			sub_506740(object);
		}
		*(uint32_t*)(object + 16) |= 0x20u;
		*(uint32_t*)(object + 452) = *getMemU32Ptr(0x5D4594, 1565588);
		*getMemU32Ptr(0x5D4594, 1565588) = object;
		*(uint32_t*)(object + 456) = nox_frame_xxx_2598000;
		if (nox_xxx_servObjectHasTeam_419130(object + 48)) {
			nox_xxx_netChangeTeamMb_419570(object + 48, *(uint32_t*)(object + 36));
		}
	}
}

//----- (004E5E80) --------------------------------------------------------
int nox_xxx_unitDeleteFinish_4E5E80(uint32_t* a1) {
	nox_xxx_unitTransferSlaves_4EC4B0((int)a1);
	nox_xxx_unitClearOwner_4EC300((int)a1);
	nox_script_activatorClearObj_51AE60(a1);
	nox_xxx_decay_5116F0((int)a1);
	nox_xxx_dropAllItems_4EDA40(a1);
	nox_xxx_servFinalizeDelObject_4DADE0((int)a1);
	return nox_xxx_objectFreeMem_4E38A0((int)a1);
}

//----- (004E5EC0) --------------------------------------------------------
uint32_t* nox_xxx_finalizeDeletingUnits_4E5EC0() {
	uint32_t* result; // eax
	uint32_t* v1;     // esi

	result = *(uint32_t**)getMemAt(0x5D4594, 1565588);
	if (*getMemU32Ptr(0x5D4594, 1565588)) {
		do {
			v1 = (uint32_t*)result[113];
			nox_xxx_unitDeleteFinish_4E5E80(result);
			result = v1;
		} while (v1);
		*getMemU32Ptr(0x5D4594, 1565588) = 0;
	} else {
		*getMemU32Ptr(0x5D4594, 1565588) = 0;
	}
	return result;
}

//----- (004E5F00) --------------------------------------------------------
void sub_4E5F00(int (*a1)(int, int), int a2) {
	int i; // esi

	for (i = *getMemU32Ptr(0x5D4594, 1565588); i; i = *(uint32_t*)(i + 452)) {
		if (*(uint32_t*)(i + 456) != nox_frame_xxx_2598000) {
			a1(i, a2);
		}
	}
}

//----- (004E5F40) --------------------------------------------------------
int sub_4E5F40(int a1) {
	int result; // eax
	int i;      // esi

	if (!*getMemU32Ptr(0x5D4594, 1565600)) {
		*getMemU32Ptr(0x5D4594, 1565600) = nox_xxx_getNameId_4E3AA0("Glyph");
	}
	result = nox_server_getFirstObject_4DA790();
	for (i = result; result; i = result) {
		if (nox_xxx_unitHasThatParent_4EC4F0(i, a1) && *(unsigned short*)(i + 4) == *getMemU32Ptr(0x5D4594, 1565600) &&
			!(*(uint8_t*)(i + 16) & 0x20)) {
			nox_xxx_netSendPointFx_522FF0(129, (float2*)(i + 56));
			nox_xxx_delayedDeleteObject_4E5CC0(i);
		}
		result = nox_server_getNextObject_4DA7A0(i);
	}
	return result;
}

//----- (004E5FC0) --------------------------------------------------------
void sub_4E5FC0(int a1) {
	int v1; // ebx
	int v2; // ebp
	int v3; // esi
	int v4; // edi

	v1 = *(uint32_t*)(a1 + 516);
	if (v1) {
		do {
			v2 = *(uint32_t*)(v1 + 512);
			if (nox_xxx_creatureIsMonitored_500CC0(a1, v1)) {
				v3 = nox_xxx_inventoryGetFirst_4E7980(v1);
				if (v3) {
					do {
						v4 = nox_xxx_inventoryGetNext_4E7990(v3);
						nox_xxx_delayedDeleteObject_4E5CC0(v3);
						v3 = v4;
					} while (v4);
				}
				nox_xxx_netSendPointFx_522FF0(129, (float2*)(v1 + 56));
				nox_xxx_delayedDeleteObject_4E5CC0(v1);
			}
			v1 = v2;
		} while (v2);
	}
}

//----- (004E6040) --------------------------------------------------------
int nox_xxx_playerCameraUnlock_4E6040(int player) {
	int result; // eax

	result = player;
	*(uint32_t*)(*(uint32_t*)(*(uint32_t*)(player + 748) + 276) + 3628) = 0;
	return result;
}

//----- (004E6060) --------------------------------------------------------
int nox_xxx_playerCameraFollow_4E6060(int player, int unitId) {
	int result; // eax

	result = *(uint32_t*)(*(uint32_t*)(player + 748) + 276);
	if (*(uint32_t*)(result + 3628) == unitId) {
		return nox_xxx_playerCameraUnlock_4E6040(player);
	}
	*(uint32_t*)(result + 3628) = unitId;
	return result;
}

//----- (004E60A0) --------------------------------------------------------
char* nox_xxx_playerLeaveObsByObserved_4E60A0(int a1) {
	char* result; // eax
	int i;        // esi

	result = nox_common_playerInfoGetFirst_416EA0();
	for (i = (int)result; result; i = (int)result) {
		if (*(uint32_t*)(i + 3628) == a1) {
			nox_xxx_playerLeaveMonsterObserver_4E60E0(i);
		}
		result = nox_common_playerInfoGetNext_416EE0(i);
	}
	return result;
}

//----- (004E60E0) --------------------------------------------------------
int nox_xxx_playerLeaveMonsterObserver_4E60E0(int a1) {
	int result; // eax
	int v2;     // edi

	result = *(uint32_t*)(a1 + 2056);
	if (result) {
		if (nox_xxx_playerGetPossess_4DDF30(*(uint32_t*)(a1 + 2056))) {
			v2 = nox_xxx_playerObserverFindGoodSlave0_4E6280(a1);
			if (!v2) {
				return nox_xxx_playerObserveClear_4DDEF0(*(uint32_t*)(a1 + 2056));
			}
		} else {
			v2 = sub_4E6150(a1);
		}
		nox_xxx_playerCameraUnlock_4E6040(*(uint32_t*)(a1 + 2056));
		result = nox_xxx_playerCameraFollow_4E6060(*(uint32_t*)(a1 + 2056), v2);
	}
	return result;
}

//----- (004E6150) --------------------------------------------------------
int sub_4E6150(int a1) {
	int v1;     // eax
	int v2;     // eax
	int i;      // esi
	char* v4;   // eax
	int result; // eax
	char* v6;   // eax

	if (!dword_5d4594_1565616) {
		dword_5d4594_1565616 = nox_xxx_getNameId_4E3AA0("GameBall");
	}
	v1 = *(uint32_t*)(a1 + 3628);
	if (v1) {
		if (*(uint8_t*)(v1 + 8) & 4) {
			v2 = nox_xxx_getNextPlayerUnit_4DA7F0(*(uint32_t*)(a1 + 3628));
			goto LABEL_7;
		}
	} else if (nox_common_gameFlags_check_40A5C0(64)) {
		v2 = sub_4E6230();
		if (v2) {
			goto LABEL_7;
		}
	}
	v2 = nox_xxx_getFirstPlayerUnit_4DA7C0();
LABEL_7:
	i = v2;
	if (!v2) {
		goto LABEL_16;
	}
	if (*(uint8_t*)(v2 + 8) & 4) {
		while (1) {
			v4 = nox_common_playerInfoGetByID_417040(*(uint32_t*)(i + 36));
			if (!(*(uint8_t*)(i + 16) & 0x20) && !(v4[3680] & 1)) {
				break;
			}
			i = nox_xxx_getNextPlayerUnit_4DA7F0(i);
			if (!i) {
				goto LABEL_16;
			}
		}
	}
	if (!i) {
	LABEL_16:
		result = sub_4E6230();
		if (result) {
			return result;
		}
		for (i = nox_xxx_getFirstPlayerUnit_4DA7C0(); i; i = nox_xxx_getNextPlayerUnit_4DA7F0(i)) {
			v6 = nox_common_playerInfoGetByID_417040(*(uint32_t*)(i + 36));
			if (!(*(uint8_t*)(i + 16) & 0x20) && !(v6[3680] & 1)) {
				break;
			}
		}
	}
	return i;
}

//----- (004E6230) --------------------------------------------------------
int sub_4E6230() {
	int result; // eax

	if (!dword_5d4594_1565616) {
		dword_5d4594_1565616 = nox_xxx_getNameId_4E3AA0("GameBall");
	}
	result = nox_server_getFirstObject_4DA790();
	if (!result) {
		return 0;
	}
	while (*(unsigned short*)(result + 4) != dword_5d4594_1565616) {
		result = nox_server_getNextObject_4DA7A0(result);
		if (!result) {
			return 0;
		}
	}
	return result;
}

//----- (004E6280) --------------------------------------------------------
int nox_xxx_playerObserverFindGoodSlave0_4E6280(int a1) {
	int result; // eax

	if (*(uint32_t*)(a1 + 3628)) {
		result = nox_xxx_playerObserverFindGoodSlave_4EC420(*(uint32_t*)(a1 + 3628));
	} else {
		result = nox_xxx_playerObserverFindGoodSlave2_4EC3E0(*(uint32_t*)(a1 + 2056));
	}
	if (result) {
		while (*(uint32_t*)(result + 16) & 0x8020) {
			result = nox_xxx_playerObserverFindGoodSlave_4EC420(result);
			if (!result) {
				goto LABEL_9;
			}
		}
	} else {
	LABEL_9:
		for (result = nox_xxx_playerObserverFindGoodSlave2_4EC3E0(*(uint32_t*)(a1 + 2056)); result;
			 result = nox_xxx_playerObserverFindGoodSlave_4EC420(result)) {
			if (!(*(uint32_t*)(result + 16) & 0x8020)) {
				break;
			}
		}
	}
	return result;
}

//----- (004E62F0) --------------------------------------------------------
unsigned char* nox_xxx_updatePlayerObserver_4E62F0(int a1) {
	int v1;                // edi
	int v2;                // edx
	uint32_t* v3;          // eax
	int v4;                // esi
	int v5;                // eax
	int v6;                // eax
	int v7;                // eax
	unsigned char* result; // eax
	int v9;                // ebx
	double v10;            // st7
	bool v11;              // zf
	int v12;               // eax
	int v13;               // eax
	int v14;               // eax
	int v15;               // eax
	double v16;            // st7
	double v17;            // st7
	uint32_t* v18;         // [esp+10h] [ebp-28h]
	float v19;             // [esp+14h] [ebp-24h]
	float v20;             // [esp+18h] [ebp-20h]
	float v21;             // [esp+1Ch] [ebp-1Ch]
	float2 v22;            // [esp+20h] [ebp-18h]
	float4 a1a;            // [esp+28h] [ebp-10h]

	v1 = a1;
	v2 = 4;
	v3 = *(uint32_t**)(a1 + 748);
	v18 = v3;
	v4 = v3[69];
	v5 = (int)(v3 + 29);
	do {
		if (*(uint32_t*)v5 && *(uint8_t*)(*(uint32_t*)v5 + 16) & 0x20) {
			*(uint32_t*)v5 = 0;
		}
		v5 += 4;
		--v2;
	} while (v2);
	nox_xxx_unitNeedSync_4E44F0(a1);
	if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_REPLAY_READ)) {
		v6 = *(uint32_t*)(v4 + 3628);
		if (v6) {
			*(uint32_t*)(v4 + 3632) = *(uint32_t*)(v6 + 56);
			*(uint32_t*)(v4 + 3636) = *(uint32_t*)(v6 + 60);
		}
	}
	v7 = *(uint32_t*)(v4 + 3628);
	if (v7) {
		*(uint32_t*)(v4 + 3632) = *(uint32_t*)(v7 + 56);
		*(uint32_t*)(v4 + 3636) = *(uint32_t*)(v7 + 60);
	}
	result = nox_xxx_playerControlBufferFirst_51AB50(*(unsigned char*)(v4 + 2064));
	if (result) {
		*(uint32_t*)(v4 + 3688) = 0;
		result = nox_xxx_playerControlBufferFirst_51AB50(*(unsigned char*)(v4 + 2064));
		v9 = (int)result;
		if (result) {
			while (1) {
				if (*(uint32_t*)(v9 + 8) == 2) {
					v14 = *(uint32_t*)(v4 + 3672);
					if (v14) {
						if (v14 == 1) {
							v16 = *(float*)(v4 + 3632) - (double)*(int*)(v4 + 2284);
							v19 = *(float*)(v4 + 3636) - (double)*(int*)(v4 + 2288);
							if (v16 <= *(float*)&dword_587000_202404) {
								if (v16 >= -*(float*)&dword_587000_202404) {
									v20 = *(float*)(v4 + 3632);
								} else {
									v20 = *(float*)(v4 + 3632) - (*(float*)&dword_587000_202404 + v16) * 0.1;
								}
							} else {
								v20 = *(float*)(v4 + 3632) - (v16 - *(float*)&dword_587000_202404) * 0.1;
							}
							if (v19 > (double)*(float*)&dword_587000_202404) {
								v17 = v19 - *(float*)&dword_587000_202404;
								goto LABEL_65;
							}
							if (-*(float*)&dword_587000_202404 <= v19) {
								v21 = *(float*)(v4 + 3636);
							} else {
								v17 = *(float*)&dword_587000_202404 + v19;
							LABEL_65:
								v21 = *(float*)(v4 + 3636) - v17 * 0.1;
							}
							if (sub_517590(v20, v21)) {
								*(float*)(v4 + 3632) = v20;
								*(float*)(v4 + 3636) = v21;
							}
							v1 = a1;
							goto LABEL_72;
						}
					} else {
						v15 = *(uint32_t*)(v4 + 3692);
						*(uint32_t*)(v4 + 3688) = 1;
						if (!v15) {
							nox_xxx_playerLeaveMonsterObserver_4E60E0(v4);
						}
						*(uint32_t*)(v9 + 16) = 0;
					}
					goto LABEL_72;
				}
				if (*(uint32_t*)(v9 + 8) != 6) {
					if (*(uint32_t*)(v9 + 8) != 7) {
						goto LABEL_72;
					}
					if (!nox_xxx_playerGetPossess_4DDF30(v1) && !nox_common_gameFlags_check_40A5C0(4096)) {
						a1a.field_0 = *(float*)(v4 + 3632) - 100.0;
						a1a.field_4 = *(float*)(v4 + 3636) - 100.0;
						a1a.field_8 = *(float*)(v4 + 3632) + 100.0;
						v10 = *(float*)(v4 + 3636) + 100.0;
						dword_5d4594_1565612 = 0;
						*getMemU32Ptr(0x5D4594, 1565608) = 1287568416;
						*getMemU32Ptr(0x5D4594, 1565604) = v1;
						a1a.field_C = v10;
						nox_xxx_getUnitsInRect_517C10(&a1a, sub_4E6800, v4 + 3632);
						if (dword_5d4594_1565612 && dword_5d4594_1565612 != *(uint32_t*)(v4 + 3628)) {
							nox_xxx_playerCameraFollow_4E6060(*(uint32_t*)(v4 + 2056), *(int*)&dword_5d4594_1565612);
							*(uint32_t*)(v4 + 3672) = 0;
						} else {
							nox_xxx_playerCameraUnlock_4E6040(*(uint32_t*)(v4 + 2056));
							*(uint32_t*)(v4 + 3672) = 1;
						}
						goto LABEL_72;
					}
				}
				if (dword_5d4594_2650652 && nox_common_gameFlags_check_40A5C0(49152) &&
					!sub_509CF0((const char*)(v4 + 2096), *(uint8_t*)(v4 + 2251), *(uint32_t*)(v4 + 2068))) {
					nox_xxx_netInformTextMsg_4DA0F0(*(unsigned char*)(v4 + 2064), 17, 0);
					*(uint32_t*)(v9 + 16) = 0;
					goto LABEL_72;
				}
				if (*(uint8_t*)(v4 + 3680) & 0x20) {
					goto LABEL_45;
				}
				if (nox_common_gameFlags_check_40A5C0(4096)) {
					break;
				}
				if (sub_40A740() || nox_common_gameFlags_check_40A5C0(0x8000) ||
					(v12 = *(uint32_t*)(v4 + 3680), BYTE1(v12) & 1) &&
						(v13 = nox_xxx_gamePlayIsAnyPlayers_40A8A0(), v13)) {
					v11 = sub_40AA70(v4) == 0;
				LABEL_44:
					if (v11) {
					LABEL_45:
						nox_xxx_playerLeaveMonsterObserver_4E60E0(v4);
						*(uint32_t*)(v9 + 16) = 0;
						goto LABEL_72;
					}
				}
				if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) &&
					v1 == nox_xxx_host_player_unit_3843628) {
					goto LABEL_52;
				}
				if (!nox_xxx_playerGetPossess_4DDF30(v1)) {
					sub_4DF3C0(v4);
					nox_xxx_playerLeaveObserver_0_4E6AA0(v4);
					nox_xxx_playerCameraUnlock_4E6040(v1);
					if (!nox_common_gameFlags_check_40A5C0(4096)) {
						nox_xxx_mapFindPlayerStart_4F7AB0(&v22, *(uint32_t*)(v4 + 2056));
						nox_xxx_unitMove_4E7010(*(uint32_t*)(v4 + 2056), &v22);
					}
				LABEL_52:
					*(uint32_t*)(v9 + 16) = 0;
					goto LABEL_72;
				}
				nox_xxx_playerObserveClear_4DDEF0(v1);
				*(uint32_t*)(v9 + 16) = 0;
			LABEL_72:
				result = nox_xxx_playerGetControlBufferNext_51ABC0(*(unsigned char*)(v4 + 2064));
				v9 = (int)result;
				if (!result) {
					goto LABEL_73;
				}
			}
			if (!*(uint32_t*)(v18[69] + 4792)) {
				if (v18[138] == 1) {
					nox_xxx_netPriMsgToPlayer_4DA2C0(a1, "MainBG.wnd:Loading", 0);
				} else {
					*(uint32_t*)(v18[69] + 4792) = sub_4E4100();
					if (*(uint32_t*)(v18[69] + 4792) == 1) {
						sub_4D79C0(a1);
					} else {
						nox_xxx_netPriMsgToPlayer_4DA2C0(a1, "GeneralPrint:QuestGameFull", 0);
					}
				}
				v1 = a1;
			}
			if (v18[79]) {
				sub_4D7480(v1);
				goto LABEL_72;
			}
			if (v18[78]) {
				goto LABEL_45;
			}
			v11 = *(uint32_t*)(v18[69] + 4792) == 0;
			goto LABEL_44;
		}
	LABEL_73:
		*(uint32_t*)(v4 + 3692) = *(uint32_t*)(v4 + 3688);
	}
	return result;
}
// 4E65F4: variable 'v13' is possibly undefined

//----- (004E6800) --------------------------------------------------------
void sub_4E6800(float* a1, int a2) {
	int v2;    // eax
	double v3; // st7
	double v4; // st6
	double v5; // st5

	if ((uint8_t)a1[2] & 2) {
		v2 = *((uint32_t*)a1 + 127);
		if (v2) {
			if (v2 == *getMemU32Ptr(0x5D4594, 1565604)) {
				v3 = a1[14] - *(float*)a2;
				v4 = a1[15] - *(float*)(a2 + 4);
				v5 = v4 * v4 + v3 * v3;
				if (v5 < *getMemFloatPtr(0x5D4594, 1565608)) {
					dword_5d4594_1565612 = a1;
					*getMemFloatPtr(0x5D4594, 1565608) = v5;
				}
			}
		}
	}
}

//----- (004E6860) --------------------------------------------------------
int nox_xxx_playerGoObserver_4E6860(nox_playerInfo* pl, int a2, int a3) {
	int i;           // esi
	int v8;          // eax
	unsigned int v9; // edx
	int v10;         // eax
	int v12;         // ecx
	int v13;         // [esp+Ch] [ebp+4h]

	if (!pl || !pl->playerUnit) {
		return 1;
	}
	int unit = pl->playerUnit;
	v13 = *(uint32_t*)(unit + 748);
	if (!a3 && nox_xxx_playerIsExecutingAbility_4FC2B0(unit) == 1) {
		return 0;
	}
	if (*(int (**)(uint32_t*))(unit + 744) == nox_xxx_updatePlayerMonsterBot_4FAB20) {
		return 0;
	}
	if (nox_common_gameFlags_check_40A5C0(112)) {
		if (!*getMemU32Ptr(0x5D4594, 1565620)) {
			*getMemU32Ptr(0x5D4594, 1565620) = nox_xxx_getNameId_4E3AA0("Crown");
		}
		if (!dword_5d4594_1565616) {
			dword_5d4594_1565616 = nox_xxx_getNameId_4E3AA0("GameBall");
		}
		for (i = *(uint32_t*)((int)(pl->playerUnit) + 516); i; i = *(uint32_t*)(i + 512)) {
			v8 = *(unsigned short*)(i + 4);
			if ((unsigned short)v8 == *getMemU32Ptr(0x5D4594, 1565620)) {
				nox_xxx_dropCrown_4ED5E0(pl->playerUnit, i, (int*)((int)(pl->playerUnit) + 56));
			} else if (v8 == dword_5d4594_1565616) {
				v9 = *(uint32_t*)(i + 16) & 0xFFFFFFBF;
				*(uint32_t*)(i + 520) = 0;
				*(uint32_t*)(i + 16) = v9;
				nox_xxx_unitClearOwner_4EC300(i);
				sub_4E8290(1, 0);
			} else if (*(uint32_t*)(i + 8) & 0x10000000) {
				nox_xxx_drop_4ED790(pl->playerUnit, (uint32_t*)i, (float2*)((int)(pl->playerUnit) + 56));
			}
		}
	}
	if (nox_xxx_playerGetPossess_4DDF30(pl->playerUnit)) {
		nox_xxx_playerObserveClear_4DDEF0(pl->playerUnit);
	}
	nox_xxx_netNeedTimestampStatus_4174F0(pl, 1);
	v10 = nox_xxx_gamePlayIsAnyPlayers_40A8A0();
	if (!v10 && !nox_common_gameFlags_check_40A5C0(4096)) {
		sub_40A1F0(0);
		nox_xxx_playerForceSendLessons_416E50(1);
		nox_server_teamsResetYyy_417D00();
		sub_40A970();
	}
	nox_xxx_netInformTextMsg_4DA0F0(pl->playerInd, 12, (int*)&a2);
	nox_xxx_buffApplyTo_4FF380(unit, 0, 0, 5);
	v12 = *(uint32_t*)(unit + 56);
	*(uint32_t*)(unit + 16) |= 0x40u;
	*(uint32_t*)((int)pl + 3632) = v12;
	*(uint32_t*)((int)pl + 3636) = *(uint32_t*)(unit + 60);
	nox_xxx_playerCameraUnlock_4E6040(unit);
	if (nox_common_gameFlags_check_40A5C0(2048)) {
		*(uint32_t*)((int)pl + 3672) = 1;
		*(uint32_t*)((int)pl + 3628) = 0;
	} else if (nox_common_gameFlags_check_40A5C0(64)) {
		if (!a3) {
			nox_xxx_playerLeaveMonsterObserver_4E60E0(pl);
		}
	}
	nox_xxx_playerRemoveSpawnedStuff_4E5AD0(unit);
	*(uint8_t*)(v13 + 244) = 0;
	*(uint32_t*)(unit + 744) = nox_xxx_updatePlayerObserver_4E62F0;
	sub_4D7E50(unit);
	return 1;
}
// 4E69B8: variable 'v10' is possibly undefined
// 4E69DB: variable 'v11' is possibly undefined

//----- (004E6AA0) --------------------------------------------------------
void nox_xxx_playerLeaveObserver_0_4E6AA0(nox_playerInfo* pl) {
	int a1 = pl;
	int v1;      // esi
	int v2;      // edx
	int v3;      // eax
	uint32_t* i; // esi

	if (a1) {
		v1 = *(uint32_t*)(a1 + 2056);
		if (v1) {
			if (*(int (**)(uint32_t*))(v1 + 744) != nox_xxx_updatePlayerMonsterBot_4FAB20) {
				nox_xxx_playerUnsetStatus_417530(a1, 289);
				nox_xxx_spellBuffOff_4FF5B0(v1, 0);
				v2 = *(uint32_t*)(v1 + 16);
				*(uint32_t*)(v1 + 744) = nox_xxx_updatePlayer_4F8100;
				*(uint32_t*)(v1 + 16) = v2 & 0xFFFFFFBF;
				nox_xxx_monsterMarkUpdate_4E8020(*(uint32_t*)(a1 + 2056));
				if (nox_common_gameFlags_check_40A5C0(16)) {
					if (nox_xxx_CheckGameplayFlags_417DA0(4)) {
						v3 = *((uint32_t*)nox_xxx_clientGetTeamColor_418AB0(
								   *(unsigned char*)(*(uint32_t*)(a1 + 2056) + 52)) +
							   19);
						if (v3) {
							if (!*(uint32_t*)(v3 + 492)) {
								sub_4F3400(*(uint32_t*)(a1 + 2056), v3, 1);
							}
						}
					}
				}
				if (nox_common_gameFlags_check_40A5C0(49152) && !sub_509D80(a1)) {
					sub_509C30(a1);
				}
				if (nox_common_gameFlags_check_40A5C0(4096)) {
					for (i = (uint32_t*)nox_xxx_getFirstPlayerUnit_4DA7C0(); i;
						 i = (uint32_t*)nox_xxx_getNextPlayerUnit_4DA7F0((int)i)) {
						if (*(uint32_t*)(*(uint32_t*)(i[187] + 276) + 4792) == 1) {
							nox_xxx_netReportEnchant_4D8F90(*(unsigned char*)(a1 + 2064), i);
						}
					}
				}
			}
		}
	}
}

//----- (004E6BD0) --------------------------------------------------------
int sub_4E6BD0(int a1) {
	return *(uint32_t*)(a1 + 556) && (unsigned int)(nox_frame_xxx_2598000 - *(uint32_t*)(a1 + 536)) <= 1;
}

//----- (004E6C00) --------------------------------------------------------
double nox_xxx_calcDistance_4E6C00(nox_object_t* a1p, nox_object_t* a2p) {
	int a1 = a1p;
	int a2 = a2p;
	double v2;          // st7
	double v3;          // st6
	int v4;             // edx
	double v5;     // st5
	double result; // st7
	double v7;          // st6
	int v8;             // eax
	double v9;          // st6
	float v10;          // [esp+4h] [ebp+4h]
	float v11;          // [esp+4h] [ebp+4h]

	v2 = *(float*)(a1 + 56) - *(float*)(a2 + 56);
	v3 = *(float*)(a1 + 60) - *(float*)(a2 + 60);
	v4 = *(uint32_t*)(a1 + 172);
	v5 = sqrt(v3 * v3 + v2 * v2);
	result = v5;
	if (v4 == 2) {
		result = v5 - *(float*)(a1 + 176);
	} else if (v4 == 3) {
		v7 = *(float*)(a1 + 184) * 0.5;
		v10 = *(float*)(a1 + 188) * 0.5;
		if (v7 <= v10) {
			v7 = v10;
		}
		result = v5 - v7;
	}
	v8 = *(uint32_t*)(a2 + 172);
	if (v8 == 2) {
		result = result - *(float*)(a2 + 176);
	} else if (v8 == 3) {
		v9 = *(float*)(a2 + 184) * 0.5;
		v11 = *(float*)(a2 + 188) * 0.5;
		if (v9 <= v11) {
			v9 = v11;
		}
		result = result - v9;
	}
	if (result < 0.0099999998) {
		result = 0.0099999998;
	}
	return result;
}

//----- (004E6CE0) --------------------------------------------------------
int sub_4E6CE0(float2* a1, float2* a2) {
	double v2;  // st7
	int v3;     // ecx
	int v4;     // eax
	int v5;     // ecx
	int v6;     // eax
	int result; // eax

	*(float*)&dword_5d4594_1565628 = a2->field_0 - a1->field_0;
	*(float*)&dword_5d4594_1565632 = a2->field_4 - a1->field_4;
	*getMemFloatPtr(0x5D4594, 1565652) = *(float*)&dword_5d4594_1565628 * 0.41304299 - *(float*)&dword_5d4594_1565632;
	v2 = *(float*)&dword_5d4594_1565628 * 2.4210529 - *(float*)&dword_5d4594_1565632;
	*getMemFloatPtr(0x5D4594, 1565656) = v2;
	*getMemFloatPtr(0x5D4594, 1565636) = *(float*)&dword_5d4594_1565628 * -2.4210529 - *(float*)&dword_5d4594_1565632;
	*getMemFloatPtr(0x5D4594, 1567708) = *(float*)&dword_5d4594_1565628 * -0.41304299 - *(float*)&dword_5d4594_1565632;
	if (*getMemFloatPtr(0x5D4594, 1565652) < 0.0) {
		v3 = 0;
	} else {
		v3 = 8;
	}
	if (v2 < 0.0) {
		v4 = 0;
	} else {
		v4 = 4;
	}
	v5 = v4 | v3;
	if (*getMemFloatPtr(0x5D4594, 1565636) < 0.0) {
		v6 = 0;
	} else {
		v6 = 2;
	}
	*getMemU32Ptr(0x5D4594, 1565640) = (*getMemFloatPtr(0x5D4594, 1567708) >= 0.0) | v6 | v5;
	switch (*getMemU32Ptr(0x5D4594, 1565640)) {
	case 0:
		result = 2;
		break;
	case 2:
		result = 6;
		break;
	case 3:
		result = 4;
		break;
	case 4:
		result = 10;
		break;
	case 0xB:
		result = 5;
		break;
	case 0xC:
		result = 8;
		break;
	case 0xD:
		result = 9;
		break;
	case 0xF:
		result = 1;
		break;
	default:
		result = 0;
		break;
	}
	return result;
}

//----- (004E6E50) --------------------------------------------------------
int nox_server_testTwoPointsAndDirection_4E6E50(float2* a1, int a2, float2* a3) {
	int v3;    // esi
	int v5[2]; // [esp+4h] [ebp-8h]

	nox_xxx_xferIndexedDirection_509E20(a2, (int2*)v5);
	v3 = v5[1] + v5[0] + 2 * v5[1] + 4;
	return *getMemU32Ptr(0x587000, 202504 + 4 * (sub_4E6CE0(a1, a3) + 16 * v3));
}

//----- (004E6EA0) --------------------------------------------------------
int sub_4E6EA0(int a1, float a2, int a3) {
	int result; // eax

	result = a3;
	if (a3) {
		*getMemU32Ptr(0x5D4594, 1565648) = 0;
		*getMemFloatPtr(0x5D4594, 1565644) = a2 * a2;
		*(uint32_t*)(a3 + 36) = a1;
		nox_xxx_unitsGetInCircle_517F90((float2*)(a1 + 56), a2, sub_4E6EF0, a3);
		result = *getMemU32Ptr(0x5D4594, 1565648);
	}
	return result;
}

//----- (004E6EF0) --------------------------------------------------------
void sub_4E6EF0(int a1, uint32_t* a2) {
	int v2;    // eax
	int v3;    // ecx
	int v4;    // eax
	int v5;    // eax
	int v6;    // esi
	double v7; // st7
	double v8; // st6
	double v9; // st5

	if (!(*(uint8_t*)(a1 + 16) & 0x20) && !nox_xxx_unitsHaveSameTeam_4EC520(a1, a2[9]) &&
		(!(*(uint8_t*)(a1 + 8) & 4) || !(*(uint8_t*)(*(uint32_t*)(*(uint32_t*)(a1 + 748) + 276) + 3680) & 1)) &&
		(!a2[2] || nox_xxx_unitIsEnemyTo_5330C0(a2[9], a1))) {
		if (nox_server_testTwoPointsAndDirection_4E6E50((float2*)(a2[9] + 56), *(short*)(a2[9] + 124),
														(float2*)(a1 + 56)) &
			*a2) {
			v2 = a2[9];
			if (a1 != v2 && (!a2[1] || nox_xxx_unitCanInteractWith_5370E0(v2, a1, 0))) {
				v3 = *(uint32_t*)(a1 + 8);
				if (a2[3] & v3) {
					v4 = *(uint32_t*)(a1 + 16);
					if (a2[7] & v4) {
						if (!(v3 & a2[4]) && !(v4 & a2[8])) {
							v5 = *(uint32_t*)(a1 + 12);
							if (!v5 || v5 & a2[5] && !(v5 & a2[6])) {
								v6 = a2[9];
								v7 = *(float*)(a1 + 56) - *(float*)(v6 + 56);
								v8 = *(float*)(a1 + 60) - *(float*)(v6 + 60);
								v9 = v8 * v8 + v7 * v7;
								if (v9 < *getMemFloatPtr(0x5D4594, 1565644)) {
									*getMemFloatPtr(0x5D4594, 1565644) = v9;
									*getMemU32Ptr(0x5D4594, 1565648) = a1;
								}
							}
						}
					}
				}
			}
		}
	}
}

//----- (004E7010) --------------------------------------------------------
void nox_xxx_unitMove_4E7010(nox_object_t* obj, float2* a2) {
	int a1 = obj;
	int v2;     // edi
	int v3;     // ecx
	int v4;     // eax
	char v5[5]; // [esp+4h] [ebp-8h]

	if (a1 && !(*(uint32_t*)(a1 + 8) & 0x400000)) {
		if ((long long)*(float*)(a1 + 56) != (long long)a2->field_0 ||
			(long long)*(float*)(a1 + 60) != (long long)a2->field_4) {
			nox_xxx_unitNeedSync_4E44F0(a1);
		}
		*(float2*)(a1 + 64) = *a2;
		*(float2*)(a1 + 56) = *a2;
		*(float2*)(a1 + 72) = *a2;
		nox_xxx_moveUpdateSpecial_517970(a1);
		if (*(uint32_t*)(a1 + 696)) {
			nox_xxx_unitHasCollideOrUpdateFn_537610(a1);
		}
		if (*(uint8_t*)(a1 + 8) & 6) {
			sub_537540(a1);
		}
		if (*(uint8_t*)(a1 + 8) & 2) {
			sub_5346D0(a1);
		}
		sub_4FD090(a1);
		if (*(uint8_t*)(a1 + 8) & 6) {
			nox_xxx_frameCounterSetCopyToNextFrame_5281D0();
		}
		if (*(uint8_t*)(a1 + 8) & 4 && nox_common_gameFlags_check_40A5C0(0x2000)) {
			v2 = *(uint32_t*)(a1 + 748);
			v3 = *(uint32_t*)(v2 + 276);
			*(uint32_t*)(v2 + 272) = nox_frame_xxx_2598000;
			sub_4DE4D0(*(uint8_t*)(v3 + 2064));
			v5[0] = -22;
			*(uint32_t*)&v5[1] = nox_frame_xxx_2598000;
			nox_xxx_netSendPacket1_4E5390(*(unsigned char*)(*(uint32_t*)(v2 + 276) + 2064), (int)v5, 5, 0, 0);
		}
		if (*(uint8_t*)(a1 + 8) & 4) {
			v4 = *(uint32_t*)(*(uint32_t*)(a1 + 748) + 276);
			if (!*(uint32_t*)(v4 + 3628) && !(*(uint8_t*)(v4 + 3680) & 3)) {
				*(uint32_t*)(v4 + 3632) = *(uint32_t*)(a1 + 56);
				*(uint32_t*)(v4 + 3636) = *(uint32_t*)(a1 + 60);
			}
		}
	}
}

//----- (004E7190) --------------------------------------------------------
void nox_xxx_teleportToMB_4E7190(uint8_t* a1, float* a2) {
	if (!nox_xxx_testUnitBuffs_4FF350((int)a1, 14) && !(a1[16] & 2) &&
		(!nox_common_gameFlags_check_40A5C0(4096) || !(a1[8] & 2) || !(a1[12] & 8)) &&
		(nox_common_gameFlags_check_40A5C0(2048) || a1[8] & 6)) {
		nox_xxx_unitMove_4E7010((int)a1, (float2*)a2);
	}
}

//----- (004E71F0) --------------------------------------------------------
void sub_4E71F0(int a1) {
	int* v1;    // esi
	int v2;     // eax
	int v3;     // ecx
	int v4[3];  // [esp+8h] [ebp-34h]
	int v5[10]; // [esp+14h] [ebp-28h]

	v5[5] = -1;
	v5[7] = -1;
	v1 = *(int**)(a1 + 748);
	v5[0] = 15;
	v5[1] = 1;
	v5[2] = 0;
	v5[3] = 6;
	v5[4] = 0;
	v5[6] = 0;
	v5[8] = 32800;
	v2 = sub_4E6EA0(a1, 50.0, (int)v5);
	if (v2) {
		v3 = v1[4];
		v4[0] = v2;
		nox_xxx_spellAccept_4FD400(v1[3], v1[2], (uint32_t*)*v1, *v1, v4, v3);
	}
	nox_xxx_delayedDeleteObject_4E5CC0(a1);
}

//----- (004E7290) --------------------------------------------------------
int nox_xxx_objectUnkUpdateCoords_4E7290(int a1) {
	int result; // eax
	int v2;     // ecx
	int v3;     // edx
	int v4;     // ecx

	result = a1;
	switch (*(uint32_t*)(a1 + 172)) {
	case 1:
		v2 = *(uint32_t*)(a1 + 56);
		*(uint32_t*)(a1 + 232) = v2;
		v3 = v2;
		v4 = *(uint32_t*)(a1 + 60);
		*(uint32_t*)(a1 + 240) = v3;
		*(uint32_t*)(a1 + 236) = v4;
		*(uint32_t*)(a1 + 244) = v4;
		break;
	case 2:
		*(float*)(a1 + 232) = *(float*)(a1 + 56) - *(float*)(a1 + 176);
		*(float*)(a1 + 236) = *(float*)(a1 + 60) - *(float*)(a1 + 176);
		*(float*)(a1 + 240) = *(float*)(a1 + 176) + *(float*)(a1 + 56);
		*(float*)(a1 + 244) = *(float*)(a1 + 176) + *(float*)(a1 + 60);
		break;
	case 3:
		*(float*)(a1 + 232) = *(float*)(a1 + 200) + *(float*)(a1 + 56);
		*(float*)(a1 + 236) = *(float*)(a1 + 196) + *(float*)(a1 + 60);
		*(float*)(a1 + 240) = *(float*)(a1 + 208) + *(float*)(a1 + 56);
		*(float*)(a1 + 244) = *(float*)(a1 + 220) + *(float*)(a1 + 60);
		break;
	}
	return result;
}

//----- (004E7350) --------------------------------------------------------
int sub_4E7350(int a1) {
	int result; // eax
	int v2;     // ecx
	int v3;     // edx
	int v4;     // ecx

	result = a1;
	switch (*(uint32_t*)(a1 + 172)) {
	case 1:
		v2 = *(uint32_t*)(a1 + 64);
		*(uint32_t*)(a1 + 232) = v2;
		v3 = v2;
		v4 = *(uint32_t*)(a1 + 68);
		*(uint32_t*)(a1 + 240) = v3;
		*(uint32_t*)(a1 + 236) = v4;
		*(uint32_t*)(a1 + 244) = v4;
		break;
	case 2:
		*(float*)(a1 + 232) = *(float*)(a1 + 64) - *(float*)(a1 + 176);
		*(float*)(a1 + 236) = *(float*)(a1 + 68) - *(float*)(a1 + 176);
		*(float*)(a1 + 240) = *(float*)(a1 + 176) + *(float*)(a1 + 64);
		*(float*)(a1 + 244) = *(float*)(a1 + 176) + *(float*)(a1 + 68);
		break;
	case 3:
		*(float*)(a1 + 232) = *(float*)(a1 + 200) + *(float*)(a1 + 64);
		*(float*)(a1 + 236) = *(float*)(a1 + 196) + *(float*)(a1 + 68);
		*(float*)(a1 + 240) = *(float*)(a1 + 208) + *(float*)(a1 + 64);
		*(float*)(a1 + 244) = *(float*)(a1 + 220) + *(float*)(a1 + 68);
		break;
	}
	return result;
}

//----- (004E7410) --------------------------------------------------------
int nox_xxx_unused_4E7410(int a1) {
	if (*(uint8_t*)(a1 + 16) & 0x40) {
		return 1;
	}
	nox_xxx_objectUnkUpdateCoords_4E7290(a1);
	return *(float*)(a1 + 240) - *(float*)(a1 + 232) < 85.0 && *(float*)(a1 + 244) - *(float*)(a1 + 236) < 85.0;
}

//----- (004E7470) --------------------------------------------------------
void nox_xxx_spawnSomeBarrel_4E7470(int a1, int a2) {
	const char* v2;    // eax
	unsigned char* v3; // edi
	int v4;            // eax
	int v5;            // edx
	unsigned char* v6; // esi
	unsigned char* v7; // ecx
	int v8;            // ebx
	char* result;      // eax
	int v10;           // edi
	int i;             // ebx
	uint32_t* v12;     // esi
	float2 a3;         // [esp+Ch] [ebp-8h]

	v2 = (const char*)nox_xxx_getUnitName_4E39D0(a1);
	v3 = getMemAt(0x587000, 203080);
	if (strncmp(v2, "Barrel", 6u)) {
		v3 = getMemAt(0x587000, 203240);
	}
	v4 = nox_common_randomInt_415FA0(0, 99);
	v5 = 0;
	if (*(uint32_t*)v3) {
		v6 = v3;
		v7 = v3;
		do {
			if (*((uint32_t*)v6 + 2) > v4) {
				break;
			}
			v8 = *((uint32_t*)v7 + 3);
			v7 += 12;
			++v5;
			v6 = v7;
		} while (v8);
	}
	result = *(char**)&v3[12 * v5];
	v10 = (int)&v3[12 * v5];
	if (result) {
		result = *(char**)(v10 + 4);
		for (i = 0; i < (int)result; ++i) {
			v12 = nox_xxx_newObjectByTypeID_4E3810(*(char**)v10);
			if (v12) {
				sub_4ED970(35.0, (float2*)a2, &a3);
				nox_xxx_createAt_4DAA50((int)v12, 0, a3.field_0, a3.field_4);
			}
			result = *(char**)(v10 + 4);
		}
	}
}

//----- (004E7540) --------------------------------------------------------
void sub_4E7540(nox_object_t* a1p, nox_object_t* a2p) {
	int a1 = a1p;
	int a2 = a2p;
	int v3; // eax

	if (a1) {
		if (a2) {
			if (*(uint8_t*)(a1 + 8) & 4 && *(uint8_t*)(a2 + 8) & 4 && a1 != a2) {
				v3 = *(uint32_t*)(a2 + 748);
				*(uint32_t*)(*(uint32_t*)(v3 + 276) + 3604) =
					*(unsigned char*)(*(uint32_t*)(*(uint32_t*)(a1 + 748) + 276) + 2064);
				*(uint32_t*)(*(uint32_t*)(v3 + 276) + 3608) = nox_frame_xxx_2598000;
				*(uint32_t*)(*(uint32_t*)(v3 + 276) + 3600) = 1;
			}
		}
	}
}

//----- (004E75B0) --------------------------------------------------------
char nox_xxx_objectSetOn_4E75B0(nox_object_t* obj) {
	int a1 = obj;
	int v1; // eax
	int v2; // eax

	if (!(*(uint32_t*)(a1 + 16) & 0x1000000)) {
		v1 = *(uint32_t*)(a1 + 8);
		if (v1 & 0x4000) {
			nox_xxx_aud_501960(235, a1, 0, 0);
		}
	}
	nox_xxx_unitSetOnOff_4E4670(a1, 1);
	v2 = *(uint32_t*)(a1 + 8);
	if (v2 & 0x10042000) {
		*(uint32_t*)(a1 + 16) &= 0xFFFFFFBF;
	}
	if (!(v2 & 1)) {
		LOBYTE(v2) = nox_xxx_unitHasCollideOrUpdateFn_537610(a1);
	}
	return v2;
}

//----- (004E7600) --------------------------------------------------------
int nox_xxx_objectSetOff_4E7600(nox_object_t* obj) {
	int a1 = obj;
	int v1;     // eax
	int result; // eax

	if (*(uint32_t*)(a1 + 16) & 0x1000000) {
		v1 = *(uint32_t*)(a1 + 8);
		if (v1 & 0x4000) {
			nox_xxx_aud_501960(236, a1, 0, 0);
		}
	}
	nox_xxx_unitSetOnOff_4E4670(a1, 0);
	result = *(uint32_t*)(a1 + 8);
	if (result & 0x10042000) {
		result = *(uint32_t*)(a1 + 16);
		LOBYTE(result) = result | 0x40;
		*(uint32_t*)(a1 + 16) = result;
	}
	return result;
}

//----- (004E7650) --------------------------------------------------------
char nox_xxx_objectToggle_4E7650(int a1) {
	char result; // al

	if ((*(uint32_t*)(a1 + 16) & 0x1000000) == 0x1000000) {
		result = nox_xxx_objectSetOff_4E7600(a1);
	} else {
		result = nox_xxx_objectSetOn_4E75B0(a1);
	}
	return result;
}

//----- (004E7680) --------------------------------------------------------
int sub_4E7680(int a1) {
	int result; // eax

	for (result = a1; *(uint16_t*)(a1 + 124) < 0; *(uint16_t*)(a1 + 124) += 256) {
		;
	}
	for (; *(uint16_t*)(a1 + 124) >= 256; *(uint16_t*)(a1 + 124) -= 256) {
		;
	}
	return result;
}

//----- (004E7700) --------------------------------------------------------
int sub_4E7700(int a1) {
	unsigned short* v1; // ecx
	int result;         // eax

	v1 = *(unsigned short**)(a1 + 556);
	result = *(uint32_t*)(a1 + 340) ^ *(uint32_t*)(a1 + 248) ^ *(uint32_t*)(a1 + 120) ^ *(uint32_t*)(a1 + 128) ^
			 *(uint32_t*)(a1 + 132) ^ *(uint32_t*)(a1 + 136) ^ *(uint32_t*)(a1 + 148) ^ *(uint32_t*)(a1 + 152) ^
			 *(short*)(a1 + 124) ^ *(short*)(a1 + 126) ^ *(uint32_t*)(a1 + 108) ^ *(uint32_t*)(a1 + 104) ^
			 *(uint32_t*)(a1 + 100) ^ *(uint32_t*)(a1 + 96) ^ *(uint32_t*)(a1 + 92) ^ *(uint32_t*)(a1 + 88) ^
			 *(uint32_t*)(a1 + 84) ^ *(uint32_t*)(a1 + 80) ^ *(uint32_t*)(a1 + 76) ^ *(uint32_t*)(a1 + 72) ^
			 *(uint32_t*)(a1 + 68) ^ *(uint32_t*)(a1 + 64) ^ *(uint32_t*)(a1 + 60) ^ *(uint32_t*)(a1 + 16) ^
			 *(uint32_t*)(a1 + 20) ^ *(uint32_t*)(a1 + 36) ^ *(uint32_t*)(a1 + 40) ^ *(uint32_t*)(a1 + 44) ^
			 *(uint32_t*)(a1 + 56) ^ *(unsigned short*)(a1 + 4) ^ *(unsigned char*)(a1 + 52);
	if (v1) {
		result ^= *v1 ^ v1[1] ^ v1[2];
	}
	return result;
}

//----- (004E7980) --------------------------------------------------------
int nox_xxx_inventoryGetFirst_4E7980(int a1) { return *(uint32_t*)(a1 + 504); }

//----- (004E7990) --------------------------------------------------------
int nox_xxx_inventoryGetNext_4E7990(int a1) {
	int result; // eax

	if (a1) {
		result = *(uint32_t*)(a1 + 496);
	} else {
		result = 0;
	}
	return result;
}

//----- (004E79B0) --------------------------------------------------------
int sub_4E79B0(int a1) {
	int result; // eax

	result = a1;
	*getMemU32Ptr(0x5D4594, 1567712) = a1;
	return result;
}

//----- (004E79C0) --------------------------------------------------------
char nox_xxx_unitFreeze_4E79C0(nox_object_t* obj, int a2) {
	int a1 = obj;
	int v2; // eax
	int i;  // esi

	v2 = *(uint32_t*)(a1 + 16);
	if (!(v2 & 2)) {
		LOBYTE(v2) = v2 | 2;
		*(uint32_t*)(a1 + 16) = v2;
		if (*(uint8_t*)(a1 + 8) & 4) {
			if (!*getMemU32Ptr(0x5D4594, 1567712)) {
				*getMemU32Ptr(0x5D4594, 1567712) = a2;
			}
			nox_xxx_netReportPlrStatus_4D8270(a1);
			nox_xxx_playerSetState_4FA020((uint32_t*)a1, 13);
			nox_xxx_unitRaise_4E46F0(a1, 0.0);
			sub_50B510();
			for (i = *(uint32_t*)(a1 + 516); i; i = *(uint32_t*)(i + 512)) {
				if (*(uint8_t*)(i + 8) & 2 && (*(uint8_t*)(*(uint32_t*)(i + 748) + 1440) & 0x80)) {
					nox_xxx_unitFreeze_4E79C0(i, a2);
				}
			}
		}
		LOBYTE(v2) = *(uint8_t*)(a1 + 8);
		if (v2 & 2) {
			v2 = *(uint32_t*)(a1 + 16);
			if ((v2 & 0x8000) == 0) {
				LOBYTE(v2) = (unsigned int)nox_xxx_monsterPushAction_50A260(a1, 0);
			}
		}
	}
	return v2;
}

//----- (004E7A60) --------------------------------------------------------
char nox_xxx_unitUnFreeze_4E7A60(nox_object_t* obj, int a2) {
	int a1 = obj;
	int v2; // eax
	int i;  // esi

	v2 = *(uint32_t*)(a1 + 16);
	if (v2 & 2) {
		if (*(uint8_t*)(a1 + 8) & 4) {
			LOBYTE(v2) = getMemByte(0x5D4594, 1567712);
			if (*getMemU32Ptr(0x5D4594, 1567712) && !a2) {
				return v2;
			}
			*getMemU32Ptr(0x5D4594, 1567712) = 0;
			*(uint32_t*)(a1 + 16) &= 0xFFFFFFFD;
			LOBYTE(v2) = nox_xxx_netReportPlrStatus_4D8270(a1);
			for (i = *(uint32_t*)(a1 + 516); i; i = *(uint32_t*)(i + 512)) {
				if (*(uint8_t*)(i + 8) & 2) {
					v2 = *(uint32_t*)(i + 748);
					if (*(uint8_t*)(v2 + 1440) & 0x80) {
						LOBYTE(v2) = nox_xxx_unitUnFreeze_4E7A60(i, a2);
					}
				}
			}
		} else {
			LOBYTE(v2) = v2 & 0xFD;
			*(uint32_t*)(a1 + 16) = v2;
		}
		if (*(uint8_t*)(a1 + 8) & 2) {
			v2 = *(uint32_t*)(a1 + 16);
			if ((v2 & 0x8000) == 0) {
				LOBYTE(v2) = nox_xxx_monsterPopAction_50A160(a1);
			}
		}
	}
	return v2;
}

//----- (004E7B00) --------------------------------------------------------
void nox_xxx_unitBecomePet_4E7B00(int a1, int a2) {
	int v2; // ecx
	int v3; // edi

	if (a1) {
		if (a2) {
			v2 = *(uint32_t*)(a2 + 12);
			v3 = *(uint32_t*)(a1 + 748);
			LOBYTE(v2) = v2 | 0x80;
			*(uint32_t*)(a2 + 12) = v2;
			nox_xxx_netMonitorCreature_4D9250(*(unsigned char*)(*(uint32_t*)(v3 + 276) + 2064), a2);
			nox_xxx_netMarkMinimapObject_417190(*(unsigned char*)(*(uint32_t*)(v3 + 276) + 2064), a2, 1);
			nox_xxx_unitSetOwner_4EC290(a1, a2);
		}
	}
}

//----- (004E7B60) --------------------------------------------------------
void nox_xxx_monsterRemoveMonitors_4E7B60(int a1, uint32_t* a2) {
	int v2; // edi
	int v3; // edx

	v2 = *(uint32_t*)(a1 + 748);
	if (a1) {
		if (a2) {
			v3 = a2[3];
			LOBYTE(v3) = v3 & 0x7F;
			a2[3] = v3;
			nox_xxx_netSendUnMonitorCrea_4D92A0(*(unsigned char*)(*(uint32_t*)(v2 + 276) + 2064), a2);
			nox_xxx_netUnmarkMinimapObj_417300(*(unsigned char*)(*(uint32_t*)(v2 + 276) + 2064), (int)a2, 1);
			nox_xxx_unitClearOwner_4EC300((int)a2);
		}
	}
}

//----- (004E7BC0) --------------------------------------------------------
int sub_4E7BC0(int a1) {
	int result; // eax

	result = a1;
	if (a1) {
		result = (*(uint32_t*)(a1 + 8) >> 2) & 1;
	}
	return result;
}

//----- (004E7BE0) --------------------------------------------------------
int nox_xxx_unitIsCrown_4E7BE0(int a1) {
	int v1; // eax
	int v2; // ecx

	v1 = *getMemU32Ptr(0x5D4594, 1567716);
	if (!*getMemU32Ptr(0x5D4594, 1567716)) {
		v1 = nox_xxx_getNameId_4E3AA0("Crown");
		*getMemU32Ptr(0x5D4594, 1567716) = v1;
	}
	v2 = *(uint32_t*)(a1 + 516);
	if (!v2) {
		return 0;
	}
	while (*(unsigned short*)(v2 + 4) != v1) {
		v2 = *(uint32_t*)(v2 + 512);
		if (!v2) {
			return 0;
		}
	}
	return 1;
}

//----- (004E7C30) --------------------------------------------------------
int nox_xxx_unitIsGameball_4E7C30(int a1) {
	int v1; // eax
	int v2; // ecx

	v1 = *getMemU32Ptr(0x5D4594, 1567720);
	if (!*getMemU32Ptr(0x5D4594, 1567720)) {
		v1 = nox_xxx_getNameId_4E3AA0("GameBall");
		*getMemU32Ptr(0x5D4594, 1567720) = v1;
	}
	v2 = *(uint32_t*)(a1 + 516);
	if (!v2) {
		return 0;
	}
	while (*(unsigned short*)(v2 + 4) != v1) {
		v2 = *(uint32_t*)(v2 + 512);
		if (!v2) {
			return 0;
		}
	}
	return 1;
}

#ifndef NOX_CGO
//----- (004E7C80) --------------------------------------------------------
int nox_xxx_unitIsUnitTT_4E7C80(nox_object_t* a1p, int a2) {
	int a1 = a1p;
	int result; // eax
	int i;      // ecx

	result = 0;
	if (a1) {
		for (i = *(uint32_t*)(a1 + 516); i; i = *(uint32_t*)(i + 512)) {
			if (*(unsigned short*)(i + 4) == a2 && !(*(uint8_t*)(i + 16) & 0x20)) {
				++result;
			}
		}
	}
	return result;
}
#endif // NOX_CGO

//----- (004E7CC0) --------------------------------------------------------
int sub_4E7CC0(int a1, int a2) {
	int result; // eax
	int i;      // ecx

	result = 0;
	if (!a1 || !a2) {
		return 0;
	}
	for (i = *(uint32_t*)(a1 + 516); i; i = *(uint32_t*)(i + 512)) {
		if (a2 & *(uint32_t*)(i + 8)) {
			++result;
		}
	}
	return result;
}

//----- (004E7CF0) --------------------------------------------------------
int nox_xxx_unitCountSlaves_4E7CF0(int a1, int a2, int a3) {
	int result;  // eax
	uint32_t* i; // ecx

	result = 0;
	if (!a1 || !a2 || !a3) {
		return 0;
	}
	for (i = *(uint32_t**)(a1 + 516); i; i = (uint32_t*)i[128]) {
		if (a2 & i[2]) {
			if (a3 & i[3]) {
				++result;
			}
		}
	}
	return result;
}

//----- (004E7D30) --------------------------------------------------------
int nox_xxx_inventoryCountObjects_4E7D30(int a1, int a2) {
	int result; // eax
	int i;      // ecx

	result = 0;
	if (a1) {
		for (i = *(uint32_t*)(a1 + 504); i; i = *(uint32_t*)(i + 496)) {
			if (!a2 || *(unsigned short*)(i + 4) == a2 && !(*(uint8_t*)(i + 16) & 0x20)) {
				++result;
			}
		}
	}
	return result;
}

//----- (004E7D70) --------------------------------------------------------
int sub_4E7D70(int a1, int a2) {
	int result; // eax
	int i;      // ecx

	result = 0;
	if (!a1 || !a2) {
		return 0;
	}
	for (i = *(uint32_t*)(a1 + 504); i; i = *(uint32_t*)(i + 496)) {
		if (a2 & *(uint32_t*)(i + 8)) {
			++result;
		}
	}
	return result;
}

//----- (004E7DA0) --------------------------------------------------------
int sub_4E7DA0(int a1, int a2, int a3) {
	int result;  // eax
	uint32_t* i; // ecx

	result = 0;
	if (!a1 || !a2 || !a3) {
		return 0;
	}
	for (i = *(uint32_t**)(a1 + 504); i; i = (uint32_t*)i[124]) {
		if (a2 & i[2]) {
			if (a3 & i[3]) {
				++result;
			}
		}
	}
	return result;
}

//----- (004E7DE0) --------------------------------------------------------
int sub_4E7DE0(int a1, nox_object_t* item) {
	int v2;       // ebx
	uint32_t* v3; // eax
	int v4;       // ecx
	int v5;       // edx
	int v6;       // eax
	bool v7;      // zf

	if (!a1 || !item || *(uint16_t*)(a1 + 4) != *(uint16_t*)&item->typ_ind) {
		return 0;
	}
	v2 = *(uint32_t*)(a1 + 8);
	if (v2 & 0x13001000) {
		v3 = *(uint32_t**)(a1 + 692);
		v4 = 0;
		v5 = *(uint32_t*)&item->field_173 - (uint32_t)v3;
		while (*v3 == *(uint32_t*)((char*)v3 + v5)) {
			++v4;
			++v3;
			if (v4 >= 4) {
				goto LABEL_8;
			}
		}
		return 0;
	}
LABEL_8:
	if (!(v2 & 0x100)) {
		return 1;
	}
	v6 = *(uint32_t*)(a1 + 12);
	if (v6 & 1) {
		v7 = **(uint8_t**)(a1 + 736) == **(uint8_t**)&item->field_184;
	} else {
		if (!(v6 & 2)) {
			if (**(uint8_t**)(a1 + 736) != **(uint8_t**)&item->field_184) {
				return 0;
			}
			return 1;
		}
		v7 = strcmp(*(const char**)(a1 + 736), *(const char**)&item->field_184) == 0;
	}
	if (!v7) {
		return 0;
	}
	return 1;
}

//----- (004E7EC0) --------------------------------------------------------
int sub_4E7EC0(int a1, nox_object_t* item) {
	int v2; // esi

	if (!a1) {
		return 0;
	}
	if (!item) {
		return 0;
	}
	v2 = *(uint32_t*)(a1 + 504);
	if (!v2) {
		return 0;
	}
	while (!sub_4E7DE0(v2, item)) {
		v2 = *(uint32_t*)(v2 + 496);
		if (!v2) {
			return 0;
		}
	}
	return 1;
}

//----- (004E7F10) --------------------------------------------------------
char* nox_xxx_unitPostCreateNotify_4E7F10(int a1) {
	char* result; // eax
	int i;        // edi
	int v3;       // eax
	int v4;       // esi
	int v5;       // eax

	*(uint32_t*)(a1 + 140) = 0;
	*(uint32_t*)(a1 + 144) = 0;
	result = nox_common_playerInfoGetFirst_416EA0();
	for (i = (int)result; result; i = (int)result) {
		v3 = *(uint32_t*)(i + 2056);
		v4 = 1 << *(uint8_t*)(i + 2064);
		if (v3) {
			if (nox_xxx_unitIsHostileMimic_4E7F90(v3, a1) == 1) {
				v5 = v4 | *(uint32_t*)(a1 + 144);
				*(uint32_t*)(a1 + 140) |= v4;
				*(uint32_t*)(a1 + 144) = v5;
			}
		}
		result = nox_common_playerInfoGetNext_416EE0(i);
	}
	return result;
}

//----- (004E7F90) --------------------------------------------------------
int nox_xxx_unitIsHostileMimic_4E7F90(int a1, int a2) {
	int v2; // ebx

	v2 = 0;
	if (!*getMemU32Ptr(0x5D4594, 1567724)) {
		*getMemU32Ptr(0x5D4594, 1567724) = nox_xxx_getNameId_4E3AA0("Mimic");
	}
	if (!a1 || !a2) {
		return 0;
	}
	if (!nox_xxx_unitIsEnemyTo_5330C0(a1, a2)) {
		v2 = 1;
	}
	if (nox_common_gameFlags_check_40A5C0(4096) && *(unsigned short*)(a2 + 4) == *getMemU32Ptr(0x5D4594, 1567724) &&
		*(uint8_t*)(a1 + 8) & 4 && !*(uint32_t*)(a2 + 508)) {
		v2 = 0;
	}
	return v2;
}

//----- (004E8020) --------------------------------------------------------
char* nox_xxx_monsterMarkUpdate_4E8020(int a1) {
	char* result; // eax
	int v2;       // ebx
	int v3;       // eax
	int v4;       // edi
	int v5;       // edi
	int v6;       // eax
	bool v7;      // zf
	int v8;       // eax

	result = nox_common_playerInfoGetFirst_416EA0();
	v2 = (int)result;
	if (result) {
		while (1) {
			v3 = *(uint32_t*)(v2 + 2056);
			v4 = 1 << *(uint8_t*)(v2 + 2064);
			if (!v3) {
				break;
			}
			v7 = nox_xxx_unitIsHostileMimic_4E7F90(v3, a1) == 1;
			v8 = *(uint32_t*)(a1 + 144);
			if (v7) {
				if (!(v8 & v4)) {
					*(uint32_t*)(a1 + 144) = v4 | v8;
					goto LABEL_9;
				}
			} else if (v8 & v4) {
				*(uint32_t*)(a1 + 144) = v8 & ~v4;
			LABEL_9:
				v6 = v4 | *(uint32_t*)(a1 + 140);
			LABEL_10:
				*(uint32_t*)(a1 + 140) = v6;
				goto LABEL_11;
			}
		LABEL_11:
			result = nox_common_playerInfoGetNext_416EE0(v2);
			v2 = (int)result;
			if (!result) {
				return result;
			}
		}
		v5 = ~v4;
		v6 = v5 & *(uint32_t*)(a1 + 140);
		*(uint32_t*)(a1 + 144) &= v5;
		goto LABEL_10;
	}
	return result;
}

//----- (004E80C0) --------------------------------------------------------
int sub_4E80C0(char a1) {
	int result; // eax
	int v2;     // esi
	int v3;     // edx

	result = nox_server_getFirstObject_4DA790();
	if (result) {
		v2 = ~(1 << a1);
		do {
			v3 = v2 & *(uint32_t*)(result + 140);
			*(uint32_t*)(result + 144) &= v2;
			*(uint32_t*)(result + 140) = v3;
			result = nox_server_getNextObject_4DA7A0(result);
		} while (result);
	}
	return result;
}

//----- (004E8110) --------------------------------------------------------
char* sub_4E8110(int a1) {
	int v1;       // edi
	char* result; // eax
	char* v3;     // ebx
	char* v4;     // esi
	int v5;       // ebp
	char v6;      // al
	int v7;       // ecx
	int v8;       // eax
	bool v9;      // zf
	int v10;      // eax
	int v11;      // ecx

	v1 = 1 << a1;
	result = nox_common_playerInfoFromNum_417090(a1);
	v3 = result;
	if (result) {
		result = (char*)nox_server_getFirstObject_4DA790();
		v4 = result;
		if (result) {
			v5 = ~v1;
			do {
				v6 = v4[8];
				v7 = v5 & *((uint32_t*)v4 + 35);
				*((uint32_t*)v4 + 36) &= v5;
				*((uint32_t*)v4 + 35) = v7;
				if (!(v6 & 6)) {
					goto LABEL_12;
				}
				v8 = *((uint32_t*)v3 + 514);
				if (!v8) {
					goto LABEL_12;
				}
				v9 = nox_xxx_unitIsHostileMimic_4E7F90(v8, (int)v4) == 1;
				v10 = *((uint32_t*)v4 + 36);
				if (v9) {
					if (!(v10 & v1)) {
						v11 = v1 | v10;
					LABEL_11:
						*((uint32_t*)v4 + 36) = v11;
						*((uint32_t*)v4 + 35) |= v1;
						goto LABEL_12;
					}
				} else if (v10 & v1) {
					v11 = v5 & *((uint32_t*)v4 + 36);
					goto LABEL_11;
				}
			LABEL_12:
				result = (char*)nox_server_getNextObject_4DA7A0((int)v4);
				v4 = result;
			} while (result);
		}
	}
	return result;
}

//----- (004E81D0) --------------------------------------------------------
int sub_4E81D0(nox_object_t* a1p) {
	int a1 = a1p;
	int result; // eax

	result = *getMemU32Ptr(0x5D4594, 1567728);
	if (!*getMemU32Ptr(0x5D4594, 1567728)) {
		result = nox_xxx_getNameId_4E3AA0("Pixie");
		*getMemU32Ptr(0x5D4594, 1567728) = result;
	}
	if (a1) {
		if (*(unsigned short*)(a1 + 4) == result) {
			result = *(uint32_t*)(a1 + 748);
			*(uint32_t*)(result + 4) = 0;
		}
	}
	return result;
}

//----- (004E8210) --------------------------------------------------------
int sub_4E8210(int a1, int a2) {
	float2* v2;      // edi
	unsigned int v3; // esi
	int v4;          // eax
	int v5;          // ecx

	v2 = 0;
	v3 = 0;
	v4 = nox_xxx_getFirstPlayerUnit_4DA7C0();
	if (!v4) {
		return 0;
	}
	do {
		v5 = *(uint32_t*)(*(uint32_t*)(v4 + 748) + 308);
		if (v5) {
			if (**(uint32_t**)(v5 + 700) > v3) {
				v3 = **(uint32_t**)(v5 + 700);
				v2 = *(float2**)(*(uint32_t*)(v4 + 748) + 308);
			}
		}
		v4 = nox_xxx_getNextPlayerUnit_4DA7F0(v4);
	} while (v4);
	if (!v2) {
		return 0;
	}
	*(uint32_t*)(*(uint32_t*)(a1 + 748) + 308) = v2;
	sub_4ED970(60.0, v2 + 7, (float2*)a2);
	return 1;
}

//----- (004E8290) --------------------------------------------------------
int sub_4E8290(char a1, short a2) {
	*getMemU8Ptr(0x5D4594, 1567736) = a1;
	*getMemU16Ptr(0x5D4594, 1567738) = a2;
	return nox_xxx_netSendBallStatus_4D95F0(255, a1, a2);
}

//----- (004E82C0) --------------------------------------------------------
int sub_4E82C0(unsigned char a1, char a2, char a3, short a4) {
	int v4; // eax

	v4 = 6 * a1;
	*getMemU8Ptr(0x5D4594, 1567740 + v4) = a1;
	*getMemU8Ptr(0x5D4594, 1567741 + v4) = a3;
	*getMemU8Ptr(0x5D4594, 1567742 + v4) = a2;
	*getMemU16Ptr(0x5D4594, 1567744 + v4) = a4;
	return nox_xxx_netSendFlagStatus_4D95A0(255, a1, a2, a3, a4);
}

//----- (004E8310) --------------------------------------------------------
char* sub_4E8310() { return (char*)getMemAt(0x5D4594, 1567736); }

//----- (004E8320) --------------------------------------------------------
unsigned char* sub_4E8320(unsigned char a1) { return getMemAt(0x5D4594, 1567740 + 6 * a1); }

//----- (004E8340) --------------------------------------------------------
void nox_xxx_fnFindCloseDoors_4E8340(float* a1, int a2) {
	int v2; // eax

	if (*((uint8_t*)a1 + 8) & 0x80) {
		v2 = *((uint32_t*)a1 + 187);
		if (*(uint32_t*)(v2 + 16) == *(uint32_t*)a2 && *(uint32_t*)(v2 + 20) == *(uint32_t*)(a2 + 4)) {
			*(uint8_t*)(v2 + 1) = 0;
			if (nox_common_gameFlags_check_40A5C0(4096)) {
				sub_4E8390((int)a1);
			}
		}
	}
}

//----- (004E8390) --------------------------------------------------------
int sub_4E8390(int a1) {
	*(uint8_t*)(*(uint32_t*)(a1 + 748) + 48) = 1;
	return sub_4D6A20(255, a1);
}

//----- (004E83B0) --------------------------------------------------------
unsigned char* nox_xxx_collideMonsterEventProc_4E83B0(int a1, int a2) {
	return nox_xxx_scriptCallByEventBlock_502490((int*)(*(uint32_t*)(a1 + 748) + 1272), a2, a1, 22);
}

//----- (004E83D0) --------------------------------------------------------
unsigned char* nox_xxx_collideMimic_4E83D0(int a1, int a2) {
	int v2;  // eax
	int* v3; // eax
	int* v4; // eax

	if (a2) {
		v2 = *(uint32_t*)(a2 + 16);
		if ((v2 & 0x8000) == 0 && *(uint8_t*)(a2 + 8) & 6 && nox_xxx_unitIsEnemyTo_5330C0(a1, a2) &&
			!nox_xxx_monsterIsActionScheduled_50A090(a1, 15)) {
			v3 = nox_xxx_monsterPushAction_50A260(a1, 43);
			if (v3) {
				v3[1] = nox_frame_xxx_2598000;
			}
			v4 = nox_xxx_monsterPushAction_50A260(a1, 15);
			if (v4) {
				v4[1] = *(uint32_t*)(a2 + 56);
				v4[2] = *(uint32_t*)(a2 + 60);
				v4[3] = nox_frame_xxx_2598000;
			}
		}
	}
	return nox_xxx_collideMonsterEventProc_4E83B0(a1, a2);
}

//----- (004E8460) --------------------------------------------------------
void nox_xxx_collidePlayer_4E8460(int a1, int a2) {
	int v2;       // ecx
	uint16_t* v3; // eax
	int v4;       // ebx
	int v5;       // eax
	short v6;     // ax
	int v7;       // eax
	short v8;     // ax
	int v9;       // eax
	int v10;      // eax
	int v11;      // eax
	char v12;     // al
	float v13;    // [esp+0h] [ebp-1Ch]
	float v14;    // [esp+4h] [ebp-18h]
	int v15;      // [esp+4h] [ebp-18h]
	float v16;    // [esp+Ch] [ebp-10h]
	float v17;    // [esp+Ch] [ebp-10h]
	float v18;    // [esp+Ch] [ebp-10h]
	float v19;    // [esp+10h] [ebp-Ch]

	if (nox_common_playerIsAbilityActive_4FC250(a1, 1)) {
		if (!a2) {
			goto LABEL_14;
		}
		v2 = *(uint32_t*)(a2 + 8);
		if (!(v2 & 6) || (v3 = *(uint16_t**)(a2 + 556), !*v3) && v3[2]) {
			if (!(v2 & 0x400000) && (signed char)*(uint8_t*)(a2 + 16) >= 0 &&
				*(float*)(a2 + 120) <= (double)*(float*)(a1 + 120)) {
				goto LABEL_26;
			}
		}
		if ((v2 & 0x80u) == 0) {
			if (!(*(uint8_t*)(a2 + 16) & 9) && !(v2 & 1)) {
			LABEL_14:
				nox_xxx_playerSetState_4FA020((uint32_t*)a1, 13);
				nox_xxx_earthquakeSend_4D9110((float*)(a1 + 56), 10);
				sub_4FC300((uint32_t*)a1, 1);
				if (a2) {
					v16 = nox_xxx_gamedataGetFloat_419D40("BerserkerDamage");
					v4 = nox_float2int(v16);
					if (!(*(uint32_t*)(a2 + 8) & 0x400000)) {
						sub_4E86E0(a1, (float*)a2);
					}
					v5 = nox_xxx_findParentChainPlayer_4EC580(a1);
					(*(void (**)(int, int, int, int, int))(a2 + 716))(a2, v5, a1, v4, 2);
					if (*(uint32_t*)(a2 + 8) & 0x20006) {
						goto LABEL_25;
					}
					v17 = nox_xxx_gamedataGetFloat_419D40("BerserkerStunDuration");
					v6 = nox_float2int(v17);
					nox_xxx_buffApplyTo_4FF380(a1, 5, v6, 5);
				} else {
					v7 = *(uint32_t*)(*(uint32_t*)(a1 + 748) + 296);
					if (v7 && !(getMemByte(0x85B3FC, 43076 + 12332 * *(unsigned char*)(v7 + 1)) & 5)) {
					LABEL_25:
						nox_xxx_unitMove_4E7010(a1, (float2*)(a1 + 72));
						goto LABEL_26;
					}
					nox_xxx_aud_501960(171, a1, 0, 0);
					v18 = nox_xxx_gamedataGetFloat_419D40("BerserkerStunDuration");
					v8 = nox_float2int(v18);
					nox_xxx_buffApplyTo_4FF380(a1, 5, v8, 5);
					v14 = *(float*)(a1 + 68) * 0.043478262;
					v15 = nox_float2int(v14);
					v13 = *(float*)(a1 + 64) * 0.043478262;
					v9 = nox_float2int(v13);
					nox_xxx_damageToMap_534BC0(v9, v15, 100, 2, a1);
				}
				v19 = nox_xxx_gamedataGetFloat_419D40("BerserkerPainRatio") * (double)**(unsigned short**)(a1 + 556);
				v10 = nox_float2int(v19);
				if (v10 < 1) {
					v10 = 1;
				}
				nox_xxx_unitDamageClear_4EE5E0(a1, v10);
				goto LABEL_25;
			}
		} else if (*(uint8_t*)(*(uint32_t*)(a2 + 748) + 1)) {
			goto LABEL_14;
		}
	}
LABEL_26:
	if (a2) {
		if (*(uint8_t*)(a2 + 8) & 4) {
			v11 = *(uint32_t*)(a2 + 16);
			if ((v11 & 0x8000) == 0) {
				if (nox_xxx_testUnitBuffs_4FF350(a1, 16)) {
					if (nox_xxx_unitGetBuffTimer_4FF550(a1, 16) < (unsigned int)(14 * nox_gameFPS)) {
						v12 = nox_xxx_buffGetPower_4FF570(a1, 16);
						nox_xxx_buffApplyTo_4FF380(a2, 16, 15 * (uint16_t)nox_gameFPS, v12);
						nox_xxx_spellBuffOff_4FF5B0(a1, 16);
					}
				}
			}
		}
	}
}

//----- (004E86E0) --------------------------------------------------------
void sub_4E86E0(int a1, float* a2) {
	int v2;    // ecx
	float* v3; // eax
	double v4; // st7
	double v5; // st6
	double v6; // st5
	double v7; // st4
	float v8;  // [esp+0h] [ebp-8h]
	float v9;  // [esp+4h] [ebp-4h]
	float v10; // [esp+Ch] [ebp+4h]
	float v11; // [esp+Ch] [ebp+4h]
	float v12; // [esp+10h] [ebp+8h]
	float v13; // [esp+10h] [ebp+8h]

	v2 = a1;
	if (a1) {
		v3 = a2;
		if (a2) {
			v12 = *(float*)(a1 + 120);
			v10 = v3[30];
			v8 = v10 + v12;
			v4 = (v12 - v10) / v8;
			v9 = (v10 + v10) / v8;
			v5 = *(float*)(v2 + 84) * v4 + v9 * v3[21];
			v6 = (v10 - v12) / v8;
			v7 = (v12 + v12) / v8;
			v11 = v6 * v3[20] + v7 * *(float*)(v2 + 80);
			v13 = v6 * v3[21] + v7 * *(float*)(v2 + 84);
			*(float*)(v2 + 80) = *(float*)(v2 + 80) * v4 + v9 * v3[20];
			*(float*)(v2 + 84) = v5;
			v3[21] = v13;
			v3[20] = v11;
		}
	}
}

//----- (004E87B0) --------------------------------------------------------
void nox_xxx_collideProjectileGeneric_4E87B0(int a1, int a2) {
	int* v2;   // edi
	int v3;    // eax
	double v4; // st7
	int v5;    // ebx
	int v6;    // eax
	int* v7;   // eax
	float v8;  // [esp+0h] [ebp-10h]

	v2 = *(int**)(a1 + 700);
	if (!*getMemU32Ptr(0x5D4594, 1567948)) {
		*getMemU32Ptr(0x5D4594, 1567948) = nox_xxx_getNameId_4E3AA0("ThrowingStone");
		*getMemU32Ptr(0x5D4594, 1567952) = nox_xxx_getNameId_4E3AA0("ImpShot");
	}
	v3 = *(unsigned short*)(a1 + 4);
	if ((unsigned short)v3 == *getMemU32Ptr(0x5D4594, 1567948)) {
		v4 = nox_xxx_gamedataGetFloat_419D40("UrchinStoneDamage");
	LABEL_5:
		v8 = v4;
		v5 = nox_float2int(v8);
		goto LABEL_9;
	}
	if (v3 == *getMemU32Ptr(0x5D4594, 1567952)) {
		v4 = nox_xxx_gamedataGetFloat_419D40("ImpShotDamage");
		goto LABEL_5;
	}
	v5 = *v2;
LABEL_9:
	if (a2) {
		v6 = nox_xxx_findParentChainPlayer_4EC580(a1);
		if (!(*(unsigned char (**)(int, int, int, int, int))(a2 + 716))(a2, v6, a1, v5, 11)) {
			return;
		}
	} else {
		v7 = (int*)sub_537760();
		if (v7) {
			nox_xxx_damageToMap_534BC0(*v7, v7[1], v5, 11, a1);
			nox_xxx_delayedDeleteObject_4E5CC0(a1);
			return;
		}
	}
	nox_xxx_delayedDeleteObject_4E5CC0(a1);
}

//----- (004E8880) --------------------------------------------------------
void nox_xxx_collideProjectileSpark_4E8880(int a1, int a2) {
	int* v2;  // eax
	int v3;   // eax
	int v4;   // eax
	float v5; // [esp+0h] [ebp-1Ch]
	float v6; // [esp+4h] [ebp-18h]
	int v7;   // [esp+4h] [ebp-18h]
	int v8;   // [esp+8h] [ebp-14h]
	int v9;   // [esp+Ch] [ebp-10h]

	v2 = *(int**)(a1 + 700);
	if (a2) {
		v9 = *v2;
		v3 = nox_xxx_findParentChainPlayer_4EC580(a1);
		if ((*(unsigned char (**)(int, int, int, int, int))(a2 + 716))(a2, v3, a1, v9, 11)) {
			nox_xxx_delayedDeleteObject_4E5CC0(a1);
		}
	} else {
		v8 = *v2;
		v6 = *(float*)(a1 + 68) * 0.043478262;
		v7 = nox_float2int(v6);
		v5 = *(float*)(a1 + 64) * 0.043478262;
		v4 = nox_float2int(v5);
		nox_xxx_damageToMap_534BC0(v4, v7, v8, 11, a1);
		nox_xxx_delayedDeleteObject_4E5CC0(a1);
	}
}

//----- (004E8910) --------------------------------------------------------
int nox_xxx_doorGetSomeKey_4E8910(int a1, int a2) {
	int v2;         // ebx
	int v4;         // ebp
	const char* v5; // esi

	v2 = *(uint32_t*)(a2 + 748);
	if (*(uint8_t*)(v2 + 1) == 5) {
		return 0;
	}
	if (*(uint32_t*)(a2 + 508)) {
		return 0;
	}
	v4 = *(uint32_t*)(a1 + 504);
	if (v4) {
		while (!(*(uint8_t*)(v4 + 8) & 0x40)) {
		LABEL_15:
			v4 = *(uint32_t*)(v4 + 496);
			if (!v4) {
				goto LABEL_16;
			}
		}
		v5 = (const char*)nox_xxx_getUnitName_4E39D0(v4);
		switch (*(unsigned char*)(v2 + 1)) {
		case 1u:
			if (strcmp(v5, "SilverKey")) {
				goto LABEL_15;
			}
			break;
		case 2u:
			if (strcmp(v5, "GoldKey")) {
				goto LABEL_15;
			}
			break;
		case 3u:
			if (strcmp(v5, "RubyKey")) {
				goto LABEL_15;
			}
			break;
		case 4u:
			if (strcmp(v5, "SapphireKey")) {
				goto LABEL_15;
			}
			break;
		default:
			goto LABEL_15;
		}
	}
LABEL_16:
	if (*(uint8_t*)(a1 + 8) & 4 && !v4 && nox_common_gameFlags_check_40A5C0(4096) && sub_4D72C0() == 1 &&
		*(uint8_t*)(v2 + 1) == 1) {
		v4 = sub_4E8A10();
	}
	return v4;
}

//----- (004E8A10) --------------------------------------------------------
int sub_4E8A10() {
	int v0;     // ebx
	int i;      // esi
	int v2;     // edi
	int v3;     // eax
	int result; // eax

	v0 = 0;
	if (!dword_5d4594_1567956) {
		dword_5d4594_1567956 = nox_xxx_getNameId_4E3AA0("SilverKey");
	}
	for (i = nox_xxx_getFirstPlayerUnit_4DA7C0(); i; i = nox_xxx_getNextPlayerUnit_4DA7F0(i)) {
		v2 = 0;
		v3 = nox_xxx_inventoryGetFirst_4E7980(i);
		if (v3) {
			do {
				if (*(unsigned short*)(v3 + 4) == dword_5d4594_1567956) {
					++v2;
				}
				v3 = nox_xxx_inventoryGetNext_4E7990(v3);
			} while (v3);
			if (v2 > 0) {
				v0 = i;
			}
		}
	}
	result = 0;
	if (v0) {
		for (result = nox_xxx_inventoryGetFirst_4E7980(v0); result; result = nox_xxx_inventoryGetNext_4E7990(result)) {
			if (*(unsigned short*)(result + 4) == dword_5d4594_1567956) {
				break;
			}
		}
	}
	return result;
}

//----- (004E8AC0) --------------------------------------------------------
void nox_xxx_collideDoor_4E8AC0(int a2, int a3) {
	int v2;                 // edi
	int v3;                 // esi
	int v4;                 // eax
	unsigned long long v5;  // rax
	char v6;                // al
	unsigned long long v7;  // rax
	int v8;                 // ebx
	int v9;                 // eax
	int v10;                // ecx
	int v11;                // esi
	double v12;             // st7
	double v13;             // st6
	int v14;                // ecx
	int v15;                // eax
	int v16;                // eax
	unsigned long long v17; // rax
	int a3a[2];             // [esp+10h] [ebp-18h]
	float4 a1;              // [esp+18h] [ebp-10h]
	float v20;              // [esp+2Ch] [ebp+4h]

	v2 = a2;
	v3 = *(uint32_t*)(a2 + 748);
	if (a3 && *(uint32_t*)(v3 + 12) == *(uint32_t*)(v3 + 4)) {
		v4 = *(uint32_t*)(a2 + 508);
		if (v4) {
			if (*(uint32_t*)(a2 + 136) <= nox_frame_xxx_2598000) {
				*(uint32_t*)(a2 + 508) = 0;
			} else if (v4 != a3) {
				v5 = nox_platform_get_ticks() - *(uint64_t*)&qword_5d4594_1567940;
				a3a[1] = HIDWORD(v5);
				if (v5 <= 0x5DC) {
					return;
				}
				if (*(uint8_t*)(a2 + 12) & 4) {
					nox_xxx_aud_501960(244, a2, 0, 0);
					nox_xxx_netPriMsgToPlayer_4DA2C0(a3, "objcoll.c:GateLockedMagic", 0);
				} else {
					nox_xxx_aud_501960(240, a2, 0, 0);
					nox_xxx_netPriMsgToPlayer_4DA2C0(a3, "objcoll.c:DoorLockedMagic", 0);
				}
			LABEL_38:
				*(uint64_t*)&qword_5d4594_1567940 = nox_platform_get_ticks();
				return;
			}
		}
		v6 = *(uint8_t*)(v3 + 1);
		if (!v6) {
			return;
		}
		if (v6 == 5) {
			v7 = nox_platform_get_ticks() - *(uint64_t*)&qword_5d4594_1567940;
			a3a[1] = HIDWORD(v7);
			if (v7 <= 0x5DC) {
				return;
			}
			if (*(uint8_t*)(a2 + 12) & 4) {
				nox_xxx_aud_501960(244, a2, 0, 0);
				nox_xxx_netPriMsgToPlayer_4DA2C0(a3, "objcoll.c:GateLockedMechanism", 0);
			} else {
				nox_xxx_aud_501960(240, a2, 0, 0);
				nox_xxx_netPriMsgToPlayer_4DA2C0(a3, "objcoll.c:DoorLockedMechanism", 0);
			}
			goto LABEL_38;
		}
		v8 = nox_xxx_doorGetSomeKey_4E8910(a3, a2);
		if (!v8) {
			v17 = nox_platform_get_ticks() - *(uint64_t*)&qword_5d4594_1567940;
			a3a[1] = HIDWORD(v17);
			if (v17 <= 0x5DC) {
				return;
			}
			if (*(uint8_t*)(a2 + 12) & 4) {
				nox_xxx_aud_501960(244, a2, 0, 0);
				sub_4FADD0(a3, "objcoll.c:GateLockedKey", *(uint8_t*)(v3 + 1));
			} else {
				nox_xxx_aud_501960(240, a2, 0, 0);
				sub_4FADD0(a3, "objcoll.c:DoorLockedKey", *(uint8_t*)(v3 + 1));
			}
			goto LABEL_38;
		}
		v9 = *(uint32_t*)(v3 + 16);
		v10 = *(uint32_t*)(v3 + 20);
		*(uint8_t*)(v3 + 1) = 0;
		v11 = *(uint32_t*)(v3 + 4);
		v12 = (double)(23 * v9);
		a1.field_0 = v12 - 34.0;
		v13 = (double)(23 * v10);
		v20 = v13;
		a1.field_4 = v13 - 34.0;
		a1.field_8 = v12 + 34.0;
		a1.field_C = v20 + 34.0;
		switch (v11) {
		case 0:
			v14 = v10 - 1;
			a3a[0] = v9 - 1;
			goto LABEL_24;
		case 8:
			v14 = v10 - 1;
			a3a[0] = v9 + 1;
			goto LABEL_24;
		case 16:
			v15 = v9 + 1;
			goto LABEL_23;
		case 24:
			v15 = v9 - 1;
		LABEL_23:
			a3a[0] = v15;
			v14 = v10 + 1;
		LABEL_24:
			a3a[1] = v14;
			break;
		default:
			break;
		}
		if (nox_common_gameFlags_check_40A5C0(4096)) {
			sub_4E8390(v2);
			sub_4D71E0(nox_frame_xxx_2598000);
		}
		nox_xxx_getUnitsInRect_517C10(&a1, nox_xxx_fnFindCloseDoors_4E8340, (int)a3a);
		nox_xxx_aud_501960(234, v2, 0, 0);
		v16 = *(uint32_t*)(v8 + 492);
		if (v16 && a3 != v16 && *(uint8_t*)(v16 + 8) & 4 && nox_common_gameFlags_check_40A5C0(4096) &&
			sub_4D72C0() == 1) {
			nox_xxx_netPriMsgToPlayer_4DA2C0(*(uint32_t*)(v8 + 492), "GeneralPrint:KeyShared1", 0);
		}
		nox_xxx_delayedDeleteObject_4E5CC0(v8);
	}
}

//----- (004E8DF0) --------------------------------------------------------
int nox_xxx_collidePickup_4E8DF0(int a1, int a2) {
	int result; // eax
	int v3;     // ecx

	result = a2;
	if (a2) {
		v3 = *(uint32_t*)(a2 + 8);
		if (!(v3 & 2) && (unsigned int)(nox_frame_xxx_2598000 - *(uint32_t*)(a1 + 128)) >= (int)nox_gameFPS >> 1 &&
			(!(v3 & 4) || *(uint8_t*)(*(uint32_t*)(a2 + 748) + 240) & 1)) {
			result = nox_xxx_inventoryServPlace_4F36F0(a2, a1, 1, 1);
		}
	}
	return result;
}

//----- (004E8E50) --------------------------------------------------------
unsigned char* sub_4E8E50() { return getMemAt(0x5D4594, 1567844); }

//----- (004E8E60) --------------------------------------------------------
int sub_4E8E60() {
	int v0;          // esi
	int v1;          // edi
	int v2;          // ebx
	int v3;          // eax
	int v4;          // edx
	unsigned int v5; // eax
	int v6;          // eax
	int v7;          // ecx
	int result;      // eax
	int v9;          // eax
	int v10;         // ecx
	float v11;       // [esp+0h] [ebp-1Ch]
	float v12;       // [esp+0h] [ebp-1Ch]
	int v13;         // [esp+10h] [ebp-Ch]
	int v14;         // [esp+18h] [ebp-4h]

	v11 = nox_xxx_gamedataGetFloat_419D40("QuestExitTimerStart");
	v0 = nox_float2int(v11);
	v1 = 0;
	v14 = v0;
	v2 = v0;
	v13 = 0;
	if (sub_40A220()) {
		v3 = sub_40A230();
		v4 = (int)v3 / 1000;
		v5 = 0;
		v0 = v5 + v4;
		v14 = v5 + v4;
		v2 = v5 + v4;
	}
	v6 = nox_xxx_getFirstPlayerUnit_4DA7C0();
	if (!v6) {
		return sub_40A1F0(0);
	}
	do {
		v7 = *(uint32_t*)(v6 + 748);
		if (*(uint32_t*)(*(uint32_t*)(v7 + 276) + 4792) == 1) {
			++v1;
			if (*(uint32_t*)(v7 + 312)) {
				++v13;
			}
		}
		v6 = nox_xxx_getNextPlayerUnit_4DA7F0(v6);
	} while (v6);
	if (!v1) {
		return sub_40A1F0(0);
	}
	v12 = (double)v13 / (double)v1 * (double)v14;
	v9 = nox_float2int(v12);
	v10 = v0 - v9;
	if (v0 - v9 < v0 && (v0 -= v9, v2 != v10) || (result = sub_40A300()) == 0) {
		nox_xxx_servStartCountdown_40A2A0(v0, "objcoll.c:ExitCountdown");
		result = nox_xxx_netGauntlet_4D9E70(255);
	}
	return result;
}

//----- (004E8F60) --------------------------------------------------------
#ifdef NOX_CGO
bool nox_server_questAllowDefault();
#else  // !NOX_CGO
bool nox_server_questAllowDefault() { return getenv("NOX_QUEST_WARP_ALWAYS_ALLOW") != 0; }
#endif // NOX_CGO
bool nox_server_questMaybeWarp_4E8F60() {
	unsigned int curLvl = nox_game_getQuestStage_4E3CC0();
	unsigned int toLvl = nox_server_questNextStageThreshold_4D74F0(curLvl);
	int cnt = 0;
	bool allow = nox_server_questAllowDefault();
	for (void* unit = nox_xxx_getFirstPlayerUnit_4DA7C0(); unit; unit = nox_xxx_getNextPlayerUnit_4DA7F0(unit)) {
		int v4 = *(uint32_t*)((int)unit + 748);
		if (!nox_common_gameFlags_check_40A5C0(1) ||
			!nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) ||
			*(uint8_t*)(*(uint32_t*)(v4 + 276) + 2064) != 31) {
			int v5 = *(uint32_t*)(v4 + 276);
			if (*(uint32_t*)(v5 + 4792)) {
				++cnt;
				if (!*(uint32_t*)(v4 + 316)) {
					return 0;
				}
				if (*(uint32_t*)(v5 + 4696) >= toLvl) {
					allow = 1;
				}
			}
		}
	}
	if (!cnt) {
		return 0;
	}
	return allow;
}

//----- (004E9010) --------------------------------------------------------
int sub_4E9010() {
	int v0; // ebp
	int v1; // edi
	int v2; // esi

	v0 = 0;
	v1 = nox_xxx_getFirstPlayerUnit_4DA7C0();
	if (v1) {
		while (1) {
			v2 = *(uint32_t*)(v1 + 748);
			if (!nox_common_gameFlags_check_40A5C0(1) ||
				!nox_common_getEngineFlag(NOX_ENGINE_FLAG_DISABLE_GRAPHICS_RENDERING) ||
				*(uint8_t*)(*(uint32_t*)(v2 + 276) + 2064) != 31) {
				if (*(uint32_t*)(*(uint32_t*)(v2 + 276) + 4792)) {
					++v0;
					if (!*(uint32_t*)(v2 + 312)) {
						break;
					}
				}
			}
			v1 = nox_xxx_getNextPlayerUnit_4DA7F0(v1);
			if (!v1) {
				if (!v0) {
					return 0;
				}
				return 1;
			}
		}
	}
	return 0;
}

//----- (004E9090) --------------------------------------------------------
void nox_xxx_collideExit_4E9090(int a1, int a2, int a3) {
	int v4;           // ebp
	int v5;           // esi
	uint8_t* v6;      // edi
	int i;            // edi
	char v8;          // al
	int v9;           // ebx
	char* v10;        // edi
	int v11;          // edi
	int v12;          // edi
	int v13;          // eax
	unsigned int v14; // edi
	int v15;          // eax
	int j;            // esi
	int v17;          // eax
	int v18;          // eax
	const char* v19;  // [esp+8h] [ebp+8h]

	if (!dword_5d4594_1567960) {
		dword_5d4594_1567960 = nox_xxx_getNameId_4E3AA0("Glyph");
	}
	v4 = a2;
	if (!a2) {
		return;
	}
	if (!(*(uint8_t*)(a2 + 8) & 4)) {
		nullsub_34(a1, a2, a3);
		return;
	}
	v5 = *(uint32_t*)(a2 + 748);
	v6 = *(uint8_t**)(a1 + 700);
	v19 = *(const char**)(a1 + 700);
	if (nox_common_gameFlags_check_40A5C0(4096) && (*(char**)(v5 + 312) != 0 || *(char**)(v5 + 316) != 0)) {
		return;
	}
	if ((*(uint8_t*)(a1 + 12) & 2) && sub_4D75E0() == 0) {
		return;
	}
	if (sub_4DCC90() == 1) {
		return;
	}
	if (!sub_4DCC10(v4)) {
		return;
	}
	if (nox_xxx_checkGameFlagPause_413A50() == 1) {
		return;
	}
	if (!*v6 && nox_common_gameFlags_check_40A5C0(4096) == 0) {
		return;
	}
	if (*(uint8_t*)(*(uint32_t*)(v5 + 276) + 2251) == 1) {
		for (i = *(uint32_t*)(v4 + 516); i; i = *(uint32_t*)(i + 512)) {
			if (*(unsigned short*)(i + 4) == dword_5d4594_1567960 &&
				!*(uint32_t*)(i + 492)) {
				nox_xxx_delayedDeleteObject_4E5CC0(i);
				v8 = *(uint8_t*)(v5 + 244);
				if (v8) {
					*(uint8_t*)(v5 + 244) = v8 - 1;
				}
			}
		}
	}
	sub_4DCBF0(1);
	if (nox_common_gameFlags_check_40A5C0(2048)) {
		sub_4DB130("WORKING");
		sub_4DB170(1, a1, 0);
		return;
	}
	v9 = 1;
	if (nox_common_gameFlags_check_40A5C0(4096)) {
		v10 = nox_xxx_getQuestMapFile_4D0F60();
		v19 = v10;
	} else {
		v10 = (char*)v19;
	}
	if (!nox_common_gameFlags_check_40A5C0(4096)) {
		goto LABEL_47;
	}
	v11 = 1;
	do {
		if (nox_common_playerIsAbilityActive_4FC250(v4, v11)) {
			sub_4FC300((uint32_t*)v4, v11);
		}
		++v11;
	} while (v11 < 6);
	v12 = a1;
	v13 = *(uint32_t*)(a1 + 12);
	if (v13 & 1) {
		v14 = nox_game_getQuestStage_4E3CC0() + 1;
		sub_4D60E0(v4);
		v15 = *(uint32_t*)(v5 + 276);
		if (*(uint32_t*)(v15 + 4696) < v14) {
			*(uint32_t*)(v15 + 4696) = v14;
			sub_4D7450(*(unsigned char*)(*(uint32_t*)(v5 + 276) + 2064),
					   *(uint32_t*)(*(uint32_t*)(v5 + 276) + 4696));
		}
		*(uint32_t*)(v5 + 312) = a1;
		*(uint32_t*)(v5 + 316) = 0;
		nox_xxx_playerSetState_4FA020((uint32_t*)v4, 13);
		nox_xxx_playerGoObserver_4E6860(*(uint32_t*)(v5 + 276), 0, 0);
		nox_xxx_netInformTextMsg2_4DA180(18, (uint8_t*)(v4 + 36));
		v12 = a1;
		v9 = sub_4E9010();
	} else if (v13 & 2) {
		*(uint32_t*)(v5 + 312) = 0;
		*(uint32_t*)(v5 + 316) = a1;
		sub_4D75F0(nox_frame_xxx_2598000);
		nox_xxx_playerSetState_4FA020((uint32_t*)v4, 13);
		nox_xxx_playerGoObserver_4E6860(*(uint32_t*)(v5 + 276), 0, 0);
		for (j = nox_xxx_getFirstPlayerUnit_4DA7C0(); j;
			 j = nox_xxx_getNextPlayerUnit_4DA7F0(j)) {
			if (j != v4) {
				nox_xxx_netInformTextMsg_4DA0F0(
					*(unsigned char*)(*(uint32_t*)(*(uint32_t*)(j + 748) + 276) + 2064), 19,
					(int*)(v4 + 36));
			}
		}
		nox_xxx_netPriMsgToPlayer_4DA2C0(v4, "objcoll.c:PlayerEntersWarp", 0);
		v9 = nox_server_questMaybeWarp_4E8F60();
	}
	nox_xxx_aud_501960(1003, v12, 0, 0);
	if (!(*(uint8_t*)(v12 + 12) & 2) && !v9) {
		sub_4E8E60();
	}
	strcpy((char*)getMemAt(0x5D4594, 1567844), v19);
	if (v9 == 1) {
		v10 = (char*)v19;
	LABEL_47:
		if (v10 && *v10) {
			if (*(uint8_t*)(a1 + 12) & 2) {
				v17 = nox_game_getQuestStage_4E3CC0();
				v18 = nox_server_questNextStageThreshold_4D74F0(v17);
				nox_game_setQuestStage_4E3CD0(v18 - 1);
				sub_4D76E0(1);
				sub_4D60B0();
			}
			nox_xxx_mapLoad_4D2450(v10);
		}
	}
}
// 4E87A0: using guessed type void  nullsub_34(uint32_t, uint32_t, uint32_t);

//----- (004E9430) --------------------------------------------------------
void nox_xxx_collideDamage_4E9430(int a1, int a2) {
	unsigned char* v2; // ecx
	int v3;            // eax
	int v4;            // eax
	int v5;            // [esp-8h] [ebp-Ch]
	int v6;            // [esp-4h] [ebp-8h]

	v2 = *(unsigned char**)(a1 + 700);
	if (a2 && *(uint32_t*)(a2 + 556)) {
		if (*v2 == 1 && (unsigned char)nox_frame_xxx_2598000 & 1) {
			v3 = 1;
		} else {
			v3 = *v2 >> 1;
		}
		v6 = *((uint32_t*)v2 + 1);
		v5 = v3;
		v4 = nox_xxx_findParentChainPlayer_4EC580(a1);
		(*(void (**)(int, int, int, int, int))(a2 + 716))(a2, v4, a1, v5, v6);
	}
}

//----- (004E9490) --------------------------------------------------------
uint32_t* nox_xxx_collideManadrain_4E9490(int a1, int a2) {
	uint32_t* result; // eax

	result = (uint32_t*)a2;
	if (a2 && *(uint8_t*)(a2 + 8) & 4 && *(uint16_t*)(*(uint32_t*)(a2 + 748) + 4)) {
		nox_xxx_playerManaSub_4EEBF0(a2, **(unsigned char**)(a1 + 700));
		result = (uint32_t*)(nox_frame_xxx_2598000 - *(short*)(a1 + 542));
		if ((unsigned int)result > (int)nox_gameFPS >> 1) {
			result = nox_xxx_aud_501960(228, a1, 0, 0);
			*(uint16_t*)(a1 + 542) = (unsigned short)nox_frame_xxx_2598000;
		}
	}
	return result;
}

//----- (004E9500) --------------------------------------------------------

// Mix Patch new version with fixups

/*void  nox_xxx_spellFlyCollide_4E9500(int a1, int a2, float *a3)
{
  int v3; // esi
  float2 *v4; // edi
  int v5; // ebx
  int v6; // ebp
  int v7; // ecx
  int v8; // ebx
  int v9; // eax
  int v10; // [esp+10h] [ebp-10h]
  int v11[3]; // [esp+14h] [ebp-Ch]

  v3 = a2;
  v4 = (float2 *)a1;
  v5 = *(uint32_t *)(a1 + 748);
  v10 = *(uint32_t *)(a1 + 748);
  if ( a2 )
  {
	if ( *(uint32_t *)(a2 + 16) & 0x8020 )
	  return;
	if ( !(*(uint8_t *)(a2 + 8) & 4) )
	  goto LABEL_23;
	v6 = *(uint32_t *)(a2 + 748);
	if ( *(uint8_t *)(v6 + 88) == 16 && nox_xxx_checkReflectShield_4E6E50((float2 *)(a2 + 56), *(short *)(a2 + 124),
(float2 *)(a1 + 72)) & 1 )
	{
	  nox_xxx_aud_501960(878, v3, 0, 0);
	  nox_xxx_projectileReflect_4E0A70((int)v4, v3);
	  nox_xxx_changeOwner_52BE40((int)v4, v3);
	  return;
	}
	if ( *(uint8_t *)(v6 + 88) == 13 || (!*(uint8_t *)(v6 + 88) && dword_980858[0] & 0x40000 ) )
	{
	  v7 = *(uint32_t *)(*(uint32_t *)(v6 + 276) + 4);
	  if ( v7 & 0x400 )
	  {
	if ( nox_xxx_checkReflectShield_4E6E50((float2 *)(v3 + 56), *(short *)(v3 + 124), v4 + 9) & 1 )
	{
	  v8 = nox_xxx_randInt_415FA0(18, 20);
	  nox_xxx_aud_501960(890, v3, 0, 0);
	  nox_xxx_projectileReflect_4E0A70((int)v4, v3);
	  nox_xxx_changeOwner_52BE40((int)v4, v3);
	  nox_xxx_playerSetState_4FA020((uint32_t *)v3, v8);
	  v9 = nox_xxx_playerMapAnimState_4FA2B0(v3);
	  nox_xxx_animPlayerGetFrameRange_4F9F90(v9, &a1, &a2);
	  v5 = v10;
	  *(uint8_t *)(v6 + 236) = a1 - 1;
	}
	  }
	}
M_LABEL_13:
	if ( nox_xxx_checkInversionEffect_4FA4F0(v3, (int)v4) )
	{
	  nox_xxx_changeOwner_52BE40((int)v4, v3);
	  return;
	}
	if ( nox_xxx_testUnitBuffs_4FF350(v3, 27) && nox_xxx_checkReflectShield_4E6E50((float2 *)(v3 + 56), *(short *)(v3 +
124), v4 + 7) & 1 )
	{
	  nox_xxx_changeOwner_52BE40((int)v4, v3);
	  nox_xxx_aud_501960(122, v3, 0, 0);
	}
	else
	{
LABEL_23:
	  if ( *(uint32_t *)(v5 + 4) == v3 )
	  {
	v11[0] = v3;
	nox_xxx_spellAccept_4FD400(*(uint32_t *)(v5 + 12), *(uint32_t *)(v5 + 8), *(uint32_t **)v5, (int)v4, v11, *(uint32_t
*)(v5 + 16)); nox_xxx_delayedDeleteObject_4E5CC0((int)v4);
	  }
	  else
	  {
	nox_xxx_projectileReflect_4E0A70((int)v4, v3);
	  }
	}
  }
  else if ( a3 )
  {
	nox_xxx_collideReflect_57B810(a3, a1 + 80);
  }
}*/
void nox_xxx_spellFlyCollide_4E9500(int a1, int a2, float* a3) {
	int v3;     // esi
	float2* v4; // edi
	int v5;     // ebx
	int v6;     // ebp
	int v7;     // ecx
	int v8;     // ebx
	int v9;     // eax
	char v10;   // al
	int v11;    // [esp+10h] [ebp-10h]
	int v12[3]; // [esp+14h] [ebp-Ch]

	v3 = a2;
	v4 = (float2*)a1;
	v5 = *(uint32_t*)(a1 + 748);
	v11 = *(uint32_t*)(a1 + 748);
	if (!a2) {
		if (a3) {
			nox_xxx_collideReflect_57B810(a3, a1 + 80);
		}
		return;
	}
	if (*(uint32_t*)(a2 + 16) & 0x8020) {
		return;
	}
	if (*(uint8_t*)(a2 + 8) & 4) {
		v6 = *(uint32_t*)(a2 + 748);
		if (*(uint8_t*)(v6 + 88) != 16) {
			if (*(uint8_t*)(v6 + 88) != 1 || nox_common_mapPlrActionToStateId_4FA2B0(a2) != 45 ||
				(v10 = *(uint8_t*)(*(uint32_t*)(v6 + 276) + 3), v10 != 1) && v10 != 2) {
			LABEL_22:
				if (*(uint8_t*)(v6 + 88) == 13 ||
					!*(uint8_t*)(v6 + 88) && gameex_flags & 0x4) // GREAT_SWORD_BLOKING_WALK
				{
					v7 = *(uint32_t*)(*(uint32_t*)(v6 + 276) + 4);
					if (v7 & 0x400 &&
						nox_server_testTwoPointsAndDirection_4E6E50((float2*)(v3 + 56), *(short*)(v3 + 124), v4 + 9) &
							1) {
						v8 = nox_common_randomInt_415FA0(18, 20);
						nox_xxx_aud_501960(890, v3, 0, 0);
						nox_xxx_projectileReflect_4E0A70((int)v4, v3);
						nox_xxx_changeOwner_52BE40((int)v4, v3);
						nox_xxx_playerSetState_4FA020((uint32_t*)v3, v8);
						v9 = nox_common_mapPlrActionToStateId_4FA2B0(v3);
						nox_xxx_animPlayerGetFrameRange_4F9F90(v9, &a1, &a2);
						v5 = v11;
						*(uint8_t*)(v6 + 236) = a1 - 1;
					}
				}
			LABEL_13:
				if (nox_xxx_checkInversionEffect_4FA4F0(v3, (int)v4)) {
					nox_xxx_changeOwner_52BE40((int)v4, v3);
					return;
				}
				if (nox_xxx_testUnitBuffs_4FF350(v3, 27) &&
					nox_server_testTwoPointsAndDirection_4E6E50((float2*)(v3 + 56), *(short*)(v3 + 124), v4 + 7) & 1) {
					nox_xxx_changeOwner_52BE40((int)v4, v3);
					nox_xxx_aud_501960(122, v3, 0, 0);
					return;
				}
				goto LABEL_18;
			}
			if (!(gameex_flags & 0x10)) { // BERSERKER_SHIED_BLOCK
				goto LABEL_13;
			}
		}
		if (nox_server_testTwoPointsAndDirection_4E6E50((float2*)(a2 + 56), *(short*)(a2 + 124), (float2*)(a1 + 72)) &
			1) {
			nox_xxx_aud_501960(878, v3, 0, 0);
			nox_xxx_projectileReflect_4E0A70((int)v4, v3);
			nox_xxx_changeOwner_52BE40((int)v4, v3);
			return;
		}
		goto LABEL_22;
	}
LABEL_18:
	if (*(uint32_t*)(v5 + 4) == v3) {
		v12[0] = v3;
		nox_xxx_spellAccept_4FD400(*(uint32_t*)(v5 + 12), *(uint32_t*)(v5 + 8), *(uint32_t**)v5, (int)v4, v12,
								   *(uint32_t*)(v5 + 16));
		nox_xxx_delayedDeleteObject_4E5CC0((int)v4);
	} else {
		nox_xxx_projectileReflect_4E0A70((int)v4, v3);
	}
}

//----- (004E96F0) --------------------------------------------------------
void nox_xxx_collideBomb_4E96F0(int a1, int a2) {
	int v2; // ebx
	int v3; // eax

	v2 = *(uint32_t*)(a1 + 748);
	if (!nox_common_gameFlags_check_40A5C0(2048) ||
		(*(uint8_t*)((int)nox_xxx_getFirstPlayerUnit_4DA7C0() + 16) & 2) != 2) {
		nox_xxx_scriptCallByEventBlock_502490((int*)(v2 + 1272), a2, a1, 21);
		if (a2 && *(uint8_t*)(a2 + 8) & 6 && !nox_xxx_unitsHaveSameTeam_4EC520(a1, a2)) {
			v3 = *(uint32_t*)(a2 + 16);
			if ((v3 & 0x8000) == 0) {
				*(uint32_t*)(v2 + 2176) = a2;
				nox_xxx_unitDamageClear_4EE5E0(a1, 999);
			}
		}
	}
}

//----- (004E9770) --------------------------------------------------------
void nox_xxx_collideBoom_4E9770(int a1, int a2, float* a3) {
	int v3;     // eax
	float v4;   // edx
	short v5;   // ax
	double v6;  // st7
	int* v7;    // eax
	int v8;     // eax
	int v9;     // [esp-Ch] [ebp-18h]
	float v10;  // [esp+0h] [ebp-Ch]
	float v11;  // [esp+0h] [ebp-Ch]
	float2 v12; // [esp+4h] [ebp-8h]

	if (!*getMemU32Ptr(0x5D4594, 1567964)) {
		v10 = nox_xxx_gamedataGetFloat_419D40("MagicMissileDamage");
		*getMemU32Ptr(0x5D4594, 1567968) = nox_float2int(v10);
		v11 = nox_xxx_gamedataGetFloat_419D40("MagicMissileSplashDamage");
		*getMemU32Ptr(0x5D4594, 1567972) = nox_float2int(v11);
		*getMemFloatPtr(0x5D4594, 1567976) = nox_xxx_gamedataGetFloat_419D40("MagicMissileRange");
		*getMemFloatPtr(0x5D4594, 1567980) = nox_xxx_gamedataGetFloat_419D40("MagicMissilePushRange");
		*getMemFloatPtr(0x5D4594, 1567984) = nox_xxx_gamedataGetFloat_419D40("MagicMissileForce");
		*getMemU32Ptr(0x5D4594, 1567964) = 1;
	}
	if (!nox_common_gameFlags_check_40A5C0(4096) || (v3 = nox_xxx_findParentChainPlayer_4EC580(a1)) == 0 || !a2 ||
		!(*(uint8_t*)(v3 + 8) & 4) || !(*(uint8_t*)(a2 + 8) & 4) || nox_xxx_unitIsEnemyTo_5330C0(v3, a2)) {
		if (a1) {
			nox_xxx_netSendPointFx_522FF0(134, (float2*)(a1 + 56));
		}
		if (a2) {
			if (*(uint8_t*)(a2 + 8) & 4) {
				if (nox_xxx_checkInversionEffect_4FA4F0(a2, a1)) {
					nox_xxx_changeOwner_52BE40(a1, a2);
					return;
				}
				if (nox_xxx_testUnitBuffs_4FF350(a2, 27) &&
					nox_server_testTwoPointsAndDirection_4E6E50((float2*)(a2 + 56), *(short*)(a2 + 124),
																(float2*)(a1 + 56)) &
						1) {
					nox_xxx_changeOwner_52BE40(a1, a2);
					nox_xxx_aud_501960(122, a2, 0, 0);
					return;
				}
			}
			v9 = *getMemU32Ptr(0x5D4594, 1567968);
			v8 = nox_xxx_findParentChainPlayer_4EC580(a1);
			(*(void (**)(int, int, int, int, int))(a2 + 716))(a2, v8, a1, v9, 7);
			nox_xxx_sMakeScorch_537AF0((int*)(a2 + 56), 0);
		} else if (a3) {
			nox_xxx_collideReflect_57B810(a3, a1 + 80);
			v4 = *(float*)(a1 + 84);
			v12.field_0 = *(float*)(a1 + 80);
			v12.field_4 = v4;
			v5 = nox_xxx_math_509ED0(&v12);
			v6 = *(float*)(a1 + 80) * 0.5;
			*(uint16_t*)(a1 + 126) = v5;
			*(float*)(a1 + 80) = v6;
			*(float*)(a1 + 84) = *(float*)(a1 + 84) * 0.5;
			v7 = (int*)sub_537760();
			if (v7) {
				nox_xxx_damageToMap_534BC0(*v7, v7[1], *getMemIntPtr(0x5D4594, 1567968), 7, a1);
			}
			return;
		}
		nox_xxx_mapDamageUnitsAround_4E25B0(a1 + 56, *getMemFloatPtr(0x5D4594, 1567976), 5.0,
											*getMemIntPtr(0x5D4594, 1567972), 7, a1, 0);
		nox_xxx_mapPushUnitsAround_52E040(a1 + 56, *getMemFloatPtr(0x5D4594, 1567980), *getMemIntPtr(0x5D4594, 1567980),
										  *getMemFloatPtr(0x5D4594, 1567984), a1, 0, 0);
		nox_xxx_aud_501960(84, a1, 0, 0);
		nox_xxx_delayedDeleteObject_4E5CC0(a1);
	}
}

//----- (004E99B0) --------------------------------------------------------
void nox_xxx_collideDie_4E99B0(int unit, int a2) {
	int v2;                      // edx
	void (*deleteOverride)(int); // eax

	if (a2 && !nox_xxx_unitsHaveSameTeam_4EC520(unit, a2) && *(uint8_t*)(a2 + 8) & 6) {
		v2 = *(uint32_t*)(unit + 16);
		deleteOverride = *(void (**)(int))(unit + 724);
		BYTE1(v2) |= 0x80u;
		*(uint32_t*)(unit + 16) = v2;
		if (deleteOverride) {
			deleteOverride(unit);
		} else {
			nox_xxx_delayedDeleteObject_4E5CC0(unit);
		}
	}
}

//----- (004E9A00) --------------------------------------------------------
char nox_xxx_collideGlyph_4E9A00(int a1, int a2) {
	int v2; // eax

	v2 = sub_4E9A30(a1, a2);
	if (v2) {
		LOBYTE(v2) = nox_xxx_trapBAH_537C10(a1, a2);
	}
	return v2;
}

//----- (004E9A30) --------------------------------------------------------
int sub_4E9A30(int a1, int a2) {
	int v3; // esi
	int v4; // eax
	int v5; // esi

	if (nox_common_gameFlags_check_40A5C0(2048) &&
		(*(uint8_t*)((int)nox_xxx_getFirstPlayerUnit_4DA7C0() + 16) & 2) == 2) {
		return 0;
	}
	v5 = 1;
	if (a2) {
		if (nox_xxx_unitsHaveSameTeam_4EC520(a1, a2) ||
			nox_common_gameFlags_check_40A5C0(512) &&
				(v3 = nox_xxx_findParentChainPlayer_4EC580(a1), v4 = nox_xxx_findParentChainPlayer_4EC580(a2),
				 *(uint8_t*)(v3 + 8) & 4) &&
				*(uint8_t*)(v4 + 8) & 4) {
			v5 = 0;
		}
	}
	if (nox_common_playerIsAbilityActive_4FC250(a2, 4)) {
		v5 = 0;
	}
	return v5;
}

//----- (004E9AC0) --------------------------------------------------------
void nox_xxx_fireballCollide_4E9AC0(int a1, int a2) {
	int v2;           // esi
	char* v3;         // ebp
	int v4;           // ebx
	int v5;           // eax
	int v6;           // eax
	float v7;         // [esp+0h] [ebp-28h]
	float v8;         // [esp+0h] [ebp-28h]
	int v9;           // [esp+4h] [ebp-24h]
	int v10;          // [esp+8h] [ebp-20h]
	int v11;          // [esp+10h] [ebp-18h]
	int v12;          // [esp+10h] [ebp-18h]
	int v13;          // [esp+14h] [ebp-14h]
	unsigned int v14; // [esp+2Ch] [ebp+4h]

	v2 = a1;
	v3 = *(char**)(a1 + 700);
	v4 = 1;
	if (a2 && nox_xxx_testUnitBuffs_4FF350(a2, 27) &&
		nox_server_testTwoPointsAndDirection_4E6E50((float2*)(a2 + 56), *(short*)(a2 + 124), (float2*)(a1 + 56)) & 1) {
		nox_xxx_projectileReflect_4E0A70(a1, a2);
		nox_xxx_unitClearOwner_4EC300(a1);
		nox_xxx_unitSetOwner_4EC290(a2, a1);
		v4 = 0;
		nox_xxx_aud_501960(122, a2, 0, 0);
	}
	if (!nox_common_gameFlags_check_40A5C0(4096) || (v5 = nox_xxx_findParentChainPlayer_4EC580(a1)) == 0 || !a2 ||
		!(*(uint8_t*)(v5 + 8) & 4) || !(*(uint8_t*)(a2 + 8) & 4) || nox_xxx_unitIsEnemyTo_5330C0(v5, a2)) {
		if (v4) {
			v7 = (double)(unsigned char)*v3 * 0.66666669;
			nox_xxx_mapPushUnitsAround_52E040(a1 + 56, v7, 0, 50.0, a1, 0, 0);
			if (a2) {
				v11 = (unsigned char)*v3 >> 1;
				v6 = nox_xxx_findParentChainPlayer_4EC580(a1);
				(*(void (**)(int, int, int, int, int))(a2 + 716))(a2, v6, a1, v11, 1);
			}
			if (nox_common_gameFlags_check_40A5C0(2048)) {
				v13 = a2;
				v12 = a1;
				v14 = (unsigned char)*v3;
				v10 = v14 >> 1;
				v9 = 0;
			} else {
				v13 = a2;
				v12 = a1;
				v14 = (unsigned char)*v3;
				v10 = v14 >> 1;
				v9 = 1097859072;
			}
			v8 = (double)(int)v14 * 0.33333334;
			nox_xxx_mapDamageUnitsAround_4E25B0(v2 + 56, v8, *(float*)&v9, v10, 1, v12, v13);
			nox_xxx_netSparkExplosionFx_5231B0((float*)(v2 + 56), *v3);
			nox_xxx_aud_501960(42, v2, 0, 0);
			nox_xxx_sMakeScorch_537AF0((int*)(v2 + 56), 2);
			nox_xxx_delayedDeleteObject_4E5CC0(v2);
		}
	}
}

//----- (004E9C40) --------------------------------------------------------
void nox_xxx_collideChest_4E9C40(uint32_t* a1, int a2) {
	int v2;                // esi
	int v3;                // eax
	int v4;                // eax
	int i;                 // ebp
	void (*v6)(uint32_t*); // eax

	v2 = a2;
	if (a2) {
		if (*(uint8_t*)(a2 + 8) & 4) {
			v3 = a1[4];
			if ((v3 & 0x8000) == 0) {
				if (nox_common_gameFlags_check_40A5C0(4096) && (v4 = a1[3], BYTE1(v4) & 0xF)) {
					for (i = nox_xxx_inventoryGetFirst_4E7980(a2); i; i = nox_xxx_inventoryGetNext_4E7990(i)) {
						if (*(uint8_t*)(i + 8) & 0x40) {
							if (!strcmp((const char*)nox_xxx_getUnitName_4E39D0(i), "SilverKey")) {
								nox_xxx_delayedDeleteObject_4E5CC0(i);
								nox_xxx_aud_501960(234, (int)a1, 0, 0);
								v2 = a2;
								goto LABEL_14;
							}
							v2 = a2;
						}
					}
					if ((unsigned long long)(nox_platform_get_ticks() - *(uint64_t*)&qword_5d4594_1567940) > 0x5DC) {
						nox_xxx_aud_501960(1012, (int)a1, 0, 0);
						nox_xxx_netPriMsgToPlayer_4DA2C0(v2, "objcoll.c:ChestLockedSilver", 0);
						*(uint64_t*)&qword_5d4594_1567940 = nox_platform_get_ticks();
					}
				} else {
				LABEL_14:
					v6 = (void (*)(uint32_t*))a1[181];
					if (v6) {
						v6(a1);
					}
					nox_xxx_chest_4EDF00((int)a1, v2);
					nox_xxx_dropAllItems_4EDA40(a1);
				}
			}
		}
	}
}

//----- (004E9D80) --------------------------------------------------------
void nox_xxx_collideSulphurShot2_4E9D80(int a1, int a2, float* a3) {
	int* v3;  // edi
	int v4;   // eax
	int v5;   // edi
	int v6;   // eax
	float v7; // [esp+0h] [ebp-20h]
	float v8; // [esp+4h] [ebp-1Ch]
	int v9;   // [esp+4h] [ebp-1Ch]
	int v10;  // [esp+8h] [ebp-18h]

	v3 = *(int**)(a1 + 700);
	if (a2) {
		if (!nox_xxx_unitsHaveSameTeam_4EC520(a1, a2)) {
			if (nox_common_gameFlags_check_40A5C0(4096) &&
				*(void (**)(int, int, int))(a1 + 696) == nox_xxx_collideSulphurShot_4E9E50) {
				v5 = 3 * *v3;
			} else {
				v5 = *v3;
			}
			v6 = nox_xxx_findParentChainPlayer_4EC580(a1);
			if ((*(int (**)(int, int, int, int, int))(a2 + 716))(a2, v6, a1, v5, 11)) {
				nox_xxx_delayedDeleteObject_4E5CC0(a1);
			}
		}
	} else if (a3) {
		nox_xxx_collideReflect_57B810(a3, a1 + 80);
		v10 = *v3;
		v8 = *(float*)(a1 + 68) * 0.043478262;
		v9 = nox_float2int(v8);
		v7 = *(float*)(a1 + 64) * 0.043478262;
		v4 = nox_float2int(v7);
		nox_xxx_damageToMap_534BC0(v4, v9, v10, 11, a1);
	}
}

//----- (004E9E50) --------------------------------------------------------
void nox_xxx_collideSulphurShot_4E9E50(int a1, int a2, int a3) {
	if (a1 && !nox_common_gameFlags_check_40A5C0(4)) {
		nox_xxx_netSendPointFx_522FF0(136, (float2*)(a1 + 56));
	}
	nox_xxx_collideSulphurShot2_4E9D80(a1, a2, (float*)a3);
}

//----- (004E9E90) --------------------------------------------------------
int* nox_xxx_collideDeathBall_4E9E90(int a1, int a2, float* a3) {
	int* result; // eax
	int* v4;     // esi
	int v5;      // eax
	int v6;      // eax
	int v7;      // edx
	double v8;   // st7
	double v9;   // st6
	double v10;  // st5
	int v11;     // eax
	float v12;   // [esp+0h] [ebp-1Ch]
	float v13;   // [esp+4h] [ebp-18h]
	int v14;     // [esp+4h] [ebp-18h]
	float2 a2a;  // [esp+14h] [ebp-8h]

	if (a2) {
		if ((signed char)*(uint8_t*)(a2 + 8) >= 0) {
			v13 = nox_xxx_gamedataGetFloat_419D40("DeathBallCollideDamage");
			v14 = nox_float2int(v13);
			v11 = nox_xxx_findParentChainPlayer_4EC580(a1);
			result = (int*)(*(int (**)(int, int, int, int, int))(a2 + 716))(a2, v11, a1, v14, 2);
		} else {
			v6 = *(uint32_t*)(a2 + 748);
			v7 = *(uint32_t*)(a1 + 76);
			*(uint32_t*)(a1 + 64) = *(uint32_t*)(a1 + 72);
			*(uint32_t*)(a1 + 68) = v7;
			v8 = *(float*)(a2 + 56) - *(float*)(a1 + 72);
			v9 = *(float*)(a2 + 60) - *(float*)(a1 + 76);
			a2a.field_0 = -(double)*getMemIntPtr(0x587000, 196188 + 8 * *(uint32_t*)(v6 + 12));
			v10 = (double)*getMemIntPtr(0x587000, 196184 + 8 * *(uint32_t*)(v6 + 12));
			a2a.field_4 = v10;
			if (v10 * v9 + a2a.field_0 * v8 > 0.0) {
				a2a.field_0 = -a2a.field_0;
				a2a.field_4 = -a2a.field_4;
			}
			sub_57B770((float2*)(a1 + 80), &a2a);
			result = nox_xxx_aud_501960(283, a1, 0, 0);
		}
	} else {
		result = (int*)a3;
		if (a3) {
			nox_xxx_collideReflect_57B810(a3, a1 + 80);
			nox_xxx_aud_501960(37, a1, 0, 0);
			result = (int*)sub_537760();
			v4 = result;
			if (result) {
				v12 = nox_xxx_gamedataGetFloat_419D40("DeathBallCollideDamage");
				v5 = nox_float2int(v12);
				result = (int*)nox_xxx_damageToMap_534BC0(*v4, v4[1], v5, 2, a1);
			}
		}
	}
	return result;
}

//----- (004E9FE0) --------------------------------------------------------
void nox_xxx_collideDeathBallFragment_4E9FE0(int a1, int a2, float* a3) {
	int v3;   // eax
	int v4;   // eax
	float v5; // [esp+0h] [ebp-1Ch]
	float v6; // [esp+4h] [ebp-18h]
	int v7;   // [esp+4h] [ebp-18h]

	if (a2) {
		v4 = nox_xxx_findParentChainPlayer_4EC580(a1);
		(*(void (**)(int, int, int, int, int))(a2 + 716))(a2, v4, a1, 20, 2);
	} else if (a3) {
		nox_xxx_collideReflect_57B810(a3, a1 + 80);
		nox_xxx_aud_501960(37, a1, 0, 0);
		v6 = *(float*)(a1 + 68) * 0.043478262;
		v7 = nox_float2int(v6);
		v5 = *(float*)(a1 + 64) * 0.043478262;
		v3 = nox_float2int(v5);
		nox_xxx_damageToMap_534BC0(v3, v7, 20, 2, a1);
		return;
	}
	nox_xxx_delayedDeleteObject_4E5CC0(a1);
}

//----- (004EA080) --------------------------------------------------------
void nox_xxx_collidePixie_4EA080(int a1, int a2, float* a3) {
	int* v3;   // ebp
	short v4;  // ax
	double v5; // st7
	double v6; // st7
	int v7;    // eax
	int v8;    // ecx
	int v9;    // eax
	int v10;   // eax
	float v11; // [esp+0h] [ebp-20h]
	float v12; // [esp+4h] [ebp-1Ch]
	int v13;   // [esp+4h] [ebp-1Ch]
	int v14;   // [esp+8h] [ebp-18h]
	int v15;   // [esp+Ch] [ebp-14h]

	v3 = *(int**)(a1 + 700);
	if (a2) {
		if (nox_xxx_unitIsEnemyTo_5330C0(a1, a2)) {
			v8 = *(uint32_t*)(a2 + 8);
			if (v8 & 0x20006) {
				if (!(*(uint32_t*)(a2 + 16) & 0x8020)) {
					v9 = *(uint32_t*)(a1 + 508);
					if (!v9 || (*(uint8_t*)(v9 + 8) & 4) != 4 || (*(uint8_t*)(v9 + 16) & 2) != 2) {
						if (!(v8 & 4)) {
							goto LABEL_20;
						}
						if (nox_xxx_checkInversionEffect_4FA4F0(a2, a1)) {
							nox_xxx_changeOwner_52BE40(a1, a2);
							return;
						}
						if (nox_xxx_testUnitBuffs_4FF350(a2, 27) &&
							nox_server_testTwoPointsAndDirection_4E6E50((float2*)(a2 + 56), *(short*)(a2 + 124),
																		(float2*)(a1 + 56)) &
								1) {
							nox_xxx_changeOwner_52BE40(a1, a2);
							nox_xxx_aud_501960(122, a2, 0, 0);
						} else {
						LABEL_20:
							v15 = *v3;
							v10 = nox_xxx_findParentChainPlayer_4EC580(a1);
							(*(void (**)(int, int, int, int, int))(a2 + 716))(a2, v10, a1, v15, 11);
							nox_xxx_aud_501960(96, a1, 0, 0);
							nox_xxx_delayedDeleteObject_4E5CC0(a1);
						}
					}
				}
			}
		}
	} else if (a3) {
		nox_xxx_collideReflect_57B810(a3, a1 + 80);
		v4 = nox_xxx_math_509ED0((float2*)(a1 + 80));
		v5 = *(float*)(a1 + 80) + *(float*)(a1 + 64);
		*(uint16_t*)(a1 + 126) = v4;
		*(float*)(a1 + 64) = v5;
		v6 = *(float*)(a1 + 84) + *(float*)(a1 + 68);
		*(float*)(a1 + 68) = v6;
		v14 = *v3;
		v12 = v6 * 0.043478262;
		v13 = nox_float2int(v12);
		v11 = *(float*)(a1 + 64) * 0.043478262;
		v7 = nox_float2int(v11);
		nox_xxx_damageToMap_534BC0(v7, v13, v14, 11, a1);
	} else {
		nox_xxx_delayedDeleteObject_4E5CC0(a1);
	}
}

//----- (004EA200) --------------------------------------------------------
void nox_xxx_collideWallReflectSpark_4EA200(int a1, int a2, float2* a3) {
	int* v3;   // ecx
	double v5; // st7
	int v8;    // eax
	int v9;    // eax
	float v10; // [esp+0h] [ebp-1Ch]
	float v11; // [esp+4h] [ebp-18h]
	int v12;   // [esp+4h] [ebp-18h]
	int v13;   // [esp+8h] [ebp-14h]
	int v14;   // [esp+Ch] [ebp-10h]

	v3 = *(int**)(a1 + 700);
	if (a2) {
		v14 = *v3;
		v9 = nox_xxx_findParentChainPlayer_4EC580(a1);
		if ((*(int (**)(int, int, int, int, int))(a2 + 716))(a2, v9, a1, v14, 11)) {
			nox_xxx_delayedDeleteObject_4E5CC0(a1);
		}
	} else if (a3) {
		v5 = *(float*)(a1 + 80);
		if (a3->field_0 * a3->field_4 <= 0.0) {
			*(float*)(a1 + 80) = *(float*)(a1 + 84);
		} else {
			*(float*)(a1 + 80) = -*(float*)(a1 + 84);
			v5 = -v5;
		}
		*(float*)(a1 + 84) = v5;
		v13 = *v3;
		v11 = *(float*)(a1 + 68) * 0.043478262;
		v12 = nox_float2int(v11);
		v10 = *(float*)(a1 + 64) * 0.043478262;
		v8 = nox_float2int(v10);
		nox_xxx_damageToMap_534BC0(v8, v12, v13, 11, a1);
	}
}

//----- (004EA2C0) --------------------------------------------------------
void sub_4EA2C0(int a1, int a2) {
	int v2; // eax

	if (a2) {
		if (*(uint8_t*)(a2 + 8) & 4) {
			v2 = *(uint32_t*)(a1 + 508);
			if (v2 != a2 && !v2) {
				*(uint32_t*)(a1 + 136) = nox_frame_xxx_2598000;
				nox_xxx_unitSetOwner_4EC290(a2, a1);
			}
		}
	}
}

//----- (004EA300) --------------------------------------------------------
void nox_xxx_collideSpark_4EA300(int a1, int a2, float* a3) {
	char v3; // al

	if (*(uint32_t*)(*(uint32_t*)(a1 + 748) + 12) != 4) {
		if (*(uint32_t*)(*(uint32_t*)(a1 + 748) + 12) == 5) {
			if (a2) {
				nox_xxx_aud_501960(351, a1, 0, 0);
				nox_xxx_delayedDeleteObject_4E5CC0(a1);
				v3 = *(uint8_t*)(a2 + 8);
				++*(uint8_t*)(a2 + 541);
				*(uint16_t*)(a2 + 542) = 1000;
				if (v3 & 4) {
					nox_xxx_netPriMsgToPlayer_4DA2C0(a2, "objcoll.c:WebbingSlow", 0);
				}
			}
		} else {
			nox_xxx_collideSulphurShot2_4E9D80(a1, a2, a3);
		}
	}
}

//----- (004EA380) --------------------------------------------------------
void nox_xxx_collideWebbing_4EA380(int a1, int a2) {
	int v2; // eax

	if (a2) {
		nox_xxx_aud_501960(351, a1, 0, 0);
		nox_xxx_delayedDeleteObject_4E5CC0(a1);
		v2 = nox_xxx_findParentChainPlayer_4EC580(a1);
		if ((*(int (**)(int, int, int, uint32_t, int))(a2 + 716))(a2, v2, a1, 0, 2)) {
			if (*(uint8_t*)(a2 + 8) & 6) {
				nox_xxx_buffApplyTo_4FF380(a2, 4, 4 * (uint16_t)nox_gameFPS, 3);
			}
			if (*(uint8_t*)(a2 + 8) & 4) {
				nox_xxx_netPriMsgToPlayer_4DA2C0(a2, "objcoll.c:WebbingSlow", 0);
			}
		}
	}
}

//----- (004EA400) --------------------------------------------------------
void sub_4EA400(int a1, int a2) {
	int v2; // eax
	int v3; // eax

	if (a2) {
		v2 = *(uint32_t*)(a2 + 16);
		if ((v2 & 0x8000) == 0) {
			if (nox_common_gameFlags_check_40A5C0(32)) {
				if (*(uint8_t*)(a2 + 8) & 4) {
					nox_xxx_pickupFlagCtf_4EA490(a1, a2);
				}
			} else if (nox_common_gameFlags_check_40A5C0(64)) {
				v3 = *getMemU32Ptr(0x5D4594, 1567996);
				if (!*getMemU32Ptr(0x5D4594, 1567996)) {
					v3 = nox_xxx_getNameId_4E3AA0("GameBall");
					*getMemU32Ptr(0x5D4594, 1567996) = v3;
				}
				if (*(unsigned short*)(a2 + 4) == v3 || *(uint8_t*)(a2 + 8) & 4) {
					sub_4EA800(a1, a2);
				}
			}
		}
	}
}

//----- (004EA490) --------------------------------------------------------
void nox_xxx_pickupFlagCtf_4EA490(int a1, int a2) {
	int v2;            // esi
	int v3;            // edi
	char v4;           // bp
	int v5;            // ebx
	int v6;            // esi
	unsigned short v7; // ax
	int v8;            // ebp
	int v9;            // ebx
	char* v10;         // eax
	char* v11;         // esi
	char* v12;         // eax
	uint32_t* v13;     // eax
	int v14;           // ebx
	float2* v15;       // [esp-4h] [ebp-24h]
	unsigned char v16; // [esp+10h] [ebp-10h]
	unsigned char v17; // [esp+10h] [ebp-10h]
	char v18[10];      // [esp+14h] [ebp-Ch]
	int v19;           // [esp+24h] [ebp+4h]
	int v20;           // [esp+24h] [ebp+4h]

	v2 = a1;
	v3 = a2;
	a2 = *(uint32_t*)(a2 + 748);
	v4 = sub_4ECBD0(a1);
	v16 = *(uint8_t*)(a1 + 52);
	if (nox_xxx_servCompareTeams_419150(v3 + 48, a1 + 48)) {
		v5 = *(uint32_t*)(a1 + 748);
		if (fabs(*(float*)(a1 + 56) - *(float*)v5) > *getMemDoublePtr(0x581450, 10160) ||
			fabs(*(float*)(a1 + 60) - *(float*)(v5 + 4)) > *getMemDoublePtr(0x581450, 10160)) {
			v15 = *(float2**)(a1 + 748);
			a2 = *(uint32_t*)(v3 + 36);
			nox_xxx_unitMove_4E7010(a1, v15);
			nox_xxx_netInformTextMsg2_4DA180(4, &a2);
			*(uint32_t*)(v5 + 8) = 0;
			sub_4E82C0(*(uint8_t*)(v3 + 52), 0, v4, 0);
		} else {
			v6 = *(uint32_t*)(v3 + 504);
			if (v6) {
				while (1) {
					if (*(uint32_t*)(v6 + 8) & 0x10000000) {
						v7 = nox_xxx_servGamedataGet_40A020(32);
						v8 = *(uint32_t*)(v6 + 748);
						v9 = v7;
						v19 = sub_4ECBD0(v6);
						v17 = *(uint8_t*)(v6 + 52);
						nox_xxx_changeScore_4D8E90(v3, 1);
						nox_xxx_netReportLesson_4D8EF0(v3);
						if (nox_xxx_servObjectHasTeam_419130(v3 + 48)) {
							v10 = nox_xxx_clientGetTeamColor_418AB0(*(unsigned char*)(v3 + 52));
							nox_xxx_netChangeTeamID_419090((int)v10, *((uint32_t*)v10 + 13) + 1);
							if (dword_5d4594_2650652) {
								if (a2) {
									sub_425CA0(*(uint32_t*)(a2 + 276), 0);
								}
							}
						}
						sub_4ED0C0(v3, (int*)v6);
						nox_xxx_createAt_4DAA50(v6, 0, *(float*)v8, *(float*)(v8 + 4));
						nox_xxx_unitRaise_4E46F0(v6, 0.0);
						nox_xxx_netMarkMinimapForAll_4174B0(v6, 1);
						*(uint32_t*)(v8 + 8) = 0;
						sub_4E82C0(v17, 0, v19, 0);
						*(uint32_t*)&v18[2] = *(uint32_t*)(v3 + 36);
						*(uint32_t*)&v18[6] = v19;
						nox_xxx_netInformTextMsg2_4DA180(5, v18);
						if (v9 > 0) {
							break;
						}
					}
					v6 = *(uint32_t*)(v6 + 496);
					if (!v6) {
						return;
					}
				}
				v11 = nox_server_teamFirst_418B10();
				if (v11) {
					while (*((uint32_t*)v11 + 13) < v9) {
						v11 = nox_server_teamNext_418B60((int)v11);
						if (!v11) {
							return;
						}
					}
					nox_xxx_setGameFlags_40A4D0(8);
					nox_xxx_netFlagWinner_4D8C40_4D8C80((int)v11, 0);
				}
			}
		}
	} else {
		v20 = *(uint32_t*)(a1 + 748);
		if (!*(uint32_t*)(v2 + 492)) {
			v12 = nox_xxx_clientGetTeamColor_418AB0(*(unsigned char*)(v2 + 52));
			if (v12 && sub_418BC0((int)v12)) {
				v13 = *(uint32_t**)(v3 + 504);
				if (v13) {
					while (!(v13[2] & 0x10000000)) {
						v13 = (uint32_t*)v13[124];
						if (!v13) {
							goto LABEL_27;
						}
					}
					nox_xxx_invForceDropItem_4ED930(v3, v13);
				}
			LABEL_27:
				nox_xxx_servFinalizeDelObject_4DADE0(v2);
				v14 = sub_4ECBD0(v2);
				nox_xxx_inventoryPutImpl_4F3070(v3, v2, 1);
				*(uint32_t*)(*(uint32_t*)(a2 + 276) + 4) |= 1u;
				sub_4D82F0(255, (uint32_t*)v2);
				*(uint32_t*)&v18[2] = *(uint32_t*)(v3 + 36);
				*(uint32_t*)&v18[6] = v14;
				nox_xxx_netInformTextMsg2_4DA180(6, v18);
				nox_xxx_netUnmarkMinimapSpec_417470(v2, 1);
				*(uint32_t*)(v20 + 8) = 0;
				sub_4E82C0(v16, 1, v4, *(uint16_t*)(v3 + 36));
				sub_4EA7A0(v3);
			} else {
				nox_xxx_netPriMsgToPlayer_4DA2C0(v3, "objcoll.c:FlagNoTeam", 0);
			}
		}
	}
}

//----- (004EA7A0) --------------------------------------------------------
int sub_4EA7A0(int a1) {
	int i;      // esi
	int result; // eax
	int v3;     // eax

	for (i = 0; i < 32; ++i) {
		result = nox_xxx_testUnitBuffs_4FF350(a1, i);
		if (result) {
			result = nox_xxx_getEnchantSpell_424920(i);
			if (result) {
				v3 = nox_xxx_getEnchantSpell_424920(i);
				result = nox_xxx_spellHasFlags_424A50(v3, 0x80000);
				if (result) {
					result = nox_xxx_spellBuffOff_4FF5B0(a1, i);
				}
			}
		}
	}
	return result;
}

//----- (004EA800) --------------------------------------------------------
short sub_4EA800(int a1, int a2) {
	char* v2;     // eax
	int v3;       // esi
	int* v4;      // edi
	char* v5;     // eax
	int v6;       // ebx
	int v7;       // edi
	int v8;       // ebp
	int v9;       // eax
	char* v10;    // edi
	int v11;      // edi
	int i;        // eax
	int v13;      // ebp
	int j;        // edi
	int v15;      // ebp
	char v17[10]; // [esp+0h] [ebp-Ch]

	LOWORD(v2) = *getMemU16Ptr(0x5D4594, 1567992);
	if (!*getMemU32Ptr(0x5D4594, 1567992)) {
		v2 = (char*)nox_xxx_getNameId_4E3AA0("GameBall");
		*getMemU32Ptr(0x5D4594, 1567992) = v2;
	}
	v3 = a2;
	if (*(uint8_t*)(a2 + 8) & 4) {
		v2 = (char*)nox_xxx_unitIsGameball_4E7C30(a2);
		if (!v2) {
			return (short)v2;
		}
		v3 = *(uint32_t*)(a2 + 516);
		if (!v3) {
			return (short)v2;
		}
		LOWORD(v2) = *getMemU16Ptr(0x5D4594, 1567992);
		while (*(unsigned short*)(v3 + 4) != *getMemU32Ptr(0x5D4594, 1567992)) {
			v3 = *(uint32_t*)(v3 + 512);
			if (!v3) {
				return (short)v2;
			}
		}
	}
	if (v3) {
		v4 = *(int**)(v3 + 748);
		if (*v4 && *(uint8_t*)(*v4 + 16) & 0x20) {
			*v4 = 0;
		}
		v5 = nox_xxx_clientGetTeamColor_418AB0(*(unsigned char*)(a1 + 52));
		v2 = nox_server_teamNext_418B60((int)v5);
		v6 = (int)v2;
		if (!v2) {
			v2 = nox_server_teamFirst_418B10();
			v6 = (int)v2;
		}
		v7 = *v4;
		if (v7) {
			v2 = (char*)*(unsigned char*)(v7 + 52);
			if (v2 == (char*)*(unsigned char*)(v6 + 57)) {
				v8 = (unsigned short)nox_xxx_servGamedataGet_40A020(64);
				nox_xxx_changeScore_4D8E90(v7, 1);
				nox_xxx_netReportLesson_4D8EF0(v7);
				nox_xxx_netChangeTeamID_419090(v6, *(uint32_t*)(v6 + 52) + 1);
				if (dword_5d4594_2650652) {
					v9 = *(uint32_t*)(v7 + 748);
					if (v9) {
						sub_425CA0(*(uint32_t*)(v9 + 276), 0);
					}
				}
				nox_xxx_aud_501960(929, a1, 0, 0);
				*(uint32_t*)&v17[2] = *(uint32_t*)(v7 + 36);
				*(uint32_t*)&v17[6] = *(unsigned char*)(v6 + 57);
				nox_xxx_netInformTextMsg2_4DA180(9, v17);
				nox_xxx_netSendPointFx_522FF0(154, (float2*)(v3 + 56));
				if (v8 > 0) {
					v10 = nox_server_teamFirst_418B10();
					if (v10) {
						while (*((uint32_t*)v10 + 13) < v8) {
							v10 = nox_server_teamNext_418B60((int)v10);
							if (!v10) {
								goto LABEL_27;
							}
						}
						nox_xxx_setGameFlags_40A4D0(8);
						nox_xxx_netFlagballWinner_4D8C40((int)v10);
					}
				}
			LABEL_27:
				if (!dword_5d4594_1567988) {
					dword_5d4594_1567988 = nox_xxx_getNameId_4E3AA0("GameBallStart");
				}
				v11 = 0;
				for (i = nox_server_getFirstObject_4DA790(); i; i = nox_server_getNextObject_4DA7A0(i)) {
					if (*(unsigned short*)(i + 4) == dword_5d4594_1567988) {
						++v11;
					}
				}
				v13 = nox_common_randomInt_415FA0(0, v11 - 1);
				v2 = (char*)nox_server_getFirstObject_4DA790();
				for (j = (int)v2; v2; j = (int)v2) {
					LOWORD(v2) = *(uint16_t*)(j + 4);
					if ((unsigned short)v2 == dword_5d4594_1567988) {
						if (!v13) {
							if (j) {
								v15 = *(uint32_t*)(v3 + 748);
								nox_xxx_unitClearOwner_4EC300(v3);
								sub_4EB9B0(v3, 0);
								nox_xxx_netChangeTeamMb_419570(v3 + 48, *(uint32_t*)(v3 + 36));
								nox_xxx_unitHPsetOnMax_4EE6F0(v3);
								*(uint64_t*)(v15 + 8) = nox_platform_get_ticks();
								nox_xxx_unitMove_4E7010(v3, (float2*)(j + 56));
								sub_4E8290(0, 0);
								LOWORD(v2) = nox_xxx_netSendPointFx_522FF0(129, (float2*)(v3 + 56));
								*(uint32_t*)(v3 + 80) = 0;
								*(uint32_t*)(v3 + 84) = 0;
								*(uint32_t*)(v3 + 88) = 0;
								*(uint32_t*)(v3 + 100) = 0;
							}
							return (short)v2;
						}
						--v13;
					}
					v2 = (char*)nox_server_getNextObject_4DA7A0(j);
				}
			}
		}
	}
	return (short)v2;
}

//----- (004EAAA0) --------------------------------------------------------
uint32_t* sub_4EAAA0(int a1) {
	uint32_t* result; // eax

	result = (uint32_t*)a1;
	if (nox_frame_xxx_2598000 > (unsigned int)(*(uint32_t*)(a1 + 136) + 3)) {
		*(uint32_t*)(a1 + 136) = nox_frame_xxx_2598000;
		result = nox_xxx_aud_501960(281, a1, 0, 0);
	}
	return result;
}

//----- (004EAAD0) --------------------------------------------------------
uint32_t* sub_4EAAD0(int a1, int a2) {
	uint32_t* result; // eax

	result = (uint32_t*)a2;
	if (a2 && *(uint8_t*)(a2 + 8) & 4) {
		result = (uint32_t*)a1;
		if (nox_frame_xxx_2598000 > (unsigned int)(*(uint32_t*)(a1 + 136) + 30)) {
			*(uint32_t*)(a1 + 136) = nox_frame_xxx_2598000;
			result = nox_xxx_aud_501960(**(uint32_t**)(a1 + 700), a1, 0, 0);
		}
	}
	return result;
}

//----- (004EAB20) --------------------------------------------------------
int nox_xxx_collidePentagram_4EAB20(int a1) {
	int result; // eax

	result = a1;
	*(uint32_t*)(*(uint32_t*)(a1 + 748) + 4) = 1;
	return result;
}

//----- (004EAB40) --------------------------------------------------------
void nox_xxx_collideSign_4EAB40(int a1, int a2) {

	if (a2) {
		if (*(uint8_t*)(a2 + 8) & 4) {
			(*(int (**)(int, int))(a1 + 732))(a2, a1);
		}
	}
}

//----- (004EAB60) --------------------------------------------------------
void nox_xxx_collideTrapDoor_4EAB60(int a1, int a2) {
	int v2;    // ebx
	int v3;    // eax
	int v4;    // eax
	double v5; // st7

	v2 = *(uint32_t*)(a1 + 700);
	if (a2) {
		v3 = *(uint32_t*)(a2 + 8);
		if ((v3 & 0x80u) == 0) {
			if (*(uint32_t*)(a1 + 16) & 0x1000000) {
				v4 = *(uint32_t*)(a2 + 172);
				if (v4 == 3) {
					if (*(float*)(a1 + 184) < (double)*(float*)(a2 + 184) ||
						*(float*)(a1 + 188) < (double)*(float*)(a2 + 188)) {
						return;
					}
				LABEL_11:
					if (nox_xxx_map_57B850((float2*)(a1 + 56), (float*)(a1 + 172), (float2*)(a2 + 56))) {
						*(uint32_t*)(a2 + 16) |= 0x60000u;
						*(float*)(a2 + 164) = (double)*(int*)(v2 + 8);
						*(float*)(a2 + 168) = (double)*(int*)(v2 + 12);
						*(uint32_t*)(a2 + 156) = *(uint32_t*)(a1 + 56);
						*(uint32_t*)(a2 + 160) = *(uint32_t*)(a1 + 60);
					}
					return;
				}
				if (v4 != 2) {
					goto LABEL_11;
				}
				v5 = *(float*)(a2 + 176) + *(float*)(a2 + 176);
				if (v5 <= *(float*)(a1 + 184) && v5 <= *(float*)(a1 + 188)) {
					goto LABEL_11;
				}
			} else if (!*(uint32_t*)(v2 + 24) && (!(v3 & 4) || !nox_common_playerIsAbilityActive_4FC250(a2, 4))) {
				if (*(uint16_t*)(v2 + 20)) {
					*(uint32_t*)(v2 + 16) = nox_frame_xxx_2598000 + *(unsigned short*)(v2 + 20);
				}
				nox_xxx_scriptCallByEventBlock_502490((int*)v2, a2, a1, 20);
				*(uint32_t*)(v2 + 24) = 1;
			}
		}
	}
}

//----- (004EACA0) --------------------------------------------------------
uint32_t* sub_4EACA0(int a1, int a2) {
	uint32_t* result; // eax
	int* v3;          // ebx

	result = (uint32_t*)a1;
	v3 = *(int**)(a1 + 700);
	if (a2) {
		if ((signed char)*(uint8_t*)(a2 + 8) >= 0) {
			nox_xxx_netSendPointFx_522FF0(138, (float2*)(a2 + 56));
			nox_xxx_aud_501960(147, a2, 0, 0);
			*(float*)(a2 + 164) = (double)*v3;
			*(float*)(a2 + 168) = (double)v3[1];
			nox_xxx_teleportToMB_4E7190((uint8_t*)a2, (float*)(a2 + 164));
			nox_xxx_netSendPointFx_522FF0(137, (float2*)(a2 + 56));
			result = nox_xxx_aud_501960(147, a2, 0, 0);
		}
	}
	return result;
}

//----- (004EAD20) --------------------------------------------------------
int nox_xxx_collideSpellPedestal_4EAD20(int a1, int a2) {
	int result; // eax

	result = a2;
	if (a2) {
		result = nox_xxx_spellGrantToPlayer_4FB550_magic_plyrspel(a2, **(uint32_t**)(a1 + 700), 1, 0, 0);
	}
	return result;
}

//----- (004EAD50) --------------------------------------------------------
void nox_xxx_unused_4EAD50(int a1, int a2) {
	uint32_t* v2; // edi
	char* v3;     // eax

	if (a2) {
		if (*(uint8_t*)(a2 + 8) & 4) {
			v2 = *(uint32_t**)(a1 + 748);
			if (*(uint16_t*)(*(uint32_t*)(a2 + 748) + 4) < *(uint16_t*)(*(uint32_t*)(a2 + 748) + 8) && *v2 > 0) {
				if (!nox_xxx_servObjectHasTeam_419130(a1 + 48) ||
					nox_xxx_servObjectHasTeam_419130(a2 + 48) &&
						(v3 = nox_xxx_clientGetTeamColor_418AB0(*(unsigned char*)(a2 + 52))) != 0 &&
						nox_xxx_teamCompare2_419180(a1 + 48, v3[57])) {
					nox_xxx_playerManaAdd_4EEB80(a2, 1);
					--*v2;
				}
			}
		}
	}
}

//----- (004EADF0) --------------------------------------------------------
void nox_xxx_collideFist_4EADF0(int a1, int a2) {
	int v2; // eax
	int v3; // [esp-8h] [ebp-Ch]

	if (*(float*)(a1 + 104) <= 0.0) {
		if (a2) {
			v3 = **(uint32_t**)(a1 + 748);
			v2 = nox_xxx_findParentChainPlayer_4EC580(a1);
			(*(void (**)(int, int, int, int, int))(a2 + 716))(a2, v2, a1, v3, 2);
		}
	}
}

//----- (004EAE30) --------------------------------------------------------
void nox_xxx_collideTeleportWake_4EAE30(int a1, int a2) {
	float* v2; // ebx
	int v3;    // eax

	v2 = *(float**)(a1 + 700);
	if (a2) {
		if (!nox_xxx_testUnitBuffs_4FF350(a2, 14)) {
			if (!nox_common_gameFlags_check_40A5C0(4096) || (v3 = *(uint32_t*)(a1 + 508)) == 0 ||
				*(uint8_t*)(v3 + 8) & 4) {
				if (*(uint32_t*)(a2 + 8) & 0x3001016) {
					if (!nox_xxx_testUnitBuffs_4FF350(a2, 0)) {
						nox_xxx_netSendPointFx_522FF0(138, (float2*)(a2 + 56));
					}
					nox_xxx_aud_501960(147, a2, 0, 0);
					nox_xxx_teleportToMB_4E7190((uint8_t*)a2, v2);
					if (!nox_xxx_testUnitBuffs_4FF350(a2, 0)) {
						nox_xxx_netSendPointFx_522FF0(137, (float2*)(a2 + 56));
					}
					nox_xxx_aud_501960(147, a2, 0, 0);
				}
			}
		}
	}
}

//----- (004EAF00) --------------------------------------------------------
void nox_xxx_collideChakram_4EAF00(int a1, int a2, float* a3) {
	int v3;        // esi
	int v4;        // ebx
	int v5;        // eax
	int* v6;       // ebp
	int v7;        // edi
	char v8;       // al
	int* v9;       // eax
	int v10;       // eax
	int v11;       // ebp
	uint32_t* v12; // eax
	int v13;       // ecx
	int v14;       // eax
	int v15;       // edx
	double v16;    // st7
	char v17;      // al
	int v18;       // ecx
	int* v19;      // edi
	int v20;       // [esp-4h] [ebp-3Ch]
	uint32_t* v21; // [esp+10h] [ebp-28h]
	int v22[9];    // [esp+14h] [ebp-24h]
	int v23;       // [esp+3Ch] [ebp+4h]
	int v24;       // [esp+40h] [ebp+8h]

	v3 = a1;
	v20 = a1;
	v4 = *(uint32_t*)(a1 + 748);
	v23 = 1;
	v5 = nox_xxx_inventoryGetFirst_4E7980(v20);
	v6 = (int*)v5;
	v21 = (uint32_t*)v5;
	if (!v5 || *(uint8_t*)(v5 + 16) & 0x20) {
		nox_xxx_delayedDeleteObject_4E5CC0(v3);
	} else {
		v7 = a2;
		if (!a2 || *(uint8_t*)(a2 + 24) & 0x30) {
			nox_xxx_netSendPointFx_522FF0(150, (float2*)(v3 + 56));
		}
		if (!a2) {
			if (!a3) {
				return;
			}
			if (*(uint8_t*)(v4 + 4)) {
				nox_xxx_collideReflect_57B810(a3, v3 + 80);
			} else {
				sub_4EB3E0(v3);
			}
			v8 = *(uint8_t*)(v4 + 4);
			if (v8) {
				*(uint8_t*)(v4 + 4) = v8 - 1;
			} else if (!*(uint8_t*)(v4 + 24)) {
				*(uint8_t*)(v4 + 24) = 2;
				v23 = 0;
			}
			v9 = (int*)sub_537760();
			if (v9) {
				nox_xxx_damageToMap_534BC0(*v9, v9[1], 1, 0, v3);
			}
			if (*(uint8_t*)(v4 + 24) == 1) {
				nox_xxx_drop_4ED790(v3, v6, (float2*)(v3 + 56));
				nox_xxx_delayedDeleteObject_4E5CC0(v3);
				return;
			}
			if (!*(uint8_t*)(v4 + 4) && v23) {
				*(uint8_t*)(v4 + 24) = 0;
				*(uint32_t*)(v4 + 8) = *(uint32_t*)(v3 + 508);
				return;
			}
		LABEL_50:
			sub_4EB250(v3);
			return;
		}
		if (a2 == *(uint32_t*)(v3 + 508)) {
			sub_4ED0C0(v3, v6);
			nox_xxx_inventoryPutImpl_4F3070(*(uint32_t*)(v3 + 508), (int)v6, 1);
			v10 = *(uint32_t*)(v3 + 508);
			if (v10 && *(uint8_t*)(v10 + 8) & 4 && !*(uint32_t*)(*(uint32_t*)(v10 + 748) + 104)) {
				nox_xxx_playerEquipWeapon_53A420((uint32_t*)v10, (int)v6, 1, 1);
			}
			nox_xxx_aud_501960(892, v3, 0, 0);
			nox_xxx_delayedDeleteObject_4E5CC0(v3);
		} else {
			if (nox_xxx_unitsHaveSameTeam_4EC520(v3, a2)) {
				return;
			}
			v11 = *(uint32_t*)(v3 + 508);
			v12 = nox_xxx_getProjectileClassById_413250(*(unsigned short*)(v3 + 4));
			v24 = (int)v12;
			if (!v11 || *(uint32_t*)(v11 + 16) & 0x8020) {
				nox_xxx_drop_4ED790(v3, v21, (float2*)(v3 + 56));
				nox_xxx_delayedDeleteObject_4E5CC0(v3);
			} else {
				v13 = *(uint32_t*)(v7 + 16);
				if ((v13 & 0x8000) == 0 && v12) {
					v14 = nox_xxx_unitGetStrength_4F9FD0(v11);
					v15 = *(uint32_t*)(v3 + 60);
					v22[4] = *(uint32_t*)(v3 + 56);
					v22[7] = v3;
					v22[5] = v15;
					*(float*)v22 = nox_xxx_calcBoltDamage_4EF1E0(v14, v24);
					v16 = *(float*)(v3 + 176) + 30.0;
					LOBYTE(v22[1]) = 0;
					v22[3] = v11;
					*(float*)&v22[2] = v16;
					v22[6] = 0;
					nox_xxx_itemApplyAttackEffect_538840(v3, v11, (int)v22);
					nox_xxx_playerPreAttackEffects_538290(v7, v11, v3, (int)v22);
					(*(void (**)(int, int, int, uint32_t, uint32_t))(v7 + 716))(
						v7, v11, v3, (long long)(*(float*)v22 + *(double*)&qword_581450_9544), 0);
					if (!(*(uint32_t*)(v7 + 16) & 0x8020)) {
						*(uint32_t*)(v4 + 12) = v7;
					}
					if (*(uint8_t*)(v4 + 4)) {
						nox_xxx_projectileReflect_4E0A70(v3, v7);
					} else {
						sub_4EB3E0(v3);
					}
					v17 = *(uint8_t*)(v4 + 4);
					if (v17 || *(uint8_t*)(v4 + 24)) {
						v18 = 1;
					} else {
						*(uint8_t*)(v4 + 24) = 2;
						v18 = 0;
					}
					if (v17) {
						*(uint8_t*)(v4 + 4) = v17 - 1;
					}
					if (*(uint8_t*)(v4 + 24) == 1) {
						v19 = (int*)nox_xxx_inventoryGetFirst_4E7980(v3);
						nox_xxx_aud_501960(893, v3, 0, 0);
						sub_4ED0C0(v3, v19);
						nox_xxx_createAt_4DAA50((int)v19, 0, *(float*)(v3 + 56), *(float*)(v3 + 60));
						nox_xxx_delayedDeleteObject_4E5CC0(v3);
						return;
					}
					if (!*(uint8_t*)(v4 + 4) && v18) {
						*(uint32_t*)(v4 + 8) = v11;
						*(uint8_t*)(v4 + 24) = 0;
						return;
					}
					goto LABEL_50;
				}
			}
		}
	}
}

//----- (004EB250) --------------------------------------------------------
int sub_4EB250(int a1) {
	float* v1;  // esi
	int v2;     // ebx
	int result; // eax
	double v4;  // st7
	double v5;  // st6
	float v6;   // [esp+Ch] [ebp-14h]
	float4 a1a; // [esp+10h] [ebp-10h]
	float v8;   // [esp+24h] [ebp+4h]

	v1 = (float*)a1;
	v2 = *(uint32_t*)(a1 + 748);
	dword_5d4594_1567928 = 0;
	*getMemU32Ptr(0x5D4594, 1567932) = *(uint32_t*)(v2 + 12);
	*getMemU32Ptr(0x5D4594, 1567840) = *(uint32_t*)(a1 + 508);
	*getMemU32Ptr(0x5D4594, 1567924) = a1;
	*getMemU32Ptr(0x5D4594, 1567836) = 1259902592;
	a1a.field_0 = *(float*)(a1 + 56) - 400.0;
	a1a.field_4 = *(float*)(a1 + 60) - 400.0;
	a1a.field_8 = *(float*)(a1 + 56) + 400.0;
	a1a.field_C = *(float*)(a1 + 60) + 400.0;
	nox_xxx_getUnitsInRect_517C10(&a1a, sub_4EB340, a1 + 56);
	result = dword_5d4594_1567928;
	if (dword_5d4594_1567928) {
		*(uint8_t*)(v2 + 24) = 2;
		result = dword_5d4594_1567928;
		v4 = *(float*)(dword_5d4594_1567928 + 56) - *(float*)(a1 + 56);
		v5 = *(float*)(dword_5d4594_1567928 + 60) - *(float*)(a1 + 60);
		v8 = v5;
		v6 = sqrt(v5 * v8 + v4 * v4) + *(double*)&qword_581450_10176;
		v1[20] = v4 * v1[136] / v6;
		v1[21] = v8 * v1[136] / v6;
	}
	return result;
}

//----- (004EB340) --------------------------------------------------------
void sub_4EB340(float* a1, int a2) {
	double v2; // st7
	double v3; // st6
	double v4; // st5

	if ((uint32_t)a1[2] & 0x20006) {
		if (!((uint32_t)a1[4] & 0x8020) && !nox_xxx_testUnitBuffs_4FF350((int)a1, 0) &&
			a1 != *(float**)getMemAt(0x5D4594, 1567840) && a1 != *(float**)getMemAt(0x5D4594, 1567932)) {
			if (nox_xxx_mapCheck_537110((int)a1, *getMemIntPtr(0x5D4594, 1567924))) {
				v2 = *(float*)a2 - a1[14];
				v3 = *(float*)(a2 + 4) - a1[15];
				v4 = v3 * v3 + v2 * v2;
				if (v4 <= 160000.0 && v4 < *getMemFloatPtr(0x5D4594, 1567836)) {
					*getMemFloatPtr(0x5D4594, 1567836) = v4;
					dword_5d4594_1567928 = a1;
				}
			}
		}
	}
}

//----- (004EB3E0) --------------------------------------------------------
void sub_4EB3E0(int a1) {
	int v1;     // esi
	float* v2;  // edi
	int v3;     // ebx
	int v4;     // eax
	int v5;     // ecx
	double v6;  // st7
	int v7;     // eax
	float2* v8; // [esp-4h] [ebp-10h]
	float v9;   // [esp+10h] [ebp+4h]

	v1 = a1;
	v2 = (float*)(a1 + 80);
	v8 = (float2*)(a1 + 80);
	v9 = sqrt(*(float*)(a1 + 80) * *(float*)(a1 + 80) + *(float*)(a1 + 84) * *(float*)(a1 + 84));
	v3 = nox_xxx_math_509ED0(v8);
	v4 = nox_common_randomInt_415FA0(-64, 64) + v3 + 128;
	if (v4 < 0) {
		v4 += (unsigned int)(255 - v4) >> 8 << 8;
	}
	if (v4 >= 256) {
		v4 += -256 * ((unsigned int)v4 >> 8);
	}
	v5 = *(uint32_t*)(v1 + 76);
	*v2 = v9 * *getMemFloatPtr(0x587000, 194136 + 8 * v4);
	v6 = v9 * *getMemFloatPtr(0x587000, 194140 + 8 * v4);
	v7 = *(uint32_t*)(v1 + 72);
	*(uint32_t*)(v1 + 68) = v5;
	*(uint32_t*)(v1 + 64) = v7;
	*(uint32_t*)(v1 + 56) = v7;
	*(float*)(v1 + 84) = v6;
	*(uint32_t*)(v1 + 60) = v5;
	nox_xxx_moveUpdateSpecial_517970(v1);
}

//----- (004EB490) --------------------------------------------------------
void nox_xxx_collideArrow_4EB490(int a1, int a2) {
	int v2;        // esi
	uint32_t* v3;  // ebp
	int v4;        // eax
	int v5;        // ebx
	int v6;        // eax
	int v7;        // eax
	int v8;        // eax
	int v9;        // ecx
	double v10;    // st7
	int v11;       // edx
	int v12;       // eax
	int v13;       // eax
	char v14;      // al
	uint16_t* v15; // edi
	int* v16;      // edi
	double v17;    // st7
	int v18;       // [esp-8h] [ebp-3Ch]
	int v19;       // [esp-4h] [ebp-38h]
	int v20;       // [esp-4h] [ebp-38h]
	int v21[9];    // [esp+10h] [ebp-24h]
	int v22;       // [esp+38h] [ebp+4h]

	v2 = a1;
	v19 = *(unsigned short*)(a1 + 4);
	v22 = *(uint32_t*)(a1 + 700);
	v3 = nox_xxx_getProjectileClassById_413250(v19);
	if (!v3) {
		return;
	}
	v4 = *(uint32_t*)(v2 + 508);
	if (v4 == a2) {
		if (a2) {
			return;
		}
	}
	if (v4) {
		v5 = nox_xxx_unitGetStrength_4F9FD0(*(uint32_t*)(v2 + 508));
	} else {
		v5 = 30;
	}
	if (nox_common_gameFlags_check_40A5C0(4096)) {
		v6 = nox_xxx_findParentChainPlayer_4EC580(v2);
		if (v6) {
			if (!a2) {
				goto LABEL_24;
			}
			if (*(uint8_t*)(v6 + 8) & 4 && *(uint8_t*)(a2 + 8) & 4 && !nox_xxx_unitIsEnemyTo_5330C0(v6, a2)) {
				return;
			}
		}
	}
	if (!a2) {
	LABEL_24:
		v16 = (int*)sub_537760();
		if (v16) {
			v17 = nox_xxx_calcBoltDamage_4EF1E0(v5, (int)v3);
			nox_xxx_damageToMap_534BC0(*v16, v16[1], (long long)v17, 11, v2);
			nox_xxx_delayedDeleteObject_4E5CC0(v2);
			return;
		}
		goto LABEL_27;
	}
	nox_xxx_unitGetStrength_4F9FD0(*(uint32_t*)(v2 + 508));
	if (!*getMemU32Ptr(0x5D4594, 1568000)) {
		*getMemU32Ptr(0x5D4594, 1568000) = nox_xxx_getNameId_4E3AA0("ArcherBolt");
	}
	v7 = *(uint32_t*)(a2 + 16);
	if ((v7 & 0x8000) == 0) {
		v8 = *(uint32_t*)(v2 + 56);
		v9 = *(uint32_t*)(v2 + 60);
		v21[7] = v2;
		v21[4] = v8;
		v21[5] = v9;
		v10 = nox_xxx_calcBoltDamage_4EF1E0(v5, (int)v3);
		v11 = *(uint32_t*)(v2 + 176);
		*(float*)v21 = v10;
		v12 = *(uint32_t*)(v22 + 4);
		LOBYTE(v21[1]) = 11;
		v21[3] = v12;
		v21[2] = v11;
		v21[6] = 0;
		nox_xxx_itemApplyAttackEffect_538840(v2, v12, (int)v21);
		if (*(uint32_t*)(v2 + 508) != a2) {
			nox_xxx_playerPreAttackEffects_538290(a2, *(uint32_t*)(v22 + 4), v2, (int)v21);
		}
		v20 = LOBYTE(v21[1]);
		v18 = (long long)(*(float*)v21 + *(double*)&qword_581450_9544);
		v13 = nox_xxx_findParentChainPlayer_4EC580(v2);
		v14 = (*(int (**)(int, int, int, int, int))(a2 + 716))(a2, v13, v2, v18, v20);
		if (*(unsigned short*)(v2 + 4) == *getMemU32Ptr(0x5D4594, 1568000)) {
			v15 = *(uint16_t**)(a2 + 556);
			if (v15 && !*v15) {
				if (!v15[2]) {
					nox_xxx_delayedDeleteObject_4E5CC0(v2);
				}
				return;
			}
		} else if (!v14) {
			return;
		}
	LABEL_27:
		nox_xxx_delayedDeleteObject_4E5CC0(v2);
	}
}

//----- (004EB6A0) --------------------------------------------------------
void nox_xxx_collideHarpoon_4EB6A0(int a1, int a2) {
	int v2;       // eax
	uint32_t* v3; // ebp
	uint32_t* v4; // ebx
	int v5;       // eax
	int v6;       // eax
	float v7;     // [esp+0h] [ebp-24h]
	float v8;     // [esp+4h] [ebp-20h]
	int v9;       // [esp+4h] [ebp-20h]
	int v10;      // [esp+8h] [ebp-1Ch]
	int v11;      // [esp+Ch] [ebp-18h]
	int v12;      // [esp+Ch] [ebp-18h]
	float v13;    // [esp+10h] [ebp-14h]

	v2 = *getMemU32Ptr(0x5D4594, 1568004);
	v3 = *(uint32_t**)(a1 + 508);
	v4 = (uint32_t*)v3[187];
	if (!*getMemU32Ptr(0x5D4594, 1568004)) {
		v13 = nox_xxx_gamedataGetFloat_419D40("HarpoonDamage");
		v2 = nox_float2int(v13);
		*getMemU32Ptr(0x5D4594, 1568004) = v2;
	}
	if (!a2) {
		v10 = v2;
		v8 = *(float*)(a1 + 68) * 0.043478262;
		v9 = nox_float2int(v8);
		v7 = *(float*)(a1 + 64) * 0.043478262;
		v6 = nox_float2int(v7);
		nox_xxx_damageToMap_534BC0(v6, v9, v10, 11, a1);
	LABEL_13:
		v4[33] = 0;
		sub_4FC300(v3, 3);
		nox_xxx_delayedDeleteObject_4E5CC0(a1);
		v4[34] = 0;
		return;
	}
	if (!(*(uint32_t*)(a2 + 16) & 0x8020) && (uint32_t*)a2 != v3) {
		v11 = v2;
		v5 = nox_xxx_findParentChainPlayer_4EC580(a1);
		if ((*(int (**)(int, int, int, int, int))(a2 + 716))(a2, v5, a1, v11, 11) &&
			(nox_xxx_unitIsEnemyTo_5330C0((int)v3, a2) ||
			 nox_xxx_CheckGameplayFlags_417DA0(1) && *(uint8_t*)(a2 + 8) & 6)) {
			v4[33] = a2;
			v4[36] = *(uint32_t*)(a2 + 56);
			v4[37] = *(uint32_t*)(a2 + 60);
			v4[38] = nox_frame_xxx_2598000;
			v12 = *(uint32_t*)(a1 + 508);
			*(uint32_t*)(a1 + 16) |= 0x40u;
			sub_4E7540(v12, a2);
			nox_xxx_aud_501960(999, (int)v3, 0, 0);
			return;
		}
		nox_xxx_soundDefaultDamageSound_532E20(a2, a1);
		goto LABEL_13;
	}
}

//----- (004EB800) --------------------------------------------------------
void nox_xxx_collideMonsterArrow_4EB800(int a1, int a2) {
	int* v2; // esi
	int v3;  // edi
	int v4;  // eax
	int v5;  // eax
	int* v6; // eax

	v2 = *(int**)(a1 + 700);
	if (nox_common_gameFlags_check_40A5C0(2048)) {
		v3 = *v2;
	} else {
		v3 = v2[1];
	}
	if (a2) {
		v4 = *(uint32_t*)(a2 + 16);
		if ((v4 & 0x8000) == 0) {
			v5 = nox_xxx_findParentChainPlayer_4EC580(a1);
			(*(void (**)(int, int, int, int, int))(a2 + 716))(a2, v5, a1, v3, 3);
			nox_xxx_delayedDeleteObject_4E5CC0(a1);
		}
	} else {
		v6 = (int*)sub_537760();
		if (v6) {
			nox_xxx_damageToMap_534BC0(*v6, v6[1], v3, 11, a1);
		}
		nox_xxx_delayedDeleteObject_4E5CC0(a1);
	}
}

//----- (004EB890) --------------------------------------------------------
void nox_xxx_collideBearTrap_4EB890(int* a1, int a2) {
	uint32_t* v2; // eax

	if (a2 && sub_4E9A30((int)a1, a2)) {
		v2 = nox_xxx_newObjectByTypeID_4E3810("ClosedBearTrap");
		if (v2) {
			nox_xxx_createAt_4DAA50((int)v2, a1[127], *((float*)a1 + 14), *((float*)a1 + 15));
			nox_xxx_delayedDeleteObject_4E5CC0((int)a1);
			nox_xxx_buffApplyTo_4FF380(a2, 5, 90, 5);
			nox_xxx_buffApplyTo_4FF380(a2, 14, 90, 5);
			nox_xxx_aud_501960(846, (int)a1, 0, 0);
		}
	}
}

//----- (004EB910) --------------------------------------------------------
void nox_xxx_collidePoisonGasTrap_4EB910(int* a1, int a2) {
	uint32_t* v2; // edi
	uint32_t* v3; // edi
	float v4;     // [esp+0h] [ebp-14h]

	if (a2 && sub_4E9A30((int)a1, a2)) {
		v2 = nox_xxx_newObjectByTypeID_4E3810("ToxicCloud");
		if (v2) {
			nox_xxx_createAt_4DAA50((int)v2, a1[127], *((float*)a1 + 14), *((float*)a1 + 15));
			v3 = (uint32_t*)v2[187];
			v4 = nox_xxx_gamedataGetFloat_419D40("ToxicCloudLifetime") * (double)(int)nox_gameFPS;
			*v3 = nox_float2int(v4);
			nox_xxx_aud_501960(847, (int)a1, 0, 0);
			nox_xxx_delayedDeleteObject_4E5CC0((int)a1);
		}
	}
}

//----- (004EB9B0) --------------------------------------------------------
int sub_4EB9B0(int a1, int a2) {
	uint32_t* v2; // esi
	int result;   // eax

	v2 = *(uint32_t**)(a1 + 748);
	result = a2;
	if (a2 && (result = nox_xxx_findParentChainPlayer_4EC580(a2)) != 0 && *(uint8_t*)(result + 8) & 4) {
		*v2 = result;
		v2[1] = *(unsigned char*)(result + 52);
		v2[4] = nox_frame_xxx_2598000;
	} else {
		*v2 = 0;
		v2[1] = 0;
	}
	return result;
}

//----- (004EBA00) --------------------------------------------------------
uint32_t* nox_xxx_collideBall_4EBA00(int a1, int a2) {
	char* v2;         // ebp
	uint32_t* v3;     // ebx
	uint32_t* result; // eax

	v2 = 0;
	v3 = *(uint32_t**)(a1 + 748);
	if (a2) {
		v2 = nox_xxx_clientGetTeamColor_418AB0(*(unsigned char*)(a2 + 52));
		if (*v3 == a2 && v2 && sub_418BC0((int)v2) > 1) {
			if ((unsigned int)(nox_frame_xxx_2598000 - *getMemU32Ptr(0x5D4594, 1568008)) > 0x2D) {
				nox_xxx_netPriMsgToPlayer_4DA2C0(a2, "objcoll.c:CantPickupBall", 0);
				*getMemU32Ptr(0x5D4594, 1568008) = nox_frame_xxx_2598000;
			}
			return nox_xxx_aud_501960(928, a1, 0, 0);
		}
	}
	if (*(uint32_t*)(a1 + 508) || !a2 || !(*(uint8_t*)(a2 + 8) & 4)) {
		return nox_xxx_aud_501960(928, a1, 0, 0);
	}
	result = *(uint32_t**)(a2 + 516);
	if (!result) {
	LABEL_17:
		nox_xxx_unitSetOwner_4EC290(a2, a1);
		if (nox_xxx_servObjectHasTeam_419130(a1 + 48)) {
			if (!v2) {
			LABEL_25:
				sub_4EB9B0(a1, a2);
				nox_xxx_aud_501960(927, a1, 0, 0);
				*(uint32_t*)(a1 + 16) |= 0x40u;
				return (uint32_t*)sub_4EA7A0(a2);
			}
			sub_4196D0(a1 + 48, (int)v2, *(uint32_t*)(a1 + 36), 0);
		} else {
			nox_xxx_createAtImpl_4191D0(*(uint8_t*)(a2 + 52), a1 + 48, 1, *(uint32_t*)(a1 + 36), 0);
		}
		if (v2) {
			if (v2[56] == 2) {
				sub_4E8290(4, *(uint16_t*)(a2 + 36));
			} else {
				sub_4E8290(2, *(uint16_t*)(a2 + 36));
			}
		}
		goto LABEL_25;
	}
	while (*((uint16_t*)result + 2) != *(uint16_t*)(a1 + 4)) {
		result = (uint32_t*)result[128];
		if (!result) {
			goto LABEL_17;
		}
	}
	return result;
}

//----- (004EBB50) --------------------------------------------------------
int sub_4EBB50(int a1, int a2) {
	int result; // eax

	result = a2;
	if (a2 && !(*(uint32_t*)(a2 + 16) & 0x8020)) {
		if (*(uint8_t*)(a2 + 8) & 4) {
			result = sub_4F3400(a2, a1, 1);
		}
	}
	return result;
}

//----- (004EBB80) --------------------------------------------------------
short nox_xxx_collideHomeBase_4EBB80(int a1, int a2) {
	int v2;   // esi
	int v3;   // eax
	int* v4;  // edi
	char* v5; // esi
	char* v6; // ebp
	int v7;   // edi
	int v8;   // edi
	int v9;   // esi
	int i;    // eax
	int v11;  // edi
	int j;    // esi
	int v14;  // [esp+10h] [ebp-4h]

	v2 = nox_xxx_getNameId_4E3AA0("GameBall");
	v3 = nox_xxx_getNameId_4E3AA0("GameBallStart");
	v14 = v3;
	if (a2) {
		LOWORD(v3) = *(uint16_t*)(a2 + 4);
		if ((unsigned short)v3 == v2) {
			v4 = *(int**)(a2 + 748);
			v5 = 0;
			v6 = 0;
			if (nox_xxx_servObjectHasTeam_419130(a1 + 48)) {
				v5 = nox_xxx_clientGetTeamColor_418AB0(*(unsigned char*)(a1 + 52));
			}
			if (*v4 && nox_xxx_servObjectHasTeam_419130(*v4 + 48)) {
				v6 = nox_xxx_clientGetTeamColor_418AB0(*(unsigned char*)(*v4 + 52));
			}
			if (v5 == v6) {
				nox_xxx_changeScore_4D8E90(*v4, 1);
				nox_xxx_netReportLesson_4D8EF0(*v4);
			}
			if (v5) {
				nox_xxx_netChangeTeamID_419090((int)v5, *((uint32_t*)v5 + 13) + 1);
				if (dword_5d4594_2650652) {
					v7 = *v4;
					if (v7) {
						v8 = *(uint32_t*)(v7 + 748);
						if (v8) {
							sub_425CA0(*(uint32_t*)(v8 + 276), 0);
						}
					}
				}
				nox_xxx_aud_501960(929, a1, 0, 0);
				nox_xxx_netSendPointFx_522FF0(154, (float2*)(a2 + 56));
			}
			v9 = 0;
			for (i = nox_server_getFirstObject_4DA790(); i; i = nox_server_getNextObject_4DA7A0(i)) {
				if (*(unsigned short*)(i + 4) == v14) {
					++v9;
				}
			}
			v11 = nox_common_randomInt_415FA0(0, v9 - 1);
			v3 = nox_server_getFirstObject_4DA790();
			for (j = v3; v3; j = v3) {
				LOWORD(v3) = v14;
				if (*(unsigned short*)(j + 4) == v14) {
					if (!v11) {
						if (j) {
							nox_xxx_unitClearOwner_4EC300(a2);
							nox_xxx_unitMove_4E7010(a2, (float2*)(j + 56));
							LOWORD(v3) = nox_xxx_netSendPointFx_522FF0(129, (float2*)(a2 + 56));
							*(uint32_t*)(a2 + 80) = 0;
							*(uint32_t*)(a2 + 84) = 0;
							*(uint32_t*)(a2 + 88) = 0;
							*(uint32_t*)(a2 + 100) = 0;
						}
						return v3;
					}
					--v11;
				}
				v3 = nox_server_getNextObject_4DA7A0(j);
			}
		}
	}
	return v3;
}

//----- (004EBD40) --------------------------------------------------------
void nox_xxx_collideUndeadKiller_4EBD40(int a1, int a2, int a3) {
	int v3;            // ebx
	int* v4;           // esi
	unsigned short v5; // ax
	int v6;            // esi
	int v7;            // edi
	int v8;            // esi
	int v9;            // eax
	int v10;           // eax
	int v11;           // [esp+14h] [ebp+4h]

	if (a2) {
		if (*(uint8_t*)(a2 + 8) & 2 && *(uint8_t*)(a2 + 12) & 0x40) {
			v3 = a1;
			v4 = *(int**)(a1 + 700);
			v5 = nox_xxx_unitGetHP_4EE780(a2);
			v6 = *v4;
			v11 = v6;
			v7 = v5;
			v8 = *(uint32_t*)(v6 + 72);
			if (v8 <= v5) {
				if (v8) {
					v10 = nox_xxx_findParentChainPlayer_4EC580(v3);
					(*(void (**)(int, int, int, int, int))(a2 + 716))(a2, v10, v3, v8, 6);
					nox_xxx_delayedDeleteObject_4E5CC0(v3);
					*(uint32_t*)(v11 + 72) -= v8;
				} else {
					nox_xxx_delayedDeleteObject_4E5CC0(v3);
				}
			} else {
				v9 = nox_xxx_findParentChainPlayer_4EC580(v3);
				(*(void (**)(int, int, int, int, int))(a2 + 716))(a2, v9, v3, v7, 6);
				*(uint32_t*)(v11 + 72) = v8 - v7;
			}
		}
	} else if (!a3) {
		nox_xxx_delayedDeleteObject_4E5CC0(a1);
	}
}

//----- (004EBE10) --------------------------------------------------------
void nox_xxx_collideMonsterGen_4EBE10(int a1, int a2) {
	if (a2) {
		if (*(uint8_t*)(a2 + 8) & 4) {
			nox_xxx_scriptCallByEventBlock_502490((int*)(*(uint32_t*)(a1 + 748) + 72), a2, a1, 19);
		}
	}
}

//----- (004EBE40) --------------------------------------------------------
void sub_4EBE40(int a1, int a2) {
	float2* v2;   // edi
	int v3;       // esi
	int v4;       // eax
	int v5;       // ecx
	int v6;       // esi
	uint32_t* v7; // [esp+Ch] [ebp+4h]

	v2 = (float2*)a1;
	v7 = *(uint32_t**)(a1 + 700);
	if (nox_common_gameFlags_check_40A5C0(4096) && a2 && *(uint8_t*)(a2 + 8) & 4) {
		sub_4D7520(0);
		v3 = 1;
		v4 = nox_xxx_getFirstPlayerUnit_4DA7C0();
		if (!v4) {
			goto LABEL_17;
		}
		do {
			v5 = *(uint32_t*)(v4 + 748);
			if (*(uint32_t*)(*(uint32_t*)(v5 + 276) + 4792) == 1 && *(uint32_t*)(v5 + 308)) {
				v3 = 0;
			}
			v4 = nox_xxx_getNextPlayerUnit_4DA7F0(v4);
		} while (v4);
		if (v3 == 1) {
		LABEL_17:
			sub_4D71E0(nox_frame_xxx_2598000);
		}
		v6 = *(uint32_t*)(a2 + 748);
		if (*(float2**)(v6 + 308) != v2 || (unsigned int)(nox_frame_xxx_2598000 - *v7) > (int)nox_gameFPS) {
			nox_xxx_aud_501960(1005, (int)v2, 0, 0);
			nox_xxx_netSendPointFx_522FF0(130, v2 + 7);
			nox_xxx_netPriMsgToPlayer_4DA2C0(a2, "objcoll.c:SoulGateCollide", 0);
		}
		*(uint32_t*)(v6 + 308) = v2;
		*v7 = nox_frame_xxx_2598000;
	}
}

//----- (004EBF40) --------------------------------------------------------
void nox_xxx_collideAnkhQuest_4EBF40(int a1, int a2) {
	int v2;            // esi
	int v3;            // ebp
	int v4;            // ebx
	int v5;            // ecx
	uint32_t* v6;      // eax
	int v7;            // edi
	int v8;            // eax
	int v9;            // edx
	int v10;           // eax
	uint32_t* v11;     // ecx
	uint32_t* v12;     // eax
	int v13;           // edx
	int v14;           // eax
	uint32_t* v15;     // ecx
	unsigned char v16; // al
	float v17;         // [esp+0h] [ebp-20h]
	int v18;           // [esp+14h] [ebp-Ch]
	int v19;           // [esp+18h] [ebp-8h]

	v2 = a2;
	v3 = *(uint32_t*)(a1 + 692);
	v19 = 0;
	if (a2 && *(uint8_t*)(a2 + 8) & 4) {
		v4 = *(uint32_t*)(a2 + 748);
		v5 = 0;
		v6 = (uint32_t*)(*(uint32_t*)(v4 + 276) + 4796);
		while (*v6 != a1) {
			++v5;
			++v6;
			if (v5 >= 5) {
				goto LABEL_8;
			}
		}
		v19 = 1;
	LABEL_8:
		v18 = 0;
		v7 = v3 + 50;
		do {
			if (nox_frame_xxx_2598000 - *(uint32_t*)(v7 + 26) > (unsigned int)(240 * nox_gameFPS)) {
				nox_wcscpy((wchar_t*)(v7 - 50), (const wchar_t*)getMemAt(0x5D4594, 1568012));
				*(uint8_t*)(v7 + 1) = getMemByte(0x5D4594, 1568016);
				*(uint8_t*)v7 = 0;
				*(uint32_t*)(v7 + 26) = 0;
			}
			v8 = *(uint32_t*)(v4 + 276);
			if (*(uint8_t*)v7 == *(uint8_t*)(v8 + 2251) &&
				!nox_wcscmp((const wchar_t*)(v7 - 50), (const wchar_t*)(v8 + 2185))) {
				if (!strcmp((const char*)(v7 + 1), (const char*)(*(uint32_t*)(v4 + 276) + 2112))) {
					v9 = *(uint32_t*)(v4 + 276);
					v10 = 0;
					v11 = (uint32_t*)(v9 + 4796);
					while (*v11) {
						++v10;
						++v11;
						if (v10 >= 5) {
							v2 = a2;
							goto LABEL_17;
						}
					}
					v2 = a2;
					*(uint32_t*)(v9 + 4 * v10 + 4796) = a1;
				LABEL_17:
					if ((unsigned long long)(nox_platform_get_ticks() - *(uint64_t*)&qword_5d4594_1567940) <= 0x5DC) {
						return;
					}
					nox_xxx_netPriMsgToPlayer_4DA2C0(v2, "objcoll.c:ExtraLifeAlreadyAwarded", 0);
				LABEL_19:
					nox_xxx_aud_501960(925, v2, 0, 0);
					*(uint64_t*)&qword_5d4594_1567940 = nox_platform_get_ticks();
					return;
				}
				v2 = a2;
			}
			v7 += 80;
			++v18;
		} while (v18 < 64);
		if (v19 == 1) {
			goto LABEL_17;
		}
		v17 = nox_xxx_gamedataGetFloat_419D40("MaxExtraLives");
		if (*(uint32_t*)(v4 + 320) < nox_float2int(v17)) {
			v12 = nox_xxx_newObjectByTypeID_4E3810("AnkhTradable");
			if (v12) {
				((void (*)(int, uint32_t*, int, uint32_t))v12[177])(v2, v12, 1, 0);
			}
			*(uint32_t*)(a1 + 136) = nox_frame_xxx_2598000;
			nox_xxx_aud_501960(1004, a1, 0, 0);
			nox_xxx_netSendPointFx_522FF0(130, (float2*)(a1 + 56));
			nox_xxx_netPriMsgToPlayer_4DA2C0(v2, "objcoll.c:AwardExtraLife", 0);
			v13 = *(uint32_t*)(v4 + 276);
			v14 = 0;
			v15 = (uint32_t*)(v13 + 4796);
			while (*v15) {
				++v14;
				++v15;
				if (v14 >= 5) {
					goto LABEL_35;
				}
			}
			*(uint32_t*)(v13 + 4 * v14 + 4796) = a1;
		LABEL_35:
			nox_wcscpy((wchar_t*)(v3 + 80 * *(unsigned char*)(v3 + 5120)),
					   (const wchar_t*)(*(uint32_t*)(v4 + 276) + 2185));
			*(uint8_t*)(80 * *(unsigned char*)(v3 + 5120) + v3 + 50) = *(uint8_t*)(*(uint32_t*)(v4 + 276) + 2251);
			strcpy((char*)(80 * *(unsigned char*)(v3 + 5120) + v3 + 51), (const char*)(*(uint32_t*)(v4 + 276) + 2112));
			*(uint32_t*)(80 * *(unsigned char*)(v3 + 5120) + v3 + 76) = nox_frame_xxx_2598000;
			v16 = *(uint8_t*)(v3 + 5120) + 1;
			*(uint8_t*)(v3 + 5120) = v16;
			if (v16 >= 0x40u) {
				*(uint8_t*)(v3 + 5120) = 0;
			}
		} else if ((unsigned long long)(nox_platform_get_ticks() - *(uint64_t*)&qword_5d4594_1567940) > 0x5DC) {
			nox_xxx_netPriMsgToPlayer_4DA2C0(v2, "pickup.c:MaxTradableAnkhsReached", 0);
			goto LABEL_19;
		}
	}
}

//----- (004EC290) --------------------------------------------------------
void nox_xxx_unitSetOwner_4EC290(nox_object_t* obj1, nox_object_t* obj2) {
	int a1 = obj1;
	int a2 = obj2;
	if (!a2) {
		return;
	}
	nox_xxx_unitClearOwner_4EC300(a2);
	int v2 = a1;
	if (a1) {
		while (*(uint8_t*)(v2 + 16) & 0x20) {
			v2 = *(uint32_t*)(v2 + 508);
			if (!v2) {
				break;
			}
		}
		if (v2) {
			*(uint32_t*)(a2 + 512) = *(uint32_t*)(v2 + 516);
			*(uint32_t*)(v2 + 516) = a2;
		}
	}
	*(uint32_t*)(a2 + 508) = v2;
	if (*(uint8_t*)(a2 + 8) & 2) {
		nox_xxx_monsterResetEnemy_5346F0(a2);
	}
	if (*(uint8_t*)(a2 + 8) & 6) {
		nox_xxx_monsterMarkUpdate_4E8020(a2);
	}
}

//----- (004EC300) --------------------------------------------------------
void nox_xxx_unitClearOwner_4EC300(nox_object_t* obj) {
	int a1 = obj;
	int v1;  // eax
	int v2;  // edx
	int v3;  // edi
	int v4;  // edx
	int v5;  // ecx
	int v6;  // eax
	char v7; // al

	if (a1) {
		v1 = *(uint32_t*)(a1 + 508);
		if (v1) {
			if (*(uint8_t*)(v1 + 8) & 4 && nox_xxx_creatureIsMonitored_500CC0(v1, a1)) {
				v2 = *(uint32_t*)(a1 + 12);
				LOBYTE(v2) = v2 & 0x7F;
				v3 = *(uint32_t*)(*(uint32_t*)(a1 + 508) + 748);
				*(uint32_t*)(a1 + 12) = v2;
				nox_xxx_netFxShield_0_4D9200(*(unsigned char*)(*(uint32_t*)(v3 + 276) + 2064), a1);
				nox_xxx_netUnmarkMinimapObj_417300(*(unsigned char*)(*(uint32_t*)(v3 + 276) + 2064), a1, 1);
			}
			v4 = *(uint32_t*)(a1 + 508);
			v5 = 0;
			v6 = *(uint32_t*)(v4 + 516);
			if (!v6) {
				goto LABEL_18;
			}
			do {
				if (v6 == a1) {
					break;
				}
				v5 = v6;
				v6 = *(uint32_t*)(v6 + 512);
			} while (v6);
			if (v5) {
				*(uint32_t*)(v5 + 512) = *(uint32_t*)(a1 + 512);
			} else {
			LABEL_18:
				*(uint32_t*)(v4 + 516) = *(uint32_t*)(a1 + 512);
			}
			v7 = *(uint8_t*)(a1 + 8);
			*(uint32_t*)(a1 + 508) = 0;
			if (v7 & 2) {
				nox_xxx_monsterResetEnemy_5346F0(a1);
			}
			if (*(uint8_t*)(a1 + 8) & 6) {
				nox_xxx_monsterMarkUpdate_4E8020(a1);
			}
		}
	}
}

//----- (004EC3E0) --------------------------------------------------------
int nox_xxx_playerObserverFindGoodSlave2_4EC3E0(int a1) {
	int result; // eax

	if (!a1) {
		return 0;
	}
	result = *(uint32_t*)(a1 + 516);
	if (!result) {
		return 0;
	}
	while (!(*(uint8_t*)(result + 8) & 2) || !(*(uint8_t*)(*(uint32_t*)(result + 748) + 1440) & 0x80)) {
		result = *(uint32_t*)(result + 512);
		if (!result) {
			return 0;
		}
	}
	return result;
}

//----- (004EC420) --------------------------------------------------------
int nox_xxx_playerObserverFindGoodSlave_4EC420(int a1) {
	int result; // eax

	if (!a1) {
		return 0;
	}
	if (!*(uint32_t*)(a1 + 508)) {
		return 0;
	}
	result = *(uint32_t*)(a1 + 512);
	if (!result) {
		return 0;
	}
	while (!(*(uint8_t*)(result + 8) & 2) || !(*(uint8_t*)(*(uint32_t*)(result + 748) + 1440) & 0x80)) {
		result = *(uint32_t*)(result + 512);
		if (!result) {
			return 0;
		}
	}
	return result;
}

//----- (004EC470) --------------------------------------------------------
void nox_xxx_unitRemoveChild_4EC470(int a1) {
	int v1; // eax
	int v2; // ecx

	if (a1) {
		v1 = *(uint32_t*)(a1 + 516);
		if (v1) {
			do {
				v2 = *(uint32_t*)(v1 + 512);
				*(uint32_t*)(v1 + 508) = 0;
				*(uint32_t*)(v1 + 512) = 0;
				v1 = v2;
			} while (v2);
		}
		*(uint32_t*)(a1 + 516) = 0;
	}
}

//----- (004EC4B0) --------------------------------------------------------
void nox_xxx_unitTransferSlaves_4EC4B0(int a1) {
	int v1; // eax
	int v2; // esi

	if (a1) {
		v1 = *(uint32_t*)(a1 + 516);
		if (v1) {
			do {
				v2 = *(uint32_t*)(v1 + 512);
				nox_xxx_unitSetOwner_4EC290(*(uint32_t*)(a1 + 508), v1);
				v1 = v2;
			} while (v2);
		}
	}
}

//----- (004EC4F0) --------------------------------------------------------
int nox_xxx_unitHasThatParent_4EC4F0(int a1, int a2) {
	int v2; // eax

	v2 = a1;
	if (!a1 || !a2) {
		return 0;
	}
	while (v2 != a2) {
		v2 = *(uint32_t*)(v2 + 508);
		if (!v2) {
			return 0;
		}
	}
	return 1;
}

//----- (004EC520) --------------------------------------------------------
int nox_xxx_unitsHaveSameTeam_4EC520(int a1, int a2) {
	int v2; // edi
	int v3; // esi

	v2 = a1;
	if (a1 && a2) {
		while (2) {
			v3 = a2;
			do {
				if (nox_xxx_servCompareTeams_419150(v2 + 48, v3 + 48) || v2 == v3) {
					return 1;
				}
				v3 = *(uint32_t*)(v3 + 508);
			} while (v3);
			v2 = *(uint32_t*)(v2 + 508);
			if (v2) {
				continue;
			}
			break;
		}
	}
	return 0;
}

#ifndef NOX_CGO
//----- (004EC580) --------------------------------------------------------
nox_object_t* nox_xxx_findParentChainPlayer_4EC580(nox_object_t* unitp) {
	int unit = unitp;
	int result; // eax
	int i;      // ecx

	result = unit;
	if (unit) {
		for (i = *(uint32_t*)(unit + 508); i; i = *(uint32_t*)(i + 508)) {
			if (*(uint8_t*)(result + 8) & 4) {
				break;
			}
			result = i;
		}
	}
	return result;
}
#endif // NOX_CGO

//----- (004EC5B0) --------------------------------------------------------
void sub_4EC5B0() {
	dword_5d4594_1568024 = 0;
	nox_alloc_class_free_all(*(uint32_t**)&nox_alloc_respawn_1568020);
	nox_xxx_respawnAllow_587000_205200 = 1;
}

//----- (004EC5E0) --------------------------------------------------------
uint32_t* nox_xxx_respawnAdd_4EC5E0(int a1) {
	uint32_t* result;  // eax
	uint32_t* v2;      // ebx
	unsigned short v3; // cx
	uint8_t* v4;       // ebp

	result = *(uint32_t**)&nox_xxx_respawnAllow_587000_205200;
	if (nox_xxx_respawnAllow_587000_205200) {
		result = nox_alloc_class_new_obj_zero(*(uint32_t**)&nox_alloc_respawn_1568020);
		v2 = result;
		if (result) {
			v3 = *(uint16_t*)(a1 + 4);
			result[1] = a1;
			*result = v3;
			result[2] = *(uint32_t*)(a1 + 56);
			result[3] = *(uint32_t*)(a1 + 60);
			*((uint16_t*)result + 8) = *(uint16_t*)(a1 + 124);
			if (*(uint32_t*)(a1 + 8) & 0x13001000) {
				memcpy(result + 7, *(const void**)(a1 + 692), 0x14u);
			}
			if (*(uint32_t*)(a1 + 8) & 0x1000000 && nox_xxx_weaponInventoryEquipFlags_415820(a1) & 0x82) {
				v4 = *(uint8_t**)(a1 + 736);
				*((uint8_t*)v2 + 48) = v4[1];
				*((uint8_t*)v2 + 49) = *v4;
			}
			v2[14] = 0;
			v2[13] = dword_5d4594_1568024;
			result = *(uint32_t**)&dword_5d4594_1568024;
			if (dword_5d4594_1568024) {
				*(uint32_t*)(dword_5d4594_1568024 + 56) = v2;
			}
			dword_5d4594_1568024 = v2;
		}
	}
	return result;
}

//----- (004EC6A0) --------------------------------------------------------
void sub_4EC6A0(int a1) {
	int v1;       // eax
	uint64_t* v2; // ecx
	int v3;       // eax
	int v4;       // ecx
	int v5;       // ecx

	v1 = dword_5d4594_1568024;
	if (*(uint32_t*)(dword_5d4594_1568024 + 4) == a1) {
		v2 = *(uint64_t**)&dword_5d4594_1568024;
		dword_5d4594_1568024 = *(uint32_t*)(dword_5d4594_1568024 + 52);
		v3 = *(uint32_t*)(v1 + 52);
		if (v3) {
			*(uint32_t*)(v3 + 56) = 0;
		}
		nox_alloc_class_free_obj_first(*(unsigned int**)&nox_alloc_respawn_1568020, v2);
	} else if (dword_5d4594_1568024) {
		while (*(uint32_t*)(v1 + 4) != a1) {
			v1 = *(uint32_t*)(v1 + 52);
			if (!v1) {
				return;
			}
		}
		v4 = *(uint32_t*)(v1 + 56);
		if (v4) {
			*(uint32_t*)(v4 + 52) = *(uint32_t*)(v1 + 52);
		}
		v5 = *(uint32_t*)(v1 + 52);
		if (v5) {
			*(uint32_t*)(v5 + 56) = *(uint32_t*)(v1 + 56);
		}
		nox_alloc_class_free_obj_first(*(unsigned int**)&nox_alloc_respawn_1568020, (uint64_t*)v1);
	}
}

//----- (004ECA60) --------------------------------------------------------
int nox_xxx_allocItemRespawnArray_4ECA60() {
	nox_alloc_respawn_1568020 = nox_new_alloc_class("Respawn", 60, 384);
	return nox_alloc_respawn_1568020 != 0;
}

//----- (004ECA90) --------------------------------------------------------
void sub_4ECA90() { nox_free_alloc_class(*(void**)&nox_alloc_respawn_1568020); }

//----- (004ECAA0) --------------------------------------------------------
char* sub_4ECAA0(char a1) {
	char* result; // eax

	if (a1 <= 16) {
		result = *(char**)getMemAt(0x587000, 205304 + 4 * a1);
	} else {
		result = *(char**)getMemAt(0x587000, 205304);
	}
	return result;
}

//----- (004ECAC0) --------------------------------------------------------
unsigned char sub_4ECAC0(const char* a1) {
	unsigned char result; // al
	unsigned char v2;     // [esp+Ch] [ebp-4h]

	result = 0;
	v2 = 0;
	while (strcmp(a1, *(const char**)getMemAt(0x587000, 205304 + 4 * v2))) {
		v2 = ++result;
		if (result > 0x10u) {
			return 0;
		}
	}
	return result;
}

//----- (004ECB20) --------------------------------------------------------
char* sub_4ECB20(char* a1) {
	int v2;           // ecx
	unsigned char* i; // eax
	int v4;           // esi

	if (!a1) {
		return (char*)getMemAt(0x587000, 205676);
	}
	v2 = 0;
	if (!*getMemU32Ptr(0x587000, 205224)) {
		return 0;
	}
	for (i = getMemAt(0x587000, 205224); *((char**)i + 1) != a1; i += 8) {
		v4 = *((uint32_t*)i + 2);
		++v2;
		if (!v4) {
			return 0;
		}
	}
	return *(char**)getMemAt(0x587000, 205224 + 8 * v2);
}

//----- (004ECB60) --------------------------------------------------------
int sub_4ECB60(const char* a1) {
	const char* v1;    // eax
	int v2;            // ebp
	unsigned char* v3; // edi

	v1 = *(const char**)getMemAt(0x587000, 205224);
	v2 = 0;
	if (!*getMemU32Ptr(0x587000, 205224)) {
		return 0;
	}
	v3 = getMemAt(0x587000, 205224);
	while (strcmp(v1, a1)) {
		v1 = (const char*)*((uint32_t*)v3 + 2);
		v3 += 8;
		++v2;
		if (!v1) {
			return 0;
		}
	}
	return *getMemU32Ptr(0x587000, 205228 + 8 * v2);
}

//----- (004ECBD0) --------------------------------------------------------
int sub_4ECBD0(int a1) {
	int result; // eax

	if (*(uint32_t*)(a1 + 8) & 0x10000000) {
		result = sub_4ECC00(*(const char***)(*(uint32_t*)(a1 + 692) + 4));
	} else {
		result = 0;
	}
	return result;
}

//----- (004ECC00) --------------------------------------------------------
int sub_4ECC00(const char** a1) {
	const char* v1;    // esi
	int v2;            // edx
	unsigned char* v3; // edi

	if (!a1) {
		return 0;
	}
	v1 = *(const char**)getMemAt(0x587000, 205224);
	v2 = 0;
	if (!*getMemU32Ptr(0x587000, 205224)) {
		return 0;
	}
	v3 = getMemAt(0x587000, 205224);
	while (strcmp(*a1, v1)) {
		v1 = (const char*)*((uint32_t*)v3 + 2);
		v3 += 8;
		++v2;
		if (!v1) {
			return 0;
		}
	}
	return *getMemU32Ptr(0x587000, 205228 + 8 * v2);
}

//----- (004ECC70) --------------------------------------------------------
int sub_4ECC70(int a1) {
	int v1;     // eax
	int result; // eax

	v1 = *getMemU32Ptr(0x5D4594, 1568032); // FIXME: could be part of netCodeCache struct, but there are no references
										   // to this function at all
	if (!*getMemU32Ptr(0x5D4594, 1568032)) {
		v1 = nox_xxx_getNameId_4E3AA0("TeamBase");
		*getMemU32Ptr(0x5D4594, 1568032) = v1;
	}
	if (*(unsigned short*)(a1 + 4) == v1) {
		result = sub_4ECC00(*(const char***)(*(uint32_t*)(a1 + 692) + 4));
	} else {
		result = 0;
	}
	return result;
}

//----- (004ECCB0) --------------------------------------------------------
int nox_server_getObjectFromNetCode_4ECCB0(int a1) {
	int result; // eax
	int v2;     // edi
	int v3;     // esi
	char* v4;   // eax
	int v5;     // ecx

	result = nox_server_netCodeCache_lookupObj_4ECD90(a1);
	if (!result) {
		v2 = nox_server_getFirstObject_4DA790();
		if (v2) {
			while (1) {
				if (!(*(uint8_t*)(v2 + 16) & 0x20) && *(uint32_t*)(v2 + 36) == a1) {
					nox_server_netCodeCache_addObj_4ECEA0(v2);
					return v2;
				}
				v3 = *(uint32_t*)(v2 + 504);
				if (v3) {
					break;
				}
			LABEL_9:
				v2 = nox_server_getNextObject_4DA7A0(v2);
				if (!v2) {
					goto LABEL_10;
				}
			}
			while (*(uint8_t*)(v3 + 16) & 0x20 || *(uint32_t*)(v3 + 36) != a1) {
				v3 = *(uint32_t*)(v3 + 496);
				if (!v3) {
					goto LABEL_9;
				}
			}
			goto LABEL_16;
		}
	LABEL_10:
		v3 = nox_server_getFirstObjectUninited_4DA870();
		if (v3) {
			while (*(uint8_t*)(v3 + 16) & 0x20 || *(uint32_t*)(v3 + 36) != a1) {
				v3 = nox_server_getNextObjectUninited_4DA880(v3);
				if (!v3) {
					goto LABEL_17;
				}
			}
		LABEL_16:
			nox_server_netCodeCache_addObj_4ECEA0(v3);
			return v3;
		}
	LABEL_17:
		v4 = nox_common_playerInfoGetFirst_416EA0();
		if (v4) {
			while (1) {
				v5 = *((uint32_t*)v4 + 514);
				if (v5) {
					if (!(*(uint8_t*)(v5 + 16) & 0x20) && *(uint32_t*)(v5 + 36) == a1) {
						break;
					}
				}
				v4 = nox_common_playerInfoGetNext_416EE0((int)v4);
				if (!v4) {
					goto LABEL_22;
				}
			}
			result = *((uint32_t*)v4 + 514);
		} else {
		LABEL_22:
			result = 0;
		}
	}
	return result;
}

nox_server_netCodeCacheStruct nox_server_netCodeCache;

//----- (004ECD90) --------------------------------------------------------
int nox_server_netCodeCache_lookupObj_4ECD90(int a1) {
	uint32_t* v1; // esi

	if (nox_server_needInitNetCodeCache) {
		nox_server_netCodeCache_initArray_4ECE50();
	}
	v1 = *(uint32_t**)&nox_server_netCodeCache.firstUsedObject;
	if (!*(uint32_t*)&nox_server_netCodeCache.firstUsedObject) {
		return 0;
	}
	while (*(uint32_t*)(*v1 + 36) != a1) { // Search for netCode/objectCode/extent in cache
		v1 = (uint32_t*)v1[2];
		if (!v1) {
			return 0;
		}
	}
	sub_4ECE10(&nox_server_netCodeCache.firstUsedObject, (int)v1);
	sub_4ECDE0(&nox_server_netCodeCache.firstUsedObject, (int)v1);
	return *v1;
}

//----- (004ECDE0) --------------------------------------------------------
int sub_4ECDE0(uint32_t* a1, int a2) {
	int result; // eax

	result = a2;
	*(uint32_t*)(a2 + 4) = 0;
	*(uint32_t*)(a2 + 8) = *a1;
	if (*a1) {
		*(uint32_t*)(*a1 + 4) = a2;
	} else {
		a1[1] = a2;
	}
	*a1 = a2;
	return result;
}

//----- (004ECE10) --------------------------------------------------------
int sub_4ECE10(uint32_t* a1, int a2) {
	int result; // eax
	int v3;     // ecx
	int v4;     // ecx

	result = a2;
	v3 = *(uint32_t*)(a2 + 8);
	if (v3) {
		*(uint32_t*)(v3 + 4) = *(uint32_t*)(a2 + 4);
	} else {
		a1[1] = *(uint32_t*)(a2 + 4);
	}
	v4 = *(uint32_t*)(a2 + 4);
	if (v4) {
		*(uint32_t*)(v4 + 8) = *(uint32_t*)(a2 + 8);
	} else {
		result = *(uint32_t*)(a2 + 8);
		*a1 = result;
	}
	return result;
}

//----- (004ECE50) --------------------------------------------------------
int nox_server_netCodeCache_initArray_4ECE50() {
	unsigned char* v0; // esi
	int result;        // eax

	v0 = &nox_server_netCodeCache.objArray[0]; // actually start of the array! size=234-44=(192/12)=16
	nox_server_netCodeCache.firstUsedObject = 0;
	nox_server_netCodeCache.lastUsedObject = 0;
	nox_server_netCodeCache.firstFreeObject = 0;
	nox_server_netCodeCache.lastFreeObject = 0;
	do {
		result = sub_4ECDE0(&nox_server_netCodeCache.firstFreeObject, (int)v0);
		v0 += 12;
	} while ((int)v0 < &nox_server_netCodeCache.firstUsedObject);
	nox_server_needInitNetCodeCache = 0;
	return result;
}

//----- (004ECEA0) --------------------------------------------------------
int nox_server_netCodeCache_addObj_4ECEA0(int a1) {
	int* v1;    // eax
	int v2;     // esi
	int result; // eax
	int v4;     // [esp-8h] [ebp-8h]

	v1 = (int*)nox_server_netCodeCache_nextUnused_4ECEF0();
	if (v1) {
		*v1 = a1;
		result = sub_4ECDE0(&nox_server_netCodeCache.firstUsedObject, (int)v1);
	} else {
		v2 = nox_server_netCodeCache.lastUsedObject;
		v4 = nox_server_netCodeCache.lastUsedObject;
		nox_server_netCodeCache.lastUsedObject->value = a1;
		sub_4ECE10(&nox_server_netCodeCache.firstUsedObject, v4);
		result = sub_4ECDE0(&nox_server_netCodeCache.firstUsedObject, v2);
	}
	return result;
}

//----- (004ECEF0) --------------------------------------------------------
int nox_server_netCodeCache_nextUnused_4ECEF0() {
	int result; // eax

	result = nox_server_netCodeCache.firstFreeObject;
	if (!nox_server_netCodeCache.firstFreeObject) {
		return 0;
	}
	nox_server_netCodeCache.firstFreeObject =
		nox_server_netCodeCache.firstFreeObject->prev; //*(uint32_t*)(*(uint32_t*)&netCodeCache.firstFreeObject + 8);
	return result;
}

//----- (004ECF10) --------------------------------------------------------
int sub_4ECF10(int a1) {
	int result = nox_server_getFirstObject_4DA790();
	while (result) {
		if (!(*(uint8_t*)(result + 16) & 0x20 || *(uint32_t*)(result + 44) != a1)) {
			return result;
		}

		int v2 = *(uint32_t*)(result + 504);

		while (v2) {
			if (!(*(uint8_t*)(v2 + 16) & 0x20 || *(uint32_t*)(v2 + 44) != a1)) {
				return v2;
			}
			v2 = *(uint32_t*)(v2 + 496);
		}
		result = nox_server_getNextObject_4DA7A0(result);
	}

	result = nox_server_getFirstObjectUninited_4DA870();
	while (result != 0) {
		if (!(*(uint8_t*)(result + 16) & 0x20) && *(uint32_t*)(result + 44) == a1) {
			return result;
		}
		result = nox_server_getNextObjectUninited_4DA880(result);
	}

	nox_object_t* obj = nox_xxx_getFirstUpdatable2Object_4DA840();
	while (obj) {
		if (!(obj->flags & 0x20) && obj->script_id == a1) {
			return obj;
		}

		obj = nox_xxx_getNextUpdatable2Object_4DA850(obj);
	}

	return obj;
}

//----- (004ECFA0) --------------------------------------------------------
int sub_4ECFA0(int a1) {
	int result;   // eax
	uint32_t* v2; // esi

	result = nox_server_needInitNetCodeCache;
	if (!nox_server_needInitNetCodeCache) {
		v2 = *(uint32_t**)&nox_server_netCodeCache.firstUsedObject;
		if (*(uint32_t*)&nox_server_netCodeCache.firstUsedObject) {
			result = a1;
			while (*v2 != a1) {
				v2 = (uint32_t*)v2[2];
				if (!v2) {
					return result;
				}
			}
			sub_4ECE10(&nox_server_netCodeCache.firstUsedObject, (int)v2);
			result = sub_4ECDE0(&nox_server_netCodeCache.firstFreeObject, (int)v2);
		}
	}
	return result;
}

//----- (004ECFE0) --------------------------------------------------------
int sub_4ECFE0() {
	int result; // eax
	int v1;     // esi
	int v2;     // edi

	result = nox_server_needInitNetCodeCache;
	if (!nox_server_needInitNetCodeCache) {
		v1 = *(uint32_t*)&nox_server_netCodeCache.firstUsedObject;
		if (*(uint32_t*)&nox_server_netCodeCache.firstUsedObject) {
			do {
				v2 = *(uint32_t*)(v1 + 8);
				sub_4ECE10(&nox_server_netCodeCache.firstUsedObject, v1);
				result = sub_4ECDE0(&nox_server_netCodeCache.firstFreeObject, v1);
				v1 = v2;
			} while (v2);
		}
	}
	return result;
}

//----- (004ED020) --------------------------------------------------------
int nox_xxx_netGetUnitByExtent_4ED020(int a1) {
	int result; // eax

	result = nox_server_getFirstObject_4DA790();
	if (!result) {
		return 0;
	}
	while (*(uint8_t*)(result + 16) & 0x20 || *(uint32_t*)(result + 40) != a1) {
		result = nox_server_getNextObject_4DA7A0(result);
		if (!result) {
			return 0;
		}
	}
	return result;
}

//----- (004ED050) --------------------------------------------------------
void sub_4ED050(int a1, int a2) {
	int v2; // eax
	int i;  // esi
	int v4; // edi

	LOWORD(v2) = *getMemU16Ptr(0x5D4594, 1568248);
	if (!*getMemU32Ptr(0x5D4594, 1568248)) {
		v2 = nox_xxx_getNameId_4E3AA0("Crown");
		*getMemU32Ptr(0x5D4594, 1568248) = v2;
	}
	for (i = *(uint32_t*)(a1 + 516); i; i = *(uint32_t*)(i + 512)) {
		LOWORD(v2) = *(uint16_t*)(i + 4);
		if ((unsigned short)v2 == *getMemU32Ptr(0x5D4594, 1568248)) {
			v4 = *(uint32_t*)(i + 748);
			LOWORD(v2) = nox_xxx_dropCrown_4ED5E0(a1, i, (int*)(a1 + 56));
			*(uint32_t*)(v4 + 4) = a2;
		}
	}
}

//----- (004ED0C0) --------------------------------------------------------
void sub_4ED0C0(int a1, nox_object_t* object) {
	int v2;  // ebx
	int v3;  // eax
	int v4;  // ebp
	int v5;  // eax
	int v6;  // eax
	int v7;  // eax
	int v8;  // esi
	int i;   // ecx
	int v10; // edx

	v2 = 1;
	if (a1 && object) {
		v3 = *(uint32_t*)(a1 + 8);
		if (v3 & 4) {
			v4 = *(uint32_t*)(a1 + 748);
			if (!nox_common_gameFlags_check_40A5C0(4096) && (*(uint32_t*)(a1 + 16) & 0x8000) == 0x8000 &&
				object->obj_class & 0x13001000) {
				v2 = 0;
			}
			if (object->obj_class & 0x10000000) {
				if (nox_common_gameFlags_check_40A5C0(32)) {
					*(uint32_t*)(*(uint32_t*)(v4 + 276) + 4) &= 0xFFFFFFFE;
					if (v2 == 1) {
						nox_xxx_netReportDequip_4D84C0(255, object);
					}
				}
			}
			sub_53E430((uint32_t*)a1, object, 0, v2);
			nox_xxx_playerDequipWeapon_53A140((uint32_t*)a1, object, 0, v2);
			nox_xxx_netReportDrop_4D8B50(*(unsigned char*)(*(uint32_t*)(v4 + 276) + 2064), object);
			nox_xxx_protect_56FC50(*(uint32_t*)(*(uint32_t*)(v4 + 276) + 4632), object);
		} else if (v3 & 2) {
			if (*(uint8_t*)(a1 + 12) & 0x10 && object->obj_class & 0x10000000 &&
				nox_common_gameFlags_check_40A5C0(32)) {
				nox_xxx_npcSetItemEquipFlags_4E4B20(a1, object, 0);
			}
			sub_53E430((uint32_t*)a1, object, 1, 1);
			nox_xxx_playerDequipWeapon_53A140((uint32_t*)a1, object, 1, 1);
		}
		v5 = object->field_125;
		if (v5) {
			*(uint32_t*)(v5 + 496) = object->field_124;
		} else {
			*(uint32_t*)(a1 + 504) = object->field_124;
		}
		v6 = object->field_124;
		if (v6) {
			*(uint32_t*)(v6 + 500) = object->field_125;
		}
		object->field_123 = 0;
		nox_xxx_unitClearOwner_4EC300(object);
		if (*(uint8_t*)(a1 + 8) & 4) {
			v7 = *(uint32_t*)(a1 + 504);
			v8 = *(uint32_t*)(a1 + 748);
			for (i = 0; v7; i += v10) {
				v10 = *(unsigned char*)(v7 + 488);
				v7 = *(uint32_t*)(v7 + 496);
			}
			*(uint32_t*)(*(uint32_t*)(v8 + 276) + 3656) = i > *(unsigned short*)(a1 + 490);
		}
	}
}

//----- (004ED290) --------------------------------------------------------
int nox_xxx_dropDefault_4ED290(int a1, int a2, float2* a3) {
	int v3;            // ebp
	int result;        // eax
	int* v5;           // edi
	int v6;            // eax
	int v7;            // ebx
	int v8;            // eax
	char v9;           // di
	int v10;           // eax
	int v11;           // ecx
	int v12;           // eax
	char v13[10];      // [esp+8h] [ebp-Ch]
	unsigned char v14; // [esp+18h] [ebp+4h]

	v3 = a1;
	if (*(uint32_t*)(a2 + 492) != a1) {
		return 0;
	}
	if (*(uint8_t*)(a1 + 8) & 4 && nox_xxx_ItemIsDroppable_53EBF0(a2) && sub_53EC80(a2, 1)) {
		if (!(*(uint32_t*)(a1 + 16) & 0x8020)) {
			nox_xxx_netPriMsgToPlayer_4DA2C0(a1, "drop.c:CantDropThat", 0);
			nox_xxx_aud_501960(925, a1, 2, *(uint32_t*)(a1 + 36));
		}
		result = 0;
	} else {
		sub_4ED0C0(a1, (int*)a2);
		nox_xxx_createAt_4DAA50(a2, 0, a3->field_0, a3->field_4);
		if (*(uint32_t*)(a2 + 8) & 0x1000000) {
			if (nox_xxx_weaponInventoryEquipFlags_415820(a2) == 4) {
				v5 = *(int**)(a1 + 504);
				if (v5) {
					while (1) {
						if (v5[2] & 0x1000000) {
							if (nox_xxx_weaponInventoryEquipFlags_415820((int)v5) == 2) {
								v6 = v5[4];
								if (!(v6 & 0x100)) {
									if (*(uint8_t*)(v5[184] + 2)) {
										break;
									}
								}
							}
						}
						v5 = (int*)v5[124];
						if (!v5) {
							goto LABEL_19;
						}
					}
					sub_4ED0C0(a1, v5);
					nox_xxx_delayedDeleteObject_4E5CC0((int)v5);
				}
			}
		}
	LABEL_19:
		if (*(uint32_t*)(a2 + 8) & 0x10000000) {
			v7 = *(uint32_t*)(a2 + 748);
			v8 = sub_4ECBD0(a2);
			v9 = v8;
			v14 = *(uint8_t*)(a2 + 52);
			*(uint32_t*)&v13[2] = *(uint32_t*)(v3 + 36);
			*(uint32_t*)&v13[6] = v8;
			nox_xxx_netInformTextMsg2_4DA180(7, v13);
			nox_xxx_netMarkMinimapForAll_4174B0(a2, 1);
			*(uint32_t*)(v7 + 8) = nox_frame_xxx_2598000;
			sub_4E82C0(v14, 2, v9, 0);
		}
		if (!*getMemU32Ptr(0x5D4594, 1568252)) {
			*getMemU32Ptr(0x5D4594, 1568252) = nox_xxx_getNameId_4E3AA0("Glyph");
		}
		if (!nox_common_gameFlags_check_40A5C0(2048) && !nox_common_gameFlags_check_40A5C0(4096) &&
			!(*(uint32_t*)(a2 + 16) & 0x80000) && !(*(uint32_t*)(a2 + 8) & 0x10000000) &&
			*(unsigned short*)(a2 + 4) != *getMemU32Ptr(0x5D4594, 1568252)) {
			nox_xxx_unitSetDecayTime_511660((uint32_t*)a2, 10 * nox_gameFPS);
		}
		nox_xxx_unitRaise_4E46F0(a2, 0.0);
		if (*(uint8_t*)(a2 + 8) & 0x40) {
			nox_xxx_aud_501960(821, a2, 0, 0);
		}
		if (*(uint8_t*)(a2 + 8) & 2) {
			v10 = *(uint32_t*)(a2 + 748);
			v11 = *(uint32_t*)(v10 + 1440);
			*(uint32_t*)(v10 + 1360) = 15;
			BYTE1(v11) |= 1u;
			*(uint32_t*)(v10 + 1440) = v11;
		}
		if (!*getMemU32Ptr(0x5D4594, 1568256)) {
			*getMemU32Ptr(0x5D4594, 1568256) = nox_xxx_getNameId_4E3AA0("Torch");
			*getMemU32Ptr(0x5D4594, 1568244) = nox_xxx_getNameId_4E3AA0("Lantern");
		}
		v12 = *(unsigned short*)(a2 + 4);
		if ((unsigned short)v12 == *getMemU32Ptr(0x5D4594, 1568256) || v12 == *getMemU32Ptr(0x5D4594, 1568244)) {
			nox_xxx_spellBuffOff_4FF5B0(v3, 15);
		}
		result = 1;
	}
	return result;
}

//----- (004ED500) --------------------------------------------------------
int sub_4ED500(int a1, int a2, float2* a3) {
	short v3;  // ax
	float2 v5; // [esp+Ch] [ebp-8h]

	if (!nox_xxx_dropTrap_4ED580(a1, a2, a3)) {
		return 0;
	}
	*(float2*)(*(uint32_t*)(a2 + 692) + 28) = *a3;
	v5.field_0 = *(float*)(a1 + 56) - a3->field_0;
	v5.field_4 = *(float*)(a1 + 60) - a3->field_4;
	v3 = nox_xxx_math_509ED0(&v5);
	*(uint16_t*)(a2 + 126) = v3;
	*(uint16_t*)(a2 + 124) = v3;
	nox_xxx_aud_501960(825, a2, 0, 0);
	return 1;
}

//----- (004ED580) --------------------------------------------------------
int nox_xxx_dropTrap_4ED580(int a1, int a2, float2* a3) {
	if (nox_xxx_mapTileAllowTeleport_411A90(a3)) {
		nox_xxx_aud_501960(925, a1, 2, *(uint32_t*)(a1 + 36));
		return 0;
	}
	if (!nox_xxx_dropDefault_4ED290(a1, a2, a3)) {
		return 0;
	}
	nox_xxx_unitSetOwner_4EC290(a1, a2);
	return 1;
}

//----- (004ED5E0) --------------------------------------------------------
int nox_xxx_dropCrown_4ED5E0(int a1, int a2, int* a3) {
	int v3;       // edi
	int v4;       // ebx
	int v5;       // ebp
	int v6;       // esi
	int v7;       // edi
	int v8;       // esi
	int v10;      // [esp+10h] [ebp-10h]
	char v11[10]; // [esp+14h] [ebp-Ch]

	if (!nox_common_gameFlags_check_40A5C0(16) || !nox_xxx_CheckGameplayFlags_417DA0(4)) {
		v3 = a2;
		goto LABEL_14;
	}
	v3 = a2;
	v4 = nox_frame_xxx_2598000;
	if (!*(uint8_t*)(a2 + 52)) {
	LABEL_14:
		v8 = a1;
		goto LABEL_15;
	}
	v10 = *(uint32_t*)(a2 + 748);
	v5 = a2;
	v6 = nox_xxx_getFirstPlayerUnit_4DA7C0();
	if (v6) {
		do {
			v7 = *(uint32_t*)(v6 + 748);
			if (nox_xxx_teamCompare2_419180(v6 + 48, *(uint8_t*)(a2 + 52)) && *(uint32_t*)(v7 + 264) < v4) {
				v4 = *(uint32_t*)(v7 + 264);
				v5 = v6;
			}
			v6 = nox_xxx_getNextPlayerUnit_4DA7F0(v6);
		} while (v6);
		v3 = a2;
	}
	v8 = a1;
	if (v5 && a1 != v5) {
		*(uint32_t*)(v10 + 4) = v5;
	}
LABEL_15:
	if (!nox_xxx_dropDefault_4ED290(v8, v3, (float2*)a3)) {
		return 0;
	}
	nox_xxx_unitClearOwner_4EC300(v3);
	nox_xxx_spellBuffOff_4FF5B0(v8, 30);
	*(uint32_t*)&v11[2] = *(uint32_t*)(v8 + 36);
	if (nox_xxx_servObjectHasTeam_419130(v8 + 48)) {
		*(uint32_t*)&v11[6] = *(unsigned char*)(v8 + 52);
	} else {
		*(uint32_t*)&v11[6] = 0;
	}
	nox_xxx_netInformTextMsg2_4DA180(11, v11);
	nox_xxx_netMarkMinimapForAll_4174B0(v3, 1);
	return 1;
}

//----- (004ED710) --------------------------------------------------------
int nox_xxx_dropTreasure_4ED710(int a1, int a2, int* a3) {
	int v3; // edi

	if (!nox_xxx_dropDefault_4ED290(a1, a2, (float2*)a3)) {
		return 0;
	}
	if (*(uint8_t*)(a1 + 8) & 4) {
		if (nox_common_gameFlags_check_40A5C0(64)) {
			v3 = *(uint32_t*)(a1 + 748);
			--*(uint32_t*)(*(uint32_t*)(v3 + 276) + 2152);
			*(uint32_t*)(*(uint32_t*)(v3 + 276) + 2156) = nox_xxx_scavengerTreasureMax_4D1600();
			nox_xxx_scavengerHuntReport_4D8CD0(a1);
			nox_xxx_aud_501960(308, a1, 0, 0);
		}
	}
	return 1;
}

//----- (004ED790) --------------------------------------------------------
int nox_xxx_drop_4ED790(nox_object_t* a1p, nox_object_t* a2p, float2* a3) {
	int a1 = a1p;
	uint32_t* a2 = a2p;
	int result;                         // eax
	int (*v4)(int, uint32_t*, float2*); // eax

	if (!a2) {
		return 0;
	}
	if (nox_common_gameFlags_check_40A5C0(0x2000) && !nox_common_gameFlags_check_40A5C0(4096) && a2[2] & 0x3001010) {
		a2[4] |= 0x40u;
		nox_xxx_unit_511810((int)a2);
	}
	v4 = (int (*)(int, uint32_t*, float2*))a2[178];
	if (v4) {
		result = v4(a1, a2, a3);
	} else {
		result = nox_xxx_dropDefault_4ED290(a1, (int)a2, a3);
	}
	return result;
}

//----- (004ED810) --------------------------------------------------------
int nox_xxx_drop_4ED810(int a1, int a2, float* a3) {
	int v3;         // esi
	float v4;       // ecx
	float v5;       // eax
	double v6;      // st7
	double v7;      // st6
	long double v8; // st6
	int result;     // eax
	int v10;        // eax
	float4 v11;     // [esp+8h] [ebp-10h]
	float v12;      // [esp+1Ch] [ebp+4h]
	float v13;      // [esp+24h] [ebp+Ch]

	v3 = a1;
	v4 = *(float*)(a1 + 60);
	v11.field_0 = *(float*)(a1 + 56);
	v11.field_4 = v4;
	v5 = a3[1];
	v11.field_8 = *a3;
	v11.field_C = v5;
	v6 = v11.field_8 - v11.field_0;
	v7 = v5 - v4;
	v12 = v7;
	v8 = sqrt(v7 * v12 + v6 * v6);
	v13 = v8;
	if (v8 > 75.0) {
		v11.field_8 = v6 * 75.0 / v13 + v11.field_0;
		v11.field_C = v12 * 75.0 / v13 + v11.field_4;
	}
	if (nox_xxx_mapTraceRay_535250(&v11, 0, 0, 0)) {
		if (!nox_common_gameFlags_check_40A5C0(16)) {
			goto LABEL_13;
		}
		v10 = *getMemU32Ptr(0x5D4594, 1568248);
		if (!*getMemU32Ptr(0x5D4594, 1568248)) {
			v10 = nox_xxx_getNameId_4E3AA0("Crown");
			*getMemU32Ptr(0x5D4594, 1568248) = v10;
		}
		if (*(unsigned short*)(a2 + 4) == v10) {
			result = 0;
		} else {
		LABEL_13:
			result = nox_xxx_drop_4ED790(v3, (uint32_t*)a2, (float2*)&v11.field_8);
		}
	} else {
		nox_xxx_netPriMsgToPlayer_4DA2C0(v3, "drop.c:DropNotAllowed", 0);
		nox_xxx_aud_501960(925, v3, 2, *(uint32_t*)(v3 + 36));
		result = 0;
	}
	return result;
}

//----- (004ED930) --------------------------------------------------------
int nox_xxx_invForceDropItem_4ED930(int a1, uint32_t* a2) {
	float2 v3; // [esp+4h] [ebp-8h]

	sub_4ED970(50.0, (float2*)(a1 + 56), &v3);
	return nox_xxx_drop_4ED790(a1, a2, &v3);
}

//----- (004ED970) --------------------------------------------------------
float2* sub_4ED970(float a1, float2* a2, float2* a3) {
	float2* v3;     // esi
	float v4;       // ecx
	int v5;         // edi
	double v6;      // st7
	float2* result; // eax
	float v8;       // edx
	float v9;       // [esp+0h] [ebp-14h]
	float4 v10;     // [esp+4h] [ebp-10h]
	float v11;      // [esp+1Ch] [ebp+8h]

	v3 = a2;
	v4 = a2->field_4;
	v9 = a1 * 0.015625;
	v10.field_0 = a2->field_0;
	v10.field_4 = v4;
	v11 = nox_common_randomFloat_416030(-3.1415927, 3.1415927);
	v5 = 0;
	while (1) {
		v6 = v11 + 1.8849558;
		v11 = v6;
		v10.field_8 = cos(v6) * a1 + v3->field_0;
		v10.field_C = sin(v11) * a1 + v3->field_4;
		if (nox_xxx_mapTraceRay_535250(&v10, 0, 0, 1)) {
			break;
		}
		++v5;
		a1 = a1 - v9;
		if (v5 >= 64) {
			result = a3;
			*a3 = *v3;
			return result;
		}
	}
	result = a3;
	v8 = v10.field_C;
	a3->field_0 = v10.field_8;
	a3->field_4 = v8;
	return result;
}

//----- (004EDA40) --------------------------------------------------------
uint32_t* nox_xxx_dropAllItems_4EDA40(uint32_t* a1) {
	float2* v1;       // ebp
	int v2;           // edi
	int v3;           // esi
	uint32_t* result; // eax
	float v5;         // edx
	int v6;           // esi
	int v7;           // ebx
	int v8;           // ecx
	int v9;           // edx
	uint32_t* v10;    // esi
	uint32_t* v11;    // edi
	float v12;        // [esp+10h] [ebp-34h]
	float v13;        // [esp+10h] [ebp-34h]
	int v14;          // [esp+14h] [ebp-30h]
	int v15;          // [esp+18h] [ebp-2Ch]
	int v16;          // [esp+1Ch] [ebp-28h]
	int v17;          // [esp+20h] [ebp-24h]
	uint32_t* v18;    // [esp+24h] [ebp-20h]
	uint32_t* v19;    // [esp+28h] [ebp-1Ch]
	int v20;          // [esp+2Ch] [ebp-18h]
	int v21;          // [esp+30h] [ebp-14h]
	float4 v22;       // [esp+34h] [ebp-10h]
	uint32_t* v23;    // [esp+48h] [ebp+4h]

	v1 = (float2*)a1;
	v2 = 0;
	v3 = a1[126];
	v12 = 0.0;
	while (v3) {
		if (nox_xxx_unitDropCheckSome_4EDCD0((int)a1, v3) && *(float*)(v3 + 176) > (double)v12) {
			v12 = *(float*)(v3 + 176);
		}
		v3 = *(uint32_t*)(v3 + 496);
	}
	result = (uint32_t*)a1[126];
	v5 = *((float*)a1 + 15);
	v6 = -1;
	v15 = 0;
	v7 = 3;
	v20 = 0;
	v21 = -1;
	v14 = 0;
	v16 = 0;
	v22.field_0 = *((float*)a1 + 14);
	v22.field_4 = v5;
	v23 = result;
	v13 = v12 + v12 + 6.0;
	if (!result) {
		return result;
	}
	while (2) {
		v19 = (uint32_t*)result[124];
		if (!nox_xxx_unitDropCheckSome_4EDCD0((int)v1, (int)result)) {
			v8 = 1;
		} else {
			v17 = 0;
			v18 = (uint32_t*)(v7 - 1);
			while (1) {
				v22.field_8 = (double)v20 * v13 + v1[7].field_0;
				v22.field_C = v1[7].field_4 - (double)v21 * v13;
				v22.field_8 = nox_common_randomFloat_416030(-3.0, 3.0) + v22.field_8;
				v22.field_C = nox_common_randomFloat_416030(-3.0, 3.0) + v22.field_C;
				if (nox_xxx_mapTraceRay_535250(&v22, 0, 0, 1)) {
					nox_xxx_drop_4ED790((int)v1, v23, (float2*)&v22.field_8);
					v8 = 1;
					v16 = 1;
					v17 = 1;
				} else {
					v8 = v17;
				}
				result = v18;
				if ((uint32_t*)v14 != v18) {
					v9 = v15;
					++v14;
					switch (v9) {
					case 0:
						v20 = ++v2;
						break;
					case 1:
						++v6;
						v21 = v6;
						break;
					case 2:
						v20 = --v2;
						break;
					case 3:
						--v6;
						v21 = v6;
						break;
					default:
						break;
					}
				} else if (v15 != 3 && v18) {
					v9 = v15 + 1;
					v14 = 1;
					++v15;
					switch (v9) {
					case 0:
						v20 = ++v2;
						break;
					case 1:
						++v6;
						v21 = v6;
						break;
					case 2:
						v20 = --v2;
						break;
					case 3:
						--v6;
						v21 = v6;
						break;
					default:
						break;
					}
				} else {
					if (!v16) {
						break;
					}
					v7 += 2;
					v18 = (uint32_t*)((char*)v18 + 2);
					v2 = 1 - v7 / 2;
					v20 = 1 - v7 / 2;
					v14 = 1;
					v6 = v7 / -2;
					v21 = v7 / -2;
					v15 = 0;
					v16 = 0;
				}
				if (v8) {
					break;
				}
			}
		}
		if (!v8) {
			break;
		}
		result = v19;
		v23 = v19;
		if (!v19) {
			return result;
		}
		result = v19;
	}
	v10 = v23;
	if (!v23) {
		return result;
	}
	while (1) {
		v11 = (uint32_t*)v10[124];
		result = (uint32_t*)nox_xxx_unitDropCheckSome_4EDCD0((int)v1, (int)v10);
		if (result) {
			result = (uint32_t*)nox_xxx_drop_4ED790((int)v1, v10, v1 + 7);
		}
		if (!v11) {
			break;
		}
		v10 = v11;
	}
	return result;
}

//----- (004EDCD0) --------------------------------------------------------
int nox_xxx_unitDropCheckSome_4EDCD0(int a1, int a2) {
	int v2; // eax

	v2 = *(uint32_t*)(a2 + 16);
	return v2 & 0x20 || !(*(uint8_t*)(a1 + 8) & 6) || !(v2 & 0x10000000);
}

//----- (004EDD00) --------------------------------------------------------
void sub_4EDD00(int a1, int a2) {
	int v2;    // eax
	int* v3;   // esi
	int v4;    // edi
	float2 a3; // [esp+8h] [ebp-8h]

	v2 = nox_xxx_inventoryGetFirst_4E7980(a1);
	v3 = (int*)v2;
	if (v2) {
		do {
			v4 = nox_xxx_inventoryGetNext_4E7990((int)v3);
			v2 = v3[2];
			if (v2 & a2) {
				sub_4ED0C0(a1, v3);
				sub_4ED970(60.0, (float2*)(a1 + 56), &a3);
				nox_xxx_createAt_4DAA50((int)v3, 0, a3.field_0, a3.field_4);
			}
			v3 = (int*)v4;
		} while (v4);
	}
}

//----- (004EDDE0) --------------------------------------------------------
int sub_4EDDE0(int a1, uint32_t* a2, int* a3) {
	if (!nox_xxx_dropDefault_4ED290(a1, (int)a2, (float2*)a3)) {
		return 0;
	}
	nox_xxx_aud_501960(833, (int)a2, 0, 0);
	if (!nox_common_gameFlags_check_40A5C0(2048) && !nox_common_gameFlags_check_40A5C0(4096)) {
		nox_xxx_unitSetDecayTime_511660(a2, 25 * nox_gameFPS);
	}
	return 1;
}

//----- (004EDE50) --------------------------------------------------------
int nox_xxx_dropFood_4EDE50(int a1, int a2, int* a3) {
	int v3;            // edi
	unsigned char* v4; // eax

	if (!a1 || !a2 || !a3) {
		return 0;
	}
	v3 = nox_xxx_dropDefault_4ED290(a1, a2, (float2*)a3);
	if (v3) {
		if (!nox_common_gameFlags_check_40A5C0(2048)) {
			nox_xxx_unitSetDecayTime_511660((uint32_t*)a2, 25 * nox_gameFPS);
		}
		v4 = getMemAt(0x587000, 205704);
		if (*getMemU16Ptr(0x587000, 205710)) {
			while (!(*(uint32_t*)(a2 + 12) & *(uint32_t*)v4) && !(*((uint16_t*)v4 + 2) & *(uint16_t*)(a2 + 24))) {
				v4 += 8;
				if (!*((uint16_t*)v4 + 3)) {
					return v3;
				}
			}
			nox_xxx_aud_501960(*((unsigned short*)v4 + 3), a1, 0, 0);
		}
	}
	return v3;
}

//----- (004EDF00) --------------------------------------------------------
void nox_xxx_chest_4EDF00(int a1, int a2) {
	int v2;        // eax
	double v3;     // st7
	double v4;     // st7
	double v5;     // st7
	double v6;     // st6
	double v7;     // st7
	double v8;     // st6
	double v9;     // st7
	double v10;    // st6
	double v11;    // st5
	float v12;     // ecx
	float v13;     // edx
	float v14;     // eax
	float v15;     // eax
	float v16;     // esi
	float v17;     // eax
	float v18;     // esi
	float v19;     // ecx
	float v20;     // ecx
	float v21;     // eax
	float v22;     // edx
	int v23;       // eax
	uint32_t* v24; // esi
	int v25;       // esi
	int v26;       // edi
	float v27;     // [esp+Ch] [ebp-44h]
	float v28;     // [esp+10h] [ebp-40h]
	float v29;     // [esp+14h] [ebp-3Ch]
	float v30;     // [esp+18h] [ebp-38h]
	int v31;       // [esp+1Ch] [ebp-34h]
	int v32;       // [esp+1Ch] [ebp-34h]
	float2 a1a;    // [esp+20h] [ebp-30h]
	float4 v34;    // [esp+28h] [ebp-28h]
	float2 a3[3];  // [esp+38h] [ebp-18h]

	if (a1) {
		if (a2) {
			v31 = nox_xxx_inventoryCountObjects_4E7D30(a1, 0);
			if (v31) {
				v2 = *(uint32_t*)(a1 + 12);
				if (v2 & 0x100) {
					a1a.field_0 = -1.0;
					a1a.field_4 = -1.0;
				} else if (v2 & 0x200) {
					a1a.field_0 = 1.0;
					a1a.field_4 = -1.0;
				} else if (v2 & 0x400) {
					a1a.field_0 = 1.0;
					a1a.field_4 = 1.0;
				} else if (v2 & 0x800) {
					a1a.field_0 = -1.0;
					a1a.field_4 = 1.0;
				} else {
					a1a.field_0 = *(float*)(a2 + 56) - *(float*)(a1 + 56);
					a1a.field_4 = *(float*)(a2 + 60) - *(float*)(a1 + 60);
				}
				nox_xxx_utilNormalizeVector_509F20(&a1a);
				v3 = sub_4EE2A0(a1) + 4.0 + 15.0;
				a3[0].field_0 = v3 * a1a.field_0 + *(float*)(a1 + 56);
				a3[0].field_4 = v3 * a1a.field_4 + *(float*)(a1 + 60);
				v4 = -a1a.field_4;
				v29 = -v4;
				v30 = -a1a.field_0;
				a3[1].field_0 = v4 * 30.0 + a3[0].field_0;
				a3[1].field_4 = a1a.field_0 * 30.0 + a3[0].field_4;
				a3[2].field_0 = v29 * 30.0 + a3[0].field_0;
				a3[2].field_4 = v30 * 30.0 + a3[0].field_4;
				v5 = a3[0].field_0 - *(float*)(a2 + 56);
				v6 = a3[0].field_4 - *(float*)(a2 + 60);
				v27 = v6 * v6 + v5 * v5;
				v7 = a3[1].field_0 - *(float*)(a2 + 56);
				v8 = a3[1].field_4 - *(float*)(a2 + 60);
				v9 = v8 * v8 + v7 * v7;
				v10 = a3[2].field_0 - *(float*)(a2 + 56);
				v11 = a3[2].field_4 - *(float*)(a2 + 60);
				v28 = v11 * v11 + v10 * v10;
				if (v27 >= v9) {
					v13 = a3[1].field_4;
					v12 = a3[1].field_0;
				} else {
					v12 = a3[0].field_0;
					v13 = a3[0].field_4;
					a3[0].field_0 = a3[1].field_0;
					a3[1].field_0 = v12;
					a3[0].field_4 = a3[1].field_4;
					v14 = v27;
					v27 = v9;
					a3[1].field_4 = v13;
					v9 = v14;
				}
				if (v9 < v28) {
					v15 = v12;
					v12 = a3[2].field_0;
					v16 = v13;
					v13 = a3[2].field_4;
					v9 = v28;
					a3[1].field_0 = a3[2].field_0;
					a3[1].field_4 = a3[2].field_4;
					a3[2].field_0 = v15;
					a3[2].field_4 = v16;
				}
				if (v27 < v9) {
					v17 = a3[0].field_0;
					v18 = a3[0].field_4;
					a3[0].field_0 = v12;
					a3[0].field_4 = v13;
					a3[1].field_0 = v17;
					a3[1].field_4 = v18;
				}
				v19 = *(float*)(a1 + 56);
				v34.field_4 = *(float*)(a1 + 60);
				v34.field_0 = v19;
				v34.field_8 = a3[2].field_0;
				v34.field_C = a3[2].field_4;
				if (!nox_xxx_mapTraceRay_535250(&v34, 0, 0, 1)) {
					v20 = *(float*)(a2 + 60);
					a3[2].field_0 = *(float*)(a2 + 56);
					a3[2].field_4 = v20;
				}
				v34.field_8 = a3[1].field_0;
				v34.field_C = a3[1].field_4;
				if (!nox_xxx_mapTraceRay_535250(&v34, 0, 0, 1)) {
					v21 = *(float*)(a2 + 60);
					a3[1].field_0 = *(float*)(a2 + 56);
					a3[1].field_4 = v21;
				}
				v34.field_8 = a3[0].field_0;
				v34.field_C = a3[0].field_4;
				if (!nox_xxx_mapTraceRay_535250(&v34, 0, 0, 1)) {
					v22 = *(float*)(a2 + 60);
					a3[0].field_0 = *(float*)(a2 + 56);
					a3[0].field_4 = v22;
				}
				if (v31 == 1) {
					v23 = nox_xxx_inventoryGetFirst_4E7980(a1);
					v24 = (uint32_t*)v23;
					if (*(char*)(v23 + 488) != -1 && !(*(uint8_t*)(v23 + 8) & 2)) {
						*(uint32_t*)(v23 + 16) |= 0x40u;
						nox_xxx_unit_511810(v23);
						nox_xxx_drop_4ED790(a1, v24, a3);
					}
				} else {
					v25 = nox_xxx_inventoryGetFirst_4E7980(a1);
					v26 = 0;
					if (v25) {
						do {
							v32 = nox_xxx_inventoryGetNext_4E7990(v25);
							if (*(char*)(v25 + 488) != -1 && !(*(uint8_t*)(v25 + 8) & 2)) {
								*(uint32_t*)(v25 + 16) |= 0x40u;
								nox_xxx_unit_511810(v25);
								nox_xxx_drop_4ED790(a1, (uint32_t*)v25, &a3[v26++]);
								if (v26 >= 3) {
									v26 = 0;
								}
							}
							v25 = v32;
						} while (v32);
					}
				}
			}
		}
	}
}

//----- (004EE2A0) --------------------------------------------------------
double sub_4EE2A0(int a1) {
	int v1; // eax

	v1 = *(uint32_t*)(a1 + 172);
	if (v1 == 2) {
		return *(float*)(a1 + 176);
	}
	if (v1 != 3) {
		return 0.0;
	}
	if (*(float*)(a1 + 184) <= (double)*(float*)(a1 + 188)) {
		return *(float*)(a1 + 188) * 0.5;
	}
	return *(float*)(a1 + 184) * 0.5;
}

//----- (004EE2F0) --------------------------------------------------------
int sub_4EE2F0(int a1, int a2, int* a3) {
	int v3;            // edi
	short v4;          // ax
	unsigned char* v5; // ecx

	if (!a1 || !a2 || !a3) {
		return 0;
	}
	v3 = nox_xxx_dropDefault_4ED290(a1, a2, (float2*)a3);
	if (v3) {
		v4 = *getMemU16Ptr(0x973F18, 15752);
		v5 = getMemAt(0x973F18, 15752);
		if (*getMemI16Ptr(0x973F18, 15752) != -1) {
			while (v4 != *(uint16_t*)(a2 + 4)) {
				v4 = *((uint16_t*)v5 + 2);
				v5 += 4;
				if (v4 == -1) {
					return v3;
				}
			}
			nox_xxx_aud_501960(*((unsigned short*)v5 + 1), a1, 0, 0);
		}
	}
	return v3;
}

//----- (004EE370) --------------------------------------------------------
int nox_xxx_dropAnkhTradable_4EE370(int a1, int a2, int* a3) { return nox_xxx_dropDefault_4ED290(a1, a2, (float2*)a3); }

//----- (004EE390) --------------------------------------------------------
int nox_xxx_unused_4EE390(int a1) {
	int result; // eax
	int v2;     // ecx

	result = a1;
	if (a1) {
		v2 = *(uint32_t*)(a1 + 556);
		if (v2) {
			*(uint32_t*)(v2 + 12) = 0;
			result = *(uint32_t*)(a1 + 556);
			*(uint32_t*)(result + 8) = 0;
		} else {
			*(uint32_t*)0xC = 0;
			*(uint32_t*)(*(uint32_t*)(a1 + 556) + 8) = dword_5d4594_1568260;
			if (dword_5d4594_1568260) {
				*(uint32_t*)(dword_5d4594_1568260 + 448) = a1;
			}
			dword_5d4594_1568260 = a1;
		}
	}
	return result;
}

//----- (004EE3E0) --------------------------------------------------------
void nox_xxx_unused_4EE3E0(int a1) {
	int v1; // eax
	int v2; // ecx
	int v3; // eax
	int v4; // ecx

	if (a1) {
		v1 = *(uint32_t*)(a1 + 556);
		if (v1) {
			v2 = *(uint32_t*)(v1 + 8);
			if (v2) {
				*(uint32_t*)(*(uint32_t*)(v2 + 556) + 12) = *(uint32_t*)(v1 + 12);
			}
			v3 = *(uint32_t*)(a1 + 556);
			v4 = *(uint32_t*)(v3 + 12);
			if (v4) {
				*(uint32_t*)(*(uint32_t*)(v4 + 556) + 8) = *(uint32_t*)(v3 + 8);
			} else {
				dword_5d4594_1568260 = *(uint32_t*)(v3 + 8);
			}
		}
	}
}

//----- (004EE430) --------------------------------------------------------
int sub_4EE430() { return dword_5d4594_1568260; }

//----- (004EE440) --------------------------------------------------------
int sub_4EE440(int a1) {
	int result; // eax

	if (a1) {
		result = *(uint32_t*)(*(uint32_t*)(a1 + 556) + 8);
	} else {
		result = 0;
	}
	return result;
}

//----- (004EE460) --------------------------------------------------------
void nox_xxx_unitAdjustHP_4EE460(nox_object_t* unitp, int dv) {
	int unit = unitp;
	if (nox_common_gameFlags_check_40A5C0(0x4000000)) {
		return;
	}
	unsigned short* v2 = *(unsigned short**)(unit + 556);
	if (!v2) {
		return;
	}
	unsigned short max = v2[2];
	if (*v2 < max) {
		int set = *v2 + dv;
		unsigned short val = set;
		if (set > max) {
			val = max;
		}
		nox_xxx_unitSetHP_4E4560(unit, val);
		if (*(uint8_t*)(unit + 8) & 2) {
			nox_xxx_mobInformOwnerHP_4EE4C0(unit);
		}
	}
}

//----- (004EE4C0) --------------------------------------------------------
void nox_xxx_mobInformOwnerHP_4EE4C0(nox_object_t* obj) {
	uint32_t* a1 = obj;
	int v1; // eax

	if (a1) {
		v1 = a1[127];
		if (v1) {
			if (*(uint8_t*)(v1 + 8) & 4) {
				nox_xxx_netReportUnitCurrentHP_4D8620(
					*(unsigned char*)(*(uint32_t*)(*(uint32_t*)(v1 + 748) + 276) + 2064), a1);
			}
		}
	}
}

//----- (004EE5E0) --------------------------------------------------------
void nox_xxx_unitDamageClear_4EE5E0(nox_object_t* unitp, int damageAmount) {
	int unit = unitp;
	int healthData;              // eax
	int v3;                      // eax
	int v4;                      // eax
	void (*deleteOverride)(int); // eax

	if (unit) {
		healthData = *(uint32_t*)(unit + 556);
		if (healthData) {
			if (*(uint16_t*)(healthData + 4) &&
				(!nox_common_getEngineFlag(NOX_ENGINE_FLAG_GODMODE) || !(*(uint8_t*)(unit + 8) & 4))) {
				if (*(uint8_t*)(unit + 8) & 4) {
					v3 = *(uint32_t*)(unit + 748);
					if (v3) {
						if (!*(uint8_t*)(*(uint32_t*)(v3 + 276) + 2251) && *(uint32_t*)(v3 + 132)) {
							nox_xxx_harpoonBreakForPlr_537520((uint32_t*)unit);
						}
					}
				}
				// Checks if health is higher than the amount of damage
				if (**(unsigned short**)(unit + 556) > damageAmount) {
					nox_xxx_unitSetHP_4E4560(unit, **(uint16_t**)(unit + 556) - damageAmount);
				} else {
					nox_xxx_unitSetHP_4E4560(unit, 0);
					v4 = *(uint32_t*)(unit + 16);
					if ((v4 & 0x8000) == 0) {
						BYTE1(v4) |= 0x80u;
						*(uint32_t*)(unit + 16) = v4;
						nox_xxx_spellBuffOff_4FF5B0(unit, 16);
						if (!nox_xxx_unitIsZombie_534A40(unit)) {
							nox_xxx_soloMonsterKillReward_4EE500_obj_health(unit);
						}
						if (*(uint8_t*)(unit + 8) & 2) {
							nox_xxx_monsterCallDieFn_50A3D0((uint32_t*)unit);
						} else {
							deleteOverride = *(void (**)(int))(unit + 724);
							if (deleteOverride) {
								deleteOverride(unit);
							} else {
								nox_xxx_delayedDeleteObject_4E5CC0(unit);
							}
						}
					}
				}
				if (*(uint8_t*)(unit + 8) & 2) {
					nox_xxx_mobInformOwnerHP_4EE4C0((uint32_t*)unit);
				}
			}
		}
	}
}

//----- (004EE6F0) --------------------------------------------------------
void nox_xxx_unitHPsetOnMax_4EE6F0(int unit) {
	int v1; // eax

	if (unit) {
		v1 = *(uint32_t*)(unit + 556);
		if (v1) {
			nox_xxx_unitSetHP_4E4560(unit, *(uint16_t*)(v1 + 4));
			*(uint16_t*)(*(uint32_t*)(unit + 556) + 2) = **(uint16_t**)(unit + 556);
			if (*(uint8_t*)(unit + 8) & 2) {
				nox_xxx_mobInformOwnerHP_4EE4C0((uint32_t*)unit);
			}
		}
	}
}

//----- (004EE730) --------------------------------------------------------
void nox_xxx_playerHP_4EE730(int a1) {
	int v1; // esi
	int v2; // eax
	int v3; // edx

	if (a1) {
		if (*(uint8_t*)(a1 + 8) & 4) {
			v1 = *(uint32_t*)(a1 + 748);
			if (*(uint32_t*)(a1 + 556)) {
				v2 = v1 + 12;
				v3 = 32;
				do {
					v2 += 2;
					--v3;
					*(uint16_t*)(v2 - 2) = **(uint16_t**)(a1 + 556);
				} while (v3);
				*(uint16_t*)(v1 + 76) = **(uint16_t**)(a1 + 556);
			}
		}
	}
}

//----- (004EE780) --------------------------------------------------------
short nox_xxx_unitGetHP_4EE780(nox_object_t* item) {
	short* v1;    // eax
	short result; // ax

	if (item && (v1 = *(short**)&item->field_139) != 0) {
		result = *v1;
	} else {
		result = 0;
	}
	return result;
}

//----- (004EE7A0) --------------------------------------------------------
short nox_xxx_unitGetMaxHP_4EE7A0(int a1) {
	int v1;       // eax
	short result; // ax

	if (a1 && (v1 = *(uint32_t*)(a1 + 556)) != 0) {
		result = *(uint16_t*)(v1 + 4);
	} else {
		result = 0;
	}
	return result;
}

//----- (004EE7C0) --------------------------------------------------------
int nox_xxx_unitSetMaxHP_4EE7C0(int a1, short a2) {
	int result; // eax

	result = a1;
	if (a1) {
		result = *(uint32_t*)(a1 + 556);
		if (result) {
			*(uint16_t*)(result + 4) = a2;
		}
	}
	return result;
}

//----- (004EE7E0) --------------------------------------------------------
int nox_xxx_activatePoison_4EE7E0(int a1, int a2, int a3) {
	int v3;    // ebx
	int v5;    // eax
	int v6;    // eax
	int v7;    // edi
	int v8;    // edi
	int v9;    // esi
	float v10; // [esp+0h] [ebp-10h]

	v3 = *(unsigned char*)(a1 + 540);
	if (!a1) {
		return 0;
	}
	if (*(uint8_t*)(a1 + 16) & 2) {
		return 0;
	}
	if (nox_xxx_testUnitBuffs_4FF350(a1, 23)) {
		return 0;
	}
	v5 = *(uint32_t*)(a1 + 8);
	if (v5 & 4 && (*(uint8_t*)(*(uint32_t*)(*(uint32_t*)(a1 + 748) + 276) + 3680) & 1) == 1) {
		return 0;
	}
	if (v5 & 2) {
		v6 = *(uint32_t*)(a1 + 12);
		if (v6 & 0x200) {
			return 0;
		}
	}
	v10 = nox_xxx_getPoisonDmg_4E0040((uint32_t*)a1) * 100.0;
	v7 = nox_float2int(v10);
	if (nox_common_randomInt_415FA0(0, 100) < v7) {
		nox_xxx_netPriMsgToPlayer_4DA2C0(a1, "Health.c:ResistPoison", 0);
		return 0;
	}
	v8 = v3 + a2;
	if (v3 + a2 <= a3) {
		goto LABEL_19;
	}
	if (v3 <= a3) {
		v8 = a3;
	LABEL_19:
		if (v8 != v3) {
			nox_xxx_setSomePoisonData_4EEA90(a1, v8);
			nox_xxx_aud_501960(100, a1, 0, 0);
		}
		goto LABEL_21;
	}
	v8 = v3;
LABEL_21:
	if (!v3 && v8 > 0) {
		v9 = *(uint32_t*)(a1 + 556);
		if (v9) {
			*(uint32_t*)(v9 + 16) = nox_frame_xxx_2598000;
		}
	}
	return 1;
}

//----- (004EE8F0) --------------------------------------------------------
void nox_xxx_updatePoison_4EE8F0(int a1, int a2) {
	int v2;   // eax
	int v3;   // eax
	char* v4; // eax
	int v5;   // eax
	int v6;   // eax

	if (a1) {
		if (*(unsigned char*)(a1 + 540) > a2) {
			*(uint8_t*)(a1 + 540) -= a2;
		} else {
			v2 = *(uint32_t*)(a1 + 556);
			*(uint8_t*)(a1 + 540) = 0;
			if (v2) {
				*(uint32_t*)(v2 + 16) = 0;
			}
			v3 = *(uint32_t*)(a1 + 8);
			if (v3 & 4) {
				nox_xxx_playerUnsetStatus_417530(*(uint32_t*)(*(uint32_t*)(a1 + 748) + 276), 1024);
				nox_xxx_netPriMsgToPlayer_4DA2C0(a1, "Health.c:PoisonFade", 0);
			} else if (v3 & 2) {
				if (nox_common_gameFlags_check_40A5C0(2048) && *(uint8_t*)(a1 + 12) & 0x10) {
					v4 = nox_common_playerInfoFromNum_417090(31);
					if (v4) {
						v5 = *((uint32_t*)v4 + 514);
						if (v5) {
							nox_xxx_netReportObjectPoison_4D7F40(v5, (uint32_t*)a1, 0);
						}
					}
				} else if (*(uint8_t*)(a1 + 12) & 0x80) {
					v6 = *(uint32_t*)(a1 + 508);
					if (v6) {
						nox_xxx_netReportObjectPoison_4D7F40(v6, (uint32_t*)a1, 0);
					}
				}
			}
		}
	}
}

//----- (004EE9D0) --------------------------------------------------------
void nox_xxx_removePoison_4EE9D0(int a1) {
	int v1;   // eax
	int v2;   // eax
	char* v3; // eax
	int v4;   // eax
	int v5;   // eax

	if (a1 && *(uint8_t*)(a1 + 540)) {
		v1 = *(uint32_t*)(a1 + 556);
		*(uint8_t*)(a1 + 540) = 0;
		if (v1) {
			*(uint32_t*)(v1 + 16) = 0;
		}
		v2 = *(uint32_t*)(a1 + 8);
		if (v2 & 4) {
			nox_xxx_playerUnsetStatus_417530(*(uint32_t*)(*(uint32_t*)(a1 + 748) + 276), 1024);
		} else if (v2 & 2) {
			if (nox_common_gameFlags_check_40A5C0(2048) && *(uint8_t*)(a1 + 12) & 0x10) {
				v3 = nox_common_playerInfoFromNum_417090(31);
				if (v3) {
					v4 = *((uint32_t*)v3 + 514);
					if (v4) {
						nox_xxx_netReportObjectPoison_4D7F40(v4, (uint32_t*)a1, 0);
					}
				}
			} else if (*(uint8_t*)(a1 + 12) & 0x80) {
				v5 = *(uint32_t*)(a1 + 508);
				if (v5) {
					nox_xxx_netReportObjectPoison_4D7F40(v5, (uint32_t*)a1, 0);
				}
			}
		}
	}
}

//----- (004EEA90) --------------------------------------------------------
void nox_xxx_setSomePoisonData_4EEA90(int a1, int a2) {
	int v2;   // eax
	int v3;   // eax
	int v4;   // eax
	char* v5; // eax
	int v6;   // eax

	if (a1) {
		if (!*(uint8_t*)(a1 + 540) && a2 > 0) {
			v2 = *(uint32_t*)(a1 + 556);
			if (v2) {
				*(uint32_t*)(v2 + 16) = nox_frame_xxx_2598000;
			}
		}
		v3 = *(uint32_t*)(a1 + 8);
		*(uint8_t*)(a1 + 540) = a2;
		if (v3 & 4) {
			v4 = *(uint32_t*)(a1 + 748);
			if (a2 != 0) {
				nox_xxx_netNeedTimestampStatus_4174F0(*(uint32_t*)(v4 + 276), 1024);
			} else {
				nox_xxx_playerUnsetStatus_417530(*(uint32_t*)(v4 + 276), 1024);
			}
		} else if (v3 & 2) {
			if (nox_common_gameFlags_check_40A5C0(2048) && *(uint8_t*)(a1 + 12) & 0x10) {
				v5 = nox_common_playerInfoFromNum_417090(31);
				if (!v5) {
					goto LABEL_19;
				}
				v6 = *((uint32_t*)v5 + 514);
				if (!v6) {
					goto LABEL_19;
				}
			} else {
				if ((signed char)*(uint8_t*)(a1 + 12) >= 0) {
					goto LABEL_19;
				}
				v6 = *(uint32_t*)(a1 + 508);
				if (!v6) {
					goto LABEL_19;
				}
			}
			nox_xxx_netReportObjectPoison_4D7F40(v6, (uint32_t*)a1, a2 != 0);
		}
	LABEL_19:
		if (a2) {
			*(uint16_t*)(a1 + 542) = 1000;
		} else {
			*(uint16_t*)(a1 + 542) = 0;
		}
	}
}

//----- (004EEB80) --------------------------------------------------------
unsigned short nox_xxx_playerManaAdd_4EEB80(nox_object_t* unitp, short amount) {
	int unit = unitp;
	unsigned short result;    // ax
	int manaData;             // esi
	short currentMana;        // ax
	unsigned short maxMana;   // cx
	unsigned short newAmount; // ax

	result = unit;
	if (unit && *(uint8_t*)(unit + 8) & 4) { // is player
		manaData = *(uint32_t*)(unit + 748);
		currentMana = *(uint16_t*)(manaData + 4);
		maxMana = *(uint16_t*)(manaData + 8);

		// Previous mana amount?
		*(uint16_t*)(manaData + 6) = currentMana;

		newAmount = amount + currentMana;
		*(uint16_t*)(manaData + 4) = newAmount;

		if (newAmount > maxMana) {
			*(uint16_t*)(manaData + 4) = maxMana;
		}

		nox_xxx_protectMana_56F9E0(*(uint32_t*)(*(uint32_t*)(manaData + 276) + 4596), amount);
		result = *(uint16_t*)(manaData + 8);

		if (*(uint16_t*)(manaData + 4) > result) {
			result = (unsigned int)nox_xxx_protectPlayerHPMana_56F870(*(uint32_t*)(*(uint32_t*)(manaData + 276) + 4596),
																	  result);
		}
	}
	return result;
}

//----- (004EEBF0) --------------------------------------------------------
uint32_t* nox_xxx_playerManaSub_4EEBF0(int unit, int amount) {
	uint32_t* result;           // eax
	unsigned short currentMana; // cx

	result = (uint32_t*)unit;
	if (unit) {
		if (*(uint8_t*)(unit + 8) & 4) { // is player
			result = *(uint32_t**)(unit + 748);
			if (!nox_common_getEngineFlag(NOX_ENGINE_FLAG_GODMODE)) {
				currentMana = *((uint16_t*)result + 2);
				*((uint16_t*)result + 3) = currentMana;

				if (currentMana > amount) {
					*((uint16_t*)result + 2) = currentMana - amount;
				} else {
					*((uint16_t*)result + 2) = 0;
				}

				if (*((unsigned short*)result + 2) > amount) {
					result = nox_xxx_protectMana_56F9E0(*(uint32_t*)(result[69] + 4596), -(short)amount);
				} else {
					result = nox_xxx_protectMana_56F9E0(*(uint32_t*)(result[69] + 4596), -*((uint16_t*)result + 2));
				}
			}
		}
	}
	return result;
}

//----- (004EEC80) --------------------------------------------------------
short nox_xxx_unitGetOldMana_4EEC80(int unit) {
	int flags;    // eax
	short result; // ax

	if (!unit) {
		goto LABEL_9;
	}
	flags = *(uint32_t*)(unit + 8);
	if (flags & 4) { // is player
		return *(uint16_t*)(*(uint32_t*)(unit + 748) + 4);
	}
	if (flags & 2) { // owned monster
		result = 1000;
	} else {
	LABEL_9:
		result = 0;
	}
	return result;
}

//----- (004EECB0) --------------------------------------------------------
short nox_xxx_playerGetMaxMana_4EECB0(int unit) {
	short result; // ax

	if (unit && *(uint8_t*)(unit + 8) & 4) { // is player
		result = *(uint16_t*)(*(uint32_t*)(unit + 748) + 8);
	} else {
		result = 0;
	}
	return result;
}

//----- (004EECD0) --------------------------------------------------------
int nox_xxx_playerSetMaxMana_4EECD0(int unit, short amount) {
	int result; // eax

	result = unit;
	if (unit) {
		if (*(uint8_t*)(unit + 8) & 4) { // is player
			result = *(uint32_t*)(unit + 748);
			*(uint16_t*)(result + 8) = amount;
		}
	}
	return result;
}

//----- (004EECF0) --------------------------------------------------------
uint32_t* nox_xxx_playerManaRefresh_4EECF0(int unit) {
	uint32_t* result; // eax
	int manaData;     // eax
	int v3;           // edx
	short v4;         // cx

	result = (uint32_t*)unit;
	if (unit) {
		if (*(uint8_t*)(unit + 8) & 4) { // Is player ?
			manaData = *(uint32_t*)(unit + 748);
			v3 = *(uint32_t*)(manaData + 276);
			*(uint16_t*)(manaData + 6) = *(uint16_t*)(manaData + 4);
			v4 = *(uint16_t*)(manaData + 8);
			*(uint16_t*)(manaData + 4) = v4;
			result = nox_xxx_protectMana_56F9E0(*(uint32_t*)(v3 + 4596), v4);
		}
	}
	return result;
}

//----- (004EED40) --------------------------------------------------------
void nox_xxx_abilGivePlayerAll_4EED40(int a1, char a2, int a3) {
	int* v3;      // esi
	uint32_t* v4; // edi
	int v5;       // ebx

	if (a1 && a2 > 0) {
		v3 = getMemIntPtr(0x587000, 206108);
		v4 = (uint32_t*)(*(uint32_t*)(*(uint32_t*)(a1 + 748) + 276) + 3696);
		v5 = a2;
		do {
			if (*v3) {
				if (nox_common_gameFlags_check_40A5C0(4096) || nox_xxx_isQuest_4D6F50() || sub_4D6F70()) {
					*v4 = 0;
				} else {
					nox_xxx_abilityRewardServ_4FB9C0_ability(a1, *v3, a3);
				}
			}
			++v3;
			++v4;
			--v5;
		} while (v5);
	}
}

//----- (004EEDC0) --------------------------------------------------------
int nox_xxx_plrReadVals_4EEDC0(int a1, int a2) {
	int v2;     // ebx
	int v3;     // edi
	int v4;     // esi
	float* v5;  // ebp
	short v6;   // ax
	char v7;    // al
	double v8;  // st7
	short v9;   // ax
	double v10; // st7
	int i;      // eax
	int v12;    // edx
	int v13;    // eax
	size_t v14; // eax
	int result; // eax
	float v16;  // [esp-1Ch] [ebp-40h]
	float v17;  // [esp+0h] [ebp-24h]
	float v18;  // [esp+0h] [ebp-24h]
	float v19;  // [esp+0h] [ebp-24h]
	float v20;  // [esp+0h] [ebp-24h]
	int v21;    // [esp+0h] [ebp-24h]
	float v22;  // [esp+14h] [ebp-10h]
	int v23;    // [esp+18h] [ebp-Ch]
	char v24;   // [esp+1Ch] [ebp-8h]
	float* v25; // [esp+20h] [ebp-4h]
	float* v26; // [esp+28h] [ebp+4h]

	v2 = a1;
	v3 = *(uint32_t*)(a1 + 748);
	v23 = 0;
	v4 = *(uint32_t*)(v3 + 276);
	v26 = sub_57B350();
	v5 = nox_xxx_plrGetMaxVarsPtr_57B360(*(unsigned char*)(v4 + 2251));
	v25 = nox_xxx_plrGetMaxVarsPtr_57B360(0);
	if (nox_common_gameFlags_check_40A5C0(0x2000)) {
		*(uint16_t*)(*(uint32_t*)(v2 + 556) + 4) = nox_float2int(*v5);
		v6 = nox_float2int16_abs(*v5);
		nox_xxx_unitSetHP_4E4560(v2, v6);
		*(uint16_t*)(v3 + 8) = nox_float2int(v5[1]);
		*(uint16_t*)(v3 + 4) = nox_float2int(v5[1]);
		*(uint32_t*)(v4 + 2239) = nox_float2int(v5[3]);
		v16 = v5[2];
		*(float*)(v2 + 548) = v5[2] * 0.000099999997;
		*(uint32_t*)(v4 + 2235) = nox_float2int(v16);
		if (!*(uint8_t*)(v4 + 2251) && !nox_common_gameFlags_check_40A5C0(4096) && !sub_4D6F30()) {
			nox_xxx_abilGivePlayerAll_4EED40(v2, 10, 0);
		}
	} else {
		v7 = *(uint8_t*)(v4 + 3684);
		if (v7 > NOX_PLAYER_MAX_LEVEL) {
			v7 = NOX_PLAYER_MAX_LEVEL;
		}
		v24 = v7;
		v22 = (double)(v7 - 1);
		v17 = (*v5 - *v26) * v22 / ((double)NOX_PLAYER_MAX_LEVEL - 1) + *v26 + 0.5;
		*(uint16_t*)(*(uint32_t*)(v2 + 556) + 4) = nox_float2int(v17);
		nox_xxx_unitSetHP_4E4560(v2, *(uint16_t*)(*(uint32_t*)(v2 + 556) + 4));
		v8 = (v5[1] - v26[1]) * v22 / ((double)NOX_PLAYER_MAX_LEVEL - 1) + v26[1];
		if (v8 > v5[1]) {
			v8 = v5[1];
		}
		v18 = v8 + 0.5;
		v9 = nox_float2int(v18);
		*(uint16_t*)(v3 + 8) = v9;
		*(uint16_t*)(v3 + 4) = v9;
		v19 = (v5[3] - v26[3]) * v22 / ((double)NOX_PLAYER_MAX_LEVEL - 1) + v26[3] + 0.5;
		*(uint32_t*)(v4 + 2239) = nox_float2int(v19);
		v10 = (v5[2] - v26[2]) * v22 / ((double)NOX_PLAYER_MAX_LEVEL - 1) + v26[2];
		*(float*)(v2 + 548) = v10 * 0.000099999997;
		v20 = v10 + 0.5;
		*(uint32_t*)(v4 + 2235) = nox_float2int(v20);
		if (!*(uint8_t*)(v4 + 2251)) {
			nox_xxx_abilGivePlayerAll_4EED40(v2, v24, a2);
		}
	}
	*(float*)(v2 + 120) = (double)*(int*)(v4 + 2239) / v25[3] * 20.0 + 10.0;
	*(uint16_t*)(*(uint32_t*)(v3 + 276) + 3652) =
		(long long)(((double)*(int*)(v4 + 2239) / v25[3] * 1250.0 + 750.0) * *getMemDoublePtr(0x581450, 10216));
	*(uint16_t*)(v2 + 490) = *(uint16_t*)(*(uint32_t*)(v3 + 276) + 3652);
	sub_56F780(*(uint32_t*)(*(uint32_t*)(v3 + 276) + 4624), *(uint32_t*)(v4 + 2239));
	sub_56F780(*(uint32_t*)(*(uint32_t*)(v3 + 276) + 4620), *(uint32_t*)(v4 + 2235));
	nox_xxx_protectPlayerHPMana_56F870(*(uint32_t*)(*(uint32_t*)(v3 + 276) + 4600), *(uint16_t*)(v3 + 8));
	nox_xxx_protectPlayerHPMana_56F870(*(uint32_t*)(*(uint32_t*)(v3 + 276) + 4592),
									   *(uint16_t*)(*(uint32_t*)(v2 + 556) + 4));
	for (i = *(uint32_t*)(v2 + 504); i; v23 += v12) {
		v12 = *(unsigned char*)(i + 488);
		i = *(uint32_t*)(i + 496);
	}
	*(uint32_t*)(v4 + 3656) = v23 > *(unsigned short*)(v2 + 490);
	v13 = *(uint32_t*)(v3 + 276);
	v21 = *(uint32_t*)(v13 + 4628);
	v14 = nox_wcslen((const wchar_t*)(v13 + 2185));
	result = sub_56FB00((int*)(*(uint32_t*)(v3 + 276) + 2185), 2 * v14, v21);
	*(uint8_t*)(v4 + 2184) = 1;
	return result;
}

//----- (004EF140) --------------------------------------------------------
int sub_4EF140(int a1) {
	int v1;     // edi
	int v2;     // ecx
	int result; // eax
	int i;      // ebx
	int v5;     // [esp-Ch] [ebp-14h]

	v1 = *(uint32_t*)(*(uint32_t*)(a1 + 748) + 276);
	if (nox_common_gameFlags_check_40A5C0(0x2000)) {
		v2 = *(uint32_t*)(v1 + 4644);
		*(uint8_t*)(v1 + 3684) = NOX_PLAYER_MAX_LEVEL;
		sub_56F820(v2, 0xAu);
		result = nox_xxx_plrReadVals_4EEDC0(a1, 0);
	} else {
		for (i = 0; i <= NOX_PLAYER_MAX_LEVEL; ++i) {
			if (nox_xxx_gamedataGetFloatTable_419D70("XPTable", i) > *(float*)(a1 + 28)) {
				break;
			}
		}
		v5 = *(uint32_t*)(v1 + 4644);
		*(uint8_t*)(v1 + 3684) = i - 1;
		sub_56F820(v5, i - 1);
		result = nox_xxx_plrReadVals_4EEDC0(a1, 0);
	}
	return result;
}

//----- (004EF1E0) --------------------------------------------------------
double nox_xxx_calcBoltDamage_4EF1E0(int a1, int a2) {
	double result; // st7

	if (!*getMemU32Ptr(0x5D4594, 1568264)) {
		*getMemU32Ptr(0x5D4594, 1568264) = nox_xxx_getNameId_4E3AA0("ArcherBolt");
	}
	if (!nox_common_gameFlags_check_40A5C0(2048) || *(uint32_t*)(a2 + 4) != *getMemU32Ptr(0x5D4594, 1568264)) {
		result = (double)(a1 - *(unsigned short*)(a2 + 60)) * *(float*)(a2 + 64) + (double)*(unsigned short*)(a2 + 72);
	} else {
		result = nox_xxx_gamedataGetFloat_419D40("BoltSoloDamageMin") +
				 (double)(a1 - *(unsigned short*)(a2 + 60)) * *(float*)(a2 + 64);
	}
	return result;
}

//----- (004EF410) --------------------------------------------------------
void sub_4EF410(int a1, unsigned char a2) {
	signed char v2; // bl
	int v3;         // esi
	int v4;         // edi
	uint32_t* v5;   // esi
	int v6;         // [esp-10h] [ebp-24h]
	float v7;       // [esp+0h] [ebp-14h]

	v2 = a2;
	v3 = *(uint32_t*)(*(uint32_t*)(a1 + 748) + 276);
	if ((char)a2 > NOX_PLAYER_MAX_LEVEL) {
		v2 = NOX_PLAYER_MAX_LEVEL;
		a2 = NOX_PLAYER_MAX_LEVEL;
	}
	*(float*)(a1 + 28) = nox_xxx_gamedataGetFloatTable_419D70("XPTable", v2);
	v7 = nox_xxx_gamedataGetFloatTable_419D70("XPTable", v2);
	sub_56F8C0(*(uint32_t*)(v3 + 4604), v7);
	sub_4D81A0(a1);
	v6 = *(uint32_t*)(v3 + 4644);
	*(uint8_t*)(v3 + 3684) = v2;
	sub_56F820(v6, a2);
	nox_xxx_plrReadVals_4EEDC0(a1, 0);
	if (nox_common_gameFlags_check_40A5C0(2048) && !*(uint8_t*)(v3 + 2251)) {
		v4 = 1;
		v5 = (uint32_t*)(v3 + 3700);
		do {
			if (*v5) {
				nox_xxx_book_45DBE0((void*)3, v4, v4 - 1);
			}
			++v4;
			++v5;
		} while (v4 < 6);
	}
	if (nox_common_gameFlags_check_40A5C0(2048)) {
		sub_57AF30(a1, 0);
	}
}

#ifndef NOX_CGO
//----- (004EF500) --------------------------------------------------------
void nox_xxx_set_god_4EF500(int a1) {
	if (nox_common_gameFlags_check_40A5C0(2048)) {
		if (a1 == 1) {
			nox_common_setEngineFlag(NOX_ENGINE_FLAG_ADMIN | NOX_ENGINE_FLAG_GODMODE);
		} else {
			nox_common_resetEngineFlag(NOX_ENGINE_FLAG_ADMIN | NOX_ENGINE_FLAG_GODMODE);
		}
		char* result = nox_common_playerInfoGetFirst_416EA0();
		for (int i = (int)result; result; i = (int)result) {
			nox_xxx_spellAwardAll1_4EFD80(i);
			nox_xxx_spellAwardAll2_4EFC80(i);
			nox_xxx_spellAwardAll3_4EFE10(i);
			result = nox_common_playerInfoGetNext_416EE0(i);
		}
	}
}
#endif // NOX_CGO

//----- (004EF580) --------------------------------------------------------
char nox_xxx_getRespawnWeaponFlags_4EF580() {
	char v0; // bl
	int v1;  // eax
	int v2;  // eax
	int v3;  // eax
	int v4;  // eax
	int v5;  // eax
	int v6;  // eax
	int v7;  // eax
	int v8;  // eax

	v0 = 0;
	v1 = sub_415CD0((char*)0x400);
	if (nox_xxx_getUnitDefDd10_4E3BA0(v1)) {
		v0 = 1;
	}
	v2 = sub_415CD0((char*)4);
	if (nox_xxx_getUnitDefDd10_4E3BA0(v2)) {
		v0 |= 2u;
	}
	v3 = sub_415CD0((char*)1);
	if (nox_xxx_getUnitDefDd10_4E3BA0(v3)) {
		v0 |= 4u;
	}
	v4 = sub_415840((char*)0x8000);
	if (nox_xxx_getUnitDefDd10_4E3BA0(v4)) {
		v0 |= 8u;
	}
	v5 = sub_415CD0((char*)0x4000);
	if (nox_xxx_getUnitDefDd10_4E3BA0(v5)) {
		v0 |= 0x10u;
	}
	v6 = sub_415840((char*)0x100);
	if (nox_xxx_getUnitDefDd10_4E3BA0(v6)) {
		v0 |= 0x20u;
	}
	v7 = sub_415840((char*)0x200);
	if (nox_xxx_getUnitDefDd10_4E3BA0(v7)) {
		v0 |= 0x40u;
	}
	v8 = sub_415CD0((char*)0x1000000);
	if (nox_xxx_getUnitDefDd10_4E3BA0(v8)) {
		v0 |= 0x80u;
	}
	return v0;
}

//----- (004EF6F0) --------------------------------------------------------
int sub_4EF6F0(int a1) {
	int v1; // esi
	int i;  // eax

	if (!*getMemU32Ptr(0x5D4594, 1568268)) {
		*getMemU32Ptr(0x5D4594, 1568268) = nox_xxx_getNameId_4E3AA0("Glyph");
	}
	v1 = 0;
	for (i = nox_xxx_inventoryGetFirst_4E7980(a1); i; i = nox_xxx_inventoryGetNext_4E7990(i)) {
		if (*(unsigned short*)(i + 4) == *getMemU32Ptr(0x5D4594, 1568268)) {
			++v1;
		}
	}
	return v1;
}

//----- (004EF750) --------------------------------------------------------
uint32_t* nox_xxx_playerRespawnItem_4EF750(int a1, char* a2, int* a3, int a4, int a5) {
	uint32_t* v5;                    // eax
	uint32_t* v6;                    // esi
	void (*v7)(uint32_t*, uint32_t); // eax
	int v8;                          // eax

	v5 = nox_xxx_newObjectByTypeID_4E3810(a2);
	v6 = v5;
	if (v5) {
		v7 = (void (*)(uint32_t*, uint32_t))v5[172];
		if (v7) {
			v7(v6, 0);
		}
		if (a3) {
			nox_xxx_modifSetItemAttrs_4E4990((int)v6, a3);
		}
		nox_xxx_inventoryServPlace_4F36F0(a1, (int)v6, a4, a5);
		v8 = v6[2];
		v6[4] &= 0xFFF7FFFF;
		if (v8 & 0x3001000) {
			*(uint32_t*)(v6[187] + 4) |= 1u;
		}
	}
	return v6;
}

//----- (004EF7D0) --------------------------------------------------------
char nox_xxx_playerMakeDefItems_4EF7D0(int a1, int a2, int a3) {
	int v3;                // esi
	int v4;                // edi
	int v5;                // eax
	int v6;                // ecx
	int v7;                // eax
	uint32_t* v8;          // ebp
	int v9;                // eax
	int v10;               // eax
	int v11;               // ebp
	int v12;               // ecx
	int v13;               // eax
	int v14;               // eax
	int v15;               // eax
	int v16;               // edi
	unsigned char v18[20]; // [esp+10h] [ebp-14h]
	unsigned char* v19;    // [esp+28h] [ebp+4h]
	uint32_t* v20;         // [esp+2Ch] [ebp+8h]

	v3 = a1;
	v4 = *(uint32_t*)(a1 + 748);
	v19 = (unsigned char*)(*(uint32_t*)(v4 + 276) + 2185);
	if (a2) {
		nox_xxx_removePoison_4EE9D0(v3);
		nox_xxx_unitHPsetOnMax_4EE6F0(v3);
		nox_xxx_playerManaRefresh_4EECF0(v3);
	}
	nox_xxx_playerCancelAbils_4FC180(v3);
	sub_4D7E50(v3);
	*(uint32_t*)(v4 + 312) = 0;
	*(uint32_t*)(v4 + 316) = 0;
	*(uint8_t*)(v3 + 541) = 0;
	*(uint32_t*)(v4 + 84) = 0;
	*(uint16_t*)(v4 + 78) = 0;
	*(uint16_t*)(v4 + 76) = 0;
	v5 = v4 + 12;
	v6 = 32;
	do {
		v5 += 2;
		--v6;
		*(uint16_t*)(v5 - 2) = **(uint16_t**)(v3 + 556);
	} while (v6);
	*(uint32_t*)(v3 + 16) &= 0xFFEB3FE7;
	nox_xxx_playerSetState_4FA020((uint32_t*)v3, 13);
	nox_xxx_unitClearBuffs_4FF580(v3);
	*(uint8_t*)(v4 + 188) = 0;
	*(uint32_t*)(v4 + 216) = 0;
	*(uint32_t*)(v4 + 192) = 0;
	*(uint32_t*)(v4 + 196) = 0;
	*(uint32_t*)(v4 + 200) = 0;
	*(uint32_t*)(v4 + 204) = 0;
	*(uint32_t*)(v4 + 208) = 0;
	*(uint8_t*)(v4 + 212) = 0;
	*(uint32_t*)(v4 + 136) = 0;
	*(uint32_t*)(v4 + 132) = 0;
	*(uint32_t*)(v4 + 268) = 0;
	sub_4F7950(v3);
	*(uint32_t*)(v3 + 520) = 0;
	if (nox_common_gameFlags_check_40A5C0(0x2000)) {
		sub_4DE4D0(*(uint8_t*)(*(uint32_t*)(v4 + 276) + 2064));
	}
	v7 = *(uint32_t*)(v4 + 276);
	if (v7 && !*(uint32_t*)(v7 + 4700)) {
		nox_xxx_netReportTotalHealth_4D85C0(*(unsigned char*)(v7 + 2064), (uint32_t*)v3);
		nox_xxx_netReportTotalMana_4D88C0(*(unsigned char*)(*(uint32_t*)(v4 + 276) + 2064), v3);
		if (a3) {
			LOBYTE(v7) = nox_xxx_netSendPlayerRespawn_4EFC30(v3, 0);
		} else {
			v8 = *(uint32_t**)(v3 + 504);
			if (v8) {
				do {
					v20 = (uint32_t*)v8[124];
					if (sub_53E2D0((int)v8) || (v9 = v8[4], !(v9 & 0x100)) ||
						v8[2] & 0x2000000 && nox_xxx_unitArmorInventoryEquipFlags_415C70((int)v8) & 0x808) {
						nox_xxx_delayedDeleteObject_4E5CC0((int)v8);
					}
					v8 = v20;
				} while (v20);
			}
			nox_xxx_netSendPlayerRespawn_4EFC30(v3, 1);
			v10 = nox_xxx_modifGetIdByName_413290("UserColor1");
			v11 = nox_xxx_modifGetDescById_413330(v10);
			if (nox_common_gameFlags_check_40A5C0(2560) || *(uint8_t*)(*(uint32_t*)(v4 + 276) + 2251)) {
				v12 = **(uint32_t**)(v4 + 276);
				if (!(v12 & 0x400)) {
					*(uint32_t*)v18 = 0;
					*(uint32_t*)&v18[4] = nox_xxx_modifGetDescById_413330(*(uint32_t*)(v11 + 4) + v19[84]);
					*(uint32_t*)&v18[8] = nox_xxx_modifGetDescById_413330(*(uint32_t*)(v11 + 4) + v19[85]);
					*(uint32_t*)&v18[12] = 0;
					nox_xxx_playerRespawnItem_4EF750(v3, "StreetShirt", (int*)v18, 1, 0);
				}
			}
			if (!(**(uint8_t**)(v4 + 276) & 4)) {
				*(uint32_t*)v18 = 0;
				*(uint32_t*)&v18[4] = nox_xxx_modifGetDescById_413330(*(uint32_t*)(v11 + 4) + v19[83]);
				*(uint32_t*)&v18[8] = 0;
				*(uint32_t*)&v18[12] = 0;
				nox_xxx_playerRespawnItem_4EF750(v3, "StreetPants", (int*)v18, 1, 0);
			}
			if (!(**(uint8_t**)(v4 + 276) & 1)) {
				*(uint32_t*)v18 = nox_xxx_modifGetDescById_413330(*(uint32_t*)(v11 + 4) + v19[87]);
				*(uint32_t*)&v18[4] = nox_xxx_modifGetDescById_413330(*(uint32_t*)(v11 + 4) + v19[86]);
				*(uint32_t*)&v18[8] = 0;
				*(uint32_t*)&v18[12] = 0;
				nox_xxx_playerRespawnItem_4EF750(v3, "StreetSneakers", (int*)v18, 1, 0);
			}
			if (nox_common_gameFlags_check_40A5C0(2048)) {
				v13 = nox_xxx_modifGetIdByName_413290("ArmorQuality1");
				*(uint32_t*)v18 = nox_xxx_modifGetDescById_413330(v13);
				*(uint32_t*)&v18[8] = 0;
				*(uint32_t*)&v18[12] = 0;
				if (*(uint8_t*)(*(uint32_t*)(v4 + 276) + 2251)) {
					*(uint32_t*)&v18[4] = 0;
				} else {
					v14 = nox_xxx_modifGetIdByName_413290("Material1");
					*(uint32_t*)&v18[4] = nox_xxx_modifGetDescById_413330(v14);
				}
				LOBYTE(v7) = (unsigned int)nox_xxx_playerRespawnItem_4EF750(
					v3, *(char**)getMemAt(0x587000, 206376 + 4 * *(unsigned char*)(*(uint32_t*)(v4 + 276) + 2251)),
					(int*)v18, 1, 0);
			} else if (nox_common_gameFlags_check_40A5C0(4096) && sub_4CFE00() >= 0) {
				*(uint32_t*)v18 = 0;
				*(uint32_t*)&v18[4] = 0;
				*(uint32_t*)&v18[8] = 0;
				*(uint32_t*)&v18[12] = 0;
				if (*(uint8_t*)(*(uint32_t*)(v4 + 276) + 2251) == 1) {
					v15 = nox_xxx_modifGetIdByName_413290("Replenishment1");
					*(uint32_t*)&v18[8] = nox_xxx_modifGetDescById_413330(v15);
				}
				LOBYTE(v7) = (unsigned int)nox_xxx_playerRespawnItem_4EF750(
					v3, *(char**)getMemAt(0x587000, 206388 + 4 * *(unsigned char*)(*(uint32_t*)(v4 + 276) + 2251)),
					(int*)v18, 1, 0);
			} else {
				LOBYTE(v7) = *(uint8_t*)(*(uint32_t*)(v4 + 276) + 2251);
				if ((uint8_t)v7) {
					if ((uint8_t)v7 == 1) {
						LOBYTE(v7) = (unsigned int)nox_xxx_playerRespawnItem_4EF750(v3, "WizardRobe", 0, 1, 0);
					}
				} else {
					nox_xxx_playerRespawnItem_4EF750(v3, "Longsword", 0, 1, 0);
					LOBYTE(v7) = (unsigned int)nox_xxx_playerRespawnItem_4EF750(v3, "WoodenShield", 0, 1, 0);
				}
			}
		}
		v16 = *(uint32_t*)(v4 + 276);
		if (v16) {
			*(uint32_t*)(v16 + 4700) = 1;
		}
	}
	return v7;
}

//----- (004EFC30) --------------------------------------------------------
int nox_xxx_netSendPlayerRespawn_4EFC30(int a1, char a2) {
	char v3[9]; // [esp+0h] [ebp-Ch]

	v3[0] = -23;
	*(uint32_t*)&v3[3] = nox_frame_xxx_2598000;
	*(uint16_t*)&v3[1] = *(uint16_t*)(a1 + 36);
	v3[7] = nox_xxx_getRespawnWeaponFlags_4EF580();
	v3[8] = a2;
	return nox_xxx_netSendPacket1_4E5390(255, (int)v3, 9, 0, 0);
}

#ifndef NOX_CGO
//----- (004EFC80) --------------------------------------------------------
void nox_xxx_spellAwardAll2_4EFC80(nox_playerInfo* a1p) {
	int a1 = a1p;
	int v1;       // edi
	uint32_t* v2; // ebx
	char v3;      // al

	nox_xxx_playerUpdateNetBuffs_56F7D0(*(uint32_t*)(a1 + 4636), 0);
	v1 = 1;
	v2 = (uint32_t*)(a1 + 3700);
	if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ADMIN)) {
		do {
			*v2 = 3;
			nox_xxx_playerAwardSpellProtection_56FCE0(*(uint32_t*)(a1 + 4636), v1++, 3);
			++v2;
		} while (v1 < 137);
	} else {
		do {
			*v2 = 0;
			nox_xxx_playerAwardSpellProtection_56FCE0(*(uint32_t*)(a1 + 4636), v1++, 0);
			++v2;
		} while (v1 < 137);
		if (nox_common_gameFlags_check_40A5C0(4096)) {
			v3 = *(uint8_t*)(a1 + 2251);
			if (v3 == 1) {
				nox_xxx_spellGrantToPlayer_4FB550_magic_plyrspel(*(uint32_t*)(a1 + 2056), 27, 1, 1, 1);
			} else if (v3 == 2) {
				nox_xxx_spellGrantToPlayer_4FB550_magic_plyrspel(*(uint32_t*)(a1 + 2056), 9, 1, 1, 1);
				nox_xxx_spellGrantToPlayer_4FB550_magic_plyrspel(*(uint32_t*)(a1 + 2056), 41, 1, 1, 1);
			}
		}
	}
	sub_56FD50(*(uint32_t*)(a1 + 4636), a1 + 3696, 137);
}

//----- (004EFD80) --------------------------------------------------------
void nox_xxx_spellAwardAll1_4EFD80(nox_playerInfo* a1p) {
	int a1 = a1p;
	int v1;       // esi
	uint32_t* v2; // ebx

	nox_xxx_playerUpdateNetBuffs_56F7D0(*(uint32_t*)(a1 + 4640), 0);
	v1 = 1;
	v2 = (uint32_t*)(a1 + 4248);
	if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ADMIN)) {
		do {
			*v2 = 1;
			nox_xxx_playerAwardSpellProtection_56FCE0(*(uint32_t*)(a1 + 4640), v1++, 1);
			++v2;
		} while (v1 < 41);
	} else {
		do {
			*v2 = 0;
			nox_xxx_playerAwardSpellProtection_56FCE0(*(uint32_t*)(a1 + 4640), v1++, 0);
			++v2;
		} while (v1 < 41);
	}
	sub_56FD50(*(uint32_t*)(a1 + 4640), a1 + 4244, 41);
}

//----- (004EFE10) --------------------------------------------------------
void nox_xxx_spellAwardAll3_4EFE10(nox_playerInfo* a1p) {
	int a1 = a1p;
	int v2;       // esi
	uint32_t* v3; // ebx

	if (!*(uint8_t*)(a1 + 2251)) {
		v2 = 1;
		v3 = (uint32_t*)(a1 + 3700);
		if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_ADMIN)) {
			do {
				*v3 = 5;
				nox_xxx_playerAwardSpellProtection_56FCE0(*(uint32_t*)(a1 + 4636), v2++, 5);
				++v3;
			} while (v2 < 6);
		} else {
			do {
				*v3 = 0;
				nox_xxx_playerAwardSpellProtection_56FCE0(*(uint32_t*)(a1 + 4636), v2++, 0);
				++v3;
			} while (v2 < 6);
		}
	}
}
#endif // NOX_CGO

//----- (004EFE80) --------------------------------------------------------
char nox_xxx_unitInitPlayer_4EFE80(int a1) {
	int v1;   // edi
	int v2;   // eax
	float v4; // [esp+0h] [ebp-Ch]

	v1 = *(uint32_t*)(a1 + 748);
	v2 = sub_4FA6D0(a1);
	nox_xxx_playerSubGold_4FA5D0(a1, v2);
	sub_4EF140(a1);
	nox_xxx_spellAwardAll1_4EFD80(*(uint32_t*)(v1 + 276));
	nox_xxx_spellAwardAll2_4EFC80(*(uint32_t*)(v1 + 276));
	nox_xxx_plrReadVals_4EEDC0(a1, 0);
	nox_xxx_spellAwardAll3_4EFE10(*(uint32_t*)(v1 + 276));
	if (nox_common_gameFlags_check_40A5C0(4096)) {
		v4 = nox_xxx_gamedataGetFloat_419D40("QuestGameStartingExtraLives");
		*(uint32_t*)(v1 + 320) = nox_float2int(v4);
	}
	return nox_xxx_playerMakeDefItems_4EF7D0(a1, 1, 0);
}

//----- (004EFF10) --------------------------------------------------------
int sub_4EFF10(int a1) {
	int v1;            // edi
	unsigned short v2; // ax
	int v3;            // ecx
	unsigned int v4;   // ecx
	int result;        // eax

	v1 = *(uint32_t*)(a1 + 748);
	nox_xxx_spellAwardAll1_4EFD80(*(uint32_t*)(v1 + 276));
	nox_xxx_spellAwardAll2_4EFC80(*(uint32_t*)(v1 + 276));
	*(uint8_t*)(*(uint32_t*)(v1 + 276) + 3684) = 1;
	nox_xxx_playerCancelAbils_4FC180(a1);
	nox_xxx_plrReadVals_4EEDC0(a1, 0);
	nox_xxx_spellAwardAll3_4EFE10(*(uint32_t*)(v1 + 276));
	v2 = *(uint16_t*)(v1 + 8);
	v3 = *(uint32_t*)(v1 + 276);
	*(uint16_t*)(v1 + 4) = v2;
	*(uint16_t*)(v1 + 6) = v2;
	nox_xxx_protectPlayerHPMana_56F870(*(uint32_t*)(v3 + 4596), v2);
	*(uint32_t*)(v1 + 192) = 0;
	*(uint32_t*)(v1 + 196) = 0;
	*(uint32_t*)(v1 + 200) = 0;
	*(uint32_t*)(v1 + 204) = 0;
	*(uint32_t*)(v1 + 208) = 0;
	*(uint8_t*)(v1 + 212) = 0;
	nox_xxx_unitHPsetOnMax_4EE6F0(a1);
	v4 = *(uint32_t*)(a1 + 16) & 0xFFEB3FE7;
	*(uint8_t*)(a1 + 541) = 0;
	*(uint32_t*)(a1 + 16) = v4;
	nox_xxx_playerSetState_4FA020((uint32_t*)a1, 13);
	nox_xxx_unitClearBuffs_4FF580(a1);
	nox_xxx_playerCancelSpells_4FEAE0(a1);
	nox_xxx_removePoison_4EE9D0(a1);
	sub_4F7950(a1);
	nox_xxx_netReportTotalHealth_4D85C0(*(unsigned char*)(*(uint32_t*)(v1 + 276) + 2064), (uint32_t*)a1);
	nox_xxx_netReportTotalMana_4D88C0(*(unsigned char*)(*(uint32_t*)(v1 + 276) + 2064), a1);
	*(uint32_t*)(a1 + 520) = 0;
	result = -559023410;
	*(uint32_t*)(*(uint32_t*)(v1 + 276) + 3664) = -559023410;
	*(uint32_t*)(*(uint32_t*)(v1 + 276) + 3660) = -559023410;
	return result;
}

//----- (004F0040) --------------------------------------------------------
int nox_xxx_unitMonsterInit_4F0040(int a1) {
	int v1;        // eax
	int v2;        // edi
	int v3;        // edx
	int* v4;       // eax
	int v5;        // eax
	int* v6;       // eax
	int* v7;       // eax
	int* v8;       // eax
	int* v9;       // eax
	uint16_t* v10; // ecx
	int v11;       // eax
	int v12;       // ecx
	double v13;    // st7
	int result;    // eax

	v1 = *getMemU32Ptr(0x5D4594, 1568272);
	v2 = *(uint32_t*)(a1 + 748);
	if (!*getMemU32Ptr(0x5D4594, 1568272)) {
		v1 = nox_xxx_getNameId_4E3AA0("CarnivorousPlant");
		*getMemU32Ptr(0x5D4594, 1568272) = v1;
	}
	if (!(*(uint32_t*)(a1 + 16) & 0x8020)) {
		if (*(unsigned short*)(a1 + 4) == v1) {
			nox_xxx_monsterClearActionStack_50A3A0(a1);
			v3 = *(uint32_t*)(v2 + 484);
			*(uint32_t*)(v2 + 1360) = 4;
			*(float*)(v2 + 1312) = *(float*)(v3 + 112) + *(float*)(a1 + 176) + 10.0;
			goto LABEL_15;
		}
		if (nox_xxx_unitIsARat_534B60(a1)) {
			nox_xxx_monsterClearActionStack_50A3A0(a1);
			nox_xxx_monsterPushAction_50A260(a1, 29);
			*(uint32_t*)(v2 + 1304) = 1042536202;
		} else if (nox_xxx_unitIsAFish_534B10(a1)) {
			nox_xxx_monsterClearActionStack_50A3A0(a1);
			v4 = nox_xxx_monsterPushAction_50A260(a1, 10);
			if (v4) {
				v4[1] = 0;
				*((uint8_t*)v4 + 12) = -1;
			}
			*(uint32_t*)(v2 + 1304) = 1042536202;
		} else {
			if (!nox_xxx_unitIsAFrog_534B90(a1)) {
				goto LABEL_15;
			}
			nox_xxx_monsterClearActionStack_50A3A0(a1);
			nox_xxx_monsterPushAction_50A260(a1, 0);
			v5 = *(uint32_t*)(v2 + 1440);
			BYTE1(v5) |= 1u;
			*(uint32_t*)(v2 + 1304) = 1042536202;
			*(uint32_t*)(v2 + 1440) = v5;
		}
		*(uint32_t*)(v2 + 1360) = 38;
	}
LABEL_15:
	switch (*(uint32_t*)(v2 + 1360)) {
	case 3:
		v7 = nox_xxx_monsterPushAction_50A260(a1, 3);
		if (v7) {
			v7[1] = *(uint32_t*)(a1 + 56);
			v7[2] = *(uint32_t*)(a1 + 60);
			v7[3] = 0;
		}
		break;
	case 4:
		v9 = nox_xxx_monsterPushAction_50A260(a1, 4);
		if (v9) {
			v9[1] = *(uint32_t*)(a1 + 56);
			v9[2] = *(uint32_t*)(a1 + 60);
			v9[3] = *(short*)(a1 + 124);
		}
		break;
	case 0xA:
		if (nox_xxx_monsterCanAttackAtWill_534390(a1)) {
			nox_xxx_monsterPushAction_50A260(a1, 5);
		} else {
			v8 = nox_xxx_monsterPushAction_50A260(a1, 10);
			if (v8) {
				v8[1] = 0;
				*((uint8_t*)v8 + 12) = *(uint8_t*)(v2 + 1332);
			}
		}
		break;
	case 0xF:
		v6 = nox_xxx_monsterPushAction_50A260(a1, 15);
		if (v6) {
			v6[1] = *(uint32_t*)(a1 + 56);
			v6[2] = *(uint32_t*)(a1 + 60);
			v6[3] = nox_frame_xxx_2598000;
		}
		break;
	case 0x26:
		break;
	default:
		nox_xxx_monsterPushAction_50A260(a1, 0);
		break;
	}
	*(uint32_t*)(v2 + 1360) = 38;
	*(uint32_t*)(v2 + 376) = *(short*)(a1 + 124);
	*(uint32_t*)(v2 + 380) = *(uint32_t*)(a1 + 56);
	*(uint32_t*)(v2 + 384) = *(uint32_t*)(a1 + 60);
	v10 = *(uint16_t**)(a1 + 556);
	if (*v10 == v10[2]) {
		nox_xxx_unitSetHP_4E4560(a1, (long long)((double)(unsigned short)v10[2] * *(float*)(v2 + 1352)));
	}
	*(uint16_t*)(*(uint32_t*)(a1 + 556) + 2) = **(uint16_t**)(a1 + 556);
	v11 = v2 + 412;
	v12 = 32;
	do {
		v11 += 2;
		--v12;
		*(uint16_t*)(v11 - 2) = **(uint16_t**)(a1 + 556);
	} while (v12);
	if (*(uint8_t*)(a1 + 12) & 0x30) {
		v13 = *(float*)(v2 + 1328) * 0.5 + 1.7;
	} else {
		v13 = nox_common_randomFloat_416030(0.94999999, 1.05) * *(float*)(a1 + 548);
	}
	*(float*)(a1 + 548) = v13;
	if (nox_xxx_monsterCanCast_534300(a1)) {
		*(uint32_t*)(v2 + 1356) = 1120403456;
	}
	result = *(uint32_t*)(v2 + 1440);
	if (result & 0x40) {
		*(uint32_t*)(v2 + 1356) = 0;
	}
	if ((result & 0x8000) != 0) {
		BYTE1(result) |= 0x40u;
		*(uint32_t*)(v2 + 1440) = result;
	}
	return result;
}

//----- (004F0390) --------------------------------------------------------
uint32_t* nox_xxx_unitSparkInit_4F0390(int a1) {
	uint32_t* result; // eax

	result = *(uint32_t**)(a1 + 748);
	result[1] = 32;
	*result = 32;
	return result;
}

//----- (004F03B0) --------------------------------------------------------
int nox_xxx_initFrog_4F03B0(int a1) {
	uint8_t* v1; // esi
	int result;  // eax

	v1 = *(uint8_t**)(a1 + 748);
	*v1 = nox_common_randomInt_415FA0(55, 60);
	v1[1] = 1;
	v1[2] = 0;
	result = nox_common_randomInt_415FA0(0, 255);
	*(uint16_t*)(a1 + 126) = result;
	return result;
}

//----- (004F0400) --------------------------------------------------------
int* nox_xxx_initChest_4F0400(int a1) {
	int* result; // eax

	result = (int*)a1;
	if (!(*(uint8_t*)(a1 + 20) & 0xE)) {
		result = nox_xxx_unitSetXStatus_4E4800(a1, (int*)2);
	}
	return result;
}

//----- (004F0420) --------------------------------------------------------
uint32_t* nox_xxx_unitBoulderInit_4F0420(uint32_t* a1) {
	uint32_t* result; // eax
	int v2;           // edx

	result = a1;
	v2 = a1[15];
	a1[39] = a1[14];
	a1[40] = v2;
	return result;
}

//----- (004F0450) --------------------------------------------------------
int sub_4F0450(int a1) {
	int v1;     // edi
	short v2;   // ax
	int result; // eax

	v1 = *(uint32_t*)(a1 + 748);
	v2 = nox_xxx_xferDirectionToAngle_509E00(*(uint32_t**)(a1 + 692));
	*(uint16_t*)(a1 + 126) = v2;
	*(uint16_t*)(a1 + 124) = v2;
	result = nox_xxx_getNameId_4E3AA0((char*)(v1 + 16));
	*(uint32_t*)(v1 + 12) = result;
	return result;
}

//----- (004F0490) --------------------------------------------------------
int sub_4F0490(int a1) {
	int result; // eax

	result = nox_xxx_xferDirectionToAngle_509E00(*(uint32_t**)(a1 + 692));
	*(uint16_t*)(a1 + 126) = result;
	*(uint16_t*)(a1 + 124) = result;
	return result;
}

//----- (004F04B0) --------------------------------------------------------
int nox_xxx_unitInitGold_4F04B0(int a1) {
	int result;   // eax
	uint32_t* v2; // edi
	char* v3;     // eax
	int v4;       // esi
	int v5;       // ecx
	int v6;       // esi
	int v7;       // [esp+4h] [ebp-4h]
	float v8;     // [esp+Ch] [ebp+4h]
	float v9;     // [esp+Ch] [ebp+4h]

	result = a1;
	v2 = *(uint32_t**)(a1 + 692);
	if (!*v2) {
		v3 = nox_common_playerInfoGetFirst_416EA0();
		v4 = 0;
		v7 = 0;
		v8 = 0.0;
		if (v3) {
			do {
				v5 = *((uint32_t*)v3 + 514);
				if (v5) {
					v8 = v8 + *(float*)(v5 + 28);
				}
				v3 = nox_common_playerInfoGetNext_416EE0((int)v3);
				++v4;
			} while (v3);
			v7 = v4;
		}
		v9 = v8 / (double)v7;
		v6 = nox_common_randomInt_415FA0((long long)(v9 * *(double*)&qword_581450_10256),
										 (long long)(v9 * *getMemDoublePtr(0x581450, 10264))) -
			 (unsigned long long)(long long)(v9 * *getMemDoublePtr(0x581450, 10248));
		result = nox_common_randomInt_415FA0(15, 30);
		*v2 = result + v6;
	}
	return result;
}

//----- (004F0570) --------------------------------------------------------
int* nox_xxx_breakInit_4F0570(int a1) {
	int* result; // eax

	result = (int*)a1;
	if (!(*(uint8_t*)(a1 + 20) & 0xE)) {
		result = nox_xxx_unitSetXStatus_4E4800(a1, (int*)2);
	}
	return result;
}

//----- (004F0590) --------------------------------------------------------
int nox_xxx_unitInitGenerator_4F0590(int a1) {
	int v1;     // esi
	double v2;  // st7
	int result; // eax

	v1 = *(uint32_t*)(a1 + 748);
	switch (*(unsigned char*)(nox_xxx_getQuestStage_51A930() + v1 + 83)) {
	case 0u:
		v2 = nox_xxx_gamedataGetFloat_419D40("GeneratorMaxActiveCreaturesHigh");
		goto LABEL_6;
	case 1u:
		v2 = nox_xxx_gamedataGetFloat_419D40("GeneratorMaxActiveCreaturesNormal");
		goto LABEL_6;
	case 2u:
		v2 = nox_xxx_gamedataGetFloat_419D40("GeneratorMaxActiveCreaturesLow");
		goto LABEL_6;
	case 3u:
		v2 = nox_xxx_gamedataGetFloat_419D40("GeneratorMaxActiveCreaturesSingular");
	LABEL_6:
		*(uint8_t*)(v1 + 87) = (long long)v2;
		break;
	default:
		break;
	}
	result = *(uint32_t*)(a1 + 12);
	if (result & 1) {
		result = nox_xxx_mathDirection4ToAngle_509E90(0);
	LABEL_15:
		*(uint16_t*)(a1 + 124) = result;
		goto LABEL_16;
	}
	if (result & 2) {
		result = nox_xxx_mathDirection4ToAngle_509E90(2);
		goto LABEL_15;
	}
	if (result & 4) {
		result = nox_xxx_mathDirection4ToAngle_509E90(8);
		goto LABEL_15;
	}
	if (result & 8) {
		result = nox_xxx_mathDirection4ToAngle_509E90(6);
		goto LABEL_15;
	}
LABEL_16:
	*(uint16_t*)(a1 + 126) = *(uint16_t*)(a1 + 124);
	return result;
}

//----- (004F0720) --------------------------------------------------------
uint32_t* nox_server_rewardgen_activateMarker_4F0720(int a1, unsigned int a2) {
	int v2;             // eax
	int v3;             // ebx
	int* v4;            // ebp
	uint32_t* result;   // eax
	int v6;             // esi
	char v7;            // cl
	unsigned char* v8;  // eax
	unsigned int v9;    // eax
	int v10;            // ebp
	unsigned int v11;   // edi
	char v12;           // cl
	unsigned char* v13; // esi
	unsigned int v14;   // edx

	v2 = *getMemU32Ptr(0x5D4594, 1568276);
	v3 = a1;
	v4 = *(int**)(a1 + 692);
	if (!*getMemU32Ptr(0x5D4594, 1568276)) {
		v2 = nox_xxx_getNameId_4E3AA0("RewardMarkerPlus");
		*getMemU32Ptr(0x5D4594, 1568276) = v2;
	}
	if (*(unsigned short*)(a1 + 4) == v2) {
		a2 += 2;
	}
	switch (v4[53]) {
	case 1:
		if (nox_common_randomInt_415FA0(0, 100) <= 75) {
			goto LABEL_14;
		}
		result = 0;
		break;
	case 2:
		if (nox_common_randomInt_415FA0(0, 100) <= 50) {
			goto LABEL_14;
		}
		result = 0;
		break;
	case 3:
		if (nox_common_randomInt_415FA0(0, 100) <= 25) {
			goto LABEL_14;
		}
		result = 0;
		break;
	case 4:
		if (nox_common_randomInt_415FA0(0, 100) <= 5) {
			goto LABEL_14;
		}
		result = 0;
		break;
	default:
	LABEL_14:
		v6 = 0;
		v7 = 0;
		v8 = getMemAt(0x587000, 207044);
		do {
			if ((1 << v7) & *v4) {
				v6 += *v8;
			}
			v8 += 8;
			++v7;
		} while ((int)v8 < (int)getMemAt(0x587000, 207108));
		if (v6) {
			v9 = nox_common_randomInt_415FA0(1, v6);
			v10 = *v4;
			v11 = 0;
			v12 = 0;
			v13 = getMemAt(0x587000, 207044);
			while (1) {
				v14 = 1 << v12;
				if (v10 & (1 << v12)) {
					v11 += *v13;
					v3 = a1;
					if (v11 >= v9) {
						break;
					}
				}
				v13 += 8;
				++v12;
				if ((int)v13 >= (int)getMemAt(0x587000, 207108)) {
					v14 = a2;
					break;
				}
			}
			switch (v14) {
			case 1u:
				result = nox_xxx_rewardSpellBook_4F09F0(v3, a2);
				break;
			case 2u:
				result = nox_xxx_rewardAbilityBook_4F0C70(v3);
				break;
			case 4u:
				result = nox_xxx_rewardFieldGuide_4F0D20(v3, a2);
				break;
			case 8u:
				result = (uint32_t*)nox_xxx_rewardMakeWeapon_4F14E0(v3, a2);
				break;
			case 0x10u:
				result = nox_xxx_rewardMakeArmor_4F0E80(v3, a2);
				break;
			case 0x20u:
				result = nox_xxx_createGem_4F1D30(v3, a2);
				break;
			case 0x40u:
				result = nox_xxx_rewardMakePotion_4F1C40(v3, a2);
				break;
			case 0x80u:
				result = nox_xxx_createGem2_4F1F00(v3, a2);
				break;
			default:
				result = nox_xxx_createGem_4F1D30(v3, a2);
				break;
			}
		} else {
			result = 0;
		}
		break;
	}
	return result;
}

//----- (004F09F0) --------------------------------------------------------
uint32_t* nox_xxx_rewardSpellBook_4F09F0(int a1, unsigned int a2) {
	int v2;             // esi
	int v3;             // ecx
	int i;              // eax
	int v5;             // eax
	int v6;             // edx
	int v7;             // ecx
	uint32_t* result;   // eax
	int v9;             // ebx
	int v10;            // ebp
	int v11;            // ecx
	unsigned char* v12; // eax
	int v13;            // edx
	int v14;            // edi
	int v15;            // esi
	int v16;            // edx
	unsigned char* j;   // ecx
	int v18;            // eax

	v2 = *(uint32_t*)(a1 + 692);
	if (*(uint8_t*)(v2 + 4) & 1) {
		v3 = 0;
		for (i = 0; i < 137; ++i) {
			if (*(uint8_t*)(v2 + i + 8) == 1) {
				++v3;
			}
		}
		if (v3) {
			v5 = nox_common_randomInt_415FA0(0, v3 - 1);
			v6 = 0;
			v7 = 0;
			while (1) {
				if (*(uint8_t*)(v2 + v7 + 8) == 1) {
					if (v6 == v5) {
						v9 = v7;
						goto LABEL_27;
					}
					++v6;
				}
				if (++v7 >= 137) {
					return 0;
				}
			}
		}
		return 0;
	}
	v10 = nox_server_rewardGen_pickRandomSlots_4F0B60(a2);
	v11 = 0;
	if (!*getMemU32Ptr(0x587000, 207108)) {
		return 0;
	}
	v12 = getMemAt(0x587000, 207104);
	do {
		if (v10 & *((uint32_t*)v12 + 2)) {
			v11 += *v12;
		}
		v13 = *((uint32_t*)v12 + 4);
		v12 += 12;
	} while (v13);
	if (!v11) {
		return 0;
	}
	v14 = nox_common_randomInt_415FA0(0, v11 - 1);
	v15 = 0;
	v16 = 0;
	if (!*getMemU32Ptr(0x587000, 207108)) {
		return 0;
	}
	for (j = getMemAt(0x587000, 207104);; j += 12) {
		if (v10 & *((uint32_t*)j + 2)) {
			v15 += *j;
			if (v14 < v15) {
				break;
			}
		}
		v18 = *((uint32_t*)j + 4);
		++v16;
		if (!v18) {
			return 0;
		}
	}
	v9 = *getMemU32Ptr(0x587000, 207108 + 12 * v16);
LABEL_27:
	if (!v9) {
		return 0;
	}
	if (nox_xxx_playerCheckSpellClass_57AEA0(1, v9) || nox_xxx_playerCheckSpellClass_57AEA0(2, v9)) {
		if (nox_xxx_playerCheckSpellClass_57AEA0(1, v9)) {
			if (nox_xxx_playerCheckSpellClass_57AEA0(2, v9)) {
				return 0;
			}
			result = nox_xxx_newObjectByTypeID_4E3810("ConjurerSpellBook");
		} else {
			result = nox_xxx_newObjectByTypeID_4E3810("WizardSpellBook");
		}
	} else {
		result = nox_xxx_newObjectByTypeID_4E3810("CommonSpellBook");
	}
	if (!result) {
		return 0;
	}
	*(uint8_t*)result[184] = v9;
	return result;
}

//----- (004F0B60) --------------------------------------------------------
int nox_server_rewardGen_pickRandomSlots_4F0B60(unsigned int a1) {
	unsigned int v2; // eax
	float* v3;       // eax
	int v4;          // eax
	int v5;          // ecx
	float* v6;       // edx
	double v7;       // st7
	int v8;          // [esp+0h] [ebp-18h]
	float v9[5];     // [esp+4h] [ebp-14h]
	float v10;       // [esp+1Ch] [ebp+4h]

	v9[0] = 0.0;
	v9[1] = 0.0;
	v9[2] = 0.0;
	v9[3] = 0.0;
	v9[4] = 0.0;
	if (a1 > 0xA) {
		return 16;
	}
	switch (a1) {
	case 0u:
		return 1;
	case 1u:
		v9[0] = 87.5;
		v9[1] = 12.5;
		goto LABEL_12;
	case 9u:
		v9[3] = 12.5;
		v9[4] = 87.5;
		goto LABEL_12;
	case 0xAu:
		return 16;
	}
	if (a1 & 1) {
		v2 = a1 >> 1;
		v9[v2] = 75.0;
		*(int*)((char*)&v9 + v2 * 4) = 1095237632; // it's a float actually
		v9[v2 + 1] = 12.5;
	} else {
		v3 = &v9[a1 >> 1];
		*(v3 - 1) = 50.0;
		*v3 = 50.0;
	}
LABEL_12:
	v8 = 545;
	v4 = nox_common_randomInt_415FA0(0, 200);
	v5 = 0;
	v6 = v9;
	v7 = 0.0;
	while (1) {
		v7 = v7 + *v6;
		v10 = (double)v4 * 0.5;
		if (v10 <= v7) {
			break;
		}
		++v5;
		++v6;
		if (v5 >= 5) {
			return 1;
		}
	}
	return 1 << v5;
}

//----- (004F0C70) --------------------------------------------------------
uint32_t* nox_xxx_rewardAbilityBook_4F0C70(int a1) {
	int v1;           // esi
	int v2;           // ecx
	int i;            // eax
	uint32_t* result; // eax
	int v5;           // eax
	int v6;           // edx
	int v7;           // ecx
	int v8;           // ebx

	v1 = *(uint32_t*)(a1 + 692);
	if (!(*(uint8_t*)(v1 + 4) & 2)) {
		v8 = nox_common_randomInt_415FA0(1, 5);
		goto LABEL_16;
	}
	v2 = 0;
	for (i = 0; i < 6; ++i) {
		if (*(uint8_t*)(v1 + i + 145) == 1) {
			++v2;
		}
	}
	if (!v2) {
		return 0;
	}
	v5 = nox_common_randomInt_415FA0(0, v2 - 1);
	v6 = 0;
	v7 = 0;
	while (*(uint8_t*)(v1 + v7 + 145) != 1) {
	LABEL_12:
		if (++v7 >= 6) {
			return 0;
		}
	}
	if (v6 != v5) {
		++v6;
		goto LABEL_12;
	}
	v8 = v7;
LABEL_16:
	if (!v8) {
		return 0;
	}
	result = nox_xxx_newObjectByTypeID_4E3810("AbilityBook");
	if (result) {
		*(uint8_t*)result[184] = v8;
	}
	return result;
}

//----- (004F0D20) --------------------------------------------------------
uint32_t* nox_xxx_rewardFieldGuide_4F0D20(int a1, unsigned int a2) {
	int v2;             // esi
	int v3;             // ecx
	int i;              // eax
	uint32_t* result;   // eax
	int v6;             // eax
	int v7;             // edx
	int v8;             // ecx
	int v9;             // esi
	int v10;            // ebp
	int v11;            // ecx
	unsigned char* v12; // eax
	int v13;            // edx
	int v14;            // edi
	int v15;            // esi
	int v16;            // edx
	unsigned char* j;   // ecx
	int v18;            // eax
	uint32_t* v19;      // ebx
	char* v20;          // ebp
	char* v21;          // edi

	v2 = *(uint32_t*)(a1 + 692);
	if (*(uint8_t*)(v2 + 4) & 4) {
		v3 = 0;
		for (i = 0; i < 41; ++i) {
			if (*(uint8_t*)(v2 + i + 151) == 1) {
				++v3;
			}
		}
		if (v3) {
			v6 = nox_common_randomInt_415FA0(0, v3 - 1);
			v7 = 0;
			v8 = 0;
			while (1) {
				if (*(uint8_t*)(v2 + v8 + 151) == 1) {
					if (v7 == v6) {
						v9 = v8;
						goto LABEL_29;
					}
					++v7;
				}
				if (++v8 >= 41) {
					return 0;
				}
			}
		}
		result = 0;
	} else {
		v10 = nox_server_rewardGen_pickRandomSlots_4F0B60(a2);
		v11 = 0;
		if (!*getMemU32Ptr(0x587000, 207796)) {
			goto LABEL_35;
		}
		v12 = getMemAt(0x587000, 207792);
		do {
			if (v10 & *((uint32_t*)v12 + 2)) {
				v11 += *v12;
			}
			v13 = *((uint32_t*)v12 + 4);
			v12 += 12;
		} while (v13);
		if (v11) {
			v14 = nox_common_randomInt_415FA0(0, v11 - 1);
			v15 = 0;
			v16 = 0;
			if (!*getMemU32Ptr(0x587000, 207796)) {
				goto LABEL_36;
			}
			for (j = getMemAt(0x587000, 207792);; j += 12) {
				if (v10 & *((uint32_t*)j + 2)) {
					v15 += *j;
					if (v14 < v15) {
						break;
					}
				}
				v18 = *((uint32_t*)j + 4);
				++v16;
				if (!v18) {
					return 0;
				}
			}
			v9 = *getMemU32Ptr(0x587000, 207796 + 12 * v16);
		LABEL_29:
			if (v9) {
				result = nox_xxx_newObjectByTypeID_4E3810("FieldGuide");
				v19 = result;
				if (result) {
					v20 = (char*)result[184];
					v21 = nox_xxx_guideNameByN_427230(v9);
					result = v19;
					strcpy(v20, v21);
				}
			} else {
			LABEL_36:
				result = 0;
			}
		} else {
		LABEL_35:
			result = 0;
		}
	}
	return result;
}

//----- (004F0E80) --------------------------------------------------------
uint32_t* nox_xxx_rewardMakeArmor_4F0E80(int a1, unsigned int a2) {
	int v2;                // ebx
	int v3;                // edi
	unsigned char* v4;     // esi
	int v5;                // eax
	int v7;                // ebx
	int v8;                // ebp
	int v9;                // edi
	unsigned char* i;      // esi
	int v11;               // eax
	int v12;               // esi
	int v13;               // ebp
	uint32_t* v14;         // edi
	int v15;               // eax
	int v16;               // eax
	short v17;             // bx
	int v18;               // eax
	int v19;               // ecx
	unsigned char* v20;    // eax
	int v21;               // edx
	int v22;               // ecx
	unsigned char* v23;    // eax
	int v24;               // edx
	int v25;               // edx
	unsigned char* v26;    // eax
	int v27;               // ecx
	int v28;               // ecx
	unsigned char* v29;    // eax
	int v30;               // edx
	int v31;               // eax
	int v32;               // esi
	int v33;               // edx
	unsigned char* v34;    // ecx
	int v35;               // edi
	int v36;               // ecx
	unsigned char* v37;    // eax
	int v38;               // esi
	int v39;               // eax
	int v40;               // esi
	int v41;               // edx
	unsigned char* v42;    // ecx
	int v43;               // edi
	int v44;               // edx
	unsigned char* v45;    // eax
	int v46;               // ecx
	int v47;               // eax
	int v48;               // edi
	int v49;               // esi
	unsigned char* v50;    // ecx
	int v51;               // edx
	signed int v52;        // eax
	int v53;               // ecx
	int v54;               // eax
	int v55;               // ebx
	int v56;               // edx
	unsigned char* v57;    // eax
	int v58;               // ecx
	int v59;               // eax
	int v60;               // edi
	int v61;               // esi
	unsigned char* v62;    // ecx
	int v63;               // edx
	int v64;               // [esp+10h] [ebp-20h]
	int v65;               // [esp+14h] [ebp-1Ch]
	int v66;               // [esp+18h] [ebp-18h]
	unsigned char v67[20]; // [esp+1Ch] [ebp-14h]

	v65 = 0;
	v2 = nox_server_rewardGen_pickRandomSlots_4F0B60(a2);
	v3 = 0;
	v64 = v2;
	if (!*getMemU32Ptr(0x587000, 208180)) {
		return 0;
	}
	v4 = getMemAt(0x587000, 208192);
	do {
		if (*(v4 - 4) & 2 && v2 & *(uint32_t*)v4 && nox_xxx_getUnitDefDd10_4E3BA0(*((uint32_t*)v4 - 2))) {
			v3 += *(v4 - 16);
		}
		v5 = *((uint32_t*)v4 + 2);
		v4 += 20;
	} while (v5);
	if (!v3) {
		return 0;
	}
	v7 = nox_common_randomInt_415FA0(0, v3 - 1);
	v8 = 0;
	v9 = 0;
	if (!*getMemU32Ptr(0x587000, 208180)) {
		return 0;
	}
	for (i = getMemAt(0x587000, 208192);; i += 20) {
		if (*(i - 4) & 2) {
			if (v64 & *(uint32_t*)i) {
				if (nox_xxx_getUnitDefDd10_4E3BA0(*((uint32_t*)i - 2))) {
					v8 += *(i - 16);
					if (v7 < v8) {
						break;
					}
				}
			}
		}
		v11 = *((uint32_t*)i + 2);
		++v9;
		if (!v11) {
			return 0;
		}
	}
	v12 = *getMemU32Ptr(0x587000, 208184 + 20 * v9);
	if (!v12) {
		return 0;
	}
	v13 = sub_415D10(*(char**)getMemAt(0x587000, 208184 + 20 * v9));
	v14 = nox_xxx_newObjectWithTypeInd_4E3450(v12);
	v66 = (int)v14;
	if (!v14) {
		return 0;
	}
	switch (v64) {
	case 2:
		v15 = nox_common_randomInt_415FA0(0, 1);
		goto LABEL_27;
	case 4:
		v15 = nox_common_randomInt_415FA0(0, 2);
		goto LABEL_27;
	case 8:
		v15 = nox_common_randomInt_415FA0(1, 3);
		goto LABEL_27;
	case 16:
		v15 = nox_common_randomInt_415FA0(2, 4);
	LABEL_27:
		if (!v15) {
			return v14;
		}
		*(uint32_t*)v67 = 0;
		*(uint32_t*)&v67[4] = 0;
		*(uint32_t*)&v67[8] = 0;
		*(uint32_t*)&v67[12] = 0;
		*(uint16_t*)&v67[16] = 0;
		*(uint16_t*)&v67[18] = 0;
		switch (v15) {
		case 1:
			v16 = nox_common_randomInt_415FA0(1, 100);
			if (v16 > 20) {
				v17 = (v16 > 50) + 1;
			} else {
				v17 = 4;
			}
			break;
		case 2:
			v18 = nox_common_randomInt_415FA0(1, 100);
			if (v18 > 12) {
				v17 = v18 > 25 ? 3 : 6;
			} else {
				v17 = 5;
			}
			break;
		case 3:
			v17 = 7;
			break;
		default:
			v17 = 15;
			if (v15 != 4) {
				v17 = a2;
			}
			break;
		}
		if (v17 & 1) {
			v19 = 0;
			if (!*getMemU32Ptr(0x587000, 210856)) {
				goto LABEL_178;
			}
			v20 = getMemAt(0x587000, 210852);
			do {
				if (v64 & *((uint32_t*)v20 + 2) && v13 & *(uint32_t*)(*(uint32_t*)v20 + 32) &&
					!(v13 & *((uint32_t*)v20 + 3))) {
					++v19;
				}
				v21 = *((uint32_t*)v20 + 7);
				v20 += 24;
			} while (v21);
			if (!v19) {
			LABEL_178:
				if (v17 & 2) {
					if (v17 & 4) {
						if (!(v17 & 8)) {
							v17 |= 8u;
						}
					} else {
						v17 |= 4u;
					}
				} else {
					v17 |= 2u;
				}
				v17 &= 0xFFFEu;
			}
		}
		if (v17 & 2) {
			v22 = 0;
			if (!*getMemU32Ptr(0x587000, 211000)) {
				goto LABEL_179;
			}
			v23 = getMemAt(0x587000, 210996);
			do {
				if (v64 & *((uint32_t*)v23 + 2) && v13 & *(uint32_t*)(*(uint32_t*)v23 + 32) &&
					!(v13 & *((uint32_t*)v23 + 3))) {
					++v22;
				}
				v24 = *((uint32_t*)v23 + 7);
				v23 += 24;
			} while (v24);
			if (!v22) {
			LABEL_179:
				if (v17 & 4) {
					if (!(v17 & 8)) {
						v17 |= 8u;
					}
				} else {
					v17 |= 4u;
				}
				v17 &= 0xFFFDu;
			}
		}
		if (v17 & 4) {
			v25 = 0;
			if (!*getMemU32Ptr(0x587000, 209344)) {
				goto LABEL_180;
			}
			v26 = getMemAt(0x587000, 209340);
			do {
				if (v64 & *((uint32_t*)v26 + 2) && v13 & *(uint32_t*)(*(uint32_t*)v26 + 32) &&
					!(v13 & *((uint32_t*)v26 + 3)) && *(uint8_t*)(*(uint32_t*)v26 + 36) & 1) {
					++v25;
				}
				v27 = *((uint32_t*)v26 + 7);
				v26 += 24;
			} while (v27);
			if (!v25) {
			LABEL_180:
				v17 &= 0xFFF3u;
			}
		}
		if (!v17) {
			return v14;
		}
		if (!(v17 & 1)) {
			goto LABEL_103;
		}
		v28 = 0;
		if (!*getMemU32Ptr(0x587000, 210856)) {
			goto LABEL_103;
		}
		v29 = getMemAt(0x587000, 210852);
		do {
			if (*((uint32_t*)v29 + 2) & v64 && v13 & *(uint32_t*)(*(uint32_t*)v29 + 32) &&
				!(v13 & *((uint32_t*)v29 + 3))) {
				++v28;
			}
			v30 = *((uint32_t*)v29 + 7);
			v29 += 24;
		} while (v30);
		if (!v28) {
			goto LABEL_103;
		}
		v31 = nox_common_randomInt_415FA0(0, v28 - 1);
		v32 = 0;
		v33 = 0;
		if (!*getMemU32Ptr(0x587000, 210856)) {
			goto LABEL_103;
		}
		v34 = getMemAt(0x587000, 210852);
		break;
	default:
		return v14;
	}
	while (1) {
		if (!(v64 & *((uint32_t*)v34 + 2)) || !(v13 & *(uint32_t*)(*(uint32_t*)v34 + 32)) ||
			v13 & *((uint32_t*)v34 + 3)) {
			goto LABEL_100;
		}
		if (v32 == v31) {
			break;
		}
		++v32;
	LABEL_100:
		v35 = *((uint32_t*)v34 + 7);
		v34 += 24;
		++v33;
		if (!v35) {
			goto LABEL_103;
		}
	}
	*(uint32_t*)v67 = *getMemU32Ptr(0x587000, 210852 + 24 * v33);
LABEL_103:
	if (v17 & 2) {
		v36 = 0;
		if (*getMemU32Ptr(0x587000, 211000)) {
			v37 = getMemAt(0x587000, 210996);
			do {
				if (v64 & *((uint32_t*)v37 + 2) && v13 & *(uint32_t*)(*(uint32_t*)v37 + 32) &&
					!(v13 & *((uint32_t*)v37 + 3))) {
					++v36;
				}
				v38 = *((uint32_t*)v37 + 7);
				v37 += 24;
			} while (v38);
			if (v36) {
				v39 = nox_common_randomInt_415FA0(0, v36 - 1);
				v40 = 0;
				v41 = 0;
				if (*getMemU32Ptr(0x587000, 211000)) {
					v42 = getMemAt(0x587000, 210996);
					do {
						if (v64 & *((uint32_t*)v42 + 2) && v13 & *(uint32_t*)(*(uint32_t*)v42 + 32) &&
							!(v13 & *((uint32_t*)v42 + 3))) {
							if (v40 == v39) {
								*(uint32_t*)&v67[4] = *getMemU32Ptr(0x587000, 210996 + 24 * v41);
								break;
							}
							++v40;
						}
						v43 = *((uint32_t*)v42 + 7);
						v42 += 24;
						++v41;
					} while (v43);
				}
			}
		}
	}
	if (v17 & 4) {
		v44 = 0;
		if (*getMemU32Ptr(0x587000, 209344)) {
			v45 = getMemAt(0x587000, 209340);
			do {
				if (v64 & *((uint32_t*)v45 + 2) && v13 & *(uint32_t*)(*(uint32_t*)v45 + 32) &&
					!(v13 & *((uint32_t*)v45 + 3)) && *(uint8_t*)(*(uint32_t*)v45 + 36) & 1) {
					++v44;
				}
				v46 = *((uint32_t*)v45 + 7);
				v45 += 24;
			} while (v46);
			if (v44) {
				v47 = nox_common_randomInt_415FA0(0, v44 - 1);
				v48 = 0;
				v49 = 0;
				if (*getMemU32Ptr(0x587000, 209344)) {
					v50 = getMemAt(0x587000, 209340);
					do {
						if (v64 & *((uint32_t*)v50 + 2) && v13 & *(uint32_t*)(*(uint32_t*)v50 + 32) &&
							!(v13 & *((uint32_t*)v50 + 3)) && *(uint8_t*)(*(uint32_t*)v50 + 36) & 1) {
							if (v48 == v47) {
								v65 = v49;
								*(uint32_t*)&v67[8] = *getMemU32Ptr(0x587000, 209340 + 24 * v49);
								break;
							}
							++v48;
						}
						v51 = *((uint32_t*)v50 + 7);
						v50 += 24;
						++v49;
					} while (v51);
				}
			}
		}
	}
	if (v17 & 8) {
		v52 = a2 >> 1;
		if ((int)(a2 >> 1) >= 1) {
			if (v52 >= 5) {
				v52 = 4;
			}
		} else {
			v52 = 1;
		}
		v53 = v52 - 1;
		v54 = v52 + 1;
		if (v53 < 1) {
			v53 = 1;
		}
		if (v54 >= 5) {
			v54 = 4;
		}
		v55 = nox_common_randomInt_415FA0(v53, v54);
		v56 = 0;
		if (*getMemU32Ptr(0x587000, 209344)) {
			v57 = getMemAt(0x587000, 209340);
			do {
				if (v55 & *((uint32_t*)v57 + 2) && v13 & *(uint32_t*)(*(uint32_t*)v57 + 32) &&
					!(v13 & *((uint32_t*)v57 + 3)) && *(uint8_t*)(*(uint32_t*)v57 + 36) & 2) {
					++v56;
				}
				v58 = *((uint32_t*)v57 + 7);
				v57 += 24;
			} while (v58);
			if (v56) {
				v59 = nox_common_randomInt_415FA0(0, v56 - 1);
				v60 = 0;
				v61 = 0;
				if (*getMemU32Ptr(0x587000, 209344)) {
					v62 = getMemAt(0x587000, 209340);
					do {
						if (v55 & *((uint32_t*)v62 + 2) && v13 & *(uint32_t*)(*(uint32_t*)v62 + 32) &&
							!(v13 & *((uint32_t*)v62 + 3)) && *(uint8_t*)(*(uint32_t*)v62 + 36) & 2) {
							if (v60 == v59) {
								if (getMemByte(0x587000, 209336 + 24 * v65) !=
									getMemByte(0x587000, 209336 + 24 * v61)) {
									*(uint32_t*)&v67[12] = *getMemU32Ptr(0x587000, 209340 + 24 * v61);
								}
								break;
							}
							++v60;
						}
						v63 = *((uint32_t*)v62 + 7);
						v62 += 24;
						++v61;
					} while (v63);
				}
			}
		}
	}
	nox_xxx_modifSetItemAttrs_4E4990(v66, (int*)v67);
	return (uint32_t*)v66;
}

//----- (004F14E0) --------------------------------------------------------
int nox_xxx_rewardMakeWeapon_4F14E0(int a1, unsigned int a2) {
	int v2;                // ebx
	int v3;                // edi
	unsigned char* v4;     // esi
	int v5;                // eax
	int v7;                // ebx
	int v8;                // edi
	int v9;                // ebp
	unsigned char* v10;    // esi
	int v11;               // eax
	char* v12;             // esi
	uint32_t* v13;         // eax
	int v14;               // edi
	int v15;               // eax
	int v16;               // eax
	int v17;               // eax
	int v18;               // eax
	short v19;             // bx
	int v20;               // eax
	int v21;               // ecx
	int v22;               // ebp
	unsigned char* v23;    // eax
	int v24;               // edx
	int v25;               // ecx
	unsigned char* v26;    // eax
	int v27;               // edx
	int v28;               // edx
	unsigned char* v29;    // eax
	int v30;               // ecx
	int v31;               // ecx
	unsigned char* v32;    // eax
	int v33;               // edx
	int v34;               // eax
	int v35;               // esi
	int v36;               // edx
	unsigned char* v37;    // ecx
	int v38;               // edi
	int v39;               // ecx
	unsigned char* v40;    // eax
	int v41;               // esi
	int v42;               // eax
	int v43;               // esi
	int v44;               // edx
	unsigned char* v45;    // ecx
	int v46;               // edi
	signed int v47;        // eax
	int v48;               // ecx
	int v49;               // eax
	int v50;               // ebp
	int v51;               // edx
	unsigned char* v52;    // eax
	int v53;               // ecx
	int v54;               // eax
	int v55;               // edi
	int v56;               // esi
	unsigned char* v57;    // ecx
	int v58;               // edx
	signed int v59;        // eax
	int v60;               // ecx
	int v61;               // eax
	int v62;               // ebp
	int v63;               // edx
	unsigned char* v64;    // eax
	int v65;               // ecx
	int v66;               // eax
	int v67;               // edi
	int v68;               // esi
	unsigned char* v69;    // ecx
	int v70;               // edx
	short v71 = 0;         // [esp+10h] [ebp-28h]
	int v72;               // [esp+14h] [ebp-24h]
	int v73;               // [esp+18h] [ebp-20h]
	int v74;               // [esp+1Ch] [ebp-1Ch]
	int v75;               // [esp+20h] [ebp-18h]
	unsigned char v76[20]; // [esp+24h] [ebp-14h]

	v74 = 0;
	v2 = nox_server_rewardGen_pickRandomSlots_4F0B60(a2);
	v3 = 0;
	v72 = v2;
	if (!*getMemU32Ptr(0x587000, 208180)) {
		return 0;
	}
	v4 = getMemAt(0x587000, 208192);
	do {
		if (*(v4 - 4) & 1 && v2 & *(uint32_t*)v4 && nox_xxx_getUnitDefDd10_4E3BA0(*((uint32_t*)v4 - 2))) {
			v3 += *(v4 - 16);
		}
		v5 = *((uint32_t*)v4 + 2);
		v4 += 20;
	} while (v5);
	if (!v3) {
		return 0;
	}
	v7 = nox_common_randomInt_415FA0(0, v3 - 1);
	v8 = 0;
	v9 = 0;
	if (*getMemU32Ptr(0x587000, 208180)) {
		v10 = getMemAt(0x587000, 208192);
		while (1) {
			if (*(v10 - 4) & 1) {
				if (v72 & *(uint32_t*)v10) {
					if (nox_xxx_getUnitDefDd10_4E3BA0(*((uint32_t*)v10 - 2))) {
						v8 += *(v10 - 16);
						if (v7 < v8) {
							break;
						}
					}
				}
			}
			v11 = *((uint32_t*)v10 + 2);
			v10 += 20;
			++v9;
			if (!v11) {
				goto LABEL_17;
			}
		}
		v12 = *(char**)getMemAt(0x587000, 208184 + 20 * v9);
	} else {
	LABEL_17:
		v12 = (char*)a2;
	}
	if (!v12) {
		return 0;
	}
	v73 = nox_xxx_ammoCheck_415880(v12);
	v13 = nox_xxx_newObjectWithTypeInd_4E3450((int)v12);
	v14 = (int)v13;
	v75 = (int)v13;
	if (!v13) {
		return 0;
	}
	v15 = v13[2];
	if (v15 & 0x1000 && *(uint32_t*)(v14 + 12) & 0x47F0000) {
		if (**(uint8_t**)getMemAt(0x587000, 208180 + 20 * v9) == 35) {
			*(uint32_t*)v76 = 0;
			*(uint32_t*)&v76[4] = 0;
			v16 = nox_xxx_modifGetIdByName_413290("Replenishment1");
			*(uint32_t*)&v76[8] = nox_xxx_modifGetDescById_413330(v16);
			*(uint32_t*)&v76[12] = 0;
			*(uint16_t*)&v76[16] = 0;
			*(uint16_t*)&v76[18] = 0;
			nox_xxx_modifSetItemAttrs_4E4990(v14, (int*)v76);
		}
		return v14;
	}
	switch (v72) {
	case 2:
		v17 = nox_common_randomInt_415FA0(0, 1);
		goto LABEL_33;
	case 4:
		v17 = nox_common_randomInt_415FA0(0, 2);
		goto LABEL_33;
	case 8:
		v17 = nox_common_randomInt_415FA0(1, 3);
		goto LABEL_33;
	case 16:
		v17 = nox_common_randomInt_415FA0(2, 4);
	LABEL_33:
		if (!v17) {
			return v14;
		}
		*(uint32_t*)v76 = 0;
		*(uint32_t*)&v76[4] = 0;
		*(uint32_t*)&v76[8] = 0;
		*(uint32_t*)&v76[12] = 0;
		*(uint16_t*)&v76[16] = 0;
		*(uint16_t*)&v76[18] = 0;
		switch (v17) {
		case 1:
			v18 = nox_common_randomInt_415FA0(1, 100);
			if (v18 > 20) {
				v19 = (v18 > 50) + 1;
				LOBYTE(v71) = (v18 > 50) + 1;
			} else {
				v19 = 4;
				LOBYTE(v71) = 4;
			}
			break;
		case 2:
			v20 = nox_common_randomInt_415FA0(1, 100);
			if (v20 > 12) {
				v19 = v20 > 25 ? 3 : 6;
				LOBYTE(v71) = v20 > 25 ? 3 : 6;
			} else {
				v19 = 5;
				LOBYTE(v71) = 5;
			}
			break;
		case 3:
			v19 = 7;
			LOBYTE(v71) = 7;
			break;
		case 4:
			v19 = 15;
			LOBYTE(v71) = 15;
			break;
		default:
			v19 = v71;
			break;
		}
		if (!(v19 & 1)) {
			v22 = v73;
			goto LABEL_67;
		}
		v21 = 0;
		if (!*getMemU32Ptr(0x587000, 210712)) {
			v22 = v73;
		LABEL_59:
			if (v19 & 2) {
				if (v19 & 4) {
					if (!(v19 & 8)) {
						v19 |= 8u;
					}
					v19 &= 0xFFFEu;
					LOBYTE(v71) = v19;
				} else {
					v19 = (v19 | 4) & 0xFFFE;
					LOBYTE(v71) = v19;
				}
			} else {
				v19 = (v19 | 2) & 0xFFFE;
				LOBYTE(v71) = v19;
			}
			goto LABEL_67;
		}
		v22 = v73;
		v23 = getMemAt(0x587000, 210708);
		do {
			if (v72 & *((uint32_t*)v23 + 2) && v73 & *(uint32_t*)(*(uint32_t*)v23 + 28) &&
				!(v73 & *((uint32_t*)v23 + 4))) {
				++v21;
			}
			v24 = *((uint32_t*)v23 + 7);
			v23 += 24;
		} while (v24);
		if (!v21) {
			goto LABEL_59;
		}
	LABEL_67:
		if (v19 & 2) {
			v25 = 0;
			if (!*getMemU32Ptr(0x587000, 211000)) {
				goto LABEL_196;
			}
			v26 = getMemAt(0x587000, 210996);
			do {
				if (v72 & *((uint32_t*)v26 + 2) && v22 & *(uint32_t*)(*(uint32_t*)v26 + 28) &&
					!(v22 & *((uint32_t*)v26 + 4))) {
					++v25;
				}
				v27 = *((uint32_t*)v26 + 7);
				v26 += 24;
			} while (v27);
			if (!v25) {
			LABEL_196:
				if (v19 & 4) {
					if (!(v19 & 8)) {
						v19 |= 8u;
					}
				} else {
					v19 |= 4u;
				}
				v19 &= 0xFFFDu;
				LOBYTE(v71) = v19;
			}
		}
		if (v19 & 4) {
			v28 = 0;
			if (!*getMemU32Ptr(0x587000, 209344)) {
				goto LABEL_197;
			}
			v29 = getMemAt(0x587000, 209340);
			do {
				if (v72 & *((uint32_t*)v29 + 2) && v22 & *(uint32_t*)(*(uint32_t*)v29 + 28) &&
					!(v22 & *((uint32_t*)v29 + 4)) && *(uint8_t*)(*(uint32_t*)v29 + 36) & 1) {
					++v28;
				}
				v30 = *((uint32_t*)v29 + 7);
				v29 += 24;
			} while (v30);
			if (!v28) {
			LABEL_197:
				v19 &= 0xFFF3u;
				LOBYTE(v71) = v19;
			}
		}
		if (!v19) {
			return v14;
		}
		if (v19 & 1) {
			v31 = 0;
			if (*getMemU32Ptr(0x587000, 210712)) {
				v32 = getMemAt(0x587000, 210708);
				do {
					if (*((uint32_t*)v32 + 2) & v72 && v22 & *(uint32_t*)(*(uint32_t*)v32 + 28) &&
						!(v22 & *((uint32_t*)v32 + 4))) {
						++v31;
					}
					v33 = *((uint32_t*)v32 + 7);
					v32 += 24;
				} while (v33);
				if (v31) {
					v34 = nox_common_randomInt_415FA0(0, v31 - 1);
					v35 = 0;
					v36 = 0;
					if (*getMemU32Ptr(0x587000, 210712)) {
						v37 = getMemAt(0x587000, 210708);
						do {
							if (v72 & *((uint32_t*)v37 + 2) && v22 & *(uint32_t*)(*(uint32_t*)v37 + 28) &&
								!(v22 & *((uint32_t*)v37 + 4))) {
								if (v35 == v34) {
									*(uint32_t*)v76 = *getMemU32Ptr(0x587000, 210708 + 24 * v36);
									break;
								}
								++v35;
							}
							v38 = *((uint32_t*)v37 + 7);
							v37 += 24;
							++v36;
						} while (v38);
					}
				}
			}
		}
		if (v19 & 2) {
			v39 = 0;
			if (*getMemU32Ptr(0x587000, 211000)) {
				v40 = getMemAt(0x587000, 210996);
				do {
					if (v72 & *((uint32_t*)v40 + 2) && v22 & *(uint32_t*)(*(uint32_t*)v40 + 28) &&
						!(v22 & *((uint32_t*)v40 + 4))) {
						++v39;
					}
					v41 = *((uint32_t*)v40 + 7);
					v40 += 24;
				} while (v41);
				if (v39) {
					v42 = nox_common_randomInt_415FA0(0, v39 - 1);
					v43 = 0;
					v44 = 0;
					if (*getMemU32Ptr(0x587000, 211000)) {
						v45 = getMemAt(0x587000, 210996);
						do {
							if (v72 & *((uint32_t*)v45 + 2) && v22 & *(uint32_t*)(*(uint32_t*)v45 + 28) &&
								!(v22 & *((uint32_t*)v45 + 4))) {
								if (v43 == v42) {
									*(uint32_t*)&v76[4] = *getMemU32Ptr(0x587000, 210996 + 24 * v44);
									break;
								}
								++v43;
							}
							v46 = *((uint32_t*)v45 + 7);
							v45 += 24;
							++v44;
						} while (v46);
					}
				}
			}
		}
		if (v19 & 4) {
			v47 = a2 >> 1;
			if ((int)(a2 >> 1) >= 1) {
				if (v47 >= 5) {
					v47 = 4;
				}
			} else {
				v47 = 1;
			}
			v48 = v47 - 1;
			v49 = v47 + 1;
			if (v48 < 1) {
				v48 = 1;
			}
			if (v49 >= 5) {
				v49 = 4;
			}
			v50 = nox_common_randomInt_415FA0(v48, v49);
			v51 = 0;
			if (*getMemU32Ptr(0x587000, 209344)) {
				v52 = getMemAt(0x587000, 209340);
				do {
					if (v50 & *((uint32_t*)v52 + 2) && v73 & *(uint32_t*)(*(uint32_t*)v52 + 28) &&
						!(v73 & *((uint32_t*)v52 + 4)) && *(uint8_t*)(*(uint32_t*)v52 + 36) & 1) {
						++v51;
					}
					v53 = *((uint32_t*)v52 + 7);
					v52 += 24;
				} while (v53);
				if (v51) {
					v54 = nox_common_randomInt_415FA0(0, v51 - 1);
					v55 = 0;
					v56 = 0;
					if (*getMemU32Ptr(0x587000, 209344)) {
						v57 = getMemAt(0x587000, 209340);
						do {
							if (v50 & *((uint32_t*)v57 + 2)) {
								if (v73 & *(uint32_t*)(*(uint32_t*)v57 + 28) && !(v73 & *((uint32_t*)v57 + 4)) &&
									*(uint8_t*)(*(uint32_t*)v57 + 36) & 1) {
									if (v55 == v54) {
										LOBYTE(v19) = v71;
										v74 = v56;
										*(uint32_t*)&v76[8] = *getMemU32Ptr(0x587000, 209340 + 24 * v56);
										break;
									}
									++v55;
								}
								LOBYTE(v19) = v71;
							}
							v58 = *((uint32_t*)v57 + 7);
							v57 += 24;
							++v56;
						} while (v58);
					}
				}
			}
		}
		if (v19 & 8) {
			v59 = a2 >> 1;
			if ((int)(a2 >> 1) >= 1) {
				if (v59 >= 5) {
					v59 = 4;
				}
			} else {
				v59 = 1;
			}
			v60 = v59 - 1;
			v61 = v59 + 1;
			if (v60 < 1) {
				v60 = 1;
			}
			if (v61 >= 5) {
				v61 = 4;
			}
			v62 = nox_common_randomInt_415FA0(v60, v61);
			v63 = 0;
			if (*getMemU32Ptr(0x587000, 209344)) {
				v64 = getMemAt(0x587000, 209340);
				do {
					if (v62 & *((uint32_t*)v64 + 2) && v73 & *(uint32_t*)(*(uint32_t*)v64 + 28) &&
						!(v73 & *((uint32_t*)v64 + 4)) && *(uint8_t*)(*(uint32_t*)v64 + 36) & 2) {
						++v63;
					}
					v65 = *((uint32_t*)v64 + 7);
					v64 += 24;
				} while (v65);
				if (v63) {
					v66 = nox_common_randomInt_415FA0(0, v63 - 1);
					v67 = 0;
					v68 = 0;
					if (*getMemU32Ptr(0x587000, 209344)) {
						v69 = getMemAt(0x587000, 209340);
						do {
							if (v62 & *((uint32_t*)v69 + 2) && v73 & *(uint32_t*)(*(uint32_t*)v69 + 28) &&
								!(v73 & *((uint32_t*)v69 + 4)) && *(uint8_t*)(*(uint32_t*)v69 + 36) & 2) {
								if (v67 == v66) {
									if (getMemByte(0x587000, 209336 + 24 * v74) !=
										getMemByte(0x587000, 209336 + 24 * v68)) {
										*(uint32_t*)&v76[12] = *getMemU32Ptr(0x587000, 209340 + 24 * v68);
									}
									break;
								}
								++v67;
							}
							v70 = *((uint32_t*)v69 + 7);
							v69 += 24;
							++v68;
						} while (v70);
					}
				}
			}
		}
		nox_xxx_modifSetItemAttrs_4E4990(v75, (int*)v76);
		return v75;
	default:
		return v14;
	}
}
// 4F1776: variable 'v71' is possibly undefined

//----- (004F1C40) --------------------------------------------------------
uint32_t* nox_xxx_rewardMakePotion_4F1C40(int a1, unsigned int a2) {
	int v2;            // ebx
	int v3;            // edi
	unsigned char* v4; // esi
	int v5;            // eax
	uint32_t* result;  // eax
	int v7;            // ebx
	int v8;            // ebp
	int v9;            // edi
	unsigned char* i;  // esi
	int v11;           // eax
	int v12;           // [esp+18h] [ebp+8h]

	v2 = nox_server_rewardGen_pickRandomSlots_4F0B60(a2);
	v3 = 0;
	v12 = v2;
	if (!*getMemU32Ptr(0x587000, 208180)) {
		return 0;
	}
	v4 = getMemAt(0x587000, 208192);
	do {
		if (*(v4 - 4) & 4 && v2 & *(uint32_t*)v4 && nox_xxx_getUnitDefDd10_4E3BA0(*((uint32_t*)v4 - 2))) {
			v3 += *(v4 - 16);
		}
		v5 = *((uint32_t*)v4 + 2);
		v4 += 20;
	} while (v5);
	if (!v3) {
		return 0;
	}
	v7 = nox_common_randomInt_415FA0(0, v3 - 1);
	v8 = 0;
	v9 = 0;
	if (!*getMemU32Ptr(0x587000, 208180)) {
		goto LABEL_24;
	}
	for (i = getMemAt(0x587000, 208192);; i += 20) {
		if (*(i - 4) & 4) {
			if (*(uint32_t*)i & v12) {
				if (nox_xxx_getUnitDefDd10_4E3BA0(*((uint32_t*)i - 2))) {
					v8 += *(i - 16);
					if (v7 < v8) {
						break;
					}
				}
			}
		}
		v11 = *((uint32_t*)i + 2);
		++v9;
		if (!v11) {
			return 0;
		}
	}
	if (*getMemU32Ptr(0x587000, 208184 + 20 * v9)) {
		result = nox_xxx_newObjectWithTypeInd_4E3450(*getMemU32Ptr(0x587000, 208184 + 20 * v9));
	} else {
	LABEL_24:
		result = 0;
	}
	return result;
}

//----- (004F1D30) --------------------------------------------------------
uint32_t* nox_xxx_createGem_4F1D30(int a1, unsigned int a2) {
	unsigned int v2;  // ebx
	int v3;           // eax
	uint32_t* result; // eax
	uint32_t* v5;     // edi
	int* v6;          // esi

	v2 = nox_server_rewardGen_pickRandomSlots_4F0B60(a2);
	if (v2 < 4 || nox_common_randomInt_415FA0(1, 100) <= 90) {
		if (nox_common_randomInt_415FA0(1, 2) == 1) {
			result = nox_xxx_newObjectByTypeID_4E3810("QuestGoldChest");
		} else {
			result = nox_xxx_newObjectByTypeID_4E3810("QuestGoldPile");
		}
		v5 = result;
		if (result) {
			v6 = (int*)result[173];
			switch (v2) {
			case 2u:
				*v6 = nox_common_randomInt_415FA0(*getMemIntPtr(0x587000, 211144), *getMemIntPtr(0x587000, 211148));
				result = v5;
				break;
			case 4u:
				*v6 = nox_common_randomInt_415FA0(*getMemIntPtr(0x587000, 211152), *getMemIntPtr(0x587000, 211156));
				result = v5;
				break;
			case 8u:
				*v6 = nox_common_randomInt_415FA0(*getMemIntPtr(0x587000, 211160), *getMemIntPtr(0x587000, 211164));
				result = v5;
				break;
			case 0x10u:
				*v6 = nox_common_randomInt_415FA0(*getMemIntPtr(0x587000, 211168), *getMemIntPtr(0x587000, 211172));
				result = v5;
				break;
			default:
				*v6 = nox_common_randomInt_415FA0(*getMemIntPtr(0x587000, 211136), *getMemIntPtr(0x587000, 211140));
				result = v5;
				break;
			}
		}
	} else {
		v3 = nox_common_randomInt_415FA0(1, 100);
		if (v3 >= 50) {
			if (v3 >= 90) {
				result = nox_xxx_newObjectByTypeID_4E3810("DiamondGem");
			} else {
				result = nox_xxx_newObjectByTypeID_4E3810("EmeraldGem");
			}
		} else {
			result = nox_xxx_newObjectByTypeID_4E3810("RubyGem");
		}
	}
	return result;
}

//----- (004F1F00) --------------------------------------------------------
uint32_t* nox_xxx_createGem2_4F1F00(int a1, unsigned int a2) { return nox_xxx_createGem_4F1D30(a1, a2); }

//----- (004F2110) --------------------------------------------------------
void sub_4F2110() {
	int v0;       // esi
	int i;        // eax
	int v2;       // ecx
	int v3;       // ebx
	int v4;       // edi
	int j;        // esi
	int v6;       // eax
	uint32_t* v7; // eax

	v0 = 0;
	if (!dword_5d4594_1568280) {
		dword_5d4594_1568280 = nox_xxx_getNameId_4E3AA0("RewardMarker");
		*getMemU32Ptr(0x5D4594, 1568284) = nox_xxx_getNameId_4E3AA0("RewardMarkerPlus");
	}
	for (i = nox_server_getFirstObject_4DA790(); i; i = nox_server_getNextObject_4DA7A0(i)) {
		v2 = *(unsigned short*)(i + 4);
		if (((unsigned short)v2 == dword_5d4594_1568280 || v2 == *getMemU32Ptr(0x5D4594, 1568284)) &&
			(**(uint8_t**)(i + 692) & 0x80)) {
			++v0;
		}
	}
	v3 = nox_common_randomInt_415FA0(0, v0 - 1);
	v4 = 0;
	for (j = nox_server_getFirstObject_4DA790(); j; j = nox_server_getNextObject_4DA7A0(j)) {
		v6 = *(unsigned short*)(j + 4);
		if (((unsigned short)v6 == dword_5d4594_1568280 || v6 == *getMemU32Ptr(0x5D4594, 1568284)) &&
			(**(uint8_t**)(j + 692) & 0x80)) {
			if (v4 == v3) {
				v7 = nox_xxx_newObjectByTypeID_4E3810("Ankh");
				if (v7) {
					nox_xxx_createAt_4DAA50((int)v7, 0, *(float*)(j + 56), *(float*)(j + 60));
					nox_xxx_delayedDeleteObject_4E5CC0(j);
					return;
				}
			} else {
				++v4;
			}
		}
	}
}

//----- (004F2210) --------------------------------------------------------
int sub_4F2210() {
	uint32_t* v0;     // ebp
	int v1;           // esi
	int v2;           // edi
	int v3;           // edi
	int v4;           // esi
	int result;       // eax
	int v6;           // ecx
	unsigned int v7;  // edi
	uint32_t* v8;     // esi
	uint32_t* v9;     // ebx
	int v10;          // ecx
	int v11;          // edx
	char v12;         // cl
	int v13;          // esi
	int v14;          // ebx
	uint32_t* v15;    // edi
	int v16;          // eax
	int v17;          // ecx
	int* v18;         // ecx
	int v19;          // edx
	int v20;          // eax
	unsigned int v21; // ebx
	int v22;          // esi
	uint32_t* v23;    // edi
	int v24;          // eax
	int v25;          // ecx
	unsigned int v26; // esi
	int* v27;         // edi
	float v28 = 0;    // [esp+10h] [ebp-14h]
	uint32_t* lpMem;  // [esp+14h] [ebp-10h]
	unsigned int v30; // [esp+18h] [ebp-Ch]
	unsigned int v31; // [esp+18h] [ebp-Ch]

	v0 = 0;
	lpMem = 0;
	v1 = nox_game_getQuestStage_4E3CC0();
	v2 = nox_xxx_player_4E3CE0();
	if (!dword_5d4594_1568288) {
		dword_5d4594_1568288 = nox_xxx_getNameId_4E3AA0("RewardMarker");
		*getMemU32Ptr(0x5D4594, 1568292) = nox_xxx_getNameId_4E3AA0("RewardMarkerPlus");
		*getMemU32Ptr(0x5D4594, 1568296) = nox_xxx_getNameId_4E3AA0("RedPotion");
	}
	if (v1 == 1) {
		v28 = 0.5;
	} else {
		switch (v2) {
		case 1:
		case 2:
			v28 = 0.40000001;
			break;
		case 3:
		case 4:
			v28 = 0.69999999;
			break;
		case 5:
		case 6:
			v28 = 1.0;
			break;
		default:
			break;
		}
	}
	v3 = 0;
	v4 = 0;
	result = nox_server_getFirstObject_4DA790();
	if (result) {
		do {
			v6 = *(unsigned short*)(result + 4);
			if ((unsigned short)v6 == dword_5d4594_1568288) {
				if (!(*(uint8_t*)(*(uint32_t*)(result + 692) + 216) & 1)) {
					++v3;
				}
			} else if (v6 == *getMemU32Ptr(0x5D4594, 1568296)) {
				++v4;
			}
			result = nox_server_getNextObject_4DA7A0(result);
		} while (result);
		if (v3) {
			v0 = calloc(v3, 4);
			if (!v4) {
				goto LABEL_21;
			}
		} else if (!v4) {
			return result;
		}
		lpMem = calloc(v4, 4);
	LABEL_21:
		v7 = 0;
		v30 = 0;
		result = nox_server_getFirstObject_4DA790();
		if (result) {
			v8 = lpMem;
			v9 = v0;
			do {
				v10 = *(unsigned short*)(result + 4);
				if ((unsigned short)v10 == dword_5d4594_1568288) {
					v11 = *(uint32_t*)(result + 692);
					v12 = *(uint8_t*)(v11 + 216);
					if (v12 & 1) {
						*(uint8_t*)(v11 + 216) = v12 | 0x80;
					} else {
						*v9 = result;
						++v7;
						++v9;
					}
				} else if (v10 == *getMemU32Ptr(0x5D4594, 1568292)) {
					*(uint8_t*)(*(uint32_t*)(result + 692) + 216) |= 0x80u;
				} else if (v10 == *getMemU32Ptr(0x5D4594, 1568296)) {
					*v8 = result;
					++v8;
					++v30;
				}
				result = nox_server_getNextObject_4DA7A0(result);
			} while (result);
			if (v7) {
				v13 = v7 - 1;
				v14 = (long long)((double)v7 * v28 + 0.5);
				if (v7 != 1) {
					v15 = &v0[v13];
					do {
						v16 = nox_common_randomInt_415FA0(0, v13);
						v17 = v0[v16];
						v0[v16] = *v15;
						*v15 = v17;
						--v13;
						--v15;
					} while (v13);
				}
				if (v14) {
					v18 = v0;
					v19 = v14;
					do {
						v20 = *v18;
						++v18;
						--v19;
						*(uint8_t*)(*(uint32_t*)(v20 + 692) + 216) |= 0x80u;
					} while (v19);
				}
				free(v0);
			}
			v21 = v30;
			if (v30) {
				v22 = v30 - 1;
				v31 = (long long)((double)v30 * v28 + 0.5);
				if (v21 != 1) {
					v23 = &lpMem[v22];
					do {
						v24 = nox_common_randomInt_415FA0(0, v22);
						v25 = lpMem[v24];
						lpMem[v24] = *v23;
						*v23 = v25;
						--v22;
						--v23;
					} while (v22);
				}
				v26 = 0;
				if (v21) {
					v27 = lpMem;
					do {
						if (v26 >= v31) {
							nox_xxx_delayedDeleteObject_4E5CC0(*v27);
						}
						++v26;
						++v27;
					} while (v26 < v21);
				}
				free(lpMem);
			}
		}
	}
	return result;
}
// 4F23B8: variable 'v28' is possibly undefined

//----- (004F24E0) --------------------------------------------------------
int sub_4F24E0(int a1) {
	int v1;            // eax
	unsigned char* v2; // ecx
	int result;        // eax

	v1 = *getMemU32Ptr(0x587000, 207108);
	if (!*getMemU32Ptr(0x587000, 207108)) {
		goto LABEL_6;
	}
	v2 = getMemAt(0x587000, 207108);
	while (v1 != a1 || !*((uint32_t*)v2 + 1)) {
		v1 = *((uint32_t*)v2 + 3);
		v2 += 12;
		if (!v1) {
			goto LABEL_6;
		}
	}
	if (a1 && a1 != 34 && a1 != 27 && a1 != 9 && a1 != 41) {
		result = 1;
	} else {
	LABEL_6:
		result = 0;
	}
	return result;
}

//----- (004F2530) --------------------------------------------------------
int sub_4F2530(int a1) {
	int v1;           // eax
	unsigned char* i; // ecx

	v1 = *getMemU32Ptr(0x587000, 207796);
	if (!*getMemU32Ptr(0x587000, 207796)) {
		return 0;
	}
	for (i = getMemAt(0x587000, 207796); v1 != a1 || !*((uint32_t*)i + 1); i += 12) {
		v1 = *((uint32_t*)i + 3);
		if (!v1) {
			return 0;
		}
	}
	return a1 != 0;
}

//----- (004F2570) --------------------------------------------------------
int sub_4F2570(int a1) { return a1 > 0 && a1 < 6; }

//----- (004F2590) --------------------------------------------------------
int sub_4F2590(int a1) {
	int v1;            // ebx
	int v3;            // ecx
	int v4;            // edx
	unsigned char* v5; // eax
	int v6;            // edi

	if (!*getMemU32Ptr(0x5D4594, 1568328)) {
		*getMemU32Ptr(0x5D4594, 1568328) = nox_xxx_getNameId_4E3AA0("Diamond");
		*getMemU32Ptr(0x5D4594, 1568332) = nox_xxx_getNameId_4E3AA0("Emerald");
		*getMemU32Ptr(0x5D4594, 1568336) = nox_xxx_getNameId_4E3AA0("Ruby");
		*getMemU32Ptr(0x5D4594, 1568340) = nox_xxx_getNameId_4E3AA0("SulphorousFlareWand");
		*getMemU32Ptr(0x5D4594, 1568344) = nox_xxx_getNameId_4E3AA0("StreetSneakers");
		*getMemU32Ptr(0x5D4594, 1568352) = nox_xxx_getNameId_4E3AA0("StreetShirt");
		*getMemU32Ptr(0x5D4594, 1568348) = nox_xxx_getNameId_4E3AA0("StreetPants");
	}
	v1 = *(uint32_t*)(a1 + 8);
	if (v1 & 0x40) {
		return 0;
	}
	if (v1 & 0x10) {
		return (*(uint32_t*)(a1 + 12) & 0x1FF78) != 0;
	}
	if (v1 & 0x100) {
		return sub_4F2700(a1);
	}
	v3 = *(unsigned short*)(a1 + 4);
	if ((unsigned short)v3 != *getMemU32Ptr(0x5D4594, 1568328) && v3 != *getMemU32Ptr(0x5D4594, 1568332) &&
		v3 != *getMemU32Ptr(0x5D4594, 1568336)) {
		v4 = 0;
		if (*getMemU32Ptr(0x587000, 208180)) {
			v5 = getMemAt(0x587000, 208180);
			while (*((uint32_t*)v5 + 1) != v3) {
				v6 = *((uint32_t*)v5 + 5);
				v5 += 20;
				if (!v6) {
					goto LABEL_18;
				}
			}
			v4 = 1;
		}
	LABEL_18:
		if (v3 == *getMemU32Ptr(0x5D4594, 1568340) || v3 == *getMemU32Ptr(0x5D4594, 1568344) ||
			v3 == *getMemU32Ptr(0x5D4594, 1568352) || v3 == *getMemU32Ptr(0x5D4594, 1568348)) {
			return sub_4F2B60(a1);
		}
		if (v4 != 1) {
			return 0;
		}
		if (v1 & 0x1000000) {
			return sub_4F27A0(a1);
		}
		if (v1 & 0x2000000) {
			return sub_4F2B20(a1);
		}
	}
	return 1;
}

//----- (004F2700) --------------------------------------------------------
int sub_4F2700(int a1) {
	int v1;           // ecx
	int v2;           // eax
	unsigned char* i; // ecx
	int v5;           // eax
	int v6;           // ecx
	unsigned char* j; // edx
	unsigned char v8; // al

	v1 = *(uint32_t*)(a1 + 12);
	if (v1 & 1) {
		if (*getMemU32Ptr(0x587000, 207108)) {
			v2 = *getMemU32Ptr(0x587000, 207108);
			for (i = getMemAt(0x587000, 207108); v2 != **(unsigned char**)(a1 + 736) || !*((uint32_t*)i + 1); i += 12) {
				v2 = *((uint32_t*)i + 3);
				if (!v2) {
					return 0;
				}
			}
			return 1;
		}
		return 0;
	}
	if (v1 & 2) {
		v5 = nox_xxx_guide_427010(*(const char**)(a1 + 736));
		v6 = *getMemU32Ptr(0x587000, 207796);
		if (*getMemU32Ptr(0x587000, 207796)) {
			for (j = getMemAt(0x587000, 207796); v6 != v5 || !*((uint32_t*)j + 1); j += 12) {
				v6 = *((uint32_t*)j + 3);
				if (!v6) {
					return 0;
				}
			}
			return 1;
		}
		return 0;
	}
	if (!(v1 & 4)) {
		return 0;
	}
	v8 = **(uint8_t**)(a1 + 736);
	if (!v8 || v8 >= 6u) {
		return 0;
	}
	return 1;
}

//----- (004F27A0) --------------------------------------------------------
int sub_4F27A0(int a1) {
	int result; // eax

	result = sub_4F27E0(a1);
	if (result) {
		result = sub_4F28C0(a1);
		if (result) {
			result = sub_4F2960(a1) != 0;
		}
	}
	return result;
}

//----- (004F27E0) --------------------------------------------------------
int sub_4F27E0(int a1) {
	int v1;            // edi
	int v2;            // eax
	int v3;            // esi
	int v4;            // edx
	unsigned char* i;  // ecx
	int v6;            // ebx
	unsigned char* v8; // ecx
	int v9;            // edx
	unsigned char* j;  // ecx
	int v11;           // ebx

	v1 = **(uint32_t**)(a1 + 692);
	if (!v1) {
		return 1;
	}
	if (*(uint32_t*)(a1 + 8) & 0x1000000) {
		v2 = nox_xxx_weaponInventoryEquipFlags_415820(a1);
	} else {
		v2 = nox_xxx_unitArmorInventoryEquipFlags_415C70(a1);
	}
	v3 = *(uint32_t*)(a1 + 8) & 0x1000000;
	if (v3) {
		v4 = 0;
		if (*getMemU32Ptr(0x587000, 210712)) {
			for (i = getMemAt(0x587000, 210712); *((uint32_t*)i - 1) != v1; i += 24) {
				v6 = *((uint32_t*)i + 6);
				++v4;
				if (!v6) {
					return 0;
				}
			}
			v8 = getMemAt(0x587000, 210704 + 24 * v4);
			goto LABEL_18;
		}
		return 0;
	}
	v9 = 0;
	if (!*getMemU32Ptr(0x587000, 210856)) {
		return 0;
	}
	for (j = getMemAt(0x587000, 210856); *((uint32_t*)j - 1) != v1; j += 24) {
		v11 = *((uint32_t*)j + 6);
		++v9;
		if (!v11) {
			return 0;
		}
	}
	v8 = getMemAt(0x587000, 210848 + 24 * v9);
LABEL_18:
	if (!v8) {
		return 0;
	}
	if (v3) {
		if (!(v2 & *(uint32_t*)(v1 + 28)) || v2 & *((uint32_t*)v8 + 5)) {
			return 0;
		}
	} else if (!(v2 & *(uint32_t*)(v1 + 32)) || v2 & *((uint32_t*)v8 + 4)) {
		return 0;
	}
	return 1;
}

//----- (004F28C0) --------------------------------------------------------
int sub_4F28C0(int a1) {
	int v1;            // esi
	int v2;            // eax
	int v3;            // edx
	unsigned char* i;  // ecx
	int v5;            // ebp
	unsigned char* v7; // ecx

	v1 = *(uint32_t*)(*(uint32_t*)(a1 + 692) + 4);
	if (v1) {
		if (*(uint32_t*)(a1 + 8) & 0x1000000) {
			v2 = nox_xxx_weaponInventoryEquipFlags_415820(a1);
		} else {
			v2 = nox_xxx_unitArmorInventoryEquipFlags_415C70(a1);
		}
		v3 = 0;
		if (!*getMemU32Ptr(0x587000, 211000)) {
			return 0;
		}
		for (i = getMemAt(0x587000, 211000); *((uint32_t*)i - 1) != v1; i += 24) {
			v5 = *((uint32_t*)i + 6);
			++v3;
			if (!v5) {
				return 0;
			}
		}
		v7 = getMemAt(0x587000, 210992 + 24 * v3);
		if (!v7) {
			return 0;
		}
		if (*(uint32_t*)(a1 + 8) & 0x1000000) {
			if (!(v2 & *(uint32_t*)(v1 + 28)) || v2 & *((uint32_t*)v7 + 5)) {
				return 0;
			}
		} else if (!(v2 & *(uint32_t*)(v1 + 32)) || v2 & *((uint32_t*)v7 + 4)) {
			return 0;
		}
	}
	return 1;
}

//----- (004F2960) --------------------------------------------------------
int sub_4F2960(int a1) {
	int v1;             // eax
	int v2;             // eax
	int v3;             // eax
	int v4;             // eax
	int v5;             // eax
	int v6;             // ebx
	int v7;             // ecx
	char v8;            // dl
	unsigned char* v9;  // edi
	int v10;            // esi
	unsigned char* v11; // edx
	int v12;            // esi
	uint8_t* v13;       // ecx
	unsigned char* v14; // edx
	int v16;            // [esp+10h] [ebp-4h]

	v16 = *(uint32_t*)(a1 + 692);
	if (!dword_5d4594_1568308) {
		v1 = nox_xxx_modifGetIdByName_413290("Replenishment1");
		dword_5d4594_1568308 = nox_xxx_modifGetDescById_413330(v1);
		v2 = nox_xxx_modifGetIdByName_413290("Replenishment2");
		*getMemU32Ptr(0x5D4594, 1568312) = nox_xxx_modifGetDescById_413330(v2);
		v3 = nox_xxx_modifGetIdByName_413290("Replenishment3");
		*getMemU32Ptr(0x5D4594, 1568316) = nox_xxx_modifGetDescById_413330(v3);
		v4 = nox_xxx_modifGetIdByName_413290("Replenishment4");
		*getMemU32Ptr(0x5D4594, 1568320) = nox_xxx_modifGetDescById_413330(v4);
	}
	if (*(uint32_t*)(a1 + 8) & 0x1000000) {
		v5 = nox_xxx_weaponInventoryEquipFlags_415820(a1);
	} else {
		v5 = nox_xxx_unitArmorInventoryEquipFlags_415C70(a1);
	}
	v6 = 2;
	while (1) {
		v7 = *(uint32_t*)(v16 + 4 * v6);
		if (!v7) {
			goto LABEL_40;
		}
		v8 = *(uint8_t*)(v7 + 36);
		v9 = 0;
		if (v6 == 2) {
			if (!(v8 & 1)) {
				return 0;
			}
		} else if (!(v8 & 2)) {
			return 0;
		}
		v10 = 0;
		if (!*getMemU32Ptr(0x587000, 209344)) {
			goto LABEL_18;
		}
		v11 = getMemAt(0x587000, 209344);
		while (*((uint32_t*)v11 - 1) != v7) {
			v11 += 24;
			++v10;
			if (!*(uint32_t*)v11) {
				goto LABEL_18;
			}
		}
		v9 = getMemAt(0x587000, 209336 + 24 * v10);
		if (!v9) {
		LABEL_18:
			if (v7 == dword_5d4594_1568308) {
				break;
			}
			if (v7 != *getMemU32Ptr(0x5D4594, 1568312) && v7 != *getMemU32Ptr(0x5D4594, 1568316) &&
				v7 != *getMemU32Ptr(0x5D4594, 1568320)) {
				return 0;
			}
		}
		if (v7 == dword_5d4594_1568308 || v7 == *getMemU32Ptr(0x5D4594, 1568312) ||
			v7 == *getMemU32Ptr(0x5D4594, 1568316) || v7 == *getMemU32Ptr(0x5D4594, 1568320)) {
			break;
		}
		if (*(uint32_t*)(a1 + 8) & 0x1000000) {
			if (!(v5 & *(uint32_t*)(v7 + 28)) || v5 & *((uint32_t*)v9 + 5)) {
				return 0;
			}
		} else if (!(v5 & *(uint32_t*)(v7 + 32)) || v5 & *((uint32_t*)v9 + 4)) {
			return 0;
		}
	LABEL_40:
		if (++v6 >= 4) {
			return 1;
		}
	}
	v12 = 0;
	if (*getMemU32Ptr(0x587000, 208180)) {
		v13 = *(uint8_t**)getMemAt(0x587000, 208180);
		v14 = getMemAt(0x587000, 208180);
		do {
			if (*v13 == 35 && *((uint32_t*)v14 + 1) == *(unsigned short*)(a1 + 4)) {
				v12 = 1;
			}
			v13 = (uint8_t*)*((uint32_t*)v14 + 5);
			v14 += 20;
		} while (v13);
		if (v12) {
			goto LABEL_40;
		}
	}
	return 0;
}

//----- (004F2B20) --------------------------------------------------------
int sub_4F2B20(int a1) {
	int result; // eax

	result = sub_4F27E0(a1);
	if (result) {
		result = sub_4F28C0(a1);
		if (result) {
			result = sub_4F2960(a1) != 0;
		}
	}
	return result;
}

//----- (004F2B60) --------------------------------------------------------
int sub_4F2B60(int a1) {
	int v1;           // eax
	uint32_t* v2;     // eax
	short v4;         // ax
	const char*** v5; // esi
	int v6;           // edi

	if (!*getMemU32Ptr(0x5D4594, 1568324)) {
		v1 = nox_xxx_modifGetIdByName_413290("Replenishment1");
		*getMemU32Ptr(0x5D4594, 1568324) = nox_xxx_modifGetDescById_413330(v1);
	}
	if (*(uint32_t*)(a1 + 8) & 0x1000000 && nox_xxx_weaponInventoryEquipFlags_415820(a1) & 0x10000) {
		v2 = *(uint32_t**)(a1 + 692);
		if (*v2) {
			return 0;
		}
		if (v2[1]) {
			return 0;
		}
		if (v2[2] != *getMemU32Ptr(0x5D4594, 1568324)) {
			return 0;
		}
		if (v2[3]) {
			return 0;
		}
	}
	if (*(uint32_t*)(a1 + 8) & 0x2000000) {
		v4 = nox_xxx_unitArmorInventoryEquipFlags_415C70(a1);
		v5 = *(const char****)(a1 + 692);
		if (v4 & 0x405) {
			v6 = 0;
			while (!*v5 || !_strnicmp(**v5, "UserColo", 8u)) {
				++v6;
				++v5;
				if (v6 >= 4) {
					return 1;
				}
			}
			return 0;
		}
	}
	return 1;
}

//----- (004F2C30) --------------------------------------------------------
int sub_4F2C30(int a1) {
	int v1;   // edi
	float v3; // [esp+0h] [ebp-Ch]

	if (!*getMemU32Ptr(0x5D4594, 1568356)) {
		*getMemU32Ptr(0x5D4594, 1568356) = nox_xxx_getNameId_4E3AA0("RedPotion");
		*getMemU32Ptr(0x5D4594, 1568360) = nox_xxx_getNameId_4E3AA0("BluePotion");
		*getMemU32Ptr(0x5D4594, 1568364) = nox_xxx_getNameId_4E3AA0("CurePoisonPotion");
		*getMemU32Ptr(0x5D4594, 1568368) = nox_xxx_getNameId_4E3AA0("HastePotion");
		*getMemU32Ptr(0x5D4594, 1568372) = nox_xxx_getNameId_4E3AA0("InvisibilityPotion");
		*getMemU32Ptr(0x5D4594, 1568376) = nox_xxx_getNameId_4E3AA0("ShieldPotion");
		*getMemU32Ptr(0x5D4594, 1568380) = nox_xxx_getNameId_4E3AA0("VampirismPotion");
		*getMemU32Ptr(0x5D4594, 1568384) = nox_xxx_getNameId_4E3AA0("FireProtectPotion");
		*getMemU32Ptr(0x5D4594, 1568388) = nox_xxx_getNameId_4E3AA0("ShockProtectPotion");
		*getMemU32Ptr(0x5D4594, 1568392) = nox_xxx_getNameId_4E3AA0("PoisonProtectPotion");
		*getMemU32Ptr(0x5D4594, 1568396) = nox_xxx_getNameId_4E3AA0("InvulnerabilityPotion");
		*getMemU32Ptr(0x5D4594, 1568400) = nox_xxx_getNameId_4E3AA0("InfravisionPotion");
		*getMemU32Ptr(0x5D4594, 1568404) = nox_xxx_getNameId_4E3AA0("InfinitePainWand");
	}
	if (!a1 || !(*(uint8_t*)(a1 + 8) & 4)) {
		return 1;
	}
	if (nox_xxx_inventoryCountObjects_4E7D30(a1, *getMemIntPtr(0x5D4594, 1568356)) > 9 ||
		nox_xxx_inventoryCountObjects_4E7D30(a1, *getMemIntPtr(0x5D4594, 1568360)) > 9 ||
		nox_xxx_inventoryCountObjects_4E7D30(a1, *getMemIntPtr(0x5D4594, 1568364)) > 9 ||
		nox_xxx_inventoryCountObjects_4E7D30(a1, *getMemIntPtr(0x5D4594, 1568368)) > 9 ||
		nox_xxx_inventoryCountObjects_4E7D30(a1, *getMemIntPtr(0x5D4594, 1568372)) > 9 ||
		nox_xxx_inventoryCountObjects_4E7D30(a1, *getMemIntPtr(0x5D4594, 1568376)) > 9 ||
		nox_xxx_inventoryCountObjects_4E7D30(a1, *getMemIntPtr(0x5D4594, 1568380)) > 9 ||
		nox_xxx_inventoryCountObjects_4E7D30(a1, *getMemIntPtr(0x5D4594, 1568384)) > 9 ||
		nox_xxx_inventoryCountObjects_4E7D30(a1, *getMemIntPtr(0x5D4594, 1568388)) > 9 ||
		nox_xxx_inventoryCountObjects_4E7D30(a1, *getMemIntPtr(0x5D4594, 1568392)) > 9 ||
		nox_xxx_inventoryCountObjects_4E7D30(a1, *getMemIntPtr(0x5D4594, 1568396)) > 9 ||
		nox_xxx_inventoryCountObjects_4E7D30(a1, *getMemIntPtr(0x5D4594, 1568400)) > 9) {
		return 0;
	}
	v3 = nox_xxx_gamedataGetFloat_419D40("ForceOfNatureStaffLimit");
	v1 = nox_float2int(v3);
	return nox_xxx_inventoryCountObjects_4E7D30(a1, *getMemIntPtr(0x5D4594, 1568404)) <= v1;
}

//----- (004F2E70) --------------------------------------------------------
int nox_xxx_spell_4F2E70(int a1) {
	int v1;            // eax
	int v2;            // esi
	unsigned char* v3; // ecx

	v1 = *getMemU32Ptr(0x587000, 207108);
	v2 = 0;
	if (*getMemU32Ptr(0x587000, 207108)) {
		v3 = getMemAt(0x587000, 207108);
		while (v1 != a1 || !*((uint32_t*)v3 + 1)) {
			v1 = *((uint32_t*)v3 + 3);
			v3 += 12;
			if (!v1) {
				goto LABEL_8;
			}
		}
		v2 = 1;
	}
LABEL_8:
	if (a1 == 46 || a1 == 47 || a1 == 48 || a1 == 49 || a1 == 122 || a1 == 123 || a1 == 124 || a1 == 125) {
		v2 = 1;
	}
	return a1 >= 75 && a1 <= 114 || v2;
}

//----- (004F2EF0) --------------------------------------------------------
int sub_4F2EF0(int a1) {
	int v1;            // eax
	int v2;            // edi
	unsigned char* v3; // ecx
	int* v4;           // eax
	unsigned char* v5; // edx
	int v6;            // ecx
	int* v7;           // eax
	int v8;            // ecx

	v1 = *getMemU32Ptr(0x587000, 207796);
	v2 = 0;
	if (*getMemU32Ptr(0x587000, 207796)) {
		v3 = getMemAt(0x587000, 207796);
		while (v1 != a1 || !*((uint32_t*)v3 + 1)) {
			v1 = *((uint32_t*)v3 + 3);
			v3 += 12;
			if (!v1) {
				goto LABEL_8;
			}
		}
		v2 = 1;
	}
LABEL_8:
	v4 = *(int**)getMemAt(0x587000, 207032);
	v5 = getMemAt(0x587000, 207032);
	if (*getMemU32Ptr(0x587000, 207032)) {
		do {
			v6 = *v4;
			v7 = v4 + 1;
			if (v6) {
				while (1) {
					v8 = *v7;
					if (*v7 == a1) {
						break;
					}
					++v7;
					if (!v8) {
						goto LABEL_14;
					}
				}
				v2 = 1;
			}
		LABEL_14:
			v4 = (int*)*((uint32_t*)v5 + 1);
			v5 += 4;
		} while (v4);
	}
	return v2 != 0;
}

//----- (004F2F70) --------------------------------------------------------
int nox_xxx_playerTryEquip_4F2F70(uint32_t* a1, nox_object_t* item) {
	int result; // eax

	if (nox_xxx_playerEquipWeapon_53A420(a1, item, 1, 1) ||
		(result = nox_xxx_playerEquipArmor_53E650(a1, item, 1, 1)) != 0) {
		result = 1;
	}
	return result;
}

//----- (004F2FB0) --------------------------------------------------------
int nox_xxx_playerTryDequip_4F2FB0(uint32_t* a1, const nox_object_t* object) {
	int result; // eax

	if (nox_xxx_playerDequipWeapon_53A140(a1, object, 1, 1) || (result = sub_53E430(a1, object, 1, 1)) != 0) {
		result = 1;
	}
	return result;
}

//----- (004F2FF0) --------------------------------------------------------
int nox_xxx_itemApplyEngageEffect_4F2FF0(nox_object_t* item, int a2) {
	int v2;                   // ebp
	int* v3;                  // esi
	int result;               // eax
	int (*v5)(int, int, int); // ecx

	v2 = 2;
	v3 = (int*)(*(uint32_t*)&item->field_173 + 8);
	do {
		result = *v3;
		if (*v3) {
			v5 = *(int (**)(int, int, int))(result + 112);
			if (v5) {
				result = v5(result, a2, item);
			}
		}
		++v3;
		--v2;
	} while (v2);
	return result;
}

//----- (004F3030) --------------------------------------------------------
int nox_xxx_itemApplyDisengageEffect_4F3030(const nox_object_t* object, int a2) {
	int v2;                   // ebp
	int* v3;                  // esi
	int result;               // eax
	int (*v5)(int, int, int); // ecx

	v2 = 2;
	v3 = (int*)(*(uint32_t*)&object->field_173 + 8);
	do {
		result = *v3;
		if (*v3) {
			v5 = *(int (**)(int, int, int))(result + 116);
			if (v5) {
				result = v5(result, a2, object);
			}
		}
		++v3;
		--v2;
	} while (v2);
	return result;
}

//----- (004F3070) --------------------------------------------------------
void nox_xxx_inventoryPutImpl_4F3070(int a1, nox_object_t* item, int a3) {
	int v3; // ebp
	int v4; // eax
	int v5; // ebx
	int i;  // eax
	int v7; // ecx

	v3 = 0;
	if (a1 && item && !(*(uint8_t*)(a1 + 16) & 0x20) && !(item->flags & 0x20)) {
		*(uint32_t*)&item->field_125 = 0;
		*(uint32_t*)&item->field_124 = *(uint32_t*)(a1 + 504);
		v4 = *(uint32_t*)(a1 + 504);
		if (v4) {
			*(uint32_t*)(v4 + 500) = item;
		}
		*(uint32_t*)(a1 + 504) = item;
		*(uint32_t*)&item->field_123 = a1;
		nox_xxx_unitSetOwner_4EC290(a1, item);
		if (*(uint8_t*)(a1 + 8) & 4) {
			v5 = *(uint32_t*)(*(uint32_t*)(a1 + 748) + 276);
			if (a3) {
				nox_xxx_netReportPickup_4D8A60(*(unsigned char*)(v5 + 2064), item);
			}
			nox_xxx_protect_56FBF0(*(uint32_t*)(v5 + 4632), item);
			for (i = *(uint32_t*)(a1 + 504); i; v3 += v7) {
				v7 = *(unsigned char*)(i + 488);
				i = *(uint32_t*)(i + 496);
			}
			*(uint32_t*)(v5 + 3656) = v3 > *(unsigned short*)(a1 + 490);
		}
		if (*(uint8_t*)&item->obj_class & 0x40) {
			nox_xxx_aud_501960(820, a1, 0, 0);
		}
	}
}

//----- (004F3180) --------------------------------------------------------
extern int nox_cheat_allowall;

bool nox_xxx_playerCheckStrength_4F3180(nox_object_t* a1p, nox_object_t* item) {
	int a1 = a1p;
	if (nox_cheat_allowall) {
		return 1;
	}
	int v2;       // esi
	uint32_t* v3; // eax
	bool result;  // al

	if (*(uint8_t*)(a1 + 8) & 4 &&
		((v2 = nox_xxx_unitGetStrength_4F9FD0(a1), !(*(uint32_t*)&item->obj_class & 0x2000000))
			 ? (v3 = nox_xxx_getProjectileClassById_413250(*(unsigned short*)&item->typ_ind))
			 : (v3 = nox_xxx_equipClothFindDefByTT_413270(*(unsigned short*)&item->typ_ind)),
		 v3)) {
		result = v2 >= *((unsigned short*)v3 + 30);
	} else {
		result = 0;
	}
	return result;
}

//----- (004F31E0) --------------------------------------------------------
int nox_xxx_pickupDefault_4F31E0(int a1, nox_object_t* item, int a3) {
	int v3;     // eax
	int v4;     // edi
	char* v6;   // eax
	int v7;     // ecx
	int result; // eax
	int v9;     // eax
	int i;      // ecx
	int v11;    // edx
	int v12;    // esi
	int v13;    // esi

	v3 = nox_common_gameFlags_check_40A5C0(4096);
	v4 = a1;
	if (v3 || !nox_xxx_servObjectHasTeam_419130(&item->field_12) ||
		nox_xxx_servCompareTeams_419150(v4 + 48, &item->field_12) ||
		(v6 = nox_xxx_clientGetTeamColor_418AB0(*(unsigned char*)&item->field_13)) == 0) {
		if (*(uint32_t*)&item->field_123) {
			result = 0;
		} else if (*(uint16_t*)(v4 + 490)) {
			v9 = *(uint32_t*)(v4 + 504);
			for (i = 0; v9; i += v11) {
				v11 = *(unsigned char*)(v9 + 488);
				v9 = *(uint32_t*)(v9 + 496);
			}
			if (2 * *(unsigned short*)(v4 + 490) - i >= *(unsigned char*)&item->field_122_0) {
				if ((*(uint8_t*)&item->obj_class & 0x10) != 16 ||
					((v12 = nox_xxx_inventoryCountObjects_4E7D30(v4, *(unsigned short*)&item->typ_ind),
					  !nox_common_gameFlags_check_40A5C0(6144))
						 ? (v13 = v12 - 3)
						 : (v13 = v12 - 9),
					 v13 < 0)) {
					nox_xxx_servFinalizeDelObject_4DADE0(item);
					nox_xxx_inventoryPutImpl_4F3070(v4, item, a3);
					result = 1;
				} else {
					nox_xxx_netPriMsgToPlayer_4DA2C0(v4, "pickup.c:MaxSameItem", 0);
					result = 0;
				}
			} else {
				nox_xxx_netPriMsgToPlayer_4DA2C0(v4, "pickup.c:CarryingTooMuch", 0);
				result = 0;
			}
		} else {
			result = 0;
		}
	} else {
		if (*(uint8_t*)(v4 + 8) & 4) {
			v7 = *(uint32_t*)(v4 + 748);
			a1 = (unsigned char)v6[56];
			nox_xxx_netInformTextMsg_4DA0F0(*(unsigned char*)(*(uint32_t*)(v7 + 276) + 2064), 16, &a1);
		}
		result = 0;
	}
	return result;
}

//----- (004F3350) --------------------------------------------------------
int nox_xxx_pickupFood_4F3350(int a1, int a2, int a3) {
	int v4;            // ebx
	unsigned char* v5; // eax

	if (!a1 || !a2) {
		return 0;
	}
	if (!sub_419E60(a1) && !(*(uint8_t*)(a2 + 12) & 0x84)) {
		(*(void (**)(int, int))(a2 + 732))(a1, a2);
	}
	if (*(uint8_t*)(a2 + 16) & 0x20) {
		return 1;
	}
	v4 = nox_xxx_pickupDefault_4F31E0(a1, a2, a3);
	if (v4) {
		v5 = getMemAt(0x587000, 215640);
		if (*getMemU16Ptr(0x587000, 215646)) {
			while (!(*(uint32_t*)(a2 + 12) & *(uint32_t*)v5) && !(*((uint16_t*)v5 + 2) & *(uint16_t*)(a2 + 24))) {
				v5 += 8;
				if (!*((uint16_t*)v5 + 3)) {
					return v4;
				}
			}
			nox_xxx_aud_501960(*((unsigned short*)v5 + 3), a1, 0, 0);
		}
	}
	return v4;
}

//----- (004F3400) --------------------------------------------------------
int sub_4F3400(int a1, int a2, int a3) {
	int v3;      // ebp
	int result;  // eax
	int v5;      // ebx
	char v6[10]; // [esp+Ch] [ebp-Ch]

	v3 = *(uint32_t*)(a2 + 748);
	if (!(*(uint8_t*)(a1 + 8) & 4)) {
		return 0;
	}
	v5 = nox_xxx_pickupDefault_4F31E0(a1, a2, a3);
	if (v5) {
		*(uint32_t*)(*(uint32_t*)(a1 + 748) + 264) = nox_frame_xxx_2598000;
		nox_xxx_unitSetOwner_4EC290(a1, a2);
		nox_xxx_buffApplyTo_4FF380(a1, 30, 0, 5);
		nox_xxx_aud_501960(313, a1, 0, 0);
		*(uint32_t*)&v6[2] = *(uint32_t*)(a1 + 36);
		if (nox_xxx_servObjectHasTeam_419130(a1 + 48)) {
			*(uint32_t*)&v6[6] = *(unsigned char*)(a1 + 52);
		} else {
			*(uint32_t*)&v6[6] = 0;
		}
		nox_xxx_netInformTextMsg2_4DA180(10, v6);
		nox_xxx_netUnmarkMinimapSpec_417470(a2, 1);
	}
	result = v5;
	*(uint32_t*)(v3 + 4) = 0;
	return result;
}

//----- (004F34D0) --------------------------------------------------------
int nox_xxx_pickupUse_4F34D0(int a1, int a2, int a3) {
	int result; // eax

	nox_xxx_useByNetCode_53F8E0(a1, a2);
	if (*(uint8_t*)(a2 + 16) & 0x20) {
		result = 1;
	} else {
		result = nox_xxx_pickupDefault_4F31E0(a1, a2, a3);
	}
	return result;
}

//----- (004F3510) --------------------------------------------------------
int nox_xxx_pickupTrap_4F3510(int a1, int a2, int a3) {
	int v3;     // edi
	int result; // eax

	if (nox_xxx_unitHasThatParent_4EC4F0(a2, a1)) {
		v3 = nox_xxx_pickupDefault_4F31E0(a1, a2, a3);
		if (v3) {
			nox_xxx_aud_501960(824, a1, 0, 0);
		}
		result = v3;
	} else {
		if (*(uint8_t*)(a1 + 8) & 4) {
			nox_xxx_aud_501960(925, a1, 2, *(uint32_t*)(a1 + 36));
		}
		result = 0;
	}
	return result;
}

//----- (004F3580) --------------------------------------------------------
int nox_xxx_pickupTreasure_4F3580(int a1, int a2, int a3) {
	int v3;   // edi
	int v4;   // edi
	char* v5; // ebx
	int j;    // esi
	int i;    // edi

	if (!nox_xxx_pickupDefault_4F31E0(a1, a2, a3)) {
		return 0;
	}
	if (!(*(uint8_t*)(a1 + 8) & 4)) {
		return 1;
	}
	v3 = *(uint32_t*)(a1 + 748);
	if (!nox_common_gameFlags_check_40A5C0(64)) {
		return 1;
	}
	nox_xxx_aud_501960(307, a1, 0, 0);
	++*(uint32_t*)(*(uint32_t*)(v3 + 276) + 2152);
	*(uint32_t*)(*(uint32_t*)(v3 + 276) + 2156) = nox_xxx_scavengerTreasureMax_4D1600();
	nox_xxx_scavengerHuntReport_4D8CD0(a1);
	if (!nox_xxx_servObjectHasTeam_419130(a1 + 48)) {
		if (*(uint32_t*)(*(uint32_t*)(v3 + 276) + 2152) == nox_xxx_scavengerTreasureMax_4D1600()) {
			nox_xxx_setGameFlags_40A4D0(8);
			nox_xxx_changeScore_4D8E90(a1, 1);
			nox_xxx_netReportLesson_4D8EF0(a1);
			for (i = nox_xxx_getFirstPlayerUnit_4DA7C0(); i; i = nox_xxx_getNextPlayerUnit_4DA7F0(i)) {
				if (i != a1) {
					nox_xxx_playerIncrementElimDeath_4D8D40(i);
					nox_xxx_netReportLesson_4D8EF0(i);
				}
			}
		}
		return 1;
	}
	v4 = 0;
	v5 = nox_xxx_clientGetTeamColor_418AB0(*(unsigned char*)(a1 + 52));
	if (v5) {
		for (j = nox_xxx_getFirstPlayerUnit_4DA7C0(); j; j = nox_xxx_getNextPlayerUnit_4DA7F0(j)) {
			if (nox_xxx_teamCompare2_419180(j + 48, v5[57])) {
				v4 += *(uint32_t*)(*(uint32_t*)(*(uint32_t*)(j + 748) + 276) + 2152);
			}
		}
		if (v4 == nox_xxx_scavengerTreasureMax_4D1600()) {
			nox_xxx_setGameFlags_40A4D0(8);
		}
	}
	return 1;
}

//----- (004F36F0) --------------------------------------------------------
int nox_xxx_inventoryServPlace_4F36F0(int a1, int a2, int a3, int a4) {
	int v4;                        // eax
	int (*v5)(int, int, int, int); // eax
	int v6;                        // eax
	int v7;                        // ebx
	int v8;                        // eax

	if (!a1) {
		return 0;
	}
	if (!a2) {
		return 0;
	}
	if (!*(uint16_t*)(a1 + 490)) {
		return 0;
	}
	if (*(uint8_t*)(a2 + 16) & 0x20) {
		return 0;
	}
	v4 = *(uint32_t*)(a1 + 16);
	if ((v4 & 0x8000) != 0 || !nox_xxx_getUnitDefDd10_4E3BA0(*(unsigned short*)(a2 + 4)) ||
		!(*(uint8_t*)(a1 + 8) & 6)) {
		return 0;
	}
	v5 = *(int (**)(int, int, int, int))(a2 + 708);
	if (v5) {
		v6 = v5(a1, a2, a3, a4);
	} else {
		v6 = nox_xxx_pickupDefault_4F31E0(a1, a2, a3);
	}
	v7 = v6;
	if (v6) {
		v8 = *(uint32_t*)(a2 + 16);
		if (v8 & 0x40) {
			LOBYTE(v8) = v8 & 0xBF;
			*(uint32_t*)(a2 + 16) = v8;
			if (*(uint32_t*)(a2 + 696)) {
				sub_5117F0(a2);
			}
		}
		if (*(int*)(a2 + 768) != -1) {
			nox_xxx_scriptCallByEventBlock_502490((int*)(a2 + 764), a1, a2, 18);
			*(uint32_t*)(a2 + 768) = -1;
		}
	}
	return v7;
}

//----- (004F37D0) --------------------------------------------------------
int nox_xxx_pickupPotion_4F37D0(int a1, int a2, int a3) {
	int v3;     // ebx
	int* v4;    // eax
	int v5;     // edi
	char v7;    // al
	double v8;  // st7
	int v9;     // ebp
	char v10;   // al
	double v11; // st7
	int v12;    // eax
	int v13;    // edi
	float v14;  // [esp+0h] [ebp-18h]
	float v15;  // [esp+4h] [ebp-14h]
	int v16;    // [esp+14h] [ebp-4h]
	int v17;    // [esp+20h] [ebp+8h]

	v3 = a2;
	v4 = *(int**)(a2 + 736);
	v16 = 0;
	v5 = *v4;
	v17 = *v4;
	if (nox_common_gameFlags_check_40A5C0(0x2000) && !nox_common_gameFlags_check_40A5C0(4096) &&
		*(uint8_t*)(a1 + 8) & 4 &&
		!nox_xxx_playerClassCanUseItem_57B3D0(v3, *(uint8_t*)(*(uint32_t*)(*(uint32_t*)(a1 + 748) + 276) + 2251))) {
		nox_xxx_netPriMsgToPlayer_4DA2C0(a1, "pickup.c:ObjectEquipClassFail", 0);
		nox_xxx_aud_501960(925, a1, 2, *(uint32_t*)(a1 + 36));
		return 0;
	}
	if (sub_419E60(a1)) {
		goto LABEL_36;
	}
	if (*(uint8_t*)(v3 + 12) & 0x10 && *(uint32_t*)(a1 + 556)) {
		if (!(*(uint8_t*)(a1 + 8) & 4)) {
			goto LABEL_17;
		}
		v7 = *(uint8_t*)(*(uint32_t*)(*(uint32_t*)(a1 + 748) + 276) + 2251);
		if (v7) {
			if (v7 == 1) {
				v8 = (double)v17 * *(float*)&nox_xxx_wizardMaxHealth_587000_312816;
			} else {
				if (v7 != 2) {
					goto LABEL_17;
				}
				v8 = (double)v17 * *(float*)&nox_xxx_conjurerMaxHealth_587000_312800;
			}
		} else {
			v8 = (double)v17 * *(float*)&nox_xxx_warriorMaxHealth_587000_312784;
		}
		v15 = v8;
		v5 = nox_float2int(v15);
		v17 = v5;
	LABEL_17:
		if (v5 + **(unsigned short**)(a1 + 556) < *(unsigned short*)(*(uint32_t*)(a1 + 556) + 4)) {
			nox_xxx_unitAdjustHP_4EE460(a1, v5);
			nox_xxx_aud_501960(754, a1, 0, 0);
			v16 = 1;
		}
	}
	if (!(*(uint8_t*)(v3 + 12) & 0x20) || !(*(uint8_t*)(a1 + 8) & 4)) {
		goto LABEL_30;
	}
	v9 = *(uint32_t*)(a1 + 748);
	v10 = *(uint8_t*)(*(uint32_t*)(v9 + 276) + 2251);
	if (v10) {
		if (v10 == 1) {
			v11 = (double)v17 * *(float*)&nox_xxx_wizardMaximumMana_587000_312820;
		} else {
			if (v10 != 2) {
				goto LABEL_28;
			}
			v11 = (double)v17 * *(float*)&nox_xxx_conjurerMaxMana_587000_312804;
		}
	} else {
		v11 = (double)v17 * *(float*)&nox_xxx_warriorMaxMana_587000_312788;
	}
	v14 = v11;
	v5 = nox_float2int(v14);
LABEL_28:
	if (v5 + *(unsigned short*)(v9 + 4) < *(unsigned short*)(v9 + 8)) {
		nox_xxx_playerManaAdd_4EEB80(a1, v5);
		nox_xxx_aud_501960(755, a1, 0, 0);
		v16 = 1;
	}
LABEL_30:
	if (*(uint8_t*)(v3 + 12) & 0x40 && *(uint8_t*)(a1 + 8) & 4 && *(uint8_t*)(a1 + 540)) {
		nox_xxx_removePoison_4EE9D0(a1);
		v12 = nox_xxx_spellGetAud44_424800(14, 1);
		nox_xxx_aud_501960(v12, a1, 0, 0);
		nox_xxx_delayedDeleteObject_4E5CC0(v3);
		return 1;
	}
	if (v16) {
		nox_xxx_delayedDeleteObject_4E5CC0(v3);
		return 1;
	}
LABEL_36:
	nox_xxx_decay_5116F0(v3);
	v13 = nox_xxx_pickupDefault_4F31E0(a1, v3, a3);
	if (v13 == 1) {
		nox_xxx_aud_501960(832, a1, 0, 0);
	}
	return v13;
}

//----- (004F3B00) --------------------------------------------------------
int nox_xxx_pickupAmmo_4F3B00(int a1, nox_object_t* item, int a3, int a4) {
	int v5;             // eax
	int v6;             // ebx
	int v7;             // esi
	uint32_t* v8;       // edi
	char* v9;           // eax
	uint32_t* v10;      // ecx
	int v11;            // edx
	int v12;            // ebp
	int v13;            // edi
	char v15;           // bl
	char v16;           // dl
	char v17;           // dl
	int v18;            // [esp+10h] [ebp-10h]
	unsigned char* v19; // [esp+14h] [ebp-Ch]
	uint32_t* v20;      // [esp+18h] [ebp-8h]
	int v21;            // [esp+1Ch] [ebp-4h]

	v5 = nox_xxx_weaponInventoryEquipFlags_415820(item);
	v6 = a1;
	v18 = v5;
	if (!(*(uint8_t*)(a1 + 8) & 4)) {
		return sub_53A720(v6, item, a3, a4);
	}
	v21 = *(uint32_t*)(a1 + 748);
	if (!(v5 & 0x82)) {
		return sub_53A720(v6, item, a3, a4);
	}
	v7 = *(uint32_t*)(a1 + 504);
	v8 = *(uint32_t**)&item->field_173;
	v20 = *(uint32_t**)&item->field_173;
	v19 = *(unsigned char**)&item->field_184;
	if (!v7) {
		return sub_53A720(v6, item, a3, a4);
	}
	while (1) {
		if (*(uint16_t*)(v7 + 4) != *(uint16_t*)&item->typ_ind || !(*(uint32_t*)(v7 + 8) & 0x1000000) ||
			!(nox_xxx_weaponInventoryEquipFlags_415820(v7) & v18)) {
			goto LABEL_15;
		}
		v9 = *(char**)(v7 + 736);
		v10 = v8;
		v11 = *(uint32_t*)(v7 + 692) - (uint32_t)v8;
		v12 = 1;
		v13 = 4;
		do {
			if (*(uint32_t*)((char*)v10 + v11) != *v10) {
				v12 = 0;
			}
			++v10;
			--v13;
		} while (v13);
		if (v12 == 1 && !v9[2] && *v19 + (unsigned char)*v9 <= 250) {
			break;
		}
		v6 = a1;
		v8 = v20;
	LABEL_15:
		v7 = *(uint32_t*)(v7 + 496);
		if (!v7) {
			return sub_53A720(v6, item, a3, a4);
		}
	}
	v15 = v19[1] + v9[1];
	v16 = *v9;
	v9[1] = v15;
	v17 = *v19 + v16;
	*v9 = v17;
	nox_xxx_netReportCharges_4D82B0(*(unsigned char*)(*(uint32_t*)(v21 + 276) + 2064), (uint32_t*)v7, v15, v17);
	nox_xxx_delayedDeleteObject_4E5CC0(item);
	sub_53A6C0(a1, item);
	return 1;
}

//----- (004F3C60) --------------------------------------------------------
int nox_xxx_pickupSpellbook_4F3C60(int a1, int a2, int a3) {
	int v4; // ebx

	if (nox_common_gameFlags_check_40A5C0(6144)) {
		nox_xxx_useByNetCode_53F8E0(a1, a2);
	}
	if (*(uint8_t*)(a2 + 16) & 0x20) {
		return 1;
	}
	v4 = nox_xxx_pickupDefault_4F31E0(a1, a2, a3);
	if (v4) {
		if (*(uint8_t*)(a2 + 12) & 1) {
			nox_xxx_aud_501960(826, a1, 0, 0);
			return v4;
		}
		nox_xxx_aud_501960(828, a1, 0, 0);
	}
	return v4;
}

//----- (004F3CE0) --------------------------------------------------------
int nox_xxx_pickupAbilitybook_4F3CE0(int a1, int a2, int a3) {
	int v4; // esi

	if (nox_common_gameFlags_check_40A5C0(6144)) {
		nox_xxx_useByNetCode_53F8E0(a1, a2);
	}
	if (*(uint8_t*)(a2 + 16) & 0x20) {
		return 1;
	}
	v4 = nox_xxx_pickupDefault_4F31E0(a1, a2, a3);
	if (v4) {
		nox_xxx_aud_501960(826, a1, 0, 0);
	}
	return v4;
}

//----- (004F3D50) --------------------------------------------------------
int sub_4F3D50(int a1, int a2, int a3) {
	int v3;            // ebx
	short v4;          // ax
	unsigned char* v5; // ecx

	if (!a1 || !a2) {
		return 0;
	}
	v3 = nox_xxx_pickupDefault_4F31E0(a1, a2, a3);
	if (v3) {
		v4 = *getMemU16Ptr(0x973F18, 15976);
		v5 = getMemAt(0x973F18, 15976);
		if (*getMemI16Ptr(0x973F18, 15976) != -1) {
			while (v4 != *(uint16_t*)(a2 + 4)) {
				v4 = *((uint16_t*)v5 + 2);
				v5 += 4;
				if (v4 == -1) {
					return v3;
				}
			}
			nox_xxx_aud_501960(*((unsigned short*)v5 + 1), a1, 0, 0);
		}
	}
	return v3;
}

//----- (004F3DD0) --------------------------------------------------------
int sub_4F3DD0(int a1, int a2) {
	if (!(*(uint8_t*)(a1 + 8) & 4)) {
		return 0;
	}
	++*(uint32_t*)(*(uint32_t*)(a1 + 748) + 320);
	nox_xxx_delayedDeleteObject_4E5CC0(a2);
	nox_xxx_aud_501960(1004, a1, 0, 0);
	return 1;
}

//----- (004F3E30) --------------------------------------------------------
int nox_xxx_xfer_4F3E30(unsigned short a1, int a2, int a3) {
	int v3;            // ebp
	unsigned short v4; // si
	uint32_t* v5;      // eax
	uint32_t* v6;      // esi
	int v7;            // edx
	int v8;            // eax
	int v10;           // [esp+10h] [ebp-10Ch]
	int v11;           // [esp+14h] [ebp-108h]
	int v12;           // [esp+18h] [ebp-104h]
	char v13[256];     // [esp+1Ch] [ebp-100h]

	v3 = 0;
	if (a3 <= 0) {
		return 1;
	}
	while (1) {
		if (a1 < 0x3Cu) {
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v10, 1u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(v13, (unsigned char)v10);
			v13[(unsigned char)v10] = 0;
			v4 = nox_xxx_getNameId_4E3AA0(v13);
			if (!v4) {
				return 0;
			}
		} else {
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v11, 2u);
			v4 = nox_xxx_objectTOCgetTT_42C2B0(v11);
			if (!v4) {
				return 0;
			}
		}
		nox_xxx_fileCryptReadCrcMB_426C20(&v12, 4u);
		v5 = nox_xxx_newObjectWithTypeInd_4E3450(v4);
		v6 = v5;
		if (!v5 || !((int (*)(uint32_t*, uint32_t))v5[176])(v5, 0)) {
			break;
		}
		v7 = *(uint32_t*)(a2 + 504);
		v6[125] = 0;
		v6[124] = v7;
		v8 = *(uint32_t*)(a2 + 504);
		if (v8) {
			*(uint32_t*)(v8 + 500) = v6;
		}
		++v3;
		*(uint32_t*)(a2 + 504) = v6;
		v6[123] = a2;
		if (v3 >= a3) {
			return 1;
		}
	}
	return 0;
}
// 4F3E30: using guessed type char var_100[256];

//----- (004F3F50) --------------------------------------------------------
int nox_xxx_servMapLoadPlaceObj_4F3F50(nox_object_t* a1p, int a2, void* a3p) {
	int a1 = a1p;
	int* a3 = a3p;
	int v3;     // eax
	int v4;     // edi
	int result; // eax
	char* v6;   // eax
	int v7;     // eax
	int v8;     // edi

	if (nox_common_gameFlags_check_40A5C0(0x400000) || nox_xxx_getUnitDefDd10_4E3BA0(*(unsigned short*)(a1 + 4))) {
		if (a3) {
			v6 = nox_xxx_mapGetWallSize_426A70();
			*(float*)(a1 + 56) = *(float*)(a1 + 56) - (double)(int)(23 * *(uint32_t*)v6) + (double)*a3 - 11.0;
			*(float*)(a1 + 60) = *(float*)(a1 + 60) - (double)(int)(23 * *((uint32_t*)v6 + 1)) + (double)a3[1] - 11.0;
		}
		if (nox_common_gameFlags_check_40A5C0(0x400000)) {
			nox_xxx_unitAddToList_5048A0(a1);
			result = 1;
		} else if (nox_common_gameFlags_check_40A5C0(0x200000) || sub_4E3AD0(*(unsigned short*)(a1 + 4))) {
			nox_xxx_createAt_4DAA50(a1, a2, *(float*)(a1 + 56), *(float*)(a1 + 60));
			result = 1;
		} else {
			v7 = *(uint32_t*)(a1 + 504);
			if (v7) {
				do {
					v8 = *(uint32_t*)(v7 + 496);
					nox_xxx_objectFreeMem_4E38A0(v7);
					v7 = v8;
				} while (v8);
			}
			*(uint32_t*)(a1 + 504) = 0;
			nox_xxx_objectFreeMem_4E38A0(a1);
			result = 0;
		}
	} else {
		v3 = *(uint32_t*)(a1 + 504);
		if (v3) {
			do {
				v4 = *(uint32_t*)(v3 + 496);
				nox_xxx_objectFreeMem_4E38A0(v3);
				v3 = v4;
			} while (v4);
		}
		nox_xxx_objectFreeMem_4E38A0(a1);
		result = 0;
	}
	return result;
}

//----- (004F40A0) --------------------------------------------------------
char sub_4F40A0(int a1) {
	int v2;         // eax
	const char* v3; // esi

	if (a1) {
		if (*(uint32_t*)a1) {
			return -1;
		}
		if (*(uint32_t*)(a1 + 504)) {
			return -1;
		}
		if (*(uint32_t*)(a1 + 516)) {
			return -1;
		}
		if (*(uint8_t*)(a1 + 52)) {
			return -1;
		}
		v2 = nox_xxx_objectTypeByInd_4E3B70(*(unsigned short*)(a1 + 4));
		if ((*(uint32_t*)(a1 + 16) ^ *(uint32_t*)(v2 + 32)) & 0x11408162) {
			return -1;
		}
		if ((*(uint8_t*)(a1 + 20) ^ *(uint8_t*)(v2 + 36)) & 0x5E) {
			return -1;
		}
		if (nox_common_gameFlags_check_40A5C0(6291456)) {
			v3 = *(const char**)(a1 + 756);
			if (v3 && strlen(v3)) {
				return -1;
			}
		} else if (nox_common_gameFlags_check_40A5C0(1) && *(int*)(a1 + 768) != -1) {
			return -1;
		}
	}
	return 0;
}

//----- (004F4170) --------------------------------------------------------
int nox_xxx_readObjectOldVer_4F4170(int a1, int a2, int a3) {
	uint8_t** v3;       // esi
	uint8_t* v4;        // ebx
	unsigned int v5;    // edx
	uint8_t* v6;        // eax
	int v7;             // eax
	int v8;             // ebx
	int v9;             // ebp
	uint32_t* v10;      // edi
	uint8_t* v11;       // edx
	int result;         // eax
	uint8_t* v13;       // eax
	int* v14;           // ebx
	uint8_t* v15;       // edi
	unsigned short v16; // ax
	uint8_t* j;         // edi
	unsigned int i;     // edi
	int v19;            // [esp+10h] [ebp-18h]
	int v20;            // [esp+14h] [ebp-14h]
	int v21;            // [esp+18h] [ebp-10h]
	int v22;            // [esp+1Ch] [ebp-Ch]
	int v23[2];         // [esp+20h] [ebp-8h]

	v3 = (uint8_t**)a1;
	LOBYTE(v20) = 0;
	if (nox_xxx_cryptGetXxx() == 1) {
		*(uint32_t*)(a1 + 136) = 0;
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)v3 + 40, 4u);
	v4 = v3[4];
	v21 = (unsigned int)v3[4] & 0x11408162;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v21, 4u);
	v5 = (unsigned int)v3[4] & 0xEEBF7E9D;
	v3[4] = (uint8_t*)v5;
	v6 = (uint8_t*)v5;
	if ((unsigned char)v4 & 0x40) {
		LOBYTE(v6) = v5 | 0x40;
		v3[4] = v6;
	}
	v7 = v21;
	v3[4] = (uint8_t*)(v21 | (unsigned int)v3[4]);
	if (nox_xxx_cryptGetXxx() == 1) {
		if (v7 & 0x1000000) {
			nox_xxx_objectSetOn_4E75B0((int)v3);
		} else {
			nox_xxx_objectSetOff_4E7600((int)v3);
		}
	}
	v8 = a3;
	v9 = a2;
	if (nox_xxx_cryptGetXxx()) {
		if (a3 < 40 || a2 < 4) {
			nox_xxx_fileReadWrite_426AC0_file3_fread(v23, 8u);
			v10 = v3 + 14;
			*((float*)v3 + 14) = (double)v23[0];
			*((float*)v3 + 15) = (double)v23[1];
		} else {
			v10 = v3 + 14;
			nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)v3 + 56, 4u);
			nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)v3 + 60, 4u);
		}
		v11 = (uint8_t*)v10[1];
		v3[16] = (uint8_t*)*v10;
		v3[17] = v11;
	} else {
		nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)v3 + 56, 4u);
		nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)v3 + 60, 4u);
	}
	if (v8 >= 10) {
		if (*v3) {
			LOBYTE(v19) = strlen(*v3);
		} else {
			LOBYTE(v19) = 0;
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v19, 1u);
		if (nox_xxx_cryptGetXxx() == 1) {
			if ((uint8_t)v19) {
				result = (int)calloc(1, (unsigned char)v19 + 1);
				*v3 = (uint8_t*)result;
				if (!result) {
					return result;
				}
			}
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread(*v3, (unsigned char)v19);
		if (*v3) {
			(*v3)[(unsigned char)v19] = 0;
		}
	}
	if (v8 >= 20) {
		nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)v3 + 52, 1u);
	}
	if (v8 >= 30) {
		v13 = v3[126];
		for (LOBYTE(v20) = 0; v13; LOBYTE(v20) = v20 + 1) {
			v13 = (uint8_t*)*((uint32_t*)v13 + 124);
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v20, 1u);
		if (nox_xxx_cryptGetXxx() == 1) {
			v3[34] = (uint8_t*)(unsigned char)v20;
		}
	}
	if (v8 >= 40) {
		v14 = (int*)(v3 + 11);
		nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)v3 + 44, 4u);
		if (!v3[11] && nox_xxx_cryptGetXxx() == 1 && !nox_common_gameFlags_check_40A5C0(0x200000) &&
			!nox_common_gameFlags_check_40A5C0(0x400000)) {
			*v14 = nox_server_NextObjectScriptID();
		}
		if (v9 >= 2) {
			v15 = v3[129];
			v16 = 0;
			a1 = 0;
			if (v15) {
				do {
					if (!(v15[16] & 0x20) && sub_4E3B80(*((unsigned short*)v15 + 2))) {
						++a1;
					}
					v15 = (uint8_t*)*((uint32_t*)v15 + 128);
				} while (v15);
				v16 = a1;
			}
			if (v9 < 5) {
				v22 = v16;
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v22, 4u);
				a1 = v22;
			} else {
				nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 2u);
			}
			if (nox_xxx_cryptGetXxx()) {
				for (i = 0; i < (unsigned short)a1; ++i) {
					nox_xxx_fileReadWrite_426AC0_file3_fread(&a3, 4u);
					if (!nox_common_gameFlags_check_40A5C0(0x200000) && !nox_common_gameFlags_check_40A5C0(0x400000)) {
						sub_516F90(*v14, a3);
					}
				}
			} else {
				for (j = v3[129]; j; j = (uint8_t*)*((uint32_t*)j + 128)) {
					if (!(j[16] & 0x20) && sub_4E3B80(*((unsigned short*)j + 2))) {
						nox_xxx_fileReadWrite_426AC0_file3_fread(j + 44, 4u);
					}
				}
			}
		}
		if (v9 >= 3) {
			v21 = (unsigned int)v3[5] & 0x5E;
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v21, 4u);
			nox_xxx_unitUnsetXStatus_4E4780((int)v3, 94);
			nox_xxx_unitSetXStatus_4E4800((int)v3, (int*)v21);
		}
	}
	return 1;
}

//----- (004F4530) --------------------------------------------------------
int nox_xxx_mapReadWriteObjData_4F4530(int* a1, int a2) {
	int* v2;          // esi
	int v3;           // edi
	int v4;           // ecx
	short v5;         // ax
	int result;       // eax
	int* v7;          // ebp
	int* v8;          // edi
	int v9;           // ecx
	int v10;          // ebx
	unsigned int v11; // edx
	unsigned int v12; // eax
	int v13;          // eax
	int v14;          // eax
	int v15;          // edi
	int k;            // edi
	unsigned int j;   // edi
	int v18;          // [esp+10h] [ebp-1Ch]
	int v19;          // [esp+14h] [ebp-18h]
	int i;            // [esp+18h] [ebp-14h]
	int v21;          // [esp+1Ch] [ebp-10h]
	int v22[2];       // [esp+20h] [ebp-Ch]
	int v23;          // [esp+28h] [ebp-4h]

	v2 = a1;
	v3 = a2;
	v4 = a1[34];
	v5 = 0;
	LOBYTE(v19) = 0;
	v18 = 0;
	v23 = v4;
	if (a2 >= 40 || !nox_xxx_cryptGetXxx()) {
		v18 = 64;
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v18, 2u);
		v5 = v18;
		if ((short)v18 > 64) {
			return 0;
		}
	}
	if (v3 < 40 || v5 < 61) {
		return nox_xxx_readObjectOldVer_4F4170((int)v2, v5, v3);
	}
	if (nox_xxx_cryptGetXxx() == 1) {
		v2[34] = 0;
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)v2 + 40, 4u);
	v7 = v2 + 11;
	nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)v2 + 44, 4u);
	if (!v2[11] && nox_xxx_cryptGetXxx() == 1 && !nox_common_gameFlags_check_40A5C0(0x200000) &&
		!nox_common_gameFlags_check_40A5C0(0x400000)) {
		*v7 = nox_server_NextObjectScriptID();
	}
	if (nox_xxx_cryptGetXxx()) {
		if ((short)v18 < 4) {
			nox_xxx_fileReadWrite_426AC0_file3_fread(v22, 8u);
			v8 = v2 + 14;
			*((float*)v2 + 14) = (double)v22[0];
			*((float*)v2 + 15) = (double)v22[1];
		} else {
			v8 = v2 + 14;
			nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)v2 + 56, 4u);
			nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)v2 + 60, 4u);
		}
		v9 = v8[1];
		v2[16] = *v8;
		v2[17] = v9;
	} else {
		nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)v2 + 56, 4u);
		nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)v2 + 60, 4u);
	}
	LOBYTE(a1) = sub_4F40A0((int)v2);
	nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 1u);
	if (!(uint8_t)a1) {
		return 1;
	}
	v10 = v2[4];
	v21 = v2[4] & 0x11408162;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v21, 4u);
	v11 = v2[4] & 0xEEBF7E9D;
	v2[4] = v11;
	v12 = v11;
	if (v10 & 0x40) {
		LOBYTE(v12) = v11 | 0x40;
		v2[4] = v12;
	}
	v13 = v21;
	v2[4] |= v21;
	if (nox_xxx_cryptGetXxx() == 1) {
		if (v13 & 0x1000000) {
			nox_xxx_objectSetOn_4E75B0((int)v2);
		} else {
			nox_xxx_objectSetOff_4E7600((int)v2);
		}
	}
	if (*v2) {
		LOBYTE(a2) = strlen((const char*)*v2);
	} else {
		LOBYTE(a2) = 0;
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread(&a2, 1u);
	if (nox_xxx_cryptGetXxx() != 1 || !(uint8_t)a2 ||
		(result = (int)calloc(1, (unsigned char)a2 + 1), (*v2 = result) != 0)) {
		nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)*v2, (unsigned char)a2);
		if (*v2) {
			*(uint8_t*)((unsigned char)a2 + *v2) = 0;
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)v2 + 52, 1u);
		v14 = v2[126];
		for (LOBYTE(v19) = 0; v14; LOBYTE(v19) = v19 + 1) {
			v14 = *(uint32_t*)(v14 + 496);
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v19, 1u);
		if (nox_xxx_cryptGetXxx() == 1) {
			v2[34] = (unsigned char)v19;
		}
		v15 = v2[129];
		for (i = 0; v15; v15 = *(uint32_t*)(v15 + 512)) {
			if (!(*(uint8_t*)(v15 + 16) & 0x20) && sub_4E3B80(*(unsigned short*)(v15 + 4))) {
				++i;
			}
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread(&i, 2u);
		if (nox_xxx_cryptGetXxx()) {
			for (j = 0; j < (unsigned short)i; ++j) {
				nox_xxx_fileReadWrite_426AC0_file3_fread(v22, 4u);
				if (!nox_common_gameFlags_check_40A5C0(0x200000) && !nox_common_gameFlags_check_40A5C0(0x400000)) {
					sub_516F90(*v7, v22[0]);
				}
			}
		} else {
			for (k = v2[129]; k; k = *(uint32_t*)(k + 512)) {
				if (!(*(uint8_t*)(k + 16) & 0x20) && sub_4E3B80(*(unsigned short*)(k + 4))) {
					nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(k + 44), 4u);
				}
			}
		}
		v21 = v2[5] & 0x5E;
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v21, 4u);
		nox_xxx_unitUnsetXStatus_4E4780((int)v2, 94);
		nox_xxx_unitSetXStatus_4E4800((int)v2, (int*)v21);
		if ((short)v18 < 63 || (result = nox_xxx_xferReadScriptHandler_4F5580((int)(v2 + 191), (char*)v2[189])) != 0) {
			if ((short)v18 >= 64) {
				v22[0] = v23 - nox_frame_xxx_2598000;
				nox_xxx_fileReadWrite_426AC0_file3_fread(v22, 4u);
				if (v22[0] > 0 && nox_xxx_cryptGetXxx() == 1) {
					if (v2[4] & 0x400000) {
						v2[32] = v22[0];
					}
				}
			}
			return 1;
		}
	}
	return result;
}

//----- (004F49A0) --------------------------------------------------------
int nox_xxx_XFerDefault_4F49A0(int a1) {
	int* v1;    // esi
	int v2;     // edi
	int result; // eax

	v1 = (int*)a1;
	v2 = *(uint32_t*)(a1 + 136);
	a1 = 60;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 2u);
	if ((short)a1 > 60) {
		return 0;
	}
	result = nox_xxx_mapReadWriteObjData_4F4530(v1, (short)a1);
	if (result) {
		if (!v1[34] || nox_xxx_cryptGetXxx() != 1 || (result = nox_xxx_xfer_4F3E30(a1, (int)v1, v1[34])) != 0) {
			v1[34] = v2;
			result = 1;
		}
	}
	return result;
}

//----- (004F4A20) --------------------------------------------------------
int nox_xxx_XFerSpellPagePedistal_4F4A20(int a1) {
	int v1;     // esi
	int v2;     // edi
	int result; // eax

	v1 = a1;
	v2 = *(uint32_t*)(a1 + 136);
	a1 = 60;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 2u);
	if ((short)a1 > 60) {
		return 0;
	}
	result = nox_xxx_mapReadWriteObjData_4F4530((int*)v1, (short)a1);
	if (result) {
		nox_xxx_fileReadWrite_426AC0_file3_fread(*(uint8_t**)(v1 + 700), 4u);
		if (!*(uint32_t*)(v1 + 136) || nox_xxx_cryptGetXxx() != 1 ||
			(result = nox_xxx_xfer_4F3E30(a1, v1, *(uint32_t*)(v1 + 136))) != 0) {
			*(uint32_t*)(v1 + 136) = v2;
			result = 1;
		}
	}
	return result;
}

//----- (004F4AB0) --------------------------------------------------------
int nox_xxx_XFerReadable_4F4AB0(int a1) {
	int* v1;    // esi
	int v2;     // ebx
	int v3;     // edi
	int result; // eax
	size_t v5;  // [esp+Ch] [ebp-4h]

	v1 = (int*)a1;
	v2 = *(uint32_t*)(a1 + 736);
	v3 = *(uint32_t*)(a1 + 136);
	v5 = strlen(*(const char**)(a1 + 736)) + 1;
	a1 = 60;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 2u);
	if ((short)a1 > 60) {
		return 0;
	}
	result = nox_xxx_mapReadWriteObjData_4F4530(v1, (short)a1);
	if (result) {
		if ((short)a1 >= 2) {
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v5, 4u);
			nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)v2, v5);
		} else {
			nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)v2, v5);
		}
		if (nox_xxx_cryptGetXxx() != 1 || (*(uint32_t*)(v2 + 256) = 0, !v1[34]) ||
			(result = nox_xxx_xfer_4F3E30(a1, (int)v1, v1[34])) != 0) {
			v1[34] = v3;
			result = 1;
		}
	}
	return result;
}

//----- (004F4B90) --------------------------------------------------------
int nox_xxx_XFerExit_4F4B90(int a1) {
	int* v1;     // ebp
	uint8_t* v2; // ebx
	int v3;      // edi
	int result;  // eax
	uint8_t* i;  // esi
	size_t v6;   // [esp+Ch] [ebp-4h]

	v1 = (int*)a1;
	v2 = *(uint8_t**)(a1 + 700);
	v3 = *(uint32_t*)(a1 + 136);
	v6 = strlen(*(const char**)(a1 + 700)) + 1;
	a1 = 60;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 2u);
	if ((short)a1 > 60) {
		return 0;
	}
	result = nox_xxx_mapReadWriteObjData_4F4530(v1, (short)a1);
	if (result) {
		if ((short)a1 >= 2) {
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v6, 4u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(v2, v6);
		} else if (nox_xxx_cryptGetXxx() == 1) {
			for (i = v2;; ++i) {
				nox_xxx_fileReadWrite_426AC0_file3_fread(i, 1u);
				if (!*i) {
					break;
				}
			}
		} else {
			nox_xxx_fileReadWrite_426AC0_file3_fread(v2, v6);
		}
		if ((short)a1 >= 31) {
			nox_xxx_fileReadWrite_426AC0_file3_fread(v2 + 80, 4u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(v2 + 84, 4u);
		}
		if (!v1[34] || nox_xxx_cryptGetXxx() != 1 || (result = nox_xxx_xfer_4F3E30(a1, (int)v1, v1[34])) != 0) {
			v1[34] = v3;
			result = 1;
		}
	}
	return result;
}

//----- (004F4CB0) --------------------------------------------------------
int nox_xxx_XFerDoor_4F4CB0(int a1) {
	int v1;     // edi
	int v2;     // esi
	int result; // eax
	int v4;     // ebx
	int v5;     // ebp
	int v6;     // [esp+8h] [ebp-14h]
	int v7;     // [esp+Ch] [ebp-10h]
	int v8;     // [esp+10h] [ebp-Ch]
	int v9;     // [esp+14h] [ebp-8h]
	int v10;    // [esp+18h] [ebp-4h]

	v1 = a1;
	v2 = *(uint32_t*)(a1 + 748);
	v10 = *(uint32_t*)(a1 + 136);
	v7 = 60;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v7, 2u);
	if ((short)v7 > 60) {
		return 0;
	}
	result = nox_xxx_mapReadWriteObjData_4F4530((int*)v1, (short)v7);
	if (result) {
		if (!nox_xxx_cryptGetXxx()) {
			a1 = *(uint32_t*)(v2 + 12);
			v8 = *(unsigned char*)(v2 + 1);
			v6 = *(uint32_t*)(v2 + 4);
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 4u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(&v8, 4u);
		if ((short)v7 < 41) {
			v6 = a1;
		} else {
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v6, 4u);
		}
		if (nox_xxx_cryptGetXxx() == 1) {
			*(uint32_t*)(v2 + 12) = a1;
			*(uint16_t*)(v2 + 40) = (a1 << 8) / 32;
			*(uint32_t*)(v2 + 4) = v6;
			*(uint32_t*)(v2 + 8) = a1;
			v9 = *getMemIntPtr(0x587000, 196184 + 8 * v6) / 2;
			v4 = (long long)(((double)v9 + *(float*)(v1 + 56)) * 0.043478262);
			v9 = *getMemIntPtr(0x587000, 196188 + 8 * v6) / 2;
			v5 = (long long)(((double)v9 + *(float*)(v1 + 60)) * 0.043478262);
			nox_xxx_doorAttachWall_410360(v1, v4, v5);
			*(uint32_t*)(v2 + 16) = v4;
			*(uint32_t*)(v2 + 20) = v5;
			*(uint8_t*)(v2 + 1) = v8;
		}
		if (!*(uint32_t*)(v1 + 136) || nox_xxx_cryptGetXxx() != 1 ||
			(result = nox_xxx_xfer_4F3E30(v7, v1, *(uint32_t*)(v1 + 136))) != 0) {
			*(uint32_t*)(v1 + 136) = v10;
			result = 1;
		}
	}
	return result;
}

//----- (004F4E50) --------------------------------------------------------
int nox_xxx_unitTriggerXfer_4F4E50(float a1) {
	int v1;      // edi
	uint8_t* v2; // esi
	int result;  // eax
	double v4;   // st7
	double v5;   // st7
	double v6;   // st7
	char* v7;    // ebp
	char* v8;    // eax
	char* v9;    // eax
	char* v10;   // eax
	int v11;     // [esp+Ch] [ebp-Ch]
	int v12;     // [esp+10h] [ebp-8h]
	int v13;     // [esp+14h] [ebp-4h]

	v1 = LODWORD(a1);
	v2 = *(uint8_t**)(LODWORD(a1) + 748);
	v13 = *(uint32_t*)(LODWORD(a1) + 136);
	v11 = 61;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v11, 2u);
	if ((short)v11 > 61) {
		return 0;
	}
	result = nox_xxx_mapReadWriteObjData_4F4530((int*)v1, (short)v11);
	if (result) {
		if (nox_xxx_cryptGetXxx()) {
			nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 4u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v12, 4u);
			v5 = (double)SLODWORD(a1);
			a1 = v5;
			*(float*)(v1 + 184) = v5;
			v6 = (double)v12;
			*(float*)(v1 + 188) = v6;
			if (a1 > 60.0) {
				*(uint32_t*)(v1 + 184) = 1114636288;
			}
			if (v6 > 60.0) {
				*(uint32_t*)(v1 + 188) = 1114636288;
			}
		} else {
			v4 = *(float*)(v1 + 188);
			LODWORD(a1) = (long long)*(float*)(v1 + 184);
			v12 = (long long)v4;
			nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 4u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v12, 4u);
		}
		nox_shape_box_calc((nox_shape*)(v1 + 172));
		if ((short)v11 < 41) {
			nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 3u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 3u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 3u);
		} else {
			nox_xxx_fileReadWrite_426AC0_file3_fread(v2 + 54, 1u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(v2 + 55, 1u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(v2 + 56, 1u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(v2 + 57, 1u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(v2 + 58, 1u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(v2 + 59, 1u);
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread(v2, 4u);
		if ((short)v11 >= 3) {
			v7 = *(char**)(v1 + 756);
			if (v7) {
				v8 = v7 + 256;
			} else {
				v8 = 0;
			}
			nox_xxx_xferReadScriptHandler_4F5580((int)(v2 + 20), v8);
			if (v7) {
				v9 = v7 + 384;
			} else {
				v9 = 0;
			}
			nox_xxx_xferReadScriptHandler_4F5580((int)(v2 + 28), v9);
			if ((short)v11 >= 31) {
				if (v7) {
					v10 = v7 + 512;
				} else {
					v10 = 0;
				}
				nox_xxx_xferReadScriptHandler_4F5580((int)(v2 + 12), v10);
			}
		} else {
			sub_4F5540((int)(v2 + 20));
			sub_4F5540((int)(v2 + 28));
		}
		if (nox_xxx_cryptGetXxx() == 1 && (short)v11 < 31) {
			nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 1u);
			nox_xxx_cryptSeekCur_40E0A0(4 * LOBYTE(a1));
			nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 1u);
			nox_xxx_cryptSeekCur_40E0A0(4 * LOBYTE(a1));
			nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 1u);
			nox_xxx_cryptSeekCur_40E0A0(4 * LOBYTE(a1));
			nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 1u);
			nox_xxx_cryptSeekCur_40E0A0(4 * LOBYTE(a1));
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread(v2 + 44, 4u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(v2 + 48, 4u);
		if (nox_xxx_cryptGetXxx() == 1) {
			v2[52] = 0;
			v2[53] = 0;
		}
		if (!nox_xxx_cryptGetXxx() || (short)v11 >= 21) {
			nox_xxx_fileReadWrite_426AC0_file3_fread(v2 + 52, 1u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(v2 + 53, 1u);
		}
		if ((short)v11 >= 61) {
			nox_xxx_fileReadWrite_426AC0_file3_fread(v2 + 8, 1u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(v2 + 9, 1u);
			nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(v1 + 132), 4u);
			if (nox_xxx_cryptGetXxx() == 1) {
				nox_xxx_servMarkObjAnimFrame_4E4880(v1, *(uint32_t*)(v1 + 132));
			}
		}
		if (!*(uint32_t*)(v1 + 136) || nox_xxx_cryptGetXxx() != 1 ||
			(result = nox_xxx_xfer_4F3E30(v11, v1, *(uint32_t*)(v1 + 136))) != 0) {
			result = 1;
			*(uint32_t*)(v1 + 136) = v13;
		}
	}
	return result;
}

//----- (004F51D0) --------------------------------------------------------
int nox_xxx_XFerHole_4F51D0(int a1) {
	int* v1;    // edi
	int v2;     // ebx
	int v3;     // esi
	int result; // eax
	char* v5;   // eax
	int v6;     // [esp+Ch] [ebp-4h]

	v1 = (int*)a1;
	v2 = *(uint32_t*)(a1 + 756);
	v3 = *(uint32_t*)(a1 + 700);
	v6 = *(uint32_t*)(a1 + 136);
	a1 = 60;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 2u);
	if ((short)a1 > 60) {
		return 0;
	}
	result = nox_xxx_mapReadWriteObjData_4F4530(v1, (short)a1);
	if (result) {
		if ((short)a1 < 42) {
			*(uint32_t*)(v3 + 24) = 0;
		} else {
			nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(v3 + 24), 4u);
		}
		if ((short)a1 < 41) {
			nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(v3 + 8), 8u);
			*(uint32_t*)(v3 + 4) = -1;
			*(uint32_t*)v3 = 0;
			*(uint32_t*)(v3 + 16) = 0;
			*(uint16_t*)(v3 + 20) = 0;
		} else {
			if (v2) {
				v5 = (char*)(v2 + 128);
			} else {
				v5 = 0;
			}
			nox_xxx_xferReadScriptHandler_4F5580(v3, v5);
			nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(v3 + 8), 8u);
			nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(v3 + 16), 4u);
			nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(v3 + 20), 2u);
		}
		if (!v1[34] || nox_xxx_cryptGetXxx() != 1 || (result = nox_xxx_xfer_4F3E30(a1, (int)v1, v1[34])) != 0) {
			result = 1;
			v1[34] = v6;
		}
	}
	return result;
}

//----- (004F5300) --------------------------------------------------------
int nox_xxx_XFerTransporter_4F5300(int a1) {
	int* v1;    // esi
	int v2;     // edi
	int v3;     // ebx
	int result; // eax
	int v5;     // [esp+Ch] [ebp-4h]

	v1 = (int*)a1;
	v2 = *(uint32_t*)(a1 + 748);
	v3 = *(uint32_t*)(a1 + 136);
	a1 = 60;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 2u);
	if ((short)a1 > 60) {
		return 0;
	}
	result = nox_xxx_mapReadWriteObjData_4F4530(v1, (short)a1);
	if (result) {
		if (nox_xxx_cryptGetXxx()) {
			nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(v2 + 16), 4u);
		} else {
			if (*(uint32_t*)(v2 + 12)) {
				v5 = *(uint32_t*)(v2 + 16);
			} else {
				v5 = 0;
			}
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v5, 4u);
		}
		if (!v1[34] || nox_xxx_cryptGetXxx() != 1 || (result = nox_xxx_xfer_4F3E30(a1, (int)v1, v1[34])) != 0) {
			v1[34] = v3;
			result = 1;
		}
	}
	return result;
}

//----- (004F53D0) --------------------------------------------------------
int nox_xxx_XFerElevator_4F53D0(int a1) {
	int* v1;     // esi
	uint8_t* v2; // edi
	int v3;      // ebx
	int result;  // eax

	v1 = (int*)a1;
	v2 = *(uint8_t**)(a1 + 748);
	v3 = *(uint32_t*)(a1 + 136);
	a1 = 61;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 2u);
	if ((short)a1 > 61) {
		return 0;
	}
	result = nox_xxx_mapReadWriteObjData_4F4530(v1, (short)a1);
	if (result) {
		nox_xxx_fileReadWrite_426AC0_file3_fread(v2 + 8, 4u);
		if ((short)a1 >= 41) {
			nox_xxx_fileReadWrite_426AC0_file3_fread(v2 + 16, 4u);
		}
		if ((short)a1 >= 61) {
			nox_xxx_fileReadWrite_426AC0_file3_fread(v2 + 12, 1u);
		}
		if (!v1[34] || nox_xxx_cryptGetXxx() != 1 || (result = nox_xxx_xfer_4F3E30(a1, (int)v1, v1[34])) != 0) {
			v1[34] = v3;
			result = 1;
		}
	}
	return result;
}

//----- (004F54A0) --------------------------------------------------------
int nox_xxx_XFerElevatorShaft_4F54A0(int a1) {
	int* v1;    // esi
	int v2;     // edi
	int v3;     // ebx
	int result; // eax

	v1 = (int*)a1;
	v2 = *(uint32_t*)(a1 + 748);
	v3 = *(uint32_t*)(a1 + 136);
	a1 = 60;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 2u);
	if ((short)a1 > 60) {
		return 0;
	}
	result = nox_xxx_mapReadWriteObjData_4F4530(v1, (short)a1);
	if (result) {
		nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(v2 + 8), 4u);
		if (!v1[34] || nox_xxx_cryptGetXxx() != 1 || (result = nox_xxx_xfer_4F3E30(a1, (int)v1, v1[34])) != 0) {
			v1[34] = v3;
			result = 1;
		}
	}
	return result;
}

//----- (004F5540) --------------------------------------------------------
int sub_4F5540(int a1) {
	int result; // eax
	FILE* v2;   // eax

	result = nox_xxx_cryptGetXxx();
	if (nox_xxx_cryptGetXxx() == 1) {
		v2 = nox_xxx_mapgenGetSomeFile_426A60();
		nox_xxx_mapgenMakeScript_502790(v2, (char*)a1);
		result = nox_common_gameFlags_check_40A5C0(0x400000);
		if (!result) {
			*(uint32_t*)(a1 + 4) = -1;
		}
	}
	return result;
}

//----- (004F5730) --------------------------------------------------------
int nox_xxx_XFerMover_4F5730(int a1) {
	int v1;     // edi
	int v2;     // esi
	int v3;     // ebp
	int result; // eax
	int* v5;    // eax
	int* v6;    // esi
	int v7;     // [esp+Ch] [ebp-4h]

	v1 = a1;
	v2 = *(uint32_t*)(a1 + 748);
	v3 = *(uint32_t*)(a1 + 136);
	v7 = 60;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v7, 2u);
	if ((short)v7 > 60) {
		return 0;
	}
	result = nox_xxx_mapReadWriteObjData_4F4530((int*)v1, (short)v7);
	if (result) {
		nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(v2 + 4), 4u);
		nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(v2 + 8), 4u);
		nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(v2 + 32), 4u);
		if ((short)v7 >= 41) {
			nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)v2, 1u);
			if (nox_xxx_cryptGetXxx()) {
				nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(v2 + 16), 4u);
				nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(v2 + 24), 4u);
			} else {
				v5 = *(int**)(v2 + 12);
				a1 = 0;
				if (v5) {
					a1 = *v5;
				}
				nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 4u);
				v6 = *(int**)(v2 + 20);
				a1 = 0;
				if (v6) {
					a1 = *v6;
				}
				nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 4u);
			}
		}
		if ((short)v7 >= 42) {
			nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(v1 + 548), 4u);
			nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(v1 + 544), 4u);
		}
		if (!*(uint32_t*)(v1 + 136) || nox_xxx_cryptGetXxx() != 1 ||
			(result = nox_xxx_xfer_4F3E30(v7, v1, *(uint32_t*)(v1 + 136))) != 0) {
			*(uint32_t*)(v1 + 136) = v3;
			result = 1;
		}
	}
	return result;
}

//----- (004F5890) --------------------------------------------------------
int nox_xxx_XFerGlyph_4F5890(int a1) {
	int v1;        // edi
	int v2;        // ebp
	int v3;        // eax
	int result;    // eax
	uint8_t* v5;   // esi
	int v6;        // edi
	int* v7;       // ebp
	int v8;        // ebx
	char* v9;      // eax
	size_t v10;    // [esp-Ch] [ebp-128h]
	int v11;       // [esp+8h] [ebp-114h]
	int v12;       // [esp+Ch] [ebp-110h]
	int* v13;      // [esp+10h] [ebp-10Ch]
	int v14;       // [esp+14h] [ebp-108h]
	int v15;       // [esp+18h] [ebp-104h]
	char v16[256]; // [esp+1Ch] [ebp-100h]

	v1 = a1;
	v2 = *(uint32_t*)(a1 + 692);
	v3 = *(uint32_t*)(a1 + 136);
	v13 = *(int**)(a1 + 692);
	v14 = v3;
	v12 = 60;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v12, 2u);
	if ((short)v12 > 60) {
		return 0;
	}
	result = nox_xxx_mapReadWriteObjData_4F4530((int*)a1, (short)v12);
	if (result) {
		if ((short)v12 < 41) {
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v15, 4u);
		}
		nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(a1 + 124), 1u);
		nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(v2 + 28), 4u);
		nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(v2 + 32), 4u);
		v5 = (uint8_t*)(v2 + 20);
		nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)(v2 + 20), 1u);
		if (nox_xxx_cryptGetXxx() == 1) {
			if ((short)v12 < 31) {
				nox_xxx_fileReadWrite_426AC0_file3_fread((uint8_t*)v2, 0x14u);
				goto LABEL_16;
			}
			v6 = 0;
			if (!*v5) {
				v1 = a1;
				v2 = (int)v13;
				goto LABEL_19;
			}
			v7 = v13;
			do {
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v11, 1u);
				nox_xxx_fileReadWrite_426AC0_file3_fread(v16, (unsigned char)v11);
				v16[(unsigned char)v11] = 0;
				*v7 = nox_xxx_spellNameToN_4243F0(v16);
				++v6;
				++v7;
			} while (v6 < (unsigned char)*v5);
		} else {
			v8 = 0;
			if (!*v5) {
				goto LABEL_16;
			}
			do {
				LOBYTE(v11) = strlen(nox_xxx_spellNameByN_424870(*(uint32_t*)v2));
				nox_xxx_fileReadWrite_426AC0_file3_fread(&v11, 1u);
				v10 = (unsigned char)v11;
				v9 = nox_xxx_spellNameByN_424870(*(uint32_t*)v2);
				nox_xxx_fileReadWrite_426AC0_file3_fread(v9, v10);
				++v8;
				v2 += 4;
			} while (v8 < (unsigned char)*v5);
		}
		v1 = a1;
		v2 = (int)v13;
	LABEL_16:
		if (nox_xxx_cryptGetXxx() != 1) {
		LABEL_20:
			if (!*(uint32_t*)(v1 + 136) || nox_xxx_cryptGetXxx() != 1 ||
				(result = nox_xxx_xfer_4F3E30(v12, v1, *(uint32_t*)(v1 + 136))) != 0) {
				result = 1;
				*(uint32_t*)(v1 + 136) = v14;
			}
			return result;
		}
	LABEL_19:
		*(uint16_t*)(v1 + 126) = *(uint16_t*)(v1 + 124);
		*(uint32_t*)(v2 + 24) = 0;
		goto LABEL_20;
	}
	return result;
}
// 4F5890: using guessed type char var_100[256];

//----- (004F5AA0) --------------------------------------------------------
int nox_xxx_XFerInvLight_4F5AA0(int* a1) {
	int result;   // eax
	uint32_t* v2; // eax
	int v3;       // [esp+8h] [ebp-98h]
	int v4;       // [esp+Ch] [ebp-94h]
	int v5;       // [esp+10h] [ebp-90h]
	char v6[140]; // [esp+14h] [ebp-8Ch]

	v5 = a1[34];
	memset(v6, 0, sizeof(v6));
	v3 = 60;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v3, 2u);
	if ((short)v3 > 60) {
		return 0;
	}
	result = nox_xxx_mapReadWriteObjData_4F4530(a1, (short)v3);
	if (result) {
		if (nox_xxx_cryptGetXxx()) {
			goto LABEL_14;
		}
		if (nox_common_gameFlags_check_40A5C0(6291456)) {
			v2 = (uint32_t*)sub_45A060();
			if (!v2) {
				goto LABEL_14;
			}
			while (v2[32] != a1[10]) {
				v2 = (uint32_t*)sub_45A070((int)v2);
				if (!v2) {
					goto LABEL_14;
				}
			}
		} else if (a1[2] & 0x20400000) {
			v2 = nox_xxx_netSpriteByCodeStatic_45A720(a1[10]);
		} else {
			v2 = nox_xxx_netSpriteByCodeDynamic_45A6F0(a1[9]);
		}
		if (!v2) {
			abort();
		}
		memcpy(v6, v2 + 34, sizeof(v6));
	LABEL_14:
		if ((short)v3 >= 2) {
			nox_xxx_fileReadWrite_426AC0_file3_fread(v6, 4u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v6[4], 4u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v6[8], 4u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v6[12], 4u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v6[16], 0xCu);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v6[28], 2u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v6[30], 2u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v6[32], 4u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v6[40], 2u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v6[42], 0x30u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v6[90], 0x10u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v6[106], 0x10u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v6[122], 2u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v6[124], 2u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v6[126], 2u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v6[128], 4u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v6[134], 2u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v6[136], 2u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v6[138], 1u);
			if ((short)v3 > 40) {
				if ((short)v3 >= 42) {
					nox_xxx_fileReadWrite_426AC0_file3_fread(&v6[36], 4u);
				} else {
					nox_xxx_fileReadWrite_426AC0_file3_fread(&v4, 1u);
					*(uint32_t*)&v6[36] = (unsigned char)v4;
				}
			LABEL_19:
				if (nox_xxx_cryptGetXxx() == 1) {
					goto LABEL_20;
				}
			LABEL_22:
				if (!a1[34] || nox_xxx_cryptGetXxx() != 1 ||
					(result = nox_xxx_xfer_4F3E30(v3, (int)a1, a1[34])) != 0) {
					a1[34] = v5;
					result = 1;
				}
				return result;
			}
			if (nox_xxx_cryptGetXxx() != 1) {
				goto LABEL_22;
			}
			*(uint32_t*)&v6[36] = 0;
		} else {
			nox_xxx_fileReadWrite_426AC0_file3_fread(v6, 4u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v6[4], 4u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v6[8], 4u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v6[12], 4u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v6[16], 0xCu);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v6[28], 2u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v6[30], 2u);
			nox_xxx_fileReadWrite_426AC0_file3_fread(&v6[32], 4u);
			*(uint16_t*)&v6[40] = 0;
			*(uint16_t*)&v6[122] = 0;
			*(uint16_t*)&v6[124] = 0;
			*(uint16_t*)&v6[126] = 0;
			*(uint32_t*)&v6[128] = 0;
			*(uint16_t*)&v6[134] = 0;
			v6[138] = -128;
			if (nox_xxx_cryptGetXxx() != 1) {
				goto LABEL_22;
			}
			if (*(float*)&v6[4] > 63.0 ||
				(double)*(int*)&v6[12] * *getMemDoublePtr(0x581450, 9752) > *getMemDoublePtr(0x581450, 9744)) {
				sub_484CE0((int)v6, 63.0);
				goto LABEL_19;
			}
		}
	LABEL_20:
		if (nox_common_gameFlags_check_40A5C0(6291456)) {
			memcpy((void*)(a1[189] + 2432), v6, 0x8Cu);
		}
		goto LABEL_22;
	}
	return result;
}

//----- (004F5E50) --------------------------------------------------------
int nox_xxx_XFerSentry_4F5E50(int a1) {
	int* v1;     // edi
	uint8_t* v2; // esi
	int v3;      // ebp
	int result;  // eax

	v1 = (int*)a1;
	v2 = *(uint8_t**)(a1 + 748);
	v3 = *(uint32_t*)(a1 + 136);
	a1 = 61;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&a1, 2u);
	if ((short)a1 > 61) {
		return 0;
	}
	result = nox_xxx_mapReadWriteObjData_4F4530(v1, (short)a1);
	if (result) {
		nox_xxx_fileReadWrite_426AC0_file3_fread(v2 + 4, 4u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(v2 + 8, 4u);
		if (nox_xxx_cryptGetXxx() == 1 || nox_common_gameFlags_check_40A5C0(0x200000)) {
			*(uint32_t*)v2 = *((uint32_t*)v2 + 1);
		}
		if ((short)a1 >= 61) {
			nox_xxx_fileReadWrite_426AC0_file3_fread(v2, 4u);
		}
		if (!v1[34] || nox_xxx_cryptGetXxx() != 1 || (result = nox_xxx_xfer_4F3E30(a1, (int)v1, v1[34])) != 0) {
			v1[34] = v3;
			result = 1;
		}
	}
	return result;
}
