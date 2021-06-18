#include "common__magic__speltree.h"

#include "proto.h"
extern void* dword_587000_66120;

//----- (00424460) --------------------------------------------------------
int  nox_xxx_spellLoadSpells_424460(nox_memfile* f, void* a2) {
	int v3;               // ebx
	int v4;               // eax
	int result;           // eax
	unsigned __int8 v9;   // dl
	int* v10;             // edi
	unsigned __int8 v12;  // cl
	int** v13;            // edi
	int* v14;             // eax
	int v16;              // edi
	char v18;             // cl
	int v20;              // edi
	char v22;             // cl
	int v24;              // ecx
	int v27;              // edi
	unsigned __int8 v29;  // cl
	int v30;              // edi
	unsigned __int8 v33;  // [esp+10h] [ebp-138h]
	unsigned __int8 v34;  // [esp+10h] [ebp-138h]
	unsigned __int8 v35;  // [esp+10h] [ebp-138h]
	unsigned __int8 v36;  // [esp+10h] [ebp-138h]
	unsigned __int8 v37;  // [esp+10h] [ebp-138h]
	unsigned __int8 v38;  // [esp+10h] [ebp-138h]
	const char* v39;      // [esp+14h] [ebp-134h]
	unsigned __int8 v40;  // [esp+1Ch] [ebp-12Ch]
	int v41;              // [esp+20h] [ebp-128h]
	int v42;              // [esp+24h] [ebp-124h]
	char v43[256];        // [esp+28h] [ebp-120h]
	char v44[32];         // [esp+128h] [ebp-20h]

	v33 = nox_memfile_read_u8(f);
	nox_memfile_read(a2, 1, v33, f);
	v3 = 0;
	*((_BYTE*)a2 + v33) = 0;
	v4 = nox_xxx_spellNameToN_4243F0((const char*)a2);
	v41 = v4;
	if (!v4)
		return 0;
	nox_spell_t* sp = (nox_spell_t*)getMemAt(0x5D4594, 588124 + sizeof(nox_spell_t) * v4);
	v40 = 0;
	v39 = 0;
	sp->mana_cost = nox_memfile_read_u8(f);
	sp->price = nox_memfile_read_u16(f);
	v9 = nox_memfile_read_u8(f);
	sp->phonemes_cnt = v9;
	v10 = *(int**)&dword_587000_66120;
	v42 = v9;
	if ((int)v9 > 0) {
		do {
			v12 = nox_memfile_read_u8(f);
			if (v12 >= 9)
				return 0;
			v44[v40++] = v12;
			v13 = (int**)&v10[v12 + 1];
			if (*v13) {
				v10 = *v13;
			} else {
				v14 = (int*)calloc(1u, 0x28u);
				*v13 = v14;
				if (!v14)
					return 0;
				*v14 = 0;
				v10 = *v13;
				v4 = v41;
			}
		} while ((int)++v39 < v42);
	}
	*v10 = v4;
	v16 = nox_memfile_read_i32(f);
	sp->icon = 0;
	v43[0] = getMemByte(0x5D4594, 599124);
	if (v16 == -1) {
		v18 = nox_memfile_read_i8(f);
		LOBYTE(v39) = v18;
		v34 = nox_memfile_read_i8(f);
		nox_memfile_read(v43, 1, v34, f);
		v43[v34] = 0;
		v16 = -1;
	}
	if (nox_common_gameFlags_check_40A5C0(2))
		sp->icon = nox_xxx_readImgMB_42FAA0(v16, v39, v43);
	v20 = nox_memfile_read_i32(f);
	sp->icon_spent = 0;
	v43[0] = getMemByte(0x5D4594, 599128);
	if (v20 == -1) {
		v22 = nox_memfile_read_i8(f);
		LOBYTE(v39) = v22;
		v35 = nox_memfile_read_i8(f);
		nox_memfile_read(v43, 1, v35, f);
		v43[v35] = 0;
		v20 = -1;
	}
	if (nox_common_gameFlags_check_40A5C0(2))
		sp->icon_spent = nox_xxx_readImgMB_42FAA0(v20, v39, v43);
	v24 = nox_memfile_read_i32(f);
	sp->flags = v24;
	v36 = nox_memfile_read_u8(f);
	nox_memfile_read(v43, 1, v36, f);
	v43[v36] = 0;
	sp->title = nox_strman_loadString_40F1D0(v43, 0, "C:\\NoxPost\\src\\Common\\Magic\\Speltree.c", 481);
	v27 = nox_memfile_read_i16(f);
	nox_memfile_read(v43, 1, v27, f);
	v43[v27] = 0;
	sp->desc = nox_strman_loadString_40F1D0(v43, 0, "C:\\NoxPost\\src\\Common\\Magic\\Speltree.c", 488);
	v29 = nox_memfile_read_u8(f);
	v30 = v29;
	nox_memfile_read(v43, 1, v29, f);
	v43[v30] = 0;
	sp->cast_sound = nox_xxx_utilFindSound_40AF50(v43);
	v37 = nox_memfile_read_u8(f);
	nox_memfile_read(v43, 1, v37, f);
	v43[v37] = 0;
	sp->on_sound = nox_xxx_utilFindSound_40AF50(v43);
	v38 = nox_memfile_read_u8(f);
	nox_memfile_read(v43, 1, v38, f);
	v43[v38] = 0;
	sp->off_sound = nox_xxx_utilFindSound_40AF50(v43);
	if ((int)v40 > 0) {
		memcpy(sp->data_7, v44, v40);
		v3 = v40;
	}
	result = 1;
	sp->data_7[v3] = 4;
	sp->enabled = 1;
	sp->valid = 1;
	return result;
}
