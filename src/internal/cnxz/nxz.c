#include <stdint.h>
#include <stdlib.h>
#include <string.h>

void* nxz_getMemAt(uintptr_t base, uintptr_t off);

#define SHIWORD(x) (((short*)(&x))[1])

typedef struct {
	uint32_t v1;
	uint32_t v2;
} uint32_vec2;

uint32_vec2 nxz_table_2[9] = {
	{0x8, 0x106},
	{0x0, 0x0},
	{0x0, 0x1},
	{0x1, 0x2},
	{0x2, 0x4},
	{0x3, 0x8},
	{0x4, 0x10},
	{0x5, 0x20},
	{0x6, 0x40},
};

uint32_vec2 nxz_table_1[272] = {
	{0x1d70009, 0x1d80009},
	{0x1d90009, 0x1da0009},
	{0x1db0009, 0x1dc0009},
	{0x1dd0009, 0x1de0009},
	{0x1df0009, 0x1e00009},
	{0x1e10009, 0x1e20009},
	{0x1e30009, 0x1e40009},
	{0x1e50009, 0x1e60009},
	{0x1e70009, 0x1e80009},
	{0x1e90009, 0x1ea0009},
	{0x1eb0009, 0x1ec0009},
	{0x1ed0009, 0x1ee0009},
	{0x1ef0009, 0x1f00009},
	{0x1f10009, 0x1f20009},
	{0x1f30009, 0x1f40009},
	{0x1f50009, 0x1f60009},
	{0x1f70009, 0x1f80009},
	{0x1f90009, 0x1fa0009},
	{0x1fb0009, 0x170007},
	{0x6, 0x10006},
	{0x20006, 0x30006},
	{0x80007, 0x90007},
	{0xa0007, 0xb0007},
	{0xc0007, 0xd0007},
	{0xe0007, 0xf0007},
	{0x100007, 0x110007},
	{0x120007, 0x130007},
	{0x1fc0009, 0x1fd0009},
	{0x108, 0x1},
	{0x0, 0x109},
	{0x2, 0x0},
	{0x109, 0x2},
	{0x2, 0x10a},
	{0x3, 0x0},
	{0x10a, 0x3},
	{0x2, 0x10a},
	{0x3, 0x4},
	{0x10a, 0x3},
	{0x6, 0x10b},
	{0x4, 0x0},
	{0x10b, 0x4},
	{0x2, 0x10b},
	{0x4, 0x4},
	{0x10b, 0x4},
	{0x6, 0x10b},
	{0x4, 0x8},
	{0x10b, 0x4},
	{0xa, 0x10b},
	{0x4, 0xc},
	{0x10b, 0x4},
	{0xe, 0x0},
	{0x3, 0x0},
	{0x3, 0x1},
	{0x4, 0x4},
	{0x4, 0x5},
	{0x5, 0xc},
	{0x5, 0xd},
	{0x5, 0xe},
	{0x5, 0xf},
	{0x6, 0x20},
	{0x6, 0x21},
	{0x6, 0x22},
	{0x6, 0x23},
	{0x6, 0x24},
	{0x6, 0x25},
	{0x6, 0x26},
	{0x6, 0x27},
	{0x7, 0x50},
	{0x7, 0x51},
	{0x7, 0x52},
	{0x7, 0x53},
	{0x7, 0x54},
	{0x7, 0x55},
	{0x7, 0x56},
	{0x7, 0x57},
	{0x7, 0x58},
	{0x7, 0x59},
	{0x7, 0x5a},
	{0x7, 0x5b},
	{0x7, 0x5c},
	{0x7, 0x5d},
	{0x7, 0x5e},
	{0x7, 0x5f},
	{0x8, 0xc0},
	{0x8, 0xc1},
	{0x8, 0xc2},
	{0x8, 0xc3},
	{0x8, 0xc4},
	{0x8, 0xc5},
	{0x8, 0xc6},
	{0x8, 0xc7},
	{0x8, 0xc8},
	{0x8, 0xc9},
	{0x8, 0xca},
	{0x8, 0xcb},
	{0x8, 0xcc},
	{0x8, 0xcd},
	{0x8, 0xce},
	{0x8, 0xcf},
	{0x8, 0xd0},
	{0x8, 0xd1},
	{0x8, 0xd2},
	{0x8, 0xd3},
	{0x8, 0xd4},
	{0x8, 0xd5},
	{0x8, 0xd6},
	{0x8, 0xd7},
	{0x8, 0xd8},
	{0x8, 0xd9},
	{0x8, 0xda},
	{0x8, 0xdb},
	{0x8, 0xdc},
	{0x8, 0xdd},
	{0x8, 0xde},
	{0x8, 0xdf},
	{0x9, 0x1c0},
	{0x9, 0x1c1},
	{0x9, 0x1c2},
	{0x9, 0x1c3},
	{0x9, 0x1c4},
	{0x9, 0x1c5},
	{0x9, 0x1c6},
	{0x9, 0x1c7},
	{0x9, 0x1c8},
	{0x9, 0x1c9},
	{0x9, 0x1ca},
	{0x9, 0x1cb},
	{0x9, 0x1cc},
	{0x9, 0x1cd},
	{0x9, 0x1ce},
	{0x9, 0x1cf},
	{0x9, 0x1d0},
	{0x9, 0x1d1},
	{0x9, 0x1d2},
	{0x9, 0x1d3},
	{0x9, 0x1d4},
	{0x9, 0x1d5},
	{0x9, 0x1d6},
	{0x9, 0x1d7},
	{0x9, 0x1d8},
	{0x9, 0x1d9},
	{0x9, 0x1da},
	{0x9, 0x1db},
	{0x9, 0x1dc},
	{0x9, 0x1dd},
	{0x9, 0x1de},
	{0x9, 0x1df},
	{0x9, 0x1e0},
	{0x9, 0x1e1},
	{0x9, 0x1e2},
	{0x9, 0x1e3},
	{0x9, 0x1e4},
	{0x9, 0x1e5},
	{0x9, 0x1e6},
	{0x9, 0x1e7},
	{0x9, 0x1e8},
	{0x9, 0x1e9},
	{0x9, 0x1ea},
	{0x9, 0x1eb},
	{0x9, 0x1ec},
	{0x9, 0x1ed},
	{0x9, 0x1ee},
	{0x9, 0x1ef},
	{0x9, 0x1f0},
	{0x9, 0x1f1},
	{0x9, 0x1f2},
	{0x9, 0x1f3},
	{0x9, 0x1f4},
	{0x9, 0x1f5},
	{0x9, 0x1f6},
	{0x9, 0x1f7},
	{0x9, 0x1f8},
	{0x9, 0x1f9},
	{0x9, 0x1fa},
	{0x9, 0x1fb},
	{0x9, 0x1fc},
	{0x9, 0x1fd},
	{0x9, 0x1fe},
	{0x9, 0x1ff},
	{0x2, 0x0},
	{0x3, 0x4},
	{0x3, 0xc},
	{0x4, 0x14},
	{0x4, 0x24},
	{0x4, 0x34},
	{0x4, 0x44},
	{0x4, 0x54},
	{0x4, 0x64},
	{0x4, 0x74},
	{0x4, 0x84},
	{0x4, 0x94},
	{0x4, 0xa4},
	{0x5, 0xb4},
	{0x5, 0xd4},
	{0x5, 0xf4},
	{0x1010100, 0x1030102},
	{0x1050104, 0x1070106},
	{0x1090108, 0x10b010a},
	{0x10d010c, 0x10f010e},
	{0x200000, 0xff0030},
	{0x20001, 0x40003},
	{0x60005, 0x80007},
	{0xa0009, 0xc000b},
	{0xe000d, 0x10000f},
	{0x120011, 0x140013},
	{0x160015, 0x180017},
	{0x1a0019, 0x1c001b},
	{0x1e001d, 0x21001f},
	{0x230022, 0x250024},
	{0x270026, 0x290028},
	{0x2b002a, 0x2d002c},
	{0x2f002e, 0x320031},
	{0x340033, 0x360035},
	{0x380037, 0x3a0039},
	{0x3c003b, 0x3e003d},
	{0x40003f, 0x420041},
	{0x440043, 0x460045},
	{0x480047, 0x4a0049},
	{0x4c004b, 0x4e004d},
	{0x50004f, 0x520051},
	{0x540053, 0x560055},
	{0x580057, 0x5a0059},
	{0x5c005b, 0x5e005d},
	{0x60005f, 0x620061},
	{0x640063, 0x660065},
	{0x680067, 0x6a0069},
	{0x6c006b, 0x6e006d},
	{0x70006f, 0x720071},
	{0x740073, 0x760075},
	{0x780077, 0x7a0079},
	{0x7c007b, 0x7e007d},
	{0x80007f, 0x820081},
	{0x840083, 0x860085},
	{0x880087, 0x8a0089},
	{0x8c008b, 0x8e008d},
	{0x90008f, 0x920091},
	{0x940093, 0x960095},
	{0x980097, 0x9a0099},
	{0x9c009b, 0x9e009d},
	{0xa0009f, 0xa200a1},
	{0xa400a3, 0xa600a5},
	{0xa800a7, 0xaa00a9},
	{0xac00ab, 0xae00ad},
	{0xb000af, 0xb200b1},
	{0xb400b3, 0xb600b5},
	{0xb800b7, 0xba00b9},
	{0xbc00bb, 0xbe00bd},
	{0xc000bf, 0xc200c1},
	{0xc400c3, 0xc600c5},
	{0xc800c7, 0xca00c9},
	{0xcc00cb, 0xce00cd},
	{0xd000cf, 0xd200d1},
	{0xd400d3, 0xd600d5},
	{0xd800d7, 0xda00d9},
	{0xdc00db, 0xde00dd},
	{0xe000df, 0xe200e1},
	{0xe400e3, 0xe600e5},
	{0xe800e7, 0xea00e9},
	{0xec00eb, 0xee00ed},
	{0xf000ef, 0xf200f1},
	{0xf400f3, 0xf600f5},
	{0xf800f7, 0xfa00f9},
	{0xfc00fb, 0xfe00fd},
	{0x1110110, 0x0},
	{0x1, 0x8},
	{0x2, 0xa},
	{0x3, 0xe},
	{0x4, 0x16},
	{0x5, 0x26},
	{0x6, 0x46},
	{0x7, 0x86},
	{0x8, 0x106},
};

