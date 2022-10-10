#include <math.h>
#include <stdio.h>
#include <string.h>

#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_1.h"
#include "GAME2_2.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4.h"
#include "GAME4_1.h"
#include "GAME4_2.h"
#include "GAME4_3.h"
#include "GAME5.h"
#include "GAME5_2.h"
#include "client__video__draw_common.h"
#include "common__magic__speltree.h"
#include "common__random.h"
#include "common__strman.h"
#include "common__system__team.h"
#include "operators.h"
#include "server__gamemech__explevel.h"
#include "server__magic__plyrspel.h"
#include "server__script__activator.h"
#include "server__script__builtin.h"
#include "server__script__internal.h"
#include "server__script__script.h"

// TODO: move somewhere else
int nox_xxx_netSendChat_528AC0(nox_object_t* a1, wchar_t* a2, wchar_t a3);

extern unsigned int dword_5d4594_2386836;
extern unsigned int nox_gameDisableMapDraw_5d4594_2650672;
extern unsigned int nox_gameFPS;
extern unsigned int nox_frame_xxx_2598000;

unsigned int dword_5d4594_1599628 = 0;
void* nox_script_objGold = 0;
unsigned int dword_5d4594_2386848 = 0;
unsigned int dword_5d4594_2386852 = 0;

//----- (00512E80) --------------------------------------------------------
int sub_512E80(int a1) {
	int v1; // eax

	v1 = dword_5d4594_1599628;
	if (*(int*)&dword_5d4594_1599628 < 1024) {
		*getMemU32Ptr(0x973F18, 26664 + 4 * dword_5d4594_1599628) = a1;
		dword_5d4594_1599628 = ++v1;
	}
	return v1 - 1;
}

//----- (00511E60) --------------------------------------------------------
void sub_511E60() {
	if (!dword_5d4594_2386836) {
		dword_5d4594_2386836 = nox_xxx_getNameId_4E3AA0("Mover");
	}
	nox_script_freeEverything_5058F0();
	nox_script_activatorCancelAll_51AC60();
	*getMemU32Ptr(0x5D4594, 2386844) = 0;
	dword_5d4594_2386848 = 0;
	dword_5d4594_2386852 = 0;
}

//----- (00513B00) --------------------------------------------------------
void nox_xxx_playerCanCarryItem_513B00(int a1, int a2) {
	uint32_t* v2; // ebp
	int v3;       // edi
	int v4;       // esi
	int v5;       // eax
	int v6;       // eax
	float2 v7;    // [esp+0h] [ebp-8h]

	if (!*getMemU32Ptr(0x5D4594, 2386856)) {
		*getMemU32Ptr(0x5D4594, 2386856) = nox_xxx_getNameId_4E3AA0("Glyph");
	}
	if (sub_467B00(*(unsigned short*)(a2 + 4), 1) - *(int*)&dword_5d4594_2386848 <= 0) {
		v2 = 0;
		v3 = 999999;
		v4 = nox_xxx_inventoryGetFirst_4E7980(a1);
		if (v4) {
			do {
				if (!(*(uint8_t*)(v4 + 8) & 0x10)) {
					v5 = *(uint32_t*)(v4 + 16);
					if (!(v5 & 0x100) && *(unsigned short*)(v4 + 4) != *getMemU32Ptr(0x5D4594, 2386856) &&
						!nox_xxx_ItemIsDroppable_53EBF0(v4)) {
						v6 = nox_xxx_shopGetItemCost_50E3D0(1, 0, *(float*)&v4);
						if (v6 < v3) {
							v3 = v6;
							v2 = (uint32_t*)v4;
						}
					}
				}
				v4 = nox_xxx_inventoryGetNext_4E7990(v4);
			} while (v4);
			if (v2) {
				sub_4ED970(50.0, (float2*)(a1 + 56), &v7);
				nox_xxx_drop_4ED790(a1, v2, &v7);
				if (!dword_5d4594_2386852) {
					nox_xxx_netPriMsgToPlayer_4DA2C0(a1, "pickup.c:CarryingTooMuch", 0);
					dword_5d4594_2386852 = 1;
				}
			}
		}
	}
}

//----- (00511EB0) --------------------------------------------------------
int nox_script_getWall_511EB0() {
	int v0; // edi
	int v1; // esi

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	if (nox_script_builtinGetF40() || nox_script_builtinGetF44()) {
		v1 = (nox_script_builtinGetF40() + 23 * v1) / 23;
		v0 = (nox_script_builtinGetF44() + 23 * v0) / 23;
	}
	if (nox_server_getWallAtGrid_410580(v1, v0)) {
		nox_script_push(v0 | (v1 << 16));
	} else {
		nox_script_push(0);
	}
	return 0;
}

//----- (00512100) --------------------------------------------------------
int nox_script_closeWallGroup_512100() {
	int v0;            // eax
	unsigned char* v1; // eax

	v0 = nox_script_pop();
	v1 = (unsigned char*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 2, nox_xxx_wallClose_512070, 0);
	return 0;
}

//----- (00512260) --------------------------------------------------------
int nox_script_toggleWallGroup_512260() {
	int v0;            // eax
	unsigned char* v1; // eax

	v0 = nox_script_pop();
	v1 = (unsigned char*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 2, nox_xxx_wallToggle_512160, 0);
	return 0;
}

//----- (005122F0) --------------------------------------------------------
int nox_script_wallGroupBreak_5122F0() {
	int v0;            // eax
	unsigned char* v1; // eax

	v0 = nox_script_pop();
	v1 = (unsigned char*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 2, nox_xxx_wallPreDestroyByPtr_5122C0, 0);
	return 0;
}

//----- (005123C0) --------------------------------------------------------
int* nox_server_scriptMoveTo_5123C0(int a1, int a2) {
	int* result; // eax
	int v3;      // ebx
	int* v4;     // eax
	int* v5;     // eax
	int* i;      // esi

	result = *(int**)(a1 + 16);
	if (SBYTE1(result) >= 0) {
		if (*(uint8_t*)(a1 + 8) & 2) {
			v3 = *(uint32_t*)(a1 + 748);
			nox_xxx_monsterClearActionStack_50A3A0(a1);
			v4 = nox_xxx_monsterPushAction_50A260(a1, 32);
			if (v4) {
				v4[1] = 8;
			}
			if (*(uint8_t*)(a2 + 476)) {
				v5 = nox_xxx_monsterPushAction_50A260(a1, 10);
				if (v5) {
					v5[1] = a2;
					*((uint8_t*)v5 + 12) = *(uint8_t*)(v3 + 1332);
				}
			}
			result = nox_xxx_monsterPushAction_50A260(a1, 8);
			if (result) {
				result[1] = *(uint32_t*)(a2 + 8);
				result[2] = *(uint32_t*)(a2 + 12);
				result[3] = 0;
			}
		} else if (*(unsigned short*)(a1 + 4) == dword_5d4594_2386836) {
			result = (int*)nox_xxx_moverGoTo_5124C0((uint32_t*)a1, (uint32_t*)a2);
		} else {
			result = (int*)nox_server_getFirstObject_4DA790();
			for (i = result; result; i = result) {
				if (*((unsigned short*)i + 2) == dword_5d4594_2386836 &&
					*(uint32_t*)(i[187] + 32) == *(uint32_t*)(a1 + 40)) {
					nox_xxx_moverGoTo_5124C0(i, (uint32_t*)a2);
				}
				result = (int*)nox_server_getNextObject_4DA7A0((int)i);
			}
		}
	}
	return result;
}

//----- (005124C0) --------------------------------------------------------
int nox_xxx_moverGoTo_5124C0(uint32_t* a1, uint32_t* a2) {
	int v2; // edi

	v2 = a1[187];
	nox_xxx_objectSetOn_4E75B0((int)a1);
	a1[20] = 0;
	a1[21] = 0;
	*(uint8_t*)v2 = 0;
	*(uint32_t*)(v2 + 8) = *a2;
	nox_xxx_unitAddToUpdatable_4DA8D0(a1);
	return a1;
}

//----- (00512500) --------------------------------------------------------
int nox_script_groupGoTo_512500() {
	int v0;       // esi
	int v1;       // eax
	int v2;       // edi
	uint32_t* v3; // ebx
	int* i;       // esi
	int v5;       // eax

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_server_scriptGetGroup_57C0A0(v1);
	v3 = nox_server_getWaypointById_579C40(v0);
	if (v3) {
		if (v2) {
			for (i = *(int**)(v2 + 84); i; i = (int*)i[2]) {
				v5 = nox_xxx_netGetUnitByExtent_4ED020(*i);
				if (v5) {
					nox_server_scriptMoveTo_5123C0(v5, (int)v3);
				}
			}
		}
	}
	return 0;
}

