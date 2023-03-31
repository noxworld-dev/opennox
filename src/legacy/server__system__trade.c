#include "server__dbase__objdb.h"

#include "GAME1.h"
#include "GAME1_1.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4.h"
#include "GAME4_1.h"
#include "GAME4_3.h"
#include "common__strman.h"
#include "operators.h"

extern uint32_t dword_5d4594_2386552;
extern uint32_t dword_5d4594_2386548;
extern uint32_t dword_5d4594_2386560;
extern void* nox_alloc_tradeItems_2386496;

//----- (0050E7A0) --------------------------------------------------------
int sub_50E7A0(uint32_t* a1, int a2) {
	int* v2; // esi
	int v4;  // eax
	int v5;  // eax
	int v6;  // eax

	v2 = (int*)a1[5];
	if (!v2) {
		return 0;
	}
	while (*v2 != a2) {
		v2 = (int*)v2[2];
		if (!v2) {
			return 0;
		}
	}
	v4 = v2[2];
	if (v4) {
		*(uint32_t*)(v4 + 12) = v2[3];
	}
	v5 = v2[3];
	if (v5) {
		*(uint32_t*)(v5 + 8) = v2[2];
	}
	if (v2 == (int*)a1[5]) {
		a1[5] = v2[2];
	}
	v6 = a1[2];
	if (!(*(uint8_t*)(v6 + 8) & 4)) {
		v6 = a1[3];
	}
	sub_50E820(v6, *v2);
	nox_alloc_class_free_obj_first(*(unsigned int**)&nox_alloc_tradeItems_2386496, v2);
	return 1;
}

//----- (0050E8F0) --------------------------------------------------------
uint32_t* nox_xxx_createPlayerShopSession_50E8F0(int a1, int a2) {
	int v2;           // ebx
	int v3;           // eax
	uint32_t* v4;     // esi
	uint32_t* result; // eax

	v2 = 0;
	if (nox_common_gameFlags_check_40A5C0(4096) &&
		(v3 = *(unsigned char*)(*(uint32_t*)(*(uint32_t*)(a1 + 748) + 276) + 2064),
		 v4 = *(uint32_t**)getMemAt(0x5D4594, 2386364 + 4 * v3), *getMemU32Ptr(0x5D4594, 2386364 + 4 * v3) = 0, v4)) {
		v2 = 1;
	} else {
		result = nox_xxx_createShopStruct_50E870();
		v4 = result;
		if (!result) {
			return result;
		}
	}
	v4[2] = a1;
	v4[3] = a2;
	v4[4] = 1;
	if (!v2) {
		nox_xxx_loadShopItems_50E970((int)v4);
	}
	return v4;
}

//----- (0050F0F0) --------------------------------------------------------
int sub_50F0F0(int a1, int a2) {
	int v2;      // ebx
	int v3;      // ebp
	wchar2_t* v4; // eax
	char v6[86]; // [esp+10h] [ebp-58h]

	*(uint16_t*)v6 = 3529;
	v2 = *(uint32_t*)(a2 + 8);
	if (*(uint8_t*)(v2 + 8) & 4) {
		v3 = *(uint32_t*)(a2 + 8);
		v2 = *(uint32_t*)(a2 + 12);
	} else {
		v3 = *(uint32_t*)(a2 + 12);
	}
	v4 = sub_4E39F0_obj_db((const char**)v2);
	nox_wcsncpy((wchar2_t*)&v6[4], v4, 0x18u);
	*(uint16_t*)&v6[52] = 0;
	strcpy(&v6[54], (const char*)(*(uint32_t*)(v2 + 692) + 1684));
	*(uint16_t*)&v6[2] = *(uint16_t*)(v2 + 4);
	return nox_xxx_netSendPacket1_4E5390(*(unsigned char*)(*(uint32_t*)(*(uint32_t*)(v3 + 748) + 276) + 2064), (int)v6,
										 86, 0, 1);
}

