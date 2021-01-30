#include "common__ability__comablty.h"

#include "proto.h"

//----- (00424F00) --------------------------------------------------------
int __cdecl nox_xxx_abil_424F00(int a1, void* a2) {
	unsigned __int8* v2;  // eax
	int v3;               // eax
	unsigned __int8* v5;  // edi
	int* v6;              // ecx
	int v7;               // ebp
	char* v8;             // eax
	char v9;              // cl
	int* v10;             // eax
	int v11;              // ebp
	char* v12;            // eax
	char v13;             // cl
	int* v14;             // eax
	int v15;              // ebp
	char* v16;            // eax
	char v17;             // cl
	unsigned __int8* v18; // eax
	__int16* v19;         // eax
	int v20;              // ebp
	unsigned __int8* v21; // eax
	unsigned __int8 v22;  // cl
	int v23;              // ebp
	unsigned __int8* v24; // eax
	unsigned __int8* v25; // eax
	unsigned __int8 v26;  // cl
	int v27;              // ebp
	unsigned __int8 v28;  // [esp+10h] [ebp-10Ch]
	unsigned __int8 v29;  // [esp+10h] [ebp-10Ch]
	unsigned __int8 v30;  // [esp+10h] [ebp-10Ch]
	unsigned __int8 v31;  // [esp+10h] [ebp-10Ch]
	unsigned __int8 v32;  // [esp+10h] [ebp-10Ch]
	unsigned __int8 v33;  // [esp+10h] [ebp-10Ch]
	const char* v34;      // [esp+18h] [ebp-104h]
	char v35[256];        // [esp+1Ch] [ebp-100h]

	v2 = *(unsigned __int8**)(a1 + 8);
	v28 = *v2;
	*(_DWORD*)(a1 + 8) = v2 + 1;
	nox_memfile_read(a2, 1u, v28, a1);
	*((_BYTE*)a2 + v28) = 0;
	v3 = nox_xxx_abilityNameToN_424D80((const char*)a2);
	if (!v3)
		return 0;
	v5 = getMemAt(0x5D4594, 52 * v3 + 599132);
	*((_DWORD*)v5 + 9) = **(char**)(a1 + 8);
	v6 = (int*)(*(_DWORD*)(a1 + 8) + 1);
	*(_DWORD*)(a1 + 8) = v6;
	v7 = *v6;
	*(_DWORD*)(a1 + 8) = v6 + 1;
	*((_DWORD*)v5 + 2) = 0;
	v35[0] = getMemByte(0x5D4594, 599444);
	if (v7 == -1) {
		v8 = *(char**)(a1 + 8);
		v9 = *v8++;
		*(_DWORD*)(a1 + 8) = v8;
		LOBYTE(v34) = v9;
		v29 = *v8;
		*(_DWORD*)(a1 + 8) = v8 + 1;
		nox_memfile_read(v35, 1u, v29, a1);
		v35[v29] = 0;
		v7 = -1;
	}
	if (nox_common_gameFlags_check_40A5C0(2))
		*((_DWORD*)v5 + 2) = nox_xxx_readImgMB_42FAA0(v7, v34, v35);
	v10 = *(int**)(a1 + 8);
	v11 = *v10;
	*(_DWORD*)(a1 + 8) = v10 + 1;
	*((_DWORD*)v5 + 3) = 0;
	v35[0] = getMemByte(0x5D4594, 599448);
	if (v11 == -1) {
		v12 = *(char**)(a1 + 8);
		v13 = *v12++;
		*(_DWORD*)(a1 + 8) = v12;
		LOBYTE(v34) = v13;
		v30 = *v12;
		*(_DWORD*)(a1 + 8) = v12 + 1;
		nox_memfile_read(v35, 1u, v30, a1);
		v35[v30] = 0;
		v11 = -1;
	}
	if (nox_common_gameFlags_check_40A5C0(2))
		*((_DWORD*)v5 + 3) = nox_xxx_readImgMB_42FAA0(v11, v34, v35);
	v14 = *(int**)(a1 + 8);
	v15 = *v14;
	*(_DWORD*)(a1 + 8) = v14 + 1;
	*((_DWORD*)v5 + 4) = 0;
	v35[0] = getMemByte(0x5D4594, 599452);
	if (v15 == -1) {
		v16 = *(char**)(a1 + 8);
		v17 = *v16++;
		*(_DWORD*)(a1 + 8) = v16;
		LOBYTE(v34) = v17;
		v31 = *v16;
		*(_DWORD*)(a1 + 8) = v16 + 1;
		nox_memfile_read(v35, 1u, v31, a1);
		v35[v31] = 0;
		v15 = -1;
	}
	if (nox_common_gameFlags_check_40A5C0(2))
		*((_DWORD*)v5 + 4) = nox_xxx_readImgMB_42FAA0(v15, v34, v35);
	v18 = *(unsigned __int8**)(a1 + 8);
	v32 = *v18;
	*(_DWORD*)(a1 + 8) = v18 + 1;
	nox_memfile_read(v35, 1u, v32, a1);
	v35[v32] = 0;
	*(_DWORD*)v5 = nox_strman_loadString_40F1D0(v35, 0, "C:\\NoxPost\\src\\common\\Ability\\ComAblty.c", 185);
	v19 = *(__int16**)(a1 + 8);
	v20 = *v19;
	*(_DWORD*)(a1 + 8) = v19 + 1;
	nox_memfile_read(v35, 1u, v20, a1);
	v35[v20] = 0;
	*((_DWORD*)v5 + 1) = nox_strman_loadString_40F1D0(v35, 0, "C:\\NoxPost\\src\\common\\Ability\\ComAblty.c", 193);
	v21 = *(unsigned __int8**)(a1 + 8);
	v22 = *v21;
	*(_DWORD*)(a1 + 8) = v21 + 1;
	v23 = v22;
	nox_memfile_read(v35, 1u, v22, a1);
	v35[v23] = 0;
	*((_DWORD*)v5 + 10) = nox_xxx_utilFindSound_40AF50(v35);
	v24 = *(unsigned __int8**)(a1 + 8);
	v33 = *v24;
	*(_DWORD*)(a1 + 8) = v24 + 1;
	nox_memfile_read(v35, 1u, v33, a1);
	v35[v33] = 0;
	*((_DWORD*)v5 + 11) = nox_xxx_utilFindSound_40AF50(v35);
	v25 = *(unsigned __int8**)(a1 + 8);
	v26 = *v25;
	*(_DWORD*)(a1 + 8) = v25 + 1;
	v27 = v26;
	nox_memfile_read(v35, 1u, v26, a1);
	v35[v27] = 0;
	*((_DWORD*)v5 + 12) = nox_xxx_utilFindSound_40AF50(v35);
	*((_DWORD*)v5 + 5) = 1;
	*((_DWORD*)v5 + 6) = 1;
	return 1;
}