//----- (00512610) --------------------------------------------------------
int nox_script_groupLookAtDirection_512610() {
	int v0;     // edi
	int v1;     // eax
	int result; // eax
	int* i;     // esi
	int v4;     // eax
	int v5;     // ecx

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	result = nox_server_scriptGetGroup_57C0A0(v1);
	if (result) {
		for (i = *(int**)(result + 84); i; i = (int*)i[2]) {
			v4 = nox_xxx_netGetUnitByExtent_4ED020(*i);
			if (v4 && *(uint8_t*)(v4 + 8) & 2) {
				v5 = *(uint32_t*)(v4 + 16);
				if ((v5 & 0x8000) == 0) {
					nox_xxx_monsterLookAt_5125A0(v4, v0);
				}
			}
		}
		result = 0;
	}
	return result;
}

//----- (00512690) --------------------------------------------------------
int nox_script_objGroupOn_512690() {
	int v0;            // eax
	unsigned char* v1; // eax

	v0 = nox_script_pop();
	v1 = (unsigned char*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 0, sub_5126C0, 0);
	return 0;
}

//----- (00512750) --------------------------------------------------------
int nox_script_objGroupOff_512750() {
	int v0;            // eax
	unsigned char* v1; // eax

	v0 = nox_script_pop();
	v1 = (unsigned char*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 0, sub_512780, 0);
	return 0;
}

//----- (005127B0) --------------------------------------------------------
int nox_script_waypointGroupOff_5127B0() {
	int v0;            // eax
	unsigned char* v1; // eax

	v0 = nox_script_pop();
	v1 = (unsigned char*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 1, sub_5127E0, 0);
	return 0;
}

//----- (00512870) --------------------------------------------------------
int nox_script_toggleWaypointGroup_512870() {
	int v0;            // eax
	unsigned char* v1; // eax

	v0 = nox_script_pop();
	v1 = (unsigned char*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 1, sub_5128A0, 0);
	return 0;
}

//----- (005128D0) --------------------------------------------------------
int nox_script_deleteObjectGroup_5128D0() {
	int v0;            // eax
	unsigned char* v1; // eax

	v0 = nox_script_pop();
	v1 = (unsigned char*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 0, sub_512900, 0);
	return 0;
}

//----- (00512930) --------------------------------------------------------
void nox_xxx_scriptMonsterRoam_512930(nox_object_t* obj) {
	int a1 = obj;
	int v1;  // eax
	int v2;  // edi
	int* v3; // eax
	int* v4; // eax

	if (*(uint8_t*)(a1 + 8) & 2) {
		v1 = *(uint32_t*)(a1 + 16);
		if ((v1 & 0x8000) == 0) {
			v2 = *(uint32_t*)(a1 + 748);
			nox_xxx_monsterClearActionStack_50A3A0(a1);
			v3 = nox_xxx_monsterPushAction_50A260(a1, 32);
			if (v3) {
				v3[1] = 10;
			}
			v4 = nox_xxx_monsterPushAction_50A260(a1, 10);
			if (v4) {
				v4[1] = 0;
				*((uint8_t*)v4 + 12) = *(uint8_t*)(v2 + 1332);
			}
		}
	}
}

//----- (00512990) --------------------------------------------------------
int nox_script_groupRoam_512990() {
	int v0;            // eax
	unsigned char* v1; // eax

	v0 = nox_script_pop();
	v1 = (unsigned char*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 0, nox_xxx_scriptMonsterRoam_512930, 0);
	return 0;
}

//----- (00512A00) --------------------------------------------------------
void nox_server_gotoHome(nox_object_t* obj) {
	int v2 = obj;
	int v3;       // eax
	uint32_t* v4; // edi
	int* v5;      // eax
	int* v6;      // eax
	int* v7;      // eax
	if (*(uint8_t*)(v2 + 8) & 2) {
		v3 = *(uint32_t*)(v2 + 16);
		if ((v3 & 0x8000) == 0) {
			v4 = *(uint32_t**)(v2 + 748);
			nox_xxx_monsterClearActionStack_50A3A0(v2);
			v5 = nox_xxx_monsterPushAction_50A260(v2, 32);
			if (v5) {
				v5[1] = 37;
			}
			v6 = nox_xxx_monsterPushAction_50A260(v2, 25);
			if (v6) {
				*((float*)v6 + 1) = *getMemFloatPtr(0x587000, 194136 + 8 * v4[94]) * 10.0 + *(float*)(v2 + 56);
				*((float*)v6 + 2) = *getMemFloatPtr(0x587000, 194140 + 8 * v4[94]) * 10.0 + *(float*)(v2 + 60);
			}
			v7 = nox_xxx_monsterPushAction_50A260(v2, 37);
			if (v7) {
				v7[1] = v4[95];
				v7[2] = v4[96];
				v7[3] = 0;
			}
		}
	}
}

//----- (00513010) --------------------------------------------------------
int nox_script_groupDamage_513010() {
	int v0;            // esi
	int v1;            // edi
	int v2;            // ebx
	int v3;            // ebp
	unsigned char* v4; // eax
	int v6[3];

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_script_pop();
	v3 = nox_script_pop();
	v6[0] = nox_server_scriptValToObjectPtr_511B60(v2);
	v6[1] = v1;
	v6[2] = v0;
	v4 = (unsigned char*)nox_server_scriptGetGroup_57C0A0(v3);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v4, 0, sub_512FE0, (int)v6);
	return 0;
}

//----- (00513160) --------------------------------------------------------
int nox_script_WanderGroup_513160() {
	int v0;            // esi
	int v1;            // edi
	unsigned char* v2; // eax
	float v4;          // [esp+8h] [ebp-10h]
	int v5[3];         // [esp+Ch] [ebp-Ch]

	v4 = nox_script_popf();
	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v5[1] = v0;
	v5[0] = (long long)v4;
	v2 = (unsigned char*)nox_server_scriptGetGroup_57C0A0(v1);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v2, 0, sub_5130E0, (int)v5);
	return 0;
}

//----- (00513230) --------------------------------------------------------
int nox_script_awardSpellGroup_513230() {
	int v0;            // esi
	int v1;            // edi
	unsigned char* v2; // eax
	int v4;            // [esp+8h] [ebp-4h]

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v4 = nox_xxx_spellNameToN_4243F0(nox_script_getString_512E40(v0));
	if (v4) {
		v2 = (unsigned char*)nox_server_scriptGetGroup_57C0A0(v1);
		nox_server_scriptExecuteFnForEachGroupObj_502670(v2, 0, sub_513280, (int)&v4);
	}
	return 0;
}

//----- (005133B0) --------------------------------------------------------
int nox_script_groupEnchant_5133B0() {
	int v0;            // esi
	int v1;            // ebx
	int v2;            // eax
	unsigned char* v3; // eax
	float v5;          // [esp+Ch] [ebp-54h]
	int v6[2];         // [esp+18h] [ebp-48h]

	v5 = nox_script_popf();
	v0 = nox_script_pop();
	v1 = nox_script_pop();
	const char* v7 = nox_script_getString_512E40(v0);
	v2 = nox_xxx_enchantByName_424880(v7);
	if (v2 != -1) {
		v6[0] = v2;
		v6[1] = (long long)((double)nox_gameFPS * v5);
		v3 = (unsigned char*)nox_server_scriptGetGroup_57C0A0(v1);
		nox_server_scriptExecuteFnForEachGroupObj_502670(v3, 0, nox_xxx_enchantUnit_513390, (int)v6);
	}
	return 0;
}

//----- (00513910) --------------------------------------------------------
int nox_script_hasItem_513910() {
	int v0; // edi
	int v1; // eax
	int v2; // esi
	int v3; // eax
	int v4; // edi

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	v3 = nox_server_scriptValToObjectPtr_511B60(v0);
	v4 = 0;
	if (v2 && v3 && nox_xxx_unitInventoryContains_4F78E0(v2, v3)) {
		v4 = 1;
	}
	nox_script_push(v4);
	return 0;
}

//----- (00513960) --------------------------------------------------------
int nox_script_getInvHolder_513960() {
	int v0; // eax
	int v1; // eax

	v0 = nox_script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1) {
		nox_script_push(*(uint32_t*)(*(uint32_t*)(v1 + 492) + 44));
	} else {
		nox_script_push(0);
	}
	return 0;
}