//----- (0050F1A0) --------------------------------------------------------
int sub_50F1A0(int a1, int a2) {
	int v2;      // eax
	int v3;      // esi
	int v4;      // edx
	wchar2_t* v6; // [esp-8h] [ebp-40h]
	char v8[52]; // [esp+4h] [ebp-34h]

	*(uint16_t*)v8 = 3273;
	v2 = *(uint32_t*)(a2 + 8);
	v3 = *(uint32_t*)(a1 + 748);
	if (a1 != v2) {
		if (*(uint8_t*)(v2 + 8) & 4) {
			nox_wcscpy((wchar2_t*)&v8[2], (const wchar2_t*)(*(uint32_t*)(*(uint32_t*)(v2 + 748) + 276) + 4704));
			return nox_xxx_netSendPacket1_4E5390(*(unsigned char*)(*(uint32_t*)(v3 + 276) + 2064), (int)v8, 52, 0, 1);
		}
		v6 = sub_4E39F0_obj_db(*(const char***)(a2 + 12));
	} else {
		v4 = *(uint32_t*)(a2 + 12);
		if (*(uint8_t*)(v4 + 8) & 4) {
			nox_wcscpy((wchar2_t*)&v8[2], (const wchar2_t*)(*(uint32_t*)(*(uint32_t*)(v4 + 748) + 276) + 4704));
			return nox_xxx_netSendPacket1_4E5390(*(unsigned char*)(*(uint32_t*)(v3 + 276) + 2064), (int)v8, 52, 0, 1);
		}
		v6 = sub_4E39F0_obj_db((const char**)v4);
	}
	nox_wcsncpy((wchar2_t*)&v8[2], v6, 0x18u);
	*(uint16_t*)&v8[50] = 0;
	return nox_xxx_netSendPacket1_4E5390(*(unsigned char*)(*(uint32_t*)(v3 + 276) + 2064), (int)v8, 52, 0, 1);
}

//----- (0050F280) --------------------------------------------------------
int nox_xxx_servSendShopItems_50F280(int a1, int a2) {
	int result;  // eax
	uint32_t* i; // esi

	result = a2;
	for (i = *(uint32_t**)(a2 + 20); i; i = (uint32_t*)i[2]) {
		result = sub_50F2B0(a1, i);
	}
	return result;
}

//----- (0050F370) --------------------------------------------------------
uint32_t* nox_xxx_tradeSetPlayer_50F370(uint32_t* a1, int a2) {
	uint32_t* result; // eax

	result = a1;
	*a1 = 1;
	if (*(uint8_t*)(a2 + 8) & 4) {
		*(uint32_t*)(*(uint32_t*)(a2 + 748) + 280) = a1;
	}
	return result;
}

//----- (0050FAE0) --------------------------------------------------------
int sub_50FAE0(int a1, int a2, int a3, int a4, int a5) {
	int v5;       // esi
	short v6;     // dx
	int v7;       // ecx
	int v8;       // edx
	int i;        // eax
	char v11[15]; // [esp+4h] [ebp-10h]

	v5 = *(uint32_t*)(a1 + 748);
	v11[0] = -55;
	v11[2] = a1 == a2;
	v11[1] = 4;
	v6 = *(uint16_t*)(a4 + 36);
	*(uint16_t*)&v11[3] = *(uint16_t*)(a4 + 4);
	*(uint32_t*)&v11[7] = a5;
	v7 = *(uint32_t*)(a4 + 8);
	*(uint16_t*)&v11[5] = v6;
	if (v7 & 0x13001000) {
		v8 = *(uint32_t*)(a4 + 692);
		for (i = 0; i < 4; ++i) {
			if (*(uint32_t*)v8) {
				v11[i + 11] = *(uint8_t*)(*(uint32_t*)v8 + 4);
			} else {
				v11[i + 11] = -1;
			}
			v8 += 4;
		}
	} else {
		*(uint32_t*)&v11[11] = -1;
	}
	return nox_xxx_netSendPacket1_4E5390(*(unsigned char*)(*(uint32_t*)(v5 + 276) + 2064), (int)v11, 15, 0, 1);
}

//----- (0050FD60) --------------------------------------------------------
int sub_50FD60(uint32_t* a1, int a2) {
	uint32_t* v2;    // esi
	unsigned int v3; // edi
	unsigned int v4; // ecx
	int v5;          // eax
	int* v6;         // edx
	int v7;          // ecx
	int v8;          // eax
	int v9;          // edx
	int* i;          // ecx
	int v12[4];      // [esp+8h] [ebp-20h]
	int v13[4];      // [esp+18h] [ebp-10h]

	v13[0] = 0;
	v12[0] = 0;
	v2 = a1;
	v13[1] = 0;
	v12[1] = 0;
	v3 = 0;
	v13[2] = 0;
	v12[2] = 0;
	v13[3] = 0;
	for (v12[3] = 0; v2; v2 = (uint32_t*)v2[2]) {
		v4 = 0;
		v5 = *(unsigned short*)(*v2 + 4);
		v6 = v13;
		while (*v6 != v5) {
			++v4;
			++v6;
			if (v4 >= 4) {
				v7 = v12[v3];
				v13[v3] = v5;
				v12[v3++] = v7 + 1;
				goto LABEL_6;
			}
		}
		++v12[v4];
	LABEL_6:;
	}
	v8 = 0;
	if (!v3) {
		return 1;
	}
	HIWORD(v9) = 0;
	for (i = v13;; ++i) {
		LOWORD(v9) = *(uint16_t*)(a2 + 4);
		if (*i == v9 && !(*(uint32_t*)(a2 + 8) & 0x13001000)) {
			break;
		}
		if (++v8 >= v3) {
			return v3 < 4;
		}
	}
	return 1;
}

