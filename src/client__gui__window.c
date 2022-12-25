#include <stdlib.h>
#include <string.h>

#include "client__gui__window.h"
#include "common/alloc/classes/alloc_class.h"

#include "defs.h" // nox_video_bag_section_t, nox_video_bag_image_t
#include "memmap.h"

// TODO: part of the GUI toolkit
void nox_client_drawImageAt_47D2C0(void* a1, int x, int y);
int nox_xxx_drawGetStringSize_43F840(int a1, unsigned short* a2, int* a3, int* a4, int a5);
void nox_client_drawSetColor_434460(int a1);
void nox_client_drawRectFilledOpaque_49CE30(int xLeft, int yTop, int a3, int a4);
nox_video_bag_image_t* nox_xxx_gLoadImg_42F970(const char* a1);

unsigned int dword_5d4594_1309696 = 0;
unsigned int dword_5d4594_1309704 = 0;

//----- (0046ACE0) --------------------------------------------------------
void sub_46ACE0(unsigned int* a1, int a2, int a3, int a4) {
	for (int i = a2; i <= a3; i++) {
		unsigned int* v5 = nox_xxx_wndGetChildByID_46B0C0(a1, i);
		nox_window_set_hidden((int)v5, a4);
	}
}

//----- (0046AD20) --------------------------------------------------------
void sub_46AD20(unsigned int* a1, int a2, int a3, int a4) {
	int i;            // esi
	unsigned int* v5; // eax

	for (i = a2; i <= a3; ++i) {
		v5 = nox_xxx_wndGetChildByID_46B0C0(a1, i);
		nox_xxx_wnd_46ABB0((int)v5, a4);
	}
}

//----- (0046AA20) --------------------------------------------------------
int nox_gui_getWindowOffs_46AA20(nox_window* win, unsigned int* px, unsigned int* py) {
	if (!win) {
		*px = 0;
		*py = 0;
		return -2;
	}
	*px = win->off_x;
	*py = win->off_y;
	return 0;
}

//----- (0046AA60) --------------------------------------------------------
int nox_client_wndGetPosition_46AA60(nox_window* win, unsigned int* px, unsigned int* py) {
	if (!win) {
		return -2;
	}

	*px = win->off_x;
	*py = win->off_y;
	for (nox_window* i = win->parent; i; i = i->parent) {
		*px += i->off_x;
		*py += i->off_y;
	}
	return 0;
}

//----- (0046AAB0) --------------------------------------------------------
bool nox_xxx_wndPointInWnd_46AAB0(unsigned int* a1, int a2, int a3) {
	unsigned int* v3; // esi
	int v5;           // [esp+4h] [ebp-Ch]
	int v6 = 0;       // [esp+8h] [ebp-8h]
	int v7 = 0;       // [esp+Ch] [ebp-4h]

	v3 = a1;
	nox_client_wndGetPosition_46AA60(a1, &a1, &v6);
	nox_window_get_size((int)v3, &v5, &v7);
	return a2 >= (int)a1 && a2 <= (int)a1 + v5 && a3 >= v6 && a3 <= v6 + v7;
}

//----- (0046AB20) --------------------------------------------------------
int sub_46AB20(unsigned int* a1, int a2, int a3) {
	int v4; // esi

	if (!a1) {
		return -2;
	}
	a1[6] = a2 + a1[4];
	v4 = a3 + a1[5];
	a1[2] = a2;
	a1[3] = a3;
	a1[7] = v4;
	nox_window_call_field_94((int)a1, 16388, a2, a3);
	return 0;
}

//----- (0046AB70) --------------------------------------------------------
int nox_window_get_size(nox_window* win, int* outW, int* outH) {
	if (!win) {
		*outW = 0;
		*outH = 0;
		return -2;
	}
	*outW = win->width;
	*outH = win->height;
	return 0;
}

//----- (0046ABB0) --------------------------------------------------------
int nox_xxx_wnd_46ABB0(nox_window* win, int a2) {
	int a1 = win;
	int v3;          // ecx
	unsigned int v4; // ecx
	int v5;          // esi

	if (!a1) {
		return -2;
	}
	v3 = *(unsigned int*)(a1 + 4);
	if (a2) {
		v4 = v3 | 8;
	} else {
		v4 = v3 & 0xFFFFFFF7;
	}
	v5 = *(unsigned int*)(a1 + 400);
	for (*(unsigned int*)(a1 + 4) = v4; v5; v5 = *(unsigned int*)(v5 + 388)) {
		nox_xxx_wnd_46ABB0(v5, a2);
	}
	return 0;
}