//----- (005139A0) --------------------------------------------------------
int nox_script_pickup_5139A0() {
	int v0; // edi
	int v1; // eax
	int v2; // esi
	int v3; // eax
	int v4; // ebp
	int v5; // eax
	int v6; // edi

	if (!nox_script_objGold) {
		nox_script_objGold = nox_xxx_getNameId_4E3AA0("Gold");
		*getMemU32Ptr(0x5D4594, 2386864) = nox_xxx_getNameId_4E3AA0("QuestGoldPile");
		*getMemU32Ptr(0x5D4594, 2386868) = nox_xxx_getNameId_4E3AA0("QuestGoldChest");
	}
	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	v3 = nox_server_scriptValToObjectPtr_511B60(v0);
	v4 = v3;
	if (v2 && v3) {
		if (nox_common_gameFlags_check_40A5C0(2048) && (*(uint8_t*)(v2 + 8) & 4) == 4 &&
			*getMemU32Ptr(0x5D4594, 2386844) != nox_frame_xxx_2598000) {
			*getMemU32Ptr(0x5D4594, 2386844) = nox_frame_xxx_2598000;
			dword_5d4594_2386848 = 0;
			dword_5d4594_2386852 = 0;
		}
		if (*(uint8_t*)(v2 + 8) & 4) {
			if (nox_common_gameFlags_check_40A5C0(2048)) {
				v5 = *(unsigned short*)(v2 + 4);
				if ((unsigned short)v5 != nox_script_objGold && v5 != *getMemU32Ptr(0x5D4594, 2386864) &&
					v5 != *getMemU32Ptr(0x5D4594, 2386868)) {
					nox_xxx_playerCanCarryItem_513B00(v2, v4);
				}
			}
		}
		v6 = nox_xxx_inventoryServPlace_4F36F0(v2, v4, 1, 1);
		if (v6 == 1 && *(uint8_t*)(v2 + 8) & 4 && nox_common_gameFlags_check_40A5C0(2048) &&
			*(unsigned short*)(v4 + 4) != nox_script_objGold) {
			++dword_5d4594_2386848;
			nox_script_push(1);
			return 0;
		}
	} else {
		v6 = 0;
	}
	nox_script_push(v6);
	return 0;
}

//----- (00513C10) --------------------------------------------------------
int nox_script_drop_513C10() {
	int v0;       // edi
	int v1;       // eax
	int v2;       // esi
	uint32_t* v3; // eax
	int v4;       // eax
	int result;   // eax

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	v3 = (uint32_t*)nox_server_scriptValToObjectPtr_511B60(v0);
	if (v2 && v3) {
		v4 = nox_xxx_invForceDropItem_4ED930(v2, v3);
		nox_script_push(v4);
		result = 0;
	} else {
		nox_script_push(0);
		result = 0;
	}
	return result;
}

//----- (00513C70) --------------------------------------------------------
int nox_script_TestBuffs_513C70() {
	int v0;     // esi
	int v1;     // ebx
	int v2;     // eax
	char v3;    // si
	int v4;     // eax
	int v5;     // eax
	int result; // eax

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	const char* v7 = nox_script_getString_512E40(v0);
	v2 = nox_xxx_enchantByName_424880(v7);
	v3 = v2;
	if (v2 != -1 && (v4 = nox_server_scriptValToObjectPtr_511B60(v1)) != 0) {
		v5 = nox_xxx_testUnitBuffs_4FF350(v4, v3);
		nox_script_push(v5);
		result = 0;
	} else {
		nox_script_push(0);
		result = 0;
	}
	return result;
}

//----- (00513D00) --------------------------------------------------------
int nox_script_cancelBuff_513D00() {
	int v0; // esi
	int v1; // ebx
	int v2; // esi
	int v3; // eax

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	const char* v5 = nox_script_getString_512E40(v0);
	v2 = nox_xxx_enchantByName_424880(v5);
	if (v2 != -1) {
		v3 = nox_server_scriptValToObjectPtr_511B60(v1);
		if (v3) {
			nox_xxx_spellBuffOff_4FF5B0(v3, v2);
		}
	}
	return 0;
}

//----- (00513D70) --------------------------------------------------------
int nox_script_getCurrentHP_513D70() {
	int v0;             // eax
	int v1;             // eax
	unsigned short* v2; // ecx
	int result;         // eax

	v0 = nox_script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1 && (v2 = *(unsigned short**)(v1 + 556)) != 0) {
		nox_script_push(*v2);
		result = 0;
	} else {
		nox_script_push(0);
		result = 0;
	}
	return result;
}

//----- (00513DB0) --------------------------------------------------------
int nox_script_getMaxHP_513DB0() {
	int v0;     // eax
	int v1;     // eax
	int v2;     // ecx
	int result; // eax

	v0 = nox_script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1 && (v2 = *(uint32_t*)(v1 + 556)) != 0) {
		nox_script_push(*(unsigned short*)(v2 + 4));
		result = 0;
	} else {
		nox_script_push(0);
		result = 0;
	}
	return result;
}

//----- (00513DF0) --------------------------------------------------------
int nox_script_restoreHP_513DF0() {
	int v0; // esi
	int v1; // eax
	int v2; // eax

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	if (v2 && v0 > 0) {
		nox_xxx_unitAdjustHP_4EE460(v2, v0);
	}
	return 0;
}

//----- (00513E20) --------------------------------------------------------
int nox_script_getDistance_513E20() {
	float v0; // eax
	float v2; // [esp+4h] [ebp-Ch]
	float v3; // [esp+8h] [ebp-8h]
	float v4; // [esp+Ch] [ebp-4h]
	int v5;   // [esp+Ch] [ebp-4h]

	v4 = nox_script_popf();
	v2 = nox_script_popf();
	v3 = nox_script_popf();
	v0 = nox_script_popf();
	*(float*)&v5 = sqrt((v3 - v4) * (v3 - v4) + (v0 - v2) * (v0 - v2));
	nox_script_push(v5);
	return 0;
}

//----- (00513E80) --------------------------------------------------------
int nox_script_canInteract_513E80() {
	int v0;    // edi
	int v1;    // eax
	int v2;    // esi
	int v3;    // eax
	int v4;    // edx
	double v5; // st7
	double v6; // st7

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	v3 = nox_server_scriptValToObjectPtr_511B60(v0);
	v4 = 0;
	if (v2 && v3) {
		v5 = *(float*)(v2 + 56) - *(float*)(v3 + 56);
		if (v5 < 0.0) {
			v5 = -v5;
		}
		if (v5 <= 512.0) {
			v6 = *(float*)(v2 + 60) - *(float*)(v3 + 60);
			if (v6 < 0.0) {
				v6 = -v6;
			}
			if (v6 <= 512.0) {
				v4 = nox_xxx_unitCanInteractWith_5370E0(v2, v3, 0);
			}
		}
	}
	nox_script_push(v4);
	return 0;
}

//----- (00513FA0) --------------------------------------------------------
int nox_script_GetHostInfo_513FA0() {
	int v0;     // esi
	char* v1;   // eax
	int result; // eax

	v0 = nox_script_pop();
	v1 = nox_xxx_getHostInfoPtr_431770();
	switch (v0) {
	case 0:
		nox_script_push(*(uint32_t*)(v1 + 50));
		result = 0;
		break;
	case 1:
		nox_script_push(*(uint32_t*)(v1 + 54));
		result = 0;
		break;
	case 2:
		nox_script_push(*(uint32_t*)(v1 + 58));
		result = 0;
		break;
	case 3:
		nox_script_push(*(uint32_t*)(v1 + 62));
		result = 0;
		break;
	case 4:
		nox_script_push((unsigned char)v1[66]);
		result = 0;
		break;
	case 5:
		nox_script_push((unsigned char)v1[67]);
		result = 0;
		break;
	default:
		nox_script_push(0);
		result = 0;
		break;
	}
	return result;
}

//----- (00514050) --------------------------------------------------------
int nox_script_FaceObject_514050() {
	int v0;    // edi
	int v1;    // eax
	int v2;    // esi
	int v3;    // eax
	short v4;  // ax
	float2 v6; // [esp+8h] [ebp-8h]

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	v3 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v2 && v3) {
		v6.field_0 = *(float*)(v3 + 56) - *(float*)(v2 + 56);
		v6.field_4 = *(float*)(v3 + 60) - *(float*)(v2 + 60);
		v4 = nox_xxx_math_509ED0(&v6);
		*(uint16_t*)(v2 + 126) = v4;
		*(uint16_t*)(v2 + 124) = v4;
	}
	return 0;
}

//----- (005140B0) --------------------------------------------------------
int nox_script_Walk_5140B0() {
	int v0;   // eax
	int v1;   // eax
	float v3; // [esp+0h] [ebp-10h]
	float v4; // [esp+4h] [ebp-Ch]
	float v5; // [esp+8h] [ebp-8h]
	float v6; // [esp+Ch] [ebp-4h]

	v5 = nox_script_popf();
	v6 = nox_script_popf();
	v0 = nox_script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1) {
		v4 = (double)nox_script_builtinGetF44() + v5;
		v3 = (double)nox_script_builtinGetF40() + v6;
		nox_xxx_monsterWalkTo_514110(v1, v3, v4);
	}
	return 0;
}

