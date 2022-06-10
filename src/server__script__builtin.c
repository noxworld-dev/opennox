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
#include "operators.h"
#include "server__gamemech__explevel.h"
#include "server__magic__plyrspel.h"
#include "server__script__builtin.h"
#include "server__script__internal.h"
#include "server__script__panic.h"
#include "server__script__script.h"
#include "server__script__activator.h"
#include "common__system__team.h"

// TODO: move somewhere else
int nox_xxx_netSendChat_528AC0(int a1, wchar_t* a2, wchar_t a3);

extern unsigned int dword_5d4594_2386836;
extern unsigned int nox_xxx_wallSounds_2386840;
extern unsigned int nox_gameDisableMapDraw_5d4594_2650672;
extern unsigned int nox_gameFPS;
extern unsigned int nox_frame_xxx_2598000;

unsigned int dword_5d4594_3821636 = 0;
unsigned int dword_5d4594_3821640 = 0;
unsigned int dword_5d4594_1599628 = 0;
void* nox_script_objGold = 0;
unsigned int dword_5d4594_2386848 = 0;
unsigned int dword_5d4594_2386852 = 0;
void* nox_xxx_imagCasterUnit_1569664 = 0;

int nox_script_builtinGetF40() { return dword_5d4594_3821636; }

int nox_script_builtinGetF44() { return dword_5d4594_3821640; }

char nox_script_builtin_buf_xxx[64] = {0};

void nox_script_resetBuiltin() {
	dword_5d4594_3821640 = 0;
	nox_script_builtin_buf_xxx[0] = 0; // TODO: was = getMemByte(0x5D4594, 1599668);
	dword_5d4594_3821636 = 0;
}

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

//----- (00511F50) --------------------------------------------------------
int nox_script_openSecretWall_511F50() {
	int v0; // eax
	int v1; // eax

	v0 = nox_script_pop();
	v1 = nox_server_getWallAtGrid_410580(v0 >> 16, (unsigned short)v0);
	if (v1) {
		nox_xxx_wallOpen_511F80(v1);
	}
	return 0;
}

//----- (00512010) --------------------------------------------------------
int nox_script_openWallGroup_512010() {
	int v0;            // eax
	unsigned char* v1; // eax

	v0 = nox_script_pop();
	v1 = (unsigned char*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 2, nox_xxx_wallOpen_511F80, 0);
	return 0;
}

