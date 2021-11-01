#include "client__gui__window.h"

int nox_window_set_all_funcs_go(nox_window* win, void* a2, void* draw, void* a4);
int nox_window_set_all_funcs(nox_window* win, int (*a2)(int, int, int, int), int (*draw)(nox_window*, void*),
							 void* a4) {
	return nox_window_set_all_funcs_go(win, a2, draw, a4);
}

nox_window* nox_window_new_go(nox_window* a1, int flags, int a3, int a4, int w, int h, void* fnc);
nox_window* nox_window_new(nox_window* a1, int flags, int a3, int a4, int w, int h, int (*fnc)(int, int, int, int)) {
	return nox_window_new_go(a1, flags, a3, a4, w, h, fnc);
}

int nox_xxx_wndSetProc_46B2C0_go(nox_window* a1, void* a2);
int nox_xxx_wndSetProc_46B2C0(int a1, int (*a2)(int, int, int, int)) { return nox_xxx_wndSetProc_46B2C0_go(a1, a2); }

int nox_xxx_wndSetWindowProc_46B300_go(nox_window* a1, void* a2);
int nox_xxx_wndSetWindowProc_46B300(int a1, int (*a2)(int, int, int, int)) {
	return nox_xxx_wndSetWindowProc_46B300_go(a1, a2);
}

int nox_xxx_wndSetDrawFn_46B340_go(nox_window* a1, void* a2);
int nox_xxx_wndSetDrawFn_46B340(int a1, int (*a2)(int, int)) { return nox_xxx_wndSetDrawFn_46B340_go(a1, a2); }

int nox_xxx_wndDefaultProc_0_46B330(int a1, int a2, int a3, int a4) { return 0; }
int nox_xxx_wndDefaultProc_46B2F0(int a1, int a2, int a3, int a4) { return 0; }