//----- (00514170) --------------------------------------------------------
int nox_script_GroupWalk_514170() {
	int v0;     // eax
	int result; // eax
	int* i;     // esi
	int v3;     // eax
	float v4;   // [esp+0h] [ebp-14h]
	float v5;   // [esp+4h] [ebp-10h]
	float v6;   // [esp+Ch] [ebp-8h]
	float v7;   // [esp+10h] [ebp-4h]

	v6 = nox_script_popf();
	v7 = nox_script_popf();
	v0 = nox_script_pop();
	result = nox_server_scriptGetGroup_57C0A0(v0);
	if (result) {
		for (i = *(int**)(result + 84); i; i = (int*)i[2]) {
			v3 = nox_xxx_netGetUnitByExtent_4ED020(*i);
			if (v3) {
				v5 = (double)nox_script_builtinGetF44() + v6;
				v4 = (double)nox_script_builtinGetF40() + v7;
				nox_xxx_monsterWalkTo_514110(v3, v4, v5);
			}
		}
		result = 0;
	}
	return result;
}

//----- (00514490) --------------------------------------------------------
int nox_script_SetOwner_514490() {
	int v0; // esi
	int v1; // eax
	int v2; // edi
	int v3; // eax

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	v3 = nox_server_scriptValToObjectPtr_511B60(v0);
	nox_xxx_unitSetOwner_4EC290(v2, v3);
	return 0;
}

//----- (005144C0) --------------------------------------------------------
int nox_script_SetOwnerGroup_5144C0() {
	int v0; // esi
	int v1; // eax
	int v2; // edi
	int v3; // eax
	int* i; // esi
	int v5; // eax

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	v3 = nox_server_scriptGetGroup_57C0A0(v0);
	if (v3) {
		for (i = *(int**)(v3 + 84); i; i = (int*)i[2]) {
			v5 = nox_xxx_netGetUnitByExtent_4ED020(*i);
			if (v5) {
				nox_xxx_unitSetOwner_4EC290(v2, v5);
			}
		}
	}
	return 0;
}

//----- (00514510) --------------------------------------------------------
int nox_script_SetOwners_514510() {
	int v0;  // edi
	int v1;  // eax
	int v2;  // esi
	int v3;  // eax
	int* v4; // esi
	int i;   // edi
	int v6;  // eax

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_server_scriptGetGroup_57C0A0(v1);
	if (v2) {
		v3 = nox_server_scriptValToObjectPtr_511B60(v0);
		v4 = *(int**)(v2 + 84);
		for (i = v3; v4; v4 = (int*)v4[2]) {
			v6 = nox_xxx_netGetUnitByExtent_4ED020(*v4);
			if (v6) {
				nox_xxx_unitSetOwner_4EC290(v6, i);
			}
		}
	}
	return 0;
}

//----- (00514570) --------------------------------------------------------
int nox_script_SetOwnersGroup_514570() {
	int v0; // edi
	int v1; // eax
	int v2; // esi
	int v3; // eax
	int v4; // ebp
	int* i; // edi
	int v6; // ebx
	int* j; // esi
	int v8; // eax

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_server_scriptGetGroup_57C0A0(v1);
	v3 = nox_server_scriptGetGroup_57C0A0(v0);
	v4 = v3;
	if (v2) {
		if (v3) {
			for (i = *(int**)(v2 + 84); i; i = (int*)i[2]) {
				v6 = nox_xxx_netGetUnitByExtent_4ED020(*i);
				if (v6) {
					for (j = *(int**)(v4 + 84); j; j = (int*)j[2]) {
						v8 = nox_xxx_netGetUnitByExtent_4ED020(*j);
						if (v8) {
							nox_xxx_unitSetOwner_4EC290(v6, v8);
						}
					}
				}
			}
		}
	}
	return 0;
}

//----- (005145F0) --------------------------------------------------------
int nox_script_IsOwnedBy_5145F0() {
	int v0; // esi
	int v1; // edi
	int v2; // esi
	int v3; // eax
	int v4; // eax

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v0);
	v3 = nox_server_scriptValToObjectPtr_511B60(v1);
	v4 = nox_xxx_unitHasThatParent_4EC4F0(v3, v2);
	nox_script_push(v4);
	return 0;
}

//----- (00514630) --------------------------------------------------------
int nox_script_IsOwnedByGroup_514630() {
	int v0;     // esi
	int v1;     // edi
	int result; // eax
	int v3;     // esi
	int v4;     // eax
	int* v5;    // esi
	int v6;     // edi
	int v7;     // ebx
	int v8;     // eax

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	result = nox_server_scriptGetGroup_57C0A0(v0);
	v3 = result;
	if (result) {
		v4 = nox_server_scriptValToObjectPtr_511B60(v1);
		v5 = *(int**)(v3 + 84);
		v6 = v4;
		v7 = 1;
		if (v5) {
			while (1) {
				v8 = nox_xxx_netGetUnitByExtent_4ED020(*v5);
				if (v8) {
					if (!nox_xxx_unitHasThatParent_4EC4F0(v6, v8)) {
						break;
					}
				}
				v5 = (int*)v5[2];
				if (!v5) {
					nox_script_push(1);
					return 0;
				}
			}
			v7 = 0;
		}
		nox_script_push(v7);
		result = 0;
	}
	return result;
}

//----- (005146B0) --------------------------------------------------------
int nox_script_IsOwnedByAny_5146B0() {
	int v0;     // edi
	int v1;     // eax
	int result; // eax
	int v3;     // esi
	int v4;     // eax
	int* v5;    // esi
	int v6;     // edi
	int v7;     // ebx
	int v8;     // eax

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	result = nox_server_scriptGetGroup_57C0A0(v1);
	v3 = result;
	if (result) {
		v4 = nox_server_scriptValToObjectPtr_511B60(v0);
		v5 = *(int**)(v3 + 84);
		v6 = v4;
		v7 = 1;
		if (v5) {
			while (1) {
				v8 = nox_xxx_netGetUnitByExtent_4ED020(*v5);
				if (v8) {
					if (!nox_xxx_unitHasThatParent_4EC4F0(v8, v6)) {
						break;
					}
				}
				v5 = (int*)v5[2];
				if (!v5) {
					nox_script_push(1);
					return 0;
				}
			}
			v7 = 0;
		}
		nox_script_push(v7);
		result = 0;
	}
	return result;
}

//----- (00514730) --------------------------------------------------------
int nox_script_IsOwnedByAnyGroup_514730() {
	int v0;  // esi
	int v1;  // edi
	int v2;  // esi
	int v3;  // eax
	int* v4; // ebx
	int i;   // ebp
	int v6;  // edi
	int* v7; // esi
	int v8;  // eax
	int v10; // [esp+8h] [ebp-4h]

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_server_scriptGetGroup_57C0A0(v0);
	v3 = nox_server_scriptGetGroup_57C0A0(v1);
	v10 = v3;
	if (!v2 || !v3) {
		return 0;
	}
	v4 = *(int**)(v2 + 84);
	for (i = 1; v4; v4 = (int*)v4[2]) {
		if (!i) {
			break;
		}
		v6 = nox_xxx_netGetUnitByExtent_4ED020(*v4);
		if (v6) {
			v7 = *(int**)(v10 + 84);
			if (v7) {
				while (1) {
					v8 = nox_xxx_netGetUnitByExtent_4ED020(*v7);
					if (v8) {
						if (!nox_xxx_unitHasThatParent_4EC4F0(v8, v6)) {
							break;
						}
					}
					v7 = (int*)v7[2];
					if (!v7) {
						goto LABEL_12;
					}
				}
				i = 0;
			}
		}
	LABEL_12:;
	}
	nox_script_push(i);
	return 0;
}

//----- (005147E0) --------------------------------------------------------
int nox_script_ClearOwner_5147E0() {
	int v0; // eax
	int v1; // eax

	v0 = nox_script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	nox_xxx_unitClearOwner_4EC300(v1);
	return 0;
}

//----- (00514BE0) --------------------------------------------------------
int nox_script_SetQuestInt_514BE0() {
	int v0; // esi
	int v1; // eax

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	nox_xxx_journalQuestSet_500540(nox_script_getString_512E40(v0), v1);
	return 0;
}

//----- (00514C10) --------------------------------------------------------
int nox_script_SetQuestFloat_514C10() {
	int v0; // esi
	int v1; // eax

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	nox_xxx_journalQuestSetBool_5006B0(nox_script_getString_512E40(v0), v1);
	return 0;
}

//----- (00514C40) --------------------------------------------------------
int nox_script_GetQuestInt_514C40() {
	int v0; // eax
	int v1; // eax

	v0 = nox_script_pop();
	v1 = sub_500750(nox_script_getString_512E40(v0));
	nox_script_push(v1);
	return 0;
}

