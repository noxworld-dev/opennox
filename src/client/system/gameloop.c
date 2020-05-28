#include "gameloop.h"

#include "../../proto.h"
#include "../io/console.h"
#include "../gui/guimsg.h"

extern int default_win_width;
extern int default_win_height;

void map_download_start()
{
	sub_467DF0(1);
	sub_4CC770();
	*(_DWORD*)& byte_587000[173328] = 1;
	*(_DWORD*)& byte_587000[173332] = 1;
	map_download_loop(1);
}

//----- (0043DEB0) --------------------------------------------------------
int sub_43DEB0()
{
    char* v0; // eax
    char* v1; // esi
    int v2; // eax
    char v3; // al
    char v4; // bl
    char* v5; // esi
    wchar_t* v6; // eax
    wchar_t* v7; // eax
    wchar_t* v8; // eax
    wchar_t* v10; // eax
    wchar_t* v12; // [esp-10h] [ebp-118h]
    char* v13; // [esp-4h] [ebp-10Ch]
    char* v14; // [esp-4h] [ebp-10Ch]
    wchar_t v15[128]; // [esp+8h] [ebp-100h]

    if (!sub_40A5C0(0x800000))
        goto LABEL_16;
    sub_477610(10);
    if (sub_4DB250())
        v0 = sub_4DB260();
    else
        v0 = sub_409B30();
    v1 = v0;
    v2 = sub_409B00();
    v3 = sub_4CF470(v1, v2);
    v4 = v3;
    if (v3 & 2 && v3 & 4)
    {
        sub_43F140(500);
        v5 = sub_4AC2B0(v1);
        sub_43F1A0();
        if (!v5)
        {
            v13 = sub_409B30();
            v6 = loadString_sub_40F1D0((char*)& byte_587000[93352], 0, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 318);
            sub_4516C0(v6, v13);
            sub_4356E0();
            return 0;
        }
        if (sub_40A5C0(1))
            sub_4DD180(31);
        else
            sub_43C9F0();
        sub_43C720(1);
        if ((int) * (_DWORD*)& byte_5D4594[3803228] < 0)
        {
            v7 = loadString_sub_40F1D0((char*)& byte_587000[93408], 0, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 338);
            sub_445490(v7);
            v14 = sub_42E8E0(8, 1);
            v8 = loadString_sub_40F1D0((char*)& byte_587000[93468], 0, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 339);
            nox_swprintf(v15, v8, v14);
            sub_445490(v15);
        }
    }
    else
    {
        if (!sub_40A5C0(1))
        {
            if (!(v4 & 1) || v4 & 4)
            {
                sub_40A4D0(0x100000);
            }
            else
            {
                sub_40A540(9437184);
                sub_477530(1);
                sub_43E1A0(1);
                v12 = loadString_sub_40F1D0((char*)& byte_587000[93244], 0, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 298);
                v10 = loadString_sub_40F1D0((char*)& byte_587000[93304], 0, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 297);
                sub_449A10(0, (int)v10, (int)v12, 24, sub_43E230, sub_43E200);
            }
            goto LABEL_16;
        }
        sub_4DD180(31);
    }
    if (!(*(_DWORD*)& byte_5D4594[2650636] & 0x40000))
    {
        *(_DWORD*)& byte_5D4594[2650672] = 1;
        sub_44DA60(1);
    }
    LABEL_16:
    if (sub_40A5C0(0x100000))
    {
        map_download_start();
        return 0;
    }
    if (sub_40A5C0(9437184))
        sub_40A540(9437184);
    return 1;
}

int map_download_finish()
{
    int result; // eax
    wchar_t* v6; // eax
    char* v13; // [esp-4h] [ebp-10Ch]

    sub_4CC930();
    result = *(_DWORD*)& byte_587000[173332];
    if (*(_DWORD*)& byte_587000[173332])
    {
        int v3; // [esp+4h] [ebp-Ch]
        int v4; // [esp+8h] [ebp-8h]
        int v5; // [esp+Ch] [ebp-4h]
        sub_43BEB0_get_video_mode(&v3, &v5, &v4);
        if (!v3)
            sub_43BEF0_set_video_mode(default_win_width, default_win_height, v4);
        result = *(_DWORD*)& byte_587000[173332];
    }

    if (!result)
    {
        sub_40A540(9437184);
        return 0;
    }
    sub_43E1A0(0);
    if (!(*(_DWORD*)& byte_5D4594[2650636] & 0x40000))
    {
        *(_DWORD*)& byte_5D4594[2650672] = 1;
        sub_44DA60(1);
    }
    if (!sub_4AC2B0(sub_409B30()))
    {
        v13 = sub_409B30();
        v6 = loadString_sub_40F1D0((char*)& byte_587000[93528], 0, "C:\\NoxPost\\src\\Client\\System\\gameloop.c", 386);
        sub_4516C0(v6, v13);
        sub_4356E0();
        return 0;
    }
    if (sub_40A5C0(1))
        sub_4DD180(31);
    else
        sub_43C9F0();
    sub_43C720(1);

    if (sub_40A5C0(9437184))
        sub_40A540(9437184);
    return 1;
}
