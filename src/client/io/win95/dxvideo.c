#include "dxvideo.h"

#include "../../../proto.h"

extern int nox_win_width;
extern int nox_win_height;

extern int default_win_width;
extern int default_win_height;

extern int nox_backbuffer_width;
extern int nox_backbuffer_height;

//----- (0047FD70) --------------------------------------------------------
int sub_47FD70()
{
    int v1; // edi
    int v2; // ebx

    unsigned int flags = 0;
    if (*(_DWORD*)& byte_587000[80848]) {
        if (*(_DWORD*)& byte_5D4594[805868])
            flags = 0x20;
    } else {
        flags = 0x10;
    }
    if (*(_DWORD*)& byte_5D4594[805860])
        flags |= 0x18u;
    if (*(_DWORD*)& byte_5D4594[2650636] & 0x2000000 && *(_DWORD*)& byte_587000[80848])
        flags &= 0xFFFFFFDF;
    if (!*(_DWORD*)& byte_587000[80804])
        flags |= 0x100u;
    if (*(_DWORD*)& byte_5D4594[805864])
        flags |= 0x200u;
    sub_48A210(sub_47FCE0);
    v1 = sub_477620();
    sub_477610(0);
    v2 = sub_48B3E0(0);
    int depth = *(_DWORD*)& byte_5D4594[3804680] != 0 ? 16 : 8;
    if (!sub_444930(getWindowHandle_sub_401FD0(), nox_win_width, nox_win_height, depth, flags))
    {
        wchar_t* v9 = loadString_sub_40F1D0("result:ERROR", 0, "C:\\NoxPost\\src\\Client\\Io\\Win95\\dxvideo.c", 213);
        wchar_t* v4 = loadString_sub_40F1D0("gfxDdraw.c:DXWarning", 0, "C:\\NoxPost\\src\\Client\\Io\\Win95\\dxvideo.c", 213);
        nullsub_4(0, v4, v9, 1);
        return 0;
    }
    printf("%s: %d\n", __FUNCTION__, 1);
    sub_477710();
    sub_477610(v1);
    sub_48B3E0(v2);
    sub_440900();
    sub_47FEF0();
    sub_49F6D0(1);
    sub_437290();
    *(_DWORD*)& byte_5D4594[3804680] = *(_DWORD*)& byte_5D4594[3801780];
    *(_DWORD*)& byte_5D4594[3805488] = *(_DWORD*)& byte_5D4594[3801808] * nox_backbuffer_height;
    *(_DWORD*)& byte_5D4594[3807124] = *(_DWORD*)& byte_5D4594[3801780] == 1;
    sub_430B50(0, 0, default_win_width-1, default_win_height-1);
    sub_4453A0_poll_events();
    return 1;
}