//----- (00514C60) --------------------------------------------------------
int nox_script_GetQuestFloat_514C60() {
	int v0; // eax
	int v2; // [esp+0h] [ebp-4h]

	v0 = nox_script_pop();
	*(float*)&v2 = sub_500770((char*)nox_script_getString_512E40(v0));
	nox_script_push(v2);
	return 0;
}

//----- (00514C90) --------------------------------------------------------
int nox_script_ResetQuestStatus_514C90() {
	int v0; // eax

	v0 = nox_script_pop();
	sub_5007E0(nox_script_getString_512E40(v0));
	return 0;
}

//----- (00514CB0) --------------------------------------------------------
int nox_script_IsTrigger_514CB0() {
	int v0; // eax
	int v1; // esi
	int v2; // eax

	v0 = nox_script_pop();
	v1 = 0;
	v2 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v2 && nox_script_get_trigger() && *(uint32_t*)(v2 + 44) == *(uint32_t*)((char*)nox_script_get_trigger() + 44)) {
		v1 = 1;
	}
	nox_script_push(v1);
	return 0;
}

//----- (00514CF0) --------------------------------------------------------
int nox_script_IsCaller_514CF0() {
	int v0; // eax
	int v1; // esi
	int v2; // eax

	v0 = nox_script_pop();
	v1 = 0;
	v2 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v2 && nox_script_get_caller() && *(uint32_t*)(v2 + 44) == *(uint32_t*)((char*)nox_script_get_caller() + 44)) {
		v1 = 1;
	}
	nox_script_push(v1);
	return 0;
}

//----- (00514D30) --------------------------------------------------------
int nox_script_GetTrigger_514D30() {
	if (nox_script_get_trigger()) {
		nox_script_push(*(uint32_t*)((char*)nox_script_get_trigger() + 44));
	} else {
		nox_script_push(0);
	}
	return 0;
}

//----- (00514D60) --------------------------------------------------------
int nox_script_GetCaller_514D60() {
	if (nox_script_get_caller()) {
		nox_script_push(*(uint32_t*)((char*)nox_script_get_caller() + 44));
	} else {
		nox_script_push(0);
	}
	return 0;
}

//----- (00514D90) --------------------------------------------------------
int nox_script_SetDialog_514D90() {
	int v0;  // ebx
	int v1;  // ebp
	int v2;  // esi
	int v3;  // edi
	int v4;  // eax
	char v6; // [esp+10h] [ebp-4h]

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_script_pop();
	v3 = nox_script_pop();
	v6 = nox_xxx_scriptGetDialogIdx_548F70(nox_script_getString_512E40(v2));
	v4 = nox_server_scriptValToObjectPtr_511B60(v3);
	if (v4) {
		nox_xxx_scriptSetDialog_548C80(v4, v6, v1, v0);
	}
	return 0;
}

//----- (00514DF0) --------------------------------------------------------
int nox_script_CancelDialog_514DF0() {
	int v0; // eax
	int v1; // eax
	int v2; // ecx

	v0 = nox_script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1) {
		v2 = *(uint32_t*)(v1 + 748);
		if (*(uint8_t*)(v1 + 8) & 2) {
			*(uint32_t*)(v2 + 2096) = -1;
			*(uint32_t*)(v2 + 2100) = -1;
			nox_xxx_unitUnsetXStatus_4E4780(v1, 16);
		}
	}
	return 0;
}

//----- (00514E30) --------------------------------------------------------
int nox_script_DialogPortrait_514E30() {
	int v0; // esi
	int v1; // eax
	int v2; // eax

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	if (v2 && *(uint8_t*)(v2 + 8) & 2) {
		strcpy((char*)(*(uint32_t*)(v2 + 748) + 2106), nox_script_getString_512E40(v0));
	}
	return 0;
}

//----- (00514E90) --------------------------------------------------------
int nox_script_TellStory_514E90() {
	int v0;         // esi
	int v1;         // eax
	int v2;         // eax
	const char* v4; // [esp-4h] [ebp-8h]

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v4 = nox_script_getString_512E40(v0);
	v2 = nox_xxx_utilFindSound_40AF50(nox_script_getString_512E40(v1));
	nox_xxx_startShopDialog_548DE0(nox_script_get_caller(), nox_script_get_trigger(), v2, v4);
	return 0;
}

//----- (00514ED0) --------------------------------------------------------
int nox_script_StartDialog_514ED0() {
	int v0; // esi
	int v1; // edi
	int v2; // esi
	int v3; // eax

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v0);
	v3 = nox_server_scriptValToObjectPtr_511B60(v1);
	if (v2 && v3) {
		nox_xxx_script_forcedialog_548CD0(v2, v3);
	}
	return 0;
}

//----- (005154A0) --------------------------------------------------------
int nox_script_GetElevatorStat_5154A0() {
	int v0; // esi
	int v1; // eax
	int v2; // eax
	int v3; // ecx

	v0 = -1;
	v1 = nox_script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	if (v2) {
		v3 = *(uint32_t*)(v2 + 8);
		if (v3 & 0x4000) {
			v0 = *(unsigned char*)(*(uint32_t*)(v2 + 748) + 12);
		}
	}
	nox_script_push(v0);
	return 0;
}

//----- (00515550) --------------------------------------------------------
int nox_script_JournalDelete_515550() {
	int v0; // esi
	int v1; // eax
	int v2; // eax

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	if (v1) {
		v2 = nox_server_scriptValToObjectPtr_511B60(v1);
		if (v2) {
			nox_xxx_comJournalEntryRemove_427630(v2, nox_script_getString_512E40(v0));
			return 0;
		}
	} else {
		nox_xxx_comRemoveEntryAll_427680(nox_script_getString_512E40(v0));
	}
	return 0;
}

//----- (005155A0) --------------------------------------------------------
int nox_script_JournalEdit_5155A0() {
	short v0; // si
	int v1;   // edi
	int v2;   // eax
	int v3;   // eax

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_script_pop();
	if (v2) {
		v3 = nox_server_scriptValToObjectPtr_511B60(v2);
		if (v3) {
			nox_xxx_comJournalEntryUpdate_427720(v3, nox_script_getString_512E40(v1), v0);
			return 0;
		}
	} else {
		nox_xxx_comUpdateEntryAll_427770(nox_script_getString_512E40(v1), v0);
	}
	return 0;
}

//----- (00515600) --------------------------------------------------------
int nox_script_Guard_515600() {
	int v0;    // eax
	int v1;    // eax
	int v3;    // [esp+0h] [ebp-28h]
	int v4;    // [esp+4h] [ebp-24h]
	int v5;    // [esp+8h] [ebp-20h]
	int v6;    // [esp+Ch] [ebp-1Ch]
	int v7;    // [esp+10h] [ebp-18h]
	int v8[5]; // [esp+14h] [ebp-14h]

	v7 = nox_script_pop();
	v6 = nox_script_pop();
	v5 = nox_script_pop();
	v4 = nox_script_pop();
	v3 = nox_script_pop();
	v0 = nox_script_pop();
	v8[0] = v3;
	v8[1] = v4;
	v8[2] = v5;
	v8[3] = v6;
	v8[4] = v7;
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1) {
		nox_xxx_monsterGoPatrol_515680(v1, v8);
	}
	return 0;
}

//----- (00515700) --------------------------------------------------------
int nox_script_GuardGroup_515700() {
	int v0;            // eax
	unsigned char* v1; // eax
	int v3;            // [esp+0h] [ebp-28h]
	int v4;            // [esp+4h] [ebp-24h]
	int v5;            // [esp+8h] [ebp-20h]
	int v6;            // [esp+Ch] [ebp-1Ch]
	int v7;            // [esp+10h] [ebp-18h]
	int v8[5];         // [esp+14h] [ebp-14h]

	v7 = nox_script_pop();
	v6 = nox_script_pop();
	v5 = nox_script_pop();
	v4 = nox_script_pop();
	v3 = nox_script_pop();
	v0 = nox_script_pop();
	v8[1] = v4;
	v8[3] = v6;
	v8[0] = v3;
	v8[2] = v5;
	v8[4] = v7;
	v1 = (unsigned char*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 0, nox_xxx_monsterGoPatrol_515680, (int)v8);
	return 0;
}

//----- (005157D0) --------------------------------------------------------
int nox_script_HuntGroup_5157D0() {
	int v0;            // eax
	unsigned char* v1; // eax

	v0 = nox_script_pop();
	v1 = (unsigned char*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 0, nox_xxx_unitHunt_5157A0, 0);
	return 0;
}

//----- (00515800) --------------------------------------------------------
int nox_script_Idle_515800() {
	int v0; // eax
	int v1; // eax

	v0 = nox_script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1) {
		nox_xxx_unitIdle_515820(v1);
	}
	return 0;
}

//----- (00515850) --------------------------------------------------------
int nox_script_GroupIdle_515850() {
	int v0;            // eax
	unsigned char* v1; // eax

	v0 = nox_script_pop();
	v1 = (unsigned char*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 0, nox_xxx_unitIdle_515820, 0);
	return 0;
}