//----- (0057DD90) --------------------------------------------------------
uint32_t* sub57DD90(uint32_t* this) {
	uint32_t* v1; // esi
	void* v2;     // eax

	v1 = this;
	v2 = calloc(1, 0x224u);
	*v1 = v2;
	memset(v2, 0, 0x224u);
	return v1;
}

//----- (0057E8A0) --------------------------------------------------------
uint32_t* sub57E8A0(uint32_t* this) {
	uint32_t* v1;      // ebx
	unsigned char* v2; // eax

	v1 = this;
	sub57DD90(this);
	v2 = (unsigned char*)calloc(1, 0x224u);
	v1[33] = v2;
	memcpy(v2, nxz_getMemAt(0x587000, 315976), 0x224u);
	memcpy(v1 + 1, nxz_getMemAt(0x587000, 315848), 0x80u);
	return v1;
}

//----- (0057E9A0) --------------------------------------------------------
uint32_t* sub57E9A0(uint32_t* this) {
	uint32_t* v1; // esi

	v1 = this;
	*this = calloc(1, 0x10000u);
	v1[1] = 0;
	sub57E8A0(v1 + 2);
	v1[37] = 0;
	v1[36] = 0;
	return v1;
}

//----- (00578BF0) --------------------------------------------------------
void* nxz_decompress_new() {
	uint32_t* v0;     // eax
	uint32_t* result; // eax

	v0 = calloc(1, 0x98u);
	if (v0) {
		result = sub57E9A0(v0);
	} else {
		result = 0;
	}
	return result;
}

