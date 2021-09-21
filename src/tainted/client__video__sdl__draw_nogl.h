#ifndef NOX_PORT_CLIENT_VIDEO_SDL_DRAW_NOGL
#define NOX_PORT_CLIENT_VIDEO_SDL_DRAW_NOGL

#include "defs.h"

int nox_video_resetRenderer_48A040(int width, int height, int depth);
void nox_video_free_renderer_48A120();
int nox_video_setBackBufSizes_48A3D0();
int nox_video_init_renderer_48B000();
int nox_client_drawGeneral_4B0340(int a1);

#endif // NOX_PORT_CLIENT_VIDEO_SDL_DRAW_NOGL
