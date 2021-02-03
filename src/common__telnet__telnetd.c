#include "common__telnet__telnetd.h"

#include "client__system__parsecmd.h"
#include "proto.h"
SOCKET nox_telnet_sock = -1;

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
	char buf[128];        // [esp+20h] [ebp-80h]

	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = 0;
	addr.sin_addr.s_addr = 0;
	memset(addr.sin_zero, 0, 8);

	v0 = 0;
	result = (int)getMemAt(0x5D4594, 2516484);
	while (*(int*)result != -1) {
		result += 1044;
		++v0;
		if (result >= (int)getMemAt(0x5D4594, 2520660))
			return result;
	}
	if (v0 != -1) {
		addrlen = 16;
		v2 = accept(nox_telnet_sock, &addr, &addrlen);
		if (v2 == -1) {
			result = WSAGetLastError();
			if (result != 10035)
				result = sub_578F20(-4);
		} else {
			v3 = 1044 * v0;
			argp = 1;
			*getMemU32Ptr(0x5D4594, 2516484 + 1036 + v3) = addr.sin_addr.s_addr;
			if (ioctlsocket(v2, -2147195266, &argp) == -1)
				sub_578F20(-5);
			++*getMemU16Ptr(0x5D4594, 2523738);
			*getMemU32Ptr(0x5D4594, 2516484 + v3) = v2;
			v7 = inet_ntoa(*(struct in_addr*)getMemAt(0x5D4594, 2516484 + 1036 + v3));
			v6 = nox_strman_loadString_40F1D0("ConnectionStarted", 0, "C:\\NoxPost\\src\\common\\Telnet\\telnetd.c",
									   142);
			v4 = nox_strman_loadString_40F1D0("Telnet", 0, "C:\\NoxPost\\src\\common\\Telnet\\telnetd.c",
									   142);
			nox_xxx_networkLog_413D30((char*)getMemAt(0x587000, 311600), v4, v6, v7);
			v5 = nox_strman_loadString_40F1D0("Password", 0, "C:\\NoxPost\\src\\common\\Telnet\\telnetd.c",
									   146);
			nox_sprintf(buf, "%S", v5);
			send(*getMemU32Ptr(0x5D4594, 2516484 + v3), buf, strlen(buf), 0);
			result = *getMemU32Ptr(0x5D4594, 2516484 + 1040 + v3);
			LOBYTE(result) = result | 1;
			*getMemU32Ptr(0x5D4594, 2516484 + 1040 + v3) = result;
		}
	}
	return result;
}

//----- (00578F30) --------------------------------------------------------
void sub_578F30() {
	unsigned __int8* v1; // esi
	if (nox_telnet_sock != -1) {
		shutdown(nox_telnet_sock, 2);
		closesocket(nox_telnet_sock);
	}
	nox_telnet_sock = -1;
	*getMemU16Ptr(0x5D4594, 2523738) = 0;
	v1 = getMemAt(0x5D4594, 2516484);
	do {
		if (*(int*)v1 != -1) {
			shutdown(nox_telnet_sock, 2);
			closesocket(*(_DWORD*)v1);
		}
		*(_DWORD*)v1 = -1;
		v1[4] = 0;
		*((_WORD*)v1 + 514) = 0;
		*((_WORD*)v1 + 515) = 0;
		*((_WORD*)v1 + 516) = 0;
		*((_DWORD*)v1 + 260) = 0;
		v1 += 1044;
	} while ((int)v1 < (int)getMemAt(0x5D4594, 2520660));
}