//----- (0057DDC0) --------------------------------------------------------
void sub57DDC0(void** this) { free(*this); }

//----- (0057E910) --------------------------------------------------------
void sub57E910(void** this) {
	void** v1; // esi

	v1 = this;
	free(this[33]);
	sub57DDC0(v1);
}

//----- (0057EA00) --------------------------------------------------------
void sub57EA00(void** this) {
	void** v1; // esi
	void** v2; // ecx
	void** v4; // [esp+4h] [ebp-10h]

	v1 = this;
	v4 = this;
	v2 = 0;
	if (v4) {
		v2 = v1 + 2;
	}
	sub57E910(v2);
	free(*v1);
}

//----- (00578C40) --------------------------------------------------------
void nxz_decompress_free(void* lpMem) {
	if (lpMem) {
		sub57EA00((void**)lpMem);
		free(lpMem);
	}
}

//----- (0057DDE0) --------------------------------------------------------
unsigned int sub57DDE0(int a1, int a2) {
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
				v12 = *(uint32_t*)(4 * v5 + v2);
				if (v5 > i) {
					v7 = 4 * i;
					do {
						v8 = *(short*)(v6 - v7 + v2 + 2) - SHIWORD(v12);
						if (!v8) {
							v8 = *(short*)(v6 - v7 + v2) - (short)v12;
						}
						if (v8 >= 0) {
							break;
						}
						*(uint32_t*)(v6 + v2) = *(uint32_t*)(v6 - v7 + v2);
						v6 -= v7;
						v10 -= i;
					} while (v10 > i);
					v5 = v11;
				}
				++v5;
				*(uint32_t*)(v2 + 4 * v10) = v12;
				v3 = a2;
				v11 = v5;
			} while (v5 <= a2);
		}
		result = (unsigned int)(i / 3) >> 31;
	}
	return result;
}

