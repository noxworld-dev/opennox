#include "drawdb.h"

#include "../../proto.h"

extern int nox_things_count;
extern nox_thing* nox_things_head;
extern nox_thing** nox_things_array;
extern nox_memfile* nox_loaded_thing_bin;

//----- (0044C480) --------------------------------------------------------
bool __cdecl nox_parse_thing_pretty_name(nox_thing* obj, nox_memfile* f, char* a3) {
	obj->pretty_name = loadString_sub_40F1D0(a3, 0, "C:\\NoxPost\\src\\Client\\Drawable\\drawdb.c", 1396);
	return 1;
}

//----- (0044C4B0) --------------------------------------------------------
bool __cdecl nox_parse_thing_desc(nox_thing* obj, nox_memfile* f, char* a3) {
	obj->desc = loadString_sub_40F1D0(a3, 0, "C:\\NoxPost\\src\\Client\\Drawable\\drawdb.c", 1403);
	return 1;
}

//----- (0044C840) --------------------------------------------------------
void* __cdecl sub_44C840_read_things(void) {
	char* v1;             // ebx
	int v6;               // eax
	CHAR* v9;             // esi
	unsigned int v10;     // edx
	unsigned __int8* v11; // edi
	unsigned __int8* v12; // edi
	CHAR* v13;            // esi
	char v14;             // cl
	unsigned __int8* v15; // edi
	int v16;              // ecx
	unsigned __int8 v17;  // al
	CHAR* v18;            // esi
	unsigned int v19;     // edx
	unsigned __int8* v20; // edi
	unsigned __int8* v21; // edi
	CHAR* v22;            // esi
	char v23;             // cl
	int v24;              // edx
	unsigned __int8* v25; // edi
	int v26;              // ecx
	int i;                // [esp+10h] [ebp-4h]
	unsigned __int8 v28;  // [esp+18h] [ebp+4h]

	v1 = (char*)nox_malloc(256 * 1024);
	sub_44CCA0();
	sub_44C580_free();
	nox_things_count = 1;
	sub_485CF0();
	sub_485F30();
	sub_46A360();

	nox_memfile* things = nox_open_thing_bin();
	if (!things)
		return 0;
	nox_memfile_seek_40AD10(things, 0, 0);
	while (nox_memfile_read(&i, 4u, 1, things)) {
		switch (i) {
		case 0x5350454C: // "SPEL"
			sub_415100_read_spells(things);
			break;
		case 0x4142494C: // "ABIL"
			sub_415320(things);
			break;
		case 0x41554420: // "AUD "
			sub_414D40(things);
			break;
		case 0x41564E54: // "AVNT"
			sub_452B00(things);
			break;
		case 0x57414C4C: // "WALL"
			if (!sub_46A010(things, v1))
				return 0;
			break;
		case 0x464C4F52: // "FLOR"
			if (!sub_485B30(things, v1))
				return 0;
			break;
		case 0x45444745: // "EDGE"
			if (!sub_485D40(things, v1))
				return 0;
			break;
		case 0x494D4147: // "IMAG"
			sub_415240(things);
			break;
		case 0x54484E47: // "THNG"
			;
			nox_thing* obj = (nox_thing*)nox_calloc(1, sizeof(nox_thing));
			if (!obj)
				return 0;
			v28 = *(unsigned __int8*)things->cur;
			things->cur++;
			nox_memfile_read(v1, 1u, v28, things);
			v1[v28] = 0;
			obj->name = nox_clone_str(v1);
			obj->menuicon = -1;
			obj->field_1c = nox_things_count++;
			obj->flags |= 0x1000000;
			*((_BYTE*)obj + 15) = 0;
			obj->field_10 = 0xFFFF;
			obj->audio_loop = 0;
			obj->draw_func = nox_thing_debug_draw;
			obj->zsize_min = 0;
			obj->zsize_max = 30.0f;
			if (!nox_parse_thing(things, v1, obj))
				return 0;
			obj->next = nox_things_head;
			nox_things_head = obj;
			sub_44CD10(obj->name);
			break;
		}
	}
	*(_DWORD*)&byte_5D4594[2649708] = 1;
	if (nox_loaded_thing_bin) {
		if (nox_common_gameFlags_check_40A5C0(1) && *(_DWORD*)&byte_5D4594[2650664]) {
			nox_free_thing_bin();
		}
	} else {
		nox_memfile_free(things);
	}
	void* result = nox_malloc(4 * nox_things_count);
	nox_things_array = result;
	if (result) {
		sub_44CCD0();
		v6 = nox_things_count;
		nox_thing* cur = nox_things_head;
		for (int i = 1; i < nox_things_count; i++) {
			nox_things_array[v6 - i] = cur;
			sub_44CD60(cur, nox_things_count - i);
			if (*((_BYTE*)cur + 0xe)) {
				if (!cur->pretty_name) {
					strcpy((char*)&byte_5D4594[830404], "thing.db:");
					v9 = cur->name;
					v10 = strlen(cur->name) + 1;
					v11 = &byte_5D4594[strlen((const char*)&byte_5D4594[830404]) + 830404];
					qmemcpy(v11, cur->name, 4 * (v10 >> 2));
					v13 = &v9[4 * (v10 >> 2)];
					v12 = &v11[4 * (v10 >> 2)];
					v14 = v10;
					LOWORD(v10) = *(_WORD*)&byte_587000[122728];
					qmemcpy(v12, v13, v14 & 3);
					v15 = &byte_5D4594[strlen((const char*)&byte_5D4594[830404]) + 830405];
					v16 = *(_DWORD*)&byte_587000[122724];
					*(_DWORD*)--v15 = *(_DWORD*)&byte_587000[122720];
					v17 = byte_587000[122730];
					*((_DWORD*)v15 + 1) = v16;
					*((_WORD*)v15 + 4) = v10;
					v15[10] = v17;
					cur->pretty_name = loadString_sub_40F1D0((char*)&byte_5D4594[830404], 0,
															 "C:\\NoxPost\\src\\Client\\Drawable\\drawdb.c", 1926);
				}
				if (!cur->desc) {
					strcpy((char*)&byte_5D4594[830404], "thing.db:");
					v18 = cur->name;
					v19 = strlen(cur->name) + 1;
					v20 = &byte_5D4594[strlen((const char*)&byte_5D4594[830404]) + 830404];
					qmemcpy(v20, cur->name, 4 * (v19 >> 2));
					v22 = &v18[4 * (v19 >> 2)];
					v21 = &v20[4 * (v19 >> 2)];
					v23 = v19;
					v24 = *(_DWORD*)&byte_587000[122792];
					qmemcpy(v21, v22, v23 & 3);
					v25 = &byte_5D4594[strlen((const char*)&byte_5D4594[830404]) + 830405];
					v26 = *(_DWORD*)&byte_587000[122788];
					*(_DWORD*)--v25 = *(_DWORD*)&byte_587000[122784];
					*((_DWORD*)v25 + 1) = v26;
					*((_DWORD*)v25 + 2) = v24;
					cur->desc = loadString_sub_40F1D0((char*)&byte_5D4594[830404], 0,
													  "C:\\NoxPost\\src\\Client\\Drawable\\drawdb.c", 1933);
				}
			}
			v6 = nox_things_count;
			cur = cur->next;
		}
		sub_44CDB0();
		free(v1);
		sub_4131A0();
		sub_415AB0();
		sub_4157C0();
		result = (void*)(sub_42BF10() != 0);
	}
	return result;
}
