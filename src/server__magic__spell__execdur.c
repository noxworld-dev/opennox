#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME3_2.h"
#include "GAME4.h"
#include "GAME4_3.h"
#include "common__strman.h"

extern unsigned int nox_frame_xxx_2598000;
//----- (00530A30) --------------------------------------------------------
int  sub_530A30_spell_execdur(int a1) {
	int v1;      // esi
	int v2;      // ebx
	int v3;      // eax
	wchar_t* v4; // eax
	int result;  // eax
	int v6;      // eax
	float v7;    // ecx
	float v8;    // edx
	int v9;      // eax
	int v10;     // ecx
	float v11;   // [esp+0h] [ebp-20h]
	float4 v12;  // [esp+10h] [ebp-10h]

	v1 = a1;
	v2 = 0;
	if (!*(uint32_t*)(a1 + 48)) {
		*(uint32_t*)(a1 + 48) = *(uint32_t*)(a1 + 16);
}
	v3 = *(uint32_t*)(v1 + 16);
	if (*(uint8_t*)(v3 + 8) & 4) {
		v2 = *(uint32_t*)(v3 + 748);
}
	if (nox_xxx_mapTileAllowTeleport_411A90((float2*)(v1 + 52))) {
		v4 = nox_strman_loadString_40F1D0("UnseenTarget", 0, "C:\\NoxPost\\src\\Server\\Magic\\Spell\\ExecDur.c",
								   2912);
		nox_xxx_netSendLineMessage_4D9EB0(*(uint32_t*)(v1 + 48), v4);
		nox_xxx_aud_501960(231, *(uint32_t*)(v1 + 48), 0, 0);
		result = 1;
	} else {
		v6 = *(uint32_t*)(v1 + 48);
		v12.field_0 = *(float*)(v6 + 56);
		v7 = *(float*)(v1 + 56);
		v8 = *(float*)(v6 + 60);
		v12.field_8 = *(float*)(v1 + 52);
		v9 = *(uint32_t*)(v1 + 16);
		v12.field_4 = v8;
		v12.field_C = v7;
		if (!v9 || (unsigned char)nox_xxx_traceRay_5374B0((float4*)&v12)) {
			if (nox_common_gameFlags_check_40A5C0(2048)) {
				v11 = nox_xxx_gamedataGetFloatTable_419D70("TeleportDelay", *(uint32_t*)(v1 + 8) - 1);
				*(uint32_t*)(v1 + 68) = nox_frame_xxx_2598000 + nox_float2int(v11);
				result = 0;
			} else {
				result = 0;
				*(uint32_t*)(v1 + 68) = nox_frame_xxx_2598000 + 1;
			}
		} else {
			if (v2) {
				v10 = *(uint32_t*)(v2 + 276);
				a1 = 2;
				nox_xxx_netInformTextMsg_4DA0F0(*(unsigned char*)(v10 + 2064), 0, &a1);
			}
			result = 1;
		}
	}
	return result;
}