//----- (00512040) --------------------------------------------------------
int nox_script_closeWall_512040() {
	int v0; // eax
	int v1; // eax

	v0 = nox_script_pop();
	v1 = nox_server_getWallAtGrid_410580(v0 >> 16, (unsigned short)v0);
	if (v1) {
		nox_xxx_wallClose_512070(v1);
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

//----- (00512130) --------------------------------------------------------
int nox_script_toggleWall_512130() {
	int v0; // eax
	int v1; // eax

	v0 = nox_script_pop();
	v1 = nox_server_getWallAtGrid_410580(v0 >> 16, (unsigned short)v0);
	if (v1) {
		nox_xxx_wallToggle_512160(v1);
	}
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

//----- (00512290) --------------------------------------------------------
int nox_script_wallBreak_512290() {
	int v0; // eax
	int v1; // eax

	v0 = nox_script_pop();
	v1 = nox_server_getWallAtGrid_410580(v0 >> 16, (unsigned short)v0);
	if (v1) {
		nox_xxx_wallPreDestroyByPtr_5122C0(v1);
	}
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

//----- (00512320) --------------------------------------------------------
int nox_script_secondTimer_512320() {
	int v0; // esi
	int v1; // eax

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	nox_script_activatorTimer_51ACA0(v1 * nox_gameFPS, v0, 0);
	return 0;
}

//----- (00512350) --------------------------------------------------------
int nox_script_frameTimer_512350() {
	int v0; // esi
	int v1; // eax

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	nox_script_activatorTimer_51ACA0(v1, v0, 0);
	return 0;
}

//----- (00512370) --------------------------------------------------------
int nox_script_moverOrMonsterGo_512370() {
	int v0;       // edi
	int v1;       // eax
	int v2;       // eax
	int v3;       // esi
	int v4;       // eax
	uint32_t* v5; // eax

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	v3 = v2;
	if (v2) {
		v4 = *(uint32_t*)(v2 + 16);
		if ((v4 & 0x8000) == 0) {
			v5 = nox_server_getWaypointById_579C40(v0);
			if (v5) {
				nox_server_scriptMoveTo_5123C0(v3, (int)v5);
			}
		}
	}
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
	return nox_xxx_unitAddToUpdatable_4DA8D0((int)a1);
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

//----- (00512560) --------------------------------------------------------
int nox_script_lookAtDirection_512560() {
	int v0; // esi
	int v1; // eax
	int v2; // eax
	int v3; // ecx

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	if (v2) {
		if (*(uint8_t*)(v2 + 8) & 2) {
			v3 = *(uint32_t*)(v2 + 16);
			if ((v3 & 0x8000) == 0) {
				nox_xxx_monsterLookAt_5125A0(v2, v0);
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

//----- (00512670) --------------------------------------------------------
int nox_script_objectOn_512670() {
	int v0; // eax
	int v1; // eax

	v0 = nox_script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1) {
		nox_xxx_objectSetOn_4E75B0(v1);
	}
	return 0;
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

//----- (005126D0) --------------------------------------------------------
int nox_script_waypointOn_5126D0() {
	int v0;       // eax
	uint32_t* v1; // eax

	v0 = nox_script_pop();
	v1 = nox_server_getWaypointById_579C40(v0);
	if (v1) {
		v1[120] |= 1u;
	}
	return 0;
}

//----- (005126F0) --------------------------------------------------------
int nox_script_waypointGroupOn_5126F0() {
	int v0;            // eax
	unsigned char* v1; // eax

	v0 = nox_script_pop();
	v1 = (unsigned char*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 1, sub_512720, 0);
	return 0;
}

//----- (00512730) --------------------------------------------------------
int nox_script_objectOff_512730() {
	int v0; // eax
	int v1; // eax

	v0 = nox_script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1) {
		nox_xxx_objectSetOff_4E7600(v1);
	}
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

//----- (00512790) --------------------------------------------------------
int nox_script_waypointOff_512790() {
	int v0;       // eax
	uint32_t* v1; // eax

	v0 = nox_script_pop();
	v1 = nox_server_getWaypointById_579C40(v0);
	if (v1) {
		v1[120] &= 0xFFFFFFFE;
	}
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

//----- (005127F0) --------------------------------------------------------
int nox_script_toggleObject_5127F0() {
	int v0; // eax
	int v1; // eax

	v0 = nox_script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1) {
		nox_xxx_objectToggle_4E7650(v1);
	}
	return 0;
}

//----- (00512810) --------------------------------------------------------
int nox_script_toggleObjectGroup_512810() {
	int v0;            // eax
	unsigned char* v1; // eax

	v0 = nox_script_pop();
	v1 = (unsigned char*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 0, sub_512840, 0);
	return 0;
}

//----- (00512850) --------------------------------------------------------
int nox_script_toggleWaypoint_512850() {
	int v0;       // eax
	uint32_t* v1; // eax

	v0 = nox_script_pop();
	v1 = nox_server_getWaypointById_579C40(v0);
	if (v1) {
		v1[120] ^= 1u;
	}
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

//----- (005128B0) --------------------------------------------------------
int nox_script_deleteObject_5128B0() {
	int v0; // eax
	int v1; // eax

	v0 = nox_script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1) {
		nox_xxx_delayedDeleteObject_4E5CC0(v1);
	}
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

//----- (00512910) --------------------------------------------------------
int nox_script_followNearestWaypoint_512910() {
	int v0; // eax
	int v1; // eax

	v0 = nox_script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1) {
		nox_xxx_scriptMonsterRoam_512930(v1);
	}
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

//----- (005129C0) --------------------------------------------------------
int nox_script_getObject2_5129C0() {
	int v0; // eax

	v0 = nox_script_pop();
	nox_server_scriptValToObjectPtr_511B60(v0);
	return 0;
}

//----- (005129E0) --------------------------------------------------------
int nox_script_getObject3_5129E0() {
	int v0; // eax

	v0 = nox_script_pop();
	nox_server_scriptValToObjectPtr_511B60(v0);
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
int nox_script_gotoHome_512A00() {
	int v0;     // eax
	int result; // eax
	int v2;     // esi

	v0 = nox_script_pop();
	result = nox_server_scriptValToObjectPtr_511B60(v0);
	v2 = result;
	if (v2) {
		nox_server_gotoHome(v2);
		result = 0;
	}
	return result;
}

//----- (00512AC0) --------------------------------------------------------
int nox_script_audioEven_512AC0() {
	int v0;     // esi
	int v1;     // edi
	float2* v2; // eax
	int v3;     // eax
	float2* v5; // [esp-Ch] [ebp-14h]

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = (float2*)nox_server_getWaypointById_579C40(v0);
	if (v2) {
		v5 = v2 + 1;
		v3 = nox_xxx_utilFindSound_40AF50(nox_script_getString_512E40(v1));
		nox_xxx_audCreate_501A30(v3, v5, 0, 0);
	}
	return 0;
}

//----- (00512C10) --------------------------------------------------------
int nox_script_returnOne_512C10() { return 1; }

//----- (00512C20) --------------------------------------------------------
int nox_script_unlockDoor_512C20() {
	int v0; // eax
	int v1; // eax

	v0 = nox_script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1 && (*(uint8_t*)(v1 + 8) & 0x80)) {
		*(uint8_t*)(*(uint32_t*)(v1 + 748) + 1) = 0;
		nox_xxx_aud_501960(234, v1, 0, 0);
	}
	return 0;
}

//----- (00512C60) --------------------------------------------------------
int nox_script_lockDoor_512C60() {
	int v0; // eax
	int v1; // eax

	v0 = nox_script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1 && (*(uint8_t*)(v1 + 8) & 0x80)) {
		*(uint8_t*)(*(uint32_t*)(v1 + 748) + 1) = 5;
		nox_xxx_aud_501960(233, v1, 0, 0);
	}
	return 0;
}

//----- (00512CA0) --------------------------------------------------------
int nox_script_isOn_512CA0() {
	int v0;     // eax
	int v1;     // eax
	int result; // eax

	v0 = nox_script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1 && *(uint32_t*)(v1 + 16) & 0x1000000) {
		nox_script_push(1);
		result = 0;
	} else {
		nox_script_push(0);
		result = 0;
	}
	return result;
}

//----- (00512CE0) --------------------------------------------------------
int nox_script_wpIsEnabled_512CE0() {
	int v0;       // eax
	uint32_t* v1; // eax
	int result;   // eax

	v0 = nox_script_pop();
	v1 = nox_server_getWaypointById_579C40(v0);
	if (v1 && v1[120] & 1) {
		nox_script_push(1);
		result = 0;
	} else {
		nox_script_push(0);
		result = 0;
	}
	return result;
}

//----- (00512D20) --------------------------------------------------------
int nox_script_doorIsLocked_512D20() {
	int v0;     // eax
	int v1;     // eax
	int result; // eax

	v0 = nox_script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1 && (*(uint8_t*)(v1 + 8) & 0x80)) {
		nox_script_push(*(uint8_t*)(*(uint32_t*)(v1 + 748) + 1) != 0);
		result = 0;
	} else {
		nox_script_push(0);
		result = 0;
	}
	return result;
}

//----- (00512D70) --------------------------------------------------------
int nox_script_randomFloat_512D70() {
	int v0; // esi
	int v1; // eax
	int v3; // [esp+0h] [ebp-4h]

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	*(float*)&v3 = nox_common_randomFloat_416030(*(float*)&v1, *(float*)&v0);
	nox_script_push(v3);
	return 0;
}

//----- (00512DB0) --------------------------------------------------------
int nox_script_randomInt_512DB0() {
	int v0; // esi
	int v1; // eax
	int v2; // eax

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_common_randomInt_415FA0(v1, v0);
	nox_script_push(v2);
	return 0;
}

//----- (00512DE0) --------------------------------------------------------
int nox_script_timerSecSpecial_512DE0() {
	int v0; // esi
	int v1; // edi
	int v2; // eax

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_script_pop();
	nox_script_activatorTimer_51ACA0(v2 * nox_gameFPS, v0, v1);
	return 0;
}

//----- (00512E10) --------------------------------------------------------
int nox_script_specialTimer_512E10() {
	int v0; // esi
	int v1; // edi
	int v2; // eax

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_script_pop();
	nox_script_activatorTimer_51ACA0(v2, v0, v1);
	return 0;
}

//----- (00512EA0) --------------------------------------------------------
int nox_script_intToString_512EA0() {
	int v0; // eax
	int v1; // eax

	v0 = nox_script_pop();
	_itoa(v0, (char*)getMemAt(0x973F18, 22280), 10);
	v1 = nox_script_addString_512E40((char*)getMemAt(0x973F18, 22280));
	nox_script_push(v1);
	return 0;
}

//----- (00512ED0) --------------------------------------------------------
int nox_script_floatToString_512ED0() {
	float v0; // eax
	int v1;   // eax

	v0 = nox_script_popf();
	nox_sprintf((char*)getMemAt(0x973F18, 22280), "%f", v0, v0);
	v1 = nox_script_addString_512E40((char*)getMemAt(0x973F18, 22280));
	nox_script_push(v1);
	return 0;
}

//----- (00512F10) --------------------------------------------------------
int nox_script_create_512F10() {
	int v0;       // esi
	int v1;       // edi
	float* v2;    // esi
	uint32_t* v3; // eax
	uint32_t* v4; // edi

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = (float*)nox_server_getWaypointById_579C40(v0);
	if (v2) {
		v3 = nox_xxx_newObjectByTypeID_4E3810(nox_script_getString_512E40(v1));
		v4 = v3;
		if (!v3) {
			nox_script_push(0);
			return 0;
		}
		nox_xxx_createAt_4DAA50((int)v3, 0, v2[2], v2[3]);
		nox_script_push(v4[11]);
	}
	return 0;
}

//----- (00512F80) --------------------------------------------------------
int nox_script_damage_512F80() {
	int v0;    // edi
	int v1;    // ebx
	int v2;    // ebp
	int v3;    // eax
	int v4;    // esi
	int v6[3]; // [esp+10h] [ebp-Ch]

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_script_pop();
	v3 = nox_script_pop();
	v4 = nox_server_scriptValToObjectPtr_511B60(v3);
	if (v4) {
		v6[0] = nox_server_scriptValToObjectPtr_511B60(v2);
		v6[1] = v1;
		v6[2] = v0;
		sub_512FE0(v4, v6);
	}
	return 0;
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

//----- (00513070) --------------------------------------------------------
int nox_script_builtin_513070() {
	int v0;    // edi
	int v1;    // eax
	int v2;    // esi
	float v4;  // [esp+8h] [ebp-10h]
	int v5[3]; // [esp+Ch] [ebp-Ch]

	v4 = nox_script_popf();
	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	if (v2) {
		v5[1] = v0;
		v5[0] = (long long)v4;
		sub_5130E0(v2, v5);
		nox_script_push(v5[2]);
	} else {
		nox_script_push(0);
	}
	return 0;
}

//----- (00513160) --------------------------------------------------------
int nox_script_builtin_513160() {
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

//----- (005131C0) --------------------------------------------------------
int nox_script_awardSpell_5131C0() {
	int v0;     // esi
	int v1;     // edi
	int v2;     // esi
	int result; // eax
	int v4;     // eax
	int v5;     // eax

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_xxx_spellNameToN_4243F0(nox_script_getString_512E40(v0));
	if (v2) {
		v4 = nox_server_scriptValToObjectPtr_511B60(v1);
		if (v4) {
			v5 = nox_xxx_spellGrantToPlayer_4FB550(v4, v2, 1, 0, 0);
			nox_script_push(v5);
		} else {
			nox_script_push(0);
		}
		result = 0;
	} else {
		nox_script_push(0);
		result = 0;
	}
	return result;
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

//----- (005132E0) --------------------------------------------------------
int nox_script_enchant_5132E0() {
	int v0;    // esi
	int v1;    // ebx
	int v2;    // esi
	int v3;    // edi
	float v5;  // [esp+Ch] [ebp-54h]
	int v6[2]; // [esp+18h] [ebp-48h]

	v5 = nox_script_popf();
	v0 = nox_script_pop();
	v1 = nox_script_pop();
	const char* v8 = nox_script_getString_512E40(v0);
	v2 = nox_xxx_enchantByName_424880(v8);
	if (v2 != -1) {
		v3 = nox_server_scriptValToObjectPtr_511B60(v1);
		if (v3) {
			v6[0] = v2;
			v6[1] = (long long)((double)nox_gameFPS * v5);
			nox_xxx_enchantUnit_513390(v3, v6);
		}
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

//----- (00513460) --------------------------------------------------------
int nox_script_getHost_513460() {
	int v0; // eax

	v0 = *((uint32_t*)nox_common_playerInfoFromNum_417090(31) + 514);
	if (v0) {
		nox_script_push(*(uint32_t*)(v0 + 44));
	} else {
		nox_script_push(0);
	}
	return 0;
}

//----- (00513490) --------------------------------------------------------
int nox_script_objectGet_513490() {
	int v0;      // eax
	char v2[76]; // [esp+4h] [ebp-4Ch]

	strncpy(v2, nox_script_getString_512E40(nox_script_pop()), sizeof(v2) - 1);
	strncat(v2, nox_script_builtin_buf_xxx, sizeof(v2) - 1);
	v0 = nox_xxx_getObjectByScrName_4DA4F0(v2);
	if (v0) {
		nox_script_push(*(uint32_t*)(v0 + 44));
	} else {
		nox_script_push(0);
	}
	return 0;
}

//----- (00513530) --------------------------------------------------------
int nox_script_getObjectX_513530() {
	int v0; // eax
	int v1; // eax

	v0 = nox_script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1) {
		nox_script_push(*(uint32_t*)(v1 + 56));
	} else {
		nox_script_push(0);
	}
	return 0;
}

//----- (00513570) --------------------------------------------------------
int nox_script_getWaypointX_513570() {
	int v0;       // eax
	uint32_t* v1; // eax

	v0 = nox_script_pop();
	v1 = nox_server_getWaypointById_579C40(v0);
	if (v1) {
		nox_script_push(v1[2]);
	} else {
		nox_script_push(0);
	}
	return 0;
}

//----- (005135B0) --------------------------------------------------------
int nox_script_getObjectY_5135B0() {
	int v0; // eax
	int v1; // eax

	v0 = nox_script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1) {
		nox_script_push(*(uint32_t*)(v1 + 60));
	} else {
		nox_script_push(0);
	}
	return 0;
}

//----- (005135F0) --------------------------------------------------------
int nox_script_getWaypointY_5135F0() {
	int v0;       // eax
	uint32_t* v1; // eax

	v0 = nox_script_pop();
	v1 = nox_server_getWaypointById_579C40(v0);
	if (v1) {
		nox_script_push(v1[3]);
	} else {
		nox_script_push(0);
	}
	return 0;
}

//----- (00513630) --------------------------------------------------------
int nox_script_unitHeight_513630() {
	int v0; // eax
	int v1; // eax

	v0 = nox_script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1) {
		nox_script_push(*(uint32_t*)(v1 + 104));
	} else {
		nox_script_push(0);
	}
	return 0;
}

//----- (00513670) --------------------------------------------------------
int nox_script_getUnitLook_513670() {
	int v0; // eax
	int v1; // eax

	v0 = nox_script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1) {
		nox_script_push(*(short*)(v1 + 124));
	} else {
		nox_script_push(0);
	}
	return 0;
}

//----- (005136A0) --------------------------------------------------------
int nox_script_moveObject_5136A0() {
	int v0;    // eax
	int v1;    // eax
	float2 v3; // [esp+0h] [ebp-Ch]
	float v4;  // [esp+8h] [ebp-4h]

	v4 = nox_script_popf();
	LODWORD(v3.field_0) = nox_script_pop();
	v0 = nox_script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1) {
		v3.field_0 = (double)nox_script_builtinGetF40() + v3.field_0;
		v3.field_4 = (double)nox_script_builtinGetF44() + v4;
		nox_xxx_unitMove_4E7010(v1, &v3);
	}
	return 0;
}

//----- (00513700) --------------------------------------------------------
int nox_script_moveWaypoint_513700() {
	int v0;    // eax
	float* v1; // eax
	float v3;  // [esp+0h] [ebp-8h]
	float v4;  // [esp+4h] [ebp-4h]

	v4 = nox_script_popf();
	v3 = nox_script_popf();
	v0 = nox_script_pop();
	v1 = (float*)nox_server_getWaypointById_579C40(v0);
	if (v1) {
		v1[2] = (double)nox_script_builtinGetF40() + v3;
		v1[3] = (double)nox_script_builtinGetF44() + v4;
	}
	return 0;
}

//----- (00513750) --------------------------------------------------------
int nox_script_raise_513750() {
	int v0; // esi
	int v1; // eax
	int v2; // eax

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	if (v2) {
		nox_xxx_unitRaise_4E46F0(v2, *(float*)&v0);
	}
	return 0;
}

//----- (00513780) --------------------------------------------------------
int nox_script_faceAngle_513780() {
	int v0;          // esi
	int v1;          // eax
	int v2;          // eax
	unsigned int v3; // ecx

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	if (v2) {
		v3 = v0;
		if (v0 < 0) {
			v3 = v0 + ((unsigned int)(255 - v0) >> 8 << 8);
		}
		if ((int)v3 >= 256) {
			LOWORD(v3) = -256 * (v3 >> 8) + v3;
		}
		*(uint16_t*)(v2 + 126) = v3;
		*(uint16_t*)(v2 + 124) = v3;
	}
	return 0;
}

//----- (005137D0) --------------------------------------------------------
int nox_script_pushObject_5137D0() {
	int v0;   // eax
	int v1;   // eax
	float v3; // [esp+0h] [ebp-8h]
	float v4; // [esp+4h] [ebp-4h]

	v4 = nox_script_popf();
	v3 = nox_script_popf();
	v0 = nox_script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1) {
		*(float*)(v1 + 88) = v3 + *(float*)(v1 + 88);
		*(float*)(v1 + 92) = v4 + *(float*)(v1 + 92);
	}
	return 0;
}

//----- (00513820) --------------------------------------------------------
int nox_script_pushObjectTo_513820() {
	int v0;    // eax
	float* v1; // eax
	double v2; // st7
	double v3; // st6
	float v5;  // [esp+0h] [ebp-Ch]
	float v6;  // [esp+0h] [ebp-Ch]
	float v7;  // [esp+4h] [ebp-8h]
	float v8;  // [esp+8h] [ebp-4h]
	float v9;  // [esp+8h] [ebp-4h]

	v5 = nox_script_popf();
	v8 = nox_script_popf();
	v7 = nox_script_popf();
	v0 = nox_script_pop();
	v1 = (float*)nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1) {
		v2 = v1[14] - v8 + (double)nox_script_builtinGetF40();
		v3 = v1[15] - v5 + (double)nox_script_builtinGetF44();
		v6 = v3;
		v9 = sqrt(v3 * v6 + v2 * v2);
		v1[22] = v7 * v2 / v9 + v1[22];
		v1[23] = v7 * v6 / v9 + v1[23];
	}
	return 0;
}

//----- (005138B0) --------------------------------------------------------
int nox_script_getFirstInvItem_5138B0() {
	int v0; // eax
	int v1; // esi
	int v2; // eax
	int v3; // eax

	v0 = nox_script_pop();
	v1 = 0;
	v2 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v2) {
		v3 = *(uint32_t*)(v2 + 504);
		if (v3) {
			v1 = *(uint32_t*)(v3 + 44);
		}
	}
	nox_script_push(v1);
	return 0;
}

//----- (005138E0) --------------------------------------------------------
int nox_script_getNextInvItem_5138E0() {
	int v0; // eax
	int v1; // esi
	int v2; // eax
	int v3; // eax

	v0 = nox_script_pop();
	v1 = 0;
	v2 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v2) {
		v3 = *(uint32_t*)(v2 + 496);
		if (v3) {
			v1 = *(uint32_t*)(v3 + 44);
		}
	}
	nox_script_push(v1);
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

//----- (00513C60) --------------------------------------------------------
int nox_script_builtin_513C60() { return 0; }

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

//----- (00513F10) --------------------------------------------------------
int nox_script_fn58_513F10() {
	nox_script_pop();
	nox_script_pop();
	return 0;
}

//----- (00513F20) --------------------------------------------------------
int nox_script_fn59_513F20() {
	nox_script_pop();
	nox_script_pop();
	return 0;
}

//----- (00513F30) --------------------------------------------------------
int nox_script_fn5A_513F30() {
	nox_script_pop();
	nox_script_pop();
	return 0;
}

//----- (00513F40) --------------------------------------------------------
int nox_script_fn5B_513F40() {
	nox_script_pop();
	nox_script_pop();
	return 0;
}

//----- (00513F50) --------------------------------------------------------
int nox_script_Fn5C_513F50() {
	nox_script_pop();
	nox_script_pop();
	return 0;
}

//----- (00513F60) --------------------------------------------------------
int nox_script_Fn5D_513F60() {
	nox_script_pop();
	nox_script_pop();
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

//----- (005141F0) --------------------------------------------------------
int nox_script_CancelTimer_5141F0() {
	int v0; // eax
	int v1; // eax

	v0 = nox_script_pop();
	v1 = nox_script_activatorCancel_51AD60(v0);
	nox_script_push(v1 != 0);
	return 0;
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
int nox_script_GroupSetOwner_5144C0() {
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
int nox_script_SetOwnerGroup_514510() {
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
int nox_script_builtin_514570() {
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
int nox_script_builtin_5145F0() {
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
int nox_script_builtin_514630() {
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
int nox_script_builtin_5146B0() {
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
int nox_script_builtin_514730() {
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

//----- (00514800) --------------------------------------------------------
int nox_script_Waypoint_514800() {
	int* v0;     // eax
	char v2[76]; // [esp+4h] [ebp-4Ch]

	strncpy(v2, nox_script_getString_512E40(nox_script_pop()), sizeof(v2) - 1);
	strncat(v2, nox_script_builtin_buf_xxx, sizeof(v2) - 1);
	v0 = (int*)nox_xxx_waypointByName_579E30(v2);
	if (v0) {
		nox_script_push(*v0);
	} else {
		nox_script_push(0);
	}
	return 0;
}

//----- (005148A0) --------------------------------------------------------
int nox_script_GetWaypointGroup_5148A0() {
	int v0;      // eax
	char v2[76]; // [esp+4h] [ebp-4Ch]

	strncpy(v2, nox_script_getString_512E40(nox_script_pop()), sizeof(v2) - 1);
	strncat(v2, nox_script_builtin_buf_xxx, sizeof(v2) - 1);
	v0 = nox_server_scriptGetMapGroupByName_57C280(v2, 1);
	if (v0) {
		nox_script_push(*(uint32_t*)(v0 + 4));
	} else {
		nox_script_push(0);
	}
	return 0;
}

//----- (00514940) --------------------------------------------------------
int nox_script_GetObjectGroup_514940() {
	int v0;      // eax
	char v2[76]; // [esp+4h] [ebp-4Ch]

	strncpy(v2, nox_script_getString_512E40(nox_script_pop()), sizeof(v2) - 1);
	strncat(v2, nox_script_builtin_buf_xxx, sizeof(v2) - 1);
	v0 = nox_server_scriptGetMapGroupByName_57C280(v2, 0);
	if (v0) {
		nox_script_push(*(uint32_t*)(v0 + 4));
	} else {
		nox_script_push(0);
	}
	return 0;
}

//----- (005149E0) --------------------------------------------------------
int nox_script_GetWallGroup_5149E0() {
	int v0; // eax
	char v2[76];

	strncpy(v2, nox_script_getString_512E40(nox_script_pop()), sizeof(v2) - 1);
	strncat(v2, nox_script_builtin_buf_xxx, sizeof(v2) - 1);
	v0 = nox_server_scriptGetMapGroupByName_57C280(v2, 2);
	if (v0) {
		nox_script_push(*(uint32_t*)(v0 + 4));
	} else {
		nox_script_push(0);
	}
	return 0;
}

//----- (00514BA0) --------------------------------------------------------
int nox_script_Pop2_74_514BA0() {
	nox_script_pop();
	nox_script_pop();
	return 0;
}

//----- (00514BB0) --------------------------------------------------------
int nox_script_RemoveChat_514BB0() {
	int v0;       // eax
	uint32_t* v1; // eax

	v0 = nox_script_pop();
	v1 = (uint32_t*)nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1) {
		nox_xxx_netKillChat_528D00(v1);
	}
	return 0;
}

//----- (00514BD0) --------------------------------------------------------
int nox_script_NoChatAll_514BD0() {
	nox_xxx_destroyEveryChatMB_528D60();
	return 0;
}

//----- (00514BE0) --------------------------------------------------------
int nox_script_JournalQuest_514BE0() {
	int v0; // esi
	int v1; // eax

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	nox_xxx_journalQuestSet_500540(nox_script_getString_512E40(v0), v1);
	return 0;
}

//----- (00514C10) --------------------------------------------------------
int nox_script_JournalQuestBool_514C10() {
	int v0; // esi
	int v1; // eax

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	nox_xxx_journalQuestSetBool_5006B0(nox_script_getString_512E40(v0), v1);
	return 0;
}

//----- (00514C40) --------------------------------------------------------
int nox_script_JournalGetQuest_514C40() {
	int v0; // eax
	int v1; // eax

	v0 = nox_script_pop();
	v1 = sub_500750(nox_script_getString_512E40(v0));
	nox_script_push(v1);
	return 0;
}

//----- (00514C60) --------------------------------------------------------
int nox_script_JournalGetQuestBool_514C60() {
	int v0; // eax
	int v2; // [esp+0h] [ebp-4h]

	v0 = nox_script_pop();
	*(float*)&v2 = sub_500770((char*)nox_script_getString_512E40(v0));
	nox_script_push(v2);
	return 0;
}

//----- (00514C90) --------------------------------------------------------
int nox_script_RestoreQuestStatus_514C90() {
	int v0; // eax

	v0 = nox_script_pop();
	sub_5007E0(nox_script_getString_512E40(v0));
	return 0;
}

//----- (00514CB0) --------------------------------------------------------
int nox_script_ObjIsTrigger_514CB0() {
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
int nox_script_builtin_514CF0() {
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
int nox_script_ForceDialog_514ED0() {
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

//----- (00514F10) --------------------------------------------------------
int nox_script_builtin_514F10() {
	int v0;     // ebp
	int v1;     // esi
	int v2;     // eax
	int v3;     // ebx
	int v4;     // eax
	int v5;     // edi
	int v6;     // eax
	int v7;     // esi
	float2 v9;  // [esp+10h] [ebp-14h]
	int v10[3]; // [esp+18h] [ebp-Ch]

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_script_pop();
	v3 = nox_xxx_spellNameToN_4243F0(nox_script_getString_512E40(v2));
	if (v3) {
		v4 = nox_server_scriptValToObjectPtr_511B60(v1);
		v5 = v4;
		if (v4) {
			if (!(*(uint32_t*)(v4 + 16) & 0x8020)) {
				v6 = nox_server_scriptValToObjectPtr_511B60(v0);
				v7 = v6;
				if (v6) {
					v9.field_0 = *(float*)(v6 + 56) - *(float*)(v5 + 56);
					v9.field_4 = *(float*)(v6 + 60) - *(float*)(v5 + 60);
					*(uint16_t*)(v5 + 124) = nox_xxx_math_509ED0(&v9);
					v10[0] = v7;
					v10[1] = *(uint32_t*)(v7 + 56);
					v10[2] = *(uint32_t*)(v7 + 60);
					nox_xxx_castSpellByUser_4FDD20(v3, (uint32_t*)v5, v10);
				}
			}
		}
	}
	return 0;
}

//----- (00514FC0) --------------------------------------------------------
int nox_script_builtin_514FC0() {
	int v0;       // esi
	int v1;       // eax
	int v2;       // edi
	int v3;       // eax
	uint32_t* v4; // esi
	float v6;     // [esp+8h] [ebp-1Ch]
	float v7;     // [esp+Ch] [ebp-18h]
	float2 v8;    // [esp+10h] [ebp-14h]
	float v9[3];  // [esp+18h] [ebp-Ch]

	v7 = nox_script_popf();
	v6 = nox_script_popf();
	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_xxx_spellNameToN_4243F0(nox_script_getString_512E40(v1));
	if (v2) {
		v3 = nox_server_scriptValToObjectPtr_511B60(v0);
		v4 = (uint32_t*)v3;
		if (v3) {
			v8.field_0 = v6 - *(float*)(v3 + 56);
			v8.field_4 = v7 - *(float*)(v3 + 60);
			*(uint16_t*)(v3 + 124) = nox_xxx_math_509ED0(&v8);
			v9[0] = 0.0;
			v9[1] = v6;
			v9[2] = v7;
			nox_xxx_castSpellByUser_4FDD20(v2, v4, v9);
		}
	}
	return 0;
}

//----- (00515060) --------------------------------------------------------
int nox_script_builtin_515060() {
	int v0;    // esi
	int v1;    // eax
	int v2;    // edi
	int v3;    // esi
	float2 v5; // [esp+8h] [ebp-1Ch]
	float2 v6; // [esp+10h] [ebp-14h]
	int v7[3]; // [esp+18h] [ebp-Ch]

	v0 = nox_script_pop();
	LODWORD(v5.field_4) = nox_script_pop();
	LODWORD(v5.field_0) = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_xxx_spellNameToN_4243F0(nox_script_getString_512E40(v1));
	if (v2) {
		v3 = nox_server_scriptValToObjectPtr_511B60(v0);
		if (v3) {
			v6 = v5;
			nox_xxx_unitMove_4E7010(nox_xxx_imagCasterUnit_1569664, &v6);
			v6.field_0 = *(float*)(v3 + 56) - v5.field_0;
			v6.field_4 = *(float*)(v3 + 60) - v5.field_4;
			*(uint16_t*)((uint32_t)nox_xxx_imagCasterUnit_1569664 + 124) = nox_xxx_math_509ED0(&v6);
			v7[0] = v3;
			v7[1] = *(uint32_t*)(v3 + 56);
			v7[2] = *(uint32_t*)(v3 + 60);
			nox_xxx_castSpellByUser_4FDD20(v2, nox_xxx_imagCasterUnit_1569664, &v7);
		}
	}
	return 0;
}

//----- (00515130) --------------------------------------------------------
int nox_script_cast_515130() {
	int v0;      // eax
	int v1;      // esi
	float2 v3;   // [esp+4h] [ebp-24h]
	float v4;    // [esp+Ch] [ebp-1Ch]
	float v5;    // [esp+10h] [ebp-18h]
	float2 v6;   // [esp+14h] [ebp-14h]
	float v7[3]; // [esp+1Ch] [ebp-Ch]

	v5 = nox_script_popf();
	v4 = nox_script_popf();
	LODWORD(v3.field_4) = nox_script_pop();
	LODWORD(v3.field_0) = nox_script_pop();
	v0 = nox_script_pop();
	v1 = nox_xxx_spellNameToN_4243F0(nox_script_getString_512E40(v0));
	if (v1) {
		v6 = v3;
		nox_xxx_unitMove_4E7010(nox_xxx_imagCasterUnit_1569664, &v6);
		v6.field_0 = v4 - v3.field_0;
		v6.field_4 = v5 - v3.field_4;
		*(uint16_t*)((uint32_t)nox_xxx_imagCasterUnit_1569664 + 124) = nox_xxx_math_509ED0(&v6);
		v7[1] = v4;
		v7[0] = 0.0;
		v7[2] = v5;
		nox_xxx_castSpellByUser_4FDD20(v1, nox_xxx_imagCasterUnit_1569664, &v7);
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

//----- (005154E0) --------------------------------------------------------
int nox_script_builtin_5154E0() {
	short v0; // bx
	int v1;   // edi
	int v2;   // eax
	int v3;   // esi

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_script_pop();
	if (v2) {
		v3 = nox_server_scriptValToObjectPtr_511B60(v2);
		if (v3) {
			nox_xxx_comJournalEntryAdd_427500(v3, nox_script_getString_512E40(v1), v0);
			if (v0 & 0xB) {
				nox_xxx_aud_501960(903, v3, 0, 0);
				return 0;
			}
		}
	} else {
		nox_xxx_comAddEntryAll_427550(nox_script_getString_512E40(v1), v0);
	}
	return 0;
}

//----- (00515550) --------------------------------------------------------
int nox_script_DeleteJournalEntry_515550() {
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
int nox_script_builtin_5155A0() {
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
int nox_script_SetGuardPoint_515600() {
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
int nox_script_builtin_515700() {
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

//----- (00515780) --------------------------------------------------------
int nox_script_MonsterHunt_515780() {
	int v0; // eax
	int v1; // eax

	v0 = nox_script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1) {
		nox_xxx_unitHunt_5157A0(v1);
	}
	return 0;
}

//----- (005157D0) --------------------------------------------------------
int nox_script_builtin_5157D0() {
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
int nox_script_builtin_515910() {
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
int nox_script_AgresssionLevel_515950() {
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
int nox_script_builtin_5159B0() {
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
int nox_script_builtin_515AE0() {
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
int nox_script_ShootLocation_515B30() {
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
int nox_script_builtin_515BF0() {
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
int nox_script_MonsterWayFlag_515C40(int a1) {
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
int nox_script_builtin_515CB0() {
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
int nox_script_builtin_515DB0() {
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
int nox_script_SetIdleLevel_515DF0() {
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
int nox_script_GroupSetIdleHP_515E50() {
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
int nox_script_builtin_515EE0() {
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
int nox_script_monsterGroupFleeFrom_516000() {
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
int nox_script_MonsterWait_516060() {
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
int nox_script_builtin_5160F0() {
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
int nox_script_builtin_516120() {
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
int nox_script_builtin_516160() {
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

//----- (005161C0) --------------------------------------------------------
int nox_script_builtin_5161C0() {
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
	if (v2 && v3 && nox_xxx_unitIsEnemyTo_5330C0(v2, v3)) {
		v4 = 1;
	}
	nox_script_push(v4);
	return 0;
}

//----- (00516210) --------------------------------------------------------
int nox_script_getObjectType_516210() {
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
int nox_script_builtin_5162D0() {
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

//----- (00516400) --------------------------------------------------------
int nox_script_ForceAutosave_516400() {
	if (nox_common_gameFlags_check_40A5C0(2048)) {
		sub_4DB130("AUTOSAVE");
		sub_4DB170(1, 0, 0);
	}
	return 0;
}

//----- (00516430) --------------------------------------------------------
int nox_script_Music_516430() {
	int v0;     // ebx
	char v2[3]; // [esp+4h] [ebp-8h]
	int v3;     // [esp+8h] [ebp-4h]

	v0 = nox_script_pop();
	v3 = nox_script_pop();
	if (nox_common_gameFlags_check_40A5C0(2048)) {
		sub_43D9B0(v3, v0);
	} else {
		v2[1] = v3;
		v2[2] = v0;
		v2[0] = -27;
		nox_xxx_netSendPacket1_4E5390(255, (int)v2, 3, 0, 1);
	}
	return 0;
}

//----- (005164A0) --------------------------------------------------------
int nox_script_builtin_5164A0(void* this) {
	void* v2; // [esp+0h] [ebp-4h]

	v2 = this;
	if (nox_common_gameFlags_check_40A5C0(2048)) {
		sub_43DA80();
	} else {
		LOBYTE(v2) = -26;
		nox_xxx_netSendPacket1_4E5390(255, (int)&v2, 3, 0, 1);
	}
	return 0;
}

//----- (005164E0) --------------------------------------------------------
int nox_script_builtin_5164E0(void* this) {
	void* v2; // [esp+0h] [ebp-4h]

	v2 = this;
	if (nox_common_gameFlags_check_40A5C0(2048)) {
		sub_43DAD0();
	} else {
		LOBYTE(v2) = -25;
		nox_xxx_netSendPacket1_4E5390(255, (int)&v2, 3, 0, 1);
	}
	return 0;
}

//----- (00516520) --------------------------------------------------------
int nox_script_ClearMusic_516520(void* this) {
	void* v2; // [esp+0h] [ebp-4h]

	v2 = this;
	if (nox_common_gameFlags_check_40A5C0(2048)) {
		sub_43D9B0(0, 0);
	} else {
		LOWORD(v2) = 229;
		nox_xxx_netSendPacket1_4E5390(255, (int)&v2, 3, 0, 1);
	}
	return 0;
}

//----- (00516600) --------------------------------------------------------
int nox_script_builtin_516600() {
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

//----- (00516680) --------------------------------------------------------
int nox_script_builtin_516680() {
	*getMemU32Ptr(0x5D4594, 2386832) = 0;
	sub_5165D0();
	return 0;
}

//----- (005166A0) --------------------------------------------------------
int nox_script_builtin_5166A0() {
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
int nox_script_builtin_516720() {
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
int nox_script_builtin_516760() {
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

//----- (00516920) --------------------------------------------------------
int nox_script_Frozen_516920() {
	int v0; // esi
	int v1; // eax
	int v2; // eax

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	if (v2) {
		if (v0 == 1) {
			nox_xxx_unitFreeze_4E79C0(v2, 1);
			return 0;
		}
		nox_xxx_unitUnFreeze_4E7A60(v2, 1);
	}
	return 0;
}

//----- (00516960) --------------------------------------------------------
int nox_script_builtin_516960() {
	nox_xxx_wallSounds_2386840 = nox_script_pop();
	return 0;
}

//----- (00516970) --------------------------------------------------------
int nox_script_SetProperty_516970() {
	int v0;       // esi
	int v1;       // edi
	int v2;       // eax
	int v3;       // eax
	uint32_t* v4; // eax
	int result;   // eax

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_script_pop();
	v3 = nox_server_scriptValToObjectPtr_511B60(v2);
	if (!v3 || !(*(uint8_t*)(v3 + 8) & 2)) {
		return 0;
	}
	v4 = *(uint32_t**)(v3 + 748);
	switch (v1) {
	case 3: // Enemy sighted
		v4[309] = v0;
		result = 0;
		break;
	case 4: // Looking for enemy
		v4[307] = v0;
		result = 0;
		break;
	case 5: // Death
		v4[317] = v0;
		result = 0;
		break;
	case 6: // Change focus
		v4[311] = v0;
		result = 0;
		break;
	case 7: // Is hit
		v4[313] = v0;
		result = 0;
		break;
	case 8: // Retreat
		v4[315] = v0;
		result = 0;
		break;
	case 9: // Collision
		v4[319] = v0;
		result = 0;
		break;
	case 10: // Enemy heard
		v4[321] = v0;
		result = 0;
		break;
	case 11: // End of waypoint
		v4[323] = v0;
		result = 0;
		break;
	case 13: // Lost sight of enemy
		v4[325] = v0;
		return 0;
	default:
		return 0;
	}
	return result;
}

//----- (00516A50) --------------------------------------------------------
int nox_script_DecayObject_516A50() {
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

//----- (00516BC0) --------------------------------------------------------
int nox_script_builtin_516BC0() {
	int v0; // eax
	int v1; // eax

	v0 = nox_script_pop();
	v1 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v1) {
		nox_xxx_netScriptMessageKill_4D9760(v1);
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
int nox_script_TestMobStatus_516C30() {
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
int nox_script_builtin_516C70() {
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
int nox_script_builtin_516CB0() {
	int v0;            // eax
	unsigned char* v1; // eax

	v0 = nox_script_pop();
	v1 = (unsigned char*)nox_server_scriptGetGroup_57C0A0(v0);
	nox_server_scriptExecuteFnForEachGroupObj_502670(v1, 0, nox_xxx_zombieSetStayDead_516C90, 0);
	return 0;
}

//----- (00516CE0) --------------------------------------------------------
int nox_script_builtin_516CE0() {
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
int nox_script_builtin_516D40() {
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

//----- (00516E30) --------------------------------------------------------
int nox_script_PlayerScore_516E30() {
	int v0;   // edi
	int v1;   // eax
	int v2;   // eax
	int v3;   // esi
	char* v4; // eax

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	v3 = v2;
	if (v2 && *(uint8_t*)(v2 + 8) & 4) {
		if (v0 <= 0) {
			nox_xxx_playerSubLessons_4D8EC0(v2, -v0);
		} else {
			nox_xxx_changeScore_4D8E90(v2, v0);
		}
		v4 = nox_xxx_clientGetTeamColor_418AB0(*(unsigned char*)(v3 + 52));
		if (v4) {
			nox_xxx_netChangeTeamID_419090((int)v4, v0 + *((uint32_t*)v4 + 13));
		}
		nox_xxx_netReportLesson_4D8EF0(v3);
	}
	return 0;
}

//----- (00516EA0) --------------------------------------------------------
int nox_script_builtin_516EA0() {
	int v0; // eax
	int v1; // esi
	int v2; // eax

	v0 = nox_script_pop();
	v1 = 0;
	v2 = nox_server_scriptValToObjectPtr_511B60(v0);
	if (v2 && *(uint8_t*)(v2 + 8) & 4) {
		v1 = *(uint32_t*)(*(uint32_t*)(*(uint32_t*)(v2 + 748) + 276) + 2136);
	}
	nox_script_push(v1);
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
int nox_script_builtin_514A80() {
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
int nox_script_builtin_514B10() {
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

//----- (00512B10) --------------------------------------------------------
int nox_script_printToCaller_512B10() {
	int v0;      // eax
	wchar_t* v1; // eax

	v0 = nox_script_pop();
	if (nox_script_get_caller() && *(uint8_t*)((char*)nox_script_get_caller() + 8) & 4) {
		v1 = nox_strman_loadString_40F1D0(nox_script_getString_512E40(v0), 0,
										  "C:\\NoxPost\\src\\Server\\System\\CScrFunc.c", 1285);
		nox_xxx_netSendLineMessage_4D9EB0(nox_script_get_caller(), v1);
	}
	return 0;
}

//----- (00512B60) --------------------------------------------------------
int nox_script_printToAll_512B60() {
	int v0;      // eax
	wchar_t* v1; // eax

	v0 = nox_script_pop();
	v1 = nox_strman_loadString_40F1D0(nox_script_getString_512E40(v0), 0,
									  "C:\\NoxPost\\src\\Server\\System\\CScrFunc.c", 1310);
	nox_xxx_printToAll_4D9FD0(0, v1);
	return 0;
}

//----- (00512B90) --------------------------------------------------------
int nox_script_sayChat_512B90() {
	int v0;      // edi
	int v1;      // eax
	int v2;      // esi
	char* v3;    // ecx
	wchar_t* v4; // eax
	int v6;      // [esp+8h] [ebp-4h]

	v0 = nox_script_pop();
	v1 = nox_script_pop();
	v2 = nox_server_scriptValToObjectPtr_511B60(v1);
	if (v2) {
		v3 = nox_script_getString_512E40(v0);
		v6 = 0;
		v4 = nox_strman_loadString_40F1D0(v3, &v6, "C:\\NoxPost\\src\\Server\\System\\CScrFunc.c", 1342);
		nox_xxx_netSendChat_528AC0(v2, v4, 0);
		if (nox_common_gameFlags_check_40A5C0(2048)) {
			nox_xxx_playDialogFile_44D900(v6, 100);
		}
	}
	return 0;
}

int nox_script_StartGame_516C20();
int nox_script_EndGame_516E10();
int nox_script_UnBlind_515200();
int nox_script_Blind_515220();
int nox_script_WideScreen_515240();
int nox_script_StopAllFades_516C10();
int nox_script_Effect_514210();

//-------------------------------------------------------------------------
void* nox_script_builtin[] = {
	&nox_script_getWall_511EB0,               // 0
	&nox_script_openSecretWall_511F50,        // 1
	&nox_script_openWallGroup_512010,         // 2
	&nox_script_closeWall_512040,             // 3
	&nox_script_closeWallGroup_512100,        // 4
	&nox_script_toggleWall_512130,            // 5
	&nox_script_toggleWallGroup_512260,       // 6
	&nox_script_wallBreak_512290,             // 7
	&nox_script_wallGroupBreak_5122F0,        // 8
	&nox_script_secondTimer_512320,           // 9
	&nox_script_frameTimer_512350,            // 10
	&nox_script_moverOrMonsterGo_512370,      // 11
	&nox_script_groupGoTo_512500,             // 12
	&nox_script_lookAtDirection_512560,       // 13
	&nox_script_groupLookAtDirection_512610,  // 14
	&nox_script_objectOn_512670,              // 15
	&nox_script_objGroupOn_512690,            // 16
	&nox_script_waypointOn_5126D0,            // 17
	&nox_script_waypointGroupOn_5126F0,       // 18
	&nox_script_objectOff_512730,             // 19
	&nox_script_objGroupOff_512750,           // 20
	&nox_script_waypointOff_512790,           // 21
	&nox_script_waypointGroupOff_5127B0,      // 22
	&nox_script_toggleObject_5127F0,          // 23
	&nox_script_toggleObjectGroup_512810,     // 24
	&nox_script_toggleWaypoint_512850,        // 25
	&nox_script_toggleWaypointGroup_512870,   // 26
	&nox_script_deleteObject_5128B0,          // 27
	&nox_script_deleteObjectGroup_5128D0,     // 28
	&nox_script_followNearestWaypoint_512910, // 29
	&nox_script_groupRoam_512990,             // 30
	&nox_script_getObject2_5129C0,            // 31
	&nox_script_getObject3_5129E0,            // 32
	&nox_script_gotoHome_512A00,              // 33
	&nox_script_audioEven_512AC0,             // 34
	&nox_script_printToCaller_512B10,         // 35
	&nox_script_printToAll_512B60,            // 36
	&nox_script_sayChat_512B90,               // 37
	&nox_script_returnOne_512C10,             // 38
	&nox_script_unlockDoor_512C20,            // 39
	&nox_script_lockDoor_512C60,              // 40
	&nox_script_isOn_512CA0,                  // 41
	&nox_script_wpIsEnabled_512CE0,           // 42
	&nox_script_doorIsLocked_512D20,          // 43
	&nox_script_randomFloat_512D70,           // 44
	&nox_script_randomInt_512DB0,             // 45
	&nox_script_timerSecSpecial_512DE0,       // 46
	&nox_script_specialTimer_512E10,          // 47
	&nox_script_intToString_512EA0,           // 48
	&nox_script_floatToString_512ED0,         // 49
	&nox_script_create_512F10,                // 50
	&nox_script_damage_512F80,                // 51
	&nox_script_groupDamage_513010,           // 52
	&nox_script_builtin_513070,               // 53
	&nox_script_builtin_513160,               // 54
	&nox_script_awardSpell_5131C0,            // 55
	&nox_script_awardSpellGroup_513230,       // 56
	&nox_script_enchant_5132E0,               // 57
	&nox_script_groupEnchant_5133B0,          // 58
	&nox_script_getHost_513460,               // 59
	&nox_script_objectGet_513490,             // 60
	&nox_script_getObjectX_513530,            // 61
	&nox_script_getWaypointX_513570,          // 62
	&nox_script_getObjectY_5135B0,            // 63
	&nox_script_getWaypointY_5135F0,          // 64
	&nox_script_unitHeight_513630,            // 65
	&nox_script_getUnitLook_513670,           // 66
	&nox_script_moveObject_5136A0,            // 67
	&nox_script_moveWaypoint_513700,          // 68
	&nox_script_raise_513750,                 // 69
	&nox_script_faceAngle_513780,             // 70
	&nox_script_pushObject_5137D0,            // 71
	&nox_script_pushObjectTo_513820,          // 72
	&nox_script_getFirstInvItem_5138B0,       // 73
	&nox_script_getNextInvItem_5138E0,        // 74
	&nox_script_hasItem_513910,               // 75
	&nox_script_getInvHolder_513960,          // 76
	&nox_script_pickup_5139A0,                // 77
	&nox_script_drop_513C10,                  // 78
	&nox_script_getObjectType_516210,         // 79
	&nox_script_builtin_513C60,               // 80
	&nox_script_TestBuffs_513C70,             // 81
	&nox_script_cancelBuff_513D00,            // 82
	&nox_script_getCurrentHP_513D70,          // 83
	&nox_script_getMaxHP_513DB0,              // 84
	&nox_script_restoreHP_513DF0,             // 85
	&nox_script_getDistance_513E20,           // 86
	&nox_script_canInteract_513E80,           // 87
	&nox_script_fn58_513F10,                  // 88
	&nox_script_fn59_513F20,                  // 89
	&nox_script_fn5A_513F30,                  // 90
	&nox_script_fn5B_513F40,                  // 91
	&nox_script_Fn5C_513F50,                  // 92
	&nox_script_Fn5D_513F60,                  // 93
	&nox_script_Fn5E_513F70,                  // 94
	&nox_script_GetHostInfo_513FA0,           // 95
	&nox_script_FaceObject_514050,            // 96
	&nox_script_Walk_5140B0,                  // 97
	&nox_script_GroupWalk_514170,             // 98
	&nox_script_CancelTimer_5141F0,           // 99
	&nox_script_Effect_514210,                // 100
	&nox_script_SetOwner_514490,              // 101
	&nox_script_GroupSetOwner_5144C0,         // 102
	&nox_script_SetOwnerGroup_514510,         // 103
	&nox_script_builtin_514570,               // 104
	&nox_script_builtin_5145F0,               // 105
	&nox_script_builtin_514630,               // 106
	&nox_script_builtin_5146B0,               // 107
	&nox_script_builtin_514730,               // 108
	&nox_script_ClearOwner_5147E0,            // 109
	&nox_script_Waypoint_514800,              // 110
	&nox_script_GetWaypointGroup_5148A0,      // 111
	&nox_script_GetObjectGroup_514940,        // 112
	&nox_script_GetWallGroup_5149E0,          // 113
	&nox_script_builtin_514A80,               // 114
	&nox_script_builtin_514B10,               // 115
	&nox_script_Pop2_74_514BA0,               // 116
	&nox_script_RemoveChat_514BB0,            // 117
	&nox_script_NoChatAll_514BD0,             // 118
	&nox_script_JournalQuest_514BE0,          // 119
	&nox_script_JournalQuestBool_514C10,      // 120
	&nox_script_JournalGetQuest_514C40,       // 121
	&nox_script_JournalGetQuestBool_514C60,   // 122
	&nox_script_RestoreQuestStatus_514C90,    // 123
	&nox_script_ObjIsTrigger_514CB0,          // 124
	&nox_script_builtin_514CF0,               // 125
	&nox_script_SetDialog_514D90,             // 126
	&nox_script_CancelDialog_514DF0,          // 127
	&nox_script_DialogPortrait_514E30,        // 128
	&nox_script_TellStory_514E90,             // 129
	&nox_script_ForceDialog_514ED0,           // 130
	&nox_script_builtin_514F10,               // 131
	&nox_script_builtin_514FC0,               // 132
	&nox_script_builtin_515060,               // 133
	&nox_script_cast_515130,                  // 134
	&nox_script_UnBlind_515200,               // 135
	&nox_script_Blind_515220,                 // 136
	&nox_script_WideScreen_515240,            // 137
	&nox_script_GetElevatorStat_5154A0,       // 138
	&nox_script_SetGuardPoint_515600,         // 139
	&nox_script_builtin_515700,               // 140
	&nox_script_MonsterHunt_515780,           // 141
	&nox_script_builtin_5157D0,               // 142
	&nox_script_Idle_515800,                  // 143
	&nox_script_GroupIdle_515850,             // 144
	&nox_script_Follow_515880,                // 145
	&nox_script_builtin_515910,               // 146
	&nox_script_AgresssionLevel_515950,       // 147
	&nox_script_builtin_5159B0,               // 148
	&nox_script_HitLocation_5159E0,           // 149
	&nox_script_builtin_515AE0,               // 150
	&nox_script_ShootLocation_515B30,         // 151
	&nox_script_builtin_515BF0,               // 152
	&nox_script_MonsterWayFlag_515C40,        // 153
	&nox_script_builtin_515CB0,               // 154
	&nox_script_Attack_515CF0,                // 155
	&nox_script_builtin_515DB0,               // 156
	&nox_script_builtin_5154E0,               // 157
	&nox_script_DeleteJournalEntry_515550,    // 158
	&nox_script_builtin_5155A0,               // 159
	&nox_script_SetIdleLevel_515DF0,          // 160
	&nox_script_GroupSetIdleHP_515E50,        // 161
	&nox_script_SetResumeLevel_515E80,        // 162
	&nox_script_builtin_515EE0,               // 163
	&nox_script_RunAway_515F10,               // 164
	&nox_script_monsterGroupFleeFrom_516000,  // 165
	&nox_script_MonsterWait_516060,           // 166
	&nox_script_builtin_5160F0,               // 167
	&nox_script_builtin_5161C0,               // 168
	&nox_script_builtin_516120,               // 169
	&nox_script_builtin_516160,               // 170
	&nox_script_DialogResult_5163C0,          // 171
	&nox_script_GiveExp_516190,               // 172
	&nox_script_builtin_5162D0,               // 173
	&nox_script_ForceAutosave_516400,         // 174
	&nox_script_Music_516430,                 // 175
	&nox_script_builtin_516600,               // 176
	&nox_script_builtin_5166A0,               // 177
	&nox_script_GetTrigger_514D30,            // 178
	&nox_script_GetCaller_514D60,             // 179
	&nox_script_builtin_516720,               // 180
	&nox_script_builtin_516760,               // 181
	&nox_script_BecomePet_5167D0,             // 182
	&nox_script_BecomeEnemy_516810,           // 183
	&nox_script_builtin_516790,               // 184
	&nox_script_builtin_516850,               // 185
	&nox_script_OblivionGive_516890,          // 186
	&nox_script_builtin_516680,               // 187
	&nox_script_Frozen_516920,                // 188
	&nox_script_builtin_516960,               // 189
	&nox_script_SetProperty_516970,           // 190
	&nox_script_DecayObject_516A50,           // 191
	&nox_script_TrapSpells_516B40,            // 192
	&nox_script_PlayerIsTrading_5166E0,       // 193
	&nox_script_builtin_516BC0,               // 194
	&nox_script_SetShopkeeperGreet_516BE0,    // 195
	&nox_script_StopAllFades_516C10,          // 196
	&nox_script_TestMobStatus_516C30,         // 197
	&nox_script_builtin_516C70,               // 198
	&nox_script_builtin_516CB0,               // 199
	&nox_script_builtin_516CE0,               // 200
	&nox_script_builtin_516D40,               // 201
	&nox_script_builtin_5164A0,               // 202
	&nox_script_builtin_5164E0,               // 203
	&nox_script_ClearMusic_516520,            // 204
	&nox_script_ObjIsGameball_516D70,         // 205
	&nox_script_ObjIsCrown_516DC0,            // 206
	&nox_script_EndGame_516E10,               // 207
	&nox_script_StartGame_516C20,             // 208
	&nox_script_PlayerScore_516E30,           // 209
	&nox_script_builtin_516EA0,               // 210
};
int nox_script_builtin_cnt = sizeof(nox_script_builtin) / sizeof(void*);

//----- (00508C30) --------------------------------------------------------
// TODO: 5 items in the array, but the count is set to 7; why?
void* nox_script_builtin_xxx[] = {
	&nox_script_objectGet_513490,
	&nox_script_Waypoint_514800,
	&nox_script_GetObjectGroup_514940,
	&nox_script_GetWaypointGroup_5148A0,
	&nox_script_GetWallGroup_5149E0,
	0, // TODO: safeguard for the comment above
	0,
};
int nox_script_xxxCount_246800 = 7;
int nox_script_builtinNeedsField36_508C30(int fi) {
	for (int i = 0; i < nox_script_xxxCount_246800; i++) {
		if (nox_script_builtin[fi] == nox_script_builtin_xxx[i]) {
			return 1;
		}
	}
	return 0;
}

//----- (00508C70) --------------------------------------------------------
// TODO: 7 items in the array, but the count is set to 5; why?
void* nox_script_builtin_yyy[] = {
	&nox_script_getWall_511EB0,      &nox_script_moveObject_5136A0, &nox_script_moveWaypoint_513700,
	&nox_script_pushObjectTo_513820, &nox_script_Walk_5140B0,       &nox_script_GroupWalk_514170,
	&nox_script_Effect_514210,
};
int nox_script_yyyCount_246768 = 5;
int nox_script_builtinNeedsFields4044_508C30(int fi) {
	for (int i = 0; i < nox_script_yyyCount_246768; i++) {
		if (nox_script_builtin[fi] == nox_script_builtin_yyy[i]) {
			return 1;
		}
	}
	return 0;
}

int nox_script_callBuiltin(int fi) {
	int res = 0;
	if (nox_script_panic_compiler_call(fi, &res)) {
		return res;
	}
	return (*(int (**)()) & nox_script_builtin[fi])();
}

//----- (00508B70) --------------------------------------------------------
int nox_script_callBuiltin_508B70(int i, int fi) {
	if (fi < 0 || fi >= nox_script_builtin_cnt) {
		if (!nox_script_panic_compiler_check(fi)) {
			printf("noxscript: invalid builtin index: %d (%x)\n", fi, fi);
			return 0;
		}
		return 0;
	}
	if (!nox_script_getField36(i)) {
		return nox_script_callBuiltin(fi);
	}
	if (nox_script_builtinNeedsField36_508C30(fi)) {
		strcpy(nox_script_builtin_buf_xxx, nox_script_getField36(i));
	}
	if (nox_script_builtinNeedsFields4044_508C30(fi)) {
		dword_5d4594_3821636 = nox_script_getField40(i);
		dword_5d4594_3821640 = nox_script_getField44(i);
	}
	int res = nox_script_callBuiltin(fi);
	nox_script_resetBuiltin();
	return res;
}

bool nox_script_shouldReadMoreXxx(int fi) {
	void* f = nox_script_builtin[fi];
	return f == nox_script_secondTimer_512320 || f == nox_script_frameTimer_512350 ||
		   f == nox_script_timerSecSpecial_512DE0 || f == nox_script_specialTimer_512E10 ||
		   f == nox_script_SetProperty_516970 || f == nox_script_SetDialog_514D90;
}

bool nox_script_shouldReadEvenMoreXxx(int fi) {
	void* f = nox_script_builtin[fi];
	return f == nox_script_SetDialog_514D90;
}