//----- (0057DEA0) --------------------------------------------------------
int sub57DEA0(uint32_t* this, uint16_t* a2) {
	uint16_t* v2; // esi
	int v3;       // ebx
	int i;        // eax
	short* v5;    // edi
	short v6;     // dx

	v2 = a2;
	v3 = 0;
	for (i = 0; i < 274; ++i) {
		*v2 = i;
		v2 += 2;
		*(v2 - 1) = *(uint16_t*)(*this + 2 * i);
		v5 = (short*)(*this + 2 * i);
		v6 = *v5;
		v3 += v6;
		*v5 = v6 >> 1;
	}
	sub57DDE0((int)(a2 - 2), 274);
	return v3;
}

//----- (0057EA80) --------------------------------------------------------
int nxz_decompress(void* a1p, uint8_t* a2p, int* a3p, uint8_t* a4p, int* a5p) {
	uint32_t* this = a1p;
	uint8_t* a2 = a2p;
	uint32_t* a3 = a3p;
	unsigned int a4 = a4p;
	uint32_t* a5 = a5p;
	unsigned char* v5; // ebp
	uint32_t* v6;      // ebx
	unsigned int v7;   // edx
	int v8;            // esi
	int v9;            // eax
	int v10;           // ecx
	unsigned int v11;  // eax
	int v12;           // esi
	int v13;           // eax
	int v14;           // edi
	int v15;           // edx
	int v16;           // ecx
	int v17;           // eax
	int v18;           // ecx
	int v19;           // eax
	char* v20;         // ecx
	short v21;         // si
	int v22;           // edi
	uint32_t* v23;     // edx
	int v24;           // esi
	int v25;           // ecx
	int v26;           // eax
	int v27;           // esi
	int v28;           // eax
	int v29;           // edi
	int v30;           // esi
	int v31;           // esi
	int v32;           // ecx
	int v33;           // edx
	int v34;           // esi
	int v35;           // ecx
	unsigned int v36;  // eax
	int v37;           // esi
	int v38;           // edi
	int v39;           // eax
	int v40;           // ecx
	unsigned int v41;  // eax
	int v42;           // edi
	int v43;           // eax
	int v44;           // edx
	uint8_t* v45;      // edi
	int v46;           // ebp
	int v47;           // eax
	int v48;           // ecx
	int v49;           // esi
	int v50;           // esi
	int v51;           // edx
	const void* v52;   // esi
	unsigned int v53;  // ecx
	int v54;           // esi
	int v55;           // edi
	uint8_t* v56;      // ebp
	int v57;           // edi
	int v58;           // edx
	void* v59;         // edi
	unsigned int v60;  // ecx
	uint8_t* v61;      // esi
	int v63;           // [esp+10h] [ebp-464h]
	int i;             // [esp+10h] [ebp-464h]
	int v65;           // [esp+10h] [ebp-464h]
	int v66;           // [esp+14h] [ebp-460h]
	int v67;           // [esp+14h] [ebp-460h]
	uint8_t* v68;      // [esp+14h] [ebp-460h]
	unsigned int v69;  // [esp+18h] [ebp-45Ch]
	int v70;           // [esp+1Ch] [ebp-458h]
	int v71;           // [esp+1Ch] [ebp-458h]
	uint8_t* v72;      // [esp+20h] [ebp-454h]
	unsigned int v73;  // [esp+24h] [ebp-450h]
	uint8_t* v74;      // [esp+28h] [ebp-44Ch]
	char v75[1096];    // [esp+2Ch] [ebp-448h]

	v5 = (unsigned char*)a4;
	v6 = this;
	v7 = a4 + *a5;
	v74 = a2;
	v73 = a4;
	v69 = a4 + *a5;
	v72 = &a2[*a3];
	this[37] = 0;
	if (a4 >= v7) {
		return 0;
	}
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
			v13 = *(short*)(v6[35] + 2 * v6[2 * v9 + 4]);
			goto LABEL_18;
		}
		v14 = v6[37];
		if (v14 >= v12) {
			goto LABEL_15;
		}
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
		if (v17 >= 274) {
			return 0;
		}
		v13 = *(short*)(v6[35] + 2 * v17);
	LABEL_18:
		++*(uint16_t*)(v6[2] + 2 * v13);
		// _dprintf("decompress: %d", v13);
		if (v13 < 256) {
			if (a2 < v72) {
				*a2++ = v13;
				v18 = v6[1];
				v6[1] = v18 + 1;
				*(uint8_t*)((unsigned short)v18 + *v6) = v13;
				goto LABEL_73;
			}
			return 0;
		}
		if (v13 == 272) {
			sub57DEA0(v6 + 2, v75);
			v19 = 0;
			v20 = v75;
			do {
				v21 = *(uint16_t*)v20;
				v20 += 4;
				*(uint16_t*)(v19 + v6[35]) = v21;
				v19 += 2;
			} while (v19 < 548);
			v22 = 0;
			v23 = v6 + 4;
			v70 = 0;
			v66 = 16;
			while (1) {
				for (i = 0;; ++i) {
					v24 = v6[37];
					if (v24 >= 1) {
						goto LABEL_29;
					}
					if ((unsigned int)v5 >= v69) {
						break;
					}
					v25 = (*v5++ << (24 - v24)) | v6[36];
					v6[36] = v25;
					v6[37] = v24 + 8;
				LABEL_29:
					v26 = v6[36] >> 31;
					v27 = v6[37] - 1;
					v6[36] *= 2;
					v6[37] = v27;
					if (v26) {
						goto LABEL_32;
					}
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
		if (v13 == 273) {
			break;
		}
		if (v13 < 264) {
			v28 = v13 - 256;
			goto LABEL_43;
		}
		v29 = nxz_table_1[v13].v1;
		v30 = v6[37];
		if (v30 >= v29) {
			goto LABEL_41;
		}
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
		v28 = v31 + nxz_table_1[v13].v2;
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
		v37 = nxz_table_2[v71+1].v1 + 9;
		if (v37 <= 8) {
			goto LABEL_55;
		}
		v38 = v6[37];
		v37 = nxz_table_2[v71+1].v1 + 1;
		if (v38 >= 8) {
			goto LABEL_53;
		}
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
		if (v42 >= v37) {
			goto LABEL_59;
		}
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
		v46 = (nxz_table_2[v71+1].v2 << 9) + (v65 | v43);
		v47 = v67 + 4;
		v68 = &a2[v67 + 4];
		// _dprintf("length: %d, distance: %d", v47, v46);
		if (v68 > v72) {
			return 0;
		}
		v48 = v6[1] - v46;
		if (v47 >= v46) {
			v50 = (unsigned short)v48;
			if ((unsigned short)v48 + v46 <= 0x10000) {
				v53 = v46;
				v52 = (const void*)(*v6 + v50);
			} else {
				v51 = 0x10000 - (unsigned short)v48;
				memcpy(a2, (const void*)(*v6 + (unsigned short)v48), 0x10000 - (unsigned short)v48);
				v52 = (const void*)*v6;
				v53 = v46 - v51;
				v45 = &a2[v51];
			}
			memcpy(v45, v52, v53);
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
			v49 = (unsigned short)v48;
			if (v49 + v47 <= 0x10000) {
				memcpy(a2, (const void*)(*v6 + v49), v47);
			} else {
				memcpy(a2, (const void*)(*v6 + v49), 0x10000 - v49);
				memcpy(&a2[0x10000 - v49], (const void*)*v6, v47 - (0x10000 - v49));
			}
		}
		v57 = v6[1] & 0xFFFF;
		if (v57 + v47 <= 0x10000) {
			v61 = a2;
			v60 = v47;
			v59 = (void*)(*v6 + v57);
		} else {
			v58 = 0x10000 - v57;
			memcpy((void*)(*v6 + v57), a2, 0x10000 - v57);
			v59 = (void*)*v6;
			v60 = v47 - v58;
			v61 = &a2[v58];
		}
		v5 = (unsigned char*)a4;
		memcpy(v59, v61, v60);
		v6[1] += v47;
		a2 = v68;
	LABEL_73:
		if ((unsigned int)v5 >= v69) {
			return 0;
		}
		v7 = v69;
	}
	if (a3) {
		*a3 += v74 - a2;
	}
	if (a5) {
		*a5 += v73 - (uint32_t)v5;
	}
	return 1;
}