//----- (00515880) --------------------------------------------------------
int nox_script_Follow_515880() {
	int v0; // edi
	int v1; // eax
	int v2; // esi
	int v3; // eax

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	if (v2) {
		v3 = nox_server_scriptValToObjectPtr_511B60(v0);
		if (v3) {
			nox_xxx_unitSetFollow_5158C0(v2, v3);
		}
	}
	return 0;
}

//----- (00515910) --------------------------------------------------------
int nox_script_FollowGroup_515910() {
	int v0;            // esi
	int v1;            // edi
	int v2;            // eax
	unsigned char* v3; // eax
	int v5;            // [esp-4h] [ebp-Ch]

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v2) {
		v5 = v2;
		v3 = (unsigned char*)nox_server_scriptGetGroup_57C0A0(v1);
		nox_server_scriptExecuteFnForEachGroupObj_502670(v3, 0, nox_xxx_unitSetFollow_5158C0, v5);
	}
	return 0;
}

//----- (00515950) --------------------------------------------------------
int nox_script_AgressionLevel_515950() {
	int v0; // eax
	int v1; // eax
	int v3; // [esp+0h] [ebp-4h]

	v3 = nox_script_pop();
	v0 = nox_script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1) {
		nox_xxx_monsterSetAgressiveness_515980(v1, &v3);
	}
	return 0;
}

//----- (005159B0) --------------------------------------------------------
int nox_script_AggressionLevelGroup_5159B0() {
	int v0;            // eax
	unsigned char* v1; // eax
	int v3;            // [esp+0h] [ebp-4h]

	v3 = nox_script_pop();
	v0 = nox_script_pop();
	v1 = (unsigned char*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 0, nox_xxx_monsterSetAgressiveness_515980, (int)&v3);
	return 0;
}

//----- (005159E0) --------------------------------------------------------
int nox_script_HitLocation_5159E0() {
	int v0;   // eax
	int v1;   // eax
	float v3; // [esp+0h] [ebp-10h]
	float v4; // [esp+4h] [ebp-Ch]
	float2 v5;

	v4 = nox_script_popf();
	v3 = nox_script_popf();
	v0 = nox_script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1) {
		v5.field_0 = v3;
		v5.field_4 = v4;
		nox_xxx_monsterActionMelee_515A30(v1, (float2*)&v5);
	}
	return 0;
}

//----- (00515AE0) --------------------------------------------------------
int nox_script_HitLocationGroup_515AE0() {
	int v0;            // eax
	unsigned char* v1; // eax
	float2 v3;         // [esp+0h] [ebp-10h]
	float2 v4;         // [esp+8h] [ebp-8h]

	LODWORD(v3.field_4) = nox_script_pop();
	LODWORD(v3.field_0) = nox_script_pop();
	v0 = nox_script_pop();
	v4 = v3;
	v1 = (unsigned char*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 0, nox_xxx_monsterActionMelee_515A30, (int)&v4);
	return 0;
}

//----- (00515B30) --------------------------------------------------------
int nox_script_HitFarLocation_515B30() {
	int v0;    // eax
	int v1;    // eax
	int v3[2]; // [esp+0h] [ebp-10h]
	int v4[2]; // [esp+8h] [ebp-8h]

	v3[1] = nox_script_pop();
	v3[0] = nox_script_pop();
	v0 = nox_script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1) {
		*(uint64_t*)v4 = *(uint64_t*)v3;
		nox_xxx_monsterMissileAttack_515B80(v1, v4);
	}
	return 0;
}

//----- (00515BF0) --------------------------------------------------------
int nox_script_HitFarLocationGroup_515BF0() {
	int v0;            // eax
	unsigned char* v1; // eax
	int v3[2];         // [esp+0h] [ebp-10h]
	int v4[2];         // [esp+8h] [ebp-8h]

	v3[1] = nox_script_pop();
	v3[0] = nox_script_pop();
	v0 = nox_script_pop();
	*(uint64_t*)v4 = *(uint64_t*)v3;
	v1 = (unsigned char*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 0, nox_xxx_monsterMissileAttack_515B80, (int)v4);
	return 0;
}

//----- (00515C40) --------------------------------------------------------
int nox_script_SetRoamFlag_515C40(int a1) {
	char v1; // bl
	int v2;  // eax
	int v3;  // eax
	char v5; // [esp+1h] [ebp-1h]

	v5 = HIBYTE(a1);
	v1 = nox_script_pop();
	v2 = nox_script_pop();
	v3 = nox_server_scriptValToObjectPtr_511B60(v2);
	if (v3) {
		v5 = v1;
		sub_515C80(v3, &v5);
	}
	return 0;
}

//----- (00515CB0) --------------------------------------------------------
int nox_script_SetRoamFlagGroup_515CB0() {
	char v0;           // bl
	int v1;            // eax
	unsigned char* v2; // eax
	char v4;           // [esp+1h] [ebp-1h]

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v4 = v0;
	v2 = (unsigned char*)nox_server_scriptGetGroup_57C0A0(v1);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v2, 0, sub_515C80, (int)&v4);
	return 0;
}

//----- (00515CF0) --------------------------------------------------------
int nox_script_Attack_515CF0() {
	int v0; // edi
	int v1; // eax
	int v2; // esi
	int v3; // eax

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	if (v2) {
		v3 = nox_server_scriptValToObjectPtr_511B60(v0);
		nox_xxx_mobSetFightTarg_515D30(v2, v3);
	}
	return 0;
}

//----- (00515DB0) --------------------------------------------------------
int nox_script_AttackGroup_515DB0() {
	int v0;            // esi
	int v1;            // edi
	unsigned char* v2; // eax
	int v4;            // [esp-4h] [ebp-Ch]

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v4 = nox_server_scriptValToObjectPtr_511B60(v0);
	v2 = (unsigned char*)nox_server_scriptGetGroup_57C0A0(v1);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v2, 0, nox_xxx_mobSetFightTarg_515D30, v4);
	return 0;
}

//----- (00515DF0) --------------------------------------------------------
int nox_script_RetreatLevel_515DF0() {
	int v0; // eax
	int v1; // eax
	int v3; // [esp+0h] [ebp-4h]

	v3 = nox_script_pop();
	v0 = nox_script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1) {
		sub_515E20(v1, &v3);
	}
	return 0;
}

//----- (00515E50) --------------------------------------------------------
int nox_script_RetreatLevelGroup_515E50() {
	int v0;            // eax
	unsigned char* v1; // eax
	int v3;            // [esp+0h] [ebp-4h]

	v3 = nox_script_pop();
	v0 = nox_script_pop();
	v1 = (unsigned char*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 0, sub_515E20, (int)&v3);
	return 0;
}

//----- (00515E80) --------------------------------------------------------
int nox_script_SetResumeLevel_515E80() {
	int v0; // eax
	int v1; // eax
	int v3; // [esp+0h] [ebp-4h]

	v3 = nox_script_pop();
	v0 = nox_script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1) {
		sub_515EB0(v1, &v3);
	}
	return 0;
}

//----- (00515EE0) --------------------------------------------------------
int nox_script_SetResumeLevelGroup_515EE0() {
	int v0;            // eax
	unsigned char* v1; // eax
	int v3;            // [esp+0h] [ebp-4h]

	v3 = nox_script_pop();
	v0 = nox_script_pop();
	v1 = (unsigned char*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 0, sub_515EB0, (int)&v3);
	return 0;
}

//----- (00515F10) --------------------------------------------------------
int nox_script_RunAway_515F10() {
	int v0;    // ebx
	int v1;    // esi
	int v2;    // edi
	int v3;    // eax
	int v5[2]; // [esp+Ch] [ebp-8h]

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_script_pop();
	v5[0] = nox_server_scriptValToObjectPtr_511B60(v1);
	if (v5[0]) {
		v3 = nox_server_scriptValToObjectPtr_511B60(v2);
		if (v3) {
			v5[1] = v0;
			nox_server_scriptFleeFrom_515F70(v3, v5);
		}
	}
	return 0;
}

//----- (00516000) --------------------------------------------------------
int nox_script_RunAwayGroup_516000() {
	int v0;            // edi
	int v1;            // esi
	int v2;            // ebx
	unsigned char* v3; // eax
	int v5[2];         // [esp+Ch] [ebp-8h]

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_script_pop();
	v5[0] = nox_server_scriptValToObjectPtr_511B60(v1);
	if (v5[0]) {
		v5[1] = v0;
		v3 = (unsigned char*)nox_server_scriptGetGroup_57C0A0(v2);
		nox_server_scriptExecuteFnForEachGroupObj_502670(v3, 0, nox_server_scriptFleeFrom_515F70, (int)v5);
	}
	return 0;
}

