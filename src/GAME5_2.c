#include "client/system/parsecmd.h"

#include "client/gui/guiinv.h"
#include "common/system/group.h"
#include "comw32/comlib.h"

#include "proto.h"

#include <float.h>
extern _DWORD dword_587000_312804;
extern _DWORD dword_5d4594_3844304;
extern _DWORD dword_5d4594_2513920;
extern _DWORD dword_587000_312820;
extern _QWORD qword_581450_9544;
extern _DWORD dword_5d4594_2523912;
extern _DWORD dword_5d4594_2523780;
extern _DWORD dword_5d4594_2495920;
extern _DWORD dword_5d4594_2516344;
extern _DWORD dword_5d4594_2523900;
extern _DWORD dword_5d4594_2523756;
extern _DWORD dword_5d4594_2523752;
extern _DWORD dword_5d4594_2516328;
extern _DWORD dword_5d4594_2516348;
extern _DWORD dword_5d4594_2650652;

//----- (005528B0) --------------------------------------------------------
int __cdecl sub_5528B0(unsigned int a1, char a2) {
	unsigned int v2;     // ecx
	int v3;              // edx
	unsigned int v5;     // eax
	unsigned int v6;     // ebx
	int v7;              // edi
	unsigned __int8* v8; // eax
	int v9;              // esi
	DWORD v10;           // eax
	int v11;             // eax
	unsigned int v12;    // eax
	char* v13;           // eax
	int v14;             // ebp
	unsigned int v15;    // [esp+10h] [ebp-Ch]
	unsigned __int8* i;  // [esp+14h] [ebp-8h]
	SOCKET* v17;         // [esp+18h] [ebp-4h]
	unsigned int v18;    // [esp+20h] [ebp+4h]

	v2 = a1;
	v3 = *(_DWORD*)&byte_5D4594[4 * a1 + 3843788];
	v17 = *(SOCKET**)&byte_5D4594[4 * a1 + 3843788];
	if (a1 >= 0x80)
		return -3;
	if (!v3)
		return -3;
	if (*(int*)(v3 + 20) == -1) {
		if (*(_DWORD*)(v3 + 76)) {
			SetEvent(*(HANDLE*)(v3 + 136));
			return 0;
		}
		v5 = 0;
		v18 = 128;
	} else {
		v5 = a1;
		v18 = a1 + 1;
		v2 = *(_DWORD*)(v3 + 20);
	}
	v15 = v2;
	v6 = v5;
	if (v5 < v18) {
		v7 = v18;
		v8 = &byte_5D4594[4 * v5 + 3843788];
		for (i = v8;; i += 4) {
			v9 = *(_DWORD*)v8;
			if (*(_DWORD*)v8 && *(_DWORD*)(v9 + 20) == v15) {
				sub_5552D0(v6, 0, 0);
				v10 = WaitForSingleObject(*(HANDLE*)(v9 + 128), 0x3E8u);
				v7 = v10;
				if (v10 == -1 || v10 == 258)
					return -16;
				if (!(a2 & 1)) {
					v11 = (*(int(__cdecl**)(unsigned int, _DWORD, int, _DWORD))(v9 + 140))(
					    v6, *(_DWORD*)(v9 + 52), *(_DWORD*)(v9 + 60) - *(_DWORD*)(v9 + 52),
					    *(_DWORD*)(v9 + 120));
					v7 = v11;
					if (v11 > 0) {
						v12 = v11 + *(_DWORD*)(v9 + 52);
						if (v12 < *(int*)(v9 + 60))
							*(_DWORD*)(v9 + 52) = v12;
					}
				}
				v13 = *(char**)(v9 + 48);
				v14 = *(_DWORD*)(v9 + 52) - (_DWORD)v13;
				if (v14 > 2) {
					v7 = sub_551F90(*v17, v13, v14, 0, (struct sockaddr*)(v9 + 4), 16);
					if (v7 == -1)
						return -1;
					sub_553F40(v14, 1);
					sub_554030(v14, v6);
					*(_DWORD*)(v9 + 52) = *(_DWORD*)(v9 + 56);
				}
				if (!ReleaseMutex(*(HANDLE*)(v9 + 128)))
					ReleaseMutex(*(HANDLE*)(v9 + 128));
			}
			++v6;
			v8 = i + 4;
			if (v6 >= v18)
				return v7;
		}
	}
	return v18;
}

//----- (00552A80) --------------------------------------------------------
int __cdecl sub_552A80(unsigned int a1, char a2) {
	int v2;              // ebp
	int result;          // eax
	SOCKET v4;           // eax
	int v5;              // eax
	int v6;              // esi
	unsigned __int8* v7; // eax
	unsigned int v8;     // ebx
	unsigned __int8 v9;  // cl
	unsigned __int8 v10; // al
	char v11;            // al
	unsigned int v12;    // ecx
	char* v13;           // edi
	char* v14;           // esi
	char v15;            // cl
	int v16;             // edi
	BYTE v17;            // al
	unsigned __int8 v18; // dl
	unsigned __int8 v19; // di
	int v20;             // edi
	char v21;            // dl
	unsigned int v22;    // ecx
	int v23;             // eax
	char* v24;           // [esp-14h] [ebp-150h]
	int v25;             // [esp-10h] [ebp-14Ch]
	char v26;            // [esp+12h] [ebp-12Ah]
	unsigned __int8 v27; // [esp+13h] [ebp-129h]
	int tolen;           // [esp+14h] [ebp-128h]
	int v29;             // [esp+18h] [ebp-124h]
	u_long argp;         // [esp+1Ch] [ebp-120h]
	BYTE v31;
	int v32;            // [esp+24h] [ebp-118h]
	int v33;            // [esp+28h] [ebp-114h]
	struct sockaddr to; // [esp+2Ch] [ebp-110h]
	char buf[256];      // [esp+3Ch] [ebp-100h]

	v2 = *(_DWORD*)&byte_5D4594[4 * a1 + 3843788];
	tolen = 16;
	v29 = v2;
	v26 = 1;
	if (a1 >= 0x80)
		return -3;
	if (!v2)
		return -3;
	v32 = a2 & 1;
	if (!(a2 & 1)) {
		argp = 1;
		while (1) {
		LABEL_10:
			v25 = *(_DWORD*)(v2 + 44) - *(_DWORD*)(v2 + 36);
			v24 = *(char**)(v2 + 36);
			v4 = *(_DWORD*)v2;
			v33 = 1;
			v5 = sub_552020(v4, v24, v25, 0, &to, &tolen);
			v6 = v5;
			if (v5 == -1)
				goto LABEL_8;
			sub_553FC0(v5, 1);
			if (v6 < 3)
				goto LABEL_48;
			v7 = *(unsigned __int8**)(v2 + 40);
			*(_DWORD*)(v2 + 36) += v6;
			v8 = *v7;
			v9 = v7[1];
			v10 = v7[2];
			v31 = v9;
			v27 = v10;
			if (v10 == 12) {
				if (!sub_43AF70()) {
					v6 = sub_554040(*(_DWORD*)(v2 + 40), *(_DWORD*)(v2 + 36) - *(_DWORD*)(v2 + 40),
							buf);
					if (v6 > 0) {
						v6 = sendto(*(_DWORD*)v2, buf, v6, 0, &to, tolen);
						sub_553F40(v6, 1);
					}
				}
				goto LABEL_48;
			}
			if (v10 < 0xEu || v10 > 0x14u) {
				if (v8 == 255) {
					if (v26 != 1)
						goto LABEL_48;
				} else {
					v26 = 0;
					if (!sub_551E00(v8 & 0x7F, (int)&to))
						goto LABEL_48;
					v10 = v27;
					v9 = v31;
					v26 = 1;
				}
				if (*(int*)(v2 + 20) == -1)
					v29 = *(_DWORD*)&byte_5D4594[4 * (v8 & 0x7F) + 3843788];
				if ((v8 & 0x80u) == 0) {
					if (!v29)
						goto LABEL_48;
					if (v9 == *(_BYTE*)(v29 + 113))
						goto LABEL_42;
					v19 = v31;
					sub_5551F0(v8, v31, 1);
					sub_555360(v8, v19, 1);
					*(_BYTE*)(v29 + 113) = v31;
					if (sub_551EB0(a1, v8, v19, *(_DWORD*)(v2 + 40),
						       *(_DWORD*)(v2 + 36) - *(_DWORD*)(v2 + 40)) == 1)
						v20 = 0;
					else
						v20 = v33;
					buf[0] = 38;
					buf[1] = *(_BYTE*)(v29 + 113);
					(*(void(__cdecl**)(unsigned int, char*, int, _DWORD))(v2 + 144))(
					    v8, buf, 2, *(_DWORD*)(v29 + 120));
					if (!v20)
						goto LABEL_48;
				} else {
					if (v8 == 255) {
						if (!v10) {
							v11 = tolen;
							v12 = (unsigned int)tolen >> 2;
							qmemcpy(buf, &to, 4 * ((unsigned int)tolen >> 2));
							v14 = (char*)&to + 4 * v12;
							v13 = &buf[4 * v12];
							v15 = v11;
							goto LABEL_29;
						}
						goto LABEL_42;
					}
					**(_BYTE**)(v2 + 40) &= 0x7Fu;
					v8 = **(unsigned __int8**)(v2 + 40);
					if (!v29)
						goto LABEL_48;
					v16 = *(_DWORD*)(v29 + 48);
					v17 = *(_BYTE*)(v16 + 1);
					if (v17 != v9)
						goto LABEL_48;
					v18 = v31;
					*(BYTE*)(v16 + 1) = v17 + 1;
					if (sub_551EB0(a1, v8, v18, *(_DWORD*)(v2 + 40),
						       *(_DWORD*)(v2 + 36) - *(_DWORD*)(v2 + 40)) == 1)
						goto LABEL_48;
				}
				v10 = v27;
			} else {
				v26 = 1;
			}
		LABEL_42:
			if (v10 < 0x20u) {
				v21 = tolen;
				v22 = (unsigned int)tolen >> 2;
				qmemcpy(buf, &to, 4 * ((unsigned int)tolen >> 2));
				v14 = (char*)&to + 4 * v22;
				v13 = &buf[4 * v22];
				v15 = v21;
			LABEL_29:
				qmemcpy(v13, v14, v15 & 3);
				v6 = sub_553210(a1, *(unsigned __int8**)(v2 + 40),
						*(_DWORD*)(v2 + 36) - *(_DWORD*)(v2 + 40), (int)buf);
				if (v6 > 0) {
					v6 = sub_551F90(*(_DWORD*)v2, buf, v6, 0, &to, tolen);
					sub_553F40(v6, 1);
				}
				goto LABEL_48;
			}
			if (v29 && !(a2 & 2))
				(*(void(__cdecl**)(unsigned int, int, int, _DWORD))(v2 + 144))(
				    v8, *(_DWORD*)(v2 + 40) + 2, v6 - 2, *(_DWORD*)(v29 + 120));
		LABEL_48:
			v23 = *(_DWORD*)(v2 + 32);
			*(_DWORD*)(v2 + 40) = v23;
			*(_DWORD*)(v2 + 36) = v23;
			argp = 0;
			if (v32 && !(a2 & 4)) {
				if (ioctlsocket(*(_DWORD*)v2, 1074030207, &argp) == -1)
					goto LABEL_8;
				if (argp)
					continue;
			}
			return v6;
		}
	}
	result = ioctlsocket(*(_DWORD*)v2, 1074030207, &argp);
	if (result != -1) {
		if (argp)
			goto LABEL_10;
	LABEL_8:
		result = -1;
	}
	return result;
}

//----- (00552E70) --------------------------------------------------------
int __cdecl sub_552E70(unsigned int a1) {
	int v1;              // ecx
	unsigned int v3;     // esi
	unsigned int v4;     // edi
	unsigned int v5;     // ebp
	unsigned __int8* v6; // ebx
	_DWORD* v7;          // eax
	int v8;              // ecx
	char v9[5];          // [esp+0h] [ebp-8h]

	v1 = *(_DWORD*)&byte_5D4594[4 * a1 + 3843788];
	if (a1 >= 0x80)
		return -3;
	if (!v1)
		return -3;
	if (*(int*)(v1 + 20) == -1) {
		v3 = 0;
		v4 = 128;
		v5 = a1;
	} else {
		v5 = *(_DWORD*)(v1 + 20);
		v3 = a1;
		v4 = a1 + 1;
	}
	v9[0] = 6;
	if (v3 < v4) {
		v6 = &byte_5D4594[4 * v3 + 3843788];
		do {
			v7 = *(_DWORD**)v6;
			if (*(_DWORD*)v6) {
				if (v7[5] == v5) {
					v8 = dword_5d4594_2495920;
					v7[22] = dword_5d4594_2495920;
					v7[23] = dword_5d4594_2495920;
					*(_DWORD*)&v9[1] = v8;
					sub_552640(v3, v9, 5, 2);
				}
			}
			++v3;
			v6 += 4;
		} while (v3 < v4);
	}
	return 0;
}

//----- (00552F20) --------------------------------------------------------
int __cdecl sub_552F20(unsigned int a1) {
	int v1;              // ecx
	unsigned int v3;     // esi
	unsigned int v4;     // edi
	unsigned int v5;     // ebp
	unsigned __int8* v6; // ebx
	_DWORD* v7;          // eax
	int v8;              // edx
	char v9[256];        // [esp+0h] [ebp-100h]

	v1 = *(_DWORD*)&byte_5D4594[4 * a1 + 3843788];
	if (a1 >= 0x80)
		return -3;
	if (!v1)
		return -3;
	if (*(int*)(v1 + 20) == -1) {
		v3 = 0;
		v4 = 128;
		v5 = a1;
	} else {
		v5 = *(_DWORD*)(v1 + 20);
		v3 = a1;
		v4 = a1 + 1;
	}
	v9[0] = 5;
	if (v3 < v4) {
		v6 = &byte_5D4594[4 * v3 + 3843788];
		do {
			v7 = *(_DWORD**)v6;
			if (*(_DWORD*)v6) {
				if (v7[5] == v5) {
					v8 = v7[25] + 1;
					v7[25] = v8;
					v7[26] = dword_5d4594_2495920;
					*(_DWORD*)&v9[1] = v8;
					sub_552640(v3, v9, 256, 2);
				}
			}
			++v3;
			v6 += 4;
		} while (v3 < v4);
	}
	return 0;
}

//----- (00552FD0) --------------------------------------------------------
u_long __cdecl sub_552FD0(u_long argp) {
	u_long result; // eax

	if (ioctlsocket(**(_DWORD**)&byte_5D4594[4 * argp + 3843788], 1074030207, &argp))
		result = -1;
	else
		result = argp;
	return result;
}

//----- (00553000) --------------------------------------------------------
void* __cdecl sub_553000(size_t* a1) {
	void* result;  // eax
	void* v2;      // esi
	HANDLE v3;     // eax
	HANDLE v4;     // eax
	void* v5;      // edi
	signed int v6; // eax
	char* v7;      // eax
	void* v8;      // edi
	int v9;        // eax
	size_t v10;    // eax
	size_t v11;    // ebx

	result = nox_malloc(0xA4u);
	v2 = result;
	if (result) {
		memset(result, 0, 0xA4u);
		v3 = CreateMutexA(0, 0, 0);
		*((_DWORD*)v2 + 32) = v3;
		if (!v3) {
			free(v2);
			return 0;
		}
		v4 = CreateMutexA(0, 0, 0);
		*((_DWORD*)v2 + 31) = v4;
		if (!v4) {
			free(v2);
			return 0;
		}
		if ((int)a1[3] > 0) {
			v5 = nox_malloc(a1[3]);
			*((_DWORD*)v2 + 30) = v5;
			if (!v5) {
				free(v2);
				return 0;
			}
			memset(v5, 0, a1[3]);
		}
		v6 = a1[5];
		if (v6 > 0) {
			LOBYTE(v6) = v6 & 0xFC;
			a1[5] = v6;
		} else {
			a1[5] = 1024;
		}
		v7 = (char*)nox_malloc(a1[5] + 2);
		*((_DWORD*)v2 + 8) = v7;
		if (v7) {
			*((_DWORD*)v2 + 10) = v7;
			*((_DWORD*)v2 + 9) = v7;
			*((_DWORD*)v2 + 11) = &v7[a1[5] + 2];
			v8 = nox_malloc(a1[5] + 2);
			*((_DWORD*)v2 + 12) = v8;
			if (v8) {
				memset(v8, 0, a1[5] + 2);
				**((_BYTE**)v2 + 12) = -1;
				v9 = *((_DWORD*)v2 + 12);
				*((_DWORD*)v2 + 13) = v9 + 2;
				*((_DWORD*)v2 + 14) = v9 + 2;
				*((_DWORD*)v2 + 15) = v9 + a1[5] + 2;
				*((_DWORD*)v2 + 20) = a1[4];
				v10 = a1[8];
				if (v10)
					*((_DWORD*)v2 + 35) = v10;
				else
					*((_DWORD*)v2 + 35) = sub_553D60;
				v11 = a1[9];
				if (v11)
					*((_DWORD*)v2 + 36) = v11;
				else
					*((_DWORD*)v2 + 36) = sub_553D70;
				*((_BYTE*)v2 + 113) = -1;
				*((_BYTE*)v2 + 148) = 0;
				result = v2;
			} else {
				free(*((LPVOID*)v2 + 8));
				free(*((LPVOID*)v2 + 30));
				free(v2);
				result = 0;
			}
		} else {
			free(*((LPVOID*)v2 + 30));
			free(v2);
			result = 0;
		}
	}
	return result;
}

//----- (005531C0) --------------------------------------------------------
void __cdecl sub_5531C0(LPVOID lpMem) {
	if (*((_DWORD*)lpMem + 30))
		free(*((LPVOID*)lpMem + 30));
	free(*((LPVOID*)lpMem + 8));
	free(*((LPVOID*)lpMem + 12));
	CloseHandle(*((HANDLE*)lpMem + 32));
	CloseHandle(*((HANDLE*)lpMem + 31));
	free(lpMem);
}

//----- (00553210) --------------------------------------------------------
int __cdecl sub_553210(unsigned int a1, unsigned __int8* a2, int a3, int a4) {
	int v4;                 // ebp
	unsigned __int8* v5;    // ecx
	unsigned int v6;        // esi
	int v7;                 // ebx
	int v8;                 // ecx
	unsigned __int8* v9;    // edi
	int v10;                // eax
	int v11;                // eax
	_BYTE* v12;             // edx
	_BYTE* v13;             // edi
	_BYTE v14;              // al
	_BYTE v15;              // dl
	int result;             // eax
	int v17;                // eax
	int v18;                // edx
	int v19;                // ecx
	char v20;               // cl
	int v21;                // ecx
	int v22;                // edi
	int v23;                // eax
	int v24;                // edx
	int v25;                // esi
	int v26;                // edx
	int v27;                // edi
	unsigned __int8* v28;   // eax
	int v29;                // ebx
	char v30;               // dl
	int v31;                // edi
	int v32;                // eax
	char* v33;              // eax
	char v34;               // dl
	char* v35;              // esi
	const wchar_t* v36;     // ecx
	DWORD v37;              // eax
	unsigned __int8* v38;   // edi
	int v39;                // esi
	int v40;                // eax
	unsigned __int8* v41;   // ecx
	unsigned __int8 v42;    // dl
	int v43;                // edi
	char v44;               // dl
	char* v45;              // eax
	int v46;                // esi
	char* i;                // esi
	int* v48;               // esi
	const wchar_t* v49;     // edi
	_DWORD* v50;            // eax
	int* j;                 // ebx
	char v52;               // al
	int v53;                // eax
	int v54;                // ecx
	unsigned __int8* v55;   // edx
	char v56;               // dl
	unsigned int v57;       // edx
	unsigned __int8* v58;   // ecx
	int v59;                // eax
	int v60;                // eax
	void* v61;              // eax
	int v62;                // ecx
	char v63;               // al
	char v64;               // al
	char v65;               // bl
	int v66;                // edx
	char v67;               // al
	int v68;                // eax
	int* v69;               // eax
	int* v70;               // edi
	int v71;                // eax
	int v72;                // [esp+10h] [ebp-40h]
	unsigned int v73;       // [esp+14h] [ebp-3Ch]
	unsigned __int8 v74[8]; // [esp+18h] [ebp-38h]
	int v75;                // [esp+20h] [ebp-30h]
	int v76;                // [esp+24h] [ebp-2Ch]
	char v77[40];           // [esp+28h] [ebp-28h]
	char* v78;              // [esp+54h] [ebp+4h]

	v4 = a4;
	v5 = &a2[a3];
	// dhexdump(a2, a3);
	v6 = *a2;
	LOBYTE(a3) = a2[1];
	v7 = *(_DWORD*)&byte_5D4594[4 * a1 + 3843788];
	v73 = (unsigned int)v5;
	v8 = *(_DWORD*)&byte_5D4594[4 * v6 + 3843788];
	*(_DWORD*)v74 = *(_DWORD*)a4;
	v9 = a2 + 2;
	v72 = v8;
	*(_DWORD*)&v74[4] = *(_DWORD*)(a4 + 4);
	v75 = *(_DWORD*)(a4 + 8);
	v76 = *(_DWORD*)(a4 + 12);
	if ((unsigned int)(a2 + 2) < v73) {
		while (2) {
			v10 = *v9++;
			switch (v10) {
			case 0:
				if (nox_common_gameFlags_check_40A5C0(1) && nox_common_gameFlags_check_40A5C0(8))
					return 0;
				v56 = a3;
				*(_BYTE*)v4 = 0;
				*(_BYTE*)(v4 + 1) = v56;
				if (*(_DWORD*)(v7 + 84) >= sub_409FA0() + (unsigned int)byte_5D4594[2500076] - 1)
					goto LABEL_113;
				v57 = 0;
				v58 = &byte_5D4594[3843788];
				while (1) {
					v59 = *(_DWORD*)v58;
					if (!*(_DWORD*)v58)
						break;
					if (*(_WORD*)&v74[2] == *(_WORD*)(v59 + 6) &&
					    *(_DWORD*)&v74[4] == *(_DWORD*)(v59 + 8)) {
						printf("%d %d\n", *(_WORD*)&v74[2], *(_DWORD*)&v74[4]);
						*(_BYTE*)(v4 + 2) = 4;
						return 3;
					}
					v58 += 4;
					++v57;
					if ((int)v58 >= (int)&byte_5D4594[3844300])
						goto LABEL_108;
				}
				v6 = v57;
			LABEL_108:
				if (v6 == -1) {
					*(_BYTE*)(v4 + 2) = 2;
					result = 3;
				} else {
					memset(v77, 0, sizeof(v77));
					v60 = *(_DWORD*)(v7 + 60) - *(_DWORD*)(v7 + 48);
					*(_DWORD*)&v77[12] = 4;
					*(_DWORD*)&v77[20] = v60;
					v61 = sub_553000((size_t*)v77);
					*(_DWORD*)&byte_5D4594[4 * v6 + 3843788] = v61;
					if (v61) {
						++*(_DWORD*)(v7 + 84);
						**(_BYTE**)(*(_DWORD*)&byte_5D4594[4 * v6 + 3843788] + 48) = a1;
						v62 = *(_DWORD*)(*(_DWORD*)&byte_5D4594[4 * v6 + 3843788] + 48);
						v63 = *(_BYTE*)(v62 + 1);
						if (v63 == (_BYTE)a3)
							*(_BYTE*)(v62 + 1) = v63 + 1;
						*(_DWORD*)(*(_DWORD*)&byte_5D4594[4 * v6 + 3843788] + 20) = a1;
						**(_DWORD**)&byte_5D4594[4 * v6 + 3843788] = *(_DWORD*)v7;
						*(_DWORD*)(*(_DWORD*)&byte_5D4594[4 * v6 + 3843788] + 140) =
						    *(_DWORD*)(v7 + 140);
						*(_DWORD*)(*(_DWORD*)&byte_5D4594[4 * v6 + 3843788] + 144) =
						    *(_DWORD*)(v7 + 144);
						memset(&byte_5D4594[32 * a1 + 2508788], 0, 0x20u);
						*(_DWORD*)&byte_5D4594[32 * a1 + 2508816] = 1;
						v64 = nox_common_randomInt_415FA0(1, 255);
						v65 = v64;
						*(_BYTE*)(*(_DWORD*)&byte_5D4594[4 * v6 + 3843788] + 148) = 0;
						v66 = *(_DWORD*)&byte_5D4594[4 * v6 + 3843788] + 4;
						*(_QWORD*)v66 = *(_QWORD*)v74;
						*(_DWORD*)(v66 + 8) = v75;
						*(_DWORD*)(v66 + 12) = v76;
						LOBYTE(v66) = a3;
						*(_BYTE*)v4 = 31;
						*(_BYTE*)(v4 + 1) = v66;
						*(_BYTE*)(v4 + 2) = 1;
						*(_DWORD*)(v4 + 3) = v6;
						*(_BYTE*)(v4 + 7) = v64;
						v67 = sub_552640(v6, (const void*)v4, 8, 3);
						*(_BYTE*)(*(_DWORD*)&byte_5D4594[4 * v6 + 3843788] + 148) = v65;
						*(_DWORD*)(*(_DWORD*)&byte_5D4594[4 * v6 + 3843788] + 152) = 1;
						*(_BYTE*)(*(_DWORD*)&byte_5D4594[4 * v6 + 3843788] + 156) = v67;
						*(_DWORD*)(*(_DWORD*)&byte_5D4594[4 * v6 + 3843788] + 160) =
						    *(_DWORD*)&byte_5D4594[2598000];
						result = 0;
					} else {
					LABEL_113:
						*(_BYTE*)(v4 + 2) = 2;
						result = 3;
					}
				}
				return result;
			case 1:
				v11 = *(_DWORD*)v9;
				v12 = *(_BYTE**)(v7 + 48);
				v13 = v9 + 4;
				*(_DWORD*)(v7 + 20) = v11;
				*v12 = v11;
				LOBYTE(v12) = *v13;
				v9 = v13 + 1;
				*(_BYTE*)(v7 + 148) = (_BYTE)v12;
				dword_5d4594_3844304 = 1;
				goto LABEL_9;
			case 2:
				*(_DWORD*)(v7 + 20) = -18;
				dword_5d4594_3844304 = 1;
				goto LABEL_9;
			case 3:
				*(_DWORD*)(v7 + 20) = -12;
				dword_5d4594_3844304 = 1;
				goto LABEL_9;
			case 4:
				*(_DWORD*)(v7 + 20) = -13;
				dword_5d4594_3844304 = 1;
				goto LABEL_9;
			case 5:
				result = 7;
				v30 = **(_BYTE**)(v7 + 48);
				*(_BYTE*)(v4 + 2) = 7;
				*(_BYTE*)v4 = v30;
				*(_DWORD*)(v4 + 3) = *(_DWORD*)v9;
				return result;
			case 6:
				v17 = *(_DWORD*)&byte_5D4594[4 * v6 + 3843788];
				LOBYTE(a2) = 37;
				(*(void(__cdecl**)(unsigned int, unsigned __int8**, int, _DWORD))(v7 + 144))(
				    v6, &a2, 1, *(_DWORD*)(v17 + 120));
				if (*(int*)(v7 + 20) == -1) {
					*(_BYTE*)v4 = *(_BYTE*)(v72 + 20);
					v18 = *(_DWORD*)(v72 + 48);
				} else {
					*(_BYTE*)v4 = *(_BYTE*)(v7 + 20);
					v18 = *(_DWORD*)(v7 + 48);
				}
				*(_BYTE*)(v4 + 1) = *(_BYTE*)(v18 + 1);
				result = 7;
				*(_DWORD*)&byte_5D4594[32 * v6 + 2508792] = *(_DWORD*)v9;
				*(_BYTE*)(v4 + 2) = 8;
				*(_DWORD*)(v4 + 3) = *(_DWORD*)v9;
				return result;
			case 7:
				if (!*(_DWORD*)(v8 + 100))
					return 0;
				v31 = dword_5d4594_2495920 - *(_DWORD*)(v8 + 104) - *(_DWORD*)(v8 + 96);
				if (v31 >= 1)
					v32 = 256000 / v31;
				else
					v32 = -1;
				*(_BYTE*)v4 = 35;
				*(_DWORD*)(v4 + 1) = v32;
				if (*(int*)(v7 + 20) == -1)
					(*(void(__cdecl**)(unsigned int, int, int, _DWORD))(v7 + 144))(
					    v6, v4, 5, *(_DWORD*)(v8 + 120));
				else
					(*(void(__cdecl**)(unsigned int, int, int, _DWORD))(v7 + 144))(
					    v6, v4, 5, *(_DWORD*)(v7 + 120));
				return 0;
			case 8:
				if (*(_DWORD*)v9 != *(_DWORD*)(v8 + 88))
					return 0;
				*(_DWORD*)(v8 + 96) = dword_5d4594_2495920 - *(_DWORD*)(v8 + 92);
				*(_BYTE*)v4 = 36;
				*(_DWORD*)(v4 + 1) = *(_DWORD*)(v8 + 96);
				if (*(int*)(v7 + 20) == -1)
					v19 = *(_DWORD*)(v8 + 120);
				else
					v19 = *(_DWORD*)(v7 + 120);
				(*(void(__cdecl**)(unsigned int, int, int, int))(v7 + 144))(v6, v4, 5, v19);
				*(_BYTE*)v4 = **(_BYTE**)(v7 + 48);
				v20 = *(_BYTE*)(*(_DWORD*)(v72 + 48) + 1);
				*(_BYTE*)(v4 + 2) = 9;
				*(_BYTE*)(v4 + 1) = v20;
				*(_DWORD*)(v4 + 3) = dword_5d4594_2495920;
				return 7;
			case 9:
				v21 = 32 * v6;
				v22 = *(_DWORD*)v9 - *(_DWORD*)&byte_5D4594[32 * v6 + 2508792];
				if (v22 <= 0 || v22 >= 1000)
					return 0;
				v23 = *(_DWORD*)&byte_5D4594[32 * v6 + 2508788];
				v24 = v23 + 8 * v6;
				v25 = 5;
				*(_DWORD*)&byte_5D4594[4 * v24 + 2508796] = v22;
				v26 = (v23 + 1) % 5;
				v27 = v26;
				if (!v26) {
					v28 = &byte_5D4594[v21 + 2508796];
					do {
						v29 = *(_DWORD*)v28;
						v28 += 4;
						v26 += v29;
						--v25;
					} while (v25);
					*(_DWORD*)&byte_5D4594[v21 + 2508816] = v26 / 5;
				}
				*(_DWORD*)&byte_5D4594[v21 + 2508788] = v27;
				return 0;
			case 10:
				if (v6 == 255)
					return 0;
				v68 = *(_DWORD*)&byte_5D4594[4 * v6 + 3843788];
				if (*(_DWORD*)(v68 + 152) == 1)
					return 0;
				LOBYTE(a2) = 34;
				(*(void(__cdecl**)(unsigned int, unsigned __int8**, int, _DWORD))(v7 + 144))(
				    v6, &a2, 1, *(_DWORD*)(v68 + 120));
				memset(&byte_5D4594[32 * a1 + 2508788], 0, 0x20u);
				v69 = sub_5541D0(v6);
				v70 = v69;
				if (v69) {
					sub_425920((_DWORD**)v69);
					free(v70);
					--byte_5D4594[2500076];
				}
				sub_5545B0(v6);
				return 0;
			case 11:
				v71 = *(_DWORD*)&byte_5D4594[4 * v6 + 3843788];
				LOBYTE(a2) = 33;
				(*(void(__cdecl**)(unsigned int, unsigned __int8**, int, _DWORD))(v7 + 144))(
				    v6, &a2, 1, *(_DWORD*)(v71 + 120));
				sub_554A50(a1);
				return 0;
			case 14:
				v43 = 0;
				v78 = sub_416640();
				sub_416590(0);
				v44 = a3;
				a4 = 0;
				*(_BYTE*)v4 = 0;
				*(_BYTE*)(v4 + 1) = v44;
				if (sub_43AF70())
					goto LABEL_50;
				v45 = sub_416EA0();
				if (!v45)
					goto LABEL_50;
				break;
			case 17:
				v33 = sub_416640();
				v34 = a3;
				v35 = v33;
				v36 = (const wchar_t*)(a2 + 4);
				*(_BYTE*)v4 = 0;
				*(_BYTE*)(v4 + 1) = v34;
				if (nox_wcscmp(v36, (const wchar_t*)v33 + 39)) {
					*(_BYTE*)(v4 + 2) = 19;
					*(_BYTE*)(v4 + 3) = 6;
					return 4;
				}
				if (*(short*)(v35 + 105) != -1)
					goto LABEL_97;
				goto LABEL_96;
			case 18:
				v37 = nox_get_ticks();
				v38 = a2;
				v39 = v37 - *((_DWORD*)a2 + 1);
				v40 = sub_553D30((int)v74);
				if (v40 < 0)
					return 0;
				v41 = &byte_5D4594[68 * v40 + 2500089];
				if (v38[3] != byte_5D4594[68 * v40 + 2500089])
					return 0;
				*(_DWORD*)&byte_5D4594[4 * (byte_5D4594[68 * v40 + 2500089] + 17 * v40) + 2500108] =
				    v39;
				v42 = *v41 + 1;
				*v41 = v42;
				if (v42 >= 0xAu)
					return 0;
				return sub_552340(v40, v4);
			case 31:
				v14 = *v9;
				v15 = *(_BYTE*)(v8 + 113);
				++v9;
				LOBYTE(a4) = v14;
				printf("foo 0x%x 0x%x\n", v14, v15);
				if (v14 != v15) {
					sub_5551F0(v6, a4, 1);
					sub_555360(v6, a4, 1);
					*(_BYTE*)(v72 + 113) = a4;
					*(_BYTE*)v4 = 38;
					*(_BYTE*)(v4 + 1) = *(_BYTE*)(v72 + 113);
					(*(void(__cdecl**)(unsigned int, int, int, _DWORD))(v7 + 144))(
					    v6, v4, 2, *(_DWORD*)(v72 + 120));
					v8 = v72;
				}
			LABEL_9:
				if ((unsigned int)v9 < v73)
					continue;
				return 0;
			default:
				return 0;
			}
			break;
		}
		do {
			if (v45[2135] == a2[98]) {
				if (!strcmp(v45 + 2112, (const char*)a2 + 56)) {
					*(_BYTE*)(v4 + 2) = 19;
					*(_BYTE*)(v4 + 3) = 12;
					return 4;
				}
				v43 = 0;
			}
			v45 = sub_416EE0((int)v45);
		} while (v45);
	LABEL_50:
		if (*((_DWORD*)a2 + 20) != 66458) {
			*(_BYTE*)(v4 + 2) = 19;
			*(_BYTE*)(v4 + 3) = 13;
			return 4;
		}
		if (*(_DWORD*)(v7 + 84) >= (unsigned int)(sub_409FA0() - 1))
			a4 = 1;
		if (!sub_40A740())
			goto LABEL_67;
		v46 = sub_425BF0();
		if (!*((_DWORD*)a2 + 21)) {
			if (v46 >= (unsigned __int8)v78[53])
				goto LABEL_80;
			goto LABEL_67;
		}
		if (sub_418AE0(*((_DWORD*)a2 + 21))) {
			if (v46 > 0) {
			LABEL_66:
				v43 = 1;
				goto LABEL_67;
			}
		} else {
			if ((unsigned __int8)sub_417DE0() >= (unsigned __int8)v78[52]) {
				if (v46 >= (unsigned __int8)v78[53])
					goto LABEL_80;
				goto LABEL_67;
			}
			if (v46 > 0)
				goto LABEL_66;
		}
	LABEL_67:
		if (!a4)
			goto LABEL_73;
		if (v43 && *(_DWORD*)(v78 + 54)) {
			for (i = sub_425C40(); i; i = sub_425C70((int)i)) {
				if (!sub_5541D0((unsigned __int8)i[2064] + 1)) {
					sub_4DEAB0((unsigned __int8)i[2064], 4);
					v50 = nox_malloc(0x10u);
					v50[3] = (unsigned __int8)i[2064] + 1;
					sub_4258E0((int)&byte_5D4594[2495908], v50);
					++byte_5D4594[2500076];
					*(_BYTE*)(v4 + 2) = 21;
					return 3;
				}
			}
		LABEL_73:
			if (v78[100] & 0x10) {
				v48 = sub_4168E0();
				if (!v48) {
					*(_BYTE*)(v4 + 2) = 19;
					*(_BYTE*)(v4 + 3) = 4;
					return 4;
				}
				v49 = (const wchar_t*)(a2 + 4);
				while (_nox_wcsicmp((const wchar_t*)v48 + 6, v49)) {
					v48 = sub_4168F0(v48);
					if (!v48) {
						*(_BYTE*)(v4 + 2) = 19;
						*(_BYTE*)(v4 + 3) = 4;
						return 4;
					}
				}
			} else {
				for (j = sub_416900(); j; j = sub_416910(j)) {
					if (!strcmp((const char*)j + 72, "0")) {
						if (!_nox_wcsicmp((const wchar_t*)j + 6, (const wchar_t*)a2 + 2))
							goto LABEL_92;
					} else if (!_strcmpi((const char*)j + 72, (const char*)a2 + 56)) {
					LABEL_92:
						*(_BYTE*)(v4 + 2) = 19;
						*(_BYTE*)(v4 + 3) = 5;
						return 4;
					}
				}
			}
			v35 = v78;
			v52 = v78[100];
			if (v52 && (unsigned __int8)(1 << a2[54]) & (unsigned __int8)v52) {
				*(_BYTE*)(v4 + 2) = 19;
				*(_BYTE*)(v4 + 3) = 7;
				return 4;
			}
			if (v52 & 0x20) {
				*(_BYTE*)(v4 + 2) = 15;
				return 3;
			}
			if (*(short*)(v78 + 105) == -1) {
			LABEL_96:
				if (*(short*)(v35 + 107) == -1) {
				LABEL_99:
					*(_BYTE*)(v4 + 2) = 20;
					return 3;
				}
			}
		LABEL_97:
			v53 = sub_553D10();
			if (v53 >= 0) {
				v54 = 68 * v53;
				*(_DWORD*)&byte_5D4594[v54 + 2500084] = 1;
				byte_5D4594[v54 + 2500089] = 0;
				byte_5D4594[v54 + 2500088] = 0;
				v55 = &byte_5D4594[68 * v53 + 2500092];
				*(_QWORD*)v55 = *(_QWORD*)v74;
				*((_DWORD*)v55 + 2) = v75;
				*((_DWORD*)v55 + 3) = v76;
				return sub_552340(v53, v4);
			}
			goto LABEL_99;
		}
	LABEL_80:
		*(_BYTE*)(v4 + 2) = 19;
		*(_BYTE*)(v4 + 3) = 11;
		return 4;
	}
	return 0;
}

