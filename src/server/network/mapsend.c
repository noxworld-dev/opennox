#include "../../proto.h"

//----- (005199F0) --------------------------------------------------------
void __cdecl sub_5199F0_net_mapsend(unsigned __int8* a1) {
	char* v1;         // eax
	wchar_t* v2;      // eax
	_WORD* v3;        // ebp
	unsigned int v4;  // eax
	int v5;           // esi
	int v6;           // edi
	unsigned int v7;  // ecx
	unsigned int v8;  // eax
	unsigned int v9;  // esi
	int v10;          // ebp
	char* v11;        // edi
	wchar_t* v12;     // eax
	int v13;          // eax
	wchar_t* v14;     // eax
	int v15;          // [esp-4h] [ebp-178h]
	int v16;          // [esp-4h] [ebp-178h]
	int v17;          // [esp+10h] [ebp-164h]
	int v18;          // [esp+14h] [ebp-160h]
	char v19[88];     // [esp+1Ch] [ebp-158h]
	wchar_t v20[128]; // [esp+74h] [ebp-100h]

	if (a1) {
		if (!*((_DWORD*)a1 + 6)) {
			v1 = sub_417090(*a1);
			if (v1) {
				v15 = (int)(v1 + 4704);
				v2 = loadString_sub_40F1D0((char*)&byte_587000[249408], 0,
							   "C:\\NoxPost\\src\\Server\\Network\\mapsend.c", 231);
				nox_swprintf(v20, v2, &byte_5D4594[2387068], v15);
				sub_450B90(6u, (int)v20);
			}
			*(_DWORD*)&v19[4] = *((_DWORD*)a1 + 3);
			v19[0] = -72;
			strcpy(&v19[8], (const char*)&byte_5D4594[2387068]);
			sub_552640(*a1 + 1, v19, 88, 3);
		}
		v3 = nox_malloc(*((unsigned __int16*)a1 + 10) + 6);
		if (v3) {
			v4 = *((unsigned __int16*)a1 + 10);
			if ((unsigned __int16)v4 >= (unsigned int)(*((_DWORD*)a1 + 3) - *((_DWORD*)a1 + 6))) {
				v17 = *((_DWORD*)a1 + 3) - *((_DWORD*)a1 + 6);
				v4 = *((_DWORD*)a1 + 3) - *((_DWORD*)a1 + 6);
			} else {
				v17 = *((unsigned __int16*)a1 + 10);
			}
			LOBYTE(v18) = -71;
			HIWORD(v18) = *((_WORD*)a1 + 8);
			*(_DWORD*)v3 = v18;
			v3[2] = v4;
			if (*((_WORD*)a1 + 2)) {
				v5 = *((_DWORD*)a1 + 2);
				v6 = *((_DWORD*)a1 + 6);
			} else {
				v5 = *((_DWORD*)a1 + 6);
				v6 = *(_DWORD*)&byte_5D4594[2388640];
			}
			qmemcpy(v3 + 3, (const void*)(v6 + v5), v4);
			sub_552640(*a1 + 1, v3, v4 + 6, 3);
			free(v3);
			v7 = *((_DWORD*)a1 + 3);
			v8 = v17 + *((_DWORD*)a1 + 6);
			++*((_DWORD*)a1 + 4);
			*((_DWORD*)a1 + 6) = v8;
			if (v8 < v7) {
				*((_WORD*)a1 + 1) = 1;
			} else {
				v9 = (sub_416BB0() - *((_QWORD*)a1 + 5)) / (unsigned __int64)1000;
				if (v9)
					v10 = *((_DWORD*)a1 + 3) / v9;
				else
					v10 = *((_DWORD*)a1 + 3);
				v11 = sub_417090(*a1);
				if (v11) {
					v12 =
					    loadString_sub_40F1D0((char*)&byte_587000[249464], 0,
								  "C:\\NoxPost\\src\\Server\\Network\\mapsend.c", 299);
					nox_swprintf(v20, v12, *((_DWORD*)a1 + 6), *((_DWORD*)a1 + 4) - 1, v10, v9,
						     v11 + 4704);
					sub_450B90(6u, (int)v20);
				}
				if (*((_WORD*)a1 + 2) == 1 && *((_DWORD*)a1 + 2))
					free(*((LPVOID*)a1 + 2));
				v13 = *(_DWORD*)&byte_5D4594[2388648];
				if (*(_DWORD*)&byte_5D4594[2388648])
					v13 = --*(_DWORD*)&byte_5D4594[2388648];
				v16 = v13;
				v14 = loadString_sub_40F1D0((char*)&byte_587000[249520], 0,
							    "C:\\NoxPost\\src\\Server\\Network\\mapsend.c", 315);
				nox_swprintf(v20, v14, v16);
				sub_450B90(6u, (int)v20);
				sub_519830((int)a1, *a1);
			}
		}
	}
}
// 519AFD: variable 'v18' is possibly undefined