//----- (00510320) --------------------------------------------------------
void sub_510320(int a1, int a2) {
	int v2;      // ecx
	uint8_t* v3; // ebp
	int v4;      // eax
	int v5;      // esi
	char v6;     // cl
	int v7;      // edx
	int v8;      // eax

	if (a1 && a2) {
		v2 = *(uint32_t*)(a2 + 8);
		if (*(uint8_t*)(v2 + 8) & 4) {
			v2 = *(uint32_t*)(a2 + 12);
		}
		v3 = *(uint8_t**)(v2 + 692);
		v4 = nox_xxx_getSomeShopData_5103A0(a2, a1);
		if (v4 != -1) {
			v5 = (int)&v3[28 * v4];
			v6 = v3[28 * v4 + 8] - 1;
			*(uint8_t*)(v5 + 8) = v6;
			if (!v6) {
				v7 = v4;
				if (v4 < (unsigned char)*v3 - 1) {
					v8 = v5 + 4;
					do {
						++v7;
						memcpy((void*)v8, (const void*)(v8 + 28), 0x1Cu);
						v8 += 28;
					} while (v7 < (unsigned char)*v3 - 1);
				}
				--*v3;
			}
		}
	}
}

//----- (005104F0) --------------------------------------------------------
int sub_5104F0(int a1, short a2) {
	int v2;     // eax
	char v4[4]; // [esp+0h] [ebp-4h]

	*(uint16_t*)&v4[2] = a2;
	v2 = *(uint32_t*)(a1 + 748);
	v4[0] = -55;
	v4[1] = 27;
	return nox_xxx_netSendPacket0_4E5420(*(unsigned char*)(*(uint32_t*)(v2 + 276) + 2064), v4, 4, 0, 1);
}

//----- (00510540) --------------------------------------------------------
int sub_510540(int a1) {
	if (!nox_common_gameFlags_check_40A5C0(4096)) {
		return 1;
	}
	if (!*getMemU32Ptr(0x5D4594, 2386520)) {
		*getMemU32Ptr(0x5D4594, 2386520) = nox_xxx_getNameId_4E3AA0("Diamond");
		*getMemU32Ptr(0x5D4594, 2386528) = nox_xxx_getNameId_4E3AA0("Emerald");
		*getMemU32Ptr(0x5D4594, 2386524) = nox_xxx_getNameId_4E3AA0("Ruby");
		*getMemU32Ptr(0x5D4594, 2386532) = nox_xxx_getNameId_4E3AA0("AnkhTradable");
	}
	int v1 = *(unsigned short*)(a1 + 4);
	if ((unsigned short)v1 == *getMemU32Ptr(0x5D4594, 2386520) || v1 == *getMemU32Ptr(0x5D4594, 2386524) ||
		v1 == *getMemU32Ptr(0x5D4594, 2386528) || v1 == *getMemU32Ptr(0x5D4594, 2386532)) {
		return 0;
	}
	return 1;
}

//----- (005105D0) --------------------------------------------------------
int sub_5105D0(int a1) {
	int v1; // eax

	if (!*getMemU32Ptr(0x5D4594, 2386536)) {
		*getMemU32Ptr(0x5D4594, 2386536) = nox_xxx_getNameId_4E3AA0("Diamond");
		*getMemU32Ptr(0x5D4594, 2386544) = nox_xxx_getNameId_4E3AA0("Emerald");
		*getMemU32Ptr(0x5D4594, 2386540) = nox_xxx_getNameId_4E3AA0("Ruby");
	}
	v1 = *(unsigned short*)(a1 + 4);
	return (unsigned short)v1 == *getMemU32Ptr(0x5D4594, 2386536) || v1 == *getMemU32Ptr(0x5D4594, 2386540) ||
		   v1 == *getMemU32Ptr(0x5D4594, 2386544);
}

