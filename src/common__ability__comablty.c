#include "common__ability__comablty.h"

#include "common__strman.h"
#include "GAME1.h"
#include "GAME1_2.h"
#include "GAME1_1.h"
#include "operators.h"

//----- (00424F00) --------------------------------------------------------
int  nox_thing_read_ABIL_rec_424F00(nox_memfile* f, void* a2) {
	int v3;               // eax
	unsigned char* v5;  // edi
	int v7;               // ebp
	char v9;              // cl
	int v11;              // ebp
	char v13;             // cl
	int v15;              // ebp
	char v17;             // cl
	int v20;              // ebp
	unsigned char v22;  // cl
	int v23;              // ebp
	unsigned char v26;  // cl
	int v27;              // ebp
	unsigned char v28;  // [esp+10h] [ebp-10Ch]
	unsigned char v29;  // [esp+10h] [ebp-10Ch]
	unsigned char v30;  // [esp+10h] [ebp-10Ch]
	unsigned char v31;  // [esp+10h] [ebp-10Ch]
	unsigned char v32;  // [esp+10h] [ebp-10Ch]
	unsigned char v33;  // [esp+10h] [ebp-10Ch]
	const char* v34;      // [esp+18h] [ebp-104h]
	char v35[256];        // [esp+1Ch] [ebp-100h]

	v28 = nox_memfile_read_u8(f);
	nox_memfile_read(a2, 1, v28, f);
	*((uint8_t*)a2 + v28) = 0;
	v3 = nox_xxx_abilityNameToN_424D80((const char*)a2);
	if (!v3) {
		return 0;
}
	v5 = getMemAt(0x5D4594, 599132 + 52 * v3);
	*((uint32_t*)v5 + 9) = nox_memfile_read_i8(f);
	v7 = nox_memfile_read_i32(f);
	*((uint32_t*)v5 + 2) = 0;
	v35[0] = getMemByte(0x5D4594, 599444);
	if (v7 == -1) {
		v9 = nox_memfile_read_i8(f);
		LOBYTE(v34) = v9;
		v29 = nox_memfile_read_i8(f);
		nox_memfile_read(v35, 1, v29, f);
		v35[v29] = 0;
		v7 = -1;
	}
	if (nox_common_gameFlags_check_40A5C0(2)) {
		*((uint32_t*)v5 + 2) = nox_xxx_readImgMB_42FAA0(v7, v34, v35);
}
	v11 = nox_memfile_read_i32(f);
	*((uint32_t*)v5 + 3) = 0;
	v35[0] = getMemByte(0x5D4594, 599448);
	if (v11 == -1) {
		v13 = nox_memfile_read_i8(f);
		LOBYTE(v34) = v13;
		v30 = nox_memfile_read_i8(f);
		nox_memfile_read(v35, 1, v30, f);
		v35[v30] = 0;
		v11 = -1;
	}
	if (nox_common_gameFlags_check_40A5C0(2)) {
		*((uint32_t*)v5 + 3) = nox_xxx_readImgMB_42FAA0(v11, v34, v35);
}
	v15 = nox_memfile_read_i32(f);
	*((uint32_t*)v5 + 4) = 0;
	v35[0] = getMemByte(0x5D4594, 599452);
	if (v15 == -1) {
		v17 = nox_memfile_read_i8(f);
		LOBYTE(v34) = v17;
		v31 = nox_memfile_read_i8(f);
		nox_memfile_read(v35, 1, v31, f);
		v35[v31] = 0;
		v15 = -1;
	}
	if (nox_common_gameFlags_check_40A5C0(2)) {
		*((uint32_t*)v5 + 4) = nox_xxx_readImgMB_42FAA0(v15, v34, v35);
}
	v32 = nox_memfile_read_u8(f);
	nox_memfile_read(v35, 1, v32, f);
	v35[v32] = 0;
	*(uint32_t*)v5 = nox_strman_loadString_40F1D0(v35, 0, "C:\\NoxPost\\src\\common\\Ability\\ComAblty.c", 185);
	v20 = nox_memfile_read_i16(f);
	nox_memfile_read(v35, 1, v20, f);
	v35[v20] = 0;
	*((uint32_t*)v5 + 1) = nox_strman_loadString_40F1D0(v35, 0, "C:\\NoxPost\\src\\common\\Ability\\ComAblty.c", 193);
	v22 = nox_memfile_read_u8(f);
	v23 = v22;
	nox_memfile_read(v35, 1, v22, f);
	v35[v23] = 0;
	*((uint32_t*)v5 + 10) = nox_xxx_utilFindSound_40AF50(v35);
	v33 = nox_memfile_read_u8(f);
	nox_memfile_read(v35, 1, v33, f);
	v35[v33] = 0;
	*((uint32_t*)v5 + 11) = nox_xxx_utilFindSound_40AF50(v35);
	v26 = nox_memfile_read_u8(f);
	v27 = v26;
	nox_memfile_read(v35, 1, v26, f);
	v35[v27] = 0;
	*((uint32_t*)v5 + 12) = nox_xxx_utilFindSound_40AF50(v35);
	*((uint32_t*)v5 + 5) = 1;
	*((uint32_t*)v5 + 6) = 1;
	return 1;
}