//----- (00553D10) --------------------------------------------------------
int sub_553D10() {
	int result;          // eax
	unsigned __int8* v1; // ecx

	result = 0;
	v1 = &byte_5D4594[2500084];
	while (*(_DWORD*)v1) {
		v1 += 68;
		++result;
		if ((int)v1 >= (int)&byte_5D4594[2508788])
			return -1;
	}
	return result;
}

//----- (00553D30) --------------------------------------------------------
int __cdecl sub_553D30(int a1) {
	int result;          // eax
	unsigned __int8* v2; // ecx

	result = 0;
	v2 = &byte_5D4594[2500094];
	while (*(_DWORD*)(v2 + 2) != *(_DWORD*)(a1 + 4) || *(_WORD*)v2 != *(_WORD*)(a1 + 2)) {
		v2 += 68;
		++result;
		if ((int)v2 >= (int)&byte_5D4594[2508798])
			return -1;
	}
	return result;
}

//----- (00553D60) --------------------------------------------------------
int sub_553D60() { return 0; }

//----- (00553D70) --------------------------------------------------------
int sub_553D70() { return 0; }

//----- (00553D80) --------------------------------------------------------
int sub_553D80() { return *(_DWORD*)&byte_5D4594[2495944]; }

//----- (00553D90) --------------------------------------------------------
int sub_553D90() { return *(_DWORD*)&byte_5D4594[2495952]; }

//----- (00553DA0) --------------------------------------------------------
int sub_553DA0() { return *(_DWORD*)&byte_5D4594[2495948]; }

//----- (00553DB0) --------------------------------------------------------
int sub_553DB0() { return *(_DWORD*)&byte_5D4594[2495956]; }

//----- (00553DC0) --------------------------------------------------------
__int64 __cdecl sub_553DC0(int a1) {
	int v1;          // eax
	unsigned int v2; // ecx
	int v3;          // edx

	v1 = *(_DWORD*)&byte_5D4594[2496472];
	v2 = 0;
	v3 = 127;
	do {
		v2 += *(_DWORD*)&byte_5D4594[4 * v1 + 2495960];
		v1 = (v1 + 1) % 128;
		--v3;
	} while (v3);
	return (__int64)((double)v2 / (128.0 / (double)a1));
}

//----- (00553E10) --------------------------------------------------------
unsigned int __cdecl sub_553E10(int a1) {
	int v1;          // eax
	unsigned int v2; // ecx
	int v3;          // edx

	v1 = *(_DWORD*)&byte_5D4594[2497504];
	v2 = 0;
	v3 = 127;
	do {
		v2 += *(_DWORD*)&byte_5D4594[4 * v1 + 2496992];
		v1 = (v1 + 1) % 128;
		--v3;
	} while (v3);
	return v2 / (128 / a1);
}

//----- (00553E50) --------------------------------------------------------
unsigned int __cdecl sub_553E50(int a1) {
	int v1;          // eax
	unsigned int v2; // ecx
	int v3;          // edx

	v1 = *(_DWORD*)&byte_5D4594[2496988];
	v2 = 0;
	v3 = 127;
	do {
		v2 += *(_DWORD*)&byte_5D4594[4 * v1 + 2496476];
		v1 = (v1 + 1) % 128;
		--v3;
	} while (v3);
	return v2 / (128 / a1);
}

//----- (00553E90) --------------------------------------------------------
unsigned int __cdecl sub_553E90(int a1) {
	int v1;          // eax
	unsigned int v2; // ecx
	int v3;          // edx

	v1 = *(_DWORD*)&byte_5D4594[2498020];
	v2 = 0;
	v3 = 127;
	do {
		v2 += *(_DWORD*)&byte_5D4594[4 * v1 + 2497508];
		v1 = (v1 + 1) % 128;
		--v3;
	} while (v3);
	return v2 / (128 / a1);
}

//----- (00553ED0) --------------------------------------------------------
int __cdecl sub_553ED0(int a3) {
	unsigned __int64 v1; // rax
	__int64 v2;          // rdi
	int result;          // eax
	int v4;              // edi

	v1 = sub_416BB0();
	LODWORD(v2) = *(_DWORD*)&byte_5D4594[8 * a3 + 2499052];
	HIDWORD(v2) = *(_DWORD*)&byte_5D4594[8 * a3 + 2499056];
	if (v1 < v2 + 1000)
		return *(_DWORD*)&byte_5D4594[4 * a3 + 2498536];
	v4 = *(_DWORD*)&byte_5D4594[4 * a3 + 2498024];
	*(_DWORD*)&byte_5D4594[8 * a3 + 2499052] = v1;
	LODWORD(v1) = v4;
	*(_DWORD*)&byte_5D4594[4 * a3 + 2498536] = v4;
	*(_DWORD*)&byte_5D4594[4 * a3 + 2498024] = 0;
	*(_DWORD*)&byte_5D4594[8 * a3 + 2499056] = HIDWORD(v1);
	return result;
}

//----- (00553F40) --------------------------------------------------------
void __cdecl sub_553F40(int a1, int a2) {
	*(_DWORD*)&byte_5D4594[2495952] += a1;
	*(_DWORD*)&byte_5D4594[2495956] += a2;
	*(_DWORD*)&byte_5D4594[4 * *(_DWORD*)&byte_5D4594[2497504] + 2496992] = a1;
	*(_DWORD*)&byte_5D4594[4 * *(_DWORD*)&byte_5D4594[2498020] + 2497508] = a2;
	*(_DWORD*)&byte_5D4594[2497504] = (*(_DWORD*)&byte_5D4594[2496472] + 1) % 128;
	*(_DWORD*)&byte_5D4594[2498020] = (*(_DWORD*)&byte_5D4594[2496988] + 1) % 128;
}

//----- (00553FC0) --------------------------------------------------------
void __cdecl sub_553FC0(int a1, int a2) {
	int v2; // edx
	int v3; // eax

	*(_DWORD*)&byte_5D4594[2495944] += a1;
	*(_DWORD*)&byte_5D4594[2495948] += a2;
	v2 = *(_DWORD*)&byte_5D4594[2496472];
	*(_DWORD*)&byte_5D4594[4 * *(_DWORD*)&byte_5D4594[2496472] + 2495960] = a1;
	v3 = *(_DWORD*)&byte_5D4594[2496988];
	*(_DWORD*)&byte_5D4594[4 * *(_DWORD*)&byte_5D4594[2496988] + 2496476] = a2;
	*(_DWORD*)&byte_5D4594[2496472] = (v2 + 1) % 128;
	*(_DWORD*)&byte_5D4594[2496988] = (v3 + 1) % 128;
}

//----- (00554030) --------------------------------------------------------
void __cdecl sub_554030(int a1, int a2) { *(_DWORD*)&byte_5D4594[4 * a2 + 2498024] += a1; }

//----- (00554040) --------------------------------------------------------
unsigned int __cdecl sub_554040(int a1, int a2, char* a3) {
	char* v3;           // esi
	char* v4;           // edi
	char v5;            // bl
	char* v6;           // ebp
	int v7;             // ebx
	unsigned __int8 v8; // al
	char v9;            // cl
	int v10;            // ecx
	char v11;           // al
	int v12;            // ecx
	int v13;            // edx
	int v14;            // eax
	char v16;           // [esp+8h] [ebp-4Ch]
	char v17[72];       // [esp+Ch] [ebp-48h]

	v3 = sub_416640();
	v4 = sub_416590(0);
	if (!sub_43AF30() || sub_4D6F30())
		return 0;
	v16 = sub_409FA0();
	v5 = sub_416F40();
	if (*(_DWORD*)&nox_common_engineFlags & 0x40000) {
		--v5;
		--v16;
	}
	v6 = sub_40A4C0();
	v17[0] = 0;
	v17[1] = 0;
	v17[2] = 13;
	v17[3] = v5;
	v17[4] = v16;
	v7 = nox_common_gameFlags_getVal_40A5B0();
	*(_DWORD*)&v17[28] = v7;
	if (sub_4D6F50()) {
		LOBYTE(v7) = v7 & 0x7F;
		BYTE1(v7) |= 0x10u;
		*(_DWORD*)&v17[28] = v7;
		*(_WORD*)&v17[68] = sub_4E3CC0();
	}
	v8 = v3[101];
	v9 = v3[101];
	*(_WORD*)&v17[36] = *(_WORD*)(v3 + 105);
	v17[5] = v9 & 0xF;
	v10 = *((_DWORD*)v3 + 11);
	v17[6] = v8 >> 4;
	*(_WORD*)&v17[38] = *(_WORD*)(v3 + 107);
	*(_DWORD*)&v17[40] = v10;
	v11 = sub_43BE50_get_video_mode_id();
	v12 = *((_DWORD*)v4 + 12);
	v17[19] = v3[102] | v11;
	v17[20] = v3[100];
	v17[21] = v17[20] & 0x10;
	v13 = *((_DWORD*)v3 + 12);
	*(_DWORD*)&v17[44] = *(_DWORD*)(a1 + 8);
	v14 = *((_DWORD*)v4 + 11);
	*(_DWORD*)&v17[32] = v12;
	*(_DWORD*)&v17[24] = v13;
	*(_DWORD*)&v17[7] = v14;
	qmemcpy(&v17[48], v4 + 24, 0x14u);
	strcpy(&v17[10], sub_409B40());
	qmemcpy(a3, v17, 0x48u);
	strcpy(a3 + 72, v6);
	return strlen(v6) + 73;
}

//----- (005541D0) --------------------------------------------------------
int* __cdecl sub_5541D0(int a1) {
	int* result; // eax

	result = sub_425890((int*)&byte_5D4594[2495908]);
	if (!result)
		return 0;
	while (result[3] != a1) {
		result = sub_4258A0(result);
		if (!result)
			return 0;
	}
	return result;
}

//----- (00554200) --------------------------------------------------------
int __cdecl sub_554200(unsigned int a1) {
	int result; // eax
	int v2;     // eax

	if (a1 > 0x80)
		goto LABEL_9;
	if (!a1)
		return *(_DWORD*)&byte_5D4594[3843632];
	v2 = *(_DWORD*)&byte_5D4594[4 * a1 + 3843788];
	if (v2)
		result = *(_DWORD*)(v2 + 8);
	else
	LABEL_9:
		result = 0;
	return result;
}

//----- (00554230) --------------------------------------------------------
char* sub_554230() { return (char*)&byte_5D4594[3843644]; }

unsigned int sub_554290() {
	unsigned int v0;     // edi
	int v1;              // ebx
	char* v2;            // esi
	unsigned int v3;     // eax
	unsigned int result; // eax

	v0 = -1;
	v1 = 0;
	v2 = sub_416EA0();
	if (!v2)
		goto LABEL_13;
	do {
		if (v2[2064] != 31 && sub_554240((unsigned __int8)v2[2064]) > 0) {
			v3 = sub_554240((unsigned __int8)v2[2064]);
			if (v3 < v0)
				v0 = v3;
			++v1;
		}
		v2 = sub_416EE0((int)v2);
	} while (v2);
	if (v1)
		result = v0;
	else
	LABEL_13:
		result = 0;
	return result;
}

int sub_554300() {
	int v0;     // ebx
	int v1;     // edi
	char* v2;   // esi
	int result; // eax

	v0 = 0;
	v1 = 0;
	v2 = sub_416EA0();
	if (!v2)
		goto LABEL_11;
	do {
		if (v2[2064] != 31 && (int)sub_554240((unsigned __int8)v2[2064]) > 0) {
			v0 += sub_554240((unsigned __int8)v2[2064]);
			++v1;
		}
		v2 = sub_416EE0((int)v2);
	} while (v2);
	if (v1)
		result = v0 / v1;
	else
	LABEL_11:
		result = 0;
	return result;
}

//----- (00554240) --------------------------------------------------------
int __cdecl sub_554240(int a1) {
	char* v1;   // eax
	int result; // eax

	if (a1 != 31)
		return *(_DWORD*)&byte_5D4594[32 * a1 + 2508848];
	v1 = sub_416640();
	switch (*(_DWORD*)(v1 + 66)) {
	case 1:
		result = sub_554290();
		break;
	case 2:
		result = sub_554300();
		break;
	case 3:
		result = *(_DWORD*)(v1 + 70);
		break;
	default:
		result = 0;
		break;
	}
	return result;
}

//----- (00554370) --------------------------------------------------------
void sub_554370() { nox_srand(0x8FDu); }

//----- (00554380) --------------------------------------------------------
int __cdecl sub_554380(size_t* a1) {
	int result;             // eax
	int v2;                 // ebx
	unsigned __int8* v3;    // eax
	SOCKET* v4;             // eax
	SOCKET* v5;             // esi
	SOCKET v6;              // eax
	signed int v7;          // eax
	u_short v8;             // ax
	__int16 v9;             // cx
	struct hostent* v10;    // eax
	u_short v11;            // [esp-4h] [ebp-1B8h]
	u_short v12;            // [esp-4h] [ebp-1B8h]
	struct sockaddr name;   // [esp+14h] [ebp-1A0h]
	struct WSAData WSAData; // [esp+24h] [ebp-190h]

	if (!a1)
		return -2;
	if (*a1)
		return -5;
	if ((int)a1[4] > 128)
		return -2;
	v2 = 0;
	byte_5D4594[3843644] = 0;
	*(_DWORD*)&byte_5D4594[3843632] = 0;
	byte_5D4594[3843660] = 0;
	v3 = &byte_5D4594[3843788];
	while (*(_DWORD*)v3) {
		v3 += 4;
		++v2;
		if ((int)v3 >= (int)&byte_5D4594[3844300])
			return -8;
	}
	if (v2 == -1)
		return -8;
	v4 = (SOCKET*)sub_553000(a1);
	v5 = v4;
	*(_DWORD*)&byte_5D4594[4 * v2 + 3843788] = v4;
	if (!v4)
		return -1;
	*(_BYTE*)v4[12] = v2;
	v4[5] = -1;
	result = WSAStartup(0x101u, &WSAData);
	if (result != -1) {
		v6 = socket(2, 2, 0);
		*v5 = v6;
		if (v6 == -1) {
		LABEL_17:
			WSACleanup();
			result = -1;
		} else {
			v7 = a1[2];
			if (v7 < 1024 || v7 > 0x10000)
				a1[2] = 18590;
			v11 = *((_WORD*)a1 + 4);
			*(_WORD*)name.sa_data = 0;
			name.sa_family = 2;
			*(_DWORD*)&name.sa_data[2] = 0;
			*(_DWORD*)&name.sa_data[6] = 0;
			*(_DWORD*)&name.sa_data[10] = 0;
			v8 = htons(v11);
			v9 = *((_WORD*)a1 + 4);
			*(_DWORD*)&name.sa_data[2] = 0;
			*(_WORD*)name.sa_data = v8;
			*(_WORD*)&byte_5D4594[3843636] = v9;
			while (bind(*v5, &name, 16) == -1) {
				if (WSAGetLastError() != 10048)
					goto LABEL_17;
				v12 = *((_WORD*)a1 + 4) + 1;
				++a1[2];
				*(_WORD*)name.sa_data = htons(v12);
			}
			if (gethostname((char*)&byte_5D4594[3843660], 128) != -1) {
				v10 = gethostbyname((const char*)&byte_5D4594[3843660]);
				if (v10) {
					*(_DWORD*)&byte_5D4594[3843632] = **(_DWORD**)v10->h_addr_list;
					strcpy((char*)&byte_5D4594[3843644],
					       inet_ntoa(*(struct in_addr*)&byte_5D4594[3843632]));
				}
			}
			result = v2;
		}
	}
	return result;
}

//----- (005545A0) --------------------------------------------------------
__int16 sub_5545A0() { return *(_WORD*)&byte_5D4594[3843636]; }

//----- (005545B0) --------------------------------------------------------
int __cdecl sub_5545B0(unsigned int a1) {
	unsigned int v1; // ebx
	_DWORD* v3;      // ecx
	int v4;          // ebp
	unsigned int v5; // esi
	int v6;          // eax
	LPVOID* v7;      // edi
	char v8;         // [esp+Fh] [ebp-1h]
	unsigned int v9; // [esp+14h] [ebp+4h]

	v1 = a1;
	v8 = 11;
	if (a1 >= 0x80)
		return -3;
	v3 = *(_DWORD**)&byte_5D4594[4 * a1 + 3843788];
	if (!v3)
		return 0;
	v4 = v3[5];
	if (v4 == -1) {
		v5 = 0;
		v9 = 128;
		v4 = v1;
	} else {
		v5 = a1;
		v9 = a1 + 1;
		v6 = *(_DWORD*)&byte_5D4594[4 * v4 + 3843788];
		if (!v6 || *(int*)(v6 + 20) != -1) {
			sub_5531C0(v3);
			*(_DWORD*)&byte_5D4594[4 * v1 + 3843788] = 0;
			return 0;
		}
	}
	if (v5 >= v9)
		return 0;
	v7 = (LPVOID*)&byte_5D4594[4 * v5 + 3843788];
	do {
		if (*v7) {
			if (*((int*)*v7 + 5) == v4) {
				sub_5528B0(v5, 1);
				sub_552640(v5, &v8, 1, 0);
				sub_5528B0(v5, 1);
				--*(_DWORD*)(*(_DWORD*)&byte_5D4594[4 * v4 + 3843788] + 84);
				sub_555360(v1, 0, 2);
				sub_5531C0(*v7);
				*v7 = 0;
			}
		}
		++v5;
		++v7;
	} while (v5 < v9);
	return 0;
}

//----- (005546A0) --------------------------------------------------------
int __cdecl sub_5546A0(unsigned int a1) {
	SOCKET* v2; // eax

	if (a1 >= 0x80)
		return -3;
	v2 = *(SOCKET**)&byte_5D4594[4 * a1 + 3843788];
	if (v2) {
		closesocket(*v2);
		sub_5531C0(*(LPVOID*)&byte_5D4594[4 * a1 + 3843788]);
		*(_DWORD*)&byte_5D4594[4 * a1 + 3843788] = 0;
		WSACleanup();
	}
	return 0;
}

//----- (005546F0) --------------------------------------------------------
int __cdecl sub_5546F0(size_t* a1) {
	int result;          // eax
	int v2;              // esi
	unsigned __int8* v3; // eax
	void* v4;            // eax

	if (!a1)
		return -2;
	if (*a1)
		return -5;
	v2 = 0;
	v3 = &byte_5D4594[3843788];
	while (*(_DWORD*)v3) {
		v3 += 4;
		++v2;
		if ((int)v3 >= (int)&byte_5D4594[3844300])
			return -8;
	}
	if (v2 == -1)
		return -8;
	v4 = sub_553000(a1);
	*(_DWORD*)&byte_5D4594[4 * v2 + 3843788] = v4;
	if (v4)
		result = v2;
	else
		result = -1;
	return result;
}

//----- (00554760) --------------------------------------------------------
int __cdecl sub_554760(int a1, char* cp, int hostshort, int a4, int a5) {
	int* v5;                // ebp
	int v7;                 // eax
	unsigned int v8;        // ebx
	struct hostent* v9;     // eax
	int v10;                // esi
	char v11;               // al
	char v12;               // [esp+12h] [ebp-1B2h]
	struct sockaddr name;   // [esp+14h] [ebp-1B0h]
	WORD v14[2];            // [esp+24h] [ebp-1A0h]
	int v15;                // [esp+28h] [ebp-19Ch]
	struct WSAData WSAData; // [esp+34h] [ebp-190h]

	v5 = *(int**)&byte_5D4594[4 * a1 + 3843788];
	if ((unsigned int)a1 >= 0x80)
		return -3;
	if (!v5)
		return -3;
	if (!cp)
		return -4;
	if (hostshort < 1024 || hostshort > 0x10000)
		return -15;
	if (WSAStartup(0x101u, &WSAData) == -1)
		return -21;
	v7 = socket(2, 2, 0);
	*v5 = v7;
	if (v7 == -1) {
		WSACleanup();
		return -22;
	}
	if ((unsigned __int8)*cp < 0x30u || (unsigned __int8)*cp > 0x39u) {
		v9 = gethostbyname(cp);
		if (!v9) {
			WSACleanup();
			return -4;
		}
		v8 = **(_DWORD**)v9->h_addr_list;
	} else {
		v8 = inet_addr(cp);
	}
	v15 = 0;
	v14[0] = 2;
	v14[1] = htons(hostshort);
	v5[1] = *(_DWORD*)v14;
	v5[2] = v8;
	v5[3] = 0;
	v5[4] = 0;
	v10 = sub_40A420();
	name.sa_family = 2;
	*(_DWORD*)&name.sa_data[6] = 0;
	*(_DWORD*)&name.sa_data[10] = 0;
	*(_WORD*)name.sa_data = htons(v10);
	*(_DWORD*)&name.sa_data[2] = 0;
	while (bind(*v5, &name, 16) == -1) {
		if (WSAGetLastError() != 10048) {
			WSACleanup();
			return -1;
		}
		*(_WORD*)name.sa_data = htons(++v10);
	}
	dword_5d4594_3844304 = 0;
	v12 = 0;
	v11 = sub_552640(a1, &v12, 1, 3);
	if (sub_5525B0(a1, v11, 60, 6))
		return -23;
	printf("bar %d\n", dword_5d4594_3844304);
	if (dword_5d4594_3844304 && (int)v5[5] >= 0) {
		memset(&byte_5D4594[2512892], 0, 0x400u);
		byte_5D4594[2512892] = 31;
		byte_5D4594[2512893] = *(_BYTE*)(v5[12] + 1);
		byte_5D4594[2512894] = 32;
		if (a4)
			qmemcpy(&byte_5D4594[2512895], (const void*)a4, a5);
		sub_552640(a1, &byte_5D4594[2512892], a5 + 3, 3);
	}
	return v5[5];
}

//----- (005549F0) --------------------------------------------------------
int __cdecl sub_5549F0(unsigned int a1) {
	char v2; // [esp+7h] [ebp-1h]

	v2 = 10;
	if (a1 >= 0x80)
		return -3;
	if (*(_DWORD*)&byte_5D4594[4 * a1 + 3843788]) {
		sub_5528B0(a1, 0);
		sub_552640(a1, &v2, 1, 0);
		sub_5528B0(a1, 0);
		sub_554A50(a1);
	}
	return 0;
}

//----- (00554A50) --------------------------------------------------------
int __cdecl sub_554A50(unsigned int a1) {
	SOCKET* v2; // eax

	if (a1 >= 0x80)
		return -3;
	v2 = *(SOCKET**)&byte_5D4594[4 * a1 + 3843788];
	if (v2) {
		closesocket(*v2);
		OnLibraryNotice(259, *(_DWORD*)&byte_5D4594[4 * a1 + 3843788]);
		sub_5531C0(*(LPVOID*)&byte_5D4594[4 * a1 + 3843788]);
		*(_DWORD*)&byte_5D4594[4 * a1 + 3843788] = 0;
		WSACleanup();
	}
	return 0;
}

//----- (00554AA0) --------------------------------------------------------
void __cdecl sub_554AA0(u_short hostshort, int a2, int a3, int a4) {
	int v4;   // esi
	char* v5; // ebx
	int v6[3];

	v4 = 12;
	v5 = (char*)nox_malloc((unsigned __int16)a3 + 12);
	v5[2] = 12;
	*v5 = 0;
	v5[1] = 0;
	*((_WORD*)v5 + 2) = 0;
	*((_DWORD*)v5 + 2) = a4;
	if (a2 && (unsigned __int16)a3 > 0u) {
		qmemcpy(v5 + 12, (const void*)a2, (unsigned __int16)a3);
		*((_WORD*)v5 + 2) = a3;
		v4 = a3 + 12;
	}
	dword_5d4594_3844304 = 0;
	sub_554C80(hostshort, v5, v4);
	v6[0] = hostshort;
	v6[1] = v5;
	v6[2] = v4;
	OnLibraryNotice(260, &v6);
	free(v5);
}

//----- (00554B30) --------------------------------------------------------
void sub_554B30() { nox_srand(0x910u); }

//----- (00554B40) --------------------------------------------------------
int __cdecl sub_554B40(u_short hostshort) {
	int result;             // eax
	struct sockaddr name;   // [esp+4h] [ebp-1A4h]
	char optval[4];         // [esp+14h] [ebp-194h]
	struct WSAData WSAData; // [esp+18h] [ebp-190h]

	if (*(_DWORD*)&byte_5D4594[2513916] == 1)
		return -14;
	result = WSAStartup(0x101u, &WSAData);
	if (result != -1) {
		dword_5d4594_2513920 = socket(2, 2, 0);
		if (*(int*)&dword_5d4594_2513920 == -1) {
			WSACleanup();
			result = -1;
		} else {
			*(_DWORD*)&byte_5D4594[2513924] = socket(2, 2, 0);
			if (*(int*)&byte_5D4594[2513924] == -1) {
				WSACleanup();
				result = -1;
			} else {
				name.sa_family = 2;
				*(_DWORD*)&name.sa_data[6] = 0;
				*(_DWORD*)&name.sa_data[10] = 0;
				*(_WORD*)name.sa_data = htons(hostshort);
				*(_DWORD*)&name.sa_data[2] = 0;
				if (bind(*(SOCKET*)&dword_5d4594_2513920, &name, 16) == -1) {
					WSACleanup();
					result = -1;
				} else {
					*(_DWORD*)optval = 1;
					result = setsockopt(*(SOCKET*)&dword_5d4594_2513920, 0xFFFF, 32, optval, 4);
					if (result != -1) {
						nox_set_draw_unk1((int)sub_554FF0);
						*(_DWORD*)&byte_5D4594[2513916] = 1;
						result = 0;
					}
				}
			}
		}
	}
	return result;
}

//----- (00554C80) --------------------------------------------------------
int __cdecl sub_554C80(u_short hostshort, char* buf, int a3) {
	int v3;             // esi
	int result;         // eax
	struct sockaddr to; // [esp+4h] [ebp-10h]

	v3 = 0;
	if (!*(_DWORD*)&byte_5D4594[2513916])
		return -17;
	to.sa_family = 2;
	*(_DWORD*)&to.sa_data[6] = 0;
	*(_DWORD*)&to.sa_data[10] = 0;
	*(_WORD*)to.sa_data = htons(hostshort);
	*(_DWORD*)&to.sa_data[2] = -1;
	if (!buf || (unsigned __int16)a3 < 2u ||
	    (result = sendto(*(SOCKET*)&dword_5d4594_2513920, buf, (unsigned __int16)a3, 0, &to, 16), v3 = result,
	     result != -1)) {
		result = v3;
	}
	return result;
}

//----- (00554D10) --------------------------------------------------------
int sub_554D10() {
	if (*(_DWORD*)&byte_5D4594[2513916]) {
		closesocket(*(SOCKET*)&dword_5d4594_2513920);
		closesocket(*(SOCKET*)&byte_5D4594[2513924]);
		dword_5d4594_2513920 = 0;
		*(_DWORD*)&byte_5D4594[2513924] = 0;
		*(_DWORD*)&byte_5D4594[2513916] = 0;
		nox_set_draw_unk1(0);
		sub_555000(0);
		WSACleanup();
	}
	return 0;
}

//----- (00554D70) --------------------------------------------------------
int __cdecl sub_554D70(char a1) {
	int result;           // eax
	int v2;               // ebp
	char v3;              // al
	char* v4;             // eax
	char* v5;             // esi
	int v6;               // eax
	u_short v7;           // ax
	int v8;               // [esp+0h] [ebp-230h]
	u_long argp;          // [esp+10h] [ebp-220h]
	int fromlen;          // [esp+14h] [ebp-21Ch]
	int v11;              // [esp+18h] [ebp-218h]
	int v12;              // [esp+1Ch] [ebp-214h]
	struct sockaddr from; // [esp+20h] [ebp-210h]
	char buf[256];        // [esp+30h] [ebp-200h]
	char in[256];         // [esp+130h] [ebp-100h]

	fromlen = 16;
	if (!*(_DWORD*)&byte_5D4594[2513916])
		return -17;
	v11 = a1 & 1;
	if (a1 & 1) {
		result = ioctlsocket(*(SOCKET*)&dword_5d4594_2513920, 1074030207, &argp);
		if (result == -1)
			return result;
		if (argp)
			goto LABEL_8;
	} else {
		argp = 1;
	LABEL_8:
		while (1) {
			v2 = mix_recvfrom(*(SOCKET*)&dword_5d4594_2513920, buf, 256, 0, &from, &fromlen);
			if (v2 == -1)
				break;
			v3 = buf[2];
			LOBYTE(v12) = buf[2];
			if (buf[2] < 0x20u) {
				qmemcpy(in, &from, fromlen);
				if (v3 == 13 || sub_43B300() == *(_DWORD*)&from.sa_data[2]) {
					switch ((unsigned __int8)v12) {
					case 0xDu:
						v4 = inet_ntoa(*(struct in_addr*)&in[4]);
						v5 = v4;
						if (&v8 != (int*)-120) {
							if (v4) {
								if (*(_DWORD*)&byte_5D4594[2513928]) {
									OnLibraryNotice(262, &v8);
									LOWORD(v6) = ntohs(*(u_short*)&in[2]);
									if ((*(int(__cdecl**)(_DWORD, _DWORD, _DWORD,
											      _DWORD)) &
									     byte_5D4594[2513928])(v5, v6, &buf[72],
												   buf) == 1)
										sub_555000(0);
								}
							}
						}
						break;
					case 0xFu:
						if (sub_43B6D0())
							sub_43AF90(5);
						break;
					case 0x10u:
						if (sub_43B6D0()) {
							sub_43AF90(4);
							buf[2] = 18;
							v7 = htons(*(u_short*)from.sa_data);
							sub_555010(*(int*)&from.sa_data[2], v7, buf, 8);
						}
						break;
						/*case 0x13u:
						  if ( sub_43B6D0() )
						    sub_43AFA0((unsigned __int8)buf[3]);
						  break;*/
					case 0x13u:
					case 0x14u:
						if (sub_43B6D0() && sub_43AF80() == 3)
							sub_43AF90(7);
						break;
					case 0x15u:
						if (sub_43B6D0())
							sub_43AF90(8);
						break;
					default:
						break;
					}
				}
			}
			if (v11 && !(a1 & 4)) {
				if (ioctlsocket(*(SOCKET*)&dword_5d4594_2513920, 1074030207, &argp) == -1)
					return -1;
				if (argp)
					continue;
			}
			return v2;
		}
	}
	return -1;
}
// 554EC5: variable 'v6' is possibly undefined

//----- (00554FF0) --------------------------------------------------------
int sub_554FF0() {
	sub_554D70(1);
	return 1;
}

//----- (00555000) --------------------------------------------------------
int __cdecl sub_555000(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[2513928] = a1;
	return result;
}

//----- (00555010) --------------------------------------------------------
int __cdecl sub_555010(int a1, u_short hostshort, char* buf, int a4) {
	int v4;             // esi
	int result;         // eax
	struct sockaddr to; // [esp+4h] [ebp-10h]

	v4 = 0;
	if (!*(_DWORD*)&byte_5D4594[2513916])
		return -17;
	to.sa_family = 2;
	*(_DWORD*)&to.sa_data[6] = 0;
	*(_DWORD*)&to.sa_data[10] = 0;
	*(_WORD*)to.sa_data = htons(hostshort);
	*(_DWORD*)&to.sa_data[2] = a1;
	if (!buf || (unsigned __int16)a4 < 2u ||
	    (result = sendto(*(SOCKET*)&dword_5d4594_2513920, buf, (unsigned __int16)a4, 0, &to, 16), v4 = result,
	     result != -1)) {
		result = v4;
	}
	return result;
}

//----- (005550A0) --------------------------------------------------------
int __cdecl sub_5550A0(int a1, u_short hostshort, char* buf) {
	*buf = 0;
	buf[1] = 0;
	buf[2] = 14;
	return sub_555010(a1, hostshort, buf, 100);
}

//----- (005550D0) --------------------------------------------------------
int __cdecl sub_5550D0(int a1, u_short hostshort, char* buf) {
	*buf = 0;
	buf[1] = 0;
	buf[2] = 17;
	return sub_555010(a1, hostshort, buf, 22);
}

//----- (00555100) --------------------------------------------------------
int sub_555100() { return *(_DWORD*)&byte_5D4594[2513916]; }

//----- (00555110) --------------------------------------------------------
void sub_555110() { nox_srand(0x911u); }

//----- (00555120) --------------------------------------------------------
void sub_555120() { nox_srand(0x906u); }

//----- (00555130) --------------------------------------------------------
int __cdecl sub_555130(unsigned int a1, const void* a2, signed int a3) {
	int v3;     // edi
	_DWORD* v5; // eax

	v3 = *(_DWORD*)&byte_5D4594[4 * a1 + 3843788];
	if (a3 > *(int*)&byte_5D4594[2512884])
		return -1;
	if (!a2)
		return -1;
	if (a1 >= 0x80)
		return -3;
	if (!v3)
		return -3;
	v5 = nox_alloc_class_new_obj_zero(*(_DWORD**)&byte_5D4594[3844300]);
	if (!v5)
		return -1;
	*v5 = *(_DWORD*)(v3 + 116);
	*(_DWORD*)(v3 + 116) = v5;
	v5[3] = 1;
	*((_BYTE*)v5 + 20) = **(_BYTE**)(v3 + 48) | 0x80;
	*((_BYTE*)v5 + 21) = (*(_BYTE*)(v3 + 112))++;
	v5[4] = a3 + 2;
	qmemcpy((char*)v5 + 22, a2, a3);
	return *((unsigned __int8*)v5 + 21);
}

//----- (005551F0) --------------------------------------------------------
int __cdecl sub_5551F0(unsigned int a1, char a2, int a3) {
	int v4; // eax
	int* i; // eax

	if (a1 >= 0x80)
		return -3;
	v4 = *(_DWORD*)&byte_5D4594[4 * a1 + 3843788];
	if (!v4)
		return -3;
	for (i = *(int**)(v4 + 116); i; i = (int*)*i) {
		if (a3) {
			if (*((_BYTE*)i + 21) == a2)
				goto LABEL_10;
		} else if (i[1] <= *(int*)&dword_5d4594_2495920) {
		LABEL_10:
			i[3] = 1;
			continue;
		}
	}
	return 0;
}

//----- (00555250) --------------------------------------------------------
int __cdecl sub_555250(unsigned int a1, _DWORD* a2) {
	int v2;     // eax
	int v3;     // eax
	int v4;     // ecx
	int result; // eax

	if (a1 >= 0x80)
		return 0;
	v2 = *(_DWORD*)&byte_5D4594[4 * a1 + 3843788];
	if (!v2)
		return 0;
	v3 = *(_DWORD*)(v2 + 116);
	if (!v3)
		return 0;
	v4 = *(_DWORD*)(v3 + 16);
	result = v3 + 22;
	*a2 = v4;
	*(_DWORD*)&byte_5D4594[2513932] = *(_DWORD*)(result - 22);
	return result;
}

//----- (00555290) --------------------------------------------------------
int __cdecl sub_555290(unsigned int a1, _DWORD* a2) {
	int result; // eax

	if (!*(_DWORD*)&byte_5D4594[2513932] || a1 >= 0x80 || !*(_DWORD*)&byte_5D4594[4 * a1 + 3843788])
		return 0;
	result = *(_DWORD*)&byte_5D4594[2513932] + 22;
	*a2 = *(_DWORD*)(*(_DWORD*)&byte_5D4594[2513932] + 16);
	*(_DWORD*)&byte_5D4594[2513932] = *(_DWORD*)(result - 22);
	return result;
}

//----- (005552D0) --------------------------------------------------------
int __cdecl sub_5552D0(unsigned int a1, char a2, int a3) {
	int v3; // edi
	int* i; // esi
	int v6; // eax

	v3 = *(_DWORD*)&byte_5D4594[4 * a1 + 3843788];
	if (a1 >= 0x80)
		return -3;
	if (!v3)
		return -3;
	for (i = *(int**)(v3 + 116); i; i = (int*)*i) {
		if (a3) {
			if (*((_BYTE*)i + 21) == a2)
				goto LABEL_10;
		} else if (i[3]) {
		LABEL_10:
			v6 = i[4];
			i[3] = 0;
			i[1] = dword_5d4594_2495920 + 2000;
			if (sub_551F90(*(_DWORD*)v3, (char*)i + 20, v6, 0, (struct sockaddr*)(v3 + 4), 16) == -1)
				return 0;
			continue;
		}
	}
	return 0;
}