//----- (0050EF10) --------------------------------------------------------
uint32_t* nox_xxx_servShopStart_50EF10_trade(int a1, int a2) {
	int v2;           // edx
	int v3;           // eax
	wchar2_t* v4;      // eax
	int v6;           // ecx
	int v7;           // eax
	wchar2_t* v8;      // eax
	uint32_t* v9;     // esi
	char v10;         // al
	int v11;          // eax
	int v12;          // eax
	int v13;          // [esp-4h] [ebp-114h]
	wchar2_t v14[128]; // [esp+10h] [ebp-100h]

	v2 = *(uint32_t*)(a1 + 8) & 4;
	if (v2) {
		v3 = *(uint32_t*)(*(uint32_t*)(a1 + 748) + 280);
		if (v3) {
			if (*(uint32_t*)(v3 + 12) != a2) {
				v4 = nox_strman_loadString_40F1D0("StarterAlreadyTrading", 0,
												  "C:\\NoxPost\\src\\Server\\System\\Trade.c", 1836);
				nox_xxx_netSendLineMessage_4D9EB0(a1, v4);
			}
			return 0;
		}
	}
	v6 = *(uint32_t*)(a2 + 8) & 4;
	if (v6) {
		v7 = *(uint32_t*)(a2 + 748);
		if (*(uint32_t*)(v7 + 280)) {
			if (v2) {
				v13 = *(uint32_t*)(v7 + 276) + 4704;
				v8 = nox_strman_loadString_40F1D0("OtherAlreadyTrading", 0, "C:\\NoxPost\\src\\Server\\System\\Trade.c",
												  1878);
				nox_swprintf(v14, v8, v13);
				nox_xxx_netSendLineMessage_4D9EB0(a1, v14);
			}
			return 0;
		}
	}
	if (v2) {
		if (!v6) {
			v9 = nox_xxx_createPlayerShopSession_50E8F0(a1, a2);
			goto LABEL_18;
		}
	} else if (!v6) {
		goto LABEL_17;
	}
	if (!v2) {
		v9 = nox_xxx_createPlayerShopSession_50E8F0(a2, a1);
		goto LABEL_18;
	}
LABEL_17:
	v9 = nox_xxx_createShopStruct_50E870();
	v9[2] = a1;
	v9[3] = a2;
LABEL_18:
	if (!v9) {
		return 0;
	}
	v9[1] = gameFrame();
	nox_xxx_tradeSetPlayer_50F370(v9, a1);
	nox_xxx_tradeSetPlayer_50F370(v9, a2);
	v10 = *(uint8_t*)(a1 + 8);
	if (v9[4]) {
		if (v10 & 4) {
			sub_50F0F0(a1, (int)v9);
		}
		if (*(uint8_t*)(a2 + 8) & 4) {
			sub_50F0F0(a2, (int)v9);
		}
	} else {
		if (v10 & 4) {
			sub_50F1A0(a1, (int)v9);
		}
		if (*(uint8_t*)(a2 + 8) & 4) {
			sub_50F1A0(a2, (int)v9);
		}
	}
	if (v9[4]) {
		v11 = v9[2];
		if (*(uint8_t*)(v11 + 8) & 4) {
			nox_xxx_servSendShopItems_50F280(v11, (int)v9);
		} else {
			nox_xxx_servSendShopItems_50F280(v9[3], (int)v9);
		}
		if (v9[4] && nox_common_gameFlags_check_40A5C0(2048)) {
			v12 = v9[2];
			if (!(*(uint8_t*)(v12 + 8) & 4)) {
				v12 = v9[3];
			}
			nox_xxx_unitFreeze_4E79C0(v12, 0);
		}
	}
	return v9;
}

