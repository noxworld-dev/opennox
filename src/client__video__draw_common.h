// This must come before the SDL includes.
#ifndef NOX_PORT_CLIENT_VIDEO_DRAW_COMMON_H
#define NOX_PORT_CLIENT_VIDEO_DRAW_COMMON_H

#include <stdint.h>

int nox_getBackbufWidth();
int nox_getBackbufHeight();

extern uint32_t dword_5d4594_823776;
extern uint8_t* nox_pixbuffer_3798780;
extern int nox_backbuffer_pitch_3801808;
extern int nox_enable_audio;

extern int nox_win_width;
extern int nox_win_height;

void nox_video_setGammaSlider(int v);
int nox_video_getFullScreen();
void nox_video_setFullScreen(int v);

int nox_draw_setColorMultAndIntensityRGB_433CD0(uint8_t a1, uint8_t a2, uint8_t a3);
int nox_draw_setColorMultAndIntensity_433E40(int a1);
void nox_draw_set54RGB32_434040(int a1);
void nox_draw_setMaterial_4340A0(int a1, int a2, int a3, int a4);
void nox_draw_setMaterial_4341D0(int a1, int a2);
void nox_set_color_rgb_434430(int r, int g, int b);
uint32_t nox_color_rgb_4344A0(int r, int g, int b);
void nox_video_callCopyBackBuffer_4AD170(void);

#endif // NOX_PORT_CLIENT_VIDEO_DRAW_COMMON_H