//----- (00516060) --------------------------------------------------------
int nox_script_PauseObject_516060() {
	int v0; // eax
	int v1; // eax
	int v3; // [esp+0h] [ebp-4h]

	v3 = nox_script_pop();
	v0 = nox_script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1) {
		sub_516090(v1, &v3);
	}
	return 0;
}

//----- (005160F0) --------------------------------------------------------
int nox_script_PauseObjectGroup_5160F0() {
	int v0;            // eax
	unsigned char* v1; // eax
	int v3;            // [esp+0h] [ebp-4h]

	v3 = nox_script_pop();
	v0 = nox_script_pop();
	v1 = (unsigned char*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 0, sub_516090, (int)&v3);
	return 0;
}

//----- (00516120) --------------------------------------------------------
int nox_script_GetGold_516120() {
	int v0; // eax
	int v1; // eax
	int v2; // eax

	v0 = nox_script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1) {
		v2 = sub_4FA6D0(v1);
		nox_script_push(v2);
	} else {
		nox_script_push(0);
	}
	return 0;
}

//----- (00516160) --------------------------------------------------------
int nox_script_ChangeGold_516160() {
	int v0; // esi
	int v1; // eax
	int v2; // eax

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	if (v2) {
		sub_4FA620(v2, v0);
	}
	return 0;
}

//----- (00516190) --------------------------------------------------------
int nox_script_GiveExp_516190() {
	int v0; // esi
	int v1; // eax
	int v2; // eax

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	if (v2) {
		nox_xxx_plyrGiveExp_4EF3A0_exp_level(v2, *(float*)&v0);
	}
	return 0;
}

//----- (00516210) --------------------------------------------------------
int nox_script_HasClass_516210() {
	int v0;            // esi
	int v1;            // eax
	int result;        // eax
	const char* v3;    // ecx
	int v4;            // ebp
	const char* v5;    // ebx
	unsigned char* v6; // edi
	int v7;            // [esp+10h] [ebp-4h]

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v7 = nox_server_scriptValToObjectPtr_511B60(v1);
	if (v7) {
		v3 = *(const char**)getMemAt(0x587000, 237172);
		v4 = 1;
		if (*getMemU32Ptr(0x587000, 237172)) {
			v5 = nox_script_getString_512E40(v0);
			v6 = getMemAt(0x587000, 237172);
			while (strcmp(v3, v5)) {
				v3 = (const char*)*((uint32_t*)v6 + 1);
				v6 += 4;
				v4 *= 2;
				if (!v3) {
					return 0;
				}
			}
			nox_script_push((v4 & *(uint32_t*)(v7 + 8)) != 0);
		}
		result = 0;
	} else {
		nox_script_push(0);
		result = 0;
	}
	return result;
}

//----- (005162D0) --------------------------------------------------------
int nox_script_HasSubclass_5162D0() {
	int v0;            // eax
	int result;        // eax
	unsigned char* v2; // edi
	int v3;            // ebp
	const char* v4;    // ecx
	const char** i;    // [esp+10h] [ebp-10h]
	unsigned char* v7; // [esp+14h] [ebp-Ch]
	int v8;            // [esp+18h] [ebp-8h]
	int v9;            // [esp+1Ch] [ebp-4h]

	v8 = nox_script_pop();
	v0 = nox_script_pop();
	v9 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v9) {
		v2 = getMemAt(0x587000, 237304);
		v7 = getMemAt(0x587000, 237304);
		for (i = (const char**)getMemAt(0x587000, 237304);; i += 32) {
			v3 = 1;
			v4 = *i;
			if (*i) {
				break;
			}
		LABEL_8:
			v2 = v7 + 128;
			v7 += 128;
		}
		while (strcmp(v4, nox_script_getString_512E40(v8))) {
			v4 = (const char*)*((uint32_t*)v2 + 1);
			v2 += 4;
			v3 *= 2;
			if (!v4) {
				goto LABEL_8;
			}
		}
		nox_script_push((v3 & *(uint32_t*)(v9 + 12)) != 0);
		result = 0;
	} else {
		nox_script_push(0);
		result = 0;
	}
	return result;
}

//----- (005163C0) --------------------------------------------------------
int nox_script_DialogResult_5163C0() {
	int v0; // eax
	int v1; // eax
	int v2; // eax

	v0 = nox_script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1) {
		v2 = sub_548F40(v1);
		nox_script_push(v2);
	} else {
		nox_script_push(0);
	}
	return 0;
}

//----- (00516600) --------------------------------------------------------
int nox_script_StartupScreen_516600() {
	int i;  // esi
	int v1; // esi
	int v2; // edi

	for (i = nox_xxx_getFirstPlayerUnit_4DA7C0(); i; i = nox_xxx_getNextPlayerUnit_4DA7F0(i)) {
		if (*(uint8_t*)(*(uint32_t*)(*(uint32_t*)(i + 748) + 276) + 2064) == 31) {
			break;
		}
	}
	sub_4277B0(i, 0xEu);
	v1 = nox_xxx_inventoryGetFirst_4E7980(i);
	if (v1) {
		do {
			v2 = nox_xxx_inventoryGetNext_4E7990(v1);
			if (*(uint8_t*)(v1 + 8) & 0x40) {
				nox_xxx_delayedDeleteObject_4E5CC0(v1);
			}
			v1 = v2;
		} while (v2);
	}
	*getMemU32Ptr(0x5D4594, 2386832) = 1;
	sub_5165D0();
	return 0;
}

//----- (005166A0) --------------------------------------------------------
int nox_script_IsTalking_5166A0() {
	char* v0; // eax
	int v1;   // ecx

	v0 = nox_common_playerInfoFromNum_417090(31);
	v1 = 0;
	if (v0 && *(uint32_t*)(*(uint32_t*)(*((uint32_t*)v0 + 514) + 748) + 284)) {
		v1 = 1;
	}
	nox_script_push(v1);
	return 0;
}

//----- (005166E0) --------------------------------------------------------
int nox_script_PlayerIsTrading_5166E0() {
	char* v0; // eax
	int v1;   // ecx

	v0 = nox_common_playerInfoFromNum_417090(31);
	v1 = 0;
	if (v0 && *(uint32_t*)(*(uint32_t*)(*((uint32_t*)v0 + 514) + 748) + 280)) {
		v1 = 1;
	}
	nox_script_push(v1);
	return 0;
}

//----- (00516720) --------------------------------------------------------
int nox_script_MakeFriendly_516720() {
	char* v0; // esi
	int v1;   // eax
	int v2;   // eax
	int v3;   // ecx
	int v4;   // ecx

	v0 = nox_common_playerInfoFromNum_417090(31);
	v1 = nox_script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	if (v2) {
		v3 = *(uint32_t*)(v2 + 12);
		BYTE1(v3) |= 1u;
		*(uint32_t*)(v2 + 12) = v3;
		v4 = *((uint32_t*)v0 + 514);
		if (v4) {
			nox_xxx_unitSetOwner_4EC290(v4, v2);
		}
	}
	return 0;
}

//----- (00516760) --------------------------------------------------------
int nox_script_MakeEnemy_516760() {
	int v0; // eax
	int v1; // eax
	int v2; // edx

	v0 = nox_script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1) {
		v2 = *(uint32_t*)(v1 + 12);
		BYTE1(v2) &= 0xFEu;
		*(uint32_t*)(v1 + 12) = v2;
		nox_xxx_unitClearOwner_4EC300(v1);
	}
	return 0;
}

//----- (00516790) --------------------------------------------------------
int nox_script_builtin_516790(void* this) {
	int v1;   // eax
	int v2;   // eax
	void* v4; // [esp+0h] [ebp-4h]

	v4 = this;
	v1 = nox_script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	if (v2) {
		nox_script_push((*(uint32_t*)(v2 + 12) >> 8) & 1);
	} else {
		nox_script_push((int)v4);
	}
	return 0;
}

//----- (005167D0) --------------------------------------------------------
int nox_script_BecomePet_5167D0() {
	char* v0; // esi
	int v1;   // eax
	int v2;   // eax
	int v3;   // ecx

	v0 = nox_common_playerInfoFromNum_417090(31);
	v1 = nox_script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	if (v2) {
		v3 = *((uint32_t*)v0 + 514);
		if (v3) {
			nox_xxx_unitBecomePet_4E7B00(v3, v2);
		}
	}
	return 0;
}

//----- (00516810) --------------------------------------------------------
int nox_script_BecomeEnemy_516810() {
	char* v0;     // esi
	int v1;       // eax
	uint32_t* v2; // eax
	int v3;       // ecx

	v0 = nox_common_playerInfoFromNum_417090(31);
	v1 = nox_script_pop();
	v2 = (uint32_t*)nox_server_scriptValToObjectPtr_511B60(v1);
	if (v2) {
		v3 = *((uint32_t*)v0 + 514);
		if (v3) {
			nox_xxx_monsterRemoveMonitors_4E7B60(v3, v2);
		}
	}
	return 0;
}