//----- (0050F820) --------------------------------------------------------
int nox_xxx_tradeP2PAddOffer2_50F820_trade(int a1, int a2, float a3) {
	float v3;    // ebx
	int result;  // eax
	int* v5;     // eax
	int* v6;     // edi
	wchar2_t* v7; // eax
	wchar2_t* v8; // eax
	int v9;      // eax
	int v10;     // eax
	int v11;     // eax
	int v12;     // eax

	if (!*getMemU32Ptr(0x5D4594, 2386516)) {
		*getMemU32Ptr(0x5D4594, 2386516) = nox_xxx_getNameId_4E3AA0("Gold");
	}
	if (*(uint32_t*)(a1 + 8) == a2) {
		v3 = a3;
		if (!sub_50FD60(*(uint32_t**)(a1 + 32), SLODWORD(a3))) {
			return 0;
		}
	} else {
		if (*(uint32_t*)(a1 + 12) != a2) {
			return 0;
		}
		v3 = a3;
		if (!sub_50FD60(*(uint32_t**)(a1 + 36), SLODWORD(a3))) {
			return 0;
		}
	}
	v5 = (int*)nox_alloc_class_new_obj_zero(*(uint32_t**)&nox_alloc_tradeItems_2386496);
	v6 = v5;
	if (v5) {
		*(float*)v5 = v3;
		v5[2] = 0;
		v5[3] = 0;
		v5[1] = nox_xxx_shopGetItemCost_50E3D0(1, a1, v3);
		if (*(uint32_t*)(a1 + 8) == a2) {
			v6[2] = *(uint32_t*)(a1 + 32);
			v9 = *(uint32_t*)(a1 + 32);
			if (v9) {
				*(uint32_t*)(v9 + 12) = v6;
			}
			*(uint32_t*)(a1 + 32) = v6;
		} else {
			v6[2] = *(uint32_t*)(a1 + 36);
			v10 = *(uint32_t*)(a1 + 36);
			if (v10) {
				*(uint32_t*)(v10 + 12) = v6;
			}
			*(uint32_t*)(a1 + 36) = v6;
		}
		sub_50FB90((uint32_t*)a1);
		v11 = *(uint32_t*)(a1 + 8);
		*(uint32_t*)(a1 + 24) = 0;
		*(uint32_t*)(a1 + 28) = 0;
		if (*(uint8_t*)(v11 + 8) & 4) {
			if (!(*(uint8_t*)(*(uint32_t*)(a1 + 12) + 8) & 4) && *(uint32_t*)(a1 + 44) <= *(int*)(a1 + 40)) {
				*(uint32_t*)(a1 + 28) = 1;
			}
		} else if (*(uint32_t*)(a1 + 40) <= *(int*)(a1 + 44)) {
			*(uint32_t*)(a1 + 24) = 1;
		}
		if (*(uint8_t*)(v11 + 8) & 4) {
			nox_xxx_tradeP2PUpdStuff_50FA00(v11, (uint32_t*)a1);
			sub_50FAE0(*(uint32_t*)(a1 + 8), a2, a1, *v6, v6[1]);
			sub_50F720(*(uint32_t*)(a1 + 8), (uint32_t*)a1);
		}
		v12 = *(uint32_t*)(a1 + 12);
		if (*(uint8_t*)(v12 + 8) & 4) {
			nox_xxx_tradeP2PUpdStuff_50FA00(v12, (uint32_t*)a1);
			sub_50FAE0(*(uint32_t*)(a1 + 12), a2, a1, *v6, v6[1]);
			sub_50F720(*(uint32_t*)(a1 + 12), (uint32_t*)a1);
		}
		result = 1;
	} else {
		if (*(uint8_t*)(*(uint32_t*)(a1 + 8) + 8) & 4) {
			v7 = nox_strman_loadString_40F1D0("TradeMaxObjectsReached", 0, "C:\\NoxPost\\src\\Server\\System\\Trade.c",
											  2487);
			nox_xxx_netSendLineMessage_4D9EB0(*(uint32_t*)(a1 + 8), v7);
		}
		if (!(*(uint8_t*)(*(uint32_t*)(a1 + 12) + 8) & 4)) {
			return 0;
		}
		v8 = nox_strman_loadString_40F1D0("TradeMaxObjectsReached", 0, "C:\\NoxPost\\src\\Server\\System\\Trade.c",
										  2490);
		nox_xxx_netSendLineMessage_4D9EB0(*(uint32_t*)(a1 + 12), v8);
		result = 0;
	}
	return result;
}

