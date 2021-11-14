#include <stdlib.h>
#include <string.h>

#include "client__gui__window.h"
#include "common/alloc/classes/alloc_class.h"

#include "defs.h" // nox_video_bag_section_t, nox_video_bag_image_t
#include "memmap.h"

// TODO: part of the GUI toolkit
void nox_client_drawImageAt_47D2C0(void* a1, int x, int y);
int nox_xxx_drawGetStringSize_43F840(int a1, unsigned short* a2, int* a3, int* a4, int a5);
int nox_client_drawSetColor_434460(int a1);
void nox_client_drawRectFilledOpaque_49CE30(int xLeft, int yTop, int a3, int a4);
nox_video_bag_image_t* nox_xxx_gLoadImg_42F970(const char* a1);

// TODO: reference to input
void sub_4309B0(unsigned char i, unsigned char v);

extern unsigned int dword_5d4594_3799468;
extern nox_window* nox_win_1064916;

int dword_5d4594_3799524 = 0;

unsigned int dword_5d4594_1309696 = 0;
unsigned int dword_5d4594_1309704 = 0;

nox_window* dword_5d4594_1064896 = 0;

nox_window_ref* nox_win_1064912 = 0;
#ifndef NOX_CGO
extern nox_video_bag_section_t* nox_video_bag_sections_arr;
nox_alloc_class* nox_alloc_window = 0;
nox_window* nox_win_xxx1_first = 0;
nox_window* nox_win_xxx1_last = 0;
void* nox_win_activeWindow_1064900 = 0;
nox_window* nox_win_cur_focused = 0;
nox_window* nox_win_unk3 = 0;
#endif // NOX_CGO

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

#ifndef NOX_CGO
//----- (0046A920) --------------------------------------------------------
void nox_client_wndListXxxAdd_46A920(nox_window* win) {
	win->next = 0;
	win->prev = nox_win_xxx1_last;
	if (nox_win_xxx1_last) {
		nox_win_xxx1_last->next = win;
	} else {
		nox_win_xxx1_first = win;
	}
	nox_win_xxx1_last = win;
}

//----- (0046A960) --------------------------------------------------------
void nox_client_wndListXxxRemove_46A960(nox_window* win) {
	nox_window* prev = win->prev;
	nox_window* next = win->next;
	if (prev) {
		prev->next = next;
	} else {
		nox_win_xxx1_first = next;
	}
	if (next) {
		next->prev = prev;
	} else {
		nox_win_xxx1_last = prev;
	}
}

//----- (0046A9F0) --------------------------------------------------------
void nox_xxx_wndFixCoords_46A9F0(nox_window* win) {
	unsigned int* a1 = win;
	int v2; // ecx
	int v3; // edx
	int v4; // ecx
	int v5; // edx

	v2 = a1[4];
	v3 = a1[6];
	if (v2 > v3) {
		a1[4] = v3;
		a1[6] = v2;
	}
	v4 = a1[5];
	v5 = a1[7];
	if (v4 > v5) {
		a1[5] = v5;
		a1[7] = v4;
	}
}

//----- (0046A9B0) --------------------------------------------------------
int nox_window_setPos_46A9B0(nox_window* win, int a2, int a3) {
	unsigned int* a1 = win;
	int v4; // esi
	int v5; // ecx

	if (!a1) {
		return -2;
	}
	v4 = a1[2];
	a1[4] = a2;
	v5 = a3 + a1[3];
	a1[5] = a3;
	a1[6] = a2 + v4;
	a1[7] = v5;
	nox_xxx_wndFixCoords_46A9F0(a1);
	return 0;
}

//----- (0046A8C0) --------------------------------------------------------
int nox_xxx_wndShowModalMB_46A8C0(nox_window* win) {
	int a1 = win;
	int result; // eax
	int v2;     // eax
	int v3;     // eax

	if (!a1) {
		return -2;
	}
	v2 = nox_win_xxx1_last;
	if (nox_win_xxx1_last == a1) {
	LABEL_6:
		nox_client_wndListXxxRemove_46A960(a1);
		nox_client_wndListXxxAdd_46A920(a1);
		v3 = *(unsigned int*)(a1 + 4);
		v3 |= 1;
		*(unsigned int*)(a1 + 4) = v3;
		nox_window_set_hidden(a1, 0);
		result = 0;
	} else {
		while (v2) {
			v2 = *(unsigned int*)(v2 + 388);
			if (v2 == a1) {
				goto LABEL_6;
			}
		}
		result = -3;
	}
	return result;
}