//----- (00578E10) --------------------------------------------------------
int nox_xxx_telnet_578E10() {
	unsigned __int8* v1;  // eax
	u_long argp;          // [esp+4h] [ebp-14h]
	struct sockaddr_in name; // [esp+8h] [ebp-10h]

	argp = 1;
	name.sin_family = AF_INET;
	name.sin_port = htons(getMemU16Ptr(0x5D4594, 2523736));
	name.sin_addr.s_addr = 0;
	memset(name.sin_zero, 0, 8);
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
	nox_telnet_sock = sock;
	if (sock == -1) {
		return -1;
	}
	if (bind(sock, &name, 16) == -1) {
		return -2;
	} else if (ioctlsocket(nox_telnet_sock, -2147195266, &argp) == -1) {
		sub_578F20(-5);
		return -5;
	}
	if (listen(nox_telnet_sock, 1) == -1) {
		WSAGetLastError();
		sub_578F20(-3);
	}
	*getMemU16Ptr(0x5D4594, 2523738) = 0;
	v1 = getMemAt(0x5D4594, 2516484 + 4);
	do {
		*((_DWORD*)v1 - 1) = -1;
		*v1 = 0;
		*((_WORD*)v1 + 512) = 0;
		*((_WORD*)v1 + 513) = 0;
		*((_WORD*)v1 + 514) = 0;
		*((_DWORD*)v1 + 259) = 0;
		v1 += 1044;
	} while ((int)v1 < (int)getMemAt(0x5D4594, 2520664));
	return 0;
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
	v0 = getMemAt(0x5D4594, 2516484 + 1040);
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
						v3 = nox_xxx_sysopGetPass_40A630();
						*(_DWORD*)v0 &= 0xFFFFFFFE;
						if (nox_wcscmp(v3, (const wchar_t*)getMemAt(0x5D4594, 2523748)) && _nox_wcsicmp(v11, v3)) {
							v8 = inet_ntoa(*(struct in_addr*)(v0 - 4));
							v6 = nox_strman_loadString_40F1D0("BadPassword", 0,
													   "C:\\NoxPost\\src\\common\\Telnet\\telnetd.c", 371);
							v4 = nox_strman_loadString_40F1D0("Telnet", 0,
													   "C:\\NoxPost\\src\\common\\Telnet\\telnetd.c", 371);
							nox_xxx_networkLog_413D30((char*)getMemAt(0x587000, 311776), v4, v6, v8);
							result = (char*)sub_579350(v10);
							goto LABEL_14;
						}
						send(*v2, "\r\n", 2, 0);
						v9 = inet_ntoa(*(struct in_addr*)(v0 - 4));
						v7 = nox_strman_loadString_40F1D0("LoginSuccessful", 0,
												   "C:\\NoxPost\\src\\common\\Telnet\\telnetd.c", 381);
						v5 = nox_strman_loadString_40F1D0("Telnet", 0,
												   "C:\\NoxPost\\src\\common\\Telnet\\telnetd.c", 381);
						nox_xxx_networkLog_413D30((char*)getMemAt(0x587000, 311896), v5, v7, v9);
					} else {
						nox_server_parseCmdText_443C80(v11, 0);
					}
				}
				result = (char*)send(*v2, *(const char**)getMemAt(0x587000, 311484),
									 strlen(*(const char**)getMemAt(0x587000, 311484)), 0);
			}
		}
	LABEL_14:
		v0 += 1044;
		++v10;
	} while ((int)v0 < (int)getMemAt(0x5D4594, 2521700));
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
	v3 = recv(*(_DWORD*)v2, (char*)getMemAt(0x5D4594, 2522712), 1024, 0);
	v4 = v3;
	if (v3 != -1) {
		if (!v3) {
			v5 = a2;
			sub_579350(a2);
			v22 = inet_ntoa(*(struct in_addr*)getMemAt(0x5D4594, 2516484 + 1044*v5 + 1036));
			v20 = nox_strman_loadString_40F1D0("ConnectionTerminated", 0, "C:\\NoxPost\\src\\common\\Telnet\\telnetd.c",
										211);
			v6 = nox_strman_loadString_40F1D0("Telnet", 0, "C:\\NoxPost\\src\\common\\Telnet\\telnetd.c",
									   211);
			nox_xxx_networkLog_413D30((char*)getMemAt(0x587000, 312020), v6, v20, v22);
			return 0;
		}
		if (*(_BYTE*)(v2 + 1040) & 1) {
			v8 = 0;
			v9 = v3;
			if (v3 > 0) {
				do {
					v10 = getMemByte(0x5D4594, v8 + 2522712);
					if (v10 == 10 || v10 == 13)
						--v9;
					++v8;
				} while (v8 < v4);
			}
			memset(getMemAt(0x5D4594, 2521684), 0x2Au, v9);
			*getMemU8Ptr( 0x5D4594, v9 + 2521684) = 0;
			send(*(_DWORD*)v2, (const char*)getMemAt(0x5D4594, 2521684), v9, 0);
		} else {
			send(*(_DWORD*)v2, (const char*)getMemAt(0x5D4594, 2522712), v3, 0);
		}
		v11 = *(__int16*)(v2 + 1030);
		v12 = (unsigned __int8*)(v11 + v2 + 4);
		if (v11 + v4 < 1024) {
			memcpy(v12, getMemAt(0x5D4594, 2522712), v4);
			*(_WORD*)(v2 + 1030) += v4;
		} else {
			v14 = 1024 - v11;
			v13 = v14;
			memcpy(v12, getMemAt(0x5D4594, 2522712), v14);
			*(_WORD*)(v2 + 1030) = 0;
			v15 = v4 - v14;
			if (v15 > 0)
				memcpy((void*)(v2 + 4), getMemAt(0x5D4594, v13 + 2522712),
						4 * ((unsigned int)v15 >> 2) + (((_BYTE)v4 - (_BYTE)v13) & 3));
			*(_WORD*)(v2 + 1030) = v4 - v13;
		}
		*(_WORD*)(v2 + 1032) += v4;
	} else if (WSAGetLastError() != 10035) {
		v18 = a2;
		sub_579350(a2);
		v23 = inet_ntoa(*(struct in_addr*)getMemAt(0x5D4594, 2516484 + 1044*v18 + 1036));
		v21 = nox_strman_loadString_40F1D0("ConnectionTerminated", 0, "C:\\NoxPost\\src\\common\\Telnet\\telnetd.c", 273);
		v19 = nox_strman_loadString_40F1D0("Telnet", 0, "C:\\NoxPost\\src\\common\\Telnet\\telnetd.c", 273);
		nox_xxx_networkLog_413D30((char*)getMemAt(0x587000, 312144), v19, v21, v23);
		return 0;
	}
	if (!sub_579700(v2)) {
		return 0;
	}
	v16 = *(__int16*)(v2 + 1028);
	v17 = 0;
	while (1) {
		if (v16 == 1024)
			v16 = 0;
		switch (*(unsigned __int8*)(v16 + v2 + 4)) {
			case 8u:
			case 0x7Fu:
				if (v17 <= 0) {
					++v16;
					break;
				}
				--v17;
				++v16;
				continue;
			case 0xAu:
				*getMemU8Ptr( 0x5D4594, v17 + 2521684) = 0;
				*(_WORD*)(v2 + 1032) += -1 - v17;
				*(_WORD*)(v2 + 1028) = v16 + 1;
				return (char*)getMemAt(0x5D4594, 2521684);
			case 0xDu:
				++v16;
				break;
			default:
				*getMemU8Ptr( 0x5D4594, v17++ + 2521684) = *(_BYTE*)(v16 + v2 + 4);
				++v16;
				break;
		}
	}
}