//----- (005100C0) --------------------------------------------------------
void sub_5100C0_trade(int a1, uint32_t* a2, int a3) {
	int v3;                                // edi
	unsigned int v4;                       // ebx
	float* result;                         // eax
	int v6;                                // esi
	unsigned int v7;                       // eax
	unsigned int v8;                       // ebp
	int v9;                                // ebx
	wchar2_t* v10;                          // eax
	int v11;                               // eax
	int v12;                               // ebx
	uint32_t* v13;                         // eax
	void (*v14)(int, uint32_t*, int, int); // ecx
	int v15;                               // [esp+0h] [ebp-14h]
	float v16;                             // [esp+0h] [ebp-14h]
	float v17;                             // [esp+0h] [ebp-14h]
	int v18;                               // [esp+18h] [ebp+4h]

	v3 = a1;
	v15 = a1;
	v18 = *(uint32_t*)(a1 + 748);
	v4 = nox_xxx_playerGetGold_4FA6B0(v15);
	if (!dword_5d4594_2386548) {
		dword_5d4594_2386548 = nox_xxx_getNameId_4E3AA0("AnkhTradable");
	}
	result = (float*)a2[5];
	if (result) {
		while (!*(uint32_t*)result || *(uint32_t*)(*(uint32_t*)result + 36) != a3) {
			result = (float*)*((uint32_t*)result + 2);
			if (!result) {
				return;
			}
		}
		v6 = *(uint32_t*)result;
		if (*(uint32_t*)result) {
			v7 = nox_xxx_shopGetItemCost_50E3D0(1, (int)a2, *result);
			v8 = v7;
			if (v7 > v4) {
				sub_5104F0(v3, v7 - v4);
				return;
			}
			if (*(uint8_t*)(v6 + 8) & 0x10) {
				v9 = nox_xxx_inventoryCountObjects_4E7D30(v3, *(unsigned short*)(v6 + 4));
				if (v9 >= (nox_common_gameFlags_check_40A5C0(6144) ? 9 : 3)) {
					v10 = nox_strman_loadString_40F1D0("pickup.c:MaxSameItem", 0,
													   "C:\\NoxPost\\src\\Server\\System\\Trade.c", 2943);
					nox_xxx_netSendLineMessage_4D9EB0(v3, v10);
					return;
				}
			}
			if (*(unsigned short*)(v6 + 4) == dword_5d4594_2386548) {
				v16 = nox_xxx_gamedataGetFloat_419D40("MaxExtraLives");
				if (*(uint32_t*)(v18 + 320) >= nox_float2int(v16)) {
					nox_xxx_netPriMsgToPlayer_4DA2C0(v3, "pickup.c:MaxTradableAnkhsReached", 0);
					nox_xxx_aud_501960(925, v3, 0, 0);
					return;
				}
			}
			if (nox_common_gameFlags_check_40A5C0(4096)) {
				v11 = *(uint32_t*)(v6 + 8);
				if (v11 & 0x1000) {
					if (*(uint32_t*)(v6 + 12) & 0x200000) {
						v17 = nox_xxx_gamedataGetFloat_419D40("ForceOfNatureStaffLimit");
						v12 = nox_float2int(v17);
						if (nox_xxx_inventoryCountObjects_4E7D30(v3, *(unsigned short*)(v6 + 4)) >= v12) {
							nox_xxx_netPriMsgToPlayer_4DA2C0(v3, "pickup.c:MaxSameItem", 0);
							nox_xxx_aud_501960(925, v3, 0, 0);
							return;
						}
					}
				}
			}
			if (nox_common_gameFlags_check_40A5C0(4096) &&
				(sub_5105D0(v6) || *(unsigned short*)(v6 + 4) == dword_5d4594_2386548)) {
				v13 = nox_xxx_newObjectWithTypeInd_4E3450(*(unsigned short*)(v6 + 4));
			} else {
				v13 = (uint32_t*)v6;
			}
			if (v13[2] & 0x110 || (v14 = (void (*)(int, uint32_t*, int, int))v13[177]) == 0) {
				nox_xxx_inventoryPutImpl_4F3070(v3, (int)v13, 1);
				nox_xxx_aud_501960(307, v3, 2, *(uint32_t*)(v3 + 36));
			} else {
				v14(v3, v13, 1, 1);
			}
			sub_510320(v6, (int)a2);
			if (sub_510540(v6)) {
				sub_50E7A0(a2, v6);
			}
			nox_xxx_playerSubGold_4FA5D0(v3, v8);
			sub_4D8870(*(unsigned char*)(*(uint32_t*)(v18 + 276) + 2064), v3);
		}
	}
}