//----- (0042FAE0) --------------------------------------------------------
void sub_42FAE0(void* a1) {
	nox_video_bag_section_t* ent = &nox_video_bag_sections_arr[*(unsigned short*)((char*)a1 + 8)];
	if (ent->field_6 == -1) {
		if (ent->data) {
			free(ent->data);
			ent->data = 0;
		}
	}
}

//----- (0046AC60) --------------------------------------------------------
void sub_46AC60(nox_window* a1p) {
	int a1 = a1p;
	int v2; // esi

	if (*(unsigned char*)(a1 + 4) & 0x80) {
		if (*(unsigned int*)(a1 + 60)) {
			sub_42FAE0(*(unsigned int*)(a1 + 60));
		}
		if (*(unsigned int*)(a1 + 84)) {
			sub_42FAE0(*(unsigned int*)(a1 + 84));
		}
		if (*(unsigned int*)(a1 + 68)) {
			sub_42FAE0(*(unsigned int*)(a1 + 68));
		}
		if (*(unsigned int**)(a1 + 92)) {
			sub_42FAE0(*(unsigned int*)(a1 + 92));
		}
		v2 = *(unsigned int*)(a1 + 76);
		if (v2) {
			sub_42FAE0(v2);
		}
	}
}

//----- (0046B180) --------------------------------------------------------
void sub_46B180(nox_window* win) {
	nox_window* next = win->next;
	nox_window* prev = win->prev;
	if (next) {
		next->prev = prev;
		if (prev) {
			prev->next = win->next;
		}
	} else if (prev) {
		win->parent->field_100 = prev;
		win->prev->next = win->next;
		win->prev = 0;
	} else {
		win->parent->field_100 = 0;
	}
}