//----- (00555360) --------------------------------------------------------
int __cdecl sub_555360(unsigned int a1, unsigned __int8 a2, int a3) {
	int v3;      // edi
	char* v5;    // esi
	_QWORD* v6;  // eax
	_DWORD* v7;  // ecx
	char v8[24]; // [esp+4h] [ebp-18h]

	v3 = *(_DWORD*)&byte_5D4594[4 * a1 + 3843788];
	if (a1 >= 0x80)
		return -3;
	if (!v3)
		return -3;
	*(_DWORD*)v8 = *(_DWORD*)(v3 + 116);
	v5 = v8;
	while (*(_DWORD*)v5) {
		if (a3) {
			if (a3 == 1) {
				if (a2 < 0x20u || a2 > 0xE0u) {
					if (*(_BYTE*)(*(_DWORD*)v5 + 21) < (char)a2)
						goto LABEL_17;
				} else if (*(_BYTE*)(*(_DWORD*)v5 + 21) < a2) {
					goto LABEL_17;
				}
			} else if (a3 == 2) {
			LABEL_17:
				v6 = *(_QWORD**)v5;
				v7 = *(_DWORD**)(v3 + 116);
				if (*(_DWORD**)v5 == v7)
					*(_DWORD*)(v3 + 116) = *v7;
				*(_DWORD*)v5 = **(_DWORD**)v5;
				*(_DWORD*)v6 = 0;
				sub_414330(*(unsigned int**)&byte_5D4594[3844300], v6);
				continue;
			}
		} else if (*(_BYTE*)(*(_DWORD*)v5 + 21) == a2) {
			goto LABEL_17;
		}
		v5 = *(char**)v5;
	}
	return 0;
}

//----- (00555420) --------------------------------------------------------
void sub_555420() { nox_srand(0x907u); }

//----- (00565360) --------------------------------------------------------
int* __cdecl sub_565360(int a1, _WORD* a2, int* a3, unsigned int a4, int a5, int a6) {
	int* v6;               // edx
	int v7;                // ebp
	_WORD* v8;             // esi
	int* result;           // eax
	int* v10;              // edi
	int v11;               // ecx
	_WORD* v12;            // eax
	int v13;               // ebx
	int* v14;              // esi
	int v15;               // edi
	unsigned __int16* v16; // eax
	int v17;               // esi
	unsigned __int16 v18;  // cx
	unsigned __int16 v19;  // bx
	unsigned __int16* v20; // eax
	unsigned __int16 v21;  // cx
	unsigned __int16 v22;  // bx
	int* v23;              // [esp+Ch] [ebp-4h]
	int v24;               // [esp+1Ch] [ebp+Ch]
	int* v25;              // [esp+24h] [ebp+14h]
	int* v26;              // [esp+28h] [ebp+18h]

	v6 = a3;
	v7 = 2 * a6;
	v8 = a2;
	result = (int*)((char*)a3 + 2 * 2 * a6 * a5);
	v10 = a3;
	v23 = (int*)((char*)a3 + 2 * 2 * a6 * a5);
	v26 = a3;
	v25 = &a3[2 * a4];
	if (a3 < result) {
		while (1) {
			result = (int*)(*v8 & 0x1FFF);
			v11 = *v8 & 0xE000;
			v24 = (int)(v8 + 1);
			if (*v8 & 0xE000) {
				if (v11 == 0x2000) {
					v12 = (_WORD*)(a1 + 16 * (*v8 & 0x1FFF));
					v13 = 2;
					do {
						v14 = v6;
						v15 = 4;
						do {
							if (*v12 != -32768)
								*(_WORD*)v14 = *v12;
							v14 = (int*)((char*)v14 + 2);
							++v12;
							--v15;
						} while (v15);
						v6 = (int*)((char*)v6 + v7);
						--v13;
					} while (v13);
					v10 = v26;
					result = (int*)(2 * v7);
					v6 = (int*)((char*)v6 + 8 - 2 * v7);
				} else if (v11 == 0x4000) {
					v6 += 2;
				}
			} else {
				v16 = (unsigned __int16*)(a1 + 16 * (*v8 & 0x1FFF));
				v17 = 2;
				do {
					v18 = v16[1];
					v19 = *v16;
					v20 = v16 + 2;
					*v6 = v19 | (v18 << 16);
					v21 = v20[1];
					v22 = *v20;
					v16 = v20 + 2;
					v6[1] = v22 | (v21 << 16);
					v6 = (int*)((char*)v6 + v7);
					--v17;
				} while (v17);
				result = (int*)(2 * v7);
				v6 = (int*)((char*)v6 + 8 - 2 * v7);
			}
			if (v6 == v25) {
				v10 = (int*)((char*)v10 + 2 * v7);
				result = (int*)a4;
				v26 = v10;
				v6 = v10;
				v25 = &v10[2 * a4];
			}
			if (v6 >= v23)
				break;
			v8 = (_WORD*)v24;
		}
	}
	return result;
}

//----- (005654A0) --------------------------------------------------------
unsigned int __cdecl sub_5654A0(int a1, unsigned __int8* a2, int* a3, unsigned int a4, int a5, int a6) {
	int v6;                // edi
	int v7;                // ecx
	int* v8;               // ebx
	unsigned __int8* v9;   // esi
	unsigned int result;   // eax
	__int16 v11;           // ax
	__int16 v12;           // cx
	unsigned int v13;      // ecx
	int* v14;              // edi
	unsigned __int16* v15; // ecx
	int v16;               // eax
	int v17;               // esi
	unsigned __int16 v18;  // dx
	unsigned __int16 v19;  // bp
	unsigned __int16* v20; // ecx
	unsigned __int16 v21;  // dx
	unsigned __int16 v22;  // bp
	unsigned __int8* v23;  // ecx
	int* v24;              // edx
	unsigned __int16* v25; // eax
	int v26;               // edi
	unsigned __int16 v27;  // cx
	unsigned __int16 v28;  // bp
	unsigned __int16* v29; // eax
	unsigned __int16 v30;  // cx
	unsigned __int16 v31;  // bp
	int v32;               // edx
	unsigned __int16* v33; // eax
	int v34;               // edx
	unsigned __int16 v35;  // cx
	unsigned __int16 v36;  // bp
	unsigned __int16* v37; // eax
	unsigned __int16 v38;  // cx
	unsigned __int16 v39;  // bp
	int v40;               // ebp
	__int16* v41;          // eax
	int* v42;              // edi
	__int16 v43;           // dx
	int* v44;              // ecx
	int v45;               // esi
	int v46;               // ebp
	int* v47;              // ecx
	int v48;               // eax
	int* v49;              // ecx
	int* v50;              // esi
	int v51;               // edi
	int v52;               // eax
	_DWORD* v53;           // esi
	int v54;               // edi
	_WORD* v55;            // eax
	int v56;               // ebp
	int* v57;              // edx
	int v58;               // esi
	int* v59;              // [esp+Ch] [ebp-Ch]
	int* v60;              // [esp+10h] [ebp-8h]
	unsigned int v61;      // [esp+14h] [ebp-4h]
	int v62;               // [esp+20h] [ebp+8h]
	unsigned int v63;      // [esp+24h] [ebp+Ch]
	int v64;               // [esp+24h] [ebp+Ch]
	int v65;               // [esp+24h] [ebp+Ch]
	int v66;               // [esp+2Ch] [ebp+14h]
	unsigned int v67;      // [esp+2Ch] [ebp+14h]
	unsigned int v68;      // [esp+30h] [ebp+18h]

	v6 = 2 * a6;
	v7 = 2 * a6 * a5;
	v8 = a3;
	v9 = a2;
	v68 = 2 * a6;
	result = (unsigned int)a3 + 2 * v7;
	v61 = result;
	v59 = a3;
	v60 = &a3[2 * a4];
	if ((unsigned int)a3 < result) {
		do {
			v11 = *(_WORD*)v9;
			v9 += 2;
			v12 = v11;
			result = v11 & 0x1FFF;
			v13 = v12 & 0xE000;
			v66 = (int)v9;
			if (v13 > 0x6000) {
				switch (v13) {
				case 0x8000u:
					v55 = (_WORD*)(a1 + 16 * (unsigned __int16)result);
					v56 = 2;
					do {
						v57 = v8;
						v58 = 4;
						do {
							if (*v55 != -32768)
								*(_WORD*)v57 = *v55;
							v57 = (int*)((char*)v57 + 2);
							++v55;
							--v58;
						} while (v58);
						v8 = (int*)((char*)v8 + v6);
						--v56;
					} while (v56);
					result = 2 * v6;
					v8 = (int*)((char*)v8 + 8 - 2 * v6);
					goto LABEL_52;
				case 0xA000u:
					goto LABEL_16;
				case 0xC000u:
					v40 = *v9;
					v66 = (int)(v9 + 1);
					v41 = (__int16*)(a1 + 16 * (unsigned __int16)result);
					v62 = 2;
					do {
						v42 = v8;
						v65 = 4;
						do {
							v43 = *v41;
							if (*v41 != -32768) {
								v44 = v42;
								if (v40) {
									v45 = v40;
									do {
										*(_WORD*)v44 = v43;
										v44 += 2;
										--v45;
									} while (v45);
								}
							}
							v42 = (int*)((char*)v42 + 2);
							++v41;
							--v65;
						} while (v65);
						v8 = (int*)((char*)v8 + v68);
						--v62;
					} while (v62);
					v6 = v68;
					result = 2 * v68;
					v8 = (int*)((char*)v8 + 8 * v40 - 2 * v68);
					goto LABEL_52;
				}
			} else if (v13 == 24576) {
				v33 = (unsigned __int16*)(a1 + 16 * (unsigned __int16)result);
				v34 = 2;
				do {
					v35 = v33[1];
					v36 = *v33;
					v37 = v33 + 2;
					*v8 = v36 | (v35 << 16);
					v38 = v37[1];
					v39 = *v37;
					v33 = v37 + 2;
					v8[1] = v39 | (v38 << 16);
					v8 = (int*)((char*)v8 + v6);
					--v34;
				} while (v34);
				result = 2 * v6;
				v8 = (int*)((char*)v8 + 8 - 2 * v6);
			} else if (v13) {
				if (v13 == 0x2000) {
					v32 = (((unsigned __int16)result >> 7) & 0x3E) + 2;
					if ((((unsigned __int16)result >> 7) & 0x3E) == -2) {
					LABEL_16:
						result = (unsigned __int16)result;
						v32 = *v9;
						v66 = (int)(v9 + 1);
					} else {
						result = (unsigned __int8)result;
					}
					v46 = 2;
					v47 = (int*)(a1 + 16 * result);
					do {
						v48 = *v47;
						v49 = v47 + 1;
						v50 = v8;
						if (v32) {
							v51 = v32;
							do {
								*v50 = v48;
								v50 += 2;
								--v51;
							} while (v51);
							v6 = v68;
						}
						v52 = *v49;
						v47 = v49 + 1;
						v53 = v8 + 1;
						if (v32) {
							v54 = v32;
							do {
								*v53 = v52;
								v53 += 2;
								--v54;
							} while (v54);
							v6 = v68;
						}
						v8 = (int*)((char*)v8 + v6);
						--v46;
					} while (v46);
					result = 2 * v6;
					v8 = (int*)((char*)v8 + 8 * v32 - 2 * v6);
				LABEL_52:
					v9 = (unsigned __int8*)v66;
					goto LABEL_53;
				}
				if (v13 == 0x4000) {
					v14 = v8;
					v15 = (unsigned __int16*)(a1 + 16 * *(v9 - 2));
					v63 = ((result >> 7) & 0x3E) + 2;
					v16 = 2;
					v17 = 4 * (v68 >> 2);
					do {
						v18 = v15[1];
						v19 = *v15;
						v20 = v15 + 2;
						*v14 = v19 | (v18 << 16);
						v21 = v20[1];
						v22 = *v20;
						v15 = v20 + 2;
						v14[1] = v22 | (v21 << 16);
						v14 = (int*)((char*)v14 + v17);
						--v16;
					} while (v16);
					result = v63;
					v23 = (unsigned __int8*)v66;
					v8 += 2;
					if (v63) {
						v67 = v63;
						do {
							v24 = v8;
							v64 = (int)(v23 + 1);
							v25 = (unsigned __int16*)(a1 + 16 * *v23);
							v26 = 2;
							do {
								v27 = v25[1];
								v28 = *v25;
								v29 = v25 + 2;
								*v24 = v28 | (v27 << 16);
								v30 = v29[1];
								v31 = *v29;
								v25 = v29 + 2;
								v24[1] = v31 | (v30 << 16);
								v24 = (int*)((char*)v24 + v17);
								--v26;
							} while (v26);
							v23 = (unsigned __int8*)v64;
							v8 += 2;
							result = --v67;
						} while (v67);
					}
					v6 = v68;
					v66 = (int)v23;
					goto LABEL_52;
				}
			} else {
				result = (unsigned __int8)result;
				v8 += 2 * (unsigned __int8)result;
			}
		LABEL_53:
			if (v8 == v60) {
				v8 = (int*)((char*)v59 + 2 * v6);
				result = a4;
				v59 = v8;
				v60 = &v8[2 * a4];
			}
		} while ((unsigned int)v8 < v61);
	}
	return result;
}

//----- (0056F1C0) --------------------------------------------------------
int sub_56F1C0() {
	int v0;     // eax
	int result; // eax

	v0 = time(0);
	sub_56FF00(v0);
	*(_DWORD*)&byte_5D4594[2516352] = 0;
	dword_5d4594_2516348 = *(_DWORD*)&byte_5D4594[2598000];
	dword_5d4594_2516344 = 0;
	*(_WORD*)&byte_587000[311204] = 0;
	*(_DWORD*)&byte_5D4594[2516356] = 657757279;
	dword_5d4594_2516348 ^= sub_56F240();
	dword_5d4594_2516328 = ~dword_5d4594_2516348;
	*(_DWORD*)&byte_5D4594[2516340] = sub_56F400(0);
	sub_56F250();
	result = sub_56F400(1);
	*(_DWORD*)&byte_5D4594[2516332] = result;
	return result;
}

//----- (0056F240) --------------------------------------------------------
int sub_56F240() { return sub_56FF80(1, -1); }

//----- (0056F250) --------------------------------------------------------
int sub_56F250() {
	int v0;     // esi
	int result; // eax

	v0 = 7;
	do {
		result = sub_56F280(*(int*)&byte_5D4594[2516356], 0);
		--v0;
		++*(_DWORD*)&byte_5D4594[2516356];
	} while (v0);
	return result;
}

//----- (0056F280) --------------------------------------------------------
int __cdecl sub_56F280(int a1, int a2) {
	_DWORD* v2; // eax
	int v3;     // ecx
	int v4;     // ecx

	v2 = nox_calloc(1u, 0x10u);
	if (!v2)
		return 0;
	v2[3] = 0;
	v2[2] = 0;
	v3 = a1 ^ dword_5d4594_2516348;
	*v2 = a1 ^ dword_5d4594_2516348;
	dword_5d4594_2516328 ^= v3;
	v2[1] = a2;
	v4 = a2 ^ dword_5d4594_2516348;
	v2[1] = a2 ^ dword_5d4594_2516348;
	dword_5d4594_2516328 ^= v4;
	return sub_56F2F0(v2);
}

//----- (0056F2F0) --------------------------------------------------------
int __cdecl sub_56F2F0(_DWORD* a1) {
	int v1;     // esi
	__int16 v2; // di
	int result; // eax
	__int16 i;  // ax
	int v5;     // eax

	v1 = dword_5d4594_2516344;
	v2 = 0;
	if (*(_WORD*)&byte_587000[311204]) {
		for (i = nox_common_randomInt_415FA0(0, *(unsigned __int16*)&byte_587000[311204] - 1); v1; ++v2) {
			if (v2 == i)
				break;
			v1 = *(_DWORD*)(v1 + 8);
		}
		a1[3] = *(_DWORD*)(v1 + 12);
		if (!dword_5d4594_2516348)
			nullsub_31(1);
		a1[2] = v1;
		*(_DWORD*)(v1 + 12) = a1;
		v5 = a1[3];
		if (v5) {
			*(_DWORD*)(v5 + 8) = a1;
			++*(_WORD*)&byte_587000[311204];
		} else {
			++*(_WORD*)&byte_587000[311204];
			dword_5d4594_2516344 = a1;
		}
		result = 1;
	} else {
		++*(_WORD*)&byte_587000[311204];
		*(_DWORD*)&byte_5D4594[2516352] = a1;
		dword_5d4594_2516344 = a1;
		result = 1;
	}
	return result;
}
// 560840: using guessed type void __cdecl nullsub_31(_DWORD);

//----- (0056F3B0) --------------------------------------------------------
_DWORD* sub_56F3B0() {
	_DWORD* result; // eax
	_DWORD* v1;     // esi

	result = *(_DWORD**)&dword_5d4594_2516344;
	if (dword_5d4594_2516344) {
		do {
			v1 = (_DWORD*)result[2];
			free(result);
			result = v1;
		} while (v1);
	}
	dword_5d4594_2516328 = 0;
	*(_WORD*)&byte_587000[311204] = 0;
	dword_5d4594_2516348 = 0;
	*(_DWORD*)&byte_5D4594[2516352] = 0;
	dword_5d4594_2516344 = 0;
	return result;
}

//----- (0056F400) --------------------------------------------------------
int __cdecl sub_56F400(int a1) {
	if (sub_56F280(*(int*)&byte_5D4594[2516356], a1))
		return (*(_DWORD*)&byte_5D4594[2516356])++;
	nullsub_31(1);
	return 0;
}
// 560840: using guessed type void __cdecl nullsub_31(_DWORD);

//----- (0056F440) --------------------------------------------------------
int __cdecl sub_56F440(int a1) {
	if (sub_56F480(*(int*)&byte_5D4594[2516356], a1))
		return (*(_DWORD*)&byte_5D4594[2516356])++;
	nullsub_31(1);
	return 0;
}
// 560840: using guessed type void __cdecl nullsub_31(_DWORD);

//----- (0056F480) --------------------------------------------------------
int __cdecl sub_56F480(int a1, int a2) {
	_DWORD* v2; // eax
	int v3;     // ecx
	int v4;     // ecx

	v2 = nox_calloc(1u, 0x10u);
	if (!v2)
		return 0;
	v2[3] = 0;
	v2[2] = 0;
	v3 = a1 ^ dword_5d4594_2516348;
	*v2 = a1 ^ dword_5d4594_2516348;
	dword_5d4594_2516328 ^= v3;
	v2[1] = a2;
	v4 = a2 ^ dword_5d4594_2516348;
	v2[1] = a2 ^ dword_5d4594_2516348;
	dword_5d4594_2516328 ^= v4;
	return sub_56F2F0(v2);
}

//----- (0056F4F0) --------------------------------------------------------
int __cdecl sub_56F4F0(int* a1) {
	int result; // eax

	result = sub_56F510(*a1);
	if (result)
		*a1 = 0;
	return result;
}

//----- (0056F510) --------------------------------------------------------
int __cdecl sub_56F510(int a1) {
	_DWORD* v1; // eax
	int v2;     // ecx
	int v3;     // ecx
	int v4;     // ecx
	int v5;     // ecx

	v1 = sub_56F590(a1);
	if (!v1)
		return 0;
	v2 = v1[3];
	if (v2)
		*(_DWORD*)(v2 + 8) = v1[2];
	else
		dword_5d4594_2516344 = v1[2];
	v3 = v1[2];
	if (v3)
		*(_DWORD*)(v3 + 12) = v1[3];
	else
		*(_DWORD*)&byte_5D4594[2516352] = v1[3];
	v4 = *v1 ^ dword_5d4594_2516328;
	dword_5d4594_2516328 = v4;
	v5 = v1[1] ^ v4;
	--*(_WORD*)&byte_587000[311204];
	dword_5d4594_2516328 = v5;
	free(v1);
	return 1;
}

//----- (0056F590) --------------------------------------------------------
_DWORD* __cdecl sub_56F590(int a1) {
	_DWORD* result; // eax

	result = *(_DWORD**)&dword_5d4594_2516344;
	if (dword_5d4594_2516344) {
		while (*result != (a1 ^ dword_5d4594_2516348)) {
			result = (_DWORD*)result[2];
			if (!result)
				goto LABEL_4;
		}
	} else {
	LABEL_4:
		nullsub_31(1);
		result = 0;
	}
	return result;
}
// 560840: using guessed type void __cdecl nullsub_31(_DWORD);

//----- (0056F5C0) --------------------------------------------------------
int sub_56F5C0() {
	int v0;          // ebx
	int v1;          // edi
	int v2;          // ebx
	int v3;          // edi
	unsigned int v4; // eax
	int i;           // ebp
	int v6;          // esi
	int v7;          // eax
	int* v8;         // eax
	int* v9;         // eax
	int v10;         // ecx
	int v11;         // ebp
	bool v12;        // zf
	int result;      // eax
	int* v14;        // [esp-14h] [ebp-14h]

	if (!dword_5d4594_2516348)
		nullsub_31(1);
	v0 = *(_DWORD*)&byte_5D4594[2598000];
	v1 = dword_5d4594_2516348;
	v2 = sub_56F240() ^ v0;
	v3 = v2 ^ v1;
	dword_5d4594_2516328 = ~v2;
	v4 = *(unsigned __int16*)&byte_587000[311204];
	for (i = 0; i < (*(unsigned __int16*)&byte_587000[311204] >> 2); v4 = *(unsigned __int16*)&byte_587000[311204]) {
		v6 = nox_common_randomInt_415FA0(0, v4 >> 1);
		v7 = nox_common_randomInt_415FA0((*(unsigned __int16*)&byte_587000[311204] >> 1) + 1,
						 *(unsigned __int16*)&byte_587000[311204] - 1);
		if (v6 != v7) {
			v14 = sub_56F6F0(v7);
			v8 = sub_56F6F0(v6);
			sub_56F720(v8, v14);
		}
		++i;
	}
	v9 = *(int**)&dword_5d4594_2516344;
	dword_5d4594_2516348 = 0;
	if (dword_5d4594_2516344) {
		do {
			v10 = v3 ^ *v9;
			v11 = v3 ^ v9[1];
			*v9 = v10;
			v9[1] = v11;
			dword_5d4594_2516328 ^= v10;
			dword_5d4594_2516328 ^= v9[1];
			v9 = (int*)v9[2];
		} while (v9);
	}
	result = v2 ^ dword_5d4594_2516348;
	v12 = v2 == dword_5d4594_2516348;
	++*(_DWORD*)&byte_5D4594[2516364];
	dword_5d4594_2516348 ^= v2;
	if (v12)
		nullsub_31(1);
	return result;
}
// 560840: using guessed type void __cdecl nullsub_31(_DWORD);

//----- (0056F6F0) --------------------------------------------------------
_DWORD* __cdecl sub_56F6F0(int a1) {
	_DWORD* result; // eax
	int v2;         // ecx

	result = *(_DWORD**)&dword_5d4594_2516344;
	v2 = 0;
	if (dword_5d4594_2516344) {
		while (v2 != a1) {
			result = (_DWORD*)result[2];
			++v2;
			if (!result)
				goto LABEL_4;
		}
	} else {
	LABEL_4:
		nullsub_31(1);
		result = 0;
	}
	return result;
}
// 560840: using guessed type void __cdecl nullsub_31(_DWORD);

//----- (0056F720) --------------------------------------------------------
void __cdecl sub_56F720(int* a1, int* a2) {
	int v2; // edx
	int v3; // esi

	if (!a1 || !a2) {
		nullsub_31(1);
		return;
	}
	v2 = *a1;
	v3 = a1[1];
	*a1 = *a2;
	a1[1] = a2[1];
	*a2 = v2;
	a2[1] = v3;
	++*(_DWORD*)&byte_5D4594[2516360];
	if (!dword_5d4594_2516348)
		nullsub_31(1);
}
// 560840: using guessed type void __cdecl nullsub_31(_DWORD);

//----- (0056F780) --------------------------------------------------------
_DWORD* __cdecl sub_56F780(int a1, int a2) {
	_DWORD* result; // eax
	int v3;         // ecx

	result = (_DWORD*)a1;
	if (a1 >= 657757279) {
		result = sub_56F590(a1);
		if (result) {
			dword_5d4594_2516328 ^= result[1];
			v3 = a2 ^ dword_5d4594_2516348;
			result[1] = a2 ^ dword_5d4594_2516348;
			dword_5d4594_2516328 ^= v3;
			result = (_DWORD*)sub_56F5C0();
		}
	}
	return result;
}

//----- (0056F7D0) --------------------------------------------------------
_DWORD* __cdecl sub_56F7D0(int a1, int a2) {
	_DWORD* result; // eax
	int v3;         // ecx

	result = (_DWORD*)a1;
	if (a1 >= 657757279) {
		result = sub_56F590(a1);
		if (result) {
			dword_5d4594_2516328 ^= result[1];
			v3 = a2 ^ dword_5d4594_2516348;
			result[1] = a2 ^ dword_5d4594_2516348;
			dword_5d4594_2516328 ^= v3;
			result = (_DWORD*)sub_56F5C0();
		}
	}
	return result;
}

//----- (0056F820) --------------------------------------------------------
_DWORD* __cdecl sub_56F820(int a1, unsigned __int8 a2) {
	_DWORD* result; // eax
	int v3;         // ecx

	result = (_DWORD*)a1;
	if (a1 >= 657757279) {
		result = sub_56F590(a1);
		if (result) {
			dword_5d4594_2516328 ^= result[1];
			v3 = dword_5d4594_2516348 ^ a2;
			result[1] = v3;
			dword_5d4594_2516328 ^= v3;
			result = (_DWORD*)sub_56F5C0();
		}
	}
	return result;
}

//----- (0056F870) --------------------------------------------------------
_DWORD* __cdecl sub_56F870(int a1, unsigned __int16 a2) {
	_DWORD* result; // eax
	int v3;         // ecx

	result = (_DWORD*)a1;
	if (a1 >= 657757279) {
		result = sub_56F590(a1);
		if (result) {
			dword_5d4594_2516328 ^= result[1];
			v3 = dword_5d4594_2516348 ^ a2;
			result[1] = v3;
			dword_5d4594_2516328 ^= v3;
			result = (_DWORD*)sub_56F5C0();
		}
	}
	return result;
}

//----- (0056F8C0) --------------------------------------------------------
_DWORD* __cdecl sub_56F8C0(int a1, float a2) {
	_DWORD* result; // eax
	_DWORD* v3;     // esi
	int v4;         // eax

	result = (_DWORD*)a1;
	if (a1 >= 657757279) {
		result = sub_56F590(a1);
		v3 = result;
		if (result) {
			dword_5d4594_2516328 ^= result[1];
			v4 = dword_5d4594_2516348 ^ (unsigned __int64)(__int64)a2;
			v3[1] = v4;
			dword_5d4594_2516328 ^= v4;
			result = (_DWORD*)sub_56F5C0();
		}
	}
	return result;
}

//----- (0056F920) --------------------------------------------------------
_DWORD* __cdecl sub_56F920(int a1, int a2) {
	_DWORD* result; // eax
	int v3;         // ecx

	result = (_DWORD*)a1;
	if (a1 >= 657757279) {
		result = sub_56F590(a1);
		if (result) {
			dword_5d4594_2516328 ^= result[1];
			v3 = dword_5d4594_2516348 ^ (a2 + (dword_5d4594_2516348 ^ result[1]));
			result[1] = v3;
			dword_5d4594_2516328 ^= v3;
			result = (_DWORD*)sub_56F5C0();
		}
	}
	return result;
}

//----- (0056F9E0) --------------------------------------------------------
_DWORD* __cdecl sub_56F9E0(int a1, __int16 a2) {
	_DWORD* result; // eax
	int v3;         // ecx

	result = (_DWORD*)a1;
	if (a1 >= 657757279) {
		result = sub_56F590(a1);
		if (result) {
			dword_5d4594_2516328 ^= result[1];
			v3 = dword_5d4594_2516348 ^ (a2 + (dword_5d4594_2516348 ^ result[1]));
			result[1] = v3;
			dword_5d4594_2516328 ^= v3;
			result = (_DWORD*)sub_56F5C0();
		}
	}
	return result;
}

//----- (0056FA40) --------------------------------------------------------
_DWORD* __cdecl sub_56FA40(int a1, float a2) {
	_DWORD* result; // eax
	_DWORD* v3;     // esi
	int v4;         // eax

	result = (_DWORD*)a1;
	if (a1 >= 657757279) {
		result = sub_56F590(a1);
		v3 = result;
		if (result) {
			dword_5d4594_2516328 ^= result[1];
			v4 = dword_5d4594_2516348 ^
			     (unsigned __int64)(__int64)((double)(unsigned int)(dword_5d4594_2516348 ^
										result[1]) +
							 a2);
			v3[1] = v4;
			dword_5d4594_2516328 ^= v4;
			result = (_DWORD*)sub_56F5C0();
		}
	}
	return result;
}

//----- (0056FAC0) --------------------------------------------------------
int __cdecl sub_56FAC0(int* a1, unsigned int a2) {
	int* v2;        // ecx
	int result;     // eax
	unsigned int i; // edx
	int v5;         // esi

	v2 = a1;
	result = 0;
	for (i = a2 >> 2; i; --i) {
		v5 = *v2;
		++v2;
		result ^= v5;
	}
	return result;
}

//----- (0056FAE0) --------------------------------------------------------
int __cdecl sub_56FAE0(int* a1, unsigned int a2) {
	int result; // eax

	result = 0;
	if (a1)
		result = sub_56FAC0(a1, a2);
	return result;
}

//----- (0056FB00) --------------------------------------------------------
int __cdecl sub_56FB00(int* a1, unsigned int a2, int a3) {
	_DWORD* v3; // esi

	if (a3 >= 657757279) {
		v3 = sub_56F590(a3);
		if (v3 && (dword_5d4594_2516348 ^ sub_56FAE0(a1, a2)) == v3[1])
			return 1;
		nullsub_31(1);
	}
	return 0;
}
// 560840: using guessed type void __cdecl nullsub_31(_DWORD);

//----- (0056FB60) --------------------------------------------------------
int __cdecl sub_56FB60(int* a1) {
	int result; // eax
	int v2;     // ebx
	int v3;     // ebx
	int v4;     // ebx
	int* v5;    // edi
	int v6;     // eax
	int* v7;    // eax

	result = 0;
	if (a1) {
		v2 = sub_4E4C00((int)a1);
		v3 = (unsigned __int16)sub_4EE780((int)a1) ^ v2;
		v4 = sub_4E4C10((int)a1) ^ v3;
		v5 = (int*)sub_4E4C30((int)a1);
		v6 = sub_4E4C50((int)a1);
		if (v5 && v6 > 0)
			v4 ^= sub_56FAC0(v5, v6);
		v7 = (int*)sub_4E4C80(a1);
		if (v7) {
			if (strlen((const char*)v7))
				v4 ^= sub_56FAC0(v7, strlen((const char*)v7));
		}
		result = v4;
	}
	return result;
}

//----- (0056FBF0) --------------------------------------------------------
int __cdecl sub_56FBF0(int a1, int* a2) {
	int result; // eax
	_DWORD* v3; // eax
	_DWORD* v4; // esi
	int v5;     // ecx

	result = a1;
	if (a1 >= 657757279) {
		v3 = sub_56F590(a1);
		v4 = v3;
		if (v3) {
			dword_5d4594_2516328 ^= v3[1];
			v5 = sub_56FB60(a2) ^ v3[1];
			v4[1] = v5;
			result = v5 ^ dword_5d4594_2516328;
			dword_5d4594_2516328 ^= v5;
		} else {
			nullsub_31(1);
		}
	}
	return result;
}
// 560840: using guessed type void __cdecl nullsub_31(_DWORD);

//----- (0056FC50) --------------------------------------------------------
int __cdecl sub_56FC50(int a1, int* a2) {
	int result; // eax
	_DWORD* v3; // eax
	_DWORD* v4; // esi
	int v5;     // ecx

	result = a1;
	if (a1 >= 657757279) {
		v3 = sub_56F590(a1);
		v4 = v3;
		if (v3) {
			dword_5d4594_2516328 ^= v3[1];
			v5 = sub_56FB60(a2) ^ v3[1];
			v4[1] = v5;
			result = v5 ^ dword_5d4594_2516328;
			dword_5d4594_2516328 ^= v5;
		} else {
			nullsub_31(1);
		}
	}
	return result;
}
// 560840: using guessed type void __cdecl nullsub_31(_DWORD);

//----- (0056FCB0) --------------------------------------------------------
int __cdecl sub_56FCB0(int a1, int a2) {
	int result; // eax

	result = 0;
	if (a2)
		result = 1 << (a1 % 32);
	return result;
}

//----- (0056FCE0) --------------------------------------------------------
int __cdecl sub_56FCE0(int a1, int a2, int a3) {
	int result; // eax
	_DWORD* v4; // eax
	_DWORD* v5; // esi

	result = a1;
	if (a1 >= 657757279) {
		v4 = sub_56F590(a1);
		v5 = v4;
		if (v4) {
			dword_5d4594_2516328 ^= v4[1];
			result = dword_5d4594_2516348 ^
				 (dword_5d4594_2516348 ^ v4[1] | sub_56FCB0(a2, a3));
			v5[1] = result;
			dword_5d4594_2516328 ^= result;
		} else {
			nullsub_31(1);
		}
	}
	return result;
}
// 560840: using guessed type void __cdecl nullsub_31(_DWORD);

//----- (0056FD50) --------------------------------------------------------
int __cdecl sub_56FD50(int a1, int a2, int a3) {
	int v3;     // ebp
	_DWORD* v4; // eax
	int v5;     // esi
	int* v6;    // edi
	_DWORD* v8; // [esp+8h] [ebp+4h]

	v3 = 0;
	if (a1 >= 657757279) {
		v4 = sub_56F590(a1);
		v8 = v4;
		if (v4) {
			v5 = 1;
			if (a3 > 1) {
				v6 = (int*)(a2 + 4);
				do {
					v3 |= sub_56FCB0(v5++, *v6);
					++v6;
				} while (v5 < a3);
				v4 = v8;
			}
			if ((v3 ^ dword_5d4594_2516348) == v4[1])
				return 1;
		}
		nullsub_31(1);
	}
	return 0;
}
// 560840: using guessed type void __cdecl nullsub_31(_DWORD);

//----- (0056FDD0) --------------------------------------------------------
_BYTE* __cdecl sub_56FDD0(char a1, _BYTE* a2, int a3) {
	_BYTE* result; // eax
	int i;         // ecx

	result = a2;
	if (a2) {
		for (i = a3; i; --i)
			*result++ ^= a1;
	}
	return result;
}

//----- (0056FE00) --------------------------------------------------------
void __cdecl sub_56FE00(char a1, _BYTE* a2, int a3, _BYTE* a4) {
	_BYTE* v4; // esi
	int v5;    // edi
	_BYTE* v6; // eax
	char v7;   // dl

	v4 = a2;
	if (a2) {
		v5 = a3;
		if (a3) {
			v6 = a4;
			if (a4) {
				do {
					v7 = a1 ^ *v4++;
					*v6++ = v7;
					--v5;
				} while (v5);
			}
		}
	}
}

//----- (0056FE30) --------------------------------------------------------
double sub_56FE30() {
	double v0; // st7

	*(_QWORD*)&byte_5D4594[2516412] = *(_QWORD*)&byte_5D4594[2516404];
	*(_QWORD*)&byte_5D4594[2516404] = *(_QWORD*)&byte_5D4594[2516396];
	*(_DWORD*)&byte_5D4594[2516396] = *(_DWORD*)&byte_5D4594[2516388];
	*(_DWORD*)&byte_5D4594[2516400] = *(_DWORD*)&byte_5D4594[2516392];
	v0 = *(double*)&byte_5D4594[2516388] * *(double*)&byte_581450[11376] +
	     *(double*)&byte_5D4594[2516404] * *(double*)&byte_581450[11368] +
	     *(double*)&byte_5D4594[2516412] * *(double*)&byte_581450[11360] +
	     *(double*)&byte_5D4594[2516412] * *(double*)&byte_581450[11352] + *(double*)&byte_5D4594[2516420];
	floor(v0);
	*(double*)&byte_5D4594[2516388] = v0 - v0;
	*(double*)&byte_5D4594[2516420] = v0 * *(double*)&byte_581450[11344];
	return *(double*)&byte_5D4594[2516388];
}

//----- (0056FF00) --------------------------------------------------------
void __cdecl sub_56FF00(int a1) {
	int v1;              // eax
	unsigned __int8* v2; // ecx
	unsigned int v3;     // eax
	int v4;              // esi

	v1 = a1;
	if (!a1)
		v1 = -1;
	v2 = &byte_5D4594[2516388];
	do {
		v2 += 8;
		v3 = (((v1 << 13) ^ (unsigned int)v1) >> 17) ^ (v1 << 13) ^ v1;
		v1 = (32 * v3) ^ v3;
		*((double*)v2 - 1) = (double)(unsigned int)v1 * *(double*)&byte_581450[11344];
	} while ((int)v2 < (int)&byte_5D4594[2516428]);
	v4 = 19;
	do {
		sub_56FE30();
		--v4;
	} while (v4);
	*(_DWORD*)&byte_5D4594[2516380] = 0;
	*(_DWORD*)&byte_5D4594[2516376] = 99;
	*(_DWORD*)&byte_5D4594[2516372] = 100;
}

