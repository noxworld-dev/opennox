#include "parse.h"
#include "../../../proto.h"

//----- (0044C000) --------------------------------------------------------
void* __cdecl sub_44C000(char* attr_value, nox_memfile* f) {
	_DWORD* v2;          // eax
	_DWORD* v4;          // ebp
	void* result;        // eax
	int v7;              // edi
	_BYTE* v8;           // ebx
	int v10;             // ecx
	char v12;            // cl
	const char* v13;     // [esp+Ch] [ebp-4h]
	unsigned __int8 v14; // [esp+14h] [ebp+4h]
	unsigned __int8 v15; // [esp+18h] [ebp+8h]
	int v16;             // [esp+18h] [ebp+8h]

	v2 = nox_calloc(1u, 0xCu);
	v4 = v2;
	*v2 = 12;
	v15 = nox_memfile_read_u8(f);
	*((_BYTE*)v4 + 8) = v15;
	result = nox_malloc(4 * v15);
	v4[1] = result;
	if (result) {
		v7 = 0;
		v16 = 0;
		if (*((_BYTE*)v4 + 8)) {
			v8 = attr_value;
			do {
				v10 = nox_memfile_read_i32(f);
				*v8 = byte_5D4594[830852];
				if (v10 == -1) {
					v12 = nox_memfile_read_i8(f);
					LOBYTE(v13) = v12;
					v14 = nox_memfile_read_i8(f);
					nox_memfile_read(v8, 1u, v14, f);
					v10 = -1;
					v8[v14] = 0;
					v7 = v16;
				}
				*(_DWORD*)(v4[1] + 4 * v7++) = sub_42FAA0(v10, v13, v8);
				v16 = v7;
			} while (v7 < *((unsigned __int8*)v4 + 8));
		}
		result = v4;
	}
	return result;
}

//----- (0044BFA0) --------------------------------------------------------
int __cdecl sub_44BFA0(int a1, int a2) {
	int result; // eax

	result = sub_44B8B0(a1, a2);
	if (result)
		result = sub_44BC50(a1, a2);
	return result;
}

//----- (0044B8B0) --------------------------------------------------------
int __cdecl sub_44B8B0(int a1, nox_memfile* f) {
	int a2 = f;
	unsigned __int8* v2; // ecx
	unsigned __int8 v3;  // dl
	unsigned __int8* v4; // ecx
	unsigned __int8 v5;  // dl
	unsigned __int8* v6; // ecx
	unsigned __int8 v8;  // [esp+8h] [ebp-104h]
	char v9[256];        // [esp+Ch] [ebp-100h]

	v2 = *(unsigned __int8**)(a2 + 8);
	v3 = *v2;
	*(_DWORD*)(a2 + 8) = v2 + 1;
	*(_WORD*)(a1 + 40) = v3;
	v4 = *(unsigned __int8**)(a2 + 8);
	v5 = *v4;
	*(_DWORD*)(a2 + 8) = v4 + 1;
	*(_WORD*)(a1 + 42) = v5;
	v6 = *(unsigned __int8**)(a2 + 8);
	v8 = *v6;
	*(_DWORD*)(a2 + 8) = v6 + 1;
	nox_memfile_read(v9, 1u, v8, f);
	v9[v8] = 0;
	*(_DWORD*)(a1 + 44) = sub_44B4C0(v9);
	return 1;
}

//----- (0044BC50) --------------------------------------------------------
int __cdecl sub_44BC50(int a1, int a2) {
	int v2;               // ebp
	int v3;               // esi
	void* v4;             // eax
	int v5;               // ebx
	int* v6;              // eax
	int v7;               // ebp
	_BYTE* v8;            // eax
	char v9;              // dl
	unsigned __int8* v10; // eax
	int v11;              // esi
	int v13;              // [esp+10h] [ebp-90h]
	int v14;              // [esp+14h] [ebp-8Ch]
	const char* v15;      // [esp+1Ch] [ebp-84h]
	char v16[128];        // [esp+20h] [ebp-80h]

	v2 = 0;
	v14 = 0;
	while (1) {
		v13 = v2 >= 16 ? v2 + 4 : v2;
		v3 = a1;
		v4 = nox_malloc(4 * *(__int16*)(a1 + 40));
		*(_DWORD*)(v13 + a1 + 4) = v4;
		if (!v4)
			break;
		v5 = 0;
		if (*(_WORD*)(a1 + 40) > 0) {
			do {
				v6 = *(int**)(a2 + 8);
				v7 = *v6;
				v8 = v6 + 1;
				*(_DWORD*)(a2 + 8) = v8;
				v16[0] = byte_5D4594[830844];
				if (v7 == -1) {
					v9 = *v8;
					v10 = v8 + 1;
					*(_DWORD*)(a2 + 8) = v10;
					LOBYTE(v15) = v9;
					v11 = *v10;
					*(_DWORD*)(a2 + 8) = v10 + 1;
					nox_memfile_read(v16, 1u, v11, a2);
					v16[v11] = 0;
					v3 = a1;
				}
				*(_DWORD*)(*(_DWORD*)(v13 + v3 + 4) + 4 * ++v5 - 4) = sub_42FAA0(v7, v15, v16);
			} while (v5 < *(__int16*)(v3 + 40));
			v2 = v14;
		}
		v2 += 4;
		v14 = v2;
		if (v2 >= 32)
			return 1;
	}
	return 0;
}

//----- (0044B4C0) --------------------------------------------------------
int __cdecl sub_44B4C0(const char* a1) {
	if (!strcmp(a1, "OneShot"))
		return 0;
	if (!strcmp(a1, "OneShotRemove"))
		return 1;
	if (!strcmp(a1, "Loop"))
		return 2;
	if (!strcmp(a1, "LoopAndFade"))
		return 3;
	if (!strcmp(a1, "Random"))
		return 4;
	return strcmp(a1, "Slave") != 0 ? 0 : 5;
}