//----- (004A9E90) --------------------------------------------------------
void sub_4A9E90(int a1, int a2, int a3, int a4) {
	int v4;  // eax
	int v5;  // esi
	int v6;  // ebp
	int v7;  // edi
	int v8;  // ebx
	int v9;  // edi
	int v10; // esi
	int v11; // eax
	int v12; // esi
	// bool v13; // zf
	// bool v14; // of
	int v15; // ebp
	int v16; // esi
	int v18; // [esp+10h] [ebp-4h]
	int v19; // [esp+18h] [ebp+4h]
	int v20; // [esp+1Ch] [ebp+8h]
	int v21; // [esp+20h] [ebp+Ch]

	v4 = a1 + a3;
	v18 = a1;
	v5 = a1 + 10;
	v6 = a2 - 10;
	v7 = a1 + a3 - 30;
	v19 = a1 + a3;
	v21 = a2 - 10;
	v8 = a2 + a4 - 10;
	if (v5 <= v7) {
		do {
			nox_client_drawImageAt_47D2C0(*getMemIntPtr(0x5D4594, 1309692), v5, v6);
			nox_client_drawImageAt_47D2C0(*getMemIntPtr(0x5D4594, 1309692), v5, v8);
			v5 += 20;
		} while (v5 <= v7);
		v4 = v19;
	}
	v9 = v4 - 10;
	if (v4 - 10 - v5 >= 10) {
		nox_client_drawImageAt_47D2C0(dword_5d4594_1309696, v5, v6);
		nox_client_drawImageAt_47D2C0(dword_5d4594_1309696, v5, v8);
		v5 += 10;
	}
	if (v5 < v9) {
		v10 = v5 + ((v9 - v5 + 1) & 0xFFFFFFFE) - 10;
		nox_client_drawImageAt_47D2C0(dword_5d4594_1309696, v10, v6);
		nox_client_drawImageAt_47D2C0(dword_5d4594_1309696, v10, v8);
	}
	v11 = a2 + a4 - 30;
	v12 = a2 + 10;
	// v14 = __OFSUB__(a2 + 10, v11);
	// v13 = a2 + 10 == v11;
	v15 = v18 - 10;
	v20 = a2 + a4 - 30;
	// if ( (10 - (a4 - 30) < 0) ^ v14 | v13 )
	while (v12 <= v20) {
		nox_client_drawImageAt_47D2C0(*getMemIntPtr(0x5D4594, 1309700), v15, v12);
		nox_client_drawImageAt_47D2C0(*getMemIntPtr(0x5D4594, 1309700), v9, v12);
		v12 += 20;
	}
	if (v8 - v12 >= 10) {
		nox_client_drawImageAt_47D2C0(dword_5d4594_1309704, v15, v12);
		nox_client_drawImageAt_47D2C0(dword_5d4594_1309704, v9, v12);
		v12 += 10;
	}
	if (v12 < v8) {
		v16 = v12 + ((v8 - v12 + 1) & 0xFFFFFFFE) - 10;
		nox_client_drawImageAt_47D2C0(dword_5d4594_1309704, v15, v16);
		nox_client_drawImageAt_47D2C0(dword_5d4594_1309704, v9, v16);
	}
	nox_client_drawImageAt_47D2C0(*getMemIntPtr(0x5D4594, 1309676), v15, v21);
	nox_client_drawImageAt_47D2C0(*getMemIntPtr(0x5D4594, 1309680), v9, v21);
	nox_client_drawImageAt_47D2C0(*getMemIntPtr(0x5D4594, 1309684), v15, v8);
	nox_client_drawImageAt_47D2C0(*getMemIntPtr(0x5D4594, 1309688), v9, v8);
}

