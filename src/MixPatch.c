#include "GameEx.h"

__int16 asc_9800B0[] = {
	0,   0,   0,   0,   0,   0,   49,  33,  0,   50,  64,  0,   51,  35,  0,   52,  36,  0,   53,  37,  0,   54,  94,
	0,   55,  38,  0,   56,  42,  0,   57,  40,  0,   48,  41,  0,   45,  95,  0,   61,  43,  0,   8,   8,   0,   9,
	9,   0,   233, 201, 0,   246, 214, 0,   243, 211, 0,   234, 202, 0,   229, 197, 0,   237, 205, 0,   227, 195, 0,
	248, 216, 0,   249, 217, 0,   231, 199, 0,   245, 213, 0,   250, 218, 0,   10,  10,  0,   0,   0,   0,   244, 212,
	0,   251, 219, 0,   226, 194, 0,   224, 192, 0,   239, 207, 0,   240, 208, 0,   238, 206, 0,   235, 203, 0,   228,
	196, 0,   230, 198, 0,   253, 221, 0,   96,  126, 0,   0,   0,   0,   92,  124, 0,   255, 223, 0,   247, 215, 0,
	241, 209, 0,   236, 204, 0,   232, 200, 0,   242, 210, 0,   252, 220, 0,   225, 193, 0,   254, 222, 0,   47,  63,
	0,   0,   0,   0,   42,  42,  0,   0,   0,   0,   32,  32,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
	0,   0,   0,   0,   0,   0,   55,  55,  0,   56,  56,  0,   57,  57,  0,   45,  45,  0,   52,  52,  0,   53,  53,
	0,   54,  54,  0,   43,  43,  0,   49,  49,  0,   50,  50,  0,   51,  51,  0,   48,  48,  0,   46,  46,  0,   0,
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   49,  33,  0,   50,  64,  0,   51,
	35,  0,   52,  36,  0,   53,  37,  0,   54,  94,  0,   55,  38,  0,   56,  42,  0,   57,  40,  0,   48,  41,  0,
	45,  95,  0,   61,  43,  0,   8,   8,   0,   9,   9,   0,   233, 201, 0,   246, 214, 0,   243, 211, 0,   234, 202,
	0,   229, 197, 0,   237, 205, 0,   227, 195, 0,   248, 216, 0,   249, 217, 0,   231, 199, 0,   245, 213, 0,   250,
	218, 0,   10,  10,  0,   0,   0,   0,   244, 212, 0,   251, 219, 0,   226, 194, 0,   224, 192, 0,   239, 207, 0,
	240, 208, 0,   238, 206, 0,   235, 203, 0,   228, 196, 0,   230, 198, 0,   253, 221, 0,   96,  126, 0,   0,   0,
	0,   92,  124, 0,   255, 223, 0,   247, 215, 0,   241, 209, 0,   236, 204, 0,   232, 200, 0,   242, 210, 0,   252,
	220, 0,   225, 193, 0,   254, 222, 0,   47,  63,  0,   0,   0,   0,   42,  42,  0,   0,   0,   0,   32,  32,  0,
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   55,  55,  0,   56,  56,  0,   57,
	57,  0,   45,  45,  0,   52,  52,  0,   53,  53,  0,   54,  54,  0,   43,  43,  0,   49,  49,  0,   50,  50,  0,
	51,  51,  0,   48,  48,  0,   46,  46,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0};

void init_data_mix() { GameEx_DllMain(NULL, 1, NULL); }

void OnLibraryNotice_stub(int a1, ...) {
	/* TODO: STUB */
}

void __cdecl sub_980523(_DWORD* a1) {
	_DWORD* i; // esi
	int v2;    // eax

	if (!a1)
		return;
	for (i = *(_DWORD**)(a1 + 126); i; i = (_DWORD*)i[124]) {
		if (i[2] & 0x2000000) {
			v2 = i[4];
			if (v2 & 0x100) {
				if (nox_xxx_unitArmorInventoryEquipFlags_415C70((int)i) & 0x3000000)
					*(_DWORD*)(*(_DWORD*)(*(_DWORD*)(a1 + 187) + 276) + 2500) = i;
			}
		}
	}
}

_DWORD* __cdecl sub_9805EB(_DWORD* a1) {
	_DWORD* v1; // esi

	if (!a1)
		goto LABEL_6;
	v1 = *(_DWORD**)(a1 + 126);
	if (!v1)
		goto LABEL_6;
	while (!(v1[2] & 0x2000000) || (unsigned __int8)v1[4] != 16) {
	LABEL_6:
		v1 = (_DWORD*)v1[124];
		if (!v1)
			return 0;
	}
	return (int)v1;
}

int __stdcall mix_recvfrom(SOCKET s, char* buf, int len, int flags, struct sockaddr* from, int* fromlen) {
	return MixRecvFromReplacer(s, buf, len, flags, from, fromlen);
}