//----- (00510640) --------------------------------------------------------
float* sub_510640_trade(int a1, int a2, int a3, float* a4) {
	int v4;                                // ebp
	float* result;                         // eax
	uint32_t* v6;                          // edi
	int v7;                                // esi
	unsigned int v8;                       // ebx
	int v9;                                // edi
	int v10;                               // eax
	int v11;                               // edi
	uint32_t* v12;                         // eax
	void (*v13)(int, uint32_t*, int, int); // ecx
	wchar2_t* v14;                          // eax
	int v15;                               // [esp+0h] [ebp-1Ch]
	float v16;                             // [esp+0h] [ebp-1Ch]
	float v17;                             // [esp+0h] [ebp-1Ch]
	unsigned int v18;                      // [esp+14h] [ebp-8h]
	unsigned int v19;                      // [esp+18h] [ebp-4h]
	int v20;                               // [esp+20h] [ebp+4h]

	v4 = a1;
	v15 = a1;
	v20 = *(uint32_t*)(a1 + 748);
	v19 = nox_xxx_playerGetGold_4FA6B0(v15);
	if (!dword_5d4594_2386552) {
		dword_5d4594_2386552 = nox_xxx_getNameId_4E3AA0("AnkhTradable");
	}
	result = a4;
	v18 = 0;
	if (a4) {
		while (1) {
			v6 = (uint32_t*)a2;
			result = *(float**)(a2 + 20);
			if (!result) {
				return result;
			}
			while (*(unsigned short*)(*(uint32_t*)result + 4) != a3) {
				result = (float*)*((uint32_t*)result + 2);
				if (!result) {
					return result;
				}
			}
			v7 = *(uint32_t*)result;
			if (!*(uint32_t*)result) {
				return result;
			}
			v8 = nox_xxx_shopGetItemCost_50E3D0(1, a2, *result);
			if (v8 > v19) {
				return (float*)sub_5104F0(v4, v8 - v19);
			}
			if (*(uint8_t*)(v7 + 8) & 0x10) {
				v9 = nox_xxx_inventoryCountObjects_4E7D30(v4, *(unsigned short*)(v7 + 4));
				if (v9 >= (nox_common_gameFlags_check_40A5C0(6144) ? 9 : 3)) {
					v14 = nox_strman_loadString_40F1D0("pickup.c:MaxSameItem", 0,
													   "C:\\NoxPost\\src\\Server\\System\\Trade.c", 3108);
					return (float*)nox_xxx_netSendLineMessage_4D9EB0(v4, v14);
				}
				v6 = (uint32_t*)a2;
			}
			if (*(unsigned short*)(v7 + 4) == dword_5d4594_2386552) {
				v16 = nox_xxx_gamedataGetFloat_419D40("MaxExtraLives");
				if (*(uint32_t*)(v20 + 320) >= nox_float2int(v16)) {
					break;
				}
			}
			if (nox_common_gameFlags_check_40A5C0(4096)) {
				v10 = *(uint32_t*)(v7 + 8);
				if (v10 & 0x1000) {
					if (*(uint32_t*)(v7 + 12) & 0x200000) {
						v17 = nox_xxx_gamedataGetFloat_419D40("ForceOfNatureStaffLimit");
						v11 = nox_float2int(v17);
						if (nox_xxx_inventoryCountObjects_4E7D30(v4, *(unsigned short*)(v7 + 4)) >= v11) {
							nox_xxx_netPriMsgToPlayer_4DA2C0(v4, "pickup.c:MaxSameItem", 0);
							goto LABEL_36;
						}
						v6 = (uint32_t*)a2;
					}
				}
			}
			if (nox_common_gameFlags_check_40A5C0(4096) &&
				(sub_5105D0(v7) || *(unsigned short*)(v7 + 4) == dword_5d4594_2386552)) {
				v12 = nox_xxx_newObjectWithTypeInd_4E3450(*(unsigned short*)(v7 + 4));
			} else {
				v12 = (uint32_t*)v7;
			}
			v13 = (void (*)(int, uint32_t*, int, int))v12[177];
			if (v13) {
				v13(v4, v12, 1, 1);
			} else {
				nox_xxx_inventoryPutImpl_4F3070(v4, (int)v12, 1);
			}
			sub_510320(v7, (int)v6);
			if (sub_510540(v7)) {
				sub_50E7A0(v6, v7);
			}
			nox_xxx_playerSubGold_4FA5D0(v4, v8);
			sub_4D8870(*(unsigned char*)(*(uint32_t*)(v20 + 276) + 2064), v4);
			result = (float*)++v18;
			if (v18 >= (unsigned int)a4) {
				return result;
			}
		}
		nox_xxx_netPriMsgToPlayer_4DA2C0(v4, "pickup.c:MaxTradableAnkhsReached", 0);
	LABEL_36:
		nox_xxx_aud_501960(925, v4, 0, 0);
	}
	return result;
}

