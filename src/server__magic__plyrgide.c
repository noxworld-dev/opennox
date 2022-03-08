#include "GAME1.h"
#include "GAME3_2.h"
#include "GAME3_3.h"
#include "GAME4.h"
#include "GAME5_2.h"
#include "common__strman.h"
#include "operators.h"

//----- (004D8000) --------------------------------------------------------
int nox_xxx_netReportGuideAward_4D8000(int a1, char a2, char a3, int a4) {
	int result; // eax
	int v5;     // ecx

	result = a1;
	if (*(uint8_t*)(a1 + 8) & 4) {
		v5 = *(uint32_t*)(a1 + 748);
		BYTE1(a1) = a2;
		LOBYTE(a1) = -47;
		BYTE2(a1) = a3;
		if (a4) {
			BYTE2(a1) = a3 | 0x80;
		}
		result = nox_xxx_netSendPacket1_4E5390(*(unsigned char*)(*(uint32_t*)(v5 + 276) + 2064), (int)&a1, 3, 0, 1);
	}
	return result;
}

//----- (004FAE80) --------------------------------------------------------
int nox_xxx_awardBeastGuide_4FAE80_magic_plyrgide(int a1, int a2, int a3) {
	int v3;             // ebp
	int v4;             // edi
	int v5;             // eax
	int v6;             // ecx
	uint32_t* v7;       // eax
	unsigned char* v8;  // ecx
	uint32_t* v9;       // esi
	int v10;            // eax
	int* v11;           // esi
	int v12;            // eax
	char* i;            // esi
	int v14;            // eax
	wchar_t* v16;       // eax
	unsigned char* v17; // [esp+10h] [ebp+4h]

	v3 = a1;
	if (!(*(uint8_t*)(a1 + 8) & 4)) {
		return 0;
	}
	if (a2 <= 0 || a2 >= 41) {
		v16 = nox_strman_loadString_40F1D0("AwardGuideError", 0, "C:\\NoxPost\\src\\Server\\Magic\\PlyrGide.c", 39);
		nox_xxx_netSendLineMessage_4D9EB0(a1, v16);
		return 0;
	}
	v4 = *(uint32_t*)(a1 + 748);
	v5 = *(uint32_t*)(v4 + 276);
	v6 = *(uint32_t*)(v5 + 4 * a2 + 4244);
	v7 = (uint32_t*)(v5 + 4 * a2 + 4244);
	if (v6) {
		return 0;
	}
	*v7 = 1;
	nox_xxx_playerAwardSpellProtectionCRC_56FCE0(*(uint32_t*)(*(uint32_t*)(v4 + 276) + 4640), a2,
											  *(uint32_t*)(*(uint32_t*)(v4 + 276) + 4 * a2 + 4244));
	if (a3) {
		nox_xxx_aud_501960(227, a1, 0, 0);
		nox_xxx_netSendRewardNotify_4FAD50(a1, 1, a1, a2);
	}
	v8 = getMemAt(0x587000, 216292);
	v17 = getMemAt(0x587000, 216292);
	if (*getMemU32Ptr(0x587000, 216292)) {
		do {
			v9 = *(uint32_t**)v8;
			if (a2 == **(uint32_t**)v8) {
				v10 = v9[1];
				v11 = v9 + 1;
				if (v10) {
					do {
						*(uint32_t*)(*(uint32_t*)(v4 + 276) + 4 * v10 + 4244) = 1;
						nox_xxx_playerAwardSpellProtectionCRC_56FCE0(
							*(uint32_t*)(*(uint32_t*)(v4 + 276) + 4640), *v11,
							*(uint32_t*)(*(uint32_t*)(v4 + 276) + 4 * *v11 + 4244));
						v10 = v11[1];
						++v11;
					} while (v10);
					v8 = v17;
				}
			}
			v12 = *((uint32_t*)v8 + 1);
			v8 += 4;
			v17 = v8;
		} while (v12);
	}
	if (a3) {
		for (i = nox_common_playerInfoGetFirst_416EA0(); i; i = nox_common_playerInfoGetNext_416EE0((int)i)) {
			v14 = *((uint32_t*)i + 514);
			if (v14 != v3) {
				if (v14) {
					nox_xxx_netSendRewardNotify_4FAD50(v14, 1, v3, a2);
				}
			}
		}
	}
	nox_xxx_netReportGuideAward_4D8000(v3, a2, a3, 0);
	return 1;
}
