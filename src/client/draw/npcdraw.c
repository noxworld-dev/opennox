#include "npcdraw.h"
#include "vectdraw.h"
#include "../drawable/drawable.h"
#include "../system/npcinfo.h"
#include "../../proto.h"

extern _DWORD dword_5d4594_1313796;
extern _DWORD dword_5d4594_1313800;

//----- (004B9050) --------------------------------------------------------
int __cdecl nox_thing_npc_draw(int* a1, nox_drawable* dr) {
	int v2;                           // eax
	int v4;                           // edi
	int* v5;                          // ebp
	int v6;                           // eax
	int v7;                           // esi
	int v8;                           // eax
	int v9;                           // esi
	int v10;                          // eax
	int v11;                          // esi
	int v12;                          // esi
	int* v13;                         // ebx
	int v14;                          // eax
	int v15;                          // eax
	int* v16;                         // ebx
	int v17;                          // esi
	int v18;                          // eax
	int v19;                          // ebp
	int v20;                          // ebx
	int* v21;                         // esi
	char v22;                         // al
	int v23;                          // eax
	void(__cdecl * *v24)(char*, int); // ebx
	char* v25;                        // eax
	int v26;                          // eax
	void(__cdecl * *v27)(char*, int); // ebx
	char* v28;                        // eax
	int i;                            // esi
	int v30;                          // [esp-4h] [ebp-24h]
	int v31;                          // [esp-4h] [ebp-24h]
	int v32;                          // [esp-4h] [ebp-24h]
	int* v33;                         // [esp+10h] [ebp-10h]
	int v34;                          // [esp+14h] [ebp-Ch]
	int v35;                          // [esp+18h] [ebp-8h]
	int v36;                          // [esp+1Ch] [ebp-4h]

	int a2 = dr;

	if (nox_common_gameFlags_check_40A5C0(0x200000)) {
		v2 = *(_DWORD*)(sub_44D330((CHAR*)getMemAt(0x587000, 177440)) + 92) + 4;
		if (*(_WORD*)(v2 + 40)) {
			sub_4C4770_draw(a1, (unsigned __int8*)a2,
				**(_DWORD**)(*(_DWORD*)(v2 + 48) + 4 * *(unsigned __int8*)(a2 + 297) + 4));
			return 1;
		}
	} else {
		v4 = a2;
		v30 = *(_DWORD*)(a2 + 128);
		v36 = *(_DWORD*)(*getMemU32Ptr(0x5D4594, 2614252) + 304);
		v5 = (int*)nox_npc_by_id(v30);
		v33 = v5;
		if (v5) {
			if (sub_4356C0(v4, 23)) {
				if (getMemByte(0x5D4594, 2598000) & 1) {
					v6 = 0;
					do {
						v7 = v6 + 1;
						sub_4341D0(v6 + 1, *getMemIntPtr(0x5D4594, 2523948));
						v6 = v7;
					} while (v7 < 6);
				} else {
					v8 = 0;
					do {
						v9 = v8 + 1;
						sub_4341D0(v8 + 1, *getMemIntPtr(0x5D4594, 2650684));
						v8 = v9;
					} while (v9 < 6);
				}
			} else if (sub_4356C0(v4, 25)) {
				v10 = 0;
				do {
					v11 = v10 + 1;
					sub_4341D0(v10 + 1, *getMemIntPtr(0x5D4594, 2650684));
					v10 = v11;
				} while (v11 < 6);
			} else if (v5[328] == 1) {
				v12 = 0;
				v13 = v5 + 2;
				do {
					sub_434480(*v13, (int)&v35, (int)&a2, (int)&v34);
					if ((unsigned __int8)a2 >= 0x9Bu)
					LOBYTE(a2) = -1;
					else
					LOBYTE(a2) = a2 + 100;
					++v12;
					v14 = sub_4344A0(v35, a2, v34);
					sub_4341D0(v12, v14);
					++v13;
				} while (v12 < 6);
			} else {
				v15 = 0;
				v16 = v5 + 2;
				do {
					v17 = v15 + 1;
					sub_4341D0(v15 + 1, *v16);
					v15 = v17;
					++v16;
				} while (v17 < 6);
			}
			v18 = sub_49A4B0((_DWORD*)v4, v5[326], v5[327]);
			v19 = v36 + 264 * v18 + 4;
			if (*(_WORD*)(v36 + 264 * v18 + 44)) {
				v20 = sub_4BC5D0((_DWORD*)v4, v36 + 264 * v18 + 4);
				if (v20 < 0)
					return 0;
				v21 = a1;
				sub_4C4770_draw(
					a1, (unsigned __int8*)v4,
					*(_DWORD*)(*(_DWORD*)(*(_DWORD*)(v19 + 48) + 4 * *(unsigned __int8*)(v4 + 297) + 4) + 4 * v20));
				v22 = *(_BYTE*)(v4 + 297);
				if (v22 != 1 && v22 && v22 != 2 && v22 != 3 && v22 != 6 || *(_DWORD*)(v4 + 276) == 37) {
					sub_4B8960(v21, v4, v33[327], v33 + 170, v19, v20);
					sub_4B8D40(v21, v4, v33[326], v33 + 8, v19, v20);
				} else {
					sub_4B8D40(v21, v4, v33[326], v33 + 8, v19, v20);
					sub_4B8960(v21, v4, v33[327], v33 + 170, v19, v20);
				}
				if (sub_4356C0(v4, 16)) {
					if (!dword_5d4594_1313796) {
						v23 = sub_44CFC0((CHAR*)getMemAt(0x587000, 177452));
						dword_5d4594_1313796 = nox_new_drawable_for_thing(v23);
						*(_DWORD*)(dword_5d4594_1313796 + 120) |= 0x1000000u;
					}
					*(_DWORD*)(dword_5d4594_1313796 + 12) = *v21 + *(_DWORD*)(v4 + 12) - v21[4];
					*(_DWORD*)(dword_5d4594_1313796 + 16) = v21[1] - v21[5] + *(_DWORD*)(v4 + 16) - 50;
					v31 = dword_5d4594_1313796;
					v24 = (void(__cdecl**)(char*, int))(dword_5d4594_1313796 + 300);
					v25 = sub_437250();
					(*v24)(v25, v31);
				}
				if (sub_4356C0(v4, 30)) {
					if (!dword_5d4594_1313800) {
						v26 = sub_44CFC0((CHAR*)getMemAt(0x587000, 177468));
						dword_5d4594_1313800 = nox_new_drawable_for_thing(v26);
						*(_DWORD*)(dword_5d4594_1313800 + 120) |= 0x1000000u;
					}
					*(_DWORD*)(dword_5d4594_1313800 + 12) = *v21 + *(_DWORD*)(v4 + 12) - v21[4];
					*(_DWORD*)(dword_5d4594_1313800 + 16) = v21[1] - v21[5] + *(_DWORD*)(v4 + 16) - 50;
					v32 = dword_5d4594_1313800;
					v27 = (void(__cdecl**)(char*, int))(dword_5d4594_1313800 + 300);
					v28 = sub_437250();
					(*v27)(v28, v32);
				}
				if (sub_4951F0(*(_DWORD*)(v4 + 128))) {
					v33 = 0;
					a1 = 0;
					LOBYTE(a2) = 0;
					sub_495180(*(_DWORD*)(v4 + 128), &v33, &a1, &a2);
					sub_4BC080(v21, v4, (unsigned __int16)v33, (unsigned __int16)a1, a2);
				}
				for (i = 0; i < 6; ++i)
					sub_4341D0(i, *getMemIntPtr(0x5D4594, 2523948));
			}
		}
	}
	return 1;
}