//----- (00519C80) --------------------------------------------------------
void __cdecl sub_519C80_net_mapsend(unsigned __int8* a1, unsigned __int8 a2) {
	int v2;          // ecx
	wchar_t* v3;     // eax
	int v4;          // [esp-Ch] [ebp-114h]
	char v5[2];      // [esp+6h] [ebp-102h]
	wchar_t v6[128]; // [esp+8h] [ebp-100h]

	if (a1) {
		v2 = *a1;
		v5[0] = -70;
		v5[1] = a2;
		sub_552640(v2 + 1, v5, 2, 3);
		if (*(_DWORD*)&byte_5D4594[2388648])
			--*(_DWORD*)&byte_5D4594[2388648];
		v4 = *a1;
		v3 = loadString_sub_40F1D0((char*)&byte_587000[249572], 0,
					   "C:\\NoxPost\\src\\Server\\Network\\mapsend.c", 350);
		nox_swprintf(v6, v3, v4, a2);
		sub_450B90(6u, (int)v6);
	}
}

//----- (00519D20) --------------------------------------------------------
char* __cdecl sub_519D20(int a1) {
	unsigned __int8* v1; // esi
	wchar_t* v2;         // eax
	char* result;        // eax

	v1 = &byte_5D4594[48 * a1 + 2387148];
	++*(_DWORD*)&byte_5D4594[2388648];
	if (*((_WORD*)v1 + 1)) {
		if (*((_WORD*)v1 + 1) == 1)
			v2 = loadString_sub_40F1D0((char*)&byte_587000[249628], 0,
						   "C:\\NoxPost\\src\\Server\\Network\\mapsend.c", 392);
		else
			v2 = loadString_sub_40F1D0((char*)&byte_587000[249676], 0,
						   "C:\\NoxPost\\src\\Server\\Network\\mapsend.c", 397);
		result = (char*)sub_450B90(6u, (int)v2);
	} else {
		++*(_WORD*)&byte_5D4594[2388636];
		*((_WORD*)v1 + 1) = 1;
		*((_DWORD*)v1 + 6) = 0;
		*((_DWORD*)v1 + 4) = 1;
		*((_WORD*)v1 + 10) = 512;
		*((_DWORD*)v1 + 3) = *(_DWORD*)&byte_5D4594[2388644];
		*((_QWORD*)v1 + 5) = sub_416BB0();
		result = sub_417090(a1);
	}
	return result;
}

//----- (00519DE0) --------------------------------------------------------
int __cdecl sub_519DE0_net_mapsend(int a1) {
	unsigned __int8* v1; // esi
	char* v2;            // ebx
	int result;          // eax
	wchar_t* v4;         // eax

	v1 = &byte_5D4594[48 * a1 + 2387148];
	v2 = sub_417090(a1);
	*((_WORD*)v1 + 1) = 0;
	nullsub_27(v1);
	++*(_WORD*)&byte_5D4594[2388638];
	if (*((_WORD*)v1 + 2) == 1 && *((_DWORD*)v1 + 2))
		free(*((LPVOID*)v1 + 2));
	sub_519830((int)v1, a1);
	result = *(_DWORD*)&byte_5D4594[2388648];
	if (*(_DWORD*)&byte_5D4594[2388648])
		result = --*(_DWORD*)&byte_5D4594[2388648];
	if (v2) {
		v4 = loadString_sub_40F1D0((char*)&byte_587000[249728], 0,
					   "C:\\NoxPost\\src\\Server\\Network\\mapsend.c", 428);
		result = sub_450C00(6u, v4, v2 + 4704);
	}
	return result;
}
// 519920: using guessed type void __cdecl nullsub_27(_DWORD);

