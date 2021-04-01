#include "client__gui__window.h"

void nox_window_call_draw_func(nox_window* win, nox_window_data* data) {
	win->draw_func(win, data);
}
