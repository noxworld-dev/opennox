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