//----- (0056FF80) --------------------------------------------------------
int __cdecl sub_56FF80(int a1, int a2) {
	__int64 v2; // rax
	int result; // eax

	*(_DWORD*)&byte_5D4594[2516376] = a2;
	*(_DWORD*)&byte_5D4594[2516380] = a1;
	*(_DWORD*)&byte_5D4594[2516372] = a2 - a1 + 1;
	v2 = (__int64)(sub_56FE30() * (double)*(unsigned int*)&byte_5D4594[2516372]);
	if ((unsigned int)v2 < *(int*)&byte_5D4594[2516372])
		result = *(_DWORD*)&byte_5D4594[2516380] + v2;
	else
		result = *(_DWORD*)&byte_5D4594[2516372] + *(_DWORD*)&byte_5D4594[2516380];
	return result;
}

//----- (00578AC0) --------------------------------------------------------
unsigned int __cdecl sub_578AC0(_DWORD* a1) {
	unsigned int result; // eax

	if (!a1)
		return 0;
	if (a1[9] >= 0x8000u)
		return 0;
	result = a1[10];
	if (result >= 0x8000)
		return 0;
	if (!(a1[2] & 0x20400000))
		return a1[9];
	BYTE1(result) |= 0x80u;
	return result;
}

//----- (00578B00) --------------------------------------------------------
unsigned int __cdecl sub_578B00(int a1) {
	unsigned int result; // eax

	if (!a1)
		return 0;
	result = *(_DWORD*)(a1 + 128);
	if (result >= 0x8000)
		return 0;
	if (*(_DWORD*)(a1 + 112) & 0x20400000)
		BYTE1(result) |= 0x80u;
	return result;
}

//----- (00578B30) --------------------------------------------------------
int __cdecl sub_578B30(__int16 a1) { return a1 & 0x7FFF; }

//----- (00578B40) --------------------------------------------------------
int __cdecl sub_578B40(int a1) {
	int result; // eax
	int v2;     // eax

	result = a1;
	if ((a1 & 0x8000) == 0x8000) {
		BYTE1(result) &= 0x7Fu;
		v2 = sub_4ED020(result);
		if (v2)
			result = *(_DWORD*)(v2 + 36);
		else
			result = 0;
	}
	return result;
}

//----- (00578B70) --------------------------------------------------------
unsigned int __cdecl sub_578B70(unsigned int a1) { return (a1 >> 15) & 1; }