//----- (00516850) --------------------------------------------------------
int nox_script_builtin_516850(void* this) {
	int v1;   // eax
	int v2;   // eax
	void* v4; // [esp+0h] [ebp-4h]

	v4 = this;
	v1 = nox_script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	if (v2) {
		nox_script_push((*(uint32_t*)(v2 + 12) & 0xFFu) >> 7);
	} else {
		nox_script_push((int)v4);
	}
	return 0;
}

//----- (00516890) --------------------------------------------------------
int nox_script_OblivionGive_516890() {
	uint32_t* v0; // edi
	int v1;       // esi
	int v2;       // ebx
	uint32_t* v3; // eax
	uint32_t* v4; // eax

	v0 = (uint32_t*)*((uint32_t*)nox_common_playerInfoFromNum_417090(31) + 514);
	v1 = 0;
	v2 = nox_script_pop();
	v3 = (uint32_t*)v0[126];
	if (v3) {
		while (!(v3[2] & 0x1000000) || !(v3[3] & 0x7800000)) {
			v3 = (uint32_t*)v3[124];
			if (!v3) {
				goto LABEL_7;
			}
		}
		v1 = (v3[4] >> 8) & 1;
		nox_xxx_delayedDeleteObject_4E5CC0((int)v3);
	}
LABEL_7:
	v4 = nox_xxx_playerRespawnItem_4EF750((int)v0, *(char**)getMemAt(0x587000, 247336 + 4 * v2), 0, 1, 1);
	if (v1) {
		nox_xxx_playerTryEquip_4F2F70(v0, (int)v4);
	}
	return 0;
}

//----- (00516A50) --------------------------------------------------------
int nox_script_DeleteObjectTimer_516A50() {
	int v0;       // esi
	int v1;       // eax
	uint32_t* v2; // eax

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = (uint32_t*)nox_server_scriptValToObjectPtr_511B60(v1);
	if (v2) {
		nox_xxx_unitSetDecayTime_511660(v2, v0);
	}
	return 0;
}

//----- (00516B40) --------------------------------------------------------
int nox_script_TrapSpells_516B40() {
	int v0; // ebp
	int v1; // ebx
	int v2; // edi
	int v3; // eax
	int v4; // eax
	int v5; // esi
	int v6; // eax
	int v7; // edi
	int v8; // ebx
	int v9; // eax

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_script_pop();
	v3 = nox_script_pop();
	v4 = nox_server_scriptValToObjectPtr_511B60(v3);
	v5 = v4;
	if (v4) {
		if (*(uint8_t*)(v4 + 8) & 2) {
			v6 = *(uint32_t*)(v4 + 12);
			if (v6 & 0x2000) {
				v7 = nox_xxx_spellNameToN_4243F0(nox_script_getString_512E40(v2));
				v8 = nox_xxx_spellNameToN_4243F0(nox_script_getString_512E40(v1));
				v9 = nox_xxx_spellNameToN_4243F0(nox_script_getString_512E40(v0));
				sub_516A80(v5, v7, v8, v9);
			}
		}
	}
	return 0;
}

//----- (00516BE0) --------------------------------------------------------
int nox_script_SetShopkeeperGreet_516BE0() {
	int v0; // esi
	int v1; // eax
	int v2; // eax

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	if (v2) {
		sub_548FE0(v2, nox_script_getString_512E40(v0));
	}
	return 0;
}

//----- (00516C30) --------------------------------------------------------
int nox_script_IsSummoned_516C30() {
	int v0; // eax
	int v1; // esi
	int v2; // eax

	v0 = nox_script_pop();
	v1 = 0;
	v2 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v2 && *(uint8_t*)(v2 + 8) & 2) {
		v1 = (*(uint32_t*)(*(uint32_t*)(v2 + 748) + 1440) >> 7) & 1;
	}
	nox_script_push(v1);
	return 0;
}

//----- (00516C70) --------------------------------------------------------
int nox_script_ZombieStayDown_516C70() {
	int v0; // eax
	int v1; // eax

	v0 = nox_script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1) {
		nox_xxx_zombieSetStayDead_516C90(v1);
	}
	return 0;
}

//----- (00516CB0) --------------------------------------------------------
int nox_script_ZombieStayDownGroup_516CB0() {
	int v0;            // eax
	unsigned char* v1; // eax

	v0 = nox_script_pop();
	v1 = (unsigned char*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 0, nox_xxx_zombieSetStayDead_516C90, 0);
	return 0;
}

//----- (00516CE0) --------------------------------------------------------
int nox_script_RaiseZombie_516CE0() {
	int v0; // eax
	int v1; // eax

	v0 = nox_script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1) {
		sub_516D00(v1);
	}
	return 0;
}

//----- (00516D40) --------------------------------------------------------
int nox_script_RaiseZombieGroup_516D40() {
	int v0;            // eax
	unsigned char* v1; // eax

	v0 = nox_script_pop();
	v1 = (unsigned char*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 0, sub_516D00, 0);
	return 0;
}

//----- (00516D70) --------------------------------------------------------
int nox_script_ObjIsGameball_516D70() {
	int v0; // eax
	int v1; // esi
	int v2; // eax

	v0 = nox_script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1) {
		v2 = *getMemU32Ptr(0x5D4594, 2386908);
		if (!*getMemU32Ptr(0x5D4594, 2386908)) {
			v2 = nox_xxx_getNameId_4E3AA0("GameBall");
			*getMemU32Ptr(0x5D4594, 2386908) = v2;
		}
		nox_script_push(*(unsigned short*)(v1 + 4) == v2);
	}
	return 0;
}

//----- (00516DC0) --------------------------------------------------------
int nox_script_ObjIsCrown_516DC0() {
	int v0; // eax
	int v1; // esi
	int v2; // eax

	v0 = nox_script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1) {
		v2 = *getMemU32Ptr(0x5D4594, 2386912);
		if (!*getMemU32Ptr(0x5D4594, 2386912)) {
			v2 = nox_xxx_getNameId_4E3AA0("Crown");
			*getMemU32Ptr(0x5D4594, 2386912) = v2;
		}
		nox_script_push(*(unsigned short*)(v1 + 4) == v2);
	}
	return 0;
}

//----- (00513F70) --------------------------------------------------------
int nox_script_Fn5E_513F70() {
	int v0;      // eax
	wchar_t* v1; // eax
	int v2;      // eax

	v0 = nox_script_pop();
	v1 = nox_strman_loadString_40F1D0(nox_script_getString_512E40(v0), 0,
									  "C:\\NoxPost\\src\\Server\\System\\CScrFunc.c", 2901);
	v2 = sub_512E80((int)v1);
	nox_script_push(v2);
	return 0;
}

//----- (00514A80) --------------------------------------------------------
int nox_script_ChatTimerSeconds_514A80() {
	short v0;    // di
	int v1;      // ebx
	int v2;      // eax
	int v3;      // esi
	char* v4;    // edx
	wchar_t* v5; // eax
	wchar_t v7;  // [esp-4h] [ebp-14h]
	int v8;      // [esp+Ch] [ebp-4h]

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_script_pop();
	v3 = nox_server_scriptValToObjectPtr_511B60(v2);
	if (v3) {
		v4 = nox_script_getString_512E40(v1);
		v7 = v0 * (uint16_t)nox_gameFPS;
		v8 = 0;
		v5 = nox_strman_loadString_40F1D0(v4, &v8, "C:\\NoxPost\\src\\Server\\System\\CScrFunc.c", 3629);
		nox_xxx_netSendChat_528AC0(v3, v5, v7);
		if (nox_common_gameFlags_check_40A5C0(2048)) {
			nox_xxx_playDialogFile_44D900(v8, 100);
		}
	}
	return 0;
}

//----- (00514B10) --------------------------------------------------------
int nox_script_ChatTimerFrames_514B10() {
	wchar_t v0;  // di
	int v1;      // ebx
	int v2;      // eax
	int v3;      // esi
	char* v4;    // ecx
	wchar_t* v5; // eax
	int v7;      // [esp+Ch] [ebp-4h]

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_script_pop();
	v3 = nox_server_scriptValToObjectPtr_511B60(v2);
	if (v3) {
		v4 = nox_script_getString_512E40(v1);
		v7 = 0;
		v5 = nox_strman_loadString_40F1D0(v4, &v7, "C:\\NoxPost\\src\\Server\\System\\CScrFunc.c", 3670);
		nox_xxx_netSendChat_528AC0(v3, v5, v0);
		if (v7) {
			if (nox_common_gameFlags_check_40A5C0(2048)) {
				nox_xxx_playDialogFile_44D900(v7, 100);
			}
		}
	}
	return 0;
}