//----- (005109C0) --------------------------------------------------------
uint32_t* sub_5109C0_trade(int* a1, int a2, uint32_t* a3) {
	int v3;           // ebx
	int v4;           // esi
	uint32_t* result; // eax
	wchar2_t* v6;      // eax
	wchar2_t* v7;      // eax
	char v8[8];       // [esp+Ch] [ebp-8h]

	v3 = a1[187];
	if (!*getMemU32Ptr(0x5D4594, 2386556)) {
		*getMemU32Ptr(0x5D4594, 2386556) = nox_xxx_getNameId_4E3AA0("Glyph");
	}
	v4 = a1[126];
	result = a3;
	v8[0] = -55;
	v8[1] = 29;
	*(uint16_t*)&v8[2] = (uint16_t)a3;
	if (v4) {
		while (*(uint32_t**)(v4 + 36) != a3) {
			v4 = *(uint32_t*)(v4 + 496);
			if (!v4) {
				return result;
			}
		}
		if (nox_xxx_ItemIsDroppable_53EBF0(v4) == 1) {
			v6 =
				nox_strman_loadString_40F1D0("CantSellQuestItem", 0, "C:\\NoxPost\\src\\Server\\System\\Trade.c", 3298);
			nox_xxx_netSendLineMessage_4D9EB0((int)a1, v6);
			nox_xxx_aud_501960(925, (int)a1, 2, a1[9]);
		} else if (*(unsigned short*)(v4 + 4) == *getMemU32Ptr(0x5D4594, 2386556)) {
			v7 = nox_strman_loadString_40F1D0("CantSellItem", 0, "C:\\NoxPost\\src\\Server\\System\\Trade.c", 3308);
			nox_xxx_netSendLineMessage_4D9EB0((int)a1, v7);
			nox_xxx_aud_501960(925, (int)a1, 2, a1[9]);
		} else {
			*(uint32_t*)&v8[4] = nox_xxx_shopGetItemCost_50E3D0(0, a2, *(float*)&v4);
			result =
				(uint32_t*)nox_xxx_netSendPacket0_4E5420(*(unsigned char*)(*(uint32_t*)(v3 + 276) + 2064), v8, 8, 0, 1);
		}
	}
	return result;
}

//----- (00510BE0) --------------------------------------------------------
uint32_t* sub_510BE0_trade(int* a1, int a2, uint32_t* a3) {
	uint32_t* result; // eax
	int v4;           // ebx
	int v5;           // esi
	wchar2_t* v6;      // eax
	wchar2_t* v7;      // eax
	int v8;           // eax

	nox_xxx_playerGetGold_4FA6B0((int)a1);
	result = *(uint32_t**)&dword_5d4594_2386560;
	v4 = a1[187];
	if (!dword_5d4594_2386560) {
		result = (uint32_t*)nox_xxx_getNameId_4E3AA0("Glyph");
		dword_5d4594_2386560 = result;
	}
	v5 = a1[126];
	if (v5) {
		result = a3;
		while (*(uint32_t**)(v5 + 36) != a3) {
			v5 = *(uint32_t*)(v5 + 496);
			if (!v5) {
				return result;
			}
		}
		if (nox_xxx_ItemIsDroppable_53EBF0(v5) == 1) {
			v6 =
				nox_strman_loadString_40F1D0("CantSellQuestItem", 0, "C:\\NoxPost\\src\\Server\\System\\Trade.c", 3413);
			nox_xxx_netSendLineMessage_4D9EB0((int)a1, v6);
			nox_xxx_aud_501960(925, (int)a1, 2, a1[9]);
		} else if (*(unsigned short*)(v5 + 4) == dword_5d4594_2386560) {
			v7 = nox_strman_loadString_40F1D0("CantSellItem", 0, "C:\\NoxPost\\src\\Server\\System\\Trade.c", 3423);
			nox_xxx_netSendLineMessage_4D9EB0((int)a1, v7);
			nox_xxx_aud_501960(925, (int)a1, 2, a1[9]);
		} else {
			sub_4ED0C0((int)a1, (int*)v5);
			nox_xxx_delayedDeleteObject_4E5CC0(v5);
			v8 = nox_xxx_shopGetItemCost_50E3D0(0, a2, *(float*)&v5);
			nox_xxx_playerAddGold_4FA590((int)a1, v8);
			sub_4D8870(*(unsigned char*)(*(uint32_t*)(v4 + 276) + 2064), (int)a1);
			nox_xxx_aud_501960(307, (int)a1, 2, a1[9]);
		}
	}
	return result;
}
