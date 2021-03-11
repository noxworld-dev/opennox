#include "proto.h"
#include "nox_fs.h"
extern _DWORD dword_5d4594_2388640;
extern _DWORD dword_5d4594_2388648;

//----- (005199F0) --------------------------------------------------------
void  nox_xxx_netSendMap_5199F0_net_mapsend(unsigned __int8* a1) {
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
			v1 = nox_common_playerInfoFromNum_417090(*a1);
			if (v1) {
				v15 = (int)(v1 + 4704);
				v2 = nox_strman_loadString_40F1D0("Downloadingmap", 0,
										   "C:\\NoxPost\\src\\Server\\Network\\mapsend.c", 231);
				nox_swprintf(v20, v2, getMemAt(0x5D4594, 2387068), v15);
				nox_xxx_consolePrint_450B90(6u, (int)v20);
			}
			*(_DWORD*)&v19[4] = *((_DWORD*)a1 + 3);
			v19[0] = -72;
			strcpy(&v19[8], (const char*)getMemAt(0x5D4594, 2387068));
			nox_xxx_netSendSock_552640(*a1 + 1, v19, 88, NOX_NET_SEND_NO_LOCK | NOX_NET_SEND_FLAG2);
		}
		v3 = malloc(*((unsigned __int16*)a1 + 10) + 6);
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
				v6 = dword_5d4594_2388640;
			}
			memcpy(v3 + 3, (const void*)(v6 + v5), v4);
			nox_xxx_netSendSock_552640(*a1 + 1, v3, v4 + 6, NOX_NET_SEND_NO_LOCK | NOX_NET_SEND_FLAG2);
			free(v3);
			v7 = *((_DWORD*)a1 + 3);
			v8 = v17 + *((_DWORD*)a1 + 6);
			++*((_DWORD*)a1 + 4);
			*((_DWORD*)a1 + 6) = v8;
			if (v8 < v7) {
				*((_WORD*)a1 + 1) = 1;
			} else {
				v9 = (nox_platform_get_ticks() - *((_QWORD*)a1 + 5)) / (unsigned __int64)1000;
				if (v9)
					v10 = *((_DWORD*)a1 + 3) / v9;
				else
					v10 = *((_DWORD*)a1 + 3);
				v11 = nox_common_playerInfoFromNum_417090(*a1);
				if (v11) {
					v12 = nox_strman_loadString_40F1D0("downloaddone", 0,
												"C:\\NoxPost\\src\\Server\\Network\\mapsend.c", 299);
					nox_swprintf(v20, v12, *((_DWORD*)a1 + 6), *((_DWORD*)a1 + 4) - 1, v10, v9, v11 + 4704);
					nox_xxx_consolePrint_450B90(6u, (int)v20);
				}
				if (*((_WORD*)a1 + 2) == 1 && *((_DWORD*)a1 + 2))
					free(*((LPVOID*)a1 + 2));
				v13 = dword_5d4594_2388648;
				if (dword_5d4594_2388648)
					v13 = --dword_5d4594_2388648;
				v16 = v13;
				v14 = nox_strman_loadString_40F1D0("InProgress", 0,
											"C:\\NoxPost\\src\\Server\\Network\\mapsend.c", 315);
				nox_swprintf(v20, v14, v16);
				nox_xxx_consolePrint_450B90(6u, (int)v20);
				nox_xxx_netMapSendClear_519830((int)a1, *a1);
			}
		}
	}
}
// 519AFD: variable 'v18' is possibly undefined

//----- (00519C80) --------------------------------------------------------
void  nox_xxx_netSendMapAbort_519C80_net_mapsend(unsigned __int8* a1, unsigned __int8 a2) {
	int v2;          // ecx
	wchar_t* v3;     // eax
	int v4;          // [esp-Ch] [ebp-114h]
	char v5[2];      // [esp+6h] [ebp-102h]
	wchar_t v6[128]; // [esp+8h] [ebp-100h]

	if (a1) {
		v2 = *a1;
		v5[0] = -70;
		v5[1] = a2;
		nox_xxx_netSendSock_552640(v2 + 1, v5, 2, NOX_NET_SEND_NO_LOCK | NOX_NET_SEND_FLAG2);
		if (dword_5d4594_2388648)
			--dword_5d4594_2388648;
		v4 = *a1;
		v3 = nox_strman_loadString_40F1D0("downloadaborted", 0, "C:\\NoxPost\\src\\Server\\Network\\mapsend.c", 350);
		nox_swprintf(v6, v3, v4, a2);
		nox_xxx_consolePrint_450B90(6u, (int)v6);
	}
}

//----- (00519D20) --------------------------------------------------------
char*  nox_xxx_netMapSend_519D20(int a1) {
	unsigned __int8* v1; // esi
	wchar_t* v2;         // eax
	char* result;        // eax

	v1 = getMemAt(0x5D4594, 48 * a1 + 2387148);
	++dword_5d4594_2388648;
	if (*((_WORD*)v1 + 1)) {
		if (*((_WORD*)v1 + 1) == 1)
			v2 = nox_strman_loadString_40F1D0("Sending", 0, "C:\\NoxPost\\src\\Server\\Network\\mapsend.c",
									   392);
		else
			v2 = nox_strman_loadString_40F1D0("BadState", 0, "C:\\NoxPost\\src\\Server\\Network\\mapsend.c",
									   397);
		result = (char*)nox_xxx_consolePrint_450B90(6u, (int)v2);
	} else {
		++*getMemU16Ptr(0x5D4594, 2388636);
		*((_WORD*)v1 + 1) = 1;
		*((_DWORD*)v1 + 6) = 0;
		*((_DWORD*)v1 + 4) = 1;
		*((_WORD*)v1 + 10) = 512;
		*((_DWORD*)v1 + 3) = *getMemU32Ptr(0x5D4594, 2388644);
		*((_QWORD*)v1 + 5) = nox_platform_get_ticks();
		result = nox_common_playerInfoFromNum_417090(a1);
	}
	return result;
}

