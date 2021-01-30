#include "proto.h"

//----- (00530A30) --------------------------------------------------------
int __cdecl sub_530A30_spell_execdur(int a1) {
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
	if (!*(_DWORD*)(a1 + 48))
		*(_DWORD*)(a1 + 48) = *(_DWORD*)(a1 + 16);
	v3 = *(_DWORD*)(v1 + 16);
	if (*(_BYTE*)(v3 + 8) & 4)
		v2 = *(_DWORD*)(v3 + 748);
	if (nox_xxx_mapTileAllowTeleport_411A90((float2*)(v1 + 52))) {
		v4 = nox_strman_loadString_40F1D0((char*)getMemAt(0x587000, 260960), 0, "C:\\NoxPost\\src\\Server\\Magic\\Spell\\ExecDur.c",
								   2912);
		nox_xxx_netSendLineMessage_4D9EB0(*(_DWORD*)(v1 + 48), v4);
		nox_xxx_aud_501960(231, *(_DWORD*)(v1 + 48), 0, 0);
		result = 1;
	} else {
		v6 = *(_DWORD*)(v1 + 48);
		v12.field_0 = *(float*)(v6 + 56);
		v7 = *(float*)(v1 + 56);
		v8 = *(float*)(v6 + 60);
		v12.field_8 = *(float*)(v1 + 52);
		v9 = *(_DWORD*)(v1 + 16);
		v12.field_4 = v8;
		v12.field_C = v7;
		if (!v9 || (unsigned __int8)nox_xxx_traceRay_5374B0((float4*)&v12)) {
			if (nox_common_gameFlags_check_40A5C0(2048)) {
				v11 = nox_xxx_loadFloatVar_419D70(getMemAt(0x587000, 260976), *(_DWORD*)(v1 + 8) - 1);
				*(_DWORD*)(v1 + 68) = *getMemU32Ptr(0x5D4594, 2598000) + nox_float2int(v11);
				result = 0;
			} else {
				result = 0;
				*(_DWORD*)(v1 + 68) = *getMemU32Ptr(0x5D4594, 2598000) + 1;
			}
		} else {
			if (v2) {
				v10 = *(_DWORD*)(v2 + 276);
				a1 = 2;
				nox_xxx_netInformTextMsg_4DA0F0(*(unsigned __int8*)(v10 + 2064), 0, &a1);
			}
			result = 1;
		}
	}
	return result;
}