//----- (00519EB0) --------------------------------------------------------
int sub_519EB0_net_mapsend() {
	char* v0;            // eax
	unsigned __int8* v1; // ebx
	void* v2;            // eax
	const void* v3;      // esi
	unsigned int v4;     // kr00_4
	wchar_t* v5;         // eax
	char* v6;            // edi
	unsigned __int8 v7;  // cl
	FILE* v8;            // ebx
	int result;          // eax
	wchar_t* v10;        // eax
	const char* v11;     // [esp+10h] [ebp-104h]
	char v12[256];       // [esp+14h] [ebp-100h]

	v0 = nox_server_currentMapGetFilename_409B30();
	v11 = v0;
	if (*(_DWORD*)&byte_5D4594[2388648]) {
		v1 = &byte_5D4594[2387156];
		do {
			if (*((_WORD*)v1 - 3) == 1) {
				v2 = nox_malloc(*(size_t*)&byte_5D4594[2388644]);
				*(_DWORD*)v1 = v2;
				if (v2) {
					v3 = *(const void**)&byte_5D4594[2388640];
					v4 = *(_DWORD*)&byte_5D4594[2388644];
					*((_WORD*)v1 - 2) = 1;
					qmemcpy(v2, v3, v4);
					*((_DWORD*)v1 + 1) = *(_DWORD*)&byte_5D4594[2388644];
					v5 = loadString_sub_40F1D0((char*)&byte_587000[249788], 0,
								   "C:\\NoxPost\\src\\Server\\Network\\mapsend.c", 478);
					sub_450B90(6u, (int)v5);
				} else {
					sub_519C80_net_mapsend(v1 - 8, 1u);
				}
			}
			v1 += 48;
		} while ((int)v1 < (int)&byte_5D4594[2388644]);
		v0 = (char*)v11;
	}
	if (!v0)
		goto LABEL_16;
	if (!memcmp(v0, &byte_5D4594[2388652], 1u))
		goto LABEL_16;
	strcpy(v12, "maps\\");
	strcat(v12, sub_409B40());
	*(_WORD*)&v12[strlen(v12)] = *(_WORD*)&byte_587000[249808];
	strcat(v12, sub_409B40());
	v6 = &v12[strlen(v12) + 1];
	v7 = byte_587000[249816];
	*(_DWORD*)--v6 = *(_DWORD*)&byte_587000[249812];
	v6[4] = v7;
	v8 = fopen(v12, "rb");
	if (v8) {
		strcpy((char*)&byte_5D4594[2386988], v12);
		strcpy((char*)&byte_5D4594[2387068], v11);
		fseek(v8, 0, 2);
		*(_DWORD*)&byte_5D4594[2388644] = ftell(v8);
		fseek(v8, 0, 0);
		*(_DWORD*)&byte_5D4594[2388640] = nox_malloc(*(size_t*)&byte_5D4594[2388644]);
		sub_40ADD0_fread(*(char**)&byte_5D4594[2388640], 1u, *(size_t*)&byte_5D4594[2388644], v8);
		fclose(v8);
		result = 1;
	} else {
	LABEL_16:
		v10 = loadString_sub_40F1D0((char*)&byte_587000[249864], 0,
					    "C:\\NoxPost\\src\\Server\\Network\\mapsend.c", 518);
		sub_450B90(6u, (int)v10);
		result = 0;
	}
	return result;
}