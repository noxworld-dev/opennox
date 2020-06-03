#include "telnetd.h"

#include "../../client/system/parsecmd.h"
#include "../../proto.h"

//----- (00578FF0) --------------------------------------------------------
int sub_578FF0() {
	int v0;               // esi
	int result;           // eax
	SOCKET v2;            // edi
	int v3;               // esi
	wchar_t* v4;          // eax
	wchar_t* v5;          // eax
	wchar_t* v6;          // [esp-8h] [ebp-A8h]
	char* v7;             // [esp-4h] [ebp-A4h]
	u_long argp;          // [esp+8h] [ebp-98h]
	int addrlen;          // [esp+Ch] [ebp-94h]
	struct sockaddr addr; // [esp+10h] [ebp-90h]
	char buf[128];        // [esp+20h] [ebp-80h]

	*(_DWORD*)addr.sa_data = 0;
	*(_DWORD*)&addr.sa_data[4] = 0;
	addr.sa_family = 2;
	*(_DWORD*)&addr.sa_data[8] = 0;
	v0 = 0;
	*(_WORD*)&addr.sa_data[12] = 0;
	result = (int)&byte_5D4594[2516484];
	while (*(int*)result != -1) {
		result += 1044;
		++v0;
		if (result >= (int)&byte_5D4594[2520660])
			return result;
	}
	if (v0 != -1) {
		addrlen = 16;
		v2 = accept(*(SOCKET*)&byte_587000[311480], &addr, &addrlen);
		if (v2 == -1) {
			result = WSAGetLastError();
			if (result != 10035)
				result = sub_578F20(-4);
		} else {
			v3 = 1044 * v0;
			argp = 1;
			*(_DWORD*)&byte_5D4594[v3 + 2517520] = *(_DWORD*)&addr.sa_data[2];
			if (ioctlsocket(v2, -2147195266, &argp) == -1)
				sub_578F20(-5);
			++*(_WORD*)&byte_5D4594[2523738];
			*(_DWORD*)&byte_5D4594[v3 + 2516484] = v2;
			v7 = inet_ntoa(*(struct in_addr*)&byte_5D4594[v3 + 2517520]);
			v6 = loadString_sub_40F1D0((char*)&byte_587000[311532], 0,
						   "C:\\NoxPost\\src\\common\\Telnet\\telnetd.c", 142);
			v4 = loadString_sub_40F1D0((char*)&byte_587000[311592], 0,
						   "C:\\NoxPost\\src\\common\\Telnet\\telnetd.c", 142);
			sub_413D30((char*)&byte_587000[311600], v4, v6, v7);
			v5 = loadString_sub_40F1D0((char*)&byte_587000[311652], 0,
						   "C:\\NoxPost\\src\\common\\Telnet\\telnetd.c", 146);
			nox_sprintf(buf, "%S", v5);
			send(*(_DWORD*)&byte_5D4594[v3 + 2516484], buf, strlen(buf), 0);
			result = *(_DWORD*)&byte_5D4594[v3 + 2517524];
			LOBYTE(result) = result | 1;
			*(_DWORD*)&byte_5D4594[v3 + 2517524] = result;
		}
	}
	return result;
}

//----- (00579190) --------------------------------------------------------
char* sub_579190() {
	unsigned __int8* v0; // esi
	char* result;        // eax
	SOCKET* v2;          // ebp
	wchar_t* v3;         // edi
	wchar_t* v4;         // eax
	wchar_t* v5;         // eax
	wchar_t* v6;         // [esp-8h] [ebp-11Ch]
	wchar_t* v7;         // [esp-8h] [ebp-11Ch]
	char* v8;            // [esp-4h] [ebp-118h]
	char* v9;            // [esp-4h] [ebp-118h]
	int v10;             // [esp+10h] [ebp-104h]
	wchar_t v11[128];    // [esp+14h] [ebp-100h]

	v10 = 0;
	v0 = &byte_5D4594[2517524];
	do {
		result = (char*)*((_DWORD*)v0 - 260);
		v2 = (SOCKET*)(v0 - 1040);
		if (result != (char*)-1) {
			result = sub_5793B0((u_long)(v0 - 1040), v10);
			if (result) {
				if (*result) {
					if (strlen(result) >= 0x7F)
						result[127] = 0;
					nox_swprintf(v11, L"%S", result);
					if (*v0 & 1) {
						v3 = sub_40A630();
						*(_DWORD*)v0 &= 0xFFFFFFFE;
						if (nox_wcscmp(v3, (const wchar_t*)&byte_5D4594[2523748]) &&
						    _nox_wcsicmp(v11, v3)) {
							v8 = inet_ntoa(*(struct in_addr*)(v0 - 4));
							v6 = loadString_sub_40F1D0(
							    (char*)&byte_587000[311716], 0,
							    "C:\\NoxPost\\src\\common\\Telnet\\telnetd.c", 371);
							v4 = loadString_sub_40F1D0(
							    (char*)&byte_587000[311768], 0,
							    "C:\\NoxPost\\src\\common\\Telnet\\telnetd.c", 371);
							sub_413D30((char*)&byte_587000[311776], v4, v6, v8);
							result = (char*)sub_579350(v10);
							goto LABEL_14;
						}
						send(*v2, "\r\n", 2, 0);
						v9 = inet_ntoa(*(struct in_addr*)(v0 - 4));
						v7 = loadString_sub_40F1D0(
						    (char*)&byte_587000[311832], 0,
						    "C:\\NoxPost\\src\\common\\Telnet\\telnetd.c", 381);
						v5 = loadString_sub_40F1D0(
						    (char*)&byte_587000[311888], 0,
						    "C:\\NoxPost\\src\\common\\Telnet\\telnetd.c", 381);
						sub_413D30((char*)&byte_587000[311896], v5, v7, v9);
					} else {
						nox_server_parseCmdText_443C80(v11, 0);
					}
				}
				result = (char*)send(*v2, *(const char**)&byte_587000[311484],
						     strlen(*(const char**)&byte_587000[311484]), 0);
			}
		}
	LABEL_14:
		v0 += 1044;
		++v10;
	} while ((int)v0 < (int)&byte_5D4594[2521700]);
	return result;
}

//----- (005793B0) --------------------------------------------------------
char* __cdecl sub_5793B0(u_long argp, int a2) {
	int v2;               // ebp
	int v3;               // eax
	signed int v4;        // ebx
	int v5;               // esi
	wchar_t* v6;          // eax
	signed int v8;        // ecx
	unsigned int v9;      // edx
	unsigned __int8 v10;  // al
	int v11;              // ecx
	unsigned __int8* v12; // edi
	unsigned int v13;     // eax
	unsigned int v14;     // ecx
	int v15;              // ecx
	int v16;              // esi
	int v17;              // edi
	int v18;              // esi
	wchar_t* v19;         // eax
	wchar_t* v20;         // [esp-8h] [ebp-18h]
	wchar_t* v21;         // [esp-8h] [ebp-18h]
	char* v22;            // [esp-4h] [ebp-14h]
	char* v23;            // [esp-4h] [ebp-14h]

	v2 = argp;
	if (ioctlsocket(*(_DWORD*)argp, 1074030207, &argp) == -1 || (int)(argp + *(__int16*)(v2 + 1032)) > 1024)
		return 0;
	v3 = recv(*(_DWORD*)v2, (char*)&byte_5D4594[2522712], 1024, 0);
	v4 = v3;
	if (v3 != -1) {
		if (!v3) {
			v5 = a2;
			sub_579350(a2);
			v22 = inet_ntoa(*(struct in_addr*)&byte_5D4594[1044 * v5 + 2517520]);
			v20 = loadString_sub_40F1D0((char*)&byte_587000[311948], 0,
						    "C:\\NoxPost\\src\\common\\Telnet\\telnetd.c", 211);
			v6 = loadString_sub_40F1D0((char*)&byte_587000[312012], 0,
						   "C:\\NoxPost\\src\\common\\Telnet\\telnetd.c", 211);
			sub_413D30((char*)&byte_587000[312020], v6, v20, v22);
			return 0;
		}
		if (*(_BYTE*)(v2 + 1040) & 1) {
			v8 = 0;
			v9 = v3;
			if (v3 > 0) {
				do {
					v10 = byte_5D4594[v8 + 2522712];
					if (v10 == 10 || v10 == 13)
						--v9;
					++v8;
				} while (v8 < v4);
			}
			memset(&byte_5D4594[2521684], 0x2Au, v9);
			byte_5D4594[v9 + 2521684] = 0;
			send(*(_DWORD*)v2, (const char*)&byte_5D4594[2521684], v9, 0);
		} else {
			send(*(_DWORD*)v2, (const char*)&byte_5D4594[2522712], v3, 0);
		}
		v11 = *(__int16*)(v2 + 1030);
		v12 = (unsigned __int8*)(v11 + v2 + 4);
		if (v11 + v4 < 1024) {
			qmemcpy(v12, &byte_5D4594[2522712], v4);
			*(_WORD*)(v2 + 1030) += v4;
		} else {
			v14 = 1024 - v11;
			v13 = v14;
			qmemcpy(v12, &byte_5D4594[2522712], v14);
			*(_WORD*)(v2 + 1030) = 0;
			v15 = v4 - v14;
			if (v15 > 0)
				qmemcpy((void*)(v2 + 4), &byte_5D4594[v13 + 2522712],
					4 * ((unsigned int)v15 >> 2) + (((_BYTE)v4 - (_BYTE)v13) & 3));
			*(_WORD*)(v2 + 1030) = v4 - v13;
		}
		*(_WORD*)(v2 + 1032) += v4;
	LABEL_21:
		if (sub_579700(v2)) {
			v16 = *(__int16*)(v2 + 1028);
			v17 = 0;
			while (1) {
				if (v16 == 1024)
					v16 = 0;
				switch (*(unsigned __int8*)(v16 + v2 + 4)) {
				case 8u:
				case 0x7Fu:
					if (v17 <= 0)
						goto LABEL_31;
					--v17;
					++v16;
					continue;
				case 0xAu:
					byte_5D4594[v17 + 2521684] = 0;
					*(_WORD*)(v2 + 1032) += -1 - v17;
					*(_WORD*)(v2 + 1028) = v16 + 1;
					return (char*)&byte_5D4594[2521684];
				case 0xDu:
					goto LABEL_31;
				default:
					byte_5D4594[v17++ + 2521684] = *(_BYTE*)(v16 + v2 + 4);
				LABEL_31:
					++v16;
					break;
				}
			}
		}
		return 0;
	}
	if (WSAGetLastError() == 10035)
		goto LABEL_21;
	v18 = a2;
	sub_579350(a2);
	v23 = inet_ntoa(*(struct in_addr*)&byte_5D4594[1044 * v18 + 2517520]);
	v21 = loadString_sub_40F1D0((char*)&byte_587000[312072], 0, "C:\\NoxPost\\src\\common\\Telnet\\telnetd.c", 273);
	v19 = loadString_sub_40F1D0((char*)&byte_587000[312136], 0, "C:\\NoxPost\\src\\common\\Telnet\\telnetd.c", 273);
	sub_413D30((char*)&byte_587000[312144], v19, v21, v23);
	return 0;
}