//----- (004AA030) --------------------------------------------------------
void sub_4AA030(nox_window* win, nox_window_data* data) {
	unsigned int* a1 = win;
	int a2 = data;
	unsigned int* v2;  // esi
	int v3;            // edi
	int v4;            // eax
	unsigned int v5;   // ebx
	int v6;            // edx
	int v7;            // ecx
	int v8;            // eax
	unsigned int* v9;  // eax
	int v10;           // ebp
	bool v11;          // zf
	int v12;           // ebx
	unsigned int* v13; // edi
	short v14;         // cx
	int v16 = 0;       // [esp+10h] [ebp-10h]
	unsigned int v17;  // [esp+14h] [ebp-Ch]
	int v18;           // [esp+18h] [ebp-8h]
	int v19;           // [esp+1Ch] [ebp-4h]

	v2 = a1;
	v3 = 0;
	nox_client_wndGetPosition_46AA60(a1, &a1, &v16);
	v5 = 0;
	v17 = 0;
	while (!v3) {
		v4 = (1 << v5) & v2[11];
		if (v4) {
			if (v4 <= 32) {
				if (v4 != 32) {
					switch (--v4) {
					case 0:
					case 1:
						goto LABEL_24;
					case 3:
					case 7:
					case 15:
						goto LABEL_25;
					default:
						goto LABEL_26;
					}
					goto LABEL_26;
				}
				v6 = v2[8];
				v7 = 0;
				v8 = 0;
				if (*(unsigned int*)(v6 + 12)) {
					v7 = *(unsigned int*)(*(unsigned int*)(*(unsigned int*)(v6 + 36) + 400) + 12);
				}
				if (*((unsigned short*)v2 + 54)) {
					v8 = 4;
				}
				sub_4A9E90((int)a1 - 3, v16 - v8 - 3, v2[2] - v7 + 3, v2[3] + 6);
				goto LABEL_25;
			}
			if (v4 > 4096) {
				if (v4 == 0x2000) {
					goto LABEL_24;
				}
			} else {
				switch (v4) {
				case 4096:
					goto LABEL_24;
				case 128:
					v9 = a1;
					v10 = v2[8];
					v11 = *(unsigned short*)(a2 + 72) == 0;
					v12 = v2[2];
					v19 = v16;
					v13 = a1;
					if (!v11) {
						nox_xxx_drawGetStringSize_43F840(*(unsigned int*)(a2 + 200), (unsigned short*)(a2 + 72), &v18,
														 0, 0);
						v13 = (unsigned int*)((char*)v13 + v18 + 6);
						v9 = a1;
						v12 += -6 - v18;
					}
					v14 = *(unsigned short*)(v10 + 1042);
					if (v14 > 0 && v12 > v14) {
						v12 = v14;
						v13 = (unsigned int*)((char*)v9 + v2[2] - v14);
					}
					sub_4A9E90((int)v13, v19, v12, v2[3]);
					v5 = v17;
					v3 = 1;
					break;
				case 2048:
				LABEL_24:
					sub_4A9E90((int)a1, v16, v2[2], v2[3]);
				LABEL_25:
					v3 = 1;
					break;
				}
			}
		}
	LABEL_26:
		v17 = ++v5;
		if (v5 >= 0x20) {
			break;
		}
	}
}

//----- (0046AD60) --------------------------------------------------------
int nox_xxx_wnd_46AD60(int a1, int a2) {
	int result; // eax

	if (!a1) {
		return -2;
	}
	result = *(unsigned int*)(a1 + 4);
	*(unsigned int*)(a1 + 4) = a2 | result;
	return result;
}

//----- (0046AD80) --------------------------------------------------------
int nox_xxx_wndClearFlag_46AD80(int a1, int a2) {
	int result; // eax

	if (!a1) {
		return -2;
	}
	result = *(unsigned int*)(a1 + 4);
	*(unsigned int*)(a1 + 4) = result & ~a2;
	return result;
}

//----- (0046ADA0) --------------------------------------------------------
int nox_xxx_wndGetFlags_46ADA0(int a1) {
	int result; // eax

	if (a1) {
		result = *(unsigned int*)(a1 + 4);
	} else {
		result = -2;
	}
	return result;
}

//----- (0046B250) --------------------------------------------------------
int nox_window_is_child(nox_window* a1, nox_window* a2) {
	if (!a1) {
		return 0;
	}
	if (!a2) {
		return 0;
	}

	nox_window* cur = a2;
	while (1) {
		cur = cur->parent;
		if (a1 == cur) {
			break;
		}
		if (!cur) {
			return 0;
		}
	}
	return 1;
}

//----- (0046B280) --------------------------------------------------------
int nox_xxx_wnd_46B280(int a1, int a2) {
	if (!a1) {
		return -2;
	}
	if (a2) {
		*(unsigned int*)(a1 + 52) = a2;
	} else {
		*(unsigned int*)(a1 + 52) = a1;
	}
	return 0;
}

//----- (004AA1F0) --------------------------------------------------------
char* nox_xxx_wndLoadBorder_4AA1F0() {
	char* result; // eax

	*getMemU32Ptr(0x5D4594, 1309676) = nox_xxx_gLoadImg_42F970("BorderCornerUL");
	*getMemU32Ptr(0x5D4594, 1309680) = nox_xxx_gLoadImg_42F970("BorderCornerUR");
	*getMemU32Ptr(0x5D4594, 1309684) = nox_xxx_gLoadImg_42F970("BorderCornerLL");
	*getMemU32Ptr(0x5D4594, 1309688) = nox_xxx_gLoadImg_42F970("BorderCornerLR");
	*getMemU32Ptr(0x5D4594, 1309692) = nox_xxx_gLoadImg_42F970("BorderHorizontal");
	dword_5d4594_1309696 = nox_xxx_gLoadImg_42F970("BorderHorizontalShort");
	*getMemU32Ptr(0x5D4594, 1309700) = nox_xxx_gLoadImg_42F970("BorderVertical");
	result = nox_xxx_gLoadImg_42F970("BorderVerticalShort");
	dword_5d4594_1309704 = result;
	return result;
}
