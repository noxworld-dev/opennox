#include "dxvideo.h"

#include "../../../proto.h"

extern _DWORD dword_5d4594_805860;
extern _DWORD dword_5d4594_3804680;
extern int nox_pitch_3801808;
extern _DWORD dword_5d4594_3801780;
extern int nox_enable_threads;

extern int nox_win_width;
extern int nox_win_height;

extern int nox_backbuffer_width;
extern int nox_backbuffer_height;
extern int nox_video_renderTargetFlags;
extern int nox_video_dxFullScreen;
extern int nox_video_dxUnlockSurface;

//----- (0047FD70) --------------------------------------------------------
int nox_video_recreateRenderTarget_47FD70() {
	int v1; // edi
	int v2; // ebx

	unsigned int flags = 0;
	if (nox_video_dxFullScreen) {
		if (nox_video_dxUnlockSurface)
			flags = 0x20;
	} else {
		flags = 0x10;
	}
	if (dword_5d4594_805860)
		flags |= 0x18u;
	if (nox_common_getEngineFlag(NOX_ENGINE_FLAG_26) && nox_video_dxFullScreen)
		flags &= 0xFFFFFFDF;
	if (!nox_enable_threads)
		flags |= 0x100u;
	if (*(_DWORD*)&byte_5D4594[805864])
		flags |= 0x200u;
	sub_48A210(sub_47FCE0);
	v1 = nox_client_getCursorType_477620();
	nox_client_setCursorType_477610(0);
	v2 = sub_48B3E0(0);
	int depth = dword_5d4594_3804680 != 0 ? 16 : 8;
	if (!sub_444930(getWindowHandle_sub_401FD0(), nox_win_width, nox_win_height, depth, flags)) {
		wchar_t* v9 = loadString_sub_40F1D0("result:ERROR", 0, "C:\\NoxPost\\src\\Client\\Io\\Win95\\dxvideo.c", 213);
		wchar_t* v4 =
			loadString_sub_40F1D0("gfxDdraw.c:DXWarning", 0, "C:\\NoxPost\\src\\Client\\Io\\Win95\\dxvideo.c", 213);
		nullsub_4(0, v4, v9, 1);
		return 0;
	}
	printf("%s: %d\n", __FUNCTION__, 1);
	sub_477710();
	nox_client_setCursorType_477610(v1);
	sub_48B3E0(v2);
	sub_440900();
	sub_47FEF0();
	sub_49F6D0(1);
	sub_437290();
	dword_5d4594_3804680 = dword_5d4594_3801780;
	*(_DWORD*)&byte_5D4594[3805488] = nox_pitch_3801808 * nox_backbuffer_height;
	*(_DWORD*)&byte_5D4594[3807124] = dword_5d4594_3801780 == 1;
	sub_430B50(0, 0, NOX_DEFAULT_WIDTH - 1, NOX_DEFAULT_HEIGHT - 1);
	sub_4453A0_poll_events();
	return 1;
}
