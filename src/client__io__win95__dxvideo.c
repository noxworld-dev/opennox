#include "client__io__win95__dxvideo.h"
#include "client__video__draw_common.h"
#include "common__strman.h"

#include "GAME1.h"
#include "GAME1_2.h"
#include "GAME1_3.h"
#include "GAME2_2.h"
#include "GAME2_3.h"
#include "GAME5_2.h"
#include "client__gui__window.h"

extern uint32_t dword_5d4594_805860;
extern int nox_video_16bit;
extern int nox_backbuffer_pitch_3801808;
extern uint32_t nox_video_modeXxx_3801780;
extern int nox_enable_threads;

extern int nox_win_width;
extern int nox_win_height;

extern int nox_backbuffer_width;
extern int nox_backbuffer_height;
extern int nox_video_renderTargetFlags;
extern int nox_video_dxFullScreen;
extern unsigned int nox_video_dxUnlockSurface;

//----- (0047FD70) --------------------------------------------------------
#ifndef NOX_CGO
int nox_video_recreateRenderTarget_47FD70() {
	int v1; // edi
	int v2; // ebx

	unsigned int flags = 0;
	if (nox_video_dxFullScreen) {
		if (nox_video_dxUnlockSurface) {
			flags = 0x20;
		}
	} else {
		flags = 0x10;
	}
	if (dword_5d4594_805860) {
		flags |= 0x18u;
	}
	if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_LOCK_VIDEO_RESOLUTION) && nox_video_dxFullScreen) {
		flags &= 0xFFFFFFDF;
	}
	if (!nox_enable_threads) {
		flags |= 0x100u;
	}
	if (*getMemU32Ptr(0x5D4594, 805864)) {
		flags |= 0x200u;
	}
	nox_xxx_setSomeFunc_48A210(sub_47FCE0);
	v1 = nox_client_getCursorType_477620();
	nox_client_setCursorType_477610(0);
	v2 = sub_48B3E0(0);
	int depth = nox_video_16bit != 0 ? 16 : 8;
	if (!nox_xxx_GfxInit_444930(nox_win_width, nox_win_height, depth, flags)) {
		wchar_t* v9 =
			nox_strman_loadString_40F1D0("result:ERROR", 0, "C:\\NoxPost\\src\\Client\\Io\\Win95\\dxvideo.c", 213);
		wchar_t* v4 = nox_strman_loadString_40F1D0("gfxDdraw.c:DXWarning", 0,
												   "C:\\NoxPost\\src\\Client\\Io\\Win95\\dxvideo.c", 213);
		nullsub_4(0, v4, v9, 1);
		return 0;
	}
	printf("%s: %d\n", __FUNCTION__, 1);
	nox_xxx_cursorLoadAll_477710();
	nox_client_setCursorType_477610(v1);
	sub_48B3E0(v2);
	nox_client_clearScreen_440900();
	nox_xxx_setupSomeVideo_47FEF0();
	sub_49F6D0(1);
	sub_437290();
	nox_video_16bit = nox_video_modeXxx_3801780;
	*getMemU32Ptr(0x973F18, 6060) = nox_backbuffer_pitch_3801808 * nox_backbuffer_height;
	*getMemU32Ptr(0x973F18, 7696) = nox_video_modeXxx_3801780 == 1;
	sub_430B50(0, 0, NOX_DEFAULT_WIDTH - 1, NOX_DEFAULT_HEIGHT - 1);
	nox_input_pollEvents_4453A0();
	return 1;
}
#endif // NOX_CGO