//----- (00519DE0) --------------------------------------------------------
int  nox_xxx_netMapSendCancelMap_519DE0_net_mapsend(int a1) {
	unsigned __int8* v1; // esi
	char* v2;            // ebx
	int result;          // eax
	wchar_t* v4;         // eax

	v1 = getMemAt(0x5D4594, 48 * a1 + 2387148);
	v2 = nox_common_playerInfoFromNum_417090(a1);
	*((_WORD*)v1 + 1) = 0;
	nullsub_27(v1);
	++*getMemU16Ptr(0x5D4594, 2388638);
	if (*((_WORD*)v1 + 2) == 1 && *((_DWORD*)v1 + 2))
		free(*((LPVOID*)v1 + 2));
	nox_xxx_netMapSendClear_519830((int)v1, a1);
	result = dword_5d4594_2388648;
	if (dword_5d4594_2388648)
		result = --dword_5d4594_2388648;
	if (v2) {
		v4 = nox_strman_loadString_40F1D0("downloadcancelled", 0, "C:\\NoxPost\\src\\Server\\Network\\mapsend.c", 428);
		result = nox_xxx_consoleVPrint_450C00(6u, v4, v2 + 4704);
	}
	return result;
}
// 519920: using guessed type void  nullsub_27(_DWORD);

//----- (00519EB0) --------------------------------------------------------
int nox_xxx_netMapSendPrepair_519EB0_net_mapsend() {
	char* v0;            // eax
	unsigned __int8* v1; // ebx
	void* v2;            // eax
	const void* v3;      // esi
	unsigned int v4;     // kr00_4
	wchar_t* v5;         // eax
	char* v6;            // edi
	unsigned __int8 v7;  // cl
	FILE* v8;            // ebx
	wchar_t* v10;        // eax
	const char* v11;     // [esp+10h] [ebp-104h]
	char v12[256];       // [esp+14h] [ebp-100h]

	v0 = nox_server_currentMapGetFilename_409B30();
	v11 = v0;
	if (dword_5d4594_2388648) {
		v1 = getMemAt(0x5D4594, 2387156);
		do {
			if (*((_WORD*)v1 - 3) == 1) {
				v2 = malloc(*(size_t*)getMemAt(0x5D4594, 2388644));
				*(_DWORD*)v1 = v2;
				if (v2) {
					v3 = *(const void**)&dword_5d4594_2388640;
					v4 = *getMemU32Ptr(0x5D4594, 2388644);
					*((_WORD*)v1 - 2) = 1;
					memcpy(v2, v3, v4);
					*((_DWORD*)v1 + 1) = *getMemU32Ptr(0x5D4594, 2388644);
					v5 = nox_strman_loadString_40F1D0("ForceCopy", 0,
											   "C:\\NoxPost\\src\\Server\\Network\\mapsend.c", 478);
					nox_xxx_consolePrint_450B90(6u, (int)v5);
				} else {
					nox_xxx_netSendMapAbort_519C80_net_mapsend(v1 - 8, 1u);
				}
			}
			v1 += 48;
		} while ((int)v1 < (int)getMemAt(0x5D4594, 2388644));
		v0 = (char*)v11;
	}
	if (!v0) {
		v10 = nox_strman_loadString_40F1D0("CompressFail", 0, "C:\\NoxPost\\src\\Server\\Network\\mapsend.c", 518);
		nox_xxx_consolePrint_450B90(6u, (int)v10);
		return 0;
	}
	if (!memcmp(v0, getMemAt(0x5D4594, 2388652), 1u)) {
		v10 = nox_strman_loadString_40F1D0("CompressFail", 0, "C:\\NoxPost\\src\\Server\\Network\\mapsend.c", 518);
		nox_xxx_consolePrint_450B90(6u, (int)v10);
		return 0;
	}
	strcpy(v12, "maps\\");
	strcat(v12, nox_xxx_mapGetMapName_409B40());
	*(_WORD*)&v12[strlen(v12)] = *getMemU16Ptr(0x587000, 249808);
	strcat(v12, nox_xxx_mapGetMapName_409B40());
	v6 = &v12[strlen(v12) + 1];
	v7 = getMemByte(0x587000, 249816);
	*(_DWORD*)--v6 = *getMemU32Ptr(0x587000, 249812);
	v6[4] = v7;
	v8 = nox_fs_open(v12);
	if (!v8) {
		v10 = nox_strman_loadString_40F1D0("CompressFail", 0, "C:\\NoxPost\\src\\Server\\Network\\mapsend.c", 518);
		nox_xxx_consolePrint_450B90(6u, (int)v10);
		return 0;
	}
	strcpy((char*)getMemAt(0x5D4594, 2386988), v12);
	strcpy((char*)getMemAt(0x5D4594, 2387068), v11);
	fseek(v8, 0, SEEK_END);
	*getMemU32Ptr(0x5D4594, 2388644) = ftell(v8);
	fseek(v8, 0, SEEK_SET);
	dword_5d4594_2388640 = malloc(*(size_t*)getMemAt(0x5D4594, 2388644));
	nox_xxx_fileBinRead_40ADD0_fread(*(char**)&dword_5d4594_2388640, 1u, *(size_t*)getMemAt(0x5D4594, 2388644), v8);
	fclose(v8);
	return 1;
}