//----- (0046C4E0) --------------------------------------------------------
int nox_xxx_windowDestroyMB_46C4E0(nox_window* a1p) {
	unsigned int* a1 = a1p;
	int v2;           // eax
	unsigned int* v3; // eax
	unsigned int* v4; // edi

	if (!a1) {
		return -2;
	}
	v2 = a1[1];
	if (!(v2 & 0x800)) {
		v2 |= 0x800u;
		a1[1] = v2;
		sub_46AC60((int)a1);
		if (nox_win_unk3 == a1) {
			nox_xxx_wndClearCaptureMain_46ADE0((int)a1);
		}
		if (nox_win_cur_focused == a1) {
			nox_xxx_windowFocus_46B500(0);
		}
		if (nox_win_1064912 && a1 == nox_win_1064912->win) {
			nox_xxx_wnd_46C6E0(nox_win_1064912->win);
		}
		if (nox_win_activeWindow_1064900 == a1) {
			nox_win_activeWindow_1064900 = 0;
		}
		if (nox_win_1064916 == a1) {
			nox_win_1064916 = 0;
		}
		v3 = (unsigned int*)a1[100];
		if (v3) {
			do {
				v4 = (unsigned int*)v3[97];
				nox_xxx_windowDestroyMB_46C4E0(v3);
				v3 = v4;
			} while (v4);
		}
		if (a1[99]) {
			sub_46B180(a1);
		} else {
			nox_client_wndListXxxRemove_46A960((int)a1);
		}
		a1[98] = 0;
		a1[97] = dword_5d4594_1064896;
		dword_5d4594_1064896 = a1;
	}
	return 0;
}
#endif // NOX_CGO

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
int nox_xxx_wnd_46ABB0(int a1, int a2) {
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

#ifndef NOX_CGO
//----- (0046AC00) --------------------------------------------------------
int nox_window_set_hidden(nox_window* win, int hidden) {
	if (!win) {
		return -2;
	}

	if (!hidden) {
		win->flags &= ~NOX_WIN_HIDDEN;
		return 0;
	}

	if ((win->flags & 0x8000) == 0) {
		sub_46AC60(win);
	}

	if (dword_5d4594_3799468) {
		if (!(win->flags & NOX_WIN_HIDDEN)) {
			dword_5d4594_3799524 = 1;
		}
	}
	win->flags |= NOX_WIN_HIDDEN;
	return 0;
}

//----- (0046ACC0) --------------------------------------------------------
int wndIsShown_nox_xxx_wndIsShown_46ACC0(nox_window* win) {
	int a1 = win;
	int result; // eax

	if (a1) {
		result = (*(unsigned int*)(a1 + 4) >> 4) & 1;
	} else {
		result = 1;
	}
	return result;
}

//----- (0046AFE0) --------------------------------------------------------
int nox_xxx_wndSetRectColor2MB_46AFE0(nox_window* win, int a2) {
	int a1 = win;
	if (!a1) {
		return -2;
	}
	*(unsigned int*)(a1 + 56) = a2;
	return 0;
}

//----- (0046B070) --------------------------------------------------------
void nox_gui_winSetFunc96_46B070(nox_window* win, void* fnc) { win->tooltip_func = fnc; }

//----- (0046B080) --------------------------------------------------------
int nox_xxx_wndSetID_46B080(nox_window* win, int id) {
	if (!win) {
		return -2;
	}
	win->id = id;
	return 0;
}

//----- (0046B0A0) --------------------------------------------------------
int nox_xxx_wndGetID_46B0A0(nox_window* win) {
	if (!win) {
		return -2;
	}
	return win->id;
}

//----- (0046B0C0) --------------------------------------------------------
nox_window* nox_xxx_wndGetChildByID_46B0C0(nox_window* root, int id) {
	nox_window* cur = root;
	if (!root) {
		if (!nox_win_xxx1_last) {
			return 0;
		}
		cur = nox_win_xxx1_last;
	}
	for (; cur; cur = cur->prev) {
		if (cur->id == id) {
			return cur;
		}
		if (cur->field_100) {
			nox_window* res = nox_xxx_wndGetChildByID_46B0C0(cur->field_100, id);
			if (res) {
				return res;
			}
		}
	}
	return 0;
}

//----- (0046B110) --------------------------------------------------------
int nox_client_wndListXxxLast_46B110() { return nox_win_xxx1_last; }

//----- (0046B200) --------------------------------------------------------
void nox_window_set_ptrs_97(nox_window* win, nox_window* a2) {
	if (!a2) {
		return;
	}

	win->next = 0;
	nox_window* v2 = a2->field_100;
	win->prev = v2;
	if (v2) {
		v2->next = win;
	}
	a2->field_100 = win;
	win->parent = a2;
}

//----- (0046B120) --------------------------------------------------------
int sub_46B120(nox_window* win, nox_window* a2) {
	if (!win) {
		return -2;
	}
	if (win->parent) {
		sub_46B180(win);
	} else {
		nox_client_wndListXxxRemove_46A960(win);
	}
	if (a2) {
		nox_window_set_ptrs_97(win, a2);
	} else {
		nox_client_wndListXxxAdd_46A920(win);
		win->parent = 0;
	}
	return 0;
}
#endif // NOX_CGO

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

//----- (0046C370) --------------------------------------------------------
#ifndef NOX_CGO
int nox_window_draw_recursive(nox_window* win) {
	if (!win) {
		return -2;
	}
	if (win->flags & NOX_WIN_HIDDEN) {
		return 0;
	}

	if (win->draw_func) {
		win->draw_func(win, &win->draw_data);
	}
	if ((win->flags & 0x1000) == 0x1000) {
		sub_4AA030(win, &win->draw_data);
	}

	for (nox_window* i = win->field_100; i; i = i->prev) {
		nox_window_draw_recursive(i);
	}
	return 0;
}

//----- (0046C2E0) --------------------------------------------------------
void nox_gui_draw() {
	// background and some UI parts
	for (nox_window* win = nox_win_xxx1_first; win; win = win->next) {
		if (win->flags & NOX_WIN_LAYER_BACK) {
			nox_window_draw_recursive(win);
		}
	}
	for (nox_window* win = nox_win_xxx1_first; win; win = win->next) {
		if ((win->flags & (NOX_WIN_LAYER_BACK | NOX_WIN_LAYER_FRONT)) == 0) {
			nox_window_draw_recursive(win);
		}
	}
	for (nox_window* win = nox_win_xxx1_first; win; win = win->next) {
		if (win->flags & NOX_WIN_LAYER_FRONT) {
			nox_window_draw_recursive(win);
		}
	}
}
#endif // NOX_CGO

//----- (0046B370) --------------------------------------------------------
int nox_xxx_wndDrawFnDefault_46B370(int a1, int* a2) {
	int v2;        // edx
	int v3;        // ecx
	int result;    // eax
	int xLeft = 0; // [esp+4h] [ebp-8h]
	int yTop = 0;  // [esp+8h] [ebp-4h]

	nox_client_wndGetPosition_46AA60((unsigned int*)a1, &xLeft, &yTop);
	if ((signed char)*(unsigned char*)(a1 + 4) >= 0) {
		if (a2[5] != 0x80000000) {
			nox_client_drawSetColor_434460(a2[5]);
			nox_client_drawRectFilledOpaque_49CE30(xLeft, yTop, *(unsigned int*)(a1 + 8), *(unsigned int*)(a1 + 12));
		}
		result = 1;
	} else {
		v2 = *(unsigned int*)(a1 + 100);
		xLeft += *(unsigned int*)(a1 + 96);
		v3 = v2 + yTop;
		yTop = v3;
		if (*(unsigned char*)(a1 + 36) & 2) {
			nox_client_drawImageAt_47D2C0(a2[10], xLeft, v3);
		} else {
			nox_client_drawImageAt_47D2C0(a2[6], xLeft, v3);
		}
		result = 1;
	}
	return result;
}

#ifndef NOX_CGO
//----- (0046B330) --------------------------------------------------------
int nox_xxx_wndDefaultProc_0_46B330(int a1, int a2, int a3, int a4) { return 0; }

//----- (0046B2F0) --------------------------------------------------------
int nox_xxx_wndDefaultProc_46B2F0(int a1, int a2, int a3, int a4) { return 0; }

//----- (0046C3E0) --------------------------------------------------------
nox_window* nox_window_new(nox_window* a1, int flags, int x, int y, int w, int h, int (*fnc)(int, int, int, int)) {
	nox_alloc_class* al = nox_alloc_window;
	if (!al) {
		al = nox_new_alloc_class("Window", sizeof(nox_window), 576);
		nox_alloc_window = al;
	}
	if (!al) {
		return 0;
	}

	nox_window* win = (nox_window*)nox_alloc_class_new_obj_zero(al);
	if (!win) {
		return 0;
	}

	if (a1) {
		nox_window_set_ptrs_97(win, a1);
	} else {
		nox_client_wndListXxxAdd_46A920(win);
	}
	win->id = 0;
	win->flags = flags;
	win->width = w;
	win->height = h;
	win->off_x = x;
	win->off_y = y;
	win->end_x = w + x;
	win->end_y = h + y;
	win->draw_data.tooltip[0] = 0;
	nox_xxx_wndFixCoords_46A9F0(win);
	win->draw_func = nox_xxx_wndDrawFnDefault_46B370;
	win->field_93 = nox_xxx_wndDefaultProc_0_46B330;
	if (fnc) {
		win->field_94 = fnc;
		nox_window_call_field_94((int)win, 1, 0, 0);
	} else {
		win->field_94 = nox_xxx_wndDefaultProc_46B2F0;
	}
	memset(&win->draw_data, 0, sizeof(nox_window_data));
	win->field_92 = 0;
	return win;
}

//----- (0046C5D0) --------------------------------------------------------
int sub_46C5D0() {
	unsigned int* v0; // eax
	unsigned int* v1; // esi

	v0 = *(unsigned int**)&nox_win_xxx1_last;
	if (nox_win_xxx1_last) {
		do {
			v1 = (unsigned int*)v0[97];
			nox_xxx_windowDestroyMB_46C4E0(v0);
			v0 = v1;
		} while (v1);
	}
	sub_46C200();
	nox_alloc_class_free_all(nox_alloc_window);
	return 0;
}

//----- (0046B430) --------------------------------------------------------
int nox_window_set_all_funcs(nox_window* win, int (*a2)(int, int, int, int), int (*draw)(nox_window*, void*),
							 void* a4) {
	if (!win) {
		return -2;
	}
	if (a2) {
		win->field_93 = a2;
	} else {
		win->field_93 = nox_xxx_wndDefaultProc_0_46B330;
	}
	if (draw) {
		win->draw_func = draw;
	} else {
		win->draw_func = nox_xxx_wndDrawFnDefault_46B370;
	}
	win->tooltip_func = a4;
	return 0;
}

//----- (0046B490) --------------------------------------------------------
int nox_window_call_field_94(nox_window* win, int a2, int a3, int a4) {
	if (!win) {
		return 0;
	}
	//	if (a2 & 0x4000)
	//		printf("win event 94: id=%d, ev=0x4000 | %d, a1=%d, a2=%d\n", win->id, a2 - 0x4000, a3, a4);
	//	else
	//		printf("win event 94: id=%d, ev=%d, a1=%d, a2=%d\n", win->id, a2, a3, a4);
	return win->field_94(win, a2, a3, a4);
}

//----- (0046B4C0) --------------------------------------------------------
int nox_window_call_field_93(nox_window* win, int a2, int a3, int a4) {
	if (!win) {
		return 0;
	}
	//	if (a2 & 0x4000)
	//		printf("win event 93: id=%d, ev=0x4000 | %d, a1=%d, a2=%d\n", win->id, a2 - 0x4000, a3, a4);
	//	else
	//		printf("win event 93: id=%d, ev=%d, a1=%d, a2=%d\n", win->id, a2, a3, a4);
	return win->field_93(win, a2, a3, a4);
}

//----- (0046B4F0) --------------------------------------------------------
nox_window* nox_xxx_wndGetFocus_46B4F0() { return nox_win_cur_focused; }

//----- (0046B500) --------------------------------------------------------
int nox_xxx_windowFocus_46B500(nox_window* win) {
	if (win) {
		if (win->flags & 0x400) {
			return 0;
		}
	}
	if (nox_win_cur_focused) {
		if (nox_win_cur_focused != win) {
			nox_window_call_field_94(nox_win_cur_focused, 23, 0, 0);
		}
	}
	nox_win_cur_focused = win;
	if (!win) {
		nox_win_cur_focused = 0;
		return 0;
	}
	if (!nox_window_call_field_94(win, 23, 1, 0)) {
		nox_window* cur = win;
		while (1) {
			cur = cur->parent;
			if (!cur) {
				break;
			}
			if (nox_window_call_field_94(cur, 23, 1, 0)) {
				return 0;
			}
		}
		nox_win_cur_focused = 0;
	}
	return 0;
}
#endif // NOX_CGO

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

#ifndef NOX_CGO
//----- (0046ADC0) --------------------------------------------------------
int nox_xxx_wndSetCaptureMain_46ADC0(nox_window* a1) {
	if (nox_win_unk3) {
		return -4;
	}
	nox_win_unk3 = a1;
	return 0;
}

//----- (0046ADE0) --------------------------------------------------------
int nox_xxx_wndClearCaptureMain_46ADE0(nox_window* a1) {
	if (a1 == nox_win_unk3) {
		nox_win_unk3 = 0;
	}
	return 0;
}

//----- (0046AE00) --------------------------------------------------------
nox_window* nox_xxx_wndGetCaptureMain_46AE00() { return nox_win_unk3; }

//----- (0046B6B0) --------------------------------------------------------
void nox_xxx_windowUpdateKeysMB_46B6B0(unsigned char* a1) {
	if (!nox_win_cur_focused) {
		return;
	}
	if (!*a1) {
		return;
	}
	if (a1[2] == 1) {
		return;
	}
	char v3 = 1;
	char v7 = 1;
	unsigned char* v2 = a1;
	int v1 = nox_win_cur_focused;
	while (!nox_window_call_field_93(v1, 21, *v2, v2[1])) {
		v1 = *(unsigned int*)(v1 + 396);
		if (!v1) {
			v3 = 0;
			v7 = 0;
			break;
		}
	}
	unsigned char v6 = *v2;
	v2[2] = v3;
	sub_4309B0(v6, v7);
}

//----- (0046C200) --------------------------------------------------------
void sub_46C200() {
	int v0;  // esi
	bool v1; // zf
	int v2;  // edi

	v0 = dword_5d4594_1064896;
	v1 = dword_5d4594_1064896 == 0;
	dword_5d4594_1064896 = 0;
	if (!v1) {
		do {
			v2 = *(unsigned int*)(v0 + 388);
			if (nox_win_unk3 == v0) {
				nox_xxx_wndClearCaptureMain_46ADE0(v0);
			}
			if (nox_win_cur_focused == v0) {
				nox_xxx_windowFocus_46B500(0);
			}
			if (nox_win_1064912 && v0 == nox_win_1064912->win) {
				nox_xxx_wnd_46C6E0(nox_win_1064912->win);
			}
			if (nox_win_activeWindow_1064900 == v0) {
				nox_win_activeWindow_1064900 = 0;
			}
			if (nox_win_1064916 == v0) {
				nox_win_1064916 = 0;
			}
			nox_window_call_field_94(v0, 2, 0, 0);
			nox_alloc_class_free_obj_first(nox_alloc_window, v0);
			v0 = v2;
		} while (v2);
	}
}
#endif // NOX_CGO

//----- (0046C690) --------------------------------------------------------
int sub_46C690(int a1) {
	if (!a1) {
		return -2;
	}
	if (*(unsigned int*)(a1 + 396)) {
		return -3;
	}
	nox_window_ref* v2 = calloc(1, sizeof(nox_window_ref));
	if (!v2) {
		return -1;
	}
	v2->win = a1;
	v2->next = nox_win_1064912;
	nox_win_1064912 = v2;
	return 0;
}

//----- (0046C6E0) --------------------------------------------------------
int nox_xxx_wnd_46C6E0(nox_window* a1) {
	int v2; // esi

	if (!a1) {
		return -2;
	}
	if (!nox_win_1064912 || nox_win_1064912->win != a1) {
		return -1;
	}
	v2 = nox_win_1064912->next;
	free(nox_win_1064912);
	nox_win_1064912 = v2;
	return 0;
}

//----- (0046B240) --------------------------------------------------------
int sub_46B240(int a1) {
	int result; // eax

	result = a1;
	if (a1) {
		result = *(unsigned int*)(a1 + 396);
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

//----- (0046B2B0) --------------------------------------------------------
int sub_46B2B0(int a1) {
	int result; // eax

	result = a1;
	if (a1) {
		result = *(unsigned int*)(a1 + 52);
	}
	return result;
}

#ifndef NOX_CGO
//----- (0046B2C0) --------------------------------------------------------
int nox_xxx_wndSetProc_46B2C0(int a1, int (*a2)(int, int, int, int)) {
	if (!a1) {
		return -2;
	}
	if (a2) {
		*(unsigned int*)(a1 + 376) = a2;
	} else {
		*(unsigned int*)(a1 + 376) = nox_xxx_wndDefaultProc_46B2F0;
	}
	return 0;
}

//----- (0046B300) --------------------------------------------------------
int nox_xxx_wndSetWindowProc_46B300(int a1, int (*a2)(int, int, int, int)) {
	if (!a1) {
		return -2;
	}
	if (a2) {
		*(unsigned int*)(a1 + 372) = a2;
	} else {
		*(unsigned int*)(a1 + 372) = nox_xxx_wndDefaultProc_0_46B330;
	}
	return 0;
}

//----- (0046B340) --------------------------------------------------------
int nox_xxx_wndSetDrawFn_46B340(int a1, int (*a2)(int, int)) {
	if (!a1) {
		return -2;
	}
	if (a2) {
		*(unsigned int*)(a1 + 380) = a2;
	} else {
		*(unsigned int*)(a1 + 380) = nox_xxx_wndDrawFnDefault_46B370;
	}
	return 0;
}

//----- (0046B580) --------------------------------------------------------
int sub_46B580(int a1) {
	if (!a1) {
		return -2;
	}
	if (!(*(unsigned char*)(a1 + 4) & 0x10)) {
		nox_xxx_wndDrawFnDefault_46B370(a1, (int*)(a1 + 36));
	}
	return 0;
}
#endif // NOX_CGO

//----- (0046B5B0) --------------------------------------------------------
nox_window* nox_client_inWindowByPos_46B5B0(nox_window* root, int x, int y) {
	if (!root) {
		return 0;
	}

	nox_window* cur = root;
LOOP:
	for (nox_window* win = cur->field_100; win; win = win->prev) {
		int px = win->off_x;
		int py = win->off_y;
		for (nox_window* win2 = win->parent; win2; win2 = win2->parent) {
			px += win2->off_x;
			py += win2->off_y;
		}
		if (x >= px && x <= px + win->width && y >= py && y <= py + win->height) {
			if (win->flags & 8 && !(win->flags & 0x10)) {
				cur = win;
				goto LOOP;
			}
		}
	}
	return cur;
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