//----- (00578B80) --------------------------------------------------------
_DWORD* sub_578B80() {
	_DWORD* v0; // eax
	_DWORD* v2; // esi
	int v3;     // eax

	v0 = operator_new(0x18u);
	if (!v0)
		return 0;
	v2 = v0;
	*v0 = operator_new(0x10000u);
	v2[1] = 0;
	sub_57DF00(v2 + 2);
	v2[5] = operator_new(0x10000u);
	v3 = 0;
	do {
		v3 += 2;
		*(_WORD*)(v3 + v2[5] - 2) = -1;
	} while (v3 < 0x10000);
	return v2;
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (00578BA0) --------------------------------------------------------
unsigned int __cdecl sub_578BA0(unsigned int a1) { return (a1 >> 1) + a1 + 32; }

//----- (00578BB0) --------------------------------------------------------
int __cdecl sub_578BB0(void** a1, int a2, unsigned __int8* a3, int a4) { return sub_57D1C0(a1, a2, a3, a4); }

//----- (00578BD0) --------------------------------------------------------
int __cdecl sub_578BD0(LPVOID lpMem) {
	int result; // eax

	if (lpMem) {
		sub_57D150((LPVOID*)lpMem);
		operator_delete(lpMem);
	}
	return result;
}

//----- (00578BF0) --------------------------------------------------------
_DWORD* sub_578BF0() {
	_DWORD* v0;     // eax
	_DWORD* result; // eax

	v0 = operator_new(0x98u);
	if (v0)
		result = sub_57E9A0(v0);
	else
		result = 0;
	return result;
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (00578C10) --------------------------------------------------------
int __cdecl sub_578C10(_DWORD* a1, _BYTE* a2, _DWORD* a3, unsigned int a4, _DWORD* a5) {
	return sub_57EA80(a1, a2, a3, a4, a5);
}

//----- (00578C30) --------------------------------------------------------
int __cdecl sub_578C30(int a1) { return sub_57EA60(a1); }

//----- (00578C40) --------------------------------------------------------
int __cdecl sub_578C40(LPVOID lpMem) {
	int result; // eax

	if (lpMem) {
		sub_57EA00((LPVOID*)lpMem);
		operator_delete(lpMem);
	}
	return result;
}

//----- (00578C60) --------------------------------------------------------
int sub_578C60() {
	if (sub_44E560()) {
		nox_client_lockScreenBriefing_450160(255, 1, 0);
		sub_4A2530();
	}
	return 1;
}

//----- (00578C90) --------------------------------------------------------
int __cdecl sub_578C90(int a1) {
	*(_DWORD*)&byte_587000[311372] = a1;
	byte_5D4594[2516476] |= 1 << a1;
	sub_44E0B0(1);
	sub_413960();
	sub_477530(0);
	return sub_4460C0();
}

//----- (00578CD0) --------------------------------------------------------
int sub_578CD0() {
	int result;         // eax
	unsigned __int8 v1; // dl
	char* v2;           // edi
	char v3[16];        // [esp+0h] [ebp-90h]
	char v4[128];       // [esp+10h] [ebp-80h]

	result = *(_DWORD*)&byte_587000[311372];
	if (*(int*)&byte_587000[311372] != -1) {
		v1 = byte_587000[311380];
		strcpy(v3, *(const char**)&byte_587000[4 * *(_DWORD*)&byte_587000[311372] + 29456]);
		v2 = &v3[strlen(v3)];
		*(_DWORD*)v2 = *(_DWORD*)&byte_587000[311376];
		v2[4] = v1;
		if (sub_4CB230(v3, v4)) {
			sub_4B0300(v4);
			sub_4B0640(sub_578C60);
			result = sub_4B0340(1);
		} else {
			result = sub_578C60();
		}
	}
	return result;
}
// 578CD0: using guessed type char var_90[16];

//----- (00578D80) --------------------------------------------------------
char* sub_578D80() {
	if (*(_DWORD*)&byte_587000[311372]) {
		if (*(_DWORD*)&byte_587000[311372] == 1) {
			if (!(byte_5D4594[2516476] & 1))
				return (char*)&byte_587000[311416];
			if (!(byte_5D4594[2516476] & 4))
				return (char*)&byte_587000[311432];
		} else if (*(_DWORD*)&byte_587000[311372] == 2) {
			if (!(byte_5D4594[2516476] & 2))
				return (char*)&byte_587000[311448];
			if (!(byte_5D4594[2516476] & 1))
				return (char*)&byte_587000[311464];
		}
	} else {
		if (!(byte_5D4594[2516476] & 2))
			return (char*)&byte_587000[311384];
		if (!(byte_5D4594[2516476] & 4))
			return (char*)&byte_587000[311400];
	}
	return 0;
}

//----- (00578DE0) --------------------------------------------------------
char __cdecl sub_578DE0(char a1) {
	char result; // al

	result = a1;
	byte_5D4594[2516476] = a1;
	return result;
}

//----- (00578DF0) --------------------------------------------------------
unsigned __int8 sub_578DF0() { return byte_5D4594[2516476]; }

//----- (00578E00) --------------------------------------------------------
void sub_578E00() { *(_DWORD*)&byte_587000[311372] = -1; }

//----- (00578E10) --------------------------------------------------------
SOCKET sub_578E10() {
	SOCKET result;        // eax
	unsigned __int8* v1;  // eax
	u_long argp;          // [esp+4h] [ebp-14h]
	struct sockaddr name; // [esp+8h] [ebp-10h]

	*(_WORD*)&name.sa_data[6] = 0;
	*(_DWORD*)&name.sa_data[8] = 0;
	argp = 1;
	name.sa_family = 2;
	*(_WORD*)&name.sa_data[12] = 0;
	*(_WORD*)name.sa_data = htons(*(u_short*)&byte_5D4594[2523736]);
	*(_DWORD*)&name.sa_data[2] = 0;
	result = socket(2, 1, 0);
	*(_DWORD*)&byte_587000[311480] = result;
	if (result != -1) {
		if (bind(result, &name, 16) == -1) {
			result = -2;
		} else if (ioctlsocket(*(SOCKET*)&byte_587000[311480], -2147195266, &argp) == -1) {
			sub_578F20(-5);
			result = -5;
		} else {
			if (listen(*(SOCKET*)&byte_587000[311480], 1) == -1) {
				WSAGetLastError();
				sub_578F20(-3);
			}
			*(_WORD*)&byte_5D4594[2523738] = 0;
			v1 = &byte_5D4594[2516488];
			do {
				*((_DWORD*)v1 - 1) = -1;
				*v1 = 0;
				*((_WORD*)v1 + 512) = 0;
				*((_WORD*)v1 + 513) = 0;
				*((_WORD*)v1 + 514) = 0;
				*((_DWORD*)v1 + 259) = 0;
				v1 += 1044;
			} while ((int)v1 < (int)&byte_5D4594[2520664]);
			result = 0;
		}
	}
	return result;
}

//----- (00578F20) --------------------------------------------------------
int __cdecl sub_578F20(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)&byte_5D4594[2523740] = a1;
	return result;
}

//----- (00579350) --------------------------------------------------------
int __cdecl sub_579350(int a1) {
	int result; // eax

	if (*(int*)&byte_5D4594[1044 * a1 + 2516484] != -1) {
		closesocket(*(_DWORD*)&byte_5D4594[1044 * a1 + 2516484]);
		--*(_WORD*)&byte_5D4594[2523738];
	}
	result = 0;
	*(_DWORD*)&byte_5D4594[1044 * a1 + 2516484] = -1;
	byte_5D4594[1044 * a1 + 2516488] = 0;
	*(_WORD*)&byte_5D4594[1044 * a1 + 2517512] = 0;
	*(_WORD*)&byte_5D4594[1044 * a1 + 2517514] = 0;
	*(_WORD*)&byte_5D4594[1044 * a1 + 2517516] = 0;
	*(_DWORD*)&byte_5D4594[1044 * a1 + 2517524] = 0;
	return result;
}

//----- (00579700) --------------------------------------------------------
int __cdecl sub_579700(int a1) {
	int v1; // eax
	int v2; // edx

	if (!a1)
		return 0;
	v1 = *(__int16*)(a1 + 1028);
	v2 = *(__int16*)(a1 + 1030);
	if (v1 == v2)
		return 0;
	while (*(_BYTE*)(a1 + v1 + 4) != 10) {
		if (++v1 == 1024)
			v1 = 0;
		if (v1 == v2)
			return 0;
	}
	return 1;
}

//----- (00579740) --------------------------------------------------------
BOOL sub_579740() { return *(_WORD*)&byte_5D4594[2523738] != 0; }

//----- (00579750) --------------------------------------------------------
int __cdecl sub_579750(int a1) {
	unsigned __int8* v1; // esi
	unsigned __int8* v2; // edi
	unsigned __int8 v3;  // cl
	SOCKET v4;           // edx
	int result;          // eax

	if (a1) {
		v1 = &byte_5D4594[2516484];
		do {
			if (*(int*)v1 != -1 && !(v1[1040] & 1)) {
				nox_sprintf((char*)&byte_5D4594[2520660], "%S", a1);
				v2 = &byte_5D4594[strlen((const char*)&byte_5D4594[2520660]) + 2520661];
				v3 = byte_587000[312162];
				--v2;
				v4 = *(_DWORD*)v1;
				*(_WORD*)v2 = *(_WORD*)&byte_587000[312160];
				v2[2] = v3;
				result = send(v4, (const char*)&byte_5D4594[2520660],
					      strlen((const char*)&byte_5D4594[2520660]), 0);
			}
			v1 += 1044;
		} while ((int)v1 < (int)&byte_5D4594[2520660]);
	}
	return result;
}

//----- (005797E0) --------------------------------------------------------
int sub_5797E0() { return *(_DWORD*)&byte_5D4594[2523744]; }

//----- (00579860) --------------------------------------------------------
LPVOID sub_579860() { return *(LPVOID*)&dword_5d4594_2523752; }

//----- (00579870) --------------------------------------------------------
int __cdecl sub_579870(int a1) {
	int result; // eax

	if (a1)
		result = *(_DWORD*)(a1 + 484);
	else
		result = 0;
	return result;
}

//----- (00579890) --------------------------------------------------------
int sub_579890() { return dword_5d4594_2523756; }

//----- (005798A0) --------------------------------------------------------
int __cdecl sub_5798A0(int a1) {
	int result; // eax

	if (a1)
		result = *(_DWORD*)(a1 + 484);
	else
		result = 0;
	return result;
}

//----- (005798C0) --------------------------------------------------------
unsigned int sub_5798C0() {
	_DWORD* v0;          // ecx
	unsigned int result; // eax

	v0 = *(_DWORD**)&dword_5d4594_2523752;
	result = 1;
	if (dword_5d4594_2523752) {
		do {
			if (result <= *v0)
				result = *v0 + 1;
			v0 = (_DWORD*)v0[121];
		} while (v0);
	}
	return result;
}

//----- (005798F0) --------------------------------------------------------
_DWORD* __cdecl sub_5798F0(float a1, float a2) {
	_DWORD* v2;      // esi
	unsigned int v3; // eax
	int v4;          // edx

	v2 = nox_calloc(1u, 0x204u);
	v3 = sub_5798C0();
	v4 = v2[120];
	*v2 = v3;
	*((float*)v2 + 2) = a1;
	*((float*)v2 + 3) = a2;
	v2[120] = v4 | 1;
	v2[121] = dword_5d4594_2523752;
	if (dword_5d4594_2523752)
		*(_DWORD*)(dword_5d4594_2523752 + 488) = v2;
	dword_5d4594_2523752 = v2;
	if (nox_common_gameFlags_check_40A5C0(1))
		sub_5179B0((int)v2);
	return v2;
}

//----- (00579970) --------------------------------------------------------
float* __cdecl sub_579970(int a1, float a2, float a3) {
	float* result; // eax
	int v4;        // ecx

	result = (float*)nox_calloc(1u, 0x204u);
	*(_DWORD*)result = a1;
	result[3] = a3;
	v4 = *((_DWORD*)result + 120) | 1;
	result[2] = a2;
	*((_DWORD*)result + 120) = v4;
	result[121] = *(float*)&dword_5d4594_2523756;
	dword_5d4594_2523756 = result;
	return result;
}

//----- (005799C0) --------------------------------------------------------
char* sub_5799C0() {
	int v0; // esi
	int v1; // edi

	v0 = dword_5d4594_2523756;
	if (dword_5d4594_2523756) {
		do {
			v1 = *(_DWORD*)(v0 + 484);
			*(_DWORD*)(v0 + 484) = dword_5d4594_2523752;
			if (dword_5d4594_2523752)
				*(_DWORD*)(dword_5d4594_2523752 + 488) = v0;
			dword_5d4594_2523752 = v0;
			if (nox_common_gameFlags_check_40A5C0(1))
				sub_5179B0(v0);
			v0 = v1;
		} while (v1);
	}
	dword_5d4594_2523756 = 0;
	return sub_579A30();
}

//----- (00579A30) --------------------------------------------------------
char* sub_579A30() {
	char* result; // eax
	char* i;      // esi
	int v2;       // eax
	char* v3;     // ecx
	char v4;      // dl
	char* j;      // eax
	int v6;       // edi
	_BYTE* v7;    // ecx

	result = (char*)sub_579860();
	for (i = result; result; i = result) {
		i[477] = 0;
		v2 = 0;
		if (i[476]) {
			v3 = i + 96;
			do {
				v4 = *v3;
				v3 += 8;
				i[477] |= v4;
				++v2;
			} while (v2 < (unsigned __int8)i[476]);
		}
		for (j = (char*)sub_579860(); j; j = (char*)sub_579870((int)j)) {
			v6 = 0;
			if (j[476]) {
				v7 = j + 96;
				do {
					if (*((char**)v7 - 1) == i)
						i[477] |= *v7;
					++v6;
					v7 += 8;
				} while (v6 < (unsigned __int8)j[476]);
			}
		}
		result = (char*)sub_579870((int)i);
	}
	return result;
}

//----- (00579AD0) --------------------------------------------------------
float* __cdecl sub_579AD0(float a1, float a2) {
	int v2;    // ecx
	int v3;    // edx
	double v4; // st7
	double v5; // st6
	double v6; // st5
	float i;   // [esp+0h] [ebp-4h]

	v2 = dword_5d4594_2523752;
	v3 = 0;
	for (i = 100.0; v2; v2 = *(_DWORD*)(v2 + 484)) {
		v4 = *(float*)(v2 + 8) - a1;
		v5 = *(float*)(v2 + 12) - a2;
		v6 = v5 * v5 + v4 * v4;
		if (v6 < i) {
			i = v6;
			v3 = v2;
		}
	}
	return (float*)v3;
}

//----- (00579B30) --------------------------------------------------------
void __cdecl sub_579B30(LPVOID lpMem) {
	int i;      // ecx
	int v2;     // eax
	int v3;     // edx
	LPVOID* v4; // esi
	int v5;     // esi
	_DWORD* v6; // eax
	int v7;     // eax
	int v8;     // eax

	for (i = dword_5d4594_2523752; i; i = *(_DWORD*)(i + 484)) {
		v2 = 0;
		v3 = *(unsigned __int8*)(i + 476);
		if (v3 > 0) {
			v4 = (LPVOID*)(i + 92);
			while (*v4 != lpMem) {
				++v2;
				v4 += 2;
				if (v2 >= v3)
					goto LABEL_11;
			}
			v5 = v2;
			if (v2 < v3 - 1) {
				v6 = (_DWORD*)(i + 8 * v2 + 92);
				do {
					++v5;
					*v6 = v6[2];
					v6[1] = v6[3];
					v6 += 2;
				} while (v5 < *(unsigned __int8*)(i + 476) - 1);
			}
			--*(_BYTE*)(i + 476);
		}
	LABEL_11:;
	}
	v7 = *((_DWORD*)lpMem + 121);
	if (v7)
		*(_DWORD*)(v7 + 488) = *((_DWORD*)lpMem + 122);
	v8 = *((_DWORD*)lpMem + 122);
	if (v8)
		*(_DWORD*)(v8 + 484) = *((_DWORD*)lpMem + 121);
	else
		dword_5d4594_2523752 = *((_DWORD*)lpMem + 121);
	if (nox_common_gameFlags_check_40A5C0(1))
		sub_517A70((int)lpMem);
	free(lpMem);
}

//----- (00579C00) --------------------------------------------------------
_DWORD* sub_579C00() {
	_DWORD* result; // eax
	_DWORD* v1;     // esi

	result = *(_DWORD**)&dword_5d4594_2523752;
	if (dword_5d4594_2523752) {
		do {
			v1 = (_DWORD*)result[121];
			free(result);
			result = v1;
		} while (v1);
		dword_5d4594_2523752 = 0;
	} else {
		dword_5d4594_2523752 = 0;
	}
	return result;
}

//----- (00579C40) --------------------------------------------------------
_DWORD* __cdecl nox_server_getWaypointById_579C40(int a1) {
	_DWORD* result; // eax

	result = *(_DWORD**)&dword_5d4594_2523752;
	if (!dword_5d4594_2523752)
		return 0;
	while (*result != a1) {
		result = (_DWORD*)result[121];
		if (!result)
			return 0;
	}
	return result;
}

//----- (00579C60) --------------------------------------------------------
int __cdecl sub_579C60(int a1) {
	int result; // eax

	result = dword_5d4594_2523756;
	if (!dword_5d4594_2523756)
		return 0;
	while (*(_DWORD*)(result + 4) != a1) {
		result = *(_DWORD*)(result + 484);
		if (!result)
			return 0;
	}
	return result;
}

//----- (00579C80) --------------------------------------------------------
_DWORD* __cdecl sub_579C80(int a1) {
	_DWORD* result; // eax

	result = *(_DWORD**)&dword_5d4594_2523756;
	if (!dword_5d4594_2523756)
		return 0;
	while (*result != a1) {
		result = (_DWORD*)result[121];
		if (!result)
			return 0;
	}
	return result;
}

//----- (00579CA0) --------------------------------------------------------
int sub_579CA0() {
	_DWORD* v0; // eax
	_DWORD* v1; // esi
	int v2;     // ebp
	int* v3;    // ebx
	int* v4;    // edi
	int v5;     // eax

	v0 = *(_DWORD**)&dword_5d4594_2523756;
	if (dword_5d4594_2523756) {
		do {
			v0[1] = *v0;
			v0 = (_DWORD*)v0[121];
		} while (v0);
		v0 = *(_DWORD**)&dword_5d4594_2523756;
	}
	v1 = v0;
	if (!v0)
		return 1;
	while (1) {
		v2 = 0;
		if (*((_BYTE*)v1 + 476))
			break;
	LABEL_9:
		v1 = (_DWORD*)v1[121];
		if (!v1)
			return 1;
	}
	v3 = v1 + 23;
	v4 = v1 + 87;
	while (1) {
		v5 = sub_579C60(*v4);
		*v3 = v5;
		if (!v5)
			return 0;
		++v2;
		++v4;
		v3 += 2;
		if (v2 >= *((unsigned __int8*)v1 + 476))
			goto LABEL_9;
	}
}

//----- (00579D20) --------------------------------------------------------
int sub_579D20() {
	unsigned int v0;  // eax
	unsigned int* v1; // ecx
	unsigned int v2;  // edx
	unsigned int* v3; // esi
	int v4;           // ebx
	int* v5;          // ebp
	int* v6;          // edi
	int v7;           // eax
	char v9;          // [esp+0h] [ebp-4h]

	v0 = sub_5798C0();
	v1 = *(unsigned int**)&dword_5d4594_2523756;
	if (dword_5d4594_2523756) {
		do {
			v2 = *v1;
			*v1 = v0;
			v1[1] = v2;
			v1 = (unsigned int*)v1[121];
			++v0;
		} while (v1);
		v1 = *(unsigned int**)&dword_5d4594_2523756;
	}
	v3 = v1;
	if (!v1)
		return 1;
	do {
		v4 = 0;
		v9 = 0;
		if (*((_BYTE*)v3 + 476)) {
			v5 = (int*)(v3 + 23);
			v6 = (int*)(v3 + 87);
			do {
				v7 = sub_579C60(*v6);
				*v5 = v7;
				if (v7) {
					v5 += 2;
					++v9;
				}
				++v4;
				++v6;
			} while (v4 < *((unsigned __int8*)v3 + 476));
		}
		*((_BYTE*)v3 + 476) = v9;
		v3 = (unsigned int*)v3[121];
	} while (v3);
	return 1;
}

//----- (00579DD0) --------------------------------------------------------
void sub_579DD0() {
	_DWORD* v0; // esi
	_DWORD* v1; // edi

	v0 = *(_DWORD**)&dword_5d4594_2523752;
	if (dword_5d4594_2523752) {
		do {
			v1 = (_DWORD*)v0[121];
			if (nox_common_gameFlags_check_40A5C0(1))
				sub_517A70((int)v0);
			free(v0);
			v0 = v1;
		} while (v1);
	}
	dword_5d4594_2523752 = 0;
	dword_5d4594_2523756 = 0;
	*(_DWORD*)&byte_5D4594[2523760] = 0;
}

//----- (00579E30) --------------------------------------------------------
const char* __cdecl sub_579E30(const char* a1) {
	const char* i; // esi

	for (i = (const char*)sub_579860(); i; i = (const char*)sub_579870((int)i)) {
		if (nox_server_strcmpWithoutMapname_4DA3F0(i + 16, a1))
			break;
	}
	return i;
}

//----- (00579E70) --------------------------------------------------------
_DWORD* sub_579E70() {
	_DWORD* result; // eax

	result = nox_calloc(1u, 0x204u);
	if (result)
		result[120] |= 0x1000000u;
	return result;
}

//----- (00579E90) --------------------------------------------------------
void __cdecl sub_579E90(int a1) {
	*(_DWORD*)(a1 + 480) |= 0x1000000u;
	*(_DWORD*)(a1 + 484) = dword_5d4594_2523756;
	if (dword_5d4594_2523756)
		*(_DWORD*)(dword_5d4594_2523756 + 488) = a1;
	dword_5d4594_2523756 = a1;
	if (nox_common_gameFlags_check_40A5C0(1))
		sub_5179B0(a1);
}

//----- (00579EE0) --------------------------------------------------------
BOOL __cdecl sub_579EE0(int a1, unsigned __int8 a2) { return (a2 & *(_BYTE*)(a1 + 477)) != 0; }

//----- (00579F00) --------------------------------------------------------
int __cdecl sub_579F00(_DWORD* a1, int a2) {
	int v2;     // ebp
	int v3;     // esi
	_BYTE* i;   // esi
	int v5;     // edi
	LPVOID v6;  // esi
	float* v7;  // edx
	float v8;   // eax
	float v9;   // ecx
	float v10;  // edx
	float4 v12; // [esp+10h] [ebp-10h]

	v2 = 0;
	if (nox_common_gameFlags_check_40A5C0(32)) {
		if (a2) {
			v3 = sub_4DA790();
			if (v3) {
				while (!(*(_DWORD*)(v3 + 8) & 0x10000000) || sub_419150(a2 + 48, v3 + 48)) {
					v3 = sub_4DA7A0(v3);
					if (!v3)
						goto LABEL_9;
				}
				v2 = v3;
			}
		}
	}
LABEL_9:
	*(_DWORD*)&byte_5D4594[2523760] = 0;
	for (i = sub_579860(); i; i = (_BYTE*)sub_579870((int)i)) {
		if (sub_579EE0((int)i, 0x80u) && i[480] & 1)
			++*(_DWORD*)&byte_5D4594[2523760];
	}
	if (!*(_DWORD*)&byte_5D4594[2523760])
		return 0;
	v5 = nox_common_randomInt_415FA0(0, *(_DWORD*)&byte_5D4594[2523760] - 1);
	v6 = sub_579860();
	if (!v6)
		return 0;
	while (1) {
		if (!sub_579EE0((int)v6, 0x80u))
			goto LABEL_24;
		if (!(*((_BYTE*)v6 + 480) & 1))
			goto LABEL_24;
		if (nox_common_gameFlags_check_40A5C0(32)) {
			if (v2) {
				if (a2) {
					v7 = *(float**)(v2 + 748);
					v12.field_0 = *v7;
					v8 = *((float*)v6 + 3);
					v9 = v7[1];
					v10 = *((float*)v6 + 2);
					v12.field_4 = v9;
					v12.field_8 = v10;
					v12.field_C = v8;
					if (sub_535250(&v12, 0, 0, 9) == 1)
						goto LABEL_24;
				}
			}
		}
		if (!v5)
			break;
		--v5;
	LABEL_24:
		v6 = (LPVOID)sub_579870((int)v6);
		if (!v6)
			return 0;
	}
	*a1 = *((_DWORD*)v6 + 2);
	a1[1] = *((_DWORD*)v6 + 3);
	return 1;
}

//----- (0057A160) --------------------------------------------------------
int __cdecl sub_57A160(int a1) {
	int result; // eax

	if (a1 && nox_common_gameFlags_check_40A5C0(2))
		result = (*(_DWORD*)(a1 + 3680) >> 3) & 1;
	else
		result = 0;
	return result;
}

//----- (0057A190) --------------------------------------------------------
int __cdecl sub_57A190(int a1) {
	int result; // eax

	if (a1)
		result = (*(_DWORD*)(a1 + 3680) >> 2) & 1;
	else
		result = 0;
	return result;
}

//----- (0057A1B0) --------------------------------------------------------
char* __cdecl sub_57A1B0(__int16 a1) {
	int v1;              // ecx
	unsigned __int8* v2; // eax

	v1 = 0;
	v2 = &byte_587000[312212];
	while ((a1 & 0x17F0) != *(_DWORD*)v2) {
		v2 += 8;
		++v1;
		if ((int)v2 >= (int)&byte_587000[312268])
			return 0;
	}
	return *(char**)&byte_587000[8 * v1 + 312208];
}

//----- (0057A1E0) --------------------------------------------------------
char __cdecl sub_57A1E0(int* a1, const char* a2, int* a3, char a4, __int16 a5) {
	int* v5;             // esi
	int v6;              // ebx
	unsigned __int8 v7;  // dl
	char* v8;            // edi
	int v9;              // ecx
	int v10;             // eax
	char* v11;           // edi
	unsigned __int8 v12; // cl
	char result;         // al
	char v14[256];       // [esp+14h] [ebp-200h]
	char v15[256];       // [esp+114h] [ebp-100h]

	v5 = a3;
	v6 = a5 & 0x17F0;
	if (a3)
		sub_57ADF0(a3);
	a1[6] = -1;
	a1[7] = -1;
	a1[8] = -1;
	a1[9] = -1;
	a1[10] = -1;
	a1[11] = -1;
	a1[12] = -1;
	if (a4 & 3) {
		v15[0] = 0;
		strcpy(v14, "maps\\");
		strncat(v14, (const char*)a1, 8u);
		*(_WORD*)&v14[strlen(v14)] = *(_WORD*)&byte_587000[312376];
		if (a4 & 2) {
			strcpy(v15, v14);
			if (a2) {
				strcat(v15, a2);
			} else {
				v7 = byte_587000[312388];
				v8 = &v15[strlen(v15) + 1];
				v9 = *(_DWORD*)&byte_587000[312384];
				*(_DWORD*)--v8 = *(_DWORD*)&byte_587000[312380];
				*((_DWORD*)v8 + 1) = v9;
				v8[8] = v7;
			}
			v10 = sub_57A3F0(v15, (int)a1, (int)a3, v6);
			v5 = a3;
		} else {
			v10 = 0;
		}
		if (a4 & 1 && !v10) {
			strncat(v14, (const char*)a1, 8u);
			v11 = &v14[strlen(v14) + 1];
			v12 = byte_587000[312396];
			*(_DWORD*)--v11 = *(_DWORD*)&byte_587000[312392];
			v11[4] = v12;
			sub_57A3F0(v14, (int)a1, (int)v5, v6);
		}
	}
	if (dword_5d4594_2650652 && a4 & 4)
		sub_57A3F0((char*)&byte_587000[312400], (int)a1, (int)v5, v6);
	result = a5;
	if (a5 & 0x40)
		result = sub_453FA0((int)(a1 + 6), 132, 0);
	return result;
}
// 57A1E0: using guessed type char var_100[256];

//----- (0057A3F0) --------------------------------------------------------
int __cdecl sub_57A3F0(char* a1, int a2, int a3, int a4) {
	FILE* v4;        // eax
	FILE* v5;        // esi
	char* v6;        // eax
	char v8[256];    // [esp+4h] [ebp-300h]
	wchar_t v9[256]; // [esp+104h] [ebp-200h]

	*(_DWORD*)&byte_5D4594[2523764] = 6128;
	v4 = fopen(a1, "r");
	v5 = v4;
	if (!v4)
		return 0;
	if (!feof(v4)) {
		do {
			memset(v8, 0, sizeof(v8));
			fgets(v8, 256, v5);
			v6 = strchr(v8, 10);
			if (v6)
				*v6 = 0;
			if (v8[0]) {
				nox_swprintf(v9, L"%S", v8);
				sub_57A4D0(v9, a2, a3, a4);
			}
		} while (!feof(v5));
	}
	fclose(v5);
	return 1;
}

//----- (0057A4D0) --------------------------------------------------------
const wchar_t* __cdecl sub_57A4D0(wchar_t* a1, int a2, int a3, int a4) {
	unsigned __int8 v4;    // bl
	int v5;                // edi
	const wchar_t* result; // eax
	const wchar_t* v7;     // esi
	int v8;                // ecx
	const wchar_t* v9;     // eax
	wchar_t* v10;          // esi
	unsigned __int8 v11;   // [esp+10h] [ebp-284h]
	int v12[32];           // [esp+14h] [ebp-280h]
	wchar_t v13[256];      // [esp+94h] [ebp-200h]

	v4 = 0;
	v5 = 0;
	v11 = 0;
	sub_416580();
	result = nox_wcscpy(v13, a1);
	if (v13) {
		if (v13[0] == 34) {
			result = nox_wcstok(&v13[1], L"\"\n\r");
			v7 = result;
			v5 = 1;
		} else {
			result = nox_wcstok(v13, L" \n\t\r");
			v7 = result;
		}
		if (v7) {
			do {
				v8 = v11;
				v11 = ++v4;
				v12[v8] = (int)v7;
				v9 = &v7[nox_wcslen(v7) + 1];
				if (v5)
					++v9;
				if (*v9 == 34) {
					result = nox_wcstok((wchar_t*)v9 + 1, L"\"\n\r");
					v7 = result;
					v5 = 1;
				} else {
					result = nox_wcstok(0, L" \n\t\r");
					v7 = result;
					v5 = 0;
				}
			} while (v7);
			if (v4) {
				result = (const wchar_t*)sub_57A620(v4, (const wchar_t**)v12, a2, a4);
				if (!result) {
					if (a3) {
						v10 = (wchar_t*)nox_malloc(0x20Cu);
						nox_wcscpy(v10 + 6, a1);
						result = (const wchar_t*)sub_4258E0(a3, v10);
					}
				}
			}
		}
	}
	return result;
}
// 57A4D0: using guessed type int var_280[32];

//----- (0057A620) --------------------------------------------------------
BOOL __cdecl sub_57A620(unsigned __int8 a1, const wchar_t** a2, int a3, int a4) {
	const wchar_t** v4;    // ebp
	unsigned __int8 v5;    // dl
	int v6;                // esi
	unsigned __int16* v8;  // eax
	int v9;                // eax
	int v10;               // ebx
	unsigned __int8 v11;   // cl
	int v12;               // eax
	unsigned __int16* v13; // eax
	int v14;               // esi
	int v15;               // ecx
	char v16[100];         // [esp+10h] [ebp-64h]
	unsigned __int8 v17;   // [esp+7Ch] [ebp+8h]
	unsigned __int8 v18;   // [esp+7Ch] [ebp+8h]

	v4 = a2;
	nox_sprintf(v16, "%S", *a2);
	v5 = 0;
	v17 = 0;
	do {
		if (!strcmp(*(const char**)&byte_587000[8 * v17 + 312208], v16)) {
			*(_DWORD*)&byte_5D4594[2523764] = *(_DWORD*)&byte_587000[8 * v17 + 312212];
			return a4 == *(_DWORD*)&byte_5D4594[2523764];
		}
		v17 = ++v5;
	} while (v5 < 7u);
	if (!(*(_DWORD*)&byte_5D4594[2523764] & a4) || _nox_wcsicmp(*v4, L"set") || a1 <= 1u)
		return 0;
	if (_nox_wcsicmp(v4[1], L"spell")) {
		if (_nox_wcsicmp(v4[1], L"weapon")) {
			if (_nox_wcsicmp(v4[1], L"armor"))
				return 0;
			if (a1 != 4)
				return 0;
			if (!nox_common_gameFlags_check_40A5C0(1))
				return 0;
			nox_sprintf(v16, "%S", v4[2]);
			v13 = (unsigned __int16*)sub_415EC0(v16);
			if (!v13)
				return 0;
			v14 = sub_415D10((char*)*v13);
			if (!v14)
				return 0;
			if (_nox_wcsicmp(v4[3], L"off"))
				v15 = v14 | *(_DWORD*)(a3 + 48);
			else
				v15 = ~v14 & *(_DWORD*)(a3 + 48);
			*(_DWORD*)(a3 + 48) = v15;
		} else {
			if (a1 != 4)
				return 0;
			if (!nox_common_gameFlags_check_40A5C0(1))
				return 0;
			nox_sprintf(v16, "%S", v4[2]);
			v8 = (unsigned __int16*)sub_415A30(v16);
			if (!v8)
				return 0;
			v9 = sub_415880((char*)*v8);
			v10 = v9;
			if (!v9)
				return 0;
			v11 = 0;
			v18 = 0;
			if (v9 > 0) {
				do {
					v12 = v10 >> 8;
					if (v10 >> 8 > 0)
						v10 >>= 8;
					++v11;
				} while (v12 > 0);
				v18 = v11;
			}
			if (_nox_wcsicmp(v4[3], L"off"))
				*(_BYTE*)(v18 + a3 + 43) |= v10;
			else
				*(_BYTE*)(v18 + a3 + 43) &= ~(_BYTE)v10;
		}
	} else {
		if (a1 != 4)
			return 0;
		nox_sprintf(v16, "%S", v4[2]);
		v6 = sub_4243F0(v16);
		if (!v6) {
			v6 = sub_424960((wchar_t*)v4[2]);
			if (!v6)
				return 0;
		}
		if (!sub_424B50(v6))
			return 0;
		if (sub_424A70(v6) & 0x7000000) {
			if (!_nox_wcsicmp(v4[3], L"off"))
				sub_453FA0(a3 + 24, v6, 0);
		}
	}
	if (a4 == *(_DWORD*)&byte_5D4594[2523764])
		return 1;
	return 0;
}

//----- (0057A950) --------------------------------------------------------
int __cdecl sub_57A950(char* a1) {
	char v2[256]; // [esp+Ch] [ebp-100h]

	strcpy(v2, "maps\\");
	strncat(v2, a1, strlen(a1) - 4);
	*(_WORD*)&v2[strlen(v2)] = *(_WORD*)&byte_587000[312564];
	strcat(v2, a1);
	return sub_4D0550(v2);
}

//----- (0057A9F0) --------------------------------------------------------
int __cdecl sub_57A9F0(const char* a1, const char* a2) {
	CHAR FileName[256]; // [esp+Ch] [ebp-100h]

	strcpy(FileName, "maps\\");
	strcat(FileName, a1);
	*(_WORD*)&FileName[strlen(FileName)] = *(_WORD*)&byte_587000[312576];
	strcat(FileName, a2);
	return remove(FileName);
}

//----- (0057AAA0) --------------------------------------------------------
char __cdecl sub_57AAA0(const char* a1, char* a2, int* a3) {
	FILE* v3;           // eax
	FILE* v4;           // ebp
	int* i;             // esi
	char* v6;           // eax
	int v7;             // esi
	int v8;             // edi
	char* v9;           // eax
	int v10;            // esi
	int v11;            // edi
	char* v12;          // eax
	int v13;            // ebx
	int v14;            // esi
	char* v15;          // edi
	char* v16;          // eax
	int v18;            // [esp+10h] [ebp-27Ch]
	char v19[24];       // [esp+14h] [ebp-278h]
	char v20[36];       // [esp+2Ch] [ebp-260h]
	char v21[24];       // [esp+50h] [ebp-23Ch]
	char v22[36];       // [esp+68h] [ebp-224h]
	CHAR v23[256];      // [esp+8Ch] [ebp-200h]
	CHAR FileName[256]; // [esp+18Ch] [ebp-100h]

	LOBYTE(v3) = a2[52];
	if ((char)v3 >= 0) {
		strcpy(FileName, "maps\\");
		strncat(FileName, a2, 8u);
		*(_WORD*)&FileName[strlen(FileName)] = *(_WORD*)&byte_587000[312588];
		strcat(FileName, a1);
		_chmod(FileName, 128);
		v3 = fopen(FileName, "w");
		v4 = v3;
		if (v3) {
			if (dword_5d4594_2650652) {
				strcpy(v21, a2);
				strcpy(v19, a2);
				sub_57A1E0((int*)v21, 0, 0, 4, *((_WORD*)a2 + 26));
				sub_57A1E0((int*)v19, 0, 0, 3, *((_WORD*)a2 + 26));
			}
			if (a3) {
				for (i = sub_425890(a3); i; i = sub_4258A0(i)) {
					nox_sprintf(v23, "%S\n", i + 3);
					fputs(v23, v4);
				}
			}
			v6 = sub_57A1B0(*((_WORD*)a2 + 26));
			fputs(v6, v4);
			fputs("\n", v4);
			v7 = 1;
			v8 = 136;
			do {
				if (sub_424B50(v7) && !sub_454000((int)(a2 + 24), v7) && sub_424A70(v7) & 0x7000000 &&
				    (!dword_5d4594_2650652 || sub_454000((int)v22, v7) ||
				     !sub_454000((int)v20, v7))) {
					v9 = sub_424870(v7);
					nox_sprintf(v23, "%s %s \"%s\" %s\n", &byte_587000[312616],
						    &byte_587000[312608], v9, &byte_587000[312604]);
					fputs(v23, v4);
				}
				++v7;
				--v8;
			} while (v8);
			v10 = 1;
			v11 = 26;
			do {
				if (!(v10 & *((_DWORD*)a2 + 12))) {
					v12 = sub_415E40((char*)v10);
					if (v12) {
						nox_sprintf(v23, "%s %s \"%s\" %s\n", &byte_587000[312648],
							    &byte_587000[312640], v12, &byte_587000[312636]);
						fputs(v23, v4);
					}
				}
				v10 *= 2;
				--v11;
			} while (v11);
			v13 = 1;
			v14 = 1;
			v18 = 27;
			v15 = a2 + 44;
			do {
				if (!((unsigned __int8)v13 & (unsigned __int8)*v15)) {
					v16 = sub_4159B0((char*)v14);
					if (v16) {
						nox_sprintf(v23, "%s %s \"%s\" %s\n", &byte_587000[312680],
							    &byte_587000[312672], v16, &byte_587000[312668]);
						fputs(v23, v4);
					}
				}
				if (v13 == 128) {
					v13 = 1;
					++v15;
				} else {
					v13 *= 2;
				}
				v14 *= 2;
				--v18;
			} while (v18);
			LOBYTE(v3) = fclose(v4);
		}
	}
	return (char)v3;
}

//----- (0057ADF0) --------------------------------------------------------
int* __cdecl sub_57ADF0(int* a1) {
	int* result; // eax
	int* v2;     // esi
	int* v3;     // edi

	result = sub_425890(a1);
	v2 = result;
	if (result) {
		do {
			v3 = sub_4258A0(v2);
			sub_425920((_DWORD**)v2);
			free(v2);
			v2 = v3;
		} while (v3);
	}
	return result;
}

//----- (0057AE30) --------------------------------------------------------
int __cdecl sub_57AE30(const char* a1) {
	int v1;          // ebp
	const char** v2; // edi

	v1 = 0;
	v2 = (const char**)&byte_587000[312208];
	while (strcmp(*v2, a1)) {
		v2 += 2;
		++v1;
		if ((int)v2 >= (int)&byte_587000[312264])
			return 0;
	}
	return *(_DWORD*)&byte_587000[8 * v1 + 312212];
}

//----- (0057AE90) --------------------------------------------------------
void sub_57AE90() { nox_srand(0x9DCu); }

//----- (0057AEA0) --------------------------------------------------------
int __cdecl sub_57AEA0(int a1, int a2) {
	int v2;     // eax
	int result; // eax
	int v4;     // ecx

	v2 = sub_424A70(a2);
	if (a1 == 1) {
		v4 = 0x2000000;
	} else {
		if (a1 != 2)
			return 9;
		v4 = 0x4000000;
	}
	if (v2 & 0x1000000 || v4 & v2)
		result = 0;
	else
		result = 9;
	return result;
}

//----- (0057AEE0) --------------------------------------------------------
BOOL __cdecl sub_57AEE0(int a1, int a2) { return a1 < 75 || a1 > 114 || sub_500D10(a2) <= 4; }

//----- (0057AF10) --------------------------------------------------------
void sub_57AF10() { nox_srand(0x9DDu); }

//----- (0057AF20) --------------------------------------------------------
int sub_57AF20() { return *(_DWORD*)&byte_5D4594[2523804]; }

//----- (0057B0A0) --------------------------------------------------------
void sub_57B0A0() {
	int result; // eax
	_DWORD* v1; // ecx

	result = *(_DWORD*)&byte_5D4594[2523804];
	if (!result) {
		return;
	}
	v1 = *(_DWORD**)&dword_5d4594_2523780;
	if (dword_5d4594_2523780 &&
	    (!*(_DWORD*)&byte_5D4594[2523772] || *(_DWORD*)&byte_5D4594[2523772] == 1)) {
		sub_522FF0(154, (float2*)(dword_5d4594_2523780 + 56));
		v1 = *(_DWORD**)&dword_5d4594_2523780;
	}
	if (*(_DWORD*)&byte_5D4594[2523776]) {
		sub_4E5CC0(*(int*)&byte_5D4594[2523776]);
		v1 = *(_DWORD**)&dword_5d4594_2523780;
	}
	*(_DWORD*)&byte_5D4594[2523776] = 0;
	if (v1)
		sub_4FA020(v1, 13);
	dword_5d4594_2523780 = 0;
	if (!sub_45D9B0())
		sub_413A00(0);
	*(_DWORD*)&byte_5D4594[2523804] = 0;
}

//----- (0057B180) --------------------------------------------------------
__int64 sub_57B180() { return *(_QWORD*)&byte_5D4594[2523788]; }

//----- (0057B190) --------------------------------------------------------
int __cdecl sub_57B190(unsigned __int16 a1, unsigned __int16 a2) {
	int result; // eax
	double v3;  // st7
	double v4;  // st6

	if (!a2)
		return 4;
	if (a1 == a2)
		return 0;
	v3 = (double)a1;
	v4 = (double)a2;
	if (v3 >= v4 * *(double*)&qword_581450_9544)
		return 1;
	result = 2;
	if (v3 < v4 * *(double*)&byte_581450[9608])
		result = 3;
	return result;
}

//----- (0057B200) --------------------------------------------------------
void sub_57B200() {
	*(float*)&byte_5D4594[2523812] = sub_419D40(&byte_587000[312832]);
	*(float*)&byte_5D4594[2523816] = sub_419D40(&byte_587000[312844]);
	*(float*)&byte_5D4594[2523824] = sub_419D40(&byte_587000[312856]);
	*(float*)&byte_5D4594[2523820] = sub_419D40(&byte_587000[312872]);
	*(float*)&byte_5D4594[2523828] = sub_419D40(&byte_587000[312884]) * *(float*)&byte_587000[312784];
	*(float*)&byte_5D4594[2523832] = sub_419D40(&byte_587000[312904]) * *(float*)&byte_587000[312788];
	*(float*)&byte_5D4594[2523840] = sub_419D40(&byte_587000[312920]) * *(float*)&byte_587000[312792];
	*(float*)&byte_5D4594[2523836] = sub_419D40(&byte_587000[312940]) * *(float*)&byte_587000[312796];
	*(float*)&byte_5D4594[2523860] = sub_419D40(&byte_587000[312956]) * *(float*)&byte_587000[312800];
	*(float*)&byte_5D4594[2523864] = sub_419D40(&byte_587000[312976]) * *(float*)&dword_587000_312804;
	*(float*)&byte_5D4594[2523872] = sub_419D40(&byte_587000[312992]) * *(float*)&byte_587000[312808];
	*(float*)&byte_5D4594[2523868] = sub_419D40(&byte_587000[313012]) * *(float*)&byte_587000[312812];
	*(float*)&byte_5D4594[2523844] = sub_419D40(&byte_587000[313032]) * *(float*)&byte_587000[312816];
	*(float*)&byte_5D4594[2523848] = sub_419D40(&byte_587000[313048]) * *(float*)&dword_587000_312820;
	*(float*)&byte_5D4594[2523856] = sub_419D40(&byte_587000[313064]) * *(float*)&byte_587000[312824];
	*(float*)&byte_5D4594[2523852] = sub_419D40(&byte_587000[313084]) * *(float*)&byte_587000[312828];
}

//----- (0057B350) --------------------------------------------------------
float* sub_57B350() { return (float*)&byte_5D4594[2523812]; }

//----- (0057B360) --------------------------------------------------------
float* __cdecl sub_57B360(int a1) { return (float*)&byte_5D4594[16 * a1 + 2523828]; }

//----- (0057B370) --------------------------------------------------------
char __cdecl sub_57B370(int a1, unsigned __int8 a2, int a3) {
	_DWORD* v3;  // eax
	char result; // al

	if (!(a1 & 0x3001010))
		return -1;
	if (a1 & 0x1001000) {
		v3 = sub_413250(a3);
		goto LABEL_4;
	}
	if (a1 & 0x2000000) {
		v3 = sub_413270(a3);
	LABEL_4:
		if (v3)
			result = *((_BYTE*)v3 + 62);
		else
			result = 0;
		return result;
	}
	if (a1 & 0x10)
		result = ~(a2 >> 5) | 0xFE;
	else
		result = a3;
	return result;
}

//----- (0057B3D0) --------------------------------------------------------
BOOL __cdecl sub_57B3D0(int a1, char a2) {
	return ((unsigned __int8)(1 << a2) & (unsigned __int8)sub_57B370(*(_DWORD*)(a1 + 8), *(_DWORD*)(a1 + 12),
									 *(unsigned __int16*)(a1 + 4))) != 0;
}

//----- (0057B400) --------------------------------------------------------
int __cdecl sub_57B400(int a1) {
	int v1; // eax

	v1 = *(_DWORD*)&byte_5D4594[2523876];
	if (!*(_DWORD*)&byte_5D4594[2523876]) {
		v1 = sub_44CFC0((CHAR*)&byte_587000[313100]);
		*(_DWORD*)&byte_5D4594[2523876] = v1;
	}
	if (!*(_DWORD*)&byte_5D4594[2618908])
		return 0;
	if (*(_DWORD*)(a1 + 108) != v1 || *(_BYTE*)(*(_DWORD*)&byte_5D4594[2618908] + 2251) == 1)
		return 1;
	return 0;
}

//----- (0057B450) --------------------------------------------------------
BOOL __cdecl sub_57B450(int* a1) {
	int v1;             // eax
	unsigned __int8 v2; // bl

	v1 = *(_DWORD*)&byte_5D4594[2523880];
	if (!*(_DWORD*)&byte_5D4594[2523880]) {
		v1 = sub_44CFC0((CHAR*)&byte_587000[313108]);
		*(_DWORD*)&byte_5D4594[2523880] = v1;
	}
	if (!a1 || !*(_DWORD*)&byte_5D4594[2614252] || !*(_DWORD*)&byte_5D4594[2618908] ||
	    a1[27] == v1 && *(_BYTE*)(*(_DWORD*)&byte_5D4594[2618908] + 2251) != 1) {
		return 0;
	}
	v2 = 1 << *(_BYTE*)(*(_DWORD*)&byte_5D4594[2618908] + 2251);
	return (v2 & (unsigned __int8)sub_57B370(a1[28], a1[29], a1[27])) != 0;
}

//----- (0057B4D0) --------------------------------------------------------
int __cdecl sub_57B4D0(int a1) {
	int result; // eax

	result = a1;
	if (a1) {
		*(_DWORD*)&byte_5D4594[2523884] = a1;
		*(_DWORD*)&byte_5D4594[2523888] = 1;
	} else {
		*(_DWORD*)&byte_5D4594[2523888] = 0;
	}
	return result;
}

//----- (0057B500) --------------------------------------------------------
char __cdecl sub_57B500(int a1, int a2, char a3) {
	int v3;      // eax
	char v4;     // cl
	int v5;      // esi
	int v6;      // edi
	char result; // al
	int v8;      // eax
	int v9;      // ecx
	bool v10;    // sf
	bool v11;    // cc

	if (a1 < 0)
		return -1;
	if (a1 >= 256)
		return -1;
	if (a2 < 0)
		return -1;
	if (a2 >= 256)
		return -1;
	v3 = sub_4105E0(a1, a2);
	if (!v3)
		return -1;
	v4 = *(_BYTE*)(v3 + 4);
	if (v4 & 0x10) {
		if (!(a3 & 0x10))
			return -1;
		v5 = *(_DWORD*)(v3 + 28);
		if (!v5)
			return -1;
		v6 = *(_DWORD*)(v5 + 748);
		if (a3 & 8) {
			if (!*(_BYTE*)(v6 + 1))
				return -1;
			if (*(_DWORD*)&byte_5D4594[2523888] && sub_4E8910(*(int*)&byte_5D4594[2523884], v5)) {
				*(_DWORD*)&byte_5D4594[2523888] = 0;
				return -1;
			}
		}
		if (a3 >= 0 && *(_BYTE*)(v5 + 12) & 4)
			return -1;
		v8 = *(_DWORD*)(v6 + 12);
		if (v8 != *(_DWORD*)(v6 + 4))
			return -1;
		v9 = *(int*)&byte_587000[8 * v8 + 196184];
		v10 = v9 < 0;
		v11 = v9 <= 0;
		if (v9 > 0) {
			if (*(int*)&byte_587000[8 * v8 + 196188] > 0)
				return 1;
			v10 = v9 < 0;
			v11 = v9 <= 0;
		}
		if (v10) {
			if (*(int*)&byte_587000[8 * v8 + 196188] < 0)
				return 1;
			v11 = v9 <= 0;
			if (v9 < 0) {
				if (*(int*)&byte_587000[8 * v8 + 196188] > 0)
					return 0;
				v11 = v9 <= 0;
			}
		}
		if (v11 || *(int*)&byte_587000[8 * v8 + 196188] >= 0)
			return -1;
		result = 0;
	} else {
		if (!(a3 & 0x40) && v4 & 0x40 || v4 & 4 && *(_BYTE*)(*(_DWORD*)(v3 + 28) + 22) > 0xBu)
			return -1;
		result = *(_BYTE*)v3;
	}
	return result;
}

//----- (0057B630) --------------------------------------------------------
char __cdecl sub_57B630(int a1, int a2, int a3) {
	int v3;   // eax
	char v4;  // cl
	int v5;   // eax
	int v6;   // esi
	int v7;   // ecx
	int v8;   // edx
	bool v9;  // sf
	bool v10; // cc
	char v11; // bl
	int v13;  // ecx

	if (a2 >= 0 && a2 < 256 && (a3 >= 0 || a3 < 256)) {
		v3 = sub_4105E0(a2, a3);
		if (v3) {
			v4 = *(_BYTE*)(v3 + 4);
			if (v4 & 0x10) {
				v5 = *(_DWORD*)(v3 + 28);
				if (v5) {
					v6 = *(_DWORD*)(v5 + 748);
					v7 = *(_DWORD*)(v6 + 12);
					if (v7 == *(int*)(v6 + 4)) {
						v8 = *(int*)&byte_587000[8 * v7 + 196184];
						v9 = v8 < 0;
						v10 = v8 <= 0;
						if (v8 > 0) {
							if (*(int*)&byte_587000[8 * v7 + 196188] > 0) {
								v11 = 1;
								goto LABEL_22;
							}
							v9 = v8 < 0;
							v10 = v8 <= 0;
						}
						if (v9) {
							if (*(int*)&byte_587000[8 * v7 + 196188] < 0) {
								v11 = 1;
								goto LABEL_22;
							}
							v10 = v8 <= 0;
							if (v8 < 0) {
								if (*(int*)&byte_587000[8 * v7 + 196188] > 0) {
								LABEL_21:
									v11 = 0;
								LABEL_22:
									if (*(_DWORD*)(v5 + 508)) {
										if (nox_common_randomInt_415FA0(
											0, 100) >= 50)
											return v11;
									} else if (*(_BYTE*)(v6 + 1) &&
										   !sub_4E8910(a1, v5)) {
										return v11;
									}
									return -1;
								}
								v10 = v8 <= 0;
							}
						}
						if (!v10 && *(int*)&byte_587000[8 * v7 + 196188] < 0)
							goto LABEL_21;
					}
				}
			} else if (!(*(_DWORD*)(a1 + 16) & 0x4000) || !(v4 & 0x40)) {
				if (!(v4 & 4))
					return *(_BYTE*)v3;
				v13 = *(_DWORD*)(v3 + 28);
				if (!(*(_BYTE*)(v13 + 20) & 2) && *(_BYTE*)(v13 + 22) <= 0xBu)
					return *(_BYTE*)v3;
			}
		}
	}
	return -1;
}

//----- (0057B770) --------------------------------------------------------
float2* __cdecl sub_57B770(float2* a1, float2* a2) {
	float2* result; // eax
	long double v3; // st5
	long double v4; // st7
	double v5;      // st6
	long double v6; // st5
	float v7;       // [esp+0h] [ebp-18h]
	float v8;       // [esp+4h] [ebp-14h]
	float v9;       // [esp+Ch] [ebp-Ch]
	float v10;      // [esp+10h] [ebp-8h]
	float v11;      // [esp+20h] [ebp+8h]

	result = a2;
	v9 = a2->field_0;
	v3 = sqrt(a2->field_0 * a2->field_0 + a2->field_4 * a2->field_4);
	v4 = v3 + 0.1;
	v5 = -a2->field_4;
	v6 = (a1->field_0 * a2->field_0 + a1->field_4 * a2->field_4) / (v3 + 0.1);
	v11 = (a2->field_0 * a1->field_4 + v5 * a1->field_0) / v4;
	v7 = v6 * result->field_0 / v4;
	v8 = v6 * result->field_4 / v4;
	v10 = v11 * v5 / v4;
	a1->field_0 = v10 - v7;
	a1->field_4 = v11 * v9 / v4 - v8;
	return result;
}

//----- (0057B810) --------------------------------------------------------
int __cdecl sub_57B810(float* a1, int a2) {
	int result; // eax
	double v3;  // st7
	int v4;     // ecx

	result = a2;
	v3 = *(float*)a2;
	if (a1[1] * *a1 <= 0.0) {
		v4 = *(_DWORD*)(a2 + 4);
		*(float*)(a2 + 4) = *(float*)a2;
		*(_DWORD*)a2 = v4;
	} else {
		*(float*)a2 = -*(float*)(a2 + 4);
		*(float*)(a2 + 4) = -v3;
	}
	return result;
}

//----- (0057B850) --------------------------------------------------------
BOOL __cdecl sub_57B850(float2* a1, float* a2, float2* a3) {
	BOOL result; // eax
	float v4;    // [esp+0h] [ebp-10h]
	float v5;    // [esp+4h] [ebp-Ch]
	float v6;    // [esp+8h] [ebp-8h]
	float v7;    // [esp+Ch] [ebp-4h]

	v4 = a2[5] + a1->field_0;
	v5 = a2[6] + a1->field_4;
	result = 0;
	if ((v5 - v4 + a3->field_0 - a3->field_4) * 0.70709997 < 0.0 &&
	    (a2[8] + a1->field_4 - (a2[7] + a1->field_0) + a3->field_0 - a3->field_4) * 0.70709997 > 0.0) {
		v6 = a2[9] + a1->field_0;
		v7 = a2[10] + a1->field_4;
		if ((v7 + v6 - a3->field_0 - a3->field_4) * 0.70709997 > 0.0 &&
		    (v5 + v4 - a3->field_0 - a3->field_4) * 0.70709997 < 0.0) {
			result = 1;
		}
	}
	return result;
}

//----- (0057B920) --------------------------------------------------------
int __cdecl sub_57B920(void* a1) {
	int result; // eax

	result = 0;
	memset(a1, 0, 0x7F8u);
	return result;
}

//----- (0057B930) --------------------------------------------------------
char __cdecl sub_57B930(int a1, int a2, int a3, unsigned int a4) {
	int v4; // eax
	int v5; // edx

	v4 = (unsigned __int8)a2;
	v5 = (unsigned __int8)a2;
	if ((unsigned __int8)a2 == 255 || !(_BYTE)a2) {
		v4 = 1;
		v5 = 1;
	}
	while (*(unsigned __int16*)(a1 + 8 * v4) != a2 || *(unsigned __int16*)(a1 + 8 * v4 + 2) != a3) {
		if (++v4 == 255)
			v4 = 1;
		if (v4 == v5)
			goto LABEL_11;
	}
	if (*(_DWORD*)(a1 + 8 * v4 + 4) >= a4)
		return v4;
LABEL_11:
	LOBYTE(v4) = -1;
	return v4;
}

//----- (0057B9A0) --------------------------------------------------------
char __cdecl sub_57B9A0(int a1, int a2, int a3, unsigned int a4) {
	int v4; // eax
	int v5; // edx

	v4 = (unsigned __int8)a2;
	v5 = (unsigned __int8)a2;
	if ((unsigned __int8)a2 == 255 || !(_BYTE)a2) {
		v4 = 1;
		v5 = 1;
	}
	while ((*(unsigned __int16*)(a1 + 8 * v4) != a2 || *(unsigned __int16*)(a1 + 8 * v4 + 2) != a3) &&
	       *(_DWORD*)(a1 + 8 * v4 + 4) >= a4) {
		if (++v4 == 255)
			v4 = 1;
		if (v4 == v5) {
			LOBYTE(v4) = -1;
			return v4;
		}
	}
	return v4;
}

//----- (0057BA10) --------------------------------------------------------
int __cdecl sub_57BA10(int a1, __int16 a2, __int16 a3, int a4) {
	int result; // eax

	result = a1;
	*(_WORD*)a1 = a2;
	*(_WORD*)(a1 + 2) = a3;
	*(_DWORD*)(a1 + 4) = a4;
	return result;
}

//----- (0057BA30) --------------------------------------------------------
int __cdecl sub_57BA30(int2* a1, int2* a2, int4* a3) {
	int v3;     // eax
	int v4;     // edx
	int v5;     // ebx
	int v6;     // edx
	int v7;     // ebp
	int v8;     // ebx
	int result; // eax
	int v10;    // edx
	int v11;    // edi
	BOOL v12;   // [esp+10h] [ebp-4h]

	v12 = 0;
	while (1) {
		if (a1->field_0 >= a3->field_0)
			v3 = a1->field_0 <= a3->field_8 ? 0 : 4;
		else
			v3 = 8;
		v4 = a1->field_4;
		v5 = a3->field_4;
		if (v4 >= v5) {
			if (v4 > a3->field_C)
				LOBYTE(v3) = v3 | 1;
		} else {
			LOBYTE(v3) = v3 | 2;
		}
		if (a2->field_0 >= a3->field_0)
			v6 = a2->field_0 <= a3->field_8 ? 0 : 4;
		else
			v6 = 8;
		v7 = a2->field_4;
		if (v7 >= v5) {
			if (v7 > a3->field_C)
				v6 |= 1u;
		} else {
			v6 |= 2u;
		}
		if (v6 & v3) {
			result = 0;
			goto LABEL_30;
		}
		if (!v3)
			break;
	LABEL_20:
		if (v3 & 1) {
			a1->field_0 +=
			    (a3->field_C - a1->field_4) * (a2->field_0 - a1->field_0) / (a2->field_4 - a1->field_4);
			a1->field_4 = a3->field_C;
		} else if (v3 & 2) {
			a1->field_0 +=
			    (a3->field_4 - a1->field_4) * (a2->field_0 - a1->field_0) / (a2->field_4 - a1->field_4);
			a1->field_4 = a3->field_4;
		} else if (v3 & 4) {
			a1->field_4 +=
			    (a3->field_8 - a1->field_0) * (a2->field_4 - a1->field_4) / (a2->field_0 - a1->field_0);
			a1->field_0 = a3->field_8;
		} else if (v3 & 8) {
			a1->field_4 +=
			    (a2->field_4 - a1->field_4) * (a3->field_0 - a1->field_0) / (a2->field_0 - a1->field_0);
			a1->field_0 = a3->field_0;
		}
	}
	if (v6) {
		v3 = a1->field_0;
		v8 = a1->field_4;
		*a1 = *a2;
		a2->field_0 = v3;
		a2->field_4 = v8;
		LOBYTE(v3) = v6;
		v12 = !v12;
		goto LABEL_20;
	}
	result = 1;
LABEL_30:
	if (v12) {
		v10 = a1->field_0;
		v11 = a1->field_4;
		*a1 = *a2;
		a2->field_0 = v10;
		a2->field_4 = v11;
	}
	return result;
}

//----- (0057BBC0) --------------------------------------------------------
int __cdecl sub_57BBC0(FILE* a1, int a2, int a3) {
	int v3;     // esi
	int v4;     // ebx
	char v5;    // al
	int v6;     // eax
	int result; // eax

	v3 = 0;
	v4 = 1;
	if (a3 <= 0) {
	LABEL_11:
		result = a3;
		*(_BYTE*)(a2 + a3 - 1) = 0;
		return result;
	}
	while (1) {
		v5 = fgetc(a1);
		*(_BYTE*)(v3 + a2) = v5;
		v6 = isspace(v5);
		if (!v6)
			break;
		if (!v4) {
			*(_BYTE*)(v3 + a2) = 32;
		LABEL_9:
			++v3;
		}
		if (v3 >= a3)
			goto LABEL_11;
	}
	result = *(unsigned __int8*)(v3 + a2);
	v4 = 0;
	if ((_BYTE)result != 59)
		goto LABEL_9;
	*(_BYTE*)(v3 + a2) = 0;
	return result;
}

//----- (0057BC50) --------------------------------------------------------
int __cdecl sub_57BC50(char* a1, char* a2) {
	FILE* v2;   // eax
	FILE* v3;   // edi
	int v4;     // esi
	char* v5;   // esi
	char* v6;   // ebx
	char* v7;   // eax
	char* v8;   // ebp
	_DWORD* v9; // edi
	FILE* v10;  // esi
	size_t v12; // [esp+10h] [ebp-8h]
	size_t v13; // [esp+14h] [ebp-4h]

	v12 = 0;
	if (!a1)
		return 0;
	if (!a2)
		return 0;
	v2 = fopen(a1, "rb");
	v3 = v2;
	if (!v2)
		return 0;
	fseek(v2, 0, 2);
	v4 = ftell(v3);
	fseek(v3, 0, 0);
	v5 = (char*)(v4 - 4);
	sub_40ADD0_fread((char*)&v12, 1u, 4u, v3);
	v6 = (char*)nox_malloc((size_t)v5);
	v7 = (char*)nox_malloc(v12);
	v8 = v7;
	if (!v6 || !v7)
		return 0;
	sub_40ADD0_fread(v6, 1u, (size_t)v5, v3);
	fclose(v3);
	a1 = v5;
	v13 = v12;
	v9 = sub_578BF0();
	if (sub_578C10(v9, &v8[v12 - v13], &v13, (unsigned int)&v5[v6 - a1], &a1)) {
		while ((int)a1 > 0 && sub_578C10(v9, &v8[v12 - v13], &v13, (unsigned int)&v5[v6 - a1], &a1))
			;
	}
	sub_578C40(v9);
	v10 = fopen(a2, "wb");
	if (!v10)
		return 0;
	fwrite(v8, v12, 1u, v10);
	fclose(v10);
	free(v6);
	free(v8);
	return 1;
}

//----- (0057BDD0) --------------------------------------------------------
int __cdecl sub_57BDD0(LPVOID lpMem, int a2) {
	size_t v2;        // ebx
	FILE* v3;         // eax
	FILE* v4;         // esi
	char* v5;         // edi
	unsigned int v6;  // eax
	void* v7;         // eax
	void** v8;        // ebp
	size_t v9;        // eax
	size_t i;         // esi
	unsigned int v11; // eax
	FILE* v12;        // eax
	FILE* v13;        // esi
	size_t v15;       // [esp+Ch] [ebp-4h]
	void* lpMema;     // [esp+14h] [ebp+4h]

	v2 = 0;
	v15 = 0;
	if (!lpMem)
		return 0;
	if (!a2)
		return 0;
	v3 = fopen((const char*)lpMem, "rb");
	v4 = v3;
	if (!v3)
		return 0;
	fseek(v3, 0, 2);
	v15 = ftell(v4);
	fseek(v4, 0, 0);
	v5 = (char*)nox_malloc(v15);
	v6 = sub_578BA0(v15);
	v7 = nox_malloc(v6);
	lpMema = v7;
	if (!v5 || !v7)
		return 0;
	sub_40ADD0_fread(v5, 1u, v15, v4);
	fclose(v4);
	v8 = (void**)sub_578B80();
	v9 = v15;
	for (i = 0; i < v15; i += 500000) {
		v11 = v9 - i;
		if (v11 > 0x7A120)
			v11 = 500000;
		v2 += sub_578BB0(v8, (int)lpMema + v2, (unsigned __int8*)&v5[i], v11);
		v9 = v15;
	}
	sub_578BD0(v8);
	v12 = fopen((const char*)a2, "wb");
	v13 = v12;
	if (!v12)
		return 0;
	fwrite(&v15, 4u, 1u, v12);
	fwrite(lpMema, v2, 1u, v13);
	fclose(v13);
	free(v5);
	free(lpMema);
	return 1;
}

//----- (0057BF20) --------------------------------------------------------
BOOL __cdecl sub_57BF20(int a1, int a2) { return a1 && a2; }

//----- (0057BF40) --------------------------------------------------------
BOOL __cdecl sub_57BF40(int a1, int a2) { return a1 && a2; }

//----- (0057BF60) --------------------------------------------------------
int sub_57BF60() { return 0; }

//----- (0057BF70) --------------------------------------------------------
int sub_57BF70() { return *(_DWORD*)&byte_5D4594[2523904]; }

//----- (0057BF80) --------------------------------------------------------
unsigned int sub_57BF80() {
	unsigned int v0; // esi
	int i;           // eax
	unsigned int v2; // ecx

	v0 = 0;
	for (i = nox_server_getFirstMapGroup_57C080(); i; i = nox_server_getNextMapGroup_57C090(i)) {
		v2 = *(_DWORD*)(i + 4);
		if (v2 >= v0)
			v0 = v2 + 1;
	}
	return v0;
}

//----- (0057BFB0) --------------------------------------------------------
char* sub_57BFB0() {
	char* result; // eax

	*(_DWORD*)&byte_5D4594[2523904] = 0;
	result = nox_new_alloc_class("ItemGroupInfo", 96, 512);
	*(_DWORD*)&byte_5D4594[2523892] = result;
	if (result) {
		*(_DWORD*)&byte_5D4594[2523896] = nox_new_alloc_class("ItemGroupElement", 16, 5000);
		result = (char*)(*(_DWORD*)&byte_5D4594[2523896] != 0);
	}
	return result;
}

//----- (0057C000) --------------------------------------------------------
void sub_57C000() {
	*(_DWORD*)&byte_5D4594[2523904] = 0;
	sub_4144D0(*(_DWORD**)&byte_5D4594[2523896]);
	sub_4144D0(*(_DWORD**)&byte_5D4594[2523892]);
	dword_5d4594_2523900 = 0;
}

//----- (0057C030) --------------------------------------------------------
int sub_57C030() {
	*(_DWORD*)&byte_5D4594[2523904] = 0;
	if (*(_DWORD*)&byte_5D4594[2523892]) {
		nox_free_alloc_class(*(LPVOID*)&byte_5D4594[2523892]);
		*(_DWORD*)&byte_5D4594[2523892] = 0;
	}
	if (*(_DWORD*)&byte_5D4594[2523896]) {
		nox_free_alloc_class(*(LPVOID*)&byte_5D4594[2523896]);
		*(_DWORD*)&byte_5D4594[2523896] = 0;
	}
	dword_5d4594_2523900 = 0;
	return 1;
}

//----- (0057C080) --------------------------------------------------------
int nox_server_getFirstMapGroup_57C080() { return dword_5d4594_2523900; }

//----- (0057C090) --------------------------------------------------------
int __cdecl nox_server_getNextMapGroup_57C090(int a1) {
	int result; // eax

	if (a1)
		result = *(_DWORD*)(a1 + 88);
	else
		result = 0;
	return result;
}

//----- (0057C0A0) --------------------------------------------------------
int __cdecl nox_server_scriptGetGroup_57C0A0(int a1) {
	int result; // eax

	result = dword_5d4594_2523900;
	if (!dword_5d4594_2523900)
		return 0;
	while (*(_DWORD*)(result + 4) != a1) {
		result = *(_DWORD*)(result + 88);
		if (!result)
			return 0;
	}
	return result;
}

//----- (0057C0C0) --------------------------------------------------------
int __cdecl nox_server_mapLoadAddGroup_57C0C0(char* a1, int a2, char a3) {
	int result; // eax
	int v4;     // esi
	int v5;     // ecx

	result = (int)sub_57C330();
	v4 = result;
	if (result) {
		*(_DWORD*)(result + 4) = a2;
		*(_BYTE*)result = a3;
		strncpy((char*)(result + 8), a1, 0x4Cu);
		*(_BYTE*)(v4 + 83) = 0;
		*(_DWORD*)(v4 + 84) = 0;
		v5 = dword_5d4594_2523900;
		*(_DWORD*)(v4 + 92) = 0;
		*(_DWORD*)(v4 + 88) = v5;
		if (dword_5d4594_2523900)
			*(_DWORD*)(dword_5d4594_2523900 + 92) = v4;
		dword_5d4594_2523900 = v4;
		result = 1;
	}
	return result;
}

//----- (0057C130) --------------------------------------------------------
int __cdecl sub_57C130(_DWORD* a1, int a2) {
	int result; // eax
	char* v3;   // esi
	char v4;    // bl
	int v5;     // edx
	int v6;     // ecx

	if (!a1)
		return 0;
	v3 = *(char**)&dword_5d4594_2523900;
	if (!dword_5d4594_2523900)
		return 0;
	while (*((_DWORD*)v3 + 1) != a2) {
		v3 = (char*)*((_DWORD*)v3 + 22);
		if (!v3)
			return 0;
	}
	if (!v3)
		return 0;
	v4 = *v3;
	result = (int)sub_57C360();
	if (result) {
		if (v4 && v4 != 1 && v4 != 3) {
			if (v4 != 2) {
				sub_414330(*(unsigned int**)&byte_5D4594[2523896], (_QWORD*)result);
				return 0;
			}
			*(_DWORD*)result = *a1;
			*(_DWORD*)(result + 4) = a1[1];
		} else {
			*(_DWORD*)result = *a1;
		}
		v5 = *((_DWORD*)v3 + 21);
		*(_DWORD*)(result + 12) = 0;
		*(_DWORD*)(result + 8) = v5;
		v6 = *((_DWORD*)v3 + 21);
		if (v6)
			*(_DWORD*)(v6 + 12) = result;
		*((_DWORD*)v3 + 21) = result;
		result = 1;
	}
	return result;
}

//----- (0057C1E0) --------------------------------------------------------
int __cdecl sub_57C1E0(_DWORD* a1, int a2) {
	int v2;   // ebx
	char* v3; // ebp
	int i;    // esi
	char v5;  // al
	int v7;   // eax

	v2 = 0;
	v3 = *(char**)&dword_5d4594_2523900;
	if (!dword_5d4594_2523900)
		return 0;
	while (*(_DWORD*)(dword_5d4594_2523900 + 4) != a2)
		;
	for (i = *(_DWORD*)(dword_5d4594_2523900 + 84); i; i = *(_DWORD*)(i + 8)) {
		v5 = *v3;
		if (*v3 && v5 != 1 && v5 != 3) {
			if (v5 == 2 && *(_DWORD*)i == *a1 && *(_DWORD*)(i + 4) == a1[1]) {
				v2 = 1;
			LABEL_15:
				if (*(_DWORD*)(i + 12))
					*(_DWORD*)(i + 12) = *(_DWORD*)(i + 8);
				v7 = *(_DWORD*)(i + 8);
				if (v7)
					*(_DWORD*)(v7 + 12) = *(_DWORD*)(i + 12);
				sub_57C390((_QWORD*)i);
				continue;
			}
		} else if (*(_DWORD*)i == *a1) {
			v2 = 1;
			goto LABEL_15;
		}
		if (v2 == 1)
			goto LABEL_15;
	}
	return v2;
}

//----- (0057C280) --------------------------------------------------------
int __cdecl nox_server_scriptGetMapGroupByName_57C280(const char* a1, int a2) {
	int i; // esi

	for (i = nox_server_getFirstMapGroup_57C080(); i; i = nox_server_getNextMapGroup_57C090(i)) {
		if (a2 == nox_server_scriptGetGroupId_57C2D0((int**)i) && nox_server_strcmpWithoutMapname_4DA3F0((const char*)(i + 8), a1))
			break;
	}
	return i;
}

//----- (0057C330) --------------------------------------------------------
void* sub_57C330() {
	void* v0;     // esi
	void* result; // eax

	v0 = 0;
	if (!nox_common_gameFlags_check_40A5C0(2097153) ||
	    (result = nox_alloc_class_new_obj_zero(*(_DWORD**)&byte_5D4594[2523892]), (v0 = result) != 0))
		result = v0;
	return result;
}

//----- (0057C360) --------------------------------------------------------
void* sub_57C360() { return nox_alloc_class_new_obj_zero(*(_DWORD**)&byte_5D4594[2523896]); }

//----- (0057C370) --------------------------------------------------------
void __cdecl sub_57C370(_QWORD* a1) { sub_414330(*(unsigned int**)&byte_5D4594[2523892], a1); }

//----- (0057C390) --------------------------------------------------------
void __cdecl sub_57C390(_QWORD* a1) { sub_414330(*(unsigned int**)&byte_5D4594[2523896], a1); }

//----- (0057C3B0) --------------------------------------------------------
int __cdecl nox_server_addNewMapGroup_57C3B0(int a1) {
	int result; // eax

	result = a1;
	*(_DWORD*)(a1 + 92) = 0;
	*(_DWORD*)(a1 + 88) = dword_5d4594_2523900;
	if (dword_5d4594_2523900)
		*(_DWORD*)(dword_5d4594_2523900 + 92) = a1;
	dword_5d4594_2523900 = a1;
	return result;
}

//----- (0057C3E0) --------------------------------------------------------
int sub_57C3E0() { return dword_5d4594_2523912; }

//----- (0057C3F0) --------------------------------------------------------
int __cdecl sub_57C3F0(int a1) {
	int result; // eax

	if (a1)
		result = *(_DWORD*)(a1 + 336);
	else
		result = 0;
	return result;
}

//----- (0057C410) --------------------------------------------------------
BOOL sub_57C410() {
	*(_DWORD*)&byte_5D4594[2523908] = nox_new_alloc_class("DebugData", 344, 256);
	return *(_DWORD*)&byte_5D4594[2523908] != 0;
}

//----- (0057C440) --------------------------------------------------------
void sub_57C440() {
	sub_4144D0(*(_DWORD**)&byte_5D4594[2523908]);
	dword_5d4594_2523912 = 0;
}

//----- (0057C460) --------------------------------------------------------
int sub_57C460() {
	if (*(_DWORD*)&byte_5D4594[2523908]) {
		nox_free_alloc_class(*(LPVOID*)&byte_5D4594[2523908]);
		*(_DWORD*)&byte_5D4594[2523908] = 0;
	}
	dword_5d4594_2523912 = 0;
	return 1;
}

//----- (0057C490) --------------------------------------------------------
int __cdecl sub_57C490(const char* a1) {
	int v1; // edi

	v1 = dword_5d4594_2523912;
	if (!dword_5d4594_2523912)
		return 0;
	while (strcmp(a1, (const char*)v1)) {
		v1 = *(_DWORD*)(v1 + 336);
		if (!v1)
			return 0;
	}
	return v1 + 80;
}

//----- (0057C500) --------------------------------------------------------
int __cdecl sub_57C500(const char* a1, const char* a2) {
	char* v2; // edx

	v2 = (char*)nox_alloc_class_new_obj_zero(*(_DWORD**)&byte_5D4594[2523908]);
	if (!v2)
		return 0;
	strcpy(v2, a1);
	strcpy(v2 + 80, a2);
	*((_DWORD*)v2 + 85) = 0;
	*((_DWORD*)v2 + 84) = dword_5d4594_2523912;
	if (dword_5d4594_2523912)
		*(_DWORD*)(dword_5d4594_2523912 + 340) = v2;
	dword_5d4594_2523912 = v2;
	return 1;
}

//----- (0057C5A0) --------------------------------------------------------
void __cdecl sub_57C5A0(const char* a1) {
	int v1; // edi
	int v2; // eax
	int v3; // eax

	v1 = dword_5d4594_2523912;
	if (dword_5d4594_2523912) {
		while (strcmp(a1, (const char*)v1)) {
			v1 = *(_DWORD*)(v1 + 336);
			if (!v1)
				return;
		}
		v2 = *(_DWORD*)(v1 + 340);
		if (v2)
			*(_DWORD*)(v2 + 336) = *(_DWORD*)(v1 + 336);
		else
			dword_5d4594_2523912 = *(_DWORD*)(v1 + 336);
		v3 = *(_DWORD*)(v1 + 336);
		if (v3)
			*(_DWORD*)(v3 + 340) = *(_DWORD*)(v1 + 340);
		sub_414330(*(unsigned int**)&byte_5D4594[2523908], (_QWORD*)v1);
	}
}

//----- (0057C650) --------------------------------------------------------
void __cdecl sub_57C650(float* a1, float* a2, float* a3) {
	float* v3;      // ecx
	double v4;      // st7
	double v5;      // st6
	long double v6; // st7
	float* v7;      // edx
	long double v8; // st4
	double v9;      // st7
	float v10;      // [esp+0h] [ebp-10h]
	float v11;      // [esp+0h] [ebp-10h]
	float v12;      // [esp+Ch] [ebp-4h]
	float v13;      // [esp+14h] [ebp+4h]
	float v14;      // [esp+14h] [ebp+4h]
	float v15;      // [esp+18h] [ebp+8h]
	float v16;      // [esp+1Ch] [ebp+Ch]

	v3 = a1;
	v4 = a1[2] - *a1;
	v13 = v4;
	v5 = v3[3] - v3[1];
	v6 = sqrt(v5 * v5 + v4 * v4);
	if (v6 < 0.0099999998)
		v6 = 0.0099999998;
	v12 = v5;
	v7 = a3;
	v10 = v5;
	v8 = (v10 * (a2[1] - v3[1]) + v13 * (*a2 - *v3)) / (v6 * v6);
	v11 = v8 * v13;
	*a3 = v11 + *v3;
	a3[1] = v8 * v12 + v3[1];
	if (*v3 >= (double)v3[2]) {
		v15 = *v3;
		v14 = v3[2];
	} else {
		v14 = *v3;
		v15 = v3[2];
	}
	if (v3[1] >= (double)v3[3]) {
		v9 = v3[3];
		v16 = v3[1];
	} else {
		v9 = v3[1];
		v16 = v3[3];
	}
	if (*v7 >= (double)v14) {
		if (*v7 > (double)v15)
			*v7 = v15;
	} else {
		*v7 = v14;
	}
	if (v9 <= v7[1]) {
		if (v7[1] > (double)v16)
			v7[1] = v16;
	} else {
		v7[1] = v9;
	}
}

//----- (0057C790) --------------------------------------------------------
void __cdecl sub_57C790(float4* a1, float2* a2, float2* a3, float a4) {
	double v4; // st5
	double v5; // st7
	double v6; // st6
	double v7; // st7
	float v8;  // [esp+0h] [ebp-10h]
	float v9;  // [esp+4h] [ebp-Ch]
	float v10; // [esp+8h] [ebp-8h]
	float v11; // [esp+14h] [ebp+4h]
	float v12; // [esp+18h] [ebp+8h]
	float v13; // [esp+20h] [ebp+10h]

	v8 = a1->field_8 - a1->field_0;
	v4 = a1->field_C - a1->field_4;
	v9 = v4;
	v5 = v4 * (a2->field_4 - a1->field_4) + v8 * (a2->field_0 - a1->field_0);
	v6 = a4 * a4;
	v10 = v5 * v8 / v6;
	a3->field_0 = v10 + a1->field_0;
	a3->field_4 = v5 * v9 / v6 + a1->field_4;
	if (a1->field_0 >= (double)a1->field_8) {
		v12 = a1->field_0;
		v13 = a1->field_8;
	} else {
		v13 = a1->field_0;
		v12 = a1->field_8;
	}
	if (a1->field_4 >= (double)a1->field_C) {
		v7 = a1->field_C;
		v11 = a1->field_4;
	} else {
		v7 = a1->field_4;
		v11 = a1->field_C;
	}
	if (a3->field_0 >= (double)v13) {
		if (a3->field_0 > (double)v12)
			a3->field_0 = v12;
	} else {
		a3->field_0 = v13;
	}
	if (v7 <= a3->field_4) {
		if (a3->field_4 > (double)v11)
			a3->field_4 = v11;
	} else {
		a3->field_4 = v7;
	}
}

//----- (0057C8A0) --------------------------------------------------------
BOOL __cdecl sub_57C8A0(float4* a1, float2* a2, float2* a3) {
	float4* v3; // ecx
	float2* v4; // edx
	double v5;  // st7
	double v6;  // st6
	double v7;  // st6
	double v8;  // st7
	float v10;  // [esp+0h] [ebp-Ch]
	float v11;  // [esp+0h] [ebp-Ch]
	float v12;  // [esp+8h] [ebp-4h]
	float v13;  // [esp+8h] [ebp-4h]
	float v14;  // [esp+10h] [ebp+4h]
	float v15;  // [esp+10h] [ebp+4h]
	float v16;  // [esp+14h] [ebp+8h]
	float v17;  // [esp+18h] [ebp+Ch]

	v3 = a1;
	v4 = a3;
	v5 = a1->field_8 - a1->field_0;
	v6 = a1->field_C - a1->field_4;
	v12 = v6;
	v10 = v6 * v12 + v5 * v5;
	v7 = (a2->field_4 - a1->field_4) * v12 + (a2->field_0 - a1->field_0) * v5;
	v14 = v7;
	v13 = v14 * v12 / v10;
	a3->field_0 = v5 * v7 / v10 + v3->field_0;
	v15 = v13 + v3->field_4;
	a3->field_4 = v15;
	if (v3->field_0 >= (double)v3->field_8) {
		v8 = v3->field_8;
		v16 = v3->field_0;
	} else {
		v8 = v3->field_0;
		v16 = v3->field_8;
	}
	if (v3->field_4 >= (double)v3->field_C) {
		v11 = v3->field_4;
		v17 = v3->field_C;
	} else {
		v17 = v3->field_4;
		v11 = v3->field_C;
	}
	return v8 <= v4->field_0 && v4->field_0 <= (double)v16 && v15 >= (double)v17 && v15 <= (double)v11;
}

//----- (0057C9A0) --------------------------------------------------------
char __cdecl sub_57C9A0(int a1, int a2, float* a3, float* a4, char a5) {
	int v5;    // ebp
	char v6;   // bl
	double v7; // st7
	double v8; // st6
	int v9;    // eax
	int v10;   // eax
	float v11; // edx
	float v12; // ecx
	float v13; // eax
	float v14; // edx
	char v15;  // bl
	double v16;
	double v17;
	float v18;           // eax
	float v19;           // edx
	float v20;           // esi
	float2 a3a;          // [esp+10h] [ebp-30h]
	float2 v23;          // [esp+18h] [ebp-28h]
	float2 a2a;          // [esp+20h] [ebp-20h]
	float2 v25;          // [esp+28h] [ebp-18h]
	float v26;           // [esp+30h] [ebp-10h]
	float v27;           // [esp+34h] [ebp-Ch]
	float v28;           // [esp+38h] [ebp-8h]
	float v29;           // [esp+3Ch] [ebp-4h]
	char v30;            // [esp+44h] [ebp+4h]
	unsigned __int8 v31; // [esp+44h] [ebp+4h]
	unsigned __int8 v32; // [esp+48h] [ebp+8h]

	v5 = a1;
	if (a1 < 0 || a1 >= 256 || a2 < 0 || a2 >= 256)
		return 0;
	v6 = a5;
	if (a5 & 8) {
		v7 = (double)a1 * *(float*)&byte_587000[313536] + 11.5 - *a3;
		v8 = (double)a2 * *(float*)&byte_587000[313536] + 11.5 - a3[1];
		if (v8 * v8 + v7 * v7 < 3600.0)
			v6 = a5 | 4;
	}
	v30 = 16 * (~v6 & 4);
	if (v6 & 1)
		v30 = (16 * (~v6 & 4)) | 0x10;
	v31 = (unsigned char)sub_57B500(v5, a2, v30);
	if (v31 == 255)
		return 0;
	v9 = v6 & 1 ? sub_4105E0(v5, a2) : nox_server_getWallAtPoint_410580(v5, a2);
	if (!v9 || v6 < 0 && *(_BYTE*)(v9 + 4) & 4 && *(_BYTE*)(*(_DWORD*)(v9 + 28) + 20) & 2)
		return 0;
	v10 = *(_DWORD*)&byte_5D4594[12332 * *(unsigned __int8*)(v9 + 1) + 2692780];
	if (v10 & 2 || v6 & 0x40 && !(v10 & 1))
		return 0;
	if (*a3 >= (double)a3[2]) {
		v12 = a3[2];
		v28 = *a3;
		v26 = v12;
	} else {
		v11 = a3[2];
		v26 = *a3;
		v28 = v11;
	}
	if (a3[1] >= (double)a3[3]) {
		v14 = a3[3];
		v29 = a3[1];
		v27 = v14;
	} else {
		v13 = a3[3];
		v27 = a3[1];
		v29 = v13;
	}
	a2a.field_0 = (double)(23 * v5);
	a2a.field_4 = (double)(23 * a2);
	if (v31)
		sub_57CD30((float4*)a3, &a2a, &a3a);
	if (v31 != 1) {
		v25.field_0 = a2a.field_0 + 23.0;
		v25.field_4 = a2a.field_4;
		sub_57CD70((float4*)a3, &v25, &v23);
	}
	v15 = 0;
	v32 = 0;
	if (byte_587000[24 * v31 + 313272] && a2a.field_0 + *(float*)&byte_587000[24 * v31 + 313276] <= a3a.field_0 &&
	    a2a.field_0 + *(float*)&byte_587000[24 * v31 + 313280] >= a3a.field_0 && a3a.field_0 >= (double)v26 &&
	    a3a.field_0 <= (double)v28 && a3a.field_4 >= (double)v27 && a3a.field_4 <= (double)v29) {
		v15 = 1;
		*(float2*)a4 = a3a;
		v32 = 1;
	}
	if (byte_587000[24 * v31 + 313284] && a2a.field_0 + *(float*)&byte_587000[24 * v31 + 313288] <= v23.field_0 &&
	    a2a.field_0 + *(float*)&byte_587000[24 * v31 + 313292] >= v23.field_0 && v23.field_0 >= (double)v26 &&
	    v23.field_0 <= (double)v28 && v23.field_4 >= (double)v27 && v23.field_4 <= (double)v29) {
		++v15;
		*(float2*)&a4[2 * v32] = v23;
	}
	if (v15 == 2) {
		v16 = a3[1] - a3a.field_4;
		v17 = a3[1] - v23.field_4;
		if (v17 * v17 + (*a3 - v23.field_0) * (*a3 - v23.field_0) <
		    v16 * v16 + (*a3 - a3a.field_0) * (*a3 - a3a.field_0)) {
			v18 = *a4;
			v19 = a4[1];
			*a4 = a4[2];
			v20 = a4[3];
			a4[2] = v18;
			a4[1] = v20;
			a4[3] = v19;
		}
	}
	return v15;
}

//----- (0057CD30) --------------------------------------------------------
float2* __cdecl sub_57CD30(float4* a1, float2* a2, float2* a3) {
	double v3;      // st7
	double v4;      // st6
	float2* result; // eax
	double v6;      // st7

	v3 = a1->field_8 - a1->field_0;
	v4 = a1->field_C - a1->field_4;
	result = a3;
	v6 = ((a2->field_4 - a1->field_4) * v3 - (a2->field_0 - a1->field_0) * v4) / (v4 - v3);
	a3->field_0 = v6 + a2->field_0;
	a3->field_4 = v6 + a2->field_4;
	return result;
}

//----- (0057CD70) --------------------------------------------------------
float2* __cdecl sub_57CD70(float4* a1, float2* a2, float2* a3) {
	double v3;      // st7
	double v4;      // st6
	float2* result; // eax
	double v6;      // st7

	v3 = a1->field_8 - a1->field_0;
	v4 = a1->field_C - a1->field_4;
	result = a3;
	v6 = ((a2->field_4 - a1->field_4) * v3 - (a2->field_0 - a1->field_0) * v4) / (-v4 - v3);
	a3->field_0 = a2->field_0 - v6;
	a3->field_4 = v6 + a2->field_4;
	return result;
}

//----- (0057CDB0) --------------------------------------------------------
int __cdecl sub_57CDB0(int2* a1, float* a2, float2* a3) {
	int2* v3;   // esi
	char v4;    // bl
	int result; // eax
	float2* v6; // eax
	float2* v7; // eax
	float2* v8; // eax
	char v9;    // [esp+10h] [ebp+4h]

	v3 = a1;
	v9 = sub_57F2A0((float2*)a2, a1->field_0, a1->field_4);
	v4 = sub_57F1D0((float2*)a2 + 1);
	switch (sub_57B500(v3->field_0, v3->field_4, 64)) {
	case 0:
		if (v9 != 1 && v9)
			goto LABEL_44;
		a3->field_0 = -0.70709997;
		a3->field_4 = -0.70709997;
		return 1;
	case 1:
		if (v9 == 1 || v9 == 2)
			goto LABEL_43;
		a3->field_0 = -0.70709997;
		a3->field_4 = 0.70709997;
		return 1;
	case 2:
		switch (v9) {
		case 0:
			goto LABEL_40;
		case 1:
			v6 = a3;
			if (!(v4 & 1))
				goto LABEL_23;
			a3->field_0 = -0.70709997;
			a3->field_4 = -0.70709997;
			result = 1;
			break;
		case 2:
			goto LABEL_30;
		case 3:
			goto LABEL_35;
		default:
			return 1;
		}
		return result;
	case 3:
		if (!v9)
			goto LABEL_40;
		if (v9 != 1)
			goto LABEL_44;
		goto LABEL_25;
	case 4:
		if (v9 == 1)
			goto LABEL_25;
		if (v9 == 2)
			goto LABEL_30;
		a3->field_0 = -0.70709997;
		a3->field_4 = 0.70709997;
		return 1;
	case 5:
		if (v9 == 2)
			goto LABEL_30;
		if (v9 == 3)
			goto LABEL_35;
		a3->field_0 = -0.70709997;
		a3->field_4 = -0.70709997;
		return 1;
	case 6:
		if (!v9)
			goto LABEL_40;
		if (v9 == 3)
			goto LABEL_35;
		v6 = a3;
	LABEL_23:
		v6->field_0 = 0.70709997;
		v6->field_4 = -0.70709997;
		return 1;
	case 7:
		if (v9 == 1) {
		LABEL_25:
			v7 = a3;
			if (!(v4 & 1))
				goto LABEL_38;
			goto LABEL_26;
		}
		v8 = a3;
		if (v4 & 1)
			goto LABEL_45;
		a3->field_0 = -0.70709997;
		a3->field_4 = 0.70709997;
		return 1;
	case 8:
		if (v9 == 2) {
		LABEL_30:
			v8 = a3;
			a3->field_0 = 0.70709997;
			if (v4 & 1)
				goto LABEL_46;
			a3->field_4 = -0.70709997;
			result = 1;
		} else {
			v8 = a3;
			a3->field_0 = -0.70709997;
			if (!(v4 & 1))
				goto LABEL_46;
			a3->field_4 = -0.70709997;
			result = 1;
		}
		return result;
	case 9:
		if (v9 == 3) {
		LABEL_35:
			v8 = a3;
			if (!(v4 & 4))
				goto LABEL_45;
			a3->field_0 = -0.70709997;
			a3->field_4 = 0.70709997;
			result = 1;
		} else {
			v7 = a3;
			if (v4 & 4) {
			LABEL_38:
				v7->field_0 = 0.70709997;
				v7->field_4 = -0.70709997;
				result = 1;
			} else {
			LABEL_26:
				v7->field_0 = -0.70709997;
				v7->field_4 = -0.70709997;
				result = 1;
			}
		}
		return result;
	case 0xA:
		if (v9) {
			if (v4 & 2) {
			LABEL_43:
				a3->field_0 = 0.70709997;
				a3->field_4 = -0.70709997;
				return 1;
			}
		LABEL_44:
			v8 = a3;
		LABEL_45:
			v8->field_0 = 0.70709997;
		} else {
		LABEL_40:
			v8 = a3;
			a3->field_0 = -0.70709997;
			if (!(v4 & 2)) {
				a3->field_4 = -0.70709997;
				return 1;
			}
		}
	LABEL_46:
		v8->field_4 = 0.70709997;
		return 1;
	default:
		return 0;
	}
}

//----- (0057D150) --------------------------------------------------------
void __thiscall sub_57D150(LPVOID* this) {
	LPVOID* v1; // esi

	v1 = this;
	operator_delete(this[5]);
	sub_57DF70(v1 + 2);
	operator_delete(*v1);
}

//----- (0057D1C0) --------------------------------------------------------
int __thiscall sub_57D1C0(void** this, int a2, unsigned __int8* a3, int a4) {
	void** v4;             // ebx
	void* v5;              // ecx
	int v6;                // eax
	unsigned __int8* v7;   // esi
	int v8;                // ecx
	int v9;                // eax
	int v10;               // edx
	int v11;               // edi
	int v12;               // ebp
	_WORD* v13;            // ecx
	unsigned int v14;      // eax
	int v15;               // esi
	_WORD* v16;            // eax
	int v17;               // ecx
	int v18;               // eax
	int v19;               // ebp
	int v20;               // eax
	unsigned __int8* i;    // eax
	int v22;               // ecx
	int v23;               // ecx
	int v24;               // eax
	int v25;               // edx
	int v26;               // eax
	int v27;               // ecx
	unsigned __int8* v28;  // eax
	int v29;               // edx
	int v30;               // eax
	unsigned __int8 v31;   // cl
	int v32;               // eax
	int v33;               // esi
	int v34;               // esi
	char* v35;             // eax
	int v36;               // eax
	int v37;               // esi
	int v38;               // ecx
	unsigned __int8* v39;  // edx
	unsigned __int8* v40;  // edi
	unsigned __int8* v41;  // eax
	unsigned int v42;      // ecx
	int v43;               // edx
	int v44;               // eax
	int v45;               // edi
	int v46;               // edx
	int v47;               // edi
	int v48;               // eax
	char* v49;             // edi
	unsigned __int8* v50;  // esi
	unsigned int v51;      // eax
	char* v52;             // edi
	unsigned __int8* v53;  // esi
	char v54;              // cl
	int v55;               // esi
	int v56;               // ecx
	int v57;               // ebp
	unsigned __int8* v58;  // edx
	int v59;               // ecx
	int v60;               // esi
	unsigned __int8* v61;  // eax
	unsigned int v62;      // ebp
	int v63;               // ecx
	int v64;               // eax
	int v65;               // esi
	int v66;               // ecx
	int v67;               // edx
	int v68;               // edi
	signed int v69;        // ebp
	int v70;               // eax
	int v71;               // esi
	int v72;               // ecx
	unsigned __int8* v73;  // edi
	unsigned __int8* v74;  // eax
	unsigned int v75;      // ecx
	int v76;               // edx
	int v77;               // eax
	int v78;               // edi
	int v79;               // edx
	int v80;               // eax
	char* v81;             // edi
	unsigned __int8* v82;  // esi
	unsigned int v83;      // eax
	char* v84;             // edi
	int v85;               // ebp
	unsigned __int8* v86;  // edx
	int v87;               // esi
	int v88;               // ecx
	unsigned __int8* v89;  // edi
	unsigned __int8* v90;  // eax
	unsigned int v91;      // ebp
	int v92;               // ecx
	int v93;               // eax
	int v94;               // edi
	int v95;               // eax
	int v96;               // ecx
	int v97;               // edx
	int v98;               // edi
	signed int v99;        // ebp
	int v100;              // eax
	unsigned __int8* v101; // esi
	int v102;              // edi
	int v103;              // edx
	unsigned __int8* v104; // edi
	unsigned int v105;     // ecx
	int v106;              // edi
	unsigned __int8* v107; // edx
	int v108;              // ebp
	signed int v110;       // [esp+10h] [ebp-5Ch]
	int v111;              // [esp+14h] [ebp-58h]
	int v112;              // [esp+18h] [ebp-54h]
	int v113;              // [esp+18h] [ebp-54h]
	int v114;              // [esp+18h] [ebp-54h]
	int v115;              // [esp+18h] [ebp-54h]
	int v116;              // [esp+18h] [ebp-54h]
	int v117;              // [esp+1Ch] [ebp-50h]
	unsigned __int8* v118; // [esp+20h] [ebp-4Ch]
	int v119;              // [esp+24h] [ebp-48h]
	int v120;              // [esp+24h] [ebp-48h]
	int v121;              // [esp+24h] [ebp-48h]
	unsigned __int16 v122; // [esp+24h] [ebp-48h]
	int v123;              // [esp+24h] [ebp-48h]
	int v124;              // [esp+24h] [ebp-48h]
	int v125;              // [esp+28h] [ebp-44h]
	int v126;              // [esp+2Ch] [ebp-40h]
	int v127;              // [esp+30h] [ebp-3Ch]
	__int16 v128;          // [esp+34h] [ebp-38h]
	int v129;              // [esp+38h] [ebp-34h]
	int v130;              // [esp+38h] [ebp-34h]
	int v131;              // [esp+38h] [ebp-34h]
	int v132;              // [esp+38h] [ebp-34h]
	void* v133;            // [esp+3Ch] [ebp-30h]
	int v134;              // [esp+40h] [ebp-2Ch]
	int v135[10];          // [esp+44h] [ebp-28h]
	int v136;              // [esp+70h] [ebp+4h]
	unsigned __int8* v137; // [esp+70h] [ebp+4h]
	unsigned __int8* v138; // [esp+78h] [ebp+Ch]
	unsigned __int8* v139; // [esp+78h] [ebp+Ch]
	unsigned __int8* v140; // [esp+78h] [ebp+Ch]
	int v141;              // [esp+78h] [ebp+Ch]
	unsigned __int8* v142; // [esp+78h] [ebp+Ch]
	unsigned __int8* v143; // [esp+78h] [ebp+Ch]

	v4 = this;
	v5 = this[2];
	v135[0] = (int)(v4 + 2);
	v135[2] = (int)(v4 + 3);
	v135[4] = a2;
	v135[3] = a2;
	v6 = 0;
	v135[1] = (int)v5;
	v135[5] = 0;
	v135[6] = 0;
	v135[9] = 0;
	v136 = 0;
	v118 = &a3[a4];
	if ((unsigned int)a4 >= 5) {
		v7 = a3;
		if (a3 < a3 + 5) {
			do {
				v8 = *v7++;
				v6 = __ROL4__(v8 ^ v6, 5);
			} while (v7 < a3 + 5);
			v136 = v6;
		}
	}
	v9 = a4;
	v111 = a4;
	if (a4 < 5)
		goto LABEL_144;
	v10 = v136;
	while (2) {
		v11 = 0;
		v126 = v9 - 5;
		if (v9 - 5 >= 64)
			v126 = 64;
		v110 = 0;
		v125 = 0;
		while (1) {
			HIWORD(v15) = 0;
			v12 = 0;
			v13 = v4[5];
			v14 = (unsigned int)(214013 * v10 + 2531011) >> 17;
			LOWORD(v15) = v13[v14];
			v16 = &v13[v14];
			v17 = (unsigned int)v4[1] & 0xFFFF;
			v117 = v17;
			*v16 = v17;
			if ((unsigned __int16)v15 == 0xFFFF || v15 == v17)
				goto LABEL_62;
			v18 = (unsigned __int16)(v17 - v15);
			v19 = v18;
			if (v18 >= v111 - v11)
				v19 = v111 - v11;
			if (v19 >= 521) {
				v18 = 521;
			} else if (v18 >= v111 - v11) {
				v18 = v111 - v11;
			}
			v112 = v18;
			v138 = &a3[v11];
			v119 = 0x10000 - v15;
			if (0x10000 - v15 < v18) {
				v22 = v15;
				if (v15 >= 0x10000) {
				LABEL_33:
					v23 = 0;
					if (v18 + v15 - 0x10000 <= 0) {
					LABEL_23:
						v12 = v18;
						goto LABEL_24;
					}
					while (*((_BYTE*)*v4 + v23) == v138[v119 + v23]) {
						v18 = v112;
						if (++v23 >= v112 + v15 - 0x10000)
							goto LABEL_23;
					}
					v12 = v119 + v23;
				} else {
					while (*((_BYTE*)*v4 + v22) == v138[v22 - v15]) {
						if (++v22 >= 0x10000) {
							v10 = v136;
							goto LABEL_33;
						}
					}
					v10 = v136;
					v12 = v22 - v15;
				}
			} else {
				v12 = 0;
				if (v18 <= 0)
					goto LABEL_23;
				while (*((_BYTE*)*v4 + v15 + v12) == a3[v11 + v12]) {
					v18 = v112;
					if (++v12 >= v112)
						goto LABEL_23;
				}
			}
		LABEL_24:
			if ((unsigned __int16)(v15 + v12) == v117) {
				v20 = v111 + -v12 - v11;
				if (521 - v12 < v20)
					v20 = 521 - v12;
				v120 = v20;
				v113 = 0;
				if (v20 > 0) {
					for (i = &a3[v11]; *i == i[v12]; ++i) {
						if (++v113 >= v120)
							break;
					}
				}
				v12 += v113;
			}
			if (v12 >= 3) {
				v114 = 521 - v12;
				if (521 - v12 >= v11)
					v114 = v11;
				v24 = (unsigned __int16)((char*)v4[1] - v15);
				if (v114 >= v24 - v12)
					v121 = (unsigned __int16)((char*)v4[1] - v15) - v12;
				else
					v121 = v114;
				v25 = 0x10000 - v24;
				if (v121 < 0x10000 - v24) {
					v25 = v114;
					if (v114 < v24 - v12) {
					LABEL_53:
						v26 = 0;
						if (v25 <= 0)
							goto LABEL_152;
						v122 = v15 - 1;
						v139 = v138 - 1;
						do {
							if (*((_BYTE*)*v4 + v122) != *v139)
								break;
							++v26;
							--v122;
							--v139;
						} while (v26 < v114);
						if (v26 <= 0) {
						LABEL_152:
							v10 = v136;
						} else {
							v11 -= v26;
							v27 = (int)v4[1] - v26;
							LOWORD(v15) = v15 - v26;
							v12 += v26;
							v4[1] = (void*)v27;
							v28 = &a3[v11];
							LOWORD(v117) = v27;
							v10 = 0;
							if (v28 < v28 + 5) {
								do {
									v29 = *v28++ ^ v10;
									v10 = __ROL4__(v29, 5);
								} while (v28 < &a3[v11 + 5]);
							}
							v136 = v10;
							v125 = 1;
						}
						goto LABEL_62;
					}
					v25 = (unsigned __int16)((char*)v4[1] - v15) - v12;
				}
				v114 = v25;
				goto LABEL_53;
			}
		LABEL_62:
			v30 = v110;
			if (v110 >= 4) {
				v115 = v11;
				if (v12 <= v110) {
					v4[1] = v133;
					v137 = &a3[v127];
					v55 = __ROL4__(v134 ^ a3[v127 + 5] ^ __ROL4__(a3[v127], 25), 5);
					sub_57E4C0((_DWORD**)v135, (unsigned int)a3, v127, v110 - 4,
						   (unsigned __int16)((_WORD)v133 - v128));
					v56 = &v118[-v127] - a3;
					v57 = v110 - 2;
					if (v110 - 2 >= v56 - 2)
						v57 = v56 - 2;
					v58 = &a3[v127];
					v59 = (int)v4[1] + 2;
					v141 = (int)v4[1] + 2;
					if (v57 > 0) {
						if (v57 <= 1024) {
							v64 = __ROL4__(v55 ^ v137[6] ^ __ROL4__(v137[1], 25), 5);
							v65 = 0;
							v130 = (int)(v137 + 7);
							while (1) {
								*((_WORD*)v4[5] +
								  ((unsigned int)(214013 * v64 + 2531011) >> 17)) =
								    v65 + v59;
								v66 = *(unsigned __int8*)(v130 + v65);
								v67 =
								    __ROL4__(*(unsigned __int8*)(v130 + v65++ - 5), 25);
								v64 = __ROL4__(v64 ^ v66 ^ v67, 5);
								if (v65 >= v57)
									break;
								LOWORD(v59) = v141;
							}
							v58 = &a3[v127];
							v136 = v64;
						} else {
							v60 = 0;
							v61 = &v137[v57 + 2];
							v62 = (unsigned int)(v61 + 5);
							if (v61 < v61 + 5) {
								do {
									v63 = *v61++;
									v60 = __ROL4__(v63 ^ v60, 5);
								} while ((unsigned int)v61 < v62);
							}
							v136 = v60;
						}
					} else {
						v136 = 0;
					}
					v68 = (unsigned int)v4[1] & 0xFFFF;
					if (v68 + v110 <= 0x10000) {
						v69 = v110;
						qmemcpy((char*)*v4 + v68, v58, v110);
					} else {
						qmemcpy((char*)*v4 + v68, v58, 0x10000 - v68);
						v69 = v110;
						qmemcpy(*v4, &v58[0x10000 - v68], v110 - (0x10000 - v68));
					}
					v4[1] = (char*)v4[1] + v69;
					a3 += v69 + v127;
					goto LABEL_143;
				}
				sub_57E4C0((_DWORD**)v135, (unsigned int)a3, v11, v12 - 4,
					   (unsigned __int16)(v117 - v15));
				v36 = &v118[-v11] - a3 - 1;
				if (v12 - 1 < v36)
					v36 = v12 - 1;
				v37 = 0;
				v38 = (int)v4[1] + 1;
				v39 = &a3[v11];
				v123 = v36;
				v129 = (int)v4[1] + 1;
				v140 = &a3[v11];
				v40 = &a3[v11];
				if (v36 > 0) {
					if (v36 <= 1024) {
						v44 = __ROL4__(v136 ^ v40[5] ^ __ROL4__(*v40, 25), 5);
						v45 = (int)(v40 + 1);
						if (v123 > 0) {
							while (1) {
								*((_WORD*)v4[5] +
								  ((unsigned int)(214013 * v44 + 2531011) >> 17)) =
								    v37 + v38;
								v46 = v44 ^ *(unsigned __int8*)(v45 + 5 + v37) ^
								      __ROL4__(*(unsigned __int8*)(v45 + v37), 25);
								++v37;
								v44 = __ROL4__(v46, 5);
								if (v37 >= v123)
									break;
								LOWORD(v38) = v129;
							}
						}
						v136 = v44;
					} else {
						v41 = &v40[v36 + 1];
						v42 = (unsigned int)(v41 + 5);
						if (v41 < v41 + 5) {
							do {
								v43 = *v41++;
								v37 = __ROL4__(v43 ^ v37, 5);
							} while ((unsigned int)v41 < v42);
						}
						v136 = v37;
					}
					v39 = v140;
				} else {
					v136 = 0;
				}
				v47 = (unsigned int)v4[1] & 0xFFFF;
				if (v47 + v12 > 0x10000) {
					v48 = 0x10000 - v47;
					qmemcpy((char*)*v4 + v47, v39, 0x10000 - v47);
					v49 = (char*)*v4;
					v50 = &v140[v48];
					v51 = v12 - v48;
					qmemcpy(*v4, v50, 4 * (v51 >> 2));
					v53 = &v50[4 * (v51 >> 2)];
					v52 = &v49[4 * (v51 >> 2)];
					v54 = v51;
				LABEL_118:
					qmemcpy(v52, v53, v54 & 3);
					v4[1] = (char*)v4[1] + v12;
					a3 += v115 + v12;
					goto LABEL_143;
				}
			LABEL_117:
				v84 = (char*)*v4 + v47;
				qmemcpy(v84, v39, 4 * ((unsigned int)v12 >> 2));
				v53 = &v39[4 * ((unsigned int)v12 >> 2)];
				v52 = &v84[4 * ((unsigned int)v12 >> 2)];
				v54 = v12;
				goto LABEL_118;
			}
			if (v12 < 4)
				goto LABEL_66;
			if (v125) {
				v115 = v11;
				sub_57E4C0((_DWORD**)v135, (unsigned int)a3, v11, v12 - 4,
					   (unsigned __int16)(v117 - v15));
				v70 = &v118[-v11] - a3 - 1;
				if (v12 - 1 < v70)
					v70 = v12 - 1;
				v71 = 0;
				v72 = (int)v4[1] + 1;
				v39 = &a3[v11];
				v124 = v70;
				v131 = (int)v4[1] + 1;
				v142 = &a3[v11];
				v73 = &a3[v11];
				if (v70 > 0) {
					if (v70 <= 1024) {
						v77 = __ROL4__(v136 ^ v73[5] ^ __ROL4__(*v73, 25), 5);
						v78 = (int)(v73 + 1);
						if (v124 > 0) {
							while (1) {
								*((_WORD*)v4[5] +
								  ((unsigned int)(214013 * v77 + 2531011) >> 17)) =
								    v71 + v72;
								v79 = v77 ^ *(unsigned __int8*)(v78 + 5 + v71) ^
								      __ROL4__(*(unsigned __int8*)(v78 + v71), 25);
								++v71;
								v77 = __ROL4__(v79, 5);
								if (v71 >= v124)
									break;
								LOWORD(v72) = v131;
							}
						}
						v136 = v77;
					} else {
						v74 = &v73[v70 + 1];
						v75 = (unsigned int)(v74 + 5);
						if (v74 < v74 + 5) {
							do {
								v76 = *v74++;
								v71 = __ROL4__(v76 ^ v71, 5);
							} while ((unsigned int)v74 < v75);
						}
						v136 = v71;
					}
					v39 = v142;
				} else {
					v136 = 0;
				}
				v47 = (unsigned int)v4[1] & 0xFFFF;
				if (v47 + v12 > 0x10000) {
					v80 = 0x10000 - v47;
					qmemcpy((char*)*v4 + v47, v39, 0x10000 - v47);
					v81 = (char*)*v4;
					v82 = &v142[v80];
					v83 = v12 - v80;
					qmemcpy(*v4, v82, 4 * (v83 >> 2));
					v53 = &v82[4 * (v83 >> 2)];
					v52 = &v81[4 * (v83 >> 2)];
					v54 = v83;
					goto LABEL_118;
				}
				goto LABEL_117;
			}
			v30 = v12;
			v110 = v12;
			v128 = v15;
			v127 = v11;
			v133 = v4[1];
			v134 = v10;
		LABEL_66:
			if (v11 + 1 > v126)
				break;
			v31 = a3[v11];
			v32 = a3[v11 + 5];
			v33 = a3[v11++];
			v34 = v32 ^ __ROL4__(v33, 25);
			v35 = (char*)v4[1];
			v10 = __ROL4__(v10 ^ v34, 5);
			v4[1] = v35 + 1;
			v136 = v10;
			*((_BYTE*)*v4 + (unsigned __int16)v35) = v31;
		}
		v116 = v11;
		if (v30 < 4) {
			if (v11 + 5 >= v111 && v111 <= 64) {
				v100 = v111 - v11;
				v101 = &a3[v11];
				v102 = (unsigned int)v4[1] & 0xFFFF;
				if (v102 + v100 <= 0x10000) {
					v105 = v100;
					v104 = (unsigned __int8*)*v4 + v102;
				} else {
					v103 = 0x10000 - v102;
					qmemcpy((char*)*v4 + v102, v101, 0x10000 - v102);
					v104 = (unsigned __int8*)*v4;
					v105 = v100 - v103;
					v101 += v103;
				}
				qmemcpy(v104, v101, v105);
				v4[1] = (char*)v4[1] + v100;
				v11 = v111;
			}
			sub_57E3F0((_DWORD**)v135, (unsigned int)a3, v11);
			a3 += v11;
		} else {
			sub_57E4C0((_DWORD**)v135, (unsigned int)a3, v11, v110 - 4,
				   (unsigned __int16)((char*)v4[1] - v128));
			v85 = v110 - 1;
			if (v110 - 1 >= &v118[-v11] - a3 - 1)
				v85 = &v118[-v11] - a3 - 1;
			v86 = &a3[v11];
			v87 = 0;
			v88 = (int)v4[1] + 1;
			v132 = (int)v4[1] + 1;
			v143 = &a3[v11];
			v89 = &a3[v11];
			if (v85 > 0) {
				if (v85 <= 1024) {
					v93 = v136 ^ v89[5] ^ __ROL4__(*v86, 25);
					v94 = (int)(v89 + 1);
					v95 = __ROL4__(v93, 5);
					while (1) {
						*((_WORD*)v4[5] + ((unsigned int)(214013 * v95 + 2531011) >> 17)) =
						    v87 + v88;
						v96 = *(unsigned __int8*)(v94 + 5 + v87);
						v97 = __ROL4__(*(unsigned __int8*)(v94 + v87++), 25);
						v95 = __ROL4__(v95 ^ v96 ^ v97, 5);
						if (v87 >= v85)
							break;
						LOWORD(v88) = v132;
					}
					v86 = v143;
					v136 = v95;
				} else {
					v90 = &v86[v85 + 1];
					v91 = (unsigned int)(v90 + 5);
					if (v90 < v90 + 5) {
						do {
							v92 = *v90++;
							v87 = __ROL4__(v92 ^ v87, 5);
						} while ((unsigned int)v90 < v91);
					}
					v136 = v87;
				}
			} else {
				v136 = 0;
			}
			v98 = (unsigned int)v4[1] & 0xFFFF;
			if (v98 + v110 <= 0x10000) {
				v99 = v110;
				qmemcpy((char*)*v4 + v98, v86, v110);
			} else {
				qmemcpy((char*)*v4 + v98, v86, 0x10000 - v98);
				v99 = v110;
				qmemcpy(*v4, &v86[0x10000 - v98], v110 - (0x10000 - v98));
			}
			v4[1] = (char*)v4[1] + v99;
			a3 += v116 + v99;
		}
	LABEL_143:
		v9 = v118 - a3;
		v111 = v118 - a3;
		if (v118 - a3 >= 5) {
			v10 = v136;
			continue;
		}
		break;
	}
LABEL_144:
	if (v111) {
		v106 = (unsigned int)v4[1] & 0xFFFF;
		if (v106 + v111 <= 0x10000) {
			v108 = v111;
			qmemcpy((char*)*v4 + v106, a3, v111);
			v107 = a3;
		} else {
			v107 = a3;
			qmemcpy((char*)*v4 + v106, a3, 0x10000 - v106);
			v108 = v111;
			qmemcpy(*v4, &a3[0x10000 - v106], v111 - (0x10000 - v106));
		}
		v4[1] = (char*)v4[1] + v108;
		sub_57E3F0((_DWORD**)v135, (unsigned int)v107, v108);
	}
	return sub_57E7D0((_DWORD**)v135);
}
// 57D736: variable 'v133' is possibly undefined
// 57D739: variable 'v127' is possibly undefined
// 57D75C: variable 'v134' is possibly undefined
// 57D764: variable 'v128' is possibly undefined

//----- (0057DD70) --------------------------------------------------------
void __thiscall sub_57DD70(LPVOID* this) { operator_delete(*this); }

//----- (0057DD90) --------------------------------------------------------
_DWORD* __thiscall sub_57DD90(_DWORD* this) {
	_DWORD* v1; // esi
	void* v2;   // eax

	v1 = this;
	v2 = operator_new(0x224u);
	*v1 = v2;
	memset(v2, 0, 0x224u);
	return v1;
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (0057DDC0) --------------------------------------------------------
void __thiscall sub_57DDC0(LPVOID* this) { operator_delete(*this); }

//----- (0057DDD0) --------------------------------------------------------
int __thiscall sub_57DDD0(void** this) {
	int result; // eax

	result = 0;
	memset(*this, 0, 0x224u);
	return result;
}

//----- (0057DDE0) --------------------------------------------------------
unsigned int __cdecl sub_57DDE0(int a1, int a2) {
	int v2;              // ecx
	int v3;              // esi
	int i;               // ebx
	int v5;              // eax
	int v6;              // edx
	int v7;              // edi
	int v8;              // esi
	unsigned int result; // eax
	int v10;             // [esp+10h] [ebp-8h]
	int v11;             // [esp+14h] [ebp-4h]
	int v12;             // [esp+1Ch] [ebp+4h]

	v2 = a1;
	v3 = a2;
	for (i = 40; i > 0; i /= 3) {
		v5 = i + 1;
		v11 = i + 1;
		if (i + 1 <= v3) {
			do {
				v6 = 4 * v5;
				v10 = v5;
				v12 = *(_DWORD*)(4 * v5 + v2);
				if (v5 > i) {
					v7 = 4 * i;
					do {
						v8 = *(__int16*)(v6 - v7 + v2 + 2) - SHIWORD(v12);
						if (!v8)
							v8 = *(__int16*)(v6 - v7 + v2) - (__int16)v12;
						if (v8 >= 0)
							break;
						*(_DWORD*)(v6 + v2) = *(_DWORD*)(v6 - v7 + v2);
						v6 -= v7;
						v10 -= i;
					} while (v10 > i);
					v5 = v11;
				}
				++v5;
				*(_DWORD*)(v2 + 4 * v10) = v12;
				v3 = a2;
				v11 = v5;
			} while (v5 <= a2);
		}
		result = (unsigned int)(i / 3) >> 31;
	}
	return result;
}

//----- (0057DEA0) --------------------------------------------------------
int __thiscall sub_57DEA0(_DWORD* this, _WORD* a2) {
	_WORD* v2;   // esi
	int v3;      // ebx
	int i;       // eax
	__int16* v5; // edi
	__int16 v6;  // dx

	v2 = a2;
	v3 = 0;
	for (i = 0; i < 274; ++i) {
		*v2 = i;
		v2 += 2;
		*(v2 - 1) = *(_WORD*)(*this + 2 * i);
		v5 = (__int16*)(*this + 2 * i);
		v6 = *v5;
		v3 += v6;
		*v5 = v6 >> 1;
	}
	sub_57DDE0((int)(a2 - 2), 274);
	return v3;
}

//----- (0057DF00) --------------------------------------------------------
_DWORD* __thiscall sub_57DF00(_DWORD* this) {
	_DWORD* v1;          // ebx
	unsigned __int8* v2; // eax
	unsigned __int8* v3; // edi
	_DWORD* result;      // eax

	v1 = this;
	sub_57DD90(this);
	v1[1] = 4096;
	v2 = (unsigned __int8*)operator_new(0x448u);
	v3 = v2;
	v1[2] = v2;
	result = v1;
	qmemcpy(v3, &byte_587000[313544], 0x448u);
	return result;
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (0057DF70) --------------------------------------------------------
void __thiscall sub_57DF70(LPVOID* this) {
	LPVOID* v1; // esi

	v1 = this;
	operator_delete(this[2]);
	sub_57DDC0(v1);
}

//----- (0057DFC0) --------------------------------------------------------
int __thiscall sub_57DFC0(_DWORD* this, int* a2) {
	_DWORD* v2;     // esi
	int v3;         // eax
	int v4;         // ecx
	int v5;         // edi
	int v6;         // ebp
	int v7;         // esi
	int v8;         // ebx
	int v9;         // eax
	int v10;        // edx
	int v11;        // eax
	char* v12;      // edx
	int v13;        // eax
	int* v14;       // edx
	int v15;        // edx
	int v16;        // ebx
	int v17;        // esi
	char* v18;      // eax
	int v19;        // ecx
	int v20;        // esi
	int v21;        // eax
	int v22;        // ecx
	int v23;        // eax
	char* v24;      // ecx
	int v25;        // ecx
	int v26;        // eax
	int* v27;       // edi
	int v28;        // ecx
	int* v29;       // eax
	int v30;        // ecx
	int* v31;       // eax
	int v32;        // ebx
	int v33;        // esi
	int v34;        // ecx
	int v35;        // edi
	int result;     // eax
	int v37;        // edx
	__int16 v38;    // di
	int v39;        // esi
	char* v40;      // ecx
	int v41;        // eax
	__int16 v42;    // bp
	int* v43;       // [esp+10h] [ebp-46Ch]
	int v44;        // [esp+10h] [ebp-46Ch]
	int v45;        // [esp+10h] [ebp-46Ch]
	int v46;        // [esp+14h] [ebp-468h]
	int v47;        // [esp+14h] [ebp-468h]
	int* v48;       // [esp+14h] [ebp-468h]
	int v49;        // [esp+18h] [ebp-464h]
	int v50;        // [esp+18h] [ebp-464h]
	int v51;        // [esp+18h] [ebp-464h]
	int v52;        // [esp+1Ch] [ebp-460h]
	int v53;        // [esp+1Ch] [ebp-460h]
	int v54;        // [esp+1Ch] [ebp-460h]
	int v55;        // [esp+20h] [ebp-45Ch]
	int v56;        // [esp+24h] [ebp-458h]
	int v57;        // [esp+24h] [ebp-458h]
	int v58;        // [esp+28h] [ebp-454h]
	int v59;        // [esp+2Ch] [ebp-450h]
	char v60[1100]; // [esp+30h] [ebp-44Ch]

	v2 = this;
	*(_DWORD*)v60 = this;
	v3 = sub_57DEA0(this, &v60[4]);
	v4 = 0;
	v5 = 0;
	v6 = 16;
	v56 = v3;
	v2[1] = 4096;
	v55 = 0;
	v46 = 0;
	v52 = 16;
	v43 = a2 - 1;
	while (1) {
		v7 = 0;
		v58 = 0;
		v8 = 0;
		v59 = (v56 - v55) / v6;
		while (1) {
			v49 = 0;
			v9 = 1 << v4;
			if (v5 + (1 << v4) + v7 > 274) {
				v49 = 1;
				v9 = 274 - v5;
			}
			if (v7 < v9) {
				v10 = v7 + v5;
				v11 = v9 - v7;
				v7 += v11;
				v12 = &v60[4 * v10 + 6];
				do {
					v8 += *(__int16*)v12;
					v12 += 4;
					--v11;
				} while (v11);
				v6 = v52;
			}
			if (v49 || v4 >= 8 || v8 > v59)
				break;
			v58 = v8;
			++v4;
		}
		if (v4 && abs32(v58 - v59) <= abs32(v8 - v59)) {
			v8 = v58;
			--v4;
		}
		v13 = v46;
		if (v6 < 16) {
			v14 = v43;
			do {
				if (v4 >= *v14)
					break;
				v14[1] = *v14;
				--v13;
				--v14;
			} while (v13 > 0);
		}
		a2[v13] = v4;
		v55 += v8;
		++v43;
		v5 += 1 << v4;
		--v6;
		++v46;
		v52 = v6;
		if (v6 <= 2)
			break;
		v4 = 0;
	}
	v15 = 0;
	v16 = 0;
	v17 = 0;
	v44 = 0;
	v47 = 0;
	v50 = 0x7FFFFFFF;
	v53 = 0;
	if (v5 < 274) {
		v18 = &v60[4 * v5 + 6];
		v19 = 274 - v5;
		do {
			v17 += *(__int16*)v18;
			v18 += 4;
			--v19;
		} while (v19);
		v53 = v17;
	}
	v20 = 0;
	v21 = 1;
	if (v5 + 1 <= 274) {
		do {
			if (v15 < v21) {
				v22 = v15 + v5;
				v23 = v21 - v15;
				v15 += v23;
				v24 = &v60[4 * v22 + 6];
				do {
					v16 += *(__int16*)v24;
					v24 += 4;
					--v23;
				} while (v23);
			}
			v25 = 0;
			v26 = 274 - v15 - v5;
			if (v26 > 1) {
				do
					++v25;
				while (1 << v25 < v26);
			}
			if (v20 <= 8 && v25 <= 8) {
				if (v16 * v20 + v25 * (v53 - v16) >= v50)
					break;
				v50 = v16 * v20 + v25 * (v53 - v16);
				v44 = v20;
				v47 = v25;
			}
			v21 = 1 << ++v20;
		} while (v5 + (1 << v20) + v15 <= 274);
	}
	v27 = a2;
	v28 = 14;
	v29 = a2 + 13;
	do {
		if (v44 >= *v29)
			break;
		v29[1] = *v29;
		--v28;
		--v29;
	} while (v28 > 0);
	a2[v28] = v44;
	v30 = 15;
	v31 = a2 + 14;
	do {
		if (v47 >= *v31)
			break;
		v31[1] = *v31;
		--v30;
		--v31;
	} while (v30 > 0);
	a2[v30] = v47;
	v32 = 0;
	v33 = 0;
	v51 = 0;
	v45 = 0;
	v48 = a2;
	do {
		v34 = *v27;
		v35 = 1 << *v27;
		result = 274 - v32;
		v57 = v35;
		if (v35 < 274 - v32)
			result = v35;
		v37 = 0;
		v54 = result;
		if (result > 0) {
			v38 = v34 + 4;
			v39 = v33 << v34;
			v40 = &v60[4 * v32 + 4];
			do {
				v41 = *(__int16*)v40;
				v40 += 4;
				*(_WORD*)(*(_DWORD*)(*(_DWORD*)v60 + 8) + 4 * v41) = v38;
				v42 = v37++ | v39;
				*(_WORD*)(*(_DWORD*)(*(_DWORD*)v60 + 8) + 4 * v41 + 2) = v42;
				result = v54;
			} while (v37 < v54);
			v35 = v57;
			v33 = v45;
			v32 = v51;
		}
		v32 += v35;
		++v33;
		v27 = v48 + 1;
		v51 = v32;
		v45 = v33;
		++v48;
	} while (v33 < 16);
	return result;
}

//----- (0057E2C0) --------------------------------------------------------
int __thiscall sub_57E2C0(_DWORD** this) {
	_DWORD** v1;         // esi
	_DWORD* v2;          // edi
	unsigned int v3;     // ebp
	int v4;              // eax
	int v5;              // edx
	unsigned __int16 v6; // bx
	int v7;              // ebp
	_DWORD* v8;          // edx
	_BYTE* v9;           // ebx
	int v10;             // ecx
	_DWORD* v11;         // eax
	int v12;             // edi
	char* v13;           // ebx
	_DWORD* v14;         // edx
	int v15;             // eax
	char v16;            // cl
	int v17;             // eax
	int v18;             // ebp
	unsigned int v19;    // ecx
	int v20;             // ecx
	_BYTE* v21;          // eax
	unsigned int v22;    // ecx
	_DWORD* v23;         // eax
	int v24;             // ecx
	int result;          // eax
	int v26;             // [esp+10h] [ebp-44h]
	char v27[64];        // [esp+14h] [ebp-40h]

	v1 = this;
	*this[2] = 2;
	if ((int)--*this[2] <= 0)
		sub_57E2C0(this);
	++*((_WORD*)v1[1] + 272);
	v2 = v1[6];
	v3 = (unsigned int)v1[5];
	v4 = (*v1)[2];
	v5 = *(__int16*)(v4 + 1088);
	v6 = *(_WORD*)(v4 + 1090);
	v1[6] = (_DWORD*)((char*)v2 + v5);
	v7 = (v6 << (32 - (_BYTE)v2 - v5)) | v3;
	v1[5] = (_DWORD*)v7;
	if ((int)v2 + v5 >= 16) {
		*(_BYTE*)v1[3] = HIBYTE(v7);
		v8 = v1[5];
		v9 = (char*)v1[3] + 1;
		v1[3] = v9;
		*v9 = BYTE2(v8);
		v10 = (int)(v1[6] - 4);
		v11 = (_DWORD*)((_DWORD)v1[5] << 16);
		v1[3] = (_DWORD*)((char*)v1[3] + 1);
		v1[6] = (_DWORD*)v10;
		v1[5] = v11;
	}
	sub_57DFC0(*v1, (int*)v27);
	v12 = 0;
	v13 = v27;
	v26 = 16;
	do {
		v14 = v1[6];
		v15 = *(_DWORD*)v13 - v12;
		v12 = *(_DWORD*)v13;
		v16 = 32 - (_BYTE)v14 - ++v15;
		v17 = (int)v14 + v15;
		v18 = 1 << v16;
		v19 = (unsigned int)v1[5];
		v1[6] = (_DWORD*)v17;
		v20 = v18 | v19;
		v1[5] = (_DWORD*)v20;
		if (v17 >= 16) {
			*(_BYTE*)v1[3] = HIBYTE(v20);
			v21 = (char*)v1[3] + 1;
			v22 = (unsigned int)v1[5] >> 16;
			v1[3] = v21;
			*v21 = v22;
			v23 = v1[5];
			v24 = (int)(v1[6] - 4);
			v1[3] = (_DWORD*)((char*)v1[3] + 1);
			v1[6] = (_DWORD*)v24;
			v1[5] = (_DWORD*)((_DWORD)v23 << 16);
		}
		v13 += 4;
		result = --v26;
	} while (v26);
	return result;
}

//----- (0057E3F0) --------------------------------------------------------
unsigned int __thiscall sub_57E3F0(_DWORD** this, unsigned int a2, int a3) {
	unsigned __int8* v3;  // ebx
	unsigned int result;  // eax
	_DWORD** v5;          // esi
	bool v6;              // cf
	unsigned __int16 v7;  // di
	int v8;               // eax
	_DWORD* v9;           // edi
	int v10;              // edx
	unsigned __int16 v11; // bp
	int v12;              // edx
	_DWORD* v13;          // edx
	_BYTE* v14;           // ebp
	int v15;              // ecx
	_DWORD* v16;          // eax
	unsigned int v17;     // [esp+Ch] [ebp+4h]

	v3 = (unsigned __int8*)a2;
	result = a2 + a3;
	v5 = this;
	v6 = a2 < a2 + a3;
	v17 = a2 + a3;
	if (v6) {
		do {
			v7 = *v3;
			if ((int)--*v5[2] <= 0)
				sub_57E2C0(v5);
			v8 = v7;
			++*((_WORD*)v5[1] + v7);
			v9 = v5[6];
			v10 = (*v5)[2];
			v11 = *(_WORD*)(v10 + 4 * v8 + 2);
			v12 = *(__int16*)(v10 + 4 * v8);
			v5[5] = (_DWORD*)((v11 << (32 - (_BYTE)v9 - v12)) | (unsigned int)v5[5]);
			v5[6] = (_DWORD*)((char*)v9 + v12);
			if ((int)v9 + v12 >= 16) {
				*(_BYTE*)v5[3] = (unsigned int)v5[5] >> 24;
				v13 = v5[5];
				v14 = (char*)v5[3] + 1;
				v5[3] = v14;
				*v14 = BYTE2(v13);
				v15 = (int)(v5[6] - 4);
				v16 = (_DWORD*)((_DWORD)v5[5] << 16);
				v5[3] = (_DWORD*)((char*)v5[3] + 1);
				v5[6] = (_DWORD*)v15;
				v5[5] = v16;
			}
			result = v17;
			++v3;
		} while ((unsigned int)v3 < v17);
	}
	return result;
}

//----- (0057E4C0) --------------------------------------------------------
int __thiscall sub_57E4C0(_DWORD** this, unsigned int a2, int a3, unsigned int a4, unsigned int a5) {
	_DWORD** v5;          // esi
	unsigned __int16 v6;  // di
	int v7;               // eax
	_DWORD* v8;           // edi
	unsigned int v9;      // ebp
	int v10;              // ecx
	int v11;              // edx
	unsigned __int16 v12; // bx
	unsigned __int16 v13; // bp
	unsigned int v14;     // ebx
	int v15;              // edi
	int v16;              // ecx
	_DWORD* v17;          // edx
	int v18;              // eax
	int v19;              // ebp
	unsigned int v20;     // edi
	int v21;              // ecx
	int v22;              // eax
	unsigned __int8* v23; // ebx
	unsigned __int16 v24; // bp
	_DWORD* v25;          // edx
	int v26;              // eax
	unsigned int v27;     // edi
	int v28;              // ebx
	int v29;              // eax
	_DWORD* v30;          // ecx
	_BYTE* v31;           // ebx
	int v32;              // ecx
	_DWORD* v33;          // eax
	int v34;              // edx
	unsigned int v35;     // eax
	_DWORD* v36;          // edi
	unsigned int v37;     // ebp
	int v38;              // edx
	int v39;              // ebp
	_DWORD* v40;          // edx
	_BYTE* v41;           // ebp
	int v42;              // edx
	_DWORD* v43;          // ecx
	_DWORD* v44;          // edx
	int v45;              // edi
	int result;           // eax
	_DWORD* v47;          // edi
	char v48;             // cl
	int v49;              // edx
	unsigned int v50;     // ecx
	_DWORD* v51;          // edx
	_BYTE* v52;           // ebx
	int v53;              // ecx

	v5 = this;
	sub_57E3F0(this, a2, a3);
	if (a4 >= 8) {
		if (a4 >= 0x26) {
			v23 = &byte_587000[12 * ((a4 - 38) >> 5) + 314640];
			v24 = *(_WORD*)&byte_587000[12 * ((a4 - 38) >> 5) + 314640] + 4;
			if ((int)--*v5[2] <= 0)
				sub_57E2C0(v5);
			++*((_WORD*)v5[1] + v24);
			sub_57F160((int)v5, *(__int16*)((*v5)[2] + 4 * v24),
				   *(unsigned __int16*)((*v5)[2] + 4 * v24 + 2));
			v25 = v5[6];
			v26 = *((_DWORD*)v23 + 1) + 4;
			v27 = (unsigned int)v5[5];
			v28 = (((_BYTE)a4 - 38) & 0x1F | (16 * *((unsigned __int16*)v23 + 4)))
			      << (32 - (_BYTE)v25 - v26);
			v29 = (int)v25 + v26;
			v5[6] = (_DWORD*)v29;
			v5[5] = (_DWORD*)(v28 | v27);
			if (v29 >= 16)
				goto LABEL_14;
		} else {
			v13 = *(_WORD*)&byte_587000[12 * ((a4 - 8) >> 1) + 314640];
			v14 = (a4 - 8) & 1 | *(unsigned __int16*)&byte_587000[12 * ((a4 - 8) >> 1) + 314648];
			v15 = *(_DWORD*)&byte_587000[12 * ((a4 - 8) >> 1) + 314644];
			if ((int)--*v5[2] <= 0)
				sub_57E2C0(v5);
			++*((_WORD*)v5[1] + v13);
			v16 = (*v5)[2];
			v17 = v5[6];
			v18 = v15 + *(__int16*)(v16 + 4 * v13);
			v19 = *(unsigned __int16*)(v16 + 4 * v13 + 2) << v15;
			v20 = (unsigned int)v5[5];
			v21 = 32 - (_DWORD)v17 - v18;
			v22 = (int)v17 + v18;
			v5[6] = (_DWORD*)v22;
			v5[5] = (_DWORD*)(((v14 | v19) << v21) | v20);
			if (v22 >= 16)
				goto LABEL_14;
		}
	} else {
		v6 = a4 + 256;
		if ((int)--*v5[2] <= 0)
			sub_57E2C0(v5);
		v7 = v6;
		++*((_WORD*)v5[1] + v6);
		v8 = v5[6];
		v9 = (unsigned int)v5[5];
		v10 = (*v5)[2];
		v11 = *(__int16*)(v10 + 4 * v7);
		v12 = *(_WORD*)(v10 + 4 * v7 + 2);
		v5[6] = (_DWORD*)((char*)v8 + v11);
		v5[5] = (_DWORD*)((v12 << (32 - (_BYTE)v8 - v11)) | v9);
		if ((int)v8 + v11 >= 16) {
		LABEL_14:
			*(_BYTE*)v5[3] = (unsigned int)v5[5] >> 24;
			v30 = v5[5];
			v31 = (char*)v5[3] + 1;
			v5[3] = v31;
			*v31 = BYTE2(v30);
			v32 = (int)(v5[6] - 4);
			v33 = (_DWORD*)((_DWORD)v5[5] << 16);
			v5[3] = (_DWORD*)((char*)v5[3] + 1);
			v5[6] = (_DWORD*)v32;
			v5[5] = v33;
			goto LABEL_15;
		}
	}
LABEL_15:
	v34 = *(_DWORD*)&byte_587000[8 * (a5 >> 9) + 314824] + 9;
	v35 = a5 & 0x1FF | (*(unsigned __int16*)&byte_587000[8 * (a5 >> 9) + 314828] << 9);
	if (v34 <= 16) {
		v47 = v5[6];
		v48 = 32 - (_BYTE)v47 - v34;
		v49 = (int)v47 + v34;
		result = v35 << v48;
		v50 = (unsigned int)v5[5];
		v5[6] = (_DWORD*)v49;
		v5[5] = (_DWORD*)(result | v50);
		if (v49 < 16)
			return result;
		goto LABEL_21;
	}
	v36 = v5[6];
	v37 = (unsigned int)v5[5];
	v38 = *(_DWORD*)&byte_587000[8 * (a5 >> 9) + 314824] - 7;
	v5[6] = (_DWORD*)((char*)v36 + v38);
	v39 = (v35 >> 16 << (32 - (_BYTE)v36 - v38)) | v37;
	v5[5] = (_DWORD*)v39;
	if ((int)v36 + v38 >= 16) {
		*(_BYTE*)v5[3] = HIBYTE(v39);
		v40 = v5[5];
		v41 = (char*)v5[3] + 1;
		v5[3] = v41;
		*v41 = BYTE2(v40);
		v42 = (int)(v5[6] - 4);
		v43 = (_DWORD*)((_DWORD)v5[5] << 16);
		v5[3] = (_DWORD*)((char*)v5[3] + 1);
		v5[6] = (_DWORD*)v42;
		v5[5] = v43;
	}
	v44 = v5[6];
	v45 = ((unsigned __int16)v35 << (16 - (_BYTE)v44)) | (unsigned int)v5[5];
	result = (int)(v44 + 4);
	v5[5] = (_DWORD*)v45;
	v5[6] = v44 + 4;
	if ((int)(v44 + 4) >= 16) {
	LABEL_21:
		*(_BYTE*)v5[3] = (unsigned int)v5[5] >> 24;
		v51 = v5[5];
		v52 = (char*)v5[3] + 1;
		v5[3] = v52;
		*v52 = BYTE2(v51);
		v53 = (int)(v5[6] - 4);
		result = (_DWORD)v5[5] << 16;
		v5[3] = (_DWORD*)((char*)v5[3] + 1);
		v5[6] = (_DWORD*)v53;
		v5[5] = (_DWORD*)result;
	}
	return result;
}

//----- (0057E7D0) --------------------------------------------------------
int __thiscall sub_57E7D0(_DWORD** this) {
	_DWORD** v1; // esi
	_DWORD* v2;  // edi
	int v3;      // edx
	_DWORD* v4;  // ecx
	_BYTE* v5;   // ebx
	int v6;      // ecx
	_DWORD* v7;  // eax
	_DWORD* v8;  // edi
	int v9;      // ebx

	v1 = this;
	if ((int)--*this[2] <= 0)
		sub_57E2C0(this);
	++*((_WORD*)v1[1] + 273);
	v2 = v1[6];
	v3 = *(__int16*)((*v1)[2] + 1092);
	v1[5] = (_DWORD*)((*(unsigned __int16*)((*v1)[2] + 1094) << (32 - (_BYTE)v2 - v3)) | (unsigned int)v1[5]);
	v1[6] = (_DWORD*)((char*)v2 + v3);
	if ((int)v2 + v3 >= 16) {
		*(_BYTE*)v1[3] = (unsigned int)v1[5] >> 24;
		v4 = v1[5];
		v5 = (char*)v1[3] + 1;
		v1[3] = v5;
		*v5 = BYTE2(v4);
		v6 = (int)(v1[6] - 4);
		v7 = (_DWORD*)((_DWORD)v1[5] << 16);
		v1[3] = (_DWORD*)((char*)v1[3] + 1);
		v1[6] = (_DWORD*)v6;
		v1[5] = v7;
	}
	if ((int)v1[6] > 0) {
		do {
			*(_BYTE*)v1[3] = (unsigned int)v1[5] >> 24;
			v8 = v1[5];
			v9 = (int)(v1[6] - 2);
			v1[3] = (_DWORD*)((char*)v1[3] + 1);
			v1[6] = (_DWORD*)v9;
			v1[5] = (_DWORD*)((_DWORD)v8 << 8);
		} while (v9 > 0);
	}
	return (char*)v1[3] - (char*)v1[4];
}

//----- (0057E8A0) --------------------------------------------------------
_DWORD* __thiscall sub_57E8A0(_DWORD* this) {
	_DWORD* v1;          // ebx
	unsigned __int8* v2; // eax

	v1 = this;
	sub_57DD90(this);
	v2 = (unsigned __int8*)operator_new(0x224u);
	v1[33] = v2;
	qmemcpy(v2, &byte_587000[315976], 0x224u);
	qmemcpy(v1 + 1, &byte_587000[315848], 0x80u);
	return v1;
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (0057E910) --------------------------------------------------------
void __thiscall sub_57E910(LPVOID* this) {
	LPVOID* v1; // esi

	v1 = this;
	operator_delete(this[33]);
	sub_57DDC0(v1);
}

//----- (0057E970) --------------------------------------------------------
int __thiscall sub_57E970(void** this) {
	qmemcpy(this[33], &byte_587000[315976], 0x224u);
	qmemcpy(this + 1, &byte_587000[315848], 0x80u);
	return sub_57DDD0(this);
}

//----- (0057E9A0) --------------------------------------------------------
_DWORD* __thiscall sub_57E9A0(_DWORD* this) {
	_DWORD* v1; // esi

	v1 = this;
	*this = operator_new(0x10000u);
	v1[1] = 0;
	sub_57E8A0(v1 + 2);
	v1[37] = 0;
	v1[36] = 0;
	return v1;
}
// 5667CB: using guessed type void *__cdecl operator_new(unsigned int);

//----- (0057EA00) --------------------------------------------------------
void __thiscall sub_57EA00(LPVOID* this) {
	LPVOID* v1; // esi
	LPVOID* v2; // ecx
	LPVOID* v4; // [esp+4h] [ebp-10h]

	v1 = this;
	v4 = this;
	v2 = 0;
	if (v4)
		v2 = v1 + 2;
	sub_57E910(v2);
	operator_delete(*v1);
}

//----- (0057EA60) --------------------------------------------------------
int __thiscall sub_57EA60(int this) {
	*(_DWORD*)(this + 148) = 0;
	*(_DWORD*)(this + 144) = 0;
	*(_DWORD*)(this + 4) = 0;
	return sub_57E970((void**)(this + 8));
}

//----- (0057EA80) --------------------------------------------------------
int __thiscall sub_57EA80(_DWORD* this, _BYTE* a2, _DWORD* a3, unsigned int a4, _DWORD* a5) {
	unsigned __int8* v5; // ebp
	_DWORD* v6;          // ebx
	unsigned int v7;     // edx
	int v8;              // esi
	int v9;              // eax
	int v10;             // ecx
	unsigned int v11;    // eax
	int v12;             // esi
	int v13;             // eax
	int v14;             // edi
	int v15;             // edx
	int v16;             // ecx
	int v17;             // eax
	int v18;             // ecx
	int v19;             // eax
	char* v20;           // ecx
	__int16 v21;         // si
	int v22;             // edi
	_DWORD* v23;         // edx
	int v24;             // esi
	int v25;             // ecx
	int v26;             // eax
	int v27;             // esi
	int v28;             // eax
	int v29;             // edi
	int v30;             // esi
	int v31;             // esi
	int v32;             // ecx
	int v33;             // edx
	int v34;             // esi
	int v35;             // ecx
	unsigned int v36;    // eax
	int v37;             // esi
	int v38;             // edi
	int v39;             // eax
	int v40;             // ecx
	unsigned int v41;    // eax
	int v42;             // edi
	int v43;             // eax
	int v44;             // edx
	_BYTE* v45;          // edi
	int v46;             // ebp
	int v47;             // eax
	int v48;             // ecx
	int v49;             // esi
	int v50;             // esi
	int v51;             // edx
	const void* v52;     // esi
	unsigned int v53;    // ecx
	int v54;             // esi
	int v55;             // edi
	_BYTE* v56;          // ebp
	int v57;             // edi
	int v58;             // edx
	void* v59;           // edi
	unsigned int v60;    // ecx
	_BYTE* v61;          // esi
	int v63;             // [esp+10h] [ebp-464h]
	int i;               // [esp+10h] [ebp-464h]
	int v65;             // [esp+10h] [ebp-464h]
	int v66;             // [esp+14h] [ebp-460h]
	int v67;             // [esp+14h] [ebp-460h]
	_BYTE* v68;          // [esp+14h] [ebp-460h]
	unsigned int v69;    // [esp+18h] [ebp-45Ch]
	int v70;             // [esp+1Ch] [ebp-458h]
	int v71;             // [esp+1Ch] [ebp-458h]
	_BYTE* v72;          // [esp+20h] [ebp-454h]
	unsigned int v73;    // [esp+24h] [ebp-450h]
	_BYTE* v74;          // [esp+28h] [ebp-44Ch]
	char v75[1096];      // [esp+2Ch] [ebp-448h]

	v5 = (unsigned __int8*)a4;
	v6 = this;
	v7 = a4 + *a5;
	v74 = a2;
	v73 = a4;
	v69 = a4 + *a5;
	v72 = &a2[*a3];
	this[37] = 0;
	if (a4 >= v7)
		return 0;
	while (1) {
		v8 = v6[37];
		if (v8 < 4) {
			if ((unsigned int)v5 >= v7) {
				v9 = -1;
				v6[37] = 0;
				v63 = -1;
				goto LABEL_9;
			}
			v10 = (*v5++ << (24 - v8)) | v6[36];
			v6[36] = v10;
			a4 = (unsigned int)v5;
			v6[37] = v8 + 8;
		}
		v11 = v6[36];
		v6[36] = 16 * v11;
		v63 = v11 >> 28;
		v6[37] -= 4;
		v9 = v11 >> 28;
	LABEL_9:
		v12 = v6[2 * v9 + 3];
		if (!v12) {
			v13 = *(__int16*)(v6[35] + 2 * v6[2 * v9 + 4]);
			goto LABEL_18;
		}
		v14 = v6[37];
		if (v14 >= v12)
			goto LABEL_15;
		if ((unsigned int)v5 < v7) {
			v16 = (*v5++ << (24 - v14)) | v6[36];
			v6[36] = v16;
			a4 = (unsigned int)v5;
			v6[37] = v14 + 8;
		LABEL_15:
			v15 = v6[36] >> (32 - v12);
			v6[36] <<= v12;
			v6[37] -= v12;
			v9 = v63;
			goto LABEL_16;
		}
		v6[37] = 0;
		v15 = -1;
	LABEL_16:
		v17 = v15 + v6[2 * v9 + 4];
		if (v17 >= 274)
			return 0;
		v13 = *(__int16*)(v6[35] + 2 * v17);
	LABEL_18:
		++*(_WORD*)(v6[2] + 2 * v13);
		// dprintf("decompress: %d", v13);
		if (v13 < 256) {
			if (a2 < v72) {
				*a2++ = v13;
				v18 = v6[1];
				v6[1] = v18 + 1;
				*(_BYTE*)((unsigned __int16)v18 + *v6) = v13;
				goto LABEL_73;
			}
			return 0;
		}
		if (v13 == 272) {
			sub_57DEA0(v6 + 2, v75);
			v19 = 0;
			v20 = v75;
			do {
				v21 = *(_WORD*)v20;
				v20 += 4;
				*(_WORD*)(v19 + v6[35]) = v21;
				v19 += 2;
			} while (v19 < 548);
			v22 = 0;
			v23 = v6 + 4;
			v70 = 0;
			v66 = 16;
			while (1) {
				for (i = 0;; ++i) {
					v24 = v6[37];
					if (v24 >= 1)
						goto LABEL_29;
					if ((unsigned int)v5 >= v69)
						break;
					v25 = (*v5++ << (24 - v24)) | v6[36];
					v6[36] = v25;
					v6[37] = v24 + 8;
				LABEL_29:
					v26 = v6[36] >> 31;
					v27 = v6[37] - 1;
					v6[36] *= 2;
					v6[37] = v27;
					if (v26)
						goto LABEL_32;
				}
				v6[37] = 0;
			LABEL_32:
				v22 += i;
				*(v23 - 1) = v22;
				*v23 = v70;
				v23 += 2;
				v70 += 1 << v22;
				if (!--v66) {
					a4 = (unsigned int)v5;
					goto LABEL_73;
				}
			}
		}
		if (v13 == 273)
			break;
		if (v13 < 264) {
			v28 = v13 - 256;
			goto LABEL_43;
		}
		v29 = *(_DWORD*)&byte_587000[8 * v13 + 314416];
		v30 = v6[37];
		if (v30 >= v29)
			goto LABEL_41;
		if ((unsigned int)v5 < v69) {
			v32 = (*v5++ << (24 - v30)) | v6[36];
			v6[36] = v32;
			a4 = (unsigned int)v5;
			v6[37] = v30 + 8;
		LABEL_41:
			v31 = v6[36] >> (32 - v29);
			v33 = v6[36] << v29;
			v6[37] -= v29;
			v6[36] = v33;
			goto LABEL_42;
		}
		v6[37] = 0;
		v31 = -1;
	LABEL_42:
		v28 = v31 + *(_DWORD*)&byte_587000[8 * v13 + 314420];
	LABEL_43:
		v34 = v6[37];
		v67 = v28;
		if (v34 < 3) {
			if ((unsigned int)v5 >= v69) {
				v6[37] = 0;
				v71 = -1;
				goto LABEL_48;
			}
			v35 = (*v5++ << (24 - v34)) | v6[36];
			v6[36] = v35;
			a4 = (unsigned int)v5;
			v6[37] = v34 + 8;
		}
		v36 = v6[36];
		v6[36] = 8 * v36;
		v71 = v36 >> 29;
		v6[37] -= 3;
	LABEL_48:
		v65 = 0;
		v37 = *(_DWORD*)&byte_587000[8 * v71 + 316592] + 9;
		if (v37 <= 8)
			goto LABEL_55;
		v38 = v6[37];
		v37 = *(_DWORD*)&byte_587000[8 * v71 + 316592] + 1;
		if (v38 >= 8)
			goto LABEL_53;
		if ((unsigned int)v5 < v69) {
			v40 = (*v5++ << (24 - v38)) | v6[36];
			v6[36] = v40;
			a4 = (unsigned int)v5;
			v6[37] = v38 + 8;
		LABEL_53:
			v41 = v6[36];
			v6[36] = v41 << 8;
			v6[37] -= 8;
			v39 = v41 >> 24;
			goto LABEL_54;
		}
		v6[37] = 0;
		v39 = -1;
	LABEL_54:
		v65 = v39 << v37;
	LABEL_55:
		v42 = v6[37];
		if (v42 >= v37)
			goto LABEL_59;
		if ((unsigned int)v5 < v69) {
			v6[36] |= *v5 << (24 - v42);
			a4 = (unsigned int)(v5 + 1);
			v6[37] = v42 + 8;
		LABEL_59:
			v43 = v6[36] >> (32 - v37);
			v44 = v6[36] << v37;
			v6[37] -= v37;
			v6[36] = v44;
			goto LABEL_60;
		}
		v6[37] = 0;
		v43 = -1;
	LABEL_60:
		v45 = a2;
		v46 = (*(_DWORD*)&byte_587000[8 * v71 + 316596] << 9) + (v65 | v43);
		v47 = v67 + 4;
		v68 = &a2[v67 + 4];
		// dprintf("length: %d, distance: %d", v47, v46);
		if (v68 > v72)
			return 0;
		v48 = v6[1] - v46;
		if (v47 >= v46) {
			v50 = (unsigned __int16)v48;
			if ((unsigned __int16)v48 + v46 <= 0x10000) {
				v53 = v46;
				v52 = (const void*)(*v6 + v50);
			} else {
				v51 = 0x10000 - (unsigned __int16)v48;
				qmemcpy(a2, (const void*)(*v6 + (unsigned __int16)v48),
					0x10000 - (unsigned __int16)v48);
				v52 = (const void*)*v6;
				v53 = v46 - v51;
				v45 = &a2[v51];
			}
			qmemcpy(v45, v52, v53);
			v54 = 0;
			v55 = v47 - v46;
			if (v47 - v46 > 0) {
				v56 = &a2[v46];
				do {
					++v54;
					v56[v54 - 1] = a2[v54 - 1];
				} while (v54 < v55);
			}
		} else {
			v49 = (unsigned __int16)v48;
			if (v49 + v47 <= 0x10000) {
				qmemcpy(a2, (const void*)(*v6 + v49), v47);
			} else {
				qmemcpy(a2, (const void*)(*v6 + v49), 0x10000 - v49);
				qmemcpy(&a2[0x10000 - v49], (const void*)*v6, v47 - (0x10000 - v49));
			}
		}
		v57 = v6[1] & 0xFFFF;
		if (v57 + v47 <= 0x10000) {
			v61 = a2;
			v60 = v47;
			v59 = (void*)(*v6 + v57);
		} else {
			v58 = 0x10000 - v57;
			qmemcpy((void*)(*v6 + v57), a2, 0x10000 - v57);
			v59 = (void*)*v6;
			v60 = v47 - v58;
			v61 = &a2[v58];
		}
		v5 = (unsigned __int8*)a4;
		qmemcpy(v59, v61, v60);
		v6[1] += v47;
		a2 = v68;
	LABEL_73:
		if ((unsigned int)v5 >= v69)
			return 0;
		v7 = v69;
	}
	if (a3)
		*a3 += v74 - a2;
	if (a5)
		*a5 += v73 - (_DWORD)v5;
	return 1;
}

//----- (0057F160) --------------------------------------------------------
_DWORD* __thiscall sub_57F160(int this, int a2, int a3) {
	_DWORD* result; // eax
	int v4;         // edx
	_BYTE* v5;      // ecx
	int v6;         // edx
	int v7;         // ecx
	int v8;         // edx

	result = (_DWORD*)this;
	v4 = *(_DWORD*)(this + 24);
	*(_DWORD*)(this + 20) |= a3 << (32 - v4 - a2);
	*(_DWORD*)(this + 24) = v4 + a2;
	if (v4 + a2 >= 16) {
		**(_BYTE**)(this + 12) = *(_DWORD*)(this + 20) >> 24;
		v5 = (_BYTE*)(*(_DWORD*)(this + 12) + 1);
		v6 = result[5] >> 16;
		result[3] = v5;
		*v5 = v6;
		v7 = result[5];
		v8 = result[6] - 16;
		++result[3];
		result[6] = v8;
		result[5] = v7 << 16;
	}
	return result;
}

//----- (0057F1D0) --------------------------------------------------------
char __cdecl sub_57F1D0(float2* a1) {
	char v1;            // bl
	int v2;             // edi
	double v3;          // st7
	double v4;          // st6
	double v5;          // st7
	unsigned __int8 v7; // [esp+Ch] [ebp-4h]

	v1 = 0;
	v2 = nox_float2int(a1->field_0);
	v7 = nox_float2int(a1->field_4) % 23;
	v3 = (double)(unsigned __int8)(v2 % 23);
	if (v3 >= 11.5) {
		v4 = (double)v7;
		if (v4 >= 11.5)
			v1 = 4;
		if (v4 <= 11.5)
			v1 |= 1u;
	}
	if (v3 <= 11.5) {
		v5 = (double)v7;
		if (v5 >= 11.5)
			v1 |= 8u;
		if (v5 <= 11.5)
			v1 |= 2u;
	}
	return v1;
}

//----- (0057F2A0) --------------------------------------------------------
int __cdecl sub_57F2A0(float2* a1, int a2, int a3) {
	int v3;     // esi
	int v4;     // eax
	int result; // eax
	int v6;     // eax
	float v7;   // [esp+0h] [ebp-Ch]
	float v8;   // [esp+0h] [ebp-Ch]

	v7 = a1->field_0 - (double)(23 * a2);
	v3 = nox_float2int(v7);
	v8 = a1->field_4 - (double)(23 * a3);
	v4 = nox_float2int(v8);
	if (v3 <= v4) {
		LOBYTE(v4) = 22 - v3 <= v4;
		v6 = v4 - 1;
		LOBYTE(v6) = v6 & 0xFD;
		result = v6 + 3;
	} else {
		LOBYTE(v4) = 22 - v3 <= v4;
		result = v4 + 1;
	}
	return result;
}

#if 0
//----- (0057FA20) --------------------------------------------------------
int __usercall sub_57FA20@<eax > (int a1@<ebp > )
{
    return sub_40E3D0((int*)(a1 - 16));
}

//----- (0057FA28) --------------------------------------------------------
int __usercall sub_57FA28@<eax > (int a1@<ebp > )
{
    return sub_40E3D0((int*)(a1 - 20));
}

//----- (0057FA30) --------------------------------------------------------
int __cdecl SEH_40E260(int a1, int a2, int a3, int a4)
{
    return __CxxFrameHandler((int)& byte_581450[11984], a1, a2, a3, a4);
}

//----- (0057FA40) --------------------------------------------------------
int __usercall sub_57FA40@<eax > (int a1@<ebp > )
{
    return sub_40E3D0((int*)(a1 - 16));
}

//----- (0057FA48) --------------------------------------------------------
int __usercall sub_57FA48@<eax > (int a1@<ebp > )
{
    return sub_40E3D0((int*)(a1 - 20));
}

//----- (0057FA50) --------------------------------------------------------
int __cdecl SEH_40E320(int a1, int a2, int a3, int a4)
{
    return __CxxFrameHandler((int)& byte_581450[12032], a1, a2, a3, a4);
}

//----- (0057FB20) --------------------------------------------------------
void __usercall sub_57FB20@<eax > (int a1@<ebp > )
{
    operator_delete(*(LPVOID*)(a1 - 16));
}

//----- (0057FB2B) --------------------------------------------------------
void __usercall sub_57FB2B@<eax > (int a1@<ebp > )
{
    operator_delete(*(LPVOID*)(a1 + 4));
}

//----- (0057FB36) --------------------------------------------------------
void __usercall sub_57FB36@<eax > (int a1@<ebp > )
{
    operator_delete(*(LPVOID*)(a1 + 4));
}

//----- (0057FB41) --------------------------------------------------------
void __usercall sub_57FB41@<eax > (int a1@<ebp > )
{
    operator_delete(*(LPVOID*)(a1 + 4));
}

//----- (0057FB57) --------------------------------------------------------
void __usercall sub_57FB57@<eax > (int a1@<ebp > )
{
    operator_delete(*(LPVOID*)(a1 - 16));
}

//----- (0057FB62) --------------------------------------------------------
void __usercall sub_57FB62@<eax > (int a1@<ebp > )
{
    operator_delete(*(LPVOID*)(a1 - 16));
}

//----- (0057FB6D) --------------------------------------------------------
void __usercall sub_57FB6D@<eax > (int a1@<ebp > )
{
    operator_delete(*(LPVOID*)(a1 - 16));
}

//----- (0057FBB0) --------------------------------------------------------
int __usercall sub_57FBB0@<eax > (int a1@<ebp > )
{
    return sub_5562D0(*(_DWORD * *)(a1 - 16));
}

//----- (0057FBB8) --------------------------------------------------------
int __usercall sub_57FBB8@<eax > (int a1@<ebp > )
{
    return sub_559AB0(*(_DWORD*)(a1 - 16) + 40);
}

//----- (0057FBC3) --------------------------------------------------------
int __cdecl SEH_556500(int a1, int a2, int a3, int a4)
{
    return __CxxFrameHandler((int)& byte_581450[12456], a1, a2, a3, a4);
}

//----- (0057FBD0) --------------------------------------------------------
int __usercall sub_57FBD0@<eax > (int a1@<ebp > )
{
    return sub_5562D0(*(_DWORD * *)(a1 - 16));
}

//----- (0057FBD8) --------------------------------------------------------
int __usercall sub_57FBD8@<eax > (int a1@<ebp > )
{
    return sub_559AB0(*(_DWORD*)(a1 - 16) + 40);
}

//----- (0057FBE3) --------------------------------------------------------
int __cdecl SEH_556570(int a1, int a2, int a3, int a4)
{
    return __CxxFrameHandler((int)& byte_581450[12504], a1, a2, a3, a4);
}

//----- (0057FBF0) --------------------------------------------------------
int __usercall sub_57FBF0@<eax > (int a1@<ebp > )
{
    return sub_5562D0(*(_DWORD * *)(a1 - 16));
}

//----- (0057FBF8) --------------------------------------------------------
int __usercall sub_57FBF8@<eax > (int a1@<ebp > )
{
    return sub_559AB0(*(_DWORD*)(a1 - 16) + 40);
}

//----- (0057FC03) --------------------------------------------------------
int __cdecl SEH_5565E0(int a1, int a2, int a3, int a4)
{
    return __CxxFrameHandler((int)& byte_581450[12552], a1, a2, a3, a4);
}

//----- (0057FC50) --------------------------------------------------------
int __usercall sub_57FC50@<eax > (int a1@<ebp > )
{
    return sub_559AE0(*(_DWORD*)(a1 - 16) + 4);
}
// 559AE0: using guessed type int __thiscall sub_559AE0(_DWORD);

//----- (0057FC5B) --------------------------------------------------------
int __cdecl SEH_557C70(int a1, int a2, int a3, int a4)
{
    return __CxxFrameHandler((int)& byte_581450[12648], a1, a2, a3, a4);
}

//----- (0057FC90) --------------------------------------------------------
wstring* __usercall sub_57FC90@<eax > (int a1@<ebp > )
{
    return sub_57211C(*(HIMC * *)(a1 - 16));
}

//----- (0057FC99) --------------------------------------------------------
int __cdecl SEH_5704C0(int a1, int a2, int a3, int a4)
{
    return __CxxFrameHandler((int)& byte_581450[12728], a1, a2, a3, a4);
}

//----- (0057FCB0) --------------------------------------------------------
wstring* __usercall sub_57FCB0@<eax > (int a1@<ebp > )
{
    return sub_57211C(*(HIMC * *)(a1 - 16));
}

//----- (0057FCB9) --------------------------------------------------------
int __cdecl SEH_570570(int a1, int a2, int a3, int a4)
{
    return __CxxFrameHandler((int)& byte_581450[12768], a1, a2, a3, a4);
}

//----- (0057FCD0) --------------------------------------------------------
void sub_57FCD0()
{
    sub_5717C0();
}

//----- (0057FCE1) --------------------------------------------------------
int __cdecl SEH_570B90(int a1, int a2, int a3, int a4)
{
    return __CxxFrameHandler((int)& byte_581450[12808], a1, a2, a3, a4);
}

//----- (0057FD00) --------------------------------------------------------
wstring* __usercall sub_57FD00@<eax > (int a1@<ebp > )
{
    return sub_570CE0((int*)(a1 - 36));
}

//----- (0057FD09) --------------------------------------------------------
int __cdecl SEH_571810(int a1, int a2, int a3, int a4)
{
    return __CxxFrameHandler((int)& byte_581450[12936], a1, a2, a3, a4);
}

//----- (0057FD13) --------------------------------------------------------
int* __usercall sub_57FD13@<eax > (int a1@<ebp > )
{
    return sub_573DE0((int*)(a1 - 48));
}

//----- (0057FD1C) --------------------------------------------------------
int* __usercall sub_57FD1C@<eax > (int a1@<ebp > )
{
    return sub_573DE0((int*)(a1 - 28));
}

//----- (0057FD25) --------------------------------------------------------
int* __usercall sub_57FD25@<eax > (int a1@<ebp > )
{
    return sub_573DE0((int*)(a1 - 92));
}

//----- (0057FD2E) --------------------------------------------------------
int* __usercall sub_57FD2E@<eax > (int a1@<ebp > )
{
    return sub_573DE0((int*)(a1 - 116));
}

//----- (0057FD37) --------------------------------------------------------
int __cdecl SEH_571C0E(int a1, int a2, int a3, int a4)
{
    return __CxxFrameHandler((int)& byte_581450[12976], a1, a2, a3, a4);
}

//----- (0057FD41) --------------------------------------------------------
wstring* __usercall sub_57FD41@<eax > (int a1@<ebp > )
{
    return sub_570CE0((int*)(*(_DWORD*)(a1 - 32) + 8));
}

//----- (0057FD4D) --------------------------------------------------------
wstring* __usercall sub_57FD4D@<eax > (int a1@<ebp > )
{
    return sub_570CE0((int*)(*(_DWORD*)(a1 - 32) + 24));
}

//----- (0057FD59) --------------------------------------------------------
wstring* __usercall sub_57FD59@<eax > (int a1@<ebp > )
{
    return sub_570CE0((int*)(*(_DWORD*)(a1 - 32) + 40));
}

//----- (0057FD65) --------------------------------------------------------
int __cdecl SEH_572045(int a1, int a2, int a3, int a4)
{
    return __CxxFrameHandler((int)& byte_581450[13040], a1, a2, a3, a4);
}

//----- (0057FD6F) --------------------------------------------------------
wstring* __usercall sub_57FD6F@<eax > (int a1@<ebp > )
{
    return sub_570CE0((int*)(*(_DWORD*)(a1 - 16) + 8));
}

//----- (0057FD7B) --------------------------------------------------------
wstring* __usercall sub_57FD7B@<eax > (int a1@<ebp > )
{
    return sub_570CE0((int*)(*(_DWORD*)(a1 - 16) + 24));
}

//----- (0057FD87) --------------------------------------------------------
wstring* __usercall sub_57FD87@<eax > (int a1@<ebp > )
{
    return sub_570CE0((int*)(*(_DWORD*)(a1 - 16) + 40));
}

//----- (0057FD93) --------------------------------------------------------
int __cdecl SEH_57211C(int a1, int a2, int a3, int a4)
{
    return __CxxFrameHandler((int)& byte_581450[13096], a1, a2, a3, a4);
}

//----- (0057FD9D) --------------------------------------------------------
BOOL __usercall sub_57FD9D@<eax > (int a1@<ebp > )
{
    return sub_574EC0(a1 - 20);
}

//----- (0057FDA6) --------------------------------------------------------
wstring* __usercall sub_57FDA6@<eax > (int a1@<ebp > )
{
    return sub_570CE0((int*)(a1 - 40));
}

//----- (0057FDAF) --------------------------------------------------------
int __cdecl SEH_57222A(int a1, int a2, int a3, int a4)
{
    return __CxxFrameHandler((int)& byte_581450[13152], a1, a2, a3, a4);
}

//----- (0057FDB9) --------------------------------------------------------
BOOL __usercall sub_57FDB9@<eax > (int a1@<ebp > )
{
    return sub_574EC0(a1 - 20);
}

//----- (0057FDC2) --------------------------------------------------------
wstring* __usercall sub_57FDC2@<eax > (int a1@<ebp > )
{
    return sub_570CE0((int*)(a1 - 40));
}

//----- (0057FDCB) --------------------------------------------------------
int __cdecl SEH_572333(int a1, int a2, int a3, int a4)
{
    return __CxxFrameHandler((int)& byte_581450[13200], a1, a2, a3, a4);
}

//----- (0057FDD5) --------------------------------------------------------
BOOL __usercall sub_57FDD5@<eax > (int a1@<ebp > )
{
    return sub_574EC0(a1 - 20);
}

//----- (0057FDDE) --------------------------------------------------------
wstring* __usercall sub_57FDDE@<eax > (int a1@<ebp > )
{
    return sub_570CE0((int*)(a1 - 304));
}

//----- (0057FDEA) --------------------------------------------------------
int __cdecl SEH_572442(int a1, int a2, int a3, int a4)
{
    return __CxxFrameHandler((int)& byte_581450[13248], a1, a2, a3, a4);
}

//----- (0057FE07) --------------------------------------------------------
BOOL __usercall sub_57FE07@<eax > (int a1@<ebp > )
{
    return sub_574EC0(a1 - 20);
}

//----- (0057FE10) --------------------------------------------------------
int __cdecl SEH_572A06(int a1, int a2, int a3, int a4)
{
    return __CxxFrameHandler((int)& byte_581450[13336], a1, a2, a3, a4);
}

//----- (0057FE1A) --------------------------------------------------------
int* __usercall sub_57FE1A@<eax > (int a1@<ebp > )
{
    return sub_574660((int*)(a1 - 36));
}

//----- (0057FE23) --------------------------------------------------------
int* __usercall sub_57FE23@<eax > (int a1@<ebp > )
{
    return sub_574660((int*)(a1 - 60));
}

//----- (0057FE2C) --------------------------------------------------------
int __cdecl SEH_572BD6(int a1, int a2, int a3, int a4)
{
    return __CxxFrameHandler((int)& byte_581450[13376], a1, a2, a3, a4);
}

//----- (0057FE36) --------------------------------------------------------
BOOL __usercall sub_57FE36@<eax > (int a1@<ebp > )
{
    return sub_574EC0(a1 - 20);
}

//----- (0057FE3F) --------------------------------------------------------
int** __usercall sub_57FE3F@<eax > (int a1@<ebp > )
{
    return sub_5705D0((int**)(a1 - 60));
}

//----- (0057FE48) --------------------------------------------------------
int __cdecl SEH_573153(int a1, int a2, int a3, int a4)
{
    return __CxxFrameHandler((int)& byte_581450[13424], a1, a2, a3, a4);
}

//----- (0057FE52) --------------------------------------------------------
BOOL __usercall sub_57FE52@<eax > (int a1@<ebp > )
{
    return sub_574EC0(a1 - 20);
}

//----- (0057FE5B) --------------------------------------------------------
int** __usercall sub_57FE5B@<eax > (int a1@<ebp > )
{
    return sub_5705D0((int**)(a1 - 60));
}

//----- (0057FE64) --------------------------------------------------------
int __cdecl SEH_57330C(int a1, int a2, int a3, int a4)
{
    return __CxxFrameHandler((int)& byte_581450[13472], a1, a2, a3, a4);
}

//----- (0057FE6E) --------------------------------------------------------
LPVOID* __usercall sub_57FE6E@<eax > (int a1@<ebp > )
{
    return sub_574930((LPVOID*)(a1 - 32));
}

//----- (0057FE77) --------------------------------------------------------
wstring* __usercall sub_57FE77@<eax > (int a1@<ebp > )
{
    return sub_570CE0((int*)(a1 - 60));
}

//----- (0057FE80) --------------------------------------------------------
wstring* __usercall sub_57FE80@<eax > (int a1@<ebp > )
{
    return sub_570CE0((int*)(a1 - 92));
}

//----- (0057FE89) --------------------------------------------------------
int __cdecl SEH_573401(int a1, int a2, int a3, int a4)
{
    return __CxxFrameHandler((int)& byte_581450[13520], a1, a2, a3, a4);
}

//----- (0057FE93) --------------------------------------------------------
BOOL __usercall sub_57FE93@<eax > (int a1@<ebp > )
{
    return sub_574EC0(a1 - 20);
}

//----- (0057FE9C) --------------------------------------------------------
int __cdecl SEH_57366C(int a1, int a2, int a3, int a4)
{
    return __CxxFrameHandler((int)& byte_581450[13576], a1, a2, a3, a4);
}

//----- (0057FEA6) --------------------------------------------------------
BOOL __usercall sub_57FEA6@<eax > (int a1@<ebp > )
{
    return sub_574EC0(a1 - 20);
}

//----- (0057FEAF) --------------------------------------------------------
int __cdecl SEH_57381A(int a1, int a2, int a3, int a4)
{
    return __CxxFrameHandler((int)& byte_581450[13616], a1, a2, a3, a4);
}

//----- (0057FEB9) --------------------------------------------------------
BOOL __usercall sub_57FEB9@<eax > (int a1@<ebp > )
{
    return sub_574EC0(a1 - 20);
}

//----- (0057FEC2) --------------------------------------------------------
int __cdecl SEH_57390B(int a1, int a2, int a3, int a4)
{
    return __CxxFrameHandler((int)& byte_581450[13656], a1, a2, a3, a4);
}

//----- (0057FECC) --------------------------------------------------------
BOOL __usercall sub_57FECC@<eax > (int a1@<ebp > )
{
    return sub_574EC0(a1 - 20);
}

//----- (0057FED5) --------------------------------------------------------
int __cdecl SEH_5739D2(int a1, int a2, int a3, int a4)
{
    return __CxxFrameHandler((int)& byte_581450[13696], a1, a2, a3, a4);
}

//----- (0057FEE0) --------------------------------------------------------
void __usercall sub_57FEE0(int a1@<ebp > )
{
    std___Lockit__destructor_Lockit((std___Lockit*)(a1 - 16));
}
// 57F713: using guessed type void __thiscall std___Lockit__destructor_Lockit(std___Lockit *__hidden this);

//----- (0057FEE9) --------------------------------------------------------
int __cdecl SEH_574410(int a1, int a2, int a3, int a4)
{
    return __CxxFrameHandler((int)& byte_581450[13736], a1, a2, a3, a4);
}

//----- (0057FF00) --------------------------------------------------------
void __usercall sub_57FF00(int a1@<ebp > )
{
    std___Lockit__destructor_Lockit((std___Lockit*)(a1 - 24));
}
// 57F713: using guessed type void __thiscall std___Lockit__destructor_Lockit(std___Lockit *__hidden this);

//----- (0057FF09) --------------------------------------------------------
int __cdecl SEH_5755F0(int a1, int a2, int a3, int a4)
{
    return __CxxFrameHandler((int)& byte_581450[13776], a1, a2, a3, a4);
}

//----- (0057FF20) --------------------------------------------------------
void __usercall sub_57FF20(int a1@<ebp > )
{
    std___Lockit__destructor_Lockit((std___Lockit*)(a1 - 16));
}
// 57F713: using guessed type void __thiscall std___Lockit__destructor_Lockit(std___Lockit *__hidden this);

//----- (0057FF29) --------------------------------------------------------
int __cdecl SEH_575E60(int a1, int a2, int a3, int a4)
{
    return __CxxFrameHandler((int)& byte_581450[13816], a1, a2, a3, a4);
}

//----- (0057FF40) --------------------------------------------------------
void __usercall sub_57FF40(int a1@<ebp > )
{
    std___Lockit__destructor_Lockit((std___Lockit*)(a1 - 32));
}
// 57F713: using guessed type void __thiscall std___Lockit__destructor_Lockit(std___Lockit *__hidden this);

//----- (0057FF49) --------------------------------------------------------
int __cdecl SEH_576A20(int a1, int a2, int a3, int a4)
{
    return __CxxFrameHandler((int)& byte_581450[13856], a1, a2, a3, a4);
}

//----- (0057FF80) --------------------------------------------------------
void __usercall sub_57FF80(int a1@<ebp > )
{
    std___Lockit__destructor_Lockit((std___Lockit*)(a1 - 16));
}
// 57F713: using guessed type void __thiscall std___Lockit__destructor_Lockit(std___Lockit *__hidden this);

//----- (0057FF89) --------------------------------------------------------
int __cdecl SEH_576DA0(int a1, int a2, int a3, int a4)
{
    return __CxxFrameHandler((int)& byte_581450[13936], a1, a2, a3, a4);
}

//----- (0057FFC0) --------------------------------------------------------
void __usercall sub_57FFC0(int a1@<ebp > )
{
    std___Lockit__destructor_Lockit((std___Lockit*)(a1 - 16));
}
// 57F713: using guessed type void __thiscall std___Lockit__destructor_Lockit(std___Lockit *__hidden this);

//----- (0057FFC9) --------------------------------------------------------
int __cdecl SEH_577060(int a1, int a2, int a3, int a4)
{
    return __CxxFrameHandler((int)& byte_581450[14016], a1, a2, a3, a4);
}

//----- (0057FFE0) --------------------------------------------------------
void __usercall sub_57FFE0(int a1@<ebp > )
{
    std___Lockit__destructor_Lockit((std___Lockit*)(a1 - 16));
}
// 57F713: using guessed type void __thiscall std___Lockit__destructor_Lockit(std___Lockit *__hidden this);

//----- (0057FFE9) --------------------------------------------------------
int __cdecl SEH_577100(int a1, int a2, int a3, int a4)
{
    return __CxxFrameHandler((int)& byte_581450[14056], a1, a2, a3, a4);
}

//----- (00580020) --------------------------------------------------------
int __cdecl SEH_577760(int a1, int a2, int a3, int a4)
{
    return __CxxFrameHandler((int)& byte_581450[14136], a1, a2, a3, a4);
}

//----- (00580050) --------------------------------------------------------
void __usercall sub_580050(int a1@<ebp > )
{
    std___Lockit__destructor_Lockit((std___Lockit*)(a1 - 24));
}
// 57F713: using guessed type void __thiscall std___Lockit__destructor_Lockit(std___Lockit *__hidden this);

//----- (00580059) --------------------------------------------------------
int __cdecl SEH_577F90(int a1, int a2, int a3, int a4)
{
    return __CxxFrameHandler((int)& byte_581450[14264], a1, a2, a3, a4);
}

//----- (00580070) --------------------------------------------------------
void __usercall sub_580070(int a1@<ebp > )
{
    std___Lockit__destructor_Lockit((std___Lockit*)(a1 - 16));
}
// 57F713: using guessed type void __thiscall std___Lockit__destructor_Lockit(std___Lockit *__hidden this);

//----- (00580079) --------------------------------------------------------
int __cdecl SEH_578240(int a1, int a2, int a3, int a4)
{
    return __CxxFrameHandler((int)& byte_581450[14304], a1, a2, a3, a4);
}

//----- (00580090) --------------------------------------------------------
void __usercall sub_580090(int a1@<ebp > )
{
    std___Lockit__destructor_Lockit((std___Lockit*)(a1 - 16));
}
// 57F713: using guessed type void __thiscall std___Lockit__destructor_Lockit(std___Lockit *__hidden this);

//----- (00580099) --------------------------------------------------------
int __cdecl SEH_578370(int a1, int a2, int a3, int a4)
{
    return __CxxFrameHandler((int)& byte_581450[14344], a1, a2, a3, a4);
}

//----- (005800B0) --------------------------------------------------------
void sub_5800B0()
{
    sub_5717C0();
}

//----- (005800C1) --------------------------------------------------------
int __cdecl SEH_578810(int a1, int a2, int a3, int a4)
{
    return __CxxFrameHandler((int)& byte_581450[14384], a1, a2, a3, a4);
}

//----- (005800D8) --------------------------------------------------------
int __usercall sub_5800D8@<eax > (int a1@<ebp > )
{
    return sub_57DF70((LPVOID*)(*(_DWORD*)(a1 - 16) + 8));
}

//----- (005800F5) --------------------------------------------------------
int __usercall sub_5800F5@<eax > (int a1@<ebp > )
{
    return sub_57DF70((LPVOID*)(*(_DWORD*)(a1 - 16) + 8));
}

//----- (0058010A) --------------------------------------------------------
int __usercall sub_58010A@<eax > (int a1@<ebp > )
{
    return nullsub_71(a1 - 40);
}
// 57DD80: using guessed type int __thiscall nullsub_71(_DWORD);

//----- (00580112) --------------------------------------------------------
int __cdecl SEH_57D1C0(int a1, int a2, int a3, int a4)
{
    return __CxxFrameHandler((int)& byte_581450[14520], a1, a2, a3, a4);
}

//----- (00580120) --------------------------------------------------------
void __usercall sub_580120@<eax > (int a1@<ebp > )
{
    sub_57DDC0(*(LPVOID * *)(a1 - 16));
}

//----- (00580128) --------------------------------------------------------
int __cdecl SEH_57DF00(int a1, int a2, int a3, int a4)
{
    return __CxxFrameHandler((int)& byte_581450[14560], a1, a2, a3, a4);
}

//----- (00580132) --------------------------------------------------------
void __usercall sub_580132@<eax > (int a1@<ebp > )
{
    sub_57DDC0(*(LPVOID * *)(a1 - 16));
}

//----- (0058013A) --------------------------------------------------------
int __cdecl SEH_57DF70(int a1, int a2, int a3, int a4)
{
    return __CxxFrameHandler((int)& byte_581450[14600], a1, a2, a3, a4);
}

//----- (00580144) --------------------------------------------------------
void __usercall sub_580144@<eax > (int a1@<ebp > )
{
    sub_57DDC0(*(LPVOID * *)(a1 - 16));
}

//----- (0058014C) --------------------------------------------------------
int __cdecl SEH_57E8A0(int a1, int a2, int a3, int a4)
{
    return __CxxFrameHandler((int)& byte_581450[14640], a1, a2, a3, a4);
}

//----- (00580156) --------------------------------------------------------
void __usercall sub_580156@<eax > (int a1@<ebp > )
{
    sub_57DDC0(*(LPVOID * *)(a1 - 16));
}

//----- (0058015E) --------------------------------------------------------
int __cdecl SEH_57E910(int a1, int a2, int a3, int a4)
{
    return __CxxFrameHandler((int)& byte_581450[14680], a1, a2, a3, a4);
}

//----- (0058017A) --------------------------------------------------------
int __usercall sub_58017A@<eax > (int a1@<ebp > )
{
    return sub_57DD70(*(LPVOID * *)(a1 - 16));
}

//----- (00580182) --------------------------------------------------------
int __cdecl SEH_57EA00(int a1, int a2, int a3, int a4)
{
    return __CxxFrameHandler((int)& byte_581450[14760], a1, a2, a3, a4);
}
#endif

void nullsub_2() {}

void sub_4093D0(void) { sub_409560(); }

__int64 sub_416BB0() { return ((__int64(__fastcall*)()) * (_DWORD*)&byte_5D4594[371716])(); }

int sub_448640(void) { return sub_44A400(); }

void nullsub_4(_DWORD a1, _DWORD a2, _DWORD a3, _DWORD a4) {}

void nullsub_26(_DWORD a1) {}

void nullsub_5(void) {}

void nullsub_10(_DWORD a1) {}

int __thiscall sub_42CC50(LPVOID* this) { return sub_42C770(this); }

void sub_49A2E0(void) { nox_alloc_npcs(); }

void nullsub_16(void) {}

void nullsub_12(void) {}

void nullsub_17(void) {}

void nullsub_18(void) {}

void nullsub_11(void) {}

void nullsub_13(void) {}

void nullsub_15(void) {}

void nullsub_14(void) {}

void nullsub_3(void) {}

void nullsub_6(void) {}

void nullsub_19(void) {}

int sub_467460(void) { return sub_4671E0(); }

void __cdecl nox_alloc_npcs_2() { nox_alloc_npcs(); }

void nullsub_8(void) {}
void nullsub_27(_DWORD a1) {}
void nullsub_28(_DWORD a1) {}
void nullsub_30(_DWORD a1) {}
void nullsub_36(void) {}
void nullsub_29(void) {}
void nullsub_35(_DWORD a1, _DWORD a2) {}
void nullsub_34(_DWORD a1, _DWORD a2, _DWORD a3) {}
void nullsub_20(void) {}
void nullsub_24(_DWORD a1) {}
void nullsub_31(_DWORD a1) {}
void nullsub_22(void) {}
void nullsub_23(void) {}
void nullsub_7(void) {}
void nullsub_9(_DWORD a1) {}
void nullsub_33(_DWORD a1, _DWORD a2, _DWORD a3) {}
int __thiscall sub_558800(int (**this)(void)) { return this[385](); }
int __thiscall sub_558810(int (**this)(void)) { return this[386](); }
BOOL sub_444D90() { return 0; }
void sub_511840(void) { sub_5486D0(); }

// ALL OK, 8062 function(s) have been successfully decompiled